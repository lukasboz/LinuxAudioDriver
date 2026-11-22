"""Per-machine configuration, startup integration and hash-checked rollback."""

import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import tempfile
import time

import realtek_rear_mic

from . import audio


def run(*args, check=True):
    process = subprocess.run([str(a) for a in args], capture_output=True, text=True, timeout=30)
    if check and process.returncode:
        raise RuntimeError(f'{args[0]} failed: {process.stderr.strip() or process.stdout.strip()}')
    return process.stdout.strip()


def sources():
    return json.loads(run('pactl', '--format=json', 'list', 'sources'))


def require_commands(*names):
    missing = [name for name in names if not shutil.which(name)]
    if missing:
        raise ValueError('Install required system commands: ' + ', '.join(missing))


def digest(data):
    return hashlib.sha256(data).hexdigest()


def write_json(path, data):
    temporary = None
    try:
        with tempfile.NamedTemporaryFile(mode='w', dir=path.parent, prefix='.install-', delete=False) as stream:
            temporary = Path(stream.name)
            json.dump(data, stream, indent=2)
            stream.write('\n')
        temporary.replace(path)
    finally:
        if temporary is not None:
            temporary.unlink(missing_ok=True)


def verify_manifest(manifest, allowed):
    records = manifest.get('files', [])
    if not records or len({r['path'] for r in records}) != len(records):
        raise ValueError('Invalid installation file list')
    for record in records:
        path = Path(record['path'])
        if path not in allowed:
            raise ValueError(f'Unexpected installation path: {path}')
        if path.is_symlink() or not path.is_file() or digest(path.read_bytes()) != record['sha256']:
            raise ValueError(f'Installed file was modified or is missing: {path}; preserving it')


def install_files(manifest_path, payloads, metadata):
    if manifest_path.exists() or manifest_path.is_symlink():
        raise ValueError('An installation already exists; remove it before changing configuration')
    for path in payloads:
        if path.exists() or path.is_symlink():
            raise ValueError(f'Refusing to overwrite existing file: {path}')
    created = []
    try:
        for path, (data, mode) in payloads.items():
            path.parent.mkdir(parents=True, exist_ok=True)
            with path.open('xb') as stream:
                stream.write(data)
            created.append(path)
            path.chmod(mode)
        manifest_path.parent.mkdir(parents=True, exist_ok=True)
        write_json(manifest_path, {**metadata, 'files': [
            {'path': str(path), 'sha256': digest(data)} for path, (data, _) in payloads.items()]})
    except BaseException:
        for path in reversed(created):
            path.unlink()
        raise


def user_paths(home=None):
    base = (home or Path.home()) / '.config'
    return (base / 'alc408x-mic/install.json', base / 'alc408x-mic/filter.conf',
            base / 'systemd/user' / audio.UNIT)


def restore_source(metadata):
    names = {s['name'] for s in sources()}
    before = metadata['master_before']
    if before['name'] in names:
        run('pactl', 'set-source-volume', before['name'],
            *[v['value'] for v in before['volume'].values()])
        run('pactl', 'set-source-mute', before['name'], int(before['mute']))
    if metadata['default_before'] in names:
        run('pactl', 'set-default-source', metadata['default_before'])


def install_user(selected, gain, hardware_volume='current', make_default=True, dry_run=False):
    manifest, config_path, service = user_paths()
    source = selected['source']
    channels, positions = audio.channel_layout(source)
    config = audio.filter_config(source['name'], gain, channels, positions)
    # Keep formatted JSON: PipeWire 1.6.2 skipped modules in a compact rendering
    # of the same config during the native release check.
    payloads = {config_path: ((json.dumps(config, indent=2) + '\n').encode(), 0o644),
                config_path.parent / 'wait_audio.py': (Path(__file__).with_name('wait_audio.py').read_bytes(), 0o644),
                service: (audio.user_unit().encode(), 0o644)}
    plan = {'scope': 'desktop', 'source': source['name'], 'usb_id': selected['device']['usb_id'],
            'recognized_family': selected['device']['recognized'], 'gain_db': gain,
            'hardware_volume': hardware_volume, 'make_default': make_default,
            'files': [str(p) for p in payloads], 'vendor_usb_writes': False}
    if dry_run:
        return plan
    if os.geteuid() == 0:
        raise ValueError('Run setup as your desktop user, without sudo')
    require_commands('pactl', 'pipewire', 'systemctl')
    if any(s['name'] == audio.SOURCE_NAME for s in sources()):
        raise ValueError('ALC408x virtual source already exists; remove its setup before reconfiguring')
    metadata = {**plan, 'default_before': run('pactl', 'get-default-source'), 'master_before': source}
    install_files(manifest, payloads, metadata)
    try:
        run('pactl', 'set-source-mute', source['name'], 0)
        if hardware_volume == 'max':
            run('pactl', 'set-source-volume', source['name'], '100%')
        run('systemctl', '--user', 'daemon-reload')
        run('systemctl', '--user', 'enable', '--now', audio.UNIT)
        for _ in range(50):
            if any(s['name'] == audio.SOURCE_NAME for s in sources()):
                run('pactl', 'set-source-volume', audio.SOURCE_NAME, '100%')
                run('pactl', 'set-source-mute', audio.SOURCE_NAME, 0)
                if make_default:
                    run('pactl', 'set-default-source', audio.SOURCE_NAME)
                return {**plan, 'status': 'installed', 'virtual_source': audio.SOURCE_NAME}
            time.sleep(0.1)
        raise RuntimeError('Microphone source did not appear; inspect the user service journal')
    except BaseException:
        run('systemctl', '--user', 'disable', '--now', audio.UNIT, check=False)
        restore_source(metadata)
        for path in payloads:
            path.unlink()
        manifest.unlink()
        run('systemctl', '--user', 'daemon-reload', check=False)
        raise


def remove_user():
    if os.geteuid() == 0:
        raise ValueError('Run remove as your desktop user, without sudo')
    manifest, config, service = user_paths()
    if not manifest.exists():
        return {'status': 'not-installed'}
    metadata = json.loads(manifest.read_text())
    verify_manifest(metadata, {config, service, config.parent / 'wait_audio.py'})
    run('systemctl', '--user', 'disable', '--now', audio.UNIT)
    restore_source(metadata)
    for record in metadata['files']:
        Path(record['path']).unlink()
    manifest.unlink()
    run('systemctl', '--user', 'daemon-reload')
    return {'status': 'removed', 'scope': 'desktop'}


SYSTEM_UNIT = 'alc408x-mic-init.service'


def system_files(prefix=Path('/')):
    def p(relative):
        return prefix / relative
    unit = f'''[Unit]
Description=Verified Realtek USB rear microphone initialization
After=sound.target
StartLimitIntervalSec=60
StartLimitBurst=15

[Service]
Type=oneshot
ExecStart=/usr/bin/python3 /usr/local/lib/alc408x-mic/realtek_rear_mic.py apply
Restart=on-failure
RestartSec=2
NoNewPrivileges=yes
ProtectSystem=strict
ProtectHome=yes
PrivateTmp=yes

[Install]
WantedBy=multi-user.target
'''
    rule = f'ACTION=="add", SUBSYSTEM=="sound", KERNEL=="card[0-9]*", ATTRS{{idVendor}}=="0b05", ATTRS{{idProduct}}=="1b9b", TAG+="systemd", ENV{{SYSTEMD_WANTS}}+="{SYSTEM_UNIT}"\n'
    resume = f'#!/bin/sh\nif [ "$1" = post ]; then\n    /usr/bin/systemctl --no-block restart {SYSTEM_UNIT}\nfi\n'
    return p('var/lib/alc408x-mic/install.json'), {
        p('usr/local/lib/alc408x-mic/realtek_rear_mic.py'): (Path(realtek_rear_mic.__file__).read_bytes(), 0o644),
        p(f'etc/systemd/system/{SYSTEM_UNIT}'): (unit.encode(), 0o644),
        p('etc/udev/rules.d/90-alc408x-mic.rules'): (rule.encode(), 0o644),
        p('usr/lib/systemd/system-sleep/alc408x-mic'): (resume.encode(), 0o755)}


def install_system(dry_run=False):
    # This guard includes the board, firmware revision, descriptors and driver.
    device = realtek_rear_mic.discover_device()
    manifest, payloads = system_files()
    plan = {'scope': 'system', 'profile': 'asus-x870e-e-rear', 'board': device.board,
            'files': [str(p) for p in payloads], 'vendor_usb_writes': True}
    if dry_run:
        return plan
    if os.geteuid() != 0:
        raise ValueError('Run install-system with sudo')
    require_commands('systemctl', 'udevadm')
    install_files(manifest, payloads, plan)
    try:
        run('systemctl', 'daemon-reload')
        run('udevadm', 'control', '--reload-rules')
        run('systemctl', 'enable', '--now', SYSTEM_UNIT)
    except BaseException:
        run('systemctl', 'disable', '--now', SYSTEM_UNIT, check=False)
        for path in payloads:
            path.unlink()
        manifest.unlink()
        run('systemctl', 'daemon-reload', check=False)
        run('udevadm', 'control', '--reload-rules', check=False)
        raise
    return {**plan, 'status': 'installed'}


def remove_system():
    if os.geteuid() != 0:
        raise ValueError('Run remove-system with sudo')
    manifest, payloads = system_files()
    if not manifest.exists():
        return {'status': 'not-installed'}
    metadata = json.loads(manifest.read_text())
    verify_manifest(metadata, set(payloads))
    run('systemctl', 'disable', '--now', SYSTEM_UNIT)
    for record in metadata['files']:
        Path(record['path']).unlink()
    manifest.unlink()
    run('systemctl', 'daemon-reload')
    run('udevadm', 'control', '--reload-rules')
    return {'status': 'removed', 'scope': 'system', 'current_hardware_mode': 'unchanged'}

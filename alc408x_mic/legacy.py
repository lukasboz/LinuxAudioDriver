"""Remove earlier machine-specific installations without their original checkout."""

import json
import os
from pathlib import Path

from . import installer


def paths(scope, home=None):
    if scope == 'system':
        return Path('/var/lib/realtek-rear-mic/install.json'), {
            Path('/usr/local/lib/realtek-rear-mic/realtek_rear_mic.py'),
            Path('/etc/systemd/system/realtek-rear-mic.service'),
            Path('/etc/udev/rules.d/90-realtek-rear-mic.rules'),
            Path('/usr/lib/systemd/system-sleep/realtek-rear-mic')}
    if scope != 'desktop':
        raise ValueError('Choose desktop or system')
    base = (home or Path.home()) / '.config'
    return base / 'realtek-rear-mic/install.json', {
        base / 'pipewire/g335-rear-microphone.conf',
        base / 'pipewire/g335-wait-audio.py',
        base / 'systemd/user/g335-rear-microphone.service'}


def remove(scope, dry_run=False):
    manifest, allowed = paths(scope)
    if not dry_run and (scope == 'system') != (os.geteuid() == 0):
        raise ValueError('Use sudo for system removal and the desktop user for desktop removal')
    if not manifest.exists():
        return {'status': 'not-installed', 'scope': scope}
    metadata = json.loads(manifest.read_text())
    # Validate the complete list and every hash before stopping any service.
    installer.verify_manifest(metadata, allowed)
    plan = {'scope': scope, 'files': [r['path'] for r in metadata['files']]}
    if dry_run:
        return {**plan, 'status': 'planned'}
    if scope == 'system':
        installer.run('systemctl', 'disable', '--now', 'realtek-rear-mic.service')
    else:
        installer.run('systemctl', '--user', 'disable', '--now', 'g335-rear-microphone.service')
        names = {s['name'] for s in installer.sources()}
        before = metadata.get('master_before')
        if before and before['name'] in names:
            installer.run('pactl', 'set-source-volume', before['name'],
                          *[v['value'] for v in before['volume'].values()])
            installer.run('pactl', 'set-source-mute', before['name'], int(before['mute']))
        if metadata.get('default_before') in names:
            installer.run('pactl', 'set-default-source', metadata['default_before'])
    for record in metadata['files']:
        Path(record['path']).unlink()
    manifest.unlink()
    if scope == 'system':
        installer.run('systemctl', 'daemon-reload')
        installer.run('udevadm', 'control', '--reload-rules')
    else:
        installer.run('systemctl', '--user', 'daemon-reload')
    return {**plan, 'status': 'removed', 'current_hardware_mode': 'unchanged'}

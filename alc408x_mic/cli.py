"""Command-line interface; ordinary setup never sends vendor USB commands."""

import argparse
from dataclasses import asdict
import json
import platform
import sys

import realtek_rear_mic

from . import __version__, audio, hardware, installer, legacy


def parser():
    command = argparse.ArgumentParser(description='Configure an ALC4080/4082 USB microphone on Linux')
    command.add_argument('--version', action='version', version=__version__)
    actions = command.add_subparsers(dest='action', required=True)
    detect = actions.add_parser('detect', help='List USB audio devices, capture routes and initialization support')
    detect.add_argument('--hardware-only', action='store_true', help='Do not connect to the desktop audio session')
    setup = actions.add_parser('setup', help='Install a configurable PipeWire microphone source for this user')
    setup.add_argument('--source', help='Exact capture node name from detect; required when routes are ambiguous')
    setup.add_argument('--gain', type=float, help='0–48 dB; default 30 on the verified rear route, otherwise 0')
    setup.add_argument('--hardware-volume', choices=['current', 'max'], default='current')
    setup.add_argument('--no-default', action='store_true', help='Keep the existing default input')
    setup.add_argument('--dry-run', action='store_true')
    actions.add_parser('status', help='Show installed configuration and the current desktop input')
    actions.add_parser('remove', help='Remove this user setup and restore the previous input/settings')
    init = actions.add_parser('install-system', help='Install hardware initialization for a verified profile (sudo)')
    init.add_argument('--dry-run', action='store_true')
    actions.add_parser('remove-system', help='Remove hardware initialization (sudo)')
    old = actions.add_parser('remove-legacy', help='Remove an earlier machine-specific installation')
    old.add_argument('scope', choices=['desktop', 'system'])
    old.add_argument('--dry-run', action='store_true')
    apply = actions.add_parser('apply', help='Apply the verified hardware profile once (sudo)')
    apply.add_argument('--dry-run', action='store_true')
    return command


def main(argv=None):
    command = parser()
    args = command.parse_args(argv)
    try:
        if sys.platform != 'linux':
            raise ValueError('This tool requires Linux with snd-usb-audio; it is not a Windows driver installer')
        if args.action == 'detect':
            devices = hardware.discover()
            result = {'version': __version__, 'kernel': platform.release(),
                      'devices': [{**asdict(d), 'hardware_profile': hardware.verified_profile(d)} for d in devices],
                      'catalog_source': hardware.CATALOG['source'],
                      'capture_sources': [], 'vendor_usb_writes': False}
            if not args.hardware_only:
                try:
                    captures = hardware.capture_sources(installer.sources(), devices, explicit=True)
                    result['capture_sources'] = [{k: v for k, v in s.items() if k != 'source'} for s in captures]
                except (RuntimeError, OSError) as error:
                    result['desktop_audio_error'] = str(error)
        elif args.action == 'setup':
            selected = hardware.select_source(installer.sources(), hardware.discover(), args.source)
            gain = args.gain
            if gain is None:
                gain = 30 if selected['hardware_profile'] and selected['pcm'] == 1 else 0
            result = installer.install_user(selected, gain, args.hardware_volume,
                                            not args.no_default, args.dry_run)
        elif args.action == 'status':
            manifest, _, _ = installer.user_paths()
            result = {'installed': manifest.exists(),
                      'default_source': installer.run('pactl', 'get-default-source'),
                      'filter_active': installer.run('systemctl', '--user', 'is-active', audio.UNIT, check=False),
                      'source': next((s for s in installer.sources() if s['name'] == audio.SOURCE_NAME), None)}
            if manifest.exists():
                result['configuration'] = json.loads(manifest.read_text())
        elif args.action == 'remove':
            result = installer.remove_user()
        elif args.action == 'install-system':
            result = installer.install_system(args.dry_run)
        elif args.action == 'remove-system':
            result = installer.remove_system()
        elif args.action == 'remove-legacy':
            result = legacy.remove(args.scope, args.dry_run)
        else:
            device = realtek_rear_mic.discover_device()
            result = (realtek_rear_mic.plan() if args.dry_run else realtek_rear_mic.execute(device, 'apply'))
        print(json.dumps(result, indent=2))
        return 0
    except (ValueError, RuntimeError, OSError, KeyError) as error:
        print(json.dumps({'status': 'error', 'error': str(error)}, indent=2), file=sys.stderr)
        return 1
    except KeyboardInterrupt:
        print('Interrupted; inspect status before retrying.', file=sys.stderr)
        return 130


if __name__ == '__main__':
    raise SystemExit(main())

#!/usr/bin/env python3
"""Wait for an actual capture source before/after starting a PipeWire filter.

Copied as a standalone user helper, so installed services survive checkout or
Python-package removal. This helper never sends vendor USB commands.
"""

import argparse
import json
from pathlib import Path
import subprocess
import sys
import time


def get_sources():
    process = subprocess.run(['pactl', '--format=json', 'list', 'sources'],
                             capture_output=True, text=True, timeout=2)
    if process.returncode:
        raise RuntimeError(process.stderr.strip() or 'Desktop audio server is not ready')
    return json.loads(process.stdout)


def capture_present(sources, name):
    return any(s.get('name') == name and not s.get('monitor_source')
               and s.get('properties', {}).get('media.class') == 'Audio/Source'
               for s in sources)


def wait_for_source(name, timeout=30, fetch=get_sources, clock=time.monotonic, sleep=time.sleep):
    deadline = clock() + timeout
    last_error = ''
    while True:
        try:
            if capture_present(fetch(), name):
                return
        except (RuntimeError, OSError, ValueError, subprocess.TimeoutExpired) as error:
            last_error = str(error)
        remaining = deadline - clock()
        if remaining <= 0:
            raise TimeoutError(f'Capture source {name!r} did not appear: {last_error or "source missing"}')
        sleep(min(0.25, remaining))


def filter_names(config):
    filters = [m['args'] for m in config.get('context.modules', [])
               if m.get('name') == 'libpipewire-module-filter-chain']
    if len(filters) != 1:
        raise ValueError('Expected exactly one microphone filter in the configuration')
    master = filters[0]['capture.props']['target.object']
    output = filters[0]['playback.props']['node.name']
    if not isinstance(master, str) or not master or not isinstance(output, str) or not output:
        raise ValueError('Filter source names must be nonempty strings')
    return master, output


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--config', required=True, type=Path)
    parser.add_argument('--kind', required=True, choices=['master', 'output'])
    parser.add_argument('--timeout', type=float, default=30)
    parser.add_argument('--select', action='store_true')
    parser.add_argument('--state', type=Path, help='Select output only when saved make_default is true')
    args = parser.parse_args()
    if not 0 < args.timeout <= 120:
        parser.error('Timeout must be between 0 and 120 seconds')
    try:
        master, output = filter_names(json.loads(args.config.read_text()))
        name = master if args.kind == 'master' else output
        wait_for_source(name, args.timeout)
        select = args.select or (args.state is not None and
                                json.loads(args.state.read_text()).get('make_default', False))
        if args.kind == 'output' and select:
            subprocess.run(['pactl', 'set-default-source', output], check=True,
                           capture_output=True, text=True, timeout=5)
        print(f'{args.kind} capture source ready: {name}', flush=True)
        return 0
    except (OSError, ValueError, RuntimeError, KeyError, subprocess.SubprocessError) as error:
        print(str(error), file=sys.stderr)
        return 1


if __name__ == '__main__':
    raise SystemExit(main())

#!/usr/bin/env python3
"""Build a small portable release and a Debian/Ubuntu package without driver binaries."""

import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tarfile
import tempfile

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / 'dist'
sys.path.insert(0, str(ROOT))
from alc408x_mic import __version__


def main():
    version = __version__
    name = f'alc408x-mic-{version}'
    OUT.mkdir(exist_ok=True)
    with tempfile.TemporaryDirectory(prefix='alc408x-build-') as temp:
        stage = Path(temp) / name
        stage.mkdir()
        package = stage / 'alc408x_mic'
        package.mkdir()
        for file in sorted((ROOT / 'alc408x_mic').iterdir()):
            if file.suffix in ('.py', '.json'):
                shutil.copyfile(file, package / file.name)
        for file in ('realtek_rear_mic.py', 'pyproject.toml', 'INSTALL.md'):
            shutil.copyfile(ROOT / file, stage / file)
        # The standalone archive needs instructions for its own contents, not
        # the investigation README's checkout-only diagnostics and evidence.
        shutil.copyfile(ROOT / 'INSTALL.md', stage / 'README.md')
        launcher = stage / 'alc408x-mic'
        launcher.write_text('#!/usr/bin/env python3\nfrom alc408x_mic.cli import main\nraise SystemExit(main())\n')
        launcher.chmod(0o755)
        archive = OUT / f'{name}.tar.gz'
        with tarfile.open(archive, 'w:gz') as tar:
            for path in sorted(stage.rglob('*')):
                tar.add(path, arcname=f'{name}/{path.relative_to(stage)}', recursive=False)
        deb = Path(temp) / 'deb'
        dist_packages = deb / 'usr/lib/python3/dist-packages'
        dist_packages.mkdir(parents=True)
        shutil.copytree(package, dist_packages / 'alc408x_mic')
        shutil.copyfile(stage / 'realtek_rear_mic.py', dist_packages / 'realtek_rear_mic.py')
        (deb / 'usr/bin').mkdir()
        shutil.copyfile(launcher, deb / 'usr/bin/alc408x-mic')
        (deb / 'usr/bin/alc408x-mic').chmod(0o755)
        docs = deb / 'usr/share/doc/alc408x-mic'
        docs.mkdir(parents=True)
        shutil.copyfile(ROOT / 'INSTALL.md', docs / 'INSTALL.md')
        (deb / 'DEBIAN').mkdir()
        (deb / 'DEBIAN/control').write_text(f'''Package: alc408x-mic
Version: {version}
Section: sound
Priority: optional
Architecture: all
Maintainer: LinuxAudioDriver project <noreply@localhost>
Depends: python3 (>= 3.10), pipewire-bin, pipewire-pulse, wireplumber, pulseaudio-utils, alsa-ucm-conf, systemd, udev
Description: Configurable Realtek ALC4080/4082 microphone setup
 Portable PipeWire input selection and gain, with separately enabled,
 device-specific hardware initialization. Installing the package alone
 does not change audio settings or send USB commands.
''')
        environment = {**os.environ, 'SOURCE_DATE_EPOCH': '1795305600'}
        subprocess.run(['dpkg-deb', '--root-owner-group', '--build', str(deb),
                        str(OUT / f'alc408x-mic_{version}_all.deb')], check=True, env=environment)
        # Keep setuptools' build directories and metadata out of the checkout.
        subprocess.run([sys.executable, '-m', 'pip', 'wheel', '--no-cache-dir', '--no-index',
                        '--no-deps', '--no-build-isolation', str(stage), '--wheel-dir', str(OUT)],
                       check=True, env=environment)
    for path in (archive, OUT / f'alc408x-mic_{version}_all.deb',
                 OUT / f'alc408x_mic-{version}-py3-none-any.whl'):
        checksum = hashlib.sha256(path.read_bytes()).hexdigest()
        path.with_name(path.name + '.sha256').write_text(f'{checksum}  {path.name}\n')
        print(json.dumps({'path': str(path), 'bytes': path.stat().st_size, 'sha256': checksum}))


if __name__ == '__main__':
    main()

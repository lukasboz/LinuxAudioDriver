# ALC4080 / ALC4082 microphone workaround

Configure USB microphone capture and software gain on Linux with PipeWire.
The installer includes guarded rear-microphone initialization for the ASUS
ROG STRIX X870E-E GAMING WIFI (`0b05:1b9b`, revision `0013`).

## Install

On a supported ASUS system using Debian or Ubuntu:

```bash
sudo apt install ./dist/alc408x-mic_0.2.2_all.deb
sudo alc408x-mic install-system
alc408x-mic setup --gain 30 --hardware-volume max
alc408x-mic status
```

Use [INSTALL.md](INSTALL.md) for portable installation, source selection,
configuration options and removal. Packages and their SHA-256 checksums are in
[dist/](dist/).

## Compatibility

| Feature | Support |
|---|---|
| USB audio discovery | Devices using `snd-usb-audio` |
| ALC4080/4082 recognition | 63 USB IDs from the ALSA UCM catalogue |
| Persistent software gain | Selected mono or stereo USB capture sources |
| Rear microphone hardware initialization | Verified ASUS X870E-E profile only |

Other boards can use source selection and software gain. Hardware
initialization requires a verified profile; sharing a codec family does not
establish compatible vendor commands. Gain cannot recover an input with
missing hardware routing or microphone bias.

The ASUS workaround uses rear PCM 1 / Line capture, the microphone mode
selection and +30 dB of software gain. Automatic startup and usable speech have
been verified after a full power-off boot on that board. Suspend/resume,
plug cycles and other motherboard initialization profiles remain unverified.

## Development

```bash
python3 -m unittest discover -s tests -v
python3 tools/build_release.py
```

Building requires Python 3.10+, pip, setuptools, wheel and `dpkg-deb`. The build
produces a Debian package, portable Linux archive and Python wheel without
fetching dependencies. Runtime requirements are listed in
[INSTALL.md](INSTALL.md).

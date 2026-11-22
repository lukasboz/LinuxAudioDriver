# Installation

`alc408x-mic` configures microphone capture using the existing Linux
`snd-usb-audio` driver, PipeWire and WirePlumber. It supports mono or stereo USB
inputs and adjustable software gain. Hardware initialization is available for
the verified ASUS ROG STRIX X870E-E GAMING WIFI profile only.

## Debian and Ubuntu

Install the package from `dist/`:

```bash
sudo apt install ./alc408x-mic_0.2.2_all.deb
alc408x-mic detect
```

Run the command from the directory containing the package. Installing the
package adds the command and documentation. Run the setup commands below to
configure audio.

Dependencies: Python 3.10+, PipeWire binaries, PipeWire's PulseAudio server,
WirePlumber, PulseAudio command-line utilities, ALSA UCM configuration, systemd
and udev. The Debian package declares these dependencies. No custom kernel
module or Secure Boot changes are required.

## Portable installation

Install the same runtime dependencies using your distribution's package
manager, then extract the archive:

```bash
tar -xzf alc408x-mic-0.2.2.tar.gz
cd alc408x-mic-0.2.2
./alc408x-mic detect
```

Use `./alc408x-mic` in place of `alc408x-mic` in the commands below, including
`sudo ./alc408x-mic install-system` when enabling the supported hardware profile.
The archive can also be installed into a Python virtual environment using
`pip install .`. The Python package has no third-party Python runtime
dependencies. A wheel is supplied in `dist/` as well.

## Verified ASUS rear microphone

For ASUS ROG STRIX X870E-E GAMING WIFI, USB `0b05:1b9b`, revision `0013`:

```bash
sudo alc408x-mic install-system
alc408x-mic setup --gain 30 --hardware-volume max
alc408x-mic status
```

Connect the headset splitter to the rear output and microphone jacks and lower
its microphone boom. This profile selects PCM 1 / Line capture. The hardware
helper checks the motherboard, USB identity and revision, interface/endpoint
topology, ALSA association and driver binding before sending the microphone
mode request (`40/6c`, value 0, index 1, one byte `13`). It also revalidates the
opened device identity before writing.

The hardware service runs at boot. A udev rule requests initialization when the
sound device appears, and a sleep hook requests it after resume. Installed
helpers are copied into root-owned paths and do not depend on the checkout.
Automatic startup has been verified after a full power-off boot on this board;
real suspend/resume and plug cycles still need validation.

## Other devices and source selection

```bash
alc408x-mic detect
alc408x-mic setup --source 'COPIED_CAPTURE_NODE' --gain 20 --dry-run
alc408x-mic setup --source 'COPIED_CAPTURE_NODE' --gain 20
```

Copy the capture source's exact name from `detect`. Front and rear capture PCMs
vary between boards, so choose a route that contains microphone speech. The
kernel and ALSA UCM configuration must expose that route to PipeWire.

The catalogue recognizes 63 ALC4080/4082 USB IDs across several vendors.
Unlisted USB capture devices can be selected explicitly with `--source`.
Recognition does not enable vendor commands: `install-system` and `apply`
refuse hardware outside the verified ASUS profile. Software gain cannot repair
missing hardware routing or bias on another board.

## Gain and startup

The new input is **ALC4080/4082 Microphone** (`alc408x_microphone`). It becomes
the desktop default. Select it explicitly in applications that maintain their
own input selection. Use `--no-default` to preserve the existing default.

Gain accepts 0–48 dB. Without `--gain`, the default is 30 dB for the verified
ASUS rear route and 0 dB for other inputs. Start at 0 dB for an input with normal
levels. `--hardware-volume max` raises exposed capture gain; otherwise its
volume is preserved. Setup unmutes the selected source. The normal desktop
input slider can reduce the output level.

The filter uses three linear gain stages per channel to stay within each
stage's supported range. Its user service waits for the actual capture source,
verifies the virtual output appears and then selects the configured default.
Failed startup checks cause a service restart.

## Verify

```bash
alc408x-mic status
pw-record --target=alc408x_microphone microphone.wav
```

Speak normally, press Ctrl+C, then play the recording:

```bash
pw-play microphone.wav
```

Check an ordinary application using the default input as well. Validate cold
boot, suspend/resume and device reconnection on the machine being configured.

## Remove or reconfigure

To change source or gain, remove the setup and run `setup` again. To remove the
workaround:

```bash
alc408x-mic remove
sudo alc408x-mic remove-system
```

Run these commands before uninstalling the package or deleting the portable
installation. Removal checks file hashes, preserves modified files and
restores the previous input/default and volume/mute when available. Removing
the initialization service leaves the current hardware mode in place until
power-off or reset.

User files are under `~/.config/alc408x-mic/`, with the user unit
`alc408x-microphone.service`. Root initialization is recorded under
`/var/lib/alc408x-mic/`, with helper code under `/usr/local/lib/alc408x-mic/`.

Earlier machine-specific installations using **Logitech G335 Rear Microphone**
remain independent. When replacing one with this package, remove it with:

```bash
alc408x-mic remove-legacy desktop --dry-run
alc408x-mic remove-legacy desktop
sudo alc408x-mic remove-legacy system
```

These commands validate the earlier installation's manifest, allowed paths and
file hashes before making changes. They do not require the earlier checkout.

## Sources

The USB ID catalogue and board-dependent routes follow the upstream
[USB-Audio configuration](https://github.com/alsa-project/alsa-ucm-conf/blob/master/ucm2/USB-Audio/USB-Audio.conf)
and [ALC4080/4082 mappings](https://github.com/alsa-project/alsa-ucm-conf/blob/master/ucm2/USB-Audio/Realtek/ALC4080-HiFi.conf).

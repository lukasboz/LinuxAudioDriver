# Initial Ubuntu findings supplied by the user

These facts are extracted from the user's pasted commands, not independently measured by the implementation session.

| Item | Observed value |
|---|---|
| OS | Ubuntu 26.04.1 LTS, Resolute Raccoon |
| Running kernel | `7.0.0-34-generic` |
| Motherboard USB audio | `0b05:1b9b`, Generic USB Audio |
| USB address in this boot | Bus 003, device 006 |
| ALSA card | 3, ID `Audio_1` |
| Physical USB path | `usb-0000:13:00.0-6`, sysfs `usb3/3-6` |
| Driver | `snd_usb_audio` |
| Playback devices | 0, 1, 2, 3 |
| Capture devices | 0, 1, 2 |
| Active desktop profile | `HiFi` |
| Rear input port | `[In] Line`, available |
| Microphone port | `[In] Mic`, not available |
| Default desktop source | UVC Camera Mono |
| UCM package | `1.2.15.3-1ubuntu1.5` |
| ALSA utilities | `1.2.15.2-1ubuntu1` |
| ALSA library | `1.2.15.3-1ubuntu1.1` |
| PipeWire | `1.6.2-1ubuntu1.2` |
| WirePlumber | `0.5.13-1ubuntu1` |
| Boot provenance | Restart from Windows after confirming the headset microphone worked there |

The Logitech G335 uses its Y-splitter in the motherboard's rear LINE OUT and MIC IN jacks. Headphone playback works. Ubuntu lists the rear input as “USB Audio Line Input (plugged in)” but there is no microphone audio.

The existing HiFi profile and source ports demonstrate that UCM is already active. There is no basis for proposing a missing-ID-only fix. The webcam default could independently route an application's recording to the wrong source; it does not explain a verified silent direct hardware recording, which has not been performed yet.

The Line/Mic availability mismatch is a clue that requires the mixer topology and direct capture recordings. This output provides neither `/proc/asound/card3/usbmixer` nor `stream*` descriptors, detailed mixer controls, raw recordings, or a cold-boot comparison. It therefore does not yet distinguish a UCM mapping problem from missing device initialization.

Next: run the collector, jack monitor, and direct capture test, review the WAV recordings, and repeat with a cold-boot label. The diagnostic tools discover the card afresh; card number 3 and bus/device address 003/006 are observations from this boot, not permanent identifiers.

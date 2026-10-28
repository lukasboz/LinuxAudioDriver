# Next experiment after test_1

**Status update:** the cold comparison and complete archive are now received, and the user confirms no intelligible voice in either boot condition. See `../test_2/ANALYSIS.md` for archive verification and `../../USB_CAPTURE.md` for the current experiment. The original jack monitors failed because of an argument bug, now fixed; repeat only that short stage with the updated script. The cold capture matrix below is completed and does not need repetition.

All 12 direct ALSA recordings completed successfully, the exposed capture routes were tested at maximum gain, and the user confirmed no intelligible voice in any recording. Investigate missing device/driver microphone setup. The precise operation is not identified yet.

## 1. Establish a direct cold Ubuntu baseline

Shut down, remove standby power until the motherboard lights extinguish, restore power, and boot directly into Ubuntu. Keep the splitter, BIOS, and packages unchanged. In the project directory, run as your ordinary desktop user:

```bash
python3 audio_diag.py collect --boot cold
python3 audio_diag.py jacks --boot cold
python3 audio_diag.py test --boot cold
```

The monitor runs for 20 seconds: unplug/reinsert only the rear microphone plug. The test then repeats the controlled capture matrix, including checking whether the route-to-PCM behavior changes between boot conditions. Follow the silent-then-speech instructions.

After restoration, review the new test directory printed by the script:

```bash
python3 audio_diag.py review "diagnostics/REPLACE-WITH-THE-NEW-TEST-DIRECTORY"
```

If the desktop playback check is inaudible, select a working headset output or supply the correct `--target` node name as described in `README.md`.

## 2. Transfer the complete evidence

Bring the entire warm and cold collector/jack directories into the workspace, as well as the cold test's result/summary and per-trial mixer/arecord logs. The warm `results.json` already transferred is useful, but its control list does not contain the complete USB descriptors, USB mixer-unit topology, installed UCM configuration, or jack event timeline.

An easy way to retain all runs in one local archive is this standard-library command, run from the Ubuntu project directory:

```bash
python3 -m zipfile -c full-diagnostics.zip diagnostics
```

Copy that archive into `observations/test_2`, or copy the run directories directly. The archive includes recordings; if you want to keep them local, copy only the collector/jack directories and the test's `.json`, `.md`, `.txt`, `.jsonl`, and `.state` files. Nothing is uploaded automatically.

Do not edit the original JSON to claim a cold boot or completed review. Preserve the original boot condition and use the new run for the cold comparison.

## 3. If cold capture is also unusable, collect the Windows reference

The next substantive investigation is a USB trace comparison. It must capture the internal motherboard audio device `0b05:1b9b`, not the analog Logitech headset.

On Windows:

1. Record the ASUS/Realtek audio driver provider/version and the current Windows jack assignment.
2. Install/use Wireshark with USBPcap. Identify the root hub containing the motherboard audio device; retain its enumeration/descriptors so a changing USB address can be tracked.
3. Start capture before the target audio device is initialized. A capture running only after opening Wireshark may miss boot initialization. Restarting only the identified audio device while capture is active is one way to investigate setup; if that does not reproduce it, boot-time capture is needed. An analog jack unplug alone does not re-enumerate the USB codec.
4. Record action times for microphone removal/insertion, any Realtek microphone/line-mode selection, recording start/stop, and available gain/boost adjustments. Confirm working voice at the relevant times.
5. Preserve the original capture and an action timeline. Export the audio device's relevant interfaces/control traffic for sharing rather than assuming all significant traffic is on one interface.

The Linux comparison uses `usbmon` on the verified USB bus with the same jack and capture actions. Analyze standard Audio Class requests as well as any HID/vendor messages. The capture/controller details will be chosen from the collected descriptors before providing a device-specific experiment. Sending guessed commands or replaying an entire Windows trace is not a suitable next test.

Primary capture references: [Wireshark USB capture](https://wiki.wireshark.org/CaptureSetup/USB), [USBPcap setup](https://desowin.org/usbpcap/tour.html), and the ALSA maintainer's [ALC4080 investigation guidance](https://github.com/alsa-project/alsa-ucm-conf/issues/541).

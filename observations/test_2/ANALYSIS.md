# Cold-boot comparison: test_2

Inspected files: `results (2).json` and `SUMMARY (1).md`, compared with `../test_1/results.json`, followed by the complete `../diagnostics.zip` archive. The original JSON has no saved listening reviews, but the user subsequently confirmed: **"i can confirm i hear nothing."** That confirmation is recorded in `LISTENING_REVIEW.json`. Recordings were independently reanalyzed for validity and levels, but not independently listened to by this session.

## Capture validity and identity

- The run is labelled `cold` and was recorded at `2026-10-03T23:43:00.513349+00:00`.
- All 12 planned captures report `ok`, with 384,000 frames each: eight seconds of stereo S16_LE at 48 kHz.
- No restoration errors are reported; this was not a dry run.
- Target identity is unchanged: USB `0b05:1b9b`, raw `bcdDevice` value `0013`, ALSA card 3 / `Audio_1`, physical USB port `usb3/3-6`. The USB device address changed from 6 to 5; the physical path and IDs match.
- Initial controls, recognized capture routes, and PCM formats are identical to the warm run. No additional source selectors or untested capture controls are listed.
- Initial jack states remain Line on, Analog In on, Mic off. The Mic capture switch is initially off, but isolated Mic trials test it enabled at maximum advertised capture gain.

## Warm versus cold measurements

The intended speech window is the last six seconds of each recording. These figures rely on the recording prompts having been followed; the analysis does not detect speech.

| Isolated capture route | Affected PCM | Warm speech RMS, channels 1 / 2 | Cold speech RMS, channels 1 / 2 | Cold RMS in signed 16-bit sample counts |
|---|---|---|---|---|
| Line, numid 13 | 1 | -83.38 / -83.41 dBFS | -91.88 / -91.81 dBFS | 0.83 / 0.84 |
| Mic, numid 17 | 2 | -91.92 / -91.96 dBFS | -91.91 / -92.01 dBFS | 0.83 / 0.82 |
| Analog In, numid 9 | 0 | -81.30 / -81.51 dBFS | -81.24 / -81.42 dBFS | 2.84 / 2.78 |

Sample-count RMS uses `32768 * 10 ** (rms_dbfs / 20)` for S16_LE.

In both runs, enabling each isolated capture switch produces nonzero samples only on its corresponding PCM: Analog In on PCM 0, Line on PCM 1, Mic on PCM 2. All six isolated recordings on the other PCMs contain exact digital silence. The original-state recordings have nonzero PCM 0 and PCM 1, and zero PCM 2.

The Mic and Analog In speech-window levels differ by at most 0.09 dB between boots. Line is about 8.4-8.5 dB quieter after the cold boot. This is a measured difference, not evidence of working warm-boot microphone capture: the user confirmed no intelligible voice anywhere in the warm recordings.

Cold recordings have more energy during their first two seconds than in the intended speech window. For example, isolated Analog In has initial RMS -58.33/-63.39 dBFS and later RMS -81.24/-81.42 dBFS. Whole-file levels therefore overstate the sustained later signal. Identifying startup transients or speech requires listening or waveform inspection.

## Decision

**Chosen branch: investigate device/driver microphone setup below UCM.** Both tested boot conditions fail to provide intelligible voice through the available direct ALSA capture routes, according to the user's listening checks. A UCM-only patch has no demonstrated working hardware route to expose. Input mode, bias, hardware gain, firmware behavior, and USB initialization remain hypotheses; no specific missing command is proven.

## Complete archive verification

The user supplied `observations/diagnostics.zip`, SHA-256:

```text
d1f2b9232685cda16fe5dba1a0bc290b17398b71d54653b47bedaa6c8e29b3a9
```

CRC verification passed. Its 525 entries were extracted without overwriting supplied results into `observations/imported_diagnostics`. It contains six runs:

| Boot | Collector | Jack monitor | Direct test |
|---|---|---|---|
| Windows warm | `20261003T194200.496959Z-collect` | `20261003T194200.982122Z-jacks` | `20261003T194201.057160Z-test` |
| Cold | `20261003T234259.934341Z-collect` | `20261003T234300.420906Z-jacks` | `20261003T234300.495571Z-test` |

The imported result JSONs match the previously supplied test_1/test_2 JSONs exactly as parsed. Reanalyzing all 24 WAV files reproduces every saved analysis dictionary. Each isolated trial's mixer log confirms its chosen switch is on, the other two capture switches are off, and the selected volume is `39,39` (+12 dB). All logged commands in both direct tests report `ok`.

Collectors confirm the motherboard as **ROG STRIX X870E-E GAMING WIFI**, Rev 1.xx, BIOS 2202 with date string `04/09/2026`. Kernel and packages match the initial report. Opening the UCM configuration did not change the mixer snapshots in either collector.

USB descriptors show Audio Class 2 control interface 0; Analog In, Line, and Mic streaming interfaces 1, 2, and 3; playback interfaces 4-6; and HID interface 7. Capture endpoints are respectively `0x81`, `0x83`, and `0x84`. Feature Units 25, 27, and 28 expose mute and channel volumes. The installed UCM maps Line to PCM 1 and Mic to PCM 2. Analog In PCM 0 was also tested directly, even though this board's installed profile does not expose it as a separate source.

The HID interface advertises a 34-byte report descriptor and interrupt endpoint `0x8a`. The unprivileged `lsusb` query reports it unavailable and warns that some information is missing. The collector's zero exit status is therefore not proof of a complete HID descriptor capture. Presence of HID does not prove that missing microphone initialization uses it; include it alongside Audio Class control traffic in the Windows reference.

## Jack monitor defect and correction

Both original jack monitors failed immediately with exit status 2:

```text
alsa-lib control.c:1575:(snd_ctl_open_noupdate) [error.control] Invalid CTL Audio_1
Cannot open ctl Audio_1
```

They therefore provide no valid event timeline. Before/after jack snapshots alone cannot establish which detector responds to insertion. The failure is a bug in this diagnostic tool, not evidence that the kernel cannot monitor jacks. `alsactl monitor` accepts an ALSA control device name; the corrected tool uses `hw:Audio_1`. See the [ALSA implementation](https://github.com/alsa-project/alsa-utils/blob/master/alsactl/monitor.c).

The correction includes a regression fixture reproducing rejection of the bare ID. All 31 local tests pass. Copy the updated script and repeat only `jacks` on Ubuntu with the appropriate boot label; the direct capture matrices do not need repetition. Actual hardware validation of the corrected monitor remains pending.

## Next experiment

Follow [USB_CAPTURE.md](../../USB_CAPTURE.md) to record the working Windows reference with the complete device identity, an exact target-device restart, jack actions, and a recording timeline. USBPcap hub numbers must be discovered on Windows rather than copied from Linux. After inspecting that reference, choose the corresponding Linux usbmon experiment and any justified proof of concept. No guessed writes, whole-trace replay, or firmware changes are proposed.

Original supplied result and summary files are preserved unchanged.

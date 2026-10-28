# Analysis of test_1

Sources: the user-supplied `results.json` and `SUMMARY.md` in this directory, plus the user's subsequent listening confirmation: **“No intelligible voice in any recording.”** No WAV/raw recordings, per-trial command logs, collector directory, or jack-event logs were supplied here. The recordings have not been listened to by this session. All saved `voice_audible` reviews are absent in the original JSON; the user's confirmation is preserved separately in `LISTENING_REVIEW.json` without rewriting the supplied results.

## What the run establishes

- Target: ASUS USB audio `0b05:1b9b`, ALSA card 3, card ID `Audio_1`, physical port `usb3/3-6`, USB `bcdDevice` value `0013`.
- Boot condition: `windows-warm`, meaning Ubuntu was restarted into after a working Windows microphone session. This is not a cold-boot result.
- All 12 recordings have successful statuses, 384,000 frames, eight-second durations, and stereo S16_LE at 48 kHz.
- The tool reports no restoration errors.
- The initial controls contain Line and Analog In capture switches on, Mic capture switch off. Read-only jack controls report Line on, Analog In on, and Mic off.
- Line Capture Volume was already at its advertised maximum, 39/39. Mic and Analog In volumes were initially 23/23; their isolated trials requested maximum gain.
- No additional input selectors or untested capture controls were identified in the saved control list.

The isolated trial matrix demonstrates the following ALSA control-to-PCM relationship. This establishes which capture mute control affects each PCM; it does **not** establish which physical jack carries microphone speech.

| Enabled capture route | PCM 0 | PCM 1 | PCM 2 |
|---|---|---|---|
| Line, numid 13 | Exact digital silence | Nonzero samples | Exact digital silence |
| Mic, numid 17 | Exact digital silence | Exact digital silence | Nonzero samples |
| Analog In, numid 9 | Nonzero samples | Exact digital silence | Exact digital silence |

The baseline PCM 0 and PCM 1 recordings are nonzero; baseline PCM 2 is zero, consistent with their initial switch states. ALSA streams and mute routing are functioning. These observations do not prove that the rear jack has the correct analog microphone mode, bias, or gain.

## Signal levels during the intended speech portion

The tool labels the first two seconds as initial silence and the remaining six seconds as the speech window, based on its instructions to the user. It does not detect when speech actually occurred. The figures below rely on those instructions having been followed.

| Recording | Capture path | Channel 1 speech RMS | Channel 2 speech RMS | Approximate RMS in signed 16-bit sample counts |
|---|---|---|---|---|
| `05-pcm1-switch13-max.wav` | Line / PCM 1 | -83.38 dBFS | -83.41 dBFS | 2.22 / 2.21 |
| `09-pcm2-switch17-max.wav` | Mic / PCM 2 | -91.92 dBFS | -91.96 dBFS | 0.83 / 0.83 |
| `10-pcm0-switch9-max.wav` | Analog In / PCM 0 | -81.30 dBFS | -81.51 dBFS | 2.82 / 2.75 |

Sample-count RMS is computed as `32768 * 10 ** (rms_dbfs / 20)` for the S16_LE recordings. These are extremely small signals. Nonzero values at this level may be noise or a very weak signal; they are not proof of intelligible speech.

Analog In has substantially more energy in the initial two seconds than later: -59.89/-64.17 dBFS initial RMS versus -81.30/-81.51 dBFS later. This is consistent with a startup transient contributing to the overall level, but waveform inspection/listening is needed to identify it. Mic also has less energy in the intended speech portion than at startup. Line channel 1 increases 5.19 dB between the two windows, while channel 2 increases 1.08 dB; this could be a weak signal or changing noise and is not sufficient to classify speech.

## Decision and next evidence

**Chosen investigation branch: missing rear-microphone setup below UCM, including USB initialization.** The user's listening confirmation establishes that none of the successful hardware captures carries intelligible voice. These captures bypass desktop routing and exercise the available capture switches at maximum gain. A cosmetic jack-name change or adding the already-matched USB ID is not justified by this evidence. The precise missing operation (if any) remains unknown; input mode, microphone bias, hardware gain, firmware behavior, and other driver setup remain hypotheses.

1. Listening is now confirmed by the user. Running `audio_diag.py review` on the original Ubuntu test directory remains useful to save the reviews into the original result files, but another listening confirmation is not needed to select this investigation branch. The most informative isolated recordings are 05 (Line), 09 (Mic), and 10 (Analog In).
2. Supply the collector and jack-event logs, including `usbmixer`, `stream*`, USB descriptors, UCM dump/configuration, and the per-trial mixer/arecord logs. The JSON contains useful control snapshots but does not replace the USB topology and UCM evidence.
3. Repeat collection/capture after a direct Ubuntu boot with standby power removed, using `--boot cold`. Keep wiring, packages, and BIOS unchanged. A working warm recording alone would not prove Linux initializes the codec correctly.
4. If reviewed cold captures still have no usable voice with the available controls, proceed to comparing Windows USB initialization and jack-mode changes with Linux. If voice is demonstrated after a cold boot, investigate the corresponding PCM/control/jack mapping and desktop source selection before proposing driver commands.

Do not overwrite the user's original `results.json` or classify its noise as voice automatically. This report separates measurements from the user's listening evidence. A cold-boot comparison and descriptor/control logs remain outstanding.

## Upstream check following the results

The same-board [issue #718](https://github.com/alsa-project/alsa-ucm-conf/issues/718) still describes silent rear capture after UCM profile matching. The related same-ID [issue #780](https://github.com/alsa-project/alsa-ucm-conf/issues/780) describes a similar Line/Mic mismatch on another ASUS model. The maintainer's [issue #541](https://github.com/alsa-project/alsa-ucm-conf/issues/541) distinguishes absent driver functionality from profile mapping and recommends Windows USB capture when available ALSA controls cannot provide it. No verified command sequence for this board was found in the primary sources checked in this session. This is a scoped research finding, not a claim that no fix exists anywhere.

The [discussion in #317](https://github.com/alsa-project/alsa-ucm-conf/issues/317) also raises missing hardware microphone gain as a hypothesis on other ALC4080 boards; commenters disagree on aspects of Windows behavior. That discussion is not proof of this board's cause and is not a basis for applying another board's firmware or guessed register writes.

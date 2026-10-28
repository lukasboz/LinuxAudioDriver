# ASUS rear microphone setup and diagnostics

This project contains a recovered Windows-driver rear-microphone selection for the ASUS ROG STRIX X870E-E GAMING WIFI and tools to verify its capture paths on Kubuntu 26.04. Start with [the setup and hardware test instructions](REVERSE_ENGINEERING.md). The guarded `realtek_rear_mic.py` candidate uses the existing Linux USB audio driver and Python 3.10+; its software tests pass, while working audio awaits the user's hardware test.

The user's initial report confirms Ubuntu 26.04.1, kernel `7.0.0-34-generic`, USB `0b05:1b9b`, and ALSA card 3 (`Audio_1`). The installed HiFi profile exposes Line Input as available and Microphone as unavailable. These results came from a Windows-to-Ubuntu restart. See [the recorded findings](observations/initial-findings.md).

Both original warm and cold capture matrices completed with no intelligible voice confirmed by the user. Static analysis of `RtUsbA64.sys` has since recovered the exact target-specific rear MicIn command: vendor request `0x6c`, index 1, data byte `0x13`. After applying it, the expected path is **PCM 1 / Line Input**, rather than the front `Mic`/PCM 2 route. Run the new hardware experiment in [REVERSE_ENGINEERING.md](REVERSE_ENGINEERING.md); keep the existing baseline recordings. [The Windows USB reference experiment](USB_CAPTURE.md) remains the next step if usable voice is absent. The earlier `alsactl monitor` argument bug is fixed; the completed baseline matrices remain valid.

Run `audio_diag.py` on the actual Kubuntu desktop as your usual user, so it uses your desktop audio session. It automatically finds `0b05:1b9b`; `--card 3` is optional and still verifies the USB ID. Only the explicit `realtek_rear_mic.py apply`/`line` USB transfer requires `sudo`.

## Run the collector

Copy this project to a writable directory on Ubuntu, or use the shared project folder. Change into that directory. Run:

```bash
python3 audio_diag.py collect --boot windows-warm
python3 audio_diag.py jacks --boot windows-warm
```

For the 20-second jack test, remove and reinsert only the rear microphone plug. Keep the headphone plug connected. Both commands save a separate directory under `diagnostics/` and print its absolute path. The collector saves package versions, USB descriptors/topology, DMI board and BIOS identifiers, ALSA PCMs/controls, UCM files/output, desktop audio sources, and available logs. Each command's exit status and errors are retained. It does not automatically upload anything.

The collector does not deliberately change controls or services. The `alsaucm` configuration query is bracketed by mixer snapshots: opening a UCM configuration can run initialization, so any observed control difference is retained. Permission errors from optional logs or USB descriptors are recorded; do not run the entire script as root to resolve them.

## Run the direct ALSA test

Close applications using sound, including browser voice calls and Spotify. Keep the G335 splitter connected to rear LINE OUT and MIC IN, and lower its microphone boom.

You can first inspect the proposed test without changing audio settings:

```bash
python3 audio_diag.py test --dry-run --boot windows-warm
```

Then run:

```bash
python3 audio_diag.py test --boot windows-warm
```

With the three PCMs and three expected capture switches, this creates **12 recordings**: the original mixer state on each PCM, then each recognized capture switch enabled individually on each PCM. Each recording is eight seconds. When prompted, press Enter, stay silent for the first two seconds, then repeat “rear headset microphone test” until recording ends.

The script selects a format advertised in each PCM's `/proc/asound/cardN/streamM` file. It uses explicit `hw:CARD,DEV` capture devices and records raw PCM before generating WAV files, avoiding desktop routing and sample conversion. It keeps errors, short/incomplete recordings, and overruns separate from successful silence. Unsupported formats are not evidence of microphone failure.

For isolated capture-route trials, the default is `--gain max`: it raises only the selected route's capture volume to its advertised maximum. Each trial begins by restoring the original mixer state. Playback volumes and jack-presence controls are not changed. To keep original capture volumes during isolated trials, use `--gain current`. Unknown source selectors or additional capture controls are logged for inspection, and prevent an automatic conclusion that USB initialization must be missing.

Before recording, the script saves the target card's mixer state and the active/inactive states of the discovered PipeWire/PulseAudio user units. It stops active audio services and their activation sockets, checks they stay stopped, and restores the mixer and previously active units in a `finally` block. It does not disable or mask units. A Ctrl+C, terminal EOF, SIGTERM, or ordinary recording error runs cleanup. SIGKILL, loss of power, or forcibly closing the execution environment may require manual recovery.

Each test directory contains:

- `plan.json`: the discovered card, controls, PCM formats, boot condition, and test count.
- `original-mixer.state` and `recovery.json`: the backup and recovery information.
- `commands.jsonl` and numbered logs: exact command arguments, statuses, and output.
- WAV/raw recordings and a mixer snapshot for each trial.
- `results.json` and `SUMMARY.md`: recording validity, channel measurements, listening review, next-step decision, and restoration errors.

If format selection fails, inspect the saved `stream*.txt` files. An explicit override is available, for example `--format S16_LE --rate 48000 --channels 2`, but use values supported by the hardware. The tool will retain an ALSA rejection as an error rather than call it silence.

## Listen and decide the next step

Once audio services have been restored, use the **test directory printed by the script**:

```bash
python3 audio_diag.py review diagnostics/REPLACE-WITH-THE-TEST-DIRECTORY
```

Review first plays a brief check tone and asks whether it was audible, then plays successful recordings through the normal desktop output. Enter `y` only when intelligible microphone speech is audible, `n` when it is not, and `u` if uncertain. `l` and `r` replay each channel separately, helping detect signals hidden by a stereo downmix. `p` replays the full recording; `q` saves the current reviews and finishes. Use `--no-play` if you listen to the files in another WAV player, or `--again` to revise earlier reviews.

The user's initial default output was HDMI. If the check tone is inaudible, select the headset as the desktop playback output and rerun review. Alternatively, run `pactl list short sinks`, copy the USB rear speaker sink's **node name** from its second column, and pass `--target 'COPIED-NODE-NAME'` to review. This targets that `pw-play` stream without changing the global default. The displayed description “Logitech Headset Speakers” and an old `wpctl` numeric ID are not necessarily the node name. See [PipeWire's target documentation](https://docs.pipewire.org/page_man_pw-cat_1.html).

Channel RMS/peak, clipped samples, digital silence, and initial-silence versus speech-window levels are measurements, not automatic speech detection. A click, background noise, or a moving level meter does not establish that the microphone works.

The saved summary selects the next step as follows:

| Reviewed result | Next step |
|---|---|
| Voice exists in a hardware recording after a cold Ubuntu boot | Investigate UCM mapping or desktop routing using that PCM and mixer snapshot |
| Voice exists, but only a warm/unknown boot was tested | Confirm raw capture after a cold boot before choosing a persistent fix |
| All expected captures succeeded and contain no reviewed voice after a cold boot, with no unresolved controls | Investigate Windows/Linux USB initialization |
| Capture errors, unfinished reviews, uncertain speech, or unresolved source controls | Resolve those gaps before choosing a patch |

For a cold comparison, shut down, remove standby power until the motherboard lights extinguish, restore power, and boot **directly into Ubuntu**. Repeat `collect`, `test`, and `review`, using `--boot cold` for collection/testing. Do not use that label for an ordinary restart from Windows. Keep wiring, packages, and BIOS unchanged during the comparison.

Share the resulting `SUMMARY.md`, `results.json`, and collector mixer/stream/UCM/USB logs in the coding session. WAV files can stay local unless listening evidence is needed. The initial pasted output alone does not establish whether raw capture works.

## Recover an interrupted test

If the script reports restoration errors, use its printed recovery command:

```bash
python3 audio_diag.py restore diagnostics/REPLACE-WITH-THE-TEST-DIRECTORY
```

Recovery verifies the user and target card, restores only the saved card's state, and restarts only the previously active audio units. `alsactl --no-init-fallback` prevents a failed restore from falling back to global/default initialization. Restarting services is attempted even if mixer restoration fails. A changed or missing target card causes a reported error instead of writes to a different card.

## Local verification

```bash
python3 -m unittest discover -s tests -v
python3 audio_diag.py --help
```

The tests use simulated ALSA/service state and generated PCM recordings. They verify format/control parsing, individual channels, incomplete/error handling, interruption cleanup, and decision criteria. They cannot validate the microphone on this Windows-hosted workspace; the direct ALSA run on Ubuntu provides that evidence.

Tool options follow the primary ALSA sources: [alsactl](https://github.com/alsa-project/alsa-utils/blob/master/alsactl/alsactl.c), [arecord/aplay](https://github.com/alsa-project/alsa-utils/blob/master/aplay/aplay.c), and [amixer](https://github.com/alsa-project/alsa-utils/blob/master/amixer/amixer.c).

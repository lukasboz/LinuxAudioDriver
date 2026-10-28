# ASUS ROG STRIX X870E-E rear microphone: investigation and fix handoff

## Purpose and current status

The user wants a software fix that allows their Logitech G335 headset microphone to work normally on Ubuntu using the motherboard's rear audio connectors. Headphone playback already works. The same headset and wiring work on Windows.

Diagnostic collection, jack monitoring, controlled direct ALSA tests, and WAV review are implemented in `audio_diag.py`; see `README.md` for commands. The user completed warm and cold baseline capture matrices: all 12 captures in each run succeeded and restoration reported no errors, but the user confirmed no intelligible voice. The complete `observations/diagnostics.zip` archive was extracted to `observations/imported_diagnostics`; all 24 WAV analyses and isolated mixer states were verified. Both runs have identical initial controls, formats, and mute-to-PCM behavior, with extremely small signals during speech. This established the need to investigate microphone setup below UCM. Both original jack monitors failed because the tool supplied a bare card ID rather than a control device name; that diagnostic bug is fixed. The newer reverse-engineering result and candidate are described below.

**Update, 2026-10-13:** The user approved REA installation and reverse engineering of the supplied Windows ZIP, authorized required dependencies, and chose to run Kubuntu hardware tests personally. REA 6.4.0 is installed and its Codex MCP connection verified. Native Ghidra analysis recovered the compiled target profile and its rear MicIn vendor request (`40/6c`, value 0, index 1, one byte `13`). `realtek_rear_mic.py` implements a guarded runtime experiment; expected capture is PCM 1 / Line. All 54 software tests pass on Linux; actual audio remains unverified. The boost update was traced to Windows FX registry properties without an additional recovered USB command. See [REVERSE_ENGINEERING.md](REVERSE_ENGINEERING.md) for evidence, installation details, hardware commands, and Line-mode recovery. The earlier paragraph describes the baseline stage; a candidate now exists, while persistent kernel/UCM integration awaits repeatable working capture.

The workspace is `C:\Users\lukas\Github Projects\LinuxAudioDriver`. The investigation runs in Windows PowerShell. No `AGENTS.md` was found within it. User-supplied Ubuntu hardware logs and recordings have been inspected, but this session cannot run its live audio hardware tests. Run hardware experiments on the actual Kubuntu installation; a Windows shell or ordinary WSL environment is not a substitute for testing its running audio stack.

## Confirmed user facts

- Motherboard: ASUS ROG X870E-E Gaming WiFi, understood to be the ROG STRIX X870E-E GAMING WIFI model. Verify the exact DMI model and revision during collection.
- Headset: Logitech G335.
- Connection: the headset's Y-splitter connects to both rear motherboard jacks, LINE OUT and MIC IN.
- Windows: headphones and microphone work with this wiring.
- Ubuntu: headphones work; the input is listed as **“USB Audio Line Input (plugged in)”**, but captures no audio.
- Target OS: Ubuntu 26.04, as reported by the user.
- Kernel: the supplied `uname -r` confirms **`7.0.0-34-generic`**, rather than the initially suggested 7.1.
- Primary issue supplied by the user: <https://github.com/alsa-project/alsa-ucm-conf/issues/541>.
- Desired outcome: reliable operation through the existing rear jacks, without needing to boot Windows first.
- Initial Ubuntu output confirms USB `0b05:1b9b`, ALSA card 3 (`Audio_1`), three capture PCMs (0, 1, 2), and an active HiFi UCM profile. Line Input is available while Microphone is unavailable. The default source is the webcam. Package versions and interpretations are recorded in `observations/initial-findings.md`.
- Boot provenance of that initial output: a Windows-to-Ubuntu restart after confirming microphone operation in Windows. A subsequent direct ALSA run labelled `cold` is supplied in `observations/test_2`. Both complete collector/test runs were received and the user confirms no intelligible voice in either. Original jack-event attempts failed in the diagnostic tool and must be repeated using the corrected script.

## Research findings and uncertainty

Sources were checked during planning on 2026-10-03. Recheck relevant upstream changes before implementing a patch.

1. ASUS specifies ALC4080 for this motherboard. The codec is connected over USB; investigate `snd-usb-audio`. Do not assume that generic `snd-hda-intel` model overrides or HDA jack-retasking tools apply to this device.
2. Upstream reports identify this board's audio device as USB `0b05:1b9b`. This remains an expected ID until confirmed on the user's machine.
3. The same-board report, [#718](https://github.com/alsa-project/alsa-ucm-conf/issues/718), describes a rear microphone detected as Line In and silent recordings. Its author added the USB ID to UCM matching and the ALC4080 HiFi configuration; additional microphone options appeared, but usable recording did not. The report calls the codec ALC4082; ASUS's specification says ALC4080. Preserve the discrepancy rather than treating the report's codec label as authoritative.
4. Current upstream UCM already matches `0b05:1b9b`. The addition is listed in the 1.2.14 release changes. Adding the USB ID is not, by itself, a demonstrated microphone fix.
5. In the ALC4080 HiFi configuration inspected during planning, the default microphone uses PCM device 2 and the `Mic` mixer/jack controls; the line input uses PCM device 1 and `Line` controls. An `Analog In` microphone mapping exists in a branch for another ASUS ID, `0b05:1996`. These are investigation clues, not verified mappings for this machine.
6. Related report [#780](https://github.com/alsa-project/alsa-ucm-conf/issues/780) concerns ASUS X870-F with the same USB ID. It reports working front capture and silent rear capture. A VID:PID match may cover more than one board; any fix must consider shared IDs and differing firmware or wiring.
7. The maintainer's advice in #541 is to establish direct ALSA behavior first. UCM cannot provide hardware functionality absent from the driver. If necessary, capture Windows USB communication with a timeline of actions.
8. Windows working makes a Linux software fix plausible. It does not establish the missing operation or guarantee that a short configuration change will suffice. Routing, bias, gain, and jack mode are hypotheses, not diagnoses.

The GitHub issue bodies and accessible upstream source were inspected. Some dynamic GitHub discussion content was not available through the browsing interface; the linked kernel Bugzilla page returned a bot challenge. Do not interpret this research as an exhaustive review of every comment, attachment, or proposed fix.

## Exact six-stage plan from the planning response

The following six stages preserve the plan presented to the user.

1. **Collect a baseline before changing anything.**

   Identify the actual kernel, audio packages, USB device ID, motherboard/BIOS version, capture devices, mixer controls, and loaded audio profile. The expected USB ID is `0b05:1b9b`, but verify yours.

   Capture `amixer` state with the rear microphone plugged and unplugged, alongside `/proc/asound/cardN/usbmixer`, the USB descriptors, and `alsaucm` output. Use the discovered card number; it can change between boots.

   Also compare two startup conditions: a direct Ubuntu boot after completely removing power, and a Windows session with a working microphone followed by a restart into Ubuntu. A difference would suggest hardware configuration surviving the restart—one of the problems described in [#541](https://github.com/alsa-project/alsa-ucm-conf/issues/541).

   **Deliverable:** a diagnostic bundle and a reproducible description of the failure.

2. **Determine whether the microphone works below PipeWire.**

   Temporarily stop the user audio services and their activation sockets, then record directly through ALSA from **every capture device on this sound card**. Restore the services afterward.

   Test the exposed `Line`, `Mic`, and `Analog In` capture controls individually, using supported recording formats and documented mixer ranges. Inspect each recorded channel separately. Unsupported formats, busy devices, and muted controls must be resolved before treating a silent recording as evidence.

   If available, test the front microphone connector as a comparison. A related ASUS board with the same USB ID has a report of working front capture and silent rear capture. [Related report #780](https://github.com/alsa-project/alsa-ucm-conf/issues/780).

   | Result | What we should fix |
   |---|---|
   | Direct ALSA recording works, desktop recording fails | ALSA UCM profile or PipeWire/WirePlumber routing |
   | Recording works after changing an exposed mixer control | Persist that setting through the appropriate audio configuration |
   | Every correctly configured rear capture path remains silent | Investigate missing driver/device initialization |
   | Capture works only after booting Windows first | Compare initialization and retained device state |

   This follows the upstream project's [direct ALSA debugging workflow](https://github.com/alsa-project/alsa-ucm-conf/blob/master/ucm2/DEBUG.md).

3. **If raw capture works, implement a narrowly scoped UCM fix.**

   UCM describes which hardware capture device, mixer control, and jack detector belong together. Map the rear microphone to the combination demonstrated to work, with appropriate enable/disable sequences.

   The board's USB ID is already recognized upstream, and its support appears in the ALSA 1.2.14 changes. **Adding `1b9b` alone is not a sufficient proposed fix:** the exact-board reporter tried that and still had silent recordings. [ALSA release changes](https://www.alsa-project.org/wiki/Detailed_changes_v1.2.13_v1.2.14), [#718](https://github.com/alsa-project/alsa-ucm-conf/issues/718).

   Compare Ubuntu's installed configuration with upstream, backport only the necessary changes, and check compatibility with the installed ALSA library. Provide an installer and rollback procedure. Renaming “Line Input” to “Microphone” only counts as a fix if voice recording actually works.

4. **If raw capture fails, capture what Windows does differently.**

   Use **Wireshark with USBPcap** on Windows to capture this motherboard audio device. Record a timeline covering device initialization, microphone unplug/replug, any Realtek jack-mode selection, and recording start/stop. Capture initialization by starting before restarting the audio device; boot-time capture may be necessary if that misses the relevant setup.

   Capture equivalent actions under Ubuntu with `usbmon`. These are supported USB capture mechanisms. [Wireshark USB capture documentation](https://wiki.wireshark.org/CaptureSetup/USB).

   The coding work would extract and compare control transfers and any relevant HID/vendor messages. Look for commands affecting input selection, microphone bias, gain, and jack mode. Those are hypotheses to investigate, **not established causes**.

   **Deliverable:** a small, explained set of candidate setup commands, with evidence tying them to microphone operation.

5. **Prove the missing operation, then make it persistent.**

   Build a minimal Linux experiment that sends only the understood, relevant commands to the verified device. Account for driver ownership and whether restarting/rebinding the driver resets the configuration. Avoid blindly replaying an entire Windows capture or guessing register writes.

   Require repeatable voice capture after a cold boot before packaging anything.

   If the experiment succeeds, integrate it into the appropriate `snd-usb-audio` quirk or mixer-control path, including resume/reset handling. Likely investigation points are `sound/usb/quirks.c` and `sound/usb/mixer_quirks.c`; the trace determines the actual implementation. Scope device matching carefully because another ASUS model reports the same USB ID.

   Build against the **actual Ubuntu kernel version**, retain a working fallback kernel, and handle module signing if Secure Boot requires it. Include any companion UCM change and rollback instructions.

6. **Validate normal desktop use.**

   Completion means intelligible microphone recordings through both ALSA and desktop applications, working headphones during capture, and reliable behavior across cold boot, restart, suspend/resume, and unplug/replug. Windows must not be needed to initialize it.

   Prepare the resulting diagnostics and patch for the appropriate upstream project: UCM for profile changes, ALSA/kernel for missing hardware functionality.

## Immediate next action for the user

Boot Ubuntu with the same splitter connections and run these read-only diagnostics. They identify the system; they do not implement a fix. If a command or package is missing, preserve that error and let the coding session decide what needs installing.

```bash
cat /etc/os-release
uname -r
lsusb
cat /proc/asound/cards
aplay -l
arecord -l
wpctl status
pactl list cards
dpkg-query -W alsa-ucm-conf libasound2t64 alsa-utils pipewire wireplumber
```

Suggested coding-session instruction:

> Read HANDOFF.md. Implement the diagnostic collection and direct ALSA test stages of this plan. Use the results to choose between a UCM fix and investigation of missing USB initialization. The confirmed setup is a G335 Y-splitter in the rear LINE OUT and MIC IN jacks; Ubuntu shows “USB Audio Line Input (plugged in)” with no audio, while Windows works. Start by verifying the actual Ubuntu kernel and USB device ID.

## Additional implementation details

### Stage 1: diagnostic collection

Make the first tool collect information without deliberately changing mixer settings, profiles, services, packages, or drivers. Save output locally, with a timestamp and explicit success/failure for each command. Do not upload it automatically.

Record:

- OS release; full running kernel release; installed ALSA library, UCM, PipeWire, and WirePlumber versions.
- DMI board vendor/name/version and BIOS version/date. Board serial numbers are unnecessary.
- `lsusb`, `lsusb -t`, and the target device's detailed USB descriptors, including `bcdDevice`, interface classes, endpoints, and product strings.
- `/proc/asound/cards`, `/proc/asound/pcm`, the target card's `id`, `usbid`, `usbmixer`, and available `stream*` files.
- `aplay -l`, `arecord -l`, and optionally the corresponding `-L` lists.
- `amixer -c N contents` and `amixer -c N scontents`.
- `alsaucm -c hw:N dump text`, including any parsing or missing-profile errors.
- `wpctl status`, `pactl list cards`, `pactl list sources`, and relevant user-service/kernel logs.
- Copies of relevant installed UCM files and existing local audio overrides, so a later change can be compared with the baseline.
- `alsa-info.sh --no-upload` if available; keep its output local and review it before sharing.
- The Windows audio driver provider/version and BIOS version when collecting the Windows reference.

Here `N` is a placeholder for the verified motherboard USB audio card. Do not copy card 3 from the upstream report. GPU HDMI audio and other USB audio devices may enumerate first. Cross-check the ALSA card with USB topology/sysfs and the driver, not just the generic name “USB Audio.”

Use an event monitor such as `alsactl monitor` or the available `amixer` event facility while the user removes and reinserts only the microphone plug. Save before/after control snapshots. A read-only jack-presence control is an observation, not a setting to force on.

Keep package versions and BIOS unchanged during the initial comparison. If updating packages becomes a justified experiment, save a before/after baseline and change one relevant layer at a time. Do not overwrite the complete system UCM tree with unpinned upstream files as the first step.

### Stage 2: controlled capture tests

Before testing, record the initial audio-service state and save the target card's mixer state to a dedicated backup file. Restore the original state afterward, including on interruption. Do not delete the global ALSA state file as a troubleshooting shortcut.

Discover the actual user units and audio server before stopping anything. On a normal PipeWire setup, relevant units can include `wireplumber.service`, `pipewire.service`, `pipewire.socket`, `pipewire-pulse.service`, and `pipewire-pulse.socket`. Closing audio applications and stopping sockets prevents accidental reactivation during the direct tests. A different stack needs its own equivalent procedure; do not assume these units exist.

Record from explicit hardware PCMs such as `hw:N,M`, where `M` comes from `arecord -l`. Do not use `default`, `pulse`, or `pipewire` for the isolation test. Inspect `/proc/asound/cardN/stream*` and hardware constraints to select a supported sample format, channel count, and rate. A rejected recording format is not a silent-capture result.

For each relevant capture PCM:

1. Start from a known mixer state and record which capture switch, source selector, and gain are active.
2. Use only controls that exist on this machine. Increase gain within its advertised range as necessary; do not assume a `Mic Boost` control exists.
3. Record several seconds of silence followed by speech with the G335 boom lowered. Keep the wiring fixed during each sample.
4. Listen to the recording and measure signal level for each channel separately. Distinguish digital silence, background noise, startup clicks, weak speech, and intelligible voice. Check channels before downmixing; a combined mono result can obscure channel-specific behavior.
5. Save the command, exit status, selected hardware format, mixer snapshot, boot condition, and WAV filename together.

Avoid a blind sweep of all mixer controls. Use the descriptors and control topology to construct a small test matrix, including plausible source-selection controls if present. Do not change playback volume or unrelated devices while exploring capture.

An optional front-panel test is diagnostic, not a replacement for the rear-jack goal. Only perform it if the front connectors are wired and available; preserve the appropriate splitter arrangement for that connector.

For the cold/warm comparison, record exactly how each boot was performed. A cold baseline should follow an OS shutdown and removal of standby power, with motherboard lights allowed to extinguish, then a direct Ubuntu boot. The warm comparison should be a Windows restart into Ubuntu after confirming voice capture. Do not treat Windows hybrid shutdown as proof of a cold start. A negative warm-boot result does not rule out missing initialization: firmware or the Linux driver may reset the device during boot.

### Stage 3: UCM implementation boundaries

Relevant upstream files:

- `ucm2/USB-Audio/USB-Audio.conf`: USB ID/profile selection.
- `ucm2/USB-Audio/Realtek/ALC4080.conf`: profile entry point.
- `ucm2/USB-Audio/Realtek/ALC4080-HiFi.conf`: device mappings and control sequences.

Inspect the installed versions before editing. The upstream `USB-Audio.conf` inspected during planning uses UCM syntax 8; do not assume an older installed ALSA library can parse arbitrary current upstream configuration.

A useful patch must connect the demonstrated capture PCM, the effective mixer element, and the observed jack detector. Do not simply copy another board's `Analog In` branch because the names look similar. If jack detection is demonstrably wrong while capture works, address availability/mapping on the affected hardware without globally disabling jack detection.

Prefer the smallest change compatible with the installed package. Keep an exact backup and diff. Document package-update behavior and removal. Use the upstream UCM validator with suitable hardware information when preparing a UCM patch, and validate it on the actual system; a syntax check alone cannot establish working capture.

### Stage 4: capture and comparison procedure

The G335 itself is an analog device. Capture the motherboard's internal USB audio device, not a nonexistent Logitech USB headset.

Start with short, repeatable recordings with explicit timestamps for:

| Event | Evidence to retain |
|---|---|
| Audio device initialization | Enumeration, descriptors, interface setup, and initialization messages |
| Microphone insertion/removal | Jack events and subsequent control/HID/vendor traffic |
| Selecting microphone versus line mode, if Windows exposes it | Messages associated with each selection |
| Changing input gain/boost, if exposed | Before/after values and corresponding messages |
| Starting/stopping a voice recording | Streaming setup and any capture-specific initialization |

Identify the correct USB root hub and device address. Addresses may change after device restart; retain enumeration information so the trace can be followed. USBPcap operates at the root-hub level, so keep unrelated device traffic out of shared exports where possible. Preserve the audio device's relevant descriptors and all its relevant interfaces when filtering.

Restart only the identified audio device when capturing its initialization; do not disable a whole USB controller. An analog jack unplug does not re-enumerate the internal USB codec. If device restart does not reproduce initial setup, investigate boot capture rather than assuming initialization sends no special commands.

Compare transactions semantically: request type, request, value, index, payload, direction, result, ordering, and timing. Match submissions with completions. Device addresses, URB identifiers, and operating-system scheduling will differ, so a text diff of complete captures is insufficient.

Standard USB Audio Class controls matter too. Do not assume every relevant operation is a vendor command. Separate streaming data from setup/control traffic, and inspect any companion HID/vendor interfaces only where descriptors and traces support doing so.

### Stage 5: proof of concept and durable fix

The experiment should explicitly match the verified device identity and interface, log every operation, check return values/timeouts, and support a dry-run description of the intended sequence. Minimize the candidate command sequence using repeated before/after tests from the same starting state. Do not guess firmware writes, EEPROM operations, or undocumented register values.

Choose the mechanism after understanding the interface. Possible investigation tools include libusb/usbfs for appropriate USB transfers or an interface-specific HID tool if the device actually exposes the needed HID mechanism. Driver ownership matters: detaching/rebinding or resetting the device may undo the state being tested. Do not interpret that as proof that a command had no effect.

Existing Realtek support in `mixer_quirks.c` includes other hardware families. Similar vendor names or apparent HDA-style operations are not evidence that their request codes or node/register addresses are valid on this board. Derive commands from this hardware's observations and available documentation.

For a kernel fix:

- Use the matching Ubuntu kernel source/build configuration and required symbol versions, not a module built against an unrelated upstream tree.
- Decide whether a probe/reset/resume quirk or an exposed mixer control is the correct abstraction. UCM can use a newly exposed control if runtime selection is required.
- Match only the hardware/firmware scope justified by evidence. Consider USB revision and DMI distinctions if the shared VID:PID is insufficient.
- Handle failure and lifecycle ordering without breaking working playback or other devices.
- Test the actual Secure Boot/module-signing path if applicable; do not silently disable Secure Boot.
- Keep the distribution kernel/module recoverable. Document installation, removal, and what happens on a kernel update.
- Do not choose a permanent DKMS or boot-service workaround before demonstrating that it is reliable and necessary. A temporary userspace experiment and the durable upstream fix have different requirements.

### Validation record and definition of done

Record results for the original baseline and the candidate fix using the same cable, microphone position, format, and test phrases where practical.

| Scenario | Required outcome |
|---|---|
| Direct Ubuntu boot after power removal | Usable rear microphone without previous Windows initialization |
| Ubuntu restart | Microphone remains usable |
| Windows-to-Ubuntu restart | No incorrect inherited jack mode |
| Suspend/resume, if supported by the desktop | Microphone and headphone playback recover |
| Rear microphone unplug/replug | Capture returns without a special plug sequence |
| ALSA hardware recording | Intelligible voice with reasonable level and no severe clipping/noise |
| PipeWire/default application recording | Correct source is available and works |
| Simultaneous playback and capture | Existing headphone playback continues normally |
| Removal of the patch | Documented rollback succeeds |

Use more than one cold-boot repetition to avoid accepting retained Windows state as a fix. Record observed signal quality rather than declaring success solely because an input meter moves or a new source name appears.

If only the UCM path is needed, stages 4 and 5's reverse-engineering work are unnecessary. If the results point below UCM, stop making cosmetic profile edits and collect the Windows reference before proposing kernel commands. A failure to identify a reproducible working command sequence is an unresolved investigation, not a completed fix.

## Suggested project artifacts

The diagnostic collector/test/review tool, its instructions, fixture tests, and initial findings now exist. Create the remaining artifacts as the work reaches the relevant stage:

- A diagnostic collector and instructions for running it on Ubuntu.
- A local diagnostics directory with version/topology snapshots and a capture-test results table.
- A controlled ALSA test procedure with state restoration.
- If needed, Windows/Linux capture instructions, an event timeline, and a trace-analysis tool.
- A minimal proof of concept only after candidate commands are understood.
- The final UCM/kernel patch, installation and rollback instructions, and validation results.
- An upstream-ready report with the smallest relevant evidence and reproduction steps. Preparing a report does not authorize posting it or uploading recordings automatically.

## Sources

- ASUS motherboard manual: <https://dlcdnets.asus.com/pub/ASUS/mb/SocketAM5/ROG_STRIX_X870E-E_GAMING_WIFI/E25504_ROG_STRIX_X870E-E_GAMING_WIFI_EM_V2_WEB.pdf>
- General ALC4080 driver discussion supplied by the user: <https://github.com/alsa-project/alsa-ucm-conf/issues/541>
- Same-board rear-microphone report: <https://github.com/alsa-project/alsa-ucm-conf/issues/718>
- Related ASUS board with the same USB ID: <https://github.com/alsa-project/alsa-ucm-conf/issues/780>
- ALSA direct debugging instructions: <https://github.com/alsa-project/alsa-ucm-conf/blob/master/ucm2/DEBUG.md>
- Upstream report cited by the maintainer as a useful diagnostic example: <https://github.com/alsa-project/alsa-ucm-conf/issues/528>
- UCM board-support contribution: <https://github.com/alsa-project/alsa-ucm-conf/pull/486>
- ALSA 1.2.14 changes: <https://www.alsa-project.org/wiki/Detailed_changes_v1.2.13_v1.2.14>
- USB profile selection: <https://github.com/alsa-project/alsa-ucm-conf/blob/master/ucm2/USB-Audio/USB-Audio.conf>
- ALC4080 HiFi configuration: <https://github.com/alsa-project/alsa-ucm-conf/blob/master/ucm2/USB-Audio/Realtek/ALC4080-HiFi.conf>
- ALSA UCM repository, installation and validation notes: <https://github.com/alsa-project/alsa-ucm-conf>
- Kernel USB audio quirks: <https://github.com/torvalds/linux/blob/master/sound/usb/quirks.c>
- Kernel USB mixer quirks: <https://github.com/torvalds/linux/blob/master/sound/usb/mixer_quirks.c>
- Kernel USB mixer maps: <https://github.com/torvalds/linux/blob/master/sound/usb/mixer_maps.c>
- Kernel driver configuration documentation: <https://docs.kernel.org/sound/alsa-configuration.html>
- USB capture on Windows and Linux: <https://wiki.wireshark.org/CaptureSetup/USB>
- USBPcap capture setup: <https://desowin.org/usbpcap/tour.html>
- Logitech G335 product information: <https://www.logitechg.com/en-us/shop/p/g335-gaming-headset.981-001017>

The linked upstream branches are mutable. Record exact commits/package versions when implementation begins so a later reviewer can reproduce the work.

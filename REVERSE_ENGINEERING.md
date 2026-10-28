# Recovered rear-microphone setup for Kubuntu 26.04

The supplied Windows driver contains an explicit rear-microphone selection for this motherboard. `realtek_rear_mic.py` sends that recovered command through Linux's existing USB interface. It is ready for a controlled hardware test: all 54 software tests pass on Linux, but intelligible microphone recording has not been verified on the actual Kubuntu machine.

The expected capture path after selection is **PCM device 1 / the `Line` mixer route / USB interface 2**. The existing desktop label is **Line Input**. PCM device 2 and the `Mic` controls describe the front microphone path in this Windows profile.

## Run on the actual Kubuntu machine

Copy this project to a writable directory on Kubuntu and change into it, or extract `dist/realtek-rear-mic-kubuntu.zip` and change into the extracted directory. The bundle contains the runtime tools, tests, reports, and static evidence; it excludes the proprietary Windows binaries and earlier audio recordings. The runtime tool uses Python 3.10+ and the existing `snd-usb-audio` driver; REA, Node, Ghidra, compilation, and a replacement kernel module are unnecessary on Kubuntu.

Keep the G335 splitter connected to the rear LINE OUT and MIC IN connectors and lower the microphone boom. For a reproducible result, shut down, remove standby power until the motherboard lights extinguish, restore power, and boot directly into Kubuntu. Close applications using sound.

First inspect the command and check the detected hardware, as your normal desktop user:

```bash
python3 realtek_rear_mic.py plan
python3 realtek_rear_mic.py status
```

`status` must report `"status": "identified"`. It verifies the board, USB identity/revision, audio interfaces, expected capture endpoints, driver binding, and associated ALSA card. The card and USB bus/address are discovered each time; do not assume card 3 or bus 3.

Apply the recovered rear-microphone selection:

```bash
mkdir -p diagnostics
sudo python3 realtek_rear_mic.py apply > diagnostics/realtek-rear-mic-apply.json
cat diagnostics/realtek-rear-mic-apply.json
```

Continue only when this reports `"status": "transferred"`, one transferred byte, and payload `13`. This confirms acceptance of the USB request, not working microphone audio. A failed command exits with status 1 and prints its reason; retain that JSON for inspection.

Now run the existing direct ALSA matrix as your **normal desktop user**, leaving the newly selected device powered and attached:

```bash
python3 audio_diag.py test --boot cold
```

Use `--boot cold` only if you performed the cold boot described above; otherwise use `--boot unknown`. For each eight-second recording, stay silent for two seconds, then speak clearly. The test exercises all three capture PCMs and their capture switches, including PCM 1 with the Line switch enabled and its exposed gain at maximum. It saves and restores ordinary ALSA controls and the prior desktop audio-service state.

Listen to the recordings using the actual test directory printed by the command:

```bash
python3 audio_diag.py review diagnostics/REPLACE-WITH-THE-PRINTED-TEST-DIRECTORY
```

Check the playback tone first; select the headset as the playback output if needed. Report voice only when intelligible speech is audible. The first expected successful trial is **PCM 1 with the Line capture route enabled**. A level meter, click, noise, or successful USB transfer is insufficient. See [README.md](README.md) for channel playback and recovery options.

Return `diagnostics/realtek-rear-mic-apply.json`, the new test's `SUMMARY.md` and `results.json`, and which PCM/route contains intelligible voice. Keep the earlier warm/cold baseline bundles. If it works, repeat this procedure after another full cold boot to establish reproducibility. You can then try the desktop's **USB Audio Line Input** source. UCM naming, persistence, and reset/resume integration should follow the demonstrated result.

To select Line input again:

```bash
sudo python3 realtek_rear_mic.py line > diagnostics/realtek-rear-mic-line.json
```

This sends the driver's LineIn selector `12`. It selects Line mode; it does not restore every previous internal hardware setting. A complete power removal can establish a fresh boot baseline. The experiment installs no boot service or kernel module. If the matrix reports ordinary ALSA/service restoration errors, use its printed `audio_diag.py restore` command.

## Target and supplied artifact

| Item | Verified identity |
|---|---|
| Board | ASUS ROG STRIX X870E-E GAMING WIFI, Rev 1.xx |
| Codec | ALC4080 USB audio |
| USB | `0b05:1b9b`, raw `bcdDevice=0x0013` |
| Recorded target system | Kubuntu/Ubuntu 26.04.1, kernel `7.0.0-34-generic` |
| Supplied ZIP | `DRV_Audio_RTK_USB_DD_TP_W11_64_V6396002393_20240823R.zip` |
| ZIP SHA-256 | `226bc139959cdff02a48f71d0ac5d69a3e9bf5ccdca5a7360ef9a319ca97ace2` |
| Native driver | `Win11/USBAud/Win64/RtUsbA64.sys`, AMD64, version `6.3.9600.2393` |
| Driver SHA-256 | `4fef11b7d0d2b04b9ca830a4b10f02a60c0c105703d80f4a746e9be5411a8921` |

The archive's Windows 11 USB payload was extracted and checked against its original members. The base and extension INF both match this USB ID. Package installers and Windows driver code were not executed. The DAT container has no explicit mapping/profile for `0b05:1b9b`; firmware images for other boards were excluded from the experiment. The matching profile is compiled into the native driver.

## Recovered protocol and evidence

| Setup field | Rear MicIn selection | LineIn selection |
|---|---|---|
| `bmRequestType` | `0x40`: OUT, vendor, device | `0x40` |
| `bRequest` | `0x6c` | `0x6c` |
| `wValue` | `0` | `0` |
| `wIndex` | `1` | `1` |
| `wLength` | `1` | `1` |
| Data byte | **`0x13`** | **`0x12`** |

The static proof chain in `RtUsbA64.sys` is:

1. `0x14004eb18` looks up the VID/PID table. The target record at file offset `0x672c0` / VA `0x1400692c0` selects family `0xb4`, profile `0x84`.
2. `0x14003e2d8` constructs that profile with rear capture interface 2 and front capture interface 3. Its rear pin record is `0x41a89020`.
3. `0x140053be0` decodes that record as widget `0x18` (MIC_IN), assigns the rear retask slot at context offset `0xe58`, and selects its default device type. `0x140055f24` maps its microphone nibble to `WidgetTypeMicIn=1`.
4. `0x14005470c` (`CWidget::AssignDeviceType`) sends byte `0x13` when that rear widget is assigned MicIn. It precedes this with byte `0x15` only when changing from the Center playback type. The minimal experiment assumes the baseline rear input state; it implements `13` alone.
5. `0x140052368` calls the vendor request builder `0x14003190c` with the exact tuple above. Its assembly independently confirms the request, direction, index, value, and one-byte length. The LineIn branch sends `12` from prior MicIn/LineIn state.
6. `0x1400395d8` labels interface 2 as **Rear Mic** for the resulting internal microphone type. The user's descriptors map interface 2 to endpoint `0x83`, Feature Unit 27, and Linux PCM 1.

This establishes what the driver's target-specific control flow submits. Static analysis does not observe the current device firmware executing it or prove that it is the complete sequence needed on this machine. Persisted Windows retask overrides can change startup behavior.

The 0–30 dB Windows microphone-boost node was also traced. Its handler `0x14004d7e8` calls `0x14003c4a8`, then `0x14003bf88`, to write an endpoint FX registry property. Both storage branches use Windows registry APIs. No extra USB boost command follows from this inspected update; the later APO/service consumer remains unresolved. Existing standard ALSA mute/volume controls remain appropriate for the recording test.

Full findings and reproducible inputs:

- [Native retasking and boost findings](observations/driver_reverse_engineering/native-retasking-findings.md), with raw function pseudocode, assembly, and caller/callee exports under `observations/driver_reverse_engineering/ghidra/`.
- [Package configuration findings](observations/driver_reverse_engineering/configuration-findings.md), [package manifest](observations/driver_reverse_engineering/package-manifest.json), and [DAT inventory](observations/driver_reverse_engineering/configuration-inventory.json).
- [Linux/UCM findings](observations/driver_reverse_engineering/linux-support-findings.md), including pinned source revisions and the recorded hardware topology.
- [REA archive Evidence bundle](observations/driver_reverse_engineering/rea-package-evidence.json). Archive inspection Evidence ID: `ev_540e329bf4b63f93ba883fc6777774fb9938c9115803a41df3885c827ab3bd73`.
- [Machine-readable verification](observations/driver_reverse_engineering/verification.json).

Ghidra identified 966 functions and 514 strings; 72 focused function exports cover the routing, USB builder, profile, endpoint, gain, and property paths described here. Decompiled types are inferred and Windows import prototypes are incomplete without the original PDB. This reconstructs the setup behavior relevant to the rear microphone. Windows APO, ASIO, and endpoint services have not been reimplemented.

## REA installation and connection verification

REA **6.4.0** is installed and registered as the `rea` MCP server in `C:\Users\lukas\.codex\config.toml`. Restart Codex to load that registration into its tool catalog.

| Component | Installation |
|---|---|
| Node | `24.21.0`, `C:\Users\lukas\.rea\tools\node-v24.21.0-win-x64` |
| REA | `C:\Users\lukas\.rea\cli\node_modules\rea-agents` |
| Ghidra | `12.1.4`, `C:\Users\lukas\.rea\tools\ghidra_12.1.4_PUBLIC` |
| Java | Existing Microsoft OpenJDK `21.0.4.7-hotspot` |
| REA skill | `C:\Users\lukas\.agents\skills\reverse-engineer-anything`, version 37 |

The approved `npx rea-agents@latest setup` workflow was run, then the registration was refreshed to use the stable local package and explicit Node executable. The scoped Codex/Ghidra/skill doctor reports healthy. A real stdio MCP client verified initialization, REA package/catalog identity, all **170 tools and 6 prompts**, and a successful `binary_session` request. Final records are [the scoped doctor](observations/driver_reverse_engineering/setup/rea-doctor.json) and [the MCP doctor](observations/driver_reverse_engineering/setup/rea-stable-mcp-doctor.json).

REA's native Ghidra adapter encountered a Windows drive-root handle-sharing error on this host (`ERR_REA_WINDOWS_NATIVE`, Win32 32). The recorded native query failure is distinct from the successful MCP connection and portable archive/resource inspections. The native driver analysis therefore used the installed official Ghidra headless CLI, with logs and exports saved locally. Those exports are ordinary Ghidra evidence, not REA Evidence envelopes. The corresponding [upstream issue](https://github.com/morluto/rea/issues/2257) and [change](https://github.com/morluto/rea/pull/2467) are documented; a native-provider fix has not been verified here.

## Software validation and practical limits

The final test suite contains 54 tests: **54 pass under Linux in WSL**; **48 pass on Windows with six Linux sysfs tests skipped**. The tests check the exact request and inverse selector, native ioctl layout, discovery through real Linux symlinks, wrong board/revision/topology rejection, device-address reuse, short transfers and USB stalls, cleanup, dry-run behavior, and the existing ALSA recording/review safeguards. The runtime selection tool uses only Python's standard library.

The USB ABI is checked against Linux's [`usbdevice_fs.h`](https://github.com/torvalds/linux/blob/24a19b953e2a3d0ea5a8c4951a0ab8f32720c907/include/uapi/linux/usbdevice_fs.h). On supported 64-bit x86/ARM Linux, `usbdevfs_ctrltransfer` is 24 bytes, its data pointer is at offset 16, and `USBDEVFS_CONTROL` is `0xc0185500`. Linux's [`check_ctrlrecip()`](https://github.com/torvalds/linux/blob/24a19b953e2a3d0ea5a8c4951a0ab8f32720c907/drivers/usb/core/devio.c#L960) permits vendor device control requests without claiming or detaching the audio interface. The tool verifies the opened USB character device and rereads its identity before the vendor OUT transfer.

To rerun the software checks:

```bash
python3 -m unittest discover -s tests -v
python3 realtek_rear_mic.py apply --dry-run
```

WSL has no access to this motherboard audio device; these are software checks, not Kubuntu hardware tests. The outstanding decisive check is usable voice after `13` on a cold boot. Bias, firmware-side gain, jack notifications, suspend/resume, and reset behavior are not yet demonstrated. If the request is accepted but recording remains unusable, retain the results and continue with [USB_CAPTURE.md](USB_CAPTURE.md) to compare a working Windows session with Linux. A persistent quirk or boot integration requires that hardware evidence.

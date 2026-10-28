# Windows package configuration findings

Scope: supplied archive `DRV_Audio_RTK_USB_DD_TP_W11_64_V6396002393_20240823R.zip`, extracted Windows 11 USB audio payload, target `USB\VID_0B05&PID_1B9B&MI_00`. No package programs, driver loads, device commands, or firmware writes were performed.

**Result:** the INF selects this target, but `RTUSBAIODAT.DAT` has no explicit target device record. The DAT is a mixed, structured resource container containing firmware-labelled images and signal-processing data for other devices. It is not an identified set of microphone setup commands for this motherboard. Microphone bias, route, retask and boost selectors remain unresolved by this configuration inspection.

## Reproducible evidence

Run `python tools/inspect_realtek_data.py` to regenerate `configuration-inventory.json`. That JSON records exact file/block hashes, absolute file offsets, all 42 device mappings, all 40 profiles, all 54 blocks, and nested ZIP members. DAT/INF findings below are ordinary Python and text inspection, **not REA Evidence records**. Native consumer semantics were not examined in this branch of the investigation.

| File | Bytes | SHA-256 |
|---|---:|---|
| `RTUSBAIODAT.DAT` | 2163502 | `ec8575588926f5932b3f0069f5b61d3c7a4c65fe3f800fa49a6b74383cc0ecc0` |
| `RtDUsbAD_asus.inf` | 13303 | `a11b789fdd901982f9b5c2fc5e3356e4441fb8a3c18abf225faa8f7fdd82a690` |
| `Realtek/CodecExtOem_RTK_82/ExtRtXUsb_Asus_RTK.inf` | 21102 | `dbf7f1418fdf9174a8c3dfe5a1897957c52a6b0c5d9e22cc6b2f7bacb85ab54c` |

These three extracted files were compared directly with their archive members and are byte-for-byte identical.

## Target installation settings: high confidence, static text

- Base INF line 67 maps `0b05:1b9b` to `RtkUsbAD`; service `RtkUsbAD_2393` loads `RtUsbA64.sys`. Driver version is `6.3.9600.2393`, dated 2024-06-27.
- The base installation copies `RTUSBAIODAT.DAT` alongside the driver and registers its install path. There is no board-specific registry configuration in the target match line: the target uses the same base install section as the other ASUS IDs.
- The base INF exposes capture interfaces `WaveIn1` through `WaveIn6`. Names such as `KSNAME_RearLineInWave1` are symbolic INF labels; they do not establish a correspondence to Linux PCM numbers or physical microphone pins. Its `WaveMicIn` section adds general endpoint registration and event-driven-mode properties.
- Extension INF line 18 maps the target to `DeviceExtension_Install_DSD`. That branch adds `IntcAzAudModelAddReg`, plus Realtek USB APO (`VEN_10EC&AID_0002`), universal service, HSA/audio-control application and ASIO components. Its registry section associates render/capture endpoints with Windows audio-processing classes. It does not contain microphone bias or vendor register values.
- The separate `DeviceExtension_Install` branch adds Intel speech preprocessing DLL settings, but the target selects `DeviceExtension_Install_DSD`. Copying every nearby extension setting would therefore misrepresent the target's selected branch.
- The base INF includes optional OEM-format sections, including a 96 kHz/24-bit branch. The target's match selects plain `RtkUsbAD`; the presence of an optional format section does not make it a target-specific default.

## DAT structure: high confidence layout, inferred field meanings

All offsets are absolute zero-based offsets within `RTUSBAIODAT.DAT`, all numeric fields below are little endian.

| Range | Observed structure |
|---|---|
| `0x0`, 16 bytes | `MDTR`, u32 file size `0x21032e`, u32 `42`, u32 `40` |
| `0x10` through `0x4a8` | 42 entries of seven u32 fields each, 28 bytes per entry |
| `0x4a8` through `0x908` | 40 descriptors: u32 offset, u32 block count, u32 profile byte size, 16-byte ASCII label |
| `0x908` through `0x21032e` | Profile data, contiguous through EOF |

Each profile contains its declared number of blocks. Each block has a 36-byte header: 28 bytes of UTF-16LE name, an unidentified u32 at +28, u32 payload length at +32, then payload bytes at +36. The parser verifies every span, profile/block contiguity, exact EOF consumption, and CRCs of all four embedded ZIP archives.

The first two u32 mapping words consistently look like USB VID/PID start and end values with VID in the high 16 bits. They are equal in all 42 entries. Word 5 consistently indexes the adjacent profile table; e.g. mapping at `0x278` contains `0x0b051915`, index `20`, which points to profile `Asus 1915`. These meanings are strong layout inferences corroborated by device labels. Words 2, 3, 4 and 6 and the block header's +28 word remain unidentified. Their raw values are preserved in the JSON; no timing, flags or checksum semantics are assigned.

There is **no `0x0b051b9b` mapping** and no candidate range covers it. The full container also has no ASCII or UTF-16LE `1B9B`, nor either packed byte order `9b 1b 05 0b` or `05 0b 9b 1b`. A two-byte search for `9b 1b` has 16 incidental hits inside other payloads; those are not target identity records.

The 54 blocks comprise:

- 22 `FWSPI64` blocks, each with a 65536-byte payload. Older ASUS IDs `1915`, `1916`, `1917`, `1918`, `19AC`, `1996`, `1998`, `1999` select profiles containing one such block. For example, `Asus 1996` descriptor is at `0x87c`, block header at `0x1c027a`, payload at `0x1c029e`, SHA-256 `252a4bece41137d6bb6cab18d4ea3c4646f2537db42ec1d5a1f502568b18953d`.
- 16 `Gen3pKeyU`, three `RTUSBEQ`, three `RTUSBMicEQ`, two `SAMSfPu`, and four DSP/microphone-model-labelled blocks. EQ/processing meanings are indicated by their labels, signatures such as `MIEQ`/`EQEX`, and numerical data; the exact consumer behavior remains unproven.
- Four ZIP payloads labelled `SR483B`, `SR484D`, `SR0269`, `SR0567`. The first ZIP begins at `0x43e4` and contains `SSIDMAP.bin`, `CHIDMAP.bin`, and six `EFX/.../Preset.bin` files for handset/headset AnyContent/Movie/Music. ZIP inventory and CRCs prove their packaged structure; they do not establish effect activation on this target.

The `FWSPI64` labels, fixed image length, embedded USB strings/descriptors and executable-looking bytes strongly support firmware-image classification. Actual loading, update conditions and whether writes go to persistent storage require tracing the driver's consumer. **No payload is selected for `1b9b` by the inferred DAT mapping. Other board payloads are not target microphone settings and have not been proposed for use.**

## Ancillary REA resource inspection

REA 6.4.0's portable `inspect-pe-resources` was used directly; no native/provider session was opened. Saved outputs preserve complete inline Evidence.

| Artifact | SHA-256 | REA Evidence |
|---|---|---|
| `RtkAudUServiceConf64.dll` | `072380dc0ba317d91c8fd5b7eb6089db2df6b97941a098679e7a0bd9cda6d29c` | `ev_287af2e28b061c684d8e8be526509422130b889fd2a0bcc11fa706eb159b4ebc` in `service-conf-resources.json` |
| `RtkAudUServiceRes64.dll` | `349b70140864d2a669295091dbc056d538690348fe56a6d2a705ac67727457c8` | `ev_85d9a01761e1914d84f0e859a34e406d4638114087ca69a142571c8871c1cd04` in `service-res-resources.json` |
| `RtkCfg64.dll` | `910b905c918c141322cc872f2eb35429319b3ff52dcdf4d51706c7c9a67537ea` | `ev_6c1b29e099ce7c6e9a1d9eeb55379d78ab1abc01fd45011e3486111044608ff3` in `cfg-resources.json` |

Service-conf contains an opaque `DAT/102/1033` resource at `0x46c8`, 7952 bytes. Service-res contains several opaque numerical DAT tables, one WAV, and TXT resource `106` at `0x25dea0`, 194 bytes. The TXT maps laptop/device IDs such as `17AA2301`, `103C8A7F` and `1025171F` to resource numbers. RtkCfg's REGISTRY resources describe COM registration. Ordinary payload inspection found no explicit packed `0b051b9b` value in these three DLLs. None of this proves that generic service code cannot affect the target.

Ordinary string scans, recorded with hashes and offsets in `configuration-inventory.json`, yield candidate native follow-up anchors:

- `RtkApi64U.dll` SHA-256 `9dd40948f825bd7018843d8e73d44e906a24cebaff2027527b74ee804ec34ecc`: UTF-16LE `VolCtrl_AsBoost` at `0x72188`.
- `RtkAudUService64.exe` SHA-256 `65e2e4fce442553a4de56f098b3225354290b6e59babd8b2c05fbd42d577cdbb`: `CAudioDeviceLineVolumes::IsMicBoostControl` at `0x11ea40`, `IntMicBoost` at `0x15c5e0`, `ExtMicBoost` at `0x15c5f8`, and retask-related diagnostics/classes at `0x1274b0`, `0x13e8b0`, `0x182430`.

These strings establish names present in the artifacts. They do **not** establish USB selectors, board defaults, support on this device, bias enablement, or a required Linux operation. Some retask strings explicitly mention ACX/SDCA and could belong to unrelated supported device families.

## Answered questions and actionable gaps

| Question | Status / next evidence |
|---|---|
| Does Windows package identify the target? | Answered: base and extension INF matches |
| Does DAT provide its target board record? | Answered within the parsed layout: no matching mapping/profile |
| What is DAT? | Partially answered: mixed structured firmware/effects/processing resource container; consumer conditions unresolved |
| Target microphone/jack/boost/bias defaults? | Unresolved: not identified in selected INF branches or DAT |
| Can these resources yield a Linux fix? | Unresolved: requires target driver's code and USB runtime corroboration |

Next native questions: trace `RTUSBAIODAT` and `FWSPI64` consumers in `RtUsbA64.sys`; verify the mapping semantics and behavior when no target record matches; locate compiled `1b9b`/generic codec defaults; trace jack-retask and analog microphone boost/bias initialization to USB requests. Driver string anchors observed during ordinary package scanning are `RTUSBAIODAT` at file `0x5d000` and `FWSPI64` at `0x5afc0`. A working-Windows USB trace should distinguish class controls from vendor initialization and supply evidence of the target's actual operations.

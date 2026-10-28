# Linux support and integration evidence: ASUS USB 0b05:1b9b

Checked 2026-10-13. This report covers upstream Linux/UCM source, the user's existing diagnostics, and the three upstream issues. It does not claim the Windows driver was executed, identify a proven missing write, or supply a verified microphone fix. The main investigation owns the REA/Ghidra session; the findings below are source and recorded hardware evidence, not REA Evidence IDs.

## Result

The existing `snd-usb-audio` driver already enumerates this device's three capture streams and implements its advertised UAC2 mute, gain, and jack-status controls. The user's direct ALSA trials exercised all three streams, with each exposed gain at +12 dB, but produced no intelligible voice. Upstream UCM recognizes this USB ID already. A UCM-only change currently lacks a demonstrated working route to expose.

There is an existing Linux Realtek USB-to-HDA verb transport in `sound/usb/mixer_quirks.c`. Its request/byte layout is concrete and useful when comparing the Windows driver. Its existing users are Dell docks with different chips and USB IDs. Compatibility with this ASUS ALC4080 and its correct pin/node/coefficient values remain unproved.

No verified exact-board rear-microphone fix was found in the inspected upstream sources or issues. This is a bounded finding, not proof that none exists elsewhere.

## Checklist and evidence ledger

| Question | Status | Evidence and limits |
|---|---|---|
| Which stack/device is involved? | Answered | User descriptors and `usbmixer`: UAC2, `snd-usb-audio`, USB `0b05:1b9b`, raw `bcdDevice=0013`, control interface 0. GPU HDA is separate. |
| Does direct ALSA already expose working rear speech? | Answered for supplied trials | `observations/test_2/ANALYSIS.md`, the imported WAV/mixer matrix, and user listening confirmation: no intelligible voice in either warm or cold matrix. |
| Is this USB ID missing from current UCM? | Answered | UCM commit `d260eedd1900dbf3b477047e048d5382a5f50e24` explicitly matches it. |
| Does the current kernel include an exact-ID microphone quirk? | Answered for inspected files | No `1b9b` entry in the checked mixer maps/quirks, device quirks, or quirks table at Linux commit `24a19b953e2a3d0ea5a8c4951a0ab8f32720c907`. This is upstream, not the user's complete Ubuntu downstream source. |
| Is there precedent for Realtek vendor transport? | Answered | Existing Dell-dock HDA transport in `mixer_quirks.c`, plus a separately reported MSI surround-mode vendor request. Neither establishes an ASUS microphone command. |
| What must a Linux implementation preserve? | Partially answered | Generic UAC2 streams/controls, power management, reset/resume restoration, exact hardware match, and Windows-state interaction. Final initialization ordering depends on Windows static/trace evidence. |
| Which write fixes this rear microphone? | Unresolved | Requires Windows code/configuration evidence and corroboration on this hardware. No guessed HDA node, coefficient, bias, or gain write is justified by these sources. |

## Exact current source identities

Files are retained under `linux_source/` beside this report. Their original paths appear in the linked upstream permalinks.

- Linux: [`24a19b953e2a3d0ea5a8c4951a0ab8f32720c907`](https://github.com/torvalds/linux/tree/24a19b953e2a3d0ea5a8c4951a0ab8f32720c907). Parent supplied `mixer_quirks.c`, `mixer_maps.c`, `quirks.c`, and `hda_verbs.h`. This pass additionally saved `mixer.c`, `mixer.h`, `helper.c`, `card.c`, `quirks-table.h`, and `include/linux/usb/audio-v2.h` from that exact commit.
- ALSA UCM: [`d260eedd1900dbf3b477047e048d5382a5f50e24`](https://github.com/alsa-project/alsa-ucm-conf/tree/d260eedd1900dbf3b477047e048d5382a5f50e24). Saved `USB-Audio.conf`, `Realtek/ALC4080.conf`, `Realtek/ALC4080-HiFi.conf`, and `ucm2/DEBUG.md`.
- GitHub issue bodies plus all available comments for #718 (1), #780 (2), and #541 (62) were fetched via public GitHub REST endpoints, `comments?per_page=100`, and retained as `ucm-issue-*.json`. API metadata reports all three issues open. Latest update timestamps: #718 `2026-03-17T18:56:47Z`; #780 `2026-08-03T16:17:42Z`; #541 `2026-08-15T01:10:29Z`.
- The supplied target system snapshot reports kernel `7.0.0-34-generic`, UCM `1.2.15.3-1ubuntu1.5`, ALSA library `1.2.15.3-1ubuntu1.1`, ALSA utils `1.2.15.2-1ubuntu1`, PipeWire `1.6.2-1ubuntu1.2`, and WirePlumber `0.5.13-1ubuntu1`. These are recorded versions, not assumptions about every Kubuntu 26.04 installation.

## Advertised hardware topology and standard control protocol

Recorded sources: [USB descriptors](../imported_diagnostics/diagnostics/20261003T234259.934341Z-collect/005-usb-descriptors.txt) and [USB mixer topology](../imported_diagnostics/diagnostics/20261003T234259.934341Z-collect/files/proc/asound/card3/usbmixer).

| Linux capture route | Descriptor path | Stream | Control addresses on interface 0 |
|---|---|---|---|
| Analog In, PCM 0 | Input Terminal 9 (`0x0601` analog connector) → Feature Unit 25 → Output Terminal 17 | Interface 1, endpoint `0x81` | Connector unit 9: `wIndex=0x0900`; mute/gain unit 25: `wIndex=0x1900` |
| Line, PCM 1 | Input Terminal 11 (`0x0603` line connector) → Feature Unit 27 → Output Terminal 19 | Interface 2, endpoint `0x83` | Connector unit 11: `wIndex=0x0b00`; mute/gain unit 27: `wIndex=0x1b00` |
| Mic, PCM 2 | Input Terminal 12 (`0x0201` microphone) → Feature Unit 28 → Output Terminal 20 | Interface 3, endpoint `0x84` | Connector unit 12: `wIndex=0x0c00`; mute/gain unit 28: `wIndex=0x1c00` |

The ALSA route/control names follow those advertised terminal types. Seeing `Line - Input Jack` react to the physical rear MIC IN does not by itself show that Linux invented an incorrect name or prove which underlying analog node must be retasked. UAC entity IDs in this table are not established HDA node IDs; matching numerical values would not prove a mapping between the two protocols.

The UAC2 protocol implemented by [`get_ctl_value_v2()` and `snd_usb_mixer_set_ctl_value()`](https://github.com/torvalds/linux/blob/24a19b953e2a3d0ea5a8c4951a0ab8f32720c907/sound/usb/mixer.c#L338) uses:

- Class/interface request types: read `0xa1`, write `0x21`.
- `bRequest=0x01` for CUR; read `0x02` for RANGE. `wIndex=(entity_id << 8) | control_interface`; `wValue=(control_selector << 8) | channel`.
- Feature-unit mute selector 1 on master channel 0, one byte. ALSA capture-switch on corresponds to USB mute false; it is an inverted Boolean.
- Feature-unit volume selector 2 on channels 1 and 2, little-endian signed 16-bit payload, in 1/256 dB units. The recorded range is -4416 to 3072 (-17.25 to +12 dB). The advertised maximum is `0x0c00`, carried as bytes `00 0c`.
- Terminal connector selector 2 on channel 0, read-only. [`get_connector_value()`](https://github.com/torvalds/linux/blob/24a19b953e2a3d0ea5a8c4951a0ab8f32720c907/sound/usb/mixer.c#L1606) requests its status and reports `bNrChannels != 0`. [`build_connector_control()`](https://github.com/torvalds/linux/blob/24a19b953e2a3d0ea5a8c4951a0ab8f32720c907/sound/usb/mixer.c#L2046) creates a read-only control, not a programmable jack-mode selector.

The descriptors also advertise Extension Unit 33, `wExtensionCode=0x0bda`, source Feature Unit 25, stereo, `bmControls=0x00`. No writable Audio Class control is advertised there; Output Terminal 17 refers directly to unit 25. This is an investigation seed for Windows vendor-specific processing, not evidence that unit 33 supplies missing gain or bias. The HID interface is 7 with endpoint `0x8a`; its 34-byte report descriptor was inaccessible to the unprivileged Linux collection, so its contents remain unknown.

The existing trial outcomes are more informative than changing names: each isolated capture switch affected only its own PCM, and the other two PCMs became digital silence. The +12 dB controls demonstrably reach their matching capture streams, while the user still hears no voice. This supports investigation below UCM but does not isolate routing versus bias versus gain versus firmware state.

## Current UCM behavior

[`USB-Audio.conf` lines 68–140](https://github.com/alsa-project/alsa-ucm-conf/blob/d260eedd1900dbf3b477047e048d5382a5f50e24/ucm2/USB-Audio/USB-Audio.conf#L68) selects `Realtek/ALC4080` for `0b05:1b9b`. [`ALC4080-HiFi.conf` defaults](https://github.com/alsa-project/alsa-ucm-conf/blob/d260eedd1900dbf3b477047e048d5382a5f50e24/ucm2/USB-Audio/Realtek/ALC4080-HiFi.conf#L22) retain Mic/PCM 2 and Line/PCM 1. No exact `1b9b` override appears in that HiFi file. The Analog In/PCM 0 rear-microphone override at [line 134](https://github.com/alsa-project/alsa-ucm-conf/blob/d260eedd1900dbf3b477047e048d5382a5f50e24/ucm2/USB-Audio/Realtek/ALC4080-HiFi.conf#L134) matches another ASUS device, `0b05:1996`.

UCM enable sequences merely switch the chosen advertised capture mute control on; they do not send a newly established vendor microphone-initialization request. The user's PCM 0 direct trials already cover the apparent Analog In alternative. Copying the other board's override would therefore not be a demonstrated audio fix.

## Existing Realtek USB/HDA tunnel

[`mixer_quirks.c` lines 2214–2272](https://github.com/torvalds/linux/blob/24a19b953e2a3d0ea5a8c4951a0ab8f32720c907/sound/usb/mixer_quirks.c#L2214) documents Dell WD15 ALC4020 USB controller plus ALC3263 codec. UAC1 lacks jack detection, so that implementation transports HDA commands over vendor USB control transfers.

| Operation | bmRequestType | bRequest | wValue | wIndex | Payload/result |
|---|---|---|---|---|---|
| `realtek_hda_set()` | `0x40` (OUT/vendor/device) | 62 / `0x3e` | `0x0038` | 0 | 4-byte **big-endian** HDA command |
| `realtek_hda_get()`, command stage | `0x40` | 88 / `0x58` | `0x0038` | 0 | 4-byte big-endian HDA command |
| `realtek_hda_get()`, response stage | `0xc0` (IN/vendor/device) | 89 / `0x59` | `0x0038` | 0 | 4-byte big-endian response |
| Existing Dell manual-mode disable | `0x40` | 72 / `0x48` | 0 | 0 | No payload |

The macro constructs `cmd=(node << 20) | (verb << 8) | data`. Linux constants in [`hda_verbs.h`](https://github.com/torvalds/linux/blob/24a19b953e2a3d0ea5a8c4951a0ab8f32720c907/include/sound/hda_verbs.h#L36) can decode Windows payloads if compatibility is established: connection select (`0x701`/`0xf01`), pin widget control (`0x707`/`0xf07`), pin sense (`0xf09`), amplifier (`0x300`/`0xb00`), coefficient index (`0x500`), and coefficient access (`0x400`/`0xc00`). Pin-control bits distinguish input enable and VREF choices, but no ASUS pin node or VREF setting is established by the Dell code.

The existing [Dell creation path](https://github.com/torvalds/linux/blob/24a19b953e2a3d0ea5a8c4951a0ab8f32720c907/sound/usb/mixer_quirks.c#L2358) first powers its codec down and disables manual mode; this is not an ASUS initialization recipe. [Dispatch](https://github.com/torvalds/linux/blob/24a19b953e2a3d0ea5a8c4951a0ab8f32720c907/sound/usb/mixer_quirks.c#L4545) invokes it only for `0bda:4014`/`0bda:402e`, not this `0b05:1b9b`. The Dell HDA node IDs `0x1a`, `0x20`, and `0x21` and coefficient `0x50` cannot be transferred to this board from naming alone.

## Latest issue evidence and reported fixes

- [#718](https://github.com/alsa-project/alsa-ucm-conf/issues/718): exact X870E-E, same USB ID. The body reports unsuccessful rear capture after UCM recognition, startup clicks, and Line jack events. Its [March 17 comment](https://github.com/alsa-project/alsa-ucm-conf/issues/718#issuecomment-4077303510) explicitly presents initialization/routing as a guess, not a proven command. The body's ALC4082 label conflicts with the board's ALC4080 specification and is not treated as hardware authority.
- [#780](https://github.com/alsa-project/alsa-ucm-conf/issues/780): X870-F, same USB ID, working front microphone and silent rear microphone. Its [maintainer reply](https://github.com/alsa-project/alsa-ucm-conf/issues/780#issuecomment-4649386197) asks for a newer UCM retest and ALSA info. An [August 3 X870-A report](https://github.com/alsa-project/alsa-ucm-conf/issues/780#issuecomment-5168928475) still reports rear-mic failure with UCM 1.2.16 and kernel 7.1.5. Thus a shared USB ID covers multiple board models and a newer version alone is not a verified cure.
- [#541 maintainer instructions](https://github.com/alsa-project/alsa-ucm-conf/issues/541): establish direct ALSA PCM/mixer/jack behavior first; then analyze Windows USB transactions with an action timeline where functionality is missing. Device-specific firmware and undocumented transactions are possibilities, not proved causes for this user.
- The exact-board [March 7 comment](https://github.com/alsa-project/alsa-ucm-conf/issues/541#issuecomment-4017511620) retracts its original workaround and reports temporary success after Windows reboot. The user's complete warm/cold matrices do **not** reproduce usable voice, so that anecdote cannot replace the current evidence or justify a boot-Windows workaround.
- A [reported MSI 5.1 fix](https://github.com/alsa-project/alsa-ucm-conf/issues/541#issuecomment-3431915021) has an [independent MSI X870E Edge Ti confirmation](https://github.com/alsa-project/alsa-ucm-conf/issues/541#issuecomment-3691085689). Its [source](https://pastebin.com/3bdAwD74) is saved as `linux_source/community-5.1-libusb.cpp` (SHA-256 `05c2f99f464f880074e5a76428cbc0bf06a70c35e52f273e8cf0dac73d839758`). It selects **MSI `0db0:cd0e`**, sends vendor request `0x40/0x6c`, `wValue=0`, `wIndex=1`, first one-byte data `02`, then `04`. This demonstrates a reported retasking command for surround on a different board. It neither enables microphone gain nor proves ASUS compatibility. It was inspected, not compiled or executed here.
- A claimed [MSI B850 UCM recognition fix](https://github.com/alsa-project/alsa-ucm-conf/issues/541#issuecomment-4290940221) is about another ID. The exact-board reporter [explicitly says recognition is insufficient](https://github.com/alsa-project/alsa-ucm-conf/issues/541#issuecomment-4320658110). Neither is a candidate command for this ASUS device.

## Plausible Linux integration point after the Windows evidence is established

1. **Known, fixed microphone initialization:** `snd_usb_mixer_apply_create_quirk()` is called after generic mixer controls and status setup, before exposing the completed mixer. A narrow device/board quirk can use `snd_usb_ctl_msg()` to retain the driver's transfer allocation, timeout, and quirk behavior. Static helper layout should be corroborated with a hardware transaction/result before introducing a default write.
2. **User-selectable microphone/line retasking or boost:** an ALSA mixer quirk is a natural place for a documented control with truthful ranges, readback where possible, serialized request handling, and a resume callback. Merely renaming the UAC terminal or mapping a different PCM does not supply that hardware function.
3. **Earlier probe-time request:** `snd_usb_apply_boot_quirk()`/`snd_usb_apply_boot_quirk_once()` are available if evidence proves a command must occur before generic parsing or enumeration. Their [call sites](https://github.com/torvalds/linux/blob/24a19b953e2a3d0ea5a8c4951a0ab8f32720c907/sound/usb/card.c#L975) are earlier than mixer creation. Choose them only from established ordering requirements, not because initialization is suspected.
4. **Power management:** [`snd_usb_mixer_resume()`](https://github.com/torvalds/linux/blob/24a19b953e2a3d0ea5a8c4951a0ab8f32720c907/sound/usb/mixer.c#L3902) invokes `private_resume`, restores per-element values/callbacks, then runs the device-specific resume quirk and activates the status endpoint. The correct ordering for ASUS mode/bias versus generic mute/volume restoration remains unknown. Request-pair HDA GET operations and coefficient-index/access pairs need a single shared serialization boundary to avoid interleaving.
5. **Desktop exposure:** once direct rear speech works, map its measured PCM, effective mixer element, and responding jack detector in a scoped UCM change. Keep playback working, and test reset, resume, cold boot, and jack reinsert before describing the result as fixed.

USB ID alone is insufficiently unique for assuming an exact board layout. The confirmed board is ASUS ROG STRIX X870E-E GAMING WIFI Rev 1.xx, BIOS 2202, revision `0013`; other reports use the same VID:PID. Validate descriptors/revision and, if needed, DMI board matching before any default board-specific behavior. Build against the user's actual `7.0.0-34-generic` source/headers rather than substituting upstream master. Nothing in this report proves the running Ubuntu kernel's downstream behavior matches every inspected upstream line.

## Remaining evidence needed

- Resolve the Windows driver entry points and per-board configuration for the supplied ZIP's matching hardware ID. Determine whether rear MIC IN mode, bias, analog boost, and capture start actually use HDA tunnel requests, request `0x6c`, standard UAC2 controls, HID, or some other protocol.
- Recover exact payloads, lengths, byte order, sequencing, node/register meaning, preserved bits, and restore/reset requirements. A transport helper or debug string alone does not establish that a sequence runs for this board.
- Obtain the working target's Windows control traffic with a recording timeline if static evidence leaves a command's execution/ordering unresolved. The generic Windows driver package may cover several firmware/board configurations.
- Hardware verification on Kubuntu is pending. The current Windows workspace cannot truthfully certify Linux rear microphone speech, suspend/resume, or kernel-module compatibility.

Search boundary: inspected the files and exact commits listed above; all public API comment records returned for issues #718/#780/#541; focused web searches for the exact USB ID, ALC4080 microphone/HDA/vendor transport, and upstream ALSA discussion. Kernel Bugzilla #218913 remained behind an Anubis access challenge, so its full comments/attachments were not verified. No unsupported command was sent to hardware, no complete Windows trace was replayed, and no firmware was flashed.

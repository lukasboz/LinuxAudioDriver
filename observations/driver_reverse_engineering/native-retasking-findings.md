# Native jack-retasking findings

Source: `RtUsbA64.sys`, SHA-256 `4fef11b7d0d2b04b9ca830a4b10f02a60c0c105703d80f4a746e9be5411a8921`. The existing Ghidra project was reused through the saved CLI function exports under `ghidra/`; this branch opened no provider or duplicate project. This is decompiled static evidence, not original source or an observed Windows execution. Raw exports are ordinary Ghidra results, not REA Evidence envelopes.

## Exact recovered type names

`0x1400560ec` returns these literal names, removing an ambiguity in the assignment function's integer argument:

| `AssignDeviceType` argument | Literal name |
|---:|---|
| `0` | `WidgetTypeLineIn` |
| `1` | `WidgetTypeMicIn` |
| `5` | `WidgetTypeSurr` |
| `6` | `WidgetTypeCenter` |
| `7` | `WidgetTypeSide` |
| `0xf` | `WidgetTypeMicIn2` |
| `0x21` | `WidgetTypeHeadSetMic` |

Therefore `0x21` and `0xf` are distinct headset/second-microphone cases. Neither can be assumed to represent the default rear microphone merely because it contains a microphone label.

`0x14005470c` computes an internal endpoint type separately: `MicIn2` fixes it to `8`; `HeadSetMic` fixes it to `10`. `MicIn` uses flags, family/profile and widget identity. For family values `0x34`, `0x92`, `0xb3`, `0xb4`, widget ID `0x18` maps to `6`, widget `0x38` to `8`, and `0x39` to `11`. Widget `0x19` maps to `6` in the explicit profile `0x84/0x85` branch; other conditions can retain its existing internal type. `0x14003a624` returns exact internal names: `6=eMic`, `7=eLineIn`, `8=e2ndMic`, `10=eHeadsetMic`, `11=e3rdMic`. These are Windows driver enums, not USB Audio control selectors.

## Target's compiled rear microphone configuration

The driver VID/PID table entry at file `0x672c0` / VA `0x1400692c0` is `05 0b 9b 1b b4 00 00 00 84 00 00 00 00 00 00 00`: target VID/PID, family `0xb4`, profile `0x84`, and zero extra word. `0x14004eb18` searches 16-byte table entries for the two 16-bit IDs and returns these three values.

The family `0xb4`/profile `0x84` branch of `0x14003e2d8` supplies `cb6=1`, `cb4=2`, `cb1=3`, `cb2=4`, `cb0=5`, `cb5=6`; `cb3` is not assigned in that branch. It sets `0x2388` bits `1` and `2`; the explicit PID `1b9b` suffix adds bit `4` and `0x2384` bit `0x40000`. Base-family initialization and possible later registry overrides must still be considered when treating these as a runtime flag snapshot.

The CCommon constructor `0x140023438` zeroes the qword at offset `0xcb0`, including `cb3`; the family helper `0x1400304b8` changes flags without assigning those bytes. Consequently that branch constructs the rear record at `context+0xe94` (index 3 of the 12-byte records starting at `0xe70`): first dword `0x41a89020`, remaining dwords zero, paired override at `context+0xf3c` equal to `0x30100`. The record is derived explicitly from `cb4=2`; `0x1400395d8` labels that capture interface **Rear Mic** when internal type is `6=eMic`.

`0x140053be0` decodes this first dword into widget ID `(word>>30)*16 + ((word>>16)&15) = 0x18`, named `WIDGET_ID_MIC_IN` by `0x14005627c`. The record's device-type nibble is `0xa` (microphone). Its constructor assigns the widget to `context+0xe58` when that nibble matches the compiled microphone slot and the profile is `0x84/0x85`. The constructor later calls `AssignDeviceType` with its selected/default type. The default decoder `0x140055f24` maps nibble `0xa` to argument `1=WidgetTypeMicIn`; persisted-type override `0x14004c75c` can take precedence.

Thus the Windows driver explicitly treats this rear USB/interface path as its first microphone. This identifies a concrete target-specific MicIn branch rather than relying on adjacent-device resemblance. The rear record calculation has been verified numerically: `0x41a89020` gives widget `0x18`, device nibble `0xa`, interface nibble `2`; front record `0xc2b89030` gives widget `0x38`, device nibble `0xb`, interface nibble `3`.

## USB request wrapper and conditional microphone transitions

`0x140052368(context, byte)` calls `0x14003190c(context, 0x17, 0x40, 0x6c, 0, 1, &byte, 1, 0)`. The common request-builder export shows the USB setup fields and buffer length. Its recovered setup is:

```text
bmRequestType = 0x40
bRequest     = 0x6c
wValue       = 0
wIndex       = 1
wLength      = 1
payload      = one selector byte
```

This proves that these helper calls submit vendor commands in the recovered control flow. It does not independently prove the firmware-side meaning or that a given branch executes for the attached target.

In `0x14005470c`, selecting `WidgetTypeMicIn` (`argument=1`) dispatches the following conditional commands, depending on which context slot contains the current widget:

| Widget equals context slot | Hexadecimal byte payloads, in order |
|---|---|
| `context+0xe48` | `00`; then `0d` only when the old widget type was `WidgetTypeSurr` (`5`) |
| `context+0xe58` | `15` only when the old widget type was `WidgetTypeCenter` (`6`); then `13` |
| `context+0xe60` | `0f` |

For selecting `WidgetTypeLineIn` (`argument=0`): `context+0xe48` dispatches payload `00` or `01` according to flag mask `0x80400`; `context+0xe58` dispatches `12` when its prior type is below `2`, or `15` when prior type is `6`.

The compiled target configuration plus constructor now establishes `context+0xe58` as this rear microphone widget. Therefore selecting `WidgetTypeMicIn` on that rear widget dispatches vendor request `0x6c` with payload **`0x13`**, preceded by **`0x15`** only when converting from Center (`6`). The default constructor argument is MicIn when a persisted override is absent. Its USB submission occurs before the assignment function's later `uVar10==0` gate, so that gate does not suppress this request. This is a supported static startup protocol candidate; actual startup execution, firmware-side effect, bias state and working Linux behavior have not been observed.

**Payload `01` followed by `0c` is not the MicIn branch.** It occurs when selecting `WidgetTypeSurr` (`argument=5`), the widget equals `context+0xe48`, and `context+0x2388` bit 0 is set. The PID `1b9b` special case in that branch changes the subsequent software endpoint handling; it does not turn surround into microphone. Likewise, the `14` branch belongs to selecting `WidgetTypeCenter`, not MicIn.

## Target-specific endpoint handling versus hardware actions

`0x1400395d8` explicitly tests PID `1b9b` (or profile `0x85`) and assigns endpoint names:

- Interface number equals context byte at `0xcb1`: internal type `8` becomes **Front Mic**, otherwise **Front Line**.
- Interface number equals context byte at `0xcb4`: internal type `6` becomes **Rear Mic**, otherwise **Rear Line**.

This establishes the driver's front/rear labeling rule; the compiled target profile initializes `cb1=3`, `cb4=2` as described above. The function writes endpoint property names through `0x14003bf88`; it is not a recovered microphone bias operation.

Other assignment helpers also need careful interpretation:

- `0x14003c72c` disables/frees Windows KS filter-factory objects. Its body contains no recovered USB submission.
- `0x14003a868` creates/enables Windows KS filter factories and their classes. Its target-specific branches suppress capture endpoints while relevant widgets have surround/center/side types. This explains part of Windows endpoint visibility; it does not by itself initialize the codec.
- `0x14003c95c` calls `0x14003cbd8` and `0x14003c8b8`, then updates internal type and pin-data descriptors. Both callees have now been inspected: they update in-memory pin/connection descriptors without calling a USB helper. Scheduled notification callbacks remain a separate boundary.
- `0x140055f90` edits in-memory pin-configuration bits according to widget type. Values `1` and `0xf` assign the same microphone device nibble `0xa`; it contains no USB submission itself.
- `0x14003ccf0` notifies Windows KS clients or schedules a callback/timer. It contains no direct USB request; a scheduled callback is a separate analysis boundary.
- `0x14003c514` updates endpoint processing-mode GUID properties, rather than a microphone gain/bias control.

## Jack-state path

`0x140055b90` (`CWidget::ChkPlugState`) uses a generic `node<<20 | 0xf0900` command only outside its recognized codec-family condition. Codec value `0x4080` bypasses that generic branch and delegates to `0x140055990`.

`0x140055990` obtains state through the object's `context+0xb18` virtual interface, compares repeated readings, updates widget state bits, and can call `0x140030f40` when flags permit. The concrete implementation behind that virtual interface must be resolved to derive the target's jack-status USB read. Assuming the generic `0xf0900` path applies to this target would be unsupported.

`0x1400256a0` (`CCommon::CheckJDStatus`) also has an explicit PID `1b9b` branch: on jack-state changes it skips the normal endpoint notification for widget IDs `0x3a/0x3b`. That is evidence of tailored jack/topology handling, not proof of a Linux jack fix.

## Microphone boost and ordinary gain

The gain-field interpretation is now corroborated by node identities and consumers. Raw GUID bytes at VA `0x14005fd20` decode to `3a5acc00-c557-11d0-8a2b-00a0c9255ac1` (`KSNODETYPE_VOLUME`); at `0x14005feb0`, they decode to `2bc31d6a-96e3-11d2-ac4c-00c04f8efb68` (`KSAUDFNAME_MICROPHONE_BOOST`). These names match [Microsoft's ksmedia.h definitions](https://github.com/microsoft/win32metadata/blob/main/generation/WinSDK/RecompiledIdlHeaders/shared/ksmedia.h#L2147).

`0x1400375b8` builds that additional microphone-boost node using max `30`, min `0`, step metadata `10` from `context+0xad8/0xadc`. The B4/profile84 path qualifies feature-unit IDs `0x1b` and `0x1c`; its different-profile special case for `0x1a` does not apply. `0x14004d7e8` shifts range limits by 16 bits when handling volume values. Microsoft documents volume property units as [1/65536 dB](https://learn.microsoft.com/en-us/windows-hardware/drivers/audio/ksproperty-audio-volumelevel), supporting a 0–30 dB boost range. Exact step handling and firmware gain correspondence still need further tracing.

The boost handler `0x14004d7e8` updates the added node's channel values and calls `0x14003c4a8(endpoint, 6, &gain, 4)` for a channel-zero update. The final property path has now been traced: `0x14003c4a8` indexes an endpoint-property name table and calls `0x14003bf88` with its FX-property flag set. That helper writes `FxProperties` in the device registry, or the Windows `MMDevices\\Audio\\Capture` registry tree, using `ZwSetValueKey`. Its alternate device-registry helpers `0x14003ac18` and `0x140031bac` use `IoOpenDeviceRegistryKey`, `ZwCreateKey`, and `ZwSetValueKey`; `0x14003a5ec` selects the endpoint's WaveIn/WaveOut key. These inspected paths contain no USB submission. Therefore this boost-property update is Windows processing/registry state, not an additional recovered USB boost command. The later APO/service consumer and resulting gain implementation have not been traced.

The separate `0x14004db18` handler dispatches ordinary USB class mute/volume requests through `0x140031890`, with selector, channel, feature-unit and value derived from USB/control metadata. This supports continuing to use the existing ALSA capture switch/volume during the experiment; it does not establish an additional fixed vendor sequence that must accompany payload `0x13`.

The proposed `realtek_rear_mic.py` tuple matches the recovered request, and its LineIn payload `0x12` matches the static inverse selection from MicIn type `1`. Sending only `0x13` is a justified minimal experiment, not a proven complete microphone fix. No bias control or extra compulsory vendor initialization was identified in the inspected assignment/endpoint helpers.

## Remaining decisive gaps

1. Target family/profile, compiled interfaces, rear slot and default MicIn argument are established above. Persisted-type overrides and later flag handling can still change runtime behavior.
2. The inspected endpoint descriptor/activation helpers principally handle Windows software state. The identified 0–30 dB microphone-boost node writes an FX registry property; its later APO/service consumer remains unresolved. No additional required hardware boost command follows from that update.
3. Resolve jack virtual-interface implementation and `0x140030f40` to recover target read/change handling.
4. Bias enablement and firmware-side boost/gain implementation are **unresolved** in this export set. No register/control has been established as bias, and no command from this report has been tested on Kubuntu.

The guarded Linux experiment implements the recovered rear MicIn request only. Its USB tuple and device checks are software-tested; usable voice and completeness of the runtime sequence require the user's hardware test. If that test fails, a working-Windows USB trace can establish the actual conditional commands and further device setup. See [the experiment and verification instructions](../../REVERSE_ENGINEERING.md).

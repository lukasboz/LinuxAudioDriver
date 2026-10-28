# Next experiment: capture the working Windows device setup

**Update, 2026-10-13:** Static analysis has recovered this exact board's rear-microphone selector. Try the guarded candidate and recording procedure in [REVERSE_ENGINEERING.md](REVERSE_ENGINEERING.md) first. The capture workflow below remains useful if that request fails or is accepted without intelligible voice; it can establish further runtime setup and conditional commands.

Both warm and cold Ubuntu direct ALSA matrices completed successfully, with each isolated capture path at its exposed maximum of +12 dB. The user confirms no intelligible voice in either run. The archive verifies the mixer writes and recordings. Continue below UCM; no particular missing command or driver patch has been proven.

## Confirmed target

| Item | Value from the Ubuntu archive |
|---|---|
| Motherboard | ASUS ROG STRIX X870E-E GAMING WIFI, Rev 1.xx |
| BIOS | 2202; date string `04/09/2026` |
| USB identity | `0b05:1b9b`, device revision 0.13 |
| Physical Linux USB port | `3-6`, controller PCI `0000:13:00.0` |
| Audio control interface | 0, with interrupt endpoint `0x89` |
| Analog In capture | PCM 0, interface 1, endpoint `0x81`, Feature Unit 25 |
| Line capture | PCM 1, interface 2, endpoint `0x83`, Feature Unit 27 |
| Mic capture | PCM 2, interface 3, endpoint `0x84`, Feature Unit 28 |
| Other interfaces | Playback interfaces 4-6; HID interface 7, interrupt endpoint `0x8a` |

The HID interface advertises a 34-byte report descriptor, but the unprivileged collector could not read that descriptor. Its presence is not proof of a vendor command mechanism. Capture the device's complete control traffic, audio control notifications, and HID traffic. Do not restrict the capture to the Windows audio child alone.

The analog G335 does not have its own USB address. Windows USBPcap hub numbers do not correspond directly to Linux bus 3. Addresses can change after a device restart.

## 1. Record the Windows reference

Boot Windows and confirm intelligible microphone recording with the same rear splitter connection and lowered microphone boom. Record:

- Windows version and ASUS/Realtek audio driver provider, version, and date, from Device Manager.
- Rear jack assignment shown in the Realtek app, if available.
- Input level, microphone boost, and any recording enhancements. Keep the initial settings and record changes instead of assuming these settings are irrelevant.

In PowerShell, list the matching USB devices:

```powershell
Get-PnpDevice -PresentOnly |
    Where-Object { $_.InstanceId -like 'USB\VID_0B05&PID_1B9B*' } |
    Format-List Status,Class,FriendlyName,InstanceId
```

Save that output or the matching Device Manager hardware IDs with the capture. The physical USB parent has an instance ID without an `&MI_` interface suffix. The audio child generally has `&MI_00` and the HID child `&MI_07`. Verify this on the actual machine; friendly names can differ.

## 2. Capture Windows actions

Use Wireshark with USBPcap. If either component is absent, install it using the official [Wireshark downloads](https://www.wireshark.org/download.html) and [USBPcap project](https://desowin.org/usbpcap/) instructions, and restart Windows if the installer requires it.

1. In Wireshark, open the configuration gear for a USBPcap capture interface. Inspect its attached-device tree to find the root hub containing the device with VID `0b05` and PID `1b9b`. Choose that hub. Include the target device and newly connected devices, so a changed address will still be captured. If identity or filtering is unclear, retain a short complete capture of that hub locally and filter a copy afterward.
2. Start capture **before** restarting the target. Close camera and other unnecessary USB streaming applications to keep the capture manageable. Leave capture length/snap length at full packets.
3. Restart only the verified physical USB audio parent while capture runs. This may briefly interrupt motherboard audio. To select it precisely, run the following in an Administrator PowerShell window:

   ```powershell
   $audioParent = @(Get-PnpDevice -PresentOnly | Where-Object {
       $_.InstanceId -match '^USB\\VID_0B05&PID_1B9B(?:&REV_[0-9A-F]{4})?\\'
   })
   if ($audioParent.Count -ne 1) {
       throw 'Expected exactly one matching physical USB audio parent; inspect Device Manager.'
   }
   $audioParent | Format-List Status,Class,FriendlyName,InstanceId
   pnputil /restart-device "$($audioParent[0].InstanceId)"
   ```

   Retain the selected instance ID, restart command result, and approximate capture-relative time. If restart is rejected, requires a reboot, or recording fails afterward, preserve that result and stop treating the trace as a working reinitialization reference. Do not restart a USB controller or root hub.
4. Wait for audio to return. Remove just the rear microphone plug, wait about five seconds, reinsert it, and wait another five seconds. Keep a timeline of these events. If Realtek asks which kind of device was connected, choose the microphone setting that makes Windows recording work and note the choice.
5. Record 10-15 seconds of spoken audio in Windows and confirm it works. Note the exact input source and capture start/stop times. If a microphone/line selector or hardware boost exists, capture one controlled change and a recording afterward, then restore its initial value. Do not invent or apply unavailable controls.
6. Stop capture and save `windows-rear-mic.pcapng`, the action timeline, device/driver information, and the final voice result. Keep the original file unchanged.

A device restart is a useful experiment, not a guarantee of capturing every power-on initialization operation. If it does not reproduce the relevant setup, preserve that result; a more complete re-enumeration or earlier capture must be designed after inspecting the trace. No built-in USBPcap boot-capture procedure has been verified for this machine. Unplugging the analog mic alone does not re-enumerate the internal USB codec. USBPcap's [capture guide](https://desowin.org/usbpcap/tour.html) explains selecting the root hub and capturing new devices. Microsoft's [PnPUtil reference](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/pnputil-command-syntax) documents restarting an exact instance ID.

## 3. Return the evidence

Place the Windows capture and timeline in `observations/windows_reference`. Retain the complete root-hub capture locally; if unrelated devices were captured, supply a filtered copy covering **all** addresses occupied by this device and all its interfaces, preserving enumeration and target control messages. A display filter changes the view; exporting displayed packets creates a filtered file.

An example timeline, with times relative to the capture start:

```text
00.000 capture started; microphone inserted
05.000 physical USB audio parent restart requested; command result: ...
15.000 audio returned
20.000 microphone plug removed
25.000 microphone plug inserted; Realtek selection: ...
35.000 Windows recording started; source: ...
50.000 recording stopped; intelligible voice: yes/no
55.000 capture stopped
```

Use the actual times and outcomes rather than copying these example times. There is no automatic upload or external posting.

## 4. Linux comparison and corrected jack monitor

The original jack-event attempts exited immediately because the tool passed bare `Audio_1` to `alsactl monitor`. It now passes `hw:Audio_1`, the actual ALSA control device. Capture tests use separate code and remain valid. Copy the updated `audio_diag.py` to Ubuntu, then repeat only this short stage:

```bash
python3 audio_diag.py jacks --boot cold
```

Use `--boot cold` only after a direct cold Ubuntu boot. If returning directly from Windows, use `--boot windows-warm` instead. Return the new jack directory; another 12-recording matrix is unnecessary for this correction.

For USB trace comparison, Linux supports usbmon. After the Windows reference is inspected, select the matching Linux operations and initialization trigger. The basic capture preparation, on Ubuntu, is:

```bash
lsusb -d 0b05:1b9b
sudo modprobe usbmon
dumpcap -D
```

The current target is on bus 3, so `usbmon3` is the expected capture interface; verify the bus in that boot. If usbmon permissions need adjustment, use the [Wireshark USB capture instructions](https://wiki.wireshark.org/CaptureSetup/USB). Keep the GUI and `audio_diag.py` running as the desktop user. Do not unload all USB audio drivers or copy/replay Windows writes while collecting a baseline.

Comparison will correlate standard Audio Class requests, any HID/vendor transfers, timing, payloads, and completion status. Candidate writes must be understood and isolated before any proof of concept is implemented. Audio gain, microphone bias, jack mode, and firmware setup remain hypotheses until the traces provide evidence.

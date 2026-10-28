#!/usr/bin/env python3
"""Test the Windows driver's rear-microphone selection on the verified ASUS board.

The default action only prints a plan. 'apply' selects the rear microphone;
'line' selects line input again. This experimental runtime fix needs the user's
Kubuntu recording test. The exact request is documented in REVERSE_ENGINEERING.md.
"""

from __future__ import annotations

import argparse
import ctypes
from dataclasses import dataclass, asdict
import datetime
import json
import os
from pathlib import Path
import platform
import stat
import struct
import sys
from typing import Callable


VID = 0x0B05
PID = 0x1B9B
REVISION = 0x0013
BOARD = "ROG STRIX X870E-E GAMING WIFI"
MODES = {"apply": 0x13, "line": 0x12}
EXPECTED_CAPTURE = {"interface": 2, "pcm_device": 1, "mixer_route": "Line"}


class ControlTransfer(ctypes.Structure):
    # include/uapi/linux/usbdevice_fs.h; the data pointer follows native alignment.
    _fields_ = [
        ("request_type", ctypes.c_uint8), ("request", ctypes.c_uint8),
        ("value", ctypes.c_uint16), ("index", ctypes.c_uint16),
        ("length", ctypes.c_uint16), ("timeout_ms", ctypes.c_uint32),
        ("data", ctypes.c_void_p),
    ]


def control_ioctl_number() -> int:
    return (3 << 30) | (ctypes.sizeof(ControlTransfer) << 16) | (ord("U") << 8)


def validate_device_descriptor(data: bytes) -> None:
    if len(data) != 18 or data[:2] != b"\x12\x01":
        raise ValueError("The USB device descriptor is incomplete or invalid")
    if struct.unpack_from("<HHH", data, 8) != (VID, PID, REVISION):
        raise ValueError("USB identity or device revision differs from the analyzed hardware")


def validate_topology(data: bytes) -> None:
    validate_device_descriptor(data[:18])
    if len(data) < 27 or data[18:20] != b"\x09\x02":
        raise ValueError("Missing USB configuration descriptor")
    total = struct.unpack_from("<H", data, 20)[0]
    if len(data) != 18 + total or data[22] != 8:
        raise ValueError("USB configuration length or interface count differs from the baseline")
    interfaces: dict[int, tuple[int, int, int]] = {}
    endpoints: dict[int, set[int]] = {}
    interface = None
    offset = 18
    while offset < len(data):
        if offset + 2 > len(data):
            raise ValueError("Truncated USB descriptor header")
        length, kind = data[offset:offset + 2]
        if length < 2 or offset + length > len(data):
            raise ValueError("Invalid USB descriptor boundary")
        part = data[offset:offset + length]
        if kind == 4:
            if length < 9:
                raise ValueError("Truncated interface descriptor")
            interface = part[2]
            declaration = tuple(part[5:8])
            if interface in interfaces and interfaces[interface] != declaration:
                raise ValueError("Inconsistent alternate interface settings")
            interfaces[interface] = declaration
        elif kind == 5:
            if length < 7 or interface is None:
                raise ValueError("Endpoint without a valid interface")
            endpoints.setdefault(interface, set()).add(part[2])
        offset += length
    expected = {0: (1, 1, 0x20), 7: (3, 0, 0)}
    expected.update({number: (1, 2, 0x20) for number in range(1, 7)})
    if interfaces != expected:
        raise ValueError("USB audio/HID interface topology differs from the analyzed hardware")
    for number, endpoint in {0: 0x89, 1: 0x81, 2: 0x83, 3: 0x84, 7: 0x8A}.items():
        if endpoint not in endpoints.get(number, set()):
            raise ValueError(f"Expected endpoint 0x{endpoint:02x} absent on interface {number}")


@dataclass(frozen=True)
class Device:
    sysfs_path: str
    bus: int
    address: int
    board: str
    alsa_cards: tuple[str, ...]

    @property
    def device_node(self) -> str:
        return f"/dev/bus/usb/{self.bus:03d}/{self.address:03d}"


def discover_device(sysfs: Path = Path("/sys")) -> Device:
    board = (sysfs / "class/dmi/id/board_name").read_text().strip()
    if board.upper() != BOARD:
        raise ValueError(f"This experiment was derived for {BOARD}; detected {board!r}")
    matches = []
    for entry in (sysfs / "bus/usb/devices").iterdir():
        if ":" in entry.name or not (entry / "idVendor").exists():
            continue
        if (int((entry / "idVendor").read_text(), 16),
                int((entry / "idProduct").read_text(), 16)) == (VID, PID):
            matches.append(entry)
    if len(matches) != 1:
        raise ValueError(f"Expected exactly one {VID:04x}:{PID:04x} USB device; found {len(matches)}")
    target = matches[0]
    if int((target / "bcdDevice").read_text(), 16) != REVISION:
        raise ValueError("Device revision differs from the analyzed 0x0013 hardware")
    validate_topology((target / "descriptors").read_bytes())
    driver = (sysfs / "bus/usb/devices" / (target.name + ":1.0") / "driver").resolve()
    if driver.name != "snd-usb-audio":
        raise ValueError("The target audio interface is not bound to snd-usb-audio")
    cards = []
    for card in (sysfs / "class/sound").glob("card[0-9]*"):
        if card.name[4:].isdigit() and (card / "device").resolve().is_relative_to(target.resolve()):
            cards.append(card.name)
    if len(cards) != 1:
        raise ValueError(f"Expected one ALSA card for the target; found {len(cards)}")
    bus, address = int((target / "busnum").read_text()), int((target / "devnum").read_text())
    if not 1 <= bus <= 999 or not 1 <= address <= 127:
        raise ValueError("Invalid USB bus/device address")
    return Device(str(target.resolve()), bus, address, board, tuple(sorted(cards)))


class Usbfs:
    def __init__(self, fd: int, ioctl: Callable | None = None):
        self.fd = fd
        if ioctl is None:
            library = ctypes.CDLL(None, use_errno=True)
            ioctl = library.ioctl
            ioctl.argtypes = [ctypes.c_int, ctypes.c_ulong, ctypes.c_void_p]
            ioctl.restype = ctypes.c_int
        self.ioctl = ioctl

    def transfer(self, request_type: int, request: int, value: int, index: int,
                 payload: bytes | int) -> bytes:
        incoming = bool(request_type & 0x80)
        if incoming:
            if not isinstance(payload, int):
                raise ValueError("IN transfer requires a length")
            buffer = (ctypes.c_ubyte * payload)()
        else:
            if not isinstance(payload, bytes):
                raise ValueError("OUT transfer requires bytes")
            buffer = (ctypes.c_ubyte * len(payload)).from_buffer_copy(payload)
        control = ControlTransfer(request_type, request, value, index,
                                  len(buffer), 3000, ctypes.addressof(buffer))
        ctypes.set_errno(0)
        returned = self.ioctl(self.fd, control_ioctl_number(), ctypes.byref(control))
        if returned < 0:
            error = ctypes.get_errno()
            raise OSError(error, os.strerror(error))
        if returned != len(buffer):
            raise OSError(f"USB transfer returned {returned} bytes; expected {len(buffer)}")
        return bytes(buffer)


def send_mode(usb: Usbfs, action: str) -> dict:
    # Revalidate the opened device after discovery, before any OUT transfer.
    descriptor = usb.transfer(0x80, 6, 0x0100, 0, 18)
    validate_device_descriptor(descriptor)
    mode = MODES[action]
    usb.transfer(0x40, 0x6C, 0, 1, bytes([mode]))
    return {"bmRequestType": "0x40", "bRequest": "0x6c", "wValue": 0,
            "wIndex": 1, "wLength": 1, "payload_hex": f"{mode:02x}",
            "transferred_bytes": 1}


def execute(device: Device, action: str) -> dict:
    if sys.platform != "linux" or platform.machine().lower() not in {"x86_64", "aarch64"}:
        raise ValueError("Hardware transfer supports 64-bit x86/ARM Linux only")
    if os.geteuid() != 0:
        raise PermissionError("Run the apply/line action with sudo to access this USB device")
    fd = os.open(device.device_node, os.O_RDWR | os.O_CLOEXEC | os.O_NOFOLLOW)
    try:
        info = os.fstat(fd)
        expected_minor = (device.bus - 1) * 128 + device.address - 1
        if not stat.S_ISCHR(info.st_mode) or os.major(info.st_rdev) != 189 or os.minor(info.st_rdev) != expected_minor:
            raise ValueError("Opened node does not match the discovered USB bus/device")
        transfer = send_mode(Usbfs(fd), action)
        return {"status": "transferred", "device": asdict(device), "transfer": transfer,
                "hardware_audio_result": "unverified; listen to a direct ALSA recording"}
    finally:
        os.close(fd)


def plan() -> dict:
    return {
        "status": "planned", "experimental": True,
        "target": {"usb_id": "0b05:1b9b", "bcdDevice": "0x0013", "board": BOARD},
        "apply_transfer": {"bmRequestType": "0x40", "bRequest": "0x6c", "wValue": 0,
                           "wIndex": 1, "wLength": 1, "payload_hex": "13"},
        "line_input_transfer": {"bmRequestType": "0x40", "bRequest": "0x6c", "wValue": 0,
                                "wIndex": 1, "wLength": 1, "payload_hex": "12"},
        "expected_capture": EXPECTED_CAPTURE,
        "evidence": "observations/driver_reverse_engineering/native-retasking-findings.md",
        "verification": "Transfer construction tested; hardware recording result is pending",
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("action", nargs="?", choices=["plan", "status", "apply", "line"], default="plan")
    parser.add_argument("--dry-run", action="store_true", help="Print the plan without opening the device")
    args = parser.parse_args(argv)
    report = plan()
    try:
        if not args.dry_run and args.action != "plan":
            if sys.platform != "linux":
                raise ValueError("Device discovery requires the actual Linux host")
            device = discover_device()
            if args.action == "status":
                report = {"status": "identified", "device": asdict(device), "expected_capture": EXPECTED_CAPTURE}
            else:
                report = execute(device, args.action)
    except (OSError, ValueError) as error:
        report = {"status": "failed", "error": str(error)}
    report["timestamp_utc"] = datetime.datetime.now(datetime.timezone.utc).isoformat()
    print(json.dumps(report, indent=2))
    return 1 if report["status"] == "failed" else 0


if __name__ == "__main__":
    raise SystemExit(main())

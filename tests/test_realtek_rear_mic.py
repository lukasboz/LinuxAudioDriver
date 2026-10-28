"""Verify device admission and USB packets without touching audio hardware."""
import ctypes
import errno
import json
import os
from pathlib import Path
import stat
import struct
import subprocess
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest import mock

import realtek_rear_mic as mic


def descriptor(pid=mic.PID, revision=mic.REVISION):
    return struct.pack("<BBHBBBBHHHBBBB", 18, 1, 0x200, 0xEF, 2, 1, 64,
                       mic.VID, pid, revision, 3, 1, 0, 1)


def configuration():
    parts = []
    for number in range(8):
        declaration = (1, 1, 0x20) if number == 0 else ((3, 0, 0) if number == 7 else (1, 2, 0x20))
        endpoint = {0: 0x89, 1: 0x81, 2: 0x83, 3: 0x84, 4: 2, 5: 5, 6: 6, 7: 0x8A}[number]
        parts.append(bytes([9, 4, number, 0, 1, *declaration, 0]))
        parts.append(bytes([7, 5, endpoint, 3, 64, 0, 1]))
    body = b"".join(parts)
    return descriptor() + struct.pack("<BBHBBBBB", 9, 2, len(body) + 9, 8, 1, 0, 0x80, 50) + body


class FakeIoctl:
    def __init__(self, identity=None, short=False, fail=False):
        self.identity = descriptor() if identity is None else identity
        self.short, self.fail = short, fail
        self.calls = []

    def __call__(self, fd, request, pointer):
        control = ctypes.cast(pointer, ctypes.POINTER(mic.ControlTransfer)).contents
        incoming = bool(control.request_type & 0x80)
        packet = (control.request_type, control.request, control.value, control.index, control.length)
        data = ctypes.string_at(control.data, control.length)
        self.calls.append((packet, data, request))
        if incoming:
            ctypes.memmove(control.data, self.identity, len(self.identity))
            return len(self.identity)
        if self.fail:
            ctypes.set_errno(errno.EPIPE)
            return -1
        return 0 if self.short else control.length


class RearMicTests(unittest.TestCase):
    def test_apply_is_identity_read_then_exact_recovered_out_packet(self):
        fake = FakeIoctl()
        result = mic.send_mode(mic.Usbfs(123, fake), "apply")
        self.assertEqual(len(fake.calls), 2)
        self.assertEqual(fake.calls[0][0], (0x80, 6, 0x100, 0, 18))
        self.assertEqual(fake.calls[1][:2], ((0x40, 0x6C, 0, 1, 1), b"\x13"))
        self.assertEqual(result["transferred_bytes"], 1)

    def test_line_mode_is_driver_inverse_of_mic_selection(self):
        fake = FakeIoctl()
        mic.send_mode(mic.Usbfs(123, fake), "line")
        self.assertEqual(fake.calls[1][:2], ((0x40, 0x6C, 0, 1, 1), b"\x12"))

    def test_address_reuse_with_other_product_prevents_out(self):
        fake = FakeIoctl(identity=descriptor(pid=0x1996))
        with self.assertRaises(ValueError):
            mic.send_mode(mic.Usbfs(123, fake), "apply")
        self.assertEqual(len(fake.calls), 1)

    def test_unanalyzed_revision_prevents_out(self):
        fake = FakeIoctl(identity=descriptor(revision=0x14))
        with self.assertRaises(ValueError):
            mic.send_mode(mic.Usbfs(123, fake), "apply")
        self.assertEqual(len(fake.calls), 1)

    def test_short_device_descriptor_prevents_out(self):
        fake = FakeIoctl(identity=descriptor()[:8])
        with self.assertRaises(OSError):
            mic.send_mode(mic.Usbfs(123, fake), "apply")
        self.assertEqual(len(fake.calls), 1)

    def test_short_write_is_failure(self):
        with self.assertRaises(OSError):
            mic.send_mode(mic.Usbfs(123, FakeIoctl(short=True)), "apply")

    def test_stall_is_failure_with_preserved_errno(self):
        with self.assertRaises(OSError) as captured:
            mic.send_mode(mic.Usbfs(123, FakeIoctl(fail=True)), "apply")
        self.assertEqual(captured.exception.errno, errno.EPIPE)

    def test_expected_topology_is_admitted(self):
        mic.validate_topology(configuration())

    def test_changed_capture_endpoint_is_rejected(self):
        changed = configuration().replace(b"\x07\x05\x83", b"\x07\x05\x82")
        with self.assertRaises(ValueError):
            mic.validate_topology(changed)

    def test_truncated_configuration_is_rejected(self):
        with self.assertRaises(ValueError):
            mic.validate_topology(configuration()[:-1])

    def test_zero_descriptor_length_is_rejected(self):
        changed = bytearray(configuration())
        changed[27] = 0
        with self.assertRaises(ValueError):
            mic.validate_topology(bytes(changed))

    def test_changed_audio_class_is_rejected(self):
        changed = bytearray(configuration())
        changed[32] = 0xFF
        with self.assertRaises(ValueError):
            mic.validate_topology(bytes(changed))

    def test_plan_is_default_and_platform_independent(self):
        process = subprocess.run([sys.executable, str(Path(mic.__file__))],
                                 capture_output=True, text=True, check=True)
        report = json.loads(process.stdout)
        self.assertEqual(report["status"], "planned")
        self.assertEqual(report["apply_transfer"]["payload_hex"], "13")
        self.assertNotIn("device", report)

    def test_native_64_bit_ioctl_abi(self):
        if ctypes.sizeof(ctypes.c_void_p) != 8:
            self.skipTest("64-bit ABI check")
        self.assertEqual(ctypes.sizeof(mic.ControlTransfer), 24)
        self.assertEqual(mic.ControlTransfer.data.offset, 16)
        self.assertEqual(mic.control_ioctl_number(), 0xC0185500)

    def test_execute_refuses_wrong_device_major_and_closes_fd(self):
        device = mic.Device("/sys/example", 3, 5, mic.BOARD, ("card3",))
        with mock.patch.object(mic.sys, "platform", "linux"), \
             mock.patch.object(mic.platform, "machine", return_value="x86_64"), \
             mock.patch.object(mic.os, "geteuid", return_value=0, create=True), \
             mock.patch.object(mic.os, "O_CLOEXEC", 0, create=True), \
             mock.patch.object(mic.os, "O_NOFOLLOW", 0, create=True), \
             mock.patch.object(mic.os, "open", return_value=7), \
             mock.patch.object(mic.os, "fstat", return_value=SimpleNamespace(st_mode=stat.S_IFCHR, st_rdev=1)), \
             mock.patch.object(mic.os, "major", return_value=1, create=True), \
             mock.patch.object(mic.os, "close") as closed, \
             mock.patch.object(mic, "Usbfs") as usb:
            with self.assertRaises(ValueError):
                mic.execute(device, "apply")
            usb.assert_not_called()
            closed.assert_called_once_with(7)

    def test_execute_closes_fd_after_transfer_failure(self):
        device = mic.Device("/sys/example", 3, 5, mic.BOARD, ("card3",))
        with mock.patch.object(mic.sys, "platform", "linux"), \
             mock.patch.object(mic.platform, "machine", return_value="x86_64"), \
             mock.patch.object(mic.os, "geteuid", return_value=0, create=True), \
             mock.patch.object(mic.os, "O_CLOEXEC", 0, create=True), \
             mock.patch.object(mic.os, "O_NOFOLLOW", 0, create=True), \
             mock.patch.object(mic.os, "open", return_value=7), \
             mock.patch.object(mic.os, "fstat", return_value=SimpleNamespace(st_mode=stat.S_IFCHR, st_rdev=1)), \
             mock.patch.object(mic.os, "major", return_value=189, create=True), \
             mock.patch.object(mic.os, "minor", return_value=260, create=True), \
             mock.patch.object(mic.os, "close") as closed, \
             mock.patch.object(mic, "Usbfs"), \
             mock.patch.object(mic, "send_mode", side_effect=OSError("stall")):
            with self.assertRaises(OSError):
                mic.execute(device, "apply")
            closed.assert_called_once_with(7)

    def test_explicit_apply_with_dry_run_never_opens_device(self):
        with mock.patch.object(mic, "discover_device") as discover, \
             mock.patch.object(mic, "execute") as execute, \
             mock.patch("builtins.print"):
            self.assertEqual(mic.main(["apply", "--dry-run"]), 0)
            discover.assert_not_called()
            execute.assert_not_called()


@unittest.skipUnless(sys.platform == "linux", "Real sysfs symlink fixtures run under Linux")
class DiscoveryTests(unittest.TestCase):
    def setUp(self):
        self.directory = tempfile.TemporaryDirectory()
        self.addCleanup(self.directory.cleanup)
        self.root = Path(self.directory.name)
        board = self.root / "class/dmi/id/board_name"
        board.parent.mkdir(parents=True)
        board.write_text(mic.BOARD)
        self.target = self.root / "bus/usb/devices/3-6"
        self.target.mkdir(parents=True)
        for key, value in {"idVendor": "0b05", "idProduct": "1b9b", "bcdDevice": "0013",
                           "busnum": "3", "devnum": "5"}.items():
            (self.target / key).write_text(value)
        (self.target / "descriptors").write_bytes(configuration())
        interface = self.target / "3-6:1.0"
        interface.mkdir()
        (self.target.parent / "3-6:1.0").symlink_to(interface, target_is_directory=True)
        driver = self.root / "bus/usb/drivers/snd-usb-audio"
        driver.mkdir(parents=True)
        (interface / "driver").symlink_to(driver, target_is_directory=True)
        card = self.root / "class/sound/card3"
        card.mkdir(parents=True)
        (card / "device").symlink_to(interface, target_is_directory=True)

    def test_discovery_tracks_dynamic_usb_address_and_card(self):
        device = mic.discover_device(self.root)
        self.assertEqual(device.device_node, "/dev/bus/usb/003/005")
        self.assertEqual(device.alsa_cards, ("card3",))

    def test_different_motherboard_is_rejected(self):
        (self.root / "class/dmi/id/board_name").write_text("ROG STRIX X870-F GAMING WIFI")
        with self.assertRaises(ValueError):
            mic.discover_device(self.root)

    def test_unbound_audio_interface_is_rejected(self):
        (self.target / "3-6:1.0/driver").unlink()
        with self.assertRaises(ValueError):
            mic.discover_device(self.root)

    def test_revision_change_is_rejected(self):
        (self.target / "bcdDevice").write_text("0014")
        with self.assertRaises(ValueError):
            mic.discover_device(self.root)

    def test_duplicate_matching_devices_are_rejected(self):
        other = self.target.parent / "3-7"
        other.mkdir()
        (other / "idVendor").write_text("0b05")
        (other / "idProduct").write_text("1b9b")
        with self.assertRaises(ValueError):
            mic.discover_device(self.root)

    def test_absent_alsa_card_is_rejected(self):
        (self.root / "class/sound/card3/device").unlink()
        with self.assertRaises(ValueError):
            mic.discover_device(self.root)


if __name__ == "__main__":
    unittest.main()

import argparse
import contextlib
import copy
import io
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch
import wave

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import audio_diag as diag


PCM_TEXT = """00-03: HDMI : playback 1
01-00: UVC Camera : capture 1
03-00: USB Audio : playback 1 : capture 1
03-01: USB Audio #1 : playback 1 : capture 1
03-02: USB Audio #2 : playback 1 : capture 1
03-03: USB Audio #3 : playback 1
"""
STREAM_TEXT = """Generic USB Audio : USB Audio

Playback:
  Status: Stop
  Interface 1
    Altset 1
    Format: S32_LE
    Channels: 8
    Rates: 48000

Capture:
  Status: Stop
  Interface 2
    Altset 1
    Format: S16_LE
    Channels: 2
    Rates: 8000
  Interface 2
    Altset 2
    Format: S24_LE
    Channels: 2
    Rates: 48000, 96000
"""
CONTROL_TEXT = """numid=1,iface=CARD,name='Line - Input Jack'
  ; type=BOOLEAN,access=r-------,values=1
  : values=on
numid=2,iface=MIXER,name='PCM Playback Switch'
  ; type=BOOLEAN,access=rw------,values=1
  : values=on
numid=3,iface=MIXER,name='Line Capture Switch'
  ; type=BOOLEAN,access=rw------,values=1
  : values=off
numid=4,iface=MIXER,name='Line Capture Volume'
  ; type=INTEGER,access=rw---R--,values=2,min=0,max=39,step=0
  : values=20,20
  | dBminmax-min=-17.25dB,max=12.00dB
numid=5,iface=MIXER,name='Mic Capture Switch'
  ; type=BOOLEAN,access=rw------,values=1
  : values=on
numid=6,iface=MIXER,name='Mic Capture Volume'
  ; type=INTEGER,access=rw---R--,values=2,min=0,max=39,step=0
  : values=10,10
numid=7,iface=MIXER,name='Analog In Capture Switch'
  ; type=BOOLEAN,access=rw------,values=1
  : values=off
numid=8,iface=MIXER,name='Analog In Capture Volume'
  ; type=INTEGER,access=rw---R--,values=2,min=0,max=39,step=0
  : values=30,30
"""
CARD = {"number": 3, "id": "Audio_1", "usb_id": diag.USB_ID,
        "physical_path": "/sys/devices/usb3/3-6/3-6:1.0", "usb": {}}


class ParsingTests(unittest.TestCase):
    def test_discovers_usb_identity_instead_of_generic_card_name(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for number, usb_id, card_id in ((1, "12d1:4321", "Camera"), (3, diag.USB_ID, "Audio_1")):
                proc = root / "proc" / f"card{number}"
                proc.mkdir(parents=True)
                (proc / "usbid").write_text(usb_id)
                (proc / "id").write_text(card_id)
            card = diag.discover_card(proc_root=root / "proc", sys_root=root / "sys")
            self.assertEqual(card["number"], 3)
            extra = root / "proc/card4"
            extra.mkdir()
            (extra / "usbid").write_text(diag.USB_ID)
            (extra / "id").write_text("Audio_2")
            with self.assertRaises(diag.DiagnosticError):
                diag.discover_card(proc_root=root / "proc", sys_root=root / "sys")
            self.assertEqual(diag.discover_card(3, root / "proc", root / "sys")["id"], "Audio_1")

    def test_wrong_physical_card_is_rejected(self):
        changed = dict(CARD, physical_path="/sys/devices/usb3/3-7/3-7:1.0")
        with patch.object(diag, "discover_card", return_value=changed):
            with self.assertRaises(diag.DiagnosticError):
                diag.verify_card(CARD)

    def test_pcm_discovery_excludes_camera_and_playback_only_device(self):
        self.assertEqual(diag.capture_devices(3, PCM_TEXT), [0, 1, 2])

    def test_capture_format_selection_excludes_playback(self):
        formats = diag.capture_formats(STREAM_TEXT)
        self.assertEqual(formats[0], {"format": "S16_LE", "channels": 2, "rate": 8000})
        self.assertEqual(len(formats), 2)
        self.assertNotIn(8, [setting["channels"] for setting in formats])
        self.assertEqual(diag.capture_formats("Playback:\n  Format: S16_LE"), [])

    def test_continuous_rate_range_is_not_treated_as_two_discrete_rates(self):
        stream = STREAM_TEXT.replace("Rates: 8000", "Rates: 8000 - 96000 (continuous)")
        self.assertEqual(diag.capture_formats(stream)[0]["rate"], 48000)

    def test_capture_control_allowlist_excludes_jacks_and_playback(self):
        switches, volumes, selectors = diag.route_controls(diag.parse_controls(CONTROL_TEXT))
        self.assertEqual([control.numid for control in switches], [3, 5, 7])
        self.assertEqual([control.maximum for control in volumes], [39, 39, 39])
        self.assertEqual(selectors, [])

    def test_indexed_mixer_and_enumerated_selector_are_retained(self):
        text = """numid=9,iface=MIXER,name='Mic Capture Switch',index=1
  ; type=BOOLEAN,access=rw------,values=1
  : values=off
numid=10,iface=MIXER,name='Input Source'
  ; type=ENUMERATED,access=rw------,values=1,items=2
  ; Item #0 'Line'
  ; Item #1 'Mic'
  : values=0
"""
        switches, _, selectors = diag.route_controls(diag.parse_controls(text))
        self.assertEqual(switches[0].index, 1)
        self.assertEqual(selectors[0].name, "Input Source")


class WaveTests(unittest.TestCase):
    def test_channel_analysis_does_not_hide_opposite_phase_speech(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "opposite.wav"
            with wave.open(str(path), "wb") as stream:
                stream.setparams((2, 2, 8000, 0, "NONE", "not compressed"))
                stream.writeframes(b"".join(struct.pack("<hh", value, -value)
                                             for value in ([0] * 16000 + [2000, -2000] * 12000)))
            result = diag.analyze_wav(path)
            self.assertFalse(result["digital_silence"])
            self.assertEqual(result["channels"][0]["initial_silence"]["nonzero_samples"], 0)
            self.assertGreater(result["channels"][0]["speech_window"]["nonzero_samples"], 0)
            self.assertEqual(result["channels"][0]["overall"], result["channels"][1]["overall"])
            solo = Path(directory) / "left.wav"
            diag.solo_channel(path, solo, 0)
            self.assertEqual(len(diag.analyze_wav(solo)["channels"]), 1)

    def test_24_bit_padded_alsa_pcm_is_packed_without_losing_sign(self):
        with tempfile.TemporaryDirectory() as directory:
            raw, wav = Path(directory) / "test.raw", Path(directory) / "test.wav"
            values = [-8388608, -1, 0, 1, 8388607]
            raw.write_bytes(b"".join(struct.pack("<i", value) for value in values))
            diag.raw_to_wav(raw, wav, {"format": "S24_LE", "channels": 1, "rate": 8000})
            with wave.open(str(wav), "rb") as stream:
                self.assertEqual(list(diag.decode_pcm(stream.readframes(5), 3)), values)
            self.assertEqual(diag.analyze_wav(wav)["channels"][0]["overall"]["clipped_samples"], 2)

    def test_incomplete_raw_frame_is_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            raw = Path(directory) / "bad.raw"
            raw.write_bytes(b"\x00\x00\x00")
            with self.assertRaises(diag.DiagnosticError):
                diag.raw_to_wav(raw, Path(directory) / "bad.wav",
                                {"format": "S16_LE", "channels": 2, "rate": 48000})

    def test_truncated_wav_is_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "truncated.wav"
            with wave.open(str(path), "wb") as stream:
                stream.setparams((1, 2, 8000, 0, "NONE", "not compressed"))
                stream.writeframes(b"\x00" * 200)
            path.write_bytes(path.read_bytes()[:-4])
            with self.assertRaises(diag.DiagnosticError):
                diag.analyze_wav(path)


class DecisionTests(unittest.TestCase):
    def results(self, voice, boot="cold", status="ok"):
        return {"boot_condition": boot, "planned_trials": 1, "routes": [{"name": "Line"}],
                "selectors": [], "trials": [{"status": status, "voice_audible": voice}]}

    def test_voice_after_cold_boot_supports_configuration_investigation(self):
        self.assertEqual(diag.decision(self.results(True))["next_step"], "ucm_or_desktop_routing")

    def test_voice_after_windows_requires_cold_confirmation(self):
        self.assertEqual(diag.decision(self.results(True, "windows-warm"))["next_step"],
                         "confirm_capture_after_cold_boot")

    def test_all_reviewed_silent_routes_support_usb_investigation(self):
        self.assertEqual(diag.decision(self.results(False))["next_step"], "investigate_usb_initialization")

    def test_unreviewed_noise_is_not_classified_as_voice(self):
        result = self.results(None)
        result["trials"][0]["analysis"] = {"digital_silence": False}
        self.assertEqual(diag.decision(result)["next_step"], "finish_direct_capture_tests_and_review")

    def test_failed_or_skipped_trials_are_not_classified_as_silence(self):
        self.assertEqual(diag.decision(self.results(False, status="recording-error"))["next_step"],
                         "finish_direct_capture_tests_and_review")
        result = self.results(False)
        result["planned_trials"] = 2
        self.assertEqual(diag.decision(result)["next_step"], "finish_direct_capture_tests_and_review")

    def test_untested_selectors_prevent_a_driver_conclusion(self):
        result = self.results(False)
        result["selectors"] = [{"name": "Input Source"}]
        self.assertEqual(diag.decision(result)["next_step"], "resolve_exposed_capture_controls")
        result["selectors"] = []
        result["untested_controls"] = [{"name": "Mic Boost"}]
        self.assertEqual(diag.decision(result)["next_step"], "resolve_exposed_capture_controls")


class FakeRunner:
    def __init__(self, directory, failure=None):
        self.directory = Path(directory)
        self.calls = []
        self.failure = failure
        self.active = {unit: "active" for unit in diag.UNITS if "pulseaudio" not in unit}
        self.active["pipewire-pulse.service"] = "inactive"
        self.initial_services = copy.deepcopy(self.active)
        self.mixer = {3: "off", 4: "20,20", 5: "on", 6: "10,10", 7: "off", 8: "30,30"}
        self.initial_mixer = copy.deepcopy(self.mixer)
        self.backup = None
        self.record_count = 0

    def run(self, argv, label, timeout=20, required=False):
        argv = [str(value) for value in argv]
        self.calls.append((argv, label))
        result = {"stdout": "", "stderr": "", "status": "ok", "returncode": 0,
                  "log": label + ".txt"}
        if argv[0] == "amixer":
            if argv[-1] == "contents":
                blocks = re_render_controls(self.mixer)
                result["stdout"] = blocks
            elif "cset" in argv:
                numid = int(argv[-2].split("=")[1])
                self.mixer[numid] = argv[-1]
        elif argv[0] == "alsactl":
            if "store" in argv:
                self.backup = copy.deepcopy(self.mixer)
                Path(argv[argv.index("--file") + 1]).write_text("fixture mixer backup")
            elif "restore" in argv:
                if self.failure == "restore":
                    raise diag.DiagnosticError("fixture restore failure")
                self.mixer = copy.deepcopy(self.backup)
        elif argv[0] == "systemctl":
            if "show" in argv:
                unit = argv[argv.index("show") + 1]
                if unit not in self.active:
                    result.update(stdout="LoadState=not-found\nActiveState=inactive\n",
                                  status="error", returncode=1)
                else:
                    result["stdout"] = f"LoadState=loaded\nActiveState={self.active[unit]}\n"
            elif "stop" in argv:
                for unit in argv[argv.index("stop") + 1:]:
                    self.active[unit] = "inactive"
                if self.failure == "stop":
                    raise diag.DiagnosticError("fixture partially completed stop failure")
            elif "start" in argv:
                for unit in argv[argv.index("start") + 1:]:
                    self.active[unit] = "active"
        elif argv[0] == "arecord":
            self.record_count += 1
            if self.failure == "interrupt" and self.record_count == 2:
                raise KeyboardInterrupt
            duration = int(argv[argv.index("--duration") + 1])
            rate = int(argv[argv.index("--rate") + 1])
            channels = int(argv[argv.index("--channels") + 1])
            frames = duration * rate
            if self.failure == "short":
                frames //= 2
            Path(argv[-1]).write_bytes(bytes(frames * channels * 2))
            if self.failure == "record":
                result.update(status="error", returncode=1, stderr="fixture unsupported format")
        return result


def re_render_controls(values):
    blocks = CONTROL_TEXT.split("numid=")
    output = []
    for block in blocks[1:]:
        numid = int(block.split(",", 1)[0])
        if numid in values:
            lines = block.splitlines()
            lines = [("  : values=" + values[numid]) if line.strip().startswith(": values=") else line
                     for line in lines]
            block = "\n".join(lines) + "\n"
        output.append("numid=" + block)
    return "".join(output)


class JackMonitorTests(unittest.TestCase):
    def test_card_id_opens_hardware_control_device_for_monitor(self):
        # Real test_1/test_2 logs returned Invalid CTL for bare "Audio_1".
        # Simulate that distinction rather than accepting every alsactl argv.
        with tempfile.TemporaryDirectory() as directory:
            fake = FakeRunner(directory)
            original_run = fake.run

            def monitor(argv, label, **kwargs):
                result = original_run(argv, label, **kwargs)
                if argv[:2] == ["alsactl", "monitor"]:
                    if argv[2] == "hw:Audio_1":
                        result.update(status="timeout", returncode=-15,
                                      stdout="node hw:Audio_1, #1 Line - Input Jack VALUE\n")
                    else:
                        result.update(status="error", returncode=2,
                                      stderr="Invalid CTL Audio_1\nCannot open ctl Audio_1\n")
                return result

            with patch.object(diag, "require_desktop_linux"), \
                    patch.object(diag, "require_commands"), \
                    patch.object(diag, "discover_card", return_value=CARD), \
                    patch.object(diag, "verify_card", return_value=CARD), \
                    patch.object(diag, "new_run", return_value=Path(directory)), \
                    patch.object(diag, "Runner", return_value=fake), \
                    patch.object(fake, "run", side_effect=monitor), \
                    contextlib.redirect_stdout(io.StringIO()):
                status = diag.jack_test(argparse.Namespace(card=None, output=directory,
                                                          boot="cold", seconds=20))
            self.assertEqual(status, 0)
            self.assertEqual(fake.mixer, fake.initial_mixer)
            self.assertEqual(fake.active, fake.initial_services)


class SessionTests(unittest.TestCase):
    def execute(self, directory, failure=None, dry_run=False):
        run = Path(directory) / "run"
        run.mkdir()
        fake = FakeRunner(run, failure)
        args = argparse.Namespace(card=None, output=directory, boot="cold", seconds=5,
                                  gain="max", dry_run=dry_run, format=None, rate=48000, channels=2)

        def read(path):
            return PCM_TEXT if str(path) == "/proc/asound/pcm" else STREAM_TEXT

        with contextlib.ExitStack() as stack:
            stack.enter_context(patch.object(diag, "require_desktop_linux"))
            stack.enter_context(patch.object(diag, "require_commands"))
            stack.enter_context(patch.object(diag.os, "getuid", return_value=1000, create=True))
            stack.enter_context(patch.object(diag, "discover_card", return_value=CARD))
            stack.enter_context(patch.object(diag, "verify_card", return_value=CARD))
            stack.enter_context(patch.object(diag, "new_run", return_value=run))
            stack.enter_context(patch.object(diag, "Runner", return_value=fake))
            stack.enter_context(patch.object(diag, "read_text", side_effect=read))
            stack.enter_context(patch.object(diag.sys.stdin, "isatty", return_value=True))
            stack.enter_context(patch("builtins.input", return_value=""))
            stack.enter_context(contextlib.redirect_stdout(io.StringIO()))
            stack.enter_context(contextlib.redirect_stderr(io.StringIO()))
            self.fake, self.run = fake, run
            return diag.test_capture(args)

    def test_full_capture_matrix_and_cleanup_preserve_original_state(self):
        with tempfile.TemporaryDirectory() as directory:
            self.assertEqual(self.execute(directory), 0)
            results = json.loads((self.run / "results.json").read_text())
            self.assertEqual(len(results["trials"]), 12)
            self.assertTrue(all(trial["status"] == "ok" for trial in results["trials"]))
            self.assertEqual(self.fake.mixer, self.fake.initial_mixer)
            self.assertEqual(self.fake.active, self.fake.initial_services)
            written_ids = {int(argv[-2].split("=")[1]) for argv, _ in self.fake.calls
                           if argv[0] == "amixer" and "cset" in argv}
            self.assertEqual(written_ids, {3, 4, 5, 6, 7, 8})
            restores = [argv for argv, _ in self.fake.calls if argv[0] == "alsactl" and "restore" in argv]
            self.assertTrue(all("--no-init-fallback" in argv for argv in restores))
            self.assertEqual(results["decision"]["next_step"], "finish_direct_capture_tests_and_review")

    def test_interruption_restores_mixer_and_services(self):
        with tempfile.TemporaryDirectory() as directory:
            with self.assertRaises(KeyboardInterrupt):
                self.execute(directory, "interrupt")
            self.assertEqual(self.fake.mixer, self.fake.initial_mixer)
            self.assertEqual(self.fake.active, self.fake.initial_services)
            self.assertTrue((self.run / "recovery.json").exists())

    def test_partially_failed_service_stop_still_restarts_original_units(self):
        with tempfile.TemporaryDirectory() as directory:
            with self.assertRaises(diag.DiagnosticError):
                self.execute(directory, "stop")
            self.assertEqual(self.fake.active, self.fake.initial_services)
            self.assertEqual(self.fake.mixer, self.fake.initial_mixer)

    def test_mixer_restore_failure_does_not_prevent_service_recovery(self):
        with tempfile.TemporaryDirectory() as directory:
            with self.assertRaises(diag.DiagnosticError):
                self.execute(directory, "restore")
            self.assertEqual(self.fake.active, self.fake.initial_services)
            result = json.loads((self.run / "results.json").read_text())
            self.assertTrue(result["cleanup_errors"])

    def test_capture_errors_do_not_count_as_successful_silence(self):
        with tempfile.TemporaryDirectory() as directory:
            self.assertEqual(self.execute(directory, "record"), 1)
            result = json.loads((self.run / "results.json").read_text())
            self.assertTrue(all(trial["status"] == "recording-error" for trial in result["trials"]))
            self.assertEqual(self.fake.active, self.fake.initial_services)

    def test_short_capture_is_not_valid(self):
        with tempfile.TemporaryDirectory() as directory:
            self.assertEqual(self.execute(directory, "short"), 1)
            result = json.loads((self.run / "results.json").read_text())
            self.assertTrue(all(trial["status"] == "invalid-recording" for trial in result["trials"]))

    def test_dry_run_performs_no_mixer_or_service_mutations(self):
        with tempfile.TemporaryDirectory() as directory:
            self.assertEqual(self.execute(directory, dry_run=True), 0)
            commands = [argv for argv, _ in self.fake.calls]
            self.assertTrue(all(argv[0] == "amixer" and argv[-1] == "contents" for argv in commands))
            self.assertFalse((self.run / "original-mixer.state").exists())

    def test_masked_inactive_pulseaudio_units_do_not_block_pipewire_tests(self):
        with tempfile.TemporaryDirectory() as directory:
            fake = FakeRunner(directory)
            original_run = fake.run

            def masked(argv, label, **kwargs):
                result = original_run(argv, label, **kwargs)
                if argv[0] == "systemctl" and "show" in argv and "pulseaudio" in argv[3]:
                    result.update(status="ok", returncode=0,
                                  stdout="LoadState=masked\nActiveState=inactive\n")
                return result

            with patch.object(fake, "run", side_effect=masked):
                session = diag.ServiceSession(fake)
                session.snapshot()
                session.stop()
                self.assertEqual(session.restore(), [])
            self.assertEqual(fake.active, fake.initial_services)

    def test_unexpected_activation_of_originally_inactive_unit_is_undone(self):
        with tempfile.TemporaryDirectory() as directory:
            fake = FakeRunner(directory)
            session = diag.ServiceSession(fake)
            session.snapshot()
            session.stop()
            fake.active["pipewire-pulse.service"] = "active"
            with self.assertRaises(diag.DiagnosticError):
                session.check_stopped()
            self.assertEqual(session.restore(), [])
            self.assertEqual(fake.active, fake.initial_services)


class RunnerTests(unittest.TestCase):
    def test_timeout_is_retained_and_not_reported_as_success(self):
        with tempfile.TemporaryDirectory() as directory:
            runner = diag.Runner(directory)
            result = runner.run([sys.executable, "-c", "import time; time.sleep(2)"], "timeout", timeout=0.05)
            self.assertEqual(result["status"], "timeout")
            self.assertTrue((Path(directory) / result["log"]).exists())

    def test_reopening_runner_does_not_overwrite_existing_logs(self):
        with tempfile.TemporaryDirectory() as directory:
            first = diag.Runner(directory).run([sys.executable, "-c", "print('original')"], "one")
            second = diag.Runner(directory).run([sys.executable, "-c", "print('later')"], "one")
            self.assertNotEqual(first["log"], second["log"])
            self.assertIn("original", (Path(directory) / first["log"]).read_text())


class ReviewTests(unittest.TestCase):
    def fixture(self, directory):
        run = Path(directory)
        results = {"boot_condition": "cold", "planned_trials": 1, "routes": [{"name": "Line"}],
                   "selectors": [], "seconds": 5, "cleanup_errors": [],
                   "trials": [{"name": "sample", "pcm": "hw:Audio_1,1", "route": "Line", "status": "ok",
                               "wav": "sample.wav", "analysis": {"digital_silence": True, "channels": []}}]}
        diag.save_json(run / "results.json", results)
        return argparse.Namespace(run=run, no_play=False, again=False, target="usb-headset-sink")

    def test_failed_listening_check_does_not_create_a_no_voice_review(self):
        with tempfile.TemporaryDirectory() as directory:
            args = self.fixture(directory)
            fake = FakeRunner(directory)
            with patch.object(diag.shutil, "which", return_value="/usr/bin/pw-play"), \
                    patch.object(diag, "Runner", return_value=fake), \
                    patch("builtins.input", return_value="n"), \
                    contextlib.redirect_stdout(io.StringIO()):
                with self.assertRaises(diag.DiagnosticError):
                    diag.review(args)
            results = json.loads((Path(directory) / "results.json").read_text())
            self.assertNotIn("voice_audible", results["trials"][0])
            self.assertEqual(fake.calls[0][0][1:3], ["--target", "usb-headset-sink"])

    def test_playback_failure_keeps_a_recording_unreviewed(self):
        with tempfile.TemporaryDirectory() as directory:
            args = self.fixture(directory)
            fake = FakeRunner(directory)
            original_run = fake.run

            def fail_playback(argv, label, **kwargs):
                result = original_run(argv, label, **kwargs)
                if label.startswith("listen-"):
                    result.update(status="error", returncode=1)
                return result

            with patch.object(diag.shutil, "which", return_value="/usr/bin/pw-play"), \
                    patch.object(diag, "Runner", return_value=fake), \
                    patch.object(fake, "run", side_effect=fail_playback), \
                    patch("builtins.input", return_value="y"), \
                    contextlib.redirect_stdout(io.StringIO()):
                self.assertEqual(diag.review(args), 0)
            results = json.loads((Path(directory) / "results.json").read_text())
            self.assertNotIn("voice_audible", results["trials"][0])
            self.assertEqual(results["decision"]["next_step"], "finish_direct_capture_tests_and_review")


if __name__ == "__main__":
    unittest.main()

#!/usr/bin/env python3
"""Local ALSA diagnostics for ASUS USB audio, using Python's standard library."""

import argparse
from array import array
from contextlib import contextmanager
from dataclasses import asdict, dataclass
from datetime import datetime, timezone
import hashlib
import json
import math
import os
from pathlib import Path
import re
import shlex
import shutil
import signal
import subprocess
import sys
import time
import wave


USB_ID = "0b05:1b9b"
UNITS = (
    "pipewire-pulse.socket", "pipewire.socket", "pulseaudio.socket",
    "wireplumber.service", "pipewire-pulse.service", "pipewire.service",
    "pulseaudio.service",
)
CAPTURE_NAMES = ("Analog In", "Line", "Mic")
FORMATS = {"S16_LE": (2, 2), "S32_LE": (4, 4),
           "S24_3LE": (3, 3), "S24_LE": (4, 3)}


class DiagnosticError(Exception):
    pass


def utc_now():
    return datetime.now(timezone.utc).isoformat()


def save_json(path, value):
    path = Path(path)
    temporary = path.with_name(path.name + ".tmp")
    temporary.write_text(json.dumps(value, indent=2) + "\n", encoding="utf-8")
    temporary.replace(path)


def new_run(parent, kind):
    parent = Path(parent).expanduser().resolve()
    parent.mkdir(parents=True, exist_ok=True)
    stamp = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S.%fZ")
    run = parent / (stamp + "-" + kind)
    run.mkdir(mode=0o700)
    return run


def require_desktop_linux():
    if sys.platform != "linux":
        raise DiagnosticError("Run collect/jacks/test/restore on the actual Ubuntu desktop.")
    if os.geteuid() == 0:
        raise DiagnosticError("Run as your desktop user, without sudo, so the correct user audio session is used.")


def require_commands(*names):
    missing = [name for name in names if shutil.which(name) is None]
    if missing:
        raise DiagnosticError("Missing commands: " + ", ".join(missing))


class Runner:
    """Execute argv without a shell and retain errors, timeouts, and command provenance."""

    def __init__(self, directory):
        self.directory = Path(directory)
        self.sequence = max((int(path.name.split("-", 1)[0])
                             for path in self.directory.glob("[0-9]*-*.txt")
                             if path.name.split("-", 1)[0].isdigit()), default=0)

    def run(self, argv, label, timeout=20, required=False):
        argv = [str(arg) for arg in argv]
        self.sequence += 1
        safe_label = re.sub(r"[^A-Za-z0-9_.-]", "-", label)
        logfile = self.directory / f"{self.sequence:03d}-{safe_label}.txt"
        result = {"argv": argv, "started": utc_now(), "returncode": None,
                  "status": "ok", "log": logfile.name}
        start = time.monotonic()
        output, errors = "", ""
        process = None
        interrupted = False
        try:
            env = os.environ.copy()
            env["LC_ALL"] = "C"
            process = subprocess.Popen(argv, stdout=subprocess.PIPE,
                                       stderr=subprocess.PIPE, text=True,
                                       errors="replace", env=env)
            output, errors = process.communicate(timeout=timeout)
            result["returncode"] = process.returncode
            if process.returncode:
                result["status"] = "error"
        except FileNotFoundError as exc:
            result.update(status="missing", returncode=127)
            errors = str(exc)
        except (subprocess.TimeoutExpired, KeyboardInterrupt) as exc:
            interrupted = isinstance(exc, KeyboardInterrupt)
            result["status"] = "interrupted" if interrupted else "timeout"
            if process is not None:
                process.terminate()
                try:
                    output, errors = process.communicate(timeout=3)
                except subprocess.TimeoutExpired:
                    process.kill()
                    output, errors = process.communicate()
                result["returncode"] = process.returncode
        except OSError as exc:
            result["status"] = "error"
            errors = str(exc)
        finally:
            result["elapsed_seconds"] = round(time.monotonic() - start, 3)
            logfile.write_text("$ " + shlex.join(argv) + "\n\nSTDOUT\n" + output
                               + "\nSTDERR\n" + errors + "\n", encoding="utf-8")
            with (self.directory / "commands.jsonl").open("a", encoding="utf-8") as stream:
                stream.write(json.dumps(result) + "\n")
        result.update(stdout=output, stderr=errors)
        if interrupted:
            raise KeyboardInterrupt
        if required and result["status"] != "ok":
            raise DiagnosticError(f"{label} failed; see {logfile}")
        return result


def read_text(path):
    return Path(path).read_text(encoding="utf-8", errors="replace").strip()


def discover_card(card_number=None, proc_root=Path("/proc/asound"),
                  sys_root=Path("/sys/class/sound")):
    matches = []
    for path in sorted(Path(proc_root).glob("card[0-9]*")):
        try:
            number = int(path.name[4:])
            usbid = read_text(path / "usbid").lower()
            card_id = read_text(path / "id")
        except (OSError, ValueError):
            continue
        if usbid != USB_ID or (card_number is not None and number != card_number):
            continue
        physical = (Path(sys_root) / path.name / "device").resolve()
        attributes = {}
        for parent in (physical, *physical.parents):
            try:
                identity = read_text(parent / "idVendor") + ":" + read_text(parent / "idProduct")
            except OSError:
                continue
            if identity.lower() == USB_ID:
                for name in ("bcdDevice", "busnum", "devnum", "product", "manufacturer"):
                    try:
                        attributes[name] = read_text(parent / name)
                    except OSError:
                        pass
                attributes["usb_sysfs_path"] = str(parent)
                break
        matches.append({"number": number, "id": card_id, "usb_id": usbid,
                        "physical_path": str(physical), "usb": attributes})
    if len(matches) != 1:
        raise DiagnosticError(f"Expected exactly one ALSA card for {USB_ID}; found {len(matches)}. "
                              "Check /proc/asound/card*/usbid and use --card if necessary.")
    return matches[0]


def verify_card(original):
    current = discover_card(original["number"])
    if any(current[key] != original[key] for key in ("id", "usb_id", "physical_path")):
        raise DiagnosticError("The target card changed during testing; refusing mixer writes.")
    return current


def capture_devices(card_number, pcm_text):
    devices = []
    for line in pcm_text.splitlines():
        match = re.match(r"\s*(\d+)-(\d+):", line)
        if match and int(match[1]) == card_number and re.search(r"\bcapture\s+[1-9]\d*", line):
            devices.append(int(match[2]))
    return sorted(set(devices))


def capture_formats(stream_text):
    """Read advertised capture altsettings, excluding playback and active status."""
    section = stream_text.split("Capture:", 1)
    if len(section) != 2:
        return []
    section = section[1].split("Playback:", 1)[0]
    settings = []
    for block in re.split(r"\n\s*Interface \d+", section):
        if not re.search(r"\bAltset\s+\d+", block):
            continue
        fmt = re.search(r"^\s*Format:\s*(\S+)", block, re.M)
        channels = re.search(r"^\s*Channels:\s*(\d+)", block, re.M)
        rates = re.search(r"^\s*Rates:\s*(.+)", block, re.M)
        if not (fmt and channels and rates) or fmt[1] not in FORMATS:
            continue
        rate_text = rates[1]
        if "continuous" in rate_text.lower() or "-" in rate_text:
            endpoints = [int(value) for value in re.findall(r"\d+", rate_text)]
            if len(endpoints) != 2:
                continue
            lo, hi = endpoints
            rate = next((value for value in (48000, 44100) if lo <= value <= hi), lo)
        else:
            available = [int(value) for value in re.findall(r"\d+", rate_text)]
            if not available:
                continue
            rate = next((value for value in (48000, 44100) if value in available), available[0])
        settings.append({"format": fmt[1], "channels": int(channels[1]), "rate": rate})
    preference = {fmt: index for index, fmt in enumerate(FORMATS)}
    return sorted(settings, key=lambda value: (value["channels"] != 2,
                                               preference[value["format"]],
                                               value["rate"] != 48000))


@dataclass
class Control:
    numid: int
    name: str
    index: int
    iface: str
    type: str
    access: str
    count: int
    minimum: int | None
    maximum: int | None
    values: str

    @property
    def writable(self):
        return "w" in self.access


def parse_controls(contents):
    controls = []
    for block in re.split(r"(?=^numid=)", contents, flags=re.M):
        header = re.match(r"numid=(\d+),iface=([^,\n]+),name='(.*?)'([^\n]*)", block)
        info = re.search(r"type=(\w+),access=([^,\s]+),values=(\d+)", block)
        if not (header and info):
            continue
        index = re.search(r"(?:^|,)index=(\d+)", header[4])
        minimum = re.search(r"(?:^|,)min=(-?\d+)", block, re.M)
        maximum = re.search(r"(?:^|,)max=(-?\d+)", block, re.M)
        values = re.search(r"^\s*: values=(.*)", block, re.M)
        controls.append(Control(int(header[1]), header[3], int(index[1]) if index else 0,
                                header[2], info[1], info[2], int(info[3]),
                                int(minimum[1]) if minimum else None,
                                int(maximum[1]) if maximum else None,
                                values[1].strip() if values else ""))
    return controls


def route_controls(controls):
    switches = [control for control in controls
                if control.iface == "MIXER" and control.writable and control.type == "BOOLEAN"
                and control.name in {name + " Capture Switch" for name in CAPTURE_NAMES}]
    volumes = [control for control in controls
               if control.iface == "MIXER" and control.writable and control.type == "INTEGER"
               and control.name in {name + " Capture Volume" for name in CAPTURE_NAMES}]
    selectors = [control for control in controls if control.iface == "MIXER"
                 and control.writable and control.type == "ENUMERATED"
                 and re.search(r"capture|input|mic", control.name, re.I)]
    return switches, volumes, selectors


def file_snapshot(run, source, destination):
    source, destination = Path(source), Path(run) / destination
    try:
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(source.read_bytes())
        return {"source": str(source), "copy": str(destination.relative_to(run)), "status": "ok",
                "sha256": hashlib.sha256(destination.read_bytes()).hexdigest()}
    except OSError as exc:
        return {"source": str(source), "status": "unavailable", "error": str(exc)}


def collect(args):
    require_desktop_linux()
    card = discover_card(args.card)
    run = new_run(args.output, "collect")
    runner = Runner(run)
    metadata = {"created": utc_now(), "boot_condition": args.boot, "card": card,
                "uid": os.getuid(), "kind": "collect", "files": []}
    save_json(run / "metadata.json", metadata)
    print(f"Collecting card {card['number']} ({card['id']}, {USB_ID}) into {run}", flush=True)
    commands = [
        (["uname", "-a"], "kernel"),
        (["dpkg-query", "-W", "alsa-ucm-conf", "libasound2t64", "alsa-utils", "pipewire", "wireplumber"], "packages"),
        (["lsusb"], "usb-list"), (["lsusb", "-t"], "usb-topology"),
        (["lsusb", "-v", "-d", USB_ID], "usb-descriptors"),
        (["aplay", "-l"], "playback-devices"), (["arecord", "-l"], "capture-devices"),
        (["aplay", "-L"], "playback-pcms"), (["arecord", "-L"], "capture-pcms"),
        (["amixer", "-c", card["id"], "contents"], "mixer-before-ucm-query"),
        (["amixer", "-c", card["id"], "scontents"], "simple-mixer"),
        (["alsaucm", "-c", "hw:" + card["id"], "dump", "text"], "ucm-dump"),
        (["amixer", "-c", card["id"], "contents"], "mixer-after-ucm-query"),
        (["wpctl", "status"], "wireplumber"), (["pactl", "list", "cards"], "pipewire-cards"),
        (["pactl", "list", "sources"], "pipewire-sources"),
        (["systemctl", "--user", "list-units", "--all", "--no-pager", "pipewire*", "wireplumber*", "pulseaudio*"], "audio-services"),
        (["journalctl", "--user", "-b", "--no-pager", "-n", "150", "-u", "wireplumber", "-u", "pipewire", "-u", "pipewire-pulse"], "audio-journal"),
        (["journalctl", "-k", "-b", "--no-pager", "-n", "200", "-g", "snd|audio|usb 3-6"], "kernel-journal"),
    ]
    for argv, label in commands:
        result = runner.run(argv, label)
        if result["status"] != "ok":
            print(f"  {label}: {result['status']} (retained in log)", flush=True)
    sources = [Path("/etc/os-release"), Path("/proc/asound/cards"), Path("/proc/asound/pcm")]
    for name in ("id", "usbid", "usbmixer"):
        sources.append(Path(f"/proc/asound/card{card['number']}") / name)
    sources.extend(sorted(Path(f"/proc/asound/card{card['number']}").glob("stream*")))
    for name in ("board_vendor", "board_name", "board_version", "bios_vendor", "bios_version", "bios_date"):
        sources.append(Path("/sys/class/dmi/id") / name)
    for source in sources:
        metadata["files"].append(file_snapshot(run, source, "files/" + str(source).lstrip("/")))
    ucm = Path("/usr/share/alsa/ucm2")
    config_sources = [ucm / "USB-Audio/USB-Audio.conf"]
    config_sources.extend(sorted((ucm / "USB-Audio/Realtek").glob("ALC4080*.conf")))
    config_sources.extend(sorted((ucm / "USB-Audio/conf.d").glob("*1b9b*")))
    config_sources.extend(sorted((ucm / "conf.d/USB-Audio").glob("*.conf")))
    config_sources.extend([Path("/etc/asound.conf"), Path.home() / ".asoundrc"])
    for base in (Path("/etc/pipewire"), Path("/etc/wireplumber"),
                 Path.home() / ".config/pipewire", Path.home() / ".config/wireplumber"):
        if base.exists():
            config_sources.extend(sorted(path for path in base.rglob("*") if path.is_file()))
    for source in config_sources:
        metadata["files"].append(file_snapshot(run, source, "config/" + str(source).lstrip("/")))
    save_json(run / "metadata.json", metadata)
    (run / "NEXT.txt").write_text(
        "HiFi/source enumeration alone cannot distinguish UCM routing from missing initialization.\n"
        "Next: run audio_diag.py test with the same wiring and record boot provenance.\n"
        "No packages, profiles, services, or mixer controls were deliberately changed by collect.\n"
        "The UCM query is bracketed by mixer snapshots because opening a UCM profile can initialize controls.\n",
        encoding="utf-8")
    print(f"Saved: {run}\nOptional permission errors are logged; do not rerun the whole tool with sudo.")
    return 0


def jack_test(args):
    require_desktop_linux()
    require_commands("amixer", "alsactl")
    card = discover_card(args.card)
    run = new_run(args.output, "jacks")
    runner = Runner(run)
    save_json(run / "metadata.json", {"created": utc_now(), "card": card, "boot_condition": args.boot})
    runner.run(["amixer", "-c", card["id"], "contents"], "jack-before", required=True)
    print(f"For {args.seconds} seconds, unplug and reinsert ONLY the rear microphone plug.\n"
          "Leave the headphone plug connected. This records events without changing controls.", flush=True)
    # Unlike alsactl store/restore, monitor takes an ALSA control device name.
    result = runner.run(["alsactl", "monitor", "hw:" + card["id"]],
                        "jack-events", timeout=args.seconds)
    verify_card(card)
    runner.run(["amixer", "-c", card["id"], "contents"], "jack-after", required=True)
    if result["status"] not in ("ok", "timeout"):
        print(f"Jack event monitor failed ({result['status']}); see {run / result['log']}.")
        return 1
    print(f"Saved: {run} (the monitor timeout is expected)")
    return 0


class ServiceSession:
    def __init__(self, runner):
        self.runner = runner
        self.original = {}
        self.touched = False

    def state(self, unit):
        result = self.runner.run(["systemctl", "--user", "show", unit,
                                  "--property=LoadState", "--property=ActiveState"], "state-" + unit)
        fields = dict(line.split("=", 1) for line in result["stdout"].splitlines() if "=" in line)
        if result["status"] != "ok" and fields.get("LoadState") != "not-found":
            raise DiagnosticError("Could not inspect the desktop audio services; see systemctl log.")
        return fields

    def snapshot(self):
        for unit in UNITS:
            state = self.state(unit)
            if state.get("LoadState") == "not-found" or (
                    state.get("LoadState") == "masked" and state.get("ActiveState") in ("inactive", "failed")):
                continue
            if state.get("LoadState") != "loaded":
                raise DiagnosticError(f"Unexpected unit load state for {unit}: {state}")
            if state.get("ActiveState") not in ("active", "inactive", "failed"):
                raise DiagnosticError(f"Wait for {unit} to finish its current transition, then retry.")
            self.original[unit] = state["ActiveState"]

    def stop(self):
        active = [unit for unit, state in self.original.items() if state == "active"]
        if active:
            self.touched = True
            self.runner.run(["systemctl", "--user", "stop", *active], "stop-audio", timeout=30, required=True)
        self.check_stopped()

    def check_stopped(self):
        for unit in self.original:
            if self.state(unit).get("ActiveState") not in ("inactive", "failed"):
                raise DiagnosticError(f"{unit} reactivated. Close audio applications before testing.")

    def restore(self):
        if not self.touched:
            return []
        errors = []
        active = [unit for unit, state in self.original.items() if state == "active"]
        # A client may explicitly reactivate a service even after its socket is stopped.
        # Remove those extra activations before restoring the original active set.
        extra = []
        for unit, initial in self.original.items():
            if initial == "active":
                continue
            try:
                if self.state(unit).get("ActiveState") not in ("inactive", "failed"):
                    extra.append(unit)
            except DiagnosticError as exc:
                errors.append(str(exc))
        if extra:
            stopped = self.runner.run(["systemctl", "--user", "stop", *extra],
                                      "stop-unexpected-activations", timeout=30)
            if stopped["status"] != "ok":
                errors.append("Could not stop unexpectedly activated audio units.")
        result = self.runner.run(["systemctl", "--user", "start", *active], "restore-audio", timeout=30)
        if result["status"] != "ok":
            errors.append("Could not restart all previously active audio units.")
        for unit, initial in self.original.items():
            try:
                current = self.state(unit).get("ActiveState")
                if initial == "active" and current != "active":
                    errors.append(f"{unit} did not return to active state.")
                elif initial != "active" and current not in ("inactive", "failed"):
                    errors.append(f"{unit} became active despite originally being {initial}.")
            except DiagnosticError as exc:
                errors.append(str(exc))
        return errors


def restore_mixer(runner, card, backup):
    verify_card(card)
    return runner.run(["alsactl", "--no-init-fallback", "--file", backup,
                       "restore", card["id"]], "restore-mixer", required=True)


@contextmanager
def cleanup_signals():
    previous = {}
    for name in ("SIGINT", "SIGTERM"):
        sig = getattr(signal, name, None)
        if sig is not None:
            previous[sig] = signal.signal(sig, signal.SIG_IGN)
    try:
        yield
    finally:
        for sig, handler in previous.items():
            signal.signal(sig, handler)


def cleanup_session(runner, card, backup, services, saved):
    errors = []
    with cleanup_signals():
        if saved:
            try:
                restore_mixer(runner, card, backup)
            except (DiagnosticError, OSError) as exc:
                errors.append(str(exc))
        # Restart services even when mixer restoration fails.
        errors.extend(services.restore())
    return errors


def raw_to_wav(raw_path, wav_path, setting):
    physical, packed = FORMATS[setting["format"]]
    raw = Path(raw_path).read_bytes()
    frame_bytes = physical * setting["channels"]
    if len(raw) % frame_bytes:
        raise DiagnosticError("Raw recording ends with an incomplete sample frame.")
    if setting["format"] == "S24_LE":
        # ALSA S24_LE stores a signed 24-bit value in the low bytes of a 32-bit word.
        raw = b"".join(raw[offset:offset + 3] for offset in range(0, len(raw), 4))
    with wave.open(str(wav_path), "wb") as stream:
        stream.setnchannels(setting["channels"])
        stream.setsampwidth(packed)
        stream.setframerate(setting["rate"])
        stream.writeframes(raw)


def decode_pcm(data, width):
    if width == 1:
        return [value - 128 for value in data]
    if width in (2, 4):
        values = array("h" if width == 2 else "i")
        values.frombytes(data)
        if sys.byteorder != "little":
            values.byteswap()
        return values
    if width == 3:
        return [int.from_bytes(data[offset:offset + 3], "little", signed=True)
                for offset in range(0, len(data), 3)]
    raise DiagnosticError(f"Unsupported PCM sample width: {width}")


def level(values, scale):
    if not values:
        return {"rms_dbfs": None, "peak_dbfs": None, "nonzero_samples": 0,
                "clipped_samples": 0}
    rms = math.sqrt(sum(value * value for value in values) / len(values)) / scale
    peak = max(abs(value) for value in values) / scale
    return {"rms_dbfs": round(20 * math.log10(rms), 2) if rms else None,
            "peak_dbfs": round(20 * math.log10(peak), 2) if peak else None,
            "nonzero_samples": sum(value != 0 for value in values),
            "clipped_samples": sum(abs(value) >= scale - 1 for value in values)}


def analyze_wav(path, silence_seconds=2):
    with wave.open(str(path), "rb") as stream:
        channels, width, rate = stream.getnchannels(), stream.getsampwidth(), stream.getframerate()
        frames = stream.getnframes()
        data = stream.readframes(frames)
    if len(data) != frames * channels * width:
        raise DiagnosticError("WAV is truncated; it is not a valid completed capture.")
    values = decode_pcm(data, width)
    scale = 2 ** (width * 8 - 1)
    result = {"frames": frames, "duration_seconds": frames / rate,
              "rate": rate, "channels": [], "sample_width": width}
    for channel in range(channels):
        samples = values[channel::channels]
        split = min(len(samples), int(silence_seconds * rate))
        result["channels"].append({"channel": channel + 1,
                                   "overall": level(samples, scale),
                                   "initial_silence": level(samples[:split], scale),
                                   "speech_window": level(samples[split:], scale)})
    result["digital_silence"] = all(item["overall"]["nonzero_samples"] == 0 for item in result["channels"])
    return result


def decision(results):
    trials = results.get("trials", [])
    valid = [trial for trial in trials if trial.get("status") == "ok"]
    heard = [trial for trial in valid if trial.get("voice_audible") is True]
    if heard:
        if results.get("boot_condition") != "cold":
            return {"next_step": "confirm_capture_after_cold_boot",
                    "reason": "Voice is confirmed in a hardware recording, but cold-boot behavior is not established. "
                              "UCM/routing is a candidate; retained Windows initialization must be excluded."}
        return {"next_step": "ucm_or_desktop_routing",
                "reason": "Voice is confirmed in a direct hardware recording after a cold boot. "
                          "Use the recorded PCM and mixer state to investigate UCM/desktop routing."}
    complete = len(trials) == results.get("planned_trials") and bool(trials) and len(valid) == len(trials)
    if complete and all(trial.get("voice_audible") is False for trial in valid):
        if results.get("selectors") or results.get("untested_controls") or not results.get("routes"):
            return {"next_step": "resolve_exposed_capture_controls",
                    "reason": "Voice was not heard, but selectors or unrecognized routing controls still need inspection."}
        if results.get("boot_condition") != "cold":
            return {"next_step": "repeat_after_cold_boot",
                    "reason": "The tested capture routes carry no reviewed voice; establish a cold-boot baseline before USB analysis."}
        return {"next_step": "investigate_usb_initialization",
                "reason": "All completed baseline and known capture-route recordings were reviewed without voice after a cold boot. "
                          "Compare Windows/Linux initialization, retaining the descriptors and mixer topology."}
    return {"next_step": "finish_direct_capture_tests_and_review",
            "reason": "Enumeration or signal level alone does not identify microphone speech. "
                      "Resolve failed/skipped captures and listen to the recordings before choosing a patch."}


def write_results(run, results):
    results["decision"] = decision(results)
    save_json(Path(run) / "results.json", results)
    lines = ["# Direct ALSA capture results", "", f"Boot condition: {results['boot_condition']}", "",
             "| Test | PCM | Route | Status | Digital silence | Voice heard |",
             "|---|---|---|---|---|---|"]
    for trial in results["trials"]:
        silent = trial.get("analysis", {}).get("digital_silence", "unknown")
        lines.append(f"| {trial['name']} | {trial['pcm']} | {trial['route']} | {trial['status']} | "
                     f"{silent} | {trial.get('voice_audible', 'unreviewed')} |")
    lines += ["", "Next step: **" + results["decision"]["next_step"] + "**", "",
              results["decision"]["reason"], "", "Restoration errors: " + str(results.get("cleanup_errors", [])), ""]
    (Path(run) / "SUMMARY.md").write_text("\n".join(lines), encoding="utf-8")


def test_capture(args):
    require_desktop_linux()
    require_commands("amixer", "alsactl", "arecord", "systemctl")
    if not args.dry_run and not sys.stdin.isatty():
        raise DiagnosticError("The recording test is interactive. Run it in an Ubuntu terminal.")
    card = discover_card(args.card)
    devices = capture_devices(card["number"], read_text("/proc/asound/pcm"))
    if not devices:
        raise DiagnosticError("The verified card exposes no capture PCMs.")
    run = new_run(args.output, "test")
    runner = Runner(run)
    contents = runner.run(["amixer", "-c", card["id"], "contents"], "initial-mixer", required=True)
    controls = parse_controls(contents["stdout"])
    switches, volumes, selectors = route_controls(controls)
    known = {control.numid for control in switches + volumes}
    untested = [control for control in controls if control.writable and control.iface == "MIXER"
                and control.numid not in known and re.search(r"capture|input|mic", control.name, re.I)]
    results = {"created": utc_now(), "card": card, "boot_condition": args.boot,
               "routes": [asdict(control) for control in switches],
               "selectors": [asdict(control) for control in selectors],
               "untested_controls": [asdict(control) for control in untested],
               "controls": [asdict(control) for control in controls],
               "gain": args.gain, "seconds": args.seconds, "trials": [], "planned_trials": 0,
               "cleanup_errors": [], "dry_run": args.dry_run}
    settings = {}
    for device in devices:
        try:
            stream = read_text(f"/proc/asound/card{card['number']}/stream{device}")
        except OSError:
            stream = ""
        (run / f"stream{device}.txt").write_text(stream + "\n", encoding="utf-8")
        available = capture_formats(stream)
        if args.format:
            settings[device] = {"format": args.format, "channels": args.channels, "rate": args.rate}
        else:
            settings[device] = available[0] if available else None
    plan = [(device, None) for device in devices]
    plan += [(device, switch) for switch in switches for device in devices]
    results["planned_trials"] = len(plan)
    results["settings"] = settings
    save_json(run / "plan.json", results)
    print(f"Target: card {card['number']} ({card['id']}, {USB_ID})\n"
          f"Plan: {len(plan)} recordings, {args.seconds} seconds each. Capture gain: {args.gain}.\n"
          "First record the original mixer state on each PCM, then each recognized capture switch separately.\n"
          f"Artifacts: {run}", flush=True)
    if untested:
        print("Additional capture controls will be logged for inspection without guessing their values.", flush=True)
    if args.dry_run:
        print("Dry run complete. No mixer settings or services changed.")
        return 0
    if any(setting is None for setting in settings.values()):
        raise DiagnosticError(f"Cannot choose advertised formats for every PCM. Inspect {run}/stream*.txt; "
                              "then supply --format, --rate, and --channels explicitly if needed.")
    input("Close audio applications. Keep the splitter connected and lower the mic boom. Press Enter to begin: ")
    services = ServiceSession(runner)
    services.snapshot()
    backup = run / "original-mixer.state"
    saved = False
    recovery = {"uid": os.getuid(), "card": card, "original_services": services.original,
                "saved": False, "services_touched": False, "cleanup_complete": False}
    save_json(run / "recovery.json", recovery)
    try:
        verify_card(card)
        runner.run(["alsactl", "--file", backup, "store", card["id"]], "save-mixer", required=True)
        if not backup.is_file() or backup.stat().st_size == 0:
            raise DiagnosticError("Mixer backup was not saved; no audio services have been stopped.")
        saved = recovery["saved"] = True
        # Persist recovery intent before an interruptible stop operation.
        recovery["services_touched"] = any(state == "active" for state in services.original.values())
        save_json(run / "recovery.json", recovery)
        services.stop()
        for index, (device, switch) in enumerate(plan, 1):
            services.check_stopped()
            verify_card(card)
            restore_mixer(runner, card, backup)
            route = "original-state" if switch is None else f"{switch.name} index={switch.index}"
            name = f"{index:02d}-pcm{device}-" + ("original" if switch is None else f"switch{switch.numid}-{args.gain}")
            trial = {"name": name, "pcm": f"hw:{card['id']},{device}", "device": device,
                     "route": route, "status": "pending", "setting": settings[device],
                     "wav": name + ".wav", "raw": name + ".raw"}
            results["trials"].append(trial)
            write_results(run, results)
            if switch is not None:
                for candidate in switches:
                    value = "on" if candidate.numid == switch.numid else "off"
                    runner.run(["amixer", "-c", card["id"], "cset", f"numid={candidate.numid}",
                                ",".join([value] * candidate.count)], "set-capture-switch", required=True)
                if args.gain == "max":
                    volume_name = switch.name.removesuffix("Switch") + "Volume"
                    for volume in volumes:
                        if (volume.name == volume_name and volume.index == switch.index
                                and volume.maximum is not None):
                            runner.run(["amixer", "-c", card["id"], "cset", f"numid={volume.numid}",
                                        ",".join([str(volume.maximum)] * volume.count)],
                                       "set-capture-gain", required=True)
            before = runner.run(["amixer", "-c", card["id"], "contents"], name + "-mixer", required=True)
            trial["mixer_log"] = before["log"]
            print(f"\n[{index}/{len(plan)}] {trial['pcm']} / {route}", flush=True)
            input(f"Press Enter to record. Stay silent for 2 seconds, then speak until {args.seconds} seconds have passed: ")
            setting = settings[device]
            argv = ["arecord", "--device", trial["pcm"], "--file-type", "raw", "--format", setting["format"],
                    "--rate", setting["rate"], "--channels", setting["channels"], "--duration", args.seconds,
                    "--dump-hw-params", "--fatal-errors", run / trial["raw"]]
            print("Recording now: silence for 2 seconds, then say 'rear headset microphone test' repeatedly.", flush=True)
            verify_card(card)
            result = runner.run(argv, name + "-arecord", timeout=args.seconds + 10)
            trial["record_log"] = result["log"]
            if result["status"] != "ok" or "rate is not accurate" in result["stderr"].lower():
                trial["status"] = "recording-error"
                trial["error"] = result["stderr"]
                print("Recording failed. The error is retained; it will not count as silence.", flush=True)
            else:
                try:
                    raw_to_wav(run / trial["raw"], run / trial["wav"], setting)
                    trial["analysis"] = analyze_wav(run / trial["wav"])
                    if abs(trial["analysis"]["duration_seconds"] - args.seconds) > 0.25:
                        raise DiagnosticError("Recording duration differs from the requested duration.")
                    trial["status"] = "ok"
                    print("Recording complete. Digital silence: " + str(trial["analysis"]["digital_silence"]), flush=True)
                except (DiagnosticError, OSError, wave.Error) as exc:
                    trial.update(status="invalid-recording", error=str(exc))
            write_results(run, results)
        results["finished"] = utc_now()
    finally:
        print("\nRestoring the mixer and original audio services...", flush=True)
        errors = cleanup_session(runner, card, backup, services, saved)
        results["cleanup_errors"] = errors
        recovery["cleanup_complete"] = not errors
        recovery["cleanup_errors"] = errors
        save_json(run / "recovery.json", recovery)
        write_results(run, results)
        if errors:
            print("Restoration needs attention: " + "; ".join(errors), file=sys.stderr)
            print(f"Recovery: python3 audio_diag.py restore {shlex.quote(str(run))}", file=sys.stderr)
        else:
            print("Original mixer and previously active services restored.", flush=True)
    print(f"Saved: {run}\nNext: python3 audio_diag.py review {shlex.quote(str(run))}")
    return 1 if results["cleanup_errors"] or any(trial["status"] != "ok" for trial in results["trials"]) else 0


def manual_restore(args):
    require_desktop_linux()
    require_commands("systemctl", "alsactl")
    run = Path(args.run).expanduser().resolve()
    recovery = json.loads((run / "recovery.json").read_text(encoding="utf-8"))
    if recovery["uid"] != os.getuid() or recovery["card"]["usb_id"] != USB_ID:
        raise DiagnosticError("Recovery belongs to a different user or device.")
    if any(unit not in UNITS or state not in ("active", "inactive", "failed")
           for unit, state in recovery["original_services"].items()):
        raise DiagnosticError("Recovery contains unexpected service names or states.")
    services = ServiceSession(Runner(run))
    services.original = recovery["original_services"]
    services.touched = recovery["services_touched"]
    errors = cleanup_session(services.runner, recovery["card"], run / "original-mixer.state",
                             services, recovery["saved"])
    recovery.update(cleanup_complete=not errors, cleanup_errors=errors)
    save_json(run / "recovery.json", recovery)
    print("Restoration complete." if not errors else "Restoration errors: " + "; ".join(errors))
    return bool(errors)


def solo_channel(source, destination, channel):
    with wave.open(str(source), "rb") as stream:
        channels, width, rate = stream.getnchannels(), stream.getsampwidth(), stream.getframerate()
        data = stream.readframes(stream.getnframes())
    if channel >= channels:
        raise DiagnosticError("That channel does not exist in this recording.")
    stride = channels * width
    mono = b"".join(data[offset + channel * width:offset + (channel + 1) * width]
                    for offset in range(0, len(data), stride))
    with wave.open(str(destination), "wb") as stream:
        stream.setnchannels(1)
        stream.setsampwidth(width)
        stream.setframerate(rate)
        stream.writeframes(mono)


def playback_check(path):
    rate, frames = 48000, 24000
    samples = array("h")
    for frame in range(frames):
        envelope = min(1.0, frame / 480, (frames - frame - 1) / 480)
        samples.append(round(3276 * envelope * math.sin(2 * math.pi * 440 * frame / rate)))
    if sys.byteorder != "little":
        samples.byteswap()
    with wave.open(str(path), "wb") as stream:
        stream.setnchannels(1)
        stream.setsampwidth(2)
        stream.setframerate(rate)
        stream.writeframes(samples.tobytes())


def review(args):
    run = Path(args.run).expanduser().resolve()
    results = json.loads((run / "results.json").read_text(encoding="utf-8"))
    player = shutil.which("pw-play") or shutil.which("aplay")
    if not args.no_play and not player:
        raise DiagnosticError("No pw-play/aplay found. Use --no-play and listen with another WAV player.")
    if args.target and (not player or Path(player).stem != "pw-play"):
        raise DiagnosticError("--target requires pw-play. Otherwise select a working default output in desktop Sound settings.")
    runner = Runner(run)
    player_args = [player] if player else []
    if args.target:
        player_args += ["--target", args.target]
    pending = [trial for trial in results["trials"] if trial.get("status") == "ok"
               and (trial.get("voice_audible") is None or args.again)]
    if pending and not args.no_play:
        tone = run / "playback-check.wav"
        playback_check(tone)
        print("Playing a brief tone to verify the listening output...", flush=True)
        runner.run([*player_args, tone], "playback-check", timeout=10, required=True)
        if input("Could you hear that tone? [y/n]: ").strip().lower() != "y":
            raise DiagnosticError("Select a working desktop output, or use review --target with the headset's node name. "
                                  "No recordings were classified from this failed listening check.")
        results["playback_check"] = {"audible": True, "target": args.target or "desktop-default", "time": utc_now()}
        write_results(run, results)
    for trial in results["trials"]:
        if trial.get("status") != "ok":
            continue
        wav_path = run / trial["wav"]
        print(f"\n{trial['name']}: {trial['pcm']} / {trial['route']}")
        print(json.dumps(trial["analysis"]["channels"], indent=2))
        if trial.get("voice_audible") is not None and not args.again:
            print("Already reviewed; use --again to revisit.")
            continue
        if not args.no_play:
            played = runner.run([*player_args, wav_path], "listen-" + trial["name"], timeout=results["seconds"] + 10)
            if played["status"] != "ok":
                print("Playback failed; this recording remains unreviewed. Fix the output and retry.")
                continue
        while True:
            answer = input("Intelligible voice? y=yes, n=no, u=uncertain; p=replay, l/r=solo channel, q=finish: ").strip().lower()
            if answer == "q":
                write_results(run, results)
                print(json.dumps(results["decision"], indent=2))
                return 0
            if answer in ("y", "n", "u"):
                trial["voice_audible"] = {"y": True, "n": False, "u": None}[answer]
                trial["reviewed"] = utc_now()
                write_results(run, results)
                break
            if answer in ("p", "l", "r") and player and not args.no_play:
                destination = wav_path
                if answer != "p":
                    destination = run / (trial["name"] + "-solo-" + answer + ".wav")
                    try:
                        solo_channel(wav_path, destination, 0 if answer == "l" else 1)
                    except DiagnosticError as exc:
                        print(str(exc))
                        continue
                played = runner.run([*player_args, destination], "listen-" + trial["name"], timeout=results["seconds"] + 10)
                if played["status"] != "ok":
                    print("Replay failed. Do not classify speech from an inaudible replay.")
    write_results(run, results)
    print(json.dumps(results["decision"], indent=2))
    print(f"Summary: {run / 'SUMMARY.md'}")
    return 0


def analyze(args):
    for path in args.wav:
        print(json.dumps({"file": str(path), "analysis": analyze_wav(path)}, indent=2))
    return 0


def bounded_int(lo, hi):
    def parse(value):
        result = int(value)
        if not lo <= result <= hi:
            raise argparse.ArgumentTypeError(f"Choose a value between {lo} and {hi}.")
        return result
    return parse


def build_parser():
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    for name, function in (("collect", collect), ("jacks", jack_test), ("test", test_capture)):
        command = commands.add_parser(name)
        command.set_defaults(function=function)
        command.add_argument("--card", type=bounded_int(0, 99), help="Optional current ALSA card number; USB ID is still verified")
        command.add_argument("--output", default="diagnostics", help="Parent directory for a new timestamped run")
        command.add_argument("--boot", choices=("unknown", "cold", "ubuntu-restart", "windows-warm"), default="unknown")
    commands.choices["jacks"].add_argument("--seconds", type=bounded_int(5, 120), default=20)
    test = commands.choices["test"]
    test.add_argument("--seconds", type=bounded_int(5, 30), default=8)
    test.add_argument("--gain", choices=("current", "max"), default="max",
                      help="Isolated trials keep the original volume or use the advertised maximum; playback volume is untouched")
    test.add_argument("--dry-run", action="store_true", help="Discover and save the plan without changing mixer or service state")
    test.add_argument("--format", choices=tuple(FORMATS), help="Override advertised format selection for all capture PCMs")
    test.add_argument("--rate", type=bounded_int(8000, 384000), default=48000)
    test.add_argument("--channels", type=bounded_int(1, 8), default=2)
    for name, function in (("restore", manual_restore), ("review", review)):
        command = commands.add_parser(name)
        command.add_argument("run", type=Path)
        command.set_defaults(function=function)
    commands.choices["review"].add_argument("--no-play", action="store_true")
    commands.choices["review"].add_argument("--again", action="store_true")
    commands.choices["review"].add_argument("--target", help="pw-play output node.name from pactl list short sinks")
    command = commands.add_parser("analyze")
    command.add_argument("wav", nargs="+", type=Path)
    command.set_defaults(function=analyze)
    return parser


def main(argv=None):
    args = build_parser().parse_args(argv)
    if hasattr(signal, "SIGTERM"):
        def terminate(signum, frame):
            raise KeyboardInterrupt
        signal.signal(signal.SIGTERM, terminate)
    try:
        return args.function(args)
    except (DiagnosticError, OSError, ValueError, wave.Error) as exc:
        print("Error: " + str(exc), file=sys.stderr)
        return 1
    except (KeyboardInterrupt, EOFError):
        print("Interrupted. If a test was active, its cleanup ran; inspect recovery.json if restoration reported errors.", file=sys.stderr)
        return 130


if __name__ == "__main__":
    sys.exit(main())

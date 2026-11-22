"""Identify USB audio devices without inferring firmware commands from codec names."""

from dataclasses import asdict, dataclass
import json
from pathlib import Path
import re

import realtek_rear_mic


CATALOG = json.loads(Path(__file__).with_name('devices.json').read_text())


@dataclass(frozen=True)
class Device:
    usb_id: str
    revision: str
    path: str
    cards: tuple[int, ...]
    board: str
    recognized: bool
    product: str


def discover(sysfs=Path('/sys')):
    """Enumerate sound-card ancestors; no assumption about card number or USB port."""
    try:
        board = (sysfs / 'class/dmi/id/board_name').read_text().strip()
    except OSError:
        board = ''
    devices = []
    for usb in sorted((sysfs / 'bus/usb/devices').iterdir()):
        if ':' in usb.name or not (usb / 'idVendor').is_file():
            continue
        usb_id = f'{int((usb / "idVendor").read_text(), 16):04x}:{int((usb / "idProduct").read_text(), 16):04x}'
        cards = []
        for card in (sysfs / 'class/sound').glob('card[0-9]*'):
            if not card.name[4:].isdigit():
                continue
            if (card / 'device').resolve().is_relative_to(usb.resolve()):
                interface = (card / 'device').resolve()
                # Hubs/root controllers also contain the card path. Only the
                # nearest USB device ancestor identifies the actual codec.
                parent = next((p for p in (interface, *interface.parents)
                               if (p / 'idVendor').is_file()), None)
                if parent == usb.resolve() and (interface / 'driver').resolve().name == 'snd-usb-audio':
                    cards.append(int(card.name[4:]))
        if cards:
            product = (usb / 'product').read_text().strip() if (usb / 'product').exists() else 'USB Audio'
            devices.append(Device(usb_id, (usb / 'bcdDevice').read_text().strip().lower(),
                                  str(usb.resolve()), tuple(sorted(cards)), board,
                                  usb_id in CATALOG['usb_ids'], product))
    return devices


def verified_profile(device):
    """Only this complete identity has hardware command evidence and live validation."""
    if (device.usb_id == '0b05:1b9b' and device.revision == '0013'
            and device.board.upper() == realtek_rear_mic.BOARD):
        return 'asus-x870e-e-rear'
    return None


def capture_sources(sources, devices, explicit=False):
    result = []
    for source in sources:
        props = source.get('properties', {})
        if (props.get('media.class') != 'Audio/Source'
                or props.get('api.alsa.pcm.stream') != 'capture'
                or source.get('monitor_source')):
            continue
        card = str(props.get('api.alsa.pcm.card', props.get('alsa.card', '')))
        if not card.isdigit():
            continue
        matches = [d for d in devices if int(card) in d.cards and (d.recognized or explicit)]
        if len(matches) != 1:
            continue
        device = matches[0]
        # Cross-check the ALSA component when provided; never admit a playback monitor.
        component = re.search(r'USB([0-9a-f]{4}:[0-9a-f]{4})', str(props.get('alsa.components', '')), re.I)
        if component and component[1].lower() != device.usb_id:
            continue
        pcm = str(props.get('alsa.device', ''))
        if not pcm.isdigit():
            match = re.search(r',([0-9]+)$', str(props.get('api.alsa.path', '')))
            pcm = match[1] if match else ''
        result.append({'name': source['name'], 'description': source.get('description', source['name']),
                       'pcm': int(pcm) if pcm.isdigit() else None,
                       'device': asdict(device), 'hardware_profile': verified_profile(device),
                       'source': source})
    return result


def select_source(sources, devices, source_name=None):
    candidates = capture_sources(sources, devices, explicit=source_name is not None)
    if source_name:
        selected = [s for s in candidates if s['name'] == source_name]
        if len(selected) != 1:
            raise ValueError('Selected source is not a capture source on a detected snd-usb-audio device')
        return selected[0]
    known_rear = [s for s in candidates if s['hardware_profile'] and s['pcm'] == 1]
    if len(known_rear) == 1:
        return known_rear[0]
    if len(candidates) == 1:
        return candidates[0]
    raise ValueError('Choose a capture source with --source from `alc408x-mic detect`; '
                     'front/rear PCM mappings vary between boards')

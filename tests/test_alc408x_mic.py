"""Cross-vendor admission, gain limits and installer failure/rollback behavior."""

import json
import math
from pathlib import Path
import tempfile
import unittest
from unittest import mock

from alc408x_mic import audio, hardware, installer


def device(usb_id='0db0:cd0e', board='MSI board', card=9, revision='0001'):
    return hardware.Device(usb_id, revision, '/sys/devices/usb1/1-2', (card,), board,
                           usb_id in hardware.CATALOG['usb_ids'], 'USB Audio')


def source(name='rear', pcm=0, card=9, usb_id='0db0:cd0e', channels='front-left,front-right'):
    return {'name': name, 'description': name, 'channel_map': channels,
            'mute': False, 'volume': {'front-left': {'value': 50000}, 'front-right': {'value': 50000}},
            'properties': {'media.class': 'Audio/Source', 'api.alsa.pcm.stream': 'capture',
                           'api.alsa.pcm.card': str(card), 'alsa.device': str(pcm),
                           'alsa.components': f'USB{usb_id}'}}


class HardwareTests(unittest.TestCase):
    def test_catalog_includes_multiple_vendors_and_alc4082(self):
        ids = hardware.CATALOG['usb_ids']
        for usb_id in ('0b05:1a27', '0b05:1a53', '0414:a014', '0db0:cd0e', '26ce:0a0b'):
            self.assertIn(usb_id, ids)
        self.assertNotIn('12d1:4321', ids)
        self.assertEqual(len(ids), len(set(ids)))

    def test_msi_routes_require_selection_instead_of_assuming_pcm1(self):
        sources = [source('front', pcm=2), source('rear', pcm=0)]
        with self.assertRaisesRegex(ValueError, 'mappings vary'):
            hardware.select_source(sources, [device()])
        selected = hardware.select_source(sources, [device()], 'rear')
        self.assertEqual(selected['pcm'], 0)
        self.assertIsNone(selected['hardware_profile'])

    def test_asrock_capture_maps_to_its_actual_card_and_pcm(self):
        d = device('26ce:0a0b', board='X870E Taichi', card=12)
        s = source('taichi-rear', pcm=0, card=12, usb_id=d.usb_id)
        self.assertEqual(hardware.select_source([s], [d])['name'], 'taichi-rear')

    def test_known_asus_rear_is_selected_among_front_and_rear(self):
        d = device('0b05:1b9b', board=hardware.realtek_rear_mic.BOARD, revision='0013')
        s = [source('front', pcm=2, usb_id=d.usb_id), source('rear', pcm=1, usb_id=d.usb_id)]
        self.assertEqual(hardware.select_source(s, [d])['name'], 'rear')

    def test_same_usb_id_different_board_or_revision_has_no_hardware_profile(self):
        self.assertIsNone(hardware.verified_profile(device('0b05:1b9b', board='OTHER', revision='0013')))
        self.assertIsNone(hardware.verified_profile(device('0b05:1b9b', board=hardware.realtek_rear_mic.BOARD,
                                                           revision='0020')))

    def test_unlisted_usb_device_needs_explicit_source(self):
        d = device('1234:abcd')
        s = source(usb_id=d.usb_id)
        with self.assertRaises(ValueError):
            hardware.select_source([s], [d])
        self.assertEqual(hardware.select_source([s], [d], 'rear')['device']['recognized'], False)

    def test_monitor_playback_and_wrong_component_are_rejected(self):
        original = source()
        for patch in ({'media.class': 'Audio/Sink'}, {'api.alsa.pcm.stream': 'playback'},
                      {'alsa.components': 'USB1234:abcd'}):
            s = {**original, 'properties': {**original['properties'], **patch}}
            self.assertEqual(hardware.capture_sources([s], [device()]), [])
        self.assertEqual(hardware.capture_sources([{**original, 'monitor_source': 'speaker'}], [device()]), [])

    def test_hub_is_not_mistaken_for_its_usb_audio_child(self):
        with tempfile.TemporaryDirectory() as temp:
            sysfs = Path(temp)
            hub = sysfs / 'devices/usb1/1-1'
            codec = hub / '1-1.2'
            interface = codec / '1-1.2:1.0'
            card = interface / 'sound/card9'
            card.mkdir(parents=True)
            for path, vid, pid in ((hub, '174c', '2074'), (codec, '0db0', 'cd0e')):
                for key, value in {'idVendor': vid, 'idProduct': pid, 'bcdDevice': '0001'}.items():
                    (path / key).write_text(value)
            bus = sysfs / 'bus/usb/devices'
            bus.mkdir(parents=True)
            (bus / '1-1').symlink_to(hub)
            (bus / '1-1.2').symlink_to(codec)
            sound = sysfs / 'class/sound'
            sound.mkdir(parents=True)
            (sound / 'card9').symlink_to(card)
            (card / 'device').symlink_to(interface)
            driver = sysfs / 'bus/usb/drivers/snd-usb-audio'
            driver.mkdir(parents=True)
            (interface / 'driver').symlink_to(driver)
            found = hardware.discover(sysfs)
            self.assertEqual([(d.usb_id, d.cards) for d in found], [('0db0:cd0e', (9,))])
            self.assertEqual(found[0].board, '')  # DMI is optional for generic gain.


class GainTests(unittest.TestCase):
    def test_gain_above_20db_uses_supported_control_values(self):
        # Regression: a single Mult=63.1 read back as +36 dB but produced +20 dB.
        for gain in (0, 20, 30, 36, 48):
            config = audio.filter_config('actual-source', gain)
            graph = config['context.modules'][-1]['args']['filter.graph']
            for channel in ('ch0', 'ch1'):
                stages = [n for n in graph['nodes'] if n['name'].startswith(channel)]
                self.assertTrue(all(0 <= n['control']['Mult'] <= 10 for n in stages))
                actual = 20 * math.log10(math.prod(n['control']['Mult'] for n in stages))
                self.assertAlmostEqual(actual, gain)

    def test_mono_source_is_not_silently_treated_as_stereo(self):
        channels, layout = audio.channel_layout(source(channels='mono'))
        config = audio.filter_config('mono-source', 12, channels, layout)
        args = config['context.modules'][-1]['args']
        self.assertEqual(args['audio.position'], ['MONO'])
        self.assertEqual(len(args['filter.graph']['inputs']), 1)
        self.assertEqual(args['capture.props']['target.object'], 'mono-source')
        self.assertTrue(args['capture.props']['node.dont-fallback'])

    def test_invalid_gain_and_channel_layout_rejected(self):
        for gain in (-1, 49, float('nan'), float('inf')):
            with self.assertRaises(ValueError):
                audio.filter_config('source', gain)
        with self.assertRaises(ValueError):
            audio.channel_layout(source(channels='front-left,front-right,rear-left,rear-right'))


class InstallerTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.home = Path(self.temp.name)

    def test_preexisting_file_stops_install_before_any_write(self):
        first, second = self.home / 'first', self.home / 'second'
        second.write_bytes(b'user settings')
        with self.assertRaises(ValueError):
            installer.install_files(self.home / 'manifest.json',
                                    {first: (b'one', 0o644), second: (b'two', 0o644)}, {})
        self.assertFalse(first.exists())
        self.assertEqual(second.read_bytes(), b'user settings')

    def test_mid_install_error_removes_created_files(self):
        first, blocked = self.home / 'first', self.home / 'blocked'
        blocked.write_bytes(b'not a directory')
        with self.assertRaises(OSError):
            installer.install_files(self.home / 'manifest.json',
                                    {first: (b'one', 0o644), blocked / 'second': (b'two', 0o644)}, {})
        self.assertFalse(first.exists())
        self.assertFalse((self.home / 'manifest.json').exists())

    def test_manifest_cannot_remove_unrelated_or_modified_files(self):
        path = self.home / 'config'
        manifest = self.home / 'manifest.json'
        installer.install_files(manifest, {path: (b'original', 0o644)}, {})
        records = json.loads(manifest.read_text())
        with self.assertRaisesRegex(ValueError, 'Unexpected'):
            installer.verify_manifest(records, {self.home / 'unrelated'})
        path.write_bytes(b'modified')
        with self.assertRaisesRegex(ValueError, 'modified'):
            installer.verify_manifest(records, {path})
        self.assertEqual(path.read_bytes(), b'modified')

    def test_user_service_failure_restores_audio_and_removes_config(self):
        paths = installer.user_paths(self.home)
        selected = hardware.select_source([source()], [device()])
        calls = []

        def run(*args, **kwargs):
            calls.append(args)
            if args == ('pactl', 'get-default-source'):
                return 'previous-mic'
            if args[:4] == ('systemctl', '--user', 'enable', '--now'):
                raise RuntimeError('simulated service failure')
            return ''

        with mock.patch.object(installer, 'user_paths', return_value=paths), \
             mock.patch.object(installer.os, 'geteuid', return_value=1000), \
             mock.patch.object(installer, 'require_commands'), \
             mock.patch.object(installer, 'sources', return_value=[source(), source('previous-mic')]), \
             mock.patch.object(installer, 'run', side_effect=run):
            with self.assertRaisesRegex(RuntimeError, 'simulated'):
                installer.install_user(selected, 30, 'max')
        self.assertFalse(any(p.exists() for p in paths))
        self.assertFalse((paths[1].parent / 'wait_audio.py').exists())
        self.assertIn(('pactl', 'set-default-source', 'previous-mic'), calls)
        self.assertIn(('pactl', 'set-source-volume', 'rear', 50000, 50000), calls)

    def test_generic_setup_dry_run_has_no_writes_or_root_requirement(self):
        selected = hardware.select_source([source()], [device()])
        with mock.patch.object(installer, 'run') as run, \
             mock.patch.object(installer, 'install_files') as write:
            plan = installer.install_user(selected, 15, dry_run=True)
        self.assertFalse(plan['vendor_usb_writes'])
        run.assert_not_called()
        write.assert_not_called()

    def test_unsupported_initialization_fails_before_writes(self):
        with mock.patch.object(installer.realtek_rear_mic, 'discover_device', side_effect=ValueError('wrong board')), \
             mock.patch.object(installer, 'install_files') as write:
            with self.assertRaisesRegex(ValueError, 'wrong board'):
                installer.install_system()
        write.assert_not_called()


if __name__ == '__main__':
    unittest.main()

import hashlib
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from alc408x_mic import legacy


class LegacyRemovalTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.home = Path(self.temp.name)
        self.manifest, self.allowed = legacy.paths('desktop', self.home)
        self.target = self.home / '.config/pipewire/g335-rear-microphone.conf'
        self.target.parent.mkdir(parents=True)
        self.target.write_bytes(b'installed filter')
        self.manifest.parent.mkdir(parents=True)
        self.metadata = {'files': [{'path': str(self.target),
                                   'sha256': hashlib.sha256(self.target.read_bytes()).hexdigest()}],
                         'default_before': 'previous-input',
                         'master_before': {'name': 'raw-input', 'mute': True,
                                           'volume': {'mono': {'value': 40000}}}}
        self.manifest.write_text(json.dumps(self.metadata))
        self.paths = patch.object(legacy, 'paths', return_value=(self.manifest, self.allowed))
        self.paths.start()
        self.addCleanup(self.paths.stop)

    def test_dry_run_never_changes_services_or_files(self):
        with patch.object(legacy.installer, 'run') as run:
            result = legacy.remove('desktop', dry_run=True)
        self.assertEqual(result['status'], 'planned')
        self.assertTrue(self.target.exists())
        self.assertTrue(self.manifest.exists())
        run.assert_not_called()

    def test_modified_file_blocks_removal_before_service_changes(self):
        self.target.write_bytes(b'user edited this')
        with patch.object(legacy.os, 'geteuid', return_value=1000), \
                patch.object(legacy.installer, 'run') as run:
            with self.assertRaisesRegex(ValueError, 'modified'):
                legacy.remove('desktop')
        self.assertTrue(self.manifest.exists())
        run.assert_not_called()

    def test_unexpected_manifest_path_cannot_be_removed(self):
        self.metadata['files'][0]['path'] = str(self.home / 'unrelated')
        self.manifest.write_text(json.dumps(self.metadata))
        with patch.object(legacy.os, 'geteuid', return_value=1000), \
                patch.object(legacy.installer, 'run') as run:
            with self.assertRaisesRegex(ValueError, 'Unexpected'):
                legacy.remove('desktop')
        self.assertTrue(self.target.exists())
        run.assert_not_called()

    def test_removal_restores_previous_input_and_preserves_other_files(self):
        unrelated = self.target.parent / 'other.conf'
        unrelated.write_text('keep')
        with patch.object(legacy.os, 'geteuid', return_value=1000), \
                patch.object(legacy.installer, 'sources', return_value=[{'name': 'raw-input'}, {'name': 'previous-input'}]), \
                patch.object(legacy.installer, 'run') as run:
            self.assertEqual(legacy.remove('desktop')['status'], 'removed')
        self.assertFalse(self.target.exists())
        self.assertFalse(self.manifest.exists())
        self.assertEqual(unrelated.read_text(), 'keep')
        run.assert_any_call('pactl', 'set-default-source', 'previous-input')
        run.assert_any_call('pactl', 'set-source-volume', 'raw-input', 40000)
        run.assert_any_call('pactl', 'set-source-mute', 'raw-input', 1)


if __name__ == '__main__':
    unittest.main()

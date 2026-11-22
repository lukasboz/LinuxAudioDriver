import unittest
from alc408x_mic import audio, wait_audio


def source(name, media_class='Audio/Source', monitor=''):
    return {'name': name, 'monitor_source': monitor, 'properties': {'media.class': media_class}}


class FakeClock:
    def __init__(self):
        self.now = 0

    def clock(self):
        return self.now

    def sleep(self, seconds):
        self.now += seconds


class AudioStartupTests(unittest.TestCase):
    def test_running_server_without_capture_node_does_not_count_as_ready(self):
        clock = FakeClock()
        with self.assertRaises(TimeoutError):
            wait_audio.wait_for_source('mic', 1, fetch=lambda: [source('webcam')],
                                       clock=clock.clock, sleep=clock.sleep)
        self.assertEqual(clock.now, 1)

    def test_delayed_usb_source_is_waited_for(self):
        clock = FakeClock()
        responses = iter([[], [source('webcam')], [source('mic')]])
        wait_audio.wait_for_source('mic', 2, fetch=lambda: next(responses),
                                   clock=clock.clock, sleep=clock.sleep)
        self.assertEqual(clock.now, .5)

    def test_temporary_server_connection_failure_is_retried(self):
        clock = FakeClock()
        calls = []
        def fetch():
            calls.append(1)
            if len(calls) < 3:
                raise RuntimeError('Server not listening yet')
            return [source('mic')]
        wait_audio.wait_for_source('mic', 2, fetch=fetch, clock=clock.clock, sleep=clock.sleep)
        self.assertEqual(len(calls), 3)

    def test_playback_monitor_cannot_satisfy_capture_readiness(self):
        self.assertFalse(wait_audio.capture_present([source('mic', monitor='speaker')], 'mic'))
        self.assertFalse(wait_audio.capture_present([source('mic', media_class='Audio/Sink')], 'mic'))

    def test_renamed_and_mono_sources_are_derived_from_config(self):
        config = audio.filter_config('actual-usb-route', 12, channels=1, name='custom_mic')
        self.assertEqual(wait_audio.filter_names(config), ('actual-usb-route', 'custom_mic'))

    def test_missing_filter_is_not_treated_as_a_ready_service(self):
        with self.assertRaises(ValueError):
            wait_audio.filter_names({'context.modules': []})


if __name__ == '__main__':
    unittest.main()

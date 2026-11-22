"""Generate a fixed-gain source that follows an explicitly selected USB input."""

import math


SOURCE_NAME = 'alc408x_microphone'
DESCRIPTION = 'ALC4080/4082 Microphone'
UNIT = 'alc408x-microphone.service'


def filter_config(master, gain, channels=2, positions=None, name=SOURCE_NAME):
    if not math.isfinite(gain) or not 0 <= gain <= 48:
        raise ValueError('Software gain must be between 0 and 48 dB')
    if channels not in (1, 2):
        raise ValueError('Select a mono or stereo microphone source')
    positions = positions or (['MONO'] if channels == 1 else ['FL', 'FR'])
    if len(positions) != channels:
        raise ValueError('Channel positions do not match the channel count')
    names = [f'ch{channel}' for channel in range(channels)]
    graph = {
        'nodes': [{'type': 'builtin', 'name': f'{channel}_{stage}', 'label': 'linear',
                   'control': {'Mult': 10 ** (gain / 60), 'Add': 0.0}}
                  for channel in names for stage in range(3)],
        'links': [{'output': f'{channel}_{stage}:Out', 'input': f'{channel}_{stage+1}:In'}
                  for channel in names for stage in range(2)],
        'inputs': [f'{channel}_0:In' for channel in names],
        'outputs': [f'{channel}_2:Out' for channel in names]}
    return {
        'context.properties': {'log.level': 2},
        'context.spa-libs': {'audio.convert.*': 'audioconvert/libspa-audioconvert',
                             'support.*': 'support/libspa-support'},
        'context.modules': [
            {'name': 'libpipewire-module-rt', 'flags': ['ifexists', 'nofail']},
            {'name': 'libpipewire-module-protocol-native'},
            {'name': 'libpipewire-module-client-node'},
            {'name': 'libpipewire-module-adapter'},
            {'name': 'libpipewire-module-filter-chain', 'args': {
                'node.description': DESCRIPTION, 'media.name': DESCRIPTION,
                'audio.channels': channels, 'audio.position': positions,
                'filter.graph': graph,
                'capture.props': {'node.name': f'capture.{name}', 'target.object': master,
                                  'node.passive': True, 'stream.dont-remix': True,
                                  'node.dont-fallback': True},
                'playback.props': {'node.name': name, 'node.description': DESCRIPTION,
                                   'media.class': 'Audio/Source', 'priority.session': 0}}}]}


def channel_layout(source):
    positions = {'mono': 'MONO', 'front-left': 'FL', 'front-right': 'FR'}
    channel_map = source.get('channel_map', '')
    try:
        layout = [positions[p.strip()] for p in channel_map.split(',')]
    except KeyError as error:
        raise ValueError(f'Unsupported microphone channel map: {channel_map}') from error
    if len(layout) not in (1, 2):
        raise ValueError('Select a mono or stereo microphone source')
    return len(layout), layout


def user_unit():
    return '''[Unit]
Description=Realtek ALC4080/4082 microphone gain
After=pipewire.service wireplumber.service
Requires=pipewire.service
PartOf=pipewire.service

[Service]
Type=exec
ExecStartPre=/usr/bin/python3 %h/.config/alc408x-mic/wait_audio.py --config %h/.config/alc408x-mic/filter.conf --kind master --timeout 30
ExecStart=/usr/bin/pipewire -c %h/.config/alc408x-mic/filter.conf
ExecStartPost=/usr/bin/python3 %h/.config/alc408x-mic/wait_audio.py --config %h/.config/alc408x-mic/filter.conf --kind output --timeout 10 --state %h/.config/alc408x-mic/install.json
TimeoutStartSec=50
Restart=on-failure
RestartSec=2

[Install]
WantedBy=pipewire.service
'''

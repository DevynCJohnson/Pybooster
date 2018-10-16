#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Library for multimedia manipulation

@file multimedia.py
@package pybooster.multimedia
@version 2018.10.13
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This software is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
"""


from array import array
import wave

PYGAME_IMPORTED: bool = False

try:
    from pygame.mixer import init, music
    PYGAME_IMPORTED = True
except ImportError:
    pass


__all__: list = [
    # AUDIO #
    r'openwavfile',
    r'playmusic'
]


# AUDIO #


def openwavfile(_filename: str) -> dict:
    """Get the contents of the specified WAV file and return the data as a list of integers in a dictionary describing the data"""
    _wav_data: list = []
    with wave.open(_filename, mode=r'rb') as _file:
        _wav_data.append(_file.readframes(_file.getnframes()))
    _out: dict = {
        r'num_frames': _file.getnframes(),
        r'frame_rate': _file.getframerate(),
        r'num_channels': _file.getnchannels(),
        r'sample_width': _file.getsampwidth()
    }
    if _out[r'sample_width'] == 1:  # 8-bit
        _out[r'data'] = array(r'b', _wav_data[0])
    elif _out[r'sample_width'] == 2:  # 16-bit
        _out[r'data'] = array(r'h', _wav_data[0])
    elif _out[r'sample_width'] == 4:  # 32-bit
        _out[r'data'] = array(r'l', _wav_data[0])
    if _out[r'num_channels'] == 2:
        _out[r'left_audio'] = _out[r'data'][0::2]
        _out[r'right_audio'] = _out[r'data'][1::2]
    return _out


def playmusic(_file: str) -> None:
    """Play an MP3, WAV, or other audio files via Pygame3"""
    if not PYGAME_IMPORTED:
        raise Exception(r'Pygame is not installed nor found.')
    init()
    music.load(_file)
    music.play()
    while music.get_busy() is True:
        continue

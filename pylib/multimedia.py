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


import wave

try:
    from pygame.mixer import init, music
except ImportError:
    raise Exception(r'Pygame is not installed or found.')


__all__: list = [
    # AUDIO #
    r'openwavfile',
    r'playmusic'
]


# AUDIO #


def openwavfile(_filename: str) -> list:
    """Get the contents of the specified WAV file and return the data as a list of bytes"""
    _out: list = []
    with wave.open(_filename, mode=r'rb') as _file:
        _out.append(_file.readframes(_file.getnframes()))
    return _out


def playmusic(_file: str) -> None:
    """Play an MP3, WAV, or other audio files via Pygame3"""
    init()
    music.load(_file)
    music.play()
    while music.get_busy() is True:
        continue

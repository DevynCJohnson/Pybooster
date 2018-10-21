#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Advanced math functions (mostly graphing)

@file ymath.py
@package pybooster.ymath
@version 2018.10.21
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
S
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


# pylint: disable=C0103,E1101


from time import time
from typing import Union
import wave

from pybooster.iterables import func_range

import matplotlib.pyplot as plt
import numpy as np


__all__: list = [
    # RANDOM #
    r'get_rng',
    r'get_rand_byte_str',
    r'get_rand_int32_array',
    r'get_rand_int64_array',
    r'get_rand_f32_array',
    r'get_rand_f64_array',
    r'rand_noise_wav',
    r'rand_noise_write',
    # IMAGING #
    r'saveasimg',
    r'funcimg',
    r'funcimg_aitoff',
    r'funcimg_lambert',
    r'funcimg_polar',
    r'randimg',
    r'randcimg'
]


# RANDOM #


def get_rng() -> object:
    """Return a random number generator; Returns a np.random.mtrand.RandomState object"""
    return np.random.RandomState(int(time()))


def get_rand_byte_str(_length: int, rng: object) -> bytes:
    """Return a string of random bytes using the given number generator"""
    return rng.bytes(_length)  # type: ignore


def get_rand_int32_array(_low: int, _high: int, _width: int, _height: int, rng: object) -> object:
    """Return an array of random 32-bit integers between low & high using the given number generator; Returns an np.ndarray"""
    return rng.randint(_low, high=_high + 1, size=(_width, _height), dtype=r'int32')  # type: ignore


def get_rand_int64_array(_low: int, _high: int, _width: int, _height: int, rng: object) -> object:
    """Return an array of random 64-bit integers between low & high using the given number generator; Returns an np.ndarray"""
    return rng.randint(_low, high=_high + 1, size=(_width, _height), dtype=r'int64')  # type: ignore


def get_rand_f32_array(_width: int, _height: int, rng: object) -> object:
    """Return an array of random 32-bit floats using the given number generator; Returns an np.ndarray"""
    return np.array(rng.rand(_width, _height), dtype=r'float32')  # type: ignore


def get_rand_f64_array(_width: int, _height: int, rng: object) -> object:
    """Return an array of random 64-bit floats using the given number generator; Returns an np.ndarray"""
    return np.array(rng.rand(_width, _height), dtype=r'float64')  # type: ignore


def rand_noise_wav(_seconds: int, _framerate: int = 44100) -> dict:
    """Generate a 16-bit mono WAV file containing random noise & return the data"""
    _data = np.random.uniform(-1, 1, _framerate * _seconds)
    _scaled = np.int16(_data / np.max(np.abs(_data)) * 32767)
    _out: dict = {
        r'num_frames': _scaled.shape[0],  # pylint: disable=E1136
        r'frame_rate': _framerate,
        r'num_channels': 1,
        r'sample_width': 2,
        r'data': bytes(_scaled)
    }
    return _out


def rand_noise_write(_filename: str, _seconds: int, _framerate: int = 44100) -> None:
    """Generate a 16-bit mono WAV file containing random noise & write it to a file"""
    _data = np.random.uniform(-1, 1, _framerate * _seconds)
    _scaled = np.int16(_data / np.max(np.abs(_data)) * 32767)
    _wav_data: bytes = bytes(_scaled)
    with wave.open(_filename, mode=r'wb') as _file:
        _file.setparams((1, 2, _framerate, _scaled.shape[0], r'NONE', r'not compressed'))  # pylint: disable=E1101,E1136
        _file.writeframes(_wav_data)  # pylint: disable=E1101


# IMAGING #


def saveasimg(_figure: object, _filepath: str) -> None:
    """Save the given figure to the spefified file path"""
    _figure.savefig(_filepath, bbox_inches=r'tight', dpi=r'figure', quality=95)  # type: ignore


def funcimg(_func: object, _start: Union[float, int] = 0, _stop: Union[float, int] = 360, _step: Union[float, int] = 1) -> object:
    """Produce an image with the specified number of random pixels (x & y) of size _height & _width graphing the specified function; Returns matplotlib.image.FigureImage"""
    plt.rc(r'axes', labelsize=18, labelweight=r'bold', titlesize=24)
    plt.rc(r'xtick.major.pad', pad=10)
    _img: object = plt.figure(figsize=(20, 14), dpi=400)
    _data: object = np.array(func_range(_func, _start, _stop, _step), dtype=r'float64')
    _img.subplots(subplot_kw={r'adjustable': r'datalim', r'aspect': r'auto', r'autoscale_on': True, r'projection': r'rectilinear', r'xlabel': r'Inputs', r'xscale': r'linear', r'ylabel': r'Outputs', r'yscale': r'linear'})  # type: ignore
    _img.tight_layout()  # type: ignore
    plt.plot(_data)
    return _img


def funcimg_aitoff(_func: object, _start: Union[float, int] = 0, _stop: Union[float, int] = 360, _step: Union[float, int] = 1) -> object:
    """Produce an image with the specified number of random pixels (x & y) of size _height & _width graphing (aitoff) the specified function; Returns matplotlib.image.FigureImage"""
    plt.rc(r'axes', labelsize=18, labelweight=r'bold', titlesize=24)
    plt.rc(r'xtick.major.pad', pad=10)
    _img: object = plt.figure(figsize=(20, 14), dpi=400)
    _data: object = np.array(func_range(_func, _start, _stop, _step), dtype=r'float64')
    _img.subplots(subplot_kw={r'adjustable': r'datalim', r'aspect': r'auto', r'autoscale_on': True, r'projection': r'aitoff', r'xlabel': r'Inputs', r'xscale': r'linear', r'ylabel': r'Outputs', r'yscale': r'linear'})  # type: ignore
    _img.tight_layout()  # type: ignore
    plt.plot(_data)
    return _img


def funcimg_lambert(_func: object, _start: Union[float, int] = 0, _stop: Union[float, int] = 360, _step: Union[float, int] = 1) -> object:
    """Produce an image with the specified number of random pixels (x & y) of size _height & _width graphing (lambert) the specified function; Returns matplotlib.image.FigureImage"""
    plt.rc(r'axes', labelsize=18, labelweight=r'bold', titlesize=24)
    plt.rc(r'xtick.major.pad', pad=10)
    _img: object = plt.figure(figsize=(20, 14), dpi=400)
    _data: object = np.array(func_range(_func, _start, _stop, _step), dtype=r'float64')
    _img.subplots(subplot_kw={r'adjustable': r'datalim', r'aspect': r'auto', r'autoscale_on': True, r'projection': r'lambert', r'xlabel': r'Inputs', r'xscale': r'linear', r'ylabel': r'Outputs', r'yscale': r'linear'})  # type: ignore
    _img.tight_layout()  # type: ignore
    plt.plot(_data)
    return _img


def funcimg_polar(_func: object, _start: Union[float, int] = 0, _stop: Union[float, int] = 360, _step: Union[float, int] = 1) -> object:
    """Produce an image with the specified number of random pixels (x & y) of size _height & _width graphing (polar) the specified function; Returns matplotlib.image.FigureImage"""
    plt.rc(r'axes', labelsize=18, labelweight=r'bold', titlesize=24)
    plt.rc(r'xtick.major.pad', pad=10)
    _img: object = plt.figure(figsize=(20, 14), dpi=400)
    _data: object = np.array(func_range(_func, _start, _stop, _step), dtype=r'float64')
    _img.subplots(subplot_kw={r'adjustable': r'datalim', r'aspect': r'auto', r'autoscale_on': True, r'projection': r'polar', r'xlabel': r'Inputs', r'xscale': r'linear', r'ylabel': r'Outputs', r'yscale': r'linear'})  # type: ignore
    _img.tight_layout()  # type: ignore
    plt.plot(_data)
    return _img


def randimg(_width: int, _height: int) -> object:
    """Produce a random image with the specified number of random pixels (x & y) of size _height & _width; Returns matplotlib.image.FigureImage"""
    _img: object = plt.figure(dpi=100, tight_layout=True)
    rng: object = get_rng()
    _img.figimage(np.array(rng.rand(_width, _height), dtype=r'float64'), cmap=plt.cm.gray_r, resize=True)  # type: ignore
    return _img


def randcimg(_width: int, _height: int) -> object:
    """Produce a random image with the specified number of random pixels (x & y) of size _height & _width; Returns matplotlib.image.FigureImage"""
    _img: object = plt.figure(dpi=100, tight_layout=True)
    rng: object = get_rng()
    _img.figimage(np.array(rng.rand(_width, _height), dtype=r'float64'), cmap=plt.cm.hsv_r, resize=True)  # type: ignore
    return _img

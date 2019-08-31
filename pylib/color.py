#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Color manipulation.

@file color.py
@package pybooster.color
@version 2019.08.31
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
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
"""


from math import acos, cos, sqrt
from typing import Union


__all__: list = [
    # GENERAL FUNCTIONS #
    r'hue2value',
    r'huedegree2huefloat',
    r'huefloat2huedegree',
    # COLOR THEORY FUNCTIONS #
    r'analogous',
    r'complement',
    r'opposite',
    # HTML #
    r'html2hex',
    r'html2rgb',
    r'shorthand2sixdigit',
    # CMY #
    r'cmy2cmyk',
    r'cmy2rgb',
    # CMYK #
    r'cmyk2cmy',
    r'cmyk2rgb',
    # HSI #
    r'hsi2rgb',
    # HLS #
    r'hls2hsv',
    r'hls2rgb',
    # HSV #
    r'hsv2hls',
    r'hsv2rgb',
    # HUNTERLAB #
    r'hunterlab2xyz',
    # RGB (BYTE-NOTATION & FLOAT-NOTATION) #
    r'rgb2cmy',
    r'rgb2cmyk',
    r'rgb2hex',
    r'rgb2hls',
    r'rgb2hsi',
    r'rgb2hsv',
    r'rgb2html',
    r'rgb2xyz',
    r'rgb2yiq',
    # RGB & RGBA #
    r'rgb2rgba',
    r'rgba2rgb',
    # RGB FLOATS & RGB INTEGERS (BYTE ARRAY) #
    r'rgb2rgbf',
    r'rgbf2rgb',
    r'roundrgb',
    # RYB #
    r'ryb2rgb',
    # XYZ #
    r'xyz2hunterlab',
    r'xyz2rgb',
    # YIQ #
    r'yiq2rgb'
]


# GLOBALS #


ONE_SIXTH: float = 1.0 / 6.0
ONE_THIRD: float = 1.0 / 3.0
TWO_THIRD: float = 2.0 / 3.0


# FUNCTIONS #


def hilo(_x: Union[float, int], _y: Union[float, int], _z: Union[float, int]) -> Union[float, int]:
    """Sum of the min & max of `_x`, `_y`, and `_z`.

    >>> hilo(1, 2, 3)
    4
    >>> hilo(1, 5, 9)
    10
    >>> hilo(0, 0, 0)
    0
    >>> hilo(1.0, 1.0, 1.0)
    2.0
    """
    if _z < _y:
        _y, _z = _z, _y
    if _y < _x:
        _x, _y = _y, _x
    if _z < _y:
        _y, _z = _z, _y
    return _x + _z


def hue2value(_m1: float, _m2: float, _hue: float) -> float:
    """Get value from hue."""
    _hue %= 1.0
    if _hue < ONE_SIXTH:
        return ((_m2 - _m1) * _hue * 6.0) + _m1
    if _hue < 0.5:
        return _m2
    if _hue < TWO_THIRD:
        return ((_m2 - _m1) * (TWO_THIRD - _hue) * 6.0) + _m1
    return _m1


def huedegree2huefloat(_hue: int) -> float:
    """Hue in degrees -> Hue as a float."""
    return float(_hue) / 360.0


def huefloat2huedegree(_hue: float) -> int:
    """Hue as a float -> Hue in degrees."""
    return int(_hue * 360.0)


# COLOR THEORY FUNCTIONS #


def analogous(_rgb: tuple, _float_notation: bool = True) -> tuple:
    """Calculate the two analogous colors.

    >>> analogous((98, 182, 17), False)
    ((17, 182, 19), (181, 182, 17))
    """
    _hue, _light, _sat = rgb2hls(_rgb[0], _rgb[1], _rgb[2], _float_notation)
    _hue_deg: tuple = ((_hue + 0.0833333333333334) % 1, (_hue - 0.0833333333333334) % 1)
    return hls2rgb(_hue_deg[0], _light, _sat, _float_notation), hls2rgb(_hue_deg[1], _light, _sat, _float_notation)


def complement(rgba: tuple, _float_notation: bool = True) -> tuple:
    """Get complementary color (modern color wheel) given a rgb/rgba tuple of integers.

    >>> complement((255, 255, 255), False)
    (255, 255, 255)
    >>> complement((0, 0, 0), False)
    (0, 0, 0)
    >>> complement((1.0, 1.0, 1.0), True)
    (1.0, 1.0, 1.0)
    >>> complement((98, 182, 17), False)
    (101, 17, 182)
    >>> complement((255, 0, 0), False)
    (0, 255, 255)
    >>> complement((150, 0, 100), False)
    (0, 150, 50)
    """
    if _float_notation:
        rgba = tuple(int(_val * 255) for _val in rgba)
    _key = hilo(rgba[0], rgba[1], rgba[2])
    _output = [_key - _color for _color in rgba[0:3]]
    if _float_notation:
        return tuple(_color / 255.0 for _color in _output)
    if len(rgba) == 4:
        _output.append(rgba[3])
    return tuple(_output)


def opposite(rgba: tuple, _float_notation: bool = True) -> tuple:
    """Get opposite color (traditional color wheel) given a rgb/rgba tuple of integers.

    >>> opposite((255, 255, 255), False)
    (0, 0, 0)
    >>> opposite((0, 0, 0), False)
    (255, 255, 255)
    >>> opposite((1.0, 1.0, 1.0), True)
    (0.0, 0.0, 0.0)
    >>> opposite((98, 182, 17), False)
    (157, 73, 238)
    >>> opposite((255, 0, 0), False)
    (0, 255, 255)
    >>> opposite((150, 0, 100), False)
    (105, 255, 155)
    """
    if _float_notation:
        rgba = tuple(int(_val * 255) for _val in rgba)
    _output = [255 - _color for _color in rgba[0:3]]
    if _float_notation:
        return tuple(_color / 255.0 for _color in _output)
    if len(rgba) == 4:
        _output.append(rgba[3])
    return tuple(_output)


# HTML (WEB COLORS) #


def html2hex(_html: str) -> tuple:
    """HTML notation -> hex notation.

    >>> html2hex('#62B611')
    ('62', 'B6', '11')
    """
    return _html[1:3], _html[3:5], _html[-2:]


def html2rgb(_html: str) -> tuple:
    """HTML notation (#f6a797) -> RGB (byte array - 0-255).

    >>> html2rgb('#62B611')
    (98, 182, 17)
    >>> html2rgb('#FF00FF')
    (255, 0, 255)
    >>> html2rgb('#Ff00fF')
    (255, 0, 255)
    """
    return int(_html[1:3], 16), int(_html[3:5], 16), int(_html[-2:], 16)


def shorthand2sixdigit(_shorthand: str) -> str:
    """Shorthand HTML notation (#789) -> 6-digit HTML notation (#778899).

    >>> shorthand2sixdigit('#789')
    '#778899'
    >>> shorthand2sixdigit('#37B')
    '#3377BB'
    """
    if r'#' in _shorthand:
        _red = _shorthand[1] + _shorthand[1]
        _green = _shorthand[2] + _shorthand[2]
        _blue = _shorthand[3] + _shorthand[3]
    else:
        _red = _shorthand[0] + _shorthand[0]
        _green = _shorthand[1] + _shorthand[1]
        _blue = _shorthand[2] + _shorthand[2]
    return r'#' + _red + _green + _blue


# CMY #


def cmy2cmyk(_cyan: float, _magenta: float, _yellow: float) -> tuple:
    """CMY -> CMYK.

    >>> cmy2cmyk(0.537, 0.314, 0.273)
    (0.3631361760660248, 0.05639614855570837, 0.0, 0.273)
    """
    _black: float = _yellow if _yellow < 1.0 else _magenta if _magenta < 1.0 else _cyan if _cyan < 1.0 else 1.0
    if _black == 1.0:
        return 0.0, 0.0, 0.0, _black
    return (_cyan - _black) / (1.0 - _black), (_magenta - _black) / (1.0 - _black), (_yellow - _black) / (1.0 - _black), _black


def cmy2rgb(_cyan: float, _magenta: float, _yellow: float, _rgb_float_notation: bool = True) -> tuple:
    """CMY -> RGB.

    >>> cmy2rgb(0.537, 0.314, 0.273)
    (0.46299999999999997, 0.6859999999999999, 0.727)
    """
    if _rgb_float_notation:
        return 1.0 - _cyan, 1.0 - _magenta, 1.0 - _yellow
    return int(round((1.0 - _cyan) * 255.0)), int(round((1.0 - _magenta) * 255.0)), int(round((1.0 - _yellow) * 255.0))


# CMYK #


def cmyk2cmy(_cyan: float, _magenta: float, _yellow: float, _black: float) -> tuple:
    """CMYK -> CMY.

    >>> cmyk2cmy(0.3631361760660248, 0.05639614855570837, 0.0, 0.273)
    (0.537, 0.314, 0.273)
    """
    return _cyan * (1.0 - _black) + _black, _magenta * (1.0 - _black) + _black, _yellow * (1.0 - _black) + _black


def cmyk2rgb(_cyan: float, _magenta: float, _yellow: float, _black: float, _rgb_float_notation: bool = True) -> tuple:
    """CMYK -> RGB.

    >>> cmyk2rgb(0.3631361760660248, 0.05639614855570837, 0.0, 0.273)
    (0.46299999999999997, 0.6859999999999999, 0.727)
    """
    if _rgb_float_notation:
        return (1.0 - _cyan) * (1.0 - _black), (1.0 - _magenta) * (1.0 - _black), (1.0 - _yellow) * (1.0 - _black)
    return int(round((1.0 - _cyan) * (1.0 - _black) * 255.0)), int(round((1.0 - _magenta) * (1.0 - _black) * 255.0)), int(round((1.0 - _yellow) * (1.0 - _black) * 255.0))


# HSI #


def hsi2rgb(_hue: float, _sat: float, _intensity: float, _rgb_float_notation: bool = True) -> tuple:  # noqa: C901,R701
    """HSI -> RGB.

    >>> hsi2rgb(0.3334, 0.5777, 0.3311)
    (0.002783669573166151, 0.0005632969758534564, 0.0005483275686274509)
    """
    _huerad: float = 0.017453292519943295 * _hue  # Convert degrees to radians
    _si: float = _sat * _intensity
    _si2: float = _si * 2.0
    if _hue == 0.0 or _hue >= 360.0:
        _red = _intensity + _si2
        _green = _intensity - _si
        _blue = _green
    elif 0.0 < _hue < 120.0:
        _cosvar = 57.29577951308232 * cos(_huerad) / (57.29577951308232 * cos(1.0471975511965976 - _huerad))
        _red = _intensity + (_si * _cosvar)
        _green = _intensity + (_si * (1.0 - _cosvar))
        _blue = _intensity - _si
    elif _hue == 120.0:
        _red = _intensity - _si
        _green = _intensity + _si2
        _blue = _red
    elif 120.0 < _hue < 240.0:
        _red = _intensity - _si
        _cosvar = 57.29577951308232 * cos(_huerad - 2.0943951023931953) / (57.29577951308232 * cos(3.141592653589793 - _huerad))
        _green = _intensity + (_si * _cosvar)
        _blue = _intensity + (_si * (1.0 - _cosvar))
    elif _hue == 240.0:
        _red = _intensity - _si
        _green = _red
        _blue = _intensity + _si2
    elif 240.0 < _hue < 360.0:
        _cosvar = 57.29577951308232 * cos(_huerad - 4.1887902047863905) / (57.29577951308232 * cos(5.235987755982989 - _huerad))
        _red = _intensity + (_si * (1.0 - _cosvar))
        _green = _intensity - _si
        _blue = _intensity + (_si * _cosvar)
    if _red > 255.0:
        _red = 255.0
    if _green > 255.0:
        _green = 255.0
    if _blue > 255.0:
        _blue = 255.0
    if _rgb_float_notation:
        return _red / 255.0, _green / 255.0, _blue / 255.0
    return int(round(_red)), int(round(_green)), int(round(_blue))


# HLS #


def hls2hsv(_hue: float, _light: float, _sat: float) -> tuple:
    """HLS -> HSV.

    >>> hls2hsv(0.1375, 0.497, 0.893)
    (0.1375, 0.9434759640781828, 0.940821)
    """
    _l: float = 2.0 * _light
    _value: float = (_l + _sat * (1.0 - abs(_l - 1.0))) * 0.5
    return _hue, (2.0 * (_value - _light)) / _value, _value


def hls2rgb(_hue: float, _light: float, _sat: float, _rgb_float_notation: bool = True) -> tuple:
    """HLS -> RGB."""
    if _sat == 0.0 and not _rgb_float_notation:
        return int(round(_light * 255.0)), int(round(_light * 255.0)), int(round(_light * 255.0))
    if _sat == 0.0 and _rgb_float_notation:
        return _light, _light, _light
    _m2: float = _light * (1.0 + _sat) if _light <= 0.5 else _light + _sat - (_light * _sat)
    _m1: float = 2.0 * _light - _m2
    if _rgb_float_notation:
        return hue2value(_m1, _m2, _hue + ONE_THIRD), hue2value(_m1, _m2, _hue), hue2value(_m1, _m2, _hue - ONE_THIRD)
    return int(round(hue2value(_m1, _m2, _hue + ONE_THIRD) * 255.0)), int(round(hue2value(_m1, _m2, _hue) * 255.0)), int(round(hue2value(_m1, _m2, _hue - ONE_THIRD) * 255.0))


# HSV #


def hsv2hls(_hue: float, _sat: float, _value: float) -> tuple:
    """HSV -> HLS."""
    _sat2: float = _sat * _value / ((2.0 - _sat) * _value) if (2.0 - _sat) * _value < 1.0 else _sat * _value / (2.0 - (2.0 - _sat) * _value)
    return _hue, (2.0 - _sat) * _value * 0.5, _sat2


def hsv2rgb(_hue: float, _sat: float, _value: float, _rgb_float_notation: bool = True) -> tuple:
    """HSV -> RGB.

    >>> hsv2rgb(0.5, 0.5, 0.5, False)
    (64, 128, 128)
    """
    if _sat == 0.0:
        return _value, _value, _value
    _i: int = int(_hue * 6.0)
    _f: float = (_hue * 6.0) - _i
    _p: float = _value * (1.0 - _sat)
    _i %= 6
    if _i == 0:
        _output: tuple = (_value, _value * (1.0 - _sat * (1.0 - _f)), _p)
    elif _i == 1:
        _output = (_value * (1.0 - _sat * _f), _value, _p)
    elif _i == 2:
        _output = (_p, _value, _value * (1.0 - _sat * (1.0 - _f)))
    elif _i == 3:
        _output = (_p, _value * (1.0 - _sat * _f), _value)
    elif _i == 4:
        _output = (_value * (1.0 - _sat * (1.0 - _f)), _p, _value)
    else:
        _output = (_value, _p, _value * (1.0 - _sat * _f))
    if _rgb_float_notation:
        return _output
    return int(round(_output[0] * 255.0)), int(round(_output[1] * 255.0)), int(round(_output[2] * 255.0))


# HUNTER LAB #


def hunterlab2xyz(_hl: float, _ha: float, _hb: float) -> tuple:
    """Hunter Lab -> XYZ."""
    _y: float = _hl * 0.1
    _x: float = _ha / 17.5 * _y
    _z: float = _hb / 7.0 * _y
    _y *= _y
    _x = (_x + _y) / 1.02
    _z = - (_z - _y) / 0.847
    return _x, _y, _z


# RGB (BYTE-NOTATION & FLOAT-NOTATION) #


def rgb2cmy(_red: Union[float, int], _green: Union[float, int], _blue: Union[float, int], _float_notation: bool = True) -> tuple:
    """RGB -> CMY."""
    if _float_notation:
        return 1.0 - _red, 1.0 - _green, 1.0 - _blue
    return 1.0 - (_red / 255.0), 1.0 - (_green / 255.0), 1.0 - (_blue / 255.0)


def rgb2cmyk(_red: Union[float, int], _green: Union[float, int], _blue: Union[float, int], _float_notation: bool = True) -> tuple:
    """RGB -> CMYK."""
    if not _float_notation:
        _red /= 255.0
        _green /= 255.0
        _blue /= 255.0
    _black: float = 1.0 - max(_red, _green, _blue)
    _cyan: float = 0.0 if _black >= 1.0 else (1.0 - _red - _black) / (1.0 - _black)
    _magenta: float = 0.0 if _black >= 1.0 else (1.0 - _green - _black) / (1.0 - _black)
    _yellow: float = 0.0 if _black >= 1.0 else (1.0 - _blue - _black) / (1.0 - _black)
    return _cyan, _magenta, _yellow, _black


def rgb2hex(_red: Union[float, int], _green: Union[float, int], _blue: Union[float, int], _float_notation: bool = True) -> tuple:
    """RGB -> hex-notation.

    >>> rgb2hex(0, 255, 255, False)
    ('0x0', 'ff', 'ff')
    >>> rgb2hex(0.0, 1.0, 1.0, True)
    ('0x0', 'ff', 'ff')
    """
    if _float_notation:
        _red *= 255.0
        _green *= 255.0
        _blue *= 255.0
    ret_r: str = hex(round(_red)) if _red < 255.0 else r'ff'
    ret_g: str = hex(round(_green)) if _green < 255.0 else r'ff'
    ret_b: str = hex(round(_blue)) if _blue < 255.0 else r'ff'
    return ret_r, ret_g, ret_b


def rgb2hls(_red: Union[float, int], _green: Union[float, int], _blue: Union[float, int], _float_notation: bool = True) -> tuple:
    """RGB -> HLS."""
    if not _float_notation:
        _red /= 255.0
        _green /= 255.0
        _blue /= 255.0
    maxc: float = max(_red, _green, _blue)
    minc: float = min(_red, _green, _blue)
    _light: float = (minc + maxc) / 2.0
    if minc == maxc:
        return 0.0, _light, 0.0
    maxc_minc: float = maxc - minc
    _sat: float = maxc_minc / (maxc + minc) if _light <= 0.5 else maxc_minc / (2.001 - maxc_minc)
    if _red == maxc:
        _hue = ((maxc - _blue) / maxc_minc) - ((maxc - _green) / maxc_minc)
    elif _green == maxc:
        _hue = 2.0 + ((maxc - _red) / maxc_minc) - ((maxc - _blue) / maxc_minc)
    else:
        _hue = 4.0 + ((maxc - _green) / maxc_minc) - ((maxc - _red) / maxc_minc)
    return (_hue / 6.0) % 1.0, _light, _sat


def rgb2hsi(_red: Union[float, int], _green: Union[float, int], _blue: Union[float, int], _float_notation: bool = True) -> tuple:  # noqa: R701
    """RGB -> HSI.

    >>> rgb2hsi(255, 0, 255, False)
    (300.0, 1.0, 170.0)
    >>> rgb2hsi(html2rgb('#FF00FF')[0], html2rgb('#FF00FF')[1], html2rgb('#FF00FF')[2], False)
    (300.0, 1.0, 170.0)
    """
    if _float_notation:
        _red = round(_red * 255.0, 6)
        _green = round(_green * 255.0, 6)
        _blue = round(_blue * 255.0, 6)
    if isinstance(_red, str) or _red < 0.0:
        _red = 0.0
    if isinstance(_green, str) or _green < 0.0:
        _green = 0.0
    if isinstance(_blue, str) or _green < 0.0:
        _blue = 0.0
    _rgb_added: float = _red + _green + _blue
    _intensity: float = _rgb_added / 3.0
    _rgbmin: float = min(_red, _green, _blue)
    _sat: float = 0.0 if _rgb_added <= 0.0 else 1.0 - _rgbmin * (3.0 / _rgb_added)
    _x0: float = 0.0 if _red == _green and _green == _blue else sqrt(((_red - _green) * (_red - _green)) + ((_red - _blue) * (_green - _blue)))
    if _x0 == 0 or _rgb_added == 0.0:
        _hue: float = 0.0
    elif _green >= _blue:
        _hue = acos((0.5 * ((_red - _green) + (_red - _blue)) / _x0))
    else:
        _hue = 6.283185307179586 - acos((0.5 * ((_red - _green) + (_red - _blue)) / _x0))
    return round(_hue * 180.0 / 3.141592653589793, 10), round(_sat, 9), round(_intensity, 9)


def rgb2hsv(_red: Union[float, int], _green: Union[float, int], _blue: Union[float, int], _float_notation: bool = True) -> tuple:
    """RGB -> HSV.

    >>> rgb2hsv(255, 0, 255, False)
    (0.833333333, 1.0, 1.0)
    """
    if not _float_notation:
        _red /= 255.0
        _green /= 255.0
        _blue /= 255.0
    maxc: float = max(_red, _green, _blue)
    minc: float = min(_red, _green, _blue)
    if minc == maxc:
        return 0.0, 0.0, maxc
    minmaxc: float = maxc - minc
    _rc: float = (maxc - _red) / minmaxc
    _gc: float = (maxc - _green) / minmaxc
    _bc: float = (maxc - _blue) / minmaxc
    _hue = ((_bc - _gc if _red == maxc else 2.0 + _rc - _bc if _green == maxc else 4.0 + _gc - _rc) * 0.16666666666666666) % 1.0
    return round(_hue, 9), round(minmaxc / maxc, 9), round(maxc, 9)


def rgb2html(_red: Union[float, int], _green: Union[float, int], _blue: Union[float, int], _float_notation: bool = True, _uppercase: bool = False) -> str:
    """RGB -> HTML-notation.

    >>> rgb2html(1.0, 1.0, 1.0)
    '#ffffff'
    >>> rgb2html(255, 255, 255, False, True)
    '#FFFFFF'
    """
    if _float_notation:
        _red *= 255.0
        _green *= 255.0
        _blue *= 255.0
    _output: str = r'#' + hex(round(_red))[2:4] + hex(round(_green))[2:4] + hex(round(_blue))[2:4]
    if _uppercase:
        return _output.upper()
    return _output


def rgb2xyz(_red: Union[float, int], _green: Union[float, int], _blue: Union[float, int], _float_notation: bool = True) -> tuple:
    """RGB -> XYZ."""
    if not _float_notation:
        _red = _red / 255.0
        _green = _green / 255.0
        _blue = _blue / 255.0
    _red = ((_red + 0.055) / 1.055) ** 2.4 if _red > 0.04045 else _red / 12.92
    _green = ((_green + 0.055) / 1.055) ** 2.4 if _green > 0.04045 else _green / 12.92
    _blue = ((_blue + 0.055) / 1.055) ** 2.4 if _blue > 0.04045 else _blue / 12.92
    _red *= 100.0
    _green *= 100.0
    _blue *= 100.0
    _x: float = _red * 0.4124 + _green * 0.3576 + _blue * 0.1805
    _y: float = _red * 0.2126 + _green * 0.7152 + _blue * 0.0722
    _z: float = _red * 0.0193 + _green * 0.1192 + _blue * 0.9505
    return _x, _y, _z


def rgb2yiq(_red: Union[float, int], _green: Union[float, int], _blue: Union[float, int], _float_notation: bool = True) -> tuple:
    """RGB -> YIQ."""
    if not _float_notation:
        _red = _red / 255.0
        _green = _green / 255.0
        _blue = _blue / 255.0
    _y: float = 0.30 * _red + 0.59 * _green + 0.11 * _blue
    _i: float = 0.74 * (_red - _y) - 0.27 * (_blue - _y)
    _q: float = 0.48 * (_red - _y) + 0.41 * (_blue - _y)
    return round(_y, 9), round(_i, 9), round(_q, 9)


# RGB & RGBA #


def rgb2rgba(rgb: tuple, _float_notation: bool = True) -> tuple:
    """RGB (byte-notation/float-notation) -> RGBA."""
    return (float(rgb[0]), float(rgb[1]), float(rgb[2]), 1.0000) if _float_notation else (int(rgb[0]), int(rgb[1]), int(rgb[2]), 255)


def rgba2rgb(rgba: tuple) -> tuple:
    """RGBA -> RGB."""
    return rgba[0], rgba[1], rgba[2]


# RGB FLOATS & RGB INTEGERS (BYTE ARRAY) #


def rgb2rgbf(_red: int, _green: int, _blue: int) -> tuple:
    """RGB byte-notation -> RGB float-notation."""
    return _red / 255, _green / 255, _blue / 255


def rgbf2rgb(_red: float, _green: float, _blue: float) -> tuple:
    """RGB float-notation -> RGB byte-notation."""
    return int(_red * 255.0), int(_green * 255.0), int(_blue * 255.0)


def roundrgb(_red: float, _green: float, _blue: float) -> tuple:
    """Round RGB byte-notation float-points (like 254.649915) to byte-notation integers (255)."""
    return int(_red), int(_green), int(_blue)


# RYB #


def ryb2rgb(_red: float, _yellow: float, _blue: float, _float_notation: bool = True) -> tuple:
    """Convert RYB -> RGB (both will use the same notation).

    >>> ryb2rgb(255, 128, 0, False)
    (255, 64, 0)
    >>> ryb2rgb(98, 182, 17, False)
    (252, 203, 34)
    """
    if not _float_notation:
        _red /= 255.0
        _yellow /= 255.0
        _blue /= 255.0
    _red2: float = (3.0 - 2.0 * _red) * _red * _red
    _yellow2: float = (3.0 - 2.0 * _yellow) * _yellow * _yellow
    _blue2: float = (3.0 - 2.0 * _blue) * _blue * _blue
    # Red
    _x0: float = 1.0 + _blue2 * -0.837
    _x2: float = 1.0 + _blue2 * -0.5
    _x3: float = 1.0 + _blue2 * -0.8
    _y0: float = _x0 + _yellow2 * ((1.0 - _blue2) - _x0)
    _y1: float = _x2 + _yellow2 * (_x3 - _x2)
    rgb_red: float = _y0 + _red2 * (_y1 - _y0)
    # Green
    _x0 = 1.0 + _blue2 * -0.627
    _x1: float = 1.0 + _blue2 * -0.34
    _x3 = 0.5 + _blue2 * -0.406
    _y0 = _x0 + _yellow2 * (_x1 - _x0)
    rgb_green: float = _y0 + _red2 * (_yellow2 * _x3 - _y0)
    # Blue
    _x0 = 1.0 + _blue2 * -0.4
    _x2 = _blue2 * 0.5
    _y0 = _x0 + _yellow2 * (_blue2 * 0.2 - _x0)
    _y1 = _x2 + _yellow2 * (0.0 - _x2)
    rgb_blue: float = _y0 + _red2 * (_y1 - _y0)
    if _float_notation:
        return (rgb_red, rgb_green, rgb_blue)
    return (int(rgb_red * 255.0), int(rgb_green * 255.0), int(rgb_blue * 255.0))


# XYZ #


def xyz2hunterlab(_x: float, _y: float, _z: float) -> tuple:
    """XYZ -> Hunter Lab."""
    sqrt_y: float = sqrt(_y)
    _hla: float = 17.5 * (((1.02 * _x) - _y) / sqrt_y)
    _hlb: float = 7.0 * ((_y - (0.847 * _z)) / sqrt_y)
    return 10.0 * sqrt_y, _hla, _hlb


def xyz2rgb(_x: float, _y: float, _z: float, _rgb_float_notation: bool = True) -> tuple:
    """XYZ -> RGB."""
    _x *= 0.01
    _y *= 0.01
    _z *= 0.01
    _red: float = _x * 3.2406 + _y * -1.5372 + _z * -0.4986
    _green: float = _x * -0.9689 + _y * 1.8758 + _z * 0.0415
    _blue: float = _x * 0.0557 + _y * -0.2040 + _z * 1.0570
    _red = 1.055 * (_red ** 0.4166667) - 0.055 if _red > 0.0031308 else 12.92 * _red
    _green = 1.055 * (_green ** 0.4166667) - 0.055 if _green > 0.0031308 else 12.92 * _green
    _blue = 1.055 * (_blue ** 0.4166667) - 0.055 if _blue > 0.0031308 else 12.92 * _blue
    if _rgb_float_notation:
        return _red, _green, _blue
    return int(round(_red * 255.0)), int(round(_green * 255.0)), int(round(_blue * 255.0))


# YIQ #


def yiq2rgb(_yellow: float, _in_phase: float, _quadrature: float, _rgb_float_notation: bool = True) -> tuple:
    """YIQ -> RGB."""
    _red: float = _yellow + 0.9468822170900693 * _in_phase + 0.6235565819861433 * _quadrature
    _green: float = _yellow - 0.27478764629897834 * _in_phase - 0.6356910791873801 * _quadrature
    _blue: float = _yellow - 1.1085450346420322 * _in_phase + 1.7090069284064666 * _quadrature
    if _red < 0.0:
        _red = 0.0
    elif _red > 1.0:
        _red = 1.0
    if _green < 0.0:
        _green = 0.0
    elif _green > 1.0:
        _green = 1.0
    if _blue < 0.0:
        _blue = 0.0
    elif _blue > 1.0:
        _blue = 1.0
    if _rgb_float_notation:
        return _red, _green, _blue
    return int(round(_red * 255.0)), int(round(_green * 255.0)), int(round(_blue * 255.0))

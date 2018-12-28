#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Color manipulation

@file color.py
@package pybooster.color
@version 2018.12.28
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


# pylint: disable=C0103


from math import acos, cos, sqrt


__all__: list = [
    # CMY #
    r'cmy2cmyk',
    r'cmy2rgb',
    # CMYK #
    r'cmyk2cmy',
    r'cmyk2rgb',
    r'cmyk2rgbbyte',
    # GETVALUE #
    r'getvalue',
    # HSI #
    r'hsi2rgb',
    r'hsi2rgbbyte',
    # HLS #
    r'hls2hsv',
    r'hls2rgb',
    # HSV #
    r'hsv2hls',
    r'hsv2rgb',
    # HUE #
    r'huedegree2huefloat',
    r'huefloat2huedegree',
    # HTML #
    r'html2hex',
    r'html2rgb',
    r'shorthand2sixdigit',
    # HUNTERLAB #
    r'hunterlab2xyz',
    # RGB #
    r'rgb2cmy',
    r'rgb2cmyk',
    r'rgb2hex',
    r'rgb2hls',
    r'rgb2hsi',
    r'rgb2hsv',
    r'rgb2html',
    r'rgb2xyz',
    r'rgb2yiq',
    r'rgb2rgba',
    r'rgba2rgb',
    r'rgb2rgbf',
    r'rgbf2rgb',
    # ROUND #
    r'roundrgb',
    # XYZ #
    r'xyz2hunterlab',
    r'xyz2rgb',
    r'xyz2rgb_int',
    # YIQ #
    r'yiq2rgb'
]


# FUNCTIONS #


def getvalue(m1: float, m2: float, hue: float) -> float:
    """Get value from hue"""
    hue %= 1.0
    if hue < 0.166666666666667:
        return m1 + (m2 - m1) * hue * 6.0
    if hue < 0.5:
        return m2
    if hue < 0.666666666666667:
        return m1 + (m2 - m1) * (0.666666666666667 - hue) * 6.0
    return m1


# CMY #


def cmy2cmyk(_cyan: float, _magenta: float, _yellow: float) -> tuple:
    """CMY -> CMYK"""
    _black: float = _yellow if _yellow < 1.0 else _magenta if _magenta < 1.0 else _cyan if _cyan < 1.0 else 1.0
    if _black == 1.0:
        return 0.0, 0.0, 0.0, _black
    return (_cyan - _black) / (1.0 - _black), (_magenta - _black) / (1.0 - _black), (_yellow - _black) / (1.0 - _black), _black


def cmy2rgb(_c: float, _m: float, _y: float, _out_float: bool = True) -> tuple:
    """CMY -> RGB"""
    if _out_float:
        return 1.0 - _c, 1.0 - _m, 1.0 - _y
    return (1.0 - _c) * 255.0, (1.0 - _m) * 255.0, (1.0 - _y) * 255.0


# CMYK #


def cmyk2cmy(_cyan: float, _magenta: float, _yellow: float, _black: float) -> tuple:
    """CMYK -> CMY"""
    return _cyan * (1.0 - _black) + _black, _magenta * (1.0 - _black) + _black, _yellow * (1.0 - _black) + _black


def cmyk2rgb(_cyan: float, _magenta: float, _yellow: float, _black: float) -> tuple:
    """CMYK -> RGB"""
    return (1.0 - _cyan) * (1.0 - _black), (1.0 - _magenta) * (1.0 - _black), (1.0 - _yellow) * (1.0 - _black)


def cmyk2rgbbyte(_cyan: float, _magenta: float, _yellow: float, _black: float) -> tuple:
    """CMYK -> RGB byte-array"""
    _red: float = (1.0 - _cyan) * (1.0 - _black)
    _green: float = (1.0 - _magenta) * (1.0 - _black)
    _blue: float = (1.0 - _yellow) * (1.0 - _black)
    return int(255.0 * _red), int(255.0 * _green), int(255.0 * _blue)


# HSI #


def hsi2rgb(_hue: float, _sat: float, _intensity: float) -> tuple:
    """HSI -> RGB"""
    _huerad: float = 0.017453 * _hue  # Convert degrees to radians
    _si: float = _sat * _intensity
    _si2: float = _si * 2.0
    if _hue == 0.0 or _hue >= 360.0:
        _red = _intensity + _si2
        _green = _intensity - _si
        _blue = _green
    elif 0.0 < _hue < 120.0:
        _cosvar = round(round(57.295828 * cos(_huerad), 6) / (57.295828 * cos(1.04718 - _huerad)), 6)
        _red = _intensity + (_si * _cosvar)
        _green = _intensity + (_si * (1 - _cosvar))
        _blue = _intensity - _si
    elif _hue == 120.0:
        _red = _intensity - _si
        _green = _intensity + _si2
        _blue = _red
    elif 120.0 < _hue < 240.0:
        _red = _intensity - _si
        _cosvar = round((57.295828 * cos(_huerad - 2.09436)) / (57.295828 * cos(3.1415926535 - _huerad)), 6)
        _green = _intensity + (_si * _cosvar)
        _blue = _intensity + (_si * (1 - _cosvar))
    elif _hue == 240.0:
        _red = _intensity - _si
        _green = _red
        _blue = _intensity + _si2
    elif 240.0 < _hue < 360.0:
        _cosvar = round((round(57.295828 * cos(_huerad - 4.18872), 6)) / (57.295828 * cos(5.2359 - _huerad)), 6)
        _red = _intensity + (_si * (1 - _cosvar))
        _green = _intensity - _si
        _blue = _intensity + (_si * _cosvar)
    _red = round(_red, 6)
    _green = round(_green, 6)
    _blue = round(_blue, 6)
    if _red > 255.0:
        _red = 255.0
    if _green > 255.0:
        _green = 255.0
    if _blue > 255.0:
        _blue = 255.0
    return _red / 255.0, _green / 255.0, _blue / 255.0


def hsi2rgbbyte(_hue: float, _sat: float, _intensity: float) -> tuple:
    """HSI -> RGB byte array"""
    _huerad: float = 0.017453 * _hue  # Convert degrees to radians
    _si: float = _sat * _intensity
    _si2: float = _si * 2.0
    if _hue == 0.0 or _hue >= 360.0:
        _red = _intensity + _si2
        _green = _intensity - _si
        _blue = _green
    elif 0.0 < _hue < 120.0:
        _cosvar = round(round(57.295828 * cos(_huerad), 6) / (57.295828 * cos(1.04718 - _huerad)), 6)
        _red = _intensity + (_si * _cosvar)
        _green = _intensity + (_si * (1 - _cosvar))
        _blue = _intensity - _si
    elif _hue == 120.0:
        _red = _intensity - _si
        _green = _intensity + _si2
        _blue = _red
    elif 120.0 < _hue < 240.0:
        _red = _intensity - _si
        _cosvar = round((57.295828 * cos(_huerad - 2.09436)) / (57.295828 * cos(3.1415926535 - _huerad)), 6)
        _green = _intensity + (_si * _cosvar)
        _blue = _intensity + (_si * (1 - _cosvar))
    elif _hue == 240.0:
        _red = _intensity - _si
        _green = _red
        _blue = _intensity + _si2
    elif 240.0 < _hue < 360.0:
        _cosvar = round(round(57.295828 * cos(_huerad - 4.18872), 6) / (57.295828 * cos(5.2359 - _huerad)), 6)
        _red = _intensity + (_si * (1 - _cosvar))
        _green = _intensity - _si
        _blue = _intensity + (_si * _cosvar)
    _red = round(_red, 6)
    _green = round(_green, 6)
    _blue = round(_blue, 6)
    if _red > 255.0:
        _red = 255.0
    if _green > 255.0:
        _green = 255.0
    if _blue > 255.0:
        _blue = 255.0
    return _red, _green, _blue


# HLS #


def hls2hsv(hue: float, light: float, sat: float) -> tuple:
    """HLS -> HSV"""
    _l: float = 2.0 * light
    v: float = (_l + sat * (1.0 - abs(_l - 1.0))) * 0.5
    return hue, (2.0 * (v - light)) / v, v


def hls2rgb(h: float, _l: float, s: float) -> tuple:
    """HLS -> RGB"""
    if s == 0.0:
        return _l, _l, _l
    m2: float = _l * (1.0 + s) if _l <= 0.5 else _l + s - (_l * s)
    m1: float = 2.0 * _l - m2
    return (getvalue(m1, m2, h + 0.333333333333333), getvalue(m1, m2, h), getvalue(m1, m2, h - 0.333333333333333))


# HSV #


def hsv2hls(_hue: float, _sat: float, _value: float) -> tuple:
    """HSV -> HLS"""
    _s: float = _sat * _value / ((2.0 - _sat) * _value) if (2.0 - _sat) * _value < 1.0 else _sat * _value / (2.0 - (2.0 - _sat) * _value)
    return _hue, (2.0 - _sat) * _value * 0.5, _s


def hsv2rgb(h: float, s: float, v: float) -> tuple:
    """HSV -> RGB"""
    if s == 0.0:
        return v, v, v
    i: int = int(h * 6.0)
    f: float = (h * 6.0) - i
    p: float = v * (1.0 - s)
    i %= 6
    if i == 0:
        return v, v * (1.0 - s * (1.0 - f)), p
    if i == 1:
        return v * (1.0 - s * f), v, p
    if i == 2:
        return p, v, v * (1.0 - s * (1.0 - f))
    if i == 3:
        return p, v * (1.0 - s * f), v
    if i == 4:
        return v * (1.0 - s * (1.0 - f)), p, v
    return v, p, v * (1.0 - s * f)


# HUE CONVERSIONS #


def huedegree2huefloat(_hue: int) -> float:
    """Hue in degrees -> Hue as a float"""
    return float(_hue) / 360


def huefloat2huedegree(_hue: float) -> int:
    """Hue as a float -> Hue in degrees"""
    return int(_hue * 360)


# HTML (WEB COLORS) #


def html2hex(_html: str) -> tuple:
    """HTML notation -> hex notation"""
    return _html[1:3], _html[3:5], _html[-2:]


def html2rgb(_html: str) -> tuple:
    """HTML notation (#f6a797) -> RGB (byte array - 0-255)"""
    return int(_html[1:3], 16), int(_html[3:5], 16), int(_html[-2:], 16)


def shorthand2sixdigit(_shorthand: str) -> str:
    """Shorthand HTML notation (#789) -> 6-digit HTML notation (#778899)"""
    if r'#' in _shorthand:
        _red = _shorthand[1] + _shorthand[1]
        _green = _shorthand[2] + _shorthand[2]
        _blue = _shorthand[3] + _shorthand[3]
    else:
        _red = _shorthand[0] + _shorthand[0]
        _green = _shorthand[1] + _shorthand[1]
        _blue = _shorthand[2] + _shorthand[2]
    return r'#' + str(_red) + str(_green) + str(_blue)


# HUNTER LAB #


def hunterlab2xyz(_hl: float, _ha: float, _hb: float) -> tuple:
    """Hunter Lab -> XYZ"""
    _y: float = _hl * 0.1
    _x: float = _ha / 17.5 * _y
    _z: float = _hb / 7.0 * _y
    _y *= _y
    _x = (_x + _y) / 1.02
    _z = - (_z - _y) / 0.847
    return _x, _y, _z


# RGB #


def rgb2cmy(_red, _green, _blue, _float: bool = True) -> tuple:
    """RGB -> CMY"""
    if _float:
        return 1.0 - _red, 1.0 - _green, 1.0 - _blue
    return 1.0 - (_red / 255.0), 1.0 - (_green / 255.0), 1.0 - (_blue / 255.0)


# RGB (AS FLOAT) #


def rgb2cmyk(r: float, g: float, b: float) -> tuple:
    """RGB -> CMYK"""
    _black: float = 1.0 - max(r, g, b)
    _cyan: float = (1.0 - r - _black) / (1.0 - _black)
    _magenta: float = (1.0 - g - _black) / (1.0 - _black)
    _yellow: float = (1.0 - b - _black) / (1.0 - _black)
    return _cyan, _magenta, _yellow, _black


def rgb2hex(r: float, g: float, b: float) -> tuple:
    """RGB (byte array - 0-255) -> hex notation"""
    if r < 1.0 and g < 1.0 and b < 1.0:
        r *= 255.0
        g *= 255.0
        b *= 255.0
    elif r == 1.0 and g == 1.0 and b == 1.0:
        return r'ff', r'ff', r'ff'
    return hex(round(r)), hex(round(g)), hex(round(b))


def rgb2hls(r: float, g: float, b: float) -> tuple:
    """RGB -> HLS"""
    maxc: float = max(r, g, b)
    minc: float = min(r, g, b)
    _l: float = (minc + maxc) * 0.5
    if minc == maxc:
        return 0.0, _l, 0.0
    maxc_minc: float = maxc - minc
    s: float = maxc_minc / (maxc + minc) if _l <= 0.5 else maxc_minc / (2.0 - maxc_minc)
    if r == maxc:
        h = ((maxc - b) / maxc_minc) - ((maxc - g) / maxc_minc)
    elif g == maxc:
        h = 2.0 + ((maxc - r) / maxc_minc) - ((maxc - b) / maxc_minc)
    else:
        h = 4.0 + ((maxc - g) / maxc_minc) - ((maxc - r) / maxc_minc)
    return (h * 0.166666667) % 1.0, _l, s


def rgb2hsi(_red: float, _green: float, _blue: float) -> tuple:
    """RGB -> HSI"""
    _red = round(_red * 255.0, 6)
    _green = round(_green * 255.0, 6)
    _blue = round(_blue * 255.0, 6)
    if isinstance(_red, str) or _red < 0.0:
        _red = 0.0
    if isinstance(_green, str) or _green < 0.0:
        _green = 0.0
    if isinstance(_blue, str) or _green < 0.0:
        _blue = 0.0
    _rgbmin: float = min(_red, _green, _blue)
    _rgbplus: float = _red + _green + _blue
    _var0: float = (_red * _green) - (_red * _blue) - (_green * _blue)
    _var1: float = _red - (_green * 0.5) - (_blue * 0.5)
    _var2: float = _var1 / round(sqrt((_red * _red) + (_green * _green) + (_blue * _blue) - _var0), 6)
    _intensity: float = (_red + _green + _blue) * 0.333333333333333
    if _rgbplus == 765:
        return 0.0, 0.0, round(_intensity, 6)
    if _intensity > 0.0:
        _sat = 1.0 - (_rgbmin / _intensity)
    elif _intensity == 0.0:
        _sat = 0.0
    if _green >= _blue:
        _hue = 57.2958279088 * acos(_var2)
    elif _blue > _green:
        _hue = 360.0 - (57.2958279088 * acos(_var2))
    return round(_hue, 6), round(_sat, 6), round(_intensity, 6)


def rgb2hsv(_red: float, _green: float, _blue: float) -> tuple:
    """RGB -> HSV"""
    maxc: float = max(_red, _green, _blue)
    minc: float = min(_red, _green, _blue)
    if minc == maxc:
        return 0.0, 0.0, maxc
    minmaxc: float = maxc - minc
    rc: float = (maxc - _red) / minmaxc
    gc: float = (maxc - _green) / minmaxc
    bc: float = (maxc - _blue) / minmaxc
    _hue = ((bc - gc if _red == maxc else 2.0 + rc - bc if _green == maxc else 4.0 + gc - rc) * 0.1666666667) % 1.0
    return _hue, minmaxc / maxc, maxc


def rgb2html(_red: float, _green: float, _blue: float) -> str:
    """RGB -> HTML notation"""
    return r'#' + hex(round(_red))[2:4] + hex(round(_green))[2:4] + hex(round(_blue))[2:4]


def rgb2xyz(_red: float, _green: float, _blue: float, _float: bool = True) -> tuple:
    """RGB -> XYZ"""
    if not _float:
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


def rgb2yiq(_red: float, _green: float, _blue: float) -> tuple:
    """RGB -> YIQ"""
    _y: float = 0.30 * _red + 0.59 * _green + 0.11 * _blue
    _i: float = 0.74 * (_red - _y) - 0.27 * (_blue - _y)
    _q: float = 0.48 * (_red - _y) + 0.41 * (_blue - _y)
    return _y, _i, _q


# RGB & RGBA #


def rgb2rgba(_red: float, _green: float, _blue: float, _bytearray: bool = False) -> tuple:
    """RGB -> RGBA"""
    return (_red, _green, _blue, 1.0000) if _bytearray is False else (_red, _green, _blue, 255.0)


def rgba2rgb(_red: float, _green: float, _blue: float) -> tuple:
    """RGBA -> RGB"""
    return _red, _green, _blue


# RGB FLOATS & RGB INTEGERS (BYTE ARRAY) #


def rgb2rgbf(_red: float, _green: float, _blue: float) -> tuple:
    """RGB Integer -> RGB Float"""
    return _red / 255.0, _green / 255.0, _blue / 255.0


def rgbf2rgb(_red: float, _green: float, _blue: float) -> tuple:
    """RGB Float -> RGB Integer"""
    return _red * 255.0, _green * 255.0, _blue * 255.0


def roundrgb(_r: float, _g: float, _b: float) -> tuple:
    """Round RGB float-points (like 245.649915) to integer (246)"""
    return round(_r), round(_g), round(_b)


# XYZ #


def xyz2hunterlab(_x: float, _y: float, _z: float) -> tuple:
    """XYZ -> Hunter Lab"""
    sqrt_y: float = sqrt(_y)
    _hla: float = 17.5 * (((1.02 * _x) - _y) / sqrt_y)
    _hlb: float = 7.0 * ((_y - (0.847 * _z)) / sqrt_y)
    return 10.0 * sqrt_y, _hla, _hlb


def xyz2rgb(_x: float, _y: float, _z: float) -> tuple:
    """XYZ -> RGB"""
    _x *= 0.01
    _y *= 0.01
    _z *= 0.01
    _red: float = _x * 3.2406 + _y * -1.5372 + _z * -0.4986
    _green: float = _x * -0.9689 + _y * 1.8758 + _z * 0.0415
    _blue: float = _x * 0.0557 + _y * -0.2040 + _z * 1.0570
    _red = 1.055 * (_red ** 0.4166667) - 0.055 if _red > 0.0031308 else 12.92 * _red
    _green = 1.055 * (_green ** 0.4166667) - 0.055 if _green > 0.0031308 else 12.92 * _green
    _blue = 1.055 * (_blue ** 0.4166667) - 0.055 if _blue > 0.0031308 else 12.92 * _blue
    return _red, _green, _blue


def xyz2rgb_int(_x: float, _y: float, _z: float) -> tuple:
    """XYZ -> RGB as an integer"""
    _x *= 0.01
    _y *= 0.01
    _z *= 0.01
    _red: float = _x * 3.2406 + _y * -1.5372 + _z * -0.4986
    _green: float = _x * -0.9689 + _y * 1.8758 + _z * 0.0415
    _blue: float = _x * 0.0557 + _y * -0.2040 + _z * 1.0570
    _red = 1.055 * (_red ** 0.4166667) - 0.055 if _red > 0.0031308 else 12.92 * _red
    _green = 1.055 * (_green ** 0.4166667) - 0.055 if _green > 0.0031308 else 12.92 * _green
    _blue = 1.055 * (_blue ** 0.4166667) - 0.055 if _blue > 0.0031308 else 12.92 * _blue
    return _red * 255.0, _green * 255.0, _blue * 255.0


# YIQ #


def yiq2rgb(_y: float, _i: float, _q: float) -> tuple:
    """YIQ -> RGB"""
    _red: float = _y + 0.9468822170900693 * _i + 0.6235565819861433 * _q
    _green: float = _y - 0.27478764629897834 * _i - 0.6356910791873801 * _q
    _blue: float = _y - 1.1085450346420322 * _i + 1.7090069284064666 * _q
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
    return _red, _green, _blue

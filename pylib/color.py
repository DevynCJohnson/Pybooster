#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Color manipulation

@file color.py
@package pybooster.color
@version 2018.10.02
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
    hue: float = hue % 1.0
    if hue < 0.166666666666667:
        return m1 + (m2 - m1) * hue * 6.0
    elif hue < 0.5:
        return m2
    elif hue < 0.666666666666667:
        return m1 + (m2 - m1) * (0.666666666666667 - hue) * 6.0
    return m1


# CMY #


def cmy2cmyk(_cyan: float, _magenta: float, _yellow: float) -> tuple:
    """CMY -> CMYK"""
    _black: float = 1.0
    if _cyan < 1.0:
        _black = _cyan
    if _magenta < 1.0:
        _black = _magenta
    if _yellow < 1.0:
        _black = _yellow
    if _black == 1.0:
        _cyan = 0.0
        _magenta = 0.0
        _yellow = 0.0
    else:
        _cyan = (_cyan - _black) / (1.0 - _black)
        _magenta = (_magenta - _black) / (1.0 - _black)
        _yellow = (_yellow - _black) / (1.0 - _black)
    return _cyan, _magenta, _yellow, _black


def cmy2rgb(_c: float, _m: float, _y: float, _out_float: bool = True) -> tuple:
    """CMY -> RGB"""
    _red: float = 1.0 - _c
    _green: float = 1.0 - _m
    _blue: float = 1.0 - _y
    if _out_float:
        return _red, _green, _blue
    return _red * 255.0, _green * 255.0, _blue * 255.0


# CMYK #


def cmyk2cmy(_cyan: float, _magenta: float, _yellow: float, _black: float) -> tuple:
    """CMYK -> CMY"""
    _cyan = _cyan * (1.0 - _black) + _black
    _magenta = _magenta * (1.0 - _black) + _black
    _yellow = _yellow * (1.0 - _black) + _black
    return _cyan, _magenta, _yellow


def cmyk2rgb(_cyan: float, _magenta: float, _yellow: float, _black: float) -> tuple:
    """CMYK -> RGB"""
    _red = (1.0 - _cyan) * (1.0 - _black)
    _green = (1.0 - _magenta) * (1.0 - _black)
    _blue = (1.0 - _yellow) * (1.0 - _black)
    return _red, _green, _blue


def cmyk2rgbbyte(_cyan: float, _magenta: float, _yellow: float, _black: float) -> tuple:
    """CMYK -> RGB byte-array"""
    _red = (1.0 - _cyan) * (1.0 - _black)
    _green = (1.0 - _magenta) * (1.0 - _black)
    _blue = (1.0 - _yellow) * (1.0 - _black)
    return int(255.0 * _red), int(255.0 * _green), int(255.0 * _blue)


# HSI #


def hsi2rgb(_hue: float, _sat: float, _intensity: float) -> tuple:
    """HSI -> RGB"""
    _radconv: float = 57.295828
    _degconv: float = 0.017453
    _huerad: float = _degconv * _hue  # Convert degrees to radians
    _si: float = _sat * _intensity
    _si2: float = _sat * _intensity * 2.0
    if _hue == 0.0 or _hue >= 360.0:
        _red = _intensity + _si2
        _green = _intensity - _si
        _blue = _intensity - _si
    elif 0.0 < _hue < 120.0:
        _var1 = _degconv * 60.0
        _var2 = round(_radconv * cos(_huerad), 6)
        _cosvar = round(_var2 / (_radconv * cos(_var1 - _huerad)), 6)
        _red = _intensity + (_si * _cosvar)
        _green = _intensity + (_si * (1 - _cosvar))
        _blue = _intensity - _si
    elif _hue == 120.0:
        _red = _intensity - _si
        _green = _intensity + _si2
        _blue = _intensity - _si
    elif 120.0 < _hue < 240.0:
        _var1 = _degconv * 120.0
        _var2 = _degconv * 180.0
        _red = _intensity - _si
        _var3 = _radconv * cos(_huerad - _var1)
        _cosvar = round(_var3 / (_radconv * cos(_var2 - _huerad)), 6)
        _green = _intensity + (_si * _cosvar)
        _blue = _intensity + (_si * (1 - _cosvar))
    elif _hue == 240.0:
        _red = _intensity - _si
        _green = _intensity - _si
        _blue = _intensity + _si2
    elif 240.0 < _hue < 360.0:
        _var1 = _degconv * 240.0
        _var2 = _degconv * 300.0
        _var3 = round(_radconv * cos(_huerad - _var1), 6)
        _cosvar = round(_var3 / (_radconv * cos(_var2 - _huerad)), 6)
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
    _radconv: float = 57.295828
    _degconv: float = 0.017453
    _huerad: float = _degconv * _hue  # Convert degrees to radians
    _si: float = _sat * _intensity
    _si2: float = _sat * _intensity * 2.0
    if _hue == 0.0 or _hue >= 360.0:
        _red = _intensity + _si2
        _green = _intensity - _si
        _blue = _intensity - _si
    elif 0.0 < _hue < 120.0:
        _var1 = _degconv * 60.0
        _var2 = round(_radconv * cos(_huerad), 6)
        _cosvar = round(_var2 / (_radconv * cos(_var1 - _huerad)), 6)
        _red = _intensity + (_si * _cosvar)
        _green = _intensity + (_si * (1 - _cosvar))
        _blue = _intensity - _si
    elif _hue == 120.0:
        _red = _intensity - _si
        _green = _intensity + _si2
        _blue = _intensity - _si
    elif 120.0 < _hue < 240.0:
        _var1 = _degconv * 120.0
        _var2 = _degconv * 180.0
        _red = _intensity - _si
        _var3 = _radconv * cos(_huerad - _var1)
        _cosvar = round(_var3 / (_radconv * cos(_var2 - _huerad)), 6)
        _green = _intensity + (_si * _cosvar)
        _blue = _intensity + (_si * (1 - _cosvar))
    elif _hue == 240.0:
        _red = _intensity - _si
        _green = _intensity - _si
        _blue = _intensity + _si2
    elif 240.0 < _hue < 360.0:
        _var1 = _degconv * 240.0
        _var2 = _degconv * 300.0
        _var3 = round(_radconv * cos(_huerad - _var1), 6)
        _cosvar = round(_var3 / (_radconv * cos(_var2 - _huerad)), 6)
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
    _var: float = 1.0 - abs(_l - 1.0)
    v: float = (_l + sat * _var) * 0.5
    s: float = (2.0 * (v - light)) / v
    return hue, s, v


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
    if (2.0 - _sat) * _value < 1.0:
        _s = _sat * _value / ((2.0 - _sat) * _value)
    else:
        _s = _sat * _value / (2.0 - (2.0 - _sat) * _value)
    _light: float = (2.0 - _sat) * _value * 0.5
    return _hue, _light, _s


def hsv2rgb(h: float, s: float, v: float) -> tuple:
    """HSV -> RGB"""
    if s == 0.0:
        return v, v, v
    i = int(h * 6.0)
    f = (h * 6.0) - i
    p = v * (1.0 - s)
    q = v * (1.0 - s * f)
    t = v * (1.0 - s * (1.0 - f))
    i = i % 6
    if i == 0:
        return v, t, p
    elif i == 1:
        return q, v, p
    elif i == 2:
        return p, v, t
    elif i == 3:
        return p, q, v
    elif i == 4:
        return t, p, v
    return v, p, q


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
    _red = _html[1:3]
    _green = _html[3:5]
    _blue = _html[-2:]
    return _red, _green, _blue


def html2rgb(_html: str) -> tuple:
    """HTML notation (#f6a797) -> RGB (byte array - 0-255)"""
    _red = int(_html[1:3], 16)
    _green = int(_html[3:5], 16)
    _blue = int(_html[-2:], 16)
    return _red, _green, _blue


def shorthand2sixdigit(_shorthand: str) -> str:
    """Shorthand HTML notation (#789) -> 6-digit HTML notation (#778899)"""
    if '#' in _shorthand:
        _red = _shorthand[1] + _shorthand[1]
        _green = _shorthand[2] + _shorthand[2]
        _blue = _shorthand[3] + _shorthand[3]
    else:
        _red = _shorthand[0] + _shorthand[0]
        _green = _shorthand[1] + _shorthand[1]
        _blue = _shorthand[2] + _shorthand[2]
    return '#' + str(_red) + str(_green) + str(_blue)


# HUNTER LAB #


def hunterlab2xyz(_hl: float, _ha: float, _hb: float) -> tuple:
    """Hunter Lab -> XYZ"""
    _y: float = _hl * 0.1
    _x: float = _ha / 17.5 * _y
    _z: float = _hb / 7.0 * _y
    _y = _y * _y
    _x = (_x + _y) / 1.02
    _z = - (_z - _y) / 0.847
    return _x, _y, _z


# RGB #


def rgb2cmy(_red, _green, _blue, _float: bool = True) -> tuple:
    """RGB -> CMY"""
    if _float:
        _c = 1.0 - _red
        _m = 1.0 - _green
        _y = 1.0 - _blue
    else:
        _c = 1.0 - (_red / 255.0)
        _m = 1.0 - (_green / 255.0)
        _y = 1.0 - (_blue / 255.0)
    return _c, _m, _y


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
        r = r * 255.0
        g = g * 255.0
        b = b * 255.0
    elif r == 1.0 and g == 1.0 and b == 1.0:
        return r'ff', r'ff', r'ff'
    return hex(round(r)), hex(round(g)), hex(round(b))


def rgb2hls(r: float, g: float, b: float) -> tuple:
    """RGB -> HLS"""
    maxc = max(r, g, b)
    minc = min(r, g, b)
    _l = (minc + maxc) * 0.5
    if minc == maxc:
        return 0.0, _l, 0.0
    maxc_minc = maxc - minc
    if _l <= 0.5:
        s = maxc_minc / (maxc + minc)
    else:
        s = maxc_minc / (2.0 - maxc_minc)
    if r == maxc:
        h = ((maxc - b) / maxc_minc) - ((maxc - g) / maxc_minc)
    elif g == maxc:
        h = 2.0 + ((maxc - r) / maxc_minc) - ((maxc - b) / maxc_minc)
    else:
        h = 4.0 + ((maxc - g) / maxc_minc) - ((maxc - r) / maxc_minc)
    h = (h * 0.166666667) % 1.0
    return h, _l, s


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
    _rgbmin = min(_red, _green, _blue)
    _rgbplus = _red + _green + _blue
    _red2 = _red * _red
    _green2 = _green * _green
    _blue2 = _blue * _blue
    _var0 = (_red * _green) - (_red * _blue) - (_green * _blue)
    _squareroot = round(sqrt(_red2 + _green2 + _blue2 - _var0), 6)
    _var1 = _red - (_green * 0.5) - (_blue * 0.5)
    _var2 = _var1 / _squareroot
    _radconv = 57.2958279088
    _intensity = (_red + _green + _blue) * 0.33333333
    if _rgbplus == 765:
        _sat = 0.0
        _hue = 0.0
        return _hue, _sat, round(_intensity, 6)
    if _intensity > 0.0:
        _sat = 1.0 - (_rgbmin / _intensity)
    elif _intensity == 0.0:
        _sat = 0.0
    if _green >= _blue:
        _hue = _radconv * acos(_var2)
    elif _blue > _green:
        _hue = 360.0 - (_radconv * acos(_var2))
    return round(_hue, 6), round(_sat, 6), round(_intensity, 6)


def rgb2hsv(_red: float, _green: float, _blue: float) -> tuple:
    """RGB -> HSV"""
    maxc = max(_red, _green, _blue)
    minc = min(_red, _green, _blue)
    _value = maxc
    if minc == maxc:
        return 0.0, 0.0, _value
    minmaxc = maxc - minc
    _sat = minmaxc / maxc
    rc = (maxc - _red) / minmaxc
    gc = (maxc - _green) / minmaxc
    bc = (maxc - _blue) / minmaxc
    if _red == maxc:
        _hue = bc - gc
    elif _green == maxc:
        _hue = 2.0 + rc - bc
    else:
        _hue = 4.0 + gc - rc
    _hue = (_hue * 0.1666666667) % 1.0
    return _hue, _sat, _value


def rgb2html(_red: float, _green: float, _blue: float) -> str:
    """RGB -> HTML notation"""
    return r'#' + hex(round(_red))[2:4] + hex(round(_green))[2:4] + hex(round(_blue))[2:4]


def rgb2xyz(_red: float, _green: float, _blue: float, _float: bool = True) -> tuple:
    """RGB -> XYZ"""
    if not _float:
        _red = _red / 255.0
        _green = _green / 255.0
        _blue = _blue / 255.0
    if _red > 0.04045:
        _red = ((_red + 0.055) / 1.055) ** 2.4
    else:
        _red = _red / 12.92
    if _green > 0.04045:
        _green = ((_green + 0.055) / 1.055) ** 2.4
    else:
        _green = _green / 12.92
    if _blue > 0.04045:
        _blue = ((_blue + 0.055) / 1.055) ** 2.4
    else:
        _blue = _blue / 12.92
    _red = _red * 100.0
    _green = _green * 100.0
    _blue = _blue * 100.0
    _x = _red * 0.4124 + _green * 0.3576 + _blue * 0.1805
    _y = _red * 0.2126 + _green * 0.7152 + _blue * 0.0722
    _z = _red * 0.0193 + _green * 0.1192 + _blue * 0.9505
    return _x, _y, _z


def rgb2yiq(_red: float, _green: float, _blue: float) -> tuple:
    """RGB -> YIQ"""
    _y = 0.30 * _red + 0.59 * _green + 0.11 * _blue
    _i = 0.74 * (_red - _y) - 0.27 * (_blue - _y)
    _q = 0.48 * (_red - _y) + 0.41 * (_blue - _y)
    return (_y, _i, _q)


# RGB & RGBA #


def rgb2rgba(_red: float, _green: float, _blue: float, _bytearray: bool = False) -> tuple:
    """RGB -> RGBA"""
    if _bytearray is False:
        return _red, _green, _blue, 1.0000
    return _red, _green, _blue, 255.0


def rgba2rgb(_red: float, _green: float, _blue: float) -> tuple:
    """RGBA -> RGB"""
    return _red, _green, _blue


# RGB FLOATS & RGB INTEGERS (BYTE ARRAY) #


def rgb2rgbf(_red: float, _green: float, _blue: float) -> tuple:
    """RGB Integer -> RGB Float"""
    return (_red / 255.0, _green / 255.0, _blue / 255.0)


def rgbf2rgb(_red: float, _green: float, _blue: float) -> tuple:
    """RGB Float -> RGB Integer"""
    return (_red * 255.0, _green * 255.0, _blue * 255.0)


def roundrgb(_r: float, _g: float, _b: float) -> tuple:
    """Round RGB float-points (like 245.649915) to integer (246)"""
    return (round(_r), round(_g), round(_b))


# XYZ #


def xyz2hunterlab(_x: float, _y: float, _z: float) -> tuple:
    """XYZ -> Hunter Lab"""
    sqrt_y = sqrt(_y)
    _hll = 10.0 * sqrt_y
    _hla = 17.5 * (((1.02 * _x) - _y) / sqrt_y)
    _hlb = 7.0 * ((_y - (0.847 * _z)) / sqrt_y)
    return _hll, _hla, _hlb


def xyz2rgb(_x: float, _y: float, _z: float) -> tuple:
    """XYZ -> RGB"""
    _x = _x * 0.01
    _y = _y * 0.01
    _z = _z * 0.01
    _red = _x * 3.2406 + _y * -1.5372 + _z * -0.4986
    _green = _x * -0.9689 + _y * 1.8758 + _z * 0.0415
    _blue = _x * 0.0557 + _y * -0.2040 + _z * 1.0570
    if _red > 0.0031308:
        _red = 1.055 * (_red ** 0.4166667) - 0.055
    else:
        _red = 12.92 * _red
    if _green > 0.0031308:
        _green = 1.055 * (_green ** 0.4166667) - 0.055
    else:
        _green = 12.92 * _green
    if _blue > 0.0031308:
        _blue = 1.055 * (_blue ** 0.4166667) - 0.055
    else:
        _blue = 12.92 * _blue
    return _red, _green, _blue


def xyz2rgb_int(_x: float, _y: float, _z: float) -> tuple:
    """XYZ -> RGB as an integer"""
    _x = _x * 0.01
    _y = _y * 0.01
    _z = _z * 0.01
    _red = _x * 3.2406 + _y * -1.5372 + _z * -0.4986
    _green = _x * -0.9689 + _y * 1.8758 + _z * 0.0415
    _blue = _x * 0.0557 + _y * -0.2040 + _z * 1.0570
    if _red > 0.0031308:
        _red = 1.055 * (_red ** 0.4166667) - 0.055
    else:
        _red = 12.92 * _red
    if _green > 0.0031308:
        _green = 1.055 * (_green ** 0.4166667) - 0.055
    else:
        _green = 12.92 * _green
    if _blue > 0.0031308:
        _blue = 1.055 * (_blue ** 0.4166667) - 0.055
    else:
        _blue = 12.92 * _blue
    return _red * 255.0, _green * 255.0, _blue * 255.0


# YIQ #


def yiq2rgb(_y: float, _i: float, _q: float) -> tuple:
    """YIQ -> RGB"""
    _red = _y + 0.9468822170900693 * _i + 0.6235565819861433 * _q
    _green = _y - 0.27478764629897834 * _i - 0.6356910791873801 * _q
    _blue = _y - 1.1085450346420322 * _i + 1.7090069284064666 * _q
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
    return (_red, _green, _blue)

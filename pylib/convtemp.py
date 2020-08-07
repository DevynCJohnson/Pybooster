#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Temperature measurement conversions.

@file convtemp.py
@package pybooster.convtemp
@version 2020.08.06
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


from typing import Union


__all__: list = [
    # CELSIUS #
    r'celsius2delisle',
    r'celsius2fahrenheit',
    r'celsius2kelvin',
    r'celsius2rankine',
    # CENTIGRADE #
    r'centigrade2delisle',
    r'centigrade2fahrenheit',
    r'centigrade2kelvin',
    r'centigrade2rankine',
    # DELISLE #
    r'delisle2celsius',
    r'delisle2centigrade',
    r'delisle2fahrenheit',
    r'delisle2kelvin',
    r'delisle2rankine',
    # FAHRENHEIT #
    r'fahrenheit2celsius',
    r'fahrenheit2centigrade',
    r'fahrenheit2delisle',
    r'fahrenheit2kelvin',
    r'fahrenheit2rankine',
    # KELVIN #
    r'kelvin2celsius',
    r'kelvin2centigrade',
    r'kelvin2delisle',
    r'kelvin2fahrenheit',
    r'kelvin2rankine',
    # NEWTON #
    # RANKINE #
    r'rankine2celsius',
    r'rankine2centigrade',
    r'rankine2delisle',
    r'rankine2fahrenheit',
    r'rankine2kelvin'
    # RÉAUMUR #
    # RØMER #
]


# CELSIUS #


def celsius2delisle(_temp: Union[float, int], _round: int = 3) -> float:
    """Celsius -> Delisle."""
    _temp = 100 - float(_temp)
    return round(_temp * 1.5, _round)


def celsius2fahrenheit(_temp: Union[float, int], _round: int = 3) -> float:
    """Celsius -> Fahrenheit."""
    _temp = float(_temp) * 1.8
    return round(_temp + 32.0, _round)


def celsius2kelvin(_temp: Union[float, int], _round: int = 3) -> float:
    """Celsius -> Kelvin."""
    return round(_temp + 273.15, _round)


def celsius2rankine(_temp: Union[float, int], _round: int = 3) -> float:
    """Celsius -> Rankine."""
    _temp = float(_temp) + 273.15
    return round(_temp * 1.8, _round)


# CENTIGRADE #


def centigrade2delisle(_temp: Union[float, int], _round: int = 3) -> float:
    """Centigrade -> Delisle."""
    _temp = 100 - float(_temp)
    return round(_temp * 1.5, _round)


def centigrade2fahrenheit(_temp: Union[float, int], _round: int = 3) -> float:
    """Centigrade -> Fahrenheit."""
    _temp = float(_temp) * 1.8
    return round(_temp + 32.0, _round)


def centigrade2kelvin(_temp: Union[float, int], _round: int = 3) -> float:
    """Centigrade -> Kelvin."""
    return round(_temp + 273.15, _round)


def centigrade2rankine(_temp: Union[float, int], _round: int = 3) -> float:
    """Centigrade -> Rankine."""
    _temp = float(_temp) + 273.15
    return round(_temp * 1.8, _round)


# DELISLE #


def delisle2celsius(_temp: Union[float, int], _round: int = 3) -> float:
    """Delisle -> Celsius."""
    _temp = float(_temp) * 0.666666667
    return round(100.0 - _temp, _round)


def delisle2centigrade(_temp: Union[float, int], _round: int = 3) -> float:
    """Delisle -> Centigrade."""
    _temp = float(_temp) * 0.666666667
    return round(100.0 - _temp, _round)


def delisle2fahrenheit(_temp: Union[float, int], _round: int = 3) -> float:
    """Delisle -> Fahrenheit."""
    _temp = float(_temp) * 1.2
    return round(212.0 - _temp, _round)


def delisle2kelvin(_temp: Union[float, int], _round: int = 3) -> float:
    """Delisle -> Kelvin."""
    _temp = float(_temp) * 0.666666667
    return round(373.15 - _temp, _round)


def delisle2rankine(_temp: Union[float, int], _round: int = 3) -> float:
    """Delisle -> Rankine."""
    _temp = float(_temp) * 1.2
    return round(671.67 - _temp, _round)


# FAHRENHEIT #


def fahrenheit2celsius(_temp: Union[float, int], _round: int = 3) -> float:
    """Fahrenheit -> Celsius."""
    _temp = float(_temp) - 32.0
    return round(_temp * 0.555555556, _round)


def fahrenheit2centigrade(_temp: Union[float, int], _round: int = 3) -> float:
    """Fahrenheit -> Centigrade."""
    _temp = float(_temp) - 32.0
    return round(_temp * 0.555555556, _round)


def fahrenheit2delisle(_temp: Union[float, int], _round: int = 3) -> float:
    """Fahrenheit -> Delisle."""
    _temp = 212 - float(_temp)
    return round(_temp * 0.833333333, _round)


def fahrenheit2kelvin(_temp: Union[float, int], _round: int = 3) -> float:
    """Fahrenheit -> Kelvin."""
    _temp = float(_temp) + 459.67
    return round(_temp * 0.555555556, _round)


def fahrenheit2rankine(_temp: Union[float, int], _round: int = 3) -> float:
    """Fahrenheit -> Rankine."""
    _temp = float(_temp) + 459.67
    return round(_temp, _round)


# KELVIN #


def kelvin2celsius(_temp: Union[float, int], _round: int = 3) -> float:
    """Kelvin -> Celsius."""
    _temp = float(_temp) - 273.15
    return round(_temp, _round)


def kelvin2centigrade(_temp: Union[float, int], _round: int = 3) -> float:
    """Kelvin -> Centigrade."""
    _temp = float(_temp) - 273.15
    return round(_temp, _round)


def kelvin2delisle(_temp: Union[float, int], _round: int = 3) -> float:
    """Kelvin -> Delisle."""
    _temp = 373.15 - float(_temp)
    return round(_temp * 1.5, _round)


def kelvin2fahrenheit(_temp: Union[float, int], _round: int = 3) -> float:
    """Kelvin -> Fahrenheit."""
    _temp = float(_temp) * 1.8
    return round(_temp - 459.67, _round)


def kelvin2rankine(_temp: Union[float, int], _round: int = 3) -> float:
    """Kelvin -> Rankine."""
    _temp = float(_temp) * 1.8
    return round(_temp, _round)


# RANKINE #


def rankine2celsius(_temp: Union[float, int], _round: int = 3) -> float:
    """Rankine -> Celsius."""
    _temp = float(_temp) - 491.67
    return round(_temp * 0.555555556, _round)


def rankine2centigrade(_temp: Union[float, int], _round: int = 3) -> float:
    """Rankine -> Centigrade."""
    _temp = float(_temp) - 491.67
    return round(_temp * 0.555555556, _round)


def rankine2delisle(_temp: Union[float, int], _round: int = 3) -> float:
    """Rankine -> Delisle."""
    _temp = 671.67 - float(_temp)
    return round(_temp * 0.833333333, _round)


def rankine2fahrenheit(_temp: Union[float, int], _round: int = 3) -> float:
    """Rankine -> Fahrenheit."""
    return round(float(_temp) - 459.67, _round)


def rankine2kelvin(_temp: Union[float, int], _round: int = 3) -> float:
    """Rankine -> Kelvin."""
    return round(float(_temp) * 0.555555556, _round)

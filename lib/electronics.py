#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
@file electronics.py
@package pybooster.electronics
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@brief Electronics equations
@version 2016.03.18

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

The PyBooster Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.
"""


__all__ = [
    # CONSTANTS
    'OHMS',
    # FUNCTIONS
    'current',
    'resistance',
    'voltage',
    'power',
]


# CONSTANTS


OHMS = 'Ω'


# FUNCTIONS


def current(_voltage: float, _resistance: float) -> float:
    """I=E/Ω"""
    return _voltage / _resistance


def resistance(_voltage: float, _current: float) -> float:
    """Ω=E/I"""
    return _voltage / _current


def voltage(_current: float, _resistance: float) -> float:
    """E=IΩ"""
    return _current * _resistance


def power(_current: float=None, _resistance: float=None, _voltage: float=None) -> float:
    """Power (Wattage)"""
    if _current is None:  # P=(E^2)/Ω
        return (_voltage ** 2) / _resistance
    elif _resistance is None:  # P=IE
        return _current * _voltage
    elif _voltage is None:  # P=(I^2)Ω
        return (_current ** 2) * _resistance
    return None

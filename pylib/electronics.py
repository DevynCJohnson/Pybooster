#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Electrical equations

@file electronics.py
@package pybooster.electronics
@version 2018.04.27
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


__all__ = [
    # CONSTANTS #
    r'OHMS',
    # FUNCTIONS #
    r'current',
    r'resistance',
    r'voltage',
    r'power'
]


# CONSTANTS #


OHMS = r'Ω'


# FUNCTIONS #


def current(_voltage: float, _resistance: float) -> float:
    """I=E/Ω"""
    return _voltage / _resistance


def resistance(_voltage: float, _current: float) -> float:
    """Ω=E/I"""
    return _voltage / _current


def voltage(_current: float, _resistance: float) -> float:
    """E=IΩ"""
    return _current * _resistance


def power(_current: float = None, _resistance: float = None, _voltage: float = None) -> float:
    """Power (Wattage)"""
    if _current is None:  # P=(E^2)/Ω
        return (_voltage ** 2) / _resistance
    elif _resistance is None:  # P=IE
        return _current * _voltage
    elif _voltage is None:  # P=(I^2)Ω
        return (_current ** 2) * _resistance
    return None

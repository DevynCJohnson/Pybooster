#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""@brief Metric related functions
@file metric.py
@package pybooster.metric
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@version 2016.03.20

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


# pylint: disable=R0911,R0912


from re import sub as resub


__all__ = [
    # CONSTANTS
    'YOCTO_UNITS',
    'ZEPTO_UNITS',
    'ATTO_UNITS',
    'FEMTO_UNITS',
    'PICO_UNITS',
    'NANO_UNITS',
    'MICRO_UNITS',
    'MILLI_UNITS',
    'CENTI_UNITS',
    'DECI_UNITS',
    'DECA_UNITS',
    'HECTO_UNITS',
    'KILO_UNITS',
    'MEGA_UNITS',
    'GIGA_UNITS',
    'TERA_UNITS',
    'PETA_UNITS',
    'EXA_UNITS',
    'ZETTA_UNITS',
    'YOTTA_UNITS',
    'SIUNITS',
    'METRIC_PREFIX',
    'NON_STANDARD_PREFIX',
    # FUNCTIONS
    'str2tupleunit',
    'siunits2base',
]


# CONSTANTS


YOCTO_UNITS = (
    r'ym',
    r'yV',
    r'yA',
    r'yΩ',
)


ZEPTO_UNITS = (
    r'zm',
    r'zV',
    r'zA',
    r'zΩ',
)


ATTO_UNITS = (
    r'am',
    r'aV',
    r'aA',
    r'aΩ',
)


FEMTO_UNITS = (
    r'fm',
    r'fV',
    r'fA',
    r'fΩ',
)


PICO_UNITS = (
    r'pm',
    r'pV',
    r'pA',
    r'pΩ',
)


NANO_UNITS = (
    r'nm',
    r'nV',
    r'nA',
    r'nΩ',
)


MICRO_UNITS = (
    r'μm',
    r'μV',
    r'μA',
    r'μΩ',
)


MILLI_UNITS = (
    r'mm',
    r'mV',
    r'mA',
    r'mΩ',
)


CENTI_UNITS = (
    r'cm',
    r'cV',
    r'cA',
    r'cΩ',
)


DECI_UNITS = (
    r'dm',
    r'dV',
    r'dA',
    r'dΩ',
)


DECA_UNITS = (
    r'dam',
    r'daV',
    r'daA',
    r'daΩ',
)


HECTO_UNITS = (
    r'hm',
    r'hV',
    r'hA',
    r'hΩ',
)


KILO_UNITS = (
    r'km',
    r'kV',
    r'kA',
    r'kΩ',
)


MEGA_UNITS = (
    r'Mm',
    r'MV',
    r'MA',
    r'MΩ',
)


GIGA_UNITS = (
    r'Gm',
    r'GV',
    r'GA',
    r'GΩ',
)


TERA_UNITS = (
    r'Tm',
    r'TV',
    r'TA',
    r'TΩ',
)


PETA_UNITS = (
    r'Pm',
    r'PV',
    r'PA',
    r'PΩ',
)


EXA_UNITS = (
    r'Em',
    r'EV',
    r'EA',
    r'EΩ',
)


ZETTA_UNITS = (
    r'Zm',
    r'ZV',
    r'ZA',
    r'ZΩ',
)


YOTTA_UNITS = (
    r'Ym',
    r'YV',
    r'YA',
    r'YΩ',
)


SIUNITS = (
    YOCTO_UNITS,
    ZEPTO_UNITS,
    ATTO_UNITS,
    FEMTO_UNITS,
    PICO_UNITS,
    NANO_UNITS,
    MICRO_UNITS,
    MILLI_UNITS,
    CENTI_UNITS,
    DECI_UNITS,
    DECA_UNITS,
    HECTO_UNITS,
    KILO_UNITS,
    MEGA_UNITS,
    GIGA_UNITS,
    TERA_UNITS,
    PETA_UNITS,
    EXA_UNITS,
    ZETTA_UNITS,
    YOTTA_UNITS
)


METRIC_PREFIX = {
    'yotta': ('Y', 1000000000000000000000000),
    'zetta': ('Z', 1000000000000000000000),
    'exa': ('E', 1000000000000000000),
    'peta': ('P', 1000000000000000),
    'tera': ('T', 1000000000000),
    'giga': ('G', 1000000000),
    'mega': ('M', 1000000),
    'kilo': ('k', 1000),
    'hecto': ('h', 100),
    'deca': ('da', 10),
    'deci': ('d', 0.1),
    'centi': ('c', 0.01),
    'milli': ('m', 0.001),
    'micro': ('μ', 0.000001),
    'nano': ('n', 0.000000001),
    'pico': ('p', 0.000000000001),
    'femto': ('f', 0.000000000000001),
    'atto': ('a', 0.000000000000000001),
    'zepto': ('z', 0.000000000000000000001),
    'yocto': ('y', 0.000000000000000000000001),
}


NON_STANDARD_PREFIX = {
    'myria': ('my', 10000),
    'hella': ('H', 1000000000000000000000000000),
}


# FUNCTIONS


def str2tupleunit(_str: str) -> tuple:
    """Convert measurement units from string to tuple"""
    _num = resub('([0-9.]+)([ _,]*)([A-Za-z/]+)', r'\1', _str)
    _unit = resub('([0-9.]+)([ _,]*)([A-Za-z/]+)', r'\3', _str)
    return (_num, _unit)


def siunits2base(_measurement: tuple) -> tuple:  # noqa
    """Convert SI units to base unit"""
    if _measurement[1] in YOCTO_UNITS:
        return (float(_measurement[0]) * 0.000000000000000000000001, _measurement[1][1:])
    elif _measurement[1] in ZEPTO_UNITS:
        return (float(_measurement[0]) * 0.000000000000000000001, _measurement[1][1:])
    elif _measurement[1] in ATTO_UNITS:
        return (float(_measurement[0]) * 0.000000000000000001, _measurement[1][1:])
    elif _measurement[1] in FEMTO_UNITS:
        return (float(_measurement[0]) * 0.000000000000001, _measurement[1][1:])
    elif _measurement[1] in PICO_UNITS:
        return (float(_measurement[0]) * 0.000000000001, _measurement[1][1:])
    elif _measurement[1] in NANO_UNITS:
        return (float(_measurement[0]) * 0.000000001, _measurement[1][1:])
    elif _measurement[1] in MICRO_UNITS:
        return (float(_measurement[0]) * 0.000001, _measurement[1][1:])
    elif _measurement[1] in MILLI_UNITS:
        return (float(_measurement[0]) * 0.001, _measurement[1][1:])
    elif _measurement[1] in CENTI_UNITS:
        return (float(_measurement[0]) * 0.01, _measurement[1][1:])
    elif _measurement[1] in DECI_UNITS:
        return (float(_measurement[0]) * 0.1, _measurement[1][1:])
    elif _measurement[1] in DECA_UNITS:
        return (float(_measurement[0]) * 10.0, _measurement[1][1:])
    elif _measurement[1] in HECTO_UNITS:
        return (float(_measurement[0]) * 100.0, _measurement[1][1:])
    elif _measurement[1] in KILO_UNITS:
        return (float(_measurement[0]) * 1000.0, _measurement[1][1:])
    elif _measurement[1] in MEGA_UNITS:
        return (float(_measurement[0]) * 1000000.0, _measurement[1][1:])
    elif _measurement[1] in GIGA_UNITS:
        return (float(_measurement[0]) * 1000000000.0, _measurement[1][1:])
    elif _measurement[1] in TERA_UNITS:
        return (float(_measurement[0]) * 1000000000000.0, _measurement[1][1:])
    elif _measurement[1] in PETA_UNITS:
        return (float(_measurement[0]) * 1000000000000000.0, _measurement[1][1:])
    elif _measurement[1] in EXA_UNITS:
        return (float(_measurement[0]) * 1000000000000000000.0, _measurement[1][1:])
    elif _measurement[1] in ZETTA_UNITS:
        return (float(_measurement[0]) * 1000000000000000000000.0, _measurement[1][1:])
    elif _measurement[1] in YOTTA_UNITS:
        return (float(_measurement[0]) * 1000000000000000000000000.0, _measurement[1][1:])
    return (float(_measurement[0]), _measurement[1])

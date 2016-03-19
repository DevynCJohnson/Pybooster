#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
@file metric.py
@package pybooster.metric
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@brief Metric related functions
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
    'ym',
    'yV',
    'yA',
    'yΩ',
)


ZEPTO_UNITS = (
    'zm',
    'zV',
    'zA',
    'zΩ',
)


ATTO_UNITS = (
    'am',
    'aV',
    'aA',
    'aΩ',
)


FEMTO_UNITS = (
    'fm',
    'fV',
    'fA',
    'fΩ',
)


PICO_UNITS = (
    'pm',
    'pV',
    'pA',
    'pΩ',
)


NANO_UNITS = (
    'nm',
    'nV',
    'nA',
    'nΩ',
)


MICRO_UNITS = (
    'μm',
    'μV',
    'μA',
    'μΩ',
)


MILLI_UNITS = (
    'mm',
    'mV',
    'mA',
    'mΩ',
)


CENTI_UNITS = (
    'cm',
    'cV',
    'cA',
    'cΩ',
)


DECI_UNITS = (
    'dm',
    'dV',
    'dA',
    'dΩ',
)


DECA_UNITS = (
    'dam',
    'daV',
    'daA',
    'daΩ',
)


HECTO_UNITS = (
    'hm',
    'hV',
    'hA',
    'hΩ',
)


KILO_UNITS = (
    'km',
    'kV',
    'kA',
    'kΩ',
)


MEGA_UNITS = (
    'Mm',
    'MV',
    'MA',
    'MΩ',
)


GIGA_UNITS = (
    'Gm',
    'GV',
    'GA',
    'GΩ',
)


TERA_UNITS = (
    'Tm',
    'TV',
    'TA',
    'TΩ',
)


PETA_UNITS = (
    'Pm',
    'PV',
    'PA',
    'PΩ',
)


EXA_UNITS = (
    'Em',
    'EV',
    'EA',
    'EΩ',
)


ZETTA_UNITS = (
    'Zm',
    'ZV',
    'ZA',
    'ZΩ',
)


YOTTA_UNITS = (
    'Ym',
    'YV',
    'YA',
    'YΩ',
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


def siunits2base(_measurement: tuple) -> tuple:
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

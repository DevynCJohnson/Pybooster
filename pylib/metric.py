#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Metric-related functions

@file metric.py
@package pybooster.metric
@version 2018.08.31
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


try:  # Regular Expression module
    from regex import sub as resub
except ImportError:
    from re import sub as resub


__all__: list = [
    # CONSTANTS #
    r'YOCTO_UNITS',
    r'ZEPTO_UNITS',
    r'ATTO_UNITS',
    r'FEMTO_UNITS',
    r'PICO_UNITS',
    r'NANO_UNITS',
    r'MICRO_UNITS',
    r'MILLI_UNITS',
    r'CENTI_UNITS',
    r'DECI_UNITS',
    r'DECA_UNITS',
    r'HECTO_UNITS',
    r'KILO_UNITS',
    r'MEGA_UNITS',
    r'GIGA_UNITS',
    r'TERA_UNITS',
    r'PETA_UNITS',
    r'EXA_UNITS',
    r'ZETTA_UNITS',
    r'YOTTA_UNITS',
    r'SIUNITS',
    r'METRIC_PREFIX',
    r'NON_STANDARD_PREFIX',
    # FUNCTIONS #
    r'str2tupleunit',
    r'siunits2base'
]


# CONSTANTS #


YOCTO_UNITS = (r'ym', r'yV', r'yA', 'y\u03A9')


ZEPTO_UNITS = (r'zm', r'zV', r'zA', 'z\u03A9')


ATTO_UNITS = (r'am', r'aV', r'aA', 'a\u03A9')


FEMTO_UNITS = (r'fm', r'fV', r'fA', 'f\u03A9')


PICO_UNITS = (r'pm', r'pV', r'pA', 'p\u03A9')


NANO_UNITS = (r'nm', r'nV', r'nA', 'n\u03A9')


MICRO_UNITS = ('\u03BCm', '\u03BCV', '\u03BCA', '\u03A9')


MILLI_UNITS = (r'mm', r'mV', r'mA', 'm\u03A9')


CENTI_UNITS = (r'cm', r'cV', r'cA', 'c\u03A9')


DECI_UNITS = (r'dm', r'dV', r'dA', 'd\u03A9')


DECA_UNITS = (r'dam', r'daV', r'daA', 'da\u03A9')


HECTO_UNITS = (r'hm', r'hV', r'hA', 'h\u03A9')


KILO_UNITS = (r'km', r'kV', r'kA', 'k\u03A9')


MEGA_UNITS = (r'Mm', r'MV', r'MA', 'M\u03A9')


GIGA_UNITS = (r'Gm', r'GV', r'GA', 'G\u03A9')


TERA_UNITS = (r'Tm', r'TV', r'TA', 'T\u03A9')


PETA_UNITS = (r'Pm', r'PV', r'PA', 'P\u03A9')


EXA_UNITS = (r'Em', r'EV', r'EA', 'E\u03A9')


ZETTA_UNITS = (r'Zm', r'ZV', r'ZA', 'Z\u03A9')


YOTTA_UNITS = (r'Ym', r'YV', r'YA', 'Y\u03A9')


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
    r'yotta': (r'Y', 1000000000000000000000000),
    r'zetta': (r'Z', 1000000000000000000000),
    r'exa': (r'E', 1000000000000000000),
    r'peta': (r'P', 1000000000000000),
    r'tera': (r'T', 1000000000000),
    r'giga': (r'G', 1000000000),
    r'mega': (r'M', 1000000),
    r'kilo': (r'k', 1000),
    r'hecto': (r'h', 100),
    r'deca': (r'da', 10),
    r'deci': (r'd', 0.1),
    r'centi': (r'c', 0.01),
    r'milli': (r'm', 0.001),
    r'micro': ('\u03BC', 0.000001),
    r'nano': (r'n', 0.000000001),
    r'pico': (r'p', 0.000000000001),
    r'femto': (r'f', 0.000000000000001),
    r'atto': (r'a', 0.000000000000000001),
    r'zepto': (r'z', 0.000000000000000000001),
    r'yocto': (r'y', 0.000000000000000000000001)
}


NON_STANDARD_PREFIX = {
    r'myria': (r'my', 10000),
    r'hella': (r'H', 1000000000000000000000000000),
}


# FUNCTIONS #


def str2tupleunit(_str: str) -> tuple:
    """Convert measurement units from string to tuple"""
    _num = resub('([0-9.]+)([ _,]*)([A-Za-z/]+)', r'\1', _str)
    _unit = resub('([0-9.]+)([ _,]*)([A-Za-z/]+)', r'\3', _str)
    return (_num, _unit)


def siunits2base(_measurement: tuple) -> tuple:   # noqa: C901  # pylint: disable=R0911,R0912
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

#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Length measurement conversions

@file convlength.py
@package pybooster.convlength
@version 2018.11.11
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


from typing import Union


__all__: list = [
    # CENTIMETERS #
    r'centimeter2chain',
    r'centimeter2decimeter',
    r'centimeter2foot',
    r'centimeter2inch',
    r'centimeter2kilometer',
    r'centimeter2meter',
    r'centimeter2microinch',
    r'centimeter2micron',
    r'centimeter2millimeter',
    r'centimeter2yard',
    # FEET #
    r'foot2chain',
    r'foot2centimeter',
    r'foot2decimeter',
    r'foot2furlong',
    r'foot2inch',
    r'foot2kilometer',
    r'foot2meter',
    r'foot2microinch',
    r'foot2mile',
    r'foot2millimeter',
    r'foot2yard',
    # INCHES #
    r'inch2chain',
    r'inch2centimeter',
    r'inch2decimeter',
    r'inch2foot',
    r'inch2furlong',
    r'inch2kilometer',
    r'inch2meter',
    r'inch2microinch',
    r'inch2millimeter',
    r'inch2yard',
    # KILOMETERS #
    r'kilometer2chain',
    r'kilometer2centimeter',
    r'kilometer2decimeter',
    r'kilometer2foot',
    r'kilometer2furlong',
    r'kilometer2inch',
    r'kilometer2lightyear',
    r'kilometer2meter',
    r'kilometer2mile',
    r'kilometer2microinch',
    r'kilometer2millimeter',
    r'kilometer2nauticalmile',
    r'kilometer2parsec',
    r'kilometer2yard',
    # METERS #
    r'meter2foot',
    r'meter2inch',
    r'meter2yard',
    # MILES #
    r'mile2chain',
    r'mile2foot',
    r'mile2furlong',
    r'mile2inch',
    r'mile2kilometer',
    r'mile2meter',
    r'mile2microinch',
    r'mile2yard',
    # YARDS #
    r'yard2chain',
    r'yard2centimeter',
    r'yard2decimeter',
    r'yard2foot',
    r'yard2furlong',
    r'yard2inch',
    r'yard2kilometer',
    r'yard2meter',
    r'yard2microinch',
    r'yard2mile',
    r'yard2millimeter'
]


# CENTIMETERS #


def centimeter2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Chains"""
    return round(_length * 0.00049710, _round)


def centimeter2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Decimeters"""
    return round(_length * 0.1, _round)


def centimeter2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Feet"""
    return round(_length * 0.032808, _round)


def centimeter2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Inches"""
    return round(_length * 0.39370, _round)


def centimeter2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Kilometers"""
    return round(_length * 0.00001, _round)


def centimeter2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Meters"""
    return round(_length * 0.01, _round)


def centimeter2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Microinches"""
    return round(_length * 393700.0, _round)


def centimeter2micron(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Microns"""
    return round(_length * 10000.0, _round)


def centimeter2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Millimeters"""
    return round(_length * 10.0, _round)


def centimeter2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Yards"""
    return round(_length * 0.010936, _round)


# FEET #


def foot2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Chains"""
    return round(_length * 0.015151, _round)


def foot2centimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Centimeters"""
    return round(_length * 30.480370641306998, _round)


def foot2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Decimeters"""
    return round(_length * 3.0480370641307, _round)


def foot2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Furlongs"""
    return round(_length * 0.0015151, _round)


def foot2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Inches"""
    return round(_length * 12.0, _round)


def foot2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Kilometers"""
    return round(_length * 0.000304803706413, _round)


def foot2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Meters"""
    return round(_length * 0.3948, _round)


def foot2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Microinches"""
    return round(_length * 12000000.0, _round)


def foot2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Miles"""
    return round(_length * 0.00018939, _round)


def foot2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Millimeters"""
    return round(_length * 304.803706413069983, _round)


def foot2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Yards"""
    return round(_length * 0.333333333333333, _round)


# INCHES #


def inch2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Chains"""
    return round(_length * 0.0012626, _round)


def inch2centimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Centimeters"""
    return round(_length * 2.54000508001016, _round)


def inch2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Decimeters"""
    return round(_length * 0.254000508001016, _round)


def inch2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Feet"""
    return round(_length * 0.083333333333333, _round)


def inch2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Furlong"""
    return round(_length * 0.00012626, _round)


def inch2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Kilometers"""
    return round(_length * 0.0000254000508, _round)


def inch2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Meters"""
    return round(_length * 0.0254, _round)


def inch2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Microinches"""
    return round(_length * 1000000.0, _round)


def inch2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Millimeters"""
    return round(_length * 25.4000508001016, _round)


def inch2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Yards"""
    return round(_length * 0.027777777777778, _round)


# KILOMETERS #


def kilometer2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Chains"""
    return round(_length * 49.710, _round)


def kilometer2centimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Centimeters"""
    return round(_length * 100000.0, _round)


def kilometer2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Decimeters"""
    return round(_length * 10000.0, _round)


def kilometer2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Feet"""
    return round(_length * 3280.8, _round)


def kilometer2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Furlongs"""
    return round(_length * 4.9710, _round)


def kilometer2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Inches"""
    return round(_length * 39370.0, _round)


def kilometer2lightyear(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Lightyears"""
    return round(_length / 9460730472580.8, _round)


def kilometer2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Meters"""
    return round(_length * 1000.0, _round)


def kilometer2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Miles"""
    return round(_length * 0.621371, _round)


def kilometer2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Microinches"""
    return round(_length * 39370000000.0, _round)


def kilometer2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Millimeters"""
    return round(_length * 1000000.0, _round)


def kilometer2nauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Nautical Miles"""
    return round(_length * 0.53996, _round)


def kilometer2parsec(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Parsecs"""
    return round(_length / 30857000000000.0, _round)


def kilometer2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Yards"""
    return round(_length * 1093.6, _round)


# METERS #


def meter2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Feet"""
    return round(_length / 0.3948, _round)


def meter2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Inches"""
    return round(_length / 0.0254, _round)


def meter2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Yards"""
    return round(_length / 0.9144, _round)


# MILES #


def mile2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Chains"""
    return round(_length * 80.0, _round)


def mile2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Feet"""
    return round(_length * 5280.0, _round)


def mile2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Furlongs"""
    return round(_length * 8.0, _round)


def mile2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Inches"""
    return round(_length * 63360.0, _round)


def mile2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Kilometers"""
    return round(_length / 0.62137, _round)


def mile2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Meters"""
    return round(_length / 0.00062137, _round)


def mile2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Microinches"""
    return round(_length * 63360000000.0, _round)


def mile2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Yards"""
    return round(_length * 1760.0, _round)


# YARDS #


def yard2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Chains"""
    return round(_length * 0.045454, _round)


def yard2centimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Centimeters"""
    return round(_length / 0.010936, _round)


def yard2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Decimeters"""
    return round(_length / 0.10936, _round)


def yard2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Feet"""
    return round(_length * 3.0, _round)


def yard2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Furlongs"""
    return round(_length * 0.0045454, _round)


def yard2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Inches"""
    return round(_length * 36.0, _round)


def yard2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Kilometers"""
    return round(_length / 1093.6, _round)


def yard2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Meters"""
    return round(_length * 0.9144, _round)


def yard2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Microinches"""
    return round(_length * 36000000.0, _round)


def yard2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Miles"""
    return round(_length * 0.00056818, _round)


def yard2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Millimeters"""
    return round(_length / 0.0010936, _round)

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
Created by Devyn Collier Johnson
<DevynCJohnson@Gmail.com>
LGPLv3 License
-- --
PyBooster - Various Extras for Python3
pybooster.convlength
-- --
Measurement (Length) Conversions
-- --
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
    # CENTIMETERS
    'centimeter2chain',
    'centimeter2decimeter',
    'centimeter2foot',
    'centimeter2inch',
    'centimeter2kilometer',
    'centimeter2meter',
    'centimeter2microinch',
    'centimeter2micron',
    'centimeter2millimeter',
    'centimeter2yard',
    # FEET
    'foot2chain',
    'foot2centimeter',
    'foot2decimeter',
    'foot2furlong',
    'foot2inch',
    'foot2kilometer',
    'foot2meter',
    'foot2microinch',
    'foot2mile',
    'foot2millimeter',
    'foot2yard',
    # INCHES
    'inch2chain',
    'inch2centimeter',
    'inch2decimeter',
    'inch2foot',
    'inch2furlong',
    'inch2kilometer',
    'inch2meter',
    'inch2microinch',
    'inch2millimeter',
    'inch2yard',
    # KILOMETERS
    'kilometer2chain',
    'kilometer2centimeter',
    'kilometer2decimeter',
    'kilometer2foot',
    'kilometer2furlong',
    'kilometer2inch',
    'kilometer2lightyear',
    'kilometer2meter',
    'kilometer2mile',
    'kilometer2microinch',
    'kilometer2millimeter',
    'kilometer2nauticalmile',
    'kilometer2parsec',
    'kilometer2yard',
    # METERS
    'meter2foot',
    'meter2inch',
    'meter2yard',
    # MILES
    'mile2chain',
    'mile2foot',
    'mile2furlong',
    'mile2inch',
    'mile2kilometer',
    'mile2meter',
    'mile2microinch',
    'mile2yard',
    # YARDS
    'yard2chain',
    'yard2centimeter',
    'yard2decimeter',
    'yard2foot',
    'yard2furlong',
    'yard2inch',
    'yard2kilometer',
    'yard2meter',
    'yard2microinch',
    'yard2mile',
    'yard2millimeter',
]

__author__ = 'Devyn Collier Johnson'
__copyright__ = 'LGPLv3'
__version__ = '2016.03.18'


# CENTIMETERS


def centimeter2chain(_length: int or float, _round: int=3) -> float:
    """Centimeters -> Chains"""
    return round(_length * 0.00049710, _round)


def centimeter2decimeter(_length: int or float, _round: int=3) -> float:
    """Centimeters -> Decimeters"""
    return round(_length * 0.1, _round)


def centimeter2foot(_length: int or float, _round: int=3) -> float:
    """Centimeters -> Feet"""
    return round(_length * 0.032808, _round)


def centimeter2inch(_length: int or float, _round: int=3) -> float:
    """Centimeters -> Inches"""
    return round(_length * 0.39370, _round)


def centimeter2kilometer(_length: int or float, _round: int=3) -> float:
    """Centimeters -> Kilometers"""
    return round(_length * 0.00001, _round)


def centimeter2meter(_length: int or float, _round: int=3) -> float:
    """Centimeters -> Meters"""
    return round(_length * 0.01, _round)


def centimeter2microinch(_length: int or float, _round: int=3) -> float:
    """Centimeters -> Microinches"""
    return round(_length * 393700, _round)


def centimeter2micron(_length: int or float, _round: int=3) -> float:
    """Centimeters -> Microns"""
    return round(_length * 10000, _round)


def centimeter2millimeter(_length: int or float, _round: int=3) -> float:
    """Centimeters -> Millimeters"""
    return round(_length * 10, _round)


def centimeter2yard(_length: int or float, _round: int=3) -> float:
    """Centimeters -> Yards"""
    return round(_length * 0.010936, _round)


# FEET


def foot2chain(_length: int or float, _round: int=3) -> float:
    """Feet -> Chains"""
    return round(_length * 0.015151, _round)


def foot2centimeter(_length: int or float, _round: int=3) -> float:
    """Feet -> Centimeters"""
    return round(_length * 30.480370641306998, _round)


def foot2decimeter(_length: int or float, _round: int=3) -> float:
    """Feet -> Decimeters"""
    return round(_length * 3.0480370641307, _round)


def foot2furlong(_length: int or float, _round: int=3) -> float:
    """Feet -> Furlongs"""
    return round(_length * 0.0015151, _round)


def foot2inch(_length: int or float, _round: int=3) -> float:
    """Feet -> Inches"""
    return round(_length * 12, _round)


def foot2kilometer(_length: int or float, _round: int=3) -> float:
    """Feet -> Kilometers"""
    return round(_length * 0.000304803706413, _round)


def foot2meter(_length: int or float, _round: int=3) -> float:
    """Feet -> Meters"""
    return round(_length * 0.3948, _round)


def foot2microinch(_length: int or float, _round: int=3) -> float:
    """Feet -> Microinches"""
    return round(_length * 12000000, _round)


def foot2mile(_length: int or float, _round: int=3) -> float:
    """Feet -> Miles"""
    return round(_length * 0.00018939, _round)


def foot2millimeter(_length: int or float, _round: int=3) -> float:
    """Feet -> Millimeters"""
    return round(_length * 304.803706413069983, _round)


def foot2yard(_length: int or float, _round: int=3) -> float:
    """Feet -> Yards"""
    return round(_length * 0.333333333333333, _round)


# INCHES


def inch2chain(_length: int or float, _round: int=3) -> float:
    """Inches -> Chains"""
    return round(_length * 0.0012626, _round)


def inch2centimeter(_length: int or float, _round: int=3) -> float:
    """Inches -> Centimeters"""
    return round(_length * 2.54000508001016, _round)


def inch2decimeter(_length: int or float, _round: int=3) -> float:
    """Inches -> Decimeters"""
    return round(_length * 0.254000508001016, _round)


def inch2foot(_length: int or float, _round: int=3) -> float:
    """Inches -> Feet"""
    return round(_length * 0.083333333333333, _round)


def inch2furlong(_length: int or float, _round: int=3) -> float:
    """Inches -> Furlong"""
    return round(_length * 0.00012626, _round)


def inch2kilometer(_length: int or float, _round: int=3) -> float:
    """Inches -> Kilometers"""
    return round(_length * 0.0000254000508, _round)


def inch2meter(_length: int or float, _round: int=3) -> float:
    """Inches -> Meters"""
    return round(_length * 0.0254, _round)


def inch2microinch(_length: int or float, _round: int=3) -> float:
    """Inches -> Microinches"""
    return round(_length * 1000000, _round)


def inch2millimeter(_length: int or float, _round: int=3) -> float:
    """Inches -> Millimeters"""
    return round(_length * 25.4000508001016, _round)


def inch2yard(_length: int or float, _round: int=3) -> float:
    """Inches -> Yards"""
    return round(_length * 0.027777777777778, _round)


# KILOMETERS


def kilometer2chain(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Chains"""
    return round(_length * 49.710, _round)


def kilometer2centimeter(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Centimeters"""
    return round(_length * 100000, _round)


def kilometer2decimeter(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Decimeters"""
    return round(_length * 10000, _round)


def kilometer2foot(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Feet"""
    return round(_length * 3280.8, _round)


def kilometer2furlong(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Furlongs"""
    return round(_length * 4.9710, _round)


def kilometer2inch(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Inches"""
    return round(_length * 39370, _round)


def kilometer2lightyear(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Lightyears"""
    return round(_length / 9460730472580.8, _round)


def kilometer2meter(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Meters"""
    return round(_length * 1000, _round)


def kilometer2mile(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Miles"""
    return round(_length * 0.621371, _round)


def kilometer2microinch(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Microinches"""
    return round(_length * 39370000000, _round)


def kilometer2millimeter(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Millimeters"""
    return round(_length * 1000000, _round)


def kilometer2nauticalmile(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Nautical Miles"""
    return round(_length * 0.53996, _round)


def kilometer2parsec(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Parsecs"""
    return round(_length / 30857000000000, _round)


def kilometer2yard(_length: int or float, _round: int=3) -> float:
    """Kilometers -> Yards"""
    return round(_length * 1093.6, _round)


# METERS


def meter2foot(_length: int or float, _round: int=3) -> float:
    """Meters -> Feet"""
    return round(_length / 0.3948, _round)


def meter2inch(_length: int or float, _round: int=3) -> float:
    """Meters -> Inches"""
    return round(_length / 0.0254, _round)


def meter2yard(_length: int or float, _round: int=3) -> float:
    """Meters -> Yards"""
    return round(_length / 0.9144, _round)


# MILES


def mile2chain(_length: int or float, _round: int=3) -> float:
    """Miles -> Chains"""
    return round(_length * 80, _round)


def mile2foot(_length: int or float, _round: int=3) -> float:
    """Miles -> Feet"""
    return round(_length * 5280, _round)


def mile2furlong(_length: int or float, _round: int=3) -> float:
    """Miles -> Furlongs"""
    return round(_length * 8, _round)


def mile2inch(_length: int or float, _round: int=3) -> float:
    """Miles -> Inches"""
    return round(_length * 63360, _round)


def mile2kilometer(_length: int or float, _round: int=3) -> float:
    """Miles -> Kilometers"""
    return round(_length / 0.62137, _round)


def mile2meter(_length: int or float, _round: int=3) -> float:
    """Miles -> Meters"""
    return round(_length / 0.00062137, _round)


def mile2microinch(_length: int or float, _round: int=3) -> float:
    """Miles -> Microinches"""
    return round(_length * 63360000000, _round)


def mile2yard(_length: int or float, _round: int=3) -> float:
    """Miles -> Yards"""
    return round(_length * 1760, _round)


# YARDS


def yard2chain(_length: int or float, _round: int=3) -> float:
    """Yards -> Chains"""
    return round(_length * 0.045454, _round)


def yard2centimeter(_length: int or float, _round: int=3) -> float:
    """Yards -> Centimeters"""
    return round(_length / 0.010936, _round)


def yard2decimeter(_length: int or float, _round: int=3) -> float:
    """Yards -> Decimeters"""
    return round(_length / 0.10936, _round)


def yard2foot(_length: int or float, _round: int=3) -> float:
    """Yards -> Feet"""
    return round(_length * 3, _round)


def yard2furlong(_length: int or float, _round: int=3) -> float:
    """Yards -> Furlongs"""
    return round(_length * 0.0045454, _round)


def yard2inch(_length: int or float, _round: int=3) -> float:
    """Yards -> Inches"""
    return round(_length * 36, _round)


def yard2kilometer(_length: int or float, _round: int=3) -> float:
    """Yards -> Kilometers"""
    return round(_length / 1093.6, _round)


def yard2meter(_length: int or float, _round: int=3) -> float:
    """Yards -> Meters"""
    return round(_length * 0.9144, _round)


def yard2microinch(_length: int or float, _round: int=3) -> float:
    """Yards -> Microinches"""
    return round(_length * 36000000, _round)


def yard2mile(_length: int or float, _round: int=3) -> float:
    """Yards -> Miles"""
    return round(_length * 0.00056818, _round)


def yard2millimeter(_length: int or float, _round: int=3) -> float:
    """Yards -> Millimeters"""
    return round(_length / 0.0010936, _round)

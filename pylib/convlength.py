#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Length measurement conversions.

@file convlength.py
@package pybooster.convlength
@version 2020.08.01
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
    # CENTIMETERS #
    r'centimeter2chain',
    r'centimeter2decimeter',
    r'centimeter2foot',
    r'centimeter2furlong',
    r'centimeter2inch',
    r'centimeter2kilometer',
    r'centimeter2lightyear',
    r'centimeter2meter',
    r'centimeter2microinch',
    r'centimeter2micron',
    r'centimeter2mile',
    r'centimeter2millimeter',
    r'centimeter2parsec',
    r'centimeter2uknauticalmile',
    r'centimeter2usnauticalmile',
    r'centimeter2yard',
    # CHAINS #
    r'chain2centimeter',
    r'chain2decimeter',
    r'chain2foot',
    r'chain2furlong',
    r'chain2inch',
    r'chain2kilometer',
    r'chain2lightyear',
    r'chain2meter',
    r'chain2microinch',
    r'chain2micron',
    r'chain2mile',
    r'chain2millimeter',
    r'chain2parsec',
    r'chain2uknauticalmile',
    r'chain2usnauticalmile',
    r'chain2yard',
    # DECIMETERS #
    r'decimeter2centimeter',
    r'decimeter2chain',
    r'decimeter2foot',
    r'decimeter2furlong',
    r'decimeter2inch',
    r'decimeter2kilometer',
    r'decimeter2lightyear',
    r'decimeter2meter',
    r'decimeter2microinch',
    r'decimeter2micron',
    r'decimeter2mile',
    r'decimeter2millimeter',
    r'decimeter2parsec',
    r'decimeter2uknauticalmile',
    r'decimeter2usnauticalmile',
    r'decimeter2yard',
    # FEET #
    r'foot2centimeter',
    r'foot2chain',
    r'foot2decimeter',
    r'foot2furlong',
    r'foot2inch',
    r'foot2kilometer',
    r'foot2lightyear',
    r'foot2meter',
    r'foot2microinch',
    r'foot2micron',
    r'foot2mile',
    r'foot2millimeter',
    r'foot2parsec',
    r'foot2uknauticalmile',
    r'foot2usnauticalmile',
    r'foot2yard',
    # INCHES #
    r'inch2centimeter',
    r'inch2chain',
    r'inch2decimeter',
    r'inch2foot',
    r'inch2furlong',
    r'inch2kilometer',
    r'inch2lightyear',
    r'inch2meter',
    r'inch2microinch',
    r'inch2micron',
    r'inch2mile',
    r'inch2millimeter',
    r'inch2parsec',
    r'inch2uknauticalmile',
    r'inch2usnauticalmile',
    r'inch2yard',
    # KILOMETERS #
    r'kilometer2centimeter',
    r'kilometer2chain',
    r'kilometer2decimeter',
    r'kilometer2foot',
    r'kilometer2furlong',
    r'kilometer2inch',
    r'kilometer2lightyear',
    r'kilometer2meter',
    r'kilometer2mile',
    r'kilometer2microinch',
    r'kilometer2micron',
    r'kilometer2mile',
    r'kilometer2millimeter',
    r'kilometer2parsec',
    r'kilometer2uknauticalmile',
    r'kilometer2usnauticalmile',
    r'kilometer2yard',
    # METERS #
    r'meter2centimeter',
    r'meter2chain',
    r'meter2decimeter',
    r'meter2foot',
    r'meter2furlong',
    r'meter2inch',
    r'meter2kilometer',
    r'meter2lightyear',
    r'meter2mile',
    r'meter2microinch',
    r'meter2micron',
    r'meter2mile',
    r'meter2millimeter',
    r'meter2parsec',
    r'meter2uknauticalmile',
    r'meter2usnauticalmile',
    r'meter2yard',
    # MILES #
    r'mile2centimeter',
    r'mile2chain',
    r'mile2decimeter',
    r'mile2foot',
    r'mile2furlong',
    r'mile2inch',
    r'mile2kilometer',
    r'mile2lightyear',
    r'mile2meter',
    r'mile2microinch',
    r'mile2micron',
    r'mile2millimeter',
    r'mile2parsec',
    r'mile2uknauticalmile',
    r'mile2usnauticalmile',
    r'mile2yard',
    # MICRONS #
    r'micron2centimeter',
    r'micron2chain',
    r'micron2decimeter',
    r'micron2foot',
    r'micron2furlong',
    r'micron2inch',
    r'micron2kilometer',
    r'micron2lightyear',
    r'micron2meter',
    r'micron2microinch',
    r'micron2mile',
    r'micron2millimeter',
    r'micron2parsec',
    r'micron2uknauticalmile',
    r'micron2usnauticalmile',
    r'micron2yard',
    # YARDS #
    r'yard2centimeter',
    r'yard2chain',
    r'yard2decimeter',
    r'yard2foot',
    r'yard2furlong',
    r'yard2inch',
    r'yard2kilometer',
    r'yard2lightyear',
    r'yard2meter',
    r'yard2microinch',
    r'yard2micron',
    r'yard2mile',
    r'yard2millimeter',
    r'yard2parsec',
    r'yard2uknauticalmile',
    r'yard2usnauticalmile'
]


# CENTIMETERS #


def centimeter2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Chains."""
    return round(_length * 0.00049710, _round)


def centimeter2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Decimeters."""
    return round(_length * 0.1, _round)


def centimeter2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Feet."""
    return round(_length * 0.032808, _round)


def centimeter2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Furlongs."""
    return round(_length * 0.000049710, _round)


def centimeter2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Inches."""
    return round(_length * 0.39370, _round)


def centimeter2lightyear(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Lightyears."""
    return round(_length * 0.00000000000000000105700008, _round)


def centimeter2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Kilometers."""
    return round(_length * 0.00001, _round)


def centimeter2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Meters."""
    return round(_length * 0.01, _round)


def centimeter2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Microinches."""
    return round(_length * 393700.0, _round)


def centimeter2micron(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Microns."""
    return round(_length * 10000.0, _round)


def centimeter2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Miles."""
    return round(_length * 0.0000062137, _round)


def centimeter2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Millimeters."""
    return round(_length * 10.0, _round)


def centimeter2parsec(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Parsecs."""
    return round(_length * 0.00000000000000000032408, _round)


def centimeter2uknauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> UK Nautical Mile."""
    return round(_length * 0.0000053961, _round)


def centimeter2usnauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> US Nautical Mile."""
    return round(_length * 0.0000053996, _round)


def centimeter2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Centimeters -> Yards."""
    return round(_length * 0.010936, _round)


# CHAINS #


def chain2centimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Centimeters."""
    return round(_length * 2011.66767250050291691813, _round)


def chain2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Decimeters."""
    return round(_length * 201.166767250050291691813, _round)


def chain2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Feet."""
    return round(_length * 66.000, _round)


def chain2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Furlongs."""
    return round(_length * 0.10000, _round)


def chain2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Inches."""
    return round(_length * 792.00, _round)


def chain2lightyear(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Lightyears."""
    return round(_length * 0.0000000000000021264, _round)


def chain2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Kilometers."""
    return round(_length * 0.02011667672500502917, _round)


def chain2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Meters."""
    return round(_length * 20.11667672500502916918, _round)


def chain2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Microinches."""
    return round(_length * 792000000.0, _round)


def chain2micron(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Microns."""
    return round(_length * 20116676.72500502916918125126, _round)


def chain2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Miles."""
    return round(_length * 0.012500, _round)


def chain2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Millimeters."""
    return round(_length * 20116.67672500502916918125, _round)


def chain2parsec(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Parsecs."""
    return round(_length * 0.00000000000000065194, _round)


def chain2uknauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> UK Nautical Mile."""
    return round(_length * 0.010855, _round)


def chain2usnauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> US Nautical Mile."""
    return round(_length * 0.010862, _round)


def chain2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Chains -> Yards."""
    return round(_length * 22.000, _round)


# DECIMETERS #


def decimeter2centimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Centimeters."""
    return round(_length * 10.0, _round)


def decimeter2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Chains."""
    return round(_length * 0.0049710, _round)


def decimeter2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Feet."""
    return round(_length * 0.32808, _round)


def decimeter2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Furlongs."""
    return round(_length * 0.00049710, _round)


def decimeter2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Inches."""
    return round(_length * 3.9370, _round)


def decimeter2lightyear(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Lightyears."""
    return round(_length * 0.0000000000000000105700008, _round)


def decimeter2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Kilometers."""
    return round(_length * 0.0001, _round)


def decimeter2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Meters."""
    return round(_length * 0.1, _round)


def decimeter2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Microinches."""
    return round(_length * 3937000.0, _round)


def decimeter2micron(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Microns."""
    return round(_length * 100000.0, _round)


def decimeter2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Miles."""
    return round(_length * 0.000062137, _round)


def decimeter2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Millimeters."""
    return round(_length * 100.0, _round)


def decimeter2parsec(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Parsecs."""
    return round(_length * 0.0000000000000000032408, _round)


def decimeter2uknauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> UK Nautical Mile."""
    return round(_length * 0.000053961, _round)


def decimeter2usnauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> US Nautical Mile."""
    return round(_length * 0.000053996, _round)


def decimeter2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Decimeters -> Yards."""
    return round(_length * 0.10936, _round)


# FEET #


def foot2centimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Centimeters."""
    return round(_length * 30.480370641306998, _round)


def foot2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Chains."""
    return round(_length * 0.015151, _round)


def foot2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Decimeters."""
    return round(_length * 3.0480370641307, _round)


def foot2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Furlongs."""
    return round(_length * 0.0015151, _round)


def foot2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Inches."""
    return round(_length * 12.0, _round)


def foot2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Kilometers."""
    return round(_length * 0.000304803706413, _round)


def foot2lightyear(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Lightyears."""
    return round(_length * 0.000000000000000032217, _round)


def foot2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Meters."""
    return round(_length * 0.3948, _round)


def foot2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Microinches."""
    return round(_length * 12000000.0, _round)


def foot2micron(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Microns."""
    return round(_length * 304803.70641306998293099244, _round)


def foot2micron(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Microns."""
    return round(_length * 304803.70641306998293099244, _round)


def foot2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Miles."""
    return round(_length * 0.00018939, _round)


def foot2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Millimeters."""
    return round(_length * 304.803706413069983, _round)


def foot2parsec(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Parsecs."""
    return round(_length * 0.0000000000000000098779, _round)


def foot2uknauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> UK Nautical Miles."""
    return round(_length * 0.00016447, _round)


def foot2usnauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> US Nautical Miles."""
    return round(_length * 0.00016458, _round)


def foot2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Feet -> Yards."""
    return round(_length * 0.333333333333333, _round)


# INCHES #


def inch2centimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Centimeters."""
    return round(_length * 2.54000508001016, _round)


def inch2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Chains."""
    return round(_length * 0.0012626, _round)


def inch2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Decimeters."""
    return round(_length * 0.254000508001016, _round)


def inch2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Feet."""
    return round(_length * 0.083333333333333, _round)


def inch2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Furlong."""
    return round(_length * 0.00012626, _round)


def inch2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Kilometers."""
    return round(_length * 0.0000254000508, _round)


def inch2lightyear(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Lightyears."""
    return round(_length * 0.0000000000000000026848, _round)


def inch2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Meters."""
    return round(_length * 0.0254, _round)


def inch2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Microinches."""
    return round(_length * 1000000.0, _round)


def inch2micron(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Microns."""
    return round(_length * 25400.05080010160020320041, _round)


def inch2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Miles."""
    return round(_length * 0.000015783, _round)


def inch2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Millimeters."""
    return round(_length * 25.4000508001016, _round)


def inch2parsec(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Parsecs."""
    return round(_length * 0.00000000000000000082316, _round)


def inch2uknauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> UK Nautical Miles."""
    return round(_length * 0.000013706, _round)


def inch2usnauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> US Nautical Miles."""
    return round(_length * 0.000013715, _round)


def inch2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Inches -> Yards."""
    return round(_length * 0.027777777777778, _round)


# KILOMETERS #


def kilometer2centimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Centimeters."""
    return round(_length * 100000.0, _round)


def kilometer2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Chains."""
    return round(_length * 49.710, _round)


def kilometer2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Decimeters."""
    return round(_length * 10000.0, _round)


def kilometer2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Feet."""
    return round(_length * 3280.8, _round)


def kilometer2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Furlongs."""
    return round(_length * 4.9710, _round)


def kilometer2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Inches."""
    return round(_length * 39370.0, _round)


def kilometer2lightyear(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Lightyears."""
    return round(_length * 0.00000000000010570008, _round)


def kilometer2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Meters."""
    return round(_length * 1000.0, _round)


def kilometer2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Miles."""
    return round(_length * 0.621371, _round)


def kilometer2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Microinches."""
    return round(_length * 39370000000.0, _round)


def kilometer2micron(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Microns."""
    return round(_length * 1000000000, _round)


def kilometer2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Miles."""
    return round(_length * 0.62137, _round)


def kilometer2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Millimeters."""
    return round(_length * 1000000.0, _round)


def kilometer2parsec(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Parsecs."""
    return round(_length * 0.00000000000003240756, _round)


def kilometer2uknauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> UK Nautical Mile."""
    return round(_length * 0.53961, _round)


def kilometer2usnauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> US Nautical Mile."""
    return round(_length * 0.53996, _round)


def kilometer2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Kilometers -> Yards."""
    return round(_length * 1093.6, _round)


# METERS #


def meter2centimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Centimeters."""
    return round(_length * 100.0, _round)


def meter2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Chains."""
    return round(_length * 0.049710, _round)


def meter2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Decimeters."""
    return round(_length * 10.0, _round)


def meter2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Feet."""
    return round(_length * 3.2808, _round)


def meter2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Furlongs."""
    return round(_length * 0.0049710, _round)


def meter2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Inches."""
    return round(_length * 39.3700, _round)


def meter2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Kilometers."""
    return round(_length * 0.001, _round)


def meter2lightyear(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Lightyears."""
    return round(_length * 0.00000000000000010570008, _round)


def meter2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Miles."""
    return round(_length * 0.000621371, _round)


def meter2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Microinches."""
    return round(_length * 39370000.0, _round)


def meter2micron(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Microns."""
    return round(_length * 1000000.0, _round)


def meter2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Miles."""
    return round(_length * 0.00062137, _round)


def meter2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Millimeters."""
    return round(_length * 1000.0, _round)


def meter2parsec(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Parsecs."""
    return round(_length * 0.00000000000000003240756, _round)


def meter2uknauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> UK Nautical Mile."""
    return round(_length * 0.00053961, _round)


def meter2usnauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> US Nautical Mile."""
    return round(_length * 0.00053996, _round)


def meter2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Meters -> Yards."""
    return round(_length * 1.0936, _round)


# MILES #


def mile2centimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Centimeters."""
    return round(_length * 160934.70878864444694787325, _round)


def mile2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Chains."""
    return round(_length * 80.0, _round)


def mile2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Decimeters."""
    return round(_length * 16093.47087886444469478732, _round)


def mile2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Feet."""
    return round(_length * 5280.0, _round)


def mile2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Furlongs."""
    return round(_length * 8.0, _round)


def mile2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Inches."""
    return round(_length * 63360.0, _round)


def mile2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Kilometers."""
    return round(_length * 1.60934708788644446948, _round)


def mile2lightyear(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Lightyears."""
    return round(_length * 0.00000000000017011, _round)


def mile2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Meters."""
    return round(_length * 1609.34708788644446947873, _round)


def mile2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Microinches."""
    return round(_length * 63360000000.0, _round)


def mile2micron(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Microns."""
    return round(_length * 1609347087.88644446947873247823, _round)


def mile2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Millimeters."""
    return round(_length * 1609347.08788644446947873247823, _round)


def mile2parsec(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Parsecs."""
    return round(_length * 0.000000000000052155, _round)


def mile2uknauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> UK Nautical Miles."""
    return round(_length * 0.86842, _round)


def mile2usnauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> US Nautical Miles."""
    return round(_length * 0.86898, _round)


def mile2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Miles -> Yards."""
    return round(_length * 1760.0, _round)


# MICRONS #


def micron2centimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Centimeters."""
    return round(_length * 0.0001, _round)


def micron2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Chains."""
    return round(_length * 0.000000049710, _round)


def micron2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Decimeters."""
    return round(_length * 0.00001, _round)


def micron2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Feet."""
    return round(_length * 0.0000032808, _round)


def micron2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Furlongs."""
    return round(_length * 0.0000000049710, _round)


def micron2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Inches."""
    return round(_length * 0.000039370, _round)


def micron2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Kilometers."""
    return round(_length * 0.000000001, _round)


def micron2lightyear(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Lightyears."""
    return round(_length * 0.00000000000000000000010570, _round)


def micron2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Meters."""
    return round(_length * 0.000001, _round)


def micron2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Microinches."""
    return round(_length * 39.370, _round)


def micron2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Miles."""
    return round(_length * 0.00000000062137, _round)


def micron2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Millimeters."""
    return round(_length * 0.001, _round)


def micron2parsec(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Parsecs."""
    return round(_length * 0.000000000000000000000032408, _round)


def micron2uknauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> UK Nautical Miles."""
    return round(_length * 0.00000000053961, _round)


def micron2usnauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> US Nautical Miles."""
    return round(_length * 0.00000000053996, _round)


def micron2yard(_length: Union[float, int], _round: int = 3) -> float:
    """Microns -> Yards."""
    return round(_length * 0.00049374, _round)


# YARDS #


def yard2centimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Centimeters."""
    return round(_length * 91.4411119239209948793, _round)


def yard2chain(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Chains."""
    return round(_length * 0.045454, _round)


def yard2decimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Decimeters."""
    return round(_length * 9.14411119239209948793, _round)


def yard2foot(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Feet."""
    return round(_length * 3.0, _round)


def yard2furlong(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Furlongs."""
    return round(_length * 0.0045454, _round)


def yard2inch(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Inches."""
    return round(_length * 36.0, _round)


def yard2kilometer(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Kilometers."""
    return round(_length * 0.00091441111923920995, _round)


def yard2lightyear(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Lightyears."""
    return round(_length * 0.000000000000000096652, _round)


def yard2meter(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Meters."""
    return round(_length * 0.9144, _round)


def yard2microinch(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Microinches."""
    return round(_length * 36000000.0, _round)


def yard2micron(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Microns."""
    return round(_length * 914411.11923920994879297732, _round)


def yard2mile(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Miles."""
    return round(_length * 0.00056818, _round)


def yard2millimeter(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Millimeters."""
    return round(_length * 914.41111923920994879298, _round)


def yard2parsec(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> Parsecs."""
    return round(_length * 0.000000000000000029634, _round)


def yard2uknauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> UK Nautical Miles."""
    return round(_length * 0.00049342, _round)


def yard2usnauticalmile(_length: Union[float, int], _round: int = 3) -> float:
    """Yards -> US Nautical Miles."""
    return round(_length * 0.00049374, _round)

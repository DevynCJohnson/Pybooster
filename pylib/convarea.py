#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Area measurement conversions

@file convarea.py
@package pybooster.convarea
@version 2018.10.13
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
    # ACRES #
    r'acre2hectare',
    r'acre2sqfoot',
    r'acre2sqinch',
    r'acre2sqkilometer',
    r'acre2sqmeter',
    r'acre2sqmile',
    r'acre2sqyard',
    # HECTARES #
    r'hectare2acre',
    r'hectare2sqfoot',
    r'hectare2sqinch',
    r'hectare2sqkilometer',
    r'hectare2sqmeter',
    r'hectare2sqmile',
    r'hectare2sqyard',
    # SQUARE FEET #
    r'sqfoot2acre',
    r'sqfoot2hectare',
    r'sqfoot2sqcentimeter',
    r'sqfoot2sqinch',
    r'sqfoot2sqkilometer',
    r'sqfoot2sqmeter',
    r'sqfoot2sqmicroinch',
    r'sqfoot2sqmile',
    r'sqfoot2sqmillimeter',
    r'sqfoot2sqyard',
    # SQUARE KILOMETERS #
    r'sqkilometer2acre',
    r'sqkilometer2hectare',
    r'sqkilometer2sqcentimeter',
    r'sqkilometer2sqfoot',
    r'sqkilometer2sqinch',
    r'sqkilometer2sqmeter',
    r'sqkilometer2sqmicrometer',
    r'sqkilometer2sqmile',
    r'sqkilometer2sqmillimeter',
    r'sqkilometer2sqyard',
    # SQUARE METERS #
    r'sqmeter2acre',
    r'sqmeter2hectare',
    r'sqmeter2sqcentimeter',
    r'sqmeter2sqfoot',
    r'sqmeter2sqinch',
    r'sqmeter2sqkilometer',
    r'sqmeter2sqyard',
    # SQUARE MILES #
    r'sqmile2acre',
    r'sqmile2hectare',
    r'sqmile2sqcentimeter',
    r'sqmile2sqfoot',
    r'sqmile2sqinch',
    r'sqmile2sqkilometer',
    r'sqmile2sqmeter',
    r'sqmile2sqyard'
]


# ACRES #


def acre2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Hectares"""
    return round(_area * 0.404678078588483, _round)


def acre2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Feet"""
    return round(_area * 43560.0, _round)


def acre2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Inches"""
    return round(_area * 6272600.0, _round)


def acre2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Kilometers"""
    return round(_area * 0.004046780785885, _round)


def acre2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Meters"""
    return round(_area * 4046.780785884828619, _round)


def acre2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Miles"""
    return round(_area * 0.0015625, _round)


def acre2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Yards"""
    return round(_area * 4840.0, _round)


# HECTARES #


def hectare2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Acres"""
    return round(_area * 2.4711, _round)


def hectare2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Feet"""
    return round(_area * 107640.0, _round)


def hectare2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Inches"""
    return round(_area * 15500000.0, _round)


def hectare2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Kilometers"""
    return round(_area * 0.01, _round)


def hectare2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Meters"""
    return round(_area * 10000.0, _round)


def hectare2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Miles"""
    return round(_area * 0.0038610, _round)


def hectare2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Yards"""
    return round(_area * 11960.0, _round)


# SQUARE FEET #


def sqfoot2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Acres"""
    return round(_area * 0.000022956841139, _round)


def sqfoot2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Hectares"""
    return round(_area * 0.000009290226682, _round)


def sqfoot2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Centimeters"""
    return round(_area * 929.022668153102936, _round)


def sqfoot2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Inches"""
    return round(_area * 144.00, _round)


def sqfoot2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Kilometers"""
    return round(_area * 0.000000092902267, _round)


def sqfoot2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Meters"""
    return round(_area * 0.09290226681531, _round)


def sqfoot2sqmicroinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Microinches"""
    return round(_area * 144000000000000.0, _round)


def sqfoot2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Miles"""
    return round(_area * 0.000000035870579, _round)


def sqfoot2sqmillimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Millimeters"""
    return round(_area * 92903.0, _round)


def sqfoot2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Yards"""
    return round(_area * 0.11111, _round)


# SQUARE KILOMETERS #


def sqkilometer2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Acres"""
    return round(_area * 247.11, _round)


def sqkilometer2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Hectares"""
    return round(_area * 100.0, _round)


def sqkilometer2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Centimeters"""
    return round(_area * 10000000000.0, _round)


def sqkilometer2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Feet"""
    return round(_area * 10764000.0, _round)


def sqkilometer2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Inches"""
    return round(_area * 1550000000.0, _round)


def sqkilometer2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Meters"""
    return round(_area * 1000000.0, _round)


def sqkilometer2sqmicrometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Micrometers"""
    return round(_area * 1000000000000000000.0, _round)


def sqkilometer2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Miles"""
    return round(_area * 0.38610, _round)


def sqkilometer2sqmillimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Millimeters"""
    return round(_area * 1000000000000.0, _round)


def sqkilometer2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Yards"""
    return round(_area * 1196000.0, _round)


# SQUARE METERS #


def sqmeter2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Acres"""
    return round(_area * 0.00024711, _round)


def sqmeter2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Hectares"""
    return round(_area * 0.0001, _round)


def sqmeter2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Centimeters"""
    return round(_area * 10000.0, _round)


def sqmeter2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Feet"""
    return round(_area * 10.764, _round)


def sqmeter2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Inches"""
    return round(_area * 1550.0, _round)


def sqmeter2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Kilometers"""
    return round(_area * 0.000001, _round)


def sqmeter2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Yards"""
    return round(_area * 1.1960, _round)


# SQUARE MILES #


def sqmile2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Acres"""
    return round(_area * 640.00, _round)


def sqmile2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Hectares"""
    return round(_area * 259.000259000259, _round)


def sqmile2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Centimeters"""
    return round(_area * 25900000000.0, _round)


def sqmile2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Feet"""
    return round(_area * 27878000.0, _round)


def sqmile2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Inches"""
    return round(_area * 4014500000.0, _round)


def sqmile2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Kilometers"""
    return round(_area * 2.59000259000259000, _round)


def sqmile2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Meters"""
    return round(_area * 2590000.0, _round)


def sqmile2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Yards"""
    return round(_area * 3097600.0, _round)

#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Area measurement conversions.

@file convarea.py
@package pybooster.convarea
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
    # ACRES #
    r'acre2hectare',
    r'acre2sqcentimeter',
    r'acre2sqfoot',
    r'acre2sqinch',
    r'acre2sqkilometer',
    r'acre2sqmeter',
    r'acre2sqmicroinch',
    r'acre2sqmicrometer',
    r'acre2sqmile',
    r'acre2sqmillimeter',
    r'acre2sqyard',
    # HECTARES #
    r'hectare2acre',
    r'hectare2sqcentimeter',
    r'hectare2sqfoot',
    r'hectare2sqinch',
    r'hectare2sqkilometer',
    r'hectare2sqmeter',
    r'hectare2sqmicroinch',
    r'hectare2sqmicrometer',
    r'hectare2sqmile',
    r'hectare2sqmillimeter',
    r'hectare2sqyard',
    # SQUARE CENTIMETERS #
    r'sqcentimeter2acre',
    r'sqcentimeter2hectare',
    r'sqcentimeter2sqfoot',
    r'sqcentimeter2sqinch',
    r'sqcentimeter2sqkilometer',
    r'sqcentimeter2sqmeter',
    r'sqcentimeter2sqmicroinch',
    r'sqcentimeter2sqmicrometer',
    r'sqcentimeter2sqmile',
    r'sqcentimeter2sqmillimeter',
    r'sqcentimeter2sqyard',
    # SQUARE FEET #
    r'sqfoot2acre',
    r'sqfoot2hectare',
    r'sqfoot2sqcentimeter',
    r'sqfoot2sqinch',
    r'sqfoot2sqkilometer',
    r'sqfoot2sqmeter',
    r'sqfoot2sqmicroinch',
    r'sqfoot2sqmicrometer',
    r'sqfoot2sqmile',
    r'sqfoot2sqmillimeter',
    r'sqfoot2sqyard',
    # SQUARE INCHES #
    r'sqinch2acre',
    r'sqinch2hectare',
    r'sqinch2sqcentimeter',
    r'sqinch2sqfoot',
    r'sqinch2sqkilometer',
    r'sqinch2sqmeter',
    r'sqinch2sqmicroinch',
    r'sqinch2sqmicrometer',
    r'sqinch2sqmile',
    r'sqinch2sqmillimeter',
    r'sqinch2sqyard',
    # SQUARE KILOMETERS #
    r'sqkilometer2acre',
    r'sqkilometer2hectare',
    r'sqkilometer2sqcentimeter',
    r'sqkilometer2sqfoot',
    r'sqkilometer2sqinch',
    r'sqkilometer2sqmeter',
    r'sqkilometer2sqmicroinch',
    r'sqkilometer2sqmicrometer',
    r'sqkilometer2sqmile',
    r'sqkilometer2sqmillimeter',
    r'sqkilometer2sqyard',
    # SQUARE MICROINCHES #
    r'sqmicroinch2acre',
    r'sqmicroinch2hectare',
    r'sqmicroinch2sqcentimeter',
    r'sqmicroinch2sqfoot',
    r'sqmicroinch2sqinch',
    r'sqmicroinch2sqmeter',
    r'sqmicroinch2sqkilometer',
    r'sqmicroinch2sqmicrometer',
    r'sqmicroinch2sqmile',
    r'sqmicroinch2sqmillimeter',
    r'sqmicroinch2sqyard',
    # SQUARE MICROMETERS #
    r'sqmicrometer2acre',
    r'sqmicrometer2hectare',
    r'sqmicrometer2sqcentimeter',
    r'sqmicrometer2sqfoot',
    r'sqmicrometer2sqinch',
    r'sqmicrometer2sqmeter',
    r'sqmicrometer2sqkilometer',
    r'sqmicrometer2sqmicroinch',
    r'sqmicrometer2sqmile',
    r'sqmicrometer2sqmillimeter',
    r'sqmicrometer2sqyard',
    # SQUARE METERS #
    r'sqmeter2acre',
    r'sqmeter2hectare',
    r'sqmeter2sqcentimeter',
    r'sqmeter2sqfoot',
    r'sqmeter2sqinch',
    r'sqmeter2sqkilometer',
    r'sqmeter2sqmicrometer',
    r'sqmeter2sqmicroinch',
    r'sqmeter2sqmile',
    r'sqmeter2sqmillimeter',
    r'sqmeter2sqyard',
    # SQUARE MILES #
    r'sqmile2acre',
    r'sqmile2hectare',
    r'sqmile2sqcentimeter',
    r'sqmile2sqfoot',
    r'sqmile2sqinch',
    r'sqmile2sqkilometer',
    r'sqmile2sqmeter',
    r'sqmile2sqmicroinch',
    r'sqmile2sqmicrometer',
    r'sqmile2sqmillimeter',
    r'sqmile2sqyard',
    # SQUARE MILLIMETERS #
    r'sqmillimeter2acre',
    r'sqmillimeter2hectare',
    r'sqmillimeter2sqcentimeter',
    r'sqmillimeter2sqfoot',
    r'sqmillimeter2sqinch',
    r'sqmillimeter2sqkilometer',
    r'sqmillimeter2sqmeter',
    r'sqmillimeter2sqmicroinch',
    r'sqmillimeter2sqmicrometer',
    r'sqmillimeter2sqmile',
    r'sqmillimeter2sqyard',
    # SQUARE YARDS #
    r'sqyard2acre',
    r'sqyard2hectare',
    r'sqyard2sqcentimeter',
    r'sqyard2sqfoot',
    r'sqyard2sqinch',
    r'sqyard2sqkilometer',
    r'sqyard2sqmeter',
    r'sqyard2sqmicroinch',
    r'sqyard2sqmicrometer',
    r'sqyard2sqmile',
    r'sqyard2sqmillimeter',
]


# ACRES #


def acre2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Hectares."""
    return round(_area * 0.404678078588483, _round)


def acre2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Centimeters."""
    return round(_area * 40467807.85884828618833717778, _round)


def acre2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Feet."""
    return round(_area * 43560.0, _round)


def acre2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Inches."""
    return round(_area * 6272600.0, _round)


def acre2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Kilometers."""
    return round(_area * 0.004046780785885, _round)


def acre2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Meters."""
    return round(_area * 4046.780785884828619, _round)


def acre2sqmicroinch(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Microinches."""
    return round(_area * 6272800000000000000.0, _round)


def acre2sqmicrometer(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Micrometers."""
    return round(_area * 4046780785884828.61883371777750799239, _round)


def acre2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Miles."""
    return round(_area * 0.0015625, _round)


def acre2sqmillimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Millimeters."""
    return round(_area * 4046780785.88482861883371777751, _round)


def acre2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Acres -> Square Yards."""
    return round(_area * 4840.0, _round)


# HECTARES #


def hectare2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Acres."""
    return round(_area * 2.4711, _round)


def hectare2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Centimeter."""
    return round(_area * 100000000.0, _round)


def hectare2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Feet."""
    return round(_area * 107640.0, _round)


def hectare2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Inches."""
    return round(_area * 15500000.0, _round)


def hectare2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Kilometers."""
    return round(_area * 0.01, _round)


def hectare2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Meters."""
    return round(_area * 10000.0, _round)


def hectare2sqmicroinch(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Microinches."""
    return round(_area * 15500000000000000000.0, _round)


def hectare2sqmicrometer(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Micrometers."""
    return round(_area * 10000000000000000, _round)


def hectare2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Miles."""
    return round(_area * 0.0038610, _round)


def hectare2sqmillimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Milliters."""
    return round(_area * 10000000000.0, _round)


def hectare2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Hectares -> Square Yards."""
    return round(_area * 11960.0, _round)


# SQUARE CENTIMETERS #


def sqcentimeter2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Centimeters -> Acres."""
    return round(_area * 0.000000024711, _round)


def sqcentimeter2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Centimeters -> Hectares."""
    return round(_area * 0.00000001, _round)


def sqcentimeter2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Square Centimeters -> Square Feet."""
    return round(_area * 0.0010764, _round)


def sqcentimeter2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Centimeters -> Square Inches."""
    return round(_area * 0.15500, _round)


def sqcentimeter2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Centimeters -> Square Kilometers."""
    return round(_area * 0.0000000001, _round)


def sqcentimeter2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Centimeters -> Square Meters."""
    return round(_area * 0.0001, _round)


def sqcentimeter2sqmicroinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Centimeters -> Square Microinches."""
    return round(_area * 155000000000.0, _round)


def sqcentimeter2sqmicrometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Centimeters -> Square Micrometers."""
    return round(_area * 100000000.0, _round)


def sqcentimeter2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Square Centimeters -> Square Miles."""
    return round(_area * 0.000000000038610, _round)


def sqcentimeter2sqmillimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Centimeters -> Square Milliters."""
    return round(_area * 100.0, _round)


def sqcentimeter2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Square Centimeters -> Square Yards."""
    return round(_area * 0.00011960, _round)


# SQUARE FEET #


def sqfoot2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Acres."""
    return round(_area * 0.000022956841139, _round)


def sqfoot2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Hectares."""
    return round(_area * 0.000009290226682, _round)


def sqfoot2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Centimeters."""
    return round(_area * 929.022668153102936, _round)


def sqfoot2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Inches."""
    return round(_area * 144.0, _round)


def sqfoot2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Kilometers."""
    return round(_area * 0.000000092902267, _round)


def sqfoot2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Meters."""
    return round(_area * 0.09290226681531, _round)


def sqfoot2sqmicroinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Microinches."""
    return round(_area * 144000000000000.0, _round)


def sqfoot2sqmicrometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Micrometers."""
    return round(_area * 92902266815.31029357116313638053, _round)


def sqfoot2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Miles."""
    return round(_area * 0.000000035870579, _round)


def sqfoot2sqmillimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Millimeters."""
    return round(_area * 92903.0, _round)


def sqfoot2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Square Feet -> Square Yards."""
    return round(_area * 0.11111, _round)


# SQUARE INCHES #


def sqinch2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Inches -> Acres."""
    return round(_area * 0.00000015942, _round)


def sqinch2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Inches -> Hectares."""
    return round(_area * 0.0000000645161290322580645161, _round)


def sqinch2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Inches -> Square Centimeters."""
    return round(_area * 6.4516129032258064516129032258, _round)


def sqinch2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Square Inches -> Square Feet."""
    return round(_area * 0.0069444, _round)


def sqinch2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Inches -> Square Kilometers."""
    return round(_area * 0.00000000064516129032258064516129032258, _round)


def sqinch2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Inches -> Square Meters."""
    return round(_area * 0.00064516129032258064516129032258, _round)


def sqinch2sqmicroinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Inches -> Square Microinches."""
    return round(_area * 1000000000000.0, _round)


def sqinch2sqmicrometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Inches -> Square Micrometers."""
    return round(_area * 645161290.32258064516129032258, _round)


def sqinch2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Square Inches -> Square Miles."""
    return round(_area * 0.00000000024910, _round)


def sqinch2sqmillimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Inches -> Square Millimeters."""
    return round(_area * 645.16129032258064516129032258, _round)


def sqinch2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Square Inches -> Square Yards."""
    return round(_area * 0.00077160, _round)


# SQUARE KILOMETERS #


def sqkilometer2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Acres."""
    return round(_area * 247.11, _round)


def sqkilometer2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Hectares."""
    return round(_area * 100.0, _round)


def sqkilometer2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Centimeters."""
    return round(_area * 10000000000.0, _round)


def sqkilometer2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Feet."""
    return round(_area * 10764000.0, _round)


def sqkilometer2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Inches."""
    return round(_area * 1550000000.0, _round)


def sqkilometer2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Meters."""
    return round(_area * 1000000.0, _round)


def sqkilometer2sqmicroinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Microinches."""
    return round(_area * 1550000000000000000000.0, _round)


def sqkilometer2sqmicrometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Micrometers."""
    return round(_area * 1000000000000000000.0, _round)


def sqkilometer2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Miles."""
    return round(_area * 0.38610, _round)


def sqkilometer2sqmillimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Millimeters."""
    return round(_area * 1000000000000.0, _round)


def sqkilometer2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Square Kilometers -> Square Yards."""
    return round(_area * 1196000.0, _round)


# SQUARE MICORINCHES #


def sqmicroinch2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Microinches -> Acres."""
    return round(_area * 0.00000000000000000015942, _round)


def sqmicroinch2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Microinches -> Hectares."""
    return round(_area * 0.00000000000000000006451612903226, _round)


def sqmicroinch2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Microinches -> Square Centimeters."""
    return round(_area * 0.0000000000064516129032258064516129032258065, _round)


def sqmicroinch2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Square Microinches -> Square Feet."""
    return round(_area * 0.0000000000000069443, _round)


def sqmicroinch2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Microinches -> Square Inches."""
    return round(_area * 0.00000000000099998, _round)


def sqmicroinch2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Microinches -> Square Meters."""
    return round(_area * 0.00000000000000064516129032258064516129032258065, _round)


def sqmicroinch2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Microinches -> Square Kilometers."""
    return round(_area * 6.4516129032258064516129032258065 ** -22, _round)


def sqmicroinch2sqmicrometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Microinches -> Square Micrometers."""
    return round(_area * 0.00064516129032258065, _round)


def sqmicroinch2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Square Microinches -> Square Miles."""
    return round(_area * 0.00000000000000000000024909, _round)


def sqmicroinch2sqmillimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Microinches -> Square Millimeters."""
    return round(_area * 0.00000000064516129032258065, _round)


def sqmicroinch2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Square Microinches -> Square Yards."""
    return round(_area * 0.00000000000000077159, _round)


# SQUARE MICORMETERS #


def sqmicrometer2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Micrometers -> Acres."""
    return round(_area * 0.00000000000000024711, _round)


def sqmicrometer2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Micrometers -> Hectares."""
    return round(_area * 0.0000000000000001, _round)


def sqmicrometer2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Micrometers -> Square Centimeters."""
    return round(_area * 0.00000001, _round)


def sqmicrometer2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Square Micrometers -> Square Feet."""
    return round(_area * 0.000000000010764, _round)


def sqmicrometer2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Micrometers -> Square Inches."""
    return round(_area * 0.0000000015500, _round)


def sqmicrometer2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Micrometers -> Square Meters."""
    return round(_area * 0.000000000001, _round)


def sqmicrometer2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Micrometers -> Square Kilometers."""
    return round(_area * 0.000000000000000001, _round)


def sqmicrometer2sqmicroinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Micrometers -> Square Microinches."""
    return round(_area * 1550.0, _round)


def sqmicrometer2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Square Micrometers -> Square Miles."""
    return round(_area * 0.00000000000000000038610, _round)


def sqmicrometer2sqmillimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Micrometers -> Square Millimeters."""
    return round(_area * 0.000001, _round)


def sqmicrometer2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Square Micrometers -> Square Yards."""
    return round(_area * 0.0000000000011960, _round)


# SQUARE METERS #


def sqmeter2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Acres."""
    return round(_area * 0.00024711, _round)


def sqmeter2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Hectares."""
    return round(_area * 0.0001, _round)


def sqmeter2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Centimeters."""
    return round(_area * 10000.0, _round)


def sqmeter2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Feet."""
    return round(_area * 10.764, _round)


def sqmeter2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Inches."""
    return round(_area * 1550.0, _round)


def sqmeter2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Kilometers."""
    return round(_area * 0.000001, _round)


def sqmeter2sqmicrometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Micrometers."""
    return round(_area * 1000000000000.0, _round)


def sqmeter2sqmicroinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Microinches."""
    return round(_area * 1550000000000000, _round)


def sqmeter2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Miles."""
    return round(_area * 0.00000038610, _round)


def sqmeter2sqmillimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Millimeters."""
    return round(_area * 1000000, _round)


def sqmeter2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Square Meters -> Square Yards."""
    return round(_area * 1.1960, _round)


# SQUARE MILES #


def sqmile2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Acres."""
    return round(_area * 640.0, _round)


def sqmile2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Hectares."""
    return round(_area * 259.000259000259, _round)


def sqmile2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Centimeters."""
    return round(_area * 25900000000.0, _round)


def sqmile2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Feet."""
    return round(_area * 27878000.0, _round)


def sqmile2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Inches."""
    return round(_area * 4014500000.0, _round)


def sqmile2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Kilometers."""
    return round(_area * 2.59000259000259000, _round)


def sqmile2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Meters."""
    return round(_area * 2590000.0, _round)


def sqmile2sqmicrometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Micrometers."""
    return round(_area * 2590002590002590002.59000259000259000259, _round)


def sqmile2sqmicroinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Microinches."""
    return round(_area * 4014600000000000000000.0, _round)


def sqmile2sqmillimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Millimeters."""
    return round(_area * 2590002590002.59000259000259000259, _round)


def sqmile2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Square Miles -> Square Yards."""
    return round(_area * 3097600.0, _round)


# SQUARE MILLIMETERS #


def sqmillimeter2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Millimeters -> Acres."""
    return round(_area * 0.00000000024711, _round)


def sqmillimeter2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Millimeters -> Hectares."""
    return round(_area * 0.0000000001, _round)


def sqmillimeter2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Millimeters -> Square Centimeters."""
    return round(_area * 0.01, _round)


def sqmillimeter2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Square Millimeters -> Square Feet."""
    return round(_area * 0.000010764, _round)


def sqmillimeter2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Millimeters -> Square Inches."""
    return round(_area * 0.0015500, _round)


def sqmillimeter2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Millimeters -> Square Kilometers."""
    return round(_area * 0.000000000001, _round)


def sqmillimeter2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Millimeters -> Square Meters."""
    return round(_area * 0.000001, _round)


def sqmillimeter2sqmicrometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Millimeters -> Square Micrometers."""
    return round(_area * 1000000, _round)


def sqmillimeter2sqmicroinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Millimeters -> Square Microinches."""
    return round(_area * 1550000000.0, _round)


def sqmillimeter2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Square Millimeters -> Square Miles."""
    return round(_area * 0.00000000000038610, _round)


def sqmillimeter2sqyard(_area: Union[float, int], _round: int = 3) -> float:
    """Square Millimeters -> Square Yards."""
    return round(_area * 0.0000011960, _round)


# SQUARE YARDS #


def sqyard2acre(_area: Union[float, int], _round: int = 3) -> float:
    """Square Yards -> Acres."""
    return round(_area * 0.00020661, _round)


def sqyard2hectare(_area: Union[float, int], _round: int = 3) -> float:
    """Square Yards -> Hectares."""
    return round(_area * 0.00008361204013377926, _round)


def sqyard2sqcentimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Yards -> Square Centimeters."""
    return round(_area * 8361.2040133779264214046822742475, _round)


def sqyard2sqfoot(_area: Union[float, int], _round: int = 3) -> float:
    """Square Yards -> Square Feet."""
    return round(_area * 9.0, _round)


def sqyard2sqinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Yards -> Square Inches."""
    return round(_area * 1296.0, _round)


def sqyard2sqkilometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Yards -> Square Kilometers."""
    return round(_area * 0.00000083612040133779264214046822742475, _round)


def sqyard2sqmeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Yards -> Square Meters."""
    return round(_area * 0.83612040133779264214046822742475, _round)


def sqyard2sqmicrometer(_area: Union[float, int], _round: int = 3) -> float:
    """Square Yards -> Square Micrometers."""
    return round(_area * 836120401337.79264214046822742475, _round)


def sqyard2sqmicroinch(_area: Union[float, int], _round: int = 3) -> float:
    """Square Yards -> Square Microinches."""
    return round(_area * 1296000000000000.0, _round)


def sqyard2sqmile(_area: Union[float, int], _round: int = 3) -> float:
    """Square Yards -> Square Miles."""
    return round(_area * 0.00000032283, _round)


def sqyard2sqmillimeter(_area: Union[float, int], _round: int = 3) -> float:
    """Square Yards -> Square Millimeters."""
    return round(_area * 836120.40133779264214046822742475, _round)

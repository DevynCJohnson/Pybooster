#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Volume measurement conversions.

@file convvolume.py
@package pybooster.convvolume
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
    # CUBIC INCHES #
    r'cubicinch2cancup',
    r'cubicinch2cubicmeter',
    r'cubicinch2dryquart',
    r'cubicinch2liter',
    r'cubicinch2metriccup',
    r'cubicinch2metrictablespoon',
    r'cubicinch2metricteaspoon',
    r'cubicinch2ukfluidounce',
    r'cubicinch2ukgallon',
    r'cubicinch2ukgill',
    r'cubicinch2ukpint',
    r'cubicinch2ukquart',
    r'cubicinch2uktablespoon',
    r'cubicinch2ukteaspoon',
    r'cubicinch2uscup',
    r'cubicinch2usdrygallon',
    r'cubicinch2usdrypint',
    r'cubicinch2usfluidounce',
    r'cubicinch2usgill',
    r'cubicinch2usliquidgallon',
    r'cubicinch2usliquidpint',
    r'cubicinch2usquart',
    r'cubicinch2ustablespoon',
    r'cubicinch2usteaspoon',
    # CUBIC METERS #
    r'cubicmeter2cubicinch',
    # LITERS #
    r'liter2cubicinch',
    # PINTS #
    r'usdrypint2ukgallon',
    r'usdrypint2usdrygallon',
    r'usdrypint2usliquidgallon',
    r'usliquidpint2ukgallon',
    r'usliquidpint2usdrygallon',
    r'usliquidpint2usliquidgallon',
    r'ukpint2ukgallon',
    r'ukpint2usdrygallon',
    r'ukpint2usliquidgallon'
]


# CUBIC INCHES #


def cubicinch2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Canadian Cups."""
    return round(_volume * 0.072093, _round)


def cubicinch2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Cubic Meters."""
    return round(_volume * 0.000016386995, _round)


def cubicinch2dryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Dry Quarts."""
    return round(_volume * 0.014881, _round)


def cubicinch2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Liters."""
    return round(_volume * 0.016386995, _round)


def cubicinch2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Metric Cups."""
    return round(_volume * 0.065548, _round)


def cubicinch2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Metric Tablespoons."""
    return round(_volume * 1.0925, _round)


def cubicinch2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Metric Teaspoons."""
    return round(_volume * 3.2774, _round)


def cubicinch2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Fluid Ounces."""
    return round(_volume * 0.57674, _round)


def cubicinch2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Gallons."""
    return round(_volume * 0.0036047, _round)


def cubicinch2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Gills."""
    return round(_volume * 0.11535, _round)


def cubicinch2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Pints."""
    return round(_volume * 0.028837, _round)


def cubicinch2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Quarts."""
    return round(_volume * 0.014419, _round)


def cubicinch2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Tablespoons."""
    return round(_volume * 1.1535, _round)


def cubicinch2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Teaspoons."""
    return round(_volume * 4.6139, _round)


def cubicinch2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Cups."""
    return round(_volume * 0.069264, _round)


def cubicinch2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Dry Gallons."""
    return round(_volume * 0.0037202, _round)


def cubicinch2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Dry Pints."""
    return round(_volume * 0.029762, _round)


def cubicinch2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Fluid Ounces."""
    return round(_volume * 0.55411, _round)


def cubicinch2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Gills."""
    return round(_volume * 0.13853, _round)


def cubicinch2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Liquid Gallons."""
    return round(_volume * 0.0043290, _round)


def cubicinch2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Liquid Pints."""
    return round(_volume * 0.034632, _round)


def cubicinch2usquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US (Liquid) Quarts."""
    return round(_volume * 0.017316, _round)


def cubicinch2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Tablespoons."""
    return round(_volume * 1.1082, _round)


def cubicinch2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Teaspoons."""
    return round(_volume * 3.3247, _round)


# CUBIC METERS #


def cubicmeter2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> Cubic Inches."""
    return round(_volume * 61024.0, _round)


# LITERS #


def liter2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> Cubic Inches."""
    return round(_volume * 61.024, _round)


# PINTS #


def usdrypint2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> UK Gallons."""
    return round(_volume * 0.12112, _round)


def usdrypint2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Dry Gallons."""
    return round(_volume * 0.12500, _round)


def usdrypint2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Liquid Gallons."""
    return round(_volume * 0.14546, _round)


def usliquidpint2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> UK Gallons."""
    return round(_volume * 0.10408, _round)


def usliquidpint2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Dry Gallons."""
    return round(_volume * 0.10742, _round)


def usliquidpint2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Liquid Gallons."""
    return round(_volume * 0.12500, _round)


def ukpint2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> UK Gallons."""
    return round(_volume * 0.12500, _round)


def ukpint2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Dry Gallons."""
    return round(_volume * 0.12901, _round)


def ukpint2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Liquid Gallons."""
    return round(_volume * 0.15012, _round)

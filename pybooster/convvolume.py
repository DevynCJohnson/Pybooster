#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
@file convvolume.py
@package pybooster.convvolume
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@brief Measurement (Volume) Conversions
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


__all__ = [
    # CUBIC INCHES
    'cuin2cancups',
    'cuin2cum',
    'cuin2dryqt',
    'cuin2l',
    'cuin2metriccups',
    'cuin2metrictbl',
    'cuin2metrictsp',
    'cuin2ukfloz',
    'cuin2ukgal',
    'cuin2ukgills',
    'cuin2ukpt',
    'cuin2ukqt',
    'cuin2uktbl',
    'cuin2uktsp',
    'cuin2uscups',
    'cuin2usdrygal',
    'cuin2usdrypt',
    'cuin2usfloz',
    'cuin2usgills',
    'cuin2usliqgal',
    'cuin2usliqpt',
    'cuin2usqt',
    'cuin2ustbl',
    'cuin2ustsp',
    # CUBIC METERS
    'cum2cuin',
    # LITERS
    'l2cuin',
    # PINTS
    'usdrypt2ukgal',
    'usdrypt2usdrygal',
    'usdrypt2usliqgal',
    'usliqpt2ukgal',
    'usliqpt2usdrygal',
    'usliqpt2usliqgal',
    'ukpt2ukgal',
    'ukpt2usdrygal',
    'ukpt2usliqgal',
]


# CUBIC INCHES


def cuin2cancups(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> Canadian Cups"""
    return round(_volume * 0.072093, _round)


def cuin2cum(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> Cubic Meters"""
    return round(_volume * 0.000016386995, _round)


def cuin2dryqt(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> Dry Quarts"""
    return round(_volume * 0.014881, _round)


def cuin2l(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> Liters"""
    return round(_volume * 0.016386995, _round)


def cuin2metriccups(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> Metric Cups"""
    return round(_volume * 0.065548, _round)


def cuin2metrictbl(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> Metric Tablespoons"""
    return round(_volume * 1.0925, _round)


def cuin2metrictsp(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> Metric Teaspoons"""
    return round(_volume * 3.2774, _round)


def cuin2ukfloz(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> UK Fluid Ounces"""
    return round(_volume * 0.57674, _round)


def cuin2ukgal(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> UK Gallons"""
    return round(_volume * 0.0036047, _round)


def cuin2ukgills(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> UK Gills"""
    return round(_volume * 0.11535, _round)


def cuin2ukpt(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> UK Pints"""
    return round(_volume * 0.028837, _round)


def cuin2ukqt(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> UK Quarts"""
    return round(_volume * 0.014419, _round)


def cuin2uktbl(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> UK Tablespoons"""
    return round(_volume * 1.1535, _round)


def cuin2uktsp(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> UK Teaspoons"""
    return round(_volume * 4.6139, _round)


def cuin2uscups(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> US Cups"""
    return round(_volume * 0.069264, _round)


def cuin2usdrygal(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> US Dry Gallons"""
    return round(_volume * 0.0037202, _round)


def cuin2usdrypt(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> US Dry Pints"""
    return round(_volume * 0.029762, _round)


def cuin2usfloz(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> US Fluid Ounces"""
    return round(_volume * 0.55411, _round)


def cuin2usgills(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> US Gills"""
    return round(_volume * 0.13853, _round)


def cuin2usliqgal(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> US Liquid Gallons"""
    return round(_volume * 0.0043290, _round)


def cuin2usliqpt(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> US Liquid Pints"""
    return round(_volume * 0.034632, _round)


def cuin2usqt(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> US (Liquid) Quarts"""
    return round(_volume * 0.017316, _round)


def cuin2ustbl(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> US Tablespoons"""
    return round(_volume * 1.1082, _round)


def cuin2ustsp(_volume: int or float, _round: int=3) -> float:
    """Cubic Inches -> US Teaspoons"""
    return round(_volume * 3.3247, _round)


# CUBIC METERS


def cum2cuin(_volume: int or float, _round: int=3) -> float:
    """Cubic Meters -> Cubic Inches"""
    return round(_volume * 61024, _round)


# LITERS


def l2cuin(_volume: int or float, _round: int=3) -> float:
    """Liters -> Cubic Inches"""
    return round(_volume * 61.024, _round)


# PINTS


def usdrypt2ukgal(_volume: int or float, _round: int=3) -> float:
    """US Dry Pints -> UK Gallons"""
    return round(_volume * 0.12112, _round)


def usdrypt2usdrygal(_volume: int or float, _round: int=3) -> float:
    """US Dry Pints -> US Dry Gallons"""
    return round(_volume * 0.12500, _round)


def usdrypt2usliqgal(_volume: int or float, _round: int=3) -> float:
    """US Dry Pints -> US Liquid Gallons"""
    return round(_volume * 0.14546, _round)


def usliqpt2ukgal(_volume: int or float, _round: int=3) -> float:
    """US Liquid Pints -> UK Gallons"""
    return round(_volume * 0.10408, _round)


def usliqpt2usdrygal(_volume: int or float, _round: int=3) -> float:
    """US Liquid Pints -> US Dry Gallons"""
    return round(_volume * 0.10742, _round)


def usliqpt2usliqgal(_volume: int or float, _round: int=3) -> float:
    """US Liquid Pints -> US Liquid Gallons"""
    return round(_volume * 0.12500, _round)


def ukpt2ukgal(_volume: int or float, _round: int=3) -> float:
    """UK Pints -> UK Gallons"""
    return round(_volume * 0.12500, _round)


def ukpt2usdrygal(_volume: int or float, _round: int=3) -> float:
    """UK Pints -> US Dry Gallons"""
    return round(_volume * 0.12901, _round)


def ukpt2usliqgal(_volume: int or float, _round: int=3) -> float:
    """UK Pints -> US Liquid Gallons"""
    return round(_volume * 0.15012, _round)

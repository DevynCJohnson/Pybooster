#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Volume measurement conversions

@file convvolume.py
@package pybooster.convvolume
@version 2018.08.23
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


__all__ = [
    # CUBIC INCHES #
    r'cuin2cancups',
    r'cuin2cum',
    r'cuin2dryqt',
    r'cuin2l',
    r'cuin2metriccups',
    r'cuin2metrictbl',
    r'cuin2metrictsp',
    r'cuin2ukfloz',
    r'cuin2ukgal',
    r'cuin2ukgills',
    r'cuin2ukpt',
    r'cuin2ukqt',
    r'cuin2uktbl',
    r'cuin2uktsp',
    r'cuin2uscups',
    r'cuin2usdrygal',
    r'cuin2usdrypt',
    r'cuin2usfloz',
    r'cuin2usgills',
    r'cuin2usliqgal',
    r'cuin2usliqpt',
    r'cuin2usqt',
    r'cuin2ustbl',
    r'cuin2ustsp',
    # CUBIC METERS #
    r'cum2cuin',
    # LITERS #
    r'l2cuin',
    # PINTS #
    r'usdrypt2ukgal',
    r'usdrypt2usdrygal',
    r'usdrypt2usliqgal',
    r'usliqpt2ukgal',
    r'usliqpt2usdrygal',
    r'usliqpt2usliqgal',
    r'ukpt2ukgal',
    r'ukpt2usdrygal',
    r'ukpt2usliqgal'
]


# CUBIC INCHES #


def cuin2cancups(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Canadian Cups"""
    return round(_volume * 0.072093, _round)


def cuin2cum(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Cubic Meters"""
    return round(_volume * 0.000016386995, _round)


def cuin2dryqt(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Dry Quarts"""
    return round(_volume * 0.014881, _round)


def cuin2l(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Liters"""
    return round(_volume * 0.016386995, _round)


def cuin2metriccups(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Metric Cups"""
    return round(_volume * 0.065548, _round)


def cuin2metrictbl(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Metric Tablespoons"""
    return round(_volume * 1.0925, _round)


def cuin2metrictsp(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Metric Teaspoons"""
    return round(_volume * 3.2774, _round)


def cuin2ukfloz(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Fluid Ounces"""
    return round(_volume * 0.57674, _round)


def cuin2ukgal(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Gallons"""
    return round(_volume * 0.0036047, _round)


def cuin2ukgills(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Gills"""
    return round(_volume * 0.11535, _round)


def cuin2ukpt(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Pints"""
    return round(_volume * 0.028837, _round)


def cuin2ukqt(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Quarts"""
    return round(_volume * 0.014419, _round)


def cuin2uktbl(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Tablespoons"""
    return round(_volume * 1.1535, _round)


def cuin2uktsp(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> UK Teaspoons"""
    return round(_volume * 4.6139, _round)


def cuin2uscups(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Cups"""
    return round(_volume * 0.069264, _round)


def cuin2usdrygal(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Dry Gallons"""
    return round(_volume * 0.0037202, _round)


def cuin2usdrypt(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Dry Pints"""
    return round(_volume * 0.029762, _round)


def cuin2usfloz(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Fluid Ounces"""
    return round(_volume * 0.55411, _round)


def cuin2usgills(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Gills"""
    return round(_volume * 0.13853, _round)


def cuin2usliqgal(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Liquid Gallons"""
    return round(_volume * 0.0043290, _round)


def cuin2usliqpt(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Liquid Pints"""
    return round(_volume * 0.034632, _round)


def cuin2usqt(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US (Liquid) Quarts"""
    return round(_volume * 0.017316, _round)


def cuin2ustbl(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Tablespoons"""
    return round(_volume * 1.1082, _round)


def cuin2ustsp(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Teaspoons"""
    return round(_volume * 3.3247, _round)


# CUBIC METERS #


def cum2cuin(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> Cubic Inches"""
    return round(_volume * 61024.0, _round)


# LITERS #


def l2cuin(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> Cubic Inches"""
    return round(_volume * 61.024, _round)


# PINTS #


def usdrypt2ukgal(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> UK Gallons"""
    return round(_volume * 0.12112, _round)


def usdrypt2usdrygal(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Dry Gallons"""
    return round(_volume * 0.12500, _round)


def usdrypt2usliqgal(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Liquid Gallons"""
    return round(_volume * 0.14546, _round)


def usliqpt2ukgal(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> UK Gallons"""
    return round(_volume * 0.10408, _round)


def usliqpt2usdrygal(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Dry Gallons"""
    return round(_volume * 0.10742, _round)


def usliqpt2usliqgal(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Liquid Gallons"""
    return round(_volume * 0.12500, _round)


def ukpt2ukgal(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> UK Gallons"""
    return round(_volume * 0.12500, _round)


def ukpt2usdrygal(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Dry Gallons"""
    return round(_volume * 0.12901, _round)


def ukpt2usliqgal(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Liquid Gallons"""
    return round(_volume * 0.15012, _round)

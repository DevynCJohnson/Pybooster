#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Volume measurement conversions.

@file convvolume.py
@package pybooster.convvolume
@version 2020.08.07
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
    # CANADIAN CUPS #
    r'cancup2cubicinch',
    r'cancup2cubicmeter',
    r'cancup2liter',
    r'cancup2metriccup',
    r'cancup2metrictablespoon',
    r'cancup2metricteaspoon',
    r'cancup2ukfluidounce',
    r'cancup2ukgallon',
    r'cancup2ukgill',
    r'cancup2ukpint',
    r'cancup2ukquart',
    r'cancup2uktablespoon',
    r'cancup2ukteaspoon',
    r'cancup2uscup',
    r'cancup2usdrygallon',
    r'cancup2usdrypint',
    r'cancup2usdryquart',
    r'cancup2usfluidounce',
    r'cancup2usgill',
    r'cancup2usliquidgallon',
    r'cancup2usliquidpint',
    r'cancup2usliquidquart',
    r'cancup2ustablespoon',
    r'cancup2usteaspoon',
    # CUBIC INCHES #
    r'cubicinch2cancup',
    r'cubicinch2cubicmeter',
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
    r'cubicinch2usdryquart',
    r'cubicinch2usfluidounce',
    r'cubicinch2usgill',
    r'cubicinch2usliquidgallon',
    r'cubicinch2usliquidpint',
    r'cubicinch2usliquidquart',
    r'cubicinch2ustablespoon',
    r'cubicinch2usteaspoon',
    # CUBIC METERS #
    r'cubicmeter2cancup',
    r'cubicmeter2cubicinch',
    r'cubicmeter2liter',
    r'cubicmeter2metriccup',
    r'cubicmeter2metrictablespoon',
    r'cubicmeter2metricteaspoon',
    r'cubicmeter2ukfluidounce',
    r'cubicmeter2ukgallon',
    r'cubicmeter2ukgill',
    r'cubicmeter2ukpint',
    r'cubicmeter2ukquart',
    r'cubicmeter2uktablespoon',
    r'cubicmeter2ukteaspoon',
    r'cubicmeter2uscup',
    r'cubicmeter2usdrygallon',
    r'cubicmeter2usdrypint',
    r'cubicmeter2usdryquart',
    r'cubicmeter2usfluidounce',
    r'cubicmeter2usgill',
    r'cubicmeter2usliquidgallon',
    r'cubicmeter2usliquidpint',
    r'cubicmeter2usliquidquart',
    r'cubicmeter2ustablespoon',
    r'cubicmeter2usteaspoon',
    # LITERS #
    r'liter2cancup',
    r'liter2cubicinch',
    r'liter2cubicmeter',
    r'liter2metriccup',
    r'liter2metrictablespoon',
    r'liter2metricteaspoon',
    r'liter2ukfluidounce',
    r'liter2ukgallon',
    r'liter2ukgill',
    r'liter2ukpint',
    r'liter2ukquart',
    r'liter2uktablespoon',
    r'liter2ukteaspoon',
    r'liter2uscup',
    r'liter2usdrygallon',
    r'liter2usdrypint',
    r'liter2usdryquart',
    r'liter2usfluidounce',
    r'liter2usgill',
    r'liter2usliquidgallon',
    r'liter2usliquidpint',
    r'liter2usliquidquart',
    r'liter2ustablespoon',
    r'liter2usteaspoon',
    # METRIC CUPS #
    r'metriccup2cancup',
    r'metriccup2cubicinch',
    r'metriccup2cubicmeter',
    r'metriccup2liter',
    r'metriccup2metrictablespoon',
    r'metriccup2metricteaspoon',
    r'metriccup2ukfluidounce',
    r'metriccup2ukgallon',
    r'metriccup2ukgill',
    r'metriccup2ukpint',
    r'metriccup2ukquart',
    r'metriccup2uktablespoon',
    r'metriccup2ukteaspoon',
    r'metriccup2uscup',
    r'metriccup2usdrygallon',
    r'metriccup2usdrypint',
    r'metriccup2usdryquart',
    r'metriccup2usfluidounce',
    r'metriccup2usgill',
    r'metriccup2usliquidgallon',
    r'metriccup2usliquidpint',
    r'metriccup2usliquidquart',
    r'metriccup2ustablespoon',
    r'metriccup2usteaspoon',
    # METRIC TABLESPOONS #
    r'metrictablespoon2cancup',
    r'metrictablespoon2cubicinch',
    r'metrictablespoon2cubicmeter',
    r'metrictablespoon2liter',
    r'metrictablespoon2metriccup',
    r'metrictablespoon2metricteaspoon',
    r'metrictablespoon2ukfluidounce',
    r'metrictablespoon2ukgallon',
    r'metrictablespoon2ukgill',
    r'metrictablespoon2ukpint',
    r'metrictablespoon2ukquart',
    r'metrictablespoon2uktablespoon',
    r'metrictablespoon2ukteaspoon',
    r'metrictablespoon2uscup',
    r'metrictablespoon2usdrygallon',
    r'metrictablespoon2usdrypint',
    r'metrictablespoon2usdryquart',
    r'metrictablespoon2usfluidounce',
    r'metrictablespoon2usgill',
    r'metrictablespoon2usliquidgallon',
    r'metrictablespoon2usliquidpint',
    r'metrictablespoon2usliquidquart',
    r'metrictablespoon2ustablespoon',
    r'metrictablespoon2usteaspoon',
    # UK PINTS #
    r'ukpint2ukgallon',
    r'ukpint2usdrygallon',
    r'ukpint2usliquidgallon',
    # US DRY PINTS #
    r'usdrypint2ukgallon',
    r'usdrypint2usdrygallon',
    r'usdrypint2usliquidgallon',
    # US LIQUID PINTS #
    r'usliquidpint2ukgallon',
    r'usliquidpint2usdrygallon',
    r'usliquidpint2usliquidgallon',
]


# CUBIC INCHES #


def cancup2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> Cubic Inches."""
    return round(_volume * 13.871, _round)


def cancup2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> Cubic Meters."""
    return round(_volume * 0.00022730372323498659, _round)


def cancup2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> Liters."""
    return round(_volume * 0.22730372323498658908, _round)


def cancup2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> Metric Cups."""
    return round(_volume * 0.90922, _round)


def cancup2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> Metric Tablespoons."""
    return round(_volume * 15.154, _round)


def cancup2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> Metric Teaspoons."""
    return round(_volume * 45.461, _round)


def cancup2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> UK Fluid Ounces."""
    return round(_volume * 8.0, _round)


def cancup2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> UK Gallons."""
    return round(_volume * 0.050000, _round)


def cancup2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> UK Gills."""
    return round(_volume * 1.6000, _round)


def cancup2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> UK Pints."""
    return round(_volume * 0.40000, _round)


def cancup2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> UK Quarts."""
    return round(_volume * 0.20000, _round)


def cancup2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> UK Tablespoons."""
    return round(_volume * 16.0, _round)


def cancup2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> UK Teaspoons."""
    return round(_volume * 64.0, _round)


def cancup2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> US Cups."""
    return round(_volume * 0.96076, _round)


def cancup2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> US Dry Gallons."""
    return round(_volume * 0.051603, _round)


def cancup2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> US Dry Pints."""
    return round(_volume * 0.41282, _round)


def cancup2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> US Dry Quarts."""
    return round(_volume * 0.20641, _round)


def cancup2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> US Fluid Ounces."""
    return round(_volume * 7.6861, _round)


def cancup2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> US Gills."""
    return round(_volume * 1.9215, _round)


def cancup2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> US Liquid Gallons."""
    return round(_volume * 0.060047, _round)


def cancup2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> US Liquid Pints."""
    return round(_volume * 0.48038, _round)


def cancup2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> US Liquid Quarts."""
    return round(_volume * 0.24019, _round)


def cancup2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> US Tablespoons."""
    return round(_volume * 15.372, _round)


def cancup2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Canadian Cups -> US Teaspoons."""
    return round(_volume * 46.116, _round)


# CUBIC INCHES #


def cubicinch2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Canadian Cups."""
    return round(_volume * 0.072093, _round)


def cubicinch2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> Cubic Meters."""
    return round(_volume * 0.000016386995, _round)


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


def cubicinch2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Dry Quarts."""
    return round(_volume * 0.014881, _round)


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


def cubicinch2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Liquid Quarts."""
    return round(_volume * 0.017316, _round)


def cubicinch2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Tablespoons."""
    return round(_volume * 1.1082, _round)


def cubicinch2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Inches -> US Teaspoons."""
    return round(_volume * 3.3247, _round)


# CUBIC METERS #


def cubicmeter2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> Canadian Cups."""
    return round(_volume * 4399.4, _round)


def cubicmeter2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> Cubic Inches."""
    return round(_volume * 61024.0, _round)


def cubicmeter2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> Liters."""
    return round(_volume * 1000.0, _round)


def cubicmeter2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> Metric Cups."""
    return round(_volume * 4000.0, _round)


def cubicmeter2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> Metric Tablespoons."""
    return round(_volume * 66667.0, _round)


def cubicmeter2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> Metric Teaspoons."""
    return round(_volume * 200000.0, _round)


def cubicmeter2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> UK Fluid Ounces."""
    return round(_volume * 35195.0, _round)


def cubicmeter2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> UK Gallons."""
    return round(_volume * 219.97, _round)


def cubicmeter2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> UK Gills."""
    return round(_volume * 7039.0, _round)


def cubicmeter2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> UK Pints."""
    return round(_volume * 1759.8, _round)


def cubicmeter2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> UK Quarts."""
    return round(_volume * 879.88, _round)


def cubicmeter2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> UK Tablespoons."""
    return round(_volume * 70390.0, _round)


def cubicmeter2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> UK Teaspoons."""
    return round(_volume * 281560.0, _round)


def cubicmeter2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> US Cups."""
    return round(_volume * 4226.8, _round)


def cubicmeter2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> US Dry Gallons."""
    return round(_volume * 227.02, _round)


def cubicmeter2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> US Dry Pints."""
    return round(_volume * 1816.2, _round)


def cubicmeter2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> US Dry Quarts."""
    return round(_volume * 908.08, _round)


def cubicmeter2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> US Fluid Ounces."""
    return round(_volume * 33814, _round)


def cubicmeter2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> US Gills."""
    return round(_volume * 8453.5, _round)


def cubicmeter2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> US Liquid Gallons."""
    return round(_volume * 264.17, _round)


def cubicmeter2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> US Liquid Pints."""
    return round(_volume * 2113.4, _round)


def cubicmeter2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> US Liquid Quarts."""
    return round(_volume * 1056.7, _round)


def cubicmeter2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> US Tablespoons."""
    return round(_volume * 67628.0, _round)


def cubicmeter2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Cubic Meters -> US Teaspoons."""
    return round(_volume * 202880.0, _round)


# LITERS #


def liter2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> Canadian Cups."""
    return round(_volume * 4.3994, _round)


def liter2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> Cubic Inches."""
    return round(_volume * 61.024, _round)


def liter2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> Cubic Meters."""
    return round(_volume * 0.001, _round)


def liter2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> Metric Cups."""
    return round(_volume * 4.0, _round)


def liter2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> Metric Tablespoons."""
    return round(_volume * 66.667, _round)


def liter2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> Metric Teaspoons."""
    return round(_volume * 200.0, _round)


def liter2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> UK Fluid Ounces."""
    return round(_volume * 35.195, _round)


def liter2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> UK Gallons."""
    return round(_volume * 0.21997, _round)


def liter2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> UK Gills."""
    return round(_volume * 7.039, _round)


def liter2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> UK Pints."""
    return round(_volume * 1.7598, _round)


def liter2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> UK Quarts."""
    return round(_volume * 0.87988, _round)


def liter2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> UK Tablespoons."""
    return round(_volume * 70.39, _round)


def liter2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> UK Teaspoons."""
    return round(_volume * 281.560, _round)


def liter2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> US Cups."""
    return round(_volume * 4.2268, _round)


def liter2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> US Dry Gallons."""
    return round(_volume * 0.22702, _round)


def liter2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> US Dry Pints."""
    return round(_volume * 1.8162, _round)


def liter2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> US Dry Quarts."""
    return round(_volume * 0.90808, _round)


def liter2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> US Fluid Ounces."""
    return round(_volume * 33.814, _round)


def liter2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> US Gills."""
    return round(_volume * 8.4535, _round)


def liter2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> US Liquid Gallons."""
    return round(_volume * 0.26417, _round)


def liter2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> US Liquid Pints."""
    return round(_volume * 2.1134, _round)


def liter2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> US Liquid Quarts."""
    return round(_volume * 1.0567, _round)


def liter2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> US Tablespoons."""
    return round(_volume * 67.628, _round)


def liter2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Liters -> US Teaspoons."""
    return round(_volume * 202.8800, _round)


# METRIC CUPS #


def metriccup2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> Canadian Cups."""
    return round(_volume * 1.0998, _round)


def metriccup2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> Cubic Inches."""
    return round(_volume * 15.256, _round)


def metriccup2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> Cubic Meters."""
    return round(_volume * 0.00025, _round)


def metriccup2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> Liters."""
    return round(_volume * 0.250, _round)


def metriccup2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> Metric Tablespoons."""
    return round(_volume * 16.667, _round)


def metriccup2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> Metric Teaspoons."""
    return round(_volume * 50.0, _round)


def metriccup2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> UK Fluid Ounces."""
    return round(_volume * 8.7988, _round)


def metriccup2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> UK Gallons."""
    return round(_volume * 0.054992, _round)


def metriccup2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> UK Gills."""
    return round(_volume * 1.7598, _round)


def metriccup2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> UK Pints."""
    return round(_volume * 0.43994, _round)


def metriccup2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> UK Quarts."""
    return round(_volume * 0.21997, _round)


def metriccup2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> UK Tablespoons."""
    return round(_volume * 17.598, _round)


def metriccup2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> UK Teaspoons."""
    return round(_volume * 70.390, _round)


def metriccup2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> US Cups."""
    return round(_volume * 1.0567, _round)


def metriccup2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> US Dry Gallons."""
    return round(_volume * 0.056755, _round)


def metriccup2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> US Dry Pints."""
    return round(_volume * 0.45404, _round)


def metriccup2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> US Dry Quarts."""
    return round(_volume * 0.22702, _round)


def metriccup2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> US Fluid Ounces."""
    return round(_volume * 8.4535, _round)


def metriccup2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> US Gills."""
    return round(_volume * 2.1134, _round)


def metriccup2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> US Liquid Gallons."""
    return round(_volume * 0.066043, _round)


def metriccup2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> US Liquid Pints."""
    return round(_volume * 0.52834, _round)


def metriccup2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> US Liquid Quarts."""
    return round(_volume * 0.26417, _round)


def metriccup2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> US Tablespoons."""
    return round(_volume * 16.907, _round)


def metriccup2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Cups -> US Teaspoons."""
    return round(_volume * 50.721, _round)


# METRIC TABLESPOONS #


def metrictablespoon2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> Canadian Cups."""
    return round(_volume * 0.065991, _round)


def metrictablespoon2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> Cubic Inches."""
    return round(_volume * 0.91536, _round)


def metrictablespoon2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> Cubic Meters."""
    return round(_volume * 0.000014999925000375, _round)


def metrictablespoon2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> Liters."""
    return round(_volume * 0.01499992500037499813, _round)


def metrictablespoon2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> Metric Cups."""
    return round(_volume * 0.060, _round)


def metrictablespoon2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> Metric Teaspoons."""
    return round(_volume * 3.0, _round)


def metrictablespoon2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> UK Fluid Ounces."""
    return round(_volume * 0.52793, _round)


def metrictablespoon2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> UK Gallons."""
    return round(_volume * 0.0032995, _round)


def metrictablespoon2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> UK Gills."""
    return round(_volume * 0.10559, _round)


def metrictablespoon2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> UK Pints."""
    return round(_volume * 0.026396, _round)


def metrictablespoon2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> UK Quarts."""
    return round(_volume * 0.013198, _round)


def metrictablespoon2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> UK Tablespoons."""
    return round(_volume * 1.0559, _round)


def metrictablespoon2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> UK Teaspoons."""
    return round(_volume * 4.2234, _round)


def metrictablespoon2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> US Cups."""
    return round(_volume * 0.063401, _round)


def metrictablespoon2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> US Dry Gallons."""
    return round(_volume * 0.0034053, _round)


def metrictablespoon2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> US Dry Pints."""
    return round(_volume * 0.027242, _round)


def metrictablespoon2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> US Dry Quarts."""
    return round(_volume * 0.013621, _round)


def metrictablespoon2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> US Fluid Ounces."""
    return round(_volume * 0.50721, _round)


def metrictablespoon2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> US Gills."""
    return round(_volume * 0.12680, _round)


def metrictablespoon2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> US Liquid Gallons."""
    return round(_volume * 0.0039626, _round)


def metrictablespoon2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> US Liquid Pints."""
    return round(_volume * 0.031701, _round)


def metrictablespoon2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> US Liquid Quarts."""
    return round(_volume * 0.015850, _round)


def metrictablespoon2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> US Tablespoons."""
    return round(_volume * 1.0144, _round)


def metrictablespoon2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Tablespoons -> US Teaspoons."""
    return round(_volume * 3.0433, _round)


# UK PINTS #


def ukpint2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> UK Gallons."""
    return round(_volume * 0.12500, _round)


def ukpint2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Dry Gallons."""
    return round(_volume * 0.12901, _round)


def ukpint2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Liquid Gallons."""
    return round(_volume * 0.15012, _round)


# US DRY PINTS #


def usdrypint2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> UK Gallons."""
    return round(_volume * 0.12112, _round)


def usdrypint2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Dry Gallons."""
    return round(_volume * 0.12500, _round)


def usdrypint2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Liquid Gallons."""
    return round(_volume * 0.14546, _round)


# US LIQUID PINTS #


def usliquidpint2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> UK Gallons."""
    return round(_volume * 0.10408, _round)


def usliquidpint2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Dry Gallons."""
    return round(_volume * 0.10742, _round)


def usliquidpint2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Liquid Gallons."""
    return round(_volume * 0.12500, _round)

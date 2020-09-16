#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Volume measurement conversions.

@file convvolume.py
@package pybooster.convvolume
@version 2020.08.08
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
    # METRIC TEASPOONS #
    r'metricteaspoon2cancup',
    r'metricteaspoon2cubicinch',
    r'metricteaspoon2cubicmeter',
    r'metricteaspoon2liter',
    r'metricteaspoon2metriccup',
    r'metricteaspoon2metrictablespoon',
    r'metricteaspoon2ukfluidounce',
    r'metricteaspoon2ukgallon',
    r'metricteaspoon2ukgill',
    r'metricteaspoon2ukpint',
    r'metricteaspoon2ukquart',
    r'metricteaspoon2uktablespoon',
    r'metricteaspoon2ukteaspoon',
    r'metricteaspoon2uscup',
    r'metricteaspoon2usdrygallon',
    r'metricteaspoon2usdrypint',
    r'metricteaspoon2usdryquart',
    r'metricteaspoon2usfluidounce',
    r'metricteaspoon2usgill',
    r'metricteaspoon2usliquidgallon',
    r'metricteaspoon2usliquidpint',
    r'metricteaspoon2usliquidquart',
    r'metricteaspoon2ustablespoon',
    r'metricteaspoon2usteaspoon',
    # UK FLUID OUNCES #
    r'ukfluidounce2cancup',
    r'ukfluidounce2cubicinch',
    r'ukfluidounce2cubicmeter',
    r'ukfluidounce2liter',
    r'ukfluidounce2metriccup',
    r'ukfluidounce2metrictablespoon',
    r'ukfluidounce2metricteaspoon',
    r'ukfluidounce2ukgallon',
    r'ukfluidounce2ukgill',
    r'ukfluidounce2ukpint',
    r'ukfluidounce2ukquart',
    r'ukfluidounce2uktablespoon',
    r'ukfluidounce2ukteaspoon',
    r'ukfluidounce2uscup',
    r'ukfluidounce2usdrygallon',
    r'ukfluidounce2usdrypint',
    r'ukfluidounce2usdryquart',
    r'ukfluidounce2usfluidounce',
    r'ukfluidounce2usgill',
    r'ukfluidounce2usliquidgallon',
    r'ukfluidounce2usliquidpint',
    r'ukfluidounce2usliquidquart',
    r'ukfluidounce2ustablespoon',
    r'ukfluidounce2usteaspoon',
    # UK GALLONS #
    r'ukgallon2cancup',
    r'ukgallon2cubicinch',
    r'ukgallon2cubicmeter',
    r'ukgallon2liter',
    r'ukgallon2metriccup',
    r'ukgallon2metrictablespoon',
    r'ukgallon2metricteaspoon',
    r'ukgallon2ukfluidounce',
    r'ukgallon2ukgill',
    r'ukgallon2ukpint',
    r'ukgallon2ukquart',
    r'ukgallon2uktablespoon',
    r'ukgallon2ukteaspoon',
    r'ukgallon2uscup',
    r'ukgallon2usdrygallon',
    r'ukgallon2usdrypint',
    r'ukgallon2usdryquart',
    r'ukgallon2usfluidounce',
    r'ukgallon2usgill',
    r'ukgallon2usliquidgallon',
    r'ukgallon2usliquidpint',
    r'ukgallon2usliquidquart',
    r'ukgallon2ustablespoon',
    r'ukgallon2usteaspoon',
    # UK GILLS #
    r'ukgill2cancup',
    r'ukgill2cubicinch',
    r'ukgill2cubicmeter',
    r'ukgill2liter',
    r'ukgill2metriccup',
    r'ukgill2metrictablespoon',
    r'ukgill2metricteaspoon',
    r'ukgill2ukfluidounce',
    r'ukgill2ukgallon',
    r'ukgill2ukpint',
    r'ukgill2ukquart',
    r'ukgill2uktablespoon',
    r'ukgill2ukteaspoon',
    r'ukgill2uscup',
    r'ukgill2usdrygallon',
    r'ukgill2usdrypint',
    r'ukgill2usdryquart',
    r'ukgill2usfluidounce',
    r'ukgill2usgill',
    r'ukgill2usliquidgallon',
    r'ukgill2usliquidpint',
    r'ukgill2usliquidquart',
    r'ukgill2ustablespoon',
    r'ukgill2usteaspoon',
    # UK PINTS #
    r'ukpint2cancup',
    r'ukpint2cubicinch',
    r'ukpint2cubicmeter',
    r'ukpint2liter',
    r'ukpint2metriccup',
    r'ukpint2metrictablespoon',
    r'ukpint2metricteaspoon',
    r'ukpint2ukfluidounce',
    r'ukpint2ukgallon',
    r'ukpint2ukgill',
    r'ukpint2ukquart',
    r'ukpint2uktablespoon',
    r'ukpint2ukteaspoon',
    r'ukpint2uscup',
    r'ukpint2usdrygallon',
    r'ukpint2usdrypint',
    r'ukpint2usdryquart',
    r'ukpint2usfluidounce',
    r'ukpint2usgill',
    r'ukpint2usliquidgallon',
    r'ukpint2usliquidpint',
    r'ukpint2usliquidquart',
    r'ukpint2ustablespoon',
    r'ukpint2usteaspoon',
    # UK QUARTS #
    r'ukquart2cancup',
    r'ukquart2cubicinch',
    r'ukquart2cubicmeter',
    r'ukquart2liter',
    r'ukquart2metriccup',
    r'ukquart2metrictablespoon',
    r'ukquart2metricteaspoon',
    r'ukquart2ukfluidounce',
    r'ukquart2ukgallon',
    r'ukquart2ukgill',
    r'ukquart2ukpint',
    r'ukquart2uktablespoon',
    r'ukquart2ukteaspoon',
    r'ukquart2uscup',
    r'ukquart2usdrygallon',
    r'ukquart2usdrypint',
    r'ukquart2usdryquart',
    r'ukquart2usfluidounce',
    r'ukquart2usgill',
    r'ukquart2usliquidgallon',
    r'ukquart2usliquidpint',
    r'ukquart2usliquidquart',
    r'ukquart2ustablespoon',
    r'ukquart2usteaspoon',
    # UK TABLESPOONS #
    r'uktablespoon2cancup',
    r'uktablespoon2cubicinch',
    r'uktablespoon2cubicmeter',
    r'uktablespoon2liter',
    r'uktablespoon2metriccup',
    r'uktablespoon2metrictablespoon',
    r'uktablespoon2metricteaspoon',
    r'uktablespoon2ukfluidounce',
    r'uktablespoon2ukgallon',
    r'uktablespoon2ukgill',
    r'uktablespoon2ukpint',
    r'uktablespoon2ukquart',
    r'uktablespoon2ukteaspoon',
    r'uktablespoon2uscup',
    r'uktablespoon2usdrygallon',
    r'uktablespoon2usdrypint',
    r'uktablespoon2usdryquart',
    r'uktablespoon2usfluidounce',
    r'uktablespoon2usgill',
    r'uktablespoon2usliquidgallon',
    r'uktablespoon2usliquidpint',
    r'uktablespoon2usliquidquart',
    r'uktablespoon2ustablespoon',
    r'uktablespoon2usteaspoon',
    # UK TEASPOONS #
    r'ukteaspoon2cancup',
    r'ukteaspoon2cubicinch',
    r'ukteaspoon2cubicmeter',
    r'ukteaspoon2liter',
    r'ukteaspoon2metriccup',
    r'ukteaspoon2metrictablespoon',
    r'ukteaspoon2metricteaspoon',
    r'ukteaspoon2ukfluidounce',
    r'ukteaspoon2ukgallon',
    r'ukteaspoon2ukgill',
    r'ukteaspoon2ukpint',
    r'ukteaspoon2ukquart',
    r'ukteaspoon2uktablespoon',
    r'ukteaspoon2uscup',
    r'ukteaspoon2usdrygallon',
    r'ukteaspoon2usdrypint',
    r'ukteaspoon2usdryquart',
    r'ukteaspoon2usfluidounce',
    r'ukteaspoon2usgill',
    r'ukteaspoon2usliquidgallon',
    r'ukteaspoon2usliquidpint',
    r'ukteaspoon2usliquidquart',
    r'ukteaspoon2ustablespoon',
    r'ukteaspoon2usteaspoon',
    # US CUPS #
    r'uscup2cancup',
    r'uscup2cubicinch',
    r'uscup2cubicmeter',
    r'uscup2liter',
    r'uscup2metriccup',
    r'uscup2metrictablespoon',
    r'uscup2metricteaspoon',
    r'uscup2ukfluidounce',
    r'uscup2ukgallon',
    r'uscup2ukgill',
    r'uscup2ukpint',
    r'uscup2ukquart',
    r'uscup2uktablespoon',
    r'uscup2ukteaspoon',
    r'uscup2usdrygallon',
    r'uscup2usdrypint',
    r'uscup2usdryquart',
    r'uscup2usfluidounce',
    r'uscup2usgill',
    r'uscup2usliquidgallon',
    r'uscup2usliquidpint',
    r'uscup2usliquidquart',
    r'uscup2ustablespoon',
    r'uscup2usteaspoon',
    # US DRY GALLONS #
    r'usdrygallon2cancup',
    r'usdrygallon2cubicinch',
    r'usdrygallon2cubicmeter',
    r'usdrygallon2liter',
    r'usdrygallon2metriccup',
    r'usdrygallon2metrictablespoon',
    r'usdrygallon2metricteaspoon',
    r'usdrygallon2ukfluidounce',
    r'usdrygallon2ukgallon',
    r'usdrygallon2ukgill',
    r'usdrygallon2ukpint',
    r'usdrygallon2ukquart',
    r'usdrygallon2uktablespoon',
    r'usdrygallon2ukteaspoon',
    r'usdrygallon2uscup',
    r'usdrygallon2usdrypint',
    r'usdrygallon2usdryquart',
    r'usdrygallon2usfluidounce',
    r'usdrygallon2usgill',
    r'usdrygallon2usliquidgallon',
    r'usdrygallon2usliquidpint',
    r'usdrygallon2usliquidquart',
    r'usdrygallon2ustablespoon',
    r'usdrygallon2usteaspoon',
    # US DRY PINTS #
    r'usdrypint2cancup',
    r'usdrypint2cubicinch',
    r'usdrypint2cubicmeter',
    r'usdrypint2liter',
    r'usdrypint2metriccup',
    r'usdrypint2metrictablespoon',
    r'usdrypint2metricteaspoon',
    r'usdrypint2ukfluidounce',
    r'usdrypint2ukgallon',
    r'usdrypint2ukgill',
    r'usdrypint2ukpint',
    r'usdrypint2ukquart',
    r'usdrypint2uktablespoon',
    r'usdrypint2ukteaspoon',
    r'usdrypint2uscup',
    r'usdrypint2usdrygallon',
    r'usdrypint2usdryquart',
    r'usdrypint2usfluidounce',
    r'usdrypint2usgill',
    r'usdrypint2usliquidgallon',
    r'usdrypint2usliquidpint',
    r'usdrypint2usliquidquart',
    r'usdrypint2ustablespoon',
    r'usdrypint2usteaspoon',
    # US DRY QUARTS #
    r'usdryquart2cancup',
    r'usdryquart2cubicinch',
    r'usdryquart2cubicmeter',
    r'usdryquart2liter',
    r'usdryquart2metriccup',
    r'usdryquart2metrictablespoon',
    r'usdryquart2metricteaspoon',
    r'usdryquart2ukfluidounce',
    r'usdryquart2ukgallon',
    r'usdryquart2ukgill',
    r'usdryquart2ukpint',
    r'usdryquart2ukquart',
    r'usdryquart2uktablespoon',
    r'usdryquart2ukteaspoon',
    r'usdryquart2uscup',
    r'usdryquart2usdrygallon',
    r'usdryquart2usdrypint',
    r'usdryquart2usfluidounce',
    r'usdryquart2usgill',
    r'usdryquart2usliquidgallon',
    r'usdryquart2usliquidpint',
    r'usdryquart2usliquidquart',
    r'usdryquart2ustablespoon',
    r'usdryquart2usteaspoon',
    # US FLUID OUNCES #
    r'usfluidounce2cancup',
    r'usfluidounce2cubicinch',
    r'usfluidounce2cubicmeter',
    r'usfluidounce2liter',
    r'usfluidounce2metriccup',
    r'usfluidounce2metrictablespoon',
    r'usfluidounce2metricteaspoon',
    r'usfluidounce2ukfluidounce',
    r'usfluidounce2ukgallon',
    r'usfluidounce2ukgill',
    r'usfluidounce2ukpint',
    r'usfluidounce2ukquart',
    r'usfluidounce2uktablespoon',
    r'usfluidounce2ukteaspoon',
    r'usfluidounce2uscup',
    r'usfluidounce2usdrygallon',
    r'usfluidounce2usdrypint',
    r'usfluidounce2usdryquart',
    r'usfluidounce2usgill',
    r'usfluidounce2usliquidgallon',
    r'usfluidounce2usliquidpint',
    r'usfluidounce2usliquidquart',
    r'usfluidounce2ustablespoon',
    r'usfluidounce2usteaspoon',
    # US GILLS #
    r'usgill2cancup',
    r'usgill2cubicinch',
    r'usgill2cubicmeter',
    r'usgill2liter',
    r'usgill2metriccup',
    r'usgill2metrictablespoon',
    r'usgill2metricteaspoon',
    r'usgill2ukfluidounce',
    r'usgill2ukgallon',
    r'usgill2ukgill',
    r'usgill2ukpint',
    r'usgill2ukquart',
    r'usgill2uktablespoon',
    r'usgill2ukteaspoon',
    r'usgill2uscup',
    r'usgill2usdrygallon',
    r'usgill2usdrypint',
    r'usgill2usdryquart',
    r'usgill2usfluidounce',
    r'usgill2usliquidgallon',
    r'usgill2usliquidpint',
    r'usgill2usliquidquart',
    r'usgill2ustablespoon',
    r'usgill2usteaspoon',
    # US LIQUID GALLONS #
    r'usliquidgallon2cancup',
    r'usliquidgallon2cubicinch',
    r'usliquidgallon2cubicmeter',
    r'usliquidgallon2liter',
    r'usliquidgallon2metriccup',
    r'usliquidgallon2metrictablespoon',
    r'usliquidgallon2metricteaspoon',
    r'usliquidgallon2ukfluidounce',
    r'usliquidgallon2ukgallon',
    r'usliquidgallon2ukgill',
    r'usliquidgallon2ukpint',
    r'usliquidgallon2ukquart',
    r'usliquidgallon2uktablespoon',
    r'usliquidgallon2ukteaspoon',
    r'usliquidgallon2uscup',
    r'usliquidgallon2usdrygallon',
    r'usliquidgallon2usdrypint',
    r'usliquidgallon2usdryquart',
    r'usliquidgallon2usfluidounce',
    r'usliquidgallon2usgill',
    r'usliquidgallon2usliquidpint',
    r'usliquidgallon2usliquidquart',
    r'usliquidgallon2ustablespoon',
    r'usliquidgallon2usteaspoon',
    # US LIQUID PINTS #
    r'usliquidpint2cancup',
    r'usliquidpint2cubicinch',
    r'usliquidpint2cubicmeter',
    r'usliquidpint2liter',
    r'usliquidpint2metriccup',
    r'usliquidpint2metrictablespoon',
    r'usliquidpint2metricteaspoon',
    r'usliquidpint2ukfluidounce',
    r'usliquidpint2ukgallon',
    r'usliquidpint2ukgill',
    r'usliquidpint2ukpint',
    r'usliquidpint2ukquart',
    r'usliquidpint2uktablespoon',
    r'usliquidpint2ukteaspoon',
    r'usliquidpint2uscup',
    r'usliquidpint2usdrygallon',
    r'usliquidpint2usdrypint',
    r'usliquidpint2usdryquart',
    r'usliquidpint2usfluidounce',
    r'usliquidpint2usgill',
    r'usliquidpint2usliquidgallon',
    r'usliquidpint2usliquidquart',
    r'usliquidpint2ustablespoon',
    r'usliquidpint2usteaspoon',
    # US LIQUID QUARTS #
    r'usliquidquart2cancup',
    r'usliquidquart2cubicinch',
    r'usliquidquart2cubicmeter',
    r'usliquidquart2liter',
    r'usliquidquart2metriccup',
    r'usliquidquart2metrictablespoon',
    r'usliquidquart2metricteaspoon',
    r'usliquidquart2ukfluidounce',
    r'usliquidquart2ukgallon',
    r'usliquidquart2ukgill',
    r'usliquidquart2ukpint',
    r'usliquidquart2ukquart',
    r'usliquidquart2uktablespoon',
    r'usliquidquart2ukteaspoon',
    r'usliquidquart2uscup',
    r'usliquidquart2usdrygallon',
    r'usliquidquart2usdrypint',
    r'usliquidquart2usdryquart',
    r'usliquidquart2usfluidounce',
    r'usliquidquart2usgill',
    r'usliquidquart2usliquidgallon',
    r'usliquidquart2usliquidpint',
    r'usliquidquart2ustablespoon',
    r'usliquidquart2usteaspoon',
    # US TABLESPOONS #
    r'ustablespoon2cancup',
    r'ustablespoon2cubicinch',
    r'ustablespoon2cubicmeter',
    r'ustablespoon2liter',
    r'ustablespoon2metriccup',
    r'ustablespoon2metrictablespoon',
    r'ustablespoon2metricteaspoon',
    r'ustablespoon2ukfluidounce',
    r'ustablespoon2ukgallon',
    r'ustablespoon2ukgill',
    r'ustablespoon2ukpint',
    r'ustablespoon2ukquart',
    r'ustablespoon2uktablespoon',
    r'ustablespoon2ukteaspoon',
    r'ustablespoon2uscup',
    r'ustablespoon2usdrygallon',
    r'ustablespoon2usdrypint',
    r'ustablespoon2usdryquart',
    r'ustablespoon2usfluidounce',
    r'ustablespoon2usgill',
    r'ustablespoon2usliquidgallon',
    r'ustablespoon2usliquidpint',
    r'ustablespoon2usliquidquart',
    r'ustablespoon2usteaspoon',
    # US TEASPOONS #
    r'usteaspoon2cancup',
    r'usteaspoon2cubicinch',
    r'usteaspoon2cubicmeter',
    r'usteaspoon2liter',
    r'usteaspoon2metriccup',
    r'usteaspoon2metrictablespoon',
    r'usteaspoon2metricteaspoon',
    r'usteaspoon2ukfluidounce',
    r'usteaspoon2ukgallon',
    r'usteaspoon2ukgill',
    r'usteaspoon2ukpint',
    r'usteaspoon2ukquart',
    r'usteaspoon2uktablespoon',
    r'usteaspoon2ukteaspoon',
    r'usteaspoon2uscup',
    r'usteaspoon2usdrygallon',
    r'usteaspoon2usdrypint',
    r'usteaspoon2usdryquart',
    r'usteaspoon2usfluidounce',
    r'usteaspoon2usgill',
    r'usteaspoon2usliquidgallon',
    r'usteaspoon2usliquidpint',
    r'usteaspoon2usliquidquart',
    r'usteaspoon2ustablespoon'
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


# METRIC TEASPOONS #


def metricteaspoon2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> Canadian Cups."""
    return round(_volume * 0.021997, _round)


def metricteaspoon2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> Cubic Inches."""
    return round(_volume * 0.30512, _round)


def metricteaspoon2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> Cubic Meters."""
    return round(_volume * 0.000005, _round)


def metricteaspoon2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> Liters."""
    return round(_volume * 0.005, _round)


def metricteaspoon2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> Metric Cups."""
    return round(_volume * 0.020000, _round)


def metricteaspoon2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> Metric Tablespoons."""
    return round(_volume * 0.33333333, _round)


def metricteaspoon2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> UK Fluid Ounces."""
    return round(_volume * 0.17598, _round)


def metricteaspoon2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> UK Gallons."""
    return round(_volume * 0.0010998, _round)


def metricteaspoon2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> UK Gills."""
    return round(_volume * 0.035195, _round)


def metricteaspoon2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> UK Pints."""
    return round(_volume * 0.0087988, _round)


def metricteaspoon2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> UK Quarts."""
    return round(_volume * 0.0043994, _round)


def metricteaspoon2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> UK Tablespoons."""
    return round(_volume * 0.35195, _round)


def metricteaspoon2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> UK Teaspoons."""
    return round(_volume * 1.4078, _round)


def metricteaspoon2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> US Cups."""
    return round(_volume * 0.021134, _round)


def metricteaspoon2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> US Dry Gallons."""
    return round(_volume * 0.0011351, _round)


def metricteaspoon2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> US Dry Pints."""
    return round(_volume * 0.0090808, _round)


def metricteaspoon2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> US Dry Quarts."""
    return round(_volume * 0.0045404, _round)


def metricteaspoon2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> US Fluid Ounces."""
    return round(_volume * 0.16907, _round)


def metricteaspoon2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> US Gills."""
    return round(_volume * 0.042268, _round)


def metricteaspoon2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> US Liquid Gallons."""
    return round(_volume * 0.0013209, _round)


def metricteaspoon2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> US Liquid Pints."""
    return round(_volume * 0.010567, _round)


def metricteaspoon2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> US Liquid Quarts."""
    return round(_volume * 0.0052834, _round)


def metricteaspoon2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> US Tablespoons."""
    return round(_volume * 0.33814, _round)


def metricteaspoon2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """Metric Teaspoons -> US Teaspoons."""
    return round(_volume * 1.0144, _round)


# UK FLUID OUNCES #


def ukfluidounce2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> Canadian Cups."""
    return round(_volume * 0.12500, _round)


def ukfluidounce2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> Cubic Inches."""
    return round(_volume * 1.7339, _round)


def ukfluidounce2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> Cubic Meters."""
    return round(_volume * 0.00002841312686461145, _round)


def ukfluidounce2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> Liters."""
    return round(_volume * 0.02841312686461145049, _round)


def ukfluidounce2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> Metric Cups."""
    return round(_volume * 0.11365, _round)


def ukfluidounce2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> Metric Tablespoons."""
    return round(_volume * 1.8942, _round)


def ukfluidounce2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> Metric Teaspoons."""
    return round(_volume * 5.6826, _round)


def ukfluidounce2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> UK Gallons."""
    return round(_volume * 0.0062500, _round)


def ukfluidounce2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> UK Gills."""
    return round(_volume * 0.20000, _round)


def ukfluidounce2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> UK Pints."""
    return round(_volume * 0.050000, _round)


def ukfluidounce2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> UK Quarts."""
    return round(_volume * 0.025000, _round)


def ukfluidounce2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> UK Tablespoons."""
    return round(_volume * 2.0000, _round)


def ukfluidounce2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> UK Teaspoons."""
    return round(_volume * 8.0000, _round)


def ukfluidounce2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> US Cups."""
    return round(_volume * 0.12009, _round)


def ukfluidounce2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> US Dry Gallons."""
    return round(_volume * 0.0064504, _round)


def ukfluidounce2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> US Dry Pints."""
    return round(_volume * 0.051603, _round)


def ukfluidounce2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> US Dry Quarts."""
    return round(_volume * 0.025801, _round)


def ukfluidounce2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> US Fluid Ounces."""
    return round(_volume * 0.96076, _round)


def ukfluidounce2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> US Gills."""
    return round(_volume * 0.24019, _round)


def ukfluidounce2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> US Liquid Gallons."""
    return round(_volume * 0.0075059, _round)


def ukfluidounce2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> US Liquid Pints."""
    return round(_volume * 0.060047, _round)


def ukfluidounce2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> US Liquid Quarts."""
    return round(_volume * 0.030024, _round)


def ukfluidounce2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> US Tablespoons."""
    return round(_volume * 1.9215, _round)


def ukfluidounce2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Fluid Ounces -> US Teaspoons."""
    return round(_volume * 5.7646, _round)


# UK GALLONS #


def ukgallon2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> Canadian Cups."""
    return round(_volume * 20.000, _round)


def ukgallon2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> Cubic Inches."""
    return round(_volume * 277.42, _round)


def ukgallon2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> Cubic Meters."""
    return round(_volume * 0.00454607446469973178, _round)


def ukgallon2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> Liters."""
    return round(_volume * 4.54607446469973178161, _round)


def ukgallon2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> Metric Cups."""
    return round(_volume * 18.184, _round)


def ukgallon2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> Metric Tablespoons."""
    return round(_volume * 303.07, _round)


def ukgallon2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> Metric Teaspoons."""
    return round(_volume * 909.22, _round)


def ukgallon2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> UK Fluid Ounces."""
    return round(_volume * 160.00, _round)


def ukgallon2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> UK Gills."""
    return round(_volume * 32.000, _round)


def ukgallon2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> UK Pints."""
    return round(_volume * 8.0000, _round)


def ukgallon2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> UK Quarts."""
    return round(_volume * 4.0000, _round)


def ukgallon2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> UK Tablespoons."""
    return round(_volume * 320.00, _round)


def ukgallon2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> UK Teaspoons."""
    return round(_volume * 1280.0, _round)


def ukgallon2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> US Cups."""
    return round(_volume * 19.215, _round)


def ukgallon2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> US Dry Gallons."""
    return round(_volume * 1.0321, _round)


def ukgallon2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> US Dry Pints."""
    return round(_volume * 8.2565, _round)


def ukgallon2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> US Dry Quarts."""
    return round(_volume * 4.1282, _round)


def ukgallon2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> US Fluid Ounces."""
    return round(_volume * 153.72, _round)


def ukgallon2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> US Gills."""
    return round(_volume * 38.430, _round)


def ukgallon2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> US Liquid Gallons."""
    return round(_volume * 1.2009, _round)


def ukgallon2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> US Liquid Pints."""
    return round(_volume * 9.6076, _round)


def ukgallon2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> US Liquid Quarts."""
    return round(_volume * 4.8038, _round)


def ukgallon2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> US Tablespoons."""
    return round(_volume * 307.44, _round)


def ukgallon2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gallons -> US Teaspoons."""
    return round(_volume * 922.33, _round)


# UK GILLS #


def ukgill2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> Canadian Cups."""
    return round(_volume * 0.62500, _round)


def ukgill2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> Cubic Inches."""
    return round(_volume * 8.6694, _round)


def ukgill2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> Cubic Meters."""
    return round(_volume * 0.00014206563432305725, _round)


def ukgill2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> Liters."""
    return round(_volume * 0.14206563432305725245, _round)


def ukgill2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> Metric Cups."""
    return round(_volume * 0.56826, _round)


def ukgill2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> Metric Tablespoons."""
    return round(_volume * 9.4710, _round)


def ukgill2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> Metric Teaspoons."""
    return round(_volume * 28.413, _round)


def ukgill2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> UK Fluid Ounces."""
    return round(_volume * 5.0000, _round)


def ukgill2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> UK Gallons."""
    return round(_volume * 0.031250, _round)


def ukgill2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> UK Pints."""
    return round(_volume * 0.25000, _round)


def ukgill2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> UK Quarts."""
    return round(_volume * 0.12500, _round)


def ukgill2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> UK Tablespoons."""
    return round(_volume * 10.000, _round)


def ukgill2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> UK Teaspoons."""
    return round(_volume * 40.000, _round)


def ukgill2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> US Cups."""
    return round(_volume * 0.60047, _round)


def ukgill2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> US Dry Gallons."""
    return round(_volume * 0.032252, _round)


def ukgill2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> US Dry Pints."""
    return round(_volume * 0.25801, _round)


def ukgill2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> US Dry Quarts."""
    return round(_volume * 0.12901, _round)


def ukgill2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> US Fluid Ounces."""
    return round(_volume * 4.8038, _round)


def ukgill2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> US Gills."""
    return round(_volume * 1.2009, _round)


def ukgill2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> US Liquid Gallons."""
    return round(_volume * 0.037530, _round)


def ukgill2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> US Liquid Pints."""
    return round(_volume * 0.30024, _round)


def ukgill2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> US Liquid Quarts."""
    return round(_volume * 0.15012, _round)


def ukgill2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> US Tablespoons."""
    return round(_volume * 9.6076, _round)


def ukgill2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Gills -> US Teaspoons."""
    return round(_volume * 28.823, _round)


# UK PINTS #


def ukpint2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> Canadian Cups."""
    return round(_volume * 2.5000, _round)


def ukpint2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> Cubic Inches."""
    return round(_volume * 34.677, _round)


def ukpint2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> Cubic Meters."""
    return round(_volume * 0.00056824639163541312, _round)


def ukpint2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> Liters."""
    return round(_volume * 0.56824639163541311513, _round)


def ukpint2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> Metric Cups."""
    return round(_volume * 2.2730, _round)


def ukpint2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> Metric Tablespoons."""
    return round(_volume * 37.884, _round)


def ukpint2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> Metric Teaspoons."""
    return round(_volume * 113.65, _round)


def ukpint2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> UK Fluid Ounces."""
    return round(_volume * 20.000, _round)


def ukpint2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> UK Gallons."""
    return round(_volume * 0.12500, _round)


def ukpint2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> UK Gills."""
    return round(_volume * 4.0000, _round)


def ukpint2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> UK Quarts."""
    return round(_volume * 0.50000, _round)


def ukpint2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> UK Tablespoons."""
    return round(_volume * 40.000, _round)


def ukpint2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> UK Teaspoons."""
    return round(_volume * 160.00, _round)


def ukpint2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Cups."""
    return round(_volume * 2.4019, _round)


def ukpint2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Dry Gallons."""
    return round(_volume * 0.0011351, _round)


def ukpint2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Dry Pints."""
    return round(_volume * 1.0321, _round)


def ukpint2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Dry Quarts."""
    return round(_volume * 0.51603, _round)


def ukpint2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Fluid Ounces."""
    return round(_volume * 19.215, _round)


def ukpint2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Gills."""
    return round(_volume * 4.8038, _round)


def ukpint2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Liquid Gallons."""
    return round(_volume * 0.15012, _round)


def ukpint2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Liquid Pints."""
    return round(_volume * 1.2009, _round)


def ukpint2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Liquid Quarts."""
    return round(_volume * 0.60047, _round)


def ukpint2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Tablespoons."""
    return round(_volume * 38.430, _round)


def ukpint2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Pints -> US Teaspoons."""
    return round(_volume * 115.29, _round)


# UK QUARTS #


def ukquart2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> Canadian Cups."""
    return round(_volume * 5.0000, _round)


def ukquart2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> Cubic Inches."""
    return round(_volume * 69.355, _round)


def ukquart2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> Cubic Meters."""
    return round(_volume * 0.00113651861617493295, _round)


def ukquart2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> Liters."""
    return round(_volume * 1.1365186161749329454, _round)


def ukquart2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> Metric Cups."""
    return round(_volume * 4.5461, _round)


def ukquart2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> Metric Tablespoons."""
    return round(_volume * 75.768, _round)


def ukquart2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> Metric Teaspoons."""
    return round(_volume * 227.30, _round)


def ukquart2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> UK Fluid Ounces."""
    return round(_volume * 40.000, _round)


def ukquart2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> UK Gallons."""
    return round(_volume * 0.25000, _round)


def ukquart2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> UK Gills."""
    return round(_volume * 8.0000, _round)


def ukquart2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> UK Pints."""
    return round(_volume * 2.0000, _round)


def ukquart2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> UK Tablespoons."""
    return round(_volume * 80.000, _round)


def ukquart2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> UK Teaspoons."""
    return round(_volume * 320.00, _round)


def ukquart2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> US Cups."""
    return round(_volume * 4.8038, _round)


def ukquart2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> US Dry Gallons."""
    return round(_volume * 0.25801, _round)


def ukquart2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> US Dry Pints."""
    return round(_volume * 2.0641, _round)


def ukquart2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> US Dry Quarts."""
    return round(_volume * 1.0321, _round)


def ukquart2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> US Fluid Ounces."""
    return round(_volume * 38.430, _round)


def ukquart2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> US Gills."""
    return round(_volume * 9.6076, _round)


def ukquart2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> US Liquid Gallons."""
    return round(_volume * 0.30024, _round)


def ukquart2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> US Liquid Pints."""
    return round(_volume * 2.4019, _round)


def ukquart2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> US Liquid Quarts."""
    return round(_volume * 1.2009, _round)


def ukquart2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> US Tablespoons."""
    return round(_volume * 76.861, _round)


def ukquart2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Quarts -> US Teaspoons."""
    return round(_volume * 230.58, _round)


# UK TABLESPOONS #


def uktablespoon2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> Canadian Cups."""
    return round(_volume * 0.062500, _round)


def uktablespoon2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> Cubic Inches."""
    return round(_volume * 0.86694, _round)


def uktablespoon2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> Cubic Meters."""
    return round(_volume * 0.00001420656343230573, _round)


def uktablespoon2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> Liters."""
    return round(_volume * 0.01420656343230572525, _round)


def uktablespoon2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> Metric Cups."""
    return round(_volume * 0.056826, _round)


def uktablespoon2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> Metric Tablespoons."""
    return round(_volume * 0.94710, _round)


def uktablespoon2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> Metric Teaspoons."""
    return round(_volume * 2.8413, _round)


def uktablespoon2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> UK Fluid Ounces."""
    return round(_volume * 0.50000, _round)


def uktablespoon2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> UK Gallons."""
    return round(_volume * 0.0031250, _round)


def uktablespoon2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> UK Gills."""
    return round(_volume * 0.10000, _round)


def uktablespoon2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> UK Pints."""
    return round(_volume * 0.025000, _round)


def uktablespoon2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> UK Quarts."""
    return round(_volume * 0.012500, _round)


def uktablespoon2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> UK Teaspoons."""
    return round(_volume * 4.0000, _round)


def uktablespoon2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> US Cups."""
    return round(_volume * 0.060048, _round)


def uktablespoon2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> US Dry Gallons."""
    return round(_volume * 0.0032252, _round)


def uktablespoon2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> US Dry Pints."""
    return round(_volume * 0.025801, _round)


def uktablespoon2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> US Dry Quarts."""
    return round(_volume * 0.012901, _round)


def uktablespoon2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> US Fluid Ounces."""
    return round(_volume * 0.48038, _round)


def uktablespoon2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> US Gills."""
    return round(_volume * 0.12010, _round)


def uktablespoon2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> US Liquid Gallons."""
    return round(_volume * 0.0037530, _round)


def uktablespoon2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> US Liquid Pints."""
    return round(_volume * 0.030024, _round)


def uktablespoon2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> US Liquid Quarts."""
    return round(_volume * 0.015012, _round)


def uktablespoon2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> US Tablespoons."""
    return round(_volume * 0.96076, _round)


def uktablespoon2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Tablespoons -> US Teaspoons."""
    return round(_volume * 2.8823, _round)


# UK TEASPOONS #


def ukteaspoon2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> Canadian Cups."""
    return round(_volume * 0.015625, _round)


def ukteaspoon2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> Cubic Inches."""
    return round(_volume * 0.21673, _round)


def ukteaspoon2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> Cubic Meters."""
    return round(_volume * 0.00000355164085807643, _round)


def ukteaspoon2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> Liters."""
    return round(_volume * 0.00355164085807643131, _round)


def ukteaspoon2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> Metric Cups."""
    return round(_volume * 0.014207, _round)


def ukteaspoon2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> Metric Tablespoons."""
    return round(_volume * 0.23678, _round)


def ukteaspoon2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> Metric Teaspoons."""
    return round(_volume * 0.71033, _round)


def ukteaspoon2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> UK Fluid Ounces."""
    return round(_volume * 0.12500, _round)


def ukteaspoon2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> UK Gallons."""
    return round(_volume * 0.00078125, _round)


def ukteaspoon2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> UK Gills."""
    return round(_volume * 0.025000, _round)


def ukteaspoon2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> UK Pints."""
    return round(_volume * 0.0062500, _round)


def ukteaspoon2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> UK Quarts."""
    return round(_volume * 0.0031250, _round)


def ukteaspoon2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> UK Tablespoons."""
    return round(_volume * 0.25000, _round)


def ukteaspoon2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> US Cups."""
    return round(_volume * 0.015012, _round)


def ukteaspoon2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> US Dry Gallons."""
    return round(_volume * 0.00080630, _round)


def ukteaspoon2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> US Dry Pints."""
    return round(_volume * 0.0064504, _round)


def ukteaspoon2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> US Dry Quarts."""
    return round(_volume * 0.0032252, _round)


def ukteaspoon2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> US Fluid Ounces."""
    return round(_volume * 0.12010, _round)


def ukteaspoon2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> US Gills."""
    return round(_volume * 0.030024, _round)


def ukteaspoon2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> US Liquid Gallons."""
    return round(_volume * 0.00093824, _round)


def ukteaspoon2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> US Liquid Pints."""
    return round(_volume * 0.0075060, _round)


def ukteaspoon2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> US Liquid Quarts."""
    return round(_volume * 0.0037530, _round)


def ukteaspoon2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> US Tablespoons."""
    return round(_volume * 0.24019, _round)


def ukteaspoon2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """UK Teaspoons -> US Teaspoons."""
    return round(_volume * 0.72057, _round)


# US CUPS #


def uscup2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> Canadian Cups."""
    return round(_volume * 1.0408, _round)


def uscup2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> Cubic Inches."""
    return round(_volume * 14.438, _round)


def uscup2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> Cubic Meters."""
    return round(_volume * 0.0002365855966688748, _round)


def uscup2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> Liters."""
    return round(_volume * 0.2365855966688747989, _round)


def uscup2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> Metric Cups."""
    return round(_volume * 0.94635, _round)


def uscup2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> Metric Tablespoons."""
    return round(_volume * 15.773, _round)


def uscup2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> Metric Teaspoons."""
    return round(_volume * 47.318, _round)


def uscup2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> UK Fluid Ounces."""
    return round(_volume * 8.3267, _round)


def uscup2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> UK Gallons."""
    return round(_volume * 0.052042, _round)


def uscup2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> UK Gills."""
    return round(_volume * 1.6653, _round)


def uscup2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> UK Pints."""
    return round(_volume * 0.41634, _round)


def uscup2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> UK Quarts."""
    return round(_volume * 0.20817, _round)


def uscup2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> UK Tablespoons."""
    return round(_volume * 16.653, _round)


def uscup2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> UK Teaspoons."""
    return round(_volume * 66.614, _round)


def uscup2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> US Dry Gallons."""
    return round(_volume * 0.053710, _round)


def uscup2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> US Dry Pints."""
    return round(_volume * 0.42968, _round)


def uscup2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> US Dry Quarts."""
    return round(_volume * 0.21484, _round)


def uscup2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> US Fluid Ounces."""
    return round(_volume * 8.0000, _round)


def uscup2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> US Gills."""
    return round(_volume * 2.0000, _round)


def uscup2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> US Liquid Gallons."""
    return round(_volume * 0.062500, _round)


def uscup2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> US Liquid Pints."""
    return round(_volume * 0.50000, _round)


def uscup2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> US Liquid Quarts."""
    return round(_volume * 0.25000, _round)


def uscup2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> US Tablespoons."""
    return round(_volume * 16.000, _round)


def uscup2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Cups -> US Teaspoons."""
    return round(_volume * 48.000, _round)


# US DRY GALLONS #


def usdrygallon2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> Canadian Cups."""
    return round(_volume * 19.379, _round)


def usdrygallon2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> Cubic Inches."""
    return round(_volume * 268.80, _round)


def usdrygallon2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> Cubic Meters."""
    return round(_volume * 0.00440489824685049775, _round)


def usdrygallon2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> Liters."""
    return round(_volume * 4.4048982468504977535, _round)


def usdrygallon2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> Metric Cups."""
    return round(_volume * 17.620, _round)


def usdrygallon2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> Metric Tablespoons."""
    return round(_volume * 293.66, _round)


def usdrygallon2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> Metric Teaspoons."""
    return round(_volume * 880.98, _round)


def usdrygallon2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> UK Fluid Ounces."""
    return round(_volume * 155.03, _round)


def usdrygallon2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> UK Gallons."""
    return round(_volume * 0.96894, _round)


def usdrygallon2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> UK Gills."""
    return round(_volume * 31.006, _round)


def usdrygallon2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> UK Pints."""
    return round(_volume * 7.7515, _round)


def usdrygallon2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> UK Quarts."""
    return round(_volume * 3.8758, _round)


def usdrygallon2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> UK Tablespoons."""
    return round(_volume * 310.06, _round)


def usdrygallon2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> UK Teaspoons."""
    return round(_volume * 1240.2, _round)


def usdrygallon2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> US Cups."""
    return round(_volume * 18.618, _round)


def usdrygallon2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> US Dry Pints."""
    return round(_volume * 8.0000, _round)


def usdrygallon2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> US Dry Quarts."""
    return round(_volume * 4.0000, _round)


def usdrygallon2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> US Fluid Ounces."""
    return round(_volume * 148.95, _round)


def usdrygallon2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> US Gills."""
    return round(_volume * 37.237, _round)


def usdrygallon2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> US Liquid Gallons."""
    return round(_volume * 1.1636, _round)


def usdrygallon2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> US Liquid Pints."""
    return round(_volume * 9.3092, _round)


def usdrygallon2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> US Liquid Quarts."""
    return round(_volume * 4.6546, _round)


def usdrygallon2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> US Tablespoons."""
    return round(_volume * 297.89, _round)


def usdrygallon2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Gallons -> US Teaspoons."""
    return round(_volume * 893.68, _round)


# US DRY PINTS #


def usdrypint2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> Canadian Cups."""
    return round(_volume * 2.4223, _round)


def usdrypint2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> Cubic Inches."""
    return round(_volume * 33.600, _round)


def usdrypint2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> Cubic Meters."""
    return round(_volume * 0.00055060015416804317, _round)


def usdrypint2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> Liters."""
    return round(_volume * 0.55060015416804316705, _round)


def usdrypint2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> Metric Cups."""
    return round(_volume * 2.2024, _round)


def usdrypint2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> Metric Tablespoons."""
    return round(_volume * 36.707, _round)


def usdrypint2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> Metric Teaspoons."""
    return round(_volume * 110.12, _round)


def usdrypint2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> UK Fluid Ounces."""
    return round(_volume * 19.379, _round)


def usdrypint2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> UK Gallons."""
    return round(_volume * 0.12112, _round)


def usdrypint2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> UK Gills."""
    return round(_volume * 3.8758, _round)


def usdrypint2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> UK Pints."""
    return round(_volume * 0.96894, _round)


def usdrypint2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> UK Quarts."""
    return round(_volume * 0.48447, _round)


def usdrypint2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> UK Tablespoons."""
    return round(_volume * 38.758, _round)


def usdrypint2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> UK Teaspoons."""
    return round(_volume * 155.03, _round)


def usdrypint2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Cups."""
    return round(_volume * 2.3273, _round)


def usdrypint2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Dry Gallons."""
    return round(_volume * 0.12500, _round)


def usdrypint2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Dry Quarts."""
    return round(_volume * 0.50000, _round)


def usdrypint2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Fluid Ounces."""
    return round(_volume * 18.618, _round)


def usdrypint2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Gills."""
    return round(_volume * 4.6546, _round)


def usdrypint2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Liquid Gallons."""
    return round(_volume * 0.14546, _round)


def usdrypint2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Liquid Pints."""
    return round(_volume * 1.1636, _round)


def usdrypint2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Liquid Quarts."""
    return round(_volume * 0.58182, _round)


def usdrypint2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Tablespoons."""
    return round(_volume * 37.237, _round)


def usdrypint2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Pints -> US Teaspoons."""
    return round(_volume * 111.71, _round)


# US DRY QUARTS #


def usdryquart2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> Canadian Cups."""
    return round(_volume * 4.8447, _round)


def usdryquart2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> Cubic Inches."""
    return round(_volume * 67.201, _round)


def usdryquart2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> Cubic Meters."""
    return round(_volume * 0.00110122456171262444, _round)


def usdryquart2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> Liters."""
    return round(_volume * 1.10122456171262443838, _round)


def usdryquart2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> Metric Cups."""
    return round(_volume * 4.4049, _round)


def usdryquart2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> Metric Tablespoons."""
    return round(_volume * 73.415, _round)


def usdryquart2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> Metric Teaspoons."""
    return round(_volume * 220.24, _round)


def usdryquart2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> UK Fluid Ounces."""
    return round(_volume * 38.758, _round)


def usdryquart2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> UK Gallons."""
    return round(_volume * 0.24223, _round)


def usdryquart2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> UK Gills."""
    return round(_volume * 7.7515, _round)


def usdryquart2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> UK Pints."""
    return round(_volume * 1.9379, _round)


def usdryquart2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> UK Quarts."""
    return round(_volume * 0.96894, _round)


def usdryquart2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> UK Tablespoons."""
    return round(_volume * 77.515, _round)


def usdryquart2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> UK Teaspoons."""
    return round(_volume * 310.06, _round)


def usdryquart2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> US Cups."""
    return round(_volume * 4.6546, _round)


def usdryquart2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> US Dry Gallons."""
    return round(_volume * 0.25000, _round)


def usdryquart2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> US Dry Pints."""
    return round(_volume * 2.0000, _round)


def usdryquart2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> US Fluid Ounces."""
    return round(_volume * 37.237, _round)


def usdryquart2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> US Gills."""
    return round(_volume * 9.3092, _round)


def usdryquart2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> US Liquid Gallons."""
    return round(_volume * 0.29091, _round)


def usdryquart2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> US Liquid Pints."""
    return round(_volume * 2.3273, _round)


def usdryquart2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> US Liquid Quarts."""
    return round(_volume * 1.1636, _round)


def usdryquart2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> US Tablespoons."""
    return round(_volume * 74.473, _round)


def usdryquart2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Dry Quarts -> US Teaspoons."""
    return round(_volume * 223.42, _round)


# US FLUID OUNCES #


def usfluidounce2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> Canadian Cups."""
    return round(_volume * 0.13011, _round)


def usfluidounce2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> Cubic Inches."""
    return round(_volume * 1.8047, _round)


def usfluidounce2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> Cubic Meters."""
    return round(_volume * 0.00002957354941740108, _round)


def usfluidounce2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> Liters."""
    return round(_volume * 0.02957354941740107648, _round)


def usfluidounce2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> Metric Cups."""
    return round(_volume * 0.11829, _round)


def usfluidounce2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> Metric Tablespoons."""
    return round(_volume * 1.9716, _round)


def usfluidounce2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> Metric Teaspoons."""
    return round(_volume * 5.9147, _round)


def usfluidounce2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> UK Fluid Ounces."""
    return round(_volume * 1.0408, _round)


def usfluidounce2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> UK Gallons."""
    return round(_volume * 0.0065053, _round)


def usfluidounce2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> UK Gills."""
    return round(_volume * 0.20817, _round)


def usfluidounce2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> UK Pints."""
    return round(_volume * 0.052042, _round)


def usfluidounce2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> UK Quarts."""
    return round(_volume * 0.026021, _round)


def usfluidounce2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> UK Tablespoons."""
    return round(_volume * 2.0817, _round)


def usfluidounce2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> UK Teaspoons."""
    return round(_volume * 8.3267, _round)


def usfluidounce2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> US Cups."""
    return round(_volume * 0.12500, _round)


def usfluidounce2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> US Dry Gallons."""
    return round(_volume * 0.0067138, _round)


def usfluidounce2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> US Dry Pints."""
    return round(_volume * 0.053710, _round)


def usfluidounce2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> US Dry Quarts."""
    return round(_volume * 0.026855, _round)


def usfluidounce2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> US Gills."""
    return round(_volume * 0.25000, _round)


def usfluidounce2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> US Liquid Gallons."""
    return round(_volume * 0.0078125, _round)


def usfluidounce2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> US Liquid Pints."""
    return round(_volume * 0.062500, _round)


def usfluidounce2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> US Liquid Quarts."""
    return round(_volume * 0.031250, _round)


def usfluidounce2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> US Tablespoons."""
    return round(_volume * 2.0000, _round)


def usfluidounce2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Fluid Ounces -> US Teaspoons."""
    return round(_volume * 6.0000, _round)


# US GILLS #


def usgill2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> Canadian Cups."""
    return round(_volume * 0.52042, _round)


def usgill2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> Cubic Inches."""
    return round(_volume * 7.2187, _round)


def usgill2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> Cubic Meters."""
    return round(_volume * 0.00011829419766960431, _round)


def usgill2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> Liters."""
    return round(_volume * 0.11829419766960430591, _round)


def usgill2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> Metric Cups."""
    return round(_volume * 0.47318, _round)


def usgill2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> Metric Tablespoons."""
    return round(_volume * 7.8863, _round)


def usgill2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> Metric Teaspoons."""
    return round(_volume * 23.659, _round)


def usgill2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> UK Fluid Ounces."""
    return round(_volume * 4.1634, _round)


def usgill2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> UK Gallons."""
    return round(_volume * 0.026021, _round)


def usgill2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> UK Gills."""
    return round(_volume * 0.83267, _round)


def usgill2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> UK Pints."""
    return round(_volume * 0.20817, _round)


def usgill2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> UK Quarts."""
    return round(_volume * 0.10408, _round)


def usgill2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> UK Tablespoons."""
    return round(_volume * 8.3267, _round)


def usgill2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> UK Teaspoons."""
    return round(_volume * 33.307, _round)


def usgill2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> US Cups."""
    return round(_volume * 0.50000, _round)


def usgill2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> US Dry Gallons."""
    return round(_volume * 0.026855, _round)


def usgill2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> US Dry Pints."""
    return round(_volume * 0.21484, _round)


def usgill2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> US Dry Quarts."""
    return round(_volume * 0.10742, _round)


def usgill2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> US Fluid Ounces."""
    return round(_volume * 4.0000, _round)


def usgill2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> US Liquid Gallons."""
    return round(_volume * 0.031250, _round)


def usgill2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> US Liquid Pints."""
    return round(_volume * 0.25000, _round)


def usgill2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> US Liquid Quarts."""
    return round(_volume * 0.12500, _round)


def usgill2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> US Tablespoons."""
    return round(_volume * 8.0000, _round)


def usgill2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Gills -> US Teaspoons."""
    return round(_volume * 24.000, _round)


# US LIQUID GALLONS #


def usliquidgallon2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> Canadian Cups."""
    return round(_volume * 16.653, _round)


def usliquidgallon2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> Cubic Inches."""
    return round(_volume * 231.00, _round)


def usliquidgallon2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> Cubic Meters."""
    return round(_volume * 0.00378544119317106409, _round)


def usliquidgallon2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> Liters."""
    return round(_volume * 3.78544119317106408752, _round)


def usliquidgallon2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> Metric Cups."""
    return round(_volume * 15.142, _round)


def usliquidgallon2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> Metric Tablespoons."""
    return round(_volume * 252.36, _round)


def usliquidgallon2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> Metric Teaspoons."""
    return round(_volume * 757.08, _round)


def usliquidgallon2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> UK Fluid Ounces."""
    return round(_volume * 133.23, _round)


def usliquidgallon2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> UK Gallons."""
    return round(_volume * 0.83267, _round)


def usliquidgallon2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> UK Gills."""
    return round(_volume * 26.646, _round)


def usliquidgallon2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> UK Pints."""
    return round(_volume * 6.6614, _round)


def usliquidgallon2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> UK Quarts."""
    return round(_volume * 3.3307, _round)


def usliquidgallon2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> UK Tablespoons."""
    return round(_volume * 266.46, _round)


def usliquidgallon2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> UK Teaspoons."""
    return round(_volume * 1065.8, _round)


def usliquidgallon2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> US Cups."""
    return round(_volume * 16.000, _round)


def usliquidgallon2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> US Dry Gallons."""
    return round(_volume * 0.85937, _round)


def usliquidgallon2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> US Dry Pints."""
    return round(_volume * 6.8749, _round)


def usliquidgallon2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> US Dry Quarts."""
    return round(_volume * 3.4375, _round)


def usliquidgallon2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> US Fluid Ounces."""
    return round(_volume * 128.00, _round)


def usliquidgallon2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> US Gills."""
    return round(_volume * 32.000, _round)


def usliquidgallon2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> US Liquid Pints."""
    return round(_volume * 8.0000, _round)


def usliquidgallon2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> US Liquid Quarts."""
    return round(_volume * 4.0000, _round)


def usliquidgallon2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> US Tablespoons."""
    return round(_volume * 256.00, _round)


def usliquidgallon2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Gallons -> US Teaspoons."""
    return round(_volume * 768.00, _round)


# US LIQUID PINTS #


def usliquidpint2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> Canadian Cups."""
    return round(_volume * 2.0817, _round)


def usliquidpint2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> Cubic Inches."""
    return round(_volume * 28.875, _round)


def usliquidpint2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> Cubic Meters."""
    return round(_volume * 0.0004731711933377496, _round)


def usliquidpint2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> Liters."""
    return round(_volume * 0.4731711933377495978, _round)


def usliquidpint2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> Metric Cups."""
    return round(_volume * 1.8927, _round)


def usliquidpint2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> Metric Tablespoons."""
    return round(_volume * 31.545, _round)


def usliquidpint2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> Metric Teaspoons."""
    return round(_volume * 94.635, _round)


def usliquidpint2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> UK Fluid Ounces."""
    return round(_volume * 16.653, _round)


def usliquidpint2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> UK Gallons."""
    return round(_volume * 0.10408, _round)


def usliquidpint2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> UK Gills."""
    return round(_volume * 3.3307, _round)


def usliquidpint2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> UK Pints."""
    return round(_volume * 0.83267, _round)


def usliquidpint2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> UK Quarts."""
    return round(_volume * 0.41634, _round)


def usliquidpint2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> UK Tablespoons."""
    return round(_volume * 33.307, _round)


def usliquidpint2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> UK Teaspoons."""
    return round(_volume * 133.23, _round)


def usliquidpint2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Cups."""
    return round(_volume * 2.0000, _round)


def usliquidpint2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Dry Gallons."""
    return round(_volume * 0.10742, _round)


def usliquidpint2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Dry Pints."""
    return round(_volume * 0.85937, _round)


def usliquidpint2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Dry Quarts."""
    return round(_volume * 0.42968, _round)


def usliquidpint2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Fluid Ounces."""
    return round(_volume * 16.000, _round)


def usliquidpint2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Gills."""
    return round(_volume * 4.0000, _round)


def usliquidpint2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Liquid Gallons."""
    return round(_volume * 0.12500, _round)


def usliquidpint2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Liquid Quarts."""
    return round(_volume * 0.50000, _round)


def usliquidpint2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Tablespoons."""
    return round(_volume * 32.000, _round)


def usliquidpint2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Pints -> US Teaspoons."""
    return round(_volume * 96.000, _round)


# US LIQUID QUARTS #


def usliquidquart2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> Canadian Cups."""
    return round(_volume * 4.1634, _round)


def usliquidquart2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> Cubic Inches."""
    return round(_volume * 57.750, _round)


def usliquidquart2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> Cubic Meters."""
    return round(_volume * 0.0009463423866754992, _round)


def usliquidquart2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> Liters."""
    return round(_volume * 0.94634238667549919561, _round)


def usliquidquart2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> Metric Cups."""
    return round(_volume * 3.7854, _round)


def usliquidquart2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> Metric Tablespoons."""
    return round(_volume * 63.090, _round)


def usliquidquart2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> Metric Teaspoons."""
    return round(_volume * 189.27, _round)


def usliquidquart2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> UK Fluid Ounces."""
    return round(_volume * 33.307, _round)


def usliquidquart2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> UK Gallons."""
    return round(_volume * 0.20817, _round)


def usliquidquart2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> UK Gills."""
    return round(_volume * 6.6614, _round)


def usliquidquart2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> UK Pints."""
    return round(_volume * 1.6653, _round)


def usliquidquart2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> UK Quarts."""
    return round(_volume * 0.83267, _round)


def usliquidquart2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> UK Tablespoons."""
    return round(_volume * 66.614, _round)


def usliquidquart2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> UK Teaspoons."""
    return round(_volume * 266.46, _round)


def usliquidquart2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> US Cups."""
    return round(_volume * 4.0000, _round)


def usliquidquart2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> US Dry Gallons."""
    return round(_volume * 0.21484, _round)


def usliquidquart2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> US Dry Pints."""
    return round(_volume * 1.7187, _round)


def usliquidquart2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> US Dry Quarts."""
    return round(_volume * 0.85937, _round)


def usliquidquart2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> US Fluid Ounces."""
    return round(_volume * 32.000, _round)


def usliquidquart2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> US Gills."""
    return round(_volume * 8.0000, _round)


def usliquidquart2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> US Liquid Gallons."""
    return round(_volume * 0.25000, _round)


def usliquidquart2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> US Liquid Pints."""
    return round(_volume * 2.0000, _round)


def usliquidquart2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> US Tablespoons."""
    return round(_volume * 64.000, _round)


def usliquidquart2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Liquid Quarts -> US Teaspoons."""
    return round(_volume * 192.00, _round)


# US TABLESPOONS #


def ustablespoon2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> Canadian Cups."""
    return round(_volume * 0.065053, _round)


def ustablespoon2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> Cubic Inches."""
    return round(_volume * 0.90234, _round)


def ustablespoon2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> Cubic Meters."""
    return round(_volume * 0.00001478677470870054, _round)


def ustablespoon2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> Liters."""
    return round(_volume * 0.01478677470870053824, _round)


def ustablespoon2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> Metric Cups."""
    return round(_volume * 0.059147, _round)


def ustablespoon2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> Metric Tablespoons."""
    return round(_volume * 0.98578, _round)


def ustablespoon2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> Metric Teaspoons."""
    return round(_volume * 2.9574, _round)


def ustablespoon2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> UK Fluid Ounces."""
    return round(_volume * 0.52042, _round)


def ustablespoon2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> UK Gallons."""
    return round(_volume * 0.0032526, _round)


def ustablespoon2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> UK Gills."""
    return round(_volume * 0.10408, _round)


def ustablespoon2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> UK Pints."""
    return round(_volume * 0.026021, _round)


def ustablespoon2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> UK Quarts."""
    return round(_volume * 0.013011, _round)


def ustablespoon2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> UK Tablespoons."""
    return round(_volume * 1.0408, _round)


def ustablespoon2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> UK Teaspoons."""
    return round(_volume * 4.1634, _round)


def ustablespoon2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> US Cups."""
    return round(_volume * 0.062500, _round)


def ustablespoon2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> US Dry Gallons."""
    return round(_volume * 0.0033569, _round)


def ustablespoon2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> US Dry Pints."""
    return round(_volume * 0.026855, _round)


def ustablespoon2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> US Dry Quarts."""
    return round(_volume * 0.013428, _round)


def ustablespoon2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> US Fluid Ounces."""
    return round(_volume * 0.50000, _round)


def ustablespoon2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> US Gills."""
    return round(_volume * 0.12500, _round)


def ustablespoon2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> US Liquid Gallons."""
    return round(_volume * 0.0039062, _round)


def ustablespoon2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> US Liquid Pints."""
    return round(_volume * 0.031250, _round)


def ustablespoon2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> US Liquid Quarts."""
    return round(_volume * 0.015625, _round)


def ustablespoon2usteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Tablespoons -> US Teaspoons."""
    return round(_volume * 3.0000, _round)


# US TEASPOONS #


def usteaspoon2cancup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> Canadian Cups."""
    return round(_volume * 0.021684, _round)


def usteaspoon2cubicinch(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> Cubic Inches."""
    return round(_volume * 0.30078, _round)


def usteaspoon2cubicmeter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> Cubic Meters."""
    return round(_volume * 0.00000492902208201893, _round)


def usteaspoon2liter(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> Liters."""
    return round(_volume * 0.00492902208201892744, _round)


def usteaspoon2metriccup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> Metric Cups."""
    return round(_volume * 0.019716, _round)


def usteaspoon2metrictablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> Metric Tablespoons."""
    return round(_volume * 0.32859, _round)


def usteaspoon2metricteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> Metric Teaspoons."""
    return round(_volume * 0.98578, _round)


def usteaspoon2ukfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> UK Fluid Ounces."""
    return round(_volume * 0.17347, _round)


def usteaspoon2ukgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> UK Gallons."""
    return round(_volume * 0.0010842, _round)


def usteaspoon2ukgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> UK Gills."""
    return round(_volume * 0.034695, _round)


def usteaspoon2ukpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> UK Pints."""
    return round(_volume * 0.0086737, _round)


def usteaspoon2ukquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> UK Quarts."""
    return round(_volume * 0.0043368, _round)


def usteaspoon2uktablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> UK Tablespoons."""
    return round(_volume * 0.34695, _round)


def usteaspoon2ukteaspoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> UK Teaspoons."""
    return round(_volume * 1.3878, _round)


def usteaspoon2uscup(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> US Cups."""
    return round(_volume * 0.020833, _round)


def usteaspoon2usdrygallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> US Dry Gallons."""
    return round(_volume * 0.0011190, _round)


def usteaspoon2usdrypint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> US Dry Pints."""
    return round(_volume * 0.0089517, _round)


def usteaspoon2usdryquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> US Dry Quarts."""
    return round(_volume * 0.0044759, _round)


def usteaspoon2usfluidounce(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> US Fluid Ounces."""
    return round(_volume * 0.16667, _round)


def usteaspoon2usgill(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> US Gills."""
    return round(_volume * 0.041667, _round)


def usteaspoon2usliquidgallon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> US Liquid Gallons."""
    return round(_volume * 0.0013021, _round)


def usteaspoon2usliquidpint(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> US Liquid Pints."""
    return round(_volume * 0.010417, _round)


def usteaspoon2usliquidquart(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> US Liquid Quarts."""
    return round(_volume * 0.0052083, _round)


def usteaspoon2ustablespoon(_volume: Union[float, int], _round: int = 3) -> float:
    """US Teaspoons -> US Tablespoons."""
    return round(_volume * 0.33333, _round)

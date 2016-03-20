#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""@brief Measurement (Time) Conversions
@file convtime.py
@package pybooster.convtime
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@version 2016.03.20

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
    # CONSTANTS
    'DAYS_IN_WEEK',
    'HOURS_IN_DAY',
    'MINUTES_IN_HOUR',
    'SECONDS_IN_DAY',
    'SECONDS_IN_HOUR',
    'SECONDS_IN_MINUTE',
    # DAYS
    'day2second',
    # SECONDS
    'second2day',
]


# CONSTANTS


DAYS_IN_WEEK = 7
HOURS_IN_DAY = 24
MINUTES_IN_HOUR = 60
SECONDS_IN_DAY = 86400
SECONDS_IN_HOUR = 360
SECONDS_IN_MINUTE = 60


# DAYS


def day2second(_time: int or float, _round: int=3) -> float:
    """Days -> Seconds"""
    return round(_time * 86400, _round)


# SECONDS


def second2day(_time: int or float, _round: int=3) -> float:
    """Seconds -> Days"""
    return round(_time * 0.000011574074074, _round)

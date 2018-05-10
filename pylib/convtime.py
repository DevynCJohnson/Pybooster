#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Time measurement conversions

@file convtime.py
@package pybooster.convtime
@version 2018.04.27
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


__all__ = [
    # CONSTANTS #
    r'DAYS_IN_WEEK',
    r'HOURS_IN_DAY',
    r'MINUTES_IN_HOUR',
    r'SECONDS_IN_DAY',
    r'SECONDS_IN_HOUR',
    r'SECONDS_IN_MINUTE',
    # DAYS #
    r'day2second',
    # SECONDS #
    r'second2day'
]


# CONSTANTS #


DAYS_IN_WEEK = 7
HOURS_IN_DAY = 24
MINUTES_IN_HOUR = 60
SECONDS_IN_DAY = 86400
SECONDS_IN_HOUR = 360
SECONDS_IN_MINUTE = 60


# DAYS #


def day2second(_time: int or float, _round: int = 3) -> float:
    """Days -> Seconds"""
    return round(_time * 86400, _round)


# SECONDS #


def second2day(_time: int or float, _round: int = 3) -> float:
    """Seconds -> Days"""
    return round(_time * 0.000011574074074, _round)
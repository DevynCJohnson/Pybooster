#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""@brief Time Utilities
@file timeutil.py
@package pybooster.timeutil
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


import datetime
import sys

import time as pytime


__all__ = [
    # CONSTANTS
    'SEASONS',
    'YEAR',
    # BOOLEAN FUNCTIONS
    'istoday',
    'istodaysunday',
    'istodaymonday',
    'istodaytuesday',
    'istodaywednesday',
    'istodaythursday',
    'istodayfriday',
    'istodaysaturday',
    'isyear',
    # FUNCTIONS
    'currentseason',
    'weekday',
    'month',
    'year',
    'date',
    'clock',
    'date_time',
    'dateandtime',
    'day',
    'hour',
    'fulltime',
    'sysuptime',
]


# CONSTANTS


SEASONS = (
    r'spring',
    r'summer',
    r'autumn',
    r'winter'
)


YEAR = int(pytime.strftime('%Y'))


# BOOLEAN FUNCTIONS


def istoday(_weekday: str) -> bool:
    """Test if today is a particular weekday"""
    return _weekday.lower() == pytime.strftime('%A').lower()


def istodaysunday() -> bool:
    """Test if today is Sunday"""
    return pytime.strftime(r'%A') == r'Sunday'


def istodaymonday() -> bool:
    """Test if today is Monday"""
    return pytime.strftime(r'%A') == r'Monday'


def istodaytuesday() -> bool:
    """Test if today is Tuesday"""
    return pytime.strftime(r'%A') == r'Tuesday'


def istodaywednesday() -> bool:
    """Test if today is Wednesday"""
    return pytime.strftime(r'%A') == r'Wednesday'


def istodaythursday() -> bool:
    """Test if today is Thursday"""
    return pytime.strftime(r'%A') == r'Thursday'


def istodayfriday() -> bool:
    """Test if today is Friday"""
    return pytime.strftime(r'%A') == r'Friday'


def istodaysaturday() -> bool:
    """Test if today is Saturday"""
    return pytime.strftime(r'%A') == r'Saturday'


def isyear(_year: str or int) -> bool:
    """Test if today is a particular year"""
    if isinstance(_year, int):
        _year = str(_year)
    return pytime.strftime('%Y') == _year


# FUNCTIONS


def currentseason(_hemisphere: str='n') -> str:
    """Return the current season"""
    _day = pytime.localtime().tm_yday
    if _day in range(80, 172):  # Spring
        season = r'spring'
    elif _day in range(172, 264):  # Summer
        season = r'summer'
    elif _day in range(264, 355):  # Fall
        season = r'fall'
    else:  # Winter
        season = r'winter'
    _hemisphere = _hemisphere.lower()
    if _hemisphere != 'n':
        if season is r'spring':
            return r'fall'
        elif season is r'fall':
            return r'spring'
        elif season is r'summer':
            return r'winter'
        elif season is r'winter':
            return r'summer'
    return season


def weekday() -> str:
    """Return the name of the weekday"""
    return pytime.strftime(r'%A')


def month() -> str:
    """Return the name of the month"""
    return pytime.strftime(r'%B')


def year() -> str:
    """Return the year"""
    return pytime.strftime(r'%Y')


def date() -> str:
    """Return the date"""
    return pytime.strftime(r'%x')


def clock() -> str:
    """Return the time"""
    return pytime.strftime(r'%X')


def date_time() -> str:
    """Return the date and time"""
    return pytime.strftime(r'%x %X')


def dateandtime() -> str:
    """Return the date and time"""
    return pytime.strftime(r'%x %X')


def day() -> str:
    """Return the day"""
    return pytime.strftime(r'%d')


def hour() -> str:
    """Return the hour"""
    return pytime.strftime(r'%I')


def fulltime() -> str:
    """Return the time, month, year, etc."""
    return pytime.strftime(r'%A %b %d, %Y, %X')


def sysuptime() -> str:
    """Return the system's uptime"""
    if sys.platform.startswith(r'win'):
        try:
            import win32api
            _uptime = win32api.GetTickCount()
        except ImportError:
            _uptime = r'Unknown'
    else:
        try:
            with open(r'/proc/uptime', mode='rt', encoding='utf-8') as _file:
                _seconds = float(_file.readline().split()[0])
                _uptime = str(datetime.timedelta(seconds=_seconds))
        except FileNotFoundError:
            _uptime = r'Unknown'
    return _uptime

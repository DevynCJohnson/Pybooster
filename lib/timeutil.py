#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
Created by Devyn Collier Johnson
<DevynCJohnson@Gmail.com>
LGPLv3 License
-- --
PyBooster - Various Extras for Python3
pybooster.timeutil
-- --
Time Utilities
-- --
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

__author__ = 'Devyn Collier Johnson'
__copyright__ = 'LGPLv3'
__version__ = '2016.03.09'


# CONSTANTS


SEASONS = (
    'spring',
    'summer',
    'autumn',
    'winter'
)


YEAR = int(pytime.strftime('%Y'))


# BOOLEAN FUNCTIONS


def istoday(_weekday: str) -> bool:
    """Test if today is a particular weekday"""
    return _weekday.lower() == pytime.strftime('%A').lower()


def istodaysunday() -> bool:
    """Test if today is Sunday"""
    return r'Sunday' == pytime.strftime(r'%A')


def istodaymonday() -> bool:
    """Test if today is Monday"""
    return r'Monday' == pytime.strftime(r'%A')


def istodaytuesday() -> bool:
    """Test if today is Tuesday"""
    return r'Tuesday' == pytime.strftime(r'%A')


def istodaywednesday() -> bool:
    """Test if today is Wednesday"""
    return r'Wednesday' == pytime.strftime(r'%A')


def istodaythursday() -> bool:
    """Test if today is Thursday"""
    return r'Thursday' == pytime.strftime(r'%A')


def istodayfriday() -> bool:
    """Test if today is Friday"""
    return r'Friday' == pytime.strftime(r'%A')


def istodaysaturday() -> bool:
    """Test if today is Saturday"""
    return r'Saturday' == pytime.strftime(r'%A')


def isyear(_year: str or int) -> bool:
    """Test if today is a particular year"""
    if isinstance(_year, int):
        _year = str(_year)
    return _year == pytime.strftime('%Y')


# FUNCTIONS


def currentseason(_hemisphere: str='n') -> str:
    """Return the current season"""
    _day = pytime.localtime().tm_yday
    if _day in range(80, 172):  # Spring
        season = 'spring'
    elif _day in range(172, 264):  # Summer
        season = 'summer'
    elif _day in range(264, 355):  # Fall
        season = 'fall'
    else:  # Winter
        season = 'winter'
    _hemisphere = _hemisphere.lower()
    if _hemisphere != 'n':
        if season is 'spring':
            return 'fall'
        elif season is 'fall':
            return 'spring'
        elif season is 'summer':
            return 'winter'
        elif season is 'winter':
            return 'summer'
    return season


def weekday() -> str:
    """Return the name of the weekday"""
    return pytime.strftime('%A')


def month() -> str:
    """Return the name of the month"""
    return pytime.strftime('%B')


def year() -> str:
    """Return the year"""
    return pytime.strftime('%Y')


def date() -> str:
    """Return the date"""
    return pytime.strftime('%x')


def clock() -> str:
    """Return the time"""
    return pytime.strftime('%X')


def date_time() -> str:
    """Return the date and time"""
    return pytime.strftime('%x %X')


def dateandtime() -> str:
    """Return the date and time"""
    return pytime.strftime('%x %X')


def day() -> str:
    """Return the day"""
    return pytime.strftime('%d')


def hour() -> str:
    """Return the hour"""
    return pytime.strftime('%I')


def fulltime() -> str:
    """Return the time, month, year, etc."""
    return pytime.strftime('%A %b %d, %Y, %X')


def sysuptime() -> str:
    """Return the system's uptime"""
    if sys.platform.startswith('win'):
        try:
            import win32api
            _uptime = win32api.GetTickCount()
        except ImportError:
            _uptime = 'Unknown'
    else:
        try:
            with open('/proc/uptime', 'r') as _file:
                _seconds = float(_file.readline().split()[0])
                _uptime = str(datetime.timedelta(seconds=_seconds))
        except FileNotFoundError:
            _uptime = 'Unknown'
    return _uptime

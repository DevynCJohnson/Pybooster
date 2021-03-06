#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Time Utilities.

@file timeutil.py
@package pybooster.timeutil
@version 2020.11.20
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


from datetime import timedelta
import time as pytime
from typing import Union


__all__: list = [
    # CONSTANTS #
    r'SEASONS',
    r'YEAR',
    # BOOLEAN FUNCTIONS #
    r'istoday',
    r'istodaysunday',
    r'istodaymonday',
    r'istodaytuesday',
    r'istodaywednesday',
    r'istodaythursday',
    r'istodayfriday',
    r'istodaysaturday',
    r'isyear',
    r'is_christmas',
    r'is_halloween',
    r'is_new_years_day',
    r'is_new_years_eve',
    # FUNCTIONS #
    r'currentseason',
    r'weekday',
    r'month',
    r'year',
    r'date',
    r'clock',
    r'date_time',
    r'dateandtime',
    r'day',
    r'hour',
    r'fulltime',
    r'sysuptime'
]


# CONSTANTS #


SEASONS = (r'spring', r'summer', r'autumn', r'winter')
YEAR = int(pytime.strftime(r'%Y'))


# BOOLEAN FUNCTIONS #


def istoday(_weekday: str) -> bool:
    """Test if today is a particular weekday."""
    return _weekday.casefold() == pytime.strftime(r'%A').casefold()


def istodaysunday() -> bool:
    """Test if today is Sunday."""
    return pytime.strftime(r'%A') == r'Sunday'


def istodaymonday() -> bool:
    """Test if today is Monday."""
    return pytime.strftime(r'%A') == r'Monday'


def istodaytuesday() -> bool:
    """Test if today is Tuesday."""
    return pytime.strftime(r'%A') == r'Tuesday'


def istodaywednesday() -> bool:
    """Test if today is Wednesday."""
    return pytime.strftime(r'%A') == r'Wednesday'


def istodaythursday() -> bool:
    """Test if today is Thursday."""
    return pytime.strftime(r'%A') == r'Thursday'


def istodayfriday() -> bool:
    """Test if today is Friday."""
    return pytime.strftime(r'%A') == r'Friday'


def istodaysaturday() -> bool:
    """Test if today is Saturday."""
    return pytime.strftime(r'%A') == r'Saturday'


def isyear(_year: Union[int, str]) -> bool:
    """Test if today is a particular year."""
    if isinstance(_year, int):
        _year = str(_year)
    return pytime.strftime(r'%Y') == _year


def is_christmas(_unix_time: Union[int, str] = 0) -> bool:
    """Test if today is Christmas."""
    _today = datetime.utcfromtimestamp(_unix_time) if _unix_time else datetime.today()
    return _today.month == 12 and _today.day == 25


def is_halloween(_unix_time: Union[int, str] = 0) -> bool:
    """Test if today is Halloween."""
    _today = datetime.utcfromtimestamp(_unix_time) if _unix_time else datetime.today()
    return _today.month == 10 and _today.day == 31


def is_new_years_day(_unix_time: Union[int, str] = 0) -> bool:
    """Test if today is New Year's Day."""
    _today = datetime.utcfromtimestamp(_unix_time) if _unix_time else datetime.today()
    return _today.month == 1 and _today.day == 1


def is_new_years_eve(_unix_time: Union[int, str] = 0) -> bool:
    """Test if today is New Year's Eve."""
    _today = datetime.utcfromtimestamp(_unix_time) if _unix_time else datetime.today()
    return _today.month == 12 and _today.day == 31


# FUNCTIONS #


def currentseason(_hemisphere: str = 'n') -> str:
    """Return the current season."""
    _day = pytime.localtime().tm_yday
    if _day in range(80, 172):  # Spring
        season = r'spring'
    elif _day in range(172, 264):  # Summer
        season = r'summer'
    elif _day in range(264, 355):  # Fall
        season = r'fall'
    else:  # Winter
        season = r'winter'
    if _hemisphere.casefold() != 'n':
        if season == r'spring':
            return r'fall'
        if season == r'fall':
            return r'spring'
        if season == r'summer':
            return r'winter'
        if season == r'winter':
            return r'summer'
    return season


def weekday(_unix_time: Union[int, str] = 0) -> str:
    """Return the name of the weekday."""
    return pytime.strftime(r'%A') if not _unix_time else datetime.utcfromtimestamp(_unix_time).strftime(r'%A')


def month() -> str:
    """Return the name of the month."""
    return pytime.strftime(r'%B')


def year() -> str:
    """Return the year."""
    return pytime.strftime(r'%Y')


def date(_unix_time: Union[int, str] = 0) -> str:
    """Return the date."""
    return pytime.strftime(r'%x') if not _unix_time else datetime.utcfromtimestamp(_unix_time).strftime(r'%x')


def clock() -> str:
    """Return the time."""
    return pytime.strftime(r'%X')


def date_time() -> str:
    """Return the date and time."""
    return pytime.strftime(r'%x %X')


def dateandtime() -> str:
    """Return the date and time."""
    return pytime.strftime(r'%x %X')


def day(_unix_time: Union[int, str] = 0) -> str:
    """Return the day."""
    return pytime.strftime(r'%d') if not _unix_time else datetime.utcfromtimestamp(_unix_time).strftime(r'%d')


def hour() -> str:
    """Return the hour."""
    return pytime.strftime(r'%I')


def fulltime() -> str:
    """Return the time, month, year, etc.."""
    return pytime.strftime(r'%A %b %d, %Y, %X')


def sysuptime() -> str:
    """Return the system's uptime."""
    try:
        with open(r'/proc/uptime', mode=r'rt', encoding=r'utf-8') as _file:
            _seconds = float(_file.readline().split()[0])
            return str(timedelta(seconds=_seconds))
    except FileNotFoundError:
        return r'Unknown'

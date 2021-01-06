#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Functions related to obtaining or processing geographic data.

@file geo.py
@package pybooster.geo
@version 2020.11.28
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


from json import loads
from urllib.request import urlopen


__all__: list = [
    # CONSTANTS #
    r'ZIPCODE_PRIMARY_STATE',
    # FUNCTIONS #
    r'getgeodata',
    r'getcity',
    r'getcountry',
    r'getisp',
    r'getlatitude',
    r'getlongitude',
    r'gettimezone',
    r'getzipcode',
    r'getzipcode_int',
    r'dms2dd'
]


# CONSTANTS #


"""Dictionary indicating the first digit of the zip code that each state uses"""
ZIPCODE_PRIMARY_STATE: dict = {
    r'0': {r'AE', r'CT', r'MA', r'ME', r'NH', r'NJ', r'NY', r'PR', r'RI', r'VI', r'VT'},
    r'1': {r'DE', r'NY', r'PA'},
    r'2': {r'DC', r'MD', r'NC', r'SC', r'VA', r'WV'},
    r'3': {r'AA', r'AL', r'FL', r'GA', r'MS', r'TN'},
    r'4': {r'IN', r'KY', r'MI', r'OH'},
    r'5': {r'IA', r'MN', r'MT', r'ND', r'SD', r'WI'},
    r'6': {r'IL', r'KS', r'MO', r'NE'},
    r'7': {r'AR', r'LA', r'OK', r'TX'},
    r'8': {r'AZ', r'CO', r'ID', r'NM', r'NV', r'UT', r'WY'},
    r'9': {r'AK', r'AP', r'AS', r'CA', r'FM', r'GU', r'HI', r'MH', r'MP', r'OR', r'PW', r'WA'}
}


# FUNCTIONS #


def zip2states(_zipcode: int) -> set:
    """Return a set of USA state abbreviations that use zip codes that begin with the same number as the given zip code.

    >>> data = list(zip2states(63119)); data.sort(); data
    ['IL', 'KS', 'MO', 'NE']
    >>> data = list(zip2states(47542)); data.sort(); data
    ['IN', 'KY', 'MI', 'OH']
    """
    return ZIPCODE_PRIMARY_STATE[str(_zipcode)[0]]


def getgeodata() -> dict:
    """Retrieve the system's current geographical location based on the ISP."""
    with urlopen(r'http://ip-api.com/json') as conn:  # nosec
        return loads(conn.read().decode(r'utf-8'))


def getcity(_loc: dict) -> str:
    """Retrieve the system's current city based on the ISP.

    Prerequisite: Data from getgeodata()
    """
    return _loc[r'city']


def getcountry(_loc: dict) -> str:
    """Retrieve the system's current country based on the ISP.

    Prerequisite: Data from getgeodata()
    """
    return _loc[r'country']


def getisp(_loc: dict) -> str:
    """Retrieve the system's current ISP.

    Prerequisite: Data from getgeodata()
    """
    return _loc[r'isp']


def getlatitude(_loc: dict) -> float:
    """Retrieve the system's current latitude based on the ISP.

    Prerequisite: Data from getgeodata()
    """
    return _loc[r'lat']


def getlongitude(_loc: dict) -> float:
    """Retrieve the system's current longitude based on the ISP.

    Prerequisite: Data from getgeodata()
    """
    return _loc[r'lon']


def gettimezone(_loc: dict) -> str:
    """Retrieve the system's current timezone based on the ISP.

    Prerequisite: Data from getgeodata()
    """
    return _loc[r'timezone']


def getzipcode(_loc: dict) -> str:
    """Retrieve the system's current zipcode (as a string) based on the ISP.

    Prerequisite: Data from getgeodata()
    """
    return _loc[r'zip']


def getzipcode_int(_loc: dict) -> int:
    """Retrieve the system's current zipcode (as an integer) based on the ISP.

    Prerequisite: Data from getgeodata()
    """
    return int(_loc[r'zip'])


def dms2dd(_degrees: int, _minutes: int, _seconds: float) -> float:
    """Convert DMS coordinates (degrees, minutes, and seconds) to DD coordinates (decimal degrees).

    >>> dms2dd(78, 55, 44.29458)
    78.92897071666667
    """
    return _degrees + _minutes / 60.0 + _seconds / 3600.0


def dd2dms(deg: float) -> list:
    """Convert DD coordinates (decimal degrees) to DMS coordinates (degrees, minutes, and seconds)."""
    _degrees: int = int(deg)
    mindegrees: float = abs(deg - _degrees) * 60
    _minutes: int = int(mindegrees)
    _seconds: float = (mindegrees - _minutes) * 60
    return [_degrees, _minutes, _seconds]

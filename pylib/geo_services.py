#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Functions related to obtaining or processing current/local geographic data

@file geo_services.py
@package pybooster.geo_services
@version 2018.09.11
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


from json import loads
from urllib.request import urlopen


__all__: list = [
    r'getgeodata',
    r'getcity',
    r'getcountry',
    r'getisp',
    r'getlatitude',
    r'getlongitude',
    r'gettimezone',
    r'getzipcode',
    r'getzipcode_int'
]


def getgeodata() -> dict:
    """Retrieve the system's current geographical location based on the ISP"""
    return loads(urlopen(r'http://ip-api.com/json').read().decode(r'utf-8'))  # nosec


def getcity(_loc: dict) -> str:
    """Retrieve the system's current city based on the ISP

    Prerequisite: Data from getgeodata()
    """
    return _loc[r'city']


def getcountry(_loc: dict) -> str:
    """Retrieve the system's current country based on the ISP

    Prerequisite: Data from getgeodata()
    """
    return _loc[r'country']


def getisp(_loc: dict) -> str:
    """Retrieve the system's current ISP

    Prerequisite: Data from getgeodata()
    """
    return _loc[r'isp']


def getlatitude(_loc: dict) -> float:
    """Retrieve the system's current latitude based on the ISP

    Prerequisite: Data from getgeodata()
    """
    return _loc[r'lat']


def getlongitude(_loc: dict) -> float:
    """Retrieve the system's current longitude based on the ISP

    Prerequisite: data from getgeodata()
    """
    return _loc[r'lon']


def gettimezone(_loc: dict) -> str:
    """Retrieve the system's current timezone based on the ISP

    Prerequisite: data from getgeodata()
    """
    return _loc[r'timezone']


def getzipcode(_loc: dict) -> str:
    """Retrieve the system's current zipcode (as a string) based on the ISP

    Prerequisite: data from getgeodata()
    """
    return _loc[r'zip']


def getzipcode_int(_loc: dict) -> int:
    """Retrieve the system's current zipcode (as an integer) based on the ISP

    Prerequisite: data from getgeodata()
    """
    return int(_loc[r'zip'])

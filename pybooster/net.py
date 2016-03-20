#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""@brief Network-related functions
@file net.py
@package pybooster.net
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


from socket import gaierror, gethostbyname, inet_ntoa
from struct import pack
from subprocess import PIPE, Popen, TimeoutExpired
from urllib.request import urlopen


__all__ = [
    # IPV4/6 CONVERTIONS
    'ints2ipv6',
    'lst2ipv6',
    # MISCELLANEOUS
    'isdomain',
    'name2ip',
    'ping',
    'findgw',
    'hasnet',
]


# IPV4/6 CONVERTIONS


def ints2ipv6(*args: int) -> str:
    """When given eight separate integers, a hex IPv6 address is returned"""
    if len(args) is 8:
        for i in args:
            assert i <= 65535, \
                'One of the given integers is larger than 65535!'
        return ':'.join('{:02x}'.format(i) for i in args)
    else:
        raise ValueError(r'The given data must have eight groups of integers.')


def lst2ipv6(_list: list) -> str:
    """When given eight separate integers, a hex IPv6 address is returned"""
    if len(_list) is 8:
        for i in _list:
            assert i <= 65535, \
                'One of the given integers is larger than 65535!'
        return ':'.join('{:02x}'.format(i) for i in _list)
    else:
        raise ValueError(r'The given data must have eight groups of integers.')


# MISCELLANEOUS


def name2ip(_address: str='localhost') -> str:
    """Convert a domain name to an IPv4 address"""
    return gethostbyname(_address)


def isdomain(_address: str) -> bool:
    """Test if a Domain Name resolves to an IP address"""
    try:
        gethostbyname(_address)
    except gaierror:
        return False
    return True


def ping(_address: str='localhost') -> bool:
    """Specify an IP address or a domain name"""
    try:
        child = Popen(['ping', '-c 1', _address], stdout=PIPE, stderr=PIPE, shell=False)
        _results = child.communicate(timeout=3)[0]  # Wait for results and get return code
    except TimeoutExpired:
        return False
    if len(_results) and child.returncode is 0:
        return True
    return False


def findgw() -> str:
    """Get the Gateway IP address"""
    with open(r'/proc/net/route', mode='rt', encoding='utf-8') as _file:
        for _line in _file:
            _field = _line.strip().split()
            if _field[1] != '00000000' or not int(_field[3], 16) & 2:
                continue
            return inet_ntoa(pack('<L', int(_field[2], 16)))


def hasnet() -> bool:
    """Return True if the Internet is available"""
    if urlopen(r'http://google.com').getcode() == 200:
        return True
    elif urlopen(r'https://www.wikipedia.org').getcode() == 200:
        return True
    elif urlopen(r'https://docs.python.org').getcode() == 200:
        return True
    return False

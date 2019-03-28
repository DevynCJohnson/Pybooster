#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Network-related functions

@file net.py
@package pybooster.net
@version 2019.03.28
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


from socket import gaierror, gethostbyname, inet_ntoa
from struct import pack
from subprocess import PIPE, Popen, TimeoutExpired  # nosec
from urllib.request import urlopen


__all__: list = [
    # IPV4/6 CONVERTIONS #
    r'ints2ipv6',
    r'lst2ipv6',
    # MISCELLANEOUS #
    r'isdomain',
    r'name2ip',
    r'ping',
    r'findgw',
    r'hasnet',
    r'getwebpage'
]


# IPV4/6 CONVERTIONS #


def ints2ipv6(*args: int) -> str:
    """When given eight separate integers, a hex IPv6 address is returned"""
    if len(args) == 8:
        for i in args:
            if i >= 65535:
                raise Exception(r'One of the integers is larger than 65535!')
        return r':'.join(r'{:02x}'.format(i) for i in args)
    raise ValueError(r'The data must have eight groups of integers.')


def lst2ipv6(_list: list) -> str:
    """When given eight separate integers, a hex IPv6 address is returned"""
    if len(_list) == 8:
        for i in _list:
            if i >= 65535:
                raise Exception(r'One of the integers is larger than 65535!')
        return r':'.join(r'{:02x}'.format(i) for i in _list)
    raise ValueError(r'The data must have eight groups of integers.')


# MISCELLANEOUS #


def name2ip(_address: str = r'localhost') -> str:
    """Convert a domain name to an IPv4 address"""
    return gethostbyname(_address)


def isdomain(_address: str) -> bool:
    """Test if a Domain Name resolves to an IP address"""
    try:
        gethostbyname(_address)
    except gaierror:
        return False
    return True


def ping(_address: str = r'localhost') -> bool:
    """Specify an IP address or a domain name"""
    try:
        child = Popen([r'ping', r'-c 1', _address], stdout=PIPE, stderr=PIPE, shell=False)  # nosec
        _results = child.communicate(timeout=3)[0]  # Wait for results and get return code
    except TimeoutExpired:
        return False
    return True if _results and child.returncode == 0 else False


def findgw() -> str:
    """Get the Gateway IP address"""
    with open(r'/proc/net/route', mode=r'rt', encoding=r'utf-8') as _file:
        for _line in _file:
            _field = _line.strip().split()
            if _field[1] != r'00000000' or not int(_field[3], 16) & 2:
                continue
            return inet_ntoa(pack(r'<L', int(_field[2], 16)))
    return r''


def hasnet() -> bool:
    """Return True if the Internet is available

    >>> hasnet()
    True
    """
    if urlopen(r'http://google.com').getcode() == 200:  # type: ignore  # nosec
        return True
    if urlopen(r'https://www.wikipedia.org').getcode() == 200:  # type: ignore  # nosec
        return True
    if urlopen(r'https://docs.python.org').getcode() == 200:  # type: ignore  # nosec
        return True
    return False


def getwebpage(_address: str) -> bytes:
    """Return a webpage's HTML code as a string"""
    if r'://' not in _address:
        _address = r'https://' + _address
    if not _address.endswith(r'/'):
        _address += r'/'
    return urlopen(_address).read()  # nosec

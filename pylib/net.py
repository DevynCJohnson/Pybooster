#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Network-related functions.

@file net.py
@package pybooster.net
@version 2020.02.07
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
    # CONSTANTS #
    r'SCHEME_PORT_MAP',
    r'NETLOC_SCHEMES',
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


# CONSTANTS #


SCHEME_PORT_MAP: dict = {
    r'acap': 674,
    r'afp': 548,
    r'dict': 2628,
    r'dns': 53,
    r'file': None,
    r'ftp': 21,
    r'git': 9418,
    r'gopher': 70,
    r'http': 80,
    r'https': 443,
    r'imap': 143,
    r'ipp': 631,
    r'ipps': 631,
    r'irc': 194,
    r'ircs': 6697,
    r'ldap': 389,
    r'ldaps': 636,
    r'mms': 1755,
    r'msrp': 2855,
    r'msrps': None,
    r'mtqp': 1038,
    r'nfs': 111,
    r'nntp': 119,
    r'nntps': 563,
    r'pop': 110,
    r'prospero': 1525,
    r'redis': 6379,
    r'rsync': 873,
    r'rtsp': 554,
    r'rtsps': 322,
    r'rtspu': 5005,
    r'sftp': 22,
    r'smb': 445,
    r'snmp': 161,
    r'ssh': 22,
    r'steam': None,
    r'svn': 3690,
    r'telnet': 23,
    r'ventrilo': 3784,
    r'vnc': 5900,
    r'wais': 210,
    r'ws': 80,
    r'wss': 443,
    r'xmpp': None
}


NETLOC_SCHEMES: set = {r'about', r'bitcoin', r'blob', r'data', r'geo', r'magnet', r'mailto', r'news', r'pkcs11', r'sip', r'sips', r'tel', r'urn'}


# IPV4/6 CONVERTIONS #


def ints2ipv6(*args: int) -> str:
    """When given eight separate integers, a hex IPv6 address is returned."""
    if len(args) == 8:
        for i in args:
            if i >= 65535:
                raise Exception(r'One of the integers is larger than 65535!')
        return r':'.join(fr'{i:02x}' for i in args)
    raise ValueError(r'The data must have eight groups of integers.')


def lst2ipv6(_list: list) -> str:
    """When given eight separate integers, a hex IPv6 address is returned."""
    if len(_list) == 8:
        for i in _list:
            if i >= 65535:
                raise Exception(r'One of the integers is larger than 65535!')
        return r':'.join(fr'{i:02x}' for i in _list)
    raise ValueError(r'The data must have eight groups of integers.')


# MISCELLANEOUS #


def name2ip(_address: str = r'localhost') -> str:
    """Convert a domain name to an IPv4 address."""
    return gethostbyname(_address)


def isdomain(_address: str) -> bool:
    """Test if a Domain Name resolves to an IP address."""
    try:
        gethostbyname(_address)
    except gaierror:
        return False
    return True


def ping(_address: str = r'localhost') -> bool:
    """Specify an IP address or a domain name."""
    try:
        child = Popen([r'ping', r'-c 1', _address], stdout=PIPE, stderr=PIPE, shell=False)  # nosec
        _results = child.communicate(timeout=3)[0]  # Wait for results and get return code
    except TimeoutExpired:
        return False
    return bool(_results and child.returncode == 0)


def findgw() -> str:
    """Get the Gateway IP address."""
    with open(r'/proc/net/route', mode=r'rt', encoding=r'utf-8') as _file:
        for _line in _file:
            _field = _line.strip().split()
            if _field[1] != r'00000000' or not int(_field[3], 16) & 2:
                continue
            return inet_ntoa(pack(r'<L', int(_field[2], 16)))
    return r''


def hasnet() -> bool:
    """Return True if the Internet is available.

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
    """Return a webpage's HTML code as a string."""
    if r'://' not in _address:
        _address = r'https://' + _address
    if not _address.endswith(r'/'):
        _address += r'/'
    return urlopen(_address).read()  # nosec

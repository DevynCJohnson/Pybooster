#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
Created by Devyn Collier Johnson
<DevynCJohnson@Gmail.com>
LGPLv3 License
-- --
PyBooster - Various Extras for Python3
pybooster.unix
-- --
Miscellaneous functions specific to Unix systems
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

from os import statvfs
from os.path import expanduser
from shutil import rmtree


__all__ = [
    # SPACE/STORAGE
    'dt',
    'df',
    'du',
    # MISC FUNCTIONS
    'getetcfstab',
    'getetchosts',
    'thumbnail_cleaner',
]

__author__ = 'Devyn Collier Johnson'
__copyright__ = 'LGPLv3'
__version__ = '2016.03.09'


# SPACE/STORAGE


def dt() -> float:
    """Return total disk space of current filesystem
    The returned value is a float of metric gigabytes (GB)
    """
    _disk = statvfs('/')
    total = _disk.f_blocks * _disk.f_frsize
    return round(total * 0.000000001, 3)


def df() -> float:
    """Return free disk space of current filesystem
    The returned value is a float of metric gigabytes (GB)
    """
    _disk = statvfs('/')
    free = _disk.f_bavail * _disk.f_frsize
    return round(free * 0.000000001, 3)


def du() -> float:
    """Return used disk space of current filesystem
    The returned value is a float of metric gigabytes (GB)
    """
    _disk = statvfs('/')
    used = (_disk.f_blocks - _disk.f_bfree) * _disk.f_frsize
    return round(used * 0.000000001, 3)


# MISC FUNCTIONS


def getetcfstab() -> str:
    """Get the contents of /etc/fstab"""
    _out = []
    with open('/etc/fstab', mode='rt', encoding='utf-8') as _file:
        _out.append(''.join(_file.readlines()).strip())
    return ''.join(_out)


def getetchosts() -> str:
    """Get the contents of /etc/hosts"""
    _out = []
    with open('/etc/hosts', mode='rt', encoding='utf-8') as _file:
        _out.append(''.join(_file.readlines()).strip())
    return ''.join(_out)


def thumbnail_cleaner() -> None:
    """Delete thumbnails from the user's home folder"""
    try:
        rmtree(expanduser('~/.thumbnails'))
        rmtree(expanduser('~/.cache/thumbnails'))
    except OSError as _err:
        print('Error: {} - {}.'.format(_err.filename, _err.strerror))
    except Exception:
        return None
    return None

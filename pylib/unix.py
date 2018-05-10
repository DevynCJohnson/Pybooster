#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Miscellaneous functions specific to Unix systems

@file unix.py
@package pybooster.unix
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


from os import statvfs
from os.path import expanduser
from shutil import rmtree
from sys import stderr


__all__ = [
    # SPACE/STORAGE #
    r'dt',
    r'df',
    r'du',
    # MISCELLANEOUS FUNCTIONS #
    r'getetcfstab',
    r'getetchosts',
    r'thumbnail_cleaner'
]


# SPACE/STORAGE #


def dt() -> float:  # pylint: disable=C0103
    """Return total disk space of current filesystem

    The returned value is a float of metric gigabytes (GB)
    """
    _disk = statvfs(r'/')
    total = _disk.f_blocks * _disk.f_frsize
    return round(total * 0.000000001, 3)


def df() -> float:  # pylint: disable=C0103
    """Return free disk space of current filesystem

    The returned value is a float of metric gigabytes (GB)
    """
    _disk = statvfs(r'/')
    free = _disk.f_bavail * _disk.f_frsize
    return round(free * 0.000000001, 3)


def du() -> float:  # pylint: disable=C0103
    """Return used disk space of current filesystem

    The returned value is a float of metric gigabytes (GB)
    """
    _disk = statvfs(r'/')
    used = (_disk.f_blocks - _disk.f_bfree) * _disk.f_frsize
    return round(used * 0.000000001, 3)


# MISCELLANEOUS FUNCTIONS #


def getetcfstab() -> str:
    """Get the contents of /etc/fstab"""
    _out = []
    with open(r'/etc/fstab', mode=r'rt', encoding=r'utf-8') as _file:
        _out.append(r''.join(_file.readlines()).strip())
    return r''.join(_out)


def getetchosts() -> str:
    """Get the contents of /etc/hosts"""
    _out = []
    with open(r'/etc/hosts', mode=r'rt', encoding=r'utf-8') as _file:
        _out.append(r''.join(_file.readlines()).strip())
    return r''.join(_out)


def thumbnail_cleaner() -> None:
    """Delete thumbnails from the user's home folder"""
    try:
        rmtree(expanduser(r'~/.thumbnails'))
        rmtree(expanduser(r'~/.cache/thumbnails'))
    except OSError as _err:
        stderr.write('Error: {} - {}\n'.format(_err.filename, _err.strerror))
    except RuntimeError:
        return None
    return None
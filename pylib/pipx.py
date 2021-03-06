#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief PIP Extras.

@file pipx.py
@package pybooster.pipx
@version 2019.12.23
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
along with this softwa
"""


from subprocess import getoutput  # nosec

from pip._internal import main as pipmain

try:  # Regular Expression module
    from regex import MULTILINE, sub
except ImportError:
    from re import MULTILINE, sub


__all__: list = [
    r'install',
    r'uninstall',
    r'listinstalled',
    r'listoutdated',
    r'listcurrent',
    r'numpkg',
    r'pkginfo',
    r'pkgsearch'
]


def install(package: str) -> int:
    """Install PIP package."""
    return pipmain([r'install', package])  # pylint: disable=E1102


def uninstall(package: str) -> int:
    """Uninstall a PIP package."""
    return pipmain([r'uninstall', package])  # pylint: disable=E1102


def listinstalled() -> str:
    """List installed PIP packages."""
    return getoutput(r'pip list')


def listoutdated() -> str:
    """List outdated PIP packages."""
    results = sub(r'Could not(.+)\n', r'', getoutput(r'pip list -o'), flags=MULTILINE)
    results = sub(r'Some externally hosted files(.+)\n', r'', results, flags=MULTILINE)
    return results


def listcurrent() -> str:
    """List up-to-dated PIP packages."""
    results = sub(r'Could not(.+)\n', r'', getoutput(r'pip list -u'), flags=MULTILINE)
    results = sub(r'Some externally hosted files(.+)\n', r'', results, flags=MULTILINE)
    return results


def numpkg() -> int:
    """Return the number of installed PIP packages."""
    results = getoutput(r'pip list')
    return len(results.split('\n'))


def pkginfo(package: str) -> str:
    """Display package info."""
    return getoutput(r'pip show ' + package)


def pkgsearch(keyword: str) -> str:
    """Search the database by keyword."""
    return getoutput(r'pip search ' + keyword)

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
Created by Devyn Collier Johnson
<DevynCJohnson@Gmail.com>
LGPLv3 License
-- --
PyBooster - Various Extras for Python3
pybooster.pipx
-- --
PIP Extras
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

import re
import subprocess

import pip


__all__ = [
    'install',
    'uninstall',
    'listinstalled',
    'listoutdated',
    'listcurrent',
    'pkginfo',
    'pkgsearch',
    'numpkg',
]

__author__ = 'Devyn Collier Johnson'
__copyright__ = 'LGPLv3'
__version__ = '2016.03.09'


def install(package) -> int:
    """Install PIP package"""
    return pip.main(['install', package])


def uninstall(package) -> int:
    """Uninstall a PIP package"""
    return pip.main(['uninstall', package])


def listinstalled() -> str:
    """List installed PIP packages"""
    return subprocess.getoutput('pip list')


def listoutdated() -> str:
    """List outdated PIP packages"""
    results = subprocess.getoutput('pip list -o')
    results = re.sub(r'Could not(.+)\n', '', results, flags=re.M)
    results = re.sub(r'Some externally hosted files(.+)\n', '', results, flags=re.M)
    return results


def listcurrent() -> str:
    """List up-to-dated PIP packages"""
    results = subprocess.getoutput('pip list -u')
    results = re.sub(r'Could not(.+)\n', '', results, flags=re.M)
    results = re.sub(r'Some externally hosted files(.+)\n', '', results, flags=re.M)
    return results


def pkginfo(package) -> str:
    """Display package info"""
    return subprocess.getoutput('pip show ' + package)


def pkgsearch(keyword) -> str:
    """Search the database by keyword"""
    return subprocess.getoutput('pip search ' + keyword)


def numpkg() -> int:
    """Return the number of installed PIP packages"""
    results = subprocess.getoutput('pip list')
    results = results.split('\n')
    return len(results)

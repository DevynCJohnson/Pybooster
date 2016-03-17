#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
Created by Devyn Collier Johnson
<DevynCJohnson@Gmail.com>
LGPLv3 License
-- --
PyBooster - Various Extras for Python3
pybooster.clibutil
-- --
Interface for system libraries via ctypes (mostly for Unixoid systems)
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

from ctypes import CDLL, cdll, util
from os.path import isfile
from re import findall
from subprocess import getoutput


__all__ = [
    # GET LIBRARY FILE NAMES
    'getlibc',
    'getlibm',
    # LIST LIBRARY OBJECTS
    'list_elf_lib_funcs',
    'list_elf_lib_consts',
    'list_elf_lib_objs',
    # LOAD LIBRARIES
    'loadlib',
    'loadlibpath',
    'loadlibc',
    'loadlibm',
]

__author__ = 'Devyn Collier Johnson'
__copyright__ = 'LGPLv3'
__version__ = '2016.03.09'


# GET LIBRARY FILE NAMES


def getlibc() -> str:
    """Return the file name of libc"""
    return util.find_library('c')


def getlibm() -> str:
    """Return the file name of libm"""
    return util.find_library('m')


# LIST LIBRARY OBJECTS


def list_elf_lib_funcs(libfile_path: str) -> list:
    """Return a list of functions in a shared ELF library
    Requires 'nm'
    """
    if isfile(libfile_path):
        libobj = getoutput('nm -D --defined-only ' + libfile_path)
        objs = findall('([a-f0-9]+) T (?!_)(.+)', libobj)
        lst = []
        for i in objs:
            lst.append(i[1])
        return lst
    else:
        raise FileNotFoundError('Library file (' + libfile_path + ') not found!')


def list_elf_lib_consts(libfile_path: str) -> list:
    """Return a list of non-static constants in a shared ELF library
    Requires 'nm'
    """
    if isfile(libfile_path):
        libobj = getoutput('nm -D --defined-only ' + libfile_path)
        objs = findall('([a-f0-9]+) R (?!_)(.+)', libobj)
        lst = []
        for i in objs:
            lst.append(i[1])
        return lst
    else:
        raise FileNotFoundError('Library file (' + libfile_path + ') not found!')


def list_elf_lib_objs(libfile_path: str) -> list:
    """Return a list of functions and non-static constants in a shared ELF library
    Requires 'nm'"""
    if isfile(libfile_path):
        libobj = getoutput('nm -D --defined-only ' + libfile_path)
        objs = findall('([a-f0-9]+) ([RT]+) (?!_)(.+)', libobj)
        lst = []
        for i in objs:
            lst.append(i[2])
        return lst
    else:
        raise FileNotFoundError('Library file (' + libfile_path + ') not found!')


# LOAD LIBRARIES


def loadlib(library: str) -> CDLL:
    """Load the specified library by name
    Usage: library = loadlib('m')
    """
    if library[:3] == 'lib':
        library = library[3:]
    return cdll.LoadLibrary(util.find_library(library))


def loadlibpath(libpath: str) -> CDLL:
    """Load the specified library by pathname
    Usage: library = loadlibpath('/DIR/libFILE.so')
    """
    return cdll.LoadLibrary(libpath)


def loadlibc() -> CDLL:
    """Load libc
    Usage: libc = loadlibc()
    """
    return cdll.LoadLibrary(util.find_library('c'))


def loadlibm() -> CDLL:
    """Load libm (Math)
    Usage: libm = loadlibm()
    """
    return cdll.LoadLibrary(util.find_library('m'))

#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Interface for system libraries via ctypes (mostly for Unixoid systems)

@file clibutil.py
@package pybooster.clibutil
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


from ctypes import CDLL, cdll, util
from os.path import isfile
from subprocess import getoutput  # nosec
from typing import Optional

try:  # Regular Expression module
    from regex import findall
except ImportError:
    from re import findall


__all__: list = [
    # GET LIBRARY FILE NAMES #
    r'getlibc',
    r'getlibm',
    # LIST LIBRARY OBJECTS #
    r'list_elf_lib_funcs',
    r'list_elf_lib_consts',
    r'list_elf_lib_objs',
    # LOAD LIBRARIES #
    r'loadlib',
    r'loadlibpath',
    r'loadlibc',
    r'loadlibm'
]


# GET LIBRARY FILE NAMES #


def getlibc() -> Optional[str]:
    """Return the file name of libc"""
    return util.find_library(r'c')


def getlibm() -> Optional[str]:
    """Return the file name of libm"""
    return util.find_library(r'm')


# LIST LIBRARY OBJECTS #


def list_elf_lib_funcs(libfile_path: str) -> list:
    """Return a list of functions in a shared ELF library; Requires 'nm'"""
    if isfile(libfile_path):
        libobj: str = getoutput(r'nm -D --defined-only ' + libfile_path)
        objs = findall('([a-f0-9]+) T (?!_)(.+)', libobj)
        return [i[1] for i in objs]
    raise FileNotFoundError(r'Library file (' + libfile_path + r') not found!')


def list_elf_lib_consts(libfile_path: str) -> list:
    """Return a list of non-static constants in a shared ELF library; Requires 'nm'"""
    if isfile(libfile_path):
        libobj = getoutput(r'nm -D --defined-only ' + libfile_path)
        objs = findall('([a-f0-9]+) R (?!_)(.+)', libobj)
        return [i[1] for i in objs]
    raise FileNotFoundError(r'Library file (' + libfile_path + r') not found!')


def list_elf_lib_objs(libfile_path: str) -> list:
    """Return a list of functions and non-static constants in a shared ELF library; Requires 'nm'"""
    if isfile(libfile_path):
        libobj = getoutput(r'nm -D --defined-only ' + libfile_path)
        objs = findall('([a-f0-9]+) ([RT]+) (?!_)(.+)', libobj)
        return [i[2] for i in objs]
    raise FileNotFoundError(r'Library file (' + libfile_path + r') not found!')


# LOAD LIBRARIES #


def loadlib(library: str) -> CDLL:
    """Load the specified library by name

    Usage: library = loadlib('m')
    """
    if library[:3] == r'lib':
        library = library[3:]
    return cdll.LoadLibrary(util.find_library(library))  # type: ignore


def loadlibpath(libpath: str) -> CDLL:
    """Load the specified library by pathname

    Usage: library = loadlibpath('/DIR/libFILE.so')
    """
    return cdll.LoadLibrary(libpath)


def loadlibc() -> CDLL:
    """Load libc

    Usage: libc = loadlibc()
    """
    return cdll.LoadLibrary(util.find_library(r'c'))  # type: ignore


def loadlibm() -> CDLL:
    """Load libm (Math)

    Usage: libm = loadlibm()
    """
    return cdll.LoadLibrary(util.find_library(r'm'))  # type: ignore

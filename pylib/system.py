#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief System-related functions

@file system.py
@package pybooster.system
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


import platform
from os import X_OK, access, environ, kill as _kill, path, pathsep
from signal import SIGKILL
from struct import Struct
from sys import byteorder as _byteorder, maxsize, platform as _platform, stdout

try:
    from ctypes.windll import kernel32
except ImportError:
    pass


__all__ = [
    # CONSTANTS #
    r'HOME',
    r'ENVKEY',
    # HOME-RELATED FUNCTIONS #
    r'home',
    # ENVIRONMENT-RELATED FUNCTIONS #
    r'envdict',
    r'envlist',
    r'printenv',
    # PROCESS-RELATED FUNCTION #
    r'isthread',
    r'ckill',
    # MACHINE-RELATED FUNCTION #
    r'bitness',
    r'cintsize',
    # SYSTEM INFO #
    r'idsys',
    # MISCELLANEOUS SYSTEM FUNCTIONS #
    r'which'
]


# CONSTANTS #


HOME = path.expanduser(r'~')
ENVKEY = dict(environ)


# HOME-RELATED FUNCTIONS #


def home() -> str:
    """Return user's home directory as a string

    >>> home()
    '/home/collier'
    """
    return path.expanduser(r'~')


# ENVIRONMENT-RELATED FUNCTIONS #


def envdict() -> dict:
    """Return the system's environment variables

    A dictionary is returned in the form { 'VAR': 'VAL'}
    """
    return dict(environ)


def envlist() -> list:
    """Return a list of the system's environment variables"""
    sysenv = []
    for k, v in zip(environ.keys(), environ.values()):
        sysenv.append(k + r'=' + v)
    return sysenv


def printenv() -> None:
    """Print the system's environment variables"""
    for k, v in zip(environ.keys(), environ.values()):
        stdout.write('{}={}\n'.format(k, v))
    return None


# PROCESS-RELATED FUNCTION #


def isthread(_thead) -> bool:
    """Test if object is a thread, or if the thread is alive/present"""
    return True if hasattr(_thead, r'is_alive') else False


def ckill(_process) -> None:
    """Cross-platform Kill

    Kill process specified by process-object or PID
    ckill(PID)
    ckill(process-obj)
    """
    if _platform == r'win32':
        _handle = kernel32.OpenProcess(1, False, _process.pid)
        kernel32.TerminateProcess(_handle, -1)
        kernel32.CloseHandle(_handle)
    else:
        try:
            _kill(_process, SIGKILL)
        except OSError:
            _kill(_process.pid, SIGKILL)
    return None


# MACHINE-RELATED FUNCTIONS #


def bitness() -> str:
    """Return a string indicating the bitness of the system

    >>> bitness()
    '64'
    """
    if maxsize == 32767:  # 2 ** 15 - 1
        return r'16'
    elif maxsize == 2147483647:  # 2 ** 31 - 1
        return r'32'
    elif maxsize == 9223372036854775807:  # 2 ** 63 - 1
        return r'64'
    elif maxsize == 170141183460469231731687303715884105727:  # 2 ** 127 - 1
        return r'128'
    return 'Unknown'


def cintsize() -> int:
    """Return the C/C++ size of an int for the current system

    The returned value is an integer for the number of bytes

    >>> cintsize()
    4
    """
    return Struct(r'i').size


# SYSTEM INFO #


def idsys() -> None:
    """Identify system and display specific info"""
    def _spinfo() -> None or str:
        """Specific system info"""
        _platsys = platform.system().lower()
        if _platsys == r'windows':
            return platform.win32_ver()
        elif _platsys == r'linux':
            return _platsys
        elif _platsys == r'java':
            return platform.java_ver()
        elif _platsys in (r'darwin', r'mac', r'osx', r'macosx'):
            return platform.mac_ver()
        return None
    stdout.write(
        'Byteorder:          {}\n'
        'System Name:        {}\n'
        'System Release:     {}\n'
        'Release Version:    {}\n'
        'Release Info:       {}\n'
        'Platform:           {}\n'
        'Machine Type:       {}\n'
        'Processor Name:     {}\n'
        'HostName:           {}\n'
        'Implementation:     {}\n'
        'Python Version:     {}\n'
        .format(
            _byteorder,
            platform.system(),
            platform.release(),
            platform.version(),
            _spinfo(),
            platform.platform(),
            platform.machine(),
            platform.processor(),
            platform.node(),
            platform.python_implementation(),
            platform.python_version()
        )
    )
    return None


# MISCELLANEOUS SYSTEM FUNCTIONS #


def which(program: str) -> str:
    """Return the path of the specified application (if it exists)

    An empty string is returned if the program does not exist
    """
    fpath = path.split(program)[0]
    if fpath and path.isfile(program) and access(program, X_OK):
        return program
    envpath = environ[r'PATH'].split(pathsep)
    for filepath in envpath:
        exe_file = path.join(filepath.strip(r'"'), program)
        if path.isfile(exe_file) and access(exe_file, X_OK):
            return exe_file
    return r''
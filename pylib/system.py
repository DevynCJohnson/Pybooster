#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief System-related functions.

@file system.py
@package pybooster.system
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


__all__: list = [
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
    r'which',
    r'is_program_aval'
]


# CONSTANTS #


HOME = path.expanduser(r'~')
ENVKEY = dict(environ)


# HOME-RELATED FUNCTIONS #


def home() -> str:
    """Return user's home directory as a string.

    >>> home()
    '/home/collier'
    """
    return path.expanduser(r'~')


# ENVIRONMENT-RELATED FUNCTIONS #


def envdict() -> dict:
    """Return the system's environment variables.

    A dictionary is returned in the form { 'VAR': 'VAL'}
    """
    return dict(environ)


def envlist() -> list:
    """Return a list of the system's environment variables."""
    return [k + r'=' + v for k, v in zip(environ.keys(), environ.values())]


def printenv() -> None:
    """Print the system's environment variables."""
    for k, v in zip(environ.keys(), environ.values()):
        stdout.write(f'{k}={v}\n')


# PROCESS-RELATED FUNCTION #


def isthread(_thead) -> bool:
    """Test if object is a thread, or if the thread is alive/present."""
    return bool(hasattr(_thead, r'is_alive'))


def ckill(_process) -> None:
    """Cross-platform Kill.

    Kill process specified by process-object or PID
    ckill(PID)
    ckill(process-obj)
    """
    if _platform == r'win32':
        _handle = kernel32.OpenProcess(1, False, _process.pid)
        kernel32.TerminateProcess(_handle, -1)
        kernel32.CloseHandle(_handle)
        return
    try:
        _kill(_process, SIGKILL)
    except OSError:
        _kill(_process.pid, SIGKILL)


# MACHINE-RELATED FUNCTIONS #


def bitness() -> str:
    """Return a string indicating the bitness of the system.

    >>> bitness()
    '64'
    """
    if maxsize == 32767:  # 2 ** 15 - 1
        return r'16'
    if maxsize == 2147483647:  # 2 ** 31 - 1
        return r'32'
    if maxsize == 9223372036854775807:  # 2 ** 63 - 1
        return r'64'
    if maxsize == 170141183460469231731687303715884105727:  # 2 ** 127 - 1
        return r'128'
    return 'Unknown'


def cintsize() -> int:
    """Return the C/C++ size of an int for the current system.

    The returned value is an integer for the number of bytes

    >>> cintsize()
    4
    """
    return Struct(r'i').size


# SYSTEM INFO #


def idsys() -> None:
    """Identify system and display specific info."""
    stdout.write(
        'Byteorder:          {}\n'
        'System Name:        {}\n'
        'System Release:     {}\n'
        'Release Version:    {}\n'
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
            platform.platform(),
            platform.machine(),
            platform.processor(),
            platform.node(),
            platform.python_implementation(),
            platform.python_version()
        )
    )


# MISCELLANEOUS SYSTEM FUNCTIONS #


def which(program: str) -> str:
    """Return the path of the specified application (if it exists).

    An empty string is returned if the program does not exist
    """
    if path.split(program)[0] and path.isfile(program) and access(program, X_OK):
        return program
    envpath: list = environ[r'PATH'].split(pathsep)
    for filepath in envpath:
        exe_file = path.join(filepath.strip(r'"'), program)
        if path.isfile(exe_file) and access(exe_file, X_OK):
            return exe_file
    return r''


def is_program_aval(program: str) -> bool:
    """Return `True` if the path of the specified application exists, otherwise, return `False`."""
    if path.split(program)[0] and path.isfile(program) and access(program, X_OK):
        return True
    envpath: list = environ[r'PATH'].split(pathsep)
    for filepath in envpath:
        exe_file = path.join(filepath.strip(r'"'), program)
        if path.isfile(exe_file) and access(exe_file, X_OK):
            return True
    return False

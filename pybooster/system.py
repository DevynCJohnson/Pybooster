#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""@brief System-related functions
@file system.py
@package pybooster.system
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@version 2016.03.20

@section LICENSE
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


import platform

from os import X_OK, access, environ, kill as _kill, path, pathsep
from signal import SIGKILL
from struct import Struct
from sys import byteorder as _byteorder, maxsize, platform as _platform

try:
    from ctypes.windll import kernel32
except ImportError:
    pass


__all__ = [
    # CONSTANTS
    'HOME',
    'ENVKEY',
    # HOME-RELATED FUNCTIONS
    'home',
    # ENVIRONMENT-RELATED FUNCTIONS
    'envdict',
    'envlist',
    'printenv',
    # PROCESS-RELATED FUNCTION
    'isthread',
    'ckill',
    # MACHINE-RELATED FUNCTION
    'bitness',
    'cintsize',
    # SYSTEM INFO
    'idsys',
    # MISCELLANEOUS
    'which',
]


# CONSTANTS


HOME = path.expanduser(r'~')
ENVKEY = dict(environ)


# HOME-RELATED FUNCTIONS


def home() -> str:
    """Return user's home directory as a string"""
    return path.expanduser(r'~')


# ENVIRONMENT-RELATED FUNCTIONS


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
        print(k, r'=', v)  # noqa
    return None


# PROCESS-RELATED FUNCTION


def isthread(_thead) -> bool:
    """Test if object is a thread, or if the thread is alive/present"""
    if hasattr(_thead, 'is_alive'):
        return True
    return False


def ckill(_process) -> None:
    """Cross-platform Kill

    Kill process specified by process-object or PID
    ckill(PID)
    ckill(process-obj)
    """
    if _platform == 'win32':
        _handle = kernel32.OpenProcess(1, False, _process.pid)
        kernel32.TerminateProcess(_handle, -1)
        kernel32.CloseHandle(_handle)
    else:
        try:
            _kill(_process, SIGKILL)
        except Exception:  # pylint: disable=W0703
            _kill(_process.pid, SIGKILL)
    return None


# MACHINE-RELATED FUNCTIONS


def bitness() -> str:
    """Return a string indicating the bitness of the system"""
    if maxsize == 32767:  # 2 ** 15 - 1
        return r'16'
    elif maxsize == 2147483647:  # 2 ** 31 - 1
        return r'32'
    elif maxsize == 9223372036854775807:  # 2 ** 63 - 1
        return r'64'
    elif maxsize == 170141183460469231731687303715884105727:  # 2 ** 127 - 1
        return r'128'
    else:
        return 'Unknown'


def cintsize() -> int:
    """Return the C/C++ size of an int for the current system

    The returned value is an integer for the number of bytes
    cintsize() => 4  # The system uses 4 bytes for integers
    """
    return Struct('i').size


# SYSTEM INFO


def idsys() -> None:
    """Identify system and display specific info"""
    def _spinfo():
        """Specific system info"""
        _platsys = platform.system().lower()
        if _platsys == 'windows':
            return platform.win32_ver()
        elif _platsys == 'linux':
            return platform.linux_distribution() + platform.libc_ver()
        elif _platsys == 'java':
            return platform.java_ver()
        elif _platsys in ('darwin', 'mac', 'osx', 'macosx'):
            return platform.mac_ver()
        else:
            return None
    print(  # noqa
        'Byteorder:          {}\n'
        'System Name:        {}\n'
        'System Release:     {}\n'
        'Release Version:    {}\n'
        'Release Info:       {}\n'
        'Distro:             {}\n'
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
            platform.dist(),
            platform.platform(),
            platform.machine(),
            platform.processor(),
            platform.node(),
            platform.python_implementation(),
            platform.python_version(),
        )
    )
    return None


# MISCELLANEOUS


def which(program: str) -> str:
    """Return the path of the specified application (if it exists)

    An empty string is returned if the program does not exist
    """
    fpath = path.split(program)[0]
    if fpath and path.isfile(program) and access(program, X_OK):
        return program
    else:
        envpath = environ['PATH'].split(pathsep)
        for filepath in envpath:
            exe_file = path.join(filepath.strip('"'), program)
            if path.isfile(exe_file) and access(exe_file, X_OK):
                return exe_file
    return ''

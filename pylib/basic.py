#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Miscellaneous functions for most uses

@file basic.py
@package pybooster.basic
@version 2018.11.11
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


from inspect import currentframe
from os.path import dirname
from sys import modules, stdout
from types import ModuleType


try:  # Regular Expression module
    from regex import IGNORECASE, fullmatch as refullmatch
except ImportError:
    from re import IGNORECASE, fullmatch as refullmatch


__all__: list = [
    # MODULES & IMPORTS #
    r'lsmods',
    r'imports',
    r'imported',
    r'wheremods',
    r'wherecurmods',
    r'modpath',
    r'modexist',
    r'rmmod',
    # MISCELLANEOUS #
    r'execfile',
    r'clearscr',
    r'pygrep',
    r'ipygrep',
    r'getlinenum',
    r'ezcompile',
    r'wlong',
    r'int2bitlen',
    r'char2bitlen'
]


# CLASSES #


class SameFileError(Exception):  # pylint: disable=W0612
    """Raised when source and target are the same file"""

    def __init__(self, msg: str = r'The source and target file are the same.') -> None:
        """Initialize exception"""
        super(SameFileError, self).__init__(msg)
        self.msg = msg

    def __str__(self) -> str:
        """Exception's string message"""
        return repr(self.msg)


class ObjectError(NameError, TypeError, ValueError):  # pylint: disable=W0612
    """Raised when an object cannot be found, used, or manipulated"""

    def __init__(self, msg: str = r'The object is malformed.') -> None:
        """Initialize exception"""
        super(ObjectError, self).__init__(msg)
        self.msg = msg

    def __str__(self) -> str:
        """Exception's string message"""
        return repr(self.msg)


class NullException(BaseException):
    """Null Exception"""

    pass


# MODULES & IMPORTS #


def lsmods() -> list:
    """List loaded modules"""
    return list(modules.keys())


def imports() -> list:
    """List all imports"""
    _imports: list = []
    for name, val in globals().items():  # pylint: disable=W0612
        if isinstance(val, ModuleType):
            _imports.append(val.__name__)
    return _imports


def imported() -> list:
    """List imports that are in 'modules' and 'globals()'"""
    return list(set(modules) & set(globals()))


def wheremods() -> list:
    """List locations of imported modules"""
    _loadedmods = set(modules) & set(globals())
    return [modules[name] for name in _loadedmods]


def wherecurmods() -> list:
    """List locations of current/present modules"""
    return [modules[name] for name in set(modules)]


def modpath(module) -> str:
    """Output module's file pathname"""
    try:
        return dirname(module.__file__)
    except AttributeError:
        raise RuntimeError(r'No module found. The module may be builtin or nonexistent.')


def modexist(_module: str) -> bool:
    """Test if module exists on system"""
    if not isinstance(_module, str):
        raise Exception('modexist() only accepts strings - modexist(\'_module\')')
    _tmp = None
    try:
        _tmp = __import__(_module)
    except ImportError:
        return False
    else:
        return True
    finally:
        del _tmp
        del _module


def rmmod(_modname: str) -> None:
    """Remove module from the running instance"""
    if not isinstance(_modname, str):
        raise Exception('rm_mod() only accepts strings - rm_mod(\'_modname\')')
    try:
        modules[_modname]
    except KeyError:
        raise ValueError(_modname)
    del modules[_modname]
    for mod in modules.values():
        try:
            delattr(mod, _modname)
        except AttributeError:
            pass


# MISCELLANEOUS #


def execfile(_filename: str) -> object:
    """Execute Python script and get output"""
    with open(_filename, mode=r'rt', encoding=r'utf-8') as _file:
        return exec(_file.read())  # nosec  # pylint: disable=W0122


def clearscr() -> None:
    """Clear Terminal"""
    stdout.write('\n' * 70)


def ipygrep(_find: str, _text: str) -> bool:
    """Case-insensitive reverse REGEX search

    Test if a plain-string matches a regex string
    """
    _match = refullmatch(_find, _text, flags=IGNORECASE)
    if _match is not None:
        return _match
    return False


def pygrep(_find: str, _text: str) -> bool:
    """Case-sensitive reverse REGEX search; Test if a plain-string matches a regex string"""
    _match = refullmatch(_find, _text, flags=None)
    if _match is not None:
        return _match
    return False


def getlinenum() -> int:
    """Return the script's line number where this method executes"""
    return currentframe().f_back.f_lineno  # type: ignore


def ezcompile(_code: str) -> object:
    """Easily compile code that is in the form of a string

    Example:
    c2 = 'x = 45 * 37; import math; y = math.cos(37); print(x); print(y)'
    bytecode = ezcompile(c2)
    exec(bytecode) # or eval(bytecode)
    """
    try:
        comcode = compile(_code, r'', r'eval')
    except SyntaxError:
        comcode = compile(_code, r'', r'exec')
    return comcode


def wlong(_int32: int) -> bytes:
    """Convert a 32-bit integer to little-endian"""
    return (int(_int32) & 0xFFFFFFFF).to_bytes(4, r'little')


def int2bitlen(_int: int) -> int:
    """Return the number of bits needed to represent an integer"""
    return _int.bit_length()


def char2bitlen(_char: str) -> int:
    """Return the number of bits needed to represent a character"""
    if len(_char) != 1:
        raise Exception(r'A string containing multiple characters was passed to char2bitlen()')
    return ord(_char).bit_length()

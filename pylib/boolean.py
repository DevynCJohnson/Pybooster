#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Boolean test functions (test a condition and return true or false)

@file boolean.py
@package pybooster.boolean
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


from ast import parse
from collections.abc import Awaitable
from os import X_OK, access, environ, pathsep
from os.path import isfile, join as joinpath, split as splitpath
from sys import modules
from typing import Iterable, Union
from types import BuiltinFunctionType, CodeType, CoroutineType, FrameType, FunctionType, GeneratorType, GetSetDescriptorType, MemberDescriptorType, MethodType, ModuleType, TracebackType


__all__: list = [
    # CONSTANTS #
    r'CO_COROUTINE',
    r'CO_GENERATOR',
    r'CO_ITERABLE_COROUTINE',
    # BOOLEAN-TEST FUNCTIONS #
    r'rmfalse',
    r'evaliter',
    r'eny',
    r'isiter',
    r'ishex',
    r'isoct',
    r'isbin',
    r'iscomplex',
    r'iscomplextype',
    r'ismodule',
    r'isclass',
    r'ismethod',
    r'ismethoddescriptor',
    r'isdatadescriptor',
    r'ismemberdescriptor',
    r'isgetsetdescriptor',
    r'isfunction',
    r'isgeneratorfunction',
    r'iscoroutinefunction',
    r'isgenerator',
    r'iscoroutine',
    r'isawaitable',
    r'istraceback',
    r'isframe',
    r'iscode',
    r'isbuiltin',
    r'isroutine',
    r'isabstract',
    r'isbetween',
    r'isdefined',
    r'ismodloaded',
    r'isfrozen',
    r'ismodfrozen',
    r'words_in_str',
    r'words_not_in_str',
    r'isexe',
    r'isinpath',
    r'isvalidcode',
    r'isintuplelist'
]


# CONSTANTS #


CO_COROUTINE: int = 128
CO_GENERATOR: int = 32
CO_ITERABLE_COROUTINE: int = 256


# BOOLEAN-TEST FUNCTIONS #


def rmfalse(_iter: Iterable) -> list:
    """Remove False values from iterable and return evaluated list"""
    return [x for x in _iter if x]


def evaliter(_iter: Iterable) -> list:
    """Evaluate values in iterable and return evaluated list of booleans"""
    return [x for x in _iter]


def eny(_iter: Iterable) -> bool:
    """Enhanced any()

    >>> eny([1, 0, 2, 'str'])
    True
    >>> eny(['str', 'x', 'y'])
    False
    >>> eny(('str', 'x', 'y'))
    False
    """
    return True in _iter


def isiter(_iter: Iterable) -> bool:
    """Test if the object is iterable

    >>> isiter('str')
    True
    >>> isiter('')
    True
    >>> isiter((0, 1))
    True
    >>> isiter(('str', [1, 2]))
    True
    >>> isiter(1)
    False
    """
    try:
        return (i for i in _iter) is not None
    except TypeError:
        return False


def ishex(_hex: str) -> bool:
    """Is the string hexadecimal

    >>> ishex('2c')
    True
    >>> ishex('0x2c')
    True
    >>> ishex('0xfFf')
    True
    >>> ishex('0001f9e6')
    True
    >>> ishex('x')
    False
    >>> ishex('0xY')
    False
    >>> ishex('STR0xff')
    False
    >>> ishex('0o7')
    False
    """
    try:
        int(_hex, 16)
        return True
    except ValueError:
        return False


def isoct(_oct: str) -> bool:
    """Is the string octal

    >>> isoct('45')
    True
    >>> isoct('0o27')
    True
    >>> isoct('0o237')
    True
    >>> isoct('x')
    False
    >>> isoct('0oY')
    False
    >>> isoct('STR0o77')
    False
    >>> isoct('0x7')
    False
    >>> isoct('0o8')
    False
    """
    try:
        int(_oct, 8)
        return True
    except ValueError:
        return False


def isbin(_bin: str) -> bool:
    """Is the string binary

    >>> isbin('01010101')
    True
    >>> isbin('0b1')
    True
    >>> isbin('0b1010')
    True
    >>> isbin('x')
    False
    >>> isbin('0bY')
    False
    >>> isbin('STR0b1100')
    False
    >>> isbin('0b7')
    False
    >>> isbin('0o10')
    False
    """
    try:
        int(_bin, 2)
        return True
    except ValueError:
        return False


def iscomplex(_obj: Union[complex, int, str]) -> bool:
    """Is the object a complex number (37+54j)

    >>> iscomplex(37+54j)
    True
    >>> iscomplex(37-54j)
    True
    >>> iscomplex(27j)
    True
    >>> iscomplex("37+54j")
    True
    >>> iscomplex('37+54j')
    True
    >>> iscomplex('37-54j')
    True
    >>> iscomplex(37+0j)
    True
    >>> iscomplex('37-54J')
    False
    >>> iscomplex(37)
    False
    >>> iscomplex('37')
    False
    """
    try:
        if _obj.__class__ is complex:
            return True
        if _obj.__class__ is int:
            return False
        if _obj.__class__ is str and r'j' in _obj and complex(_obj.replace(r' ', r'')).__class__ is complex:  # type: ignore
            return True
        return False
    except (SyntaxError, TypeError, ValueError):
        return False


def iscomplextype(_obj: object) -> bool:
    """Is the object a complex type

    >>> iscomplextype(37+54j)
    True
    >>> iscomplextype(37-54j)
    True
    >>> iscomplextype(27j)
    True
    >>> iscomplextype(-23j)
    True
    >>> iscomplextype('37+54j')
    False
    >>> iscomplextype("37+54j")
    False
    """
    return _obj.__class__ is complex


def ismodule(_object: object) -> bool:
    """Return true if the object is a module"""
    return isinstance(_object, ModuleType)


def isclass(_object: object) -> bool:
    """Return true if the object is a class"""
    return isinstance(_object, type)


def ismethod(_object: object) -> bool:
    """Return true if the object is an instance method"""
    return isinstance(_object, MethodType)


def ismethoddescriptor(_object: object) -> bool:
    """Return true if the object is a method descriptor"""
    if isinstance(_object, (FunctionType, MethodType, type)):
        return False
    objtype = type(_object)
    return hasattr(objtype, r'__get__') and not hasattr(objtype, r'__set__')


def isdatadescriptor(_object: object) -> bool:
    """Return true if the object is a data descriptor"""
    if isinstance(_object, (FunctionType, MethodType, type)):
        return False
    objtype = type(_object)
    return hasattr(objtype, r'__set__') and hasattr(objtype, r'__get__')


def ismemberdescriptor(_object: object) -> bool:
    """Return true if the object is a member descriptor"""
    return isinstance(_object, MemberDescriptorType)


def isgetsetdescriptor(_object: object) -> bool:
    """Return true if the object is a getset descriptor"""
    return isinstance(_object, GetSetDescriptorType)


def isfunction(_object: object) -> bool:
    """Return true if the object is a user-defined function"""
    return isinstance(_object, FunctionType)


def isgeneratorfunction(_object: object) -> bool:
    """Return true if the object is a user-defined generator function"""
    return bool(isinstance(_object, (FunctionType, MethodType)) and _object.__code__.co_flags & CO_GENERATOR)  # type: ignore


def iscoroutinefunction(_object: object) -> bool:
    """Return true if the object is a coroutine function"""
    return bool(isinstance(_object, (FunctionType, MethodType)) and _object.__code__.co_flags & CO_COROUTINE)  # type: ignore


def isgenerator(_object: object) -> bool:
    """Return true if the object is a generator"""
    return isinstance(_object, GeneratorType)


def iscoroutine(_object: object) -> bool:
    """Return true if the object is a coroutine"""
    return isinstance(_object, CoroutineType)


def isawaitable(_object: object) -> bool:
    """Return true if object can be passed to an `await` expression"""
    return (
        isinstance(_object, (Awaitable, CoroutineType)) or isinstance(_object, GeneratorType) and bool(_object.gi_code.co_flags & CO_ITERABLE_COROUTINE)
    )


def istraceback(_object: object) -> bool:
    """Return true if the object is a traceback"""
    return isinstance(_object, TracebackType)


def isframe(_object: object) -> bool:
    """Return true if the object is a frame object"""
    return isinstance(_object, FrameType)


def iscode(_object: object) -> bool:
    """Return true if the object is a code object"""
    return isinstance(_object, CodeType)


def isbuiltin(_object: object) -> bool:
    """Return true if the object is a built-in function or method"""
    return isinstance(_object, BuiltinFunctionType)


def isroutine(_object: object) -> bool:
    """Return true if the object is any kind of function or method"""
    return isinstance(_object, (BuiltinFunctionType, FunctionType, MethodType)) or ismethoddescriptor(_object)


def isabstract(_object: object) -> bool:
    """Return true if the object is an abstract base class (ABC)"""
    return bool(isinstance(_object, type) and _object.__flags__ & 1048576)  # type: ignore


def isbetween(_lo: Union[float, int], _hi: Union[float, int], _num: Union[float, int]) -> bool:
    """Test if a float/integer is between two other floats/integers

    >>> isbetween(2, 7, 5)
    True
    >>> isbetween(2.3, 9, 3.145149)
    True
    >>> isbetween(2.3, 9.1, 3.145149)
    True
    >>> isbetween(2, 7, 5.34)
    True
    >>> isbetween(2, 7, 13)
    False
    >>> isbetween(2, 7, 1.9)
    False
    """
    if _lo > _hi:  # type: ignore
        raise Exception(r'Invalid input for isbetween()!')
    return _lo <= _num <= _hi  # type: ignore


def isdefined(_var_name: str) -> bool:
    """Test if the named variable is defined in current scope"""
    if not isinstance(_var_name, str):
        raise Exception('isdefined() only accepts strings - isdefined(\'_var_name\')')
    return _var_name in globals() or _var_name in vars()


def ismodloaded(_module: str) -> bool:
    """Test if the named module is imported"""
    if not isinstance(_module, str):
        raise Exception('ismodloaded() only accepts strings - ismodloaded(\'_module\')')
    return _module in modules.keys()


def isfrozen() -> bool:
    """Test if the modules are built into the interpreter (As seen in py2exe)"""
    _tmp: object = None
    try:
        _tmp = __import__(r'sys')
        return hasattr(_tmp, r'frozen')
    except ImportError:
        return False
    finally:
        del _tmp


def ismodfrozen(module_name: str) -> bool:
    """Test if the specified module is frozen (built into the interpreter)"""
    _tmp: object = None
    try:
        _tmp = __import__(module_name)
        return hasattr(_tmp, r'frozen')
    except ImportError:
        return False
    finally:
        del _tmp


def words_in_str(_text: str, _wordlist: list) -> bool:
    """Test if any of the listed words are in the given string

    >>> words_in_str('This is a test.', ['test'])
    True
    >>> words_in_str('This is a test.', ['exam', 'test'])
    True
    >>> words_in_str('This is a test.', ['exam'])
    False
    """
    return bool(list(filter(_text.__contains__, _wordlist)))


def words_not_in_str(_text: str, _wordlist: list) -> bool:
    """Test if any of the listed words are not in the given string

    >>> words_not_in_str('This is a test.', ['exam', 'test'])
    True
    >>> words_not_in_str('This is a test.', ['exam'])
    True
    >>> words_not_in_str('This is a test.', ['test'])
    False
    """
    return any((_word not in _text for _word in _wordlist))


def isexe(fpath: str) -> bool:
    """Test if the specified file is executable

    >>> isexe('/bin/sh')
    True
    >>> isexe('/usr/bin/env')
    True
    >>> isexe('/usr/bin')
    False
    >>> isexe('/etc/mime.types')
    False
    """
    return isfile(fpath) and access(fpath, X_OK)


def isinpath(program: str) -> bool:
    """Test if the specified application is in the system PATH

    >>> isinpath('sh')
    True
    >>> isinpath('env')
    True
    >>> isinpath('firefox')
    True
    >>> isinpath('FIREFOX')
    False
    >>> isinpath('not_in_path')
    False
    >>> isinpath('/usr/bin')
    False
    >>> isinpath('/usr/bin/')
    False
    >>> isinpath('/usr')
    False
    """
    fpath = splitpath(program)[0]
    if fpath and isfile(program) and access(program, X_OK):
        return True
    envpath = environ[r'PATH'].split(pathsep)
    for filepath in envpath:
        exe_file = joinpath(filepath.strip(r'"'), program)
        if isfile(exe_file) and access(exe_file, X_OK):
            return True
    return False


def isvalidcode(_code: str) -> bool:
    """Test if the given string is valid Python code

    >>> isvalidcode('print("True")')
    True
    >>> isvalidcode('_str = Invalid"')
    False
    """
    try:
        parse(_code)
    except SyntaxError:
        return False
    return True


def isintuplelist(_tuple_list: list, _val: str) -> bool:
    """Test if the given value is the first value in the list of tuples

    >>> isintuplelist([('test', 'value'), (1, 2), ('found', 'string')], 'found')
    True
    """
    return any((_val == _test[0] for _test in _tuple_list))

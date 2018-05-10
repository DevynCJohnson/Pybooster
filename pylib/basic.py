#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Basic functions for most uses

@file basic.py
@package pybooster.basic
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


from ast import parse
from collections.abc import Awaitable
from base64 import b64decode, b64encode
from csv import reader as creader
from inspect import currentframe
from json import dumps as jdump
from os import X_OK, access, environ, pathsep
from os.path import dirname, isfile, join as joinpath, split as splitpath
from pickle import dumps, loads
from sys import modules, stdout
from types import BuiltinFunctionType, CodeType, CoroutineType, FrameType, FunctionType, GeneratorType, GetSetDescriptorType, MemberDescriptorType, MethodType, ModuleType, TracebackType
from urllib.request import urlopen
from zlib import compress as zlibcompress, decompress as zlibdecompress


try:  # Regular Expression module
    from regex import I as REI, fullmatch as refullmatch
except ImportError:
    from re import I as REI, fullmatch as refullmatch


__all__ = [
    # CONSTANTS #
    r'CO_COROUTINE',
    r'CO_GENERATOR',
    r'CO_ITERABLE_COROUTINE',
    # CLASSES #
    r'SameFileError',
    r'ObjectError',
    r'NullException',
    # BOOLEAN-RELATED FUNCTIONS #
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
    r'isintuplelist',
    # MODULES & IMPORTS #
    r'lsmods',
    r'imports',
    r'imported',
    r'wheremods',
    r'wherecurmods',
    r'modpath',
    r'modexist',
    r'rmmod',
    # DICTIONARY-RELATED FUNCTIONS #
    r'finddictkey',
    r'finddictkeys',
    r'doeskeymvalue',
    r'rmdupkey',
    r'rmdupkey_casein',
    r'rmdupval',
    r'listkeys',
    r'mergestrdict',
    # LIST-RELATED FUNCTIONS #
    r'create_2d_array',
    r'sortlistshort2long',
    r'sortlistlong2short',
    r'rmduplist',
    r'rmduplist_tuple',
    r'rmduplist_set',
    r'rmduplist_frozenset',
    # MISCELLANEOUS #
    r'datadump',
    r'execfile',
    r'incde',
    r'clearscr',
    r'pygrep',
    r'ipygrep',
    r'playmusic',
    r'getlinenum',
    r'ezcompile',
    r'csv2json',
    r'getwebpage',
    r'wlong',
    r'int2bitlen',
    r'char2bitlen'
]


# CONSTANTS #


CO_COROUTINE = 128
CO_GENERATOR = 32
CO_ITERABLE_COROUTINE = 256


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


# BOOLEAN-RELATED FUNCTIONS #


def rmfalse(_iter: iter) -> list:
    """Remove False values from iterable and return evaluated list"""
    return [x for x in _iter if x]


def evaliter(_iter: iter) -> list:
    """Evaluate values in iterable and return evaluated list of booleans"""
    return [x for x in _iter]


def eny(_iter: iter) -> bool:
    """Enhanced any()

    >>> eny([1, 0, 2, 'str'])
    True
    >>> eny(['str', 'x', 'y'])
    False
    >>> eny(('str', 'x', 'y'))
    False
    """
    return True if True in _iter else False


def isiter(_iter: iter) -> bool:
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


def iscomplex(_obj) -> bool:
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
        elif _obj.__class__ is int:
            return False
        elif _obj.__class__ is str and r'j' not in _obj:
            return False
        elif complex(''.join(_obj.split())).__class__ is complex:
            return True
        return False
    except (SyntaxError, TypeError, ValueError):
        return False


def iscomplextype(_obj) -> bool:
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
    return True if _obj.__class__ is complex else False


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
    return bool(isinstance(_object, (FunctionType, MethodType)) and _object.__code__.co_flags & CO_GENERATOR)


def iscoroutinefunction(_object: object) -> bool:
    """Return true if the object is a coroutine function"""
    return bool(isinstance(_object, (FunctionType, MethodType)) and _object.__code__.co_flags & CO_COROUTINE)


def isgenerator(_object: object) -> bool:
    """Return true if the object is a generator"""
    return isinstance(_object, GeneratorType)


def iscoroutine(_object: object) -> bool:
    """Return true if the object is a coroutine"""
    return isinstance(_object, CoroutineType)


def isawaitable(_object: object) -> bool:
    """Return true if object can be passed to an `await` expression"""
    return (
        isinstance(_object, (Awaitable, CoroutineType)) or
        isinstance(_object, GeneratorType) and
        bool(_object.gi_code.co_flags & CO_ITERABLE_COROUTINE)
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
    return (
        isinstance(_object, (BuiltinFunctionType, FunctionType, MethodType)) or
        ismethoddescriptor(_object)
    )


def isabstract(_object: object) -> bool:
    """Return true if the object is an abstract base class (ABC)"""
    return bool(isinstance(_object, type) and _object.__flags__ & 1048576)


def isbetween(_lo: int or float, _hi: int or float, _num: int or float) -> bool:
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
    assert _lo < _hi, r'Invalid input for isbetween()!'
    return _lo <= _num <= _hi


def isdefined(_var_name: str) -> bool:
    """Test if the named variable is defined in current scope"""
    assert isinstance(_var_name, str), \
        'isdefined() only accepts strings - isdefined(\'_var_name\')'
    return _var_name in globals() or _var_name in vars()


def ismodloaded(_module: str) -> bool:
    """Test if the named module is imported"""
    assert isinstance(_module, str), \
        'ismodloaded() only accepts strings - ismodloaded(\'_module\')'
    return _module in modules.keys()


def isfrozen() -> bool:
    """Test if the modules are built into the interpreter (As seen in py2exe)"""
    _tmp = None
    try:
        _tmp = __import__(r'sys')
        return hasattr(_tmp, r'frozen')
    except ImportError:
        return False
    finally:
        del _tmp


def ismodfrozen(module_name: str) -> bool:
    """Test if the specified module is frozen (built into the interpreter)"""
    _tmp = None
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
    for _word in _wordlist:
        if _word in _text:
            return True
    return False


def words_not_in_str(_text: str, _wordlist: list) -> bool:
    """Test if any of the listed words are not in the given string

    >>> words_not_in_str('This is a test.', ['exam', 'test'])
    True
    >>> words_not_in_str('This is a test.', ['exam'])
    True
    >>> words_not_in_str('This is a test.', ['test'])
    False
    """
    for _word in _wordlist:
        if _word not in _text:
            return True
    return False


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
    else:
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


def isintuplelist(tuple_list: list, val: str) -> bool:
    """Test if the given value is the first value in the list of tuples

    >>> isintuplelist([('test', 'value'), (1, 2), ('found', 'string')], 'found')
    True
    """
    for test in tuple_list:
        if val == test[0]:
            return True
    return False


# MODULES & IMPORTS #


def lsmods() -> list:
    """List loaded modules"""
    return list(modules.keys())


def imports() -> list:
    """List all imports"""
    _imports = []
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
    assert isinstance(_module, str), \
        'modexist() only accepts strings - modexist(\'_module\')'
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
    assert isinstance(_modname, str), \
        'rm_mod() only accepts strings - rm_mod(\'_modname\')'
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
    return


# DICTIONARY-RELATED FUNCTIONS #


def finddictkey(_dict: dict, search_val) -> str:
    """Search a dictionary by value and stop on first instance

    Return the key containing the value; Else, return an empty string
    """
    for _key, val in _dict.items():
        if val == search_val:
            return _key
    return r''


def finddictkeys(_dict: dict, search_val: object) -> list:
    """Search a dictionary by value and find all instances

    Return a list of keys - ['key1', 'key2']; Else, return an empty list - []

    >>> finddictkeys({'a': 0, 'b': 1, 'c': 2}, 1)
    ['b']
    >>> finddictkeys({'a': 0, 'b': 1, 'c': 2}, 3)
    []
    """
    _out = []
    for _key, val in _dict.items():
        if val == search_val:
            _out.append(_key)
    return _out


def doeskeymvalue(_dict: dict) -> bool:
    """Test if any key matches any dict value

    Return True if a key matches a value in the dict
    Only int and str types are supported

    >>> doeskeymvalue({'A': 'x', 'B': 'A', 'C': 'z'})
    True
    >>> doeskeymvalue({'A': 'A', 'B': 'y', 'C': 'z'})
    True
    >>> doeskeymvalue({1: 'x', 2: 'y', 'C': 1})
    True
    >>> doeskeymvalue({'A': 'x', 'B': 'y', 'C': 'z'})
    False
    >>> doeskeymvalue({'A': 'x', 'B': 'a', 'C': 'z'})
    False
    >>> doeskeymvalue({'A': 'x', 'B': ['A', 'y'], 'C': 'z'})
    False
    """
    for _key in _dict.keys():
        if _key in _dict.values():
            return True
    return False


def rmdupkey(_dict: dict) -> dict:
    """Remove duplicate keys"""
    _out = {}
    for _key, val in _dict.items():
        if _key not in _out.keys():
            _out[_key] = val
    return _out


def rmdupkey_casein(_dict: dict) -> dict:
    """Values of duplicate keys (besides one instance) are removed case-insensitively

    >>> rmdupkey_casein({'KEY': [1, 2, 3], 'key': [1, 2, 3]})
    {'key': [1, 2, 3]}
    >>> rmdupkey_casein({'key': [1, 2, 3], 'KEY': [1, 2, 3]})
    {'key': [1, 2, 3]}
    """
    _out = {}
    for _key, val in _dict.items():
        if _key.lower() not in _out.keys():
            _key = _key.lower()
            _out[_key] = val
    return _out


def rmdupval(_dict: dict) -> dict:
    """Remove duplicate values from a dict

    rmdupval({'key': [1, 2, 3], 'key1': [1, 2, 3]})
    {'key': [1, 2, 3]} or {'key1': [1, 2, 3]}
    """
    _out = {}
    for _key, val in _dict.items():
        if val not in _out.values():
            _out[_key] = val
    return _out


def listkeys(dict1: dict, dict2: dict) -> set:
    """Make a list (as a 'set') of the keys from two dicts

    listkeys({'KEY': [1, 2, 3], 'key2': [1, 2, 3]}, {'x': 1, 'y': 2})
    {'key2', 'KEY', 'x', 'y'}
    """
    return dict1.keys() | dict2.keys()


def mergestrdict(dict1: dict, dict2: dict) -> dict:
    """Merge two string dictionaries"""
    _keys = listkeys(dict1, dict2)
    return {_key: dict1.get(_key, r'') + r' ' + dict2.get(_key, r'') for _key in _keys}


# LIST-RELATED FUNCTIONS #


def create_2d_array(width: int, height: int) -> list:
    """Create a 2D array with the specified width and height"""
    return [[0 for x in range(width)] for y in range(height)]


def sortlistshort2long(_list: list) -> None:
    """Re-order a list (in-place) with shorter strings first

    >>> sortlistshort2long(['xz', 'xyz', 'x'])
    """
    _list.sort(key=len, reverse=True)
    return None


def sortlistlong2short(_list: list) -> None:
    """Re-order a list (in-place) with longer strings first

    >>> sortlistlong2short(['xz', 'xyz', 'x'])
    """
    _list.sort(key=len, reverse=False)
    return None


def rmduplist(_list: list) -> list:
    """Remove duplicate items from a list

    rmduplist(['xz', 'xyz', 'xz', 'y'])
    ['xyz', 'xz', 'y']
    """
    return list(set(_list))


def rmduplist_tuple(_list: list) -> tuple:
    """Remove duplicate items from a list and return a tuple

    rmduplist_tuple(['xz', 'xyz', 'xz', 'y'])
    ('xyz', 'xz', 'y')
    """
    return tuple(frozenset(_list))


def rmduplist_set(_list: list) -> set:
    """Remove duplicate items from a list and return a set

    rmduplist_set(['xz', 'xyz', 'xz', 'y'])
    {'xyz', 'xz', 'y'}
    """
    return set(_list)


def rmduplist_frozenset(_list: list) -> frozenset:
    """Remove duplicate items from a list and return a frozenset

    rmduplist_frozenset(['xz', 'xyz', 'xz', 'y'])
    frozenset{'xyz', 'xz', 'y'}
    """
    return frozenset(_list)


# MISCELLANEOUS #


def datadump(_data) -> bytes:
    """Pickle and compress (using Zlib) data and then encode the data in base64"""
    return b64encode(zlibcompress(dumps(_data), compresslevel=9))


def loaddata(_data: str) -> bytes:
    """Load the given compressed+pickled base64 data"""
    return loads(zlibdecompress(b64decode(_data)))


def execfile(_filename: str) -> object:
    """Execute Python script and get output"""
    with open(_filename, mode=r'rt', encoding=r'utf-8') as _file:
        return exec(_file.read())  # pylint: disable=W0122


def incde(i: int, j: int, delta: int = 1) -> None:
    """Increment and Deincrement

    for i, j in incde(i=3, j=7): print(i, j)
    """
    while True:
        yield i, j
        if j <= i:
            break
        i += delta
        j -= delta
    return None


def clearscr() -> None:
    """Clear Terminal"""
    stdout.write('\n' * 70)
    return None


def ipygrep(_find: str, _text: str) -> bool:
    """Case-insensitive reverse REGEX search

    Test if a plain-string matches a regex string
    """
    _match = refullmatch(_find, _text, flags=REI)
    if _match is not None:
        return _match
    return False


def pygrep(_find: str, _text: str) -> bool:
    """Case-sensitive reverse REGEX search; Test if a plain-string matches a regex string"""
    _match = refullmatch(_find, _text, flags=None)
    if _match is not None:
        return _match
    return False


def playmusic(_file: str) -> None:
    """Play an MP3, WAV, or other audio file via Pygame3"""
    try:
        from pygame.mixer import init, music
    except ImportError:
        raise Exception(r'Pygame is not installed or found.')
    init()
    music.load(_file)
    music.play()
    while music.get_busy() is True:
        continue
    return None


def getlinenum() -> int:
    """Return the script's line number where this method executes"""
    return currentframe().f_back.f_lineno


def ezcompile(_code: str) -> object:
    r"""Easily compile code that is in the form of a string

    Example 1 -
    c = \'\'\'print(''.join([line for line in open('/etc/passwd')]))\'\'\'
    bytecode = ezcompile(c)
    exec(bytecode) # or eval(bytecode)
    .
    Example 2 -
    c2 = 'x = 45 * 37; import math; y = math.cos(37); print(x); print(y)'
    bytecode = ezcompile(c2)
    """
    _tmplist = []
    try:
        comcode = compile(_code, _tmplist, r'eval')
    except SyntaxError:
        comcode = compile(_code, _tmplist, r'exec')
    return comcode


def csv2json(_filepath: str) -> str:
    """Convert a specified CSV file to a json string"""
    return jdump(list(creader(open(_filepath, mode=r'rt', encoding=r'utf-8'))))


def getwebpage(_address: str) -> str:
    """Return a webpage's HTML code as a string"""
    if r'://' not in _address:
        _address = r'http://' + _address
    if not _address.endswith(r'/'):
        _address += r'/'
    return urlopen(_address).read()


def wlong(_int32: int) -> bytes:
    """Convert a 32-bit integer to little-endian"""
    return (int(_int32) & 0xFFFFFFFF).to_bytes(4, r'little')


def int2bitlen(_int: int) -> int:
    """Return the number of bits needed to represent an integer"""
    return _int.bit_length()


def char2bitlen(_char: str) -> int:
    """Return the number of bits needed to represent a character"""
    assert len(_char) == 1, 'A string containing multiple characters was passed to char2bitlen()'
    return ord(_char).bit_length()

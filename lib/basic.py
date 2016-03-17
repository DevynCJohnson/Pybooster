#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
Created by Devyn Collier Johnson
<DevynCJohnson@Gmail.com>
LGPLv3 License
-- --
PyBooster - Various Extras for Python3
pybooster.basic
-- --
Basic functions for most uses
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

import os

from ast import parse
from csv import reader as creader
from inspect import currentframe
from json import dumps as jdump
from re import I as REI, fullmatch as refullmatch
from sys import modules
from types import ModuleType
from urllib.request import urlopen


__all__ = [
    # CLASSES
    'SameFileError',
    'ObjectError',
    'NullException',
    # BOOLEAN-RELATED FUNCTIONS
    'rmfalse',
    'evaliter',
    'eny',
    'isiter',
    'ishex',
    'isoct',
    'isbin',
    'iscomplex',
    'iscomplextype',
    'isbetween',
    'isdefined',
    'ismodloaded',
    'isfrozen',
    'ismodfrozen',
    'words_in_str',
    'words_not_in_str',
    'isexe',
    'isinpath',
    'isvalidcode',
    # MODULES AND IMPORTS
    'lsmods',
    'imports',
    'imported',
    'wheremods',
    'wherecurmods',
    'modpath',
    'modexist',
    'rmmod',
    # DICTIONARY-RELATED FUNCTIONS
    'finddictkey',
    'finddictkeys',
    'doeskeymvalue',
    'rmdupkey',
    'rmdupkey_casein',
    'rmdupval',
    'listkeys',
    'mergestrdict',
    # LIST-RELATED FUNCTIONS
    'sortlistshort2long',
    'sortlistlong2short',
    'rmduplist',
    'rmduplist_tuple',
    'rmduplist_set',
    'rmduplist_frozenset',
    # MISCELLANEOUS
    'execfile',
    'incde',
    'clearscr',
    'pygrep',
    'ipygrep',
    'playmusic',
    'getlinenum',
    'ezcompile',
    'csv2json',
    'getwebpage',
    'wlong',
    'cache',
    'int2bitlen',
    'char2bitlen',
]

__author__ = 'Devyn Collier Johnson'
__copyright__ = 'LGPLv3'
__version__ = '2016.03.09'


# CLASSES


class SameFileError(Exception):
    """Raised when source and target are the same file"""
    def __init__(self, msg: str='The source and target file are the same.'):
        super(SameFileError, self).__init__(msg)
        self.msg = msg

    def __str__(self):
        return repr(self.msg)


class ObjectError(NameError, TypeError, ValueError):
    """Raised when an object cannot be found, used, or manipulated"""
    def __init__(self, msg: str='The object is malformed.'):
        super(ObjectError, self).__init__(msg)
        self.msg = msg

    def __str__(self):
        return repr(self.msg)


class NullException(BaseException):
    """Null Exception"""
    pass


# BOOLEAN-RELATED FUNCTIONS


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
        elif _obj.__class__ is str and 'j' not in _obj:
            return False
        elif complex(''.join(_obj.split())).__class__ is complex:
            return True
        else:
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


def isbetween(_lo: int or float, _hi: int or float, _num: int or float) -> bool:
    """Tests if a float/integer is between two other floats/integers
    'float' and 'int' types may be compared to each other
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
    """Test if the modules are built into the interpreter
    (As seen in py2exe and others)
    """
    _tmp = None
    try:
        _tmp = __import__('sys')
        return hasattr(_tmp, 'frozen')
    except ImportError:
        return False
    finally:
        del _tmp


def ismodfrozen(module_name: str) -> bool:
    """Test if the specified module is frozen (built into the interpreter)"""
    _tmp = None
    try:
        _tmp = __import__(module_name)
        return hasattr(_tmp, 'frozen')
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
    return os.path.isfile(fpath) and os.access(fpath, os.X_OK)


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
    fpath = os.path.split(program)[0]
    if fpath and os.path.isfile(program) and os.access(program, os.X_OK):
        return True
    else:
        envpath = os.environ['PATH'].split(os.pathsep)
        for filepath in envpath:
            exe_file = os.path.join(filepath.strip(r'"'), program)
            if os.path.isfile(exe_file) and os.access(exe_file, os.X_OK):
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


# MODULES AND IMPORTS


def lsmods() -> list:
    """List loaded modules"""
    return list(modules.keys())


def imports() -> list:
    """List all imports"""
    _imports = []
    for name, val in globals().items():
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


def modpath(module: 'ModuleType') -> str:
    """Output module's file pathname"""
    try:
        return os.path.dirname(module.__file__)
    except AttributeError:
        raise RuntimeError('No module found. The module may be builtin or nonexistent.')


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


def rmmod(_modname: str):
    """Remove module from the running instance"""
    assert isinstance(_modname, str), \
        'modexist() only accepts strings - rm_mod(\'_modname\')'
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


# DICTIONARY-RELATED FUNCTIONS


def finddictkey(_dict: dict, search_val) -> str:
    """Search a dictionary by value and stop on first instance
    Return the key containing the value
    Else, return an empty string
    """
    for key, val in _dict.items():
        if val == search_val:
            return key
    return ''


def finddictkeys(_dict: dict, search_val) -> list:
    """Search a dictionary by value and find all instances
    Return a list of keys - ['key1', 'key2']
    Else, return an empty list - []
    """
    _out = []
    for key, val in _dict.items():
        if val == search_val:
            _out.append(key)
    return _out


def doeskeymvalue(_dict: dict) -> bool:
    """Test if any key matches any dict value
    Return True if a key matches a value in the dict
    Examples - doeskeymvalue(DICT)
    -{ 'A': 'x', 'B': 'A', 'C': 'z'} => True
    -{ 'A': 'A', 'B': 'y', 'C': 'z'} => True
    -{ 1: 'x', 2: 'y', 'C': 1} => True
    -{ 'A': 'x', 'B': 'y', 'C': 'z'} => False
    -{ 'A': 'x', 'B': 'a', 'C': 'z'} => False
    Only int and str types are supported
    -{ 'A': 'x', 'B': ['A', 'y'], 'C': 'z'} => False
    """
    for key in _dict.keys():
        if key in _dict.values():
            return True
    return False


def rmdupkey(_dict: dict) -> dict:
    """Remove duplicate keys
    >>> rmdupkey({'key': [1, 2, 3], 'key': [4, 5, 6]})
    {'key': [4, 5, 6]}
    >>> rmdupkey({'key': [4, 5, 6], 'key': [1, 2, 3]})
    {'key': [1, 2, 3]}
    """
    _out = {}
    for key, val in _dict.items():
        if key not in _out.keys():
            _out[key] = val
    return _out


def rmdupkey_casein(_dict: dict) -> dict:
    """Remove duplicate keys case-insensitively
    Values of duplicate keys (besides one instance) are removed
    >>> rmdupkey_casein({'KEY': [1, 2, 3], 'key': [1, 2, 3]})
    {'key': [1, 2, 3]}
    >>> rmdupkey_casein({'key': [1, 2, 3], 'KEY': [1, 2, 3]})
    {'key': [1, 2, 3]}
    """
    _out = {}
    for key, val in _dict.items():
        if key.lower() not in _out.keys():
            key = key.lower()
            _out[key] = val
    return _out


def rmdupval(_dict: dict) -> dict:
    """Remove duplicate values from a dict
    rmdupval({'key': [1, 2, 3], 'key1': [1, 2, 3]})
    {'key': [1, 2, 3]} or {'key1': [1, 2, 3]}
    """
    _out = {}
    for key, val in _dict.items():
        if val not in _out.values():
            _out[key] = val
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
    return {key: dict1.get(key, '') + ' ' + dict2.get(key, '') for key in _keys}


# LIST-RELATED FUNCTIONS


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


# MISCELLANEOUS


def execfile(_filename: str):
    """Execute Python script and get output"""
    with open(_filename, mode='rt', encoding='utf-8') as _file:
        return exec(_file.read())


def incde(i: int, j: int, delta: int=1) -> None:
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
    print('\n' * 70)  # noqa
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
    """Case-ensitive reverse REGEX search
    Test if a plain-string matches a regex string
    """
    _match = refullmatch(_find, _text, flags=None)
    if _match is not None:
        return _match
    return False


def playmusic(_file: str) -> None:
    """Play an MP3, WAV, or other audio file via Pygame3"""
    try:
        from pygame.mixer import init, music
    except ImportError:
        raise Exception('Pygame is not installed or found.')
    init()
    music.load(_file)
    music.play()
    while music.get_busy() is True:
        continue
    return None


def getlinenum() -> int:
    """Return the script's line number where this method executes"""
    return currentframe().f_back.f_lineno


def ezcompile(_code: str):
    """Easily compile code that is in the form of a string
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
        comcode = compile(_code, _tmplist, 'eval')
    except SyntaxError:
        comcode = compile(_code, _tmplist, 'exec')
    return comcode


def csv2json(_filepath: str) -> str:
    """Convert a specified CSV file to a json string"""
    return jdump(list(creader(open(_filepath, mode='rt', encoding='utf-8'))))


def getwebpage(_address: str) -> str:
    """Return a webpage's HTML code as a string
    Usage:
    getwebpage('http://website.com/')
    """
    if '://' not in _address:
        _address = r'http://' + _address
    if not _address.endswith(r'/'):
        _address += r'/'
    return urlopen(_address).read()


def wlong(_int32) -> bytes:
    """Convert a 32-bit integer to little-endian"""
    return (int(_int32) & 0xFFFFFFFF).to_bytes(4, 'little')


def cache(_action: str, _ckey: str='', _cval=None):
    """Store data in cache in the form of a dict"""
    global _cache
    try:
        _cache
    except NameError:
        _cache = {}
    if _action == '':
        raise Exception('You must specify an action!')
    elif _action == 'print' or _action == 'display' or _action == 'return':
        return _cache
    elif _action in 'dpr':
        return _cache
    elif _action == 's' or _action == 'store' or _action == 'save':
        if _ckey != '' and _cval.__class__ is not None:
            _cache[_ckey] = _cval
        else:
            raise Exception('You must specify a key and value!')
    elif _action == 'k' and _ckey != '':
        return _cache[_ckey]
    elif _ckey == '' and _cval.__class__ is not None:
        raise Exception('You must specify a key!')
    else:
        raise Exception('You must specify an action and a key + value!')


def int2bitlen(_int: int) -> int:
    """Return the number of bits needed to represent an integer"""
    return _int.bit_length()


def char2bitlen(_char: str) -> int:
    """Return the number of bits needed to represent a character"""
    assert len(_char) == 1, \
        'A string containing multiple characters was passed to char2bitlen()'
    return ord(_char).bit_length()

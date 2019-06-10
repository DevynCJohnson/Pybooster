#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Functions that manipulate iterables

@file iterables.py
@package pybooster.iterables
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


from typing import AbstractSet, Any, Generator, Union


__all__: list = [
    # GENERATORS #
    r'frange',
    r'incde',
    # DICTIONARY-RELATED FUNCTIONS #
    r'doeskeymvalue',
    r'finddictkey',
    r'finddictkeys',
    r'finddictkeyx',
    r'listkeys',
    r'mergestrdict',
    r'rmdupkey',
    r'rmdupkey_casein',
    r'rmdupval',
    # LIST-RELATED FUNCTIONS #
    r'create_2d_array',
    r'func_range',
    r'mergeoddeven',
    r'rmduplist',
    r'rmduplist_frozenset',
    r'rmduplist_set',
    r'rmduplist_tuple',
    r'sortlistlong2short',
    r'sortlistshort2long',
    r'transpose2dls'
]


# GENERATORS #


def frange(start: float, stop: float, step: float = 0.1) -> Generator[float, None, None]:
    """Create a generator for a range of floats from start to stop in increments equal to step

    >>> isinstance(frange(0.1, 1.0), Generator)
    True
    >>> len(list(frange(0.1, 1.0)))
    10
    >>> len(list(frange(0.01, 1.0, 0.01)))
    100
    >>> list(frange(0.1, 1.0))
    [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    """
    _ndigits: str = str(step)
    if r'e-0' in _ndigits:
        ndigits = int(_ndigits[-1:])
    elif r'e-' in _ndigits:
        ndigits = int(_ndigits[-2:])
    else:
        ndigits = len(str(_ndigits).replace(r'-', r'')) - 2
    while start <= stop:
        yield float(start)
        start = round(start + step, ndigits)


def incde(i: int, j: int, delta: int = 1) -> Generator[tuple, None, None]:
    """Increment and Deincrement

    for i, j in incde(i=3, j=7): print(i, j)
    """
    while True:
        yield i, j
        if j <= i:
            break
        i += delta
        j -= delta


# DICTIONARY-RELATED FUNCTIONS #


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


def finddictkey(_dict: dict, _search_val: str) -> str:
    """Search a dictionary by string value and stop on first instance

    Return the key containing the value; else, return an empty string

    >>> finddictkey({'a': '0', 'b': '1', 'c': '2'}, '1')
    'b'
    >>> finddictkey({'a': '0', 'b': '1', 'c': '2'}, '3')
    ''
    """
    for _key, _val in _dict.items():
        if isinstance(_search_val, str) and _val == _search_val:
            return _key
    return r''


def finddictkeys(_dict: dict, _search_val: Any) -> list:
    """Search a dictionary by value and find all instances

    Return a list of keys - ['key1', 'key2']; Else, return an empty list - []

    >>> finddictkeys({'a': 0, 'b': 1, 'c': 2}, 1)
    ['b']
    >>> finddictkeys({'a': 0, 'b': 1, 'c': 2}, 3)
    []
    >>> finddictkeys({'a': '0', 'b': '1', 'c': '2'}, '1')
    ['b']
    >>> finddictkeys({'a': '0', 'b': '1', 'c': '2'}, 4)
    []
    >>> finddictkeys({'a': '0', 'b': '1', 'c': '2', 'd': '1'}, '1')
    ['b', 'd']
    """
    _out: list = []
    for _key, _val in _dict.items():
        try:
            if _val == _search_val:
                _out.append(_key)
        except TypeError:
            continue
    return _out


def finddictkeyx(_dict: dict, _search_val: Any) -> str:
    """Search a dictionary by value and stop on first instance

    This searches key values that are tuples, lists, or strings.
    Returns the key (if found); else returns empty string

    >>> finddictkeyx({'a': 0, 'b': 1, 'c': 2}, 0)
    'a'
    >>> finddictkeyx({'a': 0, 'b': 1, 'c': 2}, 3)
    ''
    >>> finddictkeyx({'a': '0', 'b': '1', 'c': '2'}, '1')
    'b'
    >>> finddictkeyx({'a': '0', 'b': '1', 'c': '2'}, 4)
    ''
    """
    for _key, _val in _dict.items():
        try:
            if isinstance(_val, (int, str)) and _val == _search_val:
                return _key
            if _search_val in _val:
                return _key
        except TypeError:
            continue
    return r''


def listkeys(dict1: dict, dict2: dict) -> AbstractSet[Any]:
    """Make a list (as a 'set') of the keys from two dicts

    listkeys({'KEY': [1, 2, 3], 'key2': [1, 2, 3]}, {'x': 1, 'y': 2})
    {'key2', 'KEY', 'x', 'y'}
    """
    return dict1.keys() | dict2.keys()


def mergestrdict(dict1: dict, dict2: dict) -> dict:
    """Merge two string dictionaries

    mergestrdict({'KEY': '1, 2, 3'}, {'key2': '1, 2, 3'})
    {'KEY': '1, 2, 3', 'key2': '1, 2, 3'}
    """
    _keys = listkeys(dict1, dict2)
    return {_key: str(dict1.get(_key, r'') + r' ' + dict2.get(_key, r'')).strip() for _key in _keys}


def rmdupkey(_dict: dict) -> dict:
    """Remove duplicate keys"""
    _out: dict = {}
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
    _out: dict = {}
    for _key, val in _dict.items():
        if _key.lower() not in _out.keys():
            _out[_key.lower()] = val
    return _out


def rmdupval(_dict: dict) -> dict:
    """Remove duplicate values from a dict

    >>> rmdupval({'key': [1, 2, 3], 'key1': [1, 2, 3]})
    {'key': [1, 2, 3]}
    """
    _out: dict = {}
    for _key, val in _dict.items():
        if val not in _out.values():
            _out[_key] = val
    return _out


# LIST-RELATED FUNCTIONS #


def create_2d_array(width: int, height: int) -> list:
    """Create a 2D array with the specified width and height

    >>> create_2d_array(2, 2)
    [[0, 0], [0, 0]]
    >>> create_2d_array(3, 2)
    [[0, 0, 0], [0, 0, 0]]
    """
    return [[0 for x in range(width)] for y in range(height)]


def func_range(_func: object, _start: Union[float, int] = 0, _stop: Union[float, int] = 360, _step: Union[float, int] = 1) -> list:
    """Return a list of the outputs for the given range of inputs"""
    if isinstance(_start, float) or isinstance(_stop, float) or isinstance(_step, float):
        _num_list: list = list(frange(float(_start), float(_stop), float(_step)))
        return[_func(_val) for _val in _num_list]  # type: ignore
    return [_func(_val) for _val in range(_start, _stop, _step)]


def mergeoddeven(odd_list: list, even_list: list) -> list:
    """Merge two lists where one list contains the even fields and the other contains the odd fields"""
    _out: list = odd_list[:]
    for i, v in enumerate(even_list):
        _out.insert(2 * i + 1, v)
    return _out


def sortlistlong2short(_list: list) -> None:
    """Re-order a list (in-place) with longer strings first

    >>> sortlistlong2short(['xz', 'xyz', 'x'])
    """
    _list.sort(key=len, reverse=False)


def sortlistshort2long(_list: list) -> None:
    """Re-order a list (in-place) with shorter strings first

    >>> sortlistshort2long(['xz', 'xyz', 'x'])
    """
    _list.sort(key=len, reverse=True)


def rmduplist(_list: list) -> list:
    """Remove duplicate items from a list

    rmduplist(['xz', 'xyz', 'xz', 'y'])
    ['xyz', 'xz', 'y']
    """
    return list(set(_list))


def rmduplist_frozenset(_list: list) -> frozenset:
    """Remove duplicate items from a list and return a frozenset

    rmduplist_frozenset(['xz', 'xyz', 'xz', 'y'])
    frozenset({'xz', 'y', 'xyz'})
    """
    return frozenset(_list)


def rmduplist_set(_list: list) -> set:
    """Remove duplicate items from a list and return a set

    rmduplist_set(['xz', 'xyz', 'xz', 'y'])
    {'xz', 'y', 'xyz'}
    """
    return set(_list)


def rmduplist_tuple(_list: list) -> tuple:
    """Remove duplicate items from a list and return a tuple

    rmduplist_tuple(['xz', 'xyz', 'xz', 'y'])
    ('xz', 'y', 'xyz')
    """
    return tuple(frozenset(_list))


def transpose2dls(_list: list) -> list:
    """Transpose a 2D list

    transpose2dls([['x1', 'x2', 'x3'], ['y1', 'y2', 'y3']])
    [['x1', 'y1'], ['x2', 'y2', ], ['x3', 'y3']]
    """
    return list(map(lambda *_proc: list(_proc), *_list))

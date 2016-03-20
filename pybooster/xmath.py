#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""@brief Extra Math Functions
@file xmath.py
@package pybooster.xmath
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


# pylint: disable=C0103


from math import acos, asin, atan, log
from random import choice


__all__ = [
    # CONSTANTS
    'LARGE_NUMBERS',
    'SMALL_NUMBERS',
    # PI CONSTANTS
    'PI2',
    'HALFPI',
    'PIPI',
    'TWOPI',
    # INVERSE CONSTANTS
    'ONE_THIRD',
    'ONE_FOURTH',
    'ONE_FIFTH',
    'ONE_SIXTH',
    'ONE_SEVENTH',
    'ONE_EIGHTH',
    'ONE_NINTH',
    'ONE_TENTH',
    'ONE_ELEVENTH',
    'ONE_TWELFTH',
    'ONE_THIRTEENTH',
    # INVERSE TRIGONOMETRIC FUNCTIONS
    'arccot',
    'arccsc',
    'arcsec',
    # LOGARITHMS
    'ln',
    'napierianlog',
    'naturallog',
    # ROOTS
    'curt',
    'root4',
    'root5',
    'root6',
    'root7',
    'root8',
    'root9',
    'root10',
    'root11',
    'root12',
    'root13',
    # MISCELLANEOUS
    'factors',
    'degrees2radians',
    'radians2degrees',
    'showpercent',
    'int2many',
    'dice',
    'dice8',
    'coinflip',
    'flipcoin',
]


# CONSTANTS


LARGE_NUMBERS = (
    (r'million', 1000000),
    (r'billion', 1000000000),
    (r'trillion', 1000000000000),
    (r'quadrillion ', 1000000000000000),
    (r'quintillion', 1000000000000000000),
    (r'sextillion', 1000000000000000000000),
    (r'septillion', 1000000000000000000000000),
    (r'octillion', 1000000000000000000000000000),
    (r'nonillion', 1000000000000000000000000000000),
    (r'decillion', 1000000000000000000000000000000000),
    (r'undecillion', 1000000000000000000000000000000000000),
    (r'duodecillion', 1000000000000000000000000000000000000000),
    (r'tredecillion', 1000000000000000000000000000000000000000000),
    (r'quattuordecillion', 1000000000000000000000000000000000000000000000),
    (r'quindecillion', 1000000000000000000000000000000000000000000000000),
    (r'sexdecillion', 1000000000000000000000000000000000000000000000000000),
    (r'septendecillion', 1000000000000000000000000000000000000000000000000000000),
    (r'octodecillion', 10 ** 57),
    (r'novemdecillion', 10 ** 60),
    (r'vigintillion', 10 ** 63),
    (r'centillion', '10 ** 303'),
    (r'googol', 10 ** 100),
    (r'googolplex', '10 ** 10 ** 100'),
)


SMALL_NUMBERS = (
    (r'tenth', 0.100),
    (r'hundredth', 0.0100),
    (r'thousandth', 0.00100),
    (r'ten thousandth', 0.000100),
    (r'hundred thousandth', 0.0000100),
    (r'millionth', 0.00000100),
    (r'billionth', 0.00000000100),
    (r'trillionth', 0.00000000000100),
    (r'quadrillionth', 0.00000000000000100),
    (r'quintillionth', 0.00000000000000000100),
    (r'sextillionth', 0.00000000000000000000100),
    (r'septillionth', 0.00000000000000000000000100),
    (r'octillionth', 0.00000000000000000000000000100),
    (r'nonillionth', 0.00000000000000000000000000000100),
    (r'googolminex', '1 / (10 ** 10 ** 100)'),
)


# PI CONSTANTS


PI2 = 1.5707963267948966
HALFPI = 1.5707963267948966
PIPI = 6.283185307179586
TWOPI = 6.283185307179586


# INVERSE CONSTANTS


ONE_THIRD = 0.333333333
ONE_FOURTH = 0.2500
ONE_FIFTH = 0.20
ONE_SIXTH = 0.166666667
ONE_SEVENTH = 0.142857143
ONE_EIGHTH = 0.1250
ONE_NINTH = 0.111111111
ONE_TENTH = 0.1
ONE_ELEVENTH = 0.090909091
ONE_TWELFTH = 0.083333333
ONE_THIRTEENTH = 0.076923077


# INVERSE TRIGONOMETRIC FUNCTIONS


def arccot(_num: int or float) -> float:
    """Arccotangent"""
    return atan(1 / _num)


def arccsc(_num: int or float) -> float:
    """Arccosecant"""
    return asin(1 / _num)


def arcsec(_num: int or float) -> float:
    """Arcsecant"""
    return acos(1 / _num)


# LOGARITHMS


def ln(_num: int or float) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number)"""
    return log(_num, 2.718281828459045)


def napierianlog(_num: int or float) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number)"""
    return log(_num, 2.718281828459045)


def naturallog(_num: int or float) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number)"""
    return log(_num, 2.718281828459045)


# ROOTS


def curt(_num: int or float) -> float:
    """Cubed Root"""
    return _num ** 0.333333333


def root4(_num: int or float) -> float:
    """Hypercubed Root"""
    return _num ** 0.25


def root5(_num: int or float) -> float:
    """5th Root"""
    return _num ** 0.2


def root6(_num: int or float) -> float:
    """6th Root"""
    return _num ** 0.166666667


def root7(_num: int or float) -> float:
    """7th Root"""
    return _num ** 0.142857143


def root8(_num: int or float) -> float:
    """8th Root"""
    return _num ** 0.1250


def root9(_num: int or float) -> float:
    """9th Root"""
    return _num ** 0.111111111


def root10(_num: int or float) -> float:
    """10th Root"""
    return _num ** 0.1


def root11(_num: int or float) -> float:
    """11th Root"""
    return _num ** 0.090909091


def root12(_num: int or float) -> float:
    """12th Root"""
    return _num ** 0.083333333


def root13(_num: int or float) -> float:
    """13th Root"""
    return _num ** 0.076923077


# MISCELLANEOUS


def factors(_num: int) -> set:
    """Find prime factors"""
    return set(x for tup in ([i, _num // i] for i in range(1, int(_num ** 0.5) + 1) if _num % i == 0) for x in tup)


def degrees2radians(_degrees: float) -> float:
    """Convert Degrees to Radians {(PI / 180) * Degrees}"""
    return 0.017453292519943 * _degrees


def radians2degrees(_radians: float) -> float:
    """Convert Radians to Degrees {(180 / PI) * Radians}"""
    return 57.29577951308232 * _radians


def showpercent(_portion: int or float, _total: int or float=100) -> str:
    """Convert a portion and total to a percentage

    Input int and/or float types and get a string
    """
    return '{:.2%}'.format(_portion / _total)


def int2many(_int: int) -> str:
    """Convert a decimal number to mulitple number base types

    The returned value is a table as a string
    """
    return 'dec: {0:d};  hex: {0:x};  oct: {0:o};  bin: {0:b}'.format(_int)


def dice() -> int:
    """Roll a die and return a random integer (1-6)"""
    return choice((1, 2, 3, 4, 5, 6))


def dice8() -> int:
    """Roll an 8-sided die and return a random integer (1-8)"""
    return choice((1, 2, 3, 4, 5, 6, 7, 8))


def coinflip() -> str:
    """Flip a coin and return a string of heads or tails"""
    return choice((r'heads', r'tails'))


def flipcoin() -> str:
    """Flip a coin and return a string of heads or tails"""
    return choice((r'heads', r'tails'))

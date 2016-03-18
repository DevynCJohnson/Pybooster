#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
Created by Devyn Collier Johnson
<DevynCJohnson@Gmail.com>
LGPLv3 License
-- --
PyBooster - Various Extras for Python3
pybooster.xmath
-- --
Extra Math Functions
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

__author__ = 'Devyn Collier Johnson'
__copyright__ = 'LGPLv3'
__version__ = '2016.03.18'


# CONSTANTS


LARGE_NUMBERS = (
    ('million', 1000000),
    ('billion', 1000000000),
    ('trillion', 1000000000000),
    ('quadrillion ', 1000000000000000),
    ('quintillion', 1000000000000000000),
    ('sextillion', 1000000000000000000000),
    ('septillion', 1000000000000000000000000),
    ('octillion', 1000000000000000000000000000),
    ('nonillion', 1000000000000000000000000000000),
    ('decillion', 1000000000000000000000000000000000),
    ('undecillion', 1000000000000000000000000000000000000),
    ('duodecillion', 1000000000000000000000000000000000000000),
    ('tredecillion', 1000000000000000000000000000000000000000000),
    ('quattuordecillion', 1000000000000000000000000000000000000000000000),
    ('quindecillion', 1000000000000000000000000000000000000000000000000),
    ('sexdecillion', 1000000000000000000000000000000000000000000000000000),
    ('septendecillion', 1000000000000000000000000000000000000000000000000000000),
    ('octodecillion', 10 ** 57),
    ('novemdecillion', 10 ** 60),
    ('vigintillion', 10 ** 63),
    ('centillion', '10 ** 303'),
    ('googol', 10 ** 100),
    ('googolplex', '10 ** 10 ** 100'),
)


SMALL_NUMBERS = (
    ('tenth', 0.100),
    ('hundredth', 0.0100),
    ('thousandth', 0.00100),
    ('ten thousandth', 0.000100),
    ('hundred thousandth', 0.0000100),
    ('millionth', 0.00000100),
    ('billionth', 0.00000000100),
    ('trillionth', 0.00000000000100),
    ('quadrillionth', 0.00000000000000100),
    ('quintillionth', 0.00000000000000000100),
    ('sextillionth', 0.00000000000000000000100),
    ('septillionth', 0.00000000000000000000000100),
    ('octillionth', 0.00000000000000000000000000100),
    ('nonillionth', 0.00000000000000000000000000000100),
    ('googolminex', '1 / (10 ** 10 ** 100)'),
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
    """Convert Degrees to Radians
    (PI / 180) * Degrees
    """
    return 0.017453292519943 * _degrees


def radians2degrees(_radians: float) -> float:
    """Convert Radians to Degrees
    (180 / PI) * Radians
    """
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
    return choice(('heads', 'tails'))


def flipcoin() -> str:
    """Flip a coin and return a string of heads or tails"""
    return choice(('heads', 'tails'))

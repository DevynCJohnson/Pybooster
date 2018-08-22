#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Extra Math Functions

@file xmath.py
@package pybooster.xmath
@version 2018.08.22
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


# pylint: disable=C0103


from math import acos, asin, atan, cos, erf, log, sin, sqrt, tan
from random import choice
from typing import Union


__all__ = [
    # CONSTANTS #
    r'LARGE_NUMBERS',
    r'SMALL_NUMBERS',
    # PI CONSTANTS #
    r'PI2',
    r'HALFPI',
    r'PIPI',
    r'TWOPI',
    # INVERSE CONSTANTS #
    r'ONE_THIRD',
    r'ONE_FOURTH',
    r'ONE_FIFTH',
    r'ONE_SIXTH',
    r'ONE_SEVENTH',
    r'ONE_EIGHTH',
    r'ONE_NINTH',
    r'ONE_TENTH',
    r'ONE_ELEVENTH',
    r'ONE_TWELFTH',
    r'ONE_THIRTEENTH',
    # TRIGONOMETRIC FUNCTIONS #
    r'cot',
    r'csc',
    r'cvc',
    r'cvs',
    r'hcc',
    r'hcv',
    r'hvc',
    r'hvs',
    r'sec',
    r'siv',
    r'vcs',
    # INVERSE TRIGONOMETRIC FUNCTIONS #
    r'acot',
    r'acsc',
    r'acvc',
    r'acvs',
    r'ahvc',
    r'ahvs',
    r'asec',
    r'asiv',
    r'avcs',
    # EXTERNAL TRIGONOMETRIC FUNCTIONS #
    r'excsc',
    r'exsec',
    # MISCELLANEOUS TRIGONOMETRIC FUNCTIONS #
    r'crd',
    # LOGARITHMS #
    r'ln',
    r'napierianlog',
    r'naturallog',
    # ROOTS #
    r'curt',
    r'root4',
    r'root5',
    r'root6',
    r'root7',
    r'root8',
    r'root9',
    r'root10',
    r'root11',
    r'root12',
    r'root13',
    # NUMBER THEORY #
    r'factors',
    r'phi',
    # STATISTICS #
    r'showpercent',
    # PROBABILITY #
    r'dice',
    r'dice8',
    r'coinflip',
    r'flipcoin',
    # MISCELLANEOUS #
    r'clamp',
    r'int2many',
    r'degrees2radians',
    r'radians2degrees'
]


# CONSTANTS #


LARGE_NUMBERS = (
    (r'million', 1000000),
    (r'billion', 1000000000),
    (r'trillion', 1000000000000),
    (r'quadrillion', 1000000000000000),
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
    (r'centillion', r'10 ** 303'),
    (r'googol', 10 ** 100),
    (r'googolplex', r'10 ** 10 ** 100'),
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
    (r'googolminex', r'1 / (10 ** 10 ** 100)'),
)


# PI CONSTANTS #


PI2 = 1.5707963267948966
HALFPI = 1.5707963267948966
PIPI = 6.283185307179586
TWOPI = 6.283185307179586


# INVERSE CONSTANTS #


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


# TRIGONOMETRIC FUNCTIONS #


def cot(_num: float) -> float:
    """Cotangent (Tangent Complement)

    >>> cot(90.0)
    -0.5012027833801532
    """
    return 1.0 / tan(_num)


def csc(_num: float) -> float:
    """Cosecant (Secant Complement)

    >>> csc(90.0)
    1.1185724071637084
    """
    return 1.0 / sin(_num)


def cvc(_num: float) -> float:
    """Versed Cosine Complement (covercos)

    >>> cvc(90.0)
    1.8939966636005579
    """
    return 1.0 + sin(_num)


def cvs(_num: float) -> float:
    """Versed Sine Complement (coversin, cosiv)

    >>> cvs(90.0)
    0.10600333639944215
    """
    return 1.0 - sin(_num)


def hcc(_num: float) -> float:
    """Half-Versed Cosine Complement (hacovercos)"""
    return (1.0 + sin(_num)) * 0.5


def hcv(_num: float) -> float:
    """Half-Versed Sine Complement (hacoversin)"""
    return (1.0 - sin(_num)) * 0.5


def hvc(_num: float) -> float:
    """Half-Versed Cosine (hac, havercos)"""
    return (1.0 + cos(_num)) * 0.5


def hvs(_num: float) -> float:
    """Half-Versed Sine (haversin, hv)"""
    return (1.0 - cos(_num)) * 0.5


def sec(_num: float) -> float:
    """Secant (Reciprocal of cos)"""
    return 1.0 / cos(_num)


def siv(_num: float) -> float:
    """Versed Sine (versin, siv)"""
    return 1.0 - cos(_num)


def vcs(_num: float) -> float:
    """Versed Cosine (vercos)"""
    return 1.0 + cos(_num)


# INVERSE TRIGONOMETRIC FUNCTIONS #


def acot(_num: Union[float, int]) -> float:
    """Arccotangent"""
    return atan(1 / _num)


def acsc(_num: Union[float, int]) -> float:
    """Arccosecant"""
    return asin(1 / _num)


def acvc(_num: float) -> float:
    """Versed Arccosine Complement (acovercos)"""
    return asin(1.0 + _num)


def acvs(_num: float) -> float:
    """Versed Arcsine Complement (acoversin, acosiv)"""
    return asin(1.0 - _num)


def ahvc(_num: float) -> float:
    """Half-Versed Arccosine (ahac, ahavercos)"""
    return 2.0 * acos(sqrt(_num))


def ahvs(_num: float) -> float:
    """Half-Versed Arcsine (ahaversin, ahv)"""
    return 2.0 * asin(sqrt(_num))


def asec(_num: Union[float, int]) -> float:
    """Arcsecant"""
    return acos(1 / _num)


def asiv(_num: float) -> float:
    """Versed Arcsine (aver, aversin)"""
    return acos(1.0 - _num)


def avcs(_num: float) -> float:
    """Versed Arccosine (avercos)"""
    return cos(1.0 + _num)


# EXTERNAL TRIGONOMETRIC FUNCTIONS #


def excsc(_num: float) -> float:
    """External Cosecant"""
    return (1.0 / sin(_num)) - 1.0


def exsec(_num: float) -> float:
    """External Secant"""
    return (1.0 / cos(_num)) - 1.0


# MISCELLANEOUS TRIGONOMETRIC FUNCTIONS #


def crd(_num: float) -> float:
    """Chord of a circle"""
    return sin(_num * 0.5) * 2.0


# LOGARITHMS #


def ln(_num: Union[float, int]) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number)"""
    return log(_num, 2.718281828459045)


def napierianlog(_num: Union[float, int]) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number)"""
    return log(_num, 2.718281828459045)


def naturallog(_num: Union[float, int]) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number)"""
    return log(_num, 2.718281828459045)


# ROOTS #


def curt(_num: Union[float, int]) -> float:
    """Cubed Root"""
    return _num ** 0.333333333


def root4(_num: Union[float, int]) -> float:
    """Hypercubed Root"""
    return _num ** 0.25


def root5(_num: Union[float, int]) -> float:
    """5th Root"""
    return _num ** 0.2


def root6(_num: Union[float, int]) -> float:
    """6th Root"""
    return _num ** 0.166666667


def root7(_num: Union[float, int]) -> float:
    """7th Root"""
    return _num ** 0.142857143


def root8(_num: Union[float, int]) -> float:
    """8th Root"""
    return _num ** 0.1250


def root9(_num: Union[float, int]) -> float:
    """9th Root"""
    return _num ** 0.111111111


def root10(_num: Union[float, int]) -> float:
    """10th Root"""
    return _num ** 0.1


def root11(_num: Union[float, int]) -> float:
    """11th Root"""
    return _num ** 0.090909091


def root12(_num: Union[float, int]) -> float:
    """12th Root"""
    return _num ** 0.083333333


def root13(_num: Union[float, int]) -> float:
    """13th Root"""
    return _num ** 0.076923077


# NUMBER THEORY #


def factors(_num: int) -> set:
    """Find prime factors"""
    return set(x for tup in ([i, _num // i] for i in range(1, int(_num ** 0.5) + 1) if _num % i == 0) for x in tup)


def phi(_num: float) -> float:
    """Euler's Totient Function counts the positive integers up to a given integer `_num` that are relatively prime to `_num`"""
    return (1.0 + erf(_num / 1.4142135623730950488016887242096980785696718753769480732)) * 0.5


# STATISTICS #


def showpercent(_portion: Union[float, int], _total: Union[float, int] = 100.0) -> str:
    """Convert a portion and total to a percentage

    Input int and/or float types and get a string
    """
    return r'{:.2%}'.format(float(_portion) / float(_total))


# PROBABILITY #


def dice() -> int:
    """Roll a die and return a random integer (1-6)"""
    return choice((1, 2, 3, 4, 5, 6))  # nosec


def dice8() -> int:
    """Roll an 8-sided die and return a random integer (1-8)"""
    return choice((1, 2, 3, 4, 5, 6, 7, 8))  # nosec


def coinflip() -> str:
    """Flip a coin and return a string of heads or tails"""
    return choice((r'heads', r'tails'))  # nosec


def flipcoin() -> str:
    """Flip a coin and return a string of heads or tails"""
    return choice((r'heads', r'tails'))  # nosec


# MISCELLANEOUS #


def clamp(_num: float, smallest: float = -1.0, largest: float = 1.0) -> float:
    """Clamp a value within the specified range

    >>> clamp(37.0, 17.0, 73.0)
    37.0
    >>> clamp(377.0, 17.0, 73.0)
    73.0
    >>> clamp(3.14159, 17.0, 73.0)
    17.0
    """
    if _num > largest:
        return largest
    elif _num < smallest:
        return smallest
    return _num


def int2many(_int: int) -> str:
    """Convert a decimal number to mulitple number base types

    The returned value is a table in the form of a string

    >>> int2many(37)
    'dec: 37;  hex: 25;  oct: 45;  bin: 100101'
    """
    return r'dec: {0:d};  hex: {0:x};  oct: {0:o};  bin: {0:b}'.format(_int)


def degrees2radians(_degrees: float) -> float:
    """Convert Degrees to Radians {(PI / 180) * Degrees}

    >>> degrees2radians(90.0)
    1.5707963267948701
    """
    return 0.017453292519943 * _degrees


def radians2degrees(_radians: float) -> float:
    """Convert Radians to Degrees {(180 / PI) * Radians}

    >>> radians2degrees(30.0)
    1718.8733853924696
    """
    return 57.29577951308232 * _radians

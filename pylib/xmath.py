#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Extra Math Functions

@file xmath.py
@package pybooster.xmath
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


# pylint: disable=C0103


from math import acos, asin, atan, cos, erf, log, sin, sqrt, tan
from random import choice


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
    r'covercos',
    r'coversin',
    r'csc',
    r'hacovercos',
    r'hacoversin',
    r'havercos',
    r'haversin',
    r'sec',
    r'vercos',
    r'versin',
    # INVERSE TRIGONOMETRIC FUNCTIONS #
    r'acot',
    r'acovercos',
    r'acoversin',
    r'acsc',
    r'ahavercos',
    r'ahaversin',
    r'asec',
    r'avercos',
    r'aversin',
    # EXTERNAL TRIGONOMETRIC FUNCTIONS #
    r'excsc',
    r'exsec',
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
    # MISCELLANEOUS #
    r'clamp',
    r'phi',
    r'factors',
    r'crd',
    r'degrees2radians',
    r'radians2degrees',
    r'showpercent',
    r'int2many',
    r'dice',
    r'dice8',
    r'coinflip',
    r'flipcoin'
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
    """Cotangent (Tangent Complement)"""
    return 1.0 / tan(_num)


def covercos(_num: float) -> float:
    """Versed Cosine Complement (cvc)"""
    return 1.0 + sin(_num)


def coversin(_num: float) -> float:
    """Versed Sine Complement (cvs, cosiv)"""
    return 1.0 - sin(_num)


def csc(_num: float) -> float:
    """Cosecant (Secant Complement)"""
    return 1.0 / sin(_num)


def hacovercos(_num: float) -> float:
    """Half-Versed Cosine Complement (hcc)"""
    return (1.0 + sin(_num)) * 0.5


def hacoversin(_num: float) -> float:
    """Half-Versed Sine Complement (hcv)"""
    return (1.0 - sin(_num)) * 0.5


def havercos(_num: float) -> float:
    """Half-Versed Cosine (hac, hvc)"""
    return (1.0 + cos(_num)) * 0.5


def haversin(_num: float) -> float:
    """Half-Versed Sine (hvs, hv)"""
    return (1.0 - cos(_num)) * 0.5


def sec(_num: float) -> float:
    """Secant (Reciprocal of cos)"""
    return 1.0 / cos(_num)


def vercos(_num: float) -> float:
    """Versed Cosine (vcs)"""
    return 1.0 + cos(_num)


def versin(_num: float) -> float:
    """Versed Sine (siv)"""
    return 1.0 - cos(_num)


# INVERSE TRIGONOMETRIC FUNCTIONS #


def acot(_num: int or float) -> float:
    """Arccotangent"""
    return atan(1 / _num)


def acovercos(_num: float) -> float:
    """Versed Arccosine Complement (acvc)"""
    return asin(1.0 + _num)


def acoversin(_num: float) -> float:
    """Versed Arcsine Complement (acvs, acosiv)"""
    return asin(1.0 - _num)


def acsc(_num: int or float) -> float:
    """Arccosecant"""
    return asin(1 / _num)


def ahavercos(_num: float) -> float:
    """Half-Versed Arccosine (ahac, ahvc)"""
    return 2.0 * acos(sqrt(_num))


def ahaversin(_num: float) -> float:
    """Half-Versed Arcsine (ahvs, ahv)"""
    return 2.0 * asin(sqrt(_num))


def asec(_num: int or float) -> float:
    """Arcsecant"""
    return acos(1 / _num)


def avercos(_num: float) -> float:
    """Versed Arccosine (avcs)"""
    return cos(1.0 + _num)


def aversin(_num: float) -> float:
    """Versed Arcsine (aver)"""
    return acos(1.0 - _num)


# EXTERNAL TRIGONOMETRIC FUNCTIONS #


def excsc(_num: float) -> float:
    """External Cosecant"""
    return (1.0 / sin(_num)) - 1.0


def exsec(_num: float) -> float:
    """External Secant"""
    return (1.0 / cos(_num)) - 1.0


# LOGARITHMS #


def ln(_num: int or float) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number)"""
    return log(_num, 2.718281828459045)


def napierianlog(_num: int or float) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number)"""
    return log(_num, 2.718281828459045)


def naturallog(_num: int or float) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number)"""
    return log(_num, 2.718281828459045)


# ROOTS #


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


# MISCELLANEOUS #


def clamp(_num: float, smallest: float = -1.0, largest: float = 1.0) -> float:
    """Clamp a value within the specified range"""
    if _num > largest:
        return largest
    elif _num < smallest:
        return smallest
    return _num


def phi(_num: float) -> float:
    """Cumulative distribution function for the standard normal distribution"""
    return (1.0 + erf(_num / 1.4142135623730950488016887242096980785696718753769480732)) * 0.5


def factors(_num: int) -> set:
    """Find prime factors"""
    return set(x for tup in ([i, _num // i] for i in range(1, int(_num ** 0.5) + 1) if _num % i == 0) for x in tup)


def crd(_num: float) -> float:
    """Chord of a circle"""
    return sin(_num * 0.5) * 2.0


def degrees2radians(_degrees: float) -> float:
    """Convert Degrees to Radians {(PI / 180) * Degrees}"""
    return 0.017453292519943 * _degrees


def radians2degrees(_radians: float) -> float:
    """Convert Radians to Degrees {(180 / PI) * Radians}"""
    return 57.29577951308232 * _radians


def showpercent(_portion: int or float, _total: int or float = 100) -> str:
    """Convert a portion and total to a percentage

    Input int and/or float types and get a string
    """
    return r'{:.2%}'.format(_portion / _total)


def int2many(_int: int) -> str:
    """Convert a decimal number to mulitple number base types

    The returned value is a table as a string
    """
    return r'dec: {0:d};  hex: {0:x};  oct: {0:o};  bin: {0:b}'.format(_int)


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
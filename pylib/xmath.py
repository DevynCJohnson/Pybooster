#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Extra Math Functions

@file xmath.py
@package pybooster.xmath
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


# pylint: disable=C0103


from math import acos, asin, atan, cos, erf, log, sin, sqrt, tan
from random import choice
from typing import Iterable, Tuple, Union


__all__: list = [
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
    r'root14',
    r'root15',
    # NUMBER THEORY #
    r'factors',
    r'phi',
    # STATISTICS #
    r'avgoffset',
    r'is_improvement',
    r'is_improvement_meta',
    r'showpercent',
    # PROBABILITY #
    r'dice',
    r'dice8',
    r'coinflip',
    r'flipcoin',
    # SET THEORY #
    r'getdifference',
    r'getintersection',
    r'getsymdiff',
    r'getunion',
    r'issubset',
    # MISCELLANEOUS #
    r'clamp',
    r'int2many',
    r'degrees2radians',
    r'radians2degrees'
]


# CONSTANTS #


LARGE_NUMBERS: tuple = (
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


SMALL_NUMBERS: tuple = (
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


PI2: float = 1.5707963267948966
HALFPI: float = 1.5707963267948966
PIPI: float = 6.283185307179586
TWOPI: float = 6.283185307179586


# INVERSE CONSTANTS #


ONE_THIRD: float = 0.333333333333
ONE_FOURTH: float = 0.250000
ONE_FIFTH: float = 0.200000
ONE_SIXTH: float = 0.166666666667
ONE_SEVENTH: float = 0.142857142857
ONE_EIGHTH: float = 0.1250
ONE_NINTH: float = 0.111111111
ONE_TENTH: float = 0.100000
ONE_ELEVENTH: float = 0.09090909090909091
ONE_TWELFTH: float = 0.08333333333
ONE_THIRTEENTH: float = 0.076923077


# TRIGONOMETRIC FUNCTIONS #


def cot(_num: Union[float, int]) -> float:
    """Cotangent (Tangent Complement)

    >>> cot(90.0)
    -0.5012027833801532
    """
    return 1.0 / tan(_num)


def csc(_num: Union[float, int]) -> float:
    """Cosecant (Secant Complement)

    >>> csc(90.0)
    1.1185724071637084
    """
    return 1.0 / sin(_num)


def cvc(_num: Union[float, int]) -> float:
    """Versed Cosine Complement (covercos)

    >>> cvc(90.0)
    1.8939966636005579
    """
    return 1.0 + sin(_num)


def cvs(_num: Union[float, int]) -> float:
    """Versed Sine Complement (coversin, cosiv)

    >>> cvs(90.0)
    0.10600333639944215
    """
    return 1.0 - sin(_num)


def hcc(_num: Union[float, int]) -> float:
    """Half-Versed Cosine Complement (hacovercos)

    >>> hcc(90.0)
    0.9469983318002789
    """
    return (1.0 + sin(_num)) * 0.5


def hcv(_num: Union[float, int]) -> float:
    """Half-Versed Sine Complement (hacoversin)

    >>> hcv(90.0)
    0.053001668199721075
    """
    return (1.0 - sin(_num)) * 0.5


def hvc(_num: Union[float, int]) -> float:
    """Half-Versed Cosine (hac, havercos)

    >>> hvc(90.0)
    0.27596319193541496
    """
    return (1.0 + cos(_num)) * 0.5


def hvs(_num: Union[float, int]) -> float:
    """Half-Versed Sine (haversin, hv)

    >>> hvs(90.0)
    0.724036808064585
    """
    return (1.0 - cos(_num)) * 0.5


def sec(_num: Union[float, int]) -> float:
    """Secant (Reciprocal of cos)

    >>> sec(90.0)
    -2.2317761278577963
    """
    return 1.0 / cos(_num)


def siv(_num: Union[float, int]) -> float:
    """Versed Sine (versin, siv)

    >>> siv(90.0)
    1.44807361612917
    """
    return 1.0 - cos(_num)


def vcs(_num: Union[float, int]) -> float:
    """Versed Cosine (vercos)

    >>> vcs(90.0)
    0.5519263838708299
    """
    return 1.0 + cos(_num)


# INVERSE TRIGONOMETRIC FUNCTIONS #


def acot(_num: Union[float, int]) -> float:
    """Arccotangent

    >>> acot(90)
    0.011110653897607473
    """
    return atan(1.0 / _num)


def acsc(_num: Union[float, int]) -> float:
    """Arccosecant

    >>> acsc(90)
    0.011111339747498774
    """
    return asin(1.0 / _num)


def acvc(_num: Union[float, int]) -> float:
    """Versed Arccosine Complement (acovercos)

    >>> acvc(-0.2)
    0.9272952180016123
    """
    return asin(1.0 + _num)


def acvs(_num: Union[float, int]) -> float:
    """Versed Arcsine Complement (acoversin, acosiv)

    >>> acvs(0.5)
    0.5235987755982989
    """
    return asin(1.0 - _num)


def ahvc(_num: Union[float, int]) -> float:
    """Half-Versed Arccosine (ahac, ahavercos)

    >>> ahvc(0.1)
    2.498091544796509
    """
    return 2.0 * acos(sqrt(_num))


def ahvs(_num: Union[float, int]) -> float:
    """Half-Versed Arcsine (ahaversin, ahv)

    >>> ahvs(0.1)
    0.6435011087932844
    """
    return 2.0 * asin(sqrt(_num))


def asec(_num: Union[float, int]) -> float:
    """Arcsecant

    >>> asec(90)
    1.5596849870473979
    """
    return acos(1.0 / _num)


def asiv(_num: Union[float, int]) -> float:
    """Versed Arcsine (aver, aversin)

    >>> asiv(0.5)
    1.0471975511965979
    """
    return acos(1.0 - _num)


def avcs(_num: Union[float, int]) -> float:
    """Versed Arccosine (avercos)

    >>> avcs(90)
    -0.9943674609282015
    """
    return cos(1.0 + _num)


# EXTERNAL TRIGONOMETRIC FUNCTIONS #


def excsc(_num: Union[float, int]) -> float:
    """External Cosecant

    >>> excsc(90)
    0.11857240716370843
    """
    return (1.0 / sin(_num)) - 1.0


def exsec(_num: Union[float, int]) -> float:
    """External Secant

    >>> exsec(0.5)
    0.13949392732454902
    """
    return (1.0 / cos(_num)) - 1.0


# MISCELLANEOUS TRIGONOMETRIC FUNCTIONS #


def crd(_num: Union[float, int]) -> float:
    """Chord of a circle

    >>> crd(90)
    1.7018070490682369
    """
    return sin(_num * 0.5) * 2.0


# LOGARITHMS #


def ln(_num: Union[float, int]) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number)

    >>> ln(37)
    3.6109179126442243
    """
    return log(_num, 2.718281828459045)


def napierianlog(_num: Union[float, int]) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number)

    >>> napierianlog(37)
    3.6109179126442243
    """
    return log(_num, 2.718281828459045)


def naturallog(_num: Union[float, int]) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number)

    >>> naturallog(37)
    3.6109179126442243
    """
    return log(_num, 2.718281828459045)


# ROOTS #


def curt(_num: Union[float, int]) -> float:
    """Cubed Root

    >>> curt(37)
    3.332221851641943
    """
    return _num ** 0.333333333333


def root4(_num: Union[float, int]) -> float:
    """Hypercubed Root

    >>> root4(37)
    2.4663257145596607
    """
    return _num ** 0.25000


def root5(_num: Union[float, int]) -> float:
    """5th Root

    >>> root5(37)
    2.058924136478517
    """
    return _num ** 0.20000


def root6(_num: Union[float, int]) -> float:
    """6th Root

    >>> root6(37)
    1.8254374411756633
    """
    return _num ** 0.16666666666666667


def root7(_num: Union[float, int]) -> float:
    """7th Root

    >>> root7(37)
    1.6750540209862346
    """
    return _num ** 0.142857142857142857142857


def root8(_num: Union[float, int]) -> float:
    """8th Root

    >>> root8(37)
    1.57045398358553
    """
    return _num ** 0.125000000


def root9(_num: Union[float, int]) -> float:
    """9th Root

    >>> root9(37)
    1.4936355304176858
    """
    return _num ** 0.111111111111111111


def root10(_num: Union[float, int]) -> float:
    """10th Root

    >>> root10(37)
    1.4348951656753595
    """
    return _num ** 0.100000


def root11(_num: Union[float, int]) -> float:
    """11th Root

    >>> root11(37)
    1.3885572587844555
    """
    return _num ** 0.0909090909091


def root12(_num: Union[float, int]) -> float:
    """12th Root

    >>> root12(37)
    1.3510875029901763
    """
    return _num ** 0.0833333333


def root13(_num: Union[float, int]) -> float:
    """13th Root

    >>> root13(37)
    1.3201731686397005
    """
    return _num ** 0.07692307692307692307692307692


def root14(_num: Union[float, int]) -> float:
    """14th Root

    >>> root14(37)
    1.2942387805139492
    """
    return _num ** 0.07142857142857142857142857


def root15(_num: Union[float, int]) -> float:
    """15th Root

    >>> root15(37)
    1.2721747796233518
    """
    return _num ** 0.0666666666666666666667


# NUMBER THEORY #


def factors(_num: int) -> set:
    """Find prime factors

    >>> factors(64)
    {64, 1, 2, 32, 4, 8, 16}
    >>> factors(196)
    {1, 2, 98, 196, 4, 7, 14, 49, 28}
    """
    return {x for tup in ([i, _num // i] for i in range(1, int(_num ** 0.5) + 1) if _num % i == 0) for x in tup}


def phi(_num: float) -> float:
    """Euler's Totient Function counts the positive integers up to a given integer `_num` that are relatively prime to `_num`

    >>> phi(128)
    1.0
    >>> phi(64)
    1.0
    >>> phi(phi(128))
    0.841344746068543
    """
    return (1.0 + erf(_num / 1.4142135623730950488016887242096980785696718753769480732)) * 0.5


# STATISTICS #


def avgoffset(results_list: Iterable[Union[float, int]], target_list: Iterable[Union[float, int]]) -> float:
    """Compute the average offset of the list of results versus the target list

    >>> avgoffset([3.04606776, 6.04589842, 8.0331831, 9.03312666, 12.03295732, 12.99509362, 14.02024201, 15.99492428], [3.0, 6.0, 8.0, 9.0, 12.0, 13.0, 14.0, 16.0])
    0.02768217125000022
    >>> avgoffset([3.41, 6.03, 7.89, 8.36, 10.03, 12.22, 13.15, 13.3], [3.0, 6.0, 8.0, 9.0, 12.0, 13.0, 14.0, 16.0])
    0.93625
    """
    _offset: float = 0.0
    for x, y in zip(results_list, target_list):
        _offset += abs(x - y)  # type: ignore
    return _offset / len(results_list)  # type: ignore


def is_improvement(new_list: Iterable[Union[float, int]], best_list: Iterable[Union[float, int]], target_list: Iterable[Union[float, int]]) -> bool:
    """Return true if the new results are closer to the target than the previous results

    >>> is_improvement([3.04606776, 6.04589842, 8.0331831, 9.03312666, 12.03295732, 12.99509362, 14.02024201, 15.99492428], [3.41, 6.03, 7.89, 8.36, 10.03, 12.22, 13.15, 13.3], [3.0, 6.0, 8.0, 9.0, 12.0, 13.0, 14.0, 16.0])
    True
    """
    _newlist_mean_offset: float = 0.0
    for x, y in zip(new_list, target_list):
        _newlist_mean_offset += abs(x - y)  # type: ignore
    _newlist_mean_offset /= len(new_list)  # type: ignore
    _bestlist_mean_offset: float = 0.0
    for x, y in zip(best_list, target_list):
        _bestlist_mean_offset += abs(x - y)  # type: ignore
    _bestlist_mean_offset /= len(best_list)  # type: ignore
    return True if _bestlist_mean_offset > _newlist_mean_offset else False


def is_improvement_meta(new_list: Iterable, best_list: Iterable, target_list: Iterable) -> Tuple[bool, float, float]:
    """Return true as the first item in the tuple if the new results are closer to the target than the previous results; Returns a tuple containing the boolean value of the comparison, the lowest offset, and the largest offset

    >>> is_improvement_meta([3.04606776, 6.04589842, 8.0331831, 9.03312666, 12.03295732, 12.99509362, 14.02024201, 15.99492428], [3.41, 6.03, 7.89, 8.36, 10.03, 12.22, 13.15, 13.3], [3.0, 6.0, 8.0, 9.0, 12.0, 13.0, 14.0, 16.0])
    (True, 0.02768217125000022, 0.93625)
    """
    _newlist_mean_offset: float = avgoffset(new_list, target_list)
    _bestlist_mean_offset: float = avgoffset(best_list, target_list)
    return (True, _newlist_mean_offset, _bestlist_mean_offset) if _bestlist_mean_offset >= _newlist_mean_offset else (False, _bestlist_mean_offset, _newlist_mean_offset)


def showpercent(_portion: Union[float, int], _total: Union[float, int] = 100.0) -> str:
    """Convert a portion and total to a percentage

    Input int and/or float types and get a string

    >>> showpercent(37)
    '37.00%'
    >>> showpercent(37, 1000)
    '3.70%'
    >>> showpercent(73, 10)
    '730.00%'
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


# SET THEORY #


def getdifference(_iter1: Iterable, _iter2: Iterable) -> set:
    """Return the difference set of two iterables"""
    _set1: set = set(_iter1)
    _set2: set = set(_iter2)
    return _set1.difference(_set2)


def getintersection(_iter1: Iterable, _iter2: Iterable) -> set:
    """Return the intersection set of two iterables"""
    _set1: set = set(_iter1)
    _set2: set = set(_iter2)
    return _set1.intersection(_set2)


def getsymdiff(_iter1: Iterable, _iter2: Iterable) -> set:
    """Return the symmetric difference set of two iterables"""
    _set1: set = set(_iter1)
    _set2: set = set(_iter2)
    return _set1.symmetric_difference(_set2)


def getunion(_iter1: Iterable, _iter2: Iterable) -> set:
    """Return the union set of two iterables"""
    _set1: set = set(_iter1)
    _set2: set = set(_iter2)
    return _set1.union(_set2)


def issubset(_iter1: Iterable, _iter2: Iterable) -> bool:
    """Return True if _iter1 is a subset of _iter2"""
    _set1: set = set(_iter1)
    _set2: set = set(_iter2)
    return _set1.issubset(_set2)


# MISCELLANEOUS #


def clamp(_num: float, smallest: float = -1.0, largest: float = 1.0) -> float:
    """Clamp a value within the specified range

    >>> clamp(37.0, 17.0, 73.0)
    37.0
    >>> clamp(377.0, 17.0, 73.0)
    73.0
    >>> clamp(3.14159, 17.0, 73.0)
    17.0
    >>> clamp(73.0, 17.0, 73.0)
    73.0
    >>> clamp(3.14159, 3.14159, 73.0)
    3.14159
    """
    return largest if _num >= largest else smallest if _num <= smallest else _num


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

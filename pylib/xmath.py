#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Extra Math Functions.

@file xmath.py
@package pybooster.xmath
@version 2020.11.06
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


from functools import reduce
from fractions import Fraction
from math import acos, asin, atan, cos, erf, factorial, floor, log, sin, sqrt, tan
from operator import mul
from random import choice
from typing import Generator, Iterable, Tuple, Union


__all__: list = [
    # CONSTANTS #
    r'LARGE_NUMBERS',
    r'SMALL_NUMBERS',
    r'DELIAN_CONSTANT',
    r'GOLDEN_RATIO',
    r'HYPERBOLIC_TANGENT_OF_1',
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
    # CALCULUS #
    r'derivative',
    r'integral',
    # NUMBER THEORY #
    r'bernoulli',
    r'chebyshev',
    r'doublefactorial',
    r'factors',
    r'fibonacci',
    r'hexagonal',
    r'heptagonal',
    r'ishexagonal',
    r'ispoweroftwo',
    r'isprime',
    r'issquare',
    r'istriangular',
    r'primes_under',
    r'generate_primes',
    r'mersenne',
    r'mobius',
    r'pentatope',
    r'phi',
    r'prime_factors',
    r'pronic',
    r'radical',
    r'superfactorial',
    r'tetrahedral',
    r'triangular',
    r'von_mangoldt',
    # STATISTICS #
    r'avgoffset',
    r'gmean',
    r'hmean',
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


DELIAN_CONSTANT: float = 1.25992104989487316476
GOLDEN_RATIO: float = 1.6180339887498948482
HYPERBOLIC_TANGENT_OF_1: float = 0.76159415595576488812


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
    """Cotangent (Tangent Complement).

    >>> cot(90.0)
    -0.5012027833801532
    """
    return 1.0 / tan(_num)


def csc(_num: Union[float, int]) -> float:
    """Cosecant (Secant Complement).

    >>> csc(90.0)
    1.1185724071637084
    """
    return 1.0 / sin(_num)


def cvc(_num: Union[float, int]) -> float:
    """Versed Cosine Complement (covercos).

    >>> cvc(90.0)
    1.8939966636005579
    """
    return 1.0 + sin(_num)


def cvs(_num: Union[float, int]) -> float:
    """Versed Sine Complement (coversin, cosiv).

    >>> cvs(90.0)
    0.10600333639944215
    """
    return 1.0 - sin(_num)


def hcc(_num: Union[float, int]) -> float:
    """Half-Versed Cosine Complement (hacovercos).

    >>> hcc(90.0)
    0.9469983318002789
    """
    return (1.0 + sin(_num)) * 0.5


def hcv(_num: Union[float, int]) -> float:
    """Half-Versed Sine Complement (hacoversin).

    >>> hcv(90.0)
    0.053001668199721075
    """
    return (1.0 - sin(_num)) * 0.5


def hvc(_num: Union[float, int]) -> float:
    """Half-Versed Cosine (hac, havercos).

    >>> hvc(90.0)
    0.27596319193541496
    """
    return (1.0 + cos(_num)) * 0.5


def hvs(_num: Union[float, int]) -> float:
    """Half-Versed Sine (haversin, hv).

    >>> hvs(90.0)
    0.724036808064585
    """
    return (1.0 - cos(_num)) * 0.5


def sec(_num: Union[float, int]) -> float:
    """Secant (Reciprocal of cos).

    >>> sec(90.0)
    -2.2317761278577963
    """
    return 1.0 / cos(_num)


def siv(_num: Union[float, int]) -> float:
    """Versed Sine (versin, siv).

    >>> siv(90.0)
    1.44807361612917
    """
    return 1.0 - cos(_num)


def vcs(_num: Union[float, int]) -> float:
    """Versed Cosine (vercos).

    >>> vcs(90.0)
    0.5519263838708299
    """
    return 1.0 + cos(_num)


# INVERSE TRIGONOMETRIC FUNCTIONS #


def acot(_num: Union[float, int]) -> float:
    """Arccotangent.

    >>> acot(90)
    0.011110653897607473
    """
    return atan(1.0 / _num)


def acsc(_num: Union[float, int]) -> float:
    """Arccosecant.

    >>> acsc(90)
    0.011111339747498774
    """
    return asin(1.0 / _num)


def acvc(_num: Union[float, int]) -> float:
    """Versed Arccosine Complement (acovercos).

    >>> acvc(-0.2)
    0.9272952180016123
    """
    return asin(1.0 + _num)


def acvs(_num: Union[float, int]) -> float:
    """Versed Arcsine Complement (acoversin, acosiv).

    >>> acvs(0.5)
    0.5235987755982989
    """
    return asin(1.0 - _num)


def ahvc(_num: Union[float, int]) -> float:
    """Half-Versed Arccosine (ahac, ahavercos).

    >>> ahvc(0.1)
    2.498091544796509
    """
    return 2.0 * acos(sqrt(_num))


def ahvs(_num: Union[float, int]) -> float:
    """Half-Versed Arcsine (ahaversin, ahv).

    >>> ahvs(0.1)
    0.6435011087932844
    """
    return 2.0 * asin(sqrt(_num))


def asec(_num: Union[float, int]) -> float:
    """Arcsecant.

    >>> asec(90)
    1.5596849870473979
    """
    return acos(1.0 / _num)


def asiv(_num: Union[float, int]) -> float:
    """Versed Arcsine (aver, aversin).

    >>> asiv(0.5)
    1.0471975511965979
    """
    return acos(1.0 - _num)


def avcs(_num: Union[float, int]) -> float:
    """Versed Arccosine (avercos).

    >>> avcs(90)
    -0.9943674609282015
    """
    return cos(1.0 + _num)


# EXTERNAL TRIGONOMETRIC FUNCTIONS #


def excsc(_num: Union[float, int]) -> float:
    """External Cosecant.

    >>> excsc(90)
    0.11857240716370843
    """
    return (1.0 / sin(_num)) - 1.0


def exsec(_num: Union[float, int]) -> float:
    """External Secant.

    >>> exsec(0.5)
    0.13949392732454902
    """
    return (1.0 / cos(_num)) - 1.0


# MISCELLANEOUS TRIGONOMETRIC FUNCTIONS #


def crd(_num: Union[float, int]) -> float:
    """Chord of a circle.

    >>> crd(90)
    1.7018070490682369
    """
    return sin(_num * 0.5) * 2.0


# LOGARITHMS #


def ln(_num: Union[float, int]) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number).

    >>> ln(37)
    3.6109179126442243
    """
    return log(_num, 2.718281828459045)


def napierianlog(_num: Union[float, int]) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number).

    >>> napierianlog(37)
    3.6109179126442243
    """
    return log(_num, 2.718281828459045)


def naturallog(_num: Union[float, int]) -> float:
    """Natural/Napierian Logarithm (Base = Euler's Number).

    >>> naturallog(37)
    3.6109179126442243
    """
    return log(_num, 2.718281828459045)


# ROOTS #


def curt(_num: Union[float, int]) -> float:
    """Cubed Root.

    >>> curt(37)
    3.332221851641943
    """
    return _num ** 0.333333333333


def root4(_num: Union[float, int]) -> float:
    """Hypercubed Root.

    >>> root4(37)
    2.4663257145596607
    """
    return _num ** 0.25000


def root5(_num: Union[float, int]) -> float:
    """5th Root.

    >>> root5(37)
    2.058924136478517
    """
    return _num ** 0.20000


def root6(_num: Union[float, int]) -> float:
    """6th Root.

    >>> root6(37)
    1.8254374411756633
    """
    return _num ** 0.16666666666666667


def root7(_num: Union[float, int]) -> float:
    """7th Root.

    >>> root7(37)
    1.6750540209862346
    """
    return _num ** 0.142857142857142857142857


def root8(_num: Union[float, int]) -> float:
    """8th Root.

    >>> root8(37)
    1.57045398358553
    """
    return _num ** 0.125000000


def root9(_num: Union[float, int]) -> float:
    """9th Root.

    >>> root9(37)
    1.4936355304176858
    """
    return _num ** 0.111111111111111111


def root10(_num: Union[float, int]) -> float:
    """10th Root.

    >>> root10(37)
    1.4348951656753595
    """
    return _num ** 0.100000


def root11(_num: Union[float, int]) -> float:
    """11th Root.

    >>> root11(37)
    1.3885572587844555
    """
    return _num ** 0.0909090909091


def root12(_num: Union[float, int]) -> float:
    """12th Root.

    >>> root12(37)
    1.3510875029901763
    """
    return _num ** 0.0833333333


def root13(_num: Union[float, int]) -> float:
    """13th Root.

    >>> root13(37)
    1.3201731686397005
    """
    return _num ** 0.07692307692307692307692307692


def root14(_num: Union[float, int]) -> float:
    """14th Root.

    >>> root14(37)
    1.2942387805139492
    """
    return _num ** 0.07142857142857142857142857


def root15(_num: Union[float, int]) -> float:
    """15th Root.

    >>> root15(37)
    1.2721747796233518
    """
    return _num ** 0.0666666666666666666667


# CALCULUS #


def derivative(_func, _num: Union[float, int], method: str = r'central', step_size: float = 0.01) -> Union[float, int]:
    """Calculate the derivative of a function at variable `_num` using the choosen difference formula with the given step-size such as `_func'(_num)`.

    The difference formula must be one of "central", "backward", or "forward".

    >>> derivative(lambda x: x ** 4 + 7 * (x ** 3) + 8, 4, r'central')
    592.0022999999844
    >>> derivative(lambda x: x ** 4 + 7 * (x ** 3) + 8, 4, r'backward')
    590.2022989999864
    >>> derivative(lambda x: x ** 4 + 7 * (x ** 3) + 8, 4, r'forward')
    593.8023009999824
    """
    if method == r'backward':
        return (_func(_num) - _func(_num - step_size)) / step_size
    if method == r'forward':
        return (_func(_num + step_size) - _func(_num)) / step_size
    return (_func(_num + step_size) - _func(_num - step_size)) / (2.0 * step_size)


def integral(_func, _end: int, interval: Tuple[Union[float, int], Union[float, int]]) -> Union[float, int]:
    """Calculate the integral of the given function in the given interval.

    >>> integral(lambda x: x ** 2 + 8, 7, (2, 4))
    34.65306122448979
    >>> integral(lambda x: x ** 2 + 8, 17, (2, 4))
    34.6643598615917
    >>> integral(lambda x: x ** 2 + 8, 37, (2, 4))
    34.66617969320672
    """
    value: Union[float, int] = 0
    for _num in range(1, _end + 1):
        value += _func(interval[0] + ((_num - (1 / 2)) * ((interval[1] - interval[0]) / _end)))
    return ((interval[1] - interval[0]) / _end) * value


# NUMBER THEORY #


def bernoulli(_num: int) -> Fraction:
    """Produce the Bernoulli number for the given number.

    >>> bernoulli(0)
    Fraction(1, 1)
    >>> bernoulli(1)
    Fraction(1, 2)
    >>> bernoulli(2)
    Fraction(1, 6)
    >>> bernoulli(4)
    Fraction(-1, 30)
    >>> bernoulli(60)
    Fraction(-1215233140483755572040304994079820246041491, 56786730)
    """
    _num += 1
    _tmp_array: list = [Fraction(1, 1)] * _num
    for _num2 in range(_num):
        _tmp_array[_num2] = Fraction(1, _num2 + 1)
        for _j in range(_num2, 0, -1):
            _tmp_array[_j - 1] = _j * (_tmp_array[_j - 1] - _tmp_array[_j])
    return _tmp_array[0]


def chebyshev(_num: int) -> int:
    """The first Chebyshev function used to sum up all primes equal to or less than the given number.

    >>> chebyshev(1)
    0
    >>> chebyshev(2)
    2
    >>> chebyshev(3)
    5
    >>> chebyshev(4)
    5
    """
    _result: int = 0
    for _prime in primes_under(_num):
        _result += _prime
    return _result


def doublefactorial(_num: int) -> int:
    """Calculate the double factorial for the given number.

    >>> doublefactorial(1)
    1
    >>> doublefactorial(2)
    2
    >>> doublefactorial(3)
    3
    >>> doublefactorial(4)
    8
    >>> doublefactorial(5)
    15
    >>> doublefactorial(9)
    945
    >>> doublefactorial(13)
    135135
    """
    return reduce(mul, range(_num, 0, -2))


def factors(_num: int) -> set:
    """Factorize the given number.

    >>> factors(1)
    {1}
    >>> factors(2)
    {1, 2}
    >>> factors(5)
    {1, 5}
    >>> factors(12)
    {1, 2, 3, 4, 6, 12}
    >>> factors(15)
    {1, 3, 5, 15}
    >>> factors(17)
    {1, 17}
    >>> factors(30)
    {1, 2, 3, 5, 6, 10, 15, 30}
    >>> factors(64)
    {64, 1, 2, 32, 4, 8, 16}
    >>> factors(196)
    {1, 2, 98, 196, 4, 7, 14, 49, 28}
    """
    return {x for tup in ([i, _num // i] for i in range(1, int(_num ** 0.5) + 1) if _num % i == 0) for x in tup}


def fibonacci(_num: int) -> int:
    """Calculate the Fibonacci number.

    >>> fibonacci(0)
    0
    >>> fibonacci(1)
    1
    >>> fibonacci(2)
    1
    >>> fibonacci(3)
    2
    >>> fibonacci(4)
    3
    >>> fibonacci(5)
    5
    >>> fibonacci(6)
    8
    >>> fibonacci(7)
    13
    >>> fibonacci(8)
    21
    >>> fibonacci(9)
    34
    >>> fibonacci(10)
    55
    >>> fibonacci(11)
    89
    """
    return int(((GOLDEN_RATIO ** _num) - ((1.0 - GOLDEN_RATIO) ** _num)) / sqrt(5.0))


def hexagonal(_num: int) -> int:
    """Calculate the Nth hexagonal number.

    >>> hexagonal(1)
    1
    >>> hexagonal(2)
    6
    >>> hexagonal(10)
    190
    """
    _num2: int = _num + _num
    return int((_num2 * (_num2 - 1)) / 2)


def heptagonal(_num: int) -> int:
    """Calculate the Nth heptagonal number.

    >>> heptagonal(1)
    1
    >>> heptagonal(2)
    7
    >>> heptagonal(10)
    235
    """
    return int((((_num * _num) * 5) - (3 * _num)) / 2)


def isheptagonal(_num: int) -> bool:
    """Test if the given number is heptagonal.

    >>> isheptagonal(2)
    False
    >>> isheptagonal(7)
    True
    >>> isheptagonal(149)
    False
    >>> isheptagonal(1404)
    True
    """
    _test_num: float = (sqrt((40 * _num + 9)) + 3.0) * 0.1
    return _test_num == floor(_test_num)


def ishexagonal(_num: int) -> bool:
    """Test if the given number is hexagonal.

    >>> ishexagonal(2)
    False
    >>> ishexagonal(28)
    True
    >>> ishexagonal(29)
    False
    >>> ishexagonal(703)
    True
    """
    _test_num: float = ((sqrt((8 * _num + 1)) + 1.0) * 0.25)
    return _test_num == floor(_test_num)


def ispoweroftwo(_num: int) -> bool:
    """Test if the given number is a power-of-two.

    >>> ispoweroftwo(2)
    True
    >>> ispoweroftwo(3)
    False
    >>> ispoweroftwo(4)
    True
    >>> ispoweroftwo(28)
    False
    """
    return bool(_num != 0 and not _num & (_num - 1))


def isprime(_num: int) -> bool:
    """Test if the given number is prime.

    >>> isprime(3)
    True
    >>> isprime(4)
    False
    >>> isprime(6)
    False
    >>> isprime(7)
    True
    >>> isprime(37)
    True
    >>> isprime(137)
    True
    >>> isprime(373)
    True
    """
    if _num == 1:
        return True
    if _num % 2 == 0:
        return False
    for _num2 in range(3, _num, 2):
        if _num % _num2 == 0 and _num != _num2:
            return False
    return True


def issquare(_num: int) -> bool:
    """Test if the given number is square.

    >>> issquare(3)
    False
    >>> issquare(4)
    True
    >>> issquare(6)
    False
    >>> issquare(16)
    True
    """
    _test_num: float = floor(sqrt(_num) + 0.4)
    return (_test_num * _test_num) == _num


def istriangular(_num: int) -> bool:
    """Test if the given number is triangular.

    >>> istriangular(2)
    False
    >>> istriangular(21)
    True
    >>> istriangular(24)
    False
    >>> istriangular(231)
    True
    """
    return issquare((8 * _num + 1))


def primes_under(_num: int) -> set:
    """Generate a list of the prime numbers equal to or less than the given number.

    >>> primes_under(3)
    {2, 3}
    >>> primes_under(4)
    {2, 3}
    >>> primes_under(6)
    {2, 3, 5}
    >>> primes_under(7)
    {2, 3, 5, 7}
    >>> primes_under(37)
    {2, 3, 5, 37, 7, 11, 13, 17, 19, 23, 29, 31}
    >>> primes_under(137)
    {2, 3, 131, 5, 7, 137, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127}
    >>> primes_under(373)
    {257, 2, 3, 131, 5, 7, 263, 137, 11, 139, 13, 269, 271, 17, 19, 149, 277, 23, 151, 281, 283, 29, 157, 31, 163, 37, 293, 167, 41, 43, 173, 47, 179, 307, 53, 181, 311, 313, 59, 61, 317, 191, 193, 67, 197, 71, 199, 73, 331, 79, 337, 83, 211, 89, 347, 349, 223, 97, 353, 227, 101, 229, 103, 359, 233, 107, 109, 239, 367, 113, 241, 373, 251, 127}
    """
    if _num < 2:
        return set()
    if _num == 2:
        return {2}
    _primes: set = {_num2 for _num2 in range(3, _num + 1, 2) if isprime(_num2)}
    _primes.add(2)
    return _primes


def generate_primes() -> Generator:
    """Generate prime numbers in sequential order."""
    yield 2
    yield 3
    yield 5
    yield 7
    yield 11
    yield 13
    yield 17
    yield 19
    _prime: int = 23
    while True:
        if isprime(_prime):
            yield _prime
        _prime += 2


def mersenne(_num: int) -> int:
    """Calculate the Nth mersenne number.

    >>> mersenne(1)
    1
    >>> mersenne(2)
    3
    >>> mersenne(10)
    1023
    """
    return int((1 << _num) - 1)


def mobius(_num: int) -> int:
    """Möbius function from number theory and combinatorics.

    >>> mobius(1)
    1
    >>> mobius(2)
    -1
    >>> mobius(12)
    0
    >>> mobius(15)
    1
    >>> mobius(16)
    0
    >>> mobius(17)
    -1
    >>> mobius(29)
    -1
    >>> mobius(30)
    -1
    """
    _factors: tuple = prime_factors(_num)
    if any(divisor for divisor in _factors if _num % (divisor * divisor) == 0):
        return 0
    return -1 if len(_factors) % 2 else 1


def pentatope(_num: int) -> int:
    """Calculate the Nth pentatope number.

    >>> pentatope(1)
    1
    >>> pentatope(2)
    5
    >>> pentatope(10)
    715
    """
    return int((_num * (_num + 1) * (_num + 2) * (_num + 3)) / 24)


def phi(_num: float) -> float:
    """Euler's Totient Function counts the positive integers up to a given integer `_num` that are relatively prime to `_num`.

    >>> phi(128)
    1.0
    >>> phi(64)
    1.0
    >>> phi(phi(128))
    0.8413447460685429
    """
    return (1.0 + erf(_num / 1.4142135623730950488016887242096980785696718753769480732)) * 0.5


def prime_factors(_num: int) -> tuple:
    """Find prime factors.

    >>> prime_factors(1)
    ()
    >>> prime_factors(2)
    (2,)
    >>> prime_factors(5)
    (5,)
    >>> prime_factors(12)
    (3, 2, 2)
    >>> prime_factors(15)
    (5, 3)
    >>> prime_factors(17)
    (17,)
    >>> prime_factors(64)
    (2, 2, 2, 2, 2, 2)
    >>> prime_factors(196)
    (7, 7, 2, 2)
    """
    if _num < 2:
        return ()
    max_num: int = int(sqrt(_num))
    divisor: int = 1
    qnum: int = 3 if _num % 2 else 2
    while qnum <= max_num and _num % qnum:
        qnum = 1 + (divisor << 2) - ((divisor >> 1) << 1)
        divisor += 1
    if qnum <= max_num:
        return prime_factors(_num // qnum) + (qnum,)
    return (_num,)


def pronic(_num: int) -> int:
    """Calculate the Nth pronic number.

    >>> pronic(1)
    2
    >>> pronic(2)
    6
    >>> pronic(10)
    110
    """
    return (_num * _num) + _num


def radical(_num: int) -> int:
    """Calculate the radical of a number.

    >>> radical(1)
    1
    >>> radical(2)
    2
    >>> radical(3)
    3
    >>> radical(4)
    2
    >>> radical(5)
    5
    >>> radical(6)
    6
    >>> radical(7)
    7
    >>> radical(26)
    26
    >>> radical(29)
    29
    >>> radical(50)
    10
    >>> radical(504)
    42
    """
    _result: int = 1
    for _factor in set(prime_factors(_num)):
        _result *= _factor
    return _result


def superfactorial(_num: int) -> int:
    """Calculate the superfactorial for the given number.

    >>> superfactorial(1)
    1
    >>> superfactorial(2)
    2
    >>> superfactorial(3)
    12
    >>> superfactorial(4)
    288
    >>> superfactorial(5)
    34560
    >>> superfactorial(7)
    125411328000
    """
    return reduce(lambda _fact, _int: factorial(_int) * _fact, range(1, _num + 1, 1))


def tetrahedral(_num: int) -> int:
    """Calculate the Nth tetrahedral number.

    >>> tetrahedral(1)
    1
    >>> tetrahedral(2)
    4
    >>> tetrahedral(10)
    220
    """
    return int((_num * (_num + 1) * (_num + 2)) / 6)


def triangular(_num: int) -> int:
    """Calculate the Nth triangular number.

    >>> triangular(1)
    1
    >>> triangular(2)
    3
    >>> triangular(10)
    55
    """
    return int(((_num * (_num + 1)) / 2))


def von_mangoldt(_num: int) -> float:
    """Von Mangoldt function.

    >>> von_mangoldt(1)
    0.0
    >>> von_mangoldt(2)
    0.6931471805599453
    >>> von_mangoldt(3)
    1.0986122886681098
    >>> von_mangoldt(4)
    0.6931471805599453
    >>> von_mangoldt(5)
    1.6094379124341003
    >>> von_mangoldt(6)
    0.0
    >>> von_mangoldt(7)
    1.9459101490553132
    """
    for _prime in primes_under(_num):
        _test: Union[float, int] = log(_num, _prime)
        if int(_test) == _test:
            return log(_prime)
    return 0.0


# STATISTICS #


def avgoffset(results_list: Iterable[Union[float, int]], target_list: Iterable[Union[float, int]]) -> float:
    """Compute the average offset of the list of results versus the target list.

    >>> avgoffset([3.04606776, 6.04589842, 8.0331831, 9.03312666, 12.03295732, 12.99509362, 14.02024201, 15.99492428], [3.0, 6.0, 8.0, 9.0, 12.0, 13.0, 14.0, 16.0])
    0.02768217125000022
    >>> avgoffset([3.41, 6.03, 7.89, 8.36, 10.03, 12.22, 13.15, 13.3], [3.0, 6.0, 8.0, 9.0, 12.0, 13.0, 14.0, 16.0])
    0.93625
    """
    _offset: float = 0.0
    for x, y in zip(results_list, target_list):
        _offset += abs(x - y)  # type: ignore
    return _offset / len(results_list)  # type: ignore


def gmean(num_list: Iterable[Union[float, int]]) -> Union[float, int]:
    """Calculate the geometric mean of the numbers in the given list.

    >>> gmean([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
    4.528728688116765
    """
    return reduce(mul, num_list, 1) ** (1 / len(tuple(num_list)))


def hmean(num_list: Iterable[Union[float, int]]) -> Union[float, int]:
    """Calculate the harmonic mean of the numbers in the given list.
    >>> hmean([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
    3.414171521474055
    """
    return len(tuple(num_list)) / sum(1.0 / _num for _num in num_list)  # type: ignore


def is_improvement(new_list: Iterable[Union[float, int]], best_list: Iterable[Union[float, int]], target_list: Iterable[Union[float, int]]) -> bool:
    """Return true if the new results are closer to the target than the previous results.

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
    return bool(_bestlist_mean_offset > _newlist_mean_offset)


def is_improvement_meta(new_list: Iterable, best_list: Iterable, target_list: Iterable) -> Tuple[bool, float, float]:
    """Return true as the first item in the tuple if the new results are closer to the target than the previous results; Returns a tuple containing the boolean value of the comparison, the lowest offset, and the largest offset.

    >>> is_improvement_meta([3.04606776, 6.04589842, 8.0331831, 9.03312666, 12.03295732, 12.99509362, 14.02024201, 15.99492428], [3.41, 6.03, 7.89, 8.36, 10.03, 12.22, 13.15, 13.3], [3.0, 6.0, 8.0, 9.0, 12.0, 13.0, 14.0, 16.0])
    (True, 0.02768217125000022, 0.93625)
    """
    _newlist_mean_offset: float = avgoffset(new_list, target_list)
    _bestlist_mean_offset: float = avgoffset(best_list, target_list)
    return (True, _newlist_mean_offset, _bestlist_mean_offset) if _bestlist_mean_offset >= _newlist_mean_offset else (False, _bestlist_mean_offset, _newlist_mean_offset)


def showpercent(_portion: Union[float, int], _total: Union[float, int] = 100.0) -> str:
    """Convert a portion and total to a percentage.

    Input int and/or float types and get a string

    >>> showpercent(37)
    '37.00%'
    >>> showpercent(37, 1000)
    '3.70%'
    >>> showpercent(73, 10)
    '730.00%'
    """
    return fr'{float(_portion) / float(_total):.2%}'


# PROBABILITY #


def dice() -> int:
    """Roll a die and return a random integer (1-6)."""
    return choice((1, 2, 3, 4, 5, 6))  # nosec


def dice8() -> int:
    """Roll an 8-sided die and return a random integer (1-8)."""
    return choice((1, 2, 3, 4, 5, 6, 7, 8))  # nosec


def coinflip() -> str:
    """Flip a coin and return a string of heads or tails."""
    return choice((r'heads', r'tails'))  # nosec


def flipcoin() -> str:
    """Flip a coin and return a string of heads or tails."""
    return choice((r'heads', r'tails'))  # nosec


# SET THEORY #


def getdifference(_iter1: Iterable, _iter2: Iterable) -> set:
    """Return the difference set of two iterables."""
    return set(_iter1).difference(set(_iter2))


def getintersection(_iter1: Iterable, _iter2: Iterable) -> set:
    """Return the intersection set of two iterables."""
    return set(_iter1).intersection(set(_iter2))


def getsymdiff(_iter1: Iterable, _iter2: Iterable) -> set:
    """Return the symmetric difference set of two iterables."""
    return set(_iter1).symmetric_difference(set(_iter2))


def getunion(_iter1: Iterable, _iter2: Iterable) -> set:
    """Return the union set of two iterables."""
    return set(_iter1).union(set(_iter2))


def issubset(_iter1: Iterable, _iter2: Iterable) -> bool:
    """Return True if _iter1 is a subset of _iter2."""
    return set(_iter1).issubset(set(_iter2))


# MISCELLANEOUS #


def clamp(_num: float, smallest: float = -1.0, largest: float = 1.0) -> float:
    """Clamp a value within the specified range.

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
    """Convert a decimal number to mulitple number base types.

    The returned value is a table in the form of a string

    >>> int2many(37)
    'dec: 37;  hex: 25;  oct: 45;  bin: 100101'
    """
    return fr'dec: {_int:d};  hex: {_int:x};  oct: {_int:o};  bin: {_int:b}'


def degrees2radians(_degrees: float) -> float:
    """Convert Degrees to Radians `(PI / 180) * Degrees`.

    >>> degrees2radians(90.0)
    1.5707963267948701
    """
    return 0.017453292519943 * _degrees


def radians2degrees(_radians: float) -> float:
    """Convert Radians to Degrees `(180 / PI) * Radians`.

    >>> radians2degrees(30.0)
    1718.8733853924696
    """
    return 57.29577951308232 * _radians

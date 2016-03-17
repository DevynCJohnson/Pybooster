#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
Created by Devyn Collier Johnson
<DevynCJohnson@Gmail.com>
LGPLv3 License
-- --
PyBooster - Various Extras for Python3
pybooster.pronouns
-- --
Pronouns
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

import re


__all__ = [
    # CONSTANTS
    'FIRST_THIRD',
    'FIRST_SECOND',
    'SECOND_THIRD',
    'GENDER_SWAP',
    # FUNCTIONS
    'swap_pronouns',
    'pronoun',
    'pronoun2',
    'pronoun3',
    'pronounf',
    'pronoun2f',
    'pronoun3f',
    'swap_genders',
]

__author__ = 'Devyn Collier Johnson'
__copyright__ = 'LGPLv3'
__version__ = '2016.03.09'


# CONSTANTS


FIRST_THIRD = (
    ('I', 'he or she'),
    ('me', 'him or her'),
    ('mine', 'his or hers'),
    ('my', 'his or her'),
    ('myself', 'him or herself'),
    ('he', 'I'),
    ('she', 'I'),
    ('his', 'mine'),
    ('hers', 'mine'),
    ('himself', 'myself'),
    ('herself', 'myself'),
    ('they', 'we'),
    ('we', 'they'),
)


FIRST_SECOND = (
    ('me', 'you'),
    ('you', 'me'),
    ('I', 'you'),
    ('you are', 'I am'),
    ('are you', 'am I'),
    ('your', 'my'),
    ('my', 'your'),
    ('yours', 'mine'),
    ('mine', 'yours'),
    ('you were', 'I was'),
    ('yourself', 'myself'),
    ('myself', 'yourself'),
)


SECOND_THIRD = (
    ('you', 'them'),
    ('them', 'you'),
    ('yours', 'theirs'),
    ('theirs', 'yours'),
    ('yourself', 'themselves'),
    ('themselves', 'yourself'),
    ('you are', 'they are'),
    ('they are', 'you are'),
    ('you were', 'they were'),
    ('they were', 'you were'),
    ('you have', 'they have'),
    ('they have', 'you have'),
    ('you had', 'they had'),
    ('they had', 'you had'),
)


GENDER_SWAP = (
    (r'him', r'her'),
    (r'her', r'him'),
    (r'he', r'she'),
    (r'she', r'he'),
    (r'his', r'her'),
)


# FUNCTIONS


def swap_pronouns(_str: str, _pronouns: tuple) -> str:
    """Swap pronouns"""
    _swap = []
    for i in _pronouns:
        _test = re.search(i[0], _str, re.I)
        if _test is not None:
            _swap.append(i)
    if not len(_swap):
        return _str
    else:
        for i in _swap:
            _str = re.sub(i[0], i[1], _str, re.I)
        return _str


def pronoun(_str: str) -> str:
    """Swap first and third person pronouns"""
    return swap_pronouns(_str, FIRST_THIRD)


def pronoun2(_str: str) -> str:
    """Swap first and second person pronouns"""
    return swap_pronouns(_str, FIRST_SECOND)


def pronoun3(_str: str) -> str:
    """Swap second and third person pronouns"""
    return swap_pronouns(_str, SECOND_THIRD)


def pronounf(_str: str) -> str:
    """Swap first and third person pronouns and replace spaces with %20"""
    return swap_pronouns(_str, FIRST_THIRD).replace(r' ', r'%20')


def pronoun2f(_str: str) -> str:
    """Swap first and second person pronouns and replace spaces with %20"""
    return swap_pronouns(_str, FIRST_SECOND).replace(r' ', r'%20')


def pronoun3f(_str: str) -> str:
    """Swap second and third person pronouns and replace spaces with %20"""
    return swap_pronouns(_str, SECOND_THIRD).replace(r' ', r'%20')


def swap_genders(_str: str) -> str:
    """Swap gender pronouns"""
    return swap_pronouns(_str, GENDER_SWAP)

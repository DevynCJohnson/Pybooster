#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Pronoun-related functions and constants

@file pronouns.py
@package pybooster.pronouns
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


try:  # Regular Expression module
    import regex as re  # noqa: E402  # pylint: disable=C0411
except ImportError:
    import re  # noqa: E402  # pylint: disable=C0411


__all__ = [
    # CONSTANTS #
    r'FIRST_THIRD',
    r'FIRST_SECOND',
    r'SECOND_THIRD',
    r'GENDER_SWAP',
    # FUNCTIONS #
    r'swap_pronouns',
    r'pronoun',
    r'pronoun2',
    r'pronoun3',
    r'pronounf',
    r'pronoun2f',
    r'pronoun3f',
    r'swap_genders'
]


# CONSTANTS #


FIRST_THIRD = (
    (r'I', r'he or she'),
    (r'me', r'him or her'),
    (r'mine', r'his or hers'),
    (r'my', r'his or her'),
    (r'myself', r'him or herself'),
    (r'he', r'I'),
    (r'she', r'I'),
    (r'his', r'mine'),
    (r'hers', r'mine'),
    (r'himself', r'myself'),
    (r'herself', r'myself'),
    (r'they', r'we'),
    (r'we', r'they')
)


FIRST_SECOND = (
    (r'me', r'you'),
    (r'you', r'me'),
    (r'I', r'you'),
    (r'you are', r'I am'),
    (r'are you', r'am I'),
    (r'your', r'my'),
    (r'my', r'your'),
    (r'yours', r'mine'),
    (r'mine', r'yours'),
    (r'you were', r'I was'),
    (r'yourself', r'myself'),
    (r'myself', r'yourself')
)


SECOND_THIRD = (
    (r'you', r'them'),
    (r'them', r'you'),
    (r'yours', r'theirs'),
    (r'theirs', r'yours'),
    (r'yourself', r'themselves'),
    (r'themselves', r'yourself'),
    (r'you are', r'they are'),
    (r'they are', r'you are'),
    (r'you were', r'they were'),
    (r'they were', r'you were'),
    (r'you have', r'they have'),
    (r'they have', r'you have'),
    (r'you had', r'they had'),
    (r'they had', r'you had')
)


GENDER_SWAP = (
    (r'him', r'her'),
    (r'her', r'him'),
    (r'he', r'she'),
    (r'she', r'he'),
    (r'his', r'her')
)


# FUNCTIONS #


def swap_pronouns(_str: str, _pronouns: tuple) -> str:
    """Swap pronouns"""
    _swap = []
    for i in _pronouns:
        _test = re.search(i[0], _str, re.I)
        if _test is not None:
            _swap.append(i)
    if not _swap:
        return _str
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

#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Pronoun-related functions and constants

@file pronouns.py
@package pybooster.pronouns
@version 2018.08.23
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
    (r'he', r'I'),
    (r'hers', r'mine'),
    (r'herself', r'myself'),
    (r'himself', r'myself'),
    (r'his', r'mine'),
    (r'I', r'he or she'),
    (r'me', r'him or her'),
    (r'mine', r'his or hers'),
    (r'my', r'his or her'),
    (r'myself', r'him or herself'),
    (r'she', r'I'),
    (r'they', r'we'),
    (r'we', r'they')
)


FIRST_SECOND = (
    (r'are you', r'am I'),
    (r'I', r'you'),
    (r'me', r'you'),
    (r'mine', r'yours'),
    (r'my', r'your'),
    (r'myself', r'yourself'),
    (r'you are', r'I am'),
    (r'you were', r'I was'),
    (r'you', r'me'),
    (r'your', r'my'),
    (r'yours', r'mine'),
    (r'yourself', r'myself')
)


SECOND_THIRD = (
    (r'theirs', r'yours'),
    (r'them', r'you'),
    (r'themselves', r'yourself'),
    (r'they are', r'you are'),
    (r'they had', r'you had'),
    (r'they have', r'you have'),
    (r'they were', r'you were'),
    (r'you are', r'they are'),
    (r'you had', r'they had'),
    (r'you have', r'they have'),
    (r'you were', r'they were'),
    (r'you', r'them'),
    (r'yours', r'theirs'),
    (r'yourself', r'themselves')
)


GENDER_SWAP = (
    (r'he', r'she'),
    (r'her', r'him'),
    (r'him', r'her'),
    (r'his', r'her'),
    (r'she', r'he')
)


# FUNCTIONS #


def swap_pronouns(_str: str, _pronouns: tuple) -> str:
    """Swap pronouns

    >>> swap_pronouns('I was running a test.', FIRST_THIRD)
    'he or she was running a test.'
    """
    _swap: list = []
    _test: list = _str.replace(r'.', r' . ').replace(r'!', r' ! ').replace(r'?', r' ? ').split(r' ')
    _flag: bool = False
    for _word in _test:
        for _pair in _pronouns:
            if _word.lower() == _pair[0].lower():
                _swap.append(_pair[1])
                _flag = True
                break
        if _flag:
            _flag = False
            continue
        _swap.append(_word)
    return r' '.join(_swap).replace(r' .', r'. ').replace(r' !', r'! ').replace(r' ?', r'? ').strip()


def pronoun(_str: str) -> str:
    """Swap first and third person pronouns

    >>> pronoun('I was running a test.')
    'he or she was running a test.'
    """
    return swap_pronouns(_str, FIRST_THIRD)


def pronoun2(_str: str) -> str:
    """Swap first and second person pronouns

    >>> pronoun2('This test is mine.')
    'This test is yours.'
    """
    return swap_pronouns(_str, FIRST_SECOND)


def pronoun3(_str: str) -> str:
    """Swap second and third person pronouns

    >>> pronoun3('This test is yours.')
    'This test is theirs.'
    """
    return swap_pronouns(_str, SECOND_THIRD)


def pronounf(_str: str) -> str:
    """Swap first and third person pronouns and replace spaces with %20

    >>> pronounf('I was running a test.')
    'he%20or%20she%20was%20running%20a%20test.'
    """
    return swap_pronouns(_str, FIRST_THIRD).replace(r' ', r'%20')


def pronoun2f(_str: str) -> str:
    """Swap first and second person pronouns and replace spaces with %20

    >>> pronoun2f('This test is mine.')
    'This%20test%20is%20yours.'
    """
    return swap_pronouns(_str, FIRST_SECOND).replace(r' ', r'%20')


def pronoun3f(_str: str) -> str:
    """Swap second and third person pronouns and replace spaces with %20

    >>> pronoun3f('This test is yours.')
    'This%20test%20is%20theirs.'
    """
    return swap_pronouns(_str, SECOND_THIRD).replace(r' ', r'%20')


def swap_genders(_str: str) -> str:
    """Swap gender pronouns

    >>> swap_genders('He ran the test.')
    'she ran the test.'
    """
    return swap_pronouns(_str, GENDER_SWAP)

#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Bitwise operation functions.

@file bitwise.py
@package pybooster.bitwise
@version 2019.07.14
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


from typing import Optional


__all__: list = [
    # FUNCTIONS #
    r'bit_and',
    r'bit_or',
    r'bit_xor'
]


# FUNCTIONS #


def bit_and(_num0: str, _num1: str, _base: int = 10) -> Optional[str]:
    """Bitwise ANDing.

    Given the decimal representation of two numbers as a string, return the ANDed number as a string

    >>> bit_and('53', '72')
    '0'
    """
    if not isinstance(_num0, str) or not isinstance(_num1, str):
        return None
    if _base == 2:  # Binary
        return bin(int(_num0, 2) & int(_num1, 2)).replace(r'0b', r'')
    if _base == 8:  # Octal
        return oct(int(_num0, 8) & int(_num1, 8)).replace(r'0o', r'')
    if _base == 10:  # Decimal
        return str(int(_num0) & int(_num1))
    if _base == 16:  # Hexadecimal
        return hex(int(_num0, 16) & int(_num1, 16)).replace(r'0x', r'')
    return None


def bit_or(_num0: str, _num1: str, _base: int = 10) -> Optional[str]:
    r"""Bitwise ORing.

    Given the decimal representation of two numbers as a string, return the ORed number as a string

    >>> bit_or('17', '37', 10)
    '53'
    >>> bit_or('53', '72')
    '125'
    >>> bit_or('53', '72', 17)
    <BLANKLINE>
    """
    if not isinstance(_num0, str) or not isinstance(_num1, str):
        return None
    if _base == 2:  # Binary
        return bin(int(_num0, 2) | int(_num1, 2)).replace(r'0b', r'')
    if _base == 8:  # Octal
        return oct(int(_num0, 8) | int(_num1, 8)).replace(r'0o', r'')
    if _base == 10:  # Decimal
        return str(int(_num0) | int(_num1))
    if _base == 16:  # Hexadecimal
        return hex(int(_num0, 16) | int(_num1, 16)).replace(r'0x', r'')
    return None


def bit_xor(_num0: str, _num1: str, _base: int = 10) -> Optional[str]:
    """Bitwise XORing.

    Given the decimal representation of two numbers as a string, return the XORed number as a string

    >>> bit_xor('53', '72')
    '125'
    """
    if not isinstance(_num0, str) or not isinstance(_num1, str):
        return None
    if _base == 2:  # Binary
        return bin(int(_num0, 2) ^ int(_num1, 2)).replace(r'0b', r'')
    if _base == 8:  # Octal
        return oct(int(_num0, 8) ^ int(_num1, 8)).replace(r'0o', r'')
    if _base == 10:  # Decimal
        return str(int(_num0) ^ int(_num1))
    if _base == 16:  # Hexadecimal
        return hex(int(_num0, 16) ^ int(_num1, 16)).replace(r'0x', r'')
    return None

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
@file bitwise.py
@package pybooster.bitwise
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@brief Bitwise Operations
@version 2016.03.18

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


__all__ = [
    # FUNCTIONS
    'bit_and',
    'bit_or',
    'bit_xor',
]


# FUNCTIONS


def bit_and(_num0: str, _num1: str, _base: int) -> str:
    """Bitwise ANDing
    Given the decimal representation of two numbers as a string,
    return the ANDed number as a string
    """
    if not isinstance(_num0, str) or not isinstance(_num0, str):
        return None
    if _base == 2:  # Binary
        _num = int(_num0, 2) & int(_num1, 2)
        _num = bin(_num).replace('0b', '')
    elif _base == 8:  # Octal
        _num = int(_num0, 8) & int(_num1, 8)
        _num = oct(_num).replace('0o', '')
    elif _base == 10:  # Decimal
        _num = int(_num0) & int(_num1)
    elif _base == 16:  # Hexadecimal
        _num = int(_num0, 16) & int(_num1, 16)
        _num = hex(_num).replace('0x', '')
    else:
        return None
    return _num


def bit_or(_num0: str, _num1: str, _base: int) -> str:
    """Bitwise ORing
    Given the decimal representation of two numbers as a string,
    return the ORed number as a string
    """
    if not isinstance(_num0, str) or not isinstance(_num0, str):
        return None
    if _base == 2:  # Binary
        _num = int(_num0, 2) | int(_num1, 2)
        _num = bin(_num).replace('0b', '')
    elif _base == 8:  # Octal
        _num = int(_num0, 8) | int(_num1, 8)
        _num = oct(_num).replace('0o', '')
    elif _base == 10:  # Decimal
        _num = int(_num0) | int(_num1)
    elif _base == 16:  # Hexadecimal
        _num = int(_num0, 16) | int(_num1, 16)
        _num = hex(_num).replace('0x', '')
    else:
        return None
    return _num


def bit_xor(_num0: str, _num1: str, _base: int) -> str:
    """Bitwise XORing
    Given the decimal representation of two numbers as a string,
    return the XORed number as a string
    """
    if not isinstance(_num0, str) or not isinstance(_num0, str):
        return None
    if _base == 2:  # Binary
        _num = int(_num0, 2) ^ int(_num1, 2)
        _num = bin(_num).replace('0b', '')
    elif _base == 8:  # Octal
        _num = int(_num0, 8) ^ int(_num1, 8)
        _num = oct(_num).replace('0o', '')
    elif _base == 10:  # Decimal
        _num = int(_num0) ^ int(_num1)
    elif _base == 16:  # Hexadecimal
        _num = int(_num0, 16) ^ int(_num1, 16)
        _num = hex(_num).replace('0x', '')
    else:
        return None
    return _num

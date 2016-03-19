#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
@file financial.py
@package pybooster.financial
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@brief Functions related to finances, banking, economics, accounting, etc.
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
    'compounded_interest',
    'compounded_ending_balance',
    'simple_interest',
    'simple_ending_balance',
]


# FUNCTIONS


def compounded_interest(principal: float, interest: float, compound_frequency: float) -> float:
    """Return the compounded interest earned given the principal, interest, and compound frequency"""
    return principal * (((1 + compound_frequency) ** interest) - 1)


def compounded_ending_balance(principal: float, interest: float, compound_frequency: float) -> float:
    """Return the ending balance of compounded interest earned given the principal, interest, and compound frequency"""
    return principal * (((1 + compound_frequency) ** interest))


def simple_interest(principal: float, interest: float, time: float) -> float:
    """Return the simple interest earned given the principal, interest, and time"""
    return principal * time * interest


def simple_ending_balance(principal: float, interest: float, time: float) -> float:
    """Return the ending balance of simple interest given the principal, interest, and time"""
    return principal * (1 + (time * interest))

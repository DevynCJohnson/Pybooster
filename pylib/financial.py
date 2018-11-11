#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Functions related to finances, banking, economics, accounting, etc.

@file financial.py
@package pybooster.financial
@version 2018.11.11
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


__all__: list = [
    r'compounded_interest',
    r'compounded_ending_balance',
    r'simple_interest',
    r'simple_ending_balance'
]


def compounded_interest(principal: float, interest: float, compound_frequency: float) -> float:
    """Return the compounded interest earned given the principal, interest, and compound frequency"""
    return principal * (((1.0 + compound_frequency) ** interest) - 1.0)


def compounded_ending_balance(principal: float, interest: float, compound_frequency: float) -> float:
    """Return the ending balance of compounded interest earned given the principal, interest, and compound frequency"""
    return principal * (((1.0 + compound_frequency) ** interest))


def simple_interest(principal: float, interest: float, time: float) -> float:
    """Return the simple interest earned given the principal, interest, and time"""
    return principal * time * interest


def simple_ending_balance(principal: float, interest: float, time: float) -> float:
    """Return the ending balance of simple interest given the principal, interest, and time"""
    return principal * (1.0 + (time * interest))

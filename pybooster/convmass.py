#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
@file convmass.py
@package pybooster.convmass
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@brief Measurement (Mass) Conversions
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
    # KILOGRAMS
    'kilogram2pound',
]


# KILOGRAMS


def kilogram2pound(_mass: int or float, _round: int=3) -> float:
    """Kilograms -> Pounds"""
    return round(_mass * 2.2046, _round)

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
Created by Devyn Collier Johnson
<DevynCJohnson@Gmail.com>
LGPLv3 License
-- --
PyBooster - Various Extras for Python3
pybooster.convspeed
-- --
Measurement (Speed) Conversions
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

__all__ = [
    # MILES PER HOUR
    'mph2kph',
]

__author__ = 'Devyn Collier Johnson'
__copyright__ = 'LGPLv3'
__version__ = '2016.03.18'


# MILES PER HOUR


def mph2kph(_speed: int or float, _round: int=3) -> float:
    """Miles per Hour -> Kilometers per Hour"""
    return round(_speed * 1.6093, _round)

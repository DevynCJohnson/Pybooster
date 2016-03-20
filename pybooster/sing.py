#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""@brief Functions related to generating lyrics
@file sing.py
@package pybooster.sing
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@version 2016.03.20

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
    'banana_song',
]


# FUNCTIONS


def banana_song(_name: str) -> str:
    """Return the lyrics of the Banana Song using the given name"""
    _name = _name.capitalize()
    return _name + r', ' + _name + r', bo-b' + _name[1:] + r', Banana-fana fo-f' + _name[1:] + r', Fee-Fi-mo-m' + _name[1:] + r', ' + _name + r'!'

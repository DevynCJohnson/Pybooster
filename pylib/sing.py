#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Functions related to generating lyrics

@file sing.py
@package pybooster.sing
@version 2018.10.02
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
    r'banana_song'
]


def banana_song(_name: str) -> str:
    """Return the lyrics of the Banana Song using the given name

    >>> banana_song('Bridgette')
    'Bridgette, Bridgette, bo-bridgette, Banana-fana fo-fridgette, Fee-Fi-mo-mridgette, Bridgette!'
    >>> banana_song('tucker')
    'Tucker, Tucker, bo-bucker, Banana-fana fo-fucker, Fee-Fi-mo-mucker, Tucker!'
    """
    _name = _name.capitalize()
    return _name + r', ' + _name + r', bo-b' + _name[1:] + r', Banana-fana fo-f' + _name[1:] + r', Fee-Fi-mo-m' + _name[1:] + r', ' + _name + r'!'

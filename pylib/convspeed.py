#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Speed measurement conversions.

@file convspeed.py
@package pybooster.convspeed
@version 2020.08.01
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


from typing import Union


__all__: list = [
    # KILOMETERS PER HOUR #
    r'kilometersperhour2milesperhour',
    # MILES PER HOUR #
    r'milesperhour2kilometersperhour'
]


# KILOMETERS PER HOUR #


def kilometersperhour2milesperhour(_speed: Union[float, int], _round: int = 3) -> float:
    """Kilometers per Hour -> Miles per Hour."""
    return round(_speed * 0.62137, _round)


# MILES PER HOUR #


def milesperhour2kilometersperhour(_speed: Union[float, int], _round: int = 3) -> float:
    """Miles per Hour -> Kilometers per Hour."""
    return round(_speed * 1.6093, _round)

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""@brief Astronomy Data
@file astronomy.py
@package pybooster.astronomy
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@version 2016.03.20

@section DESCRIPTION
The planet properties are dictionaries that use lowercase key names.

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
    # LISTS
    'PLANETS',
    'DWARF_PLANETS',
    'PLANET_SYMBOLS',
    # PLANET PROPERTIES
    'MERCURY',
    'VENUS',
    'EARTH',
    'CERES',
    'MARS',
    'JUPITER',
    'SATURN',
    'URANUS',
    'NEPTUNE',
    'PLUTO',
]


# LISTS


PLANETS = (
    r'Mercury',
    r'Venus',
    r'Earth',
    r'Mars',
    r'Jupiter',
    r'Saturn',
    r'Uranus',
    r'Neptune'
)


DWARF_PLANETS = (
    r'Ceres',
    r'Pluto',
    r'Haumea',
    r'Makemake',
    r'Eris'
)


"""PLANET_SYMBOLS is a dictionary that uses uppercase key names."""
PLANET_SYMBOLS = {
    r'SUN': r'☉',
    r'MOON': r'☽',
    r'MERCURY': r'☿',
    r'VENUS': r'♀',
    r'EARTH': r'♁',
    r'MARS': r'♂',
    r'CERES': r'⚳',
    r'JUPITER': r'♃',
    r'SATURN': r'♄',
    r'URANUS': r'♅',
    r'NEPTUNE': r'♆',
    r'PLUTO': r'♇'
}


# PLANET PROPERTIES


MERCURY = {
    r'symbol': r'☿',
    r'aphelion': (0.466697, r'AU'),
    r'perihelion': (0.307499, r'AU'),
    r'semimajor_axis': (0.387098, r'AU'),
    r'eccentricity': 0.205630,
}


VENUS = {
    r'symbol': r'♀',
    r'aphelion': (0.728213, r'AU'),
    r'perihelion': (0.718440, r'AU'),
    r'semimajor_axis': (0.723327, r'AU'),
    r'eccentricity': 0.0067,
}


EARTH = {
    r'symbol': r'♁',
    r'aphelion': (1.01559, r'AU'),
    r'perihelion': (0.9832687, r'AU'),
    r'semimajor_axis': (1.00000261, r'AU'),
    r'eccentricity': 0.01671123,
}


MARS = {
    r'symbol': r'♂',
    r'aphelion': (1.6660, r'AU'),
    r'perihelion': (1.3814, r'AU'),
    r'semimajor_axis': (1.523679, r'AU'),
    r'eccentricity': 0.0935,
}


CERES = {
    r'symbol': r'⚳',
}


JUPITER = {
    r'symbol': r'♃',
    r'aphelion': (5.458104, r'AU'),
    r'perihelion': (4.950429, r'AU'),
    r'semimajor_axis': (5.204267, r'AU'),
    r'eccentricity': 0.048775,
}


SATURN = {
    r'symbol': r'♄',
    r'aphelion': (10.11595804, r'AU'),
    r'perihelion': (9.04807635, r'AU'),
    r'semimajor_axis': (9.5820172, r'AU'),
    r'eccentricity': 0.055723219,
}


URANUS = {
    r'symbol': r'♅',
    r'aphelion': (20.095371, r'AU'),
    r'perihelion': (18.283135, r'AU'),
    r'semimajor_axis': (19.189253, r'AU'),
    r'eccentricity': 0.047220087,
}


NEPTUNE = {
    r'symbol': r'♆',
    r'aphelion': (30.331855, r'AU'),
    r'perihelion': (29.809946, r'AU'),
    r'semimajor_axis': (30.070900, r'AU'),
    r'eccentricity': 0.00867797,
}


PLUTO = {
    r'symbol': r'♇',
}

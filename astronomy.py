#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
Created by Devyn Collier Johnson
<DevynCJohnson@Gmail.com>
LGPLv3 License
-- --
PyBooster - Various Extras for Python3
pybooster.astronomy
-- --
Astronomy Data
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
-- --
The planet properties are dictionaries that use lowercase key names.
PLANET_SYMBOLS is a dictionary that uses uppercase key names.
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

__author__ = 'Devyn Collier Johnson'
__copyright__ = 'LGPLv3'
__version__ = '2016.03.09'


# LISTS


PLANETS = (
    'Mercury',
    'Venus',
    'Earth',
    'Mars',
    'Jupiter',
    'Saturn',
    'Uranus',
    'Neptune'
)


DWARF_PLANETS = (
    'Ceres',
    'Pluto',
    'Haumea',
    'Makemake',
    'Eris'
)


PLANET_SYMBOLS = {
    'SUN': '☉',
    'MOON': '☽',
    'MERCURY': '☿',
    'VENUS': '♀',
    'EARTH': '♁',
    'MARS': '♂',
    'CERES': '⚳',
    'JUPITER': '♃',
    'SATURN': '♄',
    'URANUS': '♅',
    'NEPTUNE': '♆',
    'PLUTO': '♇'
}


# PLANET PROPERTIES


MERCURY = {
    'symbol': '☿',
    'aphelion': (0.466697, 'AU'),
    'perihelion': (0.307499, 'AU'),
    'semimajor_axis': (0.387098, 'AU'),
    'eccentricity': 0.205630,
}


VENUS = {
    'symbol': '♀',
    'aphelion': (0.728213, 'AU'),
    'perihelion': (0.718440, 'AU'),
    'semimajor_axis': (0.723327, 'AU'),
    'eccentricity': 0.0067,
}


EARTH = {
    'symbol': '♁',
    'aphelion': (1.01559, 'AU'),
    'perihelion': (0.9832687, 'AU'),
    'semimajor_axis': (1.00000261, 'AU'),
    'eccentricity': 0.01671123,
}


MARS = {
    'symbol': '♂',
    'aphelion': (1.6660, 'AU'),
    'perihelion': (1.3814, 'AU'),
    'semimajor_axis': (1.523679, 'AU'),
    'eccentricity': 0.0935,
}


CERES = {
    'symbol': '⚳',
}


JUPITER = {
    'symbol': '♃',
    'aphelion': (5.458104, 'AU'),
    'perihelion': (4.950429, 'AU'),
    'semimajor_axis': (5.204267, 'AU'),
    'eccentricity': 0.048775,
}


SATURN = {
    'symbol': '♄',
    'aphelion': (10.11595804, 'AU'),
    'perihelion': (9.04807635, 'AU'),
    'semimajor_axis': (9.5820172, 'AU'),
    'eccentricity': 0.055723219,
}


URANUS = {
    'symbol': '♅',
    'aphelion': (20.095371, 'AU'),
    'perihelion': (18.283135, 'AU'),
    'semimajor_axis': (19.189253, 'AU'),
    'eccentricity': 0.047220087,
}


NEPTUNE = {
    'symbol': '♆',
    'aphelion': (30.331855, 'AU'),
    'perihelion': (29.809946, 'AU'),
    'semimajor_axis': (30.070900, 'AU'),
    'eccentricity': 0.00867797,
}


PLUTO = {
    'symbol': '♇',
}

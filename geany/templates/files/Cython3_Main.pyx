#!python3
#cython: language_level=3, boundscheck=False
#cython: c_string_encoding=utf-8, c_string_type=unicode
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief DESCRIPTION

@file {filename}
@package NAME
@version {date}
@author {developer} <{mail}>
@copyright LGPLv3

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) {developer}, All rights reserved.

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


import pyximport

pyximport.install()


__author__ = r'{developer}'
__copyright__ = r'LGPLv3'
__version__ = r'{date}'


def main(arg: int = DEFAULT) -> int:
    """DOCSTRING"""
    return 0


cdef int FUNCTION():
    """DOCSTRING"""
    return 0


if __name__ == '__main__':
    main()


raise SystemExit(0)

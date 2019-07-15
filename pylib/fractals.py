#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Fractal Functions.

@file fractals.py
@package pybooster.fractals
@version 2019.07.14
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


try:  # AutoJIT from Numba
    from numba import autojit
except ImportError:
    def autojit(_func: object):
        """Provide a dummy decorator for systems lacking Numba."""
        return _func


__all__: list = [
    # ITERATION TESTING #
    r'mandelbrot_max_iters',
    r'multibrot_max_iters',
    # ARRAY POPULATION #
    r'create_mandelbrot_fractal',
    r'create_multibrot_fractal'
]


# ITERATION TESTING #


@autojit
def mandelbrot_max_iters(_real: float, _imag: float, max_iters: int = 1024) -> int:
    """Given the real and imaginary parts of a complex number, determine if it is a candidate for membership in the Mandelbrot set given a fixed number of iterations."""
    _comp: complex = complex(_real, _imag)
    _z: complex = 0.0j
    for i in range(0, max_iters, 1):
        _z = _z * _z + _comp
        if (_z.real * _z.real + _z.imag * _z.imag) >= 4.0:
            return i
    return max_iters


@autojit
def multibrot_max_iters(_real: float, _imag: float, _expo: float = 2, max_iters: int = 1024) -> int:
    """Given the real and imaginary parts of a complex number, determine if it is a candidate for membership in the Multibrot set given a fixed number of iterations."""
    _comp: complex = complex(_real, _imag)
    _z: complex = 0.0j
    for i in range(max_iters):
        _z = (_z ** _expo) + _comp
        if (_z.real * _z.real + _z.imag * _z.imag) >= 4:
            return i
    return max_iters


# ARRAY POPULATION #


@autojit
def create_mandelbrot_fractal(image: object, min_x: float = -2.0, max_x: float = 1.0, min_y: float = -1.0, max_y: float = 1.0, iters: int = 1024) -> None:  # pylint: disable=R0913
    """Create a Mandelbrot fractal using the specified parameters and Numpy array."""
    height: int = image.shape[0]  # type: ignore
    width: int = image.shape[1]  # type: ignore
    pixel_size_x: float = (max_x - min_x) / width
    pixel_size_y: float = (max_y - min_y) / height
    for _x in range(0, width, 1):
        _real: float = min_x + _x * pixel_size_x
        for _y in range(0, height, 1):
            _imag: float = min_y + _y * pixel_size_y
            image[_y, _x] = mandelbrot_max_iters(_real, _imag, iters)  # type: ignore


@autojit
def create_multibrot_fractal(image: object, min_x: float = -2.0, max_x: float = 1.0, min_y: float = -1.0, max_y: float = 1.0, _expo: float = 2, iters: int = 1024) -> None:  # pylint: disable=R0913
    """Create a Multibrot fractal using the specified parameters and Numpy array."""
    height: int = image.shape[0]  # type: ignore
    width: int = image.shape[1]  # type: ignore
    pixel_size_x: float = (max_x - min_x) / width
    pixel_size_y: float = (max_y - min_y) / height
    for _x in range(0, width, 1):
        _real: float = min_x + _x * pixel_size_x
        for _y in range(0, height, 1):
            _imag: float = min_y + _y * pixel_size_y
            image[_y, _x] = multibrot_max_iters(_real, _imag, _expo, iters)  # type: ignore

// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file pyphysics.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Physics Functions
@version 2016.03.18

@section DESCRIPTION
This is a Python3 module that uses functions from physics.c
Functions related to physics calculations

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.
*/


#include "PY_MACROS.h"
#include "physics.h"

#define MODNAME   "physics"
#define MODINIT   PyMODINIT_FUNC PyInit_physics(void)
MODINIT __attribute__((flatten));


#if (defined(__GNUC__) && !defined(__clang__))  // Hard-code some optimizations
#   pragma GCC optimize (3)
#   pragma GCC optimize ("fast-math")
#   pragma GCC optimize ("no-exceptions")
#   pragma GCC optimize ("unroll-loops")
#   pragma GCC optimize ("wrapv")
#elif defined(__clang__)
#   pragma clang optimize on
#elif defined(__INTEL_COMPILER)
#   pragma intel optimization_level 3
#endif


/* FUNCTION DEFINITIONS */


#ifdef __GNUC__
static PyObject *physics_density(FUNCARGS) __attribute__((const, flatten));
static PyObject *physics_pressure(FUNCARGS) __attribute__((const, flatten));
static PyObject *physics_distance(FUNCARGS) __attribute__((const, flatten));
static PyObject *physics_speed(FUNCARGS) __attribute__((const, flatten));
static PyObject *physics_momentum(FUNCARGS) __attribute__((const, flatten));
static PyObject *physics_force(FUNCARGS) __attribute__((const, flatten));
static PyObject *physics_impulse(FUNCARGS) __attribute__((const, flatten));
#else
static PyObject *physics_density(FUNCARGS);
static PyObject *physics_pressure(FUNCARGS);
static PyObject *physics_distance(FUNCARGS);
static PyObject *physics_speed(FUNCARGS);
static PyObject *physics_momentum(FUNCARGS);
static PyObject *physics_force(FUNCARGS);
static PyObject *physics_impulse(FUNCARGS);
#endif


/* DOCSTRINGS */


static char module_docstring[32] =
    "Physics Functions";
PyDoc_STRVAR(physics_density_docstring,
    "density(mass: float, volume: float) -> float\nReturn density given mass and volume");
PyDoc_STRVAR(physics_pressure_docstring,
    "pressure(force: float, area: float) -> float\nReturn pressure given force and area");
PyDoc_STRVAR(physics_distance_docstring,
    "distance(speed: float, time: float) -> float\nReturn distance given speed and time");
PyDoc_STRVAR(physics_speed_docstring,
    "speed(distance: float, time: float) -> float\nReturn speed/velocity given the distance and time");
PyDoc_STRVAR(physics_momentum_docstring,
    "momentum(mass: float, velocity: float) -> float\nReturn momentum given mass and velocity");
PyDoc_STRVAR(physics_force_docstring,
    "force(mass: float, acceleration: float) -> float\nReturn the force given mass and acceleration");
PyDoc_STRVAR(physics_impulse_docstring,
    "impulse(force: float, time: float) -> float\nReturn impulse given force and time");


/* MODULE SPECIFICATION */


static PyMethodDef module_methods[8] = {  // Method Table
    {"density", (PyCFunction)physics_density, METH_VARARGS, physics_density_docstring},
    {"pressure", (PyCFunction)physics_pressure, METH_VARARGS, physics_pressure_docstring},
    {"distance", (PyCFunction)physics_distance, METH_VARARGS, physics_distance_docstring},
    {"speed", (PyCFunction)physics_speed, METH_VARARGS, physics_speed_docstring},
    {"momentum", (PyCFunction)physics_momentum, METH_VARARGS, physics_momentum_docstring},
    {"force", (PyCFunction)physics_force, METH_VARARGS, physics_force_docstring},
    {"impulse", (PyCFunction)physics_impulse, METH_VARARGS, physics_impulse_docstring},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef module = {  // Module Definition
    PyModuleDef_HEAD_INIT,
    MODNAME,  // Module name
    module_docstring,  // Module docstring
    -1,  // Module size
    module_methods,  // Module methods
    NULL,  // Module reload
    NULL,  // Module traverse
    NULL,  // Module clear
    NULL  // Module free
};


MODINIT {  // Initialize module
    PyObject *m;
    m = PyModule_Create(&module);
#   ifndef NOAUTHOR
    PyModule_AddStringConstant(m, "__author__", __author__);
#   endif
#   ifndef NOVERSION
    PyModule_AddStringConstant(m, "__version__", __version__);
#   endif
    if (m == (PyObject *)NULL) return NULL;
    return m;
}


/* C CODE */


static PyObject *physics_density(FUNCARGS) {
    const double mass, volume;
    ASSERT_2DOUBLE_ARG(mass, volume);
    return double2float((mass / volume));
}


static PyObject *physics_pressure(FUNCARGS) {
    const double force, area;
    ASSERT_2DOUBLE_ARG(force, area);
    return double2float((force / area));
}


static PyObject *physics_distance(FUNCARGS) {
    const double speed, time;
    ASSERT_2DOUBLE_ARG(speed, time);
    return double2float((speed * time));
}


static PyObject *physics_speed(FUNCARGS) {
    const double distance, time;
    ASSERT_2DOUBLE_ARG(distance, time);
    return double2float((distance / time));
}


static PyObject *physics_momentum(FUNCARGS) {
    const double mass, velocity;
    ASSERT_2DOUBLE_ARG(mass, velocity);
    return double2float((mass * velocity));
}


static PyObject *physics_force(FUNCARGS) {
    const double mass, acceleration;
    ASSERT_2DOUBLE_ARG(mass, acceleration);
    return double2float((mass * acceleration));
}


static PyObject *physics_impulse(FUNCARGS) {
    const double force, time;
    ASSERT_2DOUBLE_ARG(force, time);
    return double2float((force * time));
}

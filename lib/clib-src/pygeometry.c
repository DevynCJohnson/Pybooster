// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file pygeometry.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Geometry Equations
@version 2016.03.18

@section DESCRIPTION
This is a Python3 module that uses functions from geometry.c
Various geometric functions such as volume, area, distance, boolean tests, etc.

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
#include "MATH_MACROS.h"

#define MODNAME   "geometry"
#define MODINIT   PyMODINIT_FUNC PyInit_geometry(void)
MODINIT __attribute__((flatten));

#define PY_DOUBLE_PRECISION   ((double)0.00002)


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


/* HELPER FUNCTIONS */
#ifdef __GNUC__
static double squareroot(const double num) __attribute__((const, flatten));
#else
static double squareroot(const double num);
#endif

/** Private Function: Returns the Square-Root of a positive number (Limit: 1000000000000000.0) */
static double squareroot(const double num) {
    if (num < (double)0.0) { return -1.0; }
    else if (floor(num) == num && num <= (double)81.0) {
        if (num == (double)0.0) return 0.0;
        else if (num == (double)1.0) return 1.0;
        else if (num == (double)4.0) return 2.0;
        else if (num == (double)9.0) return 3.0;
        else if (num == (double)16.0) return 4.0;
        else if (num == (double)25.0) return 5.0;
        else if (num == (double)36.0) return 6.0;
        else if (num == (double)49.0) return 7.0;
        else if (num == (double)64.0) return 8.0;
        else if (num == (double)81.0) return 9.0;
    }
    register double start = (double)0.0;  // if num < 1; then 0 < num < sqrt(num); else 0 < sqrt(num) < num
    register double end = (num < (double)1.0 ? (double)1.0 : num);
    register double mid, midSqr;
    while ((end - start) > (double)PY_DOUBLE_PRECISION) {  // Define precision
        mid = ((start + end) * (double)0.5);
        midSqr = (mid * mid);
        if (midSqr == num) { return mid; }  // Exact sqrt value
        else if (midSqr < num) { start = mid; }
        else { end = mid; }
    }
    return ((start + end) * (double)0.5);
}


/* FUNCTION DEFINITIONS */


#ifdef __GNUC__
static PyObject *geometry_areacircle(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_areaellipse(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_areaequilateraltriangle(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_areaparallelogram(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_arearectangle(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_arearhombus(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_areasector(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_areasquare(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_areasquare_int(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_areatrapezoid(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_areatriangle(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_lengtharc(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_perimetercircle(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_perimeterparallelogram(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_perimeterrhombus(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_perimeterrectangle(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_perimetersquare(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_perimetertrapezoid(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_perimetertriangle(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_surfaceareacone(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_surfaceareacube(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_surfaceareacylinder(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_surfacearearectangularprism(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_surfaceareasphere(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_surfaceareasquarepyramid(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_surfaceareatorus(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_volumecone(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_volumecylinder(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_volumeellipsoid(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_volumeparallelepiped(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_volumehemisphere(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_volumeprism(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_volumerectanglarprism(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_volumesphere(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_volumesquarepyramid(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_volumetetrahedron(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *geometry_volumetorus(FUNCARGS) __attribute__((const, flatten, nonnull));
#else
static PyObject *geometry_areacircle(FUNCARGS);
static PyObject *geometry_areaellipse(FUNCARGS);
static PyObject *geometry_areaequilateraltriangle(FUNCARGS);
static PyObject *geometry_areaparallelogram(FUNCARGS);
static PyObject *geometry_arearectangle(FUNCARGS);
static PyObject *geometry_arearhombus(FUNCARGS);
static PyObject *geometry_areasector(FUNCARGS);
static PyObject *geometry_areasquare(FUNCARGS);
static PyObject *geometry_areasquare_int(FUNCARGS);
static PyObject *geometry_areatrapezoid(FUNCARGS);
static PyObject *geometry_areatriangle(FUNCARGS);
static PyObject *geometry_lengtharc(FUNCARGS);
static PyObject *geometry_perimetercircle(FUNCARGS);
static PyObject *geometry_perimeterparallelogram(FUNCARGS);
static PyObject *geometry_perimeterrhombus(FUNCARGS);
static PyObject *geometry_perimeterrectangle(FUNCARGS);
static PyObject *geometry_perimetersquare(FUNCARGS);
static PyObject *geometry_perimetertrapezoid(FUNCARGS);
static PyObject *geometry_perimetertriangle(FUNCARGS);
static PyObject *geometry_surfaceareacone(FUNCARGS);
static PyObject *geometry_surfaceareacube(FUNCARGS);
static PyObject *geometry_surfaceareacylinder(FUNCARGS);
static PyObject *geometry_surfacearearectangularprism(FUNCARGS);
static PyObject *geometry_surfaceareasphere(FUNCARGS);
static PyObject *geometry_surfaceareasquarepyramid(FUNCARGS);
static PyObject *geometry_surfaceareatorus(FUNCARGS);
static PyObject *geometry_volumecone(FUNCARGS);
static PyObject *geometry_volumecylinder(FUNCARGS);
static PyObject *geometry_volumeellipsoid(FUNCARGS);
static PyObject *geometry_volumeparallelepiped(FUNCARGS);
static PyObject *geometry_volumehemisphere(FUNCARGS);
static PyObject *geometry_volumeprism(FUNCARGS);
static PyObject *geometry_volumerectanglarprism(FUNCARGS);
static PyObject *geometry_volumesphere(FUNCARGS);
static PyObject *geometry_volumesquarepyramid(FUNCARGS);
static PyObject *geometry_volumetetrahedron(FUNCARGS);
static PyObject *geometry_volumetorus(FUNCARGS);
#endif


/* DOCSTRINGS */


static char module_docstring[32] =
    "Geometry Equations";
PyDoc_STRVAR(geometry_areacircle_docstring,
    "areacircle(radius: float) -> float\nReturn the area of a circle (float)");
PyDoc_STRVAR(geometry_areaellipse_docstring,
    "areaellipse(radius1: float, radius2: float) -> float\nReturn the area of a ellipse (float)");
PyDoc_STRVAR(geometry_areaequilateraltriangle_docstring,
    "areaequilateraltriangle(base: float) -> float\nReturn the area of a equilateral triangle (float)");
PyDoc_STRVAR(geometry_areaparallelogram_docstring,
    "areaparallelogram(base: float, height: float) -> float\nReturn the area of a parallelogram (float)");
PyDoc_STRVAR(geometry_arearectangle_docstring,
    "arearectangle(length: float, width: float) -> float\nReturn the area of a rectangle (float)");
PyDoc_STRVAR(geometry_arearhombus_docstring,
    "arearhombus(base: float) -> float\nReturn the area of a rhombus (float)");
PyDoc_STRVAR(geometry_areasector_docstring,
    "areasector(radius: float, angle_radians: float) -> float\nReturn the area of a circular sector (float)");
PyDoc_STRVAR(geometry_areasquare_docstring,
    "areasquare(length: float) -> float\nReturn the area of a square (float)");
PyDoc_STRVAR(geometry_areasquare_int_docstring,
    "areasquare_int(length: int) -> int\nReturn the area of a square (int)");
PyDoc_STRVAR(geometry_areatrapezoid_docstring,
    "areatrapezoid(base1: float, base2: float, height: float) -> float\nReturn the area of a trapezoid (float)");
PyDoc_STRVAR(geometry_areatriangle_docstring,
    "areatriangle(base: float, height: float) -> float\nReturn the area of a triangle (float)");
PyDoc_STRVAR(geometry_lengtharc_docstring,
    "lengtharc(radius: float, angle_radians: float) -> float\nReturn the length of an arc (float)");
PyDoc_STRVAR(geometry_perimetercircle_docstring,
    "perimetercircle(radius: float) -> float\nReturn the perimeter of a circle (float)");
PyDoc_STRVAR(geometry_perimeterparallelogram_docstring,
    "perimeterparallelogram(base: float, side: float) -> float\nReturn the perimeter of a parallelogram (float)");
PyDoc_STRVAR(geometry_perimeterrhombus_docstring,
    "perimeterrhombus(base: float) -> float\nReturn the perimeter of a rhombus (float)");
PyDoc_STRVAR(geometry_perimeterrectangle_docstring,
    "perimeterrectangle(length: float, width: float) -> float\nReturn the perimeter of a rectangle (float)");
PyDoc_STRVAR(geometry_perimetersquare_docstring,
    "perimetersquare(side: float) -> float\nReturn the perimeter of a square (float)");
PyDoc_STRVAR(geometry_perimetertrapezoid_docstring,
    "perimetertrapezoid(side1: float, side2: float, side3: float, side4: float) -> float\nReturn the perimeter of a trapezoid (float)");
PyDoc_STRVAR(geometry_perimetertriangle_docstring,
    "perimetertriangle(side1: float, side2: float, side3: float) -> float\nReturn the perimeter of a triangle (float)");
PyDoc_STRVAR(geometry_surfaceareacone_docstring,
    "surfaceareacone(radius: float, height: float) -> float\nReturn the surface area of a cone (float)");
PyDoc_STRVAR(geometry_surfaceareacube_docstring,
    "surfaceareacube(length: float) -> float\nReturn the surface area of a cube (float)");
PyDoc_STRVAR(geometry_surfaceareacylinder_docstring,
    "surfaceareacylinder(radius: float, height: float) -> float\nReturn the surface area of a cylinder (float)");
PyDoc_STRVAR(geometry_surfacearearectangularprism_docstring,
    "surfacearearectangularprism(length: float, width: float, height: float) -> float\nReturn the surface area of a rectangular prism (float)");
PyDoc_STRVAR(geometry_surfaceareasphere_docstring,
    "surfaceareasphere(radius: float) -> float\nReturn the surface area of a sphere (float)");
PyDoc_STRVAR(geometry_surfaceareasquarepyramid_docstring,
    "surfaceareasquarepyramid(side: float, length: float) -> float\nReturn the surface area of a square pyramid (float)");
PyDoc_STRVAR(geometry_surfaceareatorus_docstring,
    "surfaceareatorus(radius1: float, radius2: float) -> float\nReturn the surface area of a torus (float)");
PyDoc_STRVAR(geometry_volumecone_docstring,
    "volumecone(radius: float, height: float) -> float\nReturn the volume of a cone (float)");
PyDoc_STRVAR(geometry_volumecylinder_docstring,
    "volumecylinder(radius: float, height: float) -> float\nReturn the volume of a cylinder (float)");
PyDoc_STRVAR(geometry_volumeellipsoid_docstring,
    "volumeellipsoid(radius1: float, radius2: float, radius3: float) -> float\nReturn the volume of a ellipsoid (float)");
PyDoc_STRVAR(geometry_volumeparallelepiped_docstring,
    "volumeparallelepiped(length: float, width: float, height: float) -> float\nReturn the volume of a parallelepiped (float)");
PyDoc_STRVAR(geometry_volumehemisphere_docstring,
    "volumehemisphere(radius: float) -> float\nReturn the volume of a hemisphere (float)");
PyDoc_STRVAR(geometry_volumeprism_docstring,
    "volumeprism(length: float, base: float) -> float\nReturn the volume of a prism (float)");
PyDoc_STRVAR(geometry_volumerectanglarprism_docstring,
    "volumerectanglarprism(length: float, width: float, height: float) -> float\nReturn the volume of a rectanglar prism (float)");
PyDoc_STRVAR(geometry_volumesphere_docstring,
    "volumesphere(radius: float) -> float\nReturn the volume of a sphere (float)");
PyDoc_STRVAR(geometry_volumesquarepyramid_docstring,
    "volumesquarepyramid(height: float, base: float) -> float\nReturn the volume of a square pyramid (float)");
PyDoc_STRVAR(geometry_volumetetrahedron_docstring,
    "volumetetrahedron(height: float, base: float) -> float\nReturn the volume of a tetrahedron (float)");
PyDoc_STRVAR(geometry_volumetorus_docstring,
    "volumetorus(radius1: float, radius2: float) -> float\nReturn the volume of a torus (float)");


/* MODULE SPECIFICATION */


static PyMethodDef module_methods[64] = {  // Method Table
    {"areacircle", (PyCFunction)geometry_areacircle, METH_VARARGS, geometry_areacircle_docstring},
    {"areaellipse", (PyCFunction)geometry_areaellipse, METH_VARARGS, geometry_areaellipse_docstring},
    {"areaequilateraltriangle", (PyCFunction)geometry_areaequilateraltriangle, METH_VARARGS, geometry_areaequilateraltriangle_docstring},
    {"areaparallelogram", (PyCFunction)geometry_areaparallelogram, METH_VARARGS, geometry_areaparallelogram_docstring},
    {"arearectangle", (PyCFunction)geometry_arearectangle, METH_VARARGS, geometry_arearectangle_docstring},
    {"arearhombus", (PyCFunction)geometry_arearhombus, METH_VARARGS, geometry_arearhombus_docstring},
    {"areasector", (PyCFunction)geometry_areasector, METH_VARARGS, geometry_areasector_docstring},
    {"areasquare", (PyCFunction)geometry_areasquare, METH_VARARGS, geometry_areasquare_docstring},
    {"areasquare_int", (PyCFunction)geometry_areasquare_int, METH_VARARGS, geometry_areasquare_int_docstring},
    {"areatrapezoid", (PyCFunction)geometry_areatrapezoid, METH_VARARGS, geometry_areatrapezoid_docstring},
    {"areatriangle", (PyCFunction)geometry_areatriangle, METH_VARARGS, geometry_areatriangle_docstring},
    {"lengtharc", (PyCFunction)geometry_lengtharc, METH_VARARGS, geometry_lengtharc_docstring},
    {"perimetercircle", (PyCFunction)geometry_perimetercircle, METH_VARARGS, geometry_perimetercircle_docstring},
    {"perimeterparallelogram", (PyCFunction)geometry_perimeterparallelogram, METH_VARARGS, geometry_perimeterparallelogram_docstring},
    {"perimeterrhombus", (PyCFunction)geometry_perimeterrhombus, METH_VARARGS, geometry_perimeterrhombus_docstring},
    {"perimeterrectangle", (PyCFunction)geometry_perimeterrectangle, METH_VARARGS, geometry_perimeterrectangle_docstring},
    {"perimetersquare", (PyCFunction)geometry_perimetersquare, METH_VARARGS, geometry_perimetersquare_docstring},
    {"perimetertrapezoid", (PyCFunction)geometry_perimetertrapezoid, METH_VARARGS, geometry_perimetertrapezoid_docstring},
    {"perimetertriangle", (PyCFunction)geometry_perimetertriangle, METH_VARARGS, geometry_perimetertriangle_docstring},
    {"surfaceareacone", (PyCFunction)geometry_surfaceareacone, METH_VARARGS, geometry_surfaceareacone_docstring},
    {"surfaceareacube", (PyCFunction)geometry_surfaceareacube, METH_VARARGS, geometry_surfaceareacube_docstring},
    {"surfaceareacylinder", (PyCFunction)geometry_surfaceareacylinder, METH_VARARGS, geometry_surfaceareacylinder_docstring},
    {"surfacearearectangularprism", (PyCFunction)geometry_surfacearearectangularprism, METH_VARARGS, geometry_surfacearearectangularprism_docstring},
    {"surfaceareasphere", (PyCFunction)geometry_surfaceareasphere, METH_VARARGS, geometry_surfaceareasphere_docstring},
    {"surfaceareasquarepyramid", (PyCFunction)geometry_surfaceareasquarepyramid, METH_VARARGS, geometry_surfaceareasquarepyramid_docstring},
    {"surfaceareatorus", (PyCFunction)geometry_surfaceareatorus, METH_VARARGS, geometry_surfaceareatorus_docstring},
    {"volumecone", (PyCFunction)geometry_volumecone, METH_VARARGS, geometry_volumecone_docstring},
    {"volumecylinder", (PyCFunction)geometry_volumecylinder, METH_VARARGS, geometry_volumecylinder_docstring},
    {"volumeellipsoid", (PyCFunction)geometry_volumeellipsoid, METH_VARARGS, geometry_volumeellipsoid_docstring},
    {"volumeparallelepiped", (PyCFunction)geometry_volumeparallelepiped, METH_VARARGS, geometry_volumeparallelepiped_docstring},
    {"volumehemisphere", (PyCFunction)geometry_volumehemisphere, METH_VARARGS, geometry_volumehemisphere_docstring},
    {"volumeprism", (PyCFunction)geometry_volumeprism, METH_VARARGS, geometry_volumeprism_docstring},
    {"volumerectanglarprism", (PyCFunction)geometry_volumerectanglarprism, METH_VARARGS, geometry_volumerectanglarprism_docstring},
    {"volumesphere", (PyCFunction)geometry_volumesphere, METH_VARARGS, geometry_volumesphere_docstring},
    {"volumesquarepyramid", (PyCFunction)geometry_volumesquarepyramid, METH_VARARGS, geometry_volumesquarepyramid_docstring},
    {"volumetetrahedron", (PyCFunction)geometry_volumetetrahedron, METH_VARARGS, geometry_volumetetrahedron_docstring},
    {"volumetorus", (PyCFunction)geometry_volumetorus, METH_VARARGS, geometry_volumetorus_docstring},
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
    PyModule_AddObject(m, "PI", double2float(PI));  // From mathconstants
    if (m == (PyObject *)NULL) return NULL;
    return m;
}


/* C CODE */


/* AREA */


static PyObject *geometry_areacircle(FUNCARGS) {
    const double radius;
    ASSERT_DOUBLE_ARG(radius);
    return double2float((PI * radius * radius));
}


static PyObject *geometry_areaellipse(FUNCARGS) {
    const double radius1, radius2;
    ASSERT_2DOUBLE_ARG(radius1, radius2);
    return double2float((PI * radius1 * radius2));
}


static PyObject *geometry_areaequilateraltriangle(FUNCARGS) {
    const double base;
    ASSERT_DOUBLE_ARG(base);
    return double2float(((base * base) * SQRT_3_DIV_4));
}


static PyObject *geometry_areaparallelogram(FUNCARGS) {
    const double base, height;
    ASSERT_2DOUBLE_ARG(base, height);
    return double2float((base * height));
}


static PyObject *geometry_arearectangle(FUNCARGS) {
    const double length, width;
    ASSERT_2DOUBLE_ARG(length, width);
    return double2float((length * width));
}


static PyObject *geometry_arearhombus(FUNCARGS) {
    const double base;
    ASSERT_DOUBLE_ARG(base);
    return double2float((base * base));
}


static PyObject *geometry_areasector(FUNCARGS) {
    const double radius, angle_radians;
    ASSERT_2DOUBLE_ARG(radius, angle_radians);
    return double2float(((radius * radius * angle_radians) * (double)0.5));
}


static PyObject *geometry_areasquare(FUNCARGS) {
    const double length;
    ASSERT_DOUBLE_ARG(length);
    return double2float((length * length));
}


static PyObject *geometry_areasquare_int(FUNCARGS) {
    const sllint length;
    ASSERT_LONGLONG_ARG(length);
    return ll2int((length * length));
}


static PyObject *geometry_areatrapezoid(FUNCARGS) {
    const double base1, base2, height;
    ASSERT_3DOUBLE_ARG(base1, base2, height);
    return double2float((((base1 + base2) * (double)0.5) * height));
}


static PyObject *geometry_areatriangle(FUNCARGS) {
    const double base, height;
    ASSERT_2DOUBLE_ARG(base, height);
    return double2float(((base * height) * (double)0.5));
}


static PyObject *geometry_lengtharc(FUNCARGS) {
    const double radius, angle_radians;
    ASSERT_2DOUBLE_ARG(radius, angle_radians);
    return double2float((radius * angle_radians));
}


static PyObject *geometry_perimetercircle(FUNCARGS) {
    const double radius;
    ASSERT_DOUBLE_ARG(radius);
    return double2float((PI2 * radius));
}


static PyObject *geometry_perimeterparallelogram(FUNCARGS) {
    const double base, side;
    ASSERT_2DOUBLE_ARG(base, side);
    return double2float((base + base + side + side));
}


static PyObject *geometry_perimeterrhombus(FUNCARGS) {
    const double base;
    ASSERT_DOUBLE_ARG(base);
    return double2float((base + base + base + base));
}


static PyObject *geometry_perimeterrectangle(FUNCARGS) {
    const double length, width;
    ASSERT_2DOUBLE_ARG(length, width);
    return double2float((length + length + width + width));
}


static PyObject *geometry_perimetersquare(FUNCARGS) {
    const double side;
    ASSERT_DOUBLE_ARG(side);
    return double2float((side + side + side + side));
}


static PyObject *geometry_perimetertrapezoid(FUNCARGS) {
    const double side1, side2, side3, side4;
    ASSERT_4DOUBLE_ARG(side1, side2, side3, side4);
    return double2float((side1 + side2 + side3 + side4));
}


static PyObject *geometry_perimetertriangle(FUNCARGS) {
    const double side1, side2, side3;
    ASSERT_3DOUBLE_ARG(side1, side2, side3);
    return double2float((side1 + side2 + side3));
}


static PyObject *geometry_surfaceareacone(FUNCARGS) {
    const double radius, height;
    ASSERT_2DOUBLE_ARG(radius, height);
    return double2float((radius * PI * squareroot((radius * radius) + (height * height))));
}


static PyObject *geometry_surfaceareacube(FUNCARGS) {
    const double length;
    ASSERT_DOUBLE_ARG(length);
    return double2float((6.0 * (length * length)));
}


static PyObject *geometry_surfaceareacylinder(FUNCARGS) {
    const double radius, height;
    ASSERT_2DOUBLE_ARG(radius, height);
    return double2float((radius * height * PI2));
}


static PyObject *geometry_surfacearearectangularprism(FUNCARGS) {
    const double length, width, height;
    ASSERT_3DOUBLE_ARG(length, width, height);
    return double2float((2.0 * (length * width + height * width + height * length)));
}


static PyObject *geometry_surfaceareasphere(FUNCARGS) {
    const double radius;
    ASSERT_DOUBLE_ARG(radius);
    return double2float((radius * radius * PI4));
}


static PyObject *geometry_surfaceareasquarepyramid(FUNCARGS) {
    const double side, length;
    ASSERT_2DOUBLE_ARG(side, length);
    return double2float(((side * side) + (2.0 * side * length)));
}


static PyObject *geometry_surfaceareatorus(FUNCARGS) {
    const double radius1, radius2;
    ASSERT_2DOUBLE_ARG(radius1, radius2);
    return double2float((PI * ((radius2 * radius2) - (radius1 * radius1))));
}


static PyObject *geometry_volumecone(FUNCARGS) {
    const double radius, height;
    ASSERT_2DOUBLE_ARG(radius, height);
    return double2float((PI_1_3 * radius * radius * height));
}


static PyObject *geometry_volumecylinder(FUNCARGS) {
    const double radius, height;
    ASSERT_2DOUBLE_ARG(radius, height);
    return double2float((PI * radius * radius * height));
}


static PyObject *geometry_volumeellipsoid(FUNCARGS) {
    const double radius1, radius2, radius3;
    ASSERT_3DOUBLE_ARG(radius1, radius2, radius3);
    return double2float((PI_4_3 * radius1 * radius2 * radius3));
}


static PyObject *geometry_volumeparallelepiped(FUNCARGS) {
    const double length, width, height;
    ASSERT_3DOUBLE_ARG(length, width, height);
    return double2float((length * width * height));
}


static PyObject *geometry_volumehemisphere(FUNCARGS) {
    const double radius;
    ASSERT_DOUBLE_ARG(radius);
    return double2float((PI_2_3 * radius * radius * radius));
}


static PyObject *geometry_volumeprism(FUNCARGS) {
    const double length, base;
    ASSERT_2DOUBLE_ARG(length, base);
    return double2float((length * base));
}


static PyObject *geometry_volumerectanglarprism(FUNCARGS) {
    const double length, width, height;
    ASSERT_3DOUBLE_ARG(length, width, height);
    return double2float((length * width * height));
}


static PyObject *geometry_volumesphere(FUNCARGS) {
    const double radius;
    ASSERT_DOUBLE_ARG(radius);
    return double2float((PI_4_3 * radius * radius * radius));
}


static PyObject *geometry_volumesquarepyramid(FUNCARGS) {
    const double height, base;
    ASSERT_2DOUBLE_ARG(height, base);
    return double2float(((height * base) * 0.333333333));
}


static PyObject *geometry_volumetetrahedron(FUNCARGS) {
    const double height, base;
    ASSERT_2DOUBLE_ARG(height, base);
    return double2float(((height * base) * 0.333333333));
}


static PyObject *geometry_volumetorus(FUNCARGS) {
    const double radius1, radius2;
    ASSERT_2DOUBLE_ARG(radius1, radius2);
    return double2float((PI_SQUARED_1_4 * ((radius1 + radius2) * ((radius1 - radius2) * (radius1 - radius2)))));
}

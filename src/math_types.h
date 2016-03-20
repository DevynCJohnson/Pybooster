// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file math_types.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Math-related Data-types (header)
@version 2016.03.20

@section DESCRIPTION
Special math, geometry, and number datatypes such as quaternions and circles

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


#ifndef FILE_MATH_TYPES_SEEN
#define FILE_MATH_TYPES_SEEN


#include "MACROS.h"


/** Imaginary number with three imaginary parts (double) */
typedef struct { double R, i, j, k; } quaternion;
/** Imaginary number with three imaginary parts (float) */
typedef struct { float R, i, j, k; } quaternion_float;
/** Imaginary number with three imaginary parts (long double) */
typedef struct { long double R, i, j, k; } quaternion_long_double;
#ifdef FLOAT128_SUPPORTED
/** Imaginary number with three imaginary parts (float128_t) */
typedef struct { __float128 R, i, j, k; } quaternion_float128;
#endif
#ifndef QUATERNION
#   define QUATERNION(r, x, y, z)   ((quaternion){(double)(r), (double)(x), (double)(y), (double)(z)})
#endif
#ifndef QUATERNIONF
#   define QUATERNIONF(r, x, y, z)   ((quaternion_float){(float)(r), (float)(x), (float)(y), (float)(z)})
#endif
#ifndef QUATERNIONL
#   define QUATERNIONL(r, x, y, z)   ((quaternion_long_double){(long double)(r), (long double)(x), (long double)(y), (long double)(z)})
#endif
#if (defined(QUATERNIONF) && defined(FLOAT128_SUPPORTED))
#   define QUATERNIONF128(r, x, y, z)   ((quaternion_float128){(__float128)(r), (__float128)(x), (__float128)(y), (__float128)(z)})
#endif
#ifndef __quaternion__
#   define __quaternion__(r, x, y, z)   ((quaternion){(double)(r), (double)(x), (double)(y), (double)(z)})
#endif
#ifndef __quaternionf__
#   define __quaternionf__(r, x, y, z)   ((quaternion_float){(float)(r), (float)(x), (float)(y), (float)(z)})
#endif
#ifndef __quaternionl__
#   define __quaternionl__(r, x, y, z)   ((quaternion_long_double){(long double)(r), (long double)(x), (long double)(y), (long double)(z)})
#endif
#if (defined(QUATERNIONF) && defined(FLOAT128_SUPPORTED) && !defined(__quaternionf128__))
#   define __quaternionf128__(r, x, y, z)   ((quaternion_float128){(__float128)(r), (__float128)(x), (__float128)(y), (__float128)(z)})
#endif
/* GEOMETRY */
/** Coordinates of a point (double) */
typedef struct { double x, y; } point;
/** Coordinates of a point (float) */
typedef struct { float x, y; } pointf;
#ifdef FLOAT128_SUPPORTED
/** Coordinates of a point (__float128) */
typedef struct { __float128 x, y; } point__float128;
#endif
/** Coordinates of a point (long double) */
typedef struct { long double x, y; } pointl;
/** Coordinates of a point (signed long int) */
typedef struct { signed long int x, y; } point_int;
/** Two points of a line (double) */
typedef struct { point x, y; } line;
/** Two points of a line (float) */
typedef struct { pointf x, y; } linef;
/** Two points of a line (long double) */
typedef struct { pointl x, y; } linel;
/** Two points of a line (signed long int) */
typedef struct { point_int x, y; } line_int;
/* 2D SHAPES */
/** Semicircle, given the radius (double) */
typedef struct { double radius; } semicircle;
/** Semicircle, given the radius (long double) */
typedef struct { long double radius; } semicirclel;
/** Semicircle, given the radius (float) */
typedef struct { float radius; } semicirclef;
/** Circle, given the radius (double) */
typedef struct { double radius; } circle;
/** Circle, given the radius (long double) */
typedef struct { long double radius; } circlel;
/** Circle, given the radius (float) */
typedef struct { float radius; } circlef;
/** Ellipse, given the major-radius and minor-radius (double) */
typedef struct { double majorradius, minorradius; } ellipse;
/** Ellipse, given the major-radius and minor-radius (long double) */
typedef struct { long double majorradius, minorradius; } ellipsel;
/** Ellipse, given the major-radius and minor-radius (float) */
typedef struct { float majorradius, minorradius; } ellipsef;
/** Hexagon, given the width and a side-length (double) */
typedef struct { double width, sidelength; } hexagon;
/** Hexagon, given the width and a side-length (long double) */
typedef struct { long double width, sidelength; } hexagonl;
/** Hexagon, given the width and a side-length (float) */
typedef struct { float width, sidelength; } hexagonf;
/** Rectangle, given the height and width (double) */
typedef struct { double height, width; } rectangle;
/** Rectangle, given the height and width (long double) */
typedef struct { long double height, width; } rectanglel;
/** Rectangle, given the height and width (float) */
typedef struct { float height, width; } rectanglef;
/** Square, given the length (double) */
typedef struct { double length; } square;
/** Square, given the length (long double) */
typedef struct { long double length; } squarel;
/** Square, given the length (float) */
typedef struct { float length; } squaref;
/** Triangle, given the base and height (double) */
typedef struct { double base, height; } triangle;
/** Triangle, given the base and height (long double) */
typedef struct { long double base, height; } trianglel;
/** Triangle, given the base and height (float) */
typedef struct { float base, height; } trianglef;
/* 3D SHAPES */
/** Sphere, given the radius (double) */
typedef struct { double radius; } sphere;
/** Sphere, given the radius (long double) */
typedef struct { long double radius; } spherel;
/** Sphere, given the radius (float) */
typedef struct { float radius; } spheref;
#ifdef FLOAT128_SUPPORTED
/** Sphere, given the radius (__float128) */
typedef struct { __float128 radius; } sphere__float128;
#endif
/** Cube, given the length (double) */
typedef struct { double length; } cube;
/** Cube, given the length (long double) */
typedef struct { long double length; } cubel;
/** Cube, given the length (float) */
typedef struct { float length; } cubef;
#ifdef FLOAT128_SUPPORTED
/** Cube, given the length (__float128) */
typedef struct { __float128 length; } cube__float128;
#endif
/** Ellipsoid, given radius1, radius2, and radius3 (double) */
typedef struct { double radius1, radius2, radius3; } ellipsoid;
/** Ellipsoid, given radius1, radius2, and radius3 (long double) */
typedef struct { long double radius1, radius2, radius3; } ellipsoidl;
/** Ellipsoid, given radius1, radius2, and radius3 (float) */
typedef struct { float radius1, radius2, radius3; } ellipsoidf;
#ifdef FLOAT128_SUPPORTED
/** Ellipsoid, given radius1, radius2, and radius3 (__float128) */
typedef struct { __float128 radius1, radius2, radius3; } ellipsoid__float128;
#endif
/** Prism, given the depth, height, and width (double) */
typedef struct { double depth, height, width; } prism;
/** Prism, given the depth, height, and width (long double) */
typedef struct { long double depth, height, width; } prisml;
/** Prism, given the depth, height, and width (float) */
typedef struct { float depth, height, width; } prismf;
#ifdef FLOAT128_SUPPORTED
/** Prism, given the depth, height, and width (__float128) */
typedef struct { __float128 depth, height, width; } prism__float128;
#endif


#endif

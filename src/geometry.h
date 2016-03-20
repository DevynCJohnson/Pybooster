// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file geometry.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Geometry Equations (header)
@version 2016.03.20

@section DESCRIPTION
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

@section FUNCTION_NAMING_SCHEME
 - func() -> double
 - funcl() -> long double
 - funcf() -> float
 - func_int() -> unsigned long int
 - func_ull() -> unsigned long long int
 - func_signed() -> signed long long int
 - func_shape() -> shape (double)
 - func_shapel() -> shapel (long double)
*/


#ifndef FILE_GEOMETRY_SEEN
#define FILE_GEOMETRY_SEEN


#include "MACROS.h"

#include <math.h>

#include "MATH_MACROS.h"
#include "math_types.h"


/* HELPER FUNCTIONS */
#ifdef __GNUC__
static double squareroot(const double num) __attribute__((const, flatten));
static float squarerootf(const float num) __attribute__((const, flatten));
static long double squarerootl(const long double num) __attribute__((const, flatten));
#else
static double squareroot(const double num);
static float squarerootf(const float num);
static long double squarerootl(const long double num);
#endif
/* BOOLEAN TESTS */
int is_point_in_rectangle(const point p, const rectangle r);
/* COORDINATES */
doublepair_t xy2polar(const double x, const double y);
doublepair_t polar2xy(const double hypo, const double angle);
/* DISTANCE */
double distance(const double x1, const double y1, const double x2, const double y2);
long double distancel(const long double x1, const long double y1, const long double x2, const long double y2);
float distancef(const float x1, const float y1, const float x2, const float y2);
double distance_point(point location1, point location2);
long double distance_pointl(pointl location1, pointl location2);
double (* linelength_point)(point location1, point location2);
long double (* linelength_pointl)(pointl location1, pointl location2);
/* AREA */
double areacircle(const double radius);
long double areacirclel(const long double radius);
double areaellipse(const double radius1, const double radius2);
long double areaellipsel(const long double radius1, const long double radius2);
double areaequilateraltriangle(const double base);
long double areaequilateraltrianglel(const long double base);
double areaparallelogram(const double base, const double height);
long double areaparallelograml(const long double base, const long double height);
double arearectangle(const double length, const double width);
long double arearectanglel(const long double length, const long double width);
double arearhombus(const double base);
long double arearhombusl(const long double base);
double areasector(const double radius, const double angle_radians);
long double areasectorl(const long double radius, const long double angle_radians);
double areasquare(const double length);
long double areasquarel(const long double length);
unsigned long int areasquare_int(const unsigned long int length);
ullint areasquare_ull(const ullint length);
double areasquare_shape(const square shape);
long double areasquare_shapel(const squarel shape);
double areatrapezoid(const double base1, const double base2, const double height);
long double areatrapezoidl(const long double base1, const long double base2, const long double height);
double areatriangle(const double base, const double height);
long double areatrianglel(const long double base, const long double height);
/* LENGTH */
double lengtharc(const double radius, const double angle_radians);
long double lengtharcl(const long double radius, const long double angle_radians);
float lengtharcf(const float radius, const float angle_radians);
/* PERIMETER */
double perimetercircle(const double radius);
long double perimetercirclel(const long double radius);
double perimeterparallelogram(const double base, const double side);
long double perimeterparallelograml(const long double base, const long double side);
double perimeterrhombus(const double base);
long double perimeterrhombusl(const long double base);
double perimeterrectangle(const double length, const double width);
long double perimeterrectanglel(const long double length, const long double width);
double perimetersquare(const double side);
long double perimetersquarel(const long double side);
double perimetertrapezoid(const double side1, const double side2, const double side3, const double side4);
long double perimetertrapezoidl(const long double side1, const long double side2, const long double side3, const long double side4);
double perimetertriangle(const double side1, const double side2, const double side3);
long double perimetertrianglel(const long double side1, const long double side2, const long double side3);
/* SURFACE AREA */
double surfaceareacone(const double radius, const double height);
long double surfaceareaconel(const long double radius, const long double height);
float surfaceareaconef(const float radius, const float height);
double surfaceareacube(const double length);
long double surfaceareacubel(const long double length);
float surfaceareacubef(const float length);
double surfaceareacylinder(const double radius, const double height);
long double surfaceareacylinderl(const long double radius, const long double height);
float surfaceareacylinderf(const float radius, const float height);
double surfacearearectangularprism(const double length, const double width, const double height);
long double surfacearearectangularprisml(const long double length, const long double width, const long double height);
float surfacearearectangularprismf(const float length, const float width, const float height);
double surfaceareasphere(const double radius);
long double surfaceareaspherel(const long double radius);
float surfaceareaspheref(const float radius);
double surfaceareasquarepyramid(const double side, const double length);
long double surfaceareasquarepyramidl(const long double side, const long double length);
float surfaceareasquarepyramidf(const float side, const float length);
double surfaceareatorus(const double radius1, const double radius2);
long double surfaceareatorusl(const long double radius1, const long double radius2);
float surfaceareatorusf(const float radius1, const float radius2);
/* VOLUME */
double volumecone(const double radius, const double height);
long double volumeconel(const long double radius, const long double height);
float volumeconef(const float radius, const float height);
double volumecylinder(const double radius, const double height);
long double volumecylinderl(const long double radius, const long double height);
float volumecylinderf(const float radius, const float height);
double volumeellipsoid(const double radius1, const double radius2, const double radius3);
long double volumeellipsoidl(const long double radius1, const long double radius2, const long double radius3);
float volumeellipsoidf(const float radius1, const float radius2, const float radius3);
double volumehemisphere(const double radius);
long double volumehemispherel(const long double radius);
float volumehemispheref(const float radius);
double volumeparallelepiped(const double length, const double width, const double height);
long double volumeparallelepipedl(const long double length, const long double width, const long double height);
float volumeparallelepipedf(const float length, const float width, const float height);
double volumeprism(const double length, const double base);
long double volumeprisml(const long double length, const long double base);
float volumeprismf(const float length, const float base);
double volumerectanglarprism(const double length, const double width, const double height);
long double volumerectanglarprisml(const long double length, const long double width, const long double height);
float volumerectanglarprismf(const float length, const float width, const float height);
double volumesphere(const double radius);
long double volumespherel(const long double radius);
float volumespheref(const float radius);
double volumesquarepyramid(const double height, const double base);
long double volumesquarepyramidl(const long double height, const long double base);
float volumesquarepyramidf(const float height, const float base);
double volumetetrahedron(const double height, const double base);
long double volumetetrahedronl(const long double height, const long double base);
float volumetetrahedronf(const float height, const float base);
double volumetorus(const double radius1, const double radius2);
long double volumetorusl(const long double radius1, const long double radius2);
float volumetorusf(const float radius1, const float radius2);


#endif

// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file geometry.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Geometry Equations
@version 2016.03.18

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


#include "geometry.h"


/* FUNCTIONS */


/* HELPER FUNCTIONS */


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
    while ((end - start) > (double)0.00001) {  // Define precision
        mid = (start + end) * (double)0.5;
        midSqr = mid * mid;
        if (midSqr == num) return mid;  // Exact sqrt value
        else if (midSqr < num) start = mid;
        else end = mid;
    }
    return ((start + end) * (double)0.5);
}


/** Private Function: Returns the Square-Root of a positive number (Limit: 1000000000.0) */
static float squarerootf(const float num) {
    if (num < (float)0.0F) return -1.0F;
    else if (floorf(num) == num && num <= (float)81.0F) {
        if (num == (float)0.0F) return 0.0F;
        else if (num == (float)1.0F) return 1.0F;
        else if (num == (float)4.0F) return 2.0F;
        else if (num == (float)9.0F) return 3.0F;
        else if (num == (float)16.0F) return 4.0F;
        else if (num == (float)25.0F) return 5.0F;
        else if (num == (float)36.0F) return 6.0F;
        else if (num == (float)49.0F) return 7.0F;
        else if (num == (float)64.0F) return 8.0F;
        else if (num == (float)81.0F) return 9.0F;
    }
    register float start = (float)0.0F;  // if num < 1; then 0 < num < sqrt(num); else 0 < sqrt(num) < num
    register float end = (num < (float)1.0F ? (float)1.0F : num);
    register float mid, midSqr;
    while ((end - start) > (float)0.0001F) {  // Define precision
        mid = (start + end) * (float)0.5F;
        midSqr = mid * mid;
        if (midSqr == num) return mid;  // Exact sqrt value
        else if (midSqr < num) start = mid;
        else end = mid;
    }
    return ((start + end) * (float)0.5F);
}


/** Private Function: Returns the Square-Root of a positive number */
static long double squarerootl(const long double num) {
    if (num < (long double)0.0L) return -1.0L;
    else if (floorl(num) == num && num <= (long double)81.0L) {
        if (num == (long double)0.0L) return 0.0L;
        else if (num == (long double)1.0L) return 1.0L;
        else if (num == (long double)4.0L) return 2.0L;
        else if (num == (long double)9.0L) return 3.0L;
        else if (num == (long double)16.0L) return 4.0L;
        else if (num == (long double)25.0L) return 5.0L;
        else if (num == (long double)36.0L) return 6.0L;
        else if (num == (long double)49.0L) return 7.0L;
        else if (num == (long double)64.0L) return 8.0L;
        else if (num == (long double)81.0L) return 9.0L;
    }
    register long double start = (long double)0.0L;  // if num < 1; then 0 < num < sqrt(num); else 0 < sqrt(num) < num
    register long double end = (num < (long double)1.0L ? (long double)1.0L : num);
    register long double mid, midSqr;
    while ((end - start) > (long double)0.00000001L) {  // Define precision
        mid = (start + end) * (long double)0.5L;
        midSqr = mid * mid;
        if (midSqr == num) return mid;  // Exact sqrt value
        else if (midSqr < num) start = mid;
        else end = mid;
    }
    return ((start + end) * (long double)0.5L);
}


/* BOOLEAN TESTS */


/** Test if the point is within the rectangle */
int is_point_in_rectangle(const point p, const rectangle r) {
    return ((p.x <= r.width) && (p.y <= r.height));
}


/* COORDINATES */


/** Return the polar-coordinates for the given (x,y)-coordinates */
doublepair_t xy2polar(const double x, const double y) {
    doublepair_t polar;
    polar.y = (1.0 / tan(y / x));  // tan-1(y / x); angle
    polar.x = squareroot((x * x) + (y * y));  // hypot
    return polar;
}


/** Return the (x,y)-coordinates for the given polar-coordinates */
doublepair_t polar2xy(const double hypo, const double angle) {
    doublepair_t xy;
    xy.x = (hypo * cos(angle));
    xy.y = (hypo * sin(angle));
    return xy;
}


/* DISTANCE */


/** Return the distance between two points (double) */
double distance(const double x1, const double y1, const double x2, const double y2) {
    return squareroot(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}


/** Return the distance between two points (long double) */
long double distancel(const long double x1, const long double y1, const long double x2, const long double y2) {
    return squarerootl(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}


/** Return the distance between two points (float) */
float distancef(const float x1, const float y1, const float x2, const float y2) {
    return squarerootf(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}


/** Return the distance between two points (double) */
double distance_point(point location1, point location2) {
    return squareroot(((location2.x - location1.x) * (location2.x - location1.x)) + ((location2.y - location1.y) * (location2.y - location1.y)));
}


/** Return the distance between two points (long double) */
long double distance_pointl(pointl location1, pointl location2) {
    return squarerootl(((location2.x - location1.x) * (location2.x - location1.x)) + ((location2.y - location1.y) * (location2.y - location1.y)));
}


// linelength_point() is an alias for distance_point()
double (* linelength_point)(point location1, point location2) = &distance_point;
// linelength_pointl() is an alias for distance_pointl()
long double (* linelength_pointl)(pointl location1, pointl location2) = &distance_pointl;


/* AREA */


/** Return the area of a circle (double) */
double areacircle(const double radius) {
    return (PI * radius * radius);
}


/** Return the area of a circle (long double) */
long double areacirclel(const long double radius) {
    return (PIl * radius * radius);
}


/** Return the area of a ellipse (double) */
double areaellipse(const double radius1, const double radius2) {
    return (PI * radius1 * radius2);
}


/** Return the area of a ellipse (long double) */
long double areaellipsel(const long double radius1, const long double radius2) {
    return (PIl * radius1 * radius2);
}


/** Return the area of a equilateral triangle (double) */
double areaequilateraltriangle(const double base) {
    return ((base * base) * SQRT_3_DIV_4);
}


/** Return the area of a equilateral triangle (long double) */
long double areaequilateraltrianglel(const long double base) {
    return ((base * base) * SQRT_3_DIV_4l);
}


/** Return the area of a parallelogram (double) */
double areaparallelogram(const double base, const double height) {
    return (base * height);
}


/** Return the area of a parallelogram (double) */
long double areaparallelograml(const long double base, const long double height) {
    return (base * height);
}


/** Return the area of a rectangle (double) */
double arearectangle(const double length, const double width) {
    return (length * width);
}


/** Return the area of a rectangle (long double) */
long double arearectanglel(const long double length, const long double width) {
    return (length * width);
}


/** Return the area of a rhombus (double) */
double arearhombus(const double base) {
    return (base * base);
}


/** Return the area of a rhombus (long double) */
long double arearhombusl(const long double base) {
    return (base * base);
}


/** Return the area of a circular sector (double) */
double areasector(const double radius, const double angle_radians) {
    return ((radius * radius * angle_radians) * (double)0.5);
}


/** Return the area of a circular sector (long double) */
long double areasectorl(const long double radius, const long double angle_radians) {
    return ((radius * radius * angle_radians) * (long double)0.5L);
}


/** Return the area of a square (double) */
double areasquare(const double length) {
    return (length * length);
}


/** Return the area of a square (long double) */
long double areasquarel(const long double length) {
    return (length * length);
}


/** Return the area of a square (long int) */
unsigned long int areasquare_int(const unsigned long int length) {
    return (length * length);
}


/** Return the area of a square (unsigned long long int) */
ullint areasquare_ull(const ullint length) {
    return (length * length);
}


/** Return the area of a square (square) */
double areasquare_shape(const square shape) {
    return (shape.length * shape.length);
}


/** Return the area of a square (square) */
long double areasquare_shapel(const squarel shape) {
    return (shape.length * shape.length);
}


/** Return the area of a trapezoid (double) */
double areatrapezoid(const double base1, const double base2, const double height) {
    return (((base1 + base2) * (double)0.5) * height);
}


/** Return the area of a trapezoid (long double) */
long double areatrapezoidl(const long double base1, const long double base2, const long double height) {
    return (((base1 + base2) * (long double)0.5L) * height);
}


/** Return the area of a triangle (double) */
double areatriangle(const double base, const double height) {
    return ((base * height) * (double)0.5);
}


/** Return the area of a triangle (long double) */
long double areatrianglel(const long double base, const long double height) {
    return ((base * height) * (long double)0.5L);
}


/* LENGTH */


/** Return the length of an arc (double) */
double lengtharc(const double radius, const double angle_radians) {
    return (radius * angle_radians);
}


/** Return the length of an arc (long double) */
long double lengtharcl(const long double radius, const long double angle_radians) {
    return (radius * angle_radians);
}


/** Return the length of an arc (float) */
float lengtharcf(const float radius, const float angle_radians) {
    return (radius * angle_radians);
}


/* PERIMETER */


/** Return the perimeter of a circle (double) */
double perimetercircle(const double radius) {
    return (PI2 * radius);
}


/** Return the perimeter of a circle (long double) */
long double perimetercirclel(const long double radius) {
    return (PI2l * radius);
}


/** Return the perimeter of a parallelogram (double) */
double perimeterparallelogram(const double base, const double side) {
    return (base + base + side + side);
}


/** Return the perimeter of a parallelogram (long double) */
long double perimeterparallelograml(const long double base, const long double side) {
    return (base + base + side + side);
}


/** Return the perimeter of a rhombus (double) */
double perimeterrhombus(const double base) {
    return (base + base + base + base);
}


/** Return the perimeter of a rhombus (long double) */
long double perimeterrhombusl(const long double base) {
    return (base + base + base + base);
}


/** Return the perimeter of a rectangle (double) */
double perimeterrectangle(const double length, const double width) {
    return (length + length + width + width);
}


/** Return the perimeter of a rectangle (long double) */
long double perimeterrectanglel(const long double length, const long double width) {
    return (length + length + width + width);
}


/** Return the perimeter of a square (double) */
double perimetersquare(const double side) {
    return (side + side + side + side);
}


/** Return the perimeter of a square (long double) */
long double perimetersquarel(const long double side) {
    return (side + side + side + side);
}


/** Return the perimeter of a trapezoid (double) */
double perimetertrapezoid(const double side1, const double side2, const double side3, const double side4) {
    return (side1 + side2 + side3 + side4);
}


/** Return the perimeter of a trapezoid (long double) */
long double perimetertrapezoidl(const long double side1, const long double side2, const long double side3, const long double side4) {
    return (side1 + side2 + side3 + side4);
}


/** Return the perimeter of a triangle (double) */
double perimetertriangle(const double side1, const double side2, const double side3) {
    return (side1 + side2 + side3);
}


/** Return the perimeter of a triangle (long double) */
long double perimetertrianglel(const long double side1, const long double side2, const long double side3) {
    return (side1 + side2 + side3);
}


/* SURFACE AREA */


/** Return the surface area of a cone (double) */
double surfaceareacone(const double radius, const double height) {
    return (radius * PI * squareroot((radius * radius) + (height * height)));
}


/** Return the surface area of a cone (long double) */
long double surfaceareaconel(const long double radius, const long double height) {
    return (radius * PIl * squarerootl((radius * radius) + (height * height)));
}


/** Return the surface area of a cone (float) */
float surfaceareaconef(const float radius, const float height) {
    return (radius * PIf * squarerootf((radius * radius) + (height * height)));
}


/** Return the surface area of a cube (double) */
double surfaceareacube(const double length) {
    return (6.0 * (length * length));
}


/** Return the surface area of a cube (long double) */
long double surfaceareacubel(const long double length) {
    return (6.0L * (length * length));
}


/** Return the surface area of a cube (float) */
float surfaceareacubef(const float length) {
    return (6.0F * (length * length));
}


/** Return the surface area of a cylinder (double) */
double surfaceareacylinder(const double radius, const double height) {
    return (radius * height * PI2);
}


/** Return the surface area of a cylinder (long double) */
long double surfaceareacylinderl(const long double radius, const long double height) {
    return (radius * height * PI2l);
}


/** Return the surface area of a cylinder (float) */
float surfaceareacylinderf(const float radius, const float height) {
    return (radius * height * PI2f);
}


/** Return the surface area of a rectangular prism (double) */
double surfacearearectangularprism(const double length, const double width, const double height) {
    return (2.0 * (length * width + height * width + height * length));
}


/** Return the surface area of a rectangular prism (long double) */
long double surfacearearectangularprisml(const long double length, const long double width, const long double height) {
    return (2.0L * (length * width + height * width + height * length));
}


/** Return the surface area of a rectangular prism (float) */
float surfacearearectangularprismf(const float length, const float width, const float height) {
    return (2.0F * (length * width + height * width + height * length));
}


/** Return the surface area of a sphere (double) */
double surfaceareasphere(const double radius) {
    return (radius * radius * PI4);
}


/** Return the surface area of a sphere (long double) */
long double surfaceareaspherel(const long double radius) {
    return (radius * radius * PI4l);
}


/** Return the surface area of a sphere (float) */
float surfaceareaspheref(const float radius) {
    return (radius * radius * PI4f);
}


/** Return the surface area of a square pyramid (double) */
double surfaceareasquarepyramid(const double side, const double length) {
    return ((side * side) + (2.0 * side * length));
}


/** Return the surface area of a square pyramid (long double) */
long double surfaceareasquarepyramidl(const long double side, const long double length) {
    return ((side * side) + (2.0L * side * length));
}


/** Return the surface area of a square pyramid (float) */
float surfaceareasquarepyramidf(const float side, const float length) {
    return ((side * side) + (2.0F * side * length));
}


/** Return the surface area of a torus (double) */
double surfaceareatorus(const double radius1, const double radius2) {
    return (PI * ((radius2 * radius2) - (radius1 * radius1)));
}


/** Return the surface area of a torus (long double) */
long double surfaceareatorusl(const long double radius1, const long double radius2) {
    return (PIl * ((radius2 * radius2) - (radius1 * radius1)));
}


/** Return the surface area of a torus (float) */
float surfaceareatorusf(const float radius1, const float radius2) {
    return (PIf * ((radius2 * radius2) - (radius1 * radius1)));
}



/* VOLUME */


/** Return the volume of a cone (double) */
double volumecone(const double radius, const double height) {
    return (PI_1_3 * radius * radius * height);
}


/** Return the volume of a cone (long double) */
long double volumeconel(const long double radius, const long double height) {
    return (PI_1_3l * radius * radius * height);
}


/** Return the volume of a cone (float) */
float volumeconef(const float radius, const float height) {
    return (PI_1_3f * radius * radius * height);
}


/** Return the volume of a cylinder (double) */
double volumecylinder(const double radius, const double height) {
    return (PI * radius * radius * height);
}


/** Return the volume of a cylinder (long double) */
long double volumecylinderl(const long double radius, const long double height) {
    return (PIl * radius * radius * height);
}


/** Return the volume of a cylinder (float) */
float volumecylinderf(const float radius, const float height) {
    return (PIf * radius * radius * height);
}


/** Return the volume of a ellipsoid (double) */
double volumeellipsoid(const double radius1, const double radius2, const double radius3) {
    return (PI_4_3 * radius1 * radius2 * radius3);
}


/** Return the volume of a ellipsoid (long double) */
long double volumeellipsoidl(const long double radius1, const long double radius2, const long double radius3) {
    return (PI_4_3l * radius1 * radius2 * radius3);
}


/** Return the volume of a ellipsoid (float) */
float volumeellipsoidf(const float radius1, const float radius2, const float radius3) {
    return (PI_4_3f * radius1 * radius2 * radius3);
}


/** Return the volume of a parallelepiped (double) */
double volumeparallelepiped(const double length, const double width, const double height) {
    return (length * width * height);
}


/** Return the volume of a parallelepiped (long double) */
long double volumeparallelepipedl(const long double length, const long double width, const long double height) {
    return (length * width * height);
}


/** Return the volume of a parallelepiped (float) */
float volumeparallelepipedf(const float length, const float width, const float height) {
    return (length * width * height);
}


/** Return the volume of a hemisphere (double) */
double volumehemisphere(const double radius) {
    return (PI_2_3 * radius * radius * radius);
}


/** Return the volume of a hemisphere (long double) */
long double volumehemispherel(const long double radius) {
    return (PI_2_3l * radius * radius * radius);
}


/** Return the volume of a hemisphere (float) */
float volumehemispheref(const float radius) {
    return (PI_2_3f * radius * radius * radius);
}


/** Return the volume of a prism (double) */
double volumeprism(const double length, const double base) {
    return (length * base);
}


/** Return the volume of a prism (long double) */
long double volumeprisml(const long double length, const long double base) {
    return (length * base);
}


/** Return the volume of a prism (float) */
float volumeprismf(const float length, const float base) {
    return (length * base);
}


/** Return the volume of a rectanglar prism (double) */
double volumerectanglarprism(const double length, const double width, const double height) {
    return (length * width * height);
}


/** Return the volume of a rectanglar prism (long double) */
long double volumerectanglarprisml(const long double length, const long double width, const long double height) {
    return (length * width * height);
}


/** Return the volume of a rectanglar prism (float) */
float volumerectanglarprismf(const float length, const float width, const float height) {
    return (length * width * height);
}


/** Return the volume of a sphere (double) */
double volumesphere(const double radius) {
    return (PI_4_3 * radius * radius * radius);
}


/** Return the volume of a sphere (long double) */
long double volumespherel(const long double radius) {
    return (PI_4_3l * radius * radius * radius);
}


/** Return the volume of a sphere (float) */
float volumespheref(const float radius) {
    return (PI_4_3f * radius * radius * radius);
}


/** Return the volume of a square pyramid (double) */
double volumesquarepyramid(const double height, const double base) {
    return ((height * base) * 0.333333333);
}


/** Return the volume of a square pyramid (long double) */
long double volumesquarepyramidl(const long double height, const long double base) {
    return ((height * base) * 0.333333333333L);
}


/** Return the volume of a square pyramid (float) */
float volumesquarepyramidf(const float height, const float base) {
    return ((height * base) * 0.3333333F);
}


/** Return the volume of a tetrahedron (double) */
double volumetetrahedron(const double height, const double base) {
    return ((height * base) * 0.333333333);
}


/** Return the volume of a tetrahedron (long double) */
long double volumetetrahedronl(const long double height, const long double base) {
    return ((height * base) * 0.3333333333L);
}


/** Return the volume of a tetrahedron (float) */
float volumetetrahedronf(const float height, const float base) {
    return ((height * base) * 0.3333333F);
}


/** Return the volume of a torus (double) */
double volumetorus(const double radius1, const double radius2) {
    return (PI_SQUARED_1_4 * ((radius1 + radius2) * ((radius1 - radius2) * (radius1 - radius2))));
}


/** Return the volume of a torus (long double) */
long double volumetorusl(const long double radius1, const long double radius2) {
    return (PI_SQUARED_1_4l * ((radius1 + radius2) * ((radius1 - radius2) * (radius1 - radius2))));
}


/** Return the volume of a torus (float) */
float volumetorusf(const float radius1, const float radius2) {
    return (PI_SQUARED_1_4f * ((radius1 + radius2) * ((radius1 - radius2) * (radius1 - radius2))));
}

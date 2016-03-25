// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file mathfunc.swg
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@brief SWIG wrapper for mathfunc.c
@version 2016.03.25
*/


/* SWIG Renaming */


/* %rename(NEWNAME) ORIG_NAME; */


/* Header files and function declarations */


%module mathfunc
%{
/*
%include "mathfunc.h"
#include <math.h>
*/
#define DATATYPES_128BITS_SEEN
#define IMAGINARY_NUMBER_CONSTANTS_SEEN
#define NUMBER_TUPLES_SEEN
#include "MACROS.h"

#ifdef __GNUC__
unsigned int fib(const unsigned int num) __attribute__((const, flatten));
#else
unsigned int fib(const unsigned int num);
#endif
/* TRIGONOMETRY (DOUBLES) */
#ifdef __GNUC__
#ifndef SWIGPHP
double ATAN2(const double y, const double x) __attribute__((const, flatten));
#endif
double sinpi(const double num) __attribute__((const, flatten));
double crd(const double radians) __attribute__((const, flatten));
double acot(const double radians) __attribute__((const, flatten));
double arccot(const double radians) __attribute__((const, flatten));
double acoth(const double radians) __attribute__((const, flatten));
double arccoth(const double radians) __attribute__((const, flatten));
double coth(const double radians) __attribute__((const, flatten));
double cot(const double radians) __attribute__((const, flatten));
double acsc(const double radians) __attribute__((const, flatten));
double arccsc(const double radians) __attribute__((const, flatten));
double acsch(const double radians) __attribute__((const, flatten));
double arccsch(const double radians) __attribute__((const, flatten));
double csch(const double radians) __attribute__((const, flatten));
double csc(const double radians) __attribute__((const, flatten));
double asec(const double radians) __attribute__((const, flatten));
double arcsec(const double radians) __attribute__((const, flatten));
double asech(const double radians) __attribute__((const, flatten));
double arcsech(const double radians) __attribute__((const, flatten));
double sech(const double radians) __attribute__((const, flatten));
double sec(const double radians) __attribute__((const, flatten));
double arcversin(const double radians) __attribute__((const, flatten));
double arcversinh(const double radians) __attribute__((const, flatten));
double versinh(const double radians) __attribute__((const, flatten));
double versin(const double radians) __attribute__((const, flatten));
double arcvercos(const double radians) __attribute__((const, flatten));
double arcvercosh(const double radians) __attribute__((const, flatten));
double vercosh(const double radians) __attribute__((const, flatten));
double vercos(const double radians) __attribute__((const, flatten));
double haversin(const double radians) __attribute__((const, flatten));
double hacoversin(const double radians) __attribute__((const, flatten));
#else
#ifndef SWIGPHP
double ATAN2(const double y, const double x);
#endif
double sinpi(const double num);
double crd(const double radians);
double acot(const double radians);
double arccot(const double radians);
double acoth(const double radians);
double arccoth(const double radians);
double coth(const double radians);
double cot(const double radians);
double acsc(const double radians);
double arccsc(const double radians);
double acsch(const double radians);
double arccsch(const double radians);
double csch(const double radians);
double csc(const double radians);
double asec(const double radians);
double arcsec(const double radians);
double asech(const double radians);
double arcsech(const double radians);
double sech(const double radians);
double sec(const double radians);
double arcversin(const double radians);
double arcversinh(const double radians);
double versinh(const double radians);
double versin(const double radians);
double arcvercos(const double radians);
double arcvercosh(const double radians);
double vercosh(const double radians);
double vercos(const double radians);
double haversin(const double radians);
double hacoversin(const double radians);
#endif
/* EXTERNAL TRIGONOMETRY (DOUBLES) */
#ifdef __GNUC__
double arcexcot(const double radians) __attribute__((const, flatten));
double arcexcoth(const double radians) __attribute__((const, flatten));
double excoth(const double radians) __attribute__((const, flatten));
double excot(const double radians) __attribute__((const, flatten));
double arcexcsc(const double radians) __attribute__((const, flatten));
double arcexcsch(const double radians) __attribute__((const, flatten));
double excsch(const double radians) __attribute__((const, flatten));
double excsc(const double radians) __attribute__((const, flatten));
double arcexsec(const double radians) __attribute__((const, flatten));
double arcexsech(const double radians) __attribute__((const, flatten));
double exsech(const double radians) __attribute__((const, flatten));
double exsec(const double radians) __attribute__((const, flatten));
#else
double arcexcot(const double radians);
double arcexcoth(const double radians);
double excoth(const double radians);
double excot(const double radians);
double arcexcsc(const double radians);
double arcexcsch(const double radians);
double excsch(const double radians);
double excsc(const double radians);
double arcexsec(const double radians);
double arcexsech(const double radians);
double exsech(const double radians);
double exsec(const double radians);
#endif
/* SPECIAL TRIGONOMETRIC FUNCTIONS (DOUBLES) */
#ifdef __GNUC__
double cos_arcsin(const double radians) __attribute__((const, flatten));
double cos_arctan(const double radians) __attribute__((const, flatten));
double sin_arcsec(const double radians) __attribute__((const, flatten));
double sin_arctan(const double radians) __attribute__((const, flatten));
#else
double cos_arcsin(const double radians);
double cos_arctan(const double radians);
double sin_arcsec(const double radians);
double sin_arctan(const double radians);
#endif
/* TESTS */
#ifdef __GNUC__
int istriangular(const long num) __attribute__((const, flatten));
int isdoubletriangular(const double num) __attribute__((const, flatten));
int ishexagonal(const long num) __attribute__((const, flatten));
int isheptagonal(const long num) __attribute__((const, flatten));
#else
int istriangular(const long num);
int isdoubletriangular(const double num);
int ishexagonal(const long num);
int isheptagonal(const long num);
#endif


%}


/* SWIG Declarations */


unsigned int fib(const unsigned int num);
// TRIGONOMETRY (DOUBLES)
#ifndef SWIGPHP
double ATAN2(const double y, const double x);
#endif
double sinpi(const double num);
double crd(const double radians);
double acot(const double radians);
double arccot(const double radians);
double acoth(const double radians);
double arccoth(const double radians);
double coth(const double radians);
double cot(const double radians);
double acsc(const double radians);
double arccsc(const double radians);
double acsch(const double radians);
double arccsch(const double radians);
double csch(const double radians);
double csc(const double radians);
double asec(const double radians);
double arcsec(const double radians);
double asech(const double radians);
double arcsech(const double radians);
double sech(const double radians);
double sec(const double radians);
double arcversin(const double radians);
double arcversinh(const double radians);
double versinh(const double radians);
double versin(const double radians);
double arcvercos(const double radians);
double arcvercosh(const double radians);
double vercosh(const double radians);
double vercos(const double radians);
double haversin(const double radians);
double hacoversin(const double radians);
// EXTERNAL TRIGONOMETRY (DOUBLES)
double arcexcot(const double radians);
double arcexcoth(const double radians);
double excoth(const double radians);
double excot(const double radians);
double arcexcsc(const double radians);
double arcexcsch(const double radians);
double excsch(const double radians);
double excsc(const double radians);
double arcexsec(const double radians);
double arcexsech(const double radians);
double exsech(const double radians);
double exsec(const double radians);
// SPECIAL TRIGONOMETRIC FUNCTIONS (DOUBLES)
double cos_arcsin(const double radians);
double cos_arctan(const double radians);
double sin_arcsec(const double radians);
double sin_arctan(const double radians);
// TESTS
int istriangular(const long num);
int isdoubletriangular(const double num);
int ishexagonal(const long num);
int isheptagonal(const long num);

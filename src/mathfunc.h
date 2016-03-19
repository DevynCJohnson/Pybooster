// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file mathfunc.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Math Functions (header)
@version 2016.03.18

@section DESCRIPTION
Numerous mathematical and trigonometric functions.
This extends the standard math library by providing by offering faster alternatives.
Such functions include squareroot, fractorial, fib, haversin, isprime, ishexagonal, etc.

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


#ifndef FILE_MATHFUNC_SEEN
#define FILE_MATHFUNC_SEEN


#include "MACROS.h"

#include <math.h>

#include "MATH_MACROS.h"
#include "math_types.h"


/* TRIGONOMETRY FUNCTION MACROS */
#define vcs(x)   (vercos((x)))
#define vercosine(x)   (vercos((x)))
#define covercos(x)   (vercos((x)))
#define cvc(x)   (vercos((x)))
#define coversine(x)   (vercos((x)))
#define cosiv(x)   (vercos((x)))
#define cvs(x)   (vercos((x)))
#define ver(x)   (versin((x)))
#define sinver(x)   (versin((x)))
#define siv(x)   (versin((x)))
#define vers(x)   (versin((x)))
#define hav(x)   (haversin((x)))
/* ANGLES */
#ifdef __GNUC__
double complement_angle_deg(const double angle) __attribute__((const));
long double complement_angle_degl(const long double angle) __attribute__((const));
float complement_angle_degf(const float angle) __attribute__((const));
double supplement_angle_deg(const double angle) __attribute__((const));
long double supplement_angle_degl(const long double angle) __attribute__((const));
float supplement_angle_degf(const float angle) __attribute__((const));
double arc_angle(const double arc_length, const double radius) __attribute__((const));
#else
double complement_angle_deg(const double angle);
long double complement_angle_degl(const long double angle);
float complement_angle_degf(const float angle);
double supplement_angle_deg(const double angle);
long double supplement_angle_degl(const long double angle);
float supplement_angle_degf(const float angle);
double arc_angle(const double arc_length, const double radius);
#endif
/* GRAPHING */
#ifdef __GNUC__
double sin_wave_equation(const double amplitude, const double angle) __attribute__((const, flatten));
double sawtooth(const double x) __attribute__((const, flatten));
double sawtooth2(const double x, const double period, const double amplitude) __attribute__((const, flatten));
double sigmoid(const double x) __attribute__((const, flatten));
double squarewave(const double x) __attribute__((const, flatten));
int trianglewave(const int x) __attribute__((const, flatten));
#else
double sin_wave_equation(const double amplitude, const double angle);
double sawtooth(const double x);
double sawtooth2(const double x, const double period, const double amplitude);
double sigmoid(const double x);
double squarewave(const double x);
int trianglewave(const int x);
#endif
/* LOGARITHMS */
#ifdef __GNUC__
double ln(const double num) __attribute__((const, flatten));
double lnp1(const double num) __attribute__((const, flatten));
double log_plus1(const double num) __attribute__((const, flatten));
float log_plus1f(const float num) __attribute__((const, flatten));
long double log_plus1l(const long double num) __attribute__((const, flatten));
double LOG(const double num) __attribute__((const, flatten));
double LOG2(const double num) __attribute__((const, flatten));
double LOG10(const double num) __attribute__((const, flatten));
#else
double ln(const double num);
double lnp1(const double num);
double log_plus1(const double num);
float log_plus1f(const float num);
long double log_plus1l(const long double num);
double LOG(const double num);
double LOG2(const double num);
double LOG10(const double num);
#endif
/* POWERS */
#ifdef __GNUC__
double exp_minus1(const double num) __attribute__((const, flatten));
float exp_minus1f(const float num) __attribute__((const, flatten));
long double exp_minus1l(const long double num) __attribute__((const, flatten));
unsigned long long int pow2(const unsigned int num) __attribute__((const, flatten));
signed long long int pow2_longlong(const signed long long int num) __attribute__((const, flatten));
double ipow(double num, const int exp) __attribute__((const, flatten));
double pow_ten(const signed int num) __attribute__((const, flatten));
long double pow_tenl(const signed int num) __attribute__((const, flatten));
unsigned long long int pow_ten_int(const unsigned int num) __attribute__((const, flatten));
unsigned long long int pow_ten_int_fast(const unsigned int num) __attribute__((const, flatten));
double pow_ten_pos(const unsigned int num) __attribute__((const, flatten));
float pow_ten_posf(const unsigned int num) __attribute__((const, flatten));
long double pow_ten_posl(const unsigned long int num) __attribute__((const, flatten));
double pow_ten_neg(const signed int num) __attribute__((const, flatten));
float pow_ten_negf(const signed int num) __attribute__((const, flatten));
long double pow_ten_negl(const slint num) __attribute__((const, flatten));
ullint unsigned_pow(const unsigned int base, const unsigned int exponent) __attribute__((const, flatten));
double signed_pow(const signed int base, const signed int exponent) __attribute__((const, flatten));
long double signed_powl(const slint base, const slint exponent) __attribute__((const, flatten));
signed int mod_pow(const signed int base, const signed int exponent, const signed int modulus) __attribute__((const, flatten));
sllint mod_pow_longlong(const sllint base, const sllint exponent, const sllint modulus) __attribute__((const, flatten));
#else
double exp_minus1(const double num);
float exp_minus1f(const float num);
long double exp_minus1l(const long double num);
unsigned long long int pow2(const unsigned int num);
signed long long int pow2_longlong(const signed long long int num);
double ipow(double num, const int exp);
double pow_ten(const signed int num);
long double pow_tenl(const signed int num);
unsigned long long int pow_ten_int(const unsigned int num);
unsigned long long int pow_ten_int_fast(const unsigned int num);
double pow_ten_pos(const unsigned int num);
float pow_ten_posf(const unsigned int num);
long double pow_ten_posl(const unsigned long int num);
double pow_ten_neg(const signed int num);
float pow_ten_negf(const signed int num);
long double pow_ten_negl(const slint num);
ullint unsigned_pow(const unsigned int base, const unsigned int exponent);
double signed_pow(const signed int base, const signed int exponent);
long double signed_powl(const slint base, const slint exponent);
signed int mod_pow(const signed int base, const signed int exponent, const signed int modulus);
sllint mod_pow_longlong(const sllint base, const sllint exponent, const sllint modulus);
#endif
/* ROOTS */
#ifdef __GNUC__
ullint sqrtull(const ullint num) __attribute__((const, flatten));
double squareroot(const double num) __attribute__((const, flatten));
float squarerootf(const float num) __attribute__((const, flatten));
long double squarerootl(const long double num) __attribute__((const, flatten));
uint8_t sqrt16(const uint16_t num) __attribute__((const, flatten));
uint16_t sqrt32(const uint32_t num) __attribute__((const, flatten));
uint32_t sqrt64(const uint64_t num) __attribute__((const, flatten));
uint8_t isqrt8(const uint8_t num) __attribute__((const, flatten));
uint16_t isqrt16(const uint16_t num) __attribute__((const, flatten));
uint32_t isqrt32(const uint32_t num) __attribute__((const, flatten));
uint64_t isqrt64(const uint64_t num) __attribute__((const, flatten));
double triangular_root(const long num) __attribute__((const, flatten));
double hexagonal_root(const long num) __attribute__((const, flatten));
double heptagonal_root(const long num) __attribute__((const, flatten));
#else
ullint sqrtull(const ullint num);
double squareroot(const double num);
float squarerootf(const float num);
long double squarerootl(const long double num);
uint8_t sqrt16(const uint16_t num);
uint16_t sqrt32(const uint32_t num);
uint32_t sqrt64(const uint64_t num);
uint8_t isqrt8(const uint8_t num);
uint16_t isqrt16(const uint16_t num);
uint32_t isqrt32(const uint32_t num);
uint64_t isqrt64(const uint64_t num);
double triangular_root(const long num);
double hexagonal_root(const long num);
double heptagonal_root(const long num);
#endif
/* FACTORIALS */
#ifdef __GNUC__
unsigned long long int factorial(const unsigned int num) __attribute__((const, flatten));
sllint factoriallonglong(const sllint num) __attribute__((const, flatten));
ullint doublefactorial(const unsigned int num) __attribute__((const, flatten));
sllint doublefactoriallonglong(const sllint num) __attribute__((const, flatten));
ullint quadfactorial(const unsigned int num) __attribute__((const, flatten));
sllint quadfactoriallonglong(const sllint num) __attribute__((const, flatten));
ullint superfactorial(const unsigned int num) __attribute__((const, flatten));
sllint superfactoriallonglong(const sllint num) __attribute__((const, flatten));
int unfactorial(const int num) __attribute__((const, flatten));
uint64_t unfactorial64(const uint64_t num) __attribute__((const, flatten));
#else
unsigned long long int factorial(const unsigned int num);
sllint factoriallonglong(const sllint num);
ullint doublefactorial(const unsigned int num);
sllint doublefactoriallonglong(const sllint num);
ullint quadfactorial(const unsigned int num);
sllint quadfactoriallonglong(const sllint num);
ullint superfactorial(const unsigned int num);
sllint superfactoriallonglong(const sllint num);
int unfactorial(const int num);
uint64_t unfactorial64(const uint64_t num);
#endif
/* NUMBER GENERATORS */
#ifdef __GNUC__
unsigned int pronic(const unsigned int num) __attribute__((const, flatten));
ullint pronicull(const ullint num) __attribute__((const, flatten));
sllint proniclonglong(const sllint num) __attribute__((const, flatten));
#ifdef UINT128_SUPPORTED
uint128_t pronic_u128(const uint128_t num) __attribute__((const, flatten));
#endif
unsigned int fib(const unsigned int num) __attribute__((const, flatten));
unsigned long int longfib(const unsigned long int num) __attribute__((const, flatten));
sllint longlongfib(const sllint num) __attribute__((const, flatten));
unsigned int triangular_num(const unsigned int num) __attribute__((const, flatten));
ullint triangular_numull(const ullint num) __attribute__((const, flatten));
sllint triangular_numlonglong(const sllint num) __attribute__((const, flatten));
#ifdef UINT128_SUPPORTED
uint128_t triangular_u128(const uint128_t num) __attribute__((const, flatten));
#endif
unsigned int hexagonal_num(const unsigned int num) __attribute__((const, flatten));
ullint hexagonal_numull(const ullint num) __attribute__((const, flatten));
sllint hexagonal_numlonglong(const sllint num) __attribute__((const, flatten));
#ifdef UINT128_SUPPORTED
uint128_t hexagonal_u128(const uint128_t num) __attribute__((const, flatten));
#endif
unsigned int heptagonal_num(const unsigned int num) __attribute__((const, flatten));
ullint heptagonal_numull(const ullint num) __attribute__((const, flatten));
sllint heptagonal_numlonglong(const sllint num) __attribute__((const, flatten));
#ifdef UINT128_SUPPORTED
uint128_t heptagonal_u128(const uint128_t num) __attribute__((const, flatten));
#endif
unsigned int tetrahedral_num(const unsigned int num) __attribute__((const, flatten));
ullint tetrahedral_numull(const ullint num) __attribute__((const, flatten));
sllint tetrahedral_numlonglong(const sllint num) __attribute__((const, flatten));
#ifdef UINT128_SUPPORTED
uint128_t tetrahedral_u128(const uint128_t num) __attribute__((const, flatten));
#endif
unsigned int pentatope_num(const unsigned int num) __attribute__((const, flatten));
ullint pentatope_numull(const ullint num) __attribute__((const, flatten));
sllint pentatope_numlonglong(const sllint num) __attribute__((const, flatten));
#ifdef UINT128_SUPPORTED
uint128_t pentatope_u128(const uint128_t num) __attribute__((const, flatten));
#endif
unsigned int mersenne_num(const unsigned int num) __attribute__((const, flatten));
ullint mersenne_numull(const ullint num) __attribute__((const, flatten));
sllint mersenne_numlonglong(const sllint num) __attribute__((const, flatten));
#ifdef UINT128_SUPPORTED
uint128_t mersenne_u128(const uint128_t num) __attribute__((const, flatten));
#endif
#else
unsigned int pronic(const unsigned int num);
ullint pronicull(const ullint num);
sllint proniclonglong(const sllint num);
#ifdef UINT128_SUPPORTED
uint128_t pronic_u128(const uint128_t num);
#endif
unsigned int fib(const unsigned int num);
unsigned long int longfib(const unsigned long int num);
sllint longlongfib(const sllint num);
unsigned int triangular_num(const unsigned int num);
ullint triangular_numull(const ullint num);
sllint triangular_numlonglong(const sllint num);
#ifdef UINT128_SUPPORTED
uint128_t triangular_u128(const uint128_t num);
#endif
unsigned int hexagonal_num(const unsigned int num);
ullint hexagonal_numull(const ullint num);
sllint hexagonal_numlonglong(const sllint num);
#ifdef UINT128_SUPPORTED
uint128_t hexagonal_u128(const uint128_t num);
#endif
unsigned int heptagonal_num(const unsigned int num);
ullint heptagonal_numull(const ullint num);
sllint heptagonal_numlonglong(const sllint num);
#ifdef UINT128_SUPPORTED
uint128_t heptagonal_u128(const uint128_t num);
#endif
unsigned int tetrahedral_num(const unsigned int num);
ullint tetrahedral_numull(const ullint num);
sllint tetrahedral_numlonglong(const sllint num);
#ifdef UINT128_SUPPORTED
uint128_t tetrahedral_u128(const uint128_t num);
#endif
unsigned int pentatope_num(const unsigned int num);
ullint pentatope_numull(const ullint num);
sllint pentatope_numlonglong(const sllint num);
#ifdef UINT128_SUPPORTED
uint128_t pentatope_u128(const uint128_t num);
#endif
unsigned int mersenne_num(const unsigned int num);
ullint mersenne_numull(const ullint num);
sllint mersenne_numlonglong(const sllint num);
#ifdef UINT128_SUPPORTED
uint128_t mersenne_u128(const uint128_t num) __attribute__((const, flatten));
#endif
#endif
/* TRIGONOMETRY (DOUBLES) */
#ifdef __GNUC__
double ATAN2(const double y, const double x) __attribute__((const, flatten));
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
double ATAN2(const double y, const double x);
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
/* TRIGONOMETRY (LONG DOUBLES) */
#ifdef __GNUC__
long double crdl(const long double radians) __attribute__((const, flatten));
long double acotl(const long double radians) __attribute__((const, flatten));
long double arccotl(const long double radians) __attribute__((const, flatten));
long double acothl(const long double radians) __attribute__((const, flatten));
long double arccothl(const long double radians) __attribute__((const, flatten));
long double cothl(const long double radians) __attribute__((const, flatten));
long double cotl(const long double radians) __attribute__((const, flatten));
long double acscl(const long double radians) __attribute__((const, flatten));
long double arccscl(const long double radians) __attribute__((const, flatten));
long double acschl(const long double radians) __attribute__((const, flatten));
long double arccschl(const long double radians) __attribute__((const, flatten));
long double cschl(const long double radians) __attribute__((const, flatten));
long double cscl(const long double radians) __attribute__((const, flatten));
long double asecl(const long double radians) __attribute__((const, flatten));
long double arcsecl(const long double radians) __attribute__((const, flatten));
long double asechl(const long double radians) __attribute__((const, flatten));
long double arcsechl(const long double radians) __attribute__((const, flatten));
long double sechl(const long double radians) __attribute__((const, flatten));
long double secl(const long double radians) __attribute__((const, flatten));
long double arcversinl(const long double radians) __attribute__((const, flatten));
long double arcversinhl(const long double radians) __attribute__((const, flatten));
long double versinhl(const long double radians) __attribute__((const, flatten));
long double versinl(const long double radians) __attribute__((const, flatten));
long double arcvercosl(const long double radians) __attribute__((const, flatten));
long double arcvercoshl(const long double radians) __attribute__((const, flatten));
long double vercoshl(const long double radians) __attribute__((const, flatten));
long double vercosl(const long double radians) __attribute__((const, flatten));
long double haversinl(const long double radians) __attribute__((const, flatten));
long double hacoversinl(const long double radians) __attribute__((const, flatten));
#else
long double crdl(const long double radians);
long double acotl(const long double radians);
long double arccotl(const long double radians);
long double acothl(const long double radians);
long double arccothl(const long double radians);
long double cothl(const long double radians);
long double cotl(const long double radians);
long double acscl(const long double radians);
long double arccscl(const long double radians);
long double acschl(const long double radians);
long double arccschl(const long double radians);
long double cschl(const long double radians);
long double cscl(const long double radians);
long double asecl(const long double radians);
long double arcsecl(const long double radians);
long double asechl(const long double radians);
long double arcsechl(const long double radians);
long double sechl(const long double radians);
long double secl(const long double radians);
long double arcversinl(const long double radians);
long double arcversinhl(const long double radians);
long double versinhl(const long double radians);
long double versinl(const long double radians);
long double arcvercosl(const long double radians);
long double arcvercoshl(const long double radians);
long double vercoshl(const long double radians);
long double vercosl(const long double radians);
long double haversinl(const long double radians);
long double hacoversinl(const long double radians);
#endif
/* TRIGONOMETRY (FLOATS) */
#ifdef __GNUC__
float crdf(const float radians) __attribute__((const, flatten));
float acotf(const float radians) __attribute__((const, flatten));
float arccotf(const float radians) __attribute__((const, flatten));
float acothf(const float radians) __attribute__((const, flatten));
float arccothf(const float radians) __attribute__((const, flatten));
float cothf(const float radians) __attribute__((const, flatten));
float cotf(const float radians) __attribute__((const, flatten));
float acscf(const float radians) __attribute__((const, flatten));
float arccscf(const float radians) __attribute__((const, flatten));
float acschf(const float radians) __attribute__((const, flatten));
float arccschf(const float radians) __attribute__((const, flatten));
float cschf(const float radians) __attribute__((const, flatten));
float cscf(const float radians) __attribute__((const, flatten));
float asecf(const float radians) __attribute__((const, flatten));
float arcsecf(const float radians) __attribute__((const, flatten));
float asechf(const float radians) __attribute__((const, flatten));
float arcsechf(const float radians) __attribute__((const, flatten));
float sechf(const float radians) __attribute__((const, flatten));
float secf(const float radians) __attribute__((const, flatten));
float arcversinf(const float radians) __attribute__((const, flatten));
float arcversinhf(const float radians) __attribute__((const, flatten));
float versinhf(const float radians) __attribute__((const, flatten));
float versinf(const float radians) __attribute__((const, flatten));
float arcvercosf(const float radians) __attribute__((const, flatten));
float arcvercoshf(const float radians) __attribute__((const, flatten));
float vercoshf(const float radians) __attribute__((const, flatten));
float vercosf(const float radians) __attribute__((const, flatten));
float haversinf(const float radians) __attribute__((const, flatten));
float hacoversinf(const float radians) __attribute__((const, flatten));
#else
float crdf(const float radians);
float acotf(const float radians);
float arccotf(const float radians);
float acothf(const float radians);
float arccothf(const float radians);
float cothf(const float radians);
float cotf(const float radians);
float acscf(const float radians);
float arccscf(const float radians);
float acschf(const float radians);
float arccschf(const float radians);
float cschf(const float radians);
float cscf(const float radians);
float asecf(const float radians);
float arcsecf(const float radians);
float asechf(const float radians);
float arcsechf(const float radians);
float sechf(const float radians);
float secf(const float radians);
float arcversinf(const float radians);
float arcversinhf(const float radians);
float versinhf(const float radians);
float versinf(const float radians);
float arcvercosf(const float radians);
float arcvercoshf(const float radians);
float vercoshf(const float radians);
float vercosf(const float radians);
float haversinf(const float radians);
float hacoversinf(const float radians);
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
/* EXTERNAL TRIGONOMETRY (LONG DOUBLES) */
#ifdef __GNUC__
long double arcexcotl(const long double radians) __attribute__((const, flatten));
long double arcexcothl(const long double radians) __attribute__((const, flatten));
long double excothl(const long double radians) __attribute__((const, flatten));
long double excotl(const long double radians) __attribute__((const, flatten));
long double arcexcscl(const long double radians) __attribute__((const, flatten));
long double arcexcschl(const long double radians) __attribute__((const, flatten));
long double excschl(const long double radians) __attribute__((const, flatten));
long double excscl(const long double radians) __attribute__((const, flatten));
long double arcexsecl(const long double radians) __attribute__((const, flatten));
long double arcexsechl(const long double radians) __attribute__((const, flatten));
long double exsechl(const long double radians) __attribute__((const, flatten));
long double exsecl(const long double radians) __attribute__((const, flatten));
#else
long double arcexcotl(const long double radians);
long double arcexcothl(const long double radians);
long double excothl(const long double radians);
long double excotl(const long double radians);
long double arcexcscl(const long double radians);
long double arcexcschl(const long double radians);
long double excschl(const long double radians);
long double excscl(const long double radians);
long double arcexsecl(const long double radians);
long double arcexsechl(const long double radians);
long double exsechl(const long double radians);
long double exsecl(const long double radians);
#endif
/* EXTERNAL TRIGONOMETRY (FLOATS) */
#ifdef __GNUC__
float arcexcotf(const float radians) __attribute__((const, flatten));
float arcexcothf(const float radians) __attribute__((const, flatten));
float excothf(const float radians) __attribute__((const, flatten));
float excotf(const float radians) __attribute__((const, flatten));
float arcexcscf(const float radians) __attribute__((const, flatten));
float arcexcschf(const float radians) __attribute__((const, flatten));
float excschf(const float radians) __attribute__((const, flatten));
float excscf(const float radians) __attribute__((const, flatten));
float arcexsecf(const float radians) __attribute__((const, flatten));
float arcexsechf(const float radians) __attribute__((const, flatten));
float exsechf(const float radians) __attribute__((const, flatten));
float exsecf(const float radians) __attribute__((const, flatten));
#else
float arcexcotf(const float radians);
float arcexcothf(const float radians);
float excothf(const float radians);
float excotf(const float radians);
float arcexcscf(const float radians);
float arcexcschf(const float radians);
float excschf(const float radians);
float excscf(const float radians);
float arcexsecf(const float radians);
float arcexsechf(const float radians);
float exsechf(const float radians);
float exsecf(const float radians);
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
/* SPECIAL TRIGONOMETRIC FUNCTIONS (FLOATS) */
#ifdef __GNUC__
float cos_arcsinf(const float radians) __attribute__((const, flatten));
float cos_arctanf(const float radians) __attribute__((const, flatten));
float sin_arcsecf(const float radians) __attribute__((const, flatten));
float sin_arctanf(const float radians) __attribute__((const, flatten));
#else
float cos_arcsinf(const float radians);
float cos_arctanf(const float radians);
float sin_arcsecf(const float radians);
float sin_arctanf(const float radians);
#endif
/* SPECIAL TRIGONOMETRIC FUNCTIONS (LONG DOUBLES) */
#ifdef __GNUC__
long double cos_arcsinl(const long double radians) __attribute__((const, flatten));
long double cos_arctanl(const long double radians) __attribute__((const, flatten));
long double sin_arcsecl(const long double radians) __attribute__((const, flatten));
long double sin_arctanl(const long double radians) __attribute__((const, flatten));
#else
long double cos_arcsinl(const long double radians);
long double cos_arctanl(const long double radians);
long double sin_arcsecl(const long double radians);
long double sin_arctanl(const long double radians);
#endif
/* AVERAGES */
#ifdef __GNUC__
double mean(const int count, ...) __attribute__((const, flatten));
float meanf(const int count, ...) __attribute__((const, flatten));
long double meanl(const long long int count, ...) __attribute__((const, flatten));
double longmean(const slint count, ...) __attribute__((const, flatten));
#else
double mean(const int count, ...);
float meanf(const int count, ...);
long double meanl(const long long int count, ...);
double longmean(const slint count, ...);
#endif
/* COMPARISONS */
#ifndef OSWINDOWS
#   ifdef __GNUC__
int max(const int count, ...) __attribute__((const, flatten));
int min(const int count, ...) __attribute__((const, flatten));
#   else
int max(const int count, ...);
int min(const int count, ...);
#   endif
#endif
#ifdef __GNUC__
float maxf(const int count, ...) __attribute__((const, flatten));
float minf(const int count, ...) __attribute__((const, flatten));
double maxd(const int count, ...) __attribute__((const, flatten));
double mind(const int count, ...) __attribute__((const, flatten));
#else
float maxf(const int count, ...);
float minf(const int count, ...);
double maxd(const int count, ...);
double mind(const int count, ...);
#endif
/* TESTS */
#ifdef __GNUC__
int is_float_negative(float num) __attribute__((const, flatten));
int is_double_negative(double num) __attribute__((const, flatten));
int is_float_positive(float num) __attribute__((const, flatten));
int is_double_positive(double num) __attribute__((const, flatten));
int issquare(const int num) __attribute__((const, flatten));
int islongsquare(const long num) __attribute__((const, flatten));
int islonglongsquare(const long long num) __attribute__((const, flatten));
int isfloatsquare(const float num) __attribute__((const, flatten));
int isdoublesquare(const double num) __attribute__((const, flatten));
int islongdoublesquare(const long double num) __attribute__((const, flatten));
int istriangular(const long num) __attribute__((const, flatten));
int islonglongtriangular(const long long num) __attribute__((const, flatten));
int isdoubletriangular(const double num) __attribute__((const, flatten));
int ishexagonal(const long num) __attribute__((const, flatten));
int islonglonghexagonal(const long long num) __attribute__((const, flatten));
int isheptagonal(const long num) __attribute__((const, flatten));
int islonglongheptagonal(const long long num) __attribute__((const, flatten));
int ispoweroftwo(const unsigned int num) __attribute__((const, flatten));
int islonglongpoweroftwo(const long long num) __attribute__((const, flatten));
int isullpoweroftwo(const ullint num) __attribute__((const, flatten));
int ismersennenumber(const unsigned int num) __attribute__((const, flatten));
int islonglongmersennenumber(const sllint num) __attribute__((const, flatten));
int ismersenneprime(const unsigned int num) __attribute__((const, flatten));
int islonglongmersenneprime(const long long num) __attribute__((const, flatten));
int isprime(const int num) __attribute__((const, flatten));
int isunsignedprime(const unsigned int num) __attribute__((const, flatten));
int islongprime(const long num) __attribute__((const, flatten));
int islonglongprime(const long long num) __attribute__((const, flatten));
int isulprime(const ulint num) __attribute__((const, flatten));
int isullprime(const ullint num) __attribute__((const, flatten));
int iscomposite(const int num) __attribute__((const, flatten));
int isunsignedcomposite(const unsigned int num) __attribute__((const, flatten));
int islongcomposite(const long num) __attribute__((const, flatten));
int islonglongcomposite(const long long num) __attribute__((const, flatten));
int isulcomposite(const ulint num) __attribute__((const, flatten));
int isullcomposite(const ullint num) __attribute__((const, flatten));
#else
int is_float_negative(float num);
int is_double_negative(double num);
int is_float_positive(float num);
int is_double_positive(double num);
int issquare(const int num);
int islongsquare(const long num);
int islonglongsquare(const long long num);
int isfloatsquare(const float num);
int isdoublesquare(const double num);
int islongdoublesquare(const long double num);
int istriangular(const long num);
int islonglongtriangular(const long long num);
int isdoubletriangular(const double num);
int ishexagonal(const long num);
int islonglonghexagonal(const long long num);
int isheptagonal(const long num);
int islonglongheptagonal(const long long num);
int ispoweroftwo(const unsigned int num);
int islonglongpoweroftwo(const long long num);
int isullpoweroftwo(const ullint num);
int ismersennenumber(const unsigned int num);
int islonglongmersennenumber(const sllint num);
int ismersenneprime(const unsigned int num);
int islonglongmersenneprime(const long long num);
int isprime(const int num);
int isunsignedprime(const unsigned int num);
int islongprime(const long num);
int islonglongprime(const long long num);
int isulprime(const ulint num);
int isullprime(const ullint num);
int iscomposite(const int num);
int isunsignedcomposite(const unsigned int num);
int islongcomposite(const long num);
int islonglongcomposite(const long long num);
int isulcomposite(const ulint num);
int isullcomposite(const ullint num);
#endif
/* COMPLEX-NUMBER MATH */
// TRIGONOMETRY (COMPLEX DOUBLES)
#ifdef __GNUC__
double complex ccrd(const double complex radians) __attribute__((const, flatten));
double complex cacot(const double complex radians) __attribute__((const, flatten));
double complex carccot(const double complex radians) __attribute__((const, flatten));
double complex cacoth(const double complex radians) __attribute__((const, flatten));
double complex carccoth(const double complex radians) __attribute__((const, flatten));
double complex ccoth(const double complex radians) __attribute__((const, flatten));
double complex ccot(const double complex radians) __attribute__((const, flatten));
double complex cacsc(const double complex radians) __attribute__((const, flatten));
double complex carccsc(const double complex radians) __attribute__((const, flatten));
double complex cacsch(const double complex radians) __attribute__((const, flatten));
double complex carccsch(const double complex radians) __attribute__((const, flatten));
double complex ccsch(const double complex radians) __attribute__((const, flatten));
double complex ccsc(const double complex radians) __attribute__((const, flatten));
double complex casec(const double complex radians) __attribute__((const, flatten));
double complex carcsec(const double complex radians) __attribute__((const, flatten));
double complex casech(const double complex radians) __attribute__((const, flatten));
double complex carcsech(const double complex radians) __attribute__((const, flatten));
double complex csech(const double complex radians) __attribute__((const, flatten));
double complex csec(const double complex radians) __attribute__((const, flatten));
double complex carcversin(const double complex radians) __attribute__((const, flatten));
double complex carcversinh(const double complex radians) __attribute__((const, flatten));
double complex cversinh(const double complex radians) __attribute__((const, flatten));
double complex cversin(const double complex radians) __attribute__((const, flatten));
double complex carcvercos(const double complex radians) __attribute__((const, flatten));
double complex carcvercosh(const double complex radians) __attribute__((const, flatten));
double complex cvercosh(const double complex radians) __attribute__((const, flatten));
double complex cvercos(const double complex radians) __attribute__((const, flatten));
double complex chaversin(const double complex radians) __attribute__((const, flatten));
double complex chacoversin(const double complex radians) __attribute__((const, flatten));
#else
double complex ccrd(const double complex radians);
double complex cacot(const double complex radians);
double complex carccot(const double complex radians);
double complex cacoth(const double complex radians);
double complex carccoth(const double complex radians);
double complex ccoth(const double complex radians);
double complex ccot(const double complex radians);
double complex cacsc(const double complex radians);
double complex carccsc(const double complex radians);
double complex cacsch(const double complex radians);
double complex carccsch(const double complex radians);
double complex ccsch(const double complex radians);
double complex ccsc(const double complex radians);
double complex casec(const double complex radians);
double complex carcsec(const double complex radians);
double complex casech(const double complex radians);
double complex carcsech(const double complex radians);
double complex csech(const double complex radians);
double complex csec(const double complex radians);
double complex carcversin(const double complex radians);
double complex carcversinh(const double complex radians);
double complex cversinh(const double complex radians);
double complex cversin(const double complex radians);
double complex carcvercos(const double complex radians);
double complex carcvercosh(const double complex radians);
double complex cvercosh(const double complex radians);
double complex cvercos(const double complex radians);
double complex chaversin(const double complex radians);
double complex chacoversin(const double complex radians);
#endif
// TRIGONOMETRY (COMPLEX LONG DOUBLES)
#ifdef __GNUC__
long double complex ccrdl(const long double complex radians) __attribute__((const, flatten));
long double complex cacotl(const long double complex radians) __attribute__((const, flatten));
long double complex carccotl(const long double complex radians) __attribute__((const, flatten));
long double complex cacothl(const long double complex radians) __attribute__((const, flatten));
long double complex carccothl(const long double complex radians) __attribute__((const, flatten));
long double complex ccothl(const long double complex radians) __attribute__((const, flatten));
long double complex ccotl(const long double complex radians) __attribute__((const, flatten));
long double complex cacscl(const long double complex radians) __attribute__((const, flatten));
long double complex carccscl(const long double complex radians) __attribute__((const, flatten));
long double complex cacschl(const long double complex radians) __attribute__((const, flatten));
long double complex carccschl(const long double complex radians) __attribute__((const, flatten));
long double complex ccschl(const long double complex radians) __attribute__((const, flatten));
long double complex ccscl(const long double complex radians) __attribute__((const, flatten));
long double complex casecl(const long double complex radians) __attribute__((const, flatten));
long double complex carcsecl(const long double complex radians) __attribute__((const, flatten));
long double complex casechl(const long double complex radians) __attribute__((const, flatten));
long double complex carcsechl(const long double complex radians) __attribute__((const, flatten));
long double complex csechl(const long double complex radians) __attribute__((const, flatten));
long double complex csecl(const long double complex radians) __attribute__((const, flatten));
long double complex carcversinl(const long double complex radians) __attribute__((const, flatten));
long double complex carcversinhl(const long double complex radians) __attribute__((const, flatten));
long double complex cversinhl(const long double complex radians) __attribute__((const, flatten));
long double complex cversinl(const long double complex radians) __attribute__((const, flatten));
long double complex carcvercosl(const long double complex radians) __attribute__((const, flatten));
long double complex carcvercoshl(const long double complex radians) __attribute__((const, flatten));
long double complex cvercoshl(const long double complex radians) __attribute__((const, flatten));
long double complex cvercosl(const long double complex radians) __attribute__((const, flatten));
long double complex chaversinl(const long double complex radians) __attribute__((const, flatten));
long double complex chacoversinl(const long double complex radians) __attribute__((const, flatten));
#else
long double complex ccrdl(const long double complex radians);
long double complex cacotl(const long double complex radians);
long double complex carccotl(const long double complex radians);
long double complex cacothl(const long double complex radians);
long double complex carccothl(const long double complex radians);
long double complex ccothl(const long double complex radians);
long double complex ccotl(const long double complex radians);
long double complex cacscl(const long double complex radians);
long double complex carccscl(const long double complex radians);
long double complex cacschl(const long double complex radians);
long double complex carccschl(const long double complex radians);
long double complex ccschl(const long double complex radians);
long double complex ccscl(const long double complex radians);
long double complex casecl(const long double complex radians);
long double complex carcsecl(const long double complex radians);
long double complex casechl(const long double complex radians);
long double complex carcsechl(const long double complex radians);
long double complex csechl(const long double complex radians);
long double complex csecl(const long double complex radians);
long double complex carcversinl(const long double complex radians);
long double complex carcversinhl(const long double complex radians);
long double complex cversinhl(const long double complex radians);
long double complex cversinl(const long double complex radians);
long double complex carcvercosl(const long double complex radians);
long double complex carcvercoshl(const long double complex radians);
long double complex cvercoshl(const long double complex radians);
long double complex cvercosl(const long double complex radians);
long double complex chaversinl(const long double complex radians);
long double complex chacoversinl(const long double complex radians);
#endif
// TRIGONOMETRY (COMPLEX FLOATS)
#ifdef __GNUC__
float complex ccrdf(const float complex radians) __attribute__((const, flatten));
float complex cacotf(const float complex radians) __attribute__((const, flatten));
float complex carccotf(const float complex radians) __attribute__((const, flatten));
float complex cacothf(const float complex radians) __attribute__((const, flatten));
float complex carccothf(const float complex radians) __attribute__((const, flatten));
float complex ccothf(const float complex radians) __attribute__((const, flatten));
float complex ccotf(const float complex radians) __attribute__((const, flatten));
float complex cacscf(const float complex radians) __attribute__((const, flatten));
float complex carccscf(const float complex radians) __attribute__((const, flatten));
float complex cacschf(const float complex radians) __attribute__((const, flatten));
float complex carccschf(const float complex radians) __attribute__((const, flatten));
float complex ccschf(const float complex radians) __attribute__((const, flatten));
float complex ccscf(const float complex radians) __attribute__((const, flatten));
float complex casecf(const float complex radians) __attribute__((const, flatten));
float complex carcsecf(const float complex radians) __attribute__((const, flatten));
float complex casechf(const float complex radians) __attribute__((const, flatten));
float complex carcsechf(const float complex radians) __attribute__((const, flatten));
float complex csechf(const float complex radians) __attribute__((const, flatten));
float complex csecf(const float complex radians) __attribute__((const, flatten));
float complex carcversinf(const float complex radians) __attribute__((const, flatten));
float complex carcversinhf(const float complex radians) __attribute__((const, flatten));
float complex cversinhf(const float complex radians) __attribute__((const, flatten));
float complex cversinf(const float complex radians) __attribute__((const, flatten));
float complex carcvercosf(const float complex radians) __attribute__((const, flatten));
float complex carcvercoshf(const float complex radians) __attribute__((const, flatten));
float complex cvercoshf(const float complex radians) __attribute__((const, flatten));
float complex cvercosf(const float complex radians) __attribute__((const, flatten));
float complex chaversinf(const float complex radians) __attribute__((const, flatten));
float complex chacoversinf(const float complex radians) __attribute__((const, flatten));
#else
float complex ccrdf(const float complex radians);
float complex cacotf(const float complex radians);
float complex carccotf(const float complex radians);
float complex cacothf(const float complex radians);
float complex carccothf(const float complex radians);
float complex ccothf(const float complex radians);
float complex ccotf(const float complex radians);
float complex cacscf(const float complex radians);
float complex carccscf(const float complex radians);
float complex cacschf(const float complex radians);
float complex carccschf(const float complex radians);
float complex ccschf(const float complex radians);
float complex ccscf(const float complex radians);
float complex casecf(const float complex radians);
float complex carcsecf(const float complex radians);
float complex casechf(const float complex radians);
float complex carcsechf(const float complex radians);
float complex csechf(const float complex radians);
float complex csecf(const float complex radians);
float complex carcversinf(const float complex radians);
float complex carcversinhf(const float complex radians);
float complex cversinhf(const float complex radians);
float complex cversinf(const float complex radians);
float complex carcvercosf(const float complex radians);
float complex carcvercoshf(const float complex radians);
float complex cvercoshf(const float complex radians);
float complex cvercosf(const float complex radians);
float complex chaversinf(const float complex radians);
float complex chacoversinf(const float complex radians);
#endif
// EXTERNAL TRIGONOMETRY (COMPLEX DOUBLES)
#ifdef __GNUC__
double complex carcexcot(const double complex radians) __attribute__((const, flatten));
double complex carcexcoth(const double complex radians) __attribute__((const, flatten));
double complex cexcoth(const double complex radians) __attribute__((const, flatten));
double complex cexcot(const double complex radians) __attribute__((const, flatten));
double complex carcexcsc(const double complex radians) __attribute__((const, flatten));
double complex carcexcsch(const double complex radians) __attribute__((const, flatten));
double complex cexcsch(const double complex radians) __attribute__((const, flatten));
double complex cexcsc(const double complex radians) __attribute__((const, flatten));
double complex carcexsec(const double complex radians) __attribute__((const, flatten));
double complex carcexsech(const double complex radians) __attribute__((const, flatten));
double complex cexsech(const double complex radians) __attribute__((const, flatten));
double complex cexsec(const double complex radians) __attribute__((const, flatten));
#else
double complex carcexcot(const double complex radians);
double complex carcexcoth(const double complex radians);
double complex cexcoth(const double complex radians);
double complex cexcot(const double complex radians);
double complex carcexcsc(const double complex radians);
double complex carcexcsch(const double complex radians);
double complex cexcsch(const double complex radians);
double complex cexcsc(const double complex radians);
double complex carcexsec(const double complex radians);
double complex carcexsech(const double complex radians);
double complex cexsech(const double complex radians);
double complex cexsec(const double complex radians);
#endif
// EXTERNAL TRIGONOMETRY (COMPLEX LONG DOUBLES)
#ifdef __GNUC__
long double complex carcexcotl(const long double complex radians) __attribute__((const, flatten));
long double complex carcexcothl(const long double complex radians) __attribute__((const, flatten));
long double complex cexcothl(const long double complex radians) __attribute__((const, flatten));
long double complex cexcotl(const long double complex radians) __attribute__((const, flatten));
long double complex carcexcscl(const long double complex radians) __attribute__((const, flatten));
long double complex carcexcschl(const long double complex radians) __attribute__((const, flatten));
long double complex cexcschl(const long double complex radians) __attribute__((const, flatten));
long double complex cexcscl(const long double complex radians) __attribute__((const, flatten));
long double complex carcexsecl(const long double complex radians) __attribute__((const, flatten));
long double complex carcexsechl(const long double complex radians) __attribute__((const, flatten));
long double complex cexsechl(const long double complex radians) __attribute__((const, flatten));
long double complex cexsecl(const long double complex radians) __attribute__((const, flatten));
#else
long double complex carcexcotl(const long double complex radians);
long double complex carcexcothl(const long double complex radians);
long double complex cexcothl(const long double complex radians);
long double complex cexcotl(const long double complex radians);
long double complex carcexcscl(const long double complex radians);
long double complex carcexcschl(const long double complex radians);
long double complex cexcschl(const long double complex radians);
long double complex cexcscl(const long double complex radians);
long double complex carcexsecl(const long double complex radians);
long double complex carcexsechl(const long double complex radians);
long double complex cexsechl(const long double complex radians);
long double complex cexsecl(const long double complex radians);
#endif
// EXTERNAL TRIGONOMETRY (COMPLEX FLOATS)
#ifdef __GNUC__
float complex carcexcotf(const float complex radians) __attribute__((const, flatten));
float complex carcexcothf(const float complex radians) __attribute__((const, flatten));
float complex cexcothf(const float complex radians) __attribute__((const, flatten));
float complex cexcotf(const float complex radians) __attribute__((const, flatten));
float complex carcexcscf(const float complex radians) __attribute__((const, flatten));
float complex carcexcschf(const float complex radians) __attribute__((const, flatten));
float complex cexcschf(const float complex radians) __attribute__((const, flatten));
float complex cexcscf(const float complex radians) __attribute__((const, flatten));
float complex carcexsecf(const float complex radians) __attribute__((const, flatten));
float complex carcexsechf(const float complex radians) __attribute__((const, flatten));
float complex cexsechf(const float complex radians) __attribute__((const, flatten));
float complex cexsecf(const float complex radians) __attribute__((const, flatten));
#else
float complex carcexcotf(const float complex radians);
float complex carcexcothf(const float complex radians);
float complex cexcothf(const float complex radians);
float complex cexcotf(const float complex radians);
float complex carcexcscf(const float complex radians);
float complex carcexcschf(const float complex radians);
float complex cexcschf(const float complex radians);
float complex cexcscf(const float complex radians);
float complex carcexsecf(const float complex radians);
float complex carcexsechf(const float complex radians);
float complex cexsechf(const float complex radians);
float complex cexsecf(const float complex radians);
#endif
// SPECIAL TRIGONOMETRIC FUNCTIONS (COMPLEX DOUBLES)
#ifdef __GNUC__
double complex ccos_arcsin(const double complex radians) __attribute__((const, flatten));
double complex ccos_arctan(const double complex radians) __attribute__((const, flatten));
double complex csin_arcsec(const double complex radians) __attribute__((const, flatten));
double complex csin_arctan(const double complex radians) __attribute__((const, flatten));
#else
double complex ccos_arcsin(const double complex radians);
double complex ccos_arctan(const double complex radians);
double complex csin_arcsec(const double complex radians);
double complex csin_arctan(const double complex radians);
#endif
// SPECIAL TRIGONOMETRIC FUNCTIONS (COMPLEX LONG DOUBLES)
#ifdef __GNUC__
long double complex ccos_arcsinl(const long double complex radians) __attribute__((const, flatten));
long double complex ccos_arctanl(const long double complex radians) __attribute__((const, flatten));
long double complex csin_arcsecl(const long double complex radians) __attribute__((const, flatten));
long double complex csin_arctanl(const long double complex radians) __attribute__((const, flatten));
#else
long double complex ccos_arcsinl(const long double complex radians);
long double complex ccos_arctanl(const long double complex radians);
long double complex csin_arcsecl(const long double complex radians);
long double complex csin_arctanl(const long double complex radians);
#endif
// SPECIAL TRIGONOMETRIC FUNCTIONS (COMPLEX FLOATS)
#ifdef __GNUC__
float complex ccos_arcsinf(const float complex radians) __attribute__((const, flatten));
float complex ccos_arctanf(const float complex radians) __attribute__((const, flatten));
float complex csin_arcsecf(const float complex radians) __attribute__((const, flatten));
float complex csin_arctanf(const float complex radians) __attribute__((const, flatten));
#else
float complex ccos_arcsinf(const float complex radians);
float complex ccos_arctanf(const float complex radians);
float complex csin_arcsecf(const float complex radians);
float complex csin_arctanf(const float complex radians);
#endif
// MISCELLANEOUS COMPLEX-NUMBER FUNCTIONS
double complex conjugate(const double complex num);
long double complex conjugatel(const long double complex num);
float complex conjugatef(const float complex num);
#ifndef norm
double norm(const double complex x);
#endif
#ifndef norml
long double norml(const long double complex x);
#endif
#ifndef normf
float normf(const float complex x);
#endif
/* QUATERNION MATH */
#define qimag(x)   ((x).i, (x).j, (x).k)
double qreal(const quaternion num);
double qgeti(const quaternion num);
double qgetj(const quaternion num);
double qgetk(const quaternion num);
quaternion qconjugate(const quaternion num);
double qnorm(const quaternion num);
quaternion qadd(const quaternion num1, const quaternion num2);
quaternion qsub(const quaternion num1, const quaternion num2);
quaternion qmul(const quaternion num1, const quaternion num2);
quaternion qdiv(const quaternion num1, const quaternion num2);
quaternion qinv(const quaternion qnum);
void qinv_inplace(quaternion qnum);
quaternion qneg(const quaternion qnum);
void qneg_inplace(quaternion qnum);
#ifdef __GNUC__
double qlen(const quaternion num) __attribute__((const, flatten));
quaternion qmid(const quaternion num1, const quaternion num2) __attribute__((const, flatten));
quaternion qsqrt(const quaternion num) __attribute__((const, flatten));
#else
double qlen(const quaternion num);
quaternion qmid(const quaternion num1, const quaternion num2);
quaternion qsqrt(const quaternion num);
#endif
quaternion qscalar(const quaternion num);
quaternion qvector(const quaternion num);
quaternion qversor(const quaternion num);
#define qimagf(x)   ((x).i, (x).j, (x).k)
float qrealf(const quaternion_float num);
float qgetif(const quaternion_float num);
float qgetjf(const quaternion_float num);
float qgetkf(const quaternion_float num);
quaternion_float qconjugatef(const quaternion_float num);
float qnormf(const quaternion_float num);
quaternion_float qaddf(const quaternion_float num1, const quaternion_float num2);
quaternion_float qsubf(const quaternion_float num1, const quaternion_float num2);
quaternion_float qmulf(const quaternion_float num1, const quaternion_float num2);
quaternion_float qdivf(const quaternion_float num1, const quaternion_float num2);
quaternion_float qinvf(const quaternion_float qnum);
void qinv_inplacef(quaternion_float qnum);
quaternion_float qnegf(const quaternion_float qnum);
void qneg_inplacef(quaternion_float qnum);
#ifdef __GNUC__
float qlenf(const quaternion_float num) __attribute__((const, flatten));
quaternion_float qmidf(const quaternion_float num1, const quaternion_float num2) __attribute__((const, flatten));
quaternion_float qsqrtf(const quaternion_float num) __attribute__((const, flatten));
#else
float qlenf(const quaternion_float num);
quaternion_float qmidf(const quaternion_float num1, const quaternion_float num2);
quaternion_float qsqrtf(const quaternion_float num);
#endif
quaternion_float qscalarf(const quaternion_float num);
quaternion_float qvectorf(const quaternion_float num);
quaternion_float qversorf(const quaternion_float num);
#define qimagl(x)   ((x).i, (x).j, (x).k)
long double qreall(const quaternion_long_double num);
long double qgetil(const quaternion_long_double num);
long double qgetjl(const quaternion_long_double num);
long double qgetkl(const quaternion_long_double num);
quaternion_long_double qconjugatel(const quaternion_long_double num);
long double qnorml(const quaternion_long_double num);
quaternion_long_double qaddl(const quaternion_long_double num1, const quaternion_long_double num2);
quaternion_long_double qsubl(const quaternion_long_double num1, const quaternion_long_double num2);
quaternion_long_double qmull(const quaternion_long_double num1, const quaternion_long_double num2);
quaternion_long_double qdivl(const quaternion_long_double num1, const quaternion_long_double num2);
quaternion_long_double qinvl(const quaternion_long_double qnum);
void qinv_inplacel(quaternion_long_double qnum);
quaternion_long_double qnegl(const quaternion_long_double qnum);
void qneg_inplacel(quaternion_long_double qnum);
#ifdef __GNUC__
long double qlenl(const quaternion_long_double num) __attribute__((const, flatten));
quaternion_long_double qmidl(const quaternion_long_double num1, const quaternion_long_double num2) __attribute__((const, flatten));
quaternion_long_double qsqrtl(const quaternion_long_double num) __attribute__((const, flatten));
#else
long double qlenl(const quaternion_long_double num);
quaternion_long_double qmidl(const quaternion_long_double num1, const quaternion_long_double num2);
quaternion_long_double qsqrtl(const quaternion_long_double num);
#endif
quaternion_long_double qscalarl(const quaternion_long_double num);
quaternion_long_double qvectorl(const quaternion_long_double num);
quaternion_long_double qversorl(const quaternion_long_double num);
/* MISCELLANEOUS */
#ifdef __GNUC__
ullint bit_length(const ullint num) __attribute__((const, flatten));
#   ifdef UINT128_SUPPORTED
uint128_t bit128_length(const uint128_t num) __attribute__((const, flatten));
#   endif
ullint clearlsb(ullint num) __attribute__((const, flatten));
signed int sgn_int(const signed int num) __attribute__((const, flatten));
double sgn(const double num) __attribute__((const, flatten));
float sgnf(const float num) __attribute__((const, flatten));
long double sgnl(const long double num) __attribute__((const, flatten));
int abs_int(const int num) __attribute__((const, flatten));
double absd(const double num) __attribute__((const, flatten));
float absf(const float num) __attribute__((const, flatten));
long double absl(const long double num) __attribute__((const, flatten));
double retint(const double x) __attribute__((const, flatten));
double poly(const double x, const size_t n, const double *__restrict__ c) __attribute__((const, flatten));
int div_and_mod_int(const int num1, const int num2) __attribute__((const, flatten));
double div_and_mod(const double num1, const double num2) __attribute__((const, flatten));
float div_and_modf(const float num1, const float num2) __attribute__((const, flatten));
double lanczos_sum(const double x) __attribute__((const, flatten));
#else
ullint bit_length(const ullint num);
#ifdef UINT128_SUPPORTED
uint128_t bit128_length(const uint128_t num);
#endif
ullint clearlsb(ullint num);
signed int sgn_int(const signed int num);
double sgn(const double num);
float sgnf(const float num);
long double sgnl(const long double num);
int abs_int(const int num);
double absd(const double num);
float absf(const float num);
long double absl(const long double num);
double retint(const double x);
double poly(const double x, const size_t n, const double *c);
int div_and_mod_int(const int num1, const int num2);
double div_and_mod(const double num1, const double num2);
float div_and_modf(const float num1, const float num2);
double lanczos_sum(const double x);
#endif


#endif

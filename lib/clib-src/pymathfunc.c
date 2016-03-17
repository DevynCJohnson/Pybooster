// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file pymathfunc.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Math Functions
@version 2016.03.09

@section DESCRIPTION
This is a Python3 module that uses functions from mathfunc.c
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


#include "PY_MACROS.h"
#include "mathfunc.h"

#define MODNAME    "mathfunc"
#define MODINIT    PyMODINIT_FUNC PyInit_mathfunc(void)
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
/* POWERS */
static PyObject *mathfunc_pow2(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_pow_ten(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_pow_ten_int(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_pow_ten_int_fast(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_pow_ten_pos(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_pow_ten_neg(FUNCARGS) __attribute__((const, flatten));
/* ROOTS */
static PyObject *mathfunc_squareroot(FUNCARGS) __attribute__((const, flatten));
/* FACTORIALS */
static PyObject *mathfunc_factorial(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_doublefactorial(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_quadfactorial(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_superfactorial(FUNCARGS) __attribute__((const, flatten));
/* NUMBER GENERATORS */
static PyObject *mathfunc_pronic(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_fib(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_triangular_num(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_hexagonal_num(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_heptagonal_num(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_tetrahedral_num(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_pentatope_num(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_mersenne_num(FUNCARGS) __attribute__((const, flatten));
/* TRIGONOMETRY */
static PyObject *mathfunc_sinpi(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_crd(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_acot(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arccot(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_acoth(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arccoth(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_coth(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_cot(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_acsc(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arccsc(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_acsch(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arccsch(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_csch(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_csc(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_asec(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arcsec(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_asech(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arcsech(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_sech(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_sec(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arcversin(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arcversinh(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_versinh(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_versin(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arcvercos(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arcvercosh(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_vercosh(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_vercos(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_haversin(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_hacoversin(FUNCARGS) __attribute__((const, flatten));
/* EXTERNAL TRIGONOMETRY */
static PyObject *mathfunc_arcexcot(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arcexcoth(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_excoth(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_excot(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arcexcsc(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arcexcsch(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_excsch(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_excsc(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arcexsec(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_arcexsech(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_exsech(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_exsec(FUNCARGS) __attribute__((const, flatten));
/* SPECIAL TRIGONOMETRIC FUNCTIONS */
static PyObject *mathfunc_cos_arcsin(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_cos_arctan(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_sin_arcsec(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_sin_arctan(FUNCARGS) __attribute__((const, flatten));
/* TESTS */
static PyObject *mathfunc_issquare(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_isfloatsquare(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_istriangular(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_ishexagonal(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_isheptagonal(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_ispoweroftwo(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_ismersenneprime(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_ismersennenumber(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_isprime(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_iscomposite(FUNCARGS) __attribute__((const, flatten));
/* MISCELLANEOUS */
static PyObject *mathfunc_fma(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_fpclassify(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_float_diff(FUNCARGS) __attribute__((const, flatten));
static PyObject *mathfunc_bit_length(FUNCARGS) __attribute__((const, flatten));
#else
/* POWERS */
static PyObject *mathfunc_pow2(FUNCARGS);
static PyObject *mathfunc_pow_ten(FUNCARGS);
static PyObject *mathfunc_pow_ten_int(FUNCARGS);
static PyObject *mathfunc_pow_ten_int_fast(FUNCARGS);
static PyObject *mathfunc_pow_ten_pos(FUNCARGS);
static PyObject *mathfunc_pow_ten_neg(FUNCARGS);
/* ROOTS */
static PyObject *mathfunc_squareroot(FUNCARGS);
/* FACTORIALS */
static PyObject *mathfunc_factorial(FUNCARGS);
static PyObject *mathfunc_doublefactorial(FUNCARGS);
static PyObject *mathfunc_quadfactorial(FUNCARGS);
static PyObject *mathfunc_superfactorial(FUNCARGS);
/* NUMBER GENERATORS */
static PyObject *mathfunc_pronic(FUNCARGS);
static PyObject *mathfunc_fib(FUNCARGS);
static PyObject *mathfunc_triangular_num(FUNCARGS);
static PyObject *mathfunc_hexagonal_num(FUNCARGS);
static PyObject *mathfunc_heptagonal_num(FUNCARGS);
static PyObject *mathfunc_tetrahedral_num(FUNCARGS);
static PyObject *mathfunc_pentatope_num(FUNCARGS);
static PyObject *mathfunc_mersenne_num(FUNCARGS);
/* TRIGONOMETRY */
static PyObject *mathfunc_sinpi(FUNCARGS);
static PyObject *mathfunc_crd(FUNCARGS);
static PyObject *mathfunc_acot(FUNCARGS);
static PyObject *mathfunc_arccot(FUNCARGS);
static PyObject *mathfunc_acoth(FUNCARGS);
static PyObject *mathfunc_arccoth(FUNCARGS);
static PyObject *mathfunc_coth(FUNCARGS);
static PyObject *mathfunc_cot(FUNCARGS);
static PyObject *mathfunc_acsc(FUNCARGS);
static PyObject *mathfunc_arccsc(FUNCARGS);
static PyObject *mathfunc_acsch(FUNCARGS);
static PyObject *mathfunc_arccsch(FUNCARGS);
static PyObject *mathfunc_csch(FUNCARGS);
static PyObject *mathfunc_csc(FUNCARGS);
static PyObject *mathfunc_asec(FUNCARGS);
static PyObject *mathfunc_arcsec(FUNCARGS);
static PyObject *mathfunc_asech(FUNCARGS);
static PyObject *mathfunc_arcsech(FUNCARGS);
static PyObject *mathfunc_sech(FUNCARGS);
static PyObject *mathfunc_sec(FUNCARGS);
static PyObject *mathfunc_arcversin(FUNCARGS);
static PyObject *mathfunc_arcversinh(FUNCARGS);
static PyObject *mathfunc_versinh(FUNCARGS);
static PyObject *mathfunc_versin(FUNCARGS);
static PyObject *mathfunc_arcvercos(FUNCARGS);
static PyObject *mathfunc_arcvercosh(FUNCARGS);
static PyObject *mathfunc_vercosh(FUNCARGS);
static PyObject *mathfunc_vercos(FUNCARGS);
static PyObject *mathfunc_haversin(FUNCARGS);
static PyObject *mathfunc_hacoversin(FUNCARGS);
/* EXTERNAL TRIGONOMETRY */
static PyObject *mathfunc_arcexcot(FUNCARGS);
static PyObject *mathfunc_arcexcoth(FUNCARGS);
static PyObject *mathfunc_excoth(FUNCARGS);
static PyObject *mathfunc_excot(FUNCARGS);
static PyObject *mathfunc_arcexcsc(FUNCARGS);
static PyObject *mathfunc_arcexcsch(FUNCARGS);
static PyObject *mathfunc_excsch(FUNCARGS);
static PyObject *mathfunc_excsc(FUNCARGS);
static PyObject *mathfunc_arcexsec(FUNCARGS);
static PyObject *mathfunc_arcexsech(FUNCARGS);
static PyObject *mathfunc_exsech(FUNCARGS);
static PyObject *mathfunc_exsec(FUNCARGS);
/* SPECIAL TRIGONOMETRIC FUNCTIONS */
static PyObject *mathfunc_cos_arcsin(FUNCARGS);
static PyObject *mathfunc_cos_arctan(FUNCARGS);
static PyObject *mathfunc_sin_arcsec(FUNCARGS);
static PyObject *mathfunc_sin_arctan(FUNCARGS);
/* TESTS */
static PyObject *mathfunc_issquare(FUNCARGS);
static PyObject *mathfunc_isfloatsquare(FUNCARGS);
static PyObject *mathfunc_istriangular(FUNCARGS);
static PyObject *mathfunc_ishexagonal(FUNCARGS);
static PyObject *mathfunc_isheptagonal(FUNCARGS);
static PyObject *mathfunc_ispoweroftwo(FUNCARGS);
static PyObject *mathfunc_ismersenneprime(FUNCARGS);
static PyObject *mathfunc_ismersennenumber(FUNCARGS);
static PyObject *mathfunc_isprime(FUNCARGS);
static PyObject *mathfunc_iscomposite(FUNCARGS);
/* MISCELLANEOUS */
static PyObject *mathfunc_fma(FUNCARGS);
static PyObject *mathfunc_fpclassify(FUNCARGS);
static PyObject *mathfunc_float_diff(FUNCARGS);
static PyObject *mathfunc_bit_length(FUNCARGS);
#endif


/* DOCSTRINGS */


static char module_docstring[16] =
    "Math Functions";
/* POWERS */
PyDoc_STRVAR(mathfunc_pow2_docstring,
    "pow2(num: int) -> int\nReturn the power of 2^num, where \"num\" is a positive integer");
PyDoc_STRVAR(mathfunc_pow_ten_docstring,
    "pow_ten(num: int) -> float\nReturn the power of 10^num");
PyDoc_STRVAR(mathfunc_pow_ten_int_docstring,
    "pow_ten_int(num: int) -> int\nReturn the power of 10^num, where 'num' is a positive integer");
PyDoc_STRVAR(mathfunc_pow_ten_int_fast_docstring,
    "pow_ten_int_fast(num: int) -> int\nReturn the power of 10^num ('num' is a positive integer less than 18)");
PyDoc_STRVAR(mathfunc_pow_ten_pos_docstring,
    "pow_ten_pos(num: int) -> float\nReturn the power of 10^num for positive exponents");
PyDoc_STRVAR(mathfunc_pow_ten_neg_docstring,
    "pow_ten_neg(num: int) -> float\nReturn the power of 10^num for negative exponents");
/* ROOTS */
PyDoc_STRVAR(mathfunc_squareroot_docstring,
    "squareroot(num: float) -> float\nReturn the Square-Root of a positive number");
/* FACTORIALS */
PyDoc_STRVAR(mathfunc_factorial_docstring,
    "factorial(num: int) -> float\nFactorial (n!)");
PyDoc_STRVAR(mathfunc_doublefactorial_docstring,
    "doublefactorial(num: int) -> float\nDouble Factorial (n!!)");
PyDoc_STRVAR(mathfunc_quadfactorial_docstring,
    "quadfactorial(num: int) -> float\nQuadruple Factorial - (2n)!/n!");
PyDoc_STRVAR(mathfunc_superfactorial_docstring,
    "superfactorial(num: int) -> float\nSuper-Factorial");
/* NUMBER GENERATORS */
PyDoc_STRVAR(mathfunc_pronic_docstring,
    "pronic(num: int) -> int\nReturn the Nth Pronic number");
PyDoc_STRVAR(mathfunc_fib_docstring,
    "fib(num: int) -> int\nFibonacci Number Generator\nReturn the specified Fibonacci Number");
PyDoc_STRVAR(mathfunc_triangular_num_docstring,
    "triangular_num(num: int) -> int\nReturn the Nth Triangular Number");
PyDoc_STRVAR(mathfunc_hexagonal_num_docstring,
    "hexagonal_num(num: int) -> int\nReturn the Nth Hexagonal Number");
PyDoc_STRVAR(mathfunc_heptagonal_num_docstring,
    "heptagonal_num(num: int) -> int\nReturn the Nth Heptagonal Number");
PyDoc_STRVAR(mathfunc_tetrahedral_num_docstring,
    "tetrahedral_num(num: int) -> int\nReturn the Nth Tetrahedral Number");
PyDoc_STRVAR(mathfunc_pentatope_num_docstring,
    "pentatope_num(num: int) -> int\nReturn the Nth Pentatope Number");
PyDoc_STRVAR(mathfunc_mersenne_num_docstring,
    "mersenne_num(num: int) -> int\nReturn the Nth Mersenne Number");
/* TRIGONOMETRY */
PyDoc_STRVAR(mathfunc_sinpi_docstring,
    "sinpi(num: float) -> float\nReturn the Pi Sine of the given number; return 0.0 on error");
PyDoc_STRVAR(mathfunc_crd_docstring,
    "crd(radians: float) -> float\nReturn the Chord");
PyDoc_STRVAR(mathfunc_acot_docstring,
    "acot(radians: float) -> float\nReturn the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x))");
PyDoc_STRVAR(mathfunc_arccot_docstring,
    "arccot(radians: float) -> float\nReturn the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x))");
PyDoc_STRVAR(mathfunc_acoth_docstring,
    "acoth(radians: float) -> float\nReturn the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x))");
PyDoc_STRVAR(mathfunc_arccoth_docstring,
    "arccoth(radians: float) -> float\nReturn the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x))");
PyDoc_STRVAR(mathfunc_coth_docstring,
    "coth(radians: float) -> float\nReturn the Hyperbolic Cotangent (coth(x) == 1/tanh(x))");
PyDoc_STRVAR(mathfunc_cot_docstring,
    "cot(radians: float) -> float\nReturn the Cotangent (cot(x) == 1/tan(x))");
PyDoc_STRVAR(mathfunc_acsc_docstring,
    "acsc(radians: float) -> float\nReturn the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x))");
PyDoc_STRVAR(mathfunc_arccsc_docstring,
    "arccsc(radians: float) -> float\nReturn the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x))");
PyDoc_STRVAR(mathfunc_acsch_docstring,
    "acsch(radians: float) -> float\nReturn the Hyperbolic Arc-Cosecant (acsch(x)||arccsch(x) == asinh(1/x))");
PyDoc_STRVAR(mathfunc_arccsch_docstring,
    "arccsch(radians: float) -> float\nReturn the Hyperbolic Arc-Cosecant (acsc(x)||arccsch(x) == asinh(1/x))");
PyDoc_STRVAR(mathfunc_csch_docstring,
    "csch(radians: float) -> float\nReturn the Hyperbolic Cosecant (csch(x) == 1/sinh(x))");
PyDoc_STRVAR(mathfunc_csc_docstring,
    "csc(radians: float) -> float\nReturn the Cosecant (csc(x) == 1/sin(x))");
PyDoc_STRVAR(mathfunc_asec_docstring,
    "asec(radians: float) -> float\nReturn the Arc-Secant (asec(x)||arcsec(x) == acos(1/x))");
PyDoc_STRVAR(mathfunc_arcsec_docstring,
    "arcsec(radians: float) -> float\nReturn the Arc-Secant (asec(x)||arcsec(x) == acos(1/x))");
PyDoc_STRVAR(mathfunc_asech_docstring,
    "asech(radians: float) -> float\nReturn the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x))");
PyDoc_STRVAR(mathfunc_arcsech_docstring,
    "arcsech(radians: float) -> float\nReturn the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x))");
PyDoc_STRVAR(mathfunc_sech_docstring,
    "sech(radians: float) -> float\nReturn the Hyperbolic Secant (sech(x) == 1/cosh(x))");
PyDoc_STRVAR(mathfunc_sec_docstring,
    "sec(radians: float) -> float\nReturn the Secant (sec(x) == 1/cos(x))");
PyDoc_STRVAR(mathfunc_arcversin_docstring,
    "arcversin(radians: float) -> float\nReturn the Arc-Versed Sine (arcversin(x) == 1 - acos(x))");
PyDoc_STRVAR(mathfunc_arcversinh_docstring,
    "arcversinh(radians: float) -> float\nReturn the Hyperbolic Arc-Versed Sine (arcversinh(x) == 1 - acosh(x))");
PyDoc_STRVAR(mathfunc_versinh_docstring,
    "versinh(radians: float) -> float\nReturn the Hyperbolic Versed Sine (versinh(x) == 1 - cosh(x))");
PyDoc_STRVAR(mathfunc_versin_docstring,
    "versin(radians: float) -> float\nReturn the Versed Sine (versin(x) == 1 - cos(x))");
PyDoc_STRVAR(mathfunc_arcvercos_docstring,
    "arcvercos(radians: float) -> float\nReturn the Arc-Versed Cosine (arcvercos(x) == 1 - asin(x))");
PyDoc_STRVAR(mathfunc_arcvercosh_docstring,
    "arcvercosh(radians: float) -> float\nReturn the Hyperbolic Arc-Versed Cosine (arcvercosh(x) == 1 - asinh(x))");
PyDoc_STRVAR(mathfunc_vercosh_docstring,
    "vercosh(radians: float) -> float\nReturn the Hyperbolic Versed Cosine (vercosh(x) == 1 - sinh(x))");
PyDoc_STRVAR(mathfunc_vercos_docstring,
    "vercos(radians: float) -> float\nReturn the Versed Cosine (vercos(x) == 1 - sin(x))");
PyDoc_STRVAR(mathfunc_haversin_docstring,
    "haversin(radians: float) -> float\nReturn the Haversine (haversin(x) == 0.5*(1 - cos(x)))");
PyDoc_STRVAR(mathfunc_hacoversin_docstring,
    "hacoversin(radians: float) -> float\nReturn the Hacoversine (hacoversin(x) == 0.5*(1 - sin(x)))");
/* EXTERNAL TRIGONOMETRY */
PyDoc_STRVAR(mathfunc_arcexcot_docstring,
    "arcexcot(radians: float) -> float\nReturn the Arc-External Cotangent (arcexcot(x) == atan(1/(x+1)))");
PyDoc_STRVAR(mathfunc_arcexcoth_docstring,
    "arcexcoth(radians: float) -> float\nReturn the Hyperbolic Arc-External Cotangent [arcexcoth(x) == (1/atanh(x)-1)]");
PyDoc_STRVAR(mathfunc_excoth_docstring,
    "excoth(radians: float) -> float\nReturn the External Hyperbolic Cotangent [excoth(x) == (1/tanh(x)-1)]");
PyDoc_STRVAR(mathfunc_excot_docstring,
    "excot(radians: float) -> float\nReturn the External Cotangent [excot(x) == (1/tan(x))-1 == cot(x)-1]");
PyDoc_STRVAR(mathfunc_arcexcsc_docstring,
    "arcexcsc(radians: float) -> float\nReturn the Arc-External Cosecant (arcexcsc(x) == asin(1/(x+1)))");
PyDoc_STRVAR(mathfunc_arcexcsch_docstring,
    "arcexcsch(radians: float) -> float\nReturn the Hyperbolic Arc-External Cosecant [arcexcsch(x) == (1/asinh(x)-1)]");
PyDoc_STRVAR(mathfunc_excsch_docstring,
    "excsch(radians: float) -> float\nReturn the External Hyperbolic Cosecant [excsch(x) == (1/sinh(x)-1)]");
PyDoc_STRVAR(mathfunc_excsc_docstring,
    "excsc(radians: float) -> float\nReturn the External Cosecant [excsc(x) == (1/sin(x))-1 == csc(x)-1]");
PyDoc_STRVAR(mathfunc_arcexsec_docstring,
    "arcexsec(radians: float) -> float\nReturn the Arc-External Secant (arcexsec(x) == acos(1/(x+1)))");
PyDoc_STRVAR(mathfunc_arcexsech_docstring,
    "arcexsech(radians: float) -> float\nReturn the Hyperbolic Arc-External Secant [arcexsech(x) == (1/acosh(x)-1)]");
PyDoc_STRVAR(mathfunc_exsech_docstring,
    "exsech(radians: float) -> float\nReturn the External Hyperbolic Secant [exsech(x) == (1/cosh(x)-1)]");
PyDoc_STRVAR(mathfunc_exsec_docstring,
    "exsec(radians: float) -> float\nReturn the External Secant [exsec(x) == (1/cos(x))-1 == sec(x)-1]");
/* SPECIAL TRIGONOMETRIC FUNCTIONS */
PyDoc_STRVAR(mathfunc_cos_arcsin_docstring,
    "cos_arcsin(radians: float) -> float\nReturn the Cosine of an Arc-Sine [sqrt(1-(x*x))]");
PyDoc_STRVAR(mathfunc_cos_arctan_docstring,
    "cos_arctan(radians: float) -> float\nReturn the Cosine of an Arc-Tangent [1 / sqrt(1+(x*x))]");
PyDoc_STRVAR(mathfunc_sin_arcsec_docstring,
    "sin_arcsec(radians: float) -> float\nReturn the Sine of an Arc-Tangent [sqrt((x*x)-1)/x]");
PyDoc_STRVAR(mathfunc_sin_arctan_docstring,
    "sin_arctan(radians: float) -> float\nReturn the Sine of an Arc-Tangent [x / sqrt(1+(x*x))]");
/* TESTS */
PyDoc_STRVAR(mathfunc_issquare_docstring,
    "issquare(num: int) -> bool\nTest if a number is a perfect square");
PyDoc_STRVAR(mathfunc_isfloatsquare_docstring,
    "isfloatsquare(num: float) -> bool\nTest if a double is a perfect square");
PyDoc_STRVAR(mathfunc_istriangular_docstring,
    "istriangular(num: int) -> bool\nTest if the given number is a Triangular Number");
PyDoc_STRVAR(mathfunc_ishexagonal_docstring,
    "ishexagonal(num: int) -> bool\nTest if the given number is a Hexagonal Number");
PyDoc_STRVAR(mathfunc_isheptagonal_docstring,
    "isheptagonal(num: int) -> bool\nTest if the given number is a Heptagonal Number");
PyDoc_STRVAR(mathfunc_ispoweroftwo_docstring,
    "ispoweroftwo(num: int) -> bool\nTest if the given number is a Power-of-Two");
PyDoc_STRVAR(mathfunc_ismersennenumber_docstring,
    "ismersennenumber(num: int) -> bool\nTest if the given number is a Mersenne Number");
PyDoc_STRVAR(mathfunc_ismersenneprime_docstring,
    "ismersenneprime(num: int) -> bool\nTest if the given number is a Mersenne Prime");
PyDoc_STRVAR(mathfunc_isprime_docstring,
    "isprime(num: int) -> bool\nTest if a signed int is prime");
PyDoc_STRVAR(mathfunc_iscomposite_docstring,
    "iscomposite(num: int) -> bool\nTest if an int is composite");
/* MISCELLANEOUS */
PyDoc_STRVAR(mathfunc_fma_docstring,
    "fma(num1: float, num2: float, num3: float) -> float\nFused Multiply-Add (num1*num2+num3)");
PyDoc_STRVAR(mathfunc_fpclassify_docstring,
    "fpclassify(num: float) -> int\nReturn an integer that indicates the type of float\n-1: Error\n0: NaN\n1: Infinity\n2: Zero\n3: Subnormal\n4: Normal");
PyDoc_STRVAR(mathfunc_float_diff_docstring,
    "float_diff(num1: float, num2: float) -> float\nReturn the difference between the two floats");
PyDoc_STRVAR(mathfunc_bit_length_docstring,
    "bit_length(num: int) -> int\nReturn the number of bits used to represent the given number");


/* MODULE SPECIFICATION */


static PyMethodDef module_methods[128] = {  // Method Table
    /* POWERS */
    {"pow2", (PyCFunction)mathfunc_pow2, METH_VARARGS, mathfunc_pow2_docstring},
    {"pow_ten", (PyCFunction)mathfunc_pow_ten, METH_VARARGS, mathfunc_pow_ten_docstring},
    {"pow_ten_int", (PyCFunction)mathfunc_pow_ten_int, METH_VARARGS, mathfunc_pow_ten_int_docstring},
    {"pow_ten_int_fast", (PyCFunction)mathfunc_pow_ten_int_fast, METH_VARARGS, mathfunc_pow_ten_int_fast_docstring},
    {"pow_ten_pos", (PyCFunction)mathfunc_pow_ten_pos, METH_VARARGS, mathfunc_pow_ten_pos_docstring},
    {"pow_ten_neg", (PyCFunction)mathfunc_pow_ten_neg, METH_VARARGS, mathfunc_pow_ten_neg_docstring},
    /* ROOTS */
    {"squareroot", (PyCFunction)mathfunc_squareroot, METH_VARARGS, mathfunc_squareroot_docstring},
    /* FACTORIALS */
    {"factorial", (PyCFunction)mathfunc_factorial, METH_VARARGS, mathfunc_factorial_docstring},
    {"doublefactorial", (PyCFunction)mathfunc_doublefactorial, METH_VARARGS, mathfunc_doublefactorial_docstring},
    {"quadfactorial", (PyCFunction)mathfunc_quadfactorial, METH_VARARGS, mathfunc_quadfactorial_docstring},
    {"superfactorial", (PyCFunction)mathfunc_superfactorial, METH_VARARGS, mathfunc_superfactorial_docstring},
    {"fib", (PyCFunction)mathfunc_fib, METH_VARARGS, mathfunc_fib_docstring},
    /* NUMBER GENERATORS */
    {"pronic", (PyCFunction)mathfunc_pronic, METH_VARARGS, mathfunc_pronic_docstring},
    {"triangular_num", (PyCFunction)mathfunc_triangular_num, METH_VARARGS, mathfunc_triangular_num_docstring},
    {"hexagonal_num", (PyCFunction)mathfunc_hexagonal_num, METH_VARARGS, mathfunc_hexagonal_num_docstring},
    {"heptagonal_num", (PyCFunction)mathfunc_heptagonal_num, METH_VARARGS, mathfunc_heptagonal_num_docstring},
    {"tetrahedral_num", (PyCFunction)mathfunc_tetrahedral_num, METH_VARARGS, mathfunc_tetrahedral_num_docstring},
    {"pentatope_num", (PyCFunction)mathfunc_pentatope_num, METH_VARARGS, mathfunc_pentatope_num_docstring},
    {"mersenne_num", (PyCFunction)mathfunc_mersenne_num, METH_VARARGS, mathfunc_mersenne_num_docstring},
    /* TRIGONOMETRY */
    {"sinpi", (PyCFunction)mathfunc_sinpi, METH_VARARGS, mathfunc_sinpi_docstring},
    {"crd", (PyCFunction)mathfunc_crd, METH_VARARGS, mathfunc_crd_docstring},
    {"acot", (PyCFunction)mathfunc_acot, METH_VARARGS, mathfunc_acot_docstring},
    {"arccot", (PyCFunction)mathfunc_arccot, METH_VARARGS, mathfunc_arccot_docstring},
    {"acoth", (PyCFunction)mathfunc_acoth, METH_VARARGS, mathfunc_acoth_docstring},
    {"arccoth", (PyCFunction)mathfunc_arccoth, METH_VARARGS, mathfunc_arccoth_docstring},
    {"coth", (PyCFunction)mathfunc_coth, METH_VARARGS, mathfunc_coth_docstring},
    {"cot", (PyCFunction)mathfunc_cot, METH_VARARGS, mathfunc_cot_docstring},
    {"acsc", (PyCFunction)mathfunc_acsc, METH_VARARGS, mathfunc_acsc_docstring},
    {"arccsc", (PyCFunction)mathfunc_arccsc, METH_VARARGS, mathfunc_arccsc_docstring},
    {"acsch", (PyCFunction)mathfunc_acsch, METH_VARARGS, mathfunc_acsch_docstring},
    {"arccsch", (PyCFunction)mathfunc_arccsch, METH_VARARGS, mathfunc_arccsch_docstring},
    {"csch", (PyCFunction)mathfunc_csch, METH_VARARGS, mathfunc_csch_docstring},
    {"csc", (PyCFunction)mathfunc_csc, METH_VARARGS, mathfunc_csc_docstring},
    {"asec", (PyCFunction)mathfunc_asec, METH_VARARGS, mathfunc_asec_docstring},
    {"arcsec", (PyCFunction)mathfunc_arcsec, METH_VARARGS, mathfunc_arcsec_docstring},
    {"asech", (PyCFunction)mathfunc_asech, METH_VARARGS, mathfunc_asech_docstring},
    {"arcsech", (PyCFunction)mathfunc_arcsech, METH_VARARGS, mathfunc_arcsech_docstring},
    {"sech", (PyCFunction)mathfunc_sech, METH_VARARGS, mathfunc_sech_docstring},
    {"sec", (PyCFunction)mathfunc_sec, METH_VARARGS, mathfunc_sec_docstring},
    {"arcversin", (PyCFunction)mathfunc_arcversin, METH_VARARGS, mathfunc_arcversin_docstring},
    {"arcversinh", (PyCFunction)mathfunc_arcversinh, METH_VARARGS, mathfunc_arcversinh_docstring},
    {"versinh", (PyCFunction)mathfunc_versinh, METH_VARARGS, mathfunc_versinh_docstring},
    {"versin", (PyCFunction)mathfunc_versin, METH_VARARGS, mathfunc_versin_docstring},
    {"arcvercos", (PyCFunction)mathfunc_arcvercos, METH_VARARGS, mathfunc_arcvercos_docstring},
    {"arcvercosh", (PyCFunction)mathfunc_arcvercosh, METH_VARARGS, mathfunc_arcvercosh_docstring},
    {"vercosh", (PyCFunction)mathfunc_vercosh, METH_VARARGS, mathfunc_vercosh_docstring},
    {"vercos", (PyCFunction)mathfunc_vercos, METH_VARARGS, mathfunc_vercos_docstring},
    {"haversin", (PyCFunction)mathfunc_haversin, METH_VARARGS, mathfunc_haversin_docstring},
    {"hacoversin", (PyCFunction)mathfunc_hacoversin, METH_VARARGS, mathfunc_hacoversin_docstring},
    /* EXTERNAL TRIGONOMETRY */
    {"arcexcot", (PyCFunction)mathfunc_arcexcot, METH_VARARGS, mathfunc_arcexcot_docstring},
    {"arcexcoth", (PyCFunction)mathfunc_arcexcoth, METH_VARARGS, mathfunc_arcexcoth_docstring},
    {"excoth", (PyCFunction)mathfunc_excoth, METH_VARARGS, mathfunc_excoth_docstring},
    {"excot", (PyCFunction)mathfunc_excot, METH_VARARGS, mathfunc_excot_docstring},
    {"arcexcsc", (PyCFunction)mathfunc_arcexcsc, METH_VARARGS, mathfunc_arcexcsc_docstring},
    {"arcexcsch", (PyCFunction)mathfunc_arcexcsch, METH_VARARGS, mathfunc_arcexcsch_docstring},
    {"excsch", (PyCFunction)mathfunc_excsch, METH_VARARGS, mathfunc_excsch_docstring},
    {"excsc", (PyCFunction)mathfunc_excsc, METH_VARARGS, mathfunc_excsc_docstring},
    {"arcexsec", (PyCFunction)mathfunc_arcexsec, METH_VARARGS, mathfunc_arcexsec_docstring},
    {"arcexsech", (PyCFunction)mathfunc_arcexsech, METH_VARARGS, mathfunc_arcexsech_docstring},
    {"exsech", (PyCFunction)mathfunc_exsech, METH_VARARGS, mathfunc_exsech_docstring},
    {"exsec", (PyCFunction)mathfunc_exsec, METH_VARARGS, mathfunc_exsec_docstring},
    /* SPECIAL TRIGONOMETRIC FUNCTIONS */
    {"cos_arcsin", (PyCFunction)mathfunc_cos_arcsin, METH_VARARGS, mathfunc_cos_arcsin_docstring},
    {"cos_arctan", (PyCFunction)mathfunc_cos_arctan, METH_VARARGS, mathfunc_cos_arctan_docstring},
    {"sin_arcsec", (PyCFunction)mathfunc_sin_arcsec, METH_VARARGS, mathfunc_sin_arcsec_docstring},
    {"sin_arctan", (PyCFunction)mathfunc_sin_arctan, METH_VARARGS, mathfunc_sin_arctan_docstring},
    /* TESTS */
    {"issquare", (PyCFunction)mathfunc_issquare, METH_VARARGS, mathfunc_issquare_docstring},
    {"isfloatsquare", (PyCFunction)mathfunc_isfloatsquare, METH_VARARGS, mathfunc_isfloatsquare_docstring},
    {"istriangular", (PyCFunction)mathfunc_istriangular, METH_VARARGS, mathfunc_istriangular_docstring},
    {"ishexagonal", (PyCFunction)mathfunc_ishexagonal, METH_VARARGS, mathfunc_ishexagonal_docstring},
    {"isheptagonal", (PyCFunction)mathfunc_isheptagonal, METH_VARARGS, mathfunc_isheptagonal_docstring},
    {"ispoweroftwo", (PyCFunction)mathfunc_ispoweroftwo, METH_VARARGS, mathfunc_ispoweroftwo_docstring},
    {"ismersennenumber", (PyCFunction)mathfunc_ismersennenumber, METH_VARARGS, mathfunc_ismersennenumber_docstring},
    {"ismersenneprime", (PyCFunction)mathfunc_ismersenneprime, METH_VARARGS, mathfunc_ismersenneprime_docstring},
    {"isprime", (PyCFunction)mathfunc_isprime, METH_VARARGS, mathfunc_isprime_docstring},
    {"iscomposite", (PyCFunction)mathfunc_iscomposite, METH_VARARGS, mathfunc_iscomposite_docstring},
    /* MISCELLANEOUS */
    {"fma", (PyCFunction)mathfunc_fma, METH_VARARGS, mathfunc_fma_docstring},
    {"fpclassify", (PyCFunction)mathfunc_fpclassify, METH_VARARGS, mathfunc_fpclassify_docstring},
    {"float_diff", (PyCFunction)mathfunc_float_diff, METH_VARARGS, mathfunc_float_diff_docstring},
    {"bit_length", (PyCFunction)mathfunc_bit_length, METH_VARARGS, mathfunc_bit_length_docstring},
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


/* POWERS */


static PyObject *mathfunc_pow2(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    return ll2int(pow2_longlong(num));
}


static PyObject *mathfunc_pow_ten(FUNCARGS) {
    const signed int num;
    ASSERT_INT_ARG(num);
    return double2float(pow_ten(num));
}


static PyObject *mathfunc_pow_ten_int(FUNCARGS) {
    const unsigned int num;
    ASSERT_UINT_ARG(num);
    return ull2int(pow_ten_int(num));
}


static PyObject *mathfunc_pow_ten_int_fast(FUNCARGS) {
    const unsigned int num;
    ASSERT_UINT_ARG(num);
    return ull2int(pow_ten_int_fast(num));
}


static PyObject *mathfunc_pow_ten_pos(FUNCARGS) {
    const unsigned int num;
    ASSERT_UINT_ARG(num);
    return double2float(pow_ten_pos(num));
}


static PyObject *mathfunc_pow_ten_neg(FUNCARGS) {
    const signed int num;
    ASSERT_INT_ARG(num);
    return double2float(pow_ten_neg(num));
}


/* ROOTS */


static PyObject *mathfunc_squareroot(FUNCARGS) {
    const double num;
    ASSERT_DOUBLE_ARG(num);
    return double2float(squareroot(num));
}


/* FACTORIALS */


static PyObject *mathfunc_factorial(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    return ll2int(factoriallonglong(num));
}


static PyObject *mathfunc_doublefactorial(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    return ll2int(doublefactoriallonglong(num));
}


static PyObject *mathfunc_quadfactorial(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    return ll2int(quadfactoriallonglong(num));
}


static PyObject *mathfunc_superfactorial(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    return ll2int(superfactoriallonglong(num));
}


/* NUMBER GENERATORS */


static PyObject *mathfunc_pronic(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    return ll2int(proniclonglong(num));
}


static PyObject *mathfunc_fib(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
#if (defined(ENV64BIT))
    if ((num < (sllint)0x00) || (num > (sllint)91)) { return ll2int(0x0); }
#elif (defined(ENV32BIT))
    if ((num < (sllint)0x00) || (num > (sllint)35)) { return ll2int(0x0); }
#endif
    else if ((num >= 0x00) && (num <= (sllint)14)) {
        switch (num) {
            case (sllint)0: return ll2int((sllint)0x0);
            case (sllint)1: return ll2int((sllint)1);
            case (sllint)2: return ll2int((sllint)1);
            case (sllint)3: return ll2int((sllint)2);
            case (sllint)4: return ll2int((sllint)3);
            case (sllint)5: return ll2int((sllint)5);
            case (sllint)6: return ll2int((sllint)8);
            case (sllint)7: return ll2int((sllint)13);
            case (sllint)8: return ll2int((sllint)21);
            case (sllint)9: return ll2int((sllint)34);
            case (sllint)10: return ll2int((sllint)55);
            case (sllint)11: return ll2int((sllint)89);
            case (sllint)12: return ll2int((sllint)144);
            case (sllint)13: return ll2int((sllint)233);
            default: return ll2int((sllint)377);  // case (sllint)14
        }
    }
    sllint fval[92];
    fval[0] = (sllint)0;
    fval[1] = (sllint)1;
    fval[2] = (sllint)1;
    fval[3] = (sllint)2;
    fval[4] = (sllint)3;
    fval[5] = (sllint)5;
    fval[6] = (sllint)8;
    fval[7] = (sllint)13;
    fval[8] = (sllint)21;
    fval[9] = (sllint)34;
    fval[10] = (sllint)55;
    fval[11] = (sllint)89;
    fval[12] = (sllint)144;
    fval[13] = (sllint)233;
    fval[14] = (sllint)377;
    register sllint i;
    for (i = (sllint)15; i <= (sllint)num; ++i) { fval[i] = (sllint)(fval[i - (sllint)1] + fval[i - (sllint)2]); if (i >= num) { break; } }
    return ll2int(fval[num]);
}


static PyObject *mathfunc_triangular_num(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    return ll2int(triangular_numlonglong(num));
}


static PyObject *mathfunc_hexagonal_num(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    return ll2int(hexagonal_numlonglong(num));
}


static PyObject *mathfunc_heptagonal_num(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    return ll2int(heptagonal_numlonglong(num));
}


static PyObject *mathfunc_tetrahedral_num(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    return ll2int(tetrahedral_numlonglong(num));
}


static PyObject *mathfunc_pentatope_num(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    return ll2int(pentatope_numlonglong(num));
}


static PyObject *mathfunc_mersenne_num(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    return ll2int(mersenne_numlonglong(num));
}


/* TRIGONOMETRY */


static PyObject *mathfunc_sinpi(FUNCARGS) {
    const double num;
    ASSERT_DOUBLE_ARG(num);
    return double2float(sinpi(num));
}


static PyObject *mathfunc_crd(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)2.0 * sin(radians / (double)2.0)));
}


static PyObject *mathfunc_acot(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((atan((double)1.0 / radians)));
}


static PyObject *mathfunc_arccot(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((atan((double)1.0 / radians)));
}


static PyObject *mathfunc_acoth(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((atanh((double)1.0 / radians)));
}


static PyObject *mathfunc_arccoth(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((atanh((double)1.0 / radians)));
}


static PyObject *mathfunc_coth(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 / tanh(radians)));
}


static PyObject *mathfunc_cot(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 / tan(radians)));
}


static PyObject *mathfunc_acsc(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((asin((double)1.0 / radians)));
}


static PyObject *mathfunc_arccsc(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((asin((double)1.0 / radians)));
}


static PyObject *mathfunc_acsch(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((asinh((double)1.0 / radians)));
}


static PyObject *mathfunc_arccsch(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((asinh((double)1.0 / radians)));
}


static PyObject *mathfunc_csch(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 / sinh(radians)));
}


static PyObject *mathfunc_csc(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 / sin(radians)));
}


static PyObject *mathfunc_asec(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((acos((double)1.0 / radians)));
}


static PyObject *mathfunc_arcsec(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((acos((double)1.0 / radians)));
}


static PyObject *mathfunc_asech(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((acosh((double)1.0 / radians)));
}


static PyObject *mathfunc_arcsech(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((acosh((double)1.0 / radians)));
}


static PyObject *mathfunc_sech(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 / cosh(radians)));
}


static PyObject *mathfunc_sec(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 / cos(radians)));
}


static PyObject *mathfunc_arcversin(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 - acos(radians)));
}


static PyObject *mathfunc_arcversinh(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 - acosh(radians)));
}


static PyObject *mathfunc_versinh(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 - cosh(radians)));
}


static PyObject *mathfunc_versin(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 - cos(radians)));
}


static PyObject *mathfunc_arcvercos(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 - asin(radians)));
}


static PyObject *mathfunc_arcvercosh(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 - asinh(radians)));
}


static PyObject *mathfunc_vercosh(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 - sinh(radians)));
}


static PyObject *mathfunc_vercos(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 - sin(radians)));
}


static PyObject *mathfunc_haversin(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)0.5 * ((double)1.0 - cos(radians))));
}


static PyObject *mathfunc_hacoversin(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)0.5 * ((double)1.0 - sin(radians))));
}


/* EXTERNAL TRIGONOMETRY */


static PyObject *mathfunc_arcexcot(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(atan((double)1.0 / (radians + (double)1.0)));
}


static PyObject *mathfunc_arcexcoth(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((((double)1.0 / atanh(radians)) - (double)1.0));
}


static PyObject *mathfunc_excoth(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((((double)1.0 / tanh(radians)) - (double)1.0));
}


static PyObject *mathfunc_excot(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((((double)1.0 / tan(radians)) - (double)1.0));
}


static PyObject *mathfunc_arcexcsc(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(asin((double)1.0 / (radians + (double)1.0)));
}


static PyObject *mathfunc_arcexcsch(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((((double)1.0 / asinh(radians)) - (double)1.0));
}


static PyObject *mathfunc_excsch(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((((double)1.0 / sinh(radians)) - (double)1.0));
}


static PyObject *mathfunc_excsc(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((((double)1.0 / sin(radians)) - (double)1.0));
}


static PyObject *mathfunc_arcexsec(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(acos((double)1.0 / (radians + (double)1.0)));
}


static PyObject *mathfunc_arcexsech(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((((double)1.0 / acosh(radians)) - (double)1.0));
}


static PyObject *mathfunc_exsech(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((((double)1.0 / cosh(radians)) - (double)1.0));
}


static PyObject *mathfunc_exsec(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((((double)1.0 / cos(radians)) - (double)1.0));
}


/* SPECIAL TRIGONOMETRIC FUNCTIONS */


static PyObject *mathfunc_cos_arcsin(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((squareroot((double)1.0 - (radians * radians))));
}


static PyObject *mathfunc_cos_arctan(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float(((double)1.0 / squareroot((double)1.0 + (radians * radians))));
}


static PyObject *mathfunc_sin_arcsec(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((squareroot((radians * radians) - (double)1.0) / radians));
}


static PyObject *mathfunc_sin_arctan(FUNCARGS) {
    const double radians;
    ASSERT_DOUBLE_ARG(radians);
    return double2float((radians / squareroot((double)1.0 + (radians * radians))));
}


/* TESTS */


static PyObject *mathfunc_issquare(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    if (num < (sllint)0) { ERR_POSITIVE_INT; }
    returnbool(islonglongsquare(num));
}


static PyObject *mathfunc_isfloatsquare(FUNCARGS) {
    const double num;
    ASSERT_DOUBLE_ARG(num);
    returnbool(isdoublesquare(num));
}


static PyObject *mathfunc_istriangular(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    if (num < (sllint)0) { ERR_POSITIVE_INT; }
    returnbool(islonglongtriangular(num));
}


static PyObject *mathfunc_ishexagonal(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    if (num < (sllint)0) { ERR_POSITIVE_INT; }
    returnbool(islonglonghexagonal(num));
}


static PyObject *mathfunc_isheptagonal(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    if (num < (sllint)0) { ERR_POSITIVE_INT; }
    returnbool(islonglongheptagonal(num));
}


static PyObject *mathfunc_ispoweroftwo(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    if (num < (sllint)0) { ERR_POSITIVE_INT; }
    returnbool(islonglongpoweroftwo(num));
}


static PyObject *mathfunc_ismersennenumber(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    if (num < (sllint)0) { ERR_POSITIVE_INT; }
    returnbool(islonglongmersennenumber(num));
}


static PyObject *mathfunc_ismersenneprime(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    if (num < (sllint)0) { ERR_POSITIVE_INT; }
    returnbool(islonglongmersenneprime(num));
}


static PyObject *mathfunc_isprime(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    if (num < (sllint)0) { ERR_POSITIVE_INT; }
    returnbool(islonglongprime(num));
}


static PyObject *mathfunc_iscomposite(FUNCARGS) {
    const sllint num;
    ASSERT_LONGLONG_ARG(num);
    if (num < (sllint)0) { ERR_POSITIVE_INT; }
    returnbool(islonglongcomposite(num));
}


/* MISCELLANEOUS */


static PyObject *mathfunc_fma(FUNCARGS) {
    const double num1, num2, num3;
    ASSERT_3DOUBLE_ARG(num1, num2, num3);
#ifdef FP_FAST_FMA
    return double2float((fma(num1, num2, num3)));
#else
    return double2float(((num1 * num2) + num3));
#endif
}


static PyObject *mathfunc_fpclassify(FUNCARGS) {
    const double num;
    ASSERT_DOUBLE_ARG(num);
    switch (fpclassify(num)) {
        case FP_NAN: return int2int(0);
        case FP_INFINITE: return int2int(1);
        case FP_ZERO: return int2int(2);
        case FP_SUBNORMAL: return int2int(3);
        case FP_NORMAL: return int2int(4);
        default: return int2int((-1));
    }
    return int2int((-1));
}


static PyObject *mathfunc_float_diff(FUNCARGS) {
    const double num1, num2;
    ASSERT_2DOUBLE_ARG(num1, num2);
    return double2float((fdim(num1, num2)));
}


static PyObject *mathfunc_bit_length(FUNCARGS) {
    const ullint num;
    ASSERT_ULONGLONG_ARG(num);
    return ull2int((bit_length(num)));
}

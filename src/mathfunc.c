// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file mathfunc.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Math Functions
@version 2016.03.20

@section DESCRIPTION
Numerous mathematical and trigonometric functions.
This extends the standard math library by providing by offering faster alternatives.
Such functions include squareroot, fractorial, fib, haversin, isprime, ishexagonal, etc.\n
<math.h> contains
 - cos, sin, tan  // General (Radians)
 - acos, asin, atan, atan2  // Arcs
 - cosh, sinh, tanh  // Hyperbolics
 - acosh, asinh, atanh  // Arc-Hyperbolics
 - hypot

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

@section Types_of_Numbers

https://en.wikipedia.org/wiki/List_of_types_of_numbers

 - NATURAL/CARDINAL NUMBER (ℕ): Counting numbers {0, 1, 2, 3, …}, are called natural numbers. (https://en.wikipedia.org/wiki/Natural_number)
 - INTEGER (ℤ): A number that can be written without a fractional component. For example, 17, 3, 0, and -1024 are integers, while 9.73, 5 1⁄2, and √2 are not integers. (https://en.wikipedia.org/wiki/Integer)
 - RATIONAL NUMBER (ℚ): Any number that can be expressed as the quotient or fraction p/q of two integers, p and q, with the denominator, q, not equal to zero. Since q may be equal to 1, every integer is a rational number. The decimal expansion of a rational number always either terminates after a finite number of digits or begins to repeat the same finite sequence of digits over and over. (https://en.wikipedia.org/wiki/Rational_number)
 - TRANSCENDENTAL NUMBER: A real or complex number that is not algebraic; that is, it is not a root of a non-zero polynomial equation with rational coefficients. The best-known transcendental numbers are π and e. (https://en.wikipedia.org/wiki/Transcendental_number)
 - REAL NUMBER (ℝ): A value that represents a quantity along a continuous line. The real numbers include all the rational numbers, such as the integer -5 and the fraction 4/3, all the irrational numbers, such as √2 (1.41421356…) and all transcendental numbers, such as π (3.14159265…). (https://en.wikipedia.org/wiki/Real_number)
 - IRRATIONAL NUMBER (𝕀): Any real number that cannot be expressed as a ratio of integers. Irrational numbers cannot be represented as terminating or repeating decimals. As a consequence of Cantor's proof that the real numbers are uncountable and the rationals countable, almost all real numbers are irrational. Irrational numbers include √2, π, e, and φ. (https://en.wikipedia.org/wiki/Irrational_number)
 - IMAGINARY NUMBER: A complex number that can be written as a real number multiplied by the imaginary unit 𝕚. (https://en.wikipedia.org/wiki/Imaginary_number)
 - COMPLEX NUMBER (ℂ): A number that can be expressed in the form a + b𝕚, where a and b are real numbers and 𝕚 is the imaginary unit, that satisfies the equation 𝕚^2=-1. In this expression, a is the real part and b is the imaginary part of the complex number. (https://en.wikipedia.org/wiki/Complex_number)
 - TESSARINE OR BICOMPLEX-NUMBER: A hypercomplex number in a commutative, associative algebra over real numbers with two imaginary units (designated i and k). (https://en.wikipedia.org/wiki/Bicomplex_number)
 - HYPERCOMPLEX NUMBER: An element of a unital algebra over the field of real numbers. Hypercomplex numbers include quaternions, octonions, sedenions, tessarines, coquaternions, and biquaternions. (https://en.wikipedia.org/wiki/Hypercomplex_number)
 - QUATERNION (ℍ): A number system that extends the complex numbers and applied to mechanics in three-dimensional space. A feature of quaternions is that multiplication of two quaternions is noncommutative. Hamilton defined a quaternion as the quotient of two directed lines in a three-dimensional space or equivalently as the quotient of two vectors. Quaternions form a four-dimensional associative normed division algebra over the real numbers, and therefore also a domain. In fact, the quaternions were the first noncommutative division algebra to be discovered. (https://en.wikipedia.org/wiki/Quaternion)
 - SPLIT-QUATERNION OR COQUATERNION: Elements of a 4-dimensional associative algebra. Unlike the quaternion algebra, the split-quaternions contain zero divisors, nilpotent elements, and nontrivial idempotents. As a mathematical structure, they form an algebra over the real numbers, which is isomorphic to the algebra of 2 × 2 real matrices. A coquaternion equals `w + xi + yj + zk`. (https://en.wikipedia.org/wiki/Split-quaternion)
 - BIQUATERNION: Are the numbers w + x i + y j + z k, where w, x, y, and z are complex numbers and the elements of {1, i, j, k} multiply as in the quaternion group. As there are three types of complex numbers, so there are three types of biquaternions (Ordinary Biquaternions, Split-biquaternions, and Dual quaternions). (https://en.wikipedia.org/wiki/Biquaternion)
 - OCTONION (𝕆): Normed division algebra over the real numbers. Octonions have eight dimensions; twice the number of dimensions of the quaternions. They are noncommutative and nonassociative, but satisfy a weaker form of associativity. (https://en.wikipedia.org/wiki/Octonion)
 - SEDENION (𝕊): 16-dimensional noncommutative and nonassociative numbers over the reals and obtained by applying the Cayley–Dickson construction to the octonions. (https://en.wikipedia.org/wiki/Sedenion)
*/


#include "mathfunc.h"


/* HELPER CODE */


static const double LANCZOS_DEN_COEFFS__[16];
static const double LANCZOS_NUM_COEFFS__[16];

/** Private Constant */
static const double LANCZOS_DEN_COEFFS__[16] = {
    0.0,
    39916800.0,
    120543840.0,
    150917976.0,
    105258076.0,
    45995730.0,
    13339535.0,
    2637558.0,
    357423.0,
    32670.0,
    1925.0,
    66.0,
    1.0
};


/** Private Constant */
static const double LANCZOS_NUM_COEFFS__[16] = {
    23531376880.410759688572007674451636754734846804940,
    42919803642.649098768957899047001988850926355848959,
    35711959237.355668049440185451547166705960488635843,
    17921034426.037209699919755754458931112671403265390,
    6039542586.3520280050642916443072979210699388420708,
    1439720407.3117216736632230727949123939715485786772,
    248874557.86205415651146038641322942321632125127801,
    31426415.585400194380614231628318205362874684987640,
    2876370.6289353724412254090516208496135991145378768,
    186056.26539522349504029498971604569928220784236328,
    8071.6720023658162106380029022722506138218516325024,
    210.82427775157934587250973392071336271166969580291,
    2.5066282746310002701649081771338373386264310793408
};


/* ANGLES */


/** Return the complement of an angle (all in degrees) */
double complement_angle_deg(const double angle) {
    return (90.0 - angle);
}


/** Return the complement of an angle (all in degrees) */
long double complement_angle_degl(const long double angle) {
    return (90.0L - angle);
}


/** Return the complement of an angle (all in degrees) */
float complement_angle_degf(const float angle) {
    return (90.0F - angle);
}


/** Return the supplement of an angle (all in degrees) */
double supplement_angle_deg(const double angle) {
    return (180.0 - angle);
}


/** Return the supplement of an angle (all in degrees) */
long double supplement_angle_degl(const long double angle) {
    return (180.0 - angle);
}


/** Return the supplement of an angle (all in degrees) */
float supplement_angle_degf(const float angle) {
    return (180.0F - angle);
}


/** Return the angle (in radians) of an arc given arc-length and radius */
double arc_angle(const double arc_length, const double radius) {
    return (arc_length / radius);
}


/* GRAPHING */


/** Return the y coordinate for a given angle (radians) */
double sin_wave_equation(const double amplitude, const double angle) {
    return (amplitude * sin(angle));
}


/** Sawtooth-Wave function */
double sawtooth(const double x) {
    return (x - floor(x));
}


/** Advanced Sawtooth-Wave function (set period and amplitude) */
double sawtooth2(const double x, const double period, const double amplitude) {
    return ((((double)2.0 * amplitude) / PI) * (atan(cot((x * PI) / period))));
}


/** Sigmoid-Curve function */
double sigmoid(const double x) {
    return ((double)1.0 / ((double)1.0 + pow(E, -x)));
}


/** Square-Wave function */
double squarewave(const double x) {
    return sgn(sin(x));
}


/** Triangle-Wave function */
int trianglewave(const int x) {
    return (abs_int(x & 0x01) - 0x01);
}


/* LOGARITHMS */


/** Natural Logarithm */
double ln(const double num) {
    return (log(num));
}


/** Natural Logarithm plus 1 */
double lnp1(const double num) {
    return (log(num) + (double)1.0);
}


/** Return logp1 for the given number */
double log_plus1(const double num) {
    if (fabs(num) < (DBL_EPSILON / 2.0)) { return num; }
    else if ((-0.5 <= num) && (num <= 1.0)) {
        register double x = (1.0 + num);
        return ((log(x)) - (((x - 1.0) - num) / x));
    } else { return (log((1.0 + num))); }  // NaNs and infinities
}


/** Return logp1 for the given number */
float log_plus1f(const float num) {
    if (fabsf(num) < (FLT_EPSILON / 2.0F)) { return num; }
    else if ((-0.5F <= num) && (num <= 1.0F)) {
        register float x = (1.0F + num);
        return ((logf(x)) - (((x - 1.0F) - num) / x));
    } else { return (logf((1.0F + num))); }  // NaNs and infinities
}


/** Return logp1 for the given number */
long double log_plus1l(const long double num) {
    if (fabsl(num) < (LDBL_EPSILON / 2.0L)) { return num; }
    else if ((-0.5L <= num) && (num <= 1.0L)) {
        register long double x = (1.0L + num);
        return ((logl(x)) - (((x - 1.0L) - num) / x));
    } else { return (logl((1.0L + num))); }  // NaNs and infinities
}


/** log function that fixes odd behaviors on some platforms */
double LOG(const double num) {
    if (isfinite(num)) {
        if (num > 0.0) { return log(num); }
        errno = EDOM;
        if (num == 0.0) { return -HUGE_VAL; }  // log(0) = -inf
        else { return NAN; }  // log(-ve) = nan
    }
    else if (isnan(num)) { return num; }  // log(nan) = nan
    else if (num > 0.0) { return num; }  // log(inf) = inf
    else {
        errno = EDOM;
        return NAN;  // log(-inf) = nan
    }
}


/** log2 function that fixes odd behaviors on some platforms */
double LOG2(const double num) {
    if (!(isfinite(num))) {
        if (isnan(num)) { return num; }  // log2(nan) = nan
        else if (num > 0.0) { return num; }  // log2(+inf) = +inf
        else {
            errno = EDOM;
            return NAN;  // log2(-inf) = nan, invalid-operation
        }
    } else if (num > 0.0) {
        register double m;
        int e;
        m = frexp(num, &e);
        if (num >= 1.0) { return log(2.0 * m) / log(2.0) + (e - 1); }
        else { return ((log(m) / log(2.0)) + e); }
    } else if (num == 0.0) {
        errno = EDOM;
        return -HUGE_VAL;  // log2(0) = -inf, divide-by-zero
    } else {
        errno = EDOM;
        return NAN;  // log2(-inf) = nan, invalid-operation
    }
}


/** log10 function that fixes odd behaviors on some platforms */
double LOG10(const double num) {
    if (isfinite(num)) {
        if (num > 0.0) { return log10(num); }
        errno = EDOM;
        if (num == 0.0) { return (-(HUGE_VAL)); }  // log10(0) = -inf
        else { return NAN; }  // log10(-ve) = nan
    }
    else if (isnan(num)) { return num; }  // log10(nan) = nan
    else if (num > 0.0) { return num; }  // log10(inf) = inf
    else {
        errno = EDOM;
        return NAN;  // log10(-inf) = nan
    }
}


/* POWERS */


/** Return base-e minus 1 for the given number */
double exp_minus1(const double num) {
    if (fabs(num) < 0.7) {
        register double x;
        x = exp(num);
        if (x == 1.0) { return num; }
        else { return (((x - 1.0) * num) / log(x)); }
    }
    return (exp(num) - 1.0);
}


/** Return base-e minus 1 for the given number */
float exp_minus1f(const float num) {
    if (fabsf(num) < 0.7F) {
        register float x;
        x = expf(num);
        if (x == 1.0F) { return num; }
        else { return (((x - 1.0F) * num) / logf(x)); }
    }
    return (expf(num) - 1.0F);
}


/** Return base-e minus 1 for the given number */
long double exp_minus1l(const long double num) {
    if (fabsl(num) < 0.7L) {
        register long double x;
        x = expl(num);
        if (x == 1.0L) { return num; }
        else { return (((x - 1.0L) * num) / logl(x)); }
    }
    return (expl(num) - 1.0L);
}


/** Return the power of 2^num, where "num" is a positive integer; return 0 on error */
unsigned long long int pow2(const unsigned int num) {
#if (defined(ENV64BIT))
    if (num > (unsigned int)63) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (unsigned int)31) { return 0; }
#endif
    else { return (ullint)0x01 << num; }
}


/** Return the power of 2^num, where "num" is a positive integer; return 0 on error */
signed long long int pow2_longlong(const signed long long int num) {
#if (defined(ENV64BIT))
    if (num > (sllint)31) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (sllint)15) { return 0; }
#endif
    else if (num < (sllint)0) { return 0; }
    else { return (sllint)0x01 << num; }
}


/** Fast power function (num^exp) */
double ipow(double num, const int exp) {
    register int e = exp;
    if ((int)e < 0x00) {
        e = -e;
        num = (1.0 / num);
    }
    register double ret = 1.0;
    while (1) {
        if (e & 1) { ret *= num; }
        if ((e >>= 1) == 0) { break; }
        num *= num;
    }
    return ret;
}


/** Return the power of 10^num (i.e. 10^num=OUTPUT); return 0 on error */
double pow_ten(const signed int num) {
#if (defined(ENV64BIT))
    if (num > (signed int)22) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (signed int)11) { return 0; }
#endif
    else if (num == (signed int)0x00) { return 1; }
    else if (num > (signed int)0x00) {
        register signed int i;
        register double power = 1.0;
        for (i = num; --i;) { power *= 10.0; }
        return power;
    } else {
        register signed int i;
        register double power = 1.0;
        for (i = 0x00; i < (0x00 - num); ++i) { power *= 0.1; }
        return power;
    }
}


/** Return the power of 10^num (i.e. 10^num=OUTPUT); return 0 on error */
long double pow_tenl(const signed int num) {
#if (defined(ENV64BIT))
    if (0x00 > num && num < (signed int)-56) { return 0; }
    else if (num > (signed int)27) { return 0; }
#elif (defined(ENV32BIT))
    if (0x00 > num && num < (signed int)-27) { return 0; }
    else if (num > (signed int)13) { return 0; }
#endif
    else if (num == (signed int)0x00) { return 1; }
    else if (num > (signed int)0x00) {
        register signed int i;
        long double power = (long double)1.0L;
        for (i = num; --i;) { power *= (long double)10.0L; }
        return power;
    } else {
        register signed int i;
        long double power = (long double)1.0L;
        for (i = 0x00; i < (0x00 - num); ++i) { power *= (long double)0.1L; }
        return power;
    }
}


/** Return the power of 10^num, where "num" is a positive integer; return 0 on error */
unsigned long long int pow_ten_int(const unsigned int num) {
#if (defined(ENV64BIT))
    if (num > (unsigned int)19) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (unsigned int)9) { return 0; }
#endif
    else if (num == (unsigned int)0x00) { return (ullint)1; }
    else {
        register unsigned int i;
        register ullint power = 1;
        for (i = num; --i;) power *= (ullint)10;
        return power;
    }
}


/** Return the power of 10^num ("num" is a positive integer less than 18); return 0 on error */
unsigned long long int pow_ten_int_fast(const unsigned int num) {
    if (num < (unsigned int)20) {
        switch (num) {
            case (unsigned int)0: return (ullint)1ULL;
            case (unsigned int)1: return (ullint)10ULL;
            case (unsigned int)2: return (ullint)100ULL;
            case (unsigned int)3: return (ullint)1000ULL;
            case (unsigned int)4: return (ullint)10000ULL;
            case (unsigned int)5: return (ullint)100000ULL;
            case (unsigned int)6: return (ullint)1000000ULL;
            case (unsigned int)7: return (ullint)10000000ULL;
            case (unsigned int)8: return (ullint)100000000ULL;
            case (unsigned int)9: return (ullint)1000000000ULL;
            case (unsigned int)10: return (ullint)10000000000ULL;
            case (unsigned int)11: return (ullint)100000000000ULL;
            case (unsigned int)12: return (ullint)1000000000000ULL;
            case (unsigned int)13: return (ullint)10000000000000ULL;
            case (unsigned int)14: return (ullint)100000000000000ULL;
            case (unsigned int)15: return (ullint)1000000000000000ULL;
            case (unsigned int)16: return (ullint)10000000000000000ULL;
            case (unsigned int)17: return (ullint)100000000000000000ULL;
            case (unsigned int)18: return (ullint)1000000000000000000ULL;
            default: return (ullint)10000000000000000000ULL;  // 10^19
        }
    }
    return 0;
}


/** Return the power of 10^num for positive exponents (i.e. 10^num=OUTPUT); return 0 on error */
double pow_ten_pos(const unsigned int num) {
#if (defined(ENV64BIT))
    if (num > (unsigned int)22) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (unsigned int)11) { return 0; }
#endif
    else if (num == (unsigned int)0x00) { return 1.0; }
    else {
        register unsigned int i;
        register double power = 1.0;
        for (i = num; --i;) power *= (double)10.0;
        return power;
    }
}


/** Return the power of 10^num for positive exponents (i.e. 10^num=OUTPUT); return 0 on error */
float pow_ten_posf(const unsigned int num) {
#if (defined(ENV64BIT))
    if (num > (unsigned int)10) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (unsigned int)5) { return 0; }
#endif
    else if (num == (unsigned int)0x00) { return (float)1.0F; }
    else {
        register unsigned int i;
        register float power = 1.0F;
        for (i = num; --i;) power *= (float)10.0F;
        return power;
    }
}


/** Return the power of 10^num for positive exponents (i.e. 10^num=OUTPUT); return 0 on error */
long double pow_ten_posl(const unsigned long int num) {
#if (defined(ENV64BIT))
    if (num > (unsigned long int)27) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (unsigned long int)13) { return 0; }
#endif
    else if (num == (unsigned long int)0x00) { return (long double)1.0L; }
    else {
        register unsigned long int i;
        long double power = 1.0L;
        for (i = num; --i;) power *= (long double)10.0L;
        return power;
    }
}


/** Return the power of 10^num for negative exponents (i.e. 10^-num=OUTPUT); return 0 on error */
double pow_ten_neg(const signed int num) {
    register signed int xnum = num;
    if (xnum < (signed int)0x00) xnum = ((signed int)0x00 - xnum);
#if (defined(ENV64BIT))
    if (xnum > (signed int)323) { return 0; }
#elif (defined(ENV32BIT))
    if (xnum > (signed int)161) { return 0; }
#endif
    else if (xnum == (signed int)0x00) { return (double)1.0; }
    else {
        register signed int i;
        register double power = 1.0;
        for (i = xnum; --i;) power *= (double)0.1;
        return power;
    }
}


/** Return the power of 10^num for negative exponents (i.e. 10^num=OUTPUT); return 0 on error */
float pow_ten_negf(const signed int num) {
    register signed int xnum = num;
    if (xnum < (signed int)0x00) xnum = ((signed int)0 - num);
#if (defined(ENV64BIT))
    if (xnum > (signed int)45) { return 0; }
#elif (defined(ENV32BIT))
    if (xnum > (signed int)22) { return 0; }
#endif
    else if (xnum == (signed int)0x00) { return (float)1.0F; }
    else {
        register signed int i;
        register float power = 1.0F;
        for (i = xnum; --i;) power *= (float)0.1F;
        return power;
    }
}


/** Return the power of 10^num for negative exponents (i.e. 10^num=OUTPUT); return 0 on error */
long double pow_ten_negl(const slint num) {
    register slint xnum = num;
    if (xnum < (signed long int)0x00) xnum = ((signed long int)0x00 - num);
#if (defined(ENV64BIT))
    if (xnum > (signed long int)4893) { return 0; }
#elif (defined(ENV32BIT))
    if (xnum > (signed long int)2440) { return 0; }
#endif
    else if (xnum == (signed long int)0x00) { return (long double)1.0L; }
    else {
        register signed long int i;
        long double power = 1.0L;
        for (i = xnum; --i;) power *= (long double)0.1L;
        return power;
    }
}


/** Return the power of base^exponent for positive numbers */
ullint unsigned_pow(const unsigned int base, const unsigned int exponent) {
    if (exponent == (unsigned int)0x00) return (ullint)0x01;
    else if (base == (unsigned int)0x00) return (ullint)0x00;
    else if (exponent == (unsigned int)1) return (ullint)base;
    else {
        register unsigned int i;
        register ullint power = (ullint)base;
        for (i = exponent; --i;) { power *= (ullint)base; }
        return power;
    }
}


/** Return the power of base^exponent */
double signed_pow(const signed int base, const signed int exponent) {
    if (exponent == (signed int)0x00) { return (double)1.0; }
    else if (base == (signed int)0x00) { return (double)0.0; }
    else if (exponent == (signed int)0x01) { return (double)base; }
    else if (exponent < (signed int)0x00) {
        register signed int i, power;
        power = base;
        register signed int expo = (signed int)((signed int)0x00 - exponent);
        for (i = (signed int)0x01; i < expo; ++i) { power *= base; }
        return ((double)1.0 / ((double)(1.0 * (double)power)));
    } else {
        register signed int i, power;
        power = base;
        for (i = (signed int)0x01; i < exponent; ++i) { power *= base; }
        return (double)(1.0 * (double)power);
    }
}


/** Return the power of base^exponent */
long double signed_powl(const slint base, const slint exponent) {
    if (exponent == (slint)0x00) return (long double)1.0L;
    else if (base == (slint)0x00) return (long double)0.0L;
    else if (exponent == (slint)1) return (long double)base;
    else if (exponent < (slint)0x00) {
        register slint i, power;
        power = base;
        register slint expo = ((slint)0x00 - exponent);
        for (i = (slint)0x01; i < expo; ++i) power *= base;
        return (long double)1.0L / (long double)power;
    } else {
        register slint i, power;
        power = base;
        for (i = (slint)0x01; i < exponent; ++i) power *= base;
        return (long double)power;
    }
}


/** Modulo Exponentiation (B^E % M) */
signed int mod_pow(const signed int base, const signed int exponent, const signed int modulus) {
    if (modulus == 0x01 || exponent < 0x00) { return 0; }
    register signed int power;
    if (exponent == 0x00) { power = 1; }
    else {
        register signed int i;
        power = (signed int)base;
        for (i = 0x01; i < (signed int)exponent; ++i) { power *= base; }
    }
    return (signed int)((signed int)power % (signed int)modulus);
}


/** Modulo Exponentiation (B^E % M) */
sllint mod_pow_longlong(const sllint base, const sllint exponent, const sllint modulus) {
    if (modulus == (sllint)0x01 || exponent < (sllint)0x00) { return (sllint)0; }
    register sllint power;
    if (exponent == (sllint)0x00) { power = (sllint)0x01; }
    else {
        register sllint i;
        power = base;
        for (i = (sllint)0x01; i < exponent; ++i) power *= base;
    }
    return (sllint)(power % modulus);
}


/* ROOTS */


/** Approximate (and rounded) square-root of an unsigned long long int */
ullint sqrtull(const ullint num) {
    register ullint y = 1, delta = 3;
    while (y <= num) {
        y += delta;  // (y+1)^2
        delta += (ullint)2;
    }
    return ((delta >> (ullint)0x01) - (ullint)0x01);
}


/** Return the Square-Root of a positive number (Limit: 1000000000000000.0) */
double squareroot(const double num) {
    if (num < (double)0.0) return -1.0;
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
    return (double)((start + end) * (double)0.5);
}


/** Return the Square-Root of a positive number (Limit: 1000000000.0) */
float squarerootf(const float num) {
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
    return (float)((start + end) * (float)0.5F);
}


/** Return the Square-Root of a positive number */
long double squarerootl(const long double num) {
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
    return (long double)((start + end) * (long double)0.5L);
}


/** Approximate square root of an integer */
uint8_t sqrt16(const uint16_t num) {
    register uint8_t x = 0x8, y = 0x8;
    for (;;) {
        if ((uint16_t)(y * y) > num) { y ^= x; }
        x >>= 0x1;
        if (x == 0x00) { return y; }
        y |= x;
    }
}


/** Approximate square root of an integer */
uint16_t sqrt32(const uint32_t num) {
    register uint16_t x = 0x80, y = 0x80;
    for (;;) {
        if ((uint32_t)(y * y) > num) { y ^= x; }
        x >>= 0x01;
        if (x == 0x0) { return y; }
        y |= x;
    }
}


/** Approximate square root of an integer */
uint32_t sqrt64(const uint64_t num) {
    register uint32_t x = 0x8000, y = 0x8000;
    for (;;) {
        if ((uint64_t)(y * y) > num) { y ^= x; }
        x >>= 0x01;
        if (x == 0x00) { return y; }
        y |= x;
    }
}


/** Inverse Square Root of an integer */
uint8_t isqrt8(const uint8_t num) {
    register uint8_t root = 0x00, remainder = num, place = 0x40;
    while (place > remainder) { place >>= 0x02; }
    while (place) {
        if (remainder >= (root + place)) {
            remainder = (uint8_t)((remainder - root) - place);
            root = (uint8_t)(root + (uint8_t)((uint8_t)place << (uint8_t)0x01));
        }
        root >>= 0x01;
        place >>= 0x02;
    }
    return root;
}


/** Inverse Square Root of an integer */
uint16_t isqrt16(const uint16_t num) {
    register uint16_t root = 0x00, remainder = num, place = 0x4000;
    while (place > remainder) { place >>= 0x02; }
    while (place) {
        if (remainder >= (root + place)) {
            remainder = (uint16_t)((remainder - root) - place);
            root = (uint16_t)(root + ((uint16_t)place << (uint16_t)0x01));
        }
        root >>= 0x01;
        place >>= 0x02;
    }
    return root;
}


/** Inverse Square Root of an integer */
uint32_t isqrt32(const uint32_t num) {
    register uint32_t root = 0x00, remainder = num, place = 0x40000000;
    while (place > remainder) { place >>= 0x02; }
    while (place) {
        if (remainder >= (root + place)) {
            remainder = (uint32_t)((remainder - root) - place);
            root += (uint32_t)(place << 0x1);
        }
        root >>= 0x1;
        place >>= 0x2;
    }
    return root;
}


/** Inverse Square Root of an integer */
uint64_t isqrt64(const uint64_t num) {
    register uint64_t root = 0x00, remainder = num, place = 0x4000000000000000;
    while (place > remainder) { place >>= 0x02; }
    while (place) {
        if (remainder >= (root + place)) {
            remainder = (uint64_t)((remainder - root) - place);
            root += (uint64_t)(place << 0x01);
        }
        root >>= 0x01;
        place >>= 0x02;
    }
    return root;
}


/** Return the Triangular root of the given number ((√(8*num+1)−1)/2) */
double triangular_root(const long num) {
    return ((squareroot((double)(8 * num + 1)) - 1.0) * 0.5);
}


/** Return the Hexagonal root of the given number ((√(8*num+1)+1)/4) */
double hexagonal_root(const long num) {
    return ((squareroot((double)(8 * num + 1)) + 1.0) * 0.25);
}


/** Return the Heptagonal root of the given number ((√(40*num+9)+3)/10) */
double heptagonal_root(const long num) {
    return ((squareroot((double)(40 * num + 9)) + 3.0) * 0.1);
}


/* FACTORIALS */


/** Factorial (n!); return 0 on error */
ullint factorial(const unsigned int num) {
#if (defined(ENV64BIT))
    if (num > (unsigned int)22) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (unsigned int)11) { return 0; }
#endif
    else if (num == (unsigned int)0x0 || num == (unsigned int)1) { return (ullint)1; }
    register ullint i, fct = (ullint)num;
    for (i = fct - (ullint)1; --i;) { fct *= i; }
    return fct;
}


/** Factorial (n!); return 0 on error */
sllint factoriallonglong(const sllint num) {
#if (defined(ENV64BIT))
    if (num > (sllint)20) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (sllint)10) { return 0; }
#endif
    else if (num == (sllint)0 || num == (sllint)1) { return (sllint)1; }
    register sllint i, fct = (sllint)num;
    for (i = fct - (sllint)1; --i;) fct *= i;
    return fct;
}


/** Double Factorial (n!!); return 0 on error */
ullint doublefactorial(const unsigned int num) {
#if (defined(ENV64BIT))
    if (num > (unsigned int)30) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (unsigned int)10) { return 0; }
#endif
    else if (num == (unsigned int)0x0 || num == (unsigned int)1) { return (ullint)1; }
    else if (num == (unsigned int)0x2) { return (ullint)2; }
    else if (num == (unsigned int)0x3) { return (ullint)3; }
    else if (num == (unsigned int)0x4) { return (ullint)8; }
    register ullint i, fct = (ullint)num;
    if ((num % (unsigned int)2) == (unsigned int)0x0) {  // Even
        for (i = (fct - (ullint)2); i > 0x1; i = (ullint)(i - (ullint)2)) {
            if (i <= 0x1) { break; }
            else if (i == 0x2) { fct *= i; break; }
            fct *= i;
        }
    } else {  // Odd
        for (i = (fct - (ullint)2); i > 0x2; i = (ullint)(i - (ullint)2)) {
            if (i <= 0x2) { break; }
            else if (i == 0x3) { fct *= i; break; }
            fct *= i;
        }
    }
    return fct;
}


/** Double Factorial (n!!); return 0 on error */
sllint doublefactoriallonglong(const sllint num) {
#if (defined(ENV64BIT))
    if (num > (sllint)30) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (sllint)9) { return 0; }
#endif
    else if (num < (sllint)0x0) { return (sllint)0x0; }
    else if (num == (sllint)0x0 || num == (sllint)0x1) { return (sllint)0x1; }
    else if (num == (sllint)0x2) { return (sllint)2; }
    else if (num == (sllint)0x3) { return (sllint)3; }
    else if (num == (sllint)0x4) { return (sllint)8; }
    register sllint i, fct = (sllint)num;
    if ((num % (sllint)2) == (sllint)0x0) {  // Even
        for (i = (sllint)(fct - (sllint)2); i > 0x1; i = (sllint)(i - (sllint)2)) {
            if (i <= 0x1) { break; }
            else if (i == 0x2) { fct *= i; break; }
            fct *= i;
        }
    } else {  // Odd
        for (i = (fct - (sllint)2); i > 0x2; i = (sllint)(i - (sllint)2)) {
            if (i <= 0x2) { break; }
            else if (i == 0x3) { fct *= i; break; }
            fct *= i;
        }
    }
    return fct;
}


/** Quadruple Factorial - (2n)!/n!; return 0 on error */
ullint quadfactorial(const unsigned int num) {
#if (defined(ENV64BIT))
    if (num > (unsigned int)10) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (unsigned int)5) { return 0; }
#endif
    else if (num == (unsigned int)0) { return (ullint)1; }
    else if (num == (unsigned int)1) { return (ullint)2; }
    register ullint i, fct1 = (ullint)num, fct2 = (ullint)(num + num);
    for (i = fct1 - (ullint)1; i > (ullint)0; --i) { fct1 *= i; }
    for (i = fct2 - (ullint)1; i > (ullint)0; --i) { fct2 *= i; }
    return (fct2 / fct1);
}


/** Quadruple Factorial - (2n)!/n!; return 0 on error */
sllint quadfactoriallonglong(const sllint num) {
    switch (num) {
        case (sllint)0: return (sllint)1;
        case (sllint)1: return (sllint)2;
        case (sllint)2: return (sllint)12;
        case (sllint)3: return (sllint)120;
        case (sllint)4: return (sllint)1680;
        case (sllint)5: return (sllint)30240;
        case (sllint)6: return (sllint)665280;
        case (sllint)7: return (sllint)17297280;
        case (sllint)8: return (sllint)518918400;
        case (sllint)9: return (sllint)17643225600;
        default: return 0;
    }
    return 0;
}


/** Super-Factorial; return 0 on error */
ullint superfactorial(const unsigned int num) {
#if (defined(ENV64BIT))
    if (num > (unsigned int)9) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (unsigned int)4) { return 0; }
#endif
    else if (num == (unsigned int)0 || num == (unsigned int)1) { return (ullint)1; }
    register ullint i, j, fct = 1;
    for (i = (ullint)num; --i;) { for (j = i; --j;) fct *= j; }
    return fct;
}


/** Super-Factorial; return 0 on error */
sllint superfactoriallonglong(const sllint num) {
    switch (num) {
        case 0: return 1;
        case 1: return 1;
        case 2: return 2;
        case 3: return 12;
        case 4: return 288;
        case 5: return 34560;
        case 6: return 24883200;
#       if (defined(ENV64BIT))
        case 7: return 125411328000;
        case 8: return 5056584744960000;
#       elif (defined(ENV128BIT))
        case 9: return 1834933472251084800000;
        case 10: return 6658606584104736522240000000;
        case 11: return 265790267296391946810949632000000000;
        //case 12: return 127313963299399416749559771247411200000000000;
#       endif
        default: return 0;
    }
    return 0;
}


/** Find the number used to produce the factorial */
int unfactorial(const int num) {
    register int x, y = num;
    for (x = 0x1; y != x; ++x) { y /= x; }
    return x;
}


/** Find the number used to produce the factorial */
uint64_t unfactorial64(const uint64_t num) {
    register uint64_t x, y = num;
    for (x = 0x1; y != x; ++x) { y /= x; }
    return x;
}


/* NUMBER GENERATORS */


/** Return the Nth Pronic number */
unsigned int pronic(const unsigned int num) {
    return ((num * num) + num);
}


/** Return the Nth Pronic number */
ullint pronicull(const ullint num) {
    return (((ullint)num * (ullint)num) + (ullint)num);
}


/** Return the Nth Pronic number */
sllint proniclonglong(const sllint num) {
    return (((sllint)num * (sllint)num) + (sllint)num);
}


#ifdef UINT128_SUPPORTED
/** Return the Nth Pronic number (128-bit unsigned integer) */
uint128_t pronic_u128(const uint128_t num) {
    return (((uint128_t)num * (uint128_t)num) + (uint128_t)num);
}
#endif


/** Fibonacci Number Generator; return 0 on error */
unsigned int fib(const unsigned int num) {
#if (defined(ENV64BIT))
    if (num > (unsigned int)48) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (unsigned int)24) { return 0; }
#endif
    else if (num == (unsigned int)0x00) { return 0; }
    else if (num == (unsigned int)1 || num == (unsigned int)2) { return 1; }
    else {
        unsigned int fibval[num + 1];
        fibval[0] = (unsigned int)0;
        fibval[1] = (unsigned int)1;
        fibval[2] = (unsigned int)1;
        fibval[3] = (unsigned int)2;
        fibval[4] = (unsigned int)3;
        register unsigned int i;
        for (i = (unsigned int)4; i <= num; ++i)
            fibval[i] = fibval[i - (unsigned int)1] + fibval[i - (unsigned int)2];
        return fibval[num];
    }
}


/** Fibonacci Number Generator; return 0 on error */
unsigned long int longfib(const unsigned long int num) {
#if (defined(ENV64BIT))
    if (num > (ulint)91) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (ulint)37) { return 0; }
#endif
    else if (num <= (ulint)12) {
        switch (num) {
            case (ulint)0: return (ulint)0;
            case (ulint)1: return (ulint)1;
            case (ulint)2: return (ulint)1;
            case (ulint)3: return (ulint)2;
            case (ulint)4: return (ulint)3;
            case (ulint)5: return (ulint)5;
            case (ulint)6: return (ulint)8;
            case (ulint)7: return (ulint)13;
            case (ulint)8: return (ulint)21;
            case (ulint)9: return (ulint)34;
            case (ulint)10: return (ulint)55;
            case (ulint)11: return (ulint)89;
            default: return (ulint)144;  // case (ulint)12
        }
    }
    ulint fibval[92];
    fibval[0] = (ulint)0;
    fibval[1] = (ulint)1;
    fibval[2] = (ulint)1;
    fibval[3] = (ulint)2;
    fibval[4] = (ulint)3;
    fibval[5] = (ulint)5;
    fibval[6] = (ulint)8;
    fibval[7] = (ulint)13;
    fibval[8] = (ulint)21;
    fibval[9] = (ulint)34;
    fibval[10] = (ulint)55;
    fibval[11] = (ulint)89;
    fibval[12] = (ulint)144;
    register ulint i;
    for (i = (ulint)13; i <= num; ++i) fibval[i] = fibval[i - (ulint)1] + fibval[i - (ulint)2];
    return fibval[num];
}


/** Fibonacci Number Generator; return 0 on error */
sllint longlongfib(const sllint num) {
#if (defined(ENV64BIT))
    if ((num < (sllint)0x00) || (num > (sllint)91)) { return 0x0; }
#elif (defined(ENV32BIT))
    if ((num < (sllint)0x00) || (num > (sllint)35)) { return 0x0; }
#endif
    else if ((num >= 0x00) && (num <= (sllint)14)) {
        switch (num) {
            case (sllint)0: return (sllint)0x0;
            case (sllint)1: return (sllint)1;
            case (sllint)2: return (sllint)1;
            case (sllint)3: return (sllint)2;
            case (sllint)4: return (sllint)3;
            case (sllint)5: return (sllint)5;
            case (sllint)6: return (sllint)8;
            case (sllint)7: return (sllint)13;
            case (sllint)8: return (sllint)21;
            case (sllint)9: return (sllint)34;
            case (sllint)10: return (sllint)55;
            case (sllint)11: return (sllint)89;
            case (sllint)12: return (sllint)144;
            case (sllint)13: return (sllint)233;
            default: return (sllint)377;  // case (sllint)14
        }
    }
    sllint fibval[92];
    fibval[0] = (sllint)0x0;
    fibval[1] = (sllint)1;
    fibval[2] = (sllint)1;
    fibval[3] = (sllint)2;
    fibval[4] = (sllint)3;
    fibval[5] = (sllint)5;
    fibval[6] = (sllint)8;
    fibval[7] = (sllint)13;
    fibval[8] = (sllint)21;
    fibval[9] = (sllint)34;
    fibval[10] = (sllint)55;
    fibval[11] = (sllint)89;
    fibval[12] = (sllint)144;
    fibval[13] = (sllint)233;
    fibval[14] = (sllint)377;
    register sllint i;
    for (i = (sllint)15; i <= (sllint)num; ++i) { fibval[i] = (sllint)(fibval[i - (sllint)1] + fibval[i - (sllint)2]); if (i >= num) { break; } }
    return fibval[num];
}


/** Return the Nth Triangular Number */
unsigned int triangular_num(const unsigned int num) {
    return (unsigned int)((num * (num + 1)) / 2);
}


/** Return the Nth Triangular Number */
ullint triangular_numull(const ullint num) {
    return (ullint)((num * (num + (ullint)1)) / (ullint)2);
}


/** Return the Nth Triangular Number */
sllint triangular_numlonglong(const sllint num) {
    return (sllint)((num * (num + (sllint)1)) / (sllint)2);
}


#ifdef UINT128_SUPPORTED
/** Return the Nth Triangular Number (128-bit unsigned integer) */
uint128_t triangular_u128(const uint128_t num) {
    return (uint128_t)((num * (num + (uint128_t)1)) / (uint128_t)2);
}
#endif


/** Return the Nth Hexagonal Number */
unsigned int hexagonal_num(const unsigned int num) {
    register unsigned int num2 = num + num;
    return (unsigned int)((num2 * (num2 - 1)) / 2);
}


/** Return the Nth Hexagonal Number */
ullint hexagonal_numull(const ullint num) {
    register ullint num2 = num + num;
    return (ullint)((num2 * (num2 - (ullint)1)) / (ullint)2);
}


/** Return the Nth Hexagonal Number */
sllint hexagonal_numlonglong(const sllint num) {
    register sllint num2 = (num + num);
    return (sllint)((num2 * (num2 - (sllint)0x1)) / (sllint)0x2);
}


#ifdef UINT128_SUPPORTED
/** Return the Nth Hexagonal Number (128-bit unsigned integer) */
uint128_t hexagonal_u128(const uint128_t num) {
    register uint128_t num2 = (num + num);
    return (uint128_t)((num2 * (num2 - (uint128_t)0x1)) / (uint128_t)0x2);
}
#endif


/** Return the Nth Heptagonal Number ((5*(num^2) - 3 * num)/2) */
unsigned int heptagonal_num(const unsigned int num) {
    return (unsigned int)((((num * num) * 5) - (3 * num)) / 2);
}


/** Return the Nth Heptagonal Number ((5*(num^2) - 3 * num)/2) */
ullint heptagonal_numull(const ullint num) {
    return (ullint)((((num * num) * (ullint)5) - ((ullint)3 * num)) / (ullint)2);
}


/** Return the Nth Heptagonal Number ((5*(num^2) - 3 * num)/2) */
sllint heptagonal_numlonglong(const sllint num) {
    return (sllint)((((num * num) * (sllint)5) - ((sllint)3 * num)) / (sllint)2);
}


#ifdef UINT128_SUPPORTED
/** Return the Nth Heptagonal Number ((5*(num^2) - 3 * num)/2) (128-bit unsigned integer) */
uint128_t heptagonal_u128(const uint128_t num) {
    return (uint128_t)((((num * num) * (uint128_t)0x5) - ((uint128_t)0x3 * num)) / (uint128_t)0x2);
}
#endif


/** Return the Nth Tetrahedral Number */
unsigned int tetrahedral_num(const unsigned int num) {
    return (unsigned int)((num * (num + 1) * (num + 2)) / 6);
}


/** Return the Nth Tetrahedral Number */
ullint tetrahedral_numull(const ullint num) {
    return (ullint)((num * (num + (ullint)1) * (num + (ullint)2)) / (ullint)6);
}


/** Return the Nth Tetrahedral Number */
sllint tetrahedral_numlonglong(const sllint num) {
    return (num * (num + (sllint)1) * (num + (sllint)2)) / (sllint)6;
}


#ifdef UINT128_SUPPORTED
/** Return the Nth Tetrahedral Number (128-bit unsigned integer) */
uint128_t tetrahedral_u128(const uint128_t num) {
    return (num * (num + (uint128_t)0x1) * (num + (uint128_t)0x2)) / (uint128_t)0x6;
}
#endif


/** Return the Nth Pentatope Number */
unsigned int pentatope_num(const unsigned int num) {
    return ((num * (num + 1) * (num + 2) * (num + 3)) / 24);
}


/** Return the Nth Pentatope Number */
ullint pentatope_numull(const ullint num) {
    return ((num * (num + (ullint)1) * (num + (ullint)2) * (num + (ullint)3)) / (ullint)24);
}


/** Return the Nth Pentatope Number */
sllint pentatope_numlonglong(const sllint num) {
    return ((num * (num + (sllint)1) * (num + (sllint)2) * (num + (sllint)3)) / (sllint)24);
}


#ifdef UINT128_SUPPORTED
/** Return the Nth Pentatope Number (128-bit unsigned integer) */
uint128_t pentatope_u128(const uint128_t num) {
    return ((num * (num + (uint128_t)0x1) * (num + (uint128_t)0x2) * (num + (uint128_t)0x3)) / (uint128_t)0x24);
}
#endif


/** Return the Nth Mersenne Number; return 0 on error */
unsigned int mersenne_num(const unsigned int num) {
#if (defined(ENV64BIT))
    if (num > (unsigned int)31) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (unsigned int)15) { return 0; }
#endif
    else { return (((unsigned int)0x01 << num) - 0x01); }
}


/** Return the Nth Mersenne Number; return 0 on error */
ullint mersenne_numull(const ullint num) {
#if (defined(ENV64BIT))
    if (num > (ullint)63) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (ullint)31) { return 0; }
#endif
    return (((ullint)0x01 << num) - 0x01);
}


/** Return the Nth Mersenne Number; return 0 on error */
sllint mersenne_numlonglong(const sllint num) {
#if (defined(ENV64BIT))
    if (num > (sllint)63) { return 0; }
#elif (defined(ENV32BIT))
    if (num > (sllint)31) { return 0; }
#endif
    return (((sllint)0x01 << num) - 0x01);
}


#ifdef UINT128_SUPPORTED
/** Return the Nth Mersenne Number (128-bit unsigned integer); return 0 on error */
uint128_t mersenne_u128(const uint128_t num) {
    if ((uint128_t)num > (uint128_t)126) { return 0; }
    return (((uint128_t)0x01 << num) - (uint128_t)0x01);
}
#endif


/* TRIGONOMETRY (DOUBLES) */


/** Returns the principal value of the arc tangent of y/x, expressed in radians */
double ATAN2(const double y, const double x) {
    if (isnan(x) || isnan(y)) { return NAN; }
    if (isinf(y)) {
        if (isinf(x)) {
            if (copysign(1.0, x) == 1.0) { return copysign(0.25 * PI, y); }  // atan2(+-inf, +inf) == +-pi/4
            else { return copysign(0.75 * PI, y); }  // atan2(+-inf, -inf) == +-pi*3/4
        }
        return copysign(0.5 * PI, y);  // atan2(+-inf, x) == +-pi/2 for finite x
    }
    if (isinf(x) || y == 0.0) {
        if (copysign(1.0, x) == 1.0) { return copysign(0.0, y); }  // atan2(+-y, +inf) = atan2(+-0, +x) = +-0.0
        else { return copysign(PI, y); }  // atan2(+-y, -inf) = atan2(+-0., -x) = +-pi
    }
    return atan2(y, x);
}


/** Return the Pi Sine of the given number; return 0.0 on error */
double sinpi(const double num) {
    register double r;
    if (!(isfinite(num))) { return 0.0; }
    register double x = fmod(fabs(num), 2.0);
    register slint n = (slint)lround(2.0 * x);
    switch (n) {
        case 0:
            r = sin(PI * x);
            break;
        case 1:
            r = cos(PI * (x - 0.5));
            break;
        case 2:
            r = sin(PI * (1.0 - x));
            break;
        case 3:
            r = (-cos(PI * (x - 1.5)));
            break;
        case 4:
            r = sin(PI * (x - 2.0));
            break;
        default:  // Should never get here
            r = 0.0;
            break;
    }
    return (copysign(1.0, num) * r);
}


/** Return the Chord */
double crd(const double radians) {
    return ((double)2.0 * sin(radians / (double)2.0));
}


/** Return the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x)) */
double acot(const double radians) {
    return atan((double)1.0 / radians);
}


/** Return the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x)) */
double arccot(const double radians) {
    return atan((double)1.0 / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x)) */
double acoth(const double radians) {
    return atanh((double)1.0 / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x)) */
double arccoth(const double radians) {
    return atanh((double)1.0 / radians);
}


/** Return the Hyperbolic Cotangent (coth(x) == 1/tanh(x)) */
double coth(const double radians) {
    return ((double)1.0 / tanh(radians));
}


/** Return the Cotangent (cot(x) == 1/tan(x)) */
double cot(const double radians) {
    return ((double)1.0 / tan(radians));
}


/** Return the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x)) */
double acsc(const double radians) {
    return asin((double)1.0 / radians);
}


/** Return the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x)) */
double arccsc(const double radians) {
    return asin((double)1.0 / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsch(x)||arccsch(x) == asinh(1/x)) */
double acsch(const double radians) {
    return asinh((double)1.0 / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsc(x)||arccsch(x) == asinh(1/x)) */
double arccsch(const double radians) {
    return asinh((double)1.0 / radians);
}


/** Return the Hyperbolic Cosecant (csch(x) == 1/sinh(x)) */
double csch(const double radians) {
    return ((double)1.0 / sinh(radians));
}


/** Return the Cosecant (csc(x) == 1/sin(x)) */
double csc(const double radians) {
    return ((double)1.0 / sin(radians));
}


/** Return the Arc-Secant (asec(x)||arcsec(x) == acos(1/x)) */
double asec(const double radians) {
    return acos((double)1.0 / radians);
}


/** Return the Arc-Secant (asec(x)||arcsec(x) == acos(1/x)) */
double arcsec(const double radians) {
    return acos((double)1.0 / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x)) */
double asech(const double radians) {
    return acosh((double)1.0 / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x)) */
double arcsech(const double radians) {
    return acosh((double)1.0 / radians);
}


/** Return the Hyperbolic Secant (sech(x) == 1/cosh(x)) */
double sech(const double radians) {
    return ((double)1.0 / cosh(radians));
}


/** Return the Secant (sec(x) == 1/cos(x)) */
double sec(const double radians) {
    return ((double)1.0 / cos(radians));
}


/** Return the Arc-Versed Sine (arcversin(x) == 1 - acos(x)) */
double arcversin(const double radians) {
    return ((double)1.0 - acos(radians));
}


/** Return the Hyperbolic Arc-Versed Sine (arcversinh(x) == 1 - acosh(x)) */
double arcversinh(const double radians) {
    return ((double)1.0 - acosh(radians));
}


/** Return the Hyperbolic Versed Sine (versinh(x) == 1 - cosh(x)) */
double versinh(const double radians) {
    return ((double)1.0 - cosh(radians));
}


/** Return the Versed Sine (versin(x) == 1 - cos(x)) */
double versin(const double radians) {
    return ((double)1.0 - cos(radians));
}


/** Return the Arc-Versed Cosine (arcvercos(x) == 1 - asin(x)) */
double arcvercos(const double radians) {
    return ((double)1.0 - asin(radians));
}


/** Return the Hyperbolic Arc-Versed Cosine (arcvercosh(x) == 1 - asinh(x)) */
double arcvercosh(const double radians) {
    return ((double)1.0 - asinh(radians));
}


/** Return the Hyperbolic Versed Cosine (vercosh(x) == 1 - sinh(x)) */
double vercosh(const double radians) {
    return ((double)1.0 - sinh(radians));
}


/** Return the Versed Cosine (vercos(x) == 1 - sin(x)) */
double vercos(const double radians) {
    return ((double)1.0 - sin(radians));
}


/** Return the Haversine (haversin(x) == 0.5*(1 - cos(x))) */
double haversin(const double radians) {
    return ((double)0.5 * ((double)1.0 - cos(radians)));
}


/** Return the Hacoversine (hacoversin(x) == 0.5*(1 - sin(x))) */
double hacoversin(const double radians) {
    return ((double)0.5 * ((double)1.0 - sin(radians)));
}


/* TRIGONOMETRY (LONG DOUBLES) */


/** Return the Chord */
long double crdl(const long double radians) {
    return ((long double)2.0L * sinl(radians / (long double)2.0L));
}


/** Return the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x)) */
long double acotl(const long double radians) {
    return atanl((long double)1.0L / radians);
}


/** Return the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x)) */
long double arccotl(const long double radians) {
    return atanl((long double)1.0L / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x)) */
long double acothl(const long double radians) {
    return atanhl((long double)1.0L / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x)) */
long double arccothl(const long double radians) {
    return atanhl((long double)1.0L / radians);
}


/** Return the Hyperbolic Cotangent (coth(x) == 1/tanh(x)) */
long double cothl(const long double radians) {
    return ((long double)1.0L / tanhl(radians));
}


/** Return the Cotangent (cot(x) == 1/tan(x)) */
long double cotl(const long double radians) {
    return ((long double)1.0L / tanl(radians));
}


/** Return the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x)) */
long double acscl(const long double radians) {
    return asinl((long double)1.0L / radians);
}


/** Return the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x)) */
long double arccscl(const long double radians) {
    return asinl((long double)1.0L / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsch(x)||arccsch(x) == asinh(1/x)) */
long double acschl(const long double radians) {
    return asinhl((long double)1.0L / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsc(x)||arccsch(x) == asinh(1/x)) */
long double arccschl(const long double radians) {
    return asinhl((long double)1.0L / radians);
}


/** Return the Hyperbolic Cosecant (csch(x) == 1/sinh(x)) */
long double cschl(const long double radians) {
    return ((long double)1.0L / sinhl(radians));
}


/** Return the Cosecant (csc(x) == 1/sin(x)) */
long double cscl(const long double radians) {
    return ((long double)1.0L / sinl(radians));
}


/** Return the Arc-Secant (asec(x)||arcsec(x) == acos(1/x)) */
long double asecl(const long double radians) {
    return acosl((long double)1.0L / radians);
}


/** Return the Arc-Secant (asec(x)||arcsec(x) == acos(1/x)) */
long double arcsecl(const long double radians) {
    return acosl((long double)1.0L / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x)) */
long double asechl(const long double radians) {
    return acoshl((long double)1.0L / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x)) */
long double arcsechl(const long double radians) {
    return acoshl((long double)1.0L / radians);
}


/** Return the Hyperbolic Secant (sech(x) == 1/cosh(x)) */
long double sechl(const long double radians) {
    return ((long double)1.0L / coshl(radians));
}


/** Return the Secant (sec(x) == 1/cos(x)) */
long double secl(const long double radians) {
    return ((long double)1.0L / cosl(radians));
}


/** Return the Arc-Versed Sine (arcversin(x) == 1 - acos(x)) */
long double arcversinl(const long double radians) {
    return ((long double)1.0L - acosl(radians));
}


/** Return the Hyperbolic Arc-Versed Sine (arcversinh(x) == 1 - acosh(x)) */
long double arcversinhl(const long double radians) {
    return ((long double)1.0L - acoshl(radians));
}


/** Return the Hyperbolic Versed Sine (versinh(x) == 1 - cosh(x)) */
long double versinhl(const long double radians) {
    return ((long double)1.0L - coshl(radians));
}


/** Return the Versed Sine (versin(x) == 1 - cos(x)) */
long double versinl(const long double radians) {
    return ((long double)1.0L - cosl(radians));
}


/** Return the Arc-Versed Cosine (arcvercos(x) == 1 - asin(x)) */
long double arcvercosl(const long double radians) {
    return ((long double)1.0L - asinl(radians));
}


/** Return the Hyperbolic Arc-Versed Cosine (arcvercosh(x) == 1 - asinh(x)) */
long double arcvercoshl(const long double radians) {
    return ((long double)1.0L - asinhl(radians));
}


/** Return the Hyperbolic Versed Cosine (vercosh(x) == 1 - sinh(x)) */
long double vercoshl(const long double radians) {
    return ((long double)1.0L - sinhl(radians));
}


/** Return the Versed Cosine (vercos(x) == 1 - sin(x)) */
long double vercosl(const long double radians) {
    return ((long double)1.0L - sinl(radians));
}


/** Return the Haversine (haversin(x) == 0.5*(1 - cos(x))) */
long double haversinl(const long double radians) {
    return ((long double)0.5L * ((long double)1.0L - cosl(radians)));
}


/** Return the Hacoversine (hacoversin(x) == 0.5*(1 - sin(x))) */
long double hacoversinl(const long double radians) {
    return ((long double)0.5L * ((long double)1.0L - sinl(radians)));
}


/* TRIGONOMETRY (FLOATS) */


/** Return the Chord */
float crdf(const float radians) {
    return ((float)2.0F * sinf(radians / (float)2.0F));
}


/** Return the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x)) */
float acotf(const float radians) {
    return atanf((float)1.0F / radians);
}


/** Return the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x)) */
float arccotf(const float radians) {
    return atanf((float)1.0F / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x)) */
float acothf(const float radians) {
    return atanhf((float)1.0F / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x)) */
float arccothf(const float radians) {
    return atanhf((float)1.0F / radians);
}


/** Return the Hyperbolic Cotangent (coth(x) == 1/tanh(x)) */
float cothf(const float radians) {
    return ((float)1.0F / tanhf(radians));
}


/** Return the Cotangent (cot(x) == 1/tan(x)) */
float cotf(const float radians) {
    return ((float)1.0F / tanf(radians));
}


/** Return the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x)) */
float acscf(const float radians) {
    return asinf((float)1.0F / radians);
}


/** Return the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x)) */
float arccscf(const float radians) {
    return asinf((float)1.0F / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsch(x)||arccsch(x) == asinh(1/x)) */
float acschf(const float radians) {
    return asinhf((float)1.0F / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsc(x)||arccsch(x) == asinh(1/x)) */
float arccschf(const float radians) {
    return asinhf((float)1.0F / radians);
}


/** Return the Hyperbolic Cosecant (csch(x) == 1/sinh(x)) */
float cschf(const float radians) {
    return ((float)1.0F / sinhf(radians));
}


/** Return the Cosecant (csc(x) == 1/sin(x)) */
float cscf(const float radians) {
    return ((float)1.0F / sinf(radians));
}


/** Return the Arc-Secant (asec(x)||arcsec(x) == acos(1/x)) */
float asecf(const float radians) {
    return acosf((float)1.0F / radians);
}


/** Return the Arc-Secant (asec(x)||arcsec(x) == acos(1/x)) */
float arcsecf(const float radians) {
    return acosf((float)1.0F / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x)) */
float asechf(const float radians) {
    return acoshf((float)1.0F / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x)) */
float arcsechf(const float radians) {
    return acoshf((float)1.0F / radians);
}


/** Return the Hyperbolic Secant (sech(x) == 1/cosh(x)) */
float sechf(const float radians) {
    return ((float)1.0F / coshf(radians));
}


/** Return the Secant (sec(x) == 1/cos(x)) */
float secf(const float radians) {
    return ((float)1.0F / cosf(radians));
}


/** Return the Arc-Versed Sine (arcversin(x) == 1 - acos(x)) */
float arcversinf(const float radians) {
    return ((float)1.0F - acosf(radians));
}


/** Return the Hyperbolic Arc-Versed Sine (arcversinh(x) == 1 - acosh(x)) */
float arcversinhf(const float radians) {
    return ((float)1.0F - acoshf(radians));
}


/** Return the Hyperbolic Versed Sine (versinh(x) == 1 - cosh(x)) */
float versinhf(const float radians) {
    return ((float)1.0F - coshf(radians));
}


/** Return the Versed Sine (versin(x) == 1 - cos(x)) */
float versinf(const float radians) {
    return ((float)1.0F - cosf(radians));
}


/** Return the Arc-Versed Cosine (arcvercos(x) == 1 - asin(x)) */
float arcvercosf(const float radians) {
    return ((float)1.0F - asinf(radians));
}


/** Return the Hyperbolic Arc-Versed Cosine (arcvercosh(x) == 1 - asinh(x)) */
float arcvercoshf(const float radians) {
    return ((float)1.0F - asinhf(radians));
}


/** Return the Hyperbolic Versed Cosine (vercosh(x) == 1 - sinh(x)) */
float vercoshf(const float radians) {
    return ((float)1.0F - sinhf(radians));
}


/** Return the Versed Cosine (vercos(x) == 1 - sin(x)) */
float vercosf(const float radians) {
    return ((float)1.0F - sinf(radians));
}


/** Return the Haversine (haversin(x) == 0.5*(1 - cos(x))) */
float haversinf(const float radians) {
    return ((float)0.5F * ((float)1.0F - cosf(radians)));
}


/** Return the Hacoversine (hacoversin(x) == 0.5*(1 - sin(x))) */
float hacoversinf(const float radians) {
    return ((float)0.5F * ((float)1.0F - sinf(radians)));
}


/* EXTERNAL TRIGONOMETRY (DOUBLES) */


/** Return the Arc-External Cotangent (arcexcot(x) == atan(1/(x+1))) */
double arcexcot(const double radians) {
    return atan((double)1.0 / (radians + (double)1.0));
}


/** Return the Hyperbolic Arc-External Cotangent [arcexcoth(x) == (1/atanh(x)-1)] */
double arcexcoth(const double radians) {
    return (((double)1.0 / atanh(radians)) - (double)1.0);
}


/** Return the External Hyperbolic Cotangent [excoth(x) == (1/tanh(x)-1)] */
double excoth(const double radians) {
    return (((double)1.0 / tanh(radians)) - (double)1.0);
}


/** Return the External Cotangent [excot(x) == (1/tan(x))-1 == cot(x)-1] */
double excot(const double radians) {
    return (((double)1.0 / tan(radians)) - (double)1.0);
}


/** Return the Arc-External Cosecant (arcexcsc(x) == asin(1/(x+1))) */
double arcexcsc(const double radians) {
    return asin((double)1.0 / (radians + (double)1.0));
}


/** Return the Hyperbolic Arc-External Cosecant [arcexcsch(x) == (1/asinh(x)-1)] */
double arcexcsch(const double radians) {
    return (((double)1.0 / asinh(radians)) - (double)1.0);
}


/** Return the External Hyperbolic Cosecant [excsch(x) == (1/sinh(x)-1)] */
double excsch(const double radians) {
    return (((double)1.0 / sinh(radians)) - (double)1.0);
}


/** Return the External Cosecant [excsc(x) == (1/sin(x))-1 == csc(x)-1] */
double excsc(const double radians) {
    return (((double)1.0 / sin(radians)) - (double)1.0);
}


/** Return the Arc-External Secant (arcexsec(x) == acos(1/(x+1))) */
double arcexsec(const double radians) {
    return acos((double)1.0 / (radians + (double)1.0));
}


/** Return the Hyperbolic Arc-External Secant [arcexsech(x) == (1/acosh(x)-1)] */
double arcexsech(const double radians) {
    return (((double)1.0 / acosh(radians)) - (double)1.0);
}


/** Return the External Hyperbolic Secant [exsech(x) == (1/cosh(x)-1)] */
double exsech(const double radians) {
    return (((double)1.0 / cosh(radians)) - (double)1.0);
}


/** Return the External Secant [exsec(x) == (1/cos(x))-1 == sec(x)-1] */
double exsec(const double radians) {
    return (((double)1.0 / cos(radians)) - (double)1.0);
}


/* EXTERNAL TRIGONOMETRY (LONG DOUBLES) */


/** Return the Arc-External Cotangent (arcexcot(x) == atan(1/(x+1))) */
long double arcexcotl(const long double radians) {
    return atanl((long double)1.0L / (radians + (long double)1.0L));
}


/** Return the Hyperbolic Arc-External Cotangent [arcexcoth(x) == (1/atanh(x)-1)] */
long double arcexcothl(const long double radians) {
    return (((long double)1.0L / atanhl(radians)) - (long double)1.0L);
}


/** Return the External Hyperbolic Cotangent [excoth(x) == (1/tanh(x)-1)] */
long double excothl(const long double radians) {
    return (((long double)1.0L / tanhl(radians)) - (long double)1.0L);
}


/** Return the External Cotangent [excot(x) == (1/tan(x))-1 == cot(x)-1] */
long double excotl(const long double radians) {
    return (((long double)1.0L / tanl(radians)) - (long double)1.0L);
}


/** Return the Arc-External Cosecant (arcexcsc(x) == asin(1/(x+1))) */
long double arcexcscl(const long double radians) {
    return asinl((long double)1.0L / (radians + (long double)1.0L));
}


/** Return the Hyperbolic Arc-External Cosecant [arcexcsch(x) == (1/asinh(x)-1)] */
long double arcexcschl(const long double radians) {
    return (((long double)1.0L / asinhl(radians)) - (long double)1.0L);
}


/** Return the External Hyperbolic Cosecant [excsch(x) == (1/sinh(x)-1)] */
long double excschl(const long double radians) {
    return (((long double)1.0L / sinhl(radians)) - (long double)1.0L);
}


/** Return the External Cosecant [excsc(x) == (1/sin(x))-1 == csc(x)-1] */
long double excscl(const long double radians) {
    return (((long double)1.0L / sinl(radians)) - (long double)1.0L);
}


/** Return the Arc-External Secant (arcexsec(x) == acos(1/(x+1))) */
long double arcexsecl(const long double radians) {
    return acosl((long double)1.0L / (radians + (long double)1.0L));
}


/** Return the Hyperbolic Arc-External Secant [arcexsech(x) == (1/acosh(x)-1)] */
long double arcexsechl(const long double radians) {
    return (((long double)1.0L / acoshl(radians)) - (long double)1.0L);
}


/** Return the External Hyperbolic Secant [exsech(x) == (1/cosh(x)-1)] */
long double exsechl(const long double radians) {
    return (((long double)1.0L / coshl(radians)) - (long double)1.0L);
}


/** Return the External Secant [exsec(x) == (1/cos(x))-1 == sec(x)-1] */
long double exsecl(const long double radians) {
    return (((long double)1.0L / cosl(radians)) - (long double)1.0L);
}


/* EXTERNAL TRIGONOMETRY (FLOATS) */


/** Return the Arc-External Cotangent (arcexcot(x) == atan(1/(x+1))) */
float arcexcotf(const float radians) {
    return atanf((float)1.0F / (radians + (float)1.0F));
}


/** Return the Hyperbolic Arc-External Cotangent [arcexcoth(x) == (1/atanh(x)-1)] */
float arcexcothf(const float radians) {
    return (((float)1.0F / atanhf(radians)) - (float)1.0F);
}


/** Return the External Hyperbolic Cotangent [excoth(x) == (1/tanh(x)-1)] */
float excothf(const float radians) {
    return (((float)1.0F / tanhf(radians)) - (float)1.0F);
}


/** Return the External Cotangent [excot(x) == (1/tan(x))-1 == cot(x)-1] */
float excotf(const float radians) {
    return (((float)1.0F / tanf(radians)) - (float)1.0F);
}


/** Return the Arc-External Cosecant (arcexcsc(x) == asin(1/(x+1))) */
float arcexcscf(const float radians) {
    return asinf((float)1.0F / (radians + (float)1.0F));
}


/** Return the Hyperbolic Arc-External Cosecant [arcexcsch(x) == (1/asinh(x)-1)] */
float arcexcschf(const float radians) {
    return (((float)1.0F / asinhf(radians)) - (float)1.0F);
}


/** Return the External Hyperbolic Cosecant [excsch(x) == (1/sinh(x)-1)] */
float excschf(const float radians) {
    return (((float)1.0F / sinhf(radians)) - (float)1.0F);
}


/** Return the External Cosecant [excsc(x) == (1/sin(x))-1 == csc(x)-1] */
float excscf(const float radians) {
    return (((float)1.0F / sinf(radians)) - (float)1.0F);
}


/** Return the Arc-External Secant (arcexsec(x) == acos(1/(x+1))) */
float arcexsecf(const float radians) {
    return acosf((float)1.0F / (radians + (float)1.0F));
}


/** Return the Hyperbolic Arc-External Secant [arcexsech(x) == (1/acosh(x)-1)] */
float arcexsechf(const float radians) {
    return (((float)1.0F / acoshf(radians)) - (float)1.0F);
}


/** Return the External Hyperbolic Secant [exsech(x) == (1/cosh(x)-1)] */
float exsechf(const float radians) {
    return (((float)1.0F / coshf(radians)) - (float)1.0F);
}


/** Return the External Secant [exsec(x) == (1/cos(x))-1 == sec(x)-1] */
float exsecf(const float radians) {
    return (((float)1.0F / cosf(radians)) - (float)1.0F);
}


/* SPECIAL TRIGONOMETRIC FUNCTIONS (DOUBLES) */


/** Return the Cosine of an Arc-Sine [sqrt(1-(x*x))] */
double cos_arcsin(const double radians) {
    return (squareroot((double)1.0 - (radians * radians)));
}


/** Return the Cosine of an Arc-Tangent [1 / sqrt(1+(x*x))] */
double cos_arctan(const double radians) {
    return ((double)1.0 / squareroot((double)1.0 + (radians * radians)));
}


/** Return the Sine of an Arc-Tangent [sqrt((x*x)-1)/x] */
double sin_arcsec(const double radians) {
    return (squareroot((radians * radians) - (double)1.0) / radians);
}


/** Return the Sine of an Arc-Tangent [x / sqrt(1+(x*x))] */
double sin_arctan(const double radians) {
    return (radians / squareroot((double)1.0 + (radians * radians)));
}


/* SPECIAL TRIGONOMETRIC FUNCTIONS (FLOATS) */


/** Return the Cosine of an Arc-Sine [sqrt(1-(x*x))] */
float cos_arcsinf(const float radians) {
    return (squarerootf((float)1.0 - (radians * radians)));
}


/** Return the Cosine of an Arc-Tangent [1 / sqrt(1+(x*x))] */
float cos_arctanf(const float radians) {
    return ((float)1.0 / squarerootf((float)1.0 + (radians * radians)));
}


/** Return the Sine of an Arc-Tangent [sqrt((x*x)-1)/x] */
float sin_arcsecf(const float radians) {
    return (squarerootf((radians * radians) - (float)1.0) / radians);
}


/** Return the Sine of an Arc-Tangent [x / sqrt(1+(x*x))] */
float sin_arctanf(const float radians) {
    return (radians / squarerootf((float)1.0 + (radians * radians)));
}


/* SPECIAL TRIGONOMETRIC FUNCTIONS (LONG DOUBLES) */


/** Return the Cosine of an Arc-Sine [sqrt(1-(x*x))] */
long double cos_arcsinl(const long double radians) {
    return (squarerootl((long double)1.0L - (radians * radians)));
}


/** Return the Cosine of an Arc-Tangent [1 / sqrt(1+(x*x))] */
long double cos_arctanl(const long double radians) {
    return ((long double)1.0L / squarerootl((long double)1.0 + (radians * radians)));
}


/** Return the Sine of an Arc-Tangent [sqrt((x*x)-1)/x] */
long double sin_arcsecl(const long double radians) {
    return (squarerootl((radians * radians) - (long double)1.0L) / radians);
}


/** Return the Sine of an Arc-Tangent [x / sqrt(1+(x*x))] */
long double sin_arctanl(const long double radians) {
    return (radians / squarerootl((long double)1.0L + (radians * radians)));
}


/* AVERAGES */


/** Return the mean (average) of a set of numbers */
double mean(const int count, ...) {
    va_list varargs;
    va_start(varargs, count);
    register double average = (double)va_arg(varargs, int);
    register int i;
    for (i = 1; i < count; ++i) average += (double)va_arg(varargs, int);
    va_end(varargs);
    return (double)(average / (double)count);
}


/** Return the mean (average) of a set of numbers */
float meanf(const int count, ...) {
    va_list varargs;
    va_start(varargs, count);
    register float average = (float)va_arg(varargs, int);
    register int i;
    for (i = 1; i < count; ++i) average += (float)va_arg(varargs, int);
    va_end(varargs);
    return (float)(average / (float)count);
}


/** Return the mean (average) of a set of numbers */
long double meanl(const long long int count, ...) {
    va_list varargs;
    va_start(varargs, count);
    register long double average = (long double)va_arg(varargs, sllint);
    register sllint i;
    for (i = (sllint)1; i < count; ++i) average += (long double)va_arg(varargs, sllint);
    va_end(varargs);
    return (long double)(average / (long double)count);
}


/** Return the mean (average) of a set of numbers */
double longmean(const slint count, ...) {
    va_list varargs;
    va_start(varargs, count);
    register double average = (double)va_arg(varargs, slint);
    register slint i;
    for (i = (slint)1; i < count; ++i) average += (double)va_arg(varargs, slint);
    va_end(varargs);
    return (double)(average / (double)count);
}


/* COMPARISONS */


#ifndef OSWINDOWS
/** Return the largest (maximum) number */
int max(const int count, ...) {
    va_list varargs;
    va_start(varargs, count);
    register int ans = va_arg(varargs, int);
    register int i, num;
    for (i = 1; i < count; ++i) {
        num = va_arg(varargs, int);
        ans = (ans > num ? ans : num);
    }
    va_end(varargs);
    return ans;
}


/** xx */
int min(const int count, ...) {
    // Return the smallest (minimum) number
    va_list varargs;
    va_start(varargs, count);
    register int ans = va_arg(varargs, int);
    register int i, num;
    for (i = 1; i < count; ++i) {
        num = va_arg(varargs, int);
        ans = (ans < num ? ans : num);
    }
    va_end(varargs);
    return ans;
}
#endif


/** Return the largest (maximum) float */
float maxf(const int count, ...) {
    va_list varargs;
    va_start(varargs, count);
    register double num, ans = va_arg(varargs, double);
    register int i;
    for (i = 1; i < count; ++i) {
        num = va_arg(varargs, double);
        ans = (ans > num ? ans : num);
    }
    va_end(varargs);
    return (float)ans;
}


/** Return the smallest (minimum) float */
float minf(const int count, ...) {
    va_list varargs;
    va_start(varargs, count);
    register double num, ans = va_arg(varargs, double);
    register int i;
    for (i = 1; i < count; ++i) {
        num = va_arg(varargs, double);
        ans = (ans < num ? ans : num);
    }
    va_end(varargs);
    return (float)ans;
}


/** Return the largest (maximum) double */
double maxd(const int count, ...) {
    va_list varargs;
    va_start(varargs, count);
    register double num, ans = va_arg(varargs, double);
    register int i;
    for (i = 1; i < count; ++i) {
        num = va_arg(varargs, double);
        ans = (ans > num ? ans : num);
    }
    va_end(varargs);
    return ans;
}


/** Return the smallest (minimum) double */
double mind(const int count, ...) {
    va_list varargs;
    va_start(varargs, count);
    register double num, ans = va_arg(varargs, double);
    register int i;
    for (i = 1; i < count; ++i) {
        num = va_arg(varargs, double);
        ans = (ans < num ? ans : num);
    }
    va_end(varargs);
    return ans;
}


/* TESTS */


/** Test if the float is negative */
int is_float_negative(float num) {
    const uint32_t *sign_bit = (uint32_t *)&num;
    return (int)((*sign_bit & 0x80000000) != 0x0);
}


/** Test if the double is negative */
int is_double_negative(double num) {
    const uint64_t *sign_bit = (uint64_t *)&num;
    return (int)((*sign_bit & 0x8000000000000000) != 0x0);
}


/** Test if the float is positive */
int is_float_positive(float num) {
    const uint32_t *sign_bit = (uint32_t *)&num;
    return (int)!((*sign_bit & (uint32_t)0x80000000));
}


/** Test if the double is positive */
int is_double_positive(double num) {
    const uint64_t *sign_bit = (uint64_t *)&num;
    return (int)!((*sign_bit & (uint64_t)0x8000000000000000));
}


/** Test if a number is a perfect square */
int issquare(const int num) {
    if (num < 0x00) return -1;
    register double test = floor(squareroot((double)num) + (double)0.5);
    if ((int)(test * test) == num) return 1;
    return 0;
}


/** Test if a number is a perfect square */
int islongsquare(const long num) {
    if (num < (long)0x00) return -1;
    register double test = floor(squareroot((double)num) + (double)0.5);
    if ((long)(test * test) == num) return 1;
    return 0;
}


/** Test if a number is a perfect square */
int islonglongsquare(const long long num) {
    if (num < (long long)0x00) return -1;
    long double test = floorl(squarerootl((long double)num) + (long double)0.5L);
    if ((long long)(test * test) == num) return 1;
    return 0;
}


/** Test if a float is a perfect square */
int isfloatsquare(const float num) {
    if (num < (float)0.0F) return -1;
    register float test = floorf(squarerootf(num) + (float)0.5F);
    if ((float)(test * test) == num) return 1;
    return 0;
}


/** Test if a double is a perfect square */
int isdoublesquare(const double num) {
    if (num < (double)0.0) return -1;
    register double test = floor(squareroot(num) + (double)0.5);
    if ((double)(test * test) == num) return 1;
    return 0;
}


/** Test if a long double is a perfect square */
int islongdoublesquare(const long double num) {
    if (num < (long double)0.0L) return -1;
    long double test = floorl(squarerootl(num) + (long double)0.5L);
    if ((long double)(test * test) == num) return 1;
    return 0;
}


/** Test if the given number is a Triangular Number */
int istriangular(const long num) {
    if (num < (long)0x00) return -1;
    return islongsquare((long)((long)8 * num + (long)1));
}


/** Test if the given number is a Triangular Number */
int islonglongtriangular(const long long num) {
    if (num < (long long)0x00) return -1;
    return islonglongsquare((long long)((long long)8 * num + (long long)1));
}


/** Test if the given number is a Triangular Number */
int isdoubletriangular(const double num) {
    if (num < (double)0.0) return -1;
    return isdoublesquare((double)((double)8.0 * num + (double)1.0));
}


/** Test if the given number is a Hexagonal Number */
int ishexagonal(const long num) {
    if (num < (long)0x00) return -1;
    register double ans = ((squareroot((double)((long)8 * num + (long)1)) + 1.0) * 0.25);
    if (ans == floor(ans)) return 1;
    return 0;
}


/** Test if the given number is a Hexagonal Number */
int islonglonghexagonal(const long long num) {
    if (num < (long long)0x00) return -1;
    long double ans = ((squarerootl((long double)((long long)8 * num + (long long)1)) + 1.0L) * 0.25L);
    if (ans == floorl(ans)) return 1;
    return 0;
}


/** Test if the given number is a Heptagonal Number */
int isheptagonal(const long num) {
    if (num < (long)0x00) return -1;
    register double ans = ((squareroot((double)((long)40 * num + (long)9)) + 3.0) * 0.1);
    if (ans == floor(ans)) return 1;
    return 0;
}


/** Test if the given number is a Heptagonal Number */
int islonglongheptagonal(const long long num) {
    if (num < (long long)0x00) return -1;
    long double ans = ((squarerootl((long double)((long long)40 * num + (long long)9)) + 3.0L) * 0.1L);
    if (ans == floorl(ans)) return 1;
    return 0;
}


/** Test if the given number is a Power-of-Two */
int ispoweroftwo(const unsigned int num) {
    return ((num != 0x00) && !(num & (num - 1)));
}


/** Test if the given number is a Power-of-Two */
int islonglongpoweroftwo(const long long num) {
    return ((num != (long long)0x00) && !(num & (num - (long long)1)));
}


/** Test if the given number is a Power-of-Two */
int isullpoweroftwo(const ullint num) {
    return ((num != (ullint)0x00) && !(num & (num - (ullint)1)));
}


/** Test if the given number is a Mersenne Number */
int ismersennenumber(const unsigned int num) {
    return (((num + 1) != 0x00) && !((num + 1) & ((num + 1) - 1)));
}


/** Test if the given number is a Mersenne Number */
int islonglongmersennenumber(const long long num) {
    return (((num + (long long)1) != (long long)0x00) && !((num + (long long)1) & ((num + (long long)1) - (long long)1)));
}


/** Test if the given number is a Mersenne Prime */
int ismersenneprime(const unsigned int num) {
    switch (num) {
        case 1: return 0;
        case 3: return 1;
        case 7: return 1;
        case 31: return 1;
        case 127: return 1;
        case 8191: return 1;
        case 131071: return 1;
        case 524287: return 1;
        case 2147483647: return 1;
        default: return 0;
    }
    return 0;
}


/** Test if the given number is a Mersenne Prime */
int islonglongmersenneprime(const sllint num) {
    if ((num & 0x01) == 0) return 0;
    else if (num == 1) return 0;
    else if (((num + 1) != 0) && !((num + 1) & ((num + 1) - 1))) {
        if (num < (sllint)128) {
            if (num == 3 || num == 7 || num == 31 || num == 127) return 1;
            else return 0;
        }
        else if (num % 3 == 0 || num % 5 == 0 || num % 7 == 0)
            return 0;
        else if (num % 11 == 0 || num % 13 == 0 || num % 17 == 0)
            return 0;
        else if (num % 19 == 0 || num % 23 == 0 || num % 29 == 0)
            return 0;
        else if (num % 31 == 0 || num % 37 == 0 || num % 41 == 0)
            return 0;
        register sllint i;
        for (i = (sllint)129; i < num; i += (sllint)2) {
            if (num % i == (sllint)0) return (int)(i == num);
        }
        return 1;
    }
    return 0;
}


/** Test if a signed int is prime */
int isprime(const int num) {
    if ((num & 0x01) == 0) return 0;
    else if (num < 20) {
        switch (num) {
            case 1: return 0;
            case 3: return 1;
            case 7: return 1;
            case 11: return 1;
            case 13: return 1;
            case 17: return 1;
            case 19: return 1;
            default: return 0;
        }
    }
    else if (num % 3 == 0 || num % 5 == 0 || num % 7 == 0 || num % 11 == 0)
        return 0;
    else if (num % 13 == 0 || num % 17 == 0 || num % 19 == 0)
        return 0;
    register int i;
    for (i = 23; i < num; i += 2) { if (num % i == 0x00) return (int)(i == num); }
    return 1;
}


/** Test if an unsigned int is prime */
int isunsignedprime(const unsigned int num) {
    if ((num & (unsigned int)0x01) == (unsigned int)0) return 0;
    else if (num < (unsigned int)20) {
        switch (num) {
            case (unsigned int)1: return 0;
            case (unsigned int)3: return 1;
            case (unsigned int)7: return 1;
            case (unsigned int)11: return 1;
            case (unsigned int)13: return 1;
            case (unsigned int)17: return 1;
            case (unsigned int)19: return 1;
            default: return 0;
        }
    }
    else if (num % (unsigned int)3 == (unsigned int)0)
        return 0;
    else if (num % (unsigned int)5 == (unsigned int)0)
        return 0;
    else if (num % (unsigned int)7 == (unsigned int)0)
        return 0;
    else if (num % (unsigned int)11 == (unsigned int)0)
        return 0;
    else if (num % (unsigned int)13 == (unsigned int)0)
        return 0;
    else if (num % (unsigned int)17 == (unsigned int)0)
        return 0;
    else if (num % (unsigned int)19 == (unsigned int)0)
        return 0;
    register unsigned int i;
    for (i = (unsigned int)23; i < num; i += (unsigned int)2) {
        if (num % i == (unsigned int)0) return (int)(i == num);
    }
    return 1;
}


/** Test if a long int is prime */
int islongprime(const long num) {
    if ((num & (long)0x01) == (long)0) return 0;
    else if (num < (long)20) {
        switch (num) {
            case (long)1: return 0;
            case (long)3: return 1;
            case (long)7: return 1;
            case (long)11: return 1;
            case (long)13: return 1;
            case (long)17: return 1;
            case (long)19: return 1;
            default: return 0;
        }
    }
    else if (num % (long)3 == (long)0 || num % (long)5 == (long)0 || num % (long)7 == (long)0)
        return 0;
    else if (num % (long)11 == (long)0 || num % (long)13 == (long)0)
        return 0;
    else if (num % (long)17 == (long)0 || num % (long)19 == (long)0)
        return 0;
    register long i;
    for (i = (long)23; i < num; i += (long)2) {
        if (num % i == (long)0) return (int)(i == num);
    }
    return 1;
}


/** Test if a long long int is prime */
int islonglongprime(const long long num) {
    if ((num & (long long)0x01) == (long long)0) return 0;
    else if (num < (long long)20) {
        switch (num) {
            case (long long)1: return 0;
            case (long long)3: return 1;
            case (long long)7: return 1;
            case (long long)11: return 1;
            case (long long)13: return 1;
            case (long long)17: return 1;
            case (long long)19: return 1;
            default: return 0;
        }
    }
    else if (num % (long long)3 == (long long)0 || num % (long long)5 == (long long)0)
        return 0;
    else if (num % (long long)7 == (long long)0 || num % (long long)11 == (long long)0)
        return 0;
    else if (num % (long long)13 == (long long)0 || num % (long long)17 == (long long)0 || num % (long long)19 == (long long)0)
        return 0;
    register long long i;
    for (i = (long long)23; i < num; i += (long long)2) {
        if (num % i == (long long)0) return (int)(i == num);
    }
    return 1;
}


/** Test if a unsigned long int is prime */
int isulprime(const ulint num) {
    if ((num & (ulint)0x01) == (ulint)0) return 0;
    else if (num < (ulint)20) {
        switch (num) {
            case (ulint)1: return 0;
            case (ulint)3: return 1;
            case (ulint)7: return 1;
            case (ulint)11: return 1;
            case (ulint)13: return 1;
            case (ulint)17: return 1;
            case (ulint)19: return 1;
            default: break;
        }
    }
    else if (num % (ulint)3 == (ulint)0) return 0;
    else if (num % (ulint)5 == (ulint)0) return 0;
    else if (num % (ulint)7 == (ulint)0) return 0;
    else if (num % (ulint)11 == (ulint)0) return 0;
    else if (num % (ulint)13 == (ulint)0) return 0;
    else if (num % (ulint)17 == (ulint)0) return 0;
    else if (num % (ulint)19 == (ulint)0) return 0;
    register ulint i;
    for (i = (ulint)23; i < num; i += (ulint)2) {
        if (num % i == (ulint)0) return (int)(i == num);
    }
    return 1;
}


/** Test if a unsigned long long int is prime */
int isullprime(const ullint num) {
    if ((num & (ullint)0x01) == (ullint)0) return 0;
    else if (num < (ullint)20) {
        switch (num) {
            case (ullint)1: return 0;
            case (ullint)3: return 1;
            case (ullint)7: return 1;
            case (ullint)11: return 1;
            case (ullint)13: return 1;
            case (ullint)17: return 1;
            case (ullint)19: return 1;
            default: break;
        }
    }
    else if (num % (ullint)3 == (ullint)0) return 0;
    else if (num % (ullint)5 == (ullint)0) return 0;
    else if (num % (ullint)7 == (ullint)0) return 0;
    else if (num % (ullint)11 == (ullint)0) return 0;
    else if (num % (ullint)13 == (ullint)0) return 0;
    else if (num % (ullint)17 == (ullint)0) return 0;
    else if (num % (ullint)19 == (ullint)0) return 0;
    register ullint i;
    for (i = (ullint)23; i < num; i += (ullint)2) {
        if (num % i == (ullint)0) return (int)(i == num);
    }
    return 1;
}


/** Test if an int is composite */
int iscomposite(const int num) {
    if ((num & 0x01) == 0) return 1;
    else if (num < 0) return 0;
    else if (num < 20) {
        switch (num) {
            case 1: return 0;
            case 3: return 0;
            case 7: return 0;
            case 11: return 0;
            case 13: return 0;
            case 17: return 0;
            case 19: return 0;
            default: return 1;
        }
    }
    else if (num % 3 == 0 || num % 5 == 0 || num % 7 == 0)
        return 1;
    else if (num % 11 == 0 || num % 13 == 0 || num % 17 == 0 || num % 19 == 0)
        return 1;
    register int i;
    for (i = 23; i < num; i += 2) {
        if (num % i == 0) return (int)(i != num);
    }
    return 0;
}


/** Test if an unsigned int is composite */
int isunsignedcomposite(const unsigned int num) {
    if ((num & (unsigned int)0x01) == (unsigned int)0) return 1;
    else if (num < (unsigned int)20) {
        switch (num) {
            case (unsigned int)1: return 0;
            case (unsigned int)3: return 0;
            case (unsigned int)7: return 0;
            case (unsigned int)11: return 0;
            case (unsigned int)13: return 0;
            case (unsigned int)17: return 0;
            case (unsigned int)19: return 0;
            default: return 1;
        }
    }
    else if (num % (unsigned int)3 == (unsigned int)0) return 1;
    else if (num % (unsigned int)5 == (unsigned int)0) return 1;
    else if (num % (unsigned int)7 == (unsigned int)0) return 1;
    else if (num % (unsigned int)11 == (unsigned int)0) return 1;
    else if (num % (unsigned int)13 == (unsigned int)0) return 1;
    else if (num % (unsigned int)17 == (unsigned int)0) return 1;
    else if (num % (unsigned int)19 == (unsigned int)0) return 1;
    register unsigned int i;
    for (i = (unsigned int)23; i < num; i += (unsigned int)2) {
        if (num % i == (unsigned int)0) return (int)(i != num);
    }
    return 0;
}


/** Test if an long is composite */
int islongcomposite(const long num) {
    if ((num & (long)0x01) == (long)0) return 1;
    else if (num < (long)0) return 0;
    else if (num < (long)20) {
        switch (num) {
            case (long)1: return 0;
            case (long)3: return 0;
            case (long)7: return 0;
            case (long)11: return 0;
            case (long)13: return 0;
            case (long)17: return 0;
            case (long)19: return 0;
            default: return 1;
        }
    }
    else if (num % (long)3 == (long)0) return 1;
    else if (num % (long)5 == (long)0) return 1;
    else if (num % (long)7 == (long)0) return 1;
    else if (num % (long)11 == (long)0) return 1;
    else if (num % (long)13 == (long)0) return 1;
    else if (num % (long)17 == (long)0) return 1;
    else if (num % (long)19 == (long)0) return 1;
    register long i;
    for (i = (long)23; i < num; i += (long)2) {
        if (num % i == (long)0) return (int)(i != num);
    }
    return 0;
}


/** Test if an long long is composite */
int islonglongcomposite(const long long num) {
    if ((num & (long long)0x01) == (long long)0) return 1;
    else if (num < (long long)0) return 0;
    else if (num < (long long)20) {
        switch (num) {
            case (long long)1: return 0;
            case (long long)3: return 0;
            case (long long)7: return 0;
            case (long long)11: return 0;
            case (long long)13: return 0;
            case (long long)17: return 0;
            case (long long)19: return 0;
            default: return 1;
        }
    }
    else if (num % (long long)3 == (long long)0) return 1;
    else if (num % (long long)5 == (long long)0) return 1;
    else if (num % (long long)7 == (long long)0) return 1;
    else if (num % (long long)11 == (long long)0) return 1;
    else if (num % (long long)13 == (long long)0) return 1;
    else if (num % (long long)17 == (long long)0) return 1;
    else if (num % (long long)19 == (long long)0) return 1;
    register long long i;
    for (i = (long long)23; i < num; i += (long long)2) {
        if (num % i == (long long)0) return (int)(i != num);
    }
    return 0;
}


/** Test if an unsigned long int is composite */
int isulcomposite(const ulint num) {
    if ((num & (ulint)0x01) == (ulint)0) return 1;
    else if (num < (ulint)20) {
        switch (num) {
            case (ulint)1: return 0;
            case (ulint)3: return 0;
            case (ulint)7: return 0;
            case (ulint)11: return 0;
            case (ulint)13: return 0;
            case (ulint)17: return 0;
            case (ulint)19: return 0;
            default: return 1;
        }
    }
    else if (num % (ulint)3 == (ulint)0) return 1;
    else if (num % (ulint)5 == (ulint)0) return 1;
    else if (num % (ulint)7 == (ulint)0) return 1;
    else if (num % (ulint)11 == (ulint)0) return 1;
    else if (num % (ulint)13 == (ulint)0) return 1;
    else if (num % (ulint)17 == (ulint)0) return 1;
    else if (num % (ulint)19 == (ulint)0) return 1;
    register ulint i;
    for (i = (ulint)23; i < num; i += (ulint)2) {
        if (num % i == (ulint)0x00) return (int)(i != num);
    }
    return 0;
}


/** Test if an unsigned long long int is composite */
int isullcomposite(const ullint num) {
    if ((num & (ullint)0x01) == (ullint)0) return 1;
    else if (num < (ullint)20) {
        switch (num) {
            case (ullint)1: return 0;
            case (ullint)3: return 0;
            case (ullint)7: return 0;
            case (ullint)11: return 0;
            case (ullint)13: return 0;
            case (ullint)17: return 0;
            case (ullint)19: return 0;
            default: return 1;
        }
    }
    else if (num % (ullint)3 == (ullint)0) return 1;
    else if (num % (ullint)5 == (ullint)0) return 1;
    else if (num % (ullint)7 == (ullint)0) return 1;
    else if (num % (ullint)11 == (ullint)0) return 1;
    else if (num % (ullint)13 == (ullint)0) return 1;
    else if (num % (ullint)17 == (ullint)0) return 1;
    else if (num % (ullint)19 == (ullint)0) return 1;
    register ullint i;
    for (i = (ullint)23; i < num; i += (ullint)2) {
        if (num % i == (ullint)0x00) return (int)(i != num);
    }
    return 0;
}


/* COMPLEX-NUMBER MATH */


// TRIGONOMETRY (COMPLEX DOUBLES)


/** Return the Chord */
double complex ccrd(const double complex radians) {
    return ((double complex)2.0 + 2.0 * I_DOUBLE * csin(radians / (double complex)2.0 + 2.0 * I_DOUBLE));
}


/** Return the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x)) */
double complex cacot(const double complex radians) {
    return catan((double complex)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x)) */
double complex carccot(const double complex radians) {
    return catan((double complex)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x)) */
double complex cacoth(const double complex radians) {
    return catanh((double complex)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x)) */
double complex carccoth(const double complex radians) {
    return catanh((double complex)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Cotangent (coth(x) == 1/tanh(x)) */
double complex ccoth(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE / ctanh(radians));
}


/** Return the Cotangent (cot(x) == 1/tan(x)) */
double complex ccot(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE / ctan(radians));
}


/** Return the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x)) */
double complex cacsc(const double complex radians) {
    return casin((double complex)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x)) */
double complex carccsc(const double complex radians) {
    return casin((double complex)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsch(x)||arccsch(x) == asinh(1/x)) */
double complex cacsch(const double complex radians) {
    return casinh((double complex)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsc(x)||arccsch(x) == asinh(1/x)) */
double complex carccsch(const double complex radians) {
    return casinh((double complex)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Cosecant (csch(x) == 1/sinh(x)) */
double complex ccsch(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE / csinh(radians));
}


/** Return the Cosecant (csc(x) == 1/sin(x)) */
double complex ccsc(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE / csin(radians));
}


/** Return the Arc-Secant (asec(x)||arcsec(x) == acos(1/x)) */
double complex casec(const double complex radians) {
    return cacos((double complex)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Arc-Secant (asec(x)||arcsec(x) == acos(1/x)) */
double complex carcsec(const double complex radians) {
    return cacos((double complex)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x)) */
double complex casech(const double complex radians) {
    return cacosh((double complex)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x)) */
double complex carcsech(const double complex radians) {
    return cacosh((double complex)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Secant (sech(x) == 1/cosh(x)) */
double complex csech(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE / ccosh(radians));
}


/** Return the Secant (sec(x) == 1/cos(x)) */
double complex csec(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE / ccos(radians));
}


/** Return the Arc-Versed Sine (arcversin(x) == 1 - acos(x)) */
double complex carcversin(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE - cacos(radians));
}


/** Return the Hyperbolic Arc-Versed Sine (arcversinh(x) == 1 - acosh(x)) */
double complex carcversinh(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE - cacosh(radians));
}


/** Return the Hyperbolic Versed Sine (versinh(x) == 1 - cosh(x)) */
double complex cversinh(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE - ccosh(radians));
}


/** Return the Versed Sine (versin(x) == 1 - cos(x)) */
double complex cversin(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE - ccos(radians));
}


/** Return the Arc-Versed Cosine (arcvercos(x) == 1 - asin(x)) */
double complex carcvercos(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE - casin(radians));
}


/** Return the Hyperbolic Arc-Versed Cosine (arcvercosh(x) == 1 - asinh(x)) */
double complex carcvercosh(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE - casinh(radians));
}


/** Return the Hyperbolic Versed Cosine (vercosh(x) == 1 - sinh(x)) */
double complex cvercosh(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE - csinh(radians));
}


/** Return the Versed Cosine (vercos(x) == 1 - sin(x)) */
double complex cvercos(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE - csin(radians));
}


/** Return the Haversine (haversin(x) == 0.5*(1 - cos(x))) */
double complex chaversin(const double complex radians) {
    return ((double complex)0.5 * ((double complex)1.0 + 1.0 * I_DOUBLE - ccos(radians)));
}


/** Return the Hacoversine (hacoversin(x) == 0.5*(1 - sin(x))) */
double complex chacoversin(const double complex radians) {
    return ((double complex)0.5 * ((double complex)1.0 + 1.0 * I_DOUBLE - csin(radians)));
}


// TRIGONOMETRY (COMPLEX LONG DOUBLES)


/** Return the Chord */
long double complex ccrdl(const long double complex radians) {
    return ((long double complex)2.0L + 2.0L * I_LONG_DOUBLE * csinl(radians / (long double complex)2.0L + 2.0L * I_LONG_DOUBLE));
}


/** Return the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x)) */
long double complex cacotl(const long double complex radians) {
    return catanl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x)) */
long double complex carccotl(const long double complex radians) {
    return catanl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x)) */
long double complex cacothl(const long double complex radians) {
    return catanhl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x)) */
long double complex carccothl(const long double complex radians) {
    return catanhl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Cotangent (coth(x) == 1/tanh(x)) */
long double complex ccothl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / ctanhl(radians));
}


/** Return the Cotangent (cot(x) == 1/tan(x)) */
long double complex ccotl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / ctanl(radians));
}


/** Return the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x)) */
long double complex cacscl(const long double complex radians) {
    return casinl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x)) */
long double complex carccscl(const long double complex radians) {
    return casinl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsch(x)||arccsch(x) == asinh(1/x)) */
long double complex cacschl(const long double complex radians) {
    return casinhl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsc(x)||arccsch(x) == asinh(1/x)) */
long double complex carccschl(const long double complex radians) {
    return casinhl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Cosecant (csch(x) == 1/sinh(x)) */
long double complex ccschl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / csinhl(radians));
}


/** Return the Cosecant (csc(x) == 1/sin(x)) */
long double complex ccscl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / csinl(radians));
}


/** Return the Arc-Secant (asec(x)||arcsec(x) == acos(1/x)) */
long double complex casecl(const long double complex radians) {
    return cacosl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Arc-Secant (asec(x)||arcsec(x) == acos(1/x)) */
long double complex carcsecl(const long double complex radians) {
    return cacosl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x)) */
long double complex casechl(const long double complex radians) {
    return cacoshl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x)) */
long double complex carcsechl(const long double complex radians) {
    return cacoshl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Secant (sech(x) == 1/cosh(x)) */
long double complex csechl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / ccoshl(radians));
}


/** Return the Secant (sec(x) == 1/cos(x)) */
long double complex csecl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / ccosl(radians));
}


/** Return the Arc-Versed Sine (arcversin(x) == 1 - acos(x)) */
long double complex carcversinl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE - cacosl(radians));
}


/** Return the Hyperbolic Arc-Versed Sine (arcversinh(x) == 1 - acosh(x)) */
long double complex carcversinhl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE - cacoshl(radians));
}


/** Return the Hyperbolic Versed Sine (versinh(x) == 1 - cosh(x)) */
long double complex cversinhl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE - ccoshl(radians));
}


/** Return the Versed Sine (versin(x) == 1 - cos(x)) */
long double complex cversinl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE - ccosl(radians));
}


/** Return the Arc-Versed Cosine (arcvercos(x) == 1 - asin(x)) */
long double complex carcvercosl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE - casinl(radians));
}


/** Return the Hyperbolic Arc-Versed Cosine (arcvercosh(x) == 1 - asinh(x)) */
long double complex carcvercoshl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE - casinhl(radians));
}


/** Return the Hyperbolic Versed Cosine (vercosh(x) == 1 - sinh(x)) */
long double complex cvercoshl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE - csinhl(radians));
}


/** Return the Versed Cosine (vercos(x) == 1 - sin(x)) */
long double complex cvercosl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE - csinl(radians));
}


/** Return the Haversine (haversin(x) == 0.5*(1 - cos(x))) */
long double complex chaversinl(const long double complex radians) {
    return ((long double complex)0.5L * ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE - ccosl(radians)));
}


/** Return the Hacoversine (hacoversin(x) == 0.5*(1 - sin(x))) */
long double complex chacoversinl(const long double complex radians) {
    return ((long double complex)0.5L * ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE - csinl(radians)));
}


// TRIGONOMETRY (COMPLEX FLOATS)


/** Return the Chord */
float complex ccrdf(const float complex radians) {
    return ((float complex)2.0F + 2.0F * I_FLOAT * csinf(radians / (float complex)2.0F + 2.0F * I_FLOAT));
}


/** Return the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x)) */
float complex cacotf(const float complex radians) {
    return catanf((float complex)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Arc-Cotangent (acot(x)||arccot(x) == atan(1/x)) */
float complex carccotf(const float complex radians) {
    return catanf((float complex)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x)) */
float complex cacothf(const float complex radians) {
    return catanhf((float complex)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x)||arccoth(x) == atanh(1/x)) */
float complex carccothf(const float complex radians) {
    return catanhf((float complex)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Cotangent (coth(x) == 1/tanh(x)) */
float complex ccothf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT / ctanhf(radians));
}


/** Return the Cotangent (cot(x) == 1/tan(x)) */
float complex ccotf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT / ctanf(radians));
}


/** Return the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x)) */
float complex cacscf(const float complex radians) {
    return casinf((float complex)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Arc-Cosecant (acsc(x)||arccsc(x) == asin(1/x)) */
float complex carccscf(const float complex radians) {
    return casinf((float complex)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsch(x)||arccsch(x) == asinh(1/x)) */
float complex cacschf(const float complex radians) {
    return casinhf((float complex)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsc(x)||arccsch(x) == asinh(1/x)) */
float complex carccschf(const float complex radians) {
    return casinhf((float complex)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Cosecant (csch(x) == 1/sinh(x)) */
float complex ccschf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT / csinhf(radians));
}


/** Return the Cosecant (csc(x) == 1/sin(x)) */
float complex ccscf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT / csinf(radians));
}


/** Return the Arc-Secant (asec(x)||arcsec(x) == acos(1/x)) */
float complex casecf(const float complex radians) {
    return cacosf((float complex)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Arc-Secant (asec(x)||arcsec(x) == acos(1/x)) */
float complex carcsecf(const float complex radians) {
    return cacosf((float complex)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x)) */
float complex casechf(const float complex radians) {
    return cacoshf((float complex)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x)||arcsech(x) == acosh(1/x)) */
float complex carcsechf(const float complex radians) {
    return cacoshf((float complex)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Secant (sech(x) == 1/cosh(x)) */
float complex csechf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT / ccoshf(radians));
}


/** Return the Secant (sec(x) == 1/cos(x)) */
float complex csecf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT / ccosf(radians));
}


/** Return the Arc-Versed Sine (arcversin(x) == 1 - acos(x)) */
float complex carcversinf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT - cacosf(radians));
}


/** Return the Hyperbolic Arc-Versed Sine (arcversinh(x) == 1 - acosh(x)) */
float complex carcversinhf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT - cacoshf(radians));
}


/** Return the Hyperbolic Versed Sine (versinh(x) == 1 - cosh(x)) */
float complex cversinhf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT - ccoshf(radians));
}


/** Return the Versed Sine (versin(x) == 1 - cos(x)) */
float complex cversinf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT - ccosf(radians));
}


/** Return the Arc-Versed Cosine (arcvercos(x) == 1 - asin(x)) */
float complex carcvercosf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT - casinf(radians));
}


/** Return the Hyperbolic Arc-Versed Cosine (arcvercosh(x) == 1 - asinh(x)) */
float complex carcvercoshf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT - casinhf(radians));
}


/** Return the Hyperbolic Versed Cosine (vercosh(x) == 1 - sinh(x)) */
float complex cvercoshf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT - csinhf(radians));
}


/** Return the Versed Cosine (vercos(x) == 1 - sin(x)) */
float complex cvercosf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT - csinf(radians));
}


/** Return the Haversine (haversin(x) == 0.5*(1 - cos(x))) */
float complex chaversinf(const float complex radians) {
    return ((float complex)0.5F * ((float complex)1.0F + 1.0F * I_FLOAT - ccosf(radians)));
}


/** Return the Hacoversine (hacoversin(x) == 0.5*(1 - sin(x))) */
float complex chacoversinf(const float complex radians) {
    return ((float complex)0.5F * ((float complex)1.0F + 1.0F * I_FLOAT - csinf(radians)));
}


// EXTERNAL TRIGONOMETRY (COMPLEX DOUBLES)


/** Return the Arc-External Cotangent (arcexcot(x) == atan(1/(x+1))) */
double complex carcexcot(const double complex radians) {
    return catan((double complex)1.0 + 1.0 * I_DOUBLE / (radians + (double complex)1.0 + 1.0 * I_DOUBLE));
}


/** Return the Hyperbolic Arc-External Cotangent [arcexcoth(x) == (1/atanh(x)-1)] */
double complex carcexcoth(const double complex radians) {
    return (((double complex)1.0 + 1.0 * I_DOUBLE / catanh(radians)) - (double complex)1.0 + 1.0 * I_DOUBLE);
}


/** Return the External Hyperbolic Cotangent [excoth(x) == (1/tanh(x)-1)] */
double complex cexcoth(const double complex radians) {
    return (((double complex)1.0 + 1.0 * I_DOUBLE / ctanh(radians)) - (double complex)1.0 + 1.0 * I_DOUBLE);
}


/** Return the External Cotangent [excot(x) == (1/tan(x))-1 == cot(x)-1] */
double complex cexcot(const double complex radians) {
    return (((double complex)1.0 + 1.0 * I_DOUBLE / ctan(radians)) - (double complex)1.0 + 1.0 * I_DOUBLE);
}


/** Return the Arc-External Cosecant (arcexcsc(x) == asin(1/(x+1))) */
double complex carcexcsc(const double complex radians) {
    return casin((double complex)1.0 + 1.0 * I_DOUBLE / (radians + (double complex)1.0 + 1.0 * I_DOUBLE));
}


/** Return the Hyperbolic Arc-External Cosecant [arcexcsch(x) == (1/asinh(x)-1)] */
double complex carcexcsch(const double complex radians) {
    return (((double complex)1.0 + 1.0 * I_DOUBLE / casinh(radians)) - (double complex)1.0 + 1.0 * I_DOUBLE);
}


/** Return the External Hyperbolic Cosecant [excsch(x) == (1/sinh(x)-1)] */
double complex cexcsch(const double complex radians) {
    return (((double complex)1.0 + 1.0 * I_DOUBLE / csinh(radians)) - (double complex)1.0 + 1.0 * I_DOUBLE);
}


/** Return the External Cosecant [excsc(x) == (1/sin(x))-1 == csc(x)-1] */
double complex cexcsc(const double complex radians) {
    return (((double complex)1.0 + 1.0 * I_DOUBLE / csin(radians)) - (double complex)1.0 + 1.0 * I_DOUBLE);
}


/** Return the Arc-External Secant (arcexsec(x) == acos(1/(x+1))) */
double complex carcexsec(const double complex radians) {
    return cacos((double complex)1.0 + 1.0 * I_DOUBLE / (radians + (double complex)1.0 + 1.0 * I_DOUBLE));
}


/** Return the Hyperbolic Arc-External Secant [arcexsech(x) == (1/acosh(x)-1)] */
double complex carcexsech(const double complex radians) {
    return (((double complex)1.0 + 1.0 * I_DOUBLE / cacosh(radians)) - (double complex)1.0 + 1.0 * I_DOUBLE);
}


/** Return the External Hyperbolic Secant [exsech(x) == (1/cosh(x)-1)] */
double complex cexsech(const double complex radians) {
    return (((double complex)1.0 + 1.0 * I_DOUBLE / ccosh(radians)) - (double complex)1.0 + 1.0 * I_DOUBLE);
}


/** Return the External Secant [exsec(x) == (1/cos(x))-1 == sec(x)-1] */
double complex cexsec(const double complex radians) {
    return (((double complex)1.0 + 1.0 * I_DOUBLE / ccos(radians)) - (double complex)1.0 + 1.0 * I_DOUBLE);
}


// EXTERNAL TRIGONOMETRY (COMPLEX LONG DOUBLES)


/** Return the Arc-External Cotangent (arcexcot(x) == atan(1/(x+1))) */
long double complex carcexcotl(const long double complex radians) {
    return catanl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / (radians + (long double complex)1.0L + 1.0L * I_LONG_DOUBLE));
}


/** Return the Hyperbolic Arc-External Cotangent [arcexcoth(x) == (1/atanh(x)-1)] */
long double complex carcexcothl(const long double complex radians) {
    return (((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / catanhl(radians)) - (long double complex)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the External Hyperbolic Cotangent [excoth(x) == (1/tanh(x)-1)] */
long double complex cexcothl(const long double complex radians) {
    return (((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / ctanhl(radians)) - (long double complex)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the External Cotangent [excot(x) == (1/tan(x))-1 == cot(x)-1] */
long double complex cexcotl(const long double complex radians) {
    return (((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / ctanl(radians)) - (long double complex)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the Arc-External Cosecant (arcexcsc(x) == asin(1/(x+1))) */
long double complex carcexcscl(const long double complex radians) {
    return casinl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / (radians + (long double complex)1.0L + 1.0L * I_LONG_DOUBLE));
}


/** Return the Hyperbolic Arc-External Cosecant [arcexcsch(x) == (1/asinh(x)-1)] */
long double complex carcexcschl(const long double complex radians) {
    return (((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / casinhl(radians)) - (long double complex)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the External Hyperbolic Cosecant [excsch(x) == (1/sinh(x)-1)] */
long double complex cexcschl(const long double complex radians) {
    return (((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / csinhl(radians)) - (long double complex)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the External Cosecant [excsc(x) == (1/sin(x))-1 == csc(x)-1] */
long double complex cexcscl(const long double complex radians) {
    return (((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / csinl(radians)) - (long double complex)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the Arc-External Secant (arcexsec(x) == acos(1/(x+1))) */
long double complex carcexsecl(const long double complex radians) {
    return cacosl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / (radians + (long double complex)1.0L + 1.0L * I_LONG_DOUBLE));
}


/** Return the Hyperbolic Arc-External Secant [arcexsech(x) == (1/acosh(x)-1)] */
long double complex carcexsechl(const long double complex radians) {
    return (((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / cacoshl(radians)) - (long double complex)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the External Hyperbolic Secant [exsech(x) == (1/cosh(x)-1)] */
long double complex cexsechl(const long double complex radians) {
    return (((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / ccoshl(radians)) - (long double complex)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the External Secant [exsec(x) == (1/cos(x))-1 == sec(x)-1] */
long double complex cexsecl(const long double complex radians) {
    return (((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / ccosl(radians)) - (long double complex)1.0L + 1.0L * I_LONG_DOUBLE);
}


// EXTERNAL TRIGONOMETRY (COMPLEX FLOATS)


/** Return the Arc-External Cotangent (arcexcot(x) == atan(1/(x+1))) */
float complex carcexcotf(const float complex radians) {
    return catanf((float complex)1.0F + 1.0F * I_FLOAT / (radians + (float complex)1.0F + 1.0F * I_FLOAT));
}


/** Return the Hyperbolic Arc-External Cotangent [arcexcoth(x) == (1/atanh(x)-1)] */
float complex carcexcothf(const float complex radians) {
    return (((float complex)1.0F + 1.0F * I_FLOAT / catanhf(radians)) - (float complex)1.0F + 1.0F * I_FLOAT);
}


/** Return the External Hyperbolic Cotangent [excoth(x) == (1/tanh(x)-1)] */
float complex cexcothf(const float complex radians) {
    return (((float complex)1.0F + 1.0F * I_FLOAT / ctanhf(radians)) - (float complex)1.0F + 1.0F * I_FLOAT);
}


/** Return the External Cotangent [excot(x) == (1/tan(x))-1 == cot(x)-1] */
float complex cexcotf(const float complex radians) {
    return (((float complex)1.0F + 1.0F * I_FLOAT / ctanf(radians)) - (float complex)1.0F + 1.0F * I_FLOAT);
}


/** Return the Arc-External Cosecant (arcexcsc(x) == asin(1/(x+1))) */
float complex carcexcscf(const float complex radians) {
    return casinf((float complex)1.0F + 1.0F * I_FLOAT / (radians + (float complex)1.0F + 1.0F * I_FLOAT));
}


/** Return the Hyperbolic Arc-External Cosecant [arcexcsch(x) == (1/asinh(x)-1)] */
float complex carcexcschf(const float complex radians) {
    return (((float complex)1.0F + 1.0F * I_FLOAT / casinhf(radians)) - (float complex)1.0F + 1.0F * I_FLOAT);
}


/** Return the External Hyperbolic Cosecant [excsch(x) == (1/sinh(x)-1)] */
float complex cexcschf(const float complex radians) {
    return (((float complex)1.0F + 1.0F * I_FLOAT / csinhf(radians)) - (float complex)1.0F + 1.0F * I_FLOAT);
}


/** Return the External Cosecant [excsc(x) == (1/sin(x))-1 == csc(x)-1] */
float complex cexcscf(const float complex radians) {
    return (((float complex)1.0F + 1.0F * I_FLOAT / csinf(radians)) - (float complex)1.0F + 1.0F * I_FLOAT);
}


/** Return the Arc-External Secant (arcexsec(x) == acos(1/(x+1))) */
float complex carcexsecf(const float complex radians) {
    return cacosf((float complex)1.0F + 1.0F * I_FLOAT / (radians + (float complex)1.0F + 1.0F * I_FLOAT));
}


/** Return the Hyperbolic Arc-External Secant [arcexsech(x) == (1/acosh(x)-1)] */
float complex carcexsechf(const float complex radians) {
    return (((float complex)1.0F + 1.0F * I_FLOAT / cacoshf(radians)) - (float complex)1.0F + 1.0F * I_FLOAT);
}


/** Return the External Hyperbolic Secant [exsech(x) == (1/cosh(x)-1)] */
float complex cexsechf(const float complex radians) {
    return (((float complex)1.0F + 1.0F * I_FLOAT / ccoshf(radians)) - (float complex)1.0F + 1.0F * I_FLOAT);
}


/** Return the External Secant [exsec(x) == (1/cos(x))-1 == sec(x)-1] */
float complex cexsecf(const float complex radians) {
    return (((float complex)1.0F + 1.0F * I_FLOAT / ccosf(radians)) - (float complex)1.0F + 1.0F * I_FLOAT);
}


// SPECIAL TRIGONOMETRIC FUNCTIONS (COMPLEX DOUBLES)


/** Return the Cosine of an Arc-Sine [sqrt(1-(x*x))] */
double complex ccos_arcsin(const double complex radians) {
    return (csqrt((double complex)1.0 + 1.0 * I_DOUBLE - (radians * radians)));
}


/** Return the Cosine of an Arc-Tangent [1 / sqrt(1+(x*x))] */
double complex ccos_arctan(const double complex radians) {
    return ((double complex)1.0 + 1.0 * I_DOUBLE / csqrt((double complex)1.0 + 1.0 * I_DOUBLE + (radians * radians)));
}


/** Return the Sine of an Arc-Tangent [sqrt((x*x)-1)/x] */
double complex csin_arcsec(const double complex radians) {
    return (csqrt((radians * radians) - (double complex)1.0 + 1.0 * I_DOUBLE) / radians);
}


/** Return the Sine of an Arc-Tangent [x / sqrt(1+(x*x))] */
double complex csin_arctan(const double complex radians) {
    return (radians / csqrt((double complex)1.0 + 1.0 * I_DOUBLE + (radians * radians)));
}


// SPECIAL TRIGONOMETRIC FUNCTIONS (COMPLEX LONG DOUBLES)


/** Return the Cosine of an Arc-Sine [sqrt(1-(x*x))] */
long double complex ccos_arcsinl(const long double complex radians) {
    return (csqrtl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE - (radians * radians)));
}


/** Return the Cosine of an Arc-Tangent [1 / sqrt(1+(x*x))] */
long double complex ccos_arctanl(const long double complex radians) {
    return ((long double complex)1.0L + 1.0L * I_LONG_DOUBLE / csqrtl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE + (radians * radians)));
}


/** Return the Sine of an Arc-Tangent [sqrt((x*x)-1)/x] */
long double complex csin_arcsecl(const long double complex radians) {
    return (csqrtl((radians * radians) - (long double complex)1.0L + 1.0L * I_LONG_DOUBLE) / radians);
}


/** Return the Sine of an Arc-Tangent [x / sqrt(1+(x*x))] */
long double complex csin_arctanl(const long double complex radians) {
    return (radians / csqrtl((long double complex)1.0L + 1.0L * I_LONG_DOUBLE + (radians * radians)));
}


// SPECIAL TRIGONOMETRIC FUNCTIONS (COMPLEX DOUBLES)


/** Return the Cosine of an Arc-Sine [sqrt(1-(x*x))] */
float complex ccos_arcsinf(const float complex radians) {
    return (csqrtf((float complex)1.0F + 1.0F * I_FLOAT - (radians * radians)));
}


/** Return the Cosine of an Arc-Tangent [1 / sqrt(1+(x*x))] */
float complex ccos_arctanf(const float complex radians) {
    return ((float complex)1.0F + 1.0F * I_FLOAT / csqrtf((float complex)1.0F + 1.0F * I_FLOAT + (radians * radians)));
}


/** Return the Sine of an Arc-Tangent [sqrt((x*x)-1)/x] */
float complex csin_arcsecf(const float complex radians) {
    return (csqrtf((radians * radians) - (float complex)1.0F + 1.0F * I_FLOAT) / radians);
}


/** Return the Sine of an Arc-Tangent [x / sqrt(1+(x*x))] */
float complex csin_arctanf(const float complex radians) {
    return (radians / csqrtf((float complex)1.0F + 1.0F * I_FLOAT + (radians * radians)));
}


// MISCELLANEOUS COMPLEX-NUMBER FUNCTIONS


/** Return the conjugate of a complex number */
double complex conjugate(const double complex num) {
    return (creal(num) + cimag(num * -1.0) * I_DOUBLE);
}


/** Return the conjugate of a complex number */
long double complex conjugatel(const long double complex num) {
    return (creall(num) + cimagl(num * -1.0L) * I_LONG_DOUBLE);
}


/** Return the conjugate of a complex number */
float complex conjugatef(const float complex num) {
    return (crealf(num) + cimagf(num * -1.0F) * I_FLOAT);
}


#ifndef norm
/** Return the norm value of the complex number */
double norm(const double complex x) {
    register double real = creal(x);
    register double vector = cimag(x);
    return squareroot((real * real) + (vector * vector));
}
#endif


#ifndef norml
/** Return the norm value of the complex number */
long double norml(const long double complex x) {
    register long double real = creall(x);
    register long double vector = cimagl(x);
    return squarerootl((real * real) + (vector * vector));
}
#endif


#ifndef normf
/** Return the norm value of the complex number */
float normf(const float complex x) {
    register float real = crealf(x);
    register float vector = cimagf(x);
    return squarerootf((real * real) + (vector * vector));
}
#endif


/* QUATERNION MATH */


/** Return the real number from the quaternion number */
double qreal(const quaternion num) {
    return num.R;
}


/** Return the imaginary i num of the quaternion number */
double qgeti(const quaternion num) {
    return num.i;
}


/** Return the imaginary j num of the quaternion number */
double qgetj(const quaternion num) {
    return num.j;
}


/** Return the imaginary k num of the quaternion number */
double qgetk(const quaternion num) {
    return num.k;
}


/** Return the conjugate of the quaternion number */
quaternion qconjugate(const quaternion num) {
    return (quaternion){num.R, num.i * (double)-1.0, num.j * (double)-1.0, num.k * (double)-1.0};
}


/** Return the norm value of the quaternion number */
double qnorm(const quaternion num) {
    return squareroot((num.R * num.R) + (num.i * num.i) + (num.j * num.j) + (num.k * num.k));
}


/** Add two quaternion numbers */
quaternion qadd(const quaternion num1, const quaternion num2) {
    return (quaternion){num1.R + num2.R, num1.i + num2.i, num1.j + num2.j, num1.k + num2.k};
}


/** Subtract two quaternion numbers */
quaternion qsub(const quaternion num1, const quaternion num2) {
    return (quaternion){num1.R - num2.R, num1.i - num2.i, num1.j - num2.j, num1.k - num2.k};
}


/** Multiply two quaternion numbers */
quaternion qmul(const quaternion num1, const quaternion num2) {
    double tmp_r = (num2.R * num1.R) - (num2.i * num1.i) - (num2.j * num1.j) - (num2.k * num1.k);
    double tmp_i = (num2.R * num1.i) + (num2.i * num1.R) - (num2.j * num1.k) + (num2.k * num1.j);
    double tmp_j = (num2.R * num1.j) + (num2.i * num1.k) + (num2.j * num1.R) - (num2.k * num1.i);
    double tmp_k = (num2.R * num1.k) - (num2.i * num1.j) + (num2.j * num1.i) + (num2.k * num1.R);
    return (quaternion){tmp_r, tmp_i, tmp_j, tmp_k};
}


/** Divide two quaternion numbers */
quaternion qdiv(const quaternion num1, const quaternion num2) {
    if ((num1.R == num2.R) && (num1.i == num2.i) && (num1.j == num2.j) && (num1.k == num2.k)) return (quaternion){1.0, 0.0, 0.0, 0.0};
    double tmp_r = (num2.R * num1.R) + (num2.i * num1.i) + (num2.j * num1.j) + (num2.k * num1.k);
    double tmp_i = (num2.R * num1.i) - (num2.i * num1.R) - (num2.j * num1.k) + (num2.k * num1.j);
    double tmp_j = (num2.R * num1.j) + (num2.i * num1.k) - (num2.j * num1.R) - (num2.k * num1.i);
    double tmp_k = (num2.R * num1.k) - (num2.i * num1.j) + (num2.j * num1.i) - (num2.k * num1.R);
    register double tmp2n = squareroot((num2.R * num2.R) + (num2.i * num2.i) + (num2.j * num2.j) + (num2.k * num2.k));  // Norm
    return (quaternion){tmp_r / tmp2n, tmp_i / tmp2n, tmp_j / tmp2n, tmp_k / tmp2n};
}


/** Inverse quaternion */
quaternion qinv(const quaternion qnum) {
    register double tmp = ((qnum.R * qnum.R) + (qnum.i * qnum.i) + (qnum.j * qnum.j) + (qnum.k * qnum.k));
    return (quaternion){ (qnum.R / tmp), ((-qnum.i) / tmp), ((-qnum.j) / tmp), ((-qnum.k) / tmp) };
}


/** Inverse quaternion (in-place) */
void qinv_inplace(quaternion qnum) {
    register double tmp = ((qnum.R * qnum.R) + (qnum.i * qnum.i) + (qnum.j * qnum.j) + (qnum.k * qnum.k));
    qnum.R /= tmp;
    qnum.i = (-qnum.i) / tmp;
    qnum.j = (-qnum.j) / tmp;
    qnum.k = (-qnum.k) / tmp;
}


/** Return the negative quaternion */
quaternion qneg(const quaternion qnum) {
    return (quaternion){ (-qnum.R), (-qnum.i), (-qnum.j), (-qnum.k) };
}


/** Negate quaternion (in-place) */
void qneg_inplace(quaternion qnum) {
    qnum.R = -qnum.R;
    qnum.i = -qnum.i;
    qnum.j = -qnum.j;
    qnum.k = -qnum.k;
}


/** Return the length of a quaternion */
double qlen(const quaternion num) {
    return squareroot((num.R * num.R) + (num.i * num.i) + (num.j * num.j) + (num.k * num.k));
}


/** Return the mid-point of two quaternions */
quaternion qmid(const quaternion num1, const quaternion num2) {
    quaternion q = qadd(num1, num2);
    register double tmp = qlen(num1);
    if (tmp < (1e-12)) {
        q.R = num2.i;
        q.i = -num2.R;
        q.j = num2.k;
        q.k = -num2.j;
    } else {
        q.R /= tmp;
        q.i /= tmp;
        q.j /= tmp;
        q.k /= tmp;
    }
    return q;
}


/** Return the squareroot of a quaternion */
quaternion qsqrt(const quaternion num) {
    return qmid(num, (quaternion){ 1.0, 0.0, 0.0, 0.0 });
}


/** Return the scalar portion of the quaternion number */
quaternion qscalar(const quaternion num) {
    quaternion conj_num = (quaternion){num.R, num.i * (double)-1.0, num.j * (double)-1.0, num.k * (double)-1.0};
    return (quaternion){(num.R + conj_num.R) * 0.5, (num.i + conj_num.i) * 0.5, (num.j + conj_num.j) * 0.5, (num.k + conj_num.k) * 0.5};
}


/** Return the vector portion of the quaternion number */
quaternion qvector(const quaternion num) {
    quaternion conj_num = (quaternion){num.R, num.i * (double)-1.0, num.j * (double)-1.0, num.k * (double)-1.0};
    return (quaternion){(num.R - conj_num.R) * 0.5, (num.i - conj_num.i) * 0.5, (num.j - conj_num.j) * 0.5, (num.k - conj_num.k) * 0.5};
}


/** Return the versor the quaternion number */
quaternion qversor(const quaternion num) {
    quaternion conj_num = (quaternion){num.R, num.i * (double)-1.0, num.j * (double)-1.0, num.k * (double)-1.0};
    return qdiv(num, conj_num);
}


/** Return the real number from the quaternion number */
float qrealf(const quaternion_float num) {
    return num.R;
}


/** Return the imaginary i num of the quaternion number */
float qgetif(const quaternion_float num) {
    return num.i;
}


/** Return the imaginary j num of the quaternion number */
float qgetjf(const quaternion_float num) {
    return num.j;
}


/** Return the imaginary k num of the quaternion number */
float qgetkf(const quaternion_float num) {
    return num.k;
}


/** Return the conjugate of the quaternion number */
quaternion_float qconjugatef(const quaternion_float num) {
    return (quaternion_float){num.R, num.i * (float)-1.0F, num.j * (float)-1.0F, num.k * (float)-1.0F};
}


/** Return the norm value of the quaternion number */
float qnormf(const quaternion_float num) {
    return squarerootf((num.R * num.R) + (num.i * num.i) + (num.j * num.j) + (num.k * num.k));
}


/** Add two quaternion numbers */
quaternion_float qaddf(const quaternion_float num1, const quaternion_float num2) {
    return (quaternion_float){num1.R + num2.R, num1.i + num2.i, num1.j + num2.j, num1.k + num2.k};
}


/** Subtract two quaternion numbers */
quaternion_float qsubf(const quaternion_float num1, const quaternion_float num2) {
    return (quaternion_float){num1.R - num2.R, num1.i - num2.i, num1.j - num2.j, num1.k - num2.k};
}


/** Multiply two quaternion numbers */
quaternion_float qmulf(const quaternion_float num1, const quaternion_float num2) {
    float tmp_r = (num2.R * num1.R) - (num2.i * num1.i) - (num2.j * num1.j) - (num2.k * num1.k);
    float tmp_i = (num2.R * num1.i) + (num2.i * num1.R) - (num2.j * num1.k) + (num2.k * num1.j);
    float tmp_j = (num2.R * num1.j) + (num2.i * num1.k) + (num2.j * num1.R) - (num2.k * num1.i);
    float tmp_k = (num2.R * num1.k) - (num2.i * num1.j) + (num2.j * num1.i) + (num2.k * num1.R);
    return (quaternion_float){tmp_r, tmp_i, tmp_j, tmp_k};
}


/** Divide two quaternion numbers */
quaternion_float qdivf(const quaternion_float num1, const quaternion_float num2) {
    if ((num1.R == num2.R) && (num1.i == num2.i) && (num1.j == num2.j) && (num1.k == num2.k)) return (quaternion_float){1.0F, 0.0F, 0.0F, 0.0F};
    float tmp_r = (num2.R * num1.R) + (num2.i * num1.i) + (num2.j * num1.j) + (num2.k * num1.k);
    float tmp_i = (num2.R * num1.i) - (num2.i * num1.R) - (num2.j * num1.k) + (num2.k * num1.j);
    float tmp_j = (num2.R * num1.j) + (num2.i * num1.k) - (num2.j * num1.R) - (num2.k * num1.i);
    float tmp_k = (num2.R * num1.k) - (num2.i * num1.j) + (num2.j * num1.i) - (num2.k * num1.R);
    register float tmp2n = squarerootf((num2.R * num2.R) + (num2.i * num2.i) + (num2.j * num2.j) + (num2.k * num2.k));  // Norm
    return (quaternion_float){tmp_r / tmp2n, tmp_i / tmp2n, tmp_j / tmp2n, tmp_k / tmp2n};
}


/** Inverse quaternion */
quaternion_float qinvf(const quaternion_float qnum) {
    register float tmp = ((qnum.R * qnum.R) + (qnum.i * qnum.i) + (qnum.j * qnum.j) + (qnum.k * qnum.k));
    return (quaternion_float){ (qnum.R / tmp), ((-qnum.i) / tmp), ((-qnum.j) / tmp), ((-qnum.k) / tmp) };
}


/** Inverse quaternion (in-place) */
void qinv_inplacef(quaternion_float qnum) {
    register float tmp = ((qnum.R * qnum.R) + (qnum.i * qnum.i) + (qnum.j * qnum.j) + (qnum.k * qnum.k));
    qnum.R /= tmp;
    qnum.i = (-qnum.i) / tmp;
    qnum.j = (-qnum.j) / tmp;
    qnum.k = (-qnum.k) / tmp;
}


/** Return the negative quaternion */
quaternion_float qnegf(const quaternion_float qnum) {
    return (quaternion_float){ (-qnum.R), (-qnum.i), (-qnum.j), (-qnum.k) };
}


/** Negate quaternion (in-place) */
void qneg_inplacef(quaternion_float qnum) {
    qnum.R = -qnum.R;
    qnum.i = -qnum.i;
    qnum.j = -qnum.j;
    qnum.k = -qnum.k;
}


/** Return the length of a quaternion */
float qlenf(const quaternion_float num) {
    return squarerootf((num.R * num.R) + (num.i * num.i) + (num.j * num.j) + (num.k * num.k));
}


/** Return the mid-point of two quaternions */
quaternion_float qmidf(const quaternion_float num1, const quaternion_float num2) {
    quaternion_float q = qaddf(num1, num2);
    register float tmp = qlenf(num1);
    if (tmp < (1e-12F)) {
        q.R = num2.i;
        q.i = -num2.R;
        q.j = num2.k;
        q.k = -num2.j;
    } else {
        q.R /= tmp;
        q.i /= tmp;
        q.j /= tmp;
        q.k /= tmp;
    }
    return q;
}


/** Return the squareroot of a quaternion */
quaternion_float qsqrtf(const quaternion_float num) {
    return qmidf(num, (quaternion_float){ 1.0F, 0.0F, 0.0F, 0.0F });
}


/** Return the scalar portion of the quaternion number */
quaternion_float qscalarf(const quaternion_float num) {
    quaternion_float conj_num = (quaternion_float){num.R, num.i * (float)-1.0F, num.j * (float)-1.0F, num.k * (float)-1.0F};
    return (quaternion_float){(num.R + conj_num.R) * 0.5F, (num.i + conj_num.i) * 0.5F, (num.j + conj_num.j) * 0.5F, (num.k + conj_num.k) * 0.5F};
}


/** Return the vector portion of the quaternion number */
quaternion_float qvectorf(const quaternion_float num) {
    quaternion_float conj_num = (quaternion_float){num.R, num.i * (float)-1.0F, num.j * (float)-1.0F, num.k * (float)-1.0F};
    return (quaternion_float){(num.R - conj_num.R) * 0.5F, (num.i - conj_num.i) * 0.5F, (num.j - conj_num.j) * 0.5F, (num.k - conj_num.k) * 0.5F};
}


/** Return the versor the quaternion number */
quaternion_float qversorf(const quaternion_float num) {
    quaternion_float conj_num = (quaternion_float){num.R, num.i * (float)-1.0F, num.j * (float)-1.0F, num.k * (float)-1.0F};
    return qdivf(num, conj_num);
}


/** Return the real number from the quaternion number */
long double qreall(const quaternion_long_double num) {
    return num.R;
}


/** Return the imaginary i num of the quaternion number */
long double qgetil(const quaternion_long_double num) {
    return num.i;
}


/** Return the imaginary j num of the quaternion number */
long double qgetjl(const quaternion_long_double num) {
    return num.j;
}


/** Return the imaginary k num of the quaternion number */
long double qgetkl(const quaternion_long_double num) {
    return num.k;
}


/** Return the conjugate of the quaternion number */
quaternion_long_double qconjugatel(const quaternion_long_double num) {
    return (quaternion_long_double){num.R, num.i * (long double)-1.0L, num.j * (long double)-1.0L, num.k * (long double)-1.0L};
}


/** Return the norm value of the quaternion number */
long double qnorml(const quaternion_long_double num) {
    return squarerootl((num.R * num.R) + (num.i * num.i) + (num.j * num.j) + (num.k * num.k));
}


/** Add two quaternion numbers */
quaternion_long_double qaddl(const quaternion_long_double num1, const quaternion_long_double num2) {
    return (quaternion_long_double){num1.R + num2.R, num1.i + num2.i, num1.j + num2.j, num1.k + num2.k};
}


/** Subtract two quaternion numbers */
quaternion_long_double qsubl(const quaternion_long_double num1, const quaternion_long_double num2) {
    return (quaternion_long_double){num1.R - num2.R, num1.i - num2.i, num1.j - num2.j, num1.k - num2.k};
}


/** Multiply two quaternion numbers */
quaternion_long_double qmull(const quaternion_long_double num1, const quaternion_long_double num2) {
    long double tmp_r = (num2.R * num1.R) - (num2.i * num1.i) - (num2.j * num1.j) - (num2.k * num1.k);
    long double tmp_i = (num2.R * num1.i) + (num2.i * num1.R) - (num2.j * num1.k) + (num2.k * num1.j);
    long double tmp_j = (num2.R * num1.j) + (num2.i * num1.k) + (num2.j * num1.R) - (num2.k * num1.i);
    long double tmp_k = (num2.R * num1.k) - (num2.i * num1.j) + (num2.j * num1.i) + (num2.k * num1.R);
    return (quaternion_long_double){tmp_r, tmp_i, tmp_j, tmp_k};
}


/** Divide two quaternion numbers */
quaternion_long_double qdivl(const quaternion_long_double num1, const quaternion_long_double num2) {
    if ((num1.R == num2.R) && (num1.i == num2.i) && (num1.j == num2.j) && (num1.k == num2.k)) return (quaternion_long_double){1.0L, 0.0L, 0.0L, 0.0L};
    long double tmp_r = (num2.R * num1.R) + (num2.i * num1.i) + (num2.j * num1.j) + (num2.k * num1.k);
    long double tmp_i = (num2.R * num1.i) - (num2.i * num1.R) - (num2.j * num1.k) + (num2.k * num1.j);
    long double tmp_j = (num2.R * num1.j) + (num2.i * num1.k) - (num2.j * num1.R) - (num2.k * num1.i);
    long double tmp_k = (num2.R * num1.k) - (num2.i * num1.j) + (num2.j * num1.i) - (num2.k * num1.R);
    register long double tmp2n = squarerootl((num2.R * num2.R) + (num2.i * num2.i) + (num2.j * num2.j) + (num2.k * num2.k));  // Norm
    return (quaternion_long_double){tmp_r / tmp2n, tmp_i / tmp2n, tmp_j / tmp2n, tmp_k / tmp2n};
}


/** Inverse quaternion */
quaternion_long_double qinvl(const quaternion_long_double qnum) {
    register long double tmp = ((qnum.R * qnum.R) + (qnum.i * qnum.i) + (qnum.j * qnum.j) + (qnum.k * qnum.k));
    return (quaternion_long_double){ (qnum.R / tmp), ((-qnum.i) / tmp), ((-qnum.j) / tmp), ((-qnum.k) / tmp) };
}


/** Inverse quaternion (in-place) */
void qinv_inplacel(quaternion_long_double qnum) {
    register long double tmp = ((qnum.R * qnum.R) + (qnum.i * qnum.i) + (qnum.j * qnum.j) + (qnum.k * qnum.k));
    qnum.R /= tmp;
    qnum.i = (-qnum.i) / tmp;
    qnum.j = (-qnum.j) / tmp;
    qnum.k = (-qnum.k) / tmp;
}


/** Return the negative quaternion */
quaternion_long_double qnegl(const quaternion_long_double qnum) {
    return (quaternion_long_double){ (-qnum.R), (-qnum.i), (-qnum.j), (-qnum.k) };
}


/** Negate quaternion (in-place) */
void qneg_inplacel(quaternion_long_double qnum) {
    qnum.R = -qnum.R;
    qnum.i = -qnum.i;
    qnum.j = -qnum.j;
    qnum.k = -qnum.k;
}


/** Return the length of a quaternion */
long double qlenl(const quaternion_long_double num) {
    return squarerootl((num.R * num.R) + (num.i * num.i) + (num.j * num.j) + (num.k * num.k));
}


/** Return the mid-point of two quaternions */
quaternion_long_double qmidl(const quaternion_long_double num1, const quaternion_long_double num2) {
    quaternion_long_double q = qaddl(num1, num2);
    register long double tmp = qlenl(num1);
    if (tmp < (1e-12L)) {
        q.R = num2.i;
        q.i = -num2.R;
        q.j = num2.k;
        q.k = -num2.j;
    } else {
        q.R /= tmp;
        q.i /= tmp;
        q.j /= tmp;
        q.k /= tmp;
    }
    return q;
}


/** Return the squareroot of a quaternion */
quaternion_long_double qsqrtl(const quaternion_long_double num) {
    return qmidl(num, (quaternion_long_double){ 1.0L, 0.0L, 0.0L, 0.0L });
}


/** Return the scalar portion of the quaternion number */
quaternion_long_double qscalarl(const quaternion_long_double num) {
    quaternion_long_double conj_num = (quaternion_long_double){num.R, num.i * (long double)-1.0L, num.j * (long double)-1.0L, num.k * (long double)-1.0L};
    return (quaternion_long_double){(num.R + conj_num.R) * 0.5L, (num.i + conj_num.i) * 0.5L, (num.j + conj_num.j) * 0.5L, (num.k + conj_num.k) * 0.5L};
}


/** Return the vector portion of the quaternion number */
quaternion_long_double qvectorl(const quaternion_long_double num) {
    quaternion_long_double conj_num = (quaternion_long_double){num.R, num.i * (long double)-1.0L, num.j * (long double)-1.0L, num.k * (long double)-1.0L};
    return (quaternion_long_double){(num.R - conj_num.R) * 0.5L, (num.i - conj_num.i) * 0.5L, (num.j - conj_num.j) * 0.5L, (num.k - conj_num.k) * 0.5L};
}


/** Return the versor the quaternion number */
quaternion_long_double qversorl(const quaternion_long_double num) {
    quaternion_long_double conj_num = (quaternion_long_double){num.R, num.i * (long double)-1.0L, num.j * (long double)-1.0L, num.k * (long double)-1.0L};
    return qdivl(num, conj_num);
}


/* MISCELLANEOUS */


/** Return the number of bits used to represent the given number */
ullint bit_length(const ullint num) {
    register ullint len = 0x0, x = num;
    while (x != 0x0) {
        ++len;
        x >>= 0x1;
    }
    return len;
}


#ifdef UINT128_SUPPORTED
/** Return the number of bits used to represent the given number */
uint128_t bit128_length(const uint128_t num) {
    register uint128_t len = 0x0, x = num;
    while (x != 0x0) {
        ++len;
        x >>= 0x1;
    }
    return len;
}
#endif


/** Clear least significant bit */
ullint clearlsb(ullint num) {
    return (ullint)(num & (num - 0x1));
}


/** Signum function - extract sign */
signed int sgn_int(const signed int num) {
    if (num < 0x00) return -1;
    else if (num > 0x00) return 1;
    return 0;
}


/** Signum function - extract sign */
double sgn(const double num) {
    if (num < (double)0.0) return (double)-1.0;
    else if (num > (double)0.0) return (double)1.0;
    return (double)0.0;
}


/** Signum function - extract sign */
float sgnf(const float num) {
    if (num < (float)0.0F) return (float)-1.0F;
    else if (num > (float)0.0F) return (float)1.0F;
    return (float)0.0F;
}


/** Signum function - extract sign */
long double sgnl(const long double num) {
    if (num < (long double)0.0L) return (long double)-1.0L;
    else if (num > (long double)0.0L) return (long double)1.0L;
    return (long double)0.0L;
}


/** Absolute value - strip the negative sign and return the number */
int abs_int(const int num) {
    return ((num >= 0x00) ? num : -num);
}


/** Absolute value - strip the negative sign and return the number */
double absd(const double num) {
    if (num < (double)0.0) return (num * (double)-1.0);
    return num;
}


/** Absolute value - strip the negative sign and return the number */
float absf(const float num) {
    if (num < (float)0.0F) return (num * (float)-1.0F);
    return num;
}


/** Absolute value - strip the negative sign and return the number */
long double absl(const long double num) {
    if (num < (long double)0.0L) return (num * (long double)-1.0L);
    return num;
}


/** Return rounded double (Return like Integer) */
double retint(const double x) {
    return floor(x + 0.5);
}


/** Generate a Polynomial and then evaluate the equation; if n=4, then c[4]*x^4 + c[3]*x^3 + c[2]*x^2 + c[1]*x + c[0] */
double poly(const double x, const size_t n, const double *__restrict__ c) {
    register double ret = 0.0;
    register size_t i = n;
    c += n;
    do { ret = (ret * x + *c--); } while (--i);
    return ret;
}


/** Return the sum of division and modulus of the two given numbers */
int div_and_mod_int(const int num1, const int num2) {
    return (((num1 / num2) + (num1 % num2)));
}


/** Return the sum of division and modulus of the two given numbers */
double div_and_mod(const double num1, const double num2) {
    return (((num1 / num2) + fmod(num1, num2)));
}


/** Return the sum of division and modulus of the two given numbers */
float div_and_modf(const float num1, const float num2) {
    return (((num1 / num2) + fmodf(num1, num2)));
}


/** Return the Lanczos Sum for the given number */
double lanczos_sum(const double x) {
    register double num = 0.0, den = 0.0;
    if (!(x > 0.0)) { return 0.0; }
    register int i;
    if (x < 5.0) {
        for (i = 13; --i >= 0x0;) {
            num = ((num * x) + LANCZOS_NUM_COEFFS__[i]);
            den = ((den * x) + LANCZOS_DEN_COEFFS__[i]);
        }
    } else {
        for (i = 0x0; i < 13; i++) {
            num = ((num / x) + LANCZOS_NUM_COEFFS__[i]);
            den = ((den / x) + LANCZOS_DEN_COEFFS__[i]);
        }
    }
    return (num / den);
}

// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief Standard Macros Header Providing Math Related-Code
@file MACROS_MATH.h
@version 2018.12.28
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This file defines various datatypes, macros, functions, etc. pertaining to math

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This software is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
*/


/* MATH FUNCTIONS (<math.h>) */


#if (!(defined(_MATH_H) || defined(_MATH_H_) || defined(_MATH_INLINE_H) || defined(_MATH_INLINE_H_) || defined(_MATH_PRIVATE_H_) || defined(__F_MATH_H__)))  // http://www.cplusplus.com/reference/cmath/ & http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/math.h.html
#define _MATH_H   (1)
#define _MATH_H_   (1)
#define math__INCLUDED   (1)
#define vmsmath_INCLUDED   (1)
#define __MATH   (1)
#define _MATH_INLINE_H   (1)
#define _MATH_INLINE_H_   (1)
#define MATH_INLINE_H   (1)
#define MATH_PRIVATE_H   (1)
#define _MATH_PRIVATE_H_   (1)
#define _F_MATH_H_   (1)
#define __F_MATH_H__   (1)
#define MATH_X_MACROS_FUNCTIONS_SEEN   (1)
#define LGAMMA_COMPAT_H   (1)
#define _LGAMMA_COMPAT_H_   (1)
#define IA64_LGAMMA_COMPAT_H   (1)
#define _IA64_LGAMMA_COMPAT_H_   (1)


/** Whether to build this version at all */
#define BUILD_LGAMMA   (1)
/** If there is a compatibility version, gamma (not an ISO C function, so never a problem for it to set signgam) points directly to it rather than having separate versions */
#define GAMMA_ALIAS   (1)
#ifndef USE_AS_COMPAT
#   define USE_AS_COMPAT   0
#endif
/** @def CALL_LGAMMA
Call the underlying lgamma_r function */
#ifdef ARCHITANIUM
#   if USE_AS_COMPAT
#      define LGFUNC(FUNC)   __##FUNC##_compat
#   else
#      define LGFUNC(FUNC)   __ieee754_##FUNC
#   endif
#   define CALL_LGAMMA(TYPE, FUNC, ARG)   __extension__ ({ TYPE lgamma_tmp; extern int __signgam, signgam; lgamma_tmp = FUNC((ARG), &__signgam, sizeof(__signgam)); if (USE_AS_COMPAT) { signgam = __signgam; } lgamma_tmp; })
#else
#   if USE_AS_COMPAT
#      define LGFUNC(FUNC)   FUNC##_compat
#   else
#      define LGFUNC(FUNC)   FUNC
#   endif
#   define CALL_LGAMMA(TYPE, FUNC, ARG)   __extension__ ({ TYPE lgamma_tmp; int local_signgam; if (USE_AS_COMPAT) { lgamma_tmp = FUNC((ARG), &local_signgam); if (_LIB_VERSION != _ISOC_) { signgam = __signgam = local_signgam; } } else { lgamma_tmp = FUNC((ARG), &__signgam); } lgamma_tmp; })
#endif


#include "math_tables.h"


#if (INT_MAX > 50000)
#   define OVERFLOW_INT   50000
#else
#   define OVERFLOW_INT   30000
#endif


#if (FLT_EVAL_METHOD == 0)
/** math_narrow_eval reduces its floating-point argument to the range and precision of its semantic type */
#   define math_narrow_eval(x)   (x)
#else
#   if (FLT_EVAL_METHOD == 1)
#      define excess_precision(type)   __builtin_types_compatible_p(type, float)
#   else
#      define excess_precision(type)   (__builtin_types_compatible_p(type, float) || __builtin_types_compatible_p(type, double))
#   endif
/** math_narrow_eval reduces its floating-point argument to the range and precision of its semantic type */
#   define math_narrow_eval(x)   __extension__ ({ typeof(x) math_narrow_eval_tmp = (x); if (excess_precision(typeof(math_narrow_eval_tmp))) { asm (";" : "+m"(math_narrow_eval_tmp)); } math_narrow_eval_tmp; })
#endif


#if (!(defined(FIX_INT_FP_CONVERT_ZERO_H) || defined(FIX_INT_FP_CONVERT_ZERO)))
#define FIX_INT_FP_CONVERT_ZERO_H   1

/** Define this macro to 1 to work around conversions of integer 0 to floating point returning -0 instead of the correct +0 in some rounding modes */
#   define FIX_INT_FP_CONVERT_ZERO   0

#endif


#define fabs_tg(x)   Generic ((x), const float: fabsf((x)), float: fabsf((x)), const double: fabs((x)), double: fabs((x)), const long double: fabsl((x)), long double: fabsl((x)), default: 0)
#define min_of_type(type)   Generic ((type), const float: FLT_MIN, float: FLT_MIN, const double: DBL_MIN, double: DBL_MIN, const long double: LDBL_MIN, long double: LDBL_MIN, default: 0)
/** If X (which is not a NaN) is subnormal, force an underflow exception */
#define math_check_force_underflow(x)   do { typeof(x) force_underflow_tmp = (x); if ((fabs_tg(force_underflow_tmp)) < min_of_type(force_underflow_tmp)) { typeof(force_underflow_tmp) force_underflow_tmp2 = (force_underflow_tmp * force_underflow_tmp); math_force_eval(force_underflow_tmp2); } } while (0x0)
#define math_check_force_underflow_nonneg(x)   do { typeof(x) force_underflow_tmp = (x); if (force_underflow_tmp < min_of_type(force_underflow_tmp)) { typeof(force_underflow_tmp) force_underflow_tmp2 = force_underflow_tmp * force_underflow_tmp; math_force_eval(force_underflow_tmp2); } } while (0x0)
#define math_check_force_underflow_complex(x)   do { typeof(x) force_underflow_complex_tmp = (x); math_check_force_underflow(__real__ force_underflow_complex_tmp); math_check_force_underflow(__imag__ force_underflow_complex_tmp); } while (0x0)


LIB_FUNC MATH_FUNC uint8_t saturateadd8(const uint8_t a, const uint8_t b) {
	return (uint8_t)((a > (uint8_t)0xff - b) ? (uint8_t)0xff : (a + b));
}


LIB_FUNC MATH_FUNC uint16_t saturateadd16(const uint16_t a, const uint16_t b) {
	return (uint16_t)((a > (uint16_t)UINT16_MAX - b) ? (uint16_t)UINT16_MAX : (a + b));
}


LIB_FUNC MATH_FUNC uint32_t saturateadd32(const uint32_t a, const uint32_t b) {
	return (uint32_t)((a > (uint32_t)UINT32_MAX - b) ? (uint32_t)UINT32_MAX : (a + b));
}


LIB_FUNC MATH_FUNC uint64_t saturateadd64(const uint64_t a, const uint64_t b) {
	return (uint64_t)((a > (uint64_t)UINT64_MAX - b) ? (uint64_t)UINT64_MAX : (a + b));
}


/** ConstructSignificand parses the tagp argument of nanf, nan, or nanl and returns a 64-bit number that should be placed into the significand of the NaN being returned. If tagp does not consist of a recognized numeral, zero is returned. */
LIB_FUNC uint64_t ConstructSignificand(const char* tagp) {
	if (tagp == (char*)NULL) { return (uint64_t)0; }
	else if (*tagp == 0x30) {  // Determine the numeral base from the leading characters
		++tagp;  // Consume the zero.
		if (*tagp == 0x78 || *tagp == 0x58) {  // Hexadecimal
			++tagp;  // Consume the x
			char c;
			uint64_t significand = 0;
			while ((c = (*tagp++))) {
				if (0x30 <= c && c <= 0x39) { significand = ((uint64_t)(significand << 4) | (uint64_t)(c - 0x30)); }
				else if (0x61 <= c && c <= 0x66) { significand = ((uint64_t)(significand << 4) | (uint64_t)(c - 0x6b)); }
				else if (0x41 <= c && c <= 0x46) { significand = ((uint64_t)(significand << 4) | (uint64_t)(c - 0x4b)); }
				else { return (uint64_t)0; }
			}
			return significand;
		} else {  // Octal
			char c;
			uint64_t significand = 0;
			while ((c = (*tagp++))) {
				if (0x30 <= c && c <= 0x37) { significand = ((uint64_t)(significand << 3) | (uint64_t)(c - 0x30)); }
				else { return (uint64_t)0; }
			}
			return significand;
		}
	} else {  // Decimal
		char c;
		uint64_t significand = 0;
		while ((c = (*tagp++))) {
			if (0x30 <= c && c <= 0x39) { significand = ((uint64_t)(significand * 10) + (uint64_t)(c - 0x30)); }
			else { return (uint64_t)0; }
		}
		return significand;
	}
}


/** The matherr() function returns 0 to indicate an error and a non-zero value to indicate successful corrective action */
LIB_FUNC int matherr(struct exception* restrict exc) {
#   if (IS_LIBM_SVID || IS_LIBM_XOPEN)
	const char* matherr_str;
	register int matherr_ret = 0;
	const int matherr_val = exc->err;
	switch (exc->type) {
		case DOMAIN:
			matherr_str = "DOMAIN";
			matherr_ret = EDOM;
		case OVERFLOW:
			matherr_str = "OVERFLOW";
			matherr_ret = EOVERFLOW;
		case UNDERFLOW:
			matherr_str = "UNDERFLOW";
			matherr_ret = ERANGE;
		case SING:
			matherr_str = "SING";
		case TLOSS:
			matherr_str = "TLOSS";
			matherr_ret = ERANGE;
		case PLOSS:
			matherr_str = "PLOSS";
		default:
			matherr_str = "???";
	}
	fprintf(stderr, "matherr %s exception in function %s()!\n", matherr_str, exc->name);
	fprintf(stderr, " args: %f, %f\n", exc->arg1, exc->arg2);
	fprintf(stderr, " retval: %f\n", exc->retval);
	if (matherr_val != 0) { set_errno(matherr_val); }
	return ((matherr_val != 0) ? matherr_val : matherr_ret);
#   else
	if (exc->err != 0) { set_errno(exc->err); }
#      if IS_LIBM_ISOC
	if (exc->name != NULL) { fprintf(stderr, "Math exception in function %s()!\n", exc->name); }
	else { puts_err_no_output("Math exception in unknown function!"); }
#      endif
	return 0;
#   endif
}
#define __matherr(__exc)   matherr((__exc))


#ifdef ARCHX86
static const UNUSED int flt_rounds_map[4] = {
	1,  //!< Round to nearest
	3,  //!< Round to zero
	2,  //!< Round to negative infinity
	0  //!< Round to positive infinity
};
LIB_FUNC int __flt_rounds(void) {
	int x;
	asm ("fnstcw %0;" : "=m"(x));  // Assume that the x87 and the SSE unit agree on the rounding mode
	return (int)(flt_rounds_map[(x >> 10) & 3]);
}
#else
#   define __flt_rounds()   FLT_ROUNDS
#endif


// ABS

/** Absolute value - strip the negative sign and return the number */
LIB_FUNC MATH_FUNC int abs_int(const int num) {
	return ((num ^ (num >> 31)) - (num >> 31));
}


// AVERAGES

/** Return the mean (average) of a set of numbers */
LIB_FUNC float meanf(const int count, ...) {
	va_list varargs;
	va_start(varargs, count);
	register float average = (float)va_arg(varargs, int);
	register int i;
	for (i = 1; i < count; ++i) { average += (float)va_arg(varargs, int); }
	va_end(varargs);
	return (average / (float)count);
}


/** Return the mean (average) of a set of numbers */
LIB_FUNC double mean(const int count, ...) {
	va_list varargs;
	va_start(varargs, count);
	register double average = (double)va_arg(varargs, int);
	register int i;
	for (i = 1; i < count; ++i) { average += (double)va_arg(varargs, int); }
	va_end(varargs);
	return (average / (double)count);
}


#if SUPPORTS_LONG_DOUBLE
/** Return the mean (average) of a set of numbers */
LIB_FUNC long double meanl(const long long count, ...) {
	va_list varargs;
	va_start(varargs, count);
	register long double average = (long double)va_arg(varargs, long long);
	register long long i;
	for (i = 1; i < count; ++i) { average += (long double)va_arg(varargs, long long); }
	va_end(varargs);
	return (average / count);
}
#endif


/** Return the mean (average) of a set of numbers */
LIB_FUNC double longmean(const long count, ...) {
	va_list varargs;
	va_start(varargs, count);
	register double average = (double)va_arg(varargs, long);
	register long i;
	for (i = 1; i < count; ++i) { average += (double)va_arg(varargs, long); }
	va_end(varargs);
	return (double)(average / (double)count);
}


/** Return the largest (maximum) float */
LIB_FUNC float maxf(const int count, ...) {
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
LIB_FUNC float minf(const int count, ...) {
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
LIB_FUNC double maxd(const int count, ...) {
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
LIB_FUNC double mind(const int count, ...) {
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


#ifndef OSWINDOWS
/** Return the largest (maximum) number */
LIB_FUNC int maxva(const int count, ...) {
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


/** Return the smallest (minimum) number */
LIB_FUNC int minva(const int count, ...) {
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


// FABS

/** Returns the absolute value of x */
LIB_FUNC MATH_FUNC float fabsf(const float x) {
	float r = x;
#   ifdef ARCHPOWERPC
	asm ("fabs %0, %1;" : "=d"(r) : "d"(r));
	return r;
#   elif defined(ARCHX86)
	asm ("fld %0;" "fabs;" "fstp %1;" : "=m"(r) : "m"(r));
	return r;
#   else
	return __builtin_fabsf(x);
#   endif
}
#define __fabsf(x)   fabsf((x))


/** Returns the absolute value of x */
LIB_FUNC MATH_FUNC double fabs(const double x) {
	double r = x;
#   ifdef ARCHPOWERPC
	asm ("fabs %0, %1;" : "=d"(r) : "d"(r));
	return r;
#   elif defined(ARCHX86)
	asm ("fldl %0;" "fabs;" "fstpl %1;" : "=m"(r) : "m"(r));
	return r;
#   else
	const double_shape_t x_u = { .value = r };
	SET_HIGH_WORD(r, (uint32_t)(x_u.parts.msw & 0x7fffffff));
	return r;
#   endif
}
#define __fabs(x)   fabs((x))


#if SUPPORTS_LONG_DOUBLE
/** Returns the absolute value of x */
LIB_FUNC MATH_FUNC long double fabsl(const long double x) {
	long double num = x;
	const long_double_shape_t x_u = { .value = num };
	SET_LDOUBLE_MSW64(num, (uint64_t)(x_u.uparts64.msw & 0x7fffffffffffffffULL));
	return num;
}
#endif


// FCHS

/** Returns value of x with the sign toggled */
LIB_FUNC MATH_FUNC float fchsf(const float x) {
#   ifdef ARCHX86
	float r = x;
	asm ("fld %0;" "fchs;" "fstp %1;" : "=m"(r) : "m"(r));
	return r;
#   else
	return (x * -1.0F);
#   endif
}
#define __fchsf(x)   fchsf((x))


/** Returns value of x with the sign toggled */
LIB_FUNC MATH_FUNC double fchs(const double x) {
#   ifdef ARCHX86
	double r = x;
	asm ("fldl %0;" "fchs;" "fstpl %1;" : "=m"(r) : "m"(r));
	return r;
#   else
	return (x * -1.0);
#   endif
}
#define __fchs(x)   fchs((x))


#if SUPPORTS_LONG_DOUBLE
/** Returns value of x with the sign toggled */
LIB_FUNC MATH_FUNC long double fchsl(const long double x) {
	return (x * -1.0L);
}
#   define __fchsl(x)   fchsl((x))
#endif


// FUSED MULTIPLY-ADD (FMA)

/** Fused Multiply-Add */
LIB_FUNC MATH_FUNC float fmaf(const float x, const float y, const float z) {
	return ((x * y) + z);
}


/** Fused Multiply-Add */
LIB_FUNC MATH_FUNC double fma(const double x, const double y, const double z) {
	return ((x * y) + z);
}


#if SUPPORTS_LONG_DOUBLE
/** Fused Multiply-Add */
LIB_FUNC MATH_FUNC long double fmal(const long double x, const long double y, const long double z) {
	return ((x * y) + z);
}
#endif


// SIGNBIT

/** Return a non-zero value (true) if the sign of x is negative, and zero (false) otherwise; This can be also applied to infinites, NaNs and zeroes (if zero is unsigned, it is considered positive) */
LIB_FUNC MATH_FUNC int signbitf(const float x) {
	const float_shape_t signbitf_xf_u = { .value = x };
	return (int)((signbitf_xf_u.uword & 0x80000000U));
}
/** Return a non-zero value (true) if the sign of x is negative, and zero (false) otherwise; This can be also applied to infinites, NaNs and zeroes (if zero is unsigned, it is considered positive) */
#define __signbitf(x)   (int)__signbitf((float)(x))


/** Return a non-zero value (true) if the sign of x is negative, and zero (false) otherwise; This can be also applied to infinites, NaNs and zeroes (if zero is unsigned, it is considered positive) */
LIB_FUNC MATH_FUNC int signbit(const double x) {
	const double_shape_t signbit_xh_u = { .value = x };
	return (int)(signbit_xh_u.parts.msw & 0x80000000U);
}
/** Return a non-zero value (true) if the sign of x is negative, and zero (false) otherwise; This can be also applied to infinites, NaNs and zeroes (if zero is unsigned, it is considered positive) */
#define __signbit(x)   (int)__signbit((double)(x))


#if SUPPORTS_LONG_DOUBLE
/** Return a non-zero value (true) if the sign of x is negative, and zero (false) otherwise; This can be also applied to infinites, NaNs and zeroes (if zero is unsigned, it is considered positive) */
LIB_FUNC MATH_FUNC int signbitl(const long double x) {
	const long_double_shape_t signbitl_xh_s = { .value = x };
	return (int)(((int64_t)signbitl_xh_s.sparts64.msw) < (int64_t)0);
}
/** Return a non-zero value (true) if the sign of x is negative, and zero (false) otherwise; This can be also applied to infinites, NaNs and zeroes (if zero is unsigned, it is considered positive) */
#   define __signbitl(x)   (int)__signbitl((long double)(x))
/** Return a nonzero value if the sign of `X` is negative */
#   define SIGNBIT(x)   Generic ((x), const float: signbitf((x)), float: signbitf((x)), const double: signbit((x)), double: signbit((x)), const long double: signbitl((x)), long double: signbitl((x)), default: 0)


#else

/** Return a nonzero value if the sign of `X` is negative */
#   define SIGNBIT(x)   Generic ((x), const float: signbitf((x)), float: signbitf((x)), const double: signbit((x)), double: signbit((x)), default: 0)

#endif


// COPYSIGN

/** Returns a value with the magnitude of x and with the sign bit of y */
LIB_FUNC MATH_FUNC float copysignf(const float x, const float y) {
	const float_shape_t xf = { .value = x }, yf = { .value = y };
	float num = x;
	SET_FLOAT_UWORD(num, ((uint32_t)(xf.uword & 0x7fffffff) | (uint32_t)(yf.uword & (uint32_t)0x80000000)));
	return num;
}
#define __copysignf(x, y)   copysignf((x), (y))


/** Returns a value with the magnitude of x and with the sign bit of y */
LIB_FUNC MATH_FUNC double copysign(const double x, const double y) {
	const double_shape_t x_u = { .value = x }, y_u = { .value = y };
	double num = x;
	SET_HIGH_WORD(num, (int)((uint32_t)(x_u.parts.msw & 0x7fffffff) | (uint32_t)(y_u.parts.msw & (uint32_t)0x80000000)));
	return num;
}
#define __copysign(x, y)   copysign((x), (y))


#if SUPPORTS_LONG_DOUBLE
/** Returns a value with the magnitude of x and with the sign bit of y */
LIB_FUNC MATH_FUNC long double copysignl(const long double x, const long double y) {
	const long_double_shape_t xh_u = { .value = x }, yh_u = { .value = y };
	register uint64_t hx = xh_u.uparts64.msw;
	register uint64_t hy = yh_u.uparts64.msw;
	long double num = x;
	SET_LDOUBLE_MSW64(num, (uint64_t)((uint64_t)(hx & (uint64_t)0x7fffffffffffffffULL) | (uint64_t)(hy & (uint64_t)0x8000000000000000ULL)));
	return num;
}
#   define __copysignl(x, y)   copysignl((x), (y))
#endif


// FPCLASSIFY

/** Returns a value of one of the classification macro constants, depending on the value of x */
LIB_FUNC MATH_FUNC int __fpclassifyf(const float x) {
	const float_shape_t xf_u = { .value = x };
	register uint32_t wx = xf_u.uword;
	wx &= 0x7fffffff;
	if (wx == 0) { return FP_ZERO; }
	else if (wx < 0x800000) { return FP_SUBNORMAL; }
	else if (wx >= 0x7f800000) { return ((wx > 0x7f800000) ? FP_NAN : FP_INFINITE); }
	else { return FP_NORMAL; }
}


/** Returns a value of one of the classification macro constants, depending on the value of x */
LIB_FUNC MATH_FUNC int __fpclassify(const double x) {
	const double_shape_t xw_u = { .value = x };
	register uint32_t hx = xw_u.parts.msw;
	register uint32_t lx = xw_u.parts.lsw;
	lx |= (uint32_t)(hx & 0xfffff);
	hx &= 0x7ff00000;
	if ((hx | lx) == 0) { return FP_ZERO; }
	else if (hx == 0) { return FP_SUBNORMAL; }
	else if (hx == 0x7ff00000) { return ((lx != 0) ? FP_NAN : FP_INFINITE); }
	else { return FP_NORMAL; }
}


#if SUPPORTS_LONG_DOUBLE
/** Returns a value of one of the classification macro constants, depending on the value of x */
LIB_FUNC MATH_FUNC int __fpclassifyl(const long double x) {
	const long_double_shape_t xw_u = { .value = x };
	register uint64_t hx = xw_u.uparts64.msw;
	register uint64_t lx = xw_u.uparts64.lsw;
	lx |= (hx & 0xffffffffffffULL);
	hx &= 0x7fff000000000000ULL;
	if ((hx | lx) == 0) { return FP_ZERO; }
	else if (hx == 0) { return FP_SUBNORMAL; }
	else if (hx == 0x7fff000000000000ULL) { return ((lx != 0) ? FP_NAN : FP_INFINITE); }
	else { return FP_NORMAL; }
}
#endif


// FINITE & ISFINITE

/** Return 1 if x is finite, else 0 */
#define finitef(x)   __extension__ ({ const float_shape_t __finitef_xf_s = { .value = (x) }; (int)((uint32_t)((__finitef_xf_s.uword & 0x7fffffff) - 0x7f800000) >> 31); })
/** Return 1 if x is finite, else 0 */
#define __finitef(x)   (int)finitef((float)(x))
#ifndef FINITEF
#   define FINITEF(x)   finitef((x))
#endif


/** Return 1 if x is finite, else 0 */
#define finite(x)   __extension__ ({ const double_shape_t __finite_xh_s = { .value = (x) }; (int)((uint32_t)((__finite_xh_s.sparts.msw & 0x7fffffff) - 0x7ff00000) >> 31); })
/** Return 1 if x is finite, else 0 */
#define __finite(x)   (int)finite((double)(x))
#ifndef FINITE
#   define FINITE(x)   finite((x))
#endif


#if SUPPORTS_LONG_DOUBLE
/** Return 1 if x is finite, else 0 */
#   define finitel(x)   __extension__ ({ const long_double_shape_t __finitel_x_u = { .value = (x) }; (int)((uint64_t)((__finitel_x_u.uparts64.msw & 0x7fffffffffffffffULL) - 0x7fff000000000000ULL) >> 63); })
/** Return 1 if x is finite, else 0 */
#   define __finitel(x)   (int)finitel((long double)(x))
/** Return a nonzero value if `X` is not +-Inf or NaN */
#   define ISFINITE(x)   Generic ((x), const float: finitef((x)), float: finitef((x)), const double: finite((x)), double: finite((x)), const long double: finitel((x)), long double: finitel((x)), default: 0)
#   ifndef FINITEL
#      define FINITEL(x)   finitel((x))
#   endif

#else

/** Return a nonzero value if `X` is not +-Inf or NaN */
#   define ISFINITE(x)   Generic ((x), const float: finitef((x)), float: finitef((x)), const double: finite((x)), double: finite((x)), default: 0)
#endif


/** Returns 1 is x is finite, else 0 */
LIB_FUNC MATH_FUNC int isfinitef(const float x) {
	const float_shape_t xf_u = { .value = x };  // Finite numbers have at least one zero bit in exponent
	return (int)((xf_u.uword | 0x807fffff) != UINT32_MAX);  // All other numbers will result in UINT32_MAX after OR
}
#define isnotfinitef(x)   (!isfinitef((x)))
#define is_not_finitef(x)   (!isfinitef((x)))


/** Returns 1 is x is finite, else 0 */
LIB_FUNC MATH_FUNC int isfinite(const double x) {
	const double_shape_t xh_u = { .value = x };  // Finite numbers have at least one zero bit in exponent
	return (int)((xh_u.parts.msw | (uint32_t)0x800fffff) != UINT32_MAX);  // All other numbers will result in UINT32_MAX after OR
}
#define isfinited(x)   isfinite((x))
#define isnotfinite(x)   (!isfinite((x)))
#define is_not_finite(x)   (!isfinite((x)))
#define is_not_finited(x)   (!isfinite((x)))


#if SUPPORTS_LONG_DOUBLE
/** Returns 1 is x is finite, else 0 */
LIB_FUNC MATH_FUNC int isfinitel(const long double x) {
	const long_double_shape_t xh_u = { .value = x };
	register const uint64_t hx = xh_u.uparts64.msw;
	return (int)((uint64_t)((hx & 0x7fffffffffffffffULL) - 0x7fff000000000000ULL) >> 63);
}
#   define isnotfinitel(x)   (!isfinitel((x)))
#   define is_not_finitel(x)   (!isfinitel((x)))
#endif


// ISINF

/** Returns 1 if x is inf, -1 if x is -inf, else 0 */
LIB_FUNC MATH_FUNC int __isinff(const float x) {
	const float_shape_t xf_s = { .value = x };
	register const int32_t t = ((xf_s.sword & (int32_t)0x7fffffff) ^ (int32_t)0x7f800000);
	return (int)(~((t | (-t)) >> 31) & (xf_s.sword >> 30));
}
#define isinff(x)   __isinff((x))


/** Returns 1 if x is inf, -1 if x is -inf, else 0 */
LIB_FUNC MATH_FUNC int __isinf(const double x) {
	const double_shape_t xw_s = { .value = x };
	register const int32_t lx = (xw_s.sparts.lsw | ((xw_s.sparts.msw & (int32_t)0x7fffffff) ^ (int32_t)0x7ff00000));
	return (int)(~((lx | (-lx)) >> 31) & (xw_s.sparts.msw >> 30));
}
#define isinfd(x)   __isinf((x))


#if SUPPORTS_LONG_DOUBLE
/** Returns 1 if x is inf, -1 if x is -inf, else 0 */
LIB_FUNC MATH_FUNC int __isinfl(const long double x) {
	const long_double_shape_t xw_s = { .value = x };
	register int64_t lx = xw_s.sparts64.lsw;
	lx |= (int64_t)((xw_s.sparts64.msw & (int64_t)0x7fffffffffffffffLL) ^ (int64_t)0x7fff000000000000LL);
	return (int)(~((lx | (-lx)) >> 63) & (xw_s.sparts64.msw >> 62));
}
#   define isinfl(x)   __isinfl((x))
#endif


/** Returns 1 if x is infinite, else 0 */
LIB_FUNC MATH_FUNC int __isinf_nsf(const float x) {
	const float_shape_t xf_u = { .value = x };
	return (int)(((int32_t)xf_u.uword & 0x7fffffff) == 0x7f800000);
}


/** Returns 1 if x is infinite, else 0 */
LIB_FUNC MATH_FUNC int __isinf_ns(const double x) {
	const double_shape_t xw_u = { .value = x };
	return (int)(!((int32_t)xw_u.parts.lsw | (((int32_t)xw_u.parts.msw & 0x7fffffff) ^ 0x7ff00000)));
}
#define isinf_nsd(x)   __isinf_ns((x))


#if SUPPORTS_LONG_DOUBLE
/** Returns 1 if x is infinite, else 0 */
LIB_FUNC MATH_FUNC int __isinf_nsl(const long double x) {
	const long_double_shape_t xw_u = { .value = x };
	return (int)(!((int64_t)xw_u.uparts64.lsw | (int64_t)((xw_u.uparts64.msw & 0x7fffffffffffffffULL) ^ 0x7fff000000000000ULL)));
}
#   define isinf_nsl(x)   __isinf_nsl((x))
#endif


// ISNAN & NAN

/** Returns 1 is x is nan, else 0 */
LIB_FUNC MATH_FUNC int __isnanf(const float x) {
	const float_shape_t xf_u = { .value = x };
	if ((uint32_t)(xf_u.uword & 0x7fffffffU) > 0x7f800000U) { return 1; }
	return 0;
}
#define rpl_isnanf(x)   __isnanf((x))
#define isnanf(x)   __isnanf((x))


/** Returns 1 is x is nan, else 0 */
LIB_FUNC MATH_FUNC int __isnan(const double x) {
	const double_shape_t xw_u = { .value = x };
	if ((xw_u.parts.msw & 0x7fffffffU) > 0x7ff00000U) { return 1; }
	return 0;
}
#define isnand(x)   __isnan((x))
#define rpl_isnand(x)   __isnand((x))


#if SUPPORTS_LONG_DOUBLE
/** Returns 1 is x is nan, else 0 */
LIB_FUNC MATH_FUNC int __isnanl(const long double x) {
	const long_double_shape_t xw_u = { .value = x };
	if ((xw_u.uparts64.msw & 0x7fffffffU) > 0x7fff00000U) { return 1; }
	return 0;
}
/** Return a nonzero value if `X` is NaN */
#   define isnan(x)   Generic ((x), const float: __isnanf((x)), float: __isnanf((x)), const double: __isnan((x)), double: __isnan((x)), const long double: __isnanl((x)), long double: __isnanl((x)), default: 0)
#   define isnanl(x)   __isnanl((x))
#   define rpl_isnanl(x)   __isnanl((x))
#else
/** Return a nonzero value if `X` is NaN */
#   define isnan(x)   Generic ((x), const float: __isnanf((x)), float: __isnanf((x)), const double: __isnan((x)), double: __isnan((x)), default: 0)
#endif


/** Returns a quiet NaN (Not-A-Number) value */
LIB_FUNC float nanf(const char* tagp) {
	if (tagp[0] != '\0') {
		const char buf[158] = { 0 };
		return strtof(buf, (const char**)NULL);
	}
	return NANF;
}


/** Returns a quiet NaN (Not-A-Number) value */
LIB_FUNC double nan(const char* tagp) {
	if (tagp[0] != '\0') {
		const char buf[1083] = { 0 };
		return strtod(buf, (const char**)NULL);
	}
	return NAN;
}
#define nand(x)   nan((x))


#if SUPPORTS_LONG_DOUBLE
/** Returns a quiet NaN (Not-A-Number) value */
LIB_FUNC long double nanl(const char* tagp) {
	if (tagp[0] != '\0') {
		const char buf[16454] = { 0 };
		return strtold(buf, (const char**)NULL);
	}
	return NAN;
}
#endif


// ISSIGNALING

/** Returns 1 is x is signaling, else 0 */
LIB_FUNC MATH_FUNC int __issignalingf(const float x) {
	const float_shape_t xf_u = { .value = x };
	return (int)((((int32_t)xf_u.uword & 0x7fc00000) == 0x7fc00000) && ((int32_t)xf_u.uword ^ 0x7fc00000));
}


/** Returns 1 is x is signaling, else 0 */
LIB_FUNC MATH_FUNC int __issignaling(const double x) {
	const double_shape_t x_u = { .value = x };
	return (int)((((int32_t)x_u.parts.msw & 0x7ff80000) == 0x7ff80000) && ((int64_t)x_u.sword ^ (int64_t)0x7ff8000000000000));
}


#if SUPPORTS_LONG_DOUBLE
/** Returns 1 is x is signaling, else 0 */
LIB_FUNC MATH_FUNC int __issignalingl(const long double x) {
	const long_double_shape_t x_u = { .value = x };
	return (int)((x_u.uparts64.msw & (uint64_t)0x7fff800000000000ULL) == (uint64_t)0x7fff800000000000ULL);
}
/** Return a nonzero value if `X` is a signaling NaN */
#   define issignaling(x)   Generic ((x), const float: __issignalingf((x)), float: __issignalingf((x)), const double: __issignaling((x)), double: __issignaling((x)), const long double: __issignalingl((x)), long double: __issignalingl((x)), default: 0)

#else

/** Return a nonzero value if `X` is a signaling NaN */
#   define issignaling(x)   Generic ((x), const float: __issignalingf((x)), float: __issignalingf((x)), const double: __issignaling((x)), double: __issignaling((x)), default: 0)
#endif


// ISNORMAL

/** Return a nonzero value if `X` is neither zero, subnormal, Inf, nor NaN */
#define isnormal(x)   Generic ((x), float: (__fpclassifyf((x)) == FP_NORMAL), double: (__fpclassify((x)) == FP_NORMAL), long double: (__fpclassifyl((x)) == FP_NORMAL), default: 0)


// ISGREATER, ISLESS, ETC.


// ISO C99 defines some macros to compare numbers while taking care for unordered numbers; Many FPUs provide special instructions to support these operations

/** Return the number of the float-point's classification */
#define fpclassify(x)   Generic ((x), float: __fpclassifyf((x)), double: __fpclassify((x)), long double: __fpclassifyl((x)), default: 0)


#ifndef isunordered
/** Return a nonzero value if arguments are unordered */
#   define __isunorderedf(u, v)   __extension__ ({ register const float __u = (float)(u), __v = (float)(v); (__fpclassifyf(__u) == FP_NAN) || (__fpclassifyf(__v) == FP_NAN); })
/** Return a nonzero value if arguments are unordered */
#   define __isunordered(u, v)   __extension__ ({ register const double __u = (u), __v = (v); (__fpclassify(__u) == FP_NAN) || (__fpclassify(__v) == FP_NAN); })
/** Return a nonzero value if arguments are unordered */
#   define __isunorderedl(u, v)   __extension__ ({ register const long double __u = (u), __v = (v); (__fpclassifyl(__u) == FP_NAN) || (__fpclassifyl(__v) == FP_NAN); })
/** Return a nonzero value if arguments are unordered */
#   define isunordered(u, v)   Generic ((u), float: __isunorderedf((u), (v)), double: __isunordered((u), (v)), long double: __isunorderedl((u), (v)), default: 0)
#endif


/** Return a nonzero value if `X` is positive or negative infinity */
#define isinf(x)   Generic ((x), float: __isinff((x)), double: __isinf((x)), long double: __isinfl((x)), default: 0)


#ifndef isgreater
/** Return a nonzero value if X is greater than Y */
#   define __isgreaterf(x, y)   __extension__ ({ register const float __x = (x), __y = (y); (!__isunorderedf(__x, __y)) && (__x > __y); })
/** Return a nonzero value if X is greater than Y */
#   define __isgreater(x, y)   __extension__ ({ register const double __x = (x), __y = (y); (!__isunordered(__x, __y)) && (__x > __y); })
/** Return a nonzero value if X is greater than Y */
#   define __isgreaterl(x, y)   __extension__ ({ register const long double __x = (x), __y = (y); (!__isunorderedl(__x, __y)) && (__x > __y); })
/** Return a nonzero value if X is greater than Y */
#   define isgreater(x, y)   Generic ((x), float: __isgreaterf((x), (y)), double: __isgreater((x), (y)), long double: __isgreaterl((x), (y)), default: 0)
#endif


#ifndef isgreaterequal
/** Return a nonzero value if X is greater than or equal to Y */
#   define __isgreaterequalf(x, y)   __extension__ ({ register const float __x = (x), __y = (y); (!__isunorderedf(__x, __y)) && (__x >= __y); })
/** Return a nonzero value if X is greater than or equal to Y */
#   define __isgreaterequal(x, y)   __extension__ ({ register const double __x = (x), __y = (y); (!__isunordered(__x, __y)) && (__x >= __y); })
/** Return a nonzero value if X is greater than or equal to Y */
#   define __isgreaterequall(x, y)   __extension__ ({ register const long double __x = (x), __y = (y); (!__isunorderedl(__x, __y)) && (__x >= __y); })
/** Return a nonzero value if X is greater than or equal to Y */
#   define isgreaterequal(x, y)   Generic ((x), float: __isgreaterequalf((x), (y)), double: __isgreaterequal((x), (y)), long double: __isgreaterequall((x), (y)), default: 0)
#endif


#ifndef isless
/** Return a nonzero value if X is less than Y */
#   define __islessf(x, y)   __extension__ ({ register const float __x = (x), __y = (y); (!__isunorderedf(__x, __y)) && (__x < __y); })
/** Return a nonzero value if X is less than Y */
#   define __isless(x, y)   __extension__ ({ register const double __x = (x), __y = (y); (!__isunordered(__x, __y)) && (__x < __y); })
/** Return a nonzero value if X is less than Y */
#   define __islessl(x, y)   __extension__ ({ register const long double __x = (x), __y = (y); (!__isunorderedl(__x, __y)) && (__x < __y); })
/** Return a nonzero value if X is less than Y */
#   define isless(x, y)   Generic ((x), float: __islessf((x), (y)), double: __isless((x), (y)), long double: __islessl((x), (y)), default: 0)
#endif


#ifndef islessequal
/** Return a nonzero value if X is less than or equal to Y */
#   define __islessequalf(x, y)   __extension__ ({ register const float __x = (x), __y = (y); (!__isunorderedf(__x, __y)) && (__x <= __y); })
/** Return a nonzero value if X is less than or equal to Y */
#   define __islessequal(x, y)   __extension__ ({ register const double __x = (x), __y = (y); (!__isunordered(__x, __y)) && (__x <= __y); })
/** Return a nonzero value if X is less than or equal to Y */
#   define __islessequall(x, y)   __extension__ ({ register const long double __x = (x), __y = (y); (!__isunorderedl(__x, __y)) && (__x <= __y); })
/** Return a nonzero value if X is less than or equal to Y */
#   define islessequal(x, y)   Generic ((x), float: __islessequalf((x), (y)), double: __islessequal((x), (y)), long double: __islessequall((x), (y)), default: 0)
#endif


#ifndef islessgreater
/** Return a nonzero value if either X is less than Y or Y is less than X */
#   define __islessgreaterf(x, y)   __extension__ ({ register const float __x = (x), __y = (y); (!__isunorderedf(__x, __y)) && ((__x < __y) || (__y < __x)); })
/** Return a nonzero value if either X is less than Y or Y is less than X */
#   define __islessgreater(x, y)   __extension__ ({ register const double __x = (x), __y = (y); (!__isunordered(__x, __y)) && ((__x < __y) || (__y < __x)); })
/** Return a nonzero value if either X is less than Y or Y is less than X */
#   define __islessgreaterl(x, y)   __extension__ ({ register const long double __x = (x), __y = (y); (!__isunorderedl(__x, __y)) && ((__x < __y) || (__y < __x)); })
/** Return a nonzero value if either X is less than Y or Y is less than X */
#   define islessgreater(x, y)   Generic ((x), float: __islessgreaterf((x), (y)), double: __islessgreater((x), (y)), long double: __islessgreaterl((x), (y)), default: 0)
#endif


// FLOAT MAX, MIN, & DIM

/** Returns the larger of the two arguments (either x or y); If one of the arguments in a NaN, the other is returned */
LIB_FUNC MATH_FUNC float fmaxf(const float x, const float y) {
	if (PREDICT_UNLIKELY(__fpclassifyf(x) == FP_NAN)) { return x; }
	else if (PREDICT_UNLIKELY(__fpclassifyf(y) == FP_NAN)) { return y; }
	return ((x > y) ? x : y);
}


/** Returns the larger of the two arguments (either x or y); If one of the arguments in a NaN, the other is returned */
LIB_FUNC MATH_FUNC double fmax(const double x, const double y) {
	if (PREDICT_UNLIKELY(__fpclassify(x) == FP_NAN)) { return x; }
	else if (PREDICT_UNLIKELY(__fpclassify(y) == FP_NAN)) { return y; }
	return ((x > y) ? x : y);
}


#if SUPPORTS_LONG_DOUBLE
/** Returns the larger of the two arguments (either x or y); If one of the arguments in a NaN, the other is returned */
LIB_FUNC MATH_FUNC long double fmaxl(const long double x, const long double y) {
	if (PREDICT_UNLIKELY(__fpclassifyl(x) == FP_NAN)) { return x; }
	else if (PREDICT_UNLIKELY(__fpclassifyl(y) == FP_NAN)) { return y; }
	return ((x > y) ? x : y);
}
#endif


/** Returns the smaller of the two arguments (either x or y); If one of the arguments in a NaN, the other is returned */
LIB_FUNC MATH_FUNC float fminf(const float x, const float y) {
	if (__fpclassifyf(x) == FP_NAN) { return x; }
	else if (__fpclassifyf(y) == FP_NAN) { return y; }
	return ((x < y) ? x : y);
}


/** Returns the smaller of the two arguments (either x or y); If one of the arguments in a NaN, the other is returned */
LIB_FUNC MATH_FUNC double fmin(const double x, const double y) {
	if (__fpclassify(x) == FP_NAN) { return x; }
	else if (__fpclassify(y) == FP_NAN) { return y; }
	return ((x < y) ? x : y);
}


#if SUPPORTS_LONG_DOUBLE
/** Returns the smaller of the two arguments (either x or y); If one of the arguments in a NaN, the other is returned */
LIB_FUNC MATH_FUNC long double fminl(const long double x, const long double y) {
	if (__fpclassifyl(x) == FP_NAN) { return x; }
	else if (__fpclassifyl(y) == FP_NAN) { return  y; }
	return ((x < y) ? x : y);
}
#endif


/** Return the positive difference between x and y; Returns `x-y` if `x>y`, or zero otherwise */
LIB_FUNC MATH_FUNC float fdimf(const float x, const float y) {
	register const int c = __fpclassifyf(x);
	if (PREDICT_UNLIKELY(c == FP_NAN || c == FP_INFINITE)) { return HUGEF; }
	return ((x > y) ? (x - y) : 0.0F);
}


/** Return the positive difference between x and y; Returns `x-y` if `x>y`, or zero otherwise */
LIB_FUNC MATH_FUNC double fdim(const double x, const double y) {
	register const int c = __fpclassify(x);
	if (PREDICT_UNLIKELY(c == FP_NAN || c == FP_INFINITE)) { return HUGE; }
	return ((x > y) ? (x - y) : 0.0);
}


#if SUPPORTS_LONG_DOUBLE
/** Return the positive difference between x and y; Returns `x-y` if `x>y`, or zero otherwise */
LIB_FUNC MATH_FUNC long double fdiml(const long double x, const long double y) {
	register const int c = __fpclassifyl(x);
	if (PREDICT_UNLIKELY(c == FP_NAN || c == FP_INFINITE)) { return HUGEL; }
	return ((x > y) ? (x - y) : 0.0L);
}
#endif


// CEILING, FLOOR, ROUND, TRUNC, ETC.

/** Return x rounded toward inf to integral value; An inexact flag is raised if x not equal to ceil(x) */
LIB_FUNC MATH_FUNC float ceilf(const float num) {
#   if (defined(ARCHX86) && (CPU_SSE4_1 || CPU_AVX || CPU_SSE2AVX))
	float res;
#      if (CPU_AVX || CPU_SSE2AVX)
	asm ("vroundss $2, %1, %0, %0;" : "=X"(res) : "X"(num));
#      elif CPU_SSE4_1
	asm ("roundss $2, %1, %0;" : "=X"(res) : "X"(num));
#      endif
	return res;
#   elif (defined(ARCHPOWERPC) && defined(_ARCH_PWR5X))
	float z, x = num;
	vasm("frip %0, %1;" "frsp %0, %0;" : "=f"(z) : "f"(x));
	return z;
#   else
	float_shape_t xf_s = { .value = num };
	register int32_t i0 = xf_s.sword;
	register int32_t j0 = (int32_t)((i0 >> 23) & 0xff) - 0x7f;
	if (PREDICT_LIKELY(j0 < 23)) {
		if (j0 < 0) {  // Raise inexact if num != 0
			raise_flag(HUGEF + num);  // Return 0*sign(num) if |num|<1
			if (i0 < 0) { i0 = (int32_t)0x80000000; }
			else if (i0 != 0) { i0 = 0x3f800000;}
		} else {
			register uint32_t i = (uint32_t)((0x7fffff) >> j0);
			if ((uint32_t)((uint32_t)i0 & i) == (uint32_t)0) { return num; }  // num is integral
			raise_flag(HUGEF + num);  // Raise inexact flag
			if (i0 > 0) { i0 += (int32_t)((0x800000) >> j0); }
			i0 &= ((int32_t)(~i));
		}
	} else {
		if (j0 == 0x80) { return (num + num); }  // inf or NaN
		else { return num; }  // num is integral
	}
	xf_s.sword = i0;
	return xf_s.value;
#   endif
}


/** Return x rounded toward inf to integral value; An inexact flag is raised if x not equal to ceil(x) */
LIB_FUNC MATH_FUNC double ceil(const double num) {
#   if (defined(ARCHX86) && (CPU_SSE4_1 || CPU_AVX || CPU_SSE2AVX))
	double res;
#      if (CPU_AVX || CPU_SSE2AVX)
	asm ("vroundsd $1, %1, %0, %0;" : "=X"(res) : "X"(num));
#      elif CPU_SSE4_1
	asm ("roundsd $1, %1, %0;" : "=X"(res) : "X"(num));
#      endif
	return res;
#   elif (defined(ARCHPOWERPC) && defined(_ARCH_PWR5X))
	double z, x = num;
	vasm("frip %0, %1;" : "=f"(z) : "f"(x));
	return z;
#   else
	double_shape_t xw_s = { .value = num };
	register int32_t i0 = xw_s.sparts.msw;
	register int32_t i1 = xw_s.sparts.lsw;
	register int32_t j0 = (int32_t)((i0 >> 20) & 0x7ff) - 0x3ff;
	if (PREDICT_LIKELY(j0 < 20)) {
		if (j0 < 0) {  // Raise inexact if num != 0
			if ((HUGE + num) > 0.0) {  // Return 0*sign(num) if |num|<1
				if (i0 < 0) { i0 = (int32_t)0x80000000; i1 = 0; }
				else if ((i0 | i1) != 0) { i0 = 0x3ff00000; i1 = 0; }
			}
		} else {
			register int32_t i = (int32_t)(0xfffff >> j0);
			if (((int32_t)(i0 & i) | i1) == 0) { return num; }  // num is integral
			else if ((HUGE + num) > 0.0) {  // Raise inexact flag
				if (i0 > 0) { i0 += (0x100000 >> j0); }
				i0 &= ((int32_t)(~i));
				i1 = 0;
			}
		}
	} else if (j0 > 51) {
		if (j0 == 0x400) { return (num + num); }  // inf or NaN
		else { return num; }  // num is integral
	} else {
		register int32_t i = ((int32_t)UINT32_MAX) >> (j0 - 20);
		if ((int32_t)(i1 & i) == 0) { return num; }  // num is integral
		else if ((HUGE + num) > 0.0) {  // Raise inexact flag
			if (i0 > 0) {
				if (j0 == 20) { i0 += 1; }
				else {
					register int32_t j = (int32_t)(i1 + (1 << (52 - j0)));
					if (j < i1) { i0 += 1; }  // Got a carry
					i1 = (int32_t)j;
				}
			}
			i1 &= ((int32_t)(~i));
		}
	}
	xw_s.sparts.msw = i0;
	xw_s.sparts.lsw = i1;
	return xw_s.value;
#   endif
}


#if SUPPORTS_LONG_DOUBLE
/** Return x rounded toward inf to integral value; An inexact flag is raised if x not equal to ceil(x) */
LIB_FUNC MATH_FUNC long double ceill(const long double num) {
	long_double_shape_t qw = { .value = num };
	register int64_t i0 = qw.sparts64.msw;
	register int64_t i1 = qw.sparts64.lsw;
	register int64_t j0 = (((i0 >> 48) & 0x7fff) - 0x3fff);
	register int64_t i;
	if (PREDICT_LIKELY(j0 < 48)) {
		if (j0 < 0) {  // Raise inexact if num != 0
			if ((HUGEL + num) > 0.0L) {  // Return 0*sign(num) if |num|<1
				if (i0 < 0) { i0 = (int64_t)0x8000000000000000LL; i1 = 0; }
				else if ((i0 | i1) != 0) { i0 = (int64_t)0x3fff000000000000LL; i1= 0; }
			}
		} else {
			i = (int64_t)((0xffffffffffffLL) >> j0);
			if (((i0 & i) | i1) == 0) { return num; }  // num is integral
			if ((HUGEL + num) > 0.0L) {  // Raise inexact flag
				if (i0 > 0) { i0 += (int64_t)((0x1000000000000LL) >> j0); }
				i0 &= (~i);
				i1 = 0;
			}
		}
	} else if (j0 > 111) {
		if (j0 == 0x4000) { return (num + num); }  // inf or NaN
		else { return num; }  // num is integral
	} else {
		i = ((-1LL) >> (j0 - 48));
		if ((i1 & i) == 0) { return num; }  // num is integral
		if ((HUGEL + num) > 0.0L) {  // raise inexact flag
			if (i0 > 0) {
				if (j0 == 48) { i0 += 1; }
				else {
					register int64_t j = i1 + (1LL << (112 - j0));
					if (j < i1) { i0 += 1 ; }  // Got a carry
					i1 = j;
				}
			}
			i1 &= (~i);
		}
	}
	qw.sparts64.msw = i0;
	qw.sparts64.lsw = i1;
	return qw.value;
}
#endif


/** Return x rounded toward -inf (downward) to an integral value that is not greater than x; An inexact is flag raised if x is not equal to floor(x) */
LIB_FUNC MATH_FUNC float floorf(const float num) {
#   if (defined(ARCHX86) && (CPU_SSE4_1 || CPU_AVX || CPU_SSE2AVX))
	float res;
#      if (CPU_AVX || CPU_SSE2AVX)
	asm ("vroundss $1, %1, %0, %0;" : "=X"(res) : "X"(num));
#      elif CPU_SSE4_1
	asm ("roundss $1, %1, %0;" : "=X"(res) : "X"(num));
#      endif
	return res;
#   elif (defined(ARCHPOWERPC) && defined(_ARCH_PWR5X))
	float z, x = num;
	vasm("frim %0, %1;" "frsp %0, %0;" : "=f"(z) : "f"(x));
	return z;
#   else
	float x = num;
	const float_shape_t xf_u = { .value = x };
	register int32_t i0 = xf_u.sword;
	register int32_t j0 = (int32_t)(((i0 >> 23) & 0xff) - 0x7f);
	if (PREDICT_LIKELY(j0 < 23)) {
		if (j0 < 0) {  // Raise inexact if x != 0
			raise_flag(HUGEF + x);  // Return 0*sign(x) if |x|<1
			if (i0 >= 0) { i0 = 0; }
			else if ((i0 & 0x7fffffff) != 0) { i0 = (int32_t)0xbf800000; }
		} else {
			register int32_t i = (int32_t)((0x7fffff) >> j0);
			if ((i0 & i) == 0) { return x; }  // x is integral
			raise_flag(HUGEF + x);  // Raise inexact flag
			if (i0 < 0) { i0 += (int32_t)(0x800000 >> j0); }
			i0 &= ((int32_t)(~i));
		}
	} else {
		if (PREDICT_UNLIKELY(j0 == 0x80)) { return (x + x); }  // inf or NaN
		else { return x; }  // x is integral
	}
	SET_FLOAT_WORD(x, i0);
	return x;
#   endif
}


/** Return x rounded toward -inf (downward) to an integral value that is not greater than x; An inexact is flag raised if x is not equal to floor(x) */
LIB_FUNC MATH_FUNC double floor(const double num) {
#   if (defined(ARCHX86) && (CPU_SSE4_1 || CPU_AVX || CPU_SSE2AVX))
	double res;
#      if (CPU_AVX || CPU_SSE2AVX)
	asm ("vroundsd $1, %1, %0, %0;" : "=X"(res) : "X"(num));
#      elif CPU_SSE4_1
	asm ("roundsd $1, %1, %0;" : "=X"(res) : "X"(num));
#      endif
	return res;
#   elif (defined(ARCHPOWERPC) && defined(_ARCH_PWR5X))
	double z, x = num;
	vasm("frim %0, %1;" : "=f"(z) : "f"(x));
	return z;
#   else
	double x = num;
	const double_shape_t xw_u = { .value = x };
	register int32_t i0 = (int32_t)xw_u.parts.msw;
	register int32_t i1 = (int32_t)xw_u.parts.lsw;
	register int32_t j0 = (int32_t)(((i0 >> 20) & 0x7ff) - 0x3ff);
	if (PREDICT_LIKELY(j0 < 20)) {
		if (j0 < 0) {  // Raise inexact if x != 0
			if (HUGE + x > 0.0) {  // Return 0*sign(x) if |x|<1
				if (i0 >= 0) { i0 = i1 = 0; }
				else if (((i0 & 0x7fffffff) | i1) != 0) { i0 = (int32_t)0xbff00000; i1 = 0; }
			}
		} else {
			register int32_t i = (int32_t)((0xfffff) >> j0);
			if (((i0 & i) | i1) == 0) { return x; }  // x is integral
			if ((HUGE + x) > 0.0) {  // Raise inexact flag
				if (i0 < 0) { i0 += (int32_t)((0x100000) >> j0); }
				i0 &= ((int32_t)(~i));
				i1 = 0;
			}
		}
	} else if (j0 > 51) {
		if (PREDICT_UNLIKELY(j0 == 0x400)) { return (x + x); }  // inf or NaN
		else { return x; }  // x is integral
	} else {
		register int32_t i = ((int32_t)UINT32_MAX) >> (j0 - 20);
		if ((i1 & i) == 0) { return x; }  // x is integral
		if ((HUGE + x) > 0.0) {  // Raise inexact flag
			if (i0 < 0) {
				if (j0 == 20) { ++i0; }
				else {
					register int32_t j = (int32_t)(i1 + (1 << (52 - j0)));
					if (j < i1) { ++i0; }  // Got a carry
					i1 = j;
				}
			}
			i1 &= ((int32_t)(~i));
		}
	}
	xw_u.parts.msw = (uint32_t)i0;
	xw_u.parts.lsw = (uint32_t)i1;
	return xw_u.value;
#   endif
}


#if SUPPORTS_LONG_DOUBLE
/** Return x rounded toward -inf (downward) to an integral value that is not greater than x; An inexact is flag raised if x is not equal to floor(x) */
LIB_FUNC MATH_FUNC long double floorl(const long double num) {
	long double x = num;
	const long_double_shape_t xw_u = { .value = x };
	register int64_t i0 = (int64_t)xw_u.uparts64.msw;
	register int64_t i1 = (int64_t)xw_u.uparts64.lsw;
	register int64_t j0 = (int64_t)((i0 >> 48) & 0x7fff) - 0x3fff;
	if (PREDICT_LIKELY(j0 < 48)) {
		if (j0 < 0) {  // Raise inexact if x != 0
			if (HUGEL + x > 0.0L) {  // Return 0*sign(x) if |x|<1
				if (i0 >= 0) { i0 = i1 = 0; }
				else if (((i0 & (int64_t)0x7fffffffffffffffLL) | i1) != 0) { i0 = (int64_t)0xbfff000000000000LL; i1 = 0; }
			}
		} else {
			register int64_t i = (int64_t)((0xffffffffffffLL) >> j0);
			if (((i0 & i) | i1) == 0) { return x; }  // x is integral
			if (HUGEL + x > 0.0L) {  // Raise inexact flag
				if (i0 < 0) { i0 += (int64_t)((0x1000000000000LL) >> j0); }
				i0 &= ((int64_t)(~i));
				i1 = 0;
			}
		}
	} else if (j0 > 111) {
		if (PREDICT_UNLIKELY(j0 == 0x4000)) { return (x + x); }  // inf or NaN
		else { return x; }  // x is integral
	} else {
		register int64_t i = (int64_t)((-1LL) >> (j0 - 48));
		if ((i1 & i) == 0) { return x; }  // x is integral
		if (HUGEL + x > 0.0L) {  // Raise inexact flag
			if (i0 < 0) {
				if (j0 == 48) { ++i0; }
				else {
					register int64_t j = (int64_t)(i1 + (1LL << (112 - j0)));
					if (j < i1) { ++i0; }  // Got a carry
					i1 = (int64_t)j;
				}
			}
			i1 &= ((int64_t)(~i));
		}
	}
	SET_LDOUBLE_WORDS64(x, i0, i1);
	return x;
}
#endif


LIB_FUNC MATH_FUNC int round_intf(const float x) {
	return (int)((x > 0.0F) ? (x + 0.5F) : (x - 0.5F));
}


LIB_FUNC MATH_FUNC int round_int(const double x) {
	return (int)((x > 0.0) ? (x + 0.5) : (x - 0.5));
}


/** Returns the integral value that is nearest to x, with halfway cases rounded away from zero */
LIB_FUNC MATH_FUNC float roundf(const float x) {
#   if (defined(ARCHPOWERPC) && defined(_ARCH_PWR5X))
	float z;
	vasm("frin %0, %1;" "frsp %0, %0;" : "=f"(z) : "f"(x));
	return z;
#   else
	return floorf(((x > 0.0F) ? (x + 0.5F) : (x - 0.5F)));
#   endif
}


/** Returns the integral value that is nearest to x, with halfway cases rounded away from zero */
LIB_FUNC MATH_FUNC double round(const double x) {
#   if (defined(ARCHPOWERPC) && defined(_ARCH_PWR5X))
	double z;
	vasm("frin %0, %1;" : "=f"(z) : "f"(x));
	return z;
#   else
	return floor(((x > 0.0) ? (x + 0.5) : (x - 0.5)));
#   endif
}
#define __round(x)   round((x))


#if SUPPORTS_LONG_DOUBLE
/** Returns the integral value that is nearest to x, with halfway cases rounded away from zero */
LIB_FUNC MATH_FUNC long double roundl(const long double x) {
	return floorl(((x > 0.0L) ? (x + 0.5L) : (x - 0.5L)));
}
#endif


/** Round up the given digit string; If the digit string is fff...f, this procedure sets it to 100...0 and returns 1 to indicate that the exponent needs to be bumped; Otherwise, 0 is returned */
LIB_FUNC int roundup(char* restrict s0, const int ndigits) {
	char* restrict s = NULL;
	for (s = (s0 + ndigits - 1); *s == 0xf; s--) {
		if (s == s0) {
			*s = 1;
			return 1;
		}
		*s = 0;
	}
	++*s;
	return 0;
}


/** Return x rounded to integral value according to the prevailing rounding mode; An inexact flag is raised if x not equal to rint(x) */
LIB_FUNC MATH_FUNC int rintf(const float x) {
#   if (defined(ARCHX86) && (CPU_SSE4_1 || CPU_AVX || CPU_SSE2AVX))
	float res;
#      if (CPU_AVX || CPU_SSE2AVX)
	asm ("vroundss $4, %1, %0, %0;" : "=X"(res) : "X"(x));
#      elif CPU_SSE4_1
	asm ("roundss $4, %1, %0;" : "=X"(res) : "X"(x));
#      endif
	return (int)res;
#   else
	const float_shape_t xf_u = { .value = x };
	register uint32_t i0 = xf_u.uword;
	register uint32_t sx = (uint32_t)((i0 >> 31) & 1);
	register int32_t j0 = (int32_t)((((int32_t)i0 >> 23) & 0xff) - 0x7f);
	if (PREDICT_LIKELY(j0 < 23)) {
		if (j0 < 0) {
			float_shape_t tf_u = { .value = (float)((TWO23[sx] + x) - TWO23[sx]) };
			i0 = tf_u.uword;
			tf_u.uword = (uint32_t)((i0 & (uint32_t)0x7fffffff) | (uint32_t)(sx << 31));
			return (int)tf_u.value;
		}
	} else {
		if (j0 == 0x80) { return (int)(x + x); }  // INF or NaN
		else { return (int)x; }  // x is integral
	}
	return (int)((TWO23[sx] + x) - TWO23[sx]);
#   endif
}
#define __rintf(x)   rintf((x))


/** Return x rounded to integral value according to the prevailing rounding mode; An inexact flag is raised if x not equal to rint(x) */
LIB_FUNC MATH_FUNC int rint(const double x) {
#   if (defined(ARCHX86) && (CPU_SSE4_1 || CPU_AVX || CPU_SSE2AVX))
	double res;
#      if (CPU_AVX || CPU_SSE2AVX)
	asm ("vroundsd $4, %1, %0, %0;" : "=X"(res) : "X"(x));
#      elif CPU_SSE4_1
	asm ("roundsd $4, %1, %0;" : "=X"(res) : "X"(x));
#      endif
	return (int)res;
#   else
	const double_shape_t xh_u = { .value = x };
	register uint32_t i0 = xh_u.parts.msw;
	register const uint32_t sx = (uint32_t)(((uint32_t)i0 >> 31) & 1);
	register int32_t j0 = (int32_t)((((int32_t)i0 >> 20) & 0x7ff) - 0x3ff);
	if (PREDICT_LIKELY(j0 < 52)) {
		if (j0 < 0) {
			double_shape_type th_u;
			th_u.value = (double)((TWO52[sx] + x) - TWO52[sx]);
			i0 = th_u.parts.msw;
			th_u.parts.msw = (uint32_t)((i0 & (uint32_t)0x7fffffff) | (uint32_t)(sx << 31));
			return (int)th_u.value;
		}
	} else {
		if (j0 == 0x400) { return (int)(x + x); }  // INF or NaN
		else { return (int)x; }  // x is integral
	}
	return (int)((TWO52[sx] + x) - TWO52[sx]);
#   endif
}
#define __rint(x)   rint((x))


#if SUPPORTS_LONG_DOUBLE
/** Return x rounded to integral value according to the prevailing rounding mode; An inexact flag is raised if x not equal to rintl(x) */
LIB_FUNC MATH_FUNC long double rintl(const long double x) {
	const long_double_shape_t xw_u = { .value = x };
	register uint64_t i0 = xw_u.uparts64.msw;
	register uint64_t sx = (uint64_t)(i0 >> 63);
	register int64_t j0 = (int64_t)((((int64_t)i0 >> 48) & 0x7fff) - 0x3fff);
	if (PREDICT_LIKELY(j0 < 112)) {
		if (j0 < 0) {
			long_double_shape_t th_u = { .value = (long double)((TWO112[sx] + x) - TWO112[sx]) };
			i0 = th_u.uparts64.msw;
			th_u.uparts64.msw = (uint64_t)((i0 & (uint64_t)0x7fffffffffffffffLL) | (uint64_t)(sx << 63));
			return th_u.value;
		}
	} else {
		if (j0 == 0x4000) { return (x + x); }  // inf or NaN
		else { return x; }  // x is integral
	}
	return ((TWO112[sx] + x) - TWO112[sx]);
}
#   define __rintl(x)   rintl((x))
#endif


/** Round argument to nearest integral value according to current rounding direction */
LIB_FUNC MATH_FUNC long lrintf(const float x) {
	const float_shape_t xf_u = { .value = x };
	register uint32_t i0 = xf_u.uword;
	register long sx = (long)(i0 >> 31);
	register int32_t j0 = (int32_t)(((i0 >> 23) & 0xff) - 0x7f);
	i0 = (uint32_t)((i0 & 0x7fffff) | 0x800000);
	register long result;
	if (j0 < ((int32_t)(BITS_PER_LONG) - 1)) {
		if (j0 >= 23) { result = (long)(i0 << (uint32_t)(j0 - 23)); }
		else {
			const float_shape_t tf_u = { .value = (float)((TWO23[sx] + x) - TWO23[sx]) };
			i0 = tf_u.uword;
			j0 = (int32_t)(((i0 >> 23) & 0xff) - 0x7f);
			i0 = (uint32_t)((i0 & (uint32_t)0x7fffff) | (uint32_t)0x800000);
			result = (long)((j0 < 0) ? 0 : (i0 >> (23 - j0)));
		}
	} else { return (long)x; }  // The number is too large
	return (long)(sx ? (-result) : result);
}
#define __lrintf(x)   lrintf((x))


/** Round argument to nearest integral value according to current rounding direction */
LIB_FUNC MATH_FUNC long lrint(const double x) {
	double_shape_t ew_u = { .value = (double)((x)) };
	register uint32_t i0 = (uint32_t)ew_u.parts.msw;
	register uint32_t i1 = (uint32_t)ew_u.parts.lsw;
	register int32_t j0 = (int32_t)(((i0 >> 20) & 0x7ff) - 0x3ff);
	register long sx = (long)(i0 >> 31);
	i0 = (uint32_t)((i0 & 0xfffff) | 0x100000);
	register long result = 0;
	if (j0 < 20) {
		register double t = (double)((TWO52[sx] + x) - TWO52[sx]);
		ew_u.value = (double)((t));
		i0 = (uint32_t)ew_u.parts.msw;
		i1 = (uint32_t)ew_u.parts.lsw;
		j0 = (int32_t)(((i0 >> 20) & 0x7ff) - 0x3ff);
		i0 = (uint32_t)((i0 & 0xfffff) | 0x100000);
		result = (long)((j0 < 0) ? 0 : ((int32_t)i0 >> (20 - j0)));
	} else if (j0 < (int32_t)(BITS_PER_LONG) - 1) {
		if (j0 >= 52) { result = (long)(((int32_t)i0 << (j0 - 20)) | (int32_t)((int32_t)i1 << (j0 - 52))); }
		register double t = (double)((TWO52[sx] + x) - TWO52[sx]);
		EXTRACT_WORDS(i0, i1, t);
		j0 = (int32_t)(((i0 >> 20) & 0x7ff) - 0x3ff);
		i0 = (uint32_t)((i0 & 0xfffff) | 0x100000);
		if (j0 == 20) { result = (long)i0; }
		else { result = (long)((int32_t)i0 << (j0 - 20)) | (int32_t)((int32_t)i1 >> (52 - j0)); }
	} else { return (long)x; }  // The number is too large
	return (long)(sx ? (-result) : result);
}
#define __lrint(x)   lrint((x))


#if SUPPORTS_LONG_DOUBLE
/** Round argument to nearest integral value according to current rounding direction */
LIB_FUNC MATH_FUNC long lrintl(const long double x) {
	long_double_shape_t xw_u = { .value = x };
	register uint64_t i0 = xw_u.uparts64.msw;
	register uint64_t i1 = xw_u.uparts64.lsw;
	register int32_t j0 = (int32_t)(((i0 >> 48) & 0x7fff) - 0x3fff);
	register long sx = (long)(i0 >> 63);
	i0 = (uint64_t)((i0 & 0xffffffffffffULL) | 0x1000000000000ULL);
	register long result;
	if (j0 < 48) {
		const long_double_shape_t tw_u = { .value = (long double)((TWO112[sx] + x) - TWO112[sx]) };
		i0 = tw_u.uparts64.msw;
		j0 = (int32_t)(((i0 >> 48) & 0x7fff) - 0x3fff);
		i0 = (uint64_t)((i0 & (uint64_t)0xffffffffffffULL) | (uint64_t)0x1000000000000ULL);
		result = (long)((j0 < 0) ? 0 : (i0 >> (48 - j0)));
	} else if (j0 < (int32_t)(BITS_PER_LONG) - 1) {
		if (j0 >= 112) { result = (long)((i0 << (j0 - 48)) | (i1 << (j0 - 112))); }
		else {
			const long_double_shape_t tw_u = { .value = (long double)((TWO112[sx] + x) - TWO112[sx]) };
			i0 = tw_u.uparts64.msw;
			j0 = (int32_t)(((i0 >> 48) & 0x7fff) - 0x3fff);
			i0 = (uint64_t)((i0 & 0xffffffffffffULL) | 0x1000000000000ULL);
			if (j0 == 48) { result = (long)i0; }
			else { result = (long)((int32_t)(((int64_t)i0) << (j0 - 48)) | (int32_t)(((int64_t)tw_u.uparts64.lsw) >> (112 - j0))); }
		}
	} else { return (long)x; }  // The number is too large
	return (long)(sx ? (-result) : result);
}
#   define __lrintl(x)   lrintl((x))
#endif


/** Round argument to nearest integral value according to current rounding direction */
LIB_FUNC MATH_FUNC long long llrintf(const float x) {
	const float_shape_t xf_u = { .value = x };
	register uint32_t i0 = xf_u.uword;
	register const int32_t sx = (int32_t)(i0 >> 31);
	register int32_t j0 = (int32_t)((i0 >> 23) & 0xff) - 0x7f;
	i0 = (uint32_t)((i0 & 0x7fffff) | 0x800000);
	register long long result;
	if (j0 < (int32_t)(BITS_PER_LONG_LONG) - 1) {
		if (j0 >= 23) { result = (long long)i0 << (j0 - 23); }
		else {
			const float_shape_t tf_u = { .value = ((TWO23[sx] + x) - TWO23[sx]) };
			i0 = tf_u.uword;
			j0 = (int32_t)(((i0 >> 23) & 0xff) - 0x7f);
			i0 = (uint32_t)((i0 & 0x7fffff) | 0x800000);
			result = ((j0 < 0) ? 0 : (i0 >> (23 - j0)));
		}
	} else { return (long long)x; }  // The number is too large
	return (long long)(sx ? (-result) : result);
}
#define __llrintf(x)   llrintf((x))


/** Round argument to nearest integral value according to current rounding direction */
LIB_FUNC MATH_FUNC long long llrint(const double x) {
	register uint32_t i1, i0;
	EXTRACT_WORDS(i0, i1, x);
	register int32_t j0 = (int32_t)(((i0 >> 20) & 0x7ff) - 0x3ff);
	register int32_t sx = (int32_t)(i0 >> 31);
	i0 = (uint32_t)((i0 & 0xfffff) | 0x100000);
	register long long result;
	if (PREDICT_LIKELY(j0 < 20)) {
		register double t = ((TWO52[sx] + x) - TWO52[sx]);
		EXTRACT_WORDS(i0, i1, t);
		j0 = (int32_t)(((i0 >> 20) & 0x7ff) - 0x3ff);
		i0 = (uint32_t)((i0 & 0xfffff) | 0x100000);
		result = ((j0 < 0) ? 0 : (i0 >> (20 - j0)));
	} else if (j0 < (int32_t)(BITS_PER_LONG_LONG) - 1) {
		if (j0 >= 52) { result = (((long long)i0 << 32) | i1) << (j0 - 52); }
		else {
			register double t = ((TWO52[sx] + x) - TWO52[sx]);
			EXTRACT_WORDS(i0, i1, t);
			j0 = (int32_t)(((i0 >> 20) & 0x7ff) - 0x3ff);
			i0 = (uint32_t)((i0 & 0xfffff) | 0x100000);
			if (j0 == 20) { result = (long long)i0; }
			else { result = ((long long)i0 << (j0 - 20)) | (i1 >> (52 - j0)); }
		}
	} else { return (long long)x; }  // The number is too large
	return (long long)(sx ? (-result) : result);
}
#define __llrint(x)   llrint((x))


#if SUPPORTS_LONG_DOUBLE
/** Round argument to nearest integral value according to current rounding direction */
LIB_FUNC MATH_FUNC long long llrintl(const long double x) {
	const long_double_shape_t xw_u = { .value = x };
	register uint64_t i0 = xw_u.uparts64.msw;
	register uint64_t i1 = xw_u.uparts64.lsw;
	register int32_t j0 = (int32_t)(((i0 >> 48) & 0x7fff) - 0x3fff);
	register uint32_t sx = (uint32_t)(i0 >> 63);
	i0 = (uint64_t)((i0 & 0xffffffffffffULL) | 0x1000000000000ULL);
	register long long result;
	if (j0 < (int32_t)(BITS_PER_LONG_LONG) - 1) {
		const long_double_shape_t tw_u = { .value = ((TWO112[sx] + x) - TWO112[sx]) };
		i0 = tw_u.uparts64.msw;
		i1 = tw_u.uparts64.lsw;
		j0 = (int32_t)((((int32_t)(i0 >> 48)) & 0x7fff) - 0x3fff);
		i0 = (uint64_t)((uint64_t)(i0 & (uint64_t)0xffffffffffffULL) | 0x1000000000000ULL);
		if (j0 < 0) { result = 0; }
		else if (j0 <= 48) { result = (long long)(((int64_t)i0) >> (48 - j0)); }
		else { result = (long long)((((int64_t)i0) << (int64_t)(j0 - 48)) | (int64_t)(((int64_t)i1) >> (int64_t)(112 - j0))); }
	} else { return (long long)x; }  // The number is too large
	return (long long)(sx ? (-result) : result);
}
#   define __llrintl(x)   llrintl((x))
#endif


/** Returns an integer that is nearest in value to x, with halfway cases rounded away from zero */
LIB_FUNC MATH_FUNC long lroundf(const float x) {
	const float_shape_t xf_u = { .value = x };
	register uint32_t i = xf_u.uword;
	register int32_t j0 = (int32_t)(((i >> 23) & 0xff) - 0x7f);
	register long sign = (long)(((i & (uint32_t)0x80000000) != 0) ? -1 : 1);
	i = (uint32_t)((i & 0x7fffff) | 0x800000);
	register long result;
	if (j0 < (int32_t)(BITS_PER_LONG) - 1) {
		if (j0 < 0) { return (long)((j0 < -1) ? 0 : sign); }
		else if (j0 >= 23) { result = (long)((int32_t)i << (j0 - 23)); }
		else {
			i += (uint32_t)(0x400000 >> j0);
			result = (long)((int32_t)i >> (23 - j0));
		}
	} else { return (long)x; }  // The number is too large
	return (long)(sign * result);
}


/** Returns an integer that is nearest in value to x, with halfway cases rounded away from zero */
LIB_FUNC MATH_FUNC long lround(const double x) {
	register uint32_t i1, i0;
	EXTRACT_WORDS(i0, i1, x);
	register int32_t j0 = (int32_t)(((i0 >> 20) & 0x7ff) - 0x3ff);
	register long sign = (long)((i0 & (uint32_t)0x80000000) != 0 ? -1 : 1);
	i0 = ((i0 & 0xfffff) | 0x100000);
	register long result;
	if (j0 < 20) {
		if (j0 < 0) { return ((j0 < -1) ? 0 : sign); }
		else {
			i0 += (uint32_t)(0x80000 >> j0);
			result = (long)(i0 >> (20 - j0));
		}
	} else if (j0 < (int32_t)(BITS_PER_LONG) - 1) {
		if (j0 >= 52) { result = ((long)i0 << (j0 - 20)) | ((long)i1 << (j0 - 52)); }
		else {
			register uint32_t j = (uint32_t)(i1 + (uint32_t)(0x80000000 >> (j0 - 20)));
			if (j < i1) { ++i0; }
			if (j0 == 20) { result = (long)i0; }
			else { result = (long)((long)i0 << (j0 - 20)) | (j >> (52 - j0)); }
		}
	} else { return (long)x; }  // The number is too large
	return (long)(sign * result);
}


#if SUPPORTS_LONG_DOUBLE
/** Returns an integer that is nearest in value to x, with halfway cases rounded away from zero */
LIB_FUNC MATH_FUNC long lroundl(const long double x) {
	const long_double_shape_t xw_u = { .value = x };
	register uint64_t i0 = xw_u.uparts64.msw;
	register uint64_t i1 = xw_u.uparts64.lsw;
	register int64_t j0 = (int64_t)(((i0 >> 48) & 0x7fff) - 0x3fff);
	register long sign = (long)((i0 & (uint64_t)0x8000000000000000ULL) != 0 ? -1 : 1);
	i0 = (uint64_t)((i0 & (uint64_t)0xffffffffffffULL) | (uint64_t)0x1000000000000ULL);
	register long result;
	if (j0 < 48) {
		if (j0 < 0) { return (long)((j0 < -1) ? 0 : sign); }
		else {
			i0 += (uint64_t)(0x800000000000ULL >> (uint64_t)j0);
			result = (long)((int64_t)i0 >> (int64_t)(48 - j0));
		}
	} else if (j0 < (int32_t)(BITS_PER_LONG) - 1) {
		if (j0 >= 112) { result = (long)((i0 << (j0 - 48)) | (i1 << (j0 - 112))); }
		else {
			register uint64_t j = (i1 + (uint64_t)(0x8000000000000000ULL >> (uint64_t)(j0 - 48)));
			if (j < i1) { ++i0; }
			if (j0 == 48) { result = (long)i0; }
			else { result = (long)(((int64_t)i0 << (int64_t)(j0 - 48)) | (int64_t)((int64_t)j >> (int64_t)(112 - j0))); }
		}
	} else {return (long) x; }  // The number is too large
	return (long)(sign * result);
}
#endif


/** Returns an integer that is nearest in value to x, with halfway cases rounded away from zero */
LIB_FUNC MATH_FUNC long long llroundf(const float x) {
	float_shape_t xf_u = { .value = x };
	register uint32_t i = xf_u.uword;
	register int32_t j0 = (int32_t)(((i >> 23) & 0xff) - 0x7f);
	register long long sign = (long long)(((i & (uint32_t)0x80000000) != 0) ? -1 : 1);
	i = (uint32_t)((uint32_t)(i & (uint32_t)0x7fffff) | (uint32_t)0x800000);
	register long long result;
	if (PREDICT_LIKELY(j0 < (int32_t)((BITS_PER_LONG_LONG) - 1))) {
		if (j0 < 0) { return ((j0 < -1) ? 0 : sign); }
		else if (j0 >= 23) { result = (long long)(i << (j0 - 23)); }
		else {
			i += (uint32_t)(0x400000 >> j0);
			result = (long long)(i >> (23 - j0));
		}
	} else { return (long long)x; }  // The number is too large
	return (sign * result);
}


/** Returns an integer that is nearest in value to x, with halfway cases rounded away from zero */
LIB_FUNC MATH_FUNC long long llround(const double x) {
	register uint32_t i1, i0;
	EXTRACT_WORDS(i0, i1, x);
	register int32_t j0 = (int32_t)(((i0 >> 20) & 0x7ff) - 0x3ff);
	register long long sign = (long long)(((i0 & (uint32_t)0x80000000) != 0) ? -1 : 1);
	i0 = (uint32_t)((i0 & (uint32_t)0xfffff) | (uint32_t)0x100000);
	register long long result;
	if (j0 < 20) {
		if (j0 < 0) { return ((j0 < (int32_t)-1) ? 0 : sign); }
		else {
			i0 += (uint32_t)(0x80000 >> j0);
			result = (long long)(i0 >> (20 - j0));
		}
	} else if (j0 < (int32_t)(BITS_PER_LONG_LONG) - 1) {
		if (j0 >= 52) { result = (((long long)i0 << 32) | i1) << (j0 - 52); }
		else {
			uint32_t j = (uint32_t)(i1 + (0x80000000 >> (j0 - 20)));
			if (j < i1) { ++i0; }
			if (j0 == 20) { result = (long long)i0; }
			else { result = ((long long)i0 << (j0 - 20)) | (j >> (52 - j0)); }
		}
	} else { return (long long)x; }  // The number is too large
	return (sign * result);
}


#if SUPPORTS_LONG_DOUBLE
/** Returns an integer that is nearest in value to x, with halfway cases rounded away from zero */
LIB_FUNC MATH_FUNC long long llroundl(const long double x) {
	long_double_shape_t xw_u = { .value = x };
	register uint64_t i0 = xw_u.uparts64.msw;
	register uint64_t i1 = xw_u.uparts64.lsw;
	register int64_t j0 = (int64_t)(((i0 >> 48) & 0x7fff) - 0x3fff);
	register long long sign = (long long)(((i0 & (uint64_t)0x8000000000000000ULL) != 0) ? -1 : 1);
	i0 = (uint64_t)((i0 & 0xffffffffffffULL) | 0x1000000000000ULL);
	register long long result;
	if (PREDICT_LIKELY(j0 < 48)) {
		if (j0 < 0) { return ((j0 < -1) ? 0 : sign); }
		else {
			i0 += (uint64_t)(0x800000000000LL >> j0);
			result = (long long)(((int64_t)i0) >> (48 - j0));
		}
	} else if (j0 < (int64_t)(BITS_PER_LONG_LONG) - 1) {
		if (j0 >= 112) { result = (long long)(((int64_t)i0 << (j0 - 48)) | ((int64_t)i1 << (j0 - 112))); }
		else {
			register uint64_t j = (i1 + (0x8000000000000000ULL >> (uint64_t)(j0 - 48)));
			if (j < i1) { ++i0; }
			if (j0 == 48) { result = (long long)i0; }
			else { result = (long long)((i0 << (uint64_t)(j0 - 48)) | (j >> (uint64_t)(112 - j0))); }
		}
	} else { return (long long)x; }  // The number is too large
	return (long long)(sign * result);
}
#endif


/** Round x towards zero, returning the nearest integral value that is not larger than x */
LIB_FUNC MATH_FUNC float truncf(const float num) {
#   if (defined(ARCHX86) && (CPU_SSE4_1 || CPU_AVX || CPU_SSE2AVX))
	float res;
#      if (CPU_AVX || CPU_SSE2AVX)
	asm ("vroundss $3, %1, %0, %0;" : "=X"(res) : "X"(num));
#      elif CPU_SSE4_1
	asm ("roundss $3, %1, %0;" : "=X"(res) : "X"(num));
#      endif
	return res;
#   elif (defined(ARCHPOWERPC) && defined(_ARCH_PWR5X))
	float z, x = num;
	vasm("friz %0, %1;" "frsp %0, %0;" : "=f"(z) : "f"(x));
	return z;
#   else
	float x = num;
	const float_shape_t xf_u = { .value = x };
	register uint32_t i0 = xf_u.uword;
	register uint32_t sx = (uint32_t)(i0 & (uint32_t)0x80000000);
	register int32_t j0 = (int32_t)((int32_t)((int32_t)(i0 >> 23) & 0xff) - 0x7f);
	if (PREDICT_LIKELY(j0 < 23)) {
		if (j0 < 0) { SET_FLOAT_WORD(x, sx); }  // The number is < 1 so the result is +-0
		else { SET_FLOAT_WORD(x, (sx | (uint32_t)(i0 & (uint32_t)(~(0x7fffff >> j0))))); }
	} else if (j0 == 0x80) { return (x + x); }  // x is inf or NaN
	return x;
#   endif
}


/** Round x towards zero, returning the nearest integral value that is not larger than x */
LIB_FUNC MATH_FUNC double trunc(const double num) {
#   if (defined(ARCHX86) && (CPU_SSE4_1 || CPU_AVX || CPU_SSE2AVX))
	double res;
#      if (CPU_AVX || CPU_SSE2AVX)
	asm ("vroundsd $3, %1, %0, %0;" : "=X"(res) : "X"(num));
#      elif CPU_SSE4_1
	asm ("roundsd $3, %1, %0;" : "=X"(res) : "X"(num));
#      endif
	return res;
#   elif (defined(ARCHPOWERPC) && defined(_ARCH_PWR5X))
	double z, x = num;
	vasm("friz %0, %1;" : "=f"(z) : "f"(x));
	return z;
#   else
	double x = num;
	double_shape_t xw_u = { .value = x };
	register int32_t i0 = (int32_t)xw_u.parts.msw;
	register uint32_t i1 = xw_u.parts.lsw;
	register uint32_t sx = (uint32_t)((uint32_t)i0 & (uint32_t)0x80000000);
	register int32_t j0 = (int32_t)(((i0 >> 20) & 0x7ff) - 0x3ff);
	if (PREDICT_LIKELY(j0 < 20)) {
		if (j0 < 0) {  // The number is < 1 so the result is +-0
			xw_u.parts.msw = sx;
			xw_u.parts.lsw = 0U;
			return (double)xw_u.value;
		} else {
			xw_u.parts.msw = (uint32_t)(sx | (uint32_t)((uint32_t)i0 & (uint32_t)(~(0xfffff >> j0))));
			xw_u.parts.lsw = 0U;
			return xw_u.value;
		}
	} else if (j0 > 51 && j0 == 0x400) {  // x is inf or NaN
		return x + x;
	}
	xw_u.sparts.msw = i0;
	xw_u.parts.lsw = (uint32_t)(i1 & (uint32_t)(~(UINT32_MAX >> (j0 - 20))));
	return xw_u.value;
#   endif
}


#if SUPPORTS_LONG_DOUBLE
/** Round x towards zero, returning the nearest integral value that is not larger than x */
LIB_FUNC MATH_FUNC long double truncl(const long double num) {
	long double x = num;
	const long_double_shape_t x_u = { .value = x };
	register uint64_t i0 = x_u.uparts64.msw;
	register uint64_t i1 = x_u.uparts64.lsw;
	register uint64_t sx = (uint64_t)(i0 & (uint64_t)0x8000000000000000ULL);
	register int32_t j0 = (int32_t)(((i0 >> 48) & 0x7fff) - 0x3fff);
	if (PREDICT_LIKELY(j0 < 48)) {
		if (j0 < 0) { SET_LDOUBLE_WORDS64(x, sx, 0); }  // The number is < 1 so the result is +-0
		else { SET_LDOUBLE_WORDS64(x, (uint64_t)(i0 & (uint64_t)(~(0xffffffffffffULL >> (uint64_t)j0))), 0); }
	} else if (j0 > 111) {
		if (j0 == 0x4000) { return (x + x); }  // x is inf or NaN
	} else { SET_LDOUBLE_WORDS64(x, i0, (uint64_t)(i1 & (uint64_t)(~(UINT64_MAX >> (uint64_t)(j0 - 48))))); }
	return x;
}
#endif


/** Rounds x to an integral value, using the rounding direction specified by fegetround */
LIB_FUNC MATH_FUNC float nearbyintf(const float x) {
	const float_shape_t xf_s = { .value = x };
	register int32_t i0 = xf_s.sword;
	register const int32_t sx = ((i0 >> 31) & 1);
	register const int32_t j0 = (((i0 >> 23) & 0xff) - 0x7f);
	fenv_t env;
	if (PREDICT_LIKELY(j0 < 23)) {
		if (j0 < 0) {
			libc_feholdexceptf(&env);
			float_shape_t tf_u = { .value = (float)((TWO23[sx] + x) - TWO23[sx]) };
			i0 = (int32_t)tf_u.uword;
			raise_flag(tf_u.value);
			libc_fesetenvf(&env);
			tf_u.uword = (uint32_t)(((int32_t)i0 & (int32_t)0x7fffffff) | (int32_t)(sx << 31));
			return (float)tf_u.value;
		}
	} else {
		if (PREDICT_UNLIKELY(j0 == 0x80)) { return (float)(x + x); }  // inf or NaN
		else { return (float)x; }  // x is integral
	}
	libc_feholdexceptf(&env);
	register float t = (float)((TWO23[sx] + x) - TWO23[sx]);
	raise_flag(t);
	libc_fesetenvf(&env);
	return t;
}


/** Rounds x to an integral value, using the rounding direction specified by fegetround */
LIB_FUNC MATH_FUNC double nearbyint(const double x) {
	double_shape_t xh_u = { .value = x };
	register int32_t i0 = (int32_t)xh_u.parts.msw;
	register const uint32_t sx = (uint32_t)((i0 >> 31) & 1);
	register const int32_t j0 = (int32_t)(((i0 >> 20) & 0x7ff) - 0x3ff);
	if (PREDICT_LIKELY(j0 < 52)) {
		if (j0 < 0) {
			fenv_t env;
			libc_feholdexcept(&env);
			double_shape_t th_u = { .value = ((TWO52[sx] + x) - TWO52[sx]) };
			i0 = (int32_t)th_u.parts.msw;
			raise_flag(th_u.value);
			libc_fesetenv(&env);
			th_u.parts.msw = (uint32_t)(((int32_t)i0 & 0x7fffffff) | (sx << 31));
			return (double)th_u.value;
		}
	} else {
		if (PREDICT_UNLIKELY(j0 == 0x400)) { return x + x; }  // inf or NaN
		else { return x; }  // x is integral
	}
	fenv_t env;
	libc_feholdexcept(&env);
	register double t = (TWO52[sx] + x) - TWO52[sx];
	raise_flag(t);
	libc_fesetenv(&env);
	return t;
}


#if SUPPORTS_LONG_DOUBLE
/** Rounds x to an integral value, using the rounding direction specified by fegetround */
LIB_FUNC MATH_FUNC long double nearbyintl(const long double x) {
	const long_double_shape_t xw_u = { .value = x };
	register uint64_t i0 = xw_u.uparts64.msw;
	register const uint64_t sx = (uint64_t)(i0 >> 63);
	register const int64_t j0 = (int64_t)(((i0 >> 48) & 0x7fff) - 0x3fff);
	if (PREDICT_LIKELY(j0 < 112)) {
		if (j0 < 0) {
			fenv_t env;
			feholdexcept(&env);
			register long double t = (long double)((TWO112[sx] + x) - TWO112[sx]);
			raise_flag(t);
			fesetenv(&env);
			GET_LDOUBLE_MSW64(i0, t);
			SET_LDOUBLE_MSW64(t, (uint64_t)((i0 & 0x7fffffffffffffffULL) | (sx << 63)));
			return t;
		}
	} else {
		if (PREDICT_UNLIKELY(j0 == 0x4000)) { return (x + x); }  // inf or NaN
		else { return x; }  // x is integral
	}
	fenv_t env;
	feholdexcept(&env);
	register long double t = (long double)((TWO112[sx] + x) - TWO112[sx]);
	raise_flag(t);
	fesetenv(&env);
	return t;
}
#endif


// REMAINDER

/** Returns the floating-point remainder of x/y (rounded towards zero) */
LIB_FUNC MATH_FUNC float fmodf(const float x, const float y) {
	const float_shape_t xf_u = { .value = x }, yf_u = { .value = y };
	register int32_t hx = (int32_t)xf_u.uword;
	register int32_t hy = (int32_t)yf_u.uword;
	register const int32_t sx = (int32_t)(hx & (int32_t)0x80000000);  // Sign of x
	hx ^= (int32_t)sx;  // |x|
	hy &= 0x7fffffff;  // |y|
	if (hy == 0 || (hx >= 0x7f800000) || (hy > 0x7f800000)) { return ((x * y) / (x * y)); }  // y=0, x not finite, or y is NaN
	else if (hx < hy) { return x; }  // |x|<|y| return x
	else if (hx == hy) { return ZEROF[(uint32_t)sx >> 31]; }  // |x|=|y| return x*0
	register int32_t i, ix, iy;
	if (hx < 0x800000) {  // Subnormal x
		for (ix = -126, i = (hx << 8); i > 0; i <<= 1) { --ix; }
	} else { ix = (hx >> 23) - 127; }
	if (hy < 0x800000) {  // Subnormal y
		for (iy = -126, i = (hy << 8); i >= 0; i <<= 1) { --iy; }
	} else { iy = (hy >> 23) - 127; }
	register int32_t n;
	if (ix >= -126) { hx = 0x800000 | (0x7fffff & hx); }  // Align y to x
	else {  // Subnormal x, shift x to normal
		n = ((-126) - ix);
		hx = (hx << n);
	}
	if (iy >= -126) { hy = (int32_t)(0x800000 | (0x7fffff & hy)); }
	else {  // Subnormal y, shift y to normal
		n = (int32_t)((-126) - iy);
		hy = (hy << n);
	}
	// Fix-point fmod
	n = (int32_t)(ix - iy);
	register int32_t hz;
	while (n--) {
		hz = hx - hy;
		if (hz < 0) { hx += hx; }
		else {
			if (hz == 0) { return ZEROF[(uint32_t)sx >> 31]; }  // Return sign(x)*0
			hx = (hz + hz);
		}
	}
	hz = hx - hy;
	if (hz >= 0) { hx = hz; }
	// Convert back to floating value and restore the sign
	if (hx == 0) { return ZEROF[(uint32_t)sx >> 31]; }  // Return sign(x)*0
	while (hx < 0x800000) {  // Normalize x
		hx += hx;
		--iy;
	}
	register float ret = x;
	if (iy >= -126) {  // Normalize output
		hx = ((hx - 0x800000) | ((iy + 127) << 23));
		SET_FLOAT_SWORD(ret, (hx | sx));
	} else {  // Subnormal output
		n = ((-126) - iy);
		hx >>= n;
		SET_FLOAT_SWORD(ret, (hx | sx));
		ret *= 1.0F;  // Create necessary signal
	}
	return ret;  // Exact output
}
#define __ieee754_fmodf(x, y)   fmodf((x), (y))
#define __fmodf_finite(x, y)   fmodf((x), (y))
#define ieee754_fmodf(x, y)   fmodf((x), (y))
#define fmodf_finite(x, y)   fmodf((x), (y))


/** Returns the floating-point remainder of x/y (rounded towards zero) */
LIB_FUNC MATH_FUNC double fmod(const double x, const double y) {
	double_shape_t xw_u = { .value = x }, yw_u = { .value = y };
	register int32_t hx = (int32_t)xw_u.parts.msw;
	register uint32_t lx = (uint32_t)xw_u.parts.lsw;
	register int32_t hy = (int32_t)yw_u.parts.msw;
	register uint32_t ly = (uint32_t)yw_u.parts.lsw;
	register const int32_t sx = (int32_t)(hx & (int32_t)0x80000000);  // Sign of x
	hx ^= sx;  // |x|
	hy &= (int32_t)0x7fffffff;  // |y|
	if ((hy | (int32_t)ly) == 0 || (hx >= 0x7ff00000) || ((hy | (int32_t)((ly | -ly) >> 31)) > 0x7ff00000)) { return ((x * y) / (x * y)); }  // y=0, x not finite, or y is NaN
	else if (hx <= hy) {
		if ((hx < hy) || (lx < ly)) { return x; }  // |x|<|y| return x
		if (lx == ly) { return ZERO[(uint32_t)sx >> 31]; }  // |x|=|y| return x*0
	}
	register int32_t ix, iy, i;
	if (hx < 0x100000) {  // Subnormal x
		if (hx == 0) {
			for (ix = -1043, i = (int32_t)lx; i > 0; i <<= 1) { --ix; }
		} else {
			for (ix = -1022, i = (int32_t)(hx << 11); i > 0; i <<= 1) { --ix; }
		}
	} else { ix = (int32_t)((hx >> 20) - 1023); }
	if (hy < 0x100000) {  // Subnormal y
		if (hy == 0) {
			for (iy = -1043, i = (int32_t)ly; i > 0; i <<= 1) { --iy; }
		} else {
			for (iy = -1022, i = (int32_t)(hy << 11); i > 0; i <<= 1) { --iy; }
		}
	} else { iy = (int32_t)((hy >> 20) - 1023); }
	register int32_t n;
	if (ix >= -1022) { hx = 0x100000 | (0xfffff & hx); }  // Align y to x
	else {  // Subnormal x, shift x to normal
		n = (int32_t)((-1022) - ix);
		if (n <= 31) {
			hx = (int32_t)((hx << n) | (int32_t)(lx >> (32 - n)));
			lx <<= (uint32_t)n;
		} else {
			hx = (int32_t)(lx << (n - 32));
			lx = 0;
		}
	}
	if (iy >= -1022) { hy = 0x100000 | (0xfffff & hy); }
	else {  // Subnormal y, shift y to normal
		n = (int32_t)((-1022) - iy);
		if (n <= 31) {
			hy = (int32_t)((hy << n) | (int32_t)(ly >> (32 - n)));
			ly <<= (uint32_t)n;
		} else {
			hy = (int32_t)(ly << (n - 32));
			ly = 0;
		}
	}
	// Fix-point fmod
	register int32_t hz;
	register uint32_t lz;
	n = ix - iy;
	while (n--) {
		hz = hx - hy;
		lz = lx - ly;
		if (lx < ly) { --hz; }
		if (hz < 0) {
			hx = (int32_t)((hx + hx) + (int32_t)(lx >> 31));
			lx += lx;
		} else {
			if ((hz | (int32_t)lz) == 0) { return ZERO[(uint32_t) sx >> 31]; }  // Return sign(x)*0
			hx = (int32_t)((hz + hz) + (int32_t)(lz >> 31));
			lx = lz + lz;
		}
	}
	hz = hx - hy;
	lz = lx - ly;
	if (lx < ly) { --hz; }
	if (hz >= 0) { hx = hz; lx = lz; }
	// Convert back to floating value and restore the sign
	if ((hx | (int32_t)lx) == 0) { return ZERO[(uint32_t)sx >> 31]; }  // Return sign(x)*0
	while (hx < 0x100000) {  // Normalize x
		hx = (int32_t)((hx + hx) + ((int32_t)lx >> 31));
		lx += lx;
		--iy;
	}
	register double ret = x;
	if (iy >= -1022) {  // Normalize output
		hx = (int32_t)((hx - 0x100000) | ((iy + 1023) << 20));
		xw_u.parts.msw = (uint32_t)(hx | sx);
		xw_u.parts.lsw = (uint32_t)lx;
		ret = xw_u.value;
	} else {  // Subnormal output
		n = (-1022) - iy;
		if (n <= 20) {
			lx = (uint32_t)((lx >> (uint32_t)n) | (uint32_t)((uint32_t)hx << (uint32_t)(32 - n)));
			hx >>= n;
		} else if (n <= 31) {
			lx = (uint32_t)((uint32_t)(hx << (32 - n)) | (uint32_t)(lx >> n));
			hx = sx;
		} else {
			lx = (uint32_t)(hx >> (n - 32));
			hx = sx;
		}
		xw_u.parts.msw = (uint32_t)(hx | sx);
		xw_u.parts.lsw = (uint32_t)lx;
		ret = xw_u.value * 1.0;  // Create necessary signal
	}
	return ret;  // Exact output
}
#define __ieee754_fmod(x, y)   fmod((x), (y))
#define __fmod_finite(x, y)   fmod((x), (y))
#define ieee754_fmod(x, y)   fmod((x), (y))
#define fmod_finite(x, y)   fmod((x), (y))


#if SUPPORTS_LONG_DOUBLE
/** Returns the floating-point remainder of x/y (rounded towards zero) */
LIB_FUNC MATH_FUNC long double fmodl(const long double x, const long double y) {
	const long_double_shape_t xw_u = { .value = x }, yw_u = { .value = y };
	register int64_t hx = (int64_t)xw_u.uparts64.msw;
	register uint64_t lx = xw_u.uparts64.lsw;
	register int64_t hy = (int64_t)yw_u.uparts64.msw;
	register uint64_t ly = yw_u.uparts64.lsw;
	register const int64_t sx = (int64_t)(hx & (int64_t)0x8000000000000000LL);  // Sign of x
	hx ^= sx;  // |x|
	hy &= 0x7fffffffffffffffLL;  // |y|
	if ((hy | (int64_t)ly) == 0 || (hx >= 0x7fff000000000000LL) || ((hy | (int64_t)((ly | (-ly)) >> 63)) > 0x7fff000000000000LL)) { return ((x * y) / (x * y)); }  // y=0, x not finite, or y is NaN
	else if (hx <= hy) {
		if ((hx < hy) || (lx < ly)) { return x; }  // |x|<|y| return x
		else if (lx == ly) { return ZEROL[(uint64_t)sx >> 63]; }  // |x|=|y| return x*0
	}
	register int64_t ix, iy, i;
	if (hx < 0x1000000000000LL) {  // Subnormal x
		if (hx == 0) {
			for (ix = -16431, i = (int64_t)lx; i > 0; i <<= 1) { --ix; }
		} else {
			for (ix = -16382, i = (int64_t)(hx << 15); i > 0; i <<= 1) { --ix; }
		}
	} else { ix = (int64_t)((hx >> 48) - 0x3fff); }
	if (hy < 0x1000000000000LL) {  // Subnormal y
		if (hy == 0) {
			for (iy = -16431, i = (int64_t)ly; i > 0; i <<= 1) { --iy; }
		} else {
			for (iy = -16382, i = (int64_t)(hy << 15); i > 0; i <<= 1) { --iy; }
		}
	} else iy = (int64_t)((hy >> 48) - 0x3fff);
	// Align y to x
	register int64_t n;
	if (ix >= -16382) { hx = (int64_t)(0x1000000000000LL | (0xffffffffffffLL & hx)); }
	else {  // Subnormal x, shift x to normal
		n = (-16382) - ix;
		if (n <= 63) {
			hx = (int64_t)((hx << n) | (int64_t)(lx >> (64 - n)));
			lx <<= n;
		} else {
			hx = (int64_t)(lx << (n - 64));
			lx = 0;
		}
	}
	if (iy >= (-16382)) { hy = (int64_t)(0x1000000000000LL | (0xffffffffffffLL & hy)); }
	else {  // Subnormal y, shift y to normal
		n = ((-16382) - iy);
		if (n <= 63) {
			hy = (int64_t)((hy << n) | (int64_t)(ly >> (uint64_t)(64 - n)));
			ly <<= n;
		} else {
			hy = (int64_t)(ly << (uint64_t)(n - 64));
			ly = 0;
		}
	}
	// Fix-point fmod
	register int64_t hz;
	register uint64_t lz;
	n = ix - iy;
	while (n--) {
		hz = hx - hy;
		lz = lx - ly;
		if (lx < ly) { --hz; }
		if (hz < 0) {
			hx = (int64_t)((hx + hx) + (int64_t)(lx >> 63));
			lx += lx;
		} else {
			if ((hz | (int64_t)lz) == 0) { return ZEROL[(uint64_t)sx >> 63]; }  // Return sign(x)*0
			hx = (int64_t)((hz + hz) + (int64_t)(lz >> 63));
			lx = (lz + lz);
		}
	}
	hz = hx - hy;
	lz = lx - ly;
	if (lx < ly) { --hz; }
	if (hz >= 0) { hx = hz; lx = lz; }
	// Convert back to floating value and restore the sign
	if ((hx | (int64_t)lx) == 0) { return ZEROL[(uint64_t)sx >> 63]; }  // Return sign(x)*0
	while (hx < 0x1000000000000LL) {  // Normalize x
		hx = (int64_t)((hx + hx) + (int64_t)(lx >> 63));
		lx += lx;
		--iy;
	}
	long double ret = x;
	if (iy >= -16382) {  // Normalize output
		hx = ((hx - 0x1000000000000LL) | (int64_t)((iy + 16383) << 48));
		SET_LDOUBLE_WORDS64(ret, (hx | sx) ,lx);
	} else {  // Subnormal output
		n = (-16382) - iy;
		if (n <= 48) {
			lx = (uint64_t)((lx >> n) | (uint64_t)(hx << (64 - n)));
			hx >>= n;
		} else if (n <= 63) {
			lx = (uint64_t)((uint64_t)(hx << (64 - n)) | (lx >> n));
			hx = sx;
		} else {
			lx = (uint64_t)(hx >> (n - 64));
			hx = sx;
		}
		SET_LDOUBLE_WORDS64(ret, (uint64_t)(hx | sx), lx);
		ret *= 1.0L;  // Create necessary signal
	}
	return ret;  // Exact output
}
#   define __ieee754_fmodl(x, y)   fmodl((x), (y))
#   define __fmodl_finite(x, y)   fmodl((x), (y))
#   define ieee754_fmodl(x, y)   fmodl((x), (y))
#   define fmodl_finite(x, y)   fmodl((x), (y))
#endif


/** Returns the floating-point remainder of x/p (rounded to nearest) */
LIB_FUNC MATH_FUNC float remainderf(const float xnum, const float pnum) {
	float x = xnum, p = pnum;
	float_shape_t xf_u = { .value = x }, pf_u = { .value = p };
	register int32_t hx = (int32_t)xf_u.uword;
	register int32_t hp = (int32_t)pf_u.uword;
	register const uint32_t sx = (uint32_t)(hx & (int32_t)0x80000000);
	hp &= (int32_t)0x7fffffff;
	hx &= (int32_t)0x7fffffff;
	if (hp == 0) { return ((x * p) / (x * p)); }  // p = 0
	else if ((hx >= 0x7f800000) || ((hp > 0x7f800000))) { return ((x * p) / (x * p)); }  // x not finite or p is NaN
	else if (hp <= 0x7effffff) { x = fmodf(x, (p + p)); }  // Now x < 2p
	if ((hx - hp) == 0) { return (0.0F * x); }
	x = fabsf(x);
	p = fabsf(p);
	if (hp < 0x01000000) {
		if ((float)(x + x) > p) {
			x -= p;
			if ((float)(x + x) >= p) { x -= p; }
		}
	} else {
		register float p_half = (0.5F * p);
		if (x > p_half) {
			x -= p;
			if (x >= p_half) { x -= p; }
		}
	}
	xf_u.value = x;
	hx = (int32_t)xf_u.uword;
	xf_u.uword = (uint32_t)((uint32_t)hx ^ sx);
	return (float)xf_u.value;
}
#define __ieee754_remainderf(x, y)   remainderf((x), (y))
#define ieee754_remainderf(x, y)   remainderf((x), (y))
#define __remainderf_finite(x, y)   remainderf((x), (y))
#define remainderf_finite(x, y)   remainderf((x), (y))
#define __remainderf(x, y)   remainderf((x), (y))


/** Returns the floating-point remainder of x/y (rounded to nearest) */
LIB_FUNC MATH_FUNC double remainder(const double xnum, const double ynum) {
	double x = xnum, y = ynum;
	ieee754_remainder_double u = { .x = x }, t = { .x = x }, w = { { 0, 0 } }, v = { { 0, 0 } }, ww = { { 0, 0 } }, r;
	register const int kx = (u.i[HIGH_HALF] & 0x7fffffff);  // No sign for x
	t.i[HIGH_HALF] &= 0x7fffffff;  // No sign for y
	register const int ky = t.i[HIGH_HALF];
	register double z;
	if (PREDICT_LIKELY(kx < 0x7fe00000 && ky < 0x7ff00000 && ky >= 0x3500000)) {  // |x| < 2^1023 and 2^-970 < |y| < 2^1024
		if (kx + 0x100000 < ky) { return x; }
		else if ((kx - 0x1500000) < ky) {
			z = (double)(x / t.x);
			v.i[HIGH_HALF] = t.i[HIGH_HALF];
			register const double d = (double)((z + _BIG.x) - _BIG.x);
			register const double xx = (double)((x - d * v.x) - d * (t.x - v.x));
			if ((d - z) != 0.5 && (d - z) != (-0.5)) {
				return (double)((xx != 0) ? xx : ((x > 0) ? _ZERO.x : _NZERO.x));
			} else if (fabs(xx) > (0.5 * t.x)) {
				return (double)((z > d) ? (xx - t.x) : (xx + t.x));
			} else { return xx; }
		} else {  // (kx < (ky + 0x01500000))
			r.x = (1.0 / t.x);
			register const int n = t.i[HIGH_HALF];
			register const int nn = (n & 0x7ff00000) + 0x1400000;
			w.i[HIGH_HALF] = n;
			ww.x = t.x - w.x;
			register int l = ((int)(kx - nn) & (int)0xfff00000);
			register const int n1 = ww.i[HIGH_HALF];
			register const int m1 = r.i[HIGH_HALF];
			register double d;
			while (l > 0) {
				r.i[HIGH_HALF] = m1 - l;
				z = (u.x * r.x);
				w.i[HIGH_HALF] = n + l;
				ww.i[HIGH_HALF] = ((n1) ? (n1 + l) : n1);
				d = (z + _BIG.x) - _BIG.x;
				u.x = (u.x - d * w.x) - d * ww.x;
				l = (u.i[HIGH_HALF] & 0x7ff00000) - nn;
			}
			r.i[HIGH_HALF] = m1;
			w.i[HIGH_HALF] = n;
			ww.i[HIGH_HALF] = n1;
			z = (u.x * r.x);
			d = (z + _BIG.x) - _BIG.x;
			u.x = (u.x - d * w.x) - d * ww.x;
			if (fabs(u.x) < (0.5 * t.x)) {
				return (double)((u.x != 0) ? u.x : ((x > 0) ? _ZERO.x : _NZERO.x));
			} else if (fabs(u.x) > (0.5 * t.x)) {
				return (double)((d > z) ? (u.x + t.x) : (u.x - t.x));
			} else {
				d = (double)((((double)(u.x / t.x)) + _BIG.x) - _BIG.x);
				return (double)((u.x - d * w.x) - d * ww.x);
			}
		}
	} else {  // (kx<0x7fe00000&&ky<0x7ff00000&&ky>=0x03500000)
		if (PREDICT_LIKELY(kx < 0x7fe00000 && ky < 0x7ff00000 && (ky > 0 || t.i[LOW_HALF] != 0))) {
			y = fabs(y) * _T128.x;
			z = remainder(x, y) * _T128.x;
			z = remainder(z, y) * _TM128.x;
			return z;
		} else if ((kx & 0x7ff00000) == 0x7fe00000 && ky < 0x7ff00000 && (ky > 0 || t.i[LOW_HALF] != 0)) {
			y = fabs(y);
			z = (2.0 * remainder((0.5 * x), y));
			register const double d = fabs(z);
			if (d <= fabs(d - y)) { return z; }
			else { return (double)((z > 0) ? (z - y) : (z + y)); }
		} else {  // x is too big
			if (ky == 0 && t.i[LOW_HALF] == 0) { return ((x * y) / (x * y)); }  // y = 0
			else if (kx >= 0x7ff00000 || (ky > 0x7ff00000 || (ky == 0x7ff00000 && t.i[LOW_HALF] != 0))) { return ((x * y) / (x * y)); }  // x not is finite or y is NaN
			else { return x; }
		}
	UNREACHABLE
	}
}
#define __ieee754_remainder(x, y)   remainder((x), (y))
#define ieee754_remainder(x, y)   remainder((x), (y))
#define __remainder_finite(x, y)   remainder((x), (y))
#define remainder_finite(x, y)   remainder((x), (y))
#define __remainder(x, y)   remainder((x), (y))


#if SUPPORTS_LONG_DOUBLE
/** Returns the floating-point remainder of x/p (rounded to nearest) */
LIB_FUNC MATH_FUNC long double remainderl(const long double xnum, const long double pnum) {
	long double x = xnum, p = pnum;
	long_double_shape_t xw_u = { .value = x }, pw_u = { .value = p };
	register int64_t hx = (int64_t)xw_u.uparts64.msw;
	register uint64_t lx = xw_u.uparts64.lsw;
	register int64_t hp = (int64_t)pw_u.uparts64.msw;
	register const uint64_t lp = pw_u.uparts64.lsw;
	register const int64_t sx = (int64_t)(hx & (int64_t)0x8000000000000000LL);
	hp &= (int32_t)0x7fffffffffffffffLL;
	hx &= (int32_t)0x7fffffffffffffffLL;
	if ((hp | (int64_t)lp) == 0) { return ((x * p) / (x * p)); }  // p = 0
	else if ((hx >= 0x7fff000000000000LL) || ((hp >= 0x7fff000000000000LL) && (((hp - 0x7fff000000000000LL) | (int64_t)lp) != 0))) { return ((x * p) / (x * p)); }  // x is not finite or p is NaN
	else if (hp <= 0x7ffdffffffffffffLL) { x = fmodl(x, (p + p)); }  // Now x < 2p
	if (((hx - hp) | (int64_t)(lx - lp)) == 0) { return (0.0L * x); }
	x = fabsl(x);
	p = fabsl(p);
	if (hp < (int64_t)0x2000000000000LL) {
		if ((long double)(x + x) > p) {
			x -= p;
			if ((long double)(x + x) >= p) { x -= p; }
		}
	} else {
		register long double p_half = (long double)(0.5L * p);
		if (x > p_half) {
			x -= p;
			if (x >= p_half) { x -= p; }
		}
	}
	xw_u.value = x;
	hx = (int64_t)xw_u.uparts64.msw;
	xw_u.uparts64.msw = (uint64_t)(hx ^ sx);
	return (long double)xw_u.value;
}
#   define __ieee754_remainderl(x, y)   remainderl((x), (y))
#   define ieee754_remainderl(x, y)   remainderl((x), (y))
#   define __remainderl_finite(x, y)   remainderl((x), (y))
#   define remainderl_finite(x, y)   remainderl((x), (y))
#   define __remainderl(x, y)   remainderl((x), (y))
#endif


/** Returns the same as remainder, but it additionally stores the quotient internally used to determine its result in the object pointed by quot; The value pointed by quot contains the congruent modulo with at least 3 bits of the integral quotient x/y */
LIB_FUNC float remquof(const float xnum, const float ynum, int* quo) {
	float x = xnum, y = ynum;
	const float_shape_t xf_u = { .value = x }, yf_u = { .value = y };
	register int32_t hx = (int32_t)xf_u.uword;
	register int32_t hy = (int32_t)yf_u.uword;
	register const int32_t sx = (int32_t)(hx & (int32_t)0x80000000);
	register int qs = (int)(sx ^ (int32_t)(hy & (int32_t)0x80000000));
	hy &= (int32_t)0x7fffffff;
	hx &= (int32_t)0x7fffffff;
	if (hy == 0 || ((hx >= 0x7f800000) || (hy > 0x7f800000))) { return ((x * y) / (x * y)); }  // y = 0, x is not finite, or y is NaN
	else if (hy <= 0x7dffffff) { x = fmodf(x, (8.0F * y)); }  // Now x < 8y
	if ((hx - hy) == 0) {
		*quo = (qs ? -1 : 1);
		return (0.0F * x);
	}
	x = fabsf(x);
	y = fabsf(y);
	register int cquo = 0;
	if (hy <= 0x7e7fffff && x >= (4.0F * y)) {
		x -= (4.0F * y);
		cquo += 4;
	}
	if (hy <= 0x7effffff && x >= (y + y)) {
		x -= (2.0F * y);
		cquo += 2;
	}
	if (hy < 0x01000000) {
		if ((float)(x + x) > y) {
			x -= y;
			++cquo;
			if ((float)(x + x) >= y) {
				x -= y;
				++cquo;
			}
		}
	} else {
		float y_half = (0.5F * y);
		if (x > y_half) {
			x -= y;
			++cquo;
			if (x >= y_half) {
				x -= y;
				++cquo;
			}
		}
	}
	*quo = (qs ? (-cquo) : cquo);
	if (x == 0.0F) { x = 0.0F; }  // Ensure correct sign of zero result in round-downward mode
	if (sx) { x = (-x); }
	return x;
}


/** Returns the same as remainder, but it additionally stores the quotient internally used to determine its result in the object pointed by quot; The value pointed by quot contains the congruent modulo with at least 3 bits of the integral quotient x/y */
LIB_FUNC double remquo(const double xnum, const double ynum, int* quo) {
	double x = xnum, y = ynum;
	const double_shape_t xh_u = { .value = x }, yh_u = { .value = y };
	register const int signx = (int)((xh_u.parts.msw & 0x80000000) >> 31);
	register const int signy = (int)((yh_u.parts.msw & 0x80000000) >> 31);
	register const int signres = (int)((signx ^ signy) ? -1 : 1);
	*quo = (signres * (int)(lrint((fabs((double)(x / y)))) & 0x7f));
	return remainder(x, y);
}


#if SUPPORTS_LONG_DOUBLE
/** Returns the same as remainder, but it additionally stores the quotient internally used to determine its result in the object pointed by quot; The value pointed by quot contains the congruent modulo with at least 3 bits of the integral quotient x/y */
LIB_FUNC long double remquol(const long double xnum, const long double ynum, int* quo) {
	long double x = xnum, y = ynum;
	const long_double_shape_t xw_u = { .value = x }, yw_u = { .value = y };
	register int64_t hx = (int64_t)xw_u.uparts64.msw;
	register const uint64_t lx = xw_u.uparts64.lsw;
	register int64_t hy = (int64_t)yw_u.uparts64.msw;
	register const uint64_t ly = yw_u.uparts64.lsw;
	register const uint64_t sx = (uint64_t)((uint64_t)hx & 0x8000000000000000ULL);
	register const uint64_t qs = (uint64_t)(sx ^ (uint64_t)((uint64_t)hy & 0x8000000000000000ULL));
	hy &= 0x7fffffffffffffffLL;
	hx &= 0x7fffffffffffffffLL;
	if ((hy | (int64_t)ly) == 0 || ((hx >= 0x7fff000000000000LL) || ((hy >= 0x7fff000000000000LL) && (((hy - 0x7fff000000000000LL) | (int64_t)ly) != 0)))) { return ((x * y) / (x * y)); }  // y = 0, x is not finite, or y is NaN
	else if (hy <= 0x7ffbffffffffffffLL) { x = fmodl(x, (8.0L * y)); }  // Now x < 8y
	if (((hx - hy) | (int64_t)(lx - ly)) == 0) {
		*quo = (qs ? -1 : 1);
		return (0.0L * x);
	}
	x = fabsl(x);
	y = fabsl(y);
	register int cquo = 0;
	if (hy <= 0x7ffcffffffffffffLL && x >= (4.0L * y)) {
		x -= (long double)(4.0L * y);
		cquo += 4;
	}
	if (hy <= 0x7ffdffffffffffffLL && x >= (2.0L * y)) {
		x -= (long double)(2.0L * y);
		cquo += 2;
	}
	if (hy < 0x2000000000000LL) {
		if ((long double)(x + x) > y) {
			x -= y;
			++cquo;
			if ((long double)(x + x) >= y) {
				x -= y;
				++cquo;
			}
		}
	} else {
		register long double y_half = (long double)(0.5L * y);
		if (x > y_half) {
			x -= y;
			++cquo;
			if (x >= y_half) {
				x -= y;
				++cquo;
			}
		}
	}
	*quo = (qs ? (-cquo) : cquo);
	if (x == 0.0L) { x = 0.0L; }  // Ensure correct sign of zero result in round-downward mode
	if (sx) { x = (-x); }
	return x;
}
#endif


// NEXTTOWARD & NEXTAFTER

/** Returns the next representable value after x in the direction of y */
LIB_FUNC MATH_FUNC float nextafterf(const float xnum, const float y) {
	float x = xnum;
	const float_shape_t xf_s = { .value = x }, yf_s = { .value = y };
	register int32_t hx = xf_s.sword;
	register int32_t hy = yf_s.sword;
	register const int32_t ix = (int32_t)(hx & 0x7fffffff);  // |x|
	register const int32_t iy = (int32_t)(hy & 0x7fffffff);  // |y|
	if ((ix > 0x7f800000) || (iy > 0x7f800000)) { return (x + y); }  // x or y is nan
	else if (x == y) { return y; }  // x=y, return y
	else if (ix == 0) {  // x == 0
		SET_FLOAT_WORD(x, ((uint32_t)hy & (uint32_t)0x80000000) | 1);  // return +-minsubnormal
		raise_flag(x);  // Raise underflow flag
		return x;
	}
	if (hx >= 0) {  // x > 0
		if (hx > hy) { --hx; }  // x > y, x -= ulp
		else { ++hx; }  // x < y, x += ulp
	} else {  // x < 0
		if (hy >= 0 || hx > hy) { --hx; }  // x < y, x -= ulp
		else { ++hx; }  // x > y, x += ulp
	}
	hy = (hx & 0x7f800000);
	if (hy >= 0x7f800000) {
		register float u = (x + x);  // Overflow
		raise_flag(u);
	} else if (hy < 0x800000) {
		register float u = (x * x);  // Underflow
		raise_flag(u);  // Raise underflow flag
	}
	SET_FLOAT_SWORD(x, hx);
	return x;
}


/** Returns the next representable value after x in the direction of y */
LIB_FUNC MATH_FUNC double nextafter(const double xnum, const double ynum) {
	double x = xnum, y = ynum;
	double_shape_t xw_u = { .value = x };
	const double_shape_t yw_u = { .value = y };
	register int32_t hx = (int32_t)xw_u.parts.msw;
	register uint32_t lx = xw_u.parts.lsw;
	register int32_t hy = (int32_t)yw_u.parts.msw;
	register const uint32_t ly = yw_u.parts.lsw;
	register const int32_t ix = (int32_t)(hx & 0x7fffffff);  // |x|
	register const int32_t iy = (int32_t)(hy & 0x7fffffff);  // |y|
	if (((ix >= 0x7ff00000) && ((ix - 0x7ff00000) | (int32_t)lx) != 0) || ((iy >= 0x7ff00000) && ((iy - 0x7ff00000) | (int32_t)ly) != 0)) { return x + y; }  // x or y is nan
	else if (x == y) { return x; }  // x=y, return x
	else if (((uint32_t)ix | lx) == 0) {  // x == 0
		xw_u.parts.msw = (uint32_t)((uint32_t)hy & (uint32_t)0x80000000);
		xw_u.parts.lsw = (uint32_t)1;
		x = xw_u.value;  // Return +-minsubnormal
		y = x * x;
		if (PREDICT_LIKELY(y == x)) { return y; }  // Raise underflow flag
		else { return x; }
	} else if (hx >= 0) {  // x > 0
		if (hx > hy || ((hx == hy) && (lx > ly))) {  // x > y, x -= ulp
			if (lx == 0) { --hx; }
			--lx;
		} else {  // x < y, x += ulp
			++lx;
			if (lx == 0) { ++hx; }
		}
	} else {  // x < 0
		if (hy >= 0 || hx > hy || ((hx == hy) && (lx > ly))) {  // x < y, x -= ulp
			if (lx == 0) { --hx; }
			--lx;
		} else {  // x > y, x += ulp
			++lx;
			if (lx == 0) { ++hx; }
		}
	}
	hy = (hx & 0x7ff00000);
	if (hy >= 0x7ff00000) { return x + x; }  // Overflow
	else if (hy < 0x100000) {  // Underflow
		y = (double)(x * x);
		if (y != x) {  // Raise underflow flag
			xw_u.parts.msw = (uint32_t)hx;
			xw_u.parts.lsw = (uint32_t)lx;
			return (double)xw_u.value;
		}
	}
	xw_u.parts.msw = (uint32_t)hx;
	xw_u.parts.lsw = (uint32_t)lx;
	return (double)xw_u.value;
}


#if SUPPORTS_LONG_DOUBLE
/** Returns the next representable value after x in the direction of y */
LIB_FUNC MATH_FUNC long double nextafterl(const long double xnum, const long double y) {
	long double x = xnum;
	long_double_shape_t xw_u = { .value = x };
	const long_double_shape_t yw_u = { .value = y };
	register int64_t hx = (int64_t)xw_u.uparts64.msw;
	register uint64_t lx = xw_u.uparts64.lsw;
	register int64_t hy = (int64_t)yw_u.uparts64.msw;
	register const uint64_t ly = yw_u.uparts64.lsw;
	register const int64_t ix = (int64_t)(hx & 0x7fffffffffffffffLL);  // |x|
	register const int64_t iy = (int64_t)(hy & 0x7fffffffffffffffLL);  // |y|
	if (((ix >= 0x7fff000000000000LL) && ((ix - 0x7fff000000000000LL) | (int64_t)lx) != 0) || ((iy >= 0x7fff000000000000LL) && ((iy - 0x7fff000000000000LL) | (int64_t)ly) != 0)) { return (x + y); }  // x or y is nan
	if (x == y) { return y; }  // x=y, return y
	else if (((uint64_t)ix | lx) == 0) {  // x == 0
		SET_LDOUBLE_WORDS64(x, (uint64_t)(hy & (int64_t)0x8000000000000000LL), 1);  // Return +-minsubnormal
		raise_flag(x);  // Raise underflow flag
		return x;
	} else if (hx >= 0) {  // x > 0
		if (hx > hy || ((hx == hy) && (lx > ly))) {  // x > y, x -= ulp
			if (lx == 0) { --hx; }
			--lx;
		} else {  // x < y, x += ulp
			lx++;
			if (lx == 0) { ++hx; }
		}
	} else {  // x < 0
		if (hy >= 0 || hx > hy || ((hx == hy) && (lx > ly))) {  // x < y, x -= ulp
			if (lx == 0) { --hx; }
			--lx;
		} else {  // x > y, x += ulp
			lx++;
			if (lx == 0) { ++hx; }
		}
	}
	hy = (int64_t)(hx & 0x7fff000000000000LL);
	if (hy == 0x7fff000000000000LL) {
		register long double u = (long double)(x + x);  // Overflow
		raise_flag(u);
	} else if (hy == 0) {
		register long double u = (long double)(x * x);  // Underflow
		raise_flag(u);  // Raise underflow flag
	}
	xw_u.uparts64.msw = (uint64_t)hx;
	xw_u.uparts64.lsw = (uint64_t)lx;
	return (long double)xw_u.value;
}
#endif


/** Returns the next representable value after x in the direction of y; This function is like nextafter, but with a more precise y */
LIB_FUNC MATH_FUNC float nexttowardf(const float xnum, const long double y) {
	float x = xnum;
	float_shape_t xf_u = { .value = x };
	register int32_t hx = (int32_t)xf_u.uword;
	const long_double_shape_t y_u = { .value = y };
	register int64_t hy = (int64_t)y_u.uparts64.msw;
	register const uint64_t ly = y_u.uparts64.lsw;
	register const int32_t ix = (int32_t)(hx & 0x7fffffff);  // |x|
	register const int64_t iy = (int64_t)(hy & 0x7fffffffffffffffLL);  // |y|
	if ((ix > (int32_t)0x7f800000) || ((iy >= 0x7fff000000000000LL) && ((iy - 0x7fff000000000000LL) | (int64_t)ly) != 0)) { return (float)(x + y); }  // x or y is nan
	else if (((long double)x) == y) { return (float)y; }  // x=y, return y
	else if (ix == 0) {  // x == 0
		const float_shape_t uf_u = { .uword = (uint32_t)(((uint64_t)(hy >> 32) & (uint32_t)0x80000000) | 1) };  // Return +-minsub
		x = (float)uf_u.value;
		raise_flag(uf_u.value);  // Raise underflow flag
		return (float)x;
	} else if (hx >= 0) {  // x > 0
		if (x > y) { --hx; }  // x -= ulp
		else { ++hx; }  // x < y, x += ulp
	} else {  // x < 0
		if (x < y) { --hx; }  // x < y, x -= ulp
		else { ++hx; }  // x > y, x += ulp
	}
	hy = hx & 0x7f800000;
	if (hy >= 0x7f800000) { return (float)(x + x); }  // Overflow
	else if (hy < 0x800000) {
		register float u = (x * x);  // Underflow
		raise_flag(u);  // Raise underflow flag
	}
	xf_u.uword = (uint32_t)hx;
	return (float)xf_u.value;
}


/** Returns the next representable value after x in the direction of y; This function is like nextafter, but with a more precise y */
LIB_FUNC MATH_FUNC double nexttoward(const double xnum, const long double y) {
	double x = xnum;
	double_shape_t xw_u = { .value = x };
	register int32_t hx = (int32_t)xw_u.parts.msw;
	register uint32_t lx = xw_u.parts.lsw;
	const long_double_shape_t yw_u = { .value = y };
	register int64_t hy = (int64_t)yw_u.uparts64.msw;
	register const uint64_t ly = yw_u.uparts64.lsw;
	register const int32_t ix = (int32_t)(hx & 0x7fffffff);  // |x|
	register const int64_t iy = (int64_t)(hy & 0x7fffffffffffffffLL);  // |y|
	if (((ix >= 0x7ff00000) && ((ix - 0x7ff00000) | (int32_t)lx) != 0) || ((iy >= 0x7fff000000000000LL) && ((int64_t)(iy - 0x7fff000000000000LL) | (int64_t)ly) != 0)) { return (double)(x + y); }  // x or y is nan
	else if ((long double) x == y) { return (double)y; }  // x=y, return y
	else if (((uint64_t)ix | lx) == 0) {  // x == 0
		xw_u.parts.msw = (uint32_t)((hy >> 32) & 0x80000000);
		xw_u.parts.lsw = (uint32_t)1;
		raise_flag(xw_u.value);  // Raise underflow flag
		return (double)xw_u.value;  // Return +-minsub
	} else if (hx >= 0) {  // x > 0
		if (x > y) {  // x -= ulp
			if (lx == 0) { --hx; }
			--lx;
		} else {  // x < y, x += ulp
			++lx;
			if (lx == 0) { ++hx; }
		}
	} else {  // x < 0
		if (x < y) {  // x -= ulp
			if (lx == 0) { --hx; }
			--lx;
		} else {  // x > y, x += ulp
			++lx;
			if (lx == 0) { ++hx; }
		}
	}
	hy = hx & 0x7ff00000;
	if (hy >= 0x7ff00000) {
		x += x;  // Overflow
		if ((FLT_EVAL_METHOD != 0) && (FLT_EVAL_METHOD != 1)) { asm (";" : "+m"(x)); }  // Force conversion to double
		return x;
	} else if (hy < 0x100000) {
		register double u = (double)(x * x);  // Underflow
		raise_flag(u);  // Raise underflow flag
	}
	xw_u.parts.msw = (uint32_t)hx;
	xw_u.parts.lsw = lx;
	return (double)xw_u.value;
}


#if SUPPORTS_LONG_DOUBLE
/** Returns the next representable value after x in the direction of y; This function is like nextafter, but with a more precise y */
LIB_FUNC MATH_FUNC long double nexttowardl(const long double xnum, const long double y) {
	long double x = xnum;
	long_double_shape_t xw_u = { .value = x };
	const long_double_shape_t yw_u = { .value = y };
	register int64_t hx = (int64_t)xw_u.uparts64.msw;
	register uint64_t lx = xw_u.uparts64.lsw;
	register int64_t hy = (int64_t)yw_u.uparts64.msw;
	register const uint64_t ly = yw_u.uparts64.lsw;
	register const int64_t ix = (int64_t)(hx & 0x7fffffffffffffffLL);  // |x|
	register const int64_t iy = (int64_t)(hy & 0x7fffffffffffffffLL);  // |y|
	if (((ix >= 0x7fff000000000000LL) && ((ix - 0x7fff000000000000LL) | (int64_t)lx) != 0) || ((iy >= 0x7fff000000000000LL) && ((iy - 0x7fff000000000000LL) | (int64_t)ly) != 0)) { return (x + y); }  // x or y is nan
	else if (x == y) { return y; }  // x=y, return y
	else if (((uint64_t)ix | lx) == 0) {  // x == 0
		xw_u.uparts64.msw = (uint64_t)((uint64_t)hy & (uint64_t)0x8000000000000000ULL);  // Return +-minsubnormal
		xw_u.uparts64.lsw = (uint64_t)1;
		raise_flag(x);  // Raise underflow flag
		return (long double)xw_u.value;
	} else if (hx >= 0) {  // x > 0
		if (hx > hy || ((hx == hy) && (lx > ly))) {  // x > y, x -= ulp
			if (lx == 0) { --hx; }
			--lx;
		} else {  // x < y, x += ulp
			++lx;
			if (lx == 0) { ++hx; }
		}
	} else {  // x < 0
		if (hy >= 0 || hx > hy || ((hx == hy) && (lx > ly))) {  // x < y, x -= ulp
			if (lx == 0) { --hx; }
			--lx;
		} else {  // x > y, x += ulp
			++lx;
			if (lx == 0) { ++hx; }
		}
	}
	hy = (int64_t)(hx & 0x7fff000000000000LL);
	if (hy == 0x7fff000000000000LL) {
		register long double u = (long double)(x + x);  // Overflow
		raise_flag(u);
	} else if (hy == 0) {
		register long double u = (long double)(x * x);  // Underflow
		raise_flag(u);  // Raise underflow flag
	}
	xw_u.uparts64.msw = (uint64_t)hx;
	xw_u.uparts64.lsw = lx;
	return (long double)xw_u.value;
}
#endif


// MOD

/** Breaks x into an integral and a fractional part; The integer part is stored in the object pointed by `iptr`, and the fractional part is returned by the function */
LIB_FUNC float modff(const float xnum, float* restrict iptr) {
	float x = xnum;
	const float_shape_t xf_u = { .value = x };
	register const int32_t i0 = (int32_t)xf_u.uword;
	register const int32_t j0 = (int32_t)(((i0 >> 23) & 0xff) - 0x7f);  // Exponent of x
	if (PREDICT_LIKELY(j0 < 23)) {  // Integer part in x
		if (j0 < 0) {  // |x|<1
			SET_FLOAT_WORD(*iptr, ((uint32_t)i0 & (uint32_t)0x80000000));  // *iptr = +-0
			return x;
		} else {
			register uint32_t i = (uint32_t)((0x7fffff) >> j0);
			if (PREDICT_LIKELY(((((uint32_t)i0) & i) == 0))) {  // x is integral
				register uint32_t ix;
				*iptr = x;
				float_shape_t ixf_u = { .value = x };
				ix = ixf_u.uword;
				ixf_u.uword = (uint32_t)(ix & (uint32_t)0x80000000);  // return +-0
				return ixf_u.value;
			} else {
				SET_FLOAT_WORD(*iptr, ((uint32_t)i0 & (~i)));
				return (x - *iptr);
			}
		}
	} else {  // No fraction part
		*iptr = (x * ONEF);
		if (j0 == 0x80 && (int32_t)(i0 & 0x7fffff)) { return (x * ONEF); }  // Handle NaNs separately
		SET_FLOAT_WORD(x, ((uint32_t)i0 & (uint32_t)0x80000000));  // return +-0
		return x;
	}
}


/** Breaks x into an integral and a fractional part; The integer part is stored in the object pointed by `iptr`, and the fractional part is returned by the function */
LIB_FUNC double modf(const double xnum, double* restrict iptr) {
	double x = xnum;
	double_shape_t xw_u = { .value = x };
	register const int32_t i0 = (int32_t)xw_u.parts.msw;
	register const int32_t i1 = (int32_t)xw_u.parts.lsw;
	register const int32_t j0 = (int32_t)(((i0 >> 20) & 0x7ff) - 0x3ff);  // Exponent of x
	if (PREDICT_LIKELY(j0 < 20)) {  // Integer part in high x
		if (j0 < 0) {  // |x|<1
			xw_u.parts.msw = (uint32_t)(i0 & (int32_t)0x80000000);
			xw_u.parts.lsw = (uint32_t)0;  // *iptr = +-0
			return (double)xw_u.value;
		} else {
			register const uint32_t i = (uint32_t)(0xfffff >> j0);
			if (PREDICT_LIKELY(((uint32_t)(((uint32_t)i0) & i) | (uint32_t)i1) == 0)) {  // x is integral
				*iptr = x;
				xw_u.parts.msw = (uint32_t)(i0 & (int32_t)0x80000000);
				xw_u.parts.lsw = (uint32_t)0;  // return +-0
				return (double)xw_u.value;  // return +-0
			} else {
				xw_u.parts.msw = (uint32_t)((uint32_t)i0 & (uint32_t)(~i));
				xw_u.parts.lsw = (uint32_t)0;
				return (double)(x - xw_u.value);
			}
		}
	} else if (j0 > 51) {  // No fraction part
		*iptr = (x * 1.0);
		if (j0 == 0x400 && ((int32_t)(i0 & (int32_t)0xfffff) | i1)) { return x * 1.0; }  // Handle NaNs separately
		xw_u.parts.msw = (uint32_t)((uint32_t)i0 & (uint32_t)0x80000000);
		xw_u.parts.lsw = (uint32_t)0;
		return (double)xw_u.value;  // Return +-0
	} else {  // Fraction part in low x
		register uint32_t i = (uint32_t)((uint32_t)(UINT32_MAX)) >> (j0 - 20);
		if (PREDICT_LIKELY((i1 & (int32_t)i) == 0)) {  // x is integral
			*iptr = x;
			double_shape_t ixw_u = { .parts.msw = (uint32_t)((uint32_t)i0 & (uint32_t)0x80000000) };
			ixw_u.parts.lsw = (uint32_t)0;
			return (double)ixw_u.value;  // Return +-0
		} else {
			xw_u.parts.msw = (uint32_t)i0;
			xw_u.parts.lsw = (uint32_t)(((uint32_t)i1) & (~i));
			return (double)(x - xw_u.value);
		}
	}
	UNREACHABLE
}


#if SUPPORTS_LONG_DOUBLE
/** Breaks x into an integral and a fractional part; The integer part is stored in the object pointed by `iptr`, and the fractional part is returned by the function */
LIB_FUNC long double modfl(const long double xnum, long double* restrict iptr) {
	long double x = xnum;
	const long_double_shape_t xw_u = { .value = x };
	register const int64_t i0 = (int64_t)xw_u.uparts64.msw;
	register const int64_t i1 = (int64_t)xw_u.uparts64.lsw;
	register const int64_t j0 = (int64_t)(((i0 >> 48) & 0x7fff) - 0x3fff);  // Exponent of x
	if (PREDICT_LIKELY(j0 < 48)) {  // Integer part in high x
		if (j0 < 0) {  // |x|<1
			SET_LDOUBLE_WORDS64(*iptr, (uint64_t)((uint64_t)i0 & 0x8000000000000000ULL), 0);
			return x;
		} else {
			register const uint64_t i = (uint64_t)(0xffffffffffffLL >> j0);
			if (PREDICT_LIKELY(((i0 & (int64_t)i) | i1) == 0)) {  // x is integral
				*iptr = x;
				SET_LDOUBLE_WORDS64(x, (uint64_t)((uint64_t)i0 & 0x8000000000000000ULL) ,0);
				return x;  // Return +-0
			} else {
				SET_LDOUBLE_WORDS64(*iptr, ((uint64_t)i0 & (~i)), 0);
				return (long double)(x - *iptr);
			}
		}
	} else if (j0 > 111) {  // No fraction part
		*iptr = (x * 1.0L);
		if (j0 == 0x4000 && ((int64_t)(i0 & 0xffffffffffffLL) | i1)) { return (x * 1.0L); }  // Handle NaNs separately
		SET_LDOUBLE_WORDS64(x, (uint64_t)(i0 & (int64_t)0x8000000000000000LL), 0);
		return x;  // Return +-0
	} else {  // Fraction part in low x
		register uint64_t i = (uint64_t)(((int64_t)-1LL) >> (int64_t)(j0 - 48));
		if (PREDICT_LIKELY((i1 & (int64_t)i) == 0)) {  // x is integral
			*iptr = x;
			SET_LDOUBLE_WORDS64(x, (uint64_t)(i0 & (int64_t)0x8000000000000000LL), 0);
			return x;  // Return +-0
		} else {
			SET_LDOUBLE_WORDS64(*iptr, i0, ((uint64_t)i1 & (~i)));
			return (long double)(x - *iptr);
		}
	}
}
#endif


// MATH ERROR-HANDLING FUNCTIONS


/** Handle errors for a libm function as specified by TYPE, with arguments X and Y, returning the appropriate return value for that function

@section Mapping for exception cases
 - 1: acos(|x|>1)
 - 2: asin(|x|>1)
 - 3: atan2(+-0,+-0)
 - 4: hypot overflow
 - 5: cosh overflow
 - 6: exp overflow
 - 7: exp underflow
 - 8: y0(0)
 - 9: y0(-ve)
 - 10: y1(0)
 - 11: y1(-ve)
 - 12: yn(0)
 - 13: yn(-ve)
 - 14: lgamma(finite) overflow
 - 15: lgamma(-integer)
 - 16: log(0)
 - 17: log(x<0)
 - 18: log10(0)
 - 19: log10(x<0)
 - 20: pow(0.0,0.0)
 - 21: pow(x,y) overflow
 - 22: pow(x,y) underflow
 - 23: pow(0,negative)
 - 24: pow(neg,non-integral)
 - 25: sinh(finite) overflow
 - 26: sqrt(negative)
 - 27: fmod(x,0)
 - 28: remainder(x,0)
 - 29: acosh(x<1)
 - 30: atanh(|x|>1)
 - 31: atanh(|x|=1)
 - 32: scalb overflow
 - 33: scalb underflow
 - 34: j0(|x|>X_TLOSS)
 - 35: y0(x>X_TLOSS)
 - 36: j1(|x|>X_TLOSS)
 - 37: y1(x>X_TLOSS)
 - 38: jn(|x|>X_TLOSS, n)
 - 39: yn(x>X_TLOSS, n)
 - 40: tgamma(finite) overflow
 - 41: tgamma(-integer)
 - 42: pow(NaN,0.0)
 - 43: +0**neg
 - 44: exp2 overflow
 - 45: exp2 underflow
 - 46: exp10 overflow
 - 47: exp10 underflow
 - 48: log2(0)
 - 49: log2(x<0)
 - 50: tgamma(+-0)
*/
LIB_FUNC double __kernel_standard(const double x, const double y, const int type) {
#   define kernel_standard_CSTR(func)   ((const char*)(type < 100 ? func : (type < 200 ? func "f" : func "l")))
	exc.arg1 = x;
	exc.arg2 = y;
	double dy = y;
	switch (type) {
		case 1:
		case 101:
		case 201:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("acos");
			exc.err = EDOM;
			exc.retval = NAN;
			break;
		case 2:
		case 102:
		case 202:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("asin");
			exc.err = EDOM;
			exc.retval = NAN;
			break;
		case 3:
		case 103:
		case 203:
			exc.arg1 = y;
			exc.arg2 = x;
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("atan2");
			exc.err = EDOM;
			exc.retval = HUGE;
			break;
		case 4:
		case 104:
		case 204:
			exc.type = OVERFLOW;
			exc.name = kernel_standard_CSTR("hypot");
			exc.err = EOVERFLOW;
			exc.retval = HUGE_VAL;
			break;
		case 5:
		case 105:
		case 205:
			exc.type = OVERFLOW;
			exc.name = kernel_standard_CSTR("cosh");
			exc.err = EOVERFLOW;
			exc.retval = HUGE_VAL;
			break;
		case 6:
		case 106:
		case 206:
			exc.type = OVERFLOW;
			exc.name = kernel_standard_CSTR("exp");
			exc.err = EOVERFLOW;
			exc.retval = HUGE_VAL;
			break;
		case 7:
		case 107:
		case 207:
			exc.type = UNDERFLOW;
			exc.name = kernel_standard_CSTR("exp");
			exc.err = ERANGE;
			exc.retval = 0.0;
			break;
		case 8:
		case 108:
		case 208:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("y0");
			exc.err = EDOM;
			exc.retval = -HUGE_VAL;
			break;
		case 9:
		case 109:
		case 209:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("y0");
			exc.err = EDOM;
			exc.retval = NAN;
			break;
		case 10:
		case 110:
		case 210:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("y1");
			exc.err = EDOM;
			exc.retval = -HUGE_VAL;
			break;
		case 11:
		case 111:
		case 211:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("y1");
			exc.err = EDOM;
			exc.retval = NAN;
			break;
		case 12:
		case 112:
		case 212:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("yn");
			exc.err = EDOM;
			exc.retval = ((x < 0 && ((int) x & 1) != 0) ? HUGE_VAL : -HUGE_VAL);
			break;
		case 13:
		case 113:
		case 213:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("yn");
			exc.err = EDOM;
			exc.retval = NAN;
			break;
		case 14:
		case 114:
		case 214:
			exc.type = OVERFLOW;
			exc.name = kernel_standard_CSTR("lgamma");
			exc.err = EOVERFLOW;
			exc.retval = HUGE_VAL;
			break;
		case 15:
		case 115:
		case 215:
			exc.type = SING;
			exc.name = kernel_standard_CSTR("lgamma");
			exc.err = EDOM;
			exc.retval = HUGE_VAL;
			break;
		case 16:
		case 116:
		case 216:
			exc.type = SING;
			exc.name = kernel_standard_CSTR("log");
			exc.err = EDOM;
			exc.retval = -HUGE_VAL;
			break;
		case 17:
		case 117:
		case 217:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("log");
			exc.err = EDOM;
			exc.retval = NAN;
			break;
		case 18:
		case 118:
		case 218:
			exc.type = SING;
			exc.name = kernel_standard_CSTR("log10");
			exc.err = EDOM;
			exc.retval = -HUGE_VAL;
			break;
		case 19:
		case 119:
		case 219:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("log10");
			exc.err = EDOM;
			exc.retval = NAN;
			break;
		case 20:
		case 120:
		case 220:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("pow");
			exc.err = EDOM;
			exc.retval = 1.0;
			break;
		case 21:
		case 121:
		case 221:
			exc.type = OVERFLOW;
			exc.name = kernel_standard_CSTR("pow");
			exc.err = ERANGE;
			dy *= 0.5;
			if (x < 0.0 && __rint(dy) != dy) { exc.retval = -HUGE_VAL; }
			else { exc.retval = HUGE_VAL; }
			break;
		case 22:
		case 122:
		case 222:
			exc.type = UNDERFLOW;
			exc.name = kernel_standard_CSTR("pow");
			exc.err = ERANGE;
			dy *= 0.5;
			if (x < 0.0 && __rint(dy) != dy) { exc.retval = -0.0; }
			else { exc.retval = 0.0; }
			break;
		case 23:
		case 123:
		case 223:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("pow");
			exc.err = EDOM;
			exc.retval = -HUGE_VAL;
			break;
		case 43:
		case 143:
		case 243:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("pow");
			exc.err = EDOM;
			exc.retval = HUGE_VAL;
			break;
		case 24:
		case 124:
		case 224:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("pow");
			exc.err = EDOM;
			exc.retval = 0.0 / 0.0;
			break;
		case 25:
		case 125:
		case 225:
			exc.type = OVERFLOW;
			exc.name = kernel_standard_CSTR("sinh");
			exc.err = ERANGE;
			exc.retval = ((x > 0.0) ? HUGE_VAL : -HUGE_VAL);
			break;
		case 26:
		case 126:
		case 226:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("sqrt");
			exc.err = EDOM;
			exc.retval = 0.0 / 0.0;
			break;
		case 27:
		case 127:
		case 227:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("fmod");
			exc.err = EDOM;
			exc.retval = 0.0 / 0.0;
			break;
		case 28:
		case 128:
		case 228:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("remainder");
			exc.err = EDOM;
			exc.retval = 0.0 / 0.0;
			break;
		case 29:
		case 129:
		case 229:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("acosh");
			exc.err = EDOM;
			exc.retval = 0.0 / 0.0;
			break;
		case 30:
		case 130:
		case 230:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("atanh");
			exc.err = EDOM;
			exc.retval = 0.0 / 0.0;
			break;
		case 31:
		case 131:
		case 231:
			exc.type = SING;
			exc.name = kernel_standard_CSTR("atanh");
			exc.err = EDOM;
			exc.retval = x / 0.0;
			break;
		case 32:
		case 132:
		case 232:
			exc.type = OVERFLOW;
			exc.name = kernel_standard_CSTR("scalb");
			exc.err = ERANGE;
			exc.retval = (x > 0.0 ? HUGE_VAL : -HUGE_VAL);
			break;
		case 33:
		case 133:
		case 233:
			exc.type = UNDERFLOW;
			exc.name = kernel_standard_CSTR("scalb");
			exc.err = ERANGE;
			exc.retval = copysign(0.0, x);
			break;
		case 34:
		case 134:
		case 234:
			exc.type = TLOSS;
			exc.name = kernel_standard_CSTR("j0");
			exc.err = ERANGE;
			exc.retval = 0.0;
			break;
		case 35:
		case 135:
		case 235:
			exc.type = TLOSS;
			exc.name = kernel_standard_CSTR("y0");
			exc.err = ERANGE;
			exc.retval = 0.0;
			break;
		case 36:
		case 136:
		case 236:
			exc.type = TLOSS;
			exc.name = kernel_standard_CSTR("j1");
			exc.err = ERANGE;
			exc.retval = 0.0;
			break;
		case 37:
		case 137:
		case 237:
			exc.type = TLOSS;
			exc.name = kernel_standard_CSTR("y1");
			exc.err = ERANGE;
			exc.retval = 0.0;
			break;
		case 38:
		case 138:
		case 238:
			exc.type = TLOSS;
			exc.name = kernel_standard_CSTR("jn");
			exc.err = ERANGE;
			exc.retval = 0.0;
			break;
		case 39:
		case 139:
		case 239:
			exc.type = TLOSS;
			exc.name = kernel_standard_CSTR("yn");
			exc.err = ERANGE;
			exc.retval = 0.0;
			break;
		case 40:
		case 140:
		case 240:
			exc.type = OVERFLOW;
			exc.name = kernel_standard_CSTR("tgamma");
			exc.err = ERANGE;
			exc.retval = copysign(HUGE_VAL, x);
			break;
		case 41:
		case 141:
		case 241:
			exc.type = SING;
			exc.name = kernel_standard_CSTR("tgamma");
			exc.err = EDOM;
			exc.retval = NAN;
			break;
		case 42:
		case 142:
		case 242:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("pow");
			exc.err = EDOM;
			exc.retval = x;
			break;
		case 44:
		case 144:
		case 244:
			exc.type = OVERFLOW;
			exc.name = kernel_standard_CSTR("exp2");
			exc.err = ERANGE;
			exc.retval = HUGE_VAL;
			break;
		case 45:
		case 145:
		case 245:
			exc.type = UNDERFLOW;
			exc.name = kernel_standard_CSTR("exp2");
			exc.err = ERANGE;
			exc.retval = 0.0;
			break;
		case 46:
		case 146:
		case 246:
			exc.type = OVERFLOW;
			exc.name = kernel_standard_CSTR("exp10");
			exc.err = ERANGE;
			exc.retval = HUGE_VAL;
			break;
		case 47:
		case 147:
		case 247:
			exc.type = UNDERFLOW;
			exc.name = kernel_standard_CSTR("exp10");
			exc.err = ERANGE;
			exc.retval = 0.0;
			break;
		case 48:
		case 148:
		case 248:
			exc.type = SING;
			exc.name = kernel_standard_CSTR("log2");
			exc.err = EDOM;
			exc.retval = -HUGE_VAL;
			break;
		case 49:
		case 149:
		case 249:
			exc.type = DOMAIN;
			exc.name = kernel_standard_CSTR("log2");
			exc.err = EDOM;
			exc.retval = NAN;
			break;
		case 50:
		case 150:
		case 250:
			exc.type = SING;
			exc.name = kernel_standard_CSTR("tgamma");
			exc.err = ERANGE;
			exc.retval = copysign(HUGE_VAL, x);
			break;
		default:
			break;
	}
#   undef kernel_standard_CSTR
	if (exc.err != 0) { matherr(&exc); }
	return exc.retval;
}


/** Handle errors for a libm function as specified by TYPE, with arguments X and Y, returning the appropriate return value for that function */
LIB_FUNC float __kernel_standard_f(const float x, const float y, const int type) {
	return (float)__kernel_standard((double)x, (double)y, type);
}


#if SUPPORTS_LONG_DOUBLE
/** Handle errors for a libm function as specified by TYPE, with arguments X and Y, returning the appropriate return value for that function */
LIB_FUNC long double __kernel_standard_l(const long double x, const long double y, const int type) {
	fenv_t env;
	feholdexcept(&env);
	double dx = (double)x;
	double dy = (double)y;
	math_force_eval(dx);
	math_force_eval(dy);
	fesetenv(&env);
	switch (type) {
		case 221:
			exc.arg1 = dx;
			exc.arg2 = dy;
			exc.type = OVERFLOW;
			exc.name = (const char*)"powl";
			exc.err = ERANGE;
			dy *= 0.5;
			if (dx < 0.0 && rintl(dy) != dy) { exc.retval = -HUGE_VAL; }
			else { exc.retval = HUGE_VAL; }
			matherr(&exc);
			return exc.retval;
		case 222:
			exc.arg1 = dx;
			exc.arg2 = dy;
			exc.type = UNDERFLOW;
			exc.name = (const char*)"powl";
			exc.err = ERANGE;
			dy *= 0.5;
			if (dx < 0.0 && rintl(dy) != dy) { exc.retval = -0.0; }
			else { exc.retval = 0.0; }
			matherr(&exc);
			return exc.retval;
		default:
			return __kernel_standard(dx, dy, type);
	}
}
#endif


// IBM LONG DOUBLE FUNCTIONS

/** Extract high double */
#define ldbl_high(x)   ((double)x)


#if LDBL_EQ_FLOAT128


#   ifdef ARCHPOWERPC


LIB_FUNC MATH_FUNC long double ldbl_pack_ppc(const double a, const double aa) {
	register double xh asm ("fr1") xh = a;
	register double xl asm ("fr2") xl = aa;
	register long double x asm ("fr1");
	asm (";" : "=f"(x) : "f"(xh), "f"(xl));
	return x;
}
#      define ldbl_pack(a, aa)   ldbl_pack_ppc((a), (aa))


LIB_FUNC void ldbl_unpack_ppc(const long double l, double* restrict a, double* restrict aa) {
	register long double x asm ("fr1") = l;
	register double xh asm ("fr1");
	register double xl asm ("fr2");
	asm (";" : "=f"(xh), "=f"(xl) : "f"(x));
	*a = xh;
	*aa = xl;
}
#      define ldbl_unpack(l, a, aa)   ldbl_unpack_ppc((l), (a), (aa))


#   else


/** Pack/Unpack/Cononicalize and find the nearbyint of long double implemented as double double */
LIB_FUNC MATH_FUNC long double default_ldbl_pack(const double a, const double aa) {
	const union ibm_extended_long_double u = { .d[0].d = a, .d[1].d = aa };
	// u.d[1].d = aa;
	return u.e;
}
#      define ldbl_pack(a, aa)   default_ldbl_pack((a), (aa))


LIB_FUNC void default_ldbl_unpack(const long double l, double* restrict a, double* restrict aa) {
	const union ibm_extended_long_double u = { .e = l };
	*a = u.d[0].d;
	*aa = u.d[1].d;
}
#      define ldbl_unpack(l, a, aa)   default_ldbl_unpack((l), (a), (aa))


#   endif


/** Convert a finite long double to canonical form; Does not handle +/-Inf properly */
LIB_FUNC void ldbl_canonicalize(double* restrict a, double* restrict aa) {
	const double xh = *a + *aa;
	const double xl = (*a - xh) + *aa;
	*a = xh;
	*aa = xl;
}


/** Simple inline nearbyint function */
LIB_FUNC MATH_FUNC double ldbl_nearbyint(const double x) {
	register double a = x;
	if (PREDICT_LIKELY((fabs(a) < 0x1.0P+52))) {
		if (PREDICT_LIKELY((a > 0.0))) {
			a += 0x1.0P+52;
			a -= 0x1.0P+52;
		} else if (a < 0.0) {
			a = 0x1.0P+52 - a;
			a = -(a - 0x1.0P+52);
		}
	}
	return a;
}


#endif


// SCAL FUNCTIONS

LIB_FUNC MATH_FUNC float scalbnf(const float fnum, const int num) {
#   ifdef ARCHX86
	float ret;
	asm ("fscale;" : "=t"(ret) : "0"(fnum), "u"((float)num));
	return ret;
#   else
	register int n = num;
	register float x = fnum;
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	const uint32_t hx = ix & 0x7fffffff;
	int32_t k = (int32_t)(hx >> 23);
	if (FLT_UWORD_IS_ZERO(hx)) { return x; }
	else if (!FLT_UWORD_IS_FINITE(hx)) { return x + x; }
	else if (FLT_UWORD_IS_SUBNORMAL(hx)) {
		x = (x * 3.355443200E+7F);
		GET_FLOAT_WORD(ix, x);
		k = ((ix & 0x7f800000) >> 23) - 25;
		if (n < -50000) { return TINYF * x; }
	}
	k += n;
	if (k > FLT_LARGEST_EXP) { return (HUGEF * copysignf(HUGEF, x)); }
	else if (k > 0) { SET_FLOAT_WORD(x, ((unsigned int)((unsigned int)ix & 0x807fffff) | (unsigned int)(k << 23))); return x; }
	if (k < FLT_SMALLEST_EXP) {
		if (n > OVERFLOW_INT) { return (HUGEF * copysignf(HUGEF, x)); }
		else { return (TINYF * copysignf(TINYF, x)); }
	}
	k += 25;
	SET_FLOAT_WORD(x, ((unsigned int)((unsigned int)ix & 0x807fffff) | (unsigned int)(k << 23)));
	return x * 2.9802322388E-8F;
#   endif
}
#define ldexpf(x, n)   scalbnf((x), (n))
#define __scalbnf(x, n)   scalbnf((x), (n))


LIB_FUNC MATH_FUNC double scalbn(const double x, const int exp) {
#   ifdef ARCHX86
	double ret;
	asm ("fscale;" : "=t"(ret) : "0"(x), "u"((double)exp));
	return ret;
#   else
	return (double)scalbnf((float)fnum, num);
#   endif
}
#define ldexp(x, n)   scalbn((x), (n))
#define __scalbn(x, n)   scalbn((x), (n))


#if IS_LDBL_64
LIB_FUNC MATH_FUNC long double scalbnl(const long double fnum, const int num) {
	return (long double)scalbn((double)fnum, num);
}
#   define ldexpl(x, n)   scalbnl((x), (n))
#   define __scalbnl(x, n)   scalbnl((x), (n))
#else
LIB_FUNC MATH_FUNC long double scalbnl(const long double fnum, const int num) {
	register int n = num;
	register long double x = fnum;
	if (n > 16383) {
		x *= 0x1.0P+16383L;
		n -= 16383;
		if (n > 16383) {
			x *= 0x1.0P+16383L;
			n -= 16383;
			if (n > 16383) { n = 16383; }
		}
	} else if (n < -16382) {
		x *= 0x1.0P-16382L;
		n += 16382;
		if (n < -16382) {
			x *= 0x1.0P-16382L;
			n += 16382;
			if (n < -16382) { n = -16382; }
		}
	}
	long_double_shape_t u = { .value = 1.0L };
	u.uparts16.w0 = (uint16_t)(0x3fff + n);
	return x * u.value;
}
#   define ldexpl(x, n)   scalbnl((x), (n))
#   define __scalbnl(x, n)   scalbnl((x), (n))
#endif


LIB_FUNC MATH_FUNC float scalblnf(const float fnum, const long n) {
	register float x = fnum;
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	int32_t k = ((ix & 0x7f800000) >> 23);
	if (k == 0) {
		if ((ix & 0x7fffffff) == 0) { return x; }
		x *= 3.355443200E+7F;
		GET_FLOAT_WORD(ix,x);
		k = (((ix & 0x7f800000) >> 23) - 25);
	}
	if (k == 0xff) { return x + x; }
	k += (int32_t)n;
	if (n > 50000 || k > 0xfe) { return HUGEF * copysignf(HUGEF, x); }
	else if (n < -50000) { return TINYF * copysignf(TINYF, x); }
	else if (k > 0) { SET_FLOAT_WORD(x, ((unsigned int)((unsigned int)ix & 0x807fffff) | (unsigned int)(k << 23))); return x; }
	else if (k <= -25) { return TINYF * copysignf(TINYF, x); }
	k += 25;
	SET_FLOAT_WORD(x, ((unsigned int)((unsigned int)ix & 0x807fffff) | (unsigned int)(k << 23)));
	return x * 2.9802322388E-8F;
}
#define __scalblnf(x, n)   scalblnf((x), (n))


LIB_FUNC MATH_FUNC double scalbln(const double fnum, const long n) {
	register double x = fnum;
	int32_t hx, lx;
	EXTRACT_SIGNED_WORDS(hx, lx, x);
	int32_t k = ((hx & 0x7ff00000) >> 20);
	if (k == 0) {
		if ((lx | (hx & 0x7fffffff)) == 0) { return x; }
		x *= 1.80143985094819840000E+16;
		GET_HIGH_SIGNED_WORD(hx, x);
		k = ((hx & 0x7ff00000) >> 20) - 54;
	}
	if (k == 0x7ff) { return x + x; }
	k += (int32_t)n;
	if (n > 50000 || k >  0x7fe) { return HUGE * copysign(HUGE, x); }
	else if (n < -50000) { return TINY * copysign(TINY, x); }
	else if (k > 0) { SET_HIGH_WORD(x, ((unsigned int)((uint32_t)hx & 0x800fffff) | (unsigned int)(k << 20))); return x; }
	else if (k <= -54) { return TINY * copysign(TINY, x); }
	k += 54;
	SET_HIGH_WORD(x, (unsigned int)(((unsigned int)hx & 0x800fffff) | (unsigned int)(k << 20)));
	return x * 5.55111512312578270212E-17;
}
#define __scalbln(x, n)   scalbln((x), (n))


#if LDBL_EQ_DBL
LIB_FUNC MATH_FUNC long double scalblnl(const long double x, const long n) {
	return scalbln((double)x, n);
}
#   define __scalblnl(x, n)   scalblnl((x), (n))
#else
LIB_FUNC MATH_FUNC long double scalblnl(const long double x, const long n) {
	if (n > INT_MAX) { return scalbnl(x, (int)INT_MAX); }
	else if (n < INT_MIN) { return scalbnl(x, (int)INT_MIN); }
}
#   define __scalblnl(x, n)   scalblnl((x), (n))
#endif


// SGN FUNCTIONS

/** Signum function - extract sign */
LIB_FUNC MATH_FUNC signed int sgn_int(const signed int num) {
	return (num < 0 ? -1 : (num > 0 ? 1 : 0));
}


/** Signum function - extract sign */
LIB_FUNC MATH_FUNC float sgnf(const float num) {
	if (num < 0.0F) { return -1.0F; }
	else if (num > 0.0F) { return 1.0F; }
	else if (num == -0.0F) { return -0.0F; }
	return 0.0F;
}


/** Signum function - extract sign */
LIB_FUNC MATH_FUNC double sgn(const double num) {
	if (num < 0.0) { return -1.0; }
	else if (num > 0.0) { return 1.0; }
	else if (num == -0.0) { return -0.0; }
	return 0.0;
}


#if SUPPORTS_LONG_DOUBLE
/** Signum function - extract sign */
LIB_FUNC MATH_FUNC long double sgnl(const long double num) {
	if (num < 0.0L) { return -1.0L; }
	else if (num > 0.0L) { return 1.0L; }
	else if (num == -0.0L) { return -0.0L; }
	return 0.0L;
}
#endif


// POLYNOMIAL FUNCTIONS

/** Generate a Polynomial and then evaluate the equation; if n=4, then c[4]*x^4 + c[3]*x^3 + c[2]*x^2 + c[1]*x + c[0] */
LIB_FUNC MATH_FUNC double __poly(const double x, const size_t n, const double* restrict c) {
	register double ret = 0.0;
	register size_t i = n;
	double val = *(c + n);
	do { ret = ((ret * x) + val--); } while (i--);
	return ret;
}


#if (!LDBL_EQ_DBL)
/** Polynomial evaluator: P[0] x^n  +  P[1] x^(n-1)  +  ...  +  P[n] */
LIB_FUNC MATH_FUNC long double __polevll(const long double x, const long double* restrict P, const int len) {
	register int n = len;
	long double val = *(P + len);
	long double y = val++;
	do { y = y * x + val++; } while (--n);
	return y;
}


/** Polynomial evaluator: x^n  +  P[0] x^(n-1)  +  P[1] x^(n-2)  +  ...  +  P[n] */
LIB_FUNC MATH_FUNC long double __p1evll(const long double x, const long double* restrict P, const int len) {
	register int n = len - 1;
	long double val = *(P + len);
	register long double y = x + val++;
	do { y = y * x + val++; } while (--n);
	return y;
}
#endif


// POWER FUNCTIONS

LIB_FUNC MATH_FUNC float __ieee754_powf(const float x, const float y) {
	float z, p_h, p_l;
	float t1, t2, r, s, t, u, v, w;
	int32_t i, j, k, n, hx, hy, is;
	GET_FLOAT_WORD(hx, x);
	GET_FLOAT_WORD(hy, y);
	int32_t ix = hx & 0x7fffffff;
	int32_t iy = hy & 0x7fffffff;
	if (FLT_UWORD_IS_ZERO(iy)) { return 1.0F; }
	else if (FLT_UWORD_IS_NAN(ix) || FLT_UWORD_IS_NAN(iy)) {
		if (ix == 0x3f800000) { return 1.0F; }
		else { return NANF; }
	}
	int32_t yisint = 0;
	if (hx < 0) {
		if (iy >= 0x4b800000) { yisint = 2; }
		else if (iy >= 0x3f800000) {
			k = (iy >> 23) - 0x7f;
			j = iy >> (23 - k);
			if ((j << (23 - k)) == iy) { yisint = 2 - (j & 1); }
		}
	}
	if (FLT_UWORD_IS_INFINITE(iy)) {
		if (ix == 0x3f800000) { return 1.0F; }
		else if (ix > 0x3f800000) { return ((hy >= 0) ? y : 0.0F); }
		else { return (hy < 0) ? -y : 0.0F; }
	} else if (iy == 0x3f800000) {
		if (hy < 0) { return 1.0F / x; }
		else { return x; }
	} else if (hy == 0x40000000) { return x * x; }
	else if (hy == 0x3f000000 && hx >= 0) { return __ieee754_sqrtf(x); }
	float ax = fabsf(x);
	if (FLT_UWORD_IS_INFINITE(ix) || FLT_UWORD_IS_ZERO(ix) || ix == 0x3f800000) {
		z = ax;
		if (hy < 0) { z = 1.0F / z; }
		if (hx < 0) {
			if (((ix - 0x3f800000) | yisint) == 0) { z = (z - z) / (z - z); }
			else if (yisint == 1) { z = -z; }
		}
		return z;
	} else if (((((uint32_t)hx >> 31) - 1) | (uint32_t)yisint) == 0) { return (x - x) / (x - x); }
	if (iy > 0x4d000000) {
		if (ix < 0x3f7ffff8) { return (hy < 0) ? HUGEF_SQ : TINYF_SQ; }
		else if (ix > 0x3f800007) { return (hy > 0) ? HUGEF_SQ : TINYF_SQ; }
		t = ax - 1;
		w = (t * t) * (0.5F - t * (0.333333333333F - t * 0.25F));
		u = 1.4426879883F * t;
		v = t * 7.0526075433E-6F - w * M_LOG2EF;
		t1 = u + v;
		GET_FLOAT_WORD(is, t1);
		SET_FLOAT_WORD(t1, ((uint32_t)is & (uint32_t)0xfffff000));
		t2 = (v - (t1 - u));
	} else {
		float s2, s_h, s_l, t_h, t_l;
		n = 0;
		if (FLT_UWORD_IS_SUBNORMAL(ix)) {
			ax *= 16777216.0F;
			n -= 24;
			GET_FLOAT_WORD(ix, ax);
		}
		n += ((ix) >> 23) - 0x7f;
		j = ix & 0x7fffff;
		ix = j | 0x3f800000;
		if (j <= 0x1cc471) { k = 0; }
		else if (j < 0x5db3d7) { k = 1; }
		else {
			k = 0;
			n += 1;
			ix -= 0x800000;
		}
		SET_FLOAT_SWORD(ax, ix);
		const float align64 bpf[2] = { 1.0F, 1.5F };
		const float align64 dp_hf[2] = { 0.0F, 5.84960938E-1F };
		const float align64 dp_lf[2] = { 0.0F, 1.56322085E-6F };
		u = ax - bpf[k];
		v = 1.0F / (ax + bpf[k]);
		s = u * v;
		s_h = s;
		GET_FLOAT_WORD(is, s_h);
		SET_FLOAT_WORD(s_h, ((uint32_t)is & (uint32_t)0xfffff000));
		SET_FLOAT_WORD(t_h, (uint32_t)(((uint32_t)ix >> 1) | 0x20000000) + 0x40000 + ((uint32_t)k << 21));
		t_l = ax - (t_h - bpf[k]);
		s_l = v * ((u - s_h * t_h) - s_h * t_l);
		s2 = s * s;
		r = s2 * s2 * (6.0000002384E-1F + s2 * (4.2857143283E-1F + s2 * (3.3333334327E-1F + s2 * (2.7272811532E-1F + s2 * (2.3066075146E-1F + s2 * 2.0697501302E-1F)))));
		r += s_l * (s_h + s);
		s2 = s_h * s_h;
		t_h = 3.0F + s2 + r;
		GET_FLOAT_WORD(is, t_h);
		SET_FLOAT_WORD(t_h, ((uint32_t)is & (uint32_t)0xfffff000));
		t_l = r - ((t_h - 3.0F) - s2);
		u = s_h * t_h;
		v = s_l * t_h + t_l * s;
		p_h = u + v;
		GET_FLOAT_WORD(is, p_h);
		SET_FLOAT_WORD(p_h, ((uint32_t)is & (uint32_t)0xfffff000));
		p_l = v - (p_h - u);
		const float z_h = 9.6179199219E-1F * p_h;
		const float z_l = 4.7017383622E-6F * p_h + p_l * 9.6179670095E-1F + dp_lf[k];
		t = (float)n;
		t1 = (((z_h + z_l) + dp_hf[k]) + t);
		GET_FLOAT_WORD(is, t1);
		SET_FLOAT_WORD(t1, ((uint32_t)is & (uint32_t)0xfffff000));
		t2 = z_l - (((t1 - t) - dp_hf[k]) - z_h);
	}
	s = 1.0F;
	if (((((uint32_t)hx >> 31) - 1) | (uint32_t)(yisint - 1)) == 0) { s = -1.0F; }
	GET_FLOAT_WORD(is, y);
	float y1;
	SET_FLOAT_WORD(y1, ((uint32_t)is & (uint32_t)0xfffff000));
	p_l = (y - y1) * t1 + y * t2;
	p_h = y1 * t1;
	z = p_l + p_h;
	GET_FLOAT_WORD(j, z);
	i = j & 0x7fffffff;
	if (j > 0) {
		if (i > FLT_UWORD_EXP_MAX) { return s * HUGEF_SQ; }
		else if (i == FLT_UWORD_EXP_MAX && (p_l + 4.2995665694E-8F > z - p_h)) { return s * v * HUGEF; }
	} else if ((i > FLT_UWORD_EXP_MIN) || (i == FLT_UWORD_EXP_MIN && (p_l <= z - p_h))) {
		return s * TINYF_SQ;
	}
	k = (i >> 23) - 0x7f;
	n = 0;
	if (i > 0x3f000000) {
		n = j + (0x800000 >> (k + 1));
		k = ((n & 0x7fffffff) >> 23) - 0x7f;
		SET_FLOAT_WORD(t, ((uint32_t)n & (uint32_t)(~(0x7fffff >> (uint32_t)k))));
		n = ((n & 0x7fffff) | 0x800000) >> (23 - k);
		if (j < 0) { n = -n; }
		p_h -= t;
	}
	t = p_l + p_h;
	GET_FLOAT_WORD(is, t);
	SET_FLOAT_WORD(t, ((uint32_t)is & (uint32_t)0xfffff000));
	u = t * 6.93145752E-1F;
	v = (p_l - (t - p_h)) * 6.9314718246E-1F + t * 1.42860654E-6F;
	z = u + v;
	w = v - (z - u);
	t = z * z;
	t1 = z - t * (1.6666667163E-1F + t * (-2.7777778450E-3F + t * (6.6137559770E-5F + t * (-1.6533901999E-6F + t * 4.1381369442E-8F))));
	r = (z * t1) / (t1 - 2.0F) - (w + z * w);
	z = 1.0F - (r - z);
	GET_FLOAT_WORD(j, z);
	j += (n << 23);
	if ((j >> 23) <= 0) { z = scalbnf(z, (int)n); }
	else { SET_FLOAT_SWORD(z, j); }
	return s * z;
}


LIB_FUNC MATH_FUNC double __ieee754_pow(const double x, const double y) {
	double z, p_h, p_l, r, s, t, u, v, w;
	int32_t i, j, k, n;
	double_shape_t ew_su = { .value = x };
	const int32_t hx = (int32_t)ew_su.parts.msw;
	const uint32_t lx = ew_su.parts.lsw;
	ew_su.value = (double)(y);
	const int32_t hy = (int32_t)ew_su.parts.msw;
	const uint32_t ly = ew_su.parts.lsw;
	int32_t ix = (hx & 0x7fffffff), iy = (hy & 0x7fffffff);
	if (((uint32_t)iy | ly) == 0) { return 1.0; }
	else if (ix > 0x7ff00000 || ((ix == 0x7ff00000) && (lx != 0)) || iy > 0x7ff00000 || ((iy == 0x7ff00000) && (ly != 0))) {
		if (((uint32_t)(ix - 0x3ff00000) | lx) == 0) { return 1.0; }
		else { return nan(""); }
	}
	register int32_t yisint = 0;
	if (hx < 0) {
		if (iy >= 0x43400000) { yisint = 2; }
		else if (iy >= 0x3ff00000) {
			k = (int32_t)((iy >> 20) - 0x3ff);
			if (k > 20) {
				j = (int32_t)(ly >> (52 - k));
				if ((uint32_t)(j << (52 - k)) == ly) { yisint = (2 - (j & 1)); }
			} else if (ly == 0) {
				j = (int32_t)(iy >> (20 - k));
				if ((j << (20 - k)) == iy) { yisint = (2 - (j & 1)); }
			}
		}
	}
	if (ly == 0) {
		if (iy == 0x7ff00000) {
			if (((uint32_t)(ix - 0x3ff00000) | lx) == 0) { return 1.0; }
			else if (ix >= 0x3ff00000) { return (hy >= 0) ? y : 0.0; }
			else { return (hy < 0) ? -y : 0.0; }
		} else if (iy == 0x3ff00000) {
			if (hy < 0) { return 1.0 / x; }
			else { return x; }
		} else if (hy == 0x40000000) { return x * x; }
		else if (hy == 0x3fe00000 && hx >= 0) { return __ieee754_sqrt(x); }
	}
	double ax = fabs(x);
	if (lx == 0) {
		if (ix == 0x7ff00000 || ix == 0 || ix == 0x3ff00000) {
			z = ax;
			if (hy < 0) { z = 1.0 / z; }
			if (hx < 0) {
				if (((ix - 0x3ff00000) | yisint) == 0) { z = (z - z) / (z - z); }
				else if (yisint == 1) { z = -z; }
			}
			return z;
		}
	}
	const double align64 bp[2] = { 1.0, 1.5 };
	const double align64 dp_h[2] = { 0.0, 5.84962487220764160156E-1 };
	const double align64 dp_l[2] = { 0.0, 1.35003920212974897128E-8 };
	double t1, t2;
	if (((((uint32_t)hx >> 31) - 1) | (uint32_t)yisint) == 0) { return (x - x) / (x - x); }
	else if (iy > 0x41e00000) {
		if (iy > 0x43f00000) {
			if (ix <= 0x3fefffff) { return ((hy < 0) ? HUGE_SQ : TINY_SQ); }
			else if (ix >= 0x3ff00000) { return ((hy > 0) ? HUGE_SQ : TINY_SQ); }
		} else if (ix < 0x3fefffff) { return ((hy < 0) ? HUGE_SQ : TINY_SQ); }
		else if (ix > 0x3ff00000) { return ((hy > 0) ? HUGE_SQ : TINY_SQ); }
		t = ax - 1;
		w = (t * t) * (0.5 - t * (0.3333333333333333333333 - t * 0.25));
		u = M_LOG2E * t;
		v = t * 1.92596299112661746887E-8 - w * M_LOG2E;
		t1 = u + v;
		SET_LOW_WORD(t1, 0);
		t2 = v - (t1 - u);
	} else {
		register double s2, s_h, s_l, t_h, t_l;
		n = 0;
		if (ix < 0x100000) {
			ax *= 9007199254740992.0;
			n -= 53;
			double_shape_t gh_s = { .value = ax };
			ix = (int32_t)gh_s.parts.msw;
		}
		n += ((ix) >> 20) - 0x3ff;
		j = ix & 0xfffff;
		ix = j | 0x3ff00000;
		if (j <= 0x3988e) { k = 0; }
		else if (j < 0xbb67a) { k = 1; }
		else {
			k = 0;
			n += 1;
			ix -= 0x100000;
		}
		SET_HIGH_WORD(ax, ix);
		u = ax - bp[k];
		v = 1.0 / (ax + bp[k]);
		s = u * v;
		s_h = s;
		SET_LOW_WORD(s_h, 0);
		t_h = 0.0;
		SET_HIGH_WORD(t_h, ((ix >> 1) | 0x20000000) + 0x80000 + (k << 18));
		t_l = ax - (t_h - bp[k]);
		s_l = v * ((u - s_h * t_h) - s_h * t_l);
		s2 = s * s;
		r = s2 * s2 * (5.99999999999994648725E-1 + s2 * (4.28571428578550184252E-1 + s2 * (3.33333329818377432918E-1 + s2 * (2.72728123808534006489E-1 + s2 * (2.30660745775561754067E-1 + s2 * 2.06975017800338417784E-1)))));
		r += s_l * (s_h + s);
		s2 = s_h * s_h;
		t_h = 3.0 + s2 + r;
		SET_LOW_WORD(t_h, 0);
		t_l = r - ((t_h - 3.0) - s2);
		u = s_h * t_h;
		v = s_l * t_h + t_l * s;
		p_h = u + v;
		SET_LOW_WORD(p_h, 0);
		p_l = v - (p_h - u);
		const double z_h = 9.61796700954437255859E-1 * p_h;
		const double z_l = -7.02846165095275826516E-9 * p_h + p_l * 9.61796693925975554329E-1 + dp_l[k];
		t = (double)n;
		t1 = (((z_h + z_l) + dp_h[k]) + t);
		SET_LOW_WORD(t1, 0);
		t2 = z_l - (((t1 - t) - dp_h[k]) - z_h);
	}
	s = 1.0;
	if (((((uint32_t)hx >> 31) - 1) | (uint32_t)(yisint - 1)) == 0) { s = -1.0; }
	double y1 = y;
	SET_LOW_WORD(y1, 0);
	p_l = (y - y1) * t1 + y * t2;
	p_h = y1 * t1;
	z = p_l + p_h;
	EXTRACT_SIGNED_WORDS(j, i, z);
	if (j >= 0x40900000) {
		if ((((j - 0x40900000) | i) != 0) || ((p_l + 8.0085662595372944372E-17) > (z - p_h))) {
			return s * HUGE_SQ;
		}
	} else if ((j & 0x7fffffff) >= 0x4090cc00 ) {
		if ((((uint32_t)((uint32_t)j - 0xc090cc00) | (uint32_t)i) != 0) || (p_l <= z - p_h)) {
			return s * TINY_SQ;
		}
	}
	i = j & 0x7fffffff;
	k = (i >> 20) - 0x3ff;
	n = 0;
	if (i > 0x3fe00000) {
		n = j + (0x100000 >> (k + 1));
		k = ((n & 0x7fffffff) >> 20) - 0x3ff;
		t = 0.0;
		SET_HIGH_WORD(t, n & (~(0xfffff >> k)));
		n = ((n & 0xfffff) | 0x100000) >> (20 - k);
		if (j < 0) { n = -n; }
		p_h -= t;
	}
	t = p_l + p_h;
	SET_LOW_WORD(t, 0);
	u = t * 6.93147182464599609375E-1;
	v = (p_l - (t - p_h)) * 6.93147180559945286227E-1 + t * -1.90465429995776804525E-9;
	z = u + v;
	w = v - (z - u);
	t = z * z;
	t1 = z - t * (1.66666666666666019037E-1 + t * (-2.77777777770155933842E-3 + t * (6.61375632143793436117E-5 + t * (-1.65339022054652515390E-6 + t * 4.13813679705723846039E-8))));
	r = (z * t1) / (t1 - 2.0) - (w + z * w);
	z = 1.0 - (r - z);
	GET_HIGH_SIGNED_WORD(j, z);
	j += (n << 20);
	if ((j >> 20) <= 0) { z = scalbn(z, (int)n); }
	else { SET_HIGH_WORD(z, j); }
	return s * z;
}


LIB_FUNC MATH_FUNC float ipowf(const float mant, const int expo) {
	register float ret = 1.0F;
	register float m = mant;
	register unsigned int e = (unsigned int)expo;
	if (expo < 0) {
		e = (unsigned int)-e;
		m = 1.0F / m;
	}
	until_break {
		if (e & 1) { ret *= m; }
		if ((e >>= 1) == 0) { break; }
		m *= m;
	}
	return ret;
}


LIB_FUNC MATH_FUNC double ipow(const double mant, const int expo) {
	register double ret = 1.0;
	register double m = mant;
	register unsigned int e = (unsigned int)expo;
	if (expo < 0) {
		e = (unsigned int)-e;
		m = 1.0 / m;
	}
	until_break {
		if (e & 1) { ret *= m; }
		if ((e >>= 1) == 0) { break; }
		m *= m;
	}
	return ret;
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double ipowl(const long double mant, const int expo) {
	register long double ret = 1.0L;
	register long double m = mant;
	register unsigned int e = (unsigned int)expo;
	if (expo < 0) {
		e = (unsigned int)-e;
		m = 1.0L / m;
	}
	until_break {
		if (e & 1) { ret *= m; }
		if ((e >>= 1) == 0) { break; }
		m *= m;
	}
	return ret;
}
#endif


LIB_FUNC MATH_FUNC float powf(const float x, const float y) {
#if IS_LIBM_POSIX
	return __ieee754_powf(x, y);
#else
	const float z = __ieee754_powf(x, y);
	if (isnan(x)) {
		if (y == 0.0F) {
			exc.type = DOMAIN;
			exc.name = "powf";
			exc.err = EDOM;
			exc.arg1 = (double)x;
			exc.arg2 = (double)y;
			exc.retval = 1.0;
			matherr(&exc);
			return (float)exc.retval;
		} else { return z; }
	} else if (x == 0.0F) {
		if (y == 0.0F) {
			exc.type = DOMAIN;
			exc.name = "powf";
			exc.err = EDOM;
			exc.arg1 = (double)x;
			exc.arg2 = (double)y;
			exc.retval = 0.0;
			matherr(&exc);
			return (float)exc.retval;
		} else if (finitef(y) && y < 0.0F) {
			exc.type = DOMAIN;
			exc.name = "powf";
			exc.err = EDOM;
			exc.arg1 = (double)x;
			exc.arg2 = (double)y;
			exc.retval = -HUGE_VAL;
			matherr(&exc);
			return (float)exc.retval;
		}
		return z;
	}
	if (!finitef(z)) {
		if (finitef(x) && finitef(y)) {
			if (isnan(z)) {
				exc.type = DOMAIN;
				exc.name = "powf";
				exc.err = EDOM;
				exc.arg1 = (double)x;
				exc.arg2 = (double)y;
				exc.retval = 0.0 / 0.0;
				matherr(&exc);
				return (float)exc.retval;
			} else {
				exc.type = OVERFLOW;
				exc.name = "powf";
				exc.err = ERANGE;
				exc.arg1 = (double)x;
				exc.arg2 = (double)y;
				register const float y5 = (0.5F * y);
				if (x < 0.0F && rintf(y5) != y5) { exc.retval = -HUGE_VAL; }
				else { exc.retval = HUGE_VAL; }
				matherr(&exc);
				return (float)exc.retval;
			}
		}
	} else if (z == 0.0F && finitef(x) && finitef(y)) {
		exc.type = UNDERFLOW;
		exc.name = "powf";
		exc.err = ERANGE;
		exc.arg1 = (double)x;
		exc.arg2 = (double)y;
		exc.retval = 0.0;
		matherr(&exc);
		return (float)exc.retval;
	}
	return z;
#endif
}


LIB_FUNC MATH_FUNC double pow(const double x, const double y) {
#if IS_LIBM_POSIX
	return __ieee754_pow(x, y);
#else
	const double z = __ieee754_pow(x, y);
	if (__isnan(x)) {
		if (y == 0.0) {
			exc.type = DOMAIN;
			exc.name = "pow";
			exc.err = EDOM;
			exc.arg1 = x;
			exc.arg2 = y;
			exc.retval = 1.0;
			matherr(&exc);
			return exc.retval;
		}
	} else if (x == 0.0) {
		if (y == 0.0) {
			exc.type = DOMAIN;
			exc.name = "pow";
			exc.err = EDOM;
			exc.arg1 = x;
			exc.arg2 = y;
			exc.retval = 0.0;
			matherr(&exc);
			return exc.retval;
		} else if (finite(y) && y < 0.0) {
			exc.type = DOMAIN;
			exc.name = "pow";
			exc.err = EDOM;
			exc.arg1 = x;
			exc.arg2 = y;
			exc.retval = -HUGE_VAL;
			matherr(&exc);
			return exc.retval;
		}
		return z;
	} else if (!finite(z)) {
		if (finite(x) && finite(y)) {
			if (__isnan(z)) {
				exc.type = DOMAIN;
				exc.name = "pow";
				exc.err = EDOM;
				exc.arg1 = x;
				exc.arg2 = y;
				exc.retval = 0.0 / 0.0;
				matherr(&exc);
				return exc.retval;
			} else {
				exc.type = OVERFLOW;
				exc.name = "pow";
				exc.err = ERANGE;
				exc.arg1 = x;
				exc.arg2 = y;
				register const double y5 = (0.5 * y);
				if (x < 0.0 && rint(y5) != y5) { exc.retval = -HUGE_VAL; }
				else { exc.retval = HUGE_VAL; }
				matherr(&exc);
				return exc.retval;
			}
		}
	}
	if (z == 0.0 && finite(x) && finite(y)) {
		exc.type = UNDERFLOW;
		exc.name = "pow";
		exc.err = ERANGE;
		exc.arg1 = x;
		exc.arg2 = y;
		exc.retval = 0.0;
		matherr(&exc);
		return exc.retval;
	}
	return z;
#endif
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double powl(const long double x, const long double y) {
	return (long double)__ieee754_pow((double)x, (double)y);
}
#endif


LIB_FUNC MATH_FUNC float __ieee754_expf(const float x) {
	if (PREDICT_LIKELY(isless(x, 88.72283935546875F) && isgreater(x, -103.972084045410F))) {
		float n = x * M_LOG2EF + 12582912.0F;
		n -= 12582912.0F;
		register double dx = (double)(x - n * M_LN2F);
		const double t = (dx + 13194139533312.0) - 13194139533312.0;
		dx -= t;
		const int tval = (int)(t * 512.0);
		union ieee754_double ex2_u = { .d = __exp_atable[tval + 177] };
		const uint11_t tmpval = { .val16 = (unsigned short)(ex2_u.ieee.exponent + (unsigned short)n) };
		ex2_u.ieee.exponent = tmpval.val11.uval11;
		if (t >= 0) { return (float)(((0.5000000496709180453 * dx + 1.0000001192102037084) * dx + (double)-(__exp_deltatable[tval])) * ex2_u.d + ex2_u.d); }
		else { return (float)(((0.5000000496709180453 * dx + 1.0000001192102037084) * dx + (double)__exp_deltatable[-tval]) * ex2_u.d + ex2_u.d); }
	} else if (PREDICT_UNLIKELY(isinff(x))) {
		return 0;
	} else if (__islessf(x, 88.72283935546875F)) {
		return 7.88860905E-31F * 7.88860905E-31F;
	} else { return 1.7014118346E+38F * x; }
}
#define __expf_finite(x)   __ieee754_expf((x))


#if LDBL_EQ_FLOAT128
LIB_FUNC MATH_FUNC long double __ieee754_expl(const long double num) {
	long double x = num;
	if (__islessl(x, 11356.523406294143949491931077970765L) && __isgreaterl(x, -11433.4627433362978788372438434526231L)) {
		fenv_t oldenv = { 0 };
		feholdexcept(&oldenv);
#   ifdef FE_TONEAREST
		fesetround(FE_TONEAREST);
#   endif
		long double n = x * M_LOG2EL + 7788445287802241442795744493830144.0L;
		n -= 7788445287802241442795744493830144.0L;
		x = x - n * M_LN2L;
		long double xl = n * -1.94704509238074995158795957333327386E-31L;
		long double t = x + 30423614405477505635920876929024.0L;
		t -= 30423614405477505635920876929024.0L;
		const int tval1 = (int)(t * 256.0L);
		x -= __expl_table[T_EXPL_ARG1 + (tval1 + tval1)];
		xl -= __expl_table[T_EXPL_ARG1 + (tval1 + tval1) + 1];
		t = x + 59421121885698253195157962752.0L;
		t -= 59421121885698253195157962752.0L;
		const int tval2 = (int)(t * 32768.0L);
		x -= __expl_table[T_EXPL_ARG2 + (tval2 + tval2)];
		xl -= __expl_table[T_EXPL_ARG2 + (tval2 + tval2) + 1];
		x = x + xl;
		union ieee854_long_double ex2_u = { .ld = __expl_table[T_EXPL_RES1 + tval1] * __expl_table[T_EXPL_RES2 + tval2] };
		const int n_i = (int)n;
		const int unsafe = (abs(n_i) >= 15000);
		union ieee854_long_double scale_u = { .ld = 1.0L };
#   if (LDBL_EXP_BITS == 11)
		uint11_t tmpval = { .val16 = (unsigned short)(ex2_u.ieee.exponent + (unsigned short)(n_i >> unsafe)) };
		ex2_u.ieee.exponent = tmpval.val11.uval11;
		tmpval.val11.uval11 = scale_u.ieee.exponent;
		tmpval.val16 = (unsigned short)(((int)tmpval.val16 + n_i) - (n_i >> unsafe));
		scale_u.ieee.exponent = tmpval.val11.uval11;
#   elif (LDBL_EXP_BITS == 15)
		uint15_t tmpval = { .val16 = (unsigned short)(ex2_u.ieee.exponent + (unsigned short)(n_i >> unsafe)) };
		ex2_u.ieee.exponent = tmpval.val15.uval15;
		tmpval.val15.uval15 = scale_u.ieee.exponent;
		tmpval.val16 = (unsigned short)(((int)tmpval.val16 + n_i) - (n_i >> unsafe));
		scale_u.ieee.exponent = tmpval.val15.uval15;
#   endif
		const long double x22 = x + x * x * (0.5L + x * (1.66666666666666666666666666666666683E-1L + x * (4.16666666666666666666654902320001674E-2L + x * (8.33333333333333333333314659767198461E-3L + x * (1.38888888889899438565058018857254025E-3L + x * 1.98412698413981650382436541785404286E-4L)))));
		fesetenv(&oldenv);
		long double result = x22 * ex2_u.ld + ex2_u.ld;
		if (!unsafe) { return result; }
		else {
			result *= scale_u.ld;
			math_check_force_underflow_nonneg(result);
			return result;
		}
	} else if (__isinfl(x)) {
		return 0;
	} else if (__islessl(x, 11356.523406294143949491931077970765L)) {
		return TINYL_SQ;
	} else { return 5.94865747678615882542879663314003565E+4931L * x; }
}
#   define __expl_finite(x)   __ieee754_expl((x))


LIB_FUNC MATH_FUNC long double __ieee754_exp2l(const long double x) {
	if (PREDICT_LIKELY(__islessl(x, (long double)LDBL_MAX_EXP))) {
		if (PREDICT_LIKELY(__isgreaterequall(x, (long double)(LDBL_MIN_EXP - LDBL_MANT_DIG - 1)))) {
			const int intx = (int)x;
			const long double fractx = (x - intx);
			long double result;
			if (fabsl(fractx) < LDBL_EPSILON / 4.0L) {
				result = scalbnl(1.0L + fractx, intx);
			}
			else { result = scalbnl(__ieee754_expl(M_LN2L * fractx), intx); }
			math_check_force_underflow_nonneg(result);
			return result;
		}
		return LDBL_MIN * LDBL_MIN;
	} else if (__isinfl(x)) { return 0; }
	return LDBL_MAX * x;
}
#   define __exp2l_finite(x)   __ieee754_exp2l((x))
#endif


LIB_FUNC MATH_FUNC float __ieee754_exp10f(const float arg) {
	if (PREDICT_UNLIKELY(isfinitef(arg) && arg < (FLT_MIN_10_EXP - FLT_DIG - 10))) { return FLT_MIN * FLT_MIN; }
	return expf((M_LN10F * arg));
}
#define __exp10f_finite(x)   __ieee754_exp10f((x))


LIB_FUNC MATH_FUNC double __ieee754_exp10(const double arg) {
	if (PREDICT_UNLIKELY(isfinite(arg) && arg < (DBL_MIN_10_EXP - DBL_DIG - 10))) { return DBL_MIN * DBL_MIN; }
	return exp(M_LN10 * arg);
}
#define __exp10_finite(x)   __ieee754_exp10((x))


#if LDBL_EQ_FLOAT128
LIB_FUNC MATH_FUNC long double __ieee754_exp10l(const long double arg) {
	if (PREDICT_UNLIKELY(isfinitel(arg) && arg < (LDBL_MIN_10_EXP - LDBL_DIG - 10))) { return LDBL_MIN * LDBL_MIN; }
	return __ieee754_expl(M_LN10L * arg);
}
#   define __exp10l_finite(x)   __ieee754_exp10l((x))
#endif


LIB_FUNC MATH_FUNC float expf(const float num) {
	float x = num;
	uint32_t hx;
	GET_FLOAT_UWORD(hx, x);
	register int k;
	const int sign = (int)(hx >> 31);
	hx &= 0x7fffffff;
	if (hx >= 0x42aeac50) {
		if (hx >= 0x42b17218 && !sign) {
			x *= 0x1.0P+127F;
			return x;
		} else if (sign) {
			FORCE_EVAL(((float)(-0x1.0P-149) / x));
			if (hx >= 0x42cff1b5) { return 0; }
		}
	}
	register float hi, lo;
	if (hx > 0x3eb17218) {
		if (hx > 0x3f851592) { k = (int)(M_LOG2EF * x + expf_half[sign]); }
		else { k = (1 - sign) - sign; }
		hi = (x - ((float)k) * 6.9314575195E-1F);
		lo = (float)k * 1.4286067653E-6F;
		x = hi - lo;
	} else if (hx > 0x39000000) {
		k = 0;
		hi = x;
		lo = 0.0F;
	} else {
		FORCE_EVAL(0x1.0P127F + x);
		return 1.0F + x;
	}
	register const float xx = x * x;
	const float c = x - xx * (1.6666625440E-1F + xx * -2.7667332906E-3F);
	const float y = 1 + (x * c / (2 - c) - lo + hi);
	if (k == 0) { return y; }
	return scalbnf(y, k);
}


LIB_FUNC MATH_FUNC double exp(const double num) {
	double x = num, c, y;
	uint32_t hx;
	GET_HIGH_WORD(hx, x);
	register int k;
	const int sign = (int)(hx >> 31);
	hx &= 0x7fffffff;
	if (hx >= 0x4086232b) {
		if (__isnan(x)) { return x; }
		else if (x > 709.782712893383973096) {
			x *= 0x1.0P+1023;
			return x;
		} else if (x < -708.39641853226410622) {
			FORCE_EVAL(-0x1.0P-149 / x);
			if (x < -745.13321910194110842) { return 0; }
		}
	}
	register double hi, lo;
	if (hx > 0x3fd62e42) {
		if (hx >= 0x3ff0a2b2) { k = (int)(M_LOG2E * x + exp_half[sign]); }
		else { k = 1 - sign - sign; }
		hi = x - k * 6.93147180369123816490E-1;
		lo = k * 1.90821492927058770002E-10;
		x = hi - lo;
	} else if (hx > 0x3e300000) {
		k = 0;
		hi = x;
		lo = 0;
	} else {
		FORCE_EVAL(0x1.0P+1023 + x);
		return 1 + x;
	}
	register const double xx = x * x;
	c = x - xx * (1.66666666666666019037E-1 + xx * (-2.77777777770155933842E-3 + xx * (6.61375632143793436117E-5 + xx * (-1.65339022054652515390E-6 + xx * 4.13813679705723846039E-8))));
	y = 1 + (x * c / (2 - c) - lo + hi);
	if (k == 0) { return y; }
	return scalbn(y, k);
}


#if IS_LDBL_X87
LIB_FUNC MATH_FUNC long double expl(const long double num) {
	long double x = num;
	if (isnan(x)) { return x; }
	else if (x > 11356.5234062941439488L) { return x * 0x1.0P+16383L; }
	else if (x < -11399.4985314888605581L) { return -0x1.0P-16445L / x; }
	long double px = floorl(M_LOG2EL * x + 0.5L);
	int k = (int)px;
	x -= px * 6.9314575195312500000000E-1L;
	x -= px * 1.4286068203094172321215E-6L;
	const long double xx = x * x;
	px = x * __polevll(xx, P, 2);
	x = 1.0L + 2.0L * (px / (__polevll(xx, expl_Q, 3) - px));
	return scalbnl(x, k);
}
#else
LIB_FUNC MATH_FUNC long double expl(const long double num) {
	return (long double)exp((double)num);
}
#endif


LIB_FUNC MATH_FUNC float exp2f(const float num) {
	float x = num;
	union __union_exp2f_float { float f; uint32_t i; } u = { x };
	const uint32_t ix = u.i & 0x7fffffff;
	if (ix > 0x42fc0000) {
		if (u.i >= 0x43000000 && u.i < 0x80000000) {
			x *= 0x1.0P+127F;
			return x;
		} else if (u.i >= 0x80000000) {
			if (u.i >= 0xc3160000 || (u.i & 0xffff)) { FORCE_EVAL(-0x1.0P-149F / x); }
			if (u.i >= 0xc3160000) { return 0; }
		}
	} else if (ix <= 0x33000000) { return 1.0F + x; }
	u.f = x + (0x1.8P+23F / 16);
	register uint32_t i0 = (uint32_t)u.i;
	i0 += 16 / 2;
	const uint32_t k = i0 / 16;
	union __union_exp2f_double { double f; uint64_t i; } uk = { .i = (uint64_t)(0x3ff + k) << 52 };
	i0 &= 16 - 1;
	u.f -= (0x1.8P+23F / 16);
	const double z = x - u.f;
	double r = exp2f_exp2ft[i0];
	double t = r * z;
	r = r + t * (0x1.62e430P-1 + z * 0x1.ebfbe0P-3) + t * (z * z) * (0x1.c6b348P-5 + z * 0x1.3b2c9cP-7);
	return (float)(r * uk.f);
}


LIB_FUNC MATH_FUNC double exp2(const double num) {
	double x = num;
	union __union_exp2_float { double f; uint64_t i; } u = { x };
	const uint32_t ix = ((u.i >> 32) & 0x7fffffff);
	if (ix >= 0x408ff000) {
		if (ix >= 0x40900000 && u.i >> 63 == 0) {
			x *= 0x1.0P+1023;
			return x;
		} else if (ix >= 0x7ff00000) { return -1 / x; }
		else if (u.i >> 63) {
			if (x <= -1075 || x - 0x1.0P+52 + 0x1.0P+52 != x) { FORCE_EVAL((-0x1.0P-149 / x)); }
			if (x <= -1075) { return 0; }
		}
	} else if (ix < 0x3c900000) { return 1.0 + x; }
	u.f = x + (0x1.8P+52 / 256);
	uint32_t i0 = (uint32_t)u.i;
	i0 += 256 / 2;
	union __union_exp2_int32 { uint32_t u; int32_t i; } k = { .u = i0 / 256 * 256 };
	k.i /= 256;
	i0 %= 256;
	u.f -= (0x1.8P+52 / 256);
	double z = x - u.f;
	const double t = exp2_tbl[i0 + i0];
	z -= exp2_tbl[(i0 + i0) + 1];
	double r = t + t * z * (0x1.62e42fefa39efP-1 + z * (0x1.ebfbdff82c575P-3 + z * (0x1.c6b08d704a0a6P-5 + z * (0x1.3b2ab88f70400P-7 + z * 0x1.5d88003875c74P-10))));
	return scalbn(r, k.i);
}


#if IS_LDBL_X87
LIB_FUNC MATH_FUNC long double exp2l(const long double num) {
	long double x = num;
	union ldshape u = { x };
	const int e = u.i.se & 0x7fff;
	if (e >= 0x3fff + 13) {
		if (u.i.se >= 0x3fff + 14 && u.i.se >> 15 == 0) { return x * 0x1.0P+16383L; }
		else if (e == 0x7fff) { return -1 / x; }
		else if (x < -16382) {
			if (x <= -16446 || ((x - 0x1.0P+63L) + 0x1.0P+63L != x)) { FORCE_EVAL((-0x1.0P-149L / x)); }
			if (x <= -16446) { return 0; }
		}
	} else if (e < 0x3fbf) { return 1 + x; }
	u.f = x + (0x1.8P+63 / 0x80);
	uint32_t i0 = u.i.m + 0x40;
	union __union_exp2l_int32 {uint32_t u; int32_t i;} k = { .u = i0 / 0x80 * 0x80 };
	k.i /= 0x80;
	i0 %= 0x80;
	u.f -= (0x1.8p63 / 0x80);
	const long double z = x - u.f;
	const long double t_hi = exp2l_tbl[i0 + i0];
	const long double t_lo = exp2l_tbl[(i0 + i0) + 1];
	const long double r = t_lo + (t_hi + t_lo) * z * ((0x1.62e42fefa39efP-1) + z * ((0x1.ebfbdff82c58fP-3) + z * ((0x1.c6b08d7049faP-5) + z * ((0x1.3b2ab6fba4da5P-7) + z * ((0x1.5d8804780a736P-10) + z * (0x1.430918835e33dP-13)))))) + t_hi;
	return scalbnl(r, k.i);
}
#elif LDBL_EQ_FLOAT128
LIB_FUNC MATH_FUNC long double exp2l(const long double num) {
	long double x = num;
	union ldshape u = { x };
	const int e = u.i.se & 0x7fff;
	if (e >= 0x3fff + 14) {
		if (u.i.se >= (0x3fff + 15) && u.i.se >> 15 == 0) { return x * 0x1.0P+16383L; }
		else if (e == 0x7fff) { return -1 / x; }
		else if (x < -16382) {
			if (x <= -16495 || x - 0x1.0P+112L + 0x1.0P+112L != x) { FORCE_EVAL((-0x1.0P-149L / x)); }
			if (x <= -16446) { return 0; }
		}
	} else if (e < 0x3fff - 114) { return 1 + x; }
	u.f = x + (0x1.8P+112 / 0x80);
	uint32_t i0 = (uint32_t)(u.i2.lo + 0x40);
	union __union_exp2l_int32 { uint32_t u; int32_t i; } k = { .u = i0 / 0x80 * 0x80 };
	k.i /= 0x80;
	i0 %= 0x80;
	u.f -= (0x1.8P+112 / 0x80);
	long double z = x - u.f;
	const long double t = exp2l_tbl[i0];
	z -= exp2l_eps[i0];
	const long double r = t + t * z * (0x1.62e42fefa39ef35793c7673007e6P-1L + z * (0x1.ebfbdff82c58ea86f16b06ec9736P-3L + z * (0x1.c6b08d704a0bf8b33a762bad3459P-5L + z * (0x1.3b2ab6fba4e7729ccbbe0b4f3fc2P-7L + z * (0x1.5d87fe78a67311071dee13fd11d9P-10L + z * (0x1.430912f86c7876f4b663b23c5fe5P-13L + z * ((double)(0x1.ffcbfc588b041P-17) + z * ((double)(0x1.62c0223a5c7c7P-20) + z * ((double)(0x1.b52541ff59713P-24) + z * (double)(0x1.e4cf56a391e22P-28))))))))));
	return scalbnl(r, k.i);
}
#else
LIB_FUNC MATH_FUNC long double exp2l(const long double num) {
	return (long double)exp2((double)num);
}
#endif


LIB_FUNC MATH_FUNC float exp10f(const float x) {
	return powf(10.0F, x);
}
#define pow10f(x)   exp10f((x))


LIB_FUNC MATH_FUNC double exp10(const double x) {
	return pow(10.0, x);
}
#define pow10(x)   exp10((x))


#if (!LDBL_EQ_DBL)
LIB_FUNC MATH_FUNC long double exp10l(const long double x) {
	long double n, y = modfl(x, &n);
	const long_double_shape_t u = { .value = n };
	if ((u.uparts16.w0 & 0x7fff) < 0x3fff + 4) {
		if (!y) { return exp10l_p10[(int)n + 15]; }
		y = exp2l(3.32192809488736234787031942948939L * y);
		return y * exp10l_p10[(int)n + 15];
	}
	return powl(10.0L, x);
}
#   define pow10l(x)   exp10l((x))
#else
LIB_FUNC MATH_FUNC long double exp10l(const long double x) {
	return (long double)exp10((double)x);
}
#   define pow10l(x)   exp10l((x))
#endif


LIB_FUNC MATH_FUNC float __expo2f(const float x) {
	float scale;
	SET_FLOAT_WORD(scale, (uint32_t)(0x7f + 235 / 2) << 23);
	return expf(x - 0x1.45c778P+7F) * scale * scale;
}


LIB_FUNC MATH_FUNC double __expo2(const double x) {
	double scale;
	INSERT_WORDS(scale, (uint32_t)(0x3ff + 2043 / 2) << 20, 0);
	return exp(x - 0x1.62066151add8bP+10) * scale * scale;
}


LIB_FUNC MATH_FUNC float expm1f(const float num) {
	float y, c = 0.0F, t, e, x = num;
	uint32_t hx;
	register int32_t k = 0;
	GET_FLOAT_UWORD(hx, x);
	const int32_t xsb = (int32_t)((int32_t)hx & (int32_t)0x80000000);
	if (xsb == 0) { y = x; }
	else { y = -x; }
	hx &= 0x7fffffff;
	if (hx >= 0x4195b844) {
		if (FLT_UWORD_IS_NAN(hx)) { return x + x; }
		else if (FLT_UWORD_IS_INFINITE(hx)) { return (xsb == 0) ? x : -1.0F; }
		else if (xsb == 0 && hx > FLT_UWORD_LOG_MAX) { return HUGEF_SQ; }
		else if ((xsb != 0) && (x + TINYF < 0.0F)) { return TINYF - 1.0F; }
	} else if (hx > 0x3eb17218) {
		float hi, lo;
		if (hx < 0x3f851592) {
			if (xsb == 0) {
				hi = x - 6.9313812256E-1F;
				lo = 9.0580006145E-6F;
				k = 1;
			} else {
				hi = x + 6.9313812256E-1F;
				lo = -9.0580006145E-6F;
				k = -1;
			}
		} else {
			k = (int32_t)(M_LOG2EF * x + ((xsb == 0) ? 0.5F : -0.5F));
			t = (float)k;
			hi = x - t * 6.9313812256E-1F;
			lo = t * 9.0580006145E-6F;
		}
		x = hi - lo;
		c = (hi - x) - lo;
	} else if (hx < 0x33000000) {
		t = HUGEF + x;
		return x - (t - (HUGEF + x));
	} else { k = 0; }
	const float hfx = 0.5F * x;
	const float hxs = x * hfx;
	const float r1 = 1.0F + hxs * (-3.3333335072E-2F + hxs * (1.5873016091E-3F + hxs * (-7.9365076090E-5F + hxs * (4.0082177293E-6F + hxs * -2.0109921195E-7F))));
	t = 3.0F - r1 * hfx;
	e = hxs * ((r1 - t) / (6.0F - x * t));
	if (k == 0) { return x - (x * e - hxs); }
	else {
		e = (x * (e - c) - c);
		e -= hxs;
		int32_t i;
		if (k == -1) { return 0.5F * (x - e) - 0.5F; }
		else if (k == 1) {
			if (x < -0.25F) { return -2.0F * (e - (x + 0.5F)); }
			else { return 1.0F + 2.0F * (x - e); }
		} else if (k <= -2 || k > 56) {
			y = 1.0F - (e - x);
			GET_FLOAT_WORD(i, y);
			SET_FLOAT_SWORD(y, (i + (k << 23)));
			return y - 1.0F;
		}
		t = 1.0F;
		if (k < 23) {
			SET_FLOAT_SWORD(t, (0x3f800000 - (0x1000000 >> k)));
			y = t - (e - x);
			GET_FLOAT_WORD(i, y);
			SET_FLOAT_SWORD(y, (i + (k << 23)));
		} else {
			SET_FLOAT_SWORD(t, ((0x7f - k) << 23));
			y = x - (e + t);
			y += 1.0F;
			GET_FLOAT_WORD(i, y);
			SET_FLOAT_SWORD(y, (i + (k << 23)));
		}
	}
	return y;
}
#define __expm1f(x)   expm1f((x))


LIB_FUNC MATH_FUNC double expm1(const double num) {
	double y, c, t, e, x = num;
	int32_t k;
	uint32_t hx;
	GET_HIGH_WORD(hx, x);
	const int32_t xsb = (int32_t)(hx & 0x80000000);
	if (xsb == 0) { y = x; }
	else { y = -x; }
	hx &= 0x7fffffff;
	if (hx >= 0x4043687a) {
		if (hx >= 0x40862e42) {
			if (hx >= 0x7ff00000) {
				uint32_t low;
				GET_LOW_WORD(low, x);
				if (((hx & 0xfffff) | low) != 0) { return x + x; }
				else { return (xsb == 0) ? x : -1.0; }
			} else if (x > BIGX) { return HUGE_SQ; }
		}
		if ((xsb != 0) && (x + TINY < 0.0)) { return TINY - 1.0; }
	}
	if (hx > 0x3fd62e42) {
		double hi, lo;
		if (hx < 0x3ff0a2b2) {
			if (xsb == 0) {
				hi = x - 6.93147180369123816490E-1;
				lo = 1.90821492927058770002E-10;
				k = 1;
			} else {
				hi = x + 6.93147180369123816490E-1;
				lo = -1.90821492927058770002E-10;
				k = -1;
			}
		} else {
			k = (int32_t)(M_LOG2E * x + ((xsb == 0) ? 0.5 : -0.5));
			t = (double)k;
			hi = x - t * 6.93147180369123816490E-1;
			lo = t * 1.90821492927058770002E-10;
		}
		x = hi - lo;
		c = (hi - x) - lo;
	} else if (hx < 0x3c900000) {
		t = HUGE + x;
		return x - (t - (HUGE + x));
	} else { k = 0; }
	const double hfx = 0.5 * x;
	const double hxs = x * hfx;
	const double r1 = 1.0 + hxs * (-3.33333333333331316428E-2 + hxs * (1.58730158725481460165E-3 + hxs * (-7.93650757867487942473E-5 + hxs * (4.00821782732936239552E-6 + hxs * -2.01099218183624371326E-7))));
	t = 3.0 - r1 * hfx;
	e = hxs * ((r1 - t) / (6.0 - x * t));
	if (k == 0) { return x - (x * e - hxs); }
	else {
		e = (x * (e - c) - c);
		e -= hxs;
		if (k == -1) { return 0.5 * (x - e) - 0.5; }
		else if (k == 1) {
			if (x < -0.25) { return -2.0 * (e - (x + 0.5)); }
			else { return 1.0 + 2.0 * (x - e); }
		} else if (k <= -2 || k > 56) {
			uint32_t high;
			y = 1.0 - (e - x);
			GET_HIGH_WORD(high, y);
			SET_HIGH_WORD(y, (high + (uint32_t)(k << 20)));
			return y - 1.0;
		}
		t = 1.0;
		if (k < 20) {
			uint32_t high;
			SET_HIGH_WORD(t, 0x3ff00000 - (0x200000 >> k));
			y = t - (e - x);
			GET_HIGH_WORD(high, y);
			SET_HIGH_WORD(y, (high + (uint32_t)(k << 20)));
		} else {
			uint32_t high;
			SET_HIGH_WORD(t, ((0x3ff - k) << 20));
			y = x - (e + t);
			y += 1.0;
			GET_HIGH_WORD(high, y);
			SET_HIGH_WORD(y, (high + (uint32_t)(k << 20)));
		}
	}
	return y;
}
#define __expm1(x)   expm1((x))


#if LDBL_EQ_DBL
LIB_FUNC MATH_FUNC long double expm1l(const long double x) {
	return expm1(x);
}
#   define __expm1l(x)   expm1l((x))
#elif IS_LDBL_X87
LIB_FUNC MATH_FUNC long double expm1l(const long double x) {
	if (isnan(x)) { return x; }
	else if (x > 1.1356523406294143949492E+4L) { return x * 0x1.0P+16383L; }
	else if (x == 0.0) { return x; }
	else if (x < -4.5054566736396445112120088E+1L) { return -1.0L; }
	register long double px = floorl(0.5L + x / (6.93145751953125E-1L + 1.428606820309417232121458176568075500134E-6L));
	int k = px;
	long double _x = x;
	_x -= px * 6.93145751953125E-1L;
	_x -= px * 1.428606820309417232121458176568075500134E-6L;
	px = ((((-5.238523121205561042771939008061958820811E-1L * _x + 1.800826371455042224581246202420972737840E+1L) * _x + -3.423199068835684263987132888286791620673E+2L) * _x + 2.642771505685952966904660652518429479531E+3L) * _x + -1.586135578666346600772998894928250240826E+4L) * x;
	register long double qx = ((((x + -4.002027679107076077238836622982900945173E+1L) * _x + 7.206038318724600171970199625081491823079E+2L) * _x + -7.207678383830091850230366618190187434796E+3L) * _x + 3.964866271411091674556850458227710004570E+4L) * _x + -9.516813471998079611319047060563358064497E+4L;
	long double xx = _x * _x;
	qx = _x + (0.5L * xx + xx * px / qx);
	px = scalbnl(1.0L, k);
	return (px * qx + (px - 1.0L));
}
#   define __expm1l(x)   expm1l((x))
#endif


LIB_FUNC float frexpf(const float num, int* restrict e) {
#   ifdef ARCHX86
	float ret, exp_f;
	asm ("fxtract;" : "=t"(ret), "=u"(exp_f) : "0"(num));
	*e = (int)exp_f + 1;
	return 0.5F * ret;
#   else
	float x = num;
	union __union_frexpf { float f; uint32_t i; } y = { x };
	const int ee = (int)((y.i >> 23) & 0xff);
	if (!ee) {
		if (x) {
			x = frexpf((x * 0x1.0P+64F), e);
			*e -= 64;
		} else { *e = 0; }
		return x;
	} else if (ee == 0xff) { return x; }
	*e = ee - 0x7e;
	y.i &= 0x807fffffUL;
	y.i |= 0x3f000000UL;
	return y.f;
#   endif
}


LIB_FUNC double frexp(const double num, int* restrict e) {
#   ifdef ARCHX86
	double ret, exp_f;
	asm ("fxtract;" : "=t"(ret), "=u"(exp_f) : "0"(num));
	*e = (int)exp_f + 1;
	return 0.5 * ret;
#   else
	double x = num;
	union __union_frexp { double d; uint64_t i; } y = { x };
	const int ee = (int)((y.i >> 52) & 0x7ff);
	if (!ee) {
		if (x) {
			x = frexp((x * 0x1.0P+64), e);
			*e -= 64;
		} else  { *e = 0; }
		return x;
	} else if (ee == 0x7ff) { return x; }
	*e = ee - 0x3fe;
	y.i &= 0x800fffffffffffffULL;
	y.i |= 0x3fe0000000000000ULL;
	return y.d;
#   endif
}


#if (!LDBL_EQ_DBL)
LIB_FUNC long double frexpl(const long double num, int* restrict e) {
	long double x = num;
	long_double_shape_t u = { .value = x };
	const int ee = u.uparts16.w0 & 0x7fff;
	if (!ee) {
		if (x) {
			x = frexpl((x * 0x1.0P+120L), e);
			*e -= 120;
		} else { *e = 0; }
		return x;
	} else if (ee == 0x7fff) { return x; }
	*e = ee - 0x3ffe;
	u.uparts16.w0 &= 0x8000;
	u.uparts16.w0 |= 0x3ffe;
	return u.value;
}
#   define __frexpl(x, e)   frexpl((x), (e))
#else
LIB_FUNC long double frexpl(const long double x, int* restrict e) {
	return (long double)frexp((double)x, e);
}
#   define __frexpl(x, e)   frexpl((x), (e))
#endif


LIB_FUNC MATH_FUNC float iexpf(const int expo) {
	register float ret = 1.0F;
	register float m = 10.0F;
	register unsigned int e = (unsigned int)expo;
	if (expo < 0) {
		e = (unsigned int)-e;
		m = 1.0F / m;
	}
	until_break {
		if (e & 1) { ret *= m; }
		if ((e >>= 1) == 0) { break; }
		m *= m;
	}
	return ret;
}


LIB_FUNC MATH_FUNC double iexp(const int expo) {
	register double ret = 1.0;
	register double m = 10.0;
	register unsigned int e = (unsigned int)expo;
	if (expo < 0) {
		e = (unsigned int)-e;
		m = 1.0 / m;
	}
	until_break {
		if (e & 1) { ret *= m; }
		if ((e >>= 1) == 0) { break; }
		m *= m;
	}
	return ret;
}


LIB_FUNC MATH_FUNC float i64expf(const int64_t expo) {
	register float ret = 1.0F;
	register float m = 10.0F;
	register uint64_t e = (uint64_t)expo;
	if (expo < 0) {
		e = (uint64_t)-e;
		m = 1.0F / m;
	}
	until_break {
		if (e & 1) { ret *= m; }
		if ((e >>= 1) == 0) { break; }
		m *= m;
	}
	return ret;
}


LIB_FUNC MATH_FUNC double i64exp(const int64_t expo) {
	register double ret = 1.0;
	register double m = 10.0;
	register uint64_t e = (uint64_t)expo;
	if (expo < 0) {
		e = (uint64_t)-e;
		m = 1.0 / m;
	}
	until_break {
		if (e & 1) { ret *= m; }
		if ((e >>= 1) == 0) { break; }
		m *= m;
	}
	return ret;
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double iexpl(const int expo) {
	register long double ret = 1.0L;
	register long double m = 10.0L;
	register unsigned int e = (unsigned int)expo;
	if (expo < 0) {
		e = (unsigned int)-e;
		m = 1.0L / m;
	}
	until_break {
		if (e & 1) { ret *= m; }
		if ((e >>= 1) == 0) { break; }
		m *= m;
	}
	return ret;
}
#endif


// ROOT FUNCTIONS

LIB_FUNC MATH_FUNC float __ieee754_sqrtf(const float x) {
#ifdef ARCHAARCH64
	float res;
	asm ("fsqrt %s0, %s1;" : "=w"(res) : "w"(x));
	return res;
#elif defined(ARCHALPHA)
	float res;
#   ifdef _IEEE_FP_INEXACT
	asm ("sqrts/suid %1, %0;" : "=f"(res) : "f"(x));
#   else
	asm ("sqrts/sud %1, %0;" : "=f"(res) : "f"(x));
#   endif
	return ret;
#elif defined(ARCHPOWERPC)
	float res;
	asm ("fsqrts %0, %1;" : "=f"(res) : "f"(x));
	return res;
#elif (defined(ARCHX86) && (CPU_AVX || CPU_SSE2AVX))
	float res;
#   if CPU_AVX
	asm ("vsqrtss %1, %0, %0;" : "=x"(res) : "xm"(x));
#   elif (CPU_SSE2AVX || CPU_SSE)
	asm ("sqrtss %1, %0;" : "=x"(res) : "xm"(x));
#   endif
	return res;
#elif (defined(ARCHX86) && (!(CPU_AVX || CPU_SSE2AVX)))
	float res = x;
	asm ("fld %0;" "fsqrt;" "fstp %1;" : "=m"(res) : "m"(res));
	return res;
#else
	if (x <= 0.0F) {
		if (x < 0.0F) { return NANF; }
		return 0.0F;
	} else if (__isinff(x)) { return x; }
	register float est = x, nest = x - 1.0F;
	register int i;
	for (i = 0; (est != nest) && i != 20; i++) {
		est = nest;
		nest = est - (est * est - x) / (2.0F * est);
	}
	return nest;
#endif
}


LIB_FUNC MATH_FUNC double __ieee754_sqrt(const double x) {
#ifdef ARCHAARCH64
	double res;
	asm ("fsqrt %d0, %d1;" : "=w"(res) : "w"(x));
	return res;
#elif defined(ARCHALPHA)
	double res;
#   ifdef _IEEE_FP_INEXACT
	asm ("sqrtt/suid %1, %0;" : "=f"(res) : "f"(x));
#   else
	asm ("sqrtt/sud %1, %0;" : "=f"(res) : "f"(x));
#   endif
	return res;
#elif defined(ARCHPOWERPC)
	double res;
	asm ("fsqrt %0, %1;" : "=f"(res) : "f"(x));
	return res;
#elif (defined(ARCHX86) && (CPU_AVX || CPU_SSE2AVX))
	double res;
#   if CPU_AVX
	asm ("vsqrtsd %1, %0, %0;" : "=x"(res) : "xm"(x));
#   elif (CPU_SSE2AVX || CPU_SSE)
	asm ("sqrtsd %1, %0;" : "=x"(res) : "xm"(x));
#   endif
	return res;
#elif (defined(ARCHX86) && (!(CPU_AVX || CPU_SSE2AVX)))
	double res = x;
	asm ("fldl %0;" "fsqrt;" "fstpl %1;" : "=m"(res) : "m"(res));
	return res;
#else
	if (x <= 0.0) {
		if (x < 0.0) { return NAN; }
		return 0.0;
	} else if (__isinf(x)) { return x; }
	register double est = x, nest = x - 1.0;
	register int i;
	for (i = 0; (est != nest) && i != 20; i++) {
		est = nest;
		nest = est - (est * est - x) / (2.0 * est);
	}
	return nest;
#endif
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double __ieee754_sqrtl(const long double d) {
	return (long double)__ieee754_sqrt((double)d);
}
#endif


LIB_FUNC MATH_FUNC float sqrtf(const float x) {
#if IS_LIBM_POSIX
	return __ieee754_sqrtf(x);
#else
	const float z = __ieee754_sqrtf(x);
	if (__isnanf(x)) { return z; }
	else if (x < 0.0F) {
		exc.type = DOMAIN;
		exc.name = "sqrtf";
		exc.err = EDOM;
		exc.arg1 = exc.arg2 = (double)x;
		exc.retval = 0.0 / 0.0;
		matherr(&exc);
		return (float)exc.retval;
	} else { return z; }
#endif
}


LIB_FUNC MATH_FUNC double sqrt(const double x) {
#if IS_LIBM_POSIX
	return __ieee754_sqrt(x);
#else
	const double z = __ieee754_sqrt(x);
	if (__isnan(x)) { return z; }
	else if (x < 0.0) {
		exc.type = DOMAIN;
		exc.name = "sqrt";
		exc.err = EDOM;
		exc.arg1 = exc.arg2 = x;
		exc.retval = 0.0 / 0.0;
		matherr(&exc);
		return exc.retval;
	} else { return z; }
#endif
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double sqrtl(const long double x) {
	return (long double)sqrt((double)x);
}
#endif


/** Return the cubed root of x */
LIB_FUNC MATH_FUNC float cbrtf(const float num) {
	float x = num;
	int32_t hx;
	GET_FLOAT_WORD(hx, x);
	const uint32_t sign = (uint32_t)((uint32_t)hx & 0x80000000);
	hx = (int32_t)(hx ^ (int32_t)sign);
	if (!FLT_UWORD_IS_FINITE(hx)) { return x + x; }
	else if (FLT_UWORD_IS_ZERO(hx)) { return x; }
	SET_FLOAT_SWORD(x, hx);
	uint32_t high;
	float t = 0.0F;
	if (FLT_UWORD_IS_SUBNORMAL(hx)) {
		SET_FLOAT_WORD(t, 0x4b800000);
		t *= x;
		GET_FLOAT_UWORD(high, t);
		SET_FLOAT_UWORD(t, (high / 3 + (uint32_t)642849266));
	}
	else { SET_FLOAT_UWORD(t, ((uint32_t)(hx / 3) + (uint32_t)709958130)); }
	const float r = t * t / x;
	const float s = 5.4285717010E-1F + r * t;
	t *= 3.5714286566E-1F + 1.6071428061F / (s + 1.4142856598F + -7.0530611277E-1F / s);
	GET_FLOAT_UWORD(high, t);
	SET_FLOAT_UWORD(t, (high | sign));
	return t;
}


/** Return the cubed root of x */
LIB_FUNC MATH_FUNC double cbrt(const double num) {
	int32_t hx;
	double t = 0.0, x = num;
	GET_HIGH_SIGNED_WORD(hx, x);
	const uint32_t sign = (uint32_t)((uint32_t)hx & 0x80000000);
	hx = (int32_t)(hx ^ (int32_t)sign);
	if (hx >= 0x7ff00000) { return x + x; }
	uint32_t low;
	GET_LOW_WORD(low, x);
	if ((((uint32_t)hx) | low) == 0) { return x; }
	SET_HIGH_WORD(x, hx);
	uint32_t high;
	if (hx < 0x100000) {
		SET_HIGH_WORD(t, 0x43500000);
		t *= x;
		GET_HIGH_WORD(high, t);
		SET_HIGH_WORD(t, ((uint32_t)(high / 3) + (uint32_t)696219795));
	} else { SET_HIGH_WORD(t, ((uint32_t)(hx / 3) + (uint32_t)715094163)); }
	double r = (t * t) / x;
	double s = 5.42857142857142815906E-1 + r * t;
	t *= (3.57142857142857150787E-1 + 1.60714285714285720630 / (s + 1.41428571428571436819 + (-7.05306122448979611050E-1 / s)));
	GET_HIGH_WORD(high, t);
	INSERT_WORDS(t, (high + 1), 0);
	s = t * t;
	r = x / s;
	r = (r - t) / ((t + t) + r);
	t = t + (t * r);
	GET_HIGH_WORD(high, t);
	SET_HIGH_WORD(t, (high | sign));
	return t;
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double cbrtl(const long double num) {
	return (long double)cbrt((double)num);
}
#endif


/** Approximate (and rounded) square-root of an unsigned long long */
LIB_FUNC MATH_FUNC unsigned long long sqrtull(const unsigned long long num) {
	register unsigned long long y = 1, delta = 3;
	while (y <= num) {
		y += delta;  // (y+1)^2
		delta += 2ULL;
	}
	return ((delta >> 1) - 1);
}


/** Return the Square-Root of a positive number (Limit: 1000000000.0) */
LIB_FUNC MATH_FUNC float squarerootf(const float num) {
	if (num < 0.0F) { return -1.0F; }
	else if (floorf(num) == num && num <= 81.0F) {
		if (num == 0.0F) { return 0.0F; }
		else if (num == 1.0F) { return 1.0F; }
		else if (num == 4.0F) { return 2.0F; }
		else if (num == 9.0F) { return 3.0F; }
		else if (num == 16.0F) { return 4.0F; }
		else if (num == 25.0F) { return 5.0F; }
		else if (num == 36.0F) { return 6.0F; }
		else if (num == 49.0F) { return 7.0F; }
		else if (num == 64.0F) { return 8.0F; }
		else if (num == 81.0F) { return 9.0F; }
	}
	register float start = 0.0F;  // if num < 1; then 0 < num < sqrt(num); else 0 < sqrt(num) < num
	register float end = (num < 1.0F ? 1.0F : num);
	register float mid, midSqr;
	while ((end - start) > 0.0001F) {  // Define precision
		mid = (start + end) * 0.5F;
		midSqr = mid * mid;
		if (midSqr == num) { return mid; }  // Exact sqrt value
		else if (midSqr < num) { start = mid; }
		else { end = mid; }
	}
	return ((start + end) * 0.5F);
}


/** Return the Square-Root of a positive number (Limit: 1000000000000000.0) */
LIB_FUNC MATH_FUNC double squareroot(const double num) {
	if (num < 0.0) { return -1.0; }
	else if (floor(num) == num && num <= 81.0) {
		if (num == 0.0) { return 0.0; }
		else if (num == 1.0) { return 1.0; }
		else if (num == 4.0) { return 2.0; }
		else if (num == 9.0) { return 3.0; }
		else if (num == 16.0) { return 4.0; }
		else if (num == 25.0) { return 5.0; }
		else if (num == 36.0) { return 6.0; }
		else if (num == 49.0) { return 7.0; }
		else if (num == 64.0) { return 8.0; }
		else if (num == 81.0) { return 9.0; }
	}
	register double start = 0.0;  // if num < 1; then 0 < num < sqrt(num); else 0 < sqrt(num) < num
	register double end = (num < 1.0 ? 1.0 : num);
	register double mid, midSqr;
	while ((end - start) > 0.00001) {  // Define precision
		mid = (start + end) * 0.5;
		midSqr = mid * mid;
		if (midSqr == num) { return mid; }  // Exact sqrt value
		else if (midSqr < num) { start = mid; }
		else { end = mid; }
	}
	return ((start + end) * 0.5);
}


#if SUPPORTS_LONG_DOUBLE
/** Return the Square-Root of a positive number */
LIB_FUNC MATH_FUNC long double squarerootl(const long double num) {
	if (num < 0.0L) { return -1.0L; }
	else if (floorl(num) == num && num <= 81.0L) {
		if (num == 0.0L) { return 0.0L; }
		else if (num == 1.0L) { return 1.0L; }
		else if (num == 4.0L) { return 2.0L; }
		else if (num == 9.0L) { return 3.0L; }
		else if (num == 16.0L) { return 4.0L; }
		else if (num == 25.0L) { return 5.0L; }
		else if (num == 36.0L) { return 6.0L; }
		else if (num == 49.0L) { return 7.0L; }
		else if (num == 64.0L) { return 8.0L; }
		else if (num == 81.0L) { return 9.0L; }
	}
	register long double start = 0.0L;  // if num < 1; then 0 < num < sqrt(num); else 0 < sqrt(num) < num
	register long double end = (num < 1.0L ? 1.0L : num);
	register long double mid, midSqr;
	while ((end - start) > 0.00000001L) {  // Define precision
		mid = (start + end) * 0.5L;
		midSqr = mid * mid;
		if (midSqr == num) { return mid; }  // Exact sqrt value
		else if (midSqr < num) { start = mid; }
		else { end = mid; }
	}
	return ((start + end) * 0.5L);
}
#endif


/** Approximate square root of an integer */
LIB_FUNC MATH_FUNC uint8_t sqrt16(const uint16_t num) {
	register uint8_t x = 8, y = 8;
	loop_forever {
		if ((uint16_t)(y * y) > num) { y ^= x; }
		x >>= 1;
		if (x == 0) { return y; }
		y |= x;
	}
}


/** Approximate square root of an integer */
LIB_FUNC MATH_FUNC uint16_t sqrt32(const uint32_t num) {
	register uint16_t x = 0x80, y = 0x80;
	loop_forever {
		if ((uint32_t)(y * y) > num) { y ^= x; }
		x >>= 1;
		if (x == 0) { return y; }
		y |= x;
	}
}


/** Approximate square root of an integer */
LIB_FUNC MATH_FUNC uint32_t sqrt64(const uint64_t num) {
	register uint32_t x = 0x8000, y = 0x8000;
	loop_forever {
		if ((uint64_t)(y * y) > num) { y ^= x; }
		x >>= 1;
		if (x == 0) { return y; }
		y |= x;
	}
}


/** Inverse Square Root of an integer */
LIB_FUNC MATH_FUNC uint8_t isqrt8(const uint8_t num) {
	register uint8_t root = 0, remainder = num, place = 0x40;
	while (place > remainder) { place >>= 2; }
	while (place) {
		if (remainder >= (root + place)) {
			remainder = (uint8_t)((remainder - root) - place);
			root = (uint8_t)(root + (uint8_t)((uint8_t)place << (uint8_t)1));
		}
		root >>= 1;
		place >>= 2;
	}
	return root;
}


/** Inverse Square Root of an integer */
LIB_FUNC MATH_FUNC uint16_t isqrt16(const uint16_t num) {
	register uint16_t root = 0, remainder = num, place = 0x4000;
	while (place > remainder) { place >>= 2; }
	while (place) {
		if (remainder >= (root + place)) {
			remainder = (uint16_t)((remainder - root) - place);
			root = (uint16_t)(root + ((uint16_t)place << (uint16_t)1));
		}
		root >>= 1;
		place >>= 2;
	}
	return root;
}


/** Inverse Square Root of an integer */
LIB_FUNC MATH_FUNC uint32_t isqrt32(const uint32_t num) {
	register uint32_t root = 0, remainder = num, place = 0x40000000;
	while (place > remainder) { place >>= 2; }
	while (place) {
		if (remainder >= (root + place)) {
			remainder = (uint32_t)((remainder - root) - place);
			root += (uint32_t)(place << 1);
		}
		root >>= 1;
		place >>= 2;
	}
	return root;
}


/** Inverse Square Root of an integer */
LIB_FUNC MATH_FUNC uint64_t isqrt64(const uint64_t num) {
	register uint64_t root = 0, remainder = num, place = 0x4000000000000000;
	while (place > remainder) { place >>= 2; }
	while (place) {
		if (remainder >= (root + place)) {
			remainder = (uint64_t)((remainder - root) - place);
			root += (uint64_t)(place << 1);
		}
		root >>= 1;
		place >>= 2;
	}
	return root;
}


/** Return the Triangular root of the given number ((√(8*num+1)−1)/2) */
LIB_FUNC MATH_FUNC double triangular_root(const long num) {
	return ((sqrt((double)(8 * num + 1)) - 1.0) * 0.5);
}


/** Return the Hexagonal root of the given number ((√(8*num+1)+1)/4) */
LIB_FUNC MATH_FUNC double hexagonal_root(const long num) {
	return ((sqrt((double)(8 * num + 1)) + 1.0) * 0.25);
}


/** Return the Heptagonal root of the given number ((√(40*num+9)+3)/10) */
LIB_FUNC MATH_FUNC double heptagonal_root(const long num) {
	return ((sqrt((double)(40 * num + 9)) + 3.0) * 0.1);
}


// LOGARITHM FUNCTIONS

/** 2**x - 1, for -1 <= x <= 1 */
LIB_FUNC MATH_FUNC double f2xm1(const double x) {
	double ret;
	assert(x >= -1.0 && x <= 1.0);
	asm ("f2xm1;" : "=t"(ret) : "0"(x));
	return ret;
}


/** 2**x */
LIB_FUNC MATH_FUNC double f2x(const double x) {
	const double x_fl = floor(x);
	return ldexp(1.0 + f2xm1((x - x_fl)), (int)x_fl);
}


LIB_FUNC MATH_FUNC float __ieee754_logf(const float num) {
#   ifdef ARCHX86
	float ret;
	asm ("fyl2x;" : "=t"(ret) : "0"(num), "u"(M_LN2F) : "st(1)");
	return ret;
#   else
	float x = num;
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	int32_t k = 0;
	if (ix < 0x800000) {
		if (PREDICT_UNLIKELY((ix & 0x7fffffff) == 0)) { return -3.355443200E+7F / (x - x); }
		else if (PREDICT_UNLIKELY(ix < 0)) { return (x - x) / (x - x); }
		k -= 25;
		x *= 3.355443200E+7F;
		GET_FLOAT_WORD(ix, x);
	}
	if (PREDICT_UNLIKELY(ix >= 0x7f800000)) { return x + x; }
	k += (ix >> 23) - 127;
	ix &= 0x7fffff;
	int32_t i = (ix + (0x95f64 << 3)) & 0x800000;
	SET_FLOAT_SWORD(x, (ix | (i ^ 0x3f800000)));
	k += (i >> 23);
	const float f = x - 1.0F;
	float dkl
	if ((0x7fffff & (15 + ix)) < 16) {
		if (f == 0.0F) {
			if (k == 0) { return 0.0F; }
			else {
				dk = (float)k;
				return dk * 6.9313812256E-1F + dk * 9.0580006145E-6F;
			}
		}
		const float R = f * f * (0.5F - 0.33333333333333333F * f);
		if (k == 0) { return f - R; }
		dk = (float)k;
		return dk * 6.9313812256E-1F - ((R - dk * 9.0580006145E-6F) - f);
	}
	const float s = f / (2.0F + f);
	dk = (float)k;
	const float z = s * s;
	const float w = z * z;
	const float t1 = w * (4.0000000596E-1F + w * (2.2222198546E-1F + w * 1.5313838422E-1F));
	const float t2 = z * (6.6666668653E-1F + w * (2.8571429849E-1F + w * (1.8183572590E-1F + w * 1.4798198640E-1F)));
	i |= (0x35c288 - (ix - 0x30a3d0));
	const float R = t2 + t1;
	if (i > 0) {
		const float hfsq = 0.5F * f * f;
		if (k == 0) { return f - (hfsq - s * (hfsq + R)); }
		else { return dk * 6.9313812256E-1F - ((hfsq - (s * (hfsq + R) + dk * 9.0580006145E-6F)) - f); }
	} else {
		if (k == 0) { return f - s * (f - R); }
		return dk * 6.9313812256E-1F - ((s * (f - R) - dk * 9.0580006145E-6F) - f);
	}
#   endif
}
#define __logf_finite(x)   __ieee754_logf((x))


LIB_FUNC MATH_FUNC double __ieee754_log(const double num) {
#   ifdef ARCHX86
	double ret;
	asm ("fyl2x;" : "=t"(ret) : "0"(num), "u"(M_LN2) : "st(1)");
	return ret;
#   else
	double x = num;
	int32_t hx, lx;
	EXTRACT_SWORDS(hx, lx, x);
	int32_t k = 0;
	if (hx < 0x100000) {
		if (((hx & 0x7fffffff) | lx) == 0) { return -1.80143985094819840000E+16 / 0.0; }
		else if (hx < 0) { return (x - x) / 0.0; }
		k -= 54;
		x *= 1.80143985094819840000E+16;
		GET_HIGH_SWORD(hx, x);
	}
	if (hx >= 0x7ff00000) { return x + x; }
	k += (hx >> 20) - 1023;
	hx &= 0xfffff;
	int32_t i = (hx + 0x95f64) & 0x100000;
	SET_HIGH_WORD(x, (hx | (i ^ 0x3ff00000)));
	k += (i >> 20);
	double f = x - 1.0;
	double dk;
	if ((0xfffff & (2 + hx)) < 3) {
		if (f == 0.0) {
			if (k == 0) { return 0.0; }
			else {
				dk = (double)k;
				return dk * 6.93147180369123816490E-1 + dk * 1.90821492927058770002E-10;
			}
		}
		const double R = f * f * (0.5 - 0.33333333333333333 * f);
		if (k == 0) { return f - R; }
		dk = (double)k;
		return dk * 6.93147180369123816490E-1 - ((R - dk * 1.90821492927058770002E-10) - f);
	}
	const double s = f / (2.0 + f);
	dk = (double)k;
	const double z = s * s;
	const double w = z * z;
	const double t1 = w * (3.999999999940941908E-1 + w * (2.222219843214978396E-1 + w * 1.53138376992093733E-1));
	const double t2 = z * (6.666666666666735130E-1 + w * (2.857142874366239149E-1 + w * (1.818357216161805012E-1 + w * 1.479819860511658591E-1)));
	i |= (0x6b851 - (hx - 0x6147a));
	const double R = t2 + t1;
	if (i > 0) {
		const double hfsq = 0.5 * f * f;
		if (k == 0) { return f - (hfsq - s * (hfsq + R)); }
		else { return dk * 6.93147180369123816490E-1 - ((hfsq - (s * (hfsq + R) + dk * 1.90821492927058770002E-10)) - f); }
	} else if (k == 0) { return f - s * (f - R); }
	return dk * 6.93147180369123816490E-1 - ((s * (f - R) - dk * 1.90821492927058770002E-10) - f);
#   endif
}
#define __log_finite(x)   __ieee754_log((x))


#if LDBL_EQ_FLOAT128
LIB_FUNC MATH_FUNC long double __ieee754_logl(const long double num) {
	long double z, y, w, x = num;
	long_double_shape_t u = { .value = x }, t;
	unsigned int m = u.uparts32.w0;
	int k = m & 0x7fffffff;
	if (((uint32_t)k | u.uparts32.w1 | u.uparts32.w2 | u.uparts32.w3) == 0) { return -0.5L / ieee754_logtbl[38]; }
	else if (m & 0x80000000) { return (x - x) / ieee754_logtbl[38]; }
	else if (k >= 0x7fff0000) { return x + x; }
	int e;
	u.value = frexpl(x, &e);
	m = u.uparts32.w0 & 0xffff;
	m |= 0x10000;
	if (m < 0x16800) {
		k = (int)((m - 0xff00) >> 9);
		t.uparts32.w0 = (uint32_t)(0x3fff0000 + (k << 9));
		t.uparts32.w1 = 0;
		t.uparts32.w2 = 0;
		t.uparts32.w3 = 0;
		u.uparts32.w0 += 0x10000;
		e -= 1;
		k += 64;
	} else {
		k = (int)((m - 0xfe00) >> 10);
		t.uparts32.w0 = (uint32_t)(0x3ffe0000 + (k << 10));
		t.uparts32.w1 = 0;
		t.uparts32.w2 = 0;
		t.uparts32.w3 = 0;
	}
	if ((x <= 1.0078125L) && (x >= 0.9921875L)) {
		if (x == 1.0L) { return 0.0L; }
		z = x - 1.0L;
		k = 64;
		t.value = 1.0L;
		e = 0;
	} else {
		z = (u.value - t.value) / t.value;
	}
	w = z * z;
	y = ((((((((((((6.668057591071739754844678883223432347481E-2L * z + -7.144242754190814657241902218399056829264E-2L) * z + 7.692307559897661630807048686258659316091E-2L) * z + -8.333333211818065121250921925397567745734E-2L) * z + 9.090909090915566247008015301349979892689E-2L) * z + -1.000000000000532974938900317952530453248E-1L) * z + 1.111111111111111093947834982832456459186E-1L) * z + -1.249999999999999987884655626377588149000E-1L) * z + 1.428571428571428571428808945895490721564E-1L) * z + -1.666666666666666666666798448356171665678E-1L) * z + 1.999999999999999999999999998515277861905E-1L) * z + -2.499999999999999999999999999486853077002E-1L) * z + 3.333333333333333333333333333333336096926E-1L) * z * w;
	y -= 0.5 * w;
	y += e * 1.4286068203094172321214581765680755001344E-6L;
	y += z;
	y += ieee754_logtbl[k - 26];
	y += (t.value - 1.0L);
	y += e * 6.93145751953125E-1L;
	return y;
}
#   define __logl_finite(x)   __ieee754_logl((x))
#else
LIB_FUNC MATH_FUNC long double __ieee754_logl(const long double num) {
	return (long double)__ieee754_log((double)num);
}
#endif


LIB_FUNC MATH_FUNC float logf(const float x) {
	if (PREDICT_UNLIKELY(__islessequalf(x, 0.0F))) {
		if (x == 0.0F) {
			feraiseexcept(FE_DIVBYZERO);
			return __kernel_standard_f(x, x, 116);
		} else {
			feraiseexcept(FE_INVALID);
			return __kernel_standard_f(x, x, 117);
		}
	}
	return __ieee754_logf(x);
}
#define __logf(x)   logf((x))


LIB_FUNC MATH_FUNC double log(const double x) {
	if (PREDICT_UNLIKELY(__islessequal(x, 0.0))) {
		if (x == 0.0) {
			__feraiseexcept(FE_DIVBYZERO);
			return __kernel_standard(x, x, 16);
		} else {
			__feraiseexcept(FE_INVALID);
			return __kernel_standard(x, x, 17);
		}
	}
	return __ieee754_log(x);
}
#define __log(x)   log((x))


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double logl(const long double x) {
	if (PREDICT_UNLIKELY(__islessequall(x, 0.0L))) {
		if (x == 0.0L) {
			feraiseexcept(FE_DIVBYZERO);
			return __kernel_standard_l(x, x, 216);
		} else {
			feraiseexcept(FE_INVALID);
			return __kernel_standard_l(x, x, 217);
		}
	}
	return __ieee754_logl(x);
}
#   define __logl(x)   logl((x))
#endif


LIB_FUNC MATH_FUNC float __ieee754_log2f(const float num) {
#   ifdef ARCHX86
	float ret;
	asm ("fyl2x;" : "=t"(ret) : "0"(num), "u"(1.0F) : "st(1)");
	return ret;
#   else
	float x = num;
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	int32_t k = 0;
	if (ix < 0x800000) {
		if (PREDICT_UNLIKELY((ix & 0x7fffffff) == 0)) { return -3.355443200E+7F / (x - x); }
		else if (PREDICT_UNLIKELY(ix < 0)) { return (x - x) / (x - x); }
		k -= 25;
		x *= 3.355443200E+7F;
		GET_FLOAT_WORD(ix, x);
	}
	if (PREDICT_UNLIKELY(ix >= 0x7f800000)) { return x + x; }
	k += (ix >> 23) - 127;
	ix &= 0x7fffff;
	int32_t i = (ix + (0x95f64 << 3)) & 0x800000;
	SET_FLOAT_SWORD(x, (ix | (i ^ 0x3f800000)));
	k += (i >> 23);
	const float dk = (float)k;
	const float f = x - 1.0F;
	if ((0x7fffff & (15 + ix)) < 16) {
		if (f == 0.0F) {
			if (FIX_INT_FP_CONVERT_ZERO && dk == 0.0F) { dk = 0.0F; }
			return dk;
		}
		const float R = f * f * (0.5F - 0.33333333333333333F * f);
		return dk - (R - f) / M_LN2F;
	}
	const float s = f / (2.0F + f);
	const float z = s * s;
	const float w = z * z;
	i |= (0x35c288 - (ix - 0x30a3d0));
	const float R = (z * (6.6666668653E-1F + w * (2.8571429849E-1F + w * (1.8183572590E-1F + w * 1.4798198640E-1F)))) + (w * (4.0000000596E-1F + w * (2.2222198546E-1F + w * 1.5313838422E-1F)));
	if (i > 0) {
		const float hfsq = 0.5F * f * f;
		return dk - ((hfsq - (s * (hfsq + R))) - f) / M_LN2F;
	}
	return dk - ((s * (f - R)) - f) / M_LN2F;
#   endif
}
#define __log2f_finite(x)   __ieee754_log2f((x))


LIB_FUNC MATH_FUNC double __ieee754_log2(const double num) {
#   ifdef ARCHX86
	double ret;
	asm ("fyl2x;" : "=t"(ret) : "0"(num), "u"(1.0) : "st(1)");
	return ret;
#   else
	double x = num;
	int32_t hx, lx;
	EXTRACT_SWORDS(hx, lx, x);
	int32_t k = 0;
	if (hx < 0x100000) {
		if (PREDICT_UNLIKELY(((hx & 0x7fffffff) | lx) == 0)) { return -1.80143985094819840000E+16 / (x - x); }
		if (PREDICT_UNLIKELY(hx < 0)) { return (x - x) / (x - x); }
		k -= 54;
		x *= 1.80143985094819840000E+16;
		GET_HIGH_SWORD(hx, x);
	}
	if (PREDICT_UNLIKELY(hx >= 0x7ff00000)) { return x + x; }
	k += (hx >> 20) - 1023;
	hx &= 0xfffff;
	int32_t i = (hx + 0x95f64) & 0x100000;
	SET_HIGH_WORD(x, (uint32_t)(hx | (i ^ 0x3ff00000)));
	k += (i >> 20);
	const double dk = (double)k;
	const double f = x - 1.0;
	if ((0xfffff & (2 + hx)) < 3) {
		if (f == 0.0) {
			if (FIX_INT_FP_CONVERT_ZERO && dk == 0.0) { dk = 0.0; }
			return dk;
		}
		return dk - ((f * f * (0.5 - 0.33333333333333333 * f)) - f) / M_LN2;
	}
	const double s = f / (2.0 + f);
	const double z = s * s;
	const double w = z * z;
	i |= (0x6b851 - (hx - 0x6147a));
	const double R = (z * (6.666666666666735130E-1 + w * (2.857142874366239149E-1 + w * (1.818357216161805012E-1 + w * 1.479819860511658591E-1)))) + (w * (3.999999999940941908E-1 + w * (2.222219843214978396E-1 + w * 1.531383769920937332E-1)));
	if (i > 0) {
		const double hfsq = 0.5 * f * f;
		return dk - ((hfsq - (s * (hfsq + R))) - f) / M_LN2;
	}
	return dk - ((s * (f - R)) - f) / M_LN2;
#   endif
}
#define __log2_finite(x)   __ieee754_log2((x))


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC long double neval(const long double x, const long double* restrict p, int n) {
	p += n;
	long double y = *p--;
	do { y = (long double)(y * x + *p--); } while (--n > 0);
	return y;
}


LIB_FUNC long double deval(const long double x, const long double* restrict p, int n) {
	p += n;
	long double y = x + *p--;
	do { y = (long double)(y * x + *p--); } while (--n > 0);
	return y;
}
#endif


#if LDBL_EQ_FLOAT128
LIB_FUNC long double __ieee754_log2l(const long double num) {
	long double x = num;
	int64_t hx = 0, lx = 0;
	GET_LDOUBLE_SWORDS64(hx, lx, x);
	if (((hx & 0x7fffffffffffffffLL) | lx) == 0) { return (-1.0L / (x - x)); }
	else if (hx < 0) { return (x - x) / (x - x); }
	else if (hx >= 0x7fff000000000000LL) { return (x + x); }
	else if (x == 1.0L) { return 0.0L; }
	int e = 0;
	x = frexpl(x, &e);
	long double y = 0.0L, z = 0.0L;
	if ((e > 2) || (e < -2)) {
		if (x < 7.071067811865475244008443621048490392848359E-1L) {
			e -= 1;
			z = x - 0.5L;
			y = 0.5L * z + 0.5L;
		} else {
			z = x - 0.5L;
			z -= 0.5L;
			y = 0.5L * x + 0.5L;
		}
		x = z / y;
		z = x * x;
		y = x * (z * neval(z, ieee754_log2l_R, 5) / deval(z, ieee754_log2l_S, 5));
		goto goto_ieee754_log2l_done;
	}
	if (x < 7.071067811865475244008443621048490392848359E-1L) {
		e -= 1;
		x = 2.0L * x - 1.0L;
	} else { x = x - 1.0L; }
	z = x * x;
	y = x * (z * neval(x, ieee754_log2l_P, 12) / deval(x, ieee754_log2l_Q, 11));
	y = y - 0.5L * z;
goto_ieee754_log2l_done:
	z = y * 4.4269504088896340735992468100189213742664595E-1L;
	z += x * 4.4269504088896340735992468100189213742664595E-1L;
	z += y;
	z += x;
	z += e;
	return z;
}
#   define __log2l_finite(x)   __ieee754_log2l((x))
#else
LIB_FUNC long double __ieee754_log2l(const long double num) {
	return (long double)__ieee754_log2((double)num);
}
#   define __log2l_finite(x)   __ieee754_log2l((x))
#endif


LIB_FUNC MATH_FUNC float log2f(const float x) {
	if (PREDICT_UNLIKELY(__islessequalf(x, 0.0F))) {
		if (x == 0.0F) {
			feraiseexcept(FE_DIVBYZERO);
			return __kernel_standard_f(x, x, 148);
		} else {
			feraiseexcept(FE_INVALID);
			return __kernel_standard_f(x, x, 149);
		}
	}
	return __ieee754_log2f(x);
}
#define __log2f(x)   log2f((x))


LIB_FUNC MATH_FUNC double log2(const double x) {
	if (PREDICT_UNLIKELY(__islessequal(x, 0.0))) {
		if (x == 0.0) {
			feraiseexcept(FE_DIVBYZERO);
			return __kernel_standard(x, x, 48);
		} else {
			feraiseexcept(FE_INVALID);
			return __kernel_standard(x, x, 49);
		}
	}
	return __ieee754_log2(x);
}
#define __log2(x)   log2((x))


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double log2l(const long double x) {
	if (PREDICT_UNLIKELY(__islessequall(x, 0.0L))) {
		if (x == 0.0L) {
			feraiseexcept(FE_DIVBYZERO);
			return __kernel_standard_l(x, x, 248);
		} else {
			feraiseexcept(FE_INVALID);
			return __kernel_standard_l(x, x, 249);
		}
	}
	return __ieee754_log2l(x);
}
#   define __log2l(x)   log2l((x))
#endif


LIB_FUNC MATH_FUNC float __ieee754_log10f(const float num) {
	float y, z, x = num;
	int32_t i, k, hx;
	GET_FLOAT_WORD(hx, x);
	k = 0;
	if (hx < 0x00800000) {
		if (PREDICT_UNLIKELY((hx & 0x7fffffff) == 0)) { return -3.3554432000E+7F / (x - x); }
		else if (PREDICT_UNLIKELY(hx < 0)) { return (x - x) / (x - x); }
		k -= 25;
		x *= 3.3554432000E+7F;
		GET_FLOAT_WORD(hx, x);
	}
	if (PREDICT_UNLIKELY(hx >= 0x7f800000)) { return x + x; }
	k += (hx >> 23) - 127;
	i = (int32_t)(((uint32_t)k & 0x80000000) >> 31);
	hx = (hx & 0x007fffff) | ((0x7f - i) << 23);
	y = (float)(k + i);
	if (FIX_INT_FP_CONVERT_ZERO && y == 0.0F) { y = 0.0F; }
	SET_FLOAT_SWORD(x, hx);
	z = y * 7.9034151668E-7F + 4.3429449201E-1F * __ieee754_logf(x);
	return z + y * 3.0102920532E-1F;
}
#define __log10f_finite(x)   __ieee754_log10f((x))


LIB_FUNC MATH_FUNC double __ieee754_log10(const double num) {
	double y, z, x = num;
	int32_t i, k, hx, lx;
	EXTRACT_SWORDS(hx, lx, x);
	k = 0;
	if (hx < 0x100000) {
		if (PREDICT_UNLIKELY(((hx & 0x7fffffff) | lx) == 0)) { return -1.80143985094819840000E+16 / (x - x); }
		else if (PREDICT_UNLIKELY(hx < 0)) { return (x - x) / (x - x); }
		k -= 54;
		x *= 1.80143985094819840000E+16;
		GET_HIGH_SWORD(hx, x);
	}
	if (PREDICT_UNLIKELY(hx >= 0x7ff00000)) { return x + x; }
	k += (hx >> 20) - 1023;
	i = (int32_t)(((uint32_t) k & 0x80000000) >> 31);
	hx = (hx & 0x000fffff) | ((0x3ff - i) << 20);
	y = (double)(k + i);
	if (FIX_INT_FP_CONVERT_ZERO && y == 0.0) { y = 0.0; }
	SET_HIGH_WORD(x, hx);
	z = y * 3.69423907715893078616E-13 + 4.34294481903251816668E-1 * __ieee754_log(x);
	return z + y * 3.01029995663611771306E-1;
}
#define __log10_finite(x)   __ieee754_log10((x))


#if LDBL_EQ_FLOAT128
LIB_FUNC long double __ieee754_log10l(const long double num) {
	long double x = num;
	int64_t hx = 0, lx = 0;
	GET_LDOUBLE_SWORDS64(hx, lx, x);
	if (((hx & 0x7fffffffffffffffLL) | lx) == 0) { return (-1.0L / (x - x)); }
	else if (hx < 0) { return (x - x) / (x - x); }
	else if (hx >= 0x7fff000000000000LL) { return (x + x); }
	else if (x == 1.0L) { return 0.0L; }
	int e = 0;
	x = frexpl(x, &e);
	long double z = 0.0L, y = 0.0L;
	if ((e > 2) || (e < -2)) {
		if (x < 7.071067811865475244008443621048490392848359E-1L) {
			e -= 1;
			z = x - 0.5L;
			y = 0.5L * z + 0.5L;
		} else {
			z = x - 0.5L;
			z -= 0.5L;
			y = 0.5L * x + 0.5L;
		}
		x = z / y;
		z = x * x;
		y = x * (z * neval(z, log10l_R, 5) / deval(z, log10l_S, 5));
		goto goto_ieee754_log10l_done;
	}
	if (x < 7.071067811865475244008443621048490392848359E-1L) {
		e -= 1;
		x = 2.0 * x - 1.0L;
	} else { x = x - 1.0L; }
	z = x * x;
	y = x * (z * neval(x, log10l_P, 12) / deval(x, log10l_Q, 11));
	y = y - 0.5 * z;
goto_ieee754_log10l_done:
	z = y * -6.570551809674817234887108108339491770560299E-2L;
	z += x * -6.570551809674817234887108108339491770560299E-2L;
	z += e * -1.14700043360188047862611052755069732318101185E-2L;
	z += y * 0.5L;
	z += x * 0.5L;
	z += e * 0.3125L;
	return z;
}
#   define __log10l_finite(x)   __ieee754_log10l((x))
#else
LIB_FUNC long double __ieee754_log10l(const long double num) {
	return (long double)__ieee754_log10((double)num);
}
#   define __log10l_finite(x)   __ieee754_log10l((x))
#endif


LIB_FUNC MATH_FUNC float __log10f(const float x) {
	if (PREDICT_UNLIKELY(__islessequalf(x, 0.0F))) {
		if (x == 0.0F) {
			feraiseexcept(FE_DIVBYZERO);
			return __kernel_standard_f(x, x, 118);
		} else {
			feraiseexcept(FE_INVALID);
			return __kernel_standard_f(x, x, 119);
		}
	}
	return __ieee754_log10f(x);
}
#define log10f(x)   __log10f((x))


LIB_FUNC MATH_FUNC double __log10(const double x) {
	if (PREDICT_UNLIKELY(__islessequal(x, 0.0))) {
		if (x == 0.0) {
			__feraiseexcept(FE_DIVBYZERO);
			return __kernel_standard(x, x, 18);
		} else {
			__feraiseexcept(FE_INVALID);
			return __kernel_standard(x, x, 19);
		}
	}
	return __ieee754_log10(x);
}
#define log10(x)   __log10((x))


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double __log10l(const long double x) {
	if (PREDICT_UNLIKELY(__islessequall(x, 0.0L))) {
		if (x == 0.0L) {
			feraiseexcept(FE_DIVBYZERO);
			return __kernel_standard_l(x, x, 218);
		} else {
			feraiseexcept(FE_INVALID);
			return __kernel_standard_l(x, x, 219);
		}
	}
	return __ieee754_log10l(x);
}
#   define log10l(x)   __log10l((x))
#endif


/** Return the binary exponent of non-zero x */
LIB_FUNC MATH_FUNC int __ieee754_ilogbf(const float x) {
	int32_t hx, ix;
	GET_FLOAT_WORD(hx, x);
	hx &= 0x7fffffff;
	if (hx < 0x800000) {
		if (hx == 0) { return FP_ILOGB0; }
		else { for (ix = -126, hx <<= 8; hx > 0; hx <<= 1) { ix -= 1; } }
		return ix;
	} else if (hx < 0x7f800000) { return (hx >> 23) - 127; }
	else if ((FP_ILOGBNAN != INT_MAX) && (hx == 0x7f800000)) { return INT_MAX; }
	return FP_ILOGBNAN;
}


/** Return the binary exponent of non-zero x */
LIB_FUNC MATH_FUNC int __ieee754_ilogb(const double x) {
	int32_t hx = 0, lx = 0;
	GET_HIGH_SWORD(hx, x);
	hx &= 0x7fffffff;
	int32_t ix = 0;
	if (hx < 0x100000) {
		GET_LOW_SWORD(lx, x);
		if ((hx | lx) == 0) { return FP_ILOGB0; }
		else if (hx == 0) { for (ix = -1043; lx > 0; lx <<= 1) { ix -= 1; } }
		else { for (ix = -1022, hx <<= 11; hx > 0; hx <<= 1) { ix -= 1; } }
		return ix;
	} else if (hx < 0x7ff00000) { return (hx >> 20) - 1023; }
	else if (FP_ILOGBNAN != INT_MAX) {
		GET_LOW_SWORD(lx, x);
		if (((hx ^ 0x7ff00000) | lx) == 0) { return INT_MAX; }
	}
	return FP_ILOGBNAN;
}


#if LDBL_EQ_FLOAT128
/** Return the binary exponent of non-zero x */
LIB_FUNC MATH_FUNC int __ieee754_ilogbl(const long double x) {
	int64_t hx = 0, lx = 0;
	GET_LDOUBLE_SWORDS64(hx, lx, x);
	hx &= 0x7fffffffffffffffLL;
	int ix = 0;
	if (hx <= 0x1000000000000LL) {
		if ((hx | lx) == 0) { return FP_ILOGB0; }
		else if (hx == 0) { for (ix = -16431; lx > 0; lx <<= 1) { ix -=1; } }
		else { for (ix = -16382, hx <<= 15; hx > 0; hx <<= 1) { ix -=1; } }
		return ix;
	} else if (hx < 0x7fff000000000000LL) { return (int)((hx >> 48) - 0x3fff); }
	else if ((FP_ILOGBNAN != INT_MAX) && (((hx ^ 0x7fff000000000000LL) | lx) == 0)) { return INT_MAX; }
	return FP_ILOGBNAN;
}
#else
/** Return the binary exponent of non-zero x */
LIB_FUNC MATH_FUNC int __ieee754_ilogbl(const long double x) {
	return (int)__ieee754_ilogb((double)x);
}
#endif


LIB_FUNC MATH_FUNC int __ilogbf(const float x) {
	const int r = __ieee754_ilogbf(x);
	if (PREDICT_UNLIKELY(r == FP_ILOGB0) || PREDICT_UNLIKELY(r == FP_ILOGBNAN) || PREDICT_UNLIKELY(r == INT_MAX)) {
		set_errno(EDOM);
		feraiseexcept(FE_INVALID);
	}
	return r;
}
#define ilogbf(x)   __ilogbf((x))


LIB_FUNC MATH_FUNC int __ilogb(const double x) {
	const int r = __ieee754_ilogb(x);
	if (PREDICT_UNLIKELY(r == FP_ILOGB0) || PREDICT_UNLIKELY(r == FP_ILOGBNAN) || PREDICT_UNLIKELY(r == INT_MAX)) {
		set_errno(EDOM);
		__feraiseexcept(FE_INVALID);
	}
	return r;
}
#define ilogb(x)   __ilogb((x))


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC int __ilogbl(const long double x) {
	const int r = __ieee754_ilogbl(x);
	if (PREDICT_UNLIKELY(r == FP_ILOGB0) || PREDICT_UNLIKELY(r == FP_ILOGBNAN) || PREDICT_UNLIKELY(r == INT_MAX)) {
		set_errno(EDOM);
		feraiseexcept(FE_INVALID);
	}
	return r;
}
#   define ilogbl(x)   __ilogbl((x))
#endif


/** Integer log2 of a float */
LIB_FUNC MATH_FUNC int ilog2f(const float x) {
#   ifdef ARCHX86
	register int32_t retval;
	vasm("bsr %0, %1;" : "+r"(retval) : "r"(x));
	return retval;
#   else
	const uint32_t exp = (((uint32_t)x) >> 23) & 0xff;
	return ((int32_t)exp) - 127;
#   endif
}


LIB_FUNC MATH_FUNC float __w_log1pf(const float num) {
#   ifdef ARCHX86
	float ret;
	asm ("fyl2xp1;" : "=t"(ret) : "0"(num), "u"(1.0F) : "st(1)");
	return ret;
#   else
	float x = num;
	int32_t hx = 0, hu = 0, k = 1;
	GET_FLOAT_WORD(hx, x);
	const int32_t ax = (hx & 0x7fffffff);
	if (hx < 0x3ed413d7) {
		if (ax >= 0x3f800000) {
			if (x == -1.0F) { return (-3.355443200E+7F / 0.0F); }
			else { return (x - x) / (x - x); }
		} else if (ax < 0x31000000) {
			math_force_eval((3.355443200E+7F + x));
			if (ax < 0x24800000) { return x; }
			else { return x - (x * x * 0.5F); }
		}
		if (hx > 0 || hx <= ((int32_t)0xbe95f61f)) {
			k = 0;
			f = x;
			hu = 1;
		}
	}
	float c = 0.0F, f = 0.0F;
	if (hx >= 0x7f800000) { return x + x; }
	else if (k != 0) {
		float u = x;
		if (hx < 0x5a000000) {
			u += 1.0F;
			GET_FLOAT_WORD(hu, u);
			k = (hu >> 23) - 127;
			c = ((k > 0) ? (1.0F - (u - x)) : (x - (u - 1.0F))) / u;
		} else {
			GET_FLOAT_WORD(hu, u);
			k = (hu >> 23) - 127;
			c = 0;
		}
		hu &= 0x7fffff;
		if (hu < 0x3504f7) { SET_FLOAT_SWORD(u, (hu | 0x3f800000)); }
		else {
			k += 1;
			SET_FLOAT_SWORD(u, (hu | 0x3f000000));
			hu = (0x800000 - hu) >> 2;
		}
		f = u - 1.0F;
	}
	const float hfsq = 0.5F * f * f;
	if (hu == 0) {
		if (f == 0.0F) {
			if (k == 0) { return 0.0F; }
			c += ((float)k) * 9.0580006145E-6F;
			return ((float)k) * 6.9313812256E-1F + c;
		}
		const float R = hfsq * (1.0F - 0.66666666666666666F * f);
		if (k == 0) { return f - R; }
		return ((float)k) * 6.9313812256E-1F - ((R - (((float)k) * 9.0580006145E-6F + c)) - f);
	}
	const float s = f / (2.0F + f);
	const float z = s * s;
	const float R = z * (6.6666668653E-1F + z * (4.0000000596E-1F + z * (2.8571429849E-1F + z * (2.2222198546E-1F + z * (1.8183572590E-1F + z * (1.5313838422E-1F + z * 1.4798198640E-1F))))));
	if (k == 0) { return f - (hfsq - s * (hfsq + R)); }
	else { return ((float)k) * 6.9313812256E-1F - ((hfsq - (s * (hfsq + R) + (((float)k) * 9.0580006145E-6F + c))) - f); }
#   endif
}


LIB_FUNC MATH_FUNC double __w_log1p(const double num) {
#   ifdef ARCHX86
	double ret;
	asm ("fyl2xp1;" : "=t"(ret) : "0"(num), "u"(1.0) : "st(1)");
	return ret;
#   else
	double x = num;
	int32_t hx, hu = 0, k = 1;
	GET_HIGH_SWORD(hx, x);
	int32_t ax = (hx & 0x7fffffff);
	if (hx < 0x3fda827a) {
		if (ax >= 0x3ff00000) {
			if (x == -1.0) { return -1.80143985094819840000E+16 / 0.0; }
			else { return (x - x) / (x - x); }
		} else if (ax < 0x3e200000) {
			if ((1.80143985094819840000E+16 + x) > 0.0 && ax < 0x3c900000) { return x; }
			else { return x - x * x * 0.5; }
		} else if (hx > 0 || hx <= ((int32_t)0xbfd2bec3)) {
			k = 0;
			f = x;
			hu = 1;
		}
	}
	double c = 0.0, f = 0.0;
	if (hx >= 0x7ff00000) { return x + x; }
	else if (k != 0) {
		double u;
		if (hx < 0x43400000) {
			u = 1.0 + x;
			GET_HIGH_SWORD(hu, u);
			k = (hu >> 20) - 1023;
			c = ((k > 0) ? (1.0 - (u - x)) : (x - (u - 1.0))) / u;
		} else {
			u = x;
			GET_HIGH_SWORD(hu, u);
			k = (hu >> 20) - 1023;
			c = 0;
		}
		hu &= 0xfffff;
		if (hu < 0x6a09e) {
			SET_HIGH_WORD(u, (hu | 0x3ff00000));
		} else {
			k += 1;
			SET_HIGH_WORD(u, (hu | 0x3fe00000));
			hu = (0x100000 - hu) >> 2;
		}
		f = u - 1.0;
	}
	const double hfsq = 0.5 * f * f;
	if (hu == 0) {
		if (f == 0.0) {
			if (k == 0) { return 0.0; }
			else {
				c += ((double)k) * 1.90821492927058770002E-10;
				return ((double)k) * 6.93147180369123816490E-1 + c;
			}
		}
		const double R = hfsq * (1.0 - 0.66666666666666666 * f);
		if (k == 0) { return f - R; }
		else { return ((double)k) * 6.93147180369123816490E-1 - ((R - (((double)k) * 1.90821492927058770002E-10 + c)) - f); }
	}
	const double s = f / (2.0 + f);
	const double z = s * s;
	const double R = z * (6.666666666666735130E-1 + z * (3.999999999940941908E-1 + z * (2.857142874366239149E-1 + z * (2.222219843214978396E-1 + z * (1.818357216161805012E-1 + z * (1.531383769920937332E-1 + z * 1.479819860511658591E-1))))));
	if (k == 0) { return f - (hfsq - s * (hfsq + R)); }
	return ((double)k) * 6.93147180369123816490E-1 - ((hfsq - (s * (hfsq + R) + (((double)k) * 1.90821492927058770002E-10 + c))) - f);
#   endif
}


#if LDBL_EQ_FLOAT128
LIB_FUNC MATH_FUNC long double __w_log1pl(const long double num) {
	long_double_shape_t u = { .value = num };
	int32_t hx = (int32_t)u.uparts32.w0;
	if ((hx & 0x7fffffff) >= 0x7fff0000) { return num + fabsl(num); }
	else if (((hx & 0x7fffffff) == 0) && (u.uparts32.w1 | u.uparts32.w2 | u.uparts32.w3) == 0) { return num; }
	else if (((hx & 0x7fffffff) < 0x3f8e0000) && ((int)num == 0)) { return num; }
	long double x;
	if (num >= 0x1.0P+113L) { x = num; }
	else { x = num + 1.0L; }
	if (x <= 0.0L) {
		if (x == 0.0L) { return (-1.0L / 0.0L); }
		else { return (0.0L / (x - x)); }
	}
	int e;
	long double y, z;
	x = frexpl(x, &e);
	if ((e > 2) || (e < -2)) {
		if (x < SQRT_HALFL) {
			e -= 1;
			z = x - 0.5L;
			y = 0.5L * z + 0.5L;
		} else {
			z = x - 0.5L;
			z -= 0.5L;
			y = 0.5L * x + 0.5L;
		}
		x = z / y;
		z = x * x;
		const long double r = ((((-8.828896441624934385266096344596648080902E-1L * z + 8.057002716646055371965756206836056074715E+1L) * z + -2.024301798136027039250415126250455056397E+3L) * z + 2.048819892795278657810231591630928516206E+4L) * z + -8.977257995689735303686582344659576526998E+4L) * z + 1.418134209872192732479751274970992665513E+5L;
		const long double s = (((((z + -1.186359407982897997337150403816839480438E+2L) * z + 3.998526750980007367835804959888064681098E+3L) * z + -5.748542087379434595104154610899551484314E+4L) * z + 4.001557694070773974936904547424676279307E+5L) * z + -1.332535117259762928288745111081235577029E+6L) * z + 1.701761051846631278975701529965589676574E+6L;
		z = x * (z * r / s);
		z = (z + e * 1.428606820309417232121458176568075500134E-6L) + x;
		return z + e * 6.93145751953125E-1L;
	}
	if (x < SQRT_HALFL) {
		e -= 1;
		if (e != 0) { x = 2.0L * x - 1.0L; }
		else { x = num; }
	} else {
		if (e != 0) { x = x - 1.0L; }
		else { x = num; }
	}
	z = x * x;
	const long double r = (((((((((((1.538612243596254322971797716843006400388E-6L * x + 4.998469661968096229986658302195402690910E-1L) * x + 2.321125933898420063925789532045674660756E+1L) * x + 4.114517881637811823002128927449878962058E+2L) * x + 3.824952356185897735160588078446136783779E+3L) * x + 2.128857716871515081352991964243375186031E+4L) * x + 7.594356839258970405033155585486712125861E+4L) * x + 1.797628303815655343403735250238293741397E+5L) * x + 2.854829159639697837788887080758954924001E+5L) * x + 3.007007295140399532324943111654767187848E+5L) * x + 2.014652742082537582487669938141683759923E+5L) * x + 7.771154681358524243729929227226708890930E+4L) * x + 1.313572404063446165910279910527789794488E+4L;
	const long double s = (((((((((((x + 4.839208193348159620282142911143429644326e+1L) * x + 9.104928120962988414618126155557301584078E+2L) * x + 9.147150349299596453976674231612674085381E+3L) * x + 5.605842085972455027590989944010492125825E+4L) * x + 2.248234257620569139969141618556349415120E+5L) * x + 6.132189329546557743179177159925690841200E+5L) * x + 1.158019977462989115839826904108208787040E+6L) * x + 1.514882452993549494932585972882995548426E+6L) * x + 1.347518538384329112529391120390701166528E+6L) * x + 7.777690340007566932935753241556479363645E+5L) * x + 2.626900195321832660448791748036714883242E+5L) * x + 3.940717212190338497730839731583397586124E+4L;
	y = x * (z * r / s);
	y = y + e * 1.428606820309417232121458176568075500134E-6L;
	z = (y - 0.5L * z) + x;
	return z + e * 6.93145751953125E-1L;
}
#elif defined(ARCHX86)
LIB_FUNC MATH_FUNC long double __w_log1pl(const long double num) {
	long double ret;
	asm ("fyl2xp1;" : "=t"(ret) : "0"(num), "u"(1.0L) : "st(1)");
	return ret;
}
#endif


LIB_FUNC MATH_FUNC float log1pf(const float x) {
	if (PREDICT_UNLIKELY(__islessequalf(x, -1.0F))) {
		if (x == -1.0F) { set_errno(ERANGE); }
		set_errno(EDOM);
	}
	return __w_log1pf(x);
}
#define __log1pf(x)   log1pf((x))


LIB_FUNC MATH_FUNC double log1p(const double x) {
	if (PREDICT_UNLIKELY(__islessequal(x, -1.0))) {
		if (x == -1.0) { set_errno(ERANGE); }
		set_errno(EDOM);
	}
	return __w_log1p(x);
}
#define __log1p(x)   log1p((x))


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double log1pl(const long double x) {
	if (PREDICT_UNLIKELY(__islessequall(x, -1.0L))) {
		if (x == -1.0L) { set_errno(ERANGE); }
		else { set_errno(EDOM); }
	}
	return __w_log1pl(x);
}
#   define __log1pl(x)   log1pl((x))
#endif


LIB_FUNC MATH_FUNC float logbf(const float x) {
	if (!isfinitef(x)) { return x * x; }
	else if (x == 0) { return -1.0F / (x * x); }
	return (float)((uint32_t)ilogbf(x));
}


LIB_FUNC MATH_FUNC double logb(const double x) {
	if (!isfinite(x)) { return x * x; }
	else if (x == 0) { return -1.0 / (x * x); }
	return ilogb(x);
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double logbl(const long double x) {
	return (long double)logb((double)x);
}
#endif


// TRIGONOMETRY FUNCTIONS

#if LDBL_EQ_FLOAT128
/** R(x^2) is a rational approximation of (asin(x)-x)/x^3 with Remez algorithm */
LIB_FUNC MATH_FUNC long double __invtrigl_R(const long double z) {
	const long double p = z * (1.66666666666666666631E-1L + z * (-4.16313987993683104320E-1L + z * (3.69068046323246813704E-1L + z * (-1.36213932016738603108E-1L + z * (1.78324189708471965733E-2L + z * (-2.19216428382605211588E-4L + z * -7.10526623669075243183E-6L))))));
	const long double q = 1.0L + z * (-2.94788392796209867269L + z * (3.27309890266528636716L + z * (-1.68285799854822427013L + z * (3.90699412641738801874E-1L + z * -3.14365703596053263322E-2L))));
	return p / q;
}
#endif


LIB_FUNC int __rem_pio2_large(double* restrict x, double* restrict y, const int e0, const int nx, const int prec, const int32_t xitems) {
	const int align64 init_jk[4] = { 3, 4, 4, 6 };
	double align64 f[20] = { 0 }, q[20] = { 0 };
	const int32_t align64 jk = init_jk[((prec < 0 || prec > 3) ? 3 : prec)];
	const int32_t jx = (nx - 1);
	register int32_t i, jv = (int32_t)((e0 - 3) / 24);
	if (jv < 0) { jv = 0; }
	int32_t j = jv - jx;
	const int32_t m = jx + jk;
	register double fw = 0.0;
	if (j < 0) { for (i = 0; (i <= m) && (i < 20); i++) { f[i] = 0.0; } }
	else { for (i = 0; (i <= m) && (i < 20) && (j < ipio2_items); i++) { f[i] = (double)ipio2[j]; } }
	for (i = 0; (i <= jk) && (i < 20); i++) {
		if (i >= 20) { break; }
		for (j = xitems, fw = 0.0; (j <= jx) && (j < 5) && ((jx + i - j) < 20); j++) {
			if (j >= xitems) { break; }
			fw += (x[j] * f[jx + i - j]);
		}
		q[i] = fw;
	}
	const int32_t jp = jk;
	register int32_t n = 0, k = 0, ih = 0, jz = jk, q0 = (e0 - 24 * (jv + 1));
	int32_t align64 iq[20] = { 0 };
	double z;
	aln_double_t fq[20] = { 0 };
goto___rem_pio2_large_recompute:
	for (i = 0, j = jz, z = q[jz]; (j > 0) && (i < 20) && ((j - 1) < 20); i++, j--) {
		fw = (double)(int32_t)(0x1.0P-24 * z);
		iq[i] = (int32_t)(z - 0x1.0P+24 * fw);
		z = q[j - 1] + fw;
	}
	z = scalbn(z, q0);
	z -= 8.0 * floor(z * 0.125);
	n = (int32_t)z;
	z -= (double)n;
	ih = 0;
	if (q0 > 0) {
		i = (iq[jz - 1] >> (24 - q0));
		n += i;
		iq[jz - 1] -= (i << (24 - q0));
		ih = (iq[jz - 1] >> (23 - q0));
	}
	else if (q0 == 0) { ih = (iq[jz - 1] >> 23); }
	else if (z >= 0.5) { ih = 2; }
	if (ih > 0) {
		n += 1;
		register int32_t carry = 0;
		for (i = 0; (i < jz) && (i < 20); i++) {
			j = iq[i];
			if (carry == 0) {
				if (j != 0) {
					carry = 1;
					iq[i] = 0x1000000 - j;
				}
			} else { iq[i] = 0xffffff - j; }
		}
		if (q0 > 0) {
			switch (q0) {
				case 1:
					iq[jz - 1] &= 0x7fffff;
					break;
				default:  // case 2
					iq[jz - 1] &= 0x3fffff;
					break;
			}
		}
		if (ih == 2) {
			z = 1.0 - z;
			if (carry != 0) { z -= scalbn(1.0, q0); }
		}
	}
	if (z == 0.0) {
		j = 0;
		for (i = (jz - 1); (i >= jk) && (i < 20) && (i >= 0); i--) { j |= iq[i]; }
		if (PREDICT_UNLIKELY(j == 0)) {
			for (k = 1; ((jk - k) < 20) && ((jk - k) >= 0) && (iq[jk - k] == 0); k++);
			for (i = (jz + 1); (i <= (jz + k)) && (i < 20) && ((jx + i) < 20) && (j <= jx) && ((jv + i) < ipio2_items); i++) {
				if ((i >= 20) || ((jx + i) >= 20)) { jz += k; goto goto___rem_pio2_large_recompute; }
				f[jx + i] = (double)ipio2[jv + i];
				for (j = xitems, fw = 0.0; (j < 5) && (j <= jx) && ((jx + i - j) >= 0) && ((jx + i - j) < 20); j++) {
					if (j >= xitems) { jz += k; break; }
					fw += (x[j] * f[jx + i - j]);
				}
				q[i] = fw;
			}
			jz += k;
			goto goto___rem_pio2_large_recompute;
		}
	}
	if (z == 0.0) {
		jz -= 1;
		q0 -= 24;
		while ((jz >= 0) && (iq[jz] == 0)) { jz--; q0 -= 24; }
	} else {
		z = scalbn(z, -q0);
		if (z >= 0x1.0P+24) {
			fw = (double)(int32_t)(0x1.0P-24 * z);
			iq[jz] = (int32_t)(z - 0x1.0P+24 * fw);
			jz += 1;
			q0 += 24;
			iq[jz] = (int32_t)fw;
		} else { iq[jz] = (int32_t)z; }
	}
	fw = scalbn(1.0, q0);
	for (i = jz; (i >= 0) && (i < 20); i--) {
		q[i] = fw * (double)iq[i];
		fw *= 0x1.0P-24;
	}
	for (i = jz; (i >= 0) && (i < 20); i--) {
		for (fw = 0.0, k = 0; (k <= jp) && (k <= (jz - i)) && (k < 8); k++) { fw += (PIo2[k] * q[i + k]); }
		fq[jz - i] = fw;
	}
	switch (prec) {
		case 0:
			fw = 0.0;
			for (i = jz; (i >= 0) && (i < 20); i--) { fw += fq[i]; }
			y[0] = ih == 0 ? fw : -fw;
			break;
		case 1:
		case 2:
			fw = 0.0;
			for (i = jz; (i >= 0) && (i < 20); i--) { fw += fq[i]; }
			fw = (double)fw;
			y[0] = ih == 0 ? fw : -fw;
			fw = fq[0] - fw;
			for (i = 1; (i <= jz) && (i < 20); i++) { fw += fq[i]; }
			y[1] = ih == 0 ? fw : -fw;
			break;
		default:  // case 3
			for (i = jz; (i > 0) && (i < 20); i--) {
				fw = fq[i - 1] + fq[i];
				fq[i] += fq[i - 1] - fw;
				fq[i - 1] = fw;
			}
			for (i = jz; (i > 1) && (i < 20); i--) {
				fw = fq[i - 1] + fq[i];
				fq[i] += fq[i - 1] - fw;
				fq[i - 1] = fw;
			}
			for (fw = 0.0, i = jz; (i >= 2) && (i < 20); i--) { fw += fq[i]; }
			if (ih == 0) {
				y[0] = fq[0];
				y[1] = fq[1];
				y[2] = fw;
			} else {
				y[0] = -fq[0];
				y[1] = -fq[1];
				y[2] = -fw;
			}
	}
	return (int)(n & 7);
}
#define __ieee754_rem_pio2_large(x, y, e0, nx, prec, xitems)   __rem_pio2_large((x), (y), (e0), (nx), (prec), (xitems))


/** Return the remainder of x rem pi/2 in `*y` */
LIB_FUNC int __rem_pio2(const double x, double* restrict y) {
	union __union_rem_pio2 { double f; uint64_t i; } u = { x };
	double z, tx[3], ty[2];
	const int sign = (int)(u.i >> 63);
	const uint32_t ix = (uint32_t)(u.i >> 32 & 0x7fffffff);
	if (ix <= 0x400f6a7a) {
		if ((ix & 0xfffff) == 0x921fb) { goto goto___rem_pio2_medium; }
		else if (ix <= 0x4002d97c) {
			if (!sign) {
				z = x - pio2_1;
				y[0] = z - pio2_1t;
				y[1] = (z - y[0]) - pio2_1t;
				return 1;
			} else {
				z = x + pio2_1;
				y[0] = z + pio2_1t;
				y[1] = (z - y[0]) + pio2_1t;
				return -1;
			}
		} else {
			if (!sign) {
				z = x - 2 * pio2_1;
				y[0] = z - 2 * pio2_1t;
				y[1] = (z - y[0]) - 2 * pio2_1t;
				return 2;
			} else {
				z = x + 2 * pio2_1;
				y[0] = z + 2 * pio2_1t;
				y[1] = (z - y[0]) + 2 * pio2_1t;
				return -2;
			}
		}
	} else if (ix <= 0x401c463b) {
		if (ix <= 0x4015fdbc) {
			if (ix == 0x4012d97c) { goto goto___rem_pio2_medium; }
			else if (!sign) {
				z = x - 3 * pio2_1;
				y[0] = z - 3 * pio2_1t;
				y[1] = (z - y[0]) - 3 * pio2_1t;
				return 3;
			} else {
				z = x + 3 * pio2_1;
				y[0] = z + 3 * pio2_1t;
				y[1] = (z - y[0]) + 3 * pio2_1t;
				return -3;
			}
		} else {
			if (ix == 0x401921fb) { goto goto___rem_pio2_medium; }
			else if (!sign) {
				z = x - 4 * pio2_1;
				y[0] = z - 4 * pio2_1t;
				y[1] = (z - y[0]) - 4 * pio2_1t;
				return 4;
			} else {
				z = x + 4 * pio2_1;
				y[0] = z + 4 * pio2_1t;
				y[1] = (z - y[0]) + 4 * pio2_1t;
				return -4;
			}
		}
	} else if (ix < 0x413921fb) {
goto___rem_pio2_medium:
		do_sync();
		const double fn = ((double)x * invpio2 + (double)(1.5 / EPS)) - (double)(1.5 / EPS);
		int n = (int32_t)fn;
		double r = x - fn * pio2_1;
		double w = fn * pio2_1t;
		y[0] = r - w;
		u.f = y[0];
		int ey = u.i >> 52 & 0x7ff;
		const int ex = (int)(ix >> 20);
		if (ex - ey > 16) {
			double t = r;
			w = fn * pio2_2;
			r = t - w;
			w = fn * pio2_2t - ((t - r) - w);
			y[0] = r - w;
			u.f = y[0];
			ey = u.i >> 52 & 0x7ff;
			if ((ex - ey) > 49) {
				t = r;
				w = fn * pio2_3;
				r = t - w;
				w = fn * pio2_3t - ((t - r) - w);
				y[0] = r - w;
			}
		}
		y[1] = (r - y[0]) - w;
		return n;
	} else if (ix >= 0x7ff00000) {  // x is inf or NaN
		y[0] = y[1] = x - x;
		return 0;
	}
	u.f = x;
	u.i &= ((uint64_t)-1 >> 12);
	u.i |= ((uint64_t)1046 << 52);
	z = u.f;
	register int i;
	for (i = 0; i < 2; i++) {
		tx[i] = (double)((int32_t)z);
		z = (z - tx[i]) * 0x1.0P+24;
	}
	tx[i] = (double)z;
	while (tx[i] == 0.0) { i--; }
	const int n = __rem_pio2_large(tx, ty, ((int)(ix >> 20) - (0x3ff + 23)), (i + 1), 1, 3);
	if (sign) {
		y[0] = -ty[0];
		y[1] = -ty[1];
		return -n;
	}
	y[0] = ty[0];
	y[1] = ty[1];
	return n;
}
#define __ieee754_rem_pio2(x, y)   __rem_pio2((x), (y))


#if IS_LDBL_X87
LIB_FUNC int __rem_pio2l(const long double x, long double* restrict y) {
	union ldshape u = { .f = x };
	double tx[3] = { 0.0 }, ty[2] = { 0.0 };
	const int ex = u.i.se & 0x7fff;
	if (((((u.i.se & 0x7fffU) << 16) | (u.i.m >> 48)) < (((0x3fff + 25) << 16) | (0x921f >> 1) | 0x8000))) {
		const long double fn = x * 6.36619772367581343076E-1L + (1.5 / LDBL_EPSILON) - (1.5L / LDBL_EPSILON);
		const int n = (int)((int32_t)fn & 0x7fffffff);
		long double r = x - fn * M_PI_2L;
		long double w = fn * -1.07463465549719416346E-12L;
		y[0] = r - w;
		u.f = y[0];
		int ey = u.i.se & 0x7fff;
		if ((ex - ey) > 22) {
			long double t = r;
			w = fn * (long double)2.0222662487959507323994779168837751E-21L;
			r = t - w;
			w = fn * 6.36831716351095013979E-25L - ((t - r) - w);
			y[0] = r - w;
			u.f = y[0];
			ey = u.i.se & 0x7fff;
			if ((ex - ey) > 61) {
				t = r;
				w = fn * 2.0670321098263988236499468110329591E-43L;
				r = t - w;
				w = fn * -2.75299651904407171810E-37L - ((t - r) - w);
				y[0] = r - w;
			}
		}
		y[1] = (r - y[0]) - w;
		return n;
	} else if (ex == 0x7fff) {  // x is inf or NaN
		y[0] = y[1] = x - x;
		return 0;
	}
	union ldshape uz = { .f = x };
	uz.i.se = 0x3fff + 23;
	long double z = uz.f;
	register int i;
	for (i = 0; i < 3 - 1; i++) {
		tx[i] = (double)((int32_t)z);
		z = (z - tx[i]) * 0x1.0P+24;
	}
	tx[i] = (double)z;
	while (tx[i] == 0) { --i; }
	const int n = __rem_pio2_large(tx, ty, (ex - 0x3fff - 23), (i + 1), 2, 3);
	long double w = ty[1];
	const long double r = ty[0] + w;
	w -= r - ty[0];
	if (u.i.se >> 15) {
		y[0] = -r;
		y[1] = -w;
		return -n;
	}
	y[0] = r;
	y[1] = w;
	return n;
}
#   define __ieee754_rem_pio2l(x, y)   __rem_pio2l((x), (y))
#elif LDBL_EQ_FLOAT128
LIB_FUNC int __rem_pio2l(const long double x, long double* restrict y) {
	union ldshape u = { .f = x };
	double tx[5] = { 0.0 }, ty[3] = { 0.0 };
	const int ex = u.i.se & 0x7fff;
	if ((((u.i.se & 0x7fffU) << 16 | u.i.top) < ((0x3fff + 45) << 16 | 0x921f))) {
		const long double fn = x * 6.3661977236758134307553505349005747E-1L + (1.5L / LDBL_EPSILON) - (1.5L / LDBL_EPSILON);
		const int n = (int)((int64_t)fn & 0x7fffffff);
		long double r = x - fn * M_PI_2L;
		long double w = fn * 2.0222662487959507323996846200947577E-21L;
		y[0] = r - w;
		u.f = y[0];
		int ey = u.i.se & 0x7fff;
		if (ex - ey > 51) {
			long double t = r;
			w = fn * 2.0222662487959507323994779168837751E-21L;
			r = t - w;
			w = fn * 2.0670321098263988236496903051604844E-43L - ((t - r) - w);
			y[0] = r - w;
			u.f = y[0];
			ey = u.i.se & 0x7fff;
			if (ex - ey > 119) {
				t = r;
				w = fn * 2.0670321098263988236499468110329591E-43L;
				r = t - w;
				w = fn * -2.5650587247459238361625433492959285E-65L - ((t - r) - w);
				y[0] = r - w;
			}
		}
		y[1] = (r - y[0]) - w;
		return n;
	} else if (ex == 0x7fff) {  // x is inf or NaN
		y[0] = y[1] = x - x;
		return 0;
	}
	union ldshape uz = { .f = x };
	uz.i.se = 0x3fff + 23;
	register int i;
	for (i = 0; i < 5 - 1; i++) {
		tx[i] = (double)((int32_t)uz.f);
		uz.f = (uz.f - tx[i]) * 0x1.0P+24;
	}
	const long double z = uz.f;
	tx[i] = (double)z;
	while (tx[i] == 0) { --i; }
	const int n = __rem_pio2_large(tx, ty, (ex - 0x3fff - 23), (i + 1), 3, 5);
	long double w = ty[1] + ty[2];
	const long double r = ty[0] + w;
	w -= (r - ty[0]);
	if (u.i.se >> 15) {
		y[0] = -r;
		y[1] = -w;
		return -n;
	}
	y[0] = r;
	y[1] = w;
	return n;
}
#   define __ieee754_rem_pio2l(x, y)   __rem_pio2l((x), (y))
#endif


LIB_FUNC MATH_FUNC float __kernel_cosf(const float x, const float y) {
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix < 0x32000000 && (((int)x) == 0)) { return 1.0F; }
	const float z = x * x;
	const float r = z * (4.1666667908E-2F + z * (-1.3888889225E-3F + z * (2.4801587642E-5F + z * (-2.7557314297E-7F + z * (2.0875723372E-9F + z * -1.1359647598E-11F)))));
	if (ix < 0x3e99999a) { return 1.0F - (0.5F * z - (z * r - x * y)); }
	float qx;
	if (ix > 0x3f480000) { qx = 0.28125F; }
	else { SET_FLOAT_WORD(qx, ((uint32_t)ix - 0x01000000)); }
	return ((1.0F - qx) - ((0.5F * z - qx) - (z * r - x * y)));
}


LIB_FUNC MATH_FUNC double __kernel_cos(const double x, const double y) {
	int32_t ix;
	GET_HIGH_SWORD(ix, x);
	ix &= 0x7fffffff;
	if (ix < 0x3e400000 && (((int)x) == 0)) { return 1.0; }
	const double z = x * x;
	const double r = z * (4.16666666666666019037E-2 + z * (-1.38888888888741095749E-3 + z * (2.48015872894767294178E-5 + z * (-2.75573143513906633035E-7 + z * (2.08757232129817482790E-9 + z * -1.13596475577881948265E-11)))));
	double qx;
	if (ix < 0x3fd33333) { return 1.0 - (0.5 * z - (z * r - x * y)); }
	else if (ix > 0x3fe90000) { qx = 0.28125; }
	else { INSERT_WORDS(qx, (uint32_t)(ix - 0x200000), 0); }
	return ((1.0 - qx) - ((0.5 * z - qx) - (z * r - x * y)));
}


LIB_FUNC MATH_FUNC float __kernel_sinf(const float x, const float y, const int iy) {
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix < 0x32000000 && ((int)x == 0)) { return x; }
	const float z = x * x;
	const float v = z * x;
	const float r = 8.3333337680E-3F + z * (-1.9841270114E-4F + z * (2.7557314297E-6F + z * (-2.5050759689E-8F + z * 1.5896910177E-10F)));
	if (iy == 0) { return x + v * (-1.6666667163E-1F + z * r); }
	return x - ((z * (0.5F * y - v * r) - y) - v * -1.6666667163E-1F);
}


LIB_FUNC MATH_FUNC double __kernel_sin(const double x, const double y, const int iy) {
	int32_t ix;
	GET_HIGH_SWORD(ix, x);
	ix &= 0x7fffffff;
	if (ix < 0x3e400000 && ((int)x == 0)) { return x; }
	const double z = x * x;
	const double v = z * x;
	const double r = 8.33333333332248946124E-3 + z * (-1.98412698298579493134E-4 + z * (2.75573137070700676789E-6 + z * (-2.50507602534068634195E-8 + z * 1.58969099521155010221E-10)));
	if (iy == 0) { return x + v * (-1.66666666666666324348E-1 + z * r); }
	return x - ((z * (0.5 * y - v * r) - y) - v * -1.66666666666666324348E-1);
}


LIB_FUNC MATH_FUNC float __kernel_tanf(const float numx, const float numy, const int iy) {
	float z, w, x = numx, y = numy;
	int32_t hx;
	GET_FLOAT_WORD(hx, x);
	const int32_t ix = hx & 0x7fffffff;
	if (ix < 0x31800000 && ((int)x == 0)) {
		if ((ix | (iy + 1)) == 0) { return 1.0F / fabsf(x); }
		return ((iy == 1) ? x : (-1.0F / x));
	} else if (ix >= 0x3f2ca140) {
		if (hx < 0) { x = -x; y = -y; }
		z = 7.8539812565E-1F - x;
		w = 3.7748947079E-8F - y;
		x = z + w;
		y = 0.0;
	}
	z = x * x;
	w = z * z;
	float r = 1.3333334029E-1F + w * (2.1869488060E-2F + w * (3.5920790397E-3F + w * (5.8804126456E-4F + w * (7.8179444245E-5F + w * -1.8558637748E-5F))));
	float v = z * (5.3968254477E-2F + w * (8.8632395491E-3F + w * (1.4562094584E-3F + w * (2.4646313977E-4F + w * (7.1407252108E-5F + w * 2.5907305826E-5F)))));
	const float s = z * x;
	r = y + z * (s * (r + v) + y);
	r += (3.3333334327E-1F * s);
	w = x + r;
	if (ix >= 0x3f2ca140) {
		v = (float)iy;
		return (float)(1 - ((hx >> 30) & 2)) * (v - 2.0F * (x - (w * w / (w + v) - r)));
	} else if (iy == 1) { return w; }
	uint32_t i;
	z = w;
	GET_FLOAT_UWORD(i, z);
	SET_FLOAT_WORD(z, (i & 0xfffff000));
	v = r - (z - x);
	float t = -1.0F / w;
	const float a = t;
	GET_FLOAT_UWORD(i, t);
	SET_FLOAT_UWORD(t, (i & 0xfffff000));
	return (t + a * ((1.0F + t * z) + t * v));
}


LIB_FUNC MATH_FUNC double __kernel_tan(const double numx, const double numy, const int iy) {
	double z, w, x = numx, y = numy;
	int32_t hx;
	GET_HIGH_SWORD(hx, x);
	const int32_t ix = hx & 0x7fffffff;
	if (ix < 0x3e300000 && ((int)x == 0)) {
		uint32_t low;
		GET_LOW_WORD(low, x);
		if (((ix | (int32_t)low) | (int32_t)(iy + 1)) == 0) { return 1.0 / fabs(x); }
		return ((iy == 1) ? x : (-1.0 / x));
	} else if (ix >= 0x3fe59428) {
		if (hx < 0) { x = -x; y = -y; }
		z = 7.85398163397448278999E-1 - x;
		w = 3.06161699786838301793E-17 - y;
		x = z + w;
		y = 0.0;
	}
	z = x * x;
	w = z * z;
	double r = 1.33333333333201242699E-1 + w * (2.18694882948595424599E-2 + w * (3.59207910759131235356E-3 + w * (5.88041240820264096874E-4 + w * (7.81794442939557092300E-5 + w * -1.85586374855275456654E-5))));
	double v = z * (5.39682539762260521377E-2 + w * (8.86323982359930005737E-3 + w * (1.45620945432529025516E-3 + w * (2.46463134818469906812E-4 + w * (7.14072491382608190305E-5 + w * 2.59073051863633712884E-5)))));
	const double s = z * x;
	r = y + z * (s * (r + v) + y);
	r += (3.33333333333334091986E-1 * s);
	w = x + r;
	if (ix >= 0x3fe59428) {
		v = (double)iy;
		return (double)(1 - ((hx >> 30) & 2)) * (v - 2.0 * (x - (w * w / (w + v) - r)));
	} else if (iy == 1) { return w; }
	double a, t;
	z = w;
	SET_LOW_WORD(z, 0);
	v = r - (z - x);
	t = a = -1.0 / w;
	SET_LOW_WORD(t, 0);
	return t + a * ((1.0 + t * z) + t * v);
}


#if IS_LDBL_X87


LIB_FUNC MATH_FUNC long double __kernel_cosl(const long double numx, const long double numy) {
	long double x = numx, y = numy;
	if (signbitl(x)) {
		x = -x;
		y = -y;
	}
	if (x < 0.1484375L) {
		if (x < 0x1.0P-33L && (!((int)x))) { return 1.00000000000000000000000000000000000L; }
		const long double z = x * x;
		return 1.00000000000000000000000000000000000L + (z * (-4.99999999999999999999999999999999759E-1L + z * (4.16666666666666666666666666651287795E-2L + z * (-1.38888888888888888888888742314300284E-3L + z * (2.48015873015873015867694002851118210E-5L + z * (-2.75573192239858811636614709689300351E-7L + z * (2.08767569877762248667431926878073669E-9L + z * (-1.14707451049343817400420280514614892E-11L + z * 4.77810092804389587579843296923533297E-14L))))))));
	}
	int index = (int)(128 * (x - (0.1484375L - 1.0L / 256.0L)));
	const long double h = 0.1484375L + index / 128.0;
	index *= 4;
	const long double l = y - (h - x);
	const long double z = l * l;
	const long double sin_l = l * (1.00000000000000000000000000000000000L + z * (-1.66666666666666666666666666666666659E-1L + z * (8.33333333333333333333333333146298442E-3L + z * (-1.98412698412698412697726277416810661E-4L + z * (2.75573192239848624174178393552189149E-6L + z * -2.50521016467996193495359189395805639E-8L)))));
	const long double cos_l_m1 = z * (-5.00000000000000000000000000000000000e-1L + z * (4.16666666666666666666666666556146073E-2L + z * (-1.38888888888888888888309442601939728E-3L + z * (2.48015873015862382987049502531095061E-5L + z * -2.75573112601362126593516899592158083E-7L))));
	return __sincosl_table[index + 0] + (__sincosl_table[index + 1] - (__sincosl_table[index + 2] * sin_l - __sincosl_table[index + 0] * cos_l_m1));
}


LIB_FUNC MATH_FUNC long double __kernel_sinl(const long double numx, const long double numy, const int iy) {
	long double x = numx, y = numy;
	const long double absx = fabsl(x);
	if (absx < 0.1484375L) {
		if (absx < 0x1.0P-33L) {
			// math_check_force_underflow(x);
			if (!((int)x)) { return x; }
		}
		const long double z = x * x;
		return x + (x * (z * (-1.66666666666666666666666666666666538E-1L + z * (8.33333333333333333333333333307532934E-3L + z * (-1.98412698412698412698412534478712057E-4L + z * (2.75573192239858906520896496653095890E-6L + z * (-2.50521083854417116999224301266655662E-8L + z * (1.60590438367608957516841576404938118E-10L + z * (-7.64716343504264506714019494041582610E-13L + z * 2.81068754939739570236322404393398135E-15L)))))))));
	}
	int index = (int)(128 * (absx - (0.1484375L - 1.0L / 256.0L)));
	const long double h = 0.1484375L + index / 128.0;
	index *= 4;
	long double l;
	if (iy) { l = (x < 0 ? -y : y) - (h - absx); }
	else { l = absx - h; }
	const long double z = l * l;
	const long double sin_l = l * (1.00000000000000000000000000000000000L + z * (-1.66666666666666666666666666666666659E-1L + z * (8.33333333333333333333333333146298442E-3L + z * (-1.98412698412698412697726277416810661E-4L + z * (2.75573192239848624174178393552189149E-6L + z * -2.50521016467996193495359189395805639E-8L)))));
	const long double cos_l_m1 = z * (-5.00000000000000000000000000000000000E-1L + z * (4.16666666666666666666666666556146073E-2L + z * (-1.38888888888888888888309442601939728E-3L + z * (2.48015873015862382987049502531095061E-5L + z * -2.75573112601362126593516899592158083E-7L))));
	register long double _z = __sincosl_table[index + 2] + (__sincosl_table[index + 3] + (__sincosl_table[index + 2] * cos_l_m1) + (__sincosl_table[index + 0] * sin_l));
	return (x < 0) ? -_z : _z;
}


LIB_FUNC MATH_FUNC long double cosl(const long double num) {
	long double y[2] = { 0.0L }, z = 0.0, x = num;
	int32_t se, i0, i1;
	GET_LDOUBLE_WORDS(se, i0, i1, x);
	se &= 0x7fff;
	if (se < 0x3ffe || (se == 0x3ffe && i0 <= 0xc90fdaa2)) { return __kernel_cosl(x, z); }
	else if (se == 0x7fff) {
		if (i1 == 0 && i0 == 0x80000000) { set_errno(EDOM); }
		return x - x;
	}
	register const int32_t n = __ieee754_rem_pio2l(x, y);
	switch (n & 3) {
		case 0:
			return __kernel_cosl(y[0], y[1]);
		case 1:
			return -__kernel_sinl(y[0], y[1], 1);
		case 2:
			return -__kernel_cosl(y[0], y[1]);
		default:
			return __kernel_sinl(y[0], y[1], 1);
	}
}
#define __cosl(x)   cosl((x))


LIB_FUNC MATH_FUNC long double sinl(const long double numx) {
	long double y[2] = { 0.0L }, z = 0.0, x = numx;
	int32_t se, i0, i1;
	GET_LDOUBLE_WORDS(se, i0, i1, x);
	se &= 0x7fff;
	if (se < 0x3ffe || (se == 0x3ffe && i0 <= 0xc90fdaa2)) { return __kernel_sinl(x, z, 0); }
	else if (se == 0x7fff) {
		if (i1 == 0 && i0 == 0x80000000) { set_errno(EDOM); }
		return x - x;
	}
	register const int32_t n = __ieee754_rem_pio2l(x, y);
	switch (n & 3) {
		case 0:
			return __kernel_sinl(y[0], y[1], 1);
		case 1:
			return __kernel_cosl(y[0], y[1]);
		case 2:
			return -__kernel_sinl(y[0], y[1], 1);
		default:
			return -__kernel_cosl(y[0], y[1]);
	}
}
#define __sinl(x)   sinl((x))


#elif LDBL_EQ_FLOAT128


LIB_FUNC MATH_FUNC long double __kernel_cosl(const long double numx, const long double numy) {
	long double x = numx, y = numy;
	int64_t ix;
	GET_LDOUBLE_MSW64S(ix, x);
	const uint32_t tix = ((uint32_t)(((uint64_t)ix) >> 32) & (uint32_t)(~0x80000000));
	if (tix < 0x3ffc3000) {
		if (tix < 0x3fc60000 && (!((int)x))) { return 1.00000000000000000000000000000000000L; }
		const long double z = x * x;
		return 1.00000000000000000000000000000000000L + (z * (-4.99999999999999999999999999999999759E-1L + z * (4.16666666666666666666666666651287795E-2L + z * (-1.38888888888888888888888742314300284E-3L + z * (2.48015873015873015867694002851118210E-5L + z * (-2.75573192239858811636614709689300351E-7L + z * (2.08767569877762248667431926878073669E-9L + z * (-1.14707451049343817400420280514614892E-11L + z * 4.77810092804389587579843296923533297E-14L))))))));
	}
	uint32_t index = 0x3ffe - (tix >> 16);
	const uint32_t hix = (uint32_t)((tix + (uint32_t)(0x200 << index)) & (uint32_t)(0xfffffc00 << index));
	if (signbitl(x)) {
		x = -x;
		y = -y;
	}
	switch (index) {
		case 0:
			index = ((45 << 10) + hix - 0x3ffe0000) >> 8;
			break;
		case 1:
			index = ((13 << 11) + hix - 0x3ffd0000) >> 9;
			break;
		default:
		case 2:
			index = (hix - 0x3ffc3000) >> 10;
			break;
	}
	long double h;
	SET_LDOUBLE_WORDS64(h, ((uint64_t)hix) << 32, 0);
	const long double l = y - (h - x);
	const long double z = l * l;
	const long double sin_l = l * (1.00000000000000000000000000000000000L + z * (-1.66666666666666666666666666666666659E-1L + z * (8.33333333333333333333333333146298442E-3L + z * (-1.98412698412698412697726277416810661E-4L + z * (2.75573192239848624174178393552189149E-6L + z * -2.50521016467996193495359189395805639E-8L)))));
	const long double cos_l_m1 = z * (-5.00000000000000000000000000000000000E-1L + z * (4.16666666666666666666666666556146073E-2L + z * (-1.38888888888888888888309442601939728E-3L + z * (2.48015873015862382987049502531095061E-5L + z * -2.75573112601362126593516899592158083E-7L))));
	return __sincosl_table[index] + (__sincosl_table[index + 1] - (__sincosl_table[index + 2] * sin_l - __sincosl_table[index] * cos_l_m1));
}


LIB_FUNC MATH_FUNC long double __kernel_sinl(const long double numx, const long double numy, const int iy) {
	long double x = numx, y = numy;
	int64_t ix;
	GET_LDOUBLE_MSW64S(ix, x);
	const uint32_t tix = ((uint32_t)(((uint64_t)ix) >> 32) & (uint32_t)(~0x80000000));
	if (tix < 0x3ffc3000) {
		if (tix < 0x3fc60000) {
			// math_check_force_underflow(x);
			if (!((int)x)) { return x; }
		}
		const long double z = x * x;
		return x + (x * (z * (-1.66666666666666666666666666666666538E-1L + z * (8.33333333333333333333333333307532934E-3L + z * (-1.98412698412698412698412534478712057E-4L + z * (2.75573192239858906520896496653095890E-6L + z * (-2.50521083854417116999224301266655662E-8L + z * (1.60590438367608957516841576404938118E-10L + z * (-7.64716343504264506714019494041582610E-13L + z * 2.81068754939739570236322404393398135E-15L)))))))));
	}
	uint32_t index = 0x3ffe - (tix >> 16);
	const uint32_t hix = (uint32_t)((uint32_t)(tix + (uint32_t)(0x200 << index)) & (uint32_t)(0xfffffc00 << index));
	x = fabsl(x);
	switch (index) {
		case 0:
			index = ((45 << 10) + hix - 0x3ffe0000) >> 8;
			break;
		case 1:
			index = ((13 << 11) + hix - 0x3ffd0000) >> 9;
			break;
		default:
		case 2:
			index = (hix - 0x3ffc3000) >> 10;
			break;
	}
	long double h, l;
	SET_LDOUBLE_WORDS64(h, ((uint64_t)hix) << 32, 0);
	if (iy) { l = (ix < 0 ? -y : y) - (h - x); }
	else { l = x - h; }
	const long double z = l * l;
	const long double sin_l = l * (1.00000000000000000000000000000000000L + z * (-1.66666666666666666666666666666666659E-1L + z * (8.33333333333333333333333333146298442E-3L + z * (-1.98412698412698412697726277416810661E-4L + z * (2.75573192239848624174178393552189149E-6L + z * -2.50521016467996193495359189395805639E-8L)))));
	const long double cos_l_m1 = z * (-5.00000000000000000000000000000000000E-1L + z * (4.16666666666666666666666666556146073E-2L + z * (-1.38888888888888888888309442601939728E-3L + z * (2.48015873015862382987049502531095061E-5L + z * -2.75573112601362126593516899592158083E-7L))));
	long double _z = __sincosl_table[index + 2] + (__sincosl_table[index + 3] + (__sincosl_table[index + 2] * cos_l_m1) + (__sincosl_table[index] * sin_l));
	return (ix < 0) ? -_z : _z;
}


LIB_FUNC MATH_FUNC long double cosl(const long double num) {
	long double y[2] = { 0.0L }, z = 0.0L, x = num;
	int64_t n, ix;
	GET_LDOUBLE_MSW64S(ix, x);
	ix &= 0x7fffffffffffffffLL;
	if (ix <= 0x3ffe921fb54442d1LL) { return __kernel_cosl(x, z); }
	else if (ix >= 0x7fff000000000000LL) {
		if (ix == 0x7fff000000000000LL) {
			GET_LDOUBLE_LSW64S(n, x);
			if (n == 0) { set_errno(EDOM); }
		}
		return x - x;
	}
	n = __ieee754_rem_pio2l(x, y);
	switch (n & 3) {
		case 0:
			return __kernel_cosl(y[0], y[1]);
		case 1:
			return -__kernel_sinl(y[0], y[1], 1);
		case 2:
			return -__kernel_cosl(y[0], y[1]);
		default:
			return __kernel_sinl(y[0], y[1], 1);
	}
}
#define __cosl(x)   cosl((x))


LIB_FUNC MATH_FUNC long double sinl(const long double numx) {
	long double y[2] = { 0.0L }, z = 0.0L, x = numx;
	int64_t n, ix;
	GET_LDOUBLE_MSW64S(ix, x);
	ix &= 0x7fffffffffffffffLL;
	if (ix <= 0x3ffe921fb54442d1LL) { return __kernel_sinl(x, z, 0); }
	else if (ix >= 0x7fff000000000000LL) {
		if (ix == 0x7fff000000000000LL) {
			GET_LDOUBLE_LSW64S(n, x);
			if (n == 0) { set_errno(EDOM); }
		}
		return x - x;
	}
	n = __ieee754_rem_pio2l(x, y);
	switch (n & 3) {
		case 0:
			return __kernel_sinl(y[0], y[1], 1);
		case 1:
			return __kernel_cosl(y[0], y[1]);
		case 2:
			return -__kernel_sinl(y[0], y[1], 1);
		default:
			return -__kernel_cosl(y[0], y[1]);
	}
}
#define __sinl(x)   sinl((x))


#endif


LIB_FUNC void sincosf(const float x, float* restrict sinx, float* restrict cosx) {
	*sinx = sinf(x);
	*cosx = cosf(x);
}
#define __sincosf(x, sinx, cosx)   sincosf((x), (sinx), (cosx))


LIB_FUNC void sincos(const double x, double* restrict sinx, double* restrict cosx) {
	*sinx = sin(x);
	*cosx = cos(x);
}
#define __sincos(x, sinx, cosx)   sincos((x), (sinx), (cosx))


#if IS_LDBL_X87


LIB_FUNC void sincosl(const long double x, long double* restrict sinx, long double* restrict cosx) {
	int32_t se, i0, i1;
	GET_LDOUBLE_WORDS(se, i0, i1, x);
	se &= 0x7fff;
	if (se < 0x3ffe || (se == 0x3ffe && i0 <= 0xc90fdaa2)) {
		*sinx = __kernel_sinl(x, 0.0L, 0);
		*cosx = __kernel_cosl(x, 0.0L);
	} else if (se == 0x7fff) {
		*sinx = *cosx = x - x;
		if (isinf(x)) { set_errno(EDOM); }
	} else {
		long double y[2] = { 0.0L };
		int n = __ieee754_rem_pio2l(x, y);
		switch (n & 3) {
			case 0:
				*sinx = __kernel_sinl(y[0], y[1], 1);
				*cosx = __kernel_cosl(y[0], y[1]);
				break;
			case 1:
				*sinx = __kernel_cosl(y[0], y[1]);
				*cosx = -__kernel_sinl(y[0], y[1], 1);
				break;
			case 2:
				*sinx = -__kernel_sinl(y[0], y[1], 1);
				*cosx = -__kernel_cosl(y[0], y[1]);
				break;
			default:
				*sinx = -__kernel_cosl(y[0], y[1]);
				*cosx = __kernel_sinl(y[0], y[1], 1);
				break;
		}
	}
}
#   define __sincosl(x, sinx, cosx)   sincosl((x), (sinx), (cosx))


#elif LDBL_EQ_FLOAT128


LIB_FUNC void __kernel_sincosl(const long double numx, const long double numy, long double* restrict sinx, long double* restrict cosx, const int iy) {
	long double x = numx, y = numy;
	int64_t ix;
	GET_LDOUBLE_MSW64S(ix, x);
	const uint32_t tix = ((uint32_t)(((uint64_t)ix) >> 32)) & (uint32_t)(~0x80000000);
	if (tix < 0x3ffc3000) {
		if (tix < 0x3fc60000) {
			// math_check_force_underflow(x);
			if (!((int)x)) {
				*sinx = x;
				*cosx = 1.00000000000000000000000000000000000L;
				return;
			}
		}
		const long double z = x * x;
		*sinx = x + (x * (z * (-1.66666666666666666666666666666666538E-1L + z * (8.33333333333333333333333333307532934E-3L + z * (-1.98412698412698412698412534478712057E-4L + z * (2.75573192239858906520896496653095890E-6L + z * (-2.50521083854417116999224301266655662E-8L + z * (1.60590438367608957516841576404938118E-10L + z * (-7.64716343504264506714019494041582610E-13L + z * 2.81068754939739570236322404393398135E-15L)))))))));
		*cosx = 1.00000000000000000000000000000000000L + (z * (-4.99999999999999999999999999999999759E-1L + z * (4.16666666666666666666666666651287795E-2L + z * (-1.38888888888888888888888742314300284E-3L + z * (2.48015873015873015867694002851118210E-5L + z * (-2.75573192239858811636614709689300351E-7L + z * (2.08767569877762248667431926878073669E-9L + z * (-1.14707451049343817400420280514614892E-11L + z * 4.77810092804389587579843296923533297E-14L))))))));
		return;
	}
	uint32_t index = 0x3ffe - (tix >> 16);
	const uint32_t hix = (uint32_t)(tix + (uint32_t)(0x200 << index)) & (uint32_t)(0xfffffc00 << index);
	if (signbitl(x)) {
		x = -x;
		y = -y;
	}
	switch (index) {
		case 0:
			index = ((45 << 10) + hix - 0x3ffe0000) >> 8;
			break;
		case 1:
			index = ((13 << 11) + hix - 0x3ffd0000) >> 9;
			break;
		default:  // case 2
			index = (hix - 0x3ffc3000) >> 10;
			break;
	}
	long double h, l;
	SET_LDOUBLE_WORDS64(h, (uint64_t)(((uint64_t)hix) << 32), 0);
	if (iy) { l = y - (h - x); }
	else { l = x - h; }
	long double z = l * l;
	const long double sin_l = l * (1.00000000000000000000000000000000000L + z * (-1.66666666666666666666666666666666659E-1L + z * (8.33333333333333333333333333146298442E-3L + z * (-1.98412698412698412697726277416810661E-4L + z * (2.75573192239848624174178393552189149E-6L + z * -2.50521016467996193495359189395805639E-8L)))));
	const long double cos_l_m1 = z * (-5.00000000000000000000000000000000000E-1L + z * (4.16666666666666666666666666556146073E-2L + z * (-1.38888888888888888888309442601939728E-3L + z * (2.48015873015862382987049502531095061E-5L + z * -2.75573112601362126593516899592158083E-7L))));
	z = __sincosl_table[index + 2] + (__sincosl_table[index + 3] + (__sincosl_table[index + 2] * cos_l_m1) + (__sincosl_table[index + 0] * sin_l));
	*sinx = (ix < 0) ? -z : z;
	*cosx = __sincosl_table[index + 0] + (__sincosl_table[index + 1] - (__sincosl_table[index + 2] * sin_l - __sincosl_table[index + 0] * cos_l_m1));
}


LIB_FUNC void sincosl(const long double x, long double* restrict sinx, long double* restrict cosx) {
	int64_t ix;
	GET_LDOUBLE_MSW64S(ix, x);
	ix &= 0x7fffffffffffffffLL;
	if (ix <= 0x3ffe921fb54442d1LL) { __kernel_sincosl(x, 0.0L, sinx, cosx, 0); return; }
	else if (ix >= 0x7fff000000000000LL) {
		*sinx = *cosx = x - x;
		if (__isinfl(x)) { set_errno(EDOM); }
		return;
	}
	long double y[2] = { 0.0L };
	const int n = __ieee754_rem_pio2l(x, y);
	switch (n & 3) {
		case 0:
			__kernel_sincosl(y[0], y[1], sinx, cosx, 1);
			break;
		case 1:
			__kernel_sincosl(y[0], y[1], cosx, sinx, 1);
			*cosx = -*cosx;
			break;
		case 2:
			__kernel_sincosl(y[0], y[1], sinx, cosx, 1);
			*sinx = -*sinx;
			*cosx = -*cosx;
			break;
		default:
			__kernel_sincosl(y[0], y[1], cosx, sinx, 1);
			*sinx = -*sinx;
			break;
	}
}
#   define __sincosl(x, sinx, cosx)   sincosl((x), (sinx), (cosx))


#endif


LIB_FUNC MATH_FUNC float __ieee754_acosf(const float x) {
#   ifdef ARCHX86
	return atan2f(sqrtf(1 - (x * x)), x);
#   else
	int32_t hx;
	GET_FLOAT_WORD(hx, x);
	const int32_t ix = hx & 0x7fffffff;
	if (ix == 0x3f800000) {
		if (hx > 0) { return 0.0; }
		else { return PIF; }
	} else if (ix > 0x3f800000) { return (x - x) / (x - x); }
	else if (ix < 0x3f000000) {
		if (ix <= 0x23000000) { return M_PI_2F + 7.5497894159E-8F; }
		const float z = x * x;
		const float p = z * (1.6666667163E-1F + z * (-3.2556581497E-1F + z * (2.0121252537E-1F + z * (-4.0055535734E-2F + z * (7.9153501429E-4F + z * 3.4793309169E-5F)))));
		const float q = 1.0F + z * (-2.4033949375F + z * (2.0209457874F + z * (-6.8828397989E-1F + z * 7.7038154006E-2F)));
		return M_PI_2F - (x - (7.5497894159E-8F - x * (p / q)));
	} else if (hx < 0) {
		const float z = (1.0F + x) * 0.5F;
		const float p = z * (1.6666667163E-1F + z * (-3.2556581497E-1F + z * (2.0121252537E-1F + z * (-4.0055535734E-2F + z * (7.9153501429E-4F + z * 3.4793309169E-5F)))));
		const float s = __ieee754_sqrtf(z);
		const float w = (p / (1.0F + z * (-2.4033949375F + z * (2.0209457874F + z * (-6.8828397989E-1F + z * 7.7038154006E-2F))))) * s - (float)(7.5497894159E-8F);
		return PIF - 2.0F * (s + w);
	}
	const float z = (1.0F - x) * 0.5F;
	const float s = __ieee754_sqrtf(z);
	float df = s;
	int32_t idf;
	GET_FLOAT_WORD(idf, df);
	SET_FLOAT_SWORD(df, (idf & (int32_t)0xfffff000));
	const float p = z * (1.6666667163E-1F + z * (-3.2556581497E-1F + z * (2.0121252537E-1F + z * (-4.0055535734E-2F + z * (7.9153501429E-4F + z * 3.4793309169E-5F)))));
	const float q = 1.0F + z * (-2.4033949375F + z * (2.0209457874F + z * (-6.8828397989E-1F + z * 7.7038154006E-2F)));
	return 2.0F * (df + ((p / q) * s + ((z - df * df) / (s + df))));
#   endif
}


LIB_FUNC MATH_FUNC double __ieee754_acos(const double x) {
#   ifdef ARCHX86
	return atan2(sqrt(1 - (x * x)), x);
#   else
	int32_t hx;
	GET_HIGH_SWORD(hx, x);
	const int32_t ix = hx & 0x7fffffff;
	if (ix >= 0x3ff00000) {
		uint32_t lx;
		GET_LOW_WORD(lx, x);
		if (((ix - 0x3ff00000) | (int32_t)lx) == 0) {
			if (hx > 0) { return 0.0; }
			else { return PI; }
		}
		return (x - x) / (x - x);
	} else if (ix < 0x3fe00000) {
		if (ix <= 0x3c600000) { return M_PI_2 + 6.12323399573676603587E-17; }
		const double z = x * x;
		const double p = z * (1.66666666666666657415E-1 + z * (-3.25565818622400915405E-1 + z * (2.01212532134862925881E-1 + z * (-4.00555345006794114027E-2 + z * (7.91534994289814532176E-4 + z * 3.47933107596021167570E-5)))));
		const double q = 1.0 + z * (-2.40339491173441421878 + z * (2.02094576023350569471 + z * (-6.88283971605453293030E-1 + z * 7.70381505559019352791E-2)));
		return M_PI_2 - (x - (6.12323399573676603587E-17 - x * (p / q)));
	} else if (hx < 0) {
		const double z = (1.0 + x) * 0.5;
		const double p = z * (1.66666666666666657415E-1 + z * (-3.25565818622400915405E-1 + z * (2.01212532134862925881E-1 + z * (-4.00555345006794114027E-2 + z * (7.91534994289814532176E-4 + z * 3.47933107596021167570E-5)))));
		const double q = 1.0 + z * (-2.40339491173441421878 + z * (2.02094576023350569471 + z * (-6.88283971605453293030E-1 + z * 7.70381505559019352791E-2)));
		const double s = __ieee754_sqrt(z);
		return PI - 2.0 * (s + ((p / q) * s - 6.12323399573676603587E-17));
	}
	const double z = (1.0 - x) * 0.5;
	const double s = __ieee754_sqrt(z);
	double df = s;
	SET_LOW_WORD(df, 0);
	const double c = (z - df * df) / (s + df);
	const double p = z * (1.66666666666666657415E-1 + z * (-3.25565818622400915405E-1 + z * (2.01212532134862925881E-1 + z * (-4.00555345006794114027E-2 + z * (7.91534994289814532176E-4 + z * 3.47933107596021167570E-5)))));
	const double q = 1.0 + z * (-2.40339491173441421878 + z * (2.02094576023350569471 + z * (-6.88283971605453293030E-1 + z * 7.70381505559019352791E-2)));
	return 2.0 * (df + ((p / q) * s + c));
#   endif
}


LIB_FUNC MATH_FUNC float __ieee754_acoshf(const float x) {
	int32_t hx;
	GET_FLOAT_WORD(hx, x);
	if (hx < 0x3f800000) { return ((x - x) / (x - x)); }
	else if (hx >= 0x4d800000) {
		if (!(FLT_UWORD_IS_FINITE(hx))) { return x + x; }
		else { return __ieee754_logf(x) + 6.9314718246E-1F; }
	} else if (hx == 0x3f800000) { return 0.0; }
	else if (hx > 0x40000000) {
		return __ieee754_logf((2.0F * x) - 1.0F / (x + __ieee754_sqrtf((x * x) - 1.0F)));
	} else {
		register const float t = x - 1.0F;
		return log1pf(t + __ieee754_sqrtf(2.0F * t + t * t));
	}
}


LIB_FUNC MATH_FUNC double __ieee754_acosh(const double x) {
	int32_t hx, lx;
	EXTRACT_SWORDS(hx, lx, x);
	if (hx < 0x3ff00000) { return (x - x) / (x - x); }
	else if (hx >= 0x41b00000) {
		if (hx >= 0x7ff00000) { return x + x; }
		else { return log(x) + 6.93147180559945286227E-1; }
	} else if (((uint32_t)(hx - 0x3ff00000) | (uint32_t)lx) == 0) { return 0.0; }
	else if (hx > 0x40000000) {
		return log(2.0 * x - 1.0 / (x + __ieee754_sqrt((x * x) - 1.0)));
	} else {
		register const double t = x - 1.0;
		return log1p(t + __ieee754_sqrt(2.0 * t + t * t));
	}
}


LIB_FUNC MATH_FUNC float __ieee754_coshf(const float x) {
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (!(FLT_UWORD_IS_FINITE(ix))) { return x * x; }
	else if (ix < 0x3eb17218) {
		register const float t = expm1f(fabsf(x));
		if (ix < 0x24000000) { return 1.0F + t; }
		return 1.0F + (t * t) / (2.0F + t + t);
	} else if (ix < 0x41b00000) {
		register const float t = __ieee754_expf(fabsf(x));
		return ((0.5F * t) + (0.5F / t));
	} else if (ix <= FLT_UWORD_LOG_MAX) { return 0.5F * __ieee754_expf(fabsf(x)); }
	else if (ix <= FLT_UWORD_LOG_2MAX) {
		register const float w = __ieee754_expf(0.5F * fabsf(x));
		return 0.5F * w * w;
	}
	return HUGEF_SQ;
}


LIB_FUNC MATH_FUNC double __ieee754_cosh(const double x) {
	int32_t ix;
	GET_HIGH_SWORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x7ff00000) { return x * x; }
	else if (ix < 0x3fd62e43) {
		register const double t = expm1(fabs(x));
		register const double w = 1.0 + t;
		if (ix < 0x3c800000) { return w; }
		return 1.0 + (t * t) / (w + w);
	} else if (ix < 0x40360000) {
		register const double t = exp(fabs(x));
		return ((0.5 * t) + (0.5 / t));
	} else if (ix < 0x40862e42) { return 0.5 * exp(fabs(x)); }
	uint32_t lx;
	GET_LOW_WORD(lx, x);
	if (ix < 0x408633ce || (ix == 0x408633ce && lx <= (uint32_t)0x8fb9f87d)) {
		register const double w = exp(0.5 * fabs(x));
		return (0.5 * w) * w;
	}
	return HUGE_SQ;
}


LIB_FUNC MATH_FUNC float __ieee754_asinf(const float x) {
	int32_t hx;
	GET_FLOAT_WORD(hx, x);
	const int32_t ix = hx & 0x7fffffff;
	if (ix == 0x3f800000) {
		return (x * M_PI_2F + x * -4.37113900018624283E-8F);
	} else if (ix > 0x3f800000) {
		return (x - x) / (x - x);
	} else if (ix < 0x3f000000) {
		if (ix < 0x32000000) {
			if ((HUGEF + x) > 1.0F) { return x; }
		} else {
			const float t = x * x;
			const float p = t * (1.6666667163E-1F + t * (-3.2556581497E-1F + t * (2.0121252537E-1F + t * (-4.0055535734E-2F + t * (7.9153501429E-4F + t * 3.4793309169E-5F)))));
			const float q = 1.0F + t * (-2.4033949375F + t * (2.0209457874F + t * (-6.8828397989E-1F + t * 7.7038154006E-2F)));
			return x + x * (p / q);
		}
	}
	float t = (1.0F - fabsf(x)) * 0.5F;
	float p = t * (1.6666667163E-1F + t * (-3.2556581497E-1F + t * (2.0121252537E-1F + t * (-4.0055535734E-2F + t * (7.9153501429E-4F + t * 3.4793309169E-5F)))));
	float q = 1.0F + t * (-2.4033949375F + t * (2.0209457874F + t * (-6.8828397989E-1F + t * 7.7038154006E-2F)));
	const float s = __ieee754_sqrtf(t);
	if (ix >= 0x3f79999a) {
		t = M_PI_2F - (2.0F * (s + s * (p / q)) - -4.37113900018624283E-8F);
	} else {
		uint32_t iw;
		float w = s;
		GET_FLOAT_UWORD(iw, w);
		SET_FLOAT_UWORD(w, (iw & 0xfffff000));
		const float c = (t - w * w) / (s + w);
		p = 2.0F * s * (p / q) - (-4.37113900018624283E-8F - 2.0F * c);
		q = M_PI_4F - 2.0F * w;
		t = M_PI_4F - (p - q);
	}
	if (hx > 0) { return t; }
	return -t;
}


LIB_FUNC MATH_FUNC double __ieee754_asin(const double x) {
	int32_t hx;
	GET_HIGH_SWORD(hx, x);
	const int32_t ix = hx & 0x7fffffff;
	if (ix >= 0x3ff00000) {
		uint32_t lx;
		GET_LOW_WORD(lx, x);
		if (((ix - 0x3ff00000) | (int32_t)lx) == 0) { return x * M_PI_2 + x * 6.12323399573676603587E-17; }
		return (x - x) / (x - x);
	} else if (ix < 0x3fe00000) {
		if (ix < 0x3e400000) {
			if ((HUGE + x) > 1.0) { return x; }
		} else {
			const double t = x * x;
			const double p = t * (1.66666666666666657415E-1 + t * (-3.25565818622400915405E-1 + t * (2.01212532134862925881E-1 + t * (-4.00555345006794114027E-2 + t * (7.91534994289814532176E-4 + t * 3.47933107596021167570E-5)))));
			const double q = 1.0 + t * (-2.40339491173441421878 + t * (2.02094576023350569471 + t * (-6.88283971605453293030E-1 + t * 7.70381505559019352791E-2)));
			return x + x * (p / q);
		}
	}
	double t = (1.0 - fabs(x)) * 0.5;
	double p = t * (1.66666666666666657415E-1 + t * (-3.25565818622400915405E-1 + t * (2.01212532134862925881E-1 + t * (-4.00555345006794114027E-2 + t * (7.91534994289814532176E-4 + t * 3.47933107596021167570E-5)))));
	double q = 1.0 + t * (-2.40339491173441421878 + t * (2.02094576023350569471 + t * (-6.88283971605453293030E-1 + t * 7.70381505559019352791E-2)));
	const double s = __ieee754_sqrt(t);
	if (ix >= 0x3fef3333) {
		t = M_PI_2 - (2.0 * (s + s * (p / q)) - 6.12323399573676603587E-17);
	} else {
		double w = s;
		SET_LOW_WORD(w, 0);
		const double c = (t - w * w) / (s + w);
		p = 2.0 * s * (p / q) - (6.12323399573676603587E-17 - 2.0 * c);
		q = 7.85398163397448278999E-1 - 2.0 * w;
		t = 7.85398163397448278999E-1 - (p - q);
	}
	if (hx > 0) { return t; }
	return -t;
}


LIB_FUNC MATH_FUNC double __ieee754_sinh(const double x) {
	int32_t jx;
	GET_HIGH_SWORD(jx, x);
	const int32_t ix = jx & 0x7fffffff;
	if (ix >= 0x7ff00000) { return x + x; }
	double h = 0.5;
	if (jx < 0) { h = -h; }
	if (ix < 0x40360000) {
		if (ix < 0x3e300000 && ((DBL_LARGE + x) > 1.0)) { return x; }
		const double t = expm1(fabs(x));
		if (ix < 0x3ff00000) { return h * (2.0 * t - t * t / (t + 1.0)); }
		return h * (t + t / (t + 1.0));
	} else if (ix < 0x40862e42) { return h * exp(fabs(x)); }
	uint32_t lx;
	GET_LOW_WORD(lx, x);
	if (ix < 0x408633ce || (ix == 0x408633ce && lx <= (uint32_t)0x8fb9f87d)) {
		const double w = exp(0.5 * fabs(x));
		return h * w * w;
	}
	return x * DBL_LARGE;
}


LIB_FUNC MATH_FUNC float __ieee754_atanhf(const float num) {
	float x = num;
	int32_t hx;
	GET_FLOAT_WORD(hx, x);
	const int32_t ix = hx & 0x7fffffff;
	if (ix > 0x3f800000) { return (x - x) / (x - x); }
	else if (ix == 0x3f800000) { return x / 0.0F; }
	else if ((ix < 0x31800000) && ((HUGEF + x) > 0.0F)) { return x; }
	SET_FLOAT_SWORD(x, ix);
	register float t;
	if (ix < 0x3f000000) {
		t = x + x;
		t = 0.5F * log1pf(t + t * x / (1.0F - x));
	} else { t = 0.5F * log1pf((x + x) / (1.0F - x)); }
	if (hx >= 0) { return t; }
	return -t;
}


LIB_FUNC MATH_FUNC double __ieee754_atanh(const double num) {
	double x = num;
	int32_t hx, lx;
	EXTRACT_SWORDS(hx, lx, x);
	const int32_t ix = hx & 0x7fffffff;
	if ((ix | ((lx | (-lx)) >> 31)) > 0x3ff00000) { return (x - x) / (x - x); }
	else if (ix == 0x3ff00000) { return x / 0.0; }
	else if (ix < 0x3e300000 && (HUGE + x) > 0.0) { return x; }
	SET_HIGH_WORD(x, ix);
	register double t;
	if (ix < 0x3fe00000) {
		t = x + x;
		t = 0.5 * log1p(t + t * x / (1.0 - x));
	} else { t = 0.5 * log1p((x + x) / (1.0 - x)); }
	if (hx >= 0) { return t; }
	return -t;
}


LIB_FUNC MATH_FUNC float __ieee754_atan2f(const float y, const float x) {
	int32_t hx, hy;
	GET_FLOAT_WORD(hx, x);
	const int32_t ix = (hx & 0x7fffffff);
	GET_FLOAT_WORD(hy, y);
	const int32_t iy = hy & 0x7fffffff;
	if (FLT_UWORD_IS_NAN(ix) || FLT_UWORD_IS_NAN(iy)) { return x + y; }
	else if (hx == 0x3f800000) { return atanf(y); }
	const int32_t m = ((hy >> 31) & 1) | ((hx >> 30) & 2);
	if (FLT_UWORD_IS_ZERO(iy)) {
		switch (m) {
			case 0:
			case 1:
				return y;
			case 2:
				return PIF + TINYF;
			default:  // case 3
				return -PIF - TINYF;
		}
	} else if (FLT_UWORD_IS_ZERO(ix)) { return (hy < 0) ? (-M_PI_2F - TINYF) : (M_PI_2F + TINYF); }
	else if (FLT_UWORD_IS_INFINITE(ix)) {
		if (FLT_UWORD_IS_INFINITE(iy)) {
			switch (m) {
				case 0:
					return 7.8539818525E-1F + TINYF;
				case 1:
					return -7.8539818525E-1F - TINYF;
				case 2:
					return 3.0F * 7.8539818525E-1F + TINYF;
				default:  // case 3
					return -3.0F * 7.8539818525E-1F - TINYF;
			}
		} else {
			switch (m) {
				case 0:
					return 0.0F;
				case 1:
					return -0.0F;
				case 2:
					return PIF + TINYF;
				default:  // case 3
					return -PIF - TINYF;
			}
		}
	}
	if (FLT_UWORD_IS_INFINITE(iy)) { return (hy < 0) ? (-M_PI_2F - TINYF) : (M_PI_2F + TINYF); }
	const int32_t k = (iy - ix) >> 23;
	float z;
	if (k > 60) { z = M_PI_2F + 0.5F * -8.7422776573E-8F; }
	else if (hx < 0 && k < -60) { z = 0.0F; }
	else { z = atanf(fabsf(y / x)); }
	switch (m) {
		case 0:
			return z;
		case 1:
			GET_FLOAT_WORD(hy, z);
			SET_FLOAT_UWORD(z, ((uint32_t)hy ^ 0x80000000));
			return z;
		case 2:
			return PIF - (z - -8.7422776573E-8F);
		default:
			return (z - -8.7422776573E-8F) - PIF;
	}
}


LIB_FUNC MATH_FUNC double __ieee754_atan2(const double y, const double x) {
	int32_t hx, hy, lx, ly;
	EXTRACT_SWORDS(hx, lx, x);
	const int32_t ix = hx & 0x7fffffff;
	EXTRACT_SWORDS(hy, ly, y);
	const int32_t iy = hy & 0x7fffffff;
	if ((((uint32_t)ix | (((uint32_t)lx | (uint32_t)-lx) >> 31)) > 0x7ff00000) || (((uint32_t)iy | (((uint32_t)ly | (uint32_t)-ly) >> 31)) > 0x7ff00000)) { return x + y; }
	else if (((uint32_t)(hx - 0x3ff00000) | (uint32_t)lx) == 0) { return atan(y); }
	const int32_t m = ((hy >> 31) & 1) | ((hx >> 30) & 2);
	if ((iy | ly) == 0) {
		switch (m) {
			case 0:
			case 1:
				return y;
			case 2:
				return PI + TINY;
			default:  // case 3
				return -PI - TINY;
		}
	} else if ((ix | lx) == 0) { return (hy < 0) ? (-M_PI_2 - TINY) : (M_PI_2 + TINY); }
	if (ix == 0x7ff00000) {
		if (iy == 0x7ff00000) {
			switch (m) {
				case 0:
					return 7.8539816339744827900E-1 + TINY;
				case 1:
					return -7.8539816339744827900E-1 - TINY;
				case 2:
					return 3.0 * 7.8539816339744827900E-1 + TINY;
				default:  // case 3
					return -3.0 * 7.8539816339744827900E-1 - TINY;
			}
		} else {
			switch (m) {
				case 0:
					return 0.0;
				case 1:
					return -0.0;
				case 2:
					return PI + TINY;
				default:  // case 3
					return -PI - TINY;
			}
		}
	} else if (iy == 0x7ff00000) { return (hy < 0) ? (-M_PI_2 - TINY) : (M_PI_2 + TINY); }
	const int32_t k = (iy - ix) >> 20;
	double z;
	if (k > 60) { z = M_PI_2 + 0.5 * 1.2246467991473531772E-16; }
	else if (hx < 0 && k < -60) { z = 0.0; }
	else { z = atan(fabs(y / x)); }
	switch (m) {
		case 0:
			return z;
		case 1:
			GET_HIGH_SWORD(hy, z);
			SET_HIGH_WORD(z, ((uint32_t)hy ^ 0x80000000));
			return z;
		case 2:
			return PI - (z - 1.2246467991473531772E-16);
		default:
			return (z - 1.2246467991473531772E-16) - PI;
	}
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double atan2l(const long double y, const long double x) {
	return (long double)__ieee754_atan2((double)y, (double)x);
}
#endif


LIB_FUNC MATH_FUNC float acosf(const float x) {
#if IS_LIBM_POSIX
	return __ieee754_acosf(x);
#else
	const float z = __ieee754_acosf(x);
	if (__isnanf(x)) { return z; }
	else if (fabsf(x) > 1.0F) {
		exc.type = DOMAIN;
		exc.name = "acosf";
		exc.err = EDOM;
		exc.arg1 = exc.arg2 = (double)x;
		exc.retval = nan("");
		matherr(&exc);
		return (float)exc.retval;
	} else { return z; }
#endif
}


LIB_FUNC MATH_FUNC double acos(const double x) {
#if IS_LIBM_POSIX
	return __ieee754_acos(x);
#else
	const double z = __ieee754_acos(x);
	if (__isnan(x)) { return z; }
	else if (fabs(x) > 1.0) {
		exc.type = DOMAIN;
		exc.name = "acos";
		exc.err = EDOM;
		exc.arg1 = exc.arg2 = x;
		exc.retval = nan("");
		matherr(&exc);
		return exc.retval;
	} else { return z; }
#endif
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double acosl(const long double x) {
	return (long double)acos((double)x);
}
#endif


LIB_FUNC MATH_FUNC float acoshf(const float x) {
#if IS_LIBM_POSIX
	return __ieee754_acoshf(x);
#else
	const float z = __ieee754_acoshf(x);
	if (__isnanf(x)) { return z; }
	else if (x < 1.0F) {
		exc.type = DOMAIN;
		exc.name = "acoshf";
		exc.err = EDOM;
		exc.arg1 = exc.arg2 = (double)x;
		exc.retval = 0.0 / 0.0;
		matherr(&exc);
		return (float)exc.retval;
	} else { return z; }
#endif
}


LIB_FUNC MATH_FUNC double acosh(const double x) {
#if IS_LIBM_POSIX
	return __ieee754_acosh(x);
#else
	const double z = __ieee754_acosh(x);
	if (__isnan(x)) { return z; }
	else if (x < 1.0) {
		exc.type = DOMAIN;
		exc.name = "acosh";
		exc.err = EDOM;
		exc.arg1 = exc.arg2 = x;
		exc.retval = 0.0 / 0.0;
		matherr(&exc);
		return exc.retval;
	} else { return z; }
#endif
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double acoshl(const long double x) {
	return (long double)acosh((double)x);
}
#endif


LIB_FUNC MATH_FUNC float cosf(const float x) {
#   ifdef ARCHX86
	float r = x;
	asm ("fld %0;" "fcos;" "fstp %1;" : "=m"(r) : "m"(r));
	return r;
#   else
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix <= 0x3f490fd8) { return __kernel_cosf(x, 0.0F); }
	else if (!FLT_UWORD_IS_FINITE(ix)) { return x - x; }
	double align32 y[2] = { 0 };
	const int32_t n = __rem_pio2((double)x, &y);
	const float y0 = (float)y[0], y1 = (float)y[1];
	switch ((n & 3)) {
		case 0:
			return __kernel_cosf(y0, y1);
		case 1:
			return -__kernel_sinf(y0, y1, 1);
		case 2:
			return -__kernel_cosf(y0, y1);
		default:
			return __kernel_sinf(y0, y1, 1);
	}
#   endif
}


LIB_FUNC MATH_FUNC double cos(const double x) {
#   ifdef ARCHX86
	double r = x;
	asm ("fldl %0;" "fcos;" "fstpl %1;" : "=m"(r) : "m"(r));
	return r;
#   else
	int32_t ix;
	GET_HIGH_SWORD(ix, x);
	ix &= 0x7fffffff;
	if (ix <= 0x3fe921fb) { return __kernel_cos(x, 0.0); }
	else if (ix >= 0x7ff00000) { return x - x; }
	else {
		double align64 y[2] = { 0 };
		const int32_t n = __ieee754_rem_pio2(x, &y);
		switch ((n & 3)) {
			case 0:
				return __kernel_cos(y[0], y[1]);
			case 1:
				return -__kernel_sin(y[0], y[1], 1);
			case 2:
				return -__kernel_cos(y[0], y[1]);
			default:
				return __kernel_sin(y[0], y[1], 1);
		}
	}
#  endif
}


LIB_FUNC MATH_FUNC float coshf(const float x) {
#if IS_LIBM_POSIX
	return __ieee754_coshf(x);
#else
	const float z = __ieee754_coshf(x);
	if (__isnanf(x)) { return z; }
	else if (fabsf(x) > 8.9415985107E+1F) {
		exc.type = OVERFLOW;
		exc.name = "coshf";
		exc.err = ERANGE;
		exc.arg1 = exc.arg2 = (double)x;
		exc.retval = HUGE_VAL;
		matherr(&exc);
		return (float)exc.retval;
	} else { return z; }
#endif
}


LIB_FUNC MATH_FUNC double cosh(const double x) {
#if IS_LIBM_POSIX
	return __ieee754_cosh(x);
#else
	const double z = __ieee754_cosh(x);
	if (__isnan(x)) { return z; }
	else if (fabs(x) > 7.10475860073943863426E+2) {
		exc.type = OVERFLOW;
		exc.name = "cosh";
		exc.err = ERANGE;
		exc.arg1 = exc.arg2 = x;
		exc.retval = HUGE_VAL;
		matherr(&exc);
		return exc.retval;
	} else { return z; }
#endif
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double coshl(const long double x) {
	return (long double)cosh((double)x);
}
#endif


LIB_FUNC MATH_FUNC float asinf(const float x) {
#if IS_LIBM_POSIX
	return __ieee754_asinf(x);
#else
	const float z = __ieee754_asinf(x);
	if (__isnanf(x)) { return z; }
	else if (fabsf(x) > 1.0F) {
		exc.type = DOMAIN;
		exc.name = "asinf";
		exc.err = EDOM;
		exc.arg1 = exc.arg2 = (double)x;
		exc.retval = nan("");
		matherr(&exc);
		return (float)exc.retval;
	} else { return z; }
#endif
}


LIB_FUNC MATH_FUNC double asin(const double x) {
#if IS_LIBM_POSIX
	return __ieee754_asin(x);
#else
	const double z = __ieee754_asin(x);
	if (__isnan(x)) { return z; }
	else if (fabs(x) > 1.0) {
		exc.type = DOMAIN;
		exc.name = "asin";
		exc.err = EDOM;
		exc.arg1 = exc.arg2 = x;
		exc.retval = nan("");
		matherr(&exc);
		return exc.retval;
	} else { return z; }
#endif
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double asinl(const long double x) {
	return (long double)asin((double)x);
}
#endif


LIB_FUNC MATH_FUNC float asinhf(const float x) {
	float t, w;
	int32_t hx, ix;
	GET_FLOAT_WORD(hx, x);
	ix = hx & 0x7fffffff;
	if (!FLT_UWORD_IS_FINITE(ix)) { return x + x; }
	else if (ix < 0x31800000 && (HUGEF + x > 1.0F)) { return x; }
	if (ix > 0x4d800000) {
		w = __ieee754_logf(fabsf(x)) + 6.9314718246E-1F;
	} else if (ix > 0x40000000) {
		t = fabsf(x);
		w = __ieee754_logf(2.0F * t + 1.0F / (__ieee754_sqrtf(x * x + 1.0F) + t));
	} else {
		t = x * x;
		w = log1pf(fabsf(x) + t / (1.0F + __ieee754_sqrtf(1.0F + t)));
	}
	if (hx > 0) { return w; }
	else { return -w; }
}


LIB_FUNC MATH_FUNC double asinh(const double x) {
	double t, w;
	int32_t hx, ix;
	GET_HIGH_SWORD(hx, x);
	ix = hx & 0x7fffffff;
	if (ix >= 0x7ff00000) { return x + x; }
	else if (ix < 0x3e300000 && (HUGE + x > 1.0)) { return x; }
	if (ix > 0x41b00000) {
		w = log(fabs(x)) + 6.93147180559945286227E-1;
	} else if (ix > 0x40000000) {
		t = fabs(x);
		w = log(2.0 * t + 1.0 / (__ieee754_sqrt(x * x + 1.0) + t));
	} else {
		t = x * x;
		w = log1p(fabs(x) + t / (1.0 + __ieee754_sqrt(1.0 + t)));
	}
	if (hx > 0) { return w; }
	else { return -w; }
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double asinhl(const long double x) {
	return (long double)asinh((double)x);
}
#endif


LIB_FUNC MATH_FUNC float sinf(const float x) {
#   ifdef ARCHX86
	float r = x;
	asm ("fld %0;" "fsin;" "fstp %1;" : "=m"(r) : "m"(r));
	return r;
#   else
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix <= 0x3f490fd8) { return __kernel_sinf(x, 0.0F, 0); }
	else if (!FLT_UWORD_IS_FINITE(ix)) { return x - x; }
	else {
		double align32 y[2] = { 0 };
		const int32_t n = __rem_pio2((double)x, &y);
		const float y0 = (float)y[0], y1 = (float)y[1];
		switch (n & 3) {
			case 0:
				return __kernel_sinf(y0, y1, 1);
			case 1:
				return __kernel_cosf(y0, y1);
			case 2:
				return -__kernel_sinf(y0, y1, 1);
			default:
				return -__kernel_cosf(y0, y1);
		}
	}
#   endif
}


LIB_FUNC MATH_FUNC double sin(const double x) {
#   ifdef ARCHX86
	double r = x;
	asm ("fldl %0;" "fsin;" "fstpl %1;" : "=m"(r) : "m"(r));
	return r;
#   else
	int32_t ix;
	GET_HIGH_SWORD(ix, x);
	ix &= 0x7fffffff;
	if (ix <= 0x3fe921fb) { return __kernel_sin(x, 0.0, 0); }
	else if (ix >= 0x7ff00000) { return x - x; }
	else {
		double align64 y[2] = { 0 };
		const int32_t n = __ieee754_rem_pio2(x, &y);
		switch (n & 3) {
			case 0:
				return __kernel_sin(y[0], y[1], 1);
			case 1:
				return __kernel_cos(y[0], y[1]);
			case 2:
				return -__kernel_sin(y[0], y[1], 1);
			default:
				return -__kernel_cos(y[0], y[1]);
		}
	}
#   endif
}


LIB_FUNC MATH_FUNC float __ieee754_sinhf(const float num) {
	float x = num;
	int32_t jx;
	GET_FLOAT_WORD(jx, x);
	const int32_t ix = jx & 0x7fffffff;
	if (PREDICT_UNLIKELY(ix >= 0x7f800000)) { return x + x; }
	float h = 0.5F;
	if (jx < 0) { h = -h; }
	if (ix < 0x41b00000) {
		if (PREDICT_UNLIKELY(ix < 0x31800000)) {
			// math_check_force_underflow(x);
			if (FLT_LARGE + x > 1.0F) { return x; }
		}
		const float t = expm1f(fabsf(x));
		if (ix < 0x3f800000) { return h * (2.0F * t - t * t / (t + 1.0F)); }
		return h * (t + t / (t + 1.0F));
	} else if (ix < 0x42b17180) { return h * __ieee754_expf(fabsf(x)); }
	else if (ix <= 0x42b2d4fc) {
		const float w = __ieee754_expf(0.5F * fabsf(x));
		return h * w * w;
	}
	return math_narrow_eval(x * FLT_LARGE);
}
#define __sinhf_finite(x)   __ieee754_sinhf((x))


LIB_FUNC MATH_FUNC float sinhf(const float x) {
#if IS_LIBM_POSIX
	return __ieee754_sinhf(x);
#else
	const float z = __ieee754_sinhf(x);
	if (!finitef(z) && finitef(x)) {
		exc.type = OVERFLOW;
		exc.name = "sinhf";
		exc.err = ERANGE;
		exc.arg1 = exc.arg2 = (double)x;
		exc.retval = ((x > 0.0F) ? HUGE_VAL : -HUGE_VAL);
		matherr(&exc);
		return (float)exc.retval;
	} else { return z; }
#endif
}


LIB_FUNC MATH_FUNC double sinh(const double x) {
#if IS_LIBM_POSIX
	return __ieee754_sinh(x);
#else
	const double z = __ieee754_sinh(x);
	if (!finite(z) && finite(x)) {
		exc.type = OVERFLOW;
		exc.name = "sinh";
		exc.err = ERANGE;
		exc.arg1 = exc.arg2 = x;
		exc.retval = ( (x > 0.0) ? HUGE_VAL : -HUGE_VAL);
		matherr(&exc);
		return exc.retval;
	} else { return z; }
#endif
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double sinhl(const long double x) {
	return (long double)sinh((double)x);
}
#endif


/** Return the Pi Sine of the given number; return 0.0 on error */
LIB_FUNC MATH_FUNC double sinpi(const double num) {
	if (PREDICT_UNLIKELY(!(isfinite(num)))) { return 0.0; }
	register const double x = fmod(fabs(num), 2.0);
	const long n = (long)lround(2.0 * x);
	register double r;
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


LIB_FUNC MATH_FUNC double tan(const double x) {
	int32_t ix;
	GET_HIGH_SWORD(ix, x);
	ix &= 0x7fffffff;
	if (ix <= 0x3fe921fb) { return __kernel_tan(x, 0.0, 1); }
	else if (ix >= 0x7ff00000) { return x - x; }
	double y[2] = { 0.0 };
	const int rem_pio = 1 - ((__ieee754_rem_pio2(x, y) & 1) << 1);
	return __kernel_tan(y[0], y[1], rem_pio);
}


LIB_FUNC MATH_FUNC float tanf(const float x) {
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix <= 0x3f490fda) { return __kernel_tanf(x, 0.0F, 1); }
	else if (!FLT_UWORD_IS_FINITE(ix)) { return x - x; }
	return (float)tan((double)x);
}


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double tanl(const long double x) {
	return (long double)tan((double)x);
}
#endif


/** Return the arc-tangent of a float */
LIB_FUNC MATH_FUNC float atanf(const float num) {
#   ifdef ARCHX86
	float ret;
	asm ("fpatan;" : "=t"(ret) : "0"(num), "u"(1.0F) : "st(1)");
	return ret;
#   else
	float x = num;
	int32_t hx, idx;
	GET_FLOAT_WORD(hx, x);
	const int32_t ix = hx & 0x7fffffff;
	if (ix >= 0x50800000) {
		if (FLT_UWORD_IS_NAN(ix)) { return x + x; }
		else if (hx > 0) { return atanhif[3] + atanlof[3]; }
		else { return -atanhif[3] - atanlof[3]; }
	}
	if (ix < 0x3ee00000) {
		if (ix < 0x31000000 && (HUGEF + x > 1.0F)) { return x; }
		idx = -1;
	} else {
		x = fabsf(x);
		if (ix < 0x3f980000) {
			if (ix < 0x3f300000) {
				idx = 0;
				x = (2.0F * x - 1.0F) / (2.0F + x);
			} else {
				idx = 1;
				x = (x - 1.0F) / (x + 1.0F);
			}
		} else {
			if (ix < 0x401c0000) {
				idx = 2;
				x = (x - 1.5F) / (1.0F + 1.5F * x);
			} else {
				idx = 3;
				x = -1.0F / x;
			}
		}
	}
	float z = x * x;
	const float w = z * z;
	const float s1 = z * (3.3333334327E-1F + w * (1.4285714924E-1F + w * (9.0908870101E-2F + w * (6.6610731184E-2F + w * (4.9768779427E-2F + w * 1.6285819933E-2F)))));
	const float s2 = w * (-2.0000000298E-1F + w * (-1.1111110449E-1F + w * (-7.6918758452E-2F + w * (-5.8335702866E-2F + w * -3.6531571299E-2F))));
	if (idx < 0) { return x - x * (s1 + s2); }
	z = atanhif[idx] - ((x * (s1 + s2) - atanlof[idx]) - x);
	return (hx < 0) ? -z : z;
#   endif
}


/** Return the arc-tangent of a double */
LIB_FUNC MATH_FUNC double atan(const double num) {
#   ifdef ARCHX86
	double ret;
	asm ("fpatan;" : "=t"(ret) : "0"(num), "u"(1.0) : "st(1)");
	return ret;
#   else
	double x = num;
	int32_t hx, idx;
	GET_HIGH_SWORD(hx, x);
	const int32_t ix = hx & 0x7fffffff;
	if (ix >= 0x44100000) {
		uint32_t low;
		GET_LOW_WORD(low, x);
		if (ix > 0x7ff00000 || (ix == 0x7ff00000 && (low != 0))) { return x + x; }
		else if (hx > 0) { return atanhi[3] + atanlo[3]; }
		else { return -atanhi[3] - atanlo[3]; }
	}
	if (ix < 0x3fdc0000) {
		if (ix < 0x3e200000 && (HUGE + x > 1.0)) { return x; }
		idx = -1;
	} else {
		x = fabs(x);
		if (ix < 0x3ff30000) {
			if (ix < 0x3fe60000) {
				idx = 0;
				x = (2.0 * x - 1.0) / (2.0 + x);
			} else {
				idx = 1;
				x = (x - 1.0) / (x + 1.0);
			}
		} else {
			if (ix < 0x40038000) {
				idx = 2;
				x = (x - 1.5) / (1.0 + 1.5 * x);
			} else {
				idx = 3;
				x = -1.0 / x;
			}
		}
	}
	double z = x * x;
	const double w = z * z;
	const double s1 = z * (atan_aT[0] + w * (atan_aT[2] + w * (atan_aT[4] + w * (atan_aT[6] + w * (atan_aT[8] + w * atan_aT[10])))));
	const double s2 = w * (atan_aT[1] + w * (atan_aT[3] + w * (atan_aT[5] + w * (atan_aT[7] + w * atan_aT[9]))));
	if (idx < 0) { return x - x * (s1 + s2); }
	z = atanhi[idx] - ((x * (s1 + s2) - atanlo[idx]) - x);
	return (hx < 0) ? -z : z;
#   endif
}


#if SUPPORTS_LONG_DOUBLE
/** Return the arc-tangent of a long double */
LIB_FUNC MATH_FUNC long double atanl(const long double num) {
	return (long double)atan((double)num);
}
#endif


/** Return the angle between the X-axis and the line created by points x and y (each as a float) */
LIB_FUNC MATH_FUNC float atan2f(const float y, const float x) {
#   ifdef ARCHX86
	float ret;
	asm ("fpatan;" : "=t"(ret) : "0"(x), "u"(y) : "st(1)");
	return ret;
#   else
	return __ieee754_atan2f(y, x);
#   endif
}


/** Return the angle between the X-axis and the line created by points x and y (each as a double) */
LIB_FUNC MATH_FUNC double atan2(const double y, const double x) {
#   ifdef ARCHX86
	double ret;
	asm ("fpatan;" : "=t"(ret) : "0"(x), "u"(y) : "st(1)");
	return ret;
#   else
	return __ieee754_atan2(y, x);
#   endif
}


/** Return the angle between the X-axis and the line created by points x and y (each as a float) */
LIB_FUNC MATH_FUNC double ATAN2(const double y, const double x) {
	if (PREDICT_UNLIKELY(__isnan(x) || __isnan(y))) { return NAN; }
	else if (__isinf(y)) {
		if (__isinf(x)) {
			if (copysign(1.0, x) == 1.0) { return copysign(0.25 * PI, y); }  // atan2(+-inf, +inf) == +-pi/4
			return copysign(0.75 * PI, y);  // atan2(+-inf, -inf) == +-pi*3/4
		}
		return copysign(0.5 * PI, y);  // atan2(+-inf, x) == +-pi/2 for finite x
	}
	if (__isinf(x) || y == 0.0) {
		if (copysign(1.0, x) == 1.0) { return copysign(0.0, y); }  // atan2(+-y, +inf) = atan2(+-0, +x) = +-0.0
		return copysign(PI, y);  // atan2(+-y, -inf) = atan2(+-0., -x) = +-pi
	}
	return atan2(y, x);
}


/** Return the area hyperbolic tangent as a float */
LIB_FUNC MATH_FUNC float atanhf(const float x) {
#if IS_LIBM_POSIX
	return __ieee754_atanhf(x);
#else
	const float z = __ieee754_atanhf(x);
	if (__isnanf(x)) { return z; }
	const float y = fabsf(x);
	if (y >= 1.0F) {
		exc.name = "atanhf";
		exc.err = EDOM;
		exc.arg1 = exc.arg2 = (double)x;
		if (y > 1.0F) {
			exc.type = DOMAIN;
			exc.retval = 0.0 / 0.0;
		} else {
			exc.type = SING;
			exc.retval = x / 0.0F;
		}
		matherr(&exc);
		return (float)exc.retval;
	} else { return z; }
#endif
}


/** Return the area hyperbolic tangent as a double */
LIB_FUNC MATH_FUNC double atanh(const double x) {
#if IS_LIBM_POSIX
	return __ieee754_atanh(x);
#else
	const double z = __ieee754_atanh(x);
	if (__isnan(x)) { return z; }
	const double y = fabs(x);
	if (y >= 1.0) {
		exc.name = "atanh";
		exc.err = EDOM;
		exc.arg1 = exc.arg2 = x;
		if (y > 1.0) {
			exc.type = DOMAIN;
			exc.retval = 0.0 / 0.0;
		} else {
			exc.type = SING;
			exc.retval = x / 0.0;
		}
		matherr(&exc);
		return exc.retval;
	} else { return z; }
#endif
}


#if SUPPORTS_LONG_DOUBLE
/** Return the area hyperbolic tangent as a long double */
LIB_FUNC MATH_FUNC long double atanhl(const long double x) {
	return (long double)atanh((double)x);
}
#endif


/** Return the hyperbolic tangent */
LIB_FUNC MATH_FUNC float tanhf(const float x) {
	float t, z;
	int32_t jx;
	GET_FLOAT_WORD(jx, x);
	const int32_t ix = jx & 0x7fffffff;
	if (!FLT_UWORD_IS_FINITE(ix)) {
		if (jx >= 0) { return 1.0F / x + 1.0F; }
		else { return 1.0F / x - 1.0F; }
	} else if (ix < 0x41b00000) {
		if (ix < 0x24000000) { return x * (1.0F + x); }
		else if (ix >= 0x3f800000) {
			t = expm1f(2.0F * fabsf(x));
			z = 1.0F - 2.0F / (t + 2.0F);
		} else {
			t = expm1f(-2.0F * fabsf(x));
			z = -t / (t + 2.0F);
		}
	} else { z = 1.0F - TINYF; }
	return (jx >= 0) ? z : -z;
}


/** Return the hyperbolic tangent */
LIB_FUNC MATH_FUNC double tanh(const double x) {
	double t, z;
	int32_t jx;
	GET_HIGH_SWORD(jx, x);
	const int32_t ix = jx & 0x7fffffff;
	if (ix >= 0x7ff00000) {
		if (jx >= 0) { return 1.0 / x + 1.0; }
		else { return 1.0 / x - 1.0; }
	} else if (ix < 0x40360000) {
		if (ix < 0x3c800000) { return x * (1.0 + x); }
		else if (ix >= 0x3ff00000) {
			t = expm1(2.0 * fabs(x));
			z = 1.0 - 2.0 / (t + 2.0);
		} else {
			t = expm1(-2.0 * fabs(x));
			z = -t / (t + 2.0);
		}
	} else { z = 1.0 - TINY; }
	return (jx >= 0) ? z : -z;
}


#if SUPPORTS_LONG_DOUBLE
/** Return the hyperbolic tangent */
LIB_FUNC MATH_FUNC long double tanhl(const long double x) {
	return (long double)tanh((double)x);
}
#endif


/** Return the Chord */
LIB_FUNC MATH_FUNC float crdf(const float radians) {
	return (2.0F * sinf(radians / 2.0F));
}


/** Return the Chord */
LIB_FUNC MATH_FUNC double crd(const double radians) {
	return (2.0 * sin(radians / 2.0));
}


#if SUPPORTS_LONG_DOUBLE
/** Return the Chord */
LIB_FUNC MATH_FUNC long double crdl(const long double radians) {
	return (2.0L * sinl(radians / 2.0L));
}
#endif


/** Return the hypotenuse */
LIB_FUNC MATH_FUNC float __ieee754_hypotf(const float x, const float y) {
	int32_t ha, hb;
	GET_FLOAT_WORD(ha, x);
	ha &= 0x7fffffff;
	GET_FLOAT_WORD(hb, y);
	hb &= 0x7fffffff;
	if (ha == 0x7f800000) { return fabsf(x); }
	else if (hb == 0x7f800000) { return fabsf(y); }
	else if (ha > 0x7f800000 || hb > 0x7f800000) { return fabsf(x) * fabsf(y); }
	else if (ha == 0) { return fabsf(y); }
	else if (hb == 0) { return fabsf(x); }
	const double d_x = (double)x, d_y = (double)y;
	return (float)__ieee754_sqrt(d_x * d_x + d_y * d_y);
}
#define __hypotf_finite(x, y)   __ieee754_hypotf((x), (y))


/** Return the hypotenuse */
LIB_FUNC MATH_FUNC double __ieee754_hypot(const double x, const double y) {
	double a, b, w;
	int32_t j, k, ha, hb;
	GET_HIGH_SWORD(ha, x);
	ha &= 0x7fffffff;
	GET_HIGH_SWORD(hb, y);
	hb &= 0x7fffffff;
	if (hb > ha) {
		a = y;
		b = x;
		j = ha;
		ha = hb;
		hb = j;
	} else {
		a = x;
		b = y;
	}
	SET_HIGH_WORD(a, ha);
	SET_HIGH_WORD(b, hb);
	if ((ha - hb) > 0x3c00000) { return a + b; }
	k = 0;
	if (PREDICT_UNLIKELY(ha > 0x5f300000)) {
		if (ha >= 0x7ff00000) {
			uint32_t low;
			w = a + b;
			GET_LOW_WORD(low, a);
			if (((ha & 0xfffff) | low) == 0) { w = a; }
			GET_LOW_WORD(low, b);
			if (((uint32_t)(hb ^ 0x7ff00000) | low) == 0) { w = b; }
			return w;
		}
		ha -= 0x25800000;
		hb -= 0x25800000;
		k += 600;
		SET_HIGH_WORD(a, ha);
		SET_HIGH_WORD(b, hb);
	}
	double t1, y1, y2;
	if (PREDICT_UNLIKELY(hb < 0x23d00000)) {
		if (hb <= 0xfffff) {
			uint32_t low;
			GET_LOW_WORD(low, b);
			if (((uint32_t)hb | low) == 0) { return a; }
			t1 = 0;
			SET_HIGH_WORD(t1, 0x7fd00000);
			b *= t1;
			a *= t1;
			k -= 1022;
			GET_HIGH_SWORD(ha, a);
			GET_HIGH_SWORD(hb, b);
			if (hb > ha) {
				t1 = a;
				a = b;
				b = t1;
				j = ha;
				ha = hb;
				hb = j;
			}
		} else {
			ha += 0x25800000;
			hb += 0x25800000;
			k -= 600;
			SET_HIGH_WORD(a, ha);
			SET_HIGH_WORD(b, hb);
		}
	}
	w = a - b;
	double t2;
	if (w > b) {
		t1 = 0;
		SET_HIGH_WORD(t1, ha);
		t2 = a - t1;
		w = __ieee754_sqrt(t1 * t1 - (b * (-b) - t2 * (a + t1)));
	} else {
		a += a;
		y1 = 0;
		SET_HIGH_WORD(y1, hb);
		y2 = b - y1;
		t1 = 0;
		SET_HIGH_WORD(t1, (ha + 0x100000));
		t2 = a - t1;
		w = __ieee754_sqrt(t1 * y1 - (w * (-w) - (t1 * y2 + t2 * b)));
	}
	if (k != 0) {
		uint32_t high;
		t1 = 1.0;
		GET_HIGH_WORD(high, t1);
		SET_HIGH_WORD(t1, (high + (uint32_t)(k << 20)));
		w *= t1;
		math_check_force_underflow_nonneg(w);
		return w;
	} else { return w; }
}
#define __hypot_finite(x, y)   __ieee754_hypot((x), (y))


#if IS_LDBL_X87
/** Return the hypotenuse */
LIB_FUNC MATH_FUNC long double __ieee754_hypotl(const long double x, const long double y) {
	long double a, b, w;
	uint32_t j, k, ea, eb;
	GET_LDOUBLE_EXP(ea, x);
	ea &= 0x7fff;
	GET_LDOUBLE_EXP(eb, y);
	eb &= 0x7fff;
	if (eb > ea) { a = y; b = x; j = ea; ea = eb; eb = j; }
	else {a = x; b = y;}
	SET_LDOUBLE_EXP(a, ea);
	SET_LDOUBLE_EXP(b, eb);
	if ((ea - eb) > 0x46) { return a + b; }
	k = 0;
	if (PREDICT_UNLIKELY(ea > 0x5f3f)) {
		if (ea == 0x7fff) {
			uint32_t exp, high, low;
			w = a + b;
			GET_LDOUBLE_WORDS(exp, high, low, a);
			if (((high & 0x7fffffff) | low) == 0) { w = a; }
			GET_LDOUBLE_WORDS(exp, high, low, b);
			if (((eb ^ 0x7fff) | (high & 0x7fffffff) | low) == 0) { w = b; }
			return w;
		}
		ea -= 0x2580;
		eb -= 0x2580;
		k += 9600;
		SET_LDOUBLE_EXP(a, ea);
		SET_LDOUBLE_EXP(b, eb);
	}
	long double t1, t2, y1, y2;
	if (PREDICT_UNLIKELY(eb < 0x20bf)) {
		if (eb == 0) {
			uint32_t exp, high, low;
			GET_LDOUBLE_WORDS(exp, high, low, b);
			if ((high | low) == 0) { return a; }
			SET_LDOUBLE_WORDS(t1, 0x7ffd, 0x80000000, 0);
			b *= t1;
			a *= t1;
			k -= 16382;
			GET_LDOUBLE_EXP(ea, a);
			GET_LDOUBLE_EXP(eb, b);
			if (eb > ea) {
				t1 = a;
				a = b;
				b = t1;
				j = ea;
				ea = eb;
				eb = j;
			}
		} else {
			ea += 0x2580;
			eb += 0x2580;
			k -= 9600;
			SET_LDOUBLE_EXP(a, ea);
			SET_LDOUBLE_EXP(b, eb);
		}
	}
	w = a - b;
	if (w > b) {
		uint32_t high;
		GET_LDOUBLE_MSW(high, a);
		SET_LDOUBLE_WORDS(t1, ea, high, 0);
		t2 = a - t1;
		w = __ieee754_sqrtl(t1 * t1 - (b * (-b) - t2 * (a + t1)));
	} else {
		uint32_t high;
		GET_LDOUBLE_MSW(high, b);
		a += a;
		SET_LDOUBLE_WORDS(y1, eb, high, 0);
		y2 = b - y1;
		GET_LDOUBLE_MSW(high, a);
		SET_LDOUBLE_WORDS(t1, ea + 1, high, 0);
		t2 = a - t1;
		w = __ieee754_sqrtl(t1 * y1 - (w * (-w) - (t1 * y2 + t2 * b)));
	}
	if (k != 0) {
		uint32_t exp;
		t1 = 1.0;
		GET_LDOUBLE_EXP(exp, t1);
		SET_LDOUBLE_EXP(t1, exp + k);
		w *= t1;
		math_check_force_underflow_nonneg(w);
		return w;
	} else { return w; }
}
#   define __hypotl_finite(x, y)   __ieee754_hypotl((x), (y))
#elif LDBL_EQ_FLOAT128
/** Return the hypotenuse */
LIB_FUNC MATH_FUNC long double __ieee754_hypotl(const long double x, const long double y) {
	long double a, b, y1, y2, w;
	int64_t j, k, ha, hb;
	GET_LDOUBLE_MSW64S(ha, x);
	ha &= 0x7fffffffffffffffLL;
	GET_LDOUBLE_MSW64S(hb, y);
	hb &= 0x7fffffffffffffffLL;
	if (hb > ha) {a = y; b = x; j = ha; ha = hb; hb = j;}
	else {a = x; b = y;}
	SET_LDOUBLE_MSW64(a, ha);
	SET_LDOUBLE_MSW64(b, hb);
	if ((ha - hb) > 0x78000000000000LL) { return a + b; }
	k = 0;
	if (ha > 0x5f3f000000000000LL) {
		if (ha >= 0x7fff000000000000LL) {
			uint64_t low;
			w = a + b;
			GET_LDOUBLE_LSW64(low, a);
			if (((ha & 0xffffffffffffLL) | low) == 0) { w = a; }
			GET_LDOUBLE_LSW64(low, b);
			if (((uint64_t)(hb ^ 0x7fff000000000000LL) | low) == 0) { w = b; }
			return w;
		}
		ha -= 0x2580000000000000LL;
		hb -= 0x2580000000000000LL;
		k += 9600;
		SET_LDOUBLE_MSW64(a, ha);
		SET_LDOUBLE_MSW64(b, hb);
	}
	long double t1;
	if (hb < 0x20bf000000000000LL) {
		if (hb <= 0xffffffffffffLL) {
			uint64_t low;
			GET_LDOUBLE_LSW64(low, b);
			if (((uint64_t)hb | low) == 0) { return a; }
			t1 = 0;
			SET_LDOUBLE_MSW64(t1, 0x7ffd000000000000LL);
			b *= t1;
			a *= t1;
			k -= 16382;
			GET_LDOUBLE_MSW64S(ha, a);
			GET_LDOUBLE_MSW64S(hb, b);
			if (hb > ha) {
				t1 = a;
				a = b;
				b = t1;
				j = ha;
				ha = hb;
				hb = j;
			}
		} else {
			ha += 0x2580000000000000LL;
			hb += 0x2580000000000000LL;
			k -= 9600;
			SET_LDOUBLE_MSW64(a, ha);
			SET_LDOUBLE_MSW64(b, hb);
		}
	}
	w = a - b;
	long double t2;
	if (w > b) {
		t1 = 0;
		SET_LDOUBLE_MSW64(t1, ha);
		t2 = a - t1;
		w = __ieee754_sqrtl(t1 * t1 - (b * (-b) - t2 * (a + t1)));
	} else {
		a += a;
		y1 = 0;
		SET_LDOUBLE_MSW64(y1, hb);
		y2 = b - y1;
		t1 = 0;
		SET_LDOUBLE_MSW64(t1, ha + 0x1000000000000LL);
		t2 = a - t1;
		w = __ieee754_sqrtl(t1 * y1 - (w * (-w) - (t1 * y2 + t2 * b)));
	}
	if (k != 0) {
		uint64_t high;
		t1 = 1.0L;
		GET_LDOUBLE_MSW64(high, t1);
		SET_LDOUBLE_MSW64(t1, (high + (uint64_t)(k << 48)));
		w *= t1;
		math_check_force_underflow_nonneg(w);
		return w;
	} else { return w; }
}
#   define __hypotl_finite(x, y)   __ieee754_hypotl((x), (y))
#endif


/** Return the hypotenuse */
LIB_FUNC MATH_FUNC float __hypotf(const float x, const float y) {
	return __ieee754_hypotf(x, y);
}
#define hypotf(x, y)   __hypotf((x), (y))


/** Return the hypotenuse */
LIB_FUNC MATH_FUNC double __hypot(const double x, const double y) {
	return __ieee754_hypot(x, y);
}
#define hypot(x, y)   __hypot((x), (y))


#if SUPPORTS_LONG_DOUBLE
/** Return the hypotenuse */
LIB_FUNC MATH_FUNC long double __hypotl(const long double x, const long double y) {
	return __ieee754_hypotl(x, y);
}
#   define hypotl(x, y)   __hypotl((x), (y))
#endif


// EXTRA TRIGONOMETRY FUNCTIONS (FLOATS)

/** Return the Arc-Cotangent (acot(x) || arccot(x) == atan(1/x)) */
LIB_FUNC MATH_FUNC float acotf(const float radians) {
	return atanf(1.0F / radians);
}


/** Return the Arc-Cotangent (acot(x) || arccot(x) == atan(1/x)) */
LIB_FUNC MATH_FUNC float arccotf(const float radians) {
	return atanf(1.0F / radians);
}


/** Return the Area Hyperbolic Cotangent (acoth(x) || arcoth(x) == atanh(1/x)) */
LIB_FUNC MATH_FUNC float acothf(const float radians) {
	return atanhf(1.0F / radians);
}


/** Return the Area Hyperbolic Cotangent (acoth(x) || arcoth(x) == atanh(1/x)) */
LIB_FUNC MATH_FUNC float arcothf(const float radians) {
	return atanhf(1.0F / radians);
}


/** Return the Hyperbolic Cotangent (coth(x) == 1/tanh(x)) */
LIB_FUNC MATH_FUNC float cothf(const float radians) {
	return (1.0F / tanhf(radians));
}


/** Return the Cotangent (cot(x) == 1/tan(x)) */
LIB_FUNC MATH_FUNC float cotf(const float radians) {
	return (1.0F / tanf(radians));
}


/** Return the Arc-Cosecant (acsc(x) || arccsc(x) == asin(1/x)) */
LIB_FUNC MATH_FUNC float acscf(const float radians) {
	return asinf(1.0F / radians);
}


/** Return the Arc-Cosecant (acsc(x) || arccsc(x) == asin(1/x)) */
LIB_FUNC MATH_FUNC float arccscf(const float radians) {
	return asinf(1.0F / radians);
}


/** Return the Area Hyperbolic Cosecant (acsch(x) || arcsch(x) == asinh(1/x)) */
LIB_FUNC MATH_FUNC float acschf(const float radians) {
	return asinhf(1.0F / radians);
}


/** Return the Area Hyperbolic Cosecant (acsc(x) || arcsch(x) == asinh(1/x)) */
LIB_FUNC MATH_FUNC float arcschf(const float radians) {
	return asinhf(1.0F / radians);
}


/** Return the Hyperbolic Cosecant (csch(x) == 1/sinh(x)) */
LIB_FUNC MATH_FUNC float cschf(const float radians) {
	return (1.0F / sinhf(radians));
}


/** Return the Cosecant (csc(x) == 1/sin(x)) */
LIB_FUNC MATH_FUNC float cscf(const float radians) {
	return (1.0F / sinf(radians));
}


/** Return the Arc-Secant (asec(x) || arcsec(x) == acos(1/x)) */
LIB_FUNC MATH_FUNC float asecf(const float radians) {
	return acosf(1.0F / radians);
}


/** Return the Arc-Secant (asec(x) || arcsec(x) == acos(1/x)) */
LIB_FUNC MATH_FUNC float arcsecf(const float radians) {
	return acosf(1.0F / radians);
}


/** Return the Area Hyperbolic Secant (asech(x) || asech(x) == acosh(1/x)) */
LIB_FUNC MATH_FUNC float asechf(const float radians) {
	return acoshf(1.0F / radians);
}


/** Return the Area Hyperbolic Secant (asech(x) || arsech(x) == acosh(1/x)) */
LIB_FUNC MATH_FUNC float arsechf(const float radians) {
	return acoshf(1.0F / radians);
}


/** Return the Hyperbolic Secant (sech(x) == 1/cosh(x)) */
LIB_FUNC MATH_FUNC float sechf(const float radians) {
	return (1.0F / coshf(radians));
}


/** Return the Secant (sec(x) == 1/cos(x)) */
LIB_FUNC MATH_FUNC float secf(const float radians) {
	return (1.0F / cosf(radians));
}


/** Return the Arc-Versed Sine (arcversin(x) == 1 - acos(x)) */
LIB_FUNC MATH_FUNC float arcversinf(const float radians) {
	return (1.0F - acosf(radians));
}


/** Return the Hyperbolic Area-Versed Sine (arversinh(x) == 1 - acosh(x)) */
LIB_FUNC MATH_FUNC float arversinhf(const float radians) {
	return (1.0F - acoshf(radians));
}


/** Return the Hyperbolic Versed Sine (versinh(x) == 1 - cosh(x)) */
LIB_FUNC MATH_FUNC float versinhf(const float radians) {
	return (1.0F - coshf(radians));
}


/** Return the Versed Sine (versin(x) == 1 - cos(x)) */
LIB_FUNC MATH_FUNC float versinf(const float radians) {
	return (1.0F - cosf(radians));
}


/** Return the Arc-Versed Cosine (arcvercos(x) == 1 - asin(x)) */
LIB_FUNC MATH_FUNC float arcvercosf(const float radians) {
	return (1.0F - asinf(radians));
}


/** Return the Hyperbolic Area-Versed Cosine (arvercosh(x) == 1 - asinh(x)) */
LIB_FUNC MATH_FUNC float arcvercoshf(const float radians) {
	return (1.0F - asinhf(radians));
}


/** Return the Hyperbolic Versed Cosine (vercosh(x) == 1 - sinh(x)) */
LIB_FUNC MATH_FUNC float vercoshf(const float radians) {
	return (1.0F - sinhf(radians));
}


/** Return the Versed Cosine (vercos(x) == 1 - sin(x)) */
LIB_FUNC MATH_FUNC float vercosf(const float radians) {
	return (1.0F - sinf(radians));
}


/** Return the Haversine (haversin(x) == 0.5*(1 - cos(x))) */
LIB_FUNC MATH_FUNC float haversinf(const float radians) {
	return (0.5F * (1.0F - cosf(radians)));
}


/** Return the Hacoversine (hacoversin(x) == 0.5*(1 - sin(x))) */
LIB_FUNC MATH_FUNC float hacoversinf(const float radians) {
	return (0.5F * (1.0F - sinf(radians)));
}


// EXTRA TRIGONOMETRY FUNCTIONS (DOUBLES)

/** Return the Arc-Cotangent (acot(x) || arccot(x) == atan(1/x)) */
LIB_FUNC MATH_FUNC double acot(const double radians) {
	return atan(1.0 / radians);
}


/** Return the Arc-Cotangent (acot(x) || arccot(x) == atan(1/x)) */
LIB_FUNC MATH_FUNC double arccot(const double radians) {
	return atan(1.0 / radians);
}


/** Return the Area Hyperbolic Cotangent (acoth(x) || arcoth(x) == atanh(1/x)) */
LIB_FUNC MATH_FUNC double acoth(const double radians) {
	return atanh(1.0 / radians);
}


/** Return the Area Hyperbolic Cotangent (acoth(x) || arcoth(x) == atanh(1/x)) */
LIB_FUNC MATH_FUNC double arcoth(const double radians) {
	return atanh(1.0 / radians);
}


/** Return the Hyperbolic Cotangent (coth(x) == 1/tanh(x)) */
LIB_FUNC MATH_FUNC double coth(const double radians) {
	return (1.0 / tanh(radians));
}


/** Return the Cotangent (cot(x) == 1/tan(x)) */
LIB_FUNC MATH_FUNC double cot(const double radians) {
	return (1.0 / tan(radians));
}


/** Return the Arc-Cosecant (acsc(x) || arccsc(x) == asin(1/x)) */
LIB_FUNC MATH_FUNC double acsc(const double radians) {
	return asin(1.0 / radians);
}


/** Return the Arc-Cosecant (acsc(x) || arccsc(x) == asin(1/x)) */
LIB_FUNC MATH_FUNC double arccsc(const double radians) {
	return asin(1.0 / radians);
}


/** Return the Area Hyperbolic Cosecant (acsch(x) || arcsch(x) == asinh(1/x)) */
LIB_FUNC MATH_FUNC double acsch(const double radians) {
	return asinh(1.0 / radians);
}


/** Return the Area Hyperbolic Cosecant (acsc(x) || arcsch(x) == asinh(1/x)) */
LIB_FUNC MATH_FUNC double arcsch(const double radians) {
	return asinh(1.0 / radians);
}


/** Return the Hyperbolic Cosecant (csch(x) == 1/sinh(x)) */
LIB_FUNC MATH_FUNC double csch(const double radians) {
	return (1.0 / sinh(radians));
}


/** Return the Cosecant (csc(x) == 1/sin(x)) */
LIB_FUNC MATH_FUNC double csc(const double radians) {
	return (1.0 / sin(radians));
}


/** Return the Arc-Secant (asec(x) || arcsec(x) == acos(1/x)) */
LIB_FUNC MATH_FUNC double asec(const double radians) {
	return acos(1.0 / radians);
}


/** Return the Arc-Secant (asec(x) || arcsec(x) == acos(1/x)) */
LIB_FUNC MATH_FUNC double arcsec(const double radians) {
	return acos(1.0 / radians);
}


/** Return the Area Hyperbolic Secant (asech(x) || arsech(x) == acosh(1/x)) */
LIB_FUNC MATH_FUNC double asech(const double radians) {
	return acosh(1.0 / radians);
}


/** Return the Area Hyperbolic Secant (asech(x) || arsech(x) == acosh(1/x)) */
LIB_FUNC MATH_FUNC double arsech(const double radians) {
	return acosh(1.0 / radians);
}


/** Return the Hyperbolic Secant (sech(x) == 1/cosh(x)) */
LIB_FUNC MATH_FUNC double sech(const double radians) {
	return (1.0 / cosh(radians));
}


/** Return the Secant (sec(x) == 1/cos(x)) */
LIB_FUNC MATH_FUNC double sec(const double radians) {
	return (1.0 / cos(radians));
}


/** Return the Arc-Versed Sine (arcversin(x) == 1 - acos(x)) */
LIB_FUNC MATH_FUNC double arcversin(const double radians) {
	return (1.0 - acos(radians));
}


/** Return the Area Hyperbolic Versed Sine (arversinh(x) == 1 - acosh(x)) */
LIB_FUNC MATH_FUNC double arversinh(const double radians) {
	return (1.0 - acosh(radians));
}


/** Return the Hyperbolic Versed Sine (versinh(x) == 1 - cosh(x)) */
LIB_FUNC MATH_FUNC double versinh(const double radians) {
	return (1.0 - cosh(radians));
}


/** Return the Versed Sine (versin(x) == 1 - cos(x)) */
LIB_FUNC MATH_FUNC double versin(const double radians) {
	return (1.0 - cos(radians));
}


/** Return the Arc-Versed Cosine (arcvercos(x) == 1 - asin(x)) */
LIB_FUNC MATH_FUNC double arcvercos(const double radians) {
	return (1.0 - asin(radians));
}


/** Return the Area Hyperbolic Versed Cosine (arvercosh(x) == 1 - asinh(x)) */
LIB_FUNC MATH_FUNC double arvercosh(const double radians) {
	return (1.0 - asinh(radians));
}


/** Return the Hyperbolic Versed Cosine (vercosh(x) == 1 - sinh(x)) */
LIB_FUNC MATH_FUNC double vercosh(const double radians) {
	return (1.0 - sinh(radians));
}


/** Return the Versed Cosine (vercos(x) == 1 - sin(x)) */
LIB_FUNC MATH_FUNC double vercos(const double radians) {
	return (1.0 - sin(radians));
}


/** Return the Haversine (haversin(x) == 0.5*(1 - cos(x))) */
LIB_FUNC MATH_FUNC double haversin(const double radians) {
	return (0.5 * (1.0 - cos(radians)));
}


/** Return the Hacoversine (hacoversin(x) == 0.5*(1 - sin(x))) */
LIB_FUNC MATH_FUNC double hacoversin(const double radians) {
	return (0.5 * (1.0 - sin(radians)));
}


// EXTRA TRIGONOMETRY FUNCTIONS (LONG DOUBLES)

#if SUPPORTS_LONG_DOUBLE
/** Return the Arc-Cotangent (acot(x) || arccot(x) == atan(1/x)) */
LIB_FUNC MATH_FUNC long double acotl(const long double radians) {
	return atanl(1.0L / radians);
}


/** Return the Arc-Cotangent (acot(x) || arccot(x) == atan(1/x)) */
LIB_FUNC MATH_FUNC long double arccotl(const long double radians) {
	return atanl(1.0L / radians);
}


/** Return the Area Hyperbolic Cotangent (acoth(x) || arcoth(x) == atanh(1/x)) */
LIB_FUNC MATH_FUNC long double acothl(const long double radians) {
	return atanhl(1.0L / radians);
}


/** Return the Area Hyperbolic Cotangent (acoth(x) || arcoth(x) == atanh(1/x)) */
LIB_FUNC MATH_FUNC long double arcothl(const long double radians) {
	return atanhl(1.0L / radians);
}


/** Return the Hyperbolic Cotangent (coth(x) == 1/tanh(x)) */
LIB_FUNC MATH_FUNC long double cothl(const long double radians) {
	return (1.0L / tanhl(radians));
}


/** Return the Cotangent (cot(x) == 1/tan(x)) */
LIB_FUNC MATH_FUNC long double cotl(const long double radians) {
	return (1.0L / tanl(radians));
}


/** Return the Arc-Cosecant (acsc(x) || arccsc(x) == asin(1/x)) */
LIB_FUNC MATH_FUNC long double acscl(const long double radians) {
	return asinl(1.0L / radians);
}


/** Return the Arc-Cosecant (acsc(x) || arccsc(x) == asin(1/x)) */
LIB_FUNC MATH_FUNC long double arccscl(const long double radians) {
	return asinl(1.0L / radians);
}


/** Return the Area Hyperbolic Cosecant (acsch(x) || arcsch(x) == asinh(1/x)) */
LIB_FUNC MATH_FUNC long double acschl(const long double radians) {
	return asinhl(1.0L / radians);
}


/** Return the Area Hyperbolic Cosecant (acsc(x) || arcsch(x) == asinh(1/x)) */
LIB_FUNC MATH_FUNC long double arcschl(const long double radians) {
	return asinhl(1.0L / radians);
}


/** Return the Hyperbolic Cosecant (csch(x) == 1/sinh(x)) */
LIB_FUNC MATH_FUNC long double cschl(const long double radians) {
	return (1.0L / sinhl(radians));
}


/** Return the Cosecant (csc(x) == 1/sin(x)) */
LIB_FUNC MATH_FUNC long double cscl(const long double radians) {
	return (1.0L / sinl(radians));
}


/** Return the Arc-Secant (asec(x) || arcsec(x) == acos(1/x)) */
LIB_FUNC MATH_FUNC long double asecl(const long double radians) {
	return acosl(1.0L / radians);
}


/** Return the Arc-Secant (asec(x) || arcsec(x) == acos(1/x)) */
LIB_FUNC MATH_FUNC long double arcsecl(const long double radians) {
	return acosl(1.0L / radians);
}


/** Return the Area Hyperbolic Secant (asech(x) || arsech(x) == acosh(1/x)) */
LIB_FUNC MATH_FUNC long double asechl(const long double radians) {
	return acoshl(1.0L / radians);
}


/** Return the Area Hyperbolic Secant (asech(x) || arsech(x) == acosh(1/x)) */
LIB_FUNC MATH_FUNC long double arcsechl(const long double radians) {
	return acoshl(1.0L / radians);
}


/** Return the Hyperbolic Secant (sech(x) == 1/cosh(x)) */
LIB_FUNC MATH_FUNC long double sechl(const long double radians) {
	return (1.0L / coshl(radians));
}


/** Return the Secant (sec(x) == 1/cos(x)) */
LIB_FUNC MATH_FUNC long double secl(const long double radians) {
	return (1.0L / cosl(radians));
}


/** Return the Arc-Versed Sine (arcversin(x) == 1 - acos(x)) */
LIB_FUNC MATH_FUNC long double arcversinl(const long double radians) {
	return (1.0L - acosl(radians));
}


/** Return the Hyperbolic Area-Versed Sine (arversinh(x) == 1 - acosh(x)) */
LIB_FUNC MATH_FUNC long double arversinhl(const long double radians) {
	return (1.0L - acoshl(radians));
}


/** Return the Hyperbolic Versed Sine (versinh(x) == 1 - cosh(x)) */
LIB_FUNC MATH_FUNC long double versinhl(const long double radians) {
	return (1.0L - coshl(radians));
}


/** Return the Versed Sine (versin(x) == 1 - cos(x)) */
LIB_FUNC MATH_FUNC long double versinl(const long double radians) {
	return (1.0L - cosl(radians));
}


/** Return the Arc-Versed Cosine (arcvercos(x) == 1 - asin(x)) */
LIB_FUNC MATH_FUNC long double arcvercosl(const long double radians) {
	return (1.0L - asinl(radians));
}


/** Return the Hyperbolic Area-Versed Cosine (arvercosh(x) == 1 - asinh(x)) */
LIB_FUNC MATH_FUNC long double arvercoshl(const long double radians) {
	return (1.0L - asinhl(radians));
}


/** Return the Hyperbolic Versed Cosine (vercosh(x) == 1 - sinh(x)) */
LIB_FUNC MATH_FUNC long double vercoshl(const long double radians) {
	return (1.0L - sinhl(radians));
}


/** Return the Versed Cosine (vercos(x) == 1 - sin(x)) */
LIB_FUNC MATH_FUNC long double vercosl(const long double radians) {
	return (1.0L - sinl(radians));
}


/** Return the Haversine (haversin(x) == 0.5*(1 - cos(x))) */
LIB_FUNC MATH_FUNC long double haversinl(const long double radians) {
	return (0.5L * (1.0L - cosl(radians)));
}


/** Return the Hacoversine (hacoversin(x) == 0.5*(1 - sin(x))) */
LIB_FUNC MATH_FUNC long double hacoversinl(const long double radians) {
	return (0.5L * (1.0L - sinl(radians)));
}
#endif


// EXTERNAL TRIGONOMETRY (FLOATS)

/** Return the Arc-External Cotangent (arcexcot(x) == atan(1/(x+1))) */
LIB_FUNC MATH_FUNC float arcexcotf(const float radians) {
	return atanf(1.0F / (radians + 1.0F));
}


/** Return the Hyperbolic Area-External Cotangent [arexcoth(x) == (1/atanh(x)-1)] */
LIB_FUNC MATH_FUNC float arexcothf(const float radians) {
	return ((1.0F / atanhf(radians)) - 1.0F);
}


/** Return the External Hyperbolic Cotangent [excoth(x) == (1/tanh(x)-1)] */
LIB_FUNC MATH_FUNC float excothf(const float radians) {
	return ((1.0F / tanhf(radians)) - 1.0F);
}


/** Return the External Cotangent [excot(x) == (1/tan(x))-1 == cot(x)-1] */
LIB_FUNC MATH_FUNC float excotf(const float radians) {
	return ((1.0F / tanf(radians)) - 1.0F);
}


/** Return the Arc-External Cosecant (arcexcsc(x) == asin(1/(x+1))) */
LIB_FUNC MATH_FUNC float arcexcscf(const float radians) {
	return asinf(1.0F / (radians + 1.0F));
}


/** Return the Hyperbolic Area-External Cosecant [arexcsch(x) == (1/asinh(x)-1)] */
LIB_FUNC MATH_FUNC float arexcschf(const float radians) {
	return ((1.0F / asinhf(radians)) - 1.0F);
}


/** Return the External Hyperbolic Cosecant [excsch(x) == (1/sinh(x)-1)] */
LIB_FUNC MATH_FUNC float excschf(const float radians) {
	return ((1.0F / sinhf(radians)) - 1.0F);
}


/** Return the External Cosecant [excsc(x) == (1/sin(x))-1 == csc(x)-1] */
LIB_FUNC MATH_FUNC float excscf(const float radians) {
	return ((1.0F / sinf(radians)) - 1.0F);
}


/** Return the Arc-External Secant (arcexsec(x) == acos(1/(x+1))) */
LIB_FUNC MATH_FUNC float arcexsecf(const float radians) {
	return acosf(1.0F / (radians + 1.0F));
}


/** Return the Hyperbolic Area-External Secant [arexsech(x) == (1/acosh(x)-1)] */
LIB_FUNC MATH_FUNC float arexsechf(const float radians) {
	return ((1.0F / acoshf(radians)) - 1.0F);
}


/** Return the External Hyperbolic Secant [exsech(x) == (1/cosh(x)-1)] */
LIB_FUNC MATH_FUNC float exsechf(const float radians) {
	return ((1.0F / coshf(radians)) - 1.0F);
}


/** Return the External Secant [exsec(x) == (1/cos(x))-1 == sec(x)-1] */
LIB_FUNC MATH_FUNC float exsecf(const float radians) {
	return ((1.0F / cosf(radians)) - 1.0F);
}


// EXTERNAL TRIGONOMETRY (DOUBLES)

/** Return the Arc-External Cotangent (arcexcot(x) == atan(1/(x+1))) */
LIB_FUNC MATH_FUNC double arcexcot(const double radians) {
	return atan(1.0 / (radians + 1.0));
}


/** Return the Hyperbolic Area-External Cotangent [arexcoth(x) == (1/atanh(x)-1)] */
LIB_FUNC MATH_FUNC double arexcoth(const double radians) {
	return ((1.0 / atanh(radians)) - 1.0);
}


/** Return the External Hyperbolic Cotangent [excoth(x) == (1/tanh(x)-1)] */
LIB_FUNC MATH_FUNC double excoth(const double radians) {
	return ((1.0 / tanh(radians)) - 1.0);
}


/** Return the External Cotangent [excot(x) == (1/tan(x))-1 == cot(x)-1] */
LIB_FUNC MATH_FUNC double excot(const double radians) {
	return ((1.0 / tan(radians)) - 1.0);
}


/** Return the Arc-External Cosecant (arcexcsc(x) == asin(1/(x+1))) */
LIB_FUNC MATH_FUNC double arcexcsc(const double radians) {
	return asin(1.0 / (radians + 1.0));
}


/** Return the Hyperbolic Area-External Cosecant [arexcsch(x) == (1/asinh(x)-1)] */
LIB_FUNC MATH_FUNC double arexcsch(const double radians) {
	return ((1.0 / asinh(radians)) - 1.0);
}


/** Return the External Hyperbolic Cosecant [excsch(x) == (1/sinh(x)-1)] */
LIB_FUNC MATH_FUNC double excsch(const double radians) {
	return ((1.0 / sinh(radians)) - 1.0);
}


/** Return the External Cosecant [excsc(x) == (1/sin(x))-1 == csc(x)-1] */
LIB_FUNC MATH_FUNC double excsc(const double radians) {
	return ((1.0 / sin(radians)) - 1.0);
}


/** Return the Arc-External Secant (arcexsec(x) == acos(1/(x+1))) */
LIB_FUNC MATH_FUNC double arcexsec(const double radians) {
	return acos(1.0 / (radians + 1.0));
}


/** Return the Hyperbolic Area-External Secant [arexsech(x) == (1/acosh(x)-1)] */
LIB_FUNC MATH_FUNC double arexsech(const double radians) {
	return ((1.0 / acosh(radians)) - 1.0);
}


/** Return the External Hyperbolic Secant [exsech(x) == (1/cosh(x)-1)] */
LIB_FUNC MATH_FUNC double exsech(const double radians) {
	return ((1.0 / cosh(radians)) - 1.0);
}


/** Return the External Secant [exsec(x) == (1/cos(x))-1 == sec(x)-1] */
LIB_FUNC MATH_FUNC double exsec(const double radians) {
	return ((1.0 / cos(radians)) - 1.0);
}


// EXTERNAL TRIGONOMETRY (LONG DOUBLES)

#if SUPPORTS_LONG_DOUBLE
/** Return the Arc-External Cotangent (arcexcot(x) == atan(1/(x+1))) */
LIB_FUNC MATH_FUNC long double arcexcotl(const long double radians) {
	return atanl(1.0L / (radians + 1.0L));
}


/** Return the Hyperbolic Area-External Cotangent [arexcoth(x) == (1/atanh(x)-1)] */
LIB_FUNC MATH_FUNC long double arexcothl(const long double radians) {
	return ((1.0L / atanhl(radians)) - 1.0L);
}


/** Return the External Hyperbolic Cotangent [excoth(x) == (1/tanh(x)-1)] */
LIB_FUNC MATH_FUNC long double excothl(const long double radians) {
	return ((1.0L / tanhl(radians)) - 1.0L);
}


/** Return the External Cotangent [excot(x) == (1/tan(x))-1 == cot(x)-1] */
LIB_FUNC MATH_FUNC long double excotl(const long double radians) {
	return ((1.0L / tanl(radians)) - 1.0L);
}


/** Return the Arc-External Cosecant (arcexcsc(x) == asin(1/(x+1))) */
LIB_FUNC MATH_FUNC long double arcexcscl(const long double radians) {
	return asinl(1.0L / (radians + 1.0L));
}


/** Return the Hyperbolic Area-External Cosecant [arexcsch(x) == (1/asinh(x)-1)] */
LIB_FUNC MATH_FUNC long double arexcschl(const long double radians) {
	return ((1.0L / asinhl(radians)) - 1.0L);
}


/** Return the External Hyperbolic Cosecant [excsch(x) == (1/sinh(x)-1)] */
LIB_FUNC MATH_FUNC long double excschl(const long double radians) {
	return ((1.0L / sinhl(radians)) - 1.0L);
}


/** Return the External Cosecant [excsc(x) == (1/sin(x))-1 == csc(x)-1] */
LIB_FUNC MATH_FUNC long double excscl(const long double radians) {
	return ((1.0L / sinl(radians)) - 1.0L);
}


/** Return the Arc-External Secant (arcexsec(x) == acos(1/(x+1))) */
LIB_FUNC MATH_FUNC long double arcexsecl(const long double radians) {
	return acosl(1.0L / (radians + 1.0L));
}


/** Return the Hyperbolic Area-External Secant [arexsech(x) == (1/acosh(x)-1)] */
LIB_FUNC MATH_FUNC long double arexsechl(const long double radians) {
	return ((1.0L / acoshl(radians)) - 1.0L);
}


/** Return the External Hyperbolic Secant [exsech(x) == (1/cosh(x)-1)] */
LIB_FUNC MATH_FUNC long double exsechl(const long double radians) {
	return ((1.0L / coshl(radians)) - 1.0L);
}


/** Return the External Secant [exsec(x) == (1/cos(x))-1 == sec(x)-1] */
LIB_FUNC MATH_FUNC long double exsecl(const long double radians) {
	return ((1.0L / cosl(radians)) - 1.0L);
}
#endif


// SPECIAL TRIGONOMETRIC FUNCTIONS (FLOATS)

/** Return the Cosine of an Arc-Sine [sqrt(1-(x*x))] */
LIB_FUNC MATH_FUNC float cos_arcsinf(const float radians) {
	return (sqrtf(1.0F - (radians * radians)));
}


/** Return the Cosine of an Arc-Tangent [1 / sqrt(1+(x*x))] */
LIB_FUNC MATH_FUNC float cos_arctanf(const float radians) {
	return (1.0F / sqrtf(1.0F + (radians * radians)));
}


/** Return the Sine of an Arc-Tangent [sqrt((x*x)-1)/x] */
LIB_FUNC MATH_FUNC float sin_arcsecf(const float radians) {
	return (sqrtf((radians * radians) - 1.0F) / radians);
}


/** Return the Sine of an Arc-Tangent [x / sqrt(1+(x*x))] */
LIB_FUNC MATH_FUNC float sin_arctanf(const float radians) {
	return (radians / sqrtf(1.0F + (radians * radians)));
}


// SPECIAL TRIGONOMETRIC FUNCTIONS (DOUBLES)

/** Return the Cosine of an Arc-Sine [sqrt(1-(x*x))] */
LIB_FUNC MATH_FUNC double cos_arcsin(const double radians) {
	return (sqrt(1.0 - (radians * radians)));
}


/** Return the Cosine of an Arc-Tangent [1 / sqrt(1+(x*x))] */
LIB_FUNC MATH_FUNC double cos_arctan(const double radians) {
	return (1.0 / sqrt(1.0 + (radians * radians)));
}


/** Return the Sine of an Arc-Tangent [sqrt((x*x)-1)/x] */
LIB_FUNC MATH_FUNC double sin_arcsec(const double radians) {
	return (sqrt((radians * radians) - 1.0) / radians);
}


/** Return the Sine of an Arc-Tangent [x / sqrt(1+(x*x))] */
LIB_FUNC MATH_FUNC double sin_arctan(const double radians) {
	return (radians / sqrt(1.0 + (radians * radians)));
}


// SPECIAL TRIGONOMETRIC FUNCTIONS (LONG DOUBLES)

#if SUPPORTS_LONG_DOUBLE
/** Return the Cosine of an Arc-Sine [sqrt(1-(x*x))] */
LIB_FUNC MATH_FUNC long double cos_arcsinl(const long double radians) {
	return (sqrtl(1.0L - (radians * radians)));
}


/** Return the Cosine of an Arc-Tangent [1 / sqrt(1+(x*x))] */
LIB_FUNC MATH_FUNC long double cos_arctanl(const long double radians) {
	return (1.0L / sqrtl(1.0 + (radians * radians)));
}


/** Return the Sine of an Arc-Tangent [sqrt((x*x)-1)/x] */
LIB_FUNC MATH_FUNC long double sin_arcsecl(const long double radians) {
	return (sqrtl((radians * radians) - 1.0L) / radians);
}


/** Return the Sine of an Arc-Tangent [x / sqrt(1+(x*x))] */
LIB_FUNC MATH_FUNC long double sin_arctanl(const long double radians) {
	return (radians / sqrtl(1.0L + (radians * radians)));
}
#endif


// TRIGONOMETRY FUNCTION MACROS

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


// BESSEL & GAMMA FUNCTIONS


LIB_FUNC MATH_FUNC float pzerof(const float x) {
	const float *p, *q;
	float z, r, s;
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x41000000) { p = pzerof_pR8; q = pzerof_pS8; }
	else if (ix >= 0x40f71c58) { p = pzerof_pR5; q = pzerof_pS5; }
	else if (ix >= 0x4036db68) { p = pzerof_pR3; q = pzerof_pS3; }
	else { p = pzerof_pR2; q = pzerof_pS2; }
	z = 1.0F / (x * x);
	r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
	s = 1.0F + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * q[4]))));
	return 1.0F + r / s;
}


LIB_FUNC MATH_FUNC float qzerof(const float x) {
	const float *p, *q;
	float s, r, z;
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x41000000) { p = qzerof_qR8; q = qzerof_qS8; }
	else if (ix >= 0x40f71c58) { p = qzerof_qR5; q = qzerof_qS5; }
	else if (ix >= 0x4036db68) { p = qzerof_qR3; q = qzerof_qS3; }
	else { p = qzerof_qR2; q = qzerof_qS2; }
	z = 1.0F / (x * x);
	r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
	s = 1.0F + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * q[5])))));
	return (-0.125F + r / s) / x;
}


LIB_FUNC MATH_FUNC float __ieee754_j0f(const float num) {
	float z, s, c, ss, cc, r, u, v, x = num;
	int32_t hx, ix;
	GET_FLOAT_WORD(hx, x);
	ix = hx & 0x7fffffff;
	if (ix >= 0x7f800000) { return 1.0F / (x * x); }
	x = fabsf(x);
	if (ix >= 0x40000000) {
		sincosf(x, &s, &c);
		ss = s - c;
		cc = s + c;
		if (ix < 0x7f000000) {
			z = -cosf(x + x);
			if ((s * c) < 0.0F) { cc = z / ss; }
			else { ss = z / cc; }
		}
		if (ix > 0x48000000) { z = (5.6418961287E-1F * cc) / __ieee754_sqrtf(x); }
		else {
			u = pzerof(x);
			v = qzerof(x);
			z = 5.6418961287E-1F * (u * cc - v * ss) / __ieee754_sqrtf(x);
		}
		return z;
	}
	if (ix < 0x39000000) {
		math_force_eval(HUGEF + x);
		if (ix < 0x32000000) { return 1.0F; }
		else { return 1.0F - 0.25F * x * x; }
	}
	z = x * x;
	r = z * (1.5625000000E-2F + z * (-1.8997929874E-4F + z * (1.8295404516E-6F + z * -4.6183270541E-9F)));
	s = 1.0F + z * (1.5619102865E-2F + z * (1.1692678527E-4F + z * (5.1354652442E-7F + z * 1.1661400734E-9F)));
	if (ix < 0x3f800000) {
		return 1.0F + z * (-0.25F + (r / s));
	} else {
		u = 0.5F * x;
		return ((1.0F + u) * (1.0F - u) + z * (r / s));
	}
}
#define __j0f_finite(x)   __ieee754_j0f((x))


LIB_FUNC MATH_FUNC float ponef(const float x) {
	const float *p, *q;
	float z, r, s;
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x41000000) { p = ponef_pr8; q = ponef_ps8; }
	else if (ix >= 0x40f71c58) { p = ponef_pr5; q = ponef_ps5; }
	else if (ix >= 0x4036db68) { p = ponef_pr3; q = ponef_ps3; }
	else {p = ponef_pr2; q = ponef_ps2;}
	z = 1.0F / (x * x);
	r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
	s = 1.0F + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * q[4]))));
	return 1.0F + r / s;
}


LIB_FUNC MATH_FUNC float qonef(const float x) {
	const float *p, *q;
	float s, r, z;
	int32_t ix;
	GET_FLOAT_WORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x40200000) { p = qonef_qr8; q = qonef_qs8; }
	else if (ix >= 0x40f71c58) { p = qonef_qr5; q = qonef_qs5; }
	else if (ix >= 0x4036db68) { p = qonef_qr3; q = qonef_qs3; }
	else {p = qonef_qr2; q = qonef_qs2;}
	z = 1.0F / (x * x);
	r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * p[5]))));
	s = 1.0F + z * (q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * q[5])))));
	return (0.375F + r / s) / x;
}


LIB_FUNC MATH_FUNC float __ieee754_j1f(const float num) {
	float z, s, c, r, u, v, y, x = num;
	int32_t hx;
	GET_FLOAT_WORD(hx, x);
	const int32_t ix = hx & 0x7fffffff;
	if (PREDICT_UNLIKELY(ix >= 0x7f800000)) { return 1.0F / x; }
	y = fabsf(x);
	if (ix >= 0x40000000) {
		sincosf(y, &s, &c);
		float ss = -s - c;
		float cc = s - c;
		if (ix < 0x7f000000) {
			z = cosf(y + y);
			if ((s * c) > 0.0F) { cc = z / ss; }
			else { ss = z / cc; }
		}
		if (ix > 0x48000000) { z = (5.6418961287E-1F * cc) / __ieee754_sqrtf(y); }
		else {
			u = ponef(y);
			v = qonef(y);
			z = 5.6418961287E-1F * (u * cc - v * ss) / __ieee754_sqrtf(y);
		}
		if (hx < 0) { return -z; }
		else { return z; }
	}
	if (PREDICT_UNLIKELY(ix < 0x32000000)) {
		if (HUGEF + x > 1.0F) {
			float ret = math_narrow_eval(0.5F * x);
			math_check_force_underflow(ret);
			if (ret == 0 && x != 0) { set_errno(ERANGE); }
			return ret;
		}
	}
	z = x * x;
	r = z * (-6.2500000000E-2F + z * (1.4070566976E-3F + z * (-1.5995563444e-05F + z * 4.9672799207E-8F)));
	s = 1.0F + z * (1.9153760746E-2F + z * (1.8594678841E-4F + z * (1.1771846857E-6F + z * (5.0463624390E-9F + z * 1.2354227016E-11F))));
	r *= x;
	return (x * 0.5F + r / s);
}
#define __j1f_finite(x)   __ieee754_j1f((x))


LIB_FUNC MATH_FUNC float __ieee754_y1f(const float num) {
	float z, s, c, u, v, x = num;
	int32_t hx;
	GET_FLOAT_WORD(hx, x);
	const int32_t ix = 0x7fffffff & hx;
	if (PREDICT_UNLIKELY(ix >= 0x7f800000)) { return 1.0F / (x + x * x); }
	else if (PREDICT_UNLIKELY(ix == 0)) { return -HUGE_VALF + x; }
	else if (PREDICT_UNLIKELY(hx < 0)) { return 0.0F / (0.0F * x); }
	else if (ix >= 0x40000000) {
		// SET_RESTORE_ROUNDF(FE_TONEAREST);
		sincosf(x, &s, &c);
		float ss = -s - c;
		float cc = s - c;
		if (ix < 0x7f000000) {
			z = cosf(x + x);
			if ((s * c) > 0.0F) { cc = z / ss; }
			else { ss = z / cc; }
		}
		if (ix > 0x48000000) { z = (5.6418961287E-1F * ss) / __ieee754_sqrtf(x); }
		else {
			u = ponef(x);
			v = qonef(x);
			z = 5.6418961287E-1F * (u * ss + v * cc) / __ieee754_sqrtf(x);
		}
		return z;
	}
	if (PREDICT_UNLIKELY(ix <= 0x33000000)) {
		z = -6.3661974669E-1F / x;
		if (isinf(z)) { set_errno(ERANGE); }
		return z;
	}
	z = x * x;
	u = -1.9605709612E-1F + z * (5.0443872809E-2F + z * (-1.9125689287E-3F + z * (2.3525259166E-5F + z * -9.1909917899E-8F)));
	v = 1.0F + z * (1.9916731864E-2F + z * (2.0255257550E-4F + z * (1.3560879779E-6F + z * (6.2274145840E-9F + z * 1.6655924903E-11F))));
	return (x * (u / v) + 6.3661974669E-1F * (__ieee754_j1f(x) * __ieee754_logf(x) - 1.0F / x));
}
#define __y1f_finite(x)   __ieee754_y1f((x))


LIB_FUNC MATH_FUNC float __ieee754_y0f(const float num) {
	float z, s, c, u, v, x = num;
	int32_t hx;
	GET_FLOAT_WORD(hx, x);
	const int32_t ix = 0x7fffffff & hx;
	if (ix >= 0x7f800000) { return 1.0F / (x + x * x); }
	else if (ix == 0) { return -HUGE_VALF + x; }
	else if (hx < 0) { return 0.0F / (0.0F * x); }
	else if (ix >= 0x40000000) {
		sincosf(x, &s, &c);
		float ss = s - c;
		float cc = s + c;
		if (ix < 0x7f000000) {
			z = -cosf(x + x);
			if ((s * c) < 0.0F) { cc = z / ss; }
			else { ss = z / cc; }
		}
		if (ix > 0x48000000) { z = (5.6418961287E-1F * ss) / __ieee754_sqrtf(x); }
		else {
			u = pzerof(x);
			v = qzerof(x);
			z = 5.6418961287E-1F * (u * ss + v * cc) / __ieee754_sqrtf(x);
		}
		return z;
	}
	if (ix <= 0x39800000) {
		return (-7.3804296553E-2F + 6.3661974669E-1F * __ieee754_logf(x));
	}
	z = x * x;
	u = -7.3804296553E-2F + z * (1.7666645348E-1F + z * (-1.3818567619E-2F + z * (3.4745343146E-4F + z * (-3.8140706238E-6F + z * (1.9559013964E-8F + z * -3.9820518410E-11F)))));
	v = 1.0F + z * (1.2730483897E-2F + z * (7.6006865129E-5F + z * (2.5915085189E-7F + z * 4.4111031494E-10F)));
	return (u / v + 6.3661974669E-1F * (__ieee754_j0f(x) * __ieee754_logf(x)));
}
#define __y0f_finite(x)   __ieee754_y0f((x))


LIB_FUNC MATH_FUNC float __ieee754_jnf(const int num, const float numx) {
	int32_t i, hx, n = (int32_t)num;
	float a, b, di, z, w, x = numx;
	GET_FLOAT_WORD(hx, x);
	const int32_t ix = 0x7fffffff & hx;
	if (PREDICT_UNLIKELY(ix > 0x7f800000)) { return x + x; }
	else if (n < 0) {
		n = -n;
		x = -x;
		hx ^= (int32_t)0x80000000;
	}
	if (n == 0) { return (__ieee754_j0f(x)); }
	else if (n == 1) { return (__ieee754_j1f(x)); }
	const int32_t sgn = (n & 1) & (hx >> 31);
	x = fabsf(x);
	// SET_RESTORE_ROUNDF(FE_TONEAREST);
	float temp;
	if (PREDICT_UNLIKELY(ix == 0 || ix >= 0x7f800000)) { return (sgn == 1 ? -0.0F : 0.0F); }
	else if ((float)n <= x) {
		a = __ieee754_j0f(x);
		b = __ieee754_j1f(x);
		for (i = 1; i < n; i++) {
			temp = b;
			b = b * (((float)(i + i)) / x) - a;
			a = temp;
		}
	} else {
		if (ix < 0x30800000) {
			if (n > 33) { b = 0.0F; }
			else {
				temp = x * 0.5F;
				b = temp;
				for (a = 1.0F, i = 2; i <= n; i++) {
					a *= (float)i;
					b *= temp;
				}
				b /= a;
			}
		} else {
			float t, v, q0, q1, h, tmp;
			int32_t k, m;
			w = ((float)(n + n)) / x;
			h = 2.0F / x;
			q0 = w;
			z = w + h;
			q1 = w * z - 1.0F;
			k = 1;
			while (q1 < 1.0E+9F) {
				k += 1;
				z += h;
				tmp = z * q1 - q0;
				q0 = q1;
				q1 = tmp;
			}
			m = n + n;
			for (t = 0.0F, i = 2 * (n + k); i >= m; i -= 2) { t = 1.0F / (float)((float)i / x - t); }
			a = t;
			b = 1.0F;
			tmp = (float)n;
			v = 2.0F / x;
			tmp *= __ieee754_logf(fabsf(v * tmp));
			if (tmp < 8.8721679688E+1F) {
				for (i = n - 1, di = (float)(i + i); i > 0; i--) {
					temp = b;
					b *= di;
					b = b / x - a;
					a = temp;
					di -= 2.0F;
				}
			} else {
				for (i = n - 1, di = (float)(i + i); i > 0; i--) {
					temp = b;
					b *= di;
					b = b / x - a;
					a = temp;
					di -= 2.0F;
					if (b > (float)1.0E+10F) {
						a /= b;
						t /= b;
						b = 1.0F;
					}
				}
			}
			z = __ieee754_j0f(x);
			w = __ieee754_j1f(x);
			if (fabsf(z) >= fabsf(w)) { b = (t * z / b); }
			else { b = (t * w / a); }
		}
	}
	float ret = (sgn == 1 ? -b : b);
	ret = math_narrow_eval(ret);
	if (ret == 0) {
		ret = math_narrow_eval(copysignf(FLT_MIN, ret) * FLT_MIN);
		set_errno(ERANGE);
	}  // else { math_check_force_underflow(ret); }
	return ret;
}
#define __jnf_finite(n, x)   __ieee754_jnf((n), (x))


LIB_FUNC MATH_FUNC float __ieee754_ynf(const int num, const float x) {
	int32_t hx, n = (int32_t)num;
	GET_FLOAT_WORD(hx, x);
	const int32_t ix = 0x7fffffff & hx;
	if (PREDICT_UNLIKELY(ix > 0x7f800000)) { return x + x; }
	else if (PREDICT_UNLIKELY(ix == 0)) { return -HUGE_VALF + x; }
	else if (PREDICT_UNLIKELY(hx < 0)) { return 0.0F / (0.0F * x); }
	int32_t sign = 1;
	if (n < 0) {
		n = -n;
		sign = 1 - ((n & 1) << 1);
	}
	float ret, a, b;
	if (n == 0) { return __ieee754_y0f(x); }
	// SET_RESTORE_ROUNDF(FE_TONEAREST);
	else if (n == 1) {
		const float tmpf = __ieee754_y1f(x);
		ret = (float)(sign * (int32_t)tmpf);
		goto goto_ieee754_ynf_out;
	} else if (PREDICT_UNLIKELY(ix == 0x7f800000)) { return 0.0F; }
	a = __ieee754_y0f(x);
	b = __ieee754_y1f(x);
	uint32_t ib;
	GET_FLOAT_UWORD(ib, b);
	for (register int32_t i = 1; i < n && ib != 0xff800000; i++) {
		const float temp = b;
		b = (((float)(i + i)) / x) * b - a;
		GET_FLOAT_UWORD(ib, b);
		a = temp;
	}
	if (!isfinite(b)) { set_errno(ERANGE); }
	if (sign > 0) { ret = b; }
	else { ret = -b; }
goto_ieee754_ynf_out:
	if (isinf(ret)) { ret = copysignf(FLT_MAX, ret) * FLT_MAX; }
	return ret;
}
#define __ynf_finite(n, x)   __ieee754_ynf((n), (x))


LIB_FUNC MATH_FUNC double pzero(const double x) {
	const double *p, *q;
	double z, r, s, z2, z4, r1, r2, r3, s1, s2, s3;
	int32_t ix;
	GET_HIGH_SWORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x41b00000) { return 1.0; }
	else if (ix >= 0x40200000) {
		p = pzero_pR8;
		q = pzero_pS8;
	} else if (ix >= 0x40122e8b) {
		p = pzero_pR5;
		q = pzero_pS5;
	} else if (ix >= 0x4006db6d) {
		p = pzero_pR3;
		q = pzero_pS3;
	} else {
		p = pzero_pR2;
		q = pzero_pS2;
	}
	z = 1.0 / (x * x);
	r1 = p[0] + z * p[1];
	z2 = z * z;
	r2 = p[2] + z * p[3];
	z4 = z2 * z2;
	r3 = p[4] + z * p[5];
	r = r1 + z2 * r2 + z4 * r3;
	s1 = 1.0 + z * q[0];
	s2 = q[1] + z * q[2];
	s3 = q[3] + z * q[4];
	s = s1 + z2 * s2 + z4 * s3;
	return 1.0 + r / s;
}


LIB_FUNC MATH_FUNC double qzero(const double x) {
	const double *p, *q;
	double s, r, z, z2, z4, z6, r1, r2, r3, s1, s2, s3;
	int32_t ix;
	GET_HIGH_SWORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x41b00000) { return -0.125 / x; }
	else if (ix >= 0x40200000) {
		p = qzero_qR8;
		q = qzero_qS8;
	} else if (ix >= 0x40122e8b) {
		p = qzero_qR5;
		q = qzero_qS5;
	} else if (ix >= 0x4006db6d) {
		p = qzero_qR3;
		q = qzero_qS3;
	} else {
		p = qzero_qR2;
		q = qzero_qS2;
	}
	z = 1.0 / (x * x);
	r1 = p[0] + z * p[1];
	z2 = z * z;
	r2 = p[2] + z * p[3];
	z4 = z2 * z2;
	r3 = p[4] + z * p[5];
	z6 = z4 * z2;
	r = r1 + z2 * r2 + z4 * r3;
	s1 = 1.0 + z * q[0];
	s2 = q[1] + z * q[2];
	s3 = q[3] + z * q[4];
	s = s1 + z2 * s2 + z4 * s3 + z6 * q[5];
	return (-0.125 + r / s) / x;
}


LIB_FUNC MATH_FUNC double __ieee754_j0(const double num) {
	double z, s, c, ss, cc, r, u, v, r1, r2, s1, s2, z2, z4, x = num;
	int32_t hx, ix;
	GET_HIGH_SWORD(hx, x);
	ix = hx & 0x7fffffff;
	if (ix >= 0x7ff00000) { return 1.0 / (x * x); }
	x = fabs(x);
	if (ix >= 0x40000000) {
		sincos(x, &s, &c);
		ss = s - c;
		cc = s + c;
		if (ix < 0x7fe00000) {
			z = -cos(x + x);
			if ((s * c) < 0.0) { cc = z / ss; }
			else { ss = z / cc; }
		}
		if (ix > 0x48000000) { z = (5.64189583547756279280E-1 * cc) / __ieee754_sqrt(x); }
		else {
			u = pzero(x);
			v = qzero(x);
			z = 5.64189583547756279280E-1 * (u * cc - v * ss) / __ieee754_sqrt(x);
		}
		return z;
	}
	if (ix < 0x3f200000) {
		math_force_eval(HUGE + x);
		if (ix < 0x3e400000) { return 1.0; }
		else { return 1.0 - 0.25 * x * x; }
	}
	z = x * x;
	r1 = z * 1.56249999999999947958E-2;
	z2 = z * z;
	r2 = -1.89979294238854721751E-4 + z * 1.82954049532700665670E-6;
	z4 = z2 * z2;
	r = r1 + z2 * r2 + z4 * -4.61832688532103189199E-9;
	s1 = 1.0 + z * 1.56191029464890010492E-2;
	s2 = 1.16926784663337450260E-4 + z * 5.13546550207318111446E-7;
	s = s1 + z2 * s2 + z4 * 1.16614003333790000205E-9;
	if (ix < 0x3ff00000) { return 1.0 + z * (-0.25 + (r / s)); }
	else {
		u = 0.5 * x;
		return ((1.0 + u) * (1.0 - u) + z * (r / s));
	}
}
#define __j0_finite(x)   __ieee754_j0((x))


LIB_FUNC MATH_FUNC double __ieee754_y0(const double num) {
	double z, s, c, ss, cc, u, v, z2, z4, z6, u1, u2, u3, v1, v2, x = num;
	int32_t hx, ix, lx;
	EXTRACT_SWORDS(hx, lx, x);
	ix = 0x7fffffff & hx;
	if (ix >= 0x7ff00000) { return 1.0 / (x + x * x); }
	if ((ix | lx) == 0) { return -HUGE_VAL + x; }
	if (hx < 0) { return 0.0 / (0.0 * x); }
	if (ix >= 0x40000000) {
		sincos(x, &s, &c);
		ss = s - c;
		cc = s + c;
		if (ix < 0x7fe00000) {
			z = -cos(x + x);
			if ((s * c) < 0.0) { cc = z / ss; }
			else { ss = z / cc; }
		}
		if (ix > 0x48000000) { z = (5.64189583547756279280E-1 * ss) / __ieee754_sqrt(x); }
		else {
			u = pzero(x);
			v = qzero(x);
			z = 5.64189583547756279280E-1 * (u * ss + v * cc) / __ieee754_sqrt(x);
		}
		return z;
	}
	if (ix <= 0x3e400000) {
		return (-7.38042951086872317523E-2 + 6.36619772367581382433E-1 * __ieee754_log(x));
	}
	z = x * x;
	u1 = -7.38042951086872317523E-2 + z * 1.76666452509181115538E-1;
	z2 = z * z;
	u2 = -1.38185671945596898896E-2 + z * 3.47453432093683650238E-4;
	z4 = z2 * z2;
	u3 = -3.81407053724364161125E-6 + z * 1.95590137035022920206E-8;
	z6 = z4 * z2;
	u = u1 + z2 * u2 + z4 * u3 + z6 * -3.98205194132103398453E-11;
	v1 = 1.0 + z * 1.27304834834123699328E-2;
	v2 = 7.60068627350353253702E-5 + z * 2.59150851840457805467E-7;
	v = v1 + z2 * v2 + z4 * 4.41110311332675467403E-10;
	return (u / v + 6.36619772367581382433E-1 * (__ieee754_j0(x) * __ieee754_log(x)));
}
#define __y0_finite(x)   __ieee754_y0((x))


LIB_FUNC MATH_FUNC double pone(const double x) {
	const double *p, *q;
	double z, r, s, r1, r2, r3, s1, s2, s3, z2, z4;
	int32_t ix;
	GET_HIGH_SWORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x41b00000) { return 1.0; }
	else if (ix >= 0x40200000) {
		p = pone_pr8;
		q = pone_ps8;
	} else if (ix >= 0x40122e8b) {
		p = pone_pr5;
		q = pone_ps5;
	} else if (ix >= 0x4006db6d) {
		p = pone_pr3;
		q = pone_ps3;
	} else {
		p = pone_pr2;
		q = pone_ps2;
	}
	z = 1.0 / (x * x);
	r1 = p[0] + z * p[1];
	z2 = z * z;
	r2 = p[2] + z * p[3];
	z4 = z2 * z2;
	r3 = p[4] + z * p[5];
	r = r1 + z2 * r2 + z4 * r3;
	s1 = 1.0 + z * q[0];
	s2 = q[1] + z * q[2];
	s3 = q[3] + z * q[4];
	s = s1 + z2 * s2 + z4 * s3;
	return 1.0 + r / s;
}


LIB_FUNC MATH_FUNC double qone(const double x) {
	const double *p, *q;
	double s, r, z, r1, r2, r3, s1, s2, s3, z2, z4, z6;
	int32_t ix;
	GET_HIGH_SWORD(ix, x);
	ix &= 0x7fffffff;
	if (ix >= 0x41b00000) { return 0.375 / x; }
	else if (ix >= 0x40200000) {
		p = qone_qr8;
		q = qone_qs8;
	} else if (ix >= 0x40122e8b) {
		p = qone_qr5;
		q = qone_qs5;
	} else if (ix >= 0x4006db6d) {
		p = qone_qr3;
		q = qone_qs3;
	} else {
		p = qone_qr2;
		q = qone_qs2;
	}
	z = 1.0 / (x * x);
	r1 = p[0] + z * p[1];
	z2 = z * z;
	r2 = p[2] + z * p[3];
	z4 = z2 * z2;
	r3 = p[4] + z * p[5];
	z6 = z4 * z2;
	r = r1 + z2 * r2 + z4 * r3;
	s1 = 1.0 + z * q[0];
	s2 = q[1] + z * q[2];
	s3 = q[3] + z * q[4];
	s = s1 + z2 * s2 + z4 * s3 + z6 * q[5];
	return (0.375 + r / s) / x;
}


LIB_FUNC MATH_FUNC double __ieee754_j1(const double xnum) {
	double x = xnum, z, s, c, u, v;
	int32_t hx;
	GET_HIGH_SWORD(hx, x);
	const int32_t ix = hx & 0x7fffffff;
	if (PREDICT_UNLIKELY(ix >= 0x7ff00000)) { return 1.0 / x; }
	const double y = fabs(x);
	if (ix >= 0x40000000) {
		sincos(y, &s, &c);
		double ss = -s - c;
		double cc = s - c;
		if (ix < 0x7fe00000) {
			z = cos(y + y);
			if ((s * c) > 0.0) { cc = z / ss; }
			else { ss = z / cc; }
		}
		if (ix > 0x48000000) { z = (5.64189583547756279280E-1 * cc) / __ieee754_sqrt(y); }
		else {
			u = pone(y);
			v = qone(y);
			z = 5.64189583547756279280E-1 * (u * cc - v * ss) / __ieee754_sqrt(y);
		}
		if (hx < 0) { return -z; }
		return z;
	}
	if (PREDICT_UNLIKELY(ix < 0x3e400000)) {
		if (HUGE + x > 1.0) {
			double ret = math_narrow_eval(0.5 * x);
			// math_check_force_underflow(ret);
			if (ret == 0 && x != 0) { set_errno(ERANGE); }
			return ret;
		}
	}
	z = x * x;
	const double z2 = z * z;
	const double r2 = 1.40705666955189706048E-3 + z * -1.59955631084035597520E-5;
	const double z4 = z2 * z2;
	const double r = ((z * -6.25000000000000000000E-2) + z2 * r2 + z4 * 4.96727999609584448412E-8) * x;
	const double s3 = 5.04636257076217042715E-9 + z * 1.23542274426137913908E-11;
	s = (1.0 + z * 1.91537599538363460805E-2) + z2 * (1.85946785588630915560E-4 + z * 1.17718464042623683263E-6) + z4 * s3;
	return (x * 0.5 + r / s);
}
#define __j1_finite(x)   __ieee754_j1((x))


LIB_FUNC MATH_FUNC double __ieee754_y1(const double xnum) {
	double x = xnum, z, s, c, u, v;
	int32_t hx, lx;
	EXTRACT_SWORDS(hx, lx, x);
	const int32_t ix = 0x7fffffff & hx;
	if (PREDICT_UNLIKELY(ix >= 0x7ff00000)) { return 1.0 / (x + x * x); }
	else if (PREDICT_UNLIKELY((ix | lx) == 0)) { return -HUGE_VAL + x; }
	else if (PREDICT_UNLIKELY(hx < 0)) { return 0.0 / (0.0 * x); }
	else if (ix >= 0x40000000) {
		sincos(x, &s, &c);
		double ss = -s - c;
		double cc = s - c;
		if (ix < 0x7fe00000) {
			z = cos(x + x);
			if ((s * c) > 0.0) { cc = z / ss; }
			else { ss = z / cc; }
		}
		if (ix > 0x48000000) { z = (5.64189583547756279280E-1 * ss) / __ieee754_sqrt(x); }
		else {
			u = pone(x);
			v = qone(x);
			z = 5.64189583547756279280E-1 * (u * ss + v * cc) / __ieee754_sqrt(x);
		}
		return z;
	}
	if (PREDICT_UNLIKELY(ix <= 0x3c900000)) {
		z = -6.36619772367581382433E-1 / x;
		if (__isinf(z)) { set_errno(ERANGE); }
		return z;
	}
	z = x * x;
	const double z2 = z * z;
	const double z4 = z2 * z2;
	u = (-1.96057090646238940668E-1 + z * 5.04438716639811282616E-2) + z2 * (-1.91256895875763547298E-3 + z * 2.35252600561610495928E-5) + z4 * -9.19099158039878874504E-8;
	const double v1 = 1.0 + z * 1.99167318236649903973E-2;
	v = v1 + z2 * (2.02552581025135171496E-4 + z * 1.35608801097516229404E-6) + z4 * (6.22741452364621501295E-9 + z * 1.66559246207992079114E-11);
	return (x * (u / v) + 6.36619772367581382433E-1 * (__ieee754_j1(x) * __ieee754_log(x) - 1.0 / x));
}
#define __y1_finite(x)   __ieee754_y1((x))


LIB_FUNC MATH_FUNC double __ieee754_jn(const int num, const double numx) {
	int32_t i, hx, lx, n = (int32_t)num;
	double a, b, temp, di, z, w, x = numx;
	EXTRACT_SWORDS(hx, lx, x);
	const int32_t ix = 0x7fffffff & hx;
	if (PREDICT_UNLIKELY(((uint32_t)ix | ((uint32_t)(lx | -lx)) >> 31) > 0x7ff00000)) { return x + x; }
	else if (n < 0) {
		n = -n;
		x = -x;
		hx ^= (int32_t)0x80000000;
	}
	if (n == 0) { return __ieee754_j0(x); }
	else if (n == 1) { return __ieee754_j1(x); }
	const int32_t sgn = (n & 1) & (hx >> 31);
	x = fabs (x);
	// SET_RESTORE_ROUND(FE_TONEAREST);
	if (PREDICT_UNLIKELY((ix | lx) == 0 || ix >= 0x7ff00000)) { return sgn == 1 ? -0.0 : 0.0; }
	else if ((double)n <= x) {
		if (ix >= 0x52d00000) {
			double s, c;
			sincos(x, &s, &c);
			switch (n & 3) {
				case 0:
					temp = c + s;
					break;
				case 1:
					temp = -c + s;
					break;
				case 2:
					temp = -c - s;
					break;
				default:  // case 3
					temp = c - s;
					break;
			}
			b = 5.64189583547756279280E-1 * temp / __ieee754_sqrt(x);
		} else {
			a = __ieee754_j0 (x);
			b = __ieee754_j1 (x);
			for (i = 1; i < n; i++) {
				temp = b;
				b = b * ((double)(i + i) / x) - a;
				a = temp;
			}
		}
	} else {
		if (ix < 0x3e100000) {
			if (n > 33) { b = 0.0; }
			else {
				temp = x * 0.5;
				b = temp;
				for (a = 1.0, i = 2; i <= n; i++) {
					a *= (double) i;
					b *= temp;
				}
				b /= a;
			}
		} else {
			double t, v, h, tmp;
			int32_t k, m;
			w = (n + n) / (double) x;
			h = 2.0 / (double) x;
			double q0 = w;
			z = w + h;
			double q1 = w * z - 1.0;
			k = 1;
			while (q1 < 1.0E+9) {
				k += 1;
				z += h;
				tmp = z * q1 - q0;
				q0 = q1;
				q1 = tmp;
			}
			m = n + n;
			for (t = 0.0, i = 2 * (n + k); i >= m; i -= 2) { t = 1.0 / (i / x - t); }
			a = t;
			b = 1.0;
			tmp = n;
			v = 2.0 / x;
			tmp *= __ieee754_log(fabs(v * tmp));
			if (tmp < BIGX) {
				for (i = n - 1, di = (double)(i + i); i > 0; i--) {
					temp = b;
					b *= di;
					b = b / x - a;
					a = temp;
					di -= 2.0;
				}
			} else {
				for (i = n - 1, di = (double)(i + i); i > 0; i--) {
					temp = b;
					b *= di;
					b = b / x - a;
					a = temp;
					di -= 2.0;
					if (b > 1.0E+100) {
						a /= b;
						t /= b;
						b = 1.0;
					}
				}
			}
			z = __ieee754_j0(x);
			w = __ieee754_j1(x);
			if (fabs (z) >= fabs(w)) { b = (t * z / b); }
			else { b = (t * w / a); }
		}
	}
	double ret = (sgn == 1 ? -b : b);
	ret = math_narrow_eval(ret);
	if (ret == 0) {
		ret = math_narrow_eval (copysign(DBL_MIN, ret) * DBL_MIN);
		set_errno(ERANGE);
	}  // else { math_check_force_underflow(ret); }
	return ret;
}
#define __jn_finite(n, x)   __ieee754_jn((n), (x))


LIB_FUNC MATH_FUNC double __ieee754_yn(const int num, const double x) {
	int32_t i, hx, lx, n = (int32_t)num;
	double a, b, temp, ret;
	EXTRACT_SWORDS(hx, lx, x);
	const int32_t ix = 0x7fffffff & hx;
	if (PREDICT_UNLIKELY(((uint32_t)ix | (((uint32_t)lx | (uint32_t)-lx)) >> 31) > 0x7ff00000)) { return x + x; }
	else if (PREDICT_UNLIKELY((ix | lx) == 0)) { return -HUGE_VAL + x; }
	if (PREDICT_UNLIKELY(hx < 0)) { return 0.0 / (0.0 * x); }
	int32_t sign = 1;
	if (n < 0) {
		n = -n;
		sign = 1 - ((n & 1) << 1);
	}
	if (n == 0) { return (__ieee754_y0(x)); }
	// SET_RESTORE_ROUND(FE_TONEAREST);
	if (n == 1) {
		ret = sign * __ieee754_y1(x);
		goto goto_ieee754_yn_out;
	}
	if (PREDICT_UNLIKELY(ix == 0x7ff00000)) { return 0.0; }
	else if (ix >= 0x52d00000) {
		double c, s;
		sincos(x, &s, &c);
		switch (n & 3) {
			case 0:
				temp = s - c;
				break;
			case 1:
				temp = -s - c;
				break;
			case 2:
				temp = -s + c;
				break;
			default:  // case 3
				temp = s + c;
				break;
		}
		b = 5.64189583547756279280E-1 * temp / __ieee754_sqrt(x);
	} else {
		uint32_t high;
		a = __ieee754_y0(x);
		b = __ieee754_y1(x);
		GET_HIGH_WORD(high, b);
		for (i = 1; i < n && high != 0xfff00000; i++) {
			temp = b;
			b = ((double)(i + i) / x) * b - a;
			GET_HIGH_WORD(high, b);
			a = temp;
		}
		if (!isfinite(b)) { set_errno(ERANGE); }
	}
	if (sign > 0) { ret = b; }
	else { ret = -b; }
goto_ieee754_yn_out:
	if (__isinf(ret)) { ret = copysign(DBL_MAX, ret) * DBL_MAX; }
	return ret;
}
#define __yn_finite(n, x)   __ieee754_yn((n), (x))


#if IS_LDBL_X87  // j1l, jnl, y1l, ynl, & others


LIB_FUNC MATH_FUNC long double pzerol(const long double x) {
	const long double *p, *q;
	uint32_t se, i0, i1;
	GET_LDOUBLE_WORDS(se, i0, i1, x);
	const int32_t ix = se & 0x7fff;
	if (ix >= 0x4002) {
		p = pzerol_pR8;
		q = pzerol_pS8;
	} else {
		i1 = (ix << 16) | (i0 >> 16);
		if (i1 >= 0x40019174) {
			p = pzerol_pR5;
			q = pzerol_pS5;
		} else if (i1 >= 0x4000b6db) {
			p = pzerol_pR3;
			q = pzerol_pS3;
		} else {
			p = pzerol_pR2;
			q = pzerol_pS2;
		}
	}
	const long double z = 1.0L / (x * x);
	const long double r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * (p[5] + z * p[6])))));
	const long double s = q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * (q[5] + z)))));
	return (1.0L + z * r / s);
}


LIB_FUNC MATH_FUNC long double qzerol(const long double x) {
	const long double *p, *q;
	uint32_t se, i0, i1;
	GET_LDOUBLE_WORDS(se, i0, i1, x);
	const int32_t ix = se & 0x7fff;
	if (ix >= 0x4002) {
		p = qzerol_qR8;
		q = qzerol_qS8;
	} else {
		i1 = (uint32_t)((ix << 16) | (i0 >> 16));
		if (i1 >= 0x40019174) {
			p = qzerol_qR5;
			q = qzerol_qS5;
		} else if (i1 >= 0x4000b6db) {
			p = qzerol_qR3;
			q = qzerol_qS3;
		} else {
			p = qzerol_qR2;
			q = qzerol_qS2;
		}
	}
	const long double z = 1.0L / (x * x);
	const long double r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * (p[5] + z * p[6])))));
	const long double s = q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * (q[5] + z * (q[6] + z))))));
	return (-0.125L + z * r / s) / x;
}


LIB_FUNC MATH_FUNC long double __ieee754_j0l(const long double num) {
	long double z, s, c, u, v, x = num;
	uint32_t se;
	GET_LDOUBLE_EXP(se, x);
	const int32_t ix = se & 0x7fff;
	if (PREDICT_UNLIKELY(ix >= 0x7fff)) { return 1.0L / (x * x); }
	x = fabsl(x);
	if (ix >= 0x4000) {
		sincosl(x, &s, &c);
		long double ss = s - c;
		long double cc = s + c;
		if (ix < 0x7ffe) {
			z = -cosl(x + x);
			if ((s * c) < zero) { cc = z / ss; }
			else { ss = z / cc; }
		}
		if (PREDICT_UNLIKELY(ix > 0x4080)) { z = (5.6418958354775628694807945156077258584405E-1L * cc) / __ieee754_sqrtl(x); }
		else {
			u = pzerol(x);
			v = qzerol(x);
			z = 5.6418958354775628694807945156077258584405E-1L * (u * cc - v * ss) / __ieee754_sqrtl(x);
		}
		return z;
	}
	if (PREDICT_UNLIKELY(ix < 0x3fef)) {
		math_force_eval(HUGEL + x);
		if (ix < 0x3fde) { return 1.0L; }
		else { return 1.0L - 0.25 * x * x; }
	}
	z = x * x;
	const long double r = z * (4.287176872744686992880841716723478740566E+7L + z * (-6.652058897474241627570911531740907185772E+5L + z * (7.011848381719789863458364584613651091175E+3L + z * (-3.168040850193372408702135490809516253693E+1L + z * 6.030778552661102450545394348845599300939E-2L))));
	s = 2.743793198556599677955266341699130654342E+9L + z * (3.364330079384816249840086842058954076201E+7L + z * (1.924119649412510777584684927494642526573E+5L + z * (6.239282256012734914211715620088714856494E+2L + z)));
	if (ix < 0x3fff) {
		return (1.0L - 0.25 * z + z * (r / s));
	} else {
		u = 0.5L * x;
		return ((1.0L + u) * (1.0L - u) + z * (r / s));
	}
}
#define __j0l_finite(x)   __ieee754_j0l((x))


LIB_FUNC MATH_FUNC long double __ieee754_y0l(const long double num) {
	long double z, s, c, u, v, x = num;
	uint32_t se, i0, i1;
	GET_LDOUBLE_WORDS(se, i0, i1, x);
	const int32_t ix = se & 0x7fff;
	if (PREDICT_UNLIKELY(se & 0x8000)) { return 0.0L / (0.0L * x); }
	else if (PREDICT_UNLIKELY(ix >= 0x7fff)) { return 1.0L / (x + x * x); }
	else if (PREDICT_UNLIKELY((i0 | i1) == 0)) { return -HUGE_VALL + x; }
	else if (ix >= 0x4000) {
		sincosl(x, &s, &c);
		long double ss = s - c;
		long double cc = s + c;
		if (ix < 0x7ffe) {
			z = -cosl(x + x);
			if ((s * c) < 0.0L) { cc = z / ss; }
			else { ss = z / cc; }
		}
		if (PREDICT_UNLIKELY(ix > 0x4080)) { z = (5.6418958354775628694807945156077258584405E-1L * ss) / __ieee754_sqrtl(x); }
		else {
			u = pzerol(x);
			v = qzerol(x);
			z = 5.6418958354775628694807945156077258584405E-1L * (u * ss + v * cc) / __ieee754_sqrtl(x);
		}
		return z;
	}
	if (PREDICT_UNLIKELY(ix <= 0x3fde)) {
		z = -7.380429510868722527629822444004602747322E-2L + 6.3661977236758134307553505349005744813784E-1L * __ieee754_logl(x);
		return z;
	}
	z = x * x;
	u = -1.054912306975785573710813351985351350861E+10L + z * (2.520192609749295139432773849576523636127E+10L + z * (-1.856426071075602001239955451329519093395E+9L + z * (4.079209129698891442683267466276785956784E+7L + z * (-3.440684087134286610316661166492641011539E+5L + z * 1.005524356159130626192144663414848383774E+3L))));
	v = 1.429337283720789610137291929228082613676E+11L + z * (2.492593075325119157558811370165695013002E+9L + z * (2.186077620785925464237324417623665138376E+7L + z * (1.238407896366385175196515057064384929222E+5L + z * (4.693924035211032457494368947123233101664E+2L + z))));
	return (u / v + 6.3661977236758134307553505349005744813784E-1L * (__ieee754_j0l(x) * __ieee754_logl(x)));
}
#define __y0l_finite(x)   __ieee754_y0l((x))


LIB_FUNC MATH_FUNC long double ponel(const long double x) {
	const long double *p, *q;
	uint32_t se, i0, i1;
	GET_LDOUBLE_WORDS(se, i0, i1, x);
	const int32_t ix = se & 0x7fff;
	if (ix >= 0x4002) {
		p = ponel_pr8;
		q = ponel_ps8;
	} else {
		i1 = (ix << 16) | (i0 >> 16);
		if (i1 >= 0x40019174) {
			p = ponel_pr5;
			q = ponel_ps5;
		} else if (i1 >= 0x4000b6db) {
			p = ponel_pr3;
			q = ponel_ps3;
		} else {
			p = ponel_pr2;
			q = ponel_ps2;
		}
	}
	const long double z = 1.0L / (x * x);
	const long double r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * (p[5] + z * p[6])))));
	const long double s = q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * (q[5] + z)))));
	return 1.0L + z * r / s;
}


LIB_FUNC MATH_FUNC long double qonel(const long double x) {
	const long double *p, *q;
	uint32_t se, i0, i1;
	GET_LDOUBLE_WORDS(se, i0, i1, x);
	const int32_t ix = se & 0x7fff;
	if (ix >= 0x4002) {
		p = qonel_qr8;
		q = qonel_qs8;
	} else {
		i1 = (ix << 16) | (i0 >> 16);
		if (i1 >= 0x40019174) {
			p = qonel_qr5;
			q = qonel_qs5;
		} else if (i1 >= 0x4000b6db) {
			p = qonel_qr3;
			q = qonel_qs3;
		} else {
			p = qonel_qr2;
			q = qonel_qs2;
		}
	}
	const long double z = 1.0L / (x * x);
	const long double r = p[0] + z * (p[1] + z * (p[2] + z * (p[3] + z * (p[4] + z * (p[5] + z * p[6])))));
	const long double s = q[0] + z * (q[1] + z * (q[2] + z * (q[3] + z * (q[4] + z * (q[5] + z * (q[6] + z))))));
	return (0.375 + z * r / s) / x;
}


LIB_FUNC MATH_FUNC long double __ieee754_j1l(const long double num) {
	long double z, c, s, u, v, x = num;
	uint32_t se;
	GET_LDOUBLE_EXP(se, x);
	const int32_t ix = se & 0x7fff;
	if (PREDICT_UNLIKELY(ix >= 0x7fff)) { return 1.0L / x; }
	long double y = fabsl(x);
	if (ix >= 0x4000) {
		sincosl(y, &s, &c);
		long double ss = -s - c;
		long double cc = s - c;
		if (ix < 0x7ffe) {
			z = cosl(y + y);
			if ((s * c) > 0.0L) { cc = z / ss; }
			else { ss = z / cc; }
		}
		if (PREDICT_UNLIKELY(ix > 0x4080)) { z = (5.6418958354775628694807945156077258584405E-1L * cc) / __ieee754_sqrtl(y); }
		else {
			u = ponel(y);
			v = qonel(y);
			z = 5.6418958354775628694807945156077258584405E-1L * (u * cc - v * ss) / __ieee754_sqrtl(y);
		}
		if (se & 0x8000) { return -z; }
		else { return z; }
	}
	if (PREDICT_UNLIKELY(ix < 0x3fde)) {
		if (HUGEL + x > 1.0L) {
			long double ret = 0.5 * x;
			math_check_force_underflow(ret);
			if (ret == 0 && x != 0) { set_errno(ERANGE); }
			return ret;
		}
	}
	z = x * x;
	const long double r = z * (-9.647406112428107954753770469290757756814E+7L + z * (2.686288565865230690166454005558203955564E+6L + z * (-3.689682683905671185891885948692283776081E+4L + z * (2.195031194229176602851429567792676658146E+2L + z * -5.124499848728030297902028238597308971319E-1L))));
	s = 1.543584977988497274437410333029029035089E+9L + z * (2.133542369567701244002565983150952549520E+7L + z * (1.394077011298227346483732156167414670520E+5L + z * (5.252401789085732428842871556112108446506E+2L + z)));
	return (x * 0.5L + (r * x) / s);
}
#define __j1l_finite(x)   __ieee754_j1l((x))


LIB_FUNC MATH_FUNC long double __ieee754_y1l(const long double num) {
	long double z, s, c, u, v, x = num;
	uint32_t se, i0, i1;
	GET_LDOUBLE_WORDS(se, i0, i1, x);
	const int32_t ix = se & 0x7fff;
	if (PREDICT_UNLIKELY(se & 0x8000)) { return 0.0L / (0.0L * x); }
	else if (PREDICT_UNLIKELY(ix >= 0x7fff)) { return 1.0L / (x + x * x); }
	else if (PREDICT_UNLIKELY((i0 | i1) == 0)) { return -HUGE_VALL + x; }
	else if (ix >= 0x4000) {
		sincosl(x, &s, &c);
		long double ss = -s - c;
		long double cc = s - c;
		if (ix < 0x7ffe) {
			z = cosl(x + x);
			if ((s * c) > 0.0L) { cc = z / ss; }
			else { ss = z / cc; }
		}
		if (PREDICT_UNLIKELY(ix > 0x4080)) { z = (5.6418958354775628694807945156077258584405E-1L * ss) / __ieee754_sqrtl(x); }
		else {
			u = ponel(x);
			v = qonel(x);
			z = 5.6418958354775628694807945156077258584405E-1L * (u * ss + v * cc) / __ieee754_sqrtl(x);
		}
		return z;
	}
	if (PREDICT_UNLIKELY(ix <= 0x3fbe)) {
		z = -6.3661977236758134307553505349005744813784E-1L / x;
		if (isinf(z)) { set_errno(ERANGE); }
		return z;
	}
	z = x * x;
	u = -5.908077186259914699178903164682444848615E+10L + z * (1.546219327181478013495975514375773435962E+10L + z * (-6.438303331169223128870035584107053228235E+8L + z * (9.708540045657182600665968063824819371216E+6L + z * (-6.138043997084355564619377183564196265471E+4L + z * 1.418503228220927321096904291501161800215E+2L))));
	v = 3.013447341682896694781964795373783679861E+11L + z * (4.669546565705981649470005402243136124523E+9L + z * (3.595056091631351184676890179233695857260E+7L + z * (1.761554028569108722903944659933744317994E+5L + z * (5.668480419646516568875555062047234534863E+2L + z))));
	return (x * (u / v) + 6.3661977236758134307553505349005744813784E-1L * (__ieee754_j1l(x) * __ieee754_logl(x) - 1.0L / x));
}
#define __y1l_finite(x)   __ieee754_y1l((x))


LIB_FUNC MATH_FUNC long double __ieee754_jnl(const int n, const long double x) {
	uint32_t se, i0, i1;
	int32_t i;
	long double a, b, temp, di, ret, z, w;
	GET_LDOUBLE_WORDS(se, i0, i1, x);
	const int32_t ix = se & 0x7fff;
	if (PREDICT_UNLIKELY((ix == 0x7fff) && ((i0 & 0x7fffffff) != 0))) { return x + x; }
	if (n < 0) {
		n = -n;
		x = -x;
		se ^= 0x8000;
	}
	if (n == 0) { return __ieee754_j0l(x); }
	else if (n == 1) { return __ieee754_j1l(x); }
	const int32_t sgn = (n & 1) & (se >> 15);
	x = fabsl(x);
	// SET_RESTORE_ROUNDL(FE_TONEAREST);
	if (PREDICT_UNLIKELY((ix | i0 | i1) == 0 || ix >= 0x7fff)) { return sgn == 1 ? -0.0L : 0.0L; }
	else if ((long double) n <= x) {
		if (ix >= 0x412d) {
			long double s, c;
			sincosl(x, &s, &c);
			switch (n & 3) {
				case 0:
					temp = c + s;
					break;
				case 1:
					temp = -c + s;
					break;
				case 2:
					temp = -c - s;
					break;
				default:  // 3
					temp = c - s;
					break;
			}
			b = 5.64189583547756286948079E-1L * temp / __ieee754_sqrtl(x);
		} else {
			a = __ieee754_j0l(x);
			b = __ieee754_j1l(x);
			for (i = 1; i < n; i++) {
				temp = b;
				b = b * ((long double)(i + i) / x) - a;
				a = temp;
			}
		}
	} else {
		if (ix < 0x3fde) {
			if (n >= 400) { b = 0.0L; }
			else {
				temp = x * 0.5;
				b = temp;
				for (a = 1.0L, i = 2; i <= n; i++) {
					a *= (long double) i;
					b *= temp;
				}
				b /= a;
			}
		} else {
			long double t, v, tmp;
			w = (n + n) / x;
			long double h = 2.0L / x;
			long double q0 = w;
			z = w + h;
			long double q1 = w * z - 1.0L;
			int32_t k = 1;
			while (q1 < 1.0E+11L) {
				k += 1;
				z += h;
				tmp = z * q1 - q0;
				q0 = q1;
				q1 = tmp;
			}
			int32_t m = n + n;
			for (t = 0.0L, i = 2 * (n + k); i >= m; i -= 2) { t = 1.0L / (i / x - t); }
			a = t;
			b = 1.0L;
			tmp = n;
			v = 2.0L / x;
			tmp = tmp * __ieee754_logl(fabsl(v * tmp));
			if (tmp < 1.1356523406294143949491931077970765006170E+4L) {
				for (i = n - 1, di = (long double)(i + i); i > 0; i--) {
					temp = b;
					b *= di;
					b = b / x - a;
					a = temp;
					di -= 2.0L;
				}
			} else {
				for (i = n - 1, di = (long double)(i + i); i > 0; i--) {
					temp = b;
					b *= di;
					b = b / x - a;
					a = temp;
					di -= 2.0L;
					if (b > 1e100L) {
						a /= b;
						t /= b;
						b = 1.0L;
					}
				}
			}
			z = __ieee754_j0l(x);
			w = __ieee754_j1l(x);
			if (fabsl(z) >= fabsl(w)) { b = (t * z / b); }
			else { b = (t * w / a); }
		}
	}
	long double ret = (sgn == 1 ? -b : b);
	if (ret == 0) {
		ret = copysignl(LDBL_MIN, ret) * LDBL_MIN;
		set_errno(ERANGE);
	}  // else { math_check_force_underflow(ret); }
	return ret;
}
#define __jnl_finite(n, x)   __ieee754_jnl((n), (x))


LIB_FUNC MATH_FUNC long double __ieee754_ynl(const int n, const long double x) {
	uint32_t se, i0, i1;
	long double a, b, temp, ret;
	GET_LDOUBLE_WORDS(se, i0, i1, x);
	const int32_t ix = se & 0x7fff;
	if (PREDICT_UNLIKELY((ix == 0x7fff) && ((i0 & 0x7fffffff) != 0))) { return x + x; }
	else if (PREDICT_UNLIKELY((((uint32_t)ix) | i0 | i1) == 0)) { return ((n < 0 && (n & 1) != 0) ? 1.0L : -1.0L) / 0.0L; }
	else if (PREDICT_UNLIKELY(se & 0x8000)) { return 0.0L / (0.0L * x); }
	const int32_t sign = 1;
	int32_t i;
	if (n < 0) {
		n = -n;
		sign = 1 - ((n & 1) << 1);
	}
	if (n == 0) { return __ieee754_y0l(x); }
	// SET_RESTORE_ROUNDL(FE_TONEAREST);
	if (n == 1) {
		ret = sign * __ieee754_y1l(x);
		goto goto_ieee754_ynl_out;
	}
	else if (PREDICT_UNLIKELY(ix == 0x7fff)) { return 0.0L; }
	else if (ix >= 0x412d) {
		long double s, c;
		sincosl(x, &s, &c);
		switch (n & 3) {
			case 0:
				temp = s - c;
				break;
			case 1:
				temp = -s - c;
				break;
			case 2:
				temp = -s + c;
				break;
			default:  // 3
				temp = s + c;
				break;
		}
		b = 5.64189583547756286948079E-1L * temp / __ieee754_sqrtl(x);
	} else {
		a = __ieee754_y0l(x);
		b = __ieee754_y1l(x);
		GET_LDOUBLE_WORDS(se, i0, i1, b);
		for (i = 1; (i < n) && (se != UINT32_MAX); i++) {
			temp = b;
			b = ((long double)(i + i) / x) * b - a;
			GET_LDOUBLE_WORDS(se, i0, i1, b);
			a = temp;
		}
	}
	if (!isfinitel(b)) { set_errno(ERANGE); }
	if (sign > 0) { ret = b; }
	else { ret = -b; }
goto_ieee754_ynl_out:
	if (isinf(ret)) { ret = copysignl(LDBL_MAX, ret) * LDBL_MAX; }
	return ret;
}
#define __ynl_finite(n, x)   __ieee754_ynl((n), (x))


#elif LDBL_EQ_FLOAT128


LIB_FUNC MATH_FUNC long double __ieee754_j0l(const long double num) {
	long double x = num;
	if (!isfinitel(x)) {
		if (x != x) { return x; }
		return 0.0L;
	} else if (x == 0.0L) { return 1.0L; }
	const long double xx = fabsl(x);
	long double z, p, q, c, s;
	if (xx <= 2.0L) {
		if (xx < 0x1.0P-57L) { return 1.0L; }
		z = xx * xx;
		p = z * z * neval(z, J0_2N_j0l, 6) / deval(z, J0_2D_j0l, 6);
		p -= 0.25L * z;
		p += 1.0L;
		return p;
	}
	sincosl(xx, &s, &c);
	long double ss = s - c;
	long double cc = s + c;
	if (xx <= LDBL_MAX / 2.0L) {
		z = -cosl(xx + xx);
		if ((s * c) < 0) { cc = z / ss; }
		else { ss = z / cc; }
	}
	if (xx > 0x1.0P+256L) { return 5.6418958354775628694807945156077258584405E-1L * cc / __ieee754_sqrtl(xx); }
	const long double xinv = 1.0L / xx;
	z = xinv * xinv;
	if (xinv <= 0.25L) {
		if (xinv <= 0.125L) {
			if (xinv <= 0.0625L) {
				p = neval(z, P16_IN_j0l, 9) / deval(z, P16_ID_j0l, 9);
				q = neval(z, Q16_IN_j0l, 10) / deval(z, Q16_ID_j0l, 9);
			} else {
				p = neval(z, P8_16N_j0l, 10) / deval(z, P8_16D_j0l, 10);
				q = neval(z, Q8_16N_j0l, 11) / deval(z, Q8_16D_j0l, 11);
			}
		} else if (xinv <= 0.1875L) {
			p = neval(z, P5_8N_j0l, 10) / deval(z, P5_8D_j0l, 9);
			q = neval(z, Q5_8N_j0l, 10) / deval(z, Q5_8D_j0l, 10);
		} else {
			p = neval(z, P4_5N_j0l, 9) / deval(z, P4_5D_j0l, 9);
			q = neval(z, Q4_5N_j0l, 10) / deval(z, Q4_5D_j0l, 9);
		}
	} else {
		if (xinv <= 0.375L) {
			if (xinv <= 0.3125L) {
				p = neval(z, P3r2_4N_j0l, 9) / deval(z, P3r2_4D_j0l, 9);
				q = neval(z, Q3r2_4N_j0l, 10) / deval(z, Q3r2_4D_j0l, 9);
			} else {
				p = neval(z, P2r7_3r2N_j0l, 9) / deval(z, P2r7_3r2D_j0l, 8);
				q = neval(z, Q2r7_3r2N_j0l, 9) / deval(z, Q2r7_3r2D_j0l, 9);
			}
		} else if (xinv <= 0.4375L) {
			p = neval(z, P2r3_2r7N_j0l, 9) / deval(z, P2r3_2r7D_j0l, 8);
			q = neval(z, Q2r3_2r7N_j0l, 9) / deval(z, Q2r3_2r7D_j0l, 8);
		} else {
			p = neval(z, P2_2r3N_j0l, 8) / deval(z, P2_2r3D_j0l, 8);
			q = neval(z, Q2_2r3N_j0l, 9) / deval(z, Q2_2r3D_j0l, 8);
		}
	}
	p = 1.0L + z * p;
	q = z * xinv * q;
	q = q - 0.125L * xinv;
	z = 5.6418958354775628694807945156077258584405E-1L * (p * cc - q * ss) / __ieee754_sqrtl(xx);
	return z;
}
#define __j0l_finite(x)   __ieee754_j0l((x))


LIB_FUNC MATH_FUNC long double __ieee754_y0l(const long double num) {
	long double x = num;
	if (!isfinitel(x)) {
		if (x != x) { return x; }
		return 0.0L;
	} else if (x <= 0.0L) {
		if (x < 0.0L) { return (0.0L / (0.0L * x)); }
		return ((-(HUGE_VALL)) + x);
	}
	const long double xx = fabsl(x);
	long double z, p, q, c, s;
	if (xx <= 0x1.0P-57) { return -7.3804295108687225274343927948483016310862E-2L + 6.3661977236758134307553505349005744813784E-1L * __ieee754_logl(x); }
	else if (xx <= 2.0L) {
		z = xx * xx;
		p = neval(z, Y0_2N_y0l, 7) / deval(z, Y0_2D_y0l, 7);
		p = 6.3661977236758134307553505349005744813784E-1L * __ieee754_logl(x) * __ieee754_j0l(x) + p;
		return p;
	}
	sincosl(x, &s, &c);
	long double ss = s - c;
	long double cc = s + c;
	if (xx <= LDBL_MAX / 2.0L) {
		z = -cosl(x + x);
		if ((s * c) < 0) { cc = z / ss; }
		else { ss = z / cc; }
	}
	if (xx > 0x1.0P+256L) { return 5.6418958354775628694807945156077258584405E-1L * ss / __ieee754_sqrtl(x); }
	const long double xinv = 1.0L / xx;
	z = xinv * xinv;
	if (xinv <= 0.25L) {
		if (xinv <= 0.125L) {
			if (xinv <= 0.0625L) {
				p = neval(z, P16_IN_j0l, 9) / deval(z, P16_ID_j0l, 9);
				q = neval(z, Q16_IN_j0l, 10) / deval(z, Q16_ID_j0l, 9);
			} else {
				p = neval(z, P8_16N_j0l, 10) / deval(z, P8_16D_j0l, 10);
				q = neval(z, Q8_16N_j0l, 11) / deval(z, Q8_16D_j0l, 11);
			}
		} else if (xinv <= 0.1875L) {
			p = neval(z, P5_8N_j0l, 10) / deval(z, P5_8D_j0l, 9);
			q = neval(z, Q5_8N_j0l, 10) / deval(z, Q5_8D_j0l, 10);
		} else {
			p = neval(z, P4_5N_j0l, 9) / deval(z, P4_5D_j0l, 9);
			q = neval(z, Q4_5N_j0l, 10) / deval(z, Q4_5D_j0l, 9);
		}
	} else {
		if (xinv <= 0.375L) {
			if (xinv <= 0.3125L) {
				p = neval(z, P3r2_4N_j0l, 9) / deval(z, P3r2_4D_j0l, 9);
				q = neval(z, Q3r2_4N_j0l, 10) / deval(z, Q3r2_4D_j0l, 9);
			} else {
				p = neval(z, P2r7_3r2N_j0l, 9) / deval(z, P2r7_3r2D_j0l, 8);
				q = neval(z, Q2r7_3r2N_j0l, 9) / deval(z, Q2r7_3r2D_j0l, 9);
			}
		} else if (xinv <= 0.4375L) {
			p = neval(z, P2r3_2r7N_j0l, 9) / deval(z, P2r3_2r7D_j0l, 8);
			q = neval(z, Q2r3_2r7N_j0l, 9) / deval(z, Q2r3_2r7D_j0l, 8);
		} else {
			p = neval(z, P2_2r3N_j0l, 8) / deval(z, P2_2r3D_j0l, 8);
			q = neval(z, Q2_2r3N_j0l, 9) / deval(z, Q2_2r3D_j0l, 8);
		}
	}
	p = 1.0L + z * p;
	q = z * xinv * q;
	q = q - 0.125L * xinv;
	z = 5.6418958354775628694807945156077258584405E-1L * (p * ss + q * cc) / __ieee754_sqrtl(x);
	return z;
}
#define __y0l_finite(x)   __ieee754_y0l((x))


LIB_FUNC MATH_FUNC long double __ieee754_j1l(const long double num) {
	long double x = num;
	if (!isfinitel(x)) {
		if (x != x) { return x; }
		return 0.0L;
	} else if (x == 0.0L) { return x; }
	const long double xx = fabsl(x);
	long double z, p, q, c, s;
	if (xx <= 0x1.0P-58L) {
		const long double ret = x * 0.5L;
		// math_check_force_underflow(ret);
		if (ret == 0) { set_errno(ERANGE); }
		return ret;
	} else if (xx <= 2.0L) {
		z = xx * xx;
		p = xx * z * neval(z, J0_2N_j1l, 6) / deval(z, J0_2D_j1l, 6);
		p += 0.5L * xx;
		if (x < 0) { p = -p; }
		return p;
	}
	sincosl(xx, &s, &c);
	long double ss = -s - c;
	long double cc = s - c;
	if (xx <= LDBL_MAX / 2.0L) {
		z = cosl(xx + xx);
		if ((s * c) > 0) { cc = z / ss; }
		else { ss = z / cc; }
	}
	if (xx > 0x1.0P+256L) {
		z = 5.6418958354775628694807945156077258584405E-1L * cc / __ieee754_sqrtl(xx);
		if (x < 0) { z = -z; }
		return z;
	}
	const long double xinv = 1.0L / xx;
	z = xinv * xinv;
	if (xinv <= 0.25L) {
		if (xinv <= 0.125L) {
			if (xinv <= 0.0625L) {
				p = neval(z, P16_IN_j1l, 9) / deval(z, P16_ID_j1l, 9);
				q = neval(z, Q16_IN_j1l, 10) / deval(z, Q16_ID_j1l, 9);
			} else {
				p = neval(z, P8_16N_j1l, 11) / deval(z, P8_16D_j1l, 10);
				q = neval(z, Q8_16N_j1l, 11) / deval(z, Q8_16D_j1l, 11);
			}
		} else if (xinv <= 0.1875L) {
			p = neval(z, P5_8N_j1l, 10) / deval(z, P5_8D_j1l, 10);
			q = neval(z, Q5_8N_j1l, 10) / deval(z, Q5_8D_j1l, 10);
		} else {
			p = neval(z, P4_5N_j1l, 10) / deval(z, P4_5D_j1l, 9);
			q = neval(z, Q4_5N_j1l, 10) / deval(z, Q4_5D_j1l, 9);
		}
	} else {
		if (xinv <= 0.375L) {
			if (xinv <= 0.3125L) {
				p = neval(z, P3r2_4N_j1l, 9) / deval(z, P3r2_4D_j1l, 9);
				q = neval(z, Q3r2_4N_j1l, 9) / deval(z, Q3r2_4D_j1l, 9);
			} else {
				p = neval(z, P2r7_3r2N_j1l, 9) / deval(z, P2r7_3r2D_j1l, 8);
				q = neval(z, Q2r7_3r2N_j1l, 9) / deval(z, Q2r7_3r2D_j1l, 9);
			}
		} else if (xinv <= 0.4375L) {
			p = neval(z, P2r3_2r7N_j1l, 9) / deval(z, P2r3_2r7D_j1l, 8);
			q = neval(z, Q2r3_2r7N_j1l, 9) / deval(z, Q2r3_2r7D_j1l, 8);
		} else {
			p = neval(z, P2_2r3N_j1l, 8) / deval(z, P2_2r3D_j1l, 8);
			q = neval(z, Q2_2r3N_j1l, 9) / deval(z, Q2_2r3D_j1l, 8);
		}
	}
	p = 1.0L + z * p;
	q = z * q;
	q = q * xinv + 0.375L * xinv;
	z = 5.6418958354775628694807945156077258584405E-1L * (p * cc - q * ss) / __ieee754_sqrtl(xx);
	if (x < 0) { z = -z; }
	return z;
}
#define __j1l_finite(x)   __ieee754_j1l((x))


LIB_FUNC MATH_FUNC long double __ieee754_y1l(const long double num) {
	long double x = num;
	if (!isfinitel(x)) {
		if (x != x) { return x; }
		return 0.0L;
	} else if (x <= 0.0L) {
		if (x < 0.0L) { return (0.0L / (0.0L * x)); }
		return -HUGE_VALL + x;
	}
	const long double xx = fabsl(x);
	long double z, p, q, c, s;
	if (xx <= 0x1.0P-114) {
		z = -6.3661977236758134307553505349005744813784E-1L / x;
		if (__isinfl(z)) { set_errno(ERANGE); }
		return z;
	} else if (xx <= 2.0L) {
		// SET_RESTORE_ROUNDL(FE_TONEAREST);
		z = xx * xx;
		p = xx * neval(z, Y0_2N_y1l, 7) / deval(z, Y0_2D_y1l, 7);
		p = -6.3661977236758134307553505349005744813784E-1L / xx + p;
		p = 6.3661977236758134307553505349005744813784E-1L * __ieee754_logl(x) * __ieee754_j1l(x) + p;
		return p;
	}
	sincosl(xx, &s, &c);
	long double ss = -s - c;
	long double cc = s - c;
	if (xx <= LDBL_MAX / 2.0L) {
		z = cosl(xx + xx);
		if ((s * c) > 0) { cc = z / ss; }
		else { ss = z / cc; }
	}
	if (xx > 0x1.0P+256L) { return 5.6418958354775628694807945156077258584405E-1L * ss / __ieee754_sqrtl(xx); }
	const long double xinv = 1.0L / xx;
	z = xinv * xinv;
	if (xinv <= 0.25L) {
		if (xinv <= 0.125L) {
			if (xinv <= 0.0625L) {
				p = neval(z, P16_IN_j1l, 9) / deval(z, P16_ID_j1l, 9);
				q = neval(z, Q16_IN_j1l, 10) / deval(z, Q16_ID_j1l, 9);
			} else {
				p = neval(z, P8_16N_j1l, 11) / deval(z, P8_16D_j1l, 10);
				q = neval(z, Q8_16N_j1l, 11) / deval(z, Q8_16D_j1l, 11);
			}
		} else if (xinv <= 0.1875L) {
			p = neval(z, P5_8N_j1l, 10) / deval(z, P5_8D_j1l, 10);
			q = neval(z, Q5_8N_j1l, 10) / deval(z, Q5_8D_j1l, 10);
		} else {
			p = neval(z, P4_5N_j1l, 10) / deval(z, P4_5D_j1l, 9);
			q = neval(z, Q4_5N_j1l, 10) / deval(z, Q4_5D_j1l, 9);
		}
	} else {
		if (xinv <= 0.375L) {
			if (xinv <= 0.3125L) {
				p = neval(z, P3r2_4N_j1l, 9) / deval(z, P3r2_4D_j1l, 9);
				q = neval(z, Q3r2_4N_j1l, 9) / deval(z, Q3r2_4D_j1l, 9);
			} else {
				p = neval(z, P2r7_3r2N_j1l, 9) / deval(z, P2r7_3r2D_j1l, 8);
				q = neval(z, Q2r7_3r2N_j1l, 9) / deval(z, Q2r7_3r2D_j1l, 9);
			}
		} else if (xinv <= 0.4375L) {
			p = neval(z, P2r3_2r7N_j1l, 9) / deval(z, P2r3_2r7D_j1l, 8);
			q = neval(z, Q2r3_2r7N_j1l, 9) / deval(z, Q2r3_2r7D_j1l, 8);
		} else {
			p = neval(z, P2_2r3N_j1l, 8) / deval(z, P2_2r3D_j1l, 8);
			q = neval(z, Q2_2r3N_j1l, 9) / deval(z, Q2_2r3D_j1l, 8);
		}
	}
	p = 1.0L + z * p;
	q = z * q;
	q = q * xinv + 0.375L * xinv;
	z = 5.6418958354775628694807945156077258584405E-1L * (p * ss + q * cc) / __ieee754_sqrtl(xx);
	return z;
}
#define __y1l_finite(x)   __ieee754_y1l((x))


LIB_FUNC MATH_FUNC long double __ieee754_jnl(const int num, const long double numx) {
	int32_t i, n = (int32_t)num;
	long double a, b, temp, di, ret, z, w, x = numx;
	long_double_shape_t u = { .value = x };
	uint32_t se = u.uparts32.w0;
	const int32_t ix = se & 0x7fffffff;
	if (ix >= 0x7fff0000 && ((u.uparts32.w0 & 0xffff) | u.uparts32.w1 | u.uparts32.w2 | u.uparts32.w3)) { return x + x; }
	if (n < 0) {
		n = -n;
		x = -x;
		se ^= 0x80000000;
	} else if (n == 0) { return __ieee754_j0l(x); }
	else if (n == 1) { return __ieee754_j1l(x); }
	const int32_t sgn = (n & 1) & (se >> 31);
	x = fabsl(x);
	// SET_RESTORE_ROUNDL(FE_TONEAREST);
	if (x == 0.0L || ix >= 0x7fff0000) { return sgn == 1 ? -0.0L : 0.0L; }
	else if ((long double)n <= x) {
		if (ix >= 0x412d0000) {
			long double s, c;
			sincosl(x, &s, &c);
			switch (n & 3) {
				case 0:
					temp = c + s;
					break;
				case 1:
					temp = -c + s;
					break;
				case 2:
					temp = -c - s;
					break;
				default:  // 3
					temp = c - s;
					break;
			}
			b = 5.6418958354775628694807945156077258584405E-1L * temp / __ieee754_sqrtl(x);
		} else {
			a = __ieee754_j0l(x);
			b = __ieee754_j1l(x);
			for (i = 1; i < n; i++) {
				temp = b;
				b = b * ((long double)(i + i) / x) - a;
				a = temp;
			}
		}
	} else {
		if (ix < 0x3fc60000) {
			if (n >= 400) { b = 0.0L; }
			else {
				temp = x * 0.5;
				b = temp;
				for (a = 1.0L, i = 2; i <= n; i++) {
					a *= (long double)i;
					b *= temp;
				}
				b = b / a;
			}
		} else {
			long double t, v, tmp;
			int32_t k, m;
			w = (n + n) / (long double)x;
			long double h = 2.0L / (long double)x;
			long double q0 = w;
			z = w + h;
			long double q1 = w * z - 1.0L;
			k = 1;
			while (q1 < 1.0E+17L) {
				k += 1;
				z += h;
				tmp = z * q1 - q0;
				q0 = q1;
				q1 = tmp;
			}
			m = n + n;
			for (t = 0.0L, i = 2 * (n + k); i >= m; i -= 2) { t = 1.0L / (i / x - t); }
			a = t;
			b = 1.0L;
			tmp = n;
			v = 2.0L / x;
			tmp = tmp * __ieee754_logl(fabsl(v * tmp));
			if (tmp < 1.1356523406294143949491931077970765006170E+4L) {
				for (i = n - 1, di = (long double)(i + i); i > 0; i--) {
					temp = b;
					b *= di;
					b = b / x - a;
					a = temp;
					di -= 2.0L;
				}
			} else {
				for (i = n - 1, di = (long double)(i + i); i > 0; i--) {
					temp = b;
					b *= di;
					b = b / x - a;
					a = temp;
					di -= 2.0L;
					if (b > 1e100L) {
						a /= b;
						t /= b;
						b = 1.0L;
					}
				}
			}
			z = __ieee754_j0l(x);
			w = __ieee754_j1l(x);
			if (fabsl(z) >= fabsl(w)) { b = (t * z / b); }
			else { b = (t * w / a); }
		}
	}
	if (sgn == 1) { ret = -b; }
	else { ret = b; }
	if (ret == 0) {
		ret = copysignl(LDBL_MIN, ret) * LDBL_MIN;
		set_errno(ERANGE);
	}  // else { math_check_force_underflow(ret); }
	return ret;
}
#define __jnl_finite(n, x)   __ieee754_jnl((n), (x))


LIB_FUNC MATH_FUNC long double __ieee754_ynl(const int num, const long double numx) {
	int32_t i, n = (int32_t)num;
	long double a, b, temp, ret, x = numx;
	long_double_shape_t u = { .value = x };
	uint32_t se = u.uparts32.w0;
	const int32_t ix = se & 0x7fffffff;
	if (ix >= 0x7fff0000 && ((u.uparts32.w0 & 0xffff) | u.uparts32.w1 | u.uparts32.w2 | u.uparts32.w3)) { return x + x; }
	if (x <= 0.0L) {
		if (x == 0.0L) { return ((n < 0 && (n & 1) != 0) ? 1.0L : -1.0L) / 0.0L; }
		else if (se & 0x80000000) { return 0.0L / (0.0L * x); }
	}
	int32_t sign = 1;
	if (n < 0) {
		n = -n;
		sign = 1 - ((n & 1) << 1);
	}
	if (n == 0) { return __ieee754_y0l(x); } {
		// SET_RESTORE_ROUNDL(FE_TONEAREST);
		if (n == 1) {
			ret = sign * __ieee754_y1l(x);
			goto goto_ieee754_ynl_out;
		}
		if (ix >= 0x7fff0000) { return 0.0L; }
		else if (ix >= 0x412d0000) {
			long double s, c;
			sincosl(x, &s, &c);
			switch (n & 3) {
				case 0:
					temp = s - c;
					break;
				case 1:
					temp = -s - c;
					break;
				case 2:
					temp = -s + c;
					break;
				default:  // 3
					temp = s + c;
					break;
			}
			b = 5.6418958354775628694807945156077258584405E-1L * temp / __ieee754_sqrtl(x);
		} else {
			a = __ieee754_y0l(x);
			b = __ieee754_y1l(x);
			u.value = b;
			se = u.uparts32.w0 & 0xffff0000;
			for (i = 1; i < n && se != 0xffff0000; i++) {
				temp = b;
				b = ((long double)(i + i) / x) * b - a;
				u.value = b;
				se = u.uparts32.w0 & 0xffff0000;
				a = temp;
			}
		}
		if (!isfinitel(b)) { set_errno(ERANGE); }
		if (sign > 0) { ret = b; }
		else { ret = -b; }
	}
goto_ieee754_ynl_out:
	if (__isinfl(ret)) { ret = copysignl(LDBL_MAX, ret) * LDBL_MAX; }
	return ret;
}
#define __ynl_finite(n, x)   __ieee754_ynl((n), (x))


#else
#   error   "Add __ieee754_jnl() for the target platform's long double!"
#endif  // j1l, jnl, y1l, ynl, & others


LIB_FUNC MATH_FUNC float jnf(const int n, const float x) {
	return __ieee754_jnf(n, x);
}
#define __jnf(n, x) jnf((n), (x))
#define ___jnf(n, x) jnf((n), (x))


LIB_FUNC MATH_FUNC float ynf(const int n, const float x) {
	return __ieee754_ynf(n, x);
}
#define __ynf(n, x) ynf((n), (x))
#define ___ynf(n, x) ynf((n), (x))


LIB_FUNC MATH_FUNC double jn(const int n, const double x) {
	return __ieee754_jn(n, x);
}
#define __jn(n, x) jn((n), (x))


LIB_FUNC MATH_FUNC double yn(const int n, const double x) {
	return __ieee754_yn(n, x);
}
#define __yn(n, x) yn((n), (x))


#if SUPPORTS_LONG_DOUBLE


LIB_FUNC long double __jnl(int n, long double x) {
	return __ieee754_jnl(n, x);
}
#define __jnl(n, x) jnl((n), (x))
#define ___jnl(n, x) jnl((n), (x))


LIB_FUNC long double __ynl(int n, long double x) {
	return __ieee754_ynl(n, x);
}
#define __ynf(n, x) ynf((n), (x))
#define ___ynf(n, x) ynf((n), (x))


LIB_FUNC long double __P_bessel(const int My, double* x) {
	long double Sum = 0.0L, Fact = 1.0L;
	const long double z182 = (-0.015625L / (x[0] * x[0]));
	register int i;
	for (i = 1; ; i += 2) {
		Fact *= ((long)(My - (i + i - 1) * (i + i - 1))) * ((long)(My - (i + i + 1) * (i + i + 1))) * z182 / (i * (i + 1));
		if (EXPL(Fact) < 0x3fff - 53) { break; }
		Sum += Fact;
	}
	return 1.0 + Sum;
}


LIB_FUNC long double __Q_bessel(const int My, double* x) {
	long double Fact = (My - 1) / x[0] * 0.125;
	long double Sum = Fact;
	const long double z182 = -0.015625 / (x[0] * x[0]);
	register int i;
	for (i = 2; ; i += 2) {
		Fact *= ((long)(My - (i + i - 1) * (i + i - 1))) * ((long)(My - (i + i + 1) * (i + i + 1))) * z182 / (i * (i + 1));
		if (EXPL(Fact) < 0x3fff - 53) { break; }
		Sum += Fact;
	}
	return Sum;
}


LIB_FUNC long double ___jn(const int n, double* x) {
	long double Sum, Fact, y, Xi;
	register int i;
	double xx;
	int My;
	if (n < 0) { return n & 1 ? ___jn(-n, x) : -___jn(-n, x); }
	if ((x[0] >= 17.7 + 0.0144 * (n * n))) {
		Xi = (long double)(x[0] - M_PI * (n * 0.5 + 0.25));
		My = n * n << 2;
		return (long double)(((long double)sqrt(M_2_PI / x[0])) * (__P_bessel(My, x) * cosl(Xi) - __Q_bessel(My, x) * sinl(Xi)));
	}
	xx = x[0] * 0.5;
	Sum = 0.0L;
	Fact = 1.0L;
	y = -xx * xx;
	for (i = 1; i <= n; i++) { Fact *= xx / i; }
	for (i = 1; ; i++) {
		Sum += Fact;
		Fact *= y / (i * (n + i));
		if (EXPL(Sum) - EXPL(Fact) > 53 || (!EXPL(Fact))) { break; }
	}
	return Sum;
}


LIB_FUNC long double ___yn(const int n, double* x) {
	long double Sum1, Sum2, Fact1, Fact2, F1, F2, y, Xi;
	register int i;
	unsigned int My;
	if (EXPD(x[0]) == 0) { return -1.0L / 0.0L; }
	else if ((x[0] >= (n >= 32 ? 25.8 : (n < 8 ? (17.4 + 0.1 * n) : (16.2 + 0.3 * n))))) {
		Xi = x[0] - M_PI * (n * 0.5 + 0.25);
		My = (unsigned int)(n * (n << 2));
		return (long double)(((long double)sqrt(M_2_PI / x[0])) * (__P_bessel((int)My, x) * sinl(Xi) + __Q_bessel((int)My, x) * cosl(Xi)));
	}
	Sum1 = Sum2 = F1 = F2 = 0;
	const double xx = x[0] * 0.5;
	Fact1 = 1.0 / xx;
	Fact2 = 1.0;
	y = xx * xx;
	for (i = 1; i < n; i++) { Fact1 *= (n - i) / xx; }
	for (i = 1; i <= n; i++) {
		Sum1 += Fact1;
		if (i == n) { break; }
		Fact1 *= y / (i * (n - i));
	}
	for (i = 1; i <= n; i++) {
		Fact2 *= xx / i;
		F1 += 1.0 / i;
	}
	for (i = 1; ; i++) {
		Sum2 += Fact2 * (F1 + F2);
		Fact2 *= -y / (i * (n + i));
		if (EXPL(Sum2) - EXPL(Fact2) > 53 || (!EXPL(Fact2))) { break; }
		F1 += 1.0 / (n + i);
		F2 += 1.0 / i;
	}
	return (long double)(M_1_PI * (long double)(2.0 * (EULERS_CONSTANT + log(xx)) * ___jn(n, x) - Sum1 - Sum2));
}


#endif


LIB_FUNC double j0(double x) { return (double)___jn(0, &x); }
LIB_FUNC double j1(double x) { return (double)___jn(1, &x); }
LIB_FUNC double y0(double x) { return (double)___yn(0, &x); }
LIB_FUNC double y1(double x) { return (double)___yn(1, &x); }


LIB_FUNC MATH_FUNC double logfact(const long double num) {
	long double x = num, z = (2.0L * M_PI * num);
	const int e = (int)EXPL(x);
	const unsigned char list[8] = { 6, 4, 3, 3, 2, 2 };
	return (double)((logl(x) - 1) * x + 0.5L * logl(z) + __poly((1.0 / (double)(x * x)), (e < 0x4003 ? 10 : (e > 0x4008 ? 1 : list[e - 0x4003])), logfact_coeff) / x);
}


/** Return the logarithm of the absolute value of the gamma function */
LIB_FUNC MATH_FUNC double lgamma(const double x) {
	const double tmpk = floor(x);
	register int k = (int)tmpk;
	if (k >= 7) { return logfact(x - 1); }
	else if (k == x) {
		switch (k) {
			case 1 :
			case 2 :
				return 0.0;
			case 3 :
				return M_LN2;
			case 4 :
				return 1.791759469228055000858148560;
			case 5 :
				return 3.178053830347945619723759592;
			case 6 :
				return 4.787491742782045994244981560;
			default:
				return 1.0 / 0.0;
		}
	}
	long double w = 1, y = (long double)(x - k + 7.0 - 1);
	const long double z = logfact(y);
	for (k = 7 - k; k--;) { w *= y, y -= 1.0; }
	return (double)(z - logl(w));
}
#define gamma(val)   lgamma((val))
#define __gamma(val)   lgamma((val))
#define __lgamma(val)   lgamma((val))


#if SUPPORTS_LONG_DOUBLE
LIB_FUNC MATH_FUNC long double gauss(const double x) {
	const unsigned int i = (unsigned int)(x + 0.5);
	const double y = x * x;
	if (i > 150) { return 0.0; }
	else if (i > 10) { return 0.398942280401432686 * exp(-0.5 * y) / x * __poly(1.0 / y, 7, gauss_tab3); }
	else if (i > 0) { return -__poly((x - i), 31, gauss_tab2[i - 1]); }
	return 0.5 - x * __poly(y, 9, gauss_tab1);
}
#endif


LIB_FUNC MATH_FUNC float erfc1(const float x) {
	const float s = fabsf(x) - 1;
	const float P = -2.3621185683E-3F + s * (4.1485610604E-1F + s * (-3.7220788002E-1F + s * (3.1834661961E-1F + s * (-1.1089469492E-1F + s * (3.5478305072E-2F + s * -2.1663755178E-3F)))));
	const float Q = 1 + s * (1.0642088205E-1F + s * (5.4039794207E-1F + s * (7.1828655899E-2F + s * (1.2617121637E-1F + s * (1.3637083583E-2F + s * 1.1984500103E-2F)))));
	return 1 - 8.4506291151E-1F - P / Q;
}


LIB_FUNC MATH_FUNC float erfc2(const uint32_t inum, const float num) {
	if (inum < 0x3fa00000) { return erfc1(num); }
	float x = fabsf(num);
	const float s = 1 / (x * x);
	float R, S;
	if (inum < 0x4036db6d) {
		R = -9.8649440333E-3F + s * (-6.9385856390E-1F + s * (-1.0558626175E+1F + s * (-6.2375331879E+1F + s * (-1.6239666748E+2F + s * (-1.8460508728E+2F + s * (-8.1287437439E+1F + s * -9.8143291473F))))));
		S = 1.0f + s * (1.9651271820E+1F + s * (1.3765776062E+2F + s * (4.3456588745E+2F + s * (6.4538726807E+2F + s * (4.2900814819E+2F + s * (1.0863500214E+2F + s * (6.5702495575F + s * -6.0424413532E-2F)))))));
	} else {
		R = -9.8649431020E-3F + s * (-7.9928326607E-1F + s * (-1.7757955551E+1F + s * (-1.6063638306E+2F + s * (-6.3756646729E+2F + s * (-1.0250950928E+3F + s * -4.8351919556E+2F)))));
		S = 1.0F + s * (3.0338060379E+1F + s * (3.2579251099E+2F + s * (1.5367296143E+3F + s * (3.1998581543E+3F + s * (2.5530502930E+3F + s * (4.7452853394E+2F + s * -2.2440952301E+1F))))));
	}
	float z;
	uint32_t ix = inum;
	GET_FLOAT_UWORD(ix, x);
	SET_FLOAT_WORD(z, (ix & 0xffffe000));
	return expf((-z * z - 0.5625f)) * expf((z - x) * (z + x) + R / S) / x;
}


LIB_FUNC MATH_FUNC float erff(const float x) {
	uint32_t ix;
	GET_FLOAT_UWORD(ix, x);
	const int sign = (int)(ix >> 31);
	ix &= 0x7fffffff;
	float y;
	if (ix >= 0x7f800000) { return (float)(1 - (sign + sign) + (int)(1 / x)); }
	else if (ix < 0x3f580000) {
		if (ix < 0x31800000) { return 0.125F * (8 * x + 1.0270333290F * x); }
		const float z = x * x;
		const float r = 1.2837916613E-1F + z * (-3.2504209876E-1F + z * (-2.8481749818E-2F + z * (-5.7702702470E-3F + z * -2.3763017452E-5F)));
		const float s = 1 + z * (3.9791721106E-1F + z * (6.5022252500E-2F + z * (5.0813062117E-3F + z * (1.3249473704E-4F + z * -3.9602282413E-6F))));
		y = r / s;
		return x + x * y;
	}
	if (ix < 0x40c00000) { y = 1 - erfc2(ix, x); }
	else { y = 1 - 0x1.0P-120F; }
	return sign ? -y : y;
}


/** erf(x) is the probability a normal distributed event occures within the range [0,x]. erfc(x) is the probability a normal distributed event occures within the range [x,inf] */
LIB_FUNC MATH_FUNC double erf(const double x) {
	return (double)(x < 0.0 ? -0.5 + (double)gauss(-x) : 0.5 - (double)gauss(x));
}


LIB_FUNC MATH_FUNC float erfcf(const float x) {
	uint32_t ix;
	GET_FLOAT_UWORD(ix, x);
	int sign = (int)(ix >> 31);
	ix &= 0x7fffffff;
	if (ix >= 0x7f800000) { return (float)((sign + sign) + (int)(1 / x)); }
	else if (ix < 0x3f580000) {
		if (ix < 0x23800000) { return 1.0F - x; }
		const float z = x * x;
		const float s = 1.0F + z * (3.9791721106E-1F + z * (6.5022252500E-2F + z * (5.0813062117E-3F + z * (1.3249473704E-4F + z * -3.9602282413E-6F))));
		const float y = (1.2837916613E-1F + z * (-3.2504209876E-1F + z * (-2.8481749818E-2F + z * (-5.7702702470E-3F + z * -2.3763017452E-5F)))) / s;
		if (sign || ix < 0x3e800000) { return 1.0F - (x + x * y); }
		return 0.5F - (x - 0.5F + x * y);
	}
	if (ix < 0x41e00000) { return sign ? 2 - erfc2(ix, x) : erfc2(ix, x); }
	return (sign ? 2.0F - 0x1.0P-120F : 0x1.0P-120F * 0x1.0P-120F);
}


LIB_FUNC MATH_FUNC double erfc(const double x) {
	return (double)(x < 0.0 ? 1.0 - (double)gauss(-x) : (double)gauss(x));
}


#if LDBL_EQ_DBL


LIB_FUNC MATH_FUNC long double erfl(const long double x) {
	return erf(x);
}


LIB_FUNC MATH_FUNC long double erfcl(const long double x) {
	return erfc(x);
}


#elif IS_LDBL_X87


LIB_FUNC MATH_FUNC long double erfcl1(const long double x) {
	const long double s = fabsl(x) - 1;
	const long double Q = 4.559263722294508998149925774781887811255E+2L + s * (3.289248982200800575749795055149780689738E+2L + s * (2.846070965875643009598627918383314457912E+2L + s * (1.398715859064535039433275722017479994465E+2L + s * (6.060190733759793706299079050985358190726E+1L + s * (2.078695677795422351040502569964299664233E+1L + s * (4.641271134150895940966798357442234498546L + s))))));
	return 1 - 0.845062911510467529296875L - (-1.076952146179812072156734957705102256059L + s * (1.884814957770385593365179835059971587220E+2L + s * (-5.339153975012804282890066622962070115606E+1L + s * (4.435910679869176625928504532109635632618E+1L + s * (1.683219516032328828278557309642929135179E+1L + s * (-2.360236618396952560064259585299045804293L + s * (1.852230047861891953244413872297940938041L + s * 9.394994446747752308256773044667843200719E-2L))))))) / Q;
}


LIB_FUNC MATH_FUNC long double erfcl2(const uint32_t ix, const long double x) {
	if (ix < 0x3fffa000) { return erfcl1(x); }
	const long double _x = fabsl(x);
	const long double s = 1 / (_x * _x);
	long double R, S;
	if (ix < 0x4000b6db) {
		R = 1.363566591833846324191000679620738857234E-1L + s * (1.018203167219873573808450274314658434507E+1L + s * (1.862359362334248675526472871224778045594E+2L + s * (1.411622588180721285284945138667933330348E+3L + s * (5.088538459741511988784440103218342840478E+3L + s * (8.928251553922176506858267311750789273656E+3L + s * (7.264436000148052545243018622742770549982E+3L + s * (2.387492459664548651671894725748959751119E+3L + s * 2.220916652813908085449221282808458466556E+2L)))))));
		S = -1.382234625202480685182526402169222331847E+1L + s * (-3.315638835627950255832519203687435946482E+2L + s * (-2.949124863912936259747237164260785326692E+3L + s * (-1.246622099070875940506391433635999693661E+4L + s * (-2.673079795851665428695842853070996219632E+4L + s * (-2.880269786660559337358397106518918220991E+4L + s * (-1.450600228493968044773354186390390823713E+4L + s * (-2.874539731125893533960680525192064277816E+3L + s * (-1.402241261419067750237395034116942296027E+2L + s))))))));
	} else if (ix < 0x4001d555) {
		R = -4.869587348270494309550558460786501252369E-5L + s * (-4.030199390527997378549161722412466959403E-3L + s * (-9.434425866377037610206443566288917589122E-2L + s * (-9.319032754357658601200655161585539404155E-1L + s * (-4.273788174307459947350256581445442062291L + s * (-8.842289940696150508373541814064198259278L + s * (-7.069215249419887403187988144752613025255L + s * -1.401228723639514787920274427443330704764L))))));
		S = 4.936254964107175160157544545879293019085E-3L + s * (1.583457624037795744377163924895349412015E-1L + s * (1.850647991850328356622940552450636420484L + s * (9.927611557279019463768050710008450625415L + s * (2.531667257649436709617165336779212114570E+1L + s * (2.869752886406743386458304052862814690045E+1L + s * (1.182059497870819562441683560749192539345E+1L + s))))));
	} else {
		R = -8.299617545269701963973537248996670806850E-5L + s * (-6.243845685115818513578933902532056244108E-3L + s * (-1.141667210620380223113693474478394397230E-1L + s * (-7.521343797212024245375240432734425789409E-1L + s * (-1.765321928311155824664963633786967602934L + s * -1.029403473103215800456761180695263439188L))));
		S = 8.413244363014929493035952542677768808601E-3L + s * (2.065114333816877479753334599639158060979E-1L + s * (1.639064941530797583766364412782135680148L + s * (4.936788463787115555582319302981666347450L + s * (5.005177727208955487404729933261347679090L + s))));
	}
	union ldshape u = { .f = _x };
	u.i.m &= (-1ULL << 40);
	const long double z = u.f;
	return expl(-z * z - 0.5625) * expl((z - _x) * (z + _x) + R / S) / _x;
}


LIB_FUNC MATH_FUNC long double erfl(const long double x) {
	union ldshape u = { x };
	const uint32_t ix = (uint32_t)(((u.i.se & 0x7fffU) << 16) | (u.i.m >> 48));
	const int sign = (int)(u.i.se >> 15);
	if (ix >= 0x7fff0000) { return (1 - (sign + sign)) + 1 / x; }
	else if (ix < 0x3ffed800) {
		if (ix < 0x3fde8000) { return 0.125L * (8 * x + 1.0270333367641005911692712249723613735048L * x);   }
		const long double z = x * x;
		const long double s = 8.745588372054466262548908189000448124232E+6L + z * (3.746038264792471129367533128637019611485E+6L + z * (7.066358783162407559861156173539693900031E+5L + z * (7.448928604824620999413120955705448117056E+4L + z * (4.511583986730994111992253980546131408924E+3L + z * (1.368902937933296323345610240009071254014E+2L + z)))));
		const long double y = (1.122751350964552113068262337278335028553E+6L + z * (-2.808533301997696164408397079650699163276E+6L + z * (-3.314325479115357458197119660818768924100E+5L + z * (-6.848684465326256109712135497895525446398E+4L + z * (-2.657817695110739185591505062971929859314E+3L + z * -1.655310302737837556654146291646499062882E+2L))))) / s;
		return x + x * y;
	}
	long double y;
	if (ix < 0x4001d555) { y = 1 - erfcl2(ix, x); }
	else { y = 1 - 0x1.0P-16382L; }
	return sign ? -y : y;
}


LIB_FUNC MATH_FUNC long double erfcl(const long double x) {
	union ldshape u = { x };
	const uint32_t ix = (uint32_t)(((u.i.se & 0x7fffU) << 16) | (u.i.m >> 48));
	const int sign = u.i.se >> 15;
	if (ix >= 0x7fff0000) { return (sign + sign) + 1 / x; }
	else if (ix < 0x3ffed800) {
		if (ix < 0x3fbe0000) { return 1.0 - x; }
		const long double z = x * x;
		const long double s = 8.745588372054466262548908189000448124232E+6L + z * (3.746038264792471129367533128637019611485E+6L + z * (7.066358783162407559861156173539693900031E+5L + z * (7.448928604824620999413120955705448117056E+4L + z * (4.511583986730994111992253980546131408924E+3L + z * (1.368902937933296323345610240009071254014E+2L + z)))));
		const long double y = (r = 1.122751350964552113068262337278335028553E+6L + z * (-2.808533301997696164408397079650699163276E+6L + z * (-3.314325479115357458197119660818768924100E+5L + z * (-6.848684465326256109712135497895525446398E+4L + z * (-2.657817695110739185591505062971929859314E+3L + z * -1.655310302737837556654146291646499062882E+2L))))) / s;
		if (ix < 0x3ffd8000) { return 1.0 - (x + x * y); }
		return 0.5 - (x - 0.5 + x * y);
	}
	long double y;
	if (ix < 0x4005d600) { return (sign ? (2 - erfcl2(ix, x)) : erfcl2(ix, x)); }
	y = 0x1.0P-16382L;
	return sign ? 2 - y : y * y;
}


#endif


// FACTORIALS

/** Factorial (n!); return 0 on error */
LIB_FUNC MATH_FUNC unsigned long long factorial(const unsigned int num) {
#if IS_64
	if (num > 22U) { return 0; }
#elif IS_32
	if (num > 11U) { return 0; }
#endif
	else if (num == 0U || num == 1U) { return 1; }
	register unsigned long long i, fct = (unsigned long long)num;
	for (i = fct - 1ULL; --i;) { fct *= i; }
	return fct;
}


/** Factorial (n!); return 0 on error */
LIB_FUNC MATH_FUNC long long factoriallonglong(const long long num) {
#if IS_64
	if (num > 20LL) { return 0; }
#elif IS_32
	if (num > 10LL) { return 0; }
#endif
	else if (num == 0LL || num == 1LL) { return 1LL; }
	register long long i, fct = num;
	for (i = fct - 1LL; --i;) fct *= i;
	return fct;
}


/** Double Factorial (n!!); return 0 on error */
LIB_FUNC MATH_FUNC unsigned long long doublefactorial(const unsigned int num) {
#if IS_64
	if (num > 30U) { return 0; }
#elif IS_32
	if (num > 10U) { return 0; }
#endif
	else if (num == 0U || num == (unsigned int)1) { return 1ULL; }
	else if (num == 2U) { return 2ULL; }
	else if (num == 3U) { return 3ULL; }
	else if (num == 4U) { return 8ULL; }
	register unsigned long long i, fct = num;
	if ((num % 2U) == 0U) {  // Even
		for (i = (fct - 2ULL); i > 1; i = (i - 2ULL)) {
			if (i <= 1ULL) { break; }
			else if (i == 2ULL) { fct *= i; break; }
			fct *= i;
		}
	} else {  // Odd
		for (i = (fct - 2ULL); i > 2; i = (i - 2ULL)) {
			if (i <= 2) { break; }
			else if (i == 3) { fct *= i; break; }
			fct *= i;
		}
	}
	return fct;
}


/** Double Factorial (n!!); return 0 on error */
LIB_FUNC MATH_FUNC long long doublefactoriallonglong(const long long num) {
#if IS_64
	if (num > 30LL) { return 0; }
#elif IS_32
	if (num > 9LL) { return 0; }
#endif
	else if (num < 0LL) { return 0LL; }
	else if (num == 0LL || num == 1LL) { return 1; }
	else if (num == 2LL) { return 2LL; }
	else if (num == 3LL) { return 3LL; }
	else if (num == 4LL) { return 8LL; }
	register long long i, fct = num;
	if ((num % 2LL) == 0LL) {  // Even
		for (i = (fct - 2LL); i > 1; i = (i - 2LL)) {
			if (i <= 1) { break; }
			else if (i == 2) { fct *= i; break; }
			fct *= i;
		}
	} else {  // Odd
		for (i = (fct - 2LL); i > 2; i = (i - 2LL)) {
			if (i <= 2) { break; }
			else if (i == 3) { fct *= i; break; }
			fct *= i;
		}
	}
	return fct;
}


/** Quadruple Factorial - (2n)!/n!; return 0 on error */
LIB_FUNC MATH_FUNC unsigned long long quadfactorial(const unsigned int num) {
#if IS_64
	if (num > 10U) { return 0; }
#elif IS_32
	if (num > 5U) { return 0; }
#endif
	else if (num == 0U) { return 1ULL; }
	else if (num == 1U) { return 2ULL; }
	register unsigned long long i, fct1 = num, fct2 = (num + num);
	for (i = fct1 - 1ULL; i > 0ULL; --i) { fct1 *= i; }
	for (i = fct2 - 1ULL; i > 0ULL; --i) { fct2 *= i; }
	return (fct2 / fct1);
}


/** Quadruple Factorial - (2n)!/n!; return 0 on error */
LIB_FUNC MATH_FUNC long long quadfactoriallonglong(const long long num) {
	switch (num) {
		case 0LL: return 1LL;
		case 1LL: return 2LL;
		case 2LL: return 12LL;
		case 3LL: return 120LL;
		case 4LL: return 1680LL;
		case 5LL: return 30240LL;
		case 6LL: return 665280LL;
		case 7LL: return 17297280LL;
		case 8LL: return 518918400LL;
		case 9LL: return 17643225600LL;
		default: return 0;
	}
	return 0;
}


/** Super-Factorial; return 0 on error */
LIB_FUNC MATH_FUNC unsigned long long superfactorial(const unsigned int num) {
#if IS_64
	if (num > 9U) { return 0; }
#elif IS_32
	if (num > 4U) { return 0; }
#endif
	else if (num == 0U || num == 1U) { return 1ULL; }
	register unsigned long long i, j, fct = 1;
	for (i = (unsigned long long)num; --i;) { for (j = i; --j;) { fct *= j; } }
	return fct;
}


/** Super-Factorial; return 0 on error */
LIB_FUNC MATH_FUNC long long superfactoriallonglong(const long long num) {
	switch (num) {
		case 0LL: return 1LL;
		case 1LL: return 1LL;
		case 2LL: return 2LL;
		case 3LL: return 12LL;
		case 4LL: return 288LL;
		case 5LL: return 34560LL;
		case 6LL: return 24883200LL;
#   if IS_64
		case 7LL: return 125411328000LL;
		case 8LL: return 5056584744960000LL;
#   endif
#   if IS_128
		case 9LL: return 1834933472251084800000LL;
		case 10LL: return 6658606584104736522240000000LL;
		case 11LL: return 265790267296391946810949632000000000LL;
		// case 12LL: return 127313963299399416749559771247411200000000000LL;
#   endif
		default: return 0;
	}
	return 0;
}


/** Find the number used to produce the factorial */
LIB_FUNC MATH_FUNC int unfactorial(const int num) {
	register int x, y = num;
	for (x = 1; y != x; ++x) { y /= x; }
	return x;
}


/** Find the number used to produce the factorial */
LIB_FUNC MATH_FUNC uint64_t unfactorial64(const uint64_t num) {
	register uint64_t x, y = num;
	for (x = 1; y != x; ++x) { y /= x; }
	return x;
}


// NUMBER GENERATORS

/** Return the Nth Pronic number */
LIB_FUNC MATH_FUNC unsigned int pronic(const unsigned int num) {
	return ((num * num) + num);
}


/** Return the Nth Pronic number */
LIB_FUNC MATH_FUNC unsigned long long pronicull(const unsigned long long num) {
	return ((num * num) + num);
}


/** Return the Nth Pronic number */
LIB_FUNC MATH_FUNC long long proniclonglong(const long long num) {
	return ((num * num) + num);
}


#if SUPPORTS_UINT128
/** Return the Nth Pronic number (128-bit unsigned integer) */
LIB_FUNC MATH_FUNC uint128_t pronic_u128(const uint128_t num) {
	return (((uint128_t)num * (uint128_t)num) + (uint128_t)num);
}
#endif


/** Fibonacci Number Generator; return 0 on error */
LIB_FUNC MATH_FUNC unsigned int fib(const unsigned int num) {
#   if IS_64
	if (num > (unsigned int)48) { return 0; }
#   elif IS_32
	if (num > (unsigned int)24) { return 0; }
#   endif
	else if (num == (unsigned int)0) { return 0; }
	else if (num == (unsigned int)1 || num == (unsigned int)2) { return 1; }
	else {
#   if IS_64
		unsigned int align64 fibval[49] = { 0, 1, 1, 2, 3, 0, 0 };
#   elif IS_32
		unsigned int align64 fibval[25] = { 0, 1, 1, 2, 3, 0, 0 };
#   endif
		register unsigned int i;
		for (i = (unsigned int)4; i <= num; ++i) {
			fibval[i] = fibval[i - (unsigned int)1] + fibval[i - (unsigned int)2];
		}
		return fibval[num];
	}
}


/** Fibonacci Number Generator; return 0 on error */
LIB_FUNC MATH_FUNC unsigned long longfib(const unsigned long num) {
#if IS_64
	if (num > 91UL) { return 0; }
#elif IS_32
	if (num > 37UL) { return 0; }
#endif
	else if (num <= 12UL) {
		switch (num) {
			case 0UL: return 0UL;
			case 1UL: return 1UL;
			case 2UL: return 1UL;
			case 3UL: return 2UL;
			case 4UL: return 3UL;
			case 5UL: return 5UL;
			case 6UL: return 8UL;
			case 7UL: return 13UL;
			case 8UL: return 21UL;
			case 9UL: return 34UL;
			case 10UL: return 55UL;
			case 11UL: return 89UL;
			default: return 144UL;  // case 12UL
		}
	}
#   if IS_64
	unsigned long align64 fibval[92] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 0, 0 };
#   elif IS_32
	unsigned long align64 fibval[38] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 0, 0 };
#   endif
	register unsigned long i;
	for (i = 13UL; i <= num; ++i) fibval[i] = fibval[i - 1UL] + fibval[i - 2UL];
	return fibval[num];
}


/** Fibonacci Number Generator; return 0 on error */
LIB_FUNC MATH_FUNC long long longlongfib(const long long num) {
#if IS_64
	if ((num < 0LL) || (num > 91LL)) { return 0LL; }
#elif IS_32
	if ((num < 0LL) || (num > 35LL)) { return 0LL; }
#endif
	else if ((num >= 0LL) && (num <= 14LL)) {
		switch (num) {
			case 0LL: return 0LL;
			case 1LL: return 1LL;
			case 2LL: return 1LL;
			case 3LL: return 2LL;
			case 4LL: return 3LL;
			case 5LL: return 5LL;
			case 6LL: return 8LL;
			case 7LL: return 13LL;
			case 8LL: return 21LL;
			case 9LL: return 34LL;
			case 10LL: return 55LL;
			case 11LL: return 89LL;
			case 12LL: return 144LL;
			case 13LL: return 233LL;
			default: return 377LL;  // case 14
		}
	}
#   if IS_64
	long long align64 fibval[92] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 0, 0 };
#   elif IS_32
	long long align64 fibval[36] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 0, 0 };
#   endif
	register long long i;
	for (i = 15; i <= num; ++i) { fibval[i] = (fibval[i - 1] + fibval[i - 2]); if (i >= num) { break; } }
	return fibval[num];
}


#if SUPPORTS_UINT128
/** Fibonacci Number Generator (128-bit integers); return 0 on error */
LIB_FUNC MATH_FUNC uint128_t fib128(const uint64_t num) {
	if (num > (uint64_t)180) { return 0; }
	else if (num <= (uint64_t)16) {
		switch (num) {
			case (uint64_t)0: return (uint128_t)0;
			case (uint64_t)1: return (uint128_t)1;
			case (uint64_t)2: return (uint128_t)1;
			case (uint64_t)3: return (uint128_t)2;
			case (uint64_t)4: return (uint128_t)3;
			case (uint64_t)5: return (uint128_t)5;
			case (uint64_t)6: return (uint128_t)8;
			case (uint64_t)7: return (uint128_t)13;
			case (uint64_t)8: return (uint128_t)21;
			default:  // Over 8, but less than 17
				switch (num) {
					case (uint64_t)9: return (uint128_t)34;
					case (uint64_t)10: return (uint128_t)55;
					case (uint64_t)11: return (uint128_t)89;
					case (uint64_t)12: return (uint128_t)144;
					case (uint64_t)13: return (uint128_t)233;
					case (uint64_t)14: return (uint128_t)377;
					case (uint64_t)15: return (uint128_t)610;
					default: return (uint128_t)987;  // case (uint128_t)16
				}
				break;
		}
	}
	uint128_t fibval[181] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 0, 0 };
	register uint64_t i;
	for (i = (uint64_t)17; i <= num; ++i) {
		fibval[i] = fibval[(i - (uint64_t)1)] + fibval[(i - (uint64_t)2)];
	}
	return fibval[num];
}
#endif


/**
	@brief Fibonacci Prime Number Generator; return 0 on error

	@section DESCRIPTION
	A Fibonacci prime is a Fibonacci number that is prime.

	@param[in] num Specify the first, second, etc. Fibonacci Prime
	@return Fibonacci Prime
*/
LIB_FUNC MATH_FUNC uint64_t fibprime(const uint64_t num) {
	if (num > (uint64_t)11) { return 0; }
	switch (num) {
		case (uint64_t)0: return (uint64_t)2;
		case (uint64_t)1: return (uint64_t)3;
		case (uint64_t)2: return (uint64_t)5;
		case (uint64_t)3: return (uint64_t)13;
		case (uint64_t)4: return (uint64_t)89;
		case (uint64_t)5: return (uint64_t)233;
		case (uint64_t)6: return (uint64_t)1597;
		case (uint64_t)7: return (uint64_t)28657;
		case (uint64_t)8: return (uint64_t)514229;
		case (uint64_t)9: return (uint64_t)433494437;
		case (uint64_t)10: return (uint64_t)2971215073;
		default: return (uint64_t)99194853094755497;  // case (uint64_t)11
	}
	// [2, 3, 5, 13, 89, 233, 1597, 28657, 514229, 433494437, 2971215073, 99194853094755497, 1066340417491710595814572169, 19134702400093278081449423917, 475420437734698220747368027166749382927701417016557193662268716376935476241]
}


#if SUPPORTS_UINT128
/**
	@brief Fibonacci Prime Number Generator; return 0 on error

	@section DESCRIPTION
	A Fibonacci prime is a Fibonacci number that is prime.

	@param[in] num Specify the first, second, etc. Fibonacci Prime
	@return Fibonacci Prime
*/
LIB_FUNC MATH_FUNC uint128_t fibprime128(const uint64_t num) {
	if (num > (uint64_t)13) { return 0; }
	switch (num) {
		case (uint64_t)0: return (uint128_t)2;
		case (uint64_t)1: return (uint128_t)3;
		case (uint64_t)2: return (uint128_t)5;
		case (uint64_t)3: return (uint128_t)13;
		case (uint64_t)4: return (uint128_t)89;
		case (uint64_t)5: return (uint128_t)233;
		case (uint64_t)6: return (uint128_t)1597;
		case (uint64_t)7: return (uint128_t)28657;
		case (uint64_t)8: return (uint128_t)514229;
		case (uint64_t)9: return (uint128_t)433494437;
		case (uint64_t)10: return (uint128_t)2971215073;
		case (uint64_t)11: return (uint128_t)99194853094755497;
		case (uint64_t)12: return (uint128_t)((uint128_t)(10663404174917105UL * 100000000000UL) + 95814572169);  // 1066340417491710595814572169
		default: return (uint128_t)((uint128_t)(1913470240009327UL * 10000000000000UL) + 8081449423917);  // case (uint64_t)13; 19134702400093278081449423917
	}
	// [2, 3, 5, 13, 89, 233, 1597, 28657, 514229, 433494437, 2971215073, 99194853094755497, 1066340417491710595814572169, 19134702400093278081449423917, 475420437734698220747368027166749382927701417016557193662268716376935476241]
}
#endif


/** Lucas Number Generator; return 0 on error */
LIB_FUNC MATH_FUNC unsigned long lucas(const unsigned long num) {
#if IS_64
	if (num > 91UL) { return 0; }
#elif IS_32
	if (num > 37UL) { return 0; }
#endif
	else if (num <= 12UL) {
		switch (num) {
			case 0UL: return 2UL;
			case 1UL: return 1UL;
			case 2UL: return 3UL;
			case 3UL: return 4UL;
			case 4UL: return 7UL;
			case 5UL: return 11UL;
			case 6UL: return 18UL;
			case 7UL: return 29UL;
			case 8UL: return 47UL;
			case 9UL: return 76UL;
			case 10UL: return 123UL;
			case 11UL: return 199UL;
			default: return 322UL;  // case 12UL
		}
	}
#   if IS_64
	unsigned long lucasval[92] = { 2, 1, 3, 4, 7, 11, 18, 29, 47, 76, 123, 199, 322, 0, 0 };
#   elif IS_32
	unsigned long lucasval[38] = { 2, 1, 3, 4, 7, 11, 18, 29, 47, 76, 123, 199, 322, 0, 0 };
#   endif
	register unsigned long i;
	for (i = 13UL; i <= num; ++i) {
		lucasval[i] = lucasval[i - 1UL] + lucasval[i - 2UL];
	}
	return lucasval[num];
}


/**
	@brief Lucas Prime Number Generator; return 0 on error

	@section DESCRIPTION
	A Lucas prime is a Lucas number that is prime.

	@param[in] num Specify the first, second, etc. Lucas Prime
	@return Lucas Prime
*/
LIB_FUNC MATH_FUNC uint64_t lucasprime(const uint64_t num) {
	if (num > (uint64_t)14) { return 0; }
	switch (num) {
		case (uint64_t)0: return (uint64_t)2;
		case (uint64_t)1: return (uint64_t)3;
		case (uint64_t)2: return (uint64_t)7;
		case (uint64_t)3: return (uint64_t)11;
		case (uint64_t)4: return (uint64_t)29;
		case (uint64_t)5: return (uint64_t)47;
		case (uint64_t)6: return (uint64_t)199;
		case (uint64_t)7: return (uint64_t)521;
		case (uint64_t)8: return (uint64_t)2207;
		case (uint64_t)9: return (uint64_t)3571;
		case (uint64_t)10: return (uint64_t)9349;
		case (uint64_t)11: return (uint64_t)3010349;
		case (uint64_t)12: return (uint64_t)54018521;
		case (uint64_t)13: return (uint64_t)370248451;
		default: return (uint64_t)6643838879;  // case (uint64_t)14
	}
	// [0, 2, 4, 5, 7, 8, 11, 13, 16, 17, 19, 31, 37, 41, 47, 53, 61, 71, 79, 113, 313, 353, 503, 613, 617, 863, 1097, 1361, 4787, 4793, 5851, 7741, 8467, 10691, 12251, 13963, 14449, 19469, 35449, 36779, 44507, 51169, 56003, 81671, 89849, 94823, 140057, 148091, 159521, 183089, 193201, 202667, 344293, 387433, 443609, 532277, 574219, 616787, 631181, 637751, 651821, 692147, 901657, 1051849]
}


/** Return the Nth Triangular Number */
LIB_FUNC MATH_FUNC unsigned int triangular_num(const unsigned int num) {
	return (unsigned int)((num * (num + 1)) / 2);
	// [0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325, 351, 378, 406, 435, 465, 496, 528, 561, 595, 630, 666, 703, 741, 780, 820, 861, 903, 946, 990, 1035, 1081, 1128, 1176, 1225, 1275, 1326, 1378, 1431]
}


/** Return the Nth Triangular Number */
LIB_FUNC MATH_FUNC unsigned long long triangular_numull(const unsigned long long num) {
	return ((num * (num + 1ULL)) / 2ULL);
}


/** Return the Nth Triangular Number */
LIB_FUNC MATH_FUNC long long triangular_numlonglong(const long long num) {
	return ((num * (num + 1)) / 2);
}


#if SUPPORTS_UINT128
/** Return the Nth Triangular Number (128-bit unsigned integer) */
LIB_FUNC MATH_FUNC uint128_t triangular_u128(const uint128_t num) {
	return (uint128_t)((num * (num + (uint128_t)1)) / (uint128_t)2);
}
#endif


/** Return the Nth Hexagonal Number */
LIB_FUNC MATH_FUNC unsigned int hexagonal_num(const unsigned int num) {
	register unsigned int num2 = num + num;
	return (unsigned int)((num2 * (num2 - 1)) / 2);
	// [0, 1, 6, 15, 28, 45, 66, 91, 120, 153, 190, 231, 276, 325, 378, 435, 496, 561, 630, 703, 780, 861, 946, 1035, 1128, 1225, 1326, 1431, 1540, 1653, 1770, 1891, 2016, 2145, 2278, 2415, 2556, 2701, 2850, 3003, 3160, 3321, 3486, 3655, 3828, 4005, 4186, 4371, 4560]
}


/** Return the Nth Hexagonal Number */
LIB_FUNC MATH_FUNC unsigned long long hexagonal_numull(const unsigned long long num) {
	register unsigned long long num2 = num + num;
	return ((num2 * (num2 - 1ULL)) / 2ULL);
}


/** Return the Nth Hexagonal Number */
LIB_FUNC MATH_FUNC long long hexagonal_numlonglong(const long long num) {
	register long long num2 = (num + num);
	return ((num2 * (num2 - 1)) / 2);
}


#if SUPPORTS_UINT128
/** Return the Nth Hexagonal Number (128-bit unsigned integer) */
LIB_FUNC MATH_FUNC uint128_t hexagonal_u128(const uint128_t num) {
	register uint128_t num2 = (num + num);
	return (uint128_t)((num2 * (num2 - (uint128_t)1)) / (uint128_t)2);
}
#endif


/** Return the Nth Heptagonal Number ((5*(num^2) - 3 * num)/2) */
LIB_FUNC MATH_FUNC unsigned int heptagonal_num(const unsigned int num) {
	return (unsigned int)((((num * num) * 5) - (3 * num)) / 2);
	// [0, 1, 7, 18, 34, 55, 81, 112, 148, 189, 235, 286, 342, 403, 469, 540, 616, 697, 783, 874, 970, 1071, 1177, 1288, 1404, 1525, 1651, 1782, 1918, 2059, 2205, 2356, 2512, 2673, 2839, 3010, 3186, 3367, 3553, 3744, 3940, 4141, 4347, 4558, 4774, 4995, 5221, 5452, 5688]
}


/** Return the Nth Heptagonal Number ((5*(num^2) - 3 * num)/2) */
LIB_FUNC MATH_FUNC unsigned long long heptagonal_numull(const unsigned long long num) {
	return ((((num * num) * 5ULL) - (3ULL * num)) / 2ULL);
}


/** Return the Nth Heptagonal Number ((5*(num^2) - 3 * num)/2) */
LIB_FUNC MATH_FUNC long long heptagonal_numlonglong(const long long num) {
	return ((((num * num) * 5) - (3 * num)) / 2);
}


#if SUPPORTS_UINT128
/** Return the Nth Heptagonal Number ((5*(num^2) - 3 * num)/2) (128-bit unsigned integer) */
LIB_FUNC MATH_FUNC uint128_t heptagonal_u128(const uint128_t num) {
	return (uint128_t)((((num * num) * (uint128_t)5) - ((uint128_t)3 * num)) / (uint128_t)2);
}
#endif


/** Return the Nth Tetrahedral Number */
LIB_FUNC MATH_FUNC unsigned int tetrahedral_num(const unsigned int num) {
	return (unsigned int)((num * (num + 1) * (num + 2)) / 6);
	// [0, 1, 4, 10, 20, 35, 56, 84, 120, 165, 220, 286, 364, 455, 560, 680, 816, 969, 1140, 1330, 1540, 1771, 2024, 2300, 2600, 2925, 3276, 3654, 4060, 4495, 4960, 5456, 5984, 6545, 7140, 7770, 8436, 9139, 9880, 10660, 11480, 12341, 13244, 14190, 15180]
}


/** Return the Nth Tetrahedral Number */
LIB_FUNC MATH_FUNC unsigned long long tetrahedral_numull(const unsigned long long num) {
	return ((num * (num + 1ULL) * (num + 2ULL)) / 6ULL);
}


/** Return the Nth Tetrahedral Number */
LIB_FUNC MATH_FUNC long long tetrahedral_numlonglong(const long long num) {
	return ((num * (num + 1LL) * (num + 2LL)) / 6LL);
}


#if SUPPORTS_UINT128
/** Return the Nth Tetrahedral Number (128-bit unsigned integer) */
LIB_FUNC MATH_FUNC uint128_t tetrahedral_u128(const uint128_t num) {
	return (num * (num + (uint128_t)1) * (num + (uint128_t)2)) / (uint128_t)6;
}
#endif


/** Return the Nth Pentatope Number */
LIB_FUNC MATH_FUNC unsigned int pentatope_num(const unsigned int num) {
	return ((num * (num + 1) * (num + 2) * (num + 3)) / 24);
	// [2, 5, 70, 1088430, 58478088289964410654020]
}


/** Return the Nth Pentatope Number */
LIB_FUNC MATH_FUNC unsigned long long pentatope_numull(const unsigned long long num) {
	return ((num * (num + 1ULL) * (num + 2ULL) * (num + 3ULL)) / 24ULL);
}


/** Return the Nth Pentatope Number */
LIB_FUNC MATH_FUNC long long pentatope_numlonglong(const long long num) {
	return ((num * (num + 1) * (num + 2) * (num + 3)) / 24);
}


#if SUPPORTS_UINT128
/** Return the Nth Pentatope Number (128-bit unsigned integer) */
LIB_FUNC MATH_FUNC uint128_t pentatope_u128(const uint128_t num) {
	return ((num * (num + (uint128_t)0x1) * (num + (uint128_t)0x2) * (num + (uint128_t)0x3)) / (uint128_t)0x24);
}
#endif


/** Return the Nth Mersenne Number; return 0 on error */
LIB_FUNC MATH_FUNC unsigned int mersenne_num(const unsigned int num) {
#if IS_64
	if (num > 31U) { return 0; }
#elif IS_32
	if (num > 15U) { return 0; }
#endif
	else { return ((1U << num) - 1U); }
	// [0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823, 2147483647, 4294967295]
}


/** Return the Nth Mersenne Number; return 0 on error */
LIB_FUNC MATH_FUNC unsigned long long mersenne_numull(const unsigned long long num) {
#if IS_64
	if (num > 63ULL) { return 0; }
#elif IS_32
	if (num > 31ULL) { return 0; }
#endif
	return ((1ULL << num) - 1ULL);
}


/** Return the Nth Mersenne Number; return 0 on error */
LIB_FUNC MATH_FUNC long long mersenne_numlonglong(const long long num) {
#if IS_64
	if (num > 63LL || num < 1LL) { return 0; }
#elif IS_32
	if (num > 31LL || num < 1LL) { return 0; }
#endif
	return ((1LL << num) - 1LL);
	// [0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823, 2147483647, 4294967295]
}


#if SUPPORTS_UINT128
/** Return the Nth Mersenne Number (128-bit unsigned integer); return 0 on error */
LIB_FUNC MATH_FUNC uint128_t mersenne_u128(const uint128_t num) {
	if ((uint128_t)num > (uint128_t)126) { return 0; }
	return (((uint128_t)0x1 << num) - (uint128_t)0x1);
}
#endif


/** Return the Nth Mersenne Prime Number; return 0 on error */
LIB_FUNC MATH_FUNC unsigned int mersenneprime_num(const unsigned int num) {
	switch (num) {
		case (unsigned int)0: return (unsigned int)1;
		case (unsigned int)1: return (unsigned int)3;
		case (unsigned int)2: return (unsigned int)7;
		case (unsigned int)3: return (unsigned int)31;
		case (unsigned int)4: return (unsigned int)127;
		case (unsigned int)5: return (unsigned int)2047;
		case (unsigned int)6: return (unsigned int)8191;
		case (unsigned int)7: return (unsigned int)131071;
		case (unsigned int)8: return (unsigned int)524287;
		case (unsigned int)9: return (unsigned int)8388607;
		case (unsigned int)10: return (unsigned int)536870911;
		case (unsigned int)11: return (unsigned int)2147483647;
		default: return (unsigned int)0;
	}  // [3, 7, 31, 127, 2047, 8191, 131071, 524287, 8388607, 536870911, 2147483647, 137438953471, 2199023255551, 8796093022207, 140737488355327, 9007199254740991, 576460752303423487, 2305843009213693951, 147573952589676412927, 2361183241434822606847]
	return (unsigned int)0;
}


/** Return the Nth Mersenne Prime Number; return 0 on error */
LIB_FUNC MATH_FUNC unsigned long long mersenneprime_numull(const unsigned long long num) {
	switch (num) {
		case 0ULL: return 1ULL;
		case 1ULL: return 3ULL;
		case 2ULL: return 7ULL;
		case 3ULL: return 31ULL;
		case 4ULL: return 127ULL;
		case 5ULL: return 2047ULL;
		case 6ULL: return 8191ULL;
		case 7ULL: return 131071ULL;
		case 8ULL: return 524287ULL;
		case 9ULL: return 8388607ULL;
		case 10ULL: return 536870911ULL;
		case 11ULL: return 2147483647ULL;
		case 12ULL: return 137438953471ULL;
		case 13ULL: return 2199023255551ULL;
		case 14ULL: return 8796093022207ULL;
		case 15ULL: return 140737488355327ULL;
		case 16ULL: return 9007199254740991ULL;
		case 17ULL: return 576460752303423487ULL;
		case 18ULL: return 2305843009213693951ULL;
		default: return 0ULL;
	}  // [3, 7, 31, 127, 2047, 8191, 131071, 524287, 8388607, 536870911, 2147483647, 137438953471, 2199023255551, 8796093022207, 140737488355327, 9007199254740991, 576460752303423487, 2305843009213693951, 147573952589676412927, 2361183241434822606847]
	return 0ULL;
}


/** Return the Nth Mersenne Prime Number; return 0 on error */
LIB_FUNC MATH_FUNC long long mersenneprime_numlonglong(const long long num) {
	switch (num) {
		case 0LL: return 1LL;
		case 1LL: return 3LL;
		case 2LL: return 7LL;
		case 3LL: return 31LL;
		case 4LL: return 127LL;
		case 5LL: return 2047LL;
		case 6LL: return 8191LL;
		case 7LL: return 131071LL;
		case 8LL: return 524287LL;
		case 9LL: return 8388607LL;
		case 10LL: return 536870911LL;
		case 11LL: return 2147483647LL;
		case 12LL: return 137438953471LL;
		case 13LL: return 2199023255551LL;
		case 14LL: return 8796093022207LL;
		case 15LL: return 140737488355327LL;
		case 16LL: return 9007199254740991LL;
		case 17LL: return 576460752303423487LL;
		case 18LL: return 2305843009213693951LL;
		default: return 0;
	}  // [3, 7, 31, 127, 2047, 8191, 131071, 524287, 8388607, 536870911, 2147483647, 137438953471, 2199023255551, 8796093022207, 140737488355327, 9007199254740991, 576460752303423487, 2305843009213693951, 147573952589676412927, 2361183241434822606847]
	return 0;
}


#if SUPPORTS_UINT128
/** Return the Nth Mersenne Prime Number (128-bit unsigned integer); return 0 on error */
LIB_FUNC MATH_FUNC uint128_t mersenneprime_u128(const uint128_t num) {
	switch (num) {
		case (uint64_t)0: return (uint128_t)1;
		case (uint64_t)1: return (uint128_t)3;
		case (uint64_t)2: return (uint128_t)7;
		case (uint64_t)3: return (uint128_t)31;
		case (uint64_t)4: return (uint128_t)127;
		case (uint64_t)5: return (uint128_t)2047;
		case (uint64_t)6: return (uint128_t)8191;
		case (uint64_t)7: return (uint128_t)131071;
		case (uint64_t)8: return (uint128_t)524287;
		case (uint64_t)9: return (uint128_t)8388607;
		case (uint64_t)10: return (uint128_t)536870911;
		case (uint64_t)11: return (uint128_t)2147483647;
		case (uint64_t)12: return (uint128_t)137438953471;
		case (uint64_t)13: return (uint128_t)2199023255551;
		case (uint64_t)14: return (uint128_t)8796093022207;
		case (uint64_t)15: return (uint128_t)140737488355327;
		case (uint64_t)16: return (uint128_t)9007199254740991;
		case (uint64_t)17: return (uint128_t)576460752303423487;
		case (uint64_t)18: return (uint128_t)2305843009213693951;
		case (uint64_t)19: return (uint128_t)((uint128_t)(147573952589UL * 1000000000UL) + 676412927);  // 147573952589676412927
		case (uint64_t)20: return (uint128_t)((uint128_t)(23611832414UL * 100000000000UL) + 34822606847);  // 2361183241434822606847
		default: return (uint128_t)0;
	}  // [3, 7, 31, 127, 2047, 8191, 131071, 524287, 8388607, 536870911, 2147483647, 137438953471, 2199023255551, 8796093022207, 140737488355327, 9007199254740991, 576460752303423487, 2305843009213693951, 147573952589676412927, 2361183241434822606847]
	return (uint128_t)0;
}
#endif


// NUMBER-TYPE TESTS

/** Test if a number is a perfect square */
LIB_FUNC MATH_FUNC int issquare(const int num) {
	if (num < 0) { return -1; }
	register double test = floor(sqrt((double)num) + 0.5);
	if ((int)(test * test) == num) { return 1; }
	return 0;
}


/** Test if a number is a perfect square */
LIB_FUNC MATH_FUNC int islongsquare(const long num) {
	if (num < (long)0) { return -1; }
	register double test = floor(sqrt((double)num) + 0.5);
	if ((long)(test * test) == num) { return 1; }
	return 0;
}


/** Test if a number is a perfect square */
LIB_FUNC MATH_FUNC int islonglongsquare(const long long num) {
	if (num < (long long)0) { return -1; }
	long double test = floorl(sqrtl((long double)num) + 0.5L);
	if ((long long)(test * test) == num) { return 1; }
	return 0;
}


/** Test if a float is a perfect square */
LIB_FUNC MATH_FUNC int isfloatsquare(const float num) {
	if (num < 0.0F) { return -1; }
	register float test = floorf(sqrtf(num) + 0.5F);
	if ((test * test) == num) { return 1; }
	return 0;
}


/** Test if a double is a perfect square */
LIB_FUNC MATH_FUNC int isdoublesquare(const double num) {
	if (num < 0.0) { return -1; }
	register double test = floor(sqrt(num) + 0.5);
	if ((test * test) == num) { return 1; }
	return 0;
}


/** Test if a long double is a perfect square */
LIB_FUNC MATH_FUNC int islongdoublesquare(const long double num) {
	if (num < 0.0L) { return -1; }
	const long double test = floorl(sqrtl(num) + 0.5L);
	if ((test * test) == num) { return 1; }
	return 0;
}


/** Test if the given number is a Triangular Number */
LIB_FUNC MATH_FUNC int istriangular(const long num) {
	if (num < (long)0) { return -1; }
	return islongsquare((long)((long)8 * num + (long)1));
}


/** Test if the given number is a Triangular Number */
LIB_FUNC MATH_FUNC int islonglongtriangular(const long long num) {
	if (num < (long long)0) { return -1; }
	return islonglongsquare((long long)((long long)8 * num + (long long)1));
}


/** Test if the given number is a Triangular Number */
LIB_FUNC MATH_FUNC int isdoubletriangular(const double num) {
	if (num < 0.0) { return -1; }
	return isdoublesquare(8.0 * num + 1.0);
}


/** Test if the given number is a Hexagonal Number */
LIB_FUNC MATH_FUNC int ishexagonal(const long num) {
	if (num < (long)0) { return -1; }
	register double ans = ((sqrt((double)((long)8 * num + (long)1)) + 1.0) * 0.25);
	if (ans == floor(ans)) { return 1; }
	return 0;
}


/** Test if the given number is a Hexagonal Number */
LIB_FUNC MATH_FUNC int islonglonghexagonal(const long long num) {
	if (num < (long long)0) { return -1; }
	const long double ans = ((sqrtl((long double)((long long)8 * num + (long long)1)) + 1.0L) * 0.25L);
	if (ans == floorl(ans)) { return 1; }
	return 0;
}


/** Test if the given number is a Heptagonal Number */
LIB_FUNC MATH_FUNC int isheptagonal(const long num) {
	if (num < (long)0) { return -1; }
	register double ans = ((sqrt((double)((long)40 * num + (long)9)) + 3.0) * 0.1);
	if (ans == floor(ans)) { return 1; }
	return 0;
}


/** Test if the given number is a Heptagonal Number */
LIB_FUNC MATH_FUNC int islonglongheptagonal(const long long num) {
	if (num < (long long)0) { return -1; }
	long double ans = ((sqrtl((long double)((long long)40 * num + (long long)9)) + 3.0L) * 0.1L);
	if (ans == floorl(ans)) { return 1; }
	return 0;
}


/** Test if the given number is a Power-of-Two */
LIB_FUNC MATH_FUNC int ispoweroftwo(const unsigned int num) {
	return ((num != 0) && !(num & (num - 1)));
}


/** Test if the given number is a Power-of-Two */
LIB_FUNC MATH_FUNC int islonglongpoweroftwo(const long long num) {
	return ((num != (long long)0) && !(num & (num - (long long)1)));
}


/** Test if the given number is a Power-of-Two */
LIB_FUNC MATH_FUNC int isullpoweroftwo(const unsigned long long num) {
	return ((num != 0ULL) && !(num & (num - 1ULL)));
}


/** Test if the given number is a Mersenne Number */
LIB_FUNC MATH_FUNC int ismersennenumber(const unsigned int num) {
	return (((num + 1) != 0) && !((num + 1) & ((num + 1) - 1)));
}


/** Test if the given number is a Mersenne Number */
LIB_FUNC MATH_FUNC int islonglongmersennenumber(const long long num) {
	return (((num + (long long)1) != (long long)0) && !((num + (long long)1) & ((num + (long long)1) - (long long)1)));
}


/** Test if the given number is a Mersenne Prime */
LIB_FUNC MATH_FUNC int ismersenneprime(const unsigned int num) {
	switch (num) {
		case 1: return 0;
		case 3:
		case 7:
		case 31:
		case 127:
		case 2047:
		case 8191:
		case 131071:
		case 524287:
		case 8388607:
		case 536870911:
		case 2147483647: return 1;
		default: return 0;
	}  // [3, 7, 31, 127, 2047, 8191, 131071, 524287, 8388607, 536870911, 2147483647, 137438953471, 2199023255551, 8796093022207, 140737488355327, 9007199254740991, 576460752303423487, 2305843009213693951, 147573952589676412927, 2361183241434822606847]
	return 0;
}


/** Test if the given number is a Mersenne Prime */
LIB_FUNC MATH_FUNC int islonglongmersenneprime(const long long num) {
	switch (num) {
		case 3LL:
		case 7LL:
		case 31LL:
		case 127LL:
		case 2047LL:
		case 8191LL:
		case 131071LL:
		case 524287LL:
		case 8388607LL:
		case 536870911LL:
		case 2147483647LL:
		case 137438953471LL:
		case 2199023255551LL:
		case 8796093022207LL:
		case 140737488355327LL:
		case 9007199254740991LL:
		case 576460752303423487LL:
		case 2305843009213693951LL: return 1;
		default: return 0;
	}  // [3, 7, 31, 127, 2047, 8191, 131071, 524287, 8388607, 536870911, 2147483647, 137438953471, 2199023255551, 8796093022207, 140737488355327, 9007199254740991, 576460752303423487, 2305843009213693951, 147573952589676412927, 2361183241434822606847]
	return 0;
}


/** Test if a signed int is prime */
LIB_FUNC MATH_FUNC int isprime(const int num) {
	if (((num & 1) == 0) && (num != 2)) { return 0; }
	else if (num < 20) {
		switch (num) {
			case 1: return 0;
			case 2:
			case 3:
			case 5:
			case 7:
			case 11:
			case 13:
			case 17:
			case 19: return 1;
			default: return 0;
		}
	} else if (num % 3 == 0 || num % 5 == 0 || num % 7 == 0 || num % 11 == 0) {
		return 0;
	} else if (num % 13 == 0 || num % 17 == 0 || num % 19 == 0) {
		return 0;
	}
	register int i;
	for (i = 23; i < num; i += 2) { if (num % i == 0) { return (int)(i == num); } }
	return 1;
}


/** Test if an unsigned int is prime */
LIB_FUNC MATH_FUNC int isunsignedprime(const unsigned int num) {
	if (((num & (unsigned int)1) == (unsigned int)0) && (num != (unsigned int)2)) { return 0; }
	else if (num < (unsigned int)20) {
		switch (num) {
			case (unsigned int)1: return 0;
			case (unsigned int)2:
			case (unsigned int)3:
			case (unsigned int)5:
			case (unsigned int)7:
			case (unsigned int)11:
			case (unsigned int)13:
			case (unsigned int)17:
			case (unsigned int)19: return 1;
			default: return 0;
		}
	} else if (num % (unsigned int)3 == (unsigned int)0) {
		return 0;
	} else if (num % (unsigned int)5 == (unsigned int)0) {
		return 0;
	} else if (num % (unsigned int)7 == (unsigned int)0) {
		return 0;
	} else if (num % (unsigned int)11 == (unsigned int)0) {
		return 0;
	} else if (num % (unsigned int)13 == (unsigned int)0) {
		return 0;
	} else if (num % (unsigned int)17 == (unsigned int)0) {
		return 0;
	} else if (num % (unsigned int)19 == (unsigned int)0) {
		return 0;
	}
	register unsigned int i;
	for (i = (unsigned int)23; i < num; i += (unsigned int)2) {
		if (num % i == (unsigned int)0) { return (int)(i == num); }
	}
	return 1;
}


/** Test if a long is prime */
LIB_FUNC MATH_FUNC int islongprime(const long num) {
	if (((num & (long)1) == (long)0) && (num != (long)2)) { return 0; }
	else if (num < (long)20) {
		switch (num) {
			case (long)1: return 0;
			case (long)2:
			case (long)3:
			case (long)5:
			case (long)7:
			case (long)11:
			case (long)13:
			case (long)17:
			case (long)19: return 1;
			default: return 0;
		}
	} else if (num % (long)3 == (long)0 || num % (long)5 == (long)0 || num % (long)7 == (long)0) {
		return 0;
	} else if (num % (long)11 == (long)0 || num % (long)13 == (long)0) {
		return 0;
	} else if (num % (long)17 == (long)0 || num % (long)19 == (long)0) {
		return 0;
	}
	register long i;
	for (i = (long)23; i < num; i += (long)2) {
		if (num % i == (long)0) { return (int)(i == num); }
	}
	return 1;
}


/** Test if a long long is prime */
LIB_FUNC MATH_FUNC int islonglongprime(const long long num) {
	if (((num & (long long)1) == (long long)0) && (num != (long long)2)) { return 0; }
	else if (num < (long long)20) {
		switch (num) {
			case (long long)1: return 0;
			case (long long)2:
			case (long long)3:
			case (long long)5:
			case (long long)7:
			case (long long)11:
			case (long long)13:
			case (long long)17:
			case (long long)19: return 1;
			default: return 0;
		}
	} else if (num % (long long)3 == (long long)0 || num % (long long)5 == (long long)0) {
		return 0;
	} else if (num % (long long)7 == (long long)0 || num % (long long)11 == (long long)0) {
		return 0;
	} else if (num % (long long)13 == (long long)0 || num % (long long)17 == (long long)0 || num % (long long)19 == (long long)0) {
		return 0;
	}
	register long long i;
	for (i = (long long)23; i < num; i += (long long)2) {
		if (num % i == (long long)0) { return (int)(i == num); }
	}
	return 1;
}


/** Test if a unsigned long is prime */
LIB_FUNC MATH_FUNC int isulprime(const unsigned long num) {
	if (((num & 1UL) == 0UL) && (num != 2UL)) { return 0; }
	else if (num < 20UL) {
		switch (num) {
			case 1UL: return 0;
			case 2UL:
			case 3UL:
			case 5UL:
			case 7UL:
			case 11UL:
			case 13UL:
			case 17UL:
			case 19UL: return 1;
			default: break;
		}
	} else if (num % 3 == 0) { return 0; }
	else if (num % 5 == 0) { return 0; }
	else if (num % 7 == 0) { return 0; }
	else if (num % 11 == 0) { return 0; }
	else if (num % 13 == 0) { return 0; }
	else if (num % 17 == 0) { return 0; }
	else if (num % 19 == 0) { return 0; }
	register unsigned long i;
	for (i = 23UL; i < num; i += 2UL) {
		if (num % i == 0UL) { return (int)(i == num); }
	}
	return 1;
}


/** Test if an unsigned long long is prime */
LIB_FUNC MATH_FUNC int isullprime(const unsigned long long num) {
	if (((num & 1ULL) == 0ULL) && (num != 2ULL)) { return 0; }
	else if (num < 20ULL) {
		switch (num) {
			case 1ULL: return 0;
			case 2ULL:
			case 3ULL:
			case 5ULL:
			case 7ULL:
			case 11ULL:
			case 13ULL:
			case 17ULL:
			case 19ULL: return 1;
			default: break;
		}
	} else if (num % 3 == 0) { return 0; }
	else if (num % 5 == 0) { return 0; }
	else if (num % 7 == 0) { return 0; }
	else if (num % 11 == 0) { return 0; }
	else if (num % 13 == 0) { return 0; }
	else if (num % 17 == 0) { return 0; }
	else if (num % 19 == 0) { return 0; }
	register unsigned long long i;
	for (i = 23ULL; i < num; i += 2ULL) {
		if (num % i == 0ULL) { return (int)(i == num); }
	}
	return 1;
}


/** Test if an int is composite */
LIB_FUNC MATH_FUNC int iscomposite(const int num) {
	if (num < 0) { return 0; }
	else if (((num % 2) == 0) && (num != 2)) { return 1; }
	else if (num < 20) {
		switch (num) {
			case 1:
			case 2:
			case 3:
			case 5:
			case 7:
			case 11:
			case 13:
			case 17:
			case 19: return 0;
			default: return 1;
		}
	} else if (num % 3 == 0 || num % 5 == 0 || num % 7 == 0) {
		return 1;
	} else if (num % 11 == 0 || num % 13 == 0 || num % 17 == 0 || num % 19 == 0) {
		return 1;
	}
	register int i;
	for (i = 23; i < num; i += 2) {
		if (num % i == 0) { return (int)(i != num); }
	}
	return 0;
}


/** Test if an unsigned int is composite */
LIB_FUNC MATH_FUNC int isunsignedcomposite(const unsigned int num) {
	if (((num % (unsigned int)2) == (unsigned int)0) && (num != (unsigned int)2)) { return 1; }
	else if (num < (unsigned int)20) {
		switch (num) {
			case (unsigned int)1:
			case (unsigned int)2:
			case (unsigned int)3:
			case (unsigned int)5:
			case (unsigned int)7:
			case (unsigned int)11:
			case (unsigned int)13:
			case (unsigned int)17:
			case (unsigned int)19: return 0;
			default: return 1;
		}
	} else if (num % (unsigned int)3 == (unsigned int)0) { return 1; }
	else if (num % (unsigned int)5 == (unsigned int)0) { return 1; }
	else if (num % (unsigned int)7 == (unsigned int)0) { return 1; }
	else if (num % (unsigned int)11 == (unsigned int)0) { return 1; }
	else if (num % (unsigned int)13 == (unsigned int)0) { return 1; }
	else if (num % (unsigned int)17 == (unsigned int)0) { return 1; }
	else if (num % (unsigned int)19 == (unsigned int)0) { return 1; }
	register unsigned int i;
	for (i = (unsigned int)23; i < num; i += (unsigned int)2) {
		if (num % i == (unsigned int)0) { return (int)(i != num); }
	}
	return 0;
}


/** Test if an long is composite */
LIB_FUNC MATH_FUNC int islongcomposite(const long num) {
	if (num < (long)0) { return 0; }
	else if (((num % (long)2) == (long)0) && (num != (long)2)) { return 1; }
	else if (num < (long)20) {
		switch (num) {
			case (long)1:
			case (long)2:
			case (long)3:
			case (long)5:
			case (long)7:
			case (long)11:
			case (long)13:
			case (long)17:
			case (long)19: return 0;
			default: return 1;
		}
	} else if (num % (long)3 == (long)0) { return 1; }
	else if (num % (long)5 == (long)0) { return 1; }
	else if (num % (long)7 == (long)0) { return 1; }
	else if (num % (long)11 == (long)0) { return 1; }
	else if (num % (long)13 == (long)0) { return 1; }
	else if (num % (long)17 == (long)0) { return 1; }
	else if (num % (long)19 == (long)0) { return 1; }
	register long i;
	for (i = (long)23; i < num; i += (long)2) {
		if (num % i == (long)0) { return (int)(i != num); }
	}
	return 0;
}


/** Test if an long long is composite */
LIB_FUNC MATH_FUNC int islonglongcomposite(const long long num) {
	if (num < (long long)0) { return 0; }
	else if (((num % (long long)2) == (long long)0) && (num != (long long)2)) { return 1; }
	else if (num < (long long)20) {
		switch (num) {
			case (long long)1:
			case (long long)2:
			case (long long)3:
			case (long long)5:
			case (long long)7:
			case (long long)11:
			case (long long)13:
			case (long long)17:
			case (long long)19: return 0;
			default: return 1;
		}
	} else if (num % (long long)3 == (long long)0) { return 1; }
	else if (num % (long long)5 == (long long)0) { return 1; }
	else if (num % (long long)7 == (long long)0) { return 1; }
	else if (num % (long long)11 == (long long)0) { return 1; }
	else if (num % (long long)13 == (long long)0) { return 1; }
	else if (num % (long long)17 == (long long)0) { return 1; }
	else if (num % (long long)19 == (long long)0) { return 1; }
	register long long i;
	for (i = (long long)23; i < num; i += (long long)2) {
		if (num % i == (long long)0) { return (int)(i != num); }
	}
	return 0;
}


/** Test if an unsigned long is composite */
LIB_FUNC MATH_FUNC int isulcomposite(const unsigned long num) {
	if (((num % 2UL) == 0UL) && (num != 2UL)) { return 1; }
	else if (num < 20UL) {
		switch (num) {
			case 1UL:
			case 2UL:
			case 3UL:
			case 5UL:
			case 7UL:
			case 11UL:
			case 13UL:
			case 17UL:
			case 19UL: return 0;
			default: return 1;
		}
	} else if (num % 3 == 0) { return 1; }
	else if (num % 5 == 0) { return 1; }
	else if (num % 7 == 0) { return 1; }
	else if (num % 11 == 0) { return 1; }
	else if (num % 13 == 0) { return 1; }
	else if (num % 17 == 0) { return 1; }
	else if (num % 19 == 0) { return 1; }
	register unsigned long i;
	for (i = 23UL; i < num; i += 2UL) {
		if (num % i == 0UL) { return (int)(i != num); }
	}
	return 0;
}


/** Test if an unsigned long long is composite */
LIB_FUNC MATH_FUNC int isullcomposite(const unsigned long long num) {
	if (((num % 2ULL) == 0ULL) && (num != 2ULL)) { return 1; }
	else if (num < 20ULL) {
		switch (num) {
			case 1ULL:
			case 2ULL:
			case 3ULL:
			case 5ULL:
			case 7ULL:
			case 11ULL:
			case 13ULL:
			case 17ULL:
			case 19ULL: return 0;
			default: return 1;
		}
	} else if (num % 3 == 0) { return 1; }
	else if (num % 5 == 0) { return 1; }
	else if (num % 7 == 0) { return 1; }
	else if (num % 11 == 0) { return 1; }
	else if (num % 13 == 0) { return 1; }
	else if (num % 17 == 0) { return 1; }
	else if (num % 19 == 0) { return 1; }
	register unsigned long long i;
	for (i = 23ULL; i < num; i += 2ULL) {
		if (num % i == 0ULL) { return (int)(i != num); }
	}
	return 0;
}


/**
	@brief Test if an uint64_t is a Fibonacci Prime; A Fibonacci prime is a Fibonacci number that is prime
	@param[in] num A 64-bit integer
	@retval 0 False: This is not a Fibonacci Prime
	@retval 1 True: This is a Fibonacci Prime
*/
LIB_FUNC MATH_FUNC int isfibprime(const uint64_t num) {
	switch (num) {
		case (uint64_t)2:
		case (uint64_t)3:
		case (uint64_t)5:
		case (uint64_t)13:
		case (uint64_t)89:
		case (uint64_t)233:
		case (uint64_t)1597:
		case (uint64_t)28657:
		case (uint64_t)514229:
		case (uint64_t)433494437:
		case (uint64_t)2971215073:
		case (uint64_t)99194853094755497: return (int)1;
		default: return (int)0;  // False
	}
	// [2, 3, 5, 13, 89, 233, 1597, 28657, 514229, 433494437, 2971215073, 99194853094755497, 1066340417491710595814572169, 19134702400093278081449423917, 475420437734698220747368027166749382927701417016557193662268716376935476241]
}


#if SUPPORTS_UINT128
/**
	@brief Test if an uint128_t is a Fibonacci Prime; A Fibonacci prime is a Fibonacci number that is prime
	@param[in] num A 128-bit integer
	@retval 0 False: This is not a Fibonacci Prime
	@retval 1 True: This is a Fibonacci Prime
*/
LIB_FUNC MATH_FUNC int isfibprime128(const uint128_t num) {
	switch (num) {
		case (uint128_t)2:
		case (uint128_t)3:
		case (uint128_t)5:
		case (uint128_t)13:
		case (uint128_t)89:
		case (uint128_t)233:
		case (uint128_t)1597:
		case (uint128_t)28657:
		case (uint128_t)514229:
		case (uint128_t)433494437:
		case (uint128_t)2971215073:
		case (uint128_t)99194853094755497: return (int)1;
		case (uint128_t)((uint128_t)(10663404174917105UL * 100000000000UL) + 95814572169): return (int)1;  // 1066340417491710595814572169
		case (uint128_t)((uint128_t)(1913470240009327UL * 10000000000000UL) + 8081449423917): return (int)1;  // 19134702400093278081449423917
		default: return (int)0;  // False
	}
	// [2, 3, 5, 13, 89, 233, 1597, 28657, 514229, 433494437, 2971215073, 99194853094755497, 1066340417491710595814572169, 19134702400093278081449423917, 475420437734698220747368027166749382927701417016557193662268716376935476241]
}
#endif


/** Test if an uint64_t is a Lucas Number */
LIB_FUNC MATH_FUNC int islucas(const uint64_t num) {
	if (num < 1024) {
		switch (num) {
			case (uint64_t)1:
			case (uint64_t)2:
			case (uint64_t)3:
			case (uint64_t)4:
			case (uint64_t)7:
			case (uint64_t)11:
			case (uint64_t)18:
			case (uint64_t)29:
			case (uint64_t)47:
			case (uint64_t)76:
			case (uint64_t)123:
			case (uint64_t)199:
			case (uint64_t)322:
			case (uint64_t)521:
			case (uint64_t)843: return 1;
			default: return 0;
		}
	} else if (num > 1024 && num < 1860499ULL) {
		switch (num) {
			case (uint64_t)1364:
			case (uint64_t)2207:
			case (uint64_t)3571:
			case (uint64_t)5778:
			case (uint64_t)9349:
			case (uint64_t)15127:
			case (uint64_t)24476:
			case (uint64_t)39603:
			case (uint64_t)64079:
			case (uint64_t)103682:  // 24
			case (uint64_t)167761:
			case (uint64_t)271443:
			case (uint64_t)439204:
			case (uint64_t)710647:
			case (uint64_t)1149851:
			case (uint64_t)1860498: return 1;
			default: return 0;
		}
	} else if (num > 3010340ULL) {
		switch (num) {
			case (uint64_t)3010349:
			case (uint64_t)4870847:
			case (uint64_t)7881196:
			case (uint64_t)12752043:  // 34
			case (uint64_t)20633239:
			case (uint64_t)33385282:
			case (uint64_t)54018521:
			case (uint64_t)87403803:
			case (uint64_t)141422324: return 1;
			default: return 0;
		}
	} else { return 0; }
	// [1, 3, 4, 7, 11, 18, 29, 47, 76, 123, 199, 322, 521, 843, 1364, 2207, 3571, 5778, 9349, 15127, 24476, 39603, 64079, 103682, 167761, 271443, 439204, 710647, 1149851, 1860498, 3010349, 4870847, 7881196, 12752043, 20633239, 33385282, 54018521, 87403803, 141422324]
}


/**
	@brief Test if an uint64_t is a Lucas Prime; A Lucas prime is a Lucas number that is prime
	@param[in] num A 64-bit integer
	@retval 0 False: This is not a Lucas Prime
	@retval 1 True: This is a Lucas Prime
*/
LIB_FUNC MATH_FUNC int islucasprime(const uint64_t num) {
	switch (num) {
		case (uint64_t)2:
		case (uint64_t)3:
		case (uint64_t)7:
		case (uint64_t)11:
		case (uint64_t)29:
		case (uint64_t)47:
		case (uint64_t)199:
		case (uint64_t)521:
		case (uint64_t)2207:
		case (uint64_t)3571:
		case (uint64_t)9349:
		case (uint64_t)3010349:
		case (uint64_t)54018521:
		case (uint64_t)370248451:
		case (uint64_t)6643838879: return (int)1;
		default: return (int)0;  // False
	}
	// [0, 2, 4, 5, 7, 8, 11, 13, 16, 17, 19, 31, 37, 41, 47, 53, 61, 71, 79, 113, 313, 353, 503, 613, 617, 863, 1097, 1361, 4787, 4793, 5851, 7741, 8467, 10691, 12251, 13963, 14449, 19469, 35449, 36779, 44507, 51169, 56003, 81671, 89849, 94823, 140057, 148091, 159521, 183089, 193201, 202667, 344293, 387433, 443609, 532277, 574219, 616787, 631181, 637751, 651821, 692147, 901657, 1051849]
}


// ANGLES

/** Return the complement of an angle (all in degrees) */
LIB_FUNC MATH_FUNC float complement_angle_degf(const float angle) {
	return (90.0F - angle);
}


/** Return the complement of an angle (all in degrees) */
LIB_FUNC MATH_FUNC double complement_angle_deg(const double angle) {
	return (90.0 - angle);
}


#if SUPPORTS_LONG_DOUBLE
/** Return the complement of an angle (all in degrees) */
LIB_FUNC MATH_FUNC long double complement_angle_degl(const long double angle) {
	return (90.0L - angle);
}
#endif


/** Return the supplement of an angle (all in degrees) */
LIB_FUNC MATH_FUNC float supplement_angle_degf(const float angle) {
	return (180.0F - angle);
}


/** Return the supplement of an angle (all in degrees) */
LIB_FUNC MATH_FUNC double supplement_angle_deg(const double angle) {
	return (180.0 - angle);
}


#if SUPPORTS_LONG_DOUBLE
/** Return the supplement of an angle (all in degrees) */
LIB_FUNC MATH_FUNC long double supplement_angle_degl(const long double angle) {
	return (180.0 - angle);
}
#endif


/** Return the angle (in radians) of an arc given arc-length and radius */
LIB_FUNC MATH_FUNC double arc_angle(const double arc_length, const double radius) {
	return (arc_length / radius);
}


// GRAPHING

/** Return the y coordinate for a given angle (radians) */
LIB_FUNC MATH_FUNC double sin_wave_equation(const double amplitude, const double angle) {
	return (amplitude * sin(angle));
}


/** Sawtooth-Wave function */
LIB_FUNC MATH_FUNC double sawtooth(const double x) {
	return (x - floor(x));
}


/** Advanced Sawtooth-Wave function (set period and amplitude) */
LIB_FUNC MATH_FUNC double sawtooth2(const double x, const double period, const double amplitude) {
	return (((2.0 * amplitude) / PI) * (atan(cot((x * PI) / period))));
}


/** Sigmoid-Curve function */
LIB_FUNC MATH_FUNC double sigmoid(const double x) {
	return (1.0 / (1.0 + pow(M_E, -x)));
}


/** Square-Wave function */
LIB_FUNC MATH_FUNC double squarewave(const double x) {
	return sgn(sin(x));
}


/** Triangle-Wave function */
LIB_FUNC MATH_FUNC int trianglewave(const int x) {
	return (abs((x & 1)) - 1);
}


// MISCELLANEOUS MATH FUNCTIONS

/** Return the exponent(as an int64_t) of the given float */
LIB_FUNC MATH_FUNC int64_t get_flt_expo(const float x) {
	const float tmpflt = log10f(fabsf(x));
	return (int64_t)tmpflt;
}


/** Return the exponent(as an int64_t) of the given double */
LIB_FUNC MATH_FUNC int64_t get_dbl_expo(const double x) {
	const double tmpdbl = log10(fabs(x));
	return (int64_t)tmpdbl;
}


/** Compare absolute values of floating-point values pointed to by `p` and `q` for `qsort()` */
LIB_FUNC int compare_doubles(const void* p, const void* q) {
	const double pd = fabs(*(const double*)p);
	const double qd = fabs(*(const double*)q);
	if (pd < qd) { return -1; }
	else if (pd == qd) { return 0; }
	else { return 1; }
}


/** Calculate `x * y` exactly and store the result in `*hi + *lo`; It is given that the values are small enough that no overflow occurs and large enough (or zero) that no underflow occurs */
LIB_FUNC void mul_split_doubles(double* hi, double* lo, const double x, const double y) {
#ifdef __FP_FAST_FMA  // Fast built-in fused multiply-add
	*hi = x * y;
	*lo = fma(x, y, (-*hi));
#else  // Dekker's algorithm
	*hi = x * y;
	double x1 = x * ((1 << (DBL_MANT_DIG + 1) / 2) + 1);
	double y1 = y * ((1 << (DBL_MANT_DIG + 1) / 2) + 1);
	x1 = (x - x1) + x1;
	y1 = (y - y1) + y1;
	const double x2 = x - x1;
	const double y2 = y - y1;
	*lo = (((x1 * y1 - *hi) + x1 * y2) + x2 * y1) + x2 * y2;
#endif
}


/** Return the sum of division and modulus of the two given numbers */
LIB_FUNC MATH_FUNC float div_and_modf(const float num1, const float num2) {
	return (((num1 / num2) + fmodf(num1, num2)));
}


/** Return the sum of division and modulus of the two given numbers */
LIB_FUNC MATH_FUNC double div_and_mod(const double num1, const double num2) {
	return (((num1 / num2) + fmod(num1, num2)));
}


/** Return X^2 + Y^2 - 1, computed without large cancellation error; It is given that 1 > X >= Y >= epsilon / 2, and that X^2 + Y^2 >= 0.5 */
LIB_FUNC double __x2y2m1(const double x, const double y) {
	double vals[5] = { 0.0 };
	// SET_RESTORE_ROUND(FE_TONEAREST);
	mul_split_doubles(&vals[1], &vals[0], x, x);
	mul_split_doubles(&vals[3], &vals[2], y, y);
	vals[4] = -1.0;
	qsort(vals, 5, SIZEOF_DOUBLE, compare_doubles);
	for (size_t i = 0; i <= 3; i++) {
		add_split_doubles(&vals[i + 1], &vals[i], vals[i + 1], vals[i]);
		qsort((vals + i + 1), 4 - i, SIZEOF_DOUBLE, compare_doubles);
	}
	return vals[4] + vals[3] + vals[2] + vals[1] + vals[0];
}


#if IS_LDBL_X87


/** Calculate X + Y exactly and store the result in *HI + *LO; It is given that |X| >= |Y| and the values are small enough that no overflow occurs */
LIB_FUNC void add_split_long_doubles(long double* hi, long double* lo, const long double x, const long double y) {
	*hi = x + y;
	*lo = (x - *hi) + y;
}


/** Calculate X * Y exactly and store the result in *HI + *LO; It is given that the values are small enough that no overflow occurs and large enough (or zero) that no underflow occurs */
LIB_FUNC void mul_split_long_doubles(long double* hi, long double* lo, const long double x, const long double y) {
#   ifdef __FP_FAST_FMAL  // Fast built-in fused multiply-add
	*hi = x * y;
	*lo = fmal(x, y, (-*hi));
#   else  // Apply Dekker's algorithm
	*hi = x * y;
	long double x1 = x * ((1LL << (LDBL_MANT_DIG + 1) / 2) + 1);
	long double y1 = y * ((1LL << (LDBL_MANT_DIG + 1) / 2) + 1);
	x1 = (x - x1) + x1;
	y1 = (y - y1) + y1;
	const long double x2 = x - x1;
	const long double y2 = y - y1;
	*lo = (((x1 * y1 - *hi) + x1 * y2) + x2 * y1) + x2 * y2;
#   endif
}


/** Compare absolute values of floating-point values pointed to by P and Q for qsort */
LIB_FUNC int compare_long_doubles(const void* p, const void* q) {
	const long double pld = fabsl(*(const long double*)p);
	const long double qld = fabsl(*(const long double*)q);
	if (pld < qld) { return -1; }
	else if (pld == qld) { return 0; }
	else { return 1; }
}


/** Return X^2 + Y^2 - 1, computed without large cancellation error; It is given that 1 > X >= Y >= epsilon / 2, and that X^2 + Y^2 >= 0.5 */
LIB_FUNC long double __x2y2m1l(const long double x, const long double y) {
	long double vals[5] = { 0.0L };
	// SET_RESTORE_ROUNDL(FE_TONEAREST);
	mul_split_long_doubles(&vals[1], &vals[0], x, x);
	mul_split_long_doubles(&vals[3], &vals[2], y, y);
	vals[4] = -1.0L;
	qsort(vals, 5, SIZEOF_LONG_DOUBLE, compare_long_doubles);
	for (size_t i = 0; i <= 3; i++) {
		add_split_long_doubles(&vals[i + 1], &vals[i], vals[i + 1], vals[i]);
		qsort(vals + i + 1, 4 - i, SIZEOF_LONG_DOUBLE, compare_long_doubles);
	}
	return vals[4] + vals[3] + vals[2] + vals[1] + vals[0];
}


#elif LDBL_EQ_FLOAT128


/** Calculate X + Y exactly and store the result in *HI + *LO; It is given that |X| >= |Y| and the values are small enough that no overflow occurs */
LIB_FUNC void add_split_long_doubles(long double* hi, long double* lo, const long double x, const long double y) {
	*hi = x + y;
	*lo = (x - *hi) + y;
}


/** Calculate X * Y exactly and store the result in *HI + *LO; It is given that the values are small enough that no overflow occurs and large enough (or zero) that no underflow occurs */
LIB_FUNC void mul_split_long_doubles(long double* hi, long double* lo, const long double x, const long double y) {
#   ifdef __FP_FAST_FMAL  // Fast built-in fused multiply-add
	*hi = x * y;
	*lo = fmal(x, y, (-*hi));
#   else  // Apply Dekker's algorithm
	*hi = x * y;
	long double x1 = x * ((1LL << (LDBL_MANT_DIG + 1) / 2) + 1);
	long double y1 = y * ((1LL << (LDBL_MANT_DIG + 1) / 2) + 1);
	x1 = (x - x1) + x1;
	y1 = (y - y1) + y1;
	const long double x2 = x - x1;
	const long double y2 = y - y1;
	*lo = (((x1 * y1 - *hi) + x1 * y2) + x2 * y1) + x2 * y2;
#   endif
}


/** Compare absolute values of floating-point values pointed to by P and Q for qsort */
LIB_FUNC int compare_long_doubles(const void* p, const void* q) {
	const long double pld = fabsl(*(const long double*)p);
	const long double qld = fabsl(*(const long double*)q);
	if (pld < qld) { return -1; }
	else if (pld == qld) { return 0; }
	else { return 1; }
}


/** Return X^2 + Y^2 - 1, computed without large cancellation error; It is given that 1 > X >= Y >= epsilon / 2, and that X^2 + Y^2 >= 0.5 */
LIB_FUNC long double __x2y2m1l(const long double x, const long double y) {
	long double vals[5] = { 0.0L };
	// SET_RESTORE_ROUNDL(FE_TONEAREST);
	mul_split_long_doubles(&vals[1], &vals[0], x, x);
	mul_split_long_doubles(&vals[3], &vals[2], y, y);
	vals[4] = -1.0L;
	qsort(vals, 5, SIZEOF_LONG_DOUBLE, compare_long_doubles);
	for (register size_t i = 0; i <= 3; i++) {
		add_split_long_doubles(&vals[i + 1], &vals[i], vals[i + 1], vals[i]);
		qsort((vals + i + 1), (4 - i), SIZEOF_LONG_DOUBLE, compare_long_doubles);
	}
	return vals[4] + vals[3] + vals[2] + vals[1] + vals[0];
}


#endif


/** Return the Lanczos Sum for the given number */
LIB_FUNC MATH_FUNC double lanczos_sum(const double x) {
	register double num = 0.0, den = 0.0;
	if (!(x > 0.0)) { return 0.0; }
	register int i;
	if (x < 5.0) {
		for (i = 13; --i >= 0;) {
			num = ((num * x) + LANCZOS_NUM_COEFFS[i]);
			den = ((den * x) + LANCZOS_DEN_COEFFS[i]);
		}
	} else {
		for (i = 0; i < 13; i++) {
			num = ((num / x) + LANCZOS_NUM_COEFFS[i]);
			den = ((den / x) + LANCZOS_DEN_COEFFS[i]);
		}
	}
	return (num / den);
}


#endif  // MATH_H


/* COMPLEX/IMAGINARY MATH FUNCTIONS (<complex.h>) */


#if ((!(defined(COMPLEX_H) || defined(_COMPLEX_H) || defined(_COMPLEX_H_))) && SUPPORTS_COMPLEX)  // http://www.cplusplus.com/reference/complex/ & http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/complex.h.html
#define COMPLEX_H   (1)
#define _COMPLEX_H   (1)
#define _COMPLEX_H_   (1)
#define COMPLEX_INTERNAL_H_   (1)
#define __GSL_COMPLEX_MATH_H__   (1)
#define _XCOMPLEX_H_   (1)
#define _XREAL_H_   (1)


#define REAL_PART(z)   ((z).parts[0])
#define GET_REAL_PART(z)   ((z).parts[0])
#define IMAG_PART(z)   ((z).parts[1])
#define GET_IMAG_PART(z)   ((z).parts[1])


LIB_FUNC MATH_FUNC float cimagf(const complex_float z) {
	const complex_float_shape_t w = { .value = z };
	return (float)w.floats.im;
}


LIB_FUNC MATH_FUNC double cimag(const complex_double z) {
	const complex_double_shape_t w = { .value = z };
	return (double)w.doubles.im;
}


#if SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC long double cimagl(const complex_long_double z) {
	const complex_long_double_shape_t w = { .value = z };
	return (long double)w.longdoubles.im;
}
#endif


LIB_FUNC MATH_FUNC float crealf(const complex_float z) {
	const complex_float_shape_t w = { .value = z };
	return (float)w.floats.re;
}


LIB_FUNC MATH_FUNC double creal(const complex_double z) {
	const complex_double_shape_t w = { .value = z };
	return (double)w.doubles.re;
}


#if SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC long double creall(const complex_long_double z) {
	const complex_long_double_shape_t w = { .value = z };
	return (long double)w.longdoubles.re;
}
#endif


#ifndef normf
/** Return the norm value of the complex number */
LIB_FUNC MATH_FUNC float normf(const complex_float x) {
	const float real = crealf(x);
	const float vector = cimagf(x);
	return sqrtf((real * real) + (vector * vector));
}
#endif


#ifndef norm
/** Return the norm value of the complex number */
LIB_FUNC MATH_FUNC double norm(const complex_double x) {
	const double real = creal(x);
	const double vector = cimag(x);
	return sqrt((real * real) + (vector * vector));
}
#endif


#if ((!defined(norml)) && SUPPORTS_COMPLEX_LDBL)
/** Return the norm value of the complex number */
LIB_FUNC MATH_FUNC long double norml(const complex_long_double x) {
	const long double real = creall(x);
	const long double vector = cimagl(x);
	return sqrtl((real * real) + (vector * vector));
}
#endif


LIB_FUNC MATH_FUNC float cargf(const complex_float z) {
	return atan2f(cimagf(z), crealf(z));
}


LIB_FUNC MATH_FUNC double carg(const complex_double z) {
	return atan2(cimag(z), creal(z));
}


#if (LDBL_EQ_DBL && SUPPORTS_COMPLEX_LDBL)
LIB_FUNC MATH_FUNC long double cargl(const complex_long_double z) {
	return carg(z);
}
#elif SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC long double cargl(const complex_long_double z) {
	return atan2l(cimagl(z), creall(z));
}
#endif


LIB_FUNC MATH_FUNC float cabsf(const complex_float z) {
	return hypotf(crealf(z), cimagf(z));
}
#define c_absf(z)   cabsf((z))


LIB_FUNC MATH_FUNC double cabs(const complex_double z) {
	return hypot(creal(z), cimag(z));
}
#define c_abs(z)   cabs((z))


#if (LDBL_EQ_DBL && SUPPORTS_COMPLEX_LDBL)
LIB_FUNC MATH_FUNC long double cabsl(const complex_long_double z) {
	return (long double)cabs(z);
}
#   define c_absl(z)   cabsl((z))
#elif SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC long double cabsl(const complex_long_double z) {
	return hypotl(creall(z), cimagl(z));
}
#   define c_absl(z)   cabsl((z))
#endif


LIB_FUNC MATH_FUNC complex_float conjf(const complex_float z) {
	return CMPLXF(crealf(z), -cimagf(z));
}


LIB_FUNC MATH_FUNC complex_double conj(const complex_double z) {
	return CMPLX(creal(z), -cimag(z));
}


#if SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double conjl(const complex_long_double z) {
	return CMPLXL(creall(z), -cimagl(z));
}
#endif


/** Return the conjugate of a complex number */
LIB_FUNC MATH_FUNC complex_float conjugatef(const complex_float num) {
	return (crealf(num) + cimagf(num * -1.0F) * I_FLOAT);
}


/** Return the conjugate of a complex number */
LIB_FUNC MATH_FUNC complex_double conjugate(const complex_double num) {
	return (creal(num) + cimag(num * -1.0) * I_DOUBLE);
}


#if SUPPORTS_COMPLEX_LDBL
/** Return the conjugate of a complex number */
LIB_FUNC MATH_FUNC complex_long_double conjugatel(const complex_long_double num) {
	return (creall(num) + cimagl(num * -1.0L) * I_LONG_DOUBLE);
}
#endif


LIB_FUNC MATH_FUNC complex_float cprojf(const complex_float z) {
	if (__isinff(crealf(z)) || __isinff(cimagf(z))) {
		return CMPLXF(INFINITY, (copysignf(0.0F, crealf(z))));
	}
	return z;
}


LIB_FUNC MATH_FUNC complex_double cproj(const complex_double z) {
	if (__isinf(creal(z)) || __isinf(cimag(z))) {
		return CMPLX(INFINITY, (copysign(0.0, creal(z))));
	}
	return z;
}


#if (LDBL_EQ_DBL && SUPPORTS_COMPLEX_LDBL)
LIB_FUNC MATH_FUNC complex_long_double cprojl(const complex_long_double z) {
	return cproj(z);
}
#elif SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double cprojl(const complex_long_double z) {
	if (__isinfl(creall(z)) || __isinfl(cimagl(z))) {
		return CMPLXL(INFINITY, (copysignl(0.0L, creall(z))));
	}
	return z;
}
#endif


#if SUPPORTS_COMPLEX_LDBL


LIB_FUNC MATH_FUNC complex_long_double __multc3(const long double xc1, const long double yc1, const long double xc2, const long double yc2) {
	long double a = xc1, b = yc1, c = xc2, d = yc2;
	const long double ac = a * c, bd = b * d;
	const long double ad = a * d, bc = b * c;
	long double x = ac - bd, y = ad + bc;
	if (isnanl(x) && isnanl(y)) {
		register bool recalc = 0;
		if (isinfl(a) || isinfl(b)) {
			a = copysignl(isinfl(a) ? 1 : 0, a);
			b = copysignl(isinfl(b) ? 1 : 0, b);
			if (isnanl(c)) { c = copysignl(0, c); }
			if (isnanl(d)) { d = copysignl(0, d); }
			recalc = 1;
		}
		if (isinfl(c) || isinfl(d)) {
			c = copysignl(isinfl(c) ? 1 : 0, c);
			d = copysignl(isinfl(d) ? 1 : 0, d);
			if (isnanl(a)) { a = copysignl(0, a); }
			if (isnanl(b)) { b = copysignl(0, b); }
			recalc = 1;
		}
		if ((!recalc) && (isinfl(ac) || isinfl(bd) || isinfl(ad) || isinfl(bc))) {
			if (isnanl(a)) { a = copysignl(0, a); }
			if (isnanl(b)) { b = copysignl(0, b); }
			if (isnanl(c)) { c = copysignl(0, c); }
			if (isnanl(d)) { d = copysignl(0, d); }
			recalc = 1;
		}
		if (recalc) { x = INFINITY * (a * c - b * d); }
		y = INFINITY * (a * d + b * c);
	}
	return x + I_LONG_DOUBLE * y;
}


LIB_FUNC MATH_FUNC complex_long_double __divtc3(const long double xc1, const long double yc1, const long double xc2, const long double yc2) {
	long double denom, ratio, x, y, a = xc1, b = yc1, c = xc2, d = yc2;
	if (fabsl(c) < fabsl(d)) {
		ratio = c / d;
		denom = (c * ratio) + d;
		x = ((a * ratio) + b) / denom;
		y = ((b * ratio) - a) / denom;
	} else {
		ratio = d / c;
		denom = (d * ratio) + c;
		x = ((b * ratio) + a) / denom;
		y = (b - (a * ratio)) / denom;
	}
	if (isnanl(x) && isnanl(y)) {
		if (denom == 0.0 && (!isnanl(a) || !isnanl(b))) {
			x = copysignl(INFINITY, c) * a;
			y = copysignl(INFINITY, c) * b;
		} else if ((isinfl(a) || isinfl(b)) && isfinitel(c) && isfinitel(d)) {
			a = copysignl(isinfl(a) ? 1 : 0, a);
			b = copysignl(isinfl(b) ? 1 : 0, b);
			x = INFINITY * (a * c + b * d);
			y = INFINITY * (b * c - a * d);
		} else if ((isinfl(c) || isinfl(d)) && isfinitel(a) && isfinitel(b)) {
			c = copysignl(isinfl(c) ? 1 : 0, c);
			d = copysignl(isinfl(d) ? 1 : 0, d);
			x = 0.0 * (a * c + b * d);
			y = 0.0 * (b * c - a * d);
		}
	}
	return x + I_LONG_DOUBLE * y;
}


#endif


LIB_FUNC void cmul(const double c1, const double c2, const double d1, const double d2, double* e1, double* e2) {
	*e1 = c1 * d1 - c2 * d2;
	*e2 = c1 * d2 + c2 * d1;
}


LIB_FUNC void csq(const double c1, const double c2, double* e1, double* e2) {
	*e1 = c1 * c1 - c2 * c2;
	*e2 = c1 * c2 * 2;
}


/** Compute exp(x), scaled to avoid spurious overflow; An exponent is returned separately in 'expt'
* @Input: ln(FLT_MAX) <= x < ln(2 * FLT_MAX / FLT_MIN_DENORM) ~= 192.7
* @Output: 2**127 <= y < 2**128
*/
LIB_FUNC float __frexp_expf(const float x, int* restrict expt) {
	float exp_x = expf(x - 162.88958740F);
	uint32_t hx;
	GET_FLOAT_UWORD(hx, exp_x);
	*expt = (int)((int)(hx >> 23) - (0x7f + 127) + 235);
	SET_FLOAT_WORD(exp_x, ((hx & 0x7fffff) | 0x7f000000));
	return exp_x;
}


LIB_FUNC MATH_FUNC complex_float __ldexp_cexpf(const complex_float z, const int expt) {
	const float x = crealf(z), y = cimagf(z);
	int ex_expt, _expt = expt;
	const float exp_x = __frexp_expf(x, &ex_expt);
	_expt += ex_expt;
	int half_expt = _expt / 2;
	float scale1, scale2;
	SET_FLOAT_SWORD(scale1, ((0x7f + half_expt) << 23));
	half_expt = _expt - half_expt;
	SET_FLOAT_SWORD(scale2, ((0x7f + half_expt) << 23));
	return CMPLXF((cosf(y) * exp_x * scale1 * scale2), (sinf(y) * exp_x * scale1 * scale2));
}


LIB_FUNC MATH_FUNC complex_float _cexpf(const complex_float z) {
	const float x = crealf(z), y = cimagf(z);
	uint32_t hx, hy;
	GET_FLOAT_UWORD(hy, y);
	hy &= 0x7fffffff;
	if (hy == 0) { return CMPLXF(expf(x), y); }
	GET_FLOAT_UWORD(hx, x);
	if ((hx & 0x7fffffff) == 0) { return CMPLXF(cosf(y), sinf(y)); }
	else if (hy >= 0x7f800000) {
		if ((hx & 0x7fffffff) != 0x7f800000) {  // cexp(finite|NaN +- I Inf|NaN) = NaN + I NaN
			return CMPLXF(y - y, y - y);
		} else if (hx & 0x80000000) {  // cexp(-Inf +- I Inf|NaN) = 0 + I 0
			return CMPLXF(0.0, 0.0);
		} else {  // cexp(+Inf +- I Inf|NaN) = Inf + I NaN
			return CMPLXF(x, y - y);
		}
	} else if (hx >= 0x42b17218 && hx <= 0x43400074) {
		// x is between 88.7 and 192, so we must scale to avoid overflow in expf(x)
		return __ldexp_cexpf(z, 0);
	} else {
		/* Cases covered here:
		 * x < exp_ovfl and exp(x) will not overflow (common case)
		 * x > cexp_ovfl, so exp(x) * s overflows for all s > 0
		 * x = +-Inf (generated by exp())
		 * x = NaN (spurious inexact exception from y) */
		const float exp_x = expf(x);
		return CMPLXF((exp_x * cosf(y)), (exp_x * sinf(y)));
	}
}


/** Compute exp(x), scaled to avoid spurious overflow; An exponent is returned separately in 'expt'
* @Input: ln(DBL_MAX) <= x < ln(2 * DBL_MAX / DBL_MIN_DENORM) ~= 1454.91
* @Output: 2**1023 <= y < 2**1024
*/
LIB_FUNC double __frexp_exp(const double x, int* restrict expt) {
	uint32_t hx;
	double exp_x = exp(x - 1246.97177782734161156);
	GET_HIGH_WORD(hx, exp_x);
	*expt = (int)((int)(hx >> 20) - (0x3ff + 1023) + 1799);
	SET_HIGH_WORD(exp_x, (int)((hx & 0xfffff) | ((0x3ff + 1023) << 20)));
	return exp_x;
}


/** Intended for large arguments (real part >= ln(DBL_MAX)) where care is needed to avoid overflow */
LIB_FUNC MATH_FUNC complex_double __ldexp_cexp(const complex_double z, const int expt) {
	double x = creal(z), y = cimag(z), scale1, scale2;
	int ex_expt, _expt = expt;
	const double exp_x = __frexp_exp(x, &ex_expt);
	_expt += ex_expt;
	int half_expt = _expt / 2;
	INSERT_WORDS(scale1, (uint32_t)((0x3ff + half_expt) << 20), 0);
	half_expt = _expt - half_expt;
	INSERT_WORDS(scale2, (uint32_t)((0x3ff + half_expt) << 20), 0);
	return CMPLX((cos(y) * exp_x * scale1 * scale2), (sin(y) * exp_x * scale1 * scale2));
}


LIB_FUNC MATH_FUNC complex_double _cexp(const complex_double z) {
	const double x = creal(z), y = cimag(z);
	uint32_t hx, hy, lx, ly;
	EXTRACT_WORDS(hy, ly, y);
	hy &= 0x7fffffff;
	if ((hy | ly) == 0) { return CMPLX(exp(x), y); }
	EXTRACT_WORDS(hx, lx, x);
	if (((hx & 0x7fffffff) | lx) == 0) { return CMPLX(cos(y), sin(y)); }
	else if (hy >= 0x7ff00000) {
		if (lx != 0 || (hx & 0x7fffffff) != 0x7ff00000) {  // cexp(finite|NaN +- I Inf|NaN) = NaN + I NaN
			return CMPLX(y - y, y - y);
		} else if (hx & 0x80000000) {  // cexp(-Inf +- I Inf|NaN) = 0 + I 0
			return CMPLX(0.0, 0.0);
		} else {  // cexp(+Inf +- I Inf|NaN) = Inf + I NaN
			return CMPLX(x, y - y);
		}
	} else if (hx >= (uint32_t)0x40862e42 && hx <= (uint32_t)0x4096b8e4) {
		// x is between 709.7 and 1454.3, so we must scale to avoid overflow in exp(x)
		return __ldexp_cexp(z, 0);
	} else {
		/* Cases covered here:
		 * x < exp_ovfl and exp(x) will not overflow (common case)
		 * x > cexp_ovfl, so exp(x) * s overflows for all s > 0
		 * x = +-Inf (generated by exp())
		 * x = NaN (spurious inexact exception from y) */
		const double exp_x = exp(x);
		return CMPLX((exp_x * cos(y)), (exp_x * sin(y)));
	}
}


LIB_FUNC MATH_FUNC complex_float cexpf(const complex_float z) {
	const float x = crealf(z), y = cimagf(z), r = expf(x);
	return CMPLXF(r * cosf(y), r * sinf(y));
}


LIB_FUNC MATH_FUNC complex_double cexp(const complex_double z) {
	const double x = creal(z), y = cimag(z), r = exp(x);
	return (complex_double)(r * cos(y) + r * sin(y) * I);
}


#if SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double cexpl(const complex_long_double z) {
	const long double x = creall(z), y = cimagl(z), r = expl(x);
	return (complex_long_double)(r * cosl(y) + r * sinl(y) * I);
}
#endif


// COMPLEX LOGARITHM FUNCTIONS

LIB_FUNC MATH_FUNC complex_float clogf(const complex_float z) {
	const float r = cabsf(z), phi = cargf(z);
	return CMPLXF(logf(r), phi);
}


LIB_FUNC MATH_FUNC complex_double clog(const complex_double z) {
	const double r = cabs(z), phi = carg(z);
	return CMPLX(log(r), phi);
}


#if SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double clogl(const complex_long_double z) {
	const long double p = logl(cabsl(z));
	register long double rr = atan2l(cimagl(z), creall(z));
	return (complex_long_double)(p + rr * I);
}
#endif


LIB_FUNC MATH_FUNC complex_float clog10f(const complex_float z) {
	const float p = log10f(cabsf(z));
	const float rr = atan2f(cimagf(z), crealf(z)) * M_IVLN10F;
	return CMPLXF(p, rr);
}


LIB_FUNC MATH_FUNC complex_double clog10(const complex_double z) {
	const double p = log10(cabs(z));
	const double rr = atan2(cimag(z), creal(z)) * M_IVLN10;
	return (complex_double)(p + rr * I);
}


// COMPLEX POWER FUNCTIONS

LIB_FUNC MATH_FUNC complex_float cpowf(const complex_float z, const complex_float c) {
	return cexpf(c * clogf(z));
}


LIB_FUNC MATH_FUNC complex_double cpow(const complex_double z, const complex_double c) {
	return cexp(c * clog(z));
}


#if (LDBL_EQ_DBL && SUPPORTS_COMPLEX_LDBL)
LIB_FUNC MATH_FUNC complex_long_double cpowl(const complex_long_double z, const complex_long_double c) {
	return cpow(z, c);
}
#elif SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double cpowl(const complex_long_double z, const complex_long_double c) {
	return cexpl(c * clogl(z));
}
#endif


// COMPLEX SQUAREROOT FUNCTIONS

LIB_FUNC MATH_FUNC complex_float csqrtf(const complex_float z) {
	const float a = crealf(z), b = cimagf(z);
	double t;
	if (z == 0) { return CMPLXF(0, b); }
	else if (isinff(b)) { return CMPLXF(INFINITY, b); }
	else if (isnanf(a)) {
		t = (b - b) / (b - b);  // Raise invalid if b is not a NaN
		return CMPLXF(a, t);  // Return NaN + NaN i
	} else if (isinff(a)) {
		/* csqrtf(inf + NaN i) = inf + NaN i
		 * csqrtf(inf + y i) = inf + 0 i
		 * csqrtf(-inf + NaN i) = NaN +- inf i
		 * csqrtf(-inf + y i) = 0 + inf i */
		if (signbit(a)) { return CMPLXF(fabsf(b - b), copysignf(a, b)); }
		else { return CMPLXF(a, copysignf(b - b, b)); }
	}
	if (a >= 0) {
		t = sqrt((((double)a) + hypot((double)a, (double)b)) * 0.5);
		return CMPLXF(t, (b / (float)(2.0 * t)));
	} else {
		t = sqrt(((((double)-a) + hypot((double)a, (double)b)) * 0.5));
		return CMPLXF(fabsf(b) / (float)(2.0 * t), copysignf((float)t, b));
	}
}


LIB_FUNC MATH_FUNC complex_double csqrt(const complex_double z) {
	complex_double result;
	double a = creal(z), b = cimag(z), t;
	if (z == 0) { return CMPLX(0, b); }
	else if (__isinf(b)) { return CMPLX(INFINITY, b); }
	else if (__isnan(a)) {
		t = (b - b) / (b - b);  // Raise invalid if b is not a NaN
		return CMPLX(a, t);  // Return NaN + NaN i
	} else if (__isinf(a)) {
		/* csqrt(inf + NaN i) = inf + NaN i
		 * csqrt(inf + y i) = inf + 0 i
		 * csqrt(-inf + NaN i) = NaN +- inf i
		 * csqrt(-inf + y i) = 0 + inf i */
		if (signbit(a)) { return CMPLX(fabs(b - b), copysign(a, b)); }
		else { return CMPLX(a, copysign(b - b, b)); }
	}
	register int scale;
	if (fabs(a) >= 0x1.a827999fcef32P+1022 || fabs(b) >= 0x1.a827999fcef32P+1022) {
		a *= 0.25;
		b *= 0.25;
		scale = 1;
	} else { scale = 0; }
	if (a >= 0) {
		t = sqrt((a + hypot(a, b)) * 0.5);
		result = CMPLX(t, b / (t + t));
	} else {
		t = sqrt((-a + hypot(a, b)) * 0.5);
		result = CMPLX(fabs(b) / (t + t), copysign(t, b));
	}
	if (scale) { result *= 2; }
	return result;
}


#if SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double csqrtl(const complex_long_double z) {
	return csqrt((complex_double)z);
}
#endif


// COMPLEX TRIGONOMETRY FUNCTIONS

LIB_FUNC MATH_FUNC complex_float casinf(const complex_float z) {
	const float x = crealf(z), y = cimagf(z);
	const complex_float w = CMPLXF((1.0F - (x - y) * (x + y)), (-2.0F * x * y));
	return clogf(CMPLXF(-y, x) + csqrtf(w));
}


LIB_FUNC MATH_FUNC complex_double casin(const complex_double z) {
	const double x = creal(z), y = cimag(z);
	const complex_double w = CMPLX((1.0 - (x - y) * (x + y)), (-2.0 * x * y));
	return clog(CMPLX(-y, x) + csqrt(w));
}


#if (LDBL_EQ_DBL && SUPPORTS_COMPLEX_LDBL)
LIB_FUNC MATH_FUNC complex_long_double casinl(const complex_long_double z) {
	return (complex_long_double)casin((complex_double)z);
}
#elif SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double casinl(const complex_long_double z) {
	const long double x = creall(z), y = cimagl(z);
	const complex_long_double w = CMPLXL((1.0 - (x - y) * (x + y)), (-2.0 * x * y));
	return clogl(CMPLXL(-y, x) + csqrtl(w));
}
#endif


LIB_FUNC MATH_FUNC complex_float cacosf(const complex_float z) {
	const complex_float y = casinf(z);
	return CMPLXF(((float)M_PI_2 - crealf(y)), -cimagf(y));
}


LIB_FUNC MATH_FUNC complex_double cacos(const complex_double z) {
	const complex_double y = casin(z);
	return CMPLX(M_PI_2 - creal(y), -cimag(y));
}


#if (LDBL_EQ_DBL && SUPPORTS_COMPLEX_LDBL)
LIB_FUNC MATH_FUNC complex_long_double cacosl(const complex_long_double z) {
	return cacos(z);
}
#elif SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double cacosl(const complex_long_double z) {
	const complex_long_double y = casinl(z);
	return CMPLXL((M_PI_2L - creall(y)), -cimagl(y));
}
#endif


LIB_FUNC MATH_FUNC complex_float cacoshf(const complex_float z) {
	const complex_float y = cacosf(z);
	return CMPLXF(-cimagf(y), crealf(y));
}


LIB_FUNC MATH_FUNC complex_double cacosh(const complex_double z) {
	const complex_double y = cacos(z);
	return CMPLX(-cimag(y), creal(y));
}


#if (LDBL_EQ_DBL && SUPPORTS_COMPLEX_LDBL)
LIB_FUNC MATH_FUNC complex_long_double cacoshl(const complex_long_double z) {
	return (complex_long_double)cacosh((complex_double)z);
}
#elif SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double cacoshl(const complex_long_double z) {
	const complex_long_double y = cacosl(z);
	return CMPLXL(-cimagl(y), creall(y));
}
#endif


LIB_FUNC MATH_FUNC complex_float casinhf(const complex_float z) {
	const complex_float y = casinf(CMPLXF(-cimagf(z), crealf(z)));
	return CMPLXF(cimagf(y), -crealf(y));
}


LIB_FUNC MATH_FUNC complex_double casinh(const complex_double z) {
	const complex_double y = casin(CMPLX(-cimag(z), creal(z)));
	return CMPLX(cimag(y), -creal(y));
}


#if (LDBL_EQ_DBL && SUPPORTS_COMPLEX_LDBL)
LIB_FUNC MATH_FUNC complex_long_double casinhl(const complex_long_double z) {
	return (complex_long_double)casinh((complex_double)z);
}
#elif SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double casinhl(const complex_long_double z) {
	const complex_long_double y = casinl(CMPLXL(-cimagl(z), creall(z)));
	return CMPLXL(cimagl(y), -creall(y));
}
#endif


LIB_FUNC MATH_FUNC float _redupif(const float x) {
	register float t = x / (float)M_PI;
	if (t >= 0.0F) { t += 0.5F; }
	else { t -= 0.5F; }
	const long i = (long)t;
	t = (float)i;
	t = ((x - t * 3.140625F) - t * 9.67502593994140625E-4F) - t * 1.509957990978376432E-7F;
	return t;
}
#define redupif(x)   _redupif((x))
#define __redupif(x)   _redupif((x))


LIB_FUNC MATH_FUNC complex_float catanf(const complex_float z) {
	const float x = crealf(z), y = cimagf(z);
	const float x2 = x * x;
	float a = (1.0F - x2 - (y * y));
	if (((x == 0.0F) && (y > 1.0F)) || (a == 0.0F)) { return CMPLXF_MAX_10; }
	const complex_float w = _redupif(0.5F * atan2f(2.0F * x, a));
	register float t = y - 1.0F;
	a = x2 + (t * t);
	if (a == 0.0F) { return CMPLXF_MAX_10; }
	t = y + 1.0F;
	a = (x2 + (t * t)) / a;
	return CMPLXF(w, (0.25F * logf(a)));
}


LIB_FUNC MATH_FUNC double _redupi(const double x) {
	double t = x / M_PI;
	if (t >= 0.0) { t += 0.5; }
	else { t -= 0.5; }
	const long i = (long)t;
	t = (double)i;
	return ((x - t * PI) - t * 1.98418714791870343106E-9) - t * 1.14423774522196636802E-17;
}


LIB_FUNC MATH_FUNC complex_double catan(const complex_double z) {
	const double x = creal(z), y = cimag(z);
	const double x2 = x * x;
	double a = 1.0 - x2 - (y * y);
	if ((x == 0.0 && y > 1.0) || (a == 0.0)) { return CMPLX_MAX_10; }
	const complex_double w = _redupi(0.5 * atan2(2.0 * x, a));
	double t = y - 1.0;
	a = x2 + (t * t);
	if (a == 0.0) { return CMPLX_MAX_10; }
	t = y + 1.0;
	a = (x2 + t * t) / a;
	return CMPLX(w, (0.25 * log(a)));
}


#if (LDBL_EQ_DBL && SUPPORTS_COMPLEX_LDBL)
LIB_FUNC MATH_FUNC complex_long_double catanl(const complex_long_double z) {
	return catan(z);
}
#elif SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC long double redupil(const long double x) {
	long double t = x / PIL;
	if (t >= 0.0L) { t += 0.5L; }
	else { t -= 0.5L; }
	const long long i = (long long)t;
	t = (long double)i;
	return ((x - t * PIL) - t * 1.6667485837041756656403424829301998703007E-19L) - t * 1.8830410776607851167459095484560349402753E-39L;
}


LIB_FUNC MATH_FUNC complex_long_double catanl(const complex_long_double z) {
	const long double x = creall(z), y = cimagl(z);
	const long double x2 = x * x;
	long double a = 1.0L - x2 - (y * y);
	if (((x == 0.0L) && (y > 1.0L)) || (a == 0.0L)) { return CMPLXL(LDBL_MAX, LDBL_MAX); }
	const complex_long_double w = redupil(atan2l(2.0L * x, a) * 0.5L);
	long double t = y - 1.0L;
	a = x2 + (t * t);
	if (a == 0.0L) { return CMPLXL(LDBL_MAX, LDBL_MAX); }
	t = y + 1.0L;
	a = (x2 + (t * t)) / a;
	return CMPLXL(w, (0.25L * logl(a)));
}
#endif


LIB_FUNC MATH_FUNC complex_float catanhf(const complex_float z) {
	const complex_float y = catanf(CMPLXF(-cimagf(z), crealf(z)));
	return CMPLXF(cimagf(y), -crealf(y));
}


LIB_FUNC MATH_FUNC complex_double catanh(const complex_double z) {
	const complex_double y = catan(CMPLX(-cimag(z), creal(z)));
	return CMPLX(cimag(y), -creal(y));
}


#if (LDBL_EQ_DBL && SUPPORTS_COMPLEX_LDBL)
LIB_FUNC MATH_FUNC complex_long_double catanhl(const complex_long_double z) {
	return catanh(z);
}
#elif SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double catanhl(const complex_long_double z) {
	const complex_long_double y = catanl(CMPLXL(-cimagl(z), creall(z)));
	return CMPLXL(cimagl(y), -creall(y));
}
#endif


LIB_FUNC MATH_FUNC complex_float ccoshf(const complex_float num) {
	complex_float z = num;
	float x = crealf(z), y = cimagf(z), h;
	int32_t hx, hy;
	GET_FLOAT_WORD(hx, x);
	GET_FLOAT_WORD(hy, y);
	const int32_t ix = 0x7fffffff & hx;
	const int32_t iy = 0x7fffffff & hy;
	if (ix < 0x7f800000 && iy < 0x7f800000) {
		if (iy == 0) { return CMPLXF(coshf(x), x * y); }
		else if (ix < 0x41100000) { return CMPLXF(coshf(x) * cosf(y), sinhf(x) * sinf(y)); }
		else if (ix < 0x42b17218) {
			h = expf(fabsf(x)) * 0.5f;
			return CMPLXF(h * cosf(y), copysignf(h, x) * sinf(y));
		} else if (ix < 0x4340b1e7) {
			z = __ldexp_cexpf(CMPLXF(fabsf(x), y), -1);
			return CMPLXF(crealf(z), cimagf(z) * copysignf(1, x));
		} else {
			h = 0x1.0P+127F * x;
			return CMPLXF(h * h * cosf(y), h * sinf(y));
		}
	}
	if (ix == 0 && iy >= 0x7f800000) { return CMPLXF(y - y, copysignf(0, x * (y - y))); }
	else if (iy == 0 && ix >= 0x7f800000) {
		if ((hx & 0x7fffff) == 0) { return CMPLXF(x * x, copysignf(0, x) * y); }
		return CMPLXF(x * x, copysignf(0, (x + x) * y));
	}
	else if (ix < 0x7f800000 && iy >= 0x7f800000) { return CMPLXF(y - y, x * (y - y)); }
	else if (ix >= 0x7f800000 && (hx & 0x7fffff) == 0) {
		if (iy >= 0x7f800000) { return CMPLXF(x * x, x * (y - y)); }
		return CMPLXF((x * x) * cosf(y), x * sinf(y));
	}
	return CMPLXF(((x * x) * (y - y)), ((x + x) * (y - y)));
}


LIB_FUNC MATH_FUNC complex_double ccosh(const complex_double num) {
	complex_double z = num;
	const double x = creal(z), y = cimag(z);
	double h;
	int32_t hx, hy, lx, ly;
	EXTRACT_SWORDS(hx, lx, x);
	EXTRACT_SWORDS(hy, ly, y);
	const int32_t ix = 0x7fffffff & hx;
	const int32_t iy = 0x7fffffff & hy;
	if (ix < 0x7ff00000 && iy < 0x7ff00000) {
		if ((iy | ly) == 0) { return CMPLX(cosh(x), x * y); }
		else if (ix < 0x40360000) { return CMPLX(cosh(x) * cos(y), sinh(x) * sin(y)); }
		else if (ix < 0x40862e42) {
			h = exp(fabs(x)) * 0.5;
			return CMPLX(h * cos(y), copysign(h, x) * sin(y));
		} else if (ix < 0x4096bbaa) {
			z = __ldexp_cexp(CMPLX(fabs(x), y), -1);
			return CMPLX(creal(z), cimag(z) * copysign(1, x));
		} else {
			h = (0x1.0P+1023 * x);
			return CMPLX(h * h * cos(y), h * sin(y));
		}
	}
	if ((ix | lx) == 0 && iy >= 0x7ff00000) { return CMPLX(y - y, copysign(0, x * (y - y))); }
	else if ((iy | ly) == 0 && ix >= 0x7ff00000) {
		if (((hx & 0xfffff) | lx) == 0) { return CMPLX(x * x, copysign(0, x) * y); }
		return CMPLX(x * x, copysign(0, (x + x) * y));
	}
	else if (ix < 0x7ff00000 && iy >= 0x7ff00000) { return CMPLX(y - y, x * (y - y)); }
	else if (ix >= 0x7ff00000 && ((hx & 0xfffff) | lx) == 0) {
		if (iy >= 0x7ff00000) { return CMPLX(x * x, x * (y - y)); }
		return CMPLX((x * x) * cos(y), x * sin(y));
	}
	return CMPLX(((x * x) * (y - y)), ((x + x) * (y - y)));
}


#if SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double ccoshl(const complex_long_double z) {
	return (complex_long_double)ccosh((complex_double)z);
}
#endif


LIB_FUNC MATH_FUNC complex_float ccosf(const complex_float z) {
	return ccoshf(CMPLXF(-cimagf(z), crealf(z)));
}


LIB_FUNC MATH_FUNC complex_double ccos(const complex_double z) {
	return ccosh(CMPLX(-cimag(z), creal(z)));
}


#if (LDBL_EQ_DBL && SUPPORTS_COMPLEX_LDBL)
LIB_FUNC MATH_FUNC complex_long_double ccosl(const complex_long_double z) {
	return (complex_long_double)ccos((complex_double)z);
}
#elif SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double ccosl(const complex_long_double z) {
	return ccoshl(CMPLXL(-cimagl(z), creall(z)));
}
#endif


LIB_FUNC MATH_FUNC complex_float csinhf(const complex_float num) {
	complex_float z = num;
	const float x = crealf(z), y = cimagf(z);
	float h;
	int32_t hx, hy;
	GET_FLOAT_WORD(hx, x);
	GET_FLOAT_WORD(hy, y);
	const int32_t ix = 0x7fffffff & hx;
	const int32_t iy = 0x7fffffff & hy;
	if (ix < 0x7f800000 && iy < 0x7f800000) {
		if (iy == 0) { return CMPLXF(sinhf(x), y); }
		else if (ix < 0x41100000) { return CMPLXF(sinhf(x) * cosf(y), coshf(x) * sinf(y)); }
		else if (ix < 0x42b17218) {
			h = expf(fabsf(x)) * 0.5f;
			return CMPLXF(copysignf(h, x) * cosf(y), h * sinf(y));
		} else if (ix < 0x4340b1e7) {
			z = __ldexp_cexpf(CMPLXF(fabsf(x), y), -1);
			return CMPLXF(crealf(z) * copysignf(1, x), cimagf(z));
		} else {
			h = 0x1.0P+127F * x;
			return CMPLXF(h * cosf(y), (h * h * sinf(y)));
		}
	}
	if (ix == 0 && iy >= 0x7f800000) { return CMPLXF(copysignf(0, x * (y - y)), y - y); }
	else if (iy == 0 && ix >= 0x7f800000) {
		if ((hx & 0x7fffff) == 0) { return CMPLXF(x, y); }
		return CMPLXF(x, copysignf(0, y));
	} else if (ix < 0x7f800000 && iy >= 0x7f800000) { return CMPLXF(y - y, x * (y - y)); }
	else if (ix >= 0x7f800000 && (hx & 0x7fffff) == 0) {
		if (iy >= 0x7f800000) { return CMPLXF(x * x, x * (y - y)); }
		return CMPLXF(x * cosf(y), INFF * sinf(y));
	}
	return CMPLXF(((x * x) * (y - y)), ((x + x) * (y - y)));
}


LIB_FUNC MATH_FUNC complex_double csinh(const complex_double num) {
	complex_double z = num;
	const double x = creal(z), y = cimag(z);
	double h;
	int32_t hx, hy, lx, ly;
	EXTRACT_SWORDS(hx, lx, x);
	EXTRACT_SWORDS(hy, ly, y);
	const int32_t ix = 0x7fffffff & hx;
	const int32_t iy = 0x7fffffff & hy;
	if (ix < 0x7ff00000 && iy < 0x7ff00000) {
		if ((iy | ly) == 0) { return CMPLX(sinh(x), y); }
		else if (ix < 0x40360000) { return CMPLX(sinh(x) * cos(y), cosh(x) * sin(y)); }
		if (ix < 0x40862e42) {
			h = exp(fabs(x)) * 0.5;
			return CMPLX(copysign(h, x) * cos(y), h * sin(y));
		} else if (ix < 0x4096bbaa) {
			z = __ldexp_cexp(CMPLX(fabs(x), y), -1);
			return CMPLX(creal(z) * copysign(1, x), cimag(z));
		} else {
			h = (0x1.0P+1023 * x);
			return CMPLX(h * cos(y), (h * h * sin(y)));
		}
	}
	if ((ix | lx) == 0 && iy >= 0x7ff00000) { return CMPLX(copysign(0, x * (y - y)), y - y); }
	else if ((iy | ly) == 0 && ix >= 0x7ff00000) {
		if (((hx & 0xfffff) | lx) == 0) { return CMPLX(x, y); }
		return CMPLX(x, copysign(0, y));
	} else if (ix < 0x7ff00000 && iy >= 0x7ff00000) { return CMPLX(y - y, x * (y - y)); }
	else if (ix >= 0x7ff00000 && ((hx & 0xfffff) | lx) == 0) {
		if (iy >= 0x7ff00000) { return CMPLX(x * x, x * (y - y)); }
		return CMPLX(x * cos(y), INFINITY * sin(y));
	}
	return CMPLX(((x * x) * (y - y)), ((x + x) * (y - y)));
}


#if SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double csinhl(const complex_long_double z) {
	return (complex_long_double)csinh((complex_double)z);
}
#endif


LIB_FUNC MATH_FUNC complex_float csinf(const complex_float z) {
	const complex_float y = csinhf(CMPLXF(-cimagf(z), crealf(z)));
	return CMPLXF(cimagf(y), -crealf(y));
}


LIB_FUNC MATH_FUNC complex_double csin(const complex_double z) {
	const complex_double y = csinh(CMPLX(-cimag(z), creal(z)));
	return CMPLX(cimag(y), -creal(y));
}


#if (LDBL_EQ_DBL && SUPPORTS_COMPLEX_LDBL)
LIB_FUNC MATH_FUNC complex_long_double csinl(const complex_long_double z) {
	return (complex_long_double)csin((complex_double)z);
}
#elif SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double csinl(const complex_long_double z) {
	const complex_long_double y = csinhl(CMPLXL(-cimagl(z), creall(z)));
	return CMPLXL(cimagl(y), -creall(y));
}
#endif


LIB_FUNC MATH_FUNC complex_float ctanhf(const complex_float z) {
	float x = crealf(z), y = cimagf(z);
	uint32_t hx;
	GET_FLOAT_UWORD(hx, x);
	const uint32_t ix = hx & 0x7fffffff;
	if (ix >= 0x7f800000) {
		if (ix & 0x7fffff) { return CMPLXF(x, (y == 0 ? y : x * y)); }
		SET_FLOAT_WORD(x, (hx - 0x40000000));
		return CMPLXF(x, copysignf(0, isinf(y) ? y : sinf(y) * cosf(y)));
	} else if (!isfinite(y)) { return CMPLXF(ix ? y - y : x, y - y); }
	else if (ix >= 0x41300000) {  // x >= 11
		const float exp_mx = expf(-fabsf(x));
		return CMPLXF(copysignf(1, x), (4 * sinf(y) * cosf(y) * exp_mx * exp_mx));
	}
	const float t = tanf(y);
	const float beta = 1.0F + t * t;
	const float s = sinhf(x);
	const float denom = 1.0F + beta * s * s;
	return CMPLXF(((beta * sqrtf((1.0F + s * s)) * s) / denom), (t / denom));
}


LIB_FUNC MATH_FUNC complex_double ctanh(const complex_double z) {
	double x = creal(z), y = cimag(z);
	uint32_t hx, lx;
	EXTRACT_WORDS(hx, lx, x);
	const uint32_t ix = hx & 0x7fffffff;
	/* ctanh(NaN + i 0) = NaN + i 0
	 * ctanh(NaN + i y) = NaN + i NaN (if y != 0)
	 * ctanh(+-Inf +- i Inf) = +-1 +- 0
	 * ctanh(+-Inf + i y) = +-1 + 0 sin(2y) (if y is finite) */
	if (ix >= 0x7ff00000) {
		if ((ix & 0xfffff) | lx) { return CMPLX(x, (y == 0 ? y : x * y)); }  // x is NaN
		SET_HIGH_WORD(x, (int)(hx - 0x40000000));  // x = copysign(1, x)
		return CMPLX(x, copysign(0, __isinf(y) ? y : sin(y) * cos(y)));
	}
	/* ctanh(+-0 + i NAN) = +-0 + i NaN
	 * ctanh(+-0 +- i Inf) = +-0 + i NaN
	 * ctanh(x + i NAN) = NaN + i NaN
	 * ctanh(x +- i Inf) = NaN + i NaN */
	else if (!isfinite(y)) { return CMPLX(x ? y - y : x, y - y); }
	else if (ix >= 0x40360000) {  // x >= 22
		const double exp_mx = exp(-fabs(x));
		return CMPLX(copysign(1, x), (4 * sin(y) * cos(y) * exp_mx * exp_mx));
	}
	const double t = tan(y);
	const double beta = 1.0 + t * t;
	const double s = sinh(x);
	const double denom = 1.0 + beta * s * s;
	return CMPLX(((beta * sqrt(1.0 + s * s) * s) / denom), (t / denom));
}


#if SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double ctanhl(const complex_long_double z) {
	return (complex_long_double)ctanh((complex_double)z);
}
#endif


LIB_FUNC MATH_FUNC complex_float ctanf(const complex_float z) {
	const complex_float y = ctanhf(CMPLXF(-cimagf(z), crealf(z)));
	return CMPLXF(cimagf(y), -crealf(y));
}


LIB_FUNC MATH_FUNC complex_double ctan(const complex_double z) {
	const complex_double y = ctanh(CMPLX(-cimag(z), creal(z)));
	return CMPLX(cimag(y), -creal(y));
}


#if (LDBL_EQ_DBL && SUPPORTS_COMPLEX_LDBL)
LIB_FUNC MATH_FUNC complex_long_double ctanl(const complex_long_double z) {
	return ctan(z);
}
#elif SUPPORTS_COMPLEX_LDBL
LIB_FUNC MATH_FUNC complex_long_double ctanl(const complex_long_double z) {
	const complex_long_double y = ctanhl(CMPLXL(-cimagl(z), creall(z)));
	return CMPLXL(cimagl(y), -creall(y));
}
#endif


/** Calculate cosh and sinh */
LIB_FUNC void _cchshf(const float x, float* restrict c, float* restrict s) {
	if (fabsf(x) <= 0.5F) {
		*c = coshf(x);
		*s = sinhf(x);
	} else {
		register float e = expf(x);
		const float ei = 0.5F / e;
		e = 0.5F * e;
		*s = e - ei;
		*c = e + ei;
	}
}


LIB_FUNC void _cchsh(const double x, double* restrict c, double* restrict s) {
	if (fabs(x) <= 0.5) {
		*c = cosh(x);
		*s = sinh(x);
	} else {
		register double e = exp(x);
		const double ei = 0.5 / e;
		e = 0.5 * e;
		*s = e - ei;
		*c = e + ei;
	}
}


/** Taylor series expansion for cosh(2y) - cos(2x) */
LIB_FUNC MATH_FUNC float _ctansf(const complex_float z) {
	float x = fabsf(2.0F * crealf(z)), y = fabsf(2.0F * cimagf(z));
	register float f = 1.0F, x2 = 1.0F, y2 = 1.0F, rn = 0.0F, t, d = 0.0F;
	x = _redupif(x);
	x *= x;
	y *= y;
	do {
		rn += 1.0F;
		f *= rn;
		rn += 1.0F;
		f *= rn;
		x2 *= x;
		y2 *= y;
		t = y2 + x2;
		t /= f;
		d += t;
		rn += 1.0F;
		f *= rn;
		rn += 1.0F;
		f *= rn;
		x2 *= x;
		y2 *= y;
		t = y2 - x2;
		t /= f;
		d += t;
	} while (fabsf(t / d) > 3.0E-8F);
	return d;
}


/** Taylor series expansion for cosh(2y) - cos(2x) */
LIB_FUNC MATH_FUNC double _ctans(const complex_double z) {
	double f = 1.0, x2 = 1.0, y2 = 1.0, rn = 0.0, t, d = 0.0;
	register double x = fabs(2.0 * creal(z)), y = fabs(2.0 * cimag(z));
	x = _redupi(x);
	x *= x;
	y *= y;
	do {
		rn += 1.0;
		f *= rn;
		rn += 1.0;
		f *= rn;
		x2 *= x;
		y2 *= y;
		t = y2 + x2;
		t /= f;
		d += t;
		rn += 1.0;
		f *= rn;
		rn += 1.0;
		f *= rn;
		x2 *= x;
		y2 *= y;
		t = y2 - x2;
		t /= f;
		d += t;
	} while (fabs(t / d) > 1.1E-16);
	return d;
}


// TRIGONOMETRY (COMPLEX FLOATS)

/** Return the Chord */
LIB_FUNC MATH_FUNC complex_float ccrdf(const complex_float radians) {
	return ((complex_float)2.0F + 2.0F * I_FLOAT * csinf(radians / (complex_float)2.0F + 2.0F * I_FLOAT));
}


/** Return the Arc-Cotangent (acot(x) || arccot(x) == atan(1/x)) */
LIB_FUNC MATH_FUNC complex_float cacotf(const complex_float radians) {
	return catanf((complex_float)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Arc-Cotangent (acot(x) || arccot(x) == atan(1/x)) */
LIB_FUNC MATH_FUNC complex_float carccotf(const complex_float radians) {
	return catanf((complex_float)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x) || arccoth(x) == atanh(1/x)) */
LIB_FUNC MATH_FUNC complex_float cacothf(const complex_float radians) {
	return catanhf((complex_float)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x) || arccoth(x) == atanh(1/x)) */
LIB_FUNC MATH_FUNC complex_float carccothf(const complex_float radians) {
	return catanhf((complex_float)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Cotangent (coth(x) == 1/tanh(x)) */
LIB_FUNC MATH_FUNC complex_float ccothf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT / ctanhf(radians));
}


/** Return the Cotangent (cot(x) == 1/tan(x)) */
LIB_FUNC MATH_FUNC complex_float ccotf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT / ctanf(radians));
}


/** Return the Arc-Cosecant (acsc(x) || arccsc(x) == asin(1/x)) */
LIB_FUNC MATH_FUNC complex_float cacscf(const complex_float radians) {
	return casinf((complex_float)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Arc-Cosecant (acsc(x) || arccsc(x) == asin(1/x)) */
LIB_FUNC MATH_FUNC complex_float carccscf(const complex_float radians) {
	return casinf((complex_float)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsch(x) || arccsch(x) == asinh(1/x)) */
LIB_FUNC MATH_FUNC complex_float cacschf(const complex_float radians) {
	return casinhf((complex_float)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsc(x) || arccsch(x) == asinh(1/x)) */
LIB_FUNC MATH_FUNC complex_float carccschf(const complex_float radians) {
	return casinhf((complex_float)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Cosecant (csch(x) == 1/sinh(x)) */
LIB_FUNC MATH_FUNC complex_float ccschf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT / csinhf(radians));
}


/** Return the Cosecant (csc(x) == 1/sin(x)) */
LIB_FUNC MATH_FUNC complex_float ccscf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT / csinf(radians));
}


/** Return the Arc-Secant (asec(x) || arcsec(x) == acos(1/x)) */
LIB_FUNC MATH_FUNC complex_float casecf(const complex_float radians) {
	return cacosf((complex_float)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Arc-Secant (asec(x) || arcsec(x) == acos(1/x)) */
LIB_FUNC MATH_FUNC complex_float carcsecf(const complex_float radians) {
	return cacosf((complex_float)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x) || arcsech(x) == acosh(1/x)) */
LIB_FUNC MATH_FUNC complex_float casechf(const complex_float radians) {
	return cacoshf((complex_float)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x) || arcsech(x) == acosh(1/x)) */
LIB_FUNC MATH_FUNC complex_float carcsechf(const complex_float radians) {
	return cacoshf((complex_float)1.0F + 1.0F * I_FLOAT / radians);
}


/** Return the Hyperbolic Secant (sech(x) == 1/cosh(x)) */
LIB_FUNC MATH_FUNC complex_float csechf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT / ccoshf(radians));
}


/** Return the Secant (sec(x) == 1/cos(x)) */
LIB_FUNC MATH_FUNC complex_float csecf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT / ccosf(radians));
}


/** Return the Arc-Versed Sine (arcversin(x) == 1 - acos(x)) */
LIB_FUNC MATH_FUNC complex_float carcversinf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT - cacosf(radians));
}


/** Return the Hyperbolic Arc-Versed Sine (arcversinh(x) == 1 - acosh(x)) */
LIB_FUNC MATH_FUNC complex_float carcversinhf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT - cacoshf(radians));
}


/** Return the Hyperbolic Versed Sine (versinh(x) == 1 - cosh(x)) */
LIB_FUNC MATH_FUNC complex_float cversinhf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT - ccoshf(radians));
}


/** Return the Versed Sine (versin(x) == 1 - cos(x)) */
LIB_FUNC MATH_FUNC complex_float cversinf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT - ccosf(radians));
}


/** Return the Arc-Versed Cosine (arcvercos(x) == 1 - asin(x)) */
LIB_FUNC MATH_FUNC complex_float carcvercosf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT - casinf(radians));
}


/** Return the Hyperbolic Arc-Versed Cosine (arcvercosh(x) == 1 - asinh(x)) */
LIB_FUNC MATH_FUNC complex_float carcvercoshf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT - casinhf(radians));
}


/** Return the Hyperbolic Versed Cosine (vercosh(x) == 1 - sinh(x)) */
LIB_FUNC MATH_FUNC complex_float cvercoshf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT - csinhf(radians));
}


/** Return the Versed Cosine (vercos(x) == 1 - sin(x)) */
LIB_FUNC MATH_FUNC complex_float cvercosf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT - csinf(radians));
}


/** Return the Haversine (haversin(x) == 0.5*(1 - cos(x))) */
LIB_FUNC MATH_FUNC complex_float chaversinf(const complex_float radians) {
	return ((complex_float)0.5F * ((complex_float)1.0F + 1.0F * I_FLOAT - ccosf(radians)));
}


/** Return the Hacoversine (hacoversin(x) == 0.5*(1 - sin(x))) */
LIB_FUNC MATH_FUNC complex_float chacoversinf(const complex_float radians) {
	return ((complex_float)0.5F * ((complex_float)1.0F + 1.0F * I_FLOAT - csinf(radians)));
}


// TRIGONOMETRY (COMPLEX DOUBLES)

/** Return the Chord */
LIB_FUNC MATH_FUNC complex_double ccrd(const complex_double radians) {
	return ((complex_double)2.0 + 2.0 * I_DOUBLE * csin(radians / (complex_double)2.0 + 2.0 * I_DOUBLE));
}


/** Return the Arc-Cotangent (acot(x) || arccot(x) == atan(1/x)) */
LIB_FUNC MATH_FUNC complex_double cacot(const complex_double radians) {
	return catan((complex_double)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Arc-Cotangent (acot(x) || arccot(x) == atan(1/x)) */
LIB_FUNC MATH_FUNC complex_double carccot(const complex_double radians) {
	return catan((complex_double)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x) || arccoth(x) == atanh(1/x)) */
LIB_FUNC MATH_FUNC complex_double cacoth(const complex_double radians) {
	return catanh((complex_double)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x) || arccoth(x) == atanh(1/x)) */
LIB_FUNC MATH_FUNC complex_double carccoth(const complex_double radians) {
	return catanh((complex_double)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Cotangent (coth(x) == 1/tanh(x)) */
LIB_FUNC MATH_FUNC complex_double ccoth(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE / ctanh(radians));
}


/** Return the Cotangent (cot(x) == 1/tan(x)) */
LIB_FUNC MATH_FUNC complex_double ccot(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE / ctan(radians));
}


/** Return the Arc-Cosecant (acsc(x) || arccsc(x) == asin(1/x)) */
LIB_FUNC MATH_FUNC complex_double cacsc(const complex_double radians) {
	return casin((complex_double)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Arc-Cosecant (acsc(x) || arccsc(x) == asin(1/x)) */
LIB_FUNC MATH_FUNC complex_double carccsc(const complex_double radians) {
	return casin((complex_double)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsch(x) || arccsch(x) == asinh(1/x)) */
LIB_FUNC MATH_FUNC complex_double cacsch(const complex_double radians) {
	return casinh((complex_double)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsc(x) || arccsch(x) == asinh(1/x)) */
LIB_FUNC MATH_FUNC complex_double carccsch(const complex_double radians) {
	return casinh((complex_double)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Cosecant (csch(x) == 1/sinh(x)) */
LIB_FUNC MATH_FUNC complex_double ccsch(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE / csinh(radians));
}


/** Return the Cosecant (csc(x) == 1/sin(x)) */
LIB_FUNC MATH_FUNC complex_double ccsc(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE / csin(radians));
}


/** Return the Arc-Secant (asec(x) || arcsec(x) == acos(1/x)) */
LIB_FUNC MATH_FUNC complex_double casec(const complex_double radians) {
	return cacos((complex_double)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Arc-Secant (asec(x) || arcsec(x) == acos(1/x)) */
LIB_FUNC MATH_FUNC complex_double carcsec(const complex_double radians) {
	return cacos((complex_double)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x) || arcsech(x) == acosh(1/x)) */
LIB_FUNC MATH_FUNC complex_double casech(const complex_double radians) {
	return cacosh((complex_double)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x) || arcsech(x) == acosh(1/x)) */
LIB_FUNC MATH_FUNC complex_double carcsech(const complex_double radians) {
	return cacosh((complex_double)1.0 + 1.0 * I_DOUBLE / radians);
}


/** Return the Hyperbolic Secant (sech(x) == 1/cosh(x)) */
LIB_FUNC MATH_FUNC complex_double csech(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE / ccosh(radians));
}


/** Return the Secant (sec(x) == 1/cos(x)) */
LIB_FUNC MATH_FUNC complex_double csec(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE / ccos(radians));
}


/** Return the Arc-Versed Sine (arcversin(x) == 1 - acos(x)) */
LIB_FUNC MATH_FUNC complex_double carcversin(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE - cacos(radians));
}


/** Return the Hyperbolic Arc-Versed Sine (arcversinh(x) == 1 - acosh(x)) */
LIB_FUNC MATH_FUNC complex_double carcversinh(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE - cacosh(radians));
}


/** Return the Hyperbolic Versed Sine (versinh(x) == 1 - cosh(x)) */
LIB_FUNC MATH_FUNC complex_double cversinh(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE - ccosh(radians));
}


/** Return the Versed Sine (versin(x) == 1 - cos(x)) */
LIB_FUNC MATH_FUNC complex_double cversin(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE - ccos(radians));
}


/** Return the Arc-Versed Cosine (arcvercos(x) == 1 - asin(x)) */
LIB_FUNC MATH_FUNC complex_double carcvercos(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE - casin(radians));
}


/** Return the Hyperbolic Arc-Versed Cosine (arcvercosh(x) == 1 - asinh(x)) */
LIB_FUNC MATH_FUNC complex_double carcvercosh(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE - casinh(radians));
}


/** Return the Hyperbolic Versed Cosine (vercosh(x) == 1 - sinh(x)) */
LIB_FUNC MATH_FUNC complex_double cvercosh(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE - csinh(radians));
}


/** Return the Versed Cosine (vercos(x) == 1 - sin(x)) */
LIB_FUNC MATH_FUNC complex_double cvercos(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE - csin(radians));
}


/** Return the Haversine (haversin(x) == 0.5*(1 - cos(x))) */
LIB_FUNC MATH_FUNC complex_double chaversin(const complex_double radians) {
	return ((complex_double)0.5 * ((complex_double)1.0 + 1.0 * I_DOUBLE - ccos(radians)));
}


/** Return the Hacoversine (hacoversin(x) == 0.5*(1 - sin(x))) */
LIB_FUNC MATH_FUNC complex_double chacoversin(const complex_double radians) {
	return ((complex_double)0.5 * ((complex_double)1.0 + 1.0 * I_DOUBLE - csin(radians)));
}


// TRIGONOMETRY (COMPLEX LONG DOUBLES)

#if SUPPORTS_COMPLEX_LDBL
/** Return the Chord */
LIB_FUNC MATH_FUNC complex_long_double ccrdl(const complex_long_double radians) {
	return ((complex_long_double)2.0L + 2.0L * I_LONG_DOUBLE * csinl(radians / (complex_long_double)2.0L + 2.0L * I_LONG_DOUBLE));
}


/** Return the Arc-Cotangent (acot(x) || arccot(x) == atan(1/x)) */
LIB_FUNC MATH_FUNC complex_long_double cacotl(const complex_long_double radians) {
	return catanl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Arc-Cotangent (acot(x) || arccot(x) == atan(1/x)) */
LIB_FUNC MATH_FUNC complex_long_double carccotl(const complex_long_double radians) {
	return catanl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x) || arccoth(x) == atanh(1/x)) */
LIB_FUNC MATH_FUNC complex_long_double cacothl(const complex_long_double radians) {
	return catanhl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cotangent (acoth(x) || arccoth(x) == atanh(1/x)) */
LIB_FUNC MATH_FUNC complex_long_double carccothl(const complex_long_double radians) {
	return catanhl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Cotangent (coth(x) == 1/tanh(x)) */
LIB_FUNC MATH_FUNC complex_long_double ccothl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / ctanhl(radians));
}


/** Return the Cotangent (cot(x) == 1/tan(x)) */
LIB_FUNC MATH_FUNC complex_long_double ccotl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / ctanl(radians));
}


/** Return the Arc-Cosecant (acsc(x) || arccsc(x) == asin(1/x)) */
LIB_FUNC MATH_FUNC complex_long_double cacscl(const complex_long_double radians) {
	return casinl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Arc-Cosecant (acsc(x) || arccsc(x) == asin(1/x)) */
LIB_FUNC MATH_FUNC complex_long_double carccscl(const complex_long_double radians) {
	return casinl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsch(x) || arccsch(x) == asinh(1/x)) */
LIB_FUNC MATH_FUNC complex_long_double cacschl(const complex_long_double radians) {
	return casinhl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Cosecant (acsc(x) || arccsch(x) == asinh(1/x)) */
LIB_FUNC MATH_FUNC complex_long_double carccschl(const complex_long_double radians) {
	return casinhl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Cosecant (csch(x) == 1/sinh(x)) */
LIB_FUNC MATH_FUNC complex_long_double ccschl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / csinhl(radians));
}


/** Return the Cosecant (csc(x) == 1/sin(x)) */
LIB_FUNC MATH_FUNC complex_long_double ccscl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / csinl(radians));
}


/** Return the Arc-Secant (asec(x) || arcsec(x) == acos(1/x)) */
LIB_FUNC MATH_FUNC complex_long_double casecl(const complex_long_double radians) {
	return cacosl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Arc-Secant (asec(x) || arcsec(x) == acos(1/x)) */
LIB_FUNC MATH_FUNC complex_long_double carcsecl(const complex_long_double radians) {
	return cacosl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x) || arcsech(x) == acosh(1/x)) */
LIB_FUNC MATH_FUNC complex_long_double casechl(const complex_long_double radians) {
	return cacoshl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Arc-Secant (asech(x) || arcsech(x) == acosh(1/x)) */
LIB_FUNC MATH_FUNC complex_long_double carcsechl(const complex_long_double radians) {
	return cacoshl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / radians);
}


/** Return the Hyperbolic Secant (sech(x) == 1/cosh(x)) */
LIB_FUNC MATH_FUNC complex_long_double csechl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / ccoshl(radians));
}


/** Return the Secant (sec(x) == 1/cos(x)) */
LIB_FUNC MATH_FUNC complex_long_double csecl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / ccosl(radians));
}


/** Return the Arc-Versed Sine (arcversin(x) == 1 - acos(x)) */
LIB_FUNC MATH_FUNC complex_long_double carcversinl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE - cacosl(radians));
}


/** Return the Hyperbolic Arc-Versed Sine (arcversinh(x) == 1 - acosh(x)) */
LIB_FUNC MATH_FUNC complex_long_double carcversinhl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE - cacoshl(radians));
}


/** Return the Hyperbolic Versed Sine (versinh(x) == 1 - cosh(x)) */
LIB_FUNC MATH_FUNC complex_long_double cversinhl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE - ccoshl(radians));
}


/** Return the Versed Sine (versin(x) == 1 - cos(x)) */
LIB_FUNC MATH_FUNC complex_long_double cversinl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE - ccosl(radians));
}


/** Return the Arc-Versed Cosine (arcvercos(x) == 1 - asin(x)) */
LIB_FUNC MATH_FUNC complex_long_double carcvercosl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE - casinl(radians));
}


/** Return the Hyperbolic Arc-Versed Cosine (arcvercosh(x) == 1 - asinh(x)) */
LIB_FUNC MATH_FUNC complex_long_double carcvercoshl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE - casinhl(radians));
}


/** Return the Hyperbolic Versed Cosine (vercosh(x) == 1 - sinh(x)) */
LIB_FUNC MATH_FUNC complex_long_double cvercoshl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE - csinhl(radians));
}


/** Return the Versed Cosine (vercos(x) == 1 - sin(x)) */
LIB_FUNC MATH_FUNC complex_long_double cvercosl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE - csinl(radians));
}


/** Return the Haversine (haversin(x) == 0.5*(1 - cos(x))) */
LIB_FUNC MATH_FUNC complex_long_double chaversinl(const complex_long_double radians) {
	return ((complex_long_double)0.5L * ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE - ccosl(radians)));
}


/** Return the Hacoversine (hacoversin(x) == 0.5*(1 - sin(x))) */
LIB_FUNC MATH_FUNC complex_long_double chacoversinl(const complex_long_double radians) {
	return ((complex_long_double)0.5L * ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE - csinl(radians)));
}
#endif


// EXTERNAL TRIGONOMETRY (COMPLEX FLOATS)

/** Return the Arc-External Cotangent (arcexcot(x) == atan(1/(x+1))) */
LIB_FUNC MATH_FUNC complex_float carcexcotf(const complex_float radians) {
	return catanf((complex_float)1.0F + 1.0F * I_FLOAT / (radians + (complex_float)1.0F + 1.0F * I_FLOAT));
}


/** Return the Hyperbolic Arc-External Cotangent [arcexcoth(x) == (1/atanh(x)-1)] */
LIB_FUNC MATH_FUNC complex_float carcexcothf(const complex_float radians) {
	return (((complex_float)1.0F + 1.0F * I_FLOAT / catanhf(radians)) - (complex_float)1.0F + 1.0F * I_FLOAT);
}


/** Return the External Hyperbolic Cotangent [excoth(x) == (1/tanh(x)-1)] */
LIB_FUNC MATH_FUNC complex_float cexcothf(const complex_float radians) {
	return (((complex_float)1.0F + 1.0F * I_FLOAT / ctanhf(radians)) - (complex_float)1.0F + 1.0F * I_FLOAT);
}


/** Return the External Cotangent [excot(x) == (1/tan(x))-1 == cot(x)-1] */
LIB_FUNC MATH_FUNC complex_float cexcotf(const complex_float radians) {
	return (((complex_float)1.0F + 1.0F * I_FLOAT / ctanf(radians)) - (complex_float)1.0F + 1.0F * I_FLOAT);
}


/** Return the Arc-External Cosecant (arcexcsc(x) == asin(1/(x+1))) */
LIB_FUNC MATH_FUNC complex_float carcexcscf(const complex_float radians) {
	return casinf((complex_float)1.0F + 1.0F * I_FLOAT / (radians + (complex_float)1.0F + 1.0F * I_FLOAT));
}


/** Return the Hyperbolic Arc-External Cosecant [arcexcsch(x) == (1/asinh(x)-1)] */
LIB_FUNC MATH_FUNC complex_float carcexcschf(const complex_float radians) {
	return (((complex_float)1.0F + 1.0F * I_FLOAT / casinhf(radians)) - (complex_float)1.0F + 1.0F * I_FLOAT);
}


/** Return the External Hyperbolic Cosecant [excsch(x) == (1/sinh(x)-1)] */
LIB_FUNC MATH_FUNC complex_float cexcschf(const complex_float radians) {
	return (((complex_float)1.0F + 1.0F * I_FLOAT / csinhf(radians)) - (complex_float)1.0F + 1.0F * I_FLOAT);
}


/** Return the External Cosecant [excsc(x) == (1/sin(x))-1 == csc(x)-1] */
LIB_FUNC MATH_FUNC complex_float cexcscf(const complex_float radians) {
	return (((complex_float)1.0F + 1.0F * I_FLOAT / csinf(radians)) - (complex_float)1.0F + 1.0F * I_FLOAT);
}


/** Return the Arc-External Secant (arcexsec(x) == acos(1/(x+1))) */
LIB_FUNC MATH_FUNC complex_float carcexsecf(const complex_float radians) {
	return cacosf((complex_float)1.0F + 1.0F * I_FLOAT / (radians + (complex_float)1.0F + 1.0F * I_FLOAT));
}


/** Return the Hyperbolic Arc-External Secant [arcexsech(x) == (1/acosh(x)-1)] */
LIB_FUNC MATH_FUNC complex_float carcexsechf(const complex_float radians) {
	return (((complex_float)1.0F + 1.0F * I_FLOAT / cacoshf(radians)) - (complex_float)1.0F + 1.0F * I_FLOAT);
}


/** Return the External Hyperbolic Secant [exsech(x) == (1/cosh(x)-1)] */
LIB_FUNC MATH_FUNC complex_float cexsechf(const complex_float radians) {
	return (((complex_float)1.0F + 1.0F * I_FLOAT / ccoshf(radians)) - (complex_float)1.0F + 1.0F * I_FLOAT);
}


/** Return the External Secant [exsec(x) == (1/cos(x))-1 == sec(x)-1] */
LIB_FUNC MATH_FUNC complex_float cexsecf(const complex_float radians) {
	return (((complex_float)1.0F + 1.0F * I_FLOAT / ccosf(radians)) - (complex_float)1.0F + 1.0F * I_FLOAT);
}


// EXTERNAL TRIGONOMETRY (COMPLEX DOUBLES)

/** Return the Arc-External Cotangent (arcexcot(x) == atan(1/(x+1))) */
LIB_FUNC MATH_FUNC complex_double carcexcot(const complex_double radians) {
	return catan((complex_double)1.0 + 1.0 * I_DOUBLE / (radians + (complex_double)1.0 + 1.0 * I_DOUBLE));
}


/** Return the Hyperbolic Arc-External Cotangent [arcexcoth(x) == (1/atanh(x)-1)] */
LIB_FUNC MATH_FUNC complex_double carcexcoth(const complex_double radians) {
	return (((complex_double)1.0 + 1.0 * I_DOUBLE / catanh(radians)) - (complex_double)1.0 + 1.0 * I_DOUBLE);
}


/** Return the External Hyperbolic Cotangent [excoth(x) == (1/tanh(x)-1)] */
LIB_FUNC MATH_FUNC complex_double cexcoth(const complex_double radians) {
	return (((complex_double)1.0 + 1.0 * I_DOUBLE / ctanh(radians)) - (complex_double)1.0 + 1.0 * I_DOUBLE);
}


/** Return the External Cotangent [excot(x) == (1/tan(x))-1 == cot(x)-1] */
LIB_FUNC MATH_FUNC complex_double cexcot(const complex_double radians) {
	return (((complex_double)1.0 + 1.0 * I_DOUBLE / ctan(radians)) - (complex_double)1.0 + 1.0 * I_DOUBLE);
}


/** Return the Arc-External Cosecant (arcexcsc(x) == asin(1/(x+1))) */
LIB_FUNC MATH_FUNC complex_double carcexcsc(const complex_double radians) {
	return casin((complex_double)1.0 + 1.0 * I_DOUBLE / (radians + (complex_double)1.0 + 1.0 * I_DOUBLE));
}


/** Return the Hyperbolic Arc-External Cosecant [arcexcsch(x) == (1/asinh(x)-1)] */
LIB_FUNC MATH_FUNC complex_double carcexcsch(const complex_double radians) {
	return (((complex_double)1.0 + 1.0 * I_DOUBLE / casinh(radians)) - (complex_double)1.0 + 1.0 * I_DOUBLE);
}


/** Return the External Hyperbolic Cosecant [excsch(x) == (1/sinh(x)-1)] */
LIB_FUNC MATH_FUNC complex_double cexcsch(const complex_double radians) {
	return (((complex_double)1.0 + 1.0 * I_DOUBLE / csinh(radians)) - (complex_double)1.0 + 1.0 * I_DOUBLE);
}


/** Return the External Cosecant [excsc(x) == (1/sin(x))-1 == csc(x)-1] */
LIB_FUNC MATH_FUNC complex_double cexcsc(const complex_double radians) {
	return (((complex_double)1.0 + 1.0 * I_DOUBLE / csin(radians)) - (complex_double)1.0 + 1.0 * I_DOUBLE);
}


/** Return the Arc-External Secant (arcexsec(x) == acos(1/(x+1))) */
LIB_FUNC MATH_FUNC complex_double carcexsec(const complex_double radians) {
	return cacos((complex_double)1.0 + 1.0 * I_DOUBLE / (radians + (complex_double)1.0 + 1.0 * I_DOUBLE));
}


/** Return the Hyperbolic Arc-External Secant [arcexsech(x) == (1/acosh(x)-1)] */
LIB_FUNC MATH_FUNC complex_double carcexsech(const complex_double radians) {
	return (((complex_double)1.0 + 1.0 * I_DOUBLE / cacosh(radians)) - (complex_double)1.0 + 1.0 * I_DOUBLE);
}


/** Return the External Hyperbolic Secant [exsech(x) == (1/cosh(x)-1)] */
LIB_FUNC MATH_FUNC complex_double cexsech(const complex_double radians) {
	return (((complex_double)1.0 + 1.0 * I_DOUBLE / ccosh(radians)) - (complex_double)1.0 + 1.0 * I_DOUBLE);
}


/** Return the External Secant [exsec(x) == (1/cos(x))-1 == sec(x)-1] */
LIB_FUNC MATH_FUNC complex_double cexsec(const complex_double radians) {
	return (((complex_double)1.0 + 1.0 * I_DOUBLE / ccos(radians)) - (complex_double)1.0 + 1.0 * I_DOUBLE);
}


// EXTERNAL TRIGONOMETRY (COMPLEX LONG DOUBLES)

#if SUPPORTS_COMPLEX_LDBL
/** Return the Arc-External Cotangent (arcexcot(x) == atan(1/(x+1))) */
LIB_FUNC MATH_FUNC complex_long_double carcexcotl(const complex_long_double radians) {
	return catanl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / (radians + (complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE));
}


/** Return the Hyperbolic Arc-External Cotangent [arcexcoth(x) == (1/atanh(x)-1)] */
LIB_FUNC MATH_FUNC complex_long_double carcexcothl(const complex_long_double radians) {
	return (((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / catanhl(radians)) - (complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the External Hyperbolic Cotangent [excoth(x) == (1/tanh(x)-1)] */
LIB_FUNC MATH_FUNC complex_long_double cexcothl(const complex_long_double radians) {
	return (((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / ctanhl(radians)) - (complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the External Cotangent [excot(x) == (1/tan(x))-1 == cot(x)-1] */
LIB_FUNC MATH_FUNC complex_long_double cexcotl(const complex_long_double radians) {
	return (((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / ctanl(radians)) - (complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the Arc-External Cosecant (arcexcsc(x) == asin(1/(x+1))) */
LIB_FUNC MATH_FUNC complex_long_double carcexcscl(const complex_long_double radians) {
	return casinl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / (radians + (complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE));
}


/** Return the Hyperbolic Arc-External Cosecant [arcexcsch(x) == (1/asinh(x)-1)] */
LIB_FUNC MATH_FUNC complex_long_double carcexcschl(const complex_long_double radians) {
	return (((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / casinhl(radians)) - (complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the External Hyperbolic Cosecant [excsch(x) == (1/sinh(x)-1)] */
LIB_FUNC MATH_FUNC complex_long_double cexcschl(const complex_long_double radians) {
	return (((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / csinhl(radians)) - (complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the External Cosecant [excsc(x) == (1/sin(x))-1 == csc(x)-1] */
LIB_FUNC MATH_FUNC complex_long_double cexcscl(const complex_long_double radians) {
	return (((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / csinl(radians)) - (complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the Arc-External Secant (arcexsec(x) == acos(1/(x+1))) */
LIB_FUNC MATH_FUNC complex_long_double carcexsecl(const complex_long_double radians) {
	return cacosl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / (radians + (complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE));
}


/** Return the Hyperbolic Arc-External Secant [arcexsech(x) == (1/acosh(x)-1)] */
LIB_FUNC MATH_FUNC complex_long_double carcexsechl(const complex_long_double radians) {
	return (((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / cacoshl(radians)) - (complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the External Hyperbolic Secant [exsech(x) == (1/cosh(x)-1)] */
LIB_FUNC MATH_FUNC complex_long_double cexsechl(const complex_long_double radians) {
	return (((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / ccoshl(radians)) - (complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE);
}


/** Return the External Secant [exsec(x) == (1/cos(x))-1 == sec(x)-1] */
LIB_FUNC MATH_FUNC complex_long_double cexsecl(const complex_long_double radians) {
	return (((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / ccosl(radians)) - (complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE);
}
#endif


// SPECIAL TRIGONOMETRIC FUNCTIONS (COMPLEX FLOATS)

/** Return the Cosine of an Arc-Sine [sqrt(1-(x*x))] */
LIB_FUNC MATH_FUNC complex_float ccos_arcsinf(const complex_float radians) {
	return (csqrtf((complex_float)1.0F + 1.0F * I_FLOAT - (radians * radians)));
}


/** Return the Cosine of an Arc-Tangent [1 / sqrt(1+(x*x))] */
LIB_FUNC MATH_FUNC complex_float ccos_arctanf(const complex_float radians) {
	return ((complex_float)1.0F + 1.0F * I_FLOAT / csqrtf((complex_float)1.0F + 1.0F * I_FLOAT + (radians * radians)));
}


/** Return the Sine of an Arc-Tangent [sqrt((x*x)-1)/x] */
LIB_FUNC MATH_FUNC complex_float csin_arcsecf(const complex_float radians) {
	return (csqrtf((radians * radians) - (complex_float)1.0F + 1.0F * I_FLOAT) / radians);
}


/** Return the Sine of an Arc-Tangent [x / sqrt(1+(x*x))] */
LIB_FUNC MATH_FUNC complex_float csin_arctanf(const complex_float radians) {
	return (radians / csqrtf((complex_float)1.0F + 1.0F * I_FLOAT + (radians * radians)));
}


// SPECIAL TRIGONOMETRIC FUNCTIONS (COMPLEX DOUBLES)

/** Return the Cosine of an Arc-Sine [sqrt(1-(x*x))] */
LIB_FUNC MATH_FUNC complex_double ccos_arcsin(const complex_double radians) {
	return (csqrt((complex_double)1.0 + 1.0 * I_DOUBLE - (radians * radians)));
}


/** Return the Cosine of an Arc-Tangent [1 / sqrt(1+(x*x))] */
LIB_FUNC MATH_FUNC complex_double ccos_arctan(const complex_double radians) {
	return ((complex_double)1.0 + 1.0 * I_DOUBLE / csqrt((complex_double)1.0 + 1.0 * I_DOUBLE + (radians * radians)));
}


/** Return the Sine of an Arc-Tangent [sqrt((x*x)-1)/x] */
LIB_FUNC MATH_FUNC complex_double csin_arcsec(const complex_double radians) {
	return (csqrt((radians * radians) - (complex_double)1.0 + 1.0 * I_DOUBLE) / radians);
}


/** Return the Sine of an Arc-Tangent [x / sqrt(1+(x*x))] */
LIB_FUNC MATH_FUNC complex_double csin_arctan(const complex_double radians) {
	return (radians / csqrt((complex_double)1.0 + 1.0 * I_DOUBLE + (radians * radians)));
}


// SPECIAL TRIGONOMETRIC FUNCTIONS (COMPLEX LONG DOUBLES)

#if SUPPORTS_COMPLEX_LDBL
/** Return the Cosine of an Arc-Sine [sqrt(1-(x*x))] */
LIB_FUNC MATH_FUNC complex_long_double ccos_arcsinl(const complex_long_double radians) {
	return (csqrtl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE - (radians * radians)));
}


/** Return the Cosine of an Arc-Tangent [1 / sqrt(1+(x*x))] */
LIB_FUNC MATH_FUNC complex_long_double ccos_arctanl(const complex_long_double radians) {
	return ((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE / csqrtl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE + (radians * radians)));
}


/** Return the Sine of an Arc-Tangent [sqrt((x*x)-1)/x] */
LIB_FUNC MATH_FUNC complex_long_double csin_arcsecl(const complex_long_double radians) {
	return (csqrtl((radians * radians) - (complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE) / radians);
}


/** Return the Sine of an Arc-Tangent [x / sqrt(1+(x*x))] */
LIB_FUNC MATH_FUNC complex_long_double csin_arctanl(const complex_long_double radians) {
	return (radians / csqrtl((complex_long_double)1.0L + 1.0L * I_LONG_DOUBLE + (radians * radians)));
}
#endif


#endif  // COMPLEX_H


/* QUATERNION MATH */


#if (!(defined(QUATERNION_H) || defined(_QUATERNION_H) || defined(_QUATERNION_H_)))
#define QUATERNION_H   (1)
#define _QUATERNION_H   (1)
#define _QUATERNION_H_   (1)


/** Imaginary number with three imaginary parts (float) */
typedef struct quaternion_float { float R, i, j, k; }   quaternion_float;
/** Imaginary number with three imaginary parts (double) */
typedef struct quaternion { double R, i, j, k; }   quaternion;
#if SUPPORTS_LONG_DOUBLE
/** Imaginary number with three imaginary parts (long double) */
typedef struct quaternion_long_double { long double R, i, j, k; }   quaternion_long_double;
#endif
#if SUPPORTS_FLOAT128
/** Imaginary number with three imaginary parts (float128) */
typedef struct quaternion_float128 { float128 R, i, j, k; }   quaternion_float128;
#endif
#ifndef QUATERNIONF
#   define QUATERNIONF(r, x, y, z)   ((quaternion_float){(float)(r), (float)(x), (float)(y), (float)(z)})
#endif
#ifndef __quaternionf__
#   define __quaternionf__(r, x, y, z)   QUATERNIONF(r, x, y, z)
#endif
#ifndef QUATERNION
#   define QUATERNION(r, x, y, z)   ((quaternion){(double)(r), (double)(x), (double)(y), (double)(z)})
#endif
#ifndef __quaternion__
#   define __quaternion__(r, x, y, z)   QUATERNION(r, x, y, z)
#endif
#if ((!defined(QUATERNIONL)) && SUPPORTS_LONG_DOUBLE)
#   define QUATERNIONL(r, x, y, z)   ((quaternion_long_double){(long double)(r), (long double)(x), (long double)(y), (long double)(z)})
#endif
#if ((!defined(__quaternionl__)) && SUPPORTS_LONG_DOUBLE)
#   define __quaternionl__(r, x, y, z)   QUATERNIONL(r, x, y, z)
#endif
#if ((!defined(QUATERNIONF128)) && SUPPORTS_FLOAT128)
#   define QUATERNIONF128(r, x, y, z)   ((quaternion_float128){(float128)(r), (float128)(x), (float128)(y), (float128)(z)})
#endif
#if ((!defined(__quaternionf128__)) && SUPPORTS_FLOAT128)
#   define __quaternionf128__(r, x, y, z)   QUATERNIONF128(r, x, y, z)
#endif


#define qimagf(x)   ((x).i, (x).j, (x).k)
#define qimag(x)   ((x).i, (x).j, (x).k)
#define qimagl(x)   ((x).i, (x).j, (x).k)


// FLOAT QUATERNION FUNCTIONS

/** Return the real number from the quaternion number */
LIB_FUNC MATH_FUNC float qrealf(const quaternion_float num) {
	return num.R;
}


/** Return the imaginary i num of the quaternion number */
LIB_FUNC MATH_FUNC float qgetif(const quaternion_float num) {
	return num.i;
}


/** Return the imaginary j num of the quaternion number */
LIB_FUNC MATH_FUNC float qgetjf(const quaternion_float num) {
	return num.j;
}


/** Return the imaginary k num of the quaternion number */
LIB_FUNC MATH_FUNC float qgetkf(const quaternion_float num) {
	return num.k;
}


/** Return the conjugate of the quaternion number */
LIB_FUNC MATH_FUNC quaternion_float qconjugatef(const quaternion_float num) {
	return (quaternion_float){num.R, num.i * -1.0F, num.j * -1.0F, num.k * -1.0F};
}


/** Return the norm value of the quaternion number */
LIB_FUNC MATH_FUNC float qnormf(const quaternion_float num) {
	return squarerootf((num.R * num.R) + (num.i * num.i) + (num.j * num.j) + (num.k * num.k));
}


/** Add two quaternion numbers */
LIB_FUNC MATH_FUNC quaternion_float qaddf(const quaternion_float num1, const quaternion_float num2) {
	return (quaternion_float){num1.R + num2.R, num1.i + num2.i, num1.j + num2.j, num1.k + num2.k};
}


/** Subtract two quaternion numbers */
LIB_FUNC MATH_FUNC quaternion_float qsubf(const quaternion_float num1, const quaternion_float num2) {
	return (quaternion_float){num1.R - num2.R, num1.i - num2.i, num1.j - num2.j, num1.k - num2.k};
}


/** Multiply two quaternion numbers */
LIB_FUNC MATH_FUNC quaternion_float qmulf(const quaternion_float num1, const quaternion_float num2) {
	const float tmp_r = (num2.R * num1.R) - (num2.i * num1.i) - (num2.j * num1.j) - (num2.k * num1.k);
	const float tmp_i = (num2.R * num1.i) + (num2.i * num1.R) - (num2.j * num1.k) + (num2.k * num1.j);
	const float tmp_j = (num2.R * num1.j) + (num2.i * num1.k) + (num2.j * num1.R) - (num2.k * num1.i);
	const float tmp_k = (num2.R * num1.k) - (num2.i * num1.j) + (num2.j * num1.i) + (num2.k * num1.R);
	return (quaternion_float){tmp_r, tmp_i, tmp_j, tmp_k};
}


/** Divide two quaternion numbers */
LIB_FUNC MATH_FUNC quaternion_float qdivf(const quaternion_float num1, const quaternion_float num2) {
	if ((num1.R == num2.R) && (num1.i == num2.i) && (num1.j == num2.j) && (num1.k == num2.k)) return (quaternion_float){1.0F, 0.0F, 0.0F, 0.0F};
	const float tmp_r = (num2.R * num1.R) + (num2.i * num1.i) + (num2.j * num1.j) + (num2.k * num1.k);
	const float tmp_i = (num2.R * num1.i) - (num2.i * num1.R) - (num2.j * num1.k) + (num2.k * num1.j);
	const float tmp_j = (num2.R * num1.j) + (num2.i * num1.k) - (num2.j * num1.R) - (num2.k * num1.i);
	const float tmp_k = (num2.R * num1.k) - (num2.i * num1.j) + (num2.j * num1.i) - (num2.k * num1.R);
	register const float tmp2n = squarerootf((num2.R * num2.R) + (num2.i * num2.i) + (num2.j * num2.j) + (num2.k * num2.k));  // Norm
	return (quaternion_float){tmp_r / tmp2n, tmp_i / tmp2n, tmp_j / tmp2n, tmp_k / tmp2n};
}


/** Inverse quaternion */
LIB_FUNC MATH_FUNC quaternion_float qinvf(const quaternion_float qnum) {
	register const float tmp = ((qnum.R * qnum.R) + (qnum.i * qnum.i) + (qnum.j * qnum.j) + (qnum.k * qnum.k));
	return (quaternion_float){ (qnum.R / tmp), ((-qnum.i) / tmp), ((-qnum.j) / tmp), ((-qnum.k) / tmp) };
}


/** Inverse quaternion (in-place) */
LIB_FUNC void qinv_inplacef(quaternion_float qnum) {
	register const float tmp = ((qnum.R * qnum.R) + (qnum.i * qnum.i) + (qnum.j * qnum.j) + (qnum.k * qnum.k));
	qnum.R /= tmp;
	qnum.i = (-qnum.i) / tmp;
	qnum.j = (-qnum.j) / tmp;
	qnum.k = (-qnum.k) / tmp;
}


/** Return the negative quaternion */
LIB_FUNC MATH_FUNC quaternion_float qnegf(const quaternion_float qnum) {
	return (quaternion_float){ (-qnum.R), (-qnum.i), (-qnum.j), (-qnum.k) };
}


/** Negate quaternion (in-place) */
LIB_FUNC void qneg_inplacef(quaternion_float qnum) {
	qnum.R = -qnum.R;
	qnum.i = -qnum.i;
	qnum.j = -qnum.j;
	qnum.k = -qnum.k;
}


/** Return the length of a quaternion */
LIB_FUNC MATH_FUNC float qlenf(const quaternion_float num) {
	return squarerootf((num.R * num.R) + (num.i * num.i) + (num.j * num.j) + (num.k * num.k));
}


/** Return the mid-point of two quaternions */
LIB_FUNC MATH_FUNC quaternion_float qmidf(const quaternion_float num1, const quaternion_float num2) {
	quaternion_float q = qaddf(num1, num2);
	register const float tmp = qlenf(num1);
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
LIB_FUNC MATH_FUNC quaternion_float qsqrtf(const quaternion_float num) {
	return qmidf(num, (quaternion_float){ 1.0F, 0.0F, 0.0F, 0.0F });
}


/** Return the scalar portion of the quaternion number */
LIB_FUNC MATH_FUNC quaternion_float qscalarf(const quaternion_float num) {
	const quaternion_float conj_num = (quaternion_float){num.R, num.i * -1.0F, num.j * -1.0F, num.k * -1.0F};
	return (quaternion_float){(num.R + conj_num.R) * 0.5F, (num.i + conj_num.i) * 0.5F, (num.j + conj_num.j) * 0.5F, (num.k + conj_num.k) * 0.5F};
}


/** Return the vector portion of the quaternion number */
LIB_FUNC MATH_FUNC quaternion_float qvectorf(const quaternion_float num) {
	const quaternion_float conj_num = (quaternion_float){num.R, num.i * -1.0F, num.j * -1.0F, num.k * -1.0F};
	return (quaternion_float){(num.R - conj_num.R) * 0.5F, (num.i - conj_num.i) * 0.5F, (num.j - conj_num.j) * 0.5F, (num.k - conj_num.k) * 0.5F};
}


/** Return the versor the quaternion number */
LIB_FUNC MATH_FUNC quaternion_float qversorf(const quaternion_float num) {
	const quaternion_float conj_num = (quaternion_float){num.R, num.i * -1.0F, num.j * -1.0F, num.k * -1.0F};
	return qdivf(num, conj_num);
}


// DOUBLE QUATERNION FUNCTIONS

/** Return the real number from the quaternion number */
LIB_FUNC MATH_FUNC double qreal(const quaternion num) {
	return num.R;
}


/** Return the imaginary i num of the quaternion number */
LIB_FUNC MATH_FUNC double qgeti(const quaternion num) {
	return num.i;
}


/** Return the imaginary j num of the quaternion number */
LIB_FUNC MATH_FUNC double qgetj(const quaternion num) {
	return num.j;
}


/** Return the imaginary k num of the quaternion number */
LIB_FUNC MATH_FUNC double qgetk(const quaternion num) {
	return num.k;
}


/** Return the conjugate of the quaternion number */
LIB_FUNC MATH_FUNC quaternion qconjugate(const quaternion num) {
	return (quaternion){num.R, num.i * -1.0, num.j * -1.0, num.k * -1.0};
}


/** Return the norm value of the quaternion number */
LIB_FUNC MATH_FUNC double qnorm(const quaternion num) {
	return squareroot((num.R * num.R) + (num.i * num.i) + (num.j * num.j) + (num.k * num.k));
}


/** Add two quaternion numbers */
LIB_FUNC MATH_FUNC quaternion qadd(const quaternion num1, const quaternion num2) {
	return (quaternion){num1.R + num2.R, num1.i + num2.i, num1.j + num2.j, num1.k + num2.k};
}


/** Subtract two quaternion numbers */
LIB_FUNC MATH_FUNC quaternion qsub(const quaternion num1, const quaternion num2) {
	return (quaternion){num1.R - num2.R, num1.i - num2.i, num1.j - num2.j, num1.k - num2.k};
}


/** Multiply two quaternion numbers */
LIB_FUNC MATH_FUNC quaternion qmul(const quaternion num1, const quaternion num2) {
	const double tmp_r = (num2.R * num1.R) - (num2.i * num1.i) - (num2.j * num1.j) - (num2.k * num1.k);
	const double tmp_i = (num2.R * num1.i) + (num2.i * num1.R) - (num2.j * num1.k) + (num2.k * num1.j);
	const double tmp_j = (num2.R * num1.j) + (num2.i * num1.k) + (num2.j * num1.R) - (num2.k * num1.i);
	const double tmp_k = (num2.R * num1.k) - (num2.i * num1.j) + (num2.j * num1.i) + (num2.k * num1.R);
	return (quaternion){tmp_r, tmp_i, tmp_j, tmp_k};
}


/** Divide two quaternion numbers */
LIB_FUNC MATH_FUNC quaternion qdiv(const quaternion num1, const quaternion num2) {
	if ((num1.R == num2.R) && (num1.i == num2.i) && (num1.j == num2.j) && (num1.k == num2.k)) return (quaternion){1.0, 0.0, 0.0, 0.0};
	const double tmp_r = (num2.R * num1.R) + (num2.i * num1.i) + (num2.j * num1.j) + (num2.k * num1.k);
	const double tmp_i = (num2.R * num1.i) - (num2.i * num1.R) - (num2.j * num1.k) + (num2.k * num1.j);
	const double tmp_j = (num2.R * num1.j) + (num2.i * num1.k) - (num2.j * num1.R) - (num2.k * num1.i);
	const double tmp_k = (num2.R * num1.k) - (num2.i * num1.j) + (num2.j * num1.i) - (num2.k * num1.R);
	register const double tmp2n = squareroot((num2.R * num2.R) + (num2.i * num2.i) + (num2.j * num2.j) + (num2.k * num2.k));  // Norm
	return (quaternion){tmp_r / tmp2n, tmp_i / tmp2n, tmp_j / tmp2n, tmp_k / tmp2n};
}


/** Inverse quaternion */
LIB_FUNC MATH_FUNC quaternion qinv(const quaternion qnum) {
	register const double tmp = ((qnum.R * qnum.R) + (qnum.i * qnum.i) + (qnum.j * qnum.j) + (qnum.k * qnum.k));
	return (quaternion){ (qnum.R / tmp), ((-qnum.i) / tmp), ((-qnum.j) / tmp), ((-qnum.k) / tmp) };
}


/** Inverse quaternion (in-place) */
LIB_FUNC void qinv_inplace(quaternion qnum) {
	register const double tmp = ((qnum.R * qnum.R) + (qnum.i * qnum.i) + (qnum.j * qnum.j) + (qnum.k * qnum.k));
	qnum.R /= tmp;
	qnum.i = (-qnum.i) / tmp;
	qnum.j = (-qnum.j) / tmp;
	qnum.k = (-qnum.k) / tmp;
}


/** Return the negative quaternion */
LIB_FUNC MATH_FUNC quaternion qneg(const quaternion qnum) {
	return (quaternion){ (-qnum.R), (-qnum.i), (-qnum.j), (-qnum.k) };
}


/** Negate quaternion (in-place) */
LIB_FUNC void qneg_inplace(quaternion qnum) {
	qnum.R = -qnum.R;
	qnum.i = -qnum.i;
	qnum.j = -qnum.j;
	qnum.k = -qnum.k;
}


/** Return the length of a quaternion */
LIB_FUNC MATH_FUNC double qlen(const quaternion num) {
	return squareroot((num.R * num.R) + (num.i * num.i) + (num.j * num.j) + (num.k * num.k));
}


/** Return the mid-point of two quaternions */
LIB_FUNC MATH_FUNC quaternion qmid(const quaternion num1, const quaternion num2) {
	quaternion q = qadd(num1, num2);
	register const double tmp = qlen(num1);
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
LIB_FUNC MATH_FUNC quaternion qsqrt(const quaternion num) {
	return qmid(num, (quaternion){ 1.0, 0.0, 0.0, 0.0 });
}


/** Return the scalar portion of the quaternion number */
LIB_FUNC MATH_FUNC quaternion qscalar(const quaternion num) {
	const quaternion conj_num = (quaternion){num.R, num.i * -1.0, num.j * -1.0, num.k * -1.0};
	return (quaternion){(num.R + conj_num.R) * 0.5, (num.i + conj_num.i) * 0.5, (num.j + conj_num.j) * 0.5, (num.k + conj_num.k) * 0.5};
}


/** Return the vector portion of the quaternion number */
LIB_FUNC MATH_FUNC quaternion qvector(const quaternion num) {
	const quaternion conj_num = (quaternion){num.R, num.i * -1.0, num.j * -1.0, num.k * -1.0};
	return (quaternion){(num.R - conj_num.R) * 0.5, (num.i - conj_num.i) * 0.5, (num.j - conj_num.j) * 0.5, (num.k - conj_num.k) * 0.5};
}


/** Return the versor the quaternion number */
LIB_FUNC MATH_FUNC quaternion qversor(const quaternion num) {
	const quaternion conj_num = (quaternion){num.R, num.i * -1.0, num.j * -1.0, num.k * -1.0};
	return qdiv(num, conj_num);
}


// LONG DOUBLE QUATERNION FUNCTIONS

#if SUPPORTS_LONG_DOUBLE


/** Return the real number from the quaternion number */
LIB_FUNC MATH_FUNC long double qreall(const quaternion_long_double num) {
	return num.R;
}


/** Return the imaginary i num of the quaternion number */
LIB_FUNC MATH_FUNC long double qgetil(const quaternion_long_double num) {
	return num.i;
}


/** Return the imaginary j num of the quaternion number */
LIB_FUNC MATH_FUNC long double qgetjl(const quaternion_long_double num) {
	return num.j;
}


/** Return the imaginary k num of the quaternion number */
LIB_FUNC MATH_FUNC long double qgetkl(const quaternion_long_double num) {
	return num.k;
}


/** Return the conjugate of the quaternion number */
LIB_FUNC MATH_FUNC quaternion_long_double qconjugatel(const quaternion_long_double num) {
	return (quaternion_long_double){num.R, num.i * -1.0L, num.j * -1.0L, num.k * -1.0L};
}


/** Return the norm value of the quaternion number */
LIB_FUNC MATH_FUNC long double qnorml(const quaternion_long_double num) {
	return squarerootl((num.R * num.R) + (num.i * num.i) + (num.j * num.j) + (num.k * num.k));
}


/** Add two quaternion numbers */
LIB_FUNC MATH_FUNC quaternion_long_double qaddl(const quaternion_long_double num1, const quaternion_long_double num2) {
	return (quaternion_long_double){num1.R + num2.R, num1.i + num2.i, num1.j + num2.j, num1.k + num2.k};
}


/** Subtract two quaternion numbers */
LIB_FUNC MATH_FUNC quaternion_long_double qsubl(const quaternion_long_double num1, const quaternion_long_double num2) {
	return (quaternion_long_double){num1.R - num2.R, num1.i - num2.i, num1.j - num2.j, num1.k - num2.k};
}


/** Multiply two quaternion numbers */
LIB_FUNC MATH_FUNC quaternion_long_double qmull(const quaternion_long_double num1, const quaternion_long_double num2) {
	const long double tmp_r = (num2.R * num1.R) - (num2.i * num1.i) - (num2.j * num1.j) - (num2.k * num1.k);
	const long double tmp_i = (num2.R * num1.i) + (num2.i * num1.R) - (num2.j * num1.k) + (num2.k * num1.j);
	const long double tmp_j = (num2.R * num1.j) + (num2.i * num1.k) + (num2.j * num1.R) - (num2.k * num1.i);
	const long double tmp_k = (num2.R * num1.k) - (num2.i * num1.j) + (num2.j * num1.i) + (num2.k * num1.R);
	return (quaternion_long_double){tmp_r, tmp_i, tmp_j, tmp_k};
}


/** Divide two quaternion numbers */
LIB_FUNC MATH_FUNC quaternion_long_double qdivl(const quaternion_long_double num1, const quaternion_long_double num2) {
	if ((num1.R == num2.R) && (num1.i == num2.i) && (num1.j == num2.j) && (num1.k == num2.k)) {
		return (quaternion_long_double){1.0L, 0.0L, 0.0L, 0.0L};
	}
	const long double tmp_r = (num2.R * num1.R) + (num2.i * num1.i) + (num2.j * num1.j) + (num2.k * num1.k);
	const long double tmp_i = (num2.R * num1.i) - (num2.i * num1.R) - (num2.j * num1.k) + (num2.k * num1.j);
	const long double tmp_j = (num2.R * num1.j) + (num2.i * num1.k) - (num2.j * num1.R) - (num2.k * num1.i);
	const long double tmp_k = (num2.R * num1.k) - (num2.i * num1.j) + (num2.j * num1.i) - (num2.k * num1.R);
	register long double tmp2n = squarerootl((num2.R * num2.R) + (num2.i * num2.i) + (num2.j * num2.j) + (num2.k * num2.k));  // Norm
	return (quaternion_long_double){tmp_r / tmp2n, tmp_i / tmp2n, tmp_j / tmp2n, tmp_k / tmp2n};
}


/** Inverse quaternion */
LIB_FUNC MATH_FUNC quaternion_long_double qinvl(const quaternion_long_double qnum) {
	register const long double tmp = ((qnum.R * qnum.R) + (qnum.i * qnum.i) + (qnum.j * qnum.j) + (qnum.k * qnum.k));
	return (quaternion_long_double){ (qnum.R / tmp), ((-qnum.i) / tmp), ((-qnum.j) / tmp), ((-qnum.k) / tmp) };
}


/** Inverse quaternion (in-place) */
LIB_FUNC void qinv_inplacel(quaternion_long_double qnum) {
	register const long double tmp = ((qnum.R * qnum.R) + (qnum.i * qnum.i) + (qnum.j * qnum.j) + (qnum.k * qnum.k));
	qnum.R /= tmp;
	qnum.i = (-qnum.i) / tmp;
	qnum.j = (-qnum.j) / tmp;
	qnum.k = (-qnum.k) / tmp;
}


/** Return the negative quaternion */
LIB_FUNC MATH_FUNC quaternion_long_double qnegl(const quaternion_long_double qnum) {
	return (quaternion_long_double){ (-qnum.R), (-qnum.i), (-qnum.j), (-qnum.k) };
}


/** Negate quaternion (in-place) */
LIB_FUNC void qneg_inplacel(quaternion_long_double qnum) {
	qnum.R = -qnum.R;
	qnum.i = -qnum.i;
	qnum.j = -qnum.j;
	qnum.k = -qnum.k;
}


/** Return the length of a quaternion */
LIB_FUNC MATH_FUNC long double qlenl(const quaternion_long_double num) {
	return squarerootl((num.R * num.R) + (num.i * num.i) + (num.j * num.j) + (num.k * num.k));
}


/** Return the mid-point of two quaternions */
LIB_FUNC MATH_FUNC quaternion_long_double qmidl(const quaternion_long_double num1, const quaternion_long_double num2) {
	quaternion_long_double q = qaddl(num1, num2);
	register const long double tmp = qlenl(num1);
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
LIB_FUNC MATH_FUNC quaternion_long_double qsqrtl(const quaternion_long_double num) {
	return qmidl(num, (quaternion_long_double){ 1.0L, 0.0L, 0.0L, 0.0L });
}


/** Return the scalar portion of the quaternion number */
LIB_FUNC MATH_FUNC quaternion_long_double qscalarl(const quaternion_long_double num) {
	const quaternion_long_double conj_num = (quaternion_long_double){num.R, num.i * -1.0L, num.j * -1.0L, num.k * -1.0L};
	return (quaternion_long_double){(num.R + conj_num.R) * 0.5L, (num.i + conj_num.i) * 0.5L, (num.j + conj_num.j) * 0.5L, (num.k + conj_num.k) * 0.5L};
}


/** Return the vector portion of the quaternion number */
LIB_FUNC MATH_FUNC quaternion_long_double qvectorl(const quaternion_long_double num) {
	const quaternion_long_double conj_num = (quaternion_long_double){num.R, num.i * -1.0L, num.j * -1.0L, num.k * -1.0L};
	return (quaternion_long_double){(num.R - conj_num.R) * 0.5L, (num.i - conj_num.i) * 0.5L, (num.j - conj_num.j) * 0.5L, (num.k - conj_num.k) * 0.5L};
}


/** Return the versor the quaternion number */
LIB_FUNC MATH_FUNC quaternion_long_double qversorl(const quaternion_long_double num) {
	const quaternion_long_double conj_num = (quaternion_long_double){num.R, num.i * -1.0L, num.j * -1.0L, num.k * -1.0L};
	return qdivl(num, conj_num);
}


#endif


#endif  // QUATERNION_H


/* TYPE GENERIC MATH (<tgmath.h>) */


#if ((!(defined(TGMATH_H) || defined(_TGMATH_H) || defined(_TGMATH_H_) || defined(__TGMATH_H))) && IS_NOT_CPLUSPLUS)  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/tgmath.h.html & http://www.cplusplus.com/reference/ctgmath/
#define TGMATH_H   (1)
#define _TGMATH_H   (1)
#define _TGMATH_H_   (1)
#define __TGMATH_H   (1)


#if SUPPORTS_LONG_DOUBLE
#   define tg_select_ldbl   long double: func ## l(expr)
#   define tg_select2_ldbl   long double: func ## l(expr1, expr2)
#   define tg_select3_ldbl   long double: func ## l(expr1, expr2, expr3)
#endif
#if SUPPORTS_COMPLEX
#   define tg_select_cmpx   complex_float: c ## func ## f(expr), complex_double: c ## func(expr)
#endif
#if SUPPORTS_COMPLEX_LDBL
#   define tg_select_cmpx_ldbl   complex_long_double: c ## func ## l(expr)
#endif
#define tg_select(expr, func)   Generic ((expr), \
	float: func ## f(expr), \
	double: func(expr), \
	tg_select_ldbl, \
	tg_select_cmpx, \
	tg_select_cmpx_ldbl, \
	default: 0 \
)


#define tgf_select(expr, func)   Generic ((expr), \
	float: func ## f(expr), \
	double: func(expr), \
	tg_select_ldbl, \
	default: 0 \
)


#define tgf_select2(expr1, expr2, func)   Generic ((expr1), \
	float: func ## f(expr1, expr2), \
	double: func(expr1, expr2), \
	tg_select2_ldbl, \
	default: 0 \
)


#define tgf_select3(expr1, expr2, expr3, func)   Generic ((expr1), \
	float: func ## f(expr1, expr2, expr3), \
	double: func(expr1, expr2, expr3), \
	tg_select3_ldbl, \
	default: 0 \
)


// ACOS
#define tg_acos(x)   tg_select(x, acos)
#define __tg_acos(x)   tg_select(x, acos)

// ASIN
#define tg_asin(x)   tg_select(x, asin)
#define __tg_asin(x)   tg_select(x, asin)

// ATAN
#define tg_atan(x)   tg_select(x, atan)
#define __tg_atan(x)   tg_select(x, atan)

// ACOSH
#define tg_acosh(x)   tg_select(x, acosh)
#define __tg_acosh(x)   tg_select(x, acosh)

// ASINH
#define tg_asinh(x)   tg_select(x, asinh)
#define __tg_asinh(x)   tg_select(x, asinh)

// ATANH
#define tg_atanh(x)   tg_select(x, atanh)
#define __tg_atanh(x)   tg_select(x, atanh)

// COS
#define tg_cos(x)   tg_select(x, cos)
#define __tg_cos(x)   tg_select(x, cos)

// SIN
#define tg_sin(x)   tg_select(x, sin)
#define __tg_sin(x)   tg_select(x, sin)

// TAN
#define tg_tan(x)   tg_select(x, tan)
#define __tg_tan(x)   tg_select(x, tan)

// COSH
#define tg_cosh(x)   tg_select(x, cosh)
#define __tg_cosh(x)   tg_select(x, cosh)

// SINH
#define tg_sinh(x)   tg_select(x, sinh)
#define __tg_sinh(x)   tg_select(x, sinh)

// TANH
#define tg_tanh(x)   tg_select(x, tanh)
#define __tg_tanh(x)   tg_select(x, tanh)

// ATAN2
#define tg_atan2(x)   tgf_select(x, atan2)
#define __tg_atan2(x)   tgf_select(x, atan2)

// EXP
#define tg_exp(x)   tg_select(x, exp)
#define __tg_exp(x)   tg_select(x, exp)

// EXP2
#define tg_exp2(x)   tgf_select(x, exp2)
#define __tg_exp2(x)   tgf_select(x, exp2)

// EXPM1
#define tg_expm1(x)   tgf_select(x, expm1)
#define __tg_expm1(x)   tgf_select(x, expm1)

// LDEXP
#define tg_ldexp(x)   tgf_select(x, ldexp)
#define __tg_ldexp(x)   tgf_select(x, ldexp)

// LOG
#define tg_log(x)   tg_select(x, log)
#define __tg_log(x)   tg_select(x, log)

// ILOGB
#define tg_ilogb(x)   tgf_select(x, ilogb)
#define __tg_ilogb(x)   tgf_select(x, ilogb)

// LOG10
#define tg_log10(x)   tgf_select(x, log10)
#define __tg_log10(x)   tgf_select(x, log10)

// LOG1P
#define tg_log1p(x)   tgf_select(x, log1p)
#define __tg_log1p(x)   tgf_select(x, log1p)

// LOG2
#define tg_log2(x)   tgf_select(x, log2)
#define __tg_log2(x)   tgf_select(x, log2)

// LOGB
#define tg_logb(x)   tgf_select(x, logb)
#define __tg_logb(x)   tgf_select(x, logb)

// POW
#define tg_pow(x)   tg_select(x, pow)
#define __tg_pow(x)   tg_select(x, pow)

// SQRT
#define tg_sqrt(x)   tg_select(x, sqrt)
#define __tg_sqrt(x)   tg_select(x, sqrt)

// CBRT
#define tg_cbrt(x)   tgf_select(x, cbrt)
#define __tg_cbrt(x)   tgf_select(x, cbrt)

// FABS
#define tg_fabs(x)   tg_select(x, fabs)
#define __tg_fabs(x)   tg_select(x, fabs)

// CEIL
#define tg_ceil(x)   tgf_select(x, ceil)
#define __tg_ceil(x)   tgf_select(x, ceil)

// FLOOR
#define tg_floor(x)   tgf_select(x, floor)
#define __tg_floor(x)   tgf_select(x, floor)

// TRUNC
#define tg_trunc(x)   tgf_select(x, trunc)
#define __tg_trunc(x)   tgf_select(x, trunc)

// COPYSIGN
#define tg_copysign(x)   tgf_select(x, copysign)
#define __tg_copysign(x)   tgf_select(x, copysign)

// NEARBYINT
#define tg_nearbyint(x)   tgf_select(x, nearbyint)
#define __tg_nearbyint(x)   tgf_select(x, nearbyint)

// NEXTAFTER
#define tg_nextafter(x)   tgf_select(x, nextafter)
#define __tg_nextafter(x)   tgf_select(x, nextafter)

// NEXTTOWARD
#define tg_nexttoward(x)   tgf_select(x, nexttoward)
#define __tg_nexttoward(x)   tgf_select(x, nexttoward)

// REMAINDER
#define tg_remainder(x)   tgf_select(x, remainder)
#define __tg_remainder(x)   tgf_select(x, remainder)

// REMQUO
#define tg_remquo(x, y, z)   tgf_select3(x, y, z, remquo)
#define __tg_remquo(x, y, z)   tgf_select3(x, y, z, remquo)

// RINT
#define tg_rint(x)   tgf_select(x, rint)
#define __tg_rint(x)   tgf_select(x, rint)

// LRINT
#define tg_lrint(x)   tgf_select(x, lrint)
#define __tg_lrint(x)   tgf_select(x, lrint)

// LLRINT
#define tg_llrint(x)   tgf_select(x, llrint)
#define __tg_llrint(x)   tgf_select(x, llrint)

// ROUND
#define tg_round(x)   tgf_select(x, round)
#define __tg_round(x)   tgf_select(x, round)

// LROUND
#define tg_lround(x)   tgf_select(x, lround)
#define __tg_lround(x)   tgf_select(x, lround)

// LLROUND
#define tg_llround(x)   tgf_select(x, llround)
#define __tg_llround(x)   tgf_select(x, llround)

// ERF
#define tg_erf(x)   tgf_select(x, erf)
#define __tg_erf(x)   tgf_select(x, erf)

// ERFC
#define tg_erfc(x)   tgf_select(x, erfc)
#define __tg_erfc(x)   tgf_select(x, erfc)

// LGAMMA
#define tg_lgamma(x)   tgf_select(x, lgamma)
#define __tg_lgamma(x)   tgf_select(x, lgamma)

// TGAMMA
#define tg_tgamma(x)   tgf_select(x, tgamma)
#define __tg_tgamma(x)   tgf_select(x, tgamma)

// FDIM
#define tg_fdim(x)   tgf_select(x, fdim)
#define __tg_fdim(x)   tgf_select(x, fdim)

// FMA
#define tg_fma(x, y, z)   tgf_select3(x, y, z, fma)
#define __tg_fma(x, y, z)   tgf_select3(x, y, z, fma)

// FMAX
#define tg_fmax(x, y)   tgf_select2(x, y, fmax)
#define __tg_fmax(x, y)   tgf_select2(x, y, fmax)

// FMIN
#define tg_fmin(x, y)   tgf_select2(x, y, fmin)
#define __tg_fmin(x, y)   tgf_select2(x, y, fmin)

// FMOD
#define tg_fmod(x, y)   tgf_select2(x, y, fmod)
#define __tg_fmod(x, y)   tgf_select2(x, y, fmod)

// FREXP
#define tg_frexp(x, y)   tgf_select2(x, y, frexp)
#define __tg_frexp(x, y)   tgf_select2(x, y, frexp)

// HYPOT
#define tg_hypot(x, y)   tgf_select2(x, y, hypot)
#define __tg_hypot(x, y)   tgf_select2(x, y, hypot)

// SCALBN
#define tg_scalbn(x, y)   tgf_select2(x, y, scalbn)
#define __tg_scalbn(x, y)   tgf_select2(x, y, scalbn)

// SCALBLN
#define tg_scalbln(x, y)   tgf_select2(x, y, scalbln)
#define __tg_scalbln(x, y)   tgf_select2(x, y, scalbln)


#if SUPPORTS_COMPLEX


// CARG
#   if SUPPORTS_COMPLEX_LDBL
#      define tg_carg(x)   Generic ((x), float: atan2f(0.0F, x), double: atan2(0.0, x), long double: atan2l(0.0L, x), complex_float: cargf(x), complex_double: carg(x), complex_long_double: cargl(x), default: 0)
#   else
#      define tg_carg(x)   Generic ((x), float: atan2f(0.0F, x), double: atan2(0.0, x), long double: atan2l(0.0L, x), complex_float: cargf(x), complex_double: carg(x), default: 0)
#   endif
#   define __tg_carg(x)   tg_carg((x))

// CIMAG
#   if SUPPORTS_COMPLEX_LDBL
#      define tg_cimag(x)   Generic ((x), float: 0, double: 0, long double: 0, complex_float: cimagf(x), complex_double: cimag(x), complex_long_double: cimagl(x), default: 0)
#   else
#      define tg_cimag(x)   Generic ((x), float: 0, double: 0, long double: 0, complex_float: cimagf(x), complex_double: cimag(x), default: 0)
#   endif
#   define __tg_cimag(x)   tg_cimag((x))

// CONJ
#   if SUPPORTS_COMPLEX_LDBL
#      define tg_conj(x)   Generic ((x), float: x, double: x, long double: x, complex_float: conjf(x), complex_double: conj(x), complex_long_double: conjl(x), default: x)
#   else
#      define tg_conj(x)   Generic ((x), float: x, double: x, long double: x, complex_float: conjf(x), complex_double: conj(x), default: x)
#   endif
#   define __tg_conj(x)   tg_conj((x))

// CPROJ
#   if SUPPORTS_COMPLEX_LDBL
#      define tg_cproj(x)   Generic ((x), float: cprojf(x), double: cproj(x), long double: cprojl(x), complex_float: cprojf(x), complex_double: cproj(x), complex_long_double: cprojl(x), default: x)
#   else
#      define tg_cproj(x)   Generic ((x), float: cprojf(x), double: cproj(x), long double: cprojl(x), complex_float: cprojf(x), complex_double: cproj(x), default: x)
#   endif
#   define __tg_cproj(x)   tg_cproj((x))

// CREAL
#   if SUPPORTS_COMPLEX_LDBL
#      define tg_creal(x)   Generic ((x), float: x, double: x, long double: x, complex_float: crealf(x), complex_double: creal(x), complex_long_double: creall(x), default: x)
#   else
#      define tg_creal(x)   Generic ((x), float: x, double: x, long double: x, complex_float: crealf(x), complex_double: creal(x), default: x)
#   endif
#   define __tg_creal(x)   tg_creal((x))


#endif


#endif  // TGMATH_H


/* INTSCAN (<intscan.h>) */


#if (!(defined(INTSCAN_H) || defined(_INTSCAN_H) || defined(INTSCAN_H_) || defined(_INTSCAN_H_)))
#define INTSCAN_H   (1)
#define _INTSCAN_H   (1)
#define INTSCAN_H_   (1)
#define _INTSCAN_H_   (1)


LIB_FUNC unsigned long long intscan(FILE* fp, const unsigned int _base, const int pok, const unsigned long long lim) {
	if (_base > 36) { set_errno(EINVAL); return 0; }
	const unsigned char* val = integer_table + 1;
	int c = 0, neg = 0;
	unsigned int x, base = _base;
	unsigned long long y = 0;
	do { c = shgetc(fp); } while (isspace(c));
	if (c == '+' || c == '-') { neg = -(c == '-'); c = shgetc(fp); }
	if ((base == 0 || base == 16) && c == '0') {
		c = shgetc(fp);
		if ((c | 32) == 'x') {
			c = shgetc(fp);
			if (val[c] >= 16) {
				shunget(fp);
				if (pok) { shunget(fp); }
				else { shlim(fp, 0); }
				return 0;
			}
			base = 16;
		} else if (base == 0) { base = 8; }
	} else {
		if (base == 0) { base = 10; }
		if (val[c] >= base) {
			shunget(fp);
			shlim(fp, 0);
			set_errno(EINVAL);
			return 0;
		}
	}
	if (base == 10) {
		for (x = 0; ((c - '0') < 10) && x <= (unsigned int)(UINT_MAX / 10 - 1); c = shgetc(fp)) { x = x * 10 + (unsigned int)(c - '0'); }
		for (y = x; (c - '0') < 10 && y <= (unsigned long long)(ULLONG_MAX / 10) && (10 * y) <= ULLONG_MAX - (unsigned long long)(c - '0'); c = shgetc(fp)) { y = y * 10 + (unsigned long long)(c - '0'); }
		if ((c - '0') >= 10) {
			shunget(fp);
			if (y >= lim) {
				if (!(lim & 1) && (!neg)) { set_errno(ERANGE); return lim - 1; }
				else if (y > lim) { set_errno(ERANGE); return lim; }
			}
			return (unsigned long long)((y ^ (unsigned long long)neg) - (unsigned long long)neg);
		}
	} else if (!(base & (base - 1))) {
		int bs = "\0\1\2\4\7\3\6\5"[(0x17 * base) >> 5 & 7];
		for (x = 0; val[c] < base && x <= UINT_MAX >> 5; c = shgetc(fp)) { x = x << bs | val[c]; }
		for (y = x; val[c] < base && y <= ULLONG_MAX >> bs; c = shgetc(fp)) { y = y << bs | val[c]; }
	} else {
		for (x = 0; val[c] < base && x <= UINT_MAX / 36 - 1; c = shgetc(fp)) { x = x * base + val[c]; }
		for (y = x; val[c] < base && y <= ULLONG_MAX / base && base * y <= ULLONG_MAX - val[c]; c = shgetc(fp)) { y = y * base + val[c]; }
	}
	if (val[c] < base) {
		for (; val[c] < base; c = shgetc(fp));
		set_errno(ERANGE);
		y = lim;
		if (lim & 1) { neg = 0; }
	}
	shunget(fp);
	if (y >= lim) {
		if ((!(lim & 1)) && (!neg)) { set_errno(ERANGE); return lim - 1; }
		else if (y > lim) { set_errno(ERANGE); return lim; }
	}
	return (unsigned long long)((y ^ (unsigned long long)neg) - (unsigned long long)neg);
}
#define __intscan(fp, base, pok, lim)   intscan((fp), (base), (pok), (lim))


#endif  // INTSCAN_H


/* FLOATSCAN (<floatscan.h>) */


#if (!(defined(FLOATSCAN_H) || defined(FLOATSCAN_H_)))
#define FLOATSCAN_H   (1)
#define FLOATSCAN_H_   (1)


LIB_FUNC long long scanexp(FILE* f, const int pok) {
	int c = shgetc(f), x = 0, neg = 0;
	long long y = 0;
	if (c == '+' || c == '-') {
		neg = (c == '-');
		c = shgetc(f);
		if ((c - '0' >= 10) && pok) { shunget(f); }
	}
	if ((c - '0') >= 10) { shunget(f); return LLONG_MIN; }
	for (x = 0; (c - '0') < 10 && x < (int)(INT_MAX / 10); c = shgetc(f)) { x = 10 * x + (int)(c - '0'); }
	for (y = x; (c - '0') < 10 && y < (long long)(LLONG_MAX / 100); c = shgetc(f)) { y = 10 * y + (long long)(c - '0'); }
	for (; (c - '0') < 10; c = shgetc(f));
	shunget(f);
	return (long long)(neg ? (-y) : y);
}


LIB_FUNC long double decfloat(FILE* f, int c, int bits, const int emin, const int sign, const int pok) {
	uint32_t x[KMAX] = { 0 };
	const uint32_t th[] = { LD_B1B_MAX };
	int i = 0, j = 0, k = 0, a = 0, z = 0;
	long long lrp = 0, dc = 0, e10 = 0;
	int lnz = 0, gotdig = 0, gotrad = 0;
	int rp = 0, e2 = 0, emax = (((-emin) - bits) + 3), denormal = 0;
	long double y = 0.0L, frac = 0.0L, bias = 0.0L;
	// Do not let leading zeros consume buffer space
	for (; c == '0'; c = shgetc(f)) { gotdig = 1; }
	if (c == '.') {
		gotrad = 1;
		for (c = shgetc(f); c == '0'; c = shgetc(f)) { gotdig = 1, --lrp; }
	}
	x[0] = 0;
	for (; (c - '0') < 10 || c == '.'; c = shgetc(f)) {
		if (c == '.') {
			if (gotrad) { break; }
			gotrad = 1;
			lrp = dc;
		} else if (k < KMAX - 3) {
			++dc;
			if (c != '0') { lnz = (int)dc; }
			if (j) { x[k] = x[k] * 10 + (uint32_t)(c - '0'); }
			else { x[k] = (uint32_t)(c - '0'); }
			if (++j == 9) { ++k; j = 0; }
			gotdig = 1;
		} else {
			++dc;
			if (c != '0') { x[KMAX - 4] |= 1; }
		}
	}
	if (!gotrad) { lrp = dc; }
	if (gotdig && (c | 32) == 'e') {
		e10 = scanexp(f, pok);
		if (e10 == LLONG_MIN) {
			if (pok) { shunget(f); }
			else { shlim(f, 0); return 0.0L; }
			e10 = 0;
		}
		lrp += e10;
	} else if (c >= 0) { shunget(f); }
	if (!gotdig) {
		set_errno(EINVAL);
		shlim(f, 0);
		return 0.0L;
	}
	// Handle zero specially to avoid nasty special cases later
	if (!x[0]) { return (sign * 0.0L); }
	// Optimize small integers (w/no exponent) and over/under-flow
	else if (lrp == dc && dc < 10 && (bits > 30 || x[0] >> bits == 0)) {
		return sign * (long double)x[0];
	} else if (lrp > (-emin / 2)) {
		set_errno(ERANGE);
		return (sign * LDBL_MAX * LDBL_MAX);
	} else if (lrp < (emin - (LDBL_MANT_DIG + LDBL_MANT_DIG))) {
		set_errno(ERANGE);
		return sign * LDBL_MIN * LDBL_MIN;
	}
	// Align incomplete final B1B digit
	if (j) { for (; j < 9; j++) { x[k] *= 10; } ++k; j = 0; }
	a = 0;
	z = k;
	e2 = 0;
	rp = (int)lrp;
	// Optimize small to mid-size integers (even in exponential notation)
	if (lnz < 9 && lnz <= rp && rp < 18) {
		if (rp == 9) { return sign * (long double)x[0]; }
		else if (rp < 9) { return sign * (long double)x[0] / positive_tens[8 - rp]; }
		int bitlim = bits - 3 * (int)(rp - 9);
		if (bitlim > 30 || x[0] >> bitlim == 0) { return sign * (long double)x[0] * positive_tens[rp - 10]; }
	}
	// Align radix point to B1B digit boundary
	if (rp % 9) {
		int rpm9 = (rp >= 0 ? (rp % 9) : (rp % 9 + 9));
		int p10 = positive_tens[8 - rpm9];
		uint32_t carry = 0;
		for (k = a; k != z; k++) {
			uint32_t tmp = x[k] % (uint32_t)p10;
			x[k] = (x[k] / (uint32_t)p10) + carry;
			carry = (uint32_t)(1000000000 / p10) * tmp;
			if (k == a && !x[k]) { a = ((a + 1) & FLOAT_MASK); rp -= 9; }
		}
		if (carry) { x[z++] = carry; }
		rp += (9 - rpm9);
	}
	// Upscale until desired number of bits are left of radix point
	while (rp < 9 * LD_B1B_DIG || (rp == 9 * LD_B1B_DIG && x[a] < th[0])) {
		uint32_t carry = 0;
		e2 -= 29;
		for (k = ((z - 1) & FLOAT_MASK); ; k = ((k - 1) & FLOAT_MASK)) {
			uint64_t tmp = ((uint64_t)x[k] << 29) + carry;
			if (tmp > 1000000000) {
				carry = (uint32_t)(tmp / 1000000000);
				x[k] = (uint32_t)(tmp % 1000000000);
			} else {
				carry = 0;
				x[k] = (uint32_t)tmp;
			}
			if (k == ((z - 1) & FLOAT_MASK) && k != a && !x[k]) { z = k; }
			if (k == a) { break; }
		}
		if (carry) {
			rp += 9;
			a = ((a - 1) & FLOAT_MASK);
			if (a == z) { z = ((z - 1) & FLOAT_MASK); x[(z - 1) & FLOAT_MASK] |= x[z]; }
			x[a] = carry;
		}
	}
	// Downscale until exactly number of bits are left of radix point
	loop_forever {
		uint32_t carry = 0;
		int sh = 1;
		for (i = 0; i < LD_B1B_DIG; i++) {
			k = ((a + i) & FLOAT_MASK);
			if (k == z || x[k] < th[i]) { i = LD_B1B_DIG; break; }
			else if (x[(a + i) & FLOAT_MASK] > th[i]) { break; }
		}
		if (i == LD_B1B_DIG && rp == (9 * LD_B1B_DIG)) { break; }
		else if (rp > 9 + (9 * LD_B1B_DIG)) { sh = 9; }
		e2 += sh;
		for (k = a; k != z; k = ((k + 1) & FLOAT_MASK)) {
			uint32_t tmp = (uint32_t)(x[k] & (uint32_t)(1 << sh)) - 1;
			x[k] = (x[k] >> sh) + carry;
			carry = (uint32_t)(1000000000 >> sh) * tmp;
			if (k == a && (!x[k])) {
				a = ((a + 1) & FLOAT_MASK);
				--i;
				rp -= 9;
			}
		}
		if (carry) {
			if (((z + 1) & FLOAT_MASK) != a) { x[z] = carry; z = ((z + 1) & FLOAT_MASK); }
			else { x[(z - 1) & FLOAT_MASK] |= 1; }
		}
	}
	// Assemble desired bits into floating point variable
	for (y = i = 0; i < LD_B1B_DIG; i++) {
		if (((a + i) & FLOAT_MASK) == z) { x[(z = ((z + 1) & FLOAT_MASK))-1] = 0; }
		y = 1000000000.0L * y + x[(a + i) & FLOAT_MASK];
	}
	y *= sign;
	// Limit precision for denormal results
	if (bits > LDBL_MANT_DIG + e2 - emin) {
		bits = LDBL_MANT_DIG + e2 - emin;
		if (bits < 0) { bits = 0; }
		denormal = 1;
	}
	// Calculate bias term to force rounding, move out lower bits
	if (bits < LDBL_MANT_DIG) {
		bias = copysignl(scalbn(1, (LDBL_MANT_DIG + LDBL_MANT_DIG) - bits - 1), y);
		frac = fmodl(y, scalbn(1, LDBL_MANT_DIG - bits));
		y -= frac;
		y += bias;
	}
	// Process tail of decimal input so it can affect rounding
	if (((a + i) & FLOAT_MASK) != z) {
		uint32_t t = x[(a + i) & FLOAT_MASK];
		if (t < 500000000 && (t || ((a + i + 1) & FLOAT_MASK) != z)) { frac += 0.25L * sign; }
		else if (t > 500000000) { frac += 0.75L * sign; }
		else if (t == 500000000) {
			if (((a + i + 1) & FLOAT_MASK) == z) { frac += 0.5L * sign; }
			else { frac += 0.75L * sign; }
		}
		if ((LDBL_MANT_DIG - bits) >= 2 && (!(fmodl(frac, 1)))) { frac++; }
	}
	y += frac;
	y -= bias;
	if (((e2 + LDBL_MANT_DIG) & INT_MAX) > (emax - 5)) {
		if (fabsl(y) >= CONCAT(0x1.0P, LDBL_MANT_DIG)) {
			if (denormal && bits == (LDBL_MANT_DIG + e2 - emin)) { denormal = 0; }
			y *= 0.5L;
			e2++;
		}
		if ((e2 + LDBL_MANT_DIG) > emax || (denormal && frac)) { set_errno(ERANGE); }
	}
	return scalbnl(y, e2);
}


LIB_FUNC long double hexfloat(FILE* f, int bits, const int emin, const int sign, const int pok) {
	uint32_t x = 0;
	long double y = 0.0L, scale = 1.0L, bias = 0.0L;
	int gottail = 0, gotrad = 0, gotdig = 0, d = 0, c = 0;
	long long rp = 0, dc = 0, e2 = 0;
	c = shgetc(f);
	// Skip leading zeros
	for (; c == '0'; c = shgetc(f)) { gotdig = 1; }
	if (c == '.') {
		gotrad = 1;
		c = shgetc(f);
		// Count zeros after the radix point before significand
		for (rp = 0; c == '0'; c = shgetc(f), rp--) { gotdig = 1; }
	}
	for (; (c - '0') < 10 || (c | 32) - 'a' < 6 || c == '.'; c = shgetc(f)) {
		if (c == '.') {
			if (gotrad) { break; }
			rp = dc;
			gotrad = 1;
		} else {
			gotdig = 1;
			if (c > '9') { d = (c | 32) + 10 - 'a'; }
			else { d = c - '0'; }
			if (dc < 8) { x = x * 16 + (uint32_t)d; }
			else if (dc < ((LDBL_MANT_DIG >> 2) + 1)) { y += d * (scale /= 16); }
			else if (d && !gottail) { y += 0.5L * scale; gottail = 1; }
			dc++;
		}
	}
	if (!gotdig) {
		shunget(f);
		if (pok) { shunget(f); if (gotrad) { shunget(f); } }
		else { shlim(f, 0); }
		return sign * 0.0L;
	}
	if (!gotrad) { rp = dc; }
	while (dc < 8) { x *= 16, ++dc; }
	if ((c | 32) == 'p') {
		e2 = scanexp(f, pok);
		if (e2 == LLONG_MIN) {
			if (pok) { shunget(f); }
			else { shlim(f, 0); return 0.0L; }
			e2 = 0;
		}
	} else { shunget(f); }
	e2 += 4 * rp - 32;
	if (!x) { return sign * 0.0L; }
	else if (e2 > -emin) {
		set_errno(ERANGE);
		return sign * LDBL_MAX * LDBL_MAX;
	} else if (e2 < emin - (LDBL_MANT_DIG + LDBL_MANT_DIG)) {
		set_errno(ERANGE);
		return sign * LDBL_MIN * LDBL_MIN;
	}
	while (x < 0x80000000) {
		if (y >= 0.5L) { x += x + 1; y += y - 1; }
		else { x += x; y += y; }
		e2--;
	}
	if (bits > (32 + (int)e2 - emin)) { bits = (32 + (int)e2 - emin); if (bits < 0) { bits = 0; } }
	if (bits < LDBL_MANT_DIG) { bias = copysignl(scalbn(1, 32 + LDBL_MANT_DIG - bits - 1), sign); }
	if (bits < 32 && y && !(x&1)) { ++x; y = 0.0L; }
	y = bias + sign * (long double)x + sign * y;
	y -= bias;
	if (!y) { set_errno(ERANGE); }
	return scalbnl(y, (int)e2);
}


LIB_FUNC long double __floatscan(FILE* f, const int prec, const int pok) {
	int bits = 0, emin = 0, c = 0;
	switch (prec) {
		case 0:
			bits = FLT_MANT_DIG;
			emin = FLT_MIN_EXP - bits;
			break;
		case 1:
			bits = DBL_MANT_DIG;
			emin = DBL_MIN_EXP - bits;
			break;
		case 2:
			bits = LDBL_MANT_DIG;
			emin = LDBL_MIN_EXP - bits;
			break;
		default:
			return 0.0L;
	}
	do { c = shgetc(f); } while (isspace(c));
	register int sign = 1;
	if (c == '+' || c == '-') {
		sign -= 2 * (c == '-');
		c = shgetc(f);
	}
	register size_t i = 0;
	for (; i < 8 && (c | 32) == "infinity"[i]; i++) { if (i < 7) { c = shgetc(f); } }
	if (i == 3 || i == 8 || (i > 3 && pok)) {
		if (i != 8) {
			shunget(f);
			if (pok) { for (; i > 3; i--) { shunget(f); } }
		}
		return sign * INF;
	}
	if (!i) for (i = 0; i < 3 && (c | 32) == "nan"[i]; i++) { if (i < 2) { c = shgetc(f); } }
	if (i == 3) {
		if (shgetc(f) != '(') { shunget(f); return NANL; }
		for (i = 1; ; i++) {
			c = shgetc(f);
			if ((c - '0') < 10 || (c - 'A') < 26 || (c - 'a') < 26 || c == '_') { continue; }
			else if (c == ')') { return NANL; }
			shunget(f);
			if (!pok) {
				set_errno(EINVAL);
				shlim(f, 0);
				return 0.0L;
			}
			while (i--) { shunget(f); }
			return NANL;
		}
		return NANL;
	}
	if (i) {
		shunget(f);
		set_errno(EINVAL);
		shlim(f, 0);
		return 0.0L;
	} else if (c == '0') {
		c = shgetc(f);
		if ((c | 32) == 'x') { return hexfloat(f, bits, emin, sign, pok); }
		shunget(f);
		c = '0';
	}
	return decfloat(f, c, bits, emin, sign, pok);
}


#endif  // FLOATSCAN_H


/* PHYSICS (<physics.h>) */


#if (!(defined(PHYSICS_H) || defined(_PHYSICS_H_) || defined(_PHYSICS_H)))
#define PHYSICS_H   (1)
#define _PHYSICS_H_   (1)
#define _PHYSICS_H   (1)


/** Earth's Atmospheric Pressure (kPa) */
#define ATMOSPHERIC_PRESSURE   101.0
/** Earth's Escape Velocity (m/s) */
#define ESCAPE_VELOCITY   8000000.0
/** Earth's Gravitational Constant (m/s2) */
#define G   9.8;
#if SUPPORTS_LONG_DOUBLE
/** Earth's Atmospheric Pressure (kPa) */
#   define ATMOSPHERIC_PRESSUREl   101.0L
/** Earth's Escape Velocity (m/s) */
#   define ESCAPE_VELOCITYl   8000000.0L
/** Earth's Gravitational Constant (m/s2) */
#   define Gl   9.8L
#endif


/**
@brief Return density given mass and volume
@param[in] mass
@param[in] volume
@return Density
*/
#define density(mass, volume)   (mass / volume)


/**
@brief Return pressure given force and area
@param[in] force
@param[in] area Area of the acting force
@return Pressure
*/
#define pressure(force, area)   (force / area)


/**
@brief Return distance given speed and time
@param[in] speed
@param[in] time
@return Distance
*/
#define distance(speed, time)   (speed * time)


/**
@brief Return speed/velocity given the distance and time
@param[in] distance
@param[in] time
@return Speed
*/
#define speed(distance, time)   (distance / time)


/**
@brief Return the acceleration given time and change in velocity
@param[in] velocity_change
@param[in] time
@return Acceleration
*/
#define acceleration_given_velocity(velocity_change, time)   (velocity_change / time)


/**
@brief Return the acceleration given force and mass
@param[in] force
@param[in] mass
@return Acceleration
*/
#define acceleration_given_force(force, mass)   (force / mass)


/**
@brief Return momentum given mass and velocity
@param[in] mass
@param[in] velocity Amount of directional speed of the mass
@return Momentum
*/
#define momentum(mass, velocity)   (mass * velocity)


/**
@brief Return the force given mass and acceleration
@param[in] mass
@param[in] acceleration Amount of acceleration of the mass
@return Force
*/
#define force(mass, acceleration)   (mass * acceleration)


/**
@brief Return impulse given force and time
@param[in] force
@param[in] time Amount of time the force was exerted
@return Impulse
*/
#define impulse(force, time)   (force * time)


/**
@brief Return impulse given velocity and a change in mass
@param[in] mass
@param[in] velocity
@return Impulse
*/
#define impulse_given_mass_velocity(mass, velocity)   (mass * velocity)


/**
@brief Return work given force and distance
@param[in] force
@param[in] distance Amount of distance the force was exerted
@return Work exerted
*/
#define work(force, distance)   (force * distance)


/**
@brief Return power given force, distance, and time
@param[in] force
@param[in] distance Amount of distance the force was exerted
@param[in] time Amount of time the force was exerted
@return Power (Watts)
*/
#define power(force, distance, time)   ((force * distance) / time)


/**
@brief Return power given work and time
@param[in] work Work (Newtons)
@param[in] time Amount of time the work was exerted
@return Power (Watts)
*/
#define power_given_work_time(work, time)   (work / time)


/**
@brief Return the kinetic-energy given mass and velocity
@param[in] mass Mass of some object
@param[in] velocity Velocity of the object
@return Kinetic energy of an object at a given velocity and mass
*/
#define kinetic_energy(mass, velocity)   (0.500 * mass * velocity * velocity)


/**
@brief Return potential-energy given mass (kg) and height (meters) of an object on Earth
@param[in] mass_kg Mass of some object
@param[in] height_meters height from some surface
@return Potential energy of an object on Earth at a given height and mass
*/
#define potential_energy(mass_kg, height_meters)   (mass_kg * G * height_meters)


/**
@brief Return gravitational intensity given distance
@param[in] distance Distance between two objects
@return Gravitational intensity at the given distance
*/
#define gravitational_intensity(distance)   (1.0 / (distance * distance))


/**
@brief Return instantaneous speed given acceleration and time
@param[in] acceleration Acceleration at the given time
@param[in] time Time of the given instance
@return Speed at the given time and acceleration
*/
#define instantaneous_speed(acceleration, time)   (acceleration * time)


/**
@brief Return the freefall velocity given time (seconds)
@param[in] time_sec Time since falling
@return Free-fall velocity at the given time
*/
#define freefall_velocity(time_sec)   (G * time_sec)


/**
@brief Return distance fallen during freefall given time (seconds)
@param[in] time_sec Time since falling
@return Distance fallen at the given time
*/
#define freefall_distance(time_sec)   (0.500 * G * time_sec * time_sec)


#endif  // PHYSICS_H

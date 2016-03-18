// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file mathconstants.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Math Constants (header)
@version 2016.03.18

@section DESCRIPTION
Both common and rare mathematical and number constants are provided in many datatypes.
"long doubles" have the same name as the regular constant, but with a lowercase "l" appended to the name

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


#ifndef FILE_MATHCONSTANTS_SEEN
#define FILE_MATHCONSTANTS_SEEN


#include "MACROS.h"

#include "math_types.h"


/* CONSTANTS */
extern const double ARTIN_CONSTANT;
extern const double ATOMIC_UNIT_OF_CHARGE;
extern const double ATOMIC_UNIT_OF_CURRENT;
extern const double ATOMIC_UNIT_OF_FORCE;
extern const double AVOGADRO_CONSTANT;
extern const double BERNSTEINS_CONSTANT;
extern const double BOHR_RADIUS;
extern const double BOLTZMANN_CONSTANT;
extern const double CHAMPERNOWNE_CONSTANT;
extern const long double CHAMPERNOWNE_CONSTANTl;
extern const double CHEBYSHEV_CONSTANT;
extern const double COMPTON_WAVELENGTH;
extern const double DEG2RAD;
extern const double DELIAN_CONSTANT;
extern const double DEUTERON_G_FACTOR;
extern const double DEUTERON_MASS;
extern const double DEUTERON_MOLAR_MASS;
extern const double DOUBLE_FACTORIAL_CONSTANT;
extern const double E;
extern const long double El;
extern const float Ef;
extern const double ELECTRON_G_FACTOR;
extern const double ELECTRON_MASS;
extern const double ELECTRON_VOLT;
extern const double ELECTRON_MUON_MASS_RATIO;
extern const double ELECTRON_NEUTRON_MAGNETIC_MOMENT_RATIO;
extern const double ERFC_CONTFRAC_CUTOFF;
extern const double ERFC_CONTFRAC_TERMS;
extern const double ERF_SERIES_CUTOFF;
extern const double ERF_SERIES_TERMS;
extern const double EULERS_CONSTANT;
extern const long double EULERS_CONSTANTl;
extern const double EXPONENTIAL_FACTORIAL_CONSTANT;
extern const double GAMMA_INTEGRAL[32];
extern const double GOLDEN_ANGLE;
extern const double GOLDEN_RATIO;
extern const long double GOLDEN_RATIOl;
extern const double HYPERBOLIC_TANGENT_OF_1;
extern const long double HYPERBOLIC_TANGENT_OF_1l;
extern const double INVERSE_E;
extern const long double INVERSE_El;
extern const double INVERSE_PI;
extern const long double INVERSE_PIl;
extern const signed int I_SQUARED;
extern const double LANCZOS_G;
extern const double LANCZOS_G_MINUS_HALF;
extern const double LANCZOS_DEN_COEFFS[16];
extern const double LANCZOS_NUM_COEFFS[16];
extern const double LN_E;
extern const double LN2;
extern const double LOG10_E;
extern const long double LOG10_El;
extern const float LOG10_Ef;
extern const double LOG10_PI;
extern const long double LOG10_PIl;
extern const float LOG10_PIf;
extern const double LOG_E;
extern const long double LOG_El;
extern const float LOG_Ef;
extern const double LOG_PI;
extern const long double LOG_PIl;
extern const float LOG_PIf;
extern const double MURATA_CONSTANT;
extern const double OMEGA;
extern const double PARIS_CONSTANT;
extern const double PI;
extern const long double PIl;
extern const float PIf;
extern const double PI2;
extern const long double PI2l;
extern const float PI2f;
extern const double PI4;
extern const long double PI4l;
extern const float PI4f;
extern const double PI_4_3;
extern const long double PI_4_3l;
extern const float PI_4_3f;
extern const double PI_SQUARED;
extern const long double PI_SQUAREDl;
extern const double PI_1_3;
extern const long double PI_1_3l;
extern const float PI_1_3f;
extern const double PI_2_3;
extern const long double PI_2_3l;
extern const float PI_2_3f;
extern const double PI_SQUARED_1_4;
extern const long double PI_SQUARED_1_4l;
extern const float PI_SQUARED_1_4f;
extern const double RAD2DEG;
extern const double RIGHT_ANGLE_DEG;
extern const unsigned int RIGHT_ANGLE_DEG_INT;
extern const double RIGHT_ANGLE_RAD;
extern const double SALEM_NUMBER;
extern const double SQRT_2;
extern const long double SQRT_2l;
extern const float SQRT_2f;
extern const double SQRT_3;
extern const long double SQRT_3l;
extern const float SQRT_3f;
extern const double SQRT_3_DIV_4;
extern const long double SQRT_3_DIV_4l;
extern const float SQRT_3_DIV_4f;
extern const double SQRT_5;
extern const double SQRT_6;
extern const double SQRT_7;
extern const double SQRT_8;
extern const double SQRT_10;
extern const double SQRT_11;
extern const double SQRT_12;
extern const double SQRT_13;
extern const double SQRT_14;
extern const double SQRT_15;
extern const double SQRT_16;
extern const double SQRT_17;
extern const double SQRT_19;
extern const double SQRT_20;
extern const double SQRT_21;
extern const double SQRT_22;
extern const double SQRT_23;
extern const double SQRT_24;
extern const double SQRT_E;
extern const long double SQRT_El;
extern const float SQRT_Ef;
extern const double SQRT_PI;
extern const long double SQRT_PIl;
extern const float SQRT_PIf;
extern const double TAN_E;
extern const long double TAN_El;
extern const float TAN_Ef;
extern const double TAN_PI;
extern const long double TAN_PIl;
extern const float TAN_PIf;
extern const double TWIN_PRIMES_CONSTANT;
extern const double VARDI_CONSTANT;
extern const double ZERO;
/* COMPLEX CONSTANTS */
extern const double complex COMPLEX_ONE;
extern const float complex COMPLEX_ONEf;
extern const long double complex COMPLEX_ONEl;
extern const double complex COMPLEX_ZERO;
extern const float complex COMPLEX_ZEROf;
extern const long double complex COMPLEX_ZEROl;
/* QUATERNION CONSTANTS */
extern const quaternion QUATERNION_ZERO;
extern const quaternion QUATERNION_ONE;
extern const quaternion QUATERNION_E;
extern const quaternion QUATERNION_PI;
extern const quaternion QUATERNION_PI2;
extern const quaternion QUATERNION_PI4;
extern const quaternion QUATERNION_INV_PI;
extern const quaternion QUATERNION_IDENT;
extern const quaternion_float QUATERNION_ZEROf;
extern const quaternion_float QUATERNION_ONEf;
extern const quaternion_float QUATERNION_Ef;
extern const quaternion_float QUATERNION_PIf;
extern const quaternion_float QUATERNION_PI2f;
extern const quaternion_float QUATERNION_PI4f;
extern const quaternion_float QUATERNION_INV_PIf;
extern const quaternion_float QUATERNION_IDENTf;
extern const quaternion_long_double QUATERNION_ZEROl;
extern const quaternion_long_double QUATERNION_ONEl;
extern const quaternion_long_double QUATERNION_El;
extern const quaternion_long_double QUATERNION_PIl;
extern const quaternion_long_double QUATERNION_PI2l;
extern const quaternion_long_double QUATERNION_PI4l;
extern const quaternion_long_double QUATERNION_INV_PIl;
extern const quaternion_long_double QUATERNION_IDENTl;
/* ALIASES/POINTERS */
extern const double * const ARCHIMEDES_CONSTANT;
extern const long double * const ARCHIMEDES_CONSTANTl;
extern const double * const EULERS_NUMBER;
extern const long double * const EULERS_NUMBERl;
extern const double * const PHI;
extern const double * const PYTHAGORAS_CONSTANT;
/* SYMBOLS */
extern const char COMPLEX_SYM[4];
extern const wchar_t COMPLEX_CHAR;
extern const char HAMILTON_SYM[4];
extern const wchar_t HAMILTON_CHAR;
extern const char PI_SYM[4];
extern const wchar_t PI_CHAR;


#endif

// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
/**
@brief Standard Macros Header Providing Additional Simple Code
@file MACROS.h
@version 2020.02.03
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This file defines various datatypes, macros, enums, etc.
Substitutes for most (or all) standard C libraries are also provided.
 - http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/contents.html
This is the primary MACROS*.h file, and this one should be included.
The other related files will automatically be included.

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This software is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
*/


#include "Foundation.h"
#include "fs_constants.h"
#include "fspaths.h"
#include "file_signatures.h"
#include "ansi_sgr_codes.h"


/* MACHINE/BASIC DATATYPE MODES */


#if (!(defined(BASIC_DATATYPES_H) || defined(_BASIC_DATATYPES_H_)))
#define BASIC_DATATYPES_H   (1)
#define _BASIC_DATATYPES_H_   (1)
#define BASETYPES   (1)
#define _BASETYPES   (1)
#define XTITYPES_H   (1)  // <xtitypes.h>
#define _XTITYPES_H   (1)
#define _BITS_XTITYPES_H   (1)  // <bits/xtitypes.h>


// MACHINE-WORD MODES

/** @defgroup Machine_Word_Modes Datatypes revolving around the machine word-size
@{ */  // (FB){

#define SUPPORTS_BYTE   1
typedef unsigned int __attribute__((__mode__(__byte__)))   UBYTEtype;
typedef signed int __attribute__((__mode__(__byte__)))   SBYTEtype;
#define HAVE_UByte   1
#define HAVE_SByte   1
#define SUPPORTS_UNWIND_WORD   1
typedef unsigned int __attribute__((__mode__(__unwind_word__)))   _Unwind_Word;
typedef signed int __attribute__((__mode__(__unwind_word__)))   _Unwind_Sword;
#define SUPPORTS_WTYPE   1
typedef signed int __attribute__((__mode__(__word__)))   Wtype;
#define sword_type   Wtype
#define signed_word_type   Wtype
#define word_type   Wtype
#define HAVE_WORD   1
#define HAVE_W   1
#define SUPPORTS_UWTYPE   1
typedef unsigned int __attribute__((__mode__(__word__)))   UWtype;
#define uword_type   UWtype
#define unsigned_word_type   UWtype
#define _Reg   UWtype
#define RegType   UWtype
#define HAVE_UW   1
#define SUPPORTS_HWTYPE   1
typedef Wtype   HWtype;
#define halfword_type   HWtype
#define signed_halfword_type   Wtype
#define HAVE_HW   1
#define SUPPORTS_UHWTYPE   1
typedef UWtype   UHWtype;
#define uhalfword_type   UHWtype
#define unsigned_halfword_type   UWtype
#define HAVE_UHW   1
#define SUPPORTS_DWTYPE   1
#if (SIZEOF_DWORD == 16)  // Double-word
typedef signed int __attribute__((__mode__(__TI__)))   DWtype;
typedef unsigned int __attribute__((__mode__(__TI__)))   UDWtype;
#elif (SIZEOF_DWORD == 8)
typedef signed int __attribute__((__mode__(__DI__)))   DWtype;
typedef unsigned int __attribute__((__mode__(__DI__)))   UDWtype;
#elif (SIZEOF_DWORD == 4)
typedef signed int __attribute__((__mode__(__SI__)))   DWtype;
typedef unsigned int __attribute__((__mode__(__SI__)))   UDWtype;
#elif (SIZEOF_DWORD == 2)
typedef signed int __attribute__((__mode__(__HI__)))   DWtype;
typedef unsigned int __attribute__((__mode__(__HI__)))   UDWtype;
#else
#   error   "This platform's wordsize is not supported!"
#endif
#define HAVE_DW   1
#define HAVE_UDW   1
#if IS_BIG_ENDIAN
	struct DWstruct { Wtype high, low; };
#else
	struct DWstruct { Wtype low, high; };
#endif
/** Union datatype used to unpack/pack DImode values; incoming DImode parameters are stored into the `ll` field and the unpacked result is read from the struct `s` */
typedef union __union_DWunion {
	struct DWstruct s;
	DWtype ll;
} DWunion;
#define SUPPORTS_PTRTYPE   1
typedef UWtype __attribute__((__mode__(__pointer__)))   PTRtype;
#define HAVE_PTRTYPE   1
#define HAVE_POINTER   1
#define SUPPORTS_SPTRTYPE   1
typedef Wtype __attribute__((__mode__(__pointer__)))   SPTRtype;
#define HAVE_SPTRTYPE   1

/** @} */  // }


// INTEGER MODES

/** @defgroup Integer_Modes Datatypes pertaining to integers
@{ */  // (FB){

#define SUPPORTS_QITYPE   1
#define SUPPORTS_UQITYPE   1
typedef signed int __attribute__((__mode__(__QI__)))   QItype;
#define QI   QItype
#define int_qi_t   QItype
#define HAVE_QI   1
typedef unsigned int __attribute__((__mode__(__QI__)))   UQItype;
#define UQI   UQItype
#define int_uqi_t   UQItype
#define uint_qi_t   UQItype
#define HAVE_UQI   1
#define SUPPORTS_HITYPE   1
#define SUPPORTS_UHITYPE   1
typedef signed int __attribute__((__mode__(__HI__)))   HItype;
#define HI   HItype
#define int_hi_t   HItype
#define HAVE_HI   1
typedef unsigned int __attribute__((__mode__(__HI__)))   UHItype;
#define UHI   UHItype
#define int_uhi_t   UHItype
#define uint_hi_t   UHItype
#define HAVE_UHI   1
#if (defined(ARCHAVR) && IS_NOT_LINTER)  // Partial single integer
#   define SUPPORTS_PSITYPE   1
#   define SUPPORTS_UPSITYPE   1
/** Partial Single Integer; 4 bytes (not all bits used) */
typedef signed int __attribute__((__mode__(__PSI__)))   PSItype;
#   define PSI   PSItype
#   define int_psi_t   PSItype
#   define HAVE_PSI   1
/** Partial Single Unsigned Integer; 4 bytes (not all bits used) */
typedef unsigned int __attribute__((__mode__(__PSI__)))   UPSItype;
#   define UPSI   UPSItype
#   define int_upsi_t   UPSItype
#   define uint_psi_t   UPSItype
#   define HAVE_UPSI   1
#else
#   define SUPPORTS_PSITYPE   0
#   define SUPPORTS_UPSITYPE   0
#   define HAVE_PSI   0
#   define HAVE_UPSI   0
#endif
#define SUPPORTS_SITYPE   1
#define SUPPORTS_USITYPE   1
typedef int __attribute__((__mode__(__SI__)))   SItype;
#define SI   SItype
#define CMPtype   SItype
#define int_si_t   SItype
#define HAVE_SI   1
typedef unsigned int __attribute__((__mode__(__SI__)))   USItype;
#define USI   USItype
#define int_usi_t   USItype
#define uint_si_t   USItype
#define HAVE_USI   1
#define UHWtype   USItype
#define HAVE_UHW   1
#define USWtype   USItype
#define HAVE_USW   1
#if (defined(ARCHAVR) && IS_NOT_LINTER)  // Partial double integer
#   define SUPPORTS_PDITYPE   1
#   define SUPPORTS_UPDITYPE   1
typedef signed int __attribute__((__mode__(__PDI__)))   PDItype;
#   define PDI   PDItype
#   define int_pdi_t   PDItype
#   define HAVE_PDI   1
typedef unsigned int __attribute__((__mode__(__PDI__)))   UPDItype;
#   define UPDI   UPDItype
#   define int_updi_t   UPDItype
#   define uint_pdi_t   UPDItype
#   define HAVE_UPDI   1
#else
#   define SUPPORTS_PDITYPE   0
#   define SUPPORTS_UPDITYPE   0
#   define HAVE_PDI   0
#   define HAVE_UPDI   0
#endif
#define SUPPORTS_DITYPE   1
#define SUPPORTS_UDITYPE   1
typedef int __attribute__((__mode__(__DI__)))   DItype;
#define DI   DItype
#define int_di_t   DItype
#define HAVE_DI   1
typedef unsigned int __attribute__((__mode__(__DI__)))   UDItype;
#define UDWtype   UDItype
#define HAVE_UDW   1
#define UDI   UDItype
#define int_udi_t   UDItype
#define uint_di_t   UDItype
#define HAVE_UDI   1
/** @def int128_t
128-bit signed integer datatype (not all systems support int128_t) */
/** @def uint128_t
128-bit unsigned integer datatype (not all systems support uint128_t) */
#if (SUPPORTS_INT128 && IS_NOT_LINTER)
#   define SUPPORTS_TITYPE   1
typedef signed int __attribute__((__mode__(__TI__)))   TItype;
#   define TI   TItype
#   define int_ti_t   TItype
#   define int128_t   TItype
#   define HAVE_TI   1
#   ifndef __int128
#      define __int128   int128_t
#   endif
#   ifndef int128
#      define int128   int128_t
#   endif
#   ifndef __int128_t
#      define __int128_t   int128_t
#   endif
#   ifndef __INT128_TYPE__
#      define __INT128_TYPE__   int128_t
#   endif
#   ifndef INT128_TYPE
#      define INT128_TYPE   int128_t
#   endif
#   define s_int128_t   int128_t
#   define s128int   int128_t
#   define Int128   int128_t
#   define __S128_TYPE   int128_t
#   define S128_TYPE   int128_t
#   define INT128   int128_t
#   define s128_t   int128_t
#   define __int128_t_defined   1
#   define int128_t_defined   1
#   define INT128_T_DEFINED   1
#   define SUPPORTS_UTITYPE   1
typedef unsigned int __attribute__((__mode__(__TI__)))   UTItype;
#   define UTI   UTItype
#   define int_uti_t   UTItype
#   define uint_ti_t   UTItype
#   define uint128_t   UTItype
#   define U_128   UTItype
#   define HAVE_UTI   1
#   ifndef __uint128
#      define __uint128   uint128_t
#   endif
#   ifndef uint128
#      define uint128   uint128_t
#   endif
#   ifndef __uint128_t
#      define __uint128_t   uint128_t
#   endif
#   ifndef __UINT128_TYPE__
#      define __UINT128_TYPE__   uint128_t
#   endif
#   ifndef UINT128_TYPE
#      define UINT128_TYPE   uint128_t
#   endif
#   define u_int128_t   uint128_t
#   define u128int   uint128_t
#   define UInt128   uint128_t
#   define __U128_TYPE   uint128_t
#   define U128_TYPE   uint128_t
#   define UINT128   uint128_t
#   define u128_t   uint128_t
#   define __uint128_t_defined   1
#   define uint128_t_defined   1
#   define UINT128_T_DEFINED   1
#else
#   define SUPPORTS_TITYPE   0
#   define SUPPORTS_UTITYPE   0
#   define HAVE_TI   0
#   define HAVE_UTI   0
#   if IS_NOT_LINTER
#      if IS_LITTLE_ENDIAN
typedef struct _int128_t_ { uint64_t lsw, int64_t msw }   int128_t;
typedef struct _uint128_t_ { uint64_t lsw, msw }   uint128_t;
#      elif IS_BIG_ENDIAN
typedef struct _int128_t_ { uint64_t msw, int64_t lsw }   int128_t;
typedef struct _uint128_t_ { uint64_t msw, lsw }   uint128_t;
#      endif
#   endif
#endif
#if (SUPPORTS_INT256 && IS_NOT_LINTER)
#   define SUPPORTS_OITYPE   1
typedef signed int __attribute__((__mode__(__OI__)))   OItype;
#   define OI   OItype
#   define int_oi_t   OItype
/** 256-bit signed integer datatype (not all systems support int256_t) */
#   define int256_t   OItype
#   define HAVE_OI   1
#   ifndef __int256
#      define __int256   int256_t
#   endif
#   ifndef int256
#      define int256   int256_t
#   endif
#   ifndef __int256_t
#      define __int256_t   int256_t
#   endif
#   ifndef __INT256_TYPE__
#      define __INT256_TYPE__   int256_t
#   endif
#   ifndef INT256_TYPE
#      define INT256_TYPE   int256_t
#   endif
#   define s_int256_t   int256_t
#   define s256int   int256_t
#   define Int256   int256_t
#   define __S256_TYPE   int256_t
#   define S256_TYPE   int256_t
#   define INT256   int256_t
#   define s256_t   int256_t
#   ifndef octa
#      define octa   int256_t
#   endif
#   ifndef octa_t
#      define octa_t   int256_t
#   endif
#   define __int256_t_defined   1
#   define int256_t_defined   1
#   define INT256_T_DEFINED   1
#   define SUPPORTS_UOITYPE   1
typedef unsigned int __attribute__((__mode__(__OI__)))   UOItype;
#   define UOI   UOItype
#   define int_uoi_t   UOItype
#   define uint_oi_t   UOItype
/** 256-bit unsigned integer datatype (not all systems support uint256_t) */
#   define uint256_t   UOItype
#   define U_256   UOItype
#   define HAVE_UOI   1
#   ifndef __uint256
#      define __uint256   uint256_t
#   endif
#   ifndef uint256
#      define uint256   uint256_t
#   endif
#   ifndef __uint256_t
#      define __uint256_t   uint256_t
#   endif
#   ifndef __UINT256_TYPE__
#      define __UINT256_TYPE__   uint256_t
#   endif
#   ifndef UINT256_TYPE
#      define UINT256_TYPE   uint256_t
#   endif
#   define u_int256_t   uint256_t
#   define u256int   uint256_t
#   define UInt256   uint256_t
#   define __U256_TYPE   uint256_t
#   define U256_TYPE   uint256_t
#   define UINT256   uint256_t
#   define u256_t   uint256_t
#   ifndef uocta
#      define uocta   uint256_t
#   endif
#   ifndef uocta_t
#      define uocta_t   uint256_t
#   endif
#   define __uint256_t_defined   1
#   define uint256_t_defined   1
#   define UINT256_T_DEFINED   1
#else
#   define SUPPORTS_OITYPE   0
#   define SUPPORTS_UOITYPE   0
#   define HAVE_OI   0
#   define HAVE_UOI   0
#endif
#if (SUPPORTS_INT512 && IS_NOT_LINTER)
#   define SUPPORTS_XITYPE   1
typedef signed int __attribute__((__mode__(__XI__)))   XItype;
#   define XI   XItype
#   define int_xi_t   XItype
/** 512-bit signed integer datatype (not all systems support int512_t) */
#   define int512_t   XItype
#   define HAVE_XI   1
#   ifndef __int512
#      define __int512   int512_t
#   endif
#   ifndef int512
#      define int512   int512_t
#   endif
#   ifndef __int512_t
#      define __int512_t   int512_t
#   endif
#   ifndef __INT512_TYPE__
#      define __INT512_TYPE__   int512_t
#   endif
#   ifndef INT512_TYPE
#      define INT512_TYPE   int512_t
#   endif
#   define s_int512_t   int512_t
#   define s512int   int512_t
#   define Int512   int512_t
#   define __S512_TYPE   int512_t
#   define S512_TYPE   int512_t
#   define INT512   int512_t
#   define s512_t   int512_t
#   ifndef hexadeca
#      define hexadeca   int512_t
#   endif
#   ifndef hexadeca_t
#      define hexadeca_t   int512_t
#   endif
#   define __int512_t_defined   1
#   define int512_t_defined   1
#   define INT512_T_DEFINED   1
#   define SUPPORTS_UXITYPE   1
typedef unsigned int __attribute__((__mode__(__XI__)))   UXItype;
#   define UXI   UXItype
#   define int_uxi_t   UXItype
#   define uint_xi_t   UXItype
/** 512-bit unsigned integer datatype (not all systems support uint512_t) */
#   define uint512_t   UXItype
#   define U_512   UXItype
#   define HAVE_UXI   1
#   ifndef __uint512
#      define __uint512   uint512_t
#   endif
#   ifndef uint512
#      define uint512   uint512_t
#   endif
#   ifndef __uint512_t
#      define __uint512_t   uint512_t
#   endif
#   ifndef __UINT512_TYPE__
#      define __UINT512_TYPE__   uint512_t
#   endif
#   ifndef UINT512_TYPE
#      define UINT512_TYPE   uint512_t
#   endif
#   define u_int512_t   uint512_t
#   define u512int   uint512_t
#   define UInt512   uint512_t
#   define __U512_TYPE   uint512_t
#   define U512_TYPE   uint512_t
#   define UINT512   uint512_t
#   define u512_t   uint512_t
#   ifndef uhexadeca
#      define uhexadeca   uint512_t
#   endif
#   ifndef uhexadeca_t
#      define uhexadeca_t   uint512_t
#   endif
#   define __uint512_t_defined   1
#   define uint512_t_defined   1
#   define UINT512_T_DEFINED   1
#else
#   define SUPPORTS_XITYPE   0
#   define SUPPORTS_UXITYPE   0
#   define HAVE_XI   0
#   define HAVE_UXI   0
#endif

/** @} */  // }


// FLOAT-POINT MODES

/** @defgroup Float_Point_Modes Datatypes pertaining to float-points
@{ */  // (FB){

#if (SUPPORTS_FLOAT8 && IS_NOT_LINTER)
#   define SUPPORTS_QFTYPE   1
/** 8-bit quarter-precision float-point datatype */
typedef float __attribute__((__mode__(__QF__)))   QFtype;
#   define QF   QFtype
#   define __float8   QFtype
#   define float8   QFtype
#   define float8_t   QFtype
#   define minifloat_t   QFtype
#   define minifloat   QFtype
#   define quarter_float   QFtype
#   define quarter_float_t   QFtype
#   define HAVE_QF   1
#else
#   define SUPPORTS_QFTYPE   0
#   define HAVE_QF   0
#   undef SUPPORTS_FLOAT8
#   define SUPPORTS_FLOAT8   0
#endif
#if (SUPPORTS_FLOAT16 && IS_NOT_LINTER && ((defined(COMPILER_CLANG) && defined(ARCHARM)) || defined(COMPILER_GNU_GCC)))
#   define SUPPORTS_HFTYPE   1
/** 16-bit half-precision float-point datatype */
typedef float __attribute__((__mode__(__HF__)))   HFtype;
#   define HF   HFtype
#   ifndef fp16
#      define fp16   HFtype
#   endif
#   ifndef __fp16
#      define __fp16   HFtype
#   endif
#   ifndef __float16
#      define __float16   fp16
#   endif
#   define float16   fp16
#   define float16_t   fp16
#   define half_float   fp16
#   define half_float_t   fp16
#   define HAVE_HF   1
#else
#   define SUPPORTS_HFTYPE   0
#   define HAVE_HF   0
#   undef SUPPORTS_FLOAT16
#   define SUPPORTS_FLOAT16   0
#endif
#if (SUPPORTS_FLOAT24 && IS_NOT_LINTER)
#   define SUPPORTS_TQFTYPE   1
/** 24-bit three-quarter-precision float-point datatype */
typedef float __attribute__((__mode__(__TQF__)))   TQFtype;
#   define TQF   TQFtype
#   define float24   TQFtype
#   define float24_t   TQFtype
#   define HAVE_TQF   1
#else
#   define SUPPORTS_TQFTYPE   0
#   define HAVE_TQF   0
#   undef SUPPORTS_FLOAT24
#   define SUPPORTS_FLOAT24   0
#endif
#define SUPPORTS_SFTYPE   1
/** Single-precision float-point */
typedef float __attribute__((__mode__(__SF__)))   SFtype;
#define SF   SFtype
/** 32 bit IEEE float: 1 sign bit, 8 exponent bits, 23 fraction bits */
#define Float32   float
/** 32 bit IEEE float: 1 sign bit, 8 exponent bits, 23 fraction bits */
#define float32   float
/** 32 bit IEEE float: 1 sign bit, 8 exponent bits, 23 fraction bits */
#define Float32_t   float
/** 32 bit IEEE float: 1 sign bit, 8 exponent bits, 23 fraction bits */
#define float32_t   float
/** 32 bit IEEE float: 1 sign bit, 8 exponent bits, 23 fraction bits */
#define __float32_t   float
/** 32 bit IEEE float: 1 sign bit, 8 exponent bits, 23 fraction bits */
#define __float32   float
/** 32 bit IEEE float: 1 sign bit, 8 exponent bits, 23 fraction bits */
#define single   float
#define HAVE_SF   1
#define SUPPORTS_DFTYPE   1
#ifdef ARCHAM29K
#   define _FLOAT_RET   double
#else
#   define _FLOAT_RET   float
#endif
/** Double-precision float-point */
typedef float __attribute__((__mode__(__DF__)))   DFtype;
#define DF   DFtype
/** 64 bit IEEE float: 1 sign bit, 11 exponent bits, 52 fraction bits */
#define Float64   double
/** 64 bit IEEE float: 1 sign bit, 11 exponent bits, 52 fraction bits */
#define float64   double
/** 64 bit IEEE float: 1 sign bit, 11 exponent bits, 52 fraction bits */
#define Float64_t   double
/** 64 bit IEEE float: 1 sign bit, 11 exponent bits, 52 fraction bits */
#define float64_t   double
/** 64 bit IEEE float: 1 sign bit, 11 exponent bits, 52 fraction bits */
#define __float64_t   double
/** 64 bit IEEE float: 1 sign bit, 11 exponent bits, 52 fraction bits */
#define __float64   double
#if (defined(ARCHPOWERPC) && defined(__SPE__))
#   define _LONG_DOUBLE   double
#endif
#define HAVE_DF   1
#if (LDBL_EQ_XFtype && IS_NOT_LINTER)
#   define SUPPORTS_XFTYPE   1
typedef float __attribute__((__mode__(__XF__)))   XFtype;
#   define HAVE_XF   1
#else
#   define SUPPORTS_XFTYPE   0
#   define HAVE_XF   0
#endif
#if SUPPORTS_FLOAT80
#   define float80   __float80
#   define float80_t   __float80
#   define extended80   __float80
#endif
#if SUPPORTS_FLOAT96
#   define float96   __float96
#   define float96_t   __float96
#   define extended96   __float96
#endif
#if (SUPPORTS_FLOAT128 && IS_NOT_LINTER)
#   define SUPPORTS_TFTYPE   1
/** Tetra-precision float-point */
typedef float __attribute__((__mode__(__TF__)))   TFtype;
#   define HAVE_TF   1
#   define __float128   TFtype
#   ifndef __float128_t
#      define __float128_t   TFtype
#   endif
#   ifndef float128_t
#      define float128_t   TFtype
#   endif
#   ifndef float128
#      define float128   TFtype
#   endif
#   ifndef tetra
#      define tetra   TFtype
#   endif
#   ifndef tetra_t
#      define tetra_t   TFtype
#   endif
#elif IS_NOT_LINTER
#   define SUPPORTS_TFTYPE   0
typedef struct __float128 { uint8_t x[16] align16; } align16   TFtype;
#   define __float128   TFtype
#   ifndef __float128_t
#      define __float128_t   TFtype
#   endif
#   ifndef float128_t
#      define float128_t   TFtype
#   endif
#   ifndef float128
#      define float128   TFtype
#   endif
#   ifndef tetra
#      define tetra   TFtype
#   endif
#   ifndef tetra_t
#      define tetra_t   TFtype
#   endif
#   define HAVE_TF   0
#else
#   define SUPPORTS_TFTYPE   0
#   define HAVE_TF   0
#endif

/** @} */  // }


// DECIMAL FLOAT-POINT MODES

/** @defgroup Decimal_Float_Point_Modes Datatypes pertaining to decimal float-points
@{ */  // (FB){

#if (SUPPORTS_DECIMAL_FLOATS && IS_NOT_LINTER)
#   define SUPPORTS_SDTYPE   1
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
typedef float __attribute__((__mode__(__SD__)))   SDtype;
#   define SD   SDtype
#   define HAVE_SD   1
#   if IS_NOT_GNUC
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#      define _Decimal32   SDtype
#   endif
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#   define decfloat32   SDtype
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#   define _decfloat32   SDtype
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#   define __decfloat32   SDtype
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#   define decimal32   SDtype
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#   define decimal32_t   SDtype
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#   define Decimal32   SDtype
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#   define DEC32_   SDtype
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#   define dec32   SDtype
#   define SUPPORTS_DDTYPE   1
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
typedef float __attribute__((__mode__(__DD__)))   DDtype;
#   define DD   DDtype
#   define HAVE_DD   1
#   if IS_NOT_GNUC
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#      define _Decimal64   DDtype
#   endif
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#   define decfloat64   DDtype
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#   define _decfloat64   DDtype
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#   define __decfloat64   DDtype
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#   define decimal64   DDtype
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#   define decimal64_t   DDtype
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#   define Decimal64   DDtype
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#   define DEC64_   DDtype
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#   define dec64   DDtype
#else
#   define SUPPORTS_SDTYPE   0
#   define SUPPORTS_DDTYPE   0
#   define HAVE_SD   0
#   define HAVE_DD   0
#endif
#if (SUPPORTS_DECIMAL128 && IS_NOT_LINTER)
#   define SUPPORTS_TDTYPE   1
typedef float __attribute__((__mode__(__TD__)))   TDtype;
#   define TD   TDtype
#   define HAVE_TD   1
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#   define _Decimal128   TDtype
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#   define decfloat128   TDtype
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#   define _decfloat128   TDtype
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#   define __decfloat128   TDtype
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#   define decimal128   TDtype
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#   define decimal128_t   TDtype
#   ifndef Decimal128
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#      define Decimal128   TDtype
#   endif
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#   define DEC128_   TDtype
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#   define dec128   TDtype
#else
#   define SUPPORTS_TDTYPE   0
#   define HAVE_TD   0
#endif

/** @} */  // }


// COMPLEX MODES

/** @defgroup Complex_Float_Point_Modes Datatypes pertaining to complex float-points
@{ */  // (FB){

#if (SUPPORTS_COMPLEX && IS_NOT_LINTER)  // Complex floats
#   if IS_NOT_GNUC
#      define __complex__   _Complex
#   endif
#   ifndef complex
#      define complex   _Complex
#   endif
#   ifndef Complex
#      define Complex   _Complex
#   endif
#   ifndef __imaginary__
#      define __imaginary__   _Imaginary
#   endif
#   ifndef imaginary
#      define imaginary   _Imaginary
#   endif
#   ifndef Imaginary
#      define Imaginary   _Imaginary
#   endif
/** @def _Complex_I
Imaginary unit */
#   ifndef _Complex_I
#      define _Complex_I   (__extension__ (0.0 + 1.0i))
#   endif
/** @def I
Most narrow imaginary unit */
#   ifndef I
#      define I   (__extension__ 1.0i)
#   endif
/** @def __I__
Most narrow imaginary unit */
#   ifndef __I__
#      define __I__   I
#   endif
/** @def _Imaginary_I
Most narrow imaginary unit */
#   ifndef _Imaginary_I
#      define _Imaginary_I   I
#   endif
#   ifndef TO_CMPLX
#      define TO_CMPLX(x, y, t)   (((t) (x) + _Imaginary_I) * (t) (y))
#   endif
#   if IS_NOT_CPLUSPLUS
#      define __CIMAG(x, t)   (+(union __union_complex { _Complex t __z; t __xy[2]; }) {(_Complex t)(x)}.__xy[1])
#   endif
#   ifndef I_FLOAT
#      define I_FLOAT   (__extension__ 1.0Fi)
#      define I_FLOAT_NEG   (__extension__ -1.0Fi)
#      define I_FLOAT_ZERO   (__extension__ 0.0Fi)
#      define I_FLOAT_NEG_ZERO   (__extension__ -0.0Fi)
#   endif
#   define COMPLEX_ZEROf   (__extension__ (0.0Fi + 0.0Fi))
#   define COMPLEX_ONEf   (__extension__ (1.0Fi + 0.0Fi))
/** Expand into expression of specified complex type */
#   define CMPLXF(x, y)   (((float)(x) + I_FLOAT) * (float)(y))
#   define __CMPLXF(x, y)   CMPLXF((x), (y))
#   define CMPLXF_MAX_10   ((1.0E+38F + I_FLOAT) * 1.0E+38F)
#   ifndef I_DOUBLE
#      define I_DOUBLE   (__extension__ 1.0i)
#      define I_DOUBLE_NEG   (__extension__ -1.0i)
#      define I_DOUBLE_ZERO   (__extension__ 0.0i)
#      define I_DOUBLE_NEG_ZERO   (__extension__ -0.0i)
#   endif
#   define COMPLEX_ZERO   (__extension__ (0.0i + 0.0i))
#   define COMPLEX_ONE   (__extension__ (1.0i + 0.0i))
/** Expand into expression of specified complex type */
#   define CMPLX(x, y)   (((double)(x) + I_DOUBLE) * (double)(y))
#   define __CMPLX(x, y)   CMPLX((x), (y))
#   define CMPLX_MAX_10   ((1.0E+38 + I_DOUBLE) * 1.0E+38)
#   if ((!defined(I_LONG_DOUBLE)) && SUPPORTS_LONG_DOUBLE)
#      define I_LONG_DOUBLE   (__extension__ 1.0Li)
#      define I_LONG_DOUBLE_NEG   (__extension__ -1.0Li)
#      define I_LONG_DOUBLE_ZERO   (__extension__ 0.0Li)
#      define I_LONG_DOUBLE_NEG_ZERO   (__extension__ -0.0Li)
#   endif
#   if SUPPORTS_LONG_DOUBLE
#      define COMPLEX_ZEROl   (__extension__ (0.0Li + 0.0Li))
#      define COMPLEX_ONEl   (__extension__ (1.0Li + 0.0Li))
/** Expand into expression of specified complex type */
#      define CMPLXL(x, y)   (((long double)(x) + I_LONG_DOUBLE) * (long double)(y))
/** Expand into expression of specified complex type */
#      define __CMPLXL(x, y)   CMPLXL((x), (y))
#   endif
#   define SUPPORTS_SCTYPE   1
typedef _Complex float __attribute__((__mode__(__SC__)))   SCtype;
#   define SC   SCtype
#   define HAVE_SC   1
#   define _Mfloat_   float
#   define _Mfloat_complex_   SCtype
#   define complex_float   SCtype
#   define cfloat_t   SCtype
#   define SUPPORTS_DCTYPE   1
typedef _Complex float __attribute__((__mode__(__DC__)))   DCtype;
#   define DC   DCtype
#   define HAVE_DC   1
#   define _Mdouble_   double
#   define _Mdouble_complex_   DCtype
#   define complex_double   DCtype
#   define cdouble_t   DCtype
#   if (SUPPORTS_LONG_DOUBLE && SUPPORTS_COMPLEX_LDBL)
#      define SUPPORTS_XCTYPE   1
#      if SUPPORTS_COMPLEX_X87
typedef _Complex long double __attribute__((__mode__(__XC__)))   XCtype;
#         define SUPPORTS_COMPLEX_X87   1
#      else
typedef _Complex long double   XCtype;
#         define SUPPORTS_COMPLEX_X87   0
#      endif
#      define XC   XCtype
#      define HAVE_XC   1
#      define _LONG_DOUBLE   long double
#      define LDOUBLE   long double
#      define _Mlong_double_   long double
#      define _Mlong_double_complex_   XCtype
#      define complex_long_double   XCtype
#      define clong_double_t   XCtype
#      define cldouble_t   XCtype
#   else
#      define SUPPORTS_XCTYPE   0
#      define SUPPORTS_COMPLEX_LDBL   0
#      define SUPPORTS_COMPLEX_X87   0
#      define HAVE_XC   0
#   endif
#   if (SUPPORTS_FLOAT128 && SUPPORTS_COMPLEX_FLOAT128)
#      define SUPPORTS_TCTYPE   1
typedef _Complex float __attribute__((__mode__(__TC__)))   TCtype;
#      define TC   TCtype
#      define HAVE_TC   1
#      define _Mfloat128_   float128
#      define _Mfloat128_complex_   TCtype
#      define complex_float128   TCtype
#      define cfloat128_t   TCtype
#   else
#      define SUPPORTS_TCTYPE   0
#      define HAVE_TC   0
#   endif
#   ifdef ARCHAVR
#      define SUPPORTS_QCTYPE   1
typedef _Complex float __attribute__((__mode__(__QC__)))   QCtype;
#      define QC   QCtype
#      define HAVE_QC   1
#      define SUPPORTS_HCTYPE   1
typedef _Complex float __attribute__((__mode__(__HC__)))   HCtype;
#      define HC   HCtype
#      define HAVE_HC   1
#   else
#      define SUPPORTS_QCTYPE   0
#      define SUPPORTS_HCTYPE   0
#      define HAVE_QC   0
#      define HAVE_HC   0
#   endif
#else
#   define SUPPORTS_QCTYPE   0
#   define SUPPORTS_HCTYPE   0
#   define SUPPORTS_SCTYPE   0
#   define SUPPORTS_DCTYPE   0
#   define SUPPORTS_XCTYPE   0
#   define SUPPORTS_TCTYPE   0
#   define HAVE_QC   0
#   define HAVE_HC   0
#   define HAVE_SC   0
#   define HAVE_DC   0
#   define HAVE_XC   0
#   define HAVE_TC   0
#endif  // SUPPORTS_COMPLEX
#if SUPPORTS_COMPLEX_INT
#   define SUPPORTS_CQITYPE   1
typedef complex_float __attribute__((__mode__(__CQI__)))   CQItype;
#   define CQI   CQItype
#   define HAVE_CQI   1
#   define SUPPORTS_CHITYPE   1
typedef complex_float __attribute__((__mode__(__CHI__)))   CHItype;
#   define CHI   CHItype
#   define HAVE_CHI   1
#   define SUPPORTS_CSITYPE   1
typedef complex_float __attribute__((__mode__(__CSI__)))   CSItype;
#   define CSI   CSItype
#   define HAVE_CSI   1
#   define SUPPORTS_CDITYPE   1
typedef complex_float __attribute__((__mode__(__CDI__)))   CDItype;
#   define CDI   CDItype
#   define HAVE_CDI   1
#   if SUPPORTS_COMPLEX_INT128
#      define SUPPORTS_CTITYPE   1
typedef complex_float __attribute__((__mode__(__CTI__)))   CTItype;
#      define CTI   CTItype
#      define HAVE_CTI   1
#   else
#      define SUPPORTS_CTITYPE   0
#      define HAVE_CTI   0
#   endif
#   if SUPPORTS_COMPLEX_INT256
#      define SUPPORTS_COITYPE   1
typedef complex_float __attribute__((__mode__(__COI__)))   COItype;
#      define COI   COItype
#      define HAVE_COI   1
#   else
#      define SUPPORTS_COITYPE   0
#      define HAVE_COI   0
#   endif
#else
#   define SUPPORTS_CQITYPE   0
#   define SUPPORTS_CHITYPE   0
#   define SUPPORTS_CSITYPE   0
#   define SUPPORTS_CDITYPE   0
#   define SUPPORTS_CTITYPE   0
#   define SUPPORTS_COITYPE   0
#   define HAVE_CQI   0
#   define HAVE_CHI   0
#   define HAVE_CSI   0
#   define HAVE_CDI   0
#   define HAVE_CTI   0
#   define HAVE_COI   0
#endif  // SUPPORTS_COMPLEX_INT

/** @} */  // }


// FIXED-POINT ARITHMETIC MODES

/** @defgroup Fixed_Point_Modes Datatypes pertaining to fixed-point datatypes
@{ */  // (FB){

#if SUPPORTS_STDFIX
#   define accum   _Accum
#   define accum_t   _Accum
#   define Accum_t   _Accum
#   define fract   _Fract
#   define fract_t   _Fract
#   define Fract_t   _Fract
#   define sat   _Sat
typedef signed _Fract __attribute__((__mode__(__QQ__)))   QQtype;
#   define QQ   QQtype
#   define xint_hhr_t   QQtype
#   define fx_hhr_t   QQtype
#   define HAVE_QQ   1
#   define satfx_hhr_t   _Sat QQtype
typedef unsigned _Fract __attribute__((__mode__(__UQQ__)))   UQQtype;
#   define UQQ   UQQtype
#   define xint_uhhr_t   UQQtype
#   define fx_uhhr_t   UQQtype
#   define HAVE_UQQ   1
#   define satfx_uhhr_t   _Sat UQQtype
typedef signed _Fract __attribute__((__mode__(__HQ__)))   HQtype;
#   define HQ   HQtype
#   define xint_hr_t   HQtype
#   define fx_hr_t   HQtype
#   define HAVE_HQ   1
#   define satfx_hr_t   _Sat HQtype
typedef unsigned _Fract __attribute__((__mode__(__UHQ__)))   UHQtype;
#   define UHQ   UHQtype
#   define xint_uhr_t   UHQtype
#   define fx_uhr_t   UHQtype
#   define HAVE_UHQ   1
#   define satfx_uhr_t   _Sat UHQtype
typedef signed _Accum __attribute__((__mode__(__HA__)))   HAtype;
#   define HA   HAtype
#   define xint_hk_t   HAtype
#   define fx_hk_t   HAtype
#   define HAVE_HA   1
typedef unsigned _Accum __attribute__((__mode__(__UHA__)))   UHAtype;
#   define UHA   UHAtype
#   define xint_uhk_t   UHAtype
#   define fx_uhk_t   UHAtype
#   define HAVE_UHA   1
#   if (UNITS_PER_WORD > 1)
typedef signed _Fract __attribute__((__mode__(__SQ__)))   SQtype;
#      define SQ   SQtype
#      define xint_r_t   SQtype
#      define fx_t   SQtype
#      define fx_r_t   SQtype
#      define HAVE_SQ   1
#      define satfx_t   _Sat SQtype
#      define satfx_r_t   _Sat SQtype
typedef unsigned _Fract __attribute__((__mode__(__USQ__)))   USQtype;
#      define USQ   USQtype
#      define xint_ur_t   USQtype
#      define fx_ur_t   USQtype
#      define HAVE_USQ   1
#      define satfx_ur_t   _Sat USQtype
typedef signed _Accum __attribute__((__mode__(__SA__)))   SAtype;
#      define SA   SAtype
#      define xint_k_t   SAtype
#      define fx_k_t   SAtype
#      define HAVE_SA   1
typedef unsigned _Accum __attribute__((__mode__(__USA__)))   USAtype;
#      define USA   USAtype
#      define xint_uk_t   USAtype
#      define fx_uk_t   USAtype
#      define HAVE_USA   1
#      define xint_lr_t   long _Fract
#      define fx_lr_t   long _Fract
#      define xint_ulr_t   unsigned long _Fract
#      define fx_ulr_t   unsigned long _Fract
#      define xint_lk_t   long _Accum
#      define fx_lk_t   long _Accum
#      define xint_ulk_t   unsigned long _Accum
#      define fx_ulk_t   unsigned long _Accum
#   else
#      define HAVE_SQ   0
#      define HAVE_USQ   0
#      define HAVE_SA   0
#      define HAVE_USA   0
#   endif
#   if LLONG_EQ_64BITS
typedef signed _Fract __attribute__((__mode__(__DQ__)))   DQtype;
#      define DQ   DQtype
#      define xint_llr_t   DQtype
#      define fx_llr_t   DQtype
#      define HAVE_DQ   1
#      define satfx_llr_t   _Sat DQtype
typedef unsigned _Fract __attribute__((__mode__(__UDQ__)))   UDQtype;
#      define UDQ   UDQtype
#      define xint_ullr_t   UDQtype
#      define fx_ullr_t   UDQtype
#      define HAVE_UDQ   1
#      define satfx_ullr_t   _Sat UDQtype
typedef signed _Accum __attribute__((__mode__(__DA__)))   DAtype;
#      define DA   DAtype
#      define xint_llk_t   DAtype
#      define fx_llk_t   DAtype
#      define HAVE_DA   1
typedef unsigned _Accum __attribute__((__mode__(__UDA__)))   UDAtype;
#      define UDA   UDAtype
#      define xint_ullk_t   UDAtype
#      define fx_ullk_t   UDAtype
#      define HAVE_UDA   1
#   else
#      define HAVE_DQ   0
#      define HAVE_UDQ   0
#      define HAVE_DA   0
#      define HAVE_UDA   0
#   endif
#   if IS_WORDSIZE_64
typedef signed _Fract __attribute__((__mode__(__TQ__)))   TQtype;
#      define TQ   TQtype
#      define xint_tr_t   TQtype
#      define HAVE_TQ   1
#      define satfx_tr_t   _Sat TQtype
typedef unsigned _Fract __attribute__((__mode__(__UTQ__)))   UTQtype;
#      define UTQ   UTQtype
#      define xint_utr_t   UTQtype
#      define HAVE_UTQ   1
#      define satfx_utr_t   _Sat UTQtype
typedef signed _Accum __attribute__((__mode__(__TA__)))   TAtype;
#      define TA   TAtype
#      define xint_tk_t   TAtype
#      define HAVE_TA   1
typedef unsigned _Accum __attribute__((__mode__(__UTA__)))   UTAtype;
#      define UTA   UTAtype
#      define xint_utk_t   UTAtype
#      define HAVE_UTA   1
#   else
#      define HAVE_TQ   0
#      define HAVE_UTQ   0
#      define HAVE_TA   0
#      define HAVE_UTA   0
#   endif
#   if (defined(TA_MODE) || HAVE_TA)  // Accumulator Modes
#      define FIXED_SIZE   16
#      define INT_C_TYPE   TItype
#      define UINT_C_TYPE   UTItype
#      define HINT_C_TYPE   DItype
#      define HUINT_C_TYPE   UDItype
#      define MODE_NAME   TA
#      define MODE_NAME_S   ta
#      define MODE_UNSIGNED   0
#   elif (defined(DA_MODE) || HAVE_DA)
#      define FIXED_SIZE   8
#      if HAVE_TI
#         define DINT_C_TYPE   TItype
#         define DUINT_C_TYPE   UTItype
#      endif
#      define INT_C_TYPE   DItype
#      define UINT_C_TYPE   UDItype
#      define HINT_C_TYPE   SItype
#      define HUINT_C_TYPE   USItype
#      define MODE_NAME   DA
#      define MODE_NAME_S   da
#      define MODE_UNSIGNED   0
#   elif (defined(SA_MODE) || HAVE_SA)
#      define FIXED_SIZE   4
#      if HAVE_DI
#         define DINT_C_TYPE   DItype
#         define DUINT_C_TYPE   UDItype
#      endif
#      define INT_C_TYPE   SItype
#      define UINT_C_TYPE   USItype
#      define HINT_C_TYPE   HItype
#      define HUINT_C_TYPE   UHItype
#      define MODE_NAME   SA
#      define MODE_NAME_S   sa
#      define MODE_UNSIGNED   0
#   elif (defined(HA_MODE) || HAVE_HA)
#      define FIXED_SIZE   2
#      define DINT_C_TYPE   SItype
#      define DUINT_C_TYPE   USItype
#      define INT_C_TYPE   HItype
#      define UINT_C_TYPE   UHItype
#      define HINT_C_TYPE   QItype
#      define HUINT_C_TYPE   UQItype
#      define MODE_NAME   HA
#      define MODE_NAME_S   ha
#      define MODE_UNSIGNED   0
#   endif  // ACCUMULATOR MODES
#   if (defined(TQ_MODE) || (HAVE_TQ && HAVE_TI))  // Fractional Modes
#      define FIXED_SIZE   16
#      define INT_C_TYPE   TItype
#      define UINT_C_TYPE   UTItype
#      define HINT_C_TYPE   DItype
#      define HUINT_C_TYPE   UDItype
#      define MODE_NAME   TQ
#      define MODE_NAME_S   tq
#      define MODE_UNSIGNED   0
#   elif (defined(DQ_MODE) || HAVE_DQ)
#      define FIXED_SIZE   8
#      if HAVE_TI
#         define DINT_C_TYPE   TItype
#         define DUINT_C_TYPE   UTItype
#      endif
#      define INT_C_TYPE   DItype
#      define UINT_C_TYPE   UDItype
#      define HINT_C_TYPE   SItype
#      define HUINT_C_TYPE   USItype
#      define MODE_NAME   DQ
#      define MODE_NAME_S   dq
#      define MODE_UNSIGNED   0
#   elif (defined(SQ_MODE) || HAVE_SQ)
#      define FIXED_SIZE   4
#      if HAVE_DI
#         define DINT_C_TYPE   DItype
#         define DUINT_C_TYPE   UDItype
#      else
#         define DINT_C_TYPE   SItype
#         define DUINT_C_TYPE   SItype
#      endif
#      define INT_C_TYPE   SItype
#      define UINT_C_TYPE   USItype
#      define HINT_C_TYPE   HItype
#      define HUINT_C_TYPE   UHItype
#      define MODE_NAME   SQ
#      define MODE_NAME_S   sq
#      define MODE_UNSIGNED   0
#   elif (defined(HQ_MODE) || HAVE_HQ)
#      define FIXED_SIZE   2
#      define DINT_C_TYPE   SItype
#      define DUINT_C_TYPE   USItype
#      define INT_C_TYPE   HItype
#      define UINT_C_TYPE   UHItype
#      define HINT_C_TYPE   QItype
#      define HUINT_C_TYPE   UQItype
#      define MODE_NAME   HQ
#      define MODE_NAME_S   hq
#      define MODE_UNSIGNED   0
#   elif (defined(QQ_MODE) || HAVE_QQ)
#      define FIXED_SIZE   1
#      define DINT_C_TYPE   HItype
#      define DUINT_C_TYPE   UHItype
#      define INT_C_TYPE   QItype
#      define UINT_C_TYPE   UQItype
#      define MODE_NAME   QQ
#      define MODE_NAME_S   qq
#      define MODE_UNSIGNED   0
#   endif  // FRACTIONAL MODES
#else
#   define HAVE_QQ   0
#   define HAVE_UQQ   0
#   define HAVE_HQ   0
#   define HAVE_UHQ   0
#   define HAVE_HA   0
#   define HAVE_UHA   0
#   define HAVE_SQ   0
#   define HAVE_USQ   0
#   define HAVE_SA   0
#   define HAVE_USA   0
#   define HAVE_DQ   0
#   define HAVE_UDQ   0
#   define HAVE_DA   0
#   define HAVE_UDA   0
#   define HAVE_TQ   0
#   define HAVE_UTQ   0
#   define HAVE_TA   0
#   define HAVE_UTA   0
#endif  // SUPPORTS_STDFIX

/** @} */  // }


// INTEGER VECTOR MODES

/** @defgroup Integer_Vector_Modes Datatypes pertaining to integer-vectors
@{ */  // (FB){

/** Vector datatype of four single-byte (8-bit) integers */
typedef QItype VECTOR4   V4QItype;
typedef QItype VECTOR4U   V4QItype_u;
#define V4QI   V4QItype
#define __V4QI   V4QItype
#define __v4qi   V4QItype
#define int8x4_t   V4QItype
#define v4i8   V4QItype
#define v4i8_b   V4QItype_u
/** Vector datatype of eight single-byte (8-bit) integers */
typedef QItype VECTOR8   V8QItype;
typedef QItype VECTOR8U   V8QItype_u;
#define V8QI   V8QItype
#define __V8QI   V8QItype
#define __v8qi   V8QItype
#define int8x8_t   V8QItype
#define v8i8   V8QItype
#define v8i8_b   V8QItype_u
/** Vector datatype of sixteen single-byte (8-bit) integers */
typedef QItype VECTOR16   V16QItype;
typedef QItype VECTOR16U   V16QItype_u;
#define V16QI   V16QItype
#define __V16QI   V16QItype
#define __v16qi   V16QItype
#define int8x16_t   V16QItype
#define v16i8   V16QItype
#define v16i8_b   V16QItype_u
/** Vector datatype of thirty-two single-byte (8-bit) integers */
typedef QItype VECTOR32   V32QItype;
typedef QItype VECTOR32U   V32QItype_u;
#define V32QI   V32QItype
#define __V32QI   V32QItype
#define __v32qi   V32QItype
#define int8x32_t   V32QItype
#define v32i8   V32QItype
#define v32i8_b   V32QItype_u
/** Vector datatype of sixty-four single-byte (8-bit) integers */
typedef QItype VECTOR64   V64QItype;
typedef QItype VECTOR64U   V64QItype_u;
#define V64QI   V64QItype
#define __V64QI   V64QItype
#define __v64qi   V64QItype
#define int8x64_t   V64QItype
#define v64i8   V64QItype
#define v64i8_b   V64QItype_u
/** Vector datatype of two int16_t values */
typedef HItype VECTOR4   V2HItype;
typedef HItype VECTOR4U   V2HItype_u;
typedef HItype __attribute__((__aligned__(2), __may_alias__, __vector_size__(4)))   v2i16_h;
#define V2HI   V2HItype
#define __V2HI   V2HItype
#define __v2hi   V2HItype
#define v2i16   V2HItype
#define int16x2_t   V2HItype
/** Vector datatype of four int16_t values */
typedef HItype VECTOR8   V4HItype;
typedef HItype VECTOR8U   V4HItype_u;
typedef HItype __attribute__((__aligned__(2), __may_alias__, __vector_size__(8)))   v4i16_h;
#define V4HI   V4HItype
#define __V4HI   V4HItype
#define __v4hi   V4HItype
#define v4i16   V4HItype
#define int16x4_t   V4HItype
/** Vector datatype of eight int16_t values */
typedef HItype VECTOR16   V8HItype;
typedef HItype VECTOR16U   V8HItype_u;
typedef HItype __attribute__((__aligned__(2), __may_alias__, __vector_size__(16)))   v8i16_h;
#define V8HI   V8HItype
#define __V8HI   V8HItype
#define __v8hi   V8HItype
#define v8i16   V8HItype
#define int16x8_t   V8HItype
/** Vector datatype of sixteen int16_t values */
typedef HItype VECTOR32   V16HItype;
typedef HItype VECTOR32U   V16HItype_u;
typedef HItype __attribute__((__aligned__(2), __may_alias__, __vector_size__(32)))   v16i16_h;
#define V16HI   V16HItype
#define __V16HI   V16HItype
#define __v16hi   V16HItype
#define v16i16   V16HItype
#define int16x16_t   V16HItype
/** Vector datatype of thirty-two int16_t values */
typedef HItype VECTOR64   V32HItype;
typedef HItype VECTOR64U   V32HItype_u;
typedef HItype __attribute__((__aligned__(2), __may_alias__, __vector_size__(64)))   v32i16_h;
#define V32HI   V32HItype
#define __V32HI   V32HItype
#define __v32hi   V32HItype
#define v32i16   V32HItype
#define int16x32_t   V32HItype
/** Vector datatype of two int32_t values */
typedef SItype VECTOR8   V2SItype;
typedef SItype VECTOR8U   V2SItype_u;
typedef SItype __attribute__((__aligned__(4), __may_alias__, __vector_size__(8)))   v2i32_w;
#define V2SI   V2SItype
#define __V2SI   V2SItype
#define __v2si   V2SItype
#define v2i32   V2SItype
#define int32x2_t   V2SItype
/** Vector datatype of four int32_t values */
typedef SItype VECTOR16   V4SItype;
typedef SItype VECTOR16U   V4SItype_u;
typedef SItype __attribute__((__aligned__(4), __may_alias__, __vector_size__(16)))   v4i32_w;
#define V4SI   V4SItype
#define __V4SI   V4SItype
#define __v4si   V4SItype
#define v4i32   V4SItype
#define int32x4_t   V4SItype
/** Vector datatype of eight int32_t values */
typedef SItype VECTOR32   V8SItype;
typedef SItype VECTOR32U   V8SItype_u;
typedef SItype __attribute__((__aligned__(4), __may_alias__, __vector_size__(32)))   v8i32_w;
#define V8SI   V8SItype
#define __V8SI   V8SItype
#define __v8si   V8SItype
#define v8i32   V8SItype
#define int32x8_t   V8SItype
/** Vector datatype of sixteen int32_t values */
typedef SItype VECTOR64   V16SItype;
typedef SItype VECTOR64U   V16SItype_u;
typedef SItype __attribute__((__aligned__(4), __may_alias__, __vector_size__(64)))   v16i32_w;
#define V16SI   V16SItype
#define __V16SI   V16SItype
#define __v16si   V16SItype
#define v16i32   V16SItype
#define int32x16_t   V16SItype
/** Vector datatype of two int64_t values */
typedef DItype VECTOR16   V2DItype;
typedef DItype VECTOR16U   V2DItype_u;
typedef DItype __attribute__((__aligned__(8), __may_alias__, __vector_size__(16)))   v2i64_d;
#define V2DI   V2DItype
#define __V2DI   V2DItype
#define __v2di   V2DItype
#define v2i64   V2DItype
#define int64x2_t   V2DItype
/** Vector datatype of four int64_t values */
typedef DItype VECTOR32   V4DItype;
typedef DItype VECTOR32U   V4DItype_u;
typedef DItype __attribute__((__aligned__(8), __may_alias__, __vector_size__(32)))   v4i64_d;
#define V4DI   V4DItype
#define __V4DI   V4DItype
#define __v4di   V4DItype
#define v4i64   V4DItype
#define int64x4_t   V4DItype
/** Vector datatype of eight int64_t values */
typedef DItype VECTOR64   V8DItype;
typedef DItype VECTOR64U   V8DItype_u;
typedef DItype __attribute__((__aligned__(8), __may_alias__, __vector_size__(64)))   v8i64_d;
#define V8DI   V8DItype
#define __V8DI   V8DItype
#define __v8di   V8DItype
#define v8i64   V8DItype
#define int64x8_t   V8DItype
/** Vector datatype of four uint8_t values */
typedef UQItype VECTOR4   V4UQItype;
typedef UQItype VECTOR4U   V4UQItype_u;
#define V4QU   V4UQItype
#define __V4QU   V4UQItype
#define __v4qu   V4UQItype
#define uint8x4_t   V4UQItype
#define v4u8   V4UQItype
#define v4u8_b   V4UQItype_u
/** Vector datatype of eight uint8_t values */
typedef UQItype VECTOR8   V8UQItype;
typedef UQItype VECTOR8U   V8UQItype_u;
#define V8QU   V8UQItype
#define __V8QU   V8UQItype
#define __v8qu   V8UQItype
#define uint8x8_t   V8UQItype
#define v8u8   V8UQItype
#define v8u8_b   V8UQItype_u
/** Vector datatype of sixteen uint8_t values */
typedef UQItype VECTOR16   V16UQItype;
typedef UQItype VECTOR16U   V16UQItype_u;
#define V16QU   V16UQItype
#define __V16QU   V16UQItype
#define __v16qu   V16UQItype
#define uint8x16_t   V16UQItype
#define v16u8   V16UQItype
#define v16u8_b   V16UQItype_u
/** Vector datatype of thirty-two uint8_t values */
typedef UQItype VECTOR32   V32UQItype;
typedef UQItype VECTOR32U   V32UQItype_u;
#define V32QU   V32UQItype
#define __V32QU   V32UQItype
#define __v32qu   V32UQItype
#define uint8x32_t   V32UQItype
#define v32u8   V32UQItype
#define v32u8_b   V32UQItype_u
/** Vector datatype of sixty-four uint8_t values */
typedef UQItype VECTOR64   V64UQItype;
typedef UQItype VECTOR64U   V64UQItype_u;
#define V64QU   V64UQItype
#define __V64QU   V64UQItype
#define __v64qu   V64UQItype
#define uint8x64_t   V64UQItype
#define v64u8   V64UQItype
#define v64u8_b   V64UQItype_u
/** Vector datatype of two uint16_t values */
typedef UHItype VECTOR4   V2UHItype;
typedef UHItype VECTOR4U   V2UHItype_u;
typedef UHItype __attribute__((__aligned__(2), __may_alias__, __vector_size__(4)))   v2u16_h;
#define V2HU   V2UHItype
#define __V2HU   V2UHItype
#define __v2hu   V2UHItype
#define v2u16   V2UHItype
#define uint16x2_t   V2UHItype
/** Vector datatype of four uint16_t values */
typedef UHItype VECTOR8   V4UHItype;
typedef UHItype VECTOR8U   V4UHItype_u;
typedef UHItype __attribute__((__aligned__(2), __may_alias__, __vector_size__(8)))   v4u16_h;
#define V4HU   V4UHItype
#define __V4HU   V4UHItype
#define __v4hu   V4UHItype
#define v4u16   V4UHItype
#define uint16x4_t   V4UHItype
/** Vector datatype of eight uint16_t values */
typedef UHItype VECTOR16   V8UHItype;
typedef UHItype VECTOR16U   V8UHItype_u;
typedef UHItype __attribute__((__aligned__(2), __may_alias__, __vector_size__(16)))   v8u16_h;
#define V8HU   V8UHItype
#define __V8HU   V8UHItype
#define __v8hu   V8UHItype
#define v8u16   V8UHItype
#define uint16x8_t   V8UHItype
/** Vector datatype of sixteen uint16_t values */
typedef UHItype VECTOR32   V16UHItype;
typedef UHItype VECTOR32U   V16UHItype_u;
typedef UHItype __attribute__((__aligned__(2), __may_alias__, __vector_size__(32)))   v16u16_h;
#define V16HU   V16UHItype
#define __V16HU   V16UHItype
#define __v16hu   V16UHItype
#define v16u16   V16UHItype
#define uint16x16_t   V16UHItype
/** Vector datatype of thirty-two uint16_t values */
typedef UHItype VECTOR64   V32UHItype;
typedef UHItype VECTOR64U   V32UHItype_u;
typedef UHItype __attribute__((__aligned__(2), __may_alias__, __vector_size__(64)))   v32u16_h;
#define V32HU   V32UHItype
#define __V32HU   V32UHItype
#define __v32hu   V32UHItype
#define v32u16   V32UHItype
#define uint16x32_t   V32UHItype
/** Vector datatype of two uint32_t values */
typedef USItype VECTOR8   V2USItype;
typedef USItype VECTOR8U   V2USItype_u;
typedef USItype __attribute__((__aligned__(4), __may_alias__, __vector_size__(8)))   v2u32_w;
#define V2SU   V2USItype
#define __V2SU   V2USItype
#define __v2su   V2USItype
#define v2u32   V2USItype
#define uint32x2_t   V2USItype
/** Vector datatype of four uint32_t values */
typedef USItype VECTOR16   V4USItype;
typedef USItype VECTOR16U   V4USItype_u;
typedef USItype __attribute__((__aligned__(4), __may_alias__, __vector_size__(16)))   v4u32_w;
#define V4SU   V4USItype
#define __V4SU   V4USItype
#define __v4su   V4USItype
#define v4u32   V4USItype
#define uint32x4_t   V4USItype
/** Vector datatype of eight uint32_t values */
typedef USItype VECTOR32   V8USItype;
typedef USItype VECTOR32U   V8USItype_u;
typedef USItype __attribute__((__aligned__(4), __may_alias__, __vector_size__(32)))   v8u32_w;
#define V8SU   V8USItype
#define __V8SU   V8USItype
#define __v8su   V8USItype
#define v8u32   V8USItype
#define uint32x8_t   V8USItype
/** Vector datatype of sixteen uint32_t values */
typedef USItype VECTOR64   V16USItype;
typedef USItype VECTOR64U   V16USItype_u;
typedef USItype __attribute__((__aligned__(4), __may_alias__, __vector_size__(64)))   v16u32_w;
#define V16SU   V16USItype
#define __V16SU   V16USItype
#define __v16su   V16USItype
#define v16u32   V16USItype
#define uint32x16_t   V16USItype
/** Vector datatype of two uint64_t values */
typedef UDItype VECTOR16   V2UDItype;
typedef UDItype VECTOR16U   V2UDItype_u;
typedef UDItype __attribute__((__aligned__(8), __may_alias__, __vector_size__(16)))   v2u64_d;
#define V2DU   V2UDItype
#define __V2DU   V2UDItype
#define __v2du   V2UDItype
#define v2u64   V2UDItype
#define uint64x2_t   V2UDItype
/** Vector datatype of four uint64_t values */
typedef UDItype VECTOR32   V4UDItype;
typedef UDItype VECTOR32U   V4UDItype_u;
typedef UDItype __attribute__((__aligned__(8), __may_alias__, __vector_size__(32)))   v4u64_d;
#define V4DU   V4UDItype
#define __V4DU   V4UDItype
#define __v4du   V4UDItype
#define v4u64   V4UDItype
#define uint64x4_t   V4UDItype
/** Vector datatype of eight uint64_t values */
typedef UDItype VECTOR64   V8UDItype;
typedef UDItype VECTOR64U   V8UDItype_u;
typedef UDItype __attribute__((__aligned__(8), __may_alias__, __vector_size__(64)))   v8u64_d;
#define V8DU   V8UDItype
#define __V8DU   V8UDItype
#define __v8du   V8UDItype
#define v8u64   V8UDItype
#define uint64x8_t   V8UDItype
// Intrinsic Integer Datatypes
typedef UQItype POLY_VECTOR4   poly8x4_t;
typedef UQItype POLY_VECTOR8   poly8x8_t;
typedef UQItype POLY_VECTOR16   poly8x16_t;
typedef UQItype POLY_VECTOR32   poly8x32_t;
typedef UQItype POLY_VECTOR64   poly8x64_t;
typedef UHItype POLY_VECTOR4   poly16x2_t;
typedef UHItype POLY_VECTOR8   poly16x4_t;
typedef UHItype POLY_VECTOR16   poly16x8_t;
typedef UHItype POLY_VECTOR32   poly16x16_t;
typedef UHItype POLY_VECTOR64   poly16x32_t;
typedef USItype POLY_VECTOR8   poly32x2_t;
typedef USItype POLY_VECTOR16   poly32x4_t;
typedef USItype POLY_VECTOR32   poly32x8_t;
typedef USItype POLY_VECTOR64   poly32x16_t;
typedef UDItype POLY_VECTOR16   poly64x2_t;
typedef UDItype POLY_VECTOR32   poly64x4_t;
typedef UDItype POLY_VECTOR64   poly64x8_t;
typedef HItype VECTOR8   __m64bh;
typedef HItype VECTOR8U   __m64bh_u;
typedef HItype VECTOR16   __m128bh;
typedef HItype VECTOR16U   __m128bh_u;
typedef HItype VECTOR32   __m256bh;
typedef HItype VECTOR32U   __m256bh_u;
typedef HItype VECTOR64   __m512bh;
typedef HItype VECTOR64U   __m512bh_u;
typedef DItype VECTOR8   __m64i;
typedef DItype VECTOR8U   __m64i_u;
typedef DItype VECTOR16   __m128i;
typedef DItype VECTOR16U   __m128i_u;
typedef DItype VECTOR32   __m256i;
typedef DItype VECTOR32U   __m256i_u;
typedef DItype VECTOR64   __m512i;
typedef DItype VECTOR64U   __m512i_u;

/** @} */  // }


// FLOAT-POINT VECTOR MODES

/** @defgroup Float_Point_Vector_Modes Datatypes pertaining to float-point vectors
@{ */  // (FB){

/** Vector datatype of two float32 values */
typedef SFtype VECTOR8   V2SFtype;
typedef SFtype VECTOR8U   V2SFtype_u;
typedef SFtype __attribute__((__aligned__(4), __may_alias__, __vector_size__(8)))   v2f32_w;
#define V2SF   V2SFtype
#define __V2SF   V2SFtype
#define __v2sf   V2SFtype
#define float32x2_t   V2SFtype
/** Vector datatype of four float32 values */
typedef SFtype VECTOR16   V4SFtype;
typedef SFtype VECTOR16U   V4SFtype_u;
typedef SFtype __attribute__((__aligned__(4), __may_alias__, __vector_size__(16)))   v4f32_w;
#define V4SF   V4SFtype
#define __V4SF   V4SFtype
#define __v4sf   V4SFtype
#define float32x4_t   V4SFtype
/** Vector datatype of eight float32 values */
typedef SFtype VECTOR32   V8SFtype;
typedef SFtype VECTOR32U   V8SFtype_u;
typedef SFtype __attribute__((__aligned__(4), __may_alias__, __vector_size__(32)))   v8f32_w;
#define V8SF   V8SFtype
#define __V8SF   V8SFtype
#define __v8sf   V8SFtype
#define float32x8_t   V8SFtype
/** Vector datatype of sixteen float32 values */
typedef SFtype VECTOR64   V16SFtype;
typedef SFtype VECTOR64U   V16SFtype_u;
typedef SFtype __attribute__((__aligned__(4), __may_alias__, __vector_size__(64)))   v16f32_w;
#define V16SF   V16SFtype
#define __V16SF   V16SFtype
#define __v16sf   V16SFtype
#define float32x16_t   V16SFtype
/** Vector datatype of two float64 values */
typedef DFtype VECTOR16   V2DFtype;
typedef DFtype VECTOR16U   V2DFtype_u;
typedef DFtype __attribute__((__aligned__(4), __may_alias__, __vector_size__(16)))   v2f64_d;
#define V2DF   V2DFtype
#define __V2DF   V2DFtype
#define __v2df   V2DFtype
#define float64x2_t   V2DFtype
/** Vector datatype of four float64 values */
typedef DFtype VECTOR32   V4DFtype;
typedef DFtype VECTOR32U   V4DFtype_u;
typedef DFtype __attribute__((__aligned__(4), __may_alias__, __vector_size__(32)))   v4f64_d;
#define V4DF   V4DFtype
#define __V4DF   V4DFtype
#define __v4df   V4DFtype
#define float64x4_t   V4DFtype
/** Vector datatype of eight float64 values */
typedef DFtype VECTOR64   V8DFtype;
typedef DFtype VECTOR64U   V8DFtype_u;
typedef DFtype __attribute__((__aligned__(4), __may_alias__, __vector_size__(64)))   v8f64_d;
#define V8DF   V8DFtype
#define __V8DF   V8DFtype
#define __v8df   V8DFtype
#define float64x8_t   V8DFtype
// Intrinsic Float-point Datatypes
typedef SFtype VECTOR8   __m64;
#define __mm_loadl_pi_v2f32   __m64;
#define __mm_storeh_pi_v2f32   __m64;
typedef SFtype VECTOR8U   __m64_u;
typedef SFtype VECTOR16   __m128;
typedef SFtype VECTOR16U   __m128_u;
typedef SFtype VECTOR32   __m256;
typedef SFtype VECTOR32U   __m256_u;
typedef SFtype VECTOR64   __m512;
typedef SFtype VECTOR64U   __m512_u;
typedef DFtype VECTOR8   __m64d;
typedef DFtype VECTOR8U   __m64d_u;
typedef DFtype VECTOR16   __m128d;
typedef DFtype VECTOR16U   __m128d_u;
typedef DFtype VECTOR32   __m256d;
typedef DFtype VECTOR32U   __m256d_u;
typedef DFtype VECTOR64   __m512d;
typedef DFtype VECTOR64U   __m512d_u;

/** @} */  // }


// MISCELLANEOUS MODES

#ifdef ARCHM68K  // BLKtype
#   define SUPPORTS_BLKTYPE   1
#   define SUPPORTS_BLK   1
typedef size_t __attribute__((__mode__(__BLK__)))   BLKtype;
#   define HAVE_BLK   1
#else
#   define SUPPORTS_BLKTYPE   0
#   define SUPPORTS_BLK   0
#   define HAVE_BLK   0
#endif
#if IS_RISC  // CCtype
#   define SUPPORTS_CCTYPE   1
#   define SUPPORTS_CONDITION_CODE   1
typedef int __attribute__((__mode__(__CC__)))   CCtype;
#   define HAVE_CC   1
#else
#   define SUPPORTS_CCTYPE   0
#   define SUPPORTS_CONDITION_CODE   0
#   define HAVE_CC   0
#endif
#define HAVE_BI   0
#define HAVE_VOID   0
#if (defined(ARCHX86_64) && CPU_MPX && defined(COMPILER_GNU_GCC))
#   define SUPPORTS_BND32   0
#   define SUPPORTS_BND64   1
typedef int __attribute__((__mode__(__BND64__)))   BND64type;
#   define HAVE_BND32   0
#   define HAVE_BND64   1
#elif (defined(ARCHX86_32) && CPU_MPX)
#   define SUPPORTS_BND32   1
#   define SUPPORTS_BND64   0
typedef int __attribute__((__mode__(__BND32__)))   BND32type;
#   define HAVE_BND32   1
#   define HAVE_BND64   0
#else
#   define SUPPORTS_BND32   0
#   define SUPPORTS_BND64   0
#   define HAVE_BND32   0
#   define HAVE_BND64   0
#endif


// BASIC DATATYPE MODE MACROS

#define Wtype_MAX   ((Wtype)(((UWtype)1 << (W_TYPE_SIZE - 1)) - 1))
#define Wtype_MIN   (-((Wtype_MAX) - 1))
// Quarter Integer Convertions
/** Convert a QI datatype to UQI */
#define QI2UQI(x)   ((UQItype)(x))
/** Convert a UQI datatype to QI */
#define UQI2QI(x)   ((QItype)(x))
// Half Integer Convertions
/** Convert a HI datatype to UHI */
#define HI2UHI(x)   ((UHItype)(x))
/** Convert a UHI datatype to HI */
#define UHI2HI(x)   ((HItype)(x))
// Single Integer Convertions
/** Convert a SI datatype to USI */
#define SI2USI(x)   ((USItype)(x))
/** Convert a USI datatype to SI */
#define USI2SI(x)   ((SItype)(x))
// Double Integer Convertions
/** Convert a DI datatype to UDI */
#define DI2UDI(x)   ((UDItype)(x))
/** Convert a UDI datatype to DI */
#define UDI2DI(x)   ((DItype)(x))
// Tetra Integer Convertions
#if SUPPORTS_TITYPE
/** Convert a TI datatype to UTI */
#   define TI2UTI(x)   ((UTItype)(x))
/** Convert a UTI datatype to TI */
#   define UTI2TI(x)   ((TItype)(x))
#endif
// Octa Integer Convertions
#if SUPPORTS_OITYPE
/** Convert a OI datatype to UOI */
#   define OI2UOI(x)   ((UOItype)(x))
/** Convert a UOI datatype to OI */
#   define UOI2OI(x)   ((OItype)(x))
#endif
// Hexadeca Integer Convertions
#if SUPPORTS_XITYPE
/** Convert a XI datatype to UXI */
#   define XI2UXI(x)   ((UXItype)(x))
/** Convert a UXI datatype to XI */
#   define UXI2XI(x)   ((XItype)(x))
#endif
// Word Convertions
/** Convert a Wtype datatype to UWtype */
#define W2UW(x)   ((UWtype)(x))
/** Convert a UWtype datatype to Wtype */
#define UW2W(x)   ((Wtype)(x))
// Fract & Accum Convertions
#if SUPPORTS_STDFIX
#   if (HAVE_QQ && HAVE_UQQ)
/** Convert a QQ datatype to UQQ */
#      define QQ2UQQ(x)   ((UQQtype)(x))
/** Convert a UQQ datatype to QQ */
#      define UQQ2QQ(x)   ((QQtype)(x))
#   endif
#   if (HAVE_HQ && HAVE_UHQ)
/** Convert a HQ datatype to UHQ */
#      define HQ2UHQ(x)   ((UHQtype)(x))
/** Convert a UHQ datatype to HQ */
#      define UHQ2HQ(x)   ((HQtype)(x))
#   endif
#   if (HAVE_HA && HAVE_UHA)
/** Convert a HA datatype to UHA */
#      define HA2UHA(x)   ((UHAtype)(x))
/** Convert a UHA datatype to HA */
#      define UHA2HA(x)   ((HAtype)(x))
#   endif
#   if (HAVE_SQ && HAVE_USQ)
/** Convert a SQ datatype to USQ */
#      define SQ2USQ(x)   ((USQtype)(x))
/** Convert a USQ datatype to SQ */
#      define USQ2SQ(x)   ((SQtype)(x))
#   endif
#   if (HAVE_SA && HAVE_USA)
/** Convert a SA datatype to USA */
#      define SA2USA(x)   ((USAtype)(x))
/** Convert a USA datatype to SA */
#      define USA2SA(x)   ((SAtype)(x))
#   endif
#   if (HAVE_DQ && HAVE_UDQ)
/** Convert a DQ datatype to UDQ */
#      define DQ2UDQ(x)   ((UDQtype)(x))
/** Convert a UDQ datatype to DQ */
#      define UDQ2DQ(x)   ((DQtype)(x))
#   endif
#   if (HAVE_DA && HAVE_UDA)
/** Convert a DA datatype to UDA */
#      define DA2UDA(x)   ((UDAtype)(x))
/** Convert a UDA datatype to DA */
#      define UDA2DA(x)   ((DAtype)(x))
#   endif
#   if (HAVE_TQ && HAVE_UTQ)
/** Convert a TQ datatype to UTQ */
#      define TQ2UTQ(x)   ((UTQtype)(x))
/** Convert a UTQ datatype to TQ */
#      define UTQ2TQ(x)   ((TQtype)(x))
#   endif
#   if (HAVE_TA && HAVE_UTA)
/** Convert a TA datatype to UTA */
#      define TA2UTA(x)   ((UTAtype)(x))
/** Convert a UTA datatype to TA */
#      define UTA2TA(x)   ((TAtype)(x))
#   endif
#endif
// Miscellaneous Datatype Mode Macros
/** Cover macro to create a 64-bit integer */
#define MAKEDI(hi, lo)   ((((DItype)(SItype)(hi)) << 32) | ((UDItype)(USItype)(lo)))
#define __BITS4   (W_TYPE_SIZE / 4)
#define __ll_B   ((UWtype)1 << (W_TYPE_SIZE / 2))
#define __ll_lowpart(t)   ((UWtype)(t) & (__ll_B - 1))
#define __ll_highpart(t)   ((UWtype)(t) >> (W_TYPE_SIZE / 2))


// EXACT-WIDTH SIGNED INTEGRAL DATATYPES

/** @defgroup Exact_Width_Signed_Datatypes Signed datatypes with exact widths
@{ */  // (FB){

// 8-bit
#ifndef __int8_t_defined
#   define __int8_t_defined   1
typedef signed char   int8_t;
#endif
#ifndef __INT8_TYPE__
#   define __INT8_TYPE__   int8_t
#endif
#ifndef INT8_TYPE
#   define INT8_TYPE   int8_t
#endif
#define s_int8_t   int8_t
#define __int8_t   int8_t
#define __int8   int8_t
#define s8int   int8_t
#define sint8   int8_t
#define SInt   int8_t
#define SInt8   int8_t
#define __S8_TYPE   int8_t
#define S8_TYPE   int8_t
#define __s8   int8_t
#define INT8   int8_t
#define i8_t   int8_t
// 16-bit
#ifndef __int16_t_defined
#   define __int16_t_defined   1
typedef signed short   int16_t;
#endif
#ifndef __INT16_TYPE__
#   define __INT16_TYPE__   int16_t
#endif
#ifndef INT16_TYPE
#   define INT16_TYPE   int16_t
#endif
#define s_int16_t   int16_t
#define __int16_t   int16_t
#define __int16   int16_t
#define s16int   int16_t
#define sint16   int16_t
#define SInt16   int16_t
#define __S16_TYPE   int16_t
#define S16_TYPE   int16_t
#define __s16   int16_t
#define s16   int16_t
#define INT16   int16_t
#define i16_t   int16_t
// 32-bit
#ifndef __int32_t_defined
#   define __int32_t_defined   1
typedef signed int   int32_t;
#endif
#define integer_t   int32_t
#ifndef __INT32_TYPE__
#   define __INT32_TYPE__   int32_t
#endif
#ifndef INT32_TYPE
#   define INT32_TYPE   int32_t
#endif
#define s_int32_t   int32_t
#define __int32_t   int32_t
#define __int32   int32_t
#define s32int   int32_t
#define sint32   int32_t
#define SInt32   int32_t
#define __S32_TYPE   int32_t
#define S32_TYPE   int32_t
#define __s32   int32_t
#define s32   int32_t
#define INT32   int32_t
#define i32_t   int32_t
// 64-bit
#ifndef __int64_t_defined
#   define __int64_t_defined   1
#   if IS_WORDSIZE_64
typedef signed long   int64_t;
#   elif IS_WORDSIZE_32
typedef signed long long   int64_t;
#   else
#      error   "WORDSIZE is not `64` or `32`!"
#   endif
#endif
#ifndef __INT64_TYPE__
#   define __INT64_TYPE__   int64_t
#endif
#ifndef INT64_TYPE
#   define INT64_TYPE   int64_t
#endif
#define s_int64_t   int64_t
#define __int64_t   int64_t
#define __int64   int64_t
#define s64int   int64_t
#define sint64   int64_t
#define SInt64   int64_t
#define __S64_TYPE   int64_t
#define S64_TYPE   int64_t
#define __s64   int64_t
#define INT64   int64_t
#define i64_t   int64_t

/** @} */  // }


// EXACT-WIDTH UNSIGNED INTEGRAL DATATYPES

/** @defgroup Exact_Width_Unsigned_Datatypes Unsigned datatypes with exact widths
@{ */  // (FB){

// 8-bit
#ifndef __uint8_t_defined
#   define __uint8_t_defined   1
typedef unsigned char   uint8_t;
#endif
#ifndef __UINT8_TYPE__
#   define __UINT8_TYPE__   uint8_t
#endif
#ifndef UINT8_TYPE
#   define UINT8_TYPE   uint8_t
#endif
#define u_int8_t   uint8_t
#define __uint8_t   uint8_t
#define __uint8   uint8_t
#define u8int   uint8_t
#define uint8   uint8_t
#define UInt8   uint8_t
#define __U8_TYPE   uint8_t
#define U8_TYPE   uint8_t
#define __u8   uint8_t
#define UINT8   uint8_t
#define u8_t   uint8_t
#define poly8_t   uint8_t
// 16-bit
#ifndef __uint16_t_defined
#   define __uint16_t_defined   1
typedef unsigned short   uint16_t;
#endif
#ifndef __UINT16_TYPE__
#   define __UINT16_TYPE__   uint16_t
#endif
#ifndef UINT16_TYPE
#   define UINT16_TYPE   uint16_t
#endif
#define u_int16_t   uint16_t
#define __uint16_t   uint16_t
#define __uint16   uint16_t
#define u16int   uint16_t
#define uint16   uint16_t
#define UInt16   uint16_t
#define __U16_TYPE   uint16_t
#define U16_TYPE   uint16_t
#define __u16   uint16_t
#define u16   uint16_t
#define UINT16   uint16_t
#define u16_t   uint16_t
#define __le16   uint16_t
#define __be16   uint16_t
#define __sum16   uint16_t
#define poly16_t   uint16_t
// 32-bit
#ifndef __uint32_t_defined
#   define __uint32_t_defined   1
typedef unsigned int   uint32_t;
#endif
typedef uint32_t   natural_t;
typedef natural_t   mach_msg_type_number_t;
#ifndef __UINT32_TYPE__
#   define __UINT32_TYPE__   uint32_t
#endif
#ifndef UINT32_TYPE
#   define UINT32_TYPE   uint32_t
#endif
#define u_int32_t   uint32_t
#define __uint32_t   uint32_t
#define __uint32   uint32_t
#define u32int   uint32_t
#define p9u32int   uint32_t
#define uint32   uint32_t
#define UInt32   uint32_t
#define __U32_TYPE   uint32_t
#define U32_TYPE   uint32_t
#define __u32   uint32_t
#define u32   uint32_t
#define UINT32   uint32_t
#define u32_t   uint32_t
#define __le32   uint32_t
#define __be32   uint32_t
#define __wsum   uint32_t
#define poly32_t   uint32_t
// 64-bit
#ifndef __uint64_t_defined
#   define __uint64_t_defined   1
#   if IS_WORDSIZE_64
typedef unsigned long   uint64_t;
#   else  // WORDSIZE == 32
typedef unsigned long long   uint64_t;
#   endif
#endif
#ifndef __UINT64_TYPE__
#   define __UINT64_TYPE__   uint64_t
#endif
#ifndef UINT64_TYPE
#   define UINT64_TYPE   uint64_t
#endif
#define u_int64_t   uint64_t
#define __uint64_t   uint64_t
#define __uint64   uint64_t
#define u64int   uint64_t
#define uint64   uint64_t
#define UInt64   uint64_t
#define __U64_TYPE   uint64_t
#define U64_TYPE   uint64_t
#define __u64   uint64_t
#define UINT64   uint64_t
#define u64_t   uint64_t
#define __le64   uint64_t
#define __be64   uint64_t
#define poly64_t   uint64_t
typedef uint64_t   DWORD64;
#define DWORDLONG   DWORD64

/** @} */  // }


// 128-BIT INTEGERS

#if SUPPORTS_INT128
/** Integer type with a minimum of 128 bits */
typedef int128_t   int_least128_t;
#   define __int_least128_t   int_least128_t
#   define __int_least128   int_least128_t
/** Unsigned integer type with a minimum of 128 bits */
typedef uint128_t   uint_least128_t;
#   define __uint_least128_t   uint_least128_t
#   define __uint_least128   uint_least128_t
/** Fastest signed integer with a width of at least 128 bits */
typedef int128_t   int_fast128_t;
#   define __int_fast128_t   int_fast128_t
#   define __int_fast128   int_fast128_t
/** Fastest unsigned integer with a width of at least 128 bits */
typedef uint128_t   uint_fast128_t;
#   define __uint_fast128_t   uint_fast128_t
#   define __uint_fast128   uint_fast128_t
#endif


// 256-BIT INTEGERS

#if SUPPORTS_INT256
/** Integer type with a minimum of 256 bits */
typedef int256_t   int_least256_t;
#   define __int_least256_t   int_least256_t
#   define __int_least256   int_least256_t
/** Unsigned integer type with a minimum of 256 bits */
typedef uint256_t   uint_least256_t;
#   define __uint_least256_t   uint_least256_t
#   define __uint_least256   uint_least256_t
/** Fastest signed integer with a width of at least 256 bits */
typedef int256_t   int_fast256_t;
#   define __int_fast256_t   int_fast256_t
#   define __int_fast256   int_fast256_t
/** Fastest unsigned integer with a width of at least 256 bits */
typedef uint256_t   uint_fast256_t;
#   define __uint_fast256_t   uint_fast256_t
#   define __uint_fast256   uint_fast256_t
#endif


// 512-BIT INTEGERS

#if SUPPORTS_INT512
/** Integer type with a minimum of 512 bits */
typedef int512_t   int_least512_t;
#   define __int_least512_t   int_least512_t
#   define __int_least512   int_least512_t
/** Unsigned integer type with a minimum of 512 bits */
typedef uint512_t   uint_least512_t;
#   define __uint_least512_t   uint_least512_t
#   define __uint_least512   uint_least512_t
/** Fastest signed integer with a width of at least 512 bits */
typedef int512_t   int_fast512_t;
#   define __int_fast512_t   int_fast512_t
#   define __int_fast512   int_fast512_t
/** Fastest unsigned integer with a width of at least 512 bits */
typedef uint512_t   uint_fast512_t;
#   define __uint_fast512_t   uint_fast512_t
#   define __uint_fast512   uint_fast512_t
#endif


// SMALLEST FIXED-WIDTH SIGNED INTEGRAL DATATYPES

#ifdef __INT_LEAST8_TYPE__
/** Integer type with a minimum of 8 bits */
typedef __INT_LEAST8_TYPE__   int_least8_t;
#else
/** Integer type with a minimum of 8 bits */
typedef signed char   int_least8_t;
#   define __INT_LEAST8_TYPE__   int_least8_t
#endif
#ifdef __INT_LEAST16_TYPE__
/** Integer type with a minimum of 16 bits */
typedef __INT_LEAST16_TYPE__   int_least16_t;
#else
/** Integer type with a minimum of 16 bits */
typedef short   int_least16_t;
#   define __INT_LEAST16_TYPE__   int_least16_t
#endif
#ifdef __INT_LEAST32_TYPE__
/** Integer type with a minimum of 32 bits */
typedef __INT_LEAST32_TYPE__   int_least32_t;
#else
/** Integer type with a minimum of 32 bits */
typedef signed int   int_least32_t;
#   define __INT_LEAST32_TYPE__   int_least32_t
#endif
#ifdef __INT_LEAST64_TYPE__
/** Integer type with a minimum of 64 bits */
typedef __INT_LEAST64_TYPE__   int_least64_t;
#elif defined(__COMPILER_INT64__)
#   define __COMPILER_INT64__   int_least64_t
#else
#   if IS_WORDSIZE_64
/** Integer type with a minimum of 64 bits */
typedef long   int_least64_t;
#   else
/** Integer type with a minimum of 64 bits */
typedef long long   int_least64_t;
#   endif
#   define __INT_LEAST64_TYPE__   int_least64_t
#endif
#ifndef INT_LEAST8_TYPE
#   define INT_LEAST8_TYPE   int_least8_t
#endif
#ifndef INT_LEAST16_TYPE
#   define INT_LEAST16_TYPE   int_least16_t
#endif
#ifndef INT_LEAST32_TYPE
#   define INT_LEAST32_TYPE   int_least32_t
#endif
#ifndef INT_LEAST64_TYPE
#   define INT_LEAST64_TYPE   int_least64_t
#endif


// SMALLEST FIXED-WIDTH UNSIGNED INTEGRAL DATATYPES

#ifdef __UINT_LEAST8_TYPE__
/** Unsigned integer type with a minimum of 8 bits */
typedef __UINT_LEAST8_TYPE__   uint_least8_t;
#else
/** Unsigned integer type with a minimum of 8 bits */
typedef unsigned char   uint_least8_t;
#   define __UINT_LEAST8_TYPE__   uint_least8_t
#endif
#ifdef __UINT_LEAST16_TYPE__
/** Unsigned integer type with a minimum of 16 bits */
typedef __UINT_LEAST16_TYPE__   uint_least16_t;
#else
/** Unsigned integer type with a minimum of 16 bits */
typedef unsigned short   uint_least16_t;
#   define __UINT_LEAST16_TYPE__   uint_least16_t
#endif
#ifdef __UINT_LEAST32_TYPE__
/** Unsigned integer type with a minimum of 32 bits */
typedef __UINT_LEAST32_TYPE__   uint_least32_t;
#else
/** Unsigned integer type with a minimum of 32 bits */
typedef unsigned int   uint_least32_t;
#   define __UINT_LEAST32_TYPE__   uint_least32_t
#endif
#ifdef __UINT_LEAST64_TYPE__
/** Unsigned integer type with a minimum of 64 bits */
typedef __UINT_LEAST64_TYPE__   uint_least64_t;
#elif defined(__COMPILER_UINT64__)
#   define __COMPILER_UINT64__   uint_least64_t
#else
#   if IS_WORDSIZE_64
/** Unsigned integer type with a minimum of 64 bits */
typedef unsigned long   uint_least64_t;
#   else
/** Unsigned integer type with a minimum of 64 bits */
typedef unsigned long long   uint_least64_t;
#   endif
#   define __UINT_LEAST64_TYPE__   uint_least64_t
#endif
#ifndef UINT_LEAST8_TYPE
#   define UINT_LEAST8_TYPE   uint_least8_t
#endif
#ifndef UINT_LEAST16_TYPE
#   define UINT_LEAST16_TYPE   uint_least16_t
#endif
#ifndef UINT_LEAST32_TYPE
#   define UINT_LEAST32_TYPE   uint_least32_t
#endif
#ifndef UINT_LEAST64_TYPE
#   define UINT_LEAST64_TYPE   uint_least64_t
#endif


// FAST FIXED-WIDTH SIGNED INTEGRAL DATATYPES

#ifdef __INT_FAST8_TYPE__
/** Fastest signed integer with a width of at least 8 bits */
typedef __INT_FAST8_TYPE__   int_fast8_t;
#else
/** Fastest signed integer with a width of at least 8 bits */
typedef signed char   int_fast8_t;
#   define __INT_FAST8_TYPE__   int_fast8_t
#endif
#ifdef __INT_FAST16_TYPE__
/** Fastest signed integer with a width of at least 16 bits */
typedef __INT_FAST16_TYPE__   int_fast16_t;
#else
#   if IS_WORDSIZE_64
/** Fastest signed integer with a width of at least 16 bits */
typedef long   int_fast16_t;
#   else
/** Fastest signed integer with a width of at least 16 bits */
typedef int   int_fast16_t;
#   endif
#   define __INT_FAST16_TYPE__   int_fast16_t
#endif
#ifdef __INT_FAST32_TYPE__
/** Fastest signed integer with a width of at least 32 bits */
typedef __INT_FAST32_TYPE__   int_fast32_t;
#else
#   if IS_WORDSIZE_64
/** Fastest signed integer with a width of at least 32 bits */
typedef long   int_fast32_t;
#   else
/** Fastest signed integer with a width of at least 32 bits */
typedef int   int_fast32_t;
#   endif
#   define __INT_FAST32_TYPE__   int_fast32_t
#endif
#ifdef __INT_FAST64_TYPE__
/** Fastest signed integer with a width of at least 64 bits */
typedef __INT_FAST64_TYPE__   int_fast64_t;
#else
#   if IS_WORDSIZE_64
/** Fastest signed integer with a width of at least 64 bits */
typedef long   int_fast64_t;
#   else
/** Fastest signed integer with a width of at least 64 bits */
typedef long long   int_fast64_t;
#   endif
#   define __INT_FAST64_TYPE__   int_fast64_t
#endif
#ifndef INT_FAST8_TYPE
#   define INT_FAST8_TYPE   int_fast8_t
#endif
#ifndef INT_FAST16_TYPE
#   define INT_FAST16_TYPE   int_fast16_t
#endif
#ifndef INT_FAST32_TYPE
#   define INT_FAST32_TYPE   int_fast32_t
#endif
#ifndef INT_FAST64_TYPE
#   define INT_FAST64_TYPE   int_fast64_t
#endif


// FAST FIXED-WIDTH UNSIGNED INTEGRAL DATATYPES

#ifdef __UINT_FAST8_TYPE__
/** Fastest unsigned integer with a width of at least 8 bits */
typedef __UINT_FAST8_TYPE__   uint_fast8_t;
#else
/** Fastest unsigned integer with a width of at least 8 bits */
typedef unsigned char   uint_fast8_t;
#   define __UINT_FAST8_TYPE__   uint_fast8_t
#endif
#ifdef __UINT_FAST16_TYPE__
/** Fastest unsigned integer with a width of at least 16 bits */
typedef __UINT_FAST16_TYPE__   uint_fast16_t;
#else
#   if IS_WORDSIZE_64
/** Fastest unsigned integer with a width of at least 16 bits */
typedef unsigned long   uint_fast16_t;
#   else
/** Fastest unsigned integer with a width of at least 16 bits */
typedef unsigned int   uint_fast16_t;
#   endif
#   define __UINT_FAST16_TYPE__   uint_fast16_t
#endif
#ifdef __UINT_FAST32_TYPE__
/** Fastest unsigned integer with a width of at least 32 bits */
typedef __UINT_FAST32_TYPE__   uint_fast32_t;
#else
#   if IS_WORDSIZE_64
/** Fastest unsigned integer with a width of at least 32 bits */
typedef unsigned long   uint_fast32_t;
#   else
/** Fastest unsigned integer with a width of at least 32 bits */
typedef unsigned int   uint_fast32_t;
#   endif
#   define __UINT_FAST32_TYPE__   uint_fast32_t
#endif
#ifdef __UINT_FAST64_TYPE__
/** Fastest unsigned integer with a width of at least 64 bits */
typedef __UINT_FAST64_TYPE__   uint_fast64_t;
#else
#   if IS_WORDSIZE_64
/** Fastest unsigned integer with a width of at least 64 bits */
typedef unsigned long   uint_fast64_t;
#   else
/** Fastest unsigned integer with a width of at least 64 bits */
typedef unsigned long long   uint_fast64_t;
#   endif
#   define __UINT_FAST64_TYPE__   uint_fast64_t
#endif
#ifndef UINT_FAST8_TYPE
#   define UINT_FAST8_TYPE   uint_fast8_t
#endif
#ifndef UINT_FAST16_TYPE
#   define UINT_FAST16_TYPE   uint_fast16_t
#endif
#ifndef UINT_FAST32_TYPE
#   define UINT_FAST32_TYPE   uint_fast32_t
#endif
#ifndef UINT_FAST64_TYPE
#   define UINT_FAST64_TYPE   uint_fast64_t
#endif


// LARGEST EXACT-WIDTH INTEGRAL DATATYPES

#if (defined(__UINTMAX_TYPE__) && defined(__INTMAX_TYPE__))
/** Maximum width integer type */
typedef __INTMAX_TYPE__   intmax_t;
#   define SIZEOF_INTMAX_T   sizeof(intmax_t)
#   define BITS_PER_INTMAX_T   (SIZEOF_INTMAX_T * 8)
/** Maximum width unsigned integer type */
typedef __UINTMAX_TYPE__   uintmax_t;
#   define SIZEOF_UINTMAX_T   SIZEOF_INTMAX_T
#   define BITS_PER_UINTMAX_T   BITS_PER_INTMAX_T
#else
#   if IS_WORDSIZE_64
/** Maximum width integer type */
typedef signed long   intmax_t;
#      define SIZEOF_INTMAX_T   SIZEOF_LONG
#      define BITS_PER_INTMAX_T   BITS_PER_LONG
/** Maximum width unsigned integer type */
typedef unsigned long   uintmax_t;
#      define SIZEOF_UINTMAX_T   SIZEOF_LONG
#      define BITS_PER_UINTMAX_T   BITS_PER_LONG
#   else  // WORDSIZE == 32
/** Maximum width integer type */
typedef signed long long   intmax_t;
#      define SIZEOF_INTMAX_T   SIZEOF_LONG_LONG
#      define BITS_PER_INTMAX_T   BITS_PER_LONG_LONG
/** Maximum width unsigned integer type */
typedef unsigned long long   uintmax_t;
#      define SIZEOF_UINTMAX_T   SIZEOF_LONG_LONG
#      define BITS_PER_UINTMAX_T   BITS_PER_LONG_LONG
#   endif
/** Maximum width integer type */
#   define __INTMAX_TYPE__   intmax_t
/** Maximum width unsigned integer type */
#   define __UINTMAX_TYPE__   uintmax_t
#endif
#ifndef BYTES_PER_INTMAX_T
#   define BYTES_PER_INTMAX_T   SIZEOF_INTMAX_T
#endif
#ifndef BYTES_PER_INTMAX
#   define BYTES_PER_INTMAX   SIZEOF_INTMAX_T
#endif
#ifndef __INTMAX_WIDTH__
#   define __INTMAX_WIDTH__   BITS_PER_INTMAX_T
#endif
#ifndef BYTES_PER_UINTMAX_T
#   define BYTES_PER_UINTMAX_T   SIZEOF_INTMAX_T
#endif
#ifndef BYTES_PER_UINTMAX
#   define BYTES_PER_UINTMAX   SIZEOF_INTMAX_T
#endif
#ifndef __UINTMAX_WIDTH__
#   define __UINTMAX_WIDTH__   BITS_PER_UINTMAX_T
#endif
#ifndef INTMAX_TYPE
#   define INTMAX_TYPE   intmax_t
#endif
#ifndef __intmax_t
#   define __intmax_t   intmax_t
#endif
#ifndef __uintmax_t
#   define __uintmax_t   uintmax_t
#endif


// ADDITIONAL EXACT-WIDTH INTEGRAL DATATYPES

/** @defgroup Additional_Exact_Width_Datatypes Extra datatypes with exact widths
@{ */  // (FB){

#define smallint_type   int
#define smallint   signed int
#define smalluint   unsigned int
#if IS_WORDSIZE_32
#   define __SWORD_TYPE   signed int
#   define __UWORD_TYPE   unsigned int
#   ifndef SIZEOF_UWORD_TYPE
#      define SIZEOF_UWORD_TYPE   SIZEOF_INT
#   endif
#   define __INT_PTR_TYPE   signed int
#   define __UINT_PTR_TYPE   unsigned int
#   define __SLONG32_TYPE   signed long
#   define __ULONG32_TYPE   unsigned long
#   define gawble   uint32_t
#else  // WORDSIZE == 64
#   define __SWORD_TYPE   signed long
#   define __UWORD_TYPE   unsigned long
#   ifndef SIZEOF_UWORD_TYPE
#      define SIZEOF_UWORD_TYPE   SIZEOF_LONG
#   endif
#   define __INT_PTR_TYPE   signed long
#   define __UINT_PTR_TYPE   unsigned long
#   define __SLONG32_TYPE   signed int
#   define __ULONG32_TYPE   unsigned int
#   define gawble   uint64_t
#endif
#define __SLONGWORD_TYPE   signed long
#define __ULONGWORD_TYPE   unsigned long
#define __SWBLK_T_TYPE   signed long
#define _Addr   __UWORD_TYPE
#define _Int64   __UWORD_TYPE
/** Unsigned 8-bit quantity */
typedef uint8_t   Byte;
typedef int8_t   SignedByte;
#define bytes2   unsigned short
#define bytes4   unsigned int
#define bytes8   uint64_t
#define wyde   uint16_t
#define doublet   uint16_t
#define plate   uint16_t
#define playte   uint16_t
#define chome   uint16_t
#define chawne   uint16_t
#define quadlet   uint32_t
#define dinner   uint32_t
#define dynner   uint32_t
#define quadlet   uint32_t
#define octlet   uint64_t
#define __BLKCNT_T_TYPE   __SLONGWORD_TYPE
#define __BLKCNT64_T_TYPE   __SQUAD_TYPE
#define __BLKSIZE_T_TYPE   __SLONGWORD_TYPE
#define _BSD_CLOCK_T_   __SLONGWORD_TYPE
#define _BSD_CLOCKID_T_   __S32_TYPE
#define _BSD_PTRDIFF_T_   __SWORD_TYPE
#define _BSD_TIME_T_   __TIME_T_TYPE
#define _BSD_TIMER_T_   __TIMER_T_TYPE
#define __CLOCK_T_TYPE   __SLONGWORD_TYPE
#define __CLOCKID_T_TYPE   __S32_TYPE
#define __DADDR_T_TYPE   __S32_TYPE
#define __FSBLKCNT_T_TYPE   __ULONGWORD_TYPE
#define __FSBLKCNT64_T_TYPE   __UQUAD_TYPE
#define __FSFILCNT_T_TYPE   __ULONGWORD_TYPE
#define __FSFILCNT64_T_TYPE   __UQUAD_TYPE
/** Filesystem ID Datatype */
#define __FSID_T_TYPE   struct fsid { int32_t __val[2]; }
#define __FSWORD_T_TYPE   __SWORD_TYPE
#define __GID_T_TYPE   __U32_TYPE
#define __ID_T_TYPE   __U32_TYPE
#define __INO_T_TYPE   __ULONGWORD_TYPE
#define __INO64_T_TYPE   __UQUAD_TYPE
#ifndef __INTPTR_TYPE__
#   define __INTPTR_TYPE__   __SWORD_TYPE
#endif
#define __KEY_T_TYPE   __S32_TYPE
#define __OFF_T_TYPE   __SLONGWORD_TYPE
#define __OFF64_T_TYPE   __SQUAD_TYPE
#define __PID_T_TYPE   __S32_TYPE
#ifndef __PTRDIFF_TYPE__
#   define __PTRDIFF_TYPE__   __SWORD_TYPE
#endif
/** Resource limit datatype */
#define __RLIM_T_TYPE   unsigned long long
#define __RLIM64_T_TYPE   __RLIM_T_TYPE
#ifdef __SIG_ATOMIC_TYPE__
/** An integer type which can be accessed as an atomic entity even in the presence of asynchronous interrupts made by signals */
typedef __SIG_ATOMIC_TYPE__   sig_atomic_t;
#else
/** An integer type which can be accessed as an atomic entity even in the presence of asynchronous interrupts made by signals */
typedef int   sig_atomic_t;
/** An integer type which can be accessed as an atomic entity even in the presence of asynchronous interrupts made by signals */
#   define __SIG_ATOMIC_TYPE__   sig_atomic_t
#endif
#define __sig_atomic_t_defined   1
#define __have_sig_atomic_t   1
#define __DEFINED_sig_atomic_t   1
#ifdef ARCHMIPS
#   define SIGSET_WORDS   (128 / BITS_PER_LONG)
#else
#   define SIGSET_WORDS   (64 / BITS_PER_LONG)
#endif
typedef struct __sigset { unsigned long bits[SIGSET_WORDS]; }   sigset_t;
#define SIZEOF_SIGSET_T   (SIGSET_WORDS * SIZEOF_LONG)
#define __DEFINED_sigset_t   1
#define __sigset_t_defined   1
#ifndef __SIZE_T_TYPE
#   define __SIZE_T_TYPE   __UWORD_TYPE
#endif
#ifndef __SIZE_T_TYPE__
#   define __SIZE_T_TYPE__   __UWORD_TYPE
#endif
#ifndef __SIZE_TYPE
#   define __SIZE_TYPE   __UWORD_TYPE
#endif
#ifndef SIZE_TYPE
#   define SIZE_TYPE   __UWORD_TYPE
#endif
#ifndef __SIZE_TYPE__
#   define __SIZE_TYPE__   __UWORD_TYPE
#endif
#ifndef __SSIZE_T_TYPE
#   define __SSIZE_T_TYPE   __SWORD_TYPE
#endif
#ifndef __SSIZE_TYPE
#   define __SSIZE_TYPE   __SWORD_TYPE
#endif
#ifndef SSIZE_TYPE
#   define SSIZE_TYPE   __SWORD_TYPE
#endif
#ifndef __SSIZE_TYPE__
#   define __SSIZE_TYPE__   __SWORD_TYPE
#endif
/** Datatype commonly used for sizes */
typedef __SIZE_T_TYPE__   size_t;
/** Type of a byte count, or error */
typedef __SSIZE_T_TYPE   ssize_t;
#define __SUSECONDS_T_TYPE   __SLONGWORD_TYPE
#ifndef __SYSCALL_SLONG_TYPE
#   define __SYSCALL_SLONG_TYPE   __SLONGWORD_TYPE
#endif
#ifndef __SYSCALL_ULONG_TYPE
#   define __SYSCALL_ULONG_TYPE   __ULONGWORD_TYPE
#endif
/** Signed long type used in system calls */
typedef __SYSCALL_SLONG_TYPE   syscall_slong_t;
#define __syscall_slong_t   syscall_slong_t
/** Unsigned long type used in system calls */
typedef __SYSCALL_ULONG_TYPE   syscall_ulong_t;
#define __syscall_ulong_t   syscall_ulong_t
/** System call argument datatype */
typedef __SLONGWORD_TYPE   syscall_arg_t;
#define __TIME_T_TYPE   __SLONGWORD_TYPE
#define __TIMER_T_TYPE   void*
#define __UID_T_TYPE   __U32_TYPE
#ifndef __UINTPTR_TYPE__
#   define __UINTPTR_TYPE__   __UWORD_TYPE
#endif
#define __USECONDS_T_TYPE   __U32_TYPE
#ifdef ARCHAVR
#   define __SMALL_BITFIELDS
#   define _POINTER_INT   short
#endif

/** @} */  // }


// QUAD

#define __quad_t   int64_t
#define quad_t   int64_t
#define __s_quad_t   int64_t
#define s_quad_t   int64_t
#define _quad_t   int64_t
#define __u_quad_t   uint64_t
#define u_quad_t   uint64_t
#define uquad_t   uint64_t
#define _u_quad_t   uint64_t
#define __SQUAD_TYPE   int64_t
#define __UQUAD_TYPE   uint64_t


// CHARACTER DATATYPES

/** @defgroup Character_Datatypes Datatypes for characters
@{ */  // (FB){

// SIGNED & UNSIGNED CHAR

#define CHAR_T   char
#define __CHAR_T   char
#define CHAR   char
/** ANSI character */
#define ANSICHAR   char
#define schar   signed char
typedef signed char   schar8_t;
#ifndef __s_char_defined
#   define __s_char_defined   (1)
#   define __s_char   signed char
#   define s_char   signed char
#endif
#define uchar   unsigned char
#define uchar_t   unsigned char
#define UCHAR   uchar
#define p9uchar   uchar
#define _utfuchar   uchar
#define utfuchar   uchar
/** ANSI character */
#define ANSIUCHAR   unsigned char
typedef unsigned char   uchar8_t;
#ifndef __u_char_defined
#   define __u_char_defined   (1)
#   define __u_char   unsigned char
#   define u_char   unsigned char
#endif


// CHAR8_T

#ifdef __CHAR8_TYPE__
typedef __CHAR8_TYPE__   char8_t;
#else
typedef char   char8_t;
#   define __CHAR8_TYPE__   char8_t
#endif
#ifndef CHAR8_TYPE
#   define CHAR8_TYPE   __CHAR8_TYPE__
#endif
#ifndef __char8_t
#   define __char8_t   __CHAR8_TYPE__
#endif
/** An 8-bit code value in UTF-8 format; UnicodeScalarValues 0-0x7f are expressed in UTF-8 format using one UTF8Char with the same value; UnicodeScalarValues above 0x7f are expressed in UTF-8 format using 2-4 UTF8Chars, all with values in the range 0x80-0xf4 (UnicodeScalarValues 0x100-0xffff use two or three UTF8Chars, UnicodeScalarValues 0x10000-0x10ffff use four UTF8Chars) */
typedef uchar8_t   UTF8Char;


// CHAR16_T

#ifdef __CHAR16_TYPE__
typedef __CHAR16_TYPE__   char16_t;
#else
typedef unsigned short   char16_t;
#   define __CHAR16_TYPE__   char16_t
#endif
#ifndef CHAR16_TYPE
#   define CHAR16_TYPE   char16_t
#endif
#ifndef __char16_t
#   define __char16_t   char16_t
#endif
typedef signed short   schar16_t;
typedef unsigned short   uchar16_t;
#ifndef __schar16_t
#   define __schar16_t   schar16_t
#endif
#ifndef __s_char16_t
#   define _s_schar16_t   schar16_t
#endif
#ifndef __uchar16_t
#   define __uchar16_t   uchar16_t
#endif
#ifndef _u_char16_t
#   define _u_char16_t   uchar16_t
#endif
/** Alias for "uchar16_t" */
#define utf16   uchar16_t
#define utf16_t   uchar16_t
/** Wide character (as UCS-2) according to ISO/IEC 10646 */
#define ucs2_t   uchar16_t
/** A 16-bit Unicode code value in the default UTF-16 format; UnicodeScalarValues 0x10000-0x10ffff are expressed in UTF-16 format using a pair of UTF16Chars - one in the high surrogate range (0xd800-0xdbff) followed by one in the low surrogate range (0xdc00-0xdfff); All of the characters defined in Unicode versions through 3.0 are in the range 0-0xffff and can be expressed using a single UTF16Char */
typedef uchar16_t   UTF16Char;
#define UniChar   uchar16_t


// CHAR32_T

#ifdef __CHAR32_TYPE__
typedef __CHAR32_TYPE__   char32_t;
#else
typedef unsigned int   char32_t;
#   define __CHAR32_TYPE__   char32_t
#endif
#ifndef CHAR32_TYPE
#   define CHAR32_TYPE   char32_t
#endif
#ifndef __char32_t
#   define __char32_t   char32_t
#endif
typedef signed int   schar32_t;
#define uchar32_t   char32_t
#ifndef __schar32_t
#   define __schar32_t   schar32_t
#endif
#ifndef __s_char32_t
#   define _s_schar32_t   schar32_t
#endif
#ifndef __uchar32_t
#   define __uchar32_t   uchar32_t
#endif
#ifndef _u_char32_t
#   define _u_char32_t   uchar32_t
#endif
/** Alias for "uchar32_t" */
#define utf32   uchar32_t
/** Alias for "uchar32_t" */
#define utf32_t   uchar32_t
/** Wide character (as UCS-4) according to ISO-10646-1 */
#define ucs4_t   char32_t
/** Datatype used to manipulate UTF-8 and UTF-32/UCS-4 characters */
typedef union utf8bytes {
#   if IS_LITTLE_ENDIAN
	struct utf8parts { uint8_t byte1, byte2, byte3, byte4; } bytes;
	struct utf8chars { char byte1, byte2, byte3, byte4; } chars;
#   else
	struct utf8parts { uint8_t byte4, byte3, byte2, byte1; } bytes;
	struct utf8chars { char byte4, byte3, byte2, byte1; } chars;
#   endif
	uint32_t whole;
}   utf8_t;
typedef uint32_t   TextEncoding;
/** A complete Unicode character in UTF-32 format, with values from 0 through 0x10ffff (excluding the surrogate range 0xd800-0xdfff and certain disallowed values) */
typedef uchar32_t   UnicodeScalarValue;
#define UTF32Char   uchar32_t


// CHAR64_T

#ifdef __CHAR64_TYPE__
typedef __CHAR64_TYPE__   char64_t;
#else
typedef uint64_t   char64_t;
#   define __CHAR64_TYPE__   char64_t
#endif
#ifndef CHAR64_TYPE
#   define CHAR64_TYPE   __CHAR64_TYPE__
#endif
#ifndef __char64_t
#   define __char64_t   __CHAR64_TYPE__
#endif
typedef int64_t   schar64_t;
typedef uint64_t   uchar64_t;
#ifndef __schar64_t
#   define __schar64_t   schar64_t
#endif
#ifndef __s_char64_t
#   define _s_schar64_t   schar64_t
#endif
#ifndef __uchar64_t
#   define __uchar64_t   uchar64_t
#endif
#ifndef _u_char64_t
#   define _u_char64_t   uchar64_t
#endif
/** Alias for "uchar64_t" */
#define utf64   uchar64_t


// CHAR128_T

#if SUPPORTS_INT128

#ifdef __CHAR128_TYPE__
typedef __CHAR128_TYPE__   char128_t;
#else
typedef uint128_t   char128_t;
#   define __CHAR128_TYPE__   char128_t
#endif
#ifndef CHAR128_TYPE
#   define CHAR128_TYPE   __CHAR128_TYPE__
#endif
#ifndef __char128_t
#   define __char128_t   __CHAR128_TYPE__
#endif
typedef int128_t   schar128_t;
typedef uint128_t   uchar128_t;
#ifndef __schar128_t
#   define __schar128_t   schar128_t
#endif
#ifndef __s_char128_t
#   define _s_schar128_t   schar128_t
#endif
#ifndef __uchar128_t
#   define __uchar128_t   uchar128_t
#endif
#ifndef _u_char128_t
#   define _u_char128_t   uchar128_t
#endif
/** Alias for "uchar128_t" */
#define utf128   uchar128_t

#endif  // SUPPORTS_INT128

/** @} */  // }


// WIDE-CHARACTER DATATYPES

/** @defgroup Wide_Character_Datatypes Datatypes for wide characters
@{ */  // (FB){


#if (!(defined(__DEFINED_mbstate_t) || defined(_MBSTATE_T)))  // mbstate_t
/** Type that holds the information necessary to maintain the state when converting between sequences of multibyte characters and wide characters */
typedef struct __mbstate_t { unsigned int __opaque1, __opaque2; }   mbstate_t;
#   define _mbstate_t   mbstate_t
#   define _MBSTATE_T   mbstate_t
#   define __DEFINED_mbstate_t
#endif  // mbstate_t
#if (IS_NOT_CPLUSPLUS && (!defined(__DEFINED_wchar_t)))
#   ifdef __WCHAR_TYPE__
typedef __WCHAR_TYPE__   wchar_t;
typedef __WCHAR_TYPE__   gwchar_t;
#   else
typedef int   wchar_t;
typedef int   gwchar_t;
#      define __WCHAR_TYPE__   wchar_t
#   endif  // __WCHAR_TYPE__
#   define __DEFINED_wchar_t   (1)
#   define ____gwchar_t_defined   (1)
#endif  // wchar_t
#if IS_NOT_LINTER
_Static_assert(((SIZEOF_WCHAR_T == sizeof(wchar_t)) && (SIZEOF_WINT_T == SIZEOF_INT)), "Improperly set `wchar_t` datatype!");
#endif
#define WCHAR   wchar_t
/** Unicode character */
#define UNICHAR   wchar_t
#define __gwchar_t   gwchar_t
/** State used by a conversion; 0 denotes the initial state */
typedef unsigned int   state_t;
#ifndef __DEFINED_wint_t  // wint_t
#   ifdef __WINT_TYPE__
typedef __WINT_TYPE__   wint_t;
#   else
typedef unsigned int   wint_t;
#      define __WINT_TYPE__   wint_t
#   endif
#   define __DEFINED_wint_t   (1)
#endif  // wint_t
#if IS_NOT_LINTER
_Static_assert(((SIZEOF_WINT_T == sizeof(wint_t)) && (SIZEOF_WINT_T == SIZEOF_INT)), "Improperly set `wint_t` datatype!");
#endif
#define WINT   wint_t
#ifndef WEOF
/** Constant expression of type `wint_t` whose value does not correspond to any member of the extended character set; End-Of-File */
#   define WEOF   ((wint_t)UINT32_MAX)
#endif
#define weof   WEOF
#define WIDE_EOF   WEOF
#ifndef _WCTRANS_T  // wctype
/** Scalar type that can hold values which represent locale-specific character mappings */
typedef const int32_t*   wctrans_t;
#   define _WCTRANS_T   wctrans_t
#endif
#if ((!defined(__DEFINED_wctype_t)) && (!defined(_WCTYPE_T)))  // wctype
/** Scalar type that can hold values which represent locale-specific character classifications */
typedef enum wctype {
	WC_TYPE_INVALID = 0,
	WC_TYPE_ALNUM,
	WC_TYPE_ALPHA,
	WC_TYPE_BLANK,
	WC_TYPE_CNTRL,
	WC_TYPE_DIGIT,
	WC_TYPE_GRAPH,
	WC_TYPE_LOWER,
	WC_TYPE_PRINT,
	WC_TYPE_PUNCT,
	WC_TYPE_SPACE,
	WC_TYPE_UPPER,
	WC_TYPE_XDIGIT,
	WC_TYPE_MAX
} wctype_t;
#   define _WCTYPE_T   wctype_t
#   define __DEFINED_wctype_t   (1)
#endif


// T-CHARACTER DATATYPES (<tchar.h>)

#if (!(defined(TCHAR_DEFINED) || defined(__TCHAR_DEFINED)))
#   define TCHAR_DEFINED   (1)
#   define __TCHAR_DEFINED   (1)
#   ifdef _UNICODE
#      define TCHAR   wchar_t
#      define TSCHAR   wchar_t
#      define TUCHAR   wchar_t
#      define TXCHAR   wchar_t
#      define PTCHAR   wchar_t*
#      define TBYTE   wchar_t
#      define PTBYTE   wchar_t*
#      define TEOF   WEOF
#      define _TEOF   WEOF
#   else
#      define TCHAR   char
#      define TSCHAR   char
#      define TUCHAR   char
#      define TXCHAR   char
#      define TINT   int32_t
#      define PTCHAR   char*
#      define TBYTE   char
#      define PTBYTE   char*
#      define TEOF   EOF
#      define _TEOF   EOF
#   endif
#   define _TCHAR   TCHAR
#   define _TSCHAR   TSCHAR
#   define _TUCHAR   TUCHAR
#   define _TXCHAR   TXCHAR
#   define _TINT   TINT
#endif
#ifndef NUX_UNICODE
#   ifndef NUX_MBCS
#      define NUX_TCHAR_ROUTINE(ansi, mbcs, unicode)   (ansi)
#   else
#      define NUX_TCHAR_ROUTINE(ansi, mbcs, unicode)   (mbcs)
#   endif
#else
#   define NUX_TCHAR_ROUTINE(ansi, mbcs, unicode)   (unicode)
#endif
#define NUX_UNIX_SYS_HOST_ROOT   TEXT("/")
#define NUX_UNIX_SYS_HOME   TEXT("/home")

/** @} */  // }


// RUNE DATATYPES

/** @defgroup Rune_Datatypes Datatypes for various characters
@{ */  // (FB){

#define _RUNE_T_DECLARED   (1)
typedef uint32_t   RuneType;
#define _RuneType   RuneType
#define _RuneType_t   RuneType
#define RuneType_t   RuneType
typedef uint64_t   runepad_t;
#define __runepad_t   runepad_t
#define _runepad_t   runepad_t
typedef uint32_t   nbrune_t;
#define __nbrune_t   nbrune_t
typedef int   rune_t;
#define __rune_t   rune_t
#define _BSD_RUNE_T_   rune_t
#define RUNE   rune_t
#define Rune   rune_t
/** Cannot represent part of a UTF sequence (<) */
#define Runesync   0x80
/** Rune and UTF sequences are the same (<) */
#define Runeself   0x80
/** Decoding error in UTF */
#define Runeerror   0xfffd
#define xRuneerror   Runeerror
/** 16-bit rune */
#define Runemax   0xffff
/** 21-bit rune */
#define Rune21max   0x10ffff
/** Bits used by runes */
#define Runemask   0x1fffff
/** Alpha */
#define _RUNETYPE_A   0x100U
/** Control */
#define _RUNETYPE_C   0x200U
/** Digit */
#define _RUNETYPE_D   0x400U
/** Graph */
#define _RUNETYPE_G   0x800U
/** Lower */
#define _RUNETYPE_L   0x1000U
/** Punct */
#define _RUNETYPE_P   0x2000U
/** Space */
#define _RUNETYPE_S   0x4000U
/** Upper */
#define _RUNETYPE_U   0x8000U
/** X digit */
#define _RUNETYPE_X   0x10000U
/** Blank */
#define _RUNETYPE_B   0x20000U
/** Print */
#define _RUNETYPE_R   0x40000U
/** Ideogram */
#define _RUNETYPE_I   0x80000U
/** Special */
#define _RUNETYPE_T   0x100000U
/** Phonogram */
#define _RUNETYPE_Q   0x200000U
/** Mask to get screen width data */
#define _RUNETYPE_SWM   0xe0000000U
/** Bits to shift to get width */
#define _RUNETYPE_SWS   30
/** 0 width character */
#define _RUNETYPE_SW0   0x20000000U
/** 1 width character */
#define _RUNETYPE_SW1   0x40000000U
/** 2 width character */
#define _RUNETYPE_SW2   0x80000000U
/** 3 width character */
#define _RUNETYPE_SW3   0xc0000000U
#define CACHED_RUNES   0x100
#define _CACHED_RUNES   0x100
#define CRMASK   0xffffff00
#define _CRMASK   0xffffff00
#define _RUNE_ISCACHED(c)   ((c) >= 0 && ((c) < _CACHED_RUNES))
#define RUNE_ISCACHED(c)   _RUNE_ISCACHED((c))
#define _DEFAULT_INVALID_RUNE   ((rune_t)-3)
#define USE_FPdbleword   1
#define SurrogateMin   0xd800
#define SurrogateMax   0xdfff
#define Bad   Runeerror
#define RuneX(i)   ((1 << ((7 - (i)) + ((i) - 1) * 6)) - 1)
/** Indicates version 0 of RuneLocale */
#define _RUNE_MAGIC_1   "RuneMagi"
/** Indicates version A of RuneLocale */
#define _RUNE_MAGIC_A   "RuneMagA"
/** Rune codeset tag */
#define _RUNE_CODESET   "CODESET="
/** Magic string for dynamic link module; Type should be like "LC_CTYPE" */
#define _RUNE_MODULE_1(type)   "RuneModule10." type
#define _WCTRANS_INDEX_LOWER   0
#define _WCTRANS_INDEX_UPPER   1
#define _WCTRANS_NINDEXES   2
#define _WCTYPE_INDEX_ALNUM   0
#define _WCTYPE_INDEX_ALPHA   1
#define _WCTYPE_INDEX_BLANK   2
#define _WCTYPE_INDEX_CNTRL   3
#define _WCTYPE_INDEX_DIGIT   4
#define _WCTYPE_INDEX_GRAPH   5
#define _WCTYPE_INDEX_LOWER   6
#define _WCTYPE_INDEX_PRINT   7
#define _WCTYPE_INDEX_PUNCT   8
#define _WCTYPE_INDEX_SPACE   9
#define _WCTYPE_INDEX_UPPER   10
#define _WCTYPE_INDEX_XDIGIT   11
#define _WCTYPE_NINDEXES   12

/** Rune file format (Network endian) */
typedef struct _FileRuneEntry {
	int32_t fre_min;  //!< First rune of the range
	int32_t fre_max;  //!< Last rune (inclusive) of the range
	int32_t fre_map;  //!< What first maps to in maps
} _FileRuneEntry;

/** Number of ranges stored */
typedef struct _FileRuneRange { uint32_t frr_nranges; }   _FileRuneRange;

/** The lower 8 bits of runetype[] contain the digit value of the rune */
typedef struct _RuneEntry {
	unsigned long* types;  //!< Array of types in range
	rune_t min;  //!< First rune of the range
	rune_t max;  //!< Last rune (inclusive) of the range
	rune_t map;  //!< First maps in mapping
	rune_t pad0;  //!< Padding
} _RuneEntry;

#define __RuneEntry   _RuneEntry

typedef struct _RuneRange {
	_RuneEntry* ranges;  //!< Pointer to the ranges
	int nranges;  //!< Number of ranges stored
	int pad0;  //!< Padding
} _RuneRange;

#define __RuneRange   _RuneRange

typedef struct _RuneCharClass {
	char __name[14];  //!< CHARCLASS_NAME_MAX = 14
	short pad0;  //!< Padding
	uint32_t __mask;  //!< charclass mask
} _RuneCharClass;

typedef struct _WCTransEntry {
	char* te_name;
	rune_t* te_cached;
	_RuneRange* te_extmap;
} _WCTransEntry;

typedef struct _WCTypeEntry {
	char* te_name;
	RuneType te_mask;
	rune_t pad0;  //!< Padding
} _WCTypeEntry;

struct old_tabs {
	short tolower_tab[257];
	short toupper_tab[257];
	char ctype_tab[257];
	char pad0[3];  //!< Padding
};

typedef struct Fconv {
	char* out;  //!< Pointer to next output
	char* eout;  //!< Pointer to end
	int f1, f2, f3, chr;
} Fconv;

/** @} */  // }


// VOID DATATYPES

/** Void Datatype */
#define Void_t   void
/** Void Datatype */
#define void_t   void
/** Void Datatype */
#define VOID   void
/** Void Pointer Datatype */
typedef void*   void_ptr_t;
/** Void Pointer Volatile Datatype */
typedef volatile void_ptr_t   vvoid_ptr_t;
/** Void Pointer Datatype */
typedef void*   ptr_t;
/** Void Pointer Datatype */
#define __ptr_t   ptr_t
typedef void   DB_ENV;


// END-OF-FILE DATATYPES

/** End-Of-File */
#define EOF   (-1)


// POINTER-RELATED DATATYPES

/** @defgroup Pointer_Datatypes Datatypes for pointers
@{ */  // (FB){

#if (BITS_PER_POINTER == 64)
#   define __sptr   int64_t
#   define __uptr   uint64_t
#elif (BITS_PER_POINTER == 32)
#   define __sptr   int32_t
#   define __uptr   uint32_t
#else
#   error   "Only 32-bit and 64-bit pointers are supported!"
#endif
#define POINTER_SIGNED   __sptr
#define POINTER_UNSIGNED   __uptr
#define FIRMWARE_PTR   uint32_t
#define __ptr32   uint32_t
#define ptr32_t   uint32_t
#define POINTER_32   uint32_t
#define POINTER_32_INT   uint32_t
#define SPOINTER_32   int32_t
#define UPOINTER_32   uint32_t
#define __ptr64   uint64_t
#define ptr64_t   uint64_t
#define POINTER_64   uint64_t
#define POINTER_64_INT   uint64_t
#define SPOINTER_64   int64_t
#define UPOINTER_64   uint64_t
#ifndef PTRDIFF_TYPE
#   define PTRDIFF_TYPE   __PTRDIFF_TYPE__
#endif
#ifndef __PTRDIFF_T_TYPE
#   define __PTRDIFF_T_TYPE   __PTRDIFF_TYPE__
#endif
#ifndef __PTRDIFF_T_TYPE__
#   define __PTRDIFF_T_TYPE__   __PTRDIFF_TYPE__
#endif
#ifndef PTRDIFF_T_TYPE
#   define PTRDIFF_T_TYPE   __PTRDIFF_TYPE__
#endif
typedef __PTRDIFF_TYPE__   ptrdiff_t;
#define __ptrdiff_t   ptrdiff_t
#ifndef __INTPTR_T_TYPE__
#   define __INTPTR_T_TYPE__   __INTPTR_TYPE__
#endif
#ifndef INTPTR_TYPE
#   define INTPTR_TYPE   __INTPTR_TYPE__
#endif
#ifndef __intptr_t_defined
typedef __INTPTR_TYPE__   intptr_t;
#   define __intptr_t   intptr_t
#   define __intptr_t_defined   (1)
#endif
#ifndef UINTPTR_TYPE
#   define UINTPTR_TYPE   __UINTPTR_TYPE__
#endif
#ifndef __uintptr_t_defined
typedef __UINTPTR_TYPE__   uintptr_t;
#   define __uintptr_t   uintptr_t
#   define __uintptr_t   uintptr_t
#   define uintptr   uintptr_t
#   define __uintptr_t_defined   (1)
#endif
#ifndef SIZEOF_UINTPTR_T
#   define SIZEOF_UINTPTR_T   SIZEOF_UWORD_TYPE
#endif
/** Signed integer datatype that can hold a pointer beyond 64KB (from Atmel AVR) */
typedef int32_t   int_farptr_t;
/** Unsigned integer datatype that can hold a pointer beyond 64KB (from Atmel AVR) */
typedef uint32_t   uint_farptr_t;
typedef void*   LPVOID;
#define PVOID   LPVOID
#ifndef _LPCVOID_DEFINED
#   define _LPCVOID_DEFINED   (1)
typedef const void*   LPCVOID;
#endif
#if IS_64
#   define __int3264   int64_t
#   define ADDRESS_TAG_BIT   0x40000000000ULL
typedef int32_t   HALF_PTR;
typedef uint32_t   UHALF_PTR;
typedef int32_t*   PHALF_PTR;
typedef uint32_t*   PUHALF_PTR;
typedef int64_t*   PINT_PTR;
typedef uint64_t*   PUINT_PTR;
typedef int64_t*   PLONG_PTR;
typedef uint64_t*   PULONG_PTR;
typedef int64_t   SHANDLE_PTR;
typedef uint64_t   HANDLE_PTR;
#elif IS_32
#   define __int3264   int32_t
#   define ADDRESS_TAG_BIT   0x80000000UL
typedef int16_t   HALF_PTR;
typedef uint16_t   UHALF_PTR;
typedef int16_t*   PHALF_PTR;
typedef uint16_t*   PUHALF_PTR;
typedef int32_t*   PINT_PTR;
typedef uint32_t*   PUINT_PTR;
typedef long*   PLONG_PTR;
typedef unsigned long*   PULONG_PTR;
typedef int32_t   SHANDLE_PTR;
typedef uint32_t   HANDLE_PTR;
#endif
#define PLONG   PLONG_PTR
/** Character pointer */
typedef char*   PCHAR;
#define PSZ   PCHAR
/** Unsigned character pointer */
typedef unsigned char*   PUCHAR;
#define BYTE   unsigned char
typedef BYTE*   PBYTE;
#define LPBYTE   PBYTE
/** Windows signed pointer datatype */
typedef __INT_PTR_TYPE   INT_PTR;
/** Windows unsigned pointer datatype */
typedef __UINT_PTR_TYPE   UINT_PTR;
/** Windows pointer datatype */
typedef __UINT_PTR_TYPE   LONG_PTR;
#define LONG_PTR_DEFINED   (1)
/** Windows unsigned pointer datatype */
typedef __UINT_PTR_TYPE   ULONG_PTR;
typedef ULONG_PTR*   PDWORD_PTR;
typedef __UINT_PTR_TYPE   KAFFINITY;
typedef KAFFINITY*   PKAFFINITY;
/** Windows pointer datatype */
typedef __UINT_PTR_TYPE   DWORD_PTR;
/** Windows datatype */
typedef __UINT_PTR_TYPE   WPARAM;
/** Windows datatype */
typedef __UINT_PTR_TYPE   LPARAM;
/** Windows datatype */
typedef __UINT_PTR_TYPE   LRESULT;
typedef char*   char_ptr_t;
typedef short*   short_ptr_t;
#define PSHORT   short_ptr_t
typedef int*   int_ptr_t;
#define _Mbstatet   int_ptr_t
#define PINT   int_ptr_t
#define LPINT   int_ptr_t
#define PLONG32   int_ptr_t
#define PINT32   int_ptr_t
typedef long*   long_ptr_t;
#define LPLONG   long_ptr_t
#define PLARGE_INTEGER   long_ptr_t
typedef unsigned char*   uchar_ptr_t;
typedef unsigned short*   ushort_ptr_t;
#define PUSHORT   ushort_ptr_t
#define PUSHORT   ushort_ptr_t
typedef unsigned int*   uint_ptr_t;
#define PUINT   uint_ptr_t
#define LPUINT   uint_ptr_t
#define PULONG32   uint_ptr_t
#define PDWORD32   uint_ptr_t
#define PUINT32   uint_ptr_t
typedef unsigned long*   ulong_ptr_t;
#define PULONG   ulong_ptr_t
typedef quad_t*   quad_ptr_t;
typedef int8_t*   i8_ptr_t;
#define s8_ptr_t   i8_ptr_t
#define PINT8   i8_ptr_t
typedef int16_t*   i16_ptr_t;
#define s16_ptr_t   i16_ptr_t
#define PINT16   i16_ptr_t
typedef int32_t*   s32_ptr_t;
#define i32_ptr_t   s32_ptr_t
typedef int64_t*   PINT64;
#define PLONG64   PINT64
#define s64_ptr_t   PINT64
#define i64_ptr_t   PINT64
typedef uint8_t*   PUINT8;
#define u8_ptr_t   PUINT8
#define ptr8_t   PUINT8
typedef uint16_t*   PUINT16;
#define u16_ptr_t   PUINT16
#define ptr16_t   PUINT16
typedef uint32_t*   u32_ptr_t;
typedef uint64_t*   u64_ptr_t;
#define PDWORD64   u64_ptr_t
#define PUINT64   u64_ptr_t
#define PULONG64   u64_ptr_t
typedef size_t*   PSIZE_T;
/** Windows pointer datatype */
typedef ssize_t*   PSSIZE_T;
typedef float*   float_ptr_t;
#define PFLOAT   float_ptr_t
typedef double*   double_ptr_t;
#define PDOUBLE   double_ptr_t
#define MAXUINT_PTR   (~((UINT_PTR)0))
#define MAXINT_PTR   ((INT_PTR)(MAXUINT_PTR >> 1))
#define MININT_PTR   (~(MAXINT_PTR))
#define MAXULONG_PTR   (~((ULONG_PTR)0))
#define MAXLONG_PTR   ((LONG_PTR)(MAXULONG_PTR >> 1))
#define MINLONG_PTR   (~(MAXLONG_PTR))
#define MAXUHALF_PTR   ((UHALF_PTR)~0)
#define MAXHALF_PTR   ((HALF_PTR)(MAXUHALF_PTR >> 1))
#define MINHALF_PTR   (~MAXHALF_PTR)
#define MAXUINT   ((UINT)~((UINT)0))
#define MAXULONGLONG   ((ULONGLONG)~((ULONGLONG)0))

/** @} */  // }


// DATATYPE DIAGNOSTICS

#if IS_NOT_LINTER
_Static_assert((\
	(sizeof(int8_t) < sizeof(int16_t)) && (sizeof(int16_t) < sizeof(int32_t)) && \
	(sizeof(int32_t) < sizeof(int64_t)) && (sizeof(int64_t) > sizeof(int8_t)) && \
	(sizeof(int32_t) == sizeof(uint32_t)) && (sizeof(int64_t) >= sizeof(size_t)) && \
	(sizeof(size_t) == sizeof(ssize_t)) && (sizeof(int) == sizeof(uint32_t)) && \
	(SIZEOF_INT == sizeof(int32_t)) && (SIZEOF_LONG_LONG == sizeof(uint64_t)) \
	), \
	"Fixed-width integer datatypes have invalid sizes!" \
);
#   if SUPPORTS_DECIMAL_FLOATS
_Static_assert(((SIZEOF_DECIMAL32 == sizeof(decimal32)) && (SIZEOF_DECIMAL32 == 4) && (SIZEOF_DECIMAL32 == SIZEOF_FLOAT)), "Improperly set `decimal32` datatype size!");
_Static_assert(((SIZEOF_DECIMAL64 == sizeof(decimal64)) && (SIZEOF_DECIMAL64 == 8) && (SIZEOF_DECIMAL64 == SIZEOF_DOUBLE)), "Improperly set `decimal64` datatype size!");
#   endif
#endif


#endif  // BASIC_DATATYPES_H


/* KERNEL DATATYPES */


#if (!(defined(BITS_KERNEL_TYPES_H) || defined(_BITS_KERNEL_TYPES_H) || defined(_BITS_KERNEL_TYPES_H_)))
#define BITS_KERNEL_TYPES_H   (1)
#define _BITS_KERNEL_TYPES_H   (1)
#define _BITS_KERNEL_TYPES_H_   (1)


#if (defined(ARCHALPHA) && (!(defined(ALPHA_POSIX_TYPES_H) || defined(_ALPHA_POSIX_TYPES_H) || defined(_ALPHA_POSIX_TYPES_H_))))
#define ALPHA_POSIX_TYPES_H   (1)
#define _ALPHA_POSIX_TYPES_H   (1)
#define _ALPHA_POSIX_TYPES_H_   (1)


typedef unsigned int   __kernel_dev_t;
typedef unsigned int   __kernel_ino_t;
typedef unsigned int   __kernel_mode_t;
typedef unsigned int   __kernel_nlink_t;
typedef long   __kernel_off_t;
typedef long   __kernel_loff_t;
typedef int   __kernel_pid_t;
typedef int   __kernel_ipc_pid_t;
typedef unsigned int   __kernel_uid_t;
typedef unsigned int   __kernel_gid_t;
typedef unsigned long   __kernel_size_t;
typedef long   __kernel_ssize_t;
typedef long   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_daddr_t;
typedef char*   __kernel_caddr_t;
typedef unsigned long   __kernel_sigset_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef __kernel_uid_t   __kernel_old_uid_t;
typedef __kernel_gid_t   __kernel_old_gid_t;
typedef __kernel_uid_t   __kernel_uid32_t;
typedef __kernel_gid_t   __kernel_gid32_t;
typedef __kernel_dev_t   __kernel_old_dev_t;
typedef struct kernel_fsid { int val[2]; }   __kernel_fsid_t;


#elif (defined(ARCHARM) && (!(defined(_ARCH_ARM_POSIX_TYPES_H) || defined(_ARCH_ARM_POSIX_TYPES_H_) || defined(__ARCH_ARM_POSIX_TYPES_H))))
#define _ARCH_ARM_POSIX_TYPES_H   (1)
#define _ARCH_ARM_POSIX_TYPES_H_   (1)
#define __ARCH_ARM_POSIX_TYPES_H   (1)


typedef unsigned short   __kernel_dev_t;
typedef unsigned long   __kernel_ino_t;
typedef unsigned short   __kernel_mode_t;
typedef unsigned short   __kernel_nlink_t;
typedef long   __kernel_off_t;
typedef int   __kernel_pid_t;
typedef unsigned short   __kernel_ipc_pid_t;
typedef unsigned short   __kernel_uid_t;
typedef unsigned short   __kernel_gid_t;
typedef unsigned int   __kernel_size_t;
typedef int   __kernel_ssize_t;
typedef int   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_daddr_t;
typedef char*   __kernel_caddr_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef unsigned int   __kernel_uid32_t;
typedef unsigned int   __kernel_gid32_t;
typedef unsigned short   __kernel_old_uid_t;
typedef unsigned short   __kernel_old_gid_t;
typedef long long   __kernel_loff_t;
typedef __kernel_dev_t   __kernel_old_dev_t;
typedef struct kernel_fsid { int __val[2]; }   __kernel_fsid_t;


#elif (defined(ARCHBLACKFIN) && (!(defined(__ARCH_BFIN_POSIX_TYPES_H) || defined(_ARCH_BFIN_POSIX_TYPES_H) || defined(_ARCH_BFIN_POSIX_TYPES_H_))))
#define __ARCH_BFIN_POSIX_TYPES_H   (1)
#define _ARCH_BFIN_POSIX_TYPES_H   (1)
#define _ARCH_BFIN_POSIX_TYPES_H_   (1)


typedef unsigned short   __kernel_dev_t;
typedef unsigned long   __kernel_ino_t;
typedef unsigned short   __kernel_mode_t;
typedef unsigned short   __kernel_nlink_t;
typedef long   __kernel_off_t;
typedef int   __kernel_pid_t;
typedef unsigned int   __kernel_ipc_pid_t;
typedef unsigned int   __kernel_uid_t;
typedef unsigned int   __kernel_gid_t;
typedef unsigned int   __kernel_size_t;
typedef int   __kernel_ssize_t;
typedef int   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_daddr_t;
typedef char*   __kernel_caddr_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef unsigned int   __kernel_uid32_t;
typedef unsigned int   __kernel_gid32_t;
typedef unsigned short   __kernel_old_uid_t;
typedef unsigned short   __kernel_old_gid_t;
typedef long long   __kernel_loff_t;
typedef __kernel_dev_t   __kernel_old_dev_t;
typedef struct kernel_fsid { int __val[2]; }   __kernel_fsid_t;


#elif (defined(ARCHPARISC) && (!(defined(_ARCH_PARISC_POSIX_TYPES_H) || defined(_ARCH_PARISC_POSIX_TYPES_H_) || defined(__ARCH_PARISC_POSIX_TYPES_H))))
#define _ARCH_PARISC_POSIX_TYPES_H   (1)
#define _ARCH_PARISC_POSIX_TYPES_H_   (1)
#define __ARCH_PARISC_POSIX_TYPES_H   (1)


typedef unsigned long   __kernel_dev_t;
typedef unsigned long   __kernel_ino_t;
typedef unsigned short   __kernel_mode_t;
typedef unsigned short   __kernel_nlink_t;
typedef long   __kernel_off_t;
typedef int   __kernel_pid_t;
typedef unsigned short   __kernel_ipc_pid_t;
typedef unsigned int   __kernel_uid_t;
typedef unsigned int   __kernel_gid_t;
typedef int   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_timer_t;
typedef int   __kernel_clockid_t;
typedef int   __kernel_daddr_t;
#   ifdef DATAMODEL_LP64
typedef unsigned long   __kernel_size_t;
typedef long   __kernel_ssize_t;
typedef long   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
#   else
typedef unsigned int   __kernel_size_t;
typedef int   __kernel_ssize_t;
typedef int   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
#   endif
typedef char*   __kernel_caddr_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef unsigned int   __kernel_uid32_t;
typedef unsigned int   __kernel_gid32_t;
typedef long long   __kernel_loff_t;
typedef long long   __kernel_off64_t;
typedef unsigned long long   __kernel_ino64_t;
typedef unsigned int   __kernel_old_dev_t;
typedef __kernel_uid_t   __kernel_old_uid_t;
typedef __kernel_gid_t   __kernel_old_gid_t;
typedef struct kernel_fsid { int __val[2]; }   __kernel_fsid_t;


#elif (defined(ARCHPOWERPC) && (!(defined(_PPC_POSIX_TYPES_H) || defined(_PPC64_POSIX_TYPES_H) || defined(_ASM_POWERPC_POSIX_TYPES_H) || defined(__ASM_POWERPC_POSIX_TYPES_H))))
#define _PPC_POSIX_TYPES_H   (1)
#define _PPC64_POSIX_TYPES_H   (1)
#define _ASM_POWERPC_POSIX_TYPES_H   (1)
#define __ASM_POWERPC_POSIX_TYPES_H   (1)


#   if IS_WORDSIZE_64
typedef unsigned int   __kernel_dev_t;
typedef unsigned int   __kernel_ino_t;
typedef unsigned int   __kernel_nlink_t;
typedef unsigned int   __kernel_mode_t;
typedef long   __kernel_off_t;
typedef long long   __kernel_loff_t;
typedef int   __kernel_pid_t;
typedef int   __kernel_ipc_pid_t;
typedef unsigned int   __kernel_uid_t;
typedef unsigned int   __kernel_gid_t;
typedef unsigned long   __kernel_size_t;
typedef long   __kernel_ssize_t;
typedef long   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_daddr_t;
typedef char*   __kernel_caddr_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef unsigned int   __kernel_uid32_t;
typedef unsigned int   __kernel_gid32_t;
typedef unsigned int   __kernel_old_uid_t;
typedef unsigned int   __kernel_old_gid_t;
typedef __kernel_dev_t   __kernel_old_dev_t;
#   else
typedef unsigned int   __kernel_dev_t;
typedef unsigned int   __kernel_ino_t;
typedef unsigned int   __kernel_mode_t;
typedef unsigned short   __kernel_nlink_t;
typedef long   __kernel_off_t;
typedef int   __kernel_pid_t;
typedef unsigned int   __kernel_uid_t;
typedef unsigned int   __kernel_gid_t;
typedef unsigned int   __kernel_size_t;
typedef int   __kernel_ssize_t;
typedef long   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_daddr_t;
typedef char*   __kernel_caddr_t;
typedef short   __kernel_ipc_pid_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef unsigned int   __kernel_uid32_t;
typedef unsigned int   __kernel_gid32_t;
typedef unsigned int   __kernel_old_uid_t;
typedef unsigned int   __kernel_old_gid_t;
typedef __kernel_dev_t   __kernel_old_dev_t;
typedef long long   __kernel_loff_t;
#   endif
typedef struct kernel_fsid { int val[2]; }   __kernel_fsid_t;


#elif (defined(ARCHITANIUM) && (!(defined(_ASM_IA64_POSIX_TYPES_H) || defined(_ASM_IA64_POSIX_TYPES_H_))))
#define _ASM_IA64_POSIX_TYPES_H   (1)
#define _ASM_IA64_POSIX_TYPES_H_   (1)


typedef unsigned long   __kernel_ino_t;
typedef unsigned int   __kernel_mode_t;
typedef unsigned int   __kernel_nlink_t;
typedef long   __kernel_off_t;
typedef long long   __kernel_loff_t;
typedef int   __kernel_pid_t;
typedef int   __kernel_ipc_pid_t;
typedef unsigned int   __kernel_uid_t;
typedef unsigned int   __kernel_gid_t;
typedef unsigned long   __kernel_size_t;
typedef long   __kernel_ssize_t;
typedef long   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_timer_t;
typedef int   __kernel_clockid_t;
typedef int   __kernel_daddr_t;
typedef char*   __kernel_caddr_t;
typedef unsigned long   __kernel_sigset_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef __kernel_uid_t   __kernel_old_uid_t;
typedef __kernel_gid_t   __kernel_old_gid_t;
typedef __kernel_uid_t   __kernel_uid32_t;
typedef __kernel_gid_t   __kernel_gid32_t;
typedef unsigned int   __kernel_dev_t;
typedef unsigned int   __kernel_old_dev_t;
typedef struct kernel_fsid { int val[2]; }   __kernel_fsid_t;


#elif (defined(ARCHM68K) && (!(defined(_ARCH_M68K_POSIX_TYPES_H) || defined(_ARCH_M68K_POSIX_TYPES_H_) || defined(__ARCH_M68K_POSIX_TYPES_H))))
#define _ARCH_M68K_POSIX_TYPES_H   (1)
#define _ARCH_M68K_POSIX_TYPES_H_   (1)
#define __ARCH_M68K_POSIX_TYPES_H   (1)


typedef unsigned short   __kernel_dev_t;
typedef unsigned long   __kernel_ino_t;
typedef unsigned short   __kernel_mode_t;
typedef unsigned short   __kernel_nlink_t;
typedef long   __kernel_off_t;
typedef int   __kernel_pid_t;
typedef unsigned short   __kernel_ipc_pid_t;
typedef unsigned short   __kernel_uid_t;
typedef unsigned short   __kernel_gid_t;
typedef unsigned int   __kernel_size_t;
typedef int   __kernel_ssize_t;
typedef int   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_daddr_t;
typedef char*   __kernel_caddr_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef unsigned int   __kernel_uid32_t;
typedef unsigned int   __kernel_gid32_t;
typedef unsigned short   __kernel_old_uid_t;
typedef unsigned short   __kernel_old_gid_t;
typedef long long   __kernel_loff_t;
typedef __kernel_dev_t   __kernel_old_dev_t;
typedef struct __kernel_fsid {
#   ifdef __USE_ALL
	int val[2];
#   else
	int __val[2];
#   endif
} __kernel_fsid_t;


#elif (defined(ARCHMICROBLAZE) && (!(defined(_ASM_MICROBLAZE_POSIX_TYPES_H) || defined(_ASM_MICROBLAZE_POSIX_TYPES_H) || defined(__ASM_MICROBLAZE_POSIX_TYPES_H))))
#define _ASM_MICROBLAZE_POSIX_TYPES_H   (1)
#define _ASM_MICROBLAZE_POSIX_TYPES_H_   (1)
#define __ASM_MICROBLAZE_POSIX_TYPES_H   (1)


typedef unsigned long   __kernel_dev_t;
typedef unsigned long   __kernel_ino_t;
typedef unsigned short   __kernel_mode_t;
typedef unsigned long   __kernel_nlink_t;
typedef long   __kernel_off_t;
typedef int   __kernel_pid_t;
typedef int   __kernel_ipc_pid_t;
typedef unsigned int   __kernel_uid_t;
typedef unsigned int   __kernel_gid_t;
typedef unsigned int   __kernel_size_t;
typedef int   __kernel_ssize_t;
typedef int   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_timer_t;
typedef int   __kernel_clockid_t;
typedef int   __kernel_daddr_t;
typedef char*   __kernel_caddr_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef unsigned int   __kernel_uid32_t;
typedef unsigned int   __kernel_gid32_t;
typedef unsigned int   __kernel_old_uid_t;
typedef unsigned int   __kernel_old_gid_t;
typedef unsigned int   __kernel_old_dev_t;
typedef long long   __kernel_loff_t;
typedef struct kernel_fsid { int __val[2]; }   __kernel_fsid_t;


#elif (defined(ARCHSPARC) && (!(defined(__ARCH_SPARC_POSIX_TYPES_H) || defined(__ARCH_SPARC64_POSIX_TYPES_H) || defined(__SPARC_POSIX_TYPES_H))))
#define __ARCH_SPARC_POSIX_TYPES_H   (1)
#define _ARCH_SPARC_POSIX_TYPES_H   (1)
#define __ARCH_SPARC64_POSIX_TYPES_H   (1)
#define _ARCH_SPARC64_POSIX_TYPES_H   (1)
#define __SPARC_POSIX_TYPES_H   (1)
#define _SPARC_POSIX_TYPES_H   (1)


#   if IS_WORDSIZE_64
typedef unsigned long   __kernel_size_t;
typedef long   __kernel_ssize_t;
typedef long   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_pid_t;
typedef int   __kernel_ipc_pid_t;
typedef unsigned int   __kernel_uid_t;
typedef unsigned int   __kernel_gid_t;
typedef unsigned int   __kernel_dev_t;
typedef unsigned long   __kernel_ino_t;
typedef unsigned int   __kernel_mode_t;
typedef unsigned short   __kernel_umode_t;
typedef unsigned int   __kernel_nlink_t;
typedef int   __kernel_daddr_t;
typedef long   __kernel_off_t;
typedef char*   __kernel_caddr_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef __kernel_uid_t   __kernel_old_uid_t;
typedef __kernel_gid_t   __kernel_old_gid_t;
typedef __kernel_dev_t   __kernel_old_dev_t;
typedef __kernel_uid_t   __kernel_uid32_t;
typedef __kernel_gid_t   __kernel_gid32_t;
typedef int   __kernel_suseconds_t;
typedef long long   __kernel_loff_t;
#   else
typedef unsigned int   __kernel_size_t;
typedef int   __kernel_ssize_t;
typedef long   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_pid_t;
typedef unsigned short   __kernel_ipc_pid_t;
typedef unsigned short   __kernel_uid_t;
typedef unsigned short   __kernel_gid_t;
typedef unsigned short   __kernel_dev_t;
typedef unsigned long   __kernel_ino_t;
typedef unsigned short   __kernel_mode_t;
typedef unsigned short   __kernel_umode_t;
typedef short   __kernel_nlink_t;
typedef long   __kernel_daddr_t;
typedef long   __kernel_off_t;
typedef char*   __kernel_caddr_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef unsigned int   __kernel_uid32_t;
typedef unsigned int   __kernel_gid32_t;
typedef unsigned short   __kernel_old_uid_t;
typedef unsigned short   __kernel_old_gid_t;
typedef __kernel_dev_t   __kernel_old_dev_t;
typedef long long   __kernel_loff_t;
#   endif
typedef struct __kernel_fsid {
#   ifdef __USE_ALL
	int val[2];
#   else
	int __val[2];
#   endif
} __kernel_fsid_t;


#elif (defined(ARCHSUPERH64) && (!(defined(_ASM_SH64_POSIX_TYPES_H) || defined(_ASM_SH64_POSIX_TYPES_H_) || defined(__ASM_SH64_POSIX_TYPES_H))))
#define _ASM_SH64_POSIX_TYPES_H   (1)
#define _ASM_SH64_POSIX_TYPES_H_   (1)
#define __ASM_SH64_POSIX_TYPES_H   (1)


typedef unsigned short   __kernel_dev_t;
typedef unsigned long   __kernel_ino_t;
typedef unsigned short   __kernel_mode_t;
typedef unsigned short   __kernel_nlink_t;
typedef long   __kernel_off_t;
typedef int   __kernel_pid_t;
typedef unsigned short   __kernel_ipc_pid_t;
typedef unsigned short   __kernel_uid_t;
typedef unsigned short   __kernel_gid_t;
typedef long unsigned int   __kernel_size_t;
typedef int   __kernel_ssize_t;
typedef int   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_daddr_t;
typedef char*   __kernel_caddr_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef unsigned int   __kernel_uid32_t;
typedef unsigned int   __kernel_gid32_t;
typedef unsigned short   __kernel_old_uid_t;
typedef unsigned short   __kernel_old_gid_t;
typedef __kernel_dev_t   __kernel_old_dev_t;
typedef long long   __kernel_loff_t;
typedef struct __kernel_fsid {
#   ifdef __USE_ALL
	int val[2];
#   else
	int __val[2];
#   endif
} __kernel_fsid_t;


#elif (defined(ARCHSUPERH) && (!(defined(__ASM_SH_POSIX_TYPES_H) || defined(__ASM_SH_POSIX_TYPES_32_H))))
#define __ASM_SH_POSIX_TYPES_H   (1)
#define _ASM_SH_POSIX_TYPES_H   (1)
#define __ASM_SH_POSIX_TYPES_32_H   (1)
#define _ASM_SH_POSIX_TYPES_32_H   (1)


typedef unsigned short   __kernel_dev_t;
typedef unsigned long   __kernel_ino_t;
typedef unsigned short   __kernel_mode_t;
typedef unsigned short   __kernel_nlink_t;
typedef long   __kernel_off_t;
typedef int   __kernel_pid_t;
typedef unsigned short   __kernel_ipc_pid_t;
typedef unsigned short   __kernel_uid_t;
typedef unsigned short   __kernel_gid_t;
typedef unsigned int   __kernel_size_t;
typedef int   __kernel_ssize_t;
typedef int   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_daddr_t;
typedef char*   __kernel_caddr_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef unsigned int   __kernel_uid32_t;
typedef unsigned int   __kernel_gid32_t;
typedef unsigned short   __kernel_old_uid_t;
typedef unsigned short   __kernel_old_gid_t;
typedef __kernel_dev_t   __kernel_old_dev_t;
typedef long long   __kernel_loff_t;
typedef struct __kernel_fsid {
#   ifdef __USE_ALL
	int val[2];
#   else
	int __val[2];
#   endif
} __kernel_fsid_t;


#elif (defined(ARCHXTENSA) && (!(defined(_XTENSA_POSIX_TYPES_H) || defined(_XTENSA_POSIX_TYPES_H_) || defined(__XTENSA_POSIX_TYPES_H))))
#define _XTENSA_POSIX_TYPES_H   (1)
#define _XTENSA_POSIX_TYPES_H_   (1)
#define __XTENSA_POSIX_TYPES_H   (1)


typedef unsigned long   __kernel_ino_t;
typedef unsigned int   __kernel_mode_t;
typedef unsigned long   __kernel_nlink_t;
typedef long   __kernel_off_t;
typedef int   __kernel_pid_t;
typedef unsigned short   __kernel_ipc_pid_t;
typedef unsigned int   __kernel_uid_t;
typedef unsigned int   __kernel_gid_t;
typedef unsigned int   __kernel_size_t;
typedef int   __kernel_ssize_t;
typedef long   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef int   __kernel_timer_t;
typedef int   __kernel_clockid_t;
typedef int   __kernel_daddr_t;
typedef char*   __kernel_caddr_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef unsigned int   __kernel_uid32_t;
typedef unsigned int   __kernel_gid32_t;
typedef unsigned short   __kernel_old_uid_t;
typedef unsigned short   __kernel_old_gid_t;
typedef unsigned short   __kernel_old_dev_t;
typedef long long   __kernel_loff_t;
typedef unsigned int   __kernel_dev_t;
typedef struct __kernel_fsid { int val[2]; }   __kernel_fsid_t;


#else


#if (!(defined(_ASM_POSIX_TYPES_H) || defined(_ASM_POSIX_TYPES_H_) || defined(__ASM_POSIX_TYPES_H)))
#define _ASM_POSIX_TYPES_H   (1)
#define _ASM_POSIX_TYPES_H_   (1)
#define __ASM_POSIX_TYPES_H   (1)


#   if IS_WORDSIZE_64
typedef unsigned int   __kernel_dev_t;
typedef unsigned long   __kernel_ino_t;
typedef unsigned int   __kernel_mode_t;
typedef unsigned int   __kernel_nlink_t;
typedef long   __kernel_off_t;
typedef int   __kernel_pid_t;
typedef long   __kernel_ipc_pid_t;
typedef int   __kernel_uid_t;
typedef int   __kernel_gid_t;
typedef unsigned long   __kernel_size_t;
typedef long   __kernel_ssize_t;
typedef long   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef long   __kernel_daddr_t;
typedef char*   __kernel_caddr_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef int   __kernel_uid32_t;
typedef int   __kernel_gid32_t;
typedef __kernel_uid_t   __kernel_old_uid_t;
typedef __kernel_gid_t   __kernel_old_gid_t;
typedef __kernel_dev_t   __kernel_old_dev_t;
typedef long long   __kernel_loff_t;
#   else
typedef unsigned int   __kernel_dev_t;
typedef unsigned long   __kernel_ino_t;
typedef unsigned int   __kernel_mode_t;
typedef unsigned long   __kernel_nlink_t;
typedef long   __kernel_off_t;
typedef int   __kernel_pid_t;
typedef long   __kernel_ipc_pid_t;
typedef int   __kernel_uid_t;
typedef int   __kernel_gid_t;
typedef unsigned int   __kernel_size_t;
typedef int   __kernel_ssize_t;
typedef int   __kernel_ptrdiff_t;
typedef long   __kernel_time_t;
typedef long   __kernel_suseconds_t;
typedef long   __kernel_clock_t;
typedef long   __kernel_daddr_t;
typedef char*   __kernel_caddr_t;
typedef unsigned short   __kernel_uid16_t;
typedef unsigned short   __kernel_gid16_t;
typedef int   __kernel_uid32_t;
typedef int   __kernel_gid32_t;
typedef __kernel_uid_t   __kernel_old_uid_t;
typedef __kernel_gid_t   __kernel_old_gid_t;
typedef __kernel_dev_t   __kernel_old_dev_t;
typedef long long   __kernel_loff_t;
#   endif
typedef struct __kernel_fsid { long val[2]; }   __kernel_fsid_t;


#endif  // ASM_POSIX_TYPES_H


#endif


#endif  // BITS_KERNEL_TYPES_H


/* PRINTING & SCANNING FORMAT SPECIFIERS */


#ifndef __STDC_FORMAT_MACROS
#   define __STDC_FORMAT_MACROS   (1)
#endif

#if ((!defined(PRINTF_SCANF_FORMAT_SPECIFIERS_H)) && defined(ALLOW_HEADER_PRINTF_SCANF_FORMAT_SPECIFIERS_H))
#define PRINTF_SCANF_FORMAT_SPECIFIERS_H   (1)


#if IS_WORDSIZE_64
#   define __PRI64_PREFIX   "l"
#   define __PRIPTR_PREFIX   "l"
#else
#   define __PRI64_PREFIX   "ll"
#   define __PRIPTR_PREFIX   "ll"
# endif
#ifndef PRI64_PREFIX
#   define PRI64_PREFIX   __PRI64_PREFIX
#endif
#ifndef PRIPTR_PREFIX
#   define PRIPTR_PREFIX   __PRIPTR_PREFIX
#endif


// PRINTING FORMAT SPECIFIERS

/** @defgroup Printing_Format_Specifiers Macros for `printf()` (and other similar functions) format specifiers
@{ */  // (FB){

/** Casts the uint64_t value in `x` to the right type for an argument to printf */
#define U64_PRINTF_ARG(x)   ((uint64_t)(x))
/** Casts the int64_t value in `x` to the right type for an argument to printf */
#define I64_PRINTF_ARG(x)   ((int64_t)(x))
// Octal Notation
#define PRIo8   "o"
#define PRIo16   "o"
#define PRIo32   "o"
#define PRIo64   __PRI64_PREFIX "o"
#define PRIoLEAST8   "o"
#define PRIoLEAST16   "o"
#define PRIoLEAST32   "o"
#define PRIoLEAST64   __PRI64_PREFIX "o"
#define PRIoFAST8   "o"
#define PRIoFAST16   "o"
#define PRIoFAST32   "o"
#define PRIoFAST64   __PRI64_PREFIX "o"
// Decimal Notation
#define PRId8   "d"
#define PRId16   "d"
#define PRId32   "d"
#define PRId64   __PRI64_PREFIX "d"
#define PRIdLEAST8   "d"
#define PRIdLEAST16   "d"
#define PRIdLEAST32   "d"
#define PRIdLEAST64   __PRI64_PREFIX "d"
#define PRIdFAST8   "d"
#define PRIdFAST16   "d"
#define PRIdFAST32   "d"
#define PRIdFAST64   __PRI64_PREFIX "d"
// Lowercase Hexadecimal Notation
#define PRIx8   "x"
#define PRIx16   "x"
#define PRIx32   "x"
#define PRIx64   __PRI64_PREFIX "x"
#define PRIxLEAST8   "x"
#define PRIxLEAST16   "x"
#define PRIxLEAST32   "x"
#define PRIxLEAST64   __PRI64_PREFIX "x"
#define PRIxFAST8   "x"
#define PRIxFAST16   "x"
#define PRIxFAST32   "x"
#define PRIxFAST64   __PRI64_PREFIX "x"
// Uppercase Hexadecimal Notation
#define PRIX8   "X"
#define PRIX16   "X"
#define PRIX32   "X"
#define PRIX64   __PRI64_PREFIX "X"
#define PRIXLEAST8   "X"
#define PRIXLEAST16   "X"
#define PRIXLEAST32   "X"
#define PRIXLEAST64   __PRI64_PREFIX "X"
#define PRIXFAST8   "X"
#define PRIXFAST16   "X"
#define PRIXFAST32   "X"
#define PRIXFAST64   __PRI64_PREFIX "X"
// Singed Integers
#define PRIi8   "i"
#define PRIi16   "i"
#define PRIi32   "i"
#define PRIi64   __PRI64_PREFIX "i"
#define PRIiLEAST8   "i"
#define PRIiLEAST16   "i"
#define PRIiLEAST32   "i"
#define PRIiLEAST64   __PRI64_PREFIX "i"
#define PRIiFAST8   "i"
#define PRIiFAST16   "i"
#define PRIiFAST32   "i"
#define PRIiFAST64   __PRI64_PREFIX "i"
// Unsigned Integers
#define PRIu8   "u"
#define PRIu16   "u"
#define PRIu32   "u"
#define PRIu64   __PRI64_PREFIX "u"
#define PRIuLEAST8   "u"
#define PRIuLEAST16   "u"
#define PRIuLEAST32   "u"
#define PRIuLEAST64   __PRI64_PREFIX "u"
#define PRIuFAST8   "u"
#define PRIuFAST16   "u"
#define PRIuFAST32   "u"
#define PRIuFAST64   __PRI64_PREFIX "u"
// Other Fixed-Width Integrals
#define PRIsize   "zu"
#define PRIssize   "zd"
// `intmax_t` & `uintmax_t`
#define PRIdMAX   __PRI64_PREFIX "d"
#define PRIiMAX   __PRI64_PREFIX "i"
#define PRIoMAX   __PRI64_PREFIX "o"
#define PRIuMAX   __PRI64_PREFIX "u"
#define __PRIuBIT   PRIuMAX
#define __PRIuBITS   PRIuMAX
#define PRIxMAX   __PRI64_PREFIX "x"
#define PRIXMAX   __PRI64_PREFIX "X"
#define __PRIxBIT   PRIxMAX
#define __PRIxBITS   PRIxMAX
// `intptr_t` & `uintptr_t`
#define PRIdPTR   __PRIPTR_PREFIX "d"
#define PRIiPTR   __PRIPTR_PREFIX "i"
#define PRIoPTR   __PRIPTR_PREFIX "o"
#define PRIuPTR   __PRIPTR_PREFIX "u"
#define PRIxPTR   __PRIPTR_PREFIX "x"
#define PRIXPTR   __PRIPTR_PREFIX "X"
// Architecture-Specific Specifiers
#ifdef ARCHARM
#   define PRIuPSIZE   "lu"
#   define PRIuVSIZE   "lu"
#   define PRIxPADDR   "lx"
#   define PRIxPSIZE   "lx"
#   define PRIxREGISTER   "x"
#   define PRIxVADDR   "lx"
#   define PRIxVSIZE   "lx"
#elif defined(ARCHX86_32)
#   ifdef _KERNEL
#      ifdef PAE
#         define PRIuPSIZE   "llu"
#         define PRIxPADDR   "llx"
#         define PRIxPSIZE   "llx"
#      else
#         define PRIuPSIZE   "lu"
#         define PRIxPADDR   "lx"
#         define PRIxPSIZE   "lx"
#      endif  // PAE
#   else
#      define PRIuPSIZE   "llu"
#      define PRIxPADDR   "llx"
#      define PRIxPSIZE   "llx"
#   endif  // _KERNEL
#   define PRIuVSIZE   "lu"
#   define PRIxREGISTER   "x"
#   define PRIxVADDR   "lx"
#   define PRIxVSIZE   "lx"
#endif

/** @} */  // }


// SCANNING FORMAT SPECIFIERS

/** @defgroup Scanning_Format_Specifiers Macros for `scanf()` (and other similar functions) format specifiers
@{ */  // (FB){

// Octal Notation
#define SCNo8   "hho"
#define SCNo16   "ho"
#define SCNo32   "o"
#define SCNo64   __PRI64_PREFIX "o"
#define SCNoLEAST8   "hho"
#define SCNoLEAST16   "ho"
#define SCNoLEAST32   "o"
#define SCNoLEAST64   __PRI64_PREFIX "o"
#define SCNoFAST8   "hho"
#define SCNoFAST16   "ho"
#define SCNoFAST32   "o"
#define SCNoFAST64   __PRI64_PREFIX "o"
// Signed Decimal Notation
#define SCNd8   "hhd"
#define SCNd16   "hd"
#define SCNd32   "d"
#define SCNd64   __PRI64_PREFIX "d"
#define SCNdLEAST8   "hhd"
#define SCNdLEAST16   "hd"
#define SCNdLEAST32   "d"
#define SCNdLEAST64   __PRI64_PREFIX "d"
#define SCNdFAST8   "hhd"
#define SCNdFAST16   "hd"
#define SCNdFAST32   "d"
#define SCNdFAST64   __PRI64_PREFIX "d"
// Hexadecimal Notation
#define SCNx8   "hhx"
#define SCNx16   "hx"
#define SCNx32   "x"
#define SCNx64   __PRI64_PREFIX "x"
#define SCNxLEAST8   "hhx"
#define SCNxLEAST16   "hx"
#define SCNxLEAST32   "x"
#define SCNxLEAST64   __PRI64_PREFIX "x"
#define SCNxFAST8   "hhx"
#define SCNxFAST16   "hx"
#define SCNxFAST32   "x"
#define SCNxFAST64   __PRI64_PREFIX "x"
// Signed Integer Notation
#define SCNi8   "hhi"
#define SCNi16   "hi"
#define SCNi32   "i"
#define SCNi64   __PRI64_PREFIX "i"
#define SCNiLEAST8   "hhi"
#define SCNiLEAST16   "hi"
#define SCNiLEAST32   "i"
#define SCNiLEAST64   __PRI64_PREFIX "i"
#define SCNiFAST8   "hhi"
#define SCNiFAST16   "hi"
#define SCNiFAST32   "i"
#define SCNiFAST64   __PRI64_PREFIX "i"
// Unsigned Integer Notation
#define SCNu8   "hhu"
#define SCNu16   "hu"
#define SCNu32   "u"
#define SCNu64   __PRI64_PREFIX "u"
#define SCNuLEAST8   "hhu"
#define SCNuLEAST16   "hu"
#define SCNuLEAST32   "u"
#define SCNuLEAST64   __PRI64_PREFIX "u"
#define SCNuFAST8   "hhu"
#define SCNuFAST16   "hu"
#define SCNuFAST32   "u"
#define SCNuFAST64   __PRI64_PREFIX "u"
// Scanning `intmax_t` & `uintmax_t`
#define SCNdMAX   __PRI64_PREFIX "d"
#define SCNiMAX   __PRI64_PREFIX "i"
#define SCNoMAX   __PRI64_PREFIX "o"
#define SCNuMAX   __PRI64_PREFIX "u"
#define SCNxMAX   __PRI64_PREFIX "x"
// Scanning `intptr_t` & `uintptr_t`
#define SCNdPTR   __PRIPTR_PREFIX "d"
#define SCNiPTR   __PRIPTR_PREFIX "i"
#define SCNoPTR   __PRIPTR_PREFIX "o"
#define SCNuPTR   __PRIPTR_PREFIX "u"
#define SCNxPTR   __PRIPTR_PREFIX "x"

/** @} */  // }


// MICROSOFT PRINTF & SCANF MACROS

/** @defgroup MS_Microsoft_Printing_and_Scanning_Format_Specifiers MS-Microsoft-specific macros-based format specifiers for `printf()`, `scanf()`, and other related functions
@{ */  // (FB){

#ifdef OSWINDOWS
#   define PFMT64x   "I64x"
#   define PFMT64d   "I64d"
#   define PFMT64u   "I64u"
#   define PFMT64o   "I64o"
#else
#   define PFMT64x   "llx"
#   define PFMT64d   "lld"
#   define PFMT64u   "llu"
#   define PFMT64o   "llo"
#endif
/** @def U64_FORMAT
The formatting string used to put an `uint64_t` value in a `printf()` or `scanf()` function */
/** @def I64_FORMAT
The formatting string used to put an `int64_t` value in a `printf()` or `scanf()` function */
/** @def U64_SCANF_ARG
Casts the `uint64_t*` value in `x` to the right type for an argument to `scanf()` */
/** @def U64_LITERAL
Expands to a literal `uint64_t` constant for the value `n` */
#if (defined(COMPILER_MICROSOFT) || defined(COMPILER_MINGW))
#   define U64_FORMAT   "%I64u"
#   define I64_FORMAT   "%I64d"
#   define U64_SCANF_ARG(x)   x
#   define U64_LITERAL(n)   n ## ui64
#   define I64_SCANF_ARG(x)   x
#   define I64_LITERAL(n)   n ## i64
#else
#   define U64_FORMAT   "%llu"
#   define I64_FORMAT   "%lld"
#   define U64_SCANF_ARG(x)   ((uint64_t*)(x))
#   define U64_LITERAL(n)   n ## llu
#   define I64_SCANF_ARG(x)   ((int64_t*)(x))
#   define I64_LITERAL(n)   n ## ll
#endif

/** @} */  // }


// PLAN9 PRINTF & SCANF MACROS

/** @defgroup Plan9_Printing_and_Scanning_Format_Specifiers Plan9-specific macros-based format specifiers for `printf()`, `scanf()`, and other related functions
@{ */  // (FB){

#ifdef OSPLAN9
#   pragma varargck type "d" int
#   pragma varargck type "o" int
#   pragma varargck type "x" int
#   pragma varargck type "c" int
#   pragma varargck type "C" int
#   pragma varargck type "b" int
#   pragma varargck type "d" unsigned int
#   pragma varargck type "x" unsigned int
#   pragma varargck type "c" unsigned int
#   pragma varargck type "C" unsigned int
#   pragma varargck type "b" unsigned int
#   pragma varargck type "ld" long
#   pragma varargck type "lo" long
#   pragma varargck type "lx" long
#   pragma varargck type "lb" long
#   pragma varargck type "ld" unsigned long
#   pragma varargck type "lo" unsigned long
#   pragma varargck type "lx" unsigned long
#   pragma varargck type "lb" unsigned long
#   pragma varargck type "lld" long long
#   pragma varargck type "llo" long long
#   pragma varargck type "llx" long long
#   pragma varargck type "llb" long long
#   pragma varargck type "lld" unsigned long long
#   pragma varargck type "llo" unsigned long long
#   pragma varargck type "llx" unsigned long long
#   pragma varargck type "llb" unsigned long long
#   pragma varargck type "f" double
#   pragma varargck type "e" double
#   pragma varargck type "g" double
#   pragma varargck type "r" void
#   pragma varargck type "%" void
#   pragma varargck type "p" void*
#   pragma varargck type "<" void*
#   pragma varargck type "[" void*
#   pragma varargck type "H" void*
#   pragma varargck type "lH" void*
#   pragma varargck type "s" char*
#   pragma varargck type "q" char*
#   pragma varargck type "S" Rune*
#   pragma varargck type "Q" Rune*
#   pragma varargck type "n" int*
#   pragma varargck type "p" uintptr_t
#   pragma varargck flag ','
#   pragma varargck flag ' '
#   pragma varargck flag 'h'
#endif

/** @} */  // }


// MISCELLANEOUS PRINTF & SCANF MACROS

/** @defgroup Miscellaneous_Printing_and_Scanning_Format_Specifiers Miscellaneous macros-based format specifiers for `printf()`, `scanf()`, and other related functions
@{ */  // (FB){

#define PTRDIFF_T_SUFFIX   l
#define SIZE_T_SUFFIX   ul
#define WINT_T_SUFFIX   u
#ifdef __PTRDIFF_FMTd__
#   define PTRDIFF_FMTd   __PTRDIFF_FMTd__
#else
#   define __PTRDIFF_FMTd__   "ld"
#   define PTRDIFF_FMTd   __PTRDIFF_FMTd__
#endif
#ifdef __PTRDIFF_FMTi__
#   define PTRDIFF_FMTi   __PTRDIFF_FMTi__
#else
#   define __PTRDIFF_FMTi__   "li"
#   define PTRDIFF_FMTi   __PTRDIFF_FMTi__
#endif
#ifdef __SIZE_FMTX__
#   define SIZE_FMTX   __SIZE_FMTX__
#else
#   define __SIZE_FMTX__   "lX"
#   define SIZE_FMTX   __SIZE_FMTX__
#endif
#ifdef __SIZE_FMTo__
#   define SIZE_FMTo   __SIZE_FMTo__
#else
#   define __SIZE_FMTo__   "lo"
#   define SIZE_FMTo   __SIZE_FMTo__
#endif
#ifdef __SIZE_FMTu__
#   define SIZE_FMTu   __SIZE_FMTu__
#else
#   define __SIZE_FMTu__   "lu"
#   define SIZE_FMTu   __SIZE_FMTu__
#endif
#ifdef __SIZE_FMTx__
#   define SIZE_FMTx   __SIZE_FMTx__
#else
#   define __SIZE_FMTx__   "lx"
#   define SIZE_FMTx   __SIZE_FMTx__
#endif
#define __INT16_C_SUFFIX__
#define __INT16_FMTd__   "hd"
#define __INT16_FMTi__   "hi"
#define __INT32_C_SUFFIX__
#define __INT32_FMTd__   "d"
#define __INT32_FMTi__   "i"
#define __INT64_C_SUFFIX__   L
#define __INT64_FMTd__   "ld"
#define __INT64_FMTi__   "li"
#define __INT8_C_SUFFIX__
#define __INT8_FMTd__   "hhd"
#define __INT8_FMTi__   "hhi"
#define __INTMAX_C_SUFFIX__   L
#define __INTMAX_FMTd__   "ld"
#define __INTMAX_FMTi__   "li"
#define __INTPTR_FMTd__   "ld"
#define __INTPTR_FMTi__   "li"
#define __INT_FAST16_FMTd__   "hd"
#define __INT_FAST16_FMTi__   "hi"
#define __INT_FAST32_FMTd__   "d"
#define __INT_FAST32_FMTi__   "i"
#define __INT_FAST64_FMTd__   "ld"
#define __INT_FAST64_FMTi__   "li"
#define __INT_FAST8_FMTd__   "hhd"
#define __INT_FAST8_FMTi__   "hhi"
#define __INT_LEAST16_FMTd__   "hd"
#define __INT_LEAST16_FMTi__   "hi"
#define __INT_LEAST32_FMTd__   "d"
#define __INT_LEAST32_FMTi__   "i"
#define __INT_LEAST64_FMTd__   "ld"
#define __INT_LEAST64_FMTi__   "li"
#define __INT_LEAST8_FMTd__   "hhd"
#define __INT_LEAST8_FMTi__   "hhi"
#define __UINT16_C_SUFFIX__
#define __UINT16_FMTX__   "hX"
#define __UINT16_FMTo__   "ho"
#define __UINT16_FMTu__   "hu"
#define __UINT16_FMTx__   "hx"
#define __UINT32_C_SUFFIX__   U
#define __UINT32_FMTX__   "X"
#define __UINT32_FMTo__   "o"
#define __UINT32_FMTu__   "u"
#define __UINT32_FMTx__   "x"
#define __UINT64_C_SUFFIX__   UL
#define __UINT64_FMTX__   "lX"
#define __UINT64_FMTo__   "lo"
#define __UINT64_FMTu__   "lu"
#define __UINT64_FMTx__   "lx"
#define __UINT8_C_SUFFIX__
#define __UINT8_FMTX__   "hhX"
#define __UINT8_FMTo__   "hho"
#define __UINT8_FMTu__   "hhu"
#define __UINT8_FMTx__   "hhx"
#define __UINTMAX_C_SUFFIX__   UL
#define __UINTMAX_FMTX__   "lX"
#define __UINTMAX_FMTo__   "lo"
#define __UINTMAX_FMTu__   "lu"
#define __UINTMAX_FMTx__   "lx"
#define __UINTPTR_FMTX__   "lX"
#define __UINTPTR_FMTo__   "lo"
#define __UINTPTR_FMTu__   "lu"
#define __UINTPTR_FMTx__   "lx"
#define __UINT_FAST16_FMTX__   "hX"
#define __UINT_FAST16_FMTo__   "ho"
#define __UINT_FAST16_FMTu__   "hu"
#define __UINT_FAST16_FMTx__   "hx"
#define __UINT_FAST32_FMTX__   "X"
#define __UINT_FAST32_FMTo__   "o"
#define __UINT_FAST32_FMTu__   "u"
#define __UINT_FAST32_FMTx__   "x"
#define __UINT_FAST64_FMTX__   "lX"
#define __UINT_FAST64_FMTo__   "lo"
#define __UINT_FAST64_FMTu__   "lu"
#define __UINT_FAST64_FMTx__   "lx"
#define __UINT_FAST8_FMTX__   "hhX"
#define __UINT_FAST8_FMTo__   "hho"
#define __UINT_FAST8_FMTu__   "hhu"
#define __UINT_FAST8_FMTx__   "hhx"
#define __UINT_LEAST16_FMTX__   "hX"
#define __UINT_LEAST16_FMTo__   "ho"
#define __UINT_LEAST16_FMTu__   "hu"
#define __UINT_LEAST16_FMTx__   "hx"
#define __UINT_LEAST32_FMTX__   "X"
#define __UINT_LEAST32_FMTo__   "o"
#define __UINT_LEAST32_FMTu__   "u"
#define __UINT_LEAST32_FMTx__   "x"
#define __UINT_LEAST64_FMTX__   "lX"
#define __UINT_LEAST64_FMTo__   "lo"
#define __UINT_LEAST64_FMTu__   "lu"
#define __UINT_LEAST64_FMTx__   "lx"
#define __UINT_LEAST8_FMTX__   "hhX"
#define __UINT_LEAST8_FMTo__   "hho"
#define __UINT_LEAST8_FMTu__   "hhu"
#define __UINT_LEAST8_FMTx__   "hhx"

/** @} */  // }


#endif  // PRINTF_SCANF_FORMAT_SPECIFIERS_H


/* SPECIFICATIONS & FEATURES MACROS */


#if (!(defined(SPECIFICATIONS_H) || defined(_SPECIFICATIONS_H_)))
#define SPECIFICATIONS_H   (1)
#define _SPECIFICATIONS_H   (1)
#define _SPECIFICATIONS_H_   (1)
#define _BASETSD_H_   (1)
#define FEATURES_H   (1)  // <features.h>
#define _FEATURES_H   (1)
#define _FEATURES_H_   (1)
#define UNISTD_H   (1)  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/unistd.h.html
#define _UNISTD_H   (1)  // <unistd.h>
#define _UNISTD_H_   (1)
#define _LIBC_UNISTD_H   (1)
#define _LIBC_UNISTD_H_   (1)
#define _BSD_UNISTD_H   (1)
#define _BSD_UNISTD_H_   (1)
#define _LINUX_UNISTD_H_   (1)
#define _NEWLIB_UNISTD_H   (1)
#define _SYS_UNISTD_H   (1)
#define _LIBROOT_UNISTD_PRIVATE_H   (1)
#define _LIBROOT_UNISTD_PRIVATE_H_   (1)
#define unistd__INCLUDED   (1)
#define _COMPAT_UNISTD_H_   (1)
#define _BITS_POSIX_OPT_H   (1)
#define _LINUX_LIMITS_H   (1)
#define _LINUX_LIMITS_H_   (1)
#define _XOPEN_LIM_H   (1)
#define _XOPEN_LIM_H_   (1)
#define _BITS_POSIX1_LIM_H   (1)
#define _BITS_POSIX1_LIM_H_   (1)
#define _BITS_POSIX2_LIM_H   (1)
#define _BITS_POSIX2_LIM_H_   (1)
#define _SYS_SYSLIMITS_H   (1)
#define _SYS_SYSLIMITS_H_   (1)
#define _PAX_LIMITS_H   (1)
#define _SYS_VLIMIT_H_   (1)


// DATATYPE CLASSES

enum type_class {
	no_type_class = -1,
	void_type_class,
	integer_type_class,
	char_type_class,
	enumeral_type_class,
	boolean_type_class,
	pointer_type_class,
	reference_type_class,
	offset_type_class,
	real_type_class,
	complex_type_class,
	function_type_class,
	method_type_class,
	record_type_class,
	union_type_class,
	array_type_class,
	string_type_class,
	lang_type_class
};


// MACROS FOR INTEGER & FLOAT CONSTANTS

/** @defgroup Macros_for_Datatype_Constants Macros for creating dataype constants dynamically in macros
@{ */  // (FB){

#ifndef __int_join
#   define __int_join_(n, suffix)   n ## suffix
#   define __int_join(n, suffix)   n ## suffix
#endif
#define __int_c_join(n, suffix)   n ## suffix
#define __int_c(n, suffix)   n ## suffix
#define __uint_join(n, suffix)   n ## U ## suffix
#define __uint_c(n, suffix)   n ## U ## suffix
#define __stdint_join3(type, n, suffix)   type ## n ## suffix
#define __intn_t(n)   __stdint_join3("int", n, "_t")
#define __uintn_t(n)   __stdint_join3("uint", n, "_t")
#define __INTN_MIN(n)   __stdint_join3("INT", n, "_MIN")
#define __INTN_MAX(n)   __stdint_join3("INT", n, "_MAX")
#define __UINTN_MAX(n)   __stdint_join3("UINT", n, "_MAX")
#define __long_join(n)   n ## L
#define eval_long_join(n)   __long_join(n)
#define __ulong_join(n)   n ## UL
#define eval_ulong_join(n)   eval_ulong_join(n)
#define __longlong_join(n)   n ## LL
#define eval_longlong_join(n)   eval_longlong_join(n)
#define __ulonglong_join(n)   n ## ULL
#define eval_ulonglong_join(n)   __ulonglong_join(n)
#ifndef __flt_join
#   define __flt_join_(n, suffix)   n ## suffix
#   define __flt_join(n, suffix)   n ## suffix
#endif
#define __flt_c_join(n, suffix)   n ## suffix
#define __flt_c(n, suffix)   n ## suffix
#define __float_join(n, suffix)   n ## suffix
#if (AT_LEAST_GCC7 && SUPPORTS_FLOAT16)
#   define __f16(x)   x ## F16
#   define __flt16_join(x)   x ## F16
#elif SUPPORTS_FLOAT16
#   define __f16(x)   (float16)(x ## F)
#   define __flt16_join(x)   (float16)(x ## F)
#endif
#define flt_join(n)   n ## F
#define eval_flt_join(n)   flt_join(n)
#if AT_LEAST_GCC7
#   define __flt32_join(n)   n ## F32
#   define __flt64_join(n)   n ## F64
#   if SUPPORTS_FLOAT128
#      define __flt128_join(n)   n ## F128
#   endif
#   define __flt32x_join(n)   n ## F32x
#   define __flt64x_join(n)   n ## F64x
#else
#   define __flt32_join(n)   n ## F
#   define __flt64_join(n)   n
#   define __flt32x_join(n)   n
#endif
#define __ldbl_join(n)   n ## L
#define ldbl_join(n)   n ## L
#define eval_ldbl_join(n)   ldbl_join(n)
#define __flt80_join(n)   n ## W
#define __quadflt_join(n)   n ## Q
#define __ibmflt_join(n)   n ## W
#define __dec32_join(n)   n ## DF
#define eval_dec32_join(n)   __dec32_join(n)
#define __dec64_join(n)   n ## DD
#define eval_dec64_join(n)   __dec64_join(n)
#define __dec128_join(n)   n ## DL
#define __cmplx_int_join(n)   n ## i
#define __cmplx_flt_join(n)   n ## Fi
#define __cmplx_dbl_join(n)   n ## F64i
#define __cmplx_flt128_join(n)   n ## F128i
#define __cmplx_ldbl_join(n)   n ## Li
#if IS_NOT_CPLUSPLUS
#   ifndef __INT8_C
/** Expands to an integer constant (of type int8_t) having the value specified by its argument */
#      define __INT8_C(num)   ((int8_t)num)
#   endif
#   ifndef INT8_C
/** Expands to an integer constant (of type int8_t) having the value specified by its argument */
#      define INT8_C(num)   __INT8_C((num))
#   endif
#   ifndef __INT16_C
#      define __INT16_C(num)   ((int16_t)num)
#   endif
#   ifndef INT16_C
#      define INT16_C(num)   __INT16_C((num))
#   endif
#   if ((!defined(__INT32_C)) && LONG_EQ_INT)
#      define __INT32_C(num)   ((int32_t)(num ## L))
#   elif (!defined(__INT32_C))
#      define __INT32_C(num)   ((int32_t)(num))
#   endif
#   ifndef INT32_C
#      define INT32_C(num)   __INT32_C((num))
#   endif
#   ifndef __UINT8_C
#      define __UINT8_C(num)   ((uint8_t)num)
#   endif
#   ifndef UINT8_C
#      define UINT8_C(num)   __UINT8_C((num))
#   endif
#   ifndef __UINT16_C
#      define __UINT16_C(num)   ((uint16_t)num)
#   endif
#   ifndef UINT16_C
#      define UINT16_C(num)   __UINT16_C((num))
#   endif
#   if ((!defined(__UINT32_C)) && LONG_EQ_INT)
#      define __UINT32_C(num)   ((uint32_t)(num ## UL))
#   elif (!defined(__UINT32_C))
#      define __UINT32_C(num)   ((uint32_t)(num ## U))
#   endif
#   ifndef UINT32_C
#      define UINT32_C(num)   __UINT32_C((num))
#   endif
#   if IS_WORDSIZE_64
#      ifndef __INT64_C
/** Expands to an integer constant (of type int64_t) having the value specified by its argument */
#         define __INT64_C(num)   ((int64_t)num ## L)
#         define INT64_C(num)   __INT64_C((num))
#      else
#         define INT64_C(num)   __INT64_C((num))
#      endif
#      ifndef __UINT64_C
/** Expands to an integer constant (of type uint64_t) having the value specified by its argument */
#         define __UINT64_C(num)   ((uint64_t)num ## UL)
#         define UINT64_C(num)   __UINT64_C((num))
#      else
#         define UINT64_C(num)   __UINT64_C((num))
#      endif
#   else  // WORDSIZE == 32
#      ifndef __INT64_C
/** Expands to an integer constant (of type int64_t) having the value specified by its argument */
#         define __INT64_C(num)   ((int64_t)num ## LL)
#         define INT64_C(num)   __INT64_C((num))
#      else
#         define INT64_C(num)   __INT64_C((num))
#      endif
#      ifndef __UINT64_C
#         define __UINT64_C(num)   ((uint64_t)num ## ULL)
#         define UINT64_C(num)   __UINT64_C((num))
#      else
#         define UINT64_C(num)   __UINT64_C((num))
#      endif
#   endif  // IS_WORDSIZE_64
#   define LIT64(a)   __INT64_C(num)
#   ifdef __INTMAX_C
/** Expands to an integer constant (of type intmax_t) having the value specified by its argument */
#      define INTMAX_C(num)   __INTMAX_C((num))
#   else
#      define __INTMAX_C(num)   ((int64_t)(num) ## LL)
#      define INTMAX_C(num)   __INTMAX_C((num))
#   endif
#   ifdef __UINTMAX_C
/** Expands to an integer constant (of type uintmax_t) having the value specified by its argument */
#      define UINTMAX_C(num)   __UINTMAX_C((num))
#   else
#      define __UINTMAX_C(num)   ((uint64_t)(num) ## ULL)
#      define UINTMAX_C(num)   __UINTMAX_C((num))
#   endif
#endif  // IS_NOT_CPLUSPLUS

// Uncommon Integral Constants

#if SUPPORTS_INT24
#   ifdef __INT24_C_SUFFIX__
#      define INT24_C(n)   __int_join(n, __INT24_C_SUFFIX__)
#      define UINT24_C(n)   __uint_join(n, __INT24_C_SUFFIX__)
#   else
#      define INT24_C(n)   n
#      define UINT24_C(n)   (n ## U)
#   endif
#endif
#if SUPPORTS_INT40
#   ifdef __INT40_C_SUFFIX__
#      define INT40_C(n)   __int_join(n, __INT40_C_SUFFIX__)
#      define UINT40_C(n)   __uint_join(n, __INT40_C_SUFFIX__)
#   else
#      define INT40_C(n)   n
#      define UINT40_C(n)   (n ## U)
#   endif
#endif
#if SUPPORTS_INT48
#   ifdef __INT48_C_SUFFIX__
#      define INT48_C(n)   __int_join(n, __INT48_C_SUFFIX__)
#      define UINT48_C(n)   __uint_join(n, __INT48_C_SUFFIX__)
#   else
#      define INT48_C(n)   n
#      define UINT48_C(n)   (n ## U)
#   endif
#endif
#if SUPPORTS_INT56
#   ifdef __INT56_C_SUFFIX__
#      define INT56_C(n)   __int_join(n, __INT56_C_SUFFIX__)
#      define UINT56_C(n)   __uint_join(n, __INT56_C_SUFFIX__)
#   else
#      define INT56_C(n)   n
#      define UINT56_C(n)   (n ## U)
#   endif
#endif

/** @} */  // }


// MATH FEATURE SUPPORT

/** @defgroup Math_Feature_Support Macros for testing and indicating the support status of various math features
@{ */  // (FB){

/** @def __NO_MATH_INLINES
When compiling in strict ISO C compatible mode, inline functions must not be used since they do not set the `errno` variable correctly */
#ifndef __NO_MATH_INLINES
#   define __NO_MATH_INLINES   0
#endif
/** @def NO_MATH_INLINES
When compiling in strict ISO C compatible mode, inline functions must not be used since they do not set the `errno` variable correctly */
#ifndef NO_MATH_INLINES
#   define NO_MATH_INLINES   0
#endif
#if ((!defined(FAST_MATH)) && (defined(__FAST_MATH__) || defined(__fast_math__)))
#   define FAST_MATH   1
#endif
#if ((!defined(FINITE_MATH_ONLY)) && (defined(__FINITE_MATH_ONLY__) && (__FINITE_MATH_ONLY__ > 0)))
#   define FINITE_MATH_ONLY   1
#else
#   undef __FINITE_MATH_ONLY__
#   define __FINITE_MATH_ONLY__   0
#   define FINITE_MATH_ONLY   0
#endif

/** @} */  // }


// SUPPORTED HEADERS & FEATURES

/** @defgroup Supported_Features_and_Headers Macros for testing and indicating the support status of various C features and headers
@{ */  // (FB){

#ifndef __STDC_NO_THREADS__
/** No support for C11 <threads.h> */
#   define __STDC_NO_THREADS__   1
#endif
#ifndef __STDC_HOSTED__
/** Defined if the target has a hosted environment (complete standard C library) */
#   define __STDC_HOSTED__   0
#endif
/** @def IS_HOSTED
Returns 1 (true) if the target has a hosted environment (complete standard C library) */
#if ((!defined(IS_HOSTED)) && defined(__STDC_HOSTED__))
#   define IS_HOSTED   1
#elif (!defined(IS_HOSTED))
#   define IS_HOSTED   0
#endif
#ifndef __STD_UTF_8__
/** Values of type uchar8_t have UTF-8 encoding, otherwise, the encoding of uchar8_t is unspecified */
#   define __STD_UTF_8__   1
#endif
#ifndef __STDC_UTF_8__
/** Values of type uchar8_t have UTF-8 encoding, otherwise, the encoding of uchar8_t is unspecified */
#   define __STDC_UTF_8__   __STD_UTF_8__
#endif
#ifndef __STD_UTF_16__
/** Values of type char16_t have UTF-16 encoding, otherwise, the encoding of char16_t is unspecified */
#   define __STD_UTF_16__   1
#endif
#ifndef __STDC_UTF_16__
/** Values of type char16_t have UTF-16 encoding, otherwise, the encoding of char16_t is unspecified */
#   define __STDC_UTF_16__   __STD_UTF_16__
#endif
#ifndef __STD_UTF_32__
/** Values of type char32_t have UTF-32 encoding, otherwise, the encoding of char32_t is unspecified */
#   define __STD_UTF_32__   1
#endif
#ifndef __STDC_UTF_32__
/** Values of type char32_t have UTF-32 encoding, otherwise, the encoding of char32_t is unspecified */
#   define __STDC_UTF_32__   __STD_UTF_32__
#endif
#ifndef __STDC_UTF_64__
/** Values of type char64_t have UTF-64 encoding, otherwise, the encoding of char64_t is unspecified */
#   define __STDC_UTF_64__   __STD_UTF_64__
#endif
#define HAVE_ALLOCA   1
#define HAVE_MBSRTOWCS   1
#define HAVE_MBSTATE_T   1
#define HAVE_WCHAR_T   1
#define HAVE_STRUCT_STAT_ST_FLAGS   1
#define STDC_HEADERS   1
#define HAVE_ARPA_FTP_H   1
#define HAVE_ARPA_INET_H   1
#define HAVE_ARPA_NAMESER_H   1
#define HAVE_ARPA_TELNET_H   1
#define HAVE_ARPA_TFTP_H   1
#define HAVE_ASSERT_H   1
#define HAVE_ATOMIC_H   1
#define HAVE_CPIO_H   1
#define HAVE_CTYPE_H   1
#define HAVE_ERR_H   1
#define HAVE_ERRNO_H   1
#define HAVE_FENV_H   1
#define HAVE_FLOAT_H   1
#define HAVE_ICONV_H   0
#define HAVE_IFADDRS_H   1
#define HAVE_INTTYPES_H   1
#define HAVE_IPC_H   1
#define HAVE_ISO646_H   1
#define HAVE_LANGINFO_H   1
#define HAVE_LIMITS_H   1
#define HAVE_LOCALE_H   1
#define HAVE_MBCTYPE_H   1
#define HAVE_MATH_H   1
#define HAVE_MONETARY_H   1
#define HAVE_NET_ETHERNET_H   1
#define HAVE_NET_IF_H   1
#define HAVE_NET_IF_ARP_H   1
#define HAVE_NET_ROUTE_H   1
#define HAVE_NETINET_ICMP6_H   1
#define HAVE_NETINET_IF_ETHER_H   1
#define HAVE_NETINET_IN_H   1
#define HAVE_NETINET_TCP_H   1
#define HAVE_NL_TYPES_H   1
#define HAVE_NSCD_PROTO_H   1
#define HAVE_NSSWITCH_H   1
#define HAVE_OBSTACK_H   1
#define HAVE_PATHS_H   1
#define HAVE_POLL_H   1
#define HAVE_PPP_DEFS_H   1
#define HAVE_SETJMP_H   1
#define HAVE_SIGNAL_H   1
#define HAVE_STDALIGN_H   1
#define HAVE_STDARG_H   1
#define HAVE_STDATOMIC_H   1
#define HAVE_STDBOOL_H   1
#define HAVE_STDINT_H   1
#define HAVE_STDIO_H   1
#define HAVE_STDLIB_H   1
#define HAVE_STDNORETURN_H   1
#define HAVE_STRERROR_R   1
#define HAVE_STRING_H   1
#define HAVE_STRINGS_H   1
#define HAVE_STROPTS_H   1
#define HAVE_SYSLOG_H   1
#define HAVE_SYS_FANOTIFY_H   1
#define HAVE_SYS_INOTIFY_H   1
#define HAVE_SYS_IPC_H   1
#define HAVE_SYS_MMAN_H   0
#define HAVE_SYS_RESOURCE_H   1
#define HAVE_SYS_SEM_H   1
#define HAVE_SYS_SHM_H   1
#define HAVE_SYS_SENDFILE_H   1
#define HAVE_SYS_SIGNAL_H   1
#define HAVE_SYS_SOCKET_H   1
#define HAVE_SYS_STAT_H   1
#define HAVE_SYS_STATVFS_H   1
#define HAVE_SYS_TIME_H   1
#define HAVE_SYS_TIMES_H   1
#define HAVE_SYS_TYPES_H   1
#define HAVE_SYS_UIO_H   1
#define HAVE_SYS_UN_H   1
#define HAVE_TAR_H   1
#define HAVE_TGMATH_H   1
#define HAVE_TIME_H   1
#define HAVE_UCHAR_H   1
#define HAVE_ULIMIT_H   1
#define HAVE_UN_H   1
#define HAVE_UNISTD_H   1
#define HAVE_UTIME_H   1
#define HAVE_VADEFS_H   1
#define HAVE_VARARGS_H   1
#define HAVE_WCHAR_H   1
#define HAVE_WCTYPE_H   1
#define HAVE_XLOCALE_H   1

/** @} */  // }


// ENABLE/DISABLE HEADERS & FEATURES

/** @defgroup Enable_Disable_Headers_and_Features Macros used to enable/disable various headers and features in this library
@{ */  // (FB){

#ifdef ENABLE_BEOS_MACROS
/** Allow BeOS macros to be used */
#   define ALLOW_HEADER_BE_BUILD_H   1
#endif
#ifdef ENABLE_ELF_HEADERS
/** Allow ELF headers to be used */
#   define ALLOW_HEADER_ELF_H   1
#endif
#ifdef ENABLE_EMBEDDED_DEVICE_DATATYPES
/** Allow embedded device datatypes to be used */
#   define ALLOW_HEADER_EMBEDDED_DEVICE_DATATYPES_H   1
#endif
#ifdef ENABLE_FORMAT_SPECIFIERS
/** Allow printf/scanf format specifiers to be used */
#   define ALLOW_HEADER_PRINTF_SCANF_FORMAT_SPECIFIERS_H   1
#endif
#ifdef ENABLE_IIO_TYPES
/** Allow Industrial I/O datatypes to be used */
#   define ALLOW_HEADER_IIO_TYPES_H   1
#endif
#if (defined(ENABLE_MACH_FEATURES) || defined(OSMACH))
/** Allow Mach datatypes to be used */
#   define ALLOW_HEADER_MACH_DATATYPES_H   1
#endif
#ifdef ENABLE_PRTYPES
/** Allow PRTYPES to be used */
#   define ALLOW_HEADER_PRTYPES_H   1
#endif
#ifdef ENABLE_XNU_DATATYPES
/** Allow XNU datatypes to be used */
#   define ALLOW_XNU_DATATYPES_H   1
#endif
#ifdef DISABLE_ANSI_SGR
/** Disable ANSI SGR features and macros used in some functions */
#   define DISABLE_ANSI_SGR   1
#endif

/** @} */  // }


// GNU, POSIX, XOPEN, & OTHER EXTENSIONS

/** @defgroup GNU_POSIX_XOPEN_and_Other_Extensions Macros for setting, tweaking, and enabling/disabling various library extensions and features
@{ */  // (FB){

/** Define to 1 to enable a few rarely used encodings */
#define ENABLE_EXTRA   1
/** @def _ALL_SOURCE
Enable AIX 3 & Interix extensions */
#ifndef _ALL_SOURCE
#   define _ALL_SOURCE   1
#endif
/** @def __EXTENSIONS__
Enable general Solaris extensions */
#ifndef __EXTENSIONS__
#   define __EXTENSIONS__   1
#endif
/** @def _TANDEM_SOURCE
Enable HP NonStop extensions */
#ifndef _TANDEM_SOURCE
#   define _TANDEM_SOURCE   1
#endif
/** @def __USE_ISOC95
This is to enable the ISO C95 extensions */
#if IS_STDC95
#   define __USE_ISOC95   1
#endif
/** @def __USE_ISOC99
This is to enable the ISO C99 extensions */
#if IS_STDC99
#   define __USE_ISOC99   1
#endif
#if IS_STDC11
/** This is to enable the ISO C11 extensions */
#   define __USE_ISOC11   1
#endif
#if IS_STDC17
/** This is to enable the ISO C17 extensions */
#   define __USE_ISOC17   1
#endif
/** @def _DEFAULT_SOURCE
`_BSD_SOURCE` and `_SVID_SOURCE` are deprecated aliases for `_DEFAULT_SOURCE` */
#if (defined(_BSD_SOURCE) || defined(_SVID_SOURCE))
#   undef _DEFAULT_SOURCE
#   define _DEFAULT_SOURCE   1
#endif
/** @def _POSIX_SOURCE
Special POSIX macro that is used to include POSIX functionality */
/** @def _POSIX_C_SOURCE
Special POSIX macro used to include POSIX functionality */
#ifndef _GNU_SOURCE  // If `_GNU_SOURCE` was defined by the user, turn on all the other features
#   ifdef OSPOSIX
#      undef _POSIX_SOURCE
#      undef _POSIX_C_SOURCE
#      define _POSIX_SOURCE   (201712L)
#      define _POSIX_C_SOURCE   (201712L)
#   endif
#   ifdef OSUNIX
#      define _XOPEN_SOURCE   (700)
#      define _XOPEN_VERSION   (700)
#      define _XOPEN_SOURCE_EXTENDED
#   endif
#else
#   undef _ISOC95_SOURCE
#   define _ISOC95_SOURCE   1
#   undef _ISOC99_SOURCE
#   define _ISOC99_SOURCE   1
#   undef _ISOC11_SOURCE
#   define _ISOC11_SOURCE   1
#   undef _POSIX_SOURCE
#   define _POSIX_SOURCE   1
#   undef _POSIX_C_SOURCE
#   define _POSIX_C_SOURCE   (201712L)
#   undef _XOPEN_SOURCE
#   define _XOPEN_SOURCE   (700)
#   undef _XOPEN_SOURCE_EXTENDED
#   define _XOPEN_SOURCE_EXTENDED   1
#   undef _LARGEFILE64_SOURCE
#   define _LARGEFILE64_SOURCE   1
#   undef _DEFAULT_SOURCE
#   define _DEFAULT_SOURCE   1
#   undef _ATFILE_SOURCE
#   define _ATFILE_SOURCE   1
#   undef __USE_GNU
/** Adds features for ISO C89, ISO C99, POSIX.1, POSIX.2, BSD, SVID, X/Open, LFS, and GNU extensions */
#   define __USE_GNU   1
#endif
// If nothing (other than `_GNU_SOURCE` and `_DEFAULT_SOURCE`) is defined, then define `_DEFAULT_SOURCE`
#if (defined(_DEFAULT_SOURCE) || (IS_NOT_STRICT_ANSI && ((!(defined(_ISOC99_SOURCE)) || defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) || defined(_XOPEN_SOURCE)))))
#   undef _DEFAULT_SOURCE
#   define _DEFAULT_SOURCE   1
#endif
// If none of the ANSI nor POSIX macros are defined or if `_DEFAULT_SOURCE` is defined, then use POSIX.1-2017
#ifdef _DEFAULT_SOURCE
#   if ((!defined(_POSIX_SOURCE)) && (!defined(_POSIX_C_SOURCE)))
#      define __USE_POSIX_IMPLICITLY   1
#   endif
#   undef _POSIX_SOURCE
#   define _POSIX_SOURCE   1
#   undef _POSIX_C_SOURCE
#   define _POSIX_C_SOURCE   (201712L)
#endif

// POSIX Specification

#if ((IS_NOT_STRICT_ANSI || (defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE - 0) >= 500)) && (!defined(_POSIX_SOURCE)) && (!defined(_POSIX_C_SOURCE)))
#   define _POSIX_SOURCE   1
#   if (defined(_XOPEN_SOURCE) && ((_XOPEN_SOURCE - 0) < 700))
#      define _POSIX_C_SOURCE   (200809L)
#   else
#      define _POSIX_C_SOURCE   (201712L)
#   endif
#   define __USE_POSIX_IMPLICITLY   1
#endif
#if (defined(_POSIX_SOURCE) || (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 1)) || defined(_XOPEN_SOURCE))
#   define __USE_POSIX   1
#endif
#if (defined(_POSIX_SOURCE) || (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 2)) || defined(_XOPEN_SOURCE))
#   define __USE_POSIX2   1
#endif
#if ((defined(_POSIX_C_SOURCE) && ((_POSIX_C_SOURCE - 0) >= 200809L)) & (!defined(__USE_POSIX199309)) && (!defined(__USE_POSIX199506)))
#   define __USE_XOPEN2K8   1
#   undef _ATFILE_SOURCE
#   define _ATFILE_SOURCE   1
#else
#   error   "This library requires `_POSIX_C_SOURCE` to be at least `200809`!"
#endif
#ifndef _POSIX_VERSION
#   define _POSIX_VERSION   _POSIX_C_SOURCE
#endif
#ifndef _POSIX2_VERSION
#   define _POSIX2_VERSION   _POSIX_C_SOURCE
#endif
#ifndef __POSIX_VISIBLE
#   define __POSIX_VISIBLE   _POSIX_C_SOURCE
#endif
#define _POSIX2_C_BIND   (200112L)
#define _POSIX2_C_DEV   (200112L)
#define _POSIX2_CHAR_TERM   (200112L)
#define _POSIX2_FORT_DEV   (-1)
#define _POSIX2_FORT_RUN   (200112L)
#define _POSIX2_LOCALEDEF   (200112L)
#define _POSIX2_PBS   (-1)
#define _POSIX2_PBS_ACCOUNTING   (-1)
#define _POSIX2_PBS_CHECKPOINT   (-1)
#define _POSIX2_PBS_LOCATE   (-1)
#define _POSIX2_PBS_MESSAGE   (-1)
#define _POSIX2_PBS_TRACK   (-1)
#define _POSIX2_SW_DEV   (200112L)
#define _POSIX2_UPE   (200112L)
#define _POSIX_ADVISORY_INFO   (-1)
#define _POSIX_ASYNCHRONOUS_IO   (-1)
#define _POSIX_BARRIERS   (-1)
#define _POSIX_CHOWN_RESTRICTED   (200112L)
#define _POSIX_CLOCK_SELECTION   (-1)
#define _POSIX_CPUTIME   (200809L)
#define _POSIX_FSYNC   (200112L)
#define _POSIX_IPV6   (200112L)
#define _POSIX_JOB_CONTROL   (200112L)
#define _POSIX_MAPPED_FILES   (200809L)
#define _POSIX_MEMLOCK   (-1)
#define _POSIX_MEMLOCK_RANGE   (-1)
#define _POSIX_MEMORY_PROTECTION   (200809L)
#define _POSIX_MESSAGE_PASSING   (-1)
#define _POSIX_MONOTONIC_CLOCK   (200809L)
#define _POSIX_NO_TRUNC   (200112L)
#define _POSIX_PRIORITIZED_IO   (-1)
#define _POSIX_PRIORITY_SCHEDULING   (-1)
#define _POSIX_RAW_SOCKETS   (-1)
#define _POSIX_READER_WRITER_LOCKS   (200112L)
#define _POSIX_REALTIME_SIGNALS   (200809L)
#define _POSIX_REGEXP   (200112L)
#define _POSIX_SAVED_IDS   (200112L)
#define _POSIX_SEMAPHORES   (200112L)
#define _POSIX_SHARED_MEMORY_OBJECTS   (-1)
#define _POSIX_SHELL   (200112L)
#define _POSIX_SPAWN   (-1)
#define _POSIX_SPIN_LOCKS   (-1)
#define _POSIX_SPORADIC_SERVER   (-1)
#define _POSIX_SYNCHRONIZED_IO   (-1)
#define _POSIX_THREAD_ATTR_STACKADDR   (200112L)
#define _POSIX_THREAD_ATTR_STACKSIZE   (200809L)
#define _POSIX_THREAD_CPUTIME   (200809L)
#define _POSIX_THREAD_PRIO_INHERIT   (-1)
#define _POSIX_THREAD_PRIO_PROTECT   (-1)
#define _POSIX_THREAD_PRIORITY_SCHEDULING   (-1)
#define _POSIX_THREAD_PROCESS_SHARED   (200809L)
#define _POSIX_THREAD_SAFE_FUNCTIONS   (200112L)
#define _POSIX_THREAD_SPORADIC_SERVER   (-1)
#define _POSIX_THREADS   (200112L)
#define _POSIX_TIMEOUTS   (-1)
#define _POSIX_TIMERS   (200809L)
#define _POSIX_TRACE   (-1)
#define _POSIX_TRACE_EVENT_FILTER   (-1)
#define _POSIX_TRACE_INHERIT   (-1)
#define _POSIX_TRACE_LOG   (-1)
#define _POSIX_TYPED_MEMORY_OBJECTS   (-1)

// XOPEN Specification

#ifdef _XOPEN_SOURCE
/** @def _XOPEN_SOURCE
Special UNIX macro used to include functionality described in the X/Open Portability Guide */
/** @def _XOPEN_VERSION
Special UNIX macro used to include functionality described in the X/Open Portability Guide */
/** @def _XOPEN_SOURCE_EXTENDED
Special UNIX macro used to include extra functionality described in the X/Open Portability Guide */
#   define __USE_XOPEN   1
#   if ((_XOPEN_SOURCE - 0) >= 500)
#      define __USE_XOPEN_EXTENDED   1
#      define __USE_UNIX98   1
#      undef _LARGEFILE_SOURCE
#      define _LARGEFILE_SOURCE   1
#      if ((_XOPEN_SOURCE - 0) >= 600)
#         if ((_XOPEN_SOURCE - 0) >= 700)
#            define __USE_XOPEN2K8   1
#            define __USE_XOPEN2K8XSI   1
#         endif
#         define __USE_XOPEN2K   1
#         define __USE_XOPEN2KXSI   1
#         undef __USE_ISOC95
#         define __USE_ISOC95      1
#         undef __USE_ISOC99
#         define __USE_ISOC99      1
#      endif
#   else
#      ifdef _XOPEN_SOURCE_EXTENDED
#         define __USE_XOPEN_EXTENDED   1
#      endif
#   endif
#   ifndef __XSI_VISIBLE
#      if ((_XOPEN_SOURCE - 0) >= 700)
#         define __XSI_VISIBLE   700
#      elif ((_XOPEN_SOURCE - 0) >= 600)
#         define __XSI_VISIBLE   600
#      elif ((_XOPEN_SOURCE - 0) >= 500)
#         define __XSI_VISIBLE   500
#      endif
#   endif
#endif  // _XOPEN_SOURCE
#if (defined(_POSIX_VERSION) && (_POSIX_VERSION > 0))
#   define _XOPEN_CRYPT   1
#   define _XOPEN_ENH_I18N   1
#   define _XOPEN_SHM   1
#   define _XOPEN_UNIX   1
#   define _XOPEN_XPG2   1
#   define _XOPEN_XPG3   1
#   define _XOPEN_XPG4   1
#endif
#ifndef _XOPEN_LEGACY
#   define _XOPEN_LEGACY   (-1)
#endif
#ifndef _XOPEN_REALTIME
#   define _XOPEN_REALTIME   (-1)
#endif
#ifndef _XOPEN_REALTIME_THREADS
#   define _XOPEN_REALTIME_THREADS   (-1)
#endif
#ifndef _XOPEN_STREAMS
#   define _XOPEN_STREAMS   (-1)
#endif
#ifndef __XPG_VISIBLE
#   define __XPG_VISIBLE   (700)
#endif

// BSD Specifications

#define BSD   (199506)
/** BSD 4.3 Compliant */
#define BSD4_3   1
/** BSD 4.4 Compliant */
#define BSD4_4   1
/** NeXTBSD version (year, month, release) */
#define NeXTBSD   (1995064)
/** NeXTBSD 4.0 */
#define NeXTBSD4_0   0
#ifndef __BSD_VISIBLE
#   define __BSD_VISIBLE   1
#endif

// Darwin Specifications

/** @def __DARWIN_C_ANSI
Darwin extensions */
#ifndef __DARWIN_C_ANSI
#   define __DARWIN_C_ANSI   (010000L)
#endif
/** @def __DARWIN_C_FULL
Darwin extensions */
#ifndef __DARWIN_C_FULL
#   define __DARWIN_C_FULL   (900000L)
#endif
#ifdef _ANSI_SOURCE
#   define __DARWIN_C_LEVEL   __DARWIN_C_ANSI
#elif (defined(_POSIX_C_SOURCE) && (!defined(_DARWIN_C_SOURCE)) && (!defined(_NONSTD_SOURCE)))
#   define __DARWIN_C_LEVEL   _POSIX_C_SOURCE
#else
#   define __DARWIN_C_LEVEL   __DARWIN_C_FULL
#endif
#ifdef __DARWIN_ONLY_VERS_1050
/** Indicates that only those APIs updated in 10.5 exists; no pre-10.5 variants are available */
#   define _DARWIN_FEATURE_ONLY_VERS_1050   1
#endif
#if (defined(__DARWIN_ONLY_UNIX_CONFORMANCE) || (!defined(_DARWIN_FEATURE_ONLY_UNIX_CONFORMANCE)))
/** Indicates only UNIX conforming API are available (the legacy BSD APIs are not available) */
#   define _DARWIN_FEATURE_ONLY_UNIX_CONFORMANCE   1
#endif
#if (defined(__DARWIN_UNIX03) || (!defined(_DARWIN_FEATURE_UNIX_CONFORMANCE)))
/** Indicates whether UNIX conformance is on and specifies the conformance level (3 is SUSv3) */
#   define _DARWIN_FEATURE_UNIX_CONFORMANCE   3
#endif
#if (IS_STRICT_ANSI && ((__STDC_VERSION__ - 0) < 199901L) && (!defined(__GNUG__)))
#   define __DARWIN_NO_LONG_LONG   1
#endif
#ifndef __DARWIN_64_BIT_INO_T
#   if ((defined(__INO_T_MATCHES_INO64_T) && (__INO_T_MATCHES_INO64_T > 0)) || (defined(__OFF_T_MATCHES_OFF64_T) && (__OFF_T_MATCHES_OFF64_T > 0)))
#      define __DARWIN_64_BIT_INO_T   1
#   else
#      define __DARWIN_64_BIT_INO_T   SUPPORTS_LARGEFILE64
#   endif
#endif
#ifndef DARWIN_64_BIT_INO_T
#   define DARWIN_64_BIT_INO_T   __DARWIN_64_BIT_INO_T
#endif
#ifndef __DARWIN_ONLY_64_BIT_INO_T
#   define __DARWIN_ONLY_64_BIT_INO_T   DARWIN_64_BIT_INO_T
#endif
#if DARWIN_64_BIT_INO_T
/** Indicates that the ino_t type is 64-bit and structures modified for 64-bit inodes (like struct stat) will be used */
#   define _DARWIN_FEATURE_64_BIT_INODE   1
/** Indicates that the ino_t type may only be 64-bit; there is no support for 32-bit ino_t when this macro is defined (and non-zero); There is no struct stat64 either, as the regular struct stat will already be the 64-bit version */
#   define _DARWIN_FEATURE_ONLY_64_BIT_INODE   1
#endif

#ifndef __ISO_C_VISIBLE
#   define __ISO_C_VISIBLE   (2017)
#endif
#ifndef __BIONIC__
#   define __BIONIC__   1
#endif
#ifdef _LARGEFILE_SOURCE
#   define __USE_LARGEFILE   1
#endif
#ifdef _LARGEFILE64_SOURCE
#   define __USE_LARGEFILE64   1
#   define _FILE_OFFSET_BITS   64
#endif
#if (defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64))
#   define __USE_FILE_OFFSET64   1
#endif
#ifndef USE_FILE_OFFSET64
#   define USE_FILE_OFFSET64   __USE_FILE_OFFSET64
#endif
#ifdef __USE_FILE_OFFSET64
#   define __USE_LARGEFILE   1
#   define __USE_LARGEFILE64   1
#endif
/** @def SUPPORTS_LARGEFILE64
Indicates support for a 64-bit I/O interface, which allows large files and large file I/O; LFS symbols are also enabled */
#if (defined(_LARGEFILE64_SOURCE) || defined(__USE_LARGEFILE64) || defined(__USE_FILE_OFFSET64))
#   define SUPPORTS_LARGEFILE64   1
#else
#   define SUPPORTS_LARGEFILE64   0
#endif
#if (defined(_DEFAULT_SOURCE) && (!defined(__USE_MISC)))
#   define __USE_MISC   1
#endif
#if (defined(_ATFILE_SOURCE) && (!defined(__USE_ATFILE)))
#   define __USE_ATFILE   1
#endif
/** @def _FORTIFY_SOURCE
Adds lightweight checks (if value above 0) that detect some buffer overflow errors */
#ifndef _FORTIFY_SOURCE
#   define _FORTIFY_SOURCE   1
#elif (defined(COMPILER_MINGW) || (defined(OSWINDOWS) && ((!defined(_FORTIFY_SOURCE)) || (_FORTIFY_SOURCE != 0))))
#   define _FORTIFY_SOURCE   0  // Fix bug in MingW
#endif
/** @def __USE_FORTIFY_LEVEL
Adds code that detects buffer-overflow errors (if value above 0) */
#if (defined(_FORTIFY_SOURCE) && (_FORTIFY_SOURCE > 0) && defined(__OPTIMIZE__) && (__OPTIMIZE__ > 0))
#   if (_FORTIFY_SOURCE > 1)
#      define __USE_FORTIFY_LEVEL   2
#   else
#      define __USE_FORTIFY_LEVEL   1
#   endif
#else
#   define __USE_FORTIFY_LEVEL   0
#endif
#if (defined(OPT_CODE) && (!defined(OPT_SIZE)) && (!defined(__NO_INLINE__)) && defined(extern_inline))
/** Indicates whether 'extern inline' is defined for functions in headers */
#   define __USE_EXTERN_INLINES   1
#endif
/** @def __BIONIC_FORTIFY
Adds lightweight checks (if value above 0) that detect some buffer overflow errors */
#if ((defined(_FORTIFY_SOURCE) && (_FORTIFY_SOURCE > 0)) && IS_OPT_OVER_0)
#   define __BIONIC_FORTIFY   1
#else
#   define __BIONIC_FORTIFY   0
#endif
#ifdef __BIONIC_FORTIFY
#   define BIONIC_FORTIFY   __BIONIC_FORTIFY
#endif

/** @} */  // }


// POSIX MANDATED VALUES

/** @defgroup POSIX_Mandated_Values Macros used to store various limits and properties required by POSIX
@{ */  // (FB){

// POSIX.1 MANDATED VALUES (<bits/posix1_lim.h>)

/** Number of files one process can have open at once */
#define _POSIX_OPEN_MAX   20
/** FOPEN_MAX is a minimum maximum, and is the number of streams that stdio can provide without attempting to allocate further resources (which could fail) */
#define FOPEN_MAX   _POSIX_OPEN_MAX  // Must be <= OPEN_MAX
#define OPEN_MAX   _POSIX_OPEN_MAX
/** Number of bytes in a pathname */
#define _POSIX_PATH_MAX   256
#ifndef MAXNAMLEN
#   define MAXNAMLEN   (_POSIX_PATH_MAX - 1)
#endif
/** Maximum number of chars in a filename */
#define NAME_MAX   MAXNAMLEN
/** @def MAXPATHLEN
POSIX 1003.1 maximum path length; MAXPATHLEN defines the longest permissable path length after expanding symbolic links; It is used to allocate a temporary buffer from the buffer pool in which to do the name expansion, hence should be a power of two, and must be less than or equal to MAXBSIZE */
/** @def PATH_MAX
Number of chars in a path name including NUL */
#ifdef _POSIX_SOURCE
#   ifndef MAXPATHLEN
#      define MAXPATHLEN   4096
#   endif
#   ifndef PATH_MAX
#      define PATH_MAX   MAXPATHLEN
#   endif
#else
#   ifndef MAXPATHLEN
#      define MAXPATHLEN   1024
#   endif
#   ifndef PATH_MAX
#      define PATH_MAX   MAXPATHLEN
#   endif
#endif
#ifndef _POSIX_FD_SETSIZE
/** Number of descriptors that a process may examine with `pselect` or `select` */
#   define _POSIX_FD_SETSIZE   _POSIX_OPEN_MAX
#endif
#define MAX_ADDR_LEN   7
#define MAXLOGNAME   255
/** Minimum number of operations in one list I/O call */
#define _POSIX_AIO_LISTIO_MAX   2
/** Minimum number of operations in one list I/O call */
#define _POSIX_AIO_LIST_MAX   _POSIX_AIO_LISTIO_MAX
/** Minimum number of operations in one list I/O call */
#define AIO_LIST_MAX   _POSIX_AIO_LISTIO_MAX
/** Minimal number of outstanding asynchronous I/O operations */
#define _POSIX_AIO_MAX   1
/** Minimal number of outstanding asynchronous I/O operations */
#define AIO_MAX   _POSIX_AIO_MAX
#define AIO_PRIO_DELTA_MAX   0
/** Maximum length of arguments to `execve`, including environment */
#define _POSIX_ARG_MAX   4096
/** Minimal number of timer expiration overruns */
#define _POSIX_DELAYTIMER_MAX   32
/** Minimal number of timer expiration overruns */
#define DELAYTIMER_MAX   _POSIX_DELAYTIMER_MAX
/** Maximum length of a hostname (excluding terminating null) as returned from the GETHOSTNAME function */
#define _POSIX_HOST_NAME_MAX   255
/** Maximum link count of a file */
#define _POSIX_LINK_MAX   8
/** Maximum length of login name */
#define _POSIX_LOGIN_NAME_MAX   9
/** Number of bytes in a terminal canonical input queue */
#define _POSIX_MAX_CANON   255
/** Number of bytes for which space will be available in a terminal input queue */
#define _POSIX_MAX_INPUT   255
/** Maximum number of message queues open for a process */
#define _POSIX_MQ_OPEN_MAX   8
/** Maximum number of supported message priorities */
#define _POSIX_MQ_PRIO_MAX   32
/** Number of bytes in a filename */
#define _POSIX_NAME_MAX   14
/** Number of simultaneous supplementary group IDs per process */
#define _POSIX_NGROUPS_MAX   8
#ifndef NGROUPS_MAX
/** Supplemental group IDs are available */
#   define NGROUPS_MAX   _POSIX_NGROUPS_MAX
#endif
/** Maximum simultaneous processes per real user ID */
#define _POSIX_CHILD_MAX   25
/** Number of bytes than can be written atomically to a pipe */
#define _POSIX_PIPE_BUF   512
/** The number of repeated occurrences of a BRE permitted by the REGEXEC and REGCOMP functions when using the interval notation */
#define _POSIX_RE_DUP_MAX   255
/** Minimal number of realtime signals reserved for the application */
#define _POSIX_RTSIG_MAX   8
/** Number of semaphores a process can have */
#define _POSIX_SEM_NSEMS_MAX   256
/** Maximal value of a semaphore */
#define _POSIX_SEM_VALUE_MAX   32767
/** Number of pending realtime signals */
#define _POSIX_SIGQUEUE_MAX   32
/** Number of pending realtime signals */
#define SIGQUEUE_MAX   _POSIX_SIGQUEUE_MAX
/** Number of streams a process can have open at once */
#define _POSIX_STREAM_MAX   8
/** The number of bytes in a symbolic link */
#define _POSIX_SYMLINK_MAX   255
/** The number of symbolic links that can be traversed in the resolution of a pathname in the absence of a loop */
#define _POSIX_SYMLOOP_MAX   8
/** Number of timer for a process */
#define _POSIX_TIMER_MAX   32
/** Maximum number of characters in a tty name */
#define _POSIX_TTY_NAME_MAX   9
/** Maximum length of a timezone name (element of `tzname`) */
#define _POSIX_TZNAME_MAX   6
/** Maximum number of connections that can be queued on a socket */
#define _POSIX_QLIMIT   1
/** Maximum number of bytes that can be buffered on a socket for send or receive */
#define _POSIX_HIWAT   _POSIX_PIPE_BUF
/** Maximum number of elements in an `iovec` array */
#define _POSIX_UIO_MAXIOV   16
/** Maximum clock resolution in nanoseconds */
#define _POSIX_CLOCKRES_MIN   20000000
#define _POSIX_THREAD_DESTRUCTOR_ITERATIONS   4

// POSIX.2 MANDATED VALUES (<bits/posix2_lim.h>)

/** The maximum `ibase` and `obase` values allowed by the `bc` utility */
#define _POSIX2_BC_BASE_MAX   99
/** The maximum number of elements allowed in an array by the `bc` utility */
#define _POSIX2_BC_DIM_MAX   2048
/** The maximum `scale` value allowed by the `bc` utility */
#define _POSIX2_BC_SCALE_MAX   99
/** The maximum length of a string constant accepted by the `bc` utility */
#define _POSIX2_BC_STRING_MAX   1000
/** The maximum number of weights that can be assigned to an entry of the LC_COLLATE `order` keyword in the locale definition file */
#define _POSIX2_COLL_WEIGHTS_MAX   2
/** The maximum number of expressions that can be nested within parentheses by the `expr` utility */
#define _POSIX2_EXPR_NEST_MAX   32
/** The maximum length, in bytes, of an input line */
#define _POSIX2_LINE_MAX   2048
/** POSIX 1003.2 RE length limit; The maximum number of repeated occurrences of a regular expression permitted when using the interval notation `\{M,N\}` */
#define _POSIX2_RE_DUP_MAX   255
/** The maximum number of bytes in a character class name; There is no fixed limit */
#define _POSIX2_CHARCLASS_NAME_MAX   14
/** This value is defined like this in regex.h */
#define RE_DUP_MAX   0x7fff
// These values are implementation-specific, and may vary within the implementation
#ifndef BC_BASE_MAX
/** Maximum obase values allowed by the bc utility */
#   define BC_BASE_MAX   _POSIX2_BC_BASE_MAX
#endif
#ifndef BC_DIM_MAX
/** Maximum number of elements permitted in an array by the bc utility */
#   define BC_DIM_MAX   _POSIX2_BC_DIM_MAX
#endif
#ifndef BC_SCALE_MAX
#   define BC_SCALE_MAX   _POSIX2_BC_SCALE_MAX
#endif
#ifndef BC_STRING_MAX
#   define BC_STRING_MAX   _POSIX2_BC_STRING_MAX
#endif
#ifndef COLL_WEIGHTS_MAX
#   define COLL_WEIGHTS_MAX   _POSIX2_COLL_WEIGHTS_MAX
#endif
#ifndef EXPR_NEST_MAX
#   define EXPR_NEST_MAX   _POSIX2_EXPR_NEST_MAX
#endif
#ifndef LINE_MAX
#   define LINE_MAX   _POSIX2_LINE_MAX
#endif
#ifndef CHARCLASS_NAME_MAX
#   define CHARCLASS_NAME_MAX   _POSIX2_CHARCLASS_NAME_MAX
#endif

/** @} */  // }


// SUS REQUIREMENTS

/** @defgroup SUS_Requirements Macros used to store various limits and properties required by SUS
@{ */  // (FB){

/** The number of replenishment operations that may be simultaneously pending for a particular sporadic server scheduler */
#define _POSIX_SS_REPL_MAX   4
/** The number of data keys per process */
#define _POSIX_THREAD_KEYS_MAX   128
#define _POSIX_THREAD_THREADS_MAX   64
#define _POSIX_TRACE_EVENT_NAME_MAX   30
#define _POSIX_TRACE_NAME_MAX   8
#define _POSIX_TRACE_SYS_MAX   8
#define _POSIX_TRACE_USER_EVENT_MAX   32
/** Minimal requirement of SUSv2 */
#define WCIO_UNGETWC_BUFSIZE   1

/** @} */  // }


// LIMITS FOR X/OPEN PORTABILITY (<bits/xopen_lim.h>)

/** @defgroup XOPEN_Limits Macros used to store various limits and properties required by XOPEN for Portability
@{ */  // (FB){

/** Maximum number of bytes in a filename (not including the terminating null of a filename string) */
#define _XOPEN_NAME_MAX   255
/** Minimum number the implementation will accept as the maximum number of bytes in a pathname */
#define _XOPEN_PATH_MAX   1024
/** Maximum number of iovec structures that one process has available for use with `readv()` or `writev()` */
#define IOV_MAX   1024
/** Maximum number of `iovec` structures that one process has available for use with `readv()` or writev()` */
#define _XOPEN_IOV_MAX   16
/** Maximum value of `digit` in calls to the `printf()` and `scanf()` functions */
#define NL_ARGMAX   _POSIX_ARG_MAX
/** Maximum number of bytes in a `LANG` name */
#define NL_LANGMAX   _POSIX2_LINE_MAX
/** Maximum number of messages per set */
#define NL_MGSMAX   1024
/** Maximum number of bytes in a message */
#define NL_TEXTMAX   1024
/** Default process priority (nice value) */
#define NZERO   20
/** @def _POSIX_VDISABLE
POSIX 1003.1 tty disabling character; On some systems, `_POSIX_VDISABLE` is `\\377` since Ultrix does not honor `_POSIX_VDISABLE` (treats it as `^@`); The symptom is that the `^@` keystroke immediately drops the core */
#ifdef HAVE_BROKEN_VDISABLE
#   undef _POSIX_VDISABLE
#   define _POSIX_VDISABLE   ((unsigned char)'\377')
#else
#   define _POSIX_VDISABLE   -1
#endif

/** @} */  // }


// LINUX LIMITS

/** @defgroup Linux_Limits Macros used to store various limits and properties required by Linux
@{ */  // (FB){

#ifndef RAND_MAX
/** The largest number rand will return (same as `INT_MAX`) */
#   define RAND_MAX   (INT_MAX)
#endif
#define NR_OPEN   1024
#define NLIMITS   6
/** Maximum number of bytes of args + environ for `exec()` */
#define ARG_MAX   131072
#ifndef NCARGS
/** Max bytes for an exec function */
#   define NCARGS   ARG_MAX
#endif
/** Maximum number of links a file may have */
#define LINK_MAX   _POSIX_SYMLINK_MAX
/** Maximum number of links a file may have */
#define SYMLINK_MAX   _POSIX_SYMLINK_MAX
#define SYMLOOP_MAX   _POSIX_SYMLOOP_MAX
#ifndef MAXSYMLINKS
/** MAXSYMLINKS defines the maximum number of symbolic links that may be expanded in a pathname; It should be set high enough to allow all legitimate uses, but halt infinite loops reasonably quickly */
#   define MAXSYMLINKS   32
#endif
/** Size of the canonical input queue */
#define MAX_CANON   255
/** Size of the type-ahead buffer */
#define MAX_INPUT   _POSIX_MAX_INPUT
/** Number of bytes in atomic write to a pipe */
#define PIPE_BUF   _POSIX_PIPE_BUF
/** Number of chars in an extended attribute name */
#define XATTR_NAME_MAX   255
/** Size of an extended attribute value (64k) */
#define XATTR_SIZE_MAX   65536
/** Size of extended attribute namelist (64k) */
#define XATTR_LIST_MAX   65536
#define RTSIG_MAX   32
#define FILESIZEBITS   64
#define WORD_BIT   32
#define TZNAME_MAX   _POSIX_TZNAME_MAX
#define TTY_NAME_MAX   _POSIX_TTY_NAME_MAX
#define HOST_NAME_MAX   _POSIX_HOST_NAME_MAX
#define PTHREAD_KEYS_MAX   32
#define PTHREAD_STACK_MIN   2048
#define PTHREAD_DESTRUCTOR_ITERATIONS   1
#define SEM_VALUE_MAX   0x7fffffff
#define SEM_NSEMS_MAX   256
#ifndef DELAYTIMER_MAX
#   define DELAYTIMER_MAX   0x7fffffff
#endif
#define MQ_PRIO_MAX   32768
#define LOGIN_NAME_MAX   _POSIX_LOGIN_NAME_MAX
#ifndef MAXDOMNAMELEN
/** Maximum domain name length */
#   define MAXDOMNAMELEN   255
#endif
#ifndef MAXHOSTNAMELEN
/** Max hostname size */
#   define MAXHOSTNAMELEN   255
#endif
#ifndef HOST_NAME_MAX
#   define HOST_NAME_MAX   MAXHOSTNAMELEN
#endif
#ifndef NGROUPS
/** Max number groups */
#   define NGROUPS   32
#endif
#ifndef NGROUPS_MAX
/** Max number groups */
#   define NGROUPS_MAX   32
#endif
#ifndef NOGROUP
/** Marker for empty group set member */
#   define NOGROUP   65535
#endif
#ifndef CANBSIZE
#   define CANBSIZE   255
#endif
#ifndef NOFILE
/** Default max open files per process */
#   define NOFILE   256
#endif
#ifndef DEV_BSIZE
/** Unit of `st_blocks`; All (or most) references to `DEV_BSIZE` are for NetBSD's file images */
#   define DEV_BSIZE   512
#endif
#ifndef NODEV
/** Non-existent device */
#   define NODEV   ((dev_t)-1)
#endif
/** Max command name remembered */
#define MAXCOMLEN   16
/** Max interpreter filename length */
#define MAXINTERP   64
/** Max simultaneous processes */
#define MAXUPRC   CHILD_MAX
/** ORed with pri for tsleep to check signals */
#define PCATCH   0x100
/** For tty SIGTTOU and SIGTTIN blocking */
#define PTTYBLOCK   0x200
/** ORed with pri to stop re-aquistion of mutex upon wakeup */
#define PDROP   0x400
/** ORed with pri to require mutex in spin mode upon wakeup */
#define PSPIN   0x800
/** Default file mask: S_IWGRP|S_IWOTH */
#define CMASK   022
#define MAXBSIZE   1048576
#define MAXPHYSIO   MAXPHYS
#define MAXFRAG   8
#define MAXPHYSIO_WIRED   16777216
/** MINBUCKET is the smallest unit of memory that will be allocated; It must be at least large enough to hold a pointer */
#define MINBUCKET   4
#define FSHIFT   11
#define FSCALE   0x800
#define LIM_NORAISE   0
/** Max secs cpu time */
#define LIM_CPU   1
/** Max size of file created */
#define LIM_FSIZE   2
/** Max growth of data space */
#define LIM_DATA   3
/** Max growth of stack */
#define LIM_STACK   4
/** Max size of `core` file */
#define LIM_CORE   5
/** Max desired data+stack core usage */
#define LIM_MAXRSS   6
// Priorities; Note that with 32 run queues, differences less than 4 are insignificant
#define PSWP   0
#define PVM   4
#define PINOD   8
#define PRIBIO   16
#define PVFS   20
#define PZERO   22
#define PSOCK   24
#define PWAIT   32
#define PLOCK   36
#define PPAUSE   40
#define PUSER   50
#define MAXPRI   127
#define PRIMASK   0xff

/** @} */  // }


// POSIX & UNIX I/O ENUMS & MACROS

#define F_LINUX_SPECIFIC_BASE   1024

/** @defgroup STDIO_Buffer_Sizes STDIO Buffer Sizes
@{ */  // (FB){

/** @def BUFSIZ
Size of the STDIO buffers */
#ifndef BUFSIZ
#   if (defined(WANT_SMALL_STDIO_BUFS) || defined(SMALL_STDIO_BUFS))
#      define BUFSIZ   128
#   elif (defined(WANT_LARGE_STDIO_BUFS) || defined(LARGE_STDIO_BUFS))
#      define BUFSIZ   2048
#   else
#      define BUFSIZ   1024
#   endif
#endif  // BUFSIZ
#ifndef BUFSIZE
/** Size of the STDIO buffers */
#      define BUFSIZE   BUFSIZ
#endif
#ifndef __STDIO_BUFSIZ
/** Size of the STDIO buffers */
#   define __STDIO_BUFSIZ   BUFSIZ
#endif
#ifndef UNGET
#   define UNGET   8
#endif

/** @} */  // }

#ifndef S_BLKSIZE
/** Block size for `st_blocks` */
#   define S_BLKSIZE   512
#endif
#ifndef UTIME_NOW
#   define UTIME_NOW   0x3fffffffL
#endif
#ifndef UTIME_OMIT
#   define UTIME_OMIT   0x3ffffffeL
#endif
#if (defined(OSNETBSD) || defined(OSMINIX))
#   define SF_APPEND   0x40000
#   define SF_ARCHIVED   0x10000
#   define SF_IMMUTABLE   0x20000
#   define SF_SETTABLE   0xffff0000
#   define UF_APPEND   4
#   define UF_IMMUTABLE   2
#   define UF_NODUMP   1
#   define UF_OPAQUE   8
#   define UF_SETTABLE   UINT16_MAX
#endif
#define F_OWNER_TID   0
#define F_OWNER_PID   1
#define F_OWNER_PGRP   2
#define F_OWNER_GID   2
#define FALLOC_FL_KEEP_SIZE   1
#define FALLOC_FL_PUNCH_HOLE   2
#define F_NOTIFY   1026
#define F_CANCELLK   1029
#define F_SETPIPE_SZ   1031
#define F_GETPIPE_SZ   1032
/** Return (as the function result) the current set of seals of the inode referred to by the file descriptor */
#define F_ADD_SEALS   1033
/** Add the seals given in the bit-mask argument `arg` to the set of seals of the inode referred to by the file descriptor */
#define F_GET_SEALS   1034

/** @defgroup File_Properties Macros and enums used to represent various file properties
@{ */  // (FB){

/** @defgroup File_Orientations_and_Modes Macros for file orientations & modes
@{ */  // (FB){

#define _O_BINARY   0x8000
#define _O_BYTE   -1
#define _O_NOINHERIT   0x80
#define _O_RANDOM   0x10
#define _O_RAW   _O_BINARY
#define _O_SEQUENTIAL   0x20
#define _O_SHORT_LIVED   0x1000
#define _O_TEMPORARY   0x40
#define _O_TEXT   0x4000
#define _O_U16TEXT   0x20000
#define _O_U8TEXT   0x40000
#define _O_UNCHANGED   0x0
#define _O_WIDE   1
#define _O_WTEXT   0x10000

/** @} */  // }

/** POSIX 1003.1 names for standard file descriptors */
enum STD_FD {
/** STDIN file descriptor */
	STDIN_FILENO = 0,
/** STDOUT file descriptor */
	STDOUT_FILENO = 1,
/** STDERR file descriptor */
	STDERR_FILENO = 2
};

/** File access modes */
enum FILE_MODES {
	F_OK = 0,
	X_OK = 1,
	W_OK = 2,
	R_OK = 4
};

/** Access mode flags for creating and manipulating files */
enum FILE_ACCESS_MODES {
/** Open for reading only */
	O_RDONLY = 0,
/** Open for reading only */
#   define _O_RDONLY   O_RDONLY
/** Open for writing only */
	O_WRONLY = 1,
/** Open for writing only */
#   define _O_WRONLY   O_WRONLY
/** Open for reading and writing */
	O_RDWR = 2,
/** Open for reading and writing */
#   define _O_RDWR   O_RDWR
/** Mask for above modes */
	O_ACCMODE = 3,
/** Mask for above modes */
#   define _O_ACCMODE   O_ACCMODE
/** 4.4BSD extension to atomically obtain a shared lock on a file */
	O_SHLOCK = 0x10,
/** 4.4BSD extension to atomically obtain a shared lock on a file */
#   define _O_SHLOCK   O_SHLOCK
/** 4.4BSD extension to atomically obtain an exclusive lock on a file */
	O_EXLOCK = 0x20
/** 4.4BSD extension to atomically obtain an exclusive lock on a file */
#   define _O_EXLOCK   O_EXLOCK
};

/** @defgroup File_Permissions File permission values stored in enums and macros
@{ */  // (FB){

/** Stat file permission flags */
enum STAT_FILE_PERM_FLAGS {
/** Execute by owner */
	__S_IEXEC = 0100,
/** Execute by owner */
#   define _S_IEXEC   __S_IEXEC
/** Execute by owner */
#   define S_IEXEC   __S_IEXEC
/** Execute by owner */
#   define S_IXUSR   __S_IEXEC
/** Write by owner */
	__S_IWRITE = 0200,
/** Write by owner */
#   define _S_IWRITE   __S_IWRITE
/** Write by owner */
#   define S_IWRITE   __S_IWRITE
/** Write by owner */
#   define S_IWUSR   __S_IWRITE
/** Read by owner */
	__S_IREAD = 0400,
/** Read by owner */
#   define _S_IREAD   __S_IREAD
/** Read by owner */
#   define S_IREAD   __S_IREAD
/** Read by owner */
#   define S_IRUSR   __S_IREAD
/** Read and write by owner */
	__S_IRWU = 0600,
/** Read, write, and execute by owner */
#   define _S_IRWU   __S_IRWU
/** Read, write, and execute by owner */
#   define S_IRWU   __S_IRWU
/** Read, write, and execute by owner */
	__S_IRWXU = 0700,
/** Read, write, and execute by owner */
#   define _S_IRWXU   __S_IRWXU
/** Read, write, and execute by owner */
#   define S_IRWXU   __S_IRWXU
/** Save swapped text after use (sticky bit) */
	__S_ISVTX = 01000,
/** Save swapped text after use (sticky bit) */
#   define _S_ISVTX   __S_ISVTX
/** Save swapped text after use (sticky bit) */
#   define S_ISVTX   __S_ISVTX
/** Save swapped text after use (sticky bit) */
#   define __S_ISTXT   __S_ISVTX
/** Save swapped text after use (sticky bit) */
#   define _S_ISTXT   __S_ISVTX
/** Save swapped text after use (sticky bit) */
#   define S_ISTXT   __S_ISVTX
/** Set group ID on execution */
	__S_ISGID = 02000,
/** Set group ID on execution */
#   define _S_ISGID   __S_ISGID
/** Set group ID on execution */
#   define S_ISGID   __S_ISGID
/** Set user ID on execution */
	__S_ISUID = 04000
/** Set user ID on execution */
#   define _S_ISUID   __S_ISUID
/** Set user ID on execution */
#   define S_ISUID   __S_ISUID
};
/** Read by group */
#define S_IRGRP   32
/** Write by group */
#define S_IWGRP   16
/** Read and write by group */
#define S_IRWGRP   48
/** Execute by group */
#define S_IXGRP   8
/** Read, write, and execute by group */
#define S_IRWXG   56
/** Read by others */
#define S_IROTH   4
/** Write by others */
#define S_IWOTH   2
/** Read and write by others */
#define S_IRWOTH   6
/** Execute by others */
#define S_IXOTH   1
/** Read, write, and execute by others */
#define S_IRWXO   7
/** All users can read (0222) */
#define ALL_S_IREAD   292
/** All users can write (0444) */
#define ALL_S_IWRITE   146
/** All users can read and write (0666) */
#define ALL_S_IRW   438
/** All users can read and write (0666) */
#define DEFFILEMODE   ALL_S_IRW
/** All users can execute (0111) */
#define ALL_S_IEXEC   73
/** All users can read, write, and execute (0777) */
#define ALL_S_IRWX   511
/** All users can read, write, and execute (0777) */
#define ACCESSPERMS   ALL_S_IRWX
/** All users can read, write, and execute (7777) */
#define ALLPERMS   4095
/** All the mode bits that can be affected by chmod */
#define CHMOD_MODE_BITS   ALLPERMS
#define AT_FDCWD   -100
#define AT_SYMLINK_NOFOLLOW   256
#define AT_REMOVEDIR   512
#define AT_EACCESS   512
#define AT_SYMLINK_FOLLOW   1024
#define AT_NO_AUTOMOUNT   2048
#define AT_EMPTY_PATH   4096

/** @} */  // }

/** File status flags for creating and manipulating files */
enum FILE_STATUS_FLAGS {
#   if (defined(ARCHITANIUM) || defined(ARCHS390) || defined(ARCHX86))
	O_CREAT = 0100,  //!< O_CREAT Create if nonexistent
	O_EXCL = 0200,  //!< Error if already exists
	O_NOCTTY = 0400,  //!< Do not assign controlling terminal
	O_TRUNC = 01000,  //!< Truncate to zero length
	O_APPEND = 02000,  //!< Set append mode
	O_NONBLOCK = 04000,  //!< No delay
	O_SYNC = 010000,  //!< Synchronous writes (ext2, ext3, and ext4 filesystems only)
	FASYNC = 020000,  //!< BSD compatibility
	O_DIRECT = 040000,  //!< Direct I/O hint
	O_LARGEFILE = 0100000,
	O_DIRECTORY = 0200000,  //!< Fail if not a directory
	O_NOFOLLOW = 0400000,  //!< Do not follow symlinks on the last
	O_NOATIME = 01000000,
	O_PATH = 010000000,  //!< Resolve pathname but do not open file
	O_TMPFILE = 020200000
#   elif defined(ARCHALPHA)
	O_NONBLOCK = 4,
	O_APPEND = 010,
	O_CREAT = 01000,
	O_TRUNC = 02000,
	O_EXCL = 04000,
	O_NOCTTY = 010000,
	FASYNC = 020000,
	O_SYNC = 040000,
	O_DIRECTORY = 0100000,
	O_NOFOLLOW = 0200000,
	O_LARGEFILE = 0400000,
	O_DIRECT = 02000000,
	O_NOATIME = 04000000,
	O_TMPFILE = 020040000,
	O_PATH = 040000000,
	O_TMPFILE = 0100000000
#   elif defined(ARCHARM)
	O_CREAT = 0100,
	O_EXCL = 0200,
	O_NOCTTY = 0400,
	O_TRUNC = 01000,
	O_APPEND = 02000,
	O_NONBLOCK = 04000,
	O_SYNC = 010000,
	FASYNC = 020000,
	O_DIRECTORY = 040000,
	O_NOFOLLOW = 0100000,
	O_DIRECT = 0200000,
	O_LARGEFILE = 0400000,
	O_NOATIME = 01000000,
	O_PATH = 010000000,
	O_TMPFILE = 020040000
#   elif defined(ARCHMIPS)
	O_APPEND = 8,
	O_SYNC = 0x10,
	O_NONBLOCK = 0x80,
	O_CREAT = 0x100,
	O_TRUNC = 0x200,
	O_EXCL = 0x400,
	O_NOCTTY = 0x800,
	FASYNC = 0x1000,
	O_LARGEFILE = 0x2000,
	O_DIRECT = 0x8000,
	O_DIRECTORY = 0x10000,
	O_NOFOLLOW = 0x20000,
	O_NOATIME = 0x40000,
	O_PATH = 010000000,
	O_TMPFILE = 020200000
#   elif defined(ARCHPARISC)
	O_APPEND = 010,
	O_BLKSEEK = 0100,
	O_NOFOLLOW = 0200,
	O_CREAT = 0400,
	O_TRUNC = 01000,
	O_EXCL = 02000,
	O_LARGEFILE = 04000,
	O_DIRECTORY = 010000,
	O_ASYNC = 020000,
	O_DIRECT = 040000,
	O_SYNC = 0100000,
	O_NONBLOCK = 0200004,
	O_NOCTTY = 0400000,
	O_DSYNC = 01000000,  //!< Write: I/O data completion (HPUX only)
	O_RSYNC = 02000000,  //!< Read: I/O completion as for write (HPUX only)
	O_NOATIME = 04000000,
	O_PATH = 020000000
#   elif defined(ARCHPOWERPC)
	O_CREAT = 0100,
	O_EXCL = 0200,
	O_NOCTTY = 0400,
	O_TRUNC = 01000,
	O_APPEND = 02000,
	O_NONBLOCK = 04000,
	O_SYNC = 010000,
	FASYNC = 020000,
	O_DIRECTORY = 040000,
	O_NOFOLLOW = 0100000,
	O_LARGEFILE = 0200000,
	O_DIRECT = 0400000,
	O_NOATIME = 01000000,
	O_PATH = 010000000,
	O_TMPFILE = 020040000
#   elif defined(ARCHSPARC)
	O_APPEND = 8,
	FASYNC = 0x40,
	O_CREAT = 0x200,
	O_TRUNC = 0x400,
	O_EXCL = 0x800,
	O_SYNC = 0x2000,
	O_NONBLOCK = 0x4000,
	O_NDELAY = 0x4004,
	O_NOCTTY = 0x8000,
	O_DIRECTORY = 0x10000,
	O_NOFOLLOW = 0x20000,
	O_LARGEFILE  0x40000,
	O_DIRECT = 0x100000,
	O_NOATIME = 0x200000,
	O_PATH = 0x1000000,
	O_TMPFILE = 020200000
#   else
#      error   "Add support for enum FILE_STATUS_FLAGS for the target platform."
#   endif
};
#define __O_TMPFILE   O_TMPFILE
#define _O_APPEND   O_APPEND
#define _O_CREAT   O_CREAT
#define _O_EXCL   O_EXCL
#define _O_TRUNC   O_TRUNC
/** Set close on exec */
#define O_CLOEXEC   FD_CLOEXEC
#define FAPPEND   O_APPEND
#define FFSYNC   O_FSYNC
#define FNONBLOCK   O_NONBLOCK
#define FNDELAY   O_NONBLOCK
#define O_NDELAY   O_NONBLOCK
/** Skip exec permission checks */
#define O_EXEC   O_PATH
/** Skip search permission checks */
#define O_SEARCH   O_PATH
#ifndef O_ASYNC
/** Signal pgrp when data ready */
#   define O_ASYNC   0
#endif
#ifndef FASYNC
/** Signal pgrp when data ready */
#   define FASYNC   O_ASYNC
#endif
#ifndef O_ALT_IO
/** Use alternate I/O semantics (BSD only) */
#   define O_ALT_IO   0
#endif
#ifndef O_NOSIGPIPE
/** Return EPIPE instead of raising SIGPIPE */
#   define O_NOSIGPIPE   0
#endif
/** @def O_DSYNC
Write: I/O data completion (HPUX only) */
/** @def O_RSYNC
Read: I/O completion as for write (HPUX only) */
#ifndef O_DSYNC
#   define O_DSYNC   0
#   define O_RSYNC   0
#endif
/** @def O_INVISIBLE
Invisible I/O (for DMAPI/XDSM) */
#ifndef O_INVISIBLE
#   define O_INVISIBLE   O_NOATIME
#endif
#define HONORED_STATE_MODES   (O_APPEND | O_ASYNC | O_FSYNC | O_NONBLOCK | O_NOATIME)
/** All settable bits during open(2) */
#define O_MASK   (O_ACCMODE | O_NONBLOCK | O_APPEND | O_SHLOCK | O_EXLOCK | O_ASYNC | O_SYNC | O_CREAT | O_TRUNC | O_EXCL | O_DSYNC | O_RSYNC | O_NOCTTY | O_ALT_IO | O_NOFOLLOW | O_DIRECT | O_DIRECTORY | O_CLOEXEC | O_NOSIGPIPE)

/** I/O Buffering Flags */
enum IO_BUFFERING {
/** `setvbuf()` should set I/O fully buffered */
	_IOFBF = 0,
/** `setvbuf()` should set I/O fully buffered */
#   define __STDIO_IOFBF   _IOFBF
/** `setvbuf()` should set I/O line buffered */
	_IOLBF = 1,
/** `setvbuf()` should set I/O line buffered */
#   define __STDIO_IOLBF   _IOLBF
/** `setvbuf()` should set I/O unbuffered */
	_IONBF = 2
/** `setvbuf()` should set I/O unbuffered */
#   define __STDIO_IONBF   _IONBF
};

/** STDIO State Flags */
enum STDIO_STATE_FLAGS {
/** Line buffered */
	__SLBF = 1,
#   define _IO_USER_BUF   __SLBF
#   define _IO_LINE_BUF   __SLBF
/** Unbuffered */
	__SNBF = 2,
#   define _IO_UNBUFFERED   __SNBF
/** OK to read; RD and WR are never simultaneously asserted */
	__SRD = 4,
#   define F_RD   __SRD
#   define _IO_NO_WRITES   __SRD
/** OK to write; RD and WR are never simultaneously asserted */
	__SWR = 8,
#   define F_WR   __SWR
#   define _IO_NO_READS   __SWR
/** Open for reading & writing */
	__SRW = 0x10,
/** Found EOF */
	__SEOF = 0x20,
#   define F_EOF   __SEOF
#   define _IO_EOF_SEEN   __SEOF
/** File error occurred */
	__SERR = 0x40,
#   define F_ERR   __SERR
#   define _IO_ERR_SEEN   __SERR
/** _buf is from malloc */
	__SMBF = 0x80,
/** fdopen()ed in append mode */
	__SAPP = 0x100,
#   define F_APP   __SAPP
/** This is a sprintf/snprintf string */
	__SSTR = 0x200,
/** Do fseek() optimisation */
	__SOPT = 0x400,
/** Do not do fseek() optimization */
	__SNPT = 0x800,
/** Set if offset is in fact correct */
	__SOFF = 0x1000,
/** true => fgetln modified _p text */
	__SMOD = 0x2000,
/** Allocate string space dynamically */
	__SALC = 0x4000,
/** Ignore this file in _fwalk */
	__SIGN = 0x8000
};

/** Stat mode filetypes */
enum STAT_FILETYPES {
/** FIFO */
	__S_IFIFO = 010000,
#   define S_IFIFO   __S_IFIFO
/** Character device */
	__S_IFCHR = 020000,
#   define S_IFCHR   __S_IFCHR
/** Directory */
	__S_IFDIR = 040000,
#   define S_IFDIR   __S_IFDIR
/** Block device */
	__S_IFBLK = 060000,
#   define S_IFBLK   __S_IFBLK
/** Regular file */
	__S_IFREG = 0100000,
#   define S_IFREG   __S_IFREG
/** Symbolic link */
	__S_IFLNK = 0120000,
#   define S_IFLNK   __S_IFLNK
/** Socket */
	__S_IFSOCK = 0140000,
#   define S_IFSOCK   __S_IFSOCK
/** Encoding of the file mode */
	__S_IFMT = 0170000
#   define S_IFMT   __S_IFMT
};
// Test Macros for Filetypes
#define __S_ISTYPE(mode, mask)   (((mode) & 0170000) == (mask))
#define S_ISBLK(mode)   (((mode) & 0170000) == 060000)
#define S_ISCHR(mode)   (((mode) & 0170000) == 020000)
#define S_ISDIR(mode)   (((mode) & 0170000) == 040000)
#define S_ISFIFO(mode)   (((mode) & 0170000) == 010000)
#define S_ISLNK(mode)   (((mode) & 0170000) == 0120000)
#define S_ISREG(mode)   (((mode) & 0170000) == 0100000)
#define S_ISSOCK(mode)   (((mode) & 0170000) == 0140000)
// POSIX.1b objects; Note that these macros always evaluate to zero
#define __S_TYPEISMQ(buf)   (0)
#define S_TYPEISMQ(buf)   (0)
#define __S_TYPEISSEM(buf)   (0)
#define S_TYPEISSEM(buf)   (0)
#define __S_TYPEISSHM(buf)   (0)
#define S_TYPEISSHM(buf)   (0)

/** File and directory change notification flags (dnotify) */
enum DNOTIFY_FLAGS {
/** File was accessed */
	DN_ACCESS = 1,
/** File was modified */
	DN_MODIFY = 2,
/** File was created */
	DN_CREATE = 4,
/** File was deleted */
	DN_DELETE = 8,
/** File was renamed */
	DN_RENAME = 0x10,
/** File attributes were changed */
	DN_ATTRIB = 0x20
};
/** Notifications will remain in effect until explicitly removed */
#define DN_MULTISHOT   0x80000000

/** Flags for manipulating the flags associated with a file descriptor */
enum FD_FLAGS {
/** Return (as the function result) the file descriptor flags */
	F_GETFD = 1,
/** Set the file descriptor flags to the value specified */
	F_SETFD = 2
};

/** Flags for the status of the file descriptor flags */
enum FD_STATUS_FLAGS {
/** Return (as the function result) the file access mode and the file status flags; `arg` is ignored */
	F_GETFL = 3,
/** Set the file status flags to the value specified by `arg`. File access mode and file creation flags in `arg` are ignored */
	F_SETFL = 4
};

/** Flags for duplicating a file descriptor */
enum DUP_FD_FLAGS {
/** Duplicate the file descriptor using the lowest-numbered available file descriptor greater than or equal to arg */
	F_DUPFD = 0,
/** Same as `F_DUPFD`, but additionally set the close-on-exec flag for the duplicate file descriptor */
	FD_CLOEXEC = 1
#   define F_DUPFD_CLOEXEC   FD_CLOEXEC
};

/** Flags for file descriptor advisory record locking */
enum ADVISORY_RECORD_LOCKING_FLAGS {
#   if (defined(ARM) || defined(ARCHITANIUM) || defined(ARCHPOWERPC) || defined(ARCHS390) || defined(ARCHX86))
/** Acquire lock */
	F_GETLK = 5,
/** Release or acquire lock */
	F_SETLK = 6,
/** Wait for lock to be released prior to acquiring a lock */
	F_SETLKW = 7,
/** Acquire lock (flock64) */
	F_GETLK64 = 12,
/** Release or acquire lock (flock64) */
	F_SETLK64 = 13,
/** Wait for lock to be released prior to acquiring a lock (flock64) */
	F_SETLKW64 = 14
#   elif (defined(ARCHALPHA) || defined(ARCHSPARC))
/** Acquire lock */
	F_GETLK = 7,
/** Release or acquire lock */
	F_SETLK = 8,
/** Wait for lock to be released prior to acquiring a lock */
	F_SETLKW = 9,
	/** Acquire lock (flock64) */
	F_GETLK64 = 12,
/** Release or acquire lock (flock64) */
	F_SETLK64 = 13,
/** Wait for lock to be released prior to acquiring a lock (flock64) */
	F_SETLKW64 = 14
#   elif defined(ARCHMIPS)
/** Acquire lock */
	F_GETLK = 14,
/** Release or acquire lock */
	F_SETLK = 6,
/** Wait for lock to be released prior to acquiring a lock */
	F_SETLKW = 7
#      ifndef ARCHMIPS64
/** Acquire lock (flock64) */
	F_GETLK64 = 33,
/** Release or acquire lock (flock64) */
	F_SETLK64 = 34,
/** Wait for lock to be released prior to acquiring a lock (flock64) */
	F_SETLKW64 = 35
#      endif
#   elif defined(ARCHPARISC)
/** Acquire lock */
	F_GETLK = 5,
/** Release or acquire lock */
	F_SETLK = 6,
/** Wait for lock to be released prior to acquiring a lock */
	F_SETLKW = 7,
/** Acquire lock (flock64) */
	F_GETLK64 = 8,
/** Release or acquire lock (flock64) */
	F_SETLK64 = 9,
/** Wait for lock to be released prior to acquiring a lock (flock64) */
	F_SETLKW64 = 10
#   else
#      error   "Add support for enum ADVISORY_RECORD_LOCKING_FLAGS for the target platform."
#   endif
#   define F_OFD_GETLK   F_GETLK
#   define F_OFD_SETLK   F_SETLK
#   define F_OFD_SETLKW   F_SETLKW
#   ifdef F_GETLK64
#      define F_OFD_GETLK64   F_GETLK64
#      define F_OFD_SETLK64   F_SETLK64
#      define F_OFD_SETLKW64   F_SETLKW64
#   endif
};

/** Flags used to manage I/O availability signals */
enum IO_AVAILABILITY_SIGNAL_FLAGS {
#   if (defined(ARCHARM) || defined(ARCHITANIUM) || defined(ARCHPOWERPC) || defined(ARCHS390) || defined(ARCHX86))
/** Set the process ID or process group ID that will receive SIGIO and SIGURG signals for events on the file descriptor */
	F_SETOWN = 8,
/** Return (as the function result) the process ID or process group currently receiving SIGIO and SIGURG signals for events on the file descriptor */
	F_GETOWN = 9,
/** Set the signal sent when input or output becomes possible to the value given in `arg` */
	F_SETSIG = 10,
/** Return (as the function result) the signal sent when input or output becomes possible */
	F_GETSIG = 11,
/** Direct I/O availability signals to a specific thread, process, or process group */
	F_SETOWN_EX = 15,
/** Return the current file descriptor owner settings as defined by a previous F_SETOWN_EX operation */
	F_GETOWN_EX = 16,
	F_GETOWNER_UIDS = 17
#   elif (defined(ARCHALPHA) || defined(ARCHSPARC))
/** Set the process ID or process group ID that will receive SIGIO and SIGURG signals for events on the file descriptor */
	F_SETOWN = 5,
/** Return (as the function result) the process ID or process group currently receiving SIGIO and SIGURG signals for events on the file descriptor */
	F_GETOWN = 6,
/** Set the signal sent when input or output becomes possible to the value given in `arg` */
	F_SETSIG = 10,
/** Return (as the function result) the signal sent when input or output becomes possible */
	F_GETSIG = 11
#   elif defined(ARCHMIPS)
/** Set the process ID or process group ID that will receive SIGIO and SIGURG signals for events on the file descriptor */
	F_SETOWN = 24,
/** Return (as the function result) the process ID or process group currently receiving SIGIO and SIGURG signals for events on the file descriptor */
	F_GETOWN = 23,
/** Set the signal sent when input or output becomes possible to the value given in `arg` */
	F_SETSIG = 10,
/** Return (as the function result) the signal sent when input or output becomes possible */
	F_GETSIG = 11
#   elif defined(ARCHPARISC)
/** Set the process ID or process group ID that will receive SIGIO and SIGURG signals for events on the file descriptor */
	F_SETOWN = 11,
/** Return (as the function result) the process ID or process group currently receiving SIGIO and SIGURG signals for events on the file descriptor */
	F_GETOWN = 12,
/** Set the signal sent when input or output becomes possible to the value given in `arg` */
	F_SETSIG = 13,
/** Return (as the function result) the signal sent when input or output becomes possible */
	F_GETSIG = 14
#   else
#      error   "Add support for enum IO_AVAILABILITY_SIGNAL_FLAGS for the target platform."
#   endif
};

/** Flags for manipulating file locks/leases */
enum FILE_LEASE_ACTIONS {
#   if (defined(ARCHARM) || defined(ARCHITANIUM) || defined(ARCHMIPS) || defined(ARCHPOWERPC) || defined(ARCHS390) || defined(ARCHX86))
/** Read lock/lease */
	F_RDLCK = 0,
/** Write lock/lease */
	F_WRLCK = 1,
/** Remove lock/lease */
	F_UNLCK = 2,
/** Exclusive lock/lease */
	F_EXLCK = 4,
/** Shared lock/lease */
	F_SHLCK = 8,
/** Lock/Lease in proogress */
	F_INPROGRESS = 16
#   elif defined(ARCHALPHA)
/** Read lock/lease */
	F_RDLCK = 1,
/** Write lock/lease */
	F_WRLCK = 2,
/** Remove lock/lease */
	F_UNLCK = 8,
/** Exclusive lock/lease */
	F_EXLCK = 16,
/** Shared lock/lease */
	F_SHLCK = 32,
/** Lock/Lease in proogress */
	F_INPROGRESS = 64
#   elif (defined(ARCHPARISC) || defined(ARCHSPARC))
/** Read lock/lease */
	F_RDLCK = 1,
/** Write lock/lease */
	F_WRLCK = 2,
/** Remove lock/lease */
	F_UNLCK = 3,
/** Exclusive lock/lease */
	F_EXLCK = 4,
/** Shared lock/lease */
	F_SHLCK = 8,
/** Lock/Lease in proogress */
	F_INPROGRESS = 16
#   else
#      error   "Add support for enum FILE_LEASE_ACTIONS for the target platform."
#   endif
};
/** Open with shared file lock */
#define O_SHLOCK   F_SHLCK
/** Open with exclusive file lock */
#define O_EXLOCK   F_EXLCK

/** Flags for manipulating BSD file locks/leases */
enum BSD_FILE_LEASE_ACTIONS {
/** Shared lock/lease */
	LOCK_SH = 1,
/** Exclusive lock/lease */
	LOCK_EX = 2,
/** Mask ORed with other locks/leases */
	LOCK_NB = 4,
/** Remove lock/lease */
	LOCK_UN = 8,
/** Mandatory lock/lease */
	LOCK_MAND = 32,
/** Read lock/lease */
	LOCK_READ = 64,
/** Write lock/lease */
	LOCK_WRITE = 128,
/** Read/Write lock/lease */
	LOCK_RW = 192
};

enum FD_LEASES { F_SETLEASE = 1024, F_GETLEASE = 1025 };

/** File seals limit the set of allowed operations on a given file */
enum FILE_SEALS {
/** Any further calls to fcntl() with F_ADD_SEALS will fail with EPERM */
	F_SEAL_SEAL = 1,
/** The file in question cannot be reduced in size */
	F_SEAL_SHRINK = 2,
/** The file in question cannot be increased in size */
	F_SEAL_GROW = 4,
/** The file contents cannot be modified */
	F_SEAL_WRITE = 8
};

/** fsync_range flags */
enum FSYNC_RANGE_FLAGS {
/** Sync data and minimal metadata */
	FDATASYNC = 0x10,
/** Sync data and metadata */
	FFILESYNC = 0x20,
/** Flush disk caches after sync */
	FDISKSYNC = 0x40
};

/** Flags for sync_file_range() */
enum SYNC_FILE_RANGE_FLAGS {
	SYNC_FILE_RANGE_WAIT_BEFORE = 1,
	SYNC_FILE_RANGE_WRITE = 2,
	SYNC_FILE_RANGE_WAIT_AFTER = 4
};

/** Function arguments needed by lockf() */
enum LOCKF_FLAGS {
/** Unlock a previously locked region */
	F_ULOCK = 0,
/** Lock a region for exclusive use */
	F_LOCK = 1,
/** Test and lock a section for exclusive use */
	F_TLOCK = 2,
/** Test a section for locks by other processes */
	F_TEST = 3
};

/** lseek() flags */
enum LSEEK_FLAGS {
/** Set file offset to offset */
	SEEK_SET = 0,
/** Old BSD name for SEEK_SET */
#   define L_SET   SEEK_SET
#   define _IO_seek_set   SEEK_SET
/** Set file offset to current plus offset */
	SEEK_CUR = 1,
/** Old BSD name for SEEK_CUR */
#   define L_INCR   SEEK_CUR
#   define _IO_seek_cur   SEEK_CUR
/** Set file offset to EOF plus offset */
	SEEK_END = 2,
/** Old BSD name for SEEK_END */
#   define L_XTND   SEEK_END
#   define _IO_seek_end   SEEK_END
/** Seek to next data */
	SEEK_DATA = 3,
#   define _IO_seek_data   SEEK_DATA
/** Seek to next hole */
	SEEK_HOLE = 4
#   define _IO_seek_hole   SEEK_HOLE
};

/** POSIX fadvise() flags */
enum POSIX_FADV {
/** No further special treatment */
	POSIX_FADV_NORMAL = 0,
/** Expect random page references */
	POSIX_FADV_RANDOM = 1,
/** Expect sequential page references */
	POSIX_FADV_SEQUENTIAL = 2,
/** Will need these pages */
	POSIX_FADV_WILLNEED = 3,
/** Do not need these pages */
	POSIX_FADV_DONTNEED = 4,
/** Data will be accessed once */
	POSIX_FADV_NOREUSE = 5
};

/** splice() flags */
enum SPLICE_FLAGS {
/** Attempt to move pages instead of copying */
	SPLICE_F_MOVE = 1,
/** Make the splice pipe operations nonblocking */
	SPLICE_F_NONBLOCK = 2,
/** Expect more data */
	SPLICE_F_MORE = 4,
/** Pages passed in are a gift */
	SPLICE_F_GIFT = 8
};

/** @} */  // }


// SYSCONF

/** @defgroup Sysconf_Values Macros values for various sysconf properties
@{ */  // (FB){

#if (defined(OSBEOS) || defined(OSHAIKU))
#   define _PC_CHOWN_RESTRICTED   1
#   define _PC_MAX_CANON   2
#   define _PC_MAX_INPUT   3
#   define _PC_NAME_MAX   4
#   define _PC_NO_TRUNC   5
#   define _PC_PATH_MAX   6
#   define _PC_PIPE_BUF   7
#   define _PC_VDISABLE   8
#   define _PC_LINK_MAX   25
#   define _PC_SYNC_IO   26
#   define _PC_ASYNC_IO   27
#   define _PC_PRIO_IO   28
#   define _PC_SOCK_MAXBUF   29
#   define _PC_FILESIZEBITS   30
#   define _PC_REC_INCR_XFER_SIZE   31
#   define _PC_REC_MAX_XFER_SIZE   32
#   define _PC_REC_MIN_XFER_SIZE   33
#   define _PC_REC_XFER_ALIGN   34
#   define _PC_ALLOC_SIZE_MIN   35
#   define _PC_SYMLINK_MAX   36
#   define _PC_2_SYMLINKS   37
#   define _PC_XATTR_EXISTS   38
#   define _PC_XATTR_ENABLED   39
#   define _SC_ARG_MAX   15
#   define _SC_CHILD_MAX   16
#   define _SC_CLK_TCK   17
#   define _SC_JOB_CONTROL   18
#   define _SC_NGROUPS_MAX   19
#   define _SC_OPEN_MAX   20
#   define _SC_SAVED_IDS   21
#   define _SC_STREAM_MAX   22
#   define _SC_TZNAME_MAX   23
#   define _SC_VERSION   24
#   define _SC_GETGR_R_SIZE_MAX   25
#   define _SC_GETPW_R_SIZE_MAX   26
#   define _SC_PAGE_SIZE   27
#   define _SC_PAGESIZE   _SC_PAGE_SIZE
#   define _SC_SEM_NSEMS_MAX   28
#   define _SC_SEM_VALUE_MAX   29
#   define _SC_SEMAPHORES   30
#   define _SC_THREADS   31
#   define _SC_IOV_MAX   32
#   define _SC_UIO_MAXIOV   _SC_IOV_MAX
#   define _SC_NPROCESSORS_CONF   34
#   define _SC_NPROCESSORS_ONLN   35
#   define _SC_ATEXIT_MAX   37
#   define _SC_PASS_MAX   39
#   define _SC_PHYS_PAGES   40
#   define _SC_AVPHYS_PAGES   41
#   define _SC_PIPE   42
#   define _SC_SELECT   43
#   define _SC_POLL   44
#   define _SC_MAPPED_FILES   45
#   define _SC_THREAD_PROCESS_SHARED   46
#   define _SC_THREAD_STACK_MIN   47
#   define _SC_THREAD_ATTR_STACKADDR   48
#   define _SC_THREAD_ATTR_STACKSIZE   49
#   define _SC_THREAD_PRIORITY_SCHEDULING   50
#   define _SC_REALTIME_SIGNALS   51
#   define _SC_MEMORY_PROTECTION   52
#   define _SC_SIGQUEUE_MAX   53
#   define _SC_RTSIG_MAX   54
#   define _SC_MONOTONIC_CLOCK   55
#   define _SC_DELAYTIMER_MAX   56
#   define _SC_TIMER_MAX   57
#   define _SC_TIMERS   58
#   define _SC_CPUTIME   59
#   define _SC_THREAD_CPUTIME   60
#elif defined(OSBSD)
#   define _PC_LINK_MAX   1
#   define _PC_MAX_CANON   2
#   define _PC_MAX_INPUT   3
#   define _PC_NAME_MAX   4
#   define _PC_PATH_MAX   5
#   define _PC_PIPE_BUF   6
#   define _PC_CHOWN_RESTRICTED   7
#   define _PC_NO_TRUNC   8
#   define _PC_VDISABLE   9
#   define _PC_SYNC_IO   10
#   define _PC_FILESIZEBITS   11
#   define _PC_SYMLINK_MAX   12
#   define _PC_2_SYMLINKS   13
#   define _PC_ACL_EXTENDED   14
/** From OpenSolaris; used by `seek_data()`/`seek_hole()` */
#   define _PC_MIN_HOLE_SIZE   15
#   define _SC_ARG_MAX   1
#   define _SC_CHILD_MAX   2
#   define _O_SC_CLK_TCK   3
#   define _SC_NGROUPS_MAX   4
#   define _SC_OPEN_MAX   5
#   define _SC_JOB_CONTROL   6
#   define _SC_SAVED_IDS   7
#   define _SC_VERSION   8
#   define _SC_BC_BASE_MAX   9
#   define _SC_BC_DIM_MAX   10
#   define _SC_BC_SCALE_MAX   11
#   define _SC_BC_STRING_MAX   12
#   define _SC_COLL_WEIGHTS_MAX   13
#   define _SC_EXPR_NEST_MAX   14
#   define _SC_LINE_MAX   15
#   define _SC_RE_DUP_MAX   16
#   define _SC_2_VERSION   17
#   define _SC_2_C_BIND   18
#   define _SC_2_C_DEV   19
#   define _SC_2_CHAR_TERM   20
#   define _SC_2_FORT_DEV   21
#   define _SC_2_FORT_RUN   22
#   define _SC_2_LOCALEDEF   23
#   define _SC_2_SW_DEV   24
#   define _SC_2_UPE   25
#   define _SC_STREAM_MAX   26
#   define _SC_TZNAME_MAX   27
#   define _SC_PAGESIZE   28
#   define _SC_PAGE_SIZE   _SC_PAGESIZE
#   define _SC_FSYNC   29
#   define _SC_XOPEN_SHM   30
#   define _SC_SYNCHRONIZED_IO 31
#   define _SC_IOV_MAX   32
#   define _SC_MAPPED_FILES   33
#   define _SC_MEMLOCK   34
#   define _SC_MEMLOCK_RANGE   35
#   define _SC_MEMORY_PROTECTION   36
#   define _SC_LOGIN_NAME_MAX   37
#   define _SC_MONOTONIC_CLOCK   38
#   define _SC_CLK_TCK   39
#   define _SC_ATEXIT_MAX   40
#   define _SC_THREADS   41
#   define _SC_SEMAPHORES   42
#   define _SC_BARRIERS   43
#   define _SC_TIMERS   44
#   define _SC_SPIN_LOCKS   45
#   define _SC_READER_WRITER_LOCKS   46
#   define _SC_GETGR_R_SIZE_MAX   47
#   define _SC_GETPW_R_SIZE_MAX   48
#   define _SC_CLOCK_SELECTION   49
#   define _SC_ASYNCHRONOUS_IO   50
#   define _SC_AIO_LISTIO_MAX   51
#   define _SC_AIO_MAX   52
#   define _SC_MESSAGE_PASSING   53
#   define _SC_MQ_OPEN_MAX   54
#   define _SC_MQ_PRIO_MAX   55
#   define _SC_PRIORITY_SCHEDULING   56
#   define _SC_THREAD_DESTRUCTOR_ITERATIONS   57
#   define _SC_THREAD_KEYS_MAX   58
#   define _SC_THREAD_STACK_MIN   59
#   define _SC_THREAD_THREADS_MAX   60
#   define _SC_THREAD_ATTR_STACKADDR   61
#   define _SC_THREAD_ATTR_STACKSIZE   62
#   define _SC_THREAD_PRIORITY_SCHEDULING   63
#   define _SC_THREAD_PRIO_INHERIT   64
#   define _SC_THREAD_PRIO_PROTECT   65
#   define _SC_THREAD_PROCESS_SHARED   66
#   define _SC_THREAD_SAFE_FUNCTIONS   67
#   define _SC_TTY_NAME_MAX   68
#   define _SC_HOST_NAME_MAX   69
#   define _SC_PASS_MAX   70
#   define _SC_REGEXP   71
#   define _SC_SHELL   72
#   define _SC_SYMLOOP_MAX   73
#   define _SC_V6_ILP32_OFF32   74
#   define _SC_V6_ILP32_OFFBIG   75
#   define _SC_V6_LP64_OFF64   76
#   define _SC_V6_LPBIG_OFFBIG   77
#   define _SC_2_PBS   80
#   define _SC_2_PBS_ACCOUNTING   81
#   define _SC_2_PBS_CHECKPOINT   82
#   define _SC_2_PBS_LOCATE   83
#   define _SC_2_PBS_MESSAGE   84
#   define _SC_2_PBS_TRACK   85
#   define _SC_SPAWN   86
#   define _SC_SHARED_MEMORY_OBJECTS   87
#   define _SC_PHYS_PAGES   121
#   define _SC_NPROCESSORS_CONF   1001
#   define _SC_NPROCESSORS_ONLN   1002
#   define _SC_SCHED_RT_TS   2001
#   define _SC_SCHED_PRI_MIN   2002
#   define _SC_SCHED_PRI_MAX   2003
#   define _CS_PATH   1
#elif defined(OSPLAN9)
#   define _SC_ARG_MAX   1
#   define _SC_CHILD_MAX   2
#   define _SC_CLK_TCK   3
#   define _SC_NGROUPS_MAX   4
#   define _SC_OPEN_MAX   5
#   define _SC_STREAM_MAX   6
#   define _SC_TZNAME_MAX   7
#   define _SC_JOB_CONTROL   8
#   define _SC_SAVED_IDS   9
#   define _SC_VERSION   10
#   define _SC_LOGIN_NAME_MAX   11
#   define _PC_LINK_MAX   1
#   define _PC_MAX_CANON   2
#   define _PC_MAX_INPUT   3
#   define _PC_NAME_MAX   4
#   define _PC_PATH_MAX   5
#   define _PC_PIPE_BUF   6
#   define _PC_CHOWN_RESTRICTED   7
#   define _PC_NO_TRUNC   8
#   define _PC_VDISABLE   9
#else
#   define _SC_ARG_MAX   0
#   define _SC_BC_BASE_MAX   1
#   define _SC_BC_DIM_MAX   2
#   define _SC_BC_SCALE_MAX   3
#   define _SC_BC_STRING_MAX   4
#   define _SC_CHILD_MAX   5
#   define _SC_CLK_TCK   6
#   define _SC_COLL_WEIGHTS_MAX   7
#   define _SC_EXPR_NEST_MAX   8
#   define _SC_LINE_MAX   9
#   define _SC_NGROUPS_MAX   0xa
#   define _SC_OPEN_MAX   0xb
#   define _SC_PASS_MAX   0xc
#   define _SC_2_C_BIND   0xd
#   define _SC_2_C_DEV   0xe
#   define _SC_2_C_VERSION   0xf
#   define _SC_2_CHAR_TERM   0x10
#   define _SC_2_FORT_DEV   0x11
#   define _SC_2_FORT_RUN   0x12
#   define _SC_2_LOCALEDEF   0x13
#   define _SC_2_SW_DEV   0x14
#   define _SC_2_UPE   0x15
#   define _SC_2_VERSION   0x16
#   define _SC_JOB_CONTROL   0x17
#   define _SC_SAVED_IDS   0x18
#   define _SC_VERSION   0x19
#   define _SC_RE_DUP_MAX   0x1a
#   define _SC_STREAM_MAX   0x1b
#   define _SC_TZNAME_MAX   0x1c
#   define _SC_XOPEN_CRYPT   0x1d
#   define _SC_XOPEN_ENH_I18N   0x1e
#   define _SC_XOPEN_SHM   0x1f
#   define _SC_XOPEN_VERSION   0x20
#   define _SC_XOPEN_XCU_VERSION   0x21
#   define _SC_XOPEN_REALTIME   0x22
#   define _SC_XOPEN_REALTIME_THREADS  0x23
#   define _SC_XOPEN_LEGACY   0x24
#   define _SC_ATEXIT_MAX   0x25
#   define _SC_IOV_MAX   0x26
#   define _SC_PAGESIZE   0x27
#   define _SC_PAGE_SIZE   0x28
#   define _SC_XOPEN_UNIX   0x29
#   define _SC_XBS5_ILP32_OFF32   0x2a
#   define _SC_XBS5_ILP32_OFFBIG   0x2b
#   define _SC_XBS5_LP64_OFF64   0x2c
#   define _SC_XBS5_LPBIG_OFFBIG   0x2d
#   define _SC_AIO_LISTIO_MAX   0x2e
#   define _SC_AIO_MAX   0x2f
#   define _SC_AIO_PRIO_DELTA_MAX   0x30
#   define _SC_DELAYTIMER_MAX   0x31
#   define _SC_MQ_OPEN_MAX   0x32
#   define _SC_MQ_PRIO_MAX   0x33
#   define _SC_RTSIG_MAX   0x34
#   define _SC_SEM_NSEMS_MAX   0x35
#   define _SC_SEM_VALUE_MAX   0x36
#   define _SC_SIGQUEUE_MAX   0x37
#   define _SC_TIMER_MAX   0x38
#   define _SC_ASYNCHRONOUS_IO   0x39
#   define _SC_FSYNC   0x3a
#   define _SC_MAPPED_FILES   0x3b
#   define _SC_MEMLOCK   0x3c
#   define _SC_MEMLOCK_RANGE   0x3d
#   define _SC_MEMORY_PROTECTION   0x3e
#   define _SC_MESSAGE_PASSING   0x3f
#   define _SC_PRIORITIZED_IO   0x40
#   define _SC_PRIORITY_SCHEDULING   0x41
#   define _SC_REALTIME_SIGNALS   0x42
#   define _SC_SEMAPHORES   0x43
#   define _SC_SHARED_MEMORY_OBJECTS  0x44
#   define _SC_SYNCHRONIZED_IO   0x45
#   define _SC_TIMERS   0x46
#   define _SC_GETGR_R_SIZE_MAX   0x47
#   define _SC_GETPW_R_SIZE_MAX   0x48
#   define _SC_LOGIN_NAME_MAX   0x49
#   define _SC_THREAD_DESTRUCTOR_ITERATIONS   0x4a
#   define _SC_THREAD_KEYS_MAX   0x4b
#   define _SC_THREAD_STACK_MIN   0x4c
#   define _SC_THREAD_THREADS_MAX  0x4d
#   define _SC_TTY_NAME_MAX   0x4e
#   define _SC_THREADS   0x4f
#   define _SC_THREAD_ATTR_STACKADDR   0x50
#   define _SC_THREAD_ATTR_STACKSIZE   0x51
#   define _SC_THREAD_PRIORITY_SCHEDULING   0x52
#   define _SC_THREAD_PRIO_INHERIT   0x53
#   define _SC_THREAD_PRIO_PROTECT   0x54
#   define _SC_THREAD_SAFE_FUNCTIONS   0x55
#   define _SC_NPROCESSORS_CONF   0x60
#   define _SC_NPROCESSORS_ONLN   0x61
#   define _SC_PHYS_PAGES   0x62
#   define _SC_AVPHYS_PAGES   0x63
#   define _SC_MONOTONIC_CLOCK   0x64
#endif  // SYSCONF

/** @} */  // }


#endif  // SPECIFICATIONS, FEATURES, & ARCHITECTURE MACROS


/* POINTER CASTS */


#ifndef POINTER_CASTS_H
#define POINTER_CASTS_H   (1)


/** @defgroup Pointer_Casts Macros used to cast pointers between different pointer attribute type
@{ */  // (FB){

#undef __UNCONST
/** Remove const cast-away warnings from `-Wcast-qual`; this should be used with caution because it can hide valid errors */
#define __UNCONST(x)   ((void*)(uintptr_t)(x))
/** Remove const cast-away warnings from `-Wcast-qual`; this should be used with caution because it can hide valid errors */
#define UNCONST(x)   ((void*)(uintptr_t)(x))
#undef __UNVOLATILE
/** Remove the volatile cast-away warnings from `-Wcast-qual`; this should be used with caution because it can hide valid errors or warnings */
#define __UNVOLATILE(x)   ((void*)(uintptr_t)(x))
#ifndef UNVOLATILE
/** Remove the volatile cast-away warnings from `-Wcast-qual`; this should be used with caution because it can hide valid errors or warnings */
#   define UNVOLATILE(x)   ((void*)(uintptr_t)(x))
#endif
#ifndef __DECONST
#   define __DECONST(type, var)   ((type)(uintptr_t)(var))
#endif
#ifndef DECONST
#   define DECONST(type, var)   ((type)(uintptr_t)(var))
#endif
#ifndef __DEVOLATILE
#   define __DEVOLATILE(type, var)   ((type)(uintptr_t)(var))
#endif
#ifndef DEVOLATILE
#   define DEVOLATILE(type, var)   ((type)(uintptr_t)(var))
#endif
#ifndef __DEQUALIFY
#   define __DEQUALIFY(type, var)   ((type)(uintptr_t)(var))
#endif
#ifndef DEQUALIFY
#   define DEQUALIFY(type, var)   ((type)(uintptr_t)(var))
#endif
/** The following macro is used to remove const cast-away warnings from `-Wcast-qual`; this should be used with caution because it can hide valid errors */
#define rk_UNCONST(x)   ((void*)(uintptr_t)(x))
/** Convert a pointer to an integer */
#define PTR_TO_INT(PTR)   ((size_t)((char*)(PTR) - NULL_CHAR))
#define HandleToLong(x)   ((long)(intptr_t)((void*)(x)))
#define HandleToULong(x)   ((unsigned long)(uintptr_t)((void*)(x)))
#define HandleToUlong(x)   ((unsigned long)(uintptr_t)((void*)(x)))
#define IntToPtr(x)   ((void*)(intptr_t)((int)(x)))
#define LongToHandle(x)   ((void*)(uintptr_t)((long)(x)))
#define LongToPtr(x)   ((void*)(intptr_t)((long)(x)))
#define PtrToInt(x)   ((int)(intptr_t)((void*)(x)))
#define PtrToLong(x)   ((long)(intptr_t)((void*)(x)))
#define PtrToShort(x)   ((short)(intptr_t)((void*)(x)))
#define PtrToUint(x)   ((unsigned int)(uintptr_t)((void*)(x)))
#define PtrToUlong(x)   ((unsigned long)(uintptr_t)((void*)(x)))
#define PtrToUshort(x)   ((unsigned short)(uintptr_t)((void*)(x)))
#define UIntToPtr(x)   ((void*)(uintptr_t)((unsigned int)(x)))
#define UintToPtr(x)   ((void*)(uintptr_t)((unsigned int)(x)))
#define UlongToHandle(x)   ((void*)(uintptr_t)((long)(x)))
#define ULongToHandle(x)   ((void*)(uintptr_t)((long)(x)))
#define UlongToPtr(x)   ((void*)(uintptr_t)((unsigned long)(x)))
#define ULongToPtr(x)   ((void*)(uintptr_t)((unsigned long)(x)))
/** intptr_t if P is true, or T if P is false */
#define integer_if_pointer_type_sub(T, P)   typeof(*(0 ? (typeof(0 ? (T*)0 : (void*)(P)))0 : (typeof(0 ? (intptr_t*)0 : (void*)(!(P))))0))
/** intptr_t if P is true, or T if P is false */
#define __integer_if_pointer_type_sub(T, P)   integer_if_pointer_type_sub((T), (P))
/** intptr_t if EXPR has a pointer type, or the type of EXPR otherwise */
#define integer_if_pointer_type(expr)   __integer_if_pointer_type_sub(typeof((typeof(expr))0), __pointer_type(typeof(expr)))
/** intptr_t if EXPR has a pointer type, or the type of EXPR otherwise */
#define __integer_if_pointer_type(expr)   integer_if_pointer_type((expr))
/** Cast an integer or a pointer VAL to integer with proper type */
#define cast_to_integer(val)   ((__integer_if_pointer_type(val))(val))
#define __USE(x)   ((void)(x))
/** Get the address of the object */
#define ADDRESS_FUNCTION(x)   &(x)
/** Get the address of the object */
#define GET_ADDRESS(x)   &(x)
/** Get the address of a variable and pass it on as a `void*` */
#define vp_pack(var)   ((void*)&var)
/** Get a void pointer and dereferences it to the specified datatype */
#define vp_unpack(var, type)   (*((type*)var))
/** Ignore the value of an expression when a cast to void does not suffice (in particular, for a call to a function declared with attribute warn_unused_result) */
#define ignore_value(x)   __extension__ ({ typeof(x) tmpmvar = (x); (void)tmpmvar; })
/** Return a pointer (void *const*) to the first element of SET */
#define symbol_set_first_element(set)   ((void* const*)(&__start_ ## set))
/** Return true if PTR (a void *const*) has been incremented past the last element in SET */
#define symbol_set_end_p(set, ptr)   ((ptr) >= (void* const*) &__stop_ ## set)

/** @} */  // }


#endif  // POINTER_CASTS_H


/* BIT & LOGIC MACROS */


#ifndef BIT_MACROS_H
#define BIT_MACROS_H   (1)


/** @defgroup Bit_and_Logic_Macros Macros used to manipulate bits & bytes and perform some logical operations
@{ */  // (FB){


// BYTE & BIT OPERATION MACROS

/** Mask for the specified bit within a byte */
#define byte_mask(bit)   (1 << ((bit) & 7))
/** Find least significant bit that is set; For example, a return value of "8" indicates that the LSB is in the bit position that represents a decimal value of eight */
#define FIND_LOWEST_SET_BIT(data)   ((data) & (-(data)))
/** Find least significant bit that is not set; For example, a return value of "8" indicates that the LSB unset is in the bit position that represents a decimal value of eight */
#define FIND_LOWEST_UNSET_BIT(data)   ((~(data)) & ((data) + 1))
/** Extract the bitfield selected by `__mask` from `x` and right-shift the bits so that the rightmost selected bit is at bit 0 */
#define SHIFTOUT(x, __mask)   (((x) & (__mask)) / FIND_LOWEST_SET_BIT(__mask))
/** Left-shift bits `x` into the bitfield defined by `__mask` */
#define SHIFTIN(x, __mask)   ((x) * FIND_LOWEST_SET_BIT(__mask))
/** Shift the mask towards the LSB until the specified bit (using the original mask) is the LSB */
#define SHIFTOUT_MASK(__mask)   ((__mask) / FIND_LOWEST_SET_BIT(__mask))
/** Find least significant bit that is set; For example, a return value of "4" indicates that the fourth bit (bit position representing a decimal value of eight) is the LSB */
#define find_lowest_set_bit(data)   __extension__ ({ register uint64_t tmp1var = (uint64_t)FIND_LOWEST_SET_BIT(data), tmp2var = (tmp1var == 0 ? 0 : 1); while (tmp1var >>= 1) { ++tmp2var; } tmp2var; })
/** Create a number with the specified bit set to 1 (set1bit(0) == 1) */
#define set1bit(data)   (1 << (data))
/** Set the specified bit position to one (setbit(x, 0) == x|1) */
#define setbit(x, bit)   ((x) | set1bit(bit))
/** Set the specified bits to one based on mask */
#define SETBITS(x, __mask)   ((x) | (__mask))
/** Create an uintmax_t with the value of the specified bit set */
#define __BIT(__n)   (((__UINTMAX_TYPE__)(__n) >= BITS_PER_UINTMAX_T) ? 0 : ((__UINTMAX_TYPE__)1 << (__UINTMAX_TYPE__)((__n) & (BITS_PER_UINTMAX_T - 1))))
/** Create an uintmax_t with the value of the specified bit range set */
#define __BITS(__m, __n)   ((__BIT(MAX((__m), (__n)) + 1) - 1) ^ (__BIT(MIN((__m), (__n))) - 1))
/** Bits x through y are set to "1"; Required: x < y */
#define setbitfield(x, y)   ((set1bit(MAX((x), (y)) + 1) - 1) ^ (set1bit(MIN((x), (y))) - 1))
/** Unset the specified bit */
#define unsetbit(x, bit)   ((x) & ~(set1bit(bit)))
/** Unset the specified bits based on mask */
#define UNSETBIT(x, __mask)   ((x) & ~(__mask))
/** Toggle the specified bit */
#define togglebit(x, bit)   ((x) ^ (set1bit(bit)))
/** Toggle the specified bits based on mask */
#define TOGGLEBIT(x, __mask)   ((x) ^ (__mask))
/** Clear the lowest set bit */
#define clr_lowest_set_bit(data)   ((data) & ((data) - 1))
/** Clear the specified bit */
#define clrbit(x, bit)   ((x) & (~(set1bit(bit))))
/** Clear the specified bits based on mask */
#define CLRBIT(x, __mask)   ((x) & ~(__mask))
/** Test if the specified bit is set */
#define isset(x, bit)   (!!((x) & (set1bit(bit))))
/** Test if the specified bits are set based on mask */
#define ISSET(x, __mask)   (!!((x) & (__mask)))
/** Test if the specified bit is not set */
#define isclr(x, bit)   (!!((x) & ~(set1bit(bit))))
/** Test if the specified bits are not set based on mask */
#define ISCLR(x, __mask)   (!!((x) & ~(__mask)))
/** Turn off LSB (set the right-most 1 bit to 0) */
#define turnofflsb(x)   ((x) & ((x) - 1))
/** Isolate LSB (right-most 1 bit) */
#define isolatelsb(x)   ((x) & (-(x)))
/** Right propagate the rightmost set-bit */
#define propagatelsb(x)   ((x) | ((x) - 1))
/** Isolate the rightmost 0-bit */
#define isolatelsb0bit(x)   ((~(x)) & ((x) + 1))
/** Set the rightmost 0-bit */
#define setlsb0bit(x)   ((x) | ((x) + 1))
/** Preceded byte by `i` 1's (8-bit values only); set_leading_ones_8bit(2) is 11000000 */
#define set_leading_ones_8bit(i)   (((1 << ((7 - (i)) + 1)) - 1) ^ 255)
/** Sign EXtend */
#define sex(x)   (x >> ((NBBY * sizeof(typeof(x))) - 1))
/** Get the contrast number */
#define get_contrast_num(x)   ((~x) + 1)
/** Return the twos complement of the given data */
#define COMP2(x)   ((~(x)) + 1)
/** Return the twos complement of the given data */
#define TWOS_COMPLEMENT(x)   COMP2(x)
/** Swap odd and even bits */
#define swap_odd_and_even_bits(x)   ((((x) >> 1) & 0x55555555) | (((x) & 0x55555555) << 1))
/** Swap consecutive pairs */
#define swap_consecutive_pairs(x)   ((((x) >> 2) & 0x33333333) | (((x) & 0x33333333) << 2))
/** Swap nibbles */
#define swap_nibbles(x)   ((((x) >> 4) & 0x0f0f0f0f) | (((x) & 0x0f0f0f0f) << 4))
/** Swap bytes */
#define swap_bytes(x)   ((((x) >> 8) & 0x00ff00ff) | (((x) & 0x00ff00ff) << 8))
/** Swap 2-byte-long pairs */
#define swap_2byte_long_pairs(x)   (((x) >> 16) | ((x) << 16))
/** Reverse the bits in a byte */
#define reversebyte(x)   ((((x) * 0x0202020202ULL) & 0x010884422010ULL) % 1023)
/** Return true if the data contains a NULL byte */
#define has_nullbyte(x)   (((unsigned long)((x) - 0x01010101UL) & (unsigned long)(~(x)) & 0x80808080UL) != 0)
/** Return true if the data contains a NULL byte */
#define hasNulByte(x)   has_nullbyte(x)
/** Return true if the data contains a NULL byte */
#define hasZeroByte(x)   has_nullbyte(x)
/** Return true if the data contains a NULL byte */
#define haszero(x)   has_nullbyte(x)
/** Return true if the data contains the specified byte */
#define hasvalue(x, byte)   (haszero((x) ^ ((~0UL) / 255 * (byte))))
#define __BITMAP_MASK(__t)   (_TYPEBITS(__t) - 1)
#define __BITMAP_BIT(__n, __v)    (1 << ((__n) & __BITMAP_MASK(*(__v)->_b)))
#define __BITMAP_SIZE(__t, __n)    (((__n) + (_TYPEBITS(__t) - 1)) / _TYPEBITS(__t))
#define __BITMAP_TYPE(__s, __t, __n)   struct __s { __t _b[__BITMAP_SIZE(__t, __n)]; }
#define __BITMAP_SHIFT(__t)   (ilog2(_TYPEBITS(__t)))
#define __BITMAP_WORD(__n, __v)   ((__n) >> __BITMAP_SHIFT(*(__v)->_b))
#define __BITMAP_SET(__n, __v)   ((__v)->_b[__BITMAP_WORD(__n, __v)] |= __BITMAP_BIT(__n, __v))
#define __BITMAP_CLR(__n, __v)   ((__v)->_b[__BITMAP_WORD(__n, __v)] &= ~__BITMAP_BIT(__n, __v))
#define __BITMAP_ISSET(__n, __v)   ((__v)->_b[__BITMAP_WORD(__n, __v)] & __BITMAP_BIT(__n, __v))
#define __BITMAP_ZERO(__v)   do { register size_t __i; for (__i = 0; __i < __arraycount(__v->_b); __i++) { (__v)->_b[__i] = 0; } } while (0x0)
/** This code is needed for the optimized mapping functions */
#define __tobody(c, f, a, args)   __extension__ ({ int __res; if (sizeof(c) > 1) { if (__builtin_constant_p(c)) { int __c = (c); __res = ((__c < (-128) || __c > 255) ? __c : (a)[__c]); } else { __res = f args; } } else { __res = (a)[(int)(c)]; } __res; })
/** Macro to make it easier to loop over several blocks */
#define FOR_BLOCKS(length, dst, src, blocksize)   assert(!((length) % (blocksize))); for (; (length); ((length) -= (blocksize), (dst) += (blocksize), (src) += (blocksize)))
#ifndef Storeinc
#   define Storeinc(a, b, c)   (*a++ = ((b) << 16) | ((c) & UINT16_MAX))
#endif
#define Sign_Extend(a, b)   if ((b) < 0) { a |= 0xffff0000; }
#define MEMCCPY_ALIGN   (SIZEOF_SIZE_T - 1)
#define MEMCCPY_ONES   ((size_t)(-1) / UCHAR_MAX)
#define HASZERO(x)   ((((x) - MEMCCPY_ONES) & (~(x))) & (MEMCCPY_ONES * ((UCHAR_MAX / 2) + 1)))
#define HASNTZERO(x)   (!((((x) - MEMCCPY_ONES) & (~(x))) & (MEMCCPY_ONES * ((UCHAR_MAX / 2) + 1))))
#define HASNOTZERO(x)   HASNTZERO((x))
#define HASNOZERO(x)   HASNTZERO((x))
#define BITOP(a, b, op)   ((a)[(size_t)(b) / (NBBY * sizeof(*(a)))] op (size_t)1 << ((size_t)(b) % (NBBY * sizeof(*(a)))))
/** Byte of the bitstring containing the bit */
#define bit_byte(bit)   ((bit) >> 3)
/** Bytes in a bitstring of nbits bits */
#define bitstr_size(nbits)   (((nbits) + 7) >> 3)
/** Allocate a bitstring */
#define bit_alloc(nbits)   (bitstr_t*)calloc((size_t)bitstr_size(nbits), SIZEOF_CHAR)
/** Allocate a bitstring on the stack */
#define bit_decl(name, nbits)   ((name)[bitstr_size(nbits)])
/** Is bit N of bitstring name set? */
#define bit_test(name, bit)   ((name)[bit_byte(bit)] & (byte_mask(bit)))
/** Set bit N of bitstring name */
#define bit_set(name, bit)   ((name)[bit_byte(bit)] |= (byte_mask(bit)))
/** Clear bit N of bitstring name */
#define bit_clear(name, bit)   ((name)[bit_byte(bit)] &= (~byte_mask(bit)))
/** Clear bits start ... stop in bitstring */
#define bit_nclear(name, start, stop)   do { bitstr_t* _name = name; register int _start = start, _stop = stop; while (_start <= _stop) { bit_clear(_name, _start); ++_start; } } while (0x0)
/** Set bits from `start` to `stop` in bitstring */
#define bit_nset(name, start, stop)   do { bitstr_t* _name = name; register int _start = start, _stop = stop; while (_start <= _stop) { bit_set(_name, _start); ++_start; } } while (0x0)
/** Find first bit clear in name */
#define bit_ffc(name, nbits, value)   do { bitstr_t* _name = name; register int _bit, _nbits = nbits, _value = -1; for (_bit = 0; _bit < _nbits; ++_bit) { if (!bit_test(_name, _bit)) { _value = _bit; break; } } *(value) = _value; } while (0x0)
/** Find first bit set in name */
#define bit_ffs(name, nbits, value)   do { bitstr_t* _name = name; register int _bit, _nbits = nbits, _value = -1; for (_bit = 0; _bit < _nbits; ++_bit) { if (bit_test(_name, _bit)) { _value = _bit; break; } } *(value) = _value; } while (0x0)


// LOGIC GATES & BASIC MATH MACROS

#if IS_GNUC
/** Return the absolute value of an integral value */
#   define abs(x)   __extension__ ({ (((x) >= 0) ? (x) : (-(x))); })
/** Return the absolute value of the difference between two integral values */
#   define absdiff(x, y)   __extension__ ({ const auto_type _x = x; const auto_type _y = y; (_x > _y) ? (_x - _y) : (_y - _x); })
#   define CONSTRAIN(amount, low, high)   __extension__ ({ const auto_type _amount = (amount); const auto_type _low = (low); const auto_type _high = (high); ((_amount) < (_low) ? (_low) : ((_amount) > (_high) ? (_high) : (_amount)))})
#   ifndef CLAMP
/** Computes the value of the first specified argument clamped to a range defined by the second and third specified arguments */
#      define CLAMP(x, low, high)   __extension__ ({ (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x))); })
#   endif
#   define _MAX_INT(x, y)   __extension__ ({ (x ^ ((x ^ y) & -(x < y))); })
#   define _MIN_INT(x, y)   __extension__ ({ (y ^ ((x ^ y) & -(x < y))); })
#   define MAX(x, y)   __extension__ ({ const auto_type _x = (x); const auto_type _y = (y); (_x > _y) ? _x : _y; })
#   define MIN(x, y)   __extension__ ({ const auto_type _x = (x); const auto_type _y = (y); (_x > _y) ? _y : _x; })
#   define SWAP(x, y)   __extension__ ({ const auto_type __tmp = (x); (x) = (y); (y) = __tmp; })
#   define AND(x, y)  __extension__ ({ const auto_type _x = (x); const auto_type _y = (y); (_x & _y); })
#   define AND3(x, y, z)  __extension__ ({ const auto_type _x = (x); const auto_type _y = (y); const auto_type _z = (z); ((_x & _y) & _z); })
#   define OR(x, y)   __extension__ ({ const auto_type _x = (x); const auto_type _y = (y); (_x | _y); })
#   define NAND(x, y)   __extension__ ({ const auto_type _x = (x); const auto_type _y = (y); ~(_x & _y); })
#   define NOR(x, y)   __extension__ ({ const auto_type _x = (x); const auto_type _y = (y); ~(_x | _y); })
#   define XOR(x, y)   __extension__ ({ const auto_type _x = (x); const auto_type _y = (y); (_x ^ _y); })
#   define XNOR(x, y)   __extension__ ({ const auto_type _x = (x); const auto_type _y = (y); ~(_x ^ _y); })
#   define NXOR(x, y)   __extension__ ({ const auto_type _x = (x); const auto_type _y = (y); ~(_x ^ _y); })
#   define mix(a, b, c)    __extension__ ({ \
	auto_type x = (a); auto_type y = (b); auto_type z = (c); \
	x -= y; x -= z; x ^= (z >> 13); \
	y -= z; y -= x; y ^= (x << 8); \
	z -= x; z -= y; z ^= (y >> 13); \
	x -= y; x -= z; x ^= (z >> 12); \
	y -= z; y -= x; y ^= (x << 16); \
	z -= x; z -= y; z ^= (y >> 5); \
	x -= y; x -= z; x ^= (z >> 3); \
	y -= z; y -= x; y ^= (x << 10); \
	z -= x; z -= y; z ^= (y >> 15); \
	a = x; b = y; c = z; \
})
#   ifndef howmany
/** Macros for counting how many times y fits in x */
#      define howmany(x, y)   __extension__ ({ (((x) + ((y) - 1)) / (y)); })
#   endif
#   ifndef __ispowerof2
/** Test if the value is a power of two */
#      define __ispowerof2(n)   __extension__ ({ (!(((n) - 1) & (n))); })
#   endif
/** Test if the value is a power of two */
#   define powerof2(n)   __extension__ ({ (!(((n) - 1) & (n))); })
#else
/** Return the absolute value of an integral value */
#   define abs(x)   (((x) >= 0) ? (x) : (-(x)))
/** Return the absolute value of the difference between two integral values */
#   define absdiff(x, y)   (((x) > (y)) ? ((x) - (y)) : ((y) - (x)))
#   define CONSTRAIN(amount, low, high)   ((amount) < (low) ? (low) : ((amount) > (high) ? (high) : (amount)))
#   ifndef CLAMP
/** Computes the value of the first specified argument clamped to a range defined by the second and third specified arguments */
#      define CLAMP(x, low, high)   (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))
#   endif
#   define _MAX_INT(x, y)   (x ^ ((x ^ y) & -(x < y)))
#   define _MIN_INT(x, y)   (y ^ ((x ^ y) & -(x < y)))
#   define MAX(x, y)   (((y) > (x)) ? (y) : (x))
#   define MIN(x, y)   (((y) < (x)) ? (y) : (x))
#   define SWAP(x, y)   ((y) = (x), (x) = (y))
#   define AND(x, y)   ((x) & (y))
#   define AND3(x, y, z)   (((x) & (y)) & (z))
#   define OR(x, y)   ((x) | (y))
#   define NAND(x, y)   (~((x) & (y)))
#   define NOR(x, y)   (~((x) | (y)))
#   define XOR(x, y)   ((x) ^ (y))
#   define XNOR(x, y)   (~((x) ^ (y)))
#   define NXOR(x, y)   (~((x) ^ (y)))
#   define mix(a, b, c)   do { \
	a -= b; a -= c; a ^= (c >> 13); \
	b -= c; b -= a; b ^= (a << 8); \
	c -= a; c -= b; c ^= (b >> 13); \
	a -= b; a -= c; a ^= (c >> 12); \
	b -= c; b -= a; b ^= (a << 16); \
	c -= a; c -= b; c ^= (b >> 5); \
	a -= b; a -= c; a ^= (c >> 3); \
	b -= c; b -= a; b ^= (a << 10); \
	c -= a; c -= b; c ^= (b >> 15); \
} while (0x0)
#   ifndef howmany
/** Macros for counting how many times y fits in x */
#      define howmany(x, y)   (((x) + ((y) - 1)) / (y))
#   endif
#   ifndef __ispowerof2
/** Test if the value is a power of two */
#      define __ispowerof2(n)   (!(((n) - 1) & (n)))
#   endif
/** Test if the value is a power of two */
#   define powerof2(n)   (!(((n) - 1) & (n)))
#endif  // LOGIC GATES, MAX, MIN, ETC. MACROS
/** Return true if the signs of the two values are opposite */
#define are_signs_opposite(x, y)   (((x) ^ (y)) < 0)
#define ORSWAP(x, y)   ((x) |= (y), (x) |= (y), (x) |= (y))
#define XORSWAP(x, y)   ((x) ^= (y), (x) ^= (y), (x) ^= (y))
#define MIX(a, b, c)   mix((a), (b), (c))
/** Return the absolute value of an integral value */
#define ABS(x)   abs((x), (y))
#ifndef gnu_abs
/** Return the absolute value of an integral value */
#   define gnu_abs(n)    abs((n))
#endif
#define constrain(amount, low, high)   CONSTRAIN((amount), (low), (high))
#define MAXVAL(t, b)    ((t)(((t)1 << ((b) - 1 - TYPE_SIGNED(t))) - 1 + ((t)1 << ((b) - 1 - TYPE_SIGNED(t)))))
#define MINVAL(t, b)   ((t)(TYPE_SIGNED(t) ? (-(TWOS_COMPLEMENT(b) - MAXVAL(t, b))) : 0))
#ifndef INT_STRLEN_MAXIMUM
#   define INT_STRLEN_MAXIMUM(type)   (((TYPE_BIT(type) - TYPE_SIGNED(type)) * 302) / 1000 + 1 + TYPE_SIGNED(type))
#endif
/** Round up to the next power-of-2 that is equal-to or less-than the mask */
#define P2ROUNDUP(x, __mask)   (-(-(x) & (-(__mask))))
#define P2PHASEUP(x, align, phase)   ((phase) - (((phase) - (x)) & (-(align))))
#define ROUND_UP_NEXT_128(x)   (((x) + 128) & 128)
#define ROUND_DOWN_128(x)   ((x) & 128)
/** Macros to avoid undefined behaviour that can arise if the amount of a shift is exactly equal to the size of the shifted operand */
#define SAFE_LEFT_SHIFT(op, amt)   (((amt) < (NBBY * sizeof(op))) ? ((op) << (amt)) : 0)
/** Macros to avoid undefined behaviour that can arise if the amount of a shift is exactly equal to the size of the shifted operand */
#define SAFE_RIGHT_SHIFT(op, amt)   (((amt) < (NBBY * sizeof(op))) ? ((op) >> (amt)) : 0)
/** Long zero */
#define __zerolong()   0L
/** Long zero */
#define zerolong()   __zerolong()
/** Unsigned long zero */
#define __zeroul()   0UL
/** Unsigned long zero */
#define zeroul()   __zeroul()
/** Long long zero */
#define __zeroll()   0LL
/** Long long zero */
#define zeroll()   __zeroll()
/** Unsigned long long zero */
#define __zeroull()   0ULL
/** Unsigned long long zero */
#define zeroull()   __zeroull()

/** @} */  // }


#endif  // BIT_MACROS_H


/* ALIGNMENT (<stdalign.h>) */


#if (!(defined(STDALIGN_H) || defined(__STDALIGN_H) || defined(__STDALIGN_H_) || defined(_ALIGNOF_H)))  // https://www.gnu.org/software/gnulib/manual/html_node/stdalign_002eh.html & https://www.ibm.com/support/knowledgecenter/SSLTBW_2.1.0/com.ibm.zos.v2r1.bpxbd00/stdalign.htm
#define STDALIGN_H   (1)
#define _STDALIGN_H   (1)
#define __STDALIGN_H   (1)
#define __STDALIGN_H_   (1)
#define _ALIGNOF_H   (1)
#define STRUCT_H   (1)
#define _STRUCT_H   (1)
#define _STRUCT_H_   (1)


#ifdef __BIGGEST_ALIGNMENT__
#   define BIGGEST_ALIGNMENT   __BIGGEST_ALIGNMENT__
#elif (!LDBL_EQ_DBL)
#   define __BIGGEST_ALIGNMENT__   (16)
#   define BIGGEST_ALIGNMENT   __BIGGEST_ALIGNMENT__
#else
#   define __BIGGEST_ALIGNMENT__   (16)
#   define BIGGEST_ALIGNMENT   __BIGGEST_ALIGNMENT__
#endif
#ifndef LARGEST_ALIGNMENT
#   define LARGEST_ALIGNMENT   __BIGGEST_ALIGNMENT__
#endif
#ifndef TCB_ALIGNMENT
#   define TCB_ALIGNMENT   SIZEOF_DOUBLE
#endif
#ifndef IS_BIGGEST_ALIGNMENT_8
#   define IS_BIGGEST_ALIGNMENT_8   (__BIGGEST_ALIGNMENT__ == 8)
#endif
#ifndef IS_BIGGEST_ALIGNMENT_16
#   define IS_BIGGEST_ALIGNMENT_16   (__BIGGEST_ALIGNMENT__ == 16)
#endif
#ifndef IS_BIGGEST_ALIGNMENT_32
#   define IS_BIGGEST_ALIGNMENT_32   (__BIGGEST_ALIGNMENT__ == 32)
#endif
#ifndef IS_BIGGEST_ALIGNMENT_64
#   define IS_BIGGEST_ALIGNMENT_64   (__BIGGEST_ALIGNMENT__ == 64)
#endif

/** Align the given pointer */
#define alignto(ptr, bits)   (((ptr) >> bits) << bits)
/** Add an aligned increment to the given pointer */
#define aligntonext(ptr, bits)   alignto(((ptr) + (1 << bits) - 1), bits)


// OFFSETOF

#undef offsetof
#ifndef offsetof
/** Evaluates to the offset (in bytes as size_t) of a given member within a struct or union */
#   define offsetof(type, member)   ((size_t)(&((type*)0)->member))  // (__builtin_offsetof(type, member))
#endif
#ifndef ioffsetof
/** Evaluates to the offset (in bytes as int) of a given member within a struct or union */
#   define ioffsetof(type, member)   ((int)(ssize_t)(&((type*)0)->member))  // (__builtin_offsetof(type, member))
#endif
/** Evaluates to the offset (in bytes as size_t) of a given member within a struct or union */
#define __offsetof(type, member)   offsetof((type), (member))
/** Evaluates to the offset (in bytes as size_t) of a given member within a struct or union */
#define OFFSETOF(type, member)   offsetof((type), (member))
/** Evaluates to the offset (in bytes as size_t) of a given member within a struct or union */
#define _offsetof(type, member)   offsetof((type), (member))
/** Evaluates to the offset (in bytes as size_t) of a given member within a struct or union */
#define __offsetof__(type, member)   offsetof((type), (member))


// CONTAINER_OF

#if IS_GNUC
/** Used to retrieve an enclosing structure from a pointer to a nested element */
#   define container_of(ptr, type, member)   __extension__ ({ do { const typeof(((type*)0)->member) *__mptr = (ptr); (type*)((char*)__mptr - offsetof(type, member)); } while (0x0) })
#else
/** Used to retrieve an enclosing structure from a pointer to a nested element */
#   define container_of(ptr, type, member)   ((type*)((char*)(1 ? (ptr) : &((type*)0)->member) - offsetof(type, member)))
#endif  // container_of
#ifndef SIZEOF
/** Get the size of any member of a typedef without having to actually declare a variable of that datatype */
#   define SIZEOF(obj, member)   ((size_t)sizeof(((obj*)0)->member))
#endif


// ALIGNOF

#if (IS_STDC11 && IS_NOT_CPLUSPLUS && IS_NOT_GNUC)
/** Return the natural alignment (in bytes) for the given type */
#   define __alignof(_type)   _Alignof(_type)
#elif IS_GNUC
/** Return the natural alignment (in bytes) for the given type */
#   define __alignof(_type)   __alignof__(_type)
#elif (defined(OSHPUX) || defined(OSAIX))
/** Work around a HP-UX 10.20 cc bug and AIX 3.2.5 xlc bug with enums constants defined as offsetof values */
#   define __alignof(_type)   ((sizeof(_type) <= 4) ? 4 : 8)
#else
/** Return the natural alignment (in bytes) for the given type */
#   define __alignof(_type)   (sizeof(struct { char __x; _type __y; }) - sizeof(_type))
#endif
#if IS_NOT_CPLUSPLUS
#   if (IS_STDC_BELOW_C11 && IS_GNUC)
/** Return the natural alignment (in bytes) for the given type */
#      define _Alignof(_type)    __alignof(_type)
#   endif
#   ifndef alignof
/** Return the natural alignment (in bytes) for the given type */
#      define alignof(_type)   __alignof(_type)
#   endif
#endif
/** Return the natural alignment (in bytes) for the given type */
#define sa_alignof(_type)   _Alignof(_type)
/** Return the natural alignment (in bytes) for the given type */
#define alignof_type(_type)   _Alignof(_type)
#undef __IBM__ALIGNOF__
/** Return the natural alignment (in bytes) for the given type */
#define __IBM__ALIGNOF__(_type)   _Alignof(_type)
/** Return the natural alignment (in bytes) for the given type */
#define IBM__ALIGNOF(_type)   _Alignof(_type)
#if IS_NOT_CPLUSPLUS
/** Return the natural alignment (in bytes) for the given type */
#   define alignment_of(_type)   _Alignof(_type)
#endif
#define __alignof_is_defined   (1)


// ALIGNAS

#if IS_NOT_CPLUSPLUS
#   if IS_STDC_BELOW_C11
/** Used in declaration syntax as a type specifier to modify the alignment requirement of the object being declared */
#      define _Alignas(_type)    aligned(_type)
#   endif
#   if (!(defined(alignas) || defined(__alignas_is_defined)))
/** Used in declaration syntax as a type specifier to modify the alignment requirement of the object being declared */
#      define alignas(_type)   _Alignas(_type)
#   endif
#endif
/** Used in declaration syntax as a type specifier to modify the alignment requirement of the object being declared */
#define sa_alignas(_type)   alignoas(_type)
#define __alignas_is_defined   (1)


// ALIGNOF_SLOT

#if IS_CPLUSPLUS
	template <class type> struct alignof_helper { char __slot1; type __slot2; };
/** Determine the alignment of a structure slot (field) of a given type at compile time */
#   define alignof_slot(type)   offsetof(alignof_helper<type>, __slot2)
#else
/** Determine the alignment of a structure slot (field) of a given type at compile time */
#   define alignof_slot(type)   offsetof(struct { char __slot1; type __slot2; }, __slot2)
#endif  // alignof_slot
#define __alignof_slot_is_defined   1


// ASSUME_ALIGNED

/** @def assume_aligned
The object pointed to by the given pointer is x-aligned; a third optional argument indicates the offset */
/** @def ATTR_ALIGN_TO
Align the data-structure like the specified object */
#if IS_GNUC
#   define assume_aligned(a, ...)   __attribute__((__assume_aligned__(a, ## __VA_ARGS__)))
#   define ATTR_ALIGN_TO(param)   __attribute__((__aligned__(__alignof__(param))))
#else
#   define assume_aligned(a, ...)
#   define ATTR_ALIGN_TO(param)
#endif


// BASEOF

#define BASEOF(ptr, str_type, field)   ((struct str_type*)((char*)ptr - offsetof(str_type, field)))


// FIELD OFFSET

/** Offset of the field in the structure */
#define fldoff(name, field)   ((int)&(((struct name*)0)->field))
/** Size of the field in the structure */
#define fldsiz(name, field)   (sizeof(((struct name*)0)->field))
/** Address of the structure from a field */
#define strbase(name, addr, field)   ((struct name*)((char*)addr - fldoff(name, field)))


// STRIDEOF

#define strideof(obj)   sizeof(obj)


// UNALIGNED

#define UNALIGNED(x, y)   (((unsigned long)x & (SIZEOF_LONG - 1)) ^ ((unsigned long)y & (SIZEOF_LONG - 1)))


/** The increment that guarantees room for a magic word must be >= BYTES_PER_INT and a multiple of sa_alignment_max */
#define sa_increment   (((BYTES_PER_INT + sa_alignment_max - 1) / sa_alignment_max) * sa_alignment_max)
#ifndef _ALIGNBYTES
#   ifdef __ALIGNBYTES
#      define _ALIGNBYTES   __ALIGNBYTES
#   else
#      define _ALIGNBYTES   7
#   endif
#endif
#ifndef ALIGNBYTES
#   define ALIGNBYTES   _ALIGNBYTES
#endif
#ifndef _ALIGN
#   define _ALIGN(p)   (((unsigned long long)(p) + (unsigned long long)(_ALIGNBYTES)) & (unsigned long long)(~(_ALIGNBYTES)))
#endif
#ifndef ALIGN
#   define ALIGN(p)   _ALIGN((p))
#endif
#define ALIGNBYTES32   31
#define ALIGN32(p)   ((size_t)((char*)(size_t)(p) + 31) & 0xffffffe0)
#define ALIGNBYTES64   63
#define ALIGN64(p)   ((size_t)((char*)(size_t)(p) + 63) & 0xffffffc0)
/** Align a value by rounding down to closest size; Using size of 4096, we get this behavior: {4095, 4096, 4097} = {0, 4096, 4096} */
#define ALIGN_DOWN(base, size)   ((base) & (-((typeof(base))(size))))
/** Align a value by rounding up to closest size; Using size of 4096, we get this behavior: {4095, 4096, 4097} = {4096, 4096, 8192} */
#define ALIGN_UP(base, size)   ALIGN_DOWN((base) + (size) - 1, (size))
/** Same as ALIGN_DOWN(), but automatically casts when base is a pointer */
#define PTR_ALIGN_DOWN(base, size)   ((typeof(base)) ALIGN_DOWN((uintptr_t)(base), (size)))
/** Same as ALIGN_UP(), but automatically casts when base is a pointer */
#define PTR_ALIGN_UP(base, size)   ((typeof(base)) ALIGN_UP((uintptr_t)(base), (size)))
#ifndef IS_P2ALIGNED
#   define IS_P2ALIGNED(v, a)   ((((uintptr_t)(v)) & ((uintptr_t)(a) - 1)) == 0)
#endif
#ifndef P2ROUNDUP
#   define P2ROUNDUP(x, align)   (-(-((uintptr_t)(x)) & (-((uintptr_t)align))))
#endif
#ifndef P2ROUNDDOWN
#   define P2ROUNDDOWN(x, align)   (((uintptr_t)(x)) & (~((uintptr_t)(align) - 1)))
#endif


// CLUSTERING OF HARDWARE PAGES

#define RHSDIM   1
#define BALANCETH   2
#define RBDIM   8
#define RBSIZE   64
#define SLACKNESS   8
#define BREAKEVEN   4
#define MINNNZTOPAR   128
#define BREAKNRB   1
#define MINNRBTOPAR   32
#define CLSIZE   64
#define CLBYTES   (CLSIZE * NBPG)
/** PGOFSET for clusters */
#define CLOFSET   (CLSIZE * NBPG - 1)
#define claligned(x)   ((((int)(x)) & CLOFSET) == 0)
#define CLOFF   CLOFSET
#define CLSHIFT   (PGSHIFT + CLSIZELOG2)
#if (CLSIZE == 1)
#   define clbase(i)   (i)
#   define clrnd(i)   (i)
#else
/** Give the base virtual address (first of CLSIZE) */
#   define clbase(i)   ((i) & (~(CLSIZE - 1)))
/** Round a number of clicks up to a whole cluster */
#   define clrnd(i)   (((i) + (CLSIZE - 1)) & (~(CLSIZE - 1)))
#endif
/** Clist block size; must be a power of 2 */
#define CBLOCK   64
/** bytes/cblock */
#define CBQSIZE   (CBLOCK / NBBY)
/** Clist rounding */
#define CROUND   (CBLOCK - 1)
/** Units of memory less or equal to MAXALLOCSAVE will permanently allocate physical memory; requests for these size pieces of memory are quite fast; Allocations greater than MAXALLOCSAVE must always allocate and free physical memory; requests for these size allocations should be done infrequently as they will be slow */
#define MAXALLOCSAVE   (2 * CLBYTES)


#if (!(defined(_ALIGN_64_BIT_H) || defined(_ALIGN_64_BIT_H_)))  // GET 64-BIT STRUCT ALIGNMENT
#define ALIGN_64_BIT_H   (1)
#define _ALIGN_64_BIT_H   (1)
#define _ALIGN_64_BIT_H_   (1)


typedef struct __longlong_aligned { long long x; }   longlong_aligned_t;
/** Simple macro for getting the 64-bit struct arch alignment */
#define __ARCH_64BIT_ALIGNMENT__   ATTR_ALIGN_TO(struct __longlong_aligned)
/** Simple macro for getting the 64-bit struct arch alignment */
#define ARCH_64BIT_ALIGNMENT   __ARCH_64BIT_ALIGNMENT__
/** Simple macro for getting the 64-bit struct arch alignment */
#define _64BIT_ALIGNMENT   __ARCH_64BIT_ALIGNMENT__


#endif  // ALIGN_64_BIT_H


// MAX_ALIGN_T

#ifndef _GCC_MAX_ALIGN_T
#   define _GCC_MAX_ALIGN_T   (1)
#   define __CLANG_MAX_ALIGN_T_DEFINED   (1)
#   ifdef MICROSOFT_VISUAL  // max_align_t
/** max_align_t is a type whose alignment requirement is at least as strict (as large) as that of every scalar type */
typedef double   max_align_t;
#   elif (SUPPORTS_LONG_DOUBLE && (defined(__APPLE__) || IS_GNUC))
/** max_align_t is a type whose alignment requirement is at least as strict (as large) as that of every scalar type */
typedef long double   max_align_t;
#   elif (defined(__BIGGEST_ALIGNMENT__) && (__BIGGEST_ALIGNMENT__ == 8))
/** max_align_t is a type whose alignment requirement is at least as strict (as large) as that of every scalar type */
typedef double   max_align_t;
#   elif (SUPPORTS_LONG_DOUBLE && defined(__BIGGEST_ALIGNMENT__) && (__BIGGEST_ALIGNMENT__ == BYTES_PER_LONG_DOUBLE))
/** max_align_t is a type whose alignment requirement is at least as strict (as large) as that of every scalar type */
typedef long double   max_align_t;
#   else
/** max_align_t is a type whose alignment requirement is at least as strict (as large) as that of every scalar type */
typedef struct max_align {
	align_ldbl long long __clang_max_align_nonce1;
	align_ldbl long double __clang_max_align_nonce2;
} max_align_t;
#   endif  // max_align_t
#endif  // MAX_ALIGN_T


/** The macro SAFE_CAST_PTR() casts one type of pointer to another type, making sure the data the pointer is referencing is the same size; If it is not, it will cause a division by zero compiler warning */
#define __SAFE_CAST_PTR(type, var)   (((type)(var)) + (0 / (sizeof(*var) == sizeof(*type 0) ? 1 : 0)))
/** The macro SAFE_CAST_PTR() casts one type of pointer to another type, making sure the data the pointer is referencing is the same size; If it is not, it will cause a division by zero compiler warning */
#define SAFE_CAST_PTR(type, var)   __SAFE_CAST_PTR((type), (var))
#define __CAST_PTR(type, var)   ((type)(var))
#define CAST_PTR(type, var)   ((type)(var))


#endif  // STDALIGN_H


/* STANDARD MACROS */


#ifndef STANDARD_MACROS_SEEN
#define STANDARD_MACROS_SEEN   (1)
#define _LIBC_NAMESPACE_H_   (1)
#define _LIBC_SYMBOLS_H   (1)
#define _LIBC_SYMBOLS_H_   (1)
#define _ANSIDECL_H   (1)
#define _ANSIDECL_H_   (1)
#define __EA_INTERNAL_H   (1)
#define SYSTEMGNU_H   (1)
#define _SYSTEMGNU_H_   (1)
#define _SYS_CDEFS_ELF_H_   (1)
#define _SYS_CDEFS_H   (1)
#define _SYS_CDEFS_H_   (1)
#define _BSD_SYS_CDEFS_H_   (1)
#define _MACHINE_CDEFS_H_   (1)
#define _MIPS_CDEFS_H_   (1)
#define DEFS_H_   (1)
#define _WINDEF_   (1)
#define _WINDEF_H_   (1)
#define _FBSD_COMPAT_H_  (1)
#define __FBSD_COMPAT__H   (1)
#define __FBSD_COMPAT__H_   (1)
#define __NBSD_COMPAT__H   (1)
#define __NBSD_COMPAT__H_   (1)
#define __NETBSD_COMPAT_DEFS_H__   (1)
#define _SHLIB_COMPAT_H   (1)
#define _KLIBC_EXTERN_H   (1)
#define _KLIBC_COMPILER_H   (1)
#define _INC_MINMAX   (1)
#define _INC_CRTDEFS_MACRO   (1)
#define _YVALS   (1)


// PYBOOSTER LIBRARY INTERFACE MACROS

#ifndef LIB_FUNC
#   if IS_LINTER
#      define LIB_FUNC   /*@unused@*/
#   elif defined(LIB_NO_DYNAMIC)
#      define LIB_FUNC   UNUSED
#   else
#      define LIB_FUNC   static UNUSED
#   endif
#endif
#ifndef DECL_FUNC
#   if defined(LIB_FUNC)
#      define DECL_FUNC   LIB_FUNC
#   else
#      define DECL_FUNC   static UNUSED
#   endif
#endif
#ifndef MATH_FUNC
#   if IS_LINTER
#      define MATH_FUNC
#   else
#      define MATH_FUNC   NOLIBCALL ATTR_CF WUR
#   endif
#endif


// HELPER FUNCTIONS, CONSTANTS, & VARIABLES

DECL_FUNC int not_null_ptr(const void* restrict ptr);
/** Defeat compiler optimizations that assume function addresses are never NULL */
LIB_FUNC int not_null_ptr(/*@unused@*/ const void* restrict ptr) {
	/*@-usedef@*/
	const void* restrict q;
	vasm(";" : "=rm"(q) : "0"(ptr));
	return (int)(q != 0);
	/*@=usedef@*/
}


static const UNUSED align512 unsigned char integer_table[264] = {
	0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU,
	0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU,
	0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU,
	0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU,
	0xffU, 10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U, 24U,
	25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU,
	0xffU, 10U, 11U, 12U, 13U, 14U, 15U, 16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U, 24U,
	25U, 26U, 27U, 28U, 29U, 30U, 31U, 32U, 33U, 34U, 35U, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU,
	0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU,
	0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU,
	0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU,
	0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU,
	0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU,
	0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU,
	0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU,
	0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU
};
static const UNUSED align32 int positive_tens[8] = { 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
#ifndef PADSIZE
/** Pad chunk size */
#   define PADSIZE   16
#endif
static const UNUSED align16 char fcvt_zeros[16] = "000000000000000";
static const UNUSED align16 char blanks[PADSIZE] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
static const UNUSED align16 char zeroes[PADSIZE] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
static const UNUSED align4 char period[2] = ".";
#define _ALPHABET   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define _alphabet   "abcdefghijklmnopqrstuvwxyz"
#define _numbers   "0123456789"
#define _digits   _numbers
#define _hexnumbers   "0123456789ABCDEFabcdef"
#define _hexdigits   _hexnumbers
static const UNUSED align16 char digits[16] = _numbers;
#define str_digit   digits
static const UNUSED align32 char hexdigits[32] = _hexnumbers;
#define xdigits   hexdigits
static const UNUSED align32 char xdigits_l[32] = "0123456789abcdef";
static const UNUSED align32 char xdigits_u[32] = "0123456789ABCDEF";
#define hexdigits_l   xdigits_l
#define hexdigits_u   xdigits_u
static const UNUSED align16 char octal_digits[16] = "01234567";
static const UNUSED align32 char ALPHABET[32] = _ALPHABET;
static const UNUSED align32 char alphabet[32] = _alphabet;
static const UNUSED align128 char a64l_digits[65] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
/** Upper-case digits */
static const UNUSED align128 char _itoa_upper_digits[64] = _numbers _ALPHABET;
/** Lower-case digits */
static const UNUSED align64 char _itoa_lower_digits[64] = _numbers _alphabet;
static const UNUSED align4 char not_available[4] = "\377";
static const UNUSED align8 char null_indicator[8] = "(NULL)";
static const UNUSED align2 char empty[2] = "";
static const UNUSED align2 char null_char[2] = "\0";
static const UNUSED align4 char NEWLINE[4] = { '\n', '\n', '\0', '\0' };
/** The set of "direct characters": A-Z a-z 0-9 ' ( ) , - . / : ? space tab lf cr */
static const UNUSED align16 unsigned char direct_tab[16] = {
	0U, 0x26U, 0U, 0U, 0x81U, 0xf3U, 0xffU, 0x87U, 0xfeU, 0xffU, 0xffU, 7U, 0xfeU, 0xffU, 0xffU, 7U
};
/** The set of "direct and optional direct characters": A-Z a-z 0-9 ' ( ) , - . / : ? space tab lf cr ! " # $ % & * ; < = > @ [ ] ^ _ ` { | } */
static const UNUSED align16 unsigned char xdirect_tab[16] = {
	0U, 0x26U, 0U, 0U, 0xffU, 0xf7U, 0xffU, 0xffU, 0xffU, 0xffU, 0xffU, 0xefU, 0xffU, 0xffU, 0xffU, 0x3fU
};
/** The set of "extended base64 characters": A-Z a-z 0-9 + / - */
static const UNUSED align16 unsigned char xbase64_tab[16] = {
	0U, 0U, 0U, 0U, 0U, 0xa8U, 0xffU, 3U, 0xfeU, 0xffU, 0xffU, 7U, 0xfeU, 0xffU, 0xffU, 7U
};
static const UNUSED align64 int nibblemap[16] = { 4, 3, 3, 2, 3, 2, 2, 1, 3, 2, 2, 1, 2, 1, 1, 0 };
#define A64L_TABLE_BASE   46
#define A64L_TABLE_SIZE   77
static const UNUSED align128 char a64l_table[77] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
	0x40, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
	27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 0x40, 0x40, 0x40, 0x40, 0x40,
	0x40, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
	53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63
};


// GLOBAL CODE VARIABLES

UNUSED char** environ = NULL;
#define __environ   environ
#define ___environ   environ
#define _environ   environ
#define environ   environ
UNUSED char** __env_map = NULL;
static atomic volatile UNUSED int exit_counter;
static volatile UNUSED int progslot;
static atomic volatile UNUSED align8 int tmlock[2] = { 0, 0 };
static atomic volatile UNUSED align8 int memlock[2] = { 0, 0 };
static const UNUSED align8 unsigned int __page_size = (unsigned int)PAGE_SIZE;
static const UNUSED align8 unsigned int __page_shift = (unsigned int)PAGE_SHIFT;
#define __getpagesize()   ((unsigned int)__page_size)
#define getpagesize()   ((unsigned int)__page_size)
#define __getpageshift()   ((unsigned int)__page_shift)
#define getpageshift()   ((unsigned int)__page_shift)


#endif  // STANDARD_MACROS_SEEN


/* ARCHITECTURE MACROS */


#ifndef ARCHITECTURE_MACROS_SEEN
#define ARCHITECTURE_MACROS_SEEN   (1)
#define SYS_REG_H   (1)
#define _SYS_REG_H   (1)
#define _SYS_REG_H_   (1)


// ARM MACROS

#if ((!(defined(_ARM_CDEFS_H) || defined(_ARM_CDEFS_H_))) && defined(ARCHARM))
#define _ARM_CDEFS_H   (1)
#define _ARM_CDEFS_H_   (1)
#define _ARM_IPCCONST_H_   (1)
#define _ARM_CONST_H   (1)
#define _EVBARM_TYPES_H_   (1)


#if (defined(_ARM_ARCH_T2) || (!defined(ARM_THUMB) && (defined(ARM_6_SERIES) || defined(__ARM_ARCH_5TE__) || defined(__ARM_ARCH_5TEJ__))))
#   define _ARM_ARCH_DWORD_OK   1
#endif
#ifdef __ARM_PCS_AAPCS64
#   define __ALIGNBYTES   15
#elif defined(__ARM_EABI__)
#   define __ALIGNBYTES   (BYTES_PER_LONG_LONG - 1)
#else
#   define __ALIGNBYTES   31
#endif

typedef struct label_t { int val[11]; }   label_t;
typedef unsigned long   paddr_t;
typedef unsigned long   psize_t;
typedef unsigned long   vaddr_t;
typedef unsigned long   vsize_t;
typedef unsigned long   pmc_evid_t;
#define PMC_INVALID_EVID   (-1)
typedef unsigned long   pmc_ctr_t;
typedef unsigned short   tlb_asid_t;
#ifdef _KERNEL
typedef unsigned char   __cpu_simple_lock_nv_t;
#else
typedef int   __cpu_simple_lock_nv_t;
#endif
typedef volatile __cpu_simple_lock_nv_t   __cpu_simple_lock_t;

#define DEFAULT_HZ   1000
#define __SIMPLELOCK_LOCKED   1
#define __SIMPLELOCK_UNLOCKED   0
#define __HAVE_SYSCALL_INTERN
#define __HAVE_NEW_STYLE_BUS_H
#define __HAVE_MINIMAL_EMUL
#define __HAVE_CPU_DATA_FIRST
#define __HAVE___LWP_GETPRIVATE_FAST
#define __HAVE_COMMON___TLS_GET_ADDR
#ifndef OSMINIX
#   define __HAVE_TLS_VARIANT_I
#endif
#define __HAVE_OLD_DISKLABEL
#if (defined(__ARM_EABI__) && defined(_ARM_ARCH_6))
#   define __HAVE_ATOMIC64_OPS
#endif
#if (defined(_KERNEL) || defined(_KMEMUSER))
#   define PCU_FPU   0
#   define PCU_UNIT_COUNT   1
#endif
#ifdef _KERNEL
#   define __HAVE_RAS
#endif
/** Syscall trap to kernel */
#define KERVEC_INTR   32
/** IPC trap to kernel */
#define IPCVEC_INTR   33
#define IPC_STATUS_REG   r1


#endif  // ARM


// X86, X86-64, & I386 MACROS

#ifdef ARCHX86
#define _I386_IPCCONST_H_   (1)
#define _I386_CONST_H   (1)


/** Processor Classes; CPU identification code depends on this starting at 0, and having an increment of one */
enum CPU_CLASS {
	CPUCLASS_386 = 0,
	CPUCLASS_486 = 1,
	CPUCLASS_586 = 2,
	CPUCLASS_686 = 3
};
/** Kinds of Processors; Only the first 7 are used, as they are processors that might not have a cpuid instruction */
enum PROCESSOR_TYPE {
/** Intel 80386SX */
	CPU_386SX = 0,
/** Intel 80386DX */
	CPU_386 = 1,
/** Intel 80486SX */
	CPU_486SX = 2,
/** Intel 80486DX */
	CPU_486 = 3,
/** Cyrix 486DLC */
	CPU_486DLC = 4,
/** Cyrix/IBM 6x86 */
	CPU_6x86 = 5,
/** NexGen 586 */
	CPU_NX586 = 6,
/** Intel Pentium */
	CPU_586 = 7,
/** AMD Am486 and Am5x86 */
	CPU_AM586 = 8,
/** AMD K5 */
	CPU_K5 = 9,
/** NexGen 686 aka AMD K6 */
	CPU_K6 = 10,
/** Intel Pentium Pro */
	CPU_686 = 11,
/** IDT WinChip C6 */
	CPU_C6 = 12,
/** Transmeta TMx86 */
	CPU_TMX86 = 13
};
// CPU vendors
enum X86_VENDORS {
	CPUVENDOR_UNKNOWN = 0,
	CPUVENDOR_INTEL,
	CPUVENDOR_CYRIX,
	CPUVENDOR_NEXGEN,
	CPUVENDOR_AMD,
	CPUVENDOR_IDT,
	CPUVENDOR_TRANSMETA,
	CPUVENDOR_VORTEX86
};
// Values returned by cpuid
/** Lowest that cpuid can return (i486) */
#define CPU_MINFAMILY   4
/** Highest consecutive number known (fake P4) */
#define CPU_MAXFAMILY   7
/** Family number for Pentium 4 */
#define CPU_FAMILY_P4   15
/** Clock freq (software settable on IBM-PC) */
#define DEFAULT_HZ   60


// I386 MACROS
#if ((!(defined(I386_CDEFS_H) || defined(_I386_CDEFS_H) || defined(_I386_CDEFS_H_))) && defined(ARCHX86_32))
#define I386_CDEFS_H   (1)
#define _I386_CDEFS_H_   (1)
#define _I386_CDEFS_H   (1)


#define __ALIGNBYTES   (BYTES_PER_INT - 1)
typedef struct label_t { int val[6]; }   label_t;

#ifdef _KERNEL
#   ifdef PAE
typedef unsigned long long   paddr_t;
typedef unsigned long long   psize_t;
#   else
typedef unsigned long   paddr_t;
typedef unsigned long   psize_t;
#   endif  // PAE
#else
typedef unsigned long long   paddr_t;
typedef unsigned long long   psize_t;
#endif  // _KERNEL
typedef unsigned long   vaddr_t;
typedef unsigned long   vsize_t;
typedef int   pmc_evid_t;
typedef unsigned long long   pmc_ctr_t;
typedef unsigned char   __cpu_simple_lock_nv_t;
typedef volatile __cpu_simple_lock_nv_t   __cpu_simple_lock_t;

#define __CPU_SIMPLE_LOCK_PAD
#define __SIMPLELOCK_LOCKED   1
#define __SIMPLELOCK_UNLOCKED   0
/** x86 does not have strict alignment requirements */
#define __NO_STRICT_ALIGNMENT
#define __HAVE_NEW_STYLE_BUS_H
#define __HAVE_CPU_DATA_FIRST
#define __HAVE_CPU_COUNTER
#define __HAVE_CPU_BOOTCONF
#define __HAVE_MD_CPU_OFFLINE
#define __HAVE_SYSCALL_INTERN
#define __HAVE_MINIMAL_EMUL
#define __HAVE_OLD_DISKLABEL
#ifdef _KERNEL
#   define __HAVE_ATOMIC64_OPS
#   define __HAVE_RAS
#   if ((!defined(OSXEN)) && (!defined(NO_PCI_MSI_MSIX)))
#      define __HAVE_PCI_MSI_MSIX
#   endif
#endif
#define __HAVE_ATOMIC_AS_MEMBAR
#define __HAVE_CPU_LWP_SETPRIVATE
#define __HAVE_INTR_CONTROL
#define __HAVE_MM_MD_OPEN
#define __HAVE___LWP_GETPRIVATE_FAST
#ifndef OSMINIX
#   define __HAVE_TLS_VARIANT_II
#endif
#define __HAVE_COMMON___TLS_GET_ADDR


#endif  // I386 MACROS


/** Syscall trap to kernel */
#define KERVEC_INTR   32
/** IPC trap to kernel */
#define IPCVEC_INTR   33
/** Syscall trap to kernel, user-mapped code */
#define KERVEC_UM   34
/** IPC trap to kernel, user-mapped code */
#define IPCVEC_UM   35
#define IPC_STATUS_REG   bx


// X86 MACROS
#if ((!(defined(_X86_BUSDEFS_H_) || defined(_X86_BUSDEFS_H) || defined(_X86_BUS_PRIVATE_H_))) && defined(ARCHX86))
#define _X86_BUSDEFS_H   (1)  // <x86/busdefs.h>
#define _X86_BUSDEFS_H_   (1)
#define _X86_BUS_PRIVATE_H   (1)
#define _X86_BUS_PRIVATE_H_   (1)
#define _X86_BUS_H   (1)
#define _X86_BUS_H_   (1)

// Values for the x86 bus space tag, not to be used directly by MI code
/** Space is i/o space */
#define X86_BUS_SPACE_IO   0
/** Space is mem space */
#define X86_BUS_SPACE_MEM   1
#define __BUS_SPACE_HAS_STREAM_METHODS   1
#ifdef BUS_SPACE_DEBUG
#   define BUS_SPACE_ALIGNED_ADDRESS(p, t)   ((((unsigned long)(p)) & (sizeof(t) - 1)) == 0)
#   define BUS_SPACE_ALIGNED_POINTER(p, t)   BUS_SPACE_ALIGNED_ADDRESS(p, t)
#else
#   define BUS_SPACE_ALIGNED_POINTER(p, t)   ALIGNED_POINTER(p, t)
#endif
#define BUS_DMA_TAG_VALID(__t)    ((__t) != NULL)


#endif  // X86_BUSDEFS_H


#ifdef _I386MACH_NEED_SOTYPE_FUNCTION
#   define SOTYPE_FUNCTION(sym)   .type SYM(sym),@function
#else
#   define SOTYPE_FUNCTION(sym)
#endif


#endif  // X86, X86-64, & I386 MACROS


// MIPS MACROS

#if (!(defined(_MIPS_CDEFS_H_) || defined(_SGIDEFS_H) || defined(_SGIDEFS_H_)))  // <sgidefs.h>
#define _MIPS_CDEFS_H_   (1)
#define _SGIDEFS_H   (1)
#define _SGIDEFS_H_   (1)


// Definitions for the ISA level
#define _MIPS_ISA_MIPS1   1
#define _MIPS_ISA_MIPS2   2
#define _MIPS_ISA_MIPS3   3
#define _MIPS_ISA_MIPS4   4
#define _MIPS_ISA_MIPS5   5
#define _MIPS_ISA_MIPS32   6
#define _MIPS_ISA_MIPS64   7
// Subprogram calling convention
#ifndef _ABIO32
#   define _ABIO32   1
#endif
#define _MIPS_SIM_ABI32   _ABIO32
#ifndef _ABIN32
#   define _ABIN32   2
#endif
#define _MIPS_SIM_NABI32   _ABIN32
#ifndef _ABI64
#   define _ABI64   3
#endif
#define _MIPS_SIM_ABI64   _ABI64
#ifndef _ABIO64
#   define _ABIO64   4
#endif


#endif  // MIPS_CDEFS_H


// APPLE MACROS

#ifdef OSAPPLE


#ifndef IOKIT_SERVER_VERSION
#   define IOKIT_SERVER_VERSION   (20150715)
#endif


#if (!(defined(__SYS_APPLEAPIOPTS_H) || defined(__SYS_APPLEAPIOPTS_H__)))
#define __SYS_APPLEAPIOPTS_H   (1)
#define __SYS_APPLEAPIOPTS_H__   (1)


#ifndef __APPLE_API_STANDARD
#   define __APPLE_API_STANDARD
#endif
#ifndef __APPLE_API_STABLE
#   define __APPLE_API_STABLE
#endif
#ifndef __APPLE_API_STRICT_CONFORMANCE
#   ifndef __APPLE_API_EVOLVING
#      define __APPLE_API_EVOLVING
#   endif
#   ifndef __APPLE_API_UNSTABLE
#      define __APPLE_API_UNSTABLE
#   endif
#   ifndef __APPLE_API_PRIVATE
#      define __APPLE_API_PRIVATE
#   endif
#   ifndef __APPLE_API_OBSOLETE
#      define __APPLE_API_OBSOLETE
#   endif  // __APPLE_API_OBSOLETE
#endif  // __APPLE_API_STRICT_CONFORMANCE


#endif  // SYS_APPLEAPIOPTS_H


#endif  // OSAPPLE


// LINUX MACROS

#if (defined(OSLINUX) && (!(defined(KERNEL_FEATURES_H) || defined(_KERNEL_FEATURES_H))))  // FLAGS SIGNALLING KERNEL FEATURES
#define KERNEL_FEATURES_H   (1)
#define _KERNEL_FEATURES_H   (1)


#include <linux/version.h>


#ifndef __LINUX_KERNEL_VERSION
#   define __LINUX_KERNEL_VERSION   0
#endif
#define __ASSUME_SENDFILE   1
#define __ASSUME_ST_INO_64_BIT   1
#define __ASSUME_GETDENTS64_SYSCALL 1
#define __ASSUME_STATFS64   1
#define __ASSUME_PSELECT   1
#define __ASSUME_PPOLL   1
#define __ASSUME_ATFCTS   1
#define __ASSUME_SET_ROBUST_LIST   1
#define __ASSUME_FUTEX_LOCK_PI   1
#define __ASSUME_PRIVATE_FUTEX   1
#define __ASSUME_FALLOCATE   1
#define __ASSUME_O_CLOEXEC   1
#define __ASSUME_IN_NONBLOCK   1
#define __ASSUME_PIPE2   1
#define __ASSUME_EVENTFD2   1
#define __ASSUME_SIGNALFD4   1
#define __ASSUME_DUP3   1
#define __ASSUME_FUTEX_CLOCK_REALTIME   1
#define __ASSUME_PREADV   1
#define __ASSUME_PWRITEV   1
#define __ASSUME_REQUEUE_PI   1
#if (__LINUX_KERNEL_VERSION >= 0x20621)
#   define __ASSUME_PROC_PID_TASK_COMM   1
#endif
#if (__LINUX_KERNEL_VERSION >= 0x20624)
#   define __ASSUME_STATFS_F_FLAGS   1
#   define __ASSUME_PRLIMIT64   1
#endif


#ifdef ARCHX86_64  // AVAILABLE SYSCALLS
/** accept4 syscall */
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x20621)
/** recvmmsg syscall */
#      define __ASSUME_RECVMMSG_SYSCALL   1
#   endif
#   if (__LINUX_KERNEL_VERSION >= 0x30000)
/** sendmmsg syscall */
#      define __ASSUME_SENDMMSG_SYSCALL   1
#   endif
#   if (__LINUX_KERNEL_VERSION >= 0x30100)
/** getcpu is a Linux syscall for x86-64 */
#      define __ASSUME_GETCPU_SYSCALL   1
#   endif
#elif defined(ARCHX86_32)
#   define __ASSUME_SOCKETCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x20621)
#      define __ASSUME_RECVMMSG_SYSCALL   1
#   endif
#   define __ASSUME_RECVMMSG_SYSCALL_WITH_SOCKETCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x30000)
#      define __ASSUME_SENDMMSG_SYSCALL   1
#   endif
#   define __ASSUME_SENDMMSG_SYSCALL_WITH_SOCKETCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x40300)
#      define __ASSUME_SOCKET_SYSCALL   1
#      define __ASSUME_SOCKETPAIR_SYSCALL   1
#      define __ASSUME_BIND_SYSCALL   1
#      define __ASSUME_CONNECT_SYSCALL   1
#      define __ASSUME_LISTEN_SYSCALL   1
#      define __ASSUME_ACCEPT4_SYSCALL   1
#      define __ASSUME_ACCEPT4_FOR_ACCEPT_SYSCALL   1
#      define __ASSUME_GETSOCKOPT_SYSCALL   1
#      define __ASSUME_SETSOCKOPT_SYSCALL   1
#      define __ASSUME_GETSOCKNAME_SYSCALL   1
#      define __ASSUME_GETPEERNAME_SYSCALL   1
#      define __ASSUME_SENDTO_SYSCALL   1
#      define __ASSUME_SENDTO_FOR_SEND_SYSCALL   1
#      define __ASSUME_SENDMSG_SYSCALL   1
#      define __ASSUME_RECVFROM_SYSCALL   1
#      define __ASSUME_RECVFROM_FOR_RECV_SYSCALL   1
#      define __ASSUME_RECVMSG_SYSCALL   1
#      define __ASSUME_SHUTDOWN_SYSCALL   1
#   endif
#elif defined(ARCHAARCH64)
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   define __ASSUME_RECVMMSG_SYSCALL   1
#   define __ASSUME_SENDMMSG_SYSCALL   1
#elif defined(ARCHAARCH32)
#   if (__LINUX_KERNEL_VERSION >= 0x20621)
#      define __ASSUME_RECVMMSG_SYSCALL   1
#   endif
#   if (__LINUX_KERNEL_VERSION >= 0x20624)
#      define __ASSUME_ACCEPT4_SYSCALL   1
#   endif
#   if (__LINUX_KERNEL_VERSION >= 0x30000)
#      define __ASSUME_SENDMMSG_SYSCALL   1
#   endif
// The ARM kernel before 3.14.3 may or may not support futex_atomic_cmpxchg_inatomic, depending on kernel configuration
#   if (__LINUX_KERNEL_VERSION < 0x30e03)
#      undef __ASSUME_FUTEX_LOCK_PI
#      undef __ASSUME_REQUEUE_PI
#      undef __ASSUME_SET_ROBUST_LIST
#   endif
#elif defined(ARCHALPHA)
#   if (__LINUX_KERNEL_VERSION >= 0x30200)
#      define __ASSUME_ACCEPT4_SYSCALL   1
#      define __ASSUME_SENDMMSG_SYSCALL   1
#   endif
#   undef __ASSUME_ST_INO_64_BIT
#   undef __ASSUME_STATFS64
#   define __ASSUME_STATFS64   0
#   if (__LINUX_KERNEL_VERSION >= 0x20621)
#      define __ASSUME_RECVMMSG_SYSCALL   1
#   elif (__LINUX_KERNEL_VERSION < 0x20621)
#      undef __ASSUME_FALLOCATE
#      undef __ASSUME_PREADV
#      undef __ASSUME_PWRITEV
#      undef __ASSUME_IN_NONBLOCK
#      undef __ASSUME_PIPE2
#      undef __ASSUME_EVENTFD2
#      undef __ASSUME_SIGNALFD4
#      undef __ASSUME_DUP3
#   endif
#elif defined(ARCHPARISC)
#   if (__LINUX_KERNEL_VERSION >= 0x20622)
#      define __ASSUME_ACCEPT4_SYSCALL   1
#      define __ASSUME_RECVMMSG_SYSCALL   1
#   endif
#   if (__LINUX_KERNEL_VERSION >= 0x30100)
#      define __ASSUME_SENDMMSG_SYSCALL   1
#   endif
#   if (__LINUX_KERNEL_VERSION >= 0x30e00)
#      define __ASSUME_UTIMES   1
#   endif
#   if (__LINUX_KERNEL_VERSION < 0x20625)
#      undef __ASSUME_PRLIMIT64
#   endif
#elif defined(ARCHITANIUM)
#   if (__LINUX_KERNEL_VERSION >= 0x20621)
#      define __ASSUME_RECVMMSG_SYSCALL   1
#   endif
#   if (__LINUX_KERNEL_VERSION >= 0x30000)
#      define __ASSUME_SENDMMSG_SYSCALL   1
#   endif
#   if (__LINUX_KERNEL_VERSION >= 0x30300)
#      define __ASSUME_ACCEPT4_SYSCALL   1
#   endif
#elif defined(ARCHM68K)
#   define __ASSUME_SOCKETCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x40300)
#      define __ASSUME_RECVMMSG_SYSCALL   1
#      define __ASSUME_SENDMMSG_SYSCALL   1
#      define __ASSUME_SOCKET_SYSCALL   1
#      define __ASSUME_SOCKETPAIR_SYSCALL   1
#      define __ASSUME_BIND_SYSCALL   1
#      define __ASSUME_CONNECT_SYSCALL   1
#      define __ASSUME_LISTEN_SYSCALL   1
#      define __ASSUME_ACCEPT4_SYSCALL   1
#      define __ASSUME_ACCEPT4_FOR_ACCEPT_SYSCALL   1
#      define __ASSUME_GETSOCKOPT_SYSCALL   1
#      define __ASSUME_SETSOCKOPT_SYSCALL   1
#      define __ASSUME_GETSOCKNAME_SYSCALL   1
#      define __ASSUME_GETPEERNAME_SYSCALL   1
#      define __ASSUME_SENDTO_SYSCALL   1
#      define __ASSUME_SENDTO_FOR_SEND_SYSCALL   1
#      define __ASSUME_SENDMSG_SYSCALL   1
#      define __ASSUME_RECVFROM_SYSCALL   1
#      define __ASSUME_RECVFROM_FOR_RECV_SYSCALL  1
#      define __ASSUME_RECVMSG_SYSCALL   1
#      define __ASSUME_SHUTDOWN_SYSCALL   1
#   endif
#   if (__LINUX_KERNEL_VERSION < 0x30000)
#      undef __ASSUME_PSELECT
#      undef __ASSUME_PPOLL
#   endif
#   if (__LINUX_KERNEL_VERSION < 0x30a00)
#      undef __ASSUME_FUTEX_LOCK_PI
#      undef __ASSUME_REQUEUE_PI
#      undef __ASSUME_SET_ROBUST_LIST
#   endif
#elif defined(ARCHMICROBLAZE)
#   define __ASSUME_SOCKETCALL   1
#   define __ASSUME_SOCKET_SYSCALL   1
#   define __ASSUME_BIND_SYSCALL   1
#   define __ASSUME_CONNECT_SYSCALL   1
#   define __ASSUME_LISTEN_SYSCALL   1
#   define __ASSUME_ACCEPT_SYSCALL   1
#   define __ASSUME_GETSOCKNAME_SYSCALL   1
#   define __ASSUME_GETPEERNAME_SYSCALL   1
#   define __ASSUME_SOCKETPAIR_SYSCALL   1
#   define __ASSUME_SEND_SYSCALL   1
#   define __ASSUME_SENDTO_SYSCALL   1
#   define __ASSUME_RECV_SYSCALL   1
#   define __ASSUME_RECVFROM_SYSCALL   1
#   define __ASSUME_SHUTDOWN_SYSCALL   1
#   define __ASSUME_GETSOCKOPT_SYSCALL   1
#   define __ASSUME_SETSOCKOPT_SYSCALL   1
#   define __ASSUME_SENDMSG_SYSCALL   1
#   define __ASSUME_RECVMSG_SYSCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x20621)
#      define __ASSUME_ACCEPT4_SYSCALL   1
#      define __ASSUME_RECVMMSG_SYSCALL   1
#      define __ASSUME_FUTIMESAT   1
#   elif (__LINUX_KERNEL_VERSION < 0x20621)
#      undef __ASSUME_FUTEX_LOCK_PI
#      undef __ASSUME_REQUEUE_PI
#      undef __ASSUME_SET_ROBUST_LIST
#   endif
#   define __ASSUME_RECVMMSG_SYSCALL_WITH_SOCKETCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x30300)
#      define __ASSUME_SENDMMSG_SYSCALL   1
#   endif
#   if (__LINUX_KERNEL_VERSION < 0x20625)
#      undef __ASSUME_PRLIMIT64
#   endif
#   if (__LINUX_KERNEL_VERSION < 0x30f00)
#      undef __ASSUME_PSELECT
#      undef __ASSUME_PREADV
#      undef __ASSUME_PWRITEV
#   endif
#elif defined(ARCHMIPS)
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x20621)
#      define __ASSUME_RECVMMSG_SYSCALL   1
#   endif
#   if (__LINUX_KERNEL_VERSION >= 0x30100)
#      define __ASSUME_SENDMMSG_SYSCALL   1
#   endif
#   if ((_MIPS_SIM == _ABIN32) && (__LINUX_KERNEL_VERSION < 0x20623))
#      undef __ASSUME_GETDENTS64_SYSCALL
#   endif
// The MIPS kernel does not support futex_atomic_cmpxchg_inatomic if emulating LL/SC
#   if ((__mips == 1) || defined(_MIPS_ARCH_R5900))
#      undef __ASSUME_FUTEX_LOCK_PI
#      undef __ASSUME_REQUEUE_PI
#      undef __ASSUME_SET_ROBUST_LIST
#   endif
#elif defined(ARCHNIOS2)
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   define __ASSUME_RECVMMSG_SYSCALL   1
#   define __ASSUME_SENDMMSG_SYSCALL   1
#elif defined(ARCHPOWERPC)
#   define __ASSUME_SOCKETCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x20625)
#      define __ASSUME_ACCEPT4_SYSCALL   1
#      define __ASSUME_RECVMMSG_SYSCALL   1
#      define __ASSUME_SOCKET_SYSCALL   1
#      define __ASSUME_BIND_SYSCALL   1
#      define __ASSUME_CONNECT_SYSCALL   1
#      define __ASSUME_LISTEN_SYSCALL   1
#      define __ASSUME_ACCEPT_SYSCALL   1
#      define __ASSUME_GETSOCKNAME_SYSCALL   1
#      define __ASSUME_GETPEERNAME_SYSCALL   1
#      define __ASSUME_SOCKETPAIR_SYSCALL   1
#      define __ASSUME_SEND_SYSCALL   1
#      define __ASSUME_SENDTO_SYSCALL   1
#      define __ASSUME_RECV_SYSCALL   1
#      define __ASSUME_RECVFROM_SYSCALL   1
#      define __ASSUME_SHUTDOWN_SYSCALL   1
#      define __ASSUME_GETSOCKOPT_SYSCALL   1
#      define __ASSUME_SETSOCKOPT_SYSCALL   1
#      define __ASSUME_SENDMSG_SYSCALL   1
#      define __ASSUME_RECVMSG_SYSCALL   1
#   endif
#   if (__LINUX_KERNEL_VERSION >= 0x30000)
#      define __ASSUME_SENDMMSG_SYSCALL   1
#   endif
#   define __ASSUME_SENDMMSG_SYSCALL_WITH_SOCKETCALL   1
#elif defined(ARCHS390)
#   define __ASSUME_SOCKETCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x40300)
#      define __ASSUME_RECVMMSG_SYSCALL   1
#      define __ASSUME_SENDMMSG_SYSCALL   1
#      define __ASSUME_SOCKET_SYSCALL   1
#      define __ASSUME_SOCKETPAIR_SYSCALL   1
#      define __ASSUME_BIND_SYSCALL   1
#      define __ASSUME_CONNECT_SYSCALL   1
#      define __ASSUME_LISTEN_SYSCALL   1
#      define __ASSUME_ACCEPT4_SYSCALL   1
#      define __ASSUME_ACCEPT4_FOR_ACCEPT_SYSCALL   1
#      define __ASSUME_GETSOCKOPT_SYSCALL   1
#      define __ASSUME_SETSOCKOPT_SYSCALL   1
#      define __ASSUME_GETSOCKNAME_SYSCALL   1
#      define __ASSUME_GETPEERNAME_SYSCALL   1
#      define __ASSUME_SENDTO_SYSCALL   1
#      define __ASSUME_SENDTO_FOR_SEND_SYSCALL   1
#      define __ASSUME_SENDMSG_SYSCALL   1
#      define __ASSUME_RECVFROM_SYSCALL   1
#      define __ASSUME_RECVFROM_FOR_RECV_SYSCALL   1
#      define __ASSUME_RECVMSG_SYSCALL   1
#      define __ASSUME_SHUTDOWN_SYSCALL   1
#   endif
#elif defined(ARCHSPARC)
#   define __ASSUME_SOCKETCALL   1
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   define __ASSUME_ACCEPT4_SYSCALL_WITH_SOCKETCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x20621)
#      define __ASSUME_RECVMMSG_SYSCALL   1
#   endif
#   define __ASSUME_RECVMMSG_SYSCALL_WITH_SOCKETCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x30000)
#      define __ASSUME_SENDMMSG_SYSCALL   1
#   endif
#   define __ASSUME_SENDMMSG_SYSCALL_WITH_SOCKETCALL   1
// 32-bit SPARC kernels do not support futex_atomic_cmpxchg_inatomic
#   ifndef ARCHSPARC64
#      undef __ASSUME_FUTEX_LOCK_PI
#      undef __ASSUME_REQUEUE_PI
#      undef __ASSUME_SET_ROBUST_LIST
#   endif
#elif defined(ARCHSUPERH)
#   define __ASSUME_SOCKETCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x20625)
#      define __ASSUME_SOCKET_SYSCALL   1
#      define __ASSUME_BIND_SYSCALL   1
#      define __ASSUME_CONNECT_SYSCALL   1
#      define __ASSUME_LISTEN_SYSCALL   1
#      define __ASSUME_ACCEPT_SYSCALL   1
#      define __ASSUME_GETSOCKNAME_SYSCALL   1
#      define __ASSUME_GETPEERNAME_SYSCALL   1
#      define __ASSUME_SOCKETPAIR_SYSCALL 1
#      define __ASSUME_SEND_SYSCALL   1
#      define __ASSUME_SENDTO_SYSCALL  1
#      define __ASSUME_RECV_SYSCALL   1
#      define __ASSUME_RECVFROM_SYSCALL   1
#      define __ASSUME_SHUTDOWN_SYSCALL   1
#      define __ASSUME_GETSOCKOPT_SYSCALL   1
#      define __ASSUME_SETSOCKOPT_SYSCALL   1
#      define __ASSUME_SENDMSG_SYSCALL   1
#      define __ASSUME_RECVMSG_SYSCALL   1
#      define __ASSUME_ACCEPT4_SYSCALL   1
#      define __ASSUME_RECVMMSG_SYSCALL   1
#   endif
#   if (__LINUX_KERNEL_VERSION >= 0x30000)
#      define __ASSUME_SENDMMSG_SYSCALL   1
#   endif
#   define __ASSUME_SENDMMSG_SYSCALL_WITH_SOCKETCALL   1
#   undef __ASSUME_ST_INO_64_BIT
#   if (__LINUX_KERNEL_VERSION < 0x20625)
#      undef __ASSUME_PRLIMIT64
#   endif
#elif defined(ARCHTILE)
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   define __ASSUME_RECVMMSG_SYSCALL   1
#   if (__LINUX_KERNEL_VERSION >= 0x30000)
#      define __ASSUME_SENDMMSG_SYSCALL   1
#   endif
#   define __ASSUME_ALIGNED_REGISTER_PAIRS   1
#endif  // AVAILABLE SYSCALLS


#ifdef __ASSUME_SOCKETCALL
#   define __ASSUME_ACCEPT4_SOCKETCALL   1
#endif
#if (defined(__ASSUME_ACCEPT4_SOCKETCALL) || defined(__ASSUME_ACCEPT4_SYSCALL))
#   define __ASSUME_ACCEPT4   1
#endif
#if ((__LINUX_KERNEL_VERSION >= 0x20621) && defined(__ASSUME_SOCKETCALL))
#   define __ASSUME_RECVMMSG_SOCKETCALL   1
#endif
#if (defined(__ASSUME_RECVMMSG_SOCKETCALL) || defined(__ASSUME_RECVMMSG_SYSCALL))
#   define __ASSUME_RECVMMSG   1
#endif
#if ((__LINUX_KERNEL_VERSION >= 0x30000) && defined(__ASSUME_SOCKETCALL))
#   define __ASSUME_SENDMMSG_SOCKETCALL   1
#endif
#if (defined(__ASSUME_SENDMMSG_SOCKETCALL) || defined(__ASSUME_SENDMMSG_SYSCALL))
#   define __ASSUME_SENDMMSG   1
#endif


#endif  // OSLINUX & KERNEL_FEATURES_H


// WINDOWS MACROS

#ifdef OSWINDOWS


#ifndef _WIN32_WINNT
#   define _WIN32_WINNT   0x0400
#endif
#ifndef MP_WBITS
#   define MP_WBITS   64U
#endif
#if (defined(__WINESRC__) && (!defined(__ROS_LONG64__)) && (!defined(ARCHX86_64)))
#   define __ROS_LONG64__   1
#endif
#ifndef WINVER
#   define WINVER   0x502
#endif
#define FC_BYTE   1
#define FC_CHAR   2
#define FC_SMALL   3
#define FC_USMALL   4
#define FC_WCHAR   5
#define FC_SHORT   6
#define FC_USHORT   7
#define FC_LONG   8
#define FC_ULONG   9
#define FC_FLOAT   0xa
#define FC_HYPER   0xb
#define FC_DOUBLE   0xc
#define FC_ENUM16   0xd
#define FC_ENUM32   0xe
#define FC_ERROR_STATUS_T   0x10
#define FC_INT3264   0xb8
#define FC_UINT3264   0xb9
// Default values for Microsoft Visual C++ resource script fields for embedding version information
#ifndef RC_VERSION_FIELD_1
#   define RC_VERSION_FIELD_1   0
#endif
#ifndef RC_VERSION_FIELD_2
#   define RC_VERSION_FIELD_2   0
#endif
#ifndef RC_VERSION_FIELD_3
#   define RC_VERSION_FIELD_3   0
#endif
#ifndef RC_VERSION_FIELD_4
#   define RC_VERSION_FIELD_4   0
#endif
#ifndef RC_COMPANY_NAME
#   define RC_COMPANY_NAME   ""
#endif
#ifndef RC_FILE_DESCRIPTION
#   define RC_FILE_DESCRIPTION   ""
#endif
#ifndef RC_FILE_VERSION
#   define RC_FILE_VERSION   ""
#endif
#ifndef RC_INTERNAL_NAME
#   define RC_INTERNAL_NAME   ""
#endif
#ifndef RC_ORIGINAL_FILENAME
#   define RC_ORIGINAL_FILENAME   ""
#endif
#ifndef RC_PRODUCT_NAME
#   define RC_PRODUCT_NAME   ""
#endif
#ifndef RC_PRODUCT_VERSION
#   define RC_PRODUCT_VERSION   ""
#endif


#endif  // OSWINDOWS


#endif  // ARCHITECTURE_MACROS_SEEN


/* MACHINE REGISTERS */


#if (!(defined(REGISTERS_H) || defined(_REGISTERS_H) || defined(_REGISTERS_H_)))
#define REGISTERS_H   (1)
#define _REGISTERS_H   (1)
#define _REGISTERS_H_   (1)
#define SYS_USER_H   (1)
#define _SYS_USER_H   (1)
#define _SYS_USER_H_   (1)


/** @def NGREG
Number of general registers */
/** @def NFPREG
Number of float-point registers */
/** @typedef greg_t
Container for all general registers */
/** @typedef gregset_t
Container for all general registers */
/** @typedef elf_greg_t
Container for all general registers */
/** @typedef elf_gregset_t
Container for all general registers */
#ifdef ARCHALPHA
#   define NGREG   33
#   define NFPREG   32
typedef long   greg_t, gregset_t[NGREG];
/** Type for floating-point register */
typedef long   fpreg_t, fpregset_t[NFPREG];
#elif defined(ARCHARM)
#   ifdef ARCHAARCH64
#      define NGREG   34
typedef struct user_fpsimd_struct {
	long double vregs[32];
	unsigned int fpsr, fpcr;
} elf_fpregset_t;
typedef struct user_regs_struct {
	unsigned long long regs[31];
	unsigned long long sp, pc, pstate;
} user_regs_struct_t;
#   elif defined(ARCHAARCH32)
#      define NGREG   18
typedef struct user_fpregs {
	struct fp_reg {
		unsigned int sign1:1;
		unsigned int unused:15;
		unsigned int sign2:1;
		unsigned int exponent:14;
		unsigned int j:1;
		unsigned int mantissa1:31;
		unsigned int mantissa0:32;
	} fpregs[8];
	unsigned int fpsr:32;
	unsigned int fpcr:32;
	unsigned char ftype[8];
	unsigned int init_flag;
} elf_fpregset_t;
typedef struct user_regs { unsigned long uregs[18]; }   user_regs_t;
typedef struct user {
	struct user_regs regs;
	int u_fpvalid;
	unsigned long u_tsize, u_dsize, u_ssize, start_code, start_stack;
	long signal;
	int reserved;
	struct user_regs* u_ar0;
	unsigned long magic;
	char u_comm[32];
	int u_debugreg[8];
	struct user_fpregs u_fp;
	struct user_fpregs* u_fp0;
} user_t;
#   endif
typedef long   greg_t, gregset_t[NREG];
typedef unsigned long   elf_greg_t, elf_gregset_t[NREG];
/** Structure to describe FPU registers */
typedef elf_fpregset_t   fpregset_t;
/** Number of each register is the `gregset_t` array */
enum REGISTERS {
	REG_R0 = 0,
	REG_R1,
	REG_R2,
	REG_R3,
	REG_R4,
	REG_R5,
	REG_R6,
	REG_R7,
	REG_R8,
	REG_R9,
	REG_R10,
	REG_R11,
	REG_R12,
	REG_R13,
	REG_R14,
	REG_R15
};
#elif defined(ARCHBLACKFIN)
#   define NGREG   47
typedef int   greg_t, gregset_t[NGREG];
/** Number of each register is the `gregset_t` array */
enum REGISTERS {
	REG_R0 = 0,
	REG_R1 = 1,
	REG_R2 = 2,
	REG_R3 = 3,
	REG_R4 = 4,
	REG_R5 = 5,
	REG_R6 = 6,
	REG_R7 = 7,
	REG_P0 = 8,
	REG_P1 = 9,
	REG_P2 = 10,
	REG_P3 = 11,
	REG_P4 = 12,
	REG_P5 = 13,
	REG_USP = 14,
	REG_A0W = 15,
	REG_A1W = 16,
	REG_A0X = 17,
	REG_A1X = 18,
	REG_ASTAT = 19,
	REG_RETS = 20,
	REG_PC = 21,
	REG_RETX = 22,
	REG_FP = 23,
	REG_I0 = 24,
	REG_I1 = 25,
	REG_I2 = 26,
	REG_I3 = 27,
	REG_M0 = 28,
	REG_M1 = 29,
	REG_M2 = 30,
	REG_M3 = 31,
	REG_L0 = 32,
	REG_L1 = 33,
	REG_L2 = 34,
	REG_L3 = 35,
	REG_B_0 = 36,
	REG_B1 = 37,
	REG_B2 = 38,
	REG_B3 = 39,
	REG_LC0 = 40,
	REG_LC1 = 41,
	REG_LT0 = 42,
	REG_LT1 = 43,
	REG_LB0 = 44,
	REG_LB1 = 45,
	REG_SEQSTAT = 46
};
#elif defined(ARCHITANIUM)
typedef struct ia64_fpreg {
	union __union_ia64_fpreg { unsigned long bits[2]; } u;
} align16   ia64_fpreg_t;
struct pt_all_user_regs {
	unsigned long nat, cr_iip, cfm, cr_ipsr, pr;
	unsigned long gr[32];
	unsigned long br[8];
	unsigned long ar[128];
	struct ia64_fpreg fr[128];
};
#elif defined(ARCHMIPS)
#   define NGREG   32
#   define NFPREG   32
typedef unsigned long long   greg_t, gregset_t[NGREG], elf_greg_t, elf_gregset_t[NGREG];
/** Container for all FPU registers */
typedef struct fpregset {
	union __union_fpregset {
		double fp_dregs[NFPREG];
		struct {
			float _fp_fregs;
			unsigned int _fp_pad;
		} fp_fregs[NFPREG];
	} fp_r;
} fpregset_t;
typedef double   elf_fpreg_t, elf_fpregset_t[NFPREG];
typedef struct user {
	unsigned long regs[109];
	unsigned long u_tsize, u_dsize, u_ssize, start_code, start_data, start_stack;
	long signal;
	void* u_ar0;
	unsigned long magic;
	char u_comm[32];
} user_t;
enum REGISTERS {
	EF_R0 = 6,
	EF_R1 = 7,
	EF_R2 = 8,
	EF_R3 = 9,
	EF_R4 = 10,
	EF_R5 = 11,
	EF_R6 = 12,
	EF_R7 = 13,
	EF_R8 = 14,
	EF_R9 = 15,
	EF_R10 = 16,
	EF_R11 = 17,
	EF_R12 = 18,
	EF_R13 = 19,
	EF_R14 = 20,
	EF_R15 = 21,
	EF_R16 = 22,
	EF_R17 = 23,
	EF_R18 = 24,
	EF_R19 = 25,
	EF_R20 = 26,
	EF_R21 = 27,
	EF_R22 = 28,
	EF_R23 = 29,
	EF_R24 = 30,
	EF_R25 = 31,
	EF_R26 = 32,
	EF_R27 = 33,
	EF_R28 = 34,
	EF_R29 = 35,
	EF_R30 = 36,
	EF_R31 = 37,
	EF_LO = 38,
	EF_HI = 39,
	EF_CP0_EPC = 40,
	EF_CP0_BADVADDR = 41,
	EF_CP0_STATUS = 42,
	EF_CP0_CAUSE = 43,
	EF_UNUSED0 = 44,
	EF_SIZE = 180,
};
#elif defined(ARCHPOWERPC64)
#   define NGREG   48
#   define NFPREG   33
/** Number of vector registers (Includes v0-v31, vscr, & vrsave in split vectors) */
#   define NVRREG   34
#   define ELF_NVRREG   34
typedef unsigned long   greg_t, gregset_t[NGREG], elf_greg_t, elf_gregset_t[NGREG];
typedef double   fpregset_t[NFPREG], elf_fpreg_t, elf_fpregset_t[NFPREG];
/** Container for Altivec/VMX Vector Status and Control Register; Only 32-bits but can only be copied to/from a 128-bit vector register; So we allocated a whole quadword speedup save/restore */
typedef struct _libc_vscr { unsigned int __pad[3], vscr_word; }   vscr_t;
/** Container for Altivec/VMX registers and status; Must to be aligned on a 16-byte boundary */
typedef struct _libc_vrstate {
	unsigned int vrregs[32][4];
	vscr_t vscr;
	unsigned int vrsave;
	unsigned int __pad[3];
} align16   vrregset_t;
typedef struct pt_regs {
	unsigned long gpr[32], nip, msr, orig_gpr3, ctr, link, xer, ccr, mq;
	unsigned long trap, dar, dsisr, result;
} pt_regs_t;
typedef struct user {
	struct pt_regs regs;
	unsigned long u_tsize, u_dsize, u_ssize, start_code, start_data, start_stack;
	long signal;
	void* u_ar0;
	unsigned long magic;
	char u_comm[32];
} user_t;
typedef struct __elf_vrreg { unsigned int u[4]; } align16   elf_vrreg_t, elf_vrregset_t[NVRREG];
#elif defined(ARCHPOWERPC32)
#   define NGREG   48
#   define NFPREG   33
/** Number of vector registers */
#   define NVRREG   34
#   define ELF_NVRREG   34
typedef unsigned long   gregset_t[NGREG];
/** Container for floating-point registers and status */
typedef struct _libc_fpstate {
	double fpregs[32];
	double fpscr;
	unsigned int _pad[2];
} fpregset_t;
/** Container for Altivec/VMX registers and status; Needs to be aligned on a 16-byte boundary */
typedef struct _libc_vrstate {
	unsigned int vrregs[32][4];
	unsigned int vrsave;
	unsigned int _pad[2];
	unsigned int vscr;
} vrregset_t;
typedef struct pt_regs {
	unsigned long gpr[32], nip, msr, orig_gpr3, ctr, link, xer, ccr, mq;
	unsigned long trap, dar, dsisr, result;
} pt_regs_t;
typedef struct user {
	struct pt_regs regs;
	unsigned long u_tsize, u_dsize, u_ssize, start_code, start_data, start_stack;
	long signal;
	void* u_ar0;
	unsigned long magic;
	char u_comm[32];
} user_t;
typedef struct __elf_vrreg { unsigned int u[4]; } align16   elf_vrreg_t, elf_vrregset_t[NVRREG];
#elif defined(ARCHSPARC)
#   define FPU_REGS_TYPE   unsigned int
#   define FPU_DREGS_TYPE   unsigned long long
#   define V7_FPU_FSR_TYPE   unsigned int
#   define V9_FPU_FSR_TYPE   unsigned long long
#   define V9_FPU_FPRS_TYPE   unsigned int
/** max # of fpu queue entries currently supported */
#   define MAXFPQ   16
enum REGISTERS {
	REG_PSR = 0,
#   define MC_TSTATE   0
	REG_PC = 1,
#   define MC_PC   1
	REG_nPC = 2,
#   define MC_NPC   2
	REG_Y = 3,
#   define MC_Y   3
	REG_G1 = 4,
#   define MC_G1   4
	REG_G2 = 5,
#   define MC_G2   5
	REG_G3 = 6,
#   define MC_G3   6
	REG_G4 = 7,
#   define MC_G4   7
	REG_G5 = 8,
#   define MC_G5   8
	REG_G6 = 9,
#   define MC_G6   9
	REG_G7 = 10,
#   define MC_G7   10
	REG_O0 = 11,
#   define MC_O0   11
	REG_O1 = 12,
#   define MC_O1   12
	REG_O2 = 13,
#   define MC_O2   13
	REG_O3 = 14,
#   define MC_O3   14
	REG_O4 = 15,
#   define MC_O4   15
	REG_O5 = 16,
#   define MC_O5   16
	REG_O6 = 17,
#   define MC_O6   17
	REG_O7 = 18,
#   define MC_O7   18
#   if IS_WORDSIZE_64
	REG_ASI = 19,
#   define MC_ASI   19
	REG_FPRS = 20
#   define MC_FPRS   20
#      define NGREG   21
#   else  // IS_WORDSIZE_32
#      define NGREG   19
#   endif
#   define MC_NGREG   19
};
/** Defines the minimal format of a floating point instruction queue entry */
struct _fpq {
	unsigned long* fpq_addr;
	unsigned long fpq_instr;
};
/** FPU inst/addr queue */
struct _fq {
	union __union_fq {
		double whole;
		struct _fpq fpq;
	} FQu;
};
#   if IS_WORDSIZE_64
typedef long   greg_t, gregset_t[NGREG], mc_greg_t, mc_gregset_t[NGREG];
/** FPU floating point regs */
typedef struct fpu {
	union __union_fpu {
		unsigned int fpu_regs[32];
		double fpu_dregs[16];
		long double fpu_qregs[16];
	} fpu_fr;
	struct _fq* fpu_q;
	unsigned long fpu_fsr;
	unsigned char fpu_qcnt, fpu_q_entrysize, fpu_en;
} fpregset_t;
#   else  // IS_WORDSIZE_32
typedef int   greg_t, gregset_t[NGREG], mc_greg_t, mc_gregset_t[NGREG];
/** FPU floating point regs */
typedef struct fpu {
	union __union_fpu {
		unsigned long long fpu_regs[32];
		double fpu_dregs[16];
	} fpu_fr;
	struct _fq* fpu_q;
	unsigned int fpu_fsr;
	unsigned char fpu_qcnt, fpu_q_entrysize, fpu_en;
} fpregset_t;
#   endif
#elif defined(ARCHSUPERH)
#   define NGREG   23
typedef long   greg_t;
typedef unsigned long   elf_greg_t;
typedef greg_t   gregset_t[NGREG];
typedef elf_greg_t   elf_gregset_t[NGREG];
typedef struct pt_regs {
	unsigned long regs[16];
	unsigned long pc, pr, sr, gbr, mach, macl;
	long tra;
} pt_regs_t;
typedef struct pt_dspregs {
	unsigned long a1, a0g, a1g, m0, m1, a0, x0, x1, y0, y1, dsr, rs, re, mod;
} pt_dspregs_t;
typedef struct user_fpu_struct {
	unsigned long fp_regs[16], xfp_regs[16];
	unsigned long fpscr, fpul;
} elf_fpregset_t;
typedef struct user {
	struct pt_regs regs;
	struct user_fpu_struct fpu;
	int u_fpvalid;
	unsigned long u_tsize, u_dsize, u_ssize, start_code, start_data, start_stack;
	long signal;
	unsigned long u_ar0;
	struct user_fpu_struct* u_fpstate;
	unsigned long magic;
	char u_comm[32];
} user_t;
enum REGISTERS {
	REG_REG0 = 0,
	REG_REG15 = 15,
	REG_PC = 16,
	REG_PR = 17,
	REG_SR = 18,
	REG_GBR = 19,
	REG_MACH = 20,
	REG_MACL = 21,
	REG_SYSCALL = 22,
	REG_FPREG0 = 23,
	REG_FPREG15 = 38,
	REG_XFREG0 = 39,
	REG_XFREG15 = 54,
	REG_FPSCR = 55,
	REG_FPUL = 56
};
#elif defined(ARCHX86)
typedef struct _fpreg {
	unsigned short significand[4];
	unsigned short exponent;
} _fpreg_t;
#   define _libc_fpreg   _fpreg
typedef struct _fpxreg {
	unsigned short significand[4];
	unsigned short exponent;
	unsigned short padding[3];
} _fpxreg_t;
#   define _libc_fpxreg   _fpxreg
typedef struct _xmmreg { uint32_t element[4]; }   _xmmreg_t;
#   define _libc_xmmreg   _xmmreg
#   define NFPREG   8
#   if IS_WORDSIZE_64
#      define NGREG   27
typedef long   greg_t;
typedef unsigned long long   elf_greg_t, elf_gregset_t[NGREG];
struct _libc_fpstate {
	uint16_t cwd, swd, ftw, fop;
	uint64_t rip, rdp;
	uint32_t mxcsr, mxcr_mask;
	struct _libc_fpxreg _st[8];
	struct _libc_xmmreg _xmm[16];
	uint32_t padding[24];
};
/** Structure to describe FPU registers */
typedef struct _libc_fpstate*   fpregset_t;
typedef struct user_fpregs_struct {
	uint16_t cwd, swd, ftw, fop;
	uint64_t rip, rdp;
	uint32_t mxcsr, mxcr_mask;
	uint32_t st_space[32], xmm_space[64], padding[24];
} elf_fpregset_t;
typedef struct user_regs_struct {
	unsigned long r15, r14, r13, r12, rbp, rbx, r11, r10, r9, r8;
	unsigned long rax, rcx, rdx, rsi, rdi, orig_rax, rip;
	unsigned long cs, eflags, rsp, ss, fs_base, gs_base, ds, es, fs, gs, pad0;
} user_regs_t;
/** FPU environment matching the 64-bit FXSAVE layout */
struct _fpstate {
	// Regular FPU environment
	uint16_t cwd, swd, ftw, fop;
	uint64_t rip, rdp;
	uint32_t mxcsr, mxcr_mask;
	// FXSR FPU environment
	struct _fpxreg _st[8];
	struct _xmmreg _xmm[16];
	uint32_t padding[24];
};
typedef struct user {
	struct user_regs_struct regs;
	struct user_fpregs_struct i387;
	int u_fpvalid;
	int pad0;  //!< Padding
	unsigned long u_tsize, u_dsize, u_ssize, start_code, start_stack;
	long signal;
	int reserved;
	int pad1;  //!< Padding
	struct user_regs_struct* u_ar0;
	struct user_fpregs_struct* u_fpstate;
	unsigned long magic;
	char u_comm[32];
	unsigned long u_debugreg[8];
} user_t;
enum MACHINE_REGISTERS {
	MR_R15 = 0,
	MR_R14 = 1,
	MR_R13 = 2,
	MR_R12 = 3,
	MR_RBP = 4,
	MR_RBX = 5,
	MR_R11 = 6,
	MR_R10 = 7,
	MR_R9 = 8,
	MR_R8 = 9,
	MR_RAX = 10,
	MR_RCX = 11,
	MR_RDX = 12,
	MR_RSI = 13,
	MR_RDI = 14,
	MR_ORIG_RAX = 15,
	MR_RIP = 16,
	MR_CS = 17,
	MR_EFLAGS = 18,
	MR_RSP = 19,
	MR_SS = 20,
	MR_FS_BASE = 21,
	MR_GS_BASE = 22,
	MR_DS = 23,
	MR_ES = 24,
	MR_FS = 25,
	MR_GS = 26
};
/** Number of each register in the `gregset_t` array */
enum REGISTERS {
	REG_R8 = 0,
	REG_R9,
	REG_R10,
	REG_R11,
	REG_R12,
	REG_R13,
	REG_R14,
	REG_R15,
	REG_RDI,
	REG_RSI,
	REG_RBP,
	REG_RBX,
	REG_RDX,
	REG_RAX,
	REG_RCX,
	REG_RSP,
	REG_RIP,
	REG_EFL,
	REG_CSGSFS,
	REG_ERR,
	REG_TRAPNO,
	REG_OLDMASK,
	REG_CR2
};
#   else  // x86-32
#      define NGREG   19
typedef int   greg_t;
typedef unsigned long   elf_greg_t, elf_gregset_t[NGREG];
struct _libc_fpstate {
	unsigned long cw, sw, tag, ipoff, cssel, dataoff, datasel;
	struct _libc_fpreg _st[8];
	unsigned long status;
};
/** Structure to describe FPU registers */
typedef struct _libc_fpstate*   fpregset_t;
typedef struct user_fpregs_struct {
	long cwd, swd, twd, fip, fcs, foo, fos, st_space[20];
} elf_fpregset_t;
typedef struct user_fpxregs_struct {
	unsigned short cwd, swd, twd, fop;
	long fip, fcs, foo, fos, mxcsr, reserved;
	long st_space[32], xmm_space[32], padding[56];
} elf_fpxregset_t;
struct user_regs_struct {
	long ebx, ecx, edx, esi, edi, ebp, eax, xds, xes, xfs, xgs;
	long orig_eax, eip, xcs, eflags, esp, xss;
};
/** FPU environment */
struct _fpstate {
	// Regular FPU environment
	uint32_t cw, sw, tag, ipoff, cssel, dataoff, datasel;
	struct _fpreg _st[8];
	unsigned short status, magic;
	// FXSR FPU environment
	uint32_t _fxsr_env[6];
	uint32_t mxcsr, reserved;
	struct _fpxreg _fxsr_st[8];
	struct _xmmreg _xmm[8];
	uint32_t padding[56];
};
typedef struct user {
	struct user_regs_struct regs;
	int u_fpvalid;
	struct user_fpregs_struct i387;
	unsigned long u_tsize, u_dsize, u_ssize, start_code, start_stack;
	long signal;
	int reserved;
	struct user_regs_struct* u_ar0;
	struct user_fpregs_struct* u_fpstate;
	unsigned long magic;
	char u_comm[32];
	int u_debugreg[8];
} user_t;
enum MACHINE_REGISTERS {
	MR_EBX = 0,
	MR_ECX = 1,
	MR_EDX = 2,
	MR_ESI = 3,
	MR_EDI = 4,
	MR_EBP = 5,
	MR_EAX = 6,
	MR_DS = 7,
	MR_ES = 8,
	MR_FS = 9,
	MR_GS = 10,
	MR_ORIG_EAX = 11,
	MR_EIP = 12,
	MR_CS = 13,
	MR_EFL = 14,
	MR_UESP = 15,
	MR_SS = 16
};
/** Number of each register is the `gregset_t` array */
enum REGISTERS {
	REG_GS = 0,
	REG_FS,
	REG_ES,
	REG_DS,
	REG_EDI,
	REG_ESI,
	REG_EBP,
	REG_ESP,
	REG_EBX,
	REG_EDX,
	REG_ECX,
	REG_EAX,
	REG_TRAPNO,
	REG_ERR,
	REG_EIP,
	REG_CS,
	REG_EFL,
	REG_UESP,
	REG_SS
};
#   endif
typedef greg_t   gregset_t[NGREG];
#   define _rax   REG(rax)
#   define _rbx   REG(rbx)
#   define _rcx   REG(rcx)
#   define _rdx   REG(rdx)
#   define _rsi   REG(rsi)
#   define _rdi   REG(rdi)
#   define _rbp   REG(rbp)
#   define _rsp   REG(rsp)
#   define _r8    REG(r8)
#   define _r9    REG(r9)
#   define _r10   REG(r10)
#   define _r11   REG(r11)
#   define _r12   REG(r12)
#   define _r13   REG(r13)
#   define _r14   REG(r14)
#   define _r15   REG(r15)
#   define _eax   REG(eax)
#   define _ebx   REG(ebx)
#   define _ecx   REG(ecx)
#   define _edx   REG(edx)
#   define _esi   REG(esi)
#   define _edi   REG(edi)
#   define _ebp   REG(ebp)
#   define _esp   REG(esp)
#   define _st0   REG(st)
#   define _st1   REG(st(1))
#   define _st2   REG(st(2))
#   define _st3   REG(st(3))
#   define _st4   REG(st(4))
#   define _st5   REG(st(5))
#   define _st6   REG(st(6))
#   define _st7   REG(st(7))
#   define _ax   REG(ax)
#   define _bx   REG(bx)
#   define _cx   REG(cx)
#   define _dx   REG(dx)
#   define _ah   REG(ah)
#   define _bh   REG(bh)
#   define _ch   REG(ch)
#   define _dh   REG(dh)
#   define _al   REG(al)
#   define _bl   REG(bl)
#   define _cl   REG(cl)
#   define _dl   REG(dl)
#   define _sil   REG(sil)
#   define _mm1   REG(mm1)
#   define _mm2   REG(mm2)
#   define _mm3   REG(mm3)
#   define _mm4   REG(mm4)
#   define _mm5   REG(mm5)
#   define _mm6   REG(mm6)
#   define _mm7   REG(mm7)
#   define _xmm0   REG(xmm0)
#   define _xmm1   REG(xmm1)
#   define _xmm2   REG(xmm2)
#   define _xmm3   REG(xmm3)
#   define _xmm4   REG(xmm4)
#   define _xmm5   REG(xmm5)
#   define _xmm6   REG(xmm6)
#   define _xmm7   REG(xmm7)
#   define _cr0   REG(cr0)
#   define _cr1   REG(cr1)
#   define _cr2   REG(cr2)
#   define _cr3   REG(cr3)
#   define _cr4   REG(cr4)
#endif
#ifndef ELF_NGREG
#   define ELF_NGREG   NGREG
#endif
#if (defined(NFPREG) && (!defined(ELF_NFPREG)))
#   define ELF_NFPREG   NFPREG
#endif


#endif  // REGISTERS_H


/* TIME CONSTANTS MACROS */


#ifndef TIME_CONSTANTS_MACROS
#define TIME_CONSTANTS_MACROS   (1)


// SECONDS

/** Nanoseconds per microsecond */
#define NSEC_PER_USEC   1000ULL
/** Nanoseconds per millisecond */
#define NSEC_PER_MSEC   1000000ULL
/** Nanoseconds per second */
#define NSEC_PER_SEC   1000000000ULL
/** Microseconds per second */
#define USEC_PER_SEC   1000000ULL
/** Number of seconds in a anomalistic month */
#define SECONDS_IN_ANOMALISTIC_MONTH   2380713.12
/** Number of seconds in a draconic month */
#define SECONDS_IN_DRACONIC_MONTH   2351135.808
/** Number of seconds in a Gregorian month */
#define SECONDS_IN_GREGORIAN_MONTH   2629746
/** Number of seconds in a Julian month */
#define SECONDS_IN_JULIAN_MONTH   2629800
/** Number of seconds in a sidereal month */
#define SECONDS_IN_SIDEREAL_MONTH   2360591.6
/** Number of seconds in a synodic month */
#define SECONDS_IN_SYNODIC_MONTH   2551442.8
/** Number of seconds in a tropical month */
#define SECONDS_IN_TROPICAL_MONTH   2360584.512
/** Number of seconds in an anomalistic year */
#define SECONDS_IN_ANOMALISTIC_YEAR   31558432.5504
/** Number of seconds in a draconic year */
#define SECONDS_IN_DRACONIC_YEAR   29947974.5563
/** Number of seconds in a Gregorian year */
#define SECONDS_IN_GREGORIAN_YEAR   31556952
/** Number of seconds in a Julian year */
#define SECONDS_IN_JULIAN_YEAR   31557600
/** Number of seconds in a lunar year */
#define SECONDS_IN_LUNAR_YEAR   30617568
/** Number of seconds in a sidereal year */
#define SECONDS_IN_SIDEREAL_YEAR   31558149.504
/** Number of seconds in a tropical year */
#define SECONDS_IN_TROPICAL_YEAR   31556925.445
#ifndef AVGSECSPERYEAR
/** The Gregorian year averages 365.2425 days, which is 31556952 seconds */
#   define AVGSECSPERYEAR   31556952L
#endif


// DAYS

/** Number of days in a full month */
#define DAYS_IN_FULL_MONTH   30
/** Number of days in a hollow month */
#define DAYS_IN_HOLLOW_MONTH   29
/** Number of days in a anomalistic month */
#define DAYS_IN_ANOMALISTIC_MONTH   27.55455
/** Number of days in a draconic month */
#define DAYS_IN_DRACONIC_MONTH   27.21222
/** Number of days in a sidereal month */
#define DAYS_IN_SIDEREAL_MONTH   27.32166
/** Number of days in a synodic month */
#define DAYS_IN_SYNODIC_MONTH   29.53059
/** Number of days in a tropical month */
#define DAYS_IN_TROPICAL_MONTH   27.32158
/** Number of days in 4 years */
#define DAYS_PER_4Y   1461
/** Number of days in 100 years */
#define DAYS_PER_100Y   36524
/** Number of days in 400 years */
#define DAYS_PER_400Y   146097


// YEARS

#ifndef YEARSPERREPEAT
/** Years before a Gregorian repeat */
#   define YEARSPERREPEAT   400
#endif


// MISCELLANEOUS TIME CONSTANTS

#define LEAPOCH   (951868800LL)
#define CLOCKS_PER_SEC   (1000000L)
#define CLK_TCK   CLOCKS_PER_SEC

static const UNUSED int days_per_month[16] = { 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 0, 0, 0 };
static const UNUSED int secs_through_month[16] = { 0, 2678400, 5097600, 7776000, 10368000, 13046400, 15638400, 18316800, 20995200, 23587200, 26265600, 28857600, 0, 0, 0, 0 };


#endif  // TIME_CONSTANTS_MACROS


/* MATH CONSTANTS */


#if (!(defined(MATH_H_MATHDEF) || defined(_MATH_H_MATHDEF) || defined(_MATH_H_MATHDEF_) || defined(MATH_X_STATIC_CONSTANTS_SEEN)))
#define MATH_H_MATHDEF   (1)
#define _MATH_H_MATHDEF   (1)
#define _MATH_H_MATHDEF_   (1)
#define MATH_X_STATIC_CONSTANTS_SEEN   (1)


/** @defgroup Float_Point_Zeros Macros and constants for float-point zero values
@{ */  // (FB){

#ifdef OSHPUX
static const UNUSED float zerof = 0.0F;
static const UNUSED double zerod = 0.0;
#   if SUPPORTS_LONG_DOUBLE
static const UNUSED long double zerol = 0.0L;
#   endif
#   if SUPPORTS_FLOAT128
__extension__ static const UNUSED float128 zeroq = 0.0F128;
#   endif
#   if SUPPORTS_DECIMAL_FLOATS
__extension__ static const UNUSED decimal32 zerodf = 0.0DF;
__extension__ static const UNUSED decimal64 zerodd = 0.0DD;
#      if SUPPORTS_DECIMAL128
__extension__ static const UNUSED decimal128 zerodl = 0.0DL;
#      endif
#   endif
#else
#   define zerof   0.0F
#   define zerod   0.0
#   if SUPPORTS_LONG_DOUBLE
#      define zerol   0.0L
#   endif
#   if SUPPORTS_FLOAT128
#      define zeroq   0.0F128
#   endif
#   if SUPPORTS_DECIMAL_FLOATS
#      define zerodf   (__extension__ (0.0DF))
#      define zerodd   (__extension__ (0.0DD))
#      if SUPPORTS_DECIMAL128
#         define zerodl   (__extension__ (0.0DL))
#      endif
#   endif
#endif
static const UNUSED align16 float ZEROF[2] = { 0.0F, -0.0F };
static const UNUSED align16 double ZERO[2] = { 0.0, -0.0 };
#if SUPPORTS_LONG_DOUBLE
static const UNUSED align32 long double ZEROL[2] = { 0.0L, -0.0L };
#endif
#if (SUPPORTS_FLOAT128 && SUPPORTS_F128)
__extension__ static const UNUSED align32 float128 ZEROQ[2] = { 0.0F128, -0.0F128 };
#endif
#if SUPPORTS_DECIMAL_FLOATS
__extension__ static const UNUSED align16 decimal32 ZERODF[2] = { 0.0DF, -0.0DF };
__extension__ static const UNUSED align16 decimal64 ZERODD[2] = { 0.0DD, -0.0DD };
#   if SUPPORTS_DECIMAL128
__extension__ static const UNUSED align32 decimal128 ZERODL[2] = { 0.0DL, -0.0DL };
#   endif
#endif
#define NEG_ZERO   (-0.0)

/** @} */  // }

/** @defgroup Float_Point_Ones Macros and constants for float-point one values
@{ */  // (FB){

#define ONEF   (1.0F)
#define ONE   (1.0)
#if SUPPORTS_LONG_DOUBLE
#   define ONEL   (1.0L)
#endif
#if (SUPPORTS_FLOAT128 && SUPPORTS_F128)
#   define ONEQ   (__extension__ (1.0F128))
#endif
#if SUPPORTS_DECIMAL_FLOATS
#   define ONEDF   (1.0DF)
#   define ONEDD   (1.0DD)
#   if SUPPORTS_DECIMAL128
#      define ONEDL   (1.0DL)
#   endif
#endif

/** @} */  // }

/** @defgroup Float_Point_Tiny Macros and constants for float-point `TINY` values
@{ */  // (FB){

#define TINYF   (1.0E-30F)
#define TINY   (1.0E-300)
/** TINYF Squared */
#define TINYF_SQ   (TINYF * TINYF)
/** TINY Squared */
#define TINY_SQ   (TINY * TINY)
#define TINYF_STR   "1.0E-30"
#define TINY_STR   "1.0E-300"
#if SUPPORTS_LONG_DOUBLE
#   define TINYL   (1.0E-4930L)
#   define TINYL_SQ   (TINYL * TINYL)
#   define TINYL_STR   "1.0E-4930"
#endif
#if (SUPPORTS_FLOAT128 && SUPPORTS_F128)
#   define TINYQ   (__extension__ (1.0E-4930F128))
#   define TINYQ_SQ   (TINYQ * TINYQ)
#   define TINYQ_STR   "1.0E-4930"
#endif
#if SUPPORTS_DECIMAL_FLOATS
#   define TINYDF   (1.0E-30DF)
#   define TINYDF_SQ   (TINYDF * TINYDF)
#   define TINYDD   (TINYDD * TINYDD)
#   define TINYDD_SQ   (1.0E-300DD)
#   if SUPPORTS_DECIMAL128
#      define TINYDL   (1.0E-4930DL)
#      define TINYDL_SQ   (TINYDL * TINYDL)
#   endif
#endif

/** @} */  // }

/** @defgroup Float_Point_Huge Macros and constants for float-point `HUGE` values
@{ */  // (FB){

#define HUGEF   (1.0E+30F)
#define HUGE   (1.0E+300)
/** HUGEF Squared */
#define HUGEF_SQ   (HUGEF * HUGEF)
/** HUGE Squared */
#define HUGE_SQ   (HUGE * HUGE)
#define HUGEF_STR   "1.0E+30"
#define HUGE_STR   "1.0E+300"
/** SVID mode specifies returning this large value instead of infinity */
#define SVID_HUGE   (3.40282346638528859811704183484516925440000000E+38F)
#if SUPPORTS_LONG_DOUBLE
#   define HUGEL   (1.0E+4930L)
#   define HUGEL_SQ   (HUGEL * HUGEL)
#   define HUGEL_STR   "1.0E+4930"
#endif
#if (SUPPORTS_FLOAT128 && SUPPORTS_F128)
#   define HUGEQ   (__extension__ (1.0E+4930F128))
#   define HUGEQ_SQ   (HUGEQ * HUGEQ)
#   define HUGEQ_STR   "1.0E+4930"
#endif
#if SUPPORTS_DECIMAL_FLOATS
#   define HUGEDF   (HUGEDF * HUGEDF)
#   define HUGEDF_SQ   (1.0E+30DF)
#   define HUGEDD   (HUGEDD * HUGEDD)
#   define HUGEDD_SQ   (1.0E+300DD)
#   if SUPPORTS_DECIMAL128
#      define HUGEDL   (1.0E+4930DL)
#      define HUGEDL_SQ   (HUGEDL * HUGEDL)
#   endif
#endif

/** @} */  // }

/** @defgroup Miscellaneous_Float_Point_Constants Macros and variables for miscellaneous float-point constants
@{ */  // (FB){

#define INFSTR   "Infinity"
#define NANSTR   "NaN"
/** For the Bessel functions (j0, j1, jn, y0, y1, yn) this option defines the maximum absolute value of the ordinate before we assume total loss of significance (pi*2^52) */
#define X_TLOSS   (1.414847550405688055153188683004904275E+16)
/** For the Bessel functions (j0, j1, jn, y0, y1, yn) this option defines the maximum absolute value of the ordinate before we assume total loss of significance */
#define XTLOSS   X_TLOSS
#define ERFC_CONTFRAC_CUTOFF   30.0
#define ERFC_CONTFRAC_TERMS   50.0
#define ERF_SERIES_CUTOFF   1.5
#define ERF_SERIES_TERMS   25.0
#define EULERS_CONSTANT   0.57721566490153286060651209008240243104215933593992359880576723488486772677766467093694706329174674951463144724980708248096050401448654283622417399764492353625350033374293733773767394279259525824709491600873520394816567085323315
#define EULERS_CONSTANTF   eval_flt_join(EULERS_CONSTANT)
#if SUPPORTS_LONG_DOUBLE
#   define EULERS_CONSTANTL   eval_ldbl_join(EULERS_CONSTANT)
#endif
#define EXPONENTIAL_FACTORIAL_CONSTANT   1.61111492580837673611111111111111111
/** The value returned by `ilogb` for 0 */
#define FP_ILOGB0   -2147483647
/** The value returned by `ilogb` for NaN */
#define FP_ILOGBNAN   2147483647
#define GOLDEN_ANGLE   2.39996322972865332223155550663361385
#define GOLDEN_RATIO   1.6180339887498948482045868343656381177203091798057628621354486227052604628189024497072072041893911374
#define HYPERBOLIC_TANGENT_OF_1   0.7615941559557648881194582826047935904127685972579365515968105001219532445766384834589475216736767144219027597015540775323683091147624854132970066696113211253965101376080877764393409926042066795531174758011305900662577831975245123799759179611
#define I_SQUARED   -1
#define LANCZOS_G   6.024680040776729583740234375
#define LANCZOS_G_MINUS_HALF   5.524680040776729583740234375
#define LOCHS_CONSTANT   0.97027011439203392574025601921001083378128470478516128661035052993125419989173704803621267490802902646924158952293898402230011729806683281830059035368670755943547596420700271601215730100349595546709328590981290394185183860996575
#if LDBL_EQ_FLOAT128
#   define ipio2_items   690
#else
#   define ipio2_items   66
#endif

static const UNUSED align32 int32_t ipio2[ipio2_items] = {
	0xa2f983, 0x6e4e44, 0x1529fc, 0x2757d1, 0xf534dd, 0xc0db62,
	0x95993c, 0x439041, 0xfe5163, 0xabdebb, 0xc561b7, 0x246e3a,
	0x424dd2, 0xe00649, 0x2eea09, 0xd1921c, 0xfe1deb, 0x1cb129,
	0xa73ee8, 0x8235f5, 0x2ebb44, 0x84e99c, 0x7026b4, 0x5f7e41,
	0x3991d6, 0x398353, 0x39f49c, 0x845f8b, 0xbdf928, 0x3b1ff8,
	0x97ffde, 0x05980f, 0xef2f11, 0x8b5a0a, 0x6d1f6d, 0x367ecf,
	0x27cb09, 0xb74f46, 0x3f669e, 0x5fea2d, 0x7527ba, 0xc7ebe5,
	0xf17b3d, 0x0739f7, 0x8a5292, 0xea6bfb, 0x5fb11f, 0x8d5d08,
	0x560330, 0x46fc7b, 0x6babf0, 0xcfbc20, 0x9af436, 0x1da9e3,
	0x91615e, 0xe61b08, 0x659985, 0x5f14a0, 0x68408d, 0xffd880,
	0x4d7327, 0x310606, 0x1556ca, 0x73a8c9, 0x60e27b, 0xc08c6b,
#   if LDBL_EQ_FLOAT128
	0x47c419, 0xc367cd, 0xdce809, 0x2a8359, 0xc4768b, 0x961ca6,
	0xddaf44, 0xd15719, 0x053ea5, 0xff0705, 0x3f7e33, 0xe832c2,
	0xde4f98, 0x327dbb, 0xc33d26, 0xef6b1e, 0x5ef89f, 0x3a1f35,
	0xcaf27f, 0x1d87f1, 0x21907c, 0x7c246a, 0xfa6ed5, 0x772d30,
	0x433b15, 0xc614b5, 0x9d19c3, 0xc2c4ad, 0x414d2c, 0x5d000c,
	0x467d86, 0x2d71e3, 0x9ac69b, 0x006233, 0x7cd2b4, 0x97a7b4,
	0xd55537, 0xf63ed7, 0x1810a3, 0xfc764d, 0x2a9d64, 0xabd770,
	0xf87c63, 0x57b07a, 0xe71517, 0x5649c0, 0xd9d63b, 0x3884a7,
	0xcb2324, 0x778ad6, 0x23545a, 0xb91f00, 0x1b0af1, 0xdfce19,
	0xff319f, 0x6a1e66, 0x615799, 0x47fbac, 0xd87f7e, 0xb76522,
	0x89e832, 0x60bfe6, 0xcdc4ef, 0x09366c, 0xd43f5d, 0xd7de16,
	0xde3b58, 0x929bde, 0x2822d2, 0xe88628, 0x4d58e2, 0x32cac6,
	0x16e308, 0xcb7de0, 0x50c017, 0xa71df3, 0x5be018, 0x34132e,
	0x621283, 0x014883, 0x5b8ef5, 0x7fb0ad, 0xf2e91e, 0x434a48,
	0xd36710, 0xd8ddaa, 0x425fae, 0xce616a, 0xa4280a, 0xb499d3,
	0xf2a606, 0x7f775c, 0x83c2a3, 0x883c61, 0x78738a, 0x5a8caf,
	0xbdd76f, 0x63a62d, 0xcbbff4, 0xef818d, 0x67c126, 0x45ca55,
	0x36d9ca, 0xd2a828, 0x8d61c2, 0x77c912, 0x142604, 0x9b4612,
	0xc459c4, 0x44c5c8, 0x91b24d, 0xf31700, 0xad43d4, 0xe54929,
	0x10d5fd, 0xfcbe00, 0xcc941e, 0xeece70, 0xf53e13, 0x80f1ec,
	0xc3e7b3, 0x28f8c7, 0x940593, 0x3e71c1, 0xb3092e, 0xf3450b,
	0x9c1288, 0x7b20ab, 0x9fb52e, 0xc29247, 0x2f327b, 0x6d550c,
	0x90a772, 0x1fe76b, 0x96cb31, 0x4a1679, 0xe27941, 0x89dff4,
	0x9794e8, 0x84e6e2, 0x973199, 0x6bed88, 0x365f5f, 0x0efdbb,
	0xb49a48, 0x6ca467, 0x427271, 0x325d8d, 0xb8159f, 0x09e5bc,
	0x25318d, 0x3974f7, 0x1c0530, 0x010c0d, 0x68084b, 0x58ee2c,
	0x90aa47, 0x02e774, 0x24d6bd, 0xa67df7, 0x72486e, 0xef169f,
	0xa6948e, 0xf691b4, 0x5153d1, 0xf20acf, 0x339820, 0x7e4bf5,
	0x6863b2, 0x5f3edd, 0x035d40, 0x7f8985, 0x295255, 0xc06437,
	0x10d86d, 0x324832, 0x754c5b, 0xd4714e, 0x6e5445, 0xc1090b,
	0x69f52a, 0xd56614, 0x9d0727, 0x50045d, 0xdb3bb4, 0xc576ea,
	0x17f987, 0x7d6b49, 0xba271d, 0x296996, 0xacccc6, 0x5414ad,
	0x6ae290, 0x89d988, 0x50722c, 0xbea404, 0x940777, 0x7030f3,
	0x27fc00, 0xa871ea, 0x49c266, 0x3de064, 0x83dd97, 0x973fa3,
	0xfd9443, 0x8c860d, 0xde4131, 0x9d3992, 0x8c70dd, 0xe7b717,
	0x3bdf08, 0x2b3715, 0xa0805c, 0x93805a, 0x921110, 0xd8e80f,
	0xaf806c, 0x4bffdb, 0x0f9038, 0x761859, 0x15a562, 0xbbcb61,
	0xb989c7, 0xbd4010, 0x04f2d2, 0x277549, 0xf6b6eb, 0xbb22db,
	0xaa140a, 0x2f2689, 0x768364, 0x333b09, 0x1a940e, 0xaa3a51,
	0xc2a31d, 0xaeedaf, 0x12265c, 0x4dc26d, 0x9c7a2d, 0x9756c0,
	0x833f03, 0xf6f009, 0x8c402b, 0x99316d, 0x07b439, 0x15200c,
	0x5bc3d8, 0xc492f5, 0x4badc6, 0xa5ca4e, 0xcd37a7, 0x36a9e6,
	0x9492ab, 0x6842dd, 0xde6319, 0xef8c76, 0x528b68, 0x37dbfc,
	0xaba1ae, 0x3115df, 0xa1ae00, 0xdafb0c, 0x664d64, 0xb705ed,
	0x306529, 0xbf5657, 0x3aff47, 0xb9f96a, 0xf3be75, 0xdf9328,
	0x3080ab, 0xf68c66, 0x15cb04, 0x0622fa, 0x1de4d9, 0xa4b33d,
	0x8f1b57, 0x09cd36, 0xe9424e, 0xa4be13, 0xb52333, 0x1aaaf0,
	0xa8654f, 0xa5c1d2, 0x0f3f0b, 0xcd785b, 0x76f923, 0x048b7b,
	0x721789, 0x53a6c6, 0xe26e6f, 0x00ebef, 0x584a9b, 0xb7dac4,
	0xba66aa, 0xcfcf76, 0x1d02d1, 0x2df1b1, 0xc1998c, 0x77adc3,
	0xda4886, 0xa05df7, 0xf480c6, 0x2ff0ac, 0x9aecdd, 0xbc5c3f,
	0x6dded0, 0x1fc790, 0xb6db2a, 0x3a25a3, 0x9aaf00, 0x9353ad,
	0x0457b6, 0xb42d29, 0x7e804b, 0xa707da, 0x0eaa76, 0xa1597b,
	0x2a1216, 0x2db7dc, 0xfde5fa, 0xfedb89, 0xfdbe89, 0x6c76e4,
	0xfca906, 0x70803e, 0x156e85, 0xff87fd, 0x073e28, 0x336761,
	0x86182a, 0xeabd4d, 0xafe7b3, 0x6e6d8f, 0x396795, 0x5bbf31,
	0x48d784, 0x16df30, 0x432dc7, 0x356125, 0xce70c9, 0xb8cb30,
	0xfd6cbf, 0xa200a4, 0xe46c05, 0xa0dd5a, 0x476f21, 0xd21262,
	0x845cb9, 0x496170, 0xe0566b, 0x015299, 0x375550, 0xb7d51e,
	0xc4f133, 0x5f6e13, 0xe4305d, 0xa92e85, 0xc3b21d, 0x3632a1,
	0xa4b708, 0xd4b1ea, 0x21f716, 0xe4698f, 0x77ff27, 0x80030c,
	0x2d408d, 0xa0cd4f, 0x99a520, 0xd3a2b3, 0x0a5d2f, 0x42f9b4,
	0xcbda11, 0xd0be7d, 0xc1db9b, 0xbd17ab, 0x81a2ca, 0x5c6a08,
	0x17552e, 0x550027, 0xf0147f, 0x8607e1, 0x640b14, 0x8d4196,
	0xdebe87, 0x2afdda, 0xb6256b, 0x34897b, 0xfef305, 0x9ebfb9,
	0x4f6a68, 0xa82a4a, 0x5ac44f, 0xbcf82d, 0x985ad7, 0x95c7f4,
	0x8d4d0d, 0xa63a20, 0x5f57a4, 0xb13f14, 0x953880, 0x0120cc,
	0x86dd71, 0xb6dec9, 0xf560bf, 0x11654d, 0x6b0701, 0xacb08c,
	0xd0c0b2, 0x485551, 0x0efb1e, 0xc37295, 0x3b06a3, 0x3540c0,
	0x7bdc06, 0xcc45e0, 0xfa294e, 0xc8cad6, 0x41f3e8, 0xde647c,
	0xd8649b, 0x31bed9, 0xc397a4, 0xd45877, 0xc5e369, 0x13daf0,
	0x3c3aba, 0x461846, 0x5f7555, 0xf5bdd2, 0xc6926e, 0x5d2eac,
	0xed440e, 0x423e1c, 0x87c461, 0xe9fd29, 0xf3d6e7, 0xca7c22,
	0x35916f, 0xc5e008, 0x8dd7ff, 0xe26a6e, 0xc6fdb0, 0xc10893,
	0x745d7c, 0xb2ad6b, 0x9d6ecd, 0x7b723e, 0x6a11c6, 0xa9cff7,
	0xdf7329, 0xbac9b5, 0x5100b7, 0x0db2e2, 0x24ba74, 0x607de5,
	0x8ad874, 0x2c150d, 0x0c1881, 0x94667e, 0x162901, 0x767a9f,
	0xbefdfd, 0xef4556, 0x367ed9, 0x13d9ec, 0xb9ba8b, 0xfc97c4,
	0x27a831, 0xc36ef1, 0x36c594, 0x56a8d8, 0xb5a8b4, 0x0ecccf,
	0x2d8912, 0x34576f, 0x89562c, 0xe3ce99, 0xb920d6, 0xaa5e6b,
	0x9c2a3e, 0xcc5f11, 0x4a0bfd, 0xfbf4e1, 0x6d3b8e, 0x2c86e2,
	0x84d4e9, 0xa9b4fc, 0xd1eeef, 0xc9352e, 0x61392f, 0x442138,
	0xc8d91b, 0x0afc81, 0x6a4afb, 0xd81c2f, 0x84b453, 0x8c994e,
	0xcc2254, 0xdc552a, 0xd6c6c0, 0x96190b, 0xb8701a, 0x649569,
	0x605a26, 0xee523f, 0x0f117f, 0x11b5f4, 0xf5cbfc, 0x2dbc34,
	0xeebc34, 0xcc5de8, 0x605edd, 0x9b8e67, 0xef3392, 0xb817c9,
	0x9b5861, 0xbc57e1, 0xc68351, 0x103ed8, 0x4871dd, 0xdd1c2d,
	0xa118af, 0x462c21, 0xd7f359, 0x987ad9, 0xc0549e, 0xfa864f,
	0xfc0656, 0xae79e5, 0x362289, 0x22ad38, 0xdc9367, 0xaae855,
	0x382682, 0x9be7ca, 0xa40d51, 0xb13399, 0x0ed7a9, 0x480569,
	0xf0b265, 0xa7887f, 0x974c88, 0x36d1f9, 0xb39221, 0x4a827b,
	0x21cf98, 0xdc9f40, 0x5547dc, 0x3a74e1, 0x42eb67, 0xdf9dfe,
	0x5fd45e, 0xa4677b, 0x7aacba, 0xa2f655, 0x23882b, 0x55ba41,
	0x086e59, 0x862a21, 0x834739, 0xe6e389, 0xd49ee5, 0x40fb49,
	0xe956ff, 0xca0f1c, 0x8a59c5, 0x2bfa94, 0xc5c1d3, 0xcfc50f,
	0xae5adb, 0x86c547, 0x624385, 0x3b8621, 0x94792c, 0x876110,
	0x7b4c2a, 0x1a2c80, 0x12bf43, 0x902688, 0x893c78, 0xe4c4a8,
	0x7bdbe5, 0xc23ac4, 0xeaf426, 0x8a67f7, 0xbf920d, 0x2ba365,
	0xb1933d, 0x0b7cbd, 0xdc51a4, 0x63dd27, 0xdde169, 0x19949a,
	0x9529a8, 0x28ce68, 0xb4ed09, 0x209f44, 0xca984e, 0x638270,
	0x237c7e, 0x32b90f, 0x8ef5a7, 0xe75614, 0x08f121, 0x2a9db5,
	0x4d7e6f, 0x5119a5, 0xabf9b5, 0xd6df82, 0x61dd96, 0x023616,
	0x9f3ac4, 0xa1a283, 0x6ded72, 0x7a8d39, 0xa9b882, 0x5c326b,
	0x5b2746, 0xed3400, 0x7700d2, 0x55f4fc, 0x4d5901, 0x8071e0
#   endif
};

/** 0x4b000000, 0xcb000000 */
static const UNUSED align16 float TWO23[2] = { 8.3886080000E+6F, -8.3886080000E+6F };

/** 0x43300000, 0xc3300000 */
static const UNUSED align16 double TWO52[2] = { 4.50359962737049600000E+15, -4.50359962737049600000E+15 };

#if SUPPORTS_LONG_DOUBLE
/** 0x406f000000000000, 0xc06f000000000000 */
static const UNUSED align32 long double TWO112[2] = { 5.19229685853482762853049632922009600E+33L, -5.19229685853482762853049632922009600E+33L };
#endif

static const UNUSED double BIGX = 7.09782712893383973096E+2;
static const UNUSED double SMALLX = -7.45133219101941108420E+2;
static const UNUSED float z_rooteps_f = 1.7263349182589107E-4F;
static const UNUSED double z_rooteps = 7.4505859692E-9;
/** This variable is used by `gamma()` and `lgamma()` */
extern UNUSED int signgam;

static const UNUSED align64 double GAMMA_INTEGRAL[32] = {
	1.0, 1.0, 2.0, 6.0,
	24.0, 120.0, 720.0, 5040.0,
	40320.0, 362880.0, 3628800.0, 39916800.0,
	479001600.0,
	6227020800.0,
	87178291200.0,
	1307674368000.0,
	20922789888000.0,
	355687428096000.0,
	6402373705728000.0,
	121645100408832000.0,
	2432902008176640000.0,
	51090942171709440000.0,
	1124000727777607680000.0
};

static const UNUSED align64 double LANCZOS_DEN_COEFFS[16] = {
	0.0, 39916800.0,
	120543840.0, 150917976.0,
	105258076.0, 45995730.0,
	13339535.0, 2637558.0,
	357423.0, 32670.0,
	1925.0, 66.0, 1.0
};

static const UNUSED align64 double LANCZOS_NUM_COEFFS[16] = {
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

static const UNUSED align32 double PIo2[8] = {
	1.57079625129699707031, 7.54978941586159635335E-08,
	5.39030252995776476554E-15, 3.28200341580791294123E-22,
	1.27065575308067607349E-29, 1.22933308981111328932E-36,
	2.73370053816464559624E-44, 2.16741683877804819444E-51
};

static const UNUSED align32 char debruijn32[32] = {
	0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13,
	31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14
};

static const UNUSED align64 char debruijn64[64] = {
	0, 1, 2, 53, 3, 7, 54, 27, 4, 38, 41, 8, 34, 55, 48, 28, 62, 5,
	39, 46, 44, 42, 22, 9, 24, 35, 59, 56, 49, 18, 29, 11, 63, 52, 6,
	26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10, 51, 25, 36,
	32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12
};

/** @} */  // }

/** @defgroup Eular_Number_Constants Macros for Eular-Number constants
@{ */  // (FB){

/** Eular's Number */
#define M_E   2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274274663919320030599218174135966290435729003342952605956307381323286279434907632338298807531952510190115738341879307021540891499348841675092447
#define M_EF   eval_flt_join(M_E)
/** The inverse of Eular's Number */
#define INVERSE_E   0.3678794411714423215955237701614608674458111310317678345078368016974614957448998033571472743459196437466273252768439952082469757927901290086266535894940987830921943673773381150486389911251456163449877199786844759579397473025498924954532393662
#define INVERSE_EF   eval_flt_join(INVERSE_E)
#if SUPPORTS_LONG_DOUBLE
#   define M_EL   eval_ldbl_join(M_E)
#   define INVERSE_EL   eval_ldbl_join(INVERSE_E)
#endif

/** @} */  // }

/** @defgroup PI_Constants Macros for various PI constants
@{ */  // (FB){

#define __PI   3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652
#define PI   __PI
#define M_PI   __PI
#define PI2   6.2831853071795864769252867665590057683943387987502116419498891846156328125724179972560696506842341359642961730265646132941876892191011644634507188162569622349005682054038770422111192892458979098607639288576219513318668922569512964675735663305
#define PI4   12.566370614359172953850573533118011536788677597500423283899778369231265625144835994512139301368468271928592346053129226588375378438202328926901437632513924469801136410807754084422238578491795819721527857715243902663733784513902592935147132661
/** pi/2 */
#define M_PI_2   1.57079632679489661923132169163975144209858469968755291048747229615390820314310449931401741267105853399107404325664115332354692230477529111586267970406424055872514205135096926055277982231147447746519098221440548783296672306423782
/** pi/4 */
#define M_PI_4   0.78539816339744830961566084581987572104929234984377645524373614807695410157155224965700870633552926699553702162832057666177346115238764555793133985203212027936257102567548463027638991115573723873259549
/** (1/3)pi */
#define PI_1_3   1.0471975511965977461542144610931676280657231331250352736583148641026054687620696662093449417807056893273826955044274355490312815365168607439084531360428270391500947009006461737018532148743163183101273214762703252219778153761585494112622610550
#define PI_2_3   2.0943951023931954923084289221863352561314462662500705473166297282052109375241393324186898835614113786547653910088548710980625630730337214878169062720856540783001894018012923474037064297486326366202546429525406504439556307523170988225245221101
#define PI_4_3   4.1887902047863909846168578443726705122628925325001410946332594564104218750482786648373797671228227573095307820177097421961251261460674429756338125441713081566003788036025846948074128594972652732405092859050813008879112615046341976450490442203
/** 1/pi */
#define M_1_PI   0.3183098861837906715377675267450287240689192914809128974953346881177935952684530701802276055325061719121456854535159160737858236922291573057559348214633996784584799338748181551461554927938506153774347857924347953233867247804834472580236647602
#define INVERSE_PI   M_1_PI
/** 2/pi */
#define M_2_PI   0.63661977236758134307553505349005744813783858296182579499066937623558719053690614036045521106501234382429137090703183214757164738445831461151186964292679935691695986774963631029231098558770123075486957
#define PI_SQUARED   9.8696044010893586188344909998761511353136994072407906264133493762200448224192052430017734037185522318240259137740231440777723481220300467276106176779851976609903998562065756305715060412328403287808693527693421649396665715190445387352617794138
/** (pi*pi)*(1/4) */
#define PI_SQUARED_1_4   2.4674011002723396547086227499690377838284248518101976566033373440550112056048013107504433509296380579560064784435057860194430870305075116819026544194962994152475999640516439076428765103082100821952173381923355412349166428797611346838154448534
#define LOG10_PI   0.4971498726941338543512682882908988736516783243804424461340534999249471120895526746555473864642912223694285899923596439151287253374623084834360752165209902180283467621077569356859157072339384756636526629294044142052704231980047
#define LN_PI   1.1447298858494001741434273513530587116472948129153115715136230714721377698848260797836232702754897077020098122286979891590482055279234565872790810788102868252763939142663459029024847733588699377892031196308247567940119160282172
#define SQRT_PI   1.7724538509055160272981674833411451827975494561223871282138077898529112845910321813749506567385446654162268236242825706662361528657244226025250937096027870684620376986531051228499251730289508262289320953792679628001746390153514797205167001901852340185854469744949126403139217755259062164054193325009063984076137334774751534336679897893658518364087954511651617387600590673934317913328098548462481849020546548521956132515616474675150427387610561079961271072
/** 2/sqrt(pi) */
#define M_2_SQRTPI   1.12837916709551257389615890312154517168810125865799771368817144342128493688298682897348732040421472688605669581272341470337986298965232573273097904003553798658567527411919687952070492870043594514242316049154564044110901705434643
#define TAN_PI   0.0
/** 53 bits of 2/pi; 0x3fe45f30, 0x6dc9c883 */
#define invpio2   6.36619772367581382433E-1
/** first 25 bits of pi/2; 0x3ff921fb, 0x50000000 */
#define pio2_1   1.57079631090164184570
/** pi/2 - pio2_1; 0x3e5110b4, 0x611a6263 */
#define pio2_1t   1.58932547735281966916E-8
/** second 33 bit of pi/2; 0x3dd0b461, 0x1a600000 */
#define pio2_2   6.07710050630396597660E-11
/** pi/2 - (pio2_1+pio2_2); 0x3ba3198a, 0x2e037073 */
#define pio2_2t   2.02226624879595063154E-21
/** third 33 bit of pi/2; 0x3ba3198a, 0x2e000000 */
#define pio2_3   2.02226624871116645580E-21
/** pi/2 - (pio2_1+pio2_2+pio2_3); 0x397b839a, 0x252049c1 */
#define pio2_3t   8.47842766036889956997E-32
#define M_PIF   eval_flt_join(M_PI)
#define PIF   M_PIF
#define PI2F   eval_flt_join(PI2)
#define PI4F   eval_flt_join(PI4)
#define M_PI_2F   eval_flt_join(M_PI_2)
#define M_PI_4F   eval_flt_join(M_PI_4)
#define PI_1_3F   eval_flt_join(PI_1_3)
#define PI_2_3F   eval_flt_join(PI_2_3)
#define PI_4_3F   eval_flt_join(PI_4_3)
#define M_1_PIF   eval_flt_join(M_1_PI)
#define INVERSE_PIF   M_1_PIF
#define M_2_PIF   eval_flt_join(M_2_PI)
#define PI_SQUAREDF   eval_flt_join(PI_SQUARED)
#define PI_SQUARED_1_4F   eval_flt_join(PI_SQUARED_1_4)
#define LN_PIF   eval_flt_join(LN_PI)
#define LOG10_PIF   eval_flt_join(LOG10_PI)
#define SQRT_PIF   eval_flt_join(SQRT_PI)
#define M_2_SQRTPIF   eval_flt_join(M_2_SQRTPI)
#define TAN_PIF   0.0F
#if SUPPORTS_LONG_DOUBLE
#   define M_PIL   eval_ldbl_join(M_PI)
#   define PIL   M_PIL
#   define PI2L   eval_ldbl_join(PI2)
#   define PI4L   eval_ldbl_join(PI4)
#   define M_PI_2L   eval_ldbl_join(M_PI_2)
#   define M_PI_4L   eval_ldbl_join(M_PI_4)
#   define PI_1_3L   eval_ldbl_join(PI_1_3)
#   define PI_2_3L   eval_ldbl_join(PI_2_3)
#   define PI_4_3L   eval_ldbl_join(PI_4_3)
#   define M_1_PIL   eval_ldbl_join(M_1_PI)
#   define INVERSE_PIL   M_1_PIL
#   define M_2_PIL   eval_ldbl_join(M_2_PI)
#   define PI_SQUAREDL   eval_ldbl_join(PI_SQUARED)
#   define PI_SQUARED_1_4L   eval_ldbl_join(PI_SQUARED_1_4)
#   define LN_PIL   eval_ldbl_join(LN_PI)
#   define LOG10_PIL   eval_ldbl_join(LOG10_PI)
#   define SQRT_PIL   eval_ldbl_join(SQRT_PI)
#   define M_2_SQRTPIL   eval_ldbl_join(M_2_SQRTPI)
#   define TAN_PIL   0.0L
#   define pio2_hi   1.57079632679489661926L
#   define pio2_lo   -2.50827880633416601173E-20L
#   define __pio2_hi   pio2_hi
#   define __pio2_lo   pio2_lo
#endif

/** @} */  // }

/** @defgroup Logarithm_Constants Macros for various logarithm constants
@{ */  // (FB){

/** log2(e) */
#define M_LOG2E   1.44269504088896340735992468100189213742664595415298593413544940693110921918118507988552662289350634449699751830965254425559310168716835964272066215822347933627453736988471849363070138766353201553389431891666483764312861542404747
/** log10(e) */
#define M_LOG10E   0.4342944819032518276511289189166050822943970058036665661144537831658646492088707747292249493384317483187061067447663037336416792871589639065692210646628122658521270865686703295933708696588266883311636077384905142844348666768646586085135561482
#define LOG10_E   M_LOG10E
#define LOG2_DIV_LOG10   0.30102999566398119521373889472449302676818988146210854131042746112710818927442450948692725211818617204068447719143099537909476788113352350599969233370469557506450296425419340266181973431160294350118390289817858261715443953186192
#define M_LOG2EF   eval_flt_join(M_LOG2E)
#define M_LOG10EF   eval_flt_join(M_LOG10E)
#define LOG10_EF   M_LOG10EF
#if SUPPORTS_LONG_DOUBLE
#   define M_LOG2EL   eval_ldbl_join(M_LOG2E)
#   define M_LOG10EL   eval_ldbl_join(M_LOG10E)
#   define LOG10_EL   M_LOG10EL
#endif

/** @} */  // }

/** @defgroup Natural_Logarithm_Constants Macros for various natural logarithm constants
@{ */  // (FB){

/** ln(2) */
#define M_LN2   0.69314718055994530941723212145817656807550013436025525412068000949339362196969471560586332699641868754200148102057068573368552023575813055703267075163507596193072757082837143519030703862389167347112335011536449795523912047517268
#define LN2     M_LN2
/** ln(10) */
#define M_LN10   2.30258509299404568401799145468436420760110148862877297603332790096757260967735248023599720508959829834196778404228624863340952546508280675666628736909878168948290720832555468084379989482623319852839350530896537773262884616336622
#define LN_E   1.0
/** 1/ln(10) */
#define M_IVLN10   0.43429448190325182765112891891660508229439700580366656611445378316586464920887077472922494933843174831870610674476630373364167928715896390656922106466281226585212708656867032959337086965882668833116360773849051428443486667686465
#define M_LN2F   eval_flt_join(M_LN2)
#define LN2F   M_LN2F
#define M_LN10F   eval_flt_join(M_LN10)
/** 1/ln(10) */
#define M_IVLN10F   eval_flt_join(M_IVLN10)
#if SUPPORTS_LONG_DOUBLE
#   define M_LN2L   eval_ldbl_join(M_LN2)
#   define LN2L   M_LN2L
#   define M_LN10L   eval_ldbl_join(M_LN10)
/** 1/ln(10) */
#   define M_IVLN10l   eval_ldbl_join(M_IVLN10)
#endif

/** @} */  // }

/** @defgroup Square_Root_Constants Macros for various square root constants
@{ */  // (FB){

/** sqrt(0.5) */
#define SQRT_HALF   0.70710678118654752440084436210484903928483593768847403658833986899536623923105351942519376716382078636750692311545614851246241802792536860632206074854996791570661133296375279637789997525057639103028573505477998580298513726729843
#define __SQRT_HALF   SQRT_HALF
#define SQRT_3_DIV_4   0.43301270189221932338186158537646809173570131345259515701395174486298325422720000927028654668931214391890653535385167575
/** sqrt(2) */
#define M_SQRT2   1.4142135623730950488016887242096980785696718753769480731766797379907324784621070388503875343276415727350138462309122970249248360558507372126441214970999358314132226659275055927557999505011527820605714701095599716059702745345968
#define SQRT_2   M_SQRT2
#define SQRT_3   1.73205080756887729352744634150587236694280525381038062805580697945193301690880003708114618675724857567562614141540670302
#define SQRT_5   2.23606797749978969640917366873127623544061835961152572427089724541052092563780489941441440837878227496950817615077378350425326772444707386358636012153345270886677817319187916581127664532263985658053576135041753378500342339241406
#define SQRT_6   2.4494897427831780981972840747058913919659474806566701284326925672509603774573150265398594331046402348185946012266
#define SQRT_7   2.64575131106459059050161575363926042571025918308245018036833445920106882323028362776039288647454361061506457833849746309574352988862721478442739055588010772271715072972832389229968959486508726070097805420372382802371594110034193
#define SQRT_8   2.8284271247461900976033774484193961571393437507538961463533594759814649569242140777007750686552831454700276924618
#define SQRT_10   3.1622776601683793319988935444327185337195551393252168268575048527925944386392382213442481083793002951873472841528
#define SQRT_11   3.31662479035539984911493273667068668392708854558935359705868214611648464260904384670884339912829065090701255784952745659227543978485754747977932493304472884730287397482865568257739444461209804447719311235714413297152109883266049
#define SQRT_12   3.4641016151377545870548926830117447338856105076207612561116139589038660338176000741622923735144971513512522828308
#define SQRT_13   3.60555127546398929311922126747049594625129657384524621271045305622716694829301044520461908201849071767351418202406354037603067826469780770516301716689270975774269056427415263323383039496234694479627322999628800326885642721307211
#define SQRT_14   3.7416573867739413855837487323165493017560198077787269463037454673200351563069390279768098951943795715009910887277
#define SQRT_15   3.8729833462074168851792653997823996108329217052915908265875737661134830919369790335192873768586735179163022068609
#define SQRT_16   4.0
#define SQRT_17   4.12310562561766054982140985597407702514719922537362043439863357309495434633762159358786365081068429668454404093921414161530142084041586836307954814574690697767702326643624086308779056757238570822552138073256308386030914274980467
#define SQRT_19   4.35889894354067355223698198385961565913700392523244493689034413815955732820315808565615915585194452690565862129827421362958399278382611701215656083641746990097775291887940589006199671566312074022310240232435673598104840919993150
#define SQRT_20   4.4721359549995793928183473374625524708812367192230514485417944908210418512756097988288288167575645499390163523015
#define SQRT_21   4.5825756949558400065880471937280084889844565767679719026072421239068684255477708866043615594934450326776009053975857408733118991707556019635738633623447553702817228244277981919405969049143449200907589407063891768364965598654748
#define SQRT_22   4.6904157598234295545656301135444662805882283534117371536057018910170246327532397214821155960615431353545958966615
#define SQRT_23   4.7958315233127195415974380641626939199967070419041293464853091144482572359074640824921914464369188606174745632457
#define SQRT_24   4.8989794855663561963945681494117827839318949613133402568653851345019207549146300530797188662092804696371892024532
/** 1/sqrt(2) */
#define M_SQRT1_2   0.70710678118654752440084436210484903928483593768847403658833986899536623923105351942519376716382078636750692311545614851246241802792536860632206074854996791570661133296375279637789997525057639103028573505477998580298513726729843
#define SQRT_E   1.6487212707001281468486507878141635716537761007101480115750793116406610211942156086327765200563666430028666377563077970046711669752196091598409714524900597969294226590984039147199484646594892448968689053364184657208410666568598
/** sqrt(0.5) */
#define SQRT_HALFF   eval_flt_join(SQRT_HALF)
/** sqrt(3/4) */
#define SQRT_3_DIV_4F   eval_flt_join(SQRT_3_DIV_4)
#define M_SQRT2F   eval_flt_join(M_SQRT2)
#define SQRT_2F   M_SQRT2L
#define SQRT_3F   eval_flt_join(SQRT_3)
/** 1/sqrt(2) */
#define M_SQRT1_2F   eval_flt_join(M_SQRT1_2)
#define SQRT_EF   eval_flt_join(SQRT_E)
#if SUPPORTS_LONG_DOUBLE
/** sqrt(0.5) */
#define SQRT_HALFL   eval_ldbl_join(SQRT_HALF)
/** sqrt(3/4) */
#   define SQRT_3_DIV_4L   eval_ldbl_join(SQRT_3_DIV_4)
#   define M_SQRT2L   eval_ldbl_join(M_SQRT2)
#   define SQRT_2L   M_SQRT2L
#   define SQRT_3L   eval_ldbl_join(SQRT_3)
/** 1/sqrt(2) */
#   define M_SQRT1_2L   eval_ldbl_join(M_SQRT1_2)
#   define SQRT_EL   eval_ldbl_join(SQRT_E)
#endif

/** @} */  // }

/** @defgroup Trigonometry_Constants Macros for various trigonometry constants
@{ */  // (FB){

#define TAN_E   -0.45054953406980749571063417770127929443957091173203671001233561163230090199510257284268170870246704398432546310
#define TAN_EF   eval_flt_join(TAN_E)
#if SUPPORTS_LONG_DOUBLE
#   define TAN_EL   eval_ldbl_join(TAN_E)
#endif

/** @} */  // }

/** @defgroup Angle_Constants Macros for various angle constants
@{ */  // (FB){

#define DEG2GRAD   1.11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
#define DEG2RAD   0.01745329251994329576923690768488612713442871888541725456097191440171009114603449443682241569634509482212304492507379059248385469227528101239847421893404711731916824501501076956169755358123860530516878869127117208703296358960264
#define GRAD2DEG   0.9
#define GRAD2RAD   0.01570796326794896619231321691639751442098584699687552910487472296153908203143104499314017412671058533991074043256641153323546922304775291115862679704064240558725142051350969260552779822311474477465190982214405487832966723064237
#define RAD2DEG   57.2957795130823208767981548141051703324054724665643215491602438612028471483215526324409689958511109441862233816328648932814482646012483150360682678634119421225263880974672679263079887028931107679382614426382631582096104604870205
#define RAD2GRAD   63.6619772367581343075535053490057448137838582961825794990669376235587190536906140360455211065012343824291370907031832147571647384458314611511869642926799356916959867749636310292310985587701230754869571584869590646773449560966894
#define RIGHT_ANGLE_DEG   90.0
#define RIGHT_ANGLE_DEG_INT   90
#define RIGHT_ANGLE_GRAD   100
#define RIGHT_ANGLE_RAD   M_PI_2
#define RIGHT_ANGLE_REV   0.25

/** @} */  // }

/** @defgroup Scientific_Constants Macros for various scientific constants
@{ */  // (FB){

#define ARTIN_CONSTANT   0.37395581361920228805472805434641641
#define ATOMIC_UNIT_OF_CHARGE   1.602176565E-19
#define ATOMIC_UNIT_OF_CURRENT   0.00662361795
#define ATOMIC_UNIT_OF_FORCE   8.23872278E-8
#define AVOGADRO_CONSTANT   6.02214179E+23
#define BERNSTEINS_CONSTANT   5.2917721092E-11
#define BOHR_RADIUS   0.28016949902386913303643649123067200
#define BOLTZMANN_CONSTANT   1.3806488E-23
#define CHAMPERNOWNE_CONSTANT   0.12345678910111213141516171819202122232425262728293031323334353637383940414243
#define CHEBYSHEV_CONSTANT   0.59017029950804811302266897027924429
#define COMPTON_WAVELENGTH   2.4263102389E-12
#define DELIAN_CONSTANT   1.25992104989487316476721060727822835
#define DEUTERON_G_FACTOR   0.8574382308
/** Mass of a deuteron in kilograms */
#define DEUTERON_MASS   3.34358348E-27
#define DEUTERON_MOLAR_MASS   0.00201355321271
#define DOUBLE_FACTORIAL_CONSTANT   3.05940740534257614453947549923327861
#define ELECTRON_G_FACTOR   -2.00231930436
/** Mass of an electron in kilograms */
#define ELECTRON_MASS   9.10938291E-31
#define ELECTRON_VOLT   1.602176565E-19
#define ELECTRON_MUON_MASS_RATIO   0.00483633166
#define ELECTRON_NEUTRON_MAGNETIC_MOMENT_RATIO   960.9205
#define MURATA_CONSTANT   2.82641999706759157554639174723695374
#define OMEGA   0.56714329040978387299996866221035555
#define PARIS_CONSTANT   1.09864196439415648573466891734359621
#define SALEM_NUMBER   1.17628081825991750654407033847403505
#define TWIN_PRIMES_CONSTANT   0.66016181584686957392781211001455577
#define VARDI_CONSTANT   1.26408473530530111307959958416466949

/** @} */  // }


// QUATERNION CONSTANTS

/** @defgroup Quaternion_Constants Macros for various Quaternion constants
@{ */  // (FB){

// quaternion_float

#define QUATERNION_ZEROF   ({ 0.0F, 0.0F, 0.0F, 0.0F })
#define QUATERNION_ONEF   ({ 1.0, 0.0F, 0.0F, 0.0F })
#define QUATERNION_EF   ({ M_EF, 0.0F, 0.0F, 0.0F })
#define QUATERNION_PIF   ({ M_PIF, 0.0F, 0.0F, 0.0F })
#define QUATERNION_PI2F   ({ M_PI_2F, 0.0F, 0.0F, 0.0F })
#define QUATERNION_PI4F   ({ M_PI_4F, 0.0F, 0.0F, 0.0F })
#define QUATERNION_INV_PIF   ({ INVERSE_PIF, 0.0F, 0.0F, 0.0F })
#define QUATERNION_IDENTF   ({ 1.0F, 0.0F, 0.0F, 0.0F })

// quaternion (`double`)

#define QUATERNION_ZERO   ({ 0.0, 0.0, 0.0, 0.0 })
#define QUATERNION_ONE   ({ 1.0, 0.0, 0.0, 0.0 })
#define QUATERNION_E   ({ M_EF, 0.0, 0.0, 0.0 })
#define QUATERNION_PI   ({ M_PI, 0.0, 0.0, 0.0 })
#define QUATERNION_PI2   ({ M_PI_2, 0.0, 0.0, 0.0 })
#define QUATERNION_PI4   ({ M_PI_4, 0.0, 0.0, 0.0 })
#define QUATERNION_INV_PI   ({ INVERSE_PI, 0.0, 0.0, 0.0 })
#define QUATERNION_IDENT   ({ 1.0, 0.0, 0.0, 0.0 })

// quaternion_long_double

#if SUPPORTS_LONG_DOUBLE
#   define QUATERNION_ZEROL   ({ 0.0L, 0.0L, 0.0L, 0.0L })
#   define QUATERNION_ONEL   ({ 1.0, 0.0L, 0.0L, 0.0L })
#   define QUATERNION_EL   ({ M_EL, 0.0L, 0.0L, 0.0L })
#   define QUATERNION_PIL   ({ M_PIL, 0.0L, 0.0L, 0.0L })
#   define QUATERNION_PI2L   ({ M_PI_2L, 0.0L, 0.0L, 0.0L })
#   define QUATERNION_PI4L   ({ M_PI_4L, 0.0L, 0.0L, 0.0L })
#   define QUATERNION_INV_PIL   ({ INVERSE_PIL, 0.0L, 0.0L, 0.0L })
#   define QUATERNION_IDENTL   ({ 1.0L, 0.0L, 0.0L, 0.0L })
#endif

/** @} */  // }


#endif  // MATH_H_MATHDEF


/* FLOATING-POINT MACROS (<fpu_control.h>, <float.h>, & <decfloat.h>) */


#if (!(defined(FLOAT_H) || defined(_FLOAT_H_) || defined(_FLOAT_LIB_H_) || defined(VALUES_H) || defined(FPMAX_H) || defined(FPU_CONTROL_H) || defined(IEEE754_H) || defined(_IEEE754_H) || defined(_IEEE754_H_)))  // http://www.cplusplus.com/reference/cfloat/ & http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/float.h.html
#define FLOAT_H   (1)
#define _FLOAT_H_   (1)
#define _FLOAT_H   (1)
#define _FLOAT_LIB_H_   (1)
#define _VALUES_H   (1)
#define _VALUES_H_   (1)
#define FPMAX_H   (1)
#define _FPMAX_H   (1)
#define _FPMAX_H_   (1)
#define _UCLIBC_FPMAX_H   (1)
#define FPU_CONTROL_H   (1)
#define _FPU_CONTROL_H   (1)
#define _FPU_CONTROL_H_   (1)
#define FPU_CONTROL_H_   (1)
#define IEEE754_H   (1)
#define _IEEE754_H   (1)
#define _IEEE754_H_   (1)


// FLOAT-POINT CATEGORIES

/** @defgroup Float_Point_Categories Macros representing the different categories of float-points
@{ */  // (FB){

/** Not-A-Number */
#define FP_NAN   (0)
/** Positive or negative infinity (overflow) */
#define FP_INFINITE   (1)
/** Value of zero */
#define FP_ZERO   (2)
/** Sub-normal value (underflow) */
#define FP_SUBNORMAL   (3)
/** Normal value (not an underflow, overflow, zero, `INF`, nor `NAN`) */
#define FP_NORMAL   (4)

/** @} */  // }


// MATH_ERRHANDLING MACROS

/** @defgroup Math_Errors Code associated with math-errors
@{ */  // (FB){

/** Bitmask for the math_errhandling macro; errno set by math function */
#define MATH_ERRNO   1
/** Bitmask for the math_errhandling macro; Exception raised by math function */
#define MATH_ERREXCEPT   2
#define math_errhandling   (MATH_ERRNO | MATH_ERREXCEPT)

/** Types of exceptions in the `type` field in `__exception` */
enum MATHERR_TYPE {
	DOMAIN = 1,
	SING = 2,
	OVERFLOW = 3,
	UNDERFLOW = 4,
	TLOSS = 5,
	PLOSS = 6
};

/** Support for various different standard error handling behaviors */
typedef enum _LIB_VERSION_TYPE {
	/** IEEE754/IEEE854 */
	_IEEE_ = -1,
	/** System V release 4 */
	_SVID_ = 0,
	/** Unix98 */
	_XOPEN_ = 1,
	/** POSIX */
	_POSIX_ = 2,
	/** ISO C99 */
	_ISOC_ = 3
} _LIB_VERSION_TYPE;

/** This variable can be changed at run-time to any of the values above to affect floating point error handling behavior (it may also be necessary to change the hardware FPU exception settings) */
extern UNUSED _LIB_VERSION_TYPE _LIB_VERSION;

#if ((!defined(LIBMVER)) || ((LIBMVER > 3) || (LIBMVER < -1)))  // _POSIX_ is the default
#   define LIBMVER   2
_LIB_VERSION_TYPE _LIB_VERSION = _POSIX_;
#elif ((LIBMVER > 3) || (LIBMVER < -1) || (LIBMVER == 2))
_LIB_VERSION_TYPE _LIB_VERSION = _POSIX_;
#elif (LIBMVER == -1)
_LIB_VERSION_TYPE _LIB_VERSION = _IEEE_;
#elif (LIBMVER == 0)
_LIB_VERSION_TYPE _LIB_VERSION = _SVID_;
#elif (LIBMVER == 1)
_LIB_VERSION_TYPE _LIB_VERSION = _XOPEN_;
#elif (LIBMVER == 3)
_LIB_VERSION_TYPE _LIB_VERSION = _ISOC_;
#else
_LIB_VERSION_TYPE _LIB_VERSION = _POSIX_;
#endif
#if (LIBMVER != 0)  // SVID
#   define _IEEE_LIBM   (1)
#endif
#define IS_LIBM_IEEE   (LIBMVER == -1)
#define IS_LIBM_SVID   (LIBMVER == 0)
#define IS_LIBM_XOPEN   (LIBMVER == 1)
#define IS_LIBM_POSIX   (LIBMVER == 2)
#define IS_LIBM_ISOC   (LIBMVER == 3)

/** @} */  // }


// FP_FAST_FMA

#ifdef __FP_FAST_FMAF
/** The compiler will define `__FP_FAST_FMAF` if the `fma()` builtins are supported for floats */
#   define FP_FAST_FMAF   (1)
#endif
#ifdef __FP_FAST_FMA
/** The compiler will define `__FP_FAST_FMA` if the `fma()` builtins are supported for doubles */
#   define FP_FAST_FMA   (1)
#endif
#ifdef __FP_FAST_FMAL
/** The compiler will define `__FP_FAST_FMAL` if the `fma()` builtins are supported for long doubles */
#   define FP_FAST_FMAL   (1)
#endif


// FLOAT VALUES & PROPERTIES

/** @defgroup Float16_Properties Macros providing special values and properties concerning half-floats (`float16`)
@{ */  // (FB){

#ifndef __FLT16_RADIX__
/** Radix of exponent representation */
#   define __FLT16_RADIX__   FLT_RADIX
/** Radix of exponent representation */
#   define FLT16_RADIX   FLT_RADIX
#else
/** Radix of exponent representation */
#   define FLT16_RADIX   __FLT16_RADIX__
#endif
#ifndef _FLT16_RADIX
/** Radix of exponent representation */
#   define _FLT16_RADIX   FLT16_RADIX
#endif
#ifndef __FLT16_HAS_DENORM__
/** Float16 denormal values are supported */
#   define __FLT16_HAS_DENORM__   (1)
/** Float16 denormal values are supported */
#   define FLT16_HAS_DENORM   (1)
#else
/** Float16 denormal values are supported */
#   define FLT16_HAS_DENORM   __FLT16_HAS_DENORM__
#endif
#ifndef __FLT16_HAS_INFINITY__
/** Float16 infinity is supported */
#   define __FLT16_HAS_INFINITY__   (1)
/** Float16 infinity is supported */
#   define FLT16_HAS_INFINITY   (1)
#else
/** Float16 infinity is supported */
#   define FLT16_HAS_INFINITY   __FLT16_HAS_INFINITY__
#endif
#ifndef __FLT16_HAS_QUIET_NAN__
/** Float16 quiet NAN (QNAN) is supported */
#   define __FLT16_HAS_QUIET_NAN__   (1)
/** Float16 quiet NAN (QNAN) is supported */
#   define FLT16_HAS_QUIET_NAN   (1)
#else
/** Float16 quiet NAN (QNAN) is supported */
#   define FLT16_HAS_QUIET_NAN   __FLT16_HAS_QUIET_NAN__
#endif
#ifndef __FLT16_MANT_DIG__
/** Number of base-FLT_RADIX digits in the significand of a float16 */
#   define __FLT16_MANT_DIG__   (11)
/** Number of base-FLT_RADIX digits in the significand of a float16 */
#   define FLT16_MANT_DIG   (1)
#else
/** Number of base-FLT_RADIX digits in the significand of a float16 */
#   define FLT16_MANT_DIG   __FLT16_MANT_DIG__
#endif
#ifndef __FLT16_DIG__
/** Number of decimal digits of precision in a float16 */
#   define __FLT16_DIG__   (3)
/** Number of decimal digits of precision in a float16 */
#   define FLT16_DIG   (3)
#else
/** Number of decimal digits of precision in a float16 */
#   define FLT16_DIG   __FLT16_DIG__
#endif
#ifndef __FLT16_DECIMAL_DIG__
/** Maximum significant figures */
#   define __FLT16_DECIMAL_DIG__   5
#endif
#ifndef FLT16_DECIMAL_DIG
/** Maximum significant figures */
#   define FLT16_DECIMAL_DIG   __FLT16_DECIMAL_DIG__
#endif
#ifndef __FLT16_EPSILON__
/** Difference between 1.0 and the minimum float16 greater than 1.0 */
#   define __FLT16_EPSILON__   (9.76562500000000000000000000000000000E-4F16)
/** Difference between 1.0 and the minimum float16 greater than 1.0 */
#   define FLT16_EPSILON   __FLT16_EPSILON__
#else
/** Difference between 1.0 and the minimum float16 greater than 1.0 */
#   define FLT16_EPSILON   __FLT16_EPSILON__
#endif
#ifndef __FLT16_MIN_EXP__
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float16 */
#   define __FLT16_MIN_EXP__   (-13)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float16 */
#   define FLT16_MIN_EXP   (-13)
#else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float16 */
#   define FLT16_MIN_EXP   __FLT16_MIN_EXP__
#endif
#ifndef __FLT16_MIN__
/** Minimum normalised float16 */
#   define __FLT16_MIN__   (6.10351562500000000000000000000000000E-5F16)
/** Minimum normalised float16 */
#   define FLT16_MIN   __FLT16_MIN__
#else
/** Minimum normalised float16 */
#   define FLT16_MIN   __FLT16_MIN__
#endif
#ifndef __FLT16_MIN_10_EXP__
/** Minimum int x such that 10**x is a normalised float16 */
#   define __FLT16_MIN_10_EXP__   (-4)
/** Minimum int x such that 10**x is a normalised float16 */
#   define FLT16_MIN_10_EXP   (-4)
#else
/** Minimum int x such that 10**x is a normalised float16 */
#   define FLT16_MIN_10_EXP   __FLT16_MIN_10_EXP__
#endif
#ifndef __FLT16_DENORM_MIN__
/** Minimal denormal float16 value */
#   define __FLT16_DENORM_MIN__   (5.96046447753906250000000000000000000E-8F16)
/** Minimal denormal float16 value */
#   define FLT16_DENORM_MIN   __FLT16_DENORM_MIN__
#else
/** Minimal denormal float16 value */
#   define FLT16_DENORM_MIN   __FLT16_DENORM_MIN__
#endif
#ifndef FLT16_TRUE_MIN
/** Minimal denormal float16 value */
#   define FLT16_TRUE_MIN   FLT16_DENORM_MIN
#endif
#ifndef FLT16_SUBNORMAL_MIN
/** Minimal denormal float16 value */
#   define FLT16_SUBNORMAL_MIN   FLT16_DENORM_MIN
#endif
#ifndef __FLT16_MAX_EXP__
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float16 */
#   define __FLT16_MAX_EXP__   (16)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float16 */
#   define FLT16_MAX_EXP   (16)
#else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float16 */
#   define FLT16_MAX_EXP   __FLT16_MAX_EXP__
#endif
#ifndef __FLT16_MAX__
/** The maximum representable finite float16 */
#   define __FLT16_MAX__   (6.55040000000000000000000000000000000E+4F16)
/** The maximum representable finite float16 */
#   define FLT16_MAX   __FLT16_MAX__
#else
/** The maximum representable finite float16 */
#   define FLT16_MAX   __FLT16_MAX__
#endif
#ifndef __FLT16_MAX_10_EXP__
/** Maximum int x such that 10**x is a representable float16 */
#   define __FLT16_MAX_10_EXP__   (14)
/** Maximum int x such that 10**x is a representable float16 */
#   define FLT16_MAX_10_EXP   (14)
#else
/** Maximum int x such that 10**x is a representable float16 */
#   define FLT16_MAX_10_EXP   __FLT16_MAX_10_EXP__
#endif

/** @} */  // }


/** @defgroup Float_Properties Macros providing special values and properties concerning single-floats (`float`)
@{ */  // (FB){

#ifndef __FLT_RADIX__
/** Radix of exponent representation; Base or radix of exponent representation (integer >1) */
#   define __FLT_RADIX__   (2)
/** Radix of exponent representation; Base or radix of exponent representation (integer >1) */
#   define FLT_RADIX   (2)
#else
/** Radix of exponent representation; Base or radix of exponent representation (integer >1) */
#   define FLT_RADIX   __FLT_RADIX__
#endif
#ifndef _FLT_RADIX
/** Radix of exponent representation; Base or radix of exponent representation (integer >1) */
#   define _FLT_RADIX   FLT_RADIX
#endif
#ifndef __FLT_HAS_DENORM__
/** `float` denormal values are supported */
#   define __FLT_HAS_DENORM__   (1)
/** `float` denormal values are supported */
#   define FLT_HAS_DENORM   (1)
#else
/** `float` denormal values are supported */
#   define FLT_HAS_DENORM   __FLT_HAS_DENORM__
#endif
#ifndef __FLT_HAS_INFINITY__
/** `float` infinity is supported */
#   define __FLT_HAS_INFINITY__   (1)
/** `float` infinity is supported */
#   define FLT_HAS_INFINITY   (1)
#else
/** `float` infinity is supported */
#   define FLT_HAS_INFINITY   __FLT_HAS_INFINITY__
#endif
#ifndef __FLT_HAS_QUIET_NAN__
/** `float` quiet NAN (QNAN) is supported */
#   define __FLT_HAS_QUIET_NAN__   (1)
/** `float` quiet NAN (QNAN) is supported */
#   define FLT_HAS_QUIET_NAN   (1)
#else
/** `float` quiet NAN (QNAN) is supported */
#   define FLT_HAS_QUIET_NAN   __FLT_HAS_QUIET_NAN__
#endif
#ifndef __FLT_MANT_DIG__
/** Number of base-FLT_RADIX digits in the significand of a float */
#   define __FLT_MANT_DIG__   (24)
/** Number of base-FLT_RADIX digits in the significand of a float */
#   define FLT_MANT_DIG   (24)
#else
/** Number of base-FLT_RADIX digits in the significand of a float */
#   define FLT_MANT_DIG   __FLT_MANT_DIG__
#endif
#ifndef __FLT_DIG__
/** Number of decimal digits of precision in a float */
#   define __FLT_DIG__   (6)
/** Number of decimal digits of precision in a float */
#   define FLT_DIG   (6)
#else
/** Number of decimal digits of precision in a float */
#   define FLT_DIG   __FLT_DIG__
#endif
#ifndef __FLT_DECIMAL_DIG__
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define FLT_DECIMAL_DIG   (9)
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define __FLT_DECIMAL_DIG__   (9)
#else
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define FLT_DECIMAL_DIG   __FLT_DECIMAL_DIG__
#endif
#ifndef __FLT_EPSILON__
/** Difference between 1.0 and the minimum float greater than 1.0 */
#   define __FLT_EPSILON__   (1.19209289550781250000000000000000000E-7F)
/** Difference between 1.0 and the minimum float greater than 1.0 */
#   define FLT_EPSILON   __FLT_EPSILON__
#else
/** Difference between 1.0 and the minimum float greater than 1.0 */
#   define FLT_EPSILON   __FLT_EPSILON__
#endif
#ifndef __FLT_MIN_EXP__
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float */
#   define __FLT_MIN_EXP__   (-125)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float */
#   define FLT_MIN_EXP   (-125)
#else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float */
#   define FLT_MIN_EXP   __FLT_MIN_EXP__
#endif
/** Alias for FLT_MIN_EXP */
#define FMINEXP   FLT_MIN_EXP
#ifndef __FLT_MIN__
/** Minimum normalised float */
#   define __FLT_MIN__   (1.17549435082228750796873653722224568E-38F)
/** Minimum normalised float */
#   define FLT_MIN   __FLT_MIN__
#else
/** Minimum normalised float */
#   define FLT_MIN   __FLT_MIN__
#endif
/** Alias for FLT_MIN */
#define MINFLOAT   FLT_MIN
#ifndef __FLT_MIN_10_EXP__
/** Minimum int x such that 10**x is a normalised float */
#   define __FLT_MIN_10_EXP__   (-37)
/** Minimum int x such that 10**x is a normalised float */
#   define FLT_MIN_10_EXP   (-37)
#else
/** Minimum int x such that 10**x is a normalised float */
#   define FLT_MIN_10_EXP   __FLT_MIN_10_EXP__
#endif
#ifndef __FLT_DENORM_MIN__
/** Minimal denormal float value */
#      define __FLT_DENORM_MIN__   (1.40129846432481707092372958328991613E-45F)
/** Minimal denormal float value */
#      define FLT_DENORM_MIN   __FLT_DENORM_MIN__
#   else
/** Minimal denormal float value */
#      define FLT_DENORM_MIN   __FLT_DENORM_MIN__
#endif
#ifndef FLT_TRUE_MIN
/** Minimal denormal float value */
#   define FLT_TRUE_MIN   FLT_DENORM_MIN
#endif
#ifndef FLT_SUBNORMAL_MIN
/** Minimal denormal float value */
#   define FLT_SUBNORMAL_MIN   FLT_DENORM_MIN
#endif
#ifndef __FLT_MAX_EXP__
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float */
#   define __FLT_MAX_EXP__   (128)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float */
#   define FLT_MAX_EXP   (128)
#else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float */
#   define FLT_MAX_EXP   __FLT_MAX_EXP__
#endif
/** Alias for FLT_MAX_EXP */
#define FMAXEXP   FLT_MAX_EXP
#ifndef __FLT_MAX__
/** The maximum representable finite float */
#   define __FLT_MAX__   (3.40282346638528859811704183484516925440000000E+38F)
/** The maximum representable finite float */
#   define FLT_MAX   __FLT_MAX__
#else
/** The maximum representable finite float */
#   define FLT_MAX   __FLT_MAX__
#endif
/** X/Open requires MAXFLOAT (Alias for FLT_MAX; Same value as SVID's HUGE) */
#define MAXFLOAT   FLT_MAX
#ifndef __FLT_MAX_10_EXP__
/** Maximum int x such that 10**x is a representable float */
#   define __FLT_MAX_10_EXP__   (38)
/** Maximum int x such that 10**x is a representable float */
#   define FLT_MAX_10_EXP   (38)
#else
/** Maximum int x such that 10**x is a representable float */
#   define FLT_MAX_10_EXP   __FLT_MAX_10_EXP__
#endif
#define FLT_MAX_10_EXP_LOG   5
#define FLT_MAX_10   1.0E+38F
#define FLT_LARGE   1.0E+37F
/** Added to exponent */
#define IEEE754_FLOAT_BIAS   0x7f
#define EXCESSF   126
#define HIDDENF   0x800000

/** @} */  // }


/** @defgroup Double_Properties Macros providing special values and properties concerning double-floats (`double`)
@{ */  // (FB){

#ifndef __DBL_RADIX__
/** Radix of exponent representation */
#   define __DBL_RADIX__   FLT_RADIX
/** Radix of exponent representation */
#   define DBL_RADIX   FLT_RADIX
#else
/** Radix of exponent representation */
#   define DBL_RADIX   __DBL_RADIX__
#endif
#ifndef _DBL_RADIX
/** Radix of exponent representation */
#   define _DBL_RADIX   DBL_RADIX
#endif
#ifndef __DBL_HAS_DENORM__
/** `double` denormal values are supported */
#   define __DBL_HAS_DENORM__   (1)
/** `double` denormal values are supported */
#   define DBL_HAS_DENORM   (1)
#else
/** `double` denormal values are supported */
#   define DBL_HAS_DENORM   __DBL_HAS_DENORM__
#endif
#ifndef __DBL_HAS_INFINITY__
/** `double` infinity is supported */
#   define __DBL_HAS_INFINITY__   (1)
/** `double` infinity is supported */
#   define DBL_HAS_INFINITY   (1)
#else
/** `double` infinity is supported */
#   define DBL_HAS_INFINITY   __DBL_HAS_INFINITY__
#endif
#ifndef __DBL_HAS_QUIET_NAN__
/** `double` quiet NAN (QNAN) is supported */
#   define __DBL_HAS_QUIET_NAN__   (1)
/** `double` quiet NAN (QNAN) is supported */
#   define DBL_HAS_QUIET_NAN   (1)
#else
/** `double` quiet NAN (QNAN) is supported */
#   define DBL_HAS_QUIET_NAN   __DBL_HAS_QUIET_NAN__
#endif
#ifndef __DBL_MANT_DIG__
/** Number of base-FLT_RADIX digits in the significand of a double */
#   define __DBL_MANT_DIG__   (53)
/** Number of base-FLT_RADIX digits in the significand of a double */
#   define DBL_MANT_DIG   (53)
#else
/** Number of base-FLT_RADIX digits in the significand of a double */
#   define DBL_MANT_DIG   __DBL_MANT_DIG__
#endif
#ifndef __DBL_DIG__
/** Number of decimal digits of precision in a double */
#   define __DBL_DIG__   (15)
/** Number of decimal digits of precision in a double */
#   define DBL_DIG   (15)
#else
/** Number of decimal digits of precision in a double */
#   define DBL_DIG   __DBL_DIG__
#endif
#ifndef __DBL_DECIMAL_DIG__
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define __DBL_DECIMAL_DIG__   (17)
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define DBL_DECIMAL_DIG   (17)
#else
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define DBL_DECIMAL_DIG   __DBL_DECIMAL_DIG__
#endif
#ifndef DBL_MANH_SIZE
#   define DBL_MANH_SIZE   (20)
#endif
#ifndef DBL_MANL_SIZE
#   define DBL_MANL_SIZE   (32)
#endif
#ifndef __DBL_EPSILON__
/** Difference between 1.0 and the minimum double greater than 1.0 */
#   define __DBL_EPSILON__   (2.220446049250313080847263336181640625E-16)
/** Difference between 1.0 and the minimum double greater than 1.0 */
#   define DBL_EPSILON   __DBL_EPSILON__
#else
/** Difference between 1.0 and the minimum double greater than 1.0 */
#   define DBL_EPSILON   __DBL_EPSILON__
#endif
#ifndef __DBL_MIN_EXP__
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised double */
#   define __DBL_MIN_EXP__   (-1021)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised double */
#   define DBL_MIN_EXP   (-1021)
#else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised double */
#   define DBL_MIN_EXP   __DBL_MIN_EXP__
#endif
/** Alias for DBL_MIN_EXP */
#define DMINEXP   DBL_MIN_EXP
#ifndef __DBL_MIN__
/** Minimum normalised double */
#   define __DBL_MIN__   (2.22507385850720138309023271733240406E-308)
/** Minimum normalised double */
#   define DBL_MIN   __DBL_MIN__
#else
/** Minimum normalised double */
#   define DBL_MIN   __DBL_MIN__
#endif
/** Alias for DBL_MIN */
#define MINDOUBLE   DBL_MIN
#ifndef __DBL_MIN_10_EXP__
/** Minimum int x such that 10**x is a normalised double */
#   define __DBL_MIN_10_EXP__   (-307)
/** Minimum int x such that 10**x is a normalised double */
#   define DBL_MIN_10_EXP   (-307)
#else
/** Minimum int x such that 10**x is a normalised double */
#   define DBL_MIN_10_EXP   __DBL_MIN_10_EXP__
#endif
#ifndef __DBL_DENORM_MIN__
/** Minimal denormal double value */
#   define __DBL_DENORM_MIN__   (4.94065645841246544176568792868221372E-324)
/** Minimal denormal double value */
#   define DBL_DENORM_MIN   __DBL_DENORM_MIN__
#else
/** Minimal denormal double value */
#   define DBL_DENORM_MIN   __DBL_DENORM_MIN__
#endif
#ifndef DBL_TRUE_MIN
/** Minimal denormal double value */
#   define DBL_TRUE_MIN   DBL_DENORM_MIN
#endif
#ifndef DBL_SUBNORMAL_MIN
/** Minimal denormal double value */
#   define DBL_SUBNORMAL_MIN   DBL_DENORM_MIN
#endif
#ifndef __DBL_MAX_EXP__
/** Maximum int x such that FLT_RADIX**(x-1) is a representable double */
#   define __DBL_MAX_EXP__   (1024)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable double */
#   define DBL_MAX_EXP   (1024)
#else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable double */
#   define DBL_MAX_EXP   __DBL_MAX_EXP__
#endif
/** Alias for DBL_MAX_EXP */
#define DMAXEXP   DBL_MAX_EXP
#ifndef __DBL_MAX__
/** The maximum representable finite double */
#   define __DBL_MAX__   (1.79769313486231570814527423731704357E+308)
/** The maximum representable finite double */
#   define DBL_MAX   __DBL_MAX__
#else
/** The maximum representable finite double */
#   define DBL_MAX   __DBL_MAX__
#endif
/** Alias for DBL_MAX */
#define MAXDOUBLE   DBL_MAX
#ifndef __DBL_MAX_10_EXP__
/** Maximum int x such that 10**x is a representable double */
#   define __DBL_MAX_10_EXP__   (308)
/** Maximum int x such that 10**x is a representable double */
#   define DBL_MAX_10_EXP   (308)
#else
/** Maximum int x such that 10**x is a representable double */
#   define DBL_MAX_10_EXP   __DBL_MAX_10_EXP__
#endif
#define DBL_MAX_10_EXP_LOG   8
#define DBL_MAX_10   1.0E+308
#define DBL_LARGE   1.0E+307
/** Added to exponent */
#define IEEE754_DOUBLE_BIAS   0x3ff
#define EXCESSD   1022
#define HIDDEND   0x100000

/** @} */  // }


/** @defgroup Float32_Properties Macros providing special values and properties concerning 32-bit floats (`float32`)
@{ */  // (FB){

#ifndef __FLT32_RADIX__
/** Radix of exponent representation */
#   define __FLT32_RADIX__   FLT_RADIX
/** Radix of exponent representation */
#   define FLT32_RADIX   FLT_RADIX
#else
/** Radix of exponent representation */
#   define FLT32_RADIX   __FLT32_RADIX__
#endif
#ifndef _FLT32_RADIX
/** Radix of exponent representation */
#   define _FLT32_RADIX   FLT32_RADIX
#endif
#ifndef __FLT32_HAS_DENORM__
/** Float32 denormal values are supported */
#   define __FLT32_HAS_DENORM__   (1)
/** Float32 denormal values are supported */
#   define FLT32_HAS_DENORM   (1)
#else
/** Float32 denormal values are supported */
#   define FLT32_HAS_DENORM   __FLT32_HAS_DENORM__
#endif
#ifndef __FLT32_HAS_INFINITY__
/** Float32 infinity is supported */
#   define __FLT32_HAS_INFINITY__   (1)
/** Float32 infinity is supported */
#   define FLT32_HAS_INFINITY   (1)
#else
/** Float32 infinity is supported */
#   define FLT32_HAS_INFINITY   __FLT32_HAS_INFINITY__
#endif
#ifndef __FLT32_HAS_QUIET_NAN__
/** Float32 quiet NAN (QNAN) is supported */
#   define __FLT32_HAS_QUIET_NAN__   (1)
/** Float32 quiet NAN (QNAN) is supported */
#   define FLT32_HAS_QUIET_NAN   (1)
#else
/** Float32 quiet NAN (QNAN) is supported */
#   define FLT32_HAS_QUIET_NAN   __FLT32_HAS_QUIET_NAN__
#endif
#ifndef __FLT32_MANT_DIG__
/** Number of base-FLT_RADIX digits in the significand of a float32 */
#   define __FLT32_MANT_DIG__   (24)
/** Number of base-FLT_RADIX digits in the significand of a float32 */
#   define FLT32_MANT_DIG   (24)
#else
/** Number of base-FLT_RADIX digits in the significand of a float32 */
#   define FLT32_MANT_DIG   __FLT32_MANT_DIG__
#endif
#ifndef __FLT32_DIG__
/** Number of decimal digits of precision in a float32 */
#   define __FLT32_DIG__   (6)
/** Number of decimal digits of precision in a float32 */
#   define FLT32_DIG   (6)
#else
/** Number of decimal digits of precision in a float32 */
#   define FLT32_DIG   __FLT32_DIG__
#endif
#ifndef __FLT32_DECIMAL_DIG__
/** Maximum significant figures */
#   define __FLT32_DECIMAL_DIG__   9
#endif
#ifndef FLT32_DECIMAL_DIG
/** Maximum significant figures */
#   define FLT32_DECIMAL_DIG   __FLT32_DECIMAL_DIG__
#endif
#ifndef __FLT32_EPSILON__
/** Difference between 1.0 and the minimum float32 greater than 1.0 */
#   define __FLT32_EPSILON__   (1.19209289550781250000000000000000000E-7F32)
/** Difference between 1.0 and the minimum float32 greater than 1.0 */
#   define FLT32_EPSILON   __FLT32_EPSILON__
#else
/** Difference between 1.0 and the minimum float32 greater than 1.0 */
#   define FLT32_EPSILON   __FLT32_EPSILON__
#endif
#ifndef __FLT32_MIN_EXP__
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float32 */
#   define __FLT32_MIN_EXP__   (-125)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float32 */
#   define FLT32_MIN_EXP   (-125)
#else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float32 */
#   define FLT32_MIN_EXP   __FLT32_MIN_EXP__
#endif
#ifndef __FLT32_MIN__
/** Minimum normalised float32 */
#   define __FLT32_MIN__   (1.17549435082228750796873653722224568E-38F32)
/** Minimum normalised float32 */
#   define FLT32_MIN   __FLT32_MIN__
#else
/** Minimum normalised float32 */
#   define FLT32_MIN   __FLT32_MIN__
#endif
#ifndef __FLT32_MIN_10_EXP__
/** Minimum int x such that 10**x is a normalised float32 */
#   define __FLT32_MIN_10_EXP__   (-37)
/** Minimum int x such that 10**x is a normalised float32 */
#   define FLT32_MIN_10_EXP   (-37)
#else
/** Minimum int x such that 10**x is a normalised float32 */
#   define FLT32_MIN_10_EXP   __FLT32_MIN_10_EXP__
#endif
#ifndef __FLT32_DENORM_MIN__
/** Minimal denormal float32 value */
#   define __FLT32_DENORM_MIN__   (1.40129846432481707092372958328991613E-45F32)
/** Minimal denormal float32 value */
#   define FLT32_DENORM_MIN   __FLT32_DENORM_MIN__
#else
/** Minimal denormal float32 value */
#   define FLT32_DENORM_MIN   __FLT32_DENORM_MIN__
#endif
#ifndef FLT32_TRUE_MIN
/** Minimal denormal float32 value */
#   define FLT32_TRUE_MIN   FLT32_DENORM_MIN
#endif
#ifndef FLT32_SUBNORMAL_MIN
/** Minimal denormal float32 value */
#   define FLT32_SUBNORMAL_MIN   FLT32_DENORM_MIN
#endif
#ifndef __FLT32_MAX_EXP__
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float32 */
#   define __FLT32_MAX_EXP__   (128)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float32 */
#   define FLT32_MAX_EXP   (128)
#else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float32 */
#   define FLT32_MAX_EXP   __FLT32_MAX_EXP__
#endif
#ifndef __FLT32_MAX__
/** The maximum representable finite float32 */
#   define __FLT32_MAX__   (3.40282346638528859811704183484516925E+38F32)
/** The maximum representable finite float32 */
#   define FLT32_MAX   __FLT32_MAX__
#else
/** The maximum representable finite float32 */
#   define FLT32_MAX   __FLT32_MAX__
#endif
#ifndef __FLT32_MAX_10_EXP__
/** Maximum int x such that 10**x is a representable float32 */
#   define __FLT32_MAX_10_EXP__   (38)
/** Maximum int x such that 10**x is a representable float32 */
#   define FLT32_MAX_10_EXP   (38)
#else
/** Maximum int x such that 10**x is a representable float32 */
#   define FLT32_MAX_10_EXP   __FLT32_MAX_10_EXP__
#endif
#define FLT32_MAX_10   1.0E+38F

/** @} */  // }


/** @defgroup Float64_Properties Macros providing special values and properties concerning 64-bit floats (`float64`)
@{ */  // (FB){

#ifndef __FLT64_RADIX__
/** Radix of exponent representation */
#   define __FLT64_RADIX__   FLT_RADIX
/** Radix of exponent representation */
#   define FLT64_RADIX   FLT_RADIX
#else
/** Radix of exponent representation */
#   define FLT64_RADIX   __FLT64_RADIX__
#endif
#ifndef _FLT64_RADIX
/** Radix of exponent representation */
#   define _FLT64_RADIX   FLT64_RADIX
#endif
#ifndef __FLT64_HAS_DENORM__
/** Float64 denormal values are supported */
#   define __FLT64_HAS_DENORM__   (1)
/** Float64 denormal values are supported */
#   define FLT64_HAS_DENORM   (1)
#else
/** Float64 denormal values are supported */
#   define FLT64_HAS_DENORM   __FLT64_HAS_DENORM__
#endif
#ifndef __FLT64_HAS_INFINITY__
/** Float64 infinity is supported */
#   define __FLT64_HAS_INFINITY__   (1)
/** Float64 infinity is supported */
#   define FLT64_HAS_INFINITY   (1)
#else
/** Float64 infinity is supported */
#   define FLT64_HAS_INFINITY   __FLT64_HAS_INFINITY__
#endif
#ifndef __FLT64_HAS_QUIET_NAN__
/** Float64 quiet NAN (QNAN) is supported */
#   define __FLT64_HAS_QUIET_NAN__   (1)
/** Float64 quiet NAN (QNAN) is supported */
#   define FLT64_HAS_QUIET_NAN   (1)
#else
/** Float64 quiet NAN (QNAN) is supported */
#   define FLT64_HAS_QUIET_NAN   __FLT64_HAS_QUIET_NAN__
#endif
#ifndef __FLT64_MANT_DIG__
/** Number of base-FLT_RADIX digits in the significand of a float64 */
#   define __FLT64_MANT_DIG__   (53)
/** Number of base-FLT_RADIX digits in the significand of a float64 */
#   define FLT64_MANT_DIG   (53)
#else
/** Number of base-FLT_RADIX digits in the significand of a float64 */
#   define FLT64_MANT_DIG   __FLT64_MANT_DIG__
#endif
#ifndef __FLT64_DIG__
/** Number of decimal digits of precision in a float64 */
#   define __FLT64_DIG__   (15)
/** Number of decimal digits of precision in a float64 */
#   define FLT64_DIG   (15)
#else
/** Number of decimal digits of precision in a float64 */
#   define FLT64_DIG   __FLT64_DIG__
#endif
#ifndef __FLT64_DECIMAL_DIG__
/** Maximum significant figures */
#   define __FLT64_DECIMAL_DIG__   17
#endif
#ifndef FLT64_DECIMAL_DIG
/** Maximum significant figures */
#   define FLT64_DECIMAL_DIG   __FLT64_DECIMAL_DIG__
#endif
#ifndef __FLT64_EPSILON__
/** Difference between 1.0 and the minimum float64 greater than 1.0 */
#   define __FLT64_EPSILON__   (2.22044604925031308084726333618164062E-16F64)
/** Difference between 1.0 and the minimum float64 greater than 1.0 */
#   define FLT64_EPSILON   __FLT64_EPSILON__
#else
/** Difference between 1.0 and the minimum float64 greater than 1.0 */
#   define FLT64_EPSILON   __FLT64_EPSILON__
#endif
#ifndef __FLT64_MIN_EXP__
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float64 */
#   define __FLT64_MIN_EXP__   (-1021)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float64 */
#   define FLT64_MIN_EXP   (-1021)
#else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float64 */
#   define FLT64_MIN_EXP   __FLT64_MIN_EXP__
#endif
#ifndef __FLT64_MIN__
/** Minimum normalised float64 */
#   define __FLT64_MIN__   (2.22507385850720138309023271733240406E-308F64)
/** Minimum normalised float64 */
#   define FLT64_MIN   __FLT64_MIN__
#else
/** Minimum normalised float64 */
#   define FLT64_MIN   __FLT64_MIN__
#endif
#ifndef __FLT64_MIN_10_EXP__
/** Minimum int x such that 10**x is a normalised float64 */
#   define __FLT64_MIN_10_EXP__   (-307)
/** Minimum int x such that 10**x is a normalised float64 */
#   define FLT64_MIN_10_EXP   (-307)
#else
/** Minimum int x such that 10**x is a normalised float64 */
#   define FLT64_MIN_10_EXP   __FLT64_MIN_10_EXP__
#endif
#ifndef __FLT64_DENORM_MIN__
/** Minimal denormal float64 value */
#   define __FLT64_DENORM_MIN__   (4.94065645841246544176568792868221372E-324F64)
/** Minimal denormal float64 value */
#   define FLT64_DENORM_MIN   __FLT64_DENORM_MIN__
#else
/** Minimal denormal float64 value */
#   define FLT64_DENORM_MIN   __FLT64_DENORM_MIN__
#endif
#ifndef FLT64_TRUE_MIN
/** Minimal denormal float64 value */
#   define FLT64_TRUE_MIN   FLT64_DENORM_MIN
#endif
#ifndef FLT64_SUBNORMAL_MIN
/** Minimal denormal float64 value */
#   define FLT64_SUBNORMAL_MIN   FLT64_DENORM_MIN
#endif
#ifndef __FLT64_MAX_EXP__
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float64 */
#   define __FLT64_MAX_EXP__   (1024)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float64 */
#   define FLT64_MAX_EXP   (1024)
#else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float64 */
#   define FLT64_MAX_EXP   __FLT64_MAX_EXP__
#endif
#ifndef __FLT64_MAX__
/** The maximum representable finite float64 */
#   define __FLT64_MAX__   (1.79769313486231570814527423731704357E+308F64)
/** The maximum representable finite float64 */
#   define FLT64_MAX   __FLT64_MAX__
#else
/** The maximum representable finite float64 */
#   define FLT64_MAX   __FLT64_MAX__
#endif
#ifndef __FLT64_MAX_10_EXP__
/** Maximum int x such that 10**x is a representable float64 */
#   define __FLT64_MAX_10_EXP__   (308)
/** Maximum int x such that 10**x is a representable float64 */
#   define FLT64_MAX_10_EXP   (308)
#else
/** Maximum int x such that 10**x is a representable float64 */
#   define FLT64_MAX_10_EXP   __FLT64_MAX_10_EXP__
#endif
#define FLT64_MAX_10   1.0E+308

/** @} */  // }


/** @defgroup Long_Double_Properties Macros providing special values and properties concerning `long doubles`
@{ */  // (FB){

#ifdef SUPPORTS_LONG_DOUBLE
#   ifndef __LDBL_RADIX__
/** Radix of exponent representation */
#      define __LDBL_RADIX__   FLT_RADIX
/** Radix of exponent representation */
#      define LDBL_RADIX   FLT_RADIX
#   else
/** Radix of exponent representation */
#      define LDBL_RADIX   __LDBL_RADIX__
#   endif
#   ifndef _LDBL_RADIX
/** Radix of exponent representation */
#      define _LDBL_RADIX   LDBL_RADIX
#   endif
#   ifndef __LDBL_HAS_DENORM__
/** `long double` denormal values are supported */
#      define __LDBL_HAS_DENORM__   (1)
/** `long double` denormal values are supported */
#      define LDBL_HAS_DENORM   (1)
#   else
/** `long double` denormal values are supported */
#      define LDBL_HAS_DENORM   __LDBL_HAS_DENORM__
#   endif
#   ifndef __LDBL_HAS_INFINITY__
/** `long double` infinity is supported */
#      define __LDBL_HAS_INFINITY__   (1)
/** `long double` infinity is supported */
#      define LDBL_HAS_INFINITY   (1)
#   else
/** `long double` infinity is supported */
#      define LDBL_HAS_INFINITY   __LDBL_HAS_INFINITY__
#   endif
#   ifndef __LDBL_HAS_QUIET_NAN__
/** `long double` quiet NAN (QNAN) is supported */
#      define __LDBL_HAS_QUIET_NAN__   (1)
/** `long double` quiet NAN (QNAN) is supported */
#      define LDBL_HAS_QUIET_NAN   (1)
#   else
/** `long double` quiet NAN (QNAN) is supported */
#      define LDBL_HAS_QUIET_NAN   __LDBL_HAS_QUIET_NAN__
#   endif
#   ifndef __LDBL_MANT_DIG__
#      if IS_SOFTFP
/** Number of base-FLT_RADIX digits in the significand of a long double */
#         define __LDBL_MANT_DIG__   (53)
#      elif LDBL_EQ_FLOAT128
/** Number of base-FLT_RADIX digits in the significand of a long double */
#         define __LDBL_MANT_DIG__   (113)
#      else  // 80 & 96 bit
/** Number of base-FLT_RADIX digits in the significand of a long double */
#         define __LDBL_MANT_DIG__   (64)
#      endif
#   endif
#   ifndef LDBL_MANT_DIG
/** Number of base-FLT_RADIX digits in the significand of a long double */
#      define LDBL_MANT_DIG   __LDBL_MANT_DIG__
#   endif
#   ifndef __LDBL_DIG__
#      if IS_SOFTFP
/** Number of decimal digits of precision in a long double */
#         define __LDBL_DIG__   (15)
#      elif LDBL_EQ_FLOAT128
/** Number of decimal digits of precision in a long double */
#         define __LDBL_DIG__   (33)
#      else  // 80 & 96 bit
/** Number of decimal digits of precision in a long double */
#         define __LDBL_DIG__   (18)
#      endif
#   endif
#   ifndef LDBL_DIG
/** Number of decimal digits of precision in a long double */
#      define LDBL_DIG   __LDBL_DIG__
#   endif
#   ifndef __LDBL_DECIMAL_DIG__
#      if IS_SOFTFP
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#         define __LDBL_DECIMAL_DIG__   (17)
#      elif LDBL_EQ_FLOAT128
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#         define __LDBL_DECIMAL_DIG__   (33)
#      else  // 80 & 96 bit
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#         define __LDBL_DECIMAL_DIG__   (21)
#      endif
#   endif
#   ifndef LDBL_DECIMAL_DIG
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define LDBL_DECIMAL_DIG   __LDBL_DECIMAL_DIG__
#   endif
#   ifndef __LDBL_EPSILON__
#      if IS_SOFTFP
/** Difference between 1.0 and the minimum long double greater than 1.0 */
#         define __LDBL_EPSILON__   (2.22044604925031308084726333618164062E-16L)
#      elif LDBL_EQ_FLOAT128
/** Difference between 1.0 and the minimum long double greater than 1.0 */
#         define __LDBL_EPSILON__   (1.92592994438723585305597794258492732E-34L)
#      else  // 80 & 96 bit
/** Difference between 1.0 and the minimum long double greater than 1.0 */
#         define __LDBL_EPSILON__   (1.08420217248550443400745280086994171E-19L)
#      endif
#   endif
#   ifndef LDBL_EPSILON
/** Difference between 1.0 and the minimum long double greater than 1.0 */
#      define LDBL_EPSILON   __LDBL_EPSILON__
#   endif
#   ifndef __LDBL_MIN_EXP__
#      if IS_SOFTFP
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised long double */
#         define __LDBL_MIN_EXP__   (-1021)
#      else  // 80, 96, & 128 bit
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised long double */
#         define __LDBL_MIN_EXP__   (-16381)
#      endif
#   endif
#   ifndef LDBL_MIN_EXP
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised long double */
#      define LDBL_MIN_EXP   __LDBL_MIN_EXP__
#   endif
/** Alias for LDBL_MIN_EXP */
#   define LDMINEXP   LDBL_MIN_EXP
#   ifndef __LDBL_MIN__
#      if IS_SOFTFP
/** Minimum normalised long double */
#         define __LDBL_MIN__   (2.22507385850720138309023271733240406E-308L)
#      else  // 80, 96, & 128 bit
/** Minimum normalised long double */
#         define __LDBL_MIN__   (3.36210314311209350626267781732175260E-4932L)
#      endif
#   endif
#   ifndef LDBL_MIN
/** Minimum normalised long double */
#      define LDBL_MIN   __LDBL_MIN__
#   endif
/** Alias for LDBL_MIN */
#   define MINLONGDOUBLE   LDBL_MIN
#   ifndef __LDBL_MIN_10_EXP__
#      if IS_SOFTFP
/** Minimum int x such that 10**x is a normalised long double */
#         define __LDBL_MIN_10_EXP__   (-307)
#      else  // 80, 96, & 128 bit
/** Minimum int x such that 10**x is a normalised long double */
#         define __LDBL_MIN_10_EXP__   (-4931)
#      endif
#   endif
#   ifndef LDBL_MIN_10_EXP
/** Minimum int x such that 10**x is a normalised long double */
#      define LDBL_MIN_10_EXP   __LDBL_MIN_10_EXP__
#   endif
#   ifndef __LDBL_DENORM_MIN__
#      if IS_SOFTFP
/** Minimal denormal double value */
#         define __LDBL_DENORM_MIN__   (4.94065645841246544176568792868221372E-324L)
#      elif LDBL_EQ_FLOAT128
/** Minimal denormal double value */
#         define __LDBL_DENORM_MIN__   (6.47517511943802511092443895822764655E-4966L)
#      else  // 80 & 96 bit
/** Minimal denormal double value */
#         define __LDBL_DENORM_MIN__   (3.64519953188247460252840593361941982E-4951L)
#      endif
#   endif
#   ifndef LDBL_DENORM_MIN
/** Minimal denormal double value */
#      define LDBL_DENORM_MIN   __LDBL_DENORM_MIN__
#   endif
#   ifndef LDBL_TRUE_MIN
/** Minimal denormal double value */
#      define LDBL_TRUE_MIN   __LDBL_DENORM_MIN__
#   endif
#   ifndef LDBL_SUBNORMAL_MIN
/** Minimal denormal double value */
#      define LDBL_SUBNORMAL_MIN   __LDBL_DENORM_MIN__
#   endif
#   ifndef __LDBL_MAX_EXP__
#      if IS_SOFTFP
/** Maximum int x such that FLT_RADIX**(x-1) is a representable long double */
#         define __LDBL_MAX_EXP__   (1024)
#      else  // 80, 96, & 128 bit
/** Maximum int x such that FLT_RADIX**(x-1) is a representable long double */
#         define __LDBL_MAX_EXP__   (16384)
#      endif
#   endif
#   ifndef LDBL_MAX_EXP
/** Maximum int x such that FLT_RADIX**(x-1) is a representable long double */
#      define LDBL_MAX_EXP   __LDBL_MAX_EXP__
#   endif
/** Alias for LDBL_MAX_EXP */
#   define LDMAXEXP   LDBL_MAX_EXP
#   if (SUPPORTS_LONG_DOUBLE && (LDBL_MAX_EXP == 16384))
#      define LDBL_MAX_10_EXP_LOG   12
#      define FPIOCONST_POW10_ARRAY_SIZE   15
#   elif (SUPPORTS_LONG_DOUBLE && (LDBL_MAX_EXP == 1024))
#      define LDBL_MAX_10_EXP_LOG   8
#      define FPIOCONST_POW10_ARRAY_SIZE   11
#   else
#      error   "Unrecognized value of `__LDBL_MAX_EXP__`!"
#   endif
#   ifndef __LDBL_MAX__
#      if IS_SOFTFP
/** The maximum representable finite long double */
#         define __LDBL_MAX__   (1.79769313486231570814527423731704357E+308L)
#      else  // 80, 96, & 128 bit
/** The maximum representable finite long double */
#         define __LDBL_MAX__   (1.18973149535723176502126385303097021E+4932L)
#      endif
#   endif
#   ifndef LDBL_MAX
/** The maximum representable finite long double */
#      define LDBL_MAX   __LDBL_MAX__
#   endif
/** Alias for LDBL_MAX */
#   define MAXLONGDOUBLE   LDBL_MAX
#   ifndef __LDBL_MAX_10_EXP__
#      if IS_SOFTFP
/** Maximum int x such that 10**x is a representable long double */
#         define __LDBL_MAX_10_EXP__   (308)
#         define LDBL_MAX_10   1.0E+308L
#         define LDBL_LARGE   1.0E+307L
#      else  // 80, 96, & 128 bit
/** Maximum int x such that 10**x is a representable long double */
#         define __LDBL_MAX_10_EXP__   (4932)
#         define LDBL_MAX_10   1.0E+4932L
#         define LDBL_LARGE   1.0E+4931L
#      endif
#   endif
#   ifndef LDBL_MAX_10_EXP
/** Maximum int x such that 10**x is a representable long double */
#      define LDBL_MAX_10_EXP   __LDBL_MAX_10_EXP__
#   endif
/** Added to exponent */
#   define IEEE854_LONG_DOUBLE_BIAS   0x3fff
#   if ((LDBL_MANT_DIG == 53) && (LDBL_MAX_EXP == 1024))
#      define SUPPORTS_LONG_DOUBLE_64   (1)
#      define SUPPORTS_LONG_DOUBLE_X87   (0)
#      define SUPPORTS_LONG_DOUBLE_128   (0)
#      define SUPPORTS_IBM_LONG_DOUBLE   (0)
#      define LD_B1B_DIG   2
#      define LD_B1B_MAX   9007199, 254740991
#      define KMAX   128
#      if IS_NOT_LINTER
_Static_assert((LDBL_EQ_DBL), "`long double` is not equivalent to `double`!");
_Static_assert((SIZEOF_LONG_DOUBLE == 8), "`long double` is not of the correct size!");
#      endif
#   elif ((LDBL_MANT_DIG == 64) && (LDBL_MAX_EXP == 16384))
#      define SUPPORTS_LONG_DOUBLE_64   (0)
#      define SUPPORTS_LONG_DOUBLE_X87   (1)
#      define SUPPORTS_LONG_DOUBLE_128   (0)
#      define SUPPORTS_IBM_LONG_DOUBLE   (0)
#      define LD_B1B_DIG   3
#      define LD_B1B_MAX   18, 446744073, 709551615
#      define KMAX 2048
#      if IS_NOT_LINTER
_Static_assert((IS_LDBL_X87 || FAKE_128_LDBL), "`long double` is not equivalent to `XFtype`!");
_Static_assert((((SIZEOF_LONG_DOUBLE == 10) || (SIZEOF_LONG_DOUBLE == 12)) || (FAKE_128_LDBL && (SIZEOF_LONG_DOUBLE == 16))), "`long double` is not of the correct size!");
#      endif
#   elif ((LDBL_MANT_DIG == 113) && (LDBL_MAX_EXP == 16384))
#      define SUPPORTS_LONG_DOUBLE_64   (0)
#      define SUPPORTS_LONG_DOUBLE_X87   (0)
#      define SUPPORTS_LONG_DOUBLE_128   (1)
#      define SUPPORTS_IBM_LONG_DOUBLE   (1)
#      define LD_B1B_DIG   4
#      define LD_B1B_MAX   10384593, 717069655, 257060992, 658440191
#      define KMAX   2048
#      if IS_NOT_LINTER
_Static_assert((LDBL_EQ_FLOAT128), "`long double` is not 128-bits!");
_Static_assert((SIZEOF_LONG_DOUBLE == 16), "`long double` is not of the correct size!");
#      endif
#   else
#      error   "Unsupported long double representation!"
#   endif
#   define FLOAT_MASK   (KMAX - 1)
#   define HIDDEND_LL   (0x10000000000000LL)
#endif

/** @} */  // }


/** @defgroup Float128_Properties Macros providing special values and properties concerning 128-bit floats (`float128`)
@{ */  // (FB){

#ifdef SUPPORTS_FLOAT128
#   ifndef __FLT128_RADIX__
/** Radix of exponent representation */
#      define __FLT128_RADIX__   FLT_RADIX
/** Radix of exponent representation */
#      define FLT128_RADIX   FLT_RADIX
#   else
/** Radix of exponent representation */
#      define FLT128_RADIX   __FLT128_RADIX__
#   endif
#   ifndef _FLT128_RADIX
/** Radix of exponent representation */
#      define _FLT128_RADIX   FLT128_RADIX
#   endif
#   ifndef __FLT128_HAS_DENORM__
/** Float128 denormal values are supported */
#      define __FLT128_HAS_DENORM__   (1)
/** Float128 denormal values are supported */
#      define FLT128_HAS_DENORM   (1)
#   else
/** Float128 denormal values are supported */
#      define FLT128_HAS_DENORM   __FLT128_HAS_DENORM__
#   endif
#   ifndef __FLT128_HAS_INFINITY__
/** Float128 infinity is supported */
#      define __FLT128_HAS_INFINITY__   (1)
/** Float128 infinity is supported */
#      define FLT128_HAS_INFINITY   (1)
#   else
/** Float128 infinity is supported */
#      define FLT128_HAS_INFINITY   __FLT128_HAS_INFINITY__
#   endif
#   ifndef __FLT128_HAS_QUIET_NAN__
/** Float128 quiet NAN (QNAN) is supported */
#      define __FLT128_HAS_QUIET_NAN__   (1)
/** Float128 quiet NAN (QNAN) is supported */
#      define FLT128_HAS_QUIET_NAN   (1)
#   else
/** Float128 quiet NAN (QNAN) is supported */
#      define FLT128_HAS_QUIET_NAN   __FLT128_HAS_QUIET_NAN__
#   endif
#   ifndef __FLT128_MANT_DIG__
/** Number of base-FLT_RADIX digits in the significand of a float128 */
#      define __FLT128_MANT_DIG__   (113)
/** Number of base-FLT_RADIX digits in the significand of a float128 */
#      define FLT128_MANT_DIG   (113)
#   else
/** Number of base-FLT_RADIX digits in the significand of a float128 */
#      define FLT128_MANT_DIG   __FLT128_MANT_DIG__
#   endif
#   ifndef __FLT128_DIG__
/** Number of decimal digits of precision in a float128 */
#      define __FLT128_DIG__   (33)
/** Number of decimal digits of precision in a float128 */
#      define FLT128_DIG   (33)
#   else
/** Number of decimal digits of precision in a float128 */
#      define FLT128_DIG   __FLT128_DIG__
#   endif
#   ifndef __FLT128_DECIMAL_DIG__
/** Maximum significant figures */
#      define __FLT128_DECIMAL_DIG__   36
#   endif
#   ifndef FLT128_DECIMAL_DIG
/** Maximum significant figures */
#      define FLT128_DECIMAL_DIG   __FLT128_DECIMAL_DIG__
#   endif
#   ifndef __FLT128_EPSILON__
/** Difference between 1.0 and the minimum float128 greater than 1.0 */
#      define __FLT128_EPSILON__   (1.92592994438723585305597794258492732E-34F128)
/** Difference between 1.0 and the minimum float128 greater than 1.0 */
#      define FLT128_EPSILON   __FLT128_EPSILON__
#   else
/** Difference between 1.0 and the minimum float128 greater than 1.0 */
#      define FLT128_EPSILON   __FLT128_EPSILON__
#   endif
#   ifndef __FLT128_MIN_EXP__
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float128 */
#      define __FLT128_MIN_EXP__   (-16381)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float128 */
#      define FLT128_MIN_EXP   (-16381)
#   else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float128 */
#      define FLT128_MIN_EXP   __FLT128_MIN_EXP__
#   endif
#   ifndef __FLT128_MIN__
/** Minimum normalised float128 */
#      define __FLT128_MIN__   (3.36210314311209350626267781732175260E-4932F128)
/** Minimum normalised float128 */
#      define FLT128_MIN   __FLT128_MIN__
#   else
/** Minimum normalised float128 */
#      define FLT128_MIN   __FLT128_MIN__
#   endif
#   ifndef __FLT128_MIN_10_EXP__
/** Minimum int x such that 10**x is a normalised float128 */
#      define __FLT128_MIN_10_EXP__   (-4931)
/** Minimum int x such that 10**x is a normalised float128 */
#      define FLT128_MIN_10_EXP   (-4931)
#   else
/** Minimum int x such that 10**x is a normalised float128 */
#      define FLT128_MIN_10_EXP   __FLT128_MIN_10_EXP__
#   endif
#   ifndef __FLT128_DENORM_MIN__
/** Minimal denormal float128 value */
#      define __FLT128_DENORM_MIN__   (6.47517511943802511092443895822764655E-4966F128)
/** Minimal denormal float128 value */
#      define FLT128_DENORM_MIN   __FLT128_DENORM_MIN__
#   else
/** Minimal denormal float128 value */
#      define FLT128_DENORM_MIN   __FLT128_DENORM_MIN__
#   endif
#   ifndef FLT128_TRUE_MIN
/** Minimal denormal float128 value */
#      define FLT128_TRUE_MIN   FLT128_DENORM_MIN
#   endif
#   ifndef FLT128_SUBNORMAL_MIN
/** Minimal denormal float128 value */
#      define FLT128_SUBNORMAL_MIN   FLT128_DENORM_MIN
#   endif
#   ifndef __FLT128_MAX_EXP__
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float128 */
#      define __FLT128_MAX_EXP__   (16384)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float128 */
#      define FLT128_MAX_EXP   (16384)
#   else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float128 */
#      define FLT128_MAX_EXP   __FLT128_MAX_EXP__
#   endif
#   ifndef __FLT128_MAX__
/** The maximum representable finite float128 */
#      define __FLT128_MAX__   (1.18973149535723176508575932662800702E+4932F128)
/** The maximum representable finite float128 */
#      define FLT128_MAX   __FLT128_MAX__
#   else
/** The maximum representable finite float128 */
#      define FLT128_MAX   __FLT128_MAX__
#   endif
#   ifndef __FLT128_MAX_10_EXP__
/** Maximum int x such that 10**x is a representable float128 */
#      define __FLT128_MAX_10_EXP__   (4932)
/** Maximum int x such that 10**x is a representable float128 */
#      define FLT128_MAX_10_EXP   (4932)
#   else
/** Maximum int x such that 10**x is a representable float128 */
#      define FLT128_MAX_10_EXP   __FLT128_MAX_10_EXP__
#   endif
#   define FLT128_MAX_10   1.0E+4932F128
#endif

/** @} */  // }


/** @defgroup Float32x_Properties Macros providing special values and properties concerning `float32x`
@{ */  // (FB){

#ifndef __FLT32X_RADIX__
/** Radix of exponent representation */
#   define __FLT32X_RADIX__   FLT_RADIX
/** Radix of exponent representation */
#   define FLT32X_RADIX   FLT_RADIX
#else
/** Radix of exponent representation */
#   define FLT32X_RADIX   __FLT32X_RADIX__
#endif
#ifndef _FLT32X_RADIX
/** Radix of exponent representation */
#   define _FLT32X_RADIX   FLT32X_RADIX
#endif
#ifndef __FLT32X_HAS_DENORM__
/** Float32x denormal values are supported */
#   define __FLT32X_HAS_DENORM__   (1)
/** Float32x denormal values are supported */
#   define FLT32X_HAS_DENORM   (1)
#else
/** Float32x denormal values are supported */
#   define FLT32X_HAS_DENORM   __FLT32X_HAS_DENORM__
#endif
#ifndef __FLT32X_HAS_INFINITY__
/** Float32x infinity is supported */
#   define __FLT32X_HAS_INFINITY__   (1)
/** Float32x infinity is supported */
#   define FLT32X_HAS_INFINITY   (1)
#else
/** Float32x infinity is supported */
#   define FLT32X_HAS_INFINITY   __FLT32X_HAS_INFINITY__
#endif
#ifndef __FLT32X_HAS_QUIET_NAN__
/** Float32x quiet NAN (QNAN) is supported */
#   define __FLT32X_HAS_QUIET_NAN__   (1)
/** Float32x quiet NAN (QNAN) is supported */
#   define FLT32X_HAS_QUIET_NAN   (1)
#else
/** Float32x quiet NAN (QNAN) is supported */
#   define FLT32X_HAS_QUIET_NAN   __FLT32X_HAS_QUIET_NAN__
#endif
#ifndef __FLT32X_MANT_DIG__
/** Number of base-FLT_RADIX digits in the significand of a float32x */
#   define __FLT32X_MANT_DIG__   (53)
/** Number of base-FLT_RADIX digits in the significand of a float32x */
#   define FLT32X_MANT_DIG   (53)
#else
/** Number of base-FLT_RADIX digits in the significand of a float32x */
#   define FLT32X_MANT_DIG   __FLT32X_MANT_DIG__
#endif
#ifndef __FLT32X_DIG__
/** Number of decimal digits of precision in a float32x */
#   define __FLT32X_DIG__   (15)
/** Number of decimal digits of precision in a float32x */
#   define FLT32X_DIG   (15)
#else
/** Number of decimal digits of precision in a float32x */
#   define FLT32X_DIG   __FLT32X_DIG__
#endif
#ifndef __FLT32X_DECIMAL_DIG__
/** Maximum significant figures */
#   define __FLT32X_DECIMAL_DIG__   17
#endif
#ifndef FLT32X_DECIMAL_DIG
/** Maximum significant figures */
#   define FLT32X_DECIMAL_DIG   __FLT32X_DECIMAL_DIG__
#endif
#ifndef __FLT32X_EPSILON__
/** Difference between 1.0 and the minimum float32x greater than 1.0 */
#   define __FLT32X_EPSILON__   (2.22044604925031308084726333618164062E-16F32x)
/** Difference between 1.0 and the minimum float32x greater than 1.0 */
#   define FLT32X_EPSILON   __FLT32X_EPSILON__
#else
/** Difference between 1.0 and the minimum float32x greater than 1.0 */
#   define FLT32X_EPSILON   __FLT32X_EPSILON__
#endif
#ifndef __FLT32X_MIN_EXP__
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float32x */
#   define __FLT32X_MIN_EXP__   (-1021)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float32x */
#   define FLT32X_MIN_EXP   (-1021)
#else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float32x */
#   define FLT32X_MIN_EXP   __FLT32X_MIN_EXP__
#endif
#ifndef __FLT32X_MIN__
/** Minimum normalised float32x */
#   define __FLT32X_MIN__   (2.22507385850720138309023271733240406E-308F32x)
/** Minimum normalised float32x */
#   define FLT32X_MIN   __FLT32X_MIN__
#else
/** Minimum normalised float32x */
#   define FLT32X_MIN   __FLT32X_MIN__
#endif
#ifndef __FLT32X_MIN_10_EXP__
/** Minimum int x such that 10**x is a normalised float32x */
#   define __FLT32X_MIN_10_EXP__   (-307)
/** Minimum int x such that 10**x is a normalised float32x */
#   define FLT32X_MIN_10_EXP   (-307)
#else
/** Minimum int x such that 10**x is a normalised float32x */
#   define FLT32X_MIN_10_EXP   __FLT32X_MIN_10_EXP__
#endif
#ifndef __FLT32X_DENORM_MIN__
/** Minimal denormal float32x value */
#   define __FLT32X_DENORM_MIN__   (4.94065645841246544176568792868221372E-324F32x)
/** Minimal denormal float32x value */
#   define FLT32X_DENORM_MIN   __FLT32X_DENORM_MIN__
#else
/** Minimal denormal float32x value */
#   define FLT32X_DENORM_MIN   __FLT32X_DENORM_MIN__
#endif
#ifndef FLT32X_TRUE_MIN
/** Minimal denormal float32x value */
#   define FLT32X_TRUE_MIN   FLT32X_DENORM_MIN
#endif
#ifndef FLT32X_SUBNORMAL_MIN
/** Minimal denormal float32x value */
#   define FLT32X_SUBNORMAL_MIN   FLT32X_DENORM_MIN
#endif
#ifndef __FLT32X_MAX_EXP__
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float32x */
#   define __FLT32X_MAX_EXP__   (1024)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float32x */
#   define FLT32X_MAX_EXP   (1024)
#else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float32x */
#   define FLT32X_MAX_EXP   __FLT32X_MAX_EXP__
#endif
#ifndef __FLT32X_MAX__
/** The maximum representable finite float32x */
#   define __FLT32X_MAX__   (1.79769313486231570814527423731704357E+308F32x)
/** The maximum representable finite float32x */
#   define FLT32X_MAX   __FLT32X_MAX__
#else
/** The maximum representable finite float32x */
#   define FLT32X_MAX   __FLT32X_MAX__
#endif
#ifndef __FLT32X_MAX_10_EXP__
/** Maximum int x such that 10**x is a representable float32x */
#   define __FLT32X_MAX_10_EXP__   (308)
/** Maximum int x such that 10**x is a representable float32x */
#   define FLT32X_MAX_10_EXP   (308)
#else
/** Maximum int x such that 10**x is a representable float32x */
#   define FLT32X_MAX_10_EXP   __FLT32X_MAX_10_EXP__
#endif
#define FLT32X_MAX_10   1.0E+308F32X

/** @} */  // }


/** @defgroup Float64x_Properties Macros providing special values and properties concerning `float64x`
@{ */  // (FB){

#ifndef __FLT64X_RADIX__
/** Radix of exponent representation */
#   define __FLT64X_RADIX__   FLT_RADIX
/** Radix of exponent representation */
#   define FLT64X_RADIX   FLT_RADIX
#else
/** Radix of exponent representation */
#   define FLT64X_RADIX   __FLT64X_RADIX__
#endif
#ifndef _FLT64X_RADIX
/** Radix of exponent representation */
#   define _FLT64X_RADIX   FLT64X_RADIX
#endif
#ifndef __FLT64X_HAS_DENORM__
/** Float64x denormal values are supported */
#   define __FLT64X_HAS_DENORM__   (1)
/** Float64x denormal values are supported */
#   define FLT64X_HAS_DENORM   (1)
#else
/** Float64x denormal values are supported */
#   define FLT64X_HAS_DENORM   __FLT64X_HAS_DENORM__
#endif
#ifndef __FLT64X_HAS_INFINITY__
/** Float64x infinity is supported */
#   define __FLT64X_HAS_INFINITY__   (1)
/** Float64x infinity is supported */
#   define FLT64X_HAS_INFINITY   (1)
#else
/** Float64x infinity is supported */
#   define FLT64X_HAS_INFINITY   __FLT64X_HAS_INFINITY__
#endif
#ifndef __FLT64X_HAS_QUIET_NAN__
/** Float64x quiet NAN (QNAN) is supported */
#   define __FLT64X_HAS_QUIET_NAN__   (1)
/** Float64x quiet NAN (QNAN) is supported */
#   define FLT64X_HAS_QUIET_NAN   (1)
#else
/** Float64x quiet NAN (QNAN) is supported */
#   define FLT64X_HAS_QUIET_NAN   __FLT64X_HAS_QUIET_NAN__
#endif
#ifndef __FLT64X_MANT_DIG__
/** Number of base-FLT_RADIX digits in the significand of a float64x */
#   define __FLT64X_MANT_DIG__   (113)
/** Number of base-FLT_RADIX digits in the significand of a float64x */
#   define FLT64X_MANT_DIG   (113)
#else
/** Number of base-FLT_RADIX digits in the significand of a float64x */
#   define FLT64X_MANT_DIG   __FLT64X_MANT_DIG__
#endif
#ifndef __FLT64X_DIG__
/** Number of decimal digits of precision in a float64x */
#   define __FLT64X_DIG__   (33)
/** Number of decimal digits of precision in a float64x */
#   define FLT64X_DIG   (33)
#else
/** Number of decimal digits of precision in a float64x */
#   define FLT64X_DIG   __FLT64X_DIG__
#endif
#ifndef __FLT64X_DECIMAL_DIG__
/** Maximum significant figures */
#   define __FLT64X_DECIMAL_DIG__   36
#endif
#ifndef FLT64X_DECIMAL_DIG
/** Maximum significant figures */
#   define FLT64X_DECIMAL_DIG   __FLT64X_DECIMAL_DIG__
#endif
#ifndef __FLT64X_EPSILON__
/** Difference between 1.0 and the minimum float64x greater than 1.0 */
#   define __FLT64X_EPSILON__   (1.92592994438723585305597794258492732E-34F64x)
/** Difference between 1.0 and the minimum float64x greater than 1.0 */
#   define FLT64X_EPSILON   __FLT64X_EPSILON__
#else
/** Difference between 1.0 and the minimum float64x greater than 1.0 */
#   define FLT64X_EPSILON   __FLT64X_EPSILON__
#endif
#ifndef __FLT64X_MIN_EXP__
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float64x */
#   define __FLT64X_MIN_EXP__   (-16381)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float64x */
#   define FLT64X_MIN_EXP   (-16381)
#else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float64x */
#   define FLT64X_MIN_EXP   __FLT64X_MIN_EXP__
#endif
#ifndef __FLT64X_MIN__
/** Minimum normalised float64x */
#   define __FLT64X_MIN__   (3.36210314311209350626267781732175260E-4932F64x)
/** Minimum normalised float64x */
#   define FLT64X_MIN   __FLT64X_MIN__
#else
/** Minimum normalised float64x */
#   define FLT64X_MIN   __FLT64X_MIN__
#endif
#ifndef __FLT64X_MIN_10_EXP__
/** Minimum int x such that 10**x is a normalised float64x */
#   define __FLT64X_MIN_10_EXP__   (-4931)
/** Minimum int x such that 10**x is a normalised float64x */
#   define FLT64X_MIN_10_EXP   (-4931)
#else
/** Minimum int x such that 10**x is a normalised float64x */
#   define FLT64X_MIN_10_EXP   __FLT64X_MIN_10_EXP__
#endif
#ifndef __FLT64X_DENORM_MIN__
/** Minimal denormal float64x value */
#   define __FLT64X_DENORM_MIN__   (6.47517511943802511092443895822764655E-4966F64x)
/** Minimal denormal float64x value */
#   define FLT64X_DENORM_MIN   __FLT64X_DENORM_MIN__
#else
/** Minimal denormal float64x value */
#   define FLT64X_DENORM_MIN   __FLT64X_DENORM_MIN__
#endif
#ifndef FLT64X_TRUE_MIN
/** Minimal denormal float64x value */
#   define FLT64X_TRUE_MIN   FLT64X_DENORM_MIN
#endif
#ifndef FLT64X_SUBNORMAL_MIN
/** Minimal denormal float64x value */
#   define FLT64X_SUBNORMAL_MIN   FLT64X_DENORM_MIN
#endif
#ifndef __FLT64X_MAX_EXP__
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float64x */
#   define __FLT64X_MAX_EXP__   (16384)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float64x */
#   define FLT64X_MAX_EXP   (16384)
#else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float64x */
#   define FLT64X_MAX_EXP   __FLT64X_MAX_EXP__
#endif
#ifndef __FLT64X_MAX__
/** The maximum representable finite float64x */
#   define __FLT64X_MAX__   (1.18973149535723176508575932662800702E+4932F64x)
/** The maximum representable finite float64x */
#   define FLT64X_MAX   __FLT64X_MAX__
#else
/** The maximum representable finite float64x */
#   define FLT64X_MAX   __FLT64X_MAX__
#endif
#ifndef __FLT64X_MAX_10_EXP__
/** Maximum int x such that 10**x is a representable float64x */
#   define __FLT64X_MAX_10_EXP__   (4932)
/** Maximum int x such that 10**x is a representable float64x */
#   define FLT64X_MAX_10_EXP   (4932)
#else
/** Maximum int x such that 10**x is a representable float64x */
#   define FLT64X_MAX_10_EXP   __FLT64X_MAX_10_EXP__
#endif
#define FLT64X_MAX_10   1.0E+4932F64X

/** @} */  // }


/** @defgroup Decimal32_Properties Macros providing special values and properties concerning 32-bit decimal floats (`decimal32`)
@{ */  // (FB){

#if SUPPORTS_DECIMAL32
#   ifndef __DEC32_RADIX__
/** Radix of exponent representation */
#      define __DEC32_RADIX__   (10)
/** Radix of exponent representation */
#      define DEC32_RADIX   (10)
#   else
/** Radix of exponent representation */
#      define DEC32_RADIX   (10)
#   endif
#   ifndef _DEC32_RADIX
/** Radix of exponent representation */
#      define _DEC32_RADIX   (10)
#   endif
#   ifndef __DEC32_MANT_DIG__
/** Number of base-10 digits in the significand of a decimal32 */
#      define __DEC32_MANT_DIG__   (7)
/** Number of base-10 digits in the significand of a decimal32 */
#      define DEC32_MANT_DIG   (7)
#   else
/** Number of base-10 digits in the significand of a decimal32 */
#      define DEC32_MANT_DIG   __DEC32_MANT_DIG__
#   endif
#   ifndef __DEC32_DIG__
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define __DEC32_DIG__   9
#   endif
#   ifndef DEC32_DIG
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define DEC32_DIG   9
#   endif
#   ifndef __DEC32_EPSILON__
/** Difference between 1.0 and the minimum decimal32 greater than 1.0 */
#      define __DEC32_EPSILON__   (1.0E-6DF)
/** Difference between 1.0 and the minimum decimal32 greater than 1.0 */
#      define DEC32_EPSILON   __DEC32_EPSILON__
#   else
/** Difference between 1.0 and the minimum decimal32 greater than 1.0 */
#      define DEC32_EPSILON   __DEC32_EPSILON__
#   endif
#   ifndef __DEC32_MIN_EXP__
/** Minimum int x such that 10**(x-1) is a normalised decimal32 */
#      define __DEC32_MIN_EXP__   (-94)
/** Minimum int x such that 10**(x-1) is a normalised decimal32 */
#      define DEC32_MIN_EXP   (-94)
#   else
/** Minimum int x such that 10**(x-1) is a normalised decimal32 */
#      define DEC32_MIN_EXP   __DEC32_MIN_EXP__
#   endif
#   ifndef __DEC32_MIN__
/** Minimum normalised decimal32 */
#      define __DEC32_MIN__   (1.0E-95DF)
/** Minimum normalised decimal32 */
#      define DEC32_MIN   __DEC32_MIN__
#   else
/** Minimum normalised decimal32 */
#      define DEC32_MIN   __DEC32_MIN__
#   endif
#   ifndef __DEC32_SUBNORMAL_MIN__
/** Minimal subnormal decimal32 value */
#      define __DEC32_SUBNORMAL_MIN__   (0.000001E-95DF)
/** Minimal subnormal decimal32 value */
#      define DEC32_SUBNORMAL_MIN   __DEC32_SUBNORMAL_MIN__
#   else
/** Minimal subnormal decimal32 value */
#      define DEC32_SUBNORMAL_MIN   __DEC32_SUBNORMAL_MIN__
#   endif
#   ifndef DEC32_DENORM_MIN
/** Minimal denormal decimal32 value */
#      define DEC32_DENORM_MIN   DEC32_SUBNORMAL_MIN
#   endif
#   ifndef __DEC32_MAX_EXP__
/** Maximum int x such that 10**(x-1) is a representable decimal32 */
#      define __DEC32_MAX_EXP__   (97)
/** Maximum int x such that 10**(x-1) is a representable decimal32 */
#      define DEC32_MAX_EXP   (97)
#   else
/** Maximum int x such that 10**(x-1) is a representable decimal32 */
#      define DEC32_MAX_EXP   __DEC32_MAX_EXP__
#   endif
#   ifndef __DEC32_MAX__
/** The maximum representable finite decimal float */
#      define __DEC32_MAX__   (9.999999E+96DF)
/** The maximum representable finite decimal float */
#      define DEC32_MAX   __DEC32_MAX__
#   else
/** The maximum representable finite decimal float */
#      define DEC32_MAX   __DEC32_MAX__
#   endif
#   define DEC_MAX_DIGITS   999999999
#   define DEC_MIN_DIGITS   1
#   define DEC_MAX_EMAX   999999999
#   define DEC_MIN_EMAX   0
#   define DEC_MAX_EMIN   0
#   define DEC_MIN_EMIN   -999999999
#   define DECIMAL32_Bytes   4
/** Maximum precision (digits) */
#   define DECIMAL32_Pmax   7
/** Maximum adjusted exponent */
#   define DECIMAL32_Emax   96
/** Minimum adjusted exponent */
#   define DECIMAL32_Emin   -95
/** Bias for the exponent */
#   define DECIMAL32_Bias   101
/** Maximum string length */
#   define DECIMAL32_String   14
#   define DECIMAL32_Ehigh   (DECIMAL32_Emax + DECIMAL32_Bias - DECIMAL32_Pmax + 1)
#endif

/** @} */  // }


/** @defgroup Decimal64_Properties Macros providing special values and properties concerning 64-bit decimal floats (`decimal64`)
@{ */  // (FB){

#if SUPPORTS_DECIMAL64
#   ifndef __DEC64_RADIX__
/** Radix of exponent representation */
#      define __DEC64_RADIX__   (10)
/** Radix of exponent representation */
#      define DEC64_RADIX   (10)
#   else
/** Radix of exponent representation */
#      define DEC64_RADIX   (10)
#   endif
#   ifndef _DEC64_RADIX
/** Radix of exponent representation */
#      define _DEC64_RADIX   (10)
#   endif
#   ifndef __DEC64_MANT_DIG__
/** Number of base-10 digits in the significand of a decimal64 */
#      define __DEC64_MANT_DIG__   (16)
/** Number of base-10 digits in the significand of a decimal64 */
#      define DEC64_MANT_DIG   (16)
#   else
/** Number of base-10 digits in the significand of a decimal64 */
#      define DEC64_MANT_DIG   __DEC64_MANT_DIG__
#   endif
#   ifndef __DEC64_DIG__
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define __DEC64_DIG__   (17)
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define DEC64_DIG   (17)
#   else
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define DEC64_DIG   __DEC64_DIG__
#   endif
#   ifndef DEC64_DECIMAL_DIG
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define DEC64_DECIMAL_DIG   __DEC64_DIG__
#   endif
#   ifndef __DEC64_EPSILON__
/** Difference between 1.0 and the minimum decimal64 greater than 1.0 */
#      define __DEC64_EPSILON__   (1.0E-15DD)
/** Difference between 1.0 and the minimum decimal64 greater than 1.0 */
#      define DEC64_EPSILON   __DEC64_EPSILON__
#   else
/** Difference between 1.0 and the minimum decimal64 greater than 1.0 */
#      define DEC64_EPSILON   __DEC64_EPSILON__
#   endif
#   ifndef __DEC64_MIN_EXP__
/** Minimum int x such that 10**(x-1) is a normalised decimal64 */
#      define __DEC64_MIN_EXP__   (-382)
/** Minimum int x such that 10**(x-1) is a normalised decimal64 */
#      define DEC64_MIN_EXP   (-382)
#   else
/** Minimum int x such that 10**(x-1) is a normalised decimal64 */
#      define DEC64_MIN_EXP   __DEC64_MIN_EXP__
#   endif
#   ifndef __DEC64_MIN__
/** Minimum normalised decimal64 */
#      define __DEC64_MIN__   (1.0E-383DD)
/** Minimum normalised decimal64 */
#      define DEC64_MIN   __DEC64_MIN__
#   else
/** Minimum normalised decimal64 */
#      define DEC64_MIN   __DEC64_MIN__
#   endif
#   ifndef __DEC64_SUBNORMAL_MIN__
/** Minimal subnormal decimal64 value */
#      define __DEC64_SUBNORMAL_MIN__   (0.000000000000001E-383DD)
/** Minimal subnormal decimal64 value */
#      define DEC64_SUBNORMAL_MIN   __DEC64_SUBNORMAL_MIN__
#   else
/** Minimal subnormal decimal64 value */
#      define DEC64_SUBNORMAL_MIN   __DEC64_SUBNORMAL_MIN__
#   endif
#   ifndef DEC64_DENORM_MIN
/** Minimal denormal decimal64 value */
#      define DEC64_DENORM_MIN   DEC64_SUBNORMAL_MIN
#   endif
#   ifndef __DEC64_MAX_EXP__
/** Maximum int x such that 10**(x-1) is a representable decimal32 */
#      define __DEC64_MAX_EXP__   (385)
/** Maximum int x such that 10**(x-1) is a representable decimal32 */
#      define DEC64_MAX_EXP   (385)
#   else
/** Maximum int x such that 10**(x-1) is a representable decimal32 */
#      define DEC64_MAX_EXP   __DEC64_MAX_EXP__
#   endif
#   ifndef __DEC64_MAX__
/** The maximum representable finite decimal double */
#      define __DEC64_MAX__   (9.999999999999999E+384DD)
/** The maximum representable finite decimal double */
#      define DEC64_MAX   __DEC64_MAX__
#   else
/** The maximum representable finite decimal double */
#      define DEC64_MAX   __DEC64_MAX__
#   endif
#endif

/** @} */  // }


/** @defgroup Decimal128_Properties Macros providing special values and properties concerning 128-bit decimal floats (`decimal128`)
@{ */  // (FB){

#if SUPPORTS_DECIMAL128
#   ifndef __DEC128_RADIX__
/** Radix of exponent representation */
#      define __DEC128_RADIX__   (10)
/** Radix of exponent representation */
#      define DEC128_RADIX   (10)
#   else
/** Radix of exponent representation */
#      define DEC128_RADIX   (10)
#   endif
#   ifndef _DEC128_RADIX
/** Radix of exponent representation */
#      define _DEC128_RADIX   (10)
#   endif
#   ifndef __DEC128_MANT_DIG__
/** Number of base-10 digits in the significand of a decimal128 */
#      define DEC128_MANT_DIG   (34)
/** Number of base-10 digits in the significand of a decimal128 */
#      define __DEC128_MANT_DIG__   (34)
#   else
/** Number of base-10 digits in the significand of a decimal128 */
#      define DEC128_MANT_DIG   __DEC128_MANT_DIG__
#   endif
#   ifndef __DEC128_DIG__
#      if IS_SOFTFP
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#         define __DEC128_DIG__   (17)
#      else
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#         define __DEC128_DIG__   (21)
#      endif
#   endif
#   ifndef DEC128_DIG
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define DEC128_DIG   __DEC128_DIG__
#   endif
#   ifndef DEC128_SIG_FIG
/** Maximum significant figures */
#      define DEC128_SIG_FIG   34
#   endif
#   ifndef __DEC128_EPSILON__
/** Difference between 1.0 and the minimum decimal64 greater than 1.0 */
#      define __DEC128_EPSILON__   (1.0E-33DL)
/** Difference between 1.0 and the minimum decimal64 greater than 1.0 */
#      define DEC128_EPSILON   __DEC128_EPSILON__
#   else
/** Difference between 1.0 and the minimum decimal64 greater than 1.0 */
#      define DEC128_EPSILON   __DEC128_EPSILON__
#   endif
#   ifndef __DEC128_MIN_EXP__
/** Minimum int x such that 10**(x-1) is a normalised decimal128 */
#      define __DEC128_MIN_EXP__   (-6142)
/** Minimum int x such that 10**(x-1) is a normalised decimal128 */
#      define DEC128_MIN_EXP   (-6142)
#   else
/** Minimum int x such that 10**(x-1) is a normalised decimal128 */
#      define DEC128_MIN_EXP   __DEC128_MIN_EXP__
#   endif
#   ifndef __DEC128_MIN__
/** Minimum normalised decimal128 */
#      define __DEC128_MIN__   (1.0E-6143DL)
/** Minimum normalised decimal128 */
#      define DEC128_MIN   __DEC128_MIN__
#   else
/** Minimum normalised decimal128 */
#      define DEC128_MIN   __DEC128_MIN__
#   endif
#   ifndef __DEC128_SUBNORMAL_MIN__
/** Minimal subnormal decimal64 value */
#      define __DEC128_SUBNORMAL_MIN__   (0.000000000000000000000000000000001E-6143DL)
/** Minimal subnormal decimal64 value */
#      define DEC128_SUBNORMAL_MIN   __DEC128_SUBNORMAL_MIN__
#   else
/** Minimal subnormal decimal64 value */
#      define DEC128_SUBNORMAL_MIN   __DEC128_SUBNORMAL_MIN__
#   endif
#   ifndef DEC128_DENORM_MIN
/** Minimal denormal decimal128 value */
#      define DEC128_DENORM_MIN   DEC128_SUBNORMAL_MIN
#   endif
#   ifndef __DEC128_MAX_EXP__
/** Maximum int x such that 10**(x-1) is a representable decimal128 */
#      define __DEC128_MAX_EXP__   (6145)
/** Maximum int x such that 10**(x-1) is a representable decimal128 */
#      define DEC128_MAX_EXP   __DEC128_MAX_EXP__
#   else
/** Maximum int x such that 10**(x-1) is a representable decimal128 */
#      define DEC128_MAX_EXP   __DEC128_MAX_EXP__
#   endif
#   ifndef __DEC128_MAX__
/** The maximum representable finite decimal double */
#      define __DEC128_MAX__   (9.999999999999999999999999999999999E+6144DL)
/** The maximum representable finite decimal double */
#      define DEC128_MAX   __DEC128_MAX__
#   else
/** The maximum representable finite decimal double */
#      define DEC128_MAX   __DEC128_MAX__
#   endif
#endif

/** @} */  // }


// MISCELLANEOUS VALUES (<floatio.h>)

#ifndef TININESS_AFTER_ROUNDING
#   define TININESS_AFTER_ROUNDING   0
#endif
/** Max decimal digits in a 11-bit exponent (VAX G floating-point) is 308 decimal digits */
#define MAXEXP   (308)
/** Max decimal digits in a 128-bit fraction takes up 39 decimal digits */
#define MAXFRACT   (39)
/** MAXEXPDIG is the maximum number of decimal digits needed to store a floating-point exponent in the largest supported format; It should be `ceil(log10(LDBL_MAX_10_EXP))` or `ceil(log10(LDBL_MAX_EXP))` (if hexadecimal floating-point conversions are supported) */
#define MAXEXPDIG   (6)
/** Zero-initialization; Used to avoid warnings */
#define _FP_ZERO_INIT   0
/** @def _FPIO_CONST_OFFSET
Offset of the constants in the array `_fpioconst_pow10` */
#if (BITS_PER_MP_LIMB == 32)
#   define _FPIO_CONST_OFFSET   2
#else
#   define _FPIO_CONST_OFFSET   1
#endif
/** Offset of the constants in the array `_fpioconst_pow10` */
#define FPIO_CONST_OFFSET   _FPIO_CONST_OFFSET
/** @def FLT_UWORD_IS_FINITE
True if a positive float with bitmask `x` is finite */
/** @def FLT_UWORD_IS_NAN
True if a positive float with bitmask `x` is not a number */
/** @def FLT_UWORD_IS_INFINITE
True if a positive float with bitmask `x` is +infinity */
/** @def FLT_UWORD_EXP_MAX
The bitmask of the largest finite exponent (129 if the largest exponent is used for finite numbers, 128 otherwise) */
/** @def FLT_UWORD_LOG_MAX
The bitmask of `log(FLT_MAX)` (rounded down); This value is the largest input that can be passed to `exp()` without producing overflow */
/** @def FLT_UWORD_LOG_2MAX
The bitmask of `log(2*FLT_MAX)` (rounded down); This value is the largest input than can be passed to `cosh()` without producing overflow */
#ifdef _FLT_LARGEST_EXPONENT_IS_NORMAL
#   define FLT_UWORD_IS_FINITE(x)   1
#   define FLT_UWORD_IS_NAN(x)   0
#   define FLT_UWORD_IS_INFINITE(x)   0
#   define FLT_UWORD_MAX   0x7fffffff
#   define FLT_UWORD_EXP_MAX   0x43010000
#   define FLT_UWORD_LOG_MAX   0x42b2d4fc
#   define FLT_UWORD_LOG_2MAX   0x42b437e0
#else
#   define FLT_UWORD_IS_FINITE(x)   ((x) < 0x7f800000L)
#   define FLT_UWORD_IS_NAN(x)   ((x) > 0x7f800000L)
#   define FLT_UWORD_IS_INFINITE(x)   ((x) == 0x7f800000L)
#   define FLT_UWORD_MAX   0x7f7fffffL
#   define FLT_UWORD_EXP_MAX   0x43000000
#   define FLT_UWORD_LOG_MAX   0x42b17217
#   define FLT_UWORD_LOG_2MAX   0x42b2d4fc
#endif
/** The bitmask of FLT_MAX/2 */
#define FLT_UWORD_HALF_MAX   (FLT_UWORD_MAX - 100000000000000000000000L)
/** The largest biased exponent that can be used for finite numbers (255 if the largest exponent is used for finite numbers, 254 otherwise) */
#define FLT_LARGEST_EXP   (FLT_UWORD_MAX >> 23)
/** @def FLT_UWORD_IS_ZERO
True if a positive float with bitmask `x` is +0; Without denormals, any float with a zero exponent is a +0 representation; With denormals, the only +0 representation is a 0 bitmask */
/** @def FLT_UWORD_IS_SUBNORMAL
True if a non-zero positive float with bitmask `x` is subnormal (Routines should check for zeros first) */
/** @def FLT_UWORD_MIN
The bitmask of the smallest float above +0 */
/** @def FLT_UWORD_EXP_MIN
The bitmask of the float representation of `REAL_FLT_MIN`'s exponent */
/** @def FLT_UWORD_LOG_MIN
The bitmask of `log(REAL_FLT_MIN)` (rounding down) */
/** @def FLT_SMALLEST_EXP
`REAL_FLT_MIN`'s exponent - `EXP_BIAS` (1 if denormals are not supported, -22 if they are) */
#ifdef _FLT_NO_DENORMALS
#   define FLT_UWORD_IS_ZERO(x)   ((x) < 0x800000L)
#   define FLT_UWORD_IS_SUBNORMAL(x)   0
#   define FLT_UWORD_MIN   0x800000
#   define FLT_UWORD_EXP_MIN   0x42fc0000
#   define FLT_UWORD_LOG_MIN   0x42aeac50
#   define FLT_SMALLEST_EXP   1
#else
#   define FLT_UWORD_IS_ZERO(x)   ((x) == 0)
#   define FLT_UWORD_IS_SUBNORMAL(x)   ((x) < 0x800000L)
#   define FLT_UWORD_MIN   1
#   define FLT_UWORD_EXP_MIN   0x43160000
#   define FLT_UWORD_LOG_MIN   0x42cff1b5
#   define FLT_SMALLEST_EXP   -22
#endif


// FLT_ROUNDS, FLT_EVAL_METHOD, & DEC_EVAL_METHOD

#ifndef FLT_ROUNDS
#   ifndef __FLT_ROUNDS__
/** Addition rounds to 0: zero, 1: nearest, 2: +inf, 3: -inf, -1: unknown */
#      define __FLT_ROUNDS__   (1)
/** Addition rounds to 0: zero, 1: nearest, 2: +inf, 3: -inf, -1: unknown */
#      define FLT_ROUNDS   (1)
#   else
/** Addition rounds to 0: zero, 1: nearest, 2: +inf, 3: -inf, -1: unknown */
#      define FLT_ROUNDS   __FLT_ROUNDS__
#   endif
#endif
/** @def __FLT_EVAL_METHOD__
Specifies the precision in which all floating-point arithmetic operations (other than assignment and cast) are performed

Values:
 - Negative (except -1): Implementation-defined behavior
 - -1: The default precision is not known
 - 0: All operations and constants evaluate in the range and precision of the type used. Additionally, float_t and double_t are equivalent to `float` and `double`, respectively
 - 1: All operations and constants evaluate in the range and precision of double, and float_t and double_t are equivalent to `double`
 - 2: All operations and constants evaluate in the range and precision of long double, so float_t and double_t are equivalent to `long double`
*/
#if ((!defined(__FLT_EVAL_METHOD__)) && SUPPORTS_LONG_DOUBLE)  // ix87 FPU default
#   define __FLT_EVAL_METHOD__   (2)
#elif (!defined(__FLT_EVAL_METHOD__))
#   define __FLT_EVAL_METHOD__   (0)
#endif
#if (__FLT_EVAL_METHOD__ == 0)
#   define float_t   float
#   define double_t   double
#elif (__FLT_EVAL_METHOD__ == 1)
#   define float_t   double
#   define double_t   double
#elif ((__FLT_EVAL_METHOD__ == 2) && SUPPORTS_LONG_DOUBLE)
#   define float_t   long double
#   define double_t   long double
#elif (__FLT_EVAL_METHOD__ < 0)
#   error   "FLT_EVAL_METHOD is less than 0!"
#else
#   error   "FLT_EVAL_METHOD is unspecified!"
#endif
/** Specifies the precision in which all floating-point arithmetic operations (other than assignment and cast) are performed */
#define FLT_EVAL_METHOD   __FLT_EVAL_METHOD__
#if (FLT_EVAL_METHOD == 0 || FLT_EVAL_METHOD == 1)
#   define EPS   DBL_EPSILON
#elif (FLT_EVAL_METHOD == 2)
#   define EPS   LDBL_EPSILON
#endif
#if SUPPORTS_LONG_DOUBLE
#   define __long_double_t   long double
#   ifndef __long_double_t
#      define __long_double_t   long double
#   endif
#   ifndef long_double_t
#      define long_double_t   long double
#   endif
#endif
#ifndef __DEC_EVAL_METHOD__
/** Specifies the precision in which all decimal floating-point arithmetic operations (other than assignment and cast) are performed */
#   define __DEC_EVAL_METHOD__   __FLT_EVAL_METHOD__
#endif
#ifndef DEC_EVAL_METHOD
/** Specifies the precision in which all decimal floating-point arithmetic operations (other than assignment and cast) are performed */
#   define DEC_EVAL_METHOD   __DEC_EVAL_METHOD__
#endif
#ifdef __DECIMAL_BID_FORMAT__
#   define DECIMAL_BID_FORMAT   __DECIMAL_BID_FORMAT__
#else
#   define DECIMAL_BID_FORMAT   1
#   define __DECIMAL_BID_FORMAT__   1
#endif


// FPMAX_T & FPMAX_*

/** @typedef fpmax_t
Float-point datatype that is equivalent to the largest float-point datatype supported by the target system */
#ifdef LDBL_MANT_DIG
typedef long double   fpmax_t;
#   define FPMAX_TYPE   3
#   define FPMAX_MANT_DIG   LDBL_MANT_DIG
#   define FPMAX_DIG   LDBL_DIG
#   define FPMAX_EPSILON   LDBL_EPSILON
#   define FPMAX_MIN_EXP   LDBL_MIN_EXP
#   define FPMAX_MIN   LDBL_MIN
#   define FPMAX_MIN_10_EXP   LDBL_MIN_10_EXP
#   define FPMAX_MAX_EXP   LDBL_MAX_EXP
#   define FPMAX_MAX   LDBL_MAX
#   define FPMAX_MAX_10_EXP   LDBL_MAX_10_EXP
#elif defined(DBL_MANT_DIG)
typedef double   fpmax_t;
#   define FPMAX_TYPE   2
#   define FPMAX_MANT_DIG   DBL_MANT_DIG
#   define FPMAX_DIG   DBL_DIG
#   define FPMAX_EPSILON   DBL_EPSILON
#   define FPMAX_MIN_EXP   DBL_MIN_EXP
#   define FPMAX_MIN   DBL_MIN
#   define FPMAX_MIN_10_EXP   DBL_MIN_10_EXP
#   define FPMAX_MAX_EXP   DBL_MAX_EXP
#   define FPMAX_MAX   DBL_MAX
#   define FPMAX_MAX_10_EXP   DBL_MAX_10_EXP
#elif defined(FLT_MANT_DIG)
typedef float   fpmax_t;
#   define FPMAX_TYPE   1
#   define FPMAX_MANT_DIG   FLT_MANT_DIG
#   define FPMAX_DIG   FLT_DIG
#   define FPMAX_EPSILON   FLT_EPSILON
#   define FPMAX_MIN_EXP   FLT_MIN_EXP
#   define FPMAX_MIN   FLT_MIN
#   define FPMAX_MIN_10_EXP   FLT_MIN_10_EXP
#   define FPMAX_MAX_EXP   FLT_MAX_EXP
#   define FPMAX_MAX   FLT_MAX
#   define FPMAX_MAX_10_EXP   FLT_MAX_10_EXP
#else
#   error   "Unable to determine appropriate type for __fpmax_t!"
#endif
/** Float-point datatype that is equivalent to the largest float-point datatype supported by the target system */
#define __fpmax_t   fpmax_t
/** Float-point datatype that is equivalent to the largest float-point datatype supported by the target system */
#define floatmax_t   fpmax_t
/** Float-point datatype that is equivalent to the largest float-point datatype supported by the target system */
#define float_max_t   fpmax_t
/** Checks if a fpmax_t is either 0 or +/- infinity */
#define __FPMAX_ZERO_OR_INF_CHECK(x)   ((x) == ((x) >> 2))


// FPU CONTROL DATATYPE

/** @typedef fpu_control_t
FPU Control Word Datatype */
#if (defined(ARCHM68K) || defined(ARCHMIPS))
typedef USItype   fpu_control_t;
#elif defined(ARCHSPARC)
typedef unsigned long   fpu_control_t;
#elif defined(ARCHX86)
typedef UHItype   fpu_control_t;
#else
typedef unsigned int   fpu_control_t;
#endif
#define __fpu_control_t   fpu_control_t
/** Default control word set at startup */
extern UNUSED fpu_control_t fpu_control;
#define __fpu_control   fpu_control


// FPU CONTROL MACROS

/** @defgroup FPU_Control_Macros Macros used to manipulate the FPU
@{ */  // (FB){

/** @def _FPU_MASK_I
Inexact operation */
/** @def _FPU_MASK_O
Overflow */
/** @def _FPU_MASK_PM
Inexact */
/** @def _FPU_MASK_U
Underflow */
/** @def _FPU_MASK_XM
Inexact */
/** @def _FPU_MASK_Z
Division by zero */
/** @def _FPU_IEEE
Default FPU control settings */
/** @def _FPU_DEFAULT
Default FPU control settings */
/** @def _FPU_RESERVED
Reserved FPU bits */
/** @def _FPU_GETCW
Macros for accessing the hardware control word (current status word) */
/** @def _FPU_SETCW
Get the current status word and set the control word */
#ifdef ARCHALPHA
#   define _FPU_MASK_IM   1
#   define _FPU_MASK_DM   2
#   define _FPU_MASK_ZM   4
#   define _FPU_MASK_OM   8
#   define _FPU_MASK_UM   0x10
#   define _FPU_MASK_PM   0x20
#   define _FPU_EXTENDED   0x300
#   define _FPU_DOUBLE   0x200
#   define _FPU_SINGLE   0
#   define _FPU_RC_NEAREST   0
#   define _FPU_RC_DOWN   0x400
#   define _FPU_RC_UP   0x800
#   define _FPU_RC_ZERO   0xc00
#   define FP_RND_NEAREST   FE_TONEAREST
#   define FP_RND_ZERO   FE_TOWARDZERO
#   define FP_RND_PINF   FE_UPWARD
#   define FP_RND_MINF   FE_DOWNWARD
#   define FP_ROUNDMODE   _round
#   define FP_EX_INVALID   FE_INVALID
#   define FP_EX_OVERFLOW   FE_OVERFLOW
#   define FP_EX_UNDERFLOW   FE_UNDERFLOW
#   define FP_EX_DIVZERO   FE_DIVBYZERO
#   define FP_EX_INEXACT   FE_INEXACT
#   define _FP_TININESS_AFTER_ROUNDING   1
/** Reserved bits in cw */
#   define _FPU_RESERVED   0xf0c0
#   define _FPU_DEFAULT   0x137f
#   define _FPU_IEEE   0x137f
#   define FPCR_ROUND_MASK   844424930131968UL
#   define FPCR_ROUND_SHIFT   58
#   define SWCR_MAP_MASK   12288UL
#   define SWCR_ENABLE_SHIFT   16
#   define SWCR_ENABLE_MASK   (FE_ALL_EXCEPT >> SWCR_ENABLE_SHIFT)
#   define SWCR_STATUS_MASK   (FE_ALL_EXCEPT)
#   define SWCR_ALL_MASK   (SWCR_ENABLE_MASK | SWCR_MAP_MASK | SWCR_STATUS_MASK)
#   define _FP_W_TYPE   unsigned long
#   define _FP_WS_TYPE   signed long
#   define _FP_I_TYPE   long
#elif defined(ARCHARM)
#   define _FPU_DEFAULT   0
#   if defined(ARCHAARCH64)
#      define _FPU_GETCW(fpcr)   vasm("mrs %0, fpcr;" : "=r"(fpcr))
#      define _FPU_SETCW(fpcr)   vasm("msr fpcr, %0;" : : "r"(fpcr))
#      define _FPU_GETFPSR(fpsr)   vasm("mrs %0, fpsr;" : "=r"(fpsr))
#      define _FPU_SETFPSR(fpsr)   vasm("msr fpsr, %0;" : : "r"(fpsr))
#      define _FPU_RESERVED   0xfe0fe0ff
#      define _FPU_FPSR_RESERVED  0x0fffffe0
#      define _FPU_FPSR_DEFAULT   0
#      define _FPU_FPCR_RM_MASK   0xc00000
#      define _FPU_FPCR_MASK_IXE   0x1000
#      define _FPU_FPCR_MASK_UFE   0x800
#      define _FPU_FPCR_MASK_OFE   0x400
#      define _FPU_FPCR_MASK_DZE   0x200
#      define _FPU_FPCR_MASK_IOE   0x100
#      define _FPU_FPCR_IEEE   (_FPU_DEFAULT  | _FPU_FPCR_MASK_IXE | _FPU_FPCR_MASK_UFE | _FPU_FPCR_MASK_OFE | _FPU_FPCR_MASK_DZE | _FPU_FPCR_MASK_IOE)
#      define _FPU_FPSR_IEEE   0
#      define FP_RND_NEAREST   FE_TONEAREST
#      define FP_RND_ZERO   FE_TOWARDZERO
#      define FP_RND_PINF   FE_UPWARD
#      define FP_RND_MINF   FE_DOWNWARD
#      define FP_EX_INVALID   FE_INVALID
#      define FP_EX_OVERFLOW   FE_OVERFLOW
#      define FP_EX_UNDERFLOW   FE_UNDERFLOW
#      define FP_EX_DIVZERO   FE_DIVBYZERO
#      define FP_EX_INEXACT   FE_INEXACT
#      define FP_TRAPPING_EXCEPTIONS   ((_fcw >> FE_EXCEPT_SHIFT) & FE_ALL_EXCEPT)
#      define _FP_W_TYPE   unsigned long long
#      define _FP_WS_TYPE   signed long long
#      define _FP_I_TYPE   long long
typedef unsigned int   fpu_fpsr_t;
#   elif defined(ARCHAARCH32)
#      if (!(defined(_LIBC) && (!defined(_LIBC_TEST))) && IS_SOFTFP)
#         define _FPU_RESERVED   0xffffffff
#      else
#         define _FPU_MASK_IM   0x100
#         define _FPU_MASK_ZM   0x200
#         define _FPU_MASK_OM   0x400
#         define _FPU_MASK_UM   0x800
#         define _FPU_MASK_PM   0x1000
/** NZCV flags */
#         define _FPU_MASK_NZCV   0xf0000000
/** Rounding mode */
#         define _FPU_MASK_RM   0xc00000
/** All exception flags */
#         define _FPU_MASK_EXCEPT   0x1f1f
#         define _FPU_RESERVED   0x86060
#         define _FPU_IEEE   (_FPU_DEFAULT | 0x1f00)
#         define _FPU_GETCW(cw)   vasm("mrc p10, 7, %0, cr1, cr0, 0;" : "=r"(cw))
#         define _FPU_SETCW(cw)   vasm("mcr p10, 7, %0, cr1, cr0, 0;" : : "r"(cw))
#      endif  // SOFTFP
#      define GET_FPSCR()   do { uint32_t _fpscr; vasm("fmrx %0, fpscr;" : "=r"(_fpscr)); _fpscr; } while (0x0)
#      define SET_FPSCR(_fpscr)   vasm("fmxr fpscr, %0;" : : "r"(_fpscr))
#      define FE_INEXACT   0x10
#      define FE_UNDERFLOW   8
#      define FE_OVERFLOW   4
#      define FE_DIVBYZERO   2
#      define FE_INVALID   1
#      define FE_ALL_EXCEPT   0x1f
#      define FE_TONEAREST   0
#      define FE_UPWARD   0x400000
#      define FE_DOWNWARD   0x800000
#      define FE_TOWARDZERO   0xc00000
#      define FE_ALL_RND   (FE_TONEAREST | FE_TOWARDZERO | FE_UPWARD | FE_DOWNWARD)
#      define _FP_W_TYPE   unsigned long
#      define _FP_WS_TYPE   signed long
#      define _FP_I_TYPE   long
#   endif
#   define _FP_TININESS_AFTER_ROUNDING   0
#   define JMPBUFSP   0
#   define JMPBUFPC   1
#   define JMPBUFDPC   0
#   define FPINEX   0x1000
#   define FPUNFL   0x800
#   define FPOVFL   0x400
#   define FPZDIV   0x200
#   define FPINVAL   0x100
#   define FPRNR   0
#   define FPRZ   0x400000
#   define FPRPINF   0x800000
#   define FPRNINF   0xc00000
#   define FPRMASK   0xc00000
#   define FPPEXT   0
#   define FPPSGL   0
#   define FPPDBL   0
#   define FPPMASK   0
#   define FPAINEX   0x10
#   define FPAUNFL   8
#   define FPAOVFL   4
#   define FPAZDIV   2
#   define FPAINVAL   1
#elif defined(ARCHITANIUM)
#   define FE_INEXACT   0x20UL
#   define FE_UNDERFLOW   0x10UL
#   define FE_OVERFLOW   8UL
#   define FE_DIVBYZERO   4UL
#   define FE_UNNORMAL   2UL
#   define FE_INVALID   1UL
#   define FE_ALL_EXCEPT   (FE_INEXACT | FE_UNDERFLOW | FE_OVERFLOW | FE_DIVBYZERO | FE_UNNORMAL | FE_INVALID)
#   define FE_TOWARDZERO   3
#   define FE_UPWARD   2
#   define FE_DOWNWARD   1
#   define FE_TONEAREST   0
#elif defined(ARCHM68K)
#   define _FP_TININESS_AFTER_ROUNDING   0
#   define _FP_W_TYPE   unsigned long
#   define _FP_WS_TYPE   signed long
#   define _FP_I_TYPE   long
#   if (defined(ARCHCOLDFIRE) && (!defined(__mcffpu__)))
#      define _FPU_RESERVED   0xffffffff
#      define _FPU_DEFAULT    0
#      define _FPU_GETCW(cw)   ((cw) = 0)
#      define _FPU_SETCW(cw)   ((void)(cw))
#   else
#      define _FPU_MASK_BSUN   0x8000
#      define _FPU_MASK_SNAN   0x4000
#      define _FPU_MASK_OPERR   0x2000
#      define _FPU_MASK_OVFL   0x1000
#      define _FPU_MASK_UNFL   0x800
#      define _FPU_MASK_DZ   0x400
#      define _FPU_MASK_INEX1   0x200
#      define _FPU_MASK_INEX2   0x100
#      ifdef ARCHCOLDFIRE
#         define _FPU_DOUBLE   0
/** Reserved bits in fpucr */
#         define _FPU_RESERVED   0xffff800f
#      else
#         define _FPU_EXTENDED   0
#         define _FPU_DOUBLE   0x80
/** Reserved bits in fpucr */
#         define _FPU_RESERVED   0xffff000f
#      endif
#      define _FPU_SINGLE   0x40
#      define _FPU_RC_NEAREST   0
#      define _FPU_RC_ZERO   0x10
#      define _FPU_RC_DOWN   0x20
#      define _FPU_RC_UP   0x30
#      define _FPU_DEFAULT   0
#      define _FPU_IEEE   1
/** Macros for accessing the hardware control word */
#      define _FPU_GETCW(cw)   vasm("fmove%.l %!, %0;" : "=dm"(cw))
#      define _FPU_SETCW(cw)   vasm("fmove%.l %0, %!;" : : "dm"(cw))
#   endif
#elif defined(ARCHMICROBLAZE)
#   define _FP_W_TYPE   unsigned long
#   define _FP_WS_TYPE   signed long
#   define _FP_I_TYPE   long
#   define _FP_TININESS_AFTER_ROUNDING   0
#elif defined(ARCHMIPS)
#   define ENABLE_MASK   0xf80U
#   define CAUSE_MASK   0x1f000U
#   define ENABLE_SHIFT   5
#   define CAUSE_SHIFT   10
#   ifndef __STDC_IEC_559__
/** MIPS is not aligned to IEEE 754-2008 */
#      define HIGH_ORDER_BIT_IS_SET_FOR_SNAN
#   endif
#   if IS_SOFTFP
#      define _FPU_RESERVED   0xffffffff
#      define _FPU_DEFAULT   0
#   else
/** Invalid operation */
#      define _FPU_MASK_V   0x800
#      define _FPU_MASK_Z   0x400
#      define _FPU_MASK_O   0x200
#      define _FPU_MASK_U   0x100
#      define _FPU_MASK_I   0x80
#      define _FPU_MASK_ALL   (_FPU_MASK_V | _FPU_MASK_Z | _FPU_MASK_O |_FPU_MASK_U | _FPU_MASK_I | FE_ALL_EXCEPT)
/** Flush denormalized numbers to zero */
#      define _FPU_FLUSH_TZ   0x1000000
/** IEEE 754-2008 compliance control */
#      define _FPU_ABS2008   0x80000
#      define _FPU_NAN2008   0x40000
#      define _FPU_RC_NEAREST   0
#      define _FPU_RC_ZERO   1
#      define _FPU_RC_UP   2
#      define _FPU_RC_DOWN   3
/** Mask for rounding control */
#      define _FPU_RC_MASK   3
#      define _FPU_RESERVED   0xfe8c0000
#      ifdef __mips_nan2008
#         define _FPU_DEFAULT   0xc0000
#         define _FPU_IEEE   0xc0f80
#      else
#         define _FPU_DEFAULT   0
#         define _FPU_IEEE   0xf80
#      endif
#      ifdef ARCHMIPS16
#         define _FPU_GETCW(cw)   do { (cw) = __mips_fpu_getcw(); } while (0x0)
#         define _FPU_SETCW(cw)   __mips_fpu_setcw(cw)
#      else
#         define _FPU_GETCW(cw)   vasm("cfc1 %0, $31;" : "=r"(cw))
#         define _FPU_SETCW(cw)   vasm("ctc1 %0, $31;" : : "r"(cw))
#      endif
#   endif  // mips_soft_float
#   define JMPBUFSP   0
#   define JMPBUFPC   1
#   define JMPBUFDPC   0
#   define FPINEX   0x80
#   define FPUNFL   0x100
#   define FPOVFL   0x200
#   define FPZDIV   0x400
#   define FPINVAL   0x800
#   define FPRNR   0
#   define FPRZ   1
#   define FPRPINF   2
#   define FPRNINF   3
#   define FPRMASK   3
#   define FPPEXT   0
#   define FPPSGL   0
#   define FPPDBL   0
#   define FPPMASK   0
#   define FPCOND   0x800000
#   define FPAINEX   4
#   define FPAOVFL   0x10
#   define FPAUNFL   8
#   define FPAZDIV   0x20
#   define FPAINVAL   0x40
#   define _FP_TININESS_AFTER_ROUNDING   1
#   ifdef ARCHMIPS64
#      define _FP_W_TYPE   unsigned long long
#      define _FP_WS_TYPE   signed long long
#      define _FP_I_TYPE   long long
#      define FP_RND_NEAREST   FE_TONEAREST
#      define FP_RND_ZERO   FE_TOWARDZERO
#      define FP_RND_PINF   FE_UPWARD
#      define FP_RND_MINF   FE_DOWNWARD
#      define FP_EX_INVALID   FE_INVALID
#      define FP_EX_OVERFLOW   FE_OVERFLOW
#      define FP_EX_UNDERFLOW   FE_UNDERFLOW
#      define FP_EX_DIVZERO   FE_DIVBYZERO
#      define FP_EX_INEXACT   FE_INEXACT
#   elif defined(ARCHMIPS32)
#      define _FP_W_TYPE   unsigned long
#      define _FP_WS_TYPE   signed long
#      define _FP_I_TYPE   long
#      define FP_EX_INVALID   16
#      define FP_EX_DIVZERO   8
#      define FP_EX_OVERFLOW   4
#      define FP_EX_UNDERFLOW   2
#      define FP_EX_INEXACT   1
#   endif
#elif defined(ARCHPARISC)
#   define _FPU_MASK_PM   1
#   define _FPU_MASK_UM   2
#   define _FPU_MASK_OM   4
#   define _FPU_MASK_ZM   8
#   define _FPU_MASK_IM   0x10
#   define _FPU_HPPA_MASK_RM   0x600
/** Interrupt mask */
#   define _FPU_HPPA_MASK_INT   0x1f
#   define _FPU_HPPA_SHIFT_FLAGS   27
#   define _FPU_RESERVED   0
#   define _FPU_DEFAULT   0
#   define _FPU_IEEE   (_FPU_DEFAULT | _FPU_HPPA_MASK_INT)
#   define _FPU_GETCW(cw)   __extension__ ({ union __union_FPU_GETCW { unsigned long long __fpreg; unsigned int __halfreg[2]; } __fullfp; asm ("fstd %%fr0, 0(%1);" "fldd 0(%1), %%fr0;" : "=m"(__fullfp.__fpreg) : "r"(&__fullfp.__fpreg) : "%r0"); cw = __fullfp.__halfreg[0]; })
#   define _FPU_SETCW(cw)   __extension__ ({ union __union_FPU_SETCW { unsigned long long __fpreg; unsigned int __halfreg[2]; } __fullfp; asm ("fstd %%fr0, 0(%1);" : "=m"(__fullfp.__fpreg) : "r"(&__fullfp.__fpreg) : "%r0"); __fullfp.__halfreg[0] = cw; asm ("fldd 0(%1), %%fr0;" : : "m"(__fullfp.__fpreg), "r"(&__fullfp.__fpreg) : "%r0" ); })
#elif defined(ARCHPOWERPC)
#   if IS_SOFTFP
#      define _FPU_RESERVED   0xffffffff
#      define _FPU_DEFAULT   0
#   elif defined(__NO_FPRS__)  // e500
#      define _FPU_RC_NEAREST   0
#      define _FPU_RC_DOWN   3
#      define _FPU_RC_UP   2
#      define _FPU_RC_ZERO   1
#      define _FPU_MASK_ZM   0x10
#      define _FPU_MASK_OM   4
#      define _FPU_MASK_UM   8
#      define _FPU_MASK_XM   0x40
#      define _FPU_MASK_IM   0x20
#      define _FPU_RESERVED   0xc10080
#      define _FPU_DEFAULT   0x3c
#      define _FPU_IEEE   _FPU_DEFAULT
#      define _FPU_GETCW(cw)   vasm("mfspefscr %0;" : "=r"(cw))
#      define _FPU_SETCW(cw)   vasm("mtspefscr %0;" : : "r"(cw))
#   else  // PowerPC 6xx floating-point
#      define _FPU_RC_NEAREST   0
#      define _FPU_RC_DOWN   3
#      define _FPU_RC_UP   2
#      define _FPU_RC_ZERO   1
#      define _FPU_MASK_NI   4
#      define _FPU_MASK_ZM   0x10
#      define _FPU_MASK_OM   0x40
#      define _FPU_MASK_UM   0x20
#      define _FPU_MASK_XM   8
#      define _FPU_MASK_IM   0x80
#      define _FPU_RESERVED   0xffffff00
#      define _FPU_DEFAULT   0
#      define _FPU_IEEE   0xf0
#      define _FPU_GETCW(cw)   __extension__ ({ union __union_FPU_GETCW { double __d; unsigned long long __ll; } __u; register double __fr; asm ("mffs %0;" : "=f"(__fr)); __u.__d = __fr; cw = (fpu_control_t)__u.__ll; (fpu_control_t) __u.__ll; })
#      define _FPU_SETCW(cw)   __extension__ ({ union __union_FPU_SETCW { double __d; unsigned long long __ll; } __u = { .__ll = 0xfff80000LL << 32 }; register double __fr; __u.__ll |= ((cw) & UINT32_MAX); __fr = __u.__d; asm ("mtfsf 255, %0;" : : "f"(__fr)); })
#   endif
#   define JMPBUFSP   0
#   define JMPBUFPC   1
#   define JMPBUFDPC   0
#   define _FP_W_TYPE   unsigned long
#   define _FP_WS_TYPE   signed long
#   define _FP_I_TYPE   long

/** Definitions of all the SPEFSCR bit numbers */
enum SPEFSCR_BITS {
	SPEFSCR_SOVH = 0x80000000,
	SPEFSCR_OVH = 0x40000000,
	SPEFSCR_FGH = 0x20000000,
	SPEFSCR_FXH = 0x10000000,
	SPEFSCR_FINVH = 0x8000000,
	SPEFSCR_FDBZH = 0x4000000,
	SPEFSCR_FUNFH = 0x2000000,
	SPEFSCR_FOVFH = 0x1000000,
	SPEFSCR_FINXS = 0x200000,
	SPEFSCR_FINVS = 0x100000,
	SPEFSCR_FDBZS = 0x80000,
	SPEFSCR_FUNFS = 0x40000,
	SPEFSCR_FOVFS = 0x20000,
	SPEFSCR_ALL_EXCEPT = 0x3e0000,
	SPEFSCR_MODE = 0x10000,
	SPEFSCR_SOV = 0x8000,
	SPEFSCR_OV = 0x4000,
	SPEFSCR_FG = 0x2000,
	SPEFSCR_FX = 0x1000,
	SPEFSCR_FINV = 0x800,
	SPEFSCR_FDBZ = 0x400,
	SPEFSCR_FUNF = 0x200,
	SPEFSCR_FOVF = 0x100,
	SPEFSCR_FINXE = 0x40,
	SPEFSCR_FINVE = 0x20,
	SPEFSCR_FDBZE = 0x10,
	SPEFSCR_FUNFE = 8,
	SPEFSCR_FOVFE = 4,
	SPEFSCR_ALL_EXCEPT_ENABLE = 0x7c,
	SPEFSCR_FRMC = 3
};

/** Definitions of all the FPSCR bit numbers */
enum FPSCR_BITS {
	FPSCR_FX = 0,  //!< Exception summary
	FPSCR_FEX,  //!< Enabled exception summary
	FPSCR_VX,  //!< Invalid operation summary
	FPSCR_OX,  //!< Overflow
	FPSCR_UX,  //!< Underflow
	FPSCR_ZX,  //!< Zero divide
	FPSCR_XX,  //!< Inexact
	FPSCR_VXSNAN,  //!< Invalid operation for sNaN
	FPSCR_VXISI,  //!< Invalid operation for Inf-Inf
	FPSCR_VXIDI,  //!< Invalid operation for Inf/Inf
	FPSCR_VXZDZ,  //!< Invalid operation for 0/0
	FPSCR_VXIMZ,  //!< Invalid operation for Inf*0
	FPSCR_VXVC,  //!< Invalid operation for invalid compare
	FPSCR_FR,  //!< Fraction rounded [fraction was incremented by round]
	FPSCR_FI,  //!< Fraction inexact
	FPSCR_FPRF_C,  //!< Result class descriptor
	FPSCR_FPRF_FL,  //!< Result less than (usually, less than 0)
	FPSCR_FPRF_FG,  //!< Result greater than
	FPSCR_FPRF_FE,  //!< Result equal to
	FPSCR_FPRF_FU,  //!< Result unordered
	FPSCR_20,  //!< Reserved
	FPSCR_VXSOFT,  //!< Invalid operation set by software
	FPSCR_VXSQRT,  //!< Invalid operation for square root
	FPSCR_VXCVI,  //!< Invalid operation for invalid integer convert
	FPSCR_VE,  //!< Invalid operation exception enable
	FPSCR_OE,  //!< Overflow exception enable
	FPSCR_UE,  //!< Underflow exception enable
	FPSCR_ZE,  //!< Zero divide exception enable
	FPSCR_XE,  //!< Inexact exception enable
#      ifdef _ARCH_PWR6
	FPSCR_29  //!< Reserved in ISA 2.05
#      else
	FPSCR_NI  //!< Non-IEEE mode (typically, no denormalised numbers)
#      endif  // _ARCH_PWR6
};

/** Exception summary (sticky) */
#   define FPSFX   0x80000000
/** Enabled exception summary */
#   define FPSEX   0x40000000
/** Invalid operation exception summary */
#   define FPSVX   0x20000000
/** Overflow exception OX (sticky) */
#   define FPSOX   0x10000000
/** Underflow exception UX (sticky) */
#   define FPSUX   0x8000000
/** Zero divide exception ZX (sticky) */
#   define FPSZX   0x4000000
/** Inexact exception XX (sticky) */
#   define FPSXX   0x2000000
/** Invalid operation exception for SNaN (sticky) */
#   define FPSVXSNAN   0x1000000
/** Invalid operation exception for ∞-∞ (sticky) */
#   define FPSVXISI   0x800000
/** Invalid operation exception for ∞/∞ (sticky) */
#   define FPSVXIDI   0x400000
/** Invalid operation exception for 0/0 (sticky) */
#   define FPSVXZDZ   0x200000
/** Invalid operation exception for ∞*0 (sticky) */
#   define FPSVXIMZ   0x100000
/** Invalid operation exception for invalid compare (sticky) */
#   define FPSVXVC   0x80000
/** Fraction rounded */
#   define FPSFR   0x40000
/** Fraction inexact */
#   define FPSFI   0x20000
/** Floating point result class */
#   define FPSFPRF   0x10000
/** <, >, =, unordered */
#   define FPSFPCC   0xf000
/** Enable exception for invalid integer convert (sticky) */
#   define FPVXCVI   0x100
/** Invalid operation exception enable */
#   define FPVE   0x80
/** Enable overflow exceptions */
#   define FPOVFL   0x40
/** Enable underflow */
#   define FPUNFL   0x20
/** Enable zero divide */
#   define FPZDIV   0x10
/** Enable inexact exceptions */
#   define FPINEX   8
/** Rounding mode */
#   define FPRMASK   3
#   define FPRNR   0
#   define FPRZ   1
#   define FPRPINF   2
#   define FPRNINF   3
#   define FPPEXT   0
#   define FPPSGL   0
#   define FPPDBL   0
#   define FPPMASK   0
#   define FPINVAL   FPVE
#   define FPAOVFL   FPSOX
#   define FPAINEX   FPSXX
#   define FPAUNFL   FPSUX
#   define FPAZDIV   FPSZX
#   define FPAINVAL   FPSVX
#   define _FPU_MASK_ALL   (_FPU_MASK_ZM | _FPU_MASK_OM | _FPU_MASK_UM | _FPU_MASK_XM | _FPU_MASK_IM)
/** Mask everything but the rounding moded and non-IEEE arithmetic flags */
#   define _FPU_MASK_ROUNDING   0xffffffff00000007LL
/** Mask restore rounding mode and exception enabled */
#   define _FPU_MASK_EXCEPT_ROUND   0xffffffff1fffff00LL
/** Mask exception enable but fraction rounded/inexact and FP result/CC bits */
#   define _FPU_MASK_FRAC_INEX_RET_CC   0x1ff80fff
#   define FE_INEXACT   0x2000000
#   define FE_DIVBYZERO   0x4000000
#   define FE_UNDERFLOW   0x8000000
#   define FE_OVERFLOW   0x10000000
#   define FE_INVALID   0x20000000
#   define FE_ALL_EXCEPT   0x3e000000
#   define FE_TONEAREST   0
#   define FE_TOWARDZERO   1
#   define FE_UPWARD   2
#   define FE_DOWNWARD   3
#   define FE_ALL_EXCEPT   (FE_INEXACT | FE_DIVBYZERO | FE_UNDERFLOW | FE_OVERFLOW | FE_INVALID)
/** The sticky bits in the FPSCR indicating exceptions have occurred */
#   define FPSCR_STICKY_BITS   ((FE_ALL_EXCEPT | FE_ALL_INVALID) & (~FE_INVALID))
#   define FE_ALL_FLAGS   0xfff80300
#elif defined(ARCHS390)
#   define _FPU_RESERVED   0x0707fffc
#   define _FPU_DEFAULT   0
#   if (defined(__NO_FPRS__) && IS_HARDFP)
#      define FP_EX_INEXACT   SPEFSCR_FINXS
#      define FP_EX_INVALID   SPEFSCR_FINVS
#      define FP_EX_DIVZERO   SPEFSCR_FDBZS
#      define FP_EX_UNDERFLOW   SPEFSCR_FUNFS
#      define FP_EX_OVERFLOW   SPEFSCR_FOVFS
#   else
#      define FP_EX_INVALID   536870912
#      define FP_EX_OVERFLOW   268435456
#      define FP_EX_UNDERFLOW   134217728
#      define FP_EX_DIVZERO   67108864
#      define FP_EX_INEXACT   33554432
#   endif
#   define _FPU_GETCW(cw)   vasm("efpc %0, 0;" : "=d"(cw))
#   define _FPU_SETCW(cw)   vasm("sfpc %0, 0;" : : "d"(cw))
/** Set/clear a particular FPSCR bit (for instance, `reset_fpscr_bit(FPSCR_VE)`; prevents `INVALID` exceptions from being raised) */
#   define set_fpscr_bit(x)   vasm("mtfsb1 %0;" : : "r,i,n"(x))
#   define reset_fpscr_bit(x)   vasm("mtfsb0 %0;" : : "r,i,n"(x))
#elif defined(ARCHSPARC)
#   define _FPU_MASK_IM   0x8000000
#   define _FPU_MASK_OM   0x4000000
#   define _FPU_MASK_UM   0x2000000
#   define _FPU_MASK_ZM   0x1000000
#   define _FPU_MASK_PM   0x800000
#   define _FPU_EXTENDED   0
#   define _FPU_DOUBLE   0x20000000
#   define _FPU_80BIT   0x30000000
#   define _FPU_SINGLE   0x10000000
#   define _FPU_RC_DOWN   0xc0000000
#   define _FPU_RC_UP   0x80000000
#   define _FPU_RC_ZERO   0x40000000
#   define _FPU_RC_NEAREST   0
#   define _FPU_RESERVED   0x30300000
#   define _FPU_DEFAULT   0
#   define _FPU_IEEE   0
#   define FE_INVALID   0x200
#   define FE_OVERFLOW   0x100
#   define FE_UNDERFLOW   0x80
#   define FE_DIVBYZERO   0x40
#   define FE_INEXACT   0x20
#   define FE_ALL_EXCEPT   (FE_INEXACT | FE_DIVBYZERO | FE_UNDERFLOW | FE_OVERFLOW | FE_INVALID)
#   define FE_TONEAREST   0
#   define FE_TOWARDZERO   0x40000000
#   define FE_UPWARD   0x80000000
#   define FE_DOWNWARD   0xc0000000
#   define __FE_ROUND_MASK   0xc0000000
#   define _FP_W_TYPE   unsigned long
#   define _FP_WS_TYPE   signed long
#   define _FP_I_TYPE   long
#   if IS_WORDSIZE_64
#      define _FPU_GETCW(cw)   vasm("stx %%fsr, %0;" : "=m"(*&cw))
#      define _FPU_SETCW(cw)   vasm("ldx %0, %%fsr;" : : "m"(*&cw))
#   else
#      define _FPU_GETCW(cw)   vasm("st %%fsr, %0;" : "=m"(*&cw))
#      define _FPU_SETCW(cw)   vasm("ld %0, %%fsr;" : : "m"(*&cw))
#   endif
#   define FP_EX_INVALID   16
#   define FP_EX_OVERFLOW   8
#   define FP_EX_UNDERFLOW   4
#   define FP_EX_DIVZERO   2
#   define FP_EX_INEXACT   1
#   define _FP_TININESS_AFTER_ROUNDING   0
#   define JMPBUFSP   0
#   define JMPBUFPC   1
#   define JMPBUFDPC   -8
#   define FPINEX   0x800000
#   define FPOVFL   0x4000000
#   define FPUNFL   0x2000000
#   define FPZDIV   0x1000000
#   define FPRNR   0
#   define FPRZ   0x40000000
#   define FPINVAL   0x8000000
#   define FPRPINF   0x80000000
#   define FPRNINF   0xc0000000
#   define FPRMASK   0xc0000000
#   define FPPEXT   0
#   define FPPSGL   0
#   define FPPDBL   0
#   define FPPMASK   0
#   define FPAINEX   0x20
#   define FPAZDIV   0x40
#   define FPAUNFL   0x80
#   define FPAOVFL   0x100
#   define FPAINVAL   0x200
#elif defined(ARCHSUPERH)
#   ifndef __SH_FPU_ANY__
#      define _FPU_RESERVED   0xffffffff
#      define _FPU_DEFAULT   0
#   else
#      define _FPU_MASK_VM   0x800
#      define _FPU_MASK_ZM   0x400
#      define _FPU_MASK_OM   0x200
#      define _FPU_MASK_UM   0x100
#      define _FPU_MASK_IM   0x80
#      define _FPU_RC_NEAREST   0
#      define _FPU_RC_ZERO   1
#      define _FPU_RESERVED   0xffc00000
#      define _FPU_DEFAULT   0x80000
#      define _FPU_IEEE   0x80f80
#      define _FPU_GETCW(cw)   asm ("sts fpscr, %0;" : "=r"(cw))
#      define _FPU_SETCW(cw)   asm ("lds %0, fpscr;" : : "r"(cw))
#      define __set_fpscr(cw)   asm ("lds %0, fpscr;" : : "r"(cw))
#   endif  // SH_FPU_ANY
#   define _FP_W_TYPE   unsigned long
#   define _FP_WS_TYPE   signed long
#   define _FP_I_TYPE   long
#   define FP_EX_INVALID   64
#   define FP_EX_DIVZERO   32
#   define FP_EX_OVERFLOW   16
#   define FP_EX_UNDERFLOW   8
#   define FP_EX_INEXACT   4
#   define _FP_TININESS_AFTER_ROUNDING   1
#elif defined(ARCHX86)
#   define _FPU_MASK_IM   1
#   define _FPU_MASK_DM   2
#   define _FPU_MASK_ZM   4
#   define _FPU_MASK_OM   8
#   define _FPU_MASK_UM   0x10
#   define _FPU_MASK_PM   0x20
#   define _FPU_EXTENDED   0x300
#   define _FPU_DOUBLE   0x200
#   define _FPU_SINGLE   0
#   define _FPU_RC_NEAREST  0
#   define _FPU_RC_DOWN   0x400
#   define _FPU_RC_UP   0x800
#   define _FPU_RC_ZERO   0xc00
#   define _FPU_RESERVED   0xf0c0
#   define _FPU_DEFAULT   0x37f
#   define _FPU_IEEE   0x37f
#   define FE_INEXACT   0x20
#   define FE_UNDERFLOW   0x10
#   define FE_OVERFLOW   8
#   define FE_DIVBYZERO   4
#   define FE_INVALID   1
#   define FE_TONEAREST   0
#   define FE_DOWNWARD   0x400
#   define FE_UPWARD   0x800
#   define FE_TOWARDZERO   0xc00
#   define FE_ALL_EXCEPT   (FE_INEXACT | FE_DIVBYZERO | FE_UNDERFLOW | FE_OVERFLOW | FE_INVALID)
#   define FE_ALL_RND   (FE_TONEAREST | FE_TOWARDZERO | FE_UPWARD | FE_DOWNWARD)
#   define DEFAULT_CONTROL   0x37f
#   define DEFAULT_STATUS    0
#   define DEFAULT_RESERVED   "\0\0\0\0\0\0\0"
#   define DEFAULT_MXCSR   0x1f80
#   define DEFAULT_MASK   (DEFAULT_MXCSR | 0x3f)
#   define MXCSR_PLUS_FZ_DAZ   (DEFAULT_MXCSR | 0x8040)
#   define _FPU_GETCW(cw)   vasm("fnstcw %0;" : "=m"(*&cw))
#   define _FPU_SETCW(cw)   vasm("fldcw %0;" : : "m"(*&cw))
#   define JMPBUFSP   0
#   define JMPBUFPC   1
#   define JMPBUFDPC   0
#   define FPPSGL   0
#   if (defined(ARCHX86) && (!defined(ARCHI386)))
#      define FPFTZ   0x8000
#      define FPINEX   0x1000
#      define FPUNFL   0x800
#      define FPOVFL   0x400
#      define FPZDIV   0x200
#      define FPDNRM   0x100
#      define FPINVAL   0x80
#      define FPDAZ   0x40
#      define FPRNR   0x0
#      define FPRZ   0x6000
#      define FPRPINF   0x4000
#      define FPRNINF   0x2000
#      define FPRMASK   0x6000
#      define FPPEXT   0
#      define FPPDBL   0
#      define FPPMASK   0
#      define FPAINEX   0x20
#      define FPAUNFL   0x10
#      define FPAOVFL   8
#      define FPAZDIV   4
#      define FPADNRM   2
#      define FPAINVAL   1
#   elif defined(ARCHI386)
#      define FPINEX   0x20
#      define FPUNFL   0x12
#      define FPOVFL   8
#      define FPZDIV   4
#      define FPINVAL   1
#      define FPRNR   0
#      define FPRZ   0xc00
#      define FPRPINF   0x800
#      define FPRNINF   0x400
#      define FPRMASK   0xc00
#      define FPPEXT   0x300
#      define FPPDBL   0x200
#      define FPPMASK   0x300
#      define FPAINEX   FPINEX
#      define FPAOVFL   FPOVFL
#      define FPAUNFL   FPUNFL
#      define FPAZDIV   FPZDIV
#      define FPAINVAL   FPINVAL
#   endif
#else
#   error   "Add FPU Control code for the target platform."
#endif
#ifndef _FPU_MASK_IM
#   define _FPU_MASK_IM   _FPU_MASK_I
#elif ((!defined(_FPU_MASK_I)) && defined(_FPU_MASK_IM))
#   define _FPU_MASK_I   _FPU_MASK_IM
#endif
#ifndef _FPU_MASK_ZM
#   define _FPU_MASK_ZM   _FPU_MASK_Z
#elif ((!defined(_FPU_MASK_Z)) && defined(_FPU_MASK_ZM))
#   define _FPU_MASK_Z   _FPU_MASK_ZM
#endif
#ifndef _FPU_MASK_OM
#   define _FPU_MASK_OM   _FPU_MASK_O
#elif ((!defined(_FPU_MASK_O)) && defined(_FPU_MASK_OM))
#   define _FPU_MASK_O   _FPU_MASK_OM
#endif
#ifndef _FPU_MASK_UM
#   define _FPU_MASK_UM   _FPU_MASK_U
#elif ((!defined(_FPU_MASK_U)) && defined(_FPU_MASK_UM))
#   define _FPU_MASK_U   _FPU_MASK_UM
#endif
#ifndef _FPU_MASK_PM
#   define _FPU_MASK_PM   _FPU_MASK_XM
#elif ((!defined(_FPU_MASK_XM)) && defined(_FPU_MASK_PM))
#   define _FPU_MASK_XM   _FPU_MASK_PM
#endif
#ifndef _FPU_RESERVED
/** These bits are reserved and not changed */
#   define _FPU_RESERVED   0xffffffff
#endif
#ifndef FPU_RESERVED
/** These bits are reserved and not changed */
#   define FPU_RESERVED   _FPU_RESERVED
#endif
#ifndef _FPU_DEFAULT
/** The fdlibm code requires no interrupts for exceptions */
#   define _FPU_DEFAULT   (0)
#endif
#ifndef FPU_DEFAULT
/** The fdlibm code requires no interrupts for exceptions */
#   define FPU_DEFAULT   _FPU_DEFAULT
#endif
#ifndef _FPU_GETCW
/** Get hardware control word */
#   define _FPU_GETCW(ctrlword)   ((ctrlword) = 0)
#endif
#ifndef FPU_GETCW
/** Get hardware control word */
#   define FPU_GETCW(ctrlword)   _FPU_GETCW((ctrlword))
#endif
#ifndef _FPU_SETCW
/** Set hardware control word */
#   define _FPU_SETCW(ctrlword)   ((void)(ctrlword))
#endif
#ifndef FPU_SETCW
/** Set hardware control word */
#   define FPU_SETCW(ctrlword)   _FPU_SETCW((ctrlword))
#endif
#ifndef HIGH_HALF
#   if IS_BIG_ENDIAN
#      define HIGH_HALF   0
#      define LOW_HALF   1
#   else
#      define HIGH_HALF   1
#      define LOW_HALF   0
#   endif
#endif
#define FP_CLS_NORMAL   0
#define FP_CLS_ZERO   1
#define FP_CLS_INF   2
#define FP_CLS_NAN   3
#define _FP_CLS_COMBINE(x, y)   (((x) << 2) | (y))
#define SI_BITS   (CHAR_BIT * (int)sizeof(SItype))
#define DI_BITS   (CHAR_BIT * (int)sizeof(DItype))
#define _FP_WORKBITS   3
#define _FP_WORK_LSB   ((_FP_W_TYPE)8)
#define _FP_WORK_ROUND   ((_FP_W_TYPE)4)
#define _FP_WORK_GUARD   ((_FP_W_TYPE)2)
#define _FP_WORK_STICKY   ((_FP_W_TYPE)1)

/** @} */  // }


// IEEE-754 & FLOAT-POINT DATATYPES

typedef union ieee754_remainder_double { int32_t i[2]; double x; }   ieee754_remainder_double;


#if BIG_ENDIAN
static const UNUSED ieee754_remainder_double _BIG = {{ 0x43380000, 0 }};  //!< 6755399441055744
static const UNUSED ieee754_remainder_double _T128 = {{ 0x47f00000, 0 }};  //!< 2^128
static const UNUSED ieee754_remainder_double _TM128 = {{ 0x37f00000, 0 }};  //!< 2^-128
static const UNUSED ieee754_remainder_double _ZERO = {{ 0, 0 }};  //!< 0.0
static const UNUSED ieee754_remainder_double _NZERO = {{ (int)0x80000000, 0 }};  //!< -0.0
#else  // LITTLE_ENDIAN
static const UNUSED ieee754_remainder_double _BIG = {{ 0, 0x43380000 }};  //!< 6755399441055744
static const UNUSED ieee754_remainder_double _T128 = {{ 0, 0x47f00000 }};  //!< 2^128
static const UNUSED ieee754_remainder_double _TM128 = {{ 0, 0x37f00000 }};  //!< 2^-128
static const UNUSED ieee754_remainder_double _ZERO = {{ 0, 0 }};  //!< 0.0
static const UNUSED ieee754_remainder_double _NZERO = {{ 0, (int)0x80000000 }};  //!< -0.0
#endif


/** A union that provides an IEEE-754 single-precision format and permits conversions between a float and various datatypes */
typedef union float_shape {
	float value;
	uint8_t bytes[4];
	uint16_t octets[2];
	int32_t sword;
	uint32_t uword;
#   if ((!defined(__MAVERICK__)) && (IS_BIG_ENDIAN || ((!defined(__VFP_FP__)) && (defined(ARCHARM) || defined(ARM_THUMB)))))
	struct float_shape_sparts { int16_t msw, lsw; } sparts;
	struct float_shape_parts { uint16_t msw, lsw; } parts;
#   else
	struct float_shape_sparts { int16_t lsw, msw; } sparts;
	struct float_shape_parts { uint16_t lsw, msw; } parts;
#   endif
#   if SUPPORTS_DECIMAL32
	decimal32 decword;
#   endif
	struct s754f_bits {
#   if IS_BIG_ENDIAN
		unsigned int sign:1;
		unsigned int exponent:8;
		unsigned int quiet:1;
		unsigned int significand:22;
#   else  // LITTLE_ENDIAN
		unsigned int significand:22;
		unsigned int quiet:1;
		unsigned int exponent:8;
		unsigned int sign:1;
#   endif
	} s;
	struct IEEEf_bits {
#   if IS_BIG_ENDIAN
		unsigned int sign:1;
		unsigned int exp:8;
		unsigned int man:23;
#   else  // LITTLE_ENDIAN
		unsigned int man:23;
		unsigned int exp:8;
		unsigned int sign:1;
#   endif
	} bits;
	struct ieee754f_bits {
#   if IS_BIG_ENDIAN
		unsigned int negative:1;
		unsigned int exponent:8;
		unsigned int mantissa:23;
#   else  // LITTLE_ENDIAN
		unsigned int mantissa:23;
		unsigned int exponent:8;
		unsigned int negative:1;
#   endif
	} ieee;
	struct ieee754f_nan_bits {  // This format makes it easier to see if a NaN is a signalling NaN
#   if IS_BIG_ENDIAN
		unsigned int negative:1;
		unsigned int exponent:8;
		unsigned int quiet_nan:1;
		unsigned int mantissa:22;
#   else  // LITTLE_ENDIAN
		unsigned int mantissa:22;
		unsigned int quiet_nan:1;
		unsigned int exponent:8;
		unsigned int negative:1;
#   endif
	} ieee_nan;
} float_shape_t;


/** A union that permits conversions between a double and various datatypes as well as access various parts of a double */
typedef union double_shape {
	double value;
	uint8_t bytes[8];
	uint16_t octets[4];
	int64_t sword;
	uint64_t uword;
#   if ((!defined(__MAVERICK__)) && (IS_BIG_ENDIAN || ((!defined(__VFP_FP__)) && (defined(ARCHARM) || defined(ARM_THUMB)))))
	struct double_shape_sparts { int32_t msw, lsw; } sparts;
	struct double_shape_parts { uint32_t msw, lsw; } parts;
#   else
	struct double_shape_sparts { int32_t lsw, msw; } sparts;
	struct double_shape_parts { uint32_t lsw, msw; } parts;
#   endif
#   if SUPPORTS_DECIMAL64
	decimal64 dec64word;
#   endif
	struct s754_bits {
#   if IS_BIG_ENDIAN
		unsigned int sign:1;
		unsigned int exponent:11;
		unsigned int quiet:1;
		uint64_t significand:51;
#   else  // LITTLE_ENDIAN
		uint64_t significand:51;
		unsigned int quiet:1;
		unsigned int exponent:11;
		unsigned int sign:1;
#   endif
	} s;
	struct IEEEd_bits {
#   if IS_BIG_ENDIAN
		unsigned int sign:1;
		unsigned int exp:11;
		unsigned int manh:20;
		unsigned int manl:32;
#   else  // LITTLE_ENDIAN
		unsigned int manl:32;
		unsigned int manh:20;
		unsigned int exp:11;
		unsigned int sign:1;
#   endif
	} bits;
	struct ieee754_bits {
#   if IS_BIG_ENDIAN
		unsigned int negative:1;
		unsigned int exponent:11;
		unsigned int mantissa0:20;
		unsigned int mantissa1:32;
#   else  // LITTLE_ENDIAN
		unsigned int mantissa1:32;
		unsigned int mantissa0:20;
		unsigned int exponent:11;
		unsigned int negative:1;
#   endif
	} ieee;
	struct ieee754_nan_bits {  // This format makes it easier to see if a NaN is a signalling NaN
#   if IS_BIG_ENDIAN
		unsigned int negative:1;
		unsigned int exponent:11;
		unsigned int quiet_nan:1;
		unsigned int mantissa0:19;
		unsigned int mantissa1:32;
#   else  // LITTLE_ENDIAN
		unsigned int mantissa1:32;
		unsigned int mantissa0:19;
		unsigned int quiet_nan:1;
		unsigned int exponent:11;
		unsigned int negative:1;
#   endif
	} ieee_nan;
} double_shape_t;


/** 80 bit MacOS float: 1 sign bit, 15 exponent bits, 1 integer bit, 63 fraction bits */
typedef struct Float80 {
#   if IS_BIG_ENDIAN
	int16_t exp;
	uint16_t man[4];
#   else
	uint16_t man[4];
	int16_t exp;
#   endif
} Float80;


/** 96 bit 68881 float: 1 sign bit, 15 exponent bits, 16 pad bits, 1 integer bit, 63 fraction bits */
typedef struct Float96 {
#   if IS_BIG_ENDIAN
	int16_t junk;
	int16_t exp;
	uint16_t man[4];
#   else
	uint16_t man[4];
	int16_t exp;
	int16_t junk;
#   endif
} Float96;


#if IS_LITTLE_ENDIAN
struct ld_half { uint64_t lo, hi; };
#else
struct ld_half { uint64_t hi, lo; };
#endif


#if SUPPORTS_LONG_DOUBLE


/** IEEE-854 quad-precision format union permiting conversions between a long double and various datatypes

On a PowerPC, a long double is implemented either as two doubles (with -mlong-double-128, the default) or as a single double (with -mlong-double-64, for Unix 2003 compliance). In a long double NaN, the value of the second double (if present) is ignored; Only the significand of the first double is used.

On IA-32, a long double has a different format, with an explicit integer bit in the significand.
*/
typedef union long_double_shape {
	long double value;
	uint8_t bytes[16];
	uint16_t octets[8];
	uint32_t words[4];
	struct ld_half i2;
#   if SUPPORTS_INT128
	int128_t sqword;
	uint128_t uqword;
#   endif
#   if IS_FLOAT_BIG_ENDIAN
	struct long_double_shape_uparts16 { uint16_t w0, w1, w2, w3, w4, w5, w6, w7; } uparts16;
	struct long_double_shape_sparts32 { int32_t w0, w1, w2, w3; } sparts32;
	struct long_double_shape_uparts32 { uint32_t w0, w1, w2, w3; } uparts32;
	struct long_double_shape_sparts64 { int64_t msw, lsw; } sparts64;
	struct long_double_shape_uparts64 { uint64_t msw, lsw; } uparts64;
#   elif IS_FLOAT_LITTLE_ENDIAN
	struct long_double_shape_uparts16 { uint16_t w7, w6, w5, w4, w3, w2, w1, w0; } uparts16;
	struct long_double_shape_sparts32 { int32_t w3, w2, w1, w0; } sparts32;
	struct long_double_shape_uparts32 { uint32_t w3, w2, w1, w0; } uparts32;
	struct long_double_shape_sparts64 { int64_t lsw, msw; } sparts64;
	struct long_double_shape_uparts64 { uint64_t lsw, msw; } uparts64;
#   else
#      error   "Unsupported system endian (long_double_shape_t)!"
#   endif
	float f[4];
	float_shape_t flts[4];
	double d[2];
	double_shape_t dbls[2];
#   if SUPPORTS_DECIMAL32
	decimal32 dec32[4];
#   endif
#   if SUPPORTS_DECIMAL64
	decimal64 dec64[2];
#   endif
#   if SUPPORTS_DECIMAL128
	decimal128 dec128word;
#   endif
#   ifdef ARCHPOWERPC
	struct attr_packed s854_bits {  // 128-bit float
#      if IS_BIG_ENDIAN
		unsigned int sign:1;
		unsigned int exponent:11;
		unsigned int quiet:1;
		uint64_t significand:51;
		double d;
#      else  // LITTLE_ENDIAN
		double d;
		uint64_t significand:51;
		unsigned int quiet:1;
		unsigned int exponent:11;
		unsigned int sign:1;
#      endif
	} s;
#      define LDBL_EXP_BITS   11
#   elif defined(ARCHARM)
	struct attr_packed s854_bits {  // 64-bit float
#      if IS_LITTLE_ENDIAN
		uint64_t significand:51;
		unsigned int quiet:1;
		unsigned int exponent:11;
		unsigned int sign:1;
#      else
		unsigned int sign:1;
		unsigned int exponent:11;
		unsigned int quiet:1;
		uint64_t significand:51;
#      endif
	} s;
#      define LDBL_EXP_BITS   11
#   elif defined(ARCHX86)
	struct attr_packed s854_bits {  // x87 96-bit float
#      if IS_BIG_ENDIAN
		unsigned int sign:1;
		unsigned int exponent:15;
		unsigned int integer:1;
		unsigned int quiet:1;
		uint64_t significand:62;
#      else  // LITTLE_ENDIAN
		uint64_t significand:62;
		unsigned int quiet:1;
		unsigned int integer:1;
		unsigned int exponent:15;
		unsigned int sign:1;
#      endif
		} s;
#      define LDBL_EXP_BITS   15
#   endif
	struct attr_packed ieee854_bits {  // 128-bit float
#      if IS_BIG_ENDIAN
		unsigned int negative:1;
		unsigned int exponent:15;
		unsigned int mantissa0:16;
		unsigned int mantissa1:32;
		unsigned int mantissa2:32;
		unsigned int mantissa3:32;
#      else  // LITTLE_ENDIAN
		unsigned int mantissa3:32;
		unsigned int mantissa2:32;
		unsigned int mantissa1:32;
		unsigned int mantissa0:16;
		unsigned int exponent:15;
		unsigned int negative:1;
#      endif
	} ieee;
	struct attr_packed ieee854_nan_bits {  // This format makes it easier to see if a NaN is a signalling NaN
#      if IS_BIG_ENDIAN
		unsigned int negative:1;
		unsigned int exponent:15;
		unsigned int quiet_nan:1;
		unsigned int mantissa0:15;
		unsigned int mantissa1:32;
		unsigned int mantissa2:32;
		unsigned int mantissa3:32;
#      else  // LITTLE_ENDIAN
		unsigned int mantissa3:32;
		unsigned int mantissa2:32;
		unsigned int mantissa1:32;
		unsigned int mantissa0:15;
		unsigned int quiet_nan:1;
		unsigned int exponent:15;
		unsigned int negative:1;
#      endif
	} ieee_nan;
} long_double_shape_t;


#endif


#if LDBL_EQ_FLOAT128


/** A union that permits conversions between a double and various datatypes */
typedef union float128_shape {
	double_shape_t dbls[2];
	float_shape_t flts[4];
	float128 flt128;
	long double value;
	uint8_t bytes[16];
	uint16_t octets[8];
	struct ld_half i2;
	struct ld_parts {
#   if IS_LITTLE_ENDIAN
		uint64_t lo;
		uint32_t m;
		uint16_t top, se;
#   else
		uint16_t se, top;
		uint32_t m;
		uint64_t lo;
#   endif
	} i;
#   if SUPPORTS_INT128
	int128_t shexlet;
	uint128_t uhexlet;
#   endif
#   if ((!defined(__MAVERICK__)) && (IS_BIG_ENDIAN || ((!defined(__VFP_FP__)) && (defined(ARCHARM) || defined(ARM_THUMB)))))
	struct float128_shape_sparts32 { int32_t w0, w1, w2, w3; } sparts32;
	struct float128_shape_uparts32 { uint32_t w0, w1, w2, w3; } uparts32;
	struct float128_shape_sparts { int64_t msw, lsw; } sparts;
	struct float128_shape_parts { uint64_t msw, lsw; } parts;
#   else
	struct float128_shape_sparts32 { int32_t w3, w2, w1, w0; } sparts32;
	struct float128_shape_uparts32 { uint32_t w3, w2, w1, w0; } uparts32;
	struct float128_shape_sparts { int64_t lsw, msw; } sparts;
	struct float128_shape_parts { uint64_t lsw, msw; } parts;
#   endif
#   if SUPPORTS_DECIMAL32
	decimal32 dec32[4];
#   endif
#   if SUPPORTS_DECIMAL64
	decimal64 dec64[2];
#   endif
#   if SUPPORTS_DECIMAL128
	decimal128 dec128word;
#   endif
	struct IEEEl_bits {
#   if IS_LITTLE_ENDIAN
		uint64_t manl:64;
		uint64_t manh:48;
		unsigned int exp:15;
		unsigned int sign:1;
#   else
		unsigned int sign:1;
		unsigned int exp:15;
		uint64_t manh:48;
		uint64_t manl:64;
#   endif
	} bits;
	struct ieee854_nan_bits ieee_nan;
} float128_shape_t;
#   define ldshape_t   float128_shape_t
#   define LDBL_NBIT   (0)
#   define mask_nbit_l(x)   ((void)0)
#   define LDBL_MANH_SIZE   (48)
#   define LDBL_MANL_SIZE   (64)
#   define LDBL_TO_ARRAY32(LDBL_NUM, val32)   do { (val32)[0] = (uint32_t)(LDBL_NUM).bits.manl; (val32)[1] = (uint32_t)(LDBL_NUM).bits.manh; } while (0x0)


#elif IS_LDBL_X87


/** IEEE2bits for long double; This is used to access various parts of a long double */
typedef union IEEEl2bits {
	long double value;
	long double e;
	double dbl;
	float_shape_t flts[3];
	uint8_t bytes[12];
	uint16_t octets[6];
#   if SUPPORTS_DECIMAL32
	decimal32 dec32[3];
#   endif
#   if SUPPORTS_DECIMAL64
	decimal64 dec64;
#   endif
	struct ld_parts {
#   if IS_LITTLE_ENDIAN
		uint64_t m;
		uint16_t se;
#   else
		uint16_t se;
		uint64_t m;
#   endif
	} i;
	struct IEEEl_bits {
#   if IS_LITTLE_ENDIAN
		unsigned int manl:32;
		unsigned int manh:32;
		unsigned int exp:15;
		unsigned int sign:1;
		unsigned int junk:16;
#   else
		unsigned int junk:16;
		unsigned int sign:1;
		unsigned int exp:15;
		unsigned int manh:32;
		unsigned int manl:32;
#   endif
	} bits;
} alignXF   ldshape_t;
#   define mask_nbit_l(x)   ((x).bits.manh &= 0x7fffffff)
#   define LDBL_MANH_SIZE   (32)
#   define LDBL_MANL_SIZE   (32)
#   define LDBL_TO_ARRAY32(LDBL_NUM, val32)   do { (val32)[0] = (uint32_t)(LDBL_NUM).bits.manl; (val32)[1] = (uint32_t)(LDBL_NUM).bits.manh; } while (0x0)


#elif LDBL_EQ_DBL


/** IEEE2bits for long double; This is used to access various parts of a long double */
typedef union IEEEl2bits {
	double d;
	long double value;
	struct ld_half i2;
#   if SUPPORTS_DECIMAL32
	decimal32 dec32[4];
#   endif
#   if SUPPORTS_DECIMAL64
	decimal64 dec64[2];
#   endif
	struct s754_bits {
#   if IS_BIG_ENDIAN
		unsigned int sign:1;
		unsigned int exponent:11;
		unsigned int quiet:1;
		uint64_t significand:51;
#   else  // LITTLE_ENDIAN
		uint64_t significand:51;
		unsigned int quiet:1;
		unsigned int exponent:11;
		unsigned int sign:1;
#   endif
	} s;
	struct IEEEd_bits {
#   if IS_BIG_ENDIAN
		unsigned int sign:1;
		unsigned int exp:11;
		unsigned int manh:20;
		unsigned int manl:32;
#   else  // LITTLE_ENDIAN
		unsigned int manl:32;
		unsigned int manh:20;
		unsigned int exp:11;
		unsigned int sign:1;
#   endif
	} bits;
	struct ieee754_bits {
#   if IS_BIG_ENDIAN
		unsigned int negative:1;
		unsigned int exponent:11;
		unsigned int mantissa0:20;
		unsigned int mantissa1:32;
#   else  // LITTLE_ENDIAN
		unsigned int mantissa1:32;
		unsigned int mantissa0:20;
		unsigned int exponent:11;
		unsigned int negative:1;
#   endif
	} ieee;
	struct ieee754_nan_bits {  // This format makes it easier to see if a NaN is a signalling NaN
#   if IS_BIG_ENDIAN
		unsigned int negative:1;
		unsigned int exponent:11;
		unsigned int quiet_nan:1;
		unsigned int mantissa0:19;
		unsigned int mantissa1:32;
#   else  // LITTLE_ENDIAN
		unsigned int mantissa1:32;
		unsigned int mantissa0:19;
		unsigned int quiet_nan:1;
		unsigned int exponent:11;
		unsigned int negative:1;
#   endif
	} ieee_nan;
	struct ld_parts {
#   if IS_LITTLE_ENDIAN
		unsigned int lo:32;
		unsigned int m:20;
		unsigned int top:11;
		unsigned int se:1;
#   else
		unsigned int se:1;
		unsigned int top:11;
		unsigned int m:20;
		unsigned int lo:32;
#   endif
	} i;
} ldshape_t;
#   define LDBL_NBIT   (0)
#   define mask_nbit_l(x)   ((void)0)
#   define LDBL_MANH_SIZE   (20)
#   define LDBL_MANL_SIZE   (32)
#   define LDBL_TO_ARRAY32(LDBL_NUM, val32)   do { (val32)[0] = (uint32_t)(LDBL_NUM).bits.manl; (val32)[1] = (uint32_t)(LDBL_NUM).bits.manh; } while (0x0)


#else
#   error   "Unsupported long double representation!"
#endif


#if SUPPORTS_FLOAT256
/** A union that permits conversions between a float256 and various datatypes */
typedef union float256_shape {
	float256 value;
	uint8_t bytes[32];
	uint16_t octets[16];
	uint32_t words[8];
	double_shape_t value[4];
	float_shape_t flts[8];
	float128_shape_t flt128s[2];
#   if (IS_LITTLE_ENDIAN && SUPPORTS_INT128)
	struct flt256_half { uint128_t lo, hi; } i2;
#   else
	struct flt256_half { uint128_t hi, lo; } i2;
#   endif
#   if SUPPORTS_INT256
	int256_t swhole;
	uint256_t uwhole;
#   endif
#   if ((!defined(__MAVERICK__)) && (IS_BIG_ENDIAN || ((!defined(__VFP_FP__)) && (defined(ARCHARM) || defined(ARM_THUMB)))))
	struct float256_shape_sparts64 { int64_t w0, w1, w2, w3; } sparts64;
	struct float256_shape_uparts64 { uint64_t w0, w1, w2, w3; } uparts64;
#      if SUPPORTS_INT128
	struct float256_shape_sparts { int128_t msw, lsw; } sparts;
	struct float256_shape_parts { uint128_t msw, lsw; } parts;
#      endif
#   else
	struct float256_shape_sparts64 { int64_t w3, w2, w1, w0; } sparts64;
	struct float256_shape_uparts64 { uint64_t w3, w2, w1, w0; } uparts64;
#      if SUPPORTS_INT128
	struct float256_shape_sparts { int128_t lsw, msw; } sparts;
	struct float256_shape_parts { uint128_t lsw, msw; } parts;
#      endif
#   endif
#   if SUPPORTS_DECIMAL32
	decimal32 dec32[8];
#   endif
#   if SUPPORTS_DECIMAL64
	decimal64 dec64[4];
#   endif
#   if SUPPORTS_DECIMAL128
	decimal128 dec128[2];
#   endif
} float256_shape_t;
#endif


#if (SUPPORTS_COMPLEX && IS_NOT_LINTER)


/** Datatype used to convert between a complex float and various datatypes */
typedef union complex_float_shape {
	complex_float value;
	uint8_t bytes[8];
	uint16_t octets[4];
	int64_t sword;
	uint64_t uword;
	double_shape_t dbl;
#   if ((!defined(__MAVERICK__)) && (IS_BIG_ENDIAN || ((!defined(__VFP_FP__)) && (defined(ARCHARM) || defined(ARM_THUMB)))))
	struct complex_float_shape_sparts { int32_t re, im; } sparts;
	struct complex_float_shape_uparts { uint32_t re, im; } uparts;
	struct complex_float_shape_floats { float_shape_t re, im; } floats;
#      if SUPPORTS_DECIMAL_FLOATS
	struct complex_float_shape_decfloats { decimal32 re, im; } decfloats;
#      endif
#   else
	struct complex_float_shape_sparts { int32_t im, re; } sparts;
	struct complex_float_shape_uparts { uint32_t im, re; } uparts;
	struct complex_float_shape_floats { float_shape_t im, re; } floats;
#      if SUPPORTS_DECIMAL_FLOATS
	struct complex_float_shape_decfloats { decimal32 im, re; } decfloats;
#      endif
#   endif
} complex_float_shape_t;


/** Datatype used to convert between a complex double and various datatypes */
typedef union complex_double_shape {
	complex_double value;
	uint8_t bytes[16];
	uint16_t octets[8];
	int32_t swords[4];
	uint32_t uwords[4];
	float_shape_t flts[4];
	double_shape_t dbls[2];
	long_double_shape_t ldbl;
#   if SUPPORTS_INT128
	int128_t swhole;
	uint128_t uwhole;
#   endif
#   if ((!defined(__MAVERICK__)) && (IS_BIG_ENDIAN || ((!defined(__VFP_FP__)) && (defined(ARCHARM) || defined(ARM_THUMB)))))
	struct complex_double_shape_sparts { int64_t re, im; } sparts;
	struct complex_double_shape_uparts { uint64_t re, im; } uparts;
	struct complex_double_shape_doubles { double_shape_t re, im; } doubles;
#      if SUPPORTS_DECIMAL_FLOATS
	struct complex_double_shape_decfloats { decimal64 re, im; } decfloats;
#      endif
#   else
	struct complex_double_shape_sparts { int64_t im, re; } sparts;
	struct complex_double_shape_uparts { uint64_t im, re; } uparts;
	struct complex_double_shape_doubles { double_shape_t im, re; } doubles;
#      if SUPPORTS_DECIMAL_FLOATS
	struct complex_double_shape_decfloats { decimal64 im, re; } decfloats;
#      endif
#   endif
} complex_double_shape_t;


#endif  // SUPPORTS_COMPLEX


#if SUPPORTS_COMPLEX_LDBL
/** Datatype used to convert between a complex long double and various datatypes */
typedef union complex_long_double_shape {
	complex_long_double value;
	uint8_t bytes[32];
	uint16_t octets[16];
	int32_t swords[8];
	uint32_t uwords[8];
	int64_t sdwords[4];
	uint64_t udwords[4];
	float_shape_t flts[8];
	double_shape_t dbls[4];
#   if SUPPORTS_INT256
	int256_t swhole;
	uint256_t uwhole;
#   endif
#   if ((!defined(__MAVERICK__)) && (IS_BIG_ENDIAN || ((!defined(__VFP_FP__)) && (defined(ARCHARM) || defined(ARM_THUMB)))))
#      if SUPPORTS_INT128
	struct complex_long_double_shape_sparts { int128_t re, im; } sparts;
	struct complex_long_double_shape_uparts { uint128_t re, im; } uparts;
#      endif
	struct complex_long_double_shape_longdoubles { long_double_shape_t re, im; } longdoubles;
#      if SUPPORTS_DECIMAL128
	struct complex_long_double_shape_decfloats { decimal128 re, im; } decfloats;
#      endif
#   else
#      if SUPPORTS_INT128
	struct complex_long_double_shape_sparts { int128_t im, re; } sparts;
	struct complex_long_double_shape_uparts { uint128_t im, re; } uparts;
#      endif
	struct complex_long_double_shape_longdoubles { long_double_shape_t im, re; } longdoubles;
#      if SUPPORTS_DECIMAL128
	struct complex_long_double_shape_decfloats { decimal128 im, re; } decfloats;
#      endif
#   endif
} complex_long_double_shape_t;
#endif  // SUPPORTS_COMPLEX_LDBL


// FLOAT-POINT CONVERSIONS

/** Convert a float to uint32_t */
#define FLT_TO_U32(x)   __extension__ ({ const float_shape_t FLT_TO_U32_tmp = { .value = x }; (uint32_t)FLT_TO_U32_tmp.uword; })
/** Convert a float to uint32_t */
#define float2u32(x)   FLT_TO_U32((x))
/** Convert a float to uint32_t */
#define float2uint32(x)   FLT_TO_U32((x))
/** Convert a uint32_t to float */
#define U32_TO_FLT(x)   __extension__ ({ const float_shape_t U32_TO_FLT_tmp = { .uword = x }; (float)U32_TO_FLT_tmp.value; })
#if SUPPORTS_DECIMAL32
/** Convert a float to a decimal32 */
#   define FLT_TO_DEC32(x)   __extension__ ({ const float_shape_t FLT_TO_DEC32_tmp = { .value = x }; (decimal32)FLT_TO_DEC32_tmp.decword; })
/** Convert a decimal32 to a float */
#   define DEC32_TO_FLT(x)   __extension__ ({ const float_shape_t DEC32_TO_FLT_tmp = { .decword = x }; (decimal32)DEC32_TO_FLT_tmp.value; })
/** Convert a uint32_t to a decimal32 */
#   define U32_TO_DEC32(x)   __extension__ ({ const float_shape_t U32_TO_DEC32_tmp = { .uword = x }; (decimal32)U32_TO_DEC32_tmp.decword; })
/** Convert a decimal32 to a uint32_t */
#   define DEC32_TO_U32(x)   __extension__ ({ const float_shape_t DEC32_TO_U32_tmp = { .decword = x }; (uint32_t)DEC32_TO_U32_tmp.uword; })
#endif
/** Convert a double to uint64_t */
#define DBL_TO_U64(x)   __extension__ ({ const double_shape_t DBL_TO_U64_tmp = { .value = x }; (uint64_t)DBL_TO_U64_tmp.uword; })
/** Convert a uint64_t to double */
#define U64_TO_DBL(x)   __extension__ ({ const double_shape_t U64_TO_DBL_tmp = { .uword = x }; (double)U64_TO_DBL_tmp.value; })
#define float32_to_float16(x)   (((((x) & 0x7fffffff) >> 13) - 0x1c000) | ((((x) & 0x80000000) >> 16)))
#if SUPPORTS_DECIMAL64
/** Convert a double to a decimal64 */
#   define DBL_TO_DEC64(x)   __extension__ ({ const double_shape_t DBL_TO_DEC64_tmp = { .value = x }; (decimal64)DBL_TO_DEC64_tmp.dec64word; })
/** Convert a decimal64 to a double */
#   define DEC64_TO_DBL(x)   __extension__ ({ const double_shape_t DEC64_TO_DBL_tmp = { .dec64word = x }; (decimal64)DEC64_TO_DBL_tmp.value; })
/** Convert a uint64_t to a decimal64 */
#   define U64_TO_DEC64(x)   __extension__ ({ const double_shape_t U64_TO_DEC64_tmp = { .uword = x }; (decimal64)U64_TO_DEC64_tmp.dec64word; })
/** Convert a decimal64 to a uint64_t */
#   define DEC64_TO_U64(x)   __extension__ ({ const double_shape_t DEC64_TO_U64_tmp = { .dec64word = x }; (uint64_t)DEC64_TO_U64_tmp.uword; })
#endif
#if SUPPORTS_INT128
/** Convert a long double to a int128_t */
#   define LDBL_TO_INT128(x)   __extension__ ({ const long_double_shape_t LDBL_TO_INT128_tmp = { .value = x }; (int128_t)LDBL_TO_INT128_tmp.sqword; })
/** Convert a long double to a uint128_t */
#   define LDBL_TO_UINT128(x)   __extension__ ({ const long_double_shape_t LDBL_TO_UINT128_tmp = { .value = x }; (uint128_t)LDBL_TO_UINT128_tmp.uqword; })
/** Convert a long double to a uint128_t */
#   define LDBL_TO_U128(x)   LDBL_TO_UINT128((x))
/** Convert a int128_t to a long double */
#   define INT128_TO_LDBL(x)   __extension__ ({ const long_double_shape_t INT128_TO_LDBL_tmp = { .sqword = x }; (long double)INT128_TO_LDBL_tmp.value; })
/** Convert a uint128_t to a long double */
#   define UINT128_TO_LDBL(x)   __extension__ ({ const long_double_shape_t UINT128_TO_LDBL_tmp = { .uqword = x }; (long double)UINT128_TO_LDBL_tmp.value; })
#endif
#if SUPPORTS_COMPLEX
/** Convert a complex float to uint64_t */
#   define CFLT_TO_U64(x)   __extension__ ({ const complex_float_shape_t CFLT_TO_U64_tmp = { .value = x }; (uint64_t)CFLT_TO_U64_tmp.uword; })
/** Convert a uint64_t to complex float */
#   define U64_TO_CFLT(x)   __extension__ ({ const complex_float_shape_t U64_TO_CFLT_tmp = { .uword = x }; (double)U64_TO_CFLT_tmp.value; })
#endif


// FLOAT OPERATIONS MACROS

// 32-bit float
/** Return `1` if the float is signed (otherwise, `0`) */
#define SIGNF(fp)   __extension__ ({ const float_shape_t __union_float = { .value = (float)fp }; __union_float.ieee.negative; })
/** Return the exponent of a float */
#define EXPF(fp)   __extension__ ({ const float_shape_t __union_float = { .value = (float)fp }; __union_float.ieee.exponent; })
/** Return the mantissa of a float */
#define MANTF(fp)   __extension__ ({ const float_shape_t __union_float = { .value = (float)fp }; __union_float.ieee.mantissa; })
/** Create a float-point value manually using unsigned integers */
#define PACKF(s, e, m)   __extension__ ({ const float_shape_t __union_float = { .ieee.negative = (unsigned int)s, .ieee.exponent = (unsigned int)e, .ieee.mantissa = (unsigned int)m }; __union_float.value; })
/** Set the mantissa of a float to `mant` */
#define SET_MANTISSA_FLOAT(flt, mant)   do { float_shape_t u = { .value = (float)(flt) }; u.ieee.mantissa = (((mant & 0x7fffff) == 0) ? 0x400000 : ((mant) & 0x7fffff)); (flt) = u.value; } while (0x0)
#ifdef ARCHX86
/** Direct movement of float into integer register */
#   define GET_FLOAT_WORD(i, d)   do { int i_; asm (MOVD " %1, %0" : "=rm"(i_) : "x"((float)(d))); i = i_; } while (0x0)
/** Direct movement of float into integer register */
#   define GET_FLOAT_UWORD(i, d)   do { unsigned int i_; asm (MOVD " %1, %0" : "=rm"(i_) : "x"((float)(d))); i = i_; } while (0x0)
#   define SET_FLOAT_WORD(f, i)   do { unsigned int i_ = i; float f__; asm (MOVD " %1, %0" : "=x"(f__) : "rm"(i_)); f = f__; } while (0x0)
#   define SET_FLOAT_SWORD(f, i)   do { signed int i_ = i; float f__; asm (MOVD " %1, %0" : "=x"(f__) : "rm"(i_)); f = f__; } while (0x0)
/** Direct movement of float into integer register */
#   define EXTRACT_WORDS64(i, d)   do { int64_t i_; asm (MOVQ " %1, %0" : "=rm"(i_) : "x"((double)(d))); i = i_; } while (0x0)
#   define INSERT_WORDS64(d, i)   do { int64_t i_ = i; double d__; asm (MOVQ " %1, %0" : "=x"(d__) : "rm"(i_)); d = d__; } while (0x0)
#else
/** Get a 32-bit int from a float */
#   define GET_FLOAT_WORD(i, d)   do { const float_shape_t gf_s = { .value = (d) }; i = gf_s.sword; } while (0x0)
#   define GET_FLOAT_UWORD(i, d)   do { const float_shape_t gf_u = { .value = (d) }; i = gf_u.uword; } while (0x0)
/** Set a float from a 32-bit int */
#   define SET_FLOAT_WORD(d, i)   do { const float_shape_t sf_u = { .uword = (uint32_t)(i) }; d = (float)sf_u.value; } while (0x0)
#   define SET_FLOAT_SWORD(d, i)   do { const float_shape_t sf_s = { .sword = (int32_t)(i) }; d = (float)sf_s.value; } while (0x0)
/** Direct movement of float into integer register */
#   define EXTRACT_WORDS64(i, d)   do { const double_shape_t ew_u = { .value = (double)(d) }; i = ew_u.sword; } while (0x0)
#   define INSERT_WORDS64(d, i)   do { const double_shape_t ew_u = { .sword = (int64_t)(i) }; d = ew_u.value; } while (0x0)
#endif  // X86_64
/** Get a 32-bit signed int from a float */
#define GET_FLOAT_SWORD(i, d)   GET_FLOAT_WORD((i), (d))
#define GET_FLOAT_SIGNED_WORD(i, d)   GET_FLOAT_WORD((i), (d))
#define SET_FLOAT_UWORD(f, i)   SET_FLOAT_WORD((f), (i))
/** Swap the high and low 16-bits of a float */
#define SWAP_FLOAT_HALFS(d)   do { float_shape_t _swap_flt = { .value = (float)(d) }; register const float tmpmvar = _swap_flt.parts.lsw; _swap_flt.parts.lsw = _swap_flt.parts.msw; _swap_flt.parts.msw = tmpmvar; d = _swap_flt.value; } while (0x0)
/** Return true if the implict significand bit is set */
#define is_implicit_set_flt(fp)   (EXPF(fp) ? 0 : 1)

// 64-bit float
#define DBL_ADJ   (DBL_MAX_EXP - 2 + ((DBL_MANT_DIG - 1) % 4))
/** Return `1` if the double is signed (otherwise, `0`) */
#define SIGND(fp)   __extension__ ({ const double_shape_t __union_double = { .value = (double)fp }; __union_double.ieee.negative; })
/** Return the exponent of a double */
#define EXPD(fp)   __extension__ ({ const double_shape_t __union_double = { .value = (double)fp }; __union_double.ieee.exponent; })
/** Return the mantissa of a double */
#define MANTD(fp)   __extension__ ({ const double_shape_t __union_double = { .value = (double)fp }; (((((__union_double.ieee.mantissa0) & 0xfffff) | HIDDEND) << 10) | (__union_double.ieee.mantissa1 >> 22)); })
/** Create a double manually using unsigned integers */
#define PACKD(s, e, m0, m1)   __extension__ ({ const double_shape_t __union_double = { .ieee.negative = (unsigned int)s, .ieee.exponent = (unsigned int)e, .ieee.mantissa0 = (unsigned int)m0, .ieee.mantissa1 = (unsigned int)m1 }; __union_double.f; })
#define SET_MANTISSA_DOUBLE(flt, mant)   do { double_shape_t u = { .value = (double)(flt) }; u.ieee_nan.mantissa0 = ((mant) >> 32); u.ieee_nan.mantissa1 = (mant); if ((u.ieee.mantissa0 | u.ieee.mantissa1) != 0) { flt = u.d; } } while (0x0)
/** Get two 32-bit ints from a double */
#define EXTRACT_WORDS(ix0, ix1, d)   do { const double_shape_t ew_u = { .value = (double)(d) }; ix0 = ew_u.parts.msw; ix1 = ew_u.parts.lsw; } while (0x0)
/** Get two 32-bit ints from a double */
#define EXTRACT_UWORDS(ix0, ix1, d)   do { const double_shape_t ew_uint = { .value = (double)(d) }; ix0 = (uint32_t)ew_uint.parts.msw; ix1 = (uint32_t)ew_uint.parts.lsw; } while (0x0)
/** Get two 32-bit signed ints from a double */
#define EXTRACT_SIGNED_WORDS(ix0, ix1, d)   do { const double_shape_t ew_s= { .value = (double)(d) }; ix0 = ew_s.sparts.msw; ix1 = ew_s.sparts.lsw; } while (0x0)
/** Get two 32-bit ints from a double */
#define EXTRACT_SWORDS(ix0, ix1, d)   EXTRACT_SIGNED_WORDS((ix0), (ix1), (d))
/** Get the more significant 32-bit int from a double */
#define GET_HIGH_WORD(i, d)   do { const double_shape_t gh_u = { .value = (double)(d) }; i = gh_u.parts.msw; } while (0x0)
/** Get the more significant 32-bit signed int from a double */
#define GET_HIGH_SIGNED_WORD(i, d)   do { const double_shape_t gh_s = { .value = (double)(d) }; i = gh_s.sparts.msw; } while (0x0)
/** Get the more significant 32-bit signed int from a double */
#define GET_HIGH_SWORD(i, d)   GET_HIGH_SIGNED_WORD((i), (d))
/** Get the less significant 32-bit int from a double */
#define GET_LOW_WORD(i, d)   do { const double_shape_t gl_u = { .value = (double)(d) }; i = gl_u.parts.lsw; } while (0x0)
/** Get the less significant 32-bit signed int from a double */
#define GET_LOW_SIGNED_WORD(i, d)   do { const double_shape_t gl_s = { .value = (double)(d) }; i = gl_s.sparts.lsw; } while (0x0)
/** Get the less significant 32-bit signed int from a double */
#define GET_LOW_SWORD(i, d)   GET_LOW_SIGNED_WORD((i), (d))
/** Get the more significant uint32_t from a double */
#define get_dbl_high_uword(d)   __extension__ ({ const double_shape_t gh_u = { .value = (double)(d) }; gh_u.parts.msw; })
/** Get the more significant int32_t from a double */
#define get_dbl_high_sword(d)   __extension__ ({ const double_shape_t gh_s = { .value = (double)(d) }; gh_s.sparts.msw; })
/** Get the less significant uint32_t from a double */
#define get_dbl_low_uword(d)   __extension__ ({ const double_shape_t gl_u = { .value = (double)(d) }; gl_u.parts.lsw; })
/** Get the less significant int32_t from a double */
#define get_dbl_low_sword(d)   __extension__ ({ const double_shape_t gl_s = { .value = (double)(d) }; gl_s.sparts.lsw; })
/** Set a double from two 32-bit ints */
#define INSERT_WORDS(d, ix0, ix1)   do { const double_shape_t iw_u = { .parts.msw = (ix0), .parts.lsw = (ix1) }; d = iw_u.value; } while (0x0)
/** Set the more significant 32-bits of a double from an int */
#define SET_HIGH_WORD(d, v)   do { double_shape_t sh_u = { .value = (double)(d) }; sh_u.parts.msw = (uint32_t)(v); d = sh_u.value; } while (0x0)
/** Set the less significant 32 bits of a double from an int */
#define SET_LOW_WORD(d, v)   do { double_shape_t sl_u = { .value = (double)(d) }; sl_u.parts.lsw = (uint32_t)(v); d = sl_u.value; } while (0x0)
/** Swap the high and low 32-bits of a double */
#define SWAP_DOUBLE_HALFS(d)   do { double_shape_t _swap_dbl = { .value = (double)(d) }; register const double tmpmvar = _swap_dbl.parts.lsw; _swap_dbl.parts.lsw = _swap_dbl.parts.msw; _swap_dbl.parts.msw = tmpmvar; d = _swap_dbl.value; } while (0x0)
/** Return true if the implict significand bit is set */
#define is_implicit_set_dbl(fp)   (EXPD(fp) ? 0 : 1)

// 128-bit float
#define LDBL_ADJ   (LDBL_MAX_EXP - 2 + ((LDBL_MANT_DIG - 1) % 4))
/** Return `1` if the long double is signed (otherwise, `0`) */
#define SIGNL(fp)   __extension__ ({ const long_double_shape_t __union_long_double = { .value = (long double)fp }; __union_long_double.ieee.negative; })
/** Return the exponent of a long double */
#define EXPL(fp)   __extension__ ({ const long_double_shape_t __union_long_double = { .value = (long double)fp }; __union_long_double.ieee.exponent; })
/** Return the mantissa of a long double */
#define MANTL(fp)   ((fp & (HIDDEND_LL - 1)) | HIDDEND_LL)
/** Return the mantissa of a long double */
#define MANTD_LL(fp)   MANTL(fp)
/** Create a long double manually using unsigned integers */
#define PACKD_LL(s, e, m0, m1, m2, m3)   __extension__ ({ const long_double_shape_t __union_long_double = { .ieee.negative = (unsigned int)s, .ieee.exponent = (unsigned int)e, .ieee.mantissa0 = (unsigned int)m0, .ieee.mantissa1 = (unsigned int)m1, .ieee.mantissa2 = (unsigned int)m2, .ieee.mantissa3 = (unsigned int)m3 }; __union_long_double.value; })
/** Get two 64 bit ints from a long double */
#define GET_LDOUBLE_WORDS64(ix0, ix1, d)   do { const long_double_shape_t qw_gu = { .value = (long double)(d) }; (ix0) = qw_gu.uparts64.msw; (ix1) = qw_gu.uparts64.lsw; } while (0x0)
/** Get two signed 64 bit ints from a long double */
#define GET_LDOUBLE_SWORDS64(ix0, ix1, d)   do { const long_double_shape_t qw_gs = { .value = (long double)(d) }; (ix0) = qw_gs.sparts64.msw; (ix1) = qw_gs.sparts64.lsw; } while (0x0)
/** Get the MSW (64-bit int) from a long double */
#define GET_LDOUBLE_WORDS64_MSW(ix0, d)   do { const long_double_shape_t qw_mu = { .value = (long double)(d) }; (ix0) = qw_mu.uparts64.msw; } while (0x0)
/** Set a long double from two 64-bit ints */
#define SET_LDOUBLE_WORDS64(d, ix0, ix1)   do { const long_double_shape_t qw_su = { .uparts64.msw = (uint64_t)(ix0), .uparts64.lsw = (uint64_t)(ix1) }; (d) = qw_su.value; } while (0x0)
/** Get the more significant 64 bits of a long double mantissa */
#define GET_LDOUBLE_MSW64(v, d)   do { const long_double_shape_t sh_u = { .value = (long double)(d) }; (v) = sh_u.uparts64.msw; } while (0x0)
/** Get the more significant 64 bits (signed) of a long double mantissa */
#define GET_LDOUBLE_MSW64S(v, d)   do { const long_double_shape_t sh_s = { .value = (long double)(d) }; (v) = sh_s.sparts64.msw; } while (0x0)
/** Set the more significant 64 bits of a long double mantissa from an int */
#define SET_LDOUBLE_MSW64(d, v)   do { long_double_shape_t sh_u = { .value = (long double)(d) }; sh_u.uparts64.msw = (uint64_t)((v)); ((d)) = sh_u.value; } while (0x0)
/** Get the least significant 64 bits of a long double mantissa */
#define GET_LDOUBLE_LSW64(v, d)   do { const long_double_shape_t lsw_u = { .value = (long double)(d) }; (v) = lsw_u.uparts64.lsw; } while (0x0)
/** Get the least significant 64 bits (signed) of a long double mantissa */
#define GET_LDOUBLE_LSW64S(v, d)   do { const long_double_shape_t lsw_s = { .value = (long double)(d) }; (v) = lsw_s.sparts64.lsw; } while (0x0)


// NAN (<bits/nan.h>)

// NAN float8
#if SUPPORTS_FLOAT8
#   ifndef NAN8
typedef union union_NAN8 { unsigned char __c; float8 __f; }   __NAN8_t;
#      define __NAN8_bytes   (unsigned char)0x7c  // 0b01111100
static const UNUSED __NAN8_t __nan8 = __NAN8_bytes;
/** float8 IEEE Not A Number (NAN8) */
#      define NAN8   (float8)(__nan8.__f)
#   endif  // NAN8
#   ifndef SNAN8
typedef union union_SNAN8 { unsigned char __c; float8 __f; }   __SNAN8_t;
#      define __SNAN8_bytes   (unsigned char)0x7d  // 0b01111101
static const UNUSED __SNAN8_t __snan8 = __SNAN8_bytes;
/** float8 IEEE Signalling Not A Number (SNAN) */
#      define SNAN8   (float8)(__snan8.__f)
#   endif  // SNAN8
/** float8 IEEE Quiet Not A Number (QNAN8) */
#   define QNAN8   NAN8
#endif
// NAN float16
#if SUPPORTS_FLOAT16
#   ifndef NAN16
typedef union union_NAN16 { unsigned char __c[2]; float16 __f; }   __NAN16_t;
#      if IS_BIG_ENDIAN
#         define __NAN16_bytes   { 0x7e, 0x0 }  // 0b0111111000000000
#      elif IS_LITTLE_ENDIAN
#         define __NAN16_bytes   { 0x0, 0x7e }
#      endif
static const UNUSED __NAN16_t __nan16 = { __NAN16_bytes };
/** float16 IEEE Not A Number (NAN) */
#      define NAN16   (float16)(__nan16.__f)
#   endif  // NAN16
#   ifndef SNAN16
typedef union union_SNAN16 { unsigned char __c[2]; float16 __f; }   __SNAN16_t;
#      if IS_BIG_ENDIAN
#         define __SNAN16_bytes   { 0x7e, 0x1 }  // 0b0111111000000001
#      elif IS_LITTLE_ENDIAN
#         define __SNAN16_bytes   { 0x1, 0x7e }
#      endif
static const UNUSED __SNAN16_t __snan16 = { __SNAN16_bytes };
/** float16 IEEE Signalling Not A Number (SNAN) */
#      define SNAN16   (float16)(__snan16.__f)
#   endif  // SNAN16
/** float16 IEEE Quiet Not A Number (QNAN) */
#   define QNAN16   NAN16
#endif
// NAN float
#ifndef NANF
#   if IS_BIG_ENDIAN
#      define __NANF_bytes   { 0x7f, 0xc0, 0x0, 0x0 }
#   elif IS_LITTLE_ENDIAN
#      define __NANF_bytes   { 0x0, 0x0, 0xc0, 0x7f }
#   endif
static const UNUSED float_shape_t __nanf = { .bytes = __NANF_bytes };
/** IEEE Not A Number (NAN) */
#   define NANF   (__nanf.value)  // 0x7fc00000 || 0b01111111110000000000000000000000
#endif  // NANF
#ifndef NANSF
#   if IS_BIG_ENDIAN
#      define __NANSF_bytes   { 0x7f, 0xc0, 0x0, 0x1 }
#   elif IS_LITTLE_ENDIAN
#      define __NANSF_bytes   { 0x1, 0x0, 0xc0, 0x7f }
#   endif
static const UNUSED float_shape_t __nansf = { .bytes = __NANSF_bytes };
/** Signaling IEEE Not A Number (NANS) */
#   define NANSF   (__nansf.value)  // 0x7fc00001
#endif  // NANSF
#define FLT_SNAN   NANSF
#define FLT_NANS   NANSF
#define SNANF   NANSF
#define __QNANF   NANF
#define QNANF   NANF
#define z_notanum_f   NANF
// NAN double
#ifndef NAN
#   if IS_BIG_ENDIAN
#      define __NAN_bytes   { 0x7f, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }
#   elif IS_LITTLE_ENDIAN
#      define __NAN_bytes   { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x7f }
#   endif
static const UNUSED double_shape_t __nan = { .bytes = __NAN_bytes };
/** IEEE Not A Number (NAN) */
#   define NAN   (double)(__nan.value)
#endif  // NAN
#define NAN_DOUBLE   NAN
#define z_notanum   NAN
#ifndef NANS
#   if IS_BIG_ENDIAN
#      define __NANS_bytes   { 0x7f, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1 }
#   elif IS_LITTLE_ENDIAN
#      define __NANS_bytes   { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x7f }
#   endif
static const UNUSED double_shape_t __nans = { .bytes = __NANS_bytes };
/** Signed IEEE Not A Number (NANS) */
#   define NANS   (double)(__nans.value)
#endif  // NANS
#define DBL_SNAN   NANS
#define DBL_NANS   NANS
#define SNAN   NANS
#define NANS_DOUBLE   NANS
#define __QNAN   NAN
#define QNAN   NAN
// NAN long double
#if LDBL_EQ_FLOAT128
#   ifndef NANL
#      if IS_BIG_ENDIAN
#         define __NANL_bytes   { 0x7f, 0xff, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }
#      elif IS_LITTLE_ENDIAN
#         define __NANL_bytes   { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xff, 0x7f }
#      endif
static const UNUSED long_double_shape_t __nanl = { .bytes = __NANL_bytes };
/** IEEE Not A Number (NANL) */
#      define NANL   (long double)(__nanl.value)
#   endif  // NANL
#   ifndef NANSL
#      if IS_BIG_ENDIAN
#         define __NANSL_bytes   { 0x7f, 0xff, 0xc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1 }
#      elif IS_LITTLE_ENDIAN
#         define __NANSL_bytes   { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0xff, 0x7f }
#      endif
static const UNUSED long_double_shape_t __nansl = { .bytes = __NANSL_bytes };
/** Signaling IEEE Not A Number (NANSL) */
#      define NANSL   (long double)(__nansl.value)
#   endif  // NANSL
#elif IS_LDBL_96
#   ifndef NANL
#      if IS_BIG_ENDIAN
#         define __NANL_bytes   { 0x7f, 0xff, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }
#      elif IS_LITTLE_ENDIAN
#         define __NANL_bytes   { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xff, 0x7f }
#      endif
union union_nanl { unsigned char bytes[12]; long double value; } __nanl = { .bytes = __NANL_bytes };
/** IEEE Not A Number (NANL) */
#      define NANL   (long double)(__nanl.value)
#   endif  // NANL
#   ifndef NANSL
#      if IS_BIG_ENDIAN
#         define __NANSL_bytes   { 0x7f, 0xff, 0xc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1 }
#      elif IS_LITTLE_ENDIAN
#         define __NANSL_bytes   { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0xff, 0x7f }
#      endif
union union_nansl { unsigned char bytes[12]; long double value; } __nansl = { .bytes = __NANSL_bytes };
/** Signaling IEEE Not A Number (NANSL) */
#      define NANSL   (long double)(__nansl.value)
#   endif  // NANSL
#elif IS_LDBL_80
#   ifndef NANL
#      if IS_BIG_ENDIAN
#         define __NANL_bytes   { 0x7f, 0xff, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }
#      elif IS_LITTLE_ENDIAN
#         define __NANL_bytes   { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xff, 0x7f }
#      endif
union union_nanl { unsigned char bytes[10]; long double value; } __nanl = { .bytes = __NANL_bytes };
/** IEEE Not A Number (NANL) */
#      define NANL   (long double)(__nanl.value)
#   endif  // NANL
#   ifndef NANSL
#      if IS_BIG_ENDIAN
#         define __NANSL_bytes   { 0x7f, 0xff, 0xc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1 }
#      elif IS_LITTLE_ENDIAN
#         define __NANSL_bytes   { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0xff, 0x7f }
#      endif
union union_nansl { unsigned char bytes[10]; long double value; } __nansl = { .bytes = __NANSL_bytes };
/** Signaling IEEE Not A Number (NANSL) */
#      define NANSL   (long double)(__nansl.value)
#   endif  // NANSL
#elif LDBL_EQ_DBL
#   ifndef NANL
/** IEEE Not A Number (NANL) */
#      define NANL   ((long double)NAN)
#   endif  // NANL
#   ifndef NANSL
/** Signaling IEEE Not A Number (NANSL) */
#      define NANSL   ((long double)NANSL)
#   endif  // NANSL
#endif  // NAN long double
#if SUPPORTS_LONG_DOUBLE
#   define QNANL   NANL
#   define __QNANL   NANL
#   define SNANSL   NANSL
#   define SNANL   NANSL
#   define LBL_SNAN   NANSL
#   define LBL_NANS   NANSL
#endif
// NAN float128
#if SUPPORTS_FLOAT128
#      ifndef NAN128
#         if IS_BIG_ENDIAN
#            define __NAN128_bytes   { 0x7f, 0xff, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }
#         elif IS_LITTLE_ENDIAN
#            define __NAN128_bytes   { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xff, 0x7f }
#         endif
static const UNUSED float128_shape_t __nan128 = { .bytes = __NAN128_bytes };
/** IEEE Not A Number (NAN128) */
#         define NAN128   (float128)(__nan128.value)
#      endif  // NAN128
#      define QNAN128   NAN128
#      define __QNAN128   NAN128
#      ifndef NANS128
#         if IS_BIG_ENDIAN
#            define __NANS128_bytes   { 0x7f, 0xff, 0xc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1 }
#         elif IS_LITTLE_ENDIAN
#            define __NANS128_bytes   { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0xff, 0x7f }
#         endif
static const UNUSED float128_shape_t __nans128 = { .bytes = __NANS128_bytes };
/** Signaling IEEE Not A Number (NANS128) */
#         define NANS128   (float128)(__nans128.value)
#      endif  // NANS128
#      define SNANS128   NANS128
#      define FLOAT128_SNAN   NANS128
#      define FLOAT128_NANS   NANS128
#      define SNAN128   NANS128
#endif  // SUPPORTS_FLOAT128
// NAN Decimal Floats
#if SUPPORTS_DECIMAL_FLOATS
// NAN decimal32
#   ifndef NAND32
#      if IS_BIG_ENDIAN
#         define __NAND32_bytes   { 0x7c, 0x0, 0x0, 0x0 }
#      elif IS_LITTLE_ENDIAN
#         define __NAND32_bytes   { 0x0, 0x0, 0x0, 0x7c }
#      endif
static const UNUSED float_shape_t __nand32 = { .bytes = __NAND32_bytes };
/** IEEE Not A Number (NAND32) */
#      define NAND32   (decimal32)(__nand32.decword)  // 0b01111100000000000000000000000000DF
#   endif  // NAND32
#   define QNAND32   NAND32
#   ifndef NANSD32
#      if IS_BIG_ENDIAN
#         define __NANSD32_bytes   { 0x7e, 0x0, 0x0, 0x0 }
#      elif IS_LITTLE_ENDIAN
#         define __NANSD32_bytes   { 0x0, 0x0, 0x0, 0x7e }
#      endif
static const UNUSED float_shape_t __nansd32 = { .bytes = __NANSD32_bytes };
/** Signaling IEEE Not A Number (NANSD32) */
#      define NANSD32   (decimal32)(__nansd32.decword)  // 0b01111110000000000000000000000000DF
#   endif  // NANSD32
#   define SNAND32   NANSD32
// NAN decimal64
#   ifndef NAND64
#      if IS_BIG_ENDIAN
#         define __NAND64_bytes   { 0x7c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }
#      elif IS_LITTLE_ENDIAN
#         define __NAND64_bytes   { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7c }
#      endif
static const UNUSED double_shape_t __nand64 = { .bytes = __NAND64_bytes };
/** IEEE Not A Number (NAND64) */
#      define NAND64   (decimal64)(__nand64.dec64word)
#   endif  // NAND64
#   define QNAND64   NAND64
#   ifndef NANSD64
#      if IS_BIG_ENDIAN
#         define __NANSD64_bytes   { 0x7c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1 }
#      elif IS_LITTLE_ENDIAN
#         define __NANSD64_bytes   { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7c }
#      endif
static const UNUSED double_shape_t __nansd64 = { .bytes = __NANSD64_bytes };
/** Signaling IEEE Not A Number (NANSD64) */
#      define NANSD64   (decimal64)(__nansd64.dec64word)
#   endif  // NANSD64
#   define SNANSD64   NANSD64
// NAN decimal128
#   if SUPPORTS_DECIMAL128
#      ifndef NAND128
#         if IS_BIG_ENDIAN
#            define __NAND128_bytes   { 0x7c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }
#         elif IS_LITTLE_ENDIAN
#            define __NAND128_bytes   { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7c }
#         endif
static const UNUSED float128_shape_t __nand128 = { .bytes = __NAND128_bytes };
/** IEEE Not A Number (NAND128) */
#         define NAND128   (decimal128)(__nand128.dec128word)
#      endif  // NAND128
#      define QNAND128   NAND128
#      ifndef NANSD128
#         if IS_BIG_ENDIAN
#            define __NANSD128_bytes   { 0x7c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1 }
#         elif IS_LITTLE_ENDIAN
#            define __NANSD128_bytes   { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7c }
#         endif
static const UNUSED float128_shape_t __nansd128 = { .bytes = __NANSD128_bytes };
/** Signaling IEEE Not A Number (NANSD128) */
#         define NANSD128   (decimal128)(__nansd128.dec128word)
#      endif  // NANSD128
#      define SNANSD128   NANSD128
#   endif  // SUPPORTS_DECIMAL128
#endif  // SUPPORTS_DECIMAL_FLOATS
#if IS_GNUC  // __nan()
#   define __nanf(str)   __builtin_nanf((str))
#   define __nan(str)   __builtin_nan((str))
#   define __nanl(str)  __builtin_nanl((str))
#   define __nansf(str)   __builtin_nansf((str))
#   define __nans(str)   __builtin_nans((str))
#   define __nansl(str)   __builtin_nansl((str))
#   if SUPPORTS_DECIMAL_FLOATS
#      define __nand32(str)   __builtin_nand32((str))
#      define __nand64(str)   __builtin_nand64((str))
#      if SUPPORTS_DECIMAL128
#         define __nand128(str)   __builtin_nand128((str))
#      endif
#   endif
#else
#   define __nanf(str)   (__builtin_constant_p((str)) && (str[0] == '\0') ? NANF : nanf(str))
#   define __nan(str)   (__builtin_constant_p((str)) && (str[0] == '\0') ? NAN : nan(str))
#   define __nanl(str)   (__builtin_constant_p((str)) && (str[0] == '\0') ? NANL : nanl(str))
#   define __nansf(str)   (__builtin_constant_p((str)) && (str[0] == '\0') ? NANSF : nansf(str))
#   define __nans(str)   (__builtin_constant_p((str)) && (str[0] == '\0') ? NANS : nans(str))
#   define __nansl(str)   (__builtin_constant_p((str)) && (str[0] == '\0') ? NANSL : nansl(str))
#endif  // __nan()


// INFINITY (<bits/inf.h>)

// INF float8
#if SUPPORTS_FLOAT8
#   ifndef INFINITY8
typedef union union_INFINITY8 { unsigned char __c; float8 __f; }   __INFINITY8_t;
#      define __INFINITY8_bytes   (unsigned char)0x78U  // 0b01111000
static const UNUSED __INFINITY8_t __infinity8 = __INFINITY8_bytes;
/** Positive infinity (float8) */
#      define INFINITY8   (float8)(__infinity8.__f)
#   endif  // INFINITY8
/** Positive infinity (float16) */
#   define INF8   INFINITY8
/** Positive infinity (float16) */
#   define PINF8   INFINITY8
#   ifndef NINF8
typedef union union_NINF8 { unsigned char __c; float8 __f; }   __NINF8_t;
#      define __NINF8_bytes   (unsigned char)0xf8U  // 0b11111000
static const UNUSED __NINF8_t __ninf8 = __NINF8_bytes;
/** Negative infinity (float16) */
#      define NINF8   (float8)(__ninf8.__f)
#   endif  // NINF8
#endif
// INF float16
#if SUPPORTS_FLOAT16
#   ifndef INFINITY16
typedef union union_INFINITY16 { unsigned char __c[2]; float16 __f; }   __INFINITY16_t;
#      if IS_BIG_ENDIAN
#         define __INFINITY16_bytes   { 0x7cU, 0x0U }  // 0b0111110000000000
#      elif IS_LITTLE_ENDIAN
#         define __INFINITY16_bytes   { 0x0U, 0x7cU }
#      endif
static const UNUSED __INFINITY16_t __infinity16 = { __INFINITY16_bytes };
/** Positive infinity (float16) */
#      define INFINITY16   (float16)(__infinity16.__f)
#   endif  // INFINITY16
/** Positive infinity (float16) */
#   define INF16   INFINITY16
/** Positive infinity (float16) */
#   define PINF16   INFINITY16
#   ifndef NINF16
typedef union union_NINF16 { unsigned char __c[2]; float16 __f; }   __NINF16_t;
#      if IS_BIG_ENDIAN
#         define __NINF16_bytes   { 0xfcU, 0x0U }  // 0b1111110000000000
#      elif IS_LITTLE_ENDIAN
#         define __NINF16_bytes   { 0x0U, 0xfcU }
#      endif
static const UNUSED __NINF16_t __ninf16 = { __NINF16_bytes };
/** Negative infinity (float16) */
#      define NINF16   (float16)(__ninf16.__f)
#   endif  // NINF16
#endif
// INF float
#ifndef INFINITYF
typedef union union_INFINITYF { unsigned char __c[4]; float __f; }   __INFINITYF_t;
#   if IS_BIG_ENDIAN
#      define __INFINITYF_bytes   { 0x7fU, 0x80U, 0x0U, 0x0U }
#   elif IS_LITTLE_ENDIAN
#      define __INFINITYF_bytes   { 0x0U, 0x0U, 0x80U, 0x7fU }
#   endif
static const UNUSED __INFINITYF_t __infinityf = { __INFINITYF_bytes };
/** IEEE Positive Infinity (INF) */
#   define INFINITYF   (__infinityf.__f)  // 0x7f800000
#endif  // INFINITYF
#define INFF   INFINITYF
#define z_infinity_f   INFINITYF
#define FLT_INFINITY   INFINITYF
/** Positive infinity (float) */
#define PINFF   INFINITYF
/** Positive infinity (float) */
#define PINFINITYF   PINFF
#ifndef NINFF
typedef union union_NINFF { unsigned char __c[4]; float __f; }   __NINFF_t;
#   if IS_BIG_ENDIAN
#      define __NINFF_bytes   { 0xffU, 0x80U, 0x0U, 0x0U }
#   elif IS_LITTLE_ENDIAN
#      define __NINFF_bytes   { 0x0U, 0x0U, 0x80U, 0xffU }
#   endif
static const UNUSED __NINFF_t __ninff = { __NINFF_bytes };
/** Negative infinity (float) */
#   define NINFF   (__ninff.__f)  // 0xff800000
#endif  // NINFF
/** IEEE Negative Infinity (INF) */
#define NEG_INFINITYF   NINFF
// INF double
#ifndef INFINITY
typedef union union_INFINITY { unsigned char __c[8]; double __d; }   __INFINITY_t;
#   if IS_BIG_ENDIAN
#      define __INFINITY_bytes   { 0x7fU, 0xf0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#   elif IS_LITTLE_ENDIAN
#      define __INFINITY_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0xf0U, 0x7fU }
#   endif
static const UNUSED __INFINITY_t __infinity = { __INFINITY_bytes };
/** IEEE Infinity (INF) */
#   define INFINITY   (double)(__infinity.__d)
#endif  // INFINITY
#define INF   INFINITY
#define z_infinity   INFINITY
/** Positive infinity (double) */
#define PINF   INFINITY
/** Positive infinity (double) */
#define PINFINITY   PINF
#ifndef NINF
typedef union union_NINF { unsigned char __c[8]; double __d; }   __NINF_t;
#   if IS_BIG_ENDIAN
#      define __NINF_bytes   { 0xffU, 0xf0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#   elif IS_LITTLE_ENDIAN
#      define __NINF_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0xf0U, 0xffU }
#   endif
static const UNUSED __NINF_t __ninf = { __NINF_bytes };
/** Negative infinity (double) */
#   define NINF   (double)(__ninf.__d)
#endif  // NINF
/** Negative infinity (double) */
#define NEG_INFINITY   NINF
// INF long double
#if LDBL_EQ_FLOAT128
#   ifndef INFINITYL
#      if IS_BIG_ENDIAN
#         define __INFINITYL_bytes   { 0x7fU, 0xf0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#      elif IS_LITTLE_ENDIAN
#         define __INFINITYL_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0xf0U, 0x7fU }
#      endif
union union_INFINITYL { unsigned char __c[16]; long double __ld; } __infinityl = { .__c = __INFINITYL_bytes };
/** IEEE Infinity (INF) */
#      define INFINITYL   (long double)(__infinityl.__ld)  // 0x7ff00000000000000000000000000000L
#   endif  // INFINITYL
#   ifndef NINFL
#      if IS_BIG_ENDIAN
#         define __NINFL_bytes   { 0xffU, 0xf0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#      elif IS_LITTLE_ENDIAN
#         define __NINFL_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0xf0U, 0xffU }
#      endif
union union_NINFL { unsigned char __c[16]; long double __ld; } __ninfl = { .__c = __NINFL_bytes };
/** Negative infinity (long double) */
#      define NINFL   (long double)(__ninfl.__ld)  // 0xfff00000000000000000000000000000L
#   endif  // NINFL
#elif IS_LDBL_96
#   ifndef INFINITYL
#      if IS_BIG_ENDIAN
#         define __INFINITYL_bytes   { 0x7fU, 0xf0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#      elif IS_LITTLE_ENDIAN
#         define __INFINITYL_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0xf0U, 0x7fU }
#      endif
union union_INFINITYL { unsigned char __c[12]; long double __ld; } __infinityl = { .__c = __INFINITYL_bytes };
/** IEEE Infinity (INF) */
#      define INFINITYL   (long double)(__infinityl.__ld)  // 0x7ff000000000000000000000L
#   endif  // INFINITYL
#   ifndef NINFL
#      if IS_BIG_ENDIAN
#         define __NINFL_bytes   { 0xffU, 0xf0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#      elif IS_LITTLE_ENDIAN
#         define __NINFL_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0xf0U, 0xffU }
#      endif
union union_NINFL { unsigned char __c[12]; long double __ld; } __ninfl = { .__c = __NINFL_bytes };
/** Negative infinity (long double) */
#      define NINFL   (long double)(__ninfl.__ld)  // 0xfff000000000000000000000L
#   endif  // NINFL
#elif IS_LDBL_80
#   ifndef INFINITYL
#      if IS_BIG_ENDIAN
#         define __INFINITYL_bytes   { 0x7fU, 0xf0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#      elif IS_LITTLE_ENDIAN
#         define __INFINITYL_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0xf0U, 0x7fU }
#      endif
union union_INFINITYL { unsigned char __c[10]; long double __ld; } __infinityl = { .__c = __INFINITYL_bytes };
/** IEEE Infinity (INF) */
#      define INFINITYL   (long double)(__infinityl.__ld)  // 0x7ff00000000000000000L
#   endif  // INFINITYL
#   ifndef NINFL
#      if IS_BIG_ENDIAN
#         define __NINFL_bytes   { 0xffU, 0xf0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#      elif IS_LITTLE_ENDIAN
#         define __NINFL_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0xf0U, 0xffU }
#      endif
union union_NINFL { unsigned char __c[10]; long double __ld; } __ninfl = { .__c = __NINFL_bytes };
/** Negative infinity (long double) */
#      define NINFL   (long double)(__ninfl.__ld)  // 0xfff00000000000000000L
#   endif  // NINFL
#elif LDBL_EQ_DBL
#   ifndef INFINITYL
/** IEEE Infinity (INF) */
#      define INFINITYL   ((long double)INFINITY)
#   endif  // INFINITYL
#   ifndef NINFL
/** Negative infinity (long double) */
#      define NINFL   ((long double)NINF)
#   endif  // NINFL
#endif  // INF long double
#if SUPPORTS_LONG_DOUBLE
#   define INFL   INFINITYL
#   define PINFL   INFINITYL
#   define PINFINITYL   INFINITYL
#   define NEG_INFINITYL   NINFL
#endif
// INF float128
#if SUPPORTS_FLOAT128
#   ifndef INFINITY128
typedef union union_INFINITY128 { unsigned char __c[16]; float128 __d; }   __INFINITY128_t;
#      if IS_BIG_ENDIAN
#         define __INFINITY128_bytes   { 0x7fU, 0xf0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#      elif IS_LITTLE_ENDIAN
#         define __INFINITY128_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0xf0U, 0x7fU }
#      endif
static const UNUSED __INFINITY128_t __infinity128 = { __INFINITY128_bytes };
/** IEEE Infinity (INF) */
#      define INFINITY128   (float128)(__infinity128.__d)  // 0x7ff00000000000000000000000000000
#   endif  // INFINITY128
#   define INF128   INFINITY128
#   define PINF128   INFINITY128
#   define PINFINITY128   INFINITY128
#   ifndef NINF128
typedef union union_NINF128 { unsigned char __c[16]; float128 __d; }   __NINF128_t;
#      if IS_BIG_ENDIAN
#         define __NINF128_bytes   { 0xffU, 0xf0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#      elif IS_LITTLE_ENDIAN
#         define __NINF128_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0xf0U, 0xffU }
#      endif
static const UNUSED __NINF128_t __ninf128 = { __NINF128_bytes };
/** Negative infinity (float128) */
#      define NINF128   (float128)(__ninf128.__d)  // 0xfff00000000000000000000000000000
#   endif  // NINF128
#   define NEG_INFINITY128   NINF128
#endif  // SUPPORTS_FLOAT128
// INF decimal floats
#if (SUPPORTS_DECIMAL_FLOATS && (!defined(INFINITYD64)))
#   ifndef INFINITYD32
typedef union union_INFINITYD32 { unsigned char __c[4]; decimal32 __f; }   __INFINITYD32_t;
#      if IS_BIG_ENDIAN
#         define __INFINITYD32_bytes   { 0x78U, 0x0U, 0x0U, 0x0U }
#      elif IS_LITTLE_ENDIAN
#         define __INFINITYD32_bytes   { 0x0U, 0x0U, 0x0U, 0x78U }
#      endif
static const UNUSED __INFINITYD32_t __infinityd32 = { __INFINITYD32_bytes };
/** Decimal float infinity (32-bit) */
#      define INFINITYD32   (__infinityd32.__f)  // 0b01111000000000000000000000000000DF
#   endif  // INFINITYD32
#   define INFD32   INFINITYD32
#   define POS_INFINITYD32   INFINITYD32
#   define PINFD32   POS_INFINITYD32
#   ifndef NEG_INFINITYD32
typedef union union_NEG_INFINITYD32 { unsigned char __c[4]; decimal32 __f; }   __NEG_INFINITYD32_t;
#      if IS_BIG_ENDIAN
#         define __NEG_INFINITYD32_bytes   { 0xf8U, 0x0U, 0x0U, 0x0U }
#      elif IS_LITTLE_ENDIAN
#         define __NEG_INFINITYD32_bytes   { 0x0U, 0x0U, 0x0U, 0xf8U }
#      endif
static const UNUSED __NEG_INFINITYD32_t __neg_infinityd32 = { __NEG_INFINITYD32_bytes };
/** Decimal float infinity (32-bit) */
#      define NEG_INFINITYD32   (__neg_infinityd32.__f)  // 0b11111000000000000000000000000000DF
#   endif  // NEG_INFINITYD32
#   define NINFD32   NEG_INFINITYD32
#   ifndef INFINITYD64
typedef union union_INFINITYD64 { unsigned char __c[8]; decimal64 __d; }   __INFINITYD64_t;
#      if IS_BIG_ENDIAN
#         define __INFINITYD64_bytes   { 0x78U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#      elif IS_LITTLE_ENDIAN
#         define __INFINITYD64_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x78U }
#      endif
static const UNUSED __INFINITYD64_t __infinityd64 = { __INFINITYD64_bytes };
/** IEEE Infinity (INF) */
#      define INFINITYD64   (decimal64)(__infinityd64.__d)  // 0b0111100000000000000000000000000000000000000000000000000000000000DD
#   endif  // INFINITYD64
#   define INFD64   INFINITYD64
#   define POS_INFINITYD64   INFINITYD64
#   define PINFD64   POS_INFINITYD64
#   ifndef NEG_INFINITYD64
typedef union union_NEG_INFINITYD64 { unsigned char __c[8]; decimal64 __d; }   __NEG_INFINITYD64_t;
#      if IS_BIG_ENDIAN
#         define __NEG_INFINITYD64_bytes   { 0xf8U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#      elif IS_LITTLE_ENDIAN
#         define __NEG_INFINITYD64_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0xf8U }
#      endif
static const UNUSED __NEG_INFINITYD64_t __neg_infinityd64 = { __NEG_INFINITYD64_bytes };
#      define NEG_INFINITYD64   (decimal64)(__neg_infinityd64.__d)  // 0b1111100000000000000000000000000000000000000000000000000000000000DD
#   endif  // NEG_INFINITYD64
#   define NINFD64   NEG_INFINITYD64
#   if SUPPORTS_DECIMAL128
#      ifndef INFINITYD128
typedef union union_INFINITYD128 { unsigned char __c[16]; decimal128 __d; }   __INFINITYD128_t;
#         if IS_BIG_ENDIAN
#            define __INFINITYD128_bytes   { 0x78U, 0x00U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#         elif IS_LITTLE_ENDIAN
#            define __INFINITYD128_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x00U, 0x78U }
#         endif
static const UNUSED __INFINITYD128_t __infinityd128 = { __INFINITYD128_bytes };
/** IEEE Infinity (INF) */
#         define INFINITYD128   (decimal128)(__infinityd128.__d)
#      endif  // INFINITYD128
#      define INFD128   INFINITYD128
#      define POS_INFINITYD128   INFINITYD128
#      define PINFD128   INFINITYD128
#      ifndef NINFD128
typedef union union_NINFD128 { unsigned char __c[16]; decimal128 __d; }   __NINFD128_t;
#         if IS_BIG_ENDIAN
#            define __NINFD128_bytes   { 0xf8U, 0x00U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U }
#         elif IS_LITTLE_ENDIAN
#            define __NINFD128_bytes   { 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x0U, 0x00U, 0xf8U }
#         endif
static const UNUSED __NINFD128_t __ninfd128 = { __NINFD128_bytes };
/** Negative infinity (decimal128) */
#         define NINFD128   (decimal128)(__ninfd128.__d)  // 0xf8000000000000000000000000000000DL
#      endif  // NINFD128
#      define NEG_INFINITYD128   NINFD128
#   endif  // SUPPORTS_DECIMAL128
#endif


// HUGE_VAL

// HUGE_VAL FLOAT (<bits/huge_valf.h>)
#ifndef HUGE_VALF
/** IEEE Positive Infinity (-HUGE_VAL is negative infinity) */
#   define HUGE_VALF   INFINITYF
#endif
#define z_hugeval_f   HUGE_VALF
// HUGE_VAL DOUBLE (<bits/huge_val.h>)
#ifndef HUGE_VAL
/** IEEE Positive Infinity (-HUGE_VAL is negative infinity) */
#   define HUGE_VAL   INFINITY
#endif
#define z_hugeval   HUGE_VAL
// HUGE_VAL LONG DOUBLE (<bits/huge_vall.h>)
#if SUPPORTS_LONG_DOUBLE
/** IEEE Positive Infinity (-HUGE_VALL is negative infinity) */
#   define HUGE_VALL   INFINITYL
#endif


#endif  // FLOAT_H


/* SYSTEM EXIT CODES */


#if (!(defined(SYSEXITS_H) || defined(_SYSEXITS_H) || defined(_SYSEXITS_H_)))
#define SYSEXITS_H   (1)
#define _SYSEXITS_H   (1)
#define _SYSEXITS_H_   (1)


/** @def EXIT_FAILURE
This macro expands to a system-dependent integral expression that signifies that the application failed (when used as the argument for the function exit) */
/** @def EXIT_SUCCESS
This macro expands to a system-dependent integral expression that signifies that the application was successful (when used as the argument for the function exit) */
#ifdef VMS  // VMS is nonstandard
#   define EXIT_FAILURE   (0)
#   define EXIT_SUCCESS   (1)
#else
#   define EXIT_FAILURE   (1)
#   define EXIT_SUCCESS   (0)
#endif
#ifndef exit_success
/** This macro expands to a system-dependent integral expression that signifies that the application was successful (when used as the argument for the function exit) */
#   define exit_success   EXIT_SUCCESS
#endif
#ifndef exit_failure
/** This macro expands to a system-dependent integral expression that signifies that the application failed (when used as the argument for the function exit) */
#   define exit_failure   EXIT_FAILURE
#endif

/** @defgroup Exit_Codes Macros for various exit codes
@{ */  // (FB){

/** Successful termination */
#define EX_OK   0
/** Base value for error messages */
#define EX__BASE   64
/** Command line usage error */
#define EX_USAGE   64
/** Data format error */
#define EX_DATAERR   65
/** Cannot open input */
#define EX_NOINPUT   66
/** Addressee unknown */
#define EX_NOUSER   67
/** Hostname unknown */
#define EX_NOHOST   68
/** Service unavailable */
#define EX_UNAVAILABLE   69
/** Internal software error */
#define EX_SOFTWARE   70
/** System error (cannot fork) */
#define EX_OSERR   71
/** Critical OS file missing */
#define EX_OSFILE   72
/** Cannot create (user) output file */
#define EX_CANTCREAT   73
/** I/O error */
#define EX_IOERR   74
/** Temporary failure; user is invited to retry */
#define EX_TEMPFAIL   75
/** Remote error in protocol */
#define EX_PROTOCOL   76
/** Permission denied */
#define EX_NOPERM   77
/** Configuration error */
#define EX_CONFIG   78
/** Maximum listed value */
#define EX__MAX   78

/** @} */  // }


#endif  // SYSEXITS_H


/* HEADER INCLUDES */


#include "MACROS2.h"
#include "MACROS3.h"
#include "MACROS_MATH.h"
#ifndef DISABLE_NETWORK_HEADER
#   include "MACROS_NET.h"
#endif
#ifndef DISABLE_MISC_HEADER
#   include "MACROS_MISC.h"
#endif

// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
/**
@brief Print the size and alignment of each datatype
@file typesize.c
@version 2020.02.01
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section COMPILE
gcc -Wall -Wextra -Wpedantic -O3 -Wl,-O3 -g0 -ggdb0 -s -fwhole-program -funroll-loops -ffunction-sections -fdata-sections -std=c17 -o ./typesize ./typesize.c && strip --remove-section=.note --remove-section=.comment --strip-debug --strip-unneeded ./typesize

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


#include "MACROS.h"


#define DIVIDER   "-------"


noreturn int main(void) {
	(void)puts("DATATYPE:\t\t\tSIZE\tALIGNMENT\n");
	// Basic Datatypes
	(void)fprintf(stdout, "Char:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(char), (ulint)alignof(char));
	(void)fprintf(stdout, "Int:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(int), (ulint)alignof(int));
	(void)fprintf(stdout, "Short Int:\t\t\t%lu\t%lu\n", (ulint)sizeof(short int), (ulint)alignof(short int));
	(void)fprintf(stdout, "Long Int:\t\t\t%lu\t%lu\n", (ulint)sizeof(long int), (ulint)alignof(long int));
	(void)fprintf(stdout, "Long Long Int:\t\t\t%lu\t%lu\n", (ulint)sizeof(long long int), (ulint)alignof(long long int));
#   if SUPPORTS_INT128
	(void)fprintf(stdout, "uint128_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(uint128_t), (ulint)alignof(uint128_t));
#   endif
	(void)fprintf(stdout, "Float:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(float), (ulint)alignof(float));
#   if SUPPORTS_FLOAT80
	(void)fprintf(stdout, "Float80:\t\t\t%lu\t%lu\n", (ulint)sizeof(float80), (ulint)alignof(float80));
#   endif
#   if SUPPORTS_FLOAT96
	(void)fprintf(stdout, "Float96:\t\t\t%lu\t%lu\n", (ulint)sizeof(float96), (ulint)alignof(float96));
#   endif
	(void)fprintf(stdout, "Double:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(double), (ulint)alignof(double));
	(void)fprintf(stdout, "Long Double:\t\t\t%lu\t%lu\n", (ulint)sizeof(long double), (ulint)alignof(long double));
	(void)fprintf(stdout, "uintptr_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(uintptr_t), (ulint)alignof(uintptr_t));
	const ulint ptrsize = (ulint)sizeof(char*);
	(void)fprintf(stdout, "Char*:\t\t\t\t%lu\t%lu\n", (ulint)alignof(char*), ptrsize);
	(void)fprintf(stdout, "&Address:\t\t\t%lu\t%lu\n", (ulint)sizeof(&ptrsize), (ulint)alignof(&ptrsize));
	// Decimal-Float Datatypes
	(void)puts(DIVIDER);
#   if SUPPORTS_DECIMAL_FLOATS
	(void)fprintf(stdout, "Decimal32:\t\t\t%lu\t%lu\n", (ulint)sizeof(decimal32), (ulint)alignof(decimal32));
	(void)fprintf(stdout, "Decimal64:\t\t\t%lu\t%lu\n", (ulint)sizeof(decimal64), (ulint)alignof(decimal64));
#   endif
#   if SUPPORTS_DECIMAL128
	(void)fprintf(stdout, "Decimal128:\t\t\t%lu\t%lu\n", (ulint)sizeof(decimal128), (ulint)alignof(decimal128));
#   endif
	// Complex Datatypes
	(void)puts(DIVIDER);
#   if SUPPORTS_COMPLEX
	(void)fprintf(stdout, "Complex Float:\t\t\t%lu\t%lu\n", (ulint)sizeof(complex_float), (ulint)alignof(complex_float));
	(void)fprintf(stdout, "Complex Double:\t\t\t%lu\t%lu\n", (ulint)sizeof(complex_double), (ulint)alignof(complex_double));
	(void)fprintf(stdout, "Complex Long Double:\t\t%lu\t%lu\n", (ulint)sizeof(complex_long_double), (ulint)alignof(complex_long_double));
#      if SUPPORTS_FLOAT128
	(void)fprintf(stdout, "cfloat128_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(cfloat128_t), (ulint)alignof(cfloat128_t));
#      endif
#   endif
	// Miscellaneous Datatypes
	(void)puts(DIVIDER);
	(void)fprintf(stdout, "int_least8_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(int_least8_t), (ulint)alignof(int_least8_t));
	(void)fprintf(stdout, "int_least16_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(int_least16_t), (ulint)alignof(int_least16_t));
	(void)fprintf(stdout, "int_least32_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(int_least32_t), (ulint)alignof(int_least32_t));
	(void)fprintf(stdout, "int_least64_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(int_least64_t), (ulint)alignof(int_least64_t));
	(void)fprintf(stdout, "int_fast16_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(int_fast16_t), (ulint)alignof(int_fast16_t));
	(void)fprintf(stdout, "int_fast32_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(int_fast32_t), (ulint)alignof(int_fast32_t));
	(void)fprintf(stdout, "int_fast64_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(int_fast64_t), (ulint)alignof(int_fast64_t));
	(void)fprintf(stdout, "fpmax_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(fpmax_t), (ulint)alignof(fpmax_t));
	(void)fprintf(stdout, "fpu_control_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(fpu_control_t), (ulint)alignof(fpu_control_t));
	(void)fprintf(stdout, "_Bool:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(_Bool), (ulint)alignof(_Bool));
	(void)fprintf(stdout, "va_list:\t\t\t%lu\t%lu\n", (ulint)sizeof(va_list), (ulint)alignof(va_list));
	(void)fprintf(stdout, "size_t:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(size_t), (ulint)alignof(size_t));
	(void)fprintf(stdout, "WORD:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(WORD), (ulint)alignof(WORD));
	(void)fprintf(stdout, "DWORD:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(DWORD), (ulint)alignof(DWORD));
	(void)fprintf(stdout, "RuneType:\t\t\t%lu\t%lu\n", (ulint)sizeof(RuneType), (ulint)alignof(RuneType));
	(void)fprintf(stdout, "wchar_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(wchar_t), (ulint)alignof(wchar_t));
	(void)fprintf(stdout, "wint_t:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(wint_t), (ulint)alignof(wint_t));
	(void)fprintf(stdout, "wcinfo_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(wcinfo_t), (ulint)alignof(wcinfo_t));
	(void)fprintf(stdout, "ucs4_t:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(ucs4_t), (ulint)alignof(ucs4_t));
	(void)fprintf(stdout, "utf8_t:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(utf8_t), (ulint)alignof(utf8_t));
	(void)fprintf(stdout, "off_t:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(off_t), (ulint)alignof(off_t));
	(void)fprintf(stdout, "off64_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(off64_t), (ulint)alignof(off64_t));
	(void)fprintf(stdout, "intmax_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(intmax_t), (ulint)alignof(intmax_t));
	(void)fprintf(stdout, "imaxdiv_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(imaxdiv_t), (ulint)alignof(imaxdiv_t));
	(void)fprintf(stdout, "max_align_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(max_align_t), (ulint)alignof(max_align_t));
	(void)fprintf(stdout, "mbstate_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(mbstate_t), (ulint)alignof(mbstate_t));
	(void)fprintf(stdout, "greg_t:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(greg_t), (ulint)alignof(greg_t));
	(void)fprintf(stdout, "__jmp_buf:\t\t\t%lu\t%lu\n", (ulint)sizeof(__jmp_buf), (ulint)alignof(__jmp_buf));
	// Time Datatypes
	(void)puts(DIVIDER);
	(void)fprintf(stdout, "timespec_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(timespec_t), (ulint)alignof(timespec_t));
	(void)fprintf(stdout, "timeval_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(timeval_t), (ulint)alignof(timeval_t));
	(void)fprintf(stdout, "itimerval_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(itimerval_t), (ulint)alignof(itimerval_t));
	(void)fprintf(stdout, "tm_t:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(tm_t), (ulint)alignof(tm_t));
	// Locale Datatypes
	(void)puts(DIVIDER);
	(void)fprintf(stdout, "lconv_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(lconv_t), (ulint)alignof(lconv_t));
	(void)fprintf(stdout, "locale_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(locale_t), (ulint)alignof(locale_t));
	// Thread Datatypes
	(void)puts(DIVIDER);
	(void)fprintf(stdout, "pthread_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(pthread_t), (ulint)alignof(pthread_t));
	(void)fprintf(stdout, "posix_spawnattr_t:\t\t%lu\t%lu\n", (ulint)sizeof(posix_spawnattr_t), (ulint)alignof(posix_spawnattr_t));
	(void)fprintf(stdout, "pthread_barrier_t:\t\t%lu\t%lu\n", (ulint)sizeof(pthread_barrier_t), (ulint)alignof(pthread_barrier_t));
	(void)fprintf(stdout, "pthread_cond_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(pthread_cond_t), (ulint)alignof(pthread_cond_t));
	(void)fprintf(stdout, "pthread_descr_t:\t\t%lu\t%lu\n", (ulint)sizeof(pthread_descr_t), (ulint)alignof(pthread_descr_t));
	(void)fprintf(stdout, "pthread_mutex_t:\t\t%lu\t%lu\n", (ulint)sizeof(pthread_mutex_t), (ulint)alignof(pthread_mutex_t));
	(void)fprintf(stdout, "pthread_mutexattr_t:\t\t%lu\t%lu\n", (ulint)sizeof(pthread_mutexattr_t), (ulint)alignof(pthread_mutexattr_t));
	(void)fprintf(stdout, "struct pthread:\t\t\t%lu\t%lu\n", (ulint)sizeof(struct pthread), (ulint)alignof(struct pthread));
	// Signal Datatypes
	(void)puts(DIVIDER);
	(void)fprintf(stdout, "sighandler_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(sighandler_t), (ulint)alignof(sighandler_t));
	(void)fprintf(stdout, "sigset_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(sigset_t), (ulint)alignof(sigset_t));
	(void)fprintf(stdout, "sigval_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(sigval_t), (ulint)alignof(sigval_t));
	(void)fprintf(stdout, "struct sigaction:\t\t%lu\t%lu\n", (ulint)sizeof(struct sigaction), (ulint)alignof(struct sigaction));
	(void)fprintf(stdout, "struct sigcontext:\t\t%lu\t%lu\n", (ulint)sizeof(struct sigcontext), (ulint)alignof(struct sigcontext));
	// Structure Datatypes
	(void)puts(DIVIDER);
	(void)fprintf(stdout, "FILE:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(FILE), (ulint)alignof(FILE));
	(void)fprintf(stdout, "iovec_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(iovec_t), (ulint)alignof(iovec_t));
	(void)fprintf(stdout, "statvfs_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(statvfs_t), (ulint)alignof(statvfs_t));
#   if SUPPORTS_LARGEFILE64
	(void)fprintf(stdout, "statvfs64_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(statvfs64_t), (ulint)alignof(statvfs64_t));
#   endif
	(void)fprintf(stdout, "dirent_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(dirent_t), (ulint)alignof(dirent_t));
#   if SUPPORTS_LARGEFILE64
	(void)fprintf(stdout, "dirent64_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(dirent64_t), (ulint)alignof(dirent64_t));
#   endif
	(void)fprintf(stdout, "rlimit_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(rlimit_t), (ulint)alignof(rlimit_t));
	(void)fprintf(stdout, "mcontext_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(mcontext_t), (ulint)alignof(mcontext_t));
	(void)fprintf(stdout, "ucontext_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(ucontext_t), (ulint)alignof(ucontext_t));
	// Vector Datatypes
	(void)puts(DIVIDER);
#   ifdef VECTOR4
	(void)fprintf(stdout, "V4QItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V4QItype), (ulint)alignof(V4QItype));
	(void)fprintf(stdout, "V8QItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V8QItype), (ulint)alignof(V8QItype));
	(void)fprintf(stdout, "V16QItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V16QItype), (ulint)alignof(V16QItype));
	(void)fprintf(stdout, "V32QItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V32QItype), (ulint)alignof(V32QItype));
	(void)fprintf(stdout, "V64QItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V64QItype), (ulint)alignof(V64QItype));
	(void)fprintf(stdout, "V2HItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V2HItype), (ulint)alignof(V2HItype));
	(void)fprintf(stdout, "V4HItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V4HItype), (ulint)alignof(V4HItype));
	(void)fprintf(stdout, "V8HItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V8HItype), (ulint)alignof(V8HItype));
	(void)fprintf(stdout, "V16HItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V16HItype), (ulint)alignof(V16HItype));
	(void)fprintf(stdout, "V32HItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V32HItype), (ulint)alignof(V32HItype));
	(void)fprintf(stdout, "V2SItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V2SItype), (ulint)alignof(V2SItype));
	(void)fprintf(stdout, "V4SItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V4SItype), (ulint)alignof(V4SItype));
	(void)fprintf(stdout, "V8SItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V8SItype), (ulint)alignof(V8SItype));
	(void)fprintf(stdout, "V16SItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V16SItype), (ulint)alignof(V16SItype));
	(void)fprintf(stdout, "V2DItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V2DItype), (ulint)alignof(V2DItype));
	(void)fprintf(stdout, "V4DItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V4DItype), (ulint)alignof(V4DItype));
	(void)fprintf(stdout, "V8DItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V8DItype), (ulint)alignof(V8DItype));
	(void)fprintf(stdout, "V2SFtype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V2SFtype), (ulint)alignof(V2SFtype));
	(void)fprintf(stdout, "V4SFtype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V4SFtype), (ulint)alignof(V4SFtype));
	(void)fprintf(stdout, "V8SFtype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V8SFtype), (ulint)alignof(V8SFtype));
	(void)fprintf(stdout, "V16SFtype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V16SFtype), (ulint)alignof(V16SFtype));
	(void)fprintf(stdout, "V2DFtype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V2DFtype), (ulint)alignof(V2DFtype));
	(void)fprintf(stdout, "V4DFtype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V4DFtype), (ulint)alignof(V4DFtype));
	(void)fprintf(stdout, "V8DFtype:\t\t\t%lu\t%lu\n", (ulint)sizeof(V8DFtype), (ulint)alignof(V8DFtype));
	(void)fprintf(stdout, "__m64:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(__m64), (ulint)alignof(__m64));
	(void)fprintf(stdout, "__m64_u:\t\t\t%lu\t%lu\n", (ulint)sizeof(__m64_u), (ulint)alignof(__m64_u));
#   endif
	// Struct Shape Datatypes
	(void)puts(DIVIDER);
	(void)fprintf(stdout, "float_shape_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(float_shape_t), (ulint)alignof(float_shape_t));
	(void)fprintf(stdout, "double_shape_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(double_shape_t), (ulint)alignof(double_shape_t));
#   if SUPPORTS_LONG_DOUBLE
	(void)fprintf(stdout, "long_double_shape_t:\t\t%lu\t%lu\n", (ulint)sizeof(long_double_shape_t), (ulint)alignof(long_double_shape_t));
	(void)fprintf(stdout, "ldshape_t:\t\t\t%lu\t%lu\n", (ulint)sizeof(ldshape_t), (ulint)alignof(ldshape_t));
#   endif
#   if SUPPORTS_FLOAT128
	(void)fprintf(stdout, "float128_shape_t:\t\t%lu\t%lu\n", (ulint)sizeof(float128_shape_t), (ulint)alignof(float128_shape_t));
#   endif
#   if SUPPORTS_COMPLEX
	(void)fprintf(stdout, "complex_float_shape_t:\t\t%lu\t%lu\n", (ulint)sizeof(complex_float_shape_t), (ulint)alignof(complex_float_shape_t));
	(void)fprintf(stdout, "complex_double_shape_t:\t\t%lu\t%lu\n", (ulint)sizeof(complex_double_shape_t), (ulint)alignof(complex_double_shape_t));
#   endif
#   if SUPPORTS_COMPLEX_LDBL
	(void)fprintf(stdout, "complex_long_double_shape_t:\t%lu\t%lu\n", (ulint)sizeof(complex_long_double_shape_t), (ulint)alignof(complex_long_double_shape_t));
#   endif
	// Machine Datatypes
	(void)puts(DIVIDER);
#   if SUPPORTS_BND64
	(void)fprintf(stdout, "BND64type:\t\t\t%lu\t%lu\n", (ulint)sizeof(BND64type), (ulint)alignof(BND64type));
#   endif
	(void)fprintf(stdout, "QItype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(QItype), (ulint)alignof(QItype));
	(void)fprintf(stdout, "HItype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(HItype), (ulint)alignof(HItype));
	(void)fprintf(stdout, "SItype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(SItype), (ulint)alignof(SItype));
	(void)fprintf(stdout, "DItype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(DItype), (ulint)alignof(DItype));
	(void)fprintf(stdout, "DWtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(DWtype), (ulint)alignof(DWtype));
#   if SUPPORTS_QFTYPE
	(void)fprintf(stdout, "QFtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(QFtype), (ulint)alignof(QFtype));
#   endif
#   if SUPPORTS_HFTYPE
	(void)fprintf(stdout, "HFtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(HFtype), (ulint)alignof(HFtype));
#   endif
#   if SUPPORTS_TQFTYPE
	(void)fprintf(stdout, "TQFtype:\t\t\t%lu\t%lu\n", (ulint)sizeof(TQFtype), (ulint)alignof(TQFtype));
#   endif
	(void)fprintf(stdout, "SFtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(SFtype), (ulint)alignof(SFtype));
	(void)fprintf(stdout, "DFtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(DFtype), (ulint)alignof(DFtype));
#   if SUPPORTS_XFTYPE
	(void)fprintf(stdout, "XFtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(XFtype), (ulint)alignof(XFtype));
#   endif
#   if SUPPORTS_TFTYPE
	(void)fprintf(stdout, "TFtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(TFtype), (ulint)alignof(TFtype));
#   endif
#   if SUPPORTS_DECIMAL_FLOATS
	(void)fprintf(stdout, "SDtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(SDtype), (ulint)alignof(SDtype));
	(void)fprintf(stdout, "DDtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(DDtype), (ulint)alignof(DDtype));
#   endif
#   if SUPPORTS_TDTYPE
	(void)fprintf(stdout, "TDtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(TDtype), (ulint)alignof(TDtype));
#   endif
#   if SUPPORTS_SCTYPE
	(void)fprintf(stdout, "SCtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(SCtype), (ulint)alignof(SCtype));
#   endif
#   if SUPPORTS_DCTYPE
	(void)fprintf(stdout, "DCtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(DCtype), (ulint)alignof(DCtype));
#   endif
#   if SUPPORTS_XCTYPE
	(void)fprintf(stdout, "XCtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(XCtype), (ulint)alignof(XCtype));
#   endif
#   if SUPPORTS_TCTYPE
	(void)fprintf(stdout, "TCtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(TCtype), (ulint)alignof(TCtype));
#   endif
	(void)fprintf(stdout, "PTRtype:\t\t\t%lu\t%lu\n", (ulint)sizeof(PTRtype), (ulint)alignof(PTRtype));
#   if SUPPORTS_COMPLEX_INT
	(void)fprintf(stdout, "CQItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(CQItype), (ulint)alignof(CQItype));
	(void)fprintf(stdout, "CHItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(CHItype), (ulint)alignof(CHItype));
	(void)fprintf(stdout, "CSItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(CSItype), (ulint)alignof(CSItype));
	(void)fprintf(stdout, "CDItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(CDItype), (ulint)alignof(CDItype));
#      if SUPPORTS_CTITYPE
	(void)fprintf(stdout, "CTItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(CTItype), (ulint)alignof(CTItype));
#      endif
#      if SUPPORTS_COITYPE
	(void)fprintf(stdout, "COItype:\t\t\t%lu\t%lu\n", (ulint)sizeof(COItype), (ulint)alignof(COItype));
#      endif
#   endif
#   if SUPPORTS_COMPLEX
	(void)fprintf(stdout, "SCtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(SCtype), (ulint)alignof(SCtype));
	(void)fprintf(stdout, "DCtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(DCtype), (ulint)alignof(DCtype));
	(void)fprintf(stdout, "XCtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(XCtype), (ulint)alignof(XCtype));
#      if SUPPORTS_TCTYPE
	(void)fprintf(stdout, "TCtype:\t\t\t\t%lu\t%lu\n", (ulint)sizeof(TCtype), (ulint)alignof(TCtype));
#      endif
#   endif
	fast_exit(EXIT_SUCCESS);
}

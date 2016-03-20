// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file MACROS.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Standard Macros Header
@version 2016.03.20

@section DESCRIPTION
This file defines various macros functions, names, and tests.
Substitutes for <stdbool.h>, <stdarg.h>, and <ctype.h> are also provided.

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

@section INFO
_BSD_SOURCE (deprecated since glibc 2.20)

_SVID_SOURCE (deprecated since glibc 2.20)

For more information, see http://man7.org/linux/man-pages/man7/feature_test_macros.7.html
or execute "man feature_test_macros"

Helpful Commands

 - gcc -dM -E -x c /dev/null
 - clang -dM -E -x c /dev/null
 - x86_64-w64-mingw32-gcc -m64 -dM -E -x c /dev/null
 - arm-linux-gnueabihf-gcc -march=armv6zk -mtune=arm1176jzf-s -mfloat-abi=hard -mlittle-endian -mfpu=vfp -marm -mtp=auto -dM -E -x c /dev/null
 - strings `which gcc`
 - gcc --print-search-dirs
 - gcc --print-multiarch
 - pkg-config --cflags --libs cairo
 - pkg-config --cflags --libs pango
 - pkg-config --cflags --libs glib-2.0
 - pkg-config --cflags --libs gobject-2.0
 - pkg-config --cflags --libs gobject-introspection-1.0

Macros Documentation

 - http://sourceforge.net/p/predef/wiki/Home/
 - https://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html
 - https://msdn.microsoft.com/en-us/library/b0084kay.aspx
 - http://clang.llvm.org/docs/LanguageExtensions.html

Machine Modes

 - BI - 1 Bit
 - QI - Quarter Integer; 1 byte
 - HI - Half Integer; 2 bytes
 - PSI - Partial Single Integer; 4 bytes; not all bits used
 - SI - Single Integer; 4 bytes
 - PDI - Partial Double Integer; 8 bytes; not all bits used
 - DI - Double Integer; 8 bytes
 - TI - Tetra Integer; 16 bytes
 - OI - Octa Integer; 32 bytes
 - QF - Quarter Floating; 1 byte quarter-precision float-point
 - HF - Half Floating; 2 byte half-precision float-point
 - TQF - Three Quarter Floating; 3 byte three-quarter-precision float-point
 - SF - Single Floating; 4 byte single-precision float-point
 - DF - Double Floating; 8 byte double-precision float-point
 - XF - Extended Floating; 12 byte extended-precision float-point
 - TF - Tetra Floating; 16 byte tetra-precision float-point
 - CQI - Complex Quarter Integer; 1 byte
 - CHI - Complex Half Integer; 2 bytes
 - CSI - Complex Single Integer; 4 bytes
 - CDI - Complex Double Integer; 8 bytes
 - CTI - Complex Tetra Integer; 16 bytes
 - COI - Complex Octa Integer; 32 bytes
 - QC - Quarter Complex; 1 byte quarter-precision complex float-point
 - HC - Half Complex; 2 byte half-precision complex float-point
 - SC - Single Complex; 4 byte single-precision complex float-point
 - DC - Double Complex; 8 byte double-precision complex float-point
 - XC - Extended Complex; 12 byte extended-precision complex float-point
 - TC - Tetra Complex; 16 byte tetra-precision complex float-point
 - CC - Condition Code
 - BLK - Block
 - VOID - Void
 - P - Address mode
 - V4SI - Vector; 4 single integers
 - V8QI - Vector; 8 single-byte integers
 - BND32 - 32-bit pointer bound
 - BND64 - 32-bit pointer bound
*/


#ifndef STANDARD_MACROS_SEEN
#define STANDARD_MACROS_SEEN


#if ('a' != 97 || 'z' != 122 || 'A' != 65 || ' ' != 32)
#   error   "ERROR: Invalid character encoding (must be UTF8)!"
#endif


#if (defined(__GNUC__) && !defined(__clang__))  // Hard-code some optimizations
#   pragma GCC optimize (3)
#   pragma GCC optimize ("no-exceptions")
#   pragma GCC optimize ("unroll-loops")
#   pragma GCC optimize ("wrapv")
#   define __IVDEP__  // ivdep: Vectorize loops
#elif defined(__clang__)
#   pragma clang optimize on
#elif defined(__INTEL_COMPILER)
#   pragma intel optimization_level 3
#endif


// C STANDARD
#ifndef _ISOC11_SOURCE  // C11
#   define _ISOC11_SOURCE
#endif
#ifndef __STDC_VERSION__
#   define __STDC_VERSION__   (201112L)  // C11
#endif
// ARCHITECTURE
#ifndef ARCHITECTURE_MACROS_SEEN
#define ARCHITECTURE_MACROS_SEEN
#if (defined(__thumb__) || defined(__ARMEL__) || defined(__ARM_EABI__) || defined(__arm__) || defined(__ARM_ARCH))
#   define ARCHARM
#   if (defined(__GNUC__))  // Ignore warnings that originate from the cross-compiler's system headers
#      pragma GCC diagnostic ignored "-Wcast-align"
#      pragma GCC diagnostic ignored "-Wcast-qual"
#      pragma GCC diagnostic ignored "-Wconversion"
#      pragma GCC diagnostic ignored "-Wformat-nonliteral"
#      pragma GCC diagnostic ignored "-Wpadded"
#      pragma GCC diagnostic ignored "-Wsign-conversion"
#      pragma GCC diagnostic ignored "-Wswitch-default"
#      pragma GCC diagnostic ignored "-Wtype-limits"
#   endif
#endif
// OPERATING-SYSTEM MACROS (GENERATE STANDARD OS MACROS CONSTANTS)
#ifdef EPLAN9  // Plan 9
#   define OSPLAN9
#elif defined(_AIX)
#   define OSAIX
#   define OSPOSIX
#   define OSUNIX
#elif (defined(__CYGWIN__) || defined(__CYGWIN32__))  // Cygwin
#   define OSCYGWIN
#   define OSPOSIX
#elif defined(__gnu_hurd__)  // GNU-Hurd
#   define OSHURD
#   define OSPOSIX
#elif (defined(_hpux) || defined(hpux) || defined(__hpux))  // HP-Unix
#   define OSHPUX
#   define OSPOSIX
#   define OSUNIX
#elif defined(__minix)  // Minix
#   define OSMINIX
#   define OSPOSIX
#elif (defined(__ANDROID__) && !defined(__gnu_linux__))  // Android
#   define OSANDROID
#   define OSLINUX
#   define OSPOSIX
#   ifdef _GNU_SOURCE  // Includes: ISO C89, ISO C99, POSIX.1, POSIX.2, BSD, SVID, X/Open, LFS, and GNU extensions
#      undef _GNU_SOURCE
#   endif
#   ifndef _FORTIFY_SOURCE
#      define _FORTIFY_SOURCE   (1)  // Adds lightweight checks that detect some buffer overflow errors
#   endif
#elif (defined(__linux__) || defined(linux) || defined(__linux)) || defined(__gnu_linux__) || defined(BOOST_OS_LINUX)  // Linux
#   define OSGNU
#   define OSLINUX
#   define OSPOSIX
#   ifndef _GNU_SOURCE
#      define _GNU_SOURCE  // Includes: ISO C89, ISO C99, POSIX.1, POSIX.2, BSD, SVID, X/Open, LFS, and GNU extensions
#   endif
#   ifndef _FORTIFY_SOURCE
#      define _FORTIFY_SOURCE   (1)  // Adds lightweight checks that detect some buffer overflow errors
#   endif
#elif (defined(__unix__) || defined(__unix) || defined(unix)) || (defined(__APPLE__) && defined(__MACH__))  // Unix-systems
#   define OSUNIX
#   define OSPOSIX
#   if (defined(macintosh) || defined(Macintosh) || defined(BOOST_OS_MACOS))
#      define OSMACOS
#   elif (defined(__APPLE__) && defined(__MACH__))
#      define OSOSX
#   elif (defined(__APPLE__) && !defined(__MACH__))
#      define OSAPPLE
#   elif (defined(__MACH__) && !defined(__APPLE__))
#      define OSNEXTSTEP
#   endif
#elif (defined(__MINGW32__) || defined(__MINGW64__) || defined(__WINNT__) || defined(__NT__) || defined(_WIN64) || defined(WIN64) || defined(_WIN32) || defined(WIN32) || defined(__WIN32__) || defined(BOOST_OS_WINDOWS) || defined(_UWIN) || defined(__TOS_WIN__) || defined(__WINDOWS__) || defined(_WIN32_WCE) || defined(_MSC_VER))  // Windows
#   define OSWINDOWS
#   ifdef _MSC_VER
#      define __func__   __FUNCTION__
#   endif
#   include <windows.h>
#   ifdef OSPOSIX
#      undef OSPOSIX  // Ensure `OSPOSIX` is not defined
#   endif
#   ifdef OSUNIX
#      undef OSUNIX  // Ensure `OSUNIX` is not defined
#   endif
#   ifdef _GNU_SOURCE
#      undef _GNU_SOURCE  // Ensure `_GNU_SOURCE` is not defined
#   endif
#   if (!defined(_FORTIFY_SOURCE) || _FORTIFY_SOURCE != 0)
#      define _FORTIFY_SOURCE   (0)  // Fix bug in MingW
#   endif
#   ifdef _WIN32
/* Windows names string functions differently from most other platforms */
#      define strncasecmp   _strnicmp
#      define strcasecmp   _stricmp
#   endif
#endif
#ifndef _GNU_SOURCE
#   ifdef OSPOSIX  // Set special POSIX macros
#      define _POSIX_SOURCE   (200809L)  // Includes POSIX functionality
#      define _POSIX_C_SOURCE   (200809L)  // Includes POSIX functionality
#   endif
#   ifdef OSUNIX  // Set special UNIX macros
#      define _XOPEN_SOURCE   (700)  // Includes functionality described in the X/Open Portability Guide
#      define _XOPEN_VERSION   (700)  // Includes functionality described in the X/Open Portability Guide
#      define _XOPEN_SOURCE_EXTENDED  // Includes extra functions for the X/Open Unix brand
#   endif
#endif
#if (defined(__DragonFly__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(_SYSTYPE_BSD) || defined(__bsdi__) || defined(BSD))  // BSD
#   undef _GNU_SOURCE
#   undef _POSIX_SOURCE
#   undef _POSIX_C_SOURCE
#   define _BSD_SOURCE
#   define _XOPEN_SOURCE   (700)  // Includes functionality described in the X/Open Portability Guide
#   define _XOPEN_VERSION   (700)  // Includes functionality described in the X/Open Portability Guide
#   define _XOPEN_SOURCE_EXTENDED  // Includes extra functions for the X/Open Unix brand
#   define OSBSD
#   define OSPOSIX
#   define OSUNIX
#elif (defined(__FreeBSD_kernel__ ) && defined(__GLIBC__ ))  // GNU-kFreeBSD
#   define OSGNU
#   define OSBSD
#   define OSPOSIX
#   define OSUNIX
#   define _GNU_SOURCE
#   define _POSIX_SOURCE   (200809L)  // Includes POSIX functionality
#   define _POSIX_C_SOURCE   (200809L)  // Includes POSIX functionality
#   ifdef _BSD_SOURCE
#      undef _BSD_SOURCE   // Deprecated in glibc
#   endif
#   if defined(__DragonFly__)
#      define OSDRAGONFLY
#   elif defined(__NetBSD__)
#      define OSNETBSD
#   elif defined(__OpenBSD__)
#      define OSOPENBSD
#   elif (defined(__FreeBSD__) || defined(__FreeBSD_kernel__))
#      define OSFREEBSD
#endif
#elif (defined(sun) || defined(__sun))  // Solaris, SunOS, etc.
#   define OSSUN
#   define OSPOSIX
#   define OSUNIX
#   if (defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__))  // Solaris
#      define OSSOLARIS
#   elif (defined(sun) || defined(__sun)) && !(defined(__SVR4) || defined(__svr4__))
#      define OSUNOS
#   endif
#endif
// 64-BIT OR 32-BIT? "#ifdef ENV64BIT"
#if (defined(__MINGW64__) || defined(__x86_64__) || defined(__x86_64) || defined(__amd64__) || defined(__ppc64__) || defined(ppc64le) || defined(__powerpc64__) || defined(__PPC64__) || defined(_ARCH_PPC64) || defined(_WIN64)) && !(defined(__MINGW32__) || defined(_WIN32) || defined(WIN32) || defined(__WIN32__))
#   ifndef ENV64BIT
#      define ENV64BIT
#   endif
#else
#   ifndef ENV32BIT
#      define ENV32BIT
#   endif
#endif
#if (defined(ENV64BIT) && (defined(__x86_64__) || defined(__x86_64))) && !(defined(ENV32BIT))
#   define INTEL64
#endif
#if (defined(__tune_sandybridge__) || defined(__tune_ivybridge__) || defined(__tune_haswell__) || defined(__tune_broadwell__) || defined(__tune_bonnell__) || defined(__tune_silvermont__) || defined(__tune_knl__) || defined(__tune_knight__))
#   define INTEL
#endif
// ENDIANNESS
#ifdef __BYTE_ORDER__
#   if (__ORDER_LITTLE_ENDIAN__ == __BYTE_ORDER__)
#      define ENDIAN_LITTLE
#   elif (__ORDER_BIG_ENDIAN__ == __BYTE_ORDER__)
#      define ENDIAN_BIG
#   elif (__ORDER_PDP_ENDIAN__ == __BYTE_ORDER__)
#      define ENDIAN_PDP
#   else
#      define ENDIAN_UNKNOWN
#   endif
#endif
#endif

#ifndef STANDARD_MACROS_SPECIAL_SEEN
#define STANDARD_MACROS_SPECIAL_SEEN
// SPECIAL INCLUDES
#ifdef OSUNIX
#   include <sys/param.h>
#endif
#if (defined(OSPOSIX) || defined(OSUNIX))
#   include <sys/types.h>  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_types.h.html
#   define SYS_TYPES_INCLUDED
#endif
#if (defined(OSLINUX) || defined(OSUNIX))
#   include <unistd.h>
#endif
#if (defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__))
#  include <fcntl.h>
#  include <io.h>
#endif
// TYPE SIZES
#if (defined(_LP64) || defined(__LP64__))
#   define DATAMODEL_LP64
#   define TYPESIZE_PTR   64
#elif (defined(_LP32) || defined(__LP32__))
#   define DATAMODEL_LP32
#   define TYPESIZE_PTR   32
#elif (defined(_ILP32) || defined(__ILP32__))
#   define DATAMODEL_ILP32
#   define TYPESIZE_PTR   32
#elif (defined(_ILP64) || defined(__ILP64__))
#   define DATAMODEL_ILP64
#   define TYPESIZE_PTR   64
#elif (defined(_LLP64) || defined(__LLP64__))
#   define DATAMODEL_LLP64
#   define TYPESIZE_PTR   64
#elif (defined(_SILP64) || defined(__SILP64__))
#   define DATAMODEL_SILP64
#   define TYPESIZE_PTR   64
#endif
#define TYPESIZE_CHAR   (sizeof(char))
#define TYPESIZE_SHORT   (sizeof(short))
#define TYPESIZE_INT   (sizeof(int))
#define TYPESIZE_LONG_INT   (sizeof(long int))
#define TYPESIZE_LONG_LONG   (sizeof(long long))
#define TYPESIZE_FLOAT   (sizeof(float))
#define TYPESIZE_DOUBLE   (sizeof(double))
#define TYPESIZE_LONG_DOUBLE   (sizeof(long double))
// C STANDARD LIBRARIES
#ifdef __GLIBC__
#   define STDLIB   "glibc"
#elif defined(__BIONIC__)
#   define STDLIB   "bionic"
#elif defined(__DIETLIBC__)
#   define STDLIB   "dietlibc"
#elif defined(__KLIBC__)
#   define STDLIB   "klibc"
#elif defined(__MUSL__)
#   define STDLIB   "musl"
#elif (defined(__GLIBCPP__) || defined(__GLIBCXX__))
#   error   "GNU-libstdc++ is not supported!"
#elif defined(__CRTL_VER)
#   error   "VMS-libc is not supported!"
#elif defined(__UCLIBC__)
#   error   "uClibc is not supported!"
#elif (defined(__LIBREL__) && defined(__TARGET_LIB__))
#   error   "z/OS-libc is not supported!"
#endif
/* MISCELLANEOUS HELPFUL MACROS CONSTANTS
__AES__
__AVX__
__AVX2__
__core_avx2
__tune_core_avx2__
__FMA__
__MMX__
__POPCNT__
__RDRND__
__SSE_MATH__
__SSE2_MATH__
__SSE__
__SSE2__
__SSE3__
__SSE4_2__
__SSSE3__
__NO_MATH_ERRNO__
__SIZEOF_INT__
__SIZEOF_LONG__
__SIZEOF_LONG_LONG__
__SIZEOF_SHORT__
__SIZEOF_POINTER__
__SIZEOF_FLOAT__
__SIZEOF_FLOAT80__
__SIZEOF_DOUBLE__
__SIZEOF_LONG_DOUBLE__
__SIZEOF_SIZE_T__
__SIZEOF_WCHAR_T__
__SIZEOF_WINT_T__
__SIZEOF_PTRDIFF_T__
__sandybridge
__sandybridge__
__haswell
__haswell__


__has_attribute
__has_builtin
__has_extension
__has_feature
__has_include
*/


/* STANDARD HEADERS */
/** IMPORTANT LIBRARY URLs

 * GNU-libc
https://www.gnu.org/software/gnulib/manual/html_node/Header-File-Substitutes.html

 * POSIX
http://pubs.opengroup.org/onlinepubs/9699919799/functions/contents.html

 * limits.h
http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/limits.h.html
http://www.cplusplus.com/reference/climits/
*/


#ifndef X86_EXTENSIONS_SEEN
#define X86_EXTENSIONS_SEEN
#   ifdef INTEL
#      include <immintrin.h>
#   else
#      ifdef __MMX__
#         include <mmintrin.h>
#      endif
#      ifdef __SSE__
#         include <xmmintrin.h>
#      endif
#      ifdef __SSE2__
#         include <emmintrin.h>
#      endif
#      ifdef __SSE3__
#         include <pmmintrin.h>
#      endif
#      ifdef __SSSE3__
#         include <tmmintrin.h>
#      endif
#      ifdef __SSE4_1__
#         include <smmintrin.h>
#      endif
#      ifdef __SSE4_2__
#         include <nmmintrin.h>
#      endif
#      ifdef __SSE4A__
#         include <ammintrin.h>
#      endif
#      ifdef __AES__
#         include <wmmintrin.h>
#      endif
#   endif
#endif

#include <complex.h>
#include <errno.h>
#include <float.h>  // http://www.cplusplus.com/reference/cfloat/
#include <inttypes.h>  // Also includes <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>


/* BOOLEAN TYPE (<stdbool.h> REPLACEMENT) */


#ifndef __bool_true_false_are_defined
#define __bool_true_false_are_defined   (1)
#define no   ((uint8_t)0x0)
#define NO   ((uint8_t)0x0)
#define yes   ((uint8_t)0x1)
#define YES   ((uint8_t)0x1)
#ifndef __cplusplus
#   ifndef false
#      define false   ((uint8_t)0x0)
#   endif
#   define False   ((uint8_t)0x0)
#   ifndef FALSE
#      define FALSE   ((uint8_t)0x0)
#   endif
#   define _FALSE   ((uint8_t)0x0)
#   ifndef true
#      define true   ((uint8_t)0x1)
#   endif
#   define True   ((uint8_t)0x1)
#   ifndef TRUE
#      define TRUE   ((uint8_t)0x1)
#   endif
#   define _TRUE   ((uint8_t)0x1)
#   ifndef bool
/** <stdbool.h> Replacement */
typedef _Bool   bool;
#   endif
#   if (!defined(BOOL) && !defined(OSWINDOWS))
/** Support Objective-C-Style "BOOL" datatype */
typedef _Bool   BOOL;
#   endif
#else
#   define False   (false)
#   define FALSE   (false)
#   define _FALSE   (false)
#   define True   (true)
#   define TRUE   (true)
#   define _TRUE   (true)
#endif
#endif


/* STDARG (<stdarg.h> REPLACEMENT) */


#ifdef __cplusplus
extern "C" {
#endif
#if ((__GNUC__ >= 3) && !defined(GNU_EFI_USE_EXTERNAL_STDARG) && !defined(va_end) && !defined(va_arg))
typedef __builtin_va_list   va_list;
#ifndef __GNUC_VA_LIST
#   define __GNUC_VA_LIST   (1)
typedef __builtin_va_list   __gnuc_va_list;  // Hack to make standard headers work on Ubuntu
#endif
#define va_arg   __builtin_va_arg
//#define va_arg(v,DATATYPE)   (__builtin_va_arg((v), (DATATYPE)))
//#define va_end   __builtin_va_end
#define va_end(v)   (__builtin_va_end((v)))
#define va_start(v,argnum)   (__builtin_va_start((v), (argnum)))
#define __va_copy(dest,src)   (__builtin_va_copy((dest), (src)))
// GCC only defines `va_copy` c99 mode, or if `-ansi` is not specified; va_copy is not in C90
#if ((__STDC_VERSION__ >= 199900L) || (!defined(__STRICT_ANSI__)))
#   define va_copy(dest, src)   __builtin_va_copy((dest), (src))
#endif
#else  // This is not GNU-GCC3, or <stdarg.h> is needed directly
#   include <stdarg.h>
#endif
#ifdef __cplusplus
}
#endif


/* TYPE ALIASES */


#ifndef TYPE_ALIASES_SEEN
#define TYPE_ALIASES_SEEN
#if (!defined(__GNUC__) && !defined(__asm__))
#   define __asm__    asm
#endif
#if (defined(__GNUC__) && !defined(ptrdiff_t))
#   define ptrdiff_t   __PTRDIFF_TYPE__
#if !defined(__cplusplus)
#   define wchar_t   __WCHAR_TYPE__
#endif
#else  // This is not GNU-GCC
#   define ptrdiff_t   signed long
#   define wchar_t   int
#endif
#if (defined(OSWINDOWS) && !defined(WEOF))
#   define WEOF   ((wchar_t)(0xFFFF))
#endif
#define slint   signed long int
#define sllint   signed long long int
#define uint   unsigned int
#define ulint   unsigned long int
#define ullint   unsigned long long int
#define single   float
#define Byte   uint8_t
#define Word   unsigned long
#define s8   signed char
#define u8   unsigned char
#define utf32   uint32_t
#if ((UINT_MAX) >= 4294967295UL)
#   define s16   signed short
#   define s32   signed int
#   define u16   unsigned short
#   define u32   unsigned int
#   define ONE32   (0xFFFFFFFFU)
#else
#   define s16   signed int
#   define s32   signed long
#   define u16   unsigned int
#   define u32   unsigned long
#   define ONE32   (0xFFFFFFFFUL)
#endif
// 128-bit Integers
#if (defined(__GNUC__) && defined(__GLIBC__) && defined(ENV64BIT) && !(defined(uint128_t) && defined(__uint128_t)))
/** 128-bit signed integer datatype (not all systems support int128_t) */
typedef signed int128_t   __attribute__((mode(TI)));
/** 128-bit unsigned integer datatype (not all systems support uint128_t) */
typedef unsigned uint128_t   __attribute__((mode(TI)));
#   define INT128_SUPPORTED   (1)
#   define UINT128_SUPPORTED   (1)
#   ifndef __SIZEOF_INT128__
#      define __SIZEOF_INT128__   (sizeof(int128_t))
#   endif
#   ifndef __SIZEOF_UINT128__
#      define __SIZEOF_UINT128__   (sizeof(uint128_t))
#   endif
#   ifndef TYPESIZE_INT128
#      define TYPESIZE_INT128   (sizeof(int128_t))
#   endif
#   ifndef TYPESIZE_UINT128
#      define TYPESIZE_UINT128   (sizeof(uint128_t))
#   endif
#else
#   define INT128_UNSUPPORTED
#   define UINT128_UNSUPPORTED
#endif
// 128-bit Floats
#if (defined(__GNUC__) && defined(__GLIBC__) && defined(ENV64BIT) && !defined(__float128))
/** 128-bit quad-precision floats may be supported via the synonymous datatypes tetra, float128_t, __float128, and float128 */
#   define FLOAT128_SUPPORTED   (1)
#   ifdef __clang__
typedef struct __cast__float128 {  // Work-around for Clang
    uint8_t x[16] __attribute__((aligned(16)));
} __float128;
#   endif
#   ifndef __SIZEOF_FLOAT128__
#      define __SIZEOF_FLOAT128__   (sizeof(__float128))
#   endif
#   ifndef TYPESIZE_FLOAT128
#      define TYPESIZE_FLOAT128   (sizeof(__float128))
#   endif
#   ifndef float128_t
#      define float128_t   __float128
#   endif
#   ifndef float128
#      define float128   __float128
#   endif
#   ifndef tetra
#      define tetra   __float128
#   endif
#else
#   define FLOAT128_UNSUPPORTED   (1)
#endif
// Imaginary Numbers
#ifndef IMAGINARY_NUMBER_CONSTANTS_SEEN
#define IMAGINARY_NUMBER_CONSTANTS_SEEN
#ifndef I_FLOAT
#   define I_FLOAT   (__extension__ 1.0Fi)  // (const float _Complex)1.0F
#   define I_FLOAT_NEG   (__extension__ -1.0Fi)
#   define I_FLOAT_ZERO   (__extension__ 0.0Fi)
#endif
#ifndef I_DOUBLE
#   define I_DOUBLE   (__extension__ 1.0i)  // (const double _Complex)1.0
#   define I_DOUBLE_NEG   (__extension__ -1.0i)
#   define I_DOUBLE_ZERO   (__extension__ 0.0i)
#endif
#ifndef I_LONG_DOUBLE
#   define I_LONG_DOUBLE   (__extension__ 1.0Li)  // (const long double _Complex)1.0L
#   define I_LONG_DOUBLE_NEG   (__extension__ -1.0Li)
#   define I_LONG_DOUBLE_ZERO   (__extension__ 0.0Li)
#endif
#ifndef TYPESIZE_I_FLOAT
#   define TYPESIZE_I_FLOAT   (sizeof(I_FLOAT))
#endif
#ifndef TYPESIZE_I_DOUBLE
#   define TYPESIZE_I_DOUBLE   (sizeof(I_DOUBLE))
#endif
#ifndef TYPESIZE_I_LONG_DOUBLE
#   define TYPESIZE_I_LONG_DOUBLE   (sizeof(I_LONG_DOUBLE))
#endif
#ifndef __SIZEOF_I_FLOAT__
#   define __SIZEOF_I_FLOAT__   (sizeof(I_FLOAT))
#endif
#ifndef __SIZEOF_I_DOUBLE__
#   define __SIZEOF_I_DOUBLE__   (sizeof(I_DOUBLE))
#endif
#ifndef __SIZEOF_I_LONG_DOUBLE__
#   define __SIZEOF_I_LONG_DOUBLE__   (sizeof(I_LONG_DOUBLE))
#endif
#endif  // IMAGINARY_NUMBER_CONSTANTS_SEEN
// PRINTF
#ifdef _MSC_VER
/** Casts the uint64_t value in `x` to the right type for an argument to printf. */
#   define U64_PRINTF_ARG(x)   (x)
/** Casts the `uint64_t *` value in `x` to the right type for an argument to scanf. */
#   define U64_SCANF_ARG(x)   (x)
/** Expands to a literal uint64_t-typed constant for the value `n`. */
#   define U64_LITERAL(n)   (n ## ui64)
#   define I64_PRINTF_ARG(x)   (x)
#   define I64_SCANF_ARG(x)   (x)
#   define I64_LITERAL(n)   (n ## i64)
#else
#   define U64_PRINTF_ARG(x)   ((ullint)(x))
#   define U64_SCANF_ARG(x)   ((ullint *)(x))
#   define U64_LITERAL(n)   (n ## llu)
#   define I64_PRINTF_ARG(x)   ((sllint)(x))
#   define I64_SCANF_ARG(x)   ((sllint *)(x))
#   define I64_LITERAL(n)   (n ## ll)
#endif
#if (defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__))
/** The formatting string used to put a uint64_t value in a printf() or scanf() function. */
#   define U64_FORMAT   "%I64u"
#   define I64_FORMAT   "%I64d"
#else
#   define U64_FORMAT   "%llu"
#   define I64_FORMAT   "%lld"
#endif
#endif  // TYPE_ALIASES_SEEN


/* NUMBER TUPLES */


#ifndef NUMBER_TUPLES_SEEN
#define NUMBER_TUPLES_SEEN
typedef struct { double x, y; } doublepair_t;
typedef struct { float x, y; } floatpair_t;
typedef struct { long double x, y; } longdoublepair_t;
typedef struct { uint8_t x, y; } bytepair_t;
typedef struct { signed int x, y; } intpair_t;
typedef struct { slint x, y; } slintpair_t;
typedef struct { ulint x, y; } ulintpair_t;
typedef struct { ullint x, y; } ullintpair_t;
typedef struct { sllint x, y; } sllintpair_t;
typedef struct { double x, y, z; } doubletriplet_t;
typedef struct { float x, y, z; } floattriplet_t;
#ifndef INT128_UNSUPPORTED
typedef struct { int128_t x, y; } int128pair_t;
typedef struct { int128_t x, y, z; } int128triplet_t;
#endif
#ifndef UINT128_UNSUPPORTED
typedef struct { uint128_t x, y; } uint128pair_t;
typedef struct { uint128_t x, y, z; } uint128triplet_t;
#endif
#ifndef FLOAT128_UNSUPPORTED
typedef struct { float128 x, y; } float128pair_t;
typedef struct { float128 x, y, z; } float128triplet_t;
#endif
#endif  // NUMBER_TUPLES_SEEN


/* INTEGER CONSTANTS */


#if (((!defined(__cplusplus)) || defined(__STDC_CONSTANT_MACROS)) && !defined(INT32_C))
#   define INT8_C(num)   ((int8_t)(num))
#   define INT16_C(num)   ((int16_t)(num))
#   define INT32_C(num)   ((int32_t)(num) ## L)
#   define INT64_C(num)   ((int64_t)num ## LL)
#   define UINT8_C(num)   ((uint8_t)(num))
#   define UINT16_C(num)   ((uint16_t)(num))
#   define UINT32_C(num)   ((uint32_t)(num) ## UL)
#   define UINT64_C(num)   ((uint64_t)(num) ## ULL)
#   define INTMAX_C(num)   ((int64_t)(num) ## LL)
#   define UINTMAX_C(num)   ((uint64_t)(num) ## ULL)
#endif
#ifndef WCHAR_MAX
#   define WCHAR_MAX   INT32_MAX
#endif


/* CTYPE MACROS (<ctype.h> REPLACEMENT) */


/** a=0x61; z=0x7A; A=0x41; Z=0x5A
https://en.wikipedia.org/wiki/ASCII
https://en.wikipedia.org/wiki/Latin-1_Supplement_%28Unicode_block%29
*/


#ifndef CTYPE_MACROS_SEEN
#define CTYPE_MACROS_SEEN
/** Test if the char is alphanumeric */
#define ISALNUM(c)   ((uint8_t)(((((0x60u<(uint8_t)(c))&((uint8_t)(c)<0x80u))|((0x40u<(uint8_t)(c))&((uint8_t)(c)<0x60u))))|(((0x2Fu<(uint8_t)(c))&((uint8_t)(c)<0x3Au)))))
/** Test if the char is alphanumeric */
#define ISALPHANUM(c)   ((uint8_t)(((((0x60<(uint8_t)(c))&((uint8_t)(c)<0x80))|((0x40<(uint8_t)(c))&((uint8_t)(c)<0x60))))|(((0x2F<(uint8_t)(c))&((uint8_t)(c)<0x3A)))))
/** Test if the char is an alphabetic letter */
#define ISALPHA(c)   ((uint8_t)((((0x60u<(uint8_t)(c))&((uint8_t)(c)<0x80u))|((0x40u<(uint8_t)(c))&((uint8_t)(c)<0x60u)))))
/** Test if the char is an ASCII symbol */
#define ISASCII(c)   ((uint8_t)((uint8_t)(c)<0x80u))
/** Test if the char is the bell character (\b) */
#define ISBELL(c)   ((uint8_t)((uint8_t)(c)==0x07u))
/** Test if the char is a space or tab (\t) character */
#define ISBLANK(c)   ((uint8_t)(((uint8_t)(c)==0x20u)|((uint8_t)(c)==0x09u)))
/** Test if the char is a control character */
#define ISCNTRL(c)   ((uint8_t)(((uint8_t)(c)<0x20u)|((0x7Eu<(uint8_t)(c))&((uint8_t)(c)<0xA0u))))
/** Test if the char is a currency symbol */
#define ISCURRENCY(c)   ((uint8_t)(((uint8_t)(c)==0x24u)|((0xA1u<(uint8_t)(c))&((uint8_t)(c)<0xA6u))))
/** Test if the char is a digit */
#define ISDIGIT(c)   ((uint8_t)(((0x2Fu<(uint8_t)(c))&((uint8_t)(c)<0x3Au))))
/** Test if the char is an alphabetic letter in the Latin-1 Supplement block */
#define ISEXTALPHA(c)   ((uint8_t)(((((0xBFu<(uint8_t)(c))&((uint8_t)(c)<0xD7u))|((0xD7u<(uint8_t)(c))&((uint8_t)(c)<0xDFu)))|(((0xDEu<(uint8_t)(c))&((uint8_t)(c)<0xF7u))|((0xF7u<(uint8_t)(c)))))))  // Latin-1 Supplement
/** Test if the char is a lowercase alphabetic letter in the Latin-1 Supplement block */
#define ISEXTLOWER(c)   ((uint8_t)((((0xDEu<(uint8_t)(c))&((uint8_t)(c)<0xF7u))|((0xF7u<(uint8_t)(c))))))  // Latin-1 Supplement
/** Test if the char is a uppercase alphabetic letter in the Latin-1 Supplement block */
#define ISEXTUPPER(c)   ((uint8_t)((((0xBFu<(uint8_t)(c))&((uint8_t)(c)<0xD7u))|((0xD7u<(uint8_t)(c))&((uint8_t)(c)<0xDFu)))))  // Latin-1 Supplement
/** Test if the char is a graphical character */
#define ISGRAPH(c)   ((uint8_t)((0x20u<(uint8_t)(c))&((uint8_t)(c)<0x80u)))
/** Test if the char is a printable character */
#define ISPRINT(c)   ((uint8_t)((0x1Fu<(uint8_t)(c))&((uint8_t)(c)<0x80u)))
/** Test if the char is a punctuation character */
#define ISPUNCT(c)   ((uint8_t)(((0x20u<(uint8_t)(c))&((uint8_t)(c)<0x80u))&(!((((((0x60u<(uint8_t)(c))&((uint8_t)(c)<0x80u))|((0x40u<(uint8_t)(c))&((uint8_t)(c)<0x60u))))|(((0x2Fu<(uint8_t)(c))&((uint8_t)(c)<0x3Au))))))))
/** Test if the char is a separator control character */
#define ISSEPARATOR(c)   ((uint8_t)((0x1Bu<(uint8_t)(c))&((uint8_t)(c)<0x20u)))
/** Test if the char is a space character (space, tab, form-feed, etc.) */
#define ISSPACE(c)   ((uint8_t)(((uint8_t)(c)==0x20u)|((0x8u<(uint8_t)(c))&((uint8_t)(c)<0xEu))))
/** Test if the char is a lowercase ASCII character */
#define ISLOWERASCII(c)   ((uint8_t)(((0x60u<(uint8_t)(c))&((uint8_t)(c)<0x80u))))  // ASCII only
/** Test if the char is a lowercase character */
#define ISLOWER(c)   ((uint8_t)((((0x60u<(uint8_t)(c))&((uint8_t)(c)<0x80u))|((0xDEu<(uint8_t)(c))&((uint8_t)(c)<0xF7u))|((0xF7u<(uint8_t)(c))))))  // All letters under 0xFF
/** Test if the char is a uppercase ASCII character */
#define ISUPPERASCII(c)   ((uint8_t)(((0x40u<(uint8_t)(c))&((uint8_t)(c)<0x60u))))  // ASCII only
/** Test if the char is a uppercase character */
#define ISUPPER(c)   ((uint8_t)((((0x40u<(uint8_t)(c))&((uint8_t)(c)<0x60u))|((0xBFu<(uint8_t)(c))&((uint8_t)(c)<0xD7u))|((0xD7u<(uint8_t)(c))&((uint8_t)(c)<0xDFu)))))  // All letters under 0xFF
/** Test if the char is a hexadecimal digit */
#define ISXDIGIT(c)   ((uint8_t)((((0x2Fu<(uint8_t)(c))&((uint8_t)(c)<0x3Au)))|((0x40u<(uint8_t)(c))&((uint8_t)(c)<0x47u))|((0x60u<(uint8_t)(c))&((uint8_t)(c)<0x67u))))
/** Convert the char to an ASCII character */
#define TOASCII(c)   ((uint8_t)((uint8_t)(c)&0x7Fu))
/** Convert the char to a lowercase ASCII letter */
#define TOLOWER(c)   ((uint8_t)((uint8_t)(c)+0x20u))
/** Convert the char to a uppercase ASCII letter */
#define TOUPPER(c)   ((uint8_t)((uint8_t)(c)-0x20u))
// UNICODE
#if (WCHAR_MAX == 32)
/** Test if the wchar is a lowercase wide-character */
#   define WISLOWER(w)   ((uint32_t)(((0x60u<(uint32_t)(w))&((uint32_t)(w)<0x80u))))
/** Test if the wchar is a uppercase wide-character */
#   define WISUPPER(w)   ((uint32_t)(((0x40u<(uint32_t)(w))&((uint32_t)(w)<0x60u))))
/** Convert the wchar to a lowercase wide ASCII letter */
#   define WTOLOWER(w)   (((WISUPPER(w)) ? ((uint32_t)(w)+0x20u) : (uint32_t)(w) ))
/** Convert the wchar to a uppercase wide ASCII letter */
#   define WTOUPPER(w)   (((WISLOWER(w)) ? ((uint32_t)(w)-0x20u) : (uint32_t)(w) ))
#elif (WCHAR_MAX == 16)
/** Test if the wchar is a lowercase wide-character */
#   define WISLOWER(w)   ((uint16_t)(((0x60u<(uint16_t)(w))&((uint16_t)(w)<0x80u))))
/** Test if the wchar is a uppercase wide-character */
#   define WISUPPER(w)   ((uint16_t)(((0x40u<(uint16_t)(w))&((uint16_t)(w)<0x60u))))
/** Convert the wchar to a lowercase wide ASCII letter */
#   define WTOLOWER(w)   (((WISUPPER(w)) ? ((uint16_t)(w)+0x20u) : (uint16_t)(w) ))
/** Convert the wchar to a uppercase wide ASCII letter */
#   define WTOUPPER(w)   (((WISLOWER(w)) ? ((uint16_t)(w)-0x20u) : (uint16_t)(w) ))
#endif
#endif  // CTYPE_MACROS_SEEN


/* SPECIAL MACROS */
// ARRAY SIZES
#define ARRAYLEN(arrayname)   ((sizeof(arrayname) / sizeof(*arrayname)))
#define ARRAYITEMSIZE(arrayname)   (sizeof(*arrayname))
#define GETARRAYSIZE(arrayname)   (sizeof(arrayname))
// ATTRIBUTE MACROS
#ifdef __GNUC__
#   define ATTR_NORETURN   __attribute__((noreturn))
#   define ATTR_CONST   __attribute__((const))
#   define ATTR_MALLOC   __attribute__((malloc))
#   define ATTR_NORETURN   __attribute__((noreturn))
#   define ATTR_UNUSED   __attribute__((unused))
/**
    Evaluates to `exp` and hints that the value of `exp` will probably be true.\n
    In other words, "if (PREDICT_LIKELY(foo))" is the same as "if (foo)", except that it tells the compiler that the branch will be taken most of the time. This can generate slightly better code with some CPUs.
*/
#   define PREDICT_LIKELY(exp)   __builtin_expect(!!(exp), 0x1)
/**
    Evaluates to `exp` and hints that the value of `exp` will probably be false.\n
    In other words, "if (PREDICT_UNLIKELY(foo))" is the same as "if (foo)", except that it tells the compiler that the branch will usually not be taken. This can generate slightly better code with some CPUs.
*/
#   define PREDICT_UNLIKELY(exp)   __builtin_expect(!!(exp), 0x0)
#else
#   define ATTR_NORETURN
#   define ATTR_CONST
#   define ATTR_MALLOC
#   define ATTR_NORETURN
#   define ATTR_UNUSED
#   define PREDICT_LIKELY(exp)   ((exp))
#   define PREDICT_UNLIKELY(exp)   ((exp))
#endif
// ERRORS
#define ALLOC_ERROR()   fputs("ERROR: Failed to allocate memory!\n", stderr); exit(EXIT_FAILURE);
#define ALLOC_WRITE_ERROR()   fputs("ERROR: Failed to allocate memory to write file!\n", stderr); exit(EXIT_FAILURE);
#define EXIT_ON_ERROR(msg)   fprintf(stderr, "ERROR: "#msg"!\n%s\n", strerror(errno)); exit(EXIT_FAILURE);
#define EXIT_ON_ERROR_ARG(msg, data)   fprintf(stderr, "ERROR: "#msg"!\n%s\n", data, strerror(errno)); exit(EXIT_FAILURE);
#define ERROR_EXIT(msg)   perror("ERROR: "#msg"!\n"); exit(EXIT_FAILURE);
#define FAILED_OPEN_FILE()   fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno)); exit(EXIT_FAILURE);
#define INVALID_ARGS()   fputs("ERROR: Invalid number of arguments!\n", stderr); exit(EXIT_FAILURE);
#define RETURN_ON_ERROR(msg)   perror("ERROR: "#msg"!\n"); return 1;
#define UNABLE_TO_APPEND_FILE()   fputs("ERROR: Unable to append data to file!\n", stderr); exit(EXIT_FAILURE);
#define UNABLE_TO_READ_FILE()   fputs("ERROR: Unable to read file!\n", stderr); exit(EXIT_FAILURE);
#define UNABLE_TO_WRITE_FILE()   fputs("ERROR: Unable to write file!\n", stderr); exit(EXIT_FAILURE);
// FILE I/O
#define OPENFILE(_filename, _mode)   FILE *fileptr = fopen((_filename), (_mode)); if (fileptr == (FILE *)NULL) { FAILED_OPEN_FILE() }
#define GETFILECONTENTS(_filename, _DATASIZE, _DATAVAR, _FILEPTR)   FILE *(_FILEPTR) = fopen((_filename), "rb"); if (!(_FILEPTR)) { FAILED_OPEN_FILE() } uint8_t *(_DATAVAR) = (uint8_t *)calloc((size_t)0x01, (_DATASIZE)); if ((_DATAVAR) == (uint8_t *)NULL) { ALLOC_ERROR() } if ((size_t)(fread((_DATAVAR), (size_t)0x01, (size_t)(_DATASIZE), (_FILEPTR))) != (size_t)(_DATASIZE)) { ERROR_EXIT("Unable to read file") } fclose((_FILEPTR));
// MISCELLANEOUS
#ifndef NIL
#   define NIL  (((void *)0x00))
#endif
#ifndef STMT_NIL
/** Expands to a syntactically valid empty statement */
#   define STMT_NIL   ((void)0x0)
#endif
#ifndef STMT_VOID
/** Expands to a syntactically valid empty statement, explicitly voiding its argument */
#   define STMT_VOID(x)   while (0x0) { (void)(x); }
#endif
#ifdef __GNUC__
/** STMT_BEGIN and STMT_END are used to wrap blocks inside macros so that the macro can be used as if it were a single C statement. */
#   define STMT_BEGIN   (void) ({
#   define STMT_END   })
#elif (defined(sun) || defined(__sun__))
#   define STMT_BEGIN   if (0x1) {
#   define STMT_END   } else STMT_NIL
#else
#   define STMT_BEGIN   do {
#   define STMT_END   } while (0x0)
#endif
/** Convert a float to uint32_t */
#define FLT_TO_U32(x)   ((uint32_t) (x))
/** Convert a uint32_t to float */
#define U32_TO_FLT(x)   ((float) (x))
/** Convert a double to uint64_t */
#define DBL_TO_U64(x)   ((uint64_t) (x))
/** Convert a uint64_t to double */
#define U64_TO_DBL(x)   ((double) (x))
// OPERATIONS
#define ABS(x)   ((x) >= 0x00 ? (x) : -(x))
#define ORSWAP(x, y)   ((x)|=(y), (x)|=(y), (x)|=(y))
#define XORSWAP(x, y)   ((x)^=(y), (x)^=(y), (x)^=(y))
#define SWAP(x, y)   ( (y) = (x), (x) = (y) )
#define AND(x, y)  ((x) & (y))
#define OR(x, y)  ((x) | (y))
#define NOT(x)  (~(x))
#define NAND(x, y)  (~((x) & (y)))
#define NOR(x, y)  (~((x) | (y)))
#define XOR(x, y)  ((x) ^ (y))
#define XNOR(x, y)  (~((x) ^ (y)))
#define NXOR(x, y)  (~((x) ^ (y)))
#define BYTESWAP8(x)   ((uint8_t)((x) << (uint8_t)0x4) | (uint8_t)((x) >> (uint8_t)0x4))
#define BYTESWAP16(x)   ((uint16_t)((x) << (uint16_t)0x8) | (uint16_t)((x) >> (uint16_t)0x8))
#define BYTESWAP32(x)   (((x) >> 0x18) | (((x) >> 0x8) & 0xFF00u) | (((x) << 0x8) & 0xFF0000u) | ((x) << 0x18))
// OPERATORS
#define OP_LT   <
#define OP_GT   >
#define OP_GE   >=
#define OP_LE   <=
#define OP_EQ   ==
#define __IS__   ==
#define OP_NE   !=
// STRING COPY AND CONCATENATION
#define CONCATSTRING(DEST, SOURCE, DSTLEN, SRCLEN)   ((void *)memmove((void *)((DEST) + (DSTLEN)), (const void *)(SOURCE), (size_t)((size_t)(SRCLEN) + 1)))
#define COPYSTRING(DEST, SOURCE, SRCLEN)   ((void *)memmove((void *)(DEST), (const void *)(SOURCE), (size_t)((size_t)(SRCLEN) + 1)))
// TOKENS
#define PRINT_TOKEN(token)   (printf((#token)"\n"))
#define SHOW_INT_VAL(token)   (printf((#token)" is %d\n", (token)))
#define SHOW_DOUBLE_VAL(token)   (printf((#token)" is %f\n", (token)))
#define DO_EXPAND(VAL)   ((VAL))  // Used to test macros values
#define EXPAND_MACROS(VAL)   ((VAL))  // Used to test macros values
#define CAT(x, y)   ((x) ## (y))
// TYPENAME
#ifndef typename
#define typename(x)   _Generic((x), \
    _Bool: "_Bool", \
    unsigned char: "unsigned char", \
    char: "char", \
    signed char: "signed char", \
    short int: "short int", \
    unsigned short int: "unsigned short int", \
    int: "int", \
    unsigned int: "unsigned int", \
    long int: "long int", \
    unsigned long int: "unsigned long int", \
    long long int: "long long int", \
    unsigned long long int: "unsigned long long int", \
    float: "float", \
    __float128: "__float128", \
    double: "double", \
    long double: "long double", \
    float complex: "float complex", \
    double complex: "double complex", \
    long double complex: "long double complex", \
    char *: "pointer to char", \
    unsigned char *: "pointer to unsigned char", \
    signed char *: "pointer to signed char", \
    int *: "pointer to int", \
    unsigned int *: "pointer to unsigned int", \
    void *: "pointer to void", \
    default: "other")
#endif


/* SPECIAL STATEMENT-EXPR MACROS (GCC EXTENSIONS)*/


#ifdef __GNUC__
#define __MAXINT(x, y)   ({int _x = (x), _y = (y); _x > _y ? _x : _y; })
#define __MININT(x, y)   ({int _x = (x), _y = (y); _x > _y ? _y : _x; })
#define __MAX(x, y)   ({ __auto_type _x = (x); __auto_type _y = (y); _x > _y ? _x : _y; })
#define __MIN(x, y)   ({ __auto_type _x = (x); __auto_type _y = (y); _x > _y ? _y : _x; })
#define __AND(x, y)  ({ __auto_type _x = (x); __auto_type _y = (y); (_x & _y); })
#define __OR(x, y)  ({ __auto_type _x = (x); __auto_type _y = (y); (_x | _y); })
#define __NOT(x)  ({ __auto_type _x = (x); (~_x); })
#define __COMP2(x)  ({ __auto_type _x = (x); (~_x) + 1; })
#define __NAND(x, y)  ({ __auto_type _x = (x); __auto_type _y = (y); ~(_x & _y); })
#define __NOR(x, y)  ({ __auto_type _x = (x); __auto_type _y = (y); ~(_x | _y); })
#define __XOR(x, y)  ({ __auto_type _x = (x); __auto_type _y = (y); (_x ^ _y); })
#define __XNOR(x, y)  ({ __auto_type _x = (x); __auto_type _y = (y); ~(_x ^ _y); })
#define __NXOR(x, y)  ({ __auto_type _x = (x); __auto_type _y = (y); ~(_x ^ _y); })
#endif


#endif
#endif

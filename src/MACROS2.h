// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file MACROS2.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Standard Macros Header with AT&T-style Assembly
@version 2017.07.15

@section DESCRIPTION
This file defines various datatypes and macros functions used in MACROS.h.

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


#ifdef COMPILER_CLANG
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wshadow"
#elif defined(COMPILER_GNUC)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wshadow"
#endif


/* BEOS BUILD (<BeBuild.h>) */


#if (!(defined(_BE_BUILD_H) || defined(_BE_BUILD_H_)))
#define _BE_BUILD_H   (1)
#define _BE_BUILD_H_   (1)


#define B_BEOS_VERSION_4   0x400
#define B_BEOS_VERSION_4_5   0x450
#define B_BEOS_VERSION_5   0x500
#define B_BEOS_VERSION   B_BEOS_VERSION_5
#define B_BEOS_VERSION_MAUI   B_BEOS_VERSION_5
#define B_HAIKU_VERSION_BEOS   1
#define B_HAIKU_VERSION_BONE   2
#define B_HAIKU_VERSION_DANO   3
#define B_HAIKU_VERSION_1_ALPHA_1   0x100
#define B_HAIKU_VERSION_1_PRE_ALPHA_2   0x101
#define B_HAIKU_VERSION_1_ALPHA_2   0x200
#define B_HAIKU_VERSION_1_PRE_ALPHA_3   0x201
#define B_HAIKU_VERSION_1_ALPHA_3   0x300
#define B_HAIKU_VERSION_1_PRE_ALPHA_4   0x301
#define B_HAIKU_VERSION_1_ALPHA_4   0x400
#define B_HAIKU_VERSION_1_PRE_BETA_1   0x401
#define B_HAIKU_VERSION_1   0x10000
#define B_HAIKU_VERSION   B_HAIKU_VERSION_1_PRE_ALPHA_4
#define B_HAIKU_ABI_MAJOR   0xffff0000
#define B_HAIKU_ABI_GCC_2   0x20000
#define B_HAIKU_ABI_GCC_4   0x40000
#define B_HAIKU_ABI_GCC_2_ANCIENT   0x20000
#define B_HAIKU_ABI_GCC_2_BEOS   0x20001
#define B_HAIKU_ABI_GCC_2_HAIKU   0x20002
#define B_HAIKU_ABI_NAME   __HAIKU_ARCH_ABI
#if (defined(__GNUC__) && (__GNUC__ == 2))
#   define B_HAIKU_ABI   B_HAIKU_ABI_GCC_2_HAIKU
#elif (defined(__GNUC__) && AT_LEAST_GCC4)
#   define B_HAIKU_ABI   B_HAIKU_ABI_GCC_4
#endif
#ifndef B_HAIKU_BITS
#   define B_HAIKU_BITS   HAIKU_ARCH_BITS
#endif
#ifndef B_HAIKU_PHYSICAL_BITS
#   define B_HAIKU_PHYSICAL_BITS   __HAIKU_ARCH_PHYSICAL_BITS
#endif
#ifdef __HAIKU_BEOS_COMPATIBLE
#   define B_HAIKU_BEOS_COMPATIBLE   1
#endif


#endif  // BE_BUILD_H


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

static const UNUSED int days_per_month[16] = { 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 0, 0, 0 };
static const UNUSED int secs_through_month[16] = { 0, 2678400, 5097600, 7776000, 10368000, 13046400, 15638400, 18316800, 20995200, 23587200, 26265600, 28857600, 0, 0, 0, 0 };


#endif  // TIME_CONSTANTS_MACROS


/* ISO646 ALTERNATIVE OPERATOR SPELLINGS (<iso646.h>) */


#if (!(defined(ISO646_H) || defined(_ISO646_H) || defined(_ISO646_H_) || defined(_PDCLIB_ISO646_H)))  // http://www.cplusplus.com/reference/ciso646/ & http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/iso646.h.html
#define ISO646_H   (1)
#define _ISO646_H   (1)
#define _ISO646_H_   (1)
#define _PDCLIB_ISO646_H   (1)


#if IS_NOT_CPLUSPLUS
#   define and   &&
#   define and_eq   &=
#   define bitand   &
#   define bitor   |
#   define compl   ~
#   define not   !
#   define not_eq   !=
#   define or   ||
#   define or_eq   |=
#   define xor   ^
#   define xor_eq   ^=
#endif  // IS_NOT_CPLUSPLUS

// Extensions
#define left_shift   <<
#define right_shift   >>
#define left_shift_eq   <<=
#define right_shift_eq   >>=
#define bitnot   ~
#define greater_than   >
#define less_than   <
#define greater_than_eq   >=
#define less_than_eq   <=
#define equals_eq   ==
#define add_eq   +=
#define sub_eq   -=
#define min_eq   -=
#define mul_eq   *=
#define div_eq   /=
#define mod_eq   %=
#define OP_LT   <
#define OP_GT   >
#define OP_GE   >=
#define OP_LE   <=
#define OP_EQ   ==
#define OP_NE   !=
#ifndef __IS__
#   define __IS__   ==
#endif
#ifndef ADDITION
#   define ADDITION   +
#endif
#ifndef SUB
#   define SUB   -
#endif
#ifndef MUL
#   define MUL   *
#endif
#ifndef DIV
#   define DIV   /
#endif
#ifndef MOD
#   define MOD   %
#endif
#ifndef PREINCREMENT
#   define PREINCREMENT(num)   (++(num))
#endif
#ifndef POSTINCREMENT
#   define POSTINCREMENT(num)   ((num)++)
#endif
#ifndef PREDECREMENT
#   define PREDECREMENT(num)   (--(num))
#endif
#ifndef POSTDECREMENT
#   define POSTDECREMENT(num)   ((num)--)
#endif
#if (defined(_SYSTEM) && (!defined(_SIGN)))
#   define _SIGN   -
#elif (!defined(_SIGN))
#   define _SIGN
#endif


#endif  // ISO646_H


/* BOOLEAN DATATYPE (<stdbool.h>) */


#if (!(defined(__bool_true_false_are_defined) || defined(STDBOOL_H) || defined(__STDBOOL_H) || defined(__STDBOOL_H_) || defined(_BOOL_H) || defined(_DEF_WINBOOL_) || defined(_BOOLEAN_H) || defined(_PDCLIB_STDBOOL_H)))  // http://www.cplusplus.com/reference/cstdbool/ & http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdbool.h.html
#define __bool_true_false_are_defined   (1)
#define STDBOOL_H   (1)
#define __STDBOOL_H   (1)
#define __STDBOOL_H_   (1)
#define _BOOL_H   (1)
#define _BOOLEAN_H   (1)
#define _DEF_WINBOOL_   (1)
#define _PDCLIB_STDBOOL_H   (1)


#if IS_BELOW_STDC_1999
typedef int   _Bool;
#endif
#if IS_NOT_CPLUSPLUS
/** Boolean Datatype */
typedef _Bool   bool;
#endif
#if (!(defined(BOOL) || IS_OBJ_C))
/** Support Objective-C-Style "BOOL" datatype */
typedef bool   BOOL;
#   define __objc_no   ((bool)0)
#   define __objc_yes   ((bool)1)
#endif
#ifndef objc_yes
#   define objc_yes   __objc_yes
#endif
#ifndef objc_no
#   define objc_no   __objc_no
#endif
/** Mac OS historic boolean datatype */
typedef unsigned char   Boolean;
typedef int   PRBool;
#ifndef boolean
#   define boolean   bool
#endif
/** Mach-style boolean datatype */
#define boolean_t   bool
#define MACH_MSG_TYPE_BOOLEAN   bool
/** Windows boolean datatype */
typedef int   WINBOOL;
/** Windows boolean pointer datatype */
typedef WINBOOL*   PBOOL;
/** Windows boolean pointer datatype */
typedef WINBOOL*   LPBOOL;
#define PR_TRUE   1
#define PR_FALSE   0
/** Use PRPackedBool within structs where bitfields are not desirable but minimum and consistant overhead matters */
typedef unsigned char   PRPackedBool;
/** Status code used by some routines that have a single point of failure or special status return */
typedef enum PRStatus_enum { PR_FAILURE = -1, PR_SUCCESS = 0 }   PRStatus;
#define no   ((bool)0)
#define NO   no
#define yes   ((bool)1)
#define YES   yes
#ifndef NOT
#   define NOT(_expr)   (!(_expr))
#endif
#ifndef false
#   define false   ((bool)0)
#endif
#define False   false
#ifndef FALSE
#   define FALSE   ((bool)0)
#endif
#ifndef _FALSE
#   define _FALSE   ((bool)0)
#endif
#ifndef true
#   define true   ((bool)1)
#endif
#define True   true
#ifndef TRUE
#   define TRUE   ((bool)1)
#endif
#ifndef _TRUE
#   define _TRUE   ((bool)1)
#endif


#endif  // STDBOOL_H


/* NORETURN (<stdnoreturn.h>) */


#if (!(defined(STDNORETURN_H) || defined(__STDNORETURN_H) || defined(__STDNORETURN_H_) || defined(__noreturn_is_defined) || defined(_PDCLIB_STDNORETURN_H)))
#define STDNORETURN_H   (1)
#define _STDNORETURN_H   (1)
#define __STDNORETURN_H   (1)
#define __STDNORETURN_H_   (1)
#define _PDCLIB_STDNORETURN_H   (1)
#define __noreturn_is_defined   (1)


#if (IS_BELOW_STDC_2011 && defined(__GNUC__))
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body */
#   define noreturn   __attribute__((__noreturn__))
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body */
#   define _Noreturn   __attribute__((__noreturn__))
#elif (defined(MICROSOFT_VISUAL) && defined(_MSC_VER) && (1200 <= _MSC_VER))
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body */
#   define _Noreturn   __declspec(noreturn)
#else
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body */
#   define noreturn   _Noreturn
#endif  // noreturn
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body (Alias for _Noreturn) */
#define Noreturn   _Noreturn
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body (Alias for _Noreturn) */
#define __noreturn   _Noreturn
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body (Alias for _Noreturn) */
#define ecb_noreturn   _Noreturn
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body (Alias for _Noreturn) */
#define __LA_DEAD   _Noreturn
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body (Alias for _Noreturn) */
#define ATTR_NORETURN   _Noreturn
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body (Alias for _Noreturn) */
#define ATF_DEFS_ATTRIBUTE_NORETURN   _Noreturn
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body (Alias for _Noreturn) */
#define ATTRIBUTE_NORETURN   _Noreturn
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body (Alias for _Noreturn) */
#define __dead   _Noreturn
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body (Alias for _Noreturn) */
#define __dead2   _Noreturn
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body (Alias for _Noreturn) */
#define DECLSPEC_NORETURN   _Noreturn
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body (Alias for _Noreturn) */
#define __MINGW_ATTRIB_NORETURN   _Noreturn
/** A function declaration that specifies that the function does not return by executing the return statement or by reaching the end of the function body (Alias for _Noreturn) */
#define CX_GNUC_NORETURN   _Noreturn


#endif  // STDNORETURN_H


/* ALIGNMENT (<stdalign.h>) */


#if (!(defined(__STDALIGN_H) || defined(__STDALIGN_H_) || defined(STDALIGN_H) || defined(_ALIGNOF_H) || defined(_PDCLIB_STDALIGN_H) || defined(_PDCLIB_ALIGN_H)))  // https://www.gnu.org/software/gnulib/manual/html_node/stdalign_002eh.html & https://www.ibm.com/support/knowledgecenter/SSLTBW_2.1.0/com.ibm.zos.v2r1.bpxbd00/stdalign.htm
#define STDALIGN_H   (1)
#define _STDALIGN_H   (1)
#define __STDALIGN_H   (1)
#define __STDALIGN_H_   (1)
#define _ALIGNOF_H   (1)
#define _PDCLIB_ALIGN_H   (1)
#define _PDCLIB_STDALIGN_H   (1)


#ifdef __BIGGEST_ALIGNMENT__
#   define BIGGEST_ALIGNMENT   __BIGGEST_ALIGNMENT__
#elif ((defined(SIZEOF_LONG_DOUBLE) && (SIZEOF_LONG_DOUBLE <= 16)) && (SUPPORTS_LONG_DOUBLE && (BYTES_PER_LONG_DOUBLE <= 16)))
#   define __BIGGEST_ALIGNMENT__   (16)
#   define BIGGEST_ALIGNMENT   __BIGGEST_ALIGNMENT__
#elif ((defined(SIZEOF_LONG_DOUBLE) && (SIZEOF_LONG_DOUBLE <= 32)) && (SUPPORTS_LONG_DOUBLE && (BYTES_PER_LONG_DOUBLE <= 32)))
#   define __BIGGEST_ALIGNMENT__   (32)
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

#define alignto(n, d)   ((((n) + (d) - 1) / (d)) * (d))


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
/** Evaluates to the offset (in bytes as size_t) of a given member within a struct or union */
#define fssh_offsetof(type, member)   offsetof((type), (member))


// CONTAINER_OF

#ifdef __GNUC__
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

#if (IS_STDC_2011 && IS_NOT_CPLUSPLUS && (!AT_LEAST_GCC41))
/** Return the natural alignment (in bytes) for the given type */
#   define __alignof(_type)   _Alignof(_type)
#elif AT_LEAST_GCC41
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
#   if (IS_BELOW_STDC_2011 && defined( __GNUC__))
/** Return the natural alignment (in bytes) for the given type */
#      define _Alignof(_type)    __alignof(_type)
#   endif
#   if (!(defined(alignof) || defined(__alignof_is_defined)))
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
#   if (IS_BELOW_STDC_2011 && defined( __GNUC__))
/** Used in declaration syntax as a type specifier to modify the alignment requirement of the object being declared */
#      define _Alignas(_type)    __attribute__((__aligned__(_type)))
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
#define __alignof_slot_is_defined   (1)


// STRIDEOF

#define strideof(obj)   (sizeof(obj))


// BASEOF

#define BASEOF(ptr, str_type, field)   ((struct str_type*)((char*)ptr - offsetof(str_type, field)))


// UNALIGNED

#define UNALIGNED(x, y)   (((unsigned long)x & (SIZEOF_LONG - 1)) ^ ((unsigned long)y & (SIZEOF_LONG - 1)))


// ALIGNMENT OF VARIOUS DATATYPES AT COMPILE TIME

// ALIGNMENT OF COMMON DATATYPES
#ifndef ALIGN_OF_CHAR
#   define ALIGN_OF_CHAR   1
#endif
#ifndef ALIGNOF_CHAR
#   define ALIGNOF_CHAR   1
#endif
#if (!defined(ALIGNOF_SHORT) && defined(ALIGN_OF_SHORT))
#   define ALIGNOF_SHORT   ALIGN_OF_SHORT
#elif (!(defined(ALIGNOF_SHORT) || defined(ALIGN_OF_SHORT)))
#   define ALIGNOF_SHORT   2
#   define ALIGN_OF_SHORT   2
#endif
#if (!defined(ALIGNOF_INT) && defined(ALIGN_OF_INT))
#   define ALIGNOF_INT   ALIGN_OF_INT
#elif (!(defined(ALIGNOF_INT) || defined(ALIGN_OF_INT)))
#   define ALIGNOF_INT   4
#   define ALIGN_OF_INT   4
#endif
#if (!defined(ALIGNOF_FLOAT) && defined(ALIGN_OF_FLOAT))
#   define ALIGNOF_FLOAT   ALIGN_OF_FLOAT
#elif (!(defined(ALIGNOF_FLOAT) || defined(ALIGN_OF_FLOAT)))
#   define ALIGNOF_FLOAT   4
#   define ALIGN_OF_FLOAT   4
#endif
#if (!defined(ALIGNOF_DOUBLE) && defined(ALIGN_OF_DOUBLE))
#   define ALIGNOF_DOUBLE   ALIGN_OF_DOUBLE
#elif (!(defined(ALIGNOF_DOUBLE) || defined(ALIGN_OF_DOUBLE)))
#   define ALIGNOF_DOUBLE   8
#   define ALIGN_OF_DOUBLE   8
#endif
#if (!defined(ALIGNOF_LONG) && defined(ALIGN_OF_LONG))
#   define ALIGNOF_LONG   ALIGN_OF_LONG
#elif ((!(defined(ALIGNOF_LONG) || defined(ALIGN_OF_LONG))) && (SIZEOF_LONG == 8))
#   define ALIGNOF_LONG   8
#   define ALIGN_OF_LONG   8
#elif ((!(defined(ALIGNOF_LONG) || defined(ALIGN_OF_LONG))) && (SIZEOF_LONG == 4))
#   define ALIGNOF_LONG   4
#   define ALIGN_OF_LONG   4
#endif
#ifndef SALIGN
#   define SALIGN   (SIZEOF_LONG - 1)
#endif
#if (!defined(ALIGNOF_POINTER) && defined(ALIGN_OF_POINTER))
#   define ALIGNOF_POINTER   ALIGN_OF_POINTER
#elif ((!(defined(ALIGNOF_POINTER) || defined(ALIGN_OF_POINTER))) && (SIZEOF_POINTER == 8))
#   define ALIGNOF_POINTER   8
#   define ALIGN_OF_POINTER   8
#elif ((!(defined(ALIGNOF_POINTER) || defined(ALIGN_OF_POINTER))) && (SIZEOF_POINTER == 4))
#   define ALIGNOF_POINTER   4
#   define ALIGN_OF_POINTER   4
#endif
#if (!defined(ALIGNOF_WORD) && defined(ALIGN_OF_WORD))
#   define ALIGNOF_WORD   ALIGN_OF_WORD
#elif ((!(defined(ALIGNOF_WORD) || defined(ALIGN_OF_WORD))) && IS_WORDSIZE_64)
#   define ALIGNOF_WORD   8
#   define ALIGN_OF_WORD   8
#elif ((!(defined(ALIGNOF_WORD) || defined(ALIGN_OF_WORD))) && IS_WORDSIZE_32)
#   define ALIGNOF_WORD   4
#   define ALIGN_OF_WORD   4
#endif
#if (!defined(ALIGNOF_LONG_LONG) && defined(ALIGN_OF_LONG_LONG))
#   define ALIGNOF_LONG_LONG   ALIGN_OF_LONG_LONG
#elif ((!(defined(ALIGNOF_LONG_LONG) || defined(ALIGN_OF_LONG_LONG))) && (defined(DATAMODEL_LP64) || IS_64))
#   define ALIGNOF_LONG_LONG   8
#   define ALIGN_OF_LONG_LONG   8
#elif ((!(defined(ALIGNOF_LONG_LONG) || defined(ALIGN_OF_LONG_LONG))) && IS_32)
#   define ALIGNOF_LONG_LONG   4
#   define ALIGN_OF_LONG_LONG   4
#endif
#if (!defined(ALIGNOF_LONG_DOUBLE) && defined(ALIGN_OF_LONG_DOUBLE))
#   define ALIGNOF_LONG_DOUBLE   ALIGN_OF_LONG_DOUBLE
#elif ((!(defined(ALIGNOF_LONG_DOUBLE) || defined(ALIGN_OF_LONG_DOUBLE))) && IS_64 && (defined(COMPILER_CLANG) || defined(COMPILER_GNUC)))
#   define ALIGNOF_LONG_DOUBLE   16
#   define ALIGN_OF_LONG_DOUBLE   16
#elif ((!(defined(ALIGNOF_LONG_DOUBLE) || defined(ALIGN_OF_LONG_DOUBLE))) && IS_64)
#   define ALIGNOF_LONG_DOUBLE   8
#   define ALIGN_OF_LONG_DOUBLE   8
#elif ((!(defined(ALIGNOF_LONG_DOUBLE) || defined(ALIGN_OF_LONG_DOUBLE))) && IS_32 && (defined(COMPILER_CLANG) || defined(COMPILER_GNUC)))
#   define ALIGNOF_LONG_DOUBLE   4
#   define ALIGN_OF_LONG_DOUBLE   4
#elif ((!(defined(ALIGNOF_LONG_DOUBLE) || defined(ALIGN_OF_LONG_DOUBLE))) && IS_32)
#   define ALIGNOF_LONG_DOUBLE   8
#   define ALIGN_OF_LONG_DOUBLE   8
#endif
#if (!defined(ALIGNOF_INT64) && defined(ALIGN_OF_INT64))
#   define ALIGNOF_INT64   ALIGN_OF_INT64
#elif ((!(defined(ALIGNOF_INT64) || defined(ALIGN_OF_INT64))) && defined(ARCHARM))
#   define ALIGNOF_INT64   4
#   define ALIGN_OF_INT64   4
#elif (!(defined(ALIGNOF_INT64) || defined(ALIGN_OF_INT64)))
#   define ALIGNOF_INT64   8
#   define ALIGN_OF_INT64   8
#endif
// STDFIX DATATYPE ALIGNMENTS
/** Alignment of short Fract */
#define ALIGN_OF_SHORT_FRACT   (1)
/** Alignment of short Fract */
#define ALIGNOF_SHORT_FRACT   (1)
/** Alignment of Fract */
#define ALIGN_OF_FRACT   (2)
/** Alignment of Fract */
#define ALIGNOF_FRACT   (2)
/** Alignment of long Fract */
#define ALIGN_OF_LONG_FRACT   (4)
/** Alignment of long Fract */
#define ALIGNOF_LONG_FRACT   (4)
/** Alignment of long Fract */
#define ALIGN_OF_LONG_LONG_FRACT   (8)
/** Alignment of long Fract */
#define ALIGNOF_LONG_LONG_FRACT   (8)
/** Alignment of short Accum */
#define ALIGN_OF_SHORT_ACCUM   (2)
/** Alignment of short Accum */
#define ALIGNOF_SHORT_ACCUM   (2)
/** Alignment of Accum */
#define ALIGN_OF_ACCUM   (4)
/** Alignment of Accum */
#define ALIGNOF_ACCUM   (4)
/** Alignment of long Accum */
#define ALIGN_OF_LONG_ACCUM   (8)
/** Alignment of long Accum */
#define ALIGNOF_LONG_ACCUM   (8)
// MISCELLANEOUS ALIGNMENTS
#if (ALIGNOF_DOUBLE == 8)
#   define HAVE_ALIGNED_DOUBLES   (1)
#endif
#if (ALIGNOF_INT64 == 8)
#   define HAVE_ALIGNED_LONGLONGS   (1)
#endif
#define sa_alignment_char   ALIGNOF_CHAR
#define sa_alignment_short   ALIGNOF_SHORT
#define sa_alignment_int   ALIGNOF_INT
#define sa_alignment_long   ALIGNOF_LONG
#define sa_alignment_double   ALIGNOF_DOUBLE
#define sa_alignment_longdouble   ALIGNOF_LONG_DOUBLE
#if (defined(HAVE_LONG_LONG_INT) && HAVE_LONG_LONG_INT)
#   define sa_alignment_longlong   ALIGNOF_LONG_LONG
#   define sa_alignment_max   (((sa_alignment_long - 1) | (sa_alignment_double - 1) | (sa_alignment_longlong - 1) | (sa_alignment_longdouble - 1)) + 1)
#else
#   define sa_alignment_max   (((sa_alignment_long - 1) | (sa_alignment_double - 1) | (sa_alignment_longdouble - 1)) + 1)
#endif
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
#define DARWIN_ALIGNBYTES   ALIGNBYTES
#define __DARWIN_ALIGNBYTES   ALIGNBYTES
#ifndef _ALIGN
#   define _ALIGN(p)   (((unsigned long long)(p) + (unsigned long long)(_ALIGNBYTES)) & (unsigned long long)(~(_ALIGNBYTES)))
#endif
#ifndef ALIGN
#   define ALIGN(p)   _ALIGN((p))
#endif
#define DARWIN_ALIGN(p)   ALIGN((p))
#define __DARWIN_ALIGN(p)   ALIGN((p))
#define ALIGNBYTES32   31
#define DARWIN_ALIGNBYTES32   31
#define __DARWIN_ALIGNBYTES32   31
#define ALIGN32(p)   ((size_t)((char*)(size_t)(p) + 31) & 0xffffffe0)
#define DARWIN_ALIGN32(p)   ((size_t)((char*)(size_t)(p) + 31) & 0xffffffe0)
#define __DARWIN_ALIGN32(p)   ((size_t)((char*)(size_t)(p) + 31) & 0xffffffe0)
#define ALIGNBYTES64   63
#define DARWIN_ALIGNBYTES64   63
#define __DARWIN_ALIGNBYTES64   63
#define ALIGN64(p)   ((size_t)((char*)(size_t)(p) + 63) & 0xffffffc0)
#define DARWIN_ALIGN64(p)   ((size_t)((char*)(size_t)(p) + 63) & 0xffffffc0)
#define __DARWIN_ALIGN64(p)   ((size_t)((char*)(size_t)(p) + 63) & 0xffffffc0)


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


#if (!(defined(_ALIGN_64_BIT_H) || defined(_ALIGN_64_BIT_H_)))  // GET 64-BIT STRUCT ALIGNMENT
#define ALIGN_64_BIT_H   (1)
#define _ALIGN_64_BIT_H   (1)
#define _ALIGN_64_BIT_H_   (1)


typedef struct __longlong_aligned { long long x; }   longlong_aligned_t;
/** Simple macro for getting the 64-bit struct arch alignment */
#define __ARCH_64BIT_ALIGNMENT__   __attribute__((__aligned__(__alignof__(struct __longlong_aligned))))
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
#   elif (SUPPORTS_LONG_DOUBLE && (defined(__APPLE__) || defined(__GNUC__)))
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
	long long __clang_max_align_nonce1 __attribute__((__aligned__(__alignof__(long long))));
	long double __clang_max_align_nonce2 __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
#   endif  // max_align_t
#endif  // MAX_ALIGN_T


/** The macro SAFE_CAST_PTR() casts one type of pointer to another type, making sure the data the pointer is referencing is the same size; If it is not, it will cause a division by zero compiler warning */
#define __SAFE_CAST_PTR(type, var)   (((type)(var)) + (0 / (sizeof(*var) == sizeof(*type 0) ? 1 : 0)))
/** The macro SAFE_CAST_PTR() casts one type of pointer to another type, making sure the data the pointer is referencing is the same size; If it is not, it will cause a division by zero compiler warning */
#define SAFE_CAST_PTR(type, var)   __SAFE_CAST_PTR((type), (var))
#define __CAST_PTR(type, var)   ((type)(var))
#define CAST_PTR(type, var)   ((type)(var))


#if (!(defined(STRUCT_H) || defined(_STRUCT_H) || defined(_STRUCT_H_)))
#define STRUCT_H   (1)
#define _STRUCT_H   (1)
#define _STRUCT_H_   (1)


/** Offset of the field in the structure */
#define fldoff(name, field)   ((int)&(((struct name*)0)->field))
/** Size of the field in the structure */
#define fldsiz(name, field)   (sizeof(((struct name*)0)->field))
/** Address of the structure from a field */
#define strbase(name, addr, field)   ((struct name*)((char*)addr - fldoff(name, field)))


#endif  // STRUCT_H


#endif  // STDALIGN_H


/* OBJECT STACK MACROS (<obstack.h>) */


#if (!(defined(OBSTACK_H) || defined(_OBSTACK_H) || defined(_OBSTACK_H_)))  // https://en.wikipedia.org/wiki/Obstack
#define OBSTACK_H   (1)
#define _OBSTACK_H   (1)
#define _OBSTACK_H_   (1)


typedef char*   PTR_CHAR_TYPE;
typedef int*   PTR_INT_TYPE;
typedef long*   PTR_LONG_TYPE;
/** If B is the base of an object addressed by P, return the result of aligning P to the next multiple of A + 1; B and P must be of type char *; A + 1 must be a power of 2 */
#define __BPTR_ALIGN(B, P, A)   ((B) + (((P) - (B) + (A)) & (~(A))))
/** Similar to _BPTR_ALIGN (B, P, A), except optimize the common case where pointers can be converted to integers, aligned as integers, and converted back again; If PTR_INT_TYPE is narrower than a pointer (e.g., the AS/400), play it safe and compute the alignment relative to B; Otherwise, use the faster strategy of computing the alignment relative to 0 */
#define __PTR_ALIGN(B, P, A)   __BPTR_ALIGN(((BYTES_PER_PTR < BYTES_PER_POINTER) ? (B) : (char*)0), P, A)

typedef struct attr_packed _obstack_chunk {
	char* limit;  // 1 past end of this chunk
	struct _obstack_chunk* prev;  // Address of prior chunk or NULL
	char contents[4];  // Objects begin here
} obstack_chunk_t;

#ifdef COMPILER_CLANG
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wpadded"
#elif defined(COMPILER_GNUC)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wpadded"
#endif

/** Control current object in current chunk */
typedef struct obstack {
	long chunk_size;  // Preferred size to allocate chunks
	struct _obstack_chunk* chunk;  // Address of current struct obstack_chunk
	char* object_base;  // Address of object we are building
	char* next_free;  // Where to add next char to current object
	char* chunk_limit;  // Address of char after current chunk
	union {
		PTR_INT_TYPE tempint;
		void* tempptr;
	} temp;  // Temporary for some macros
	int alignment_mask;  // Mask of alignment for each object
	struct _obstack_chunk* (*chunkfun)(void*, long);
	void (*freefun)(void*, struct _obstack_chunk*);
	void* extra_arg;  // First arg for chunk alloc/dealloc funcs
	unsigned use_extra_arg:1;  // Chunk alloc/dealloc funcs take extra arg
	unsigned maybe_empty_object:1;  // There is a possibility that the current chunk contains a zero-length object; This prevents freeing the chunk if we allocate a bigger chunk to replace it
	unsigned alloc_failed:1;  // No longer used, as we now call the failed handler on error, but retained for binary compatibility
} obstack_t;

#ifdef COMPILER_CLANG
#   pragma clang diagnostic pop
#elif defined(COMPILER_GNUC)
#   pragma GCC diagnostic pop
#endif

#ifndef __obstack_free
#   define __obstack_free   obstack_free
#endif

/** Pointer to beginning of object being allocated or to be allocated next; Note that this might not be the final address of the object because a new chunk might be needed to hold the final size */
#define obstack_base(h)   ((void*)(h)->object_base)
/** Size for allocating ordinary chunks */
#define obstack_chunk_size(h)   ((h)->chunk_size)
/** Pointer to next byte not yet allocated in current chunk */
#define obstack_next_free(h)   ((h)->next_free)
/** Mask specifying low bits that should be clear in address of an object */
#define obstack_alignment_mask(h)   ((h)->alignment_mask)
/** To prevent prototype warnings provide complete argument list */
#define obstack_init(h)   _obstack_begin((h), 0, 0, (void*(*)(long))obstack_chunk_alloc, (void (*)(void*))obstack_chunk_free)
#define obstack_begin(h, size)   _obstack_begin ((h), (size), 0, (void*(*)(long))obstack_chunk_alloc, (void (*)(void*))obstack_chunk_free)
#define obstack_specify_allocation(h, size, alignment, chunkfun, freefun)   _obstack_begin ((h), (size), (alignment), (void*(*)(long))(chunkfun), (void (*)(void*))(freefun))
#define obstack_specify_allocation_with_arg(h, size, alignment, chunkfun, freefun, arg)   _obstack_begin_1((h), (size), (alignment), (void*(*)(void*, long))(chunkfun), (void (*)(void*, void*))(freefun), (arg))
#define obstack_chunkfun(h, newchunkfun)   ((h)->chunkfun = (struct _obstack_chunk* (*)(void*, long))(newchunkfun))
#define obstack_freefun(h, newfreefun)   ((h)->freefun = (void(*)(void*, struct _obstack_chunk*))(newfreefun))
#define obstack_1grow_fast(h, achar)   (*((h)->next_free)++ = (achar))
#define obstack_blank_fast(h, n)   ((h)->next_free += (n))
#define obstack_memory_used(h)   _obstack_memory_used((h))

#ifdef COMPILER_GNUC

#   define obstack_object_size(OBSTACK)   do { struct obstack const *__o = (OBSTACK); (unsigned)(__o->next_free - __o->object_base); } while (0x0)
#   define obstack_room(OBSTACK)   do { struct obstack const *__o = (OBSTACK); (unsigned)(__o->chunk_limit - __o->next_free); } while (0x0)
#   define obstack_make_room(OBSTACK, length)   do { struct obstack* __o = (OBSTACK); int __len = (length); if (__o->chunk_limit - __o->next_free < __len) { _obstack_newchunk(__o, __len); } (void)0; } while (0x0)
#   define obstack_empty_p(OBSTACK)   do { struct obstack const *__o = (OBSTACK); (__o->chunk->prev == 0 && __o->next_free == __PTR_ALIGN((char*) __o->chunk, __o->chunk->contents,  __o->alignment_mask)); } while (0x0)
#   define obstack_grow(OBSTACK, where, length)   do { struct obstack* __o = (OBSTACK); int __len = (length); if (__o->next_free + __len > __o->chunk_limit) { _obstack_newchunk(__o, __len); } memcpy_no_output(__o->next_free, where, __len); __o->next_free += __len; (void)0; } while (0x0)
#   define obstack_grow0(OBSTACK, where, length)   do { struct obstack* __o = (OBSTACK); int __len = (length); if (__o->next_free + __len + 1 > __o->chunk_limit) { _obstack_newchunk(__o, __len + 1); } memcpy (__o->next_free, where, __len); __o->next_free += __len; *(__o->next_free)++ = 0; (void)0; } while (0x0)
#   define obstack_1grow(OBSTACK, datum)   do { struct obstack* __o = (OBSTACK); if (__o->next_free + 1 > __o->chunk_limit) { _obstack_newchunk(__o, 1); } obstack_1grow_fast(__o, datum); (void)0; } while (0x0)
#   define obstack_ptr_grow(OBSTACK, datum)   do { struct obstack* __o = (OBSTACK); if (__o->next_free + SIZEOF_VOID_P > __o->chunk_limit) { _obstack_newchunk(__o, SIZEOF_VOID_P); } obstack_ptr_grow_fast(__o, datum); } while (0x0)
#   define obstack_int_grow(OBSTACK, datum)   do { struct obstack* __o = (OBSTACK); if (__o->next_free + BYTES_PER_INT > __o->chunk_limit) { _obstack_newchunk(__o, BYTES_PER_INT); } obstack_int_grow_fast(__o, datum); } while (0x0)
#   define obstack_ptr_grow_fast(OBSTACK, aptr)   do { struct obstack* __o1 = (OBSTACK); void* __p1 = __o1->next_free; *(const void **) __p1 = (aptr); __o1->next_free += SIZEOF_VOID_P; (void)0; } while (0x0)
#   define obstack_int_grow_fast(OBSTACK, aint)   do { struct obstack* __o1 = (OBSTACK); void* __p1 = __o1->next_free; *(int*) __p1 = (aint); __o1->next_free += BYTES_PER_INT; (void)0; } while (0x0)
#   define obstack_blank(OBSTACK, length)   do { struct obstack* __o = (OBSTACK); int __len = (length); if (__o->chunk_limit - __o->next_free < __len) { _obstack_newchunk(__o, __len); } obstack_blank_fast (__o, __len); (void)0; } while (0x0)
#   define obstack_alloc(OBSTACK, length)   do { struct obstack* __h = (OBSTACK); obstack_blank(__h, (length)); obstack_finish (__h); } while (0x0)
#   define obstack_copy(OBSTACK, where, length)   do { struct obstack* __h = (OBSTACK); obstack_grow(__h, (where), (length)); obstack_finish(__h); } while (0x0)
#   define obstack_copy0(OBSTACK, where, length)   do { struct obstack* __h = (OBSTACK); obstack_grow0(__h, (where), (length)); obstack_finish(__h); } while (0x0)
/** The local variable is named __o1 to avoid a name conflict when obstack_blank is called */
#   define obstack_finish(OBSTACK)   do { struct obstack* __o1 = (OBSTACK); void* __value = (void*) __o1->object_base; if (__o1->next_free == __value) { __o1->maybe_empty_object = 1; } __o1->next_free = __PTR_ALIGN(__o1->object_base, __o1->next_free, __o1->alignment_mask); if (__o1->next_free - (char*) __o1->chunk > __o1->chunk_limit - (char*) __o1->chunk) { __o1->next_free = __o1->chunk_limit; } __o1->object_base = __o1->next_free; __value; } while (0x0)
#   define obstack_free(OBSTACK, OBJ)   do { struct obstack* __o = (OBSTACK); void* __obj = (OBJ); if (__obj > (void*) __o->chunk && __obj < (void*) __o->chunk_limit)  __o->next_free = __o->object_base = (char*) __obj; else __obstack_free(__o, __obj); } while (0x0)

#else

#   define obstack_object_size(h)   ((unsigned)((h)->next_free - (h)->object_base))
#   define obstack_room(h)   ((unsigned)((h)->chunk_limit - (h)->next_free))
#   define obstack_empty_p(h)   ((h)->chunk->prev == 0 && (h)->next_free == __PTR_ALIGN((char*)(h)->chunk, (h)->chunk->contents, (h)->alignment_mask))
#   define obstack_make_room(h, length)   ((h)->temp.tempint = (length), (((h)->next_free + (h)->temp.tempint > (h)->chunk_limit) ? (_obstack_newchunk((h), (h)->temp.tempint), 0) : 0))
#   define obstack_grow(h, where, length)   ((h)->temp.tempint = (length), (((h)->next_free + (h)->temp.tempint > (h)->chunk_limit) ? (_obstack_newchunk((h), (h)->temp.tempint), 0) : 0), memcpy ((h)->next_free, where, (h)->temp.tempint), (h)->next_free += (h)->temp.tempint)
#   define obstack_grow0(h, where, length)   ((h)->temp.tempint = (length), (((h)->next_free + (h)->temp.tempint + 1 > (h)->chunk_limit) ? (_obstack_newchunk((h), (h)->temp.tempint + 1), 0) : 0), memcpy ((h)->next_free, where, (h)->temp.tempint), (h)->next_free += (h)->temp.tempint, *((h)->next_free)++ = 0)
#   define obstack_1grow(h, datum)  ((((h)->next_free + 1 > (h)->chunk_limit) ? (_obstack_newchunk((h), 1), 0) : 0), obstack_1grow_fast(h, datum))
#   define obstack_ptr_grow(h, datum)   ((((h)->next_free + SIZEOF_POINTER > (h)->chunk_limit) ? (_obstack_newchunk((h), SIZEOF_POINTER), 0) : 0), obstack_ptr_grow_fast (h, datum))
#   define obstack_int_grow(h, datum)   ((((h)->next_free + BYTES_PER_INT > (h)->chunk_limit) ? (_obstack_newchunk((h), BYTES_PER_INT), 0) : 0), obstack_int_grow_fast (h, datum))
#   define obstack_ptr_grow_fast(h, aptr)   (((const void**)((h)->next_free += SIZEOF_POINTER))[-1] = (aptr))
#   define obstack_int_grow_fast(h, aint)   (((int*)((h)->next_free += BYTES_PER_INT))[-1] = (aint))
#   define obstack_blank(h, length)   ((h)->temp.tempint = (length), (((h)->chunk_limit - (h)->next_free < (h)->temp.tempint) ? (_obstack_newchunk((h), (h)->temp.tempint), 0) : 0), obstack_blank_fast (h, (h)->temp.tempint))
#   define obstack_alloc(h, length)   (obstack_blank((h), (length)), obstack_finish((h)))
#   define obstack_copy(h, where, length)   (obstack_grow((h), (where), (length)), obstack_finish((h)))
#   define obstack_copy0(h, where, length)   (obstack_grow0((h), (where), (length)), obstack_finish((h)))
#   define obstack_finish(h)   (((h)->next_free == (h)->object_base ? (((h)->maybe_empty_object = 1), 0) : 0), (h)->temp.tempptr = (h)->object_base, (h)->next_free = __PTR_ALIGN((h)->object_base, (h)->next_free, (h)->alignment_mask), (((h)->next_free - (char*)(h)->chunk > (h)->chunk_limit - (char*)(h)->chunk) ? ((h)->next_free = (h)->chunk_limit) : 0), (h)->object_base = (h)->next_free, (h)->temp.tempptr)
#   define obstack_free(h, obj)   ((h)->temp.tempint = (char*)(obj) - (char*)(h)->chunk, ((((h)->temp.tempint > 0 && (h)->temp.tempint < (h)->chunk_limit - (char*)(h)->chunk)) ? (void)((h)->next_free = (h)->object_base = (h)->temp.tempint + (char*)(h)->chunk) : __obstack_free(h, (h)->temp.tempint + (char*)(h)->chunk)))

#endif  // GNUC


#endif  // OBSTACK_H


/* STDARG (<stdarg.h>, <varargs.h>, & <vadefs.h>) */


#if (!(defined(STDARG_H) || defined(_STDARG_H) || defined(_STDARG_H_) || defined(_VARARGS_H) || defined(__VARARGS_H) || defined(__clang_vadefs_h) || defined(_VADEFS_H) || defined(_INC_STDARG) || defined(_INC_VADEFS)))  // http://www.cplusplus.com/reference/cstdarg/ & http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdarg.h.html
#define STDARG_H   (1)
#define _STDARG_H   (1)
#define _STDARG_H_   (1)
#define __STDARG_H_   (1)
#define SYS_STDARG_H   (1)
#define _SYS_STDARG_H   (1)
#define _SYS_STDARG_H_   (1)
#define VARARGS_H   (1)
#define _VARARGS_H   (1)
#define _VARARGS_H_   (1)
#define __VARARGS_H   (1)
#define _VADEFS_H   (1)
#define __clang_vadefs_h   (1)
#define _INC_STDARG   (1)
#define _INC_VADEFS   (1)
#define _UCLIBC_VA_COPY_H   (1)


#ifndef MAXARGS
/** Maximum number of function arguments */
#   define  MAXARGS   (31)
#endif
#ifndef MAX_ARGS
/** Maximum number of function arguments */
#   define  MAX_ARGS   MAXARGS
#endif
/** Flag used in struct _args -> flags */
#define A_ALLOCATED   (1)


// VA_LIST

#if (defined(__GNUC__) && (!defined(__GNUC_VA_LIST)))
/** Type to hold information about variable arguments */
typedef __builtin_va_list   __gnuc_va_list;
#elif defined(__VMS__)
/** Type to hold information about variable arguments */
typedef char*   __gnuc_va_list;
#else
typedef struct va_list_struct {
	char* __base;  // Pointer to first integer register
	int __offset;  // Byte offset of args so far
} __gnuc_va_list;
#endif
#define __GNUC_VA_LIST   1
/** Type to hold information about variable arguments */
#define p9va_list   __gnuc_va_list
/** Type to hold information about variable arguments */
#define va_list   __gnuc_va_list
/** Type to hold information about variable arguments */
#define _G_va_list   __gnuc_va_list
/** Type to hold information about variable arguments */
#define _IO_va_list   __gnuc_va_list
/** Type to hold information about variable arguments */
#define gnuc_va_list   __gnuc_va_list
/** Type to hold information about variable arguments */
#define __VALIST   __gnuc_va_list
/** Type to hold information about variable arguments */
#define __va_list   va_list
/** Type to hold information about variable arguments */
#define isoc_va_list   __gnuc_va_list
/** Type to hold information about variable arguments */
#define __isoc_va_list   __gnuc_va_list
/** Type to hold information about variable arguments */
#define __darwin_va_list   __gnuc_va_list
/** Type to hold information about variable arguments */
#define darwin_va_list   __gnuc_va_list
/** Type to hold information about variable arguments */
#define __va_ptr_t   __gnuc_va_list
#undef __need___va_list
#define __DEFINED___isoc_va_list   (1)
#define __DEFINED_va_list   (1)
#define VEC(...)   ((const unsigned char[]) { __VA_ARGS__ })
/** Show list of items in __VA_ARGS__ */
#define showlist(...)   puts(#__VA_ARGS__)


// VA_START, VA_END, & VA_ARG

/** Retrieve next argument */
#define va_arg   __builtin_va_arg
#if AT_LEAST_GCC44
#   define __builtin_stdarg_start(v, argnum)   __builtin_va_start((v), (argnum))
#elif defined(__GNUC__)
#   define __builtin_va_start(v, argnum)   __builtin_stdarg_start((v), (argnum))
#endif
/** Initialize a variable argument list */
#define va_start(v, argnum)   __builtin_va_start((v), (argnum))
/** Initialize a variable argument list */
#define _va_start(v, argnum)   va_start((v), (argnum))
/** Initialize a variable argument list */
#define __va_start(v, argnum)   va_start((v), (argnum))
/** Performs the appropriate actions to facilitate a normal return by a function that has used the va_list object to retrieve its additional arguments */
#define va_end(v)   __builtin_va_end((v))
/** Performs the appropriate actions to facilitate a normal return by a function that has used the va_list object to retrieve its additional arguments */
#define _va_end(v)   va_end((v))
/** Performs the appropriate actions to facilitate a normal return by a function that has used the va_list object to retrieve its additional arguments */
#define __va_end(v)   va_end((v))


// VA_ARG_PACK

/** Represents all anonymous arguments of an inline function */
#define va_arg_pack()   __builtin_va_arg_pack()
/** Represents all anonymous arguments of an inline function */
#define _va_arg_pack()   va_arg_pack()
/** Represents all anonymous arguments of an inline function */
#define __va_arg_pack()   va_arg_pack()
/** Returns the number of anonymous arguments of an inline function */
#define va_arg_pack_len()   __builtin_va_arg_pack_len()
/** Returns the number of anonymous arguments of an inline function */
#define _va_arg_pack_len()   va_arg_pack_len()
/** Returns the number of anonymous arguments of an inline function */
#define __va_arg_pack_len()   va_arg_pack_len()


// VA_COPY

// GCC only defines `va_copy` c99 mode, or if `-ansi` is not specified; va_copy is not in C90
#if (IS_STDC_1999 || (!defined(__STRICT_ANSI__)))
/** Copy variable argument list */
#   define va_copy(dest, src)   (*(dest) = *(src))  // __builtin_va_copy((dest), (src))
/** Copy variable argument list */
#   define _va_copy(dest, src)   va_copy((dest), (src))
/** Copy variable argument list */
#   define __va_copy(dest, src)   va_copy((dest), (src))
/** Copy variable argument list */
#   define gl_va_copy(dest, src)   va_copy((dest), (src))
/** Copy variable argument list (MSVC) */
#   define crt_va_copy(dest, src)   va_copy((dest), (src))
/** Copy variable argument list (MSVC) */
#   define _crt_va_copy(dest, src)   va_copy((dest), (src))
/** Copy variable argument list (VS 2015 double underscore name) */
#   define __crt_va_copy(dest, src)   va_copy((dest), (src))
#endif


// MSVC COMPATIBILITY

#define _crt_va_start(v, argnum)   va_start((v), (argnum))
#define _crt_va_end(v)   va_end((v))
#define _crt_va_arg(ap, type)   __builtin_va_arg((ap), (type))
/** Represents all anonymous arguments of an inline function */
#define _crt_va_arg_pack()   va_arg_pack()
/** Returns the number of anonymous arguments of an inline function */
#define _crt_va_arg_pack_len()   va_arg_pack_len()
// VS 2015 double underscore names
#define __crt_va_start(v, argnum)   va_start((v), (argnum))
#define __crt_va_end(v)   va_end((v))
#define __crt_va_arg(ap, type)   __builtin_va_arg((ap), (type))
/** Represents all anonymous arguments of an inline function */
#define __crt_va_arg_pack()   va_arg_pack()
/** Returns the number of anonymous arguments of an inline function */
#define __crt_va_arg_pack_len()   va_arg_pack_len()
#define crt_va_start(v, argnum)   va_start((v), (argnum))
#define crt_va_end(v)   va_end((v))
#define crt_va_arg(ap, type)   __builtin_va_arg((ap), (type))
/** Represents all anonymous arguments of an inline function */
#define crt_va_arg_pack()   va_arg_pack()
/** Returns the number of anonymous arguments of an inline function */
#define crt_va_arg_pack_len()   va_arg_pack_len()
#ifndef __ms_va_list
#   if (defined(X86_64) && defined(__GNUC__))
#      define __ms_va_list   __builtin_ms_va_list
#      define __ms_va_start(list, arg)   __builtin_ms_va_start((list), (arg))
#      define __ms_va_end(list)   __builtin_ms_va_end((list))
#   else
#      define __ms_va_list   va_list
#      define __ms_va_start(list, arg)   va_start((list), (arg))
#      define __ms_va_end(list)   va_end((list))
#   endif
#endif


// APPLY_ARGS & GET_ARG_POINTER

#ifdef __GNUC__
/** Returns a pointer to data describing how to perform a call with the same arguments as are passed to the current function */
#   define apply_args()   ((void*)__builtin_apply_args())
/** Returns a pointer to data describing how to perform a call with the same arguments as are passed to the current function */
#   define get_arg_pointer()   ((void*)__builtin_apply_args())
#endif


extern UNUSED char* argv0;


#define ARGBEGIN   for ((void)(argv0 || (argv0 = *argv)), argv++, argc--; argv[0] && argv[0][0] == '-' && argv[0][1]; argc--, argv++) { char* _args, *_argt; Rune _argc; _args = &argv[0][1]; if (_args[0] == '-' && _args[1] == 0) { argc--; argv++; break; } _argc = 0; while (*_args && (_args += chartorune(&_argc, _args))) { switch (_argc) }
#define ARGEND   _argt = 0; }
#define ARGF()   (_argt = _args, _args = "", (*_argt ? _argt : argv[1] ? (argc--, *++argv): 0))
#define EARGF(x)   (_argt = _args, _args = "", (*_argt ? _argt : argv[1] ? (argc--, *++argv) : ((x), abort(), (char*)0)))


#endif  // STDARG_H


/* KERNEL DATATYPES */


#if (!(defined(BITS_KERNEL_TYPES_H) || defined(_BITS_KERNEL_TYPES_H) || defined(_BITS_KERNEL_TYPES_H_)))
#define BITS_KERNEL_TYPES_H   (1)
#define _BITS_KERNEL_TYPES_H   (1)
#define _BITS_KERNEL_TYPES_H_   (1)


#if (defined(ALPHA) && (!(defined(ALPHA_POSIX_TYPES_H) || defined(_ALPHA_POSIX_TYPES_H) || defined(_ALPHA_POSIX_TYPES_H_))))   // ARCH
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


#elif (defined(ARM) && (!(defined(_ARCH_ARM_POSIX_TYPES_H) || defined(_ARCH_ARM_POSIX_TYPES_H_) || defined(__ARCH_ARM_POSIX_TYPES_H))))
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


#elif (defined(BLACKFIN) && (!(defined(__ARCH_BFIN_POSIX_TYPES_H) || defined(_ARCH_BFIN_POSIX_TYPES_H) || defined(_ARCH_BFIN_POSIX_TYPES_H_))))
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


#elif (defined(PARISC) && (!(defined(_ARCH_PARISC_POSIX_TYPES_H) || defined(_ARCH_PARISC_POSIX_TYPES_H_) || defined(__ARCH_PARISC_POSIX_TYPES_H))))
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


#elif ((defined(POWERPC) || defined(POWERPC64)) && (!(defined(_PPC_POSIX_TYPES_H) || defined(_PPC64_POSIX_TYPES_H) || defined(_ASM_POWERPC_POSIX_TYPES_H) || defined(__ASM_POWERPC_POSIX_TYPES_H))))
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


#elif (defined(ITANIUM) && (!(defined(_ASM_IA64_POSIX_TYPES_H) || defined(_ASM_IA64_POSIX_TYPES_H_))))
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


#elif (defined(M68K) && (!(defined(_ARCH_M68K_POSIX_TYPES_H) || defined(_ARCH_M68K_POSIX_TYPES_H_) || defined(__ARCH_M68K_POSIX_TYPES_H))))
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


#elif (defined(MICROBLAZE) && (!(defined(_ASM_MICROBLAZE_POSIX_TYPES_H) || defined(_ASM_MICROBLAZE_POSIX_TYPES_H) || defined(__ASM_MICROBLAZE_POSIX_TYPES_H))))
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


#elif (defined(SPARC) && (!(defined(__ARCH_SPARC_POSIX_TYPES_H) || defined(__ARCH_SPARC64_POSIX_TYPES_H) || defined(__SPARC_POSIX_TYPES_H))))
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


#elif (defined(SUPERH64) && (!(defined(_ASM_SH64_POSIX_TYPES_H) || defined(_ASM_SH64_POSIX_TYPES_H_) || defined(__ASM_SH64_POSIX_TYPES_H))))
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


#elif (defined(SUPERH) && (!(defined(__ASM_SH_POSIX_TYPES_H) || defined(__ASM_SH_POSIX_TYPES_32_H))))
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


#elif (defined(XTENSA) && (!(defined(_XTENSA_POSIX_TYPES_H) || defined(_XTENSA_POSIX_TYPES_H_) || defined(__XTENSA_POSIX_TYPES_H))))
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


#endif  // ARCH


#endif  // BITS_KERNEL_TYPES_H


/* DATATYPES (<sys/types.h>, <stdint.h>, <stddef.h>, & MORE) */


#if (!(defined(_BITS_TYPES_H) || defined(_BITS_TYPESIZES_H) || defined(_SYS_TYPES_H) || defined(_SYS_TYPES_H_) || defined(_SYS__TYPES_H_) || defined(ST_TYPEDEFS_H) || defined(_STDINT_H) || defined(_STDINT_H_) || defined(__CLANG_STDINT_H) || defined(_STDDEF_H) || defined(_STDDEF_H_) || defined(_INTTYPES_H) || defined(_INTTYPES_H_)))  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_types.h.html
#define _STDDEF_H   (1)  // http://www.cplusplus.com/reference/cstddef/ & pubs.opengroup.org/onlinepubs/9699919799/basedefs/stddef.h.html
#define _STDDEF_H_   (1)  // <stddef.h>
#define _RUNETYPE_H_   (1)  // <runetype.h>
#define _RUNETYPE_LOCAL_H_   (1)  // <runetype.h>
#define _RUNETYPE_FILE_H_   (1)  // <runetype.h>
#define _NB_RUNETYPE_H_   (1)  // <runetype.h>
#define _INTTYPES_H   (1)  // http://www.cplusplus.com/reference/cinttypes/ & http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/inttypes.h.html
#define _INTTYPES_H_   (1)  // <inttypes.h>
#define INTTYPES_H   (1)
#define __CLANG_INTTYPES_H   (1)
#define _LIBC_INTTYPES_H_   (1)
#define _QNX4TYPES_H   (1)  // <qnxtypes.h>
#define _QNX4TYPES_H_   (1)
#define QNX4TYPES_H   (1)
#define _QNX4_TYPES_H_   (1)
#define _STDINT_H   (1)  // http://www.cplusplus.com/reference/cstdint/ & http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdint.h.html
#define _STDINT_H_   (1)  // <stdint.h>
#define STDINT_H   (1)
#define __CLANG_STDINT_H   (1)
#define _BITS_TYPES_H   (1)  // <bits/types.h>
#define __BIT_TYPES_DEFINED__   (1)
#define _BITS_TYPESIZES_H   (1)  // <bits/typesizes.h>
#define _SYS_TYPES_H   (1)  // <sys/types.h>
#define _SYS_TYPES_H_   (1)
#define _SYS__TYPES_H_   (1)
#define _LIBCPP_INTTYPES_H   (1)
#define _TYPE_H   (1)
#define __TYPE_H   (1)
#define ST_TYPEDEFS_H   (1)
#define _ST_TYPEDEFS_H   (1)
#define _FSSH_TYPES_H   (1)
#define BASETYPES   (1)
#define _BASETYPES   (1)
#define _BITS_XTITYPES_H   (1)  // <bits/xtitypes.h>
#define _XTITYPES_H   (1)  // <xtitypes.h>
#define _ASM_TYPES_H   (1)
#define _ASM_TYPES_H_   (1)
#define _ASM_X86_TYPES_H   (1)
#define _ARM_TYPES_H_   (1)
#define _ASM_SN_TYPES_H   (1)
#define __ASM_ARM_TYPES_H   (1)
#define _ARM_INT_TYPES_H_   (1)
#define _ARM_ARM32_TYPES_H_   (1)
#define _ARM_ARM26_TYPES_H_   (1)
#define _ARM_INT_CONST_H_   (1)
#define _LINUX_TYPES_H   (1)
#define _LINUX_TYPES_H_   (1)
#define LINUX_POSIX_TYPES_H   (1)
#define LINUX_POSIX_TYPES_H_   (1)
#define _LINUX_POSIX_TYPES_H   (1)
#define _LINUX_POSIX_TYPES_H_   (1)
#define _LINUX_VIRTIO_TYPES_H   (1)  // Type definitions for virtio implementations (<virtio_types.h>)
#define _LINUX_VIRTIO_TYPES_H_   (1)
#define RPC_TYPES_H   (1)
#define _RPC_TYPES_H   (1)
#define _RPC_TYPES_H_   (1)
#define __MACTYPES__   (1)
#define _OS_OSTYPES_H   (1)
#define _OS_OSTYPES_H_   (1)
#define _MACH_STD_TYPES_H_   (1)
#define _MACH_STD_TYPES_DEFS_   (1)
#define _MACH_MACH_TYPES_H   (1)
#define _MACH_MACH_TYPES_H_   (1)
#define _MACH_MACHINE_TYPES_H   (1)
#define _MACH_MACHINE_TYPES_H_   (1)
#define _MACH_VM_TYPES_H_   (1)
#define _MACH_VOUCHER_TYPES_H_   (1)
#define _MACH_PORT_T   (1)
#define _MACH_CLOCK_TYPES_H   (1)
#define _MACH_CLOCK_TYPES_H_   (1)
#define _MACH_PPC_VM_TYPES_H_   (1)
#define _DEVICE_DEVICE_TYPES_DEFS_   (1)
#define __USERNOTIFICATION_UNDTYPES_H   (1)
#define _MACH_TYPES_H_   (1)
#define _MACHTYPES_H_   (1)
#define _I386_MACHTYPES_H_   (1)
#define _I386_INT_CONST_H_   (1)
#define _BSD_MACHINE_TYPES_H_   (1)
#define _BSD_MACHINE__TYPES_H_   (1)
#define _BSD_I386__TYPES_H_   (1)
#define _MACHINE_ARCH_TYPES_H_   (1)
#define ABSOLUTETIME_SCALAR_TYPE   (1)
#define OSTYPES_K64_REV   (2)
#define _MACH_PROF_TYPES_H   (1)
#define _MACH_MACHINE_MACHNINE_TYPES_DEFS  (1)
#define _BITSIZE_STDINTCONST_H   (1)
#define _NETINET_IN_SYSTM_H   (1)  // <netinet/in_systm.h>
#define _NETINET_IN_SYSTM_H_   (1)
#define __CMPH_TYPES_H__   (1)
#define _CMPH_TYPES_H   (1)
#define _CMPH_TYPES_H_   (1)
#define _LIMITS_H   (1)  // http://www.cplusplus.com/reference/climits/ & http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/limits.h.html
#define _LIMITS_H_   (1)  // <limits.h>
#define LIMITS_H   (1)
#define LIBC_LIMITS_H   (1)
#define _LIBC_LIMITS_H   (1)
#define _LIBC_LIMITS_H_   (1)
#define __CLANG_LIMITS_H   (1)
#define _GCC_LIMITS_H_   (1)
#define _GCC_NEXT_LIMITS_H   (1)
#define _LINUX_LIMITS_H   (1)
#define _LINUX_LIMITS_H_   (1)
#define _BITS_POSIX1_LIM_H   (1)
#define _BITS_POSIX1_LIM_H_   (1)
#define _BITS_POSIX2_LIM_H   (1)
#define _BITS_POSIX2_LIM_H_   (1)
#define _XOPEN_LIM_H   (1)
#define _XOPEN_LIM_H_   (1)
#define __WINE_LIMITS_H   (1)
#define _SYS_SYSCONF_H_   (1)
#define _MACHINE_LIMITS_H_   (1)
#define _PAX_LIMITS_H   (1)
#define __LIMITS   (1)
#define POSIX_EXTRAS_H   (1)
#define POSIX_EXTRAS_H_   (1)
#define _POSIX_EXTRAS_H   (1)
#define _POSIX_EXTRAS_H_   (1)
#define _SYS_PARAM_H   (1)
#define _SYS_PARAM_H_   (1)
#define _BSD_SYS_PARAM_H_   (1)
#define _BITSIZE_STDINTLIMITS_H   (1)
#define __BIT_TYPES_DEFINED__   (1)
#define _SYS_SYSLIMITS_H   (1)
#define _SYS_SYSLIMITS_H_   (1)
#define GNULIB_SIZE_MAX_H   (1)
#define _SYS_VLIMIT_H_   (1)
#define CGEN_BASIC_MODES_H   (1)
#define _SYS_COMMON_INT_CONST_H_   (1)
#define _COMPAT_FSTYPES_H_   (1)
#define _I386_INT_MWGWTYPES_H_   (1)
#define _ARM_INT_MWGWTYPES_H_   (1)
#define _SYS_COMMON_INT_MWGWTYPES_H_   (1)
#define _USTAT_H   (1)
#define LINUX_TYPES_WRAPPER_H   (1)
#define LINUX_TYPES_WRAPPER_H_   (1)
#define _DDEKIT_TYPES_H   (1)
#define _SYS_COMMON_INT_TYPES_H_   (1)
#define __HFS_MACOS_TYPES__   (1)
#define _KXLD_TYPES_H   (1)
#define DEVICE_TYPES_H   (1)
#define _BITS_PTHREADTYPES_H   (1)  // <bits/pthreadtypes.h>
#define _BITS_PTHREADTYPES_H_   (1)
#define _CONFIG_TYPES_H   (1)
#define _TYPE_CONSTANTS_H   (1)


// VOID DATATYPES

#ifndef Void_t
/** Void Datatype */
#   define Void_t   void
#endif
#ifndef void_t
/** Void Datatype */
#   define void_t   void
#endif
#ifndef VOID
/** Void Datatype */
#   define VOID   void
#endif
/** Void Pointer Datatype */
typedef void*   void_ptr_t;
/** Void Pointer Volatile Datatype */
typedef volatile void_ptr_t   vvoid_ptr_t;
/** Void Pointer Datatype */
typedef void*   ptr_t;
#ifndef __ptr_t
/** Void Pointer Datatype */
#   define __ptr_t   ptr_t
#endif


// EXACT-WIDTH FRACTIONAL DATATYPES

#if SUPPORTS_STDFIX
#   if (SIZEOF_SHORT_FRACT == 1)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef short _Fract   fract_8_t;
#   endif
#   if (SIZEOF_FRACT == 2)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef _Fract   fract_16_t;
#   endif
#   if (SIZEOF_LONG_FRACT == 4)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef long _Fract   fract_32_t;
#   endif
#   if (SIZEOF_LONG_LONG_FRACT == 8)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef long long _Fract   fract_64_t;
#   endif
#   if (SIZEOF_SHORT_FRACT == 1)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef unsigned short _Fract   ufract_8_t;
#   endif
#   if (SIZEOF_FRACT == 2)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef unsigned _Fract   ufract_16_t;
#   endif
#   if (SIZEOF_LONG_FRACT == 4)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef unsigned long _Fract   ufract_32_t;
#   endif
#   if (SIZEOF_LONG_LONG_FRACT == 8)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef unsigned long long _Fract   ufract_64_t;
#   endif
#   if (SIZEOF_SHORT_FRACT == 1)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef _Sat short _Fract   sat_fract_8_t;
#   endif
#   if (SIZEOF_FRACT == 2)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef _Sat _Fract   sat_fract_16_t;
#   endif
#   if (SIZEOF_LONG_FRACT == 4)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef _Sat long _Fract   sat_fract_32_t;
#   endif
#   if (SIZEOF_LONG_LONG_FRACT == 8)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef _Sat long long _Fract   sat_fract_64_t;
#   endif
#   if (SIZEOF_SHORT_FRACT == 1)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef unsigned _Sat short _Fract   sat_ufract_8_t;
#   endif
#   if (SIZEOF_FRACT == 2)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef unsigned _Sat _Fract   sat_ufract_16_t;
#   endif
#   if (SIZEOF_LONG_FRACT == 4)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef unsigned _Sat long _Fract   sat_ufract_32_t;
#   endif
#   if (SIZEOF_LONG_LONG_FRACT == 8)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef unsigned _Sat long long _Fract   sat_ufract_64_t;
#   endif
#   if (SIZEOF_SHORT_FRACT == 1)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef short _Fract   fract_0_7_t;
#   endif
#   if (SIZEOF_FRACT == 2)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef _Fract   fract_0_15_t;
#   endif
#   if (SIZEOF_LONG_FRACT == 4)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef long _Fract   fract_0_23_t;
#   endif
#   if (SIZEOF_SHORT_FRACT == 1)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef unsigned short _Fract   ufract_0_7_t;
#   endif
#   if (SIZEOF_FRACT == 2)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef unsigned _Fract   ufract_0_15_t;
#   endif
#   if (SIZEOF_LONG_FRACT == 4)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1 */
typedef unsigned long _Fract   ufract_0_23_t;
#   endif
#   if (SIZEOF_SHORT_FRACT == 1)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef _Sat short _Fract   sat_fract_0_7_t;
#   endif
#   if (SIZEOF_FRACT == 2)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef _Sat _Fract   sat_fract_0_15_t;
#   endif
#   if (SIZEOF_LONG_FRACT == 4)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef _Sat long _Fract   sat_fract_0_23_t;
#   endif
#   if (SIZEOF_SHORT_FRACT == 1)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef _Sat unsigned short _Fract   sat_ufract_0_7_t;
#   endif
#   if (SIZEOF_FRACT == 2)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef _Sat unsigned _Fract   sat_ufract_0_15_t;
#   endif
#   if (SIZEOF_LONG_FRACT == 4)
/** Fixed-point datatype with no integral bits; values of unsigned fract datatypes are in
the range of 0 to 1, and values of signed fract datatypes are in the range of -1 to 1; This datatype supports saturation */
typedef _Sat unsigned long _Fract   sat_ufract_0_23_t;
#   endif
#endif


// EXACT-WIDTH ACCUM DATATYPES

#if SUPPORTS_STDFIX
#   if (SIZEOF_SHORT_ACCUM == 2)
typedef short _Accum   accum_16_t;
#   endif
#   if (SIZEOF_ACCUM == 4)
typedef _Accum   accum_32_t;
#   endif
#   if (SIZEOF_LONG_ACCUM == 8)
typedef long _Accum   accum_64_t;
#   endif
#   if (SIZEOF_SHORT_ACCUM == 2)
typedef unsigned short _Accum   uaccum_16_t;
#   endif
#   if (SIZEOF_ACCUM == 4)
typedef unsigned _Accum   uaccum_32_t;
#   endif
#   if (SIZEOF_LONG_ACCUM == 8)
typedef unsigned long _Accum   uaccum_64_t;
#   endif
#   if (SIZEOF_SHORT_ACCUM == 2)
typedef _Sat short _Accum   saccum_16_t;
#   endif
#   if (SIZEOF_ACCUM == 4)
typedef _Sat _Accum   saccum_32_t;
#   endif
#   if (SIZEOF_LONG_ACCUM == 8)
typedef _Sat long _Accum   saccum_64_t;
#   endif
#   if (SIZEOF_SHORT_ACCUM == 2)
typedef _Sat unsigned short _Accum   suaccum_16_t;
#   endif
#   if (SIZEOF_ACCUM == 4)
typedef _Sat unsigned _Accum   suaccum_32_t;
#   endif
#   if (SIZEOF_LONG_ACCUM == 8)
typedef _Sat unsigned long _Accum   suaccum_64_t;
#   endif
#   if (SIZEOF_SHORT_ACCUM == 2)
typedef short _Accum   accum_4_7_t;
#   endif
#   if (SIZEOF_ACCUM == 4)
typedef _Accum   accum_4_15_t;
#   endif
#   if (SIZEOF_LONG_ACCUM == 8)
typedef long _Accum   accum_4_23_t;
#   endif
#   if (SIZEOF_SHORT_ACCUM == 2)
typedef unsigned short _Accum   uaccum_4_7_t;
#   endif
#   if (SIZEOF_ACCUM == 4)
typedef unsigned _Accum   uaccum_4_15_t;
#   endif
#   if (SIZEOF_LONG_ACCUM == 8)
typedef unsigned long _Accum   uaccum_4_23_t;
#   endif
#   if (SIZEOF_SHORT_ACCUM == 2)
typedef _Sat short _Accum   saccum_4_7_t;
#   endif
#   if (SIZEOF_ACCUM == 4)
typedef _Sat _Accum   saccum_4_15_t;
#   endif
#   if (SIZEOF_LONG_ACCUM == 8)
typedef _Sat long _Accum   saccum_4_23_t;
#   endif
#   if (SIZEOF_SHORT_ACCUM == 2)
typedef _Sat unsigned short _Accum   suaccum_4_7_t;
#   endif
#   if (SIZEOF_ACCUM == 4)
typedef _Sat unsigned _Accum   suaccum_4_15_t;
#   endif
#   if (SIZEOF_LONG_ACCUM == 8)
typedef _Sat unsigned long _Accum   suaccum_4_23_t;
#   endif
#endif


// EXACT-WIDTH SIGNED INTEGRAL DATATYPES

#ifndef __int8_t_defined
#   define __int8_t_defined   (1)
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
#define _PDCLIB_int8_t   int8_t
#ifndef __int16_t_defined
#   define __int16_t_defined   (1)
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
#define INT16   int16_t
#define i16_t   int16_t
#define _PDCLIB_int16_t   int16_t
#ifndef __int32_t_defined
#   define __int32_t_defined   (1)
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
#define INT32   int32_t
#define i32_t   int32_t
#define _PDCLIB_int32_t   int32_t
#ifndef __int64_t_defined
#   define __int64_t_defined   (1)
#   if IS_WORDSIZE_64
typedef signed long   int64_t;
#   elif IS_WORDSIZE_32
typedef signed long long   int64_t;
#   else
#      error   "WORDSIZE is not `64` or `32`"
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
#define  __s64   int64_t
#define INT64   int64_t
#define i64_t   int64_t
#define _PDCLIB_int64_t   int64_t


// EXACT-WIDTH UNSIGNED INTEGRAL DATATYPES

#ifndef __uint8_t_defined
#   define __uint8_t_defined   (1)
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
#define _PDCLIB_uint8_t   uint8_t
#ifndef __uint16_t_defined
#   define __uint16_t_defined   (1)
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
#define UINT16   uint16_t
#define u16_t   uint16_t
#define _PDCLIB_uint16_t   uint16_t
#define __le16   uint16_t
#define __be16   uint16_t
#define __sum16   uint16_t
#ifndef __uint32_t_defined
#   define __uint32_t_defined   (1)
typedef unsigned int   uint32_t;
#endif
#define _PDCLIB_uint16_t   uint16_t
typedef uint32_t   natural_t;
#define darwin_natural_t   natural_t
#define __darwin_natural_t   natural_t
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
#define UINT32   uint32_t
#define u32_t   uint32_t
#define _PDCLIB_uint32_t   uint32_t
#define __le32   uint32_t
#define __be32   uint32_t
#define __wsum   uint32_t
#ifndef __uint64_t_defined
#   define __uint64_t_defined   (1)
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
#define _PDCLIB_uint64_t   uint64_t
#define __le64   uint64_t
#define __be64   uint64_t
typedef uint64_t align8   __aligned_u64;
#define __aligned_be64   __aligned_u64
#define __aligned_le64   __aligned_u64
#define aligned_u64   __aligned_u64
#define aligned_be64   __aligned_u64
#define aligned_le64   __aligned_u64


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


// UNSIGNED INTEGER U-DATATYPES

typedef uint8_t   U_8;
typedef uint16_t   U_16;
typedef uint32_t   U_32;
typedef uint64_t   U_64;


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
#ifndef __COMPILER_INT64__
#   define __COMPILER_INT64__   int_least64_t
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
#ifndef __COMPILER_UINT64__
#   define __COMPILER_UINT64__   uint_least64_t
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


// UNCOMMON FIXED-WIDTH INTEGRAL DATATYPES

#ifdef __INT24_TYPE__
typedef __INT24_TYPE__   int24_t;
typedef __UINT24_TYPE__   uint24_t;
typedef int32_t   int_least24_t;
typedef uint32_t   uint_least24_t;
typedef int32_t   int_fast24_t;
typedef uint32_t   uint_fast24_t;
#   define u_int24_t   uint24_t
#   define uint24   uint24_t
#   define __int_least16_t   int32_t
#   define __uint_least16_t   uint32_t
#   define __int_least8_t   int32_t
#   define __uint_least8_t   uint32_t
#endif  // __INT24_TYPE__
#ifdef __INT40_TYPE__
typedef __INT40_TYPE__   int40_t;
typedef __UINT40_TYPE__   uint40_t;
typedef int40_t   int_least40_t;
typedef uint40_t   uint_least40_t;
typedef int40_t   int_fast40_t;
typedef uint40_t   uint_fast40_t;
#   define u_int40_t   uint40_t
#   define uint40   uint40_t
#   define __int_least32_t   int40_t
#   define __uint_least32_t   uint40_t
#   define __int_least16_t   int40_t
#   define __uint_least16_t   uint40_t
#   define __int_least8_t   int40_t
#   define __uint_least8_t   uint40_t
#endif  // __INT40_TYPE__
#ifdef __INT48_TYPE__
/** 48-bit (6 octet) integer datatype; https://en.wikipedia.org/wiki/48-bit */
typedef __INT48_TYPE__   int48_t;
/** 48-bit (6 octet) unsigned integer datatype; https://en.wikipedia.org/wiki/48-bit */
typedef __UINT48_TYPE__   uint48_t;
/** Integer type with a minimum of 48 bits */
typedef int48_t   int_least48_t;
/** Unsigned integer type with a minimum of 48 bits */
typedef uint48_t   uint_least48_t;
/** Fastest signed integer with a width of at least 48 bits */
typedef int48_t   int_fast48_t;
/** Fastest unsigned integer with a width of at least 48 bits */
typedef uint48_t   uint_fast48_t;
#   define u_int48_t   uint48_t
#   define uint48   uint48_t
#   define __int_least32_t   int48_t
#   define __uint_least32_t   uint48_t
#   define __int_least16_t   int48_t
#   define __uint_least16_t   uint48_t
#   define __int_least8_t   int48_t
#   define __uint_least8_t   uint48_t
#endif  // __INT48_TYPE__
#ifdef __INT56_TYPE__
typedef __INT56_TYPE__   int56_t;
typedef __UINT56_TYPE__   uint56_t;
typedef int56_t   int_least56_t;
typedef uint56_t   uint_least56_t;
typedef int56_t   int_fast56_t;
typedef uint56_t   uint_fast56_t;
#   define u_int56_t   uint56_t
#   define uint56   uint56_t
#   define __int_least32_t   int56_t
#   define __uint_least32_t   uint56_t
#   define __int_least16_t   int56_t
#   define __uint_least16_t   uint56_t
#   define __int_least8_t   int56_t
#   define __uint_least8_t   uint56_t
#endif  // __INT56_TYPE__
/** Datatype union for converting between 11-bit and 16-bit integers */
typedef union attr_packed uint11 { unsigned short val11:11; unsigned short val16; }   uint11_t;
/** Datatype union for converting between 15-bit and 16-bit integers */
typedef union attr_packed uint15 { unsigned short val15:15; unsigned short val16; }   uint15_t;


// 128-BIT INTEGERS

#if SUPPORTS_INT128
#   ifndef __int128_t_defined
#      define __int128_t_defined   (1)
#   endif
#   ifndef __uint128_t_defined
#      define __uint128_t_defined   (1)
#   endif
#   ifndef int128_t_defined
#      define int128_t_defined   (1)
#   endif
#   ifndef uint128_t_defined
#      define uint128_t_defined   (1)
#   endif
#   ifndef INT128_T_DEFINED
#      define INT128_T_DEFINED   (1)
#   endif
#   ifndef UINT128_T_DEFINED
#      define UINT128_T_DEFINED   (1)
#   endif
#   ifndef int128_t
/** 128-bit signed integer datatype (not all systems support int128_t) */
typedef signed int __attribute__((__mode__(__TI__)))   int128_t;
#   endif
#   ifndef uint128_t
/** 128-bit unsigned integer datatype (not all systems support uint128_t) */
typedef unsigned int __attribute__((__mode__(__TI__)))   uint128_t;
#   endif
#   ifdef SUPPORTS_INT128
/** 128-bit unsigned integer datatype (not all systems support uint128_t) */
typedef uint128_t   U_128;
#   endif
#   if (SIZEOF_LONG_DOUBLE == 16)
typedef union union_128 { uint128_t u; long double ld; }   union_128_t;
#   endif


typedef union int128_parts {
	int128_t swhole;
	uint128_t uwhole;
	uint8_t bytes[16];
	uint16_t octets[8];
	uint32_t words[4];
} int128_parts_t;


#else


#   if IS_LITTLE_ENDIAN
/** 128-bit signed integer datatype (not all systems support int128_t) */
typedef struct _int128_t_ { uint64_t lsw, int64_t msw }   int128_t;
/** 128-bit unsigned integer datatype (not all systems support uint128_t) */
typedef struct _uint128_t_ { uint64_t lsw, msw }   uint128_t;
#   elif IS_BIG_ENDIAN
/** 128-bit signed integer datatype (not all systems support int128_t) */
typedef struct _int128_t_ { uint64_t msw, int64_t lsw }   int128_t;
/** 128-bit unsigned integer datatype (not all systems support uint128_t) */
typedef struct _uint128_t_ { uint64_t msw, lsw }   uint128_t;
#   endif


#endif  // 128-BIT INTEGERS
#if SUPPORTS_INT128
#   ifndef __int128
/** 128-bit signed integer datatype (not all systems support int128_t) */
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
#   define _PDCLIB_int128_t   int128_t
#   ifndef __uint128
/** 128-bit unsigned integer datatype (not all systems support uint128_t) */
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
#   define _PDCLIB_uint128_t   uint128_t
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
#   ifndef __int256_t_defined
#      define __int256_t_defined   (1)
#   endif
#   ifndef __uint256_t_defined
#      define __uint256_t_defined   (1)
#   endif
#   ifndef int256_t_defined
#      define int256_t_defined   (1)
#   endif
#   ifndef uint256_t_defined
#      define uint256_t_defined   (1)
#   endif
#   ifndef INT256_T_DEFINED
#      define INT256_T_DEFINED   (1)
#   endif
#   ifndef UINT256_T_DEFINED
#      define UINT256_T_DEFINED   (1)
#   endif
#   ifndef int256_t
/** 256-bit signed integer datatype (not all systems support int256_t) */
typedef signed int __attribute__((__mode__(__OI__)))   int256_t;
#   endif
#   ifndef uint256_t
/** 256-bit unsigned integer datatype (not all systems support uint256_t) */
typedef unsigned int __attribute__((__mode__(__OI__)))   uint256_t;
#   endif
#   ifndef __int256
/** 256-bit signed integer datatype (not all systems support int256_t) */
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
#   define _PDCLIB_int256_t   int256_t
#   ifndef __uint256
/** 256-bit unsigned integer datatype (not all systems support uint256_t) */
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
#   define _PDCLIB_uint256_t   uint256_t
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


#ifndef octa
#   define octa   int256_t
#endif
#ifndef octa_t
#   define octa_t   int256_t
#endif
#ifndef uocta
#   define uocta   uint256_t
#endif
#ifndef uocta_t
#   define uocta_t   uint256_t
#endif


typedef union int256_parts {
	int256_t swhole;
	uint256_t uwhole;
	uint8_t bytes[32];
	uint16_t octets[16];
	uint32_t words[8];
	uint64_t quarters[4];
	uint128_t halfs[2];
} int256_parts_t;


#endif  // 256-BIT INTEGERS


// 512-BIT INTEGERS

#if SUPPORTS_INT512
#   ifndef __int512_t_defined
#      define __int512_t_defined   (1)
#   endif
#   ifndef __uint512_t_defined
#      define __uint512_t_defined   (1)
#   endif
#   ifndef int512_t_defined
#      define int512_t_defined   (1)
#   endif
#   ifndef uint512_t_defined
#      define uint512_t_defined   (1)
#   endif
#   ifndef INT512_T_DEFINED
#      define INT512_T_DEFINED   (1)
#   endif
#   ifndef UINT512_T_DEFINED
#      define UINT512_T_DEFINED   (1)
#   endif
#   ifndef int512_t
/** 512-bit signed integer datatype (not all systems support int512_t) */
typedef signed int __attribute__((__mode__(__OI__)))   int512_t;
#   endif
#   ifndef uint512_t
/** 512-bit unsigned integer datatype (not all systems support uint512_t) */
typedef unsigned int __attribute__((__mode__(__OI__)))   uint512_t;
#   endif
#   ifndef __int512
/** 512-bit signed integer datatype (not all systems support int512_t) */
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
#   define _PDCLIB_int512_t   int512_t
#   ifndef __uint512
/** 512-bit unsigned integer datatype (not all systems support uint512_t) */
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
#   define _PDCLIB_uint512_t   uint512_t
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


#ifndef hexadeca
#   define hexadeca   int512_t
#endif
#ifndef hexadeca_t
#   define hexadeca_t   int512_t
#endif
#ifndef uhexadeca
#   define uhexadeca   uint512_t
#endif
#ifndef uhexadeca_t
#   define uhexadeca_t   uint512_t
#endif


typedef union int512_parts {
	int512_t swhole;
	uint512_t uwhole;
	uint8_t bytes[64];
	uint16_t octets[32];
	uint32_t words[16];
	uint64_t dwords[8];
	uint128_t qwords[4];
	uint256_t halfs[2];
} int512_parts_t;


#endif  // 512-BIT INTEGERS


// LARGEST FIXED-WIDTH INTEGRAL DATATYPES

#if (defined(__UINTMAX_TYPE__) || defined(__INTMAX_TYPE__))
/** Maximum width integer type */
typedef __INTMAX_TYPE__   intmax_t;
#   define SIZEOF_INTMAX_T   (sizeof(intmax_t))
#   define BITS_PER_INTMAX_T   ((sizeof(intmax_t) * 8))
/** Maximum width unsigned integer type */
typedef __UINTMAX_TYPE__   uintmax_t;
#   define SIZEOF_UINTMAX_T   SIZEOF_INTMAX_T
#   define BITS_PER_UINTMAX_T   BITS_PER_UINTMAX_T
#elif SUPPORTS_INT512
/** Maximum width integer type */
typedef int512_t   intmax_t;
#   define SIZEOF_INTMAX_T   (64)
#   define BITS_PER_INTMAX_T   (512)
/** Maximum width unsigned integer type */
typedef uint512_t   uintmax_t;
#   define SIZEOF_UINTMAX_T   (64)
#   define BITS_PER_UINTMAX_T   (512)
#elif SUPPORTS_INT256
/** Maximum width integer type */
typedef int256_t   intmax_t;
#   define SIZEOF_INTMAX_T   (32)
#   define BITS_PER_INTMAX_T   (256)
/** Maximum width unsigned integer type */
typedef uint256_t   uintmax_t;
#   define SIZEOF_UINTMAX_T   (32)
#   define BITS_PER_UINTMAX_T   (256)
#elif SUPPORTS_INT128
/** Maximum width integer type */
typedef int128_t   intmax_t;
#   define SIZEOF_INTMAX_T   (16)
#   define BITS_PER_INTMAX_T   (128)
/** Maximum width unsigned integer type */
typedef uint128_t   uintmax_t;
#   define SIZEOF_UINTMAX_T   (16)
#   define BITS_PER_UINTMAX_T   (128)
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
#ifndef INTMAX_TYPE
#   define INTMAX_TYPE   intmax_t
#endif
#ifndef __intmax_t
#   define __intmax_t   intmax_t
#endif
#ifndef __uintmax_t
#   define __uintmax_t   uintmax_t
#endif
#define __type_mask(t)   (sizeof(t) < BYTES_PER_INTMAX_T ? (~((1ULL << (sizeof(t) * NBBY)) - 1)) : 0ULL)
#define type_mask(t)   __type_mask((t))


// 128-BIT FLOATS

#if SUPPORTS_FLOAT128  // TODO: Add float128 max, min, dig, epsilon, etc.


#ifdef COMPILER_CLANG
/** Work-around for Clang to produce __float128 */
typedef struct __float128 { uint8_t align16 x[16]; }   __float128;
#endif
#ifndef __float128_t
#   define __float128_t   __float128
#endif
#ifndef float128_t
#   define float128_t   __float128
#endif
#ifndef float128
#   define float128   __float128
#endif
#ifndef tetra
#   define tetra   __float128
#endif
#ifndef tetra_t
#   define tetra_t   __float128
#endif
#ifndef quadruple
#   define quadruple   __float128
#endif
#ifndef quadruple_t
#   define quadruple_t   __float128
#endif


typedef union float128_parts {
	float128_t whole;
	uint8_t bytes[16];
	uint16_t octets[8];
	uint32_t words[4];
	uint64_t dwords[2];
} float128_parts_t;


#endif  // 128-BIT FLOATS


// DECIMAL FLOATS

#if SUPPORTS_DECIMAL_FLOATS


typedef float __attribute__((__mode__(__SD__)))   _Decimal32;
typedef float __attribute__((__mode__(__DD__)))   _Decimal64;


/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#define decfloat32   _Decimal32
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#define _decfloat32   _Decimal32
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#define __decfloat32   _Decimal32
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#define decimal32   _Decimal32
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#define decimal32_t   _Decimal32
#ifndef Decimal32
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#   define Decimal32   _Decimal32
#endif
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#define DEC32_   _Decimal32
/** _Decimal32 is a 32-bit (4 octet) decimal float-point datatype */
#define dec32   _Decimal32
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#define decfloat64   _Decimal64
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#define _decfloat64   _Decimal64
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#define __decfloat64   _Decimal64
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#define decimal64   _Decimal64
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#define decimal64_t   _Decimal64
#ifndef Decimal64
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#   define Decimal64   _Decimal64
#endif
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#define DEC64_   _Decimal64
/** _Decimal64 is a 64-bit (8 octet) decimal float-point datatype */
#define dec64   _Decimal64


typedef union decimal32_parts {
	decimal32 whole;
	uint8_t bytes[4];
	uint16_t octets[2];
	uint32_t words[1];
} decimal32_parts_t;


typedef union decimal64_parts {
	decimal64 whole;
	uint8_t bytes[8];
	uint16_t octets[4];
	uint32_t words[2];
	uint64_t dwords[2];
} decimal64_parts_t;


#endif


// 128-BIT DECIMAL FLOATS

#if SUPPORTS_DECIMAL128


typedef float __attribute__((__mode__(__TD__)))   _Decimal128;


/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#define decfloat128   _Decimal128
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#define _decfloat128   _Decimal128
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#define __decfloat128   _Decimal128
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#define decimal128   _Decimal128
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#define decimal128_t   _Decimal128
#ifndef Decimal128
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#   define Decimal128   _Decimal128
#endif
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#define DEC128_   _Decimal128
/** _Decimal128 is a 128-bit (16 octet) decimal float-point datatype */
#define dec128   _Decimal128


typedef union decimal128_parts {
	Decimal128 whole;
	uint8_t bytes[16];
	uint16_t octets[8];
	uint32_t words[4];
	uint64_t dwords[2];
} decimal128_parts_t;


#endif


// IMAGINARY & COMPLEX DATATYPES

#if ((!defined(IMAGINARY_NUMBER_CONSTANTS_SEEN)) && SUPPORTS_COMPLEX)
#define IMAGINARY_NUMBER_CONSTANTS_SEEN   (1)


#if (AT_LEAST_GCC3 && (!defined(_Complex)))
#   define _Complex   __complex__
#endif
#ifndef complex
#   define complex   _Complex
#endif
#ifndef Complex
#   define Complex   _Complex
#endif
#ifndef imaginary
#   define imaginary   _Imaginary
#endif
#ifndef __imaginary__
#   define __imaginary__   _Imaginary
#endif
#define _Mfloat_   float
#define _Mdouble_   double
#define _Mlong_double_   long double
#define _Mdouble_complex_   _Mdouble_ _Complex
#define _Mfloat_complex_   _Mfloat_ _Complex
#define _Mlong_double_complex_   _Mlong_double_ _Complex
#define complex_float   _Complex float
#define complex_double   _Complex double
#define complex_long_double   _Complex long double
#define cfloat_t   _Complex float
#define cdouble_t   _Complex double
#define clong_double_t   _Complex long double
#define cldouble_t   _Complex long double
#ifndef _Complex_I
/** Imaginary unit */
#   define _Complex_I   (__extension__ (0.0F + 1.0iF))
#endif
#ifndef I
/** Most narrow imaginary unit */
#   define I   (__extension__ 1.0i)
#endif
#ifndef __I__
/** Most narrow imaginary unit */
#   define __I__   I
#endif
#ifndef _Imaginary_I
/** Most narrow imaginary unit */
#   define _Imaginary_I   I
#endif
#ifndef I_FLOAT
#   define I_FLOAT   (__extension__ 1.0iF)  // (const float _Complex)1.0F
#   define I_FLOAT_NEG   (__extension__ -1.0iF)
#   define I_FLOAT_ZERO   (__extension__ 0.0iF)
#   define I_FLOAT_NEG_ZERO   (__extension__ -0.0iF)
#endif
#ifndef I_DOUBLE
#   define I_DOUBLE   (__extension__ 1.0i)  // (const double _Complex)1.0
#   define I_DOUBLE_NEG   (__extension__ -1.0i)
#   define I_DOUBLE_ZERO   (__extension__ 0.0i)
#   define I_DOUBLE_NEG_ZERO   (__extension__ -0.0i)
#endif
#ifndef I_LONG_DOUBLE
#   define I_LONG_DOUBLE   (__extension__ 1.0iL)  // (const long double _Complex)1.0L
#   define I_LONG_DOUBLE_NEG   (__extension__ -1.0iL)
#   define I_LONG_DOUBLE_ZERO   (__extension__ 0.0iL)
#   define I_LONG_DOUBLE_NEG_ZERO   (__extension__ -0.0iL)
#endif
#ifndef TO_CMPLX  // TO_CMPLX
#   define TO_CMPLX(x, y, t)   ((t) (x) + _Imaginary_I * (t) (y))
#endif  // TO_CMPLX
/** Expand into expression of specified complex type */
#define CMPLX(x, y)   ((double)(x) + I_DOUBLE * (double)(y))
#define __CMPLX(x, y)   CMPLX((x), (y))
/** Expand into expression of specified complex type */
#define CMPLXF(x, y)   ((float)(x) + I_FLOAT * (float)(y))
#define __CMPLXF(x, y)   CMPLXF((x), (y))
/** Expand into expression of specified complex type */
#define CMPLXL(x, y)   ((long double)(x) + I_LONG_DOUBLE * (long double)(y))
#define __CMPLXL(x, y)   CMPLXL((x), (y))
#if IS_NOT_CPLUSPLUS
#   define __CIMAG(x, t)   (+(union { _Complex t __z; t __xy[2]; }) {(_Complex t)(x)}.__xy[1])
#endif


typedef union float_complex { float complex z; float parts[2]; }   float_complex;
typedef union double_complex { double complex z; double parts[2]; }   double_complex;
typedef union long_double_complex { long double complex z; long double parts[2]; }   long_double_complex;
typedef struct _float_complex { float re, im; }   float_complex_t;
typedef struct _double_complex { double re, im; }   double_complex_t;


typedef union complex_float_parts {
	complex_float whole;
	uint8_t bytes[8];
	uint16_t octets[4];
	uint32_t words[2];
	uint64_t value;
	float floats[2];
} complex_float_parts_t;


typedef union complex_double_parts {
	complex_double whole;
	uint8_t bytes[16];
	uint16_t octets[8];
	uint32_t words[4];
	uint64_t dwords[2];
	double doubles[2];
} complex_double_parts_t;


typedef union complex_long_double_parts {
	complex_long_double whole;
	uint8_t bytes[32];
	uint16_t octets[16];
	uint32_t words[8];
	uint64_t dwords[4];
	long double doubles[2];
} complex_long_double_parts_t;


#endif  // IMAGINARY_NUMBER_CONSTANTS_SEEN


// FLOAT-POINT ALIASES

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
#if SUPPORTS_FLOAT8
/** 8-bit quarter-precision float-point datatype */
typedef float __attribute__((__mode__(__QF__)))   QFtype;
#   define __float8   QFtype
#   define float8   QFtype
#   define float8_t   QFtype
#   define minifloat_t   QFtype
#   define minifloat   QFtype
#   define quarter_float   QFtype
#   define quarter_float_t   QFtype
#endif
#if SUPPORTS_FLOAT16
/** 16-bit half-precision float-point datatype */
typedef float __attribute__((__mode__(__HF__)))   HFtype;
#   ifndef fp16
#      define fp16   HFtype
#   endif
#   ifndef __float16
#      define __float16   fp16
#   endif
#   define float16   fp16
#   define float16_t   fp16
#   define half_float   fp16
#   define half_float_t   fp16
#endif
#if SUPPORTS_FLOAT24
/** 24-bit three-quarter-precision float-point datatype */
typedef float __attribute__((__mode__(__TQF__)))   TQFtype;
#   define float24   TQFtype
#   define float24_t   TQFtype
#endif
#if SUPPORTS_FLOAT80
#   define float80   __float80
#   define float80_t   __float80
#endif
#if SUPPORTS_FLOAT96
#   define float96   __float96
#   define float96_t   __float96
#endif


// MACHINE & STDFIX DATATYPES

typedef unsigned long long   fxvalue;
/** op/result */
typedef unsigned short   fxmask1;
/** op */
typedef unsigned short   fxmaskf;
/** result */
typedef unsigned short   fxmaskg;
/** op, result */
typedef unsigned short   fxmaskc;
/** op1, op2 */
typedef unsigned short   fxmaskr;
/** op1, op2, result */
typedef unsigned long   fxmask2;
// Map fixed-point datatype to the corresponding natural integer type
typedef __INT16_TYPE__   xint_hr_t;
typedef __UINT16_TYPE__   xint_uhr_t;
typedef __INT32_TYPE__   xint_hk_t;
typedef __UINT32_TYPE__   xint_uhk_t;
typedef __INT32_TYPE__   xint_r_t;
typedef __UINT32_TYPE__   xint_ur_t;
typedef __INT64_TYPE__   xint_k_t;
typedef __UINT64_TYPE__   xint_uk_t;
typedef __INT64_TYPE__   xint_lr_t;
typedef __UINT64_TYPE__   xint_ulr_t;
typedef char   int_qi_t;
typedef int   int_hi_t;
typedef long   int_si_t;
typedef long long   int_di_t;
typedef unsigned char   uint_qi_t;
typedef unsigned int   uint_hi_t;
typedef unsigned long   uint_si_t;
typedef unsigned long long   uint_di_t;
typedef signed char   int_hr_t;
#if (SIZEOF_INT == 4)
typedef int   int_hk_t;
typedef int   int_r_t;
typedef long   int_k_t;
typedef long   int_lr_t;
typedef long long   int_lk_t;
typedef long long   int_llk_t;
typedef long long   int_llr_t;
typedef unsigned char   int_uhr_t;
typedef unsigned int   int_uhk_t;
typedef unsigned int   int_ur_t;
typedef unsigned long   int_uk_t;
typedef unsigned long   int_ulr_t;
typedef unsigned long long   int_ulk_t;
typedef unsigned long long   int_ullk_t;
typedef unsigned long long   int_ullr_t;
#elif (SIZEOF_INT == 2)
typedef short   int_hk_t;
typedef short   int_r_t;
typedef unsigned short   int_uhk_t;
typedef unsigned short   int_ur_t;
typedef long   int_k_t;
typedef long   int_lr_t;
typedef unsigned long   int_uk_t;
typedef unsigned long   int_ulr_t;
typedef long long   int_lk_t;
typedef long long   int_llk_t;
typedef long long   int_llr_t;
typedef unsigned long long   int_ulk_t;
typedef unsigned long long   int_ullk_t;
typedef unsigned long long   int_ullr_t;
#elif (SIZEOF_INT == 1)
typedef long   int_hk_t;
typedef long   int_r_t;
typedef unsigned long   int_uhk_t;
typedef unsigned long   int_ur_t;
typedef long long   int_k_t;
typedef long long   int_lr_t;
typedef unsigned long long   int_uk_t;
typedef unsigned long long   int_ulr_t;
#endif
#define uint_uhr_t   int_uhr_t
#define uint_ur_t   int_ur_t
#define uint_ulr_t   int_ulr_t
#define uint_ullr_t   int_ullr_t
#define uint_uhk_t   int_uhk_t
#define uint_uk_t   int_uk_t
#define uint_ulk_t   int_ulk_t
#define uint_ullk_t   int_ullk_t


#if SUPPORTS_STDFIX


#define accum   _Accum
#define accum_t   _Accum
#define Accum_t   _Accum
#define fract   _Fract
#define fract_t   _Fract
#define Fract_t   _Fract
#define sat   _Sat
#define sat_t   _Sat
#define Sat_t   _Sat
#define HAVE_QQ   (1)
#define HAVE_UQQ   (1)
#define HAVE_HQ   (1)
#define HAVE_UHQ   (1)
#define HAVE_HA   (1)
#define HAVE_UHA   (1)


typedef _Fract   fx_t;
typedef _Sat _Fract   satfx_t;
typedef _Sat short _Fract   satfx_hr_t;
typedef short _Fract   fx_hr_t;
typedef _Fract   fx_r_t;
typedef long _Fract   fx_lr_t;
typedef long long _Fract   fx_llr_t;
typedef unsigned short _Fract   fx_uhr_t;
typedef unsigned _Fract   fx_ur_t;
typedef unsigned long _Fract   fx_ulr_t;
typedef unsigned long long _Fract   fx_ullr_t;
typedef short _Accum   fx_hk_t;
typedef _Accum   fx_k_t;
typedef long _Accum   fx_lk_t;
typedef long long _Accum   fx_llk_t;
typedef unsigned short _Accum   fx_uhk_t;
typedef unsigned _Accum   fx_uk_t;
typedef unsigned long _Accum   fx_ulk_t;
typedef unsigned long long _Accum   fx_ullk_t;


#ifdef COMPILER_CLANG
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wimplicit-int"
#elif defined(COMPILER_GNUC)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wimplicit-int"
#endif

typedef signed _Fract __attribute__((__mode__(__QQ__)))   QQtype;
typedef unsigned _Fract __attribute__((__mode__(__UQQ__)))   UQQtype;
#define QQ   QQtype
#define UQQ   UQQtype
typedef signed _Fract __attribute__((__mode__(__HQ__)))   HQtype;
typedef unsigned _Fract __attribute__((__mode__(__UHQ__)))   UHQtype;
#define HQ   HQtype
#define UHQ   UHQtype
typedef signed _Fract __attribute__((__mode__(__HA__)))   HAtype;
typedef unsigned _Fract __attribute__((__mode__(__UHA__)))   UHAtype;
#define HA   HAtype
#define UHA   UHAtype

#ifdef COMPILER_CLANG
#   pragma clang diagnostic pop
#elif defined(COMPILER_GNUC)
#   pragma GCC diagnostic pop
#endif


#if (MIN_UNITS_PER_WORD > 1)
typedef _Fract __attribute__((__mode__(__SQ__)))   SQtype;
typedef unsigned _Fract __attribute__((__mode__(__USQ__)))   USQtype;
#   define SQ   SQtype
#   define USQ   USQtype
typedef _Fract __attribute__((__mode__(__SA__)))   SAtype;
typedef unsigned _Fract __attribute__((__mode__(__USA__)))   USAtype;
#   define SA   SAtype
#   define USA   USAtype
#   define HAVE_SQ   (1)
#   define HAVE_USQ   (1)
#   define HAVE_SA   (1)
#   define HAVE_USA   (1)
#   if (LONG_LONG_TYPE_SIZE > 32)
typedef _Fract __attribute__((__mode__(__DQ__)))   DQtype;
typedef unsigned _Fract __attribute__((__mode__(__UDQ__)))   UDQtype;
#      define DQ   DQtype
#      define UDQ   UDQtype
typedef _Fract __attribute__((__mode__(__DA__)))   DAtype;
typedef unsigned _Fract __attribute__((__mode__(__UDA__)))   UDAtype;
#      define DA   DAtype
#      define UDA   UDAtype
#      define HAVE_DQ   (1)
#      define HAVE_UDQ   (1)
#      define HAVE_DA   (1)
#      define HAVE_UDA   (1)
#      if (MIN_UNITS_PER_WORD > 4)
typedef _Fract __attribute__((__mode__(__TQ__)))   TQtype;
typedef unsigned _Fract __attribute__((__mode__(__UTQ__)))   UTQtype;
#         define TQ   TQtype
#         define UTQ   UTQtype
typedef _Fract __attribute__((__mode__(__TA__)))   TAtype;
typedef unsigned _Fract __attribute__((__mode__(__UTA__)))   UTAtype;
#         define TA   TAtype
#         define UTA   UTAtype
#         define HAVE_TQ   (1)
#         define HAVE_UTQ   (1)
#         define HAVE_TA   (1)
#         define HAVE_UTA   (1)
#      endif  // (MIN_UNITS_PER_WORD > 4)
#   endif  // (LONG_LONG_TYPE_SIZE > 32)
#endif  // (MIN_UNITS_PER_WORD > 1)
#else  // !SUPPORTS_STDFIX
#   define HAVE_QQ   (0)
#   define HAVE_UQQ   (0)
#   define HAVE_HQ   (0)
#   define HAVE_UHQ   (0)
#   define HAVE_HA   (0)
#   define HAVE_UHA   (0)
#   define HAVE_SQ   (0)
#   define HAVE_USQ   (0)
#   define HAVE_SA   (0)
#   define HAVE_USA   (0)
#   define HAVE_DQ   (0)
#   define HAVE_UDQ   (0)
#   define HAVE_DA   (0)
#   define HAVE_UDA   (0)
#   define HAVE_TQ   (0)
#   define HAVE_UTQ   (0)
#   define HAVE_TA   (0)
#   define HAVE_UTA   (0)


#endif  // SUPPORTS_STDFIX


// FRACTIONAL MODES

#if SUPPORTS_STDFIX

#if (defined(QQ_MODE) && (HAVE_QQ == 1))
#   define FIXED_SIZE   (1)
#   define INT_C_TYPE   QItype
#   define UINT_C_TYPE   UQItype
#   define DINT_C_TYPE   HItype
#   define DUINT_C_TYPE   UHItype
#   define MODE_NAME   QQ
#   define MODE_NAME_S   qq
#   define MODE_UNSIGNED   (0)
#elif (defined(UQQ_MODE) && (HAVE_UQQ == 1))
#   define FIXED_SIZE   (1)
#   define INT_C_TYPE   UQItype
#   define UINT_C_TYPE   UQItype
#   define DINT_C_TYPE   UHItype
#   define DUINT_C_TYPE   UHItype
#   define MODE_NAME   UQQ
#   define MODE_NAME_S   uqq
#   define MODE_UNSIGNED   (1)
#elif (defined(HQ_MODE) && (HAVE_HQ == 1))
#   define FIXED_SIZE   (2)
#   define INT_C_TYPE   HItype
#   define UINT_C_TYPE   UHItype
#   if (HAVE_SI == 1)
#      define DINT_C_TYPE   SItype
#      define DUINT_C_TYPE   USItype
#   else
#      define HINT_C_TYPE   QItype
#      define HUINT_C_TYPE   UQItype
#   endif
#   define MODE_NAME   HQ
#   define MODE_NAME_S   hq
#   define MODE_UNSIGNED   (0)
#elif (defined(UHQ_MODE) && (HAVE_UHQ == 1))
#   define FIXED_SIZE   (2)
#   define INT_C_TYPE   UHItype
#   define UINT_C_TYPE   UHItype
#   if (HAVE_SI == 1)
#      define DINT_C_TYPE   USItype
#      define DUINT_C_TYPE   USItype
#   else
#      define HINT_C_TYPE   UQItype
#      define HUINT_C_TYPE   UQItype
#   endif
#   define MODE_NAME   UHQ
#   define MODE_NAME_S   uhq
#   define MODE_UNSIGNED   (1)
#elif (defined(SQ_MODE) && (HAVE_SQ == 1))
#   define FIXED_SIZE   (4)
#   define INT_C_TYPE   SItype
#   define UINT_C_TYPE   USItype
#   if (HAVE_DI == 1)
#      define DINT_C_TYPE   DItype
#      define DUINT_C_TYPE   UDItype
#   else
#      define HINT_C_TYPE   HItype
#      define HUINT_C_TYPE   UHItype
#   endif
#   define MODE_NAME   SQ
#   define MODE_NAME_S   sq
#   define MODE_UNSIGNED   (0)
#elif (defined(USQ_MODE) && (HAVE_USQ == 1))
#   define FIXED_SIZE   (4)
#   define INT_C_TYPE   USItype
#   define UINT_C_TYPE   USItype
#   if (HAVE_DI == 1)
#      define DINT_C_TYPE   UDItype
#      define DUINT_C_TYPE   UDItype
#   else
#      define HINT_C_TYPE   UHItype
#      define HUINT_C_TYPE   UHItype
#   endif
#   define MODE_NAME   USQ
#   define MODE_NAME_S   usq
#   define MODE_UNSIGNED   (1)
#elif (defined(DQ_MODE) && (HAVE_DQ == 1))
#   define FIXED_SIZE   (8)
#   define INT_C_TYPE   DItype
#   define UINT_C_TYPE   UDItype
#   if (HAVE_TI == 1)
#      define DINT_C_TYPE   TItype
#      define DUINT_C_TYPE   UTItype
#   else
#      define HINT_C_TYPE   SItype
#      define HUINT_C_TYPE   USItype
#   endif
#   define MODE_NAME   DQ
#   define MODE_NAME_S   dq
#   define MODE_UNSIGNED   (0)
#elif (defined(UDQ_MODE) && (HAVE_UDQ == 1))
#   define FIXED_SIZE   (8)
#   define INT_C_TYPE   UDItype
#   define UINT_C_TYPE   UDItype
#   if (HAVE_TI == 1)
#      define DINT_C_TYPE   UTItype
#      define DUINT_C_TYPE   UTItype
#   else
#      define HINT_C_TYPE   USItype
#      define HUINT_C_TYPE   USItype
#   endif
#   define MODE_NAME   UDQ
#   define MODE_NAME_S   udq
#   define MODE_UNSIGNED   (1)
#elif (defined(TQ_MODE) && (HAVE_TQ == 1))
#   define FIXED_SIZE   (16)
#   define INT_C_TYPE   TItype
#   define UINT_C_TYPE   UTItype
#   define HINT_C_TYPE   DItype
#   define HUINT_C_TYPE   UDItype
#   define MODE_NAME   TQ
#   define MODE_NAME_S   tq
#   define MODE_UNSIGNED   (0)
#elif (defined(UTQ_MODE) && (HAVE_UTQ == 1))
#   define FIXED_SIZE   (16)
#   define INT_C_TYPE   UTItype
#   define UINT_C_TYPE   UTItype
#   define HINT_C_TYPE   UDItype
#   define HUINT_C_TYPE   UDItype
#   define MODE_NAME   UTQ
#   define MODE_NAME_S   utq
#   define MODE_UNSIGNED   (1)
#endif  // FRACTIONAL MODES

#endif  // SUPPORTS_STDFIX


// ACCUMULATOR MODES

#if SUPPORTS_STDFIX

#if (defined(HA_MODE) && (HAVE_HA == 1))
#   define FIXED_SIZE   (2)
#   define INT_C_TYPE   HItype
#   define UINT_C_TYPE   UHItype
#   if (HAVE_SI == 1)
#      define DINT_C_TYPE   SItype
#      define DUINT_C_TYPE   USItype
#   else
#      define HINT_C_TYPE   QItype
#      define HUINT_C_TYPE   UQItype
#   endif
#   define MODE_NAME   HA
#   define MODE_NAME_S   ha
#   define MODE_UNSIGNED   (0)
#elif (defined(UHA_MODE) && (HAVE_UHA == 1))
#   define FIXED_SIZE   (2)
#   define INT_C_TYPE   UHItype
#   define UINT_C_TYPE   UHItype
#   if (HAVE_SI == 1)
#      define DINT_C_TYPE   USItype
#      define DUINT_C_TYPE   USItype
#   else
#      define HINT_C_TYPE   UQItype
#      define HUINT_C_TYPE   UQItype
#   endif
#   define MODE_NAME   UHA
#   define MODE_NAME_S   uha
#   define MODE_UNSIGNED   (1)
#elif (defined(SA_MODE) && (HAVE_SA == 1))
#   define FIXED_SIZE   (4)
#   define INT_C_TYPE   SItype
#   define UINT_C_TYPE   USItype
#   if (HAVE_DI == 1)
#      define DINT_C_TYPE   DItype
#      define DUINT_C_TYPE   UDItype
#   else
#      define HINT_C_TYPE   HItype
#      define HUINT_C_TYPE   UHItype
#   endif
#   define MODE_NAME   SA
#   define MODE_NAME_S   sa
#   define MODE_UNSIGNED   (0)
#elif (defined(USA_MODE) && (HAVE_USA == 1))
#   define FIXED_SIZE   (4)
#   define INT_C_TYPE   USItype
#   define UINT_C_TYPE   USItype
#   if (HAVE_DI == 1)
#      define DINT_C_TYPE   UDItype
#      define DUINT_C_TYPE   UDItype
#   else
#      define HINT_C_TYPE   UHItype
#      define HUINT_C_TYPE   UHItype
#endif
#   define MODE_NAME   USA
#   define MODE_NAME_S   usa
#   define MODE_UNSIGNED   (1)
#elif (defined(DA_MODE) && (HAVE_DA == 1))
#   define FIXED_SIZE   (8)
#   define INT_C_TYPE   DItype
#   define UINT_C_TYPE   UDItype
#   if (HAVE_TI == 1)
#      define DINT_C_TYPE   TItype
#      define DUINT_C_TYPE   UTItype
#   else
#      define HINT_C_TYPE   SItype
#      define HUINT_C_TYPE   USItype
#   endif
#   define MODE_NAME   DA
#   define MODE_NAME_S   da
#   define MODE_UNSIGNED   (0)
#elif (defined(UDA_MODE) && (HAVE_UDA == 1))
#   define FIXED_SIZE   (8)
#   define INT_C_TYPE   UDItype
#   define UINT_C_TYPE   UDItype
#   if (HAVE_TI == 1)
#      define DINT_C_TYPE   UTItype
#      define DUINT_C_TYPE   UTItype
#   else
#      define HINT_C_TYPE   USItype
#      define HUINT_C_TYPE   USItype
#   endif
#   define MODE_NAME   UDA
#   define MODE_NAME_S   uda
#   define MODE_UNSIGNED   (1)
#elif (defined(TA_MODE) && (HAVE_TA == 1))
#   define FIXED_SIZE   (16)
#   define INT_C_TYPE   TItype
#   define UINT_C_TYPE   UTItype
#   define HINT_C_TYPE   DItype
#   define HUINT_C_TYPE   UDItype
#   define MODE_NAME   TA
#   define MODE_NAME_S   ta
#   define MODE_UNSIGNED   (0)
#elif (defined(UTA_MODE) && (HAVE_UTA == 1))
#   define FIXED_SIZE   (16)
#   define INT_C_TYPE   UTItype
#   define UINT_C_TYPE   UTItype
#   define HINT_C_TYPE   UDItype
#   define HUINT_C_TYPE   UDItype
#   define MODE_NAME   UTA
#   define MODE_NAME_S   uta
#   define MODE_UNSIGNED   (1)
#endif  // ACCUMULATOR MODES

#endif  // SUPPORTS_STDFIX


// BASIC DATATYPE MODES

// Integer Modes
#define SUPPORTS_QITYPE   (1)
#define SUPPORTS_UQITYPE   (1)
typedef signed int __attribute__((__mode__(__QI__)))   QItype;
#define QI   QItype
typedef unsigned int __attribute__((__mode__(__QI__)))   UQItype;
#define UQI   UQItype
#define SUPPORTS_HITYPE   (1)
#define SUPPORTS_UHITYPE   (1)
typedef signed int __attribute__((__mode__(__HI__)))   HItype;
#define HI   HItype
typedef unsigned int __attribute__((__mode__(__HI__)))   UHItype;
#define UHI   UHItype
#ifdef ARCHAVR
/** Partial Single Integer; 4 bytes (not all bits used) */
typedef signed int __attribute__((__mode__(__PSI__)))   PSItype;
#define SUPPORTS_PSITYPE   (1)
typedef unsigned int __attribute__((__mode__(__PSI__)))   UPSItype;
#define SUPPORTS_UPSITYPE   (1)
#   define PSI   PSItype
#   define UPSI   UPSItype
#endif
#define SUPPORTS_SITYPE   (1)
#define SUPPORTS_USITYPE   (1)
typedef int __attribute__((__mode__(__SI__)))   SItype;
#define SI   SItype
typedef unsigned int __attribute__((__mode__(__SI__)))   USItype;
#define USI   USItype
#define UHWtype   USItype
#define USWtype   USItype
#ifdef ARCHAVR
typedef signed int __attribute__((__mode__(__PDI__)))   PDItype;
typedef unsigned int __attribute__((__mode__(__PDI__)))   UPDItype;
#   define PDI   PDItype
#   define UPDI   UPDItype
#   define SUPPORTS_PDITYPE   (1)
#   define SUPPORTS_UPDITYPE   (1)
#else
#   define SUPPORTS_PDITYPE   (0)
#   define SUPPORTS_UPDITYPE   (0)
#endif
#define SUPPORTS_DITYPE   (1)
#define SUPPORTS_UDITYPE   (1)
typedef int __attribute__((__mode__(__DI__)))   DItype;
#define DI   DItype
typedef unsigned int __attribute__((__mode__(__DI__)))   UDItype;
#define UDWtype   UDItype
#define UDI   UDItype
#if SUPPORTS_INT128
typedef signed int __attribute__((__mode__(__TI__)))   TItype;
typedef unsigned int __attribute__((__mode__(__TI__)))   UTItype;
#   define TI   TItype
#   define UTI   UTItype
#   define SUPPORTS_TITYPE   (1)
#   define SUPPORTS_UTITYPE   (1)
#else
#   define SUPPORTS_TITYPE   (0)
#   define SUPPORTS_UTITYPE   (0)
#endif
#if SUPPORTS_INT256
typedef signed int __attribute__((__mode__(__OI__)))   OItype;
typedef unsigned int __attribute__((__mode__(__OI__)))   UOItype;
#   define OI   OItype
#   define UOI   UOItype
#   define SUPPORTS_OITYPE   (1)
#   define SUPPORTS_UOITYPE   (1)
#else
#   define SUPPORTS_OITYPE   (0)
#   define SUPPORTS_UOITYPE   (0)
#endif
#if SUPPORTS_INT512
typedef signed int __attribute__((__mode__(__XI__)))   XItype;
typedef unsigned int __attribute__((__mode__(__XI__)))   UXItype;
#   define XI   XItype
#   define UXI   UXItype
#   define SUPPORTS_XITYPE   (1)
#   define SUPPORTS_UXITYPE   (1)
#else
#   define SUPPORTS_XITYPE   (0)
#   define SUPPORTS_UXITYPE   (0)
#endif
typedef signed int __attribute__((__mode__(__word__)))   Wtype;
#define SUPPORTS_WTYPE   (1)
#define sword_type   Wtype
#define signed_word_type   Wtype
#define word_type   Wtype
typedef unsigned int __attribute__((__mode__(__word__)))   UWtype;
#define SUPPORTS_UWTYPE   (1)
#define uword_type   UWtype
#define unsigned_word_type   UWtype
// Float-Point Modes
#ifdef ARCHAVR
/** 8-bit quarter-precision float-point datatype */
typedef float __attribute__((__mode__(__QF__)))   QFtype;
#   define QF   QFtype
#   define SUPPORTS_QFTYPE   (1)
/** 16-bit half-precision float-point datatype */
typedef float __attribute__((__mode__(__HF__)))   HFtype;
#   define HF   HFtype
#   define SUPPORTS_HFTYPE   (1)
/** 24-bit three-quarter-precision float-point datatype */
typedef float __attribute__((__mode__(__TQF__)))   TQFtype;
#   define TQF   TQFtype
#   define SUPPORTS_TQFTYPE   (1)
#else
#   define SUPPORTS_QFTYPE   (0)
#   define SUPPORTS_HFTYPE   (0)
#   define SUPPORTS_TQFTYPE   (0)
#endif
typedef float __attribute__((__mode__(__SF__)))   SFtype;
#define SF   SFtype
#define SUPPORTS_SFTYPE   (1)
typedef float __attribute__((__mode__(__DF__)))   DFtype;
#define DF   DFtype
#define SUPPORTS_DFTYPE   (1)
#if (SIZEOF_LONG_DOUBLE == SIZEOF_XFTYPE)
typedef float __attribute__((__mode__(__XF__)))   XFtype;
#   define SUPPORTS_XFTYPE   (1)
#else
#   define SUPPORTS_XFTYPE   (0)
#endif
#if SUPPORTS_FLOAT128
typedef float __attribute__((__mode__(__TF__)))   TFtype;
#   define SUPPORTS_TFTYPE   (1)
#else
#   define SUPPORTS_TFTYPE   (0)
#endif
#if SUPPORTS_DECIMAL_FLOATS
typedef float __attribute__((__mode__(__SD__)))   SDtype;
typedef float __attribute__((__mode__(__DD__)))   DDtype;
#   define SD   SDtype
#   define DD   DDtype
#   define SUPPORTS_SDTYPE   (1)
#   define SUPPORTS_DDTYPE   (1)
#   if SUPPORTS_DECIMAL128
typedef float __attribute__((__mode__(__TD__)))   TDtype;
#      define TD   TDtype
#      define SUPPORTS_TDTYPE   (1)
#   else
#      define SUPPORTS_TDTYPE   (0)
#   endif
#else
#   define SUPPORTS_SDTYPE   (0)
#   define SUPPORTS_DDTYPE   (0)
#   define SUPPORTS_TDTYPE   (0)
#endif
// Complex Modes
#if SUPPORTS_COMPLEX
#   ifdef ARCHAVR
typedef _Complex float __attribute__((__mode__(__QC__)))   QCtype;
#      define QC   QCtype
#      define SUPPORTS_QCTYPE   (1)
typedef _Complex float __attribute__((__mode__(__HC__)))   HCtype;
#      define HC   HCtype
#      define SUPPORTS_HCTYPE   (1)
#   else
#      define SUPPORTS_QCTYPE   (0)
#      define SUPPORTS_HCTYPE   (0)
#   endif
typedef _Complex float __attribute__((__mode__(__SC__)))   SCtype;
#   define SC   SCtype
#   define SUPPORTS_SCTYPE   (1)
typedef _Complex float __attribute__((__mode__(__DC__)))   DCtype;
#   define DC   DCtype
#   define SUPPORTS_DCTYPE   (1)
#   if SUPPORTS_COMPLEX128
typedef _Complex float __attribute__((__mode__(__XC__)))   XCtype;
#      define XC   XCtype
#      define SUPPORTS_XCTYPE   (1)
#   else
#      define SUPPORTS_XCTYPE   (0)
#   endif
#   if SUPPORTS_COMPLEX256
typedef _Complex float __attribute__((__mode__(__TC__)))   TCtype;
#      define TC   TCtype
#      define SUPPORTS_TCTYPE   (1)
#   else
#      define SUPPORTS_TCTYPE   (0)
#   endif
#   if SUPPORTS_COMPLEX_INT
typedef _Complex float __attribute__((__mode__(__CQI__)))   CQItype;
#      define CQI   CQItype
#      define SUPPORTS_CQITYPE   (1)
typedef _Complex float __attribute__((__mode__(__CHI__)))   CHItype;
#      define CHI   CHItype
#      define SUPPORTS_CHITYPE   (1)
typedef _Complex float __attribute__((__mode__(__CSI__)))   CSItype;
#      define CSI   CSItype
#      define SUPPORTS_CSITYPE   (1)
typedef _Complex float __attribute__((__mode__(__CDI__)))   CDItype;
#      define CDI   CDItype
#      define SUPPORTS_CDITYPE   (1)
#      if SUPPORTS_COMPLEX_INT128
typedef _Complex float __attribute__((__mode__(__CTI__)))   CTItype;
#         define CTI   CTItype
#         define SUPPORTS_CTITYPE   (1)
#      else
#         define SUPPORTS_CTITYPE   (0)
#      endif
#      if SUPPORTS_COMPLEX_INT256
typedef _Complex float __attribute__((__mode__(__COI__)))   COItype;
#         define COI   COItype
#         define SUPPORTS_COITYPE   (1)
#      else
#         define SUPPORTS_COITYPE   (0)
#      endif
#   else
#      define SUPPORTS_CQITYPE   (0)
#      define SUPPORTS_CHITYPE   (0)
#      define SUPPORTS_CSITYPE   (0)
#      define SUPPORTS_CDITYPE   (0)
#      define SUPPORTS_CTITYPE   (0)
#      define SUPPORTS_COITYPE   (0)
#   endif  // SUPPORTS_COMPLEX_INT
#else
#   define SUPPORTS_QCTYPE   (0)
#   define SUPPORTS_HCTYPE   (0)
#   define SUPPORTS_SCTYPE   (0)
#   define SUPPORTS_DCTYPE   (0)
#   define SUPPORTS_XCTYPE   (0)
#   define SUPPORTS_TCTYPE   (0)
#   define SUPPORTS_CQITYPE   (0)
#   define SUPPORTS_CHITYPE   (0)
#   define SUPPORTS_CSITYPE   (0)
#   define SUPPORTS_CDITYPE   (0)
#   define SUPPORTS_CTITYPE   (0)
#   define SUPPORTS_COITYPE   (0)
#endif  // SUPPORTS_COMPLEX
// Miscellaneous Modes
#if SUPPORTS_CONDITION_CODE
typedef int __attribute__((__mode__(__CC__)))   CCtype;
#   define SUPPORTS_CCTYPE   (1)
#else
#   define SUPPORTS_CCTYPE   (0)
#endif
#if SUPPORTS_BLK
typedef size_t __attribute__((__mode__(__BLK__)))   BLKtype;
#   define SUPPORTS_BLKTYPE   (1)
#else
#   define SUPPORTS_BLKTYPE   (0)
#endif
// HAVE_* Datatype Flags
#define HAVE_QI   (1)
#define HAVE_UQI   (1)
#define HAVE_HI   (1)
#define HAVE_UHI   (1)
#define HAVE_SI   (1)
#define HAVE_USI   (1)
#define HAVE_UHW   (1)
#define HAVE_USW   (1)
#ifdef ARCHAVR
#   define HAVE_PSI   (1)
#   define HAVE_UPSI   (1)
#   define HAVE_PDI   (1)
#   define HAVE_UPDI   (1)
#else
#   define HAVE_PSI   (0)
#   define HAVE_UPSI   (0)
#   define HAVE_PDI   (0)
#   define HAVE_UPDI   (0)
#endif
#define HAVE_DI   (1)
#define HAVE_UDI   (1)
#define HAVE_UDW   (1)
#if SUPPORTS_INT128
#   define HAVE_TI   (1)
#   define HAVE_UTI   (1)
#else
#   define HAVE_TI   (0)
#   define HAVE_UTI   (0)
#endif
#if SUPPORTS_INT256
#   define HAVE_OI   (1)
#   define HAVE_UOI   (1)
#else
#   define HAVE_OI   (0)
#   define HAVE_UOI   (0)
#endif
#if SUPPORTS_INT512
#   define HAVE_XI   (1)
#   define HAVE_UXI   (1)
#else
#   define HAVE_XI   (0)
#   define HAVE_UXI   (0)
#endif
#define HAVE_WORD   (1)
#define HAVE_W   (1)
#define HAVE_UW   (1)
#if SUPPORTS_FLOAT8
#   define HAVE_QF   (1)
#else
#   define HAVE_QF   (0)
#endif
#if SUPPORTS_FLOAT16
#   define HAVE_HF   (1)
#else
#   define HAVE_HF   (0)
#endif
#if SUPPORTS_FLOAT24
#   define HAVE_TQF   (1)
#else
#   define HAVE_TQF   (0)
#endif
#define HAVE_SF   (1)
#define HAVE_DF   (1)
#if SUPPORTS_DECIMAL_FLOATS
#   define HAVE_SD   (1)
#   define HAVE_DD   (1)
#   if SUPPORTS_DECIMAL128
#      define HAVE_TD   (1)
#   else
#      define HAVE_TD   (0)
#   endif
#else
#   define HAVE_SD   (0)
#   define HAVE_DD   (0)
#   define HAVE_TD   (0)
#endif
#if SUPPORTS_COMPLEX
#   ifdef ARCHAVR
#      define HAVE_QC   (1)
#      define HAVE_HC   (1)
#   else
#      define HAVE_QC   (0)
#      define HAVE_HC   (0)
#   endif
#   define HAVE_SC   (1)
#   define HAVE_DC   (1)
#   ifdef SUPPORTS_COMPLEX128
#      define HAVE_XC   (1)
#   else
#      define HAVE_XC   (0)
#   endif
#   ifdef SUPPORTS_COMPLEX256
#      define HAVE_TC   (1)
#   else
#      define HAVE_TC   (0)
#   endif
#   ifdef SUPPORTS_COMPLEX_INT
#      define HAVE_CQI   (1)
#      define HAVE_CHI   (1)
#      define HAVE_CSI   (1)
#      define HAVE_CDI   (1)
#      ifdef SUPPORTS_COMPLEX_INT128
#         define HAVE_CTI   (1)
#      else
#         define HAVE_CTI   (0)
#      endif
#      ifdef SUPPORTS_COMPLEX_INT256
#         define HAVE_COI   (1)
#      else
#         define HAVE_COI   (0)
#      endif
#   else
#      define HAVE_CQI   (0)
#      define HAVE_CHI   (0)
#      define HAVE_CSI   (0)
#      define HAVE_CDI   (0)
#      define HAVE_CTI   (0)
#      define HAVE_COI   (0)
#   endif  // SUPPORTS_COMPLEX_INT
#else
#   define HAVE_QC   (0)
#   define HAVE_HC   (0)
#   define HAVE_SC   (0)
#   define HAVE_DC   (0)
#   define HAVE_XC   (0)
#   define HAVE_TC   (0)
#   define HAVE_CQI   (0)
#   define HAVE_CHI   (0)
#   define HAVE_CSI   (0)
#   define HAVE_CDI   (0)
#   define HAVE_CTI   (0)
#   define HAVE_COI   (0)
#endif
#define HAVE_BND32   (0)
#define HAVE_BND64   (0)
#if SUPPORTS_CONDITION_CODE
#   define HAVE_CC   (1)
#else
#   define HAVE_CC   (0)
#endif
#if SUPPORTS_BLK
#   define HAVE_BLK   (1)
#else
#   define HAVE_BLK   (0)
#endif
#define HAVE_BI   (0)


// BASIC DATATYPE MODE MACROS

#define Wtype_MAX   ((Wtype)(((UWtype)1 << (W_TYPE_SIZE - 1)) - 1))
#define Wtype_MIN   (-((Wtype_MAX) - 1))
// Quarter Integer Convertions
/** Convert a QI datatype to UQI */
#define QI2UQI(x)   ((UQI)(x))
/** Convert a UQI datatype to QI */
#define UQI2QI(x)   ((QI)(x))
/** Convert a QI datatype to UQItype */
#define QI2UQItype(x)   ((UQItype)(x))
/** Convert a UQI datatype to UQItype */
#define UQI2UQItype(x)   ((UQItype)(x))
/** Convert a UQItype datatype to QI */
#define UQItype2QI(x)   ((QI)(x))
/** Convert a UQItype datatype to UQI */
#define UQItype2UQI(x)   ((UQI)(x))
/** Convert a QI datatype to QItype */
#define QI2QItype(x)   ((QItype)(x))
/** Convert a UQI datatype to UQItype */
#define UQI2QItype(x)   ((QItype)(x))
/** Convert a QItype datatype to QI */
#define QItype2QI(x)   ((QI)(x))
/** Convert a QItype datatype to UQI */
#define QItype2UQI(x)   ((UQI)(x))
/** Convert a UQItype datatype to QItype */
#define UQItype2QItype(x)   ((QItype)(x))
/** Convert a QItype datatype to UQItype */
#define QItype2UQItype(x)   ((UQItype)(x))
// Half Integer Convertions
/** Convert a HI datatype to UHI */
#define HI2UHI(x)   ((UHI)(x))
/** Convert a UHI datatype to HI */
#define UHI2HI(x)   ((HI)(x))
/** Convert a HI datatype to UHItype */
#define HI2UHItype(x)   ((UHItype)(x))
/** Convert a UHI datatype to UHItype */
#define UHI2UHItype(x)   ((UHItype)(x))
/** Convert a UHItype datatype to HI */
#define UHItype2HI(x)   ((HI)(x))
/** Convert a UHItype datatype to UHI */
#define UHItype2UHI(x)   ((UHI)(x))
/** Convert a HI datatype to HItype */
#define HI2HItype(x)   ((HItype)(x))
/** Convert a UHI datatype to UHItype */
#define UHI2HItype(x)   ((HItype)(x))
/** Convert a HItype datatype to HI */
#define HItype2HI(x)   ((HI)(x))
/** Convert a HItype datatype to UHI */
#define HItype2UHI(x)   ((UHI)(x))
/** Convert a UHItype datatype to HItype */
#define UHItype2HItype(x)   ((HItype)(x))
/** Convert a HItype datatype to UHItype */
#define HItype2UHItype(x)   ((UHItype)(x))
// Single Integer Convertions
/** Convert a SI datatype to USI */
#define SI2USI(x)   ((USI)(x))
/** Convert a USI datatype to SI */
#define USI2SI(x)   ((SI)(x))
/** Convert a SI datatype to USItype */
#define SI2USItype(x)   ((USItype)(x))
/** Convert a USI datatype to USItype */
#define USI2USItype(x)   ((USItype)(x))
/** Convert a USItype datatype to SI */
#define USItype2SI(x)   ((SI)(x))
/** Convert a USItype datatype to USI */
#define USItype2USI(x)   ((USI)(x))
/** Convert a SI datatype to SItype */
#define SI2SItype(x)   ((SItype)(x))
/** Convert a USI datatype to USItype */
#define USI2SItype(x)   ((SItype)(x))
/** Convert a SItype datatype to SI */
#define SItype2SI(x)   ((SI)(x))
/** Convert a SItype datatype to USI */
#define SItype2USI(x)   ((USI)(x))
/** Convert a USItype datatype to SItype */
#define USItype2SItype(x)   ((SItype)(x))
/** Convert a SItype datatype to USItype */
#define SItype2USItype(x)   ((USItype)(x))
// Double Integer Convertions
/** Convert a DI datatype to UDI */
#define DI2UDI(x)   ((UDI)(x))
/** Convert a UDI datatype to DI */
#define UDI2DI(x)   ((DI)(x))
/** Convert a DI datatype to UDItype */
#define DI2UDItype(x)   ((UDItype)(x))
/** Convert a UDI datatype to UDItype */
#define UDI2UDItype(x)   ((UDItype)(x))
/** Convert a UDItype datatype to DI */
#define UDItype2DI(x)   ((DI)(x))
/** Convert a UDItype datatype to UDI */
#define UDItype2UDI(x)   ((UDI)(x))
/** Convert a DI datatype to DItype */
#define DI2DItype(x)   ((DItype)(x))
/** Convert a UDI datatype to UDItype */
#define UDI2DItype(x)   ((DItype)(x))
/** Convert a DItype datatype to DI */
#define DItype2DI(x)   ((DI)(x))
/** Convert a DItype datatype to UDI */
#define DItype2UDI(x)   ((UDI)(x))
/** Convert a UDItype datatype to DItype */
#define UDItype2DItype(x)   ((DItype)(x))
/** Convert a DItype datatype to UDItype */
#define DItype2UDItype(x)   ((UDItype)(x))
// Tetra Integer Convertions
#if SUPPORTS_INT128
/** Convert a TI datatype to UTI */
#   define TI2UTI(x)   ((UTI)(x))
/** Convert a UTI datatype to TI */
#   define UTI2TI(x)   ((TI)(x))
/** Convert a TI datatype to UTItype */
#   define TI2UTItype(x)   ((UTItype)(x))
/** Convert a UTI datatype to UTItype */
#   define UTI2UTItype(x)   ((UTItype)(x))
/** Convert a UTItype datatype to TI */
#   define UTItype2TI(x)   ((TI)(x))
/** Convert a UTItype datatype to UTI */
#   define UTItype2UTI(x)   ((UTI)(x))
/** Convert a TI datatype to TItype */
#   define TI2TItype(x)   ((TItype)(x))
/** Convert a UTI datatype to UTItype */
#   define UTI2TItype(x)   ((TItype)(x))
/** Convert a TItype datatype to TI */
#   define TItype2TI(x)   ((TI)(x))
/** Convert a TItype datatype to UTI */
#   define TItype2UTI(x)   ((UTI)(x))
/** Convert a UTItype datatype to TItype */
#   define UTItype2TItype(x)   ((TItype)(x))
/** Convert a TItype datatype to UTItype */
#   define TItype2UTItype(x)   ((UTItype)(x))
#endif
// Octa Integer Convertions
#if SUPPORTS_INT256
/** Convert a OI datatype to UOI */
#   define OI2UOI(x)   ((UOI)(x))
/** Convert a UOI datatype to OI */
#   define UOI2OI(x)   ((OI)(x))
/** Convert a OI datatype to UOItype */
#   define OI2UOItype(x)   ((UOItype)(x))
/** Convert a UOI datatype to UOItype */
#   define UOI2UOItype(x)   ((UOItype)(x))
/** Convert a UOItype datatype to OI */
#   define UOItype2OI(x)   ((OI)(x))
/** Convert a UOItype datatype to UOI */
#   define UOItype2UOI(x)   ((UOI)(x))
/** Convert a OI datatype to OItype */
#   define OI2OItype(x)   ((OItype)(x))
/** Convert a UOI datatype to UOItype */
#   define UOI2OItype(x)   ((OItype)(x))
/** Convert a OItype datatype to OI */
#   define OItype2OI(x)   ((OI)(x))
/** Convert a OItype datatype to UOI */
#   define OItype2UOI(x)   ((UOI)(x))
/** Convert a UOItype datatype to OItype */
#   define UOItype2OItype(x)   ((OItype)(x))
/** Convert a OItype datatype to UOItype */
#   define OItype2UOItype(x)   ((UOItype)(x))
#endif
// Hexadeca Integer Convertions
#if SUPPORTS_INT512
/** Convert a XI datatype to UXI */
#   define XI2UXI(x)   ((UXI)(x))
/** Convert a UXI datatype to XI */
#   define UXI2XI(x)   ((XI)(x))
/** Convert a XI datatype to UXItype */
#   define XI2UXItype(x)   ((UXItype)(x))
/** Convert a UXI datatype to UXItype */
#   define UXI2UXItype(x)   ((UXItype)(x))
/** Convert a UXItype datatype to XI */
#   define UXItype2XI(x)   ((XI)(x))
/** Convert a UXItype datatype to UXI */
#   define UXItype2UXI(x)   ((UXI)(x))
/** Convert a XI datatype to XItype */
#   define XI2XItype(x)   ((XItype)(x))
/** Convert a UXI datatype to UXItype */
#   define UXI2XItype(x)   ((XItype)(x))
/** Convert a XItype datatype to XI */
#   define XItype2XI(x)   ((XI)(x))
/** Convert a XItype datatype to UXI */
#   define XItype2UXI(x)   ((UXI)(x))
/** Convert a UXItype datatype to XItype */
#   define UXItype2XItype(x)   ((XItype)(x))
/** Convert a XItype datatype to UXItype */
#   define XItype2UXItype(x)   ((UXItype)(x))
#endif
// Word Convertions
/** Convert a Wtype datatype to UWtype */
#define Wtype2UWtype(x)   ((UWtype)(x))
/** Convert a UWtype datatype to Wtype */
#define UWtype2Wtype(x)   ((Wtype)(x))
// Float-Point Convertions
/** Convert a SF datatype to SFtype */
#define SF2SFtype(x)   ((SFtype)(x))
/** Convert a SFtype datatype to SF */
#define SFtype2SF(x)   ((SF)(x))
/** Convert a DF datatype to DFtype */
#define DF2DFtype(x)   ((DFtype)(x))
/** Convert a DFtype datatype to DF */
#define DFtype2DF(x)   ((DF)(x))
// Fract & Accum Convertions
#if SUPPORTS_STDFIX
#   if ((HAVE_QQ == 1) && (HAVE_UQQ == 1))
/** Convert a QQ datatype to UQQ */
#      define QQ2UQQ(x)   ((UQQtype)(x))
/** Convert a UQQ datatype to QQ */
#      define UQQ2QQ(x)   ((QQtype)(x))
#   endif
#   if ((HAVE_HQ == 1) && (HAVE_UHQ == 1))
/** Convert a HQ datatype to UHQ */
#      define HQ2UHQ(x)   ((UHQtype)(x))
/** Convert a UHQ datatype to HQ */
#      define UHQ2HQ(x)   ((HQtype)(x))
#   endif
#   if ((HAVE_HA == 1) && (HAVE_UHA == 1))
/** Convert a HA datatype to UHA */
#      define HA2UHA(x)   ((UHAtype)(x))
/** Convert a UHA datatype to HA */
#      define UHA2HA(x)   ((HAtype)(x))
#   endif
#   if ((HAVE_SQ == 1) && (HAVE_USQ == 1))
/** Convert a SQ datatype to USQ */
#      define SQ2USQ(x)   ((USQtype)(x))
/** Convert a USQ datatype to SQ */
#      define USQ2SQ(x)   ((SQtype)(x))
#   endif
#   if ((HAVE_SA == 1) && (HAVE_USA == 1))
/** Convert a SA datatype to USA */
#      define SA2USA(x)   ((USAtype)(x))
/** Convert a USA datatype to SA */
#      define USA2SA(x)   ((SAtype)(x))
#   endif
#   if ((HAVE_DQ == 1) && (HAVE_UDQ == 1))
/** Convert a DQ datatype to UDQ */
#      define DQ2UDQ(x)   ((UDQtype)(x))
/** Convert a UDQ datatype to DQ */
#      define UDQ2DQ(x)   ((DQtype)(x))
#   endif
#   if ((HAVE_DA == 1) && (HAVE_UDA == 1))
/** Convert a DA datatype to UDA */
#      define DA2UDA(x)   ((UDAtype)(x))
/** Convert a UDA datatype to DA */
#      define UDA2DA(x)   ((DAtype)(x))
#   endif
#   if ((HAVE_TQ == 1) && (HAVE_UTQ == 1))
/** Convert a TQ datatype to UTQ */
#      define TQ2UTQ(x)   ((UTQtype)(x))
/** Convert a UTQ datatype to TQ */
#      define UTQ2TQ(x)   ((TQtype)(x))
#   endif
#   if ((HAVE_TA == 1) && (HAVE_UTA == 1))
/** Convert a TA datatype to UTA */
#      define TA2UTA(x)   ((UTAtype)(x))
/** Convert a UTA datatype to TA */
#      define UTA2TA(x)   ((TAtype)(x))
#   endif
#endif
// Miscellaneous Datatype Mode Macros
/** Cover macro to create a 64-bit integer */
#define MAKEDI(hi, lo)   ((((DI)(SI)(hi)) << 32) | ((UDI)(USI)(lo)))
#define __BITS4   (W_TYPE_SIZE / 4)
#define __ll_B   ((UWtype)1 << (W_TYPE_SIZE / 2))
#define __ll_lowpart(t)   ((UWtype)(t) & (__ll_B - 1))
#define __ll_highpart(t)   ((UWtype)(t) >> (W_TYPE_SIZE / 2))


// HAIKU & BEOS DATATYPES

#define haiku_std_int8   int8_t
#define haiku_std_uint8   uint8_t
#define haiku_std_int16   int16_t
#define haiku_std_uint16   uint16_t
#define __haiku_std_int8   haiku_std_int8
#define __haiku_std_uint8   haiku_std_uint8
#define __haiku_std_int16   haiku_std_int16
#define __haiku_std_uint16   haiku_std_uint16
#define __haiku_int8   haiku_std_int8
#define __haiku_uint8   haiku_std_uint8
#define __haiku_int16   haiku_std_int16
#define __haiku_uint16   haiku_std_uint16
#define haiku_int8   haiku_std_int8
#define haiku_uint8   haiku_std_uint8
#define haiku_int16   haiku_std_int16
#define haiku_uint16   haiku_std_uint16
#define haiku_std_int32   int32_t
#define haiku_std_uint32   uint32_t
#define haiku_std_int64   int64_t
#define haiku_std_uint64   uint64_t
#define __haiku_std_int32   haiku_std_int32
#define __haiku_std_uint32   haiku_std_uint32
#define __haiku_std_int64   haiku_std_int64
#define __haiku_std_uint64   haiku_std_uint64
#define __haiku_int32   haiku_std_int32
#define __haiku_uint32   haiku_std_uint32
#define __haiku_int64   haiku_std_int64
#define __haiku_uint64   haiku_std_uint64
#define haiku_int32   haiku_std_int32
#define haiku_uint32   haiku_std_uint32
#define haiku_int64   haiku_std_int64
#define haiku_uint64   haiku_std_uint64


// WORD DATATYPES

#ifdef OSWINDOWS
/** A datatype that has the length of the system's wordsize */
typedef uint16_t   WORD;
/** A datatype that is twice the length of the system's wordsize */
typedef uint32_t   DWORD;
/** A datatype that is four-times the length of the system's wordsize */
typedef uint64_t   QWORD;
#   define HAVE_QWORD   (1)
#elif IS_WORDSIZE_32
/** A datatype that has the length of the system's wordsize */
typedef uint32_t   WORD;
/** A datatype that is twice the length of the system's wordsize */
typedef uint64_t   DWORD;
#   if SUPPORTS_INT128
/** A datatype that is four-times the length of the system's wordsize */
typedef uint128_t   QWORD;
#      define HAVE_QWORD   (1)
#   endif
#elif IS_WORDSIZE_64
/** A datatype that has the length of the system's wordsize */
typedef uint64_t   WORD;
#   if SUPPORTS_INT128
/** A datatype that is twice the length of the system's wordsize */
typedef uint128_t   DWORD;
#   endif
#   if SUPPORTS_INT256
/** A datatype that is four-times the length of the system's wordsize */
typedef uint256_t   QWORD;
#      define HAVE_QWORD   (1)
#   endif
#endif
typedef int   HFILE;
/** A datatype that has the length of the system's wordsize */
#define ATOM   Word
/** A datatype that has the length of the system's wordsize */
#define Word   WORD
/** A datatype that is twice the length of the system's wordsize */
#define dword   DWORD
/** A datatype that is twice the length of the system's wordsize */
#define DWord   DWORD
/** A datatype that is twice the length of the system's wordsize */
#define Dword   DWORD
#if (defined(HAVE_QWORD) && HAVE_QWORD)
#   define qword   QWORD
#   define QWord   QWORD
#   define Qword   QWORD
#endif
typedef DWORD   COLORREF;
typedef DWORD*   LPCOLORREF;


// END-OF-FILE DATATYPES

/** End-Of-File */
#define EOF   (-1)


// SIGNED & UNSIGNED CHAR

#define CHAR_T   char
#define __CHAR_T   char
#define CHAR   char
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


// CHAR16_T

#ifdef __CHAR16_TYPE__
typedef __CHAR16_TYPE__   char16_t;
#else
typedef unsigned short   char16_t;
#   define __CHAR16_TYPE__   char16_t
#endif
#ifndef CHAR16_TYPE
#   define CHAR16_TYPE   __CHAR16_TYPE__
#endif
#ifndef __char16_t
#   define __char16_t   __CHAR16_TYPE__
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


// CHAR32_T

#ifdef __CHAR32_TYPE__
typedef __CHAR32_TYPE__   char32_t;
#else
typedef unsigned int   char32_t;
#   define __CHAR32_TYPE__   char32_t
#endif
#ifndef CHAR32_TYPE
#   define CHAR32_TYPE   __CHAR32_TYPE__
#endif
#ifndef __char32_t
#   define __char32_t   __CHAR32_TYPE__
#endif
typedef signed int   schar32_t;
typedef unsigned int   uchar32_t;
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


// WIDE-CHARACTER DATATYPES

#if (!(defined(__DEFINED_mbstate_t) || defined(_MBSTATE_T)))  // mbstate_t
/** Type that holds the information necessary to maintain the state when converting between sequences of multibyte characters and wide characters */
typedef struct __mbstate_t { unsigned int __opaque1, __opaque2; }   mbstate_t;
#   define _mbstate_t   mbstate_t
#   define _MBSTATE_T   mbstate_t
#   define __DEFINED_mbstate_t
#endif  // mbstate_t
#ifndef darwin_mbstate_t
#   define darwin_mbstate_t   mbstate_t
#endif
#ifndef __darwin_mbstate_t
#   define __darwin_mbstate_t   mbstate_t
#endif
#if (IS_NOT_CPLUSPLUS && !defined(__DEFINED_wchar_t))
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
#define WCHAR   wchar_t
#define __gwchar_t   gwchar_t
#define darwin_wchar_t   wchar_t
#define __darwin_wchar_t   wchar_t
#ifndef __DEFINED_wint_t  // wint_t
#   ifdef __WINT_TYPE__
typedef __WINT_TYPE__   wint_t;
#   else
typedef unsigned int   wint_t;
#      define __WINT_TYPE__   wint_t
#   endif
#   define __DEFINED_wint_t   (1)
#endif  // wint_t
#define WINT   wint_t
#define darwin_wint_t   wint_t
#define __darwin_wint_t   wint_t
#ifndef WEOF
/** Constant expression of type `wint_t` whose value does not correspond to any member of the extended character set; End-Of-File */
#   define WEOF   ((wint_t)0xffffffffU)
#endif
#define weof   WEOF
#define WIDE_EOF   WEOF
#define DARWIN_WEOF   WEOF
#define __DARWIN_WEOF   WEOF
#ifndef _WCTRANS_T  // wctype
/** Scalar type that can hold values which represent locale-specific character mappings */
typedef const int32_t*   wctrans_t;
#   define _WCTRANS_T   wctrans_t
#endif
#define darwin_wctrans_t   wctrans_t
#define __darwin_wctrans_t   wctrans_t
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
#define darwin_wctype_t   wctype_t
#define __darwin_wctype_t   wctype_t


// T-CHARACTER DATATYPES (<tchar.h>)

#if (!(defined(TCHAR_DEFINED) || defined(__TCHAR_DEFINED)))
#   define TCHAR_DEFINED   (1)
#   define __TCHAR_DEFINED   (1)

#   ifdef _UNICODE
typedef wchar_t   TCHAR;
typedef wchar_t   TSCHAR;
typedef wchar_t   TUCHAR;
typedef wchar_t   TXCHAR;
typedef wint_t   TINT;
typedef wchar_t*   PTCHAR;
typedef wchar_t   TBYTE, *PTBYTE;
#      define TEOF   WEOF
#      define _TEOF   WEOF
#      define TEXT(s)   L##s
#   else
typedef char   TCHAR;
typedef char   TSCHAR;
typedef char   TUCHAR;
typedef char   TXCHAR;
typedef int32_t   TINT;
typedef char*   PTCHAR;
typedef char   TBYTE, *PTBYTE;
#      define TEOF   EOF
#      define _TEOF   EOF
#      define TEXT(s)   s
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


// MISCELLANEOUS CHARACTER DATATYPES

/** ANSI character */
typedef char   ANSICHAR;
/** ANSI character */
typedef unsigned char   ANSIUCHAR;
/** Unicode character */
typedef wchar_t   UNICHAR;


// RUNE DATATYPES

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
typedef __WCHAR_TYPE__   rune_t;
#define __rune_t   rune_t
#define darwin_rune_t   rune_t
#define __darwin_rune_t   rune_t
#define _BSD_RUNE_T_   rune_t
#define RUNE   rune_t
#define Rune   rune_t
/** Maximum bytes per rune */
#define UTFmax   (3)  // 4
/** Cannot represent part of a UTF sequence (<) */
#define Runesync   0x80
/** Rune and UTF sequences are the same (<) */
#define Runeself   0x80
/** Decoding error in UTF */
#define Runeerror   0xFFFD
#define xRuneerror   Runeerror
/** 16-bit rune */
#define Runemax   0xFFFF
/** 21-bit rune */
#define Rune21max   0x10FFFF
/** Bits used by runes */
#define Runemask   0x1FFFFF
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
#define CRMASK   (0xFFFFFF00)  // (~((_CACHED_RUNES) - 1))
#define _CRMASK   (0xFFFFFF00)  // (~((_CACHED_RUNES) - 1))
#define _RUNE_ISCACHED(c)   ((c) >= 0 && ((c) < _CACHED_RUNES))
#define RUNE_ISCACHED(c)   _RUNE_ISCACHED((c))
#define _DEFAULT_INVALID_RUNE   ((rune_t)-3)
#define USE_FPdbleword   (1)
#define SurrogateMin   0xD800
#define SurrogateMax   0xDFFF
#define Bad   Runeerror
#define Bit(i)   (7 - (i))
#define Bitx   (6)
#define Maskx   (0x3f)
#define Testx   (Maskx ^ 0xFF)
/** N 0's preceded by i 1's; T(Bit(2)) is 11000000 */
#define T(i)   (((1 << (Bit(i) + 1)) - 1) ^ 0xFF)
#define Tx   (((1 << (Bit(1) + 1)) - 1) ^ 0xFF)
#define Rune1   ((1 << (Bit(0))) - 1)
#define RuneX(i)   ((1 << (Bit(i) + ((i) - 1) * Bitx)) - 1)
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
	int32_t fre_min;  // First rune of the range
	int32_t fre_max;  // Last rune (inclusive) of the range
	int32_t fre_map;  // What first maps to in maps
} _FileRuneEntry;
/** Number of ranges stored */
typedef struct _FileRuneRange { uint32_t frr_nranges; }   _FileRuneRange;
/** The lower 8 bits of runetype[] contain the digit value of the rune */
typedef struct attr_packed _RuneEntry {
	rune_t min;  // First rune of the range
	rune_t max;  // Last rune (inclusive) of the range
	rune_t map;  // What first maps to in maps
	unsigned long* types;  // Array of types in range
} _RuneEntry;
/** The lower 8 bits of runetype[] contain the digit value of the rune */
typedef struct attr_packed __RuneEntry_struct {
	rune_t __min;  // First rune of the range
	rune_t __max;  // Last rune (inclusive) of the range
	rune_t __map;  // What first maps to in maps
	uint32_t* __types;  // Array of types in range
} __RuneEntry;
typedef struct attr_packed _RuneRange {
	int nranges;  // Number of ranges stored
	_RuneEntry* ranges;  // Pointer to the ranges
} _RuneRange;
typedef struct attr_packed __RuneRange_struct {
	int __nranges;  // Number of ranges stored
	_RuneEntry* __ranges;  // Pointer to the ranges
} __RuneRange;
typedef struct attr_packed _RuneCharClass {
	char __name[14];  // CHARCLASS_NAME_MAX = 14
	uint32_t __mask;  // charclass mask
} _RuneCharClass;
typedef struct _WCTransEntry {
	char* te_name;
	rune_t* te_cached;
	_RuneRange* te_extmap;
} _WCTransEntry;
typedef struct attr_packed _WCTypeEntry {
	char* te_name;
	_RuneType te_mask;
} _WCTypeEntry;
struct attr_packed old_tabs {
	char ctype_tab[257];
	short tolower_tab[257];
	short toupper_tab[257];
};
typedef struct Fconv {
	char* out;  // Pointer to next output
	char* eout;  // pointer to end
	int f1, f2, f3, chr;
} Fconv;


// RUNE TABLES

#include "rune_tables.h"


// MISCELLANEOUS CHARACTER DATATYPES

/** Wide character (as UCS-4) according to ISO-10646-1 */
typedef unsigned int   ucs4_t;
/** State used by a conversion; 0 denotes the initial state */
typedef unsigned int   state_t;


// OTHER EXACT-WIDTH & FIXED-WIDTH INTEGRALS

#define __SWBLK_T_TYPE   long
#define __SLONGWORD_TYPE   long
#define __SLONGWORD_T_TYPE   long
#define __ULONGWORD_TYPE   unsigned long
#define __ULONGWORD_T_TYPE   unsigned long
#if IS_WORDSIZE_32
#   define __SWORD_TYPE   int
#   define __UWORD_TYPE   unsigned int
#   define __INT_PTR_TYPE   signed int
#   define __UINT_PTR_TYPE   unsigned int
#   define __SLONG32_TYPE   long
#   define __ULONG32_TYPE   unsigned long
#   define gawble   uint32_t
#else  // WORDSIZE == 64
#   define __SWORD_TYPE   long
#   define __UWORD_TYPE   unsigned long
#   define __INT_PTR_TYPE   signed long
#   define __UINT_PTR_TYPE   unsigned long
#   define __SLONG32_TYPE   int
#   define __ULONG32_TYPE   unsigned
#   define gawble   uint64_t
#endif
#define _Addr   __UWORD_TYPE
#define _Int64   __UWORD_TYPE
#define _Reg   __UWORD_TYPE
#define SHORT   short
/** Signed short */
#define sshort_t   signed short
#define INT   int
#define DWORD32   int
#ifndef _HRESULT_DEFINED
typedef long   HRESULT;
#   define _HRESULT_DEFINED   (1)
#endif
#define LONG32   __SLONG32_TYPE
/** Signed integer */
#define sint_t   signed int
#define LONG   long
/** Signed long */
#define slong_t   signed long
#define LONGLONG   long long
#define LONG64   long long
#define _Longlong   signed long long
/** Signed long long */
#define slonglong_t   signed long long
/** Datatype used in Sun-derived XDR routines */
#define longlong_t   signed long long
/** Unsigned short */
#define ushort_t   unsigned short
#define USHORT   unsigned short
/** Sys V compatibility */
#define unshort   USHORT
#define u_short   USHORT
#define __u_short   USHORT
#define _utfushort   USHORT
#define utfushort   USHORT
/** Sys V compatibility */
#define ushort   USHORT
#define p9ushort   USHORT
/** Unsigned integer */
#define uint_t   unsigned int
/** Alias for "unsigned int" */
#define UINT   unsigned int
/** Alias for "unsigned int" */
#define UInt   UINT
/** Alias for "unsigned int" */
#define p9uint   UINT
#define _utfuint   UINT
#define utfuint   UINT
/** Alias for "unsigned int" */
#define u_int   UINT
/** Alias for "unsigned int" */
#define __u_int   UINT
/** Sys V compatibility */
#define uint   UINT
/** Unsigned long */
#define ulong_t   unsigned long
#define ULONG   unsigned long
#define p9ulong   ULONG
#define ULong   ULONG
#define u_long   ULONG
#define __u_long   ULONG
/** Sys V compatibility */
#define ulong   ULONG
/** Sys V compatibility */
#define unlong   ULONG
#define _utfulong   ULONG
#define utfulong   ULONG
/** Unsigned long long */
#define ulonglong_t   unsigned long long
#define ULONGLONG   unsigned long long
#define ULONG64   unsigned long long
#define _ULonglong   unsigned long long
/** Datatype used in Sun-derived XDR routines */
#define u_longlong_t   unsigned long long
typedef uint64_t   DWORD64;
#define DWORDLONG   DWORD64
/** Signed 8-bit quantity */
typedef signed char   bit8_t;
/** Signed 8-bit quantity */
#define s_bit8_t   bit8_t
/** Signed 8-bit quantity */
#define sbit8_t   bit8_t
/** Unsigned 8-bit quantity */
typedef uint8_t   Byte;
/** Unsigned 8-bit quantity */
typedef unsigned char   ubit8_t;
/** Unsigned 8-bit quantity */
#define u_bit8_t   ubit8_t
#define sbits8   signed char
#define bits8   unsigned char
#define ubits8   unsigned char
/** Signed 16-bit quantity */
typedef signed short   bit16_t;
/** Signed 16-bit quantity */
#define s_bit16_t   bit16_t
/** Signed 16-bit quantity */
#define sbit16_t   bit16_t
/** Unsigned 16-bit quantity */
typedef unsigned short   ubit16_t;
/** Unsigned 16-bit quantity */
#define u_bit16_t   ubit16_t
#define sbits16   signed short
#define bits16   unsigned short
#define ubits16   unsigned short
/** Signed 32-bit quantity */
typedef signed int   bit32_t;
/** Signed 32-bit quantity */
#define sbit32_t   bit32_t
/** Signed 32-bit quantity */
#define s_bit32_t   bit32_t
/** Unsigned 32-bit quantity */
typedef unsigned int   u_bit32_t;
/** Unsigned 32-bit quantity */
#define ubit32_t   u_bit32_t
#define sbits32   signed int
#define bits32   unsigned int
#define ubits32   unsigned int
/** Signed 64-bit quantity */
typedef int64_t   bit64_t;
/** Signed 64-bit quantity */
#define s_bit64_t   bit64_t
/** Signed 64-bit quantity */
#define sbit64_t   bit64_t
/** Unsigned 64-bit quantity */
typedef uint64_t   ubit64_t;
/** Unsigned 64-bit quantity */
#define u_bit64_t   ubit64_t
#define sbits64   int64_t
#define bits64   uint64_t
#define ubits64   uint64_t
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
#define __KEY_T_TYPE   __S32_TYPE
/** Type of an IPC key */
typedef __KEY_T_TYPE   key_t;
/** Type of an IPC key */
#define __key_t   key_t
#define MACH_MSG_TYPE_CHAR   char
#define MACH_MSG_TYPE_INTEGER_8   unsigned char
#define MACH_MSG_TYPE_INTEGER_16   unsigned short
#define MACH_MSG_TYPE_INTEGER_32   unsigned int
#define MACH_MSG_TYPE_INTEGER_T   MACH_MSG_TYPE_INTEGER_32
#define MACH_MSG_TYPE_INTEGER_64   uint64_t
#define kern_return_t   int
#ifndef __SYSCALL_SLONG_TYPE
#   define __SYSCALL_SLONG_TYPE   __SLONGWORD_TYPE
#endif
/** Signed long type used in system calls */
typedef __SYSCALL_SLONG_TYPE   syscall_slong_t;
#define __syscall_slong_t   syscall_slong_t
#ifndef __SYSCALL_ULONG_TYPE
#   define __SYSCALL_ULONG_TYPE   __ULONGWORD_TYPE
#endif
/** Unsigned long type used in system calls */
typedef __SYSCALL_ULONG_TYPE   __syscall_ulong_t;
#define __syscall_ulong_t   syscall_ulong_t
/** This type is used by some structs in <bits/stropts.h> */
typedef __SLONGWORD_TYPE   t_scalar_t;
/** This type is used by some structs in <bits/stropts.h> */
#define __t_scalar_t   t_scalar_t
/** This type is used by some structs in <bits/stropts.h> */
typedef __ULONGWORD_TYPE   t_uscalar_t;
/** This type is used by some structs in <bits/stropts.h> */
#define __t_uscalar_t   t_uscalar_t
/** Fixed point number datatype */
typedef uint32_t   fixpt_t;
/** Fixed point number datatype */
#define __fixpt_t   fixpt_t
typedef void   DB_ENV;
typedef int   rlimit_resource_t;
#define __rlimit_resource_t   rlimit_resource_t
typedef uint32_t   pgno_t;
/** Segment size */
typedef int32_t   segsz_t;
/** Swap offset */
typedef int32_t   swblk_t;
typedef uint16_t   indx_t;
typedef uint32_t   recno_t;
typedef uint32_t   db_recno_t;
#ifndef __DEFINED_cnd_t
/** Used for condition variables */
typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; }   cnd_t;
#   define __DEFINED_cnd_t   (1)
#endif


// SOCKET DATATYPES

#ifndef __DEFINED_sa_family_t
typedef unsigned short   sa_family_t;
#   define __DEFINED_sa_family_t   (1)
#endif
#ifndef __DEFINED_socklen_t
typedef __U32_TYPE   socklen_t;  // Duplicate from <sys/socket.h>
#   define __socklen_t   socklen_t
#   define __DEFINED_socklen_t   (1)
#endif
#define ISC_SOCKLEN_T   socklen_t
#define _Socklen   socklen_t


// DEVICE DATATYPES

/** PCI register datatype */
typedef uint32_t   pcireg_t;
/** Size definition for CPU sets */
#define __CPU_SETSIZE   1024
#define __NCPUBITS   (8 * SIZEOF_LONG)
/** Type for array elements in `cpu_set_t` */
typedef unsigned long   cpu_mask_t;
#define __cpu_mask   cpu_mask_t
#define SIZEOF_CPU_MASK_T   SIZEOF_LONG
#define SIZEOF_CPU_MASK   SIZEOF_LONG
/** Data structure to describe CPU mask */
typedef struct cpu_set { cpu_mask_t __bits[__CPU_SETSIZE / __NCPUBITS]; }   cpu_set_t;
#define __cpu_set_t_defined
#define __DEV_T_TYPE   __UQUAD_TYPE
#ifndef __dev_t_defined
/** Type of device numbers */
typedef __DEV_T_TYPE   dev_t;
/** Type of device numbers */
#   define __dev_t   dev_t
#   define __dev_t_defined   (1)
#endif
typedef int   reg_class_t;
#ifndef __DEFINED_register_t
typedef _Reg __attribute__((__mode__(__word__)))   register_t;
#   define __register_t   register_t
#   define __uregister_t   register_t
#   define uregister_t   register_t
#   define __memword_t   register_t
#   define memword_t   register_t
#   define __DEFINED_register_t   (1)
#endif
typedef int   register32_t;
typedef int64_t   register64_t;
#ifndef __DEFINED_regoff_t
typedef _Addr   regoff_t;
#   define __regoff_t   regoff_t
#   define __DEFINED_regoff_t   (1)
#endif
typedef unsigned long   irq_hw_number_t;


// ID DATATYPES

#define __GID_T_TYPE   __U32_TYPE
#ifndef __gid_t_defined
/** Datatype for group identifications */
typedef __GID_T_TYPE   gid_t;
/** Datatype for group identifications */
#   define __gid_t   gid_t
#   define __gid_t_defined   (1)
#endif
/** Datatype for group identifications */
#define fssh_gid_t   gid_t
#define __UID_T_TYPE   __U32_TYPE
#ifndef __uid_t_defined
/** Datatype for user identifications */
typedef __UID_T_TYPE   uid_t;
/** Datatype for user identifications */
#   define __uid_t   uid_t
#   define __uid_t_defined   (1)
#endif
/** Datatype for user identifications */
#define fssh_uid_t   uid_t
/** ID array datatype (commonly used in Hurd) */
typedef uid_t*   idarray_t;
#define __PID_T_TYPE   __S32_TYPE
/** Datatype for process identifications */
typedef __PID_T_TYPE   pid_t;
/** Datatype for process identifications */
#define __pid_t   pid_t
/** Datatype for process identifications */
#define fssh_pid_t   pid_t
/** PID array datatype (commonly used in Hurd) */
typedef pid_t*   pidarray_t;
#define __ID_T_TYPE   __U32_TYPE
/** General type for IDs */
typedef __ID_T_TYPE   id_t;
/** General type for IDs */
#define __id_t   id_t
/** Filesystem ID Datatype */
#define __FSID_T_TYPE   struct fsid { int32_t __val[2]; }
/** Filesystem ID Datatype */
typedef __FSID_T_TYPE   fsid_t;
/** Filesystem ID Datatype */
#define __fsid_t   fsid_t
/** Grant ID Datatype */
typedef int32_t   cp_grant_id_t;
/** Grant ID Datatype */
#define __cp_grant_id_t   cp_grant_id_t
/** ID datatype */
typedef enum idtype { P_ALL = 0, P_PID = 1, P_PGID = 2 }   idtype_t;
/** LWP ID datatype */
typedef int32_t   lwpid_t;
typedef unsigned long   cpuid_t;
typedef int   psetid_t;
typedef unsigned long   cnodemask_t;
typedef signed short   nasid_t;
typedef signed short   cnodeid_t;
typedef signed char   partid_t;
typedef signed short   moduleid_t;
typedef signed short   cmoduleid_t;
typedef unsigned char   clusterid_t;
typedef unsigned long   pfn_t;
typedef dev_t   vertex_hdl_t;


// ADDRESS-RELATED DATATYPES

/** Core Address Datatype */
typedef char*   caddr_t;
/** Core Address Datatype */
#define __caddr_t   caddr_t
typedef quad_t*   qaddr_t;
#define __qaddr_t   qaddr_t
typedef signed long   haiku_saddr_t;
#define __haiku_saddr_t   haiku_saddr_t
typedef unsigned long   haiku_addr_t;
#define __haiku_addr_t   haiku_addr_t
#ifdef ENV64BIT
typedef int64_t   haiku_phys_saddr_t;
typedef uint64_t   haiku_phys_addr_t;
typedef uint64_t   fssh_addr_t;
typedef uint64_t   fssh_phys_addr_t;
typedef uint64_t   fssh_generic_addr_t;
#else
typedef int32_t   haiku_phys_saddr_t;
typedef uint32_t   haiku_phys_addr_t;
typedef uint32_t   fssh_addr_t;
typedef uint32_t   fssh_phys_addr_t;
typedef uint32_t   fssh_generic_addr_t;
#endif
#define __haiku_phys_saddr_t   haiku_phys_saddr_t
#define __haiku_phys_addr_t   haiku_phys_addr_t
#define __DADDR_T_TYPE   __S32_TYPE
#ifndef __daddr_t_defined
/** Datatype of a disk address */
typedef __DADDR_T_TYPE   daddr_t;
/** Datatype of a disk address */
#   define __daddr_t   daddr_t
#   define __daddr_t_defined   (1)
#endif


// SIZE-RELATED DATATYPES

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
typedef __SIZE_T_TYPE__   size_t;
#define __size_t   size_t
#define _IO_size_t   size_t
#define usize   size_t
#define __usize   size_t
#define usize_t   size_t
#define __usize_t   size_t
/** Windows datatype */
#define SIZE_T   size_t
/** Darwin size_t datatype */
#define __darwin_size_t   size_t
/** Darwin size_t datatype */
#define darwin_size_t   size_t
#define _BSD_SIZE_T_   size_t
typedef size_t    kxld_addr_t;
typedef size_t    kxld_size_t;
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
/** Type of a byte count, or error */
typedef __SSIZE_T_TYPE   ssize_t;
/** Type of a byte count, or error */
#define __ssize_t   ssize_t
/** Windows datatype */
#define SSIZE_T   ssize_t
/** Darwin ssize_t datatype (byte count or error) */
#define __darwin_ssize_t   ssize_t
/** Darwin ssize_t datatype (byte count or error) */
#define darwin_ssize_t   ssize_t
#define _BSD_SSIZE_T_   ssize_t
#ifdef M68K
#   define _READ_WRITE_RETURN_TYPE   ssize_t
#endif
/** Memory region datatype */
typedef size_t   info_t;
/** Restricted size_t; ISO9899:2011 7.20 (C11 Annex K) */
typedef size_t   rsize_t;
/** Restricted size_t; ISO9899:2011 7.20 (C11 Annex K) */
#define __rsize_t   rsize_t
#ifdef ENV64BIT
typedef uint64_t   fssh_size_t;
typedef int64_t   fssh_ssize_t;
#else
typedef uint32_t   fssh_size_t;
typedef int32_t   fssh_ssize_t;
#endif
typedef fssh_phys_addr_t   fssh_phys_size_t;
typedef fssh_generic_addr_t   fssh_generic_size_t;


// FILESYSTEM-RELATED DATATYPES

/** File-descriptor mask datatype (commonly used in Hurd) */
typedef int*   fd_mask_t;
typedef long   __fd_mask;
#define __MODE_T_TYPE   __U32_TYPE
#ifndef __mode_t_defined
/** Type of file attribute bitmasks */
typedef __MODE_T_TYPE   mode_t;
/** Type of file attribute bitmasks */
#   define __mode_t   mode_t
/** Type of file attribute bitmasks */
#   define fssh_mode_t   mode_t
#   define __mode_t_defined   (1)
#endif
#define __NLINK_T_TYPE   __UWORD_TYPE
#ifndef __nlink_t_defined
/** Type of file link counts */
typedef __NLINK_T_TYPE   nlink_t;
/** Type of file link counts */
#   define __nlink_t   nlink_t
/** Type of file link counts */
#   define fssh_nlink_t   nlink_t
#   define __nlink_t_defined   (1)
#endif
#define __INO_T_TYPE   __ULONGWORD_TYPE
#define __INO64_T_TYPE   __UQUAD_TYPE
#ifndef __ino_t_defined
/** Type of file serial numbers */
typedef __INO_T_TYPE   ino_t;
/** Type of file serial numbers (LFS) */
typedef __INO64_T_TYPE   ino64_t;
#   ifndef SUPPORTS_LARGEFILE64
/** Type of file serial numbers (LFS) */
#      define __ino_t   ino64_t
#   else
/** Type of file serial numbers (LFS) */
#      define __ino_t   ino_t
#   endif
/** Type of file serial numbers (LFS) */
#    define __ino64_t   ino64_t
#   define __ino_t_defined   (1)
#endif
#define fssh_ino_t   ino_t
#define __OFF_T_TYPE   __SLONGWORD_TYPE
#define __OFF64_T_TYPE   __SQUAD_TYPE
#ifndef __off_t_defined
#   if SUPPORTS_LARGEFILE64
/** Type of file sizes and offsets (LFS) */
typedef __OFF64_T_TYPE   off64_t;
/** Type of file sizes and offsets */
typedef __OFF64_T_TYPE   off_t;
#      define SIZEOF_OFF_T   8
#      define SIZEOF_OFF64_T   8
#   else
/** Type of file sizes and offsets (LFS) */
typedef __OFF64_T_TYPE   off64_t;
/** Type of file sizes and offsets */
typedef __OFF_T_TYPE   off_t;
#      define SIZEOF_OFF_T   SIZEOF_LONG
#      define SIZEOF_OFF64_T   8
#   endif
#   define __off_t_defined   (1)
/** Type of file sizes and offsets (LFS) */
#   define __off64_t   off64_t
/** Type of file sizes and offsets */
#   define __off_t   off_t
#endif  // __off_t_defined
/** Type of file sizes and offsets */
#define fssh_off_t   off_t
/** Stdio file position type */
typedef off_t   fpos_t;
/** Stdio file position type */
#define __fpos_t   fpos_t
/** The datatype of the second argument to `fgetpos` and `fsetpos` */
#define __STDIO_fpos_t   fpos_t
/** Stdio file position type */
typedef off64_t   fpos64_t;
/** Stdio file position type */
#define __fpos64_t   fpos64_t
/** The datatype of the second argument to `fgetpos` and `fsetpos` */
#define __STDIO_fpos64_t   fpos64_t
/** Type of file-sizes and offsets */
typedef __OFF64_T_TYPE   loff_t;
/** Type of file-sizes and offsets */
#define __loff_t   loff_t
/** Offset array datatype (commonly used in Hurd) */
typedef loff_t*   off_array_t;
#define __BLKSIZE_T_TYPE   __SLONGWORD_TYPE
#ifndef __blksize_t_defined
/** Type to represent block size */
typedef __BLKSIZE_T_TYPE   blksize_t;
/** Type to represent block size */
#   define __blksize_t   blksize_t
#   define __blksize_t_defined   (1)
#endif
#define __BLKCNT_T_TYPE   __SLONGWORD_TYPE
#define __BLKCNT64_T_TYPE   __SQUAD_TYPE
#ifndef __blkcnt_t_defined
/** Type to count number of disk blocks */
typedef __BLKCNT_T_TYPE   blkcnt_t;
#   define __blkcnt_t   blkcnt_t
/** Type to count number of disk blocks */
typedef __BLKCNT64_T_TYPE   blkcnt64_t;
#   define __blkcnt64_t   blkcnt64_t
#   define __blkcnt_t_defined   (1)
#endif
#define __FSBLKCNT_T_TYPE   __ULONGWORD_TYPE
#define __FSBLKCNT64_T_TYPE   __UQUAD_TYPE
#ifndef __fsblkcnt_t_defined
/** Type to count filesystem blocks */
typedef __FSBLKCNT_T_TYPE   fsblkcnt_t;
#   define __fsblkcnt_t   fsblkcnt_t
/** Type to count filesystem blocks */
typedef __FSBLKCNT64_T_TYPE   fsblkcnt64_t;
#   define __fsblkcnt64_t   fsblkcnt64_t
#   define __fsblkcnt_t_defined   (1)
#endif
#define __FSFILCNT_T_TYPE   __ULONGWORD_TYPE
/** Type to count filesystem nodes */
typedef __FSFILCNT_T_TYPE   fsfilcnt_t;
#define __fsfilcnt_t   fsfilcnt_t
#define __FSFILCNT64_T_TYPE   __UQUAD_TYPE
/** Type to count filesystem nodes */
typedef __FSFILCNT64_T_TYPE   fsfilcnt64_t;
#define __fsfilcnt64_t   fsfilcnt64_t
#define __FSWORD_T_TYPE   __SWORD_TYPE
/** Type of miscellaneous filesystem fields */
typedef __FSWORD_T_TYPE   fsword_t;
/** Type of miscellaneous filesystem fields */
#define __fsword_t   fsword_t
/** Resource limit datatype */
#define __RLIM_T_TYPE   unsigned long long
/** Resource limit datatype */
typedef __RLIM_T_TYPE   rlim_t;
/** Resource limit datatype */
#define __rlim_t   rlim_t
#define __RLIM64_T_TYPE   __RLIM_T_TYPE
/** Type for resource measurement (LFS) */
typedef __RLIM64_T_TYPE   rlim64_t;
/** Type for resource measurement (LFS) */
#define __rlim64_t   rlim64_t
typedef struct statfs {
	__SWORD_TYPE f_type, f_bsize;
#ifndef __USE_FILE_OFFSET64
	fsblkcnt_t f_blocks, f_bfree, f_bavail, f_files, f_ffree;
#else
	fsblkcnt64_t f_blocks, f_bfree, f_bavail, f_files, f_ffree;
#endif
	fsid_t f_fsid;
	__SWORD_TYPE f_namelen, f_frsize;
	__SWORD_TYPE f_spare[5];
} statfs_t;
#ifdef __USE_LARGEFILE64
typedef struct statfs64 {
	__SWORD_TYPE f_type, f_bsize;
	fsblkcnt64_t f_blocks, f_bfree, f_bavail, f_files, f_ffree;
	fsid_t f_fsid;
	__SWORD_TYPE f_namelen, f_frsize;
	__SWORD_TYPE f_spare[5];
} statfs64_t;
#endif
#ifndef __DEFINED_struct_iovec
/** The <sys/uio.h> header uses the iovec structure for scatter/gather I/O */
typedef struct iovec {
	const void* iov_base;  // Base address of a memory region for input or output
	size_t iov_len;  // The size of the memory pointed to by iov_base
} iovec_t;
#   define __DEFINED_struct_iovec   (1)
#   define HAVE_IOVEC   (1)
#endif


// MINIX-SPECIFIC FILESYSTEM-RELATED DATATYPES

#ifndef block_t
/** Block number datatype */
typedef uint32_t   block_t;
#endif
#ifndef zone_t
/** Zone number datatype */
typedef uint32_t   zone_t;
#endif
#ifndef bit_t
/** Datatype for bit numbers in bitmaps */
typedef uint32_t   bit_t;
#endif
#ifndef bitchunk_t
/** Datatype for collections of bits in bitmaps */
typedef uint32_t   bitchunk_t;
#endif
typedef struct fs_size {
	ino_t inocount;  // Amount of inodes
	zone_t zonecount;  // Amount of zones
	block_t blockcount;  // Amount of blocks
} fs_size_t;
/** Zone number datatype for V1 filesystems */
typedef uint16_t   zone1_t;


// TIME-RELATED DATATYPES

#define __CLOCK_T_TYPE   __SLONGWORD_TYPE
/** Type of CPU usage counts */
typedef __CLOCK_T_TYPE   clock_t;
/** Type of CPU usage counts */
#define __clock_t   clock_t
#define _BSD_CLOCK_T_   clock_t
#define __CLOCKID_T_TYPE   __S32_TYPE
/** Clock ID used in clock and timer functions */
typedef __CLOCKID_T_TYPE   clockid_t;
/** Clock ID used in clock and timer functions */
#define __clockid_t   clockid_t
#define _BSD_CLOCKID_T_   clockid_t
/** Datatype for clock cycles */
typedef unsigned long   cycles_t;
/** Clocksource cycle base type */
typedef uint64_t   cycle_t;
#define __TIME_T_TYPE   __SLONGWORD_TYPE
#ifndef __DEFINED_time_t
/** Seconds since the Epoch */
typedef __TIME_T_TYPE   time_t;
/** Seconds since the Epoch */
#   define __time_t   time_t
#   define __DEFINED_time_t   (1)
#endif
#define _BSD_TIME_T_   time_t
#define time_tz   time_t
#define tz_time_t   time_t
typedef uint64_t   time64_t;
#define __time64_t   time64_t
#define __TIMER_T_TYPE   void*
/** Timer ID returned by `timer_create` */
typedef __TIMER_T_TYPE   timer_t;
/** Timer ID returned by `timer_create` */
#define __timer_t   timer_t
#define _BSD_TIMER_T_   timer_t
#define __SUSECONDS_T_TYPE   __SLONGWORD_TYPE
#ifndef __DEFINED_suseconds_t
/** Signed count of microseconds */
typedef __SUSECONDS_T_TYPE   suseconds_t;
/** Signed count of microseconds */
#   define __suseconds_t   suseconds_t
#   define _BSD_SUSECONDS_T_   suseconds_t
#   define __DEFINED_suseconds_t   (1)
#endif
#define __USECONDS_T_TYPE   __U32_TYPE
#ifndef __DEFINED_useconds_t
/** Count of microseconds */
typedef __USECONDS_T_TYPE   useconds_t;
/** Count of microseconds */
#   define __useconds_t   useconds_t
#   define _BSD_USECONDS_T_   useconds_t
#   define __DEFINED_useconds_t   (1)
#endif
#if (!(defined(__DEFINED_struct_timespec) || defined(__timespec_defined)))
typedef struct timespec { time_t tv_sec; long tv_nsec; } timespec_t;
#   define __timespec   timespec
#   define __timespec_t   timespec_t
#   define __DEFINED_struct_timespec   (1)
#   define __timespec_defined   (1)
#endif
#ifndef __DEFINED_struct_timeval
typedef struct timeval { time_t tv_sec; suseconds_t tv_usec; }   timeval_t;
#   define __DEFINED_struct_timeval   (1)
#endif
typedef struct attr_packed tm {
	int tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year;
	int tm_wday;  // Day of week [0-6]
	int tm_yday;  // Day in year [0-366]
	int tm_isdst;  // DST
	long __tm_gmtoff;  // Seconds east of UTC
	const char* __tm_zone;  // Timezone abbreviation
} tm_t;
/** Structure representing a timezone */
typedef struct timezone_struct {
	int tz_minuteswest;  // Minutes west of GMT
	int tz_dsttime;  // Nonzero if DST is ever in effect
} timezone_t;
typedef struct timezone_struct* restrict   timezone_ptr_t;
#define __timezone_ptr_t   timezone_ptr_t
/** Type of the second argument to `getitimer` and the second and third arguments `setitimer` */
typedef struct itimerval {
	struct timeval it_interval;  // Value to put into `it_value` when the timer expires
	struct timeval it_value;  // Time to the next timer expiration
} itimerval_t;
#ifdef ALPHA
/** Datatype for variables used to store the time values */
typedef unsigned int   hp_timing_t;
#elif (defined(X86_64) || defined(I386) || defined(I686) || defined(X86))
typedef unsigned long long   hp_timing_t;
#elif (defined(ITANIUM) || defined(SPARC64))
typedef unsigned long   hp_timing_t;
#elif (defined(POWERPC64) || defined(POWERPC) || defined(SPARC))
typedef unsigned long long   hp_timing_t;
#else
typedef unsigned int   hp_timing_t;
#endif


// MACH TIME-RELATED DATATYPES

/** Alarm time datatype */
typedef int   alarm_type_t;
/** Sleep time datatype */
typedef int   sleep_type_t;
/** Clock identification datatype */
typedef int   clock_id_t;
/** Clock flavor datatype */
typedef int   clock_flavor_t;
/** Clock attribute datatype */
typedef int*   clock_attr_t;
/** Clock resolution datatype */
typedef int   clock_res_t;
/** Normal time specification used by the kernel clock facility */
typedef struct mach_timespec { unsigned int tv_sec; clock_res_t tv_nsec; } mach_timespec_t;
// Reserved clock id values for default clocks
#define SYSTEM_CLOCK   (0)
#define CALENDAR_CLOCK   (1)
#define REALTIME_CLOCK   (0)
// Attribute names
/** get_time call resolution */
#define CLOCK_GET_TIME_RES   (1)
/** Current alarm resolution */
#define CLOCK_ALARM_CURRES   (3)
/** Minimum alarm resolution */
#define CLOCK_ALARM_MINRES   (4)
/** Maximum alarm resolution */
#define CLOCK_ALARM_MAXRES   (5)
// Alarm parameters
/** Type (8-bit field) */
#define ALRMTYPE   (0xff)
/** Absolute time */
#define TIME_ABSOLUTE   (0)
/** Relative time */
#define TIME_RELATIVE   (1)
#define BAD_ALRMTYPE(t)   (((t) & (~(TIME_RELATIVE))) != 0)


// POINTER-RELATED DATATYPES

#if (TYPESIZE_PTR == 64)
#   define __sptr   int64_t
#   define __uptr   uint64_t
#elif (TYPESIZE_PTR == 32)
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
#ifndef __PTRDIFF_TYPE__
#   define __PTRDIFF_TYPE__   __SWORD_TYPE
#endif
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
/** Darwin ptrdiff_t datatype */
#define __darwin_ptrdiff_t   ptrdiff_t
#define darwin_ptrdiff_t   ptrdiff_t
#define _BSD_PTRDIFF_T_   ptrdiff_t
#ifndef __INTPTR_TYPE__
#   define __INTPTR_TYPE__   __SWORD_TYPE
#endif
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
#ifndef __UINTPTR_TYPE__
#   define __UINTPTR_TYPE__   __UWORD_TYPE
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
#define darwin_uintptr_t   uintptr_t
#define __darwin_uintptr_t   uintptr_t
#define rk_UNCONST(x)   ((void*)(uintptr_t)(const void*)(x))
/** Signed integer datatype that can hold a pointer beyond 64KB (from Atmel AVR)  */
typedef int32_t   int_farptr_t;
/** Unsigned integer datatype that can hold a pointer beyond 64KB (from Atmel AVR)  */
typedef uint32_t   uint_farptr_t;
typedef void*   LPVOID;
#define PVOID   LPVOID
#ifndef _LPCVOID_DEFINED
#   define _LPCVOID_DEFINED   (1)
typedef const void*   LPCVOID;
#endif
#ifdef ENV64BIT
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
#elif defined(ENV32BIT)
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
/** Unsigned character pointer */
typedef unsigned char*   PUCHAR;
typedef char*   PSZ;
#define BYTE   unsigned char
typedef BYTE*   PBYTE;
typedef BYTE*   LPBYTE;
typedef WORD*   PWORD;
typedef WORD*   LPWORD;
typedef DWORD*   PDWORD;
typedef DWORD*   LPDWORD;
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
typedef short*   PSHORT;
typedef int*   int_ptr_t;
typedef int   _Mbstatet;
typedef int*   PINT;
typedef int*   LPINT;
typedef int*   PLONG32;
typedef int*   PINT32;
typedef long*   long_ptr_t;
typedef long*   LPLONG;
typedef long*   PLARGE_INTEGER;
typedef unsigned char*   uchar_ptr_t;
typedef unsigned short*   ushort_ptr_t;
typedef unsigned short*   PUSHORT;
typedef unsigned int*   uint_ptr_t;
typedef unsigned int*   PUINT;
typedef unsigned int*   LPUINT;
typedef unsigned int*   PULONG32;
typedef unsigned int*   PDWORD32;
typedef unsigned int*   PUINT32;
typedef unsigned long*   ulong_ptr_t;
typedef unsigned long*   PULONG;
typedef quad_t*   quad_ptr_t;
typedef int8_t*   PINT8;
typedef int8_t*   s8_ptr_t;
#define i8_ptr_t   s8_ptr_t
typedef int16_t*   PINT16;
typedef int16_t*   s16_ptr_t;
#define i16_ptr_t   s16_ptr_t
typedef int32_t*   s32_ptr_t;
#define i32_ptr_t   s32_ptr_t
typedef int64_t*   PLONG64;
typedef int64_t*   PINT64;
typedef int64_t*   s64_ptr_t;
#define i64_ptr_t   s64_ptr_t
typedef uint8_t*   PUINT8;
typedef uint8_t*   u8_ptr_t;
#define ptr8_t   u8_ptr_t
typedef uint16_t*   PUINT16;
typedef uint16_t*   u16_ptr_t;
#define ptr16_t   u16_ptr_t
typedef uint32_t*   u32_ptr_t;
typedef uint64_t*   PULONG64;
typedef uint64_t*   PDWORD64;
typedef uint64_t*   PUINT64;
typedef uint64_t*   u64_ptr_t;
typedef size_t*   PSIZE_T;
/** Windows pointer datatype */
typedef ssize_t*   PSSIZE_T;
typedef float*   float_ptr_t;
typedef float*   PFLOAT;
typedef double*   double_ptr_t;
typedef double*   PDOUBLE;
#define HandleToUlong(_handle)   ((unsigned long)(uintptr_t)((void*)(_handle)))
#define HandleToLong(_handle)   ((long)(intptr_t)((void*)(_handle)))
#define ULongToHandle(_handle)   ((void*)(UINT_PTR)((long)(_handle)))
#define LongToHandle(_handle)   ((void*)(INT_PTR)((long)(_handle)))
#define PtrToUlong(__ptr)   ((unsigned long)(uintptr_t)((void*)(__ptr)))
#define PtrToUint(__ptr)   ((unsigned int)(UINT_PTR)((void*)(__ptr)))
#define PtrToUshort(__ptr)   ((unsigned short)(uintptr_t)((void*)(__ptr)))
#define PtrToLong(__ptr)   ((long)(intptr_t)((void*)(__ptr)))
#define PtrToInt(__ptr)   ((int)(INT_PTR)((void*)(__ptr)))
#define PtrToShort(__ptr)   ((short)(INT_PTR)((void*)(__ptr)))
#define IntToPtr(__num)   ((void*)(INT_PTR)((int)(__num)))
#define UIntToPtr(__num)   ((void*)(UINT_PTR)((unsigned int)(__num)))
#define LongToPtr(__num)   ((void*)(intptr_t)((long)(__num)))
#define ULongToPtr(__num)   ((void*)(uintptr_t)((unsigned long)(__num)))
#define HandleToULong(_handle)   HandleToUlong((_handle))
#define UlongToHandle(_handle)   ULongToHandle((_handle))
#define UlongToPtr(__num)   ULongToPtr((__num))
#define UintToPtr(__num)   UIntToPtr(__num)


// DDEKIT DATATYPES

typedef signed char   ddekit_int8_t;
typedef unsigned char   ddekit_uint8_t;
typedef signed short   ddekit_int16_t;
typedef unsigned short   ddekit_uint16_t;
typedef signed int   ddekit_int32_t;
typedef unsigned int   ddekit_uint32_t;
typedef unsigned long   ddekit_addr_t;


// MISCELLANEOUS FIXED-WIDTH DATATYPES

typedef int   mqd_t;
typedef uint16_t   n_short;
typedef uint32_t   n_long;
typedef uint32_t   n_time;
typedef uint32_t   memory_object_cluster_size_t;
typedef uint64_t   memory_object_offset_t;
typedef uint64_t   memory_object_size_t;
typedef struct short_div_struct {
	short quot;  // Quotient
	short rem;  // Remainder
} short_div_t;
typedef struct div_struct {
	int quot;  // Quotient
	int rem;  // Remainder
} div_t;
typedef struct ldiv_struct {
	long quot;  // Quotient
	long rem;  // Remainder
} ldiv_t;
typedef struct lldiv_struct {
	long long quot;  // Quotient
	long long rem;  // Remainder
} lldiv_t;
typedef struct div8_struct {
	int8_t quot;  // Quotient
	int8_t rem;  // Remainder
} div8_t;
typedef struct div16_struct {
	int16_t quot;  // Quotient
	int16_t rem;  // Remainder
} div16_t;
typedef struct div32_struct {
	int32_t quot;  // Quotient
	int32_t rem;  // Remainder
} div32_t;
typedef struct div64_struct {
	int64_t quot;  // Quotient
	int64_t rem;  // Remainder
} div64_t;
#if SUPPORTS_INT128
typedef struct div128_struct {
	int128_t quot;  // Quotient
	int128_t rem;  // Remainder
} div128_t;
#endif
#if IS_WORDSIZE_64
typedef struct imaxdiv {
	long quot;  // Quotient
	long rem;  // Remainder
} imaxdiv_t;
#else
typedef struct imaxdiv {
	long long quot;  // Quotient
	long long rem;  // Remainder
} imaxdiv_t;
#endif


// CHARACTERISTICS FOR IEEE FLOATING-POINT FORMATS (<float.h> & <decfloat.h>)

#if (!(defined(_FLOAT_H_) || defined(_FLOAT_H) || defined(_FLOAT_H___) || defined(_FLOAT_H__) || defined(_FLOAT_LIB_H_) || defined(_VALUES_H) || defined(_FPMAX_H)))  // http://www.cplusplus.com/reference/cfloat/ & http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/float.h.html
#define _FLOAT_H_   (1)
#define _FLOAT_H   (1)
#define FLOAT_H   (1)
#define _FLOAT_H__   (1)
#define _FLOAT_H___   (1)
#define _FLOAT_LIB_H_   (1)
#define __FLOAT_LIB_H__   (1)
#define _VALUES_H   (1)
#define _VALUES_H_   (1)
#define _FPMAX_H   (1)
#define _FPMAX_H_   (1)
#define _UCLIBC_FPMAX_H   (1)
#define DECNUMBER   (1)


// FP_FAST_FMA

#ifdef __FMA__
/** The compiler will define __FMA__ if the fma builtins are supported */
#   define SUPPORTS_FMA   (1)
#endif
#ifdef __FP_FAST_FMAF
/** The compiler will define __FP_FAST_FMAF if the fma builtins are supported for floats */
#   define FP_FAST_FMAF   (1)
#endif
#ifdef __FP_FAST_FMA
/** The compiler will define __FP_FAST_FMA if the fma builtins are supported for doubles */
#   define FP_FAST_FMA   (1)
#endif
#ifdef __FP_FAST_FMAL
/** The compiler will define __FP_FAST_FMAL if the fma builtins are supported for long doubles */
#   define FP_FAST_FMAL   (1)
#endif


// HALF-FLOAT VALUES & PROPERTIES

#ifndef HFLT_RADIX
#   ifndef __HFLT_RADIX__
/** Radix of exponent representation; Base or radix of exponent representation (integer >1) */
#      define __HFLT_RADIX__   (2)
/** Radix of exponent representation; Base or radix of exponent representation (integer >1) */
#      define HFLT_RADIX   (2)
#   else
/** Radix of exponent representation; Base or radix of exponent representation (integer >1) */
#      define HFLT_RADIX   __FLT_RADIX__
#   endif
#   ifndef _HFLT_RADIX
/** Radix of exponent representation; Base or radix of exponent representation (integer >1) */
#      define _HFLT_RADIX   HFLT_RADIX
#   endif
#endif
#ifndef HFLT_HAS_INFINITY
#   ifndef __HFLT_HAS_INFINITY__
/** Half-float infinity is supported */
#      define __HFLT_HAS_INFINITY__   (1)
/** Half-float infinity is supported */
#      define HFLT_HAS_INFINITY   (1)
#   else
/** Half-float infinity is supported */
#      define HFLT_HAS_INFINITY   __HFLT_HAS_INFINITY__
#   endif
#endif
#ifndef HFLT_HAS_QUIET_NAN
#   ifndef __HFLT_HAS_QUIET_NAN__
/** Half-float quiet NAN (QNAN) is supported */
#      define __HFLT_HAS_QUIET_NAN__   (1)
/** Half-float quiet NAN (QNAN) is supported */
#      define HFLT_HAS_QUIET_NAN   (1)
#   else
/** Half-float quiet NAN (QNAN) is supported */
#      define HFLT_HAS_QUIET_NAN   __HFLT_HAS_QUIET_NAN__
#   endif
#endif
#ifndef HFLT_HAS_DENORM
#   ifndef __HFLT_HAS_DENORM__
/** Half-float denormal values are supported */
#      define __HFLT_HAS_DENORM__   (1)
/** Half-float denormal values are supported */
#      define HFLT_HAS_DENORM   (1)
#   else
/** Half-float denormal values are supported */
#      define HFLT_HAS_DENORM   __HFLT_HAS_DENORM__
#   endif
#endif
#ifndef HFLT_MANT_DIG
#   ifndef __HFLT_MANT_DIG__
/** Number of base-HFLT_RADIX digits in the significand of a half-float */
#      define __HFLT_MANT_DIG__   (11)
/** Number of base-HFLT_RADIX digits in the significand of a half-float */
#      define HFLT_MANT_DIG   (11)
#   else
/** Number of base-HFLT_RADIX digits in the significand of a half-float */
#      define HFLT_MANT_DIG   __HFLT_MANT_DIG__
#   endif
#endif
#ifndef HFLT_DIG
#   ifndef __HFLT_DIG__
/** Number of decimal digits of precision in a half-float */
#      define __HFLT_DIG__   (3)
/** Number of decimal digits of precision in a half-float */
#      define HFLT_DIG   (3)
#   else
/** Number of decimal digits of precision in a half-float */
#      define HFLT_DIG   __HFLT_DIG__
#   endif
#endif
#ifndef HFLT_MIN_EXP
#   ifndef __HFLT_MIN_EXP__
/** Minimum int x such that HFLT_RADIX**(x-1) is a normalised half-float */
#      define __HFLT_MIN_EXP__   (-14)
/** Minimum int x such that HFLT_RADIX**(x-1) is a normalised half-float */
#      define HFLT_MIN_EXP   (-14)
#   else
/** Minimum int x such that HFLT_RADIX**(x-1) is a normalised half-float */
#      define HFLT_MIN_EXP   __HFLT_MIN_EXP__
#   endif
#endif
#ifndef HFLT_MAX_EXP
#   ifndef __HFLT_MAX_EXP__
/** Maximum int x such that HFLT_RADIX**(x-1) is a representable half-float */
#      define __HFLT_MAX_EXP__   (15)
/** Maximum int x such that HFLT_RADIX**(x-1) is a representable half-float */
#      define HFLT_MAX_EXP   (15)
#   else
/** Maximum int x such that HFLT_RADIX**(x-1) is a representable half-float */
#      define HFLT_MAX_EXP   __HFLT_MAX_EXP__
#   endif
#endif


// FLOAT VALUES & PROPERTIES

#ifndef FLT_RADIX
#   ifndef __FLT_RADIX__
/** Radix of exponent representation; Base or radix of exponent representation (integer >1) */
#      define __FLT_RADIX__   (2)
/** Radix of exponent representation; Base or radix of exponent representation (integer >1) */
#      define FLT_RADIX   (2)
#   else
/** Radix of exponent representation; Base or radix of exponent representation (integer >1) */
#      define FLT_RADIX   __FLT_RADIX__
#   endif
#   ifndef _FLT_RADIX
/** Radix of exponent representation; Base or radix of exponent representation (integer >1) */
#      define _FLT_RADIX   FLT_RADIX
#   endif
#endif
#ifndef FLT_HAS_INFINITY
#   ifndef __FLT_HAS_INFINITY__
/** `float` infinity is supported */
#      define __FLT_HAS_INFINITY__   (1)
/** `float` infinity is supported */
#      define FLT_HAS_INFINITY   (1)
#   else
/** `float` infinity is supported */
#      define FLT_HAS_INFINITY   __FLT_HAS_INFINITY__
#   endif
#endif
#ifndef FLT_HAS_QUIET_NAN
#   ifndef __FLT_HAS_QUIET_NAN__
/** `float` quiet NAN (QNAN) is supported */
#      define __FLT_HAS_QUIET_NAN__   (1)
/** `float` quiet NAN (QNAN) is supported */
#      define FLT_HAS_QUIET_NAN   (1)
#   else
/** `float` quiet NAN (QNAN) is supported */
#      define FLT_HAS_QUIET_NAN   __FLT_HAS_QUIET_NAN__
#   endif
#endif
#ifndef FLT_HAS_DENORM
#   ifndef __FLT_HAS_DENORM__
/** `float` denormal values are supported */
#      define __FLT_HAS_DENORM__   (1)
/** `float` denormal values are supported */
#      define FLT_HAS_DENORM   (1)
#   else
/** `float` denormal values are supported */
#      define FLT_HAS_DENORM   __FLT_HAS_DENORM__
#   endif
#endif
#ifndef FLT_MANT_DIG
#   ifndef __FLT_MANT_DIG__
/** Number of base-FLT_RADIX digits in the significand of a float */
#      define __FLT_MANT_DIG__   (24)
/** Number of base-FLT_RADIX digits in the significand of a float */
#      define FLT_MANT_DIG   (24)
#   else
/** Number of base-FLT_RADIX digits in the significand of a float */
#      define FLT_MANT_DIG   __FLT_MANT_DIG__
#   endif
#endif
#ifndef SF_SIZE
#   define SF_SIZE   FLT_MANT_DIG
#endif
#ifndef FLT_DIG
#   ifndef __FLT_DIG__
/** Number of decimal digits of precision in a float */
#      define __FLT_DIG__   (6)
/** Number of decimal digits of precision in a float */
#      define FLT_DIG   (6)
#   else
/** Number of decimal digits of precision in a float */
#      define FLT_DIG   __FLT_DIG__
#   endif
#endif
#ifndef FLT_EPSILON
#   ifndef __FLT_EPSILON__
/** Difference between 1.0 and the minimum float greater than 1.0 */
#      define __FLT_EPSILON__   (1.19209289550781250000e-7F)  // 1.19209290e-07F
/** Difference between 1.0 and the minimum float greater than 1.0 */
#      define FLT_EPSILON   __FLT_EPSILON__
#   else
/** Difference between 1.0 and the minimum float greater than 1.0 */
#      define FLT_EPSILON   __FLT_EPSILON__
#   endif
#endif
#ifndef FLT_MIN_EXP
#   ifndef __FLT_MIN_EXP__
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float */
#      define __FLT_MIN_EXP__   (-125)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float */
#      define FLT_MIN_EXP   (-125)
#   else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised float */
#      define FLT_MIN_EXP   __FLT_MIN_EXP__
#   endif
#endif
#ifndef FLT_MIN
#   ifndef __FLT_MIN__
/** Minimum normalised float */
#      define __FLT_MIN__   (1.17549435082228750797e-38F)  // 1.1754943508222875e-38F || 1.17549435e-38F
/** Minimum normalised float */
#      define FLT_MIN   __FLT_MIN__
#   else
/** Minimum normalised float */
#      define FLT_MIN   __FLT_MIN__
#   endif
#endif
#ifndef FLT_MIN_10_EXP
#   ifndef __FLT_MIN_10_EXP__
/** Minimum int x such that 10**x is a normalised float */
#      define __FLT_MIN_10_EXP__   (-37)
/** Minimum int x such that 10**x is a normalised float */
#      define FLT_MIN_10_EXP   (-37)
#   else
/** Minimum int x such that 10**x is a normalised float */
#      define FLT_MIN_10_EXP   __FLT_MIN_10_EXP__
#   endif
#endif
#ifndef FLT_TRUE_MIN
#   ifndef __FLT_DENORM_MIN__
/** Minimal denormal float value */
#      define FLT_TRUE_MIN   (1.40129846432481707092e-45F)  // 1.4012984643248171e-45F || 1.40129846e-45F
/** Minimal denormal float value */
#      define __FLT_DENORM_MIN__   FLT_TRUE_MIN
#   else
/** Minimal denormal float value */
#      define FLT_TRUE_MIN   __FLT_DENORM_MIN__
#   endif
#endif
#ifndef FLT_DENORM_MIN
/** Minimal denormal float value */
#   define FLT_DENORM_MIN   __FLT_DENORM_MIN__
#endif
#ifndef FLT_SUBNORMAL_MIN
/** Minimal denormal float value */
#   define FLT_SUBNORMAL_MIN   __FLT_DENORM_MIN__
#endif
#ifndef FLT_MAX_EXP
#   ifndef __FLT_MAX_EXP__
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float */
#      define __FLT_MAX_EXP__   (128)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float */
#      define FLT_MAX_EXP   (128)
#   else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable float */
#      define FLT_MAX_EXP   __FLT_MAX_EXP__
#   endif
#endif
#ifndef FLT_MAX
#   ifndef __FLT_MAX__
/** The maximum representable finite float */
#      define __FLT_MAX__   (3.40282346638528859812e+38F)  // 3.4028234663852886e+38F || 3.40282347e+38F
/** The maximum representable finite float */
#      define FLT_MAX   __FLT_MAX__
#   else
/** The maximum representable finite float */
#      define FLT_MAX   __FLT_MAX__
#   endif
#endif
#ifndef FLT_MAX_10_EXP
#   ifndef __FLT_MAX_10_EXP__
/** Maximum int x such that 10**x is a representable float */
#      define __FLT_MAX_10_EXP__   (38)
/** Maximum int x such that 10**x is a representable float */
#      define FLT_MAX_10_EXP   (38)
#   else
/** Maximum int x such that 10**x is a representable float */
#      define FLT_MAX_10_EXP   __FLT_MAX_10_EXP__
#   endif
#endif
#define EXCESSF   126
#define HIDDENF   (1 << 23)
#define SIGNF(fp)   ((fp) & 0x80000000)
#ifndef EXPF
#   define EXPF(x)   ((((short*)(void*)&(x))[1] & 0x7F80) >> 7)  // (((x) >> 23) & 0xFF)
#endif
#define MANTF(fp)   (((fp) & 0x7FFFFF) | HIDDENF)
#define PACKF(s, e, m)   ((s) | ((e) << 23) | (m))


// DOUBLE VALUES & PROPERTIES

#ifndef DBL_RADIX
#   ifndef __DBL_RADIX__
/** Radix of exponent representation */
#      define __DBL_RADIX__   FLT_RADIX
/** Radix of exponent representation */
#      define DBL_RADIX   FLT_RADIX
#   else
/** Radix of exponent representation */
#      define DBL_RADIX   __DBL_RADIX__
#   endif
#   ifndef _DBL_RADIX
/** Radix of exponent representation */
#      define _DBL_RADIX   FLT_RADIX
#   endif
#endif
#ifndef DBL_HAS_INFINITY
#   ifndef __DBL_HAS_INFINITY__
/** `double` infinity is supported */
#      define __DBL_HAS_INFINITY__   (1)
/** `double` infinity is supported */
#      define DBL_HAS_INFINITY   (1)
#   else
/** `double` infinity is supported */
#      define DBL_HAS_INFINITY   __DBL_HAS_INFINITY__
#   endif
#endif
#ifndef DBL_HAS_QUIET_NAN
#   ifndef __DBL_HAS_QUIET_NAN__
/** `double` quiet NAN (QNAN) is supported */
#      define __DBL_HAS_QUIET_NAN__   (1)
/** `double` quiet NAN (QNAN) is supported */
#      define DBL_HAS_QUIET_NAN   (1)
#   else
/** `double` quiet NAN (QNAN) is supported */
#      define DBL_HAS_QUIET_NAN   __DBL_HAS_QUIET_NAN__
#   endif
#endif
#ifndef DBL_HAS_DENORM
#   ifndef __DBL_HAS_DENORM__
/** `double` denormal values are supported */
#      define __DBL_HAS_DENORM__   (1)
/** `double` denormal values are supported */
#      define DBL_HAS_DENORM   (1)
#   else
/** `double` denormal values are supported */
#      define DBL_HAS_DENORM   __DBL_HAS_DENORM__
#   endif
#endif
#ifndef DBL_MANT_DIG
#   ifndef __DBL_MANT_DIG__
/** Number of base-FLT_RADIX digits in the significand of a double */
#      define __DBL_MANT_DIG__   (53)
/** Number of base-FLT_RADIX digits in the significand of a double */
#      define DBL_MANT_DIG   (53)
#   else
/** Number of base-FLT_RADIX digits in the significand of a double */
#      define DBL_MANT_DIG   __DBL_MANT_DIG__
#   endif
#endif
#ifndef DF_SIZE
#   define DF_SIZE   DBL_MANT_DIG
#endif
#ifndef DBL_DIG
#   ifndef __DBL_DIG__
/** Number of decimal digits of precision in a double */
#      define __DBL_DIG__   (15)
/** Number of decimal digits of precision in a double */
#      define DBL_DIG   (15)
#   else
/** Number of decimal digits of precision in a double */
#      define DBL_DIG   __DBL_DIG__
#   endif
#endif
#ifndef DBL_EPSILON
#   ifndef __DBL_EPSILON__
/** Difference between 1.0 and the minimum double greater than 1.0 */
#      define __DBL_EPSILON__   ((double)2.22044604925031308085e-16L)  // ((double)2.2204460492503131e-16L)
/** Difference between 1.0 and the minimum double greater than 1.0 */
#      define DBL_EPSILON   __DBL_EPSILON__
#   else
/** Difference between 1.0 and the minimum double greater than 1.0 */
#      define DBL_EPSILON   __DBL_EPSILON__
#   endif
#endif
#ifndef DBL_MIN_EXP
#   ifndef __DBL_MIN_EXP__
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised double */
#      define __DBL_MIN_EXP__   (-1021)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised double */
#      define DBL_MIN_EXP   (-1021)
#   else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised double */
#      define DBL_MIN_EXP   __DBL_MIN_EXP__
#   endif
#endif
#ifndef DBL_MIN
#   ifndef __DBL_MIN__
/** Minimum normalised double */
#      define __DBL_MIN__   ((double)2.22507385850720138309e-308L)  // ((double)2.2250738585072014e-308L)
/** Minimum normalised double */
#      define DBL_MIN   __DBL_MIN__
#   else
/** Minimum normalised double */
#      define DBL_MIN   __DBL_MIN__
#   endif
#endif
#ifndef DBL_MIN_10_EXP
#   ifndef __DBL_MIN_10_EXP__
/** Minimum int x such that 10**x is a normalised double */
#      define __DBL_MIN_10_EXP__   (-307)
/** Minimum int x such that 10**x is a normalised double */
#      define DBL_MIN_10_EXP   (-307)
#   else
/** Minimum int x such that 10**x is a normalised double */
#      define DBL_MIN_10_EXP   __DBL_MIN_10_EXP__
#   endif
#endif
#ifndef DBL_TRUE_MIN
#   ifndef __DBL_DENORM_MIN__
/** Minimal denormal double value */
#      define DBL_TRUE_MIN   ((double)4.94065645841246544177e-324L)  // ((double)4.9406564584124654e-324L)
/** Minimal denormal double value */
#      define __DBL_DENORM_MIN__   DBL_TRUE_MIN
#   else
/** Minimal denormal double value */
#      define DBL_TRUE_MIN   __DBL_DENORM_MIN__
#   endif
#endif
#ifndef DBL_DENORM_MIN
/** Minimal denormal double value */
#   define DBL_DENORM_MIN   DBL_TRUE_MIN
#endif
#ifndef DBL_SUBNORMAL_MIN
/** Minimal denormal double value */
#   define DBL_SUBNORMAL_MIN   DBL_TRUE_MIN
#endif
#ifndef DBL_MAX_EXP
#   ifndef __DBL_MAX_EXP__
/** Maximum int x such that FLT_RADIX**(x-1) is a representable double */
#      define __DBL_MAX_EXP__   (1024)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable double */
#      define DBL_MAX_EXP   (1024)
#   else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable double */
#      define DBL_MAX_EXP   __DBL_MAX_EXP__
#   endif
#endif
#ifndef DBL_MAX
#   ifndef __DBL_MAX__
/** The maximum representable finite double */
#      define __DBL_MAX__   ((double)1.79769313486231570815e+308L)  // ((double)1.7976931348623157e+308L)
/** The maximum representable finite double */
#      define DBL_MAX   __DBL_MAX__
#   else
/** The maximum representable finite double */
#      define DBL_MAX   __DBL_MAX__
#   endif
#endif
#ifndef DBL_MAX_10_EXP
#   ifndef __DBL_MAX_10_EXP__
/** Maximum int x such that 10**x is a representable double */
#      define __DBL_MAX_10_EXP__   (308)
/** Maximum int x such that 10**x is a representable double */
#      define DBL_MAX_10_EXP   (308)
#   else
/** Maximum int x such that 10**x is a representable double */
#      define DBL_MAX_10_EXP   __DBL_MAX_10_EXP__
#   endif
#endif
#define DBL_ADJ   (DBL_MAX_EXP - 2 + ((DBL_MANT_DIG - 1) % 4))
#define EXCESSD   1022
#define HIDDEND   (0x100000)
#ifndef EXPD
#   define EXPD(x)   ((((short*)(void*)&(x))[3] & 0x7FF0) >> 4)  // (((x.l.upper) >> 20) & 0x7FF)
#endif
#define SIGND(fp)   ((fp.l.upper) & SIGNBIT)
#define MANTD(fp)   (((((fp.l.upper) & 0xFFFFF) | HIDDEND) << 10) | (fp.l.lower >> 22))
#define HIDDEND_LL   ((long long)1 << 52)
#define MANTD_LL(fp)   ((fp.ll & (HIDDEND_LL - 1)) | HIDDEND_LL)
#define PACKD_LL(s, e, m)   (((long long)((s) + ((e) << 20)) << 32) | (m))


// LONG DOUBLE VALUES & PROPERTIES

#ifndef LDBL_RADIX
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
#      define _LDBL_RADIX   FLT_RADIX
#   endif
#endif
#ifndef LDBL_HAS_INFINITY
#   ifndef __LDBL_HAS_INFINITY__
/** `long double` infinity is supported */
#      define __LDBL_HAS_INFINITY__   (1)
/** `long double` infinity is supported */
#      define LDBL_HAS_INFINITY   (1)
#   else
/** `long double` infinity is supported */
#      define LDBL_HAS_INFINITY   __LDBL_HAS_INFINITY__
#   endif
#endif
#ifndef LDBL_HAS_QUIET_NAN
#   ifndef __LDBL_HAS_QUIET_NAN__
/** `long double` quiet NAN (QNAN) is supported */
#      define __LDBL_HAS_QUIET_NAN__   (1)
/** `long double` quiet NAN (QNAN) is supported */
#      define LDBL_HAS_QUIET_NAN   (1)
#   else
/** `long double` quiet NAN (QNAN) is supported */
#      define LDBL_HAS_QUIET_NAN   __LDBL_HAS_QUIET_NAN__
#   endif
#endif
#ifndef LDBL_HAS_DENORM
#   ifndef __LDBL_HAS_DENORM__
/** `long double` denormal values are supported */
#      define __LDBL_HAS_DENORM__   (1)
/** `long double` denormal values are supported */
#      define LDBL_HAS_DENORM   (1)
#   else
/** `long double` denormal values are supported */
#      define LDBL_HAS_DENORM   __LDBL_HAS_DENORM__
#   endif
#endif
#ifndef LDBL_MANT_DIG
#   ifndef __LDBL_MANT_DIG__
#      ifdef __VFP_FP__
/** Number of base-FLT_RADIX digits in the significand of a long double */
#         define __LDBL_MANT_DIG__   (53)
/** Number of base-FLT_RADIX digits in the significand of a long double */
#         define LDBL_MANT_DIG   (53)
#      else
/** Number of base-FLT_RADIX digits in the significand of a long double */
#         define __LDBL_MANT_DIG__   (64)
/** Number of base-FLT_RADIX digits in the significand of a long double */
#         define LDBL_MANT_DIG   (64)
#      endif
#   else
/** Number of base-FLT_RADIX digits in the significand of a long double */
#      define LDBL_MANT_DIG   __LDBL_MANT_DIG__
#   endif
#endif
#ifndef LDBL_DIG
#   ifndef __LDBL_DIG__
#      ifdef __VFP_FP__
/** Number of decimal digits of precision in a long double */
#         define __LDBL_DIG__   (15)
/** Number of decimal digits of precision in a long double */
#         define LDBL_DIG   (15)
#      else
/** Number of decimal digits of precision in a long double */
#         define __LDBL_DIG__   (18)
/** Number of decimal digits of precision in a long double */
#         define LDBL_DIG   (18)
#      endif
#   else
/** Number of decimal digits of precision in a long double */
#      define LDBL_DIG   __LDBL_DIG__
#   endif
#endif
#ifndef LDBL_EPSILON
#   ifndef __LDBL_EPSILON__
#      ifdef __VFP_FP__
/** Difference between 1.0 and the minimum long double greater than 1.0 */
#         define __LDBL_EPSILON__   ((long double)2.2204460492503131e-16L)
/** Difference between 1.0 and the minimum long double greater than 1.0 */
#         define LDBL_EPSILON   ((long double)2.2204460492503131e-16L)
#      else
/** Difference between 1.0 and the minimum long double greater than 1.0 */
#         define __LDBL_EPSILON__   ((long double)1.08420217248550443401e-19L)
/** Difference between 1.0 and the minimum long double greater than 1.0 */
#         define LDBL_EPSILON   ((long double)1.08420217248550443401e-19L)
#      endif
#   else
/** Difference between 1.0 and the minimum long double greater than 1.0 */
#      define LDBL_EPSILON   __LDBL_EPSILON__
#   endif
#endif
#ifndef LDBL_MIN_EXP
#   ifndef __LDBL_MIN_EXP__
#      ifdef __VFP_FP__
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised long double */
#         define __LDBL_MIN_EXP__   (-1021)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised long double */
#         define LDBL_MIN_EXP   (-1021)
#      else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised long double */
#         define __LDBL_MIN_EXP__   (-16381)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised long double */
#         define LDBL_MIN_EXP   (-16381)
#      endif
#   else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised long double */
#      define LDBL_MIN_EXP   __LDBL_MIN_EXP__
#   endif
#endif
#ifndef LDBL_MIN
#   ifndef __LDBL_MIN__
#      ifdef __VFP_FP__
/** Minimum normalised long double */
#         define __LDBL_MIN__   ((long double)2.2250738585072014e-308L)
/** Minimum normalised long double */
#         define LDBL_MIN   __LDBL_MIN__
#      else
/** Minimum normalised long double */
#         define __LDBL_MIN__   ((long double)3.36210314311209350626e-4932L)
/** Minimum normalised long double */
#         define LDBL_MIN   __LDBL_MIN__
#      endif
#   else
/** Minimum normalised long double */
#      define LDBL_MIN   __LDBL_MIN__
#   endif
#endif
#ifndef LDBL_MIN_10_EXP
#   ifndef __LDBL_MIN_10_EXP__
#      ifdef __VFP_FP__
/** Minimum int x such that 10**x is a normalised long double */
#         define __LDBL_MIN_10_EXP__   (-307)
/** Minimum int x such that 10**x is a normalised long double */
#         define LDBL_MIN_10_EXP   (-307)
#      else
/** Minimum int x such that 10**x is a normalised long double */
#         define __LDBL_MIN_10_EXP__   (-4931)
/** Minimum int x such that 10**x is a normalised long double */
#         define LDBL_MIN_10_EXP   (-4931)
#      endif
#   else
/** Minimum int x such that 10**x is a normalised long double */
#      define LDBL_MIN_10_EXP   __LDBL_MIN_10_EXP__
#   endif
#endif
#ifndef LDBL_TRUE_MIN
#   ifndef __LDBL_DENORM_MIN__
#      ifdef __VFP_FP__
/** Minimal denormal double value */
#         define LDBL_TRUE_MIN   ((long double)4.9406564584124654e-324L)
/** Minimal denormal double value */
#         define __LDBL_DENORM_MIN__   ((long double)4.9406564584124654e-324L)
#      else
/** Minimal denormal double value */
#         define LDBL_TRUE_MIN   ((long double)3.64519953188247460253e-4951L)
/** Minimal denormal double value */
#         define __LDBL_DENORM_MIN__   ((long double)3.64519953188247460253e-4951L)
#      endif
#   else
/** Minimal denormal double value */
#      define LDBL_TRUE_MIN   __LDBL_DENORM_MIN__
#   endif
#endif
#ifndef LDBL_DENORM_MIN
/** Minimal denormal double value */
#   define LDBL_DENORM_MIN   __LDBL_DENORM_MIN__
#endif
#ifndef LDBL_SUBNORMAL_MIN
/** Minimal denormal double value */
#   define LDBL_SUBNORMAL_MIN   __LDBL_DENORM_MIN__
#endif
#ifndef LDBL_MAX_EXP
#   ifndef __LDBL_MAX_EXP__
#      ifdef __VFP_FP__
/** Maximum int x such that FLT_RADIX**(x-1) is a representable long double */
#         define __LDBL_MAX_EXP__   (1024)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable long double */
#         define LDBL_MAX_EXP   (1024)
#      else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable long double */
#         define __LDBL_MAX_EXP__   (16384)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable long double */
#         define LDBL_MAX_EXP   (16384)
#      endif
#   else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable long double */
#      define LDBL_MAX_EXP   __LDBL_MAX_EXP__
#   endif
#endif
#ifndef LDBL_MAX
#   ifndef __LDBL_MAX__
#      ifdef __VFP_FP__
/** The maximum representable finite long double */
#         define __LDBL_MAX__   ((long double)1.7976931348623157e+308L)
/** The maximum representable finite long double */
#         define LDBL_MAX   ((long double)1.7976931348623157e+308L)
#      else
/** The maximum representable finite long double */
#         define __LDBL_MAX__   ((long double)1.18973149535723176502e+4932L)
/** The maximum representable finite long double */
#         define LDBL_MAX   ((long double)1.18973149535723176502e+4932L)
#      endif
#   else
/** The maximum representable finite long double */
#      define LDBL_MAX   __LDBL_MAX__
#   endif
#endif
#ifndef LDBL_MAX_10_EXP
#   ifndef __LDBL_MAX_10_EXP__
#      ifdef __VFP_FP__
/** Maximum int x such that 10**x is a representable long double */
#         define __LDBL_MAX_10_EXP__   (308)
/** Maximum int x such that 10**x is a representable long double */
#         define LDBL_MAX_10_EXP   (308)
#      else
/** Maximum int x such that 10**x is a representable long double */
#         define __LDBL_MAX_10_EXP__   (4932)
/** Maximum int x such that 10**x is a representable long double */
#         define LDBL_MAX_10_EXP   (4932)
#      endif
#   else
/** Maximum int x such that 10**x is a representable long double */
#      define LDBL_MAX_10_EXP   __LDBL_MAX_10_EXP__
#   endif
#endif
#if ((LDBL_MANT_DIG == 53) && (LDBL_MAX_EXP == 1024))
#   define LONG_DOUBLE_IS_BINARY64   (1)
#   define LONG_DOUBLE_IS_X87_EXTENDED   (0)
#   define LONG_DOUBLE_IS_BINARY128   (0)
#   define SUPPORTS_LONG_DOUBLE_64   (1)
#   define SUPPORTS_LONG_DOUBLE_X87   (0)
#   define SUPPORTS_LONG_DOUBLE_128   (0)
#   define SUPPORTS_IBM_LONG_DOUBLE   (0)
#elif ((LDBL_MANT_DIG == 64) && (LDBL_MAX_EXP == 16384))
#   define LONG_DOUBLE_IS_BINARY64   (0)
#   define LONG_DOUBLE_IS_X87_EXTENDED   (1)
#   define LONG_DOUBLE_IS_BINARY128   (0)
#   define SUPPORTS_LONG_DOUBLE_64   (0)
#   define SUPPORTS_LONG_DOUBLE_X87   (1)
#   define SUPPORTS_LONG_DOUBLE_128   (0)
#   define SUPPORTS_IBM_LONG_DOUBLE   (0)
#elif ((LDBL_MANT_DIG == 113) && (LDBL_MAX_EXP == 16384))
#   define LONG_DOUBLE_IS_BINARY64   (0)
#   define LONG_DOUBLE_IS_X87_EXTENDED   (0)
#   define LONG_DOUBLE_IS_BINARY128   (1)
#   define SUPPORTS_LONG_DOUBLE_64   (0)
#   define SUPPORTS_LONG_DOUBLE_X87   (0)
#   define SUPPORTS_LONG_DOUBLE_128   (1)
#   define SUPPORTS_IBM_LONG_DOUBLE   (1)
#endif
#if LONG_DOUBLE_IS_BINARY64
#   define LD_B1B_DIG   2
#   define LD_B1B_MAX   9007199, 254740991
#   define KMAX   128
#elif LONG_DOUBLE_IS_X87_EXTENDED
#   define LD_B1B_DIG   3
#   define LD_B1B_MAX   18, 446744073, 709551615
#   define KMAX 2048
#elif LONG_DOUBLE_IS_BINARY128
#   define LD_B1B_DIG   4
#   define LD_B1B_MAX   10384593, 717069655, 257060992, 658440191
#   define KMAX   2048
#else
#   error   "Unsupported long double representation!"
#endif
#define FLOAT_MASK   (KMAX - 1)
#define LDBL_ADJ   (LDBL_MAX_EXP - 2 + ((LDBL_MANT_DIG - 1) % 4))
#if LONG_DOUBLE_IS_BINARY64
typedef char compiler_defines_long_double_incorrectly[9 - (int)SIZEOF_LONG_DOUBLE];
#endif
#ifndef EXPL
#   define EXPL(x)   ((((short*)(void*)&(x))[4] & 0x7FFF))
#endif


// QUADRUPLE (128-BIT FLOAT) VALUES & PROPERTIES

#ifndef QDL_RADIX
#   ifndef __QDL_RADIX__
/** Radix of exponent representation */
#      define __QDL_RADIX__   FLT_RADIX
/** Radix of exponent representation */
#      define QDL_RADIX   FLT_RADIX
#   else
/** Radix of exponent representation */
#      define QDL_RADIX   __QDL_RADIX__
#   endif
#   ifndef _QDL_RADIX
/** Radix of exponent representation */
#      define _QDL_RADIX   FLT_RADIX
#   endif
#endif
#ifndef QDL_HAS_INFINITY
#   ifndef __QDL_HAS_INFINITY__
/** `quadruple` infinity is supported */
#      define __QDL_HAS_INFINITY__   (1)
/** `quadruple` infinity is supported */
#      define QDL_HAS_INFINITY   (1)
#   else
/** `quadruple` infinity is supported */
#      define QDL_HAS_INFINITY   __QDL_HAS_INFINITY__
#   endif
#endif
#ifndef QDL_HAS_QUIET_NAN
#   ifndef __QDL_HAS_QUIET_NAN__
/** `quadruple` quiet NAN (QNAN) is supported */
#      define __QDL_HAS_QUIET_NAN__   (1)
/** `quadruple` quiet NAN (QNAN) is supported */
#      define QDL_HAS_QUIET_NAN   (1)
#   else
/** `quadruple` quiet NAN (QNAN) is supported */
#      define QDL_HAS_QUIET_NAN   __QDL_HAS_QUIET_NAN__
#   endif
#endif
#ifndef QDL_HAS_DENORM
#   ifndef __QDL_HAS_DENORM__
/** `quadruple` denormal values are supported */
#      define __QDL_HAS_DENORM__   (1)
/** `quadruple` denormal values are supported */
#      define QDL_HAS_DENORM   (1)
#   else
/** `quadruple` denormal values are supported */
#      define QDL_HAS_DENORM   __QDL_HAS_DENORM__
#   endif
#endif
#ifndef QDL_MAX_EXP
#   ifndef __QDL_MAX_EXP__
/** Maximum int x such that FLT_RADIX**(x-1) is a representable quadruple */
#      define __QDL_MAX_EXP__   (16383)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable quadruple */
#      define QDL_MAX_EXP   (16383)
#   else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable quadruple */
#      define QDL_MAX_EXP   __QDL_MAX_EXP__
#   endif
#endif
#ifndef QDL_MIN_EXP
#   ifndef __QDL_MIN_EXP__
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised quadruple */
#      define __QDL_MIN_EXP__   (-16382)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised quadruple */
#      define QDL_MIN_EXP   (-16382)
#   else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised quadruple */
#      define QDL_MIN_EXP   __QDL_MIN_EXP__
#   endif
#endif


// OCTUPLE (256-BIT FLOAT) VALUES & PROPERTIES

#ifndef OPL_RADIX
#   ifndef __OPL_RADIX__
/** Radix of exponent representation */
#      define __OPL_RADIX__   FLT_RADIX
/** Radix of exponent representation */
#      define OPL_RADIX   FLT_RADIX
#   else
/** Radix of exponent representation */
#      define OPL_RADIX   __OPL_RADIX__
#   endif
#   ifndef _OPL_RADIX
/** Radix of exponent representation */
#      define _OPL_RADIX   FLT_RADIX
#   endif
#endif
#ifndef OPL_HAS_INFINITY
#   ifndef __OPL_HAS_INFINITY__
/** `octuple` infinity is supported */
#      define __OPL_HAS_INFINITY__   (1)
/** `octuple` infinity is supported */
#      define OPL_HAS_INFINITY   (1)
#   else
/** `octuple` infinity is supported */
#      define OPL_HAS_INFINITY   __OPL_HAS_INFINITY__
#   endif
#endif
#ifndef OPL_HAS_QUIET_NAN
#   ifndef __OPL_HAS_QUIET_NAN__
/** `octuple` quiet NAN (QNAN) is supported */
#      define __OPL_HAS_QUIET_NAN__   (1)
/** `octuple` quiet NAN (QNAN) is supported */
#      define OPL_HAS_QUIET_NAN   (1)
#   else
/** `octuple` quiet NAN (QNAN) is supported */
#      define OPL_HAS_QUIET_NAN   __OPL_HAS_QUIET_NAN__
#   endif
#endif
#ifndef OPL_HAS_DENORM
#   ifndef __OPL_HAS_DENORM__
/** `octuple` denormal values are supported */
#      define __OPL_HAS_DENORM__   (1)
/** `octuple` denormal values are supported */
#      define OPL_HAS_DENORM   (1)
#   else
/** `octuple` denormal values are supported */
#      define OPL_HAS_DENORM   __OPL_HAS_DENORM__
#   endif
#endif
#ifndef OPL_MAX_EXP
#   ifndef __OPL_MAX_EXP__
/** Maximum int x such that FLT_RADIX**(x-1) is a representable octuple */
#      define __OPL_MAX_EXP__   (262143)
/** Maximum int x such that FLT_RADIX**(x-1) is a representable octuple */
#      define OPL_MAX_EXP   (262143)
#   else
/** Maximum int x such that FLT_RADIX**(x-1) is a representable octuple */
#      define OPL_MAX_EXP   __OPL_MAX_EXP__
#   endif
#endif
#ifndef OPL_MIN_EXP
#   ifndef __OPL_MIN_EXP__
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised octuple */
#      define __OPL_MIN_EXP__   (-262142)
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised octuple */
#      define OPL_MIN_EXP   (-262142)
#   else
/** Minimum int x such that FLT_RADIX**(x-1) is a normalised octuple */
#      define OPL_MIN_EXP   __OPL_MIN_EXP__
#   endif
#endif


// DECIMAL32 (FLOAT) VALUES & PROPERTIES

#ifndef DEC32_RADIX
#   ifndef __DEC32_RADIX__
/** Radix of exponent representation */
#      define __DEC32_RADIX__   (10)
/** Radix of exponent representation */
#      define DEC32_RADIX   (10)
#   else
/** Radix of exponent representation */
#      define DEC32_RADIX   __DEC32_RADIX__
#   endif
#   ifndef _DEC32_RADIX
/** Radix of exponent representation */
#      define _DEC32_RADIX   DEC32_RADIX
#   endif
#endif
#ifndef DEC32_MANT_DIG
#   ifndef __DEC32_MANT_DIG__
/** Number of base-10 digits in the significand of a decimal32 */
#      define __DEC32_MANT_DIG__   (7)
/** Number of base-10 digits in the significand of a decimal32 */
#      define DEC32_MANT_DIG   (7)
#   else
/** Number of base-10 digits in the significand of a decimal32 */
#      define DEC32_MANT_DIG   __DEC32_MANT_DIG__
#   endif
#endif
#ifndef DEC32_DIG
#   ifndef __FLT_DECIMAL_DIG__
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define __FLT_DECIMAL_DIG__   (9)
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define DEC32_DIG   (9)
#   else
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define DEC32_DIG   __FLT_DECIMAL_DIG__
#   endif
#endif
#ifndef __DEC32_DIG__
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define __DEC32_DIG__   __FLT_DECIMAL_DIG__
#endif
#ifndef FLT_DECIMAL_DIG
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define FLT_DECIMAL_DIG   __FLT_DECIMAL_DIG__
#endif
#ifndef DEC32_EPSILON
#   ifndef __DEC32_EPSILON__
/** Difference between 1.0 and the minimum decimal32 greater than 1.0 */
#      define __DEC32_EPSILON__   (1E-6DF)
/** Difference between 1.0 and the minimum decimal32 greater than 1.0 */
#      define DEC32_EPSILON   (1E-6DF)
#   else
/** Difference between 1.0 and the minimum decimal32 greater than 1.0 */
#      define DEC32_EPSILON   __DEC32_EPSILON__
#   endif
#endif
#ifndef DEC32_MIN_EXP
#   ifndef __DEC32_MIN_EXP__
/** Minimum int x such that 10**(x-1) is a normalised decimal32 */
#      define __DEC32_MIN_EXP__   (-94)
/** Minimum int x such that 10**(x-1) is a normalised decimal32 */
#      define DEC32_MIN_EXP   (-94)
#   else
/** Minimum int x such that 10**(x-1) is a normalised decimal32 */
#      define DEC32_MIN_EXP   __DEC32_MIN_EXP__
#   endif
#endif
#ifndef DEC32_MIN
#   ifndef __DEC32_MIN__
/** Minimum normalised decimal32 */
#      define __DEC32_MIN__   (1E-95DF)
/** Minimum normalised decimal32 */
#      define DEC32_MIN   (1E-95DF)
#   else
/** Minimum normalised decimal32 */
#      define DEC32_MIN   __DEC32_MIN__
#   endif
#endif
#ifndef DEC32_SUBNORMAL_MIN
#   ifndef __DEC32_SUBNORMAL_MIN__
/** Minimal subnormal decimal32 value */
#      define __DEC32_SUBNORMAL_MIN__   (0.000001E-95DF)
/** Minimal subnormal decimal32 value */
#      define DEC32_SUBNORMAL_MIN   __DEC32_SUBNORMAL_MIN__
#   else
/** Minimal subnormal decimal32 value */
#      define DEC32_SUBNORMAL_MIN   __DEC32_SUBNORMAL_MIN__
#   endif
#endif
#ifndef DEC32_DENORM_MIN
/** Minimal denormal decimal32 value */
#   define DEC32_DENORM_MIN   DEC32_SUBNORMAL_MIN
#endif
#ifndef DEC32_MAX_EXP
#   ifndef __DEC32_MAX_EXP__
/** Maximum int x such that 10**(x-1) is a representable decimal32 */
#      define __DEC32_MAX_EXP__   (97)
/** Maximum int x such that 10**(x-1) is a representable decimal32 */
#      define DEC32_MAX_EXP   (97)
#   else
/** Maximum int x such that 10**(x-1) is a representable decimal32 */
#      define DEC32_MAX_EXP   __DEC32_MAX_EXP__
#   endif
#endif
#ifndef DEC32_MAX
#   ifndef __DEC32_MAX__
/** The maximum representable finite decimal float */
#      define __DEC32_MAX__   (9.999999E96DF)
/** The maximum representable finite decimal float */
#      define DEC32_MAX   (9.999999E96DF)
#   else
/** The maximum representable finite decimal float */
#      define DEC32_MAX   __DEC32_MAX__
#   endif
#endif
#define DEC_MAX_DIGITS   999999999
#define DEC_MIN_DIGITS   1
#define DEC_MAX_EMAX   999999999
#define DEC_MIN_EMAX   0
#define DEC_MAX_EMIN   0
#define DEC_MIN_EMIN   -999999999
#define DECIMAL32_Bytes   4
/** Maximum precision (digits) */
#define DECIMAL32_Pmax   7
/** Maximum adjusted exponent */
#define DECIMAL32_Emax   96
/** Minimum adjusted exponent */
#define DECIMAL32_Emin   -95
/** Bias for the exponent */
#define DECIMAL32_Bias   101
/** Maximum string length, +1 */
#define DECIMAL32_String   15
#define DECIMAL32_Ehigh   (DECIMAL32_Emax + DECIMAL32_Bias - DECIMAL32_Pmax + 1)
#ifndef DECIMAL_NaN
/** 0 11111 00 NaN */
#   define DECIMAL_NaN   0x7c
/** 0 11111 10 sNaN */
#   define DECIMAL_sNaN   0x7e
/** 0 11110 00 Infinity */
#   define DECIMAL_Inf   0x78
#endif


// DECIMAL64 (DOUBLE) VALUES & PROPERTIES

#ifndef DEC64_RADIX
#   ifndef __DEC64_RADIX__
/** Radix of exponent representation */
#      define __DEC64_RADIX__   (10)
/** Radix of exponent representation */
#      define DEC64_RADIX   (10)
#   else
/** Radix of exponent representation */
#      define DEC64_RADIX   __DEC64_RADIX__
#   endif
#   ifndef _DEC64_RADIX
/** Radix of exponent representation */
#      define _DEC64_RADIX   DEC64_RADIX
#   endif
#endif
#ifndef DEC64_MANT_DIG
#   ifndef __DEC64_MANT_DIG__
/** Number of base-10 digits in the significand of a decimal64 */
#      define __DEC64_MANT_DIG__   (16)
/** Number of base-10 digits in the significand of a decimal64 */
#      define DEC64_MANT_DIG   (16)
#   else
/** Number of base-10 digits in the significand of a decimal64 */
#      define DEC64_MANT_DIG   __DEC64_MANT_DIG__
#   endif
#endif
#ifndef DEC64_DECIMAL_DIG
#   ifndef __DBL_DECIMAL_DIG__
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define __DBL_DECIMAL_DIG__   (17)
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define DEC64_DECIMAL_DIG   (17)
#   else
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#      define DEC64_DECIMAL_DIG   __DBL_DECIMAL_DIG__
#   endif
#endif
#ifndef __DEC64_DIG__
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define __DEC64_DIG__   __DBL_DECIMAL_DIG__
#endif
#ifndef DBL_DECIMAL_DIG
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define DBL_DECIMAL_DIG   __DBL_DECIMAL_DIG__
#endif
#ifndef DEC64_EPSILON
#   ifndef __DEC64_EPSILON__
/** Difference between 1.0 and the minimum decimal64 greater than 1.0 */
#      define __DEC64_EPSILON__   (1E-15DD)
/** Difference between 1.0 and the minimum decimal64 greater than 1.0 */
#      define DEC64_EPSILON   (1E-15DD)
#   else
/** Difference between 1.0 and the minimum decimal64 greater than 1.0 */
#      define DEC64_EPSILON   __DEC64_EPSILON__
#   endif
#endif
#ifndef DEC64_MIN_EXP
#   ifndef __DEC64_MIN_EXP__
/** Minimum int x such that 10**(x-1) is a normalised decimal64 */
#      define __DEC64_MIN_EXP__   (-382)
/** Minimum int x such that 10**(x-1) is a normalised decimal64 */
#      define DEC64_MIN_EXP   (-382)
#   else
/** Minimum int x such that 10**(x-1) is a normalised decimal64 */
#      define DEC64_MIN_EXP   __DEC64_MIN_EXP__
#   endif
#endif
#ifndef DEC64_MIN
#   ifndef __DEC64_MIN__
/** Minimum normalised decimal64 */
#      define __DEC64_MIN__   (1E-383DD)
/** Minimum normalised decimal64 */
#      define DEC64_MIN   (1E-383DD)
#   else
/** Minimum normalised decimal64 */
#      define DEC64_MIN   __DEC64_MIN__
#   endif
#endif
#ifndef DEC64_SUBNORMAL_MIN
#   ifndef __DEC64_SUBNORMAL_MIN__
/** Minimal subnormal decimal64 value */
#      define __DEC64_SUBNORMAL_MIN__   (0.000000000000001E-383DD)
/** Minimal subnormal decimal64 value */
#      define DEC64_SUBNORMAL_MIN   __DEC64_SUBNORMAL_MIN__
#   else
/** Minimal subnormal decimal64 value */
#      define DEC64_SUBNORMAL_MIN   __DEC64_SUBNORMAL_MIN__
#   endif
#endif
#ifndef DEC64_DENORM_MIN
/** Minimal denormal decimal64 value */
#   define DEC64_DENORM_MIN   DEC64_SUBNORMAL_MIN
#endif
#ifndef DEC64_MAX_EXP
#   ifndef __DEC64_MAX_EXP__
/** Maximum int x such that 10**(x-1) is a representable decimal32 */
#      define __DEC64_MAX_EXP__   (385)
/** Maximum int x such that 10**(x-1) is a representable decimal32 */
#      define DEC64_MAX_EXP   (385)
#   else
/** Maximum int x such that 10**(x-1) is a representable decimal32 */
#      define DEC64_MAX_EXP   __DEC64_MAX_EXP__
#   endif
#endif
#ifndef DEC64_MAX
#   ifndef __DEC64_MAX__
/** The maximum representable finite decimal double */
#      define __DEC64_MAX__   (9.999999999999999E384DD)
/** The maximum representable finite decimal double */
#      define DEC64_MAX   (9.999999999999999E384DD)
#   else
/** The maximum representable finite decimal double */
#      define DEC64_MAX   __DEC64_MAX__
#   endif
#endif


// DECIMAL128 (LONG DOUBLE) VALUES & PROPERTIES

#ifndef DEC128_RADIX
#   ifndef __DEC128_RADIX__
/** Radix of exponent representation */
#      define __DEC128_RADIX__   (10)
/** Radix of exponent representation */
#      define DEC128_RADIX   (10)
#   else
/** Radix of exponent representation */
#      define DEC128_RADIX   __DEC128_RADIX__
#   endif
#   ifndef _DEC128_RADIX
/** Radix of exponent representation */
#      define _DEC128_RADIX   DEC128_RADIX
#   endif
#endif
#ifndef DEC128_MANT_DIG
#   ifndef __DEC128_MANT_DIG__
/** Number of base-10 digits in the significand of a decimal128 */
#      define DEC128_MANT_DIG   (34)
/** Number of base-10 digits in the significand of a decimal128 */
#      define __DEC128_MANT_DIG__   (34)
#   else
/** Number of base-10 digits in the significand of a decimal128 */
#      define DEC128_MANT_DIG   __DEC128_MANT_DIG__
#   endif
#endif
#ifndef DEC128_DIG
#   ifndef __LDBL_DECIMAL_DIG__
#      ifdef __VFP_FP__
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#         define __LDBL_DECIMAL_DIG__   (17)
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#         define DEC128_DIG   (17)
#      else
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#         define __LDBL_DECIMAL_DIG__   (21)
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#         define DEC128_DIG   (21)
#      endif
#   endif
#else
#   ifndef __LDBL_DECIMAL_DIG__
#      define __LDBL_DECIMAL_DIG__   DEC128_DIG
#   endif
#endif
#ifndef __DEC128_DIG__
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define __DEC128_DIG__   DEC128_DIG
#endif
#ifndef LDBL_DECIMAL_DIG
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define LDBL_DECIMAL_DIG   DEC128_DIG
#endif
#ifndef DECIMAL_DIG
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define DECIMAL_DIG   DEC128_DIG
#endif
#ifndef __DECIMAL_DIG__
/** The number of decimal digits, n, such that any floating-point number with x radix y digits can be rounded to a floating-point number with n decimal digits and back again without changing the value */
#   define __DECIMAL_DIG__   DEC128_DIG
#endif
#ifndef DEC128_EPSILON
#   ifndef __DEC128_EPSILON__
/** Difference between 1.0 and the minimum decimal64 greater than 1.0 */
#      define __DEC128_EPSILON__   (1E-33DL)
/** Difference between 1.0 and the minimum decimal64 greater than 1.0 */
#      define DEC128_EPSILON   (1E-33DL)
#   else
/** Difference between 1.0 and the minimum decimal64 greater than 1.0 */
#      define DEC128_EPSILON   __DEC128_EPSILON__
#   endif
#endif
#ifndef DEC128_MIN_EXP
#   ifndef __DEC128_MIN_EXP__
/** Minimum int x such that 10**(x-1) is a normalised decimal128 */
#      define __DEC128_MIN_EXP__   (-6142)
/** Minimum int x such that 10**(x-1) is a normalised decimal128 */
#      define DEC128_MIN_EXP   (-6142)
#   else
/** Minimum int x such that 10**(x-1) is a normalised decimal128 */
#      define DEC128_MIN_EXP   __DEC128_MIN_EXP__
#   endif
#endif
#ifndef DEC128_MIN
#   ifndef __DEC128_MIN__
/** Minimum normalised decimal128 */
#      define __DEC128_MIN__   (1E-6143DL)
/** Minimum normalised decimal128 */
#      define DEC128_MIN   __DEC128_MIN__
#   else
/** Minimum normalised decimal128 */
#      define DEC128_MIN   __DEC128_MIN__
#   endif
#endif
#ifndef DEC128_SUBNORMAL_MIN
#   ifndef __DEC128_SUBNORMAL_MIN__
/** Minimal subnormal decimal64 value */
#      define __DEC128_SUBNORMAL_MIN__   (0.000000000000000000000000000000001E-6143DL)
/** Minimal subnormal decimal64 value */
#      define DEC128_SUBNORMAL_MIN   __DEC128_SUBNORMAL_MIN__
#   else
/** Minimal subnormal decimal64 value */
#      define DEC128_SUBNORMAL_MIN   __DEC128_SUBNORMAL_MIN__
#   endif
#endif
#ifndef DEC128_DENORM_MIN
/** Minimal denormal decimal128 value */
#   define DEC128_DENORM_MIN   DEC128_SUBNORMAL_MIN
#endif
#ifndef DEC128_MAX_EXP
#   ifndef __DEC128_MAX_EXP__
/** Maximum int x such that 10**(x-1) is a representable decimal128 */
#      define __DEC128_MAX_EXP__   (6145)
/** Maximum int x such that 10**(x-1) is a representable decimal128 */
#      define DEC128_MAX_EXP   __DEC128_MAX_EXP__
#   else
/** Maximum int x such that 10**(x-1) is a representable decimal128 */
#      define DEC128_MAX_EXP   __DEC128_MAX_EXP__
#   endif
#endif
#ifndef DEC128_MAX
#   ifndef __DEC128_MAX__
/** The maximum representable finite decimal double */
#      define __DEC128_MAX__   (9.999999999999999999999999999999999E6144DL)
/** The maximum representable finite decimal double */
#      define DEC128_MAX   __DEC128_MAX__
#   else
/** The maximum representable finite decimal double */
#      define DEC128_MAX   __DEC128_MAX__
#   endif
#endif


// MISCELLANEOUS DECIMAL-FLOAT VALUES

/** Sign; 1 = negative, 0 = positive, or zero */
#define DECNEG   0x80
/** 1 = Infinity */
#define DECINF   0x40
/** 1 = NaN */
#define DECNAN   0x20
/** 1 = sNaN */
#define DECSNAN   0x10
/** The remaining bits are reserved; they must be 0 */
#define DECSPECIAL   (DECINF | DECNAN | DECSNAN)
#define DECNUMDIGITS   1
/** Decimal Digits Per UNit */
#define DECDPUN   4
#if (DECDPUN <= 2)
#   define decNumberUnit   uint8_t
#elif (DECDPUN <= 4)
#   define decNumberUnit   uint16_t
#else
#   define decNumberUnit   uint32_t
#endif
/** The number of decNumberUnits we need is ceiling of DECNUMDIGITS/DECDPUN */
#define DECNUMUNITS   ((DECNUMDIGITS + DECDPUN - 1) / DECDPUN)
/** Conditional code flag for decimal floats; 0: best performance; 1: enable subset arithmetic */
#define DECSUBSET   0
enum dec_rounding {
	DEC_ROUND_CEILING,  // Round towards +infinity
	DEC_ROUND_UP,  // Round away from 0
	DEC_ROUND_HALF_UP,  // 0.5 rounds up/
	DEC_ROUND_HALF_EVEN,  // 0.5 rounds to nearest even
	DEC_ROUND_HALF_DOWN,  // 0.5 rounds down
	DEC_ROUND_DOWN,  // Round towards 0 (truncate)
	DEC_ROUND_FLOOR,  // Round towards -infinity
	DEC_ROUND_MAX  // Enum must be less than this
};
#define DEC_Conversion_syntax   1
#define DEC_Division_by_zero   2
#define DEC_Division_impossible   4
#define DEC_Division_undefined   8
#define DEC_Insufficient_storage   0x10
#define DEC_Inexact   0x20
#define DEC_Invalid_context   0x40
#define DEC_Invalid_operation   0x80
#if DECSUBSET
#   define DEC_Lost_digits   0x100
#endif
#define DEC_Overflow   0x200
#define DEC_Clamped   0x400
#define DEC_Rounded   0x800
#define DEC_Subnormal   0x1000
#define DEC_Underflow   0x2000
#define DEC_IEEE_854_Division_by_zero   (DEC_Division_by_zero)
#if DECSUBSET
#   define DEC_IEEE_854_Inexact   (DEC_Inexact | DEC_Lost_digits)
#else
#   define DEC_IEEE_854_Inexact   (DEC_Inexact)
#endif
#define DEC_IEEE_854_Invalid_operation   (DEC_Conversion_syntax | DEC_Division_impossible | DEC_Division_undefined | DEC_Insufficient_storage | DEC_Invalid_context | DEC_Invalid_operation)
#define DEC_IEEE_854_Overflow   (DEC_Overflow)
#define DEC_IEEE_854_Underflow   (DEC_Underflow)
#define DEC_Errors   (DEC_IEEE_854_Division_by_zero | DEC_IEEE_854_Invalid_operation | DEC_IEEE_854_Overflow | DEC_IEEE_854_Underflow)
#define DEC_NaNs   DEC_IEEE_854_Invalid_operation
#if DECSUBSET
#   define DEC_Information   (DEC_Clamped | DEC_Rounded | DEC_Inexact | DEC_Lost_digits)
#else
#   define DEC_Information   (DEC_Clamped | DEC_Rounded | DEC_Inexact)
#endif
#define DEC_Condition_CS   "Conversion syntax"
#define DEC_Condition_DZ   "Division by zero"
#define DEC_Condition_DI   "Division impossible"
#define DEC_Condition_DU   "Division undefined"
#define DEC_Condition_IE   "Inexact"
#define DEC_Condition_IS   "Insufficient storage"
#define DEC_Condition_IC   "Invalid context"
#define DEC_Condition_IO   "Invalid operation"
#if DECSUBSET
#   define DEC_Condition_LD   "Lost digits"
#endif
#define DEC_Condition_OV   "Overflow"
#define DEC_Condition_PA   "Clamped"
#define DEC_Condition_RO   "Rounded"
#define DEC_Condition_SU   "Subnormal"
#define DEC_Condition_UN   "Underflow"
#define DEC_Condition_ZE   "No status"
#define DEC_Condition_MU   "Multiple status"
#define DEC_Condition_Length   21
#define DEC_INIT_BASE   0
#define DEC_INIT_DECIMAL32   32
#define DEC_INIT_DECIMAL64   64
#define DEC_INIT_DECIMAL128   128
/* TODO: Add decimal functions
#define decContextDefault   __decContextDefault
#define decContextSetStatus   __decContextSetStatus
#define decContextStatusToString   __decContextStatusToString
#define decContextSetStatusFromString   __decContextSetStatusFromString
#define decNumberFromString   __decNumberFromString
#define decNumberToString   __decNumberToString
#define decNumberToEngString   __decNumberToEngString
#define decNumberAbs   __decNumberAbs
#define decNumberAdd   __decNumberAdd
#define decNumberCompare   __decNumberCompare
#define decNumberDivide   __decNumberDivide
#define decNumberDivideInteger   __decNumberDivideInteger
#define decNumberMax   __decNumberMax
#define decNumberMin   __decNumberMin
#define decNumberMinus   __decNumberMinus
#define decNumberMultiply   __decNumberMultiply
#define decNumberNormalize   __decNumberNormalize
#define decNumberPlus   __decNumberPlus
#define decNumberPower   __decNumberPower
#define decNumberQuantize   __decNumberQuantize
#define decNumberRemainder   __decNumberRemainder
#define decNumberRemainderNear   __decNumberRemainderNear
#define decNumberRescale   __decNumberRescale
#define decNumberSameQuantum   __decNumberSameQuantum
#define decNumberSquareRoot   __decNumberSquareRoot
#define decNumberSubtract   __decNumberSubtract
#define decNumberToIntegralValue   __decNumberToIntegralValue
#define decNumberCopy   __decNumberCopy
#define decNumberTrim   __decNumberTrim
#define decNumberVersion   __decNumberVersion
#define decNumberZero   __decNumberZero
*/

typedef struct attr_packed __decNumber {
	int32_t digits;  // Count of digits in the coefficient
	int32_t exponent;  // Unadjusted exponent
	uint8_t bits;  // Indicator bits
	decNumberUnit lsu[DECNUMUNITS];  // Coefficient, from least significant unit
} decNumber;


#define decNumberIsZero(dn)     (*(dn)->lsu == 0 && (dn)->digits == 1 && (((dn)->bits & DECSPECIAL) == 0))
#define decNumberIsNegative(dn)   (((dn)->bits & DECNEG) != 0)
#define decNumberIsNaN(dn)   (((dn)->bits & (DECNAN | DECSNAN)) !=0)
#define decNumberIsInfinite(dn)   (((dn)->bits & DECINF) != 0)


// MISCELLANEOUS VALUES (<floatio.h>)

#define FLOAT   float
#define DOUBLE   double
/** Max decimal digits in a 11-bit exponent (VAX G floating-point) is 308 decimal digits */
#define MAXEXP   (308)
/** Max decimal digits in a 128-bit fraction takes up 39 decimal digits */
#define MAXFRACT   (39)
/** MAXEXPDIG is the maximum number of decimal digits needed to store a floating-point exponent in the largest supported format; It should be ceil(log10(LDBL_MAX_10_EXP)) or (if hexadecimal floating-point conversions are supported) ceil(log10(LDBL_MAX_EXP)) */
#define MAXEXPDIG   (6)
/** Zero-initialization; Used to avoid warnings */
#define _FP_ZERO_INIT   0
/** For the Bessel functions (j0, j1, jn, y0, y1, yn) this option defines the maximum absolute value of the ordinate before we assume total loss of significance */
#define X_TLOSS   (1.41484755040568800000e+16)
/** SVID mode specifies returning this large value instead of infinity */
#define SVID_HUGE   (3.40282347e+38F)
/** Alias for FLT_MAX_EXP */
#define FMAXEXP   FLT_MAX_EXP
/** Alias for FLT_MIN_EXP */
#define FMINEXP   FLT_MIN_EXP
/** Alias for DBL_MAX_EXP */
#define DMAXEXP   DBL_MAX_EXP
/** Alias for DBL_MIN_EXP */
#define DMINEXP   DBL_MIN_EXP
/** Alias for LDBL_MAX_EXP */
#define LDMAXEXP   LDBL_MAX_EXP
/** Alias for LDBL_MIN_EXP */
#define LDMINEXP   LDBL_MIN_EXP
/** X/Open requires MAXFLOAT (Alias for FLT_MAX; Same value as SVID's HUGE) */
#define MAXFLOAT   FLT_MAX
/** Alias for FLT_MIN */
#define MINFLOAT   FLT_MIN
/** Alias for DBL_MAX */
#define MAXDOUBLE   DBL_MAX
/** Alias for DBL_MIN */
#define MINDOUBLE   DBL_MIN
/** Alias for LDBL_MAX */
#define MAXLONGDOUBLE   LDBL_MAX
/** Alias for LDBL_MIN */
#define MINLONGDOUBLE   LDBL_MIN
#define FLT_MAX_10_EXP_LOG   5
#define DBL_MAX_10_EXP_LOG   8
#if (SUPPORTS_LONG_DOUBLE && (__LDBL_MAX_EXP__ > 1024))
#   define LDBL_MAX_10_EXP_LOG   12
#   define FPIOCONST_POW10_ARRAY_SIZE   15
#elif (SUPPORTS_LONG_DOUBLE && (__LDBL_MAX_EXP__ == 1024))
#   define LDBL_MAX_10_EXP_LOG   8
#   define FPIOCONST_POW10_ARRAY_SIZE   11
#endif
#if (BITS_PER_MP_LIMB == 32)
/** Offset of the constants in the array `_fpioconst_pow10` */
#   define _FPIO_CONST_OFFSET   2
#else
/** Offset of the constants in the array `_fpioconst_pow10` */
#   define _FPIO_CONST_OFFSET   1
#endif
/** Offset of the constants in the array `_fpioconst_pow10` */
#define FPIO_CONST_OFFSET   _FPIO_CONST_OFFSET
/** Checks if a fpmax_t is either 0 or +/- infinity */
#define __FPMAX_ZERO_OR_INF_CHECK(x)   ((x) == ((x) >> 2))
#ifdef _FLT_LARGEST_EXPONENT_IS_NORMAL
/** True if a positive float with bitmask X is finite */
#   define FLT_UWORD_IS_FINITE(x)   1
/** True if a positive float with bitmask X is not a number */
#   define FLT_UWORD_IS_NAN(x)   0
/** True if a positive float with bitmask X is +infinity */
#   define FLT_UWORD_IS_INFINITE(x)   0
#   define FLT_UWORD_MAX   0x7fffffff
/** The bitmask of the largest finite exponent (129 if the largest exponent is used for finite numbers, 128 otherwise) */
#   define FLT_UWORD_EXP_MAX   0x43010000
/** The bitmask of log(FLT_MAX), rounded down; This value is the largest input that can be passed to exp() without producing overflow */
#   define FLT_UWORD_LOG_MAX   0x42b2d4fc
/** The bitmask of log(2*FLT_MAX), rounded down; This value is the largest input than can be passed to cosh() without producing overflow */
#   define FLT_UWORD_LOG_2MAX   0x42b437e0
#else
/** True if a positive float with bitmask X is finite */
#   define FLT_UWORD_IS_FINITE(x)   ((x) < 0x7f800000L)
/** True if a positive float with bitmask X is not a number */
#   define FLT_UWORD_IS_NAN(x)   ((x) > 0x7f800000L)
/** True if a positive float with bitmask X is +infinity */
#   define FLT_UWORD_IS_INFINITE(x)   ((x) == 0x7f800000L)
#   define FLT_UWORD_MAX   0x7f7fffffL
/** The bitmask of the largest finite exponent (129 if the largest exponent is used for finite numbers, 128 otherwise) */
#   define FLT_UWORD_EXP_MAX   0x43000000
/** The bitmask of log(FLT_MAX), rounded down; This value is the largest input that can be passed to exp() without producing overflow */
#   define FLT_UWORD_LOG_MAX   0x42b17217
/** The bitmask of log(2*FLT_MAX), rounded down; This value is the largest input than can be passed to cosh() without producing overflow */
#   define FLT_UWORD_LOG_2MAX   0x42b2d4fc
#endif
/** The bitmask of FLT_MAX/2 */
#define FLT_UWORD_HALF_MAX   (FLT_UWORD_MAX - (1L << 23))
/** The largest biased exponent that can be used for finite numbers (255 if the largest exponent is used for finite numbers, 254 otherwise) */
#define FLT_LARGEST_EXP   (FLT_UWORD_MAX >> 23)
#ifdef _FLT_NO_DENORMALS
/** True if a positive float with bitmask X is +0; Without denormals, any float with a zero exponent is a +0 representation; With denormals, the only +0 representation is a 0 bitmask */
#   define FLT_UWORD_IS_ZERO(x)   ((x) < 0x800000L)
/** True if a non-zero positive float with bitmask X is subnormal (Routines should check for zeros first) */
#   define FLT_UWORD_IS_SUBNORMAL(x)   0
/** The bitmask of the smallest float above +0 */
#   define FLT_UWORD_MIN   0x800000
/** The bitmask of the float representation of REAL_FLT_MIN's exponent */
#   define FLT_UWORD_EXP_MIN   0x42fc0000
/** The bitmask of |log(REAL_FLT_MIN)|, rounding down */
#   define FLT_UWORD_LOG_MIN   0x42aeac50
/** REAL_FLT_MIN's exponent - EXP_BIAS (1 if denormals are not supported, -22 if they are) */
#   define FLT_SMALLEST_EXP   1
#else
/** True if a positive float with bitmask X is +0; Without denormals, any float with a zero exponent is a +0 representation; With denormals, the only +0 representation is a 0 bitmask */
#   define FLT_UWORD_IS_ZERO(x)   ((x) == 0)
/** True if a non-zero positive float with bitmask X is subnormal (Routines should check for zeros first) */
#   define FLT_UWORD_IS_SUBNORMAL(x)   ((x) < 0x800000L)
/** The bitmask of the smallest float above +0 */
#   define FLT_UWORD_MIN   1
/** The bitmask of the float representation of REAL_FLT_MIN's exponent */
#   define FLT_UWORD_EXP_MIN   0x43160000
/** The bitmask of |log(REAL_FLT_MIN)|, rounding down */
#   define FLT_UWORD_LOG_MIN   0x42cff1b5
/** REAL_FLT_MIN's exponent - EXP_BIAS (1 if denormals are not supported, -22 if they are) */
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
#if ((!defined(__FLT_EVAL_METHOD__)) && defined(SUPPORTS_LONG_DOUBLE))  // ix87 FPU default
/** Specifies the precision in which all floating-point arithmetic operations (other than assignment and cast) are performed

Values
 - Negative (except -1): Implementation-defined behavior
 - -1: The default precision is not known
 - 0: All operations and constants evaluate in the range and precision of the type used. Additionally, float_t and double_t are equivalent to `float` and `double`, respectively
 - 1: All operations and constants evaluate in the range and precision of double, and float_t and double_t are equivalent to `double`
 - 2: All operations and constants evaluate in the range and precision of long double, so float_t and double_t are equivalent to `long double`
*/
#   define __FLT_EVAL_METHOD__   (2)
#elif (!defined(__FLT_EVAL_METHOD__))
#   define __FLT_EVAL_METHOD__   (0)
#endif
#if (__FLT_EVAL_METHOD__ == 0)
#   define float_t   float
#   define double_t   double
/** Specifies the precision in which all floating-point arithmetic operations (other than assignment and cast) are performed */
#   define FLT_EVAL_METHOD   (0)
#elif (__FLT_EVAL_METHOD__ == 1)
#   define float_t   double
#   define double_t   double
#   define FLT_EVAL_METHOD   (1)
#elif (__FLT_EVAL_METHOD__ == 2)
#   define float_t   long double
#   define double_t   long double
#   define FLT_EVAL_METHOD   (2)
#elif (__FLT_EVAL_METHOD__ < 0)
#   error   "FLT_EVAL_METHOD is lss than 0!"
#else
#   error   "FLT_EVAL_METHOD is unspecified!"
#endif
#if (SUPPORTS_LONG_DOUBLE && (!defined(__long_double_t)))
#   define __long_double_t   long double
#endif
#if (SUPPORTS_LONG_DOUBLE && (!defined(long_double_t)))
#   define long_double_t   long double
#endif
/** 80 bit MacOS float: 1 sign bit, 15 exponent bits, 1 integer bit, 63 fraction bits */
typedef struct Float80 { int16_t exp; uint16_t man[4]; }   Float80;
/** 96 bit 68881 float: 1 sign bit, 15 exponent bits, 16 pad bits, 1 integer bit, 63 fraction bits */
typedef struct Float96 {
	int16_t exp[2];  // The second 16-bits are undefined
	uint16_t man[4];
} Float96;
typedef struct Float32Point { float x, y; }   Float32Point;
typedef union FPdbleword {
	double x;
#   if IS_BIG_ENDIAN
	struct double_words { unsigned int hi, lo; } double_words;
#   elif IS_LITTLE_ENDIAN
	struct double_words { unsigned int lo, hi; } double_words;
#   endif
} FPdbleword_t;
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
#if (FLT_EVAL_METHOD == 0 || FLT_EVAL_METHOD == 1)
#   define EPS   DBL_EPSILON
#elif (FLT_EVAL_METHOD == 2)
#   define EPS   LDBL_EPSILON
#endif


union float_long { float f; long l; };


union double_long {
	double d;
#ifdef SWAP  // Define SWAP for 386/960 reverse-byte-order brain-damaged CPUs
	struct {
		unsigned long lower;
		long upper;
	} l;
#else
	struct {
		long upper;
		unsigned long lower;
	} l;
#endif
	long long ll;
};


// FPMAX_T & FPMAX_*

#ifdef LDBL_MANT_DIG
/** Float-point datatype that is equivalent to the largest float-point datatype supported by the target system */
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
/** Float-point datatype that is equivalent to the largest float-point datatype supported by the target system */
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
/** Float-point datatype that is equivalent to the largest float-point datatype supported by the target system */
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


#endif  // FLOAT_H


// SUN RPC ADDITIONS TO <sys/types.h>

#ifndef __dontcare__
#   define __dontcare__   (-1)
#endif
#ifndef dontcare
#   define dontcare   (-1)
#endif
typedef int   bool_t;
typedef int   enum_t;
typedef uint32_t   rpcprog_t;
typedef uint32_t   rpcvers_t;
typedef uint32_t   rpcproc_t;
typedef uint32_t   rpcprot_t;
typedef uint32_t   rpcport_t;
typedef int32_t   rpc_inline_t;
/** The netbuf structure is used for transport-independent address storage */
typedef struct netbuf { unsigned int maxlen, len; void* buf; }   netbuf_t;
/** The format of the address and options arguments of the XTI t_bind call; Only provided for compatibility, it should not be used */
typedef struct attr_packed t_bind { struct netbuf addr; unsigned int qlen; }   t_bind_t;
/** Used with rpcbind */
typedef struct rpc_sockinfo { int si_af, si_proto, si_socktype, si_alen; }   rpc_sockinfo_t;


// NULL POINTER DATATYPES

#if IS_CPLUSPLUS_2011
#   ifndef _GXX_NULLPTR_T
#      define _GXX_NULLPTR_T   (1)
typedef decltype(nullptr)   nullptr_t;
#   endif
#endif
#if IS_NOT_CPLUSPLUS
/** NULL char pointer */
#   define NULL_CHAR   ((char*)0)
/** NULL unsigned char pointer */
#   define NULL_UNSIGNED_CHAR   ((unsigned char*)0)
/** NULL short pointer */
#   define NULL_SHORT   ((short*)0)
/** NULL unsigned short pointer */
#   define NULL_UNSIGNED_SHORT   ((unsigned short*)0)
/** NULL int pointer */
#   define NULL_INT   ((int*)0)
/** NULL unsigned int pointer */
#   define NULL_UNSIGNED_INT   ((unsigned int*)0)
/** NULL long pointer */
#   define NULL_LONG   ((long*)0)
/** NULL unsigned long pointer */
#   define NULL_UNSIGNED_LONG   ((unsigned long*)0)
/** NULL long long pointer */
#   define NULL_LONG_LONG   ((long long*)0)
/** NULL unsigned long long pointer */
#   define NULL_UNSIGNED_LONG_LONG   ((unsigned long long*)0)
/** NULL int8_t pointer */
#   define NULL_INT8_T   ((int8_t*)0)
/** NULL int16_t pointer */
#   define NULL_INT16_T   ((int16_t*)0)
/** NULL int32_t pointer */
#   define NULL_INT32_T   ((int32_t*)0)
/** NULL int64_t pointer */
#   define NULL_INT64_T   ((int64_t*)0)
/** NULL float pointer */
#   define NULL_FLOAT   ((float*)0)
/** NULL double pointer */
#   define NULL_DOUBLE   ((double*)0)
/** NULL long double pointer */
#   define NULL_LONG_DOUBLE   ((long double*)0)
#   ifdef SUPPORTS_DECIMAL_FLOATS
/** NULL decimal32 pointer */
#      define NULL_DECIMAL32   ((decimal32*)0)
/** NULL decimal64 pointer */
#      define NULL_DECIMAL64   ((decimal64*)0)
#   endif
#endif


// VECTOR DATATYPES


// Character Vectors
#if (SIZEOF_CHAR == 1)
/** Sixteen-signed-char vector */
typedef signed char VECTOR16   xSChar;
/** Sixteen-unsigned-char vector */
typedef unsigned char VECTOR16   xUChar;
#endif
/** Sixteen-char8_t vector */
typedef char8_t VECTOR16   xChar8_t;
/** Eight-char16_t vector */
typedef char16_t VECTOR16   xChar16_t;
/** Four-char32_t vector */
typedef char32_t VECTOR16   xChar32_t;
// Integral Vectors
/** Vector datatype of four single-byte (8-bit) integers */
typedef int8_t VECTOR4   __V4QI;
#define __v4qi   __V4QI
#define V4QI   __V4QI
#define V4QItype   __V4QI
/** Vector datatype of eight single-byte (8-bit) integers */
typedef int8_t VECTOR8   __V8QI;
#define __v8qi   __V8QI
#define V8QI   __V8QI
#define V8QItype   __V8QI
/** Sixteen-int8_t vector */
typedef int8_t VECTOR16   xSInt8;
/** Sixteen-uint8_t vector */
typedef uint8_t VECTOR16   xUInt8;
/** Four-int16_t vector */
typedef int16_t VECTOR8   __V4HI;
#define __v4hi   __V4HI
#define V4HI   __V4HI
#define V4HItype   __V4HI
/** Eight-int16_t vector */
typedef int16_t VECTOR16   xSInt16;
/** Eight-uint16_t vector */
typedef uint16_t VECTOR16   xUInt16;
/** Vector datatype of two 32-bit integers */
typedef int32_t VECTOR8   __V2SI;
#define __v2si   __V2SI
#define V2SI   __V2SI
#define V2SItype   __V2SI
/** Vector datatype of four 32-bit integers */
typedef int32_t VECTOR16   __V4SI;
#define __v4si   __V4SI
#define V4SI   __V4SI
#define V4SItype   __V4SI
/** Four-int32_t vector */
typedef int32_t VECTOR16   xSInt32;
/** Four-uint32_t vector */
typedef uint32_t VECTOR16   xUInt32;
/** Two-int64_t vector */
typedef int64_t VECTOR16   xSInt64;
/** Two-uint64_t vector */
typedef uint64_t VECTOR16   xUInt64;
// Float-Point Vectors
/** Two-float vector */
typedef float VECTOR8   __m64;
/** Four-float vector */
typedef float VECTOR16   xFloat;
/** Four-float vector */
#define V4SF   xFloat
/** Four-float vector */
#define __v4sf   xFloat
/** Four-float vector */
#define __m128   xFloat
/** Two-double vector */
typedef double VECTOR16   xDouble;
#if SUPPORTS_DECIMAL_FLOATS
/** Four-decimal-float vector */
typedef decimal32 VECTOR16   xDecimal32;
/** Two-decimal-double vector */
typedef decimal64 VECTOR16   xDecimal64;
#   if SUPPORTS_DECIMAL128
/** Two-decimal-double vector */
typedef decimal128 VECTOR32   xDecimal128;
#   endif
#endif
/** Single/One double */
typedef double   DoubleConstant_sd;
/** Packed double (two-double vector) */
typedef xDouble   DoubleConstant_pd;


// VOLATILE DATATYPES

typedef volatile signed char   vchar_t;
typedef volatile signed short   vshort_t;
typedef volatile signed int   vint_t;
typedef volatile signed long   vlong_t;
#define vlong   vlong_t
#define p9vlong   vlong_t
#define _utfvlong   vlong_t
#define utfvlong   vlong_t
typedef volatile signed long long   vlonglong_t;
typedef volatile int8_t   vint8_t;
typedef volatile int16_t   vint16_t;
typedef volatile int32_t   vint32_t;
typedef volatile int64_t   vint64_t;
#if SUPPORTS_INT128
typedef volatile int128_t   vint128_t;
#endif
#if SUPPORTS_INT256
typedef volatile int256_t   vint256_t;
#endif
#if SUPPORTS_INT512
typedef volatile int512_t   vint512_t;
#endif
typedef volatile unsigned char   vuchar_t;
typedef volatile unsigned short   vushort_t;
typedef volatile unsigned int   vuint_t;
typedef volatile unsigned long   vulong_t;
#define uvlong   vulong_t
#define p9uvlong   vulong_t
#define _utfuvlong   vulong_t
#define utfuvlong   vulong_t
#define vulong   vulong_t
typedef volatile unsigned long long   vulonglong_t;
typedef volatile uint8_t   vuint8_t;
typedef volatile uint16_t   vuint16_t;
typedef volatile uint32_t   vuint32_t;
typedef volatile uint64_t   vuint64_t;
#if SUPPORTS_UINT128
typedef volatile uint128_t   vuint128_t;
#endif
#if SUPPORTS_UINT256
typedef volatile uint256_t   vuint256_t;
#endif
#if SUPPORTS_UINT512
typedef volatile uint512_t   vuint512_t;
#endif
// Volatile Floats
typedef volatile float   vfloat_t;
typedef volatile double   vdouble_t;
#if SUPPORTS_FLOAT80
typedef volatile float80   vfloat80_t;
#endif
#if SUPPORTS_FLOAT96
typedef volatile float96   vfloat96_t;
#endif
#if SUPPORTS_FLOAT128
typedef volatile float128   vfloat128_t;
#endif
#if SUPPORTS_LONG_DOUBLE
typedef volatile long double   vlongdouble_t;
#endif
#if SUPPORTS_DECIMAL_FLOATS
typedef volatile decimal32   vdecimal32_t;
typedef volatile decimal64   vdecimal64_t;
#   if SUPPORTS_DECIMAL128
typedef volatile decimal128   vdecimal128_t;
#   endif
#endif
// STDFIX Volatile Datatypes
#if SUPPORTS_STDFIX
typedef volatile _Accum   vaccum_t;
typedef volatile _Fract   vfract_t;
typedef volatile fx_t   vfx_t;
typedef volatile satfx_t   vsatfx_t;
typedef volatile fx_hr_t   vfx_hr_t;
typedef volatile fx_r_t   vfx_r_t;
typedef volatile fx_lr_t   vfx_lr_t;
typedef volatile fx_llr_t   vfx_llr_t;
typedef volatile fx_uhr_t   vfx_uhr_t;
typedef volatile fx_ur_t   vfx_ur_t;
typedef volatile fx_ulr_t   vfx_ulr_t;
typedef volatile fx_ullr_t   vfx_ullr_t;
typedef volatile fx_hk_t   vfx_hk_t;
typedef volatile fx_k_t   vfx_k_t;
typedef volatile fx_lk_t   vfx_lk_t;
typedef volatile fx_llk_t   vfx_llk_t;
typedef volatile fx_uhk_t   vfx_uhk_t;
typedef volatile fx_uk_t   vfx_uk_t;
typedef volatile fx_ulk_t   vfx_ulk_t;
typedef volatile fx_ullk_t   vfx_ullk_t;
#endif
// Miscellaneous Volatile Datatypes
typedef volatile size_t   vsize_t;
typedef volatile ssize_t   vssize_t;
typedef volatile clock_t   vclock_t;
typedef volatile clockid_t   vclockid_t;
typedef volatile socklen_t   vsocklen_t;
typedef volatile dev_t   vdev_t;
typedef volatile id_t   vid_t;
typedef volatile gid_t   vgid_t;
typedef volatile pid_t   vpid_t;


// VIRTIO DATATYPES

typedef uint8_t   virtio8;
#define __virtio8   virtio8
#define virtio8_t   virtio8
#define __virtio8_t   virtio8
typedef uint16_t   virtio16;
#define __virtio16   virtio16
#define virtio16_t   virtio16
#define __virtio16_t   virtio16
typedef uint32_t   virtio32;
#define __virtio32   virtio32
#define virtio32_t   virtio32
#define __virtio32_t   virtio32
typedef uint64_t   virtio64;
#define __virtio64   virtio64
#define virtio64_t   virtio64
#define __virtio64_t   virtio64


// ASSEMBLY DATATYPES

#define __force   (1)
#ifdef ALPHA
typedef uint32_t   umode_t;
#else
typedef uint16_t   umode_t;
#endif
#if (defined(S390) || IS_WORDSIZE_64)
typedef unsigned long   kernel_size_t;
#else
typedef uint32_t   kernel_size_t;
#endif
#define __kernel_size_t   kernel_size_t


// CONVENIENCE DATATYPES

#define s8   signed char
#define u8   unsigned char
/** Sys V compatibility */
#define unchar   unsigned char
#define mpdigit   unsigned int
/** Alias for "signed long" */
#define slint   signed long
/** Alias for "signed long long" */
#define sllint   signed long long
/** Alias for "unsigned long" */
#define ulint   unsigned long
/** Alias for "unsigned long long" */
#define ullint   unsigned long long
/** Alias for "float" */
#define single   float


// FUNCTION-SPECIFIC DATATYPES

#define strtol_t   long
#define __strtol_t   long
#define strtoll_t   long long
#define __strtoll_t   long long
#define strtoul_t   unsigned long
#define __strtoul_t   unsigned long
#define strtoull_t   unsigned long long
#define __strtoull_t   unsigned long long


// MALLOC-SPECIFIC DATATYPES

#ifndef malloc_size_t
#   define malloc_size_t   size_t
#endif
#ifndef __malloc_size_t
#   define __malloc_size_t   size_t
#endif
#ifndef malloc_ptrdiff_t
#   define malloc_ptrdiff_t   ptrdiff_t
#endif
#ifndef __malloc_ptrdiff_t
#   define __malloc_ptrdiff_t   ptrdiff_t
#endif
#define malloc_ptr_t   char*
#define __malloc_ptr_t   char*
typedef struct chunk {
	size_t psize, csize;
	struct chunk *next, *prev;
} chunk_t;
/** memalign entry datatype */
typedef struct memalign_ea {
	unsigned int memptr;
	unsigned int pad0[3];
	unsigned long long align;
	unsigned int pad1[2];
	unsigned long long size;
	unsigned int pad2[2];
} memalign_ea_t;
/** SVID2/XPG mallinfo structure */
typedef struct mallinfo {
	int arena;  // Total space allocated from system
	int ordblks;  // Number of non-inuse chunks
	int smblks;  // Unused; always zero
	int hblks;  // Number of mmapped regions
	int hblkhd;  // Total space in mmapped regions
	int usmblks;  // Unused; always zero
	int fsmblks;  // Unused; always zero
	int uordblks;  // Total allocated space
	int fordblks;  // Total non-inuse space
	int keepcost;  // Top-most, releasable (via malloc_trim) space
} mallinfo_t;
typedef struct freelist_entry {
	size_t size;
	struct freelist_entry* next;
} *fle;
typedef struct realloc_ea {
	unsigned long long ptr;
	unsigned int pad0[2];
	unsigned long long size;
	unsigned int pad1[2];
} realloc_ea_t;
/** malloc memory chunk struct (malloc_chunk) and datatype (malloc_t) */
typedef struct malloc_chunk {
	size_t prev_size;  // Size of previous chunk (if free)
	size_t size;  // Size in bytes, including overhead
	struct malloc_chunk* fd;  // double links; used only if free
	struct malloc_chunk* bk;
} malloc_t;
typedef struct malloc_chunk*   mchunkptr;
typedef struct malloc_chunk*   mbinptr;
/** alloc() block datatype */
typedef struct _alloc_ { void* next; size_t size; }   alloc_t;
#define __alloc_t   alloc_t
#define SIZEOF_ALLOC_T   (SIZEOF_SIZE_T + SIZEOF_POINTER)
/** A simple linked list of allocated memory regions */
typedef struct memnode_s {
	void* aligned_ptr;
	info_t info;
	struct memnode_s* next;
} memnode_t;


// NUMBER PAIRS & TRIPLETS

/** Pair of doubles */
typedef struct doublepair { double x, y; }   doublepair_t;
/** Pair of floats */
typedef struct floatpair { float x, y; }   floatpair_t;
/** Pair of long doubles */
typedef struct longdoublepair { long double x, y; }   longdoublepair_t;
/** Pair of uint8_t integers */
typedef struct bytepair { uint8_t x, y; }   bytepair_t;
/** Pair of signed integers */
typedef struct intpair { signed int x, y; }   intpair_t;
/** Pair of long signed integers */
typedef struct slintpair { slint x, y; }   slintpair_t;
/** Pair of long unsigned integers */
typedef struct ulintpair { ulint x, y; }   ulintpair_t;
/** Pair of long long unsigned integers */
typedef struct ullintpair { ullint x, y; }   ullintpair_t;
/** Pair of long long signed integers */
typedef struct sllintpair { sllint x, y; }   sllintpair_t;
/** Group of three doubles */
typedef struct doubletriplet { double x, y, z; }   doubletriplet_t;
/** Group of three floats */
typedef struct floattriplet { float x, y, z; }   floattriplet_t;
#ifndef INT128_UNSUPPORTED
/** Pair of int128_t integers */
typedef struct int128pair { int128_t x, y; }   int128pair_t;
/** Group of three int128_t integers */
typedef struct int128triplet { int128_t x, y, z; }   int128triplet_t;
#endif
#ifndef UINT128_UNSUPPORTED
/** Pair of uint128_t integers */
typedef struct uint128pair { uint128_t x, y; }   uint128pair_t;
/** Group of three uint128_t integers */
typedef struct uint128triplet { uint128_t x, y, z; }   uint128triplet_t;
#endif
#ifndef FLOAT128_UNSUPPORTED
/** Pair of 128-bit floats */
typedef struct float128pair { float128 x, y; }   float128pair_t;
/** Group of three 128-bit floats */
typedef struct float128triplet { float128 x, y, z; }   float128triplet_t;
#endif


// STANDARD QNX DATATYPES (Originally by Richard Frowijn)

typedef uint8_t   qnx4_ftype_t;
typedef uint16_t   qnx4_nxtnt_t;
typedef uint16_t   qnx4_mode_t;
typedef uint16_t   qnx4_muid_t;
typedef uint16_t   qnx4_mgid_t;
typedef uint16_t   qnx4_nlink_t;
typedef uint32_t   qnx4_off_t;
typedef struct qnx4_xtnt { uint32_t xtnt_blk, xtnt_size; }   qnx4_xtnt_t;


// BSD DATATYPES

/** Queue Element Datatype/Structure */
typedef struct qelem {
	struct qelem* q_forw;
	struct qelem* q_back;
	char* q_data;
} qelem_t;


// DARWIN DATATYPES

/** arg type for ctype functions */
#define ct_rune_t   int
/** arg type for ctype functions */
#define __ct_rune_t   int
/** arg type for ctype functions */
#define darwin_ct_rune_t   ct_rune_t
/** arg type for ctype functions */
#define __darwin_ct_rune_t   ct_rune_t
/** pid_t, gid_t, or uid_t datatype */
#define darwin_id_t   id_t
/** pid_t, gid_t, or uid_t datatype */
#define __darwin_id_t   id_t
/** Process and group ID datatype */
#define darwin_gid_t   gid_t
/** Process and group ID datatype */
#define __darwin_gid_t   gid_t
/** User ID datatype */
#define darwin_uid_t   uid_t
/** User ID datatype */
#define __darwin_uid_t   uid_t
/** Process ID datatype */
#define darwin_pid_t   pid_t
/** Process ID datatype */
#define __darwin_pid_t   pid_t
#define darwin_clock_t   clock_t
#define __darwin_clock_t   clock_t
#define darwin_suseconds_t   suseconds_t
#define __darwin_suseconds_t   suseconds_t
#define darwin_useconds_t   useconds_t
#define __darwin_useconds_t   useconds_t
#define darwin_time_t   time_t
#define __darwin_time_t   time_t
/** 32-bit time structure with seconds and microseconds */
typedef struct timeval32 { int32_t tv_sec, tv_usec; }   timeval32_t;
#define STRUCT_TIMEVAL32   struct timeval32
#define _STRUCT_TIMEVAL32   struct timeval32
/** 64-bit time structure with seconds and microseconds */
typedef struct timeval64 { int64_t tv_sec, tv_usec; }   timeval64_t;
#define STRUCT_TIMEVAL64   struct timeval64
#define _STRUCT_TIMEVAL64   struct timeval64
#define fssh_dev_t   dev_t
#define darwin_dev_t   dev_t
#define __darwin_dev_t   dev_t
/** Total blocks datatype */
#define darwin_blkcnt_t   blkcnt_t
/** Total blocks datatype */
#define __darwin_blkcnt_t   blkcnt_t
/** Preferred block size datatype */
#define darwin_blksize_t   blksize_t
/** Preferred block size datatype */
#define __darwin_blksize_t   blksize_t
#define darwin_fsblkcnt_t   fsblkcnt_t
#define __darwin_fsblkcnt_t   fsblkcnt_t
#define darwin_fsfilcnt_t   fsfilcnt_t
#define __darwin_fsfilcnt_t   fsfilcnt_t
/** Datatype used for file sizes */
#define darwin_off_t   off_t
/** Datatype used for file sizes */
#define __darwin_off_t   off_t
/** Inode number datatype */
#define darwin_ino_t   ino_t
/** Inode number datatype */
#define __darwin_ino_t   ino_t
/** 64-bit inode number datatype */
#define darwin_ino64_t   ino64_t
/** 64-bit inode number datatype */
#define __darwin_ino64_t   ino64_t
#define darwin_mode_t   mode_t
#define __darwin_mode_t   mode_t
#define darwin_intptr_t   intptr_t
#define __darwin_intptr_t   intptr_t
/** Signal set datatype */
#define darwin_sigset_t   sigset_t
/** Signal set datatype */
#define __darwin_sigset_t   sigset_t
/** Input port datatype */
typedef uint16_t   in_port_t;
/** Socket datatype */
typedef unsigned int   darwin_socklen_t;
#define __darwin_socklen_t   darwin_socklen_t
#define KAUTH_GUID_SIZE   16
/** Apple-style globally unique identifier */
typedef struct apple_guid { unsigned char g_guid[KAUTH_GUID_SIZE]; }   guid_t;
typedef unsigned char   uuid_t[16];
typedef char   uuid_string_t[37];
#define darwin_uuid_t   uuid_t
#define __darwin_uuid_t   uuid_t
#define _UUID_T   uuid_t
#define darwin_uuid_string_t   uuid_string_t
#define __darwin_uuid_string_t   uuid_string_t
#define _UUID_STRING_T   uuid_string_t


// MACH DATATYPES

#define VM_TAG_BT   1
#define VM_TAG_KMOD   2
#define VM_TAG_UNLOAD   4
/** Implement the legacy 32-bit VM APIs published by the kernel */
#define VM32_SUPPORT   1
/** Max array size */
#define SAMPLE_MAX  256
typedef float   MACH_MSG_TYPE_REAL_32;
typedef double   MACH_MSG_TYPE_REAL_64;
typedef uint32_t   mach_port_t;
/** In user-space, "rights" are represented by the name of the right in the Mach port namespace */
#define __darwin_mach_port_t   mach_port_t
#define darwin_mach_port_t   mach_port_t
#define __mach_port_t   mach_port_t
#define MSG_TYPE_PORT_NAME  natural_t
typedef uint32_t   MACH_MSG_TYPE_COPY_SEND;
/** Use addr64_t for 64-bit addresses that are used on both 32 and 64-bit machines; On PPC, they are passed and returned as two adjacent 32-bit GPRs; Use addr64_t in places where common code must be useable both on 32 and 64-bit machines */
typedef uint64_t   addr64_t;
/** To minimize the use of 64-bit fields, keep some physical addresses (that are page aligned) as 32-bit page numbers; This limits the physical address space to 16TB of RAM */
typedef uint32_t   ppnum_t;
#if IS_WORDSIZE_64
/** Use reg64_t for addresses that are 32 bits on a 32-bit machine, and 64 bits on a 64-bit machine, but are always passed and returned in a single GPR on PPC */
typedef uint64_t    reg64_t;
#else
/** Use reg64_t for addresses that are 32 bits on a 32-bit machine, and 64 bits on a 64-bit machine, but are always passed and returned in a single GPR on PPC */
typedef uint32_t    reg64_t;
#endif
#if (TYPESIZE_PTR == 64)
typedef uint64_t   vm_address_t;
typedef uint64_t   vm_offset_t;
typedef uint64_t   vm_size_t;
#else
typedef uint32_t   vm_address_t;
typedef uint32_t   vm_offset_t;
typedef uint32_t   vm_size_t;
#endif
typedef uint64_t   vm_map_address_t;
typedef uint64_t   vm_map_offset_t;
typedef uint64_t   vm_map_size_t;
typedef vm_offset_t   pointer_t;
typedef uint8_t   vm_tag_t;
typedef uint32_t   vm32_address_t;
typedef uint32_t   vm32_offset_t;
typedef uint32_t   vm32_size_t;
typedef uint64_t   mach_port_context_t;
typedef uint64_t   mach_vm_address_t;
typedef uint64_t   mach_vm_offset_t;
typedef uint64_t   mach_vm_size_t;
typedef uint64_t   vm_object_offset_t;
typedef uint64_t   vm_object_size_t;
typedef vm_offset_t   vm_address_t;
typedef mach_port_t   vm_map_t;
typedef mach_vm_offset_t*   emulation_vector_t;
typedef struct vm_allocation_site { vm_tag_t tag; uint8_t flags; }   vm_allocation_site_t;
typedef char*   user_subsystem_t;
typedef char*   labelstr_t;
typedef char*   UNDMessage;
typedef char*   UNDLabel;
typedef char*   UNDKey;
typedef char*   UNDPath;
/** Sent as out-of-line data in a message) */
typedef const char*   xmlData_t;
typedef unsigned   mach_msg_type_name_t;
typedef unsigned   mach_port_rights_t;
typedef unsigned   mach_port_msgcount_t;
typedef unsigned   mach_port_mscount_t;
typedef unsigned   sample_array_t[SAMPLE_MAX];
typedef int64_t   ledger_amount_t;
typedef natural_t   ledger_item_t;
typedef natural_t   mach_port_right_t;
typedef natural_t   mach_port_type_t;
typedef natural_t   mach_port_urefs_t;
typedef natural_t   mach_port_seqno_t;
typedef natural_t   mach_msg_size_t;
typedef int32_t   mach_port_delta_t;
typedef int32_t   mach_msg_id_t;
typedef int32_t   mach_msg_options_t;
/** Dispatch UserNotification replies back to the in-kernel client */
typedef mach_port_t   UNDReplyRef;
typedef mach_port_t   upl_t;
typedef mach_port_t   vm_named_entry_t;
typedef mach_port_t   mach_port_name_t;
typedef mach_port_t   mach_port_move_receive_t;
typedef mach_port_t   mach_port_copy_send_t;
typedef mach_port_t   mach_port_make_send_t;
typedef mach_port_t   mach_port_move_send_t;
typedef mach_port_t   mach_port_send_once_t;
typedef mach_port_t   mach_port_make_send_once_t;
typedef mach_port_t   mach_port_move_send_once_t;
typedef mach_port_t   mach_port_receive_t;
typedef mach_port_t   mach_port_send_t;
typedef mach_port_t   mach_port_poly_t;
typedef mach_port_t   task_t;
typedef mach_port_t   task_name_t;
typedef mach_port_t   task_suspension_token_t;
typedef mach_port_t   thread_t;
typedef mach_port_t   thread_act_t;
typedef mach_port_t   ipc_space_t;
typedef mach_port_t   coalition_t;
typedef mach_port_t   host_t;
typedef mach_port_t   host_priv_t;
typedef mach_port_t   host_security_t;
typedef mach_port_t   processor_t;
typedef mach_port_t   processor_set_t;
typedef mach_port_t   processor_set_control_t;
typedef mach_port_t   semaphore_t;
typedef mach_port_t   lock_set_t;
typedef mach_port_t   ledger_t;
typedef mach_port_t   alarm_t;
typedef mach_port_t   clock_serv_t;
typedef mach_port_t   clock_ctrl_t;
typedef mach_port_t   clock_reply_t;
typedef mach_port_t   bootstrap_t;
typedef mach_port_t   mem_entry_name_port_t;
typedef mach_port_t   exception_handler_t;
typedef mach_port_t   vm_task_entry_t;
typedef mach_port_t   io_master_t;
typedef mach_port_t   UNDServerRef;
#define darwin_mach_port_t   mach_port_t
#define __darwin_mach_port_t   mach_port_t
#define darwin_mach_port_name_t   mach_port_t
#define __darwin_mach_port_name_t   mach_port_t
typedef processor_t   processor_port_t;
typedef processor_t*   processor_array_t;
typedef processor_array_t   processor_port_array_t;
typedef processor_set_t   processor_set_port_t;
typedef processor_set_t   processor_set_name_port_t;
typedef processor_set_t   processor_set_control_port_t;
typedef processor_set_t   processor_set_name_t;
typedef processor_set_t*   processor_set_array_t;
typedef processor_set_t*   processor_set_name_array_t;
typedef processor_set_array_t   processor_set_name_port_array_t;
typedef exception_handler_t   exception_port_t;
typedef exception_handler_t*   exception_handler_array_t;
typedef exception_handler_array_t   exception_port_arrary_t;
typedef task_t   task_port_t;
typedef task_t*   task_array_t;
typedef task_array_t   task_port_array_t;
typedef thread_t   thread_port_t;
typedef thread_t*   thread_array_t;
typedef thread_array_t   thread_port_array_t;
typedef thread_act_t   thread_act_port_t;
typedef thread_act_t*   thread_act_array_t;
typedef thread_act_array_t  thread_act_port_array_t;
typedef ledger_t*   ledger_array_t;
typedef ledger_t   ledger_port_t;
typedef ledger_array_t   ledger_port_array_t;
typedef ipc_space_t   ipc_space_port_t;
typedef host_t   host_name_t;
typedef host_t   host_name_port_t;
typedef semaphore_t   semaphore_port_t;
typedef lock_set_t   lock_set_port_t;
typedef alarm_t   alarm_port_t;
typedef clock_serv_t   clock_serv_port_t;
typedef clock_ctrl_t   clock_ctrl_port_t;
typedef unsigned int   lck_type_t;
typedef unsigned int   lck_sleep_action_t;
typedef struct lck_grp_spin_stat {
	uint64_t lck_grp_spin_util_cnt, lck_grp_spin_held_cnt;
	uint64_t lck_grp_spin_miss_cnt, lck_grp_spin_held_max, lck_grp_spin_held_cum;
} lck_grp_spin_stat_t;


// VOID & NULL MACH OBJECTS

#define VM_MAP_NULL   ((vm_map_t)0x0)
#define UPL_NULL   ((upl_t)0x0)
#define VM_NAMED_ENTRY_NULL  ((vm_named_entry_t)0x0)
#define UND_REPLY_NULL ((UNDReplyRef)0X0)
#define XML_DATA_NULL   ((xmlData_t)0X0)
#define TASK_NULL   ((task_t)0x0)
#define TASK_NAME_NULL   ((task_name_t)0x0)
#define THREAD_NULL   ((thread_t)0x0)
#define TID_NULL   ((uint64_t)0x0)
#define THR_ACT_NULL   ((thread_act_t)0x0)
#define IPC_SPACE_NULL   ((ipc_space_t)0x0)
#define COALITION_NULL   ((coalition_t)0x0)
#define HOST_NULL   ((host_t)0x0)
#define HOST_PRIV_NULL   ((host_priv_t)0)
#define HOST_SECURITY_NULL  ((host_security_t)0)
#define PROCESSOR_SET_NULL  ((processor_set_t)0x0)
#define PROCESSOR_NULL   ((processor_t)0x0)
#define SEMAPHORE_NULL   ((semaphore_t)0x0)
#define LOCK_SET_NULL   ((lock_set_t)0x0)
#define LEDGER_NULL   ((ledger_t)0x0)
#define ALARM_NULL   ((alarm_t)0x0)
#define CLOCK_NULL   ((clock_t)0x0)
#define UND_SERVER_NULL   ((UNDServerRef)0x0)


// MACH INFINITY OBJECTS

#define LEDGER_ITEM_INFINITY   ((ledger_item_t)(~0))
#define LEDGER_LIMIT_INFINITY   ((ledger_amount_t)(0x7fffffffULL)


// MACH VOUCHER DATATYPES

/** Add some number of external refs (not supported) */
#define MACH_VOUCHER_IMPORTANCE_ATTR_ADD_EXTERNAL   1
/** Drop some number of external refs */
#define MACH_VOUCHER_IMPORTANCE_ATTR_DROP_EXTERNAL   2
/** An immutable collection of attribute value handles */
typedef mach_port_t   mach_voucher_t;
#define MACH_VOUCHER_NULL   ((mach_voucher_t)0)
typedef mach_port_name_t   mach_voucher_name_t;
#define MACH_VOUCHER_NAME_NULL   ((mach_voucher_name_t)0)
typedef mach_voucher_name_t*   mach_voucher_name_array_t;
#define MACH_VOUCHER_NAME_ARRAY_NULL   ((mach_voucher_name_array_t)0x0)
typedef mach_voucher_t   ipc_voucher_t;
#define IPC_VOUCHER_NULL   ((ipc_voucher_t)0x0)
typedef uint32_t   mach_voucher_attr_importance_refs;
typedef uint32_t   mach_voucher_selector_t;
#define MACH_VOUCHER_SELECTOR_CURRENT   ((mach_voucher_selector_t)0x0)
#define MACH_VOUCHER_SELECTOR_EFFECTIVE   ((mach_voucher_selector_t)0x1)
/** Data passed to a resource manager for modifying an attribute value or returned from the resource manager in response to a request to externalize the current value for that attribute */
typedef uint8_t*   mach_voucher_attr_content_t;
typedef uint32_t   mach_voucher_attr_content_size_t;
/** The private verbs implemented by each voucher attribute manager via mach_voucher_attr_command() */
typedef uint32_t   mach_voucher_attr_command_t;
/** The verbs used to create/morph a voucher attribute value */
typedef uint32_t   mach_voucher_attr_recipe_command_t;
typedef mach_voucher_attr_recipe_command_t*   mach_voucher_attr_recipe_command_array_t;
#define MACH_VOUCHER_ATTR_NOOP   ((mach_voucher_attr_recipe_command_t)0x0)
#define MACH_VOUCHER_ATTR_COPY   ((mach_voucher_attr_recipe_command_t)0x1)
#define MACH_VOUCHER_ATTR_REMOVE   ((mach_voucher_attr_recipe_command_t)0x2)
#define MACH_VOUCHER_ATTR_SET_VALUE_HANDLE   ((mach_voucher_attr_recipe_command_t)3)
#define MACH_VOUCHER_ATTR_REDEEM   ((mach_voucher_attr_recipe_command_t)10)
#define MACH_VOUCHER_ATTR_IMPORTANCE_SELF   ((mach_voucher_attr_recipe_command_t)200)
#define MACH_VOUCHER_ATTR_USER_DATA_STORE   ((mach_voucher_attr_recipe_command_t)211)
#define MACH_VOUCHER_ATTR_BITS_STORE   MACH_VOUCHER_ATTR_USER_DATA_STORE
#define MACH_VOUCHER_ATTR_TEST_STORE   MACH_VOUCHER_ATTR_USER_DATA_STORE
/** The key used to identify a particular managed resource or to select the specific resource manager's data associated with a given voucher */
typedef uint32_t   mach_voucher_attr_key_t;
typedef mach_voucher_attr_key_t*   mach_voucher_attr_key_array_t;
#define MACH_VOUCHER_ATTR_KEY_ALL   ((mach_voucher_attr_key_t)~0x0)
#define MACH_VOUCHER_ATTR_KEY_NONE   ((mach_voucher_attr_key_t)0x0)
#define MACH_VOUCHER_ATTR_KEY_ATM   ((mach_voucher_attr_key_t)1)
#define MACH_VOUCHER_ATTR_KEY_IMPORTANCE   ((mach_voucher_attr_key_t)2)
#define MACH_VOUCHER_ATTR_KEY_BANK   ((mach_voucher_attr_key_t)3)
#define MACH_VOUCHER_ATTR_KEY_USER_DATA   ((mach_voucher_attr_key_t)7)
#define MACH_VOUCHER_ATTR_KEY_BITS   MACH_VOUCHER_ATTR_KEY_USER_DATA
#define MACH_VOUCHER_ATTR_KEY_TEST   ((mach_voucher_attr_key_t)8)
#define MACH_VOUCHER_ATTR_KEY_NUM_WELL_KNOWN   MACH_VOUCHER_ATTR_KEY_TEST
/** A handle provided to the voucher attribute manager for a given attribute key through which it makes inquiries or control operations of the mach voucher mechanism */
typedef mach_port_t   mach_voucher_attr_control_t;
#define MACH_VOUCHER_ATTR_CONTROL_NULL   ((mach_voucher_attr_control_t)0x0)
typedef mach_port_t   ipc_voucher_attr_manager_t;
typedef mach_port_t   ipc_voucher_attr_control_t;
#define IPC_VOUCHER_ATTR_MANAGER_NULL   ((ipc_voucher_attr_manager_t)0x0)
#define IPC_VOUCHER_ATTR_CONTROL_NULL   ((ipc_voucher_attr_control_t)0x0)
typedef uint32_t   mach_voucher_attr_value_reference_t;
typedef uint32_t   mach_voucher_attr_control_flags_t;
#define MACH_VOUCHER_ATTR_CONTROL_FLAGS_NONE   ((mach_voucher_attr_control_flags_t)0x0)
/** An element in a recipe list to create a voucher */
typedef struct mach_voucher_attr_recipe_data {
	mach_voucher_attr_key_t key;
	mach_voucher_attr_recipe_command_t command;
	mach_voucher_name_t previous_voucher;
	mach_voucher_attr_content_size_t content_size;
	uint8_t content[];
} mach_voucher_attr_recipe_data_t;
/** A handle through which the mach voucher mechanism communicates with the voucher attribute manager for a given attribute key */
typedef mach_port_t   mach_voucher_attr_manager_t;
typedef uint8_t*   mach_voucher_attr_raw_recipe_t;
/** The private handle that the voucher attribute manager provides to the mach voucher mechanism to represent a given attr content/value */
typedef uint64_t   mach_voucher_attr_value_handle_t;
typedef mach_voucher_attr_raw_recipe_t   mach_voucher_attr_raw_recipe_array_t;
typedef mach_voucher_attr_recipe_data_t*   mach_voucher_attr_recipe_t;
typedef mach_msg_type_number_t   mach_voucher_attr_recipe_size_t;
typedef mach_msg_type_number_t   mach_voucher_attr_raw_recipe_size_t;
typedef mach_msg_type_number_t   mach_voucher_attr_raw_recipe_array_size_t;
#define MACH_VOUCHER_ATTR_MANAGER_NULL   ((mach_voucher_attr_manager_t)0x0)
typedef mach_voucher_attr_value_handle_t*   mach_voucher_attr_value_handle_array_t;
typedef mach_msg_type_number_t   mach_voucher_attr_value_handle_array_size_t;
#define MACH_VOUCHER_ATTR_VALUE_MAX_NESTED   ((mach_voucher_attr_value_handle_array_size_t)4)
#if (!(defined(_ATM_ATM_TYPES_H) || defined(_ATM_ATM_TYPES_H_)))
#define _ATM_ATM_TYPES_H   (1)
#define _ATM_ATM_TYPES_H_   (1)


#define ATM_ACTION_DISCARD   0x1
#define ATM_ACTION_COLLECT   0x2
#define ATM_ACTION_LOGFAIL   0x3
#define ATM_FIND_MIN_SUB_AID   0x4
#define ATM_ACTION_UNREGISTER   0x5
#define ATM_ACTION_REGISTER   0x6
#define ATM_ACTION_GETSUBAID   0x7
#define ATM_TRACE_DISABLE   (0x100)
#define MACH_VOUCHER_ATTR_ATM_NULL   ((mach_voucher_attr_recipe_command_t)501)
#define MACH_VOUCHER_ATTR_ATM_CREATE   ((mach_voucher_attr_recipe_command_t)510)
#define MACH_VOUCHER_ATTR_ATM_REGISTER   ((mach_voucher_attr_recipe_command_t)511)
typedef uint32_t   atm_action_t;
typedef uint32_t   atm_subaid32_t;
typedef uint64_t   atm_aid_t;
typedef uint64_t   mach_atm_subaid_t;
typedef uint64_t   atm_mailbox_offset_t;
typedef uint64_t   atm_guard_t;
typedef uint64_t   aid_t;
typedef uint64_t   subaid_t;
typedef uint64_t   mailbox_offset_t;
typedef uint64_t*   atm_memory_size_array_t;
typedef mach_port_t   atm_memory_descriptor_t;
typedef atm_memory_descriptor_t*   atm_memory_descriptor_array_t;


#endif  // _ATM_ATM_TYPES_H
#if (!(defined(_BANK_BANK_TYPES_H) || defined(_BANK_BANK_TYPES_H_)))
#define _BANK_BANK_TYPES_H   (1)
#define _BANK_BANK_TYPES_H_   (1)


#define MACH_VOUCHER_ATTR_BANK_NULL    ((mach_voucher_attr_recipe_command_t)601)
#define MACH_VOUCHER_ATTR_BANK_CREATE    ((mach_voucher_attr_recipe_command_t)610)
#define MACH_VOUCHER_BANK_CONTENT_SIZE   (500)
#define BANK_ORIGINATOR_PID   0x1
typedef uint32_t    bank_action_t;


#endif  // _BANK_BANK_TYPES_H


// MINIX DATATYPES

/** Asynchronous API */
typedef int   bdev_id_t;
typedef void*   bdev_param_t;
typedef struct attr_packed bdev_callback {
	dev_t dev;
	bdev_id_t _id;
	bdev_param_t param;
	int result;
} bdev_callback_t;
/** Virtual addresses/lengths in bytes */
typedef long unsigned int   vir_bytes;
/** Virtual addr/length in clicks */
typedef unsigned int   vir_clicks;
/** Physical addr/length in bytes */
typedef unsigned long   phys_bytes;
/** Physical addr/length in clicks */
typedef unsigned int   phys_clicks;
/** Process identifier */
typedef int   endpoint_t;
/** Machine info datatype */
typedef struct attr_packed machine_struct {
	unsigned processors_count;  // Available CPUs
	unsigned bsp_id;  // ID of the bootstrap cpu
	int padding;
	int apic_enabled;  // APIC enabled/disabled
	phys_bytes acpi_rsdp;  // ACPI RSDP location
	unsigned int board_id;  // Identifier for the board
} machine_t;
/** Memory chunks datatype */
typedef struct memory_struct { phys_bytes base, size; }   memory_t;
/** Structure for virtual copying by means of a vector with requests */
typedef struct attr_packed vir_addr { endpoint_t proc_nr_e; vir_bytes offset; }   vir_addr_t;
typedef struct vir_cp_req { struct vir_addr src, dst; phys_bytes count; }   vir_cp_req_t;
#define phys_cp_req   vir_cp_req
#define phys_cp_req_t   vir_cp_req_t
/** Structures for SYS_VUMAP */
typedef struct vumap_vir {
	union {
		cp_grant_id_t u_grant;  // Grant identifier, for non-SELF endpoint
		vir_bytes u_addr;  // Local virtual address, for SELF endpoint
	} vv_u;
	size_t vv_size;  // Size in bytes
} vumap_vir_t;
#define vv_grant   vv_u.u_grant
#define vv_addr   vv_u.u_addr
typedef struct vumap_phys {
	phys_bytes vp_addr;  // Physical address
	size_t vp_size;  // Size in bytes
} vumap_phys_t;
/** I/O vector structures used in protocols between services */
typedef struct iovec_struct {
	vir_bytes iov_addr;  // Address of an I/O buffer
	vir_bytes iov_size;  // Size of an I/O buffer
} iovec_struct_t;
typedef struct attr_packed iovec_s {
	cp_grant_id_t iov_grant;  // Grant ID of an I/O buffer
	vir_bytes iov_size;  // Size of an I/O buffer
} iovec_s_t;
typedef struct io_range {
	unsigned ior_base;  // Lowest I/O port in range
	unsigned ior_limit;  // Highest I/O port in range
} io_range_t;
typedef struct minix_mem_range {
	phys_bytes mr_base;  // Lowest memory address in range
	phys_bytes mr_limit;  // Highest memory address in range
} mem_range_t;
/** Revocation Reason type */
typedef uint8_t   pgp_ss_rr_code_t;
/** Writer flags */
typedef enum pgp_writer_flags { PGP_WF_DUMMY }   pgp_writer_flags_t;
typedef struct pgp_io_t {
	void* outs;  // Output file stream
	void* errs;  // File stream to put error messages
	void* res;  // File stream to put results
} pgp_io_t;
typedef struct attr_packed pgp_map { int type; const char* _string; }   pgp_map_t, pgp_errcode_name_map_t;
/** Old, fixed size filehandle structures */
typedef struct compat_30_fid {
	unsigned short fid30_len, fid30_reserved;
	char fid30_data[16];
} compat_30_fid_t;
typedef struct compat_30_fhandle {
	fsid_t fh_fsid;
	struct compat_30_fid fh_fid;
} compat_30_fhandle_t;
#define FHANDLE30_SIZE   sizeof(compat_30_fhandle_t)


// PLAN9 DATATYPES

/** Print format datatype */
typedef struct attr_packed Fmt{
	unsigned char runes;  // Output buffer is runes or chars
	void* start;  // Beginning of buffer
	void* to;  // Current place in the buffer
	void* stop;  // End of the buffer; overwritten if flush fails
	int (*flush)(struct Fmt*);  // Called when to == stop
	void* farg;  // To make flush a closure
	int nfmt;  // Number of chars formatted so far
	va_list args;  // Args passed to dofmt
	int r;  // Format Rune
	int width, prec;
	unsigned long flags;
} Fmt;
enum {
	FmtWidth = 1,
	FmtLeft = 2,
	FmtPrec = 4,
	FmtSharp = 8,
	FmtSpace = 16,
	FmtSign = 32,
	FmtZero = 64,
	FmtUnsigned = 128,
	FmtShort = 256,
	FmtLong = 512,
	FmtVLong = 1024,
	FmtComma = 2048,
	FmtByte = 4096,
	FmtFlag = 8192
};
typedef struct Lock { long key, sem; } Lock;
typedef struct attr_packed QLp {
	int inuse;
	struct QLp* next;
	char state;
} QLp;
typedef struct attr_packed QLock {
	Lock lock;
	int locked;
	QLp* head;
	QLp* tail;
} QLock;
typedef struct RWLock {
	Lock lock;
	int readers;  // Number of readers
	int writer;  // Number of writers
	QLp* head;  // List of waiting processes
	QLp* tail;
} RWLock;
typedef struct Rendez {
	QLock* l;
	QLp* head;
	QLp* tail;
} Rendez;
typedef struct NetConnInfo {
	char* dir;  // Connection directory
	char* root;  // Network root
	char* spec;  // Binding spec
	char* lsys;  // Local system
	char* lserv;  // Local service
	char* rsys;  // Remote system
	char* rserv;  // Remote service
	char* laddr;  // Local address
	char* raddr;  // Remote address
} NetConnInfo;
typedef struct attr_packed Waitmsg {
	int pid;
	unsigned long time[3];
	char* msg;
} Waitmsg;
/** rfork enum */
enum {
	RFNAMEG = 1,
	RFENVG = 2,
	RFFDG = 4,
	RFNOTEG = 8,
	RFPROC = 16,
	RFMEM = 32,
	RFNOWAIT = 64,
	RFCNAMEG = 128,
	RFCENVG = 256,
	RFCFDG = 512,
	RFREND = 1024,
	RFNOMNT = 2048
};


// CMPH DATATYPES

/** Signed 8-bit integer datatype */
typedef int8_t   cmph_int8;
/** Unsigned 16-bit integer datatype */
typedef uint8_t   cmph_uint8;
/** Signed 16-bit integer datatype */
typedef short   cmph_int16;
/** Unsigned 16-bit integer datatype */
typedef unsigned short   cmph_uint16;
/** Signed 32-bit integer datatype */
typedef int   cmph_int32;
/** Unsigned 32-bit integer datatype */
typedef unsigned int   cmph_uint32;
/** Signed 64-bit integer datatype */
typedef int64_t   cmph_int64;
/** Unsigned 64-bit integer datatype */
typedef uint64_t   cmph_uint64;
typedef enum CMPH_HASH_ENUM { CMPH_HASH_JENKINS, CMPH_HASH_COUNT }   CMPH_HASH;
typedef enum CMPH_ALGO_ENUM {
	CMPH_BMZ,
	CMPH_BMZ8,
	CMPH_CHM,
	CMPH_BRZ,
	CMPH_FCH,
	CMPH_BDZ,
	CMPH_BDZ_PH,
	CMPH_CHD_PH,
	CMPH_CHD,
	CMPH_COUNT
} CMPH_ALGO;


// WINDOWS DATATYPES

typedef struct _W32CLIENTINFO {
	unsigned long CI_flags;
	unsigned long cSpins;
	unsigned long ulWindowsVersion;
	unsigned long ulAppCompatFlags;
	unsigned long ulAppCompatFlags2;
	unsigned long W32ClientInfo[57];
} W32CLIENTINFO;
#ifndef _FILETIME_
typedef struct _FILETIME { DWORD dwLowDateTime, dwHighDateTime; } FILETIME;
#   define _FILETIME_   FILETIME
typedef FILETIME*   PFILETIME;
typedef FILETIME*   LPFILETIME;
#endif


// XNU & MACINTOSH DATATYPES

#if IS_BIG_ENDIAN
typedef struct wide { int32_t hi; uint32_t lo; } wide;
typedef struct UnsignedWide { uint32_t hi, lo; } UnsignedWide;
#else
typedef struct wide { uint32_t lo; int32_t hi; } wide;
typedef struct UnsignedWide { uint32_t lo, hi; } UnsignedWide;
#endif  // IS_BIG_ENDIAN
/** 8-bit signed integer plus 8-bit fraction */
typedef short   ShortFixed;
typedef ShortFixed*   ShortFixedPtr;
/** 16-bit signed integer plus 16-bit fraction */
typedef int32_t   Fixed;
typedef Fixed*   FixedPtr;
/** 16-bit unsigned integer plus 16-bit fraction */
typedef uint32_t   UnsignedFixed;
typedef UnsignedFixed*   UnsignedFixedPtr;
/** 2-bit signed integer plus 30-bit fraction */
typedef int32_t   Fract;
typedef Fract*   FractPtr;
typedef char*   Ptr;
typedef Ptr*   Handle;
typedef long   Size;
/** 16-bit result error code */
typedef int16_t   OSErr;
/** 32-bit result error code */
typedef int32_t   OSStatus;
/** Address in the clients virtual address space */
typedef void*   LogicalAddress;
/** Address in the clients virtual address space that will only be read */
typedef const void*   ConstLogicalAddress;
/** Real address as used on the hardware bus */
typedef void*   PhysicalAddress;
/** Pointer to an array of bytes */
typedef uint8_t*   BytePtr;
/** The size of an array of bytes */
typedef unsigned long   ByteCount;
/** An offset into an array of bytes */
typedef unsigned long   ByteOffset;
typedef short   filter_t;
typedef int32_t   io_buf_len_t;
typedef uint32_t   recnum_t;
typedef uint32_t   dev_mode_t;
typedef uint32_t   dev_flavor_t;
typedef mach_port_t   device_t;
typedef mach_port_t   io_done_queue_t;
typedef int   dev_status_t[1024];
typedef char   dev_name_t[128];
typedef char   io_buf_ptr_inband_t[128];
typedef char*   io_buf_ptr_t;
typedef filter_t   filter_array_t[64];
/** 32-bit millisecond timer for drivers */
typedef int32_t   Duration;
/** 64-bit clock */
typedef UnsignedWide   AbsoluteTime;
/** Standard 32-bit set of bit flags */
typedef uint32_t   OptionBits;
/** 32-bit iteration count */
typedef unsigned long   ItemCount;
typedef uint32_t   PBVersion;
/** A particular set of written characters (e.g. Roman vs Cyrillic) and their encoding */
typedef int16_t   ScriptCode;
/** A particular language (e.g. English), as represented using a particular ScriptCode */
typedef int16_t   LangCode;
/** Designates a language as used in a particular region (e.g. British vs American English) together with other region-dependent characteristics (e.g. date format) */
typedef int16_t   RegionCode;
/** A 32-bit value made by packing four 1 byte characters together */
typedef uint32_t   FourCharCode;
/** A FourCharCode used in the OS and filesystem */
typedef FourCharCode   OSType;
/** A FourCharCode used to tag resources */
typedef FourCharCode   ResType;
typedef OSType*   OSTypePtr;
typedef ResType*   ResTypePtr;
/** For access to private data in callbacks */
typedef void*   PRefCon;
#ifdef DATAMODEL_LP64
typedef void*   URefCon;
typedef void*   SRefCon;
#else
typedef uint32_t   URefCon;
typedef int32_t   SRefCon;
#endif
/** OSErr: function performed properly - no error */
#define noErr   0
/** OptionBits: all flags false */
#define kNilOptions   0
/** NULL is for pointers as kInvalidID is for ID's */
#define kInvalidID   0
/** Array bounds: variable length array */
#define kVariableLengthArray   1
/** QuickTime 3.0: default unknown ResType or OSType */
#define kUnknownType   0x3F3F3F3F
/** A complete Unicode character in UTF-32 format, with values from 0 through 0x10FFFF (excluding the surrogate range 0xD800-0xDFFF and certain disallowed values) */
typedef uint32_t   UnicodeScalarValue;
/** A complete Unicode character in UTF-32 format, with values from 0 through 0x10FFFF (excluding the surrogate range 0xD800-0xDFFF and certain disallowed values) */
typedef uint32_t   UTF32Char;
/** A 16-bit Unicode code value in the default UTF-16 format; UnicodeScalarValues 0x10000-0x10FFFF are expressed in UTF-16 format using a pair of UTF16Chars - one in the high surrogate range (0xD800-0xDBFF) followed by one in the low surrogate range (0xDC00-0xDFFF); All of the characters defined in Unicode versions through 3.0 are in the range 0-0xFFFF and can be expressed using a single UTF16Char */
typedef uint16_t   UniChar;
typedef UniChar*   UniCharArrayPtr;
typedef const UniChar*   ConstUniCharArrayPtr;
typedef uint32_t   TextEncoding;
/** A 16-bit Unicode code value in the default UTF-16 format; UnicodeScalarValues 0x10000-0x10FFFF are expressed in UTF-16 format using a pair of UTF16Chars - one in the high surrogate range (0xD800-0xDBFF) followed by one in the low surrogate range (0xDC00-0xDFFF); All of the characters defined in Unicode versions through 3.0 are in the range 0-0xFFFF and can be expressed using a single UTF16Char */
typedef uint16_t   UTF16Char;
/** An 8-bit code value in UTF-8 format; UnicodeScalarValues 0-0x7F are expressed in UTF-8 format using one UTF8Char with the same value; UnicodeScalarValues above 0x7F are expressed in UTF-8 format using 2-4 UTF8Chars, all with values in the range 0x80-0xF4 (UnicodeScalarValues 0x100-0xFFFF use two or three UTF8Chars, UnicodeScalarValues 0x10000-0x10FFFF use four UTF8Chars) */
typedef uint8_t   UTF8Char;
typedef UniChar*   UniCharPtr;
/** A count of UTF-16 code values in an array or buffer */
typedef unsigned long   UniCharCount;
typedef UniCharCount*   UniCharCountPtr;
typedef unsigned char   Str255[256];
typedef unsigned char   Str63[64];
typedef unsigned char   Str32[33];
typedef unsigned char   Str31[32];
typedef unsigned char   Str27[28];
typedef unsigned char   Str15[16];
typedef Str63   StrFileName;
/** Used in many AppleTalk based data structures; It holds up to 32 one byte chars; The problem is that with the length byte it is 33 bytes long; This can cause weird alignment problems in structures */
typedef unsigned char   Str32Field[34];
/** Pointer to a string */
typedef unsigned char*   StringPtr;
/** Pointer to a StringPtr */
typedef StringPtr*   StringHandle;
/** Pointer to a read-only string */
typedef const unsigned char*   ConstStringPtr;
typedef const unsigned char*   ConstStr255Param;
typedef const unsigned char*   ConstStr63Param;
typedef const unsigned char*   ConstStr32Param;
typedef const unsigned char*   ConstStr31Param;
typedef const unsigned char*   ConstStr27Param;
typedef const unsigned char*   ConstStr15Param;
typedef ConstStr63Param   ConstStrFileNameParam;
#define StrLength(_string)   (*(unsigned char*)(_string))
#if (defined(OLDROUTINENAMES) && OLDROUTINENAMES)
#   define Length(_string)   StrLength(_string)
#endif
typedef uint8_t   Byte;
typedef int8_t   SignedByte;
typedef wide*   WidePtr;
typedef UnsignedWide*   UnsignedWidePtr;
typedef Float80   extended80;
typedef Float96   extended96;
typedef int8_t   VHSelect;
/** Type for unique process identifier */
typedef struct ProcessSerialNumber { uint32_t   highLongOfPSN, lowLongOfPSN; }   ProcessSerialNumber;
typedef ProcessSerialNumber*   ProcessSerialNumberPtr;
/** Char when used as a parameter (historical 68K convention) */
typedef short   CharParameter;
/** Quickdraw font rendering styles */
typedef unsigned char   Style;
/** Style when used as a parameter (historical 68K convention) */
typedef short   StyleParameter;
/** Style when used as a field (historical 68K convention) */
typedef Style   StyleField;
/** Count of units (QuickTime TimeBase) */
typedef int32_t   TimeValue;
/** Units per second (QuickTime TimeBase) */
typedef int32_t   TimeScale;
/** 64-bit count of units (QuickTime TimeBase) */
typedef wide   CompTimeValue;
/** 64-bit count of units (QuickTime TimeBase) */
typedef int64_t   TimeValue64;
/** An opaque reference to a time base (QuickTime TimeBase) */
typedef struct attr_packed TimeBaseRecord*   TimeBase;
/** Package of TimeBase, duration, and scale (QuickTime TimeBase) */
typedef struct attr_packed TimeRecord {
	CompTimeValue value;  // Units (duration or absolute)
	TimeScale scale;  // Units per second
	TimeBase base;  // Reference to the time base
} TimeRecord;
/** Flags for general linker behavior */
typedef enum kxld_flags { kKxldFlagDefault = 0x0, kKXLDFlagIncludeRelocs = 0x1 }   KXLDFlags;
/** Flags for the allocation callback */
typedef enum kxld_allocate_flags { kKxldAllocateDefault = 0x0, kKxldAllocateWritable = 0x1 }   KXLDAllocateFlags;
/** Flags for the logging callback */
typedef enum kxld_log_subsystem { kKxldLogLinking = 0x0, kKxldLogPatching = 0x1 }   KXLDLogSubsystem;
typedef enum kxld_log_level {
	kKxldLogExplicit = 0,
	kKxldLogErr = 1,
	kKxldLogWarn = 2,
	kKxldLogBasic = 3,
	kKxldLogDetail = 4,
	kKxldLogDebug = 5
} KXLDLogLevel;
/** Section header table index type */
typedef uint32_t   dof_secidx_t;
/** String table index type */
typedef uint32_t   dof_stridx_t;
/** Stability code */
typedef uint8_t   dtrace_stability_t;
/** Architectural dependency class */
typedef uint8_t   dtrace_class_t;
typedef uintptr_t   dtrace_provider_id_t;
typedef uintptr_t   dtrace_icookie_t;
typedef int   processorid_t;
typedef int64_t   hrtime_t;
typedef uint32_t   zoneid_t;
/** Probe identifier */
typedef uint32_t   dtrace_id_t;
/** Enabled probe identifier */
typedef uint32_t   dtrace_epid_t;
/** Aggregation identifier */
typedef uint32_t   dtrace_aggid_t;
/** Aggregation variable identifier */
typedef int64_t   dtrace_aggvarid_t;
/** Action kind */
typedef uint16_t   dtrace_actkind_t;
/** Option value */
typedef int64_t   dtrace_optval_t;
/** Predicate cache identifier */
typedef uint32_t   dtrace_cacheid_t;
typedef uint32_t   dif_instr_t;


// IOKIT DATATYPES

/** IO buffer - out-of-line array of characters */
typedef char*   io_buf_ptr_t;
typedef char   io_name_t[128];
typedef char   io_string_t[512];
typedef char   io_string_inband_t[4096];
typedef char   io_struct_inband_t[4096];
#if (defined(KERNEL) && KERNEL)
typedef uint64_t   io_user_scalar_t;
typedef uint64_t   io_user_reference_t;
typedef int   io_scalar_inband_t[16];
typedef natural_t   io_async_ref_t[8];
typedef io_user_scalar_t   io_scalar_inband64_t[16];
typedef io_user_reference_t   io_async_ref64_t[8];
#elif defined(DATAMODEL_LP64)
typedef uint64_t   io_user_scalar_t;
typedef uint64_t   io_user_reference_t;
typedef io_user_scalar_t   io_scalar_inband_t[16];
typedef io_user_reference_t   io_async_ref_t[8];
typedef io_user_scalar_t    io_scalar_inband64_t[16];
typedef io_user_reference_t   io_async_ref64_t[8];
#else
typedef int   io_user_scalar_t;
typedef natural_t   io_user_reference_t;
typedef io_user_scalar_t   io_scalar_inband_t[16];
typedef io_user_reference_t   io_async_ref_t[8];
typedef uint64_t   io_scalar_inband64_t[16];
typedef uint64_t   io_async_ref64_t[8];
#endif
#ifndef __IOKIT_PORTS_DEFINED__
#   define __IOKIT_PORTS_DEFINED__   (1)
typedef mach_port_t   io_object_t;
#endif


// SYSV IPC DATATYPES (<bits/ipctypes.h>)

#if (!(defined(BITS_IPCTYPES_H) || defined(_BITS_IPCTYPES_H) || defined(IPCTYPES_H) || defined(_IPCTYPES_H) || defined(_IPCTYPES_H_)))  // <bits/ipctypes.h>
#define BITS_IPCTYPES_H   (1)
#define _BITS_IPCTYPES_H   (1)
#define IPCTYPES_H   (1)
#define _IPCTYPES_H   (1)
#define _IPCTYPES_H_   (1)


#if IS_WORDSIZE_32
/** Used in `struct shmid_ds` */
typedef unsigned short   ipc_pid_t;
#else
/** Used in `struct shmid_ds` */
typedef int   ipc_pid_t;
#endif
#define __ipc_pid_t   ipc_pid_t


#endif  // <bits/ipctypes.h>


// REGISTER DATATYPES

#if (!(defined(SYS_USER_H) || defined(_SYS_USER_H) || defined(_SYS_USER_H_)))
#define SYS_USER_H   (1)
#define _SYS_USER_H   (1)
#define _SYS_USER_H_   (1)


#if ((defined(X86_64) || defined(X86)) && (!defined(I386)))


#define ELF_NGREG   27

typedef struct user_fpregs_struct {
	uint16_t cwd, swd, ftw, fop;
	uint64_t rip, rdp;
	uint32_t mxcsr, mxcr_mask;
	uint32_t st_space[32], xmm_space[64], padding[24];
} elf_fpregset_t;

typedef struct user_regs_struct {
	unsigned long r15, r14, r13, r12, rbp, rbx, r11, r10, r9, r8;
	unsigned long rax, rcx, rdx, rsi, rdi, orig_rax, rip;
	unsigned long cs, eflags, rsp, ss, fs_base, gs_base, ds, es, fs, gs;
} user_regs_t;

typedef unsigned long long elf_greg_t, elf_gregset_t[ELF_NGREG];

typedef struct attr_packed user {
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
	unsigned long u_debugreg[8];
} user_t;

#define PAGE_MASK   (~(PAGE_SIZE - 1))
#define NBPG   PAGE_SIZE
#define UPAGES   1
#define HOST_TEXT_START_ADDR   (u.start_code)
#define HOST_STACK_END_ADDR   (u.start_stack + u.u_ssize * NBPG)


#elif defined(I386)


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

#define ELF_NGREG   17
typedef unsigned long elf_greg_t, elf_gregset_t[ELF_NGREG];

typedef struct attr_packed user {
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

#define PAGE_MASK   (~(PAGE_SIZE - 1))
#define NBPG   PAGE_SIZE
#define UPAGES   1
#define HOST_TEXT_START_ADDR   (u.start_code)
#define HOST_STACK_END_ADDR   (u.start_stack + u.u_ssize * NBPG)


#elif defined(SUPERH)


#define REG_REG0   0
#define REG_REG15   15
#define REG_PC   16
#define REG_PR   17
#define REG_SR   18
#define REG_GBR   19
#define REG_MACH   20
#define REG_MACL   21
#define REG_SYSCALL   22
#define REG_FPREG0   23
#define REG_FPREG15   38
#define REG_XFREG0   39
#define REG_XFREG15   54
#define REG_FPSCR   55
#define REG_FPUL   56

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

#define ELF_NGREG   23
typedef unsigned long   elf_greg_t;
typedef elf_greg_t   elf_gregset_t[ELF_NGREG];

typedef struct attr_packed user {
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


#elif defined(ARM64)


typedef struct user_regs_struct {
	unsigned long long regs[31];
	unsigned long long sp, pc, pstate;
} user_regs_struct_t;

typedef struct user_fpsimd_struct {
	long double vregs[32];
	unsigned int fpsr;
	unsigned int fpcr;
} elf_fpregset_t;

#define ELF_NREG   34
typedef unsigned long   elf_greg_t, elf_gregset_t[ELF_NREG];


#elif defined(ARM)


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
#define ELF_NGREG   18
typedef unsigned long   elf_greg_t, elf_gregset_t[ELF_NGREG];

typedef struct attr_packed user {
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


#elif defined(MIPS)


typedef struct attr_packed user {
	unsigned long regs[109];
	unsigned long u_tsize, u_dsize, u_ssize;
	unsigned long start_code, start_data, start_stack;
	long signal;
	void* u_ar0;
	unsigned long magic;
	char u_comm[32];
} user_t;
#define ELF_NGREG   45
#define ELF_NFPREG   33
typedef unsigned long   elf_greg_t, elf_gregset_t[ELF_NGREG];
typedef double   elf_fpreg_t, elf_fpregset_t[ELF_NFPREG];


#elif defined(POWERPC)


typedef struct pt_regs {
	unsigned long gpr[32], nip, msr, orig_gpr3, ctr, link, xer, ccr, mq;
	unsigned long trap, dar, dsisr, result;
} pt_regs_t;

typedef struct attr_packed user {
	struct pt_regs regs;
	unsigned long u_tsize, u_dsize, u_ssize, start_code, start_data, start_stack;
	long signal;
	void* u_ar0;
	unsigned long magic;
	char u_comm[32];
} user_t;

#define ELF_NGREG   48
#define ELF_NFPREG   33
#define ELF_NVRREG   33
typedef unsigned long   elf_greg_t, elf_gregset_t[ELF_NGREG];
typedef double   elf_fpreg_t, elf_fpregset_t[ELF_NFPREG];
typedef struct __elf_vrreg { unsigned u[4]; } aligned16   elf_vrreg_t, elf_vrregset_t[ELF_NVRREG];


#endif  // ARCH


#endif  // SYS_USER_H


// GPIO DATATYPES FOR EMBEDDED SYSTEMS

/** GPIO Pin Datatype */
typedef struct GPIO_Pin { uint8_t block, port; uint16_t bit; }   GPIO_Pin_t;
typedef enum GPIO_Direction { GPIO_Input = 0, GPIO_Output = 1 }   GPIO_Direction_t;
typedef enum GPIO_OutputType { GPIO_OutputType_PP = 0, GPIO_OutputType_OD = 1 }   GPIO_OutputType_t;


typedef enum GPIO_LineLevel {
	GPIO_LineLevel_Low = 0,
	GPIO_LineLevel_High = 1,
	GPIO_LineLevel_Error = 2
} GPIO_LineLevel_t;


typedef enum GPIO_PullUpDown {
	GPIO_NoPull = 0,
	GPIO_PullUp = 1,
	GPIO_PullDown = 2,
	GPIO_PullUpDown = 3
} GPIO_PullUpDown_t;


typedef enum GPIO_RiseTime {
	GPIO_RiseTime_Shortest = 0,
	GPIO_RiseTime_Moderate = 1,
	GPIO_RiseTime_Longest = 2
} GPIO_RiseTime_t;


typedef struct GPIO_PinInitStruct {
	GPIO_Pin_t pin;
	GPIO_Direction_t direction;
	GPIO_LineLevel_t initLineLevel;
	GPIO_PullUpDown_t pull;
	GPIO_OutputType_t outputType;
	GPIO_RiseTime_t riseTime;
} GPIO_PinInitStruct_t;


/** Sets an already registered pin up with an entire new init profile */
typedef struct GPIO_PinControlInterface {
	_Bool (*reconfig)(GPIO_PinInitStruct_t* initStruct);
	_Bool (*setPinDirection)(int16_t pinIndex, GPIO_Direction_t dir);
	GPIO_Direction_t (*getPinDirection)(int16_t pinIndex);
	_Bool (*setLineLevel)(int16_t pinIndex, GPIO_LineLevel_t level);
	GPIO_LineLevel_t (*getLineLevel)(int16_t pinIndex);
	_Bool (*setPull)(int16_t pinIndex, GPIO_PullUpDown_t pull);
	GPIO_PullUpDown_t (*getPull)(int16_t pinIndex);
	_Bool (*setOutputType)(int16_t pinIndex, GPIO_OutputType_t outputType);
	GPIO_OutputType_t (*getOutputType)(int16_t pinIndex);
	_Bool (*setRiseTime)(int16_t pinIndex, GPIO_RiseTime_t riseTime);
	GPIO_RiseTime_t (*getRiseTime)(int16_t pinIndex);
} GPIO_PinControlInterface_t;


/** Registers an external GPIO block, registers an entry in the pin database, and Encapsulates pin control functions */
typedef struct GPIO_ControlInterface {
	int8_t (*registerExternGpioBlock)(GPIO_PinControlInterface_t* controlInterface);
	int16_t (*registerPin)(GPIO_PinInitStruct_t* initStruct);
	GPIO_PinControlInterface_t ctrl;
} GPIO_ControlInterface_t;


// DATATYPES FOR EMBEDDED SYSTEMS

/** I2C datatype for embedded systems */
typedef struct I2CDriver {
	_Bool (*readBytes)(uint8_t addr, char* buf, uint16_t numBytes, _Bool stop);
	_Bool (*writeBytes)(uint8_t addr, char* buf, uint16_t numBytes, _Bool stop);
} I2CDriver_t;


/** USART datatype for embedded systems */
typedef struct USARTDriver {
	uint16_t (*writeBytes)(const char* bytes, uint16_t numBytes);
	uint16_t (*writeLine)(const char* dataline);
	uint16_t (*rxBytesAvailable)(void);
	uint16_t (*readBytes)(char* buf, uint16_t numBytes);
	uint16_t (*readLine)(char* buf);
	uint16_t (*readLineTruncate)(char* buf, uint16_t maxLen);
} USARTDriver_t;


/** IOStream datatype for embedded systems */
typedef struct IOStream {
/**
	@brief   Write a specified number of bytes to the stream.
	@param   bytes     [in]  The input buffer.
	@param   numBytes  [in]  The number of bytes to write.
	@return  The number of bytes written to the stream.
*/
	uint16_t (*writeBytes)(const char* bytes, uint16_t numBytes);
/**
	@brief   Write a line to the stream. Line ending characters (determined by the implementation function) will be appended.
	@param   line       [in]   Pointer to the start of a NULL-terminated string containing the text to be written. Line ending characters will be added and so are not required.
	@return  The number of bytes written to the stream.
*/
	uint16_t (*writeLine)(const char* dataline);
/**
	@brief   Query the number of bytes available to read.
	@return  The number of bytes available to read.
*/
	uint16_t (*bytesAvailableToRead)(void);
/**
	@brief   Inspect a byte in the stream's buffer without removing it.
	@param   depth     [in]  Distance from the front of the read queue (i.e. the next byte to be read has depth 0, the byte after that has depth 1 and so on).
	@return  The byte value. In the case of an error (e.g. a byte does not exist at that depth) return an implementation-specific error code.
*/
	char (*peek)(uint16_t depth);
/**
	@brief   Read a specified number of bytes from the stream. If insufficient bytes are available, read all available bytes.
	@param   buf       [out]       The target buffer.
	@param   numBytes  [in]        The requested number of bytes.
	@return  The number of bytes read.
*/
	uint16_t (*readBytes)(char* buf, uint16_t numBytes);
/**
	@brief   Read the next available line from the stream. The implementation must define the line-ending sequence it uses to determine when a line is available. Line-ending characters are removed and the function outputs a NULL-terminated string.
	@param   buffer    [out]       The target buffer.
	@return  The length of the output string *not* including the NULL-terminator.
*/
	uint16_t (*readLine)(char* buf);
/**
	@brief   Read the next available line from the stream but truncate the output.
	 *          The implementation must define the line-ending sequence it uses to
	 *          determine when a line is available. Line-ending characters are
	 *          removed and the function outputs a NULL-terminated string. Where
	 *          the output string would exceed the maximum specified length,
	 *          truncate the string appropriately whilst still ensuring that the
	 *          NULL-terminator is the last byte in the output.
	@param   buffer    [out]       The target buffer.
	@param   maxLen    [in]        The maximum permissible length of the output (including the NULL-terminator) in bytes.
	@return  The length of the output string *not* including the NULL-terminator.
*/
	uint16_t (*readLineTruncate)(char* buf, uint16_t maxLen);
} IOStream_t;


// MISCELLANEOUS DATATYPES & MACROS

/** comp_t is a 16-bit "floating" point number with a 3-bit base 8 exponent and a 13-bit fraction */
typedef uint16_t   comp_t;
typedef struct Bigint {
	struct Bigint* next;
	int k, maxwds, sign, wds;
	unsigned long x[1];
} Bigint;
#define __BIONIC_FORTIFY_UNKNOWN_SIZE   ((size_t)-1)
typedef int   t_success;
typedef int   pri_t;
typedef int32_t   devmajor_t, devminor_t;
#define __devmajor_t   devmajor_t
#define __devminor_t   devminor_t
#define NODEVMAJOR   (-1)
typedef int64_t   fssh_bigtime_t;
typedef int32_t   fssh_status_t;
typedef uint32_t   fssh_type_code;
typedef char*   data_t;
typedef char   string_t[1024];
typedef unsigned char   bitstr_t;
typedef int*   intarray_t;
typedef struct attr_packed ustat {
#   if (defined(MIPS) || (defined(SPARC) && (!defined(ARM64))))
	long f_tfree;
#   else
	int f_tfree;
#   endif
	unsigned long f_tinode;
	char f_fname[6];
	char f_fpack[6];
} ustat_t;
#define __asan_bad_ustat   ustat_t
typedef int64_t   user_long_t;
typedef uint64_t   user_ulong_t;
typedef uint64_t   user_addr_t;
typedef uint64_t   user_size_t;
typedef int64_t   user_ssize_t;
typedef int64_t   user_off_t;
typedef int64_t   user_time_t;
#define USER_ADDR_NULL  ((user_addr_t)0)
#define CAST_USER_ADDR_T(__ptr)   ((user_addr_t)((uintptr_t)(__ptr)))
typedef int32_t   user32_long_t;
typedef uint32_t   user32_ulong_t;
typedef uint32_t   user32_addr_t;
typedef uint32_t   user32_size_t;
typedef int32_t   user32_ssize_t;
typedef int64_t align4   user32_off_t;
typedef int32_t   user32_time_t;
typedef int64_t align8   user64_long_t;
typedef uint64_t align8   user64_ulong_t;
typedef uint64_t align8   user64_addr_t;
typedef uint64_t align8   user64_size_t;
typedef int64_t align8   user64_ssize_t;
typedef int64_t align8   user64_off_t;
typedef int64_t align8   user64_time_t;
/** offset of a char string in log needs to be aligned on some systems because it is passed to db_set as a string */
typedef struct log_t_struct {
	char data[SIZEOF_CHAR + 4];
	char str[1];
} log_t;
#define CHAR_T_OFFSET   ((char*)(((log_t*)0)->str) - (char*)0)
#define PRUint8   unsigned char
#if ((IS_CPLUSPLUS && (!defined(__GNUC__))) && ((defined(HPUX) && (__cplusplus < 199707L)) || (defined(SCO) && (__cplusplus == 1L))))
#   define PRInt8   char
#else
#   define PRInt8   signed char
#endif
#if (BYTES_PER_SHORT == 2)
#   define PRUint16   unsigned short
#   define PRInt16   short
#else
#   error   "No suitable type for PRInt16/PRUint16!"
#endif
#if (BYTES_PER_INT >= 2)
#   define PRIntn   int
#   define PRUintn   unsigned int
#else
#   error   "int is a byte in length!"
#endif
#if (BYTES_PER_INT == 4)
#   define PRUint32   unsigned int
#   define PRInt32   int
#   define PR_INT32(x)   x
#   define PR_UINT32(x)   x ## U
#elif (BYTES_PER_LONG == 4)
#   define PRUint32   unsigned long
#   define PRInt32   long
#   define PR_INT32(x)   x ## L
#   define PR_UINT32(x)   x ## UL
#else
#   error   "No suitable type found for PRInt32/PRUint32!"
#endif
#ifdef HAVE_LONG_LONG
#   if (defined(OSAPPLE) || defined(OSANDROID) || defined(OSOPENBSD))
#      define ALTERNATE_INT64_TYPEDEF
#   endif
#   if ((BYTES_PER_LONG == 8) && (!defined(ALTERNATE_INT64_TYPEDEF)))
#      define PRUint64   unsigned long
#      define PRInt64   long
#      define PR_INT64(x)   x ## L
#      define PR_UINT64(x)   x ## UL
#   elif ((defined(OSWINDOWS) && defined(ENV32BIT)) && (!defined(__GNUC__)))
#      define PRUint64   uint64_t
#      define PRInt64   int64_t
#      define PR_INT64(x)   x ## i64
#      define PR_UINT64(x)   x ## ui64
#   else
#      define PRUint64   unsigned long long
#      define PRInt64   long long
#      define PR_INT64(x)   x ## LL
#      define PR_UINT64(x)   x ## ULL
#   endif  // BYTES_PER_LONG == 8
#else  // HAVE_LONG_LONG
typedef struct PRInt64_struct {
#   if IS_LITTLE_ENDIAN
	PRUint32 lo, hi;
#   else
	PRUint32 hi, lo;
#   endif
} PRInt64;
typedef PRInt64   PRUint64;
#endif  // HAVE_LONG_LONG
#define PRFloat64   double
#define PRSize   size_t
#define PROffset32   PRInt32
#define PROffset64   PRInt64
#define PRPtrdiff   ptrdiff_t
typedef struct jsre_stat {
	unsigned int dev, ino, mode, nlink, uid, gid, rdev;
	unsigned int size, blksize, blocks, atime, mtime, ctime;
} jsre_stat_t;
/** Structure for building "argc/argv" vector of arguments */
typedef struct attr_packed _args {
	char* bp;  // Argument
	size_t blen;  // Buffer length
	size_t len;  // Argument length
	unsigned char flags;  // If allocated space
} ARGS;
/** Used to identify a trace stream attributes object */
typedef int64_t   trace_attr_t;
/** Used to identify a trace event type */
typedef int64_t   trace_event_id_t;
/**  Used to identify a trace event type set */
typedef uint64_t   trace_event_set_t;
/** Used to identify a trace stream */
typedef uint64_t   trace_id_t;


// UTSNAME DATATYPE

#if (!(defined(UTSNAME_H) || defined(SYS_UTSNAME_H) || defined(_SYS_UTSNAME_H) || defined(_SYS_UTSNAME_H_)))
#define UTSNAME_H   (1)
#define SYS_UTSNAME_H   (1)
#define _SYS_UTSNAME_H   (1)
#define _SYS_UTSNAME_H_   (1)


#define __UTSNAMELEN   256
#define _SYS_NAMELEN   __UTSNAMELEN
#define SYS_NMLN   __UTSNAMELEN


typedef struct utsname {
	char sysname[SYS_NMLN];  // Name of the OS
	char nodename[SYS_NMLN];  // Name of this node (network related)
	char release[SYS_NMLN];  // Current release level
	char version[SYS_NMLN];  // Current version level
	char machine[SYS_NMLN];  // Name of the hardware type
	char domainname[SYS_NMLN];
} utsname_t;


#endif  // UTSNAME_H


// FUNCTION MACROS FOR INTEGER CONSTANTS

#ifdef __INTMAX_C_SUFFIX__
#   define __int_join_(n, suffix)   n ## suffix
#   define __int_join(n, suffix)   n ## suffix
#endif
#define __stdint_join3(a, b, c)   a ## b ## c
#define  __intn_t(n)   __stdint_join3("int", n, _t)
#define __uintn_t(n)   __stdint_join3("uint", n, _t)
#define __int_c_join(a, b)   a ## b
#define __int_c(v, suffix)   __int_c_join(v, suffix)
#define __uint_c(v, suffix)   __int_c_join(v##U, suffix)
#define  __INTN_MIN(n)   __stdint_join3("INT", n, "_MIN")
#define  __INTN_MAX(n)   __stdint_join3("INT", n, "_MAX")
#define __UINTN_MAX(n)   __stdint_join3("UINT", n, "_MAX")
#if IS_NOT_CPLUSPLUS

#ifndef __INT8_C
/** Expands to an integer constant (of type int8_t) having the value specified by its argument */
#   define __INT8_C(num)   ((int8_t)num)
#endif
#ifndef INT8_C
/** Expands to an integer constant (of type int8_t) having the value specified by its argument */
#   define INT8_C(num)   __INT8_C((num))
#endif
#ifndef __INT16_C
#   define __INT16_C(num)   ((int16_t)num)
#endif
#ifndef INT16_C
#   define INT16_C(num)   __INT16_C((num))
#endif
#ifndef __INT32_C
#   define __INT32_C(num)   ((int32_t)(num ## L))
#endif
#ifndef INT32_C
#   define INT32_C(num)   __INT32_C((num))
#endif
#ifndef __UINT8_C
#   define __UINT8_C(num)   ((uint8_t)num)
#endif
#ifndef UINT8_C
#   define UINT8_C(num)   __UINT8_C((num))
#endif
#ifndef __UINT16_C
#   define __UINT16_C(num)   ((uint16_t)num)
#endif
#ifndef UINT16_C
#   define UINT16_C(num)   __UINT16_C((num))
#endif
#ifndef __UINT32_C
#   define __UINT32_C(num)   ((uint32_t)(num ## UL))
#endif
#ifndef UINT32_C
#   define UINT32_C(num)   __UINT32_C((num))
#endif
#if IS_WORDSIZE_64
#   ifndef __INT64_C
/** Expands to an integer constant (of type int64_t) having the value specified by its argument */
#      define __INT64_C(num)   ((int64_t)num ## L)
#      define INT64_C(num)   __INT64_C((num))
#   else
#      define INT64_C(num)   __INT64_C((num))
#   endif
#   ifndef __UINT64_C
/** Expands to an integer constant (of type uint64_t) having the value specified by its argument */
#      define __UINT64_C(num)   ((uint64_t)num ## UL)
#      define UINT64_C(num)   __UINT64_C((num))
#   else
#      define UINT64_C(num)   __UINT64_C((num))
#   endif
#else  // WORDSIZE == 32
#   ifndef __INT64_C
/** Expands to an integer constant (of type int64_t) having the value specified by its argument */
#      define __INT64_C(num)   ((int64_t)num ## LL)
#      define INT64_C(num)   __INT64_C((num))
#   else
#      define INT64_C(num)   __INT64_C((num))
#   endif
#   ifndef __UINT64_C
#      define __UINT64_C(num)   ((uint64_t)num ## ULL)
#      define UINT64_C(num)   __UINT64_C((num))
#   else
#      define UINT64_C(num)   __UINT64_C((num))
#   endif
#endif  // __WORDSIZE
#ifdef __INTMAX_C
/** Expands to an integer constant (of type intmax_t) having the value specified by its argument */
#   define INTMAX_C(num)   __INTMAX_C((num))
#else
#   define __INTMAX_C(num)   ((int64_t)(num) ## LL)
#   define INTMAX_C(num)   __INTMAX_C((num))
#endif
#ifdef __UINTMAX_C
/** Expands to an integer constant (of type uintmax_t) having the value specified by its argument */
#   define UINTMAX_C(num)   __UINTMAX_C((num))
#else
#   define __UINTMAX_C(num)   ((uint64_t)(num) ## ULL)
#   define UINTMAX_C(num)   __UINTMAX_C((num))
#endif

#endif  // IS_NOT_CPLUSPLUS
#define LIT64(a)   __INT64_C(num)


// FUNCTION MACROS FOR UNCOMMON INTEGRAL CONSTANTS

#ifdef __INT24_TYPE__
#   ifdef __INT24_C_SUFFIX__
#      define INT24_C(n)   __int_c_join(n, __INT24_C_SUFFIX__)
#      define UINT24_C(n)   __uint_c(n, __INT24_C_SUFFIX__)
#   else
#      define INT24_C(n)   n
#      define UINT24_C(n)   (n ## U)
#   endif
#endif  // __INT24_TYPE__
#ifdef __INT40_TYPE__
#   ifdef __INT40_C_SUFFIX__
#      define INT40_C(n)   __int_c(n, __INT40_C_SUFFIX__)
#      define UINT40_C(n)   __uint_c(n, __INT40_C_SUFFIX__)
#   else
#      define INT40_C(n)   n
#      define UINT40_C(n)   (n ## U)
#   endif
#endif  // __INT40_TYPE__
#ifdef __INT48_TYPE__
#   ifdef __INT48_C_SUFFIX__
#      define INT48_C(n)   __int_c(n, __INT48_C_SUFFIX__)
#      define UINT48_C(n)   __uint_c(n, __INT48_C_SUFFIX__)
#   else
#      define INT48_C(n)   n
#      define UINT48_C(n)   (n ## U)
#   endif
#endif  // __INT48_TYPE__
#ifdef __INT56_TYPE__
#   ifdef __INT56_C_SUFFIX__
#      define INT56_C(n)   __int_c(n, __INT56_C_SUFFIX__)
#      define UINT56_C(n)   __uint_c(n, __INT56_C_SUFFIX__)
#   else
#      define INT56_C(n)   n
#      define UINT56_C(n)   (n ## U)
#   endif
#endif  // __INT56_TYPE__


// LIMITS OF DATATYPES

// MINIMUM OF SIGNED FIXED-WIDTH INTEGRAL TYPES
/** Minimum value of an object of type int8_t */
#define INT8_MIN   (-128)  // ((-0x7f) - 1); 0xffffff80
#ifndef MIN_8
#   define MIN_8   INT8_MIN
#endif
/** Minimum value of an object of type int16_t */
#define INT16_MIN   (-32768)  // ((-0x7fff) - 1); 0xffff8000
#ifndef MIN_16
#   define MIN_16   INT16_MIN
#endif
#ifdef __INT32_MIN__
/** Minimum value of an object of type int32_t */
#   define INT32_MIN   __INT32_MIN__
#else
/** Minimum value of an object of type int32_t */
#   define INT32_MIN   (-2147483648)  // ((-0x7fffffff) - 1)
#endif
#ifndef MIN_32
#   define MIN_32   INT32_MIN
#endif
#ifdef __INT64_MIN__
/** Minimum value of an object of type int64_t */
#   define INT64_MIN   __INT64_MIN__
#else
/** Minimum value of an object of type int64_t */
#   define INT64_MIN   ((-0x7fffffffffffffff) - 1)
#endif
#ifndef MIN_64
#   define MIN_64   INT64_MIN
#endif
#ifndef INT128_MIN
/** Minimum value of an object of type int128_t */
#   define INT128_MIN   ((int128_t)-170141183460469231731687303715884105728i128)
#endif
#ifndef __INT128_MIN__
/** Minimum value of an object of type int128_t */
#   define __INT128_MIN__   INT128_MIN
#endif
// MAXIMUM OF SIGNED FIXED-WIDTH INTEGRAL TYPES
/** Maximum value of an object of type int8_t */
#define INT8_MAX   (0x7f)  // (127)
#ifndef MAX_8
#   define MAX_8   INT8_MAX
#endif
/** Maximum value of an object of type int16_t */
#define INT16_MAX   (0x7fff)  // (32767)
#ifndef MAX_16
#   define MAX_16   INT16_MAX
#endif
#ifdef __INT32_MAX__
/** Maximum value of an object of type int32_t */
#   define INT32_MAX   __INT32_MAX__
#else
/** Maximum value of an object of type int32_t */
#   define INT32_MAX   (0x7fffffff)  // (2147483647)
#endif
#ifndef MAX_32
#   define MAX_32   INT32_MAX
#endif
#ifndef INT_MAX_32_BITS
#   define INT_MAX_32_BITS   2147483647
#endif
#ifdef __INT64_MAX__
/** Maximum value of an object of type int64_t */
#   define INT64_MAX   __INT64_MAX__
#else
/** Maximum value of an object of type int64_t */
#   define INT64_MAX   (0x7fffffffffffffffLL)  // 9223372036854775807LL
#endif
#ifndef MAX_64
#   define MAX_64   INT64_MAX
#endif
#if SUPPORTS_INT128
#   ifndef INT128_MAX
/** Maximum value of an object of type int128_t */
#      define INT128_MAX   ((int128_t)170141183460469231731687303715884105727i128)
#   endif
#   ifndef __INT128_MAX__
/** Maximum value of an object of type int128_t */
#      define __INT128_MAX__   INT128_MAX
#   endif
#endif
// MAXIMUM OF UNSIGNED FIXED-WIDTH INTEGRAL TYPES
/** Maximum value of an object of type uint8_t */
#define UINT8_MAX   (0xffU)  // (255U)
/** Maximum value of an object of type uint16_t */
#define UINT16_MAX   (0xffffU)  // (65535U)
#ifdef __UINT32_MAX__
/** Maximum value of an object of type uint32_t */
#   define UINT32_MAX   __UINT32_MAX__
#else
/** Maximum value of an object of type uint32_t */
#   define UINT32_MAX   (0xffffffffU)  // (4294967295U)
#endif
/** Maximum value storable in ppnum_t */
#define PPNUM_MAX   UINT32_MAX
#define ATM_SUBAID32_MAX   UINT32_MAX
#ifdef __UINT64_MAX__
/** Maximum value of an object of type uint64_t */
#   define UINT64_MAX   __UINT64_MAX__
#else
/** Maximum value of an object of type uint64_t */
#   define UINT64_MAX   (0xffffffffffffffffULL)
#endif
#define SUB_AID_MAX   UINT64_MAX
#if SUPPORTS_INT128
#   ifndef UINT128_MAX
/** Maximum value of an object of type uint128_t */
#      define UINT128_MAX   ((uint128_t)0xffffffffffffffffffffffffffffffffUi128)
#   endif
#   ifndef __UINT128_MAX__
/** Maximum value of an object of type uint128_t */
#      define __UINT128_MAX__   UINT128_MAX
#   endif
#endif
// MINIMUM OF SIGNED FIXED-WIDTH INTEGRAL TYPES HAVING A MINIMUM SIZE
#ifdef __INT_LEAST8_MIN__
#   define INT_LEAST8_MIN   __INT_LEAST8_MIN__
#else
#   define INT_LEAST8_MIN   INT8_MIN
#   define __INT_LEAST8_MIN__   INT_LEAST8_MIN
#endif
#ifdef __INT_LEAST16_MIN__
#   define INT_LEAST16_MIN   __INT_LEAST16_MIN__
#else
#   define INT_LEAST16_MIN   INT16_MIN
#   define __INT_LEAST16_MIN__   INT_LEAST16_MIN
#endif
#ifdef __INT_LEAST32_MIN__
#   define INT_LEAST32_MIN   __INT_LEAST32_MIN__
#else
#   define INT_LEAST32_MIN   INT32_MIN
#   define __INT_LEAST32_MIN__   INT32_MIN
#endif
#ifdef __INT_LEAST64_MIN__
#   define INT_LEAST64_MIN   __INT_LEAST64_MIN__
#else
#   define INT_LEAST64_MIN   INT64_MIN
#   define __INT_LEAST64_MIN__   INT64_MIN
#endif
#if SUPPORTS_INT128
#   ifdef __INT_LEAST128_MIN__
#      define INT_LEAST128_MIN   __INT_LEAST128_MIN__
#   else
#      define INT_LEAST128_MIN   INT128_MIN
#      define __INT_LEAST128_MIN__   INT128_MIN
#   endif
#endif
// MAXIMUM OF SIGNED FIXED-WIDTH INTEGRAL TYPES HAVING A MINIMUM SIZE
#ifdef __INT_LEAST8_MAX__
#   define INT_LEAST8_MAX   __INT_LEAST8_MAX__
#else
#   define INT_LEAST8_MAX   INT8_MAX
#   define __INT_LEAST8_MAX__   INT8_MAX
#endif
#ifdef __INT_LEAST16_MAX__
#   define INT_LEAST16_MAX   __INT_LEAST16_MAX__
#else
#   define INT_LEAST16_MAX   INT16_MAX
#   define __INT_LEAST16_MAX__   INT16_MAX
#endif
#ifdef __INT_LEAST32_MAX__
#   define INT_LEAST32_MAX   __INT_LEAST32_MAX__
#else
#   define INT_LEAST32_MAX   INT32_MAX
#   define __INT_LEAST32_MAX__   INT32_MAX
#endif
#ifdef __INT_LEAST64_MAX__
#   define INT_LEAST64_MAX   __INT_LEAST64_MAX__
#else
#   define INT_LEAST64_MAX   INT64_MAX
#   define __INT_LEAST64_MAX__   INT64_MAX
#endif
#if SUPPORTS_INT128
#   ifdef __INT_LEAST128_MAX__
#      define INT_LEAST128_MAX   __INT_LEAST128_MAX__
#   else
#      define INT_LEAST128_MAX   INT128_MAX
#      define __INT_LEAST128_MAX__   INT128_MAX
#   endif
#endif
// MAXIMUM OF UNSIGNED FIXED-WIDTH INTEGRAL TYPES HAVING A MINIMUM SIZE
#ifdef __UINT_LEAST8_MAX__
/** Maximum value of an object of type uint_least8_t */
#   define UINT_LEAST8_MAX   __UINT_LEAST8_MAX__
#else
/** Maximum value of an object of type uint_least8_t */
#   define UINT_LEAST8_MAX   (0xff)  // 255
/** Maximum value of an object of type uint_least8_t */
#   define __UINT_LEAST8_MAX__   UINT_LEAST8_MAX
#endif
#ifdef __UINT_LEAST16_MAX__
#   define UINT_LEAST16_MAX   __UINT_LEAST16_MAX__
#else
#   define UINT_LEAST16_MAX   (0xffff)  // 65535
#   define __UINT_LEAST16_MAX__   UINT_LEAST16_MAX
#endif
#ifdef __UINT_LEAST32_MAX__
/** Maximum value of an object of type uint_least32_t */
#   define UINT_LEAST32_MAX   __UINT_LEAST32_MAX__
#else
/** Maximum value of an object of type uint_least32_t */
#   define UINT_LEAST32_MAX   UINT32_MAX
/** Maximum value of an object of type uint_least32_t */
#   define __UINT_LEAST32_MAX__   UINT32_MAX
#endif
#ifdef __UINT_LEAST64_MAX__
#   define UINT_LEAST64_MAX   __UINT_LEAST64_MAX__
#else
#   define UINT_LEAST64_MAX   UINT64_MAX
#   define __UINT_LEAST64_MAX__   UINT64_MAX
#endif
#if SUPPORTS_INT128
#   ifdef __UINT_LEAST128_MAX__
#      define UINT_LEAST128_MAX   __UINT_LEAST128_MAX__
#   else
#      define UINT_LEAST128_MAX   UINT128_MAX
#      define __UINT_LEAST128_MAX__   UINT128_MAX
#   endif
#endif
// MINIMUM OF SIGNED FAST FIXED-WIDTH INTEGRAL TYPES
#ifdef __INT_FAST8_MIN__
#   define INT_FAST8_MIN   __INT_FAST8_MIN__
#else
#   define INT_FAST8_MIN   (-128)
#   define __INT_FAST8_MIN__   INT_FAST8_MIN
#endif
#if IS_WORDSIZE_64
#   define INT_FAST16_MIN   INT64_MIN
#   define INT_FAST32_MIN   INT64_MIN
#else
#   define INT_FAST16_MIN   INT32_MIN
#   define INT_FAST32_MIN   INT32_MIN
#endif
#ifndef __INT_FAST16_MIN__
#   define __INT_FAST16_MIN__   INT_FAST16_MIN
#endif
#ifndef __INT_FAST32_MIN__
#   define __INT_FAST32_MIN__   INT_FAST32_MIN
#endif
#ifdef __INT_FAST64_MIN__
#   define INT_FAST64_MIN   __INT_FAST64_MIN__
#else
#   define INT_FAST64_MIN   INT64_MIN
#   define __INT_FAST64_MIN__   INT64_MIN
#endif
#if SUPPORTS_INT128
#   ifndef INT_FAST128_MIN
#      define INT_FAST128_MIN   INT128_MIN
#   endif
#endif
// MAXIMUM OF SIGNED FAST FIXED-WIDTH INTEGRAL TYPES
#ifdef __INT_FAST8_MAX__
#   define INT_FAST8_MAX   __INT_FAST8_MAX__
#else
#   define INT_FAST8_MAX   (127)
#endif
#ifdef __INT_FAST16_MAX__
#   define INT_FAST16_MAX   __INT_FAST16_MAX__
#else
#   if IS_WORDSIZE_64
#      define INT_FAST16_MAX   INT64_MAX
#   else
#      define INT_FAST16_MAX   INT32_MAX
#   endif
#endif
#ifdef __INT_FAST32_MAX__
#   define INT_FAST32_MAX   __INT_FAST32_MAX__
#else
#   if IS_WORDSIZE_64
#      define INT_FAST32_MAX   INT64_MAX
#   else
#      define INT_FAST32_MAX   INT32_MAX
#   endif
#   define __INT_FAST32_MAX__   INT_FAST32_MAX
#endif
#ifdef __INT_FAST64_MAX__
#   define INT_FAST64_MAX   __INT_FAST64_MAX__
#else
#   define INT_FAST64_MAX   INT64_MAX
#   define __INT_FAST64_MAX__   INT64_MAX
#endif
#if SUPPORTS_INT128
#   ifdef __INT_FAST128_MAX__
#      define INT_FAST128_MAX   __INT_FAST128_MAX__
#   else
#      define INT_FAST128_MAX   INT128_MAX
#      define __INT_FAST128_MAX__   INT128_MAX
#   endif
#endif
// MAXIMUM OF UNSIGNED FAST FIXED-WIDTH INTEGRAL TYPES
#ifdef __UINT_FAST8_MAX__
#   define UINT_FAST8_MAX   __UINT_FAST8_MAX__
#else
#   define UINT_FAST8_MAX   (255U)
#endif
#ifdef __UINT_FAST16_MAX__
#   define UINT_FAST16_MAX   __UINT_FAST16_MAX__
#else
#   if IS_WORDSIZE_64
#      define UINT_FAST16_MAX   UINT64_MAX
#   else
#      define UINT_FAST16_MAX   UINT32_MAX
#   endif
#endif
#ifdef __UINT_FAST32_MAX__
#   define UINT_FAST32_MAX   __UINT_FAST32_MAX__
#else
#   if IS_WORDSIZE_64
#      define UINT_FAST32_MAX   UINT64_MAX
#   else
#      define UINT_FAST32_MAX   UINT32_MAX
#   endif
#endif
#ifdef __UINT_FAST64_MAX__
#   define UINT_FAST64_MAX   __UINT_FAST64_MAX__
#else
#   define UINT_FAST64_MAX   UINT64_MAX
#   define __UINT_FAST64_MAX__   UINT64_MAX
#endif
#if SUPPORTS_INT128
#   ifdef __UINT_FAST128_MAX__
#      define UINT_FAST128_MAX   __UINT_FAST128_MAX__
#   else
#      define UINT_FAST128_MAX   UINT128_MAX
#      define __UINT_FAST128_MAX__   UINT128_MAX
#   endif
#endif
// MAXIMUM/MINIMUM VALUES OF UNCOMMON FIXED-WIDTH INTEGRAL DATATYPES
#ifdef __INT24_TYPE__
#   define INT24_MAX   INT24_C(8388607)
#   define INT24_MIN   ((-INT24_C(8388607)) - 1)
#   define UINT24_MAX   UINT24_C(16777215)
#   define INT_LEAST24_MIN   INT24_MIN
#   define INT_LEAST24_MAX   INT24_MAX
#   define UINT_LEAST24_MAX   UINT24_MAX
#   define INT_FAST24_MIN   INT24_MIN
#   define INT_FAST24_MAX   INT24_MAX
#   define UINT_FAST24_MAX   UINT24_MAX
#   define __INT_LEAST16_MIN   INT24_MIN
#   define __INT_LEAST16_MAX   INT24_MAX
#   define __UINT_LEAST16_MAX   UINT24_MAX
#   define __INT_LEAST8_MIN   INT24_MIN
#   define __INT_LEAST8_MAX   INT24_MAX
#   define __UINT_LEAST8_MAX   UINT24_MAX
#endif  // __INT24_TYPE__
#ifdef __INT40_TYPE__
#   define INT40_MAX   INT40_C(549755813887)
#   define INT40_MIN   ((-INT40_C(549755813887)) - 1)
#   define UINT40_MAX   UINT40_C(1099511627775)
#   define INT_LEAST40_MIN   INT40_MIN
#   define INT_LEAST40_MAX   INT40_MAX
#   define UINT_LEAST40_MAX   UINT40_MAX
#   define INT_FAST40_MIN   INT40_MIN
#   define INT_FAST40_MAX   INT40_MAX
#   define UINT_FAST40_MAX   UINT40_MAX
#   define __INT_LEAST32_MIN   INT40_MIN
#   define __INT_LEAST32_MAX   INT40_MAX
#   define __UINT_LEAST32_MAX   UINT40_MAX
#   define __INT_LEAST16_MIN   INT40_MIN
#   define __INT_LEAST16_MAX   INT40_MAX
#   define __UINT_LEAST16_MAX   UINT40_MAX
#   define __INT_LEAST8_MIN   INT40_MIN
#   define __INT_LEAST8_MAX   INT40_MAX
#   define __UINT_LEAST8_MAX   UINT40_MAX
#endif  // __INT40_TYPE__
#ifdef __INT48_TYPE__
#   define INT48_MAX   INT48_C(140737488355327)
#   define INT48_MIN   ((-INT48_C(140737488355327)) - 1)
#   define UINT48_MAX   UINT48_C(281474976710655)
#   define INT_LEAST48_MIN   INT48_MIN
#   define INT_LEAST48_MAX   INT48_MAX
#   define UINT_LEAST48_MAX   UINT48_MAX
#   define INT_FAST48_MIN   INT48_MIN
#   define INT_FAST48_MAX   INT48_MAX
#   define UINT_FAST48_MAX   UINT48_MAX
#   define __INT_LEAST32_MIN   INT48_MIN
#   define __INT_LEAST32_MAX   INT48_MAX
#   define __UINT_LEAST32_MAX   UINT48_MAX
#   define __INT_LEAST16_MIN   INT48_MIN
#   define __INT_LEAST16_MAX   INT48_MAX
#   define __UINT_LEAST16_MAX   UINT48_MAX
#   define __INT_LEAST8_MIN   INT48_MIN
#   define __INT_LEAST8_MAX   INT48_MAX
#   define __UINT_LEAST8_MAX   UINT48_MAX
#endif  // __INT48_TYPE__
#ifdef __INT56_TYPE__
#   define INT56_MAX   INT56_C(36028797018963967)
#   define INT56_MIN   ((-INT56_C(36028797018963967)) - 1)
#   define UINT56_MAX   UINT56_C(72057594037927935)
#   define INT_LEAST56_MIN   INT56_MIN
#   define INT_LEAST56_MAX   INT56_MAX
#   define UINT_LEAST56_MAX   UINT56_MAX
#   define INT_FAST56_MIN   INT56_MIN
#   define INT_FAST56_MAX   INT56_MAX
#   define UINT_FAST56_MAX   UINT56_MAX
#   define __INT_LEAST32_MIN   INT56_MIN
#   define __INT_LEAST32_MAX   INT56_MAX
#   define __UINT_LEAST32_MAX   UINT56_MAX
#   define __INT_LEAST16_MIN   INT56_MIN
#   define __INT_LEAST16_MAX   INT56_MAX
#   define __UINT_LEAST16_MAX   UINT56_MAX
#   define __INT_LEAST8_MIN    INT56_MIN
#   define __INT_LEAST8_MAX    INT56_MAX
#   define __UINT_LEAST8_MAX   UINT56_MAX
#endif  // __INT56_TYPE__
// MAXIMUM/MINIMUM VALUES FOR INTPTR_T, UINTPTR_T, INTMAX_T, & UINTMAX_T
#ifdef __INTPTR_MAX__
#   define INTPTR_MAX   __INTPTR_MAX__
#else
/** Maximum value representable as type intptr_t */
#   define INTPTR_MAX   INT64_MAX
#endif
#ifdef __INTPTR_MIN__
#   define INTPTR_MIN   __INTPTR_MIN__
#else
/** Minimum value representable as type intptr_t */
#   define INTPTR_MIN   INT64_MIN
#endif
#ifdef __UINTPTR_MAX__
#   define UINTPTR_MAX   __UINTPTR_MAX__
#else
/** Maximum value representable as type uintptr_t */
#   define UINTPTR_MAX   UINT64_MAX
#endif
/** Minimum for largest signed fixed-width integral type */
#define INTMAX_MIN   ((-0x7fffffffffffffff) - 1)  // ((-(__INT64_C(9223372036854775807)))-1)
#ifndef INTMAX_MAX
/** Maximum for largest signed fixed-width integral type */
#   define INTMAX_MAX   (0x7fffffffffffffffLL)  // 9223372036854775807
#endif
#ifdef __UINTMAX_MAX__
/** Maximum for largest unsigned fixed-width integral type */
#   define UINTMAX_MAX   __UINTMAX_MAX__
#else
/** Maximum for largest unsigned fixed-width integral type */
#   define UINTMAX_MAX   (0xffffffffffffffffULL)  // 18446744073709551615ULL
/** Maximum for largest unsigned fixed-width integral type */
#   define __UINTMAX_MAX__   UINTMAX_MAX
#endif
// LIMITS OF `WCHAR_T`
#ifdef __WCHAR_MAX__
#   ifndef __WCHAR_MAX
#      define __WCHAR_MAX   __WCHAR_MAX__
#   endif
#elif ((L'\0' - 0x1) > 0x0)  // __WCHAR_MAX__ not defined
#   ifndef __WCHAR_MAX
#      define __WCHAR_MAX   (0xffffffffUL)
#   endif
#   define __WCHAR_MAX__   __WCHAR_MAX
#else
#   ifndef __WCHAR_MAX
#      define __WCHAR_MAX   (0x7fffffffL)
#   endif
#   define __WCHAR_MAX__   __WCHAR_MAX
#endif
#ifndef __DARWIN_WCHAR_MAX
#   define __DARWIN_WCHAR_MAX   __WCHAR_MAX__
#endif
#ifndef DARWIN_WCHAR_MAX
#   define DARWIN_WCHAR_MAX   __WCHAR_MAX__
#endif
#ifndef WCHAR_MAX
#   define WCHAR_MAX   __WCHAR_MAX
#endif
#ifdef __WCHAR_MIN__
#   ifndef __WCHAR_MIN
#      define __WCHAR_MIN   __WCHAR_MIN__
#   endif
#else
#   ifndef __WCHAR_MIN
#      define __WCHAR_MIN   (0x0U)
#   endif
#   define __WCHAR_MIN__   __WCHAR_MIN
#endif  // __WCHAR_MIN__
#ifndef __DARWIN_WCHAR_MIN
#   define __DARWIN_WCHAR_MIN   __WCHAR_MIN__
#endif
#ifndef DARWIN_WCHAR_MIN
#   define DARWIN_WCHAR_MIN   __WCHAR_MIN__
#endif
#ifndef WCHAR_MIN
#   define WCHAR_MIN   __WCHAR_MIN
#endif
// LIMITS OF `WINT_T`
#ifdef __WINT_MIN__
#   ifndef __WINT_MIN
#      define __WINT_MIN   __WINT_MIN__
#   endif
#else
#   ifndef __WINT_MIN
#      if (defined(__WINT_UNSIGNED__) && (__WINT_UNSIGNED__ => 1))
#         define __WINT_MIN   (0x0U)
#      else
#         error   "Add wint_t support for your target platform."
#      endif
#   endif
#   define __WINT_MIN__   __WINT_MIN
#endif
#ifndef WINT_MIN
#   define WINT_MIN   __WINT_MIN__
#endif
#ifdef __WINT_MAX__
#   ifndef __WINT_MAX
#      define __WINT_MAX   __WINT_MAX__
#   endif
#else
#   ifndef __WINT_MAX
#      define __WINT_MAX   (65535U)
#   endif
#   define __WINT_MAX__   __WINT_MAX
#endif
#ifndef WINT_MAX
#   define WINT_MAX   __WINT_MAX__
#endif
// LIMITS OF `CHAR`, `SCHAR`, & `UCHAR`
#ifdef __SCHAR_MIN__
/** Minimum value a `signed char` can hold */
#   define SCHAR_MIN   __SCHAR_MIN__
#else
/** Minimum value a `signed char` can hold */
#   define SCHAR_MIN   (-128)
/** Minimum value a `signed char` can hold */
#   define __SCHAR_MIN__   SCHAR_MIN
#endif
#ifdef __SCHAR_MAX__
/** Maximum value a `signed char` can hold */
#   define SCHAR_MAX   __SCHAR_MAX__
#else
/** Maximum value a `signed char` can hold */
#   define SCHAR_MAX   (0x7f)  // 127
/** Maximum value a `signed char` can hold */
#   define __SCHAR_MAX__   SCHAR_MAX
#endif
#ifdef __UCHAR_MAX__
/** Maximum value an `unsigned char` can hold (Minimum is 0) */
#   define UCHAR_MAX   __UCHAR_MAX__
#else
/** Maximum value an `unsigned char` can hold (Minimum is 0) */
#   define UCHAR_MAX   (255)
/** Maximum value an `unsigned char` can hold (Minimum is 0) */
#   define __UCHAR_MAX__   UCHAR_MAX
#endif
#if (defined(__CHAR_UNSIGNED__) && (__CHAR_UNSIGNED__ == 1))  // -funsigned-char
#   ifndef CHAR_MIN
/** Minimum value a `char` can hold */
#      define CHAR_MIN   (0x0)
#   endif
#   ifndef CHAR_MAX
/** Maximum value a `char` can hold */
#      define CHAR_MAX   UCHAR_MAX
#   endif
#else
#   ifndef __CHAR_SIGNED__
#      define __CHAR_SIGNED__   (1)
#   endif
#   ifndef CHAR_MIN
/** Minimum value a `char` can hold */
#      define CHAR_MIN   SCHAR_MIN
#   endif
#   ifndef CHAR_MAX
/** Maximum value a `char` can hold */
#      define CHAR_MAX   SCHAR_MAX
#   endif
#endif
// LIMITS OF BASIC INTEGRAL DATATYPES
/** Maximum length of any multibyte character in any locale */
#define MB_LEN_MAX   (16)
#ifdef __SHRT_MIN__
/** Minimum value a `signed short` can hold */
#   define SHRT_MIN   __SHRT_MIN__
#else
/** Minimum value a `signed short` can hold */
#   define SHRT_MIN   (-32768)
/** Minimum value a `signed short` can hold */
#   define __SHRT_MIN__   SHRT_MIN
#endif
#ifdef __SHRT_MAX__
/** Maximum value a `signed short` can hold */
#   define SHRT_MAX   __SHRT_MAX__
#else
/** Maximum value a `signed short` can hold */
#   define SHRT_MAX   (32767)
/** Maximum value a `signed short` can hold */
#   define __SHRT_MAX__   SHRT_MAX
#endif
/** Maximum value an `unsigned short` can hold (Minimum is 0) */
#define USHRT_MAX   (65535)
/** Minimum a `signed int` can hold */
#define INT_MIN   INT32_MIN
/** Maximum value a `signed int` can hold */
#define INT_MAX   INT32_MAX
/** Maximum number of bytes in N-to-1 collation mapping */
#define NL_NMAX   INT_MAX
/** Maximum number of sets per catalog */
#define NL_SETMAX   INT_MAX
/** Maximum value an `unsigned int` can hold (Minimum is 0) */
#define UINT_MAX   UINT32_MAX
#if IS_WORDSIZE_64
#   ifdef __LONG_MAX__
/** Minimum and maximum values a `signed long` can hold */
#      define LONG_MAX   __LONG_MAX__
#   else
/** Minimum and maximum values a `signed long` can hold */
#      define LONG_MAX   INT64_MAX
#      define __LONG_MAX__   LONG_MAX
#   endif
#   define LONG_MIN   INT64_MIN
/** Maximum value an `unsigned long` can hold (Minimum is 0) */
#   define ULONG_MAX   UINT64_MAX
#   define LONG_BIT   64
#else
#   ifdef __LONG_MAX__
/** Minimum and maximum values a `signed long` can hold */
#      define LONG_MAX   __LONG_MAX__
#   else
/** Minimum and maximum values a `signed long` can hold */
#      define LONG_MAX   INT32_MAX
#      define __LONG_MAX__   LONG_MAX
#   endif
#   define LONG_MIN   INT32_MIN
/** Maximum value an `unsigned long` can hold (Minimum is 0) */
#   define ULONG_MAX   UINT32_MAX
#   define LONG_BIT   32
#endif
#ifdef __LONG_LONG_MAX__
/** Maximum value a `signed long long` can hold */
#   define LONG_LONG_MAX   __LONG_LONG_MAX__
#else
/** Maximum value a `signed long long` can hold */
#   define LONG_LONG_MAX   (0x7fffffffffffffffLL)  // 9223372036854775807LL
#   define __LONG_LONG_MAX__   LONG_LONG_MAX
#endif
/** Maximum value a `signed long long` can hold */
#define LLONG_MAX   LONG_LONG_MAX
#define OFF_MAX   LLONG_MAX
/** Minimum value a `signed long long` can hold */
#define LLONG_MIN   ((signed long long)-9223372036854775807LL)
#define OFF_MIN   LLONG_MIN
/** Maximum value an `unsigned long long` can hold (Minimum is 0) */
#define ULLONG_MAX   (18446744073709551615ULL)  // 0xffffffffffffffffULL
#define LONGLONG_BIT   64
#define VLONG_MAX   LLONG_MAX
#define VLONG_MIN   LLONG_MIN
#define UVLONG_MAX   ULLONG_MAX
#define STRTOL_T_MINIMUM   0
#define STRTOL_T_MAXIMUM   ULONG_MAX
#if (UINT_MAX == ULONG_MAX)
#   define LONG_IS_INT
#endif
// LIMITS OF OTHER INTEGRAL DATATYPES
#if IS_WORDSIZE_64
#   define ABS_LONG_MIN   9223372036854775808UL
#else
#   define ABS_LONG_MIN   2147483648UL
#endif
#ifdef __SIZE_MAX__  // Limit of `size_t`
/** Maximum value representable as type size_t */
#   define SIZE_MAX   __SIZE_MAX__
#elif IS_WORDSIZE_64
/** Maximum value representable as type size_t */
#   define SIZE_MAX   INT64_MAX
#else  // WORDSIZE == 32
#   ifdef OSINTERIX
/** Maximum value representable as type size_t */
#      define SIZE_MAX   (unsigned long)UINT32_MAX
#   elif defined(OSSCO)  // SCO OpenServer
/** Maximum value representable as type size_t */
#      define SIZE_MAX   (unsigned int)UINT32_MAX
#   else
/** Maximum value representable as type size_t */
#      define SIZE_MAX   UINT32_MAX
#   endif
#endif  // Limit of `size_t`
#ifndef SIZE_T_MAX
#   define SIZE_T_MAX    SIZE_MAX
#endif
#ifndef __SIZE_MAX__
#   define __SIZE_MAX__    SIZE_MAX
#endif
#ifndef RSIZE_MAX
/** Maximum value representable as type rsize_t */
#   define RSIZE_MAX   (SIZE_MAX >> 1)
#endif
#ifndef __RSIZE_MAX__
/** Maximum value representable as type rsize_t */
#   define __RSIZE_MAX__   RSIZE_MAX
#endif
#if IS_WORDSIZE_32
#   ifndef __SSIZE_MAX__
#      define __SSIZE_MAX__   INT32_MAX
#   endif
#   ifndef SSIZE_MAX
#      define SSIZE_MAX   INT32_MAX
#   endif
#   ifndef __SSIZE_MIN__
#      define __SSIZE_MIN__   INT32_MIN
#   endif
#   ifndef SSIZE_MIN
#      define SSIZE_MIN   INT32_MIN
#   endif
#else  // WORDSIZE == 64
#   ifndef __SSIZE_MAX__
#      define __SSIZE_MAX__   INT64_MAX
#   endif
#   ifndef SSIZE_MAX
#      define SSIZE_MAX   INT64_MAX
#   endif
#   ifndef __SSIZE_MIN__
#      define __SSIZE_MIN__   INT64_MIN
#   endif
#   ifndef SSIZE_MIN
#      define SSIZE_MIN   INT64_MIN
#   endif
#endif
#ifdef __PTRDIFF_MIN__
/** Minimum value representable as type ptrdiff_t */
#   define PTRDIFF_MIN   __PTRDIFF_MIN__
#else
#   if IS_WORDSIZE_64
/** Minimum value representable as type ptrdiff_t */
#      define PTRDIFF_MIN   INT64_MIN
#   else
/** Minimum value representable as type ptrdiff_t */
#      define PTRDIFF_MIN   INT32_MIN
#   endif
#endif  // PTRDIFF_MIN
#ifdef __PTRDIFF_MAX__
/** Maximum value representable as type ptrdiff_t */
#   define PTRDIFF_MAX   __PTRDIFF_MAX__
#else
#   if IS_WORDSIZE_64
/** Maximum value representable as type ptrdiff_t */
#      define PTRDIFF_MAX   INT64_MAX
#   else
/** Maximum value representable as type ptrdiff_t */
#      define PTRDIFF_MAX   INT32_MAX
#   endif
#endif  // PTRDIFF_MAX
#ifdef __SIG_ATOMIC_MIN__
/** Minimum value representable as type sig_atomic_t */
#   define SIG_ATOMIC_MIN   __SIG_ATOMIC_MIN__
#else
/** Minimum value representable as type sig_atomic_t */
#   define SIG_ATOMIC_MIN   INT32_MIN
#   define __SIG_ATOMIC_MIN__   INT32_MIN
#endif
#ifdef __SIG_ATOMIC_MAX__
/** Maximum value representable as type sig_atomic_t */
#   define SIG_ATOMIC_MAX   __SIG_ATOMIC_MAX__
#else
/** Maximum value representable as type sig_atomic_t */
#   define SIG_ATOMIC_MAX   INT32_MAX
#   define __SIG_ATOMIC_MAX__   INT32_MAX
#endif
#define MAXUINT_PTR   (~((UINT_PTR)0x0))
#define MAXINT_PTR   ((INT_PTR)(MAXUINT_PTR >> 1))
#define MININT_PTR   (~(MAXINT_PTR))
#define MAXULONG_PTR   (~((ULONG_PTR)0x0))
#define MAXLONG_PTR   ((LONG_PTR)(MAXULONG_PTR >> 1))
#define MINLONG_PTR   (~(MAXLONG_PTR))
#define MAXUHALF_PTR   ((UHALF_PTR)~0x0)
#define MAXHALF_PTR   ((HALF_PTR)(MAXUHALF_PTR >> 1))
#define MINHALF_PTR   (~MAXHALF_PTR)
#define MAXUINT   ((UINT)~((UINT)0x0))
#define MAXULONGLONG   ((ULONGLONG)~((ULONGLONG)0x0))
#ifndef UID_MAX
#   define UID_MAX   UINT32_MAX
#endif
#ifndef GID_MAX
#   define GID_MAX   UINT32_MAX
#endif
#ifndef UQUAD_MAX
#   define UQUAD_MAX   ((u_quad_t)UINT64_MAX)
#endif
#ifndef QUAD_MAX
#   define QUAD_MAX   ((quad_t)INT64_MAX)
#endif
#ifndef QUAD_MIN
#   define QUAD_MIN   ((quad_t)INT64_MIN)
#endif
#define SIGEV_MAX_SIZE   64
#define SIGEV_PAD_SIZE   13  // ((SIGEV_MAX_SIZE / 4) - 3)
#define INThr_MAX   __INT8_MAX__
#define INThr_MIN   (-(__INT8_MAX__ - 1))
#define INTuhr_MAX   __UINT8_MAX__
#define INTr_MAX   __INT16_MAX__
#define INTr_MIN   (-(__INT16_MAX__ - 1))
#define INTur_MAX   __UINT16_MAX__
#define INThk_MAX   __INT16_MAX__
#define INThk_MIN   (-(__INT16_MAX__ - 1))
#define INTuhk_MAX   __UINT16_MAX__
#define INTlr_MAX   __INT32_MAX__
#define INTlr_MIN   (-(__INT32_MAX__ - 1))
#define INTulr_MAX   __UINT32_MAX__
#define INTk_MAX   __INT32_MAX__
#define INTk_MIN   (-(__INT32_MAX__ - 1))
#define INTuk_MAX   __UINT32_MAX__
#define INTlk_MAX   __INT64_MAX__
#define INTlk_MIN   (-(__INT64_MAX__ - 1))
#define INTulk_MAX   __UINT64_MAX__
#define INTllk_MAX   __INT64_MAX__
#define INTllk_MIN   (-(__INT64_MAX__ - 1))
#define INTullk_MAX   __UINT64_MAX__
#if ((SIZE_MAX != ULONG_MAX) || (UINTMAX_MAX != ULLONG_MAX))
#   define ODD_TYPES   (1)
#   define HAS_ODD_TYPES   (1)
#else
#   define HAS_ODD_TYPES   (0)
#endif


// STDFIX DATATYPE LIMITS

#if SUPPORTS_STDFIX
// FBIT = Fractional bits macros
// IBIT = Integral bits macros
#ifdef __SFRACT_FBIT__
#   define SFRACT_FBIT   __SFRACT_FBIT__
#else
#   define __SFRACT_FBIT__   7
#   define SFRACT_FBIT   __SFRACT_FBIT__
#endif
#ifdef __SFRACT_IBIT__
#   define SFRACT_IBIT   __SFRACT_IBIT__
#else
#   define __SFRACT_IBIT__   0
#   define SFRACT_IBIT   __SFRACT_IBIT__
#endif
#ifdef __SFRACT_MIN__
#   define SFRACT_MIN   __SFRACT_MIN__
#else
#   define __SFRACT_MIN__   (-0.5HR-0.5HR)
#   define SFRACT_MIN   __SFRACT_MIN__
#endif
#ifdef __SFRACT_MAX__
#   define SFRACT_MAX   __SFRACT_MAX__
#else
#   define __SFRACT_MAX__   0X7FP-7HR  // 0.9921875HR || 0X1.FCP-1HR
#   define SFRACT_MAX   __SFRACT_MAX__
#endif
#ifdef __SFRACT_EPSILON__
#   define SFRACT_EPSILON   __SFRACT_EPSILON__
#else
#   define __SFRACT_EPSILON__   0x1P-7HR  // 0.0078125HR
#   define SFRACT_EPSILON   __SFRACT_EPSILON__
#endif
#ifdef __USFRACT_FBIT__
#   define USFRACT_FBIT   __USFRACT_FBIT__
#else
#   define __USFRACT_FBIT__   8
#   define USFRACT_FBIT   __USFRACT_FBIT__
#endif
#ifdef __USFRACT_IBIT__
#   define USFRACT_IBIT   __USFRACT_IBIT__
#else
#   define __USFRACT_IBIT__   0
#   define USFRACT_IBIT   __USFRACT_IBIT__
#endif
#ifdef __USFRACT_MIN__
#   define USFRACT_MIN   __USFRACT_MIN__
#else
#   define __USFRACT_MIN__   0.0UHR
#   define USFRACT_MIN   __USFRACT_MIN__
#endif
#ifdef __USFRACT_MAX__
#   define USFRACT_MAX   __USFRACT_MAX__
#else
#   define __USFRACT_MAX__   0XFFP-8UHR  // 0.9921875UHR || 0X1.FCP-1UHR
#   define USFRACT_MAX   __USFRACT_MAX__
#endif
#ifdef __USFRACT_EPSILON__
#   define USFRACT_EPSILON   __USFRACT_EPSILON__
#else
#   define __USFRACT_EPSILON__   0x1P-8UHR  // 0.0078125UHR || 0X1P-7UHR
#   define USFRACT_EPSILON   __USFRACT_EPSILON__
#endif
#ifdef __FRACT_FBIT__
/** The number of bits that represent the fractional portion of Fract */
#   define FRACT_FBIT   __FRACT_FBIT__
#else
/** The number of bits that represent the fractional portion of Fract */
#   define __FRACT_FBIT__   15
/** The number of bits that represent the fractional portion of Fract */
#   define FRACT_FBIT   __FRACT_FBIT__
#endif
#ifdef __FRACT_IBIT__
/** The number of bits that represent the integer portion of Fract */
#   define FRACT_IBIT   __FRACT_IBIT__
#else
/** The number of bits that represent the integer portion of Fract */
#   define __FRACT_IBIT__   0
/** The number of bits that represent the integer portion of Fract */
#   define FRACT_IBIT   __FRACT_IBIT__
#endif
#ifdef __FRACT_MIN__
#   define FRACT_MIN   __FRACT_MIN__
#else
#   define __FRACT_MIN__   (-0.5R-0.5R)
#   define FRACT_MIN   __FRACT_MIN__
#endif
#ifdef __FRACT_MAX__
#   define FRACT_MAX   __FRACT_MAX__
#else
#   define __FRACT_MAX__   0X7FFFP-15R  // 0.999969482421875R || 0X1.FFFCP-1R
#   define FRACT_MAX   __FRACT_MAX__
#endif
#ifdef __FRACT_EPSILON__
#   define FRACT_EPSILON   __FRACT_EPSILON__
#else
#   define __FRACT_EPSILON__   0x1P-15R  // 0.000030517578125R
#   define FRACT_EPSILON   __FRACT_EPSILON__
#endif
#ifdef __UFRACT_FBIT__
#   define UFRACT_FBIT   __UFRACT_FBIT__
#else
#   define __UFRACT_FBIT__   16
#   define UFRACT_FBIT   __UFRACT_FBIT__
#endif
#ifdef __UFRACT_IBIT__
#   define UFRACT_IBIT   __UFRACT_IBIT__
#else
#   define __UFRACT_IBIT__   0
#   define UFRACT_IBIT   __UFRACT_IBIT__
#endif
#ifdef __UFRACT_MIN__
#   define UFRACT_MIN   __UFRACT_MIN__
#else
#   define __UFRACT_MIN__   0.0UR
#   define UFRACT_MIN   __UFRACT_MIN__
#endif
#ifdef __UFRACT_MAX__
#   define UFRACT_MAX   __UFRACT_MAX__
#else
#   define __UFRACT_MAX__   0XFFFFP-16UR  // 0.999969482421875UR || 0X1.FFFCP-1UR
#   define UFRACT_MAX   __UFRACT_MAX__
#endif
#ifdef __UFRACT_EPSILON__
#   define UFRACT_EPSILON   __UFRACT_EPSILON__
#else
#   define __UFRACT_EPSILON__   0x1P-16UR  // 0.000030517578125UR || 0X1P-15UR
#   define UFRACT_EPSILON   __UFRACT_EPSILON__
#endif
#ifdef __LFRACT_FBIT__
#   define LFRACT_FBIT   __LFRACT_FBIT__
#else
#   define __LFRACT_FBIT__   31  // 23
#   define LFRACT_FBIT   __LFRACT_FBIT__
#endif
#ifdef __LFRACT_IBIT__
#   define LFRACT_IBIT   __LFRACT_IBIT__
#else
#   define __LFRACT_IBIT__   0
#   define LFRACT_IBIT   __LFRACT_IBIT__
#endif
#ifdef __LFRACT_MIN__
#   define LFRACT_MIN   __LFRACT_MIN__
#else
#   define __LFRACT_MIN__   (-0.5LR-0.5LR)
#   define LFRACT_MIN   __LFRACT_MIN__
#endif
#ifdef __LFRACT_MAX__
#   define LFRACT_MAX   __LFRACT_MAX__
#else
#   define __LFRACT_MAX__   0X7FFFFFFFP-31LR  // 0.99999988079071044921875LR || 0X1.FFFFFCP-1LR
#   define LFRACT_MAX   __LFRACT_MAX__
#endif
#ifdef __LFRACT_EPSILON__
#   define LFRACT_EPSILON   __LFRACT_EPSILON__
#else
#   define __LFRACT_EPSILON__   0x1P-31LR  // 0.00000011920928955078125LR || 0X1P-23LR
#   define LFRACT_EPSILON   __LFRACT_EPSILON__
#endif
#ifdef __ULFRACT_FBIT__
#   define ULFRACT_FBIT   __ULFRACT_FBIT__
#else
#   define __ULFRACT_FBIT__   32
#   define ULFRACT_FBIT   __ULFRACT_FBIT__
#endif
#ifdef __ULFRACT_IBIT__
#   define ULFRACT_IBIT   __ULFRACT_IBIT__
#else
#   define __ULFRACT_IBIT__   0
#   define ULFRACT_IBIT   __ULFRACT_IBIT__
#endif
#ifdef __ULFRACT_MIN__
#   define ULFRACT_MIN   __ULFRACT_MIN__
#else
#   define __ULFRACT_MIN__   0.0ULR
#   define ULFRACT_MIN   __ULFRACT_MIN__
#endif
#ifdef __ULFRACT_MAX__
#   define ULFRACT_MAX   __ULFRACT_MAX__
#else
#   define __ULFRACT_MAX__   0XFFFFFFFFP-32ULR  // 0.99999988079071044921875ULR || 0X1.FFFFFCP-1ULR
#   define ULFRACT_MAX   __ULFRACT_MAX__
#endif
#ifdef __ULFRACT_EPSILON__
#   define ULFRACT_EPSILON   __ULFRACT_EPSILON__
#else
#   define __ULFRACT_EPSILON__   0x1P-32ULR  // 0.00000011920928955078125ULR || 0X1P-23ULR
#   define ULFRACT_EPSILON   __ULFRACT_EPSILON__
#endif
#ifdef __LLFRACT_FBIT__
#   define LLFRACT_FBIT   __LLFRACT_FBIT__
#else
#   define __LLFRACT_FBIT__   63
#   define LLFRACT_FBIT   __LLFRACT_FBIT__
#endif
#ifdef __LLFRACT_IBIT__
#   define LLFRACT_IBIT   __LLFRACT_IBIT__
#else
#   define __LLFRACT_IBIT__   0
#   define LLFRACT_IBIT   __LLFRACT_IBIT__
#endif
#ifdef __LLFRACT_MIN__
#   define LLFRACT_MIN   __LLFRACT_MIN__
#else
#   define __LLFRACT_MIN__   (-0.5LLR-0.5LLR)
#   define LLFRACT_MIN   __LLFRACT_MIN__
#endif
#ifdef __LLFRACT_MAX__
#   define LLFRACT_MAX   __LLFRACT_MAX__
#else
#   define __LLFRACT_MAX__   0X7FFFFFFFFFFFFFFFP-63LLR
#   define LLFRACT_MAX   __LLFRACT_MAX__
#endif
#ifdef __LLFRACT_EPSILON__
#   define LLFRACT_EPSILON   __LLFRACT_EPSILON__
#else
#   define __LLFRACT_EPSILON__   0x1P-63LLR
#   define LLFRACT_EPSILON   __LLFRACT_EPSILON__
#endif
#ifdef __ULLFRACT_FBIT__
#   define ULLFRACT_FBIT   __ULLFRACT_FBIT__
#else
#   define __ULLFRACT_FBIT__   64
#   define ULLFRACT_FBIT   __ULLFRACT_FBIT__
#endif
#ifdef __ULLFRACT_IBIT__
#   define ULLFRACT_IBIT   __ULLFRACT_IBIT__
#else
#   define __ULLFRACT_IBIT__   0
#   define ULLFRACT_IBIT   __ULLFRACT_IBIT__
#endif
#ifdef __ULLFRACT_MIN__
#   define ULLFRACT_MIN   __ULLFRACT_MIN__
#else
#   define __ULLFRACT_MIN__   0.0ULLR
#   define ULLFRACT_MIN   __ULLFRACT_MIN__
#endif
#ifdef __ULLFRACT_MAX__
#   define ULLFRACT_MAX   __ULLFRACT_MAX__
#else
#   define __ULLFRACT_MAX__   0XFFFFFFFFFFFFFFFFP-64ULLR
#   define ULLFRACT_MAX   __ULLFRACT_MAX__
#endif
#ifdef __ULLFRACT_EPSILON__
#   define ULLFRACT_EPSILON   __ULLFRACT_EPSILON__
#else
#   define __ULLFRACT_EPSILON__   0x1P-64ULLR
#   define ULLFRACT_EPSILON   __ULLFRACT_EPSILON__
#endif
#ifdef __SACCUM_FBIT__
#   define SACCUM_FBIT   __SACCUM_FBIT__
#else
#   define __SACCUM_FBIT__   7
#   define SACCUM_FBIT   __SACCUM_FBIT__
#endif
#ifdef __SACCUM_IBIT__
#   define SACCUM_IBIT   __SACCUM_IBIT__
#else
#   define __SACCUM_IBIT__   8
#   define SACCUM_IBIT   __SACCUM_IBIT__
#endif
#ifdef __SACCUM_MIN__
#   define SACCUM_MIN   __SACCUM_MIN__
#else
#   define __SACCUM_MIN__   (-0X1P7HK-0X1P7HK)  // (-8.0HK-8.0HK)
#   define SACCUM_MIN   __SACCUM_MIN__
#endif
#ifdef __SACCUM_MAX__
#   define SACCUM_MAX   __SACCUM_MAX__
#else
#   define __SACCUM_MAX__   0X7FFFP-7HK  // 15.9921875HK || 0X1.FFCP+3HK
#   define SACCUM_MAX   __SACCUM_MAX__
#endif
#ifdef __SACCUM_EPSILON__
#   define SACCUM_EPSILON   __SACCUM_EPSILON__
#else
#   define __SACCUM_EPSILON__   0x1P-7HK  // 0.0078125HK || 0X1P-7HK
#   define SACCUM_EPSILON   __SACCUM_EPSILON__
#endif
#ifdef __USACCUM_FBIT__
#   define USACCUM_FBIT   __USACCUM_FBIT__
#else
#   define __USACCUM_FBIT__   8
#   define USACCUM_FBIT   __USACCUM_FBIT__
#endif
#ifdef __USACCUM_IBIT__
#   define USACCUM_IBIT   __USACCUM_IBIT__
#else
#   define __USACCUM_IBIT__   8
#   define USACCUM_IBIT   __USACCUM_IBIT__
#endif
#ifdef __USACCUM_MIN__
#   define USACCUM_MIN   __USACCUM_MIN__
#else
#   define __USACCUM_MIN__   0.0UHK
#   define USACCUM_MIN   __USACCUM_MIN__
#endif
#ifdef __USACCUM_MAX__
#   define USACCUM_MAX   __USACCUM_MAX__
#else
#   define __USACCUM_MAX__   0XFFFFP-8UHK  // 15.9921875UHK || 0X1.FFCP+3UHK
#   define USACCUM_MAX   __USACCUM_MAX__
#endif
#ifdef __USACCUM_EPSILON__
#   define USACCUM_EPSILON   __USACCUM_EPSILON__
#else
#   define __USACCUM_EPSILON__   0x1P-8UHK  // 0.0078125UHK || 0X1P-7UHK
#   define USACCUM_EPSILON   __USACCUM_EPSILON__
#endif
#ifdef __ACCUM_FBIT__
#   define ACCUM_FBIT   __ACCUM_FBIT__
#else
#   define __ACCUM_FBIT__   15
#   define ACCUM_FBIT   __ACCUM_FBIT__
#endif
#ifdef __ACCUM_IBIT__
#   define ACCUM_IBIT   __ACCUM_IBIT__
#else
#   define __ACCUM_IBIT__   16
#   define ACCUM_IBIT   __ACCUM_IBIT__
#endif
#ifdef __ACCUM_MIN__
#   define ACCUM_MIN   __ACCUM_MIN__
#else
#   define __ACCUM_MIN__   (-0X1P15K-0X1P15K)  // (-8.0K-8.0K)
#   define ACCUM_MIN   __ACCUM_MIN__
#endif
#ifdef __ACCUM_MAX__
#   define ACCUM_MAX   __ACCUM_MAX__
#else
#   define __ACCUM_MAX__   0X7FFFFFFFP-15K  // 15.999969482421875K || 0X1.FFFFCP+3K
#   define ACCUM_MAX   __ACCUM_MAX__
#endif
#ifdef __ACCUM_EPSILON__
#   define ACCUM_EPSILON   __ACCUM_EPSILON__
#else
#   define __ACCUM_EPSILON__   0x1P-15K  // 0.000030517578125K || 0X1P-15K
#   define ACCUM_EPSILON   __ACCUM_EPSILON__
#endif
#ifdef __UACCUM_FBIT__
#   define UACCUM_FBIT   __UACCUM_FBIT__
#else
#   define __UACCUM_FBIT__   16
#   define UACCUM_FBIT   __UACCUM_FBIT__
#endif
#ifdef __UACCUM_IBIT__
#   define UACCUM_IBIT   __UACCUM_IBIT__
#else
#   define __UACCUM_IBIT__   16
#   define UACCUM_IBIT   __UACCUM_IBIT__
#endif
#ifdef __UACCUM_MIN__
#   define UACCUM_MIN   __UACCUM_MIN__
#else
#   define __UACCUM_MIN__   0.0UK
#   define UACCUM_MIN   __UACCUM_MIN__
#endif
#ifdef __UACCUM_MAX__
#   define UACCUM_MAX   __UACCUM_MAX__
#else
#   define __UACCUM_MAX__   0XFFFFFFFFP-16UK  // 15.999969482421875UK || 0X1.FFFFCP+3UK
#   define UACCUM_MAX   __UACCUM_MAX__
#endif
#ifdef __UACCUM_EPSILON__
#   define UACCUM_EPSILON   __UACCUM_EPSILON__
#else
#   define __UACCUM_EPSILON__   0x1P-16UK  // 0.000030517578125UK || 0X1P-15UK
#   define UACCUM_EPSILON   __UACCUM_EPSILON__
#endif
#ifdef __LACCUM_FBIT__
#   define LACCUM_FBIT   __LACCUM_FBIT__
#else
#   define __LACCUM_FBIT__   31
#   define LACCUM_FBIT   __LACCUM_FBIT__
#endif
#ifdef __LACCUM_IBIT__
#   define LACCUM_IBIT   __LACCUM_IBIT__
#else
#   define __LACCUM_IBIT__   32
#   define LACCUM_IBIT   __LACCUM_IBIT__
#endif
#ifdef __LACCUM_MIN__
#   define LACCUM_MIN   __LACCUM_MIN__
#else
#   define __LACCUM_MIN__   (-0X1P31LK-0X1P31LK)  // (-8.0LK-8.0LK)
#   define LACCUM_MIN   __LACCUM_MIN__
#endif
#ifdef __LACCUM_MAX__
#   define LACCUM_MAX   __LACCUM_MAX__
#else
#   define __LACCUM_MAX__   0X7FFFFFFFFFFFFFFFP-31LK  // 15.99999988079071044921875LK || 0X1.FFFFFFCP+3LK
#   define LACCUM_MAX   __LACCUM_MAX__
#endif
#ifdef __LACCUM_EPSILON__
#   define LACCUM_EPSILON   __LACCUM_EPSILON__
#else
#   define __LACCUM_EPSILON__   0x1P-31LK  // 0.00000011920928955078125LK || 0X1P-23LK
#   define LACCUM_EPSILON   __LACCUM_EPSILON__
#endif
#ifdef __ULACCUM_FBIT__
#   define ULACCUM_FBIT   __ULACCUM_FBIT__
#else
#   define __ULACCUM_FBIT__   32
#   define ULACCUM_FBIT   __ULACCUM_FBIT__
#endif
#ifdef __ULACCUM_IBIT__
#   define ULACCUM_IBIT   __ULACCUM_IBIT__
#else
#   define __ULACCUM_IBIT__   32
#   define ULACCUM_IBIT   __ULACCUM_IBIT__
#endif
#ifdef __ULACCUM_MIN__
#   define ULACCUM_MIN   __ULACCUM_MIN__
#else
#   define __ULACCUM_MIN__   0.0ULK
#   define ULACCUM_MIN   __ULACCUM_MIN__
#endif
#ifdef __ULACCUM_MAX__
#   define ULACCUM_MAX   __ULACCUM_MAX__
#else
#   define __ULACCUM_MAX__   0XFFFFFFFFFFFFFFFFP-32ULK  // 15.99999988079071044921875ULK || 0X1.FFFFFFCP+3ULK
#   define ULACCUM_MAX   __ULACCUM_MAX__
#endif
#ifdef __ULACCUM_EPSILON__
#   define ULACCUM_EPSILON   __ULACCUM_EPSILON__
#else
#   define __ULACCUM_EPSILON__   0x1P-32ULK  // 0.00000011920928955078125ULK || 0X1P-23ULK
#   define ULACCUM_EPSILON   __ULACCUM_EPSILON__
#endif
#ifdef __LLACCUM_FBIT__
#   define LLACCUM_FBIT   __LLACCUM_FBIT__
#else
#   define __LLACCUM_FBIT__   31
#   define LLACCUM_FBIT   __LLACCUM_FBIT__
#endif
#ifdef __LLACCUM_IBIT__
#   define LLACCUM_IBIT   __LLACCUM_IBIT__
#else
#   define __LLACCUM_IBIT__   32
#   define LLACCUM_IBIT   __LLACCUM_IBIT__
#endif
#ifdef __LLACCUM_MIN__
#   define LLACCUM_MIN   __LLACCUM_MIN__
#else
#   define __LLACCUM_MIN__   (-0X1P31LLK-0X1P31LLK)
#   define LLACCUM_MIN   __LLACCUM_MIN__
#endif
#ifdef __LLACCUM_MAX__
#   define LLACCUM_MAX   __LLACCUM_MAX__
#else
#   define __LLACCUM_MAX__   0X7FFFFFFFFFFFFFFFP-31LLK
#   define LLACCUM_MAX   __LLACCUM_MAX__
#endif
#ifdef __LLACCUM_EPSILON__
#   define LLACCUM_EPSILON   __LLACCUM_EPSILON__
#else
#   define __LLACCUM_EPSILON__   0x1P-31LLK
#   define LLACCUM_EPSILON   __LLACCUM_EPSILON__
#endif
#ifdef __ULLACCUM_FBIT__
#   define ULLACCUM_FBIT   __ULLACCUM_FBIT__
#else
#   define __ULLACCUM_FBIT__   32
#   define ULLACCUM_FBIT   __ULLACCUM_FBIT__
#endif
#ifdef __ULLACCUM_IBIT__
#   define ULLACCUM_IBIT   __ULLACCUM_IBIT__
#else
#   define __ULLACCUM_IBIT__   32
#   define ULLACCUM_IBIT   __ULLACCUM_IBIT__
#endif
#ifdef __ULLACCUM_MIN__
#   define ULLACCUM_MIN   __ULLACCUM_MIN__
#else
#   define __ULLACCUM_MIN__   0.0ULLK
#   define ULLACCUM_MIN   __ULLACCUM_MIN__
#endif
#ifdef __ULLACCUM_MAX__
#   define ULLACCUM_MAX   __ULLACCUM_MAX__
#else
#   define __ULLACCUM_MAX__   0XFFFFFFFFFFFFFFFFP-32ULLK
#   define ULLACCUM_MAX   __ULLACCUM_MAX__
#endif
#ifdef __ULLACCUM_EPSILON__
#   define ULLACCUM_EPSILON   __ULLACCUM_EPSILON__
#else
#   define __ULLACCUM_EPSILON__   0x1P-32ULLK
#   define ULLACCUM_EPSILON   __ULLACCUM_EPSILON__
#endif
#endif  // SUPPORTS_STDFIX
#ifdef __DA_FBIT__
#   define DA_FBIT   __DA_FBIT__
#else
#   define __DA_FBIT__   31
#   define DA_FBIT   __DA_FBIT__
#endif
#ifdef __DA_IBIT__
#   define DA_IBIT   __DA_IBIT__
#else
#   define __DA_IBIT__   32
#   define DA_IBIT   __DA_IBIT__
#endif
#ifdef __DQ_FBIT__
#   define DQ_FBIT   __DQ_FBIT__
#else
#   define __DQ_FBIT__   63
#   define DQ_FBIT   __DQ_FBIT__
#endif
#ifdef __DQ_IBIT__
#   define DQ_IBIT   __DQ_IBIT__
#else
#   define __DQ_IBIT__   0
#   define DQ_IBIT   __DQ_IBIT__
#endif
#ifdef __HA_FBIT__
#   define HA_FBIT   __HA_FBIT__
#else
#   define __HA_FBIT__   7
#   define HA_FBIT   __HA_FBIT__
#endif
#ifdef __HA_IBIT__
#   define HA_IBIT   __HA_IBIT__
#else
#   define __HA_IBIT__   8
#   define HA_IBIT   __HA_IBIT__
#endif
#ifdef __HQ_FBIT__
#   define HQ_FBIT   __HQ_FBIT__
#else
#   define __HQ_FBIT__   15
#   define HQ_FBIT   __HQ_FBIT__
#endif
#ifdef __HQ_IBIT__
#   define HQ_IBIT   __HQ_IBIT__
#else
#   define __HQ_IBIT__   0
#   define HQ_IBIT   __HQ_IBIT__
#endif
#ifdef __QQ_FBIT__
#   define QQ_FBIT   __QQ_FBIT__
#else
#   define __QQ_FBIT__   7
#   define QQ_FBIT   __QQ_FBIT__
#endif
#ifdef __QQ_IBIT__
#   define QQ_IBIT   __QQ_IBIT__
#else
#   define __QQ_IBIT__   0
#   define QQ_IBIT   __QQ_IBIT__
#endif
#ifdef __SA_FBIT__
#   define SA_FBIT   __SA_FBIT__
#else
#   define __SA_FBIT__   15
#   define SA_FBIT   __SA_FBIT__
#endif
#ifdef __SA_IBIT__
#   define SA_IBIT   __SA_IBIT__
#else
#   define __SA_IBIT__   16
#   define SA_IBIT   __SA_IBIT__
#endif
#ifdef __SQ_FBIT__
#   define SQ_FBIT   __SQ_FBIT__
#else
#   define __SQ_FBIT__   31
#   define SQ_FBIT   __SQ_FBIT__
#endif
#ifdef __SQ_IBIT__
#   define SQ_IBIT   __SQ_IBIT__
#else
#   define __SQ_IBIT__   0
#   define SQ_IBIT   __SQ_IBIT__
#endif
#ifdef __TA_FBIT__
#   define TA_FBIT   __TA_FBIT__
#else
#   define __TA_FBIT__   63
#   define TA_FBIT   __TA_FBIT__
#endif
#ifdef __TA_IBIT__
#   define TA_IBIT   __TA_IBIT__
#else
#   define __TA_IBIT__   64
#   define TA_IBIT   __TA_IBIT__
#endif
#ifdef __TQ_FBIT__
#   define TQ_FBIT   __TQ_FBIT__
#else
#   define __TQ_FBIT__   127
#   define TQ_FBIT   __TQ_FBIT__
#endif
#ifdef __TQ_IBIT__
#   define TQ_IBIT   __TQ_IBIT__
#else
#   define __TQ_IBIT__   0
#   define TQ_IBIT   __TQ_IBIT__
#endif
#ifdef __UDA_FBIT__
#   define UDA_FBIT   __UDA_FBIT__
#else
#   define __UDA_FBIT__   32
#   define UDA_FBIT   __UDA_FBIT__
#endif
#ifdef __UDA_IBIT__
#   define UDA_IBIT   __UDA_IBIT__
#else
#   define __UDA_IBIT__   32
#   define UDA_IBIT   __UDA_IBIT__
#endif
#ifdef __UDQ_FBIT__
#   define UDQ_FBIT   __UDQ_FBIT__
#else
#   define __UDQ_FBIT__   64
#   define UDQ_FBIT   __UDQ_FBIT__
#endif
#ifdef __UDQ_IBIT__
#   define UDQ_IBIT   __UDQ_IBIT__
#else
#   define __UDQ_IBIT__   0
#   define UDQ_IBIT   __UDQ_IBIT__
#endif
#ifdef __UHA_FBIT__
#   define UHA_FBIT   __UHA_FBIT__
#else
#   define __UHA_FBIT__   8
#   define UHA_FBIT   __UHA_FBIT__
#endif
#ifdef __UHA_IBIT__
#   define UHA_IBIT   __UHA_IBIT__
#else
#   define __UHA_IBIT__   8
#   define UHA_IBIT   __UHA_IBIT__
#endif
#ifdef __UHQ_FBIT__
#   define UHQ_FBIT   __UHQ_FBIT__
#else
#   define __UHQ_FBIT__   16
#   define UHQ_FBIT   __UHQ_FBIT__
#endif
#ifdef __UHQ_IBIT__
#   define UHQ_IBIT   __UHQ_IBIT__
#else
#   define __UHQ_IBIT__   0
#   define UHQ_IBIT   __UHQ_IBIT__
#endif
#ifdef __UQQ_FBIT__
#   define UQQ_FBIT   __UQQ_FBIT__
#else
#   define __UQQ_FBIT__   8
#   define UQQ_FBIT   __UQQ_FBIT__
#endif
#ifdef __UQQ_IBIT__
#   define UQQ_IBIT   __UQQ_IBIT__
#else
#   define __UQQ_IBIT__   0
#   define UQQ_IBIT   __UQQ_IBIT__
#endif
#ifdef __USA_FBIT__
#   define USA_FBIT   __USA_FBIT__
#else
#   define __USA_FBIT__   16
#   define USA_FBIT   __USA_FBIT__
#endif
#ifdef __USA_IBIT__
#   define USA_IBIT   __USA_IBIT__
#else
#   define __USA_IBIT__   16
#   define USA_IBIT   __USA_IBIT__
#endif
#ifdef __USQ_FBIT__
#   define USQ_FBIT   __USQ_FBIT__
#else
#   define __USQ_FBIT__   32
#   define USQ_FBIT   __USQ_FBIT__
#endif
#ifdef __USQ_IBIT__
#   define USQ_IBIT   __USQ_IBIT__
#else
#   define __USQ_IBIT__   0
#   define USQ_IBIT   __USQ_IBIT__
#endif
#ifdef __UTA_FBIT__
#   define UTA_FBIT   __UTA_FBIT__
#else
#   define __UTA_FBIT__   64
#   define UTA_FBIT   __UTA_FBIT__
#endif
#ifdef __UTA_IBIT__
#   define UTA_IBIT   __UTA_IBIT__
#else
#   define __UTA_IBIT__   64
#   define UTA_IBIT   __UTA_IBIT__
#endif
#ifdef __UTQ_FBIT__
#   define UTQ_FBIT   __UTQ_FBIT__
#else
#   define __UTQ_FBIT__   128
#   define UTQ_FBIT   __UTQ_FBIT__
#endif
#ifdef __UTQ_IBIT__
#   define UTQ_IBIT   __UTQ_IBIT__
#else
#   define __UTQ_IBIT__   0
#   define UTQ_IBIT   __UTQ_IBIT__
#endif


// WINDOWS LIMITS

/** Max path length in Windows */
#define MAX_PATH   (260)
#define WORD_MAX   ((unsigned short)0xffff)
#define DWORD_MAX   (0xffffffffUL)
#define DWORDLONG_MAX   (0xffffffffffffffffULL)
#define ULONG64_MAX   (0xffffffffffffffffULL)
#define DWORD64_MAX   (0xffffffffffffffffULL)


// HAIKU LIMITS

#ifdef ENV64BIT
#   define HAIKU_SADDR_MAX   (9223372036854775807LL)
#   define HAIKU_ADDR_MAX   (18446744073709551615ULL)
#   define HAIKU_PHYS_SADDR_MAX   (9223372036854775807LL)
#   define HAIKU_PHYS_ADDR_MAX   (18446744073709551615ULL)
#else
#   define HAIKU_SADDR_MAX   (2147483647)
#   define HAIKU_ADDR_MAX   (4294967295U)
#   define HAIKU_PHYS_SADDR_MAX   (2147483647)
#   define HAIKU_PHYS_ADDR_MAX   (4294967295U)
#endif
#define __HAIKU_SADDR_MAX   HAIKU_SADDR_MAX
#define __HAIKU_ADDR_MAX   HAIKU_ADDR_MAX
#define __HAIKU_PHYS_SADDR_MAX   HAIKU_PHYS_SADDR_MAX
#define __HAIKU_PHYS_ADDR_MAX   HAIKU_PHYS_ADDR_MAX
#define HAIKU_SADDR_MIN   ((-HAIKU_SADDR_MAX) - 1)
#define __HAIKU_SADDR_MIN   HAIKU_SADDR_MIN
#define HAIKU_PHYS_SADDR_MIN   ((-HAIKU_SADDR_MAX) - 1)
#define __HAIKU_PHYS_SADDR_MIN   HAIKU_PHYS_SADDR_MIN
#if (defined(HAIKU_ARCH_BITS) && defined(__HAIKU_ARCH_PHYSICAL_BITS) && (HAIKU_ARCH_BITS >= __HAIKU_ARCH_PHYSICAL_BITS))
typedef haiku_addr_t   haiku_generic_addr_t;
#   define HAIKU_GENERIC_ADDR_MAX   __HAIKU_ADDR_MAX
#   define HAIKU_PRI_PREFIX_GENERIC_ADDR   __HAIKU_PRI_PREFIX_ADDR
#else
typedef haiku_phys_addr_t   haiku_generic_addr_t;
#   define HAIKU_GENERIC_ADDR_MAX   __HAIKU_PHYS_ADDR_MAX
#   define HAIKU_PRI_PREFIX_GENERIC_ADDR   __HAIKU_PRI_PREFIX_PHYS_ADDR
#endif
#define __haiku_generic_addr_t   haiku_generic_addr_t
#define generic_addr_t   haiku_generic_addr_t
#define __generic_addr_t   haiku_generic_addr_t
#define __HAIKU_GENERIC_ADDR_MAX   HAIKU_GENERIC_ADDR_MAX
#define __HAIKU_PRI_PREFIX_GENERIC_ADDR   HAIKU_PRI_PREFIX_GENERIC_ADDR
#ifdef ENV64BIT
#   define FSSH_SIZE_MAX   UINT64_MAX
#   define FSSH_SSIZE_MAX   INT64_MAX
#else
#   define FSSH_SIZE_MAX   UINT32_MAX
#   define FSSH_SSIZE_MAX   INT32_MAX
#endif


// LIMIT ALIASES

#define LONGLONG_MIN   LLONG_MIN
#define LONGLONG_MAX   LLONG_MAX
#define ULONGLONG_MAX   ULLONG_MAX
#define MINSHORT   SHRT_MIN
#define MININT   INT_MIN
#define MINLONG   LONG_MIN
#define MAXSHORT   SHRT_MAX
#define MAXINT   INT_MAX
#define MAXLONG   LONG_MAX
#define HIBITS   MINSHORT
#define HIBITL   MINLONG
#define INT8_T_MAX   INT8_MAX
#define UINT8_T_MAX   UINT8_MAX
#define INT8_T_MIN   INT8_MIN
#define UINT8_T_MIN   (0x0)
#define INT16_T_MAX   INT16_MAX
#define UINT16_T_MAX   UINT16_MAX
#define INT16_T_MIN   INT16_MIN
#define UINT16_T_MIN   (0x0)
#define INT32_T_MAX   INT32_MAX
#define UINT32_T_MAX   UINT32_MAX
#define INT32_T_MIN   INT32_MIN
#define UINT32_T_MIN   (0x0)
#define INT64_T_MAX   INT64_MAX
#define UINT64_T_MAX   UINT64_MAX
#define INT64_T_MIN   INT64_MIN
#define UINT64_T_MIN   (0x0)
#define _I64_MAX   INT64_MAX
#define _I64_MIN   INT64_MIN
#define _UI64_MAX   UINT64_MAX
#define I64_MIN   INT64_MIN
#define I64_MAX   INT64_MAX
#define UI64_MAX   UINT64_MAX
#define PR_INT8_MAX   INT8_MAX
#define PR_INT8_MIN   INT8_MIN
#define PR_UINT8_MAX   UINT8_MAX
#define PR_INT16_MAX   INT16_MAX
#define PR_INT16_MIN   INT16_MIN
#define PR_UINT16_MAX   UINT16_MAX
#define PR_INT32_MAX   INT32_MAX
#define PR_INT32_MIN   INT32_MIN
#define PR_UINT32_MAX   UINT32_MAX
#define PR_INT64_MAX   INT64_MAX
#define PR_INT64_MIN   INT64_MIN
#define PR_UINT64_MAX   UINT64_MAX


// DATATYPE SIZES

#define _TYPEBITS(datatype)   (sizeof(datatype) * CHAR_BIT)
#define TYPEBITS(datatype)   _TYPEBITS((datatype))
#if (INT_MAX <= 32767)
#   define __UIM_BUFLEN_INT   7  // 10 digits + 1 null + 1 sign
#elif (INT_MAX <= 2147483647L)
#   define __UIM_BUFLEN_INT   12  // 10 digits + 1 null + 1 sign
#else
#   error   "Unknown number of digits for int!"
#endif
#if (INTMAX_MAX <= 2147483647L)
#   define __UIM_BUFLEN   12  // 10 digits + 1 null + 1 sign
#elif (INTMAX_MAX <= 9223372036854775807LL)
#   define __UIM_BUFLEN   22  // 20 digits + 1 null + 1 sign
#else
#   error   "Unknown number of digits for intmax_t!"
#endif
#if (LONG_MAX <= 2147483647L)
#   define __UIM_BUFLEN_LONG   12  // 10 digits + 1 null + 1 sign
#elif (LONG_MAX <= 9223372036854775807LL)
#   define __UIM_BUFLEN_LONG   22  // 20 digits + 1 null + 1 sign
#else
#   error   "Unknown number of digits for long!"
#endif
#ifdef LLONG_MAX
#   if (LLONG_MAX <= 2147483647L)
#      define __UIM_BUFLEN_LLONG   12  // 10 digits + 1 null + 1 sign
#   elif (LLONG_MAX <= 9223372036854775807LL)
#      define __UIM_BUFLEN_LLONG   22  // 20 digits + 1 null + 1 sign
#   else
#      error   "Unknown number of digits for long long!"
#   endif
#endif
/** The size (in bytes) of zone_t */
#define ZONE_NUM_SIZE   (4)
/** The size (in bytes) of zone_t */
#define __SIZEOF_ZONE_T__   ZONE_NUM_SIZE
/** The size (in bytes) of zone_t */
#define __SIZEOF_ZONE__   ZONE_NUM_SIZE
/** The size (in bytes) of zone_t */
#define SIZEOF_ZONE   ZONE_NUM_SIZE
/** Number of bits in sig_atomic_t */
#define BITSIZEOF_SIG_ATOMIC_T   (SIZEOF_INT * 8)
#ifndef __SIG_ATOMIC_WIDTH__
/** Number of bits in sig_atomic_t */
#   define __SIG_ATOMIC_WIDTH__   BITSIZEOF_SIG_ATOMIC_T
#endif
#ifndef BITS_PER_SIG_ATOMIC
#   define BITS_PER_SIG_ATOMIC   BITSIZEOF_SIG_ATOMIC_T
#endif
#ifndef __INTMAX_WIDTH__
#   define __INTMAX_WIDTH__   64
#endif
#ifndef BITS_PER_INTMAX
#   define BITS_PER_INTMAX   __INTMAX_WIDTH__
#endif
#ifndef __INTPTR_WIDTH__
#   define __INTPTR_WIDTH__   64
#endif
#ifndef BITS_PER_INTPTR
#   define BITS_PER_INTPTR   __INTPTR_WIDTH__
#endif
#ifndef __UINTMAX_WIDTH__
#   define __UINTMAX_WIDTH__   64
#endif
#ifndef BITS_PER_UINTMAX
#   define BITS_PER_UINTMAX   __UINTMAX_WIDTH__
#endif
#ifndef __UINTPTR_WIDTH__
#   define __UINTPTR_WIDTH__   64
#endif
#ifndef BITS_PER_UINTPTR
#   define BITS_PER_UINTPTR   __UINTPTR_WIDTH__
#endif


// LINUX VALUES

#if (defined(ARM) || defined(ARM64) || defined(X86_64) || defined(X86) || defined(I386) || defined(SUPERH) || defined(POWERPC) || defined (POWERPC64) || defined(MIPS) || defined(MICROBLAZE) || defined(S390) || defined(HPPA) || defined(IA64))  // PAGE_SIZE
#   define PAGE_SIZE   4096
#   define PAGE_SHIFT   12
#elif (defined(OR1K) || defined(ALPHA) || defined(SPARC))
#   define PAGE_SIZE   8192
#   define PAGE_SHIFT   13
#else
#   define PAGE_SIZE   4096
#   define PAGE_SHIFT   12
#endif  // PAGE_SIZE
#ifdef PAGE_SIZE
#   define PAGESIZE   PAGE_SIZE
#endif
#ifdef PAGE_SHIFT
#   define PAGESHIFT   PAGE_SHIFT
#endif
#ifndef MAXPATHLEN
/** POSIX 1003.1 maximum path length; MAXPATHLEN defines the longest permissable path length after expanding symbolic links; It is used to allocate a temporary buffer from the buffer pool in which to do the name expansion, hence should be a power of two, and must be less than or equal to MAXBSIZE */
#   define MAXPATHLEN   (4096)
#endif
#ifndef PATH_MAX
/** Number of chars in a path name including nul */
#   define PATH_MAX   MAXPATHLEN
#endif
/** Maximum number of chars in a filename */
#define NAME_MAX   (255)
#define NR_OPEN   (1024)
#define NLIMITS   (6)
/** Maximum number of bytes of args + environ for exec() */
#define ARG_MAX   (131072)
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
#define MAX_CANON   (255)
/** Size of the type-ahead buffer */
#define MAX_INPUT   _POSIX_MAX_INPUT
/** Number of bytes in atomic write to a pipe */
#define PIPE_BUF   _POSIX_PIPE_BUF
/** Number of chars in an extended attribute name */
#define XATTR_NAME_MAX   (255)
/** Size of an extended attribute value (64k) */
#define XATTR_SIZE_MAX   (65536)
/** Size of extended attribute namelist (64k) */
#define XATTR_LIST_MAX   (65536)
#define RTSIG_MAX   (32)
#define FILESIZEBITS   (64)
#define WORD_BIT   (32)
#define TZNAME_MAX   _POSIX_TZNAME_MAX
#define TTY_NAME_MAX   _POSIX_TTY_NAME_MAX
#define HOST_NAME_MAX   _POSIX_HOST_NAME_MAX
#define PTHREAD_KEYS_MAX   (32)
#define PTHREAD_STACK_MIN   (2048)
#define PTHREAD_DESTRUCTOR_ITERATIONS   (1)
#define SEM_VALUE_MAX   (0x7fffffff)
#define SEM_NSEMS_MAX   (256)
#ifndef DELAYTIMER_MAX
#   define DELAYTIMER_MAX   (0x7fffffff)
#endif
#define MQ_PRIO_MAX   (32768)
#define LOGIN_NAME_MAX   _POSIX_LOGIN_NAME_MAX
#ifndef MAXDOMNAMELEN
/** Maximum domain name length */
#   define MAXDOMNAMELEN   (255)
#endif
#ifndef MAXHOSTNAMELEN
/** Max hostname size */
#   define MAXHOSTNAMELEN   (255)
#endif
#ifndef HOST_NAME_MAX
#   define HOST_NAME_MAX   MAXHOSTNAMELEN
#endif
#ifndef MAXNAMLEN
#   define MAXNAMLEN   (255)
#endif
#ifndef NGROUPS
/** Max number groups */
#   define NGROUPS   (32)
#endif
#ifndef NGROUPS_MAX
/** Max number groups */
#   define NGROUPS_MAX   (32)
#endif
#ifndef NOGROUP
/** Marker for empty group set member */
#   define NOGROUP   (65535)
#endif
#ifndef CANBSIZE
#   define CANBSIZE   (255)
#endif
#ifndef NOFILE
/** Default max open files per process */
#   define NOFILE   (256)
#endif
#ifndef DEV_BSIZE
/** Unit of `st_blocks`; All (or most) references to `DEV_BSIZE` are for NetBSD's file images */
#   define DEV_BSIZE   (512)
#endif
#ifndef NODEV
/** Non-existent device */
#   define NODEV   ((dev_t)-1)
#endif
/** Max command name remembered */
#define MAXCOMLEN   (16)
/** Max interpreter filename length */
#define MAXINTERP   (64)
/** Max simultaneous processes */
#define MAXUPRC   CHILD_MAX
/** ORed with pri for tsleep to check signals */
#define PCATCH   (0x100)
/** For tty SIGTTOU and SIGTTIN blocking */
#define PTTYBLOCK   (0x200)
/** ORed with pri to stop re-aquistion of mutex upon wakeup */
#define PDROP   (0x400)
/** ORed with pri to require mutex in spin mode upon wakeup */
#define PSPIN   (0x800)
/** Number of bytes per word (integer) */
#define NBPW   BYTES_PER_INT
/** Default file mask: S_IWGRP|S_IWOTH */
#define CMASK   (022)
#define MAXBSIZE   (1048576)
#define MAXPHYSIO   MAXPHYS
#define MAXFRAG   (8)
#define MAXPHYSIO_WIRED   (16777216)
/** MINBUCKET is the smallest unit of memory that will be allocated; It must be at least large enough to hold a pointer */
#define MINBUCKET   (4)
/** Units of memory less or equal to MAXALLOCSAVE will permanently allocate physical memory; requests for these size pieces of memory are quite fast; Allocations greater than MAXALLOCSAVE must always allocate and free physical memory; requests for these size allocations should be done infrequently as they will be slow */
#define MAXALLOCSAVE   (2 * CLBYTES)
#define FSHIFT   (11)
#define FSCALE   (0x800)  // (1 << FSHIFT)
#define LIM_NORAISE   (0)
/** Max secs cpu time */
#define LIM_CPU   (1)
/** Max size of file created */
#define LIM_FSIZE   (2)
/** Max growth of data space */
#define LIM_DATA   (3)
/** Max growth of stack */
#define LIM_STACK   (4)
/** Max size of `core` file */
#define LIM_CORE   (5)
/** Max desired data+stack core usage */
#define LIM_MAXRSS   (6)
// Priorities; Note that with 32 run queues, differences less than 4 are insignificant
#define PSWP   (0)
#define PVM   (4)
#define PINOD   (8)
#define PRIBIO   (16)
#define PVFS   (20)
#define PZERO   (22)
#define PSOCK   (24)
#define PWAIT   (32)
#define PLOCK   (36)
#define PPAUSE   (40)
#define PUSER   (50)
#define MAXPRI   (127)
#define PRIMASK   (0xff)


// MISCELLANEOUS LIMITS

#define FSSH_B_DEV_NAME_LENGTH   (128)
#define FSSH_B_FILE_NAME_LENGTH   (256)
#define FSSH_B_PATH_NAME_LENGTH   (1024)
#define FSSH_B_ATTR_NAME_LENGTH   (FSSH_B_FILE_NAME_LENGTH - 1)
#define FSSH_B_MIME_TYPE_LENGTH   (FSSH_B_ATTR_NAME_LENGTH - 15)
#define FSSH_B_MAX_SYMLINKS   (16)


// PRINTING & SCANNING FORMAT SPECIFIERS

/** Casts the uint64_t value in `x` to the right type for an argument to printf */
#define U64_PRINTF_ARG(x)   ((unsigned long long)(x))
#define I64_PRINTF_ARG(x)   ((signed long long)(x))
#if IS_WORDSIZE_64
#   define __PRI64_PREFIX   "l"
#   define __PRIPTR_PREFIX   "l"
#else
#   define __PRI64_PREFIX   "ll"
#   define __PRIPTR_PREFIX   "ll"
# endif
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
#define PRIoFAST16   __PRIPTR_PREFIX "o"
#define PRIoFAST32   __PRIPTR_PREFIX "o"
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
#define PRIdFAST16   __PRIPTR_PREFIX "d"
#define PRIdFAST32   __PRIPTR_PREFIX "d"
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
#define PRIxFAST16   __PRIPTR_PREFIX "x"
#define PRIxFAST32   __PRIPTR_PREFIX "x"
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
#define PRIXFAST16   __PRIPTR_PREFIX "X"
#define PRIXFAST32   __PRIPTR_PREFIX "X"
#define PRIXFAST64   __PRI64_PREFIX "X"
// Singed Integer
#define PRIi8   "i"
#define PRIi16   "i"
#define PRIi32   "i"
#define PRIi64   __PRI64_PREFIX "i"
#define PRIiLEAST8   "i"
#define PRIiLEAST16   "i"
#define PRIiLEAST32   "i"
#define PRIiLEAST64   __PRI64_PREFIX "i"
#define PRIiFAST8   "i"
#define PRIiFAST16   __PRIPTR_PREFIX "i"
#define PRIiFAST32   __PRIPTR_PREFIX "i"
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
#define PRIuFAST16   __PRIPTR_PREFIX "u"
#define PRIuFAST32   __PRIPTR_PREFIX "u"
#define PRIuFAST64   __PRI64_PREFIX "u"
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
// SCANNING FORMAT SPECIFIERS
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
#define SCNoFAST16   __PRIPTR_PREFIX "o"
#define SCNoFAST32   __PRIPTR_PREFIX "o"
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
#define SCNdFAST16   __PRIPTR_PREFIX "d"
#define SCNdFAST32   __PRIPTR_PREFIX "d"
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
#define SCNxFAST16   __PRIPTR_PREFIX "x"
#define SCNxFAST32   __PRIPTR_PREFIX "x"
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
#define SCNiFAST16   __PRIPTR_PREFIX "i"
#define SCNiFAST32   __PRIPTR_PREFIX "i"
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
#define SCNuFAST16   __PRIPTR_PREFIX "u"
#define SCNuFAST32   __PRIPTR_PREFIX "u"
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


// FSSH PRINTF()/SCANF() FORMAT STRINGS

#define FSSH_B_PRId8   PRId8
#define FSSH_B_PRIi8   PRIi8
#define FSSH_B_PRId16   PRId16
#define FSSH_B_PRIi16   PRIi16
#define FSSH_B_PRId32   PRId32
#define FSSH_B_PRIi32   PRIi32
#define FSSH_B_PRId64   PRId64
#define FSSH_B_PRIi64   PRIi64
#define FSSH_B_PRIu8   PRIu8
#define FSSH_B_PRIo8   PRIo8
#define FSSH_B_PRIx8   PRIx8
#define FSSH_B_PRIX8   PRIX8
#define FSSH_B_PRIu16   PRIu16
#define FSSH_B_PRIo16   PRIo16
#define FSSH_B_PRIx16   PRIx16
#define FSSH_B_PRIX16   PRIX16
#define FSSH_B_PRIu32   PRIu32
#define FSSH_B_PRIo32   PRIo32
#define FSSH_B_PRIx32   PRIx32
#define FSSH_B_PRIX32   PRIX32
#define FSSH_B_PRIu64   PRIu64
#define FSSH_B_PRIo64   PRIo64
#define FSSH_B_PRIx64   PRIx64
#define FSSH_B_PRIX64   PRIX64
#define FSSH_B_SCNd8    SCNd8
#define FSSH_B_SCNi8    SCNi8
#define FSSH_B_SCNd16   SCNd16
#define FSSH_B_SCNi16    SCNi16
#define FSSH_B_SCNd32    SCNd32
#define FSSH_B_SCNi32    SCNi32
#define FSSH_B_SCNd64   SCNd64
#define FSSH_B_SCNi64    SCNi64
#define FSSH_B_SCNu8    SCNu8
#define FSSH_B_SCNo8    SCNo8
#define FSSH_B_SCNx8    SCNx8
#define FSSH_B_SCNu16   SCNu16
#define FSSH_B_SCNu16   SCNu16
#define FSSH_B_SCNx16   SCNx16
#define FSSH_B_SCNu32    SCNu32
#define FSSH_B_SCNo32    SCNo32
#define FSSH_B_SCNx32    SCNx32
#define FSSH_B_SCNu64   SCNu64
#define FSSH_B_SCNo64   SCNo64
#define FSSH_B_SCNx64   SCNx64
#ifdef ENV64BIT
#   define FSSH_B_PRIuADDR   FSSH_B_PRIu64
#   define FSSH_B_PRIoADDR   FSSH_B_PRIo64
#   define FSSH_B_PRIxADDR   FSSH_B_PRIx64
#   define FSSH_B_PRIXADDR   FSSH_B_PRIX64
#   define FSSH_B_PRIuSIZE   FSSH_B_PRIu64
#   define FSSH_B_PRIoSIZE   FSSH_B_PRIo64
#   define FSSH_B_PRIxSIZE   FSSH_B_PRIx64
#   define FSSH_B_PRIXSIZE   FSSH_B_PRIX64
#   define FSSH_B_PRIdSSIZE   FSSH_B_PRId64
#   define FSSH_B_PRIiSSIZE   FSSH_B_PRIi64
#   define FSSH_B_PRIuPHYSADDR   FSSH_B_PRIu64
#   define FSSH_B_PRIoPHYSADDR   FSSH_B_PRIo64
#   define FSSH_B_PRIxPHYSADDR   FSSH_B_PRIx64
#   define FSSH_B_PRIXPHYSADDR   FSSH_B_PRIX64
#else
#   define FSSH_B_PRIuADDR   FSSH_B_PRIu32
#   define FSSH_B_PRIoADDR   FSSH_B_PRIo32
#   define FSSH_B_PRIxADDR   FSSH_B_PRIx32
#   define FSSH_B_PRIXADDR   FSSH_B_PRIX32
#   define FSSH_B_PRIuSIZE   FSSH_B_PRIu32
#   define FSSH_B_PRIoSIZE   FSSH_B_PRIo32
#   define FSSH_B_PRIxSIZE   FSSH_B_PRIx32
#   define FSSH_B_PRIXSIZE   FSSH_B_PRIX32
#   define FSSH_B_PRIdSSIZE   FSSH_B_PRId32
#   define FSSH_B_PRIiSSIZE   FSSH_B_PRIi32
#   define FSSH_B_PRIuPHYSADDR   FSSH_B_PRIu32
#   define FSSH_B_PRIoPHYSADDR   FSSH_B_PRIo32
#   define FSSH_B_PRIxPHYSADDR   FSSH_B_PRIx32
#   define FSSH_B_PRIXPHYSADDR   FSSH_B_PRIX32
#endif
#define FSSH_B_PRIuGENADDR   FSSH_B_PRIuPHYSADDR
#define FSSH_B_PRIoGENADDR   FSSH_B_PRIoPHYSADDR
#define FSSH_B_PRIxGENADDR   FSSH_B_PRIxPHYSADDR
#define FSSH_B_PRIXGENADDR   FSSH_B_PRIXPHYSADDR
#define FSSH_B_PRIdOFF   FSSH_B_PRId64
#define FSSH_B_PRIiOFF   FSSH_B_PRIi64
#define FSSH_B_PRIdDEV   FSSH_B_PRId32
#define FSSH_B_PRIiDEV   FSSH_B_PRIi32
#define FSSH_B_PRIdINO   FSSH_B_PRId64
#define FSSH_B_PRIiINO   FSSH_B_PRIi64
#define FSSH_B_PRIdTIME   FSSH_B_PRId32
#define FSSH_B_PRIiTIME   FSSH_B_PRIi32


// HAIKU PRINTF & SCANF MACROS

#define HAIKU_STD_PRI_PREFIX_32   ""
#define __HAIKU_STD_PRI_PREFIX_32   ""
#ifdef ENV64BIT
#   define HAIKU_STD_PRI_PREFIX_64   "l"
#   define __HAIKU_STD_PRI_PREFIX_64   "l"
#else
#   define HAIKU_STD_PRI_PREFIX_64   "ll"
#   define __HAIKU_STD_PRI_PREFIX_64   "ll"
#endif
#ifdef __HAIKU_BEOS_COMPATIBLE_TYPES
#   define HAIKU_PRI_PREFIX_32   "l"
#   define __HAIKU_PRI_PREFIX_32   "l"
#else
#   define HAIKU_PRI_PREFIX_32   HAIKU_STD_PRI_PREFIX_32
#   define __HAIKU_PRI_PREFIX_32   __HAIKU_STD_PRI_PREFIX_32
#endif
#define HAIKU_PRI_PREFIX_64   __HAIKU_STD_PRI_PREFIX_64
#define __HAIKU_PRI_PREFIX_64   __HAIKU_STD_PRI_PREFIX_64
#define HAIKU_PRI_PREFIX_ADDR   "l"
#define __HAIKU_PRI_PREFIX_ADDR   "l"
#ifdef ENV64BIT
#   define HAIKU_PRI_PREFIX_PHYS_ADDR   __HAIKU_PRI_PREFIX_64
#   define __HAIKU_PRI_PREFIX_PHYS_ADDR   __HAIKU_PRI_PREFIX_64
#else
#   define HAIKU_PRI_PREFIX_PHYS_ADDR   __HAIKU_PRI_PREFIX_32
#   define __HAIKU_PRI_PREFIX_PHYS_ADDR   __HAIKU_PRI_PREFIX_32
#endif


// MICROSOFT PRINTF & SCANF MACROS

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
#if (defined(COMPILER_MICROSOFT) || defined(MINGW))
/** The formatting string used to put a uint64_t value in a printf() or scanf() function */
#   define U64_FORMAT   "%I64u"
/** The formatting string used to put a int64_t value in a printf() or scanf() function */
#   define I64_FORMAT   "%I64d"
/** Casts the uint64_t value in `x` to the right type for an argument to printf */
#   define U64_PRINTF_ARG(x)   ((ullint)(x))
/** Casts the `uint64_t *` value in `x` to the right type for an argument to scanf */
#   define U64_SCANF_ARG(x)   (x)
/** Expands to a literal uint64_t-typed constant for the value `n` */
#   define U64_LITERAL(n)   (n ## ui64)
#   define I64_SCANF_ARG(x)   (x)
#   define I64_LITERAL(n)   (n ## i64)
#else
/** The formatting string used to put a uint64_t value in a printf() or scanf() function */
#   define U64_FORMAT   "%llu"
/** The formatting string used to put a int64_t value in a printf() or scanf() function */
#   define I64_FORMAT   "%lld"
/** Casts the `uint64_t *` value in `x` to the right type for an argument to scanf */
#   define U64_SCANF_ARG(x)   ((ullint*)(x))
/** Expands to a literal uint64_t-typed constant for the value `n` */
#   define U64_LITERAL(n)   (n ## llu)
#   define I64_SCANF_ARG(x)   ((sllint*)(x))
#   define I64_LITERAL(n)   (n ## ll)
#endif  // MS printf and scanf


// PLAN9 PRINTF & SCANF MACROS

#ifdef OSPLAN9
#   pragma varargck type "lld" vlong
#   pragma varargck type "llo" vlong
#   pragma varargck type "llx" vlong
#   pragma varargck type "llb" vlong
#   pragma varargck type "lld" uvlong
#   pragma varargck type "llo" uvlong
#   pragma varargck type "llx" uvlong
#   pragma varargck type "llb" uvlong
#   pragma varargck type "ld" long
#   pragma varargck type "lo" long
#   pragma varargck type "lx" long
#   pragma varargck type "lb" long
#   pragma varargck type "ld" ulong
#   pragma varargck type "lo" ulong
#   pragma varargck type "lx" ulong
#   pragma varargck type "lb" ulong
#   pragma varargck type "d" int
#   pragma varargck type "o" int
#   pragma varargck type "x" int
#   pragma varargck type "c" int
#   pragma varargck type "C" int
#   pragma varargck type "b" int
#   pragma varargck type "d" uint
#   pragma varargck type "x" uint
#   pragma varargck type "c" uint
#   pragma varargck type "C" uint
#   pragma varargck type "b" uint
#   pragma varargck type "f" double
#   pragma varargck type "e" double
#   pragma varargck type "g" double
#   pragma varargck type "s" char*
#   pragma varargck type "q" char*
#   pragma varargck type "S" Rune*
#   pragma varargck type "Q" Rune*
#   pragma varargck type "r" void
#   pragma varargck type "%" void
#   pragma varargck type "n" int*
#   pragma varargck type "p" uintptr
#   pragma varargck type "p" void*
#   pragma varargck flag ','
#   pragma varargck flag ' '
#   pragma varargck flag 'h'
#   pragma varargck type "<" void*
#   pragma varargck type "[" void*
#   pragma varargck type "H" void*
#   pragma varargck type "lH" void*
#endif


// MISCELLANEOUS PRINTF & SCANF MACROS

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


// SIGNALLING & THREAD DATATYPES

typedef enum krw_t { RW_READER = 0, RW_WRITER = 1 }   krw_t;
typedef struct krwlock { volatile uintptr_t rw_owner; }   krwlock;
typedef struct raw_spinlock { volatile unsigned int lock; }   raw_spinlock_t;
typedef struct raw_rwlock { volatile unsigned int lock; }   raw_rwlock_t;
typedef struct rwlock { raw_rwlock_t raw_lock; }   rwlock_t;
/** Data structure to describe a process schedulability */
typedef struct sched_param { int __sched_priority; }   sched_param_t;
/** Data structure to describe a process schedulability */
#define __sched_param   sched_param
#define __defined_schedparam   (1)
#ifdef __need_schedparam
#   undef __need_schedparam
#endif
/** Define the real names for the elements of `struct sched_param` */
#define sched_priority   __sched_priority
#ifdef IS_REENTRANT
extern UNUSED rwlock_t __sfp_lock;
#endif
#ifndef __DEFINED_mtx_t
/** Used for mutexes */
typedef struct mtx { union { int __i[10]; volatile int __vi[10]; volatile void* volatile __p[5]; } __u; }   mtx_t;
#   define __DEFINED_mtx_t   (1)
#endif
#ifndef __DEFINED_sigset_t
typedef struct __sigset_t { unsigned long __bits[128 / SIZEOF_LONG]; }   sigset_t;
#   define OBJ_PER_SIGSET   (128 / SIZEOF_LONG)
#   define __DEFINED_sigset_t   (1)
#   define __sigset_t_defined   (1)
#endif
#ifdef __SIG_ATOMIC_TYPE__
/** An integer type which can be accessed as an atomic entity even in the presence of asynchronous interrupts made by signals */
typedef __SIG_ATOMIC_TYPE__   sig_atomic_t;
#else
/** An integer type which can be accessed as an atomic entity even in the presence of asynchronous interrupts made by signals */
typedef int   sig_atomic_t;
/** An integer type which can be accessed as an atomic entity even in the presence of asynchronous interrupts made by signals */
#   define __SIG_ATOMIC_TYPE__   sig_atomic_t
#endif
/** An integer type which can be accessed as an atomic entity even in the presence of asynchronous interrupts made by signals */
#define __sig_atomic_t   sig_atomic_t
#define __sig_atomic_t_defined   (1)
#define __have_sig_atomic_t   (1)
#define __DEFINED_sig_atomic_t   (1)
/** Type for data associated with a signal */
typedef union sigval { int sival_int; void* sival_ptr; }   sigval_t;
#define __sigval_t_defined   (1)
#define __have_sigval_t   (1)
#define __DEFINED_sigval_t   (1)
typedef struct siginfo {
	int si_signo;  // Signal number
	int si_code;  // Cause of the signal
	uid_t si_uid;
	pid_t si_pid;
	union sigval si_value;  // Signal value
} siginfo_t;
typedef struct attr_packed sigevent {
	sigval_t sigev_value;
	int32_t sigev_signo, sigev_notify;
	union attr_packed _sigev_un {
		int32_t _pad[SIGEV_PAD_SIZE];
		int32_t _tid;
		struct _sigev_thread {
			void(*_function)(sigval_t);
			void* _attribute;
		} _sigev_thread;
	} _sigev_un;
} sigevent_t;
typedef struct sigev_thread {
	void(*_function)(sigval_t);
	void* _attribute;
} sigev_thread_t;
#define sigev_notify_function   _sigev_un._sigev_thread._function
#define sigev_notify_attributes   _sigev_un._sigev_thread._attribute
#define sigev_notify_thread_id  _sigev_un._tid
#ifdef ARCHSPARC64
typedef int32_t   band_t;
#else
typedef long   band_t;
#endif
#define __band_t   band_t
// JUMP DATATYPES
#ifdef ARCHALPHA
typedef long int   __jmp_buf[17];
#elif defined(ARCHARC)
typedef int   __jmp_buf[16];  // r13-r25, fp, sp, blink
#elif defined(ARCHARM)
#   ifdef __ARM_EABI__
typedef int align8   __jmp_buf[64];
#   elif (defined(__MAVERICK__) || defined(__IWMMXT__))
typedef int   __jmp_buf[34];
#   else
#      ifdef IS_HARD_FP
typedef int   __jmp_buf[22];
#      else
typedef int   __jmp_buf[10];
#      endif
#   endif
#elif defined(ARCHAVR)
typedef int   __jmp_buf[11];  // r0-r7, sr, sp and lr
#elif defined(ARCHBLACKFIN)
typedef struct jmp_buf {
	unsigned long __pregs[6];
	unsigned long fp, sp;
	unsigned long __rregs[8];
	unsigned long astat;
	unsigned long __lcregs[2];
	unsigned long a0w, a0x, a1w, a1x;
	unsigned long __iregs[4];
	unsigned long __mregs[4];
	unsigned long __lregs[4];
	unsigned long __bregs[4];
	unsigned long pc;
} __jmp_buf[1];
#elif defined(ARCHCRIS)
typedef int   __jmp_buf[18];
#elif defined(ARCHHPPA)
typedef double   __jmp_buf[21];
#elif (defined(ARCHI386) || defined(ARCHX86_64) || defined(ARCHX86))
#   if IS_WORDSIZE_64
typedef long int   __jmp_buf[8];
#   else
typedef int   __jmp_buf[6];
#   endif
#elif defined(ARCHITANIUM)
typedef long align16   __jmp_buf[70];
#elif defined(ARCHM68K)
typedef struct jmp_buf {
	long int __dregs[7];
	int* __aregs[6];
	int* __fp;
	int* __sp;
#   if (defined(__HAVE_68881__) || IS_HARD_FP)
	char __fpregs[96];
#   endif
} __jmp_buf[1];
#elif defined(ARCHMICROBLAZE)
typedef struct jmp_buf {
	void *__sp, *__lp, *__SDA, *__SDA2;
	int __regs[14];
} __jmp_buf[1];
#elif defined(ARCHMIPS)
typedef struct jmp_buf {
	void *__pc, *__sp;
#   if (_MIPS_SIM == _MIPS_SIM_ABI32)
	int __regs[8];
#   else
	long long __regs[8];
#   endif
	void *__fp, *__gp;
	int __fpc_csr;
#   if (_MIPS_SIM == _MIPS_SIM_ABI64)
	double __fpregs[8];
#   else
	double __fpregs[6];
#   endif
} __jmp_buf[1];
#elif defined(ARCHPOWERPC)
#   if IS_WORDSIZE_64
typedef long int align16   __jmp_buf[64];
#   else
typedef long int align16   __jmp_buf[112];
#   endif
#elif defined(ARCHSUPERH)
typedef struct jmp_buf {
	int __regs[8];
	void * __pc, * __gbr;
	int __fpscr;
	int __fpregs[4];
} __jmp_buf[1];
#elif defined(ARCHSPARC)
typedef int   __jmp_buf[3];
#elif defined(ARCHXTENSA)
#   ifdef __XTENSA_WINDOWED_ABI__
typedef int   __jmp_buf[17];
#   elif defined(__XTENSA_CALL0_ABI__)
typedef int __jmp_buf[6];
#   else
#      error   "Unsupported Xtensa ABI!"
#   endif
#else
#   error   "Unsupported target platform (__jmp_buf)!"
#endif
/** Calling environment, plus possibly a saved signal mask */
struct attr_packed __jmp_buf_tag {
	__jmp_buf __jmpbuf;  // Calling environment
	int __mask_was_saved;  // Saved the signal mask
	sigset_t __saved_mask;  // Saved signal mask
};
typedef struct __jmp_buf_tag   jmp_buf[1];
#define __novmx__jmp_buf_tag   struct __jmp_buf_tag
#define __v1__jmp_buf_tag   struct __jmp_buf_tag
#define __novmx__jmp_buf   jmp_buf
#define __jmp_buf   jmp_buf
/** The `__mask_was_saved` flag determines whether or not `longjmp` will restore the signal mask */
#define sigjmp_buf   jmp_buf
#define __v1__jmp_buf   jmp_buf
typedef jmp_buf   osjmpbuf;
/** jmp_buf is in a structure so that we can declare pointers to jump locations; The global variable `handler` contains the location to jump to when an exception occurs; and the global variable `exception` contains a code identifying the exeception */
typedef struct jmploc { jmp_buf loc; }   jmploc_t;
extern struct jmploc* handler;
// POSIX THREAD (PTHREAD) DATATYPES
enum PTHREAD_MUTEXES { PTHREAD_MUTEX_FAST_NP, PTHREAD_MUTEX_RECURSIVE_NP, PTHREAD_MUTEX_ERRORCHECK_NP };
enum PTHREAD_PROCESS_SHARING { PTHREAD_PROCESS_PRIVATE, PTHREAD_PROCESS_SHARED };
#ifndef __DEFINED_pthread_t
/** Thread identifier datatype */
typedef unsigned long   pthread_t;
#   define __DEFINED_pthread_t   (1)
#endif
typedef pthread_t   bc_thread_t;
typedef pthread_t   bc_threadid_t;
#define __DEFINED_pthread_attr_t   (1)
#define __have_pthread_attr_t   (1)
/** Thread attribute datatype */
typedef union pthread_attr { char __size[__SIZEOF_PTHREAD_ATTR_T]; long __align; }   pthread_attr_t;
typedef struct __pthread_internal_list {
	struct __pthread_internal_list *__prev, *__next;
} __pthread_list_t;
typedef struct __pthread_internal_slist { struct __pthread_internal_slist* __next; }   __pthread_slist_t;
#define __DEFINED_pthread_once_t   (1)
#ifdef M68K  // pthread_once_t
/** Once-only execution; Used for dynamic package initialization */
typedef int align4   pthread_once_t;
#else
/** Once-only execution; Used for dynamic package initialization */
typedef int   pthread_once_t;
#endif
#define __DEFINED_pthread_key_t   (1)
/** Key datatype for thread-specific data */
typedef unsigned int   pthread_key_t;
#define __DEFINED_pthread_spinlock_t   (1)
typedef unsigned int   tss_t;
#define TSS_T   tss_t
#define _PDCLIB_TSS_T   tss_t
#define TSS_DTOR_ITERATIONS   5
/** POSIX spinlock datatype */
typedef volatile int32_t   pthread_spinlock_t;
/** The default value for an OSSpinLock */
#define OS_SPINLOCK_INIT   (0)
/** Datatype for a spinlock */
typedef volatile int32_t   OSSpinLock;
#define __DEFINED_pthread_barrier_t   (1)
/** POSIX barrier datatype */
typedef union pthread_barrier {
	char __size[__SIZEOF_PTHREAD_BARRIER_T];
	long __align;
} pthread_barrier_t;
#define __DEFINED_pthread_barrierattr_t   (1)
/** POSIX barrier attribute datatype */
typedef union pthread_barrierattr {
	char __size[__SIZEOF_PTHREAD_BARRIERATTR_T];
	int __align;
} pthread_barrierattr_t;
/** Data structure to contain the action information */
struct __spawn_action {
	enum { spawn_do_close, spawn_do_dup2, spawn_do_open } tag;
	union {
		struct { int fd; } close_action;
		struct { int fd, newfd; } dup2_action;
		struct attr_packed {
			int fd;
			char* path;
			int oflag;
			mode_t mode;
		} open_action;
	} action;
};
/** Data structure to contain attributes for thread creation */
typedef struct attr_packed posix_spawnattr {
	short __flags;
	pid_t __pgrp;
	sigset_t __sd, __ss;
	struct sched_param __sp;
	int __policy;
	int __pad[16];
} posix_spawnattr_t;
/** Data structure to contain information about the actions to be performed in the new process with respect to file descriptors */
typedef struct posix_spawn_file_actions {
	int _allocated, _used;
	struct __spawn_action *_actions;
	int _pad[16];
} posix_spawn_file_actions_t;
struct thread_cleanup_t {
	struct thread_cleanup_t* next;
	void (*func)(void*);
	void* arg;
};
#ifdef ARCHHPPA
struct align16 _pthread_fastlock { int __spinlock; };
#   define PTHREAD_SPIN_LOCKED   0
#   define PTHREAD_SPIN_UNLOCKED   1
#else
struct _pthread_fastlock { int __spinlock; };
#   define PTHREAD_SPIN_LOCKED   1
#   define PTHREAD_SPIN_UNLOCKED   0
#endif
/** Thread descriptor */
struct attr_packed _pthread_descr_struct {
	struct _pthread_descr_struct* next;
	struct _pthread_descr_struct** prev;
	pid_t pid;
	// Stack handling
	void* stack_begin;  // Beginning of stack; lowest address
	void* stack_end;  // End of stack
	// Thread struct lock
	struct _pthread_fastlock lock, wlock;
	int errno;
	// Thread exit handling
	sigjmp_buf jmp_exit;
	void* retval;
	// Joined threads
	struct _pthread_descr_struct* jt;
	struct _pthread_fastlock joined;
	// Conditional variables
	struct _pthread_descr_struct* waitnext;
	struct _pthread_descr_struct** waitprev;
	// Cancel handling
	unsigned char cancelstate;
	volatile unsigned char canceltype;
	// Thread flags
	volatile char dead;
	volatile char canceled;
	char detached, stack_free, p_sig;
	// Creation parameter
	void*(*func)(void* arg);
	void* arg;
	unsigned long stack_size, guard_size;
	// Cleanup stack (modify only with struct lock held)
	struct thread_cleanup_t* cleanup_stack;
	// Thread specific data
	void* tkd[PTHREAD_KEYS_MAX];
#ifdef PTHREAD_HANDLE_DNS_CORRECT
	int h_errno;
	struct res_state __res;
#endif
};
typedef struct _pthread_descr_struct*   _pthread_descr;
#define __DEFINED_pthread_mutex_t   (1)
#if (defined(ARM64))  // pthread_mutex_t
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct attr_packed __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
		unsigned int __nusers;
		int __kind, __spins;
		__pthread_list_t __list;
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#   define __PTHREAD_MUTEX_HAVE_PREV   1
#elif defined(ARM)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner
		int __kind;
		unsigned int __nusers;
		union {
			int __spins;
			__pthread_slist_t __list;
		};
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(ALPHA)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
		unsigned int __nusers;
		int __kind;
		int __spins;
		__pthread_list_t __list;
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#   define __PTHREAD_MUTEX_HAVE_PREV   1
#elif defined(ARC)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
#   if IS_WORDSIZE_64
		unsigned int __nusers;
#   endif
		int __kind;
#   if IS_WORDSIZE_64
		int __spins;
		__pthread_list_t __list;
#      define __PTHREAD_MUTEX_HAVE_PREV   (1)
#   else
		unsigned int __nusers;
		union {
			int __spins;
			__pthread_slist_t __list;
		};
#   endif
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(HPPA)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int align16 __lock;
		unsigned int __count;
		_pthread_descr __owner;
		int __kind;
		int __compat_padding[4];
		unsigned int __nusers;
		union {
			int __spins;
			__pthread_slist_t __list;
		};
		int __reserved1, __reserved2;
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(ITANIUM)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
		unsigned int __nusers;
		int __kind, __spins;
		__pthread_list_t __list;
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#   define __PTHREAD_MUTEX_HAVE_PREV   1
#elif defined(POWERPC)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
#   if IS_WORDSIZE_64
		unsigned int __nusers;
#   endif
		int __kind;
#   if IS_WORDSIZE_64
		short __spins, __elision;
		__pthread_list_t __list;
#      define __PTHREAD_MUTEX_HAVE_PREV   1
#      define __PTHREAD_SPINS   0, 0
#   else
		unsigned int __nusers;
		union {
			struct {
				short __espins;
				short __elision;
			} __elision_data;
			__pthread_slist_t __list;
		};
#      define __spins   __elision_data.__espins
#      define __elision   __elision_data.__elision
#      define __PTHREAD_SPINS   { 0, 0 }
#   endif
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(M68K)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int align4 __lock;
		unsigned int __count;
		_pthread_descr __owner;
		int __kind;
		unsigned int __nusers;
		union {
			int __spins;
			__pthread_slist_t __list;
		};
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(MICROBLAZE)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
		int __kind;
		unsigned int __nusers;
		union {
			int __spins;
			__pthread_slist_t __list;
		};
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(MIPS)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
#   if (_MIPS_SIM == _ABI64)
		unsigned int __nusers;
#   endif
		int __kind;
#   if (_MIPS_SIM == _ABI64)
		int __spins;
		__pthread_list_t __list;
#      define __PTHREAD_MUTEX_HAVE_PREV   1
#   else
		unsigned int __nusers;
		union {
			int __spins;
			__pthread_slist_t __list;
		};
#   endif
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(NIOS2)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
		int __kind;
		unsigned int __nusers;
		union {
			int __spins;
			__pthread_slist_t __list;
		};
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(S390)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
#   if IS_WORDSIZE_64
		unsigned int __nusers;
#   endif
		int __kind;
#   if IS_WORDSIZE_64
#      ifdef ENABLE_LOCK_ELISION
		short __spins, __elision;
#         define __PTHREAD_SPINS   0, 0
#      else
		int __spins;
#         define __PTHREAD_SPINS   0
#      endif
		__pthread_list_t __list;
#      define __PTHREAD_MUTEX_HAVE_PREV   1
#   else
		unsigned int __nusers;
		union {
#      ifdef ENABLE_LOCK_ELISION
			struct { short __espins, __elision; } _d;
#      define __spins   _d.__espins
#      define __elision   _d.__elision
#      define __PTHREAD_SPINS   { 0, 0 }
#   else
			int __spins;
#      define __PTHREAD_SPINS   0
#   endif
			__pthread_slist_t __list;
		};
#endif
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(SPARC)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
#   if IS_WORDSIZE_64
		unsigned int __nusers;
#   endif
		int __kind;
#   if IS_WORDSIZE_64
		int __spins;
		__pthread_list_t __list;
#      define __PTHREAD_MUTEX_HAVE_PREV   1
#   else
		unsigned int __nusers;
		union {
			int __spins;
			__pthread_slist_t __list;
		};
#   endif
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(SUPERH)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
		int __kind;
		unsigned int __nusers;
		union {
			int __spins;
			__pthread_slist_t __list;
		};
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(TILE)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
#   if IS_WORDSIZE_64
		unsigned int __nusers;
#   endif
		int __kind;
#   if IS_WORDSIZE_64
		int __spins;
		__pthread_list_t __list;
#      define __PTHREAD_MUTEX_HAVE_PREV   1
#   else
		unsigned int __nusers;
		union {
			int __spins;
			__pthread_slist_t __list;
		};
#   endif
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif (defined(X86_64) || defined(X86))
/** Data structures for mutex handling */
typedef union attr_packed pthread_mutex {
	struct attr_packed __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
		unsigned int __nusers;
		int __kind;
		int __spins;
		__pthread_list_t __list;
#   define __PTHREAD_MUTEX_HAVE_PREV   (1)
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif (defined(I386))
/** Data structures for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
		int __kind;
		unsigned int __nusers;
		union {
			int __spins;
			__pthread_slist_t __list;
		};
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(XTENSA)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
		int __kind;
		unsigned int __nusers;
		union {
			int __spins;
			__pthread_slist_t __list;
		};
	} __data;
	char __size[__SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#endif
typedef pthread_mutex_t   bc_mutex_t;
#define __DEFINED_pthread_mutexattr_t   (1)
#if ((defined(ARM64) || defined(ARM) || defined(HPPA) || defined(NIOS2) || defined(SUPERH)) && !defined(X86_64))
/** Mutex attribute datatype */
typedef union pthread_mutexattr {
	char __size[__SIZEOF_PTHREAD_MUTEXATTR_T];
	long __align;
} pthread_mutexattr_t;
#elif (defined(ALPHA) || defined(ARC) || defined(ITANIUM) || defined(S390) || defined(M68K) || defined(MICROBLAZE) || defined(MIPS) || defined(POWERPC) || defined(SPARC) || defined(TILE))
/** Mutex attribute datatype */
typedef union pthread_mutexattr {
	char __size[__SIZEOF_PTHREAD_MUTEXATTR_T];
	int __align;
} pthread_mutexattr_t;
#else
/** Mutex attribute datatype */
typedef union pthread_mutexattr {
	char __size[__SIZEOF_PTHREAD_MUTEXATTR_T];
	int __align;
} pthread_mutexattr_t;
#endif
#define __DEFINED_pthread_rwlock_t   (1)
#ifdef ARM64  // pthread_rwlock_t
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued,t __nr_writers_queued;
		int __writer, __shared;
		unsigned long __pad1, __pad2;
		unsigned int __flags;
	} __data;
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARM)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
#   if IS_BIG_ENDIAN
		unsigned char __pad1, __pad2, __shared, __flags;
#   else
		unsigned char __flags, __shared, __pad1, __pad2;
#   endif
	int __writer;
	} __data;
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif (defined(X86_64) || defined(X86))
/** Data structure for read-write lock variable handling */
typedef union attr_packed pthread_rwlock {
#   if IS_WORDSIZE_64
	struct attr_packed __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		int __writer, __shared;
		unsigned long __pad1, __pad2;
		unsigned int __flags;
	} __data;
#   else
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		unsigned char __flags, __shared, __pad1, __pad2;
		int __writer;
	} __data;
#   endif
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(I386)
/** Data structure for read-write lock variable handling */
typedef union attr_packed pthread_rwlock {
	struct attr_packed __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		unsigned char __flags, __shared, __pad1, __pad2;
		int __writer;
	} __data;
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ALPHA)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		int __writer, __shared;
		unsigned long __pad1, __pad2;
		unsigned int __flags;
	} __data;
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARC)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
#   if IS_WORDSIZE_64
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		int __writer, __shared;
		unsigned long __pad1, __pad2;
		unsigned int __flags;
	} __data;
#   else
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		unsigned char __pad1, __pad2, __shared, __flags;
		int __writer;
	} __data;
#   endif
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(HPPA)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int align16 __compat_padding[4];
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		int __writer, __reserved1;
		unsigned char __pad2, __pad1, __shared, __flags;
		int __reserved2, __reserved3, __reserved4;
	} __data;
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ITANIUM)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		int __writer, __shared;
		unsigned long __pad1, __pad2;
		unsigned int __flags;
	} __data;
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(M68K)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int align4 __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		unsigned char __pad1, __pad2, __shared, __flags;
		int __writer;
	} __data;
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(MICROBLAZE)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
#   if IS_BIG_ENDIAN
		unsigned char __pad1, __pad2, __shared, __flags;
#   else
		unsigned char __flags, __shared, __pad1, __pad2;
#   endif
		int __writer;
	} __data;
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(MIPS)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
#   if (_MIPS_SIM == _ABI64)
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		int __writer, __shared;
		unsigned long __pad1, __pad2;
		unsigned int __flags;
	} __data;
#   else
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
#   if IS_BIG_ENDIAN
		unsigned char __pad1, __pad2, __shared, __flags;
#   else
		unsigned char __flags, __shared, __pad1, __pad2;
#   endif
	int __writer;
	} __data;
#   endif
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(NIOS2)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
#   if IS_BIG_ENDIAN
		unsigned char __pad1, __pad2, __shared, __flags;
#   else
		unsigned char __flags, __shared, __pad1, __pad2;
#   endif
		int __writer;
	} __data;
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(POWERPC)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
#   if IS_WORDSIZE_64
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		int __writer, __shared;
		unsigned char __rwelision, __pad1[7];
		unsigned long __pad2;
		unsigned int __flags;
	} __data;
#      define __PTHREAD_RWLOCK_ELISION_EXTRA   0, {0, 0, 0, 0, 0, 0, 0 }
#   else
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		unsigned char __rwelision, __pad2, __shared, __flags;
		int __writer;
	} __data;
#      define __PTHREAD_RWLOCK_ELISION_EXTRA   0
#   endif
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(S390)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
#   if IS_WORDSIZE_64
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		int __writer, __shared;
		unsigned long __pad1, __pad2;
		unsigned int __flags;
	} __data;
#   else
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		unsigned char __pad1, __pad2, __shared, __flags;
		int __writer;
	} __data;
#   endif
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(SPARC)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
#   if IS_WORDSIZE_64
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		int __writer, __shared;
		unsigned long __pad1, __pad2;
		unsigned int __flags;
	} __data;
#   else
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		unsigned char __pad1, __pad2, __shared, __flags;
		int __writer;
	} __data;
# endif
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(SUPERH)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
#   if IS_BIG_ENDIAN
		unsigned char __pad1, __pad2, __shared, __flags;
#   else
		unsigned char __flags, __shared, __pad1, __pad2;
#   endif
		pthread_t __writer;
	} __data;
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(TILE)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
#   if IS_WORDSIZE_64
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		int __writer, __shared;
		unsigned long __pad1, __pad2;
		unsigned int __flags;
	} __data;
#   else
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		unsigned char __flags, __shared, __pad1, __pad2;
		int __writer;
	} __data;
#   endif
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(XTENSA)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
#   if IS_BIG_ENDIAN
		unsigned char __pad1, __pad2, __shared, __flags;
#   else
		unsigned char __flags, __shared, __pad1, __pad2;
#   endif
		int __writer;
	} __data;
	char __size[__SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#endif
#define __DEFINED_pthread_rwlockattr_t   (1)
/** Read-write lock attribute datatype */
typedef union pthread_rwlockattr {
	char __size[__SIZEOF_PTHREAD_RWLOCKATTR_T];
	long __align;
} pthread_rwlockattr_t;
#define __DEFINED_pthread_cond_t   (1)
#if (defined(ARM64) || defined(ITANIUM))  // pthread_cond_t
/** Data structure for conditional variable handling */
typedef union pthread_cond {
	struct __pthread_cond_s {
		int __lock;
		unsigned int __futex;
		unsigned long long __total_seq, __wakeup_seq, __woken_seq;
		void* __mutex;
		unsigned int __nwaiters, __broadcast_seq;
		_pthread_descr wait_chain;
	} __data;
	char __size[__SIZEOF_PTHREAD_COND_T];
	long __align;
} pthread_cond_t;
#elif (defined(ALPHA) || defined(ARC) || defined(ARM) || defined(HPPA) || defined(M68K) || defined(MICROBLAZE) || defined(MIPS) || defined(NIOS2) || defined(POWERPC) || defined(S390) || defined(SPARC) || defined(SUPERH) || defined(TILE))
/** Data structure for conditional variable handling */
typedef union pthread_cond {
	struct __pthread_cond_s {
#   if defined(HPPA)
		int align16 __lock;
#   elif defined(M68K)
		int align4 __lock;
#   else
		int __lock;
#   endif
		unsigned int __futex;
		unsigned long long __total_seq, __wakeup_seq, __woken_seq;
		void* __mutex;
		unsigned int __nwaiters, __broadcast_seq;
		_pthread_descr wait_chain;
	} __data;
	char __size[__SIZEOF_PTHREAD_COND_T];
	long long __align;
} pthread_cond_t;
#else
/** Data structure for conditional variable handling */
typedef union pthread_cond {
	struct __pthread_cond_s {
		int __lock;
		unsigned int __futex;
		unsigned long long __total_seq, __wakeup_seq, __woken_seq;
		void* __mutex;
		unsigned int __nwaiters, __broadcast_seq;
		_pthread_descr wait_chain;
	} __data;
	char __size[__SIZEOF_PTHREAD_COND_T];
	long long __align;
} pthread_cond_t;
#endif
typedef pthread_cond_t   bc_cond_t;
#define __DEFINED_pthread_condattr_t   (1)
#if (defined(ALPHA) || defined(ARC) || defined(ARM64) || defined(ITANIUM) || defined(M68K) || defined(MICROBLAZE) || defined(MIPS) || defined(POWERPC) || defined(S390) || defined(SPARC) || defined(TILE) || defined(X86_64))
/** POSIX condition attribute datatype */
typedef union pthread_condattr {
	char __size[__SIZEOF_PTHREAD_CONDATTR_T];
	int __align;
} pthread_condattr_t;
#elif (defined(ARM) || defined(HPPA) || defined(NIOS2) || defined(SUPERH) || defined(XTENSA))
/** POSIX condition attribute datatype */
typedef union pthread_condattr {
	char __size[__SIZEOF_PTHREAD_CONDATTR_T];
	long __align;
} pthread_condattr_t;
#else
/** POSIX condition attribute datatype */
typedef union pthread_condattr {
	char __size[__SIZEOF_PTHREAD_CONDATTR_T];
	long __align;
} pthread_condattr_t;
#endif
#ifndef __PTHREAD_SPINS
#   define __PTHREAD_SPINS   0
#endif
#ifndef __PTHREAD_RWLOCK_ELISION_EXTRA
/** Mutex __spins initializer used by PTHREAD_MUTEX_INITIALIZER */
#   define __PTHREAD_RWLOCK_ELISION_EXTRA   0
#endif
#define mutex_t   pthread_mutex_t
#define mutexattr_t   pthread_mutexattr_t
#define cond_t   pthread_cond_t
#define condattr_t   pthread_condattr_t
#define rwlock_t   pthread_rwlock_t
#define rwlockattr_t   pthread_rwlockattr_t
#define thread_key_t   pthread_key_t
#define thr_t   pthread_t
#define thrattr_t   pthread_attr_t
#define once_t   pthread_once_t
#define rwlock_t   pthread_rwlock_t
typedef struct __ptcb {
	void (*__f)(void*);
	void* __x;
	struct __ptcb* __next;
} ptcb_t;


// SIGNAL NUMBERS (<bits/signum.h>)

/** No async notification */
#define SIGEV_NONE   0
/** aio - Completion notification */
#define SIGEV_SIGNAL   1
/** Call notification function */
#define SIGEV_THREAD   3
#define SIGHUP   1
#define SIGINT   2
#define SIGQUIT   3
#define SIGILL   4
#define SIGTRAP   5
#define SIGABRT   6
#define SIGIOT   6
#define SIGFPE   8
#define SIGKILL   9
#define SIGSEGV   11
#define SIGPIPE   13
#define SIGALRM   14
#define SIGTERM   15
#define SIGUNUSED   31
#if (defined(ARCHI386) || defined(ARCHX86_64) || defined(ARCHPOWERPC) || defined(ARCHPOWERPC64) || defined(ARCHARM) || defined(ARCHS390) || defined(ARCHITANIUM))
#   define SIGBUS   7
#   define SIGUSR1   10
#   define SIGUSR2   12
#   define SIGSTKFLT   16
#   define SIGCHLD   17
#   define SIGCONT   18
#   define SIGSTOP   19
#   define SIGTSTP   20
#   define SIGTTIN   21
#   define SIGTTOU   22
#   define SIGURG   23
#   define SIGXCPU   24
#   define SIGXFSZ   25
#   define SIGVTALRM   26
#   define SIGPROF   27
#   define SIGWINCH   28
#   define SIGIO   29
#   define SIGPWR   30
#   define SIGSYS   31
#elif (defined(ARCHALPHA) || defined(ARCHSPARC))
#   define SIGEMT   7
#   define SIGBUS   10
#   define SIGSYS   12
#   define SIGURG   16
#   define SIGSTOP   17
#   define SIGTSTP   18
#   define SIGCONT   19
#   define SIGCHLD   20
#   define SIGTTIN   21
#   define SIGTTOU   22
#   define SIGIO   23
#   define SIGXCPU   24
#   define SIGXFSZ   25
#   define SIGVTALRM   26
#   define SIGPROF   27
#   define SIGWINCH   28
#   define SIGPWR   29
#   define SIGUSR1   30
#   define SIGUSR2   31
#   if defined(ARCHALPHA)
#      define SIGINFO   SIGPWR
#   endif
#elif defined(ARCHMIPS)
#   define SIGEMT   7
#   define SIGBUS   10
#   define SIGSYS   12
#   define SIGUSR1   16
#   define SIGUSR2   17
#   define SIGCHLD   18
#   define SIGPWR   19
#   define SIGWINCH   20
#   define SIGURG   21
#   define SIGIO   22
#   define SIGSTOP   23
#   define SIGTSTP   24
#   define SIGCONT   25
#   define SIGTTIN   26
#   define SIGTTOU   27
#   define SIGVTALRM   28
#   define SIGPROF   29
#   define SIGXCPU   30
#   define SIGXFSZ   31
#elif defined(ARCHHPPA)
#   define SIGEMT   7
#   define SIGBUS   10
#   define SIGSYS   12
#   define SIGUSR1   16
#   define SIGUSR2   17
#   define SIGCHLD   18
#   define SIGPWR   19
#   define SIGVTALRM   20
#   define SIGPROF   21
#   define SIGIO   22
#   define SIGWINCH   23
#   define SIGSTOP   24
#   define SIGTSTP   25
#   define SIGCONT   26
#   define SIGTTIN   27
#   define SIGTTOU   28
#   define SIGURG   29
#   define SIGLOST   30
#   define SIGUNUSED   31
#   define SIGRESERVE   SIGUNUSE
#   define SIGXCPU   33
#   define SIGXFSZ   34
#   define SIGSTKFLT   36
#else
#   error   "Signal layout not known for the target platform!"
#endif
#ifndef SIGCLD
#   define SIGCLD   SIGCHLD
#endif
#ifndef SIGPOLL
#   define SIGPOLL   SIGIO
#endif
#ifdef ARCHHPPA
#   define SIGRTMIN   37
#else
#   define SIGLOST   SIGPWR
#   define SIGRTMIN   32
#endif
// SA_FLAGS values
#ifdef ARCHALPHA
#   define SA_ONSTACK   1
#   define SA_RESTART   2
#   define SA_NOCLDSTOP   4
#   define SA_NODEFER   8
#   define SA_RESETHAND   0x10
#   define SA_NOCLDWAIT   0x20
#   define SA_SIGINFO   0x40
#   define SA_INTERRUPT   0x20000000
#elif defined(ARCHHPPA)
#   define SA_ONSTACK   1
#   define SA_RESETHAND   4
#   define SA_NOCLDSTOP   8
#   define SA_SIGINFO   0x10
#   define SA_NODEFER   0x20
#   define SA_RESTART   0x40
#   define SA_NOCLDWAIT   0x80
#   define _SA_SIGGFAULT   0x100
#   define SA_INTERRUPT   0x20000000
#   define SA_RESTORER   0x4000000
#elif defined(ARCHSPARC)
#   define SV_SSTACK   1
#   define SV_INTR   2
#   define SV_RESET   4
#   define SV_IGNCHILD   8
#   define SA_NOCLDSTOP   SV_IGNCHILD
#   define SA_STACK   SV_SSTACK
#   define SA_ONSTACK   SV_SSTACK
#   define SA_RESTART   SV_INTR
#   define SA_RESETHAND   SV_RESET
#   define SA_INTERRUPT   0x10
#   define SA_NODEFER   0x20
#   define SA_SHIRQ   0x40
#   define SA_NOCLDWAIT   0x100
#   define SA_SIGINFO   0x200
#else
#   ifdef ARCHMIPS
#      define SA_NOCLDSTOP   1
#      define SA_SIGINFO   8
#      define SA_NOCLDWAIT   0x10000
#   else
#      define SA_NOCLDSTOP   1
#      define SA_NOCLDWAIT   2
#      define SA_SIGINFO   4
#   endif
#   ifdef ARCHARM
#      define SA_THIRTYTWO   0x2000000
#   endif
#   define SA_RESTORER   0x4000000
#   define SA_ONSTACK   0x8000000
#   define SA_RESTART   0x10000000
#   define SA_INTERRUPT   0x20000000
#   define SA_NODEFER   0x40000000
#   define SA_RESETHAND   0x80000000
#endif
#define SA_NOMASK   SA_NODEFER
#define SA_ONESHOT   SA_RESETHAND
#ifdef ARCHSPARC
#   define SIG_BLOCK   1
#   define SIG_UNBLOCK   2
#   define SIG_SETMASK   4
#elif (defined(ARCHALPHA) || defined(ARCHMIPS))
#   define SIG_BLOCK   1
#   define SIG_UNBLOCK   2
#   define SIG_SETMASK   3
#else
#   define SIG_BLOCK   0
#   define SIG_UNBLOCK   1
#   define SIG_SETMASK   2
#endif
#ifdef ARCHALPHA
/** Values for `si_code`; Positive values are reserved for kernel-generated signals */
enum SI_CODE_ENUM {
	/** Sent by asynch name lookup completion */
	SI_ASYNCNL = -60,
	/** Sent by tkill */
	SI_TKILL = -6,
	/** Sent by queued SIGIO */
	SI_SIGIO,
	/** Sent by AIO completion */
	SI_ASYNCIO,
	/** Sent by real time mesq state change */
	SI_MESGQ,
	/** Sent by timer expiration */
	SI_TIMER,
	/** Sent by sigqueue */
	SI_QUEUE,
	/** Sent by kill, sigsend, raise */
	SI_USER,
	/** Send by kernel */
	SI_KERNEL = 0x80
};
/** `si_code` values for SIGILL signal */
enum SI_CODE_SIGILL_ENUM {
	/** Illegal opcode */
	ILL_ILLOPC = 1,
	/** Illegal operand */
	ILL_ILLOPN,
	/** Illegal addressing mode */
	ILL_ILLADR,
	/** Illegal trap */
	ILL_ILLTRP,
	/** Privileged opcode */
	ILL_PRVOPC,
	/** Privileged register */
	ILL_PRVREG,
	/** Coprocessor error */
	ILL_COPROC,
	/** Internal stack error */
	ILL_BADSTK
};
/** `si_code` values for SIGFPE signal */
enum SI_CODE_SIGFPE_ENUM {
	/** Integer divide by zero */
	FPE_INTDIV = 1,
	/** Integer overflow */
	FPE_INTOVF,
	/** Floating point divide by zero */
	FPE_FLTDIV,
	/** Floating point overflow */
	FPE_FLTOVF,
	/** Floating point underflow */
	FPE_FLTUND,
	/** Floating point inexact result */
	FPE_FLTRES,
	/** Floating point invalid operation */
	FPE_FLTINV,
	/** Subscript out of range */
	FPE_FLTSUB
};
/** `si_code` values for SIGSEGV signal */
enum SI_CODE_SIGSEGV_ENUM {
	/** Address not mapped to object */
	SEGV_MAPERR = 1,
	/** Invalid permissions for mapped object */
	SEGV_ACCERR
};
/** `si_code` values for SIGBUS signal */
enum SI_CODE_SIGBUS_ENUM {
	/** Invalid address alignment */
	BUS_ADRALN = 1,
	/** Non-existant physical address */
	BUS_ADRERR,
	/** Object specific hardware error */
	BUS_OBJERR
};
/** `si_code` values for SIGTRAP signal */
enum SI_CODE_SIGTRAP_ENUM {
	/** Process breakpoint */
	TRAP_BRKPT = 1,
	/** Process trace trap */
	TRAP_TRACE
};
/** `si_code` values for SIGCHLD signal */
enum SI_CODE_SIGCHLD_ENUM {
	/** Child has exited */
	CLD_EXITED = 1,
	/** Child was killed */
	CLD_KILLED,
	/** Child terminated abnormally */
	CLD_DUMPED,
	/** Traced child has trapped */
	CLD_TRAPPED,
	/** Child has stopped */
	CLD_STOPPED,
	/** Stopped child has continued */
	CLD_CONTINUED
};
/** `si_code` values for SIGPOLL signal */
enum SI_CODE_SIGPOLL_ENUM {
	/** Data input available */
	POLL_IN = 1,
	/** Output buffers available */
	POLL_OUT,
	/** Input message available */
	POLL_MSG,
	/** I/O error */
	POLL_ERR,
	/** High priority input available */
	POLL_PRI,
	/** Device disconnected */
	POLL_HUP
};
#elif defined(ARCHITANIUM)
/** Values for `si_code`; Positive values are reserved for kernel-generated signals */
enum SI_CODE_ENUM {
	/** Sent by asynch name lookup completion */
	SI_ASYNCNL = -60,
	/** Sent by tkill */
	SI_TKILL = -6,
	/** Sent by queued SIGIO */
	SI_SIGIO,
	/** Sent by AIO completion */
	SI_ASYNCIO,
	/** Sent by real time mesq state change */
	SI_MESGQ,
	/** Sent by timer expiration */
	SI_TIMER,
	/** Sent by sigqueue */
	SI_QUEUE,
	/** Sent by kill, sigsend, raise */
	SI_USER,
	/** Send by kernel */
	SI_KERNEL = 0x80
};
/** `si_code` values for SIGILL signal */
enum SI_CODE_SIGILL_ENUM {
	/** Illegal opcode */
	ILL_ILLOPC = 1,
	/** Illegal operand */
	ILL_ILLOPN,
	/** Illegal addressing mode */
	ILL_ILLADR,
	/** Illegal trap */
	ILL_ILLTRP,
	/** Privileged opcode */
	ILL_PRVOPC,
	/** Privileged register */
	ILL_PRVREG,
	/** Coprocessor error */
	ILL_COPROC,
	/** Internal stack error */
	ILL_BADSTK,
	/** Unimplemented instruction address */
	ILL_BADIADDR,
	ILL_BREAK
};
/** `si_code` values for SIGFPE signal */
enum SI_CODE_SIGFPE_ENUM {
	/** Integer divide by zero */
	FPE_INTDIV = 1,
	/** Integer overflow */
	FPE_INTOVF,
	/** Floating point divide by zero */
	FPE_FLTDIV,
	/** Floating point overflow */
	FPE_FLTOVF,
	/** Floating point underflow */
	FPE_FLTUND,
	/** Floating point inexact result */
	FPE_FLTRES,
	/** Floating point invalid operation */
	FPE_FLTINV,
	/** Subscript out of range */
	FPE_FLTSUB,
	/** Decimal floating point overflow */
	FPE_DECOVF,
	FPE_DECDIV,
	FPE_DECERR,
	FPE_INVASC,
	FPE_INVDEC
};
/** `si_code` values for SIGSEGV signal */
enum SI_CODE_SIGSEGV_ENUM {
	/** Address not mapped to object */
	SEGV_MAPERR = 1,
	/** Invalid permissions for mapped object */
	SEGV_ACCERR,
	/** Paragraph stack overflow */
	SEGV_PSTKOVF
};
/** `si_code` values for SIGBUS signal */
enum SI_CODE_SIGBUS_ENUM {
	/** Invalid address alignment */
	BUS_ADRALN = 1,
	/** Non-existant physical address */
	BUS_ADRERR,
	/** Object specific hardware error */
	BUS_OBJERR
};
/** `si_code` values for SIGTRAP signal */
enum SI_CODE_SIGTRAP_ENUM {
	/** Process breakpoint */
	TRAP_BRKPT = 1,
	/** Process trace trap */
	TRAP_TRACE,
	TRAP_BRANCH,
	TRAP_HWBKPT
};
/** `si_code` values for SIGCHLD signal */
enum SI_CODE_SIGCHLD_ENUM {
	/** Child has exited */
	CLD_EXITED = 1,
	/** Child was killed */
	CLD_KILLED,
	/** Child terminated abnormally */
	CLD_DUMPED,
	/** Traced child has trapped */
	CLD_TRAPPED,
	/** Child has stopped */
	CLD_STOPPED,
	/** Stopped child has continued */
	CLD_CONTINUED
};
/** `si_code` values for SIGPOLL signal */
enum SI_CODE_SIGPOLL_ENUM {
	/** Data input available */
	POLL_IN = 1,
	/** Output buffers available */
	POLL_OUT,
	/** Input message available */
	POLL_MSG,
	/** I/O error */
	POLL_ERR,
	/** High priority input available */
	POLL_PRI,
	/** Device disconnected */
	POLL_HUP
};
#elif defined(ARCHMIPS)
/** Values for `si_code`; Positive values are reserved for kernel-generated signals */
enum SI_CODE_ENUM {
	/** Sent by asynch name lookup completion */
	SI_ASYNCNL = -60,
	/** Sent by tkill */
	SI_TKILL = -6,
	/** Sent by queued SIGIO */
	SI_SIGIO,
	/** Sent by real time mesq state change */
	SI_MESGQ,
	/** Sent by real time mesq state change */
	SI_TIMER,
	/** Sent by AIO completion */
	SI_ASYNCIO,
	/** Sent by sigqueue */
	SI_QUEUE,
	/** Sent by kill, sigsend */
	SI_USER,
	/** Send by kernel */
	SI_KERNEL = 0x80
};
/** `si_code` values for SIGILL signal */
enum SI_CODE_SIGILL_ENUM {
	/** Illegal opcode */
	ILL_ILLOPC = 1,
	/** Illegal operand */
	ILL_ILLOPN,
	/** Illegal addressing mode */
	ILL_ILLADR,
	/** Illegal trap */
	ILL_ILLTRP,
	/** Privileged opcode */
	ILL_PRVOPC,
	/** Privileged register */
	ILL_PRVREG,
	/** Coprocessor error */
	ILL_COPROC,
	/** Internal stack error */
	ILL_BADSTK
};
/** `si_code` values for SIGFPE signal */
enum SI_CODE_SIGFPE_ENUM {
	/** Integer divide by zero */
	FPE_INTDIV = 1,
	/** Integer overflow */
	FPE_INTOVF,
	/** Floating point divide by zero */
	FPE_FLTDIV,
	/** Floating point overflow */
	FPE_FLTOVF,
	/** Floating point underflow */
	FPE_FLTUND,
	/** Floating point inexact result */
	FPE_FLTRES,
	/** Floating point invalid operation */
	FPE_FLTINV,
	/** Subscript out of range */
	FPE_FLTSUB
};
/** `si_code` values for SIGSEGV signal */
enum SI_CODE_SIGSEGV_ENUM {
	/** Address not mapped to object */
	SEGV_MAPERR = 1,
	/** Invalid permissions for mapped object */
	SEGV_ACCERR
};
/** `si_code` values for SIGBUS signal */
enum SI_CODE_SIGBUS_ENUM {
	/** Invalid address alignment */
	BUS_ADRALN = 1,
	/** Non-existant physical address */
	BUS_ADRERR,
	/** Object specific hardware error */
	BUS_OBJERR,
	/** Hardware memory error: action required */
	BUS_MCEERR_AR,
	/** Hardware memory error: action optional */
	BUS_MCEERR_AO
};
/** `si_code` values for SIGTRAP signal */
enum SI_CODE_SIGTRAP_ENUM {
	/** Process breakpoint */
	TRAP_BRKPT = 1,
	/** Process trace trap */
	TRAP_TRACE
};
/** `si_code` values for SIGCHLD signal */
enum SI_CODE_SIGCHLD_ENUM {
	/** Child has exited */
	CLD_EXITED = 1,
	/** Child was killed */
	CLD_KILLED,
	/** Child terminated abnormally */
	CLD_DUMPED,
	/** Traced child has trapped */
	CLD_TRAPPED,
	/** Child has stopped */
	CLD_STOPPED,
	/** Stopped child has continued */
	CLD_CONTINUED
};
/** `si_code` values for SIGPOLL signal */
enum SI_CODE_SIGPOLL_ENUM {
	/** Data input available */
	POLL_IN = 1,
	/** Output buffers available */
	POLL_OUT,
	/** Input message available */
	POLL_MSG,
	/** I/O error */
	POLL_ERR,
	/** High priority input available */
	POLL_PRI,
	/** Device disconnected */
	POLL_HUP
};
#elif defined(ARCHSPARC)
/** Values for `si_code`; Positive values are reserved for kernel-generated signals */
enum SI_CODE_ENUM {
	/** Sent by asynch name lookup completion */
	SI_ASYNCNL = -60,
	/** Sent by tkill */
	SI_TKILL = -6,
	/** Sent by queued SIGIO */
	SI_SIGIO,
	/** Sent by AIO completion */
	SI_ASYNCIO,
	/** Sent by real time mesq state change */
	SI_MESGQ,
	/** Sent by timer expiration */
	SI_TIMER,
	/** Sent by sigqueue */
	SI_QUEUE,
	/** Sent by kill, sigsend, raise */
	SI_USER,
	/** Send by kernel */
	SI_KERNEL = 0x80
};
/** `si_code` values for SIGILL signal */
enum SI_CODE_SIGILL_ENUM {
	/** Illegal opcode */
	ILL_ILLOPC = 1,
	/** Illegal operand */
	ILL_ILLOPN,
	/** Illegal addressing mode */
	ILL_ILLADR,
	/** Illegal trap */
	ILL_ILLTRP,
	/** Privileged opcode */
	ILL_PRVOPC,
	/** Privileged register */
	ILL_PRVREG,
	/** Coprocessor error */
	ILL_COPROC,
	/** Internal stack error */
	ILL_BADSTK
};
/** `si_code` values for SIGFPE signal */
enum SI_CODE_SIGFPE_ENUM {
	/** Integer divide by zero */
	FPE_INTDIV = 1,
	/** Integer overflow */
	FPE_INTOVF,
	/** Floating point divide by zero */
	FPE_FLTDIV,
	/** Floating point overflow */
	FPE_FLTOVF,
	/** Floating point underflow */
	FPE_FLTUND,
	/** Floating point inexact result */
	FPE_FLTRES,
	/** Floating point invalid operation */
	FPE_FLTINV,
	/** Subscript out of range */
	FPE_FLTSUB
};
/** `si_code` values for SIGSEGV signal */
enum SI_CODE_SIGSEGV_ENUM {
	/** Address not mapped to object */
	SEGV_MAPERR = 1,
	/** Invalid permissions for mapped object */
	SEGV_ACCERR
};
/** `si_code` values for SIGBUS signal */
enum SI_CODE_SIGBUS_ENUM {
	/** Invalid address alignment */
	BUS_ADRALN = 1,
	/** Non-existant physical address */
	BUS_ADRERR,
	/** Object specific hardware error */
	BUS_OBJERR
};
/** `si_code` values for SIGTRAP signal */
enum SI_CODE_SIGTRAP_ENUM {
	/** Process breakpoint */
	TRAP_BRKPT = 1,
	/** Process trace trap */
	TRAP_TRACE
};
/** `si_code` values for SIGCHLD signal */
enum SI_CODE_SIGCHLD_ENUM {
	/** Child has exited */
	CLD_EXITED = 1,
	/** Child was killed */
	CLD_KILLED,
	/** Child terminated abnormally */
	CLD_DUMPED,
	/** Traced child has trapped */
	CLD_TRAPPED,
	/** Child has stopped */
	CLD_STOPPED,
	/** Stopped child has continued */
	CLD_CONTINUED
};
/** `si_code` values for SIGPOLL signal */
enum SI_CODE_SIGPOLL_ENUM {
	/** Data input available */
	POLL_IN = 1,
	/** Output buffers available */
	POLL_OUT,
	/** Input message available */
	POLL_MSG,
	/** I/O error */
	POLL_ERR,
	/** High priority input available */
	POLL_PRI,
	/** Device disconnected */
	POLL_HUP
};
/** `si_code` values for SIGEMT signal */
enum SI_CODE_SIGEMT_ENUM {
	/** Tag overflow */
	EMT_TAGOVF = 1
};
#else
/** Values for `si_code`; Positive values are reserved for kernel-generated signals */
enum SI_CODE_ENUM {
	/** Sent by asynch name lookup completion */
	SI_ASYNCNL = -60,
	/** Sent by tkill */
	SI_TKILL = -6,
	/** Sent by queued SIGIO */
	SI_SIGIO,
	/** Sent by AIO completion */
	SI_ASYNCIO,
	/** Sent by real time mesq state change */
	SI_MESGQ,
	/** Sent by timer expiration */
	SI_TIMER,
	/** Sent by sigqueue */
	SI_QUEUE,
	/** Sent by kill, sigsend, raise */
	SI_USER,
	/** Send by kernel */
	SI_KERNEL = 0x80
};
/** `si_code` values for SIGILL signal */
enum SI_CODE_SIGILL_ENUM {
	/** Illegal opcode */
	ILL_ILLOPC = 1,
	/** Illegal operand */
	ILL_ILLOPN,
	/** Illegal addressing mode */
	ILL_ILLADR,
	/** Illegal trap */
	ILL_ILLTRP,
	/** Privileged opcode */
	ILL_PRVOPC,
	/** Privileged register */
	ILL_PRVREG,
	/** Coprocessor error */
	ILL_COPROC,
	/** Internal stack error */
	ILL_BADSTK
};
/** `si_code` values for SIGFPE signal */
enum SI_CODE_SIGFPE_ENUM {
	/** Integer divide by zero */
	FPE_INTDIV = 1,
	/** Integer overflow */
	FPE_INTOVF,
	/** Floating point divide by zero */
	FPE_FLTDIV,
	/** Floating point overflow */
	FPE_FLTOVF,
	/** Floating point underflow */
	FPE_FLTUND,
	/** Floating point inexact result */
	FPE_FLTRES,
	/** Floating point invalid operation */
	FPE_FLTINV,
	/** Subscript out of range */
	FPE_FLTSUB
};
/** `si_code` values for SIGSEGV signal */
enum SI_CODE_SIGSEGV_ENUM {
	/** Address not mapped to object */
	SEGV_MAPERR = 1,
	/** Invalid permissions for mapped object */
	SEGV_ACCERR
};
/** `si_code` values for SIGBUS signal */
enum SI_CODE_SIGBUS_ENUM {
	/** Invalid address alignment */
	BUS_ADRALN = 1,
	/** Non-existant physical address */
	BUS_ADRERR,
	/** Object specific hardware error */
	BUS_OBJERR
};
/** `si_code` values for SIGTRAP signal */
enum SI_CODE_SIGTRAP_ENUM {
	/** Process breakpoint */
	TRAP_BRKPT = 1,
	/** Process trace trap */
	TRAP_TRACE
};
/** `si_code` values for SIGCHLD signal */
enum SI_CODE_SIGCHLD_ENUM {
	/** Child has exited */
	CLD_EXITED = 1,
	/** Child was killed */
	CLD_KILLED,
	/** Child terminated abnormally */
	CLD_DUMPED,
	/** Traced child has trapped */
	CLD_TRAPPED,
	/** Child has stopped */
	CLD_STOPPED,
	/** Stopped child has continued */
	CLD_CONTINUED
};
/** `si_code` values for SIGPOLL signal */
enum SI_CODE_SIGPOLL_ENUM {
	/** Data input available */
	POLL_IN = 1,
	/** Output buffers available */
	POLL_OUT,
	/** Input message available */
	POLL_MSG,
	/** I/O error */
	POLL_ERR,
	/** High priority input available */
	POLL_PRI,
	/** Device disconnected */
	POLL_HUP
};
#endif


#ifndef _NSIG
/** Biggest signal number + 1 (including real-time signals) */
#   define _NSIG   (65)
#endif
/** Biggest signal number + 1 (including real-time signals) */
#define NSIG   _NSIG
// Real-time signal range
#ifndef __SIGRTMIN
#   define __SIGRTMIN   SIGRTMIN
#endif
#define __SIGRTMAX   (_NSIG - 1)
#define SIGRTMAX   __SIGRTMAX
/** Return number of available real-time signal with highest priority */
#define __libc_current_sigrtmin_private()   SIGRTMIN
/** Return number of available real-time signal with highest priority */
#define __libc_current_sigrtmin()   SIGRTMIN
/** Return number of available real-time signal with lowest priority */
#define __libc_current_sigrtmax_private()   SIGRTMAX
/** Return number of available real-time signal with lowest priority */
#define __libc_current_sigrtmax()   SIGRTMAX
#define _SYS_SIGMSG_MAXLEN   (25)
#define _STRSIGNAL_BUFSIZE   _SYS_SIGMSG_MAXLEN
// Sanity check
#if ((!defined(__SIGRTMIN)) || ((__SIGRTMAX - __SIGRTMIN) < 3))
#   error   "Missing or invalid __SIGRTMAX and __SIGRTMIN values"
#endif
#ifdef MIPS
#   define _SIGSET_NWORDS   (128 / BITS_PER_LONG)
#else
#   define _SIGSET_NWORDS   (64 / BITS_PER_LONG)
#endif
#define SIGSET_NWORDS   _SIGSET_NWORDS
// Flags for signalfd
#define SFD_CLOEXEC   02000000
#define SFD_NONBLOCK   04000

typedef struct signalfd_siginfo {
	uint32_t ssi_signo;
	int32_t ssi_errno, ssi_code;
	uint32_t ssi_pid, ssi_uid;
	int32_t ssi_fd;
	uint32_t ssi_tid, ssi_band, ssi_overrun, ssi_trapno;
	int32_t ssi_status, ssi_int;
	uint64_t ssi_ptr, ssi_utime, ssi_stime, ssi_addr;
	uint8_t __pad[48];
} signalfd_siginfo_t;
/** Signal handler datatype */
typedef void (*__sighandler_t)(int);
/** Signal handler datatype */
typedef __sighandler_t   sighandler_t;
/** Signal handler datatype */
typedef sighandler_t   sig_t;  // 4.4 BSD
typedef long   fd_mask;
#define __fd_mask   fd_mask
/** Set by siginterrupt */
static UNUSED sigset_t _sigintr;
/** Structure passed to `sigvec` */
typedef struct sigvec {
	__sighandler_t sv_handler;  // Signal handler
	int sv_mask;  // Mask of signals to be blocked
	int sv_flags;  // Flags
} sigvec_t;
#define sv_onstack   sv_flags
// Bits in `sv_flags`
/** Take the signal on the signal stack */
#define SV_ONSTACK   (1)
/** Do not restart system calls */
#define SV_INTERRUPT   (2)
/** Reset handler to SIG_DFL on receipt */
#define SV_RESETHAND   (4)
// Fake signal functions
/** Error return */
#define SIG_ERR   ((sighandler_t)(-1))
/** Default action */
#define SIG_DFL   ((sighandler_t)0)
/** Ignore signal */
#define SIG_IGN   ((sighandler_t)1)
/** Add signal to hold mask */
#define SIG_HOLD  ((sighandler_t)2)

#if (!(defined(_BITS_SIGACTION_STRUCT_H) || defined(_BITS_SIGACTION_STRUCT_H_)))  // sigaction
#define _BITS_SIGACTION_STRUCT_H  (1)
#define _BITS_SIGACTION_STRUCT_H_  (1)


#ifdef ALPHA  // sigaction

/** This is the sigaction struct from the Linux 2.1.20 kernel */
struct old_kernel_sigaction {
	__sighandler_t k_sa_handler;
	unsigned long sa_mask;
	unsigned int sa_flags;
};
/** Structure describing the action to be taken when a signal arrives */
struct sigaction {
	__sighandler_t sa_handler;
	unsigned int sa_flags;
	sigset_t sa_mask;
};
// Bits in `sa_flags`
/** Do not send SIGCHLD when children stop */
#define SA_NOCLDSTOP   4
/** Do not create zombie on child death */
#define SA_NOCLDWAIT   0x20
/** Invoke signal-catching function with three arguments instead of one */
#define SA_SIGINFO   0x40
/** Use signal stack by using `sa_restorer' */
#define SA_ONSTACK   1
/** Restart syscall on signal return */
#define SA_RESTART   2
/** Do not automatically block the signal when its handler is being executed */
#define SA_NODEFER   8
/** Reset to SIG_DFL on entry to handler */
#define SA_RESETHAND   0x10
/** Historical no-op */
#define SA_INTERRUPT   0x20000000
// Some aliases for the SA_ constants
#define SA_NOMASK   SA_NODEFER
#define SA_ONESHOT   SA_RESETHAND
#define SA_STACK   SA_ONSTACK
// Values for the HOW argument to `sigprocmask`
/** Block signals */
#define SIG_BLOCK   1
/** Unblock signals */
#define SIG_UNBLOCK   2
/** Set the set of blocked signals */
#define SIG_SETMASK   3

#elif defined(ITANIUM)

/** This is the sigaction struct from the Linux 2.1.20 kernel */
struct old_kernel_sigaction {
	__sighandler_t k_sa_handler;
	unsigned long sa_mask, sa_flags;
	void (*sa_restorer)(void);
};
/** Structure describing the action to be taken when a signal arrives */
struct sigaction {
	__sighandler_t sa_handler;
	unsigned long sa_flags;
	sigset_t sa_mask;
};
// Bits in `sa_flags`
/** Do not send SIGCHLD when children stop */
#define SA_NOCLDSTOP   1
/** Do not create zombie on child death */
#define SA_NOCLDWAIT   2
#define SA_SIGINFO    4
/** Use signal stack by using `sa_restorer` */
#define SA_ONSTACK   0x8000000
/** Restart syscall on signal return */
#define SA_RESTART   0x10000000
/** Do not automatically block the signal when its handler is being executed */
#define SA_NODEFER   0x40000000
/** Reset to SIG_DFL on entry to handler */
#define SA_RESETHAND   0x80000000
/** Historic no-op */
#define SA_INTERRUPT   0x20000000
// Some aliases for the SA_ constants
#define SA_NOMASK   SA_NODEFER
#define SA_ONESHOT   SA_RESETHAND
#define SA_STACK   SA_ONSTACK
// Values for the HOW argument to `sigprocmask`
/** for blocking signals */
#define SIG_BLOCK   0
/** for unblocking signals */
#define SIG_UNBLOCK   1
/** Used for setting the signal mask */
#define SIG_SETMASK   2

#elif defined(HPPA)

/** This is the sigaction struct from the Linux 2.1.20 kernel */
struct old_kernel_sigaction {
	__sighandler_t k_sa_handler;
	unsigned long sa_mask, sa_flags;
};
/** Structure describing the action to be taken when a signal arrives */
struct sigaction {
	__sighandler_t sa_handler;
	unsigned long sa_flags;
	sigset_t sa_mask;
};
// Bits in `sa_flags`
/** Do not send SIGCHLD when children stop */
#define SA_NOCLDSTOP   8
/** Do not create zombie on child death */
#define SA_NOCLDWAIT   0x80
/** Invoke signal-catching function with three arguments instead of one */
#define SA_SIGINFO   0x10
/** Use signal stack by using `sa_restorer` */
#define SA_ONSTACK   1
/** Reset to SIG_DFL on entry to handler */
#define SA_RESETHAND   4
/** Do not automatically block the signal when its handler is being executed */
#define SA_NODEFER   0x20
/** Restart syscall on signal return */
#define SA_RESTART   0x40
/** Historic no-op */
#define SA_INTERRUPT   0x20000000
// Some aliases for the SA_ constants
#define SA_NOMASK   SA_NODEFER
#define SA_ONESHOT   SA_RESETHAND
#define SA_STACK   SA_ONSTACK
// Values for the HOW argument to `sigprocmask`
/** for blocking signals */
#define SIG_BLOCK   0
/** for unblocking signals */
#define SIG_UNBLOCK   1
/** for setting the signal mask */
#define SIG_SETMASK   2

#elif defined(MIPS)

/** This is the sigaction struct from the Linux 2.1.20 kernel */
struct old_kernel_sigaction {
	unsigned int sa_flags;
	__sighandler_t k_sa_handler;
	unsigned long sa_mask;
	unsigned int __pad0[3];
	void (*sa_restorer)(void);
#if (_MIPS_SZPTR < 64)
	int pad1[1];
#endif
};
/** Structure describing the action to be taken when a signal arrives */
struct sigaction {
	unsigned sa_flags;
	__sighandler_t sa_handler;
	sigset_t sa_mask;
	void (*sa_restorer)(void);
	int s_resv[1];
};
// Bits in `sa_flags`
/** Do not send SIGCHLD when children stop */
#define SA_NOCLDSTOP   1
/** Do not create zombie on child death */
#define SA_NOCLDWAIT   0x10000
/** Invoke signal-catching function with three arguments instead of one */
#define SA_SIGINFO   8
/** Use signal stack by using `sa_restorer` */
#define SA_ONSTACK   0x8000000
/** Reset to SIG_DFL on entry to handler */
#define SA_RESETHAND   0x80000000
/** Restart syscall on signal return */
#define SA_RESTART   0x10000000
/** Do not automatically block the signal when its handler is being executed */
#define SA_NODEFER   0x40000000
/** Historical no-op */
#define SA_INTERRUPT   0x20000000
// Some aliases for the SA_ constants
#define SA_NOMASK   SA_NODEFER
#define SA_ONESHOT   SA_RESETHAND
#define SA_STACK   SA_ONSTACK
// Values for the HOW argument to `sigprocmask`
/** 0 is unused to catch errors */
#define SIG_NOP   0
/** Block signals */
#define SIG_BLOCK   1
/** Unblock signals */
#define SIG_UNBLOCK   2
/** Set the set of blocked signals */
#define SIG_SETMASK   3
/** From SGI for BSD compatibility: set only the low 32 bit of the sigset */
#define SIG_SETMASK32   256

#elif defined(SPARC)

/** This is the sigaction struct from the Linux 2.1.20 kernel */
struct old_kernel_sigaction {
	__sighandler_t k_sa_handler;
	unsigned long sa_mask, sa_flags;
};
/** Structure describing the action to be taken when a signal arrives */
struct sigaction {
	__sighandler_t sa_handler;
	unsigned long sa_flags;
	void (*sa_restorer)(void);
	sigset_t sa_mask;
};
// Bits in `sa_flags`
/** Do not send SIGCHLD when children stop */
#define SA_NOCLDSTOP   8
/** Do not create zombie on child death */
#define SA_NOCLDWAIT   0x100
/** Invoke signal-catching function with three arguments instead of one */
#define SA_SIGINFO   0x200
/** Use signal stack by using `sa_restorer` */
#define SA_ONSTACK   1
/** Restart syscall on signal return */
#define SA_RESTART   2
/** Historical no-op */
#define SA_INTERRUPT   0x10
/** Do not automatically block the signal when its handler is being executed */
#define SA_NOMASK   0x20
/** Reset to SIG_DFL on entry to handler */
#define SA_ONESHOT   4
// Some aliases for the SA_ constants
#define SA_NODEFER   SA_NOMASK
#define SA_RESETHAND   SA_ONESHOT
#define SA_STACK   SA_ONSTACK
// Values for the HOW argument to `sigprocmask`
/** Block signals */
#define SIG_BLOCK   1
/** Unblock signals */
#define SIG_UNBLOCK   2
/** Set the set of blocked signals */
#define SIG_SETMASK   4

#else

/** This is the sigaction struct from the Linux 2.1.20 kernel */
struct old_kernel_sigaction {
	__sighandler_t k_sa_handler;
	unsigned long sa_mask, sa_flags;
	void (*sa_restorer)(void);
};
/** Structure describing the action to be taken when a signal arrives */
struct sigaction {
	__sighandler_t sa_handler;
	unsigned long sa_flags;
	void (*sa_restorer)(void);
	sigset_t sa_mask;
};
// Bits in `sa_flags`
/** Do not send SIGCHLD when children stop */
#define SA_NOCLDSTOP   1
/** Do not create zombie on child death */
#define SA_NOCLDWAIT   2
/** Invoke signal-catching function with three arguments instead of one */
#define SA_SIGINFO   4
/** Use signal stack by using `sa_restorer` */
#define SA_ONSTACK   0x8000000
/** Restart syscall on signal return */
#define SA_RESTART   0x10000000
/** Do not automatically block the signal when its handler is being executed */
#define SA_NODEFER   0x40000000
/** Reset to SIG_DFL on entry to handler */
#define SA_RESETHAND   0x80000000
/** Historical no-op */
#define SA_INTERRUPT   0x20000000
// Some aliases for the SA_ constants
#define SA_NOMASK   SA_NODEFER
#define SA_ONESHOT   SA_RESETHAND
#define SA_STACK   SA_ONSTACK
// Values for the HOW argument to `sigprocmask`
/** Block signals */
#define SIG_BLOCK   0
/** Unblock signals */
#define SIG_UNBLOCK   1
/** Set the set of blocked signals */
#define SIG_SETMASK   2

#endif  // sigaction


#endif  // BITS_SIGACTION_STRUCT_H


// LOCALE & ICONV DATATYPES

/** __LC_LAST is changed whenever a new locale is defined */
#define __LC_LAST   (13)
#define __LC_CTYPE   (0)
#define __LC_NUMERIC   (1)
#define __LC_TIME   (2)
#define __LC_COLLATE   (3)
#define __LC_MONETARY   (4)
#define __LC_MESSAGES   (5)
#define __LC_ALL   (6)
#define __LC_PAPER   (7)
#define __LC_NAME   (8)
#define __LC_ADDRESS   (9)
#define __LC_TELEPHONE   (10)
#define __LC_MEASUREMENT   (11)
#define __LC_IDENTIFICATION   (12)
#define LC_CTYPE   __LC_CTYPE
#define LC_NUMERIC   __LC_NUMERIC
#define LC_TIME   __LC_TIME
#define LC_COLLATE   __LC_COLLATE
#define LC_MONETARY   __LC_MONETARY
#define LC_MESSAGES   __LC_MESSAGES
#define LC_ALL   __LC_ALL
#define LC_PAPER   __LC_PAPER
#define LC_NAME   __LC_NAME
#define LC_ADDRESS   __LC_ADDRESS
#define LC_TELEPHONE   __LC_TELEPHONE
#define LC_MEASUREMENT   __LC_MEASUREMENT
#define LC_IDENTIFICATION   __LC_IDENTIFICATION

typedef struct alias_map { const char* alias; const char* value; }   alias_map_t;

/** Collation sorting rules */
enum coll_sort_rule {
	illegal_0__, sort_forward, sort_backward, illegal_3__,
	sort_position, sort_forward_position, sort_backward_position, sort_mask
};

/** Collation encoding type */
typedef enum collation_encoding_type { __cet_other, __cet_8bit, __cet_utf8 }   collation_encoding_t;

typedef struct attr_packed __collate_struct {
	uint16_t num_weights, num_starters;
	uint16_t ii_shift, ti_shift, ii_len, ti_len;
	uint16_t max_weight, num_col_base, max_col_index;
	uint16_t undefined_idx, range_low, range_count;
	uint16_t range_base_weight, range_rule_offset, ii_mask, ti_mask;
	const uint16_t *index2weight_tbl, *index2ruleidx_tbl;
	const uint16_t* multistart_tbl;
	const uint16_t* wcs2colidt_tbl;
	const uint16_t* overrides_tbl;
	const uint16_t* weightstr;
	const uint16_t* ruletable;
	uint16_t *index2weight, *index2ruleidx;
	uint16_t MAX_WEIGHTS;
} __collate_t;

/** Structure describing locale data in core for a category */
struct attr_packed __locale_data {
	const char* name;
	const char* filedata;  // Region mapping the file data
	off_t filesize;  // Size of the file (and the region)
	enum _alloc_e {  // Flavor of storage used for those
		ld_malloced, ld_mapped, ld_archive
	} alloc;
	// This provides a slot for category-specific code to cache data computed about this locale; That code can set a cleanup function to deallocate the data
	struct _private {
		void (*cleanup)(struct __locale_data*) internal_function;
		union _private_u {
			void *data;
			struct lc_time_data* time;
			const struct gconv_fcts* ctype;
		} private_u;
	} private;
	unsigned int usage_count;  // Counter for users
	int use_translit;
	unsigned int nstrings;  // Number of strings below
	union locale_data_value {
		const uint32_t* wstr;
		const char* _string;
		unsigned int word;  // Note endian issues vs 64-bit pointers
	} values __flexarr;  // Items, usually pointers into `filedata`
};

/** Structure for reentrant locale using functions; This is an opaque type for the user level programs; The file and this data structure is not standardized, so do not rely on it */
typedef struct __locale_struct {
	struct __locale_data* __locales[__LC_LAST];
	const unsigned short* __ctype_b;
	const int *__ctype_tolower, *__ctype_toupper;
	const char* __names[13];
} *__locale_t;

/** POSIX 2008 makes locale_t official */
typedef __locale_t   locale_t;
#define _xlocale   __locale_t
#define __DEFINED_locale_t   (1)

/** Datatype used by the message catalog functions catopen(), catgets(), and catclose() to identify a catalog descriptor */
typedef void*   nl_catd;
#define nl_catd_t   nl_catd
/** Datatype used by nl_langinfo() to identify items of langinfo data */
typedef signed int   nl_item;
#define nl_item_t   nl_item
#define __darwin_nl_item   nl_item
#define __darwin_nl_item_t   nl_item
#define darwin_nl_item_t   nl_item

/** Identifier for conversion method from one codeset to another */
typedef void*   iconv_t;
typedef uint16_t   gidx_t;
typedef struct _utf8_state { wchar_t ch; int want; wchar_t lbound; }   utf8_state_t;


typedef struct attr_packed _RuneLocale {
	char magic[8];  // Magic saying what version we are
	char encoding[32];  // ASCII name of this encoding
	rune_t (*sgetrune)(const char*, size_t, char const**);
	int (*sputrune)(rune_t, char*, size_t, char**);
	rune_t invalid_rune;
	unsigned long runetype[_CACHED_RUNES];
	rune_t maplower[_CACHED_RUNES];
	rune_t mapupper[_CACHED_RUNES];
	_RuneRange runetype_ext, maplower_ext, mapupper_ext;
	void* variable;  // Data which depends on the encoding
	int variable_len;  // Data length
} _RuneLocale;


typedef struct _FileRuneLocale {
	char frl_magic[8];  // Magic saying what version we are
	char frl_encoding[32];  // ASCII name of this encoding
	int32_t frl_invalid_rune;
	_RuneType frl_runetype[_CACHED_RUNES];
	int32_t frl_maplower[_CACHED_RUNES];
	int32_t frl_mapupper[_CACHED_RUNES];
	_FileRuneRange frl_runetype_ext;
	_FileRuneRange frl_maplower_ext;
	_FileRuneRange frl_mapupper_ext;
	int32_t frl_variable_len;  // Data length
} _FileRuneLocale;


// I/O & FILE DATATYPES

#if (!(defined(WCIO_H) || defined(_WCIO_H) || defined(_WCIO_H_)))
#define WCIO_H   (1)
#define _WCIO_H   (1)
#define _WCIO_H_   (1)


/** Minimal requirement of SUSv2 */
#define WCIO_UNGETWC_BUFSIZE   1

typedef struct attr_packed wchar_io_data {
	mbstate_t wcio_mbstate_in, wcio_mbstate_out;
	wchar_t wcio_ungetwc_buf[WCIO_UNGETWC_BUFSIZE];
	size_t wcio_ungetwc_inbuf;
	int wcio_mode;
} wchar_io_data_t;

#define WCIO_GET(fp)   (&(_EXT(fp)->_wcio))
#define _SET_ORIENTATION(fp, mode)   do { struct wchar_io_data* _wcio = WCIO_GET(fp); if (_wcio && _wcio->wcio_mode == 0) { _wcio->wcio_mode = (mode); } } while (0x0)
#define WCIO_FREEUB(fp)   do { _EXT(fp)->_wcio.wcio_ungetwc_inbuf = 0; } while (0x0)
#define WCIO_FREE(fp)   do { _EXT(fp)->_wcio.wcio_mode = 0; WCIO_FREEUB(fp); } while (0x0)


#endif  // WCIO_H


#define F_PERM   1
#define F_NORD   4
#define F_NOWR   8
#define F_EOF   16
#define F_ERR   32
#define F_SVB   64
#define F_APP   128


typedef struct attr_packed __sbuf { unsigned char* _base; int _size; }   sbuf_t;
/** I/O descriptor for __sfvwrite() */
typedef struct __siov { void* iov_base; size_t iov_len; }   siov_t;
/** I/O descriptor for __sfvwrite() */
typedef struct __suio { struct __siov* uio_iov; int uio_iovcnt, uio_resid; }   suio_t;
typedef struct _G_fpos { off_t __pos; mbstate_t __state; }   _G_fpos_t;
#define G_fpos_t   _G_fpos_t
typedef struct _G_fpos64 { off64_t __pos; mbstate_t __state; }   _G_fpos64_t;
#define G_fpos64_t   _G_fpos64_t
typedef struct cookie { wchar_t* ws; size_t l; }   cookie_t;


typedef struct attr_packed _dirdesc {
	int dd_fd;  // File descriptor associated with directory
	long dd_loc;  // Offset in current buffer
	long dd_size;  // Amount of data returned by getdents
	char* dd_buf;  // Data buffer
	int dd_len;  // Size of data buffer
	off_t dd_seek;  // Magic cookie returned by getdents
	long dd_rewind;  // Magic cookie for rewinding
	int dd_flags;  // Flags for readdir
	void* dd_lock;  // Lock for concurrent access
} dirdesc_t;
#define dirfd(dirp)   (((struct _dirdesc*)dirp)->dd_fd)


typedef struct file_cookie {
	char** bufp;
	size_t* sizep;
	size_t pos;
	char* buf;
	size_t len, space;
} file_cookie_t;


typedef struct wms_cookie {
	wchar_t** bufp;
	size_t* sizep;
	size_t pos;
	wchar_t* buf;
	size_t len, space;
	mbstate_t mbs;
} wms_cookie_t;


/** File extension */
typedef struct attr_packed __sfileext {
	struct __sbuf _ub;  // ungetc buffer
	struct wchar_io_data _wcio;  // wide char io status
	size_t _fgetstr_len;
	char* _fgetstr_buf;
#ifdef IS_REENTRANT
	mutex_t _lock;  // Lock for FLOCKFILE/FUNLOCKFILE
	cond_t _lockcond;  // Condition variable for signalling lock releases
	thr_t _lockowner;  // The thread currently holding the lock
	int _lockcount;  // Count of recursive locks
	int _lockinternal;  // Flag of whether the lock is held inside stdio
	int _lockcancelstate;  // Stashed cancellation state on internal lock
#endif
} __sfileext_t;


#define _EXT(fp)   ((struct __sfileext*)(void*)((fp)->_ub._base))
#define _UB(fp)   _EXT(fp)
#define _FILEEXT_SETUP(f, fext)   do { (f)->_ub._base = (unsigned char*)(fext); (fext)->_fgetstr_len = 0; (fext)->_fgetstr_buf = NULL; } while (0x0)


typedef struct attr_packed __sFILEX {
	unsigned char* up;  // Saved _p when _p is doing ungetc data
	mbstate_t mbstate;  // Multibyte conversion state
	pthread_mutex_t fl_mutex;  // Used for MT-safety
	int orientation:2;  // Orientation for fwide()
	int counted:1;  // Stream counted against STREAM_MAX
	int pad1:5;  // Padding
} sFILEX_t;


/** File datatype */
typedef struct attr_packed __sFILE {
	unsigned char* _p;  // Current position in buffer
	unsigned char* _up;
	int _r;  // Read space left for getc()
	int _w;  // Write space left for putc()
	unsigned int flags;  // This FILE is free if 0
	unsigned int flags2;
	int _file;  // fileno, if Unix descriptor, else -1
	int lbfsize;  // 0 or -_bf._size, for inline putc
	unsigned char *rpos, *rend, *wend, *wpos, *wbase, *shend;
	// Operations
	void* _cookie;  // Cookie passed to IO functions
	int (*close)(void*);
	size_t (*read)(void*, unsigned char*, const size_t);
	off_t (*seek)(void*, const off_t, const int);
	size_t (*write)(void*, const unsigned char*, const size_t);
	// Buffers
	struct __sbuf _ub;  // ungetc buffer
	struct __sbuf _bf;  // The buffer (at least 1 byte, if !NULL)
	struct __sbuf _lb;  // Buffer for fgetln()
	unsigned char* buf;
	size_t buf_size;
	unsigned char _ubuf[3];  // Guarantee an ungetc() buffer
	unsigned char _nbuf[1];  // Guarantee a getc() buffer
	// Locks
	volatile int lock, waiters;
	long lockcount;
	struct __sFILE *prev_locked, *next_locked;
	// Miscellaneous
	struct __sFILEX* _extra;  // Additions to FILE to not break ABI
	int _ur;  // Saved _r when _r is counting ungetc data
	int pipe_pid, fd;
	signed char mode, lbf;
	const locale_t locale;
	int blksize;  // stat.st_blksize (may be != _bf._size)
	fpos_t offset;  // Current lseek offset
	off_t shlim, shcnt;
} FILE;
#define __FILE   FILE
#define sFILE_t   FILE
#define FILE_t   FILE
#define file_t   FILE
#define _IO_FILE   FILE
#define IO_FILE   FILE
#define IO_FILE_T   FILE
#define io_file_t   FILE
#define FILE_DEFINED   (1)
#define __DEFINED_FILE   (1)
#define _GMP_H_HAVE_FILE   (1)
#define SIZEOF_FILE   (sizeof(FILE))
#define BITS_PER_FILE   (SIZEOF_FILE * 8)
#define SIZEOF_FILE_PTR   (sizeof(FILE*))


/** struct __sFILE_fake is the start of a struct __sFILE, with only the minimal fields allocated; In __sinit() we really allocate the 3 standard streams, etc., and point away from this fake */
typedef struct attr_packed __sFILE_fake {
	unsigned char* _p;  // Current position in (some) buffer
	int _r;  // Read space left for getc()
	int _w;  // Write space left for putc()
	short _flags;  // Flags, below; this FILE is free if 0
	short _file;  // Fileno, if Unix descriptor, else -1
	struct __sbuf _bf;  // The buffer (at least 1 byte, if !NULL)
	int lbfsize;  // 0 or -_bf._size, for inline putc
} __sFILE_fake_t;


/** Represents a lockfile on which we hold the lock */
typedef struct attr_packed lockfile_struct { char* filename; int fd; }   lockfile_t;


/** The first few FILEs are statically allocated; others are dynamically allocated and linked in via this glue structure */
typedef struct attr_packed glue {
	struct glue* next;
	int niobs;
	FILE* iobs;
} glue_t;
static UNUSED struct glue __sglue;
typedef struct glue_with_file { glue_t glue; FILE file; }   glue_with_file_t;


typedef struct arg_scanf {
	void* data;
	int (*getch)(void*);
	int (*putch)(int, void*);
} arg_scanf_t;


typedef struct attr_packed output {
	char* nextc;
	int nleft;
	char* buf;
	int bufsize;
	short fd, flags;
} output_t;


typedef struct attr_packed Qid {
	uvlong path;
	unsigned long vers;
	unsigned char type;
} Qid;
// Qid.type Bits
/** Type bit for directories */
#define QTDIR   0x80
/** Type bit for append only files */
#define QTAPPEND   0x40
/** Type bit for exclusive use files */
#define QTEXCL   0x20
/** Type bit for mounted channel */
#define QTMOUNT   0x10
/** Type bit for authentication file */
#define QTAUTH   8
/** Type bit for not-backed-up file */
#define QTTMP   4
/** Plain file */
#define QTFILE   0


/** System-modified data & file data */
typedef struct attr_packed Dir {
	unsigned short type;  // Server type
	unsigned int dev;  // Server subtype
	Qid qid;  // Unique id from server
	unsigned long mode;  // Permissions
	unsigned long atime;  // Last read time
	unsigned long mtime;  // Last write time
	vlong length;  // File length
	char* name;  // Last element of path
	char* uid;  // Owner name
	char* gid;  // Group name
	char* muid;  // Last modifier name
} Dir;
// Dir.mode Bits
/** Mode bit for directories */
#define DMDIR   0x80000000
/** Mode bit for append only files */
#define DMAPPEND   0x40000000
/** Mode bit for exclusive use files */
#define DMEXCL   0x20000000
/** Mode bit for mounted channel */
#define DMMOUNT   0x10000000
/** Mode bit for authentication file */
#define DMAUTH   0x8000000
/** Mode bit for non-backed-up files */
#define DMTMP   0x4000000
/** Mode bit for read permission */
#define DMREAD   4
/** Mode bit for write permission */
#define DMWRITE   2
/** Mode bit for execute permission */
#define DMEXEC   1


typedef struct IOchunk { void* addr; unsigned long len; }   IOchunk;
#define IOchunk_t   IOchunk


/** Codes returned by `parse_printf_format` for basic types; These values cover all the standard format specifications; Users can reserve new values after PA_LAST for their own types using 'register_printf_type' */
enum parse_printf_format_enum {
	PA_INT, PA_CHAR, PA_WCHAR, PA_STRING, PA_WSTRING,
	PA_POINTER, PA_FLOAT, PA_DOUBLE, PA_LAST
};


/** This is the structure from the libstdc++ codecvt class */
enum __codecvt_result {
	__codecvt_ok, __codecvt_partial, __codecvt_error, __codecvt_noconv
};


#ifndef _IO_MTSAFE_IO
/** Handle lock */
typedef void   _IO_lock_t;
#endif
#define _IO_CHAR_TYPE   char
#define _IO_char_t   char
#define IO_char_t   char
#define _IO_SHORT_TYPE   short
#define _IO_short_t   short
#define IO_short_t   short
#define _IO_INT_TYPE   int
#define _IO_int_t   int
#define IO_int_t   int
#define _IO_UINT_TYPE   uint
#define _IO_uint_t   uint
#define IO_uint_t   uint
#define IO_long_t   long
#define IO_long_long_t   long long
#define IO_float_t   float
#define IO_double_t   double
#define _IO_wchar_t   wchar_t
#define IO_wchar_t   wchar_t
#define _IO_wint_t   wint_t
#define IO_wint_t   wint_t
#define _IO_size_t   size_t
#define IO_size_t   size_t
#define _IO_ssize_t   ssize_t
#define IO_ssize_t   ssize_t
#define _IO_off_t   off_t
#define IO_off_t   off_t
#define _IO_off64_t    off64_t
#define IO_off64_t    off64_t
#define _IO_pid_t   pid_t
#define IO_pid_t   pid_t
#define _IO_uid_t   uid_t
#define IO_uid_t   uid_t
#define _IO_fpos_t   _G_fpos_t
#define IO_fpos_t   _G_fpos_t
#define _IO_fpos64_t   _G_fpos64_t
#define IO_fpos64_t   _G_fpos64_t


/** setvbuf should set fully buffered */
#define _IOFBF   (0)
/** setvbuf should set fully buffered */
#define __STDIO_IOFBF   (0)
/** setvbuf should set line buffered */
#define _IOLBF   (1)
/** setvbuf should set line buffered */
#define __STDIO_IOLBF   (1)
/** setvbuf should set unbuffered */
#define _IONBF   (2)
/** setvbuf should set unbuffered */
#define __STDIO_IONBF   (2)
/** Line buffered */
#define __SLBF   (1)
/** Unbuffered */
#define __SNBF   (2)
/** OK to read; RD and WR are never simultaneously asserted */
#define __SRD   (4)
/** OK to write; RD and WR are never simultaneously asserted */
#define __SWR   (8)
/** Open for reading & writing */
#define __SRW   (0x10)
/** Found EOF */
#define __SEOF   (0x20)
/** Found error */
#define __SERR   (0x40)
/** _buf is from malloc */
#define __SMBF   (0x80)
/** fdopen()ed in append mode */
#define __SAPP   (0x100)
/** This is a sprintf/snprintf string */
#define __SSTR   (0x200)
/** Do fseek() optimisation */
#define __SOPT   (0x400)
/** Do not do fseek() optimization */
#define __SNPT   (0x800)
/** Set if _offset is in fact correct */
#define __SOFF   (0x1000)
/** true => fgetln modified _p text */
#define __SMOD   (0x2000)
/** Allocate string space dynamically */
#define __SALC  (0x4000)
/** Ignore this file in _fwalk */
#define __SIGN   (0x8000)
#ifndef BUFSIZ
#   if (!(defined(WANT_SMALL_STDIO_BUFS) || defined(SMALL_STDIO_BUFS)))
/** Size of buffer used by setbuf */
#      define BUFSIZE   128
/** Size of buffer used by setbuf */
#      define BUFSIZ   128
#   elif (!(defined(WANT_LARGE_STDIO_BUFS) || defined(LARGE_STDIO_BUFS)))
/** Size of buffer used by setbuf */
#      define BUFSIZE   2048
/** Size of buffer used by setbuf */
#      define BUFSIZ   2048
#   else
/** Size of buffer used by setbuf */
#      define BUFSIZE   1024
/** Size of buffer used by setbuf */
#      define BUFSIZ   1024
#   endif
#endif  // BUFSIZ
#ifndef __STDIO_BUFSIZ
/** Default buffer size */
#   define __STDIO_BUFSIZ   BUFSIZ
#endif
#ifndef UNGET
#   define UNGET   (8)
#endif


// IMPORTANT FUNCTION DECLARATIONS

#ifndef DISABLE_FUNC_DECL
DECL_FUNC void* alloca(const size_t size);
DECL_FUNC int asprintf(char** s, const char* fmt, ...);
DECL_FUNC float atanf(const float num);
DECL_FUNC double atan(const double num);
DECL_FUNC int atoi(const char* restrict s);
DECL_FUNC long atol(const char* restrict s);
DECL_FUNC long long atoll(const char* restrict s);
DECL_FUNC short atos(const char* restrict s);
DECL_FUNC void* calloc(const size_t num_members, const size_t elem_size);
DECL_FUNC clock_t clock(void);
DECL_FUNC int clock_gettime(const clockid_t clk, struct timespec* ts);
DECL_FUNC uint32_t cmpxchg(int* ptr, const int _old, const int _new);
DECL_FUNC int copystring(char* buf, const int maxlen, const char* s);
DECL_FUNC float cosf(const float x);
DECL_FUNC double cos(const double x);
DECL_FUNC int count_leading_zeros(const unsigned long x);
DECL_FUNC int __dtostr(double d, char* buf, unsigned int maxlen, unsigned int prec, unsigned int prec2, int g);
DECL_FUNC void do_tzset(void);
DECL_FUNC noreturn void _Exit(const int code);
DECL_FUNC double exp(const double num);
DECL_FUNC float expf(const float num);
DECL_FUNC int fclose(FILE* f);
DECL_FUNC int ferror(FILE* fp);
DECL_FUNC int fflush(FILE* f);
DECL_FUNC char* fgets(char* as, int n, FILE* f);
DECL_FUNC int fprintf(FILE* restrict f, const char* restrict fmt, ...);
DECL_FUNC long double __floatscan(FILE* f, int prec, int pok);
DECL_FUNC void flockfile(FILE* f);
DECL_FUNC int fmodeflags(const char* mode);
DECL_FUNC FILE* fopen(const char* restrict filename, const char* restrict mode);
DECL_FUNC wint_t fputwc(wchar_t wc, FILE* stream);
DECL_FUNC void free(void* ptr);
DECL_FUNC double frexp(const double num, int* e);
DECL_FUNC float frexpf(const float num, int* e);
DECL_FUNC int fseeko_unlocked(FILE* f, off_t off, const int whence);
DECL_FUNC off_t ftello(FILE* f);
DECL_FUNC int ftrylockfile(FILE* f);
DECL_FUNC void funlockfile(FILE* f);
DECL_FUNC int _fwalk(int (*function)(FILE*));
DECL_FUNC const char* getenv(const char* restrict name);
DECL_FUNC pid_t getpid(void);
DECL_FUNC int gettimeofday(struct timeval* restrict tv, UNUSED void* restrict tz);
DECL_FUNC uid_t getuid(void);
DECL_FUNC struct tm* gmtime_r(const time_t* restrict t, struct tm* restrict _tm);
DECL_FUNC hp_timing_t HP_TIMING(void);
DECL_FUNC double __ieee754_sqrt(const double x);
DECL_FUNC float __ieee754_sqrtf(const float x);
DECL_FUNC unsigned long long intscan(FILE* f, unsigned base, const int pok, const unsigned long long lim);
DECL_FUNC int isfinite(const double x);
DECL_FUNC int isfinitef(const float x);
DECL_FUNC int __isinf(const double x);
DECL_FUNC int __isnan(const double x);
DECL_FUNC int lflush(FILE* _fp);
DECL_FUNC int __lltostr(char* s, int size, unsigned long long i, int base, const char UpCase);
DECL_FUNC int __ltostr(char* s, unsigned int size, unsigned long i, unsigned int base, const int UpCase);
DECL_FUNC void __lock(volatile int* l);
DECL_FUNC int __lockfile(FILE* f);
DECL_FUNC int mbtowc(wchar_t* restrict pwc, const char* s, const size_t n);
DECL_FUNC void* malloc(const size_t len);
DECL_FUNC size_t mbrtowc(wchar_t* restrict pwc, const char* s, const size_t len, UNUSED mbstate_t* ps);
DECL_FUNC int mbsinit(const mbstate_t* restrict st);
DECL_FUNC const void* memchr(const void* src, const int x, const size_t len);
DECL_FUNC void* memchr_nonconst(void* src, const int x, const size_t len);
DECL_FUNC int memcmp(const void* restrict ptr1, const void* restrict ptr2, const size_t _num);
DECL_FUNC void* memcpy(void* restrict dest, const void* restrict src, const size_t n);
DECL_FUNC void memcpy_no_output(void* restrict dest, const void* restrict src, const size_t n);
DECL_FUNC NONNULL void* memmove(void* dst, const void* src, const size_t len);
DECL_FUNC void* mempcpy(void* restrict dest, const void* restrict src, const size_t len);
DECL_FUNC void* memset(void* restrict dst, const int c, const size_t len);
DECL_FUNC void memset_no_output(void* restrict dst, const int c, const size_t len);
DECL_FUNC void* mmap(void* start, size_t len, int prot, int flags, int fd, off_t off);
DECL_FUNC int munmap(void* start, const size_t len);
DECL_FUNC int munmap_const(const void* start, const size_t len);
DECL_FUNC int nanosleep(const struct timespec* req, struct timespec* rem);
DECL_FUNC int open(const char* filename, const int flags, ...);
DECL_FUNC void procfdname(char* buf, unsigned int fd);
DECL_FUNC struct pthread* __pthread_self(void);
DECL_FUNC int putc(int c, FILE* f);
DECL_FUNC FILE** __ofl_lock(void);
DECL_FUNC void __ofl_unlock(void);
DECL_FUNC FILE* __ofl_add(FILE* f);
DECL_FUNC int pipe2(int fd[2], int flag);
DECL_FUNC int pthread_setcancelstate(const int new, int* old);
DECL_FUNC int pthread_sigmask(const int how, const sigset_t* restrict set, sigset_t* restrict old);
DECL_FUNC char* randname(char* template);
DECL_FUNC void* realloc(void* ptr, const size_t len);
DECL_FUNC void* reallocarray(void* optr, const size_t nmemb, const size_t size);
DECL_FUNC size_t scan_trans(long long t, int local, size_t* alt);
DECL_FUNC void setlinebuf(FILE* f);
DECL_FUNC int __sflush(FILE* fp);
DECL_FUNC int __sfvwrite(FILE* fp, struct __suio* uio);
DECL_FUNC int __sigaction(int sig, const struct sigaction* act, struct sigaction* oact);
DECL_FUNC int signbitf(const float x);
DECL_FUNC int signbit(const double x);
DECL_FUNC float sinf(const float x);
DECL_FUNC double sin(const double x);
DECL_FUNC int snprintf(char* s, const size_t maxlen, const char* format, ...);
DECL_FUNC fpos_t __sseek(void* _cookie, const fpos_t offset, const int whence);
DECL_FUNC int __stdio_close(FILE* f);
DECL_FUNC int __stdio_close_helper(void* f);
DECL_FUNC off_t __stdio_seek(FILE* f, const off_t off, const int whence);
DECL_FUNC off_t __stdio_seek_helper(void* f, const off_t off, const int whence);
DECL_FUNC size_t __stdio_read(FILE* f, unsigned char* buf, const size_t len);
DECL_FUNC size_t __stdio_read_helper(void* f, unsigned char* buf, const size_t len);
DECL_FUNC size_t __stdio_write(FILE* f, const unsigned char* buf, const size_t len);
DECL_FUNC size_t __stdio_write_helper(void* f, const unsigned char* buf, const size_t len);
DECL_FUNC size_t __stdout_write(FILE* f, const unsigned char* buf, const size_t len);
DECL_FUNC size_t __stdout_write_helper(void* f, const unsigned char* buf, const size_t len);
DECL_FUNC int strcasecmp(const char* s1, const char* s2);
DECL_FUNC const char* strchr(const char* restrict str, const int chr);
DECL_FUNC char* strchr_nc(char* restrict str, const int chr);
DECL_FUNC int strcmp(const char* restrict s1, const char* restrict s2);
DECL_FUNC char* strcpy(char* restrict dest, const char* restrict src);
DECL_FUNC size_t strcspn(const char* restrict str, const char* restrict reject);
DECL_FUNC char* strdup(const char* s);
DECL_FUNC size_t strftime(char* restrict s, size_t n, const char* restrict f, const struct tm* restrict _tm);
DECL_FUNC const char* strftime_fmt_1(char (*s)[100], size_t* l, int f, const struct tm* _tm, locale_t loc);
DECL_FUNC NONNULL CONST_FUNC size_t strlen(const char* restrict str);
DECL_FUNC int NONNULL strncmp(const char* s1, const char* s2, const size_t len);
DECL_FUNC void strncpy_no_output(char* restrict dest, const char* restrict src, const size_t len);
DECL_FUNC NONNULL CONST_FUNC size_t strnlen(const char* restrict s, const size_t maxlen);
DECL_FUNC const char* strrchr(const char* restrict str, const int chr);
DECL_FUNC size_t strspn(const char* restrict s1, const char* restrict s2);
DECL_FUNC const char* strstr(const char* restrict s1, const char* restrict s2);
DECL_FUNC long strtol(const char* restrict nptr, const char** restrict endptr, const int _base);
DECL_FUNC unsigned long strtoul(const char* restrict nptr, const char** restrict endptr, const int _base);
DECL_FUNC time_t time(time_t* t);
DECL_FUNC int __toread(FILE* f);
DECL_FUNC void tzset(void);
DECL_FUNC int __uflow(FILE* f);
DECL_FUNC char* uintmaxtostr(const signed long _num, char b[]);
DECL_FUNC void __unlist_locked_file(FILE* f);
DECL_FUNC void __unlock(volatile int* l);
DECL_FUNC void __unlockfile(FILE* f);
DECL_FUNC int uname(struct utsname* uts);
DECL_FUNC int vfprintf(FILE* stream, const char* format, va_list arg_ptr);
DECL_FUNC int vsnprintf(char* restrict str, const size_t size, const char* restrict format, va_list args);
DECL_FUNC pid_t waitpid(pid_t pid, int* status, int options);
DECL_FUNC size_t wcrtomb(char* restrict s, wchar_t wc, UNUSED mbstate_t* restrict st);
DECL_FUNC long long wcstoll(wchar_t* restrict s, const wchar_t** restrict p, const int base);
DECL_FUNC unsigned long long wcstoull(wchar_t* restrict s, const wchar_t** restrict p, const int base);
DECL_FUNC unsigned long long wcstox(wchar_t* s, const wchar_t** p, const int base, const unsigned long long lim);
DECL_FUNC int wctomb(char* s, wchar_t wchar);
DECL_FUNC uint32_t zi_read32(const unsigned char* z);
#if SUPPORTS_LONG_DOUBLE
DECL_FUNC long double frexpl(const long double x, int* e);
DECL_FUNC int isfinitel(const long double x);
DECL_FUNC int signbitl(const long double x);
#endif
#endif  // DISABLE_FUNC_DECL
#define FFINALLOCK(f)   (((f)->lock >= 0) ? __lockfile((f)) : 0)
#define FLOCK(f)   int __need_unlock = ((f)->lock >= 0 ? __lockfile((f)) : 0)
#define FUNLOCK(f)   if (__need_unlock) { __unlockfile((f)); }


// STDIN, STDOUT, & STDERR

static UNUSED unsigned char stdbuf[BUFSIZ + UNGET];
static FILE __stdin = {
	.buf = stdbuf + UNGET,
	.buf_size = sizeof(stdbuf) - UNGET,
	.fd = 0,
	.flags = (unsigned int)(F_PERM | F_NOWR),
	.read = &__stdio_read_helper,
	.seek = &__stdio_seek_helper,
	.close = &__stdio_close_helper,
	// ._bf = { (stdbuf + UNGET), (sizeof(stdbuf) - UNGET) },
	.lock = -1,
	.waiters = -1,
	.lockcount = -1
};
/** Standard input pointer */
UNUSED FILE* __stdinp = &__stdin;
#define stdinp   __stdinp
#define STDIN   __stdinp
#define stdin   __stdinp
#define __stdin_used   __stdinp
static FILE __stdout = {
	.buf = stdbuf + UNGET,
	.buf_size = sizeof(stdbuf) - UNGET,
	.fd = 1,
	.flags = (unsigned int)(F_PERM | F_NORD),
	.lbf = '\n',
	.write = &__stdout_write_helper,
	.seek = &__stdio_seek_helper,
	.close = &__stdio_close_helper,
	// ._bf = { (stdbuf + UNGET), (sizeof(stdbuf) - UNGET) },
	.lock = -1,
	.waiters = -1,
	.lockcount = -1
};
/** Standard output pointer */
UNUSED FILE* __stdoutp = &__stdout;
#define stdoutp   __stdoutp
#define STDOUT   __stdoutp
#define stdout   __stdoutp
#define __stdout_used   __stdoutp
static FILE __stderr = {
	.buf = stdbuf + UNGET,
	.buf_size = 0,
	.fd = 2,
	.flags = (unsigned int)(F_PERM | F_NORD),
	.lbf = -1,
	.write = &__stdio_write_helper,
	.seek = &__stdio_seek_helper,
	.close = &__stdio_close_helper,
	// ._bf = { (stdbuf + UNGET), (sizeof(stdbuf) - UNGET) },
	.lock = -1,
	.waiters = -1,
	.lockcount = -1
};
/** Standard error pointer */
UNUSED FILE* __stderrp = &__stderr;
#define stderrp   __stderrp
#define STDERR   __stderrp
#define stderr   __stderrp
#define __stderr_used   __stderrp


// GEOMETRY DATATYPES

/** Coordinates of a point (double) */
typedef struct point { double x, y; }   point_t;
/** Coordinates of a point (float) */
typedef struct pointf { float x, y; }   pointf_t;
#ifdef FLOAT128_SUPPORTED
/** Coordinates of a point (float128) */
typedef struct point_float128 { float128 x, y; }   point_float128_t;
#endif
/** Coordinates of a point (long double) */
typedef struct pointl { long double x, y; }   pointl_t;
/** Coordinates of a point (signed long int) */
typedef struct point_int { signed long int x, y; }   point_int_t;
/** Two points of a line (double) */
typedef struct line { point_t x, y; }   line_t;
/** Two points of a line (float) */
typedef struct linef { pointf_t x, y; }   linef_t;
/** Two points of a line (long double) */
typedef struct linel { pointl_t x, y; }   linel_t;
/** Two points of a line (signed long int) */
typedef struct line_int { point_int_t x, y; }   line_int_t;
// 2D SHAPES
/** Semicircle, given the radius (double) */
typedef struct semicircle { double radius; }   semicircle_t;
/** Semicircle, given the radius (long double) */
typedef struct semicirclel { long double radius; }   semicirclel_t;
/** Semicircle, given the radius (float) */
typedef struct semicirclef { float radius; }   semicirclef_t;
/** Circle, given the radius (double) */
typedef struct circle { double radius; }   circle_t;
/** Circle, given the radius (long double) */
typedef struct circlel { long double radius; }   circlel_t;
/** Circle, given the radius (float) */
typedef struct circlef { float radius; }   circlef_t;
/** Ellipse, given the major-radius and minor-radius (double) */
typedef struct ellipse { double majorradius, minorradius; }   ellipse_t;
/** Ellipse, given the major-radius and minor-radius (long double) */
typedef struct ellipsel { long double majorradius, minorradius; }   ellipsel_t;
/** Ellipse, given the major-radius and minor-radius (float) */
typedef struct ellipsef { float majorradius, minorradius; }   ellipsef_t;
/** Hexagon, given the width and a side-length (double) */
typedef struct hexagon { double width, sidelength; }   hexagon_t;
/** Hexagon, given the width and a side-length (long double) */
typedef struct hexagonl { long double width, sidelength; }   hexagonl_t;
/** Hexagon, given the width and a side-length (float) */
typedef struct hexagonf { float width, sidelength; }   hexagonf_t;
/** Rectangle, given the height and width (double) */
typedef struct rectangle { double height, width; }   rectangle_t;
/** Rectangle, given the height and width (long double) */
typedef struct rectanglel { long double height, width; }   rectanglel_t;
/** Rectangle, given the height and width (float) */
typedef struct rectanglef { float height, width; }   rectanglef_t;
/** Square, given the length (double) */
typedef struct square { double length; }   square_t;
/** Square, given the length (long double) */
typedef struct squarel { long double length; }   squarel_t;
/** Square, given the length (float) */
typedef struct squaref { float length; }   squaref_t;
/** Triangle, given the base and height (double) */
typedef struct triangle { double base, height; }   triangle_t;
/** Triangle, given the base and height (long double) */
typedef struct trianglel { long double base, height; }   trianglel_t;
/** Triangle, given the base and height (float) */
typedef struct trianglef { float base, height; }   trianglef_t;
// 3D SHAPES
/** Sphere, given the radius (double) */
typedef struct sphere { double radius; }   sphere_t;
/** Sphere, given the radius (long double) */
typedef struct spherel { long double radius; }   spherel_t;
/** Sphere, given the radius (float) */
typedef struct spheref { float radius; }   spheref_t;
#ifdef FLOAT128_SUPPORTED
/** Sphere, given the radius (float128) */
typedef struct sphere_float128 { float128 radius; }   sphere_float128_t;
#endif
/** Cube, given the length (double) */
typedef struct cube { double length; }   cube_t;
/** Cube, given the length (long double) */
typedef struct cubel { long double length; }   cubel_t;
/** Cube, given the length (float) */
typedef struct cubef { float length; }   cubef_t;
#ifdef FLOAT128_SUPPORTED
/** Cube, given the length (float128) */
typedef struct cube_float128 { float128 length; }   cube_float128_t;
#endif
/** Ellipsoid, given radius1, radius2, and radius3 (double) */
typedef struct ellipsoid { double radius1, radius2, radius3; }   ellipsoid_t;
/** Ellipsoid, given radius1, radius2, and radius3 (long double) */
typedef struct ellipsoidl { long double radius1, radius2, radius3; }   ellipsoidl_t;
/** Ellipsoid, given radius1, radius2, and radius3 (float) */
typedef struct ellipsoidf { float radius1, radius2, radius3; }   ellipsoidf_t;
#ifdef FLOAT128_SUPPORTED
/** Ellipsoid, given radius1, radius2, and radius3 (float128) */
typedef struct ellipsoid_float128 { float128 radius1, radius2, radius3; }   ellipsoid_float128_t;
#endif
/** Prism, given the depth, height, and width (double) */
typedef struct prism { double depth, height, width; }   prism_t;
/** Prism, given the depth, height, and width (long double) */
typedef struct prisml { long double depth, height, width; }   prisml_t;
/** Prism, given the depth, height, and width (float) */
typedef struct prismf { float depth, height, width; }   prismf_t;
#ifdef FLOAT128_SUPPORTED
/** Prism, given the depth, height, and width (float128) */
typedef struct prism_float128 { float128 depth, height, width; }   prism_float128_t;
#endif


// MISCELLANEOUS MACROS FUNCTIONS & DATATYPES

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
/** Type of ARG for TIOCGETC and TIOCSETC requests */
typedef struct tchars {
	char t_intrc;  // Interrupt character
	char t_quitc;  // Quit character
	char t_startc;  // Start-output character
	char t_stopc;  // Stop-output character
	char t_eofc;  // End-of-file character
	char t_brkc;  // Input delimiter character
} tchars_t;
/** Type of ARG for TIOCGLTC and TIOCSLTC requests */
typedef struct ltchars {
	char t_suspc;  // Suspend character
	char t_dsuspc;  // Delayed suspend character
	char t_rprntc;  // Reprint-line character
	char t_flushc;  // Flush-output character
	char t_werasc;  // Word-erase character
	char t_lnextc;  // Literal-next character
} ltchars_t;
/** Type of ARG for TIOCGETP, TIOCSETP, gtty, and stty requests */
typedef struct sgttyb {
	char sg_ispeed;  // Input speed
	char sg_ospeed;  // Output speed
	char sg_erase;  // Erase character
	char sg_kill;  // Kill character
	short sg_flags;  // Mode flags
} sgttyb_t;
/** Type of ARG for TIOCGWINSZ and TIOCSWINSZ requests */
typedef struct winsize {
	unsigned short ws_row;  // Rows, in characters
	unsigned short ws_col;  // Columns, in characters
	unsigned short ws_xpixel;  // Horizontal pixels
	unsigned short ws_ypixel;  // Vertical pixels
} winsize_t;
typedef struct ttysize { unsigned short ts_lines, ts_cols, ts_xxx, ts_yyy; }   ttysize_t;
#ifndef __DECONST
#   define __DECONST(type, var)   ((type)(uintptr_t)(const void*)(var))
#endif
#ifndef __DEVOLATILE
#   define __DEVOLATILE(type, var)   ((type)(uintptr_t)(volatile void*)(var))
#endif
#ifndef __DEQUALIFY
#   define __DEQUALIFY(type, var)   ((type)(uintptr_t)(const volatile void*)(var))
#endif
/** 1 if 'type' is a pointer type, 0 otherwise */
#define __pointer_type(type)   (__builtin_classify_type((type)0) == 5)
/** 1 if 'type' is a pointer type, 0 otherwise */
#define pointer_type(type)   (__builtin_classify_type((type)0) == 5)
/** intptr_t if P is true, or T if P is false */
#define integer_if_pointer_type_sub(T, P)   typeof(*(0 ? (typeof(0 ? (T*)0 : (void*)(P)))0 : (typeof(0 ? (intptr_t*)0 : (void*)(!(P))))0))
/** __intptr_t if P is true, or T if P is false */
#define __integer_if_pointer_type_sub(T, P)   integer_if_pointer_type_sub((T), (P))
/** intptr_t if EXPR has a pointer type, or the type of EXPR otherwise */
#define integer_if_pointer_type(expr)   __integer_if_pointer_type_sub(typeof((typeof(expr))0), __pointer_type(typeof(expr)))
/** intptr_t if EXPR has a pointer type, or the type of EXPR otherwise */
#define __integer_if_pointer_type(expr)   integer_if_pointer_type((expr))
/** Cast an integer or a pointer VAL to integer with proper type */
#define cast_to_integer(val)   ((__integer_if_pointer_type(val))(val))
/** fd_set for select and pselect */
typedef struct fd_set_struct {
#ifdef __USE_XOPEN
	__fd_mask fds_bits[FD_SETSIZE / BITS_PER_LONG];  // XPG4.2 requires this member name
#else
	__fd_mask __fds_bits[FD_SETSIZE / BITS_PER_LONG];
#endif
} fd_set;
/** fd_set for select and pselect */
typedef struct darwin_fd_set {
	int32_t fds_bits[__DARWIN_howmany(__DARWIN_FD_SETSIZE, BITS_PER_LONG)];
} darwin_fd_set;
typedef struct __kernel_fd_set { unsigned long fds_bits[FD_SETSIZE / BITS_PER_LONG]; }   __kernel_fd_set;
#define KFDS_64BLOCK   (((PAGE_SIZE) / 384) * 64)
#define KFDS_NR   (((KFDS_64BLOCK * 8) > NR_OPEN) ? NR_OPEN : (KFDS_64BLOCK * 8))
typedef unsigned long   kernel_fd_set[KFDS_NR / __NFDBITS];
typedef void   (*__kernel_sighandler_t)(int);
typedef int   kernel_key_t;
#define __kernel_key_t   kernel_key_t
typedef int   kernel_mqd_t;
#define __kernel_mqd_t   kernel_mqd_t
#ifdef _KERNEL  // Convert from open() flags to/from fflags; convert O_RD/WR to FREAD/FWRITE
#   define FFLAGS(oflags)   ((oflags) + 1)
#   define OFLAGS(fflags)   ((fflags) - 1)
/** Mark during gc() */
#   define FMARK   0x1000
/** Defer for next gc pass */
#   define FDEFER   0x2000
/** Descriptor holds advisory lock */
#   define FHASLOCK   0x4000
/** Scan during gc passes */
#   define FSCAN   0x100000
/** Suppress kernel error messages */
#   define FSILENT   0x40000000
/** Kernel originated ioctl */
#   define FKIOCTL   0x80000000
/** Bits settable by fcntl(F_SETFL, ...) */
#   define FCNTLFLAGS   (FAPPEND | FASYNC | FFSYNC | FNONBLOCK | FDSYNC | FRSYNC | FALTIO | FDIRECT | FNOSIGPIPE)
/** Bits to save after open(2) */
#   define FMASK   (FREAD | FWRITE | FCNTLFLAGS)
#endif
#define HONORED_STATE_MODES   (O_APPEND | O_ASYNC | O_FSYNC | O_NONBLOCK | O_NOATIME)
typedef enum BEOS_TYPE_CONSTANTS {
	B_AFFINE_TRANSFORM_TYPE = 0x414D5458,  // "AMTX"
	B_ALIGNMENT_TYPE = 0x414C474E,  // "ALGN"
	B_ANY_TYPE = 0x414E5954,  // "ANYT"
	B_ATOM_TYPE = 0x41544F4D,  // "ATOM"
	B_ATOMREF_TYPE = 0x41544D52,  // "ATMR"
	B_BOOL_TYPE = 0x424F4F4C,  // "BOOL"
	B_CHAR_TYPE = 0x43484152,  // "CHAR"
	B_COLOR_8_BIT_TYPE = 0x434C5242,  // "CLRB"
	B_DOUBLE_TYPE = 0x44424C45,  // "DBLE"
	B_FLOAT_TYPE = 0x464C4F54,  // "FLOT"
	B_GRAYSCALE_8_BIT_TYPE = 0x47525942,  // "GRYB"
	B_INT16_TYPE = 0x53485254,  // "SHRT"
	B_INT32_TYPE = 0x4C4F4E47,  // "LONG"
	B_INT64_TYPE = 0x4C4C4E47,  // "LLNG"
	B_INT8_TYPE = 0x42595445,  // "BYTE"
	B_LARGE_ICON_TYPE = 0x49434F4E,  // "ICON"
	B_MEDIA_PARAMETER_GROUP_TYPE = 0x424D4347,  // "BMCG"
	B_MEDIA_PARAMETER_TYPE = 0x424D4354,  // "BMCT"
	B_MEDIA_PARAMETER_WEB_TYPE = 0x424D4357,  // "BMCW"
	B_MESSAGE_TYPE = 0x4D534747,  // "MSGG"
	B_MESSENGER_TYPE = 0x4D534E47,  // "MSNG"
	B_MIME_TYPE = 0x4D494D45,  // "MIME"
	B_MINI_ICON_TYPE = 0x4D49434E,  // "MICN"
	B_MONOCHROME_1_BIT_TYPE = 0x4D4E4F42,  // "MNOB"
	B_OBJECT_TYPE = 0x4F505452,  // "OPTR"
	B_OFF_T_TYPE = 0x4F464654,  // "OFFT"
	B_PATTERN_TYPE = 0x5041544E,  // "PATN"
	B_POINTER_TYPE = 0x504E5452,  // "PNTR"
	B_POINT_TYPE = 0x42504E54,  // "BPNT"
	B_PROPERTY_INFO_TYPE = 0x53435444,  // "SCTD"
	B_RAW_TYPE = 0x52415754,  // "RAWT"
	B_RECT_TYPE = 0x52454354,  // "RECT"
	B_REF_TYPE = 0x52524546,  // "RREF"
	B_RGB_32_BIT_TYPE = 0x52474242,  // "RGBB"
	B_RGB_COLOR_TYPE = 0x52474243,  // "RGBC"
	B_SIZE_TYPE = 0x53495A45,  // "SIZE"
	B_SIZE_T_TYPE = 0x53495A54,  // "SIZT"
	B_SSIZE_T_TYPE = 0x53535A54,  // "SSZT"
	B_STRING_TYPE = 0x43535452,  // "CSTR"
	B_STRING_LIST_TYPE = 0x5354524C,  // "STRL"
	B_TIME_TYPE = 0x54494D45,  // "TIME"
	B_UINT16_TYPE = 0x55534854,  // "USHT"
	B_UINT32_TYPE = 0x554C4E47,  // "ULNG"
	B_UINT64_TYPE = 0x554C4C47,  // "ULLG"
	B_UINT8_TYPE = 0x55425954,  // "UBYT"
	B_VECTOR_ICON_TYPE = 0x5649434E,  // "VICN"
	B_XATTR_TYPE = 0x58415452,  // "XATR"
	B_NETWORK_ADDRESS_TYPE = 0x4E574144,  // "NWAD"
	B_MIME_STRING_TYPE = 0x4D494D53,  // "MIMS"
	B_ASCII_TYPE = 0x54455854  // "TEXT"
} beos_type_constants_t;
typedef struct libc {
	int can_do_threads, threaded, secure;
	volatile int threads_minus_1;
	size_t* auxv;
	struct tls_module* tls_head;
	size_t tls_size, tls_align, tls_cnt, page_size;
	locale_t global_locale;
} libc_t;
static UNUSED struct libc libc = { 1, 1, 1, 0, NULL, NULL, 0, 0, 0, 0, NULL };
#define _libc   libc
#define __libc   libc
#define _PDCLIB_global_locale   libc.global_locale
#define _libc_global_locale   libc.global_locale


// MISCELLANEOUS LINUX DATATYPES

#if (!(defined(LINUX_BRIDGE_EBT_PKTTYPE_H) || defined(LINUX_BRIDGE_EBT_PKTTYPE_H_) || defined(__LINUX_BRIDGE_EBT_PKTTYPE_H) || defined(__LINUX_BRIDGE_EBT_PKTTYPE_H_)))
#define LINUX_BRIDGE_EBT_PKTTYPE_H   (1)
#define LINUX_BRIDGE_EBT_PKTTYPE_H_   (1)
#define __LINUX_BRIDGE_EBT_PKTTYPE_H   (1)
#define __LINUX_BRIDGE_EBT_PKTTYPE_H_   (1)


typedef struct ebt_pkttype_info { uint8_t pkt_type, invert; }   ebt_pkttype_info_t;
#define EBT_PKTTYPE_MATCH   "pkttype"


#endif  // LINUX_BRIDGE_EBT_PKTTYPE_H


#if (!(defined(XT_PKTTYPE_H) || defined(XT_PKTTYPE_H_) || defined(_XT_PKTTYPE_H) || defined(_XT_PKTTYPE_H_)))
#define XT_PKTTYPE_H   (1)
#define XT_PKTTYPE_H_   (1)
#define _XT_PKTTYPE_H   (1)
#define _XT_PKTTYPE_H_   (1)


typedef struct xt_pkttype_info { int pkttype, invert; }   xt_pkttype_info_t;


#endif  // XT_PKTTYPE_H


#if (!(defined(XT_ADDRTYPE_H) || defined(XT_ADDRTYPE_H_) || defined(_XT_ADDRTYPE_H) || defined(_XT_ADDRTYPE_H_)))
#define XT_ADDRTYPE_H   (1)
#define XT_ADDRTYPE_H_   (1)
#define _XT_ADDRTYPE_H   (1)
#define _XT_ADDRTYPE_H_   (1)


#define XT_ADDRTYPE_INVERT_SOURCE   1
#define XT_ADDRTYPE_INVERT_DEST   2
#define XT_ADDRTYPE_LIMIT_IFACE_IN   4
#define XT_ADDRTYPE_LIMIT_IFACE_OUT   8
#define XT_ADDRTYPE_UNSPEC   1
#define XT_ADDRTYPE_UNICAST   2
#define XT_ADDRTYPE_LOCAL    4
#define XT_ADDRTYPE_BROADCAST   8
#define XT_ADDRTYPE_ANYCAST   16
#define XT_ADDRTYPE_MULTICAST   32
#define XT_ADDRTYPE_BLACKHOLE   64
#define XT_ADDRTYPE_UNREACHABLE   128
#define XT_ADDRTYPE_PROHIBIT   256
#define XT_ADDRTYPE_THROW   512
#define XT_ADDRTYPE_NAT   1024
#define XT_ADDRTYPE_XRESOLVE   2048


typedef struct xt_addrtype_info_v1 {
	uint16_t source, dest;
	uint32_t flags;
} xt_addrtype_info_v1_t;


typedef struct xt_addrtype_info {
	uint16_t source, dest;
	uint32_t invert_source, invert_dest;
} xt_addrtype_info_t;


#endif  // XT_ADDRTYPE_H


#endif  // DATATYPES


/* FIXED-POINT DATATYPES, MACROS, & FUNCTIONS; ISO/IEC TR18037 (<stdfix.h> & <fixed.h>) */


#if (defined(__GNUC__) && SUPPORTS_STDFIX && (!(defined(_STDFIX_H) || defined(_STDFIX_H_) || defined(_FIXED_BIT_H))))  // http://www.qnx.com/developers/docs/660/topic/com.qnx.doc.dinkum/topic/cpp11/stdfix.html & http://www.qnx.com/developers/docs/660/topic/com.qnx.doc.dinkum/topic/cpp11/fixed.html
#define _STDFIX_H   (1)
#define _STDFIX_H_   (1)
#define _FIXED_BIT_H   (1)  // TODO: Fix & finish stdfix.h header


#ifdef HINT_C_TYPE
#   if IS_BIG_ENDIAN
typedef struct INTstruct { HINT_C_TYPE high, low; }   INTstruct_t;
#   else
typedef struct INTstruct { HINT_C_TYPE low, high; }   INTstruct_t;
#   endif
typedef union INTunion { struct INTstruct s; INT_C_TYPE ll; }   INTunion;
#endif
#define FIXED_WIDTH   (FIXED_SIZE * BITS_PER_UNIT)
#define FIXED_C_TYPE1(NAME)   NAME ## type
#define FIXED_C_TYPE2(NAME)   FIXED_C_TYPE1(NAME)
#define FIXED_C_TYPE   FIXED_C_TYPE2(MODE_NAME)
#define FBITS1(NAME)   __ ## NAME ## _FBIT__
#define FBITS2(NAME)   FBITS1(NAME)
#define FBITS   FBITS2(MODE_NAME)
#define IBITS1(NAME)   __ ## NAME ## _IBIT__
#define IBITS2(NAME)   IBITS1(NAME)
#define IBITS   IBITS2(MODE_NAME)
#define I_F_BITS   (FBITS + IBITS)
#ifdef LIBGCC2_FIXEDBIT_GNU_PREFIX
#   define FIXED_OP(OP, MODE, NUM)   __gnu_ ## OP ## MODE ## NUM
#else
#   define FIXED_OP(OP, MODE, NUM)   __ ## OP ## MODE ## NUM
#endif
#define FIXED_SATURATE1_TEMP(NAME)   FIXED_OP(saturate1, NAME, )
#define FIXED_SATURATE2_TEMP(NAME)   FIXED_OP(saturate2, NAME, )
#define FIXED_MULHELPER_TEMP(NAME)   FIXED_OP(mulhelper, NAME, )
#define FIXED_DIVHELPER_TEMP(NAME)   FIXED_OP(divhelper, NAME, )
#define FIXED_ASHLHELPER_TEMP(NAME)   FIXED_OP(ashlhelper, NAME, )
#define FIXED_ADD_TEMP(NAME)   FIXED_OP(add, NAME, 3)
#define FIXED_SSADD_TEMP(NAME)   FIXED_OP(ssadd, NAME, 3)
#define FIXED_USADD_TEMP(NAME)   FIXED_OP(usadd, NAME, 3)
#define FIXED_SUB_TEMP(NAME)   FIXED_OP(sub, NAME, 3)
#define FIXED_SSSUB_TEMP(NAME)   FIXED_OP(sssub, NAME, 3)
#define FIXED_USSUB_TEMP(NAME)   FIXED_OP(ussub, NAME, 3)
#define FIXED_MUL_TEMP(NAME)   FIXED_OP(mul, NAME, 3)
#define FIXED_SSMUL_TEMP(NAME)   FIXED_OP(ssmul, NAME, 3)
#define FIXED_USMUL_TEMP(NAME)   FIXED_OP(usmul, NAME, 3)
#define FIXED_DIV_TEMP(NAME)   FIXED_OP(div, NAME, 3)
#define FIXED_UDIV_TEMP(NAME)   FIXED_OP(udiv, NAME, 3)
#define FIXED_SSDIV_TEMP(NAME)   FIXED_OP(ssdiv, NAME, 3)
#define FIXED_USDIV_TEMP(NAME)   FIXED_OP(usdiv, NAME, 3)
#define FIXED_NEG_TEMP(NAME)   FIXED_OP(neg, NAME, 2)
#define FIXED_SSNEG_TEMP(NAME)   FIXED_OP(ssneg, NAME, 2)
#define FIXED_USNEG_TEMP(NAME)   FIXED_OP(usneg, NAME, 2)
#define FIXED_ASHL_TEMP(NAME)   FIXED_OP(ashl, NAME, 3)
#define FIXED_ASHR_TEMP(NAME)   FIXED_OP(ashr, NAME, 3)
#define FIXED_LSHR_TEMP(NAME)   FIXED_OP(lshr, NAME, 3)
#define FIXED_SSASHL_TEMP(NAME)   FIXED_OP(ssashl, NAME, 3)
#define FIXED_USASHL_TEMP(NAME)   FIXED_OP(usashl, NAME, 3)
#define FIXED_CMP_TEMP(NAME)   FIXED_OP(cmp, NAME, 2)
#ifdef MODE_NAME
#   ifdef DINT_C_TYPE
#      define FIXED_SATURATE1   FIXED_SATURATE1_TEMP(MODE_NAME_S)
#   else
#      define FIXED_SATURATE2   FIXED_SATURATE2_TEMP(MODE_NAME_S)
#   endif
#   define FIXED_MULHELPER   FIXED_MULHELPER_TEMP(MODE_NAME_S)
#   define FIXED_DIVHELPER   FIXED_DIVHELPER_TEMP(MODE_NAME_S)
#   define FIXED_ASHLHELPER   FIXED_ASHLHELPER_TEMP(MODE_NAME_S)
#   define FIXED_ADD   FIXED_ADD_TEMP(MODE_NAME_S)
#   define FIXED_SUB   FIXED_SUB_TEMP(MODE_NAME_S)
#   define FIXED_MUL   FIXED_MUL_TEMP(MODE_NAME_S)
#   define FIXED_NEG   FIXED_NEG_TEMP(MODE_NAME_S)
#   define FIXED_ASHL   FIXED_ASHL_TEMP(MODE_NAME_S)
#   define FIXED_CMP   FIXED_CMP_TEMP(MODE_NAME_S)
/* TODO: Add FIXED_C_TYPE functions
#   ifdef DINT_C_TYPE
extern void FIXED_SATURATE1(DINT_C_TYPE *);
#   else
extern void FIXED_SATURATE2(INT_C_TYPE *, INT_C_TYPE *);
#   endif
extern FIXED_C_TYPE FIXED_MULHELPER(FIXED_C_TYPE, FIXED_C_TYPE, word_type);
extern FIXED_C_TYPE FIXED_DIVHELPER(FIXED_C_TYPE, FIXED_C_TYPE, word_type);
extern FIXED_C_TYPE FIXED_ASHLHELPER(FIXED_C_TYPE, word_type, word_type);
extern FIXED_C_TYPE FIXED_ADD(FIXED_C_TYPE, FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_SUB(FIXED_C_TYPE, FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_MUL(FIXED_C_TYPE, FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_NEG(FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_ASHL(FIXED_C_TYPE, word_type);
extern word_type FIXED_CMP (FIXED_C_TYPE, FIXED_C_TYPE);
*/
#endif  // MODE_NAME
#if (MODE_UNSIGNED == 0)  // Signed datatypes
#   define PADDING_BITS   ((FIXED_WIDTH - 1) - I_F_BITS)
#   define NONPADDING_BITS   (1 + I_F_BITS)
#   ifdef MODE_NAME
#      define FIXED_DIV   FIXED_DIV_TEMP(MODE_NAME_S)
#      define FIXED_ASHR   FIXED_ASHR_TEMP(MODE_NAME_S)
#      define FIXED_SSADD   FIXED_SSADD_TEMP(MODE_NAME_S)
#      define FIXED_SSSUB   FIXED_SSSUB_TEMP(MODE_NAME_S)
#      define FIXED_SSMUL   FIXED_SSMUL_TEMP(MODE_NAME_S)
#      define FIXED_SSDIV   FIXED_SSDIV_TEMP(MODE_NAME_S)
#      define FIXED_SSNEG   FIXED_SSNEG_TEMP(MODE_NAME_S)
#      define FIXED_SSASHL   FIXED_SSASHL_TEMP(MODE_NAME_S)
/* TODO: Add FIXED_* functions
extern FIXED_C_TYPE FIXED_DIV(FIXED_C_TYPE, FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_ASHR(FIXED_C_TYPE, word_type);
extern FIXED_C_TYPE FIXED_SSADD(FIXED_C_TYPE, FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_SSSUB(FIXED_C_TYPE, FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_SSMUL(FIXED_C_TYPE, FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_SSDIV(FIXED_C_TYPE, FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_SSNEG(FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_SSASHL(FIXED_C_TYPE, word_type);
*/
#   endif  // MODE_NAME
#else  // Unsigned datatypes
#   define PADDING_BITS   (FIXED_WIDTH - I_F_BITS)
#   define NONPADDING_BITS   (I_F_BITS)
#   ifdef MODE_NAME
#      define FIXED_UDIV   FIXED_UDIV_TEMP(MODE_NAME_S)
#      define FIXED_LSHR   FIXED_LSHR_TEMP(MODE_NAME_S)
#      define FIXED_USDIV   FIXED_USDIV_TEMP(MODE_NAME_S)
#      define FIXED_USADD   FIXED_USADD_TEMP(MODE_NAME_S)
#      define FIXED_USSUB   FIXED_USSUB_TEMP(MODE_NAME_S)
#      define FIXED_USMUL   FIXED_USMUL_TEMP(MODE_NAME_S)
#      define FIXED_USNEG   FIXED_USNEG_TEMP(MODE_NAME_S)
#      define FIXED_USASHL   FIXED_USASHL_TEMP(MODE_NAME_S)
/* TODO: Add unsigned FIXED_C_TYPE functions
extern FIXED_C_TYPE FIXED_UDIV (FIXED_C_TYPE, FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_LSHR (FIXED_C_TYPE, word_type);
extern FIXED_C_TYPE FIXED_USADD (FIXED_C_TYPE, FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_USSUB (FIXED_C_TYPE, FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_USMUL (FIXED_C_TYPE, FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_USDIV (FIXED_C_TYPE, FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_USNEG (FIXED_C_TYPE);
extern FIXED_C_TYPE FIXED_USASHL (FIXED_C_TYPE, word_type);
*/
#   endif  // MODE_NAME
#endif  // MODE_UNSIGNED
/** Check if this mode has any padding bits */
#define HAVE_PADDING_BITS   (PADDING_BITS > 0)
#if (defined(FROM_QI) && (HAVE_QI == 1))
#   define FROM_TYPE   1
#   define FROM_INT_C_TYPE   QItype
#   define FROM_SINT_C_TYPE   QItype
#   define FROM_UINT_C_TYPE   UQItype
#   define FROM_MODE_NAME_S   qi
#   define FROM_INT_SIZE   1
#elif (defined(FROM_HI) && (HAVE_HI == 1))
#   define FROM_TYPE   1
#   define FROM_INT_C_TYPE   HItype
#   define FROM_SINT_C_TYPE   HItype
#   define FROM_UINT_C_TYPE   UHItype
#   define FROM_MODE_NAME_S   hi
#   define FROM_INT_SIZE   2
#elif (defined(FROM_SI) && (HAVE_SI == 1))
#   define FROM_TYPE   1
#   define FROM_INT_C_TYPE   SItype
#   define FROM_SINT_C_TYPE   SItype
#   define FROM_UINT_C_TYPE   USItype
#   define FROM_MODE_NAME_S   si
#   define FROM_INT_SIZE   4
#elif (defined(FROM_DI) && (HAVE_DI == 1))
#   define FROM_TYPE   1
#   define FROM_INT_C_TYPE   DItype
#   define FROM_SINT_C_TYPE   DItype
#   define FROM_UINT_C_TYPE   UDItype
#   define FROM_MODE_NAME_S   di
#   define FROM_INT_SIZE   8
#elif (defined(FROM_TI) && (HAVE_TI == 1))
#   define FROM_TYPE   1
#   define FROM_INT_C_TYPE   TItype
#   define FROM_SINT_C_TYPE   TItype
#   define FROM_UINT_C_TYPE   UTItype
#   define FROM_MODE_NAME_S   ti
#   define FROM_INT_SIZE   16
#elif (defined(FROM_UQI) && (HAVE_UQI == 1))
#   define FROM_TYPE   2
#   define FROM_INT_C_TYPE   QItype
#   define FROM_SINT_C_TYPE   QItype
#   define FROM_UINT_C_TYPE   UQItype
#   define FROM_MODE_NAME_S   qi
#   define FROM_INT_SIZE   1
#elif (defined(FROM_UHI) && (HAVE_UHI == 1))
#   define FROM_TYPE   2
#   define FROM_INT_C_TYPE   UHItype
#   define FROM_SINT_C_TYPE   HItype
#   define FROM_UINT_C_TYPE   UHItype
#   define FROM_MODE_NAME_S   hi
#   define FROM_INT_SIZE   2
#elif (defined(FROM_USI) && (HAVE_USI == 1))
#   define FROM_TYPE   2
#   define FROM_INT_C_TYPE   USItype
#   define FROM_SINT_C_TYPE   SItype
#   define FROM_UINT_C_TYPE   USItype
#   define FROM_MODE_NAME_S   si
#   define FROM_INT_SIZE   4
#elif (defined(FROM_UDI) && (HAVE_UDI == 1))
#   define FROM_TYPE   2
#   define FROM_INT_C_TYPE   UDItype
#   define FROM_SINT_C_TYPE   DItype
#   define FROM_UINT_C_TYPE   UDItype
#   define FROM_MODE_NAME_S   di
#   define FROM_INT_SIZE   8
#elif (defined(FROM_UTI) && (HAVE_UTI == 1))
#   define FROM_TYPE   2
#   define FROM_INT_C_TYPE   UTItype
#   define FROM_SINT_C_TYPE   TItype
#   define FROM_UINT_C_TYPE   UTItype
#   define FROM_MODE_NAME_S   ti
#   define FROM_INT_SIZE   16
#elif (defined(FROM_SF) && (HAVE_SF == 1))
#   define FROM_TYPE   3
#   define FROM_FLOAT_C_TYPE   SFtype
#   define FROM_MODE_NAME_S   sf
#elif (defined(FROM_DF) && (HAVE_DF == 1))
#   define FROM_TYPE   3
#   define FROM_FLOAT_C_TYPE   DFtype
#   define FROM_MODE_NAME_S   df
#elif (defined(FROM_QQ) && (HAVE_QQ == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   QQ
#   define FROM_MODE_NAME_S   qq
#   define FROM_INT_C_TYPE   QItype
#   define FROM_SINT_C_TYPE   QItype
#   define FROM_UINT_C_TYPE   UQItype
#   define FROM_MODE_UNSIGNED   0
#   define FROM_FIXED_SIZE   1
#elif (defined(FROM_HQ) && (HAVE_HQ == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   HQ
#   define FROM_MODE_NAME_S   hq
#   define FROM_INT_C_TYPE   HItype
#   define FROM_SINT_C_TYPE   HItype
#   define FROM_UINT_C_TYPE   UHItype
#   define FROM_MODE_UNSIGNED   0
#   define FROM_FIXED_SIZE   2
#elif (defined(FROM_SQ) && (HAVE_SQ == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   SQ
#   define FROM_MODE_NAME_S   sq
#   define FROM_INT_C_TYPE   SItype
#   define FROM_SINT_C_TYPE   SItype
#   define FROM_UINT_C_TYPE   USItype
#   define FROM_MODE_UNSIGNED   0
#   define FROM_FIXED_SIZE   4
#elif (defined(FROM_DQ) && (HAVE_DQ == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   DQ
#   define FROM_MODE_NAME_S   dq
#   define FROM_INT_C_TYPE   DItype
#   define FROM_SINT_C_TYPE   DItype
#   define FROM_UINT_C_TYPE   UDItype
#   define FROM_MODE_UNSIGNED   0
#   define FROM_FIXED_SIZE   8
#elif (defined(FROM_TQ) && (HAVE_TQ == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   TQ
#   define FROM_MODE_NAME_S   tq
#   define FROM_INT_C_TYPE   TItype
#   define FROM_SINT_C_TYPE   TItype
#   define FROM_UINT_C_TYPE   UTItype
#   define FROM_MODE_UNSIGNED   0
#   define FROM_FIXED_SIZE   16
#elif (defined(FROM_UQQ) && (HAVE_UQQ == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   UQQ
#   define FROM_MODE_NAME_S   uqq
#   define FROM_INT_C_TYPE   UQItype
#   define FROM_SINT_C_TYPE   QItype
#   define FROM_UINT_C_TYPE   UQItype
#   define FROM_MODE_UNSIGNED   1
#   define FROM_FIXED_SIZE   1
#elif (defined(FROM_UHQ) && (HAVE_UHQ == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   UHQ
#   define FROM_MODE_NAME_S   uhq
#   define FROM_INT_C_TYPE   UHItype
#   define FROM_SINT_C_TYPE   HItype
#   define FROM_UINT_C_TYPE   UHItype
#   define FROM_MODE_UNSIGNED   1
#   define FROM_FIXED_SIZE   2
#elif (defined(FROM_USQ) && (HAVE_USQ == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   USQ
#   define FROM_MODE_NAME_S   usq
#   define FROM_INT_C_TYPE   USItype
#   define FROM_SINT_C_TYPE   SItype
#   define FROM_UINT_C_TYPE   USItype
#   define FROM_MODE_UNSIGNED   1
#   define FROM_FIXED_SIZE   4
#elif (defined(FROM_UDQ) && (HAVE_UDQ == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   UDQ
#   define FROM_MODE_NAME_S   udq
#   define FROM_INT_C_TYPE   UDItype
#   define FROM_SINT_C_TYPE   DItype
#   define FROM_UINT_C_TYPE   UDItype
#   define FROM_MODE_UNSIGNED   1
#   define FROM_FIXED_SIZE   8
#elif (defined(FROM_UTQ) && (HAVE_UTQ == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   UTQ
#   define FROM_MODE_NAME_S   utq
#   define FROM_INT_C_TYPE   UTItype
#   define FROM_SINT_C_TYPE   TItype
#   define FROM_UINT_C_TYPE   UTItype
#   define FROM_MODE_UNSIGNED   1
#   define FROM_FIXED_SIZE   16
#elif (defined(FROM_HA) && (HAVE_HA == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   HA
#   define FROM_MODE_NAME_S   ha
#   define FROM_INT_C_TYPE   HItype
#   define FROM_SINT_C_TYPE   HItype
#   define FROM_UINT_C_TYPE   UHItype
#   define FROM_MODE_UNSIGNED   0
#   define FROM_FIXED_SIZE   2
#elif (defined(FROM_SA) && (HAVE_SA == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   SA
#   define FROM_MODE_NAME_S   sa
#   define FROM_INT_C_TYPE   SItype
#   define FROM_SINT_C_TYPE   SItype
#   define FROM_UINT_C_TYPE   USItype
#   define FROM_MODE_UNSIGNED   0
#   define FROM_FIXED_SIZE   4
#elif (defined(FROM_DA) && (HAVE_DA == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   DA
#   define FROM_MODE_NAME_S   da
#   define FROM_INT_C_TYPE   DItype
#   define FROM_SINT_C_TYPE   DItype
#   define FROM_UINT_C_TYPE   UDItype
#   define FROM_MODE_UNSIGNED   0
#   define FROM_FIXED_SIZE   8
#elif (defined(FROM_TA) && (HAVE_TA == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   TA
#   define FROM_MODE_NAME_S   ta
#   define FROM_INT_C_TYPE   TItype
#   define FROM_SINT_C_TYPE   TItype
#   define FROM_UINT_C_TYPE   UTItype
#   define FROM_MODE_UNSIGNED   0
#   define FROM_FIXED_SIZE   16
#elif (defined(FROM_UHA) && (HAVE_UHA == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   UHA
#   define FROM_MODE_NAME_S   uha
#   define FROM_INT_C_TYPE   UHItype
#   define FROM_SINT_C_TYPE   HItype
#   define FROM_UINT_C_TYPE   UHItype
#   define FROM_MODE_UNSIGNED   1
#   define FROM_FIXED_SIZE   2
#elif (defined(FROM_USA) && (HAVE_USA == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   USA
#   define FROM_MODE_NAME_S   usa
#   define FROM_INT_C_TYPE   USItype
#   define FROM_SINT_C_TYPE   SItype
#   define FROM_UINT_C_TYPE   USItype
#   define FROM_MODE_UNSIGNED   1
#   define FROM_FIXED_SIZE   4
#elif (defined(FROM_UDA) && (HAVE_UDA == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   UDA
#   define FROM_MODE_NAME_S   uda
#   define FROM_INT_C_TYPE   UDItype
#   define FROM_SINT_C_TYPE   DItype
#   define FROM_UINT_C_TYPE   UDItype
#   define FROM_MODE_UNSIGNED   1
#   define FROM_FIXED_SIZE   8
#elif (defined(FROM_UTA) && (HAVE_UTA == 1))
#   define FROM_TYPE   4
#   define FROM_MODE_NAME   UTA
#   define FROM_MODE_NAME_S   uta
#   define FROM_INT_C_TYPE   UTItype
#   define FROM_SINT_C_TYPE   TItype
#   define FROM_UINT_C_TYPE   UTItype
#   define FROM_MODE_UNSIGNED   1
#   define FROM_FIXED_SIZE   16
#endif
#if (defined(TO_QI) && (HAVE_QI == 1) && (!defined(FROM_QI)))
#   define TO_TYPE   1
#   define TO_INT_C_TYPE   QItype
#   define TO_SINT_C_TYPE   QItype
#   define TO_UINT_C_TYPE   UQItype
#   define TO_MODE_NAME_S   qi
#elif (defined(TO_HI) && (HAVE_HI == 1) && (!defined(FROM_HI)))
#   define TO_TYPE   1
#   define TO_INT_C_TYPE   HItype
#   define TO_SINT_C_TYPE   HItype
#   define TO_UINT_C_TYPE   UHItype
#   define TO_MODE_NAME_S   hi
#elif (defined(TO_SI) && (HAVE_SI == 1) && (!defined(FROM_SI)))
#   define TO_TYPE   1
#   define TO_INT_C_TYPE   SItype
#   define TO_SINT_C_TYPE   SItype
#   define TO_UINT_C_TYPE   USItype
#   define TO_MODE_NAME_S   si
#elif (defined(TO_DI) && (HAVE_DI == 1) && (!defined(FROM_DI)))
#   define TO_TYPE   1
#   define TO_INT_C_TYPE   DItype
#   define TO_SINT_C_TYPE   DItype
#   define TO_UINT_C_TYPE   UDItype
#   define TO_MODE_NAME_S   di
#elif (defined(TO_TI) && (HAVE_TI == 1) && (!defined(FROM_TI)))
#   define TO_TYPE   1
#   define TO_INT_C_TYPE   TItype
#   define TO_SINT_C_TYPE   TItype
#   define TO_UINT_C_TYPE   UTItype
#   define TO_MODE_NAME_S   ti
#elif (defined(TO_UQI) && (HAVE_UQI == 1) && (!defined(FROM_UQI)))
#   define TO_TYPE   2
#   define TO_INT_C_TYPE   UQItype
#   define TO_SINT_C_TYPE   QItype
#   define TO_UINT_C_TYPE   UQItype
#   define TO_MODE_NAME_S   qi
#elif (defined(TO_UHI) && (HAVE_UHI == 1) && (!defined(FROM_UHI)))
#   define TO_TYPE   2
#   define TO_INT_C_TYPE   UHItype
#   define TO_SINT_C_TYPE   HItype
#   define TO_UINT_C_TYPE   UHItype
#   define TO_MODE_NAME_S   hi
#elif (defined(TO_USI) && (HAVE_USI == 1) && (!defined(FROM_USI)))
#   define TO_TYPE   2
#   define TO_INT_C_TYPE   USItype
#   define TO_SINT_C_TYPE   SItype
#   define TO_UINT_C_TYPE   USItype
#   define TO_MODE_NAME_S   si
#elif (defined(TO_UDI) && (HAVE_UDI == 1) && (!defined(FROM_UDI)))
#   define TO_TYPE   2
#   define TO_INT_C_TYPE   UDItype
#   define TO_SINT_C_TYPE   DItype
#   define TO_UINT_C_TYPE   UDItype
#   define TO_MODE_NAME_S   di
#elif (defined(TO_UTI) && (HAVE_UTI == 1) && (!defined(FROM_UTI)))
#   define TO_TYPE   2
#   define TO_INT_C_TYPE   UTItype
#   define TO_SINT_C_TYPE   TItype
#   define TO_UINT_C_TYPE   UTItype
#   define TO_MODE_NAME_S   ti
#elif (defined(TO_SF) && (HAVE_SF == 1) && (!defined(FROM_SF)))
#   define TO_TYPE   3
#   define TO_FLOAT_C_TYPE   SFtype
#   define TO_MODE_NAME_S   sf
#elif (defined(TO_DF) && (HAVE_DF == 1) && (!defined(FROM_DF)))
#   define TO_TYPE   3
#   define TO_FLOAT_C_TYPE   DFtype
#   define TO_MODE_NAME_S   df
#elif (defined(TO_QQ) && (HAVE_QQ == 1) && (!defined(FROM_QQ)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   QQ
#   define TO_MODE_NAME_S   qq
#   define TO_INT_C_TYPE   QItype
#   define TO_SINT_C_TYPE   QItype
#   define TO_UINT_C_TYPE   UQItype
#   define TO_MODE_UNSIGNED   0
#   define TO_FIXED_SIZE   1
#elif (defined(TO_HQ) && (HAVE_HQ == 1) && (!defined(FROM_HQ)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   HQ
#   define TO_MODE_NAME_S   hq
#   define TO_INT_C_TYPE   HItype
#   define TO_SINT_C_TYPE   HItype
#   define TO_UINT_C_TYPE   UHItype
#   define TO_MODE_UNSIGNED   0
#   define TO_FIXED_SIZE   2
#elif (defined(TO_SQ) && (HAVE_SQ == 1) && (!defined(FROM_SQ)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   SQ
#   define TO_MODE_NAME_S   sq
#   define TO_INT_C_TYPE   SItype
#   define TO_SINT_C_TYPE   SItype
#   define TO_UINT_C_TYPE   USItype
#   define TO_MODE_UNSIGNED   0
#   define TO_FIXED_SIZE   4
#elif (defined(TO_DQ) && (HAVE_DQ == 1) && (!defined(FROM_DQ)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   DQ
#   define TO_MODE_NAME_S   dq
#   define TO_INT_C_TYPE   DItype
#   define TO_SINT_C_TYPE   DItype
#   define TO_UINT_C_TYPE   UDItype
#   define TO_MODE_UNSIGNED   0
#   define TO_FIXED_SIZE   8
#elif (defined(TO_TQ) && (HAVE_TQ == 1) && (!defined(FROM_TQ)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   TQ
#   define TO_MODE_NAME_S   tq
#   define TO_INT_C_TYPE   TItype
#   define TO_SINT_C_TYPE   TItype
#   define TO_UINT_C_TYPE   UTItype
#   define TO_MODE_UNSIGNED   0
#   define TO_FIXED_SIZE   16
#elif (defined(TO_UQQ) && (HAVE_UQQ == 1) && (!defined(FROM_UQQ)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   UQQ
#   define TO_MODE_NAME_S   uqq
#   define TO_INT_C_TYPE   UQItype
#   define TO_SINT_C_TYPE   QItype
#   define TO_UINT_C_TYPE   UQItype
#   define TO_MODE_UNSIGNED   1
#   define TO_FIXED_SIZE   1
#elif (defined(TO_UHQ) && (HAVE_UHQ == 1) && (!defined(FROM_UHQ)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   UHQ
#   define TO_MODE_NAME_S   uhq
#   define TO_INT_C_TYPE   UHItype
#   define TO_SINT_C_TYPE   HItype
#   define TO_UINT_C_TYPE   UHItype
#   define TO_MODE_UNSIGNED   1
#   define TO_FIXED_SIZE   2
#elif (defined(TO_USQ) && (HAVE_USQ == 1) && (!defined(FROM_USQ)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   USQ
#   define TO_MODE_NAME_S   usq
#   define TO_INT_C_TYPE   USItype
#   define TO_SINT_C_TYPE   SItype
#   define TO_UINT_C_TYPE   USItype
#   define TO_MODE_UNSIGNED   1
#   define TO_FIXED_SIZE   4
#elif (defined(TO_UDQ) && (HAVE_UDQ == 1) && (!defined(FROM_UDQ)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   UDQ
#   define TO_MODE_NAME_S   udq
#   define TO_INT_C_TYPE   UDItype
#   define TO_SINT_C_TYPE   DItype
#   define TO_UINT_C_TYPE   UDItype
#   define TO_MODE_UNSIGNED   1
#   define TO_FIXED_SIZE   8
#elif (defined(TO_UTQ) && (HAVE_UTQ == 1) && (!defined(FROM_UTQ)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   UTQ
#   define TO_MODE_NAME_S   utq
#   define TO_INT_C_TYPE   UTItype
#   define TO_SINT_C_TYPE   TItype
#   define TO_UINT_C_TYPE   UTItype
#   define TO_MODE_UNSIGNED   1
#   define TO_FIXED_SIZE   16
#elif (defined(TO_HA) && (HAVE_HA == 1) && (!defined(FROM_HA)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   HA
#   define TO_MODE_NAME_S   ha
#   define TO_INT_C_TYPE   HItype
#   define TO_SINT_C_TYPE   HItype
#   define TO_UINT_C_TYPE   UHItype
#   define TO_MODE_UNSIGNED   0
#   define TO_FIXED_SIZE   2
#elif (defined(TO_SA) && (HAVE_SA == 1) && (!defined(FROM_SA)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   SA
#   define TO_MODE_NAME_S   sa
#   define TO_INT_C_TYPE   SItype
#   define TO_SINT_C_TYPE   SItype
#   define TO_UINT_C_TYPE   USItype
#   define TO_MODE_UNSIGNED   0
#   define TO_FIXED_SIZE   4
#elif (defined(TO_DA) && (HAVE_DA == 1) && (!defined(FROM_DA)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   DA
#   define TO_MODE_NAME_S   da
#   define TO_INT_C_TYPE   DItype
#   define TO_SINT_C_TYPE   DItype
#   define TO_UINT_C_TYPE   UDItype
#   define TO_MODE_UNSIGNED   0
#   define TO_FIXED_SIZE   8
#elif (defined(TO_TA) && (HAVE_TA == 1) && (!defined(FROM_TA)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   TA
#   define TO_MODE_NAME_S   ta
#   define TO_INT_C_TYPE   TItype
#   define TO_SINT_C_TYPE   TItype
#   define TO_UINT_C_TYPE   UTItype
#   define TO_MODE_UNSIGNED   0
#   define TO_FIXED_SIZE   16
#elif (defined(TO_UHA) && (HAVE_UHA == 1) && (!defined(FROM_UHA)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   UHA
#   define TO_MODE_NAME_S   uha
#   define TO_INT_C_TYPE   UHItype
#   define TO_SINT_C_TYPE   HItype
#   define TO_UINT_C_TYPE   UHItype
#   define TO_MODE_UNSIGNED   1
#   define TO_FIXED_SIZE   2
#elif (defined(TO_USA) && (HAVE_USA == 1) && (!defined(FROM_USA)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   USA
#   define TO_MODE_NAME_S   usa
#   define TO_INT_C_TYPE   USItype
#   define TO_SINT_C_TYPE   SItype
#   define TO_UINT_C_TYPE   USItype
#   define TO_MODE_UNSIGNED   1
#   define TO_FIXED_SIZE   4
#elif (defined(TO_UDA) && (HAVE_UDA == 1) && (!defined(FROM_UDA)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   UDA
#   define TO_MODE_NAME_S   uda
#   define TO_INT_C_TYPE   UDItype
#   define TO_SINT_C_TYPE   DItype
#   define TO_UINT_C_TYPE   UDItype
#   define TO_MODE_UNSIGNED   1
#   define TO_FIXED_SIZE   8
#elif (defined(TO_UTA) && (HAVE_UTA == 1) && (!defined(FROM_UTA)))
#   define TO_TYPE   4
#   define TO_MODE_NAME   UTA
#   define TO_MODE_NAME_S   uta
#   define TO_INT_C_TYPE   UTItype
#   define TO_SINT_C_TYPE   TItype
#   define TO_UINT_C_TYPE   UTItype
#   define TO_MODE_UNSIGNED   1
#   define TO_FIXED_SIZE   16
#endif


#if (defined(__GNUC__) && defined(AVR) && (!(defined(_AVRGCC_STDFIX_H) || defined(_AVRGCC_STDFIX_H_))))  // AVR-specific code
#define AVRGCC_STDFIX_H   (1)
#define _AVRGCC_STDFIX_H   (1)
#define _AVRGCC_STDFIX_H_   (1)


#define abshr   __builtin_avr_abshr
#define absr   __builtin_avr_absr
#define abslr   __builtin_avr_abslr
#define abshk   __builtin_avr_abshk
#define absk   __builtin_avr_absk
#if (SIZEOF_INT == 2)
#   define abslk   __builtin_avr_abslk
#   define absllr   __builtin_avr_absllr
#   define absllk   __builtin_avr_absllk
#endif
#define roundhr   __builtin_avr_roundhr
#define roundr   __builtin_avr_roundr
#define roundlr   __builtin_avr_roundlr
#define rounduhr   __builtin_avr_rounduhr
#define roundur   __builtin_avr_roundur
#define roundulr   __builtin_avr_roundulr
#define roundhk   __builtin_avr_roundhk
#define roundk   __builtin_avr_roundk
#define rounduhk   __builtin_avr_rounduhk
#define rounduk   __builtin_avr_rounduk
#if (SIZEOF_INT == 2)
#   define roundlk   __builtin_avr_roundlk
#   define roundulk   __builtin_avr_roundulk
#   define roundllr   __builtin_avr_roundllr
#   define roundullr   __builtin_avr_roundullr
#   define roundllk   __builtin_avr_roundllk
#   define roundullk   __builtin_avr_roundullk
#endif
#define countlshr   __builtin_avr_countlshr
#define countlsr   __builtin_avr_countlsr
#define countlslr   __builtin_avr_countlslr
#define countlsuhr   __builtin_avr_countlsuhr
#define countlsur   __builtin_avr_countlsur
#define countlsulr   __builtin_avr_countlsulr
#define countlshk   __builtin_avr_countlshk
#define countlsk   __builtin_avr_countlsk
#define countlsuhk   __builtin_avr_countlsuhk
#define countlsuk   __builtin_avr_countlsuk
#if (SIZEOF_INT == 2)
#   define countlslk   __builtin_avr_countlslk
#   define countlsulk   __builtin_avr_countlsulk
#   define countlsllr   __builtin_avr_countlsllr
#   define countlsullr   __builtin_avr_countlsullr
#   define countlsllk   __builtin_avr_countlsllk
#   define countlsullk   __builtin_avr_countlsullk
#endif
#define bitshr   __builtin_avr_bitshr
#define bitsr   __builtin_avr_bitsr
#define bitslr   __builtin_avr_bitslr
#define bitsuhr   __builtin_avr_bitsuhr
#define bitsur   __builtin_avr_bitsur
#define bitsulr   __builtin_avr_bitsulr
#define bitshk   __builtin_avr_bitshk
#define bitsk   __builtin_avr_bitsk
#define bitsuhk   __builtin_avr_bitsuhk
#define bitsuk   __builtin_avr_bitsuk
#if (SIZEOF_INT == 2)
#   define bitslk   __builtin_avr_bitslk
#   define bitsulk   __builtin_avr_bitsulk
#   define bitsllr   __builtin_avr_bitsllr
#   define bitsullr   __builtin_avr_bitsullr
#   define bitsllk   __builtin_avr_bitsllk
#   define bitsullk   __builtin_avr_bitsullk
#endif
#define hrbits   __builtin_avr_hrbits
#define rbits   __builtin_avr_rbits
#define lrbits   __builtin_avr_lrbits
#define uhrbits   __builtin_avr_uhrbits
#define urbits   __builtin_avr_urbits
#define ulrbits   __builtin_avr_ulrbits
#define hkbits   __builtin_avr_hkbits
#define kbits   __builtin_avr_kbits
#define uhkbits   __builtin_avr_uhkbits
#define ukbits   __builtin_avr_ukbits
#if (SIZEOF_INT == 2)
#   define lkbits   __builtin_avr_lkbits
#   define ulkbits   __builtin_avr_ulkbits
#   define llrbits   __builtin_avr_llrbits
#   define ullrbits   __builtin_avr_ullrbits
#   define llkbits   __builtin_avr_llkbits
#   define ullkbits   __builtin_avr_ullkbits
#endif
#define absfx   __builtin_avr_absfx
#define roundfx   __builtin_avr_roundfx
#define countlsfx   __builtin_avr_countlsfx
#if (defined (__WITH_AVRLIBC__) && defined(__has_include) && __has_include(<stdfix-avrlibc.h>))
#   include <stdfix-avrlibc.h>
#endif


#endif  // AVRGCC_STDFIX_H


#if (defined(FROM_MODE_NAME_S) && defined(TO_MODE_NAME_S))
#   if (FROM_TYPE == 1)
#      define FROM_INT_WIDTH   (FROM_INT_SIZE * BITS_PER_UNIT)
#   elif (FROM_TYPE == 2)
#      define FROM_INT_WIDTH   (FROM_INT_SIZE * BITS_PER_UNIT)
#   elif (FROM_TYPE == 4)
#      define FROM_FIXED_C_TYPE   FIXED_C_TYPE2(FROM_MODE_NAME)
#      define FROM_FBITS   FBITS2(FROM_MODE_NAME)
#      define FROM_FIXED_WIDTH   (FROM_FIXED_SIZE * BITS_PER_UNIT)
#      define FROM_FBITS   FBITS2(FROM_MODE_NAME)
#      define FROM_IBITS   IBITS2(FROM_MODE_NAME)
#      define FROM_I_F_BITS   (FROM_FBITS + FROM_IBITS)
#      if (FROM_MODE_UNSIGNED == 0)  // Signed datatypes
#         define FROM_PADDING_BITS   (FROM_FIXED_WIDTH - 1 - FROM_I_F_BITS)
#         define FROM_NONPADDING_BITS   (1 + FROM_I_F_BITS)
#      else  // Unsigned datatypes
#         define FROM_PADDING_BITS   (FROM_FIXED_WIDTH - FROM_I_F_BITS)
#         define FROM_NONPADDING_BITS   (FROM_I_F_BITS)
#      endif
#      define FROM_HAVE_PADDING_BITS   (FROM_PADDING_BITS > 0)
#   endif  // FROM_TYPE
#   if (TO_TYPE == 4)
#      define TO_FIXED_C_TYPE   FIXED_C_TYPE2(TO_MODE_NAME)
#      define TO_FBITS   FBITS2(TO_MODE_NAME)
#      define TO_FIXED_WIDTH   (TO_FIXED_SIZE * BITS_PER_UNIT)
#      define TO_FBITS   FBITS2(TO_MODE_NAME)
#      define TO_IBITS   IBITS2(TO_MODE_NAME)
#      define TO_I_F_BITS   (TO_FBITS + TO_IBITS)
#      if (TO_MODE_UNSIGNED == 0)  // Signed datatypes
#         define TO_PADDING_BITS   (TO_FIXED_WIDTH - 1 - TO_I_F_BITS)
#         define TO_NONPADDING_BITS   (1 + TO_I_F_BITS)
#      else  // Unsigned datatypes
#         define TO_PADDING_BITS   (TO_FIXED_WIDTH - TO_I_F_BITS)
#         define TO_NONPADDING_BITS   (TO_I_F_BITS)
#      endif
#      define TO_HAVE_PADDING_BITS   (TO_PADDING_BITS > 0)
#   endif  // TO_TYPE
#   ifdef LIBGCC2_FIXEDBIT_GNU_PREFIX
#      define FIXED_CONVERT_OP(OP, FROM, TO)   __gnu_ ## OP ## FROM ## TO
#      define FIXED_CONVERT_OP2(OP, FROM, TO)   __gnu_ ## OP ## FROM ## TO ## 2
#   else
#      define FIXED_CONVERT_OP(OP, FROM, TO)   __ ## OP ## FROM ## TO
#      define FIXED_CONVERT_OP2(OP, FROM, TO)   __ ## OP ## FROM ## TO ## 2
#   endif
#   define FRACT_TEMP(N1, N2)   FIXED_CONVERT_OP(fract, N1, N2)
#   define FRACT2_TEMP(N1, N2)   FIXED_CONVERT_OP2(fract, N1, N2)
#   define SATFRACT_TEMP(N1, N2)   FIXED_CONVERT_OP(satfract, N1, N2)
#   define SATFRACT2_TEMP(N1, N2)   FIXED_CONVERT_OP2(satfract, N1, N2)
#   define FRACTUNS_TEMP(N1, N2)   FIXED_CONVERT_OP(fractuns, N1, N2)
#   define SATFRACTUNS_TEMP(N1, N2)   FIXED_CONVERT_OP(satfractuns, N1, N2)
#   if ((FROM_TYPE == 4) && (TO_TYPE == 4))  // Define conversions from fixed-point to fixed-point
#      if FROM_FIXED_SIZE > TO_FIXED_SIZE
#         define BIG_SINT_C_TYPE   FROM_SINT_C_TYPE
#         define BIG_UINT_C_TYPE   FROM_UINT_C_TYPE
#         define BIG_WIDTH   FROM_FIXED_WIDTH
#      else
#         define BIG_SINT_C_TYPE   TO_SINT_C_TYPE
#         define BIG_UINT_C_TYPE   TO_UINT_C_TYPE
#         define BIG_WIDTH   TO_FIXED_WIDTH
#      endif
#      if ((FROM_MODE_UNSIGNED == TO_MODE_UNSIGNED) && ((FROM_IBITS == 0) == (TO_IBITS == 0)))  // Check if FROM* and TO* are in the same machine class
#         define FRACT   FRACT2_TEMP(FROM_MODE_NAME_S,TO_MODE_NAME_S)
#         define SATFRACT   SATFRACT2_TEMP(FROM_MODE_NAME_S,TO_MODE_NAME_S)
#      else  // Different modes; do not append '2' to conversion function names
#         define FRACT   FRACT_TEMP(FROM_MODE_NAME_S,TO_MODE_NAME_S)
#         define SATFRACT   SATFRACT_TEMP(FROM_MODE_NAME_S,TO_MODE_NAME_S)
#      endif
extern TO_FIXED_C_TYPE FRACT(FROM_FIXED_C_TYPE);
extern TO_FIXED_C_TYPE SATFRACT(FROM_FIXED_C_TYPE);
#   endif  // ((FROM_TYPE == 4) && (TO_TYPE == 4))
#   if ((FROM_TYPE == 4) && (TO_TYPE == 1))  // Define conversions from fixed-point to signed integer
#      define FRACT   FRACT_TEMP(FROM_MODE_NAME_S,TO_MODE_NAME_S)
extern TO_INT_C_TYPE FRACT(FROM_FIXED_C_TYPE);
#   endif  // ((FROM_TYPE == 4) && (TO_TYPE == 1))
#   if ((FROM_TYPE == 4) && (TO_TYPE == 2))  // Define conversions from fixed-point to unsigned integer
#      define FRACTUNS   FRACTUNS_TEMP(FROM_MODE_NAME_S, TO_MODE_NAME_S)
extern TO_INT_C_TYPE   FRACTUNS(FROM_FIXED_C_TYPE);
#   endif  // ((FROM_TYPE == 4) && (TO_TYPE == 2))
#   if ((FROM_TYPE == 4) && (TO_TYPE == 3))  // Define conversions from fixed-point to floating-point
#      define BASE1(NUM)   0x1.0p ## NUM
#      define BASE2(NUM)   BASE1(NUM)
#      define BASE   BASE2(FROM_FBITS)
#      define FRACT   FRACT_TEMP(FROM_MODE_NAME_S,TO_MODE_NAME_S)
extern TO_FLOAT_C_TYPE   FRACT (FROM_FIXED_C_TYPE);
#   endif  // ((FROM_TYPE == 4) && (TO_TYPE == 3))
#   if ((FROM_TYPE == 1) && (TO_TYPE == 4))  // Define conversions from signed integer to fixed-point
#      if (FROM_INT_SIZE > TO_FIXED_SIZE)
#         define BIG_SINT_C_TYPE   FROM_SINT_C_TYPE
#         define BIG_UINT_C_TYPE   FROM_UINT_C_TYPE
#         define BIG_WIDTH   FROM_INT_WIDTH
#      else
#         define BIG_SINT_C_TYPE   TO_SINT_C_TYPE
#         define BIG_UINT_C_TYPE   TO_UINT_C_TYPE
#         define BIG_WIDTH   TO_FIXED_WIDTH
#      endif
#      define FRACT   FRACT_TEMP(FROM_MODE_NAME_S, TO_MODE_NAME_S)
#      define SATFRACT   SATFRACT_TEMP(FROM_MODE_NAME_S, TO_MODE_NAME_S)
extern TO_FIXED_C_TYPE FRACT(FROM_INT_C_TYPE);
extern TO_FIXED_C_TYPE SATFRACT(FROM_INT_C_TYPE);
#   endif  // ((FROM_TYPE == 1) && (TO_TYPE == 4))
#   if ((FROM_TYPE == 2) && (TO_TYPE == 4))  // Define conversions from unsigned integer to fixed-point
#      if (FROM_INT_SIZE > TO_FIXED_SIZE)
#         define BIG_SINT_C_TYPE   FROM_SINT_C_TYPE
#         define BIG_UINT_C_TYPE   FROM_UINT_C_TYPE
#         define BIG_WIDTH   FROM_INT_WIDTH
#      else
#         define BIG_SINT_C_TYPE   TO_SINT_C_TYPE
#         define BIG_UINT_C_TYPE   TO_UINT_C_TYPE
#         define BIG_WIDTH   TO_FIXED_WIDTH
#      endif
#      define FRACTUNS   FRACTUNS_TEMP(FROM_MODE_NAME_S,TO_MODE_NAME_S)
#      define SATFRACTUNS   SATFRACTUNS_TEMP(FROM_MODE_NAME_S,TO_MODE_NAME_S)
extern TO_FIXED_C_TYPE   FRACTUNS(FROM_INT_C_TYPE);
extern TO_FIXED_C_TYPE   SATFRACTUNS(FROM_INT_C_TYPE);
#   endif  // ((FROM_TYPE == 2) && (TO_TYPE == 4))
#   if ((FROM_TYPE == 3) && (TO_TYPE == 4))  // Define conversions from floating-point to fixed-point
#      define BASE1(NUM)   (0x1.0p ## NUM)
#      define BASE2(NUM)   BASE1(NUM)
#      define BASE   BASE2(TO_FBITS)
#      define FIXED_MAX1(NUM1, NUM2)   (0x1.0p ## NUM1 - 0x1.0p- ## NUM2)
#      define FIXED_MAX2(NUM1, NUM2)   FIXED_MAX1(NUM1,NUM2)
#      define FIXED_MAX   FIXED_MAX2(TO_IBITS, TO_FBITS)
#      define FIXED_MIN1(NUM)   (-0x1.0p ## NUM)
#      define FIXED_MIN2(NUM)   FIXED_MIN1(NUM)
#      if (TO_MODE_UNSIGNED == 0)
#         define FIXED_MIN   FIXED_MIN2(TO_IBITS)
#      else
#         define FIXED_MIN   0.0
#      endif
#      define FRACT   FRACT_TEMP(FROM_MODE_NAME_S, TO_MODE_NAME_S)
#      define SATFRACT   SATFRACT_TEMP(FROM_MODE_NAME_S, TO_MODE_NAME_S)
extern TO_FIXED_C_TYPE FRACT(FROM_FLOAT_C_TYPE);
extern TO_FIXED_C_TYPE SATFRACT(FROM_FLOAT_C_TYPE);
#   endif  // ((FROM_TYPE == 3) && (TO_TYPE == 4))
#endif  // (defined(FROM_MODE_NAME_S) && defined(TO_MODE_NAME_S))


LIB_FUNC int sat_add(const int a, const int b) {
	register int c = a + b;
	if ((((a ^ b) & MIN_32) == 0) && ((c ^ a) & MIN_32)) {
		c = ((a < 0) ? MIN_32 : MAX_32);
	}
	return c;
}


LIB_FUNC _Accum mul_sum(_Sat _Fract* a, _Sat _Fract* b, const int length) {
	register int i;
	_Accum accumulator = 0;
	for (i = 0; i < length; i++) { accumulator += (_Accum)(a[i] * b[i]); }
	return accumulator;
}


#if (defined(FIXED_ADD) && defined(L_add))
LIB_FUNC FIXED_C_TYPE FIXED_ADD(FIXED_C_TYPE a, FIXED_C_TYPE b) {
	FIXED_C_TYPE c;
	INT_C_TYPE x, y, z;
	memcpy_no_output(&x, &a, FIXED_SIZE);
	memcpy_no_output(&y, &b, FIXED_SIZE);
	z = x + y;
#   if HAVE_PADDING_BITS
	z <<= PADDING_BITS;
	z >>= PADDING_BITS;
#   endif
	memcpy_no_output(&c, &z, FIXED_SIZE);
	return c;
}
#endif


#if (defined(FIXED_SSADD) && defined(L_ssadd))
LIB_FUNC FIXED_C_TYPE FIXED_SSADD(FIXED_C_TYPE a, FIXED_C_TYPE b) {
	FIXED_C_TYPE c;
	INT_C_TYPE x, y, z;
	memcpy_no_output(&x, &a, FIXED_SIZE);
	memcpy_no_output(&y, &b, FIXED_SIZE);
	z = x + (UINT_C_TYPE)y;
	if ((((x ^ y) >> I_F_BITS) & 1) == 0) {
		if (((z ^ x) >> I_F_BITS) & 1) {
			z = ((UINT_C_TYPE)1) << I_F_BITS;
			if (x >= 0) { z -= (UINT_C_TYPE)1; }
		}
	}
#   if HAVE_PADDING_BITS
	z <<= PADDING_BITS;
	z >>= PADDING_BITS;
#   endif
	memcpy_no_output(&c, &z, FIXED_SIZE);
	return c;
}
#endif


#if (defined(FIXED_USADD) && defined(L_usadd))
LIB_FUNC FIXED_C_TYPE FIXED_USADD(FIXED_C_TYPE a, FIXED_C_TYPE b) {
	FIXED_C_TYPE c;
	INT_C_TYPE x, y, z;
	memcpy_no_output(&x, &a, FIXED_SIZE);
	memcpy_no_output(&y, &b, FIXED_SIZE);
	z = x + y;
#   if HAVE_PADDING_BITS
	z <<= PADDING_BITS;
	z >>= PADDING_BITS;
#   endif
	if (z < x || z < y) {
		z = -1;
#   if HAVE_PADDING_BITS
		z <<= PADDING_BITS;
		z >>= PADDING_BITS;
#   endif
	}
	memcpy_no_output(&c, &z, FIXED_SIZE);
	return c;
}
#endif


#if (defined(FIXED_SUB) && defined(L_sub))
LIB_FUNC FIXED_C_TYPE FIXED_SUB(FIXED_C_TYPE a, FIXED_C_TYPE b) {
	FIXED_C_TYPE c;
	INT_C_TYPE x, y, z;
	memcpy_no_output(&x, &a, FIXED_SIZE);
	memcpy_no_output(&y, &b, FIXED_SIZE);
	z = x - y;
#   if HAVE_PADDING_BITS
	z <<= PADDING_BITS;
	z >>= PADDING_BITS;
#   endif
	memcpy_no_output(&c, &z, FIXED_SIZE);
	return c;
}
#endif


#if (defined(FIXED_SSSUB) && defined(L_sssub))
LIB_FUNC FIXED_C_TYPE FIXED_SSSUB(FIXED_C_TYPE a, FIXED_C_TYPE b) {
	FIXED_C_TYPE c;
	INT_C_TYPE x, y, z;
	memcpy_no_output(&x, &a, FIXED_SIZE);
	memcpy_no_output(&y, &b, FIXED_SIZE);
	z = x - (UINT_C_TYPE)y;
	if (((x ^ y) >> I_F_BITS) & 1) {
		if (((z ^ x) >> I_F_BITS) & 1) {
			z = ((UINT_C_TYPE)1) << I_F_BITS;
			if (x >= 0) { z -= (UINT_C_TYPE)1; }
		}
	}
#   if HAVE_PADDING_BITS
	z <<= PADDING_BITS;
	z >>= PADDING_BITS;
#   endif
	memcpy_no_output(&c, &z, FIXED_SIZE);
	return c;
}
#endif


#if (defined(FIXED_USSUB) && defined(L_ussub))
LIB_FUNC FIXED_C_TYPE FIXED_USSUB(FIXED_C_TYPE a, FIXED_C_TYPE b) {
	FIXED_C_TYPE c;
	INT_C_TYPE x, y, z;
	memcpy_no_output(&x, &a, FIXED_SIZE);
	memcpy_no_output(&y, &b, FIXED_SIZE);
	z = x - y;
	if (x < y) { z = 0; }
#   if HAVE_PADDING_BITS
	z <<= PADDING_BITS;
	z >>= PADDING_BITS;
#   endif
	memcpy_no_output(&c, &z, FIXED_SIZE);
	return c;
}
#endif


#if (defined(FIXED_SATURATE1) && defined(L_saturate1))
LIB_FUNC void FIXED_SATURATE1(DINT_C_TYPE *a) {
	DINT_C_TYPE max, min;
	max = ((DINT_C_TYPE)1 << I_F_BITS);
	--max;
#   if (MODE_UNSIGNED == 0)
	min = (DINT_C_TYPE)1 << ((2 * FIXED_WIDTH) - 1);
	min >>= ((2 * FIXED_WIDTH) - 1 - I_F_BITS);
#   else
	min = 0;
#   endif
	if (*a > max) { *a = max; }
	else if (*a < min) { *a = min; }
}
#endif


#if (defined(FIXED_SATURATE2) && defined(L_saturate2))
LIB_FUNC void FIXED_SATURATE2(INT_C_TYPE *high, INT_C_TYPE *low) {
	INT_C_TYPE r_max, s_max, r_min, s_min;
	r_max = 0;
#   if ((MODE_UNSIGNED == 0) || HAVE_PADDING_BITS)
	s_max = (INT_C_TYPE)1 << I_F_BITS;
	--s_max;
#   else
	s_max = -1;
#   endif
#   if (MODE_UNSIGNED == 0)
	r_min = -1;
	s_min = ((INT_C_TYPE)1 << (FIXED_WIDTH - 1));
	s_min >>= (FIXED_WIDTH - 1 - I_F_BITS);
#   else
	r_min = 0;
	s_min = 0;
#   endif
	if (*high > r_max || (*high == r_max && (UINT_C_TYPE)(*low) > (UINT_C_TYPE)s_max)) {
		*high = r_max;
		*low = s_max;
	} else if (*high < r_min || (*high == r_min && (UINT_C_TYPE)(*low) < (UINT_C_TYPE)s_min)) {
		*high = r_min;
		*low = s_min;
	}
}
#endif


#if (defined(FIXED_MULHELPER) && defined(L_mulhelper))
LIB_FUNC FIXED_C_TYPE FIXED_MULHELPER(FIXED_C_TYPE a, FIXED_C_TYPE b, word_type satp) {
	FIXED_C_TYPE c;
	INT_C_TYPE x, y;
#   ifdef DINT_C_TYPE
	INT_C_TYPE z;
	DINT_C_TYPE dx, dy, dz;
	memcpy_no_output(&x, &a, FIXED_SIZE);
	memcpy_no_output(&y, &b, FIXED_SIZE);
	dx = (DINT_C_TYPE)x;
	dy = (DINT_C_TYPE)y;
	dz = dx * dy;
	dz += ((DINT_C_TYPE)1 << (FBITS - 1));
	dz = dz >> FBITS;
	if (satp)
	FIXED_SATURATE1 (&dz);
	z = (INT_C_TYPE)dz;
#      if HAVE_PADDING_BITS
	z <<= PADDING_BITS;
	z >>= PADDING_BITS;
#      endif
	memcpy_no_output(&c, &z, FIXED_SIZE);
	return c;
#   else  // No DINT_C_TYPE
	INTunion aa, bb, a_high, a_low, b_high, b_low;
	INTunion high_high, high_low, low_high, low_low;
	INTunion r, s, temp1, temp2;
	INT_C_TYPE carry = 0, z;
	memcpy_no_output(&x, &a, FIXED_SIZE);
	memcpy_no_output(&y, &b, FIXED_SIZE);
	aa.ll = x;
	bb.ll = y;
	a_high.s.low = aa.s.high;
	a_high.s.high = 0;
	a_low.s.low = aa.s.low;
	a_low.s.high = 0;
	b_high.s.low = bb.s.high;
	b_high.s.high = 0;
	b_low.s.low = bb.s.low;
	b_low.s.high = 0;
	// Perform four multiplications
	low_low.ll = a_low.ll * b_low.ll;
	low_high.ll = a_low.ll * b_high.ll;
	high_low.ll = a_high.ll * b_low.ll;
	high_high.ll = a_high.ll * b_high.ll;
	// Accumulate four results to {r, s}
	temp1.s.high = high_low.s.low;
	temp1.s.low = 0;
	s.ll = low_low.ll + temp1.ll;
	if ((UINT_C_TYPE)s.ll < (UINT_C_TYPE)low_low.ll || (UINT_C_TYPE)s.ll < (UINT_C_TYPE)temp1.ll) {
		++carry;
	}
	temp1.ll = s.ll;
	temp2.s.high = low_high.s.low;
	temp2.s.low = 0;
	s.ll = temp1.ll + temp2.ll;
	if ((UINT_C_TYPE)s.ll < (UINT_C_TYPE)temp1.ll || (UINT_C_TYPE)s.ll < (UINT_C_TYPE)temp2.ll) {
		++carry;
	}
	temp1.s.low = high_low.s.high;
	temp1.s.high = 0;
	r.ll = high_high.ll + temp1.ll;
	temp1.s.low = low_high.s.high;
	temp1.s.high = 0;
	r.ll = r.ll + temp1.ll + carry;
#      if (MODE_UNSIGNED == 0)
	if (x < 0) { r.ll -= y; }
	if (y < 0) { r.ll -= x; }
#      endif
	temp1.ll = s.ll;
	s.ll += ((INT_C_TYPE)1 << (FBITS -1));
	if ((UINT_C_TYPE)s.ll < (UINT_C_TYPE)temp1.ll || (UINT_C_TYPE)s.ll < (UINT_C_TYPE)((INT_C_TYPE)1 << (FBITS - 1))) {
		r.ll += 1;
	}
#      if (FBITS == FIXED_WIDTH)
	s.ll = r.ll;
	r.ll = 0;
#      else
	s.ll = ((UINT_C_TYPE)s.ll) >> FBITS;
	temp1.ll = r.ll << (FIXED_WIDTH - FBITS);
	s.ll |= temp1.ll;
	r.ll >>= FBITS;
#      endif
	if (satp) { FIXED_SATURATE2(&r.ll, &s.ll); }
	z = (INT_C_TYPE)s.ll;
#      if HAVE_PADDING_BITS
	z <<= PADDING_BITS;
	z >>= PADDING_BITS;
#      endif
	memcpy_no_output(&c, &z, FIXED_SIZE);
	return c;
#   endif
}
#endif


#if (defined(FIXED_MUL) && defined(L_mul))
LIB_FUNC FIXED_C_TYPE FIXED_MUL(FIXED_C_TYPE a, FIXED_C_TYPE b) {
	return FIXED_MULHELPER(a, b, 0);
}
#endif


#if (defined(FIXED_SSMUL) && defined(L_ssmul))
LIB_FUNC FIXED_C_TYPE FIXED_SSMUL(FIXED_C_TYPE a, FIXED_C_TYPE b) {
	return FIXED_MULHELPER(a, b, 1);
}
#endif


#if (defined(FIXED_USMUL) && defined(L_usmul))
LIB_FUNC FIXED_C_TYPE FIXED_USMUL(FIXED_C_TYPE a, FIXED_C_TYPE b) {
	return FIXED_MULHELPER(a, b, 1);
}
#endif


#if (defined(FIXED_DIVHELPER) && defined(L_divhelper))
LIB_FUNC FIXED_C_TYPE FIXED_DIVHELPER(FIXED_C_TYPE a, FIXED_C_TYPE b, word_type satp) {
	FIXED_C_TYPE c;
	INT_C_TYPE x, y;
	INT_C_TYPE z;
#   ifdef DINT_C_TYPE
	DINT_C_TYPE dx, dy, dz;
	memcpy_no_output(&x, &a, FIXED_SIZE);
	memcpy_no_output(&y, &b, FIXED_SIZE);
	dx = (DINT_C_TYPE)x;
	dy = (DINT_C_TYPE)y;
	dx <<= FBITS;
	dz = dx / dy;
	if (satp) { FIXED_SATURATE1(&dz); }
	z = (INT_C_TYPE)dz;
#      if HAVE_PADDING_BITS
	z <<= PADDING_BITS;
	z >>= PADDING_BITS;
#      endif
	memcpy_no_output(&c, &z, FIXED_SIZE);
	return c;
#   else
	INT_C_TYPE pos_a, pos_b, r, s, quo_r, quo_s, mod, temp;
	word_type i;
#      if (MODE_UNSIGNED == 0)
	word_type num_of_neg = 0;
#      endif
	memcpy_no_output(&x, &a, FIXED_SIZE);
	memcpy_no_output(&y, &b, FIXED_SIZE);
	pos_a = x;
	pos_b = y;
#      if (MODE_UNSIGNED == 0)
	if (pos_a < 0) {
		pos_a = -pos_a;
		++num_of_neg;
	}
	if (pos_b < 0) {
		pos_b = -pos_b;
		++num_of_neg;
	}
#      endif
#      if (FBITS == FIXED_WIDTH)
	r = pos_a;
	s = 0;
#      else
	s = pos_a << FBITS;
	r = pos_a >> (FIXED_WIDTH - FBITS);
#      endif
	quo_r = (UINT_C_TYPE)r / (UINT_C_TYPE)pos_b;
	mod = (UINT_C_TYPE)r % (UINT_C_TYPE)pos_b;
	quo_s = 0;
	for (i = 0; i < FIXED_WIDTH; i++) {
		word_type leftmost_mode = (mod >> (FIXED_WIDTH - 1)) & 1;
		mod <<= 1;
		if ((s >> (FIXED_WIDTH - 1)) & 1) { ++mod; }
		quo_s <<= 1;
		temp = mod - pos_b;
		if (leftmost_mode || ((UINT_C_TYPE)mod >= (UINT_C_TYPE)pos_b)) {
			++quo_s;
			mod = temp;
		}
		s <<= 1;
	}
#      if (MODE_UNSIGNED == 0)
	if (num_of_neg == 1) {
		quo_s = -quo_s;
		if (quo_s == 0) { quo_r = -quo_r; }
		else { quo_r = ~quo_r; }
	}
#      endif
	if (satp) { FIXED_SATURATE2(&quo_r, &quo_s); }
	z = quo_s;
#      if HAVE_PADDING_BITS
	z <<= PADDING_BITS;
	z >>= PADDING_BITS;
#      endif
	memcpy_no_output(&c, &z, FIXED_SIZE);
	return c;
#   endif
}
#endif


#if (defined(FIXED_DIV) && defined(L_div))
LIB_FUNC FIXED_C_TYPE FIXED_DIV(FIXED_C_TYPE a, FIXED_C_TYPE b) {
	return FIXED_DIVHELPER(a, b, 0);
}
#endif


#if (defined(FIXED_UDIV) && defined(L_udiv))
LIB_FUNC FIXED_C_TYPE FIXED_UDIV(FIXED_C_TYPE a, FIXED_C_TYPE b) {
	return FIXED_DIVHELPER(a, b, 0);
}
#endif


#if (defined(FIXED_SSDIV) && defined(L_ssdiv))
LIB_FUNC FIXED_C_TYPE FIXED_SSDIV(FIXED_C_TYPE a, FIXED_C_TYPE b) {
	return FIXED_DIVHELPER(a, b, 1);
}
#endif


#if (defined(FIXED_USDIV) && defined(L_usdiv))
LIB_FUNC FIXED_C_TYPE FIXED_USDIV(FIXED_C_TYPE a, FIXED_C_TYPE b) {
	return FIXED_DIVHELPER(a, b, 1);
}
#endif


#if (defined(FIXED_NEG) && defined(L_neg))
LIB_FUNC FIXED_C_TYPE FIXED_NEG(FIXED_C_TYPE a) {
	FIXED_C_TYPE c;
	INT_C_TYPE x, z;
	memcpy_no_output(&x, &a, FIXED_SIZE);
	z = -x;
#   if HAVE_PADDING_BITS
	z <<= PADDING_BITS;
	z >>= PADDING_BITS;
#   endif
	memcpy_no_output(&c, &z, FIXED_SIZE);
	return c;
}
#endif


/* TODO: Add STDFIX FUNCTIONS
signed int mulir(signed int x, signed _Fract y);
signed long mulilr(signed long x, signed long _Fract y);
signed int mulik(signed int x, signed _Accum y);
signed long mulilk(signed long x, signed long _Accum y);
unsigned int muliur(unsigned int x, unsigned _Fract y);
unsigned long muliulr(unsigned long x, unsigned long _Fract y);
unsigned int muliuk(unsigned int x, unsigned _Accum y);
unsigned long muliulk(unsigned long x, unsigned long _Accum y);
signed int divir(signed int x, signed _Fract y);
signed long divilr(signed long x, signed long _Fract y);
signed int divik(signed int x, signed _Accum y);
signed long divilk(signed long x, signed long _Accum y);
unsigned int diviur(unsigned int x, unsigned _Fract y);
unsigned long diviulr(unsigned long x, unsigned long _Fract y);
unsigned int diviuk(unsigned int x, unsigned _Accum y);
unsigned long diviulk(unsigned long x, unsigned long _Accum y);
signed int idivr(signed _Fract x, signed _Fract y);
signed long idivlr(signed long _Fract x, signed long _Fract y);
signed int idivk(signed _Accum x, signed _Accum y);
signed long idivlk(signed long _Accum x, signed long _Accum y);
unsigned int idivur(unsigned _Fract x, unsigned _Fract y);
unsigned long idivulr(unsigned long _Fract x, unsigned long _Fract y);
unsigned int idivuk(unsigned _Accum x, unsigned _Accum y);
unsigned long idivulk(unsigned long _Accum x, unsigned long _Accum y);
signed _Fract rdivi(signed int x, signed int y);
signed long _Fract lrdivi(signed long x, signed long y);
signed _Accum kdivi(signed int x, signed int y);
signed long _Accum lkdivi(signed long x, signed long y);
unsigned _Fract urdivi(unsigned int x, unsigned int y);
unsigned long _Fract ulrdivi(unsigned long x, unsigned long y);
unsigned _Accum ukdivi(unsigned int x, unsigned int y);
unsigned long _Accum ulkdivi(unsigned long x, unsigned long y);
signed short _Fract abshr(signed short _Fract x);
signed _Fract absr(signed _Fract x);
signed long _Fract abslr(signed long _Fract x);
signed short _Accum abshk(signed short _Accum x);
signed _Accum absk(signed _Accum x);
signed long _Accum abslk(signed long _Accum x);
signed short _Fract roundhr(signed short _Fract x, int y);
signed _Fract roundr(signed _Fract x, int y);
signed long _Fract roundlr(signed long _Fract x, int y);
signed short _Accum roundhk(signed short _Accum x, int y);
signed _Accum roundk(signed _Accum x, int y);
signed long _Accum roundlk(signed long _Accum x, int y);
unsigned short _Fract rounduhr(unsigned short _Fract x, int y);
unsigned _Fract roundur(unsigned _Fract x, int y);
unsigned long _Fract roundulr(unsigned long _Fract x, int y);
unsigned short _Accum rounduhk(unsigned short _Accum x, int y);
unsigned _Accum rounduk(unsigned _Accum x, int y);
unsigned long _Accum roundulk(unsigned long _Accum x, int y);
int countlshr(signed short _Fract x);
int countlsr(signed _Fract x);
int countlslr(signed long _Fract x);
int countlshk(signed short _Accum x);
int countlsk(signed _Accum x);
int countlslk(signed long _Accum x);
int countlsuhr(unsigned short _Fract x);
int countlsur(unsigned _Fract x);
int countlsulr(unsigned long _Fract x);
int countlsuhk(unsigned short _Accum x);
int countlsuk(unsigned _Accum x);
int countlsulk(unsigned long _Accum x);
int_hr_t bitshr(signed short _Fract x);
int_r_t bitsr(signed _Fract x);
int_lr_t bitslr(signed long _Fract x);
int_hk_t bitshk(signed short _Accum x);
int_k_t bitsk(signed _Accum x);
int_lk_t bitslk(signed long _Accum x);
uint_uhr_t bitsuhr(unsigned short _Fract x);
uint_ur_t bitsur(unsigned _Fract x);
uint_ulr_t bitsulr(unsigned long _Fract x);
uint_uhk_t bitsuhk(unsigned short _Accum x);
uint_uk_t bitsuk(unsigned _Accum x);
uint_ulk_t bitsulk(unsigned long _Accum x);
signed short _Fract hrbits(int x);
signed _Fract rbits(int x);
signed long _Fract lrbits(int x);
signed short _Accum hkbits(int x);
signed _Accum kbits(int x);
signed long _Accum lkbits(int x);
unsigned short _Fract uhrbits(unsigned int x);
unsigned _Fract urbits(unsigned int x);
unsigned long _Fract ulrbits(unsigned int x);
unsigned short _Accum uhkbits(unsigned int x);
unsigned _Accum ukbits(unsigned int x);
unsigned long _Accum ulkbits(unsigned int x);
signed short _Fract strtofxhr(const char* restrict s, char** restrict endptr);
signed _Fract strtofxr(const char* restrict x, char** restrict endptr);
signed long _Fract strtofxlr(const char* restrict s, char** restrict endptr);
signed short _Accum strtofxhk(const char* restrict s, char** restrict endptr);
signed _Accum strtofxk(const char* restrict s, char** restrict endptr);
signed long _Accum strtofxlk(const char* restrict s, char** restrict endptr);
unsigned short _Fract strtofxuhr(const char* restrict s, char** restrict endptr);
unsigned _Fract strtofxur(const char* restrict s, char** restrict endptr);
unsigned long _Fract strtofxulr(const char* restrict s, char** restrict endptr);
unsigned short _Accum strtofxuhk(const char* restrict s, char** restrict endptr);
unsigned _Accum strtofxuk(const char* restrict s, char** restrict endptr);
unsigned long _Accum strtofxulk(const char* restrict s, char** restrict endptr);
fx-type absfx(fx-type x);
int countlsfx(fx-type x);
fx-type roundfx(fx-type x, int y);
fxvalue _Fixed_negate(fxmask1 mask, fxvalue x);
fxvalue _Fixed_incr(fxmask1 mask, fxvalue x);
fxvalue _Fixed_decr(fxmask1 mask, fxvalue x);
fxvalue _Fixed_add(fxmask2 mask, fxvalue x, fxvalue y);
fxvalue _Fixed_subtract(fxmask2 mask, fxvalue x, fxvalue y);
fxvalue _Fixed_multiply(fxmask2 mask, fxvalue x, fxvalue y);
fxvalue _Fixed_divide(fxmask2 mask, fxvalue x, fxvalue y);
int _Fixed_eq(fxmaskr mask, fxvalue x, fxvalue y);
int _Fixed_ne(fxmaskr mask, fxvalue x, fxvalue y);
int _Fixed_gt(fxmaskr mask, fxvalue x, fxvalue y);
int _Fixed_lt(fxmaskr mask, fxvalue x, fxvalue y);
int _Fixed_ge(fxmaskr mask, fxvalue x, fxvalue y);
int _Fixed_le(fxmask maskr, fxvalue x, fxvalue y);
fxvalue _Fixed_shiftl(fxmask1 mask, fxvalue x, int y);
fxvalue _Fixed_shiftr(fxmask1 mask, fxvalue x, int y);
fxvalue _Fixed_conv(fxmaskc mask, fxvalue x);
float _Fixed_to_float(fxmaskf mask, fxvalue x);
double _Fixed_to_double(fxmaskf mask, fxvalue x);
long double _Fixed_to_ldouble(fxmaskf mask, fxvalue x);
fxvalue _Fixed_from_float(fxmaskg mask, float x);
fxvalue _Fixed_from_double(fxmaskg mask, double x);
fxvalue _Fixed_from_ldouble(fxmaskg mask, long double x);
*/


#endif  // STDFIX_H


/* PRTYPES (<prtypes.h>) */


#if (!(defined(PRTYPES_H) || defined(_PRTYPES_H_)))
#define PRTYPES_H   (1)
#define _PRTYPES_H_   (1)


#ifdef WIN32


#define PR_EXPORT(__type)   extern __declspec(dllexport) __type
#define PR_EXPORT_DATA(__type)   extern __declspec(dllexport) __type
#define PR_IMPORT(__type)   __declspec(dllimport) __type
#define PR_IMPORT_DATA(__type)   __declspec(dllimport) __type
#define PR_EXTERN(__type)   extern __declspec(dllexport) __type
#define PR_IMPLEMENT(__type)   __declspec(dllexport) __type
#define PR_EXTERN_DATA(__type)   extern __declspec(dllexport) __type
#define PR_IMPLEMENT_DATA(__type)   __declspec(dllexport) __type
#define PR_CALLBACK
#define PR_CALLBACK_DECL
#define PR_STATIC_CALLBACK(__x)   static __x


#elif defined(XP_BEOS)


#define PR_EXPORT(__type)   extern __declspec(dllexport) __type
#define PR_EXPORT_DATA(__type)   extern __declspec(dllexport) __type
#define PR_IMPORT(__type)   extern __declspec(dllexport) __type
#define PR_IMPORT_DATA(__type)   extern __declspec(dllexport) __type
#define PR_EXTERN(__type)   extern __declspec(dllexport) __type
#define PR_IMPLEMENT(__type)   __declspec(dllexport) __type
#define PR_EXTERN_DATA(__type)   extern __declspec(dllexport) __type
#define PR_IMPLEMENT_DATA(__type)   __declspec(dllexport) __type
#define PR_CALLBACK
#define PR_CALLBACK_DECL
#define PR_STATIC_CALLBACK(__x)   static __x


#elif (defined(XP_OS2) && defined(__declspec))


#define PR_EXPORT(__type)   extern __declspec(dllexport) __type
#define PR_EXPORT_DATA(__type)   extern __declspec(dllexport) __type
#define PR_IMPORT(__type)   extern  __declspec(dllimport) __type
#define PR_IMPORT_DATA(__type)   extern __declspec(dllimport) __type
#define PR_EXTERN(__type)   extern __declspec(dllexport) __type
#define PR_IMPLEMENT(__type)   __declspec(dllexport) __type
#define PR_EXTERN_DATA(__type)   extern __declspec(dllexport) __type
#define PR_IMPLEMENT_DATA(__type)   __declspec(dllexport) __type
#define PR_CALLBACK
#define PR_CALLBACK_DECL
#define PR_STATIC_CALLBACK(__x)   static __x


#elif defined(OSSYMBIAN)


#define PR_EXPORT(__type)   extern __declspec(dllexport) __type
#define PR_EXPORT_DATA(__type)   extern __declspec(dllexport) __type
#   ifdef __WINS__
#      define PR_IMPORT(__type)   extern __declspec(dllexport) __type
#      define PR_IMPORT_DATA(__type)   extern __declspec(dllexport) __type
#   else
#      define PR_IMPORT(__type)   extern __declspec(dllimport) __type
#      define PR_IMPORT_DATA(__type)   extern __declspec(dllimport) __type
#   endif
#define PR_EXTERN(__type)   extern __type
#define PR_IMPLEMENT(__type)   __type
#define PR_EXTERN_DATA(__type)   extern __type
#define PR_IMPLEMENT_DATA(__type)   __type
#define PR_CALLBACK
#define PR_CALLBACK_DECL
#define PR_STATIC_CALLBACK(__x)   static __x


#else  // Unix


#   if AT_LEAST_GCC43
#      define PR_VISIBILITY_DEFAULT   __attribute__((__visibility__("default")))
#   else
#      define PR_VISIBILITY_DEFAULT
#   endif
#define PR_EXPORT(__type)   extern PR_VISIBILITY_DEFAULT __type
#define PR_EXPORT_DATA(__type)   extern PR_VISIBILITY_DEFAULT __type
#define PR_IMPORT(__type)   extern PR_VISIBILITY_DEFAULT __type
#define PR_IMPORT_DATA(__type)   extern PR_VISIBILITY_DEFAULT __type
#define PR_EXTERN(__type)   extern PR_VISIBILITY_DEFAULT __type
#define PR_IMPLEMENT(__type)   PR_VISIBILITY_DEFAULT __type
#define PR_EXTERN_DATA(__type)   extern PR_VISIBILITY_DEFAULT __type
#define PR_IMPLEMENT_DATA(__type)   PR_VISIBILITY_DEFAULT __type
#define PR_CALLBACK
#define PR_CALLBACK_DECL
#define PR_STATIC_CALLBACK(__x)   static __x


#endif


#ifdef _NSPR_BUILD_
#   define NSPR_API(__type)   PR_EXPORT(__type)
#   define NSPR_DATA_API(__type)   PR_EXPORT_DATA(__type)
#else
#   define NSPR_API(__type)   PR_IMPORT(__type)
#   define NSPR_DATA_API(__type)   PR_IMPORT_DATA(__type)
#endif


#define PR_BEGIN_MACRO   do {
#define PR_END_MACRO   } while (0x0)
#ifdef IS_CPLUSPLUS
#   define PR_BEGIN_EXTERN_C   extern "C" {
#   define PR_END_EXTERN_C   }
#else
#   define PR_BEGIN_EXTERN_C
#   define PR_END_EXTERN_C
#endif


#define PR_BIT(n)   ((PRUint32)1 << (n))
#define PR_BITMASK(n)   (PR_BIT(n) - 1)
#define PR_ROUNDUP(x, y)   ((((x) + ((y) - 1)) / (y)) * (y))
#define PR_MIN(x, y)   ((x) < (y) ? (x) : (y))
#define PR_MAX(x, y)   ((x) > (y) ? (x) : (y))
#define PR_ABS(x)   ((x) < 0 ? -(x) : (x))
#define PR_ARRAY_SIZE(a)   (sizeof(a) / sizeof((a)[0]))


#if (defined(_WIN64) || WORDSIZE_IS_64)
typedef PRUint64   PRUptrdiff;
#else
typedef unsigned long   PRUptrdiff;
#endif
#ifndef __PRUNICHAR__
#   define __PRUNICHAR__
#   ifdef WIN32
typedef wchar_t   PRUnichar;
#   else
typedef PRUint16   PRUnichar;
#   endif
#endif
#if (defined(_WIN64) || WORDSIZE_IS_64)
typedef PRInt64   PRWord;
typedef PRUint64   PRUword;
#else
typedef long   PRWord;
typedef unsigned long   PRUword;
#endif


#ifdef __clang_analyzer__
#   if __has_extension(attribute_analyzer_noreturn)
/** This attribute is useful for annotating assertion handlers that actually can return, but for the purpose of using the analyzer we want to pretend that such functions do not return */
#      define PR_PRETEND_NORETURN   __attribute__((analyzer_noreturn))
#   endif
#endif
#ifndef PR_PRETEND_NORETURN
#   define PR_PRETEND_NORETURN
#endif

#ifndef NO_NSPR_10_SUPPORT

#   define PR_PUBLIC_API   PR_IMPLEMENT
#   define NSPR_BEGIN_MACRO   do {
#   define NSPR_END_MACRO   } while (0x0)
#   ifdef NSPR_BEGIN_EXTERN_C
#      undef NSPR_BEGIN_EXTERN_C
#   endif
#   ifdef NSPR_END_EXTERN_C
#      undef NSPR_END_EXTERN_C
#   endif
#   if IS_CPLUSPLUS
#      define NSPR_BEGIN_EXTERN_C   extern "C" {
#      define NSPR_END_EXTERN_C   }
#   else
#      define NSPR_BEGIN_EXTERN_C
#      define NSPR_END_EXTERN_C
#   endif
#endif

#define PR_STATIC_ASSERT(condition)   extern void pr_static_assert(int arg[(condition) ? 1 : -1])


#endif  // PRTYPES_H


/* CTYPE MACROS (<ctype.h>) */


#if (!(defined(CTYPE_H) || defined(_CTYPE_H) || defined(_CTYPE_H_) || defined(_CTYPE_INLINE_H_) || defined(_CTYPE_LOCAL_H_) || defined(_SYS_CTYPE_BITS_H_) || defined(_LINUX_CTYPE_H) || defined(_PDCLIB_CTYPE_H) || defined(_CITRUS_CTYPE_LOCAL_H_) || defined(SAFE_CTYPE_H)))  // http://www.cplusplus.com/reference/cctype/
#define CTYPE_H   (1)
#define _CTYPE_H   (1)
#define _CTYPE_H_   (1)
#define _CTYPE_INLINE_H_   (1)
#define _CTYPE_LOCAL_H_   (1)
#define _SYS_CTYPE_BITS_H_   (1)
#define _LINUX_CTYPE_H   (1)
#define _PDCLIB_CTYPE_H   (1)
#define _CITRUS_CTYPE_LOCAL_H_   (1)
#define SAFE_CTYPE_H   (1)


/** Alpha */
#define _CTYPE_A   1
/** Control */
#define _CTYPE_C   2
/** Digit */
#define _CTYPE_D   4
/** Graph */
#define _CTYPE_G   8
/** Lower */
#define _CTYPE_L   0x10
/** Punct */
#define _CTYPE_P   0x20
/** Space */
#define _CTYPE_S   0x40
/** Upper */
#define _CTYPE_U   0x80
/** X digit */
#define _CTYPE_X   0x100
/** Blank */
#define _CTYPE_BL   0x200
/** Print */
#define _CTYPE_R   0x400
/** Ideogram */
#define _CTYPE_I   0x800
/** Special */
#define _CTYPE_T   0x1000
/** Phonogram */
#define _CTYPE_Q   0x2000
#define CTYPE_NUM_CHARS   256
#define _CTYPE_NUM_CHARS   (1 << CHAR_BIT)
#define _CTYPE_CACHE_SIZE   0x100
#define _PDCLIB_CTYPE_ALPHA   1
#define _PDCLIB_CTYPE_BLANK   2
#define _PDCLIB_CTYPE_CNTRL   4
#define _PDCLIB_CTYPE_GRAPH   8
#define _PDCLIB_CTYPE_PUNCT   16
#define _PDCLIB_CTYPE_SPACE   32
#define _PDCLIB_CTYPE_LOWER   64
#define _PDCLIB_CTYPE_UPPER   128
#define _PDCLIB_CTYPE_DIGIT   256
#define _PDCLIB_CTYPE_XDIGT   512


// LC_CTYPE specific; Indices for standard wide character translation mappings
#define __TOW_toupper   (0)
#define __TOW_tolower   (1)
/** LC_CTYPE specific; Access a wide character class with a single character index; c must be an `unsigned char`; desc must be a nonzero wctype_t */
#define _ISCTYPE(c, desc)   (((((const uint32_t*)(desc)) - 8)[(c) >> 5] >> ((c) & 0x1F)) & 1)
#define IS_CODEUNIT(c)   (((unsigned)(c) - 0xdf80) < 0x80)

enum __encoding { CT_8BIT, CT_UTF8 };
static enum __encoding lc_ctype = CT_UTF8;

typedef enum ctype_encoding {
	__ctype_encoding_7_bit,  // C/POSIX
	__ctype_encoding_utf8,  // UTF-8
	__ctype_encoding_8_bit  // for 8-bit codeset locales
} ctype_encoding_t;

typedef enum IS_ctype {
	_ISupper = _ISbit(0),  // UPPERCASE (A-Z)
	_ISlower = _ISbit(1),  // lowercase (a-z)
	_ISalpha = _ISbit(2),  // Alphabetic (A-Za-z)
	_ISdigit = _ISbit(3),  // Numeric (0-9)
	_ISxdigit = _ISbit(4),  // Hexadecimal numeric (A-Fa-f0-9)
	_ISspace = _ISbit(5),  // Whitespace (space \t \n \r \f \v)
	_ISprint = _ISbit(6),  // Printable characters
	_ISgraph = _ISbit(7),  // Graphical
	_ISblank = _ISbit(8),  // Blank (space and tab)
	_IScntrl = _ISbit(9),  // Control character
	_ISpunct = _ISbit(10),  // Punctuation
	_ISalnum = _ISbit(11),  // Alphanumeric
} IS_ctype_t;

/** Character Categories */
typedef enum CHAR_CLASSIFICATION {
	// C99
	cc_isblank = 1,  // space \t
	cc_iscntrl = 2,  // nonprinting characters
	cc_isdigit = 4,  // 0-9
	cc_islower = 8,  // a-z
	cc_isprint = 0x10,  // any printing character including ' '
	cc_ispunct = 0x20,  // all punctuation
	cc_isspace = 0x40,  // space \t \n \r \f \v
	cc_isupper = 0x80,  // A-Z
	cc_isxdigit = 0x100,  // 0-9A-Fa-f
	// Extra categories
	cc_isidst = 0x200,  // A-Za-z_
	cc_isvsp = 0x400,  // \n \r
	cc_isnvsp = 0x800,  // space \t \f \v \0
	// Combinations
	cc_isalpha = cc_isupper | cc_islower,  // A-Za-z
	cc_isalnum = cc_isalpha | cc_isdigit,  // A-Za-z0-9
	cc_isidnum = cc_isidst | cc_isdigit,  // A-Za-z0-9_
	cc_isgraph = cc_isalnum | cc_ispunct,  // isprint (without space)
	cc_iscppsp = cc_isvsp | cc_isnvsp,  // isspace + \0
	cc_isbasic = cc_isprint | cc_iscppsp  // Basic charset of ISO C (plus ` and @)
} CHAR_CLASSIFICATION_t;

// Shorthand
#define cc_bl   cc_isblank
#define cc_cn   cc_iscntrl
#define cc_di   cc_isdigit
#define cc_is   cc_isidst
#define cc_lo   cc_islower
#define cc_nv   cc_isnvsp
#define cc_pn   cc_ispunct
#define cc_pr   cc_isprint
#define cc_sp   cc_isspace
#define cc_up   cc_isupper
#define cc_vs   cc_isvsp
#define cc_xd   cc_isxdigit
// Masks
/** Lower case letter */
#define cc_L   ((unsigned short)(cc_lo | cc_is | cc_pr))
/** Lowercase hex digit */
#define cc_XL   ((unsigned short)(cc_lo | cc_is | cc_xd | cc_pr))
/** Upper case letter */
#define cc_U   ((unsigned short)(cc_up | cc_is | cc_pr))
/** Uppercase hex digit */
#define cc_XU   ((unsigned short)(cc_up | cc_is | cc_xd | cc_pr))
/** Decimal digit */
#define cc_D   ((unsigned short)(cc_di | cc_xd | cc_pr))
/** Punctuation */
#define cc_P   ((unsigned short)(cc_pn | cc_pr))
/** Underscore */
#define cc__   ((unsigned short)(cc_pn | cc_is | cc_pr))
/** Control character */
#define cc_C   ((unsigned short)(cc_cn))
/** NUL */
#define cc_Z   ((unsigned short)(cc_nv | cc_cn))
/** Cursor movement: `\f` & `\v` */
#define cc_M   ((unsigned short)(cc_nv | cc_sp | cc_cn))
/** Vertical space: `\r` & `\n` */
#define cc_V   ((unsigned short)(cc_vs | cc_sp | cc_cn))
/** Tab */
#define cc_T   ((unsigned short)(cc_nv | cc_sp | cc_bl | cc_cn))
/** Space */
#define cc_S   ((unsigned short)(cc_nv | cc_sp | cc_bl | cc_pr))

#if (HOST_CHARSET == HOST_CHARSET_ASCII)  // Is this ASCII?

static const UNUSED unsigned short cc_istable[256] = {
	cc_Z, cc_C, cc_C, cc_C, cc_C, cc_C, cc_C, cc_C,  // NUL SOH STX ETX  EOT ENQ ACK BEL
	cc_C, cc_T, cc_V, cc_M, cc_M, cc_V, cc_C, cc_C,  // BS  HT  LF  VT FF  CR  SO  SI
	cc_C, cc_C, cc_C, cc_C, cc_C, cc_C, cc_C, cc_C,  // DLE DC1 DC2 DC3  DC4 NAK SYN ETB
	cc_C, cc_C, cc_C, cc_C, cc_C, cc_C, cc_C, cc_C,  // CAN EM  SUB ESC  FS  GS  RS  US
	cc_S, cc_P, cc_P, cc_P, cc_P, cc_P, cc_P, cc_P,  // SP  ! " #  $ % & '
	cc_P, cc_P, cc_P, cc_P, cc_P, cc_P, cc_P, cc_P,  // ( ) * +  , - . /
	cc_D, cc_D, cc_D, cc_D, cc_D, cc_D, cc_D, cc_D,  // 0 1 2 3  4 5 6 7
	cc_D, cc_D, cc_P, cc_P, cc_P, cc_P, cc_P, cc_P,  // 8 9 : ;  < = > ?
	cc_P, cc_XU, cc_XU, cc_XU, cc_XU, cc_XU, cc_XU, cc_U,  // @ A B C  cc_D E F G
	cc_U, cc_U, cc_U, cc_U, cc_U, cc_U, cc_U, cc_U,  // H I J K  L M N O
	cc_U, cc_U, cc_U, cc_U, cc_U, cc_U, cc_U, cc_U,  // P Q R S  T U V W
	cc_U, cc_U, cc_U, cc_P, cc_P, cc_P, cc_P, cc__,  // X Y Z [  \ ] ^ _
	cc_P, cc_XL, cc_XL, cc_XL, cc_XL, cc_XL, cc_XL, cc_L,  // ` a b c  d e f g
	cc_L, cc_L, cc_L, cc_L, cc_L, cc_L, cc_L, cc_L,  // h i j k  l m n o
	cc_L, cc_L, cc_L, cc_L, cc_L, cc_L, cc_L, cc_L,  // p q r s  t u v w
	cc_L, cc_L, cc_L, cc_P, cc_P, cc_P, cc_P, cc_C,  // x y z {  | } ~ DEL
	// High half of unsigned char is locale-specific, so all tests are false in "C" locale
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static const UNUSED unsigned char cc_tolower[256] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
	16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
	32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
	48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
	'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	91, 92, 93, 94, 95, 96,
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
	'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	123, 124, 125, 126, 127,
	128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143,
	144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
	160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175,
	176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191,
	192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207,
	208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223,
	224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
	240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255
};

static const UNUSED unsigned char cc_toupper[256] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
	16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
	32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
	48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	91, 92, 93, 94, 95, 96,
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	123, 124, 125, 126, 127,
	128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143,
	144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
	160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175,
	176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191,
	192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207,
	208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223,
	224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
	240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255
};

#elif (HOST_CHARSET == HOST_CHARSET_EBCDIC)
#   error   "FIXME: Write tables for EBCDIC!"
#else
#   error   "Unrecognized host character set!"
#endif

/** Test if the char is an ASCII symbol */
#define ISASCII(c)   ((c) < 0x80)
/** Test if the char is an ASCII symbol */
#define __isascii(c)   ISASCII((c))
/** Test if the char is an ASCII symbol */
#define isascii(c)   ISASCII((c))
/** Mask off high bits */
#define __toascii(c)   ((c) & 0x7F)
/** Convert the char to an ASCII character */
#define TOASCII(c)   __toascii((c))
/** Convert the char to an ASCII character */
#define toascii(c)   TOASCII((c))
#define to_char(c)   (((unsigned)((c) - '0') <= 9) ? (char)((c) + '0') : (char)(c))
/** Convert the char to a lowercase ASCII letter */
LIB_FUNC int _tolower(const int symbol) {
	if (((0x40 < symbol) & (symbol < 0x5B))) {
		return (int)(symbol + 0x20);
	} else { return symbol; }
}
/** Convert the char to a lowercase ASCII letter */
#define TOLOWER(c)   _tolower((c))
/** Convert the char to a lowercase ASCII letter */
#define tolower(c)   _tolower((c))
/** Convert the char to a lowercase ASCII letter */
#define tolower_l(c, l)   _tolower((c))
/** Convert the char to a lowercase ASCII letter */
#define __tolower_l(c, l)   _tolower((c))
/** Convert the char to a uppercase ASCII letter */
LIB_FUNC int _toupper(const int symbol) {
	if (((0x60 < symbol) & (symbol < 0x7B))) {
		return (int)(symbol - 0x20);
	} else { return symbol; }
}
/** Convert the char to a uppercase ASCII letter */
#define TOUPPER(c)   _toupper((c))
/** Convert the char to a uppercase ASCII letter */
#define toupper(c)   _toupper((c))
/** Convert the char to a uppercase ASCII letter */
#define toupper_l(c, l)   _toupper((c))
/** Convert the char to a uppercase ASCII letter */
#define __toupper_l(c, l)   _toupper((c))
/** Test if the char is a digit */
#define is_digit(c)   (((0x2F < (c)) & ((c) < 0x3A)))
/** Test if the char is a digit */
#define ISDIGIT(c)   is_digit((c))
/** Test if the char is a digit */
#define isdigit(c)   is_digit((c))
/** Test if the char is a digit */
#define __isdigit_char(c)   is_digit((c))
/** Test if the char is a digit */
#define isdigit_char(c)   is_digit((c))
/** Test if the char is a digit */
#define __isdigit_int(c)   is_digit((c))
/** Test if the char is a digit */
#define isdigit_int(c)   is_digit((c))
/** Test if the character is an octal character (0-7) */
#define ISOCTAL(c)   ((c) >= '0' && (c) <= '7')
/** Test if the character is an octal character (0-7) */
#define isoctal(c)   ISOCTAL((c))
/** Test if the char is NULL ('\0') */
#define ISNUL(c)   ((c) == 0)
/** Test if the char is NULL ('\0') */
#define isnul(c)   ISNUL((c))
/** Test if the char is NULL ('\0') */
#define ISNULL(c)   ISNUL((c))
/** Test if the char is NULL ('\0') */
#define isnull(c)   ISNUL((c))
/** Test if the char is STX (Start of Text) */
#define ISSTX(c)   ((c) == 1)
/** Test if the char is STX (Start of Text) */
#define isstx(c)   ISSTX((c))
/** Test if the char is ETX (End of Text) */
#define ISETX(c)   ((c) == 2)
/** Test if the char is ETX (End of Text) */
#define isetx(c)   ISETX((c))
/** Test if the char is EOT (End of Transmission) */
#define ISEOT(c)   ((c) == 3)
/** Test if the char is EOT (End of Transmission) */
#define iseot(c)   ISEOT((c))
/** Test if the char is the bell character (\b) */
#define ISBELL(c)   ((c) == 7)
/** Test if the char is the bell character (\b) */
#define isbell(c)   ISBELL((c))
/** Test if the char is a device control character */
#define ISDEVCHAR(c)   (((c) >= 0x11) && ((c) <= 0x14))
/** Test if the char is a device control character */
#define isdevchar(c)   ISDEVCHAR((c))
/** Test if the char is a separator character */
#define ISSEPCHAR(c)   (((c) >= 0x1C) && ((c) <= 0x1F))
/** Test if the char is a separator character */
#define issepchar(c)   ISSEPCHAR((c))
/** Test if the char is the DEL character */
#define ISDEL(c)   ((c) == 0x7F)
/** Test if the char is the DEL character */
#define isdel(c)   ISDEL((c))
/** Test if the char is EOF */
#define ISEOF(c)   (((c) == EOF) ? 1 : 0)
/** Test if the char is EOF */
#define iseof(c)   ISEOF((c))
/** Test if the char is EOF */
#define __ISEOF(c)   ISEOF((c))
/** Test if the char is EOF */
#define __iseof(c)   ISEOF((c))
/** Test if the char is alphanumeric */
#define ISALNUM(c)   ((int)(((0x60 < (c)) & ((c) < 0x7B)) | ((0x40 < (c)) & ((c) < 0x5B)) | ((0x2F < (c)) & ((c) < 0x3A))))
/** Test if the char is alphanumeric */
#define ISALPHANUM(c)   ISALNUM((c))
/** Test if the char is alphanumeric */
#define isalphanum(c)   ISALNUM((c))
/** Test if the char is alphanumeric */
#define isalnum(c)   ISALNUM((c))
/** Test if the char is alphanumeric */
#define isalnum_l(c, l)   ISALNUM((c))
/** Test if the char is an alphabetic ASCII letter */
#define ISALPHA(c)   ((int)(((0x60 < (c)) & ((c) < 0x7B)) | ((0x40 < (c)) & ((c) < 0x5B))))
/** Test if the char is an alphabetic ASCII letter */
#define isalpha(c)   ISALPHA((c))
/** Test if the char is an alphabetic ASCII letter */
#define isalpha_l(c, l)   ISALPHA((c))
/** Test if the char is a space or tab (\t) character */
#define ISBLANK(c)   (((c) == 0x20) | ((c) == 9))
/** Test if the char is a space or tab (\t) character */
#define isblank(c)   ISBLANK((c))
/** Test if the char is a control character */
#define ISCNTRL(c)   (((c) < 0x20) | (0x7F == (c)))
/** Test if the char is a control character */
#define iscntrl(c)   ISCNTRL((c))
/** Test if the char is a C++ space character (tab, newline, vertical tab, form feed, carriage return, space, and '\0') */
#define ISCPPSP(c)   (((c) == 0x20) | ((c) == 0) | ((8 < (c)) & ((c) < 0xEu)))
/** Test if the char is a C++ space character (isspace + '\0') */
#define iscppsp(c)   ISCPPSP((c))
/** Test if the char is a currency symbol */
#define ISCURRENCY(c)   (((c) == 0x24) | ((0xA1 < (c)) & ((c) < 0xA6)))
/** Test if the char is a currency symbol */
#define iscurrency(c)   ISCURRENCY((c))
/** Test if the char is an alphabetic letter in the Latin-1 Supplement block */
#define ISEXTALPHA(c)   ((((0xBF < (c)) & ((c) < 0xD7)) | ((0xD7 < (c)) & ((c) < 0xDF))) | (((0xDE < (c)) & ((c) < 0xF7)) | ((0xF7 < (c)))) | ((0xF7 < (c))))
/** Test if the char is an alphabetic letter in the Latin-1 Supplement block */
#define isextalpha(c)   ISEXTALPHA((c))
/** Test if the char is a control character (includes Latin-1 Supplement block) */
#define ISEXTCNTRL(c)   (((c) < 0x20) | ((0x7E < (c)) & ((c) < 0xA0)))
/** Test if the char is a control character (includes Latin-1 Supplement block) */
#define isextcntrl(c)   ISEXTCNTRL((c))
/** Test if the char is a lowercase alphabetic letter in the Latin-1 Supplement block */
#define ISEXTLOWER(c)   (((0xDE < (c)) & ((c) < 0xF7)) | ((0xF7 < (c))))
/** Test if the char is a lowercase alphabetic letter in the Latin-1 Supplement block */
#define isextlower(c)   ISEXTLOWER((c))
/** Test if the char is a uppercase alphabetic letter in the Latin-1 Supplement block */
#define ISEXTUPPER(c)   (((0xBF < (c)) & ((c) < 0xD7)) | ((0xD7 < (c)) & ((c) < 0xDF)))
/** Test if the char is a uppercase alphabetic letter in the Latin-1 Supplement block */
#define isextupper(c)   ISEXTUPPER((c))
/** Test if the char is a graphical character (alphanumeric and punctuation characters) */
#define ISGRAPH(c)   ((0x20 < (c)) & ((c) < 0x7F))
/** Test if the char is a graphical character (alphanumeric and punctuation characters) */
#define isgraph(c)   ISGRAPH((c))
/** Test if the char is an alphabetic character or "_" */
#define ISIDST(c)   (((0x60 < (c)) & ((c) < 0x7B)) | ((0x40 < (c)) & ((c) < 0x5B)) | ((c) == 0x5F))
/** Test if the char is an alphabetic character or "_" */
#define isidst(c)   ISIDST((c))
/** Test if the char is an alphanumeric character or "_" */
#define ISIDNUM(c)   (ISIDST((c)) | ISDIGIT((c)))
/** Test if the char is an alphanumeric character or "_" */
#define isidnum(c)   ISIDNUM((c))
/** Test if the char is a punctuation character (! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~) */
#define ISPUNCT(c)   (((0x20 < (c)) & ((c) < 0x30)) | ((0x39 < (c)) & ((c) < 0x41)) | ((0x5A < (c)) & ((c) < 0x61)) | ((0x7A < (c)) & ((c) < 0x7F)))
/** Test if the char is a punctuation character (! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~) */
#define ispunct(c)   ISPUNCT((c))
/** Test if the char is a separator control character */
#define ISSEPARATOR(c)   ((0x1B < (c)) & ((c) < 0x20))
/** Test if the char is a separator control character */
#define isseparator(c)   ISSEPARATOR((c))
/** Test if the char is a space character (tab, newline, vertical tab, form feed, carriage return, and space) */
#define ISSPACE(c)   (((c) == 0x20) | ((8 < (c)) & ((c) < 0xE)))
/** Test if the char is a space character (tab, newline, vertical tab, form feed, carriage return, and space) */
#define isspace(c)   ISSPACE((c))
/** Return true if symbol is a space in the current locale, avoiding problems with signed char and isspace */
LIB_FUNC bool locale_isspace(const char symbol) {
	register unsigned char uc = (unsigned char)symbol;
	return (bool)(isspace(uc) != 0);
}
/** Test if the char is a space character or NULL */
#define IS_SPACE_OR_NUL(c)   (((c) == 0x20) | ((c) == 0))
/** Test if the char is a space character or NULL */
#define ISSPACEORNUL(c)   IS_SPACE_OR_NUL((c))
/** Test if the char is a space character or NULL */
#define ISSPACEORNULL(c)   IS_SPACE_OR_NUL((c))
/** Test if the char is a space character or NULL */
#define isspaceornull(c)   IS_SPACE_OR_NUL((c))
/** Test if the char is a space character or NULL */
#define is_space_or_nul(c)   IS_SPACE_OR_NUL((c))
/** Test if the char is a lowercase ASCII character */
#define ISLOWERASCII(c)   ((0x60 < (c)) & ((c) < 0x7B))
/** Test if the char is a lowercase ASCII character */
#define islowerascii(c)   ISLOWERASCII((c))
/** Test if the char is a lowercase character */
#define ISLOWER(c)   ISLOWERASCII((c))
/** Test if the char is a lowercase character */
#define islower(c)   ISLOWERASCII((c))
/** Test if the char is space, '\t', '\f', '\v', or '\0' */
#define ISNVSP(c)   (((c) == 9) | ((c) == 0xB) | ((c) == 0xC) | ((c) == 0))
/** Test if the char is space, '\t', '\f', '\v', or '\0' */
#define isnvsp(c)   ISNVSP((c))
/** Test if the char is '\n' or '\r' */
#define ISVSP(c)   (((c) == 0xA) | ((c) == 0xD))
/** Test if the char is '\n' or '\r' */
#define isvsp(c)   ISVSP((c))
/** Test if the char is a uppercase ASCII character */
#define ISUPPERASCII(c)   ((0x40 < (c)) & ((c) < 0x5B))
/** Test if the char is a uppercase ASCII character */
#define isupperascii(c)   ISUPPERASCII((c))
/** Test if the char is a uppercase character */
#define ISUPPER(c)   (((0x40 < (c)) & ((c) < 0x60)) | ((0xBF < (c)) & ((c) < 0xD7)) | ((0xD7 < (c)) & ((c) < 0xDF)))  // All letters under 0xFF
/** Test if the char is a uppercase character */
#define isupper(c)   ISUPPER((c))  // All letters under 0xFF
/** Test if the char is a hexadecimal digit */
#define ISXDIGIT(c)   ((((0x2F < (c)) & ((c) < 0x3A))) | ((0x40 < (c)) & ((c) < 0x47)) | ((0x60 < (c)) & ((c) < 0x67)))
/** Test if the char is a hexadecimal digit */
#define isxdigit(c)   ISXDIGIT((c))
/** Test if the char is a printable character (alphanumeric, punctuation, and space characters) */
#define ISPRINT(c)   (ISALNUM((c)) | ISSPACE((c)) | ISPUNCT((c)))
/** Test if the char is a printable character (alphanumeric, punctuation, and space characters) */
#define isprint(c)   ISPRINT((c))
/** Test if the char is a basic ISO-C character */
#define ISBASIC(c)   (ISALNUM((c)) | ISSPACE((c)) | ISPUNCT((c)) | ISNULL((c)))
/** Test if the char is a basic ISO-C character */
#define isbasic(c)   ISBASIC((c))


LIB_FUNC int isdirect(const uint32_t ch) {
	return (int)(ch < 128 && ((direct_tab[ch >> 3] >> (ch & 7)) & 1));
}


LIB_FUNC int isxdirect(const uint32_t ch) {
	return (int)(ch < 128 && ((xdirect_tab[ch >> 3] >> (ch & 7)) & 1));
}


LIB_FUNC int isxbase64(const uint32_t ch) {
	return (int)(ch < 128 && ((xbase64_tab[ch >> 3] >> (ch & 7)) & 1));
}


#endif  // CTYPE_H


/* WIDE-CHARACTER CLASSIFICATION & MAPPING UTILITIES (<wctype.h>) */


#if (!(defined(WCTYPE_H) || defined(WCTYPE_H_) || defined(_WCTYPE_H) || defined(_WCTYPE_H_) || defined(__WCTYPE_H) || defined(_INC_WCTYPE) || defined(_LIBC_WCTYPE_H_)))  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/wctype.h.html & http://www.cplusplus.com/reference/cwctype/
#define WCTYPE_H   (1)
#define WCTYPE_H_   (1)
#define _WCTYPE_H   (1)
#define _WCTYPE_H_   (1)
#define __WCTYPE_H   (1)
#define _INC_WCTYPE   (1)
#define _LIBC_WCTYPE_H_   (1)
#define __iswxxx_defined   (1)
#undef __need_iswxxx


typedef struct wcinfo {
	wint_t start;
	uint16_t length, flags;
	wint_t lower_delta, upper_delta;
} wcinfo_t;


#define CASEMAP(u1, u2, l)   { (u1), ((l) - (u1)), ((u2) - (u1) + 1) }
#define CASELACE(u1, u2)   CASEMAP((u1), (u2), ((u1) + 1))


struct wcasemaps {
	unsigned short upper;
	signed char lower;
	unsigned char len;
} wchar_casemaps[] = {
	CASEMAP('A', 'Z', 'a'),
	CASEMAP(0xc0, 0xde, 0xe0),
	CASELACE(0x100, 0x12e),
	CASELACE(0x132, 0x136),
	CASELACE(0x139, 0x147),
	CASELACE(0x14a, 0x176),
	CASELACE(0x179, 0x17d),
	CASELACE(0x370, 0x372),
	CASEMAP(0x391, 0x3a1, 0x3b1),
	CASEMAP(0x3a3, 0x3ab, 0x3c3),
	CASEMAP(0x400, 0x40f, 0x450),
	CASEMAP(0x410, 0x42f, 0x430),
	CASELACE(0x460, 0x480),
	CASELACE(0x48a, 0x4be),
	CASELACE(0x4c1, 0x4cd),
	CASELACE(0x4d0, 0x50e),
	CASELACE(0x514, 0x526),
	CASEMAP(0x531, 0x556, 0x561),
	CASELACE(0x1a0, 0x1a4),
	CASELACE(0x1b3, 0x1b5),
	CASELACE(0x1cd, 0x1db),
	CASELACE(0x1de, 0x1ee),
	CASELACE(0x1f8, 0x21e),
	CASELACE(0x222, 0x232),
	CASELACE(0x3d8, 0x3ee),
	CASELACE(0x1e00, 0x1e94),
	CASELACE(0x1ea0, 0x1efe),
	CASEMAP(0x1f08, 0x1f0f, 0x1f00),
	CASEMAP(0x1f18, 0x1f1d, 0x1f10),
	CASEMAP(0x1f28, 0x1f2f, 0x1f20),
	CASEMAP(0x1f38, 0x1f3f, 0x1f30),
	CASEMAP(0x1f48, 0x1f4d, 0x1f40),
	CASEMAP(0x1f68, 0x1f6f, 0x1f60),
	CASEMAP(0x1f88, 0x1f8f, 0x1f80),
	CASEMAP(0x1f98, 0x1f9f, 0x1f90),
	CASEMAP(0x1fa8, 0x1faf, 0x1fa0),
	CASEMAP(0x1fb8, 0x1fb9, 0x1fb0),
	CASEMAP(0x1fba, 0x1fbb, 0x1f70),
	CASEMAP(0x1fc8, 0x1fcb, 0x1f72),
	CASEMAP(0x1fd8, 0x1fd9, 0x1fd0),
	CASEMAP(0x1fda, 0x1fdb, 0x1f76),
	CASEMAP(0x1fe8, 0x1fe9, 0x1fe0),
	CASEMAP(0x1fea, 0x1feb, 0x1f7a),
	CASEMAP(0x1ff8, 0x1ff9, 0x1f78),
	CASEMAP(0x1ffa, 0x1ffb, 0x1f7c),
	CASELACE(0x246, 0x24e),
	CASELACE(0x510, 0x512),
	CASEMAP(0x2160, 0x216f, 0x2170),
	CASEMAP(0x2c00, 0x2c2e, 0x2c30),
	CASELACE(0x2c67, 0x2c6b),
	CASELACE(0x2c80, 0x2ce2),
	CASELACE(0x2ceb, 0x2ced),
	CASELACE(0xa640, 0xa66c),
	CASELACE(0xa680, 0xa696),
	CASELACE(0xa722, 0xa72e),
	CASELACE(0xa732, 0xa76e),
	CASELACE(0xa779, 0xa77b),
	CASELACE(0xa77e, 0xa786),
	CASELACE(0xa790, 0xa792),
	CASELACE(0xa7a0, 0xa7a8),
	CASEMAP(0xff21, 0xff3a, 0xff41),
	{ 0, 0, 0 }
};


static const UNUSED wchar_t wempty[] = L"";


#include "wctype_table.h"


static const UNUSED unsigned char alpha_table[] = {
#   include "alpha.def"
};


static const UNUSED unsigned char nonspacing_table[] = {
#   include "nonspacing.def"
};


static const UNUSED unsigned char punct_table[] = {
#   include "punct.def"
};


static const UNUSED unsigned char wide_table[] = {
#   include "wide.def"
};


static const UNUSED char* const wchar_properties[WC_TYPE_MAX] = {
	"<invalid>", "alnum", "alpha", "blank", "cntrl", "digit", "graph", "lower", "print", "punct", "space", "upper", "xdigit"
};


static const UNUSED char wchar_class_names[128] = "alnum\0" "alpha\0" "blank\0" "cntrl\0" "digit\0" "graph\0" "lower\0" "print\0" "punct\0" "space\0" "upper\0" "xdigit";


/** This definition of whitespace is the Unicode White_Space property, minus non-breaking spaces (U+00A0, U+2007, and U+202F) and script-specific characters with non-blank glyphs (U+1680 and U+180E) */
static const UNUSED wchar_t wchar_spaces[32] = { ' ', '\t', '\n', '\r', 11, 12, 0x85, 0x2000, 0x2001, 0x2002, 0x2003, 0x2004, 0x2005, 0x2006, 0x2008, 0x2009, 0x200a, 0x2028, 0x2029, 0x205f, 0x3000, 0x0 };


static const UNUSED unsigned short wchar_pairs[128][2] = {
	{ 'I',  0x131 },
	{ 'S', 0x17f },
	{ 0x130, 'i' },
	{ 0x178, 0xff },
	{ 0x181, 0x253 },
	{ 0x182, 0x183 },
	{ 0x184, 0x185 },
	{ 0x186, 0x254 },
	{ 0x187, 0x188 },
	{ 0x189, 0x256 },
	{ 0x18a, 0x257 },
	{ 0x18b, 0x18c },
	{ 0x18e, 0x1dd },
	{ 0x18f, 0x259 },
	{ 0x190, 0x25b },
	{ 0x191, 0x192 },
	{ 0x193, 0x260 },
	{ 0x194, 0x263 },
	{ 0x196, 0x269 },
	{ 0x197, 0x268 },
	{ 0x198, 0x199 },
	{ 0x19c, 0x26f },
	{ 0x19d, 0x272 },
	{ 0x19f, 0x275 },
	{ 0x1a6, 0x280 },
	{ 0x1a7, 0x1a8 },
	{ 0x1a9, 0x283 },
	{ 0x1ac, 0x1ad },
	{ 0x1ae, 0x288 },
	{ 0x1af, 0x1b0 },
	{ 0x1b1, 0x28a },
	{ 0x1b2, 0x28b },
	{ 0x1b7, 0x292 },
	{ 0x1b8, 0x1b9 },
	{ 0x1bc, 0x1bd },
	{ 0x1c4, 0x1c6 },
	{ 0x1c4, 0x1c5 },
	{ 0x1c5, 0x1c6 },
	{ 0x1c7, 0x1c9 },
	{ 0x1c7, 0x1c8 },
	{ 0x1c8, 0x1c9 },
	{ 0x1ca, 0x1cc },
	{ 0x1ca, 0x1cb },
	{ 0x1cb, 0x1cc },
	{ 0x1f1, 0x1f3 },
	{ 0x1f1, 0x1f2 },
	{ 0x1f2, 0x1f3 },
	{ 0x1f4, 0x1f5 },
	{ 0x1f6, 0x195 },
	{ 0x1f7, 0x1bf },
	{ 0x220, 0x19e },
	{ 0x386, 0x3ac },
	{ 0x388, 0x3ad },
	{ 0x389, 0x3ae },
	{ 0x38a, 0x3af },
	{ 0x38c, 0x3cc },
	{ 0x38e, 0x3cd },
	{ 0x38f, 0x3ce },
	{ 0x399, 0x345 },
	{ 0x399, 0x1fbe },
	{ 0x3a3, 0x3c2 },
	{ 0x3f7, 0x3f8 },
	{ 0x3fa, 0x3fb },
	{ 0x1e60, 0x1e9b },
	{ 0x1e9e, 0xdf },
	{ 0x1f59, 0x1f51 },
	{ 0x1f5b, 0x1f53 },
	{ 0x1f5d, 0x1f55 },
	{ 0x1f5f, 0x1f57 },
	{ 0x1fbc, 0x1fb3 },
	{ 0x1fcc, 0x1fc3 },
	{ 0x1fec, 0x1fe5 },
	{ 0x1ffc, 0x1ff3 },
	{ 0x23a, 0x2c65 },
	{ 0x23b, 0x23c },
	{ 0x23d, 0x19a },
	{ 0x23e, 0x2c66 },
	{ 0x241, 0x242 },
	{ 0x243, 0x180 },
	{ 0x244, 0x289 },
	{ 0x245, 0x28c },
	{ 0x3f4, 0x3b8 },
	{ 0x3f9, 0x3f2 },
	{ 0x3fd, 0x37b },
	{ 0x3fe, 0x37c },
	{ 0x3ff, 0x37d },
	{ 0x4c0, 0x4cf },
	{ 0x2126, 0x3c9 },
	{ 0x212a, 'k' },
	{ 0x212b, 0xe5 },
	{ 0x2132, 0x214e },
	{ 0x2183, 0x2184 },
	{ 0x2c60, 0x2c61 },
	{ 0x2c62, 0x26b },
	{ 0x2c63, 0x1d7d },
	{ 0x2c64, 0x27d },
	{ 0x2c6d, 0x251 },
	{ 0x2c6e, 0x271 },
	{ 0x2c6f, 0x250 },
	{ 0x2c70, 0x252 },
	{ 0x2c72, 0x2c73 },
	{ 0x2c75, 0x2c76 },
	{ 0x2c7e, 0x23f },
	{ 0x2c7f, 0x240 },
	{ 0x2cf2, 0x2cf3 },
	{ 0xa77d, 0x1d79 },
	{ 0xa78b, 0xa78c },
	{ 0xa78d, 0x265 },
	{ 0xa7aa, 0x266 },
	{ 0x10c7, 0x2d27 },
	{ 0x10cd, 0x2d2d },
	{ 0x376, 0x377 },
	{ 0x39c, 0xb5 },
	{ 0x392, 0x3d0 },
	{ 0x398, 0x3d1 },
	{ 0x3a6, 0x3d5 },
	{ 0x3a0, 0x3d6 },
	{ 0x39a, 0x3f0 },
	{ 0x3a1, 0x3f1 },
	{ 0x395, 0x3f5 },
	{ 0x3cf, 0x3d7 },
	{ 0x0, 0x0 }
};


#if IS_BIG_ENDIAN
/** Test for a bit in a wide-character; The characteristics are stored always in network byte order */
#   define ISwbit(bit)   (1 << (bit))
#else  // LITTLE_ENDIAN
/** Test for a bit in a wide-character; The characteristics are stored always in network byte order */
#   define ISwbit(bit)   ((bit) < 8 ? (int)((1UL << (bit)) << 24) : ((bit) < 16 ? (int)((1UL << (bit)) << 8) : ((bit) < 24 ? (int)((1UL << (bit)) >> 8) : (int)((1UL << (bit)) >> 24))))
#endif
#define _ISwbit(bit)   ISwbit((bit))

typedef enum WCHAR_CLASSIFICATION {
	/** UPPERCASE */
	__ISwupper = 0,
	/** lowercase */
	__ISwlower = 1,
	/** Alphabetic */
	__ISwalpha = 2,
	/** Numeric */
	__ISwdigit = 3,
	/** Hexadecimal numeric */
	__ISwxdigit = 4,
	/** Whitespace */
	__ISwspace = 5,
	/** Printing */
	__ISwprint = 6,
	/** Graphical */
	__ISwgraph = 7,
	/** Blank (usually SPC and TAB) */
	__ISwblank = 8,
	/** Control character */
	__ISwcntrl = 9,
	/** Punctuation */
	__ISwpunct = 10,
	/** Alphanumeric */
	__ISwalnum = 11
} wchar_classification_t;

#define WCTYPE_ALNUM   1
#define WCTYPE_ALPHA   2
#define WCTYPE_BLANK   3
#define WCTYPE_CNTRL   4
#define WCTYPE_DIGIT   5
#define WCTYPE_GRAPH   6
#define WCTYPE_LOWER   7
#define WCTYPE_PRINT   8
#define WCTYPE_PUNCT   9
#define WCTYPE_SPACE   10
#define WCTYPE_UPPER   11
#define WCTYPE_XDIGIT   12
#define _PDCLIB_WCTRANS_TOLOWER   1
#define _PDCLIB_WCTRANS_TOUPPER   2


/** Uppercase */
#define _ISwupper   _ISwbit(__ISwupper)
/** Lowercase */
#define _ISwlower   _ISwbit(__ISwlower)
/** Alphabetic */
#define _ISwalpha   _ISwbit(__ISwalpha)
/** Numeric */
#define _ISwdigit   _ISwbit(__ISwdigit)
/** Hexadecimal numeric */
#define _ISwxdigit   _ISwbit(__ISwxdigit)
/** Whitespace */
#define _ISwspace   _ISwbit(__ISwspace)
/** Printing */
#define _ISwprint   _ISwbit(__ISwprint)
/** Graphical */
#define _ISwgraph   _ISwbit(__ISwgraph)
/** Blank (usually SPC and TAB) */
#define _ISwblank   _ISwbit(__ISwblank)
/** Control character */
#define _ISwcntrl   _ISwbit(__ISwcntrl)
/** Punctuation */
#define _ISwpunct   _ISwbit(__ISwpunct)
/** Alphanumeric */
#define _ISwalnum   _ISwbit(__ISwalnum)
/** Test if the wchar is a lowercase wide-character */
#define WISLOWER(wc)   ((int)(((0x60U < (wint_t)(wc)) & ((wint_t)(wc) < 0x80U))))
/** Test if the wchar is a lowercase wide-character */
#define wislower(wc)   WISLOWER(((wint_t)(wc)))
/** Test if the wchar is a lowercase wide-character */
#define ISWLOWER(wc)   WISLOWER(((wint_t)(wc)))
/** Test if the wchar is a lowercase wide-character */
#define iswlower(wc)   WISLOWER(((wint_t)(wc)))
/** Test if the wchar is a lowercase wide-character */
#define islowerW(wc)   WISLOWER(((wc))
/** Test if the wchar is a lowercase wide-character */
#define __iswlower_l(wc, l)   WISLOWER(((wint_t)(wc)))
/** Test if the wchar is a lowercase wide-character */
#define iswlower_l(wc, l)   WISLOWER(((wint_t)(wc)))
/** Test if the wchar is a uppercase wide-character */
#define WISUPPER(wc)   ((int)(((0x40U < (wint_t)(wc)) & ((wint_t)(wc) < 0x60U))))
/** Test if the wchar is a uppercase wide-character */
#define wisupper(wc)   WISUPPER(((wint_t)(wc)))
/** Test if the wchar is a uppercase wide-character */
#define ISWUPPER(wc)   WISUPPER(((wint_t)(wc)))
/** Test if the wchar is a uppercase wide-character */
#define iswupper(wc)   WISUPPER(((wint_t)(wc)))
/** Test if the wchar is a uppercase wide-character */
#define isupperW(wc)   WISUPPER(((wc))
/** Test if the wchar is a uppercase wide-character */
#define __iswupper_l(wc, l)   WISUPPER(((wint_t)(wc)))
/** Test if the wchar is a uppercase wide-character */
#define iswupper_l(wc, l)   WISUPPER(((wint_t)(wc)))
/** Convert the wchar to a lowercase wide ASCII letter */
#define WTOLOWER(wc)   (((WISUPPER(((wint_t)(wc)))) ? ((wint_t)(wc) + 0x20U) : (wint_t)(wc)))
/** Convert the wchar to a lowercase wide ASCII letter */
#define wtolower(wc)   WTOLOWER(((wint_t)(wc)))
/** Convert the wchar to a lowercase wide ASCII letter */
#define TOWLOWER(wc)   WTOLOWER(((wint_t)(wc)))
/** Convert the wchar to a lowercase wide ASCII letter */
#define towlower(wc)   WTOLOWER(((wint_t)(wc)))
/** Convert the wchar to a lowercase wide ASCII letter */
#define tolowerW(wc)   WTOLOWER(((wint_t)(wc)))
/** Convert the wchar to a lowercase wide ASCII letter */
#define __towlower_l(wc, l)   WTOLOWER(((wint_t)(wc)))
/** Convert the wchar to a lowercase wide ASCII letter */
#define towlower_l(wc, l)   WTOLOWER(((wint_t)(wc)))
/** Convert the wchar to a uppercase wide ASCII letter */
#define WTOUPPER(wc)   (((WISLOWER(((wint_t)(wc)))) ? ((wint_t)(wc) - 0x20U) : (wint_t)(wc)))
/** Convert the wchar to a uppercase wide ASCII letter */
#define wtoupper(wc)   WTOUPPER(((wint_t)(wc)))
/** Convert the wchar to a uppercase wide ASCII letter */
#define TOWUPPER(wc)   WTOUPPER(((wint_t)(wc)))
/** Convert the wchar to a uppercase wide ASCII letter */
#define towupper(wc)   WTOUPPER(((wint_t)(wc)))
/** Convert the wchar to a uppercase wide ASCII letter */
#define toupperW(wc)   WTOUPPER(((wint_t)(wc)))
/** Convert the wchar to a uppercase wide ASCII letter */
#define __towupper_l(wc, l)   WTOUPPER(((wint_t)(wc)))
/** Convert the wchar to a uppercase wide ASCII letter */
#define towupper_l(wc, l)   WTOUPPER(((wint_t)(wc)))
/** Check if wide character is alphabetic */
LIB_FUNC int iswalpha(const wint_t wc) {
	if (wc < 0x20000U) { return (int)(alpha_table[(unsigned int)(alpha_table[wc >> 8] * 32) + (unsigned int)((wc & 255) >> 3)] >> (wc & 7)) & 1; }
	else if (wc < 0x2fffeU) { return 1; }
	return 0;
}
/** Check if wide character is alphabetic */
#define isalphaW(wc)   iswalpha((wc))
/** Check if wide character is alphabetic */
#define __iswalpha_l(wc, l)   iswalpha(((wint_t)(wc)))
/** Check if wide character is alphabetic */
#define iswalpha_l(wc, l)   iswalpha(((wint_t)(wc)))
/** Check if wide character is punctuation character */
LIB_FUNC int iswpunct(const wint_t wc) {
	if (wc < 0x20000U) { return (int)(punct_table[(unsigned int)(punct_table[wc >> 8] * 32) + (unsigned int)((wc & 255) >> 3)] >> (wc & 7)) & 1; }
	return 0;
}
/** Check if wide character is punctuation character */
#define ispunctW(wc)   iswpunct((wc))
/** Check if wide character is punctuation character */
#define __iswpunct(wc)   iswpunct(((wint_t)(wc)))
/** Check if wide character is punctuation character */
#define __iswpunct_l(wc, l)   iswpunct(((wint_t)(wc)))
/** Check if wide character is punctuation character */
#define iswpunct_l(wc, l)   iswpunct(((wint_t)(wc)))
/** Check if wide character is printable */
LIB_FUNC int iswprint(const wint_t wc) {
	if (wc < 0xffU) { return (int)(((wc + 1) & 0x7f) >= 0x21); }
	else if ((wc < 0x2028U) || (wc - 0x202aU) < 0xb7d6 || ((wc - 0xe000U) < 0x1ff9)) { return 1;}
	else if (((wc - 0xfffcU) > 0x100003) || ((wc & 0xfffe) == 0xfffe)) { return 0; }
	return 1;
}
/** Check if wide character is printable */
#define isprintW(wc)   iswprint((wc))
/** Check if wide character is printable */
#define __iswprint(wc)   iswprint(((wint_t)(wc)))
/** Check if wide character is printable */
#define __iswprint_l(wc, l)   iswprint(((wint_t)(wc)))
/** Check if wide character is printable */
#define iswprint_l(wc, l)   iswprint(((wint_t)(wc)))
/** Check if wide character is blank */
#define iswblank(wc)   ((int)(((wint_t)(wc) == 0x20U) | ((wint_t)(wc) == 0x09U)))
/** Check if wide character is blank */
#define isblankW(wc)   iswblank((wc))
/** Check if wide character is blank */
#define __iswblank_l(wc, l)   iswblank(((wint_t)(wc)))
/** Check if wide character is blank */
#define iswblank_l(wc, l)   iswblank(((wint_t)(wc)))
/** Check if wide character is a control character */
#define iswcntrl(wc)   ((int)(((unsigned)(wc)) < 32 || (unsigned)(((unsigned)(wc)) - 0x7f) < 33 || (unsigned)(((unsigned)(wc)) - 0x2028) < 2 || (unsigned)(((unsigned)(wc)) - 0xfff9) < 3))
/** Check if wide character is a control character */
#define iscntrlW(wc)   iswcntrl((wc))
/** Check if wide character is a control character */
#define __iswcntrl_l(wc, l)   iswcntrl(((wint_t)(wc)))
/** Check if wide character is a control character */
#define iswcntrl_l(wc, l)   iswcntrl(((wint_t)(wc)))
/** Test for any wide character that corresponds to a decimal-digit character */
#define iswdigit(wc)   ((int)((((wint_t)(wc)) >= L'0') && (((wint_t)(wc)) <= L'9')))
/** Test for any wide character that corresponds to a decimal-digit character */
#define isdigitW(wc)   iswdigit((wc))
/** Test for any wide character that corresponds to a decimal-digit character */
#define iswdigit_l(wc, l)   iswdigit(((wint_t)(wc)))
/** Test for any wide character that corresponds to a decimal-digit character */
#define __iswdigit_l(wc, l)   iswdigit(((wint_t)(wc)))
/** Check if wide character has graphical representation */
#define iswgraph(wc)   ((int)(!(iswspace(((wint_t)(wc))) && iswprint(((wint_t)(wc))))))
/** Check if wide character has graphical representation */
#define isgraphW(wc)   iswgraph((wc))
/** Check if wide character has graphical representation */
#define __iswgraph_l(wc, l)   iswgraph(((wint_t)(wc)))
/** Check if wide character has graphical representation */
#define iswgraph_l(wc, l)   iswgraph(((wint_t)(wc)))
/** Check if wide character is a white-space character */
#define iswspace(wc)   ((int)(((wint_t)(wc)) && wcschr(wchar_spaces, ((wchar_t)(wc)))))
/** Check if wide character is a white-space character */
#define isspaceW(wc)   iswspace((wc))
/** Check if wide character is a white-space character */
#define __iswspace_l(wc, l)   iswspace(((wint_t)(wc)))
/** Check if wide character is a white-space character */
#define iswspace_l(wc, l)   iswspace(((wint_t)(wc)))
/** Check if wide character is hexadecimal digit */
#define iswxdigit(wc)   ((int)(((unsigned)(((wint_t)(wc)) - 0x30) < 10) || ((unsigned)((((wint_t)(wc)) | 32) - 0x61) < 6)))
/** Check if wide character is hexadecimal digit */
#define isxdigitW(wc)   iswxdigit((wc))
/** Check if wide character is hexadecimal digit */
#define __iswxdigit_l(wc, l)   iswxdigit(((wint_t)(wc)))
/** Check if wide character is hexadecimal digit */
#define iswxdigit_l(wc, l)   iswxdigit(((wint_t)(wc)))
/** Test for any wide character that corresponds to an alphanumeric character */
#define iswalnum(wc)   ((int)(iswdigit((wint_t)(wc)) || iswalpha((wint_t)(wc))))
/** Test for any wide character that corresponds to an alphanumeric character */
#define isalnumW(wc)   iswalnum((wc))
/** Test for any wide character that corresponds to an alphanumeric character */
#define __iswalnum_l(wc, l)   iswalnum(((wint_t)(wc)))
/** Test for any wide character that corresponds to an alphanumeric character */
#define iswalnum_l(wc, l)   iswalnum(((wint_t)(wc)))


/** Returns a value of type wctype_t that corresponds to the character category specified by `property` */
LIB_FUNC wctype_t wctype(const char* property) {
	register int i = 1;
	const char* p;
	for (p = wchar_class_names; *p; i++, p += 6) {
		if (*property == *p && (!(strcmp(property, p)))) { return i; }
	}
	return 0;
}


/** Tables indexed by a wide character are compressed through the use of a multi-level lookup.  The compression effect comes from blocks that do not need particular data and from blocks that can share their data */
LIB_FUNC int wctype_table_lookup(const char* table, const uint32_t wc) {
	register const uint32_t index1 = wc >> (uint32_t)(((const uint32_t*)table)[0]);
	register const uint32_t bound = ((const uint32_t*)table)[1];
	if (index1 < bound) {
		register const uint32_t lookup1 = ((const uint32_t*)table)[5 + index1];
		if (lookup1 != 0) {
			register const uint32_t mask2 = ((const uint32_t*)table)[3];
			register const uint32_t index2 = (wc >> (uint32_t)(((const uint32_t*)table)[2])) & mask2;
			register const uint32_t lookup2 = ((const uint32_t*)(table + lookup1))[index2];
			if (lookup2 != 0) {
				register const uint32_t index3 = (wc >> 5) & (uint32_t)(((const uint32_t*)table)[4]);
				register const uint32_t lookup3 = ((const uint32_t*)(table + lookup2))[index3];
				return (int)(lookup3 >> (wc & 0x1f)) & 1;
			}
		}
	}
	return 0;
}


/** Byte tables are similar to bit tables, except that the addressing unit is a single byte, and no 5 bits are used as a word index */
LIB_FUNC int wcwidth_table_lookup(const char* table, const uint32_t wc) {
	register const uint32_t index1 = wc >> (uint32_t)(((const uint32_t*)table)[0]);
	register const uint32_t bound = ((const uint32_t*)table)[1];
	if (index1 < bound) {
		register const uint32_t lookup1 = ((const uint32_t*)table)[5 + index1];
		if (lookup1 != 0) {
			register const uint32_t mask2 = ((const uint32_t*)table)[3];
			register const uint32_t index2 = (wc >> (uint32_t)(((const uint32_t*)table)[2])) & mask2;
			register const uint32_t lookup2 = ((const uint32_t*)(table + lookup1))[index2];
			if (lookup2 != 0) {
				register const uint32_t index3 = wc & (uint32_t)(((const uint32_t*)table)[4]);
				register const uint8_t lookup3 = ((const uint8_t*)(table + lookup2))[index3];
				return (int)lookup3;
			}
		}
	}
	return 0xff;
}


/** Mapping tables are similar to bit tables, except that the addressing unit is a single signed 32-bit word, containing the difference between the desired result and the argument, and no 5 bits are used as a word index */
LIB_FUNC uint32_t wctrans_table_lookup(const char* table, const uint32_t wc) {
	register const uint32_t index1 = wc >> (uint32_t)(((const uint32_t*)table)[0]);
	register const uint32_t bound = ((const uint32_t*)table)[1];
	if (index1 < bound) {
		register const uint32_t lookup1 = ((const uint32_t*)table)[5 + index1];
		if (lookup1 != 0) {
			register const uint32_t mask2 = ((const uint32_t*)table)[3];
			register const uint32_t index2 = (wc >> (uint32_t)(((const uint32_t*)table)[2])) & mask2;
			register const uint32_t lookup2 = ((const uint32_t*)(table + lookup1))[index2];
			if (lookup2 != 0) {
				register const uint32_t index3 = wc & (uint32_t)(((const uint32_t*)table)[4]);
				register const uint32_t lookup3 = ((const uint32_t*)(table + lookup2))[index3];
				return (uint32_t)(wc + lookup3);
			}
		}
	}
	return wc;
}


/** Returns a value of type wctype_t that corresponds to the character category specified by `property` */
LIB_FUNC wctype_t wctype_l(const char* property, const UNUSED locale_t l) {
	return wctype(property);
}
#define __wctype_l(property, l)   wctype_l((property), (l))


/** Checks whether `wc` has the property specified by `char_class` */
LIB_FUNC int iswctype(const wint_t wc, const wctype_t char_class) {
	switch ((int)char_class) {
		case WC_TYPE_ALNUM: return (int)isalnum(wc);
		case WC_TYPE_ALPHA: return (int)isalpha(wc);
		case WC_TYPE_BLANK: return (int)isblank(wc);
		case WC_TYPE_CNTRL: return (int)iscntrl(wc);
		case WC_TYPE_DIGIT: return (int)isdigit(wc);
		case WC_TYPE_GRAPH: return (int)isgraph(wc);
		case WC_TYPE_LOWER: return (int)islower(wc);
		case WC_TYPE_PRINT: return (int)isprint(wc);
		case WC_TYPE_PUNCT: return (int)ispunct(wc);
		case WC_TYPE_SPACE: return (int)isspace(wc);
		case WC_TYPE_UPPER: return (int)isupper(wc);
		case WC_TYPE_XDIGIT: return (int)isxdigit(wc);
		default: return 0;
	}
	UNREACHABLE
}


/** Checks whether `wc` has the property specified by `char_class` */
LIB_FUNC int iswctype_l(const wint_t wc, const wctype_t char_class, const UNUSED __locale_t _locale) {
	if (char_class == (wctype_t)0) { return 0; }
	return (int)wctype_table_lookup((const char*)char_class, wc);
}
#define __iswctype_l(wc, char_class, _locale)   iswctype_l((wc), (char_class), (_locale))
#define isWctype_l(wc, char_class, _locale)   iswctype_l((wc), (char_class), (_locale))
#define isctypeW_l(wc, char_class, _locale)   iswctype_l((wc), (char_class), (_locale))


LIB_FUNC unsigned short get_char_typeW(const wchar_t ch) {
	return (unsigned short)(wctype_table[wctype_table[ch >> 8] + (ch & 0xff)]);
}
#define get_char_typew(ch)   get_char_typeW((ch))
#define get_char_type_w(ch)   get_char_typeW((ch))
#define get_char_type_W(ch)   get_char_typeW((ch))


LIB_FUNC int wcinfo_cmp(const void* _key, const void* _obj) {
	const uint32_t* key = (const uint32_t*)_key;
	const wcinfo_t* obj = (const wcinfo_t*)_obj;
	if (*key < obj->start) { return -1; }
	else if (*key >= (obj->start + obj->length)) { return 1; }
	return 0;
}


#endif  // WCTYPE_H

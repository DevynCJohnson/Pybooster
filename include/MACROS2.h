// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief Standard Macros Header with AT&T-style Assembly
@file MACROS2.h
@version 2018.11.11
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This file defines various datatypes, macros, enums, functions, etc.

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


DIAG_PUSH
IGNORE_WMISSING_PROTOTYPES
IGNORE_WSHADOW


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


/* ALIGNMENT (<stdalign.h>) */


#if (!(defined(STDALIGN_H) || defined(__STDALIGN_H) || defined(__STDALIGN_H_) || defined(_ALIGNOF_H)))  // https://www.gnu.org/software/gnulib/manual/html_node/stdalign_002eh.html & https://www.ibm.com/support/knowledgecenter/SSLTBW_2.1.0/com.ibm.zos.v2r1.bpxbd00/stdalign.htm
#define STDALIGN_H   (1)
#define _STDALIGN_H   (1)
#define __STDALIGN_H   (1)
#define __STDALIGN_H_   (1)
#define _ALIGNOF_H   (1)


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


// STRIDEOF

#define strideof(obj)   sizeof(obj)


// BASEOF

#define BASEOF(ptr, str_type, field)   ((struct str_type*)((char*)ptr - offsetof(str_type, field)))


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
#define __PTR_ALIGN(B, P, A)   __BPTR_ALIGN((((sizeof(PTR_INT_TYPE)) < BYTES_PER_POINTER) ? (B) : (char*)0), P, A)

typedef struct attr_packed _obstack_chunk {
	char* limit;  // 1 past end of this chunk
	struct _obstack_chunk* prev;  // Address of prior chunk or NULL
	char contents[4];  // Objects begin here
} obstack_chunk_t;

DIAG_PUSH
IGNORE_WPADDED

/** Control current object in current chunk */
typedef struct obstack {
	long chunk_size;  // Preferred size to allocate chunks
	struct _obstack_chunk* chunk;  // Address of current struct obstack_chunk
	char* object_base;  // Address of object we are building
	char* next_free;  // Where to add next char to current object
	char* chunk_limit;  // Address of char after current chunk
	union obstack_temp_union {
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

DIAG_POP

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

#if IS_GNUC

#   define obstack_object_size(OBSTACK)   do { struct obstack const *__o = (OBSTACK); (unsigned)(__o->next_free - __o->object_base); } while (0x0)
#   define obstack_room(OBSTACK)   do { struct obstack const *__o = (OBSTACK); (unsigned)(__o->chunk_limit - __o->next_free); } while (0x0)
#   define obstack_make_room(OBSTACK, length)   do { struct obstack* __o = (OBSTACK); int __len = (length); if (__o->chunk_limit - __o->next_free < __len) { _obstack_newchunk(__o, __len); } (void)0; } while (0x0)
#   define obstack_empty_p(OBSTACK)   do { struct obstack const *__o = (OBSTACK); (__o->chunk->prev == 0 && __o->next_free == __PTR_ALIGN((char*) __o->chunk, __o->chunk->contents,  __o->alignment_mask)); } while (0x0)
#   define obstack_grow(OBSTACK, where, length)   do { struct obstack* __o = (OBSTACK); int __len = (length); if (__o->next_free + __len > __o->chunk_limit) { _obstack_newchunk(__o, __len); } memcpy_no_output(__o->next_free, where, __len); __o->next_free += __len; (void)0; } while (0x0)
#   define obstack_grow0(OBSTACK, where, length)   do { struct obstack* __o = (OBSTACK); int __len = (length); if (__o->next_free + __len + 1 > __o->chunk_limit) { _obstack_newchunk(__o, __len + 1); } memcpy (__o->next_free, where, __len); __o->next_free += __len; *(__o->next_free)++ = 0; (void)0; } while (0x0)
#   define obstack_1grow(OBSTACK, datum)   do { struct obstack* __o = (OBSTACK); if (__o->next_free + 1 > __o->chunk_limit) { _obstack_newchunk(__o, 1); } obstack_1grow_fast(__o, datum); (void)0; } while (0x0)
#   define obstack_ptr_grow(OBSTACK, datum)   do { struct obstack* __o = (OBSTACK); if (__o->next_free + SIZEOF_VOID_PTR > __o->chunk_limit) { _obstack_newchunk(__o, SIZEOF_VOID_PTR); } obstack_ptr_grow_fast(__o, datum); } while (0x0)
#   define obstack_int_grow(OBSTACK, datum)   do { struct obstack* __o = (OBSTACK); if (__o->next_free + BYTES_PER_INT > __o->chunk_limit) { _obstack_newchunk(__o, BYTES_PER_INT); } obstack_int_grow_fast(__o, datum); } while (0x0)
#   define obstack_ptr_grow_fast(OBSTACK, aptr)   do { struct obstack* __o1 = (OBSTACK); void* __p1 = __o1->next_free; *(const void **) __p1 = (aptr); __o1->next_free += SIZEOF_VOID_PTR; (void)0; } while (0x0)
#   define obstack_int_grow_fast(OBSTACK, aint)   do { struct obstack* __o1 = (OBSTACK); void* __p1 = __o1->next_free; *(int*) __p1 = (aint); __o1->next_free += BYTES_PER_INT; (void)0; } while (0x0)
#   define obstack_blank(OBSTACK, length)   do { struct obstack* __o = (OBSTACK); int __len = (length); if (__o->chunk_limit - __o->next_free < __len) { _obstack_newchunk(__o, __len); } obstack_blank_fast (__o, __len); (void)0; } while (0x0)
#   define obstack_alloc(OBSTACK, length)   do { struct obstack* __h = (OBSTACK); obstack_blank(__h, (length)); obstack_finish (__h); } while (0x0)
#   define obstack_copy(OBSTACK, where, length)   do { struct obstack* __h = (OBSTACK); obstack_grow(__h, (where), (length)); obstack_finish(__h); } while (0x0)
#   define obstack_copy0(OBSTACK, where, length)   do { struct obstack* __h = (OBSTACK); obstack_grow0(__h, (where), (length)); obstack_finish(__h); } while (0x0)
/** The local variable is named __o1 to avoid a name conflict when obstack_blank is called */
#   define obstack_finish(OBSTACK)   do { struct obstack* __o1 = (OBSTACK); void* __value = (void*) __o1->object_base; if (__o1->next_free == __value) { __o1->maybe_empty_object = 1; } __o1->next_free = __PTR_ALIGN(__o1->object_base, __o1->next_free, __o1->alignment_mask); if (__o1->next_free - (char*) __o1->chunk > __o1->chunk_limit - (char*) __o1->chunk) { __o1->next_free = __o1->chunk_limit; } __o1->object_base = __o1->next_free; __value; } while (0x0)
#   define obstack_free(OBSTACK, OBJ)   do { struct obstack* __o = (OBSTACK); void* __obj = (OBJ); if (__obj > (void*) __o->chunk && __obj < (void*) __o->chunk_limit)  __o->next_free = __o->object_base = (char*) __obj; else __obstack_free(__o, __obj); } while (0x0)

#else  // Compiler is neither Clang nor GNU-GCC

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
#   define MAXARGS   (31)
#endif
#ifndef MAX_ARGS
/** Maximum number of function arguments */
#   define MAX_ARGS   MAXARGS
#endif
/** Flag used in struct __args -> flags */
#define A_ALLOCATED   (1)


// VA_LIST

#if (IS_GNUC && (!defined(__GNUC_VA_LIST)))
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
#undef __need___va_list
#define __DEFINED___isoc_va_list   (1)
#define __DEFINED_va_list   (1)
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
#define __va_ptr_t   __gnuc_va_list
#define VEC(...)   (const unsigned char[]){ __VA_ARGS__ }
/** Show list of items in __VA_ARGS__ */
#define showlist(...)   puts(#__VA_ARGS__)


// VA_START, VA_END, & VA_ARG

/** Retrieve next argument */
#define va_arg   __builtin_va_arg
#if IS_GNUC
#   define __builtin_stdarg_start(v, argnum)   __builtin_va_start((v), (argnum))
#else
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


// VA_COPY

// GCC only defines `va_copy` c99 mode, or if `-ansi` is not specified; va_copy is not in C90
#if (IS_STDC99 || IS_NOT_STRICT_ANSI)
/** Copy variable argument list */
#   define va_copy(dest, src)   (*(dest) = *(src))  // __builtin_va_copy((dest), (src))
/** Copy variable argument list */
#   define _va_copy(dest, src)   va_copy((dest), (src))
/** Copy variable argument list */
#   define __va_copy(dest, src)   va_copy((dest), (src))
/** Copy variable argument list */
#   define gl_va_copy(dest, src)   va_copy((dest), (src))
#endif


// MSVC COMPATIBILITY

#ifndef __ms_va_list
#   if (defined(ARCHX86_64) && IS_GNUC)
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

#if IS_GNUC
/** Returns a pointer to data describing how to perform a call with the same arguments as are passed to the current function */
#   define apply_args()   (void*)__builtin_apply_args()
/** Returns a pointer to data describing how to perform a call with the same arguments as are passed to the current function */
#   define get_arg_pointer()   (void*)__builtin_apply_args()
#endif


extern UNUSED char* argv0;


#define ARGBEGIN   for ((void)(argv0 || (argv0 = *argv)), argv++, argc--; argv[0] && (argv[0][0] == '-') && argv[0][1]; argc--, argv++) { char *_args, *_argt; Rune _argc; _args = &argv[0][1]; if ((_args[0] == '-') && (_args[1] == 0)) { argc--; argv++; break; } _argc = 0; while (*_args && (_args += chartorune(&_argc, _args))) { switch (_argc) }
#define ARGEND   _argt = 0; }
#define ARGF()   (_argt = _args, _args = "", (*_argt ? _argt : argv[1] ? (argc--, *++argv) : 0))
#define EARGF(x)   (_argt = _args, _args = "", (*_argt ? _argt : argv[1] ? (argc--, *++argv) : ((x), abort(), (char*)0)))


#endif  // STDARG_H


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
#define _NETINET_IN_SYSTM_H   (1)  // <netinet/in_systm.h>
#define _NETINET_IN_SYSTM_H_   (1)
#define __WINE_LIMITS_H   (1)
#define _SYS_SYSCONF_H_   (1)
#define _MACHINE_LIMITS_H_   (1)
#define POSIX_EXTRAS_H   (1)
#define POSIX_EXTRAS_H_   (1)
#define _POSIX_EXTRAS_H   (1)
#define _POSIX_EXTRAS_H_   (1)
#define _SYS_PARAM_H   (1)
#define _SYS_PARAM_H_   (1)
#define _BSD_SYS_PARAM_H_   (1)
#define _BITSIZE_STDINTLIMITS_H   (1)
#define __BIT_TYPES_DEFINED__   (1)
#define GNULIB_SIZE_MAX_H   (1)
#define CGEN_BASIC_MODES_H   (1)
#define _SYS_COMMON_INT_CONST_H_   (1)
#define _COMPAT_FSTYPES_H_   (1)
#define _I386_INT_MWGWTYPES_H_   (1)
#define _ARM_INT_MWGWTYPES_H_   (1)
#define _SYS_COMMON_INT_MWGWTYPES_H_   (1)
#define _USTAT_H   (1)
#define LINUX_TYPES_WRAPPER_H   (1)
#define LINUX_TYPES_WRAPPER_H_   (1)
#define _SYS_COMMON_INT_TYPES_H_   (1)
#define __HFS_MACOS_TYPES__   (1)
#define _KXLD_TYPES_H   (1)
#define DEVICE_TYPES_H   (1)
#define _BITS_PTHREADTYPES_H   (1)  // <bits/pthreadtypes.h>
#define _BITS_PTHREADTYPES_H_   (1)
#define _CONFIG_TYPES_H   (1)
#define _TYPE_CONSTANTS_H   (1)
#define WCIO_H   (1)
#define _WCIO_H   (1)
#define _WCIO_H_   (1)


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


// EXACT-WIDTH FRACTIONAL DATATYPES

#if SUPPORTS_FRACT
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

#if SUPPORTS_ACCUM
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


// UNCOMMON FIXED-WIDTH INTEGRAL DATATYPES

#if SUPPORTS_INT24
typedef __INT24_TYPE__   int24_t;
typedef __UINT24_TYPE__   uint24_t;
typedef int32_t   int_least24_t;
typedef uint32_t   uint_least24_t;
typedef int32_t   int_fast24_t;
typedef uint32_t   uint_fast24_t;
#   define u_int24_t   uint24_t
#   define uint24   uint24_t
#endif
#if SUPPORTS_INT40
typedef __INT40_TYPE__   int40_t;
typedef __UINT40_TYPE__   uint40_t;
typedef int40_t   int_least40_t;
typedef uint40_t   uint_least40_t;
typedef int40_t   int_fast40_t;
typedef uint40_t   uint_fast40_t;
#   define u_int40_t   uint40_t
#   define uint40   uint40_t
#endif
#if SUPPORTS_INT48
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
#endif
#if SUPPORTS_INT56
typedef __INT56_TYPE__   int56_t;
typedef __UINT56_TYPE__   uint56_t;
typedef int56_t   int_least56_t;
typedef uint56_t   uint_least56_t;
typedef int56_t   int_fast56_t;
typedef uint56_t   uint_fast56_t;
#   define u_int56_t   uint56_t
#   define uint56   uint56_t
#endif


DIAG_PUSH
IGNORE_WPADDED

/** Datatype union for converting between 11-bit and 16-bit integers */
typedef union uint11 { struct uint11_struct { unsigned short uval11:11; } val11; unsigned short val16; }   uint11_t;
/** Datatype union for converting between 15-bit and 16-bit integers */
typedef union uint15 { struct uint15_struct { unsigned short uval15:15; } val15; unsigned short val16; }   uint15_t;

DIAG_POP


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


// WIDE-CHARACTER DATATYPES

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
_Static_assert(((SIZEOF_WCHAR_T == sizeof(wchar_t)) && (SIZEOF_WINT_T == SIZEOF_INT)), "Improperly set `wchar_t` datatype!");
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
_Static_assert(((SIZEOF_WINT_T == sizeof(wint_t)) && (SIZEOF_WINT_T == SIZEOF_INT)), "Improperly set `wint_t` datatype!");
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
typedef wchar_t   TCHAR;
typedef wchar_t   TSCHAR;
typedef wchar_t   TUCHAR;
typedef wchar_t   TXCHAR;
typedef wint_t   TINT;
typedef wchar_t*   PTCHAR;
typedef wchar_t   TBYTE, *PTBYTE;
#      define TEOF   WEOF
#      define _TEOF   WEOF
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


// STRING DATATYPES

typedef unsigned char   Str255[256];
typedef unsigned char   Str63[64];
typedef unsigned char   Str32[33];
typedef unsigned char   Str31[32];
typedef unsigned char   Str27[28];
typedef unsigned char   Str15[16];
typedef Str63   StrFileName;
/** Extended String Object */
typedef struct xstrobj {
	unsigned short len;  // Number of bytes/chars
	char chars[65536];  // String
} xstrobj_t;
/** Pascal String */
typedef struct pstring {
	unsigned char len;
	char data[];
} pstring_t;


// MISCELLANEOUS EXACT-WIDTH & FIXED-WIDTH INTEGRALS

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
#define bit8_t   int8_t
/** Signed 8-bit quantity */
#define s_bit8_t   bit8_t
/** Signed 8-bit quantity */
#define sbit8_t   bit8_t
/** Unsigned 8-bit quantity */
#define ubit8_t   uint8_t
/** Unsigned 8-bit quantity */
#define u_bit8_t   ubit8_t
#define sbits8   signed char
#define bits8   unsigned char
#define ubits8   unsigned char
/** Signed 16-bit quantity */
#define bit16_t   int16_t
/** Signed 16-bit quantity */
#define s_bit16_t   bit16_t
/** Signed 16-bit quantity */
#define sbit16_t   bit16_t
/** Unsigned 16-bit quantity */
#define ubit16_t   uint16_t
/** Unsigned 16-bit quantity */
#define u_bit16_t   ubit16_t
#define sbits16   signed short
#define bits16   unsigned short
#define ubits16   unsigned short
/** Signed 32-bit quantity */
#define bit32_t   int32_t
/** Signed 32-bit quantity */
#define sbit32_t   bit32_t
/** Signed 32-bit quantity */
#define s_bit32_t   bit32_t
/** Unsigned 32-bit quantity */
#define u_bit32_t   uint32_t
/** Unsigned 32-bit quantity */
#define ubit32_t   u_bit32_t
#define sbits32   signed int
#define bits32   unsigned int
#define ubits32   unsigned int
/** Signed 64-bit quantity */
#define bit64_t   int64_t
/** Signed 64-bit quantity */
#define s_bit64_t   bit64_t
/** Signed 64-bit quantity */
#define sbit64_t   bit64_t
/** Unsigned 64-bit quantity */
#define ubit64_t   uint64_t
/** Unsigned 64-bit quantity */
#define u_bit64_t   ubit64_t
#define sbits64   int64_t
#define bits64   uint64_t
#define ubits64   uint64_t
/** Type of an IPC key */
typedef __KEY_T_TYPE   key_t;
/** Type of an IPC key */
#define __key_t   key_t
#define kernel_key_t   key_t
#define MACH_MSG_TYPE_CHAR   char
#define MACH_MSG_TYPE_INTEGER_8   unsigned char
#define MACH_MSG_TYPE_INTEGER_16   unsigned short
#define MACH_MSG_TYPE_INTEGER_32   unsigned int
#define MACH_MSG_TYPE_INTEGER_T   MACH_MSG_TYPE_INTEGER_32
#define MACH_MSG_TYPE_INTEGER_64   uint64_t
#define kern_return_t   int
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
typedef int   rlimit_resource_t;
#define __rlimit_resource_t   rlimit_resource_t
typedef uint32_t   pgno_t;
/** Segment size */
typedef int32_t   segsz_t;
typedef uint16_t   indx_t;
typedef uint32_t   recno_t;
typedef uint32_t   db_recno_t;
#ifndef __DEFINED_cnd_t
/** Used for condition variables */
typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; }   cnd_t;
#   define __DEFINED_cnd_t   (1)
#endif
typedef int   mqd_t;
#define kernel_mqd_t   mqd_t
#define n_short   uint16_t
#define n_long   uint32_t
#define n_time   uint32_t


// DIVISION DATATYPES

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
/** Type for array elements in `cpu_set_t` */
typedef unsigned long   cpu_mask_t;
#define SIZEOF_CPU_MASK_T   SIZEOF_LONG
#define BITS_PER_CPU_MASK_T   BITS_PER_LONG
#define SIZEOF_CPU_SET_T   128
#define BITS_PER_CPU_SET_T   1024
/** Data structure to describe CPU mask */
typedef struct cpu_set { cpu_mask_t bits[SIZEOF_CPU_SET_T / SIZEOF_CPU_MASK_T]; }   cpu_set_t;
#define __cpu_set_t_defined
#ifndef __dev_t_defined
/** Type of device numbers */
typedef __UQUAD_TYPE   dev_t;
#   define __dev_t_defined   (1)
#endif
typedef int   reg_class_t;
#ifndef __DEFINED_register_t
typedef RegType   register_t;
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
/** In user-space, "rights" are represented by the name of the right in the Mach port namespace */
typedef __U32_TYPE   mach_port_t;
#define __mach_port_t   mach_port_t
typedef __U32_TYPE   dev_mode_t;
typedef __U32_TYPE   dev_flavor_t;
typedef __U32_TYPE   device_t;
typedef __U32_TYPE   io_done_queue_t;
typedef int64_t   hrtime_t;
typedef __U32_TYPE   zoneid_t;


// ID DATATYPES

#ifndef __gid_t_defined
/** Datatype for group identifications */
typedef __GID_T_TYPE   gid_t;
/** Datatype for group identifications */
#   define __gid_t   gid_t
#   define __gid_t_defined   (1)
#endif
#ifndef __uid_t_defined
/** Datatype for user identifications */
typedef __UID_T_TYPE   uid_t;
/** Datatype for user identifications */
#   define __uid_t   uid_t
#   define __uid_t_defined   (1)
#endif
/** ID array datatype (commonly used in Hurd) */
typedef uid_t*   idarray_t;
/** Datatype for process identifications */
typedef __PID_T_TYPE   pid_t;
/** Datatype for process identifications */
#define __pid_t   pid_t
/** PID array datatype (commonly used in Hurd) */
typedef pid_t*   pidarray_t;
/** General type for IDs */
typedef __ID_T_TYPE   id_t;
/** General type for IDs */
#define __id_t   id_t
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
typedef int   processorid_t;
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
#ifndef __daddr_t_defined
/** Datatype of a disk address */
typedef __DADDR_T_TYPE   daddr_t;
/** Datatype of a disk address */
#   define __daddr_t   daddr_t
#   define __daddr_t_defined   (1)
#endif


// SIZE-RELATED DATATYPES

#define __size_t   size_t
#define _IO_size_t   size_t
#define Size   size_t
#define usize   size_t
#define __usize   size_t
#define usize_t   size_t
#define __usize_t   size_t
/** Windows datatype */
#define SIZE_T   size_t
#define _BSD_SIZE_T_   size_t
#define kxld_addr_t   size_t
#define kxld_size_t   size_t
/** Memory region datatype */
typedef size_t   info_t;
/** Restricted size_t; ISO9899:2011 7.20 (C11 Annex K) */
typedef size_t   rsize_t;
/** Restricted size_t; ISO9899:2011 7.20 (C11 Annex K) */
#define __rsize_t   rsize_t
/** Type of a byte count, or error */
#define __ssize_t   ssize_t
/** Windows datatype */
#define SSIZE_T   ssize_t
#define _BSD_SSIZE_T_   ssize_t
#ifdef ARCHM68K
#   define _READ_WRITE_RETURN_TYPE   ssize_t
#endif


// FILESYSTEM-RELATED DATATYPES

/** Type for event counter */
typedef uint64_t   eventfd_t;
/** An unsigned integer type used for the number of file descriptors */
typedef unsigned int   nfds_t;
/** File-descriptor mask datatype (commonly used in Hurd) */
typedef int*   fd_mask_t;
typedef long   fd_mask;
/** Number of bits per word of `fd_set` (some code assumes this is 32) */
#define NFDBITS   BITS_PER_LONG
/** Number of bits per word of `fd_set` (some code assumes this is 32) */
#define BITS_PER_FD_MASK   NFDBITS
/** Size of fd_mask in bytes */
#define SIZEOF_FD_MASK   SIZEOF_LONG
#ifndef FD_SETSIZE
/** Number of descriptors that can fit in an `fd_set` */
#   define FD_SETSIZE   (_POSIX_FD_SETSIZE * SIZEOF_LONG)
#endif
#define BITS_PER_FD_SET   FD_SETSIZE
/** fd_set for select and pselect */
typedef struct fd_set_struct {
#   ifdef __USE_XOPEN
	fd_mask fds_bits[_POSIX_FD_SETSIZE];  // XPG4.2 requires this member name
#   else
	fd_mask __fds_bits[_POSIX_FD_SETSIZE];
#   endif
} fd_set;
#ifndef __mode_t_defined
/** Type of file attribute bitmasks */
typedef __U32_TYPE   mode_t;
/** Type of file attribute bitmasks */
#   define __mode_t   mode_t
#   define __mode_t_defined   (1)
#endif
#ifndef __nlink_t_defined
/** Type of file link counts */
typedef __UWORD_TYPE   nlink_t;
/** Type of file link counts */
#   define __nlink_t   nlink_t
#   define __nlink_t_defined   (1)
#endif
#ifndef __ino_t_defined
/** Type of file serial numbers */
typedef __INO_T_TYPE   ino_t;
/** Type of file serial numbers (LFS) */
typedef __INO64_T_TYPE   ino64_t;
#   if SUPPORTS_LARGEFILE64
/** Type of file serial numbers (LFS) */
#      define __ino_t   ino_t
#   else
/** Type of file serial numbers (LFS) */
#      define __ino_t   ino64_t
#   endif
/** Type of file serial numbers (LFS) */
#   define __ino64_t   ino64_t
#   define __ino_t_defined   (1)
#endif
#ifndef __off_t_defined
#   if SUPPORTS_LARGEFILE64
/** Datatype for file offsets (LFS) */
typedef __OFF64_T_TYPE   off64_t;
/** Datatype for file offsets */
typedef __OFF64_T_TYPE   off_t;
#      define SIZEOF_OFF_T   8
#      define SIZEOF_OFF64_T   8
#   else
/** Datatype for file offsets (LFS) */
typedef __OFF64_T_TYPE   off64_t;
/** Datatype for file offsets */
typedef __OFF_T_TYPE   off_t;
#      define SIZEOF_OFF_T   SIZEOF_LONG
#      define SIZEOF_OFF64_T   8
#   endif
#   define __off_t_defined   (1)
/** Datatype for file offsets (LFS) */
#   define __off64_t   off64_t
/** Datatype for file offsets */
#   define __off_t   off_t
#endif  // __off_t_defined
/** Swap offset */
typedef off_t   swblk_t;
/** Datatype for file offsets */
#define loff_t   off64_t
/** Datatype for file offsets */
#define __loff_t   off64_t
/** Offset array datatype (commonly used in Hurd) */
typedef loff_t*   off_array_t;
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
#ifndef __blksize_t_defined
/** Type to represent block size */
typedef __BLKSIZE_T_TYPE   blksize_t;
/** Type to represent block size */
#   define __blksize_t   blksize_t
#   define __blksize_t_defined   (1)
#endif
#ifndef __blkcnt_t_defined
/** Type to count number of disk blocks */
typedef __BLKCNT_T_TYPE   blkcnt_t;
#   define __blkcnt_t   blkcnt_t
/** Type to count number of disk blocks */
typedef __BLKCNT64_T_TYPE   blkcnt64_t;
#   define __blkcnt64_t   blkcnt64_t
#   define __blkcnt_t_defined   (1)
#endif
#ifndef __fsblkcnt_t_defined
/** Type to count filesystem blocks */
typedef __FSBLKCNT_T_TYPE   fsblkcnt_t;
#   define __fsblkcnt_t   fsblkcnt_t
/** Type to count filesystem blocks */
typedef __FSBLKCNT64_T_TYPE   fsblkcnt64_t;
#   define __fsblkcnt64_t   fsblkcnt64_t
#   define __fsblkcnt_t_defined   (1)
#endif
/** Type to count filesystem nodes */
typedef __FSFILCNT_T_TYPE   fsfilcnt_t;
#define __fsfilcnt_t   fsfilcnt_t
/** Type to count filesystem nodes */
typedef __FSFILCNT64_T_TYPE   fsfilcnt64_t;
#define __fsfilcnt64_t   fsfilcnt64_t
/** Type of miscellaneous filesystem fields */
typedef __FSWORD_T_TYPE   fsword_t;
/** Type of miscellaneous filesystem fields */
#define __fsword_t   fsword_t
/** Resource limit datatype */
typedef __RLIM_T_TYPE   rlim_t;
/** Resource limit datatype */
#define __rlim_t   rlim_t
/** Type for resource measurement (LFS) */
typedef __RLIM64_T_TYPE   rlim64_t;
/** Type for resource measurement (LFS) */
#define __rlim64_t   rlim64_t

// File-lock structure & datatype
#if (defined(ARCHALPHA) || defined(ARCHARM) || defined(ARCHITANIUM) || defined(ARCHPARISC) || defined(ARCHPOWERPC) || defined(ARCHS390) || defined(ARCHSPARC) || defined(ARCHX86))
typedef struct attr_packed flock {
	int16_t l_type, l_whence;
	off_t l_start, l_len;
	pid_t l_pid;
} flock_t;
typedef struct attr_packed flock64 {
	int16_t l_type, l_whence;
	loff_t l_start, l_len;
	pid_t  l_pid;
} flock64_t;
#elif defined(ARCHMIPS64)
typedef struct flock {
	int16_t l_type, l_whence;
	off_t l_start, l_len;
	long l_sysid;
	pid_t l_pid;
	long pad[4];
} flock_t;
typedef struct flock64 {
	int16_t l_type, l_whence;
	loff_t l_start, l_len;
	pid_t l_pid;
} flock64_t;
#elif defined(ARCHMIPS32)
typedef struct flock {
	int16_t l_type, l_whence;
	off_t l_start, l_len;
	pid_t l_pid;
} flock_t;
#   define flock64   flock
#   define flock64_t   flock_t
#else
#   error   "Add support for `struct flock`, `struct flock64`, `flock_t`, and `flock64_t` fo the target platform."
#endif

DIAG_PUSH
IGNORE_WPADDED

#ifdef OSLINUX
typedef struct statfs {
	fsword_t f_type, f_bsize;
#   ifndef USE_FILE_OFFSET64
	fsblkcnt_t f_blocks, f_bfree, f_bavail;
	fsfilcnt_t f_files, f_ffree;
#   else
	fsblkcnt64_t f_blocks, f_bfree, f_bavail;
	fsfilcnt64_t f_files, f_ffree;
#   endif
	fsid_t f_fsid;
	fsword_t f_namelen, f_frsize, f_flags;
	fsword_t f_spare[4];
} statfs_t;
#   if SUPPORTS_LARGEFILE64
typedef struct statfs64 {
	fsword_t f_type, f_bsize;
	fsblkcnt64_t f_blocks, f_bfree, f_bavail;
	fsfilcnt64_t f_files, f_ffree;
	fsid_t f_fsid;
	fsword_t f_namelen, f_frsize, f_flags;
	fsword_t f_spare[4];
} statfs64_t;
#   endif
#   define _STATFS_F_NAMELEN
#   define _STATFS_F_FRSIZE
#   define _STATFS_F_FLAGS
#else
typedef struct statfs {
	unsigned int f_type, f_bsize;
#   ifndef USE_FILE_OFFSET64
	fsblkcnt_t f_blocks, f_bfree, f_bavail, f_files, f_ffree;
#   else
	fsblkcnt64_t f_blocks, f_bfree, f_bavail, f_files, f_ffree;
#   endif
	fsid_t f_fsid;
	unsigned int f_namelen;
	unsigned int f_spare[6];
} statfs_t;
#   if SUPPORTS_LARGEFILE64
typedef struct statfs64 {
	unsigned int f_type, f_bsize;
	fsblkcnt64_t f_blocks, f_bfree, f_bavail, f_files, f_ffree;
	fsid_t f_fsid;
	unsigned int f_namelen;
	unsigned int f_spare[6];
} statfs64_t;
#   endif
#   define _STATFS_F_NAMELEN
#endif

DIAG_POP

/** The <sys/uio.h> header uses the iovec structure for scatter/gather I/O */
typedef struct iovec {
	const void* iov_base;  // Base address of a memory region for input or output
	size_t iov_len;  // The size of the memory pointed to by iov_base
} iovec_t;
#define __DEFINED_struct_iovec   (1)
#define HAVE_IOVEC   (1)


// TIME-RELATED DATATYPES

/** Type of CPU usage counts */
typedef __CLOCK_T_TYPE   clock_t;
/** Type of CPU usage counts */
#define __clock_t   clock_t
/** Clock ID used in clock and timer functions */
typedef __CLOCKID_T_TYPE   clockid_t;
/** Clock ID used in clock and timer functions */
#define __clockid_t   clockid_t
/** Datatype for clock cycles */
typedef unsigned long   cycles_t;
/** Clocksource cycle base type */
typedef uint64_t   cycle_t;
#ifndef __DEFINED_time_t
/** Seconds since the Epoch */
typedef __TIME_T_TYPE   time_t;
/** Seconds since the Epoch */
#   define __time_t   time_t
#   define __DEFINED_time_t   (1)
#endif
#define time_tz   time_t
#define tz_time_t   time_t
typedef uint64_t   time64_t;
#define __time64_t   time64_t
/** Timer ID returned by `timer_create` */
typedef __TIMER_T_TYPE   timer_t;
/** Timer ID returned by `timer_create` */
#define __timer_t   timer_t
#ifndef __DEFINED_suseconds_t
/** Signed count of microseconds */
typedef __SUSECONDS_T_TYPE   suseconds_t;
/** Signed count of microseconds */
#   define __suseconds_t   suseconds_t
#   define _BSD_SUSECONDS_T_   suseconds_t
#   define __DEFINED_suseconds_t   (1)
#endif
#ifndef __DEFINED_useconds_t
/** Count of microseconds */
typedef __USECONDS_T_TYPE   useconds_t;
/** Count of microseconds */
#   define __useconds_t   useconds_t
#   define _BSD_USECONDS_T_   useconds_t
#   define __DEFINED_useconds_t   (1)
#endif
#if (!(defined(__DEFINED_struct_timespec) || defined(__timespec_defined)))
typedef struct timespec { time_t tv_sec; long tv_nsec; }   timespec_t;
#   define __timespec   timespec
#   define __timespec_t   timespec_t
#   define __DEFINED_struct_timespec   (1)
#   define __timespec_defined   (1)
#endif
#ifndef __DEFINED_struct_timeval
typedef struct timeval { time_t tv_sec; suseconds_t tv_usec; }   timeval_t;
#   define __DEFINED_struct_timeval   (1)
#endif
/** 32-bit time structure with seconds and microseconds */
typedef struct timeval32 { int32_t tv_sec, tv_usec; }   timeval32_t;
#define STRUCT_TIMEVAL32   struct timeval32
#define _STRUCT_TIMEVAL32   struct timeval32
/** 64-bit time structure with seconds and microseconds */
typedef struct timeval64 { int64_t tv_sec, tv_usec; }   timeval64_t;
#define STRUCT_TIMEVAL64   struct timeval64
#define _STRUCT_TIMEVAL64   struct timeval64
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
/** Values for the first argument to `getitimer` and `setitimer` */
typedef enum __itimer_which {
	ITIMER_REAL = 0,  // Timers run in real time
	ITIMER_VIRTUAL = 1,  // Timers run only when the process is executing
	ITIMER_PROF = 2  // Timers run when the process is executing and when the system is executing on behalf of the process
} itimer_which_t;
typedef struct itimerspec { struct timespec it_interval, it_value; }   itimerspec_t;
typedef struct ntptimeval { struct timeval time; long maxerror, esterror; }   ntptimeval_t;
typedef struct timeval50 { long tv_sec, tv_usec; }   timeval50_t;
typedef struct itimerval50 { struct timeval50 it_interval; struct timeval50 it_value; }   itimerval50_t;
typedef struct attr_packed timespec50 { int32_t tv_sec; long tv_nsec; }   timespec50_t;
typedef struct itimerspec50 { struct timespec50 it_interval; struct timespec50 it_value; }   itimerspec50_t;
#ifdef ARCHALPHA
/** Datatype for variables used to store the time values */
#   define hp_timing_t   unsigned int
#elif (defined(ARCHX86) || defined(ARCHPOWERPC) || defined(ARCHSPARC32))
/** Datatype for variables used to store the time values */
#   define hp_timing_t   unsigned long long
#elif (defined(ARCHITANIUM) || defined(ARCHSPARC64))
/** Datatype for variables used to store the time values */
#   define hp_timing_t   unsigned long
#else
/** Datatype for variables used to store the time values */
#   define hp_timing_t   unsigned int
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
typedef timespec_t   mach_timespec_t;
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
/** Unsigned character pointer */
typedef unsigned char*   PUCHAR;
typedef char*   PSZ;
#define BYTE   unsigned char
typedef BYTE*   PBYTE;
typedef BYTE*   LPBYTE;
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
typedef int8_t*   i8_ptr_t;
typedef int16_t*   PINT16;
typedef int16_t*   s16_ptr_t;
typedef int16_t*   i16_ptr_t;
typedef int32_t*   s32_ptr_t;
typedef int32_t*   i32_ptr_t;
typedef int64_t*   PLONG64;
typedef int64_t*   PINT64;
typedef int64_t*   s64_ptr_t;
typedef int64_t*   i64_ptr_t;
typedef uint8_t*   PUINT8;
typedef uint8_t*   u8_ptr_t;
typedef uint8_t*   ptr8_t;
typedef uint16_t*   PUINT16;
typedef uint16_t*   u16_ptr_t;
typedef uint16_t*   ptr16_t;
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


// SUN RPC ADDITIONS TO <sys/types.h>

#ifndef __dontcare__
#   define __dontcare__   (-1)
#endif
#ifndef dontcare
#   define dontcare   (-1)
#endif
typedef int   bool_t;
typedef int   enum_t;
typedef int32_t   rpc_inline_t;
typedef uint32_t   rpcport_t;
typedef uint32_t   rpcproc_t;
typedef uint32_t   rpcprog_t;
typedef uint32_t   rpcprot_t;
typedef uint32_t   rpcvers_t;
/** The netbuf structure is used for transport-independent address storage */
typedef struct netbuf { unsigned int maxlen, len; void* buf; }   netbuf_t;
/** The format of the address and options arguments of the XTI t_bind call; Only provided for compatibility, it should not be used */
typedef struct attr_packed t_bind { struct netbuf addr; unsigned int qlen; }   t_bind_t;
/** Used with rpcbind */
typedef struct rpc_sockinfo { int si_af, si_proto, si_socktype, si_alen; }   rpc_sockinfo_t;


// VOLATILE DATATYPES

typedef volatile signed char   vchar_t;
typedef volatile unsigned char   vuchar_t;
// Volatile Integer Datatypes
typedef volatile signed short   vshort_t;
typedef volatile unsigned short   vushort_t;
typedef volatile signed int   vint_t;
typedef volatile unsigned int   vuint_t;
typedef volatile signed long   vlong_t;
#define vlong   vlong_t
#define p9vlong   vlong_t
#define _utfvlong   vlong_t
#define utfvlong   vlong_t
typedef volatile unsigned long   vulong_t;
#define uvlong   vulong_t
#define p9uvlong   vulong_t
#define _utfuvlong   vulong_t
#define utfuvlong   vulong_t
#define vulong   vulong_t
typedef volatile signed long long   vlonglong_t;
typedef volatile unsigned long long   vulonglong_t;
// Volatile Exact-width Integral Datatypes
typedef volatile int8_t   vint8_t;
typedef volatile uint8_t   vuint8_t;
typedef volatile int16_t   vint16_t;
typedef volatile uint16_t   vuint16_t;
typedef volatile int32_t   vint32_t;
typedef volatile uint32_t   vuint32_t;
typedef volatile int64_t   vint64_t;
typedef volatile uint64_t   vuint64_t;
#if SUPPORTS_INT128
typedef volatile int128_t   vint128_t;
typedef volatile uint128_t   vuint128_t;
#endif
#if SUPPORTS_INT256
typedef volatile int256_t   vint256_t;
typedef volatile uint256_t   vuint256_t;
#endif
#if SUPPORTS_INT512
typedef volatile int512_t   vint512_t;
typedef volatile uint512_t   vuint512_t;
#endif
// Volatile Float-Point Datatypes
typedef volatile float   vfloat_t;
typedef volatile double   vdouble_t;
#if SUPPORTS_FLOAT8
typedef volatile float8   vfloat8_t;
#endif
#if SUPPORTS_FLOAT16
typedef volatile float16   vfloat16_t;
#endif
#if SUPPORTS_FLOAT24
typedef volatile float24   vfloat24_t;
#endif
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
#endif
#if SUPPORTS_DECIMAL128
typedef volatile decimal128   vdecimal128_t;
#endif
// Volatile Stdfix Datatypes
#if SUPPORTS_STDFIX
typedef volatile _Fract   vfract_t;
typedef volatile satfx_t   vsatfx_t;
typedef volatile fx_t   vfx_t;
typedef volatile fx_hr_t   vfx_hr_t;
typedef volatile fx_r_t   vfx_r_t;
typedef volatile fx_lr_t   vfx_lr_t;
typedef volatile fx_llr_t   vfx_llr_t;
typedef volatile fx_uhr_t   vfx_uhr_t;
typedef volatile fx_ur_t   vfx_ur_t;
typedef volatile fx_ulr_t   vfx_ulr_t;
typedef volatile fx_ullr_t   vfx_ullr_t;
typedef volatile _Accum   vaccum_t;
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


// ASSEMBLY DATATYPES

#define __force   (1)
#ifdef ARCHALPHA
typedef uint32_t   umode_t;
#else
typedef uint16_t   umode_t;
#endif


// ALIGNED DATATYPES

// Aligned Basic Datatypes
typedef char align8   aln_char_t;
typedef unsigned char align8   aln_uchar_t;
typedef short align16   aln_short_t;
typedef unsigned short align16   aln_ushort_t;
typedef int align32   aln_int_t;
typedef unsigned int align32   aln_uint_t;
typedef long align_long   aln_long_t;
typedef unsigned long align_long   aln_ulong_t;
typedef long long align64   aln_llong_t;
typedef unsigned long long align64   aln_ullong_t;
typedef float alignSF   aln_float_t;
typedef double alignDF   aln_double_t;
// Aligned Exact-width Integrals
typedef int8_t align8   aln_int8_t;
typedef uint8_t align8   aln_uint8_t;
typedef int16_t align16   aln_int16_t;
typedef uint16_t align16   aln_uint16_t;
typedef int32_t align32   aln_int32_t;
typedef uint32_t align32   aln_uint32_t;
typedef int64_t align64   aln_int64_t;
typedef uint64_t align64   aln_uint64_t;
#define __aligned_u64   aln_uint64_t
#define __aligned_le64   aln_uint64_t
#define aligned_u64   aln_uint64_t
#define aligned_be64   aln_uint64_t
#define aligned_le64   aln_uint64_t
// Aligned Pointer & size_t Datatypes
typedef size_t align_ptr   aln_size_t;
typedef ssize_t align_ptr   aln_ssize_t;


// ATOMIC DATATYPES

/** Initializes a new atomic object */
#define ATOMIC_VAR_INIT(value)   (atomic uint32_t)value
/** Initializes a new atomic_flag */
#define ATOMIC_FLAG_INIT   (atomic uint32_t)(0)
/** Initializes an new 64-bit atomic object */
#define ATOMIC64_INIT(i)   (atomic uint64_t)i
/** Initializes an existing atomic object */
#define atomic_init(obj, value)   atomic (obj) = (value)
#define ATOMIC_INIT(obj, value)   atomic (obj) = (value)
#define __c11_atomic_init(obj, value)   atomic (obj) = (value)
typedef struct atomic_struct { int counter; }   atomic_t;
typedef struct atomicl_struct { long counter; }    atomic_long_t;
typedef struct atomicll_struct { long long counter; }    atomic_long_long_t;
typedef atomic int32_t    atomic32_t;
typedef atomic int64_t    atomic64_t;
#if IS_CPLUSPLUS
typedef atomic bool   atomic_bool;
#else
typedef atomic _Bool   atomic_bool;
#endif
#define abool   atomic_bool
// Atomic Character Datatypes
typedef atomic char   atomic_char;
typedef atomic signed char   atomic_schar;
typedef atomic unsigned char   atomic_uchar;
#define achar   atomic_char
#define aschar   atomic_schar
#define auchar   atomic_uchar
typedef atomic wint_t   atomic_wint_t;
#define awint_t   atomic_wint_t
typedef atomic wchar_t   atomic_wchar_t;
#define awchar_t   atomic_wchar_t
typedef atomic char16_t   atomic_char16_t;
#define achar16_t   atomic_char16_t
typedef atomic char32_t   atomic_char32_t;
#define achar32_t   atomic_char32_t
// Atomic Integer Datatypes
typedef atomic short   atomic_short;
typedef atomic unsigned short   atomic_ushort;
#define ashort   atomic_short
#define aushort   atomic_ushort
typedef atomic int   atomic_int;
typedef atomic unsigned int   atomic_uint;
#define aint   atomic_int
#define auint   atomic_uint
typedef atomic long   atomic_long;
typedef atomic unsigned long   atomic_ulong;
#define along   atomic_long
#define aulong   atomic_ulong
typedef atomic long long   atomic_llong;
typedef atomic unsigned long long   atomic_ullong;
#define allong   atomic_llong
#define aullong   atomic_ullong
#define alonglong   atomic_llong
#define aulonglong   atomic_ullong
// Atomic Exact-Width Integral Datatypes
typedef atomic int8_t   atomic_int8_t;
typedef atomic uint8_t   atomic_uint8_t;
typedef atomic int16_t   atomic_int16_t;
typedef atomic uint16_t   atomic_uint16_t;
typedef atomic int32_t   atomic_int32_t;
typedef atomic uint32_t   atomic_uint32_t;
typedef atomic int64_t   atomic_int64_t;
typedef atomic uint64_t   atomic_uint64_t;
#define aint8_t   atomic_int8_t
#define auint8_t   atomic_uint8_t
#define aint16_t   atomic_int16_t
#define auint16_t   atomic_uint16_t
#define aint32_t   atomic_int32_t
#define auint32_t   atomic_uint32_t
#define aint64_t   atomic_int64_t
#define auint64_t   atomic_uint64_t
#define atomic8_t   atomic_int8_t
#define uatomic8_t   atomic_uint8_t
#define atomic16_t   atomic_int16_t
#define uatomic16_t   atomic_uint16_t
#define atomic32_t   atomic_int32_t
#define uatomic32_t   atomic_uint32_t
#define atomic64_t   atomic_int64_t
#define uatomic64_t   atomic_uint64_t
#if LONG_EQ_32BITS
#   define memusage_cntr_t   uatomic32_t
#   define memusage_size_t   uatomic32_t
#else
#   define memusage_cntr_t   uatomic64_t
#   define memusage_size_t   uatomic64_t
#endif
typedef atomic int_least8_t   atomic_int_least8_t;
typedef atomic uint_least8_t   atomic_uint_least8_t;
typedef atomic int_least16_t   atomic_int_least16_t;
typedef atomic uint_least16_t   atomic_uint_least16_t;
typedef atomic int_least32_t   atomic_int_least32_t;
typedef atomic uint_least32_t   atomic_uint_least32_t;
typedef atomic int_least64_t   atomic_int_least64_t;
typedef atomic uint_least64_t   atomic_uint_least64_t;
#define aleast8_t   atomic_int_least8_t
#define auleast8_t   atomic_uint_least8_t
#define aleast16_t   atomic_int_least16_t
#define auleast16_t   atomic_uint_least16_t
#define aleast32_t   atomic_int_least32_t
#define auleast32_t   atomic_uint_least32_t
#define aleast64_t   atomic_int_least64_t
#define auleast64_t   atomic_uint_least64_t
#define atomic_least8_t   atomic_int_least8_t
#define uatomic_least8_t   atomic_uint_least8_t
#define atomic_least16_t   atomic_int_least16_t
#define uatomic_least16_t   atomic_uint_least16_t
#define atomic_least32_t   atomic_int_least32_t
#define uatomic_least32_t   atomic_uint_least32_t
#define atomic_least64_t   atomic_int_least64_t
#define uatomic_least64_t   atomic_uint_least64_t
typedef atomic int_fast8_t   atomic_int_fast8_t;
typedef atomic uint_fast8_t   atomic_uint_fast8_t;
typedef atomic int_fast16_t   atomic_int_fast16_t;
typedef atomic uint_fast16_t   atomic_uint_fast16_t;
typedef atomic int_fast32_t   atomic_int_fast32_t;
typedef atomic uint_fast32_t   atomic_uint_fast32_t;
typedef atomic int_fast64_t   atomic_int_fast64_t;
typedef atomic uint_fast64_t   atomic_uint_fast64_t;
#define afast8_t   atomic_int_fast8_t
#define aufast8_t   atomic_uint_fast8_t
#define afast16_t   atomic_int_fast16_t
#define aufast16_t   atomic_uint_fast16_t
#define afast32_t   atomic_int_fast32_t
#define aufast32_t   atomic_uint_fast32_t
#define afast64_t   atomic_int_fast64_t
#define aufast64_t   atomic_uint_fast64_t
#define atomic_fast8_t   atomic_int_fast8_t
#define uatomic_fast8_t   atomic_uint_fast8_t
#define atomic_fast16_t   atomic_int_fast16_t
#define uatomic_fast16_t   atomic_uint_fast16_t
#define atomic_fast32_t   atomic_int_fast32_t
#define uatomic_fast32_t   atomic_uint_fast32_t
#define atomic_fast64_t   atomic_int_fast64_t
#define uatomic_fast64_t   atomic_uint_fast64_t
// Atomic Float-Point Datatypes
#if SUPPORTS_FLOAT8
typedef atomic float8   atomic_float8;
#   define afloat8   atomic_float8
#   define afloat8   atomic_float8
#   define atomic_float8   atomic_float8
#endif
#if SUPPORTS_FLOAT16
typedef atomic float16   atomic_float16;
#   define afloat16   atomic_float16
#   define afloat16   atomic_float16
#   define atomic_float16   atomic_float16
#endif
#if SUPPORTS_FLOAT24
typedef atomic float24   atomic_float24;
#   define afloat24   atomic_float24
#   define afloat24   atomic_float24
#   define atomic_float24   atomic_float24
#endif
typedef atomic float   atomic_float;
#define afloat   atomic_float
typedef atomic double   atomic_double;
#define adouble   atomic_double
#if SUPPORTS_LONG_DOUBLE
typedef atomic long double   atomic_long_double;
#   define aldouble   atomic_long_double
#   define alongdouble   atomic_long_double
#   define atomic_ldouble   atomic_long_double
#endif
#if SUPPORTS_FLOAT80
typedef atomic float80   atomic_float80;
#   define afloat80   atomic_float80
#   define afloat80_t   atomic_float80
#endif
#if SUPPORTS_FLOAT96
typedef atomic float96   atomic_float96;
#   define afloat96   atomic_float96
#   define afloat96_t   atomic_float96
#endif
#if SUPPORTS_FLOAT128
typedef atomic float128   atomic_float128;
#   define afloat128   atomic_float128
#   define afloat128_t   atomic_float128
#endif
#if SUPPORTS_DECIMAL_FLOATS
typedef atomic decimal32   atomic_decimal32;
#   define adecimal32   atomic_decimal32
#   define adecimal32_t   atomic_decimal32
typedef atomic decimal64   atomic_decimal64;
#   define adecimal64   atomic_decimal64
#   define adecimal64_t   atomic_decimal64
#endif
#if SUPPORTS_DECIMAL128
typedef atomic decimal128   atomic_decimal128;
#   define adecimal128   atomic_decimal128
#   define adecimal128_t   atomic_decimal128
#endif
#if SUPPORTS_COMPLEX
typedef atomic complex_float   atomic_complex_float;
#   define acomplex_float   atomic_complex_float
#   define acomplex_float_t   atomic_complex_float
typedef atomic complex_double   atomic_complex_double;
#   define acomplex_double   atomic_complex_double
#   define acomplex_double_t   atomic_complex_double
#endif
#if SUPPORTS_COMPLEX_LDBL
typedef atomic complex_long_double   atomic_complex_long_double;
#   define acomplex_ldouble   atomic_complex_long_double
#   define acomplex_ldouble_t   atomic_complex_long_double
#endif
// Atomic Stdfix Datatypes
#if SUPPORTS_STDFIX
typedef atomic _Fract   atomic_fract_t;
typedef atomic satfx_t   atomic_satfx_t;
typedef atomic fx_t   atomic_fx_t;
typedef atomic fx_hr_t   atomic_fx_hr_t;
typedef atomic fx_r_t   atomic_fx_r_t;
typedef atomic fx_lr_t   atomic_fx_lr_t;
typedef atomic fx_llr_t   atomic_fx_llr_t;
typedef atomic fx_uhr_t   atomic_fx_uhr_t;
typedef atomic fx_ur_t   atomic_fx_ur_t;
typedef atomic fx_ulr_t   atomic_fx_ulr_t;
typedef atomic fx_ullr_t   atomic_fx_ullr_t;
typedef atomic _Accum   atomic_accum_t;
typedef atomic fx_hk_t   atomic_fx_hk_t;
typedef atomic fx_k_t   atomic_fx_k_t;
typedef atomic fx_lk_t   atomic_fx_lk_t;
typedef atomic fx_llk_t   atomic_fx_llk_t;
typedef atomic fx_uhk_t   atomic_fx_uhk_t;
typedef atomic fx_uk_t   atomic_fx_uk_t;
typedef atomic fx_ulk_t   atomic_fx_ulk_t;
typedef atomic fx_ullk_t   atomic_fx_ullk_t;
#endif
// Miscellaneous Atomic Datatypes
typedef atomic intptr_t   atomic_intptr_t;
#define atomicptr_t   atomic_intptr_t
#define aintptr_t   atomic_intptr_t
typedef atomic uintptr_t   atomic_uintptr_t;
#define uatomicptr_t   atomic_uintptr_t
#define auintptr_t   atomic_uintptr_t
typedef atomic ptrdiff_t   atomic_ptrdiff_t;
#define aptrdiff_t   atomic_ptrdiff_t
typedef atomic size_t   atomic_size_t;
#define asize_t   atomic_size_t
typedef atomic ssize_t   atomic_ssize_t;
#define assize_t   atomic_ssize_t
typedef atomic intmax_t   atomic_intmax_t;
#define atomic_max_t   atomic_intmax_t
#define aintmax_t   atomic_intmax_t
typedef atomic uintmax_t   atomic_uintmax_t;
#define uatomic_max_t   atomic_uintmax_t
#define auintmax_t   atomic_uintmax_t
typedef atomic struct atomic_flag_struct { atomic_bool __val; }   atomic_flag;
typedef atomic imaxdiv_t   atomic_imaxdiv_t;
#define aimaxdiv   atomic_imaxdiv_t
#define atomic_imaxdiv   atomic_imaxdiv_t
typedef atomic sig_atomic_t   atomic_sig_atomic_t;
#define asig_atomic_t   atomic_sig_atomic_t
typedef atomic mach_port_t   atomic_mach_port_t;
#define amach_port_t   atomic_mach_port_t
typedef atomic clock_t   atomic_clock_t;
#define aclock_t   atomic_clock_t
typedef atomic clockid_t   atomic_clockid_t;
#define aclockid_t   atomic_clockid_t
typedef atomic time_t   atomic_time_t;
#define atime_t   atomic_time_t
typedef atomic timer_t   atomic_timer_t;
#define atimer_t   atomic_timer_t
typedef atomic suseconds_t   atomic_suseconds_t;
#define asuseconds_t   atomic_suseconds_t
typedef atomic useconds_t   atomic_useconds_t;
#define auseconds_t   atomic_useconds_t
typedef atomic timeval_t   atomic_timeval_t;
#define atimeval_t   atomic_timeval_t
typedef atomic timeval32_t   atomic_timeval32_t;
#define atimeval32_t   atomic_timeval32_t
typedef atomic timeval64_t   atomic_timeval64_t;
#define atimeval64_t   atomic_timeval64_t
typedef atomic id_t   atomic_id_t;
#define aid_t   atomic_id_t
typedef atomic pid_t   atomic_pid_t;
#define apid_t   atomic_pid_t
typedef atomic gid_t   atomic_gid_t;
#define agid_t   atomic_gid_t
typedef atomic uid_t   atomic_uid_t;
#define auid_t   atomic_uid_t
typedef atomic dev_t   atomic_dev_t;
#define adev_t   atomic_dev_t
typedef atomic blkcnt_t   atomic_blkcnt_t;
#define ablkcnt_t   atomic_blkcnt_t
typedef atomic blksize_t   atomic_blksize_t;
#define ablksize_t   atomic_blksize_t
typedef atomic fsblkcnt_t   atomic_fsblkcnt_t;
#define afsblkcnt_t   atomic_fsblkcnt_t
typedef atomic fsfilcnt_t   atomic_fsfilcnt_t;
#define afsfilcnt_t   atomic_fsfilcnt_t
typedef atomic off_t   atomic_off_t;
#define aoff_t   atomic_off_t
typedef atomic ino_t   atomic_ino_t;
#define aino_t   atomic_ino_t
typedef atomic ino64_t   atomic_ino64_t;
#define aino64_t   atomic_ino64_t
typedef atomic mode_t   atomic_mode_t;
#define amode_t   atomic_mode_t
typedef atomic sigset_t   atomic_sigset_t;
#define asigset_t   atomic_sigset_t


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


// FUNCTION-SPECIFIC DATATYPES

#define strtol_t   long
#define strtoul_t   unsigned long
#define strtoll_t   long long
#define strtoull_t   unsigned long long


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
typedef char*   malloc_ptr_t;
#define __malloc_ptr_t   malloc_ptr_t
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


// BSD DATATYPES

/** Queue Element Datatype/Structure */
typedef struct qelem {
	struct qelem* q_forw;
	struct qelem* q_back;
	char* q_data;
} qelem_t;


// DARWIN DATATYPES

#ifdef OSDARWIN
/** Darwin size_t datatype */
#   define __darwin_size_t   size_t
/** Darwin size_t datatype */
#   define darwin_size_t   size_t
/** Darwin ssize_t datatype (byte count or error) */
#   define __darwin_ssize_t   ssize_t
/** Darwin ssize_t datatype (byte count or error) */
#   define darwin_ssize_t   ssize_t
/** Darwin ptrdiff_t datatype */
#   define __darwin_ptrdiff_t   ptrdiff_t
#   define darwin_ptrdiff_t   ptrdiff_t
#   define darwin_intptr_t   intptr_t
#   define __darwin_intptr_t   intptr_t
#   define darwin_uintptr_t   uintptr_t
#   define __darwin_uintptr_t   uintptr_t
/** Type to hold information about variable arguments */
#   define __darwin_va_list   __gnuc_va_list
/** Type to hold information about variable arguments */
#   define darwin_va_list   __gnuc_va_list
#   define darwin_natural_t   natural_t
#   define __darwin_natural_t   natural_t
#   ifndef darwin_mbstate_t
#      define darwin_mbstate_t   mbstate_t
#   endif
#   ifndef __darwin_mbstate_t
#      define __darwin_mbstate_t   mbstate_t
#   endif
#   define DARWIN_WEOF   WEOF
#   define __DARWIN_WEOF   WEOF
#   define darwin_wchar_t   wchar_t
#   define __darwin_wchar_t   wchar_t
#   define darwin_wint_t   wint_t
#   define __darwin_wint_t   wint_t
#   define darwin_wctrans_t   wctrans_t
#   define __darwin_wctrans_t   wctrans_t
#   define darwin_wctype_t   wctype_t
#   define __darwin_wctype_t   wctype_t
/** arg type for ctype functions */
#   define ct_rune_t   int
/** arg type for ctype functions */
#   define __ct_rune_t   int
/** arg type for ctype functions */
#   define darwin_ct_rune_t   ct_rune_t
/** arg type for ctype functions */
#   define __darwin_ct_rune_t   ct_rune_t
#   define darwin_rune_t   rune_t
#   define __darwin_rune_t   rune_t
/** pid_t, gid_t, or uid_t datatype */
#   define darwin_id_t   id_t
/** pid_t, gid_t, or uid_t datatype */
#   define __darwin_id_t   id_t
/** Process and group ID datatype */
#   define darwin_gid_t   gid_t
/** Process and group ID datatype */
#   define __darwin_gid_t   gid_t
/** User ID datatype */
#   define darwin_uid_t   uid_t
/** User ID datatype */
#   define __darwin_uid_t   uid_t
/** Process ID datatype */
#   define darwin_pid_t   pid_t
/** Process ID datatype */
#   define __darwin_pid_t   pid_t
#   define darwin_clock_t   clock_t
#   define __darwin_clock_t   clock_t
#   define darwin_suseconds_t   suseconds_t
#   define __darwin_suseconds_t   suseconds_t
#   define darwin_useconds_t   useconds_t
#   define __darwin_useconds_t   useconds_t
#   define darwin_time_t   time_t
#   define __darwin_time_t   time_t
typedef signed int   darwin_nl_item_t
#   define __darwin_nl_item   darwin_nl_item_t
#   define __darwin_nl_item_t   darwin_nl_item_t
#   define darwin_dev_t   dev_t
#   define __darwin_dev_t   dev_t
/** Total blocks datatype */
#   define darwin_blkcnt_t   blkcnt_t
/** Total blocks datatype */
#   define __darwin_blkcnt_t   blkcnt_t
/** Preferred block size datatype */
#   define darwin_blksize_t   blksize_t
/** Preferred block size datatype */
#   define __darwin_blksize_t   blksize_t
#   define darwin_fsblkcnt_t   fsblkcnt_t
#   define __darwin_fsblkcnt_t   fsblkcnt_t
#   define darwin_fsfilcnt_t   fsfilcnt_t
#   define __darwin_fsfilcnt_t   fsfilcnt_t
/** Datatype used for file sizes */
#   define darwin_off_t   off_t
/** Datatype used for file sizes */
#   define __darwin_off_t   off_t
/** Inode number datatype */
#   define darwin_ino_t   ino_t
/** Inode number datatype */
#   define __darwin_ino_t   ino_t
/** 64-bit inode number datatype */
#   define darwin_ino64_t   ino64_t
/** 64-bit inode number datatype */
#   define __darwin_ino64_t   ino64_t
#   define darwin_mode_t   mode_t
#   define __darwin_mode_t   mode_t
/** Signal set datatype */
#   define darwin_sigset_t   sigset_t
/** Signal set datatype */
#   define __darwin_sigset_t   sigset_t
/** Input port datatype */
typedef uint16_t   in_port_t;
/** Socket datatype */
typedef unsigned int   darwin_socklen_t;
#   define __darwin_socklen_t   darwin_socklen_t
#   define __darwin_mach_port_t   mach_port_t
#   define darwin_mach_port_t   mach_port_t
#   define darwin_mach_port_name_t   mach_port_t
#   define __darwin_mach_port_name_t   mach_port_t
#   define KAUTH_GUID_SIZE   16
/** Apple-style globally unique identifier */
typedef struct apple_guid { unsigned char g_guid[KAUTH_GUID_SIZE]; }   guid_t;
typedef unsigned char   uuid_t[16];
typedef char   uuid_string_t[37];
#   define darwin_uuid_t   uuid_t
#   define __darwin_uuid_t   uuid_t
#   define _UUID_T   uuid_t
#   define darwin_uuid_string_t   uuid_string_t
#   define __darwin_uuid_string_t   uuid_string_t
#   define _UUID_STRING_T   uuid_string_t
#endif


// MACH DATATYPES

#if ((!defined(MACH_DATATYPES_H)) && defined(ALLOW_HEADER_MACH_DATATYPES_H))
#define MACH_DATATYPES_H   (1)


#define VM_TAG_BT   1
#define VM_TAG_KMOD   2
#define VM_TAG_UNLOAD   4
/** Implement the legacy 32-bit VM APIs published by the kernel */
#define VM32_SUPPORT   1
/** Max array size */
#define SAMPLE_MAX   256
typedef float   MACH_MSG_TYPE_REAL_32;
typedef double   MACH_MSG_TYPE_REAL_64;
#define MSG_TYPE_PORT_NAME   natural_t
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
#if (SIZEOF_POINTER == 64)
typedef uint64_t   vm_address_t;
typedef uint64_t   vm_offset_t;
typedef uint64_t   vm_size_t;
#else
typedef uint32_t   vm_address_t;
typedef uint32_t   vm_offset_t;
typedef uint32_t   vm_size_t;
#endif
typedef uint64_t   mach_vm_address_t;
#define memory_object_offset_t   mach_vm_address_t
#define memory_object_size_t   mach_vm_address_t
#define vm_map_t   vm_address_t
#define vm_map_address_t   mach_vm_address_t
#define vm_map_size_t   mach_vm_address_t
#define vm_object_size_t   mach_vm_address_t
#define vm_map_offset_t   mach_vm_address_t
#define vm_object_offset_t   mach_vm_address_t
#define mach_port_context_t   mach_vm_address_t
#define mach_vm_size_t   mach_vm_address_t
#define mach_vm_offset_t   mach_vm_address_t
typedef mach_vm_offset_t*   emulation_vector_t;
typedef vm_offset_t   pointer_t;
typedef uint8_t   vm_tag_t;
typedef struct vm_allocation_site { vm_tag_t tag; uint8_t flags; }   vm_allocation_site_t;
typedef uint64_t   vm64_address_t;
typedef uint32_t   vm32_address_t;
#define memory_object_cluster_size_t   vm32_address_t
#define vm32_offset_t   vm32_address_t
#define vm32_size_t   vm32_address_t
#define VM_USRSTACK32   ((vm32_address_t)0xc0000000)
#define USRSTACK   VM_USRSTACK32
#define VM_USRSTACK64   ((vm64_address_t)0x7fff5fc00000ULL)
#define USRSTACK64   VM_USRSTACK64
typedef int64_t   user_long_t;
typedef uint64_t   user_ulong_t;
typedef uint64_t   user_size_t;
typedef int64_t   user_ssize_t;
typedef uint64_t   user_addr_t;
#define USER_ADDR_NULL   ((user_addr_t)0)
#define CAST_USER_ADDR_T(__ptr)   ((user_addr_t)((uintptr_t)(__ptr)))
typedef int64_t   user_off_t;
typedef int64_t   user_time_t;
typedef int32_t   user32_long_t;
typedef uint32_t   user32_ulong_t;
typedef uint32_t   user32_addr_t;
typedef uint32_t   user32_size_t;
typedef int32_t   user32_ssize_t;
typedef aln_int64_t   user32_off_t;
typedef int32_t   user32_time_t;
typedef aln_int64_t   user64_long_t;
typedef aln_uint64_t   user64_ulong_t;
typedef aln_uint64_t   user64_addr_t;
typedef aln_uint64_t   user64_size_t;
typedef aln_int64_t   user64_ssize_t;
typedef aln_int64_t   user64_off_t;
typedef aln_int64_t   user64_time_t;
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

#define VM_MAP_NULL   ((vm_map_t)0)
#define UPL_NULL   ((upl_t)0)
#define VM_NAMED_ENTRY_NULL  ((vm_named_entry_t)0)
#define UND_REPLY_NULL ((UNDReplyRef)0X0)
#define XML_DATA_NULL   ((xmlData_t)0X0)
#define TASK_NULL   ((task_t)0)
#define TASK_NAME_NULL   ((task_name_t)0)
#define THREAD_NULL   ((thread_t)0)
#define TID_NULL   ((uint64_t)0)
#define THR_ACT_NULL   ((thread_act_t)0)
#define IPC_SPACE_NULL   ((ipc_space_t)0)
#define COALITION_NULL   ((coalition_t)0)
#define HOST_NULL   ((host_t)0)
#define HOST_PRIV_NULL   ((host_priv_t)0)
#define HOST_SECURITY_NULL  ((host_security_t)0)
#define PROCESSOR_SET_NULL  ((processor_set_t)0)
#define PROCESSOR_NULL   ((processor_t)0)
#define SEMAPHORE_NULL   ((semaphore_t)0)
#define LOCK_SET_NULL   ((lock_set_t)0)
#define LEDGER_NULL   ((ledger_t)0)
#define ALARM_NULL   ((alarm_t)0)
#define CLOCK_NULL   ((clock_t)0)
#define UND_SERVER_NULL   ((UNDServerRef)0)


// MACH INFINITY OBJECTS

#define LEDGER_ITEM_INFINITY   ((ledger_item_t)(~0))
#define LEDGER_LIMIT_INFINITY   ((ledger_amount_t)0x7fffffffULL)


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
#define MACH_VOUCHER_NAME_ARRAY_NULL   ((mach_voucher_name_array_t)0)
typedef mach_voucher_t   ipc_voucher_t;
#define IPC_VOUCHER_NULL   ((ipc_voucher_t)0)
typedef uint32_t   mach_voucher_attr_importance_refs;
typedef uint32_t   mach_voucher_selector_t;
#define MACH_VOUCHER_SELECTOR_CURRENT   ((mach_voucher_selector_t)0)
#define MACH_VOUCHER_SELECTOR_EFFECTIVE   ((mach_voucher_selector_t)1)
/** Data passed to a resource manager for modifying an attribute value or returned from the resource manager in response to a request to externalize the current value for that attribute */
typedef uint8_t*   mach_voucher_attr_content_t;
typedef uint32_t   mach_voucher_attr_content_size_t;
/** The private verbs implemented by each voucher attribute manager via mach_voucher_attr_command() */
typedef uint32_t   mach_voucher_attr_command_t;
/** The verbs used to create/morph a voucher attribute value */
typedef uint32_t   mach_voucher_attr_recipe_command_t;
typedef mach_voucher_attr_recipe_command_t*   mach_voucher_attr_recipe_command_array_t;
#define MACH_VOUCHER_ATTR_NOOP   ((mach_voucher_attr_recipe_command_t)0)
#define MACH_VOUCHER_ATTR_COPY   ((mach_voucher_attr_recipe_command_t)1)
#define MACH_VOUCHER_ATTR_REMOVE   ((mach_voucher_attr_recipe_command_t)2)
#define MACH_VOUCHER_ATTR_SET_VALUE_HANDLE   ((mach_voucher_attr_recipe_command_t)3)
#define MACH_VOUCHER_ATTR_REDEEM   ((mach_voucher_attr_recipe_command_t)10)
#define MACH_VOUCHER_ATTR_IMPORTANCE_SELF   ((mach_voucher_attr_recipe_command_t)200)
#define MACH_VOUCHER_ATTR_USER_DATA_STORE   ((mach_voucher_attr_recipe_command_t)211)
#define MACH_VOUCHER_ATTR_BITS_STORE   MACH_VOUCHER_ATTR_USER_DATA_STORE
#define MACH_VOUCHER_ATTR_TEST_STORE   MACH_VOUCHER_ATTR_USER_DATA_STORE
/** The key used to identify a particular managed resource or to select the specific resource manager's data associated with a given voucher */
typedef uint32_t   mach_voucher_attr_key_t;
typedef mach_voucher_attr_key_t*   mach_voucher_attr_key_array_t;
#define MACH_VOUCHER_ATTR_KEY_ALL   ((mach_voucher_attr_key_t)~0)
#define MACH_VOUCHER_ATTR_KEY_NONE   ((mach_voucher_attr_key_t)0)
#define MACH_VOUCHER_ATTR_KEY_ATM   ((mach_voucher_attr_key_t)1)
#define MACH_VOUCHER_ATTR_KEY_IMPORTANCE   ((mach_voucher_attr_key_t)2)
#define MACH_VOUCHER_ATTR_KEY_BANK   ((mach_voucher_attr_key_t)3)
#define MACH_VOUCHER_ATTR_KEY_USER_DATA   ((mach_voucher_attr_key_t)7)
#define MACH_VOUCHER_ATTR_KEY_BITS   MACH_VOUCHER_ATTR_KEY_USER_DATA
#define MACH_VOUCHER_ATTR_KEY_TEST   ((mach_voucher_attr_key_t)8)
#define MACH_VOUCHER_ATTR_KEY_NUM_WELL_KNOWN   MACH_VOUCHER_ATTR_KEY_TEST
/** A handle provided to the voucher attribute manager for a given attribute key through which it makes inquiries or control operations of the mach voucher mechanism */
typedef mach_port_t   mach_voucher_attr_control_t;
#define MACH_VOUCHER_ATTR_CONTROL_NULL   ((mach_voucher_attr_control_t)0)
typedef mach_port_t   ipc_voucher_attr_manager_t;
typedef mach_port_t   ipc_voucher_attr_control_t;
#define IPC_VOUCHER_ATTR_MANAGER_NULL   ((ipc_voucher_attr_manager_t)0)
#define IPC_VOUCHER_ATTR_CONTROL_NULL   ((ipc_voucher_attr_control_t)0)
typedef uint32_t   mach_voucher_attr_value_reference_t;
typedef uint32_t   mach_voucher_attr_control_flags_t;
#define MACH_VOUCHER_ATTR_CONTROL_FLAGS_NONE   ((mach_voucher_attr_control_flags_t)0)
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
#define MACH_VOUCHER_ATTR_MANAGER_NULL   ((mach_voucher_attr_manager_t)0)
typedef mach_voucher_attr_value_handle_t*   mach_voucher_attr_value_handle_array_t;
typedef mach_msg_type_number_t   mach_voucher_attr_value_handle_array_size_t;
#define MACH_VOUCHER_ATTR_VALUE_MAX_NESTED   ((mach_voucher_attr_value_handle_array_size_t)4)


#if (!(defined(ATM_ATM_TYPES_H) || defined(_ATM_ATM_TYPES_H) || defined(_ATM_ATM_TYPES_H_)))
#define ATM_ATM_TYPES_H   (1)
#define _ATM_ATM_TYPES_H   (1)
#define _ATM_ATM_TYPES_H_   (1)


#define ATM_ACTION_DISCARD   1
#define ATM_ACTION_COLLECT   2
#define ATM_ACTION_LOGFAIL   3
#define ATM_FIND_MIN_SUB_AID   4
#define ATM_ACTION_UNREGISTER   5
#define ATM_ACTION_REGISTER   6
#define ATM_ACTION_GETSUBAID   7
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


#endif  // ATM_ATM_TYPES_H


#if (!(defined(BANK_BANK_TYPES_H) || defined(_BANK_BANK_TYPES_H) || defined(_BANK_BANK_TYPES_H_)))
#define BANK_BANK_TYPES_H   (1)
#define _BANK_BANK_TYPES_H   (1)
#define _BANK_BANK_TYPES_H_   (1)


#define MACH_VOUCHER_ATTR_BANK_NULL    ((mach_voucher_attr_recipe_command_t)601)
#define MACH_VOUCHER_ATTR_BANK_CREATE    ((mach_voucher_attr_recipe_command_t)610)
#define MACH_VOUCHER_BANK_CONTENT_SIZE   (500)
#define BANK_ORIGINATOR_PID   0x1
typedef uint32_t    bank_action_t;


#endif  // BANK_BANK_TYPES_H


#endif  // MACH_DATATYPES_H


// MINIX DATATYPES

/** Virtual addresses/lengths in bytes */
typedef long unsigned int   vir_bytes;
#ifdef OSMINIX
/** Asynchronous API */
typedef int   bdev_id_t;
typedef void*   bdev_param_t;
typedef struct attr_packed bdev_callback {
	dev_t dev;
	bdev_id_t _id;
	bdev_param_t param;
	int result;
} bdev_callback_t;
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
#   define phys_cp_req   vir_cp_req
#   define phys_cp_req_t   vir_cp_req_t
/** Structures for SYS_VUMAP */
typedef struct vumap_vir {
	union __union_vv_u {
		cp_grant_id_t u_grant;  // Grant identifier, for non-SELF endpoint
		vir_bytes u_addr;  // Local virtual address, for SELF endpoint
	} vv_u;
	size_t vv_size;  // Size in bytes
} vumap_vir_t;
#   define vv_grant   vv_u.u_grant
#   define vv_addr   vv_u.u_addr
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
#   define FHANDLE30_SIZE   sizeof(compat_30_fhandle_t)
#   ifndef block_t
/** Block number datatype */
typedef uint32_t   block_t;
#   endif
#   ifndef zone_t
/** Zone number datatype */
typedef uint32_t   zone_t;
#   endif
#   ifndef bit_t
/** Datatype for bit numbers in bitmaps */
typedef uint32_t   bit_t;
#   endif
#   ifndef bitchunk_t
/** Datatype for collections of bits in bitmaps */
typedef uint32_t   bitchunk_t;
#   endif
typedef struct fs_size {
	ino_t inocount;  // Amount of inodes
	zone_t zonecount;  // Amount of zones
	block_t blockcount;  // Amount of blocks
} fs_size_t;
/** Zone number datatype for V1 filesystems */
typedef uint16_t   zone1_t;
#endif


// PLAN9 DATATYPES

/** Print format datatype */
typedef struct attr_packed Fmt {
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
#ifdef OSPLAN9
enum FMT_enum {
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
typedef struct Lock { long key, sem; }   Lock;
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
enum rfork_enum {
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
#endif


// QNX DATATYPES (Originally by Richard Frowijn)

#ifdef OSQNX
typedef uint8_t   qnx4_ftype_t;
typedef uint16_t   qnx4_nxtnt_t;
typedef uint16_t   qnx4_mode_t;
typedef uint16_t   qnx4_muid_t;
typedef uint16_t   qnx4_mgid_t;
typedef uint16_t   qnx4_nlink_t;
typedef uint32_t   qnx4_off_t;
typedef struct qnx4_xtnt { uint32_t xtnt_blk, xtnt_size; }   qnx4_xtnt_t;
#endif


// WINDOWS DATATYPES

#define PRInt8   signed char
#define PRUint8   unsigned char
#define PRInt16   signed short
#define PRUint16   unsigned short
#define PRIntn   signed int
#define PRUintn   unsigned int
#if (BYTES_PER_INT == 4)
#   define PRInt32   signed int
#   define PRUint32   unsigned int
#   define PR_INT32(x)   x
#   define PR_UINT32(x)   x ## U
#elif LONG_EQ_32BITS
#   define PRInt32   signed long
#   define PRUint32   unsigned long
#   define PR_INT32(x)   x ## L
#   define PR_UINT32(x)   x ## UL
#else
#   error   "No suitable type found for PRInt32/PRUint32!"
#endif
#if (LONG_EQ_64BITS && (!defined(ALTERNATE_INT64_TYPEDEF)))
#   define PRInt64   signed long
#   define PRUint64   unsigned long
#   define PR_INT64(x)   x ## L
#   define PR_UINT64(x)   x ## UL
#elif (defined(OSWINDOWS) && IS_32 && IS_NOT_GNUC)
#   define PRInt64   int64_t
#   define PRUint64   uint64_t
#   define PR_INT64(x)   x ## i64
#   define PR_UINT64(x)   x ## ui64
#else
#   define PRInt64   signed long long
#   define PRUint64   unsigned long long
#   define PR_INT64(x)   x ## LL
#   define PR_UINT64(x)   x ## ULL
#endif
#define PRFloat64   double
#define PRSize   size_t
#define PROffset32   PRInt32
#define PROffset64   PRInt64
#define PRPtrdiff   ptrdiff_t
#ifndef __PRUNICHAR__
#   define __PRUNICHAR__
#   ifdef WIN32
typedef wchar_t   PRUnichar;
#   else
typedef PRUint16   PRUnichar;
#   endif
#endif
#if (defined(OSWINDOWS) || IS_WORDSIZE_64)
typedef PRInt64   PRWord;
typedef PRUint64   PRUword;
typedef PRUint64   PRUptrdiff;
#else
typedef long   PRWord;
typedef unsigned long   PRUword;
typedef unsigned long   PRUptrdiff;
#endif
/** @def WORD
A datatype that has the length of the system's wordsize */
/** @def DWORD
A datatype that is twice the length of the system's wordsize */
#ifdef OSWINDOWS
typedef uint16_t   WORD;
typedef uint32_t   DWORD;
typedef struct _W32CLIENTINFO {
	unsigned long CI_flags;
	unsigned long cSpins;
	unsigned long ulWindowsVersion;
	unsigned long ulAppCompatFlags;
	unsigned long ulAppCompatFlags2;
	unsigned long W32ClientInfo[57];
} W32CLIENTINFO;
#else
typedef Wtype   WORD;
typedef DWtype   DWORD;
#endif  // OSWINDOWS
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
typedef WORD*   PWORD;
typedef WORD*   LPWORD;
typedef DWORD*   PDWORD;
typedef DWORD*   LPDWORD;
typedef DWORD   COLORREF;
typedef DWORD*   LPCOLORREF;
#ifndef _FILETIME_
typedef struct _FILETIME { DWORD dwLowDateTime, dwHighDateTime; }   FILETIME;
#   define _FILETIME_   FILETIME
typedef FILETIME*   PFILETIME;
typedef FILETIME*   LPFILETIME;
#endif


// XNU & MACINTOSH DATATYPES

#ifdef ALLOW_XNU_DATATYPES_H
#   if IS_BIG_ENDIAN
typedef struct wide { int32_t hi; uint32_t lo; }   wide;
typedef struct UnsignedWide { uint32_t hi, lo; }   UnsignedWide;
#   else
typedef struct wide { uint32_t lo; int32_t hi; }   wide;
typedef struct UnsignedWide { uint32_t lo, hi; }   UnsignedWide;
#   endif  // IS_BIG_ENDIAN
/** 8-bit signed integer plus 8-bit fraction */
typedef int16_t   ShortFixed;
typedef int16_t*   ShortFixedPtr;
/** 16-bit signed integer plus 16-bit fraction */
typedef int32_t   Fixed;
typedef int32_t*   FixedPtr;
/** 16-bit unsigned integer plus 16-bit fraction */
typedef uint32_t   UnsignedFixed;
typedef UnsignedFixed*   UnsignedFixedPtr;
typedef char*   Ptr;
typedef Ptr*   Handle;
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
#   ifdef DATAMODEL_LP64
typedef void*   URefCon;
typedef void*   SRefCon;
#   else
typedef uint32_t   URefCon;
typedef int32_t   SRefCon;
#   endif
/** OSErr: function performed properly - no error */
#   define noErr   0
/** OptionBits: all flags false */
#   define kNilOptions   0
/** NULL is for pointers as kInvalidID is for ID's */
#   define kInvalidID   0
/** Array bounds: variable length array */
#   define kVariableLengthArray   1
/** QuickTime 3.0: default unknown ResType or OSType */
#   define kUnknownType   0x3f3f3f3f
typedef UniChar*   UniCharArrayPtr;
typedef const UniChar*   ConstUniCharArrayPtr;
typedef UniChar*   UniCharPtr;
/** A count of UTF-16 code values in an array or buffer */
typedef unsigned long   UniCharCount;
typedef UniCharCount*   UniCharCountPtr;
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
#   define StrLength(_string)   (*(unsigned char*)(_string))
#   if (defined(OLDROUTINENAMES) && OLDROUTINENAMES)
#      define Length(_string)   StrLength(_string)
#   endif
typedef wide*   WidePtr;
typedef UnsignedWide*   UnsignedWidePtr;
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
typedef enum kxld_flags { kKxldFlagDefault = 0, kKXLDFlagIncludeRelocs = 1 }   KXLDFlags;
/** Flags for the allocation callback */
typedef enum kxld_allocate_flags { kKxldAllocateDefault = 0, kKxldAllocateWritable = 1 }   KXLDAllocateFlags;
/** Flags for the logging callback */
typedef enum kxld_log_subsystem { kKxldLogLinking = 0, kKxldLogPatching = 1 }   KXLDLogSubsystem;
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
#endif  // XNU & MACINTOSH DATATYPES


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

#if (!(defined(BITS_IPCTYPES_H) || defined(_BITS_IPCTYPES_H) || defined(IPCTYPES_H) || defined(_IPCTYPES_H) || defined(_IPCTYPES_H_)))
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


// DATATYPES FOR EMBEDDED DEVICES

#if ((!defined(EMBEDDED_DEVICE_DATATYPES_H)) && defined(ALLOW_HEADER_EMBEDDED_DEVICE_DATATYPES_H))
#define EMBEDDED_DEVICE_DATATYPES_H   (1)


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
	@brief Write a specified number of bytes to the stream
	@param[in,out] bytes The input buffer
	@param[in] numBytes The number of bytes to write
	@return The number of bytes written to the stream
*/
	uint16_t (*writeBytes)(const char* bytes, uint16_t numBytes);
/**
	@brief   Write a line to the stream. Line ending characters (determined by the implementation function) will be appended
	@param[in] line Pointer to the start of a NULL-terminated string containing the text to be written. Line ending characters will be added and so are not required
	@return The number of bytes written to the stream
*/
	uint16_t (*writeLine)(const char* dataline);
/**
	@brief Query the number of bytes available to read
	@return The number of bytes available to read
*/
	uint16_t (*bytesAvailableToRead)(void);
/**
	@brief Inspect a byte in the stream's buffer without removing it
	@param[in] depth Distance from the front of the read queue (i.e. the next byte to be read has depth 0, the byte after that has depth 1 and so on)
	@return In the case of an error, return an implementation-specific error code; otherwise, this is the found value
*/
	char (*peek)(uint16_t depth);
/**
	@brief Read a specified number of bytes from the stream. If insufficient bytes are available, read all available bytes
	@param[in,out] buf The target buffer
	@param[in] numBytes The requested number of bytes
	@return The number of bytes read
*/
	uint16_t (*readBytes)(char* buf, uint16_t numBytes);
/**
	@brief Read the next available line from the stream. The implementation must define the line-ending sequence it uses to determine when a line is available. Line-ending characters are removed and the function outputs a NULL-terminated string
	@param[in,out] buffer The target buffer
	@return The length of the output string *not* including the NULL-terminator
*/
	uint16_t (*readLine)(char* buf);
/**
	@brief Read the next available line from the stream but truncate the output.
	@param[in,out] buffer The target buffer
	@param[in] maxLen The maximum permissible length of the output (including the NULL-terminator) in bytes
	@return The length of the output string *not* including the NULL-terminator
*/
	uint16_t (*readLineTruncate)(char* buf, uint16_t maxLen);
} IOStream_t;


#endif  // EMBEDDED_DEVICE_DATATYPES_H


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


// MISCELLANEOUS DATATYPES

typedef unsigned char   cc_t;
typedef uint32_t   speed_t;
typedef uint32_t   tcflag_t;
/** comp_t is a 16-bit "floating" point number with a 3-bit base 8 exponent and a 13-bit fraction */
typedef uint16_t   comp_t;
typedef unsigned long long   fxvalue;
typedef unsigned short   fxmask1;
typedef unsigned short   fxmaskf;
typedef unsigned short   fxmaskg;
typedef unsigned short   fxmaskc;
typedef unsigned short   fxmaskr;
typedef unsigned long   fxmask2;
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
typedef char*   data_t;
typedef char   string_t[1024];
typedef unsigned char   bitstr_t;
typedef int*   intarray_t;
typedef struct attr_packed ustat {
#   if (defined(ARCHMIPS) || (defined(ARCHSPARC) && (!defined(ARCHAARCH64))))
	long f_tfree;
#   else
	int f_tfree;
#   endif
	unsigned long f_tinode;
	char f_fname[6];
	char f_fpack[6];
} ustat_t;
#define __asan_bad_ustat   ustat_t
/** offset of a char string in log needs to be aligned on some systems because it is passed to db_set as a string */
typedef struct log_t_struct {
	char data[SIZEOF_CHAR + 4];
	char str[1];
} log_t;
#define CHAR_T_OFFSET   ((char*)(((log_t*)0)->str) - (char*)0)
/** Structure for building "argc/argv" vector of arguments */
typedef struct attr_packed __args {
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

/** Structure giving information about numeric and monetary notation */
typedef struct attr_packed lconv {
	// Numeric (non-monetary) information
	/** Decimal point character */
	const char* decimal_point;
	/** Thousands separator */
	const char* thousands_sep;
	/** Specifies the amount of digits that form each of the groups to be separated by thousands_sep separator for non-monetary quantities. This is a zero-terminated sequence of char values that may contain different grouping sizes for each successive group starting from the right, each number indicating the amount of digits for the group; the last number before the ending zero in this string is used for the remaining groups */
	const char* grouping;
	// Monetary information
	/** First three chars are a currency symbol from ISO4217, the fourth char is the separator, and the fifth char is '\0' */
	const char* int_curr_symbol;
	/** Local currency symbol */
	const char* currency_symbol;
	/** Decimal point character */
	const char* mon_decimal_point;
	/** Thousands separator */
	const char* mon_thousands_sep;
	/** Like `grouping` element (above) */
	const char* mon_grouping;
	/** Sign for positive values */
	const char* positive_sign;
	/** Sign for negative values */
	const char* negative_sign;
	/** International fractional digits */
	char int_frac_digits;
	/** Local fractional digits */
	char frac_digits;
	/** 1 if currency_symbol precedes a positive value, 0 if succeeds */
	char p_cs_precedes;
	/** 1 if a space separates currency_symbol from a positive value */
	char p_sep_by_space;
	/** 1 if currency_symbol precedes a negative value, 0 if succeeds */
	char n_cs_precedes;
	/** 1 iff a space separates currency_symbol from a negative value */
	char n_sep_by_space;
	/** Positive and negative sign positions:
	 - 0: Parentheses surround the quantity and currency_symbol
	 - 1: The sign string precedes the quantity and currency_symbol
	 - 2: The sign string follows the quantity and currency_symbol
	 - 3: The sign string immediately precedes the currency_symbol
	 - 4: The sign string immediately follows the currency_symbol
	*/
	char p_sign_posn, n_sign_posn;
	/** 1 if int_curr_symbol precedes a positive value, 0 if succeeds */
	char int_p_cs_precedes;
	/** 1 iff a space separates int_curr_symbol from a positive value */
	char int_p_sep_by_space;
	/** 1 if int_curr_symbol precedes a negative value, 0 if succeeds */
	char int_n_cs_precedes;
	/** 1 iff a space separates int_curr_symbol from a negative value */
	char int_n_sep_by_space;
	/** Positive and negative sign positions:
	 - 0: Parentheses surround the quantity and int_curr_symbol
	 - 1: The sign string precedes the quantity and int_curr_symbol
	 - 2: The sign string follows the quantity and int_curr_symbol
	 - 3: The sign string immediately precedes the int_curr_symbol
	 - 4: The sign string immediately follows the int_curr_symbol
	*/
	char int_p_sign_posn, int_n_sign_posn;
} lconv_t;

/** Datatype used by the message catalog functions catopen(), catgets(), and catclose() to identify a catalog descriptor */
typedef void*   nl_catd;
/** Datatype used by nl_langinfo() to identify items of langinfo data */
typedef signed int   nl_item;
#define nl_item_t   nl_item
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


// SIGNALLING & THREAD DATATYPES

typedef enum krw { RW_READER = 0, RW_WRITER = 1 }   krw_t;
typedef struct krwlock { volatile uintptr_t rw_owner; }   krwlock_t;
typedef struct raw_spinlock { volatile unsigned int lock; }   raw_spinlock_t;
typedef struct raw_rwlock { volatile unsigned int lock; }   raw_rwlock_t;
typedef struct rwlock { raw_rwlock_t raw_lock; }   rwlock_t;
/** Data structure to describe a process schedulability */
typedef struct sched_param { int sched_priority; }   sched_param_t;
#define __defined_schedparam   (1)
#ifdef __need_schedparam
#   undef __need_schedparam
#endif
#if IS_REENTRANT
extern UNUSED rwlock_t __sfp_lock;
#endif
#ifndef __DEFINED_mtx_t
/** Used for mutexes */
typedef struct mtx { union { int __i[10]; volatile int __vi[10]; volatile void* volatile __p[5]; } __u; }   mtx_t;
#   define __DEFINED_mtx_t   (1)
#endif
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
typedef struct sigev_thread {
	void(*_function)(sigval_t);
	void* _attribute;
} sigev_thread_t;
typedef struct attr_packed sigevent {
	sigval_t sigev_value;
	int32_t sigev_signo, sigev_notify;
	union attr_packed _sigev_un {
		int32_t _pad[SIGEV_PAD_SIZE];
		int32_t _tid;
		sigev_thread_t _sigev_thread;
	} _sigev_un;
} sigevent_t;
#define sigev_notify_function   _sigev_un._sigev_thread._function
#define sigev_notify_attributes   _sigev_un._sigev_thread._attribute
#define sigev_notify_thread_id  _sigev_un._tid
#ifdef ARCHSPARC64
typedef int32_t   band_t;
#else
typedef long   band_t;
#endif
#define __band_t   band_t


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
#if (defined(ARCHX86) || defined(ARCHPOWERPC) || defined(ARCHARM) || defined(ARCHS390) || defined(ARCHITANIUM))
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
#elif defined(ARCHPARISC)
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
#ifdef ARCHPARISC
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
#elif defined(ARCHPARISC)
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
#ifndef NSIG
/** Biggest signal number + 1 (including real-time signals) */
#   define NSIG   (65)
#endif
#ifndef _NSIG
/** Biggest signal number + 1 (including real-time signals) */
#   define _NSIG   NSIG
#endif
#ifndef NSIG_S3
/** Right-shift NSIG three places (NSIG >> 3) */
#   define NSIG_S3   (NSIG >> 3)
#endif
// Real-time signal range
#ifndef __SIGRTMIN
#   define __SIGRTMIN   SIGRTMIN
#endif
#define __SIGRTMAX   (NSIG - 1)
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
#   error   "Missing/Invalid __SIGRTMAX and __SIGRTMIN values!"
#endif
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
#define __kernel_sighandler_t   sighandler_t
/** Signal handler datatype */
typedef sighandler_t   sig_t;  // 4.4 BSD
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
#define SIG_ERR   ((sighandler_t)-1)
/** Default action */
#define SIG_DFL   ((sighandler_t)0)
/** Ignore signal */
#define SIG_IGN   ((sighandler_t)1)
/** Add signal to hold mask */
#define SIG_HOLD  ((sighandler_t)2)


// SIGACTION STRUCT

#if (!(defined(BITS_SIGACTION_STRUCT_H) || defined(_BITS_SIGACTION_STRUCT_H) || defined(_BITS_SIGACTION_STRUCT_H_)))
#define BITS_SIGACTION_STRUCT_H  (1)
#define _BITS_SIGACTION_STRUCT_H  (1)
#define _BITS_SIGACTION_STRUCT_H_  (1)


#ifdef ARCHALPHA

/** Structure describing the action to be taken when a signal arrives */
struct sigaction {
	__sighandler_t sa_handler;
	unsigned int sa_flags;
	sigset_t sa_mask;
};
// Bits in `sa_flags`
/** Do not send SIGCHLD when children stop */
#   define SA_NOCLDSTOP   4
/** Do not create zombie on child death */
#   define SA_NOCLDWAIT   0x20
/** Invoke signal-catching function with three arguments instead of one */
#   define SA_SIGINFO   0x40
/** Use signal stack by using `sa_restorer' */
#   define SA_ONSTACK   1
/** Restart syscall on signal return */
#   define SA_RESTART   2
/** Do not automatically block the signal when its handler is being executed */
#   define SA_NODEFER   8
/** Reset to SIG_DFL on entry to handler */
#   define SA_RESETHAND   0x10
/** Historical no-op */
#   define SA_INTERRUPT   0x20000000
// Some aliases for the SA_ constants
#   define SA_NOMASK   SA_NODEFER
#   define SA_ONESHOT   SA_RESETHAND
#   define SA_STACK   SA_ONSTACK
// Values for the HOW argument to `sigprocmask`
/** Block signals */
#   define SIG_BLOCK   1
/** Unblock signals */
#   define SIG_UNBLOCK   2
/** Set the set of blocked signals */
#   define SIG_SETMASK   3

#elif defined(ARCHITANIUM)

/** Structure describing the action to be taken when a signal arrives */
struct sigaction {
	__sighandler_t sa_handler;
	unsigned long sa_flags;
	sigset_t sa_mask;
};
// Bits in `sa_flags`
/** Do not send SIGCHLD when children stop */
#   define SA_NOCLDSTOP   1
/** Do not create zombie on child death */
#   define SA_NOCLDWAIT   2
#   define SA_SIGINFO    4
/** Use signal stack by using `sa_restorer` */
#   define SA_ONSTACK   0x8000000
/** Restart syscall on signal return */
#   define SA_RESTART   0x10000000
/** Do not automatically block the signal when its handler is being executed */
#   define SA_NODEFER   0x40000000
/** Reset to SIG_DFL on entry to handler */
#   define SA_RESETHAND   0x80000000
/** Historic no-op */
#   define SA_INTERRUPT   0x20000000
// Some aliases for the SA_ constants
#   define SA_NOMASK   SA_NODEFER
#   define SA_ONESHOT   SA_RESETHAND
#   define SA_STACK   SA_ONSTACK
// Values for the HOW argument to `sigprocmask`
/** for blocking signals */
#   define SIG_BLOCK   0
/** for unblocking signals */
#   define SIG_UNBLOCK   1
/** Used for setting the signal mask */
#   define SIG_SETMASK   2

#elif defined(ARCHPARISC)

/** Structure describing the action to be taken when a signal arrives */
struct sigaction {
	__sighandler_t sa_handler;
	unsigned long sa_flags;
	sigset_t sa_mask;
};
// Bits in `sa_flags`
/** Do not send SIGCHLD when children stop */
#   define SA_NOCLDSTOP   8
/** Do not create zombie on child death */
#   define SA_NOCLDWAIT   0x80
/** Invoke signal-catching function with three arguments instead of one */
#   define SA_SIGINFO   0x10
/** Use signal stack by using `sa_restorer` */
#   define SA_ONSTACK   1
/** Reset to SIG_DFL on entry to handler */
#   define SA_RESETHAND   4
/** Do not automatically block the signal when its handler is being executed */
#   define SA_NODEFER   0x20
/** Restart syscall on signal return */
#   define SA_RESTART   0x40
/** Historic no-op */
#   define SA_INTERRUPT   0x20000000
// Some aliases for the SA_ constants
#   define SA_NOMASK   SA_NODEFER
#   define SA_ONESHOT   SA_RESETHAND
#   define SA_STACK   SA_ONSTACK
// Values for the HOW argument to `sigprocmask`
/** for blocking signals */
#   define SIG_BLOCK   0
/** for unblocking signals */
#   define SIG_UNBLOCK   1
/** for setting the signal mask */
#   define SIG_SETMASK   2

#elif defined(ARCHMIPS)

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
#   define SA_NOCLDSTOP   1
/** Do not create zombie on child death */
#   define SA_NOCLDWAIT   0x10000
/** Invoke signal-catching function with three arguments instead of one */
#   define SA_SIGINFO   8
/** Use signal stack by using `sa_restorer` */
#   define SA_ONSTACK   0x8000000
/** Reset to SIG_DFL on entry to handler */
#   define SA_RESETHAND   0x80000000
/** Restart syscall on signal return */
#   define SA_RESTART   0x10000000
/** Do not automatically block the signal when its handler is being executed */
#   define SA_NODEFER   0x40000000
/** Historical no-op */
#   define SA_INTERRUPT   0x20000000
// Some aliases for the SA_ constants
#   define SA_NOMASK   SA_NODEFER
#   define SA_ONESHOT   SA_RESETHAND
#   define SA_STACK   SA_ONSTACK
// Values for the HOW argument to `sigprocmask`
/** 0 is unused to catch errors */
#   define SIG_NOP   0
/** Block signals */
#   define SIG_BLOCK   1
/** Unblock signals */
#   define SIG_UNBLOCK   2
/** Set the set of blocked signals */
#   define SIG_SETMASK   3
/** From SGI for BSD compatibility: set only the low 32 bit of the sigset */
#   define SIG_SETMASK32   256

#elif defined(ARCHSPARC)

/** Structure describing the action to be taken when a signal arrives */
struct sigaction {
	__sighandler_t sa_handler;
	unsigned long sa_flags;
	void (*sa_restorer)(void);
	sigset_t sa_mask;
};
// Bits in `sa_flags`
/** Do not send SIGCHLD when children stop */
#   define SA_NOCLDSTOP   8
/** Do not create zombie on child death */
#   define SA_NOCLDWAIT   0x100
/** Invoke signal-catching function with three arguments instead of one */
#   define SA_SIGINFO   0x200
/** Use signal stack by using `sa_restorer` */
#   define SA_ONSTACK   1
/** Restart syscall on signal return */
#   define SA_RESTART   2
/** Historical no-op */
#   define SA_INTERRUPT   0x10
/** Do not automatically block the signal when its handler is being executed */
#   define SA_NOMASK   0x20
/** Reset to SIG_DFL on entry to handler */
#   define SA_ONESHOT   4
// Some aliases for the SA_ constants
#   define SA_NODEFER   SA_NOMASK
#   define SA_RESETHAND   SA_ONESHOT
#   define SA_STACK   SA_ONSTACK
// Values for the HOW argument to `sigprocmask`
/** Block signals */
#   define SIG_BLOCK   1
/** Unblock signals */
#   define SIG_UNBLOCK   2
/** Set the set of blocked signals */
#   define SIG_SETMASK   4

#else

/** Structure describing the action to be taken when a signal arrives */
struct sigaction {
	__sighandler_t sa_handler;
	unsigned long sa_flags;
	void (*sa_restorer)(void);
	sigset_t sa_mask;
};
// Bits in `sa_flags`
/** Do not send SIGCHLD when children stop */
#   define SA_NOCLDSTOP   1
/** Do not create zombie on child death */
#   define SA_NOCLDWAIT   2
/** Invoke signal-catching function with three arguments instead of one */
#   define SA_SIGINFO   4
/** Use signal stack by using `sa_restorer` */
#   define SA_ONSTACK   0x8000000
/** Restart syscall on signal return */
#   define SA_RESTART   0x10000000
/** Do not automatically block the signal when its handler is being executed */
#   define SA_NODEFER   0x40000000
/** Reset to SIG_DFL on entry to handler */
#   define SA_RESETHAND   0x80000000
/** Historical no-op */
#   define SA_INTERRUPT   0x20000000
// Some aliases for the SA_ constants
#   define SA_NOMASK   SA_NODEFER
#   define SA_ONESHOT   SA_RESETHAND
#   define SA_STACK   SA_ONSTACK
// Values for the HOW argument to `sigprocmask`
/** Block signals */
#   define SIG_BLOCK   0
/** Unblock signals */
#   define SIG_UNBLOCK   1
/** Set the set of blocked signals */
#   define SIG_SETMASK   2

#endif


#endif  // BITS_SIGACTION_STRUCT_H


// JUMP DATATYPES

#ifdef ARCHALPHA
typedef long   __jmp_buf[17];
#elif defined(ARCHARC)
typedef int   __jmp_buf[16];  // r13-r25, fp, sp, blink
#elif defined(ARCHARM)
#   ifdef __ARM_EABI__
typedef int align8   __jmp_buf[64];
#   elif (defined(__MAVERICK__) || defined(__IWMMXT__))
typedef int   __jmp_buf[34];
#   else
#      ifdef IS_HARDFP
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
#elif defined(ARCHX86)
#   if IS_WORDSIZE_64
typedef greg_t   __jmp_buf[8];
#   else
typedef greg_t   __jmp_buf[6];
#   endif
#elif defined(ARCHITANIUM)
typedef long align16   __jmp_buf[70];
#elif defined(ARCHM68K)
typedef struct jmp_buf {
	long __dregs[7];
	int* __aregs[6];
	int* __fp;
	int* __sp;
#   if (defined(__HAVE_68881__) || IS_HARDFP)
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
#   ifdef ARCHMIPS64
	int __regs[8];
#   else
	long long __regs[8];
#   endif
	void *__fp, *__gp;
	int __fpc_csr;
#   ifdef ARCHMIPS64
	double __fpregs[8];
#   else
	double __fpregs[6];
#   endif
} __jmp_buf[1];
#elif defined(ARCHPARISC)
typedef double   __jmp_buf[21];
#elif defined(ARCHPOWERPC)
#   if IS_WORDSIZE_64
typedef greg_t align16   __jmp_buf[64];
#   else
typedef greg_t align16   __jmp_buf[112];
#   endif
#elif defined(ARCHSUPERH)
typedef struct jmp_buf {
	int __regs[8];
	void * __pc, * __gbr;
	int __fpscr;
	int __fpregs[4];
} __jmp_buf[1];
#elif defined(ARCHSPARC)
typedef greg_t   __jmp_buf[3];
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
struct attr_packed jmp_buf_tag {
	__jmp_buf __jmpbuf;  // Calling environment
	int __mask_was_saved;  // Saved the signal mask
	sigset_t __saved_mask;  // Saved signal mask
};
typedef struct jmp_buf_tag   jmp_buf[1];
/** The `__mask_was_saved` flag determines whether or not `longjmp` will restore the signal mask */
#define sigjmp_buf   jmp_buf
typedef jmp_buf   osjmpbuf;
/** jmp_buf is in a structure so that we can declare pointers to jump locations; The global variable `handler` contains the location to jump to when an exception occurs; and the global variable `exception` contains a code identifying the exeception */
typedef struct jmploc { jmp_buf loc; }   jmploc_t;
extern struct jmploc* handler;


// POSIX THREAD (PTHREAD) DATATYPES

typedef struct rusage {
	struct timeval ru_utime, ru_stime;
	long ru_maxrss, ru_ixrss, ru_idrss, ru_isrss;
	long ru_minflt, ru_majflt, ru_nswap, ru_inblock;
	long ru_oublock, ru_msgsnd, ru_msgrcv, ru_nsignals, ru_nvcsw, ru_nivcsw;
} rusage_t;
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
typedef union pthread_attr {
	char __size[SIZEOF_PTHREAD_ATTR_T]; long __align;
} pthread_attr_t;
typedef struct __pthread_internal_list {
	struct __pthread_internal_list *__prev, *__next;
} __pthread_list_t;
typedef struct __pthread_internal_slist {
	struct __pthread_internal_slist* __next;
} __pthread_slist_t;
#define __DEFINED_pthread_once_t   (1)
#ifdef ARCHM68K  // pthread_once_t
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
	char __size[SIZEOF_PTHREAD_BARRIER_T];
	long __align;
} pthread_barrier_t;
#define __DEFINED_pthread_barrierattr_t   (1)
/** POSIX barrier attribute datatype */
typedef union pthread_barrierattr {
	char __size[SIZEOF_PTHREAD_BARRIERATTR_T];
	int __align;
} pthread_barrierattr_t;
/** Data structure to contain the action information */
struct __spawn_action {
	enum __spawn_action_tag { spawn_do_close, spawn_do_dup2, spawn_do_open } tag;
	union __union__spawn_action {
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
#ifdef ARCHPARISC
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
#   ifdef PTHREAD_HANDLE_DNS_CORRECT
	int h_errno;
	struct res_state __res;
#   endif
};
typedef struct _pthread_descr_struct*   _pthread_descr;
#define __DEFINED_pthread_mutex_t   (1)
#if (defined(ARCHAARCH64))  // pthread_mutex_t
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
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#   define __PTHREAD_MUTEX_HAVE_PREV   1
#elif defined(ARCHAARCH32)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner
		int __kind;
		unsigned int __nusers;
		union __union_mutex_spins {
			int __spins;
			__pthread_slist_t __list;
		} mutex_spins;
	} __data;
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(ARCHALPHA)
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
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#   define __PTHREAD_MUTEX_HAVE_PREV   1
#elif defined(ARCHARC)
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
		union __union_mutex_spins {
			int __spins;
			__pthread_slist_t __list;
		} mutex_spins;
#   endif
	} __data;
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(ARCHPARISC)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int align16 __lock;
		unsigned int __count;
		_pthread_descr __owner;
		int __kind;
		int __compat_padding[4];
		unsigned int __nusers;
		union __union_mutex_spins {
			int __spins;
			__pthread_slist_t __list;
		} mutex_spins;
		int __reserved1, __reserved2;
	} __data;
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(ARCHITANIUM)
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
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#   define __PTHREAD_MUTEX_HAVE_PREV   1
#elif defined(ARCHPOWERPC)
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
		union __union_mutex_spins {
			struct {
				short __espins;
				short __elision;
			} __elision_data;
			__pthread_slist_t __list;
		} mutex_spins;
#      define __spins   __elision_data.__espins
#      define __elision   __elision_data.__elision
#      define __PTHREAD_SPINS   { 0, 0 }
#   endif
	} __data;
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif (defined(ARCHM68K) || defined(ARCHMICROBLAZE) || defined(ARCHNIOS2) || defined(ARCHSUPERH))
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
		int __kind;
		unsigned int __nusers;
		union __union_mutex_spins {
			int __spins;
			__pthread_slist_t __list;
		} mutex_spins;
	} __data;
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(ARCHMIPS)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
#   ifdef ARCHMIPS64
		unsigned int __nusers;
#   endif
		int __kind;
#   ifdef ARCHMIPS64
		int __spins;
		__pthread_list_t __list;
#      define __PTHREAD_MUTEX_HAVE_PREV   1
#   else
		unsigned int __nusers;
		union __union_mutex_spins {
			int __spins;
			__pthread_slist_t __list;
		} mutex_spins;
#   endif
	} __data;
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(ARCHS390)
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
		union __union_mutex_spins {
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
		} mutex_spins;
#endif
	} __data;
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(ARCHSPARC)
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
		union __union_mutex_spins {
			int __spins;
			__pthread_slist_t __list;
		} mutex_spins;
#   endif
	} __data;
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(ARCHTILE)
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
		union __union_mutex_spins {
			int __spins;
			__pthread_slist_t __list;
		} mutex_spins;
#   endif
	} __data;
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif (defined(ARCHX86) && (!defined(ARCHI386)))
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
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(ARCHI386)
/** Data structures for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
		int __kind;
		unsigned int __nusers;
		union __union_mutex_spins {
			int __spins;
			__pthread_slist_t __list;
		} mutex_spins;
	} __data;
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#elif defined(ARCHXTENSA)
/** Data structure for mutex handling */
typedef union pthread_mutex {
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		_pthread_descr __owner;
		int __kind;
		unsigned int __nusers;
		union __union_mutex_spins {
			int __spins;
			__pthread_slist_t __list;
		} mutex_spins;
	} __data;
	char __size[SIZEOF_PTHREAD_MUTEX_T];
	long __align;
} pthread_mutex_t;
#endif
typedef pthread_mutex_t   bc_mutex_t;
#define __DEFINED_pthread_mutexattr_t   (1)
#if (defined(ARCHARM) || defined(ARCHPARISC) || defined(ARCHNIOS2) || defined(ARCHSUPERH))
/** Mutex attribute datatype */
typedef union pthread_mutexattr {
	char __size[SIZEOF_PTHREAD_MUTEXATTR_T];
	long __align;
} pthread_mutexattr_t;
#elif (defined(ARCHALPHA) || defined(ARCHARC) || defined(ARCHITANIUM) || defined(ARCHS390) || defined(ARCHM68K) || defined(ARCHMICROBLAZE) || defined(ARCHMIPS) || defined(ARCHPOWERPC) || defined(ARCHSPARC) || defined(ARCHTILE))
/** Mutex attribute datatype */
typedef union pthread_mutexattr {
	char __size[SIZEOF_PTHREAD_MUTEXATTR_T];
	int __align;
} pthread_mutexattr_t;
#else
/** Mutex attribute datatype */
typedef union pthread_mutexattr {
	char __size[SIZEOF_PTHREAD_MUTEXATTR_T];
	int __align;
} pthread_mutexattr_t;
#endif
#define __DEFINED_pthread_rwlock_t   (1)
#ifdef ARCHAARCH64  // pthread_rwlock_t
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued,t __nr_writers_queued;
		int __writer, __shared;
		unsigned long __pad1, __pad2;
		unsigned int __flags;
	} __data;
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHAARCH32)
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
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHX86)
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
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHALPHA)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		int __writer, __shared;
		unsigned long __pad1, __pad2;
		unsigned int __flags;
	} __data;
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHARC)
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
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHPARISC)
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
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHITANIUM)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		int __writer, __shared;
		unsigned long __pad1, __pad2;
		unsigned int __flags;
	} __data;
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHM68K)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
	struct __pthread_rwlock_s {
		int align4 __lock;
		unsigned int __nr_readers, __readers_wakeup, __writer_wakeup, __nr_readers_queued, __nr_writers_queued;
		unsigned char __pad1, __pad2, __shared, __flags;
		int __writer;
	} __data;
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHMICROBLAZE)
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
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHMIPS)
/** Data structure for read-write lock variable handling */
typedef union pthread_rwlock {
#   ifdef ARCHMIPS64
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
#      if IS_BIG_ENDIAN
		unsigned char __pad1, __pad2, __shared, __flags;
#      else
		unsigned char __flags, __shared, __pad1, __pad2;
#      endif
	int __writer;
	} __data;
#   endif
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHNIOS2)
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
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHPOWERPC)
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
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif (defined(ARCHS390) || defined(ARCHSPARC))
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
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHSUPERH)
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
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHTILE)
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
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#elif defined(ARCHXTENSA)
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
	char __size[SIZEOF_PTHREAD_RWLOCK_T];
	long __align;
} pthread_rwlock_t;
#endif
#define __DEFINED_pthread_rwlockattr_t   (1)
/** Read-write lock attribute datatype */
typedef union pthread_rwlockattr {
	char __size[SIZEOF_PTHREAD_RWLOCKATTR_T];
	long __align;
} pthread_rwlockattr_t;
#define __DEFINED_pthread_cond_t   (1)
#if (defined(ARCHAARCH64) || defined(ARCHITANIUM))  // pthread_cond_t
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
	char __size[SIZEOF_PTHREAD_COND_T];
	long __align;
} pthread_cond_t;
#elif (defined(ARCHALPHA) || defined(ARCHARC) || defined(ARCHAARCH32) || defined(ARCHPARISC) || defined(ARCHM68K) || defined(ARCHMICROBLAZE) || defined(ARCHMIPS) || defined(ARCHNIOS2) || defined(ARCHPOWERPC) || defined(ARCHS390) || defined(ARCHSPARC) || defined(ARCHSUPERH) || defined(ARCHTILE))
/** Data structure for conditional variable handling */
typedef union pthread_cond {
	struct __pthread_cond_s {
#   ifdef ARCHPARISC
		int align16 __lock;
#   elif defined(ARCHM68K)
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
	char __size[SIZEOF_PTHREAD_COND_T];
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
	char __size[SIZEOF_PTHREAD_COND_T];
	long long __align;
} pthread_cond_t;
#endif
typedef pthread_cond_t   bc_cond_t;
#define __DEFINED_pthread_condattr_t   (1)
#if (defined(ARCHALPHA) || defined(ARCHARC) || defined(ARCHAARCH64) || defined(ARCHITANIUM) || defined(ARCHM68K) || defined(ARCHMICROBLAZE) || defined(ARCHMIPS) || defined(ARCHPOWERPC) || defined(ARCHS390) || defined(ARCHSPARC) || defined(ARCHTILE) || defined(ARCHX86_64))
/** POSIX condition attribute datatype */
typedef union pthread_condattr {
	char __size[SIZEOF_PTHREAD_CONDATTR_T];
	int __align;
} pthread_condattr_t;
#elif (defined(ARCHAARCH32) || defined(ARCHPARISC) || defined(ARCHNIOS2) || defined(ARCHSUPERH) || defined(ARCHXTENSA))
/** POSIX condition attribute datatype */
typedef union pthread_condattr {
	char __size[SIZEOF_PTHREAD_CONDATTR_T];
	long __align;
} pthread_condattr_t;
#else
/** POSIX condition attribute datatype */
typedef union pthread_condattr {
	char __size[SIZEOF_PTHREAD_CONDATTR_T];
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
#define rwlockattr_t   pthread_rwlockattr_t
#define thread_key_t   pthread_key_t
#define thr_t   pthread_t
#define thrattr_t   pthread_attr_t
#define once_t   pthread_once_t
typedef struct __ptcb {
	void (*__f)(void*);
	void* __x;
	struct __ptcb* __next;
} ptcb_t;
typedef struct attr_packed pthread {
	struct pthread* self;
	void **dtv, *unused1, *unused2;
	uintptr_t sysinfo, canary, canary2;
	pid_t tid, pid;
	int tsd_used, errno_val;
	volatile int cancel, canceldisable, cancelasync;
	int detached;
	unsigned char* map_base;
	size_t map_size;
	void* stack;
	size_t stack_size;
	void* start_arg;
	void* (*start)(void*);
	void* result;
	struct __ptcb* cancelbuf;
	void** tsd;
	pthread_attr_t attr;
	volatile int dead;
	struct _pthread_robust_list {
		volatile void* volatile head;
		long off;
		volatile void* volatile pending;
	} robust_list;
	int unblock_cancel;
	volatile int timer_id;
	locale_t locale;
	volatile int killlock[2];
	volatile int exitlock[2];
	volatile int startlock[2];
	unsigned long sigmask[NSIG_S3 / SIZEOF_LONG];
	char* dlerror_buf;
	int dlerror_flag;
	void* stdio_locks;
	uintptr_t canary_at_end;
	void** dtv_copy;
} struct_pthread_t;
#define _pthread   pthread
#define __pthread   pthread


// I/O & FILE DATATYPES

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

typedef struct attr_packed wchar_io_data {
	mbstate_t wcio_mbstate_in, wcio_mbstate_out;
	wchar_t wcio_ungetwc_buf[WCIO_UNGETWC_BUFSIZE];
	size_t wcio_ungetwc_inbuf;
	int wcio_mode;
} wchar_io_data_t;

/** File extension */
typedef struct attr_packed __sfileext {
	struct __sbuf _ub;  // ungetc buffer
	struct wchar_io_data _wcio;  // wide char io status
	size_t _fgetstr_len;
	char* _fgetstr_buf;
#   if IS_REENTRANT
	mutex_t _lock;  // Lock for FLOCKFILE/FUNLOCKFILE
	cond_t _lockcond;  // Condition variable for signalling lock releases
	thr_t _lockowner;  // The thread currently holding the lock
	int _lockcount;  // Count of recursive locks
	int _lockinternal;  // Flag of whether the lock is held inside stdio
	int _lockcancelstate;  // Stashed cancellation state on internal lock
#   endif
} __sfileext_t;

#define _EXT(fp)   ((struct __sfileext*)(void*)((fp)->_ub._base))
#define _UB(fp)   _EXT(fp)
#define _FILEEXT_SETUP(f, fext)   do { (f)->_ub._base = (unsigned char*)(fext); (fext)->_fgetstr_len = 0; (fext)->_fgetstr_buf = NULL; } while (0x0)
#define WCIO_GET(fp)   (&(_EXT(fp)->_wcio))
#define _SET_ORIENTATION(fp, mode)   do { struct wchar_io_data* _wcio = WCIO_GET(fp); if (_wcio && _wcio->wcio_mode == 0) { _wcio->wcio_mode = (mode); } } while (0x0)
#define WCIO_FREEUB(fp)   do { _EXT(fp)->_wcio.wcio_ungetwc_inbuf = 0; } while (0x0)
#define WCIO_FREE(fp)   do { _EXT(fp)->_wcio.wcio_mode = 0; WCIO_FREEUB(fp); } while (0x0)

typedef struct attr_packed __sFILEX {
	unsigned char* up;  // Stores _p when _p is doing ungetc data
	mbstate_t mbstate;  // Multibyte conversion state
	pthread_mutex_t fl_mutex;  // Used for MT-safety
	int orientation:2;  // Orientation for fwide()
	int counted:1;  // Stream counted against STREAM_MAX
	int pad1:5;  // Padding
} sFILEX_t;

/** File datatype */
typedef struct attr_packed __sFILE {
	// Position Pointers
	unsigned char* rpos;  // Current read position in buffer
	unsigned char* rend;  // End of read area
	unsigned char* _up;  // Stores value of rpos when ungetc() over-fills the current buffer
	unsigned char* wpos;  // Current write position in buffer
	unsigned char* wbase;  // Start of put() area
	unsigned char* wend;  // End of write area
	unsigned char* shend;  // End of shared area
	off_t shlim;  // Limit of shared area
	off_t shcnt;  // Size of shared area
	// Space left for character-stream functions
	int _r;  // Read space left for getc()
	int _ur;  // Saves _r when _r is counting ungetc data
	int _w;  // Write space left for putc()
	// General File Properties
	unsigned int flags;  // This FILE is free if 0
	unsigned int thread_flags;
	int fd;  // File number (if Unix descriptor), else -1
	int lbfsize;  // 0 or -buf_size (inline putc); used to make inline line-buffered output compact
	int blksize;  // stat.st_blksize (may not equal buffer size)
	fpos_t offset;  // Current lseek offset
	int pipe_pid;  // PID of Pipe
	signed char mode;  // I/O Mode (Text/Binary)
	// Operations
	void* _cookie;  // Cookie passed to IO functions
	int (*close)(void*);
	size_t (*read)(void*, unsigned char*, const size_t);
	ssize_t (*readc)(const int, unsigned char*, const size_t);
	off_t (*seek)(void*, const off_t, const int);
	size_t (*write)(void*, const unsigned char*, const size_t);
	// Buffers
	signed char lbf;  // Line buffer
	struct __sbuf _ub;  // ungetc buffer
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
	const locale_t locale;
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
	vulong_t path;
	unsigned long vers;
	unsigned char type;
} Qid;

/** Possible values for struct Qid.type */
enum QID_TYPE_BITS {
/** Plain file */
	QTFILE = 0,
/** Type bit for not-backed-up file */
	QTTMP = 4,
/** Type bit for authentication file */
	QTAUTH = 8,
/** Type bit for mounted channel */
	QTMOUNT = 0x10,
/** Type bit for exclusive use files */
	QTEXCL = 0x20,
/** Type bit for append only files */
	QTAPPEND = 0x40,
/** Type bit for directories */
	QTDIR = 0x80
};

/** System-modified data & file data */
typedef struct attr_packed Dir {
	unsigned short type;  // Server type
	unsigned int dev;  // Server subtype
	Qid qid;  // Unique id from server
	unsigned long mode;  // Permissions
	unsigned long atime;  // Last read time
	unsigned long mtime;  // Last write time
	vlong_t length;  // File length
	char* name;  // Last element of path
	char* uid;  // Owner name
	char* gid;  // Group name
	char* muid;  // Last modifier name
} Dir;
// Dir.mode Bits
/** Mode bit for execute permission */
#define DMEXEC   1
/** Mode bit for write permission */
#define DMWRITE   2
/** Mode bit for read permission */
#define DMREAD   4
/** Mode bit for non-backed-up files */
#define DMTMP   0x4000000
/** Mode bit for authentication file */
#define DMAUTH   0x8000000
/** Mode bit for append only files */
#define DMAPPEND   0x40000000
/** Mode bit for directories */
#define DMDIR   0x80000000
/** Mode bit for mounted channel */
#define DMMOUNT   0x10000000
/** Mode bit for exclusive use files */
#define DMEXCL   0x20000000

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


// IMPORTANT FUNCTION DECLARATIONS

#ifndef DISABLE_FUNC_DECL
DECL_FUNC void* alloca(const size_t size);
DECL_FUNC ATTR_PRINTF(2, 3) int asprintf(char** s, const char* fmt, ...);
DECL_FUNC MATH_FUNC double atan(const double num);
DECL_FUNC MATH_FUNC float atanf(const float num);
DECL_FUNC NONNULL int atoi(const char* restrict s);
DECL_FUNC NONNULL long atol(const char* restrict s);
DECL_FUNC NONNULL long long atoll(const char* restrict s);
DECL_FUNC NONNULL short atos(const char* restrict s);
DECL_FUNC NONNULL void bit8tostr(const uint8_t bits, char* restrict outstr);
DECL_FUNC NONNULL void bit16tostr(const uint16_t bits, char* restrict outstr);
DECL_FUNC NONNULL void bit32tostr(const uint32_t bits, char* restrict outstr);
DECL_FUNC NONNULL void bit64tostr(const uint64_t bits, char* restrict outstr);
DECL_FUNC NONNULL void bitlongtostr(const unsigned long bits, char* restrict outstr);
DECL_FUNC void* calloc(const size_t num_members, const size_t elem_size);
DECL_FUNC clock_t clock(void);
DECL_FUNC int clock_gettime(const clockid_t clk, struct timespec* ts);
DECL_FUNC NONNULL int cmpxchg(volatile int* restrict ptr, const int oldval, const int newval);
DECL_FUNC NOLIBCALL NONNULL int copystring(char* restrict buf, const unsigned int maxlen, const char* restrict s);
DECL_FUNC MATH_FUNC double cos(const double x);
DECL_FUNC MATH_FUNC float cosf(const float x);
DECL_FUNC int count_leading_zeros(const unsigned long x);
DECL_FUNC NONNULL void doublebittostr(const double dbits, char* restrict outstr);
DECL_FUNC NOLIBCALL int dtostr(const double num, char* restrict buf, const size_t width, const size_t prec, const char format);
DECL_FUNC void do_tzset(void);
DECL_FUNC noreturn COLD void _Exit(const int code);
DECL_FUNC MATH_FUNC double exp(const double num);
DECL_FUNC MATH_FUNC float expf(const float num);
DECL_FUNC MATH_FUNC double fabs(const double x);
DECL_FUNC MATH_FUNC float fabsf(const float x);
DECL_FUNC int fclose(FILE* f);
DECL_FUNC int fcntl(const int fd, const int cmd, ...);
DECL_FUNC long __fdelt_chk(const long d);
DECL_FUNC int ferror(FILE* fp);
DECL_FUNC int fflush(FILE* f);
DECL_FUNC char* fgets(char* as, int n, FILE* f);
DECL_FUNC ATTR_NONNULL(1) ATTR_PRINTF(2, 3) int fprintf(FILE* restrict f, const char* restrict fmt, ...);
DECL_FUNC NONNULL void floatbittostr(const float fbits, char* restrict outstr);
DECL_FUNC NOLIBCALL ATTR_PF int fmodeflags(const char* restrict mode);
DECL_FUNC FILE* fopen(const char* restrict filename, const char* restrict mode);
DECL_FUNC wint_t fputwc(const wchar_t wc, FILE* stream);
DECL_FUNC int fputws(const wchar_t* str, FILE* stream);
DECL_FUNC void free(void* ptr);
DECL_FUNC MATH_FUNC double frexp(const double num, int* e);
DECL_FUNC MATH_FUNC float frexpf(const float num, int* e);
DECL_FUNC int fseeko_unlocked(FILE* f, off_t off, const int whence);
DECL_FUNC off_t ftello(FILE* f);
DECL_FUNC int _fwalk(int (*function)(FILE*));
DECL_FUNC MATH_FUNC int64_t get_dbl_expo(const double x);
DECL_FUNC const char* getenv(const char* restrict name);
DECL_FUNC MATH_FUNC int64_t get_flt_expo(const float x);
DECL_FUNC pid_t getpid(void);
DECL_FUNC ATTR_NONNULL(1) int gettimeofday(struct timeval* restrict tv, const UNUSED void* restrict tz);
DECL_FUNC uid_t getuid(void);
DECL_FUNC struct tm* gmtime_r(const time_t* restrict t, struct tm* restrict _tm);
DECL_FUNC hp_timing_t HP_TIMING(void);
DECL_FUNC MATH_FUNC double __ieee754_sqrt(const double x);
DECL_FUNC MATH_FUNC float __ieee754_sqrtf(const float x);
DECL_FUNC MATH_FUNC double iexp(const int expo);
DECL_FUNC MATH_FUNC float iexpf(const int expo);
DECL_FUNC unsigned long long intscan(FILE* f, unsigned base, const int pok, const unsigned long long lim);
DECL_FUNC MATH_FUNC int isfinite(const double x);
DECL_FUNC MATH_FUNC int isfinitef(const float x);
DECL_FUNC MATH_FUNC int __isinf(const double x);
DECL_FUNC MATH_FUNC int __isinff(const float x);
DECL_FUNC MATH_FUNC int __isnan(const double x);
DECL_FUNC MATH_FUNC int __isnanf(const float x);
DECL_FUNC char* itoa2(int i, char b[]);
DECL_FUNC int lflush(FILE* _fp);
DECL_FUNC int __lltostr(char* s, int size, unsigned long long i, const int base, const char UpCase);
DECL_FUNC int __ltostr(char* s, unsigned int size, unsigned long i, const unsigned int base, const int UpCase);
DECL_FUNC void LOCK(volatile int* restrict l);
DECL_FUNC int LOCKFILE(FILE* restrict f);
DECL_FUNC MATH_FUNC long lrintf(const float x);
DECL_FUNC int mbtowc(wchar_t* restrict pwc, const char* s, const size_t n);
DECL_FUNC NOLIBCALL void* malloc(const size_t len);
DECL_FUNC size_t mbrtowc(wchar_t* restrict pwc, const char* s, const size_t len, const UNUSED mbstate_t* ps);
DECL_FUNC int mbsinit(const mbstate_t* restrict st);
DECL_FUNC NOLIBCALL const void* memchr(const void* src, const int x, const size_t len);
DECL_FUNC NOLIBCALL void* memchr_nonconst(void* src, const int x, const size_t len);
DECL_FUNC int memcmp(const void* restrict ptr1, const void* restrict ptr2, const size_t _num);
DECL_FUNC NOLIBCALL NONNULL void* memcpy(void* restrict dest, const void* restrict src, const size_t len);
DECL_FUNC NOLIBCALL NONNULL void memcpy_no_output(void* restrict dest, const void* restrict src, const size_t len);
DECL_FUNC NOLIBCALL NONNULL void* memmove(void* dst, const void* src, const size_t len);
DECL_FUNC NOLIBCALL NONNULL void memmove_no_output(void* dst, const void* src, const size_t len);
DECL_FUNC NOLIBCALL NONNULL void* mempcpy(void* restrict dest, const void* restrict src, const size_t len);
DECL_FUNC NOLIBCALL NONNULL void* memset(void* restrict dst, const int c, const size_t len);
DECL_FUNC NOLIBCALL NONNULL void memset_no_output(void* restrict dst, const int c, const size_t len);
DECL_FUNC NOLIBCALL void* mmap(void* restrict start, const size_t len, const int prot, const int flags, const int fd, const off_t off);
DECL_FUNC int munmap(void* start, const size_t len);
DECL_FUNC int munmap_const(const void* start, const size_t len);
DECL_FUNC int nanosleep(const struct timespec* req, struct timespec* rem);
DECL_FUNC int open(const char* filename, const int flags, ...);
DECL_FUNC ATTR_CF uint32_t popcount32(const uint32_t x);
DECL_FUNC void procfdname(char* buf, unsigned int fd);
DECL_FUNC struct pthread* __pthread_self(void);
DECL_FUNC int putb(const int8_t b, FILE* fp);
DECL_FUNC void putb_no_output(const int8_t b, FILE* fp);
DECL_FUNC int putc(int c, FILE* fp);
DECL_FUNC void putc_no_output(const int c, FILE* fp);
DECL_FUNC void puti(const int num);
DECL_FUNC int puts(const char* src);
DECL_FUNC int puts_err(const char* src);
DECL_FUNC void puts_err_no_output(const char* src);
DECL_FUNC void puts_no_output(const char* restrict src);
DECL_FUNC int pipe2(int fd[2], const int flag);
DECL_FUNC int pthread_setcancelstate(const int new, int* old);
DECL_FUNC int pthread_sigmask(const int how, const sigset_t* restrict set, sigset_t* restrict old);
DECL_FUNC char* randname(char* template);
DECL_FUNC void* realloc(void* ptr, const size_t len);
DECL_FUNC void* reallocarray(void* optr, const size_t nmemb, const size_t size);
DECL_FUNC size_t scan_trans(long long t, int local, size_t* alt);
DECL_FUNC int select(const int n, fd_set* restrict rfds, fd_set* restrict wfds, fd_set* restrict efds, struct timeval* restrict tv);
DECL_FUNC void setlinebuf(FILE* f);
DECL_FUNC int sflush(FILE* fp);
DECL_FUNC int __sfvwrite(FILE* fp, struct __suio* uio);
DECL_FUNC int __sigaction(int sig, const struct sigaction* act, struct sigaction* oact);
DECL_FUNC MATH_FUNC int signbit(const double x);
DECL_FUNC MATH_FUNC int signbitf(const float x);
DECL_FUNC MATH_FUNC double sin(const double x);
DECL_FUNC MATH_FUNC float sinf(const float x);
DECL_FUNC ATTR_PRINTF(3, 4) int snprintf(char* s, const size_t maxlen, const char* format, ...);
DECL_FUNC fpos_t __sseek(void* _cookie, const fpos_t offset, const int whence);
DECL_FUNC int __stdio_close(FILE* f);
DECL_FUNC int __stdio_close_helper(void* f);
DECL_FUNC off_t __stdio_seek(FILE* f, const off_t off, const int whence);
DECL_FUNC off_t __stdio_seek_helper(void* f, const off_t off, const int whence);
DECL_FUNC ATTR_NONNULL(2) size_t __stdio_read(FILE* f, unsigned char* buf, const size_t len);
DECL_FUNC ATTR_NONNULL(2) size_t __stdio_read_helper(void* f, unsigned char* buf, const size_t len);
DECL_FUNC ATTR_NONNULL(2) ssize_t __stdio_readc_helper(const int fd, unsigned char* buf, const size_t len);
DECL_FUNC ATTR_NONNULL(1) size_t __stdio_write(FILE* f, const unsigned char* buf, const size_t len);
DECL_FUNC ATTR_NONNULL(1) size_t __stdio_write_helper(void* f, const unsigned char* buf, const size_t len);
DECL_FUNC NONNULL size_t __stdout_write(UNUSED FILE* f, const unsigned char* restrict buf, const size_t len);
DECL_FUNC NONNULL size_t __stdout_write_helper(UNUSED void* f, const unsigned char* restrict buf, const size_t len);
DECL_FUNC int strcasecmp(const char* s1, const char* s2);
DECL_FUNC NOLIBCALL ATTR_PF const char* strchr(const char* restrict str, const int chr);
DECL_FUNC char* strchr2(const char* restrict str, const int chr);
DECL_FUNC NOLIBCALL ATTR_PF char* strchr_nc(char* restrict str, const int chr);
DECL_FUNC wchar_t* strchrW(const wchar_t* restrict str, const wchar_t ch);
DECL_FUNC NOLIBCALL NONNULL ATTR_PF int strcmp(const char* restrict s1, const char* restrict s2);
DECL_FUNC char* strcpy(char* restrict dest, const char* restrict src);
DECL_FUNC void strcpy_no_output(char* restrict dest, const char* restrict src);
DECL_FUNC NOLIBCALL ATTR_PF size_t strcspn(const char* restrict str, const char* restrict reject);
DECL_FUNC char* strdup(const char* s);
DECL_FUNC size_t strftime(char* restrict s, size_t n, const char* restrict f, const struct tm* restrict _tm);
DECL_FUNC const char* strftime_fmt_1(char (*s)[100], size_t* l, int f, const struct tm* _tm, locale_t loc);
DECL_FUNC NOLIBCALL NONNULL ATTR_PURE size_t strlen(const char* restrict str);
DECL_FUNC NONNULL ATTR_PF int strncmp(const char* s1, const char* s2, const size_t len);
DECL_FUNC void strncpy_no_output(char* restrict dest, const char* restrict src, const size_t len);
DECL_FUNC NOLIBCALL NONNULL ATTR_PURE size_t strnlen(const char* restrict s, const size_t maxlen);
DECL_FUNC ATTR_PURE double strtod(const char* restrict ptr, const char** endptr);
DECL_FUNC float strtof(const char* restrict ptr, const char** endptr);
DECL_FUNC const char* strrchr(const char* restrict str, const int chr);
DECL_FUNC NOLIBCALL ATTR_PF size_t strspn(const char* restrict s1, const char* restrict s2);
DECL_FUNC const char* strstr(const char* restrict s1, const char* restrict s2);
DECL_FUNC long strtol(const char* restrict nptr, const char** restrict endptr, const int _base);
DECL_FUNC unsigned long strtoul(const char* restrict nptr, const char** restrict endptr, const int _base);
DECL_FUNC MATH_FUNC float atan2f(const float y, const float x);
DECL_FUNC MATH_FUNC double atan2(const double y, const double x);
DECL_FUNC time_t time(time_t* t);
DECL_FUNC int __toread(FILE* f);
DECL_FUNC void tzset(void);
DECL_FUNC NONNULL void u8todec(const uint8_t num, char* restrict result);
DECL_FUNC NONNULL void u8tohex(const uint8_t num, const int use_upper, char* restrict result);
DECL_FUNC NONNULL void u8tooct(const uint8_t num, char* restrict result);
DECL_FUNC int __uflow(FILE* f);
DECL_FUNC NONNULL void uhtodec(const unsigned short num, char* restrict result);
DECL_FUNC NONNULL void uhtohex(const unsigned short num, const int use_upper, char* restrict result);
DECL_FUNC NONNULL void uhtooct(const unsigned short num, char* restrict result);
DECL_FUNC char* uintmaxtostr(const signed long _num, char b[]);
DECL_FUNC NONNULL void ulltodec(const unsigned long long num, char* restrict result);
DECL_FUNC NONNULL void ulltohex(const unsigned long long num, const int use_upper, char* restrict result);
DECL_FUNC NONNULL void ulltooct(const unsigned long long num, char* restrict result);
DECL_FUNC NONNULL void ultodec(const unsigned long num, char* restrict result);
DECL_FUNC NONNULL void ultohex(const unsigned long num, const int use_upper, char* restrict result);
DECL_FUNC NONNULL void ultooct(const unsigned long num, char* restrict result);
DECL_FUNC int uname(struct utsname* uts);
DECL_FUNC NONNULL size_t utf32toutf8(const ucs4_t* restrict codepoints, unsigned char* restrict utf8str);
DECL_FUNC void unlist_locked_file(FILE* f);
DECL_FUNC void UNLOCK(volatile int* restrict l);
DECL_FUNC void UNLOCKFILE(FILE* restrict f);
DECL_FUNC NONNULL ATTR_PURE size_t utf8len(const char* restrict str);
DECL_FUNC NONNULL ATTR_PURE size_t utf32len(const ucs4_t* restrict str);
DECL_FUNC ATTR_CF uint32_t utf32c2utf8c(const ucs4_t codepoint);
DECL_FUNC NONNULL void utodec(const unsigned int num, char* restrict result);
DECL_FUNC NONNULL void utohex(const unsigned int num, const int use_upper, char* restrict result);
DECL_FUNC NONNULL void utooct(const unsigned int num, char* restrict result);
DECL_FUNC ATTR_PRINTF(2, 0) int vfprintf(FILE* stream, const char* format, va_list arg_ptr);
DECL_FUNC int vsnprintf(char* restrict str, const size_t size, const char* restrict format, va_list args);
DECL_FUNC pid_t waitpid(const pid_t pid, const int* restrict status, const int options);
DECL_FUNC size_t wcrtomb(char* restrict s, wchar_t wc, const UNUSED mbstate_t* restrict st);
DECL_FUNC long long wcstoll(wchar_t* restrict s, const wchar_t** restrict p, const int base);
DECL_FUNC unsigned long long wcstoull(wchar_t* restrict s, const wchar_t** restrict p, const int base);
DECL_FUNC unsigned long long wcstox(wchar_t* s, const wchar_t** p, const int base, const unsigned long long lim);
DECL_FUNC int wctomb(char* s, wchar_t wchar);
DECL_FUNC NONNULL ATTR_PF long xatol(const char* restrict s);
DECL_FUNC NONNULL ATTR_PF unsigned long xatoul(const char* restrict s);
DECL_FUNC uint32_t zi_read32(const unsigned char* z);
#   if SUPPORTS_LONG_DOUBLE
DECL_FUNC long double __floatscan(FILE* f, const int prec, const int pok);
DECL_FUNC long double frexpl(const long double x, int* e);
DECL_FUNC MATH_FUNC int isfinitel(const long double x);
DECL_FUNC MATH_FUNC int signbitl(const long double x);
DECL_FUNC long double strtox(const char*  restrict ptr, const char** endptr, const int prec);
#   endif
#endif  // DISABLE_FUNC_DECL


// STDIN, STDOUT, & STDERR

static UNUSED unsigned char align64 stdbuf[UNGET + BUFSIZ] = { 0 };
static FILE align64 __stdin = {
	.flags = (unsigned int)(__SLBF | __SRD),
	.fd = STDIN_FILENO,
	.close = &__stdio_close_helper,
	.read = &__stdio_read_helper,
	.readc = &__stdio_readc_helper,
	.seek = &__stdio_seek_helper,
	.buf = stdbuf + UNGET,
	.buf_size = (sizeof(stdbuf) - UNGET),
	._ubuf = { 0 },
	._nbuf = { 0 },
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
static FILE align64 __stdout = {
	.flags = (unsigned int)(__SLBF | __SWR),
	.fd = STDOUT_FILENO,
	.close = &__stdio_close_helper,
	.seek = &__stdio_seek_helper,
	.write = &__stdio_write_helper,
	.buf = stdbuf + UNGET,
	.buf_size = (sizeof(stdbuf) - UNGET),
	._ubuf = { 0 },
	._nbuf = { 0 },
	.lock = -1,
	.waiters = -1,
	.lockcount = -1,
	.lbf = '\n'
};
/** Standard output pointer */
UNUSED FILE* __stdoutp = &__stdout;
#define stdoutp   __stdoutp
#define STDOUT   __stdoutp
#define stdout   __stdoutp
#define __stdout_used   __stdoutp
static FILE align64 __stderr = {
	.flags = (unsigned int)(__SLBF | __SWR),
	.fd = STDOUT_FILENO,
	.close = &__stdio_close_helper,
	.seek = &__stdio_seek_helper,
	.write = &__stdio_write_helper,
	.buf = stdbuf + UNGET,
	.buf_size = 0,
	.lock = -1,
	.waiters = -1,
	.lockcount = -1,
	.lbf = '\n'
};
/** Standard error pointer */
UNUSED FILE* __stderrp = &__stderr;
#define stderrp   __stderrp
#define STDERR   __stderrp
#define stderr   __stderrp
#define __stderr_used   __stderrp


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
/** Pair of signed long integers */
typedef struct slintpair { slint x, y; }   slintpair_t;
/** Pair of unsigned long integers */
typedef struct ulintpair { ulint x, y; }   ulintpair_t;
/** Pair of unsigned long long integers */
typedef struct ullintpair { ullint x, y; }   ullintpair_t;
/** Pair of signed long long integers */
typedef struct sllintpair { sllint x, y; }   sllintpair_t;
/** Group of three doubles */
typedef struct doubletriplet { double x, y, z; }   doubletriplet_t;
/** Group of three floats */
typedef struct floattriplet { float x, y, z; }   floattriplet_t;
#if SUPPORTS_INT128
/** Pair of int128_t integers */
typedef struct int128pair { int128_t x, y; }   int128pair_t;
/** Group of three int128_t integers */
typedef struct int128triplet { int128_t x, y, z; }   int128triplet_t;
#endif
#if SUPPORTS_UINT128
/** Pair of uint128_t integers */
typedef struct uint128pair { uint128_t x, y; }   uint128pair_t;
/** Group of three uint128_t integers */
typedef struct uint128triplet { uint128_t x, y, z; }   uint128triplet_t;
#endif
#if SUPPORTS_FLOAT128
/** Pair of 128-bit floats */
typedef struct float128pair { float128 x, y; }   float128pair_t;
/** Group of three 128-bit floats */
typedef struct float128triplet { float128 x, y, z; }   float128triplet_t;
#endif


// GEOMETRY DATATYPES

/** Coordinates of a point (float) */
typedef struct __pointf { float x, y; }   pointf_t;
/** Coordinates of a point (double) */
typedef struct __point { double x, y; }   point_t;
#if SUPPORTS_FLOAT128
/** Coordinates of a point (float128) */
typedef struct __point_float128 { float128 x, y; }   point_float128_t;
#endif
/** Coordinates of a point (long double) */
typedef struct __pointl { long double x, y; }   pointl_t;
/** Coordinates of a point (signed long) */
typedef struct __point_int { signed long x, y; }   point_int_t;
/** Two points of a line (float) */
typedef struct __linef { pointf_t x, y; }   linef_t;
/** Two points of a line (double) */
typedef struct __line { point_t x, y; }   line_t;
/** Two points of a line (long double) */
typedef struct __linel { pointl_t x, y; }   linel_t;
/** Two points of a line (signed long) */
typedef struct __line_int { point_int_t x, y; }   line_int_t;
// 2D SHAPES
/** Semicircle, given the radius (float) */
typedef struct __semicirclef { float radius; }   semicirclef_t;
/** Semicircle, given the radius (double) */
typedef struct __semicircle { double radius; }   semicircle_t;
/** Semicircle, given the radius (long double) */
typedef struct __semicirclel { long double radius; }   semicirclel_t;
/** Circle, given the radius (float) */
typedef struct __circlef { float radius; }   circlef_t;
/** Circle, given the radius (double) */
typedef struct __circle { double radius; }   circle_t;
/** Circle, given the radius (long double) */
typedef struct __circlel { long double radius; }   circlel_t;
/** Ellipse, given the major-radius and minor-radius (float) */
typedef struct __ellipsef { float majorradius, minorradius; }   ellipsef_t;
/** Ellipse, given the major-radius and minor-radius (double) */
typedef struct __ellipse { double majorradius, minorradius; }   ellipse_t;
/** Ellipse, given the major-radius and minor-radius (long double) */
typedef struct __ellipsel { long double majorradius, minorradius; }   ellipsel_t;
/** Hexagon, given the width and a side-length (float) */
typedef struct __hexagonf { float width, sidelength; }   hexagonf_t;
/** Hexagon, given the width and a side-length (double) */
typedef struct __hexagon { double width, sidelength; }   hexagon_t;
/** Hexagon, given the width and a side-length (long double) */
typedef struct __hexagonl { long double width, sidelength; }   hexagonl_t;
/** Rectangle, given the height and width (float) */
typedef struct __rectanglef { float height, width; }   rectanglef_t;
/** Rectangle, given the height and width (double) */
typedef struct __rectangle { double height, width; }   rectangle_t;
/** Rectangle, given the height and width (long double) */
typedef struct __rectanglel { long double height, width; }   rectanglel_t;
/** Square, given the length (float) */
typedef struct __squaref { float length; }   squaref_t;
/** Square, given the length (double) */
typedef struct __square { double length; }   square_t;
/** Square, given the length (long double) */
typedef struct __squarel { long double length; }   squarel_t;
/** Triangle, given the base and height (float) */
typedef struct __trianglef { float base, height; }   trianglef_t;
/** Triangle, given the base and height (double) */
typedef struct __triangle { double base, height; }   triangle_t;
/** Triangle, given the base and height (long double) */
typedef struct __trianglel { long double base, height; }   trianglel_t;
// 3D SHAPES
/** Sphere, given the radius (float) */
typedef struct __spheref { float radius; }   spheref_t;
/** Sphere, given the radius (double) */
typedef struct __sphere { double radius; }   sphere_t;
/** Sphere, given the radius (long double) */
typedef struct __spherel { long double radius; }   spherel_t;
#if SUPPORTS_FLOAT128
/** Sphere, given the radius (float128) */
typedef struct __sphere_float128 { float128 radius; }   sphere_float128_t;
#endif
/** Cube, given the length (float) */
typedef struct __cubef { float length; }   cubef_t;
/** Cube, given the length (double) */
typedef struct __cube { double length; }   cube_t;
/** Cube, given the length (long double) */
typedef struct __cubel { long double length; }   cubel_t;
#if SUPPORTS_FLOAT128
/** Cube, given the length (float128) */
typedef struct __cube_float128 { float128 length; }   cube_float128_t;
#endif
/** Ellipsoid, given radius1, radius2, and radius3 (float) */
typedef struct __ellipsoidf { float radius1, radius2, radius3; }   ellipsoidf_t;
/** Ellipsoid, given radius1, radius2, and radius3 (double) */
typedef struct __ellipsoid { double radius1, radius2, radius3; }   ellipsoid_t;
/** Ellipsoid, given radius1, radius2, and radius3 (long double) */
typedef struct __ellipsoidl { long double radius1, radius2, radius3; }   ellipsoidl_t;
#if SUPPORTS_FLOAT128
/** Ellipsoid, given radius1, radius2, and radius3 (float128) */
typedef struct __ellipsoid_float128 { float128 radius1, radius2, radius3; }   ellipsoid_float128_t;
#endif
/** Prism, given the depth, height, and width (float) */
typedef struct __prismf { float depth, height, width; }   prismf_t;
/** Prism, given the depth, height, and width (double) */
typedef struct __prism { double depth, height, width; }   prism_t;
/** Prism, given the depth, height, and width (long double) */
typedef struct __prisml { long double depth, height, width; }   prisml_t;
#if SUPPORTS_FLOAT128
/** Prism, given the depth, height, and width (float128) */
typedef struct __prism_float128 { float128 depth, height, width; }   prism_float128_t;
#endif


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


/* LIBRARY SETTINGS */


#if (!(defined(LIBC_H) || defined(_LIBC_H) || defined(_LIBC_H_)))
#define LIBC_H   1
#define _LIBC_H   1
#define _LIBC_H_   1


/** Locale object for global C locale */
static UNUSED locale_t __global_locale = NULL;
/** Locale object for global C locale */
#define _NL_CURRENT_LOCALE   __global_locale
#define CURRENT_LOCALE   __global_locale
UNUSED _RuneLocale _DefaultRuneLocale;
UNUSED _RuneLocale* _CurrentRuneLocale;
/** Return a pointer to the global locale */
#define __current_locale()   (locale_t)(&__global_locale)
/** Return a pointer to the global locale */
#define current_locale()   (locale_t)(&__global_locale)
#define current_locale_ptr   ((locale_t*)(&__global_locale))
#define DEFAULT_CURRENT_LOCALE(x)   if ((x) == NULL) { (x) = current_locale(); } else if ((x) == LC_GLOBAL_LOCALE) { (x) = &__global_locale; }
#define NORMALIZE_LOCALE(x)   if ((x) == NULL) { (x) = __global_locale; } else if ((x) == LC_GLOBAL_LOCALE) { (x) = __global_locale; }
#if SINGLE_THREAD_P
/** We need to have the error status variable of the resolver accessible in the libc */
volatile UNUSED locale_t locale_tls;
volatile UNUSED tss_t locale_tss;
#else
/** We need to have the error status variable of the resolver accessible in the libc */
thread_local volatile UNUSED locale_t locale_tls;
thread_local volatile UNUSED tss_t locale_tss;
#endif
#define _locale_tls   locale_tls
#define _locale_tss   locale_tss


static UNUSED struct lconv C_LOCALE_INITIALIZER = {
	".", "", "", "", "", "",  // Decimal_point - mon_decimal_point
	"", "", "", "", 127, 127,  // mon_thousands_sep - frac_digits
	127, 127, 127, 127, 127, 127,  // p_cs_precedes - n_sign_posn
	127, 127, 127, 127, 127, 127  // int_p_cs_precedes - int_n_sign_posn
};
#define locale_table   C_LOCALE_INITIALIZER


typedef struct libc {
	int can_do_threads, threaded, secure;
	volatile int threads_minus_1;
	size_t* auxv;
	struct tls_module* tls_head;
	size_t tls_size, tls_align, tls_cnt, page_size;
	locale_t global_locale;
} libc_t;
#if SINGLE_THREAD_P
static UNUSED struct libc libc = { 0, 0, 1, 0, NULL, NULL, 0, 0, 0, (size_t)PAGE_SIZE, (locale_t)(&__global_locale) };
#   else
static UNUSED struct libc libc = { 1, 1, 1, 0, NULL, NULL, 0, 0, 0, (size_t)PAGE_SIZE, (locale_t)(&__global_locale) };
#endif
#define _libc   libc
#define __libc   libc
#define _libc_global_locale   libc.global_locale
/** Set libc.global_locale to __global_locale */
#define sync_libc_locale()   do { _libc_global_locale = (locale_t)(&__global_locale); } while (0x0)


#endif  // LIBC_H


/* FIXED-POINT DATATYPES, MACROS, & FUNCTIONS; ISO/IEC TR18037 (<stdfix.h> & <fixed.h>) */


#if (IS_GNUC && SUPPORTS_STDFIX && (!(defined(STDFIX_H) || defined(_STDFIX_H) || defined(_STDFIX_H_) || defined(_FIXED_BIT_H))))  // http://www.qnx.com/developers/docs/660/topic/com.qnx.doc.dinkum/topic/cpp11/stdfix.html & http://www.qnx.com/developers/docs/660/topic/com.qnx.doc.dinkum/topic/cpp11/fixed.html
#define STDFIX_H   (1)
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
#define FIXED_WIDTH2   (FIXED_WIDTH + FIXED_WIDTH)
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


#if (IS_GNUC && defined(ARCHAVR) && (!(defined(_AVRGCC_STDFIX_H) || defined(_AVRGCC_STDFIX_H_))))  // AVR-specific code
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


LIB_FUNC MATH_FUNC int sat_add(const int a, const int b) {
	register const int c = a + b;
	if ((((a ^ b) & MIN_32) == 0) && ((c ^ a) & MIN_32)) {
		return ((a < 0) ? MIN_32 : MAX_32);
	}
	return c;
}


LIB_FUNC ATTR_PF _Accum mul_sum(_Sat _Fract* a, _Sat _Fract* b, const int length) {
	register int i = length + 1;
	_Accum accumulator = 0;
	for (; i != 0; --i) { accumulator += (_Accum)(a[i] * b[i]); }
	return accumulator;
}


#if (defined(FIXED_ADD) && defined(L_add))
LIB_FUNC MATH_FUNC FIXED_C_TYPE FIXED_ADD(FIXED_C_TYPE a, FIXED_C_TYPE b) {
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
LIB_FUNC MATH_FUNC FIXED_C_TYPE FIXED_SSADD(FIXED_C_TYPE a, FIXED_C_TYPE b) {
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
LIB_FUNC MATH_FUNC FIXED_C_TYPE FIXED_USADD(FIXED_C_TYPE a, FIXED_C_TYPE b) {
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
LIB_FUNC MATH_FUNC FIXED_C_TYPE FIXED_SUB(FIXED_C_TYPE a, FIXED_C_TYPE b) {
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
LIB_FUNC MATH_FUNC FIXED_C_TYPE FIXED_SSSUB(FIXED_C_TYPE a, FIXED_C_TYPE b) {
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
LIB_FUNC MATH_FUNC FIXED_C_TYPE FIXED_USSUB(FIXED_C_TYPE a, FIXED_C_TYPE b) {
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
	min = (DINT_C_TYPE)1 << (FIXED_WIDTH2 - 1);
	min >>= (FIXED_WIDTH2 - 1 - I_F_BITS);
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
LIB_FUNC MATH_FUNC FIXED_C_TYPE FIXED_MULHELPER(FIXED_C_TYPE a, FIXED_C_TYPE b, word_type satp) {
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
	dz >>= FBITS;
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
LIB_FUNC MATH_FUNC FIXED_C_TYPE FIXED_DIVHELPER(FIXED_C_TYPE a, FIXED_C_TYPE b, word_type satp) {
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
	for (i = FIXED_WIDTH + 1; i != 0; --i) {
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


/* GNU/HURD DATATYPES (<hurd_types.h>) */


#if ((!(defined(HURD_TYPES_H) || defined(HURD_TYPES_H_) || defined(_HURD_TYPES_H) || defined(_HURD_TYPES_H_))) && defined(OSHURD))
#define HURD_TYPES_H   (1)
#define HURD_TYPES_H_   (1)
#define _HURD_TYPES_H   (1)
#define _HURD_TYPES_H_   (1)


#ifdef USE_FILE_OFFSET64
typedef struct stat   io_statbuf_t;
typedef struct statfs   fsys_statfsbuf_t;
#else
typedef struct stat64   io_statbuf_t;
typedef struct statfs64   fsys_statfsbuf_t;
#endif
/** Values for retry field in fs.defs:dir_lookup call: */
typedef enum retry_type {
	FS_RETRY_NORMAL = 1,  // Retry normally if retry_name is not null
	FS_RETRY_REAUTH = 2,  // Retry after reauthenticating retry port
	FS_RETRY_MAGICAL = 3  // Retry string is magical
} retry_type;
#define retry_t   retry_type
/** Types for fs_notify.defs:dir_changed call: */
typedef enum dir_changed_type {
	DIR_CHANGED_NULL,  // Always sent first for sync
	DIR_CHANGED_NEW,  // Specified name has been added
	DIR_CHANGED_UNLINK,  // Specified name has been removed
	DIR_CHANGED_RENUMBER  // Name has been the target of rename
} dir_changed_type;
#define dir_changed_type_t   dir_changed_type
/** Types for fs_notify.defs:file_changed call: */
typedef enum file_changed_type {
	FILE_CHANGED_NULL,  // Always sent first for sync
	FILE_CHANGED_WRITE,  // File data has been written
	FILE_CHANGED_EXTEND,  // File has grown
	FILE_CHANGED_TRUNCATE,  // File has been truncated
	FILE_CHANGED_META  // Stat information has changed, and none of the previous three apply; Not sent for changes in node times
} file_changed_type;
#define file_changed_type_t   file_changed_type
/** Types of ports the terminal driver can run on top of; Used in term.defs:term_get_bottom_type */
typedef enum term_bottom_type {
	TERM_ON_MACHDEV, TERM_ON_HURDIO, TERM_ON_MASTERPTY
} term_bottom_t;
/** Standard port assignments for file_exec and exec_* */
enum INIT_PORT_EXEC {
	INIT_PORT_CWDIR,
	INIT_PORT_CRDIR,
	INIT_PORT_AUTH,
	INIT_PORT_PROC,
	INIT_PORT_CTTYID,
	INIT_PORT_BOOTSTRAP,
	INIT_PORT_MAX
};
/** Standard ints for file_exec and exec_* */
enum INIT_EXEC {
	INIT_UMASK,
	INIT_SIGMASK,
	INIT_SIGIGN,
	INIT_SIGPENDING,
	INIT_TRACEMASK,
	INIT_INT_MAX
};
/** Types of storage, as returned by file_get_storage_info
	- STORAGE_DEVICE is a mach device_t (for random access devices)
	- STORAGE_HURD_FILE is a hurd file_t (as if a file were mapped)
	- STORAGE_TASK is a task_t (the storage is in the vm of the task)
	- STORAGE_MEMORY is a memory object port
	- STORAGE_ZERO is a fixed-size constant source of zeros
	- STORAGE_INTERLEAVE is a set of other storage types interleaved at a fixed interval
	- STORAGE_CONCAT is a set of other storage types concatenated end-to-end
	- STORAGE_LAYER is a set of storage types, representing the same address range; all will be written too, and will be read in turn until one succeeds
	- STORAGE_REMAP is a layer on top of another store that remaps its blocks
	- STORAGE_COPY is a memory snapshot of another store
	- STORAGE_NETWORK means that the file is stored elsewhere on the network; all the remaining fields contan type-specific information.
	- STORAGE_OTHER means none of these apply; and should be used when no meaningful answer can be given
*/
typedef enum file_storage_class {
	STORAGE_OTHER,
	STORAGE_DEVICE,
	STORAGE_HURD_FILE,
	STORAGE_NETWORK,
	STORAGE_MEMORY,
	STORAGE_TASK,
	STORAGE_ZERO,
	STORAGE_CONCAT,
	STORAGE_INTERLEAVE,
	STORAGE_LAYER,
	STORAGE_REMAP,
	STORAGE_COPY
} file_storage_class_t;


#endif  // HURD_TYPES_H


/* INDUSTRIAL I/O DATATYPES (LINUX KERNEL) */


#if ((!(defined(IIO_TYPES_H) || defined(IIO_TYPES_H_) || defined(_IIO_TYPES_H) || defined(_IIO_TYPES_H_))) && defined(ALLOW_HEADER_IIO_TYPES_H))
#define IIO_TYPES_H   (1)
#define IIO_TYPES_H_   (1)
#define _IIO_TYPES_H   (1)
#define _IIO_TYPES_H_   (1)


typedef enum iio_chan_type {
	IIO_VOLTAGE,
	IIO_CURRENT,
	IIO_POWER,
	IIO_ACCEL,
	IIO_ANGL_VEL,
	IIO_MAGN,
	IIO_LIGHT,
	IIO_INTENSITY,
	IIO_PROXIMITY,
	IIO_TEMP,
	IIO_INCLI,
	IIO_ROT,
	IIO_ANGL,
	IIO_TIMESTAMP,
	IIO_CAPACITANCE,
	IIO_ALTVOLTAGE,
	IIO_CCT,
	IIO_PRESSURE,
	IIO_HUMIDITYRELATIVE,
	IIO_ACTIVITY,
	IIO_STEPS,
	IIO_ENERGY,
	IIO_DISTANCE,
	IIO_VELOCITY,
	IIO_CONCENTRATION,
	IIO_RESISTANCE
} iio_chan_t;


typedef enum iio_modifier {
	IIO_NO_MOD,
	IIO_MOD_X,
	IIO_MOD_Y,
	IIO_MOD_Z,
	IIO_MOD_X_AND_Y,
	IIO_MOD_X_AND_Z,
	IIO_MOD_Y_AND_Z,
	IIO_MOD_X_AND_Y_AND_Z,
	IIO_MOD_X_OR_Y,
	IIO_MOD_X_OR_Z,
	IIO_MOD_Y_OR_Z,
	IIO_MOD_X_OR_Y_OR_Z,
	IIO_MOD_LIGHT_BOTH,
	IIO_MOD_LIGHT_IR,
	IIO_MOD_ROOT_SUM_SQUARED_X_Y,
	IIO_MOD_SUM_SQUARED_X_Y_Z,
	IIO_MOD_LIGHT_CLEAR,
	IIO_MOD_LIGHT_RED,
	IIO_MOD_LIGHT_GREEN,
	IIO_MOD_LIGHT_BLUE,
	IIO_MOD_QUATERNION,
	IIO_MOD_TEMP_AMBIENT,
	IIO_MOD_TEMP_OBJECT,
	IIO_MOD_NORTH_MAGN,
	IIO_MOD_NORTH_TRUE,
	IIO_MOD_NORTH_MAGN_TILT_COMP,
	IIO_MOD_NORTH_TRUE_TILT_COMP,
	IIO_MOD_RUNNING,
	IIO_MOD_JOGGING,
	IIO_MOD_WALKING,
	IIO_MOD_STILL,
	IIO_MOD_ROOT_SUM_SQUARED_X_Y_Z,
	IIO_MOD_I,
	IIO_MOD_Q,
	IIO_MOD_CO2,
	IIO_MOD_VOC
} iio_modifier_t;


typedef enum iio_event_type {
	IIO_EV_TYPE_THRESH,
	IIO_EV_TYPE_MAG,
	IIO_EV_TYPE_ROC,
	IIO_EV_TYPE_THRESH_ADAPTIVE,
	IIO_EV_TYPE_MAG_ADAPTIVE,
	IIO_EV_TYPE_CHANGE
} iio_event_t;


typedef enum iio_event_direction {
	IIO_EV_DIR_EITHER,
	IIO_EV_DIR_RISING,
	IIO_EV_DIR_FALLING,
	IIO_EV_DIR_NONE
} iio_event_direction_t;


#endif  // IIO_TYPES_H


/* MINIX VBOX */


#if ((!(defined(MINIX_VBOXTYPE_H) || defined(_MINIX_VBOXTYPE_H) || defined(_MINIX_VBOXTYPE_H_))) && defined(OSMINIX))
#define MINIX_VBOXTYPE_H   (1)
#define _MINIX_VBOXTYPE_H   (1)
#define _MINIX_VBOXTYPE_H_   (1)


// This header declares the type definitions shared between VBOX driver, the interface in libsys, and any caller of those interface functions

/** Call parameter type */
typedef enum vbox_type {
	VBOX_TYPE_INVALID,  // Invalid type
	VBOX_TYPE_U32,  // 32-bit value
	VBOX_TYPE_U64,  // 64-bit value
	VBOX_TYPE_PTR  // Pointer to granted memory area
} vbox_type_t;

// Call parameter transfer direction
/** From host to guest */
#define VBOX_DIR_IN   1
/** From guest to host */
#define VBOX_DIR_OUT   2
#define VBOX_DIR_INOUT   (VBOX_DIR_IN | VBOX_DIR_OUT)

/** Call parameter */
typedef struct attr_packed vbox_param {
	vbox_type_t type;
	union _vbox_data {
		uint32_t data_u32;
		uint64_t data_u64;
		struct attr_packed vbox_param_ptr {
			cp_grant_id_t grant;
			size_t off, size;
			unsigned int dir;
		} ptr;
	} _vbox_data;
} vbox_param_t;


#endif  // MINIX_VBOXTYPE_H


/* MINIX CONSTANTS */


#if ((!(defined(MINIX_CONST_H) || defined(_MINIX_CONST_H) || defined(_MINIX_CONST_H_))) && defined(OSMINIX))
#define MINIX_CONST_H   (1)
#define _MINIX_CONST_H   (1)
#define _MINIX_CONST_H_   (1)


/** uid_t of superuser */
#define SUPER_USER   ((uid_t)0)
/** super_user's uid_t */
#define SU_UID   SUPER_USER
/** uid_t for processes PM and INIT (on Minix and perhaps other systems) */
#define SYS_UID   ((uid_t)0)
/** gid_t for processes PM and INIT (on Minix and perhaps other systems) */
#define SYS_GID   ((gid_t)0)
#define GETDENTS_BUFSIZ   1024
/** Max # of entries in a SYS_VSAFECOPY request */
#define SCPVEC_NR   64
/** Max # of entries in a SYS_VUMAP request */
#define MAPVEC_NR   64
/** Maximum number of entries in an iorequest */
#define NR_IOREQS   64
/** SYS_VUMAP: read access */
#define VUA_READ   1
/** SYS_VUMAP: write access */
#define VUA_WRITE   2
// MEMORY RELATED CONSTANTS
/** Bit mask to get segment type */
#define SEGMENT_TYPE   0xff00
/** Bit mask to get segment index */
#define SEGMENT_INDEX   0xff
/** Flag indicating entire physical memory */
#define PHYS_SEG   0x400
/** Same as LOCAL_SEG, but with vm lookup */
#define LOCAL_VM_SEG   0x1000
#define MEM_GRANT   3
#define VIR_ADDR   1
#define VM_D   (LOCAL_VM_SEG | VIR_ADDR)
#define VM_GRANT   (LOCAL_VM_SEG | MEM_GRANT)
// LABELS USED TO DISABLE CODE SECTIONS
/** Unused code in normal configuration */
#define DEAD_CODE   0
/** New code to be activated + tested later */
#define FUTURE_CODE   0
/** Active code to be removed later */
#define TEMP_CODE   1
/** Scattered I/O */
#define HAVE_SCATTERED_IO   1
// MEMORY IS ALLOCATED IN CLICKS
/** Unit in which memory is allocated */
#define CLICK_SIZE   4096
/** log2 of CLICK_SIZE */
#define CLICK_SHIFT   12
// CLICK ALIGNMENT MACROS
#define CLICK_FLOOR(n)   (((vir_bytes)(n) / CLICK_SIZE) * CLICK_SIZE)
#define CLICK_CEIL(n)   CLICK_FLOOR((vir_bytes)(n) + CLICK_SIZE - 1)
#define CLICK2ABS(v)   ((v) << CLICK_SHIFT)
#define ABS2CLICK(a)   ((a) >> CLICK_SHIFT)
/** Sizes of memory tables */
#define NR_MEMS   16
// FLAG BITS FOR I_MODE IN THE INODE
/** Field gives inode type */
#define I_TYPE   0170000
/** Unix domain socket */
#define I_UNIX_SOCKET   0140000
/** File is a symbolic link */
#define I_SYMBOLIC_LINK   0120000
/** Regular file, not dir or special */
#define I_REGULAR   0100000
/** Block special file */
#define I_BLOCK_SPECIAL   060000
/** File is a directory */
#define I_DIRECTORY   040000
/** Character special file */
#define I_CHAR_SPECIAL   020000
/** Named pipe (FIFO) */
#define I_NAMED_PIPE   010000
/** Set effective uid_t on exec */
#define I_SET_UID_BIT   04000
/** Set effective gid_t on exec */
#define I_SET_GID_BIT   02000
/** Sticky bit */
#define I_SET_STCKY_BIT   01000
/** All bits for user, group and others */
#define ALL_MODES   07777
/** Mode bits for RWX only */
#define RWX_MODES   0777
/** Rwx protection bit */
#define R_BIT   4
/** rWx protection bit */
#define W_BIT   2
/** rwX protection bit */
#define X_BIT   1
/** Free inode */
#define I_NOT_ALLOC   0
// LIMITS
/** Largest inode number */
#define MAX_INODE_NR   ((ino_t)037777777777)
/** Largest legal file offset */
#define MAX_FILE_POS   ((off_t)0x7fffffff)
/** Largest legal file offset */
#define UMAX_FILE_POS   ((unsigned)0x7fffffff)
/** Max symbolic link recursion */
#define MAX_SYM_LOOPS   8
/** Absence of a block number */
#define NO_BLOCK   ((block_t)0)
/** Absence of a dir entry */
#define NO_ENTRY   ((ino_t)0)
/** Absence of a zone number */
#define NO_ZONE   ((zone_t)0)
/** Absence of incoming links */
#define NO_LINK   ((nlink_t)0)
#ifndef NO_DEV
/** Absence of a device numb */
#   define NO_DEV   ((dev_t)0)
#endif
/** Invalid UID value */
#define INVAL_UID   ((uid_t)-1)
/** Invalid GID value */
#define INVAL_GID   ((gid_t)-1)
#define SERVARNAME   "cttyline"
#define ARCHVARNAME   "arch"
#define BOARDVARNAME   "board"
#define SERBAUDVARNAME   "cttybaud"
// BITS FOR S_FLAGS IN THE PRIVILEGE STRUCTURE
/** Kernel tasks are not preemptible */
#define PREEMPTIBLE   2
/** Some processes are not billable */
#define BILLABLE   4
/** Privilege id assigned dynamically */
#define DYN_PRIV_ID   8
/** System processes have own priv structure */
#define SYS_PROC   0x10
/** Check if I/O request is allowed */
#define CHECK_IO_PORT   0x20
/** Check if IRQ can be used */
#define CHECK_IRQ   0x40
/** Check if (VM) mem map request is allowed */
#define CHECK_MEM   0x80
/** Root-system process instance */
#define ROOT_SYS_PROC   0x100
/** VM system process instance */
#define VM_SYS_PROC   0x200
/** live updated sys proc instance */
#define LU_SYS_PROC   0x400
/** Restarted sys proc instance */
#define RST_SYS_PROC   0x800
// VALUES FOR THE "VERBOSE" BOOT MONITOR VARIABLE
#define VERBOSEBOOT_QUIET   0
#define VERBOSEBOOT_BASIC   1
#define VERBOSEBOOT_EXTRA   2
#define VERBOSEBOOT_MAX   3
#define VERBOSEBOOTVARNAME   "verbose"
/** Magic value to put in struct proc entries for sanity checks */
#define PMAGIC   0xc0ffee1
// MINIX_KERNFLAGS flags
/** SYSENTER available and supported */
#define MKF_I386_INTEL_SYSENTER   (1L)
/** SYSCALL available and supported */
#define MKF_I386_AMD_SYSCALL   (2L)


#endif  // MINIX_CONST_H


/* VMX ARCHITECTURE RELATED DEFINITIONS (<vmx.h>) */


#if ((!(defined(VMX_H) || defined(_VMX_H) || defined(_VMX_H_))) && defined(ARCH_VMX))
#define VMX_H   (1)
#define _VMX_H   (1)
#define _VMX_H_   (1)


// DEFINITIONS OF PRIMARY PROCESSOR-BASED VM-EXECUTION CONTROLS
#define CPU_BASED_VIRTUAL_INTR_PENDING   4
#define CPU_BASED_USE_TSC_OFFSETING   8
#define CPU_BASED_HLT_EXITING   0x80
#define CPU_BASED_INVLPG_EXITING   0x200
#define CPU_BASED_MWAIT_EXITING   0x400
#define CPU_BASED_RDPMC_EXITING   0x800
#define CPU_BASED_RDTSC_EXITING   0x1000
#define CPU_BASED_CR3_LOAD_EXITING   0x8000
#define CPU_BASED_CR3_STORE_EXITING   0x10000
#define CPU_BASED_CR8_LOAD_EXITING   0x80000
#define CPU_BASED_CR8_STORE_EXITING   0x100000
#define CPU_BASED_TPR_SHADOW   0x200000
#define CPU_BASED_VIRTUAL_NMI_PENDING   0x400000
#define CPU_BASED_MOV_DR_EXITING   0x800000
#define CPU_BASED_UNCOND_IO_EXITING   0x1000000
#define CPU_BASED_USE_IO_BITMAPS   0x2000000
#define CPU_BASED_USE_MSR_BITMAPS   0x10000000
#define CPU_BASED_MONITOR_EXITING   0x20000000
#define CPU_BASED_PAUSE_EXITING   0x40000000
#define CPU_BASED_ACTIVATE_SECONDARY_CONTROLS   0x80000000
#define CPU_BASED_ALWAYSON_WITHOUT_TRUE_MSR   0x401e172

// DEFINITIONS OF SECONDARY PROCESSOR-BASED VM-EXECUTION CONTROLS
#define SECONDARY_EXEC_VIRTUALIZE_APIC_ACCESSES   1
#define SECONDARY_EXEC_ENABLE_EPT   2
#define SECONDARY_EXEC_RDTSCP   8
#define SECONDARY_EXEC_VIRTUALIZE_X2APIC_MODE   0x10
#define SECONDARY_EXEC_ENABLE_VPID   0x20
#define SECONDARY_EXEC_WBINVD_EXITING   0x40
#define SECONDARY_EXEC_UNRESTRICTED_GUEST   0x80
#define SECONDARY_EXEC_APIC_REGISTER_VIRT   0x100
#define SECONDARY_EXEC_VIRTUAL_INTR_DELIVERY   0x200
#define SECONDARY_EXEC_PAUSE_LOOP_EXITING   0x400
#define SECONDARY_EXEC_ENABLE_INVPCID   0x1000
#define SECONDARY_EXEC_SHADOW_VMCS   0x4000
#define SECONDARY_EXEC_ENABLE_PML   0x20000
#define SECONDARY_EXEC_XSAVES   0x100000
#define PIN_BASED_EXT_INTR_MASK   1
#define PIN_BASED_NMI_EXITING   8
#define PIN_BASED_VIRTUAL_NMIS   0x20
#define PIN_BASED_VMX_PREEMPTION_TIMER   0x40
#define PIN_BASED_POSTED_INTR   0x80
#define PIN_BASED_ALWAYSON_WITHOUT_TRUE_MSR   0x16
#define VM_EXIT_SAVE_DEBUG_CONTROLS   4
#define VM_EXIT_HOST_ADDR_SPACE_SIZE   0x200
#define VM_EXIT_LOAD_IA32_PERF_GLOBAL_CTRL   0x1000
#define VM_EXIT_ACK_INTR_ON_EXIT   0x8000
#define VM_EXIT_SAVE_IA32_PAT   0x40000
#define VM_EXIT_LOAD_IA32_PAT   0x80000
#define VM_EXIT_SAVE_IA32_EFER   0x100000
#define VM_EXIT_LOAD_IA32_EFER   0x200000
#define VM_EXIT_SAVE_VMX_PREEMPTION_TIMER   0x400000
#define VM_EXIT_CLEAR_BNDCFGS   0x800000
#define VM_EXIT_ALWAYSON_WITHOUT_TRUE_MSR   0x36dff
#define VM_ENTRY_LOAD_DEBUG_CONTROLS   4
#define VM_ENTRY_IA32E_MODE   0x200
#define VM_ENTRY_SMM   0x400
#define VM_ENTRY_DEACT_DUAL_MONITOR   0x800
#define VM_ENTRY_LOAD_IA32_PERF_GLOBAL_CTRL   0x2000
#define VM_ENTRY_LOAD_IA32_PAT   0x4000
#define VM_ENTRY_LOAD_IA32_EFER   0x8000
#define VM_ENTRY_LOAD_BNDCFGS   0x10000
#define VM_ENTRY_ALWAYSON_WITHOUT_TRUE_MSR   0x11ff
#define VMX_MISC_PREEMPTION_TIMER_RATE_MASK   0x1f
#define VMX_MISC_SAVE_EFER_LMA   0x20
#define VMX_MISC_ACTIVITY_HLT   0x40

/** VMCS Encodings */
enum vmcs_field {
	VIRTUAL_PROCESSOR_ID = 0,
	POSTED_INTR_NV = 2,
	GUEST_ES_SELECTOR = 0x800,
	GUEST_CS_SELECTOR = 0x802,
	GUEST_SS_SELECTOR = 0x804,
	GUEST_DS_SELECTOR = 0x806,
	GUEST_FS_SELECTOR = 0x808,
	GUEST_GS_SELECTOR = 0x80a,
	GUEST_LDTR_SELECTOR = 0x80c,
	GUEST_TR_SELECTOR = 0x80e,
	GUEST_INTR_STATUS = 0x810,
	GUEST_PML_INDEX = 0x812,
	HOST_ES_SELECTOR = 0xc00,
	HOST_CS_SELECTOR = 0xc02,
	HOST_SS_SELECTOR = 0xc04,
	HOST_DS_SELECTOR = 0xc06,
	HOST_FS_SELECTOR = 0xc08,
	HOST_GS_SELECTOR = 0xc0a,
	HOST_TR_SELECTOR = 0xc0c,
	IO_BITMAP_A = 0x2000,
	IO_BITMAP_A_HIGH = 0x2001,
	IO_BITMAP_B = 0x2002,
	IO_BITMAP_B_HIGH = 0x2003,
	MSR_BITMAP = 0x2004,
	MSR_BITMAP_HIGH = 0x2005,
	VM_EXIT_MSR_STORE_ADDR = 0x2006,
	VM_EXIT_MSR_STORE_ADDR_HIGH = 0x2007,
	VM_EXIT_MSR_LOAD_ADDR = 0x2008,
	VM_EXIT_MSR_LOAD_ADDR_HIGH = 0x2009,
	VM_ENTRY_MSR_LOAD_ADDR = 0x200a,
	VM_ENTRY_MSR_LOAD_ADDR_HIGH = 0x200b,
	PML_ADDRESS = 0x200e,
	PML_ADDRESS_HIGH = 0x200f,
	TSC_OFFSET = 0x2010,
	TSC_OFFSET_HIGH = 0x2011,
	VIRTUAL_APIC_PAGE_ADDR = 0x2012,
	VIRTUAL_APIC_PAGE_ADDR_HIGH = 0x2013,
	APIC_ACCESS_ADDR = 0x2014,
	APIC_ACCESS_ADDR_HIGH = 0x2015,
	POSTED_INTR_DESC_ADDR = 0x2016,
	POSTED_INTR_DESC_ADDR_HIGH = 0x2017,
	EPT_POINTER = 0x201a,
	EPT_POINTER_HIGH = 0x201b,
	EOI_EXIT_BITMAP0 = 0x201c,
	EOI_EXIT_BITMAP0_HIGH = 0x201d,
	EOI_EXIT_BITMAP1 = 0x201e,
	EOI_EXIT_BITMAP1_HIGH = 0x201f,
	EOI_EXIT_BITMAP2 = 0x2020,
	EOI_EXIT_BITMAP2_HIGH = 0x2021,
	EOI_EXIT_BITMAP3 = 0x2022,
	EOI_EXIT_BITMAP3_HIGH = 0x2023,
	VMREAD_BITMAP = 0x2026,
	VMWRITE_BITMAP = 0x2028,
	XSS_EXIT_BITMAP = 0x202c,
	XSS_EXIT_BITMAP_HIGH = 0x202d,
	GUEST_PHYSICAL_ADDRESS = 0x2400,
	GUEST_PHYSICAL_ADDRESS_HIGH = 0x2401,
	VMCS_LINK_POINTER = 0x2800,
	VMCS_LINK_POINTER_HIGH = 0x2801,
	GUEST_IA32_DEBUGCTL = 0x2802,
	GUEST_IA32_DEBUGCTL_HIGH = 0x2803,
	GUEST_IA32_PAT = 0x2804,
	GUEST_IA32_PAT_HIGH = 0x2805,
	GUEST_IA32_EFER = 0x2806,
	GUEST_IA32_EFER_HIGH = 0x2807,
	GUEST_IA32_PERF_GLOBAL_CTRL = 0x2808,
	GUEST_IA32_PERF_GLOBAL_CTRL_HIGH = 0x2809,
	GUEST_PDPTR0 = 0x280a,
	GUEST_PDPTR0_HIGH = 0x280b,
	GUEST_PDPTR1 = 0x280c,
	GUEST_PDPTR1_HIGH = 0x280d,
	GUEST_PDPTR2 = 0x280e,
	GUEST_PDPTR2_HIGH = 0x280f,
	GUEST_PDPTR3 = 0x2810,
	GUEST_PDPTR3_HIGH = 0x2811,
	GUEST_BNDCFGS = 0x2812,
	GUEST_BNDCFGS_HIGH = 0x2813,
	HOST_IA32_PAT = 0x2c00,
	HOST_IA32_PAT_HIGH = 0x2c01,
	HOST_IA32_EFER = 0x2c02,
	HOST_IA32_EFER_HIGH = 0x2c03,
	HOST_IA32_PERF_GLOBAL_CTRL = 0x2c04,
	HOST_IA32_PERF_GLOBAL_CTRL_HIGH = 0x2c05,
	PIN_BASED_VM_EXEC_CONTROL = 0x4000,
	CPU_BASED_VM_EXEC_CONTROL = 0x4002,
	EXCEPTION_BITMAP = 0x4004,
	PAGE_FAULT_ERROR_CODE_MASK = 0x4006,
	PAGE_FAULT_ERROR_CODE_MATCH = 0x4008,
	CR3_TARGET_COUNT = 0x400a,
	VM_EXIT_CONTROLS = 0x400c,
	VM_EXIT_MSR_STORE_COUNT = 0x400e,
	VM_EXIT_MSR_LOAD_COUNT = 0x4010,
	VM_ENTRY_CONTROLS = 0x4012,
	VM_ENTRY_MSR_LOAD_COUNT = 0x4014,
	VM_ENTRY_INTR_INFO_FIELD = 0x4016,
	VM_ENTRY_EXCEPTION_ERROR_CODE = 0x4018,
	VM_ENTRY_INSTRUCTION_LEN = 0x401a,
	TPR_THRESHOLD = 0x401c,
	SECONDARY_VM_EXEC_CONTROL = 0x401e,
	PLE_GAP = 0x4020,
	PLE_WINDOW = 0x4022,
	VM_INSTRUCTION_ERROR = 0x4400,
	VM_EXIT_REASON = 0x4402,
	VM_EXIT_INTR_INFO = 0x4404,
	VM_EXIT_INTR_ERROR_CODE = 0x4406,
	IDT_VECTORING_INFO_FIELD = 0x4408,
	IDT_VECTORING_ERROR_CODE = 0x440a,
	VM_EXIT_INSTRUCTION_LEN = 0x440c,
	VMX_INSTRUCTION_INFO = 0x440e,
	GUEST_ES_LIMIT = 0x4800,
	GUEST_CS_LIMIT = 0x4802,
	GUEST_SS_LIMIT = 0x4804,
	GUEST_DS_LIMIT = 0x4806,
	GUEST_FS_LIMIT = 0x4808,
	GUEST_GS_LIMIT = 0x480a,
	GUEST_LDTR_LIMIT = 0x480c,
	GUEST_TR_LIMIT = 0x480e,
	GUEST_GDTR_LIMIT = 0x4810,
	GUEST_IDTR_LIMIT = 0x4812,
	GUEST_ES_AR_BYTES = 0x4814,
	GUEST_CS_AR_BYTES = 0x4816,
	GUEST_SS_AR_BYTES = 0x4818,
	GUEST_DS_AR_BYTES = 0x481a,
	GUEST_FS_AR_BYTES = 0x481c,
	GUEST_GS_AR_BYTES = 0x481e,
	GUEST_LDTR_AR_BYTES = 0x4820,
	GUEST_TR_AR_BYTES = 0x4822,
	GUEST_INTERRUPTIBILITY_INFO = 0x4824,
	GUEST_ACTIVITY_STATE = 0x4826,
	GUEST_SYSENTER_CS = 0x482a,
	VMX_PREEMPTION_TIMER_VALUE = 0x482e,
	HOST_IA32_SYSENTER_CS = 0x4c00,
	CR0_GUEST_HOST_MASK = 0x6000,
	CR4_GUEST_HOST_MASK = 0x6002,
	CR0_READ_SHADOW = 0x6004,
	CR4_READ_SHADOW = 0x6006,
	CR3_TARGET_VALUE0 = 0x6008,
	CR3_TARGET_VALUE1 = 0x600a,
	CR3_TARGET_VALUE2 = 0x600c,
	CR3_TARGET_VALUE3 = 0x600e,
	EXIT_QUALIFICATION = 0x6400,
	GUEST_LINEAR_ADDRESS = 0x640a,
	GUEST_CR0 = 0x6800,
	GUEST_CR3 = 0x6802,
	GUEST_CR4 = 0x6804,
	GUEST_ES_BASE = 0x6806,
	GUEST_CS_BASE = 0x6808,
	GUEST_SS_BASE = 0x680a,
	GUEST_DS_BASE = 0x680c,
	GUEST_FS_BASE = 0x680e,
	GUEST_GS_BASE = 0x6810,
	GUEST_LDTR_BASE = 0x6812,
	GUEST_TR_BASE = 0x6814,
	GUEST_GDTR_BASE = 0x6816,
	GUEST_IDTR_BASE = 0x6818,
	GUEST_DR7 = 0x681a,
	GUEST_RSP = 0x681c,
	GUEST_RIP = 0x681e,
	GUEST_RFLAGS = 0x6820,
	GUEST_PENDING_DBG_EXCEPTIONS = 0x6822,
	GUEST_SYSENTER_ESP = 0x6824,
	GUEST_SYSENTER_EIP = 0x6826,
	HOST_CR0 = 0x6c00,
	HOST_CR3 = 0x6c02,
	HOST_CR4 = 0x6c04,
	HOST_FS_BASE = 0x6c06,
	HOST_GS_BASE = 0x6c08,
	HOST_TR_BASE = 0x6c0a,
	HOST_GDTR_BASE = 0x6c0c,
	HOST_IDTR_BASE = 0x6c0e,
	HOST_IA32_SYSENTER_ESP = 0x6c10,
	HOST_IA32_SYSENTER_EIP = 0x6c12,
	HOST_RSP = 0x6c14,
	HOST_RIP = 0x6c16
};

// INTERRUPTION-INFORMATION FORMAT
#define INTR_INFO_VECTOR_MASK   0xff
#define INTR_INFO_INTR_TYPE_MASK   0x700
#define INTR_INFO_DELIVER_CODE_MASK   0x800
#define INTR_INFO_UNBLOCK_NMI   0x1000
#define INTR_INFO_VALID_MASK   0x80000000
#define INTR_INFO_RESVD_BITS_MASK   0x7ffff000
#define VECTORING_INFO_VECTOR_MASK   INTR_INFO_VECTOR_MASK
#define VECTORING_INFO_TYPE_MASK   INTR_INFO_INTR_TYPE_MASK
#define VECTORING_INFO_DELIVER_CODE_MASK   INTR_INFO_DELIVER_CODE_MASK
#define VECTORING_INFO_VALID_MASK   INTR_INFO_VALID_MASK
/** External interrupt */
#define INTR_TYPE_EXT_INTR   (0)
#define INTR_TYPE_NMI_INTR   (0x200)
/** Processor exception */
#define INTR_TYPE_HARD_EXCEPTION   (0x300)
/** Software interrupt */
#define INTR_TYPE_SOFT_INTR   (0x400)
/** Software exception */
#define INTR_TYPE_SOFT_EXCEPTION   (0x600)

/** GUEST_INTERRUPTIBILITY_INFO FLAGS */
enum GUEST_INTERRUPTIBILITY_INFO {
	GUEST_INTR_STATE_STI = 1,
	GUEST_INTR_STATE_MOV_SS = 2,
	GUEST_INTR_STATE_SMI = 4,
	GUEST_INTR_STATE_NMI = 8
};

/** Guest activity state flags */
enum GUEST_ACTIVITY_STATE {
	GUEST_ACTIVITY_ACTIVE = 0,
	GUEST_ACTIVITY_HLT = 1,
	GUEST_ACTIVITY_SHUTDOWN = 2,
	GUEST_ACTIVITY_WAIT_SIPI = 3
};

// EXIT QUALIFICATIONS FOR MOV FOR DEBUG REGISTER ACCESS
#define DEBUG_REG_ACCESS_NUM    (7)
#define DEBUG_REG_ACCESS_TYPE   (0x10)
#define TYPE_MOV_TO_DR   (0)
#define TYPE_MOV_FROM_DR   (0x10)
#define DEBUG_REG_ACCESS_REG(eq)   (((eq) >> 8) & 0xf)

// EXIT QUALIFICATIONS FOR APIC-ACCESS
#define APIC_ACCESS_OFFSET   (0xfff)
#define APIC_ACCESS_TYPE   (0xf000)
#define TYPE_LINEAR_APIC_INST_READ   (0)
#define TYPE_LINEAR_APIC_INST_WRITE   (0x1000)
#define TYPE_LINEAR_APIC_INST_FETCH   (0x2000)
#define TYPE_LINEAR_APIC_EVENT   (0x3000)
#define TYPE_PHYSICAL_APIC_EVENT   (0xa000)
#define TYPE_PHYSICAL_APIC_INST   (0xf000)

// EXIT QUALIFICATIONS FOR MOV FOR CONTROL REGISTER ACCESS
#define CONTROL_REG_ACCESS_NUM   (7)
#define CONTROL_REG_ACCESS_TYPE   (0x30)
#define CONTROL_REG_ACCESS_REG   (0xf00)
#define LMSW_SOURCE_DATA_SHIFT   (16)
#define LMSW_SOURCE_DATA   (UINT16_MAX << LMSW_SOURCE_DATA_SHIFT)
enum VMX_REGISTERS {
	REG_EAX = 0,
	REG_ECX = 0x100,
	REG_EDX = 0x200,
	REG_EBX = 0x300,
	REG_ESP = 0x400,
	REG_EBP = 0x500,
	REG_ESI = 0x600,
	REG_EDI = 0x700,
	REG_R8 = 0x800,
	REG_R9 = 0x900,
	REG_R10 = 0xa00,
	REG_R11 = 0xb00,
	REG_R12 = 0xc00,
	REG_R13 = 0xd00,
	REG_R14 = 0xe00,
	REG_R15 = 0xf00
};

// SEGMENT AR
#define SEGMENT_AR_L_MASK   (0x2000)
#define AR_TYPE_ACCESSES_MASK   (1)
#define AR_TYPE_READABLE_MASK   (2)
#define AR_TYPE_WRITEABLE_MASK   (4)
#define AR_TYPE_CODE_MASK   (8)
#define AR_TYPE_MASK   (0xf)
#define AR_TYPE_BUSY_64_TSS   (11)
#define AR_TYPE_BUSY_32_TSS   (11)
#define AR_TYPE_BUSY_16_TSS   (3)
#define AR_TYPE_LDT   (2)
#define AR_UNUSABLE_MASK   (0x10000)
#define AR_S_MASK   (0x10)
#define AR_P_MASK   (0x80)
#define AR_L_MASK   (0x2000)
#define AR_DB_MASK   (0x4000)
#define AR_G_MASK   (0x8000)
#define AR_DPL_SHIFT   (5)
#define AR_DPL(ar)   (((ar) >> AR_DPL_SHIFT) & 3)
#define AR_RESERVD_MASK   0xfffe0f00
#define TSS_PRIVATE_MEMSLOT   (KVM_USER_MEM_SLOTS)
#define APIC_ACCESS_PAGE_PRIVATE_MEMSLOT   (KVM_USER_MEM_SLOTS + 1)
#define IDENTITY_PAGETABLE_PRIVATE_MEMSLOT   (KVM_USER_MEM_SLOTS + 2)
#define VMX_NR_VPIDS   (0x10000)
#define VMX_VPID_EXTENT_SINGLE_CONTEXT   (1)
#define VMX_VPID_EXTENT_ALL_CONTEXT   (2)
#define VMX_EPT_EXTENT_INDIVIDUAL_ADDR   (0)
#define VMX_EPT_EXTENT_CONTEXT   (1)
#define VMX_EPT_EXTENT_GLOBAL   (2)
#define VMX_EPT_EXTENT_SHIFT   (24)
#define VMX_EPT_EXECUTE_ONLY_BIT   (1ULL)
#define VMX_EPT_PAGE_WALK_4_BIT   (0x40ULL)
#define VMX_EPTP_UC_BIT   (0x100ULL)
#define VMX_EPTP_WB_BIT   (0x4000ULL)
#define VMX_EPT_2MB_PAGE_BIT   (0x10000ULL)
#define VMX_EPT_1GB_PAGE_BIT   (0x20000ULL)
#define VMX_EPT_INVEPT_BIT   (0x100000ULL)
#define VMX_EPT_AD_BIT   (0x200000)
#define VMX_EPT_EXTENT_CONTEXT_BIT   (0x2000000ULL)
#define VMX_EPT_EXTENT_GLOBAL_BIT   (0x4000000)
#define VMX_VPID_EXTENT_SINGLE_CONTEXT_BIT   (0x200ULL)
#define VMX_VPID_EXTENT_GLOBAL_CONTEXT_BIT   (0x400ULL)
#define VMX_EPT_DEFAULT_GAW   (3)
#define VMX_EPT_MAX_GAW   (4)
#define VMX_EPT_MT_EPTE_SHIFT   (3)
#define VMX_EPT_GAW_EPTP_SHIFT   (3)
#define VMX_EPT_AD_ENABLE_BIT   (0x40ULL)
#define VMX_EPT_DEFAULT_MT   (6ULL)
#define VMX_EPT_READABLE_MASK   (1ULL)
#define VMX_EPT_WRITABLE_MASK   (2ULL)
#define VMX_EPT_EXECUTABLE_MASK   (4ULL)
#define VMX_EPT_IPAT_BIT   (0x40ULL)
#define VMX_EPT_ACCESS_BIT   (0x100ULL)
#define VMX_EPT_DIRTY_BIT   (0x200ULL)
#define VMX_EPT_IDENTITY_PAGETABLE_ADDR   (0xfffbc000UL)
#define ASM_VMX_VMCLEAR_RAX   ".byte 0x66, 0x0f, 0xc7, 0x30"
#define ASM_VMX_VMLAUNCH   ".byte 0x0f, 0x01, 0xc2"
#define ASM_VMX_VMRESUME   ".byte 0x0f, 0x01, 0xc3"
#define ASM_VMX_VMPTRLD_RAX   ".byte 0x0f, 0xc7, 0x30"
#define ASM_VMX_VMREAD_RDX_RAX   ".byte 0x0f, 0x78, 0xd0"
#define ASM_VMX_VMWRITE_RAX_RDX   ".byte 0x0f, 0x79, 0xd0"
#define ASM_VMX_VMWRITE_RSP_RDX   ".byte 0x0f, 0x79, 0xd4"
#define ASM_VMX_VMXOFF   ".byte 0x0f, 0x01, 0xc4"
#define ASM_VMX_VMXON_RAX   ".byte 0xf3, 0x0f, 0xc7, 0x30"
#define ASM_VMX_INVEPT   ".byte 0x66, 0x0f, 0x38, 0x80, 0x08"
#define ASM_VMX_INVVPID   ".byte 0x66, 0x0f, 0x38, 0x81, 0x08"

typedef struct align16 vmx_msr_entry {
	uint32_t index, reserved;
	uint64_t value;
} vmx_msr_entry_t;


/** EXIT QUALIFICATIONS FOR ENTRY FAILURE DURING OR AFTER LOADING GUEST STATE */
enum VMX_ENTRY_FAIL {
	ENTRY_FAIL_DEFAULT = 0,
	ENTRY_FAIL_PDPTE = 2,
	ENTRY_FAIL_NMI = 3,
	ENTRY_FAIL_VMCS_LINK_PTR = 4
};

/** VM-instruction error numbers */
enum vm_instruction_error_number {
	VMXERR_VMCALL_IN_VMX_ROOT_OPERATION = 1,
	VMXERR_VMCLEAR_INVALID_ADDRESS = 2,
	VMXERR_VMCLEAR_VMXON_POINTER = 3,
	VMXERR_VMLAUNCH_NONCLEAR_VMCS = 4,
	VMXERR_VMRESUME_NONLAUNCHED_VMCS = 5,
	VMXERR_VMRESUME_AFTER_VMXOFF = 6,
	VMXERR_ENTRY_INVALID_CONTROL_FIELD = 7,
	VMXERR_ENTRY_INVALID_HOST_STATE_FIELD = 8,
	VMXERR_VMPTRLD_INVALID_ADDRESS = 9,
	VMXERR_VMPTRLD_VMXON_POINTER = 10,
	VMXERR_VMPTRLD_INCORRECT_VMCS_REVISION_ID = 11,
	VMXERR_UNSUPPORTED_VMCS_COMPONENT = 12,
	VMXERR_VMWRITE_READ_ONLY_VMCS_COMPONENT = 13,
	VMXERR_VMXON_IN_VMX_ROOT_OPERATION = 15,
	VMXERR_ENTRY_INVALID_EXECUTIVE_VMCS_POINTER = 16,
	VMXERR_ENTRY_NONLAUNCHED_EXECUTIVE_VMCS = 17,
	VMXERR_ENTRY_EXECUTIVE_VMCS_POINTER_NOT_VMXON_POINTER = 18,
	VMXERR_VMCALL_NONCLEAR_VMCS = 19,
	VMXERR_VMCALL_INVALID_VM_EXIT_CONTROL_FIELDS = 20,
	VMXERR_VMCALL_INCORRECT_MSEG_REVISION_ID = 22,
	VMXERR_VMXOFF_UNDER_DUAL_MONITOR_TREATMENT_OF_SMIS_AND_SMM = 23,
	VMXERR_VMCALL_INVALID_SMM_MONITOR_FEATURES = 24,
	VMXERR_ENTRY_INVALID_VM_EXECUTION_CONTROL_FIELDS_IN_EXECUTIVE_VMCS = 25,
	VMXERR_ENTRY_EVENTS_BLOCKED_BY_MOV_SS = 26,
	VMXERR_INVALID_OPERAND_TO_INVEPT_INVVPID = 28
};


#endif  // VMX_H


/* PRTYPES (<prtypes.h>) */


#if ((!(defined(PRTYPES_H) || defined(_PRTYPES_H_))) && defined(ALLOW_HEADER_PRTYPES_H))
#define PRTYPES_H   (1)
#define _PRTYPES_H_   (1)


#ifdef WIN32


#   define PR_EXPORT(__type)   extern dllexport __type
#   define PR_EXPORT_DATA(__type)   extern dllexport __type
#   define PR_IMPORT(__type)   dllimport __type
#   define PR_IMPORT_DATA(__type)   dllimport __type
#   define PR_EXTERN(__type)   extern dllexport __type
#   define PR_IMPLEMENT(__type)   dllexport __type
#   define PR_EXTERN_DATA(__type)   extern dllexport __type
#   define PR_IMPLEMENT_DATA(__type)   dllexport __type
#   define PR_CALLBACK
#   define PR_CALLBACK_DECL
#   define PR_STATIC_CALLBACK(__x)   static __x


#elif defined(XP_BEOS)


#   define PR_EXPORT(__type)   extern dllexport __type
#   define PR_EXPORT_DATA(__type)   extern dllexport __type
#   define PR_IMPORT(__type)   extern dllexport __type
#   define PR_IMPORT_DATA(__type)   extern dllexport __type
#   define PR_EXTERN(__type)   extern dllexport __type
#   define PR_IMPLEMENT(__type)   dllexport __type
#   define PR_EXTERN_DATA(__type)   extern dllexport __type
#   define PR_IMPLEMENT_DATA(__type)   dllexport __type
#   define PR_CALLBACK
#   define PR_CALLBACK_DECL
#   define PR_STATIC_CALLBACK(__x)   static __x


#elif (defined(XP_OS2) && defined(__declspec))


#   define PR_EXPORT(__type)   extern dllexport __type
#   define PR_EXPORT_DATA(__type)   extern dllexport __type
#   define PR_IMPORT(__type)   extern  dllimport __type
#   define PR_IMPORT_DATA(__type)   extern dllimport __type
#   define PR_EXTERN(__type)   extern dllexport __type
#   define PR_IMPLEMENT(__type)   dllexport __type
#   define PR_EXTERN_DATA(__type)   extern dllexport __type
#   define PR_IMPLEMENT_DATA(__type)   dllexport __type
#   define PR_CALLBACK
#   define PR_CALLBACK_DECL
#   define PR_STATIC_CALLBACK(__x)   static __x


#elif defined(OSSYMBIAN)


#   define PR_EXPORT(__type)   extern dllexport __type
#   define PR_EXPORT_DATA(__type)   extern dllexport __type
#   ifdef __WINS__
#      define PR_IMPORT(__type)   extern dllexport __type
#      define PR_IMPORT_DATA(__type)   extern dllexport __type
#   else
#      define PR_IMPORT(__type)   extern dllimport __type
#      define PR_IMPORT_DATA(__type)   extern dllimport __type
#   endif
#   define PR_EXTERN(__type)   extern __type
#   define PR_IMPLEMENT(__type)   __type
#   define PR_EXTERN_DATA(__type)   extern __type
#   define PR_IMPLEMENT_DATA(__type)   __type
#   define PR_CALLBACK
#   define PR_CALLBACK_DECL
#   define PR_STATIC_CALLBACK(__x)   static __x


#else  // Unix


#   if IS_GNUC
#      define PR_VISIBILITY_DEFAULT   __dso_public
#   else
#      define PR_VISIBILITY_DEFAULT
#   endif
#   define PR_EXPORT(__type)   extern PR_VISIBILITY_DEFAULT __type
#   define PR_EXPORT_DATA(__type)   extern PR_VISIBILITY_DEFAULT __type
#   define PR_IMPORT(__type)   extern PR_VISIBILITY_DEFAULT __type
#   define PR_IMPORT_DATA(__type)   extern PR_VISIBILITY_DEFAULT __type
#   define PR_EXTERN(__type)   extern PR_VISIBILITY_DEFAULT __type
#   define PR_IMPLEMENT(__type)   PR_VISIBILITY_DEFAULT __type
#   define PR_EXTERN_DATA(__type)   extern PR_VISIBILITY_DEFAULT __type
#   define PR_IMPLEMENT_DATA(__type)   PR_VISIBILITY_DEFAULT __type
#   define PR_CALLBACK
#   define PR_CALLBACK_DECL
#   define PR_STATIC_CALLBACK(__x)   static __x


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


/* SIGNAL STACK (<bits/sigstack.h>) */


#if (!(defined(SIGSTACK_H) || defined(_SIGSTACK_H) || defined(_SIGSTACK_H_)))
#define SIGSTACK_H   (1)
#define _SIGSTACK_H   (1)
#define _SIGSTACK_H_   (1)


// Possible values for `ss_flags`
#define SS_ONSTACK   1
#define SS_DISABLE   2

#ifdef ARCHALPHA
/** Minimum stack size for a signal handler */
#   define MINSIGSTKSZ   4096
/** System default stack size */
#   define SIGSTKSZ   16384
/** Structure describing a signal stack */
typedef struct attr_packed sigstack {
	void* ss_sp;  // Signal stack pointer
	int ss_onstack;  // Nonzero if executing on this stack
} sigstack_t;
/** Preferred signal stack interface */
typedef struct attr_packed sigaltstack {
	void* ss_sp;
	int ss_flags;
	size_t ss_size;
} stack_t;
#elif defined(ARCHMIPS)
/** Minimum stack size for a signal handler */
#   define MINSIGSTKSZ   2048
/** System default stack size */
#   define SIGSTKSZ   8192
/** Structure describing a signal stack */
typedef struct attr_packed sigstack {
	void* ss_sp;  // Signal stack pointer
	int ss_onstack;  // Nonzero if executing on this stack
} sigstack_t;
/** Preferred signal stack interface */
typedef struct attr_packed sigaltstack {
	void* ss_sp;
	size_t ss_size;
	int ss_flags;
} stack_t;
#elif defined(ARCHITANIUM)
/** Minimum stack size for a signal handler */
#   define MINSIGSTKSZ   131027
/** System default stack size */
#   define SIGSTKSZ   262144
/** Structure describing a signal stack */
typedef struct attr_packed sigstack {
	void* ss_sp;  // Signal stack pointer
	int ss_onstack;  // Nonzero if executing on this stack
} sigstack_t;
/** Preferred signal stack interface */
typedef struct attr_packed sigaltstack {
	void* ss_sp;
	int ss_flags;
	size_t ss_size;
} stack_t;
#elif defined(ARCHSPARC)
/** Minimum stack size for a signal handler */
#   define MINSIGSTKSZ   4096
/** System default stack size */
#   define SIGSTKSZ   16384
/** Structure describing a signal stack */
typedef struct attr_packed sigstack {
	void* ss_sp;  // Signal stack pointer
	int ss_onstack;  // Nonzero if executing on this stack
} sigstack_t;
/** Preferred signal stack interface */
typedef struct attr_packed sigaltstack {
	void* ss_sp;
	int ss_flags;
	size_t ss_size;
} stack_t;
#else
/** Minimum stack size for a signal handler */
#   define MINSIGSTKSZ   2048
/** System default stack size */
#   define SIGSTKSZ   8192
/** Structure describing a signal stack */
typedef struct attr_packed sigstack {
	void* ss_sp;  // Signal stack pointer
	int ss_onstack;  // Nonzero if executing on this stack
} sigstack_t;
/** Preferred signal stack interface */
typedef struct attr_packed sigaltstack {
	void* ss_sp;
	int ss_flags;
	size_t ss_size;
} stack_t;
#endif  // ARCH


#endif  // SIGSTACK_H


/* SIGCONTEXT & SYSTEM V COMPLIANT CONTEXT SWITCHING SUPPORT */


#if (!(defined(BITS_SIGCONTEXT_H) || defined(_BITS_SIGCONTEXT_H) || defined(SYS_UCONTEXT_H) || defined(_SYS_UCONTEXT_H)))
#define BITS_SIGCONTEXT_H   (1)
#define _BITS_SIGCONTEXT_H   (1)
#define SYS_UCONTEXT_H   (1)
#define _SYS_UCONTEXT_H   (1)


#ifdef ARCHARM
/** Context to describe whole processor state */
typedef struct sigcontext   mcontext_t;
/** Userlevel context */
typedef struct attr_packed ucontext {
	unsigned long uc_flags;
	struct ucontext* uc_link;
	stack_t uc_stack;
	mcontext_t uc_mcontext;
	sigset_t uc_sigmask;
	unsigned long align8 uc_regspace[128];
} ucontext_t;
#   define __ARMSIGCTX_H   (1)
union sigcontext {
	struct sigcontext_v21 {
		unsigned long trap_no, error_code, oldmask;
		unsigned long arm_r0, arm_r1, arm_r2, arm_r3, arm_r4, arm_r5;
		unsigned long arm_r6, arm_r7, arm_r8, arm_r9, arm_r10;
		unsigned long arm_fp, arm_ip, arm_sp, arm_lr, arm_pc, arm_cpsr;
		unsigned long fault_address;
	} v21;
	struct sigcontext_v20 {
		unsigned long magic;
		struct pt_regs reg;
		unsigned long trap_no, error_code, oldmask;
	} v20;
};
#   define SIGCONTEXT_2_0_MAGIC   0x4b534154
#   define SIGCONTEXT   int _a2, int _a3, int _a4, union sigcontext
#   define sigcontext   SIGCONTEXT
#   define SIGCONTEXT_EXTRA_ARGS _a2, _a3, _a4,
#   define ADVANCE_STACK_FRAME(frm)   ((struct layout*)frm - 1)
#   define GET_PC(_ctx)   ((void*)_ctx.v21.arm_pc)
#   define GET_FRAME(_ctx)   ADVANCE_STACK_FRAME((void*)_ctx.v21.arm_fp)
#   define GET_STACK(_ctx)   ((void*)_ctx.v21.arm_sp)
#   define CALL_SIGHANDLER(handler, signo, _ctx)   (handler)((signo), SIGCONTEXT_EXTRA_ARGS(_ctx))
#elif defined(ARCHALPHA)
/** A machine context is exactly a sigcontext */
typedef struct sigcontext   mcontext_t;
/** Userlevel context */
typedef struct attr_packed ucontext {
	unsigned long uc_flags;
	struct ucontext* uc_link;
	unsigned long __uc_osf_sigmask;
	stack_t uc_stack;
	mcontext_t uc_mcontext;
	sigset_t uc_sigmask;
} ucontext_t;
#   define SIGCONTEXT   int _code, struct sigcontext*
#   define SIGCONTEXT_EXTRA_ARGS   _code,
#   define GET_PC(_ctx)   ((void*)(_ctx)->sc_pc)
#   define GET_FRAME(_ctx)   ((void*)(_ctx)->sc_regs[15])
#   define GET_STACK(_ctx)   ((void*)(_ctx)->sc_regs[30])
#   define CALL_SIGHANDLER(handler, signo, _ctx)   (handler)((signo), SIGCONTEXT_EXTRA_ARGS(_ctx))
#elif defined(ARCHX86)
#   if IS_WORDSIZE_64
/** Context to describe whole processor state */
typedef struct __mcontext {
	gregset_t gregs;
	fpregset_t fpregs;
	unsigned long __reserved1[8];
} mcontext_t;
/** Userlevel context */
typedef struct attr_packed ucontext {
	unsigned long uc_flags;
	struct ucontext* uc_link;
	stack_t uc_stack;
	mcontext_t uc_mcontext;
	sigset_t uc_sigmask;
	struct _libc_fpstate __fpregs_mem;
} ucontext_t;
struct sigcontext {
	unsigned long r8, r9, r10, r11, r12, r13, r14, r15;
	unsigned long rdi, rsi, rbp, rbx, rdx, rax, rcx, rsp, rip;
	unsigned long eflags;
	unsigned short cs, gs, fs, __pad0;
	unsigned long err, trapno, oldmask, cr2;
	struct _fpstate* fpstate;
	unsigned long __reserved1[8];
};
#      define SIGCONTEXT   siginfo_t* _si, struct ucontext*
#      define SIGCONTEXT_EXTRA_ARGS   _si,
#      define GET_PC(_ctx)   ((void*)(_ctx)->uc_mcontext.gregs[REG_RIP])
#      define GET_FRAME(_ctx)   ((void*)(_ctx)->uc_mcontext.gregs[REG_RBP])
#      define GET_STACK(_ctx)   ((void*)(_ctx)->uc_mcontext.gregs[REG_RSP])
#      define CALL_SIGHANDLER(handler, signo, _ctx)   (handler)((signo), SIGCONTEXT_EXTRA_ARGS(_ctx))
#   else  // IS_WORDSIZE_32
/** Context to describe whole processor state */
typedef struct __mcontext {
	gregset_t gregs;
	fpregset_t fpregs;
	unsigned long oldmask, cr2;
} mcontext_t;
/** Userlevel context */
typedef struct attr_packed ucontext {
	unsigned long uc_flags;
	struct ucontext* uc_link;
	stack_t uc_stack;
	mcontext_t uc_mcontext;
	sigset_t uc_sigmask;
	struct _libc_fpstate __fpregs_mem;
} ucontext_t;
struct sigcontext {
	unsigned short gs, __gsh, fs, __fsh;
	unsigned short es, __esh, ds, __dsh;
	unsigned long edi, esi, ebp, esp, ebx, edx, ecx, eax;
	unsigned long trapno, err, eip;
	unsigned short cs, __csh;
	unsigned long eflags, esp_at_signal;
	unsigned short ss, __ssh;
	struct _fpstate* fpstate;
	unsigned long oldmask, cr2;
};
#      define SIGCONTEXT   struct sigcontext
#      define SIGCONTEXT_EXTRA_ARGS
#      define GET_PC(_ctx)   ((void*)_ctx.eip)
#      define GET_FRAME(_ctx)   ((void*)_ctx.ebp)
#      define GET_STACK(_ctx)   ((void*)_ctx.esp_at_signal)
#      define CALL_SIGHANDLER(handler, signo, _ctx)   do { int __tmp1, __tmp2, __tmp3, __tmp4; asm volatile ( \
	"movlt %%esp, %%edi;" \
	"andlt $-16, %%esp;" \
	"sublt %8, %%esp;" \
	"movlt %%edi, %c8-4(%%esp);" \
	"movlt %1, 0(%%esp);" \
	"lealt4 (%%esp), %%edi;" \
	"cld;" \
	"reptmovsl;" \
	"callt *%0;" \
	"cld;" \
	"movlt %9, %%ecx;" \
	"sublt %%edi, %%esi;" \
	"lealt4 (%%esp,%%esi,1), %%edi;" \
	"lealt4 (%%esp), %%esi;" \
	"reptmovsl;" \
	"movlt %c8-4(%%esp), %%esp;" \
	: "=a"(__tmp1), "=d"(__tmp2), "=S"(__tmp3), "=c"(__tmp4) \
	: "0"(handler), "1"(signo), "2"(&_ctx), "3"(sizeof(struct sigcontext) >> 2), "n"((sizeof(struct sigcontext) + 19) & (~15)), "i"(sizeof(struct sigcontext) >> 2) \
	: "cc", "edi"); \
} while (0x0)
#   endif  // WORDSIZE
#elif defined(ARCHMIPS)
#   ifdef ARCHMIPS32
/** Context to describe whole processor state */
typedef struct mcontext {
	unsigned int regmask, status;
	greg_t pc;
	gregset_t gregs;
	fpregset_t fpregs;
	unsigned int fp_owned, fpc_csr, fpc_eir, used_math, dsp;
	greg_t mdhi, mdlo;
	unsigned long hi1, lo1, hi2, lo2, hi3, lo3;
} mcontext_t;
struct sigcontext {
	unsigned int sc_regmask, sc_status;
	unsigned long long sc_pc;
	unsigned long long sc_regs[32];
	unsigned long long sc_fpregs[32];
	unsigned int sc_ownedfp, sc_fpc_csr, sc_fpc_eir, sc_used_math, sc_dsp;
	unsigned long long sc_mdhi, sc_mdlo;
	unsigned long sc_hi1, sc_lo1, sc_hi2, sc_lo2, sc_hi3, sc_lo3;
};
#      define SIGCONTEXT   unsigned long _code, struct sigcontext*
#      define SIGCONTEXT_EXTRA_ARGS   _code,
#      define GET_PC(_ctx)   ((void*)_ctx->sc_pc)
#      define GET_FRAME(_ctx)   ((void*)_ctx->sc_regs[30])
#      define GET_STACK(_ctx)   ((void*)_ctx->sc_regs[29])
#      define CALL_SIGHANDLER(handler, signo, _ctx)   (handler)((signo), SIGCONTEXT_EXTRA_ARGS(_ctx))
#   else
/** Context to describe whole processor state */
typedef struct mcontext {
	gregset_t gregs;
	fpregset_t fpregs;
	greg_t mdhi, hi1, hi2, hi3, mdlo, lo1, lo2, lo3, pc;
	unsigned int fpc_csr, used_math, dsp, reserved;
} mcontext_t;
struct sigcontext {
	unsigned long long sc_regs[32];
	unsigned long long sc_fpregs[32];
	unsigned long long sc_mdhi;
	unsigned long long sc_hi1, sc_hi2, sc_hi3, sc_mdlo;
	unsigned long long sc_lo1, sc_lo2, sc_lo3, sc_pc;
	unsigned int sc_fpc_csr, sc_used_math, sc_dsp, sc_reserved;
};
#      define SIGCONTEXT   unsigned long _code, ucontext_t*
#      define SIGCONTEXT_EXTRA_ARGS   _code,
#      define GET_PC(_ctx)   ((void*)_ctx->uc_mcontext.pc)
#      define GET_FRAME(_ctx)   ((void*)_ctx->uc_mcontext.gregs[30])
#      define GET_STACK(_ctx)   ((void*)_ctx->uc_mcontext.gregs[29])
#      define CALL_SIGHANDLER(handler, signo, _ctx)   (handler)((signo), SIGCONTEXT_EXTRA_ARGS(_ctx))
#   endif
/** Userlevel context */
typedef struct attr_packed ucontext {
	unsigned long uc_flags;
	struct ucontext* uc_link;
	stack_t uc_stack;
	mcontext_t uc_mcontext;
	sigset_t uc_sigmask;
} ucontext_t;
#elif defined(ARCHBLACKFIN)
/** Context to describe whole processor state */
typedef struct mcontext { gregset_t gregs; }   mcontext_t;
/** Userlevel context */
typedef struct attr_packed ucontext {
	unsigned long uc_flags;
	struct ucontext* uc_link;
	stack_t uc_stack;
	mcontext_t uc_mcontext;
	sigset_t uc_sigmask;
} ucontext_t;
#   define SIGCONTEXT   int _code, struct sigcontext*
#   define SIGCONTEXT_EXTRA_ARGS   _code,
#   define GET_PC(_ctx)   ((void*)(_ctx)->sc_pc)
#   define GET_FRAME(_ctx)   ((void*)__builtin_frame_address(1))
#   define GET_STACK(_ctx)   ((void*)(_ctx)->sc_usp)
#   define CALL_SIGHANDLER(handler, signo, _ctx)   (handler)((signo), SIGCONTEXT_EXTRA_ARGS(_ctx))
#elif defined(ARCHMICROBLAZE)
typedef struct sigcontext   mcontext_t;
/** Userlevel context */
typedef struct attr_packed ucontext {
	unsigned long uc_flags;
	struct ucontext* uc_link;
	stack_t uc_stack;
	mcontext_t uc_mcontext;
	sigset_t uc_sigmask;
} ucontext_t;
#elif defined(ARCHPOWERPC)
#   if IS_WORDSIZE_32
/** Context to describe whole processor state */
typedef struct mcontext {
	gregset_t gregs;
	fpregset_t fpregs;
	vrregset_t align16 vrregs;
} mcontext_t;
#   else  // POWERPC64
typedef struct mcontext {
	unsigned long __unused[4];
	int signal, __pad0;
	unsigned long handler, oldmask;
	struct pt_regs* regs;
	gregset_t gp_regs;
	fpregset_t fp_regs;
	vrregset_t* v_regs;
	long vmx_reserve[NVRREG + NVRREG + 1];
} mcontext_t;
#   endif
/** Userlevel context */
typedef struct attr_packed ucontext {
	unsigned long uc_flags;
	struct ucontext* uc_link;
	stack_t uc_stack;
#   if IS_WORDSIZE_32
	int uc_pad[7];
	union uc_regs_ptr {
		struct pt_regs* regs;
		mcontext_t* uc_regs;
	} uc_mcontext;
	sigset_t uc_sigmask;
	char uc_reg_space[sizeof(mcontext_t) + 12];
#   else  // 64-bit
	sigset_t uc_sigmask;
	mcontext_t uc_mcontext;
#   endif
} ucontext_t;
#   define SIGCONTEXT   struct sigcontext*
#   define SIGCONTEXT_EXTRA_ARGS
#   define GET_PC(_ctx)   ((void*)((_ctx)->regs->nip))
#   define GET_FRAME(_ctx)   (*(void**)((_ctx)->regs->gpr[1]))
#   define GET_STACK(_ctx)   ((void*)((_ctx)->regs->gpr[1]))
#   define CALL_SIGHANDLER(handler, signo, _ctx)   (handler)((signo), SIGCONTEXT_EXTRA_ARGS(_ctx))
#elif defined(ARCHSPARC)
#   if IS_WORDSIZE_64
#      define MC_MAXFPQ   16
struct mc_fq {
	unsigned long* mcfq_addr;
	unsigned int mcfq_insn;
};
struct mc_fpu {
	union __union_mc_fpu {
		unsigned int sregs[32];
		unsigned long dregs[32];
		long double qregs[16];
	} mcfpu_fregs;
	unsigned long mcfpu_fsr;
	unsigned long mcfpu_fprs;
	unsigned long mcfpu_gsr;
	struct mc_fq* mcfpu_fq;
	unsigned char mcfpu_qcnt;
	unsigned char mcfpu_qentsz;
	unsigned char mcfpu_enab;
};
typedef struct mc_fpu   mc_fpu_t;
typedef struct mcontext {
	mc_gregset_t mc_gregs;
	mc_greg_t mc_fp;
	mc_greg_t mc_i7;
	mc_fpu_t mc_fpregs;
} mcontext_t;
typedef struct attr_packed ucontext {
	struct ucontext* uc_link;
	unsigned long uc_flags;
	unsigned long __uc_sigmask;
	mcontext_t uc_mcontext;
	stack_t uc_stack;
	sigset_t uc_sigmask;
} ucontext_t;
#   else  // IS_WORDSIZE_32
/** The following structure is for associating extra register state with the ucontext structure and is kept within the uc_mcontext filler area */
typedef struct _xrs {
	unsigned int xrs_id;
	void* xrs_ptr;
} xrs_t;
typedef struct mcontext {
	gregset_t gregs;
	gwindows_t* gwins;
	fpregset_t fpregs;
	xrs_t xrs;
	long filler[19];
} mcontext_t;
/** Userlevel context */
typedef struct attr_packed ucontext {
	unsigned long uc_flags;
	struct ucontext* uc_link;
	sigset_t uc_sigmask;
	stack_t uc_stack;
	mcontext_t uc_mcontext;
} ucontext_t;
/** The string "xrs" */
#      define XRS_ID   0x78727300
#   endif  // WORDSIZE
/** Max windows in SPARC */
#   define SPARC_MAXREGWINDOW   31
struct rwindow { greg_t rw_local[8], rw_in[8]; };
/** frame pointer */
#   define rw_fp   rw_in[6]
/** return address */
#   define rw_rtn  rw_in[7]
typedef struct gwindows {
	int wbcnt;
	int* spbuf[SPARC_MAXREGWINDOW];
	struct rwindow wbuf[SPARC_MAXREGWINDOW];
} gwindows_t;
struct sigcontext {
	struct sigcontext_si_regs {
		unsigned int psr, pc, npc, y;
		unsigned int u_regs[16];
	} si_regs;
	int si_mask;
};
#   define SIGCONTEXT   struct sigcontext*
#   define SIGCONTEXT_EXTRA_ARGS
#   define GET_PC(_ctx)   ((void*)((_ctx)->si_regs.pc))
#   define ADVANCE_STACK_FRAME(_next)   ((void*)(((unsigned int*)(_next)) + 14))
#   define GET_STACK(__ctx)   ((void*)(_ctx)->si_regs.u_regs[14])
#   define GET_FRAME(__ctx)   ADVANCE_STACK_FRAME(GET_STACK(_ctx))
#   define CALL_SIGHANDLER(handler, signo, _ctx)   (handler)((signo), SIGCONTEXT_EXTRA_ARGS(_ctx))
#elif defined(ARCHITANIUM)
struct sigcontext {
	unsigned long sc_flags;  // Manifest constants
	unsigned long sc_nat;  // bit i == 1 if scratch reg gr[i] is a NaT
	stack_t sc_stack;  // previously active stack
	unsigned long sc_ip;  // instruction pointer
	unsigned long sc_cfm;  // current frame marker
	unsigned long sc_um;  // user mask bits
	unsigned long sc_ar_rsc;  // register stack configuration register
	unsigned long sc_ar_bsp;  // backing store pointer
	unsigned long sc_ar_rnat;  // RSE NaT collection register
	unsigned long sc_ar_ccv;  // compare & exchange compare value register
	unsigned long sc_ar_unat;  // ar.unat of interrupted context
	unsigned long sc_ar_fpsr;  // floating-point status register
	unsigned long sc_ar_pfs;  // previous function state
	unsigned long sc_ar_lc;  // loop count register
	unsigned long sc_pr;  // predicate registers
	unsigned long sc_br[8];  // branch registers
	unsigned long sc_gr[32];  // general registers (static partition)
	struct ia64_fpreg sc_fr[128];  // floating-point registers
	unsigned long sc_rbs_base;  // NULL or new base of sighandler's rbs
	unsigned long sc_loadrs;  // see description above
	unsigned long sc_ar25;  // cmp8xchg16 uses this
	unsigned long sc_ar26;  // rsvd for scratch use
	unsigned long sc_rsvd[12];  // reserved for future use
	unsigned long sc_mask;  // signal mask to restore after handler returns
};
// sc_flag bit definitions (manifest constants)
#   define IA64_SC_FLAG_ONSTACK_BIT   0  // Is handler running on signal stack?
#   define IA64_SC_FLAG_IN_SYSCALL_BIT   1  // did signal interrupt a syscall?
#   define IA64_SC_FLAG_FPH_VALID_BIT   2  // is state in f[32]-f[127] valid?
#   define IA64_SC_FLAG_ONSTACK   1
#   define IA64_SC_FLAG_IN_SYSCALL   2
#   define IA64_SC_FLAG_FPH_VALID   4
#elif defined(ARCHXTENSA)
struct sigcontext {
	unsigned long sc_pc, sc_ps, sc_lbeg, sc_lend, sc_lcount, sc_sar, sc_acclo, sc_acchi;
	unsigned long sc_a[16];
	void* sc_xtregs;
};
#   define SIGCONTEXT   unsigned long _info, ucontext_t*
#   define SIGCONTEXT_EXTRA_ARGS   _info,
#   define GET_PC(_ctx)   ((void*)(_ctx->uc_mcontext.sc_pc & 0x3fffffff))
#   define GET_FRAME(_ctx)   ((void*)_ctx->uc_mcontext.sc_a[1])
#   define GET_STACK(_ctx)   ((void*)_ctx->uc_mcontext.sc_a[1])
#   define CALL_SIGHANDLER(handler, signo, _ctx)   (handler)((signo), SIGCONTEXT_EXTRA_ARGS(_ctx))
#elif defined(ARCHSUPERH)
#   define SIGCONTEXT   int _a2, int _a3, int _a4, struct sigcontext
#   define SIGCONTEXT_EXTRA_ARGS   _a2, _a3, _a4,
#   define GET_PC(_ctx)   ((void*)_ctx.sc_pc)
#   define GET_FRAME(_ctx)   ((void*)_ctx.sc_regs[14])
#   define GET_STACK(_ctx)   ((void*)_ctx.sc_regs[15])
#   define CALL_SIGHANDLER(handler, signo, _ctx)   (handler)((signo), SIGCONTEXT_EXTRA_ARGS(_ctx))
#else
#   error   "Add sigcontext and ucontext support for the target system."
#endif  // ARCH


#ifndef sigcontext_struct
#   define sigcontext_struct    sigcontext
#endif


#endif  // BITS_SIGCONTEXT_H


/* DEV_T ACCESS (<sys/sysmacros.h>) */


#if (!(defined(SYS_SYSMACROS_H) || defined(_SYS_SYSMACROS_H) || defined(_SYS_SYSMACROS_H_)))
#define SYS_SYSMACROS_H   (1)
#define _SYS_SYSMACROS_H   (1)
#define _SYS_SYSMACROS_H_   (1)


#define gnu_dev_major(__dev)   ((((uint64_t)__dev) >> 8) & 0xfffU) | ((uint32_t)(((uint64_t)__dev) >> 0x20U) & 0xfffff000U);

#define gnu_dev_minor(__dev)   ((((uint64_t)__dev) & 0xffU) | ((uint32_t)((uint64_t)__dev) >> 0xcU) & 0xffffff00U);

#define gnu_dev_makedev(__major, __minor)   ((((uint32_t)__minor) & 0xffU) | ((((uint32_t)__major) & 0xfffU) << 8) | (((uint64_t)(((uint32_t)__minor) & 0xffffff00U)) << 12) | (((uint64_t)(((uint32_t)__major) & 0xfffff000U)) << 0x20U));

#if (defined(OSNETBSD) || defined(OSMINIX))
#   define major(x)   ((int32_t)((((x) & 0xfff00U) >> 8)))
#   define minor(x)   ((int32_t)((((x) & 0xfff00000U) >> 0xc) | (((x) & 0xffU) >> 0)))
#   define makedev(x, y)   ((dev_t)((((x) << 8) & 0xfff00)U | (((y) << 0xcU) & 0xfff00000U) | ((y) & 0xffU)))
#elif defined(OSANDROID)
#   define major(x)   (((x) >> 8) & 0xfffU)
#   define minor(x)   (((x) & 0xffU) | (((x) >> 12) & 0xfff00U))
#   define makedev(x, y)   ((((x) & 0xfffU) << 8) | ((y) & 0xff)U | (((y) & 0xfff00U) << 12))
#elif defined(OSSUN)
/** Major part of a device */
#   define major(x)   ((int)(((uint32_t)(x) >> 8) & 0377U))
/** Minor part of a device */
#   define minor(x)   ((int)((x) & 0377U))
/** Make a device number */
#   define makedev(x, y)   ((dev_t)(((x) << 8) | (y)))
/** Number of SVR4 major device bits */
#   define L_BITSMAJOR   14
/** Number of SVR4 minor device bits */
#   define L_BITSMINOR   18
/** MAX minor for 3b2 software drivers; For 3b2 hardware devices the minor is restricted to 256 (0-255) */
#   define L_MAXMIN   0x3ffffU
/** Number of SunOS 4.x minor device bits */
#   define O_BITSMINOR   8
/** SunOS 4.x max major value */
#   define O_MAXMAJ   0xffU
/** SunOS 4.x max minor value */
#   define O_MAXMIN   0xffU
/** Convert to old dev format */
#   define cmpdev(x)   (unsigned long)((((x) >> L_BITSMINOR) > O_MAXMAJ || ((x) & L_MAXMIN) > O_MAXMIN) ? NODEV : ((((x) >> L_BITSMINOR) << O_BITSMINOR) | ((x) & O_MAXMIN)))
#else
#   define major(x)   gnu_dev_major(x)
#   define minor(x)   gnu_dev_minor(x)
#   define makedev(x, y)   gnu_dev_makedev(x, y)
#endif


#endif  // SYS_SYSMACROS_H


/* FILE DESCRIPTOR MACROS */


#if (!(defined(FDS_MACROS_H) || defined(_FDS_MACROS_H) || defined(_FDS_MACROS_H_)))
#define FDS_MACROS_H   (1)
#define _FDS_MACROS_H   (1)
#define _FDS_MACROS_H_   (1)


#if (_FORTIFY_SOURCE > 0)
#   define FD_ELT(d)   __extension__ ({ long __d = (d); (__builtin_constant_p(__d) ? (((0 <= __d) && (__d < BITS_PER_FD_SET)) ? (__d / BITS_PER_FD_MASK) : __fdelt_chk(__d)) : __fdelt_chk(__d)); })
#else  // !(_FORTIFY_SOURCE > 0)
#   define FD_ELT(d)   ((d) / BITS_PER_FD_MASK)
#endif  // (_FORTIFY_SOURCE > 0)
#define FD_MASK(d)   ((fd_mask)(1UL << ((d) % BITS_PER_FD_MASK)))
#ifdef __USE_XOPEN
#   define FDS_BITS(set)   ((set)->fds_bits)
#else
#   define FDS_BITS(set)   ((set)->__fds_bits)
#endif
#define FDS_LONGS(nr)   (((nr) + BITS_PER_FD_MASK - 1) / BITS_PER_FD_MASK)
#define FDS_BYTES(nr)   (FDS_LONGS(nr) * SIZEOF_LONG)
// Access macros for `fd_set`
#ifdef ARCHX86_32  // FD*
#   define FD_SET(fd, fdsp)   do { asm volatile ("btsl %1, %0;" : "=m"(FDS_BITS(fdsp)[FD_ELT(fd)]) : "r"(((int)(fd)) % BITS_PER_FD_MASK) : "cc", "memory") } while (0x0)
#   define FD_CLR(fd, fdsp)   do { asm volatile ("btrl %1, %0;" : "=m"(FDS_BITS(fdsp)[FD_ELT(fd)]) : "r"(((int)(fd)) % BITS_PER_FD_MASK) : "cc", "memory") } while (0x0)
#   define FD_ISSET(fd, fdsp)   do { register char __result; asm volatile ("btl %1, %2;" "setcb %b0;" : "=q"(__result) : "r"(((int)(fd)) % BITS_PER_FD_MASK), "m"(FDS_BITS(fdsp)[FD_ELT(fd)]) : "cc"); __result; } while (0x0)
#else
#   define FD_SET(d, s)   ((void)(FDS_BITS(s)[FD_ELT(d)] |= (FD_MASK(d))))
#   define FD_CLR(d, s)   ((void)(FDS_BITS(s)[FD_ELT(d)] &= (~(FD_MASK(d)))))
#   define FD_ISSET(d, s)   ((FDS_BITS(s)[FD_ELT(d)] & FD_MASK(d)) != 0)
#endif  // FD*
#ifdef ARCHX86_64  // FD_ZERO
/** Small `memset` substitute */
#   define FD_ZERO(fdsp)   do { int __d0, __d1; asm volatile ("cld;" "rep;" FD_ZERO_STOS : "=c"(__d0), "=D"(__d1) : "a"(0), "0"(FD_SETSIZE / SIZEOF_FD_MASK), "1"(&(FDS_BITS(fdsp))[0]) : "memory"); } while (0x0)
#elif defined(ARCHX86_32)
/** Small `memset` substitute */
#   define FD_ZERO(fdsp)   do { int __d0, __d1; asm volatile ("cld;" "rep;" "stosl;" : "=c"(__d0), "=D"(__d1) : "a"(0), "0"(FD_SETSIZE / SIZEOF_FD_MASK), "1"(&(FDS_BITS(fdsp))[0]) : "memory"); } while (0x0)
#else  // Not x86
/** Small `memset` substitute */
#   define FD_ZERO(s)   do { unsigned int __i; fd_set* __arr = (s); for (__i = 0; __i < FD_SETSIZE / SIZEOF_FD_MASK; ++__i) FDS_BITS(__arr)[__i] = 0; } while (0x0)
#endif  // FD_ZERO


#endif


/* ARM EABI & C6X UNWINDERS (<unwind-arm-common.h>) */


#if (defined(ARCHARM) && (!defined(UNWIND_ARM_COMMON_H)))
#define UNWIND_ARM_COMMON_H   (1)
#define _UNWIND_ARM_COMMON_H   (1)
#define _UNWIND_ARM_COMMON_H_   (1)


#define __ARM_EABI_UNWINDER__   1
#define _UA_SEARCH_PHASE   1
#define _UA_CLEANUP_PHASE   2
#define _UA_HANDLER_FRAME   4
#define _UA_FORCE_UNWIND   8
#define _UA_END_OF_STACK   16
#define _URC_NO_REASON   _URC_OK
typedef PTRtype   _Unwind_Ptr;
typedef _Unwind_Ptr   _Unwind_Internal_Ptr;
typedef _Unwind_Word   _uw;
typedef _uw   _Unwind_EHT_Header;
typedef UDItype   _uw64;
typedef UHItype   _uw16;
typedef UQItype   _uw8;
typedef int   _Unwind_Action;
typedef long   _sleb128_t;
typedef unsigned long   _uleb128_t;
typedef char   _Unwind_Exception_Class[8];

typedef enum Unwind_Reason_Code {
	_URC_OK = 0,
	_URC_FOREIGN_EXCEPTION_CAUGHT = 1,
	_URC_END_OF_STACK = 5,
	_URC_HANDLER_FOUND = 6,
	_URC_INSTALL_CONTEXT = 7,
	_URC_CONTINUE_UNWIND = 8,
	_URC_FAILURE = 9
} _Unwind_Reason_Code;

typedef enum _Unwind_State {
	_US_VIRTUAL_UNWIND_FRAME = 0,
	_US_UNWIND_FRAME_STARTING = 1,
	_US_UNWIND_FRAME_RESUME = 2,
	_US_ACTION_MASK = 3,
	_US_FORCE_UNWIND = 8,
	_US_END_OF_STACK = 16
} _Unwind_State;

/** Virtual Register Set*/
typedef enum _Unwind_VRS_RegClass {
	_UVRSC_CORE = 0,  // Integer register
	_UVRSC_VFP = 1,  // vfp
	_UVRSC_FPA = 2,  // fpa
	_UVRSC_WMMXD = 3,  // Intel WMMX data register
	_UVRSC_WMMXC = 4  // Intel WMMX control register
} _Unwind_VRS_RegClass;

typedef enum _Unwind_VRS_DataRepresentation {
	_UVRSD_UINT32 = 0,
	_UVRSD_VFPX = 1,
	_UVRSD_FPAX = 2,
	_UVRSD_UINT64 = 3,
	_UVRSD_FLOAT = 4,
	_UVRSD_DOUBLE = 5
} _Unwind_VRS_DataRepresentation;

typedef enum _Unwind_VRS_Result {
	_UVRSR_OK = 0,
	_UVRSR_NOT_IMPLEMENTED = 1,
	_UVRSR_FAILED = 2
} _Unwind_VRS_Result;

typedef struct _Unwind_Control_Block {
	char exception_class[8];
	void (*exception_cleanup)(_Unwind_Reason_Code, _Unwind_Control_Block*);
	struct unwinder_cache_s {  // Unwinder cache; private fields for the unwinder's use
		_uw reserved1;  // Forced unwind stop fn, 0 if not forced
		_uw reserved2;  // Personality routine address
		_uw reserved3;  // Saved callsite address
		_uw reserved4;  // Forced unwind stop arg
		_uw reserved5;
	} unwinder_cache;
	struct barrier_cache_s {  // Propagation barrier cache (valid after phase 1)
		_uw sp; _uw bitpattern[5];
	} barrier_cache;
	struct cleanup_cache_s { _uw bitpattern[4]; } cleanup_cache;  // Cleanup cache (preserved over cleanup)
	struct pr_cache_s {  // Pr cache (for pr's benefit)
		_uw fnstart;  // Function start address
		_Unwind_EHT_Header* ehtp;  // Pointer to EHT entry header word
		_uw additional;  // Additional data
		_uw reserved1;
	} pr_cache;
	long long padding:0;  // Force alignment to 8-byte boundary
} _Unwind_Control_Block;
#define _Unwind_Exception   _Unwind_Control_Block

/** Frame unwinding state */
typedef struct __gnu_unwind_state {
	_uw data;  // The current word (bytes packed msb first)
	_uw* next;  // Pointer to the next word of data
	_uw8 bytes_left;  // The number of bytes left in this word
	_uw8 words_left;  // The number of words pointed to by ptr
} __gnu_unwind_state;


#endif  // UNWIND_ARM_COMMON_H


/* AVR ARCHITECTURE & DEVICE INFORMATION DATATYPES (<avr-arch.h>) */


#if (defined(ARCHAVR) && SUPPORTS_STDFIX && (!defined(AVR_ARCH_H)))
#define AVR_ARCH_H   (1)
#define _AVR_ARCH_H   (1)
#define _AVR_ARCH_H_   (1)


#define AVR_MMCU_DEFAULT   "avr2"

/** Indices for the avr_arch_types[] table */
typedef enum avr_arch_id {
	ARCH_UNKNOWN, ARCH_AVR1,
	ARCH_AVR2, ARCH_AVR25,
	ARCH_AVR3, ARCH_AVR31,
	ARCH_AVR35, ARCH_AVR4,
	ARCH_AVR5, ARCH_AVR51,
	ARCH_AVR6, ARCH_AVRTINY,
	ARCH_AVRXMEGA2, ARCH_AVRXMEGA4,
	ARCH_AVRXMEGA5, ARCH_AVRXMEGA6, ARCH_AVRXMEGA7
} avr_arch_id_t;

/** Architecture-specific properties */
typedef struct avr_arch {
	int asm_only;
	// Core have 'MUL*' instructions
	int have_mul;
	// Core have 'CALL' and 'JMP' instructions
	int have_jmp_call;
	// Core have 'MOVW' and 'LPM Rx,Z' instructions
	int have_movw_lpmx;
	// Core have 'ELPM' instructions
	int have_elpm;
	// Core have 'ELPM Rx,Z' instructions
	int have_elpmx;
	// Core have 'EICALL' and 'EIJMP' instructions
	int have_eijmp_eicall;
	// This is an XMEGA core
	int xmega_p;
	// This core has the RAMPD special function register and thus also the RAMPX, RAMPY, and RAMPZ registers
	int have_rampd;
	// This is a TINY core
	int tiny_p;
	// Default start of data section address for architecture
	int default_data_section_start;
	// Offset between SFR address and RAM address: SFR-address = RAM-address - sfr_offset
	int sfr_offset;
	// Architecture id to built-in define __AVR_ARCH__ (NULL -> no macro)
	const char* const macro;
	// Architecture name
	const char* const name;
} avr_arch_t;

/** Device-specific properties */
typedef struct avr_mcu {
	// Device name
	const char* const name;
	// Index in avr_arch_types[]
	enum avr_arch_id arch_id;
	// Device specific feature
	int dev_attribute;
	// Must lie outside user's namespace; NULL == no macro
	const char* const macro;
	// Start of data section
	int data_section_start;
	// Start of text section
	int text_section_start;
	// Number of 64k segments in the flash
	int n_flash;
} avr_mcu_t;

/** AVR device specific features */
enum avr_device_specific_features {
	AVR_ISA_NONE,
	AVR_ISA_RMW = 1,  // Device has RMW instructions
	AVR_SHORT_SP = 2,  // Stack Pointer has 8 bits width
	AVR_ERRATA_SKIP = 4  // Device has a core erratum
};

/** Map architecture to its texinfo string */
typedef struct avr_arch_info {
	enum avr_arch_id arch_id;  // Architecture ID
	const char* texinfo;  // Textinfo source to describe the archtiecture
} avr_arch_info_t;

/** Preprocessor macros to define depending on MCU type */
static const UNUSED avr_arch_t avr_arch_types[];
static const UNUSED avr_arch_t* avr_arch;
static const UNUSED avr_mcu_t avr_mcu_types[];


#endif  // AVR_ARCH_H


/* LOW-LEVEL IO (<io.h>) */


#if (!(defined(IO_H) || defined(_IO_H) || defined(_IO_H_) || defined(_SYS_IO_H) || defined(_SYS_IO_H_)))
#define IO_H   (1)
#define _IO_H   (1)
#define _IO_H_   (1)
#define SYS_IO_H   (1)
#define _SYS_IO_H   (1)
#define _SYS_IO_H_   (1)


#define __phys_to_pfn(paddr)   ((paddr) >> PAGE_SHIFT)
#define phys_to_pfn(paddr)   ((paddr) >> PAGE_SHIFT)
#define __pfn_to_phys(pfn)   ((pfn) << PAGE_SHIFT)
#define pfn_to_phys(pfn)   ((pfn) << PAGE_SHIFT)
#define pages_to_mb(x)   ((x) >> (20 - PAGE_SHIFT))

typedef struct attr_packed pgp_memory_t {
	uint8_t* buf;
	size_t length, allocated;
	unsigned int mmapped;
} pgp_memory_t;


#ifdef ARCHX86


LIB_FUNC unsigned char inb(const unsigned short port) {
	unsigned char _v;
	asm volatile ("inb %w1, %0;" : "=a"(_v) : "Nd"(port));
	return _v;
}


LIB_FUNC unsigned char inb_p(const unsigned short port) {
	unsigned char _v;
	asm volatile ("inb %w1, %0;" "outb %%al, $0x80;" : "=a"(_v) : "Nd"(port));
	return _v;
}


LIB_FUNC unsigned short inw(const unsigned short port) {
	unsigned short _v;
	asm volatile ("inw %w1, %0;" : "=a"(_v) : "Nd"(port));
	return _v;
}


LIB_FUNC unsigned short inw_p(const unsigned short port) {
	unsigned short _v;
	asm volatile ("inw %w1, %0;" "outb %%al, $0x80;" : "=a"(_v) : "Nd"(port));
	return _v;
}


LIB_FUNC unsigned int inl(const unsigned short port) {
	unsigned int _v;
	asm volatile ("inl %w1, %0;" : "=a"(_v) : "Nd"(port));
	return _v;
}


LIB_FUNC unsigned int inl_p(const unsigned short port) {
	unsigned int _v;
	asm volatile ("inl %w1, %0;" "outb %%al, $0x80;" : "=a"(_v) : "Nd"(port));
	return _v;
}


LIB_FUNC void outb(const unsigned char value, const unsigned short port) {
	asm volatile ("outb %b0, %w1;" : : "a"(value), "Nd"(port));
}


LIB_FUNC void outb_p(const unsigned char value, const unsigned short port) {
	asm volatile ("outb %b0, %w1;" "outb %%al, $0x80;" : : "a"(value), "Nd"(port));
}


LIB_FUNC void outw(const unsigned short value, const unsigned short port) {
	asm volatile ("outw %w0, %w1;" : : "a"(value), "Nd"(port));
}


LIB_FUNC void outw_p(const unsigned short value, const unsigned short port) {
	asm volatile ("outw %w0, %w1;" "outb %%al, $0x80;" : : "a"(value), "Nd"(port));
}


LIB_FUNC void outl(const unsigned int value, const unsigned short port) {
	asm volatile ("outl %0, %w1;" : : "a"(value), "Nd"(port));
}


LIB_FUNC void outl_p(const unsigned int value, const unsigned short port) {
	asm volatile ("outl %0, %w1;" "outb %%al, $0x80;" : : "a"(value), "Nd"(port));
}


LIB_FUNC void insb(const unsigned short port, const void* restrict addr, const unsigned long count) {
	register unsigned long _count = count;
	asm volatile ("cld;" "rep;" "insb;" : "=D"(addr), "=c"(_count) : "d"(port), "0"(addr), "1"(_count));
}


LIB_FUNC void insw(const unsigned short port, const void* restrict addr, const unsigned long count) {
	register unsigned long _count = count;
	asm volatile ("cld;" "rep;" "insw;" : "=D"(addr), "=c"(_count) : "d"(port), "0"(addr), "1"(_count));
}


LIB_FUNC void insl(const unsigned short port, const void* restrict addr, const unsigned long count) {
	register unsigned long _count = count;
	asm volatile ("cld;" "rep;" "insl;" : "=D"(addr), "=c"(_count) : "d"(port), "0"(addr), "1"(_count));
}


LIB_FUNC void outsb(const unsigned short port, const void* restrict addr, const unsigned long count) {
	register unsigned long _count = count;
	asm volatile ("cld;" "rep;" "outsb;" : "=S"(addr), "=c"(_count) : "d"(port), "0"(addr), "1"(_count));
}


LIB_FUNC void outsw(const unsigned short port, const void* restrict addr, const unsigned long count) {
	register unsigned long _count = count;
	asm volatile ("cld;" "rep;" "outsw;" : "=S"(addr), "=c"(_count) : "d"(port), "0"(addr), "1"(_count));
}


LIB_FUNC void outsl(const unsigned short port, const void* restrict addr, const unsigned long count) {
	register unsigned long _count = count;
	asm volatile ("cld;" "rep;" "outsl;" : "=S"(addr), "=c"(_count) : "d"(port), "0"(addr), "1"(_count));
}


#endif  // ARCH


#define readb(x)   (*(volatile unsigned char* restrict)(x))
#define readw(x)   (*(volatile unsigned short* restrict)(x))
#define read32(x)   (*(volatile uint32_t* restrict)(x))
#define read64(x)   (*(volatile uint64_t* restrict)(x))
#define cy_readb(port)   readb(port)
#define writeb(b, p)   (*(volatile unsigned char* restrict)(p) = (b))
#define bus_writeb(b, v, a)   writeb((v), (a))
#define writew(w, p)   (*(volatile unsigned short* restrict)(p) = (w))
#define write32(w, p)   (*(volatile uint32_t* restrict)(p) = (w))
#define write64(w, p)   (*(volatile uint64_t* restrict)(p) = (w))


LIB_FUNC uint8_t sw_readb(volatile void* restrict addr) {
	return *(volatile uint8_t* restrict)addr;
}


LIB_FUNC void sw_writeb(const uint8_t data, volatile void* restrict addr) {
	*(volatile uint8_t* restrict)addr = data;
}


LIB_FUNC uint16_t sw_readw(volatile void* restrict addr) {
	return *(volatile uint16_t* restrict)addr;
}


LIB_FUNC void sw_writew(const uint16_t data, volatile void* restrict addr) {
	*(volatile uint16_t* restrict)addr = data;
}


LIB_FUNC uint32_t sw_readl(volatile void* restrict addr) {
	return *(volatile uint32_t* restrict)addr;
}


LIB_FUNC void sw_writel(const uint32_t data, volatile void* restrict addr) {
	*(volatile uint32_t* restrict)addr = data;
}


#endif  // SYS_IO_H


/* PHYSICAL MEMORY LAYOUT (<memory.h>) */


#if (!(defined(_MEMORY_H) || defined(_MEMORY_H_) || defined(_S_I_MEMORY_H)))
#define _MEMORY_H   (1)
#define _MEMORY_H_   (1)
#define _S_I_MEMORY_H   (1)


#define TOTAL_PAGES   (MAX_ADDRESS / PAGE_SIZE)
#define MIOCRAMSIZE   _IOW('m', 3, uint32_t)


#if (defined(ARCHARM) && (!(defined(__ASM_ARCH_MEMORY_H) || defined(_ARM_MEMORY_H))))
#define _ARM_MEMORY_H  (1)
#define __ASM_ARCH_MEMORY_H  (1)


#define PHYS_MEM_BEGIN   (0x80000000)
#define PHYS_MEM_END   (0xbfffffff)


#endif  // ARM_MEMORY_H


#if (defined(OSDOS) && (!(defined(_DOS_MEMORY_H) || defined(_DOS_MEMORY_H_))))
#define _DOS_MEMORY_H   (1)
#define _DOS_MEMORY_H_   (1)


#define DOS_ALLOC_HIGH   (0x40)
#define DOS_ALLOC_HIGH_LOW   (0x80)

enum DOS_ALLOC_STRATEGY {
	DOS_ALLOC_FIRST_FIT, DOS_ALLOC_BEST_FIT, DOS_ALLOC_LAST_FIT
};


#endif  // DOS_MEMORY_H


#if (defined(OSLINUX) && (!(defined(_LINUX_MEMORY_H) || defined(_LINUX_MEMORY_H_))))
#define _LINUX_MEMORY_H   (1)
#define _LINUX_MEMORY_H_   (1)


typedef struct erase_info_t { unsigned long Offset, Size; }   erase_info_t;

#define MEMGETINFO   _IOR('M', 1, region_info_t)
#define MEMERASE   _IOW('M', 2, erase_info_t)


#endif  // LINUX_MEMORY_H


#endif  // MEMORY_H


/* LOW-LEVEL I/O HARDWARE DRIVERS; TR18015 & TR18037 (<iohw.h>, <iodriv_hw.h>, & <hardware.h>) */


#if (!(defined(IOHW_H) || defined(IOHW_H_) || defined(IODRIV_HW_H) || defined(IODRIV_HW_H_)))  // http://www.qnx.com/developers/docs/6.5.0_sp1/topic/com.qnx.doc.dinkum_en_cpp/iohw.html & http://developer.blackberry.com/playbook/native/reference/com.qnx.doc.dinkum/topic/c99/iohw.html & http://www.qnx.com/developers/docs/6.5.0_sp1/topic/com.qnx.doc.dinkum_en_cpp/hardware.html
#define IOHW_H   (1)
#define IOHW_H_   (1)
#define IODRIV_HW_H   (1)
#define IODRIV_HW_H_   (1)
#define __ASM_GENERIC_IRQ_H   (1)
#define _ASM_GENERIC_IRQ_H   (1)
#define _ASM_GENERIC_IRQ_H_   (1)


#ifdef ARCHX86
// PCI BIOS function numbering for conventional PCI BIOS systems
#   define PCIBIOS_PCI_FUNCTION_ID   0xb1XX
#   define PCIBIOS_PCI_BIOS_PRESENT   0xb101
#   define PCIBIOS_FIND_PCI_DEVICE   0xb102
#   define PCIBIOS_FIND_PCI_CLASS_CODE   0xb103
#   define PCIBIOS_GENERATE_SPECIAL_CYCLE   0xb106
#   define PCIBIOS_READ_CONFIG_BYTE   0xb108
#   define PCIBIOS_READ_CONFIG_WORD   0xb109
#   define PCIBIOS_READ_CONFIG_DWORD   0xb10a
#   define PCIBIOS_WRITE_CONFIG_BYTE   0xb10b
#   define PCIBIOS_WRITE_CONFIG_WORD   0xb10c
#   define PCIBIOS_WRITE_CONFIG_DWORD   0xb10d
#   define PCIBIOS_GET_ROUTING_OPTIONS   0xb10e
#   define PCIBIOS_SET_PCI_HW_INT   0xb10f
#endif


/** Expand arguments and paste */
#define _IOHW_CAT(x, y)   x ## _ ## y


#ifndef NR_IRQS
/** Upper bound of how many interrupts can be handled in the platform */
#   define NR_IRQS   64
#endif


LIB_FUNC ATTR_CF int irq_canonicalize(const int irq) {
	return irq;
}


/* TODO: Add iohw.h Functions
typedef itype   ioindex_t;
typedef itype   ioreg;
#define iordbuf(dev, idx)   _IOHW_CAT((dev), (brd))(idx)
unsigned int iord(ioreg dev);
unsigned long iordl(ioreg dev);
unsigned int iordbuf(ioreg dev, ioindex_t idx);
unsigned long iordbufl(ioreg dev, ioindex_t idx);
void iowr(ioreg dev, unsigned int val);
void iowrl(ioreg dev, unsigned int val);
void iowrbuf(ioreg dev, ioindex_t idx, unsigned int val);
void iowrbufl(ioreg dev, ioindex_t idx, unsigned int val);
void ioor(ioreg dev, unsigned int val);
void ioorl(ioreg dev, unsigned int val);
void ioorbuf(ioreg dev, ioindex_t idx, unsigned int val);
void ioorbufl(ioreg dev, ioindex_t idx, unsigned int val);
void ioand(ioreg dev, unsigned int val);
void ioandl(ioreg dev, unsigned int val);
void ioandbuf(ioreg dev, ioindex_t idx, unsigned int val);
void ioandbufl(ioreg dev, ioindex_t idx, unsigned int val);
void ioxor(ioreg dev, unsigned int val);
void ioxorl(ioreg dev, unsigned int val);
void ioxorbuf(ioreg dev, ioindex_t idx, unsigned int val);
void ioxorbufl(ioreg dev, ioindex_t idx, unsigned int val);
void iogroup_acquire(int group);
void iogroup_release(int group);
void iogroup_map(int group, int direct);
*/


#endif  // IOHW_H


/* FRAMEBUFFER (<fb.h>) */


#if (!(defined(LINUX_FB_H) || defined(_LINUX_FB_H) || defined(_LINUX_FB_H_)))
#define LINUX_FB_H   (1)
#define _LINUX_FB_H   (1)
#define _LINUX_FB_H_   (1)


#define FB_MAX   32
#define FBIOGET_VSCREENINFO   0x4600
#define FBIOPUT_VSCREENINFO   0x4601
#define FBIOGET_FSCREENINFO   0x4602
#define FBIOGETCMAP   0x4604
#define FBIOPUTCMAP   0x4605
#define FBIOPAN_DISPLAY   0x4606
#define FBIOGET_MONITORSPEC   0x460c
#define FBIOPUT_MONITORSPEC   0x460d
#define FBIOSWITCH_MONIBIT   0x460e
#define FBIOGET_CON2FBMAP   0x460f
#define FBIOPUT_CON2FBMAP   0x4610
#define FBIOBLANK   0x4611
#define FBIO_ALLOC   0x4613
#define FBIO_FREE   0x4614
#define FBIOGET_GLYPH   0x4615
#define FBIOGET_HWCINFO   0x4616
#define FBIOPUT_MODEINFO   0x4617
#define FBIOGET_DISPINFO   0x4618
#define FBIO_WAITFORVSYNC   _IOW('F', 0x20, uint32_t)
/** Packed Pixels */
#define FB_TYPE_PACKED_PIXELS   0
/** Non interleaved planes */
#define FB_TYPE_PLANES   1
/** Interleaved planes */
#define FB_TYPE_INTERLEAVED_PLANES   2
/** Text/attributes */
#define FB_TYPE_TEXT   3
/** EGA/VGA planes */
#define FB_TYPE_VGA_PLANES   4
/** Type identified by a V4L2 FOURCC */
#define FB_TYPE_FOURCC   5
/** Monochrome text */
#define FB_AUX_TEXT_MDA   0
/** CGA/EGA/VGA Color text */
#define FB_AUX_TEXT_CGA   1
/** S3 MMIO fasttext */
#define FB_AUX_TEXT_S3_MMIO   2
/** MGA Millenium I: text, attr, 14 reserved bytes */
#define FB_AUX_TEXT_MGA_STEP16   3
/** Other MGAs: text, attr, 6 reserved bytes */
#define FB_AUX_TEXT_MGA_STEP8   4
/** 8-15: SVGA tileblit compatible modes */
#define FB_AUX_TEXT_SVGA_GROUP   8
/** lower three bits says step */
#define FB_AUX_TEXT_SVGA_MASK   7
/** SVGA text mode: text, attr */
#define FB_AUX_TEXT_SVGA_STEP2   8
/** SVGA text mode: text, attr, 2 reserved bytes */
#define FB_AUX_TEXT_SVGA_STEP4   9
/** SVGA text mode: text, attr, 6 reserved bytes */
#define FB_AUX_TEXT_SVGA_STEP8   10
/** SVGA text mode: text, attr, 14 reserved bytes */
#define FB_AUX_TEXT_SVGA_STEP16   11
/** reserved up to 15 */
#define FB_AUX_TEXT_SVGA_LAST   15
/** 16 color planes (EGA/VGA) */
#define FB_AUX_VGA_PLANES_VGA4   0
/** CFB4 in planes (VGA) */
#define FB_AUX_VGA_PLANES_CFB4   1
/** CFB8 in planes (VGA) */
#define FB_AUX_VGA_PLANES_CFB8   2
/** Monochrome 1 = Black 0 = White */
#define FB_VISUAL_MONO01   0
/** Monochrome 1 = White 0 = Black */
#define FB_VISUAL_MONO10   1
/** True color */
#define FB_VISUAL_TRUECOLOR   2
/** Pseudo color (like atari) */
#define FB_VISUAL_PSEUDOCOLOR   3
/** Direct color */
#define FB_VISUAL_DIRECTCOLOR   4
/** Pseudo color readonly */
#define FB_VISUAL_STATIC_PSEUDOCOLOR   5
/** Visual identified by a V4L2 FOURCC */
#define FB_VISUAL_FOURCC   6
/** no hardware accelerator */
#define FB_ACCEL_NONE   0
/** Atari Blitter */
#define FB_ACCEL_ATARIBLITT   1
/** Amiga Blitter */
#define FB_ACCEL_AMIGABLITT   2
/** Cybervision64 (S3 Trio64) */
#define FB_ACCEL_S3_TRIO64   3
/** RetinaZ3 (NCR 77C32BLT) */
#define FB_ACCEL_NCR_77C32BLT   4
/** Cybervision64/3D (S3 ViRGE) */
#define FB_ACCEL_S3_VIRGE   5
/** ATI Mach 64GX family */
#define FB_ACCEL_ATI_MACH64GX   6
/** DEC 21030 TGA */
#define FB_ACCEL_DEC_TGA   7
/** ATI Mach 64CT family */
#define FB_ACCEL_ATI_MACH64CT   8
/** ATI Mach 64CT family VT class */
#define FB_ACCEL_ATI_MACH64VT   9
/** ATI Mach 64CT family GT class */
#define FB_ACCEL_ATI_MACH64GT   10
/** Sun Creator/Creator3D */
#define FB_ACCEL_SUN_CREATOR   11
/** Sun cg6 */
#define FB_ACCEL_SUN_CGSIX   12
/** Sun leo/zx */
#define FB_ACCEL_SUN_LEO   13
/** IMS Twin Turbo */
#define FB_ACCEL_IMS_TWINTURBO   14
/** 3Dlabs Permedia 2 */
#define FB_ACCEL_3DLABS_PERMEDIA2   15
/** Matrox MGA2064W (Millenium) */
#define FB_ACCEL_MATROX_MGA2064W   16
/** Matrox MGA1064SG (Mystique) */
#define FB_ACCEL_MATROX_MGA1064SG   17
/** Matrox MGA2164W (Millenium II) */
#define FB_ACCEL_MATROX_MGA2164W   18
/** Matrox MGA2164W (Millenium II) */
#define FB_ACCEL_MATROX_MGA2164W_AGP   19
/** Matrox G100 (Productiva G100) */
#define FB_ACCEL_MATROX_MGAG100   20
/** Matrox G200 (Myst, Mill, ...) */
#define FB_ACCEL_MATROX_MGAG200   21
/** Sun cgfourteen */
#define FB_ACCEL_SUN_CG14   22
/** Sun bwtwo */
#define FB_ACCEL_SUN_BWTWO   23
/** Sun cgthree */
#define FB_ACCEL_SUN_CGTHREE   24
/** Sun tcx */
#define FB_ACCEL_SUN_TCX   25
/** Matrox G400 */
#define FB_ACCEL_MATROX_MGAG400   26
/** nVidia RIVA 128 */
#define FB_ACCEL_NV3   27
/** nVidia RIVA TNT */
#define FB_ACCEL_NV4   28
/** nVidia RIVA TNT2 */
#define FB_ACCEL_NV5   29
/** C&T 6555x */
#define FB_ACCEL_CT_6555x   30
/** 3Dfx Banshee */
#define FB_ACCEL_3DFX_BANSHEE   31
/** ATI Rage128 family */
#define FB_ACCEL_ATI_RAGE128   32
/** CyberPro 2000 */
#define FB_ACCEL_IGS_CYBER2000   33
/** CyberPro 2010 */
#define FB_ACCEL_IGS_CYBER2010   34
/** CyberPro 5000 */
#define FB_ACCEL_IGS_CYBER5000   35
/** SiS 300/630/540 */
#define FB_ACCEL_SIS_GLAMOUR   36
/** 3Dlabs Permedia 3 */
#define FB_ACCEL_3DLABS_PERMEDIA3   37
/** ATI Radeon family */
#define FB_ACCEL_ATI_RADEON   38
/** Intel 810/815 */
#define FB_ACCEL_I810   39
/** SiS 315, 650, 740 */
#define FB_ACCEL_SIS_GLAMOUR_2   40
/** SiS 330 ("Xabre") */
#define FB_ACCEL_SIS_XABRE   41
/** Intel 830M/845G/85x/865G */
#define FB_ACCEL_I830   42
/** nVidia Arch 10 */
#define FB_ACCEL_NV_10   43
/** nVidia Arch 20 */
#define FB_ACCEL_NV_20   44
/** nVidia Arch 30 */
#define FB_ACCEL_NV_30   45
/** nVidia Arch 40 */
#define FB_ACCEL_NV_40   46
/** XGI Volari V3XT, V5, V8 */
#define FB_ACCEL_XGI_VOLARI_V   47
/** XGI Volari Z7 */
#define FB_ACCEL_XGI_VOLARI_Z   48
/** TI OMAP16xx */
#define FB_ACCEL_OMAP1610   49
/** Trident TGUI */
#define FB_ACCEL_TRIDENT_TGUI   50
/** Trident 3DImage */
#define FB_ACCEL_TRIDENT_3DIMAGE   51
/** Trident Blade3D */
#define FB_ACCEL_TRIDENT_BLADE3D   52
/** Trident BladeXP */
#define FB_ACCEL_TRIDENT_BLADEXP   53
/** Cirrus Logic 543x/544x/5480 */
#define FB_ACCEL_CIRRUS_ALPINE   53
/** NeoMagic NM2070 */
#define FB_ACCEL_NEOMAGIC_NM2070   90
/** NeoMagic NM2090 */
#define FB_ACCEL_NEOMAGIC_NM2090   91
/** NeoMagic NM2093 */
#define FB_ACCEL_NEOMAGIC_NM2093   92
/** NeoMagic NM2097 */
#define FB_ACCEL_NEOMAGIC_NM2097   93
/** NeoMagic NM2160 */
#define FB_ACCEL_NEOMAGIC_NM2160   94
/** NeoMagic NM2200 */
#define FB_ACCEL_NEOMAGIC_NM2200   95
/** NeoMagic NM2230 */
#define FB_ACCEL_NEOMAGIC_NM2230   96
/** NeoMagic NM2360 */
#define FB_ACCEL_NEOMAGIC_NM2360   97
/** NeoMagic NM2380 */
#define FB_ACCEL_NEOMAGIC_NM2380   98
/** PXA3xx */
#define FB_ACCEL_PXA3XX   99
/** S3 Savage4 */
#define FB_ACCEL_SAVAGE4   0x80
/** S3 Savage3D */
#define FB_ACCEL_SAVAGE3D   0x81
/** S3 Savage3D-MV */
#define FB_ACCEL_SAVAGE3D_MV   0x82
/** S3 Savage2000 */
#define FB_ACCEL_SAVAGE2000   0x83
/** S3 Savage/MX-MV */
#define FB_ACCEL_SAVAGE_MX_MV   0x84
/** S3 Savage/MX */
#define FB_ACCEL_SAVAGE_MX   0x85
/** S3 Savage/IX-MV */
#define FB_ACCEL_SAVAGE_IX_MV   0x86
/** S3 Savage/IX */
#define FB_ACCEL_SAVAGE_IX   0x87
/** S3 ProSavage PM133 */
#define FB_ACCEL_PROSAVAGE_PM   0x88
/** S3 ProSavage KM133 */
#define FB_ACCEL_PROSAVAGE_KM   0x89
/** S3 Twister */
#define FB_ACCEL_S3TWISTER_P   0x8a
/** S3 TwisterK */
#define FB_ACCEL_S3TWISTER_K   0x8b
/** S3 Supersavage */
#define FB_ACCEL_SUPERSAVAGE   0x8c
/** S3 ProSavage DDR */
#define FB_ACCEL_PROSAVAGE_DDR   0x8d
/** S3 ProSavage DDR-K */
#define FB_ACCEL_PROSAVAGE_DDRK   0x8e
/** PKUnity-v3 Unigfx */
#define FB_ACCEL_PUV3_UNIGFX   0xa0
/** Device supports FOURCC-based formats */
#define FB_CAP_FOURCC   1
/** Hold-And-Modify (HAM) */
#define FB_NONSTD_HAM   (1)
/** Order of pixels in each byte is reversed */
#define FB_NONSTD_REV_PIX_IN_B   (2)
/** Set values immediately (or vbl)*/
#define FB_ACTIVATE_NOW   (0)
/** Activate on next open */
#define FB_ACTIVATE_NXTOPEN   (1)
/** Do not set, round up impossible */
#define FB_ACTIVATE_TEST   (2)
#define FB_ACTIVATE_MASK   (15)
/** Activate values on next vbl */
#define FB_ACTIVATE_VBL   (16)
/** Change colormap on vbl */
#define FB_CHANGE_CMAP_VBL   (32)
/** Change all VCs on this fb */
#define FB_ACTIVATE_ALL   (64)
/** Force apply even when no change*/
#define FB_ACTIVATE_FORCE   (128)
/** Invalidate videomode */
#define FB_ACTIVATE_INV_MODE  (256)
#define FB_ACCELF_TEXT   (1)
/** Horizontal sync high active */
#define FB_SYNC_HOR_HIGH_ACT   (1)
/** Vertical sync high active */
#define FB_SYNC_VERT_HIGH_ACT   (2)
/** External sync */
#define FB_SYNC_EXT   (4)
/** Composite sync high active */
#define FB_SYNC_COMP_HIGH_ACT   (8)
/** Broadcast video timings */
#define FB_SYNC_BROADCAST   (16)
/** Sync on green */
#define FB_SYNC_ON_GREEN   (32)
/** Non-interlaced */
#define FB_VMODE_NONINTERLACED   (0)
/** Interlaced */
#define FB_VMODE_INTERLACED   (1)
/** Double scan */
#define FB_VMODE_DOUBLE   (2)
/** Interlaced: top line first */
#define FB_VMODE_ODD_FLD_FIRST   (4)
#define FB_VMODE_MASK   (255)
/** ywrap instead of panning */
#define FB_VMODE_YWRAP   (256)
/** Smooth xpan possible (internally used) */
#define FB_VMODE_SMOOTH_XPAN   (512)
/** Do not update x/yoffset */
#define FB_VMODE_CONUPDATE   (512)
// Display rotation support
#define FB_ROTATE_UR   0
#define FB_ROTATE_CW   1
#define FB_ROTATE_UD   2
#define FB_ROTATE_CCW   3
#define PICOS2KHZ(a)   (1000000000UL / (a))
#define KHZ2PICOS(a)   (1000000000UL / (a))
// VESA Blanking Levels
#define VESA_NO_BLANKING   0
/** screen: unblanked, hsync: on, vsync: on */
#define FB_BLANK_UNBLANK   0
/** screen: blanked, hsync: on, vsync: on */
#define FB_BLANK_NORMAL   1
#define VESA_VSYNC_SUSPEND   1
/** screen: blanked, hsync: on, vsync: off */
#define FB_BLANK_VSYNC_SUSPEND   2
#define VESA_HSYNC_SUSPEND   2
/** screen: blanked, hsync: off, vsync: on */
#define FB_BLANK_HSYNC_SUSPEND   3
#define VESA_POWERDOWN   3
/** screen: blanked, hsync: off, vsync: off */
#define FB_BLANK_POWERDOWN   4
/** Currently in a vertical blank */
#define FB_VBLANK_VBLANKING   1
/** Currently in a horizontal blank */
#define FB_VBLANK_HBLANKING   2
/** Vertical blanks can be detected */
#define FB_VBLANK_HAVE_VBLANK   4
/** Horizontal blanks can be detected */
#define FB_VBLANK_HAVE_HBLANK   8
/** Global retrace counter is available */
#define FB_VBLANK_HAVE_COUNT   0x10
/** The vcount field is valid */
#define FB_VBLANK_HAVE_VCOUNT   0x20
/** The hcount field is valid */
#define FB_VBLANK_HAVE_HCOUNT   0x40
/** Currently in a vsync */
#define FB_VBLANK_VSYNCING   0x80
/** Verical syncs can be detected */
#define FB_VBLANK_HAVE_VSYNC   0x100
// Internal HW accel
#define ROP_COPY   0
#define ROP_XOR   1
// Hardware cursor control
#define FB_CUR_SETIMAGE   1
#define FB_CUR_SETPOS   2
#define FB_CUR_SETHOT   4
#define FB_CUR_SETCMAP   8
#define FB_CUR_SETSHAPE   0x10
#define FB_CUR_SETSIZE   0x20
#define FB_CUR_SETALL   0xff
// Settings for the generic backlight code
#define FB_BACKLIGHT_LEVELS   128
#define FB_BACKLIGHT_MAX   0xff


typedef struct attr_packed fb_fix_screeninfo {
	char id[16];
	unsigned long smem_start;
	uint32_t smem_len, type;
	uint32_t type_aux;  // Interleave for interleaved Planes
	uint32_t visual;
	uint16_t xpanstep, ypanstep;  // Zero if no hardware panning
	uint16_t ywrapstep;  // Zero if no hardware ywrap
	uint32_t line_length;  // Length of a line in bytes
	unsigned long mmio_start;  // Start of Memory Mapped I/O
	uint32_t mmio_len;  // Length of Memory Mapped I/O
	uint32_t accel;  // Indicate to driver the specific chip/card
	uint16_t capabilities;
	uint16_t reserved[2];
} fb_fix_screeninfo_t;

typedef struct fb_bitfield { uint32_t offset, length, msb_right; }   fb_bitfield_t;

struct fb_var_screeninfo {
	uint32_t xres, yres, xres_virtual, yres_virtual;
	uint32_t xoffset, yoffset;
	uint32_t bits_per_pixel;
	uint32_t grayscale;  // 0 = color, 1 = grayscale, >1 = FOURCC
	struct fb_bitfield red, green, blue, transp;
	uint32_t nonstd, activate;
	uint32_t height, width;
	uint32_t accel_flags, pixclock;
	uint32_t left_margin, right_margin, upper_margin, lower_margin;
	uint32_t hsync_len, vsync_len;
	uint32_t sync, vmode;
	uint32_t rotate;  // Rotation angle; counter-clockwise
	uint32_t colorspace;  // Colorspace for FOURCC-based modes
	uint32_t reserved[4];
};

typedef struct fb_cmap {
	uint32_t start, len;
	uint16_t *red, *green, *blue, *transp;
} fb_cmap_t;

typedef struct fb_con2fbmap { uint32_t console, framebuffer; }   fb_con2fbmap_t;

typedef struct fb_vblank {
	uint32_t flags, count, vcount, hcount, reserved[4];
} fb_vblank_t;

typedef struct fb_copyarea {
	uint32_t dx, dy, width, height, sx, sy;
} fb_copyarea_t;

typedef struct fb_fillrect {
	uint32_t dx, dy, width, height, color, rop;
} fb_fillrect_t;

typedef struct attr_packed fb_image {
	uint32_t dx, dy;  // Where to place image
	uint32_t width, height;
	uint32_t fg_color;  // Only used when a mono bitmap
	uint32_t bg_color;
	uint8_t depth;  // Depth of the image
	const char* data;  // Pointer to image data
	struct fb_cmap cmap;  // color map info
} fb_image_t;

typedef struct fbcurpos { uint16_t x, y; }   fbcurpos_t;

typedef struct attr_packed fb_cursor {
	uint16_t set;  // What to set
	uint16_t enable;  // Cursor on/off
	uint16_t rop;  // Bitop operation
	const char* mask;  // Cursor mask bits
	struct fbcurpos hot;  // Cursor hot spot
	struct fb_image image;  // Cursor image
} fb_cursor_t;


#define FBIO_CURSOR   _IOWR('F', 8, struct fb_cursor)
#define FBIOGET_VBLANK   _IOR('F', 0x12, struct fb_vblank)


#endif  // LINUX_FB_H


/* VGA CHIPSET INTERACTION (<video/vga.h>) */


#if (!(defined(_ASM_GENERIC_VGA_H) || defined(__ASM_GENERIC_VGA_H) || defined(_ASM_GENERIC_VGA_H_) || defined(__ASM_GENERIC_VGA_H_)))
#define _ASM_GENERIC_VGA_H   (1)
#define __ASM_GENERIC_VGA_H   (1)
#define _ASM_GENERIC_VGA_H_   (1)
#define __ASM_GENERIC_VGA_H_   (1)
#define __linux_video_vga_h__   (1)


// VGA data register ports
/** CRT Controller Data Register - color emulation */
#define VGA_CRT_DC   0x3d5
/** CRT Controller Data Register - mono emulation */
#define VGA_CRT_DM   0x3b5
/** Attribute Controller Data Read Register */
#define VGA_ATT_R   0x3c1
/** Attribute Controller Data Write Register */
#define VGA_ATT_W   0x3c0
/** Graphics Controller Data Register */
#define VGA_GFX_D   0x3cf
/** Sequencer Data Register */
#define VGA_SEQ_D   0x3c5
/** Misc Output Read Register */
#define VGA_MIS_R   0x3cc
/** Misc Output Write Register */
#define VGA_MIS_W   0x3c2
/** Feature Control Read Register */
#define VGA_FTC_R   0x3ca
/** Input Status Register 1 - color emulation */
#define VGA_IS1_RC   0x3da
/** Input Status Register 1 - mono emulation */
#define VGA_IS1_RM   0x3ba
/** PEL Data Register */
#define VGA_PEL_D   0x3c9
/** PEL mask register */
#define VGA_PEL_MSK   0x3c6
// EGA-specific registers
/** Graphics enable processor 0 */
#define EGA_GFX_E0   0x3cc
/** Graphics enable processor 1 */
#define EGA_GFX_E1   0x3ca
// VGA index register ports
/** CRT Controller Index - color emulation */
#define VGA_CRT_IC   0x3d4
/** CRT Controller Index - mono emulation */
#define VGA_CRT_IM   0x3b4
/** Attribute Controller Index & Data Write Register */
#define VGA_ATT_IW   0x3c0
/** Graphics Controller Index */
#define VGA_GFX_I   0x3ce
/** Sequencer Index */
#define VGA_SEQ_I   0x3c4
/** PEL Write Index */
#define VGA_PEL_IW   0x3c8
/** PEL Read Index */
#define VGA_PEL_IR   0x3c7
// Standard VGA indexes max counts
/** Number of CRT Controller Registers */
#define VGA_CRT_C   0x19
/** Number of Attribute Controller Registers */
#define VGA_ATT_C   0x15
/** Number of Graphics Controller Registers */
#define VGA_GFX_C   9
/** Number of Sequencer Registers */
#define VGA_SEQ_C   5
/** Number of Misc Output Register */
#define VGA_MIS_C   1
// VGA misc register bit masks
#define VGA_MIS_COLOR   1
#define VGA_MIS_ENB_MEM_ACCESS   2
#define VGA_MIS_DCLK_28322_720   4
#define VGA_MIS_ENB_PLL_LOAD   0xc
#define VGA_MIS_SEL_HIGH_PAGE   0x20
/** VGA CRT controller register indices */
enum VGA_CRTC {
	VGA_CRTC_H_TOTAL = 0,
	VGA_CRTC_H_DISP = 1,
	VGA_CRTC_H_BLANK_START = 2,
	VGA_CRTC_H_BLANK_END = 3,
	VGA_CRTC_H_SYNC_START = 4,
	VGA_CRTC_H_SYNC_END = 5,
	VGA_CRTC_V_TOTAL = 6,
	VGA_CRTC_OVERFLOW = 7,
	VGA_CRTC_PRESET_ROW = 8,
	VGA_CRTC_MAX_SCAN = 9,
	VGA_CRTC_CURSOR_START = 0xa,
	VGA_CRTC_CURSOR_END = 0xb,
	VGA_CRTC_START_HI = 0xc,
	VGA_CRTC_START_LO = 0xd,
	VGA_CRTC_CURSOR_HI = 0xe,
	VGA_CRTC_CURSOR_LO = 0xf,
	VGA_CRTC_V_SYNC_START = 0x10,
	VGA_CRTC_V_SYNC_END = 0x11,
	VGA_CRTC_V_DISP_END = 0x12,
	VGA_CRTC_OFFSET = 0x13,
	VGA_CRTC_UNDERLINE = 0x14,
	VGA_CRTC_V_BLANK_START = 0x15,
	VGA_CRTC_V_BLANK_END = 0x16,
	VGA_CRTC_MODE = 0x17,
	VGA_CRTC_LINE_COMPARE = 0x18
};
#define VGA_CRTC_REGS   VGA_CRT_C
// VGA CRT controller bit masks
/** Lock writes to CR0 - CR7 */
#define VGA_CR11_LOCK_CR0_CR7   0x80
#define VGA_CR17_H_V_SIGNALS_ENABLED   0x80
/** VGA attribute controller register indices */
enum VGA_ATTR {
	VGA_ATC_PALETTE0 = 0,
	VGA_ATC_PALETTE1 = 1,
	VGA_ATC_PALETTE2 = 2,
	VGA_ATC_PALETTE3 = 3,
	VGA_ATC_PALETTE4 = 4,
	VGA_ATC_PALETTE5 = 5,
	VGA_ATC_PALETTE6 = 6,
	VGA_ATC_PALETTE7 = 7,
	VGA_ATC_PALETTE8 = 8,
	VGA_ATC_PALETTE9 = 9,
	VGA_ATC_PALETTEA = 0xa,
	VGA_ATC_PALETTEB = 0xb,
	VGA_ATC_PALETTEC = 0xc,
	VGA_ATC_PALETTED = 0xd,
	VGA_ATC_PALETTEE = 0xe,
	VGA_ATC_PALETTEF = 0xf,
	VGA_ATC_MODE = 0x10,
	VGA_ATC_OVERSCAN = 0x11,
	VGA_ATC_PLANE_ENABLE = 0x12,
	VGA_ATC_PEL = 0x13,
	VGA_ATC_COLOR_PAGE = 0x14,
	VGA_AR_ENABLE_DISPLAY = 0x20
};
// VGA sequencer register indices
#define VGA_SEQ_RESET   0
#define VGA_SEQ_CLOCK_MODE   1
#define VGA_SEQ_PLANE_WRITE   2
#define VGA_SEQ_CHARACTER_MAP   3
#define VGA_SEQ_MEMORY_MODE   4
// VGA sequencer register bit masks
/** Bit 0: character clocks 8 dots wide are generated */
#define VGA_SR01_CHAR_CLK_8DOTS   1
/** Bit 5: Screen is off */
#define VGA_SR01_SCREEN_OFF   0x20
/** Bits 3-0: enable access to all planes */
#define VGA_SR02_ALL_PLANES   0xf
/** Bit 1: allows complete mem access to 256K */
#define VGA_SR04_EXT_MEM   2
/** Bit 2: directs system to use a sequential addressing mode */
#define VGA_SR04_SEQ_MODE   4
/** Bit 3: selects modulo 4 addressing for CPU access to display memory */
#define VGA_SR04_CHN_4M   8
/** VGA graphics controller register indices */
enum VGA_GFX {
	VGA_GFX_SR_VALUE = 0,
	VGA_GFX_SR_ENABLE = 1,
	VGA_GFX_COMPARE_VALUE = 2,
	VGA_GFX_DATA_ROTATE = 3,
	VGA_GFX_PLANE_READ = 4,
	VGA_GFX_MODE = 5,
	VGA_GFX_MISC = 6,
	VGA_GFX_COMPARE_MASK = 7,
	VGA_GFX_BIT_MASK = 8
};
/** VGA graphics controller bit mask */
#define VGA_GR06_GRAPHICS_MODE   1
/** Macro for composing an 8-bit VGA register index and value into a single 16-bit quantity */
#define VGA_OUT16VAL(v, r)   (((v) << 8) | (r))
#if IS_LITTLE_ENDIAN
/** Decide whether we should enable the faster 16-bit VGA register writes */
#   define VGA_OUTW_WRITE   (1)
#endif
/** VGA State Save and Restore */
enum VGA_SAVE {
/** Save/restore plane 2 fonts */
	VGA_SAVE_FONT0 = 1,
/** Save/restore plane 3 fonts */
	VGA_SAVE_FONT1 = 2,
/** Save/restore plane 0/1 fonts */
	VGA_SAVE_TEXT = 4,
/** Save/restore all fonts */
	VGA_SAVE_FONTS = 7,
/** Save/restore video mode */
	VGA_SAVE_MODE = 8,
/** Save/restore color map/DAC */
	VGA_SAVE_CMAP = 16
};


typedef struct attr_packed vgastate {
	void __iomem* vgabase;  // mmio base, if supported
	unsigned long membase;  // VGA window base, 0 for default - 0xa000
	uint32_t memsize;  // VGA window size, 0 for default 64K
	uint32_t flags;  // what state[s] to save (see VGA_SAVE_*)
	uint32_t depth;  // current fb depth, not important
	uint32_t num_attr;  // number of att registers, 0 for default
	uint32_t num_crtc;  // number of crt registers, 0 for default
	uint32_t num_gfx;  // number of gfx registers, 0 for default
	uint32_t num_seq;  // number of seq registers, 0 for default
	void* vidstate;
} vgastate_t;


#define vga_readb(x)   (*(x))
#define vga_writeb(x, y)   (*(y) = (x))


/** Generic VGA port read */
LIB_FUNC unsigned char vga_io_r(const unsigned short port) {
	return (unsigned char)inb_p(port);
}


/** Generic VGA port write */
LIB_FUNC void vga_io_w(const unsigned short port, const unsigned char val) {
	outb_p(val, port);
}


LIB_FUNC void vga_io_w_fast(const unsigned short port, const unsigned char reg, const unsigned char val) {
	outw((unsigned short)VGA_OUT16VAL(val, reg), port);
}


LIB_FUNC unsigned char vga_mm_r(const void __iomem* regbase, const unsigned short port) {
	return (unsigned char)(*(volatile unsigned char*)(&regbase + port));
}


LIB_FUNC void vga_mm_w(void __iomem* regbase, const unsigned short port, const unsigned char val) {
	(*(volatile unsigned char*)(&regbase + port) = val);
}


LIB_FUNC void vga_mm_w_fast(void __iomem* regbase, const unsigned short port, const unsigned char reg, const unsigned char val) {
	(*(volatile unsigned short*)(&regbase + port) = (unsigned short)VGA_OUT16VAL(val, reg));
}


LIB_FUNC unsigned char vga_r(const void __iomem* regbase, const unsigned short port) {
	if (regbase) { return (unsigned char)vga_mm_r(regbase, port); }
	return (unsigned char)vga_io_r(port);
}


LIB_FUNC void vga_w(void __iomem* regbase, const unsigned short port, const unsigned char val) {
	if (regbase) { vga_mm_w(regbase, port, val); }
	else { vga_io_w(port, val); }
}


LIB_FUNC void vga_w_fast(void __iomem* regbase, const unsigned short port, const unsigned char reg, const unsigned char val) {
	if (regbase) { vga_mm_w_fast(regbase, port, reg, val); }
	else { vga_io_w_fast(port, reg, val); }
}


/** VGA CRTC register read */
LIB_FUNC unsigned char vga_rcrt(void __iomem* regbase, const unsigned char reg) {
	vga_w(regbase, VGA_CRT_IC, reg);
	return (unsigned char)vga_r(regbase, VGA_CRT_DC);
}


/** VGA CRTC register write */
LIB_FUNC void vga_wcrt(void __iomem* regbase, const unsigned char reg, const unsigned char val) {
#   ifdef VGA_OUTW_WRITE
	vga_w_fast(regbase, VGA_CRT_IC, reg, val);
#   else
	vga_w(regbase, VGA_CRT_IC, reg);
	vga_w(regbase, VGA_CRT_DC, val);
#   endif
}


LIB_FUNC unsigned char vga_io_rcrt(const unsigned char reg) {
	vga_io_w(VGA_CRT_IC, reg);
	return (unsigned char)vga_io_r(VGA_CRT_DC);
}


LIB_FUNC void vga_io_wcrt(const unsigned char reg, const unsigned char val) {
#   ifdef VGA_OUTW_WRITE
	vga_io_w_fast(VGA_CRT_IC, reg, val);
#   else
	vga_io_w(VGA_CRT_IC, reg);
	vga_io_w(VGA_CRT_DC, val);
#   endif
}


LIB_FUNC unsigned char vga_mm_rcrt(void __iomem* regbase, const unsigned char reg) {
	vga_mm_w(regbase, VGA_CRT_IC, reg);
	return (unsigned char)vga_mm_r(regbase, VGA_CRT_DC);
}


LIB_FUNC void vga_mm_wcrt(void __iomem* regbase, const unsigned char reg, const unsigned char val) {
#   ifdef VGA_OUTW_WRITE
	vga_mm_w_fast(regbase, VGA_CRT_IC, reg, val);
#   else
	vga_mm_w(regbase, VGA_CRT_IC, reg);
	vga_mm_w(regbase, VGA_CRT_DC, val);
#   endif
}


/** VGA sequencer register read */
LIB_FUNC unsigned char vga_rseq(void __iomem* regbase, const unsigned char reg) {
	vga_w(regbase, VGA_SEQ_I, reg);
	return (unsigned char)vga_r(regbase, VGA_SEQ_D);
}


/** VGA sequencer register write */
LIB_FUNC void vga_wseq(void __iomem* regbase, const unsigned char reg, const unsigned char val) {
#   ifdef VGA_OUTW_WRITE
	vga_w_fast(regbase, VGA_SEQ_I, reg, val);
#   else
	vga_w(regbase, VGA_SEQ_I, reg);
	vga_w(regbase, VGA_SEQ_D, val);
#   endif
}


LIB_FUNC unsigned char vga_io_rseq(const unsigned char reg) {
	vga_io_w(VGA_SEQ_I, reg);
	return (unsigned char)vga_io_r(VGA_SEQ_D);
}


LIB_FUNC void vga_io_wseq(const unsigned char reg, const unsigned char val) {
#   ifdef VGA_OUTW_WRITE
	vga_io_w_fast(VGA_SEQ_I, reg, val);
#   else
	vga_io_w(VGA_SEQ_I, reg);
	vga_io_w(VGA_SEQ_D, val);
#   endif
}


LIB_FUNC unsigned char vga_mm_rseq(void __iomem* regbase, const unsigned char reg) {
	vga_mm_w(regbase, VGA_SEQ_I, reg);
	return vga_mm_r(regbase, VGA_SEQ_D);
}


LIB_FUNC void vga_mm_wseq(void __iomem* regbase, const unsigned char reg, const unsigned char val) {
#   ifdef VGA_OUTW_WRITE
	vga_mm_w_fast(regbase, VGA_SEQ_I, reg, val);
#   else
	vga_mm_w(regbase, VGA_SEQ_I, reg);
	vga_mm_w(regbase, VGA_SEQ_D, val);
#   endif
}


/** VGA graphics controller register read */
LIB_FUNC unsigned char vga_rgfx(void __iomem* regbase, const unsigned char reg) {
	vga_w(regbase, VGA_GFX_I, reg);
	return vga_r(regbase, VGA_GFX_D);
}


/** VGA graphics controller register write */
LIB_FUNC void vga_wgfx(void __iomem* regbase, const unsigned char reg, const unsigned char val) {
#   ifdef VGA_OUTW_WRITE
	vga_w_fast(regbase, VGA_GFX_I, reg, val);
#   else
	vga_w(regbase, VGA_GFX_I, reg);
	vga_w(regbase, VGA_GFX_D, val);
#   endif
}


LIB_FUNC unsigned char vga_io_rgfx(const unsigned char reg) {
	vga_io_w(VGA_GFX_I, reg);
	return vga_io_r(VGA_GFX_D);
}


LIB_FUNC void vga_io_wgfx(const unsigned char reg, const unsigned char val) {
#   ifdef VGA_OUTW_WRITE
	vga_io_w_fast(VGA_GFX_I, reg, val);
#   else
	vga_io_w(VGA_GFX_I, reg);
	vga_io_w(VGA_GFX_D, val);
#   endif
}


LIB_FUNC unsigned char vga_mm_rgfx(void __iomem* regbase, const unsigned char reg) {
	vga_mm_w(regbase, VGA_GFX_I, reg);
	return vga_mm_r(regbase, VGA_GFX_D);
}


LIB_FUNC void vga_mm_wgfx(void __iomem* regbase, const unsigned char reg, const unsigned char val) {
#   ifdef VGA_OUTW_WRITE
	vga_mm_w_fast(regbase, VGA_GFX_I, reg, val);
#   else
	vga_mm_w(regbase, VGA_GFX_I, reg);
	vga_mm_w(regbase, VGA_GFX_D, val);
#   endif
}


/** VGA attribute controller register read */
LIB_FUNC unsigned char vga_rattr(void __iomem* regbase, const unsigned char reg) {
	vga_w(regbase, VGA_ATT_IW, reg);
	return vga_r(regbase, VGA_ATT_R);
}


/** VGA attribute controller register write */
LIB_FUNC void vga_wattr(void __iomem* regbase, const unsigned char reg, const unsigned char val) {
	vga_w(regbase, VGA_ATT_IW, reg);
	vga_w(regbase, VGA_ATT_W, val);
}


LIB_FUNC unsigned char vga_io_rattr(const unsigned char reg) {
	vga_io_w(VGA_ATT_IW, reg);
	return vga_io_r(VGA_ATT_R);
}


LIB_FUNC void vga_io_wattr(const unsigned char reg, const unsigned char val) {
	vga_io_w(VGA_ATT_IW, reg);
	vga_io_w(VGA_ATT_W, val);
}


LIB_FUNC unsigned char vga_mm_rattr(void __iomem* regbase, const unsigned char reg) {
	vga_mm_w(regbase, VGA_ATT_IW, reg);
	return vga_mm_r(regbase, VGA_ATT_R);
}


LIB_FUNC void vga_mm_wattr(void __iomem* regbase, const unsigned char reg, const unsigned char val) {
	vga_mm_w(regbase, VGA_ATT_IW, reg);
	vga_mm_w(regbase, VGA_ATT_W, val);
}


#endif  // ASM_GENERIC_VGA_H


/* VGA (<vgaarb.h>) */


#if (!(defined(LINUX_VGA_H) || defined(_LINUX_VGA_H) || defined(_LINUX_VGA_H_)))
#define LINUX_VGA_H   (1)
#define _LINUX_VGA_H   (1)
#define _LINUX_VGA_H_   (1)


enum VGA_RSRC {
// Legacy VGA regions
	VGA_RSRC_NONE = 0,
	VGA_RSRC_LEGACY_IO = 1,
	VGA_RSRC_LEGACY_MEM = 2,
	VGA_RSRC_LEGACY_MASK = 3,
// Non-legacy access
	VGA_RSRC_NORMAL_IO = 4,
	VGA_RSRC_NORMAL_MEM = 8
};
#define VGA_DEFAULT_DEVICE   (NULL)


#endif  // LINUX_VGA_H


/* SUPPORT FOR LAPTOP WITH DUAL GPU (<vga_switcheroo.h>) */


#if (!(defined(LINUX_VGA_SWITCHEROO_H) || defined(LINUX_VGA_SWITCHEROO_H_) || defined(_LINUX_VGA_SWITCHEROO_H_)))
#define LINUX_VGA_SWITCHEROO_H   (1)
#define _LINUX_VGA_SWITCHEROO_H_   (1)
#define LINUX_VGA_SWITCHEROO_H_   (1)


enum vga_switcheroo_state {
	VGA_SWITCHEROO_OFF, VGA_SWITCHEROO_ON,
	VGA_SWITCHEROO_INIT, VGA_SWITCHEROO_NOT_FOUND
};

enum vga_switcheroo_client_id {
	VGA_SWITCHEROO_IGD, VGA_SWITCHEROO_DIS, VGA_SWITCHEROO_MAX_CLIENTS
};


#endif  // LINUX_VGA_SWITCHEROO_H


/* SVGA CHIPSET INTERACTION (<video/svga.h>) */


#if (!(defined(_LINUX_SVGA_H) || defined(_LINUX_SVGA_H_) || defined(_SVGA_H) || defined(_SVGA_H_)))
#define _SVGA_H   (1)
#define _SVGA_H_   (1)
#define _LINUX_SVGA_H   (1)
#define _LINUX_SVGA_H_   (1)


/** Terminator for register set */
#define VGA_REGSET_END_VAL   0xff
#define VGA_REGSET_END   { VGA_REGSET_END_VAL, 0, 0 }
#define SVGA_FORMAT_END_VAL   0xffff
#define SVGA_FORMAT_END   { SVGA_FORMAT_END_VAL, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 0, 0, 0, 0, 0, 0 }


typedef struct vga_regset { uint8_t regnum, lowbit, highbit; }   vga_regset_t;

typedef struct svga_fb_format {
	// Var part
	uint32_t bits_per_pixel;
	struct fb_bitfield red, green, blue, transp;
	uint32_t nonstd;
	// Fix part
	uint32_t type, type_aux, visual, xpanstep, xresstep;
} svga_fb_format_t;

typedef struct svga_timing_regs {
	const struct vga_regset* h_total_regs;
	const struct vga_regset* h_display_regs;
	const struct vga_regset* h_blank_start_regs;
	const struct vga_regset* h_blank_end_regs;
	const struct vga_regset* h_sync_start_regs;
	const struct vga_regset* h_sync_end_regs;
	const struct vga_regset* v_total_regs;
	const struct vga_regset* v_display_regs;
	const struct vga_regset* v_blank_start_regs;
	const struct vga_regset* v_blank_end_regs;
	const struct vga_regset* v_sync_start_regs;
	const struct vga_regset* v_sync_end_regs;
} svga_timing_regs_t;

typedef struct svga_pll {
	uint16_t m_min, m_max, n_min, n_max, r_min, r_max;  // r_max < 32
	uint32_t f_vco_min, f_vco_max, f_base;
} svga_pll_t;


/** Write a value to the attribute register */
LIB_FUNC void svga_wattr(void __iomem* regbase, const uint8_t index, const uint8_t data) {
	vga_r(regbase, VGA_IS1_RC);
	vga_w(regbase, VGA_ATT_IW, index);
	vga_w(regbase, VGA_ATT_W, data);
}


/** Write a value to a sequence register with a mask */
LIB_FUNC void svga_wseq_mask(void __iomem* regbase, const uint8_t index, const uint8_t data, const uint8_t mask) {
	vga_wseq(regbase, (unsigned char)index, (unsigned char)((data & mask) | (vga_rseq(regbase, index) & (~mask))));
}


/** Write a value to a CRT register with a mask */
LIB_FUNC void svga_wcrt_mask(void __iomem* regbase, const uint8_t index, const uint8_t data, const uint8_t mask) {
	vga_wcrt(regbase, (unsigned char)index, (unsigned char)((data & mask) | (vga_rcrt(regbase, index) & (~mask))));
}


/* TODO: Add SVGA functions
LIB_FUNC int svga_primary_device(struct pci_dev* dev) {
	uint16_t flags;
	pci_read_config_word(dev, PCI_COMMAND, &flags);
	return (int)(flags & PCI_COMMAND_IO);
}
void svga_wcrt_multi(void __iomem *regbase, const struct vga_regset *regset, uint32_t value);
void svga_wseq_multi(void __iomem *regbase, const struct vga_regset *regset, uint32_t value);
void svga_set_default_gfx_regs(void __iomem *regbase);
void svga_set_default_atc_regs(void __iomem *regbase);
void svga_set_default_seq_regs(void __iomem *regbase);
void svga_set_default_crt_regs(void __iomem *regbase);
void svga_set_textmode_vga_regs(void __iomem *regbase);
void svga_settile(struct fb_info *info, struct fb_tilemap *map);
void svga_tilecopy(struct fb_info *info, struct fb_tilearea *area);
void svga_tilefill(struct fb_info *info, struct fb_tilerect *rect);
void svga_tileblit(struct fb_info *info, struct fb_tileblit *blit);
void svga_tilecursor(void __iomem *regbase, struct fb_info *info, struct fb_tilecursor *cursor);
int svga_get_tilemax(struct fb_info *info);
void svga_get_caps(struct fb_info *info, struct fb_blit_caps *caps, struct fb_var_screeninfo *var);
int svga_compute_pll(const struct svga_pll *pll, uint32_t f_wanted, uint16_t *m, uint16_t *n, uint16_t *r, int node);
int svga_check_timings(const struct svga_timing_regs *tm, struct fb_var_screeninfo *var, int node);
void svga_set_timings(void __iomem *regbase, const struct svga_timing_regs *tm, struct fb_var_screeninfo *var, uint32_t hmul, uint32_t hdiv, uint32_t vmul, uint32_t vdiv, uint32_t hborder, int node);
int svga_match_format(const struct svga_fb_format *frm, struct fb_var_screeninfo *var, struct fb_fix_screeninfo *fix);
*/


#endif  // SVGA_H


/* TTY (<tty.h>) */


#if (!(defined(SYS_TTY_H) || defined(_SYS_TTY_H_) || defined(TTY_H) || defined(_TTY_H_)))
#define SYS_TTY_H   (1)
#define _SYS_TTY_H   (1)
#define _SYS_TTY_H_   (1)
#define TTY_H   (1)
#define _TTY_H   (1)
#define _TTY_H_   (1)


#ifndef TTYCLSIZE
#   define TTYCLSIZE   (1024)
#endif


/** NetBSD Clists are actually ring buffers. The c_cc, c_cf, and c_cl fields have exactly the same behaviour as in true clists. If c_cq is NULL, the ring buffer has no TTY_QUOTE functionality, but saves memory and cpu time */
struct clist {
	/** Count of characters in queue */
	int c_cc;
	/** Total ring buffer length */
	int c_cn;
	/** Points to first character */
	unsigned char* c_cf;
	/** Points to next open character */
	unsigned char* c_cl;
	/** Start of ring buffer */
	unsigned char* c_cs;
	/** c_ce + c_len */
	unsigned char* c_ce;
	/** N bits/bytes long */
	unsigned char* c_cq;
};


#endif  // TTY_H


/* NETWORK INTERFACE TYPES */


#if (!(defined(NET_IF_TYPES_H) || defined(_NET_IF_TYPES_H) || defined(_NET_IF_TYPES_H_)))
/** Interface types for parsing media address headers; This list is derived from the SNMP list of ifTypes, currently documented in RFC1573; The list of assignments is maintained at http://www.iana.org/assignments/smi-numbers */
#define NET_IF_TYPES_H   (1)
#define _NET_IF_TYPES_H   (1)
#define _NET_IF_TYPES_H_   (1)


/** None of the following */
#define IFT_OTHER   1
/** Old-style arpanet imp */
#define IFT_1822   2
/** HDH arpanet imp */
#define IFT_HDH1822   3
/** x25 to imp */
#define IFT_X25DDN   4
/** PDN X25 interface (RFC877) */
#define IFT_X25   5
/** Ethernet CSMACD */
#define IFT_ETHER   6
/** CMSA CD */
#define IFT_ISO88023   7
/** Token Bus */
#define IFT_ISO88024   8
/** Token Ring */
#define IFT_ISO88025   9
/** MAN */
#define IFT_ISO88026   0xa
#define IFT_STARLAN   0xb
/** Proteon 10MBit ring */
#define IFT_P10   0xc
/** Proteon 80MBit ring */
#define IFT_P80   0xd
/** Hyperchannel */
#define IFT_HY   0xe
#define IFT_FDDI   0xf
#define IFT_LAPB   0x10
#define IFT_SDLC   0x11
#define IFT_T1   0x12
/** E1 - European T1 */
#define IFT_CEPT   0x13
#define IFT_ISDNBASIC   0x14
#define IFT_ISDNPRIMARY   0x15
/** Proprietary PTP serial */
#define IFT_PTPSERIAL   0x16
/** RFC 1331 */
#define IFT_PPP   0x17
/** Loopback */
#define IFT_LOOP   0x18
/** ISO over IP */
#define IFT_EON   0x19
/** Obsolete 3MB experimental ethernet */
#define IFT_XETHER   0x1a
/** XNS over IP */
#define IFT_NSIP   0x1b
/** IP over generic TTY */
#define IFT_SLIP   0x1c
/** Ultra Technologies */
#define IFT_ULTRA   0x1d
/** Generic T3 */
#define IFT_DS3   0x1e
/** SMDS */
#define IFT_SIP   0x1f
/** Frame Relay DTE only */
#define IFT_FRELAY   0x20
#define IFT_RS232   0x21
/** parallel-port */
#define IFT_PARA   0x22
#define IFT_ARCNET   0x23
#define IFT_ARCNETPLUS  0x24
/** ATM cells */
#define IFT_ATM   0x25
#define IFT_MIOX25   0x26
/** SONET or SDH */
#define IFT_SONET   0x27
#define IFT_X25PLE  0x28
#define IFT_ISO88022LLC   0x29
#define IFT_LOCALTALK   0x2a
#define IFT_SMDSDXI   0x2b
/** Frame Relay DCE */
#define IFT_FRELAYDCE   0x2c
#define IFT_V35   0x2d
#define IFT_HSSI   0x2e
#define IFT_HIPPI   0x2f
/** Generic Modem */
#define IFT_MODEM   0x30
/** AAL5 over ATM */
#define IFT_AAL5   0x31
#define IFT_SONETPATH   0x32
#define IFT_SONETVT   0x33
/** SMDS InterCarrier Interface */
#define IFT_SMDSICIP   0x34
/** Proprietary Virtual/internal */
#define IFT_PROPVIRTUAL 0x35
/** Proprietary Multiplexing */
#define IFT_PROPMUX   0x36
#define IFT_GIF   0x37
#define IFT_FAITH   0x38
#define IFT_STF   0x39
/** Layer 2 Virtual LAN using 802.1Q */
#define IFT_L2VLAN   0x87
/** IEEE802.3ad Link Aggregate */
#define IFT_IEEE8023ADLAG   0x88
/** IEEE1394 High Performance SerialBus */
#define IFT_IEEE1394   0x90
/** Transparent bridge interface */
#define IFT_BRIDGE   0xd1
/** Encapsulation */
#define IFT_ENC   0xf4
/** Packet filter logging */
#define IFT_PFLOG   0xf5
/** Packet filter state syncing */
#define IFT_PFSYNC   0xf6
/** Common Address Redundancy Protocol */
#define IFT_CARP   0xf8
/** Packet tap pseudo interface */
#define IFT_PKTAP   0xfe
/** Packet Data over Cellular */
#define IFT_CELLULAR   0xff
/** Deprecated; use IFT_CELLULAR */
#define IFT_PDP   IFT_CELLULAR


#endif  // NET_IF_TYPES_H


/* CPIO (<cpio.h>) */


#if (!(defined(CPIO_H) || defined(_CPIO_H) || defined(_CPIO_H_)))  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/cpio.h.html
#define CPIO_H   (1)
#define _CPIO_H   (1)
#define _CPIO_H_   (1)


/** Socket */
#define C_ISSOCK   0140000
/** Symbolic link */
#define C_ISLNK   0120000
/** Reserved */
#define C_ISCTG   0110000
/** Regular file */
#define C_ISREG   0100000
/** Block special */
#define C_ISBLK   060000
/** Directory */
#define C_ISDIR   040000
/** Character special */
#define C_ISCHR   020000
/** FIFO */
#define C_ISFIFO   010000
/** Set user ID */
#define C_ISUID   04000
/** Set group ID */
#define C_ISGID   02000
/** On directories, restricted deletion flag */
#define C_ISVTX   01000
/** Read by owner */
#define C_IRUSR   0400
/** Write by owner */
#define C_IWUSR   0200
/** Execute by owner */
#define C_IXUSR   0100
/** Read by group */
#define C_IRGRP   040
/** Write by group */
#define C_IWGRP   020
/** Execute by group */
#define C_IXGRP   010
/** Read by others */
#define C_IROTH   4
/** Write by others */
#define C_IWOTH   2
/** Execute by others */
#define C_IXOTH   1
#define MAGIC   "070707"


#endif  // CPIO_H


/* TAR (<tar.h>) */


#if (!(defined(TAR_H) || defined(_TAR_H) || defined(_TAR_H_)))  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/tar.h.html
#define TAR_H   (1)
#define _TAR_H   (1)
#define _TAR_H_   (1)


/** Set UID on execution */
#define TSUID   04000
/** Set GID on execution */
#define TSGID   02000
/** On directories, restricted deletion flag */
#define TSVTX   01000
/** Read by owner */
#define TUREAD   0400
/** Write by owner */
#define TUWRITE   0200
/** Execute/search by owner */
#define TUEXEC   0100
/** Read by group */
#define TGREAD   040
/** Write by group */
#define TGWRITE   020
/** Execute/search by group */
#define TGEXEC   010
/** Read by other */
#define TOREAD   4
/** Write by other */
#define TOWRITE   2
/** Execute/search by other */
#define TOEXEC   1
/** Regular file */
#define REGTYPE   '0'
/** Regular file */
#define AREGTYPE   '\0'
/** Link */
#define LNKTYPE   '1'
/** Symbolic link */
#define SYMTYPE   '2'
/** Special Character */
#define CHRTYPE   '3'
/** Special block */
#define BLKTYPE   '4'
/** Directory */
#define DIRTYPE   '5'
/** Special FIFO */
#define FIFOTYPE   '6'
/** Reserved */
#define CONTTYPE   '7'
/** ustar plus null byte */
#define TMAGIC   "ustar\0"
/** Length of TMAGIC */
#define TMAGLEN   6
#define TVERSION   "00"
/** Length of TVERSION */
#define TVERSLEN   2


#endif  // TAR_H


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


enum CTYPES {
/** Alpha */
	_CTYPE_A = 1,
/** Control */
	_CTYPE_C = 2,
/** Digit */
	_CTYPE_D = 4,
/** Graph */
	_CTYPE_G = 8,
/** Lower */
	_CTYPE_L = 0x10,
/** Punct */
	_CTYPE_P = 0x20,
/** Space */
	_CTYPE_S = 0x40,
/** Upper */
	_CTYPE_U = 0x80,
/** X digit */
	_CTYPE_X = 0x100,
/** Blank */
	_CTYPE_BL = 0x200,
/** Print */
	_CTYPE_R = 0x400,
/** Ideogram */
	_CTYPE_I = 0x800,
/** Special */
	_CTYPE_T = 0x1000,
/** Phonogram */
	_CTYPE_Q = 0x2000
};
#define CTYPE_NUM_CHARS   256
#define _CTYPE_NUM_CHARS   (1 << CHAR_BIT)
#define _CTYPE_CACHE_SIZE   0x100

// LC_CTYPE specific; Indices for standard wide character translation mappings
#define __TOW_toupper   (0)
#define __TOW_tolower   (1)
/** LC_CTYPE specific; Access a wide character class with a single character index; c must be an `unsigned char`; desc must be a nonzero wctype_t */
#define _ISCTYPE(c, desc)   (((((const uint32_t*)(desc)) - 8)[(c) >> 5] >> ((c) & 0x1f)) & 1)
#define IS_CODEUNIT(c)   (((unsigned)(c) - 0xdf80) < 0x80)

enum __encoding { CT_8BIT, CT_UTF8 };
static volatile enum __encoding lc_ctype = CT_UTF8;

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
	_ISalnum = _ISbit(11)  // Alphanumeric
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
// Shorthand Character Categories
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
// Character Category Masks
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
/** Cursor movement: <tt>\\f</tt> & <tt>\\v</tt> */
#define cc_M   ((unsigned short)(cc_nv | cc_sp | cc_cn))
/** Vertical space: <tt>\\r</tt> & <tt>\\n</tt> */
#define cc_V   ((unsigned short)(cc_vs | cc_sp | cc_cn))
/** Tab */
#define cc_T   ((unsigned short)(cc_nv | cc_sp | cc_bl | cc_cn))
/** Space */
#define cc_S   ((unsigned short)(cc_nv | cc_sp | cc_bl | cc_pr))

#if (HOST_CHARSET == HOST_CHARSET_ASCII)  // Is this ASCII?
static const UNUSED unsigned short align64 cc_istable[256] = {
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
static const UNUSED unsigned char align64 cc_tolower[256] = {
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
static const UNUSED unsigned char align64 cc_toupper[256] = {
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
#   error   "Add tables for EBCDIC."
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
#define __toascii(c)   ((c) & 0x7f)
/** Convert the char to an ASCII character */
#define TOASCII(c)   __toascii((c))
/** Convert the char to an ASCII character */
#define toascii(c)   TOASCII((c))
#define to_char(c)   (((unsigned int)((c) - '0') <= 9) ? (char)((c) + '0') : (char)(c))
/** Convert the char to a lowercase ASCII letter */
LIB_FUNC ATTR_CF int _tolower(const int symbol) {
	return (((0x40 < symbol) && (symbol < 0x5b)) ? (int)(symbol | ' ') : symbol);
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
LIB_FUNC ATTR_CF int _toupper(const int symbol) {
	return (((0x60 < symbol) && (symbol < 0x7b)) ? (int)(symbol & '_') : symbol);
}
/** Convert the char to a uppercase ASCII letter */
#define TOUPPER(c)   _toupper((c))
/** Convert the char to a uppercase ASCII letter */
#define toupper(c)   _toupper((c))
/** Convert the char to a uppercase ASCII letter */
#define toupper_l(c, l)   _toupper((c))
/** Convert the char to a uppercase ASCII letter */
#define __toupper_l(c, l)   _toupper((c))
/** Invert the case of an ASCII letter */
LIB_FUNC ATTR_CF int invertcase(const int symbol) {
	return ((((0x60 < symbol) && (symbol < 0x7b)) || ((0x40 < symbol) && (symbol < 0x5b))) ? (int)(symbol ^ ' ') : symbol);
}
/** Invert the case of an ASCII letter */
#define flipcase(c)   invertcase((c))
/** Return the letter's position in the alphabet */
LIB_FUNC ATTR_CF int alphapos(const int symbol) {
	return ((((0x60 < symbol) && (symbol < 0x7b)) || ((0x40 < symbol) && (symbol < 0x5b))) ? (int)(symbol & '\x1F') : symbol);
}
/** Test if the char is a digit */
LIB_FUNC ATTR_CF int is_digit(const int symbol) {
	return ((0x2f < symbol) && (symbol < 0x3a));
}
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
#define ISOCTAL(c)   (((c) >= '0') && ((c) <= '7'))
/** Test if the character is an octal character (0-7) */
#define isoctal(c)   ISOCTAL((c))
/** Test if the char is NULL ('\0') */
#define ISNUL(c)   ((c) == '\0')
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
/** Test if the char is the bell character (<tt>\\b</tt>) */
#define ISBELL(c)   ((c) == '\b')
/** Test if the char is the bell character (<tt>\\b</tt>) */
#define isbell(c)   ISBELL((c))
/** Test if the char is a device control character */
#define ISDEVCHAR(c)   (((c) >= 0x11) && ((c) <= 0x14))
/** Test if the char is a device control character */
#define isdevchar(c)   ISDEVCHAR((c))
/** Test if the char is a separator character */
#define ISSEPCHAR(c)   (((c) >= 0x1c) && ((c) <= 0x1f))
/** Test if the char is a separator character */
#define issepchar(c)   ISSEPCHAR((c))
/** Test if the char is the DEL character */
#define ISDEL(c)   ((c) == 0x7f)
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
LIB_FUNC ATTR_CF int ISALNUM(const int c) {
	return (int)(((0x60 < c) && (c < 0x7b)) || ((0x40 < c) && (c < 0x5b)) || ((0x2f < c) && (c < 0x3a)));
}
/** Test if the char is alphanumeric */
#define ISALPHANUM(c)   ISALNUM((c))
/** Test if the char is alphanumeric */
#define isalphanum(c)   ISALNUM((c))
/** Test if the char is alphanumeric */
#define isalnum(c)   ISALNUM((c))
/** Test if the char is alphanumeric */
#define isalnum_l(c, l)   ISALNUM((c))
/** Test if the char is an alphabetic ASCII letter */
LIB_FUNC ATTR_CF int ISALPHA(const int c) {
	return (int)(((0x60 < c) && (c < 0x7b)) || ((0x40 < c) && (c < 0x5b)));
}
/** Test if the char is an alphabetic ASCII letter */
#define isalpha(c)   ISALPHA((c))
/** Test if the char is an alphabetic ASCII letter */
#define isalpha_l(c, l)   ISALPHA((c))
/** Test if the char is a space or tab (<tt>\\t</tt>) character */
#define ISBLANK(c)   (((c) == 0x20) || ((c) == 9))
/** Test if the char is a space or tab (<tt>\\t</tt>) character */
#define isblank(c)   ISBLANK((c))
/** Test if the char is a control character */
#define ISCNTRL(c)   (((c) < 0x20) || (0x7f == (c)))
/** Test if the char is a control character */
#define iscntrl(c)   ISCNTRL((c))
/** Test if the char is a C++ space character (tab, newline, vertical tab, form feed, carriage return, space, and '\\0') */
#define ISCPPSP(c)   (((c) == 0x20) || ((c) == 0) || ((8 < (c)) && ((c) < 0xe)))
/** Test if the char is a C++ space character (isspace + '\\0') */
#define iscppsp(c)   ISCPPSP((c))
/** Test if the char is a currency symbol */
#define ISCURRENCY(c)   (((c) == 0x24) || ((0xa1 < (c)) && ((c) < 0xa6)))
/** Test if the char is a currency symbol */
#define iscurrency(c)   ISCURRENCY((c))
/** Test if the char is an alphabetic letter in the Latin-1 Supplement block */
LIB_FUNC ATTR_CF int ISEXTALPHA(const int c) {
	return (int)((((0xbf < c) && (c < 0xd7)) || ((0xd7 < c) && (c < 0xdf))) || (((0xde < c) && (c < 0xf7)) || ((0xf7 < c))) || ((0xf7 < c)));
}
/** Test if the char is an alphabetic letter in the Latin-1 Supplement block */
#define isextalpha(c)   ISEXTALPHA((c))
/** Test if the char is a control character (includes Latin-1 Supplement block) */
#define ISEXTCNTRL(c)   (((c) < 0x20) || ((0x7e < (c)) && ((c) < 0xa0)))
/** Test if the char is a control character (includes Latin-1 Supplement block) */
#define isextcntrl(c)   ISEXTCNTRL((c))
/** Test if the char is a lowercase alphabetic letter in the Latin-1 Supplement block */
#define ISEXTLOWER(c)   (((0xde < (c)) && ((c) < 0xf7)) || ((0xf7 < (c))))
/** Test if the char is a lowercase alphabetic letter in the Latin-1 Supplement block */
#define isextlower(c)   ISEXTLOWER((c))
/** Test if the char is a uppercase alphabetic letter in the Latin-1 Supplement block */
#define ISEXTUPPER(c)   (((0xbf < (c)) && ((c) < 0xd7)) || ((0xd7 < (c)) && ((c) < 0xdf)))
/** Test if the char is a uppercase alphabetic letter in the Latin-1 Supplement block */
#define isextupper(c)   ISEXTUPPER((c))
/** Test if the char is a graphical character (alphanumeric and punctuation characters) */
#define ISGRAPH(c)   ((0x20 < (c)) && ((c) < 0x7f))
/** Test if the char is a graphical character (alphanumeric and punctuation characters) */
#define isgraph(c)   ISGRAPH((c))
/** Test if the char is an alphabetic character or "_" */
LIB_FUNC ATTR_CF int ISIDST(const int c) {
	return (((0x60 < c) && (c < 0x7b)) || ((0x40 < c) && (c < 0x5b)) || (c == 0x5f));
}
/** Test if the char is an alphabetic character or "_" */
#define isidst(c)   ISIDST((c))
/** Test if the char is an alphanumeric character or "_" */
#define ISIDNUM(c)   (ISIDST((c)) | ISDIGIT((c)))
/** Test if the char is an alphanumeric character or "_" */
#define isidnum(c)   ISIDNUM((c))
/** Test if the char is a punctuation character <tt>(! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~)</tt> */
LIB_FUNC ATTR_CF int ISPUNCT(const int c) {
	return (((0x20 < c) && (c < 0x30)) || ((0x39 < c) && (c < 0x41)) || ((0x5a < c) && (c < 0x61)) || ((0x7a < c) && (c < 0x7f)));
}
/** Test if the char is a punctuation character <tt>(! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~)</tt> */
#define ispunct(c)   ISPUNCT((c))
/** Test if the char is a separator control character */
#define ISSEPARATOR(c)   ((0x1b < (c)) && ((c) < 0x20))
/** Test if the char is a separator control character */
#define isseparator(c)   ISSEPARATOR((c))
/** Test if the char is a space character (tab, newline, vertical tab, form feed, carriage return, and space) */
LIB_FUNC ATTR_CF int ISSPACE(const int c) {
	return ((c == 0x20) || ((8 < c) && (c < 0xe)));
}
/** Test if the char is a space character (tab, newline, vertical tab, form feed, carriage return, and space) */
#define isspace(c)   ISSPACE((c))
/** Return true if symbol is a space in the current locale, avoiding problems with signed char and isspace */
LIB_FUNC ATTR_CF bool locale_isspace(const char symbol) {
	register const unsigned char uc = (unsigned char)symbol;
	return (bool)(((uc == 0x20) || ((8 < uc) && (uc < 0xb))) != 0);
}
/** Test if the char is a space character or NULL */
#define IS_SPACE_OR_NUL(c)   (((c) == 0x20) || ((c) == 0))
/** Test if the char is a space character or NULL */
#define ISSPACEORNUL(c)   IS_SPACE_OR_NUL((c))
/** Test if the char is a space character or NULL */
#define ISSPACEORNULL(c)   IS_SPACE_OR_NUL((c))
/** Test if the char is a space character or NULL */
#define isspaceornull(c)   IS_SPACE_OR_NUL((c))
/** Test if the char is a space character or NULL */
#define is_space_or_nul(c)   IS_SPACE_OR_NUL((c))
/** Test if the char is a lowercase ASCII character */
#define ISLOWERASCII(c)   ((0x60 < (c)) && ((c) < 0x7b))
/** Test if the char is a lowercase ASCII character */
#define islowerascii(c)   ISLOWERASCII((c))
/** Test if the char is a lowercase character */
#define ISLOWER(c)   ISLOWERASCII((c))
/** Test if the char is a lowercase character */
#define islower(c)   ISLOWERASCII((c))
/** Test if the char is space, <tt>\\t</tt>, <tt>\\f</tt>, <tt>\\v</tt>, or <tt>\\0</tt> */
LIB_FUNC ATTR_CF int ISNVSP(const int c) {
	return (int)((c == 9) || (c == 0xb) || (c == 0xc) || (c == 0));
}
/** Test if the char is space, <tt>\\t</tt>, <tt>\\f</tt>, <tt>\\v</tt>, or <tt>\\0</tt> */
#define isnvsp(c)   ISNVSP((c))
/** Test if the char is <tt>\\n</tt> or <tt>\\r</tt> */
#define ISVSP(c)   (((c) == 0xa) || ((c) == 0xd))
/** Test if the char is <tt>\\n</tt> or <tt>\\r</tt> */
#define isvsp(c)   ISVSP((c))
/** Test if the char is a uppercase ASCII character */
LIB_FUNC ATTR_CF int ISUPPER(const int c) {
	return ((0x40 < c) && (c < 0x5b));
}
/** Test if the char is a uppercase ASCII character */
#define ISUPPERASCII(c)   ISUPPER((c))
/** Test if the char is a uppercase ASCII character */
#define isupperascii(c)   ISUPPER((c))
/** Test if the char is a uppercase character */
#define isupper(c)   ISUPPER((c))
/** Test if the char is a hexadecimal digit */
LIB_FUNC ATTR_CF int ISXDIGIT(const int c) {
	return (int)((((0x2f < c) && (c < 0x3a))) || ((0x40 < c) && (c < 0x47)) || ((0x60 < c) && (c < 0x67)));
}
/** Test if the char is a hexadecimal digit */
#define isxdigit(c)   ISXDIGIT((c))
/** Test if the char is a printable character (alphanumeric, punctuation, and space characters) */
LIB_FUNC ATTR_CF int ISPRINT(const int c) {
	return (int)(ISALNUM(c) || ISSPACE(c) || ISPUNCT(c));
}
/** Test if the char is a printable character (alphanumeric, punctuation, and space characters) */
#define isprint(c)   ISPRINT((c))
/** Test if the char is a basic ISO-C character */
LIB_FUNC ATTR_CF int ISBASIC(const int c) {
	return (int)(ISALNUM(c) || ISSPACE(c) || ISPUNCT(c) || ISNULL(c));
}
/** Test if the char is a basic ISO-C character */
#define isbasic(c)   ISBASIC((c))


LIB_FUNC ATTR_CF int isdirect(const uint32_t c) {
	return (int)((c < 128) && ((direct_tab[c >> 3] >> (c & 7)) & 1));
}


LIB_FUNC ATTR_CF int isxdirect(const uint32_t c) {
	return (int)((c < 128) && ((xdirect_tab[c >> 3] >> (c & 7)) & 1));
}


LIB_FUNC ATTR_CF int isxbase64(const uint32_t c) {
	return (int)((c < 128) && ((xbase64_tab[c >> 3] >> (c & 7)) & 1));
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

struct wcasemaps {
	unsigned short upper;
	signed char lower;
	unsigned char len;
};

#define CASEMAP(u1, u2, l)   { (u1), ((l) - (u1)), ((u2) - (u1) + 1) }
#define CASELACE(u1, u2)   CASEMAP((u1), (u2), ((u1) + 1))

static const UNUSED struct wcasemaps wchar_casemaps[] = {
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

static const UNUSED wchar_t wempty[2] = L"";

#include "wctype_table.h"

static const UNUSED unsigned char align64 alpha_table[] = {
#   include "alpha.def"
};

static const UNUSED unsigned char align64 nonspacing_table[] = {
#   include "nonspacing.def"
};

static const UNUSED unsigned char align64 punct_table[] = {
#   include "punct.def"
};

static const UNUSED unsigned char align64 wide_table[] = {
#   include "wide.def"
};

static const UNUSED char* const wchar_properties[WC_TYPE_MAX] = {
	"<invalid>", "alnum", "alpha", "blank", "cntrl", "digit", "graph", "lower", "print", "punct", "space", "upper", "xdigit"
};

static const UNUSED char wchar_class_names[128] = "alnum\0" "alpha\0" "blank\0" "cntrl\0" "digit\0" "graph\0" "lower\0" "print\0" "punct\0" "space\0" "upper\0" "xdigit";

/** This definition of whitespace is the Unicode White_Space property, minus non-breaking spaces (U+00A0, U+2007, and U+202F) and script-specific characters with non-blank glyphs (U+1680 and U+180E) */
static const UNUSED wchar_t wchar_spaces[32] = { ' ', '\t', '\n', '\r', 11, 12, 0x85, 0x2000, 0x2001, 0x2002, 0x2003, 0x2004, 0x2005, 0x2006, 0x2008, 0x2009, 0x200a, 0x2028, 0x2029, 0x205f, 0x3000, 0x0 };

static const UNUSED unsigned short align64 wchar_pairs[128][2] = {
	{ 'I',  0x131 }, { 'S', 0x17f }, { 0x130, 'i' }, { 0x178, 0xff },
	{ 0x181, 0x253 }, { 0x182, 0x183 }, { 0x184, 0x185 }, { 0x186, 0x254 },
	{ 0x187, 0x188 }, { 0x189, 0x256 }, { 0x18a, 0x257 }, { 0x18b, 0x18c },
	{ 0x18e, 0x1dd }, { 0x18f, 0x259 }, { 0x190, 0x25b }, { 0x191, 0x192 },
	{ 0x193, 0x260 }, { 0x194, 0x263 }, { 0x196, 0x269 }, { 0x197, 0x268 },
	{ 0x198, 0x199 }, { 0x19c, 0x26f }, { 0x19d, 0x272 }, { 0x19f, 0x275 },
	{ 0x1a6, 0x280 }, { 0x1a7, 0x1a8 }, { 0x1a9, 0x283 }, { 0x1ac, 0x1ad },
	{ 0x1ae, 0x288 }, { 0x1af, 0x1b0 }, { 0x1b1, 0x28a }, { 0x1b2, 0x28b },
	{ 0x1b7, 0x292 }, { 0x1b8, 0x1b9 }, { 0x1bc, 0x1bd }, { 0x1c4, 0x1c6 },
	{ 0x1c4, 0x1c5 }, { 0x1c5, 0x1c6 }, { 0x1c7, 0x1c9 }, { 0x1c7, 0x1c8 },
	{ 0x1c8, 0x1c9 }, { 0x1ca, 0x1cc }, { 0x1ca, 0x1cb }, { 0x1cb, 0x1cc },
	{ 0x1f1, 0x1f3 }, { 0x1f1, 0x1f2 }, { 0x1f2, 0x1f3 }, { 0x1f4, 0x1f5 },
	{ 0x1f6, 0x195 }, { 0x1f7, 0x1bf }, { 0x220, 0x19e }, { 0x386, 0x3ac },
	{ 0x388, 0x3ad }, { 0x389, 0x3ae }, { 0x38a, 0x3af }, { 0x38c, 0x3cc },
	{ 0x38e, 0x3cd }, { 0x38f, 0x3ce }, { 0x399, 0x345 }, { 0x399, 0x1fbe },
	{ 0x3a3, 0x3c2 }, { 0x3f7, 0x3f8 }, { 0x3fa, 0x3fb }, { 0x1e60, 0x1e9b },
	{ 0x1e9e, 0xdf }, { 0x1f59, 0x1f51 }, { 0x1f5b, 0x1f53 }, { 0x1f5d, 0x1f55 },
	{ 0x1f5f, 0x1f57 }, { 0x1fbc, 0x1fb3 }, { 0x1fcc, 0x1fc3 }, { 0x1fec, 0x1fe5 },
	{ 0x1ffc, 0x1ff3 }, { 0x23a, 0x2c65 }, { 0x23b, 0x23c }, { 0x23d, 0x19a },
	{ 0x23e, 0x2c66 }, { 0x241, 0x242 }, { 0x243, 0x180 }, { 0x244, 0x289 },
	{ 0x245, 0x28c }, { 0x3f4, 0x3b8 }, { 0x3f9, 0x3f2 }, { 0x3fd, 0x37b },
	{ 0x3fe, 0x37c }, { 0x3ff, 0x37d }, { 0x4c0, 0x4cf }, { 0x2126, 0x3c9 },
	{ 0x212a, 'k' }, { 0x212b, 0xe5 }, { 0x2132, 0x214e }, { 0x2183, 0x2184 },
	{ 0x2c60, 0x2c61 }, { 0x2c62, 0x26b }, { 0x2c63, 0x1d7d }, { 0x2c64, 0x27d },
	{ 0x2c6d, 0x251 }, { 0x2c6e, 0x271 }, { 0x2c6f, 0x250 }, { 0x2c70, 0x252 },
	{ 0x2c72, 0x2c73 }, { 0x2c75, 0x2c76 }, { 0x2c7e, 0x23f }, { 0x2c7f, 0x240 },
	{ 0x2cf2, 0x2cf3 }, { 0xa77d, 0x1d79 }, { 0xa78b, 0xa78c }, { 0xa78d, 0x265 },
	{ 0xa7aa, 0x266 }, { 0x10c7, 0x2d27 }, { 0x10cd, 0x2d2d }, { 0x376, 0x377 },
	{ 0x39c, 0xb5 }, { 0x392, 0x3d0 }, { 0x398, 0x3d1 }, { 0x3a6, 0x3d5 },
	{ 0x3a0, 0x3d6 }, { 0x39a, 0x3f0 }, { 0x3a1, 0x3f1 }, { 0x395, 0x3f5 },
	{ 0x3cf, 0x3d7 }, { 0, 0 }
};

#if IS_BIG_ENDIAN
/** Test for a bit in a wide-character; The characteristics are stored always in network byte order */
#   define ISwbit(bit)   (1 << (bit))
#else
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
#define WISLOWER(wc)   ((int)(((0x60U < (wint_t)(wc)) && ((wint_t)(wc) < 0x80U))))
/** Test if the wchar is a lowercase wide-character */
#define wislower(wc)   WISLOWER(((wint_t)(wc)))
/** Test if the wchar is a lowercase wide-character */
#define ISWLOWER(wc)   WISLOWER(((wint_t)(wc)))
/** Test if the wchar is a lowercase wide-character */
#define iswlower(wc)   WISLOWER(((wint_t)(wc)))
/** Test if the wchar is a lowercase wide-character */
#define islowerW(wc)   WISLOWER((wc))
/** Test if the wchar is a lowercase wide-character */
#define __iswlower_l(wc, l)   WISLOWER(((wint_t)(wc)))
/** Test if the wchar is a lowercase wide-character */
#define iswlower_l(wc, l)   WISLOWER(((wint_t)(wc)))
/** Test if the wchar is a uppercase wide-character */
#define WISUPPER(wc)   ((int)(((0x40U < (wint_t)(wc)) && ((wint_t)(wc) < 0x60U))))
/** Test if the wchar is a uppercase wide-character */
#define wisupper(wc)   WISUPPER(((wint_t)(wc)))
/** Test if the wchar is a uppercase wide-character */
#define ISWUPPER(wc)   WISUPPER(((wint_t)(wc)))
/** Test if the wchar is a uppercase wide-character */
#define iswupper(wc)   WISUPPER(((wint_t)(wc)))
/** Test if the wchar is a uppercase wide-character */
#define isupperW(wc)   WISUPPER((wc))
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
LIB_FUNC ATTR_CF int iswalpha(const wint_t wc) {
	if (PREDICT_LIKELY(wc < 0x20000U)) { return (int)(alpha_table[(unsigned int)(alpha_table[wc >> 8] * 32) + (unsigned int)((wc & 255) >> 3)] >> (wc & 7)) & 1; }
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
LIB_FUNC ATTR_CF int iswpunct(const wint_t wc) {
	if (PREDICT_LIKELY(wc < 0x20000U)) { return (int)(punct_table[(unsigned int)(punct_table[wc >> 8] * 32) + (unsigned int)((wc & 255) >> 3)] >> (wc & 7)) & 1; }
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
LIB_FUNC ATTR_CF int iswprint(const wint_t wc) {
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
#define iswblank(wc)   ((int)(((wint_t)(wc) == 0x20U) || ((wint_t)(wc) == 9U)))
/** Check if wide character is blank */
#define isblankW(wc)   iswblank((wc))
/** Check if wide character is blank */
#define __iswblank_l(wc, l)   iswblank(((wint_t)(wc)))
/** Check if wide character is blank */
#define iswblank_l(wc, l)   iswblank(((wint_t)(wc)))
/** Check if wide character is a control character */
LIB_FUNC ATTR_CF int iswcntrl(const wint_t wc) {
	return (int)((wc < 32) || ((wc - 0x7f) < 33) || ((wc - 0x2028) < 2) || ((wc - 0xfff9) < 3));
}
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
/** Check if wide character is a white-space character */
#define iswspace(wc)   ((int)(((wint_t)(wc)) && strchrW(wchar_spaces, ((wchar_t)(wc)))))
/** Check if wide character is a white-space character */
#define isspaceW(wc)   iswspace((wc))
/** Check if wide character is a white-space character */
#define __iswspace_l(wc, l)   iswspace(((wint_t)(wc)))
/** Check if wide character is a white-space character */
#define iswspace_l(wc, l)   iswspace(((wint_t)(wc)))
/** Check if wide character has graphical representation */
#define iswgraph(wc)   ((int)(!(iswspace(((wint_t)(wc))) && iswprint(((wint_t)(wc))))))
/** Check if wide character has graphical representation */
#define isgraphW(wc)   iswgraph((wc))
/** Check if wide character has graphical representation */
#define __iswgraph_l(wc, l)   iswgraph(((wint_t)(wc)))
/** Check if wide character has graphical representation */
#define iswgraph_l(wc, l)   iswgraph(((wint_t)(wc)))
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
LIB_FUNC NONNULL wctype_t wctype(const char* restrict property) {
	register int i = 1;
	const char* restrict p;
	const size_t _length = strlen(property);
	for (p = wchar_class_names; *p; i++, p += 6) {
		if (*property == *p && (!(strncmp(property, p, _length)))) { return i; }
	}
	return 0;
}


/** Tables indexed by a wide character are compressed through the use of a multi-level lookup.  The compression effect comes from blocks that do not need particular data and from blocks that can share their data */
LIB_FUNC ATTR_PURE NONNULL int wctype_table_lookup(const char* table, const uint32_t wc) {
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
LIB_FUNC ATTR_PURE NONNULL int wcwidth_table_lookup(const char* table, const uint32_t wc) {
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
LIB_FUNC ATTR_PURE NONNULL uint32_t wctrans_table_lookup(const char* table, const uint32_t wc) {
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
LIB_FUNC ATTR_NONNULL(1) wctype_t wctype_l(const char* property, const UNUSED locale_t l) {
	return wctype(property);
}
#define __wctype_l(property, l)   wctype_l((property), (l))


/** Checks whether `wc` has the property specified by `char_class` */
LIB_FUNC int iswctype(const wint_t wc, const wctype_t char_class) {
	switch ((int)char_class) {
		case WC_TYPE_ALNUM: return (int)iswalnum(wc);
		case WC_TYPE_ALPHA: return (int)iswalpha(wc);
		case WC_TYPE_BLANK: return (int)iswblank(wc);
		case WC_TYPE_CNTRL: return (int)iswcntrl(wc);
		case WC_TYPE_DIGIT: return (int)iswdigit(wc);
		case WC_TYPE_GRAPH: return (int)iswgraph(wc);
		case WC_TYPE_LOWER: return (int)iswlower(wc);
		case WC_TYPE_PRINT: return (int)iswprint(wc);
		case WC_TYPE_PUNCT: return (int)iswpunct(wc);
		case WC_TYPE_SPACE: return (int)iswspace(wc);
		case WC_TYPE_UPPER: return (int)iswupper(wc);
		case WC_TYPE_XDIGIT: return (int)iswxdigit(wc);
		default: return 0;
	}
	UNREACHABLE
}


/** Checks whether `wc` has the property specified by `char_class` */
LIB_FUNC int iswctype_l(const wint_t wc, const wctype_t char_class, const UNUSED __locale_t _locale) {
	if (PREDICT_UNLIKELY(char_class == (wctype_t)0)) { return 0; }
	return (int)wctype_table_lookup((const char*)char_class, wc);
}
#define __iswctype_l(wc, char_class, _locale)   iswctype_l((wc), (char_class), (_locale))
#define isWctype_l(wc, char_class, _locale)   iswctype_l((wc), (char_class), (_locale))
#define isctypeW_l(wc, char_class, _locale)   iswctype_l((wc), (char_class), (_locale))


LIB_FUNC ATTR_CF unsigned short get_char_typeW(const wchar_t ch) {
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

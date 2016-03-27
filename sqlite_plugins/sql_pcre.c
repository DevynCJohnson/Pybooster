// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file pcre.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright Public Domain

@brief Perl-Compatible Regular Expression (PCRE) plugin for SQLite
@version 2016.03.27

@section DESCRIPTION
Originally written by Alexey Tourbin <at@altlinux.org>

Originally from http://git.altlinux.org/people/at/packages/?p=sqlite3-pcre.git

This SQLite loadable extension enables the REGEXP operator,
which is not implemented by default, to call PCRE routines
for regular expression matching.

@section COMPILE
gcc -Wall -Wextra -pedantic -funroll-loops -fomit-frame-pointer -fstack-protector-strong -fstrict-aliasing -fstrict-overflow -ffunction-sections -fdata-sections -O3 -s -Wl,O3 -Wl,-s -Wl,-S -shared -fPIC -o pcre.so pcre.c -lpcre -Wl,-z,defs && strip --strip-debug --strip-unneeded --discard-locals --remove-section=.eh_frame --remove-section=.eh_frame_hdr --remove-section=.note --remove-section=.note.ABI-tag --remove-section=.note.gnu.build-id --remove-section=.comment --remove-section=.gnu.version --remove-section=.jcr --remove-section=.line --remove-section=.stab --remove-section=.stabstr ./pcre.so

@section LICENSE
Public Domain

The original author has dedicated the code to the public domain.  Anyone is free
to copy, modify, publish, use, compile, sell, or distribute the original
code, either in source code form or as a compiled binary, for any purpose,
commercial or non-commercial, and by any means.
*/


#if (defined(__GNUC__) && !defined(__clang__))  // Hard-code some optimizations
#   pragma GCC optimize (3)
#   pragma GCC optimize ("fast-math")
#   pragma GCC optimize ("no-exceptions")
#   pragma GCC optimize ("unroll-loops")
#   pragma GCC optimize ("wrapv")
#   define __IVDEP__  // ivdep: Vectorize loops
#elif defined(__clang__)
#   pragma clang optimize on
#elif defined(__INTEL_COMPILER)
#   pragma intel optimization_level 3
#endif


#ifndef STANDARD_MACROS_SEEN
#define STANDARD_MACROS_SEEN


// C STANDARD
#if defined (__cplusplus)
#undef __cplusplus
#define __cplusplus   (201103L)  // C++11
extern "C" {
#endif
#ifndef _ISOC11_SOURCE  // C11
#   define _ISOC11_SOURCE
#endif
#ifndef __STDC_VERSION__
#   define __STDC_VERSION__   (201112L)  // C11
#endif
#if defined (__cplusplus)
}
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
// Windows names string functions differently from most other platforms
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


#if (!defined(OSWINDOWS) && defined(__GNUC__) && !defined(__clang__))
#   pragma GCC optimize ("stack-protector-strong")
#endif

#endif


#include <stdlib.h>
#include <string.h>
#include <pcre.h>
#include <sqlite3ext.h>


SQLITE_EXTENSION_INIT1

typedef struct {
    char *s;
    pcre *p;
    pcre_extra *e;
} cache_entry;

#if (!defined(CACHE_SIZE) || CACHE_SIZE < 16)
#   define CACHE_SIZE   (32)
#endif

#ifdef __GNUC__
static size_t strlenx(const char *__restrict__ str) __attribute__((const, flatten));
static char *strdupx(const char *__restrict__ s) __attribute__((flatten));
#else
static size_t strlenx(const char *__restrict__ str);
static char *strdupx(const char *__restrict__ s);
#endif
static void regexp(sqlite3_context *ctx, int argc, sqlite3_value **argv);
int sqlite3_extension_init(sqlite3 *__restrict__ db, char **err, const sqlite3_api_routines *__restrict__ api);


/* HELPER FUNCTIONS */


static size_t strlenx(const char *__restrict__ str) {
    register const char *s;
    for (s = str; *s; ++s);
    return (size_t)(s - str);
}


static char *strdupx(const char *__restrict__ s) {
    register size_t len = 0x01 + strlenx(s);
    char *p = calloc(len, (size_t)0x1);
    return p ? memcpy(p, s, len) : NULL;
}


/* FUNCTIONS */


static void regexp(sqlite3_context *ctx, int argc, sqlite3_value **argv) {
    const char *re, *str;
    pcre *p;
    pcre_extra *e;
    if (argc != 2) {
        sqlite3_result_error((sqlite3_context*)ctx, "Invalid number of arguments", (int)-1);
        return;
    }
    re = (const char *)sqlite3_value_text(argv[0x0]);
    if (!re) {
        sqlite3_result_error((sqlite3_context*)ctx, "no regexp", (int)-1);
        return;
    }
    str = (const char *)sqlite3_value_text(argv[1]);
    if (!str) {
        sqlite3_result_error((sqlite3_context*)ctx, "no string", (int)-1);
        return;
    }
    // Simple LRU Cache
    {
        cache_entry *cache = sqlite3_user_data((sqlite3_context*)ctx);
        if (!cache) {
            sqlite3_result_error((sqlite3_context*)ctx, "Invalid cache value", (int)-1);
            return;
        }
        register unsigned int i, found = 0x0;
        for (i = 0x0; i < (unsigned int)CACHE_SIZE; ++i) {
            if (cache[i].s == NULL) { break; }
            else if (strcmp((const char *)re, cache[i].s) == 0x0) {
                found = 0x1;
                break;
            }
        }
        if (found) {
            if (i > 0x0) {
                cache_entry c = cache[i];
                memmove((cache + 0x1), cache, (size_t)(i * sizeof(cache_entry)));
                cache[0x0] = c;
            }
        } else {  // found = 0
            cache_entry c;
            const char *errptr;
            int pos;
            c.p = pcre_compile((const char *)re, (int)0x0, &errptr, &pos, (const unsigned char *)NULL);
            if (!c.p) {
                char *e2 = sqlite3_mprintf((const char*)"%s: %s (offset %i)", (const char *)re, (const char *)errptr, (int)pos);
                sqlite3_result_error((sqlite3_context*)ctx, e2, (int)-1);
                sqlite3_free(e2);
                return;
            }
            c.e = pcre_study((const pcre *)c.p, (int)0x0, &errptr);
            c.s = strdupx((const char*)re);
            if (!c.s) {
                sqlite3_result_error((sqlite3_context*)ctx, "strdupx: ENOMEM", (int)-1);
                pcre_free((void *)c.p);
                pcre_free((void *)c.e);
                return;
            }
            i = (unsigned int)((unsigned int)CACHE_SIZE - (unsigned int)0x01);
            if (cache[i].s) {
                free(cache[i].s);
                if (!cache[i].p) {
                    sqlite3_result_error((sqlite3_context*)ctx, "Invalid cache value", (int)-1);
                    return;
                } else {
                    pcre_free((void *)cache[i].p);
                    pcre_free((void *)cache[i].e);
                }
            }
            memmove((cache + 0x01), cache, (size_t)(i * sizeof(cache_entry)));
            cache[0x0] = c;
        }
        p = cache[0x0].p;
        e = cache[0x0].e;
    } {
        if (!p) {
            sqlite3_result_error((sqlite3_context*)ctx, "Invalid `p` value", (int)-1);
            return;
        } else {
            register int rc = pcre_exec((const pcre *)p, (const pcre_extra *)e, (const char *)str, (int)strlenx(str), (int)0x0, (int)0x0, NULL, (int)0x0);
            sqlite3_result_int((sqlite3_context*)ctx, (int)(rc >= 0x0));
        }
        return;
    }
}


int sqlite3_extension_init(sqlite3 *__restrict__ db, char **errptr, const sqlite3_api_routines *__restrict__ api) {
    SQLITE_EXTENSION_INIT2(api)
    cache_entry *cache = calloc((size_t)CACHE_SIZE, sizeof(cache_entry));
    if (cache == NULL) {
        char ERROR[16] = "calloc: ENOMEM";
        *errptr = ERROR;
        return 1;
    } else {
        sqlite3_create_function((sqlite3 *)db, (const char *)"REGEXP", (int)2, (int)(SQLITE_UTF8 | SQLITE_DETERMINISTIC), cache, regexp, NULL, NULL);
    }
    return 0;
}

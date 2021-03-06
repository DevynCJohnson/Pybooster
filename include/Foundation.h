// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
/**
@brief Header for simple yet essential macros
@file Foundation.h
@version 2020.02.26
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This file defines macros for detecting the compiler, C version, C library, platform, etc. as well as diagnostics

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

@section Supports
Compilers:
 - GNU-GCC
 - Clang & LLVM
Architectures:
 - x86-64
Operating Systems:
 - Linux

@section Standard_C_Library
 - assert.h
 - complex.h
 - ctype.h
 - errno.h
 - fenv.h
 - float.h
 - inttypes.h
 - iso646.h
 - limits.h
 - locale.h
 - math.h
 - setjmp.h
 - signal.h
 - stdalign.h
 - stdarg.h
 - stdatomic.h
 - stdbool.h
 - stddef.h
 - stdint.h
 - stdio.h
 - stdlib.h
 - stdnoreturn.h
 - string.h
 - tgmath.h
 - threads.h
 - time.h
 - uchar.h
 - wchar.h
 - wctype.h

@section POSIX_C_Library
 - aio.h
 - arpa/inet.h
 - assert.h
 - complex.h
 - cpio.h
 - ctype.h
 - dirent.h
 - dlfcn.h
 - errno.h
 - fcntl.h
 - fenv.h
 - float.h
 - fmtmsg.h
 - fnmatch.h
 - ftw.h
 - glob.h
 - grp.h
 - iconv.h
 - inttypes.h
 - iso646.h
 - langinfo.h
 - libgen.h
 - limits.h
 - locale.h
 - math.h
 - monetary.h
 - mqueue.h
 - ndbm.h
 - net/if.h
 - netdb.h
 - netinet/in.h
 - netinet/tcp.h
 - nl_types.h
 - poll.h
 - pthread.h
 - pwd.h
 - regex.h
 - sched.h
 - search.h
 - semaphore.h
 - setjmp.h
 - signal.h
 - spawn.h
 - stdarg.h
 - stdbool.h
 - stddef.h
 - stdint.h
 - stdio.h
 - stdlib.h
 - string.h
 - strings.h
 - stropts.h
 - sys/ipc.h
 - sys/mman.h
 - sys/msg.h
 - sys/resource.h
 - sys/select.h
 - sys/sem.h
 - sys/shm.h
 - sys/socket.h
 - sys/stat.h
 - sys/statvfs.h
 - sys/time.h
 - sys/times.h
 - sys/types.h
 - sys/uio.h
 - sys/un.h
 - sys/utsname.h
 - sys/wait.h
 - syslog.h
 - tar.h
 - termios.h
 - tgmath.h
 - time.h
 - trace.h
 - ulimit.h
 - unistd.h
 - utime.h
 - utmpx.h
 - wchar.h
 - wctype.h
 - wordexp.h

@section BSD_Library
 - db.h
 - err.h
 - fts.h
 - sys/queue.h
 - sys/tree.h
 - vis.h
 - stdio.h: fgetln()
 - stdlib.h: arc4random(), daemon(), radixsort()
 - string.h: strlcat() and strlcpy()

@section Other_C_Libraries
 - reent.h (Newlib)
 - unctrl.h (Newlib)

@section C_Plus_Plus_Standard_Library
 - array
 - deque
 - forward_list
 - list
 - map
 - queue
 - set
 - stack
 - unordered_map
 - unordered_set
 - vector
 - fstream
 - iomanip
 - ios
 - iosfwd
 - iostream
 - istream
 - ostream
 - sstream
 - streambuf
 - atomic
 - condition_variable
 - future
 - mutex
 - thread
 - algorithm
 - bitset
 - chrono
 - codecvt
 - complex
 - exception
 - functional
 - initializer_list
 - iterator
 - limits
 - locale
 - memory
 - new
 - numeric
 - random
 - ratio
 - regex
 - stdexcept
 - string
 - system_error
 - tuple
 - typeindex
 - typeinfo
 - type_traits
 - utility
 - valarray

@section Linux_API_Headers
 - /usr/include/asm/
 - /usr/include/asm-generic/
 - /usr/include/drm/
 - /usr/include/linux/
 - /usr/include/mtd/
 - /usr/include/rdma/
 - /usr/include/scsi/
 - /usr/include/sound/
 - /usr/include/video/
 - /usr/include/xen/

@section Standards_&_Features
 - POSIX.1-1988: System interfaces and headers
 - POSIX.1-1990: POSIX.1-1988 update
 - POSIX.1b-1993: Realtime extensions
 - POSIX.1c-1996: Threads extensions
 - POSIX.2-1992: Shell and utilities
 - POSIX.2a-1992: Interactive shell and utilities
 - POSIX.1–2001: POSIX.1-1990 through POSIX.2a-1992 updates
 - POSIX.1-2004: POSIX.1-2001 update
 - XPG3: Superset of POSIX.1-1988 containing utilities from SVID3
 - XPG4: Superset of POSIX.1-1990, POSIX.2-1992, & POSIX.2a-1992 containing extensions to POSIX standards from XPG3
 - SUS (XPG4v2): Superset of XPG4 containing historical BSD interfaces widely used by common application packages
 - SUSv2: Superset of SUS extended to support POSIX.1b-1993, POSIX.1c-1996, & ISO/IEC 9899 (C Standard) Amendment 1
 - SUSv3: Same as POSIX.1–2001
 - XNS4: Sockets and XTI interfaces
 - XNS5: Superset and LP64-clean derivative of XNS4
 - ISO/IEC 11404: General Purpose Datatypes (GPD)
 - ISO/IEC 10646: Universal Coded Character Set (UCS)
 - ISO/IEC 10967: Language independent arithmetic (LIA)
 - ISO/IEC 80000: International System of Quantities (ISQ)
 - ISO/IEC/IEEE 60559:2011: Same as IEEE 754
 - ISO/IEC TS 18661-1:2014: IEC 60559:2011-compatible binary floating-point arithmetic
 - ISO/IEC TS 18661-2:2015: IEC 60559:2011-compatible decimal floating point arithmetic
 - ISO/IEC TS 18661-3:2015: IEC 60559:2011-compatible interchange and extended floating-point types
 - IEC 559: Same as IEEE 754-1985
 - IEEE 754-1985: Standard for floating-point computation
 - IEEE 754-2008: Includes IEEE 754-1985 & IEEE 854-1987
 - IEEE 854-1987: Standard for Radix-Independent Floating-Point Arithmetic (with radix 2 or radix 10)
 - IEEE 1588: Precision Time Protocol (PTP)

@section Specifications
These are defined by the user and/or the compiler to specify the desired environment:
 - __STRICT_ANSI__: ISO Standard C
 - _ISOC99_SOURCE: Extensions to ISO C89 from ISO C99
 - _ISOC11_SOURCE: Extensions to ISO C99 from ISO C11
 - _POSIX_SOURCE: IEEE Std 1003.1
 - _POSIX_C_SOURCE
	- if ==1, like _POSIX_SOURCE (IEEE Std 1003.1);
	- if >=2, add IEEE Std 1003.2;
	- if >=199309L, add IEEE Std 1003.1b-1993
	- if >=199506L, add IEEE Std 1003.1c-1995
	- if >=200112L, all of IEEE 1003.1-2004
	- if >=200809L, all of IEEE 1003.1-2008
 - _XOPEN_SOURCE: Includes POSIX and XPG
	- 500, Single Unix conformance is wanted
	- 600, Sixth revision
	- 700, Seventh revision
 - _XOPEN_SOURCE_EXTENDED: XPG extensions and X/Open Unix extensions
 - _LARGEFILE_SOURCE: Large file I/O
 - _LARGEFILE64_SOURCE: Additional functionality from LFS for large files
 - _FILE_OFFSET_BITS=N: Select default filesystem interface
 - _ATFILE_SOURCE: Additional *at interfaces
 - _GNU_SOURCE: All of the above, plus GNU extensions
 - _DEFAULT_SOURCE: The default set of features (taking precedence over __STRICT_ANSI__)
 - _REENTRANT: Enable reentrant features and functions (thread-safety is not the same as reentrancy)
 - _THREAD_SAFE: Enable features for thread-safety
 - _FORTIFY_SOURCE: If above 0, additional security measures are defined (according to the level)

@section Setting_Specifications
These may be defined by this file and are used by the header files to decide what to declare or define:
 - __USE_ISOC11: Define ISO C11 symbols
 - __USE_ISOC99: Define ISO C99 symbols
 - __USE_ISOC95: Define ISO C90 AMD1 (C95) symbols
 - __USE_POSIX: Define IEEE Std 1003.1 symbols
 - __USE_POSIX2: Define IEEE Std 1003.2 symbols
 - __USE_POSIX199309: Define IEEE Std 1003.1, and .1b symbols
 - __USE_POSIX199506: Define IEEE Std 1003.1, .1b, .1c and .1i symbols
 - __USE_XOPEN: Define XPG symbols
 - __USE_XOPEN_EXTENDED: Define X/Open Unix symbols
 - __USE_UNIX98: Define Single Unix V2 symbols
 - __USE_XOPEN2K: Define XPG6 symbols
 - __USE_XOPEN2KXSI: Define XPG6 XSI symbols
 - __USE_XOPEN2K8: Define XPG7 symbols
 - __USE_XOPEN2K8XSI: Define XPG7 XSI symbols
 - __USE_LARGEFILE: Define correct standard I/O symbols
 - __USE_LARGEFILE64: Define LFS symbols with separate names
 - __USE_FILE_OFFSET64: Define 64-bit interface as default
 - __USE_MISC: Define symbols from 4.3BSD or System V Unix
 - __USE_ATFILE: Define *at interfaces and AT_* constants for them
 - __USE_GNU: Define GNU extensions
 - __USE_REENTRANT: Define reentrant *_r functions
 - __USE_FORTIFY_LEVEL: Additional security measures used, according to level

@section POSIX_VERSION
 - 198808L
 - 199009L
 - 199209L
 - 199309L
 - 199506L
 - 200112L
 - 200809L
 - 201712L

@section ANSI
The `-ansi` switch to the GNU C compiler, and standards conformance options such as `-std=c99`, define __STRICT_ANSI__. If none of these are defined, or if _DEFAULT_SOURCE is defined, the default is to have _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to 200809L, as well as enabling miscellaneous functions from BSD and SVID. If more than one of these are defined, they accumulate. For example __STRICT_ANSI__, _POSIX_SOURCE, and _POSIX_C_SOURCE together give you ISO C, 1003.1, and 1003.2, but nothing else.

@section GCC-Builtins
 - https://gcc.gnu.org/onlinedocs/gcc/Target-Builtins.html
 - https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
 - https://gcc.gnu.org/onlinedocs/gcc/Cilk-Plus-Builtins.html
 - https://gcc.gnu.org/onlinedocs/gcc/x86-Built-in-Functions.html

@section Helpful_Terminal_Commands
 - echo | gcc -dM -E -x c - | cut -c 9- | sort
 - echo | gcc -fwrapv -march=haswell -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld -dM -E -x c - | cut -c 9- | sort
 - echo | clang -dM -E -x c - | cut -c 9- | sort
 - echo | llvm-gcc -dM -E -x c - | cut -c 9- | sort
 - echo | aarch64-linux-gnu-gcc -dM -E -x c - | cut -c 9- | sort
 - echo | arm-linux-gnueabihf-gcc -march=armv6zk -mtune=arm1176jzf-s -mfloat-abi=hard -mlittle-endian -mfpu=vfp -marm -mtp=auto -dM -E -x c - | cut -c 9- | sort
 - echo | arm-linux-gnueabihf-gcc -mfp16-format=ieee -dM -E -x c - | cut -c 9- | sort
 - echo | i686-w64-mingw32-gcc -dM -E -x c - | cut -c 9- | sort
 - echo | hppa-linux-gnu-gcc -dM -E -x c - | cut -c 9- | sort
 - echo | mips-linux-gnu-gcc -dM -E -x c - | cut -c 9- | sort
 - echo | mipsel-linux-gnu-gcc -dM -E -x c - | cut -c 9- | sort
 - echo | powerpc-linux-gnu-gcc -dM -E -x c - | cut -c 9- | sort
 - echo | powerpc64le-linux-gnu-gcc -dM -E -x c - | cut -c 9- | sort
 - echo | s390x-linux-gnu-gcc -dM -E -x c - | cut -c 9- | sort
 - echo | sh4-linux-gnu-gcc -dM -E -x c - | cut -c 9- | sort
 - echo | x86_64-w64-mingw32-gcc -m64 -dM -E -x c - | cut -c 9- | sort
 - echo | gcc -dI -E -  # View include directives
 - echo | gcc -fdump-passes -x c -  ## View available dump-passes
 - gcc -dumpspecs  # View dumpspecs
 - gcc -Q -v  # List hard-coded setup (configuration options)
 - strings `which gcc`
 - gcc --print-search-dirs
 - gcc --print-multiarch
 - pkg-config --cflags --libs cairo  # List options needed to link to the library
 - pkg-config --cflags --libs pango
 - pkg-config --cflags --libs glib-2.0
 - pkg-config --cflags --libs gobject-2.0
 - pkg-config --cflags --libs gobject-introspection-1.0
 - gcc -Wl,-y,FUNCTION file.c  # List references and definitions of FUNCTION

@section Machine_Modes
 - BI - 1 Bit
 - QI - Quarter Integer; 1 byte (8-bits)
 - HI - Half Integer; 2 bytes (16-bits)
 - PSI - Partial Single Integer; 4 bytes; not all bits used
 - SI - Single Integer; 4 bytes (32-bits)
 - PDI - Partial Double Integer; 8 bytes; not all bits used
 - DI - Double Integer; 8 bytes (64-bits)
 - TI - Tetra Integer; 16 bytes (128-bits)
 - OI - Octa Integer; 32 bytes (256-bits)
 - XI - Hexadeca Integer; 64 bytes (512-bits)
 - QF - Quarter Floating; 1 byte quarter-precision float-point
 - HF - Half Floating; 2 byte half-precision float-point
 - TQF - Three Quarter Floating; 3 byte three-quarter-precision float-point
 - SF - Single Floating; 4 byte single-precision float-point
 - DF - Double Floating; 8 byte double-precision float-point
 - XF - Extended Floating; 12 byte (96-bit) extended-precision float-point; Only 10 bytes (80 bits) are used
 - TF - Tetra Floating; 16 byte (128-bits) tetra-precision float-point
 - SD - Single Decimal Floating; 4 byte (32-bit) decimal float-point
 - DD - Double Decimal Floating; 8 byte (64-bit) decimal float-point
 - TD - Tetra Decimal Floating; 4 byte (128-bit) decimal float-point
 - CQI - Complex Quarter Integer; 2 bytes (16-bits); Pair of integer values
 - CHI - Complex Half Integer; 4 bytes (32-bits); Pair of integer values
 - CSI - Complex Single Integer; 8 bytes (64-bits); Pair of integer values
 - CDI - Complex Double Integer; 16 bytes (128-bits); Pair of integer values
 - CTI - Complex Tetra Integer; 32 bytes (256-bits); Pair of integer values
 - COI - Complex Octa Integer; 64 bytes (512-bits); Pair of integer values
 - QC - Quarter Complex; 2-byte quarter-precision complex float-point; Pair of FP values
 - HC - Half Complex; 4-byte half-precision complex float-point; Pair of FP values
 - SC - Single Complex; 8-byte single-precision complex float-point; Pair of FP values
 - DC - Double Complex; 16-byte double-precision complex float-point; Pair of FP values
 - XC - Extended Complex; 32-byte extended-precision complex float-point; Pair of FP values
 - TC - Tetra Complex; 64-byte tetra-precision complex float-point; Pair of FP values
 - KC - Complex __float128 (PowerPC only)
 - IC - Complex __ibm128 (PowerPC only)
 - QQ - Quarter-Fractional; 1-byte signed fractional number
 - HQ - Half-Fractional; 2-byte signed fractional number
 - SQ - Single-Fractional; 4-byte (32-bit) signed fractional number
 - DQ - Double-Fractional; 8-byte (64-bit) signed fractional number
 - TQ - Tetra-Fractional; 16-byte (128-bit) signed fractional number
 - UQQ - Unsigned Quarter-Fractional; 1-byte unsigned fractional number
 - UHQ - Unsigned Half-Fractional; 2-byte unsigned fractional number
 - USQ - Unsigned Single-Fractional; 4-byte (32-bit) unsigned fractional number
 - UDQ - Unsigned Double-Fractional; 8-byte (64-bit) unsigned fractional number
 - UTQ - Unsigned Tetra-Fractional; 16-byte (128-bit) unsigned fractional number
 - HA - Half-Accumulator; 2-byte (16-bit) signed accumulator
 - SA - Single-Accumulator; 4-byte (32-bit) signed accumulator
 - DA - Double-Accumulator; 8-byte (64-bit) signed accumulator
 - TA - Tetra-Accumulator; 16-byte (128-bit) signed accumulator
 - UHA - Unsigned Half-Accumulator; 2-byte (16-bit) unsigned accumulator
 - USA - Unsigned Single-Accumulator; 4-byte (32-bit) unsigned accumulator
 - UDA - Unsigned Double-Accumulator; 8-byte (64-bit) unsigned accumulator
 - UTA - Unsigned Tetra-Accumulator; 16-byte (128-bit) unsigned accumulator
 - CC - Condition Code
 - BLK - Block
 - VOID - Void
 - P - Address mode
 - V2SI - Vector; 2 single integers
 - V4SF - Vector; 4 single-precision floats
 - V4SI - Vector; 4 single integers
 - V8QI - Vector; 8 8-bit integers
 - BND32 - 32-bit pointer bound
 - BND64 - 64-bit pointer bound
 - word - Word-sized integer

@section Intel_Intrinsics
 - __m64 - 2-float vector; MMX/XMM register
 - __m128 - 4-float vector; SSE register
 - __m128d - 2-double vector; SSE register
 - __m128i - integers; SSE register
 - __m256 - 8-float vector; AVX/YMM register
 - __m256d - 4-double vector; AVX/YMM register
 - __m256i - integers; AVX/YMM register

@section Datamodels
 - "I" int type
 - "L" represents long type
 - "P" represents the pointer type

@section Datamodel_Systems
 - IP16 Platforms: PDP-11 Unix
 - ILP32 Platforms: IBM370 and VAX Unix
 - ILP32LL/ILP32LL64 Platforms: Windows-32 and Convex
 - ILP64 Platforms: Solaris on SPARC64
 - LP64/I32LP64 Platforms: Solaris, Linux, BSD, OS X, and z/OS
 - LLP64/IL32P64 Platforms: Windows-64
 - SILP64 Platforms: Classic UNICOS

@section Datamodel_Definitions
 - ILP32: int, long, pointer = 32;
 - LP32: short, int = 16; long, pointer = 32
 - ILP64: short = 16; int, long, long long, pointer = 64
 - LP64/I32LP64: short = 16; int = 32; long, long long, pointer = 64
 - LLP64/IL32P64/P64: short = 16; int, long = 32; long long, pointer = 64
 - SILP64: short, int, long, long long, pointer = 64

@section Datatype_Info
 - __S<SIZE>_TYPE: signed
 - __U<SIZE>_TYPE: unsigned
 - 16: natural 16-bit type (always `short`)
 - 32: natural 32-bit type (always `int`)
 - 64: natural 64-bit type (`long` or `long long`)
 - LONG32: 32-bit type (traditionally `long`)
 - WORD: natural type of WORDSIZE bits
 - LONGWORD: WORDSIZE bits (traditionally `long`)
 - `int` is always 32 bits
 - `long` is always word/address size
 - `long long` is always 64 bits

@section Primary_Fixed-point_Datatypes
 - short _Fract
 - _Fract
 - long _Fract
 - short _Accum
 - _Accum
 - long _Accum

@section Saturating_Fixed-point_Datatypes
 - _Sat short _Fract
 - _Sat _Fract
 - _Sat long _Fract
 - _Sat short _Accum
 - _Sat _Accum
 - _Sat long _Accum

@section Accumulator_Fixed-point_Datatypes
 - short _Accum
 - _Accum
 - long _Accum
 - _Sat short Accum
 - _Sat _Accum
 - _Sat long Accum

@section Fixed-point_Datatype_Suffixes
 - hr   signed short _Fract
 - r   signed _Fract
 - lr   signed long _Fract
 - llr   signed long long _Fract
 - uhr   unsigned short _Fract
 - ur   unsigned _Fract
 - ulr   unsigned long _Fract
 - ullr   unsigned long long _Fract
 - hk   signed short _Accum
 - k   signed _Accum
 - lk   signed long _Accum
 - llk   signed long long _Accum
 - uhk   unsigned short _Accum
 - uk   unsigned _Accum
 - ulk   unsigned long _Accum
 - ullk   unsigned long long _Accum

@section Strings_&_Characters
 - ASCII: 7-bit encoding for 128 characters
 - Unicode: 32-bit encoding (136755 characters as of v10.0)
 - Byte Order Mark (BOM): Unicode character indicating the endianness and Unicode encoding
	1. UTF-8: 0xef 0xbb 0xbf (ï»¿)
	2. UTF-16: 0xfe 0xff (þÿ)
 - Multibyte String: Character array containing characters represented with more than one byte
 - Wide Character: A 16 or 32-bit character
 - Wide String: A string of wide-characters (wchar_t)
 - UTF-8: 1-4 byte encoding for Unicode (1112064 characters)
	1. U+0000 - U+007f: 0xxxxxxx
	2. U+0080 - U+07ff: 110xxxxx 10xxxxxx
	3. U+0800 - U+ffff: 1110xxxx 10xxxxxx 10xxxxxx
	4. U+10000 - U+10ffff: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 - UTF-16: 1-2 16-bit encoding; big-endian by default (1112064 characters)
	1. U+0000 - U+d7ff & U+e000 - U+ffff
	2. U+10000 - U+10ffff; Surrogate Pairs are two values each in the range 0xd800-0xdfff
	 - 0x010000 is subtracted from the code point
	 - High surrogate: 0xd800 is added to the top ten bits (range 0xd800-0xdbff)
	 - low surrogate: 0xdc00 is added to the bottom ten bits (range 0xdc00-0xdfff)
 - UTF-16BE: Big-endian UTF-16 (BOM = 0xfeff)
 - UTF-16LE: Little-endian UTF-16 (BOM = 0xfeff)
 - UTF-32: 32-bit encoding (2147483648 characters; sign-bit zero & unused)
 - UCS-2: 2 byte Unicode encoding (65535 characters)
 - UCS-2BE: 2 byte big-endian Unicode encoding (65535 characters)
 - UCS-2LE: 2 byte little-endian Unicode encoding (65535 characters)
 - UCS-4: Same as UTF-32

@section Character_&_String_Literals
 - L"": Wide-character String; wchar_t[]
 - u8"": UTF-8 String; char[]
 - u"": UTF-16 String; char16_t[]
 - U"": UTF-32/UCS-4 String; char32_t[]
 - L'': Wide-character; wchar_t
 - u'': UTF-16 Character; char16_t
 - U'': UTF-32/UCS-4 Character; char32_t
 - \\x##: 8-bit character specified by two hexadecimal digits
 - \\ooo: 8-bit character specified by three octal digits
 - \\u####: 16-bit Unicode character specified by four hexadecimal digits
 - \\U########: 32-bit Unicode character specified by eight hexadecimal digits

@section Floating-Point_Constant_Literals
 - 5.3876E4 = 53876
 - 4E-11 = 0.00000000004
 - 1e+5 = 100000
 - 7.321E-3 = 0.007321
 - 3.2e+4 = 32000
 - 0.5e-6 = 0.0000005
 - 0.45 = 0.45
 - 6.e10 = 60000000000

@section Types_of_Numbers
https://en.wikipedia.org/wiki/List_of_types_of_numbers
 - NATURAL/CARDINAL NUMBER (ℕ): Counting numbers (0, 1, 2, 3, …), are called natural numbers. (https://en.wikipedia.org/wiki/Natural_number)
 - INTEGER (ℤ): A number that can be written without a fractional component. For example, 17, 3, 0, and -1024 are integers, while 9.73, 5 1⁄2, and √2 are not integers. (https://en.wikipedia.org/wiki/Integer)
 - RATIONAL NUMBER (ℚ): Any number that can be expressed as the quotient or fraction p/q of two integers, p and q, with the denominator, q, not equal to zero. Since q may be equal to 1, every integer is a rational number. The decimal expansion of a rational number always either terminates after a finite number of digits or begins to repeat the same finite sequence of digits over and over. (https://en.wikipedia.org/wiki/Rational_number)
 - TRANSCENDENTAL NUMBER: A real or complex number that is not algebraic; that is, it is not a root of a non-zero polynomial equation with rational coefficients. The best-known transcendental numbers are π and e. (https://en.wikipedia.org/wiki/Transcendental_number)
 - REAL NUMBER (ℝ): A value that represents a quantity along a continuous line. The real numbers include all the rational numbers, such as the integer -5 and the fraction 4/3, all the irrational numbers, such as √2 (1.41421356…) and all transcendental numbers, such as π (3.14159265…). (https://en.wikipedia.org/wiki/Real_number)
 - INFINITESIMAL NUMBERS: Group of numbers that are infinitely small (i.e. the numbers after the decimal-point go on without stopping). (https://en.wikipedia.org/wiki/Infinitesimal)
 - HYPERREAL NUMBERS: Group that contains infinity and infinitesimal numbers. (https://en.wikipedia.org/wiki/Hyperreal_number)
 - SURREAL NUMBER: Group that contains real numbers and hyperreal numbers. (https://en.wikipedia.org/wiki/Surreal_number)
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

@section Parallel_Computing_APIs_&_Extensions
- Cilk: C extension for multithreaded parallel computing
- Open Accelerators (OpenACC): Standard designed to simplify parallel programming of heterogeneous CPU/GPU systems
- Open Computing Language (OpenCL): Framework for writing programs that execute across heterogeneous platforms consisting of CPUs, GPUs, Digital Signal Processors (DSPs), Field-Programmable Gate Arrays (FPGAs), and other processors/hardware-accelerators
- Open Graphics Library (OpenGL): API for rendering 2D/3D vector graphics
- Open Hybrid Multicore Parallel Programming (OpenHMPP): Programming standard for heterogeneous computing based on compiler directives
- Open Multi-Processing (OpenMP): API that supports multi-platform shared memory multiprocessing programming for CPUs

@section Cilk_Documentation
 - https://www.cilkplus.org/
 - https://www.cilkplus.org/docs/doxygen/include-dir/
 - Intel Cilk Plus: https://software.intel.com/en-us/node/522579

@section Intel_Documentation
 - Automatic Vectorization: https://software.intel.com/en-us/node/522569
 - Graphics Technology: https://software.intel.com/en-us/node/522438
 - High-Level Optimization (HLO): https://software.intel.com/en-us/node/522438
 - Intel Math Library: https://software.intel.com/en-us/node/522652
 - Interprocedural Optimization (IPO): https://software.intel.com/en-us/node/522666
 - OpenMP Support: https://software.intel.com/en-us/node/522678

@section Float-Point_Documentation
 - Minifloat - https://en.wikipedia.org/wiki/Minifloat
 - Half-precision (binary16) - https://en.wikipedia.org/wiki/Half-precision_floating-point_format
 - Single-precision (binary32) - https://en.wikipedia.org/wiki/Single-precision_floating-point_format
 - Double-precision (binary64) - https://en.wikipedia.org/wiki/Double-precision_floating-point_format
 - Quadruple-precision (binary128) - https://en.wikipedia.org/wiki/Quadruple-precision_floating-point_format
 - Octuple-precision (binary256) - https://en.wikipedia.org/wiki/Octuple-precision_floating-point_format
 - Decimal32 - https://en.wikipedia.org/wiki/Decimal32_floating-point_format
 - Decimal64 - https://en.wikipedia.org/wiki/Decimal64_floating-point_format
 - Decimal128 - https://en.wikipedia.org/wiki/Decimal128_floating-point_format
 - IBM Floating Point Architecture - https://en.wikipedia.org/wiki/IBM_Floating_Point_Architecture

@section Metric_Units_for_Decimal_Data_Units
 - Value	Abbr	Name
 - 1000		kB		Kilobyte
 - 1000^2	MB		Megabyte
 - 1000^3	GB		Gigabyte
 - 1000^4	TB		Terabyte
 - 1000^5	PB		Petabyte
 - 1000^6	EB		Exabyte
 - 1000^7	ZB		Zettabyte
 - 1000^8	YB		Yottabyte

@section ISO_IEC_80000_Units_for_Binary_Data_Units
 - Value	Abbr	Name
 - 1024		KiB		Kibibyte
 - 1024^2	MiB		Mebibyte
 - 1024^3	GiB		Gibibyte
 - 1024^4	TiB		Tebibyte
 - 1024^5	PiB		Pebibyte
 - 1024^6	EiB		Exbibyte
 - 1024^7	ZiB		Zebibyte
 - 1024^8	YiB		Yobibyte
*/


/* DIAGNOSTICS */


#ifndef MACROS_DIAGNOSTICS_H
/** If defined, the macros diagnostics header is already included/present. The included macros tests to ensure that `int` is 4 bytes (32-bits) in size, the space character is 0x20 in ASCII hexadecimal, etc.. If a test fails, the compilation will stop and an error message will be provided. */
#define MACROS_DIAGNOSTICS_H   (1)


#ifdef __STDC_NO_ATOMICS__
#   error   "Atomics are required to use this library!"
#endif


// DETERMINE CHARACTER-SET

#define HOST_CHARSET_UNKNOWN   0
#define HOST_CHARSET_ASCII   1
#define HOST_CHARSET_EBCDIC   2
#if (' ' == 0x20 && '0' == 0x30 && 'A' == 0x41 && 'a' == 0x61 && '!' == 0x21)
#   define HOST_CHARSET   HOST_CHARSET_ASCII
#   define IS_HOST_CHARSET_ASCII   1
#   define IS_HOST_CHARSET_EBCDIC   0
#elif (' ' == 0x40 && '0' == 0xf0 && 'A' == 0xc1 && 'a' == 0x81 && '!' == 0x5a)
#   define HOST_CHARSET   HOST_CHARSET_EBCDIC
#   define IS_HOST_CHARSET_ASCII   0
#   define IS_HOST_CHARSET_EBCDIC   1
#   error   "The host character set is EBCDIC (must be UTF-8)!"
#else
#   define HOST_CHARSET   HOST_CHARSET_UNKNOWN
#   error   "Unrecognized host character set (must be UTF-8)!"
#endif


// OPTIMIZATION MACROS (__OPTIMIZE__)

#if (defined(SSO_OPT) && (!defined(OPT_SSO)))
#   define OPT_SSO   1
#endif
#if (defined(SPEED_OPT) && (!defined(OPT_SPEED)))
#   define OPT_SPEED   1
#endif
#if ((defined(OPT_SPEED) || defined(OPT_SSO)) && defined(OPT_ACCURACY))
#   error   "Cannot optimize for both speed and accuracy!"
#endif
#if (defined(OPT_SPEED) && (!defined(OPT_SSO)))
#   define OPT_SSO   1
#endif
#if ((defined(OPT_SIZE) || defined(PREFER_SIZE_OVER_SPEED) || defined(__OPTIMISE_SPACE)) && (!defined(__OPTIMIZE_SIZE__)))
#   define __OPTIMIZE_SIZE__   2
#elif ((defined(__OPTIMIZE_SIZE__) || defined(PREFER_SIZE_OVER_SPEED) || defined(__OPTIMISE_SPACE)) && (!defined(OPT_SIZE)))
#   define OPT_SIZE   2
#endif
#if ((defined(OPT_SPEED) || defined(OPT_SSO)) && defined(OPT_SIZE))
#   error   "Cannot optimize for both speed and size!"
#elif (defined(OPT_ACCURACY) && defined(OPT_SIZE))
#   error   "Cannot optimize for both accuracy and size!"
#endif
#if ((defined(__OPTIMIZE__) || defined(__OPTIMIZE_SIZE__) || defined(OPT_SIZE) || defined(PREFER_SIZE_OVER_SPEED)) && (!defined(OPT_CODE)))
#   define OPT_CODE   1
#endif
#if (defined(__OPTIMIZE__) && (!defined(IS_OPT_0)))
#   define IS_OPT_0   (__OPTIMIZE__ == 0)
#elif (!(defined(__OPTIMIZE__) || defined(IS_OPT_0)))
#   define IS_OPT_0   0
#endif
#if (defined(__OPTIMIZE__) && (!defined(IS_OPT_1)))
#   define IS_OPT_1   (__OPTIMIZE__ == 1)
#elif (!(defined(__OPTIMIZE__) || defined(IS_OPT_1)))
#   define IS_OPT_1   0
#endif
#if (defined(__OPTIMIZE__) && (!defined(IS_OPT_2)))
#   define IS_OPT_2   (__OPTIMIZE__ == 2)
#elif (!(defined(__OPTIMIZE__) || defined(IS_OPT_2)))
#   define IS_OPT_2   0
#endif
#if (defined(__OPTIMIZE__) && (__OPTIMIZE__ > 0) && (!defined(IS_OPT_OVER_0)))
#   define IS_OPT_OVER_0   1
#elif (!(defined(__OPTIMIZE__) || defined(IS_OPT_OVER_0)))
#   define IS_OPT_OVER_0   0
#endif


#endif  // MACROS_DIAGNOSTICS_H


/* IMPORTANT CONSTANTS */


#if (!(defined(IMPORTANT_CONSTANTS_H) || defined(_IMPORTANT_CONSTANTS_H)))
#define IMPORTANT_CONSTANTS_H   (1)
#define _IMPORTANT_CONSTANTS_H   (1)


// DATA MEASUREMENTS

/** Number of bytes in a kibibyte */
#define KBYTE   1024
/** Number of bytes in a kibibyte */
#define KIBIBYTE   1024
/** Number of bits in a kibibyte */
#define BITS_PER_KIBIBYTE   8192
/** Number of bytes in a mebibyte */
#define MBYTE   1048576
/** Number of bytes in a mebibyte */
#define MEBIBYTE   1048576
/** Number of bits in a mebibyte */
#define BITS_PER_MEBIBYTE   8388608
/** Number of bytes in a gibibyte */
#define GBYTE   1073741824
/** Number of bytes in a gibibyte */
#define GIBIBYTE   1073741824
/** Number of bits in a gibibyte */
#define BITS_PER_GIBIBYTE   8589934592


// CONSTANTS USED IN THIS LIBRARY

/** Macros for 0x3333333333333333ULL */
#define NUM_3ULL   0x3333333333333333ULL
/** Macros for 0x5555555555555555ULL */
#define NUM_5ULL   0x5555555555555555ULL
/** Macros for 0x0101010101010101ULL */
#define NUM_01ULL   0x0101010101010101ULL
/** Macros for 0x0f0f0f0f0f0f0f0fULL */
#define NUM_0fULL   0x0f0f0f0f0f0f0f0fULL


// MISCELLANEOUS IMPORTANT CONSTANTS

#ifndef __CENTURY__
/** Build-time century */
#   define __CENTURY__   20
#endif


#endif  // IMPORTANT_CONSTANTS_H


/* FOUNDATION MACROS */


#if (!(defined(FOUNDATION_H) || defined(_FOUNDATION_H_)))
#define FOUNDATION_H   (1)
#define _FOUNDATION_H_   (1)
#ifndef STDC_PREDEF_H  // <stdc-predef.h>
#   define STDC_PREDEF_H   (1)
#endif
#ifndef _STDC_PREDEF_H
#   define _STDC_PREDEF_H   (1)
#endif
#ifndef _STDC_PREDEF_H_
#   define _STDC_PREDEF_H_   (1)
#endif


// OPERATING-SYSTEM MACROS FLAGS

#ifdef _WIN32_WCE
#   define OSWINCE
#endif
#if (defined(WINNT) || defined(__WINNT) || defined(__WINNT__) || defined(__NT__))
#   define OSWINNT
#endif
#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__))
#   define OSWIN32
#endif
#if (defined(WIN64) || defined(_WIN64))
#   define OSWIN64
#endif
#ifdef __DragonFly__  // BSD Systems
/** Macros flag present if the target operating system is Dragonfly BSD */
#   define OSDRAGONFLYBSD
#elif defined(__NetBSD__)
/** Macros flag present if the target operating system is NetBSD */
#   define OSNETBSD
#elif defined(__OpenBSD__)
/** Macros flag present if the target operating system is OpenBSD */
#   define OSOPENBSD
#elif (defined(__FreeBSD__) || defined(__FreeBSD_kernel__))
/** Macros flag present if the target operating system is FreeBSD */
#   define OSFREEBSD
#   define __KFBSD__   1
#endif  // BSD Systems
#if (defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SVR4_SOURCE) || defined(_SYSTYPE_SVR4))
#   define SVR4   1
#   define _SVID_SOURCE   1
#endif
#ifdef EPLAN9  // Operating-Systems
#   define OSPLAN9
#elif (defined(_AIX) || defined(__TOS_AIX__) || defined(_AIX3) || defined(_AIX32) || defined(_AIX41) || defined(_AIX43))  // AIX
#   define OSAIX
#elif (defined(__amigaos__) || defined(AMIGA) || defined(__AMIGA__))  // AmigaOS
#   define OSAMIGAOS
#   error   "This library does not support AmigaOS!"
#elif (defined(__HAIKU__) || defined(__haiku__))  // Haiku
#   define OSHAIKU
#elif (defined(__BEOS__) || defined(__beos__))  // BeOS
#   define OSBEOS
#elif (defined(_CRAY) || defined(__cray) || defined(__cray__) || defined(_UNICOS) || defined(__unicos) || defined(__unicos__))  // Unicos/Cray
#   define OSCRAY
#   define OSUNICOS
#   error   "This library does not support Unicos/Cray!"
#elif (defined(__CYGWIN__) || defined(__CYGWIN32__))  // Cygwin
#   define OSCYGWIN
#elif (defined(__DARWIN__) || defined(__darwin__) || defined(DARWIN))  // Darwin
#   define OSDARWIN
#elif (defined(__DGUX__) || defined(__dgux__) || defined(DGUX))  // DG/UX
#   define OSDGUX
#elif (defined(__MSDOS__) || defined(__msdos__) || defined(__msdos) || defined(__DOS__) || defined(__dos__) || defined(__dos) || defined(_MSDOS) || defined(_msdos))  // MS/DOS
#   define OSMSDOS
#   define OSDOS
#   error   "This library does not support DOS!"
#elif (defined(_SEQUENT_) || defined(__sequent__) || defined(sequent))  // DYNIX/ptx
#   define OSDYNIX
#   define OSSEQUENT
#elif (defined(__ECOS) || defined(__ECOS__))  // eCos
#   define OSECOS
#   error   "This library does not support eCos!"
#elif (defined(__FREEVMS) || defined(__FREEVMS__) || defined(__freevms) || defined(__freevms__))  // FreeVMS
#   define OSFREEVMS
#   error   "This library does not support FreeVMS!"
#elif (defined(__gnu_hurd__) || defined(__gnu_hurd) || defined(__hurd__))  // GNU-Hurd
#   define OSGNU
#   define OSHURD
#elif (defined(_helenos) || defined(helenos) || defined(__helenos) || defined(__helenos__))  // HelenOS
#   define OSHELENOS
#elif (defined(_hpux) || defined(hpux) || defined(__hpux) || defined(__hpux__) || defined(_HPUX_SOURCE))  // HP-Unix
#   define OSHPUX
#elif (defined(_junos) || defined(junos) || defined(__junos) || defined(__junos__) || defined(_juniper_os))  // Junos OS (Juniper Network Operating System)
#   define OSJUNOS
#elif (defined(__sgi) || defined(sgi) || defined(__sgi__) || defined(_SGI_SOURCE))  // IRIX
#   define OSIRIX
#   error   "This library does not support Irix!"
#elif (defined(__lynx__) || defined(__Lynx__) || defined(__lynx) || defined(__Lynx))  // Lynx
#   define OSLYNX
#   error   "This library does not support Lynx!"
#elif (defined(__minix) || defined(__minix__) || defined(__MINIX) || defined(__MINIX__))  // Minix
#   define OSMINIX
#elif (defined(__MORPHOS__) || defined(__morphos__) || defined(__MORPHOS) || defined(__morphos))  // MorphOS
#   define OSMORPHOS
#   error   "This library does not support MorphOS!"
#elif (defined(__mpexl) || defined(__mpexl__) || defined(__MPEXL__) || defined(mpexl))  // MPE/iX
#   define OSMPEIX
#   error   "This library does not support MPE/iX!"
#elif (defined(__netware) || defined(__netware__) || defined(__NetWare__) || defined(__NetWare) || defined(__NETWARE__) || defined(__NETWARE))  // NetWare
#   define OSNETWARE
#   error   "This library does not support NetWare!"
#elif (defined(__OpenVMS__) || defined(__OPENVMS__) || defined(__openvms__) || defined(__OpenVMS) || defined(__OPENVMS) || defined(__openvms))  // OpenVMS
#   define OSOPENVMS
#   error   "This library does not support OpenVMS!"
#elif (defined(__TOS_OS2__) || defined(__OS2__) || defined(__os2__) || defined(__os2warp__) || defined(_OS2) || defined(OS2))  // OS2/Warp
#   define OSOS2WARP
#   error   "This library does not support OS2/Warp!"
#elif (defined(__osf__) || defined(__osf))  // OSF
#   define OSOSF
#   error   "This library does not support OSF!"
#elif (defined(__palmos__) || defined(__palmos) || defined(__garnet__) || defined(__garnet))  // Garnet/Palm OS
#   define OSGARNETOS
#   define OSPALMOS
#   error   "This library does not support PalmOS nor Garnet!"
#elif (defined(__PS3__) || defined(__PS3) || defined(__PS4__) || defined(__PS4))  // Sony Playstation
#   define OSPLAYSTATION
#   if (defined(__PS3__) || defined(__PS3))
#      define OSPLAYSTATION3
#   elif (defined(__PS4__) || defined(__PS4))
#      define OSPLAYSTATION4
#   endif
#elif (defined(__QNX__) || defined(__QNXNTO__))  // QNX
#   define OSQNX
#   error   "This library does not support QNX!"
#elif (defined(_SCO_DS) || defined(__SCO_C_DIALECT))  // SCO OpenServer
#   define OSSCO
#elif (defined(sinux) || defined(__sinux__) || defined(__sinux))  // SINIX/Reliant-UNIX
#   define OSSINIX
#elif (defined(__SYLLABLE__) || defined(__syllable__))  // Syllable
#   define OSSYLLABLE
#   error   "This library does not support Syllable!"
#elif (defined(__symbian) || defined(symbian) || defined(__symbian__) || defined(__SYMBIAN__))  // Symbian
#   define OSSYMBIAN
#   error   "This library does not support Symbian!"
#elif (defined(__tirtos) || defined(__tirtos__) || defined(tirtos))  // TI-RTOS
#   define OSTIRTOS
#   error   "This library does not support TI-RTOS!"
#elif (defined(__ultrix) || defined(__ultrix__) || defined(ultrix))  // Ultrix
#   define OSULTRIX
#   error   "This library does not support Ultrix!"
#elif (defined(__unixware__) || defined(__UNIXWARE__) || defined(_UNIXWARE7))  // Unixware
#   define OSUNIXWARE
#   error   "This library does not support Unixware!"
#elif (defined(__VXWORKS__) || defined(__vxworks__) || defined(__vxworks))  // VxWorks
#   define OSVXWORKS
#   error   "This library does not support VxWorks!"
#elif (defined(__WHIITE__) || defined(__whiite__) || defined(__whiite))  // WHIITE
#   define OSWHIITE
#   define OSLINUX
#   define OSGNU
#elif (defined(__XBOX__) || defined(__XBOX) || defined(__xbox__) || defined(__xbox) || defined(_X360) || defined(__X360) || defined(__X360__))  // Xbox
#   define OSXBOX
#   if (defined(_X360) || defined(__X360) || defined(__X360__))
#      define OSXBOX360
#   elif (defined(_XBOXONE) || defined(__XBOXONE) || defined(__XBOXONE__) || defined(_XBOX1) || defined(__XBOX1) || defined(__XBOX1__))
#      define OSXBOX1
#   endif
#elif (defined(__XEN__) || defined(__xen__) || defined(__xen) || defined(XENLOG_DEFAULT))  // Xen
#   define OSXEN
#   define IS_HYPERVISOR   1
#elif ((defined(__ANDROID__) || defined(__android__) || defined(__android)) && (!defined(__gnu_linux__)))  // Android
/** Macros flag present if the target operating system is Android */
#   define OSANDROID
#   define OSLINUX
#elif ((defined(__BADA__) || defined(__bada__) || defined(__bada)) && (!defined(__gnu_linux__)))  // Bada
#   define OSBADA
#   define OSLINUX
#elif ((defined(__MEEGO__) || defined(__meego__) || defined(__meego)) && (!defined(__gnu_linux__)))  // MeeGo
#   define OSMEEGO
#   define OSLINUX
#elif ((defined(__SAILFISH__) || defined(__sailfish__) || defined(__sailfish)) && (!defined(__gnu_linux__)))  // Sailfish
#   define OSSAILFISH
#   define OSLINUX
#elif ((defined(__TIZEN__) || defined(__tizen__) || defined(__tizen)) && (!defined(__gnu_linux__)))  // Tizen
#   define OSTIZEN
#   define OSLINUX
#elif (defined(__linux__) || defined(__LINUX__) || defined(linux) || defined(__linux)) || defined(__gnu_linux__) || defined(BOOST_OS_LINUX)  // Linux (excluding Android)
#   define OSLINUX
#   define OSGNU
#elif (defined(__FreeBSD_kernel__ ) && defined(__GLIBC__))  // GNU-kFreeBSD
#   define OSBSD
#   define OSGNU
#   define _GNU_SOURCE
#elif ((defined(OSDRAGONFLYBSD) || defined(OSNETBSD) || defined(OSOPENBSD) || defined(OSFREEBSD) || defined(_SYSTYPE_BSD) || defined(__bsdi__) || defined(__bsdi) || defined(bsdi) || defined(_SYSTYPE_BSD ) || defined(BSD)) && (!(defined(__APPLE__) || defined(macintosh) || defined(Macintosh))))  // BSD
#   define OSBSD
#   define _BSD_SOURCE
#   define _XOPEN_SOURCE   700
#   define _XOPEN_VERSION   700
#   define _XOPEN_SOURCE_EXTENDED   1
#elif (defined(sun) || defined(__sun) || defined(__SunOS_5_7) || defined(__SunOS_5_8))  // Solaris, SunOS, etc.
#   define OSSUN
#   ifdef SVR4  // Solaris
#      define OSSOLARIS
#   elif ((!defined(SVR4)) || defined(__SunOS_5_7) || defined(__SunOS_5_8))  // SunOS
#      define OSSUNOS
#   endif
#elif (defined(OSFREEVMS) || defined(OSOPENVMS) || defined(__VMS_VERSION) || defined(__vms_version) || defined(__VMS_VER) || defined(__vms_ver))  // VMS
#   define OSVMS
#elif ((defined(__unix__) || defined(__unix) || defined(unix)) || (defined(__APPLE__) && defined(__MACH__)))  // Unix-systems
#   if (defined(macintosh) || defined(Macintosh) || defined(BOOST_OS_MACOS))  // MacOS
#      define OSMACOS
#   elif (defined(__APPLE__) && defined(__MACH__))  // OSX
#      define OSOSX
#   elif (defined(__APPLE__) && (!defined(__MACH__)))  // Apple system
#      define OSAPPLE
#   elif (defined(__MACH__) && (!defined(__APPLE__)))  // Nextstep
#      define OSNEXTSTEP
#   endif
#elif (defined(COMPILER_MICROSOFT) || defined(COMPILER_MINGW) || defined(OSWINCE) || defined(OSWIN64) || defined(OSWIN32) || defined(OSWINNT) || defined(BOOST_OS_WINDOWS) || defined(_UWIN) || defined(__TOS_WIN__) || defined(__WINDOWS__) || defined(__MSVCRT__))  // Windows
#   define OSWINDOWS
#   ifdef __INTERIX  // Interix
#      define OSINTERIX
#   endif
#else
#   error   "Unknown target operating system!"
#endif  // Operating-Systems


// UNIX & POSIX OPERATING SYSTEM FLAGS

#if (defined(OSAIX) || defined(OSAPPLE) || defined(OSBSD) || defined(OSHPUX) || defined(OSINTERIX) || defined(OSIRIX) || defined(OSMACOS) || defined(OSNEXTSTEP) || defined(OSOSX) || defined(OSSCO) || defined(OSSINIX) || defined(OSSOLARIS) || defined(OSSUN) || defined(OSSUNOS) || defined(__hiuxmpp) || defined(SVR4) || ((defined(__unix__) || defined(__unix) || defined(unix)) || (defined(__APPLE__) && defined(__MACH__))))
/** Macros flag present if the target operating system is a Unix system */
#   define OSUNIX
#endif
#if (defined(OSUNIX) || defined(OSCYGWIN) || defined(OSECOS) || defined(OSGNU) || defined(OSHURD) || defined(OSLINUX) || defined(OSLYNX) || defined(OSMINIX) || defined(OSQNX) || defined(OSSYLLABLE))
/** Macros flag present if the target operating system is a POSIX system */
#   define OSPOSIX
#endif
/** @def TARGET_OS_UNIX
Macros flag indicates if the target operating system is a Unix system */
#ifdef OSUNIX
#   define TARGET_OS_UNIX   1
#else
#   define TARGET_OS_UNIX   0
#endif
/** @def TARGET_OS_POSIX
Macros flag indicates if the target operating system is a POSIX system */
#ifdef OSPOSIX
#   define TARGET_OS_POSIX   1
#else
#   define TARGET_OS_POSIX   0
#endif


// MISCELLANEOUS OPERATING SYSTEM MACROS FLAGS

/** @def TARGET_OS_WIN
Macros flag indicates if the target operating system is a Windows system */
#ifdef OSWINDOWS
#   define TARGET_OS_WIN   1
#else
#   define TARGET_OS_WIN   0
#endif
/** @def TARGET_OS_MAC
Macros flag indicates if the target operating system is a MAC system */
#ifdef OSOSX
#   define TARGET_OS_MAC   1
#else
#   define TARGET_OS_MAC   0
#endif
#ifdef __MACH__
#   define OSMACH
#endif
#if (defined(OSAPPLE) || defined(OSANDROID) || defined(OSOPENBSD))
#   define ALTERNATE_INT64_TYPEDEF
#endif
#ifndef _XOPEN_XCU_VERSION
#   define _XOPEN_XCU_VERSION   4
#endif
#ifndef __KFBSD__
#   define __KFBSD__   0
#endif
#ifndef IS_HYPERVISOR
#   define IS_HYPERVISOR   0
#endif


// C STANDARD LIBRARIES

/** @defgroup C_Standard_Library_Indicators Macros used to indicate and/or test the type of the present standard C library
@{ */  // (FB){

/** @def STDLIB
String name of the standard C library */
/** @def IS_GLIBC
Boolean macros indicating whether the standard C library is GLibc */
/** @def IS_BIONIC
Boolean macros indicating whether the standard C library is Bionic */
/** @def IS_DIETLIBC
Boolean macros indicating whether the standard C library is DietLibc */
/** @def IS_KLIBC
Boolean macros indicating whether the standard C library is KLibc */
/** @def IS_MUSL
Boolean macros indicating whether the standard C library is Musl */
#ifdef __GLIBC__
#   define STDLIB   "glibc"
#   define IS_GLIBC   1
#   define IS_BIONIC   0
#   define IS_DIETLIBC   0
#   define IS_KLIBC   0
#   define IS_MUSL   0
#elif defined(__BIONIC__)
#   define STDLIB   "bionic"
#   define IS_GLIBC   0
#   define IS_BIONIC   1
#   define IS_DIETLIBC   0
#   define IS_KLIBC   0
#   define IS_MUSL   0
#elif defined(__DIETLIBC__)
#   define STDLIB   "dietlibc"
#   define IS_GLIBC   0
#   define IS_BIONIC   0
#   define IS_DIETLIBC   1
#   define IS_KLIBC   0
#   define IS_MUSL   0
#elif defined(__KLIBC__)
#   define STDLIB   "klibc"
#   define IS_GLIBC   0
#   define IS_BIONIC   0
#   define IS_DIETLIBC   0
#   define IS_KLIBC   1
#   define IS_MUSL   0
#elif defined(__MUSL__)
#   define STDLIB   "musl"
#   define IS_GLIBC   0
#   define IS_BIONIC   0
#   define IS_DIETLIBC   0
#   define IS_KLIBC   0
#   define IS_MUSL   1
#elif (defined(__GLIBCPP__) || defined(__GLIBCXX__))
#   error   "GNU-libstdc++ is not supported!"
#elif defined(__CRTL_VER)
#   error   "VMS-libc is not supported!"
#elif defined(__UCLIBC__)
#   error   "uClibc is not supported!"
#elif (defined(__LIBREL__) && defined(__TARGET_LIB__))
#   error   "z/OS-libc is not supported!"
#else
#   define STDLIB   "unknown"
#   define IS_GLIBC   0
#   define IS_BIONIC   0
#   define IS_DIETLIBC   0
#   define IS_KLIBC   0
#   define IS_MUSL   0
#endif  // C STANDARD LIBRARIES
#ifndef ALLOW_OBSOLETE_CARBON
#   define ALLOW_OBSOLETE_CARBON   0
#endif
#ifndef ALLOW_OBSOLETE_CARBON_MACMEMORY
#   define ALLOW_OBSOLETE_CARBON_MACMEMORY   0
#endif
#ifndef ALLOW_OBSOLETE_CARBON_OSUTILS
#   define ALLOW_OBSOLETE_CARBON_OSUTILS   0
#endif

/** @} */  // }


// COMPILER TYPE

/** @defgroup Compiler_Indicators Macros used to indicate and/or test the compiler type
@{ */  // (FB){

/** @def IS_COMPILER
This macros indicates that the software reading the code is a compiler if the macros equals `1` */
/** @def IS_NOT_COMPILER
This macros indicates that the software reading the code is not a compiler if the macros equals `1` */
#if (defined(__NVCC__) || defined(__CUDACC__) || defined(__CUDACC_VER__) || defined(__CUDA_ARCH__))  // NVCC
/** Macros flag present if the current compiler is Cuda */
#   define COMPILER_CUDA   1
/** Macros flag present if the current compiler is NVCC */
#   define COMPILER_NVCC   1
#   define IS_COMPILER   1
#   define IS_NOT_COMPILER   0
#endif
#if (defined(__llvm__) || defined(__LLVM__) || defined(__llvm) || defined(__LLVM))  // LLVM
/** Macros flag present if the current compiler is LLVM */
#   define COMPILER_LLVM   1
#   define IS_COMPILER   1
#   define IS_NOT_COMPILER   0
#endif
/** @def COMPILER_GNU_GCC
Macros flag present if the current compiler is GNU-GCC */
#if (defined(__BORLANDC__) || defined(__CODEGEARC__))  // Borland
/** Macros flag present if the current compiler is Borland */
#   define COMPILER_BORLAND   1
#elif (defined(_ACC_) || defined(__ACC__))  // ACC
/** Macros flag present if the current compiler is ACC */
#   define COMPILER_ACC   1
#elif defined(__CMB__)  // Altium MicroBlaze C
/** Macros flag present if the current compiler is Altium MicroBlaze C */
#   define COMPILER_CMB   1
#elif defined(__CHC__)  // Altium C-to-Hardware
/** Macros flag present if the current compiler is Altium C-to-Hardware */
#   define COMPILER_CHC   1
#elif defined(__ACK__)  // Amsterdam Compiler Kit
/** Macros flag present if the current compiler is the Amsterdam Compiler Kit */
#   define COMPILER_ACK   1
#elif (defined(__CC_ARM) && defined(__ARMCC_VERSION))  // ARM Compiler
/** Macros flag present if the current compiler is the ARM compiler */
#   define COMPILER_ARM   1
#elif (defined(AZTEC_C) || defined(__AZTEC_C__))  // Aztec C
/** Macros flag present if the current compiler is Aztec C */
#   define COMPILER_AZTEC   1
#elif (defined(__POCC__) || defined(__PELLES_C__))  // Pelles C
/** Macros flag present if the current compiler is Pelles C */
#   define COMPILER_PELLESC   1
#elif (defined(__MINGW32__) || defined(__MINGW64__) || defined(__MINGW32_MAJOR_VERSION) || defined(__MINGW64_VERSION_MINOR))  // MinGW
/** Macros flag present if the current compiler is MingW */
#   define COMPILER_MINGW   1
#   define COMPILER_GNU_GCC   1
#   define COMPILER_MINGW   1
#   ifdef __MINGW32__
#      define COMPILER_MINGW32   1
#   elif defined(__MINGW64__)
#      define COMPILER_MINGW64   1
#   endif
#elif (defined(__clang__) || defined(__CLANG__) || defined(__clang) || defined(__clang_major__))  // Clang
/** Macros flag present if the current compiler is Clang */
#   define COMPILER_CLANG   1
#elif (defined(__GNUC__) && (!(defined(__clang__) || defined(__clang_analyzer__) || defined(COMPILER_LLVM))))  // GNU-GCC
#   define COMPILER_GNU_GCC   1
#elif (defined(__HP_cc) || defined(__HP_cc__))  // HP ANSI C
#   define COMPILER_HP   1
#elif (defined(__IAR_SYSTEMS_ICC__) || defined(__IAR_SYSTEMS_ICC))  // IAR C
#   define COMPILER_IAR   1
#elif (defined(__ILEC400__) || defined(__ILEC__) || defined(__ilec__))  // ILE C
#   define COMPILER_ILEC   1
#elif (defined(__PCC__) || defined(__pcc__))  // Portable C Compiler
#   define COMPILER_PCC   1
#elif (defined(__xlc__) || defined(__xlC__) || defined(__IBMC__) || defined(__IBMCPP__))  // IBM XL C
#   define COMPILER_XLC   1
#   define COMPILER_IBM_XLC   1
#   define COMPILER_IBM_C   1
#elif (defined(__INTEL_COMPILER) || defined(__ICC) || defined(__ECC) || defined(__ICL))  // Intel Compiler
#   define COMPILER_INTEL   1
#elif (defined(__LCC__) || defined(__LCC))  // Local C Compiler
#   define COMPILER_LLC   1
#elif (defined(_MSC_VER) || defined(_MSC_FULL_VER) || defined(_MSC_BUILD))  // Microsoft Visual C++
#   define COMPILER_MICROSOFT   1
#else
#   ifndef IS_COMPILER
#      define IS_COMPILER   0
#      define IS_NOT_COMPILER   1
#   endif
#endif  // COMPILER
#ifndef IS_COMPILER
#   define IS_COMPILER   1
#   define IS_NOT_COMPILER   0
#endif
/** @def COMPILER_GNUC
This macros indicates that the compiler is Clang or GNU-GCC */
/** @def IS_GNUC
Boolean macros indicating whether the compiler is GNU-GCC */
/** @def IS_NOT_GNUC
Boolean macros indicating whether the compiler is not GNU-GCC */
#if (defined(COMPILER_GNU_GCC) || defined(COMPILER_CLANG))  // GNUC
#   define COMPILER_GNUC   1
#   define IS_GNUC   1
#   define IS_NOT_GNUC   0
#else
#   define IS_GNUC   0
#   define IS_NOT_GNUC   1
#endif

/** @} */  // }


// ASSEMBLER MACROS

#if ((!defined(IS_ASSEMBLER)) && (defined(__ASSEMBLER__) || defined(__ASSEMBLY__)))
#   define IS_ASSEMBLER   1
#   define IS_NOT_ASSEMBLER   0
#elif (!defined(IS_ASSEMBLER))
#   define IS_ASSEMBLER   0
#   define IS_NOT_ASSEMBLER   1
#endif


// DOCUMENTOR TYPE

/** @def IS_DOC
This macros indicates that the software reading the code is a documenter (such as Doxygen) if the macros equals `1` */
/** @def IS_NOT_DOC
This macros indicates that the software reading the code is not a documenter (such as Doxygen) if the macros equals `1` */
#ifdef _DOXYGEN_
#   define IS_DOC   1
#   define IS_NOT_DOC   0
#else
#   define IS_DOC   0
#   define IS_NOT_DOC   1
#endif


// LINTER TYPE

/** @def IS_LINTER
This macros indicates that the software reading the code is a linter if the macros equals `1` */
/** @def IS_NOT_LINTER
This macros indicates that the software reading the code is not a linter if the macros equals `1` */
#ifdef __clang_analyzer__
/** This macros indicates that the linter is the Clang Analyzer */
#   define LINTER_CLANG   1
#   define IS_LINTER   1
#   define IS_NOT_LINTER   0
#elif (defined(__AUDIT__) || defined(__audit__))  // NetBSD's Audit
/** This macros indicates that the linter is NetBSD's Audit */
#   define LINTER_AUDIT   1
#   define IS_LINTER   1
#   define IS_NOT_LINTER   0
#elif (defined(__CHECKER__) || defined(__CHECK_ENDIAN__))  // Sparse or CGCC
/** This macros indicates that the linter is Sparse or CGCC */
#   define LINTER_SPARSE   1
#   define IS_LINTER   1
#   define IS_NOT_LINTER   0
#elif defined(S_SPLINT_S)  // Splint Lint Checker
/** Macros flag present if the current linter is Splint */
#   define LINTER_SPLINT   1
#   define IS_LINTER   1
#   define IS_NOT_LINTER   0
#elif ((defined(__lint__) || defined(__LINT__)) && (!defined(COMPILER_GNUC)))  // Lint
/** This macros indicates that the linter is Lint */
#   define LINTER_LINT   1
#   define IS_LINTER   1
#   define IS_NOT_LINTER   0
#else
#   if (IS_NOT_ASSEMBLER && IS_NOT_COMPILER && IS_NOT_DOC)
#      error   "Unable to determine assembler/compiler/documenter/linter type!"
#   endif
#   define IS_LINTER   0
#   define IS_NOT_LINTER   1
#endif


// COMPILER VERSION MACROS

/** @defgroup Compiler_Version Macros for testing the version of the compiler
@{ */  // (FB){

/** @def __NVCC_PREREQ(version)
Test if the NVCC compiler matches the specified version number */
#if (defined(__CUDACC_VER__) && (!defined(__NVCC_PREREQ)))
#   define __NVCC_PREREQ(version)   ((__CUDACC_VER__) >= version)
#else
#   define __NVCC_PREREQ(version)   0
#endif
#if ((!defined(GCC_VERSION)) && defined(__GNUC__) && defined(__GNUC_MINOR__))
#   define GCC_VERSION   ((__GNUC__ * 1000) + __GNUC_MINOR__)
#endif
#if ((!defined(__GCC_VER)) && defined(__GNUC__) && defined(__GNUC_MINOR__))
#   define __GCC_VER   ((__GNUC__ << 16) + __GNUC_MINOR__)
#else
#   define __GCC_VER   0
#endif
/** @def __GNUC_PREREQ(major, minor)
Test if the GNU-GCC compiler matches the specified version number */
#if (defined(__GNUC__) && defined(__GNUC_MINOR__) && (!defined(__GNUC_PREREQ)))
#   define __GNUC_PREREQ(major, minor)   (__GCC_VER >= (((major) << 16) + (minor)))
#elif (!defined(__GNUC_PREREQ))
#   define __GNUC_PREREQ(major, minor)   0
#endif
/** Test if the GNU-GCC compiler matches the specified version number */
#define __GNUC_PREREQ__(major, minor)   __GNUC_PREREQ((major), (minor))
/** Test if the GNU-GCC compiler matches the specified version number */
#define GNUC_PREREQ(major, minor)   __GNUC_PREREQ((major), (minor))
/** Test if the MinGW compiler matches the specified version number */
#define __MINGW_GNUC_PREREQ(major, minor)   __GNUC_PREREQ((major), (minor))
#define __MINGW_MSC_PREREQ(major, minor)   __MINGW_GNUC_PREREQ((major), (minor))
#define __MINGW_PREREQ(major, minor)   __MINGW_GNUC_PREREQ((major), (minor))
#define MINGW_MSC_PREREQ(major, minor)   __MINGW_GNUC_PREREQ((major), (minor))
#define MINGW_PREREQ(major, minor)   __MINGW_GNUC_PREREQ((major), (minor))
#define __MINGW_MSC_PREREQ__(major, minor)   __MINGW_GNUC_PREREQ((major), (minor))
#define __MINGW_PREREQ__(major, minor)   __MINGW_GNUC_PREREQ((major), (minor))
#if ((!defined(__CLANG_VER)) && defined(__clang_major__) && defined(__clang_minor__))
#   define __CLANG_VER   ((__clang_major__ << 16) + __clang_minor__)
#else
#   define __CLANG_VER   0
#endif
/** @def __CLANG_PREREQ(major, minor)
Test if the Clang compiler matches the specified version number */
#if (defined(COMPILER_CLANG) && defined(__clang_major__) && (!defined(__CLANG_PREREQ)))
#   define __CLANG_PREREQ(major, minor)   (__CLANG_VER >= ((major) << 16) + (minor))
#elif (!defined(__CLANG_PREREQ))
#   define __CLANG_PREREQ(major, minor)   0
#endif
/** Test if the Clang compiler matches the specified version number */
#define __CLANG_PREREQ__(major, minor)   __CLANG_PREREQ((major), (minor))
/** Test if the Clang compiler matches the specified version number */
#define CLANG_PREREQ(major, minor)   __CLANG_PREREQ((major), (minor))
/** @def __MSC_VER_PREREQ(major, minor)
Test if the Microsoft compiler matches the specified version number */
#if ((!defined(__MSC_VER_PREREQ)) && defined(COMPILER_MICROSOFT) && defined(_MSC_VER))
#   define __MSC_VER_PREREQ(major, minor)   (_MSC_VER >= ((major * 100) + (minor * 10)))
#   define AT_LEAST_MSC19   (__MSC_VER_PREREQ(19, 0))
#   define AT_LEAST_MSC20   (__MSC_VER_PREREQ(20, 0))
#   define AT_LEAST_MSC21   (__MSC_VER_PREREQ(21, 0))
#else
#   define __MSC_VER_PREREQ(major, minor)   0
#   define AT_LEAST_MSC19   0
#   define AT_LEAST_MSC20   0
#   define AT_LEAST_MSC21   0
#endif
#define MSC_VER_PREREQ(major, minor)   __MSC_VER_PREREQ((major), (minor))
#define MSC_PREREQ(major, minor)   __MSC_VER_PREREQ((major), (minor))
#ifdef __GNUC__
#   define AT_LEAST_GCC7   (__GNUC_PREREQ(7, 0))
#   define AT_LEAST_GCC71   (__GNUC_PREREQ(7, 1))
#   define AT_LEAST_GCC72   (__GNUC_PREREQ(7, 2))
#   define AT_LEAST_GCC73   (__GNUC_PREREQ(7, 3))
#   define AT_LEAST_GCC74   (__GNUC_PREREQ(7, 4))
#   define AT_LEAST_GCC75   (__GNUC_PREREQ(7, 5))
#   define AT_LEAST_GCC76   (__GNUC_PREREQ(7, 6))
#   define AT_LEAST_GCC77   (__GNUC_PREREQ(7, 7))
#   define AT_LEAST_GCC78   (__GNUC_PREREQ(7, 8))
#   define AT_LEAST_GCC79   (__GNUC_PREREQ(7, 9))
#   define AT_LEAST_GCC8   (__GNUC_PREREQ(8, 0))
#   define AT_LEAST_GCC81   (__GNUC_PREREQ(8, 1))
#   define AT_LEAST_GCC82   (__GNUC_PREREQ(8, 2))
#   define AT_LEAST_GCC83   (__GNUC_PREREQ(8, 3))
#   define AT_LEAST_GCC84   (__GNUC_PREREQ(8, 4))
#   define AT_LEAST_GCC85   (__GNUC_PREREQ(8, 5))
#   define AT_LEAST_GCC86   (__GNUC_PREREQ(8, 6))
#   define AT_LEAST_GCC87   (__GNUC_PREREQ(8, 7))
#   define AT_LEAST_GCC88   (__GNUC_PREREQ(8, 8))
#   define AT_LEAST_GCC89   (__GNUC_PREREQ(8, 9))
#   define AT_LEAST_GCC9   (__GNUC_PREREQ(9, 0))
#   define AT_LEAST_GCC91   (__GNUC_PREREQ(9, 1))
#   define AT_LEAST_GCC92   (__GNUC_PREREQ(9, 2))
#   define AT_LEAST_GCC93   (__GNUC_PREREQ(9, 3))
#   define AT_LEAST_GCC94   (__GNUC_PREREQ(9, 4))
#   define AT_LEAST_GCC95   (__GNUC_PREREQ(9, 5))
#   define AT_LEAST_GCC96   (__GNUC_PREREQ(9, 6))
#   define AT_LEAST_GCC97   (__GNUC_PREREQ(9, 7))
#   define AT_LEAST_GCC98   (__GNUC_PREREQ(9, 8))
#   define AT_LEAST_GCC99   (__GNUC_PREREQ(9, 9))
#   define AT_LEAST_GCC10   (__GNUC_PREREQ(10, 0))
#else
#   define AT_LEAST_GCC7   0
#   define AT_LEAST_GCC71   0
#   define AT_LEAST_GCC72   0
#   define AT_LEAST_GCC73   0
#   define AT_LEAST_GCC74   0
#   define AT_LEAST_GCC75   0
#   define AT_LEAST_GCC76   0
#   define AT_LEAST_GCC77   0
#   define AT_LEAST_GCC78   0
#   define AT_LEAST_GCC79   0
#   define AT_LEAST_GCC8   0
#   define AT_LEAST_GCC81   0
#   define AT_LEAST_GCC82   0
#   define AT_LEAST_GCC83   0
#   define AT_LEAST_GCC84   0
#   define AT_LEAST_GCC85   0
#   define AT_LEAST_GCC86   0
#   define AT_LEAST_GCC87   0
#   define AT_LEAST_GCC88   0
#   define AT_LEAST_GCC89   0
#   define AT_LEAST_GCC9   0
#   define AT_LEAST_GCC91   0
#   define AT_LEAST_GCC92   0
#   define AT_LEAST_GCC93   0
#   define AT_LEAST_GCC94   0
#   define AT_LEAST_GCC95   0
#   define AT_LEAST_GCC96   0
#   define AT_LEAST_GCC97   0
#   define AT_LEAST_GCC98   0
#   define AT_LEAST_GCC99   0
#   define AT_LEAST_GCC10   0
#endif
#define AT_LEAST_GCC70   AT_LEAST_GCC7
#define AT_LEAST_GCC80   AT_LEAST_GCC8
#define AT_LEAST_GCC90   AT_LEAST_GCC9
#if (defined(COMPILER_GNU_GCC) && (!AT_LEAST_GCC7))
#   error   "GNU-GCC 7.0 or newer (or a Clang equivalent) is required!"
#elif (defined(COMPILER_CLANG) && (!__CLANG_PREREQ(7, 0)))
#   error   "Clang 7 or newer is required!"
#elif (defined(COMPILER_MICROSOFT) && (!AT_LEAST_MSC19))
#   error   "MSVC version 19 or greater is required!"
#endif

/** @} */  // }


// ASSERT DATATYPE SIZES

#if IS_NOT_LINTER
_Static_assert((sizeof(char) == 1), "`char` datatype is not 8-bits!");
_Static_assert((sizeof(int) == 4), "`int` datatype is not 32-bits!");
_Static_assert((sizeof(float) == 4), "`float` datatype is not 32-bits!");
_Static_assert((sizeof(double) == 8), "`double` datatype is not 64-bits!");
_Static_assert(((sizeof(char*) == 4) || (sizeof(char*) == 8)), "The target system is not 32-bit or 64-bit!");
#endif


// C VERSION MACROS

/** @defgroup C_Versions Macros for testing types and versions of C
@{ */  // (FB){

/** @def IS_ANSI
Macros test for ANSI C */
#if (defined(__STDC__) && __STDC__)
#   define IS_ANSI   1
#else
#   define IS_ANSI   0
#endif
/** @def IS_STRICT_ANSI
Macros test for strict ANSI C */
/** @def IS_NOT_STRICT_ANSI
Macros test for strict ANSI C */
#ifdef __STRICT_ANSI__
#   define IS_STRICT_ANSI   1
#   define IS_NOT_STRICT_ANSI   0
#else
#   define IS_STRICT_ANSI   0
#   define IS_NOT_STRICT_ANSI   1
#endif
/** @def IS_NOT_STDC
Macros test for Standard C */
#if ((!(defined(__STDC_VERSION__) || defined(_ISOC99_SOURCE) || defined(_ISOC11_SOURCE))))
#   define IS_NOT_STDC   1
#else
#   define IS_NOT_STDC   0
#endif
// STD-C 1995
/** @def IS_STDC_BELOW_C95
Macros test for C standards under C95 */
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ < 199409L))
#   define IS_STDC_BELOW_C95   1
#else
#   define IS_STDC_BELOW_C95   0
#endif
/** @def IS_STDC95
Macros test for C95 */
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199409L))
#   define IS_STDC95   1
#else
#   define IS_STDC95   0
#endif
#define IS_GNUC95   (IS_STDC95 && IS_GNUC)
// STD-C 1999
/** @def IS_STDC_BELOW_C99
Macros test for C Standards below C99 */
/** @def IS_STDC_ABOVE_C99
Macros test for C Standards over C99 */
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ < 199901L))
#   define IS_STDC_BELOW_C99   1
#   define IS_STDC_ABOVE_C99   0
#elif (defined(__STDC_VERSION__) && (__STDC_VERSION__ > 199901L))
#   define IS_STDC_BELOW_C99   0
#   define IS_STDC_ABOVE_C99   1
#else
#   define IS_STDC_BELOW_C99   0
#   define IS_STDC_ABOVE_C99   0
#endif
/** @def IS_STDC99
Macros test for C99 or greater */
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L))
#   define IS_STDC99   1
#else
#   define IS_STDC99   0
#endif
#define IS_GNUC99   (IS_STDC99 && IS_GNUC)
// STD-C 2011
/** @def IS_STDC_BELOW_C11
Macros test for C Standards below C11 */
/** @def IS_STDC_ABOVE_C11
Macros test for C Standards over C11 */
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ < 201112L))
#   define IS_STDC_BELOW_C11   1
#   define IS_STDC_ABOVE_C11   0
#elif (defined(__STDC_VERSION__) && (__STDC_VERSION__ > 201112L))
#   define IS_STDC_BELOW_C11   0
#   define IS_STDC_ABOVE_C11   1
#else
#   define IS_STDC_BELOW_C11   0
#   define IS_STDC_ABOVE_C11   0
#endif
/** @def IS_STDC_EXACTLY_C11
Macros test for exactly C11 (not below and not greater) */
/** @def IS_STDC11
Macros test for C11 or greater */
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201112L))
#   define IS_STDC_EXACTLY_C11   1
#   define IS_STDC11   1
#elif (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L))
#   define IS_STDC_EXACTLY_C11   0
#   define IS_STDC11   1
#else
#   define IS_STDC_EXACTLY_C11   0
#   define IS_STDC11   0
#endif
/** Macros test for anything but C11 */
#define IS_NOT_STDC11   (!(IS_STDC_EXACTLY_C11))
#define IS_GNUC11   (IS_STDC11 && IS_GNUC)
// STD-C 2017
/** @def IS_STDC_BELOW_C17
Macros test for C Standards below C17 */
/** @def IS_STDC_ABOVE_C17
Macros test for C Standards over C17 */
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ < 201710L))
#   define IS_STDC_BELOW_C17   1
#   define IS_STDC_ABOVE_C17   0
#elif (defined(__STDC_VERSION__) && (__STDC_VERSION__ > 201710L))
#   define IS_STDC_BELOW_C17   0
#   define IS_STDC_ABOVE_C17   1
#else
#   define IS_STDC_BELOW_C17   0
#   define IS_STDC_ABOVE_C17   0
#endif
/** @def IS_STDC_EXACTLY_C17
Macros test for exactly C17 (not below and not greater) */
/** @def IS_STDC17
Macros test for C17 or greater */
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201710L))
#   define IS_STDC_EXACTLY_C17   1
#   define IS_STDC17   1
#elif (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201710L))
#   define IS_STDC_EXACTLY_C17   0
#   define IS_STDC17   1
#else
#   define IS_STDC_EXACTLY_C17   0
#   define IS_STDC17   0
#endif
/** Macros test for anything but C17 */
#define IS_NOT_STDC17   (!(IS_STDC_EXACTLY_C17))
#define IS_GNUC17   (IS_STDC17 && IS_GNUC)
// C PLUS PLUS
/** @def IS_CPLUSPLUS
Macros test for C++ */
#ifdef __cplusplus
#   define IS_CPLUSPLUS   1
#else
#   define IS_CPLUSPLUS   0
#endif
/** Macros test for the absence of C++ */
#define IS_NOT_CPLUSPLUS   (!IS_CPLUSPLUS)
// C++ 2011
/** @def IS_CPLUSPLUS_BELOW_2011
Macros test for C++ standards below C++11 */
/** @def IS_CPLUSPLUS_ABOVE_2011
Macros test for C++ standards over C++11 */
/** @def IS_CPLUSPLUS_EXACTLY_2011
Macros test for exactly C++11 */
#if (defined(__cplusplus) && (__cplusplus < 201103L))
#   define IS_CPLUSPLUS_BELOW_2011   1
#   define IS_CPLUSPLUS_ABOVE_2011   0
#   define IS_CPLUSPLUS_EXACTLY_2011   0
#elif (defined(__cplusplus) && (__cplusplus > 201103L))
#   define IS_CPLUSPLUS_BELOW_2011   0
#   define IS_CPLUSPLUS_ABOVE_2011   1
#   define IS_CPLUSPLUS_EXACTLY_2011   0
#elif (defined(__cplusplus) && (__cplusplus == 201103L))
#   define IS_CPLUSPLUS_BELOW_2011   0
#   define IS_CPLUSPLUS_ABOVE_2011   0
#   define IS_CPLUSPLUS_EXACTLY_2011   1
#else
#   define IS_CPLUSPLUS_BELOW_2011   0
#   define IS_CPLUSPLUS_ABOVE_2011   0
#   define IS_CPLUSPLUS_EXACTLY_2011   0
#endif
/** Macros test for not C++11 */
#define IS_NOT_CPLUSPLUS_2011   (!(IS_CPLUSPLUS_EXACTLY_2011))
/** @def IS_CPLUSPLUS_2011
Macros test for C++11 or greater */
#if (defined(__cplusplus) && (__cplusplus >= 201103L))
#   define IS_CPLUSPLUS_2011   1
#else
#   define IS_CPLUSPLUS_2011   0
#endif
// C++ 2014
/** @def IS_CPLUSPLUS_BELOW_2014
Macros test for C++ standards below C++14 */
/** @def IS_CPLUSPLUS_ABOVE_2014
Macros test for C++ standards over C++14 */
/** @def IS_CPLUSPLUS_EXACTLY_2014
Macros test for exactly C++14 */
#if (defined(__cplusplus) && (__cplusplus < 201403L))
#   define IS_CPLUSPLUS_BELOW_2014   1
#   define IS_CPLUSPLUS_ABOVE_2014   0
#   define IS_CPLUSPLUS_EXACTLY_2014   0
#elif (defined(__cplusplus) && (__cplusplus > 201402L))
#   define IS_CPLUSPLUS_BELOW_2014   0
#   define IS_CPLUSPLUS_ABOVE_2014   1
#   define IS_CPLUSPLUS_EXACTLY_2014   0
#elif (defined(__cplusplus) && (__cplusplus == 201402L))
#   define IS_CPLUSPLUS_BELOW_2014   0
#   define IS_CPLUSPLUS_ABOVE_2014   0
#   define IS_CPLUSPLUS_EXACTLY_2014   1
#else
#   define IS_CPLUSPLUS_BELOW_2014   0
#   define IS_CPLUSPLUS_ABOVE_2014   0
#   define IS_CPLUSPLUS_EXACTLY_2014   0
#endif
/** Macros test for not C++14 */
#define IS_NOT_CPLUSPLUS_2014   (!(IS_CPLUSPLUS_EXACTLY_2014))
/** @def IS_CPLUSPLUS_2014
Macros test for C++14 or greater */
#if (defined(__cplusplus) && (__cplusplus >= 201402L))
#   define IS_CPLUSPLUS_2014   1
#else
#   define IS_CPLUSPLUS_2014   0
#endif
// C++ 2017
/** @def IS_CPLUSPLUS_BELOW_2017
Macros test for C++ standards below C++17 */
/** @def IS_CPLUSPLUS_ABOVE_2017
Macros test for C++ standards over C++17 */
/** @def IS_CPLUSPLUS_EXACTLY_2017
Macros test for exactly C++17 */
#if (defined(__cplusplus) && (__cplusplus < 201703L))
#   define IS_CPLUSPLUS_BELOW_2017   1
#   define IS_CPLUSPLUS_ABOVE_2017   0
#   define IS_CPLUSPLUS_EXACTLY_2017   0
#elif (defined(__cplusplus) && (__cplusplus > 201703L))
#   define IS_CPLUSPLUS_BELOW_2017   0
#   define IS_CPLUSPLUS_ABOVE_2017   1
#   define IS_CPLUSPLUS_EXACTLY_2017   0
#elif (defined(__cplusplus) && (__cplusplus == 201703L))
#   define IS_CPLUSPLUS_BELOW_2017   0
#   define IS_CPLUSPLUS_ABOVE_2017   0
#   define IS_CPLUSPLUS_EXACTLY_2017   1
#else
#   define IS_CPLUSPLUS_BELOW_2017   0
#   define IS_CPLUSPLUS_ABOVE_2017   0
#   define IS_CPLUSPLUS_EXACTLY_2017   0
#endif
/** Macros test for not C++17 */
#define IS_NOT_CPLUSPLUS_2017   (!(IS_CPLUSPLUS_EXACTLY_2017))
/** @def IS_CPLUSPLUS_2017
Macros test for C++17 or greater */
#if (defined(__cplusplus) && (__cplusplus >= 201703L))
#   define IS_CPLUSPLUS_2017   1
#else
#   define IS_CPLUSPLUS_2017   0
#endif
// OBJECTIVE C
/** @def IS_OBJ_C
Macros test for Objective-C */
#if (defined(__OBJC__) || defined(__OBJC_BOOL) || defined(__objc_INCLUDE_GNU))
#   define IS_OBJ_C   1
#else
#   define IS_OBJ_C   0
#endif
// OBJECTIVE C PLUS PLUS
/** @def IS_OBJ_CPLUSPLUS
Macros test for Objective-C++ */
#if (IS_CPLUSPLUS && IS_OBJ_C)
#   define IS_OBJ_CPLUSPLUS   1
#else
#   define IS_OBJ_CPLUSPLUS   0
#endif
/** Macros test for Objective-C++ */
#define IS_OBJ_CPP   IS_OBJ_CPLUSPLUS
#if IS_OBJ_CPLUSPLUS
#   define OBJ_CPLUSPLUS   1
#   define OBJ_CPP   1
#endif
// MISCELLANEOUS C-STANDARD MACROS
#if IS_STDC_BELOW_C11
#   error   "Support for C Standard 2011 (or newer) is required!"
#endif
#ifndef __STDC_VERSION__  // C11
#   define __STDC_VERSION__   (201112L)
#endif
#ifndef __cplusplus  // C++11
#   define __cplusplus   (201103L)
#endif
/** @def __STDC_ISO_10646__
Conforms to ISO/IEC 10646. International standard that defines a character set that is exactly equivalent to the Unicode repertoire. `wchar_t` uses Unicode 8.0.0, which is synchronized with ISO/IEC 10646:2014 and Amendment 1 (published 2015-05-15). */
#ifndef __STDC_ISO_10646__
#   define __STDC_ISO_10646__   (201706L)  // wchar_t must be 32-bits
#endif
/** @def __STDC_IEC_559__
Conforms to the ISO/IEC/IEEE 60559 (IEEE754/IEC559) standards. Industry standard for representing floating-point numbers; https://en.wikipedia.org/wiki/IEEE_754-1985 */
#ifndef __STDC_IEC_559__
#   define __STDC_IEC_559__   1
#endif
/** @def __GCC_IEC_559
Conforms to the ISO/IEC/IEEE 60559 (IEEE754/IEC559) standards. Industry standard for representing floating-point numbers. This does not indicate support for decimal floating point or the IEEE-754 binary16 and binary128 datatypes */
#ifndef __GCC_IEC_559
#   define __GCC_IEC_559   2
#endif
#if ((!(defined(__STDC_DEC_FP__) || defined(__STDC_WANT_DEC_FP__))) && (defined(__DEC32_MAX__) || defined(__DEC64_MAX__) || defined(__DEC32_EPSILON__)))
/** Conforms to the ISO/IEC/IEEE 60559 (IEEE754-2008/IEC559) standards for decimal floating-points. Industry standard for representing decimal floating-point numbers. */
#   define __STDC_DEC_FP__   1
#   define __STDC_WANT_DEC_FP__   1
#endif
/** @def __STDC_IEC_559_COMPLEX__
Conforms to the ISO/IEC/IEEE 60559 (IEEE754/IEC559) standards for complex numbers. Industry standard for representing complex floating-point numbers. */
#ifndef __STDC_IEC_559_COMPLEX__
#   define __STDC_IEC_559_COMPLEX__   1
#endif
/** @def __GCC_IEC_559_COMPLEX
Conforms to the ISO/IEC/IEEE 60559 (IEEE754/IEC559) standards for complex numbers. Industry standard for representing complex floating-point numbers. */
#ifndef __GCC_IEC_559_COMPLEX
#   define __GCC_IEC_559_COMPLEX   2
#endif
typedef enum c_language_kind {
	/** C90, C94, C99, or C11 */
	clk_c = 0,
	/** clk_c with ObjC features */
	clk_objc = 1,
	/** ANSI/ISO C++ */
	clk_cxx = 2,
	/** clk_cxx with ObjC features */
	clk_objcxx = 3
} c_language_t;
/** @def c_language
Defines this library's C language type */
#if IS_OBJ_C
#   define c_language   clk_objc
#elif IS_OBJ_CPLUSPLUS
#   define c_language   clk_objcxx
#elif IS_CPLUSPLUS
#   define c_language   clk_cxx
#else
#   define c_language   clk_c
#endif
/** Test if this library is using C */
#define c_dialect_c()   (IS_NOT_CPLUSPLUS && (!IS_OBJ_C) && (!IS_OBJ_CPLUSPLUS))
/** Test if this library is using C++ */
#define c_dialect_cxx()   IS_CPLUSPLUS
/** Test if this library is using Objective-C */
#define c_dialect_objc()   IS_OBJ_C
/** Test if this library is using Objective-C++ */
#define c_dialect_objcxx()   IS_OBJ_CPLUSPLUS
#if ((IS_ANSI || IS_CPLUSPLUS) && (!defined(NO_ANSI_KEYWORDS)))
#   define _HAVE_STDC   1
#else
#   define _HAVE_STDC   0
#endif
/** @def SUPPORTS_CILK
Boolean macros flag indicating support for Cilk++ */
#ifdef __cilk
#   define SUPPORTS_CILK   1
#else
#   define SUPPORTS_CILK   0
#endif
/** @def SUPPORTS_OPENACC
Boolean macros flag indicating support for OpenACC */
#ifdef _OPENACC
#   define SUPPORTS_OPENACC   1
#else
#   define SUPPORTS_OPENACC   0
#endif
/** @def SUPPORTS_OPENMP
Boolean macros flag indicating support for OpenMP */
#ifdef _OPENMP
#   define SUPPORTS_OPENMP   1
#else
#   define SUPPORTS_OPENMP   0
#endif

/** @} */  // }


// PLATFORM FEATURES & TYPES

// ARM CPUS
#if (defined(__THUMBEB__) || defined(__THUMBEL__) || defined(__thumb) || defined(__thumb__) || defined(__THUMB) || defined(__THUMB__))
#   define ARM_THUMB1    1
#endif
#if (defined(__thumb2__) || defined(__thumb2) || defined(__THUMB2__) || defined(__THUMB2) || defined(__ARM_ARCH_6T2__))
#   define ARM_THUMB2    1
#endif
#if (defined(ARM_THUMB1) || defined(ARM_THUMB2) || defined(__TARGET_FEATURE_THUMB) || (defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB > 0)))
#   define ARM_THUMB    1
#endif
#ifdef __ARM_ARCH_2__
#   define ARM_2   1
#endif
#if (defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__))
#   define ARM_3   1
#endif
#ifdef __ARM_ARCH_3M__
#   define ARM_3M   1
#endif
#if (defined(ARM_3) || defined(ARM_3M))
#   define ARM_3_SERIES   1
#endif
#if (defined(__ARM_ARCH_4__) || defined(_ARM_ARCH_4) || defined(__TARGET_ARM_4))
#   define ARM_4   1
#endif
#if (defined(__ARM_ARCH_4T__) || defined(_ARM_ARCH_4T) || defined(__TARGET_ARM_4T))
#   define ARM_4T   1
#endif
#if (defined(ARM_4) || defined(ARM_4T))
#   define ARM_4_SERIES   1
#endif
#ifdef __ARM_ARCH_5__
#   define ARM_5   1
#endif
#ifdef __ARM_ARCH_5E__
#   define ARM_5E   1
#endif
#if (defined(__ARM_ARCH_5T__) || defined(_ARM_ARCH_5T))
#   define ARM_5T   1
#endif
#ifdef __ARM_ARCH_5TE__
#   define ARM_5TE   1
#endif
#ifdef __ARM_ARCH_5TEJ__
#   define ARM_5TEJ   1
#endif
#if (defined(ARM_5) || defined(ARM_5E) || defined(ARM_5T) || defined(ARM_5TE) || defined(ARM_5TEJ))
#   define ARM_5_SERIES   1
#endif
#if (defined(__ARM_ARCH_6__) || defined(_ARM_ARCH_6))
#   define ARM_6   1
#endif
#ifdef __ARM_ARCH_6J__
#   define ARM_6J   1
#endif
#ifdef __ARM_ARCH_6K__
#   define ARM_6   1
#endif
#ifdef __ARM_ARCH_6Z__
#   define ARM_6Z   1
#endif
#ifdef __ARM_ARCH_6ZK__
#   define ARM_6ZK   1
#endif
#ifdef __ARM_ARCH_6ZM__
#   define ARM_6ZM   1
#endif
#ifdef __ARM_ARCH_6T2__
#   define ARM_6T2   1
#endif
#if (defined(ARM_6) || defined(ARM_6J) || defined(ARM_6K) || defined(ARM_6Z) || defined(ARM_6ZK) || defined(ARM_6ZM) || defined(ARM_6T2))
#   define ARM_6_SERIES   1
#endif
#if (defined(__ARM_ARCH_7__) || defined(_ARM_ARCH_7))
#   define ARM_7   1
#endif
#ifdef __ARM_ARCH_7A__
#   define ARM_7A   1
#endif
#ifdef __ARM_ARCH_7R__
#   define ARM_7R   1
#endif
#ifdef __ARM_ARCH_7M__
#   define ARM_7M   1
#endif
#ifdef __ARM_ARCH_7S__
#   define ARM_7S   1
#endif
#ifdef __ARM_ARCH_7EM__
#   define ARM_7EM   1
#endif
#if (defined(ARM_7) || defined(ARM_7A) || defined(ARM_7R) || defined(ARM_7M) || defined(ARM_7S) || defined(ARM_7EM))
#   define ARM_7_SERIES   1
#endif
#if (defined(__ARM_ARCH_8__) || defined(_ARM_ARCH_8) || defined(__ARM_ARCH_8A__))
/** ARMv8 64-bit in AARCH32 */
#   define ARM_8   1
#   define ARM_8_SERIES   1
#endif
#if (defined(_ARM_ARCH_7) || defined(__ARM_ARCH_6T2__) || defined(_ARM_ARCH_T2))  // ARM_ARCH_T2
#   define ARM_ARCH_T2   1
#endif
#if (defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__))  // NON_MMU_ARM
/** 7R, 7M, 7EM are for non-MMU ARM processors */
#   define NON_MMU_ARM   1
#endif
// ARM FEATURES
#if (defined(__ARM_NEON__) || defined(__ARM_NEON) || defined(__arm_neon__) || defined(__arm_neon) || defined(__TARGET_FEATURE_NEON))
#   define ARM_NEON   1
#   define SUPPORTS_ARM_NEON   1
#else
#   define SUPPORTS_ARM_NEON   0
#endif
#ifdef __ARM_FEATURE_DSP
#   define ARM_DSP   1
#   define SUPPORTS_ARM_DSP   1
#else
#   define SUPPORTS_ARM_DSP   0
#endif
#ifdef __ARM_FEATURE_IDIV
#   define ARM_IDIV   1
#   define SUPPORTS_ARM_IDIV   1
#else
#   define SUPPORTS_ARM_IDIV   0
#endif
#ifdef __ARM_FEATURE_SAT
#   define ARM_SAT   1
#   define SUPPORTS_ARM_SAT   1
#else
#   define SUPPORTS_ARM_SAT   0
#endif
#ifdef __ARM_FEATURE_SIMD32
#   define ARM_SIMD32   1
#   define SUPPORTS_ARM_SIMD32   1
#else
#   define SUPPORTS_ARM_SIMD32   0
#endif
#ifdef __ARM_WMMX
#   define ARM_WMMX   1
#   define SUPPORTS_ARM_WMMX   1
#else
#   define SUPPORTS_ARM_WMMX   0
#endif
#ifdef __ARM_FEATURE_CRC32
#   define ARM_CRC32   1
#   define SUPPORTS_ARM_CRC32   1
#else
#   define SUPPORTS_ARM_CRC32   0
#endif
#ifdef __ARM_FEATURE_CRYPTO
#   define ARM_CRYPTO   1
#   define SUPPORTS_ARM_CRYPTO   1
#else
#   define SUPPORTS_ARM_CRYPTO   0
#endif
#ifdef __ARM_FEATURE_DIRECTED_ROUNDING
#   define ARM_DIRECTED_ROUNDING   1
#   define SUPPORTS_ARM_DIRECTED_ROUNDING   1
#else
#   define SUPPORTS_ARM_DIRECTED_ROUNDING   0
#endif
#ifdef __ARM_FEATURE_NUMERIC_MAXMIN
#   define ARM_MAXMIN   1
#   define SUPPORTS_ARM_MAXMIN   1
#else
#   define SUPPORTS_ARM_MAXMIN   0
#endif
#ifdef __ARM_FP16_ARGS
#   define ARM_FP16_ARGS   1
#   define SUPPORTS_ARM_FP16_ARGS   1
#else
#   define SUPPORTS_ARM_FP16_ARGS   0
#endif
#if ((defined(__aarch64__) || defined(__aarch64) || defined(__AARCH64__) || defined(__AARCH64) || defined(__AARCH64EB__) || defined(__AARCH64EL__) || defined(__ARM_ARCH_ISA_A64) || defined(__ARM_ARCH_8A__)) && (!(defined(ARM_3_SERIES) || defined(ARM_4_SERIES) || defined(ARM_5_SERIES) || defined(ARM_6_SERIES) || defined(ARM_7_SERIES))))  // Aarch64 (ARM64)
#   define ARCHARM   1
#   define ARCHAARCH64   1
#elif (defined(__ARMEL__) || defined(__ARMEB__) || defined(__ARM_EABI__) || defined(__arm__) || defined(__ARM_ARCH) || defined(__arm) || defined(_ARM) || defined(_M_ARM) || defined(ARM_THUMB) || defined(__ARM_FEATURE_DSP) || defined(__TARGET_ARCH_ARM))
#   define ARCHARM   1
#   define ARCHAARCH32   1
#endif
// X86 CPUS
#if (defined(__pentium2__) || defined(__pentium2) || defined(_ARCH_PENTIUM2))
#   define X86_PENTIUM2   1
#elif (defined(__pentium4__) || defined(__pentium4) || defined(_ARCH_PENTIUM4))
#   define X86_PENTIUM4   1
#elif (defined(__pentiumpro__) || defined(__pentiumpro))
#   define X86_PENTIUM_PRO   1
#elif (defined(__haswell__) || defined(__haswell) || defined(__tune_haswell__))
#   define X86_HASWELL   1
#elif (defined(__broadwell__) || defined(__broadwell) || defined(__tune_broadwell__))
#   define X86_BROADWELL   1
#elif (defined(__skylake__) || defined(__skylake) || defined(__tune_skylake__))
#   define X86_SKYLAKE   1
#elif (defined(__kabylake__) || defined(__kabylake) || defined(__tune_kabylake__))
#   define X86_KABYLAKE   1
#elif (defined(__cannonlake__) || defined(__cannonlake) || defined(__tune_cannonlake__))
#   define X86_CANNONLAKE   1
#elif (defined(__coffeelake__) || defined(__coffeelake) || defined(__tune_coffeelake__))
#   define X86_COFFEELAKE   1
#elif (defined(__icelake__) || defined(__icelake) || defined(__tune_icelake__))
#   define X86_ICELAKE   1
#endif
#if (defined(__amd64__) || defined(__amd64) || defined(_M_AMD64))
#   define ARCHAMD64   1
#endif
#if ((defined(__x86_64) || defined(__x86_64__)) && defined(_X86_))
#   undef _X86_
#endif
#undef _M_IX86
#if (defined(i386) || defined(__i386) || defined(__i386__) || defined(__I386) || defined(__I386__) || defined(__386))
#   define ARCHI386    1
#   define _M_IX86   300
#elif (defined(__i486__) || defined(__i486) || defined(__I486))
#   define ARCHI486    1
#   define _M_IX86   400
#elif (defined(__i586__) || defined(__i586) || defined(__pentium__) || defined(__k5__))
#   define ARCHI586    1
#   define _M_IX86   500
#elif (defined(__i686__) || defined(__i686) || defined(X86_PENTIUM_PRO) || defined(__k6__) || defined(__athlon__))
#   define ARCHI686    1
#   define _M_IX86   600
#elif (defined(__i786__) || defined(__i786) || defined(X86_PENTIUM4) || defined(__k7__))
#   define ARCHI786    1
#   define _M_IX86   700
#endif
#if (defined(__x86_64__) || defined(__x86_64) || defined(x86_64) || defined(__X86_64__) || defined(_M_X64) || defined(ARCHAMD64))  // x86-64
#   define ARCHX86   1
#   define ARCHX86_64   1
#elif (defined(ARCHI386) || defined(ARCHI486) || defined(ARCHI586) || defined(ARCHI686) || defined(_M_I86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__))  // x86
#   define ARCHX86   1
#   define ARCHX86_32   1
#endif
#if (defined(ARCHAMD64) && (defined(___AM29K__) || defined(__AM29K__) || defined(_AM29K) || defined(_AM29000) || defined(__AM29000__)))
#   define ARCHAM29K   1
#endif
// X86 FEATURES
#ifdef __MMX__
#   define CPU_MMX   1
#else
#   define CPU_MMX   0
#endif
#ifdef __SSE__
#   define CPU_SSE   1
#   ifndef __SSE_MATH__
#      define __SSE_MATH__   1
#   endif
#else
#   define CPU_SSE   0
#endif
#ifdef __SSE2__
#   define CPU_SSE2   1
#   ifndef __SSE2_MATH__
#      define __SSE2_MATH__   1
#   endif
#else
#   define CPU_SSE2   0
#endif
#ifdef __SSE3__
#   define CPU_SSE3   1
#   ifndef __SSE3_MATH__
#      define __SSE3_MATH__   1
#   endif
#else
#   define CPU_SSE3   0
#endif
#ifdef __SSE4_1__
#   define CPU_SSE4_1   1
#   ifndef __SSE4_1_MATH__
#      define __SSE4_1_MATH__   1
#   endif
#else
#   define CPU_SSE4_1   0
#endif
#ifdef __SSE4_2__
#   define CPU_SSE4_2   1
#   ifndef __SSE4_2_MATH__
#      define __SSE4_2_MATH__   1
#   endif
#else
#   define CPU_SSE4_2   0
#endif
#ifdef __SSSE3__
#   define CPU_SSSE3   1
#   ifndef __SSSE3_MATH__
#      define __SSSE3_MATH__   1
#   endif
#else
#   define CPU_SSSE3   0
#endif
#ifdef __SSE2AVX__
#   define CPU_SSE2AVX   1
#   ifndef __SSE2AVX_MATH__
#      define __SSE2AVX_MATH__   1
#   endif
#else
#   define CPU_SSE2AVX   0
#endif
#ifdef __AVX__
#   define CPU_AVX   1
#   ifndef __AVX_MATH__
#      define __AVX_MATH__   1
#   endif
#else
#   define CPU_AVX   0
#endif
#if (defined(__AVX2__) || defined(__core_avx2__) || defined(__core_avx2) || defined(__tune_core_avx2__))
#   define CPU_AVX2   1
#   ifndef __AVX2_MATH__
#      define __AVX2_MATH__   1
#   endif
#else
#   define CPU_AVX2   0
#endif
#ifdef __AVX512BW__
#   define CPU_AVX512BW   1
#else
#   define CPU_AVX512BW   0
#endif
#ifdef __AVX512CD__
#   define CPU_AVX512CD   1
#else
#   define CPU_AVX512CD   0
#endif
#ifdef __AVX512DQ__
#   define CPU_AVX512DQ   1
#else
#   define CPU_AVX512DQ   0
#endif
#ifdef __AVX512ER__
#   define CPU_AVX512ER   1
#else
#   define CPU_AVX512ER   0
#endif
#ifdef __AVX512F__
#   define CPU_AVX512F   1
#else
#   define CPU_AVX512F   0
#endif
#ifdef __AVX512IFMA__
#   define CPU_AVX512IFMA   1
#else
#   define CPU_AVX512IFMA   0
#endif
#ifdef __AVX512PF__
#   define CPU_AVX512PF   1
#else
#   define CPU_AVX512PF   0
#endif
#ifdef __AVX512VBMI__
#   define CPU_AVX512VBMI   1
#else
#   define CPU_AVX512VBMI   0
#endif
#ifdef __AVX512VL__
#   define CPU_AVX512VL   1
#else
#   define CPU_AVX512VL   0
#endif
#ifdef __ADX__
#   define CPU_ADX   1
#else
#   define CPU_ADX   0
#endif
#if (defined(__F16C__) || defined(__CVT16__))
#   define CPU_F16C   1
#   define CPU_CVT16   1
#else
#   define CPU_F16C   0
#   define CPU_CVT16   0
#endif
#if (defined(__BMI__) || defined(__BMI1__))
#   define CPU_BMI   1
#   define SUPPORTS_TZCNT   1
#else
#   define CPU_BMI   0
#   define SUPPORTS_TZCNT   0
#endif
#ifdef __BMI2__
#   define CPU_BMI2   1
#else
#   define CPU_BMI2   0
#endif
#ifdef __ABM__
#   define CPU_ABM   1
#   define CPU_POPCNT   1
#   define CPU_LZCNT   1
#elif (defined(ARCHX86) && (!defined(ARCHAMD64)))
#   define CPU_ABM   0
#   ifdef __POPCNT__
#      define CPU_POPCNT   1
#   else
#      define CPU_POPCNT   0
#   endif
#   if (defined(__LZCNT__) || defined(CPU_BMI))
#      define CPU_LZCNT   1
#   else
#      define CPU_LZCNT   0
#   endif
#else
#   define CPU_ABM   0
#   define CPU_POPCNT   0
#   define CPU_LZCNT   0
#endif
#ifdef __TBM__
#   define CPU_TBM   1
#else
#   define CPU_TBM   0
#endif
#ifdef __AES__
#   define CPU_AES   1
#else
#   define CPU_AES   0
#endif
#ifdef __SHA__
#   define CPU_SHA   1
#else
#   define CPU_SHA   0
#endif
#ifdef __SGX__
#   define CPU_SGX   1
#else
#   define CPU_SGX   0
#endif
#ifdef __MPX__
#   define CPU_MPX   1
#else
#   define CPU_MPX   0
#endif
#ifdef __FMA__
#   define CPU_FMA   1
#else
#   define CPU_FMA   0
#endif
#ifdef __FMA3__
#   define CPU_FMA3   1
#else
#   define CPU_FMA3   0
#endif
#ifdef __FMA4__
#   define CPU_FMA4   1
#else
#   define CPU_FMA4   0
#endif
#ifdef __FXSR__
#   define CPU_FXSR   1
#else
#   define CPU_FXSR   0
#endif
#ifdef __RDRND__
#   define CPU_RDRND   1
#else
#   define CPU_RDRND   0
#endif
#ifdef __RDSEED__
#   define CPU_RDSEED   1
#else
#   define CPU_RDSEED   0
#endif
#ifdef __XSAVE__
#   define CPU_XSAVE   1
#else
#   define CPU_XSAVE   0
#endif
#ifdef __XSAVEOPT__
#   define CPU_XSAVEOPT   1
#else
#   define CPU_XSAVEOPT   0
#endif
#ifdef __PCLMUL__
#   define CPU_PCLMUL   1
#else
#   define CPU_PCLMUL   0
#endif
#ifdef __CLMUL__
#   define CPU_CLMUL   1
#else
#   define CPU_CLMUL   0
#endif
#ifdef __FSGSBASE__
#   define CPU_FSGSBASE   1
#else
#   define CPU_FSGSBASE   0
#endif
#ifdef __PRFCHW__
#   define CPU_PRFCHW   1
#else
#   define CPU_PRFCHW   0
#endif
#ifdef __MWAITX__
#   define CPU_MWAITX   1
#else
#   define CPU_MWAITX   0
#endif
#ifdef __PKU__
#   define CPU_PKU   1
#else
#   define CPU_PKU   0
#endif
#ifdef __XOP__
#   define CPU_XOP   1
#else
#   define CPU_XOP   0
#endif
// MIPS CPUS
#if ((defined(__MIPS64__) || defined(_M_MIPS64) || defined(__mips64) || defined(__mips64__) || defined(_R4000) || defined(_MIPS_ISA_MIPS3) || defined(__MIPS_ISA3__) || defined(_MIPS_ISA_MIPS4) || defined(__MIPS_ISA4__)) || defined(_MIPS_SIM_ABI64) || defined(_ABI64) || (defined(__mips) && (__mips == 64)))
#   define ARCHMIPS64   1
#elif defined(__mips16)
#   define ARCHMIPS   1
#   error   "16-bit MIPS is not supported!"
#endif
#if (defined(ARCHMIPS64) || defined(ARCHMIPS16) || defined(__MIPS__) || defined(_M_MIPS) || defined(__mips) || defined(__mips__) || defined(_MIPS_SIM) || defined(__MIPSEB__) || defined(_MIPSEB) || defined(__MIPSEB) || defined(__MIPSEL__) || defined(_MIPSEL) || defined(__MIPSEL) || defined(_MIPS_ISA) || defined(_R3000) || defined(_R4000) || defined(_R5900) || defined(_MIPS_ISA_MIPS1) || defined(_MIPS_ISA_MIPS2) || defined(__MIPS_ISA2__) || defined(__mips_isa_rev))  // Mips
#   define ARCHMIPS   1
#   if (!(defined(ARCHMIPS64) || defined(ARCHMIPS16)))
#      define ARCHMIPS32   1
#   endif
#   ifdef __mips_isa_rev
#      define MIPS_REV   __mips_isa_rev
#   else
#      define MIPS_REV   0
#   endif
#endif
// POWERPC CPUS
#if (defined(__ppc64__) || defined(__ppc64) || defined(__powerpc64__) || defined(__PPC64__) || defined(_ARCH_PPC64) || defined(ppc64le) || defined(ppc64be) || defined(_ARCH_PPC64GRSQ) || defined(_ARCH_PPC64GR) || defined(_ARCH_PPC64) || defined(_ARCH_PWR4) || defined(_ARCH_PWR5))  // PPC64
#   define ARCHPOWERPC64   1
#elif (defined(__ppc32__) || defined(__ppc32) || defined(__powerpc32__) || defined(__PPC32__) || defined(_ARCH_PPC32) || defined(ppc32le) || defined(ppc32be) || defined(_ARCH_PPC32GRSQ) || defined(_ARCH_PPC32GR) || defined(_ARCH_PPC32) || defined(_ARCH_PWR3))  // PPC32
#   define ARCHPOWERPC32   1
#endif
#if (defined(ARCHPOWERPC64) || defined(ARCHPOWERPC32) || defined(__powerpc) || defined(__powerpc__) || defined(__POWERPC__) || defined(__ppc__) || defined(__ppc) || defined(POWERPC64) || defined(__PPC__) || defined(_ARCH_PPC) || defined(_M_PPC) || defined(__ppc601__) || defined(__ppc603__) || defined(__ppc604__) || defined(_ARCH_PPCGR) || defined(_ARCH_PWR) || defined(_ARCH_PWR2) || defined(_POWER) || defined(_ARCH_PPC970) || defined(__PPCGECKO__) || defined(__PPCBROADWAY__) || defined(_XENON))  // PowerPC
#   define ARCHPOWERPC   1
#endif
// SPARC CPUS
#if (defined(__sparc_v8__) || defined(__sparcv8) || defined(__supersparc__) || defined(__supersparc))
#   define ARCHSUPERSPARC   1
#elif (defined(__sparc_v9__) || defined(__sparcv9) || defined(__ultrasparc__) || defined(__ultrasparc__))
#   define ARCHULTRASPARC   1
#endif
#if (defined(__sparc64__) || defined(__sparc64) || defined(__SPARC64__) || defined(ARCHULTRASPARC))
#   define ARCHSPARC64   1
#elif (defined(__sparc32__) || defined(__sparc32) || defined(__SPARC32__) || defined(ARCHSUPERSPARC))
#   define ARCHSPARC32   1
#endif
#if (defined(ARCHSPARC32) || defined(ARCHSPARC64) || defined(__sparc__) || defined(__SPARC__) || defined(__sparc) || defined(sparc) || defined(__sparclite__) || defined(__sparclite86x__) || defined(__sparclet__))  // Sparc
#   define ARCHSPARC   1
#endif
// OTHER CPUS
#if (defined(__ALPHA__) || defined(__alpha) || defined(__alpha__) || defined(_M_ALPHA) || defined(__alpha_ev4__) || defined(__alpha_ev5__) || defined(__alpha_ev6__) || defined(__Alpha_AXP))  // Alpha
#   define ARCHALPHA   1
#elif (defined(__ARC__) || defined(__arc) || defined(__arc__))  // Arc
#   define ARCHARC   1
#elif (defined(__avr) || defined(__avr__) || defined(__AVR__) || defined(__AVR) || defined(__AVRASM_VERSION__) || defined(__AVR_AT94K__))  // AVR
#   define ARCHAVR   1
#elif (defined(__blackfin__) || defined(__bfin) || defined(__bfin__) || defined(__BFIN__) || defined(__BFIN))  // Blackfin
#   define ARCHBLACKFIN   1
#elif (defined(__coldfire) || defined(__coldfire__) || defined(__COLDFIRE__) || defined(__COLDFIRE) || defined(__mcoldfire__) || defined(__MCOLDFIRE__) || defined(__MCF5206__) || defined(__mcf5206__) || defined(__MCF5307__) || defined(__mcf5307__) || defined(__mcffpu__))  // Freescale ColdFire
#   define ARCHCOLDFIRE   1
#elif (defined(__convex__) || defined(__convex) || defined(__convex_c1__) || defined(__convex_c2__) || defined(__convex_c32__) || defined(__convex_c34__) || defined(__convex_c38__))  // Convex
#   define ARCHCONVEX   1
#elif (defined(__CRIS__) || defined(__cris) || defined(__cris__) || defined(__CRIS_arch_version))  // Cris
#   define ARCHCRIS   1
#elif (defined(__epiphany__) || defined(__epiphany) || defined(__EPIPHANY__))  // Epiphany
#   define ARCHEPIPHANY   1
#elif (defined(__hppa__) || defined(__hppa) || defined(__HPPA__) || defined(_PA_RISC1_0) || defined(_PA_RISC1_1) || defined(__HPPA11__) || defined(__PA7100__) || defined(_PA_RISC2_0) || defined(__RISC2_0__) || defined(__HPPA20__) || defined(__PA8000__) || defined(__PARISC__) || defined(_M_PARISC) || defined(__parisc) || defined(__parisc__))  // HPPA/Parisc
#   define ARCHPARISC   1
#elif (defined(__i960__) || defined(_I960) || defined(_I960_) || defined(__I960__) || defined(__i960) || defined(_M_I960) || defined(_ARCH_I960))  // i960
#   define ARCHI960   1
#elif (defined(__ia64__) || defined(_IA64) || defined(_IA64_) || defined(__IA64__) || defined(__ia64) || defined(_M_IA64) || defined(_ARCH_IA64) || defined(__itanium__))  // Itanium (IA64)
#   define ARCHITANIUM   1
#elif (defined(__MC68K__) || defined(__m68k__) || defined(__m68k) || defined(m68k) || defined(__m68000) || defined(__m68000__) || defined(m68000) || defined(M68000) || defined(__mc68000__) || defined(__MC68000__) || defined(__mc68010__) || defined(__mc68020__) || defined(__MC68020__) || defined(__mc68030__) || defined(__MC68030__) || defined(__mc68040__) || defined(__mc68060__))  // Motorola 68k
#   define ARCHM68K   1
#elif (defined(__MICROBLAZE__) || defined(_M_MICROBLAZE) || defined(__microblaze) || defined(__microblaze__) || defined(__MICROBLAZEEL__) || defined(__MICROBLAZEBL__))  // Microblaze
#   define ARCHMICROBLAZE   1
#elif (defined(__nios_little_endian__) || defined(__nios_big_endian__) || defined(__nios__) || defined(__NIOS__) || defined(__nios) || defined(__NIOS) || defined(nios) || defined(NIOS))  // NIOS
#   define ARCHNIOS   1
#   error   "NIOS is not supported!"
#elif (defined(__nios2_little_endian__) || defined(__nios2_big_endian__) || defined(__nios2__) || defined(__NIOS2__) || defined(__nios2) || defined(__NIOS2) || defined(nios2) || defined(NIOS2))  // NIOS II
#   define ARCHNIOS2   1
#   error   "NIOS2 is not supported!"
#elif (defined(__or1k__) || defined(_M_OR1K) || defined(__or1k) || defined(__OR1K__))  // Or1k
#   define ARCHOR1K   1
#   error   "OR1K is not supported!"
#elif (defined(__PICOBLAZE__) || defined(_M_PICOBLAZE) || defined(__picoblaze) || defined(__picoblaze__) || defined(__PICOBLAZEEL__) || defined(__PICOBLAZEBL__))  // Picoblaze
#   define ARCHPICOBLAZE   1
#elif (defined(__RS64__) || defined(_M_RS64) || defined(__rs64) || defined(__rs64__) || defined(_ARCH_RS64) || defined(_IBMR2) || defined(__THW_RS6000))  // RS64 (RS/6000)
#   define ARCHRS64   1
#   error   "RS64 is not supported!"
#elif (defined(__RS64II__) || defined(_M_RS64II) || defined(__rs64ii) || defined(__rs64ii__) || defined(__RS64B__) || defined(_M_RS64B) || defined(__rs64b) || defined(__rs64b__) || defined(_ARCH_RS64B))  // RS64II
#   define ARCHRS64B   1
#   define ARCHRS64II   1
#   error   "RS64II is not supported!"
#elif (defined(__RS64III__) || defined(_M_RS64III) || defined(__rs64iii) || defined(__rs64iii__) || defined(__RS64C__) || defined(_M_RS64C) || defined(__rs64c) || defined(__rs64c__) || defined(_ARCH_RS64C))  // RS64III
#   define ARCHRS64C   1
#   define ARCHRS64III   1
#   error   "RS64III is not supported!"
#elif (defined(__s390x__) || defined(__s390x) || defined(__zarch__) || defined(__SYSC_ZARCH__))  // z/Architecture (SystemZ or S390X)
#   define ARCHS390   1
#   define ARCHS390X   1
#elif (defined(__THW_370__) || defined(__s390__) || defined(__s390) || defined(__systemz))  // System/390 (SystemZ)
#   define ARCHS390   1
#elif (defined(__SH__) || defined(_M_SH) || defined(__sh) || defined(__sh__) || defined(__superh__) || defined(__superh) || defined(__SUPERH__) || defined(__SUPERH) || defined(__sh1__) || defined(__sh2__) || defined(__sh3__) || defined(__sh4__) || defined(__sh5__) || defined(__SH1__) || defined(__SH2__) || defined(__SH3__) || defined(__SH4__) || defined(__SH5__))  // SuperH
#   define ARCHSUPERH   1
#elif (defined(__TMS470__) || defined(__tms470__) || defined(__TMS470) || defined(__tms470))  // TMS470
#   define ARCHTMS470   1
#   error   "TMS470 is not supported!"
#elif (defined(__VAX__) || defined(__vax__) || defined(__VAX) || defined(__vax) || defined(vax))  // VAX
#   define ARCHVAX   1
#   error   "VAX is not supported!"
#elif (defined(__XSTORMY__) || defined(__xstormy__) || defined(__XSTORMY) || defined(__xstormy) || defined(__xstormy16__) || defined(__XSTORMY16__))  // XStormy
#   define ARCHXSTORMY   1
#   error   "XStormy is not supported!"
#elif (defined(__XTENSA__) || defined(__xtensa__) || defined(__XTENSA) || defined(__xtensa))  // Xtensa
#   define ARCHXTENSA   1
#   error   "Xtensa is not supported!"
#elif (defined(__Z8000__) || defined(__z8000__) || defined(__Z8000) || defined(__z8000))  // Z8000
#   define ARCHZ8000   1
#   error   "Z8000 is not supported!"
#endif  // OTHER CPUS


// DATAMODELS

#if (defined(_LP64) || defined(__LP64__) || defined(_I32LP64) || defined(__I32LP64__))
#   define DATAMODEL_LP64   1
#   define DATAMODEL_I32LP64   1
#   define TYPESIZE_PTR   64
#   define __SIZEOF_POINTER__   8
#   define MKL_INT   signed long long
#   define MKL_LONG   signed long long
#   define __OFF_T_MATCHES_OFF64_T   1
#   define __INO_T_MATCHES_INO64_T   1
#elif (defined(_LP32) || defined(__LP32__))
#   define DATAMODEL_LP32   1
#   define TYPESIZE_PTR   32
#   define __SIZEOF_POINTER__   4
#   define MKL_INT   signed int
#elif (defined(_ILP32) || defined(__ILP32__))
#   define DATAMODEL_ILP32   1
#   define TYPESIZE_PTR   32
#   define __SIZEOF_POINTER__   4
#   define MKL_INT   signed int
#elif (defined(_ILP64) || defined(__ILP64__))
#   define DATAMODEL_ILP64   1
#   define TYPESIZE_PTR   64
#   define __SIZEOF_POINTER__   8
#   define MKL_INT   signed long
#   define MKL_LONG   signed long long
#elif (defined(_LLP64) || defined(__LLP64__))
#   define DATAMODEL_LLP64   1
#   define TYPESIZE_PTR   64
#   define __SIZEOF_POINTER__   8
#   define MKL_INT   signed int
#   define MKL_LONG   signed long long
#elif (defined(_SILP64) || defined(__SILP64__))
#   define DATAMODEL_SILP64   1
#   define TYPESIZE_PTR   64
#   define __SIZEOF_POINTER__   8
#   define MKL_INT   signed long
#   define MKL_LONG   signed long
#else
#   error   "Unknown datamodel!"
#endif
#ifndef _INTEGRAL_MAX_BITS
#   define _INTEGRAL_MAX_BITS   TYPESIZE_PTR
#endif
#define INTEGRAL_MAX_BITS   _INTEGRAL_MAX_BITS
#ifndef SIZEOF_POINTER
#   define SIZEOF_POINTER   __SIZEOF_POINTER__
#endif
#if ((!defined(KERNEL)) || (!defined(DATAMODEL_LP64)))
/** For 32-bit-specific linking code */
#   define KXLD_USER_OR_ILP32   1
#elif ((!defined(KERNEL)) || defined(DATAMODEL_LP64))
/** For 64-bit-specific linking code */
#   define KXLD_USER_OR_LP64   1
#elif ((!defined(KERNEL)) || defined(ARCHX86_64))
/** For x86_64-specific linking code */
#   define KXLD_USER_OR_X86_64   1
#elif ((!defined(KERNEL)) || defined(ARCHX86_32))
/** For i386-specific linking code */
#   define KXLD_USER_OR_I386   1
/** For linking code specific to architectures that support common symbols */
#   define KXLD_USER_OR_COMMON   1
/** For linking code specific to architectures that use MH_OBJECT */
#   define KXLD_USER_OR_OBJECT   1
#elif ((!defined(KERNEL)) || defined(ARCHAARCH64))
/** For arm64-specific linking code */
#   define KXLD_USER_OR_ARM64   11
#elif ((!defined(KERNEL)) || defined(ARCHAARCH32))
/** For arm-specific linking code */
#   define KXLD_USER_OR_ARM   11
#endif
/** For linking code specific to architectures that use MH_KEXT_BUNDLE */
#define KXLD_USER_OR_BUNDLE   1
#define KXLD_USER_OR_GOT   0
#ifndef KERNEL
/** For building the dysymtab command generation into the dylib */
#   define KXLD_PIC_KEXTS    1
#endif
#if (!(defined(_LOOSE_KERNEL_NAMES) && defined(__KERNEL_STRICT_NAMES)))
/** Suppress kernel-name space pollution unless user expressedly asks for it */
#   define __KERNEL_STRICT_NAMES
#endif


// CPU BIT-WIDTH

/** @def IS_32
Test if the system is 32-bit */
/** @def IS_64
Test if the system is 64-bit */
/** @def IS_128
Test if the system is 128-bit */
#if ((defined(DATAMODEL_LP64) || defined(DATAMODEL_LLP64) || defined(COMPILER_MINGW64) || defined(ARCHX86_64) || defined(ARCHAMD64) || defined(ARCHALPHA) || defined(ARCHITANIUM) || defined(ARCHAARCH64) || defined(ARCHMIPS64) || defined(ARCHPOWERPC64) || defined(ARCHS390X) || defined(ARCHSPARC64) || defined(OSWIN64) || defined(__arch64__) || defined(__64BIT__)) && !(defined(DATAMODEL_ILP32) || defined(DATAMODEL_LP32) || defined(ARCHBLACKFIN) || defined(ARCHCOLDFIRE) || defined(ARCHM68K) || defined(ARCHMICROBLAZE) || defined(ARCHNIOS) || defined(ARCHNIOS2) || defined(ARCHUNICORE) || defined(ARCHVAX) || defined(ARCHXTENSA)))
#   define IS_32   0
#   define IS_64   1
#   define IS_128   0
#else  // 32-bit
#   define IS_32   1
#   define IS_64   0
#   define IS_128   0
#endif
#if (IS_64 && defined(ARCHSUPERH))  // SUPERH64
#   define ARCHSUPERH64   1
#endif


// INSTRUCTION SET DESIGN

#if (defined(ARCHALPHA) || defined(ARCHAMBER) || defined(ARCHARC) || defined(ARCHARM) || defined(ARCHAVR) || defined(ARCHBLACKFIN) || defined(ARCHI960) || defined(ARCHMICROBLAZE) || defined(ARCHMIPS) || defined(ARCHNIOS) || defined(ARCHNIOS2) || defined(ARCHPARISC) || defined(ARCHPICOBLAZE) || defined(ARCHPOWERPC) || defined(ARCHSPARC) || defined(ARCHSUPERH) || defined(ARCHUNICORE) || defined(ARCHXTENSA))
#   define RISC   1
#   define IS_RISC   1
#   define IS_CISC   0
#   define IS_EPIC   0
#elif (defined(ARCHX86) || defined(ARCHCOLDFIRE) || defined(ARCHM68K) || defined(ARCHS390) || defined(ARCHVAX))
#   define CISC   1
#   define IS_RISC   0
#   define IS_CISC   1
#   define IS_EPIC   0
#elif defined(ARCHITANIUM)
/** Explicitly Parallel Instruction Computing (EPIC) */
#   define EPIC   1
#   define IS_RISC   0
#   define IS_CISC   0
#   define IS_EPIC   1
#else
#   error   "Add support for the target system (RISC/CISC)"
#endif


// FLOAT-POINT UNIT TYPE

/** @def IS_SOFTFP
Test if the platform emulates a FPU */
/** @def IS_HARDFP
Test if the platform has a physical FPU */
/** @def IS_NOT_SOFTFP
Test if the platform does not use soft-float-points */
#if ((defined(__SOFTFP__) || defined(_SOFT_FLOAT_) || defined(_SOFT_FLOAT) || defined(__TARGET_FPU_NONE) || defined(__mips_soft_float)) && (!(defined(__mips_hard_float) || defined(__mcffpu__) || defined(__VFP_FP__) || defined(__ARM_FP) || defined(__UCLIBC_HAS_FPU__))))
#   define IS_SOFTFP   1
#   define IS_HARDFP   0
#   define IS_NOT_SOFTFP   0
#elif (defined(__TARGET_FPU_SOFTVFP) || defined(__TARGET_FPU_VFP) || defined(__SOFTVFP__))
#   define IS_SOFTFP   1
#   define IS_HARDFP   1
#   define IS_NOT_SOFTFP   0
#else
#   define IS_SOFTFP   0
#   define IS_HARDFP   1
#   define IS_NOT_SOFTFP   1
#endif
#define FLOATS_ARE_IEEE   1
#if (IS_SOFTFP && defined(ARCHARM) && (!defined(ARM_HAVE_VFP)))
#   define ARM_HAVE_VFP   1
#elif (defined(ARCHARM))
#   define ARM_HAVE_VFP   0
#endif


// EXECUTABLE TYPE

/** @def IS_PIC
Test if the target will use Position Independent Code */
#if (defined(__pic__) || defined(__PIC__))
/** @def PIC
Defined if the target will use Position Independent Code */
#   if (__PIC__ == 1)
#      define PIC   1
#   elif (__PIC__ == 2)
#      define PIC   2
#      define PIC2   2
#   endif
#   define IS_PIC   1
#else
#      define IS_PIC   0
#endif
/** @def IS_PIE
Test if the target is a Position Independent Executable */
#if (defined(__pie__) || defined(__PIE__))
/** @def PIE
Defined if the target is a Position Independent Executable */
#   if (__PIE__ == 1)
#      define PIE   1
#   elif (__PIE__ == 2)
#      define PIE   (2)
#      define PIE2   (2)
#   endif
#   define IS_PIE   1
#else
#      define IS_PIE   0
#endif
/** @def IS_ELF
Test if the target is ELF */
#ifdef __ELF__
#   define IS_ELF   1
#else
#   define IS_ELF   0
#endif
/** @def IS_CODE_MODEL_SMALL
Test if the target is using a small code model */
#if (defined(__code_model_small__) && (__code_model_small__ == 1))
#   define IS_CODE_MODEL_SMALL   1
#else
#   define IS_CODE_MODEL_SMALL   0
#endif
#define SUPPORT_PRE_GM_10_5_EXECUTABLES   (ARCHI386 || ARCHPOWERPC)


// INTEL CONTROL-FLOW ENFORCEMENT TECHNOLOGY (CET)

/** @def IS_CET_ENABLED
Set to true if Intel Control-flow Enforcement Technology (CET) features are enabled and present */
#ifdef __CET__
#   define IS_CET_ENABLED   1
#else
#   define IS_CET_ENABLED   0
#endif


// RUNTIME MACROS

/** @def RUNTIME_NEXT
Set to true if the Next-Runtime is going to be used */
#ifdef __NEXT_RUNTIME__
#   define RUNTIME_NEXT   1
#else
#   define RUNTIME_NEXT   0
#endif


// SYMMETRIC MULTI-PROCESSING (SMP)

#if (defined(CONFIG_SMP) && (!defined(__SMP__)))
#   define __SMP__   1
#endif
#undef CONFIG_SMP
/** @def IS_SMP
Macros flag that indicates whether or not the target system supports Symmetric multiprocessing */
#if (defined(__SMP__) && __SMP__)
#   define IS_SMP   1
#   undef __SMP__
#   define __SMP__   1
#else
#   define IS_SMP   0
#   undef __SMP__
#endif


// MULTITHREADING & REENTRANCY MACROS

#define IS_THREAD_SAFE   1
#ifndef _THREAD_SAFE
#   define _THREAD_SAFE   1
#endif
#if ((!defined(_REENT_SMALL)) && (defined(_WANT_REENT_SMALL) || defined(ARCHMICROBLAZE)))
#   define _REENT_SMALL   1
#endif
#if ((!defined(USE_SMALL_REENT)) && defined(_REENT_SMALL))
#   define USE_SMALL_REENT   _REENT_SMALL
#elif ((!defined(_REENT_SMALL)) && defined(USE_SMALL_REENT))
#   undef USE_SMALL_REENT
#endif
#if (!(defined(_REENTRANT) || defined(__USE_REENTRANT) || defined(USE_SMALL_REENT)))
#   define _REENTRANT   0
#elif ((!defined(_REENTRANT)) && (defined(__USE_REENTRANT) || defined(USE_SMALL_REENT)))
#   define _REENTRANT   1
#endif
#ifndef __USE_REENTRANT
#   define __USE_REENTRANT   _REENTRANT
#endif
/** @def IS_REENTRANT
Code is reentrant if it can be interrupted in the middle of execution and then safely called again before previous invocations complete execution (reentrancy differs from thread-safety in multi-threaded environments). */
#if ((!defined(IS_REENTRANT)) && (_REENTRANT < 1))
#   define IS_REENTRANT   0
#elif ((!defined(IS_REENTRANT)) && (_REENTRANT > 0))
#   define IS_REENTRANT   1
#endif
#if ((!defined(__MULTI_THREAD__)) && (SUPPORTS_CILK || SUPPORTS_OPENACC || SUPPORTS_OPENMP))
#   define __MULTI_THREAD__
#endif
/** @def SINGLE_THREAD_P
Checks if the program is in single-threaded and avoids all cancellation save/restore code */
#if (defined(__SINGLE_THREAD__) && (SUPPORTS_CILK || SUPPORTS_OPENACC || SUPPORTS_OPENMP))
#   error   "The program cannot be compiled as a single-thread with Cilk, OpenACC, nor OpenMP!"
#elif (defined(__SINGLE_THREAD__) && defined(__MULTI_THREAD__))
#   error   "The program cannot be compiled as both single-threaded and multi-threaded!"
#elif defined(__MULTI_THREAD__)
#   undef SINGLE_THREAD_P
#   undef MULTI_THREAD_P
#   define SINGLE_THREAD_P   0
#   define MULTI_THREAD_P   1
#else
#   undef SINGLE_THREAD_P
#   undef MULTI_THREAD_P
#   define SINGLE_THREAD_P   1
#   define MULTI_THREAD_P   0
#endif
/** @def RTLD_SINGLE_THREAD_P
Checks if the program is in single-threaded and avoids all cancellation save/restore code */
#ifndef RTLD_SINGLE_THREAD_P
#   define RTLD_SINGLE_THREAD_P   SINGLE_THREAD_P
#endif
/** @def SUPPORTS_THREADS
Boolean macros flag that indicates if the program supports/uses threading */
#ifndef SUPPORTS_THREADS
#   define SUPPORTS_THREADS   SINGLE_THREAD_P
#endif
/** @def SUPPORTS_RTEMS
Indicates support for POSIX 1003.1b (such as threads & mutexes) */
#if ((!defined(SUPPORTS_RTEMS)) && defined(__rtems__))
#   define SUPPORTS_RTEMS   1
#elif (!defined(SUPPORTS_RTEMS))
#   define SUPPORTS_RTEMS   0
#endif
#if (!(SUPPORTS_RTEMS || defined(OSTIRTOS)))
#   define _STDIO_CLOSE_PER_REENT_STD_STREAMS   1
#endif
#if (SUPPORTS_THREADS && defined(_POSIX_THREADS) && (!SUPPORTS_RTEMS))
#   define _STDIO_WITH_THREAD_CANCELLATION_SUPPORT   1
#endif


// SANITIZER MACROS

#if ((!defined(SANITIZER_PRESENT)) && (defined(__SANITIZE_ADDRESS__) || defined(__SANITIZE_THREAD__)))
#   define SANITIZER_PRESENT   1
#elif (!defined(SANITIZER_PRESENT))
#   define SANITIZER_PRESENT   0
#endif
#define IS_SANITIZER_PRESENT   SANITIZER_PRESENT


// STACK PROTECTOR MACROS

#if ((!defined(STACK_PROTECTOR_PRESENT)) && (defined(__SSP__) || defined(__SSP_ALL__) || defined(__SSP_STRONG__) || defined(__SSP_EXPLICIT__)))
#   define STACK_PROTECTOR_PRESENT   1
#elif (!defined(STACK_PROTECTOR_PRESENT))
#   define STACK_PROTECTOR_PRESENT   0
#endif
#define IS_STACK_PROTECTOR_PRESENT   STACK_PROTECTOR_PRESENT
#if ((!defined(IS_STACK_PROTECTOR_STRONG)) && defined(__SSP_STRONG__))
#   define IS_STACK_PROTECTOR_STRONG   1
#elif (!defined(IS_STACK_PROTECTOR_STRONG))
#   define IS_STACK_PROTECTOR_STRONG   0
#endif
#if ((!defined(SSP_STRONG)) && IS_STACK_PROTECTOR_STRONG)
#   define SSP_STRONG   __SSP_STRONG__
#endif
#if ((!defined(IS_STACK_PROTECTOR_EXPLICIT)) && defined(__SSP_EXPLICIT__))
#   define IS_STACK_PROTECTOR_EXPLICIT   1
#elif (!defined(IS_STACK_PROTECTOR_EXPLICIT))
#   define IS_STACK_PROTECTOR_EXPLICIT   0
#endif


#endif  // FOUNDATION_H


/* STACK INFO */


#if (!(defined(STACKINFO_H) || defined(_STACKINFO_H_)))
#define STACKINFO_H   (1)
#define _STACKINFO_H   (1)
#define _STACKINFO_H_   (1)


// STACK

#ifdef ARCHXTENSA  // _STACK_GROWS_*
#   define _STACK_GROWS_DOWN   1
#elif (defined(ARCHX86) || defined(ARCHSUPERH))
#   define _STACK_GROWS_DOWN   1
#elif (defined(ARCHALPHA) || defined(ARCHARM) || defined(ARCHBLACKFIN))
#   define _STACK_GROWS_DOWN   1
#elif (defined(ARCHITANIUM) || defined(ARCHM68K) || defined(ARCHMICROBLAZE))
#   define _STACK_GROWS_DOWN   1
#elif (defined(ARCHMIPS) || defined(ARCHPOWERPC) || defined(ARCHSPARC))
#   define _STACK_GROWS_DOWN   1
#else
#   error   "Define `_STACK_GROWS_DOWN` or `_STACK_GROWS_UP` for the target architecture."
#endif

#ifdef _STACK_GROWS_DOWN
#   define STACK_DIRECTION   -1
#   define IS_STACK_DIRECTION_DOWN   1
#   define IS_STACK_DIRECTION_UP   0
#   define IS_STACK_DIRECTION_UKNOWN   0
#elif _STACK_GROWS_UP
#   define STACK_DIRECTION   1
#   define IS_STACK_DIRECTION_UP   1
#   define IS_STACK_DIRECTION_DOWN   0
#   define IS_STACK_DIRECTION_UKNOWN   0
#else  // Direction unknown
#   define STACK_DIRECTION   0
#   define IS_STACK_DIRECTION_UKNOWN   1
#   define IS_STACK_DIRECTION_DOWN   0
#   define IS_STACK_DIRECTION_UP   0
#endif
#define STACK_DIR   STACK_DIRECTION

#if IS_STACK_DIRECTION_DOWN
#   define FRAME_LEFT(frame, other)   ((char*)frame >= (char*)other)
#elif IS_STACK_DIRECTION_UP
#   define FRAME_LEFT(frame, other)   ((char*)frame <= (char*)other)
#else
#   error   "Define `_STACK_GROWS_DOWN` or `_STACK_GROWS_UP` for the target architecture."
#endif


// PAGE SIZE

#if (defined(ARCHARM) || defined(ARCHX86) || defined(ARCHSUPERH) || defined(ARCHPOWERPC) || defined(ARCHMIPS) || defined(ARCHMICROBLAZE) || defined(ARCHS390) || defined(ARCHPARISC) || defined(ARCHITANIUM))
#   define PAGE_SIZE   4096
#   define PAGE_SHIFT   12
#elif (defined(ARCHOR1K) || defined(ARCHALPHA) || defined(ARCHSPARC))
#   define PAGE_SIZE   8192
#   define PAGE_SHIFT   13
#else
#   define PAGE_SIZE   4096
#   define PAGE_SHIFT   12
#endif
#define PAGESIZE   PAGE_SIZE
#define PAGESHIFT   PAGE_SHIFT
#define PAGE_MASK   (~(PAGE_SIZE - 1))
#define NBPG   PAGE_SIZE
#define UPAGES   1


#endif  // STACKINFO_H


/* ENDIAN (<endian.h>) */


#if (!(defined(ENDIAN_H) || defined(_ENDIAN_H) || defined(_ENDIAN_H_)))
#define ENDIAN_H   (1)
#define _ENDIAN_H   (1)
#define _ENDIAN_H_   (1)
#define _BYTE_ORDER_H   (1)
#define _BYTE_ORDER_H_   (1)
#define _I386__ENDIAN_H_   (1)
#define _MACHINE_ENDIAN_H   (1)
#define _MACHINE_ENDIAN_H_   (1)
#define _BSD_MACHINE_ENDIAN_H_   (1)
#define _FBSD_COMPAT_MACHINE_ENDIAN_H   (1)
#define _FBSD_COMPAT_MACHINE_ENDIAN_H_   (1)
#define _FBSD_COMPAT_SYS_ENDIAN_H   (1)
#define _FBSD_COMPAT_SYS_ENDIAN_H_   (1)
#define _SYS_ENDIAN_H   (1)
#define _SYS_ENDIAN_H_   (1)
#define _SYS__ENDIAN_H_   (1)
#define _KLIBC_ENDIAN_H   (1)
#define _NLIBC_ENDIAN_H   (1)
#define _LINUX_BYTEORDER_BIG_ENDIAN_H   (1)
#define _LINUX_BYTEORDER_LITTLE_ENDIAN_H   (1)
#define _OS_OSENDIANHELPER_H   (1)


#if (defined(__THUMBEB__) || defined(__ARMEB__) || defined(__AARCH64EB__) || (!defined(__MAVERICK__)))
#   define ARM_BIG_ENDIAN    1
#elif (defined(__MAVERICK__) || defined(__THUMBEL__) || defined(__ARMEL__) || defined(__AARCH64EL__))
#   define ARM_LITTLE_ENDIAN    1
#elif defined(__MICROBLAZEEB__)
#   define MICROBLAZE_BIG_ENDIAN    1
#elif defined(__MICROBLAZEEL__)
#   define MICROBLAZE_LITTLE_ENDIAN    1
#elif (defined(__MIPSEB__) || defined(_MIPSEB) || defined(__MIPSEB))
#   define MIPS_BIG_ENDIAN    1
#elif (defined(__MIPSEL__) || defined(_MIPSEL) || defined(__MIPSEL))
#   define MIPS_LITTLE_ENDIAN    1
#elif defined(__nios2_big_endian__)
#   define NIOS2_BIG_ENDIAN    1
#elif defined(__nios2_little_endian__)
#   define NIOS2_LITTLE_ENDIAN    1
#elif defined(__nios_big_endian__)
#   define NIOS_BIG_ENDIAN    1
#elif defined(__nios_little_endian__)
#   define NIOS_LITTLE_ENDIAN    1
#elif defined(ppc64be)
#   define POWERPC_BIG_ENDIAN    1
#   define POWERPC64_BIG_ENDIAN    1
#elif defined(ppc64le)
#   define POWERPC_LITTLE_ENDIAN    1
#   define POWERPC64_LITTLE_ENDIAN    1
#elif defined(ppc32be)
#   define POWERPC_BIG_ENDIAN    1
#   define POWERPC32_BIG_ENDIAN    1
#elif defined(ppc32le)
#   define POWERPC_LITTLE_ENDIAN    1
#   define POWERPC32_LITTLE_ENDIAN    1
#endif


#define OSUnknownByteOrder   1
#define UnknownByteOrder   1
#define OSLittleEndian   2
#define LittleEndian   2
#define OSBigEndian   3
#define BigEndian   3
#ifndef __ORDER_BIG_ENDIAN__
#   define __ORDER_BIG_ENDIAN__   (4321)
#endif
#ifndef __ORDER_LITTLE_ENDIAN__
#   define __ORDER_LITTLE_ENDIAN__   (1234)
#endif
#ifndef __ORDER_PDP_ENDIAN__
/** Little-endian (word-swapped) */
#   define __ORDER_PDP_ENDIAN__   (3412)
#endif
#define __BIG_ENDIAN   __ORDER_BIG_ENDIAN__
#define _BIG_ENDIAN   __ORDER_BIG_ENDIAN__
#define __LITTLE_ENDIAN   __ORDER_LITTLE_ENDIAN__
#define _LITTLE_ENDIAN   __ORDER_LITTLE_ENDIAN__
/** PDP-endian (word-swapped/middle-endian) */
#define __PDP_ENDIAN   __ORDER_PDP_ENDIAN__
/** PDP-endian (word-swapped/middle-endian) */
#define _PDP_ENDIAN   __ORDER_PDP_ENDIAN__
#define BIG_ENDIAN   __ORDER_BIG_ENDIAN__
#define LITTLE_ENDIAN   __ORDER_LITTLE_ENDIAN__
/** PDP-endian (word-swapped/middle-endian/mixed-endian) */
#define PDP_ENDIAN   __ORDER_PDP_ENDIAN__
#ifndef NETWORK_BYTE_ORDER
#   define NETWORK_BYTE_ORDER   __ORDER_BIG_ENDIAN__
#endif
#ifndef __NETWORK_BYTE_ORDER__
#   define __NETWORK_BYTE_ORDER__   __ORDER_BIG_ENDIAN__
#endif
// Some machines may need to use a different endianness for floating-point values
#if (defined(__FLOAT_WORD_ORDER__) || defined(__FLOAT_WORD_ORDER) || defined(FLOAT_WORD_ORDER))
#   ifdef __FLOAT_WORD_ORDER__
#      undef __FLOAT_WORD_ORDER
#      undef FLOAT_WORD_ORDER
#      define __FLOAT_WORD_ORDER   __FLOAT_WORD_ORDER__
#      define FLOAT_WORD_ORDER   __FLOAT_WORD_ORDER__
#   elif (defined(__FLOAT_WORD_ORDER))
#      undef __FLOAT_WORD_ORDER__
#      undef FLOAT_WORD_ORDER
#      define __FLOAT_WORD_ORDER__   __FLOAT_WORD_ORDER
#      define FLOAT_WORD_ORDER   __FLOAT_WORD_ORDER
#   elif (defined(FLOAT_WORD_ORDER))
#      undef __FLOAT_WORD_ORDER__
#      undef __FLOAT_WORD_ORDER
#      define __FLOAT_WORD_ORDER__   FLOAT_WORD_ORDER
#      define __FLOAT_WORD_ORDER   FLOAT_WORD_ORDER
#   endif
#else
#   define __FLOAT_WORD_ORDER__   __ORDER_LITTLE_ENDIAN__
#   define __FLOAT_WORD_ORDER   __ORDER_LITTLE_ENDIAN__
#   define FLOAT_WORD_ORDER   __ORDER_LITTLE_ENDIAN__
#endif
#if (FLOAT_WORD_ORDER == __ORDER_LITTLE_ENDIAN__)
#   define IS_FLOAT_LITTLE_ENDIAN   1
#   define IS_FLOAT_BIG_ENDIAN   0
#elif (FLOAT_WORD_ORDER == __ORDER_BIG_ENDIAN__)
#   define IS_FLOAT_LITTLE_ENDIAN   0
#   define IS_FLOAT_BIG_ENDIAN   1
#endif
#ifdef ARCHARM
#   ifdef ARM_BIG_ENDIAN
#      define IEEE_DOUBLE_MIXED_ENDIAN   0
#      define IEEE_DOUBLE_BIG_ENDIAN   1
#   elif IS_SOFTFP
#      define IEEE_DOUBLE_MIXED_ENDIAN   0
#      define IEEE_DOUBLE_BIG_ENDIAN   0
#   else
#      define IEEE_DOUBLE_BIG_ENDIAN   0
#      define IEEE_DOUBLE_MIXED_ENDIAN   1
#   endif
#elif defined(ARCHSUPERH)
#   define IEEE_DOUBLE_BIG_ENDIAN   0
#   define IEEE_DOUBLE_MIXED_ENDIAN   1
#endif
#if ((!defined(IEEE_DOUBLE_BIG_ENDIAN)) && (defined(ARCHNIOS2) || defined(ARCHS390) || defined(ARCHX86)))
#   define IEEE_DOUBLE_BIG_ENDIAN   0
#endif
#if (!(defined(BFS_LITTLE_ENDIAN_ONLY) || defined(BFS_BIG_ENDIAN_ONLY)))
#   define BFS_LITTLE_ENDIAN_ONLY   1
#endif


#if ((!defined(__BYTE_ORDER__)) && (defined(MIPS_BIG_ENDIAN) || defined(ARM_BIG_ENDIAN) || defined(POWERPC_BIG_ENDIAN) || defined(MICROBLAZE_BIG_ENDIAN) || defined(NIOS_BIG_ENDIAN) || defined(NIOS2_BIG_ENDIAN) || defined(ARCHAVR) || defined(ARCHCOLDFIRE) || defined(ARCHPARISC) || defined(ARCHS390)))
#   define __BYTE_ORDER__   __ORDER_BIG_ENDIAN__
#elif ((!defined(__BYTE_ORDER__)) && (defined(MIPS_LITTLE_ENDIAN) || defined(ARM_LITTLE_ENDIAN) || defined(POWERPC_LITTLE_ENDIAN) || defined(MICROBLAZE_LITTLE_ENDIAN) || defined(NIOS_LITTLE_ENDIAN) || defined(NIOS2_LITTLE_ENDIAN) || defined(ARCHBLACKFIN) || defined(ARCHUNICORE) || defined(ARCHVAX)))
#   define __BYTE_ORDER__   __ORDER_LITTLE_ENDIAN__
#elif (!defined(__BYTE_ORDER__))
#   define __BYTE_ORDER__   __ORDER_LITTLE_ENDIAN__
#endif
#undef __BYTE_ORDER
#undef _BYTE_ORDER
#undef BYTE_ORDER
#define __BYTE_ORDER   __BYTE_ORDER__
#define _BYTE_ORDER   __BYTE_ORDER__
#define BYTE_ORDER   __BYTE_ORDER__


#if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#   define __LONG_LONG_PAIR(HI, LO)   LO, HI
#   undef BIG_ENDI
#   define LITTLE_ENDI   1
#   define HIGH_HALF   1
#   define LOW_HALF   0
#   define IS_LITTLE_ENDIAN   1
#   define IS_BIG_ENDIAN   0
#   define IS_PDP_ENDIAN   0
#   define ENDIAN_LITTLE   1
#   define B_HOST_IS_LENDIAN   1
#   define B_HOST_IS_BENDIAN   0
#   ifndef _QUAD_HIGHWORD
#      define _QUAD_HIGHWORD   1
#   endif
#   ifndef _QUAD_LOWWORD
#      define _QUAD_LOWWORD   0
#   endif
#   ifndef __LITTLE_ENDIAN_BITFIELD
#      define __LITTLE_ENDIAN_BITFIELD   1
#   endif
#   define _ISbit(bit)   (((bit) < 8) ? ((1 << (bit)) << 8) : ((1 << (bit)) >> 8))
#   define PADDED(x, y)   x, y
#   define OSHostByteOrder()   OSLittleEndian
#elif (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#   define __LONG_LONG_PAIR(HI, LO)   HI, LO
#   define BIG_ENDI   1
#   undef LITTLE_ENDI
#   define HIGH_HALF   0
#   define LOW_HALF   1
#   define IS_BIG_ENDIAN   1
#   define IS_LITTLE_ENDIAN   0
#   define IS_PDP_ENDIAN   0
#   define ENDIAN_BIG   1
#   define B_HOST_IS_LENDIAN   0
#   define B_HOST_IS_BENDIAN   1
#   ifndef _QUAD_HIGHWORD
#      define _QUAD_HIGHWORD   0
#   endif
#   ifndef _QUAD_LOWWORD
#      define _QUAD_LOWWORD   1
#   endif
#   ifndef __BIG_ENDIAN_BITFIELD
#      define __BIG_ENDIAN_BITFIELD   1
#   endif
#   define _ISbit(bit)   (1 << (bit))
#   define PADDED(x, y)   y, x
#   define OSHostByteOrder()   OSBigEndian
#elif (__BYTE_ORDER__ == __ORDER_PDP_ENDIAN__)
#   error   "PDP byte-order is not supported!"
#   undef BIG_ENDI
#   undef LITTLE_ENDI
#   define IS_PDP_ENDIAN   1
#   define IS_LITTLE_ENDIAN   0
#   define IS_BIG_ENDIAN   0
#   define ENDIAN_PDP   1
#   ifndef __PDP_ENDIAN_BITFIELD
#      define __PDP_ENDIAN_BITFIELD   1
#   endif
#   define OSHostByteOrder()   OSUnknownByteOrder
#else
#   error   "Unknown byte-order/endianness!"
#endif
#define ISbit(bit)   _ISbit((bit))
#define isbit(bit)   _ISbit((bit))
#define __isbit(bit)   _ISbit((bit))
#define __isbit__(bit)   _ISbit((bit))


#if (defined(ARCHALPHA) || defined(ARCHARM) || defined(ARCHITANIUM) || defined(ARCHMICROBLAZE) || defined(ARCHMIPS) || defined(ARCHPOWERPC) || defined(ARCHSPARC64) || defined(ARCHSUPERH))
#   define BI_ENDIAN   1
#   define IS_BI_ENDIAN   1
#else
#   define IS_BI_ENDIAN   0
#endif


/** Swap directions */
typedef enum swap_action {
	B_SWAP_HOST_TO_LENDIAN,
	B_SWAP_HOST_TO_BENDIAN,
	B_SWAP_LENDIAN_TO_HOST,
	B_SWAP_BENDIAN_TO_HOST,
	B_SWAP_ALWAYS
} swap_action;


#endif  // ENDIAN_H


/* DATATYPE SUPPORT */


#if (!(defined(DATATYPE_SUPPORT_H) || defined(_DATATYPE_SUPPORT_H_)))
#define DATATYPE_SUPPORT_H   (1)
#define _DATATYPE_SUPPORT_H_   (1)


// INTEGER DATATYPE SUPPORT

#if (defined(__CHAR_UNSIGNED__) && (__CHAR_UNSIGNED__ == 1))  // -funsigned-char
#   define IS_CHAR_UNSIGNED   1
#   define IS_CHAR_SIGNED   0
#else
#   ifndef __CHAR_SIGNED__
#      define __CHAR_SIGNED__   1
#   endif
#   define IS_CHAR_UNSIGNED   0
#   define IS_CHAR_SIGNED   1
#endif
#if (defined(__WINT_UNSIGNED__) && (__WINT_UNSIGNED__ >= 1))
#   define IS_WINT_UNSIGNED   1
#   define IS_WINT_SIGNED   0
#else
#   ifndef __WINT_SIGNED__
#      define __WINT_SIGNED__   1
#   endif
#   define IS_WINT_UNSIGNED   0
#   define IS_WINT_SIGNED   1
#endif
#ifndef HAVE_LONG_INT
#   define HAVE_LONG_INT   1
#endif
#ifndef HAVE_LONG_LONG_INT
#   define HAVE_LONG_LONG_INT   1
#endif
#ifndef HAVE_LONG_LONG
#   define HAVE_LONG_LONG   HAVE_LONG_LONG_INT
#endif
#ifndef HAVE_INT2
#   define HAVE_INT2   0
#endif
#ifndef HAVE_INT4
#   define HAVE_INT4   0
#endif
#ifndef HAVE_INT8
#   define HAVE_INT8   1
#endif
#ifndef HAVE_INT16
#   define HAVE_INT16   1
#endif
/** @def HAVE_INT24
Indicates that 24-bit integer types are supported by the compiler */
#if ((!defined(HAVE_INT24)) && (defined(__UINT24_TYPE__) || defined(__INT24_TYPE__) || defined(__INT24_C_SUFFIX__) || defined(__INT24_C) || defined(__INT24_MAX__) || defined(ARCHAVR)))
#   define HAVE_INT24   1
#else
#   define HAVE_INT24   0
#endif
/** Indicates that 24-bit integer types are supported by the compiler */
#define SUPPORTS_INT24   HAVE_INT24
#define SUPPORTS_UINT24   HAVE_INT24
#ifndef HAVE_INT32
#   define HAVE_INT32   1
#endif
/** @def HAVE_INT40
Indicates that 40-bit integer types are supported by the compiler */
#if ((!defined(HAVE_INT40)) && (defined(__UINT40_TYPE__) || defined(__INT40_TYPE__) || defined(__INT40_C_SUFFIX__) || defined(__INT40_C) || defined(__INT40_MAX__) || defined(ARCHAVR)))
#   define HAVE_INT40   1
#else
#   define HAVE_INT40   0
#endif
/** Indicates that 40-bit integer types are supported by the compiler */
#define SUPPORTS_INT40   HAVE_INT40
#define SUPPORTS_UINT40   HAVE_INT40
/** @def HAVE_INT48
Indicates that 48-bit integer types are supported by the compiler */
#if ((!defined(HAVE_INT48)) && (defined(__UINT48_TYPE__) || defined(__INT48_TYPE__) || defined(__INT48_C_SUFFIX__) || defined(__INT48_C) || defined(__INT48_MAX__) || defined(ARCHAVR)))
#   define HAVE_INT48   1
#else
#   define HAVE_INT48   0
#endif
/** Indicates that 48-bit integer types are supported by the compiler */
#define SUPPORTS_INT48   HAVE_INT48
#define SUPPORTS_UINT48   HAVE_INT48
/** @def HAVE_INT56
Indicates that 56-bit integer types are supported by the compiler */
#if ((!defined(HAVE_INT56)) && (defined(__UINT56_TYPE__) || defined(__INT56_TYPE__) || defined(__INT56_C_SUFFIX__) || defined(__INT56_C) || defined(__INT56_MAX__) || defined(ARCHAVR)))
#   define HAVE_INT56   1
#else
#   define HAVE_INT56   0
#endif
/** Indicates that 56-bit integer types are supported by the compiler */
#define SUPPORTS_INT56   HAVE_INT56
#define SUPPORTS_UINT56   HAVE_INT56
/** @def SUPPORTS_INT64
Indicates that 64-bit integer types are supported by the compiler */
#if ((!defined(HAVE_INT64)) && (defined(__UINT64_TYPE__) || defined(__INT64_TYPE__) || defined(__INT64_C_SUFFIX__) || defined(__INT64_C) || defined(__INT64_MAX__)))
#   define HAVE_INT64   1
#else
#   define HAVE_INT64   0
#endif
#define SUPPORTS_INT64   HAVE_INT64
#define SUPPORTS_UINT64   HAVE_INT64
#if ((defined(SIZEOF_INT128) || defined(__SIZEOF_INT128__) || defined(BOOST_HAS_INT128) || defined(__int128_t) || defined(__uint128_t) || defined(__uint128)) || (defined(_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS > 64)))
#   define HAVE_INT128   1
#else
#   define HAVE_INT128   0
#endif
#define SUPPORTS_INT128   HAVE_INT128
#define SUPPORTS_UINT128   HAVE_INT128
#if ((defined(SIZEOF_INT256) || defined(__SIZEOF_INT256__) || defined(BOOST_HAS_INT256) || defined(__int256_t) || defined(__uint256_t) || defined(__uint256)) || (defined(_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS > 128)))
#   define HAVE_INT256   1
#else
#   define HAVE_INT256   0
#endif
#define SUPPORTS_INT256   HAVE_INT256
#define SUPPORTS_UINT256   HAVE_INT256
#if ((defined(SIZEOF_INT512) || defined(__SIZEOF_INT512__) || defined(BOOST_HAS_INT512) || defined(__int512_t) || defined(__uint512_t) || defined(__uint512)) || (defined(_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS > 256)))
#   define HAVE_INT512   1
#else
#   define HAVE_INT512   0
#endif
#define SUPPORTS_INT512   HAVE_INT512
#define SUPPORTS_UINT512   HAVE_INT512


// FLOAT-POINT DATATYPE SUPPORT

#if (defined(__SIZEOF_FLOAT8__) || defined(SIZEOF_FLOAT8) || defined(__FLT8_DIG__) || defined(__ARM_FP8_FORMAT_IEEE) || defined(ARCHAVR))
#   define SUPPORTS_MINIFLOAT   1
#   define SUPPORTS_FLOAT8   1
#else
#   define SUPPORTS_MINIFLOAT   0
#   define SUPPORTS_FLOAT8   0
#endif
#if (defined(__SIZEOF_FLOAT16__) || defined(SIZEOF_FLOAT16) || defined(__FLT16_DIG__) || defined(__ARM_FP16_FORMAT_IEEE) || defined(ARCHAVR))
#   define SUPPORTS_FLOAT16   1
#else
#   define SUPPORTS_FLOAT16   0
#endif
#if (defined(__SIZEOF_FLOAT24__) || defined(SIZEOF_FLOAT24) || defined(__FLT24_DIG__) || defined(__ARM_FP24_FORMAT_IEEE) || defined(ARCHAVR))
#   define SUPPORTS_FLOAT24   1
#else
#   define SUPPORTS_FLOAT24   0
#endif
#if (defined(__SIZEOF_FLOAT32__) || defined(SIZEOF_FLOAT32) || defined(__SIZEOF_FLOAT__) || defined(SIZEOF_FLOAT) || defined(__FLT32_DIG__))
#   define SUPPORTS_FLOAT32   1
#else
#   define SUPPORTS_FLOAT32   0
#endif
#if (defined(__SIZEOF_FLOAT80__) || defined(SIZEOF_FLOAT80))
#   define SUPPORTS_FLOAT80   1
#else
#   define SUPPORTS_FLOAT80   0
#endif
#if (defined(__SIZEOF_FLOAT96__) || defined(SIZEOF_FLOAT96))
#   define SUPPORTS_FLOAT96   1
#else
#   define SUPPORTS_FLOAT96   0
#endif
/** @def SUPPORTS_FLOAT128
Boolean macro for indicating support for float128. 128-bit quad-precision floats may be supported via the synonymous datatypes tetra, float128_t, __float128, and float128 */
#if (defined(__SIZEOF_FLOAT128__) || defined(SIZEOF_FLOAT128) || defined(__FLT128_DIG__) || (defined(__SIZEOF_LONG_DOUBLE__) && __SIZEOF_LONG_DOUBLE__ == 16))
#   define SUPPORTS_FLOAT128   1
#else
#   define SUPPORTS_FLOAT128   0
#endif
/** @def SUPPORTS_FLOAT256
Boolean macro for indicating support for float256. 256-bit octa-precision floats may be supported via the synonymous datatypes float256_t, __float256, and float256 */
#if (defined(__SIZEOF_FLOAT256__) || defined(SIZEOF_FLOAT256) || defined(__FLT256_DIG__))
#   define SUPPORTS_FLOAT256   1
#else
#   define SUPPORTS_FLOAT256   0
#endif
/** @def SUPPORTS_FLOAT512
Boolean macro for indicating support for float512. 512-bit hexadeca-precision floats may be supported via the synonymous datatypes float512_t, __float512, and float512 */
#if (defined(__SIZEOF_FLOAT512__) || defined(SIZEOF_FLOAT512) || defined(__FLT512_DIG__))
#   define SUPPORTS_FLOAT512   1
#else
#   define SUPPORTS_FLOAT512   0
#endif
/** @def SUPPORTS_F32
Indicates support for the `F32` datatype literal suffix */
#ifdef __FLT32_DIG__
#   define SUPPORTS_F32   1
#else
#   define SUPPORTS_F32   0
#endif
/** @def SUPPORTS_F32X
Indicates support for the `F32x` datatype literal suffix */
#ifdef __FLT32X_DIG__
#   define SUPPORTS_F32X   1
#else
#   define SUPPORTS_F32X   0
#endif
/** @def SUPPORTS_F64
Indicates support for the `F64` datatype literal suffix */
#ifdef __FLT64_DIG__
#   define SUPPORTS_F64   1
#else
#   define SUPPORTS_F64   0
#endif
/** @def SUPPORTS_F64X
Indicates support for the `F64x` datatype literal suffix */
#ifdef __FLT64X_DIG__
#   define SUPPORTS_F64X   1
#else
#   define SUPPORTS_F64X   0
#endif
/** @def SUPPORTS_F128
Indicates support for the `F128` datatype literal suffix */
#ifdef __FLT128_DIG__
#   define SUPPORTS_F128   1
#else
#   define SUPPORTS_F128   0
#endif


// LONG DOUBLE SUPPORT

#if (defined(__WANT_LONG_DOUBLE_FORMAT__) || (defined(__LONG_DOUBLE_128__) || defined(__LONG_DOUBLE_64__) || defined(__LONG_DOUBLE_x87__) || defined(__LONG_DOUBLE_80__) || defined(__LONG_DOUBLE_96__)))  // MATH_DECLARE_LDOUBLE
#   undef __WANT_LONG_DOUBLE_FORMAT__
#   undef __NO_LONG_DOUBLE_MATH
#   undef NO_LONG_DOUBLE_MATH
#   undef NO_LDOUBLE_MATH
#   undef __MATH_DECLARE_LDOUBLE
#   define __MATH_DECLARE_LDOUBLE   0
#endif
#ifdef __LONG_DOUBLE_128__  // __WANT_LONG_DOUBLE_FORMAT__
#   define __WANT_LONG_DOUBLE_FORMAT__   128
#elif defined(__LONG_DOUBLE_64__)
#   define __WANT_LONG_DOUBLE_FORMAT__   64
#elif (defined(__LONG_DOUBLE_80__) || defined(__LONG_DOUBLE_x87__))
#   define __WANT_LONG_DOUBLE_FORMAT__   80
#elif defined(__LONG_DOUBLE_96__)
#   define __WANT_LONG_DOUBLE_FORMAT__   96
#endif
// Enables/Disables the declaration of all the `long double` functions
#if (defined(__NO_LONG_DOUBLE_MATH) || defined(NO_LONG_DOUBLE_MATH) || defined(NO_LDOUBLE_MATH) || (!defined(__SIZEOF_LONG_DOUBLE__)))
#   undef __LONG_DOUBLE_MATH_OPTIONAL
#   undef LONG_DOUBLE_MATH_OPTIONAL
#   undef __MATH_DECLARE_LDOUBLE
#   undef __NO_LONG_DOUBLE_MATH
#   undef NO_LONG_DOUBLE_MATH
#   undef NO_LDOUBLE_MATH
#   undef SUPPORTS_LONG_DOUBLE
#   define __LONG_DOUBLE_MATH_OPTIONAL   0
#   define LONG_DOUBLE_MATH_OPTIONAL   0
#   define __MATH_DECLARE_LDOUBLE   0
#   define __NO_LONG_DOUBLE_MATH   1
#   define NO_LONG_DOUBLE_MATH   1
#   define NO_LDOUBLE_MATH   1
#   define SUPPORTS_LONG_DOUBLE   0
#elif ((defined(__LONG_DOUBLE_MATH_OPTIONAL) || defined(LONG_DOUBLE_MATH_OPTIONAL) || defined(__MATH_DECLARE_LDOUBLE)) && (defined(__SIZEOF_LONG_DOUBLE__) || defined(SIZEOF_LONG_DOUBLE) || defined(__LONGDOUBLE64)))
#   undef __LONG_DOUBLE_MATH_OPTIONAL
#   undef LONG_DOUBLE_MATH_OPTIONAL
#   undef __MATH_DECLARE_LDOUBLE
#   undef __NO_LONG_DOUBLE_MATH
#   undef NO_LONG_DOUBLE_MATH
#   undef NO_LDOUBLE_MATH
#   undef SUPPORTS_LONG_DOUBLE
#   define __LONG_DOUBLE_MATH_OPTIONAL   1
#   define LONG_DOUBLE_MATH_OPTIONAL   1
#   define __MATH_DECLARE_LDOUBLE   1
#   define __NO_LONG_DOUBLE_MATH   0
#   define NO_LONG_DOUBLE_MATH   0
#   define NO_LDOUBLE_MATH   0
#   define SUPPORTS_LONG_DOUBLE   1
#else
#   undef SUPPORTS_LONG_DOUBLE
#   undef __LONG_DOUBLE_MATH_OPTIONAL
#   undef LONG_DOUBLE_MATH_OPTIONAL
#   undef __MATH_DECLARE_LDOUBLE
#   undef __NO_LONG_DOUBLE_MATH
#   undef NO_LONG_DOUBLE_MATH
#   undef NO_LDOUBLE_MATH
#   define __LONG_DOUBLE_MATH_OPTIONAL   1
#   define LONG_DOUBLE_MATH_OPTIONAL   1
#   define __MATH_DECLARE_LDOUBLE   1
#   define __NO_LONG_DOUBLE_MATH   0
#   define NO_LONG_DOUBLE_MATH   0
#   define NO_LDOUBLE_MATH   0
#   define SUPPORTS_LONG_DOUBLE   1
#endif  // SUPPORTS_LONG_DOUBLE
#if (SUPPORTS_LONG_DOUBLE && (defined(__LDBL_MAX_EXP__) && (__LDBL_MAX_EXP__ > 999999)))
#   error   "Float-point buffers are too small!"
#endif


// DECIMAL-FLOAT-POINT DATATYPE SUPPORT

/** @def SUPPORTS_DECIMAL_FLOATS
If this macro equals 1, then decimal float-points are supported. Conforms to the ISO/IEC/IEEE 60559 (IEEE754-2008/IEC559) standards for decimal floating-points. Industry standard for representing decimal floating-point numbers. */
#if (defined(__STDC_DEC_FP__) || defined(__STDC_WANT_DEC_FP__) || defined(__IBM_DFP__) || defined(__DEC32_MAX__) || defined(__DEC64_MAX__) || defined(__DEC32_EPSILON__))
#   define SUPPORTS_DECIMAL_FLOATS   1
#   define SUPPORTS_DECIMAL32   1
#   define SUPPORTS_DECIMAL64   1
#else
#   define SUPPORTS_DECIMAL_FLOATS   0
#   define SUPPORTS_DECIMAL32   0
#   define SUPPORTS_DECIMAL64   0
#endif
/** @def SUPPORTS_DECIMAL128
If this macro equals 1, then long double decimal numbers (decimal128) are supported */
#if (SUPPORTS_DECIMAL_FLOATS && (defined(__DEC128_MAX__) || defined(__DEC128_MAX_EXP__)))
#   define SUPPORTS_DECIMAL128   1
#else
#   define SUPPORTS_DECIMAL128   0
#endif
/** @def SUPPORTS_DECIMAL256
If this macro equals 1, then decimal256 are supported */
#if (SUPPORTS_DECIMAL_FLOATS && (defined(__DEC256_MAX__) || defined(__DEC256_MAX_EXP__)))
#   define SUPPORTS_DECIMAL256   1
#else
#   define SUPPORTS_DECIMAL256   0
#endif
/** @def SUPPORTS_DECIMAL512
If this macro equals 1, then decimal512 are supported */
#if (SUPPORTS_DECIMAL_FLOATS && (defined(__DEC512_MAX__) || defined(__DEC512_MAX_EXP__)))
#   define SUPPORTS_DECIMAL512   1
#else
#   define SUPPORTS_DECIMAL512   0
#endif


// COMPLEX DATATYPE SUPPORT

#if (((defined(__STDC_IEC_559_COMPLEX__) && (__STDC_IEC_559_COMPLEX__ > 0)) || (defined(__GCC_IEC_559_COMPLEX) && (__GCC_IEC_559_COMPLEX > 0))) && (!(defined(COMPILER_CLANG) && (defined(NEEDS_STARTUP) || defined(USE_BAREBONES)))))
#   define SUPPORTS_COMPLEX   1
#   define SUPPORTS_IMAGINARY   1
#   if SUPPORTS_LONG_DOUBLE
#      define SUPPORTS_COMPLEX_LDBL   1
#   endif
#   if ((!defined(COMPILER_CLANG)) && ((defined(__SIZEOF_LONG_DOUBLE__) && (__SIZEOF_LONG_DOUBLE__ == 10)) || (__SIZEOF_LONG_DOUBLE__ == 12)))
#      define SUPPORTS_COMPLEX_X87   1
#   else
#      define SUPPORTS_COMPLEX_X87   0
#   endif
#   if (SUPPORTS_FLOAT128 || (defined(__SIZEOF_LONG_DOUBLE__) && (__SIZEOF_LONG_DOUBLE__ == 16)))
#      define SUPPORTS_COMPLEX_FLOAT128   1
#   else
#      define SUPPORTS_COMPLEX_FLOAT128   0
#   endif
#   if SUPPORTS_FLOAT256
#      define SUPPORTS_COMPLEX_FLOAT256   1
#   else
#      define SUPPORTS_COMPLEX_FLOAT256   0
#   endif
#   if SUPPORTS_FLOAT512
#      define SUPPORTS_COMPLEX_FLOAT512   1
#   else
#      define SUPPORTS_COMPLEX_FLOAT512   0
#   endif
#else
#   define SUPPORTS_COMPLEX   0
#   define SUPPORTS_IMAGINARY   0
#   define SUPPORTS_COMPLEX_LDBL   0
#   define SUPPORTS_COMPLEX_X87   0
#   define SUPPORTS_COMPLEX_FLOAT128   0
#   define SUPPORTS_COMPLEX_FLOAT256   0
#   define SUPPORTS_COMPLEX_FLOAT512   0
#endif
#if (SUPPORTS_COMPLEX && (defined(__SIZEOF_COMPLEX_INT__)))
#   ifndef SUPPORTS_COMPLEX_INT
#      define SUPPORTS_COMPLEX_INT   1
#   endif
#   ifndef SUPPORTS_COMPLEX_INT8
#      define SUPPORTS_COMPLEX_INT8   1
#   endif
#   ifndef SUPPORTS_COMPLEX_INT16
#      define SUPPORTS_COMPLEX_INT16   1
#   endif
#   ifndef SUPPORTS_COMPLEX_INT32
#      define SUPPORTS_COMPLEX_INT32   1
#   endif
#   ifndef SUPPORTS_COMPLEX_INT64
#      define SUPPORTS_COMPLEX_INT64   1
#   endif
#   if SUPPORTS_INT128
#      define SUPPORTS_COMPLEX_INT128   1
#   else
#      define SUPPORTS_COMPLEX_INT128   0
#   endif
#   if SUPPORTS_INT256
#      define SUPPORTS_COMPLEX_INT256   1
#   else
#      define SUPPORTS_COMPLEX_INT256   0
#   endif
#   if SUPPORTS_INT512
#      define SUPPORTS_COMPLEX_INT512   1
#   else
#      define SUPPORTS_COMPLEX_INT512   0
#   endif
#else
#   define SUPPORTS_COMPLEX_INT   0
#   define SUPPORTS_COMPLEX_INT8   0
#   define SUPPORTS_COMPLEX_INT16   0
#   define SUPPORTS_COMPLEX_INT32   0
#   define SUPPORTS_COMPLEX_INT64   0
#   define SUPPORTS_COMPLEX_INT128   0
#   define SUPPORTS_COMPLEX_INT256   0
#   define SUPPORTS_COMPLEX_INT512   0
#endif


// STDFIX DATATYPE SUPPORT

#if (defined(__SFRACT_IBIT__) || defined(__SFRACT_MIN__) || defined(__SFRACT_MAX__) || defined(__USACCUM_EPSILON__) || defined(__USACCUM_MIN__) || defined(__HQ_FBIT__) || defined(__SA_IBIT__))
#   define SUPPORTS_STDFIX   1
#   define SUPPORTS_ACCUM   1
#   define SUPPORTS_FRACT   1
#   define SUPPORTS_SAT   1
#else
#   define SUPPORTS_STDFIX   0
#   define SUPPORTS_ACCUM   0
#   define SUPPORTS_FRACT   0
#   define SUPPORTS_SAT   0
#endif


#endif  // DATATYPE_SUPPORT_H


/* DATATYPE SIZES & ALIGNMENT */


#if (!(defined(BITS_WORDSIZE_H) || defined(_BITS_WORDSIZE_H) || defined(_BITS_WORDSIZE_H_)))
#define BITS_WORDSIZE_H   (1)
#define _BITS_WORDSIZE_H   (1)
#define _BITS_WORDSIZE_H_   (1)
#define _BITSIZE_STDINTCONST_H   (1)


// ARCHITECTURE-SPECIFIC DATATYPE SIZES

#ifdef ARCHPOWERPC64
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   8
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   64
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   6
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   8
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   8
#   define BYTES_PER_HWORD   4
#   define __WORDSIZE   64
#   define BITS_PER_WORD   64
#   define BITS_PER_WORD_LOG2   6
#   define BYTES_PER_WORD   8
#   define BYTES_PER_WORD_LOG2   3
#   define ALIGN_OF_WORD   8
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHPOWERPC32)
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   4
#   define BYTES_PER_HWORD   2
#   define __WORDSIZE   32
#   define BITS_PER_WORD   32
#   define BITS_PER_WORD_LOG2   5
#   define BYTES_PER_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define ALIGN_OF_WORD   4
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHALPHA)
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   8
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   64
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   6
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   8
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   8
#   define BYTES_PER_HWORD   4
#   define __WORDSIZE   64
#   define BITS_PER_WORD   64
#   define BITS_PER_WORD_LOG2   6
#   define BYTES_PER_WORD   8
#   define BYTES_PER_WORD_LOG2   3
#   define ALIGN_OF_WORD   8
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHITANIUM)
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   8
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   64
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   6
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   8
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   8
#   define BYTES_PER_HWORD   4
#   define __WORDSIZE   64
#   define BITS_PER_WORD   64
#   define BITS_PER_WORD_LOG2   6
#   define BYTES_PER_WORD   8
#   define BYTES_PER_WORD_LOG2   3
#   define ALIGN_OF_WORD   8
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHX86_64)
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   8
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   64
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   6
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   8
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   8
#   define BYTES_PER_HWORD   4
#   define __WORDSIZE   64
#   define __WORDSIZE_TIME64_COMPAT32   1
#   define BITS_PER_WORD   64
#   define BITS_PER_WORD_LOG2   6
#   define BYTES_PER_WORD   8
#   define BYTES_PER_WORD_LOG2   3
#   define ALIGN_OF_WORD   8
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHX86_32)
#   define _LONG_LONG_LIMB
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   4
#   define BYTES_PER_HWORD   2
#   define __WORDSIZE   32
#   define BITS_PER_WORD   32
#   define BITS_PER_WORD_LOG2   5
#   define BYTES_PER_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define ALIGN_OF_WORD   4
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHSPARC64)
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   8
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   64
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   6
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   8
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   8
#   define BYTES_PER_HWORD   4
#   define __WORDSIZE   64
#   define BITS_PER_WORD   64
#   define BITS_PER_WORD_LOG2   6
#   define BYTES_PER_WORD   8
#   define BYTES_PER_WORD_LOG2   3
#   define ALIGN_OF_WORD   8
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHSPARC)
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT  4
#   define BYTES_PER_DOUBLE  8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE  64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2  4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2  5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE  8
#   define BYTES_PER_HWORD   2
#   define ALIGN_OF_POINTER  4
#   define __WORDSIZE   32
#   define BITS_PER_WORD   32
#   define BITS_PER_WORD_LOG2   5
#   define BYTES_PER_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define ALIGN_OF_WORD   4
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHMIPS64)
#   define _LONG_LONG_LIMB
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   8
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   64
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   6
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   8
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   8
#   define BYTES_PER_HWORD   4
#   define __WORDSIZE   64
#   define __WORDSIZE_TIME64_COMPAT32   1
#   define BITS_PER_WORD   64
#   define BITS_PER_WORD_LOG2   6
#   define BYTES_PER_WORD   8
#   define BYTES_PER_WORD_LOG2   3
#   define ALIGN_OF_WORD   8
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHMIPS32)
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   4
#   define BYTES_PER_HWORD   2
#   define __WORDSIZE   32
#   define BITS_PER_WORD   32
#   define BITS_PER_WORD_LOG2   5
#   define BYTES_PER_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define ALIGN_OF_WORD   4
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHAARCH64)
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   8
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   64
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   6
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   8
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   8
#   define BYTES_PER_HWORD   2
#   define __WORDSIZE   64
#   define BITS_PER_WORD   64
#   define BITS_PER_WORD_LOG2   6
#   define BYTES_PER_WORD   8
#   define BYTES_PER_WORD_LOG2   3
#   define ALIGN_OF_WORD   8
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHAARCH32)
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   4
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   4
#   define ALIGN_OF_POINTER   4
#   define BYTES_PER_HWORD   2
#   define __WORDSIZE   32
#   define BITS_PER_WORD   32
#   define BITS_PER_WORD_LOG2   5
#   define BYTES_PER_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define ALIGN_OF_WORD   4
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHPARISC)
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   4
#   define BYTES_PER_HWORD   2
#   define __WORDSIZE   32
#   define BITS_PER_WORD   32
#   define BITS_PER_WORD_LOG2   5
#   define BYTES_PER_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define ALIGN_OF_WORD   4
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHS390X)
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   8
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   64
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   6
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   8
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   8
#   define BYTES_PER_HWORD   4
#   define __WORDSIZE   64
#   define BITS_PER_WORD   64
#   define BITS_PER_WORD_LOG2   6
#   define BYTES_PER_WORD   8
#   define BYTES_PER_WORD_LOG2   3
#   define ALIGN_OF_WORD   8
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHS390)
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   4
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   4
#   define ALIGN_OF_POINTER   4
#   define BYTES_PER_HWORD   2
#   define __WORDSIZE   32
#   define BITS_PER_WORD   32
#   define BITS_PER_WORD_LOG2   5
#   define BYTES_PER_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define ALIGN_OF_WORD   4
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#elif defined(ARCHSUPERH)
#   define BYTES_PER_INT   4
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BITS_PER_INT   32
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   4
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   4
#   define ALIGN_OF_POINTER   4
#   define BYTES_PER_HWORD   2
#   define __WORDSIZE   32
#   define BITS_PER_WORD   32
#   define BITS_PER_WORD_LOG2   5
#   define BYTES_PER_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define ALIGN_OF_WORD   4
#   define BITS_PER_DWORD   64
#   define BITS_PER_DWORD_LOG2   6
#   define BYTES_PER_DWORD   8
#   define BYTES_PER_DWORD_LOG2   3
#   define ALIGN_OF_DWORD   8
#else
#   error   "Unknown CPU architecture!"
#endif


// SIZEOF INTEGRAL DATATYPES

#define ALIGN_OF_PTR   ALIGN_OF_POINTER
#define SIZEOF_HWORD   BYTES_PER_HWORD
#define SIZEOF_HWTYPE   BYTES_PER_HWORD
#define SIZEOF_WORD   BYTES_PER_WORD
#define SIZEOF_WTYPE   BYTES_PER_WORD
#define SIZEOF_DWORD   BYTES_PER_DWORD
#define SIZEOF_DTYPE   BYTES_PER_DWORD
#define WORDSIZE   __WORDSIZE
#define wmask   (__WORDSIZE - 1)
#define W_TYPE_SIZE   __WORDSIZE
#if (W_TYPE_SIZE == 8)
#   define Wtype_MAXp1_F   0x1.0P8F
#elif (W_TYPE_SIZE == 16)
#   define Wtype_MAXp1_F   0x1.0P16F
#elif (W_TYPE_SIZE == 32)
#   define Wtype_MAXp1_F   0x1.0P32F
#elif (W_TYPE_SIZE == 64)
#   define Wtype_MAXp1_F   0x1.0P64F
#else
#   error   "Expand the Wtype_MAXp1_F table."
#endif
/** @def UNITS_PER_WORD
Number of storage units in a word; normally the size of a general-purpose register (a power of two from 1 or 8) */
#if (WORDSIZE == 64)
#   define IS_WORDSIZE_16   0
#   define IS_WORDSIZE_32   0
#   define IS_WORDSIZE_64   1
#   define UNITS_PER_WORD   8
#elif (WORDSIZE == 32)
#   define IS_WORDSIZE_16   0
#   define IS_WORDSIZE_32   1
#   define IS_WORDSIZE_64   0
#   define UNITS_PER_WORD   4
#elif (WORDSIZE == 16)
#   define IS_WORDSIZE_16   1
#   define IS_WORDSIZE_32   0
#   define IS_WORDSIZE_64   0
#   define UNITS_PER_WORD   2
#else
#   error   "Invalid WORDSIZE value!"
#endif
#if IS_WORDSIZE_32
#   define ENTRY_ALIGN   4
#else
#   define ENTRY_ALIGN   2
#endif
/** @def MIN_UNITS_PER_WORD
Minimum number of units in a word */
#ifndef MIN_UNITS_PER_WORD
#   define MIN_UNITS_PER_WORD    UNITS_PER_WORD
#endif
#if (defined(ARCHX86) && (!defined(SYSCALL_WORDSIZE)))
/** @def SYSCALL_WORDSIZE
Wordsize used by syscalls. Both x86-64 and x32 use the 64-bit syscall interface. */
#   define SYSCALL_WORDSIZE   64
#endif
// BYTE
/** @def NBBY
Number of bits in a byte; not all platforms use 8-bit bytes */
#ifndef NBBY
#   define NBBY   8
#endif
/** Number of bits in a byte; not all platforms use 8-bit bytes */
#define BITS_PER_UNIT   NBBY
/** Number of bits in a byte; not all platforms use 8-bit bytes */
#define BITS_PER_BYTE   NBBY
/** Number of bytes in a byte (obviously 1); Some code depends on this symbol */
#define BYTES_PER_BYTE   1
#ifndef SIZEOF_BYTE
/** Sizeof a byte */
#   define SIZEOF_BYTE   1
#endif
#ifndef __SIZEOF_BYTE__
/** Sizeof a byte */
#   define __SIZEOF_BYTE__   1
#endif
// CHAR
#ifndef __CHAR_BIT__
/** Number of bits in a `char` */
#   define __CHAR_BIT__   8
#endif
#ifndef CHARBITS
/** Number of bits in a `char` */
#   define CHARBITS   __CHAR_BIT__
#endif
#ifndef CHAR_BIT
/** Number of bits in a `char` */
#   define CHAR_BIT   CHARBITS
#endif
/** Number of bits in a char */
#define BITS_PER_CHAR   CHARBITS
/** Number of bytes in a char */
#define BYTES_PER_CHAR   1
#ifndef SIZEOF_CHAR
/** Number of bytes in a char */
#   define SIZEOF_CHAR   BYTES_PER_CHAR
#endif
#ifndef __SIZEOF_CHAR__
/** Sizeof a char */
#   define __SIZEOF_CHAR__   BYTES_PER_CHAR
#endif
// SHORT
#ifdef __SIZEOF_SHORT__
#   ifndef SIZEOF_SHORT
#      define SIZEOF_SHORT   __SIZEOF_SHORT__
#   endif
#else
#   ifndef SIZEOF_SHORT
#      define SIZEOF_SHORT   2
#   endif
#   ifndef __SIZEOF_SHORT__
#      define __SIZEOF_SHORT__   2
#   endif
#endif
/** Number of bits in a short */
#define BITS_PER_SHORT   (SIZEOF_SHORT * NBBY)
/** Number of bytes in a short */
#define BYTES_PER_SHORT   SIZEOF_SHORT
/** Number of bits in a short */
#define BITS_PER_SHORTINT   BITS_PER_SHORT
/** Number of bits in a short */
#define BITS_PER_SHORT_INT   BITS_PER_SHORTINT
/** Number of bits in a short */
#define SHORTBITS   BITS_PER_SHORT
/** Number of bytes in a short */
#define BYTES_PER_SHORT_INT   BYTES_PER_SHORT
// INT
#ifndef INTBITS
#   define INTBITS   BITS_PER_INT
#endif
#ifdef __SIZEOF_INT__
#   ifndef SIZEOF_INT
#      define SIZEOF_INT   __SIZEOF_INT__
#   endif
#else
#   ifndef SIZEOF_INT
#      define SIZEOF_INT   BYTES_PER_INT
#   endif
#   ifndef __SIZEOF_INT__
#      define __SIZEOF_INT__   BYTES_PER_INT
#   endif
#endif
/** Number of bytes per word (integer) */
#define NBPW   BYTES_PER_INT
// LONG
/** Number of bits in a long */
#define BITS_PER_LONGINT   BITS_PER_LONG
/** Number of bits in a long */
#define BITS_PER_LONG_INT   BITS_PER_LONG
/** Number of bytes in a long */
#define BYTES_PER_LONG_INT   BYTES_PER_LONG
#ifdef __SIZEOF_LONG__
#   ifndef SIZEOF_LONG
#      define SIZEOF_LONG   __SIZEOF_LONG__
#   endif
#else
#   ifndef SIZEOF_LONG
#      define SIZEOF_LONG   BYTES_PER_LONG
#   endif
#   ifndef __SIZEOF_LONG__
#      define __SIZEOF_LONG__   BYTES_PER_LONG
#   endif
#endif
#if (SIZEOF_LONG == 4)
#   define LONG_EQ_32BITS   1
#   define LONG_EQ_64BITS   0
#else
#   define LONG_EQ_32BITS   0
#   define LONG_EQ_64BITS   1
#endif
// LONG LONG
#ifdef __SIZEOF_LONG_LONG__
#   ifndef SIZEOF_LONG_LONG
#      define SIZEOF_LONG_LONG   __SIZEOF_LONG_LONG__
#   endif
#else
#   ifndef SIZEOF_LONG_LONG
#      define SIZEOF_LONG_LONG   BYTES_PER_LONG_LONG
#   endif
#   ifndef __SIZEOF_LONG_LONG__
#      define __SIZEOF_LONG_LONG__   BYTES_PER_LONG_LONG
#   endif
#endif
/** Number of bits in a long long */
#define BITS_PER_LONG_LONG_INT   (SIZEOF_LONG_LONG * NBBY)
/** Number of bits in a long long */
#define BITS_PER_LONG_LONG   BITS_PER_LONG_LONG_INT
/** Number of bytes in a long long */
#define BYTES_PER_LONG_LONG_INT   SIZEOF_LONG_LONG
/** Number of bytes in a long long */
#define BYTES_PER_LONG_LONG   SIZEOF_LONG_LONG
#if ((SIZEOF_LONG == SIZEOF_INT) && (SIZEOF_LONG != SIZEOF_LONG_LONG))
/** Equals `1` if `long` is the same size as `int` */
#   define LONG_EQ_INT   1
/** Equals `1` if `long` is the same size as `long long` */
#   define LONG_EQ_LLONG   0
#   define LONG_GT_INT   0
#elif ((SIZEOF_LONG >= SIZEOF_INT) && (SIZEOF_LONG == SIZEOF_LONG_LONG))
/** Equals `1` if `long` is the same size as `int` */
#   define LONG_EQ_INT   0
/** Equals `1` if `long` is the same size as `long long` */
#   define LONG_EQ_LLONG   1
#   define LONG_GT_INT   1
#else
#   error   "The target platform is not supported (mismatched sizes of `int`, `long`, and `long long`)!"
#endif
#if (SIZEOF_LONG_LONG == 4)
#   define LLONG_EQ_32BITS   1
#   define LLONG_EQ_64BITS   0
#else
#   define LLONG_EQ_32BITS   0
#   define LLONG_EQ_64BITS   1
#endif
// INT64_T
#define BITS_PER_INT64   64
#define BITS_PER_INT64_LOG2   6
#define BYTES_PER_INT64   8
// INT128_T
#ifndef BITS_PER_INT128
#   define BITS_PER_INT128   128
#endif
#ifndef BYTES_PER_INT128
#   define BYTES_PER_INT128   16
#endif
#ifndef __SIZEOF_INT128__
#   define __SIZEOF_INT128__   16
#endif
#ifndef SIZEOF_INT128
#   define SIZEOF_INT128   __SIZEOF_INT128__
#endif
#ifndef BITS_PER_UINT128
#   define BITS_PER_UINT128   128
#endif
#ifndef BYTES_PER_UINT128
#   define BYTES_PER_UINT128   16
#endif
#ifndef __SIZEOF_UINT128__
#   define __SIZEOF_UINT128__   16
#endif
#ifndef SIZEOF_UINT128
#   define SIZEOF_UINT128   __SIZEOF_UINT128__
#endif
// INT256_T
#ifndef BITS_PER_INT256
#   define BITS_PER_INT256   256
#endif
#ifndef BYTES_PER_INT256
#   define BYTES_PER_INT256   32
#endif
#ifndef __SIZEOF_INT256__
#   define __SIZEOF_INT256__   32
#endif
#ifndef SIZEOF_INT256
#   define SIZEOF_INT256   __SIZEOF_INT256__
#endif
#ifndef BITS_PER_UINT256
#   define BITS_PER_UINT256   256
#endif
#ifndef BYTES_PER_UINT256
#   define BYTES_PER_UINT256   32
#endif
#ifndef __SIZEOF_UINT256__
#   define __SIZEOF_UINT256__   32
#endif
#ifndef SIZEOF_UINT256
#   define SIZEOF_UINT256   __SIZEOF_UINT256__
#endif
// INT512_T
#ifndef BITS_PER_INT512
#   define BITS_PER_INT512   512
#endif
#ifndef BYTES_PER_INT512
#   define BYTES_PER_INT512   64
#endif
#ifndef __SIZEOF_INT512__
#   define __SIZEOF_INT512__   64
#endif
#ifndef SIZEOF_INT512
#   define SIZEOF_INT512   __SIZEOF_INT512__
#endif
#ifndef BITS_PER_UINT512
#   define BITS_PER_UINT512   512
#endif
#ifndef BYTES_PER_UINT512
#   define BYTES_PER_UINT512   64
#endif
#ifndef __SIZEOF_UINT512__
#   define __SIZEOF_UINT512__   64
#endif
#ifndef SIZEOF_UINT512
#   define SIZEOF_UINT512   __SIZEOF_UINT512__
#endif
// SIZE_T, PTRDIFF_T, & POINTERS
#ifndef BYTES_PER_POINTER
#   define BYTES_PER_POINTER   SIZEOF_POINTER
#endif
#ifndef BYTES_PER_PTR
#   define BYTES_PER_PTR   SIZEOF_POINTER
#endif
#ifndef BITS_PER_POINTER
#   define BITS_PER_POINTER   TYPESIZE_PTR
#endif
#ifndef SIZEOF_VOID_PTR
#   define SIZEOF_VOID_PTR   SIZEOF_POINTER
#endif
#ifndef BITS_PER_VOID_P
#   define BITS_PER_VOID_P   BITS_PER_POINTER
#endif
#ifndef SIZEOF_VOID
#   define SIZEOF_VOID   (sizeof(void))
#endif
#ifndef BITS_PER_VOID
#   define BITS_PER_VOID   (SIZEOF_VOID * 8)
#endif
#ifndef SIZEOF_NULL
#   define SIZEOF_NULL   SIZEOF_POINTER
#endif
#ifndef BITS_PER_NULL
#   define BITS_PER_NULL   BITS_PER_POINTER
#endif
#ifndef __INTPTR_WIDTH__
#   define __INTPTR_WIDTH__   BITS_PER_POINTER
#endif
#ifndef BITS_PER_INTPTR
#   define BITS_PER_INTPTR   BITS_PER_POINTER
#endif
#ifndef __UINTPTR_WIDTH__
#   define __UINTPTR_WIDTH__   BITS_PER_POINTER
#endif
#ifndef BITS_PER_UINTPTR
#   define BITS_PER_UINTPTR   BITS_PER_POINTER
#endif
#define SIZEOF_SIZE_T   SIZEOF_POINTER
#define BITS_PER_SIZE_T   BITS_PER_POINTER
#define SIZEOF_PTRDIFF_T   SIZEOF_POINTER
#ifndef __SIZEOF_SIZE_T__
#   define __SIZEOF_SIZE_T__   SIZEOF_POINTER
#endif
#ifndef __SIZEOF_PTRDIFF_T__
#   define __SIZEOF_PTRDIFF_T__   SIZEOF_POINTER
#endif
/** Number of bits in ptrdiff_t */
#define BITS_PER_PTRDIFF_T   BITS_PER_SIZE_T
#ifndef __PTRDIFF_WIDTH__
/** Number of bits in ptrdiff_t */
#   define __PTRDIFF_WIDTH__   BITS_PER_POINTER
#endif
#if ((SIZEOF_SIZE_T == SIZEOF_INT) && (SIZEOF_SIZE_T != SIZEOF_LONG))
#   define SIZE_T_EQ_INT   1
#   define SIZE_T_EQ_LONG   0
#elif ((SIZEOF_SIZE_T != SIZEOF_INT) && (SIZEOF_SIZE_T == SIZEOF_LONG))
#   define SIZE_T_EQ_INT   0
#   define SIZE_T_EQ_LONG   1
#elif ((SIZEOF_SIZE_T == SIZEOF_INT) && (SIZEOF_SIZE_T == SIZEOF_LONG))
#   define SIZE_T_EQ_INT   1
#   define SIZE_T_EQ_LONG   1
#endif
#if (SIZEOF_SIZE_T == SIZEOF_LONG_LONG)
#   define SIZE_T_EQ_LLONG   1
#else
#   define SIZE_T_EQ_LLONG   0
#endif
#if (SIZEOF_SIZE_T == 8)
#   define SIZE_T_EQ_32BITS   0
#   define SIZE_T_EQ_64BITS   1
#else
#   define SIZE_T_EQ_32BITS   1
#   define SIZE_T_EQ_64BITS   0
#endif
#define PTR_EQ_INT   SIZE_T_EQ_INT
#define PTR_EQ_LONG   SIZE_T_EQ_LONG
#define PTR_EQ_LLONG   SIZE_T_EQ_LLONG
#define PTR_EQ_32BITS   SIZE_T_EQ_32BITS
#define PTR_EQ_64BITS   SIZE_T_EQ_64BITS


// SIZEOF FLOAT-POINTS

#ifndef BITS_PER_FLOAT8
#   define BITS_PER_FLOAT8   8
#endif
#ifndef BYTES_PER_FLOAT8
#   define BYTES_PER_FLOAT8   1
#endif
#ifdef __SIZEOF_FLOAT8__
#   ifndef SIZEOF_FLOAT8
#      define SIZEOF_FLOAT8   __SIZEOF_FLOAT8__
#   endif
#else
#   ifndef SIZEOF_FLOAT8
#      define SIZEOF_FLOAT8   1
#   endif
#   ifndef __SIZEOF_FLOAT8__
#      define __SIZEOF_FLOAT8__   1
#   endif
#endif
#ifndef BITS_PER_FLOAT16
#   define BITS_PER_FLOAT16   16
#endif
#ifndef BYTES_PER_FLOAT16
#   define BYTES_PER_FLOAT16   2
#endif
#ifdef __SIZEOF_FLOAT16__
#   ifndef SIZEOF_FLOAT16
#      define SIZEOF_FLOAT16   __SIZEOF_FLOAT16__
#   endif
#else
#   ifndef SIZEOF_FLOAT16
#      define SIZEOF_FLOAT16   2
#   endif
#   ifndef __SIZEOF_FLOAT16__
#      define __SIZEOF_FLOAT16__   2
#   endif
#endif
#ifndef __SIZEOF_FP16__
#   define __SIZEOF_FP16__   2
#endif
#ifndef SIZEOF_FP16
#   define SIZEOF_FP16   2
#endif
#ifndef BITS_PER_FLOAT24
#   define BITS_PER_FLOAT24   24
#endif
#ifndef BYTES_PER_FLOAT24
#   define BYTES_PER_FLOAT24   3
#endif
#ifdef __SIZEOF_FLOAT24__
#   ifndef SIZEOF_FLOAT24
#      define SIZEOF_FLOAT24   __SIZEOF_FLOAT24__
#   endif
#else
#   ifndef SIZEOF_FLOAT24
#      define SIZEOF_FLOAT24   3
#   endif
#   ifndef __SIZEOF_FLOAT24__
#      define __SIZEOF_FLOAT24__   3
#   endif
#endif
#ifdef __SIZEOF_FLOAT__
#   ifndef SIZEOF_FLOAT
#      define SIZEOF_FLOAT   __SIZEOF_FLOAT__
#   endif
#else
#   ifndef SIZEOF_FLOAT
#      define SIZEOF_FLOAT   BYTES_PER_FLOAT
#   endif
#   ifndef __SIZEOF_FLOAT__
#      define __SIZEOF_FLOAT__   BYTES_PER_FLOAT
#   endif
#endif
#ifndef SIZEOF_SFTYPE
#   define SIZEOF_SFTYPE   SIZEOF_FLOAT
#endif
#ifndef __SIZEOF_FLOAT32__
#   define __SIZEOF_FLOAT32__   4
#endif
#ifndef SIZEOF_FLOAT32
#   define SIZEOF_FLOAT32   __SIZEOF_FLOAT32__
#endif
#ifdef __SIZEOF_DOUBLE__
#   ifndef SIZEOF_DOUBLE
/** Size of a double */
#      define SIZEOF_DOUBLE   __SIZEOF_DOUBLE__
#   endif
#else
#   ifndef SIZEOF_DOUBLE
/** Size of a double */
#      define SIZEOF_DOUBLE   BYTES_PER_DOUBLE
#   endif
#   ifndef __SIZEOF_DOUBLE__
/** Size of a double */
#      define __SIZEOF_DOUBLE__   BYTES_PER_DOUBLE
#   endif
#endif
#ifndef SIZEOF_DFTYPE
#   define SIZEOF_DFTYPE   SIZEOF_DOUBLE
#endif
#ifndef __SIZEOF_FLOAT64__
#   define __SIZEOF_FLOAT64__   8
#endif
#ifndef SIZEOF_FLOAT64
#   define SIZEOF_FLOAT64   __SIZEOF_FLOAT64__
#endif
#if ((!defined(SIZEOF_XFTYPE)) && defined(DATAMODEL_ILP32))
#   define SIZEOF_XFTYPE   12
#elif ((!defined(SIZEOF_XFTYPE)) && defined(DATAMODEL_LP64))
#   define SIZEOF_XFTYPE   16
#endif
#ifndef __SIZEOF_XFTYPE__
#   define __SIZEOF_XFTYPE__   SIZEOF_XFTYPE
#endif
#ifdef __SIZEOF_FLOAT80__
#   define SIZEOF_FLOAT80   __SIZEOF_FLOAT80__
#elif (defined(DATAMODEL_ILP32))
#   define __SIZEOF_FLOAT80__   12
#   define SIZEOF_FLOAT80   12
#else
#   define __SIZEOF_FLOAT80__   10
#   define SIZEOF_FLOAT80   __SIZEOF_FLOAT80__
#endif
#ifdef __SIZEOF_FLOAT96__
#   define SIZEOF_FLOAT96   __SIZEOF_FLOAT96__
#else
#   define __SIZEOF_FLOAT96__   12
#   define SIZEOF_FLOAT96   __SIZEOF_FLOAT96__
#endif
#ifndef __SIZEOF_FLOAT128__
#   define __SIZEOF_FLOAT128__   16
#endif
#ifndef SIZEOF_FLOAT128
#   define SIZEOF_FLOAT128   16
#endif


// SIZEOF LONG DOUBLE

#undef LDBL_EQ_DBL
#undef _LDBL_EQ_DBL
#undef LDBL_EQ_DFtype
#undef LDBL_EQ_XFtype
#undef LDBL_EQ_TFtype
#undef LDBL_EQ_FLOAT128
#if (SUPPORTS_LONG_DOUBLE && defined(__SIZEOF_LONG_DOUBLE__))
#   ifndef SIZEOF_LONG_DOUBLE
#      define SIZEOF_LONG_DOUBLE   __SIZEOF_LONG_DOUBLE__
#   endif
#   ifndef BYTES_PER_LONG_DOUBLE
#      define BYTES_PER_LONG_DOUBLE   __SIZEOF_LONG_DOUBLE__
#   endif
#elif SUPPORTS_LONG_DOUBLE
#   error   "`__SIZEOF_LONG_DOUBLE__` is not defined!"
#endif
#if SUPPORTS_LONG_DOUBLE
#   if (defined(__SIZEOF_LONG_DOUBLE__) && (__SIZEOF_LONG_DOUBLE__ == 10))
#      define IS_LDBL_64   0
#      define IS_LDBL_80   1
#      define IS_LDBL_96   0
#      define IS_LDBL_128   0
#      define LDBL_EQ_XFtype   1
#      define BITS_PER_LONG_DOUBLE   80
#   elif (defined(__SIZEOF_LONG_DOUBLE__) && (__SIZEOF_LONG_DOUBLE__ == 12))
#      define IS_LDBL_64   0
#      define IS_LDBL_80   0
#      define IS_LDBL_96   1
#      define IS_LDBL_128   0
#      define LDBL_EQ_XFtype   1
#      define BITS_PER_LONG_DOUBLE   96
#   elif (defined(__SIZEOF_LONG_DOUBLE__) && (__SIZEOF_LONG_DOUBLE__ == 16) && ((__LDBL_MANT_DIG__ == 64) && (__LDBL_MAX_EXP__ == 16384)))  // 96-bit long double using 128-bits
#      define IS_LDBL_64   0
#      define IS_LDBL_80   0
#      define IS_LDBL_96   1
#      define IS_LDBL_128   0
#      define FAKE_128_LDBL   1
#      define LDBL_EQ_XFtype   0
#      define BITS_PER_LONG_DOUBLE   128
#   elif (defined(__SIZEOF_LONG_DOUBLE__) && (__SIZEOF_LONG_DOUBLE__ == 16))
#      define IS_LDBL_64   0
#      define IS_LDBL_80   0
#      define IS_LDBL_96   0
#      define IS_LDBL_128   1
#      define LDBL_EQ_XFtype   0
#      define BITS_PER_LONG_DOUBLE   128
#   elif (defined(__SIZEOF_LONG_DOUBLE__) && (__SIZEOF_LONG_DOUBLE__ == 8))
#      define IS_LDBL_64   1
#      define IS_LDBL_80   0
#      define IS_LDBL_96   0
#      define IS_LDBL_128   0
#      define LDBL_EQ_XFtype   0
#      define BITS_PER_LONG_DOUBLE   64
#   else
#      error   "Invalid `long double` size!"
#   endif
#   define _LDBL_EQ_DBL   ((SIZEOF_DOUBLE == __SIZEOF_LONG_DOUBLE__))
#   define LDBL_EQ_DBL   ((SIZEOF_DOUBLE == __SIZEOF_LONG_DOUBLE__))
#   define LDBL_EQ_DFtype   ((SIZEOF_DOUBLE == __SIZEOF_LONG_DOUBLE__))
#   define LDBL_EQ_TFtype   ((__SIZEOF_LONG_DOUBLE__ == 16))
#   define LDBL_EQ_FLOAT128   ((__SIZEOF_LONG_DOUBLE__ == 16))
#else
#   define IS_LDBL_64   0
#   define IS_LDBL_80   0
#   define IS_LDBL_96   0
#   define IS_LDBL_128   0
#   define _LDBL_EQ_DBL   0
#   define LDBL_EQ_DBL   0
#   define LDBL_EQ_DFtype   0
#   define LDBL_EQ_XFtype   0
#   define LDBL_EQ_TFtype   0
#   define LDBL_EQ_FLOAT128   0
#   define BITS_PER_LONG_DOUBLE   80
#   define BYTES_PER_LONG_DOUBLE   10
#   define __SIZEOF_LONG_DOUBLE__   10
#   define SIZEOF_LONG_DOUBLE   10
#endif
#ifndef FAKE_128_LDBL
#   define FAKE_128_LDBL   0
#endif
#define IS_LDBL_X87   ((IS_LDBL_80 || IS_LDBL_96) && (!FAKE_128_LDBL))


// SIZEOF DECIMAL FLOATS

#ifndef __SIZEOF_DECIMAL32__
#   define __SIZEOF_DECIMAL32__   4
#endif
#ifndef SIZEOF_DECIMAL32
#   define SIZEOF_DECIMAL32   4
#endif
#ifndef BYTES_PER_DECIMAL32
#   define BYTES_PER_DECIMAL32   4
#endif
#ifndef BITS_PER_DECIMAL32
#   define BITS_PER_DECIMAL32   32
#endif
#ifndef __SIZEOF_DECIMAL64__
#   define __SIZEOF_DECIMAL64__   8
#endif
#ifndef SIZEOF_DECIMAL64
#   define SIZEOF_DECIMAL64   8
#endif
#ifndef BYTES_PER_DECIMAL64
#   define BYTES_PER_DECIMAL64   8
#endif
#ifndef BITS_PER_DECIMAL64
#   define BITS_PER_DECIMAL64   64
#endif
#ifndef __SIZEOF_DECIMAL128__
#   define __SIZEOF_DECIMAL128__   16
#endif
#ifndef SIZEOF_DECIMAL128
#   define SIZEOF_DECIMAL128   16
#endif
#ifndef BYTES_PER_DECIMAL128
#   define BYTES_PER_DECIMAL128   16
#endif
#ifndef BITS_PER_DECIMAL128
#   define BITS_PER_DECIMAL128   128
#endif
#ifndef __SIZEOF_DECIMAL256__
#   define __SIZEOF_DECIMAL256__   32
#endif
#ifndef SIZEOF_DECIMAL256
#   define SIZEOF_DECIMAL256   32
#endif
#ifndef BYTES_PER_DECIMAL256
#   define BYTES_PER_DECIMAL256   32
#endif
#ifndef BITS_PER_DECIMAL256
#   define BITS_PER_DECIMAL256   256
#endif
#ifndef __SIZEOF_DECIMAL512__
#   define __SIZEOF_DECIMAL512__   64
#endif
#ifndef SIZEOF_DECIMAL512
#   define SIZEOF_DECIMAL512   64
#endif
#ifndef BYTES_PER_DECIMAL512
#   define BYTES_PER_DECIMAL512   64
#endif
#ifndef BITS_PER_DECIMAL512
#   define BITS_PER_DECIMAL512   512
#endif


// SIZEOF FRACTIONAL DATATYPES

#ifdef __SIZEOF_SHORT_FRACT__
#   ifndef SIZEOF_SHORT_FRACT
#      define SIZEOF_SHORT_FRACT   __SIZEOF_SHORT_FRACT__
#   endif
#else
#   ifndef SIZEOF_SHORT_FRACT
#      define SIZEOF_SHORT_FRACT   1
#   endif
#   ifndef __SIZEOF_SHORT_FRACT__
#      define __SIZEOF_SHORT_FRACT__   1
#   endif
#endif
/** Number of bytes in short Fract */
#define BYTES_PER_SHORT_FRACT   SIZEOF_SHORT_FRACT
/** Number of bits in short Fract */
#define BITS_PER_SHORT_FRACT   (SIZEOF_SHORT_FRACT * 8)
#define __SIZEOF_XINT_HR_T__   SIZEOF_SHORT_FRACT
#define SIZEOF_XINT_HR_T   SIZEOF_SHORT_FRACT
#define BYTES_PER_XINT_HR_T   SIZEOF_SHORT_FRACT
#define BITS_PER_XINT_HR_T   BITS_PER_SHORT_FRACT
#define __SIZEOF_XINT_UHR_T__   SIZEOF_SHORT_FRACT
#define SIZEOF_XINT_UHR_T   SIZEOF_SHORT_FRACT
#define BYTES_PER_XINT_UHR_T   SIZEOF_SHORT_FRACT
#define BITS_PER_XINT_UHR_T   BITS_PER_SHORT_FRACT
#define __SIZEOF_FX_HR_T__   SIZEOF_SHORT_FRACT
#define SIZEOF_FX_HR_T   SIZEOF_SHORT_FRACT
#define BYTES_PER_FX_HR_T   SIZEOF_SHORT_FRACT
#define BITS_PER_FX_HR_T   BITS_PER_SHORT_FRACT
#define __SIZEOF_FX_UHR_T__   SIZEOF_SHORT_FRACT
#define SIZEOF_FX_UHR_T   SIZEOF_SHORT_FRACT
#define BYTES_PER_FX_UHR_T   SIZEOF_SHORT_FRACT
#define BITS_PER_FX_UHR_T   BITS_PER_SHORT_FRACT
#ifdef __SIZEOF_FRACT__
#   ifndef SIZEOF_FRACT
#      define SIZEOF_FRACT   __SIZEOF_FRACT__
#   endif
#else
#   ifndef SIZEOF_FRACT
#      define SIZEOF_FRACT   2
#   endif
#   ifndef __SIZEOF_FRACT__
#      define __SIZEOF_FRACT__   2
#   endif
#endif
/** Number of bytes in Fract */
#define BYTES_PER_FRACT   SIZEOF_FRACT
/** Number of bits in Fract */
#define BITS_PER_FRACT   (SIZEOF_FRACT * 8)
#define __SIZEOF_XINT_R_T__   SIZEOF_FRACT
#define SIZEOF_XINT_R_T   SIZEOF_FRACT
#define BYTES_PER_XINT_R_T   SIZEOF_FRACT
#define BITS_PER_XINT_R_T   BITS_PER_FRACT
#define __SIZEOF_XINT_UR_T__   SIZEOF_FRACT
#define SIZEOF_XINT_UR_T   SIZEOF_FRACT
#define BYTES_PER_XINT_UR_T   SIZEOF_FRACT
#define BITS_PER_XINT_UR_T   BITS_PER_FRACT
#define __SIZEOF_FX_T__   SIZEOF_FRACT
#define SIZEOF_FX_T   SIZEOF_FRACT
#define BYTES_PER_FX_T   SIZEOF_FRACT
#define BITS_PER_FX_T   BITS_PER_FRACT
#define __SIZEOF_FX_R_T__   SIZEOF_FRACT
#define SIZEOF_FX_R_T   SIZEOF_FRACT
#define BYTES_PER_FX_R_T   SIZEOF_FRACT
#define BITS_PER_FX_R_T   BITS_PER_FRACT
#define __SIZEOF_FX_UR_T__   SIZEOF_FRACT
#define SIZEOF_FX_UR_T   SIZEOF_FRACT
#define BYTES_PER_FX_UR_T   SIZEOF_FRACT
#define BITS_PER_FX_UR_T   BITS_PER_FRACT
#ifdef __SIZEOF_LONG_FRACT__
#   ifndef SIZEOF_LONG_FRACT
#      define SIZEOF_LONG_FRACT   __SIZEOF_LONG_FRACT__
#   endif
#else
#   ifndef SIZEOF_LONG_FRACT
#      define SIZEOF_LONG_FRACT   4
#   endif
#   ifndef __SIZEOF_LONG_FRACT__
#      define __SIZEOF_LONG_FRACT__   4
#   endif
#endif
/** Number of bytes in long Fract */
#define BYTES_PER_LONG_FRACT   SIZEOF_LONG_FRACT
/** Number of bits in long Fract */
#define BITS_PER_LONG_FRACT   (SIZEOF_LONG_FRACT * 8)
#define __SIZEOF_XINT_LR_T__   SIZEOF_LONG_FRACT
#define SIZEOF_XINT_LR_T   SIZEOF_LONG_FRACT
#define BYTES_PER_XINT_LR_T   SIZEOF_LONG_FRACT
#define BITS_PER_XINT_LR_T   BITS_PER_LONG_FRACT
#define __SIZEOF_XINT_ULR_T__   SIZEOF_LONG_FRACT
#define SIZEOF_XINT_ULR_T   SIZEOF_LONG_FRACT
#define BYTES_PER_XINT_ULR_T   SIZEOF_LONG_FRACT
#define BITS_PER_XINT_ULR_T   BITS_PER_LONG_FRACT
#define __SIZEOF_FX_LR_T__   SIZEOF_LONG_FRACT
#define SIZEOF_FX_LR_T   SIZEOF_LONG_FRACT
#define BYTES_PER_FX_LR_T   SIZEOF_LONG_FRACT
#define BITS_PER_FX_LR_T   BITS_PER_LONG_FRACT
#define __SIZEOF_FX_ULR_T__   SIZEOF_LONG_FRACT
#define SIZEOF_FX_ULR_T   SIZEOF_LONG_FRACT
#define BYTES_PER_FX_ULR_T   SIZEOF_LONG_FRACT
#define BITS_PER_FX_ULR_T   BITS_PER_LONG_FRACT
#ifdef __SIZEOF_LONG_LONG_FRACT__
#   ifndef SIZEOF_LONG_LONG_FRACT
#      define SIZEOF_LONG_LONG_FRACT   __SIZEOF_LONG_LONG_FRACT__
#   endif
#else
#   ifndef SIZEOF_LONG_LONG_FRACT
#      define SIZEOF_LONG_LONG_FRACT   8
#   endif
#   ifndef __SIZEOF_LONG_LONG_FRACT__
#      define __SIZEOF_LONG_LONG_FRACT__   8
#   endif
#endif
/** Number of bytes in long Fract */
#define BYTES_PER_LONG_LONG_FRACT   SIZEOF_LONG_LONG_FRACT
/** Number of bits in long Fract */
#define BITS_PER_LONG_LONG_FRACT   (SIZEOF_LONG_LONG_FRACT * 8)
#define __SIZEOF_XINT_LLR_T__   SIZEOF_LONG_LONG_FRACT
#define SIZEOF_XINT_LLR_T   SIZEOF_LONG_LONG_FRACT
#define BYTES_PER_XINT_LLR_T   SIZEOF_LONG_LONG_FRACT
#define BITS_PER_XINT_LLR_T   BITS_PER_LONG_LONG_FRACT
#define __SIZEOF_XINT_ULLR_T__   SIZEOF_LONG_LONG_FRACT
#define SIZEOF_XINT_ULLR_T   SIZEOF_LONG_LONG_FRACT
#define BYTES_PER_XINT_ULLR_T   SIZEOF_LONG_LONG_FRACT
#define BITS_PER_XINT_ULLR_T   BITS_PER_LONG_LONG_FRACT
#define __SIZEOF_FX_LLR_T__   SIZEOF_LONG_LONG_FRACT
#define SIZEOF_FX_LLR_T   SIZEOF_LONG_LONG_FRACT
#define BYTES_PER_FX_LLR_T   SIZEOF_LONG_LONG_FRACT
#define BITS_PER_FX_LLR_T   BITS_PER_LONG_LONG_FRACT
#define __SIZEOF_FX_ULLR_T__   SIZEOF_LONG_LONG_FRACT
#define SIZEOF_FX_ULLR_T   SIZEOF_LONG_LONG_FRACT
#define BYTES_PER_FX_ULLR_T   SIZEOF_LONG_LONG_FRACT
#define BITS_PER_FX_ULLR_T   BITS_PER_LONG_LONG_FRACT


// SIZEOF FRACTIONAL BITS

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
/** @def FRACT_FBIT
The number of bits that represent the fractional portion of Fract */
#ifdef __FRACT_FBIT__
#   define FRACT_FBIT   __FRACT_FBIT__
#else
#   define __FRACT_FBIT__   15
#   define FRACT_FBIT   __FRACT_FBIT__
#endif
/** @def FRACT_IBIT
The number of bits that represent the integer portion of Fract */
#ifdef __FRACT_IBIT__
#   define FRACT_IBIT   __FRACT_IBIT__
#else
#   define __FRACT_IBIT__   0
#   define FRACT_IBIT   __FRACT_IBIT__
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
#ifdef __LFRACT_FBIT__
#   define LFRACT_FBIT   __LFRACT_FBIT__
#else
#   define __LFRACT_FBIT__   31
#   define LFRACT_FBIT   __LFRACT_FBIT__
#endif
#ifdef __LFRACT_IBIT__
#   define LFRACT_IBIT   __LFRACT_IBIT__
#else
#   define __LFRACT_IBIT__   0
#   define LFRACT_IBIT   __LFRACT_IBIT__
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


// SIZEOF ACCUMULATOR DATATYPES

#ifdef __SIZEOF_SHORT_ACCUM__
#   ifndef SIZEOF_SHORT_ACCUM
#      define SIZEOF_SHORT_ACCUM   __SIZEOF_SHORT_ACCUM__
#   endif
#else
#   ifndef SIZEOF_SHORT_ACCUM
#      define SIZEOF_SHORT_ACCUM   2
#   endif
#   ifndef __SIZEOF_SHORT_ACCUM__
#      define __SIZEOF_SHORT_ACCUM__   2
#   endif
#endif
/** Number of bytes in short Accum */
#define BYTES_PER_SHORT_ACCUM   SIZEOF_SHORT_ACCUM
/** Number of bits in short Accum */
#define BITS_PER_SHORT_ACCUM   (SIZEOF_SHORT_ACCUM * 8)
#define __SIZEOF_XINT_HK_T__   SIZEOF_SHORT_ACCUM
#define SIZEOF_XINT_HK_T   SIZEOF_SHORT_ACCUM
#define BYTES_PER_XINT_HK_T   SIZEOF_SHORT_ACCUM
#define BITS_PER_XINT_HK_T   BITS_PER_SHORT_ACCUM
#define __SIZEOF_XINT_UHK_T__   SIZEOF_SHORT_ACCUM
#define SIZEOF_XINT_UHK_T   SIZEOF_SHORT_ACCUM
#define BYTES_PER_XINT_UHK_T   SIZEOF_SHORT_ACCUM
#define BITS_PER_XINT_UHK_T   BITS_PER_SHORT_ACCUM
#define __SIZEOF_FX_HK_T__   SIZEOF_SHORT_ACCUM
#define SIZEOF_FX_HK_T   SIZEOF_SHORT_ACCUM
#define BYTES_PER_FX_HK_T   SIZEOF_SHORT_ACCUM
#define BITS_PER_FX_HK_T   BITS_PER_SHORT_ACCUM
#define __SIZEOF_FX_UHK_T__   SIZEOF_SHORT_ACCUM
#define SIZEOF_FX_UHK_T   SIZEOF_SHORT_ACCUM
#define BYTES_PER_FX_UHK_T   SIZEOF_SHORT_ACCUM
#define BITS_PER_FX_UHK_T   BITS_PER_SHORT_ACCUM
#ifdef __SIZEOF_ACCUM__
#   ifndef SIZEOF_ACCUM
#      define SIZEOF_ACCUM   __SIZEOF_ACCUM__
#   endif
#else
#   ifndef SIZEOF_ACCUM
#      define SIZEOF_ACCUM   4
#   endif
#   ifndef __SIZEOF_ACCUM__
#      define __SIZEOF_ACCUM__   4
#   endif
#endif
/** Number of bytes in Accum */
#define BYTES_PER_ACCUM   SIZEOF_ACCUM
/** Number of bits in Accum */
#define BITS_PER_ACCUM   (SIZEOF_ACCUM * 8)
#define __SIZEOF_XINT_K_T__   SIZEOF_ACCUM
#define SIZEOF_XINT_K_T   SIZEOF_ACCUM
#define BYTES_PER_XINT_K_T   SIZEOF_ACCUM
#define BITS_PER_XINT_K_T   BITS_PER_ACCUM
#define __SIZEOF_XINT_UK_T__   SIZEOF_ACCUM
#define SIZEOF_XINT_UK_T   SIZEOF_ACCUM
#define BYTES_PER_XINT_UK_T   SIZEOF_ACCUM
#define BITS_PER_XINT_UK_T   BITS_PER_ACCUM
#define __SIZEOF_FX_K_T__   SIZEOF_ACCUM
#define SIZEOF_FX_K_T   SIZEOF_ACCUM
#define BYTES_PER_FX_K_T   SIZEOF_ACCUM
#define BITS_PER_FX_K_T   BITS_PER_ACCUM
#define __SIZEOF_FX_UK_T__   SIZEOF_ACCUM
#define SIZEOF_FX_UK_T   SIZEOF_ACCUM
#define BYTES_PER_FX_UK_T   SIZEOF_ACCUM
#define BITS_PER_FX_UK_T   BITS_PER_ACCUM
#ifdef __SIZEOF_LONG_ACCUM__
#   ifndef SIZEOF_LONG_ACCUM
#      define SIZEOF_LONG_ACCUM   __SIZEOF_LONG_ACCUM__
#   endif
#else
#   ifndef SIZEOF_LONG_ACCUM
#      define SIZEOF_LONG_ACCUM   8
#   endif
#   ifndef __SIZEOF_LONG_ACCUM__
#      define __SIZEOF_LONG_ACCUM__   8
#   endif
#endif
/** Number of bytes in long Accum */
#define BYTES_PER_LONG_ACCUM   SIZEOF_LONG_ACCUM
/** Number of bits in long Accum */
#define BITS_PER_LONG_ACCUM   (SIZEOF_LONG_ACCUM * 8)
#define __SIZEOF_XINT_LK_T__   SIZEOF_LONG_ACCUM
#define SIZEOF_XINT_LK_T   SIZEOF_LONG_ACCUM
#define BYTES_PER_XINT_LK_T   SIZEOF_LONG_ACCUM
#define BITS_PER_XINT_LK_T   BITS_PER_LONG_ACCUM
#define __SIZEOF_XINT_ULK_T__   SIZEOF_LONG_ACCUM
#define SIZEOF_XINT_ULK_T   SIZEOF_LONG_ACCUM
#define BYTES_PER_XINT_ULK_T   SIZEOF_LONG_ACCUM
#define BITS_PER_XINT_ULK_T   BITS_PER_LONG_ACCUM
#define __SIZEOF_FX_LK_T__   SIZEOF_LONG_ACCUM
#define SIZEOF_FX_LK_T   SIZEOF_LONG_ACCUM
#define BYTES_PER_FX_LK_T   SIZEOF_LONG_ACCUM
#define BITS_PER_FX_LK_T   BITS_PER_LONG_ACCUM
#define __SIZEOF_FX_ULK_T__   SIZEOF_LONG_ACCUM
#define SIZEOF_FX_ULK_T   SIZEOF_LONG_ACCUM
#define BYTES_PER_FX_ULK_T   SIZEOF_LONG_ACCUM
#define BITS_PER_FX_ULK_T   BITS_PER_LONG_ACCUM
#ifdef __SIZEOF_LONG_LONG_ACCUM__
#   ifndef SIZEOF_LONG_LONG_ACCUM
#      define SIZEOF_LONG_LONG_ACCUM   __SIZEOF_LONG_LONG_ACCUM__
#   endif
#else
#   ifndef SIZEOF_LONG_LONG_ACCUM
#      define SIZEOF_LONG_LONG_ACCUM   16
#   endif
#   ifndef __SIZEOF_LONG_LONG_ACCUM__
#      define __SIZEOF_LONG_LONG_ACCUM__   16
#   endif
#endif
/** Number of bytes in long long Accum */
#define BYTES_PER_LONG_LONG_ACCUM   SIZEOF_LONG_LONG_ACCUM
/** Number of bits in long long Accum */
#define BITS_PER_LONG_LONG_ACCUM   (SIZEOF_LONG_LONG_ACCUM * 8)
#define __SIZEOF_XINT_LLK_T__   SIZEOF_LONG_LONG_ACCUM
#define SIZEOF_XINT_LLK_T   SIZEOF_LONG_LONG_ACCUM
#define BYTES_PER_XINT_LLK_T   SIZEOF_LONG_LONG_ACCUM
#define BITS_PER_XINT_LLK_T   BITS_PER_LONG_LONG_ACCUM
#define __SIZEOF_XINT_ULLK_T__   SIZEOF_LONG_LONG_ACCUM
#define SIZEOF_XINT_ULLK_T   SIZEOF_LONG_LONG_ACCUM
#define BYTES_PER_XINT_ULLK_T   SIZEOF_LONG_LONG_ACCUM
#define BITS_PER_XINT_ULLK_T   BITS_PER_LONG_LONG_ACCUM
#define __SIZEOF_FX_LLK_T__   SIZEOF_LONG_LONG_ACCUM
#define SIZEOF_FX_LLK_T   SIZEOF_LONG_LONG_ACCUM
#define BYTES_PER_FX_LLK_T   SIZEOF_LONG_LONG_ACCUM
#define BITS_PER_FX_LLK_T   BITS_PER_LONG_LONG_ACCUM
#define __SIZEOF_FX_ULLK_T__   SIZEOF_LONG_LONG_ACCUM
#define SIZEOF_FX_ULLK_T   SIZEOF_LONG_LONG_ACCUM
#define BYTES_PER_FX_ULLK_T   SIZEOF_LONG_LONG_ACCUM
#define BITS_PER_FX_ULLK_T   BITS_PER_LONG_LONG_ACCUM


// SIZEOF ACCUMULATOR BITS

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


// SIZEOF COMPLEX DATATYPES

#ifdef __SIZEOF_COMPLEX_FLOAT__
#   ifndef SIZEOF_COMPLEX_FLOAT
#      define SIZEOF_COMPLEX_FLOAT   __SIZEOF_COMPLEX_FLOAT__
#   endif
#else
#   ifndef SIZEOF_COMPLEX_FLOAT
#      define SIZEOF_COMPLEX_FLOAT   8
#   endif
#   ifndef __SIZEOF_COMPLEX_FLOAT__
#      define __SIZEOF_COMPLEX_FLOAT__   8
#   endif
#endif
/** Number of bytes in complex float */
#define BYTES_PER_COMPLEX_FLOAT   SIZEOF_COMPLEX_FLOAT
/** Number of bits in complex float */
#define BITS_PER_COMPLEX_FLOAT   (SIZEOF_COMPLEX_FLOAT * 8)
#ifndef __SIZEOF_COMPLEX__
#   define __SIZEOF_COMPLEX__   SIZEOF_COMPLEX_FLOAT
#endif
#ifndef SIZEOF_COMPLEX
#   define SIZEOF_COMPLEX   SIZEOF_COMPLEX_FLOAT
#endif
#ifdef __SIZEOF_COMPLEX_DOUBLE__
#   ifndef SIZEOF_COMPLEX_DOUBLE
#      define SIZEOF_COMPLEX_DOUBLE   __SIZEOF_COMPLEX_DOUBLE__
#   endif
#else
#   ifndef SIZEOF_COMPLEX_DOUBLE
#      define SIZEOF_COMPLEX_DOUBLE   16
#   endif
#   ifndef __SIZEOF_COMPLEX_DOUBLE__
#      define __SIZEOF_COMPLEX_DOUBLE__   16
#   endif
#endif
/** Number of bytes in complex double */
#define BYTES_PER_COMPLEX_DOUBLE   SIZEOF_COMPLEX_DOUBLE
/** Number of bits in complex double */
#define BITS_PER_COMPLEX_DOUBLE   (SIZEOF_COMPLEX_DOUBLE * 8)
#ifdef __SIZEOF_COMPLEX_LONG_DOUBLE__
#   ifndef SIZEOF_COMPLEX_LONG_DOUBLE
#      define SIZEOF_COMPLEX_LONG_DOUBLE   __SIZEOF_COMPLEX_LONG_DOUBLE__
#   endif
#else
#   ifndef SIZEOF_COMPLEX_LONG_DOUBLE
#      define SIZEOF_COMPLEX_LONG_DOUBLE   (SIZEOF_LONG_DOUBLE * 2)
#   endif
#   ifndef __SIZEOF_COMPLEX_LONG_DOUBLE__
#      define __SIZEOF_COMPLEX_LONG_DOUBLE__   (SIZEOF_LONG_DOUBLE * 2)
#   endif
#endif
/** Number of bytes in complex long double */
#define BYTES_PER_COMPLEX_LONG_DOUBLE   SIZEOF_COMPLEX_LONG_DOUBLE
/** Number of bits in complex long double */
#define BITS_PER_COMPLEX_LONG_DOUBLE   (SIZEOF_COMPLEX_LONG_DOUBLE * 8)
#ifdef __SIZEOF_COMPLEX_FLOAT128__
#   ifndef SIZEOF_COMPLEX_FLOAT128
#      define SIZEOF_COMPLEX_FLOAT128   __SIZEOF_COMPLEX_FLOAT128__
#   endif
#else
#   ifndef SIZEOF_COMPLEX_FLOAT128
#      define SIZEOF_COMPLEX_FLOAT128   32
#   endif
#   ifndef __SIZEOF_COMPLEX_FLOAT128__
#      define __SIZEOF_COMPLEX_FLOAT128__   32
#   endif
#endif
/** Number of bytes in complex float128 */
#define BYTES_PER_COMPLEX_FLOAT128   SIZEOF_COMPLEX_FLOAT128
/** Number of bits in complex float128 */
#define BITS_PER_COMPLEX_FLOAT128   (SIZEOF_COMPLEX_FLOAT128 * 8)


// SIZEOF POSIX THREAD DATATYPES

#if (defined(ARCHALPHA) || defined(ARCHITANIUM) || defined(ARCHMIPS64) || defined(ARCHPOWERPC64) || defined(ARCHS390X) || defined(ARCHSPARC64) || defined(ARCHX86_64))
#   define SIZEOF_PTHREAD_ATTR_T   56
#   define SIZEOF_PTHREAD_MUTEX_T   40
#   define SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define SIZEOF_PTHREAD_COND_T   48
#   define SIZEOF_PTHREAD_CONDATTR_T   4
#   define SIZEOF_PTHREAD_RWLOCK_T   56
#   define SIZEOF_PTHREAD_BARRIER_T   32
#   define SIZEOF_PTHREAD_BARRIERATTR_T   4
#elif defined(ARCHX86_32)
#   define SIZEOF_PTHREAD_ATTR_T   32
#   define SIZEOF_PTHREAD_MUTEX_T   32
#   define SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define SIZEOF_PTHREAD_COND_T   48
#   define SIZEOF_PTHREAD_CONDATTR_T   4
#   define SIZEOF_PTHREAD_RWLOCK_T   44
#   define SIZEOF_PTHREAD_BARRIER_T   20
#   define SIZEOF_PTHREAD_BARRIERATTR_T   4
#elif (defined(ARCHM68K) || defined(ARCHMICROBLAZE) || defined(ARCHMIPS32) || defined(ARCHNIOS2) || defined(ARCHPOWERPC32) || defined(ARCHS390) || defined(ARCHSPARC32))
#   define SIZEOF_PTHREAD_ATTR_T   36
#   define SIZEOF_PTHREAD_MUTEX_T   24
#   define SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define SIZEOF_PTHREAD_COND_T   48
#   define SIZEOF_PTHREAD_CONDATTR_T   4
#   define SIZEOF_PTHREAD_RWLOCK_T   32
#   define SIZEOF_PTHREAD_BARRIER_T   20
#   define SIZEOF_PTHREAD_BARRIERATTR_T   4
#elif defined(ARCHAARCH64)
#   define SIZEOF_PTHREAD_ATTR_T   64
#   define SIZEOF_PTHREAD_MUTEX_T   48
#   define SIZEOF_PTHREAD_MUTEXATTR_T   8
#   define SIZEOF_PTHREAD_COND_T   48
#   define SIZEOF_PTHREAD_COND_COMPAT_T   48
#   define SIZEOF_PTHREAD_CONDATTR_T   8
#   define SIZEOF_PTHREAD_RWLOCK_T   56
#   define SIZEOF_PTHREAD_BARRIER_T   32
#   define SIZEOF_PTHREAD_BARRIERATTR_T   8
#elif (defined(ARCHARC) || defined(ARCHTILE))
#   if IS_WORDSIZE_64
#      define SIZEOF_PTHREAD_ATTR_T   56
#      define SIZEOF_PTHREAD_MUTEX_T   40
#      define SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define SIZEOF_PTHREAD_COND_T   48
#      define SIZEOF_PTHREAD_CONDATTR_T   4
#      define SIZEOF_PTHREAD_RWLOCK_T   56
#      define SIZEOF_PTHREAD_BARRIER_T   32
#      define SIZEOF_PTHREAD_BARRIERATTR_T   4
#   else
#      define SIZEOF_PTHREAD_ATTR_T   36
#      define SIZEOF_PTHREAD_MUTEX_T   24
#      define SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define SIZEOF_PTHREAD_COND_T   48
#      define SIZEOF_PTHREAD_CONDATTR_T   4
#      define SIZEOF_PTHREAD_RWLOCK_T   32
#      define SIZEOF_PTHREAD_BARRIER_T   20
#      define SIZEOF_PTHREAD_BARRIERATTR_T   4
#   endif
#elif defined(ARCHPARISC)
#   define SIZEOF_PTHREAD_ATTR_T   36
#   define SIZEOF_PTHREAD_MUTEX_T   48
#   define SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define SIZEOF_PTHREAD_COND_T   48
#   define SIZEOF_PTHREAD_CONDATTR_T   4
#   define SIZEOF_PTHREAD_RWLOCK_T   64
#   define SIZEOF_PTHREAD_BARRIER_T   48
#   define SIZEOF_PTHREAD_BARRIERATTR_T   4
#elif (defined(ARCHSUPERH) || defined(ARCHXTENSA))
#   define SIZEOF_PTHREAD_ATTR_T   36
#   define SIZEOF_PTHREAD_MUTEX_T   24
#   define SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define SIZEOF_PTHREAD_COND_T   48
#   define SIZEOF_PTHREAD_COND_COMPAT_T   12
#   define SIZEOF_PTHREAD_CONDATTR_T   4
#   define SIZEOF_PTHREAD_RWLOCK_T   32
#   define SIZEOF_PTHREAD_BARRIER_T   20
#   define SIZEOF_PTHREAD_BARRIERATTR_T   4
#else
#   define SIZEOF_PTHREAD_ATTR_T   36
#   define SIZEOF_PTHREAD_MUTEX_T   24
#   define SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define SIZEOF_PTHREAD_COND_T   48
#   define SIZEOF_PTHREAD_CONDATTR_T   4
#   define SIZEOF_PTHREAD_RWLOCK_T   32
#   define SIZEOF_PTHREAD_BARRIER_T   20
#   define SIZEOF_PTHREAD_BARRIERATTR_T   4
#endif
#ifndef SIZEOF_PTHREAD_SPINLOCK_T
#   define SIZEOF_PTHREAD_SPINLOCK_T   32
#endif
#ifndef SIZEOF_PTHREAD_RWLOCKATTR_T
#   define SIZEOF_PTHREAD_RWLOCKATTR_T   8
#endif


// SIZEOF MISCELLANEOUS DATATYPES

#ifndef _FP_W_TYPE_SIZE
/** Size in bits of `_FP_W_TYPE` */
#   define _FP_W_TYPE_SIZE   W_TYPE_SIZE
#endif
#define SIZEOF_DIV_T   SIZEOF_INT
#define SIZEOF_LDIV_T   SIZEOF_LONG
#define SIZEOF_LLDIV_T   SIZEOF_LONG_LONG
#ifdef __SIZEOF_WCHAR_T__
#   ifndef SIZEOF_WCHAR_T
#      define SIZEOF_WCHAR_T   __SIZEOF_WCHAR_T__
#   endif
#else
#   ifndef SIZEOF_WCHAR_T
#      define SIZEOF_WCHAR_T   BYTES_PER_INT
#   endif
#   ifndef __SIZEOF_WCHAR_T__
#      define __SIZEOF_WCHAR_T__   BYTES_PER_INT
#   endif
#endif
#ifndef __WCHAR_WIDTH__
/** The bit-width of wchar_t */
#   define __WCHAR_WIDTH__   BITS_PER_INT
#endif
#ifndef WCHAR_WIDTH
#   define WCHAR_WIDTH   BITS_PER_INT
#endif
/** Number of bits in wchar_t */
#define BITS_PER_WCHAR_T   BITS_PER_INT
#if (SIZEOF_WCHAR_T == SIZEOF_INT)
/** Equals `1` if `wchar_t` is the same size as `short` */
#   define WCHAR_EQ_SHORT   0
/** Equals `1` if `wchar_t` is the same size as `int` */
#   define WCHAR_EQ_INT   1
#elif (SIZEOF_WCHAR_T == SIZEOF_SHORT)
/** Equals `1` if `wchar_t` is the same size as `short` */
#   define WCHAR_EQ_SHORT   1
/** Equals `1` if `wchar_t` is the same size as `int` */
#   define WCHAR_EQ_INT   0
#else
#   error   "The target platform is not supported (mismatched sizes of `wchar_t`, `short`, and `int`)!"
#endif
#ifndef __SIZEOF_WINT_T__
#   define __SIZEOF_WINT_T__   BYTES_PER_INT
#endif
#ifndef SIZEOF_WINT_T
#   define SIZEOF_WINT_T   BYTES_PER_INT
#endif
#ifndef __WINT_WIDTH__
/** The bit-width of wint_t */
#   define __WINT_WIDTH__   BITS_PER_INT
#endif
#ifndef WINT_WIDTH
#   define WINT_WIDTH   BITS_PER_INT
#endif
/** Number of bits in wint_t */
#define BITS_PER_WINT_T   BITS_PER_INT
#if (SIZEOF_WINT_T == SIZEOF_INT)
/** Equals `1` if `wint_t` is the same size as `short` */
#   define WINT_EQ_SHORT   0
/** Equals `1` if `wint_t` is the same size as `int` */
#   define WINT_EQ_INT   1
#elif (SIZEOF_WINT_T == SIZEOF_SHORT)
/** Equals `1` if `wint_t` is the same size as `short` */
#   define WINT_EQ_SHORT   1
/** Equals `1` if `wint_t` is the same size as `int` */
#   define WINT_EQ_INT   0
#else
#   error   "The target platform is not supported (mismatched sizes of `wint_t`, `short`, and `int`)!"
#endif
#ifdef __SIZEOF_RUNE__
#   ifndef SIZEOF_RUNE
#      define SIZEOF_RUNE   __SIZEOF_RUNE__
#   endif
#else
#   ifndef SIZEOF_RUNE
#      define SIZEOF_RUNE   BYTES_PER_INT
#   endif
#   ifndef __SIZEOF_RUNE__
#      define __SIZEOF_RUNE__   BYTES_PER_INT
#   endif
#endif
/** Number of bits in Rune */
#define BITS_PER_RUNE   BITS_PER_INT
/** Number of bits in Rune */
#define BITSIZEOF_RUNE   BITS_PER_INT
#ifdef __SIZEOF_MBSTATE_T__
#   ifndef SIZEOF_MBSTATE_T
#      define SIZEOF_MBSTATE_T   __SIZEOF_MBSTATE_T__
#   endif
#else
#   ifndef SIZEOF_MBSTATE_T
#      define SIZEOF_MBSTATE_T   64
#   endif
#   ifndef __SIZEOF_MBSTATE_T__
#      define __SIZEOF_MBSTATE_T__   64
#   endif
#endif
/** Number of bits in mbstate_t */
#define BITS_PER_MBSTATE_T   (__SIZEOF_MBSTATE_T__ * 8)
/** Number of bits in sig_atomic_t */
#define BITSIZEOF_SIG_ATOMIC_T   (SIZEOF_INT * 8)
#ifndef __SIG_ATOMIC_WIDTH__
/** Number of bits in sig_atomic_t */
#   define __SIG_ATOMIC_WIDTH__   BITSIZEOF_SIG_ATOMIC_T
#endif
#ifndef BITS_PER_SIG_ATOMIC
#   define BITS_PER_SIG_ATOMIC   BITSIZEOF_SIG_ATOMIC_T
#endif
/** The size (in bytes) of zone_t */
#define __SIZEOF_ZONE_T__   4
/** The size (in bytes) of zone_t */
#define __SIZEOF_ZONE__   4
/** The size (in bytes) of zone_t */
#define SIZEOF_ZONE   4
#define SIZEOF_PID_T   SIZEOF_INT
#define BITS_PER_PID_T   BITS_PER_INT
#define SIZEOF_SUSECONDS_T   SIZEOF_LONG
#define BITS_PER_SUSECONDS_T   BITS_PER_LONG
#define SIZEOF_TIME_T   SIZEOF_LONG
#define BITS_PER_TIME_T   BITS_PER_LONG
#define SIZEOF_TIMER_T   SIZEOF_POINTER
#define BITS_PER_TIMER_T   BITS_PER_POINTER
#define SIZEOF_TIMEVAL_T   (SIZEOF_SUSECONDS_T + SIZEOF_TIME_T)
#define BITS_PER_TIMEVAL_T   (BITS_PER_SUSECONDS_T + BITS_PER_TIME_T)
#define SIZEOF_TIMEVAL   SIZEOF_TIMEVAL
#define BITS_PER_TIMEVAL   BITS_PER_TIMEVAL
#define SIZEOF_TIMEZONE_T   (SIZEOF_INT * 2)
#define BITS_PER_TIMEZONE_T   (BITS_PER_INT * 2)
#define SIZE_hh   -2
#define SIZE_h   -1
#define SIZE_def   0
#define SIZE_l   1
#define SIZE_L   2
#define SIZE_ll   3
#define BITS_PER_MP_LIMB   WORDSIZE
#define BYTES_PER_MP_LIMB   BYTES_PER_WORD


// ALIGNMENT OF COMMON DATATYPES

#ifndef ALIGNOF_CHAR
#   define ALIGNOF_CHAR   1
#endif
#ifndef ALIGNOF_SHORT
#   define ALIGNOF_SHORT   2
#endif
#ifndef ALIGNOF_INT
#   define ALIGNOF_INT   4
#endif
#ifndef ALIGNOF_FLOAT
#   define ALIGNOF_FLOAT   4
#endif
#ifndef ALIGNOF_DOUBLE
#   define ALIGNOF_DOUBLE   8
#endif
#if ((!defined(ALIGNOF_LONG)) && LONG_EQ_64BITS)
#   define ALIGNOF_LONG   8
#elif ((!defined(ALIGNOF_LONG)) && LLONG_EQ_32BITS)
#   define ALIGNOF_LONG   4
#endif
#ifndef SALIGN
#   define SALIGN   (SIZEOF_LONG - 1)
#endif
#if ((!defined(ALIGNOF_POINTER)) && PTR_EQ_64BITS)
#   define ALIGNOF_POINTER   8
#elif ((!defined(ALIGNOF_POINTER)) && PTR_EQ_32BITS)
#   define ALIGNOF_POINTER   4
#endif
#if ((!defined(ALIGNOF_WORD)) && IS_WORDSIZE_64)
#   define ALIGNOF_WORD   8
#elif ((!defined(ALIGNOF_WORD)) && IS_WORDSIZE_32)
#   define ALIGNOF_WORD   4
#endif
#if ((!defined(ALIGNOF_LONG_LONG)) && LLONG_EQ_64BITS)
#   define ALIGNOF_LONG_LONG   8
#elif ((!defined(ALIGNOF_LONG_LONG)) && LLONG_EQ_32BITS)
#   define ALIGNOF_LONG_LONG   4
#endif
#if ((!defined(ALIGNOF_LONG_DOUBLE)) && IS_64 && IS_GNUC)
#   define ALIGNOF_LONG_DOUBLE   16
#elif ((!defined(ALIGNOF_LONG_DOUBLE)) && LDBL_EQ_XFtype && defined(DATAMODEL_ILP32))
#   define ALIGNOF_LONG_DOUBLE   4
#elif ((!defined(ALIGNOF_LONG_DOUBLE)) && IS_64)
#   define ALIGNOF_LONG_DOUBLE   8
#elif ((!defined(ALIGNOF_LONG_DOUBLE)) && IS_32 && IS_GNUC)
#   define ALIGNOF_LONG_DOUBLE   4
#elif ((!defined(ALIGNOF_LONG_DOUBLE)) && IS_32)
#   define ALIGNOF_LONG_DOUBLE   8
#endif
#if ((!defined(ALIGNOF_INT64)) && defined(ARCHARM))
#   define ALIGNOF_INT64   4
#elif (!defined(ALIGNOF_INT64))
#   define ALIGNOF_INT64   8
#endif


// ALIGNMENT OF STDFIX DATATYPES

/** Alignment of short Fract */
#define ALIGNOF_SHORT_FRACT   1
/** Alignment of Fract */
#define ALIGNOF_FRACT   2
/** Alignment of long Fract */
#define ALIGNOF_LONG_FRACT   4
/** Alignment of long Fract */
#define ALIGNOF_LONG_LONG_FRACT   8
/** Alignment of short Accum */
#define ALIGNOF_SHORT_ACCUM   2
/** Alignment of Accum */
#define ALIGNOF_ACCUM   4
/** Alignment of long Accum */
#define ALIGNOF_LONG_ACCUM   8


// ALIGNMENT OF MISCELLANEOUS DATATYPES

#define sa_alignment_char   ALIGNOF_CHAR
#define sa_alignment_short   ALIGNOF_SHORT
#define sa_alignment_int   ALIGNOF_INT
#define sa_alignment_long   ALIGNOF_LONG
#define sa_alignment_double   ALIGNOF_DOUBLE
#define sa_alignment_longdouble   ALIGNOF_LONG_DOUBLE
#if (ALIGNOF_DOUBLE == 8)
#   define HAVE_ALIGNED_DOUBLES   1
#endif
#if (ALIGNOF_INT64 == 8)
#   define HAVE_ALIGNED_LONGLONGS   1
#endif
#if (defined(HAVE_LONG_LONG_INT) && HAVE_LONG_LONG_INT)
#   define sa_alignment_longlong   ALIGNOF_LONG_LONG
#   define sa_alignment_max   (((sa_alignment_long - 1) | (sa_alignment_double - 1) | (sa_alignment_longlong - 1) | (sa_alignment_longdouble - 1)) + 1)
#else
#   define sa_alignment_max   (((sa_alignment_long - 1) | (sa_alignment_double - 1) | (sa_alignment_longdouble - 1)) + 1)
#endif
/** @def _STRING_ARCH_unaligned
Define to 1 if the architecture can access unaligned multi-byte variables */
#ifdef ARCHAARCH64
#   define _STRING_ARCH_unaligned   1
#elif (defined(ARCHX86) || defined(ARCHM68K))
#   define _STRING_ARCH_unaligned   1
#elif defined(ARCHS390)
#   define _STRING_ARCH_unaligned   1
#else
#   define _STRING_ARCH_unaligned   0
#endif
#define STRING_ARCH_unaligned   _STRING_ARCH_unaligned
#define string_arch_unaligned   _STRING_ARCH_unaligned


#endif  // BITS_WORDSIZE_H


/* LIMITS OF DATATYPES (<limits.h>) */


#if (!(defined(LIMITS_H) || defined(_LIMITS_H_) || defined(LIBC_LIMITS_H) || defined(_LIBC_LIMITS_H_)))  // http://www.cplusplus.com/reference/climits/ & http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/limits.h.html
#define LIMITS_H   (1)
#define _LIMITS_H   (1)
#define _LIMITS_H_   (1)
#define __LIMITS   (1)
#define LIBC_LIMITS_H   (1)
#define _LIBC_LIMITS_H   (1)
#define _LIBC_LIMITS_H_   (1)
#define __CLANG_LIMITS_H   (1)
#define _GCC_LIMITS_H_   (1)
#define _GCC_NEXT_LIMITS_H   (1)


// MAXIMUM OF SIGNED FIXED-WIDTH INTEGRAL TYPES

/** Maximum value of an object of type int8_t (127) */
#define INT8_MAX   0x7f
#ifndef __INT8_MAX__
#   define __INT8_MAX__   INT8_MAX
#endif
#ifndef MAX_8
#   define MAX_8   INT8_MAX
#endif
/** Maximum value of an object of type int16_t (32767) */
#define INT16_MAX   0x7fff
#ifndef __INT16_MAX__
#   define __INT16_MAX__   INT16_MAX
#endif
#ifndef MAX_16
#   define MAX_16   INT16_MAX
#endif
/** @def INT32_MAX
Maximum value of an object of type int32_t (2147483647) */
#ifdef __INT32_MAX__
#   define INT32_MAX   __INT32_MAX__
#else
#   define INT32_MAX   0x7fffffff
#   define __INT32_MAX__   INT32_MAX
#endif
#ifndef MAX_32
#   define MAX_32   INT32_MAX
#endif
#ifndef INT_MAX_32_BITS
#   define INT_MAX_32_BITS   INT32_MAX
#endif
/** @def INT64_MAX
Maximum value of an object of type int64_t (9223372036854775807) */
#ifdef __INT64_MAX__
#   define INT64_MAX   __INT64_MAX__
#else
#   define INT64_MAX   0x7fffffffffffffffLL
#   define __INT64_MAX__   INT64_MAX
#endif
#ifndef MAX_64
#   define MAX_64   INT64_MAX
#endif
#if SUPPORTS_INT128
/** @def INT128_MAX
Maximum value of an object of type int128_t (170141183460469231731687303715884105727) */
#   ifndef INT128_MAX
#      define INT128_MAX   0x7fffffffffffffffffffffffffffffffi128
#   endif
#   ifndef __INT128_MAX__
#      define __INT128_MAX__   INT128_MAX
#   endif
#endif


// MINIMUM OF SIGNED FIXED-WIDTH INTEGRAL TYPES

/** @def INT8_MIN
Minimum value of an object of type int8_t (-128) */
/** @def __INT8_MIN__
Minimum value of an object of type int8_t (-128) */
#ifdef __INT8_MIN__
#   define INT8_MIN   __INT8_MIN__
#else
#   define INT8_MIN   ((-INT8_MAX) - 1)
#   define __INT8_MIN__   INT8_MIN
#endif
#ifndef MIN_8
#   define MIN_8   INT8_MIN
#endif
/** @def INT16_MIN
Minimum value of an object of type int16_t (-32768) */
/** @def __INT16_MIN__
Minimum value of an object of type int16_t (-32768) */
#ifdef __INT16_MIN__
#   define INT16_MIN   __INT16_MIN__
#else
#   define INT16_MIN   ((-INT16_MAX) - 1)
#   define __INT16_MIN__   INT16_MIN
#endif
#ifndef MIN_16
#   define MIN_16   INT16_MIN
#endif
/** @def INT32_MIN
Minimum value of an object of type int32_t (-2147483648) */
/** @def __INT32_MIN__
Minimum value of an object of type int32_t (-2147483648) */
#ifdef __INT32_MIN__
#   define INT32_MIN   __INT32_MIN__
#else
#   define INT32_MIN   ((-INT32_MAX) - 1)
#   define __INT32_MIN__   INT32_MIN
#endif
#ifndef MIN_32
#   define MIN_32   INT32_MIN
#endif
/** @def INT64_MIN
Minimum value of an object of type int64_t (-9223372036854775808) */
/** @def __INT64_MIN__
Minimum value of an object of type int64_t (-9223372036854775808) */
#ifdef __INT64_MIN__
#   define INT64_MIN   __INT64_MIN__
#else
#   define INT64_MIN   ((-INT64_MAX) - 1)
#   define __INT64_MIN__   INT64_MIN
#endif
#ifndef MIN_64
#   define MIN_64   INT64_MIN
#endif
#if SUPPORTS_INT128
/** @def INT128_MIN
Minimum value of an object of type int128_t (-170141183460469231731687303715884105728) */
/** @def __INT128_MIN__
Minimum value of an object of type int128_t (-170141183460469231731687303715884105728) */
#   ifndef INT128_MIN
#      define INT128_MIN   ((-INT128_MAX) - 1)
#   endif
#   ifndef __INT128_MIN__
#      define __INT128_MIN__   INT128_MIN
#   endif
#endif


// MAXIMUM OF UNSIGNED FIXED-WIDTH INTEGRAL TYPES

/** Maximum value of an object of type uint8_t (255) */
#define UINT8_MAX   0xffU
/** Maximum value of an object of type uint16_t (65535) */
#define UINT16_MAX   0xffffU
/** @def UINT32_MAX
Maximum value of an object of type uint32_t (4294967295) */
#ifdef __UINT32_MAX__
#   define UINT32_MAX   __UINT32_MAX__
#else
#   define UINT32_MAX   0xffffffffU
#endif
/** Maximum value storable in ppnum_t */
#define PPNUM_MAX   UINT32_MAX
#define ATM_SUBAID32_MAX   UINT32_MAX
/** @def UINT64_MAX
Maximum value of an object of type uint64_t (18446744073709551615) */
#ifdef __UINT64_MAX__
#   define UINT64_MAX   __UINT64_MAX__
#else
#   define UINT64_MAX   0xffffffffffffffffULL
#endif
#define SUB_AID_MAX   UINT64_MAX
#if SUPPORTS_INT128
/** @def UINT128_MAX
Maximum value of an object of type uint128_t (340282366920938463463374607431768211455) */
#   ifndef UINT128_MAX
#      define UINT128_MAX   0xffffffffffffffffffffffffffffffffUi128
#   endif
#   ifndef __UINT128_MAX__
#      define __UINT128_MAX__   UINT128_MAX
#   endif
#endif


// MINIMUM OF SIGNED FIXED-WIDTH INTEGRAL TYPES HAVING A MINIMUM SIZE

#ifdef __INT_LEAST8_MIN__
#   define INT_LEAST8_MIN   __INT_LEAST8_MIN__
#else
#   define INT_LEAST8_MIN   INT8_MIN
#   define __INT_LEAST8_MIN__   INT8_MIN
#endif
#ifdef __INT_LEAST16_MIN__
#   define INT_LEAST16_MIN   __INT_LEAST16_MIN__
#else
#   define INT_LEAST16_MIN   INT16_MIN
#   define __INT_LEAST16_MIN__   INT16_MIN
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

/** @def UINT_LEAST8_MAX
Maximum value of an object of type uint_least8_t */
#ifdef __UINT_LEAST8_MAX__
#   define UINT_LEAST8_MAX   __UINT_LEAST8_MAX__
#else
#   define UINT_LEAST8_MAX   UINT8_MAX
#   define __UINT_LEAST8_MAX__   UINT8_MAX
#endif
#ifdef __UINT_LEAST16_MAX__
#   define UINT_LEAST16_MAX   __UINT_LEAST16_MAX__
#else
#   define UINT_LEAST16_MAX   UINT16_MAX
#   define __UINT_LEAST16_MAX__   UINT16_MAX
#endif
/** @def UINT_LEAST32_MAX
Maximum value of an object of type uint_least32_t */
#ifdef __UINT_LEAST32_MAX__
#   define UINT_LEAST32_MAX   __UINT_LEAST32_MAX__
#else
#   define UINT_LEAST32_MAX   UINT32_MAX
#   define __UINT_LEAST32_MAX__   UINT32_MAX
#endif
/** @def UINT_LEAST64_MAX
Maximum value of an object of type uint_least64_t */
#ifdef __UINT_LEAST64_MAX__
#   define UINT_LEAST64_MAX   __UINT_LEAST64_MAX__
#else
#   define UINT_LEAST64_MAX   UINT64_MAX
#   define __UINT_LEAST64_MAX__   UINT64_MAX
#endif
#if SUPPORTS_INT128
/** @def UINT_LEAST128_MAX
Maximum value of an object of type uint_least128_t */
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
#   define INT_FAST8_MIN   INT8_MIN
#   define __INT_FAST8_MIN__   INT8_MIN
#endif
#ifdef __INT_FAST16_MIN__
#   define INT_FAST16_MIN   __INT_FAST16_MIN__
#elif IS_WORDSIZE_64
#   define __INT_FAST16_MIN__   INT64_MIN
#   define INT_FAST16_MIN   INT64_MIN
#else
#   define __INT_FAST16_MIN__   INT32_MIN
#   define INT_FAST16_MIN   INT32_MIN
#endif
#ifdef __INT_FAST32_MIN__
#   define INT_FAST32_MIN   __INT_FAST32_MIN__
#elif IS_WORDSIZE_64
#   define __INT_FAST32_MIN__   INT64_MIN
#   define INT_FAST32_MIN   INT64_MIN
#else
#   define __INT_FAST32_MIN__   INT32_MIN
#   define INT_FAST32_MIN   INT32_MIN
#endif
#ifdef __INT_FAST64_MIN__
#   define INT_FAST64_MIN   __INT_FAST64_MIN__
#else
#   define INT_FAST64_MIN   INT64_MIN
#   define __INT_FAST64_MIN__   INT64_MIN
#endif
#if SUPPORTS_INT128
#   ifdef __INT_FAST128_MIN__
#      define INT_FAST128_MIN   __INT_FAST128_MIN__
#   else
#      define INT_FAST128_MIN   INT128_MIN
#      define __INT_FAST128_MIN__   INT128_MIN
#   endif
#endif


// MAXIMUM OF SIGNED FAST FIXED-WIDTH INTEGRAL TYPES

#ifdef __INT_FAST8_MAX__
#   define INT_FAST8_MAX   __INT_FAST8_MAX__
#else
#   define INT_FAST8_MAX   INT8_MAX
#endif
#ifdef __INT_FAST16_MAX__
#   define INT_FAST16_MAX   __INT_FAST16_MAX__
#else
#   if IS_WORDSIZE_64
#      define INT_FAST16_MAX   INT64_MAX
#      define __INT_FAST16_MAX__   INT64_MAX
#   else
#      define INT_FAST16_MAX   INT32_MAX
#      define __INT_FAST16_MAX__   INT32_MAX
#   endif
#endif
#ifdef __INT_FAST32_MAX__
#   define INT_FAST32_MAX   __INT_FAST32_MAX__
#elif IS_WORDSIZE_64
#   define INT_FAST32_MAX   INT64_MAX
#   define __INT_FAST32_MAX__   INT64_MAX
#else
#   define INT_FAST32_MAX   INT32_MAX
#   define __INT_FAST32_MAX__   INT32_MAX
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
#   define UINT_FAST8_MAX   UINT8_MAX
#endif
#ifdef __UINT_FAST16_MAX__
#   define UINT_FAST16_MAX   __UINT_FAST16_MAX__
#else
#   if IS_WORDSIZE_64
#      define UINT_FAST16_MAX   UINT64_MAX
#      define __UINT_FAST16_MAX__   UINT64_MAX
#   else
#      define UINT_FAST16_MAX   UINT32_MAX
#      define __UINT_FAST16_MAX__   UINT32_MAX
#   endif
#endif
#ifdef __UINT_FAST32_MAX__
#   define UINT_FAST32_MAX   __UINT_FAST32_MAX__
#else
#   if IS_WORDSIZE_64
#      define UINT_FAST32_MAX   UINT64_MAX
#      define __UINT_FAST32_MAX__   UINT64_MAX
#   else
#      define UINT_FAST32_MAX   UINT32_MAX
#      define __UINT_FAST32_MAX__   UINT32_MAX
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

#if SUPPORTS_INT24
#   define INT24_MAX   8388607
#   define INT24_MIN   ((-INT24_MAX) - 1)  // -8388608
#   define UINT24_MAX   16777215
#   define INT_LEAST24_MIN   INT32_MIN
#   define INT_LEAST24_MAX   INT32_MAX
#   define UINT_LEAST24_MAX   UINT32_MAX
#   define INT_FAST24_MIN   INT32_MIN
#   define INT_FAST24_MAX   INT32_MAX
#   define UINT_FAST24_MAX   UINT32_MAX
#endif
#if SUPPORTS_INT40
#   define INT40_MAX   549755813887
#   define INT40_MIN   ((-INT40_MAX) - 1)  // -549755813888
#   define UINT40_MAX   1099511627775
#   define INT_LEAST40_MIN   INT40_MIN
#   define INT_LEAST40_MAX   INT40_MAX
#   define UINT_LEAST40_MAX   UINT40_MAX
#   define INT_FAST40_MIN   INT40_MIN
#   define INT_FAST40_MAX   INT40_MAX
#   define UINT_FAST40_MAX   UINT40_MAX
#endif
#if SUPPORTS_INT48
#   define INT48_MAX   140737488355327
#   define INT48_MIN   ((-INT48_MAX) - 1)  // -140737488355328
#   define UINT48_MAX   281474976710655
#   define INT_LEAST48_MIN   INT48_MIN
#   define INT_LEAST48_MAX   INT48_MAX
#   define UINT_LEAST48_MAX   UINT48_MAX
#   define INT_FAST48_MIN   INT48_MIN
#   define INT_FAST48_MAX   INT48_MAX
#   define UINT_FAST48_MAX   UINT48_MAX
#endif
#if SUPPORTS_INT56
#   define INT56_MAX   36028797018963967LL
#   define INT56_MIN   ((-INT56_MAX) - 1)  // -36028797018963968
#   define UINT56_MAX   72057594037927935ULL
#   define INT_LEAST56_MIN   INT56_MIN
#   define INT_LEAST56_MAX   INT56_MAX
#   define UINT_LEAST56_MAX   UINT56_MAX
#   define INT_FAST56_MIN   INT56_MIN
#   define INT_FAST56_MAX   INT56_MAX
#   define UINT_FAST56_MAX   UINT56_MAX
#endif


// MAXIMUM/MINIMUM VALUES FOR INTPTR_T, UINTPTR_T, INTMAX_T, & UINTMAX_T

/** @def INTPTR_MAX
Maximum value representable as type intptr_t */
#ifdef __INTPTR_MAX__
#   define INTPTR_MAX   __INTPTR_MAX__
#elif IS_WORDSIZE_32
#   define INTPTR_MAX   INT32_MAX
#else
#   define INTPTR_MAX   INT64_MAX
#endif
/** @def INTPTR_MIN
Minimum value representable as type intptr_t */
#ifdef __INTPTR_MIN__
#   define INTPTR_MIN   __INTPTR_MIN__
#elif IS_WORDSIZE_32
#   define INTPTR_MIN   INT32_MIN
#else
#   define INTPTR_MIN   INT64_MIN
#endif
/** @def UINTPTR_MAX
Maximum value representable as type uintptr_t */
#ifdef __UINTPTR_MAX__
#   define UINTPTR_MAX   __UINTPTR_MAX__
#elif IS_WORDSIZE_32
#   define UINTPTR_MAX   UINT32_MAX
#else
#   define UINTPTR_MAX   UINT64_MAX
#endif
/** @def INTMAX_MIN
Minimum for largest signed fixed-width integral type */
#ifndef INTMAX_MIN
#   ifdef __INTMAX_MIN__
#      define INTMAX_MIN   __INTMAX_MIN__
#   else
#      define INTMAX_MIN   INT64_MIN
#   endif
#elif SUPPORTS_INT128
#   define INTMAX_MIN   INT128_MIN
#else
#   define INTMAX_MIN   INT64_MIN
#endif
/** @def INTMAX_MAX
Maximum for largest signed fixed-width integral type */
#ifndef INTMAX_MAX
#   ifdef __INTMAX_MAX__
#      define INTMAX_MAX   __INTMAX_MAX__
#   else
#      define INTMAX_MAX   INT64_MAX
#   endif
#elif SUPPORTS_INT128
#   define INTMAX_MAX   INT128_MAX
#else
#   define INTMAX_MAX   INT64_MAX
#endif
/** @def UINTMAX_MAX
Maximum for largest unsigned fixed-width integral type */
#ifdef __UINTMAX_MAX__
#   define UINTMAX_MAX   __UINTMAX_MAX__
#elif SUPPORTS_INT128
#   define UINTMAX_MAX   UINT128_MAX
#   define __UINTMAX_MAX__   UINT128_MAX
#else
#   define UINTMAX_MAX   UINT64_MAX
#   define __UINTMAX_MAX__   UINT64_MAX
#endif


// LIMITS OF `CHAR`, `SCHAR`, & `UCHAR`

/** @def SCHAR_MIN
Minimum value a `signed char` can hold */
#ifdef __SCHAR_MIN__
#   define SCHAR_MIN   __SCHAR_MIN__
#else
#   define SCHAR_MIN   INT8_MIN
#   define __SCHAR_MIN__   SCHAR_MIN
#endif
/** @def SCHAR_MAX
Maximum value a `signed char` can hold */
#ifdef __SCHAR_MAX__
#   define SCHAR_MAX   __SCHAR_MAX__
#else
#   define SCHAR_MAX   INT8_MAX
#   define __SCHAR_MAX__   SCHAR_MAX
#endif
/** @def UCHAR_MAX
Maximum value an `unsigned char` can hold (Minimum is 0) */
#ifdef __UCHAR_MAX__
#   define UCHAR_MAX   __UCHAR_MAX__
#else
#   define UCHAR_MAX   UINT8_MAX
#   define __UCHAR_MAX__   UCHAR_MAX
#endif
/** @def CHAR_MIN
Minimum value a `char` can hold */
/** @def CHAR_MAX
Maximum value a `char` can hold */
#if IS_CHAR_UNSIGNED
#   ifndef CHAR_MIN
#      define CHAR_MIN   0
#   endif
#   ifndef CHAR_MAX
#      define CHAR_MAX   UCHAR_MAX
#   endif
#else
#   ifndef CHAR_MIN
#      define CHAR_MIN   SCHAR_MIN
#   endif
#   ifndef CHAR_MAX
#      define CHAR_MAX   SCHAR_MAX
#   endif
#endif
#define UTF_WIDTH1_MAX   0x7f
#define UTF_WIDTH2_MAX   0x7ff
#define UTF_WIDTH3_MAX   0xffff
#define UTF_WIDTH4_MAX   0x10ffff
/** Maximum bytes per UTF character */
#define UTFmax   4


// LIMITS OF BASIC INTEGRAL DATATYPES

/** Maximum length of any multibyte character in any locale */
#define MB_LEN_MAX   16
/** @def SHRT_MIN
Minimum value a `signed short` can hold */
#ifdef __SHRT_MIN__
#   define SHRT_MIN   __SHRT_MIN__
#else
#   define SHRT_MIN   INT16_MIN
#   define __SHRT_MIN__   SHRT_MIN
#endif
/** @def SHRT_MAX
Maximum value a `signed short` can hold */
#ifdef __SHRT_MAX__
#   define SHRT_MAX   __SHRT_MAX__
#else
#   define SHRT_MAX   INT16_MAX
#   define __SHRT_MAX__   SHRT_MAX
#endif
/** Maximum value an `unsigned short` can hold (Minimum is 0) */
#define USHRT_MAX   UINT16_MAX
#define MINSHORT   SHRT_MIN
#define MAXSHORT   SHRT_MAX
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
#define ONE32   UINT32_MAX
/** @def LONG_MAX
Minimum and maximum values a `signed long` can hold */
#ifdef __LONG_MAX__
#   define LONG_MAX   __LONG_MAX__
#elif LONG_EQ_64BITS
#   define LONG_MAX   INT64_MAX
#   define __LONG_MAX__   LONG_MAX
#elif LONG_EQ_32BITS
#   define LONG_MAX   INT32_MAX
#   define __LONG_MAX__   LONG_MAX
#else
#   error   "Unable to define the limits of `long` for the target system!"
#endif
/** @def ULONG_MAX
Maximum value an `unsigned long` can hold (Minimum is 0) */
#if LONG_EQ_64BITS
#   define LONG_MIN   INT64_MIN
#   define ULONG_MAX   UINT64_MAX
#   define ABS_LONG_MIN   0x7fffffffffffffffUL
#elif LONG_EQ_32BITS
#   define LONG_MIN   INT32_MIN
#   define ULONG_MAX   UINT32_MAX
#   define ABS_LONG_MIN   2147483648UL
#endif
/** @def LONG_LONG_MAX
Maximum value a `signed long long` can hold */
#ifdef __LONG_LONG_MAX__
#   define LONG_LONG_MAX   __LONG_LONG_MAX__
#elif LLONG_EQ_64BITS
#   define LONG_LONG_MAX   INT64_MAX
#   define __LONG_LONG_MAX__   INT64_MAX
#elif LLONG_EQ_32BITS
#   define LONG_LONG_MAX   INT32_MAX
#   define __LONG_LONG_MAX__   INT32_MAX
#else
#   error   "Unable to define the limits of `long long` for the target system!"
#endif
/** @def LONG_LONG_MIN
Minimum value a `signed long long` can hold */
/** @def ULLONG_MAX
Maximum value an `unsigned long long` can hold (Minimum is 0) */
#if LLONG_EQ_64BITS
#   define LONG_LONG_MIN   INT64_MIN
#   define ULLONG_MAX   UINT64_MAX
#   define ABS_LONG_LONG_MIN   0x7fffffffffffffffULL
#elif LLONG_EQ_32BITS
#   define LONG_LONG_MIN   INT32_MIN
#   define ULLONG_MAX   UINT32_MAX
#   define ABS_LONG_LONG_MIN   2147483648ULL
#endif
/** Maximum value a `signed long long` can hold */
#define LLONG_MAX   LONG_LONG_MAX
#define LLONG_MIN   LONG_LONG_MIN
#define UNSIGNED_LONG_LONG_MAX   ULLONG_MAX
#define LONGLONG_MIN   LLONG_MIN
#define LONGLONG_MAX   LLONG_MAX
#define ULONGLONG_MAX   ULLONG_MAX
#define OFF_MAX   LLONG_MAX
#define OFF_MIN   LLONG_MIN
#define VLONG_MAX   LLONG_MAX
#define VLONG_MIN   LLONG_MIN
#define UVLONG_MAX   ULLONG_MAX
#define MINLONG   LONG_MIN
#define MAXLONG   LONG_MAX
#define STRTOL_T_MINIMUM   0
#define STRTOL_T_MAXIMUM   ULONG_MAX


// LIMITS OF `WCHAR_T`

#ifndef __WCHAR_MAX__
#   define __WCHAR_MAX__   INT_MAX
#endif
#ifndef __WCHAR_MAX
#   define __WCHAR_MAX   __WCHAR_MAX__
#endif
#ifndef WCHAR_MAX
#   define WCHAR_MAX   __WCHAR_MAX__
#endif
#ifndef __WCHAR_MIN__
#   define __WCHAR_MIN__   INT_MIN
#endif
#ifndef __WCHAR_MIN
#   define __WCHAR_MIN   __WCHAR_MIN__
#endif
#ifndef WCHAR_MIN
#   define WCHAR_MIN   __WCHAR_MIN__
#endif


// LIMITS OF `WINT_T`

#ifndef __WINT_MIN__
#   if IS_WINT_UNSIGNED
#      define __WINT_MIN__   0U
#   else
#      error   "Add wint_t support for your target platform."
#   endif
#endif
#ifndef __WINT_MIN
#   define __WINT_MIN   __WINT_MIN__
#endif
#ifndef WINT_MIN
#   define WINT_MIN   __WINT_MIN__
#endif
#ifndef __WINT_MAX__
#   define __WINT_MAX__   UINT_MAX
#endif
#ifndef __WINT_MAX
#   define __WINT_MAX   __WINT_MAX__
#endif
#ifndef WINT_MAX
#   define WINT_MAX   __WINT_MAX__
#endif


// LIMITS OF OTHER INTEGRAL DATATYPES

/** @def SIZE_MAX
Maximum value representable as type size_t */
#ifdef __SIZE_MAX__
#   define SIZE_MAX   __SIZE_MAX__
#elif SIZE_T_EQ_64BITS
#   define SIZE_MAX   UINT64_MAX
#else  // SIZE_T_EQ_32BITS
#   define SIZE_MAX   UINT32_MAX
#endif
#ifndef SIZE_T_MAX
#   define SIZE_T_MAX    SIZE_MAX
#endif
#ifndef __SIZE_MAX__
#   define __SIZE_MAX__    SIZE_MAX
#endif
/** @def SSIZE_MAX
Maximum value representable as type ssize_t */
#ifdef __SSIZE_MAX__
#   define SSIZE_MAX   __SSIZE_MAX__
#elif SIZE_T_EQ_64BITS
#   define SSIZE_MAX   INT64_MAX
#else  // SIZE_T_EQ_32BITS
#   define SSIZE_MAX   INT32_MAX
#endif
#ifndef SSIZE_T_MAX
#   define SSIZE_T_MAX    SSIZE_MAX
#endif
#ifndef __SSIZE_MAX__
#   define __SSIZE_MAX__    SSIZE_MAX
#endif
/** Largest value of a `ssize_t` */
#define _POSIX_SSIZE_MAX   SSIZE_MAX
/** @def SSIZE_MIN
Minimum value representable as type ssize_t */
#ifdef __SSIZE_MIN__
#   define SSIZE_MIN   __SSIZE_MIN__
#elif SIZE_T_EQ_64BITS
#   define SSIZE_MIN   INT64_MIN
#else  // SIZE_T_EQ_32BITS
#   define SSIZE_MIN   INT32_MIN
#endif
#ifndef SSIZE_T_MIN
#   define SSIZE_T_MIN    SSIZE_MIN
#endif
#ifndef __SSIZE_MIN__
#   define __SSIZE_MIN__    SSIZE_MIN
#endif
/** @def RSIZE_MAX
Maximum value representable as type rsize_t */
#ifndef RSIZE_MAX
#   define RSIZE_MAX   SIZE_MAX
#endif
/** @def __RSIZE_MAX__
Maximum value representable as type rsize_t */
#ifndef __RSIZE_MAX__
#   define __RSIZE_MAX__   RSIZE_MAX
#endif
/** @def PTRDIFF_MIN
Minimum value representable as type ptrdiff_t */
#ifdef __PTRDIFF_MIN__
#   define PTRDIFF_MIN   __PTRDIFF_MIN__
#elif PTR_EQ_64BITS
#   define PTRDIFF_MIN   INT64_MIN
#else
#   define PTRDIFF_MIN   INT32_MIN
#endif  // PTRDIFF_MIN
/** @def PTRDIFF_MAX
Maximum value representable as type ptrdiff_t */
#ifdef __PTRDIFF_MAX__
#   define PTRDIFF_MAX   __PTRDIFF_MAX__
#elif PTR_EQ_64BITS
#   define PTRDIFF_MAX   INT64_MAX
#else
#   define PTRDIFF_MAX   INT32_MAX
#endif  // PTRDIFF_MAX
/** @def SIG_ATOMIC_MIN
Minimum value representable as type sig_atomic_t */
#ifdef __SIG_ATOMIC_MIN__
#   define SIG_ATOMIC_MIN   __SIG_ATOMIC_MIN__
#else
#   define SIG_ATOMIC_MIN   INT32_MIN
#   define __SIG_ATOMIC_MIN__   INT32_MIN
#endif
/** @def SIG_ATOMIC_MAX
Maximum value representable as type sig_atomic_t */
#ifdef __SIG_ATOMIC_MAX__
#   define SIG_ATOMIC_MAX   __SIG_ATOMIC_MAX__
#else
#   define SIG_ATOMIC_MAX   INT32_MAX
#   define __SIG_ATOMIC_MAX__   INT32_MAX
#endif
#ifndef UID_MAX
#   define UID_MAX   UINT32_MAX
#endif
#ifndef GID_MAX
#   define GID_MAX   UINT32_MAX
#endif
#ifndef UQUAD_MAX
#   define UQUAD_MAX   UINT64_MAX
#endif
#ifndef QUAD_MAX
#   define QUAD_MAX   INT64_MAX
#endif
#ifndef QUAD_MIN
#   define QUAD_MIN   INT64_MIN
#endif
#define SIGEV_MAX_SIZE   64
#define SIGEV_PAD_SIZE   16
#if ((SIZE_MAX != ULONG_MAX) || (UINTMAX_MAX != ULLONG_MAX))
#   define ODD_TYPES   1
#   define HAS_ODD_TYPES   1
#else
#   define HAS_ODD_TYPES   0
#endif


// INTEGRAL LIMIT ALIASES

#define MININT   INT_MIN
#define MAXINT   INT_MAX
#define INT8_T_MAX   INT8_MAX
#define UINT8_T_MAX   UINT8_MAX
#define INT8_T_MIN   INT8_MIN
#define UINT8_T_MIN   0
#define INT16_T_MAX   INT16_MAX
#define UINT16_T_MAX   UINT16_MAX
#define INT16_T_MIN   INT16_MIN
#define UINT16_T_MIN   0
#define INT32_T_MAX   INT32_MAX
#define UINT32_T_MAX   UINT32_MAX
#define INT32_T_MIN   INT32_MIN
#define UINT32_T_MIN   0
#define INT64_T_MAX   INT64_MAX
#define UINT64_T_MAX   UINT64_MAX
#define INT64_T_MIN   INT64_MIN
#define UINT64_T_MIN   0
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


// FRACTIONAL DATATYPE LIMITS

#if SUPPORTS_STDFIX
#   ifdef __SFRACT_MIN__
#      define SFRACT_MIN   __SFRACT_MIN__
#   else
#      define __SFRACT_MIN__   -0.5HR-0.5HR
#      define SFRACT_MIN   __SFRACT_MIN__
#   endif
#   define INThr_MIN   SFRACT_MIN
#   ifdef __SFRACT_MAX__
#      define SFRACT_MAX   __SFRACT_MAX__
#   else
#      define __SFRACT_MAX__   0x7fP-7HR
#      define SFRACT_MAX   __SFRACT_MAX__
#   endif
#   define INThr_MAX   SFRACT_MAX
#   ifdef __SFRACT_EPSILON__
#      define SFRACT_EPSILON   __SFRACT_EPSILON__
#   else
#      define __SFRACT_EPSILON__   0x1P-7HR
#      define SFRACT_EPSILON   __SFRACT_EPSILON__
#   endif
#   ifdef __USFRACT_MIN__
#      define USFRACT_MIN   __USFRACT_MIN__
#   else
#      define __USFRACT_MIN__   0.0UHR
#      define USFRACT_MIN   __USFRACT_MIN__
#   endif
#   ifdef __USFRACT_MAX__
#      define USFRACT_MAX   __USFRACT_MAX__
#   else
#      define __USFRACT_MAX__   0xffP-8UHR
#      define USFRACT_MAX   __USFRACT_MAX__
#   endif
#   define INTuhr_MAX   USFRACT_MAX
#   ifdef __USFRACT_EPSILON__
#      define USFRACT_EPSILON   __USFRACT_EPSILON__
#   else
#      define __USFRACT_EPSILON__   0x1P-8UHR
#      define USFRACT_EPSILON   __USFRACT_EPSILON__
#   endif
#   ifdef __FRACT_MIN__
#      define FRACT_MIN   __FRACT_MIN__
#   else
#      define __FRACT_MIN__   -0.5R-0.5R
#      define FRACT_MIN   __FRACT_MIN__
#   endif
#   define INTr_MIN   FRACT_MIN
#   ifdef __FRACT_MAX__
#      define FRACT_MAX   __FRACT_MAX__
#   else
#      define __FRACT_MAX__   0x7fffP-15R
#      define FRACT_MAX   __FRACT_MAX__
#   endif
#   define INTr_MAX   FRACT_MAX
#   ifdef __FRACT_EPSILON__
#      define FRACT_EPSILON   __FRACT_EPSILON__
#   else
#      define __FRACT_EPSILON__   0x1P-15R
#      define FRACT_EPSILON   __FRACT_EPSILON__
#   endif
#   ifdef __UFRACT_MIN__
#      define UFRACT_MIN   __UFRACT_MIN__
#   else
#      define __UFRACT_MIN__   0.0UR
#      define UFRACT_MIN   __UFRACT_MIN__
#   endif
#   ifdef __UFRACT_MAX__
#      define UFRACT_MAX   __UFRACT_MAX__
#   else
#      define __UFRACT_MAX__   0xffffP-16UR
#      define UFRACT_MAX   __UFRACT_MAX__
#   endif
#   define INTur_MAX   UFRACT_MAX
#   ifdef __UFRACT_EPSILON__
#      define UFRACT_EPSILON   __UFRACT_EPSILON__
#   else
#      define __UFRACT_EPSILON__   0x1P-16UR
#      define UFRACT_EPSILON   __UFRACT_EPSILON__
#   endif
#   ifdef __LFRACT_MIN__
#      define LFRACT_MIN   __LFRACT_MIN__
#   else
#      define __LFRACT_MIN__   -0.5LR-0.5LR
#      define LFRACT_MIN   __LFRACT_MIN__
#   endif
#   define INTlr_MIN   LFRACT_MIN
#   ifdef __LFRACT_MAX__
#      define LFRACT_MAX   __LFRACT_MAX__
#   else
#      define __LFRACT_MAX__   0x7fffffffP-31LR
#      define LFRACT_MAX   __LFRACT_MAX__
#   endif
#   define INTlr_MAX   LFRACT_MAX
#   ifdef __LFRACT_EPSILON__
#      define LFRACT_EPSILON   __LFRACT_EPSILON__
#   else
#      define __LFRACT_EPSILON__   0x1P-31LR
#      define LFRACT_EPSILON   __LFRACT_EPSILON__
#   endif
#   ifdef __ULFRACT_MIN__
#      define ULFRACT_MIN   __ULFRACT_MIN__
#   else
#      define __ULFRACT_MIN__   0.0ULR
#      define ULFRACT_MIN   __ULFRACT_MIN__
#   endif
#   ifdef __ULFRACT_MAX__
#      define ULFRACT_MAX   __ULFRACT_MAX__
#   else
#      define __ULFRACT_MAX__   0xffffffffP-32ULR
#      define ULFRACT_MAX   __ULFRACT_MAX__
#   endif
#   define INTulr_MAX   ULFRACT_MAX
#   ifdef __ULFRACT_EPSILON__
#      define ULFRACT_EPSILON   __ULFRACT_EPSILON__
#   else
#      define __ULFRACT_EPSILON__   0x1P-32ULR
#      define ULFRACT_EPSILON   __ULFRACT_EPSILON__
#   endif
#   ifdef __LLFRACT_MIN__
#      define LLFRACT_MIN   __LLFRACT_MIN__
#   else
#      define __LLFRACT_MIN__   -0.5LLR-0.5LLR
#      define LLFRACT_MIN   __LLFRACT_MIN__
#   endif
#   define INTllr_MIN   LLFRACT_MIN
#   ifdef __LLFRACT_MAX__
#      define LLFRACT_MAX   __LLFRACT_MAX__
#   else
#      define __LLFRACT_MAX__   0x7fffffffffffffffP-63LLR
#      define LLFRACT_MAX   __LLFRACT_MAX__
#   endif
#   define INTllr_MAX   LLFRACT_MAX
#   ifdef __LLFRACT_EPSILON__
#      define LLFRACT_EPSILON   __LLFRACT_EPSILON__
#   else
#      define __LLFRACT_EPSILON__   0x1P-63LLR
#      define LLFRACT_EPSILON   __LLFRACT_EPSILON__
#   endif
#   ifdef __ULLFRACT_MIN__
#      define ULLFRACT_MIN   __ULLFRACT_MIN__
#   else
#      define __ULLFRACT_MIN__   0.0ULLR
#      define ULLFRACT_MIN   __ULLFRACT_MIN__
#   endif
#   ifdef __ULLFRACT_MAX__
#      define ULLFRACT_MAX   __ULLFRACT_MAX__
#   else
#      define __ULLFRACT_MAX__   0xffffffffffffffffP-64ULLR
#      define ULLFRACT_MAX   __ULLFRACT_MAX__
#   endif
#   define INTullr_MAX   ULLFRACT_MAX
#   ifdef __ULLFRACT_EPSILON__
#      define ULLFRACT_EPSILON   __ULLFRACT_EPSILON__
#   else
#      define __ULLFRACT_EPSILON__   0x1P-64ULLR
#      define ULLFRACT_EPSILON   __ULLFRACT_EPSILON__
#   endif
#endif


// ACCUMULATOR DATATYPE LIMITS

#if SUPPORTS_STDFIX
#   ifdef __SACCUM_MIN__
#      define SACCUM_MIN   __SACCUM_MIN__
#   else
#      define __SACCUM_MIN__   -0x1P7HK-0x1P7HK
#      define SACCUM_MIN   __SACCUM_MIN__
#   endif
#   define INThk_MIN   SACCUM_MIN
#   ifdef __SACCUM_MAX__
#      define SACCUM_MAX   __SACCUM_MAX__
#   else
#      define __SACCUM_MAX__   0x7fffP-7HK
#      define SACCUM_MAX   __SACCUM_MAX__
#   endif
#   define INThk_MAX   SACCUM_MAX
#   ifdef __SACCUM_EPSILON__
#      define SACCUM_EPSILON   __SACCUM_EPSILON__
#   else
#      define __SACCUM_EPSILON__   0x1P-7HK
#      define SACCUM_EPSILON   __SACCUM_EPSILON__
#   endif
#   ifdef __USACCUM_MIN__
#      define USACCUM_MIN   __USACCUM_MIN__
#   else
#      define __USACCUM_MIN__   0.0UHK
#      define USACCUM_MIN   __USACCUM_MIN__
#   endif
#   ifdef __USACCUM_MAX__
#      define USACCUM_MAX   __USACCUM_MAX__
#   else
#      define __USACCUM_MAX__   0xffffP-8UHK
#      define USACCUM_MAX   __USACCUM_MAX__
#   endif
#   define INTuhk_MAX   USACCUM_MAX
#   ifdef __USACCUM_EPSILON__
#      define USACCUM_EPSILON   __USACCUM_EPSILON__
#   else
#      define __USACCUM_EPSILON__   0x1P-8UHK
#      define USACCUM_EPSILON   __USACCUM_EPSILON__
#   endif
#   ifdef __ACCUM_MIN__
#      define ACCUM_MIN   __ACCUM_MIN__
#   else
#      define __ACCUM_MIN__   -0x1P15K-0x1P15K
#      define ACCUM_MIN   __ACCUM_MIN__
#   endif
#   define INTk_MIN   ACCUM_MIN
#   ifdef __ACCUM_MAX__
#      define ACCUM_MAX   __ACCUM_MAX__
#   else
#      define __ACCUM_MAX__   0x7fffffffP-15K
#      define ACCUM_MAX   __ACCUM_MAX__
#   endif
#   define INTk_MAX   ACCUM_MAX
#   ifdef __ACCUM_EPSILON__
#      define ACCUM_EPSILON   __ACCUM_EPSILON__
#   else
#      define __ACCUM_EPSILON__   0x1P-15K
#      define ACCUM_EPSILON   __ACCUM_EPSILON__
#   endif
#   ifdef __UACCUM_MIN__
#      define UACCUM_MIN   __UACCUM_MIN__
#   else
#      define __UACCUM_MIN__   0.0UK
#      define UACCUM_MIN   __UACCUM_MIN__
#   endif
#   ifdef __UACCUM_MAX__
#      define UACCUM_MAX   __UACCUM_MAX__
#   else
#      define __UACCUM_MAX__   0xffffffffP-16UK
#      define UACCUM_MAX   __UACCUM_MAX__
#   endif
#   define INTuk_MAX   UACCUM_MAX
#   ifdef __UACCUM_EPSILON__
#      define UACCUM_EPSILON   __UACCUM_EPSILON__
#   else
#      define __UACCUM_EPSILON__   0x1P-16UK
#      define UACCUM_EPSILON   __UACCUM_EPSILON__
#   endif
#   ifdef __LACCUM_MIN__
#      define LACCUM_MIN   __LACCUM_MIN__
#   else
#      define __LACCUM_MIN__   -0x1P31LK-0x1P31LK
#      define LACCUM_MIN   __LACCUM_MIN__
#   endif
#   define INTlk_MIN   LACCUM_MIN
#   ifdef __LACCUM_MAX__
#      define LACCUM_MAX   __LACCUM_MAX__
#   else
#      define __LACCUM_MAX__   0x7fffffffffffffffP-31LK
#      define LACCUM_MAX   __LACCUM_MAX__
#   endif
#   define INTlk_MAX   LACCUM_MAX
#   ifdef __LACCUM_EPSILON__
#      define LACCUM_EPSILON   __LACCUM_EPSILON__
#   else
#      define __LACCUM_EPSILON__   0x1P-31LK
#      define LACCUM_EPSILON   __LACCUM_EPSILON__
#   endif
#   ifdef __ULACCUM_MIN__
#      define ULACCUM_MIN   __ULACCUM_MIN__
#   else
#      define __ULACCUM_MIN__   0.0ULK
#      define ULACCUM_MIN   __ULACCUM_MIN__
#   endif
#   ifdef __ULACCUM_MAX__
#      define ULACCUM_MAX   __ULACCUM_MAX__
#   else
#      define __ULACCUM_MAX__   0xffffffffffffffffP-32ULK
#      define ULACCUM_MAX   __ULACCUM_MAX__
#   endif
#   define INTulk_MAX   ULACCUM_MAX
#   ifdef __ULACCUM_EPSILON__
#      define ULACCUM_EPSILON   __ULACCUM_EPSILON__
#   else
#      define __ULACCUM_EPSILON__   0x1P-32ULK
#      define ULACCUM_EPSILON   __ULACCUM_EPSILON__
#   endif
#   ifdef __LLACCUM_MIN__
#      define LLACCUM_MIN   __LLACCUM_MIN__
#   else
#      define __LLACCUM_MIN__   -0x1P31LLK-0x1P31LLK
#      define LLACCUM_MIN   __LLACCUM_MIN__
#   endif
#   define INTllk_MIN   LLACCUM_MIN
#   ifdef __LLACCUM_MAX__
#      define LLACCUM_MAX   __LLACCUM_MAX__
#   else
#      define __LLACCUM_MAX__   0x7fffffffffffffffP-31LLK
#      define LLACCUM_MAX   __LLACCUM_MAX__
#   endif
#   define INTllk_MAX   LLACCUM_MAX
#   ifdef __LLACCUM_EPSILON__
#      define LLACCUM_EPSILON   __LLACCUM_EPSILON__
#   else
#      define __LLACCUM_EPSILON__   0x1P-31LLK
#      define LLACCUM_EPSILON   __LLACCUM_EPSILON__
#   endif
#   ifdef __ULLACCUM_MIN__
#      define ULLACCUM_MIN   __ULLACCUM_MIN__
#   else
#      define __ULLACCUM_MIN__   0.0ULLK
#      define ULLACCUM_MIN   __ULLACCUM_MIN__
#   endif
#   ifdef __ULLACCUM_MAX__
#      define ULLACCUM_MAX   __ULLACCUM_MAX__
#   else
#      define __ULLACCUM_MAX__   0xffffffffffffffffP-32ULLK
#      define ULLACCUM_MAX   __ULLACCUM_MAX__
#   endif
#   define INTullk_MAX   ULLACCUM_MAX
#   ifdef __ULLACCUM_EPSILON__
#      define ULLACCUM_EPSILON   __ULLACCUM_EPSILON__
#   else
#      define __ULLACCUM_EPSILON__   0x1P-32ULLK
#      define ULLACCUM_EPSILON   __ULLACCUM_EPSILON__
#   endif
#endif


// INTEGER STRING BUFFER LIMITS

/** 3 digits + sign + NULL */
#define __UIM_BUFLEN_INT8   5
/** 3 digits + sign + NULL */
#define __UIM_BUFLEN_INT8_OCT   5
/** 2 digits + sign + NULL */
#define __UIM_BUFLEN_INT8_HEX   4
/** 3 digits + NULL */
#define __UIM_BUFLEN_UINT8   4
/** 3 digits + NULL */
#define __UIM_BUFLEN_UINT8_OCT   4
/** 2 digits + NULL */
#define __UIM_BUFLEN_UINT8_HEX   3
/** 3 digits + sign + NULL */
#define __UIM_BUFLEN_CHAR   5
/** 3 digits + sign + NULL */
#define __UIM_BUFLEN_CHAR_OCT   5
/** 2 digits + sign + NULL */
#define __UIM_BUFLEN_CHAR_HEX   4
/** 3 digits + NULL */
#define __UIM_BUFLEN_UCHAR   4
/** 3 digits + NULL */
#define __UIM_BUFLEN_UCHAR_OCT   4
/** 2 digits + NULL */
#define __UIM_BUFLEN_UCHAR_HEX   3
/** 5 digits + sign + NULL */
#define __UIM_BUFLEN_INT16   7
/** 6 digits + sign + NULL */
#define __UIM_BUFLEN_INT16_OCT   8
/** 4 digits + sign + NULL */
#define __UIM_BUFLEN_INT16_HEX   6
/** 5 digits + NULL */
#define __UIM_BUFLEN_UINT16   6
/** 6 digits + NULL */
#define __UIM_BUFLEN_UINT16_OCT   7
/** 4 digits + NULL */
#define __UIM_BUFLEN_UINT16_HEX   5
/** 5 digits + sign + NULL */
#define __UIM_BUFLEN_SHRT   7
/** 6 digits + sign + NULL */
#define __UIM_BUFLEN_SHRT_OCT   8
/** 4 digits + sign + NULL */
#define __UIM_BUFLEN_SHRT_HEX   6
/** 5 digits + NULL */
#define __UIM_BUFLEN_USHRT   6
/** 6 digits + NULL */
#define __UIM_BUFLEN_USHRT_OCT   7
/** 4 digits + NULL */
#define __UIM_BUFLEN_USHRT_HEX   5
/** 10 digits + sign + NULL */
#define __UIM_BUFLEN_INT32   12
/** 11 digits + sign + NULL */
#define __UIM_BUFLEN_INT32_OCT   13
/** 8 digits + sign + NULL */
#define __UIM_BUFLEN_INT32_HEX   10
/** 10 digits + NULL */
#define __UIM_BUFLEN_UINT32   11
/** 11 digits + NULL */
#define __UIM_BUFLEN_UINT32_OCT   12
/** 8 digits + NULL */
#define __UIM_BUFLEN_UINT32_HEX   9
/** 20 digits + sign + NULL */
#define __UIM_BUFLEN_INT64   22
/** 22 digits + sign + NULL */
#define __UIM_BUFLEN_INT64_OCT   24
/** 16 digits + sign + NULL */
#define __UIM_BUFLEN_INT64_HEX   18
/** 20 digits + NULL */
#define __UIM_BUFLEN_UINT64   21
/** 22 digits + NULL */
#define __UIM_BUFLEN_UINT64_OCT   23
/** 16 digits + NULL */
#define __UIM_BUFLEN_UINT64_HEX   17
#if (UINT_MAX == 4294967295UL)
#   define __UIM_BUFLEN_INT   12  // 10 digits + sign + NULL
#   define __UIM_BUFLEN_INT_OCT   __UIM_BUFLEN_INT32_OCT
#   define __UIM_BUFLEN_INT_HEX   __UIM_BUFLEN_INT32_HEX
#   define __UIM_BUFLEN_UINT   11  // 10 digits + NULL
#   define __UIM_BUFLEN_UINT_OCT   __UIM_BUFLEN_UINT32_OCT
#   define __UIM_BUFLEN_UINT_HEX   __UIM_BUFLEN_UINT32_HEX
#elif (UINT_MAX == 65535U)
#   define __UIM_BUFLEN_INT   7  // 5 digits + sign + NULL
#   define __UIM_BUFLEN_INT_OCT   __UIM_BUFLEN_SHRT_OCT
#   define __UIM_BUFLEN_INT_HEX   __UIM_BUFLEN_SHRT_HEX
#   define __UIM_BUFLEN_UINT   6  // 5 digits + NULL
#   define __UIM_BUFLEN_UINT_OCT   __UIM_BUFLEN_USHRT_OCT
#   define __UIM_BUFLEN_UINT_HEX   __UIM_BUFLEN_USHRT_HEX
#else
#   error   "Unknown number of digits for `int`!"
#endif
#if (ULONG_MAX == 18446744073709551615ULL)
#   define __UIM_BUFLEN_LONG   22  // 20 digits + sign + NULL
#   define __UIM_BUFLEN_LONG_OCT   __UIM_BUFLEN_INT64_OCT
#   define __UIM_BUFLEN_LONG_HEX   __UIM_BUFLEN_INT64_HEX
#   define __UIM_BUFLEN_ULONG   21  // 20 digits + NULL
#   define __UIM_BUFLEN_ULONG_OCT   __UIM_BUFLEN_UINT64_OCT
#   define __UIM_BUFLEN_ULONG_HEX   __UIM_BUFLEN_UINT64_HEX
#elif (ULONG_MAX == 4294967295UL)
#   define __UIM_BUFLEN_LONG   12  // 10 digits + sign + NULL
#   define __UIM_BUFLEN_LONG_OCT   __UIM_BUFLEN_INT32_OCT
#   define __UIM_BUFLEN_LONG_HEX   __UIM_BUFLEN_INT32_HEX
#   define __UIM_BUFLEN_ULONG   11  // 10 digits + NULL
#   define __UIM_BUFLEN_ULONG_OCT   __UIM_BUFLEN_UINT32_OCT
#   define __UIM_BUFLEN_ULONG_HEX   __UIM_BUFLEN_UINT32_HEX
#else
#   error   "Unknown number of digits for `long`!"
#endif
#if (ULLONG_MAX == 18446744073709551615ULL)
#   define __UIM_BUFLEN_LLONG   22  // 20 digits + sign + NULL
#   define __UIM_BUFLEN_LLONG_OCT   __UIM_BUFLEN_INT64_OCT
#   define __UIM_BUFLEN_LLONG_HEX   __UIM_BUFLEN_INT64_HEX
#   define __UIM_BUFLEN_ULLONG   21  // 20 digits + NULL
#   define __UIM_BUFLEN_ULLONG_OCT   __UIM_BUFLEN_UINT64_OCT
#   define __UIM_BUFLEN_ULLONG_HEX   __UIM_BUFLEN_UINT64_HEX
#elif (ULLONG_MAX == 4294967295ULL)
#   define __UIM_BUFLEN_LLONG   12  // 10 digits + sign + NULL
#   define __UIM_BUFLEN_LLONG_OCT   __UIM_BUFLEN_INT32_OCT
#   define __UIM_BUFLEN_LLONG_HEX   __UIM_BUFLEN_INT32_HEX
#   define __UIM_BUFLEN_ULLONG   11  // 10 digits + NULL
#   define __UIM_BUFLEN_ULLONG_OCT   __UIM_BUFLEN_UINT32_OCT
#   define __UIM_BUFLEN_ULLONG_HEX   __UIM_BUFLEN_UINT32_HEX
#else
#   error   "Unknown number of digits for `long long`!"
#endif
/** 39 digits + sign + NULL */
#define __UIM_BUFLEN_INT128   41
/** 39 digits + NULL */
#define __UIM_BUFLEN_UINT128   40
#if (SUPPORTS_INT128 && (INTMAX_MAX < INT64_MAX))  // 170141183460469231731687303715884105727i128
#   define __UIM_BUFLEN   41  // 39 digits + sign + NULL
#elif (INTMAX_MAX == 9223372036854775807LL)
#   define __UIM_BUFLEN   21  // 19 digits + sign + NULL
#elif (INTMAX_MAX == 2147483647L)
#   define __UIM_BUFLEN   12  // 10 digits + sign + NULL
#else
#   error   "Unknown number of digits for `intmax_t`!"
#endif


// WINDOWS LIMITS

/** Max path length in Windows */
#define MAX_PATH   260
#define WORD_MAX   USHRT_MAX
#define DWORD_MAX   UINT32_MAX
#define DWORDLONG_MAX   UINT64_MAX
#define ULONG64_MAX   UINT64_MAX
#define DWORD64_MAX   UINT64_MAX


#endif  // LIMITS_H


/* ISO646 ALTERNATIVE OPERATOR SPELLINGS (<iso646.h>) */


#if (!(defined(ISO646_H) || defined(_ISO646_H) || defined(_ISO646_H_)))  // http://www.cplusplus.com/reference/ciso646/ & http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/iso646.h.html
#define ISO646_H   (1)
#define _ISO646_H   (1)
#define _ISO646_H_   (1)


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


/* KEYWORDS */


#if (!(defined(KEYWORDS_H) || defined(_KEYWORDS_H_)))
#define KEYWORDS_H   (1)
#define _KEYWORDS_H_   (1)


#if ((!defined(SUPPORTS_ATTRIBUTES)) && (defined(__IBM_ATTRIBUTES) || IS_GNUC || defined(COMPILER_ILEC)))
#   define SUPPORTS_ATTRIBUTES   1
#elif (!defined(SUPPORTS_ATTRIBUTES))
#   define SUPPORTS_ATTRIBUTES   0
#endif
#if ((!defined(SUPPORTS_EXTENSION_KEYWORD)) && (defined(__IBM_EXTENSION_KEYWORD) || IS_GNUC || defined(COMPILER_ILEC)))
#   define SUPPORTS_EXTENSION_KEYWORD   1
#elif (!defined(SUPPORTS_EXTENSION_KEYWORD))
#   define SUPPORTS_EXTENSION_KEYWORD   0
#endif
#if ((!defined(SUPPORTS_HAS_INCLUDE)) && (IS_GNUC || IS_CPLUSPLUS_2017 || defined(COMPILER_MICROSOFT)))
#   define SUPPORTS_HAS_INCLUDE   1
#elif (!defined(SUPPORTS_HAS_INCLUDE))
#   define SUPPORTS_HAS_INCLUDE   0
#endif
#if ((!defined(SUPPORTS_INCLUDE_NEXT)) && (defined(__IBM_INCLUDE_NEXT) || IS_GNUC || defined(COMPILER_ILEC)))
#   define SUPPORTS_INCLUDE_NEXT   1
#elif (!defined(SUPPORTS_INCLUDE_NEXT))
#   define SUPPORTS_INCLUDE_NEXT   0
#endif
#if ((!defined(SUPPORTS_TYPEOF)) && (defined(__IBM_TYPEOF__) || IS_GNUC || defined(COMPILER_ILEC)))
#   define SUPPORTS_TYPEOF   1
#elif (!defined(SUPPORTS_TYPEOF))
#   define SUPPORTS_TYPEOF   0
#endif
#if ((!defined(SUPPORTS_VARIADIC_MACROS)) && (defined(__IBM_MACRO_WITH_VA_ARGS) || IS_GNUC || defined(COMPILER_ILEC)))
#   define SUPPORTS_VARIADIC_MACROS   1
#elif (!defined(SUPPORTS_VARIADIC_MACROS))
#   define SUPPORTS_VARIADIC_MACROS   0
#endif


// EXTENSION KEYWORD

#if (!SUPPORTS_EXTENSION_KEYWORD)
#   define __extension__
#endif
#define __GNU_EXTENSION   __extension__
#define __MINGW_EXTENSION   __extension__


// BASIC "DEFINED()" MACROS

/** Test if the symbol is not defined */
#define not_defined(x)   (!defined(x))
/** Test if the symbol is not defined */
#define ndefined(x)   not_defined(x)
/** Test if both symbols are not defined; returns false (or 0) if one or both symbols are defined */
#define neither_defined(x, y)   (!(defined(x) || defined(y)))
/** Test if one or both symbols are defined; returns false (or 0) if both symbols are not defined */
#define either_defined(x, y)   (defined(x) || defined(y))
/** Test if one or both symbols are defined; returns false (or 0) if both symbols are not defined */
#define any_defined(x, y)   either_defined(x, y)
/** Test if both symbols are defined; returns false (or 0) if both symbols are defined; returns true (or 1) if one or both symbols are not defined */
#define none_defined(x, y)   (!(defined(x) && defined(y)))


// INCLUDE MACROS

#define _STLP_MAKE_HEADER(path, _header)   <path/_header>
#define _STLP_NATIVE_INCLUDE_PATH   ../include
#define _STLP_NATIVE_C_INCLUDE_PATH   _STLP_NATIVE_INCLUDE_PATH
#define _STLP_NATIVE_CPP_C_INCLUDE_PATH   _STLP_NATIVE_INCLUDE_PATH
#define _STLP_NATIVE_CPP_RUNTIME_INCLUDE_PATH   _STLP_NATIVE_INCLUDE_PATH
#define _STLP_NATIVE_HEADER(_header)   _STLP_MAKE_HEADER(_STLP_NATIVE_INCLUDE_PATH, _header)
#define _STLP_NATIVE_C_HEADER(_header)   _STLP_NATIVE_HEADER(_header)
#define _STLP_NATIVE_CPP_C_HEADER(_header)   _STLP_NATIVE_HEADER(_header)
#define _STLP_NATIVE_CPP_RUNTIME_HEADER(_header)   _STLP_NATIVE_HEADER(_header)
#define STLP_NATIVE_CPP_RUNTIME_HEADER(_header)   _STLP_NATIVE_HEADER(_header)


// HAS_BUILTIN, HAS_INCLUDE, HAS_INCLUDE_NEXT, HAS_FEATURE, ETC.

/** @defgroup Has_Macros Macros pertaining to the many has_* macros functions
@{ */  // (FB){

#if (IS_NOT_GNUC && (!defined(__has_attribute)))
#   define __has_attribute(x)   0
#endif
#if ((!defined(COMPILER_CLANG)) && (!defined(__has_cpp_attribute)))
#   define __has_cpp_attribute(x)   0
#endif
#if ((!defined(COMPILER_CLANG)) && (!defined(__has_declspec_attribute)))
#   define __has_declspec_attribute(x)   0
#endif
#if (IS_NOT_GNUC && (!defined(__has_builtin)))
#   define __has_builtin(x)   0
#endif
#if ((!defined(COMPILER_CLANG)) && (!defined(__has_feature)))
#   define __has_feature(x)   0
#endif
#if (defined(COMPILER_CLANG) && (!defined(lacks_feature)))
#   define lacks_feature(x)   (!__has_feature(x))
#elif ((!defined(COMPILER_CLANG)) && (!defined(lacks_feature)))
#   define lacks_feature(x)   0
#endif
#if ((!defined(COMPILER_CLANG)) && (!defined(__has_extension)))
#   define __has_extension(x)   __has_feature(x)
#endif
#if ((!defined(COMPILER_CLANG)) && (!defined(__has_warning)))
#   define __has_warning(x)   0
#endif
#if ((!defined(COMPILER_CLANG)) && (!defined(__is_identifier)))
#   define __is_identifier(x)   0
#endif
#if ((!SUPPORTS_HAS_INCLUDE) && (!defined(__has_include)))
#   define __has_include(x)   0
#endif
#if (IS_NOT_GNUC && (!defined(__has_include_next)))
#   define __has_include_next(x)   0
#endif
#undef __musl_has_extension
#undef musl_has_extension
#define __musl_has_extension(x)   __has_extension(x)
#define musl_has_extension(x)   __has_extension(x)
#ifndef has_include
#   define has_include(x)    __has_include(x)
#endif
#ifndef has_include_next
#   define has_include_next(x)    __has_include_next(x)
#endif
#ifndef has_extension
#   define has_extension(x)   __has_extension(x)
#endif
#ifndef has_feature
#   define has_feature(x)   __has_feature(x)
#endif
#ifndef has_builtin
#   define has_builtin(x)   __has_builtin(x)
#endif

/** @} */  // }


// NULL

/** @defgroup NULL_Keyword The `NULL` keyword
@{ */  // (FB){

/** @def NULL
Void pointer */
#undef NULL
#if IS_CPLUSPLUS
#   define NULL   (0)
#else
#   define NULL   ((void*)0)
#endif
#ifndef _NULL
/** Alias for NULL; Void pointer */
#   define _NULL   NULL
#endif
#ifndef __null
/** Alias for NULL; Void pointer */
#   define __null   NULL
#endif
#ifndef __null__
/** Alias for NULL; Void pointer */
#   define __null__   NULL
#endif
#ifndef NIL
/** Alias for NULL; Void pointer */
#   define NIL   NULL
#endif
#ifndef nil
/** Alias for NULL; Void pointer */
#   define nil   NULL
#endif
#ifndef STMT_NIL
/** Expands to a syntactically valid empty statement */
#   define STMT_NIL   ((void)0)
#endif
/** Alias for NULL; Void pointer */
#define __eh_pc_gcc_272   NULL
/** Alias for NULL; Void pointer */
#define __eh_type_gcc_272   NULL
/** Alias for NULL; Void pointer */
#define __eh_value_gcc_272   NULL
/** Alias for NULL; Void pointer; This is what egcs uses for its global data pointer */
#define __eh_global_dataptr   NULL

/** @} */  // }


// NULL POINTERS

/** @defgroup Null_Pointers Macros for various `NULL` pointers
@{ */  // (FB){

#if IS_CPLUSPLUS_2011
#   ifndef _GXX_NULLPTR_T
#      define _GXX_NULLPTR_T
typedef decltype(nullptr)   nullptr_t;
#   endif
#endif
#if IS_NOT_CPLUSPLUS
// Basic datatype NULL pointers
/** NULL char pointer */
#   define NULL_CHAR   ((char*)0)
/** NULL signed char pointer */
#   define NULL_SCHAR   ((signed char*)0)
/** NULL unsigned char pointer */
#   define NULL_UCHAR   ((unsigned char*)0)
/** NULL short pointer */
#   define NULL_SHORT   ((short*)0)
/** NULL unsigned short pointer */
#   define NULL_USHORT   ((unsigned short*)0)
/** NULL int pointer */
#   define NULL_INT   ((int*)0)
/** NULL unsigned int pointer */
#   define NULL_UINT   ((unsigned int*)0)
/** NULL long pointer */
#   define NULL_LONG   ((long*)0)
/** NULL unsigned long pointer */
#   define NULL_ULONG   ((unsigned long*)0)
/** NULL long long pointer */
#   define NULL_LLONG   ((long long*)0)
/** NULL unsigned long long pointer */
#   define NULL_ULLONG   ((unsigned long long*)0)
// Fixed-width datatype NULL pointers
/** NULL int8_t pointer */
#   define NULL_INT8   ((int8_t*)0)
/** NULL int16_t pointer */
#   define NULL_INT16   ((int16_t*)0)
/** NULL int32_t pointer */
#   define NULL_INT32   ((int32_t*)0)
/** NULL int64_t pointer */
#   define NULL_INT64   ((int64_t*)0)
/** NULL uint8_t pointer */
#   define NULL_UINT8   ((uint8_t*)0)
/** NULL uint16_t pointer */
#   define NULL_UINT16   ((uint16_t*)0)
/** NULL uint32_t pointer */
#   define NULL_UINT32   ((uint32_t*)0)
/** NULL uint64_t pointer */
#   define NULL_UINT64   ((uint64_t*)0)
#   if SUPPORTS_INT128
/** NULL int128_t pointer */
#      define NULL_INT128   ((int128_t*)0)
/** NULL uint128_t pointer */
#      define NULL_UINT128   ((uint128_t*)0)
#   endif
// Float-point datatype NULL pointers
/** NULL float pointer */
#   define NULL_FLT   ((float*)0)
/** NULL double pointer */
#   define NULL_DBL   ((double*)0)
#   if SUPPORTS_LONG_DOUBLE
/** NULL long double pointer */
#      define NULL_LDOUBLE   ((long double*)0)
#   endif
#   if SUPPORTS_FLOAT128
/** NULL float128 pointer */
#      define NULL_FLT128   ((float128*)0)
#   endif
#   if SUPPORTS_DECIMAL_FLOATS
/** NULL decimal32 pointer */
#      define NULL_DEC32   ((decimal32*)0)
/** NULL decimal64 pointer */
#      define NULL_DEC64   ((decimal64*)0)
#      if SUPPORTS_DECIMAL128
/** NULL decimal128 pointer */
#         define NULL_DEC128   ((decimal128*)0)
#      endif
#   endif  // SUPPORTS_DECIMAL_FLOATS
// Miscellaneous datatype NULL pointers
/** NULL size_t pointer */
#   define NULL_SIZET   ((size_t*)0)
#endif  // IS_NOT_CPLUSPLUS

/** @} */  // }


// NULL, NIL, & VOID MACROS STATEMENTS

#define PTR   void*
/** Expands to a syntactically valid empty statement, explicitly voiding its argument */
#define STMT_VOID(x)   while (0x0) { (void)(x); }
/** @def STMT_BEGIN
STMT_BEGIN is used to wrap blocks inside macros so that the macro can be used as if it were a single C statement */
/** @def STMT_END
STMT_END is used to wrap blocks inside macros so that the macro can be used as if it were a single C statement */
#if SUPPORTS_EXTENSION_KEYWORD
#   define STMT_BEGIN   __extension__ ({
#   define STMT_END   })
#elif (defined(OSSUN) || defined(OSSOLARIS))  // Solaris & Other Sun-Systems
#   define STMT_BEGIN   if (0x1) {
#   define STMT_END   } else STMT_NIL
#else
#   define STMT_BEGIN   do {
#   define STMT_END   } while (0x0)
#endif
#define __statement(x)   STMT_BEGIN (x) STMT_END
/** Test if the character is non-null */
#define IS_NONNUL(c)   ((c) != '\0')
/** Test if the wide character is non-null */
#define IS_WNONNUL(c)   ((c) != L'\0')


// ATTRIBUTE & DECLSPEC KEYWORDS

/** @defgroup Attribute_Keyword Macros pertaining to the `attribute` & `declspec` keywords
@{ */  // (FB){

#ifdef COMPILER_MICROSOFT
#   define __attribute__(x)   __declspec((x))
#   define declspec(x)   __declspec((x))
#elif SUPPORTS_ATTRIBUTES
#   define __declspec(x)   __attribute__((x))
#   define declspec(x)   __attribute__((x))
#else
#   define __attribute__(x)
#   define __declspec(x)
#   define declspec(x)
#endif

/** @} */  // }


// STATIC_ASSERT KEYWORD

/** @defgroup Static_Assert_Keyword Macros pertaining to the `static_assert` keyword
@{ */  // (FB){

/** @def static_assert
Compile-time assertion */
#if IS_NOT_LINTER
#   define static_assert(expr, msg)   _Static_assert((expr), msg)
#   define _FP_STATIC_ASSERT(expr, msg)   _Static_assert((expr), msg)
#else
#   define static_assert(expr, msg)
#   define _FP_STATIC_ASSERT(expr, msg)
#endif

/** @} */  // }


// THREAD_LOCAL STORAGE KEYWORD

/** @defgroup Thread_Local_Keyword Macros pertaining to the `thread_local` keyword
@{ */  // (FB){

#if IS_CPLUSPLUS
#   define __thread   thread_local
#else  // C
#   define thread_local   __thread
#endif
/** Alias for "thread_local" on systems that lack "_Thread_local" */
#define _Thread_local   thread_local
#define Thread_local   thread_local
#define _TLS_QUAL   thread_local

/** @} */  // }


// AUTO_TYPE KEYWORD

/** @defgroup Auto_Type_Keyword Macros pertaining to the `auto_type` keyword
@{ */  // (FB){

#if IS_GNUC
#   define auto_type   __auto_type
#elif IS_CPLUSPLUS_2011
#   define auto_type   auto
#else
#   define auto_type
#endif
#define auto_t   auto_type
#define __auto_type__   auto_type

/** @} */  // }


// ATOMIC TYPE QUALIFIER KEYWORD

/** @defgroup Atomic_Keyword Macros pertaining to the `atomic` keyword
@{ */  // (FB){

#if IS_LINTER
#   define _Atomic
#elif (IS_NOT_CPLUSPLUS && IS_STDC_BELOW_C11)
#   define _Atomic   __attribute__((__atomic__))
#endif
#if IS_NOT_LINTER
#   define Atomic   _Atomic
#   define atomic   _Atomic
#   define _atomic   _Atomic
#else
#   define Atomic
#   define atomic
#   define _atomic
#endif

#ifdef NO_ATOMIC
#   define Atomic
#   define atomic
#   define _atomic
#endif

/** @} */  // }


// CONST KEYWORD

/** @defgroup Const_Keyword Macros pertaining to the `const` keyword
@{ */  // (FB){

#ifdef NO_CONST
#   define const
#endif

/** @} */  // }


// RESTRICT TYPE QUALIFIER KEYWORD

/** @defgroup Restrict_Keyword Macros pertaining to the `restrict` keyword
@{ */  // (FB){

#ifdef NO_RESTRICT
#   define restrict
#   define __restrict
#   define __restrict__
#elif IS_GNUC
#   define restrict   __restrict__
#   define __restrict   __restrict__
#elif defined(LINTER_LINT)
#   define restrict   /*@unique@*/
#   define __restrict__   /*@unique@*/
#   define __restrict   /*@unique@*/
#elif (defined(OSWIN32) && defined(COMPILER_MICROSOFT))  // As of MSVC 2013, restrict is supported with a non-standard keyword
#   define restrict   __restrict
#   define __restrict__   __restrict
#elif IS_STDC99
#   define __restrict__   restrict
#   define __restrict   restrict
#endif
#define _Restrict   restrict

/** @} */  // }


// VOLATILE TYPE QUALIFIER KEYWORD

#if IS_ANSI
#   define __volatile    __volatile__
#   define volatile    __volatile__
#endif


// ASM KEYWORD

/** @defgroup Asm_Keyword Macros pertaining to the `asm` keyword
@{ */  // (FB){

#if IS_LINTER
#   define asm    /*@i@*/  //
#   define __asm__    /*@i@*/  //
#elif IS_NOT_GNUC
#   define __asm__    asm
#elif IS_GNUC
#   define asm    __asm__
#endif
#define __asm    asm
#if IS_LINTER
#   define vasm(...)    /*@i@*/  //
#else
#   define vasm(...)   asm volatile (__VA_ARGS__)
#endif
#ifndef __USER_LABEL_PREFIX__
#   define __USER_LABEL_PREFIX__   _
#endif
#ifndef USER_LABEL_PREFIX
#   define USER_LABEL_PREFIX   __USER_LABEL_PREFIX__
#endif
#ifdef __REGISTER_PREFIX__
#   define __REG_PREFIX__   __REGISTER_PREFIX__
#else
/** Assembly register prefix */
#   define __REG_PREFIX__   %%
/** Assembly register prefix */
#   define __REGISTER_PREFIX__   %%
#endif
#ifndef __SYMBOL_PREFIX
#   define __SYMBOL_PREFIX
#endif
#ifndef C_SYMBOL_NAME
#   define C_SYMBOL_NAME(name)   name
#endif
#ifdef HAVE_SECTION_QUOTES
#   define __sec_comment   "\"\n\t#\""
#else
#   define __sec_comment   "\n\t#"
#endif
#ifndef MODULE_NAME
#   define MODULE_NAME   "libc"
#endif
/** The symbol used to separate assembly commands */
#define ASM_LINE_SEP   ;
#define __CLOBBER_CC   : "cc"
#define CLOBBER_CC   : "cc"
#define __AND_CLOBBER_CC   , "cc"
#define AND_CLOBBER_CC   , "cc"
#define ASM_GLOBAL_DIRECTIVE   .global
/** Use the correct prefix for global labels */
#define SYM(sym)   CONCAT(__USER_LABEL_PREFIX__, sym)
/** Use the correct prefix for registers */
#define REG(sym)   CONCAT(__REG_PREFIX__, sym)
#define __ASMNAME2(prefix, sym)   __STRING(prefix) sym
#define __ASMNAME(sym)   __ASMNAME2(__USER_LABEL_PREFIX__, sym)
#define __REDIRECT(sym, proto, aliasname)   sym proto asm (__ASMNAME(#aliasname))
#if IS_CPLUSPLUS
#   define __REDIRECT_NTH(sym, proto, aliasname)   sym proto __THROW asm (__ASMNAME(#aliasname))
#   define __REDIRECT_NTHNL(sym, proto, aliasname)   sym proto __THROWNL asm (__ASMNAME(#aliasname))
#else
#   define __REDIRECT_NTH(sym, proto, aliasname)   sym proto asm (__ASMNAME(#aliasname)) __THROW
#   define __REDIRECT_NTHNL(sym, proto, aliasname)    sym proto asm (__ASMNAME(#aliasname)) __THROWNL
#endif

/** @} */  // }


// SIZEOF KEYWORD & MACROS

/** @defgroup Sizeof_Keyword Macros pertaining to the `sizeof` keyword
@{ */  // (FB){

/** The type of sizeof may be (unsigned) long on some systems; Use the following macro for getting datatype sizes when expecting sizeof to return an int */
#define usizeof(datatype)   ((unsigned)sizeof(datatype))
#define __sizeof__(OBJECT)   sizeof((OBJECT))
#define __sizeof(OBJECT)   sizeof((OBJECT))
#define _sizeof(OBJECT)   sizeof((OBJECT))
/** Return the number of bits used by the given datatype */
#define _TYPEBITS(datatype)   (sizeof(datatype) * NBBY)
/** Return the number of bits used by the given datatype */
#define TYPEBITS(datatype)   _TYPEBITS(datatype)
/** Return the number of bits used by the given datatype */
#define TYPE_BIT(datatype)   _TYPEBITS(datatype)
/** Calculate the minimum signed integer value that can be represented with the given data */
#define __type_min_s(t)   ((t)((t)1 << ((sizeof(t) * NBBY) - 1)))
/** Calculate the minimum signed integer value that can be represented with the given data */
#define type_min_s(t)   __type_min_s(t)
/** Calculate the maximum signed integer value that can be represented with the given data */
#define __type_max_s(t)   ((((t)1 << (sizeof(t) * NBBY - 2)) - 1) * 2 + 1)
/** Calculate the maximum signed integer value that can be represented with the given data */
#define type_max_s(t)   __type_max_s(t)
/** Calculate the minimum unsigned integer value that can be represented with the given data */
#define __type_min_u(t)   (0)
/** Calculate the minimum unsigned integer value that can be represented with the given data */
#define type_min_u(t)   (0)
/** Calculate the maximum unsigned integer value that can be represented with the given data */
#define __type_max_u(t)   ((t)~(t)0)
/** Calculate the maximum unsigned integer value that can be represented with the given data */
#define type_max_u(t)   __type_max_u(t)
/** Test if the given data is signed */
#define issigned(t)   (((t) <= 0 && (t) != 0) || ((t) == 0 && ((~(t)) < 8)) || ((-(t)) < ((t) * 0)))
/** Test if the given datatype is signed */
#define __type_is_signed(t)   (((t)(-1)) < ((t)4))
/** Test if the given datatype is signed */
#define type_is_signed(t)   __type_is_signed(t)
/** Return true if the datatype is signed */
#define TYPE_SIGNED(t)   __type_is_signed(t)
/** Calculate the minimum integer value that can be represented with the given datatype */
#define __type_min(t)   (__type_is_signed(t) ? __type_min_s(t) : (t)0)
/** Calculate the minimum integer value that can be represented with the given datatype */
#define type_min(t)   __type_min(t)
/** Calculate the maximum integer value that can be represented with the given datatype */
#define __type_max(t)   (__type_is_signed(t) ? __type_max_s(t) : ((t)~((t)0)))
/** Calculate the maximum integer value that can be represented with the given datatype */
#define type_max(t)   __type_max(t)
/** Test if the given datatype is a native datatype (by size) */
#define __native_word(t)   (sizeof(t) == SIZEOF_CHAR || sizeof(t) == SIZEOF_SHORT || sizeof(t) == SIZEOF_INT || sizeof(t) == SIZEOF_LONG || sizeof(t) == SIZEOF_LONG_LONG)
/** Test if the given datatype is a native datatype (by size) */
#define is_native_word(x)   __native_word(x)
#define __type_mask(t)   ((sizeof(t) < SIZEOF_INTMAX_T) ? (~((1ULL << (sizeof(t) * NBBY)) - 1)) : 0ULL)
#define type_mask(t)   __type_mask(t)
/** Return the length of a constant string */
#define constant_strlen(x)   (sizeof(x) - sizeof(""))
/** Return the length of a constant string */
#define CONSTANT_STRLEN(x)   (sizeof(x) - sizeof(""))
/** Return the length of a constant wide-string */
#define constant_wstrlen(x)   (sizeof(x) - sizeof(L""))
/** Return the length of a constant wide-string */
#define CONSTANT_WSTRLEN(x)   (sizeof(x) - sizeof(L""))
/** Return the length of a constant unicode string */
#define constant_ustrlen(x)   (sizeof(x) - sizeof(U""))
/** Return the length of a constant unicode string */
#define CONSTANT_USTRLEN(x)   (sizeof(x) - sizeof(U""))

// ARRAY SIZES

#define ARRAYLEN(arrayname)   ((sizeof(arrayname) / sizeof(*arrayname)))
#define ARRAYITEMSIZE(arrayname)   sizeof(*arrayname)
/** Return the size of a statically-allocated array */
#define GETARRAYSIZE(arrayname)   sizeof(arrayname)
/** Return the number of items in a statically-allocated array */
#define __arraycount(arrayname)   (sizeof(arrayname) / sizeof(arrayname[0]))
#ifndef nitems
/** Return the number of items in a statically-allocated array */
#   define nitems(arrayname)   __arraycount(arrayname)
#endif
/** Return the number of items in a statically-allocated array */
#define nelem(x)   __arraycount(arrayname)

/** @} */  // }


// TYPEOF KEYWORD

/** @defgroup Typeof_Keyword Macros pertaining to the `typeof` keyword
@{ */  // (FB){

#if SUPPORTS_TYPEOF
#   define typeof(OBJECT)   __typeof__(OBJECT)
#   define __typeof(OBJECT)   __typeof__(OBJECT)
#elif IS_NOT_GNUC
#   define __typeof__(OBJECT)   typeof(OBJECT)
#   define __typeof(OBJECT)   typeof(OBJECT)
#else
#   define __typeof__(OBJECT)
#   define __typeof(OBJECT)
#   define typeof(OBJECT)
#endif
#define _typeof(OBJECT)   __typeof(OBJECT)
/** Alias for "typeof" */
#define GetType(OBJECT)   typeof(OBJECT)
/** `1` if 'type' is a pointer type, `0` otherwise */
#define __pointer_type(type)   (__builtin_classify_type((type)0) == 5)
/** `1` if 'type' is a pointer type, `0` otherwise */
#define pointer_type(type)   __pointer_type(type)
/** `1` if 'data' is a pointer type, `0` otherwise */
#define is_pointer(data)   (__builtin_classify_type(data) == 5)
/** `1` if 'data' is an array, `0` otherwise */
#define is_array(data)   (__builtin_classify_type(data) == array_type_class)
/** `1` if 'data' is an union, `0` otherwise */
#define is_union(data)   (__builtin_classify_type(data) == union_type_class)
/** Test if the value is negative */
#define __negative_p(x)   ((x) < 0)
/** Test if the value is negative */
#define is_negative(x)   ((x) < 0)
/** Test if the value is positive */
#define is_positive(x)   ((x) >= 0)
/** Return true if value 'a' fits in the unsigned type 't' */
#define __type_fit_u(t, a)   (is_positive(a) && (__UINTMAX_TYPE__)((unsigned long long)(a) + __zeroull()) <= (__UINTMAX_TYPE__)__type_max_u(t))
/** Return true if value 'a' fits in the signed type 't' */
#define __type_fit_s(t, a)   (is_negative(a) ? ((__INTMAX_TYPE__)((a) + __zeroll()) >= (__INTMAX_TYPE__)__type_min_s(t)) : ((__INTMAX_TYPE__)((a) + __zeroll()) >= (__INTMAX_TYPE__)0 && (__INTMAX_TYPE__)((a) + __zeroll()) <= (__INTMAX_TYPE__)__type_max_s(t)))
/** Return true if value 'a' fits in type 't' */
#define __type_fit(t, a)   (__type_is_signed(t) ? __type_fit_s(t, a) : __type_fit_u(t, a))

/** @} */  // }


// INLINE, FORCEINLINE, EXTERN_INLINE, & RELATED INLINE ATTRIBUTES

/** @defgroup Inline_Attributes Attributes controlling the inlining of code
@{ */  // (FB){

#if (defined(OSWINDOWS) && defined(COMPILER_MICROSOFT))  // inline & forceinline
// As of MSVC 2013, inline and restrict are supported with non-standard keywords
#   ifndef inline
#      define inline   __inline
#   endif
/** Alias for "inline" on systems that lack "__forceinline" */
#   define __forceinline    inline
#else
#   ifndef __inline
/** Alias for "inline" on systems that lack "__inline" */
#      define __inline    inline
#   endif
#   ifndef __forceinline
#      if IS_GNUC
/** Alias for "inline" on systems that lack "__forceinline" */
#         define __forceinline    inline __attribute__((__always_inline__))
#      else
/** Alias for "inline" on systems that lack "__forceinline" */
#         define __forceinline    inline
#      endif  // IS_GNUC
#   endif  // __forceinline
#endif  // inline & forceinline
#ifndef INLINE
/** Alias for "inline" on systems that lack "INLINE" */
#   define INLINE   inline
#endif
#ifndef __inline__
/** Alias for "inline" on systems that lack "__inline__" */
#   define __inline__    inline
#endif
#ifndef forceinline
/** Alias for "__forceinline" on systems that lack "forceinline" */
#   define forceinline   __forceinline
#endif
#ifndef __always_inline
/** Alias for "__forceinline" on systems that lack "__always_inline" */
#   define __always_inline   __forceinline
#endif
#ifndef __header_always_inline
/** Alias for "__forceinline" on systems that lack "__header_always_inline" */
#   define __header_always_inline   __forceinline
#endif
#ifndef header_always_inline
/** Alias for "__forceinline" on systems that lack "header_always_inline" */
#   define header_always_inline   __forceinline
#endif
#ifndef __header_inline
#   define __header_inline   inline
#endif
#if IS_GNUC  // noinline
/** Do not inline function */
#   define __noinline   __attribute__((__noinline__))
#else
#   define __noinline
#endif
#define DECLSPEC_NOINLINE   __noinline
#define _NOINLINE   __noinline
#ifndef noinline
/** Do not inline function */
#   define noinline   __noinline
#endif
/** Do not inline static function */
#define NOINLINE_STATIC   noinline static
#if (IS_GNUC && ((defined(__GNUC_STDC_INLINE__) && (__GNUC_STDC_INLINE__ > 0)) || (defined(__GNUC_GNU_INLINE__) && (__GNUC_GNU_INLINE__ > 0))))  // __c99inline
/** Non-static C99 inline functions are optional bodies; They do not create global symbols if not used, but can be replaced if desirable */
#   define __c99inline   extern __attribute__((__gnu_inline__)) inline
#elif IS_GNUC
/** Non-static C99 inline functions are optional bodies; They do not create global symbols if not used, but can be replaced if desirable */
#   define __c99inline   extern inline
#elif defined(__STDC_VERSION__)
/** Non-static C99 inline functions are optional bodies; They do not create global symbols if not used, but can be replaced if desirable */
#   define __c99inline   inline
#else
/** Non-static C99 inline functions are optional bodies; They do not create global symbols if not used, but can be replaced if desirable */
#   define __c99inline
#endif  // __c99inline
#if IS_GNUC
#   define __gnu_inline   __attribute__((__gnu_inline__))
#else
#   define __gnu_inline
#endif
#define __BIONIC_FORTIFY_INLINE   __c99inline
#ifndef __ATOMIC_INLINE__
#   define __ATOMIC_INLINE__   static forceinline
#endif
/** Alias for "extern inline" */
#define extern_inline   __c99inline
/** Similar to "extern inline", but always inline */
#define extern_always_inline   extern __always_inline
#ifndef _EXTERN_INLINE
/** Alias for "extern inline" */
#   define _EXTERN_INLINE   extern_inline
#endif
#define __static_inline   static inline __gnu_inline
#ifndef static_inline
#   define static_inline   __static_inline
#endif
#if IS_GNUC  // __must_inline
#   define __must_inline   extern inline __attribute__((__always_inline__))
#else
#   define __must_inline   inline
#endif
#define must_inline   __must_inline
#if (IS_GNUC && ((!defined(__GNUC_STDC_INLINE__)) || (__GNUC_STDC_INLINE__ == 0)))  // ELIDABLE_INLINE
#   define ELIDABLE_INLINE   extern inline __attribute__((__always_inline__))
#else
#   define ELIDABLE_INLINE   static inline
#endif  // ELIDABLE_INLINE
#if IS_CPLUSPLUS
#   define __MATH_INLINE   inline
#else
#   define __MATH_INLINE   extern inline
#endif

/** @} */  // }


// C++ MACROS

/** @defgroup CPP_Macros Macros for various C++ keywords
@{ */  // (FB){

#undef __P
#if (defined(__STDC__) || IS_CPLUSPLUS)
/** Handle function prototypes (ANSI C or K&R C) */
#   define __P(protos)   protos  // ANSI C prototypes
#else
/** Handle function prototypes (ANSI C or K&R C) */
#   define __P(protos)   ()  // K&R C preprocessor
#endif
#ifdef __v810__
#   define const
#endif
// Support ANSI and non-ANSI environments (<_ansi.h>)
#if _HAVE_STDC
#   define _PTR   void*
#   define _AND    ,
#   define _NOARGS   void
#   define _CONST   const
#   define _VOLATILE   volatile
#   define _SIGNED   signed
#   define _DOTS   , ...
#   define _VOID   void
#   define __const   const
#   define __signed   signed
#   ifndef __volatile
#      define __volatile   volatile
#   endif
#   if ((IS_CPLUSPLUS || defined(COMPILER_PCC)) && (!defined(__inline)))
#      define __inline   inline
#   elif (IS_NOT_GNUC && (!defined(__inline)))
#      define __inline
#   endif
#   define _DEFUN(name, arglist, args)   name(args)
#   define _DEFUN_VOID(name)   name(_NOARGS)
#   define _CAST_VOID   (void)
#   ifndef _PARAMS
#      define _PARAMS(paramlist)    paramlist
#   endif
#else  // Not _HAVE_STDC
#   if IS_NOT_GNUC
#      ifndef __const
#         define __const
#      endif
#      ifndef __inline
#         define __inline
#      endif
#      ifndef __signed
#         define __signed
#      endif
#      ifndef __volatile
#         define __volatile
#      endif
#   elif (!defined(NO_ANSI_KEYWORDS))
#      define const   __const
#      define inline   __inline
#      define signed   __signed
#      define volatile   __volatile
#   endif
#   define _PTR   char*
#   define _AND   ;
#   define _NOARGS
#   define _CONST
#   define _VOLATILE
#   define _SIGNED
#   define _DOTS
#   define _VOID   void
#   define _EXFUN(name, proto)   name()
#   define _EXFUN_NOTHROW(name, proto)   name()
#   define _DEFUN(name, arglist, args)   name arglist args;
#   define _DEFUN_VOID(name)   name()
#   define _CAST_VOID
#   ifndef _PARAMS
#      define _PARAMS(paramlist)
#   endif
#endif  // ANSI
#ifndef CONSTANT
#   define CONSTANT   const
#endif
#ifndef CONST
#   define CONST   const
#endif
#ifndef __writeonly
#   define __writeonly   const
#endif
#ifndef __gmp_const
#   define __gmp_const   const
#endif
#define tSCC   static const char
#define tCC   const char
#define tSC   static char
#ifdef LINTER_AUDIT
/** Used for internal auditing of the NetBSD source tree */
#   define __aconst   const
#else
/** Used for internal auditing of the NetBSD source tree */
#   define __aconst
#endif
#ifndef aconst
/** Used for internal auditing of the NetBSD source tree */
#   define aconst   __aconst
#endif
#if IS_NOT_CPLUSPLUS
#   define __static_cast(x, y)   (x)y
#   define __CAST(__dt, __st)   ((__dt)(__st))
/** Perform the declaration with C linkage */
#   define _GL_EXTERN_C
#   ifndef __BEGIN_DECLS
#      define __BEGIN_DECLS
#   endif
#   ifndef __END_DECLS
#      define __END_DECLS
#   endif
#   ifndef __BEGIN_EXTERN_C
#      define __BEGIN_EXTERN_C
#   endif
#   ifndef __END_EXTERN_C
#      define __END_EXTERN_C
#   endif
#   define __BEGIN_NAMESPACE_STD
#   define __END_NAMESPACE_STD
#   define __USING_NAMESPACE_STD(name)
#   define __BEGIN_NAMESPACE_C99
#   define __END_NAMESPACE_C99
#   define __USING_NAMESPACE_C99(name)
#else  // C++ needs to know that types and declarations are C, not C++
#   define __static_cast(x, y)   static_cast<x>(y)
#   define __CAST(__dt, __st)   static_cast<__dt>(__st)
/** Perform the declaration with C linkage */
#   define _GL_EXTERN_C   extern "C"
#   ifndef __BEGIN_DECLS
#      define __BEGIN_DECLS   extern "C" {
#   endif
#   ifndef __END_DECLS
#      define __END_DECLS   }
#   endif
#   ifndef __BEGIN_EXTERN_C
#      define __BEGIN_EXTERN_C   extern "C" {
#   endif
#   ifndef __END_EXTERN_C
#      define __END_EXTERN_C   }
#   endif
#   ifndef __BEGIN_NAMESPACE_STD
/** C++ standard namespace */
#      define __BEGIN_NAMESPACE_STD   namespace std {
/** End of C++ standard namespace */
#      define __END_NAMESPACE_STD   }
#      define __USING_NAMESPACE_STD(name)   using std::name;
#      define __BEGIN_NAMESPACE_C99   namespace __c99 {
#      define __END_NAMESPACE_C99   }
#      define __USING_NAMESPACE_C99(name)   using __c99::name;
#   endif  // __BEGIN_NAMESPACE_STD
#endif  // IS_NOT_CPLUSPLUS
#define _EXTERN_C   __BEGIN_DECLS
#define _END_EXTERN_C   __END_DECLS
#if (IS_CPLUSPLUS && (!defined(EXPORTED_CONST)))
#   define EXPORTED_CONST   extern const
#elif (!defined(EXPORTED_CONST))
#   define EXPORTED_CONST   const
#endif
#ifdef COMPILER_GNU_GCC  // __BEGIN_PUBLIC_DECLS
#   define __BEGIN_PUBLIC_DECLS   _Pragma("GCC visibility push(default)") __BEGIN_EXTERN_C
#   define __END_PUBLIC_DECLS   __END_EXTERN_C _Pragma("GCC visibility pop")
#   define __BEGIN_HIDDEN_DECLS   _Pragma("GCC visibility push(hidden)") __BEGIN_EXTERN_C
#   define __END_HIDDEN_DECLS   __END_EXTERN_C _Pragma("GCC visibility pop")
#elif defined(COMPILER_CLANG)
#   define __BEGIN_PUBLIC_DECLS   _Pragma("clang visibility push(default)") __BEGIN_EXTERN_C
#   define __END_PUBLIC_DECLS   __END_EXTERN_C _Pragma("clang visibility pop")
#   define __BEGIN_HIDDEN_DECLS   _Pragma("clang visibility push(hidden)") __BEGIN_EXTERN_C
#   define __END_HIDDEN_DECLS   __END_EXTERN_C _Pragma("clang visibility pop")
#else
#   define __BEGIN_PUBLIC_DECLS   __BEGIN_EXTERN_C
#   define __END_PUBLIC_DECLS   __END_EXTERN_C
#   define __BEGIN_HIDDEN_DECLS   __BEGIN_EXTERN_C
#   define __END_HIDDEN_DECLS   __END_EXTERN_C
#endif
#ifndef __CASTV
#   define __CASTV(__dt, __st)   __CAST(__dt, __CAST(void*, __st))
#endif
#ifndef CASTV
#   define CASTV(__dt, __st)   __CAST(__dt, __CAST(void*, __st))
#endif
#ifndef __CASTCV
#   define __CASTCV(__dt, __st)   __CAST(__dt, __CAST(const void*, __st))
#endif
#ifndef CASTCV
#   define CASTCV(__dt, __st)   __CAST(__dt, __CAST(const void*, __st))
#endif
#ifndef __cast__
#   define __cast__(_to)
#endif
#ifndef __CAST_AWAY_QUALIFIER
/** This macro casts away the qualifier from the variable; Note: Use at your own risk, removing qualifiers can result in catastrophic run-time failures */
#   define __CAST_AWAY_QUALIFIER(variable, qualifier, type)   type (long)variable
#endif
#ifndef CAST_AWAY_QUALIFIER
/** This macro casts away the qualifier from the variable; Note: Use at your own risk, removing qualifiers can result in catastrophic run-time failures */
#   define CAST_AWAY_QUALIFIER(variable, qualifier, type)   type (long)variable
#endif
#if IS_CPLUSPLUS
#   define __THROW   throw()
#   define __THROWNL   throw()
#   define __NTH(fct)   fct throw()
#else  // C
#   define __THROW
#   define __THROWNL
#   define __NTH(fct)   fct
#endif
#if (IS_CPLUSPLUS && IS_GNUC)  // _NOTHROW
#   define _NOTHROW   __attribute__((__nothrow__))
#else
#   define _NOTHROW
#endif

/** @} */  // }


// GENERIC KEYWORD

/** @defgroup Generic_Keyword Macros pertaining to the `Generic` keyword
@{ */  // (FB){

#ifndef Generic
/** Alias for "_Generic" on systems that lack "Generic" */
#   define Generic    _Generic
#endif
#define IS_CHAR(x)   Generic ((x), signed char: 1, unsigned char: 1, default: 0)
#define IS_STRING(x)   Generic ((x), const char*: 1, const signed char*: 1, const unsigned char*: 1, char* const: 1, signed char* const: 1, unsigned char* const: 1, const char* const: 1, const signed char* const: 1, const unsigned char* const: 1, char*: 1, signed char*: 1, unsigned char*: 1, default: 0)
#define IS_SHORT(x)   Generic ((x), short: 1, unsigned short: 1, default: 0)
#define IS_INT(x)   Generic ((x), int: 1, unsigned int: 1, default: 0)
#define IS_LONG(x)   Generic ((x), long: 1, unsigned long: 1, default: 0)
#define IS_LONG_LONG(x)   Generic ((x), long long: 1, unsigned long long: 1, default: 0)
#if SUPPORTS_FLOAT16
#   define IS_FLT16(x)   Generic ((x), float16: 1, default: 0)
#   define _IS_SCALAR_FLOAT16_   float16: 1,
#   define _TYPENAME_FLOAT16_   float16: "float16",
#else
#   define IS_FLT16(x)   0
#   define _IS_SCALAR_FLOAT16_
#   define _TYPENAME_FLOAT16_
#endif
#define IS_FLT(x)   Generic ((x), float: 1, default: 0)
#define IS_DBL(x)   Generic ((x), double: 1, default: 0)
#if SUPPORTS_LONG_DOUBLE
#   define IS_LDBL(x)   Generic ((x), long double: 1, default: 0)
#   define _IS_SCALAR_LONG_DOUBLE_   long double: 1,
#   define _TYPENAME_LONG_DOUBLE_   long double: "long double",
#else
#   define IS_LDBL(x)   0
#   define _IS_SCALAR_LONG_DOUBLE_
#   define _TYPENAME_LONG_DOUBLE_
#endif
#if (SUPPORTS_FLOAT128 && (!LDBL_EQ_FLOAT128))
#   define IS_FLT128(x)   Generic ((x), float128: 1, default: 0)
#   define _IS_SCALAR_FLOAT128_   float128: 1,
#   define _TYPENAME_FLOAT128_   float128: "float128",
#elif LDBL_EQ_FLOAT128
#   define IS_FLT128(x)   IS_LDBL(x)
#   define _IS_SCALAR_FLOAT128_
#   define _TYPENAME_FLOAT128_
#else
#   define IS_FLT128(x)   0
#   define _IS_SCALAR_FLOAT128_
#   define _TYPENAME_FLOAT128_
#endif
#define IS_BINFLT(x)   (IS_FLT(x) || IS_DBL(x) || IS_LDBL(x) || IS_FLT16(x) || IS_FLT128(x))
#if SUPPORTS_DECIMAL_FLOATS
#   define IS_DEC32(x)   Generic ((x), decimal32: 1, default: 0)
#   define IS_DEC64(x)   Generic ((x), decimal64: 1, default: 0)
#   define _IS_SCALAR_DECIMAL_FLOAT_   decimal32: 1, decimal64: 1,
#   define _TYPENAME_DECIMAL_FLOAT_   decimal32: "decimal32", decimal64: "decimal64",
#else
#   define _IS_SCALAR_DECIMAL_FLOAT_
#   define _TYPENAME_DECIMAL_FLOAT_
#endif
#if SUPPORTS_DECIMAL128
#   define IS_DEC128(x)   Generic ((x), decimal128: 1, default: 0)
#   define IS_DEC(x)   (IS_DEC32(x) || IS_DEC64(x) || IS_DEC128(x))
#   define IS_REAL(x)   (IS_BINFLT(x) || IS_DEC(x))
#   define _IS_SCALAR_DECIMAL128_   decimal128: 1,
#   define _TYPENAME_DECIMAL128_   decimal128: "decimal128",
#elif SUPPORTS_DECIMAL_FLOATS
#   define IS_DEC(x)   (IS_DEC32(x) || IS_DEC64(x))
#   define IS_REAL(x)   (IS_BINFLT(x) || IS_DEC(x))
#   define _IS_SCALAR_DECIMAL128_
#   define _TYPENAME_DECIMAL128_
#else
#   define IS_REAL(x)   IS_BINFLT(x)
#   define _IS_SCALAR_DECIMAL128_
#   define _TYPENAME_DECIMAL128_
#endif
#if SUPPORTS_COMPLEX
#   define IS_CXFLT(x)   Generic ((x), complex_float: 1, default: 0)
#   define IS_CXDBL(x)   Generic ((x), complex_double: 1, default: 0)
#   define _IS_SCALAR_COMPLEX_   complex_float: 1, complex_double: 1,
#   define _TYPENAME_COMPLEX_   complex_float: "complex_float", complex_double: "complex_double",
#else
#   define _IS_SCALAR_COMPLEX_
#   define _TYPENAME_COMPLEX_
#endif
#if SUPPORTS_COMPLEX_LDBL
#   define IS_CXLDBL(x)   Generic ((x), complex_long_double: 1, default: 0)
#   define IS_CX(x)   (IS_CXFLT(x) || IS_CXDBL(x) || IS_CXLDBL(x))
#   define IS_CMPLX(x)   IS_CX(x)
#   define IS_FP(x)   (IS_REAL(x) || IS_CMPLX(x))
#   define _IS_SCALAR_COMPLEX_LONG_DOUBLE_   complex_long_double: 1,
#   define _TYPENAME_COMPLEX_LONG_DOUBLE_   complex_long_double: "complex_long_double",
#elif SUPPORTS_COMPLEX
#   define IS_CX(x)   (IS_CXFLT(x) || IS_CXDBL(x))
#   define IS_CMPLX(x)   IS_CX(x)
#   define IS_FP(x)   (IS_REAL(x) || IS_CMPLX(x))
#   define _IS_SCALAR_COMPLEX_LONG_DOUBLE_
#   define _TYPENAME_COMPLEX_LONG_DOUBLE_
#else
#   define IS_FP(x)   IS_REAL(x)
#   define _IS_SCALAR_COMPLEX_LONG_DOUBLE_
#   define _TYPENAME_COMPLEX_LONG_DOUBLE_
#endif
#if SUPPORTS_STDFIX
#   define IS_ACCUM(x)   Generic ((x), _Accum: 1, _Sat _Accum: 1, default: 0)
#   define IS_FRACT(x)   Generic ((x), _Fract: 1, _Sat _Fract: 1, default: 0)
#   define IS_SAT(x)   Generic ((x), _Sat _Accum: 1, _Sat _Fract: 1, default: 0)
#   define _IS_ACCUM_   _Accum: 1,
#   define _IS_FRACT_   _Fract: 1,
#   define _IS_SAT_   _Sat _Accum: 1, _Sat _Fract: 1,
#   define _IS_STDFIX_   _IS_ACCUM_ _IS_FRACT_ _IS_SAT_
#   define _TYPENAME_ACCUM_   _Accum: "_Accum",
#   define _TYPENAME_FRACT_   _Fract: "_Fract",
#   define _TYPENAME_SAT_   _Sat _Accum: "_Sat _Accum", _Sat _Fract: "_Sat _Fract",
#   define _TYPENAME_STDFIX_   _Accum: "_Accum", _Sat _Accum: "_Sat _Accum", _Fract: "_Fract", _Sat _Fract: "_Sat _Fract",
#else
#   define IS_ACCUM(x)
#   define IS_FRACT(x)
#   define IS_SAT(x)
#   define _IS_ACCUM_
#   define _IS_FRACT_
#   define _IS_SAT_
#   define _IS_STDFIX_
#   define _TYPENAME_ACCUM_
#   define _TYPENAME_FRACT_
#   define _TYPENAME_SAT_
#   define _TYPENAME_STDFIX_
#endif
#define is_scalar(type)   Generic ((type), \
	signed char: 1, \
	unsigned char: 1, \
	short: 1, \
	unsigned short: 1, \
	int: 1, \
	unsigned int: 1, \
	long: 1, \
	unsigned long: 1, \
	long long: 1, \
	unsigned long long: 1, \
	_IS_SCALAR_FLOAT16_ \
	float: 1, \
	double: 1, \
	_IS_SCALAR_LONG_DOUBLE_ \
	_IS_SCALAR_FLOAT128_ \
	_IS_SCALAR_DECIMAL_FLOAT_ \
	_IS_SCALAR_DECIMAL128_ \
	_IS_SCALAR_COMPLEX_ \
	_IS_SCALAR_COMPLEX_LONG_DOUBLE_ \
	_IS_STDFIX_ \
	default: 0 \
)
/** Return the datatype of the given variable */
#define typename(type)   Generic ((type), \
	signed char: "signed char", \
	unsigned char: "unsigned char", \
	short: "short", \
	unsigned short: "unsigned short", \
	int: "int", \
	unsigned int: "unsigned int", \
	long: "long", \
	unsigned long: "unsigned long", \
	long long: "long long", \
	unsigned long long: "unsigned long long", \
	_TYPENAME_FLOAT16_ \
	float: "float", \
	double: "double", \
	_TYPENAME_LONG_DOUBLE_ \
	_TYPENAME_FLOAT128_ \
	_TYPENAME_DECIMAL_FLOAT_ \
	_TYPENAME_DECIMAL128_ \
	_TYPENAME_COMPLEX_ \
	_TYPENAME_COMPLEX_LONG_DOUBLE_ \
	_TYPENAME_STDFIX_ \
	char*: "pointer to char", \
	signed char*: "pointer to signed char", \
	unsigned char*: "pointer to unsigned char", \
	const char*: "pointer to char const", \
	const signed char*: "pointer to signed char const", \
	const unsigned char*: "pointer to unsigned char const", \
	char* const: "const pointer to char", \
	signed char* const: "const pointer to signed char", \
	unsigned char* const: "const pointer to unsigned char", \
	const char* const: "const pointer to char const", \
	const signed char* const: "const pointer to signed char const", \
	const unsigned char* const: "const pointer to unsigned char const", \
	int*: "pointer to int", \
	unsigned int*: "pointer to unsigned int", \
	const int*: "pointer to int const", \
	const unsigned int*: "pointer to unsigned int const", \
	int* const: "const pointer to int", \
	unsigned int* const: "const pointer to unsigned int", \
	const int* const: "const pointer to int const", \
	const unsigned int* const: "const pointer to unsigned int const", \
	void*: "pointer to void", \
	default: "other" \
)
/** Return the datatype of the given variable */
#define get_type(type)   typename(type)

/** @} */  // }


// FRAME MACROS

/** @defgroup Frame_Macros Macro functions pertaining to the stack frame
@{ */  // (FB){

#if (IS_GNUC && (!defined(FIRST_FRAME_POINTER)))
/** Returns the address of the stack frame (return address) of the current function or its caller */
#   define FIRST_FRAME_POINTER   __builtin_frame_address(0)
#endif
#ifndef CURRENT_STACK_FRAME
/** Get some notion of the current stack */
#   define CURRENT_STACK_FRAME   __extension__ ({ do { char __csf = '\0'; &__csf; } while (0x0) })
#endif

/** @} */  // }


// LANGUAGE CONSTRUCTS

/** @defgroup Language_Constructs Macros providing various language constructs
@{ */  // (FB){

/** Create a temporary variable for use in macros */
#define tmpmvar   CONCAT(tmp_macros_var_, __LINE__)
/** Create a temporary variable for use in macros */
#define tmp1var   CONCAT(tmp_macros_var1_, __LINE__)
/** Create a temporary variable for use in macros */
#define tmp2var   CONCAT(tmp_macros_var2_, __LINE__)
/** Create a temporary variable for use in macros */
#define tmp3var   CONCAT(tmp_macros_var3_, __LINE__)
/** A forever-running while-loop until `break` */
#define until_break   while (1)
/** A forever-running for-loop */
#define loop_forever   for (;;)
/** Run the for-loop on every value inclusively in the specified range */
#define for_each(var, array_name, len)   register size_t tmpmvar; for (tmpmvar = 0, var = array_name[0]; ((len > 0) && (tmpmvar < len) && (var = array_name[tmpmvar])); tmpmvar++)
/** Run the for-loop on every value inclusively in the specified range */
#define for_range(var, low, high)   for (var = low; ((high > low) && (var <= high)); var++)
/** Run the for-loop on every value exclusively in the specified range */
#define for_between(var, low, high)   for (var = (low + 1); ((high > low) && (var < high)); var++)
/** Run the for-loop on every value inclusively in the specified range counting down from `start` and ending at `stop` */
#define for_countdown(var, start, stop)   for (var = start; ((start > stop) && (var >= stop)); var--)
/** Test if `test_val` is inclusively within the specified values */
#define inrange(test_val, low, high)   ((high > low) && (test_val >= low) && (test_val <= high))
/** Outputs `typedef struct NAME_s NAME_t;` which will create a datatype based on the named struct */
#define DECLARE_STRUCT_TYPE(name)   typedef struct name name ## _t

/** @} */  // }


// DEBUG MACROS

/** @def DEBUG
Enable/Disable Debugging */
#if (defined(LINTER_LINT) || defined(NODEBUG) || defined(NDEBUG) || (defined(DEBUG) && (!(DEBUG > 0))))
#   undef DEBUG
#   undef NODEBUG
#   undef NDEBUG
#   define DEBUG   0
#   define NODEBUG   1
#   define NDEBUG   1
#else
#   undef DEBUG
#   undef NODEBUG
#   undef NDEBUG
#   define DEBUG   1
#   define NODEBUG   0
#   define NDEBUG   0
#endif
#ifndef DIAGNOSTIC
#   define DIAGNOSTIC   DEBUG
#endif
#ifndef ATOMIC_DEBUG
#   define ATOMIC_DEBUG   DEBUG
#endif


#endif  // KEYWORDS_H


/* STRING MANIPULATION MACROS */


#if (!(defined(STRING_MANIPULATION_MACROS_H) || defined(_STRING_MANIPULATION_MACROS_H_)))
#define STRING_MANIPULATION_MACROS_H   (1)
#define _STRING_MANIPULATION_MACROS_H_   (1)


/** @defgroup String_Manipulation_Macros Macros used to manipulate macros strings
@{ */  // (FB){

#define PASTE_NAME1(a, b)   a ## b
#define PASTE_NAME(a, b)   PASTE_NAME1(a, b)
/** Used to test macros values */
#define DO_EXPAND(val)   val
/** Used to test macros values */
#define EXPAND_MACROS(val)   DO_EXPAND(val)
#define CAT(x, y)   x ## y
/** Concatenate macros values */
#define CONCAT_X(x, y)   x ## y
#define CONCAT(x, y)   CONCAT_X(x, y)
#define CONCAT3_X(x, y, z)   x ## y ## z
#define CONCAT3(x, y, z)   CONCAT3_X(x, y, z)
#define CONCAT4_X(w, x, y, z)   w ## x ## y ## z
#define CONCAT4(w, x, y, z)   CONCAT4_X(w, x, y, z)
#define CONCAT5_X(v, w, x, y, z)   v ## w ## x ## y ## z
#define CONCAT5(v, w, x, y, z)   CONCAT5_X(v, w, x, y, z)
#define CONCAT6_X(u, v, w, x, y, z)   u ## v ## w ## x ## y ## z
#define CONCAT6(u, v, w, x, y, z)   CONCAT6_X(u, v, w, x, y, z)
#define CONCAT7_X(t, u, v, w, x, y, z)   t ## u ## v ## w ## x ## y ## z
#define CONCAT7(t, u, v, w, x, y, z)   CONCAT7_X(t, u, v, w, x, y, z)
/** Count the args in __VA_ARGS__ */
#define NARGS_X(a, b, c, d, e, f, g, h, n, ...)   n
/** Count the args in __VA_ARGS__ */
#define NARGS(...)   NARGS_X(__VA_ARGS__, 7, 6, 5, 4, 3, 2, 1, 0, )
/** Indirect stringification; Doing two levels allows the parameter to be a macro itself */
#define __stringify_1(x)    #x
/** Indirect stringification; Doing two levels allows the parameter to be a macro itself */
#define __stringify(x)      __stringify_1(x)
/** Indirect stringification; Doing two levels allows the parameter to be a macro itself */
#define S2(x)   #x
/** Indirect stringification; Doing two levels allows the parameter to be a macro itself */
#define S(x)   S2(x)
/** Indirect stringification; Doing two levels allows the parameter to be a macro itself */
#define ISTRINGIFY1(x)   #x
/** Indirect stringification; Doing two levels allows the parameter to be a macro itself */
#define ISTRINGIFY(x)   ISTRINGIFY1(x)
#define __STRING(x)   #x
#define __STRINGIFY(x)   #x
#define STRINGIFY(x)   #x
#define __MINGW64_STRINGIFY(x)   __STRINGIFY(x)
#define MINGW64_STRINGIFY(x)   __STRINGIFY(x)
#define __STR2WSTR(x)   L ## x
#define _STR2WSTR(x)   __STR2WSTR(x)
#ifdef _UNICODE
#   define TEXT(x)   L ## x
#else
#   define TEXT(x)   x
#endif
#define __FILEW__   L ## __FILE__
#define __FUNCTIONW__   L ## __FUNCTION__
#ifndef _
#   if (defined(HAVE_GETTEXT) && HAVE_GETTEXT)
#      define _(str)   gettext(str)
#   else
#      define _(str)   str
#   endif
#endif
#define EVAL0(...)   __VA_ARGS__
#define EVAL1(...)   EVAL0(EVAL0(EVAL0(__VA_ARGS__)))
#define EVAL2(...)   EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL3(...)   EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL4(...)   EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL(...)    EVAL4(EVAL4(EVAL4(__VA_ARGS__)))

/** @} */  // }


#endif  // STRING_MANIPULATION_MACROS_H


/* ATTRIBUTES, BUILTINS, & SPECIFIER MACROS */


#if (!(defined(ATTRIBUTES_H) || defined(_ATTRIBUTES_H) || defined(_ATTRIBUTES_H_)))
#define ATTRIBUTES_H   (1)
#define _ATTRIBUTES_H   (1)
#define _ATTRIBUTES_H_   (1)


// ATTRIBUTE MACROS

#if IS_GNUC
#   ifdef COMPILER_CLANG
/** Do not convert code to calls to a library */
#      define NOLIBCALL
#   else
/** Do not convert code to calls to a library */
#      define NOLIBCALL   __attribute__((__optimize__("-fno-tree-loop-distribute-patterns")))
#   endif
#   define ATTR_CAF   __attribute__((__always_inline__, __const__, __flatten__))
#   define ATTR_CIF   __attribute__((__const__, __inline__, __flatten__))
#   define ATTR_CAFN   __attribute__((__always_inline__, __const__, __flatten__, __nonnull__))
#   define ATTR_MALLOC   __attribute__((__malloc__))
/** Tell the compiler which arguments to an allocation function indicate the size of the allocation */
#   define ATTR_ALLOC_SIZE(...)   __attribute__((__alloc_size__(__VA_ARGS__)))
#   define ATTR_FLATTEN   __attribute__((__flatten__))
#   define ATTR_CF   __attribute__((__const__, __flatten__))
#   define ATTR_PF   __attribute__((__pure__, __flatten__))
/** The function does not have side-effects, only examines its arguments, does not have pointer arguments, and does not call a non-const function */
#   define ATTR_CONST   __attribute__((__const__))
/** The function is has no side-effects and its return value depends only on the parameters and/or global variables */
#   define ATTR_PURE   __attribute__((__pure__))
/** All functions, except those with callbacks or those that synchronize memory, are leaf functions */
#   define ATTR_LEAF   __attribute__((__leaf__))
/** Definition to shut the compiler up about unused arguments */
#   define UNUSED   __attribute__((__unused__))
/** Warn the developer that the function is deprecated */
#   define deprecated   __attribute__((__deprecated__))
/** If using fortification mode, warn about unused results of certain function calls which can lead to problems */
#   define WUR   __attribute__((__warn_unused_result__))
/** Fortify support */
#   define __bos(_ptr)   __builtin_object_size(_ptr, (__USE_FORTIFY_LEVEL > 1))
/** Fortify support */
#   define __bos0(_ptr)   __builtin_object_size(_ptr, 0)
/** Determine the return address */
#   define RETURN_ADDRESS(nr)   __builtin_extract_return_addr(__builtin_return_address((nr)))
/** @def attr_fallthrough
The -Wimplicit-fallthrough warning will not be triggered when a statement that falls through to another case label */
#   ifdef COMPILER_CLANG
#      define attr_fallthrough
#   else
#      define attr_fallthrough   __attribute__((__fallthrough__));
#   endif
/** Specifies that an object or member declaration with type array of char or pointer to char is intended to store character arrays that do not necessarily contain a terminating NUL character */
#   define attr_nonstring   __attribute__((__nonstring__))
#   define patchable   __attribute__((__patchable_function_entry__))
#else
#   define NOLIBCALL
#   define ATTR_CAF
#   define ATTR_CIF
#   define ATTR_CAFN
#   define ATTR_FLATTEN
#   define ATTR_CF
#   define ATTR_PF
#   define ATTR_MALLOC
#   define ATTR_ALLOC_SIZE(...)
#   define ATTR_CONST
/** The function is has no side-effects and its return value depends only on the parameters and/or global variables */
#   define ATTR_PURE
#   define ATTR_LEAF
#   ifdef LINTER_SPLINT
#      define UNUSED   /*@unused@*/
#   else
#      define UNUSED   /*ARGSUSED*/
#   endif
#   define deprecated   /*@warn@*/
/** If using fortification mode, warn about unused results of certain function calls which can lead to problems */
#   define WUR   /*@alwaysreturn@*/
/** Fortify support */
#   define __bos(_ptr)
/** Fortify support */
#   define __bos0(_ptr)
#   define RETURN_ADDRESS(nr)
#   define attr_fallthrough   /*FALLTHROUGH*/
#   define attr_nonstring
#   define patchable
#endif
/** Add the compiler optimization to inhibit loop transformation to library calls; This is used to avoid recursive calls in memset and memmove default implementations */
#define inhibit_loop_to_libcall   NOLIBCALL
/** The function is has no side-effects and its return value depends only on the parameters and/or global variables */
#define __pure   ATTR_PURE
/** Attribute alias for deprecated */
#define __dontuse__   deprecated
/** Attribute alias for deprecated */
#define __AVAILABILITY_INTERNAL_DEPRECATED   deprecated
/** Attribute alias for deprecated */
#define AVAILABILITY_INTERNAL_DEPRECATED   deprecated
/** Definition to shut the compiler up about unused arguments */
#define unusedfunc   UNUSED
#if DEBUG
/** Used in diagnostic code, but may be unused in non-diagnostic code */
#   define __diagused
/** Used in diagnostic code, but may be unused in non-diagnostic code */
#   define __debugused
#else
/** Used in diagnostic code, but may be unused in non-diagnostic code */
#   define __diagused   UNUSED
/** Used in diagnostic code, but may be unused in non-diagnostic code */
#   define __debugused   UNUSED
#endif


// OVERLOAD ATTRIBUTE

#if ((!defined(OVERLOAD)) && defined(COMPILER_CLANG))
#   define OVERLOAD   __attribute__((__overloadable__))
#   define _TG_ATTRSp   __attribute__((__overloadable__))
#   define _TG_ATTRS   __attribute__((__always_inline__, __overloadable__))
#elif (!defined(OVERLOAD))
#   define OVERLOAD
#   define _TG_ATTRSp
#   define _TG_ATTRS   forceinline
#endif


// SPARSE ATTRIBUTES

#if defined(LINTER_SPARSE)
#   define __iomem   __attribute__((__address_space__(2), __noderef__))
#   define __percpu   __attribute__((__address_space__(3), __noderef__))
#   define __pmem   __attribute__((__address_space__(5), __noderef__))
#   define __user   __attribute__((__address_space__(1), __noderef__))
#   define __kernel   __attribute__((__address_space__(0)))
#   define __safe   __attribute__((__safe__))
/** Modifies an arithmetic type so that the only arithmetic options permitted are the ones that are strictly bitwise */
#   define __bitwise   __attribute__((__bitwise__))
/** Do not dereference */
#   define __noderef   __attribute__((__noderef__))
/** Warn if pointers tagged with different address spaces are mixed and if a pointer tagged with "noderef" is dereferenced */
#   define __address_space(x)  __attribute__((__address_space__(x)))
/** Issue a warning if a type is implicitly converted unless it is exactly the same type (changes in constness is permitted, presumably changes in volatility should be permitted as well) */
#   define __nocast   __attribute__((__nocast__))
#   define __must_hold(x)   __attribute__((__context__(x, 1, 1)))
#   define __acquires(x)   __attribute__((__context__(x, 0, 1)))
#   define __releases(x)   __attribute__((__context__(x, 1, 0)))
#   define __acquire(x)   __attribute__((__context__(x, 1)))
#   define __release(x)   __attribute__((__context__(x, -1)))
/** Supports conditional lock (trylock) functions, without requiring special support for them in the compiler */
#   define __cond_lock(x, c)   ((c) ? ({ __acquire(x); 1; }) : 0)
#else
#   define __iomem
#   define __percpu
#   define __pmem
#   define __user
#   define __kernel
#   define __safe
/** Modifies an arithmetic type so that the only arithmetic options permitted are the ones that are strictly bitwise */
#   define __bitwise
/** Do not dereference */
#   define __noderef
/** Warn if pointers tagged with different address spaces are mixed and if a pointer tagged with "noderef" is dereferenced */
#   define __address_space(x)
/** Issue a warning if a type is implicitly converted unless it is exactly the same type (changes in constness is permitted, presumably changes in volatility should be permitted as well) */
#   define __nocast
#   define __must_hold(x)
#   define __acquires(x)
#   define __releases(x)
#   define __acquire(x)
#   define __release(x)
/** Supports conditional lock (trylock) functions, without requiring special support for them in the compiler */
#   define __cond_lock(x, c)
#endif  // Sparse attributes


// RETURNS_TWICE

#if IS_GNUC
/** Informs the compiler that the function returns two or more times (such as setjmp and vfork) */
#   define returns_twice   __attribute__((__returns_twice__))
#else
/** Informs the compiler that the function returns two or more times (such as setjmp and vfork) */
#   define returns_twice
#endif


// HOT & COLD FUNCTION ATTRIBUTES

#if IS_GNUC
#   define COLD   __attribute__((__cold__))
#   define HOT   __attribute__((__hot__))
#else
#   define COLD
#   define HOT
#endif


// PREDICT_LIKELY & PREDICT_UNLIKELY

/** @defgroup Predict_Macros Macros for the `__builtin_expect` compiler-keyword
@{ */  // (FB){

#if IS_GNUC
/** Evaluates to `expression` and hints that the value of `expression` will probably be true; In other words, "if (PREDICT_LIKELY(foo))" is the same as "if (foo)"; it tells the compiler that the branch will be taken most of the time; This can generate slightly better code with some CPUs */
#   define PREDICT_LIKELY(expression)   __builtin_expect((!!(expression)), 1)
/** Evaluates to `expression` and hints that the value of `expression` will probably be false; In other words, "if (PREDICT_UNLIKELY(foo))" is the same as "if (foo)"; it tells the compiler that the branch will usually not be taken; This can generate slightly better code with some CPUs */
#   define PREDICT_UNLIKELY(expression)   __builtin_expect((!!(expression)), 0)
/** Evaluates to `expression` and hints that the value of `expression` will probably be false; In other words, "if (PREDICT_UNLIKELY(foo))" is the same as "if (foo)"; it tells the compiler that the branch will usually not be taken; This can generate slightly better code with some CPUs */
#   define UNLIKELY(expression)   __builtin_expect((!!(expression)), 0)
/** Evaluates to `expression` and hints that the value of `expression` will probably equal `_val` This tells the compiler that the branch will be taken most of the time; This can generate slightly better code with some CPUs */
#   define LIKELY(expression, _val)   __builtin_expect((expression), (_val))
/** Evaluates to `expression` and hints that the value of `expression` will probably be false; this tells the compiler that the branch will usually not be taken; This can generate slightly better code with some CPUs */
#   define LIKELY_FALSE(expression)   __builtin_expect((expression), 0)
/** Evaluates to `expression` and hints that the value of `expression` will probably equal `_val` This tells the compiler that the branch will be taken most of the time; This can generate slightly better code with some CPUs */
#   define LIKELY_TRUE(expression)   __builtin_expect((expression), 1)
#   define builtin_expect(x, y)   __builtin_expect((x), (y))
#else
#   define PREDICT_LIKELY(expression)   ((expression))
#   define PREDICT_UNLIKELY(expression)   ((expression))
#   define UNLIKELY(expression)   ((expression))
#   define LIKELY(expression, _val)   ((expression))
#   define LIKELY_FALSE(expression)
#   define LIKELY_TRUE(expression)
#   define builtin_expect(x, y)
#endif

/** @} */  // }


// UNREACHABLE

/** @defgroup Unreachable Attribute macros indicating that the code region should be unreachable
@{ */  // (FB){

#if IS_LINTER
/** For unreachable default cases in switch statements over bitwise OR of FP_CLS_* values */
#   define _FP_UNREACHABLE   /*NOTREACHED*/
/** Indicates unreachable code */
#   define UNREACHABLE   /*NOTREACHED*/
#elif IS_GNUC
/** For unreachable default cases in switch statements over bitwise OR of FP_CLS_* values */
#   define _FP_UNREACHABLE   __builtin_unreachable()
/** Indicates unreachable code */
#   define UNREACHABLE   __builtin_unreachable();
#else
/** For unreachable default cases in switch statements over bitwise OR of FP_CLS_* values */
#   define _FP_UNREACHABLE   abort()
/** Indicates unreachable code */
#   define UNREACHABLE   abort();
#endif
#ifndef FP_UNREACHABLE
#   define FP_UNREACHABLE   _FP_UNREACHABLE
#endif

/** @} */  // }


// ERRORATTR & WARNATTR

#if IS_GNUC
#   ifndef __warnattr
#      define __warnattr(msg)   __attribute__((__warning__(msg)))
#   endif
#   ifndef __errorattr
#      define __errorattr(name, msg)   __attribute__((__error__(msg)))
#   endif
#else
#   ifndef __warnattr
#      define __warnattr(msg)
#   endif
#   ifndef __errorattr
#      define __errorattr(name, msg)
#   endif
#endif


// DEPRECATED_MSG

#if IS_GNUC  // deprecated_msg
#   define __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)   __attribute__((__deprecated__(_msg)))
#   define DEPRECATED_ATTRIBUTE(_msg)   __attribute__((__deprecated__(_msg)))
#   define DEPRECATED_MSG_ATTRIBUTE(_msg)   __attribute__((__deprecated__(_msg)))
#   define deprecated_msg(_msg)   __attribute__((__deprecated__(_msg)))
#   define deprecated_enum_msg(_msg)   deprecated_msg(_msg)
#else
#   define __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)   deprecated
#   define DEPRECATED_ATTRIBUTE   deprecated
#   define DEPRECATED_MSG_ATTRIBUTE(_msg)   deprecated
#   define deprecated_msg(_msg)   deprecated
#   define deprecated_enum_msg(_msg)
#endif


// VECTOR DATATYPE ATTRIBUTES

/** @defgroup Vector_Datatype_Attributes Macros for various vector attributes
@{ */  // (FB){

#ifdef ARCHX86
/** Used to make a vector datatype that is 4 bytes (32 bits) in length */
#   define VECTOR4   __attribute__((__may_alias__, __vector_size__(4)))
/** Used to make a vector datatype that is 8 bytes (64 bits) in length */
#   define VECTOR8   __attribute__((__may_alias__, __vector_size__(8)))
/** Used to make a vector datatype that is 16 bytes (128 bits) in length */
#   define VECTOR16   __attribute__((__may_alias__, __vector_size__(16)))
/** Used to make a vector datatype that is 32 bytes (256 bits) in length */
#   define VECTOR32   __attribute__((__may_alias__, __vector_size__(32)))
/** Used to make a vector datatype that is 64 bytes (512 bits) in length */
#   define VECTOR64   __attribute__((__may_alias__, __vector_size__(64)))
/** Used to make an unaligned vector datatype that is 4 bytes (32 bits) in length */
#   define VECTOR4U   __attribute__((__aligned__(1), __may_alias__, __vector_size__(4)))
/** Used to make an unaligned vector datatype that is 8 bytes (64 bits) in length */
#   define VECTOR8U   __attribute__((__aligned__(1), __may_alias__, __vector_size__(8)))
/** Used to make an unaligned vector datatype that is 16 bytes (128 bits) in length */
#   define VECTOR16U   __attribute__((__aligned__(1), __may_alias__, __vector_size__(16)))
/** Used to make an unaligned vector datatype that is 32 bytes (256 bits) in length */
#   define VECTOR32U   __attribute__((__aligned__(1), __may_alias__, __vector_size__(32)))
/** Used to make an unaligned vector datatype that is 64 bytes (512 bits) in length */
#   define VECTOR64U   __attribute__((__aligned__(1), __may_alias__, __vector_size__(64)))
/** Used to make a vector datatype that is 4 bytes (32 bits) in length */
#   define POLY_VECTOR4   __attribute__((__may_alias__, __vector_size__(4)))
/** Used to make a vector datatype that is 8 bytes (64 bits) in length */
#   define POLY_VECTOR8   __attribute__((__may_alias__, __vector_size__(8)))
/** Used to make a vector datatype that is 16 bytes (128 bits) in length */
#   define POLY_VECTOR16   __attribute__((__may_alias__, __vector_size__(16)))
/** Used to make a vector datatype that is 32 bytes (256 bits) in length */
#   define POLY_VECTOR32   __attribute__((__may_alias__, __vector_size__(32)))
/** Used to make a vector datatype that is 64 bytes (512 bits) in length */
#   define POLY_VECTOR64   __attribute__((__may_alias__, __vector_size__(64)))
#elif defined(ARCHARM)
/** Used to make a vector datatype that is 4 bytes (32 bits) in length */
#   define VECTOR4   __attribute__((__may_alias__, __neon_vector_type__(4)))
/** Used to make a vector datatype that is 8 bytes (64 bits) in length */
#   define VECTOR8   __attribute__((__may_alias__, __neon_vector_type__(8)))
/** Used to make a vector datatype that is 16 bytes (128 bits) in length */
#   define VECTOR16   __attribute__((__may_alias__, __neon_vector_type__(16)))
/** Used to make a vector datatype that is 32 bytes (256 bits) in length */
#   define VECTOR32   __attribute__((__may_alias__, __neon_vector_type__(32)))
/** Used to make a vector datatype that is 64 bytes (512 bits) in length */
#   define VECTOR64   __attribute__((__may_alias__, __neon_vector_type__(64)))
/** Used to make an unaligned vector datatype that is 4 bytes (32 bits) in length */
#   define VECTOR4U   __attribute__((__aligned__(1), __may_alias__, __neon_vector_type__(4)))
/** Used to make an unaligned vector datatype that is 8 bytes (64 bits) in length */
#   define VECTOR8U   __attribute__((__aligned__(1), __may_alias__, __neon_vector_type__(8)))
/** Used to make an unaligned vector datatype that is 16 bytes (128 bits) in length */
#   define VECTOR16U   __attribute__((__aligned__(1), __may_alias__, __neon_vector_type__(16)))
/** Used to make an unaligned vector datatype that is 32 bytes (256 bits) in length */
#   define VECTOR32U   __attribute__((__aligned__(1), __may_alias__, __neon_vector_type__(32)))
/** Used to make an unaligned vector datatype that is 64 bytes (512 bits) in length */
#   define VECTOR64U   __attribute__((__aligned__(1), __may_alias__, __neon_vector_type__(64)))
#   if defined(COMPILER_CLANG)
/** Used to make a vector datatype that is 4 bytes (32 bits) in length */
#      define POLY_VECTOR4   __attribute__((__may_alias__, __neon_polyvector_type__(4)))
/** Used to make a vector datatype that is 8 bytes (64 bits) in length */
#      define POLY_VECTOR8   __attribute__((__may_alias__, __neon_polyvector_type__(8)))
/** Used to make a vector datatype that is 16 bytes (128 bits) in length */
#      define POLY_VECTOR16   __attribute__((__may_alias__, __neon_polyvector_type__(16)))
/** Used to make a vector datatype that is 32 bytes (256 bits) in length */
#      define POLY_VECTOR32   __attribute__((__may_alias__, __neon_polyvector_type__(32)))
/** Used to make a vector datatype that is 64 bytes (512 bits) in length */
#      define POLY_VECTOR64   __attribute__((__may_alias__, __neon_polyvector_type__(64)))
#   else
/** Used to make a vector datatype that is 4 bytes (32 bits) in length */
#      define POLY_VECTOR4   __attribute__((__may_alias__, __vector_size__(4)))
/** Used to make a vector datatype that is 8 bytes (64 bits) in length */
#      define POLY_VECTOR8   __attribute__((__may_alias__, __vector_size__(8)))
/** Used to make a vector datatype that is 16 bytes (128 bits) in length */
#      define POLY_VECTOR16   __attribute__((__may_alias__, __vector_size__(16)))
/** Used to make a vector datatype that is 32 bytes (256 bits) in length */
#      define POLY_VECTOR32   __attribute__((__may_alias__, __vector_size__(32)))
/** Used to make a vector datatype that is 64 bytes (512 bits) in length */
#      define POLY_VECTOR64   __attribute__((__may_alias__, __vector_size__(64)))
#   endif
#endif

#if (defined(ARCHPOWERPC) && IS_GNUC)
#   define attr_pixel   unsigned short __attribute__((__altivec__(__pixel__)))
#   define attr_vector   __attribute__((__altivec__(__vector__)))
#else
#   define attr_pixel
#   define attr_vector
#endif

/** @} */  // }


// ARCHITECTURE SPECIFIC ATTRIBUTES & MACROS

#ifdef ARCHMICROBLAZE
#   ifdef __XMK__  // Xilinx XMK uses Unix98 mutex
#      define _UNIX98_THREAD_MUTEX_ATTRIBUTES   (1)
#   endif
#   ifndef save_volatiles
/** Indicate that the function is an interrupt handler; All volatile registers (in addition to non-volatile registers) are saved in the function prologue; If the function is a leaf function, only volatiles used by the function are saved; A normal function return is generated instead of a return from interrupt */
#      define save_volatiles   __attribute__((__save_volatiles__))
#   endif
#else
#   ifndef save_volatiles
/** Indicate that the function is an interrupt handler; All volatile registers (in addition to non-volatile registers) are saved in the function prologue; If the function is a leaf function, only volatiles used by the function are saved; A normal function return is generated instead of a return from interrupt */
#      define save_volatiles
#   endif
#endif
#if ((defined(ARCHMIPS) && (!SUPPORTS_RTEMS)) || defined(__frv__) || (defined(ARCHPOWERPC) && defined(_CALL_SYSV)))
#   define impure_ptr   __attribute__((__section__(".sdata")))
#elif defined(__v850)
#   define impure_ptr   __attribute__((__sda__))
#endif


// X86 CALLING CONVENTIONS

/** @defgroup x86_Calling_Conventions Macros pertaining to the x86 calling conventions
@{ */  // (FB){

#if (defined(ARCHX86) && IS_GNUC)
/** The specified function is an interrupt handler or an exception handler */
#   define attr_interrupt   __attribute__((__interrupt__))
#else
#   define attr_interrupt
#endif
#if (defined(ARCHX86_32) && (!defined(ARCHX86_64)) && IS_GNUC)  // https://en.wikipedia.org/wiki/X86_calling_conventions
#   ifndef __cdecl
/** cdecl is used when the varadic and non-varadic functions must have the same binary calling convention */
#      define __cdecl   __attribute__((__cdecl__, __regparm__(0)))
#   endif
#   ifndef __fastcall
/** Passes the first two arguments (left to right) that fit into ECX and EDX, and the remaining arguments are pushed onto the stack (from right to left) */
#      define __fastcall   __attribute__((__fastcall__))
#   endif
#   ifndef __stdcall
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#      define __stdcall   __attribute__((__stdcall__))
#   endif
#   ifndef __thiscall
/** Pass the first argument (if an integral) to the ECX register; The following arguments and arguments of other datatypes are passed to the stack; The called function pops the arguments off the stack; If the number of arguments is variable all arguments are pushed on the stack */
#      define __thiscall   __attribute__((__thiscall__))
#   endif
/** Optional marker for size-optimised MD calling convention */
#   define compactcall   __attribute__((__regparm__(3)))
/** On some platforms, internal function calls are a bit faster by using a different calling convention */
#   define internal_function   __attribute__((__regparm__(3), __stdcall__))
#   define REGPARM(x)   __attribute__((__regparm__(x)))
/** (x86-32 targets with SSE support only) Pass up to 3 floating-point arguments in SSE registers instead of on the stack; Functions that take a variable number of arguments continue to pass all of their floating-point arguments on the stack (x86-32 targets with SSE support only) */
#   define sseregparm   __attribute__((__sseregparm__))
#else  // Meaningless on non-i386
#   ifndef __cdecl
/** cdecl is used when the varadic and non-varadic functions must have the same binary calling convention */#      define __cdecl
#   endif
#   ifndef __fastcall
#      define __fastcall
#   endif
#   ifndef __stdcall
#      define __stdcall
#   endif
#   ifndef __thiscall
#      define __thiscall
#   endif
#   define compactcall
#   define internal_function
#   define REGPARM(x)
#   define sseregparm
#endif
#ifndef cdecl
#   define cdecl   __cdecl
#endif
#ifndef crtdecl
#   define crtdecl   cdecl
#endif
#ifndef WINAPIV
/** cdecl is used when the varadic and non-varadic functions must have the same binary calling convention */#   define WINAPIV   cdecl
#endif
#ifndef fastcall
/** Passes the first two arguments (left to right) that fit into ECX and EDX, and the remaining arguments are pushed onto the stack (from right to left) */
#   define fastcall   __fastcall
#endif
#ifndef msfastcall
/** Passes the first two arguments (left to right) that fit into ECX and EDX, and the remaining arguments are pushed onto the stack (from right to left) */
#   define msfastcall   fastcall
#endif
#ifndef stdcall
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#   define stdcall   __stdcall
#endif
#ifndef pascal
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#   define pascal   stdcall
#endif
#ifndef CALLBACK
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#   define CALLBACK   stdcall
#endif
#ifndef WINAPI
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#   define WINAPI   stdcall
#endif
#ifndef APIENTRY
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#   define APIENTRY   stdcall
#endif
#ifndef thiscall
/** Pass the first argument (if an integral) to the ECX register; The following arguments and arguments of other datatypes are passed to the stack; The called function pops the arguments off the stack; If the number of arguments is variable all arguments are pushed on the stack */
#   define thiscall   __thiscall
#endif
#if (IS_GNUC && (defined(OSWINDOWS) || defined(OSSYMBIAN)))
/** Reference a function or variable via a global pointer to a pointer that is set up by the DLL exporting the symbol; The attribute implies extern; On Microsoft Windows targets, the pointer name is formed by combining _imp__ and the function or variable name */
#   define dllimport   __attribute__((dllimport))
/** Provide a global pointer to a pointer in a DLL, so that it can be referenced with the dllimport attribute; On Microsoft Windows targets, the pointer name is formed by combining _imp__ and the function or variable name */
#   define dllexport   __attribute__((dllexport))
#elif defined(COMPILER_MICROSOFT)
#   define dllimport   __declspec(dllimport)
#   define dllexport   __declspec(dllexport)
#else
#   define dllimport
#   define dllexport
#endif
#if (defined(COMPILER_MICROSOFT) && defined(_DLL))
/** On Windows, variables that may be in a DLL must be marked specially */
#   define DLL_VARIABLE   dllimport
#else
/** On Windows, variables that may be in a DLL must be marked specially */
#   define DLL_VARIABLE
#endif
#if IS_CPLUSPLUS
#   ifdef OSCYGWIN
#      define _EXFUN_NOTHROW(name, proto)   cdecl name proto _NOTHROW
#      define _EXFUN(name, proto)   cdecl name proto
#      define _EXPARM(name, proto)   (* cdecl name) proto
#      define _EXFNPTR(name, proto)   (cdecl * name) proto
#   else  // Not Cygwin
#      define _EXFUN_NOTHROW(name, proto) name proto _NOTHROW
#      define _EXFUN(name, proto)   name proto
#      define _EXPARM(name, proto)   (* name) proto
#      define _EXFNPTR(name, proto)   (* name) proto
#   endif  // Cygwin
#endif  // IS_CPLUSPLUS
#if IS_GNUC  // EXTERN_API & CALLBACK_API
#   define EXTERN_API(_type)   dllimport _type cdecl
#   define EXTERN_API_C(_type)   dllimport _type cdecl
#   define EXTERN_API_STDCALL(_type)   dllimport _type stdcall
#   define EXTERN_API_C_STDCALL(_type)   dllimport _type stdcall
#   define DEFINE_API(_type)   dllexport _type cdecl
#   define DEFINE_API_C(_type)   dllexport _type cdecl
#   define DEFINE_API_STDCALL(_type)   dllexport _type stdcall
#   define DEFINE_API_C_STDCALL(_type)   dllexport _type stdcall
#   define CALLBACK_API(_type, _name)   _type (cdecl * _name)
#   define CALLBACK_API_C(_type, _name)   _type (cdecl * _name)
#   define CALLBACK_API_STDCALL(_type, _name)   _type (stdcall * _name)
#   define CALLBACK_API_C_STDCALL(_type, _name)   _type (stdcall * _name)
#elif defined(COMPILER_MICROSOFT)
#   define EXTERN_API(_type)   __declspec(dllimport) _type cdecl
#   define EXTERN_API_C(_type)   __declspec(dllimport) _type cdecl
#   define EXTERN_API_STDCALL(_type)   __declspec(dllimport) _type stdcall
#   define EXTERN_API_C_STDCALL(_type)   __declspec(dllimport) _type stdcall
#   define DEFINE_API(_type)   __declspec(dllexport) _type cdecl
#   define DEFINE_API_C(_type)   __declspec(dllexport) _type cdecl
#   define DEFINE_API_STDCALL(_type)   __declspec(dllexport) _type stdcall
#   define DEFINE_API_C_STDCALL(_type)   __declspec(dllexport) _type stdcall
#   define CALLBACK_API(_type, _name)   _type (cdecl * _name)
#   define CALLBACK_API_C(_type, _name)   _type (cdecl * _name)
#   define CALLBACK_API_STDCALL(_type, _name)   _type (stdcall * _name)
#   define CALLBACK_API_C_STDCALL(_type, _name)   _type (stdcall * _name)
#else
#   define EXTERN_API(_type)   extern _type
#   define EXTERN_API_C(_type)   extern _type
#   define EXTERN_API_STDCALL(_type)   extern _type
#   define EXTERN_API_C_STDCALL(_type)   extern _type
#   define DEFINE_API(_type)   _type
#   define DEFINE_API_C(_type)   _type
#   define DEFINE_API_STDCALL(_type)   _type
#   define DEFINE_API_C_STDCALL(_type)   _type
#   define CALLBACK_API(_type, _name)   _type (* _name)
#   define CALLBACK_API_C(_type, _name)   _type (* _name)
#   define CALLBACK_API_STDCALL(_type, _name)   _type (* _name)
#   define CALLBACK_API_C_STDCALL(_type, _name)   _type (* _name)
#endif  // EXTERN_API & CALLBACK_API

/** @} */  // }


// TARGET ATTRIBUTES & MACROS

/** @defgroup Build_Target Macros for specifying that a function be built for a particular target
@{ */  // (FB){

#if IS_GNUC
// PowerPC
/** Build specifically for PowerPC7 */
#   define BUILD_POWER7   __attribute__((__target__("arch=power7")))
/** Build specifically for PowerPC8 */
#   define BUILD_POWER8   __attribute__((__target__("arch=power8")))
/** Build specifically for PowerPC9 */
#   define BUILD_POWER9   __attribute__((__target__("arch=power9")))
// x86
#   define BUILD_CORE2   __attribute__((__target__("arch=core2")))
#   define BUILD_PENTIUM4   __attribute__((__target__("arch=pentium4")))
#   define BUILD_SANDYBRIDGE   __attribute__((__target__("arch=sandybridge")))
#   define BUILD_IVYBRIDGE   __attribute__((__target__("arch=ivybridge")))
#   define BUILD_HASWELL   __attribute__((__target__("arch=haswell")))
#   define BUILD_BROADWELL   __attribute__((__target__("arch=broadwell")))
/** Build specifically for Intel's Skylake processors */
#   define BUILD_SKYLAKE   __attribute__((__target__("arch=skylake")))
#   define BUILD_BONNELL   __attribute__((__target__("arch=bonnell")))
#   define BUILD_SILVERMONT   __attribute__((__target__("arch=silvermont")))
#   define BUILD_KNL   __attribute__((__target__("arch=knl")))
/** Build specifically for MMX-supporting processors */
#   define BUILD_MMX   __attribute__((__target__("mmx,sse")))
/** Build specifically for 3DNOW-supporting processors */
#   define BUILD_3DNOW   __attribute__((__target__("3dnow")))
/** Build specifically for SSE-supporting processors */
#   define BUILD_SSE   __attribute__((__target__("sse")))
/** Build specifically for SSE3-supporting processors */
#   define BUILD_SSE3   __attribute__((__target__("sse3")))
/** Build specifically for SSE4-supporting processors */
#   define BUILD_SSE4   __attribute__((__target__("sse4")))
/** Build specifically for AVX-supporting processors */
#   define BUILD_AVX   __attribute__((__target__("avx")))
/** Build specifically for AVX2-supporting processors */
#   define BUILD_AVX2   __attribute__((__target__("avx2")))
/** Build specifically for AVX512F-supporting processors */
#   define BUILD_AVX512F   __attribute__((__target__("avx512f,vaes")))
/** Build specifically for CLDEMOTE-supporting processors */
#   define BUILD_CLDEMOTE   __attribute__((__target__("cldemote")))
/** Build specifically for CLFLUSHOPT-supporting processors */
#   define BUILD_CLFLUSHOPT   __attribute__((__target__("clflushopt")))
/** Build specifically for CLWB-supporting processors */
#   define BUILD_CLWB   __attribute__((__target__("clwb")))
/** Build specifically for CLZERO-supporting processors */
#   define BUILD_CLZERO   __attribute__((__target__("clzero")))
/** Build specifically for LWP-supporting processors */
#   define BUILD_LWP   __attribute__((__target__("lwp")))
/** Build specifically for LZCNT-supporting processors */
#   define BUILD_LZCNT   __attribute__((__target__("lzcnt")))
/** Build specifically for MOVDIRI-supporting processors */
#   define BUILD_MOVDIRI   __attribute__((__target__("movdiri")))
/** Build specifically for MWAITX-supporting processors */
#   define BUILD_MWAITX   __attribute__((__target__("mwaitx")))
/** Build specifically for PCONFIG-supporting processors */
#   define BUILD_PCONFIG   __attribute__((__target__("pconfig")))
/** Build specifically for PKU-supporting processors */
#   define BUILD_PKU   __attribute__((__target__("pku")))
/** Build specifically for SGX-supporting processors */
#   define BUILD_SGX   __attribute__((__target__("sgx")))
/** Build specifically for SHA-supporting processors */
#   define BUILD_SHA   __attribute__((__target__("sha")))
/** Build specifically for RDSEED-supporting processors */
#   define BUILD_RDSEED   __attribute__((__target__("rdseed")))
/** Build specifically for VAES-supporting processors */
#   define BUILD_VAES   __attribute__((__target__("vaes")))
/** Build specifically for WAITPKG-supporting processors */
#   define BUILD_WAITPKG   __attribute__((__target__("waitpkg")))
/** Build specifically for XSAVEC-supporting processors */
#   define BUILD_XSAVEC   __attribute__((__target__("xsavec")))
/** Build specifically for XSAVEOPT-supporting processors */
#   define BUILD_XSAVEOPT   __attribute__((__target__("xsaveopt")))
/** Build specifically for XSAVES-supporting processors */
#   define BUILD_XSAVES   __attribute__((__target__("xsaves")))
/** Build specifically for XTEST-supporting processors */
#   define BUILD_XTEST   __attribute__((__target__("rtm")))
#else
// PowerPC
#   define BUILD_POWER7
#   define BUILD_POWER8
#   define BUILD_POWER9
// x86
#   define BUILD_CORE2
#   define BUILD_PENTIUM4
#   define BUILD_SANDYBRIDGE
#   define BUILD_IVYBRIDGE
#   define BUILD_HASWELL
#   define BUILD_BROADWELL
#   define BUILD_SKYLAKE
#   define BUILD_BONNELL
#   define BUILD_SILVERMONT
#   define BUILD_KNL
#   define BUILD_MMX
#   define BUILD_3DNOW
#   define BUILD_SSE
#   define BUILD_SSE3
#   define BUILD_SSE4
#   define BUILD_AVX
#   define BUILD_AVX2
#   define BUILD_AVX512F
#   define BUILD_CLDEMOTE
#   define BUILD_CLFLUSHOPT
#   define BUILD_CLWB
#   define BUILD_CLZERO
#   define BUILD_LWP
#   define BUILD_LZCNT
#   define BUILD_MOVDIRI
#   define BUILD_MWAITX
#   define BUILD_PCONFIG
#   define BUILD_PKU
#   define BUILD_SGX
#   define BUILD_SHA
#   define BUILD_RDSEED
#   define BUILD_VAES
#   define BUILD_WAITPKG
#   define BUILD_XSAVEC
#   define BUILD_XSAVEOPT
#   define BUILD_XSAVES
#   define BUILD_XTEST
#endif

/** @} */  // }


// STORAGE ATTRIBUTES

#if IS_GNUC
/** Do place the variable in common storage */
#   define attr_common   __attribute__((__common__))
/** Do not place the variable in common storage; instead, allocate space for it directly */
#   define attr_nocommon   __attribute__((__nocommon__))
#   define global_tls   __attribute__((__tls_model__("global-dynamic")))
#   define initial_tls   __attribute__((__tls_model__("initial-exec")))
#   define local_dynamic_tls   __attribute__((__tls_model__("local-dynamic")))
#   define local_exec_tls   __attribute__((__tls_model__("local-exec")))
#else
/** Do place the variable in common storage */
#   define attr_common
/** Do not place the variable in common storage; instead, allocate space for it directly */
#   define attr_nocommon
#   define global_tls
#   define initial_tls
#   define local_dynamic_tls
#   define local_exec_tls
#endif


// STRONG & WEAK ALIASES

/** @defgroup Aliases Macros pertaining to strong and weak aliases
@{ */  // (FB){

#if (IS_NOT_ASSEMBLER && IS_GNUC)
// GCC understands weak symbols and aliases; use this interface where possible, instead of embedded assembly language
/** Define `aliasname` as a strong alias for `sym` */
#   define strong_alias(sym, aliasname)   extern typeof(sym) aliasname __attribute__((__alias__(#sym)));
/** Define `aliasname` as a weak alias for `sym`. If weak aliases are not available, this defines a strong alias */
#   define weak_alias(sym, aliasname)   extern typeof(sym) aliasname __attribute__((__alias__(#sym), __weak__));
/** Declare a function weak; Place between the return type and function name */
#   define weak_const_function   __attribute__((__const__, __weak__))
/** Declare `sym` as weak undefined symbol (resolved to 0 if not defined) */
#   define weak_extern(sym)   _Pragma(#sym)
/** Declare a function weak; Place between the return type and function name */
#   define weak_function   __attribute__((__weak__))
/** Same as `weak_alias`, but mark symbol as hidden */
#   define weak_hidden_alias(sym, aliasname)   extern typeof(sym) aliasname __attribute__((__alias__(#sym), __visibility__("hidden"), __weak__));
#elif (IS_ASSEMBLER && IS_GNUC)  // IS_ASSEMBLER
#   ifdef HAVE_ASM_SET_DIRECTIVE
#      define strong_alias(sym, aliasname)   .globl C_SYMBOL_NAME(aliasname) ASM_LINE_SEP .set C_SYMBOL_NAME(aliasname), C_SYMBOL_NAME(sym)
#   else
#      define strong_alias(sym, aliasname)   .globl C_SYMBOL_NAME(aliasname) ASM_LINE_SEP C_SYMBOL_NAME(aliasname) = C_SYMBOL_NAME(sym)
#   endif
#   ifdef HAVE_ASM_WEAKEXT_DIRECTIVE
#      define weak_alias(sym, aliasname)   .weakext C_SYMBOL_NAME(aliasname), C_SYMBOL_NAME(sym)
#      define weak_extern(sym)   .weakext C_SYMBOL_NAME(sym)
#   else
#      define weak_alias(sym, aliasname)   .weak C_SYMBOL_NAME(aliasname) ASM_LINE_SEP C_SYMBOL_NAME(aliasname) = C_SYMBOL_NAME(sym)
#      define weak_extern(sym)   .weak C_SYMBOL_NAME(sym)
#   endif
#   define weak_const_function
#   define weak_function
#   define weak_hidden_alias(sym, aliasname)
#else
#   define strong_alias(sym, aliasname)
#   define weak_alias(sym, aliasname)
#   define weak_const_function
#   define weak_extern(sym)
#   define weak_function
#   define weak_hidden_alias(sym, aliasname)
#endif  // Aliases
#if IS_GNUC  // strict_weak_alias
#   define strict_weak_alias(sym, aliasname)   static UNUSED typeof(aliasname)* weak_alias_ ## aliasname = &sym; weak_alias(sym, aliasname)
#else
#   define strict_weak_alias(sym, aliasname)   weak_alias(sym, aliasname)
#endif
#define __alias(x)   __attribute__((__alias__(x), __weak__))
#define _strong_alias(sym, aliasname)   strong_alias(sym, aliasname)
#define __strong_alias(sym, aliasname)   strong_alias(sym, aliasname)
#define __strong_alias__(sym, aliasname)   strong_alias(sym, aliasname)
#define strong_data_alias(sym, aliasname)   strong_alias(sym, aliasname)
#define strong_reference(sym, aliasname)   strong_alias(sym, aliasname)
#define _strong_reference(sym, aliasname)   strong_alias(sym, aliasname)
#define __strong_reference(sym, aliasname)   strong_alias(sym, aliasname)
/** Symbols reserved to or specified by ISO C; Defines `sym` as a strong alias for _libc_sym */
#define DEF_STRONG(sym)   strong_alias(sym, HIDDEN(sym))
/** Defines _thread_sys_sym as a strong alias for _libc_sym; This should only be needed for syscalls that have C instead of ASM stubs */
#define DEF_SYS(sym)   strong_alias(_thread_sys_ ## sym, HIDDEN(sym))
#define _weak_alias(sym, aliasname)   weak_alias(sym, aliasname)
#define _weak_extern(sym)   weak_extern(sym)
#define _weak_hidden_alias(sym, aliasname)   weak_hidden_alias(sym, aliasname)
#define weak_reference(sym)   __attribute__((__weakref__(sym)))
#define _weak_reference(sym)   __attribute__((__weakref__(sym)))
#define __weak_reference(sym)   __attribute__((__weakref__(sym)))
#define _strict_weak_alias(sym, aliasname)   strict_weak_alias(sym, aliasname)
#define __strict_weak_alias(sym, aliasname)   strict_weak_alias(sym, aliasname)
/** Symbols that have a cancellation wrapper; Defines `sym` as a weak alias for _libc_sym_cancel */
#define DEF_CANCEL(sym)   weak_alias(sym, CANCEL(sym))
/** Symbols used internally and not in ISO C; Defines `sym` as a weak alias for _libc_sym */
#define DEF_WEAK(sym)   weak_alias(sym, HIDDEN(sym))
/** Defines `sym` as a weak alias for _libc_sym_wrap */
#define DEF_WRAP(sym)   weak_alias(sym, WRAP(sym))
/** Compiler macros to make an alias symbol */
#define __ALIAS(__t, __f, __p, __a)   __t __f __p __attribute__((__weak__, __alias__(#__a)));
#define LFS64_2(sym, aliasname)   weak_alias(sym, aliasname)
#define LFS64(sym)   LFS64_2(sym, sym ## 64)
/** Export the symbol for both static and dynamic linking */
#define libc_sunrpc_symbol(name, aliasname, version)   strong_alias(name, aliasname)
/** No versions to worry about, just make this the global definition */
#define versioned_symbol(lib, aliasname, sym, version)   weak_alias(sym, aliasname)
/** No old versions to worry about */
#define SHLIB_COMPAT(lib, introduced, obsoleted)   0

/** @} */  // }


// VISIBILITY ATTRIBUTES

/** @defgroup Visibility_Attributes Attribute macros for symbol visibility
@{ */  // (FB){

#if (IS_PIC || IS_GNUC)
/** Linkage decoration indicating that a symbol can be used from other compilation units, but not other libraries or executables */
#   define attr_hidden   __attribute__((__visibility__("hidden")))
#   define __hidden_proto_hiddenattr(...)   __attribute__((__visibility__("hidden"), __VA_ARGS__))
#   define __dso_hidden   __attribute__((__visibility__("hidden")))
#   define __dso_protected   __attribute__((__visibility__("protected")))
#   define __dso_public   __attribute__((__visibility__("default")))
#else
#   define attr_hidden
#   define __hidden_proto_hiddenattr(...)
#   define __dso_hidden
#   define __dso_protected
#   define __dso_public
#endif
/** Linkage decoration indicating that a symbol can be used from other compilation units, but not other libraries or executables */
#define ATTR_LIBC_VISIBILITY   attr_hidden
#ifndef __XNU_PRIVATE_EXTERN
/** Linkage decoration indicating that a symbol can be used from other compilation units, but not other libraries or executables */
#   define __XNU_PRIVATE_EXTERN   attr_hidden
#endif

/** @} */  // }


// WEAK_IMPORT & UNAVAILABLE ATTRIBUTES

#if (IS_GNUC || ((defined(__MWERKS__) && (__MWERKS__ >= 0x3205)) && (defined(MAC_OS_X_VERSION_MIN_REQUIRED) && (MAC_OS_X_VERSION_MIN_REQUIRED >= 1020)) && (!(defined(ARCHX86) || defined(ARCHX86_64)))))
#   define WEAK_IMPORT_ATTRIBUTE   __attribute__((__weak_import__))
#   define __AVAILABILITY_INTERNAL_WEAK_IMPORT   __attribute__((__weak_import__))
#   define __AVAILABILITY_INTERNAL_UNAVAILABLE   __attribute__((__unavailable__))
#   define __unavailable   __attribute__((__unavailable__))
#   define UNAVAILABLE_ATTRIBUTE   __attribute__((__unavailable__))
#else
#   define WEAK_IMPORT_ATTRIBUTE
#   define __AVAILABILITY_INTERNAL_WEAK_IMPORT
#   define __AVAILABILITY_INTERNAL_UNAVAILABLE
#   define __unavailable
#   define UNAVAILABLE_ATTRIBUTE
#endif


// LONG DOUBLE COMPATABILITY

#if (defined(__LONG_DOUBLE_MATH_OPTIONAL) && defined(__NO_LONG_DOUBLE_MATH) && (!(defined(__LDBL_COMPAT) || defined(__LDBL_REDIR1))))
#   define __LDBL_COMPAT   1
#   define __LDBL_REDIR1(sym, proto, aliasname)   __REDIRECT(sym, proto, aliasname)
#   define __LDBL_REDIR(sym, proto)   __LDBL_REDIR1(sym, proto, __nldbl_ ## sym)
#   define __LDBL_REDIR1_NTH(sym, proto, aliasname)   __REDIRECT_NTH(sym, proto, aliasname)
#   define __LDBL_REDIR_NTH(sym, proto)   __LDBL_REDIR1_NTH(sym, proto, __nldbl_ ## sym)
#   define __LDBL_REDIR1_DECL(sym, aliasname)   extern typeof(sym) sym asm (__ASMNAME(#aliasname));
#   define __LDBL_REDIR_DECL(sym)   extern typeof(sym) sym asm (__ASMNAME("__nldbl_" #sym));
#   define __REDIRECT_LDBL(sym, proto, aliasname)   __LDBL_REDIR1(sym, proto, __nldbl_ ## aliasname)
#   define __REDIRECT_NTH_LDBL(sym, proto, aliasname)   __LDBL_REDIR1_NTH(sym, proto, __nldbl_ ## aliasname)
#elif (!(defined(__LDBL_COMPAT) || defined(__LDBL_REDIR1)))
#   define __LDBL_REDIR1(sym, proto, aliasname)   sym proto
#   define __LDBL_REDIR(sym, proto)   sym proto
#   define __LDBL_REDIR1_NTH(sym, proto, aliasname)   sym proto __THROW
#   define __LDBL_REDIR_NTH(sym, proto)   sym proto __THROW
#   define __LDBL_REDIR_DECL(sym)
#   define __REDIRECT_LDBL(sym, proto, aliasname)   __REDIRECT(sym, proto, aliasname)
#   define __REDIRECT_NTH_LDBL(sym, proto, aliasname)   __REDIRECT_NTH(sym, proto, aliasname)
#endif


// FORMAT ATTRIBUTES

/** @defgroup Format_Attributes Attribute macros for printf-formats
@{ */  // (FB){

#if IS_GNUC
#   define formatfunc(t, f, a)   __attribute__((__format__(t, f, a)))
#   define __attribute_format_strfmon__(a, b)   __attribute__((__format__(__strfmon__, (a), (b))))
#   define __attribute_format_arg__(x)   __attribute__((__format_arg__(x)))
#   define __scanflike(fmtarg, firstvararg)   __attribute__((__format__(__scanf__, fmtarg, firstvararg)))
#   define format_arg(fmtarg)    __attribute__((__format_arg__(fmtarg)))
/** Attribute to make GCC check printf-like arguments */
#   define ATTR_PRINTF(m, n)   __attribute__((__format__(__printf__, m, n))) ATTR_NONNULL(m)
#   define NULL_PRINTF(m, n)   __attribute__((__format__(__printf__, m, n)))
#   define NULL_PRINTF_1   NULL_PRINTF(1, 2)
#   define NULL_PRINTF_2   NULL_PRINTF(2, 3)
#   define NULL_PRINTF_3   NULL_PRINTF(3, 4)
#   define NULL_PRINTF_4   NULL_PRINTF(4, 5)
#   define NULL_PRINTF_5   NULL_PRINTF(5, 6)
#else
#   define formatfunc(t, f, a)
#   define __attribute_format_strfmon__(a, b)
#   define __attribute_format_arg__(x)
#   define __scanflike(fmtarg, firstvararg)   /*@scanflike@*/
#   define format_arg(fmtarg)
#   define ATTR_PRINTF(m, n)   /*PRINTFLIKE*/
#   define NULL_PRINTF(m, n)   /*PRINTFLIKE*/
#   define NULL_PRINTF_1   /*PRINTFLIKE*/
#   define NULL_PRINTF_2   /*PRINTFLIKE*/
#   define NULL_PRINTF_3   /*PRINTFLIKE*/
#   define NULL_PRINTF_4   /*PRINTFLIKE*/
#   define NULL_PRINTF_5   /*PRINTFLIKE*/
#endif  // formatfunc

/** @} */  // }


// NULL_UNSPECIFIED ATTRIBUTE

#ifdef COMPILER_CLANG
/** The input pointer parameter of the function cannot use `NONNULL` nor `Nullable` */
#   define Null_unspecified   _Null_unspecified
#else
/** The input pointer parameter of the function cannot use `NONNULL` nor `Nullable` */
#   define Null_unspecified
/** The input pointer parameter of the function cannot use `NONNULL` nor `Nullable` */
#   define _Null_unspecified
#endif


// NULLABLE ATTRIBUTE

#ifdef COMPILER_CLANG
/** The input pointer parameter of the function may be NULL */
#   define Nullable   _Nullable
#else
/** The input pointer parameter of the function may be NULL */
#   define Nullable
/** The input pointer parameter of the function may be NULL */
#   define _Nullable
#endif


// NONNULL ATTRIBUTES

#if IS_GNUC
/** The functions input parameters are never NULL */
#   define NONNULL   __attribute__((__nonnull__))
/** ATTR_NONNULL(n, ..., m) tells the compiler and static analyzer tools that the values passed as the specified arguments must be non-NULL pointers; n = 1 stands for the first argument, n = 2 for the second argument, and so on */
#   define ATTR_NONNULL(params)   __attribute__((__nonnull__(params)))
/** The function never returns NULL */
#   define RETURNS_NONNULL   __attribute__((__returns_nonnull__))
/** The function does not accept nor return NULL */
#   define NONNULL_IO   __attribute__((__returns_nonnull__, __nonnull__))
/** Ensures that a parameter in a function call is an explicit NULL (only valid on variadic functions) */
#   define ATTR_SENTINEL   __attribute__((__sentinel__))
#else
/** The functions input parameters are never NULL */
#   define NONNULL   /*@notnull@*/
#   define ATTR_NONNULL(params)   /*@notnull@*/
/** The function never returns NULL */
#   define RETURNS_NONNULL   /*@notnull@*/
/** The function does not accept nor return NULL */
#   define NONNULL_IO
#   define ATTR_SENTINEL
#endif


// ARTIFICIAL ATTRIBUTE

#if IS_GNUC
/** Useful for small inline wrappers that should appear during debugging as a unit (if possible) */
#   define attr_artificial   __attribute__((__artificial__))
#else
#   define attr_artificial
#endif
#ifndef __fortify_function
#   define __fortify_function   extern_always_inline attr_artificial
#endif


// BOUNDS-CHECKER, PROFILING, & SANITIZER ATTRIBUTES

#if IS_GNUC
/** Inform the Pointer-Bounds-Checker that the size of the field should not be computed using static type information */
#   define bnd_variable_size   __attribute__((__bnd_variable_size__))
/** Do not add profiling function calls to the function nor instrument the function */
#   define __noprofile   __attribute__((__bnd_legacy__, __no_instrument_function__, __no_profile_instrument_function__, __no_sanitize__))
/** Inform the compiler that it should not instrument memory accesses in the function when compiling with the `-fsanitize=address` option */
#   define NO_SANITIZE_ADDRESS   __attribute__((__no_sanitize_address__))
/** Inform the compiler that it should not instrument memory accesses in the function when compiling with the `-fsanitize=thread` option */
#   define NO_SANITIZE_THREAD   __attribute__((__no_sanitize_thread__))
/** Inform the compiler that it should not check for undefined behavior in the function when compiling with the `-fsanitize=undefined` option */
#   define NO_SANITIZE_UNDEFINED   __attribute__((__no_sanitize_undefined__))
#   define stack_protect   __attribute__((__stack_protect__))
#else
#   define bnd_variable_size
#   define __noprofile
#   define NO_SANITIZE_ADDRESS
#   define NO_SANITIZE_THREAD
#   define NO_SANITIZE_UNDEFINED
#   define stack_protect
#endif


// ENABLE OPTIMIZATIONS

#if IS_GNUC
#   define attr_optimize(x)   __attribute__((optimize(x)))
#else
#   define attr_optimize(x)
#endif


// DISABLE OPTIMIZATIONS

#if IS_GNUC
/** Prevents a function from being considered for cloning */
#   define noclone   __attribute__((__noclone__))
/** Prevents a function from being merged with another semantically equivalent function */
#   define no_icf   __attribute__((__no_icf__))
/** Prevents a function orvariable from being reordered */
#   define no_reorder   __attribute__((__no_reorder__))
#else
#   define noclone
#   define no_icf
#   define no_reorder
#endif


// MISCELLANEOUS GNU-GCC & CLANG MACROS

#if IS_GNUC
#   define os_constant(x)   __builtin_constant_p((x))
#else
#   define os_constant(x)   ((long)0)
#endif
#if (IS_GNUC || IS_STDC99)  // __flexarr
/** Flexible array members */
#   define __flexarr   []
#else
/** Flexible array members */
#   define __flexarr   [1]
#endif


// MISCELLANEOUS MICROSOFT MACROS

/** @defgroup Microsoft_Macros Macros specific to Microsoft-product development
@{ */  // (FB){

#ifdef COMPILER_MICROSOFT  // DECLSPEC_INTRIN_TYPE
#   define DECLSPEC_INTRIN_TYPE   __declspec(intrin_type)
#else
#   define DECLSPEC_INTRIN_TYPE
#endif
#if IS_GNUC  // DECLSPEC_HOTPATCH
/** Define to a function attribute for Microsoft hotpatch assembly prefix */
#   define DECLSPEC_HOTPATCH   __attribute__((__ms_hook_prologue__))
#elif defined(COMPILER_MICROSOFT)
/** Define to a function attribute for Microsoft hotpatch assembly prefix */
#   define DECLSPEC_HOTPATCH   __declspec(ms_hook_prologue)
#else
/** Define to a function attribute for Microsoft hotpatch assembly prefix */
#   define DECLSPEC_HOTPATCH
#endif

/** @} */  // }


// LINK SET MACROS

/** @defgroup Link_Set_Macros Macros controlling the linking process
@{ */  // (FB){

#define __link_set_start(set)   __start_link_set_ ## set
#define __link_set_end(set)   __stop_link_set_ ## set
#define __link_set_count(set)   (__link_set_end(set) - __link_set_start(set))
#define __link_set_make_entry(set, sym)   static void const* const __link_set_ ## set ## _sym_ ## sym __section("link_set_" #set) UNUSED = &sym
#define __link_set_make_entry2(set, sym, n)   static void const* const __link_set_ ## set ## _sym_ ## sym ## _ ## n __section("link_set_" #set) UNUSED = &sym[n]
#define __link_set_add_text(set, sym)   __link_set_make_entry(set, sym)
#define __link_set_add_rodata(set, sym)   __link_set_make_entry(set, sym)
#define __link_set_add_data(set, sym)   __link_set_make_entry(set, sym)
#define __link_set_add_bss(set, sym)   __link_set_make_entry(set, sym)
#define __link_set_add_text2(set, sym, n)   __link_set_make_entry2(set, sym, n)
#define __link_set_add_rodata2(set, sym, n)   __link_set_make_entry2(set, sym, n)
#define __link_set_add_data2(set, sym, n)   __link_set_make_entry2(set, sym, n)
#define __link_set_add_bss2(set, sym, n)   __link_set_make_entry2(set, sym, n)
#define __link_set_decl(set, ptype)   extern ptype* const __start_link_set_ ## set[]; extern ptype* const __stop_link_set_ ## set[]
/** Iterate over the link set `set`; Because a link set is an array of pointers, pvar must be declared as `type** pvar`, and the actual entry accessed as `*pvar` */
#define __link_set_foreach(pvar, set)   for (pvar = __link_set_start(set); pvar < __link_set_end(set); pvar++)
/** Access the link set entry at index `idx` from set `set` */
#define __link_set_entry(set, idx)   (__link_set_begin(set)[idx])

/** @} */  // }


// ASSEMBLY MACROS

/** @defgroup Assembly_Macros Macros pertaining to assembly
@{ */  // (FB){

#define RELOC_HIDE(ptr, off)   do { unsigned long __ptr; vasm(";" : "=r"(__ptr) : "0"(ptr)); (typeof(ptr))(__ptr + (off)); } while (0x0)
#define OPTIMIZER_HIDE_VAR(var)   asm (";" : "=r"(var) : "0"(var))
#define asm_volatile_goto(x)   do { asm goto(x); asm (";"); } while (0x0)
#if IS_GNUC
#   if IS_NOT_ASSEMBLER  // Move compatibility symbols into a special section
#      define compat_text_section   __attribute__((__section__(".text.compat")))
#      define compat_data_section   __attribute__((__section__(".data.compat")))
#   else
#      define compat_text_section   .section ".text.compat", "ax";
#      define compat_data_section   .section ".data.compat", "aw";
#   endif
#   ifdef SHARED
/** When building a shared library, make the set section writable, because it will need to be relocated at run time anyway */
#      define _elf_set_element(set, symbol)   static const void* __elf_set_ ## set ## _element_ ## symbol ## __ __attribute__((__section__(#set), __used__)) = &(symbol)
#   else
/** When building a shared library, make the set section writable, because it will need to be relocated at run time anyway */
#      define _elf_set_element(set, symbol)   static const void* const __elf_set_ ## set ## _element_ ## symbol ## __ __attribute__((__section__(#set), __used__)) = &(symbol)
#   endif
/** Marker used for indirection function symbols */
#   define libc_ifunc(name, expr)   extern void* name ## _ifunc (void) asm (#name); void* name ## _ifunc (void) { INIT_ARCH (); typeof(name)* res = expr; return res; } asm (".type " #name ", %gnu_indirect_function");
/** The body of the function is supposed to use __get_cpu_features which will, if necessary, initialize the data first */
#   define libm_ifunc(name, expr)   extern void* name ## _ifunc (void) asm (#name); void* name ## _ifunc (void) { typeof(name)* res = expr; return res; } asm (".type " #name ", %gnu_indirect_function");
#   define tls_model_ie   __attribute__((__tls_model__("initial-exec")))
#   define attr_relro   __attribute__((__section__(".data.rel.ro")))
/** Make `symbol`, which is in the text segment, an element of `set` */
#   define text_set_element(set, symbol)   _elf_set_element(set, symbol)
/** Make `symbol`, which is in the data segment, an element of `set` */
#   define data_set_element(set, symbol)   _elf_set_element(set, symbol)
/** Make `symbol`, which is in the bss segment, an element of `set` */
#   define bss_set_element(set, symbol)   _elf_set_element(set, symbol)
#else  // Not GNU-GCC
#   define compat_text_section
#   define compat_data_section
#   define _elf_set_element(set, symbol)
#   define libc_ifunc(name, expr)
#   define libm_ifunc(name, expr)
#   define tls_model_ie
#   define attr_relro
#   define text_set_element(set, symbol)
#   define data_set_element(set, symbol)
#   define bss_set_element(set, symbol)
#endif
#if IS_NOT_ASSEMBLER
#   define link_warning(sym, msg)   asm (".section .gnu.warning." sym "\n\t.string \"" msg "\"\n\t.previous");
#else
#   define link_warning(sym, msg)   .section .gnu.warning. ## sym ; .string msg ; .previous
#endif
#if (defined(__MINGW_USE_UNDERSCORE_PREFIX) && (__MINGW_USE_UNDERSCORE_PREFIX == 1))
#   define __MINGW_IMP_SYMBOL(sym)   _imp__ ## sym
#   define __MINGW_USYMBOL(sym)   _ ## sym
#   define __MINGW_LSYMBOL(sym)   sym
#else
#   define __MINGW_IMP_SYMBOL(sym)   __imp_ ## sym
#   define __MINGW_USYMBOL(sym)   sym
#   define __MINGW_LSYMBOL(sym)   _ ## sym
#endif
#define HIDDEN(x)   _libc_ ## x
/** Expands to the internal, hidden name of a cancellation wrapper */
#define CANCEL(x)   _libc_ ## x ## _cancel
/** Expands to the internal, hidden name of a non-cancellation wrapper */
#define WRAP(x)   _libc_ ## x ## _wrap
#define HIDDEN_STRING(x)   "_libc_" __STRING(x)
#define WRAP_STRING(x)   "_libc_" __STRING(x) "_wrap"
/** Symbols used both internally and externally; This makes the compiler convert use of x to use _libc_x instead */
#define PROTO_NORMAL(x)   __dso_hidden typeof(x) x asm (HIDDEN_STRING(x))
/** Marks the symbol as deprecated */
#define PROTO_STD_DEPRECATED(x)   deprecated typeof(x) x
/** Marks the symbol as both weak and deprecated */
#define PROTO_DEPRECATED(x)   deprecated weak_function typeof(x) x
/** Functions that have cancellation wrappers */
#define PROTO_CANCEL(x)   PROTO_NORMAL(x), CANCEL(x)
/** Functions that have wrappers */
#define PROTO_WRAP(x)   PROTO_NORMAL(x), WRAP(x)
/** Symbols that are exact clones of other symbols */
#define MAKE_CLONE(dst, src)   __dso_hidden __attribute__((__alias__(HIDDEN_STRING((src))))) typeof(dst) HIDDEN(dst)
/** Define or declare a datum with TYPE for KEY; CLASS can be `static` for keys used in only one source file, empty for global definitions, or `extern` for global declarations */
#define __libc_tsd_define(CLASS, TYPE, KEY)   CLASS thread_local TYPE __libc_tsd_ ## KEY tls_model_ie;
/** Return the `TYPE *` pointing to the current thread's datum for KEY */
#define __libc_tsd_address(TYPE, KEY)   (&__libc_tsd_ ## KEY)
/** Return the `TYPE` datum for KEY */
#define __libc_tsd_get(TYPE, KEY)   (__libc_tsd_ ## KEY)
/** Set the datum for KEY to VALUE */
#define __libc_tsd_set(TYPE, KEY, VALUE)   __libc_tsd_ ## KEY = (VALUE)
#define __libc_once_define(CLASS, NAME)   CLASS int NAME = 0
#define __libc_once(ONCE_CONTROL, INIT_FUNCTION)   do { if ((ONCE_CONTROL) == 0) { INIT_FUNCTION(); (ONCE_CONTROL) = 1; } } while (0x0)
#define __libc_once_get(ONCE_CONTROL)   ((ONCE_CONTROL) == 1)
#if (defined(SHARED) && (!defined(NO_HIDDEN)) && IS_STDC_ABOVE_C99)  // hidden
#   if IS_NOT_ASSEMBLER
#      define hidden_proto(name, ...)   __hidden_proto(name, , __GI_ ## name, __VA_ARGS__)
#      define hidden_tls_proto(name, ...)   __hidden_proto(name, thread_local, __GI_ ## name, __VA_ARGS__)
#      define __hidden_proto(name, thread, internal, ...)   extern thread typeof(name) name asm (__hidden_asmname(#internal)) __hidden_proto_hiddenattr(attrs);
#      define __hidden_asmname2(prefix, name)   #prefix name
#      define __hidden_asmname1(prefix, name)   __hidden_asmname2(prefix, name)
#      define __hidden_asmname(name)   __hidden_asmname1(__USER_LABEL_PREFIX__, name)
#      define __hidden_ver1(local, internal, name)   extern typeof(name) __EI_ ## name asm (__hidden_asmname(#internal)); extern typeof(name) __EI_ ## name __attribute__((__alias__(__hidden_asmname(#local))))
#      define hidden_ver(local, name)   __hidden_ver1(local, __GI_ ## name, name);
#      define hidden_data_ver(local, name)   hidden_ver(local, name)
#      define hidden_def(name)   __hidden_ver1(__GI_ ## name, name, name);
#      define hidden_data_def(name)   hidden_def(name)
#      define hidden_weak(name)   __hidden_ver1(__GI_ ## name, name, name) weak_function;
#      define hidden_data_weak(name)   hidden_weak(name)
#      define __hidden_nolink3(local, internal, vername)   asm (".symver " #internal ", " vername);
#      define __hidden_nolink2(local, internal, name, version)   extern typeof(name) internal __attribute__((__alias__(#local)));  __hidden_nolink3(local, internal, #name "@" #version)
#      define __hidden_nolink1(local, internal, name, version)   __hidden_nolink2(local, internal, name, version)
#      define hidden_nolink(name, lib, version)   __hidden_nolink1(__GI_ ## name, __EI_ ## name, name, VERSION_ ## lib ## _ ## version)
#      define HIDDEN_JUMPTARGET(name)   __GI_ ## name
#   else  // IS_ASSEMBLER
#      define hidden_def(name)   strong_alias(name, __GI_ ## name)
#      define hidden_weak(name)   hidden_def(name)
#      define hidden_ver(local, name)   strong_alias(local, __GI_ ## name)
#      define hidden_data_def(name)   strong_data_alias(name, __GI_ ## name)
#      define hidden_data_weak(name)   hidden_data_def(name)
#      define hidden_data_ver(local, name)   strong_data_alias(local, __GI_ ## name)
#      define HIDDEN_JUMPTARGET(name)   __GI_ ## name
#   endif
#else  // (defined(SHARED) && (!defined(NO_HIDDEN)))
#   if (IS_NOT_ASSEMBLER && IS_STDC_ABOVE_C99)
#      define hidden_proto(name, ...)
#      define hidden_tls_proto(name, ...)
#   else
#      define HIDDEN_JUMPTARGET(name)   JUMPTARGET(name)
#   endif
#   define hidden_weak(name)
#   define hidden_def(name)
#   define hidden_ver(local, name)
#   define hidden_data_weak(name)
#   define hidden_data_def(name)
#   define hidden_data_ver(local, name)
#   define hidden_nolink(name, lib, version)
#endif  // hidden
#if IS_ASSEMBLER
#   define HIDDEN_BUILTIN_JUMPTARGET(name)   HIDDEN_JUMPTARGET(name)
#else
#   define HIDDEN_BUILTIN_JUMPTARGET(name)
#endif
#ifdef HAVE_ASM_SET_DIRECTIVE
#   define libc_ifunc_hidden_def1(local, name)   asm (".globl " #local "\n\t" ".hidden " #local "\n\t" ".set " #local ", " #name);
#else
#   define libc_ifunc_hidden_def1(local, name)   asm (".globl " #local "\n\t" ".hidden " #local "\n\t" #local " = " #name);
#endif
#define libc_ifunc_hidden_def(name)   libc_ifunc_hidden_def1(__GI_ ## name, name)
#ifdef HAVE_ASM_PREVIOUS_DIRECTIVE
#   define __make_section_unallocated(section_string)   asm (".section " section_string "\n\t.previous");
#elif defined(HAVE_ASM_POPSECTION_DIRECTIVE)
#   define __make_section_unallocated(section_string)   asm (".pushsection " section_string "\n\t.popsection");
#else
#   define __make_section_unallocated(section_string)
#endif
#if (ARCHX86 && (CPU_AVX || CPU_SSE2AVX))
#   define MOVD   "vmovd"
#   define MOVQ   "vmovq"
#   define STMXCSR   "vstmxcsr"
#   define LDMXCSR   "vldmxcsr"
#else
#   define MOVD   "movd"
#   define MOVQ   "movq"
#   define STMXCSR   "stmxcsr"
#   define LDMXCSR   "ldmxcsr"
#endif
#if (defined(ARCHX86) && IS_WORDSIZE_64)
#   define STOS   "stosq"
#   define FD_ZERO_STOS   "stosq"
#elif (defined(ARCHX86) && IS_WORDSIZE_32)
#   define STOS   "stosl"
#   define FD_ZERO_STOS   "stosl"
#endif
#if (defined(ARCHI386) && defined(_I386MACH_DISABLE_HW_INTERRUPTS))
#   define __CLI   cli
#   define __STI   sti
#else
#   define __CLI
#   define __STI
#endif

/** @} */  // }


#endif  // ATTRIBUTES_H


/* ALIGNMENT ATTRIBUTES */


#if (!(defined(ALIGNMENT_ATTRIBUTES_H) || defined(_ALIGNMENT_ATTRIBUTES_H) || defined(_ALIGNMENT_ATTRIBUTES_H_)))
#define ALIGNMENT_ATTRIBUTES_H   (1)
#define _ALIGNMENT_ATTRIBUTES_H   (1)
#define _ALIGNMENT_ATTRIBUTES_H_   (1)


#if ((!defined(SUPPORTS_ALIGN_SPECIFIER)) && (defined(__IBM__ALIGN) || IS_GNUC || defined(COMPILER_ILEC)))
#   define SUPPORTS_ALIGN_SPECIFIER   1
#elif (!defined(SUPPORTS_ALIGN_SPECIFIER))
#   define SUPPORTS_ALIGN_SPECIFIER   0
#endif


/** @defgroup Alignment_Attributes Macros for specifying alignment of data-structures
@{ */  // (FB){

/** @def attr_packed
Pack the data-structure instead of aligning */
/** @def aligned
Align the data to the specified number of bytes */
/** @def align1
Align the data to one byte */
/** @def align2
Align the data to two bytes (short int) */
/** @def align128
Align the data to 128 bytes */
/** @def align512
Align the data to 512 bytes */
#if (defined(COMPILER_MICROSOFT) && IS_NOT_GNUC)
#   define attr_packed
#   define attr_mspacked
#   define attr_gccpacked
#   define aligned(x)   __declspec(align((x)))
#   define auto_align
#   define align1   __declspec(align(1))
#   define align2   __declspec(align(2))
#   define align4   __declspec(align(4))
#   define align8   __declspec(align(8))
#   define align16   __declspec(align(16))
#   define align32   __declspec(align(32))
#   define align64   __declspec(align(64))
#   define align128   __declspec(align(128))
#   define align256   __declspec(align(256))
#   define align512   __declspec(align(512))
#   define align1024   __declspec(align(1024))
#   define __section(x)
#elif defined(LINTER_LINT)
#   define attr_packed
#   define attr_mspacked
#   define attr_gccpacked
#   define aligned(x)
#   define auto_align
#   define align1
#   define align2
#   define align4
#   define align8
#   define align16
#   define align32
#   define align64
#   define align128
#   define align256
#   define align512
#   define align1024
#   define __section(x)
#elif (IS_GNUC || defined(COMPILER_PCC))
#   define attr_packed   __attribute__((__packed__))
#   define attr_mspacked   __attribute__((__packed__, __ms_struct__))
#   define attr_gccpacked   __attribute__((__packed__, __gcc_struct__))
#   ifndef aligned
#      define aligned(x)   __attribute__((__aligned__((x))))
#   endif
#   define auto_align   __attribute__((__aligned__))
#   define align1   __attribute__((__aligned__(1)))
#   define align2   __attribute__((__aligned__(2)))
#   define align4   __attribute__((__aligned__(4)))
#   define align8   __attribute__((__aligned__(8)))
#   define align16   __attribute__((__aligned__(16)))
#   define align32   __attribute__((__aligned__(32)))
#   define align64   __attribute__((__aligned__(64)))
#   define align128   __attribute__((__aligned__(128)))
#   define align256   __attribute__((__aligned__(256)))
#   define align512   __attribute__((__aligned__(512)))
#   define align1024   __attribute__((__aligned__(1024)))
#   define __section(x)   __attribute__((__section__((x))))
#else
#   define attr_packed
#   define attr_mspacked
#   define attr_gccpacked
#   define aligned(x)
#   define auto_align
#   define align1
#   define align2
#   define align4
#   define align8
#   define align16
#   define align32
#   define align64
#   define __section(x)
#endif


// ALIGNMENT BY DATATYPE

#define align_short   aligned(ALIGN_OF_SHORT)
#define align_int   aligned(ALIGN_OF_INT)
#define align_int64   aligned(ALIGN_OF_INT64)
#define align_long   aligned(ALIGN_OF_LONG)
#define alignSF   aligned(ALIGN_OF_FLOAT)
#define align_flt   aligned(ALIGN_OF_FLOAT)
#define alignDF   aligned(ALIGN_OF_DOUBLE)
#define align_dbl   aligned(ALIGN_OF_DOUBLE)
#define alignXF   alignDF
#define alignTF   aligned(ALIGN_OF_DOUBLE * 2)
#if SUPPORTS_LONG_DOUBLE
#   define align_ldbl   ATTR_ALIGN_TO(long double)
#else
#   define align_ldbl
#endif
#define align_ptr   aligned(ALIGN_OF_PTR)


// ALIGNMENT ALIASES

#ifndef _MM_ALIGN4
#   define _MM_ALIGN4   align4
#endif
#ifndef _MM_ALIGN8
#   define _MM_ALIGN8   align8
#endif
#ifndef _MM_ALIGN16
#   define _MM_ALIGN16   align16
#endif
#ifndef _MM_ALIGN32
#   define _MM_ALIGN32   align32
#endif
#ifndef _MM_ALIGN64
#   define _MM_ALIGN64   align64
#endif

/** @} */  // }


#endif  // ALIGNMENT_ATTRIBUTES_H


/* PRAGMAS */


#if (!(defined(PRAGMAS_H) || defined(_PRAGMAS_H_)))
#define PRAGMAS_H   (1)
#define _PRAGMAS_H_   (1)


#if (defined(COMPILER_CLANG) && IS_NOT_LINTER)
/** Push diagnostic state */
#   define DIAG_PUSH   _Pragma("clang diagnostic push")
/** Pop diagnostic state */
#   define DIAG_POP   _Pragma("clang diagnostic pop")
/** Ignore the specified diagnostic option */
#   define DIAG_IGNORE(_option)   _Pragma(ISTRINGIFY(clang diagnostic ignored _option))
#   define IGNORE_WCAST_ALIGN   _Pragma("clang diagnostic ignored \"-Wcast-align\"")
#   define IGNORE_WFORMAT_NONLITERAL   _Pragma("clang diagnostic ignored \"-Wformat-nonliteral\"")
#   define IGNORE_WMISSING_PROTOTYPES   _Pragma("clang diagnostic ignored \"-Wmissing-prototypes\"")
#   define IGNORE_WPADDED   _Pragma("clang diagnostic ignored \"-Wpadded\"")
#   define IGNORE_WOVERLENGTH_STRINGS   _Pragma("clang diagnostic ignored \"-Woverlength-strings\"")
/** Ignore shadowed functions */
#   define IGNORE_WSHADOW   _Pragma("clang diagnostic ignored \"-Wshadow\"")
#   define IGNORE_WSTACK_PROTECTOR   _Pragma("clang diagnostic ignored \"-Wstack-protector\"")
/** Enable warning flags for missing prototypes, shadowed functions, and unused functions */
#   define DIAG_FUNCTIONS   _Pragma("clang diagnostic error \"-Wmissing-prototypes\"") \
	_Pragma("clang diagnostic error \"-Wshadow\"") \
	_Pragma("clang diagnostic error \"-Wunused-function\"")
#elif (defined(COMPILER_GNU_GCC) && IS_NOT_LINTER)
/** Push diagnostic state */
#   define DIAG_PUSH   _Pragma("GCC diagnostic push")
/** Pop diagnostic state */
#   define DIAG_POP   _Pragma("GCC diagnostic pop")
/** Ignore the specified diagnostic option */
#   define DIAG_IGNORE(_option)   _Pragma(ISTRINGIFY(GCC diagnostic ignored _option))
#   define IGNORE_WCAST_ALIGN   _Pragma("GCC diagnostic ignored \"-Wcast-align\"")
#   define IGNORE_WFORMAT_NONLITERAL   _Pragma("GCC diagnostic ignored \"-Wformat-nonliteral\"")
#   define IGNORE_WMISSING_PROTOTYPES   _Pragma("GCC diagnostic ignored \"-Wmissing-prototypes\"")
#   define IGNORE_WPADDED   _Pragma("GCC diagnostic ignored \"-Wpadded\"")
#   define IGNORE_WOVERLENGTH_STRINGS   _Pragma("GCC diagnostic ignored \"-Woverlength-strings\"")
/** Ignore shadowed functions */
#   define IGNORE_WSHADOW   _Pragma("GCC diagnostic ignored \"-Wshadow\"")
#   define IGNORE_WSTACK_PROTECTOR   _Pragma("GCC diagnostic ignored \"-Wstack-protector\"")
/** Enable warning flags for missing prototypes, shadowed functions, and unused functions */
#   define DIAG_FUNCTIONS   _Pragma("GCC diagnostic error \"-Wmissing-prototypes\"") \
	_Pragma("GCC diagnostic error \"-Wshadow\"") \
	_Pragma("GCC diagnostic error \"-Wunused-function\"")
#else
#   define DIAG_FUNCTIONS   /*@i@*/
#   define DIAG_IGNORE(_option)   /*@i@*/
#   define DIAG_POP   /*@i@*/
#   define DIAG_PUSH   /*@i@*/
#   define IGNORE_WCAST_ALIGN   /*@i@*/
#   define IGNORE_WFORMAT_NONLITERAL   /*@i@*/
#   define IGNORE_WMISSING_PROTOTYPES   /*@i@*/
#   define IGNORE_WOVERLENGTH_STRINGS   /*@i@*/
#   define IGNORE_WPADDED   /*@i@*/
#   define IGNORE_WSHADOW   /*@i@*/
#   define IGNORE_WSTACK_PROTECTOR   /*@i@*/
#endif


#endif  // PRAGMAS_H


/* BOOLEAN DATATYPE (<stdbool.h>) */


#if (!(defined(__bool_true_false_are_defined) || defined(STDBOOL_H) || defined(__STDBOOL_H) || defined(_BOOL_H) || defined(_DEF_WINBOOL_) || defined(_BOOLEAN_H)))  // http://www.cplusplus.com/reference/cstdbool/ & http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdbool.h.html
#define __bool_true_false_are_defined   (1)
#define STDBOOL_H   (1)
#define __STDBOOL_H   (1)
#define __STDBOOL_H_   (1)
#define _BOOL_H   (1)
#define _BOOLEAN_H   (1)
#define _DEF_WINBOOL_   (1)


/** @def bool
Boolean Datatype */
#if IS_LINTER
#   define _Bool   int
#   define bool   int
#elif IS_STDC_BELOW_C99
#   define _Bool   int
#   define bool   int
#elif IS_NOT_CPLUSPLUS
#   define bool   _Bool
#endif
#if (!(defined(BOOL) || IS_OBJ_C))
/** Support Objective-C-Style "BOOL" datatype */
#   define BOOL   bool
/** Objective-C false boolean constant */
#   define __objc_no   ((bool)0)
/** Objective-C true boolean constant */
#   define __objc_yes   ((bool)1)
#endif
/** MacOS historic boolean datatype */
typedef unsigned char   Boolean;
/** Mach-style boolean datatype */
#define boolean_t   bool
#define MACH_MSG_TYPE_BOOLEAN   bool
/** Windows boolean datatype */
typedef int   WINBOOL;
#define PRBool   WINBOOL
/** Windows boolean pointer datatype */
typedef WINBOOL*   PBOOL;
/** Windows boolean pointer datatype */
typedef WINBOOL*   LPBOOL;
/** Use PRPackedBool within structs where bitfields are not desirable but minimum and consistant overhead matters */
typedef unsigned char   PRPackedBool;
/** Status code used by some routines that have a single point of failure or special status return */
typedef enum PRStatus_enum { PR_FAILURE = -1, PR_SUCCESS = 0 }   PRStatus;
typedef enum PRTruth_enum { PR_FALSE = 0, PR_TRUE = 1 }   PRTruth;
typedef enum truth_enum { Unknown = -1, False = 0, True = 1, Sometimes = 2, Depends = 3 }   truth;


#define no   ((bool)0)
#define NO   no
#define NOPE   no
#define yes   ((bool)1)
#define YES   yes
#ifndef NOT
#   define NOT(expr)   (!(expr))
#endif
#ifndef false
#   define false   ((bool)0)
#endif
#ifndef FALSE
#   define FALSE   ((bool)0)
#endif
#ifndef _FALSE
#   define _FALSE   ((bool)0)
#endif
#ifndef true
#   define true   ((bool)1)
#endif
#ifndef TRUE
#   define TRUE   ((bool)1)
#endif
#ifndef _TRUE
#   define _TRUE   ((bool)1)
#endif
#ifndef objc_yes
#   define objc_yes   __objc_yes
#endif
#ifndef objc_no
#   define objc_no   __objc_no
#endif


#endif  // STDBOOL_H


/* NORETURN (<stdnoreturn.h>) */


#if (!(defined(STDNORETURN_H) || defined(__STDNORETURN_H) || defined(__STDNORETURN_H_) || defined(__noreturn_is_defined)))
#define STDNORETURN_H   (1)
#define _STDNORETURN_H   (1)
#define __STDNORETURN_H   (1)
#define __STDNORETURN_H_   (1)
#define __noreturn_is_defined   (1)


/** @defgroup NoReturn Function declaration indicating that the function does not return by executing the return statement or by reaching the end of the function body
@{ */  // (FB){

#if (IS_STDC_BELOW_C11 && IS_GNUC)
#   define noreturn   __attribute__((__noreturn__))
#   define _Noreturn   __attribute__((__noreturn__))
#elif (defined(COMPILER_MICROSOFT) && (defined(_MSC_VER) && (_MSC_VER >= 1200)))
#   define _Noreturn   __declspec(noreturn)
#elif (defined(LINTER_CLANG) && __has_extension(attribute_analyzer_noreturn))
#   define noreturn   __attribute__((analyzer_noreturn))
#   define _Noreturn   __attribute__((analyzer_noreturn))
#elif IS_LINTER
#   define _Noreturn   /*@noreturn@*/
#   define noreturn   /*@noreturn@*/
#else
#   define noreturn   _Noreturn
#endif  // noreturn
#define Noreturn   _Noreturn
#define __noreturn   _Noreturn
#define DECLSPEC_NORETURN   _Noreturn
#define PR_PRETEND_NORETURN   _Noreturn

/** @} */  // }


#endif  // STDNORETURN_H


/* STRING MACROS */


#ifndef STRING_MACROS_H
#define STRING_MACROS_H   (1)


// PROGRAM NAME MACROS

#if ((!defined(getprogname)) && defined(PROGRAM_NAME))
#   define getprogname()   PROGRAM_NAME
#elif ((!defined(getprogname)) && (!defined(PROGRAM_NAME)))
#   define getprogname()   "UNAMED_PROGRAM\0"
#endif
/*@-readonlytrans@*/
static const char* __progname = NULL;
static const UNUSED char* progname = NULL;
static const UNUSED char* program_name = NULL;
static const UNUSED char* __progname_full = NULL;
/*@-readonlytrans@*/
static const UNUSED char* program_invocation_name = getprogname();
/*@=readonlytrans@*/
#define program_invocation_short_name   program_invocation_name
#define __IDSTRING(name, str)   static const UNUSED char name[] = str
#ifndef __COPYRIGHT
#   define __COPYRIGHT(str)   __IDSTRING(copyright, str)
#endif
#ifndef __PROJECT_VERSION
#   define __PROJECT_VERSION(str)   __IDSTRING(__MODULE_VERSION__, str)
#endif
#ifndef __FBSDID
#   define __FBSDID(str)   __IDSTRING(fbsdid, str)
#endif
#undef __KERNEL_RCSID
#if (defined(_KERNEL) && defined(NO_KERNEL_RCSIDS))
#   define __KERNEL_RCSID(name, str)
#else
#   define __KERNEL_RCSID(name, str)   __IDSTRING(name, str)
#endif
#ifndef __RCSID
#   define __RCSID(str)   __IDSTRING(rcsid, str)
#endif
#ifndef __SCCSID
#   define __SCCSID(str)   __IDSTRING(sccsid, str)
#endif


// LOCATION MACROS

#ifndef __func__
#   if (IS_CPLUSPLUS && IS_GNUC)
#      define __func__   __PRETTY_FUNCTION__
#   else
#      if IS_STDC99
#         define __func__   __FUNCTION__
#      elif (IS_GNUC || defined(COMPILER_MICROSOFT))
#         define __func__   __FUNCTION__
#      else
#         define __func__   ((const char*)0)
#      endif
#   endif
#endif
#if IS_GNUC
/** String identifier for the current code position */
#   define CODE_POS   __FILE__ ":" S(__LINE__) ":" __PRETTY_FUNCTION__ "()"
#   define GNUC_FUNCTION   __FUNCTION__
#   define GNUC_PRETTY_FUNCTION   __PRETTY_FUNCTION__
/** Current function identifier */
#   define FUNC_NAME   ((const char*)(__PRETTY_FUNCTION__))
#elif IS_STDC11
/** String identifier for the current code position */
#   define CODE_POS   __FILE__ ":" S(__LINE__)
#   define GNUC_FUNCTION   ""
#   define GNUC_PRETTY_FUNCTION   ""
/** Current function identifier */
#   define FUNC_NAME   ((const char*)(__func__))
#else
#   error   "This library requires Standard C version 2011 or newer!"
#endif
#define WHERESTR   "[file %s, line %d]: "
#if (defined(__FILE__) && defined(__LINE__))
#   define WHEREARG   __FILE__, __LINE__
#   define CODE_LOCATION   __BASE_FILE__ ":" __FILE__ ":" S(__LINE__)
#endif
/** Compile Time Assertion */
#define __CTASSERT1(x, y, z)   typedef char y ## z[(x) ? 1 : (-1)] UNUSED
/** Compile Time Assertion */
#define __CTASSERT0(x, y, z)   __CTASSERT1(x, y, z)
#ifdef __COUNTER__
/** Compile Time Assertion */
#   define __CTASSERT(x)   __CTASSERT0(x, __ctassert, __COUNTER__)
#else
/** Compile Time Assertion */
#   define __CTASSERT99(x, y, z)   __CTASSERT0(x, CONCAT_X(__ctassert, y), CONCAT_X(_, z))
/** Compile Time Assertion */
#   define __CTASSERT(x)   __CTASSERT99(x, __INCLUDE_LEVEL__, __LINE__)
#endif


#endif  // STRING_MACROS_H


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
typedef __builtin_va_list   va_list;
#elif defined(__VMS__)
/** Type to hold information about variable arguments */
typedef char*   va_list;
#else
#   ifdef ARCHX86_64
typedef struct va_struct {
	uint32_t gp_offset;  //!< Holds the offset in bytes from `reg_save_area` to the place where the next available general purpose argument register is saved. If all the argument registers are exhausted, then it is set to the value `48`.
	uint32_t fp_offset;  //!< Holds the offset in bytes from `reg_save_area` to the place where the next available ﬂoating point argument register is saved. If all the argument registers are exhausted, then it is set to the value `304`.
	void* overflow_arg_area;  //!< Pointer used to fetch arguments passed on the stack. It is initialized with the address of the ﬁrst argument passed on the stack (if any). It is always updated to point to the start of the next argument on the stack.
	void* reg_save_area;  //!< Pointer to the start of the register save area
} va_list[1];
#   else
typedef uintptr_t   va_list;
#   endif
#endif
#define __GNUC_VA_LIST   1
#undef __need___va_list
#define __DEFINED___isoc_va_list   (1)
#define __DEFINED_va_list   (1)
/** Type to hold information about variable arguments */
#define __gnuc_va_list   va_list
/** Type to hold information about variable arguments */
#define p9va_list   __gnuc_va_list
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
#define va_arg(v, datatype)   __builtin_va_arg(v, datatype)

#if IS_GNUC
#   define __builtin_stdarg_start(v, argnum)   __builtin_va_start((v), (argnum))
#elif (!defined(__builtin_va_start))
#   define __builtin_va_start(v, argnum)   __builtin_stdarg_start((v), (argnum))
#endif
/** Initialize a variable argument list */
#define va_start(v, argnum)   __builtin_va_start((v), (argnum))
/** Initialize a variable argument list */
#define stdarg_start(v, argnum)   __builtin_va_start((v), (argnum))
/** Initialize a variable argument list */
#define _stdarg_start(v, argnum)   __builtin_va_start((v), (argnum))
/** Initialize a variable argument list */
#define _va_start(v, argnum)   __builtin_va_start((v), (argnum))
/** Initialize a variable argument list */
#define __va_start(v, argnum)   __builtin_va_start((v), (argnum))
/** Performs the appropriate actions to facilitate a normal return by a function that has used the va_list object to retrieve its additional arguments */
#define va_end(v)   __builtin_va_end((v))
/** Performs the appropriate actions to facilitate a normal return by a function that has used the va_list object to retrieve its additional arguments */
#define _va_end(v)   __builtin_va_end((v))
/** Performs the appropriate actions to facilitate a normal return by a function that has used the va_list object to retrieve its additional arguments */
#define __va_end(v)   __builtin_va_end((v))


// VA_COPY

/** Copy variable argument list */
#define va_copy(dest, src)   (*(dest) = *(src))  // __builtin_va_copy((dest), (src))
/** Copy variable argument list */
#define __builtin_va_copy(dest, src)   (*(dest) = *(src))
/** Copy variable argument list */
#define _va_copy(dest, src)   (*(dest) = *(src))
/** Copy variable argument list */
#define __va_copy(dest, src)   (*(dest) = *(src))
/** Copy variable argument list */
#define gl_va_copy(dest, src)   (*(dest) = *(src))


// MSVC COMPATIBILITY

#ifndef __ms_va_list
#   if (defined(ARCHX86_64) && IS_GNUC)
#      define __ms_va_list   __builtin_ms_va_list
#      define __ms_va_start(list, arg)   __builtin_ms_va_start((list), (arg))
#      define __ms_va_end(list)   __builtin_ms_va_end((list))
#      define __ms_va_copy(dest, src)   __builtin_ms_va_copy((dest), (src))
#   else
#      define __ms_va_list   va_list
#      define __ms_va_start(list, arg)   va_start((list), (arg))
#      define __ms_va_end(list)   va_end((list))
#      define __ms_va_copy(dest, src)   (*(dest) = *(src))
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


/* DATATYPE DIAGNOSTICS */


#if IS_NOT_LINTER
#   if lacks_feature(c_atomic)
#      error   "Atomics are required to use this library!"
#   endif
_Static_assert((('A' + 0x20 == 'a') && (' ' == 32)), "Invalid character encoding (must be UTF-8)!");
_Static_assert((SIZEOF_CHAR == 1), "`char` datatype is not 8-bits!");
_Static_assert((((SIZEOF_CHAR * 8) == NBBY) && ((sizeof(char) * 8) == NBBY)), "A byte is not 8-bits on this platform!");
_Static_assert(((SIZEOF_INT == 4) && (BYTES_PER_INT == 4) && (BITS_PER_INT == 32)), "`int` datatype is not 32-bits!");
_Static_assert(((SIZEOF_LONG == BYTES_PER_LONG) && (BITS_PER_LONG == (BYTES_PER_LONG * NBBY))), "`long` datatype has two different sizes set in the macros!");
_Static_assert(((SIZEOF_LONG_LONG == 8) && (BYTES_PER_LONG_LONG == 8) && (BITS_PER_LONG_LONG == 64)), "`long long` datatype is not 64-bits!");
_Static_assert(((SIZEOF_FLOAT == 4) && (BITS_PER_FLOAT == 32)), "`float` datatype is not 32-bits!");
_Static_assert(((SIZEOF_DOUBLE == 8) && (BITS_PER_DOUBLE == 64)), "`double` datatype is not 64-bits!");
_Static_assert(((SIZEOF_DECIMAL64 == 8) && (BITS_PER_DECIMAL64 == 64)), "`decimal64` datatype is not 64-bits!");
_Static_assert((SIZEOF_INT < SIZEOF_LONG_LONG), "Improperly set `int` and `long long` datatype sizes!");
_Static_assert((SIZEOF_FLOAT < SIZEOF_DOUBLE), "Improperly set `float` and `double` datatype sizes!");
_Static_assert((SIZEOF_DECIMAL32 < SIZEOF_DECIMAL64), "Improperly set `decimal32` and `decimal64` datatype sizes!");
_Static_assert((\
	(SCHAR_MAX == 127) && (SCHAR_MIN == -128) && \
	(INT8_MAX == 127) && (INT8_MIN == -128) && \
	(INT16_MAX == 32767) && (INT16_MIN == -32768) && \
	(INT32_MAX == 2147483647) && (INT32_MIN == -2147483648) && \
	(INT64_MAX == 9223372036854775807) && (INT64_MIN == ((-__INT64_MAX__) - 1)) && \
	(UINT8_MAX == 255) && (UINT16_MAX == 65535) && \
	(UINT32_MAX == 4294967295) && (UINT64_MAX == 18446744073709551615ULL) && \
	(SCHAR_MAX == INT8_MAX) && (SHRT_MAX == INT16_MAX) \
	), \
	"Invalid datatype ranges (minimums & maximums)!" \
);
_Static_assert((\
	(INT_MAX <= LONG_MAX) && (LONG_MAX <= LONGLONG_MAX) && \
	(__LONG_MAX__ == LONG_MAX) && (__LONG_LONG_MAX__ == LONGLONG_MAX) && \
	(((SIZEOF_LONG == 8) && (LONG_MIN == INT64_MIN) && (LONG_MAX == INT64_MAX)) || \
	((SIZEOF_LONG == 4) && (LONG_MIN == INT32_MIN) && (LONG_MAX == INT32_MAX))) && \
	(((SIZEOF_LONG == 8) && (ULONG_MAX == UINT64_MAX)) || \
	((SIZEOF_LONG == 4) && (ULONG_MAX == UINT32_MAX))) && \
	(((SIZEOF_LONG_LONG == 8) && (LONG_LONG_MIN == INT64_MIN) && (LONG_LONG_MAX == INT64_MAX)) || \
	((SIZEOF_LONG_LONG == 4) && (LONG_LONG_MIN == INT32_MIN) && (LONG_LONG_MAX == INT32_MAX))) && \
	(((SIZEOF_LONG_LONG == 8) && (ULLONG_MAX == UINT64_MAX)) || \
	((SIZEOF_LONG_LONG == 4) && (ULLONG_MAX == UINT32_MAX))) \
	), \
	"Invalid `long` & `long long` datatype ranges (minimums & maximums)!" \
);
_Static_assert((\
	(INT_LEAST8_MIN == INT8_MIN) && (INT_LEAST16_MIN == INT16_MIN) && \
	(INT_LEAST32_MIN == INT32_MIN) && (INT_LEAST64_MIN == INT64_MIN) && \
	(INT_LEAST8_MAX == INT8_MAX) && (INT_LEAST16_MAX == INT16_MAX) && \
	(INT_LEAST32_MAX == INT32_MAX) && (INT_LEAST64_MAX == INT64_MAX) \
	), \
	"Invalid \"least\" datatype ranges (minimums & maximums)!" \
);
#   if SUPPORTS_STDFIX
_Static_assert((\
	(__SFRACT_MIN__ == -0.5HR-0.5HR) && (__SFRACT_MAX__ == 0x7fP-7HR) && \
	(__SFRACT_EPSILON__ == 0x1P-7HR) && (SFRACT_EPSILON == __SFRACT_EPSILON__) && \
	(USFRACT_MAX == 0xffP-8UHR) && (LFRACT_EPSILON == 0x1P-31LR) && \
	(LLFRACT_MIN == -0.5LLR-0.5LLR) && (ULLFRACT_MAX == 0xffffffffffffffffP-64ULLR) && \
	(__SACCUM_MIN__ == -0x1P7HK-0x1P7HK) && (__SACCUM_MAX__ == 0x7fffP-7HK) && \
	(__SACCUM_EPSILON__ == 0x1P-7HK) && (SACCUM_EPSILON == __SACCUM_EPSILON__) && \
	(USACCUM_MAX == 0xffffP-8UHK) && (LACCUM_EPSILON == 0x1P-31LK) && \
	(LLACCUM_MIN == -0x1P31LLK-0x1P31LLK) && (ULLACCUM_MAX == 0xffffffffffffffffP-32ULLK) \
	), \
	"Invalid accum and fract datatype ranges (minimums, maximums, and epsilons)!" \
);
#   endif
#endif


#ifdef COMPILER_GNU_GCC  // Hard-code some optimizations
#   pragma GCC optimize (3)
#   pragma GCC optimize ("unroll-loops")
/** ivdep: Vectorize loops */
#   define __IVDEP__
#elif defined(COMPILER_CLANG)
#   pragma clang optimize on
#elif defined(COMPILER_INTEL)
#   pragma intel optimization_level 3
#endif

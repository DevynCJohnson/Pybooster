// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file MACROS.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Standard Macros Header with AT&T-style Assembly
@version 2017.07.15

@section DESCRIPTION
This file defines various datatypes, macros functions, names, and tests.
Substitutes for most standard C libraries are also provided.
 - http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/contents.html
This is the primary MACROS*.h file, and this one should be included.
The other MACROS*.h files will automatically be included.

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

@section Supports
Compilers:
 - GNU-GCC
 - Clang & LLVM
Architectures:
 - x86-64
Operating Systems:
 - Linux

@section Standard C Library
 - <assert.h>
 - <complex.h>
 - <ctype.h>
 - <errno.h>
 - <fenv.h>
 - <float.h>
 - <inttypes.h>
 - <iso646.h>
 - <limits.h>
 - <locale.h>
 - <math.h>
 - <setjmp.h>
 - <signal.h>
 - <stdalign.h>
 - <stdarg.h>
 - <stdatomic.h>
 - <stdbool.h>
 - <stddef.h>
 - <stdint.h>
 - <stdio.h>
 - <stdlib.h>
 - <stdnoreturn.h>
 - <string.h>
 - <tgmath.h>
 - <threads.h>
 - <time.h>
 - <uchar.h>
 - <wchar.h>
 - <wctype.h>

@section POSIX C Library
 - <aio.h>
 - <arpa/inet.h>
 - <assert.h>
 - <complex.h>
 - <cpio.h>
 - <ctype.h>
 - <dirent.h>
 - <dlfcn.h>
 - <errno.h>
 - <fcntl.h>
 - <fenv.h>
 - <float.h>
 - <fmtmsg.h>
 - <fnmatch.h>
 - <ftw.h>
 - <glob.h>
 - <grp.h>
 - <iconv.h>
 - <inttypes.h>
 - <iso646.h>
 - <langinfo.h>
 - <libgen.h>
 - <limits.h>
 - <locale.h>
 - <math.h>
 - <monetary.h>
 - <mqueue.h>
 - <ndbm.h>
 - <net/if.h>
 - <netdb.h>
 - <netinet/in.h>
 - <netinet/tcp.h>
 - <nl_types.h>
 - <poll.h>
 - <pthread.h>
 - <pwd.h>
 - <regex.h>
 - <sched.h>
 - <search.h>
 - <semaphore.h>
 - <setjmp.h>
 - <signal.h>
 - <spawn.h>
 - <stdarg.h>
 - <stdbool.h>
 - <stddef.h>
 - <stdint.h>
 - <stdio.h>
 - <stdlib.h>
 - <string.h>
 - <strings.h>
 - <stropts.h>
 - <sys/ipc.h>
 - <sys/mman.h>
 - <sys/msg.h>
 - <sys/resource.h>
 - <sys/select.h>
 - <sys/sem.h>
 - <sys/shm.h>
 - <sys/socket.h>
 - <sys/stat.h>
 - <sys/statvfs.h>
 - <sys/time.h>
 - <sys/times.h>
 - <sys/types.h>
 - <sys/uio.h>
 - <sys/un.h>
 - <sys/utsname.h>
 - <sys/wait.h>
 - <syslog.h>
 - <tar.h>
 - <termios.h>
 - <tgmath.h>
 - <time.h>
 - <trace.h>
 - <ulimit.h>
 - <unistd.h>
 - <utime.h>
 - <utmpx.h>
 - <wchar.h>
 - <wctype.h>
 - <wordexp.h>

@section BSD Library
 - <db.h>
 - <err.h>
 - <fts.h>
 - <sys/queue.h>
 - <sys/tree.h>
 - <vis.h>
 - <stdio.h>: fgetln()
 - <stdlib.h>: arc4random(), daemon(), radixsort()
 - <string.h>: strlcat() and strlcpy()

@section C++ STL
 - <array>
 - <deque>
 - <forward_list>
 - <list>
 - <map>
 - <queue>
 - <set>
 - <stack>
 - <unordered_map>
 - <unordered_set>
 - <vector>
 - <fstream>
 - <iomanip>
 - <ios>
 - <iosfwd>
 - <iostream>
 - <istream>
 - <ostream>
 - <sstream>
 - <streambuf>
 - <atomic>
 - <condition_variable>
 - <future>
 - <mutex>
 - <thread>
 - <algorithm>
 - <bitset>
 - <chrono>
 - <codecvt>
 - <complex>
 - <exception>
 - <functional>
 - <initializer_list>
 - <iterator>
 - <limits>
 - <locale>
 - <memory>
 - <new>
 - <numeric>
 - <random>
 - <ratio>
 - <regex>
 - <stdexcept>
 - <string>
 - <system_error>
 - <tuple>
 - <typeindex>
 - <typeinfo>
 - <type_traits>
 - <utility>
 - <valarray>

@section Linux API Headers
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

@section Other C Libraries
 - <reent.h> (Newlib)
 - <unctrl.h> (Newlib)

@section Standards & Features
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
 - IEC 559: Same as IEEE 754-1985
 - IEEE 754: Standard for floating-point computation
 - IEEE 854-1987: Standard for Radix-Independent Floating-Point Arithmetic
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
 - _REENTRANT: Select additionally reentrant object
 - _THREAD_SAFE: Same as _REENTRANT, often used by other systems
 - _FORTIFY_SOURCE: If above 0, additional security measures are defined (according to the level)

@section Set Specification
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
 - __USE_REENTRANT: Define reentrant/thread-safe *_r functions
 - __USE_FORTIFY_LEVEL: Additional security measures used, according to level

@section ANSI
The `-ansi` switch to the GNU C compiler, and standards conformance options such as `-std=c99`, define __STRICT_ANSI__. If none of these are defined, or if _DEFAULT_SOURCE is defined, the default is to have _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to 200809L, as well as enabling miscellaneous functions from BSD and SVID. If more than one of these are defined, they accumulate. For example __STRICT_ANSI__, _POSIX_SOURCE, and _POSIX_C_SOURCE together give you ISO C, 1003.1, and 1003.2, but nothing else.

@section Intel Intrinsics
 - __m64 - 64-bits; MMX register
 - __m128 - 4-float vector; SSE register
 - __m128d - 2-double vector; SSE register
 - __m128i - integers; SSE register
 - __m256 - 8-float vector; AVX/YMM register
 - __m256d - 4-double vector; AVX/YMM register
 - __m256i - integers; AVX/YMM register

@section GCC-Builtins
 - https://gcc.gnu.org/onlinedocs/gcc/Target-Builtins.html
 - https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
 - https://gcc.gnu.org/onlinedocs/gcc/Cilk-Plus-Builtins.html
 - https://gcc.gnu.org/onlinedocs/gcc/x86-Built-in-Functions.html

@section Helpful Terminal Commands
 - gcc -dM -E -x c /dev/null
 - gcc -march=haswell -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld -dM -E -x c /dev/null
 - clang -dM -E -x c /dev/null
 - llvm-gcc -dM -E -x c /dev/null
 - arm-linux-gnueabihf-gcc -march=armv6zk -mtune=arm1176jzf-s -mfloat-abi=hard -mlittle-endian -mfpu=vfp -marm -mtp=auto -dM -E -x c /dev/null
 - arm-linux-gnueabihf-gcc -mfp16-format=ieee -dM -E -x c /dev/null
 - i686-w64-mingw32-gcc -dM -E -x c /dev/null
 - hppa-linux-gnu-gcc -dM -E -x c /dev/null
 - mips-linux-gnu-gcc -dM -E -x c /dev/null
 - mipsel-linux-gnu-gcc -dM -E -x c /dev/null
 - powerpc-linux-gnu-gcc -dM -E -x c /dev/null
 - powerpc64le-linux-gnu-gcc -dM -E -x c /dev/null
 - s390x-linux-gnu-gcc -dM -E -x c /dev/null
 - sh4-linux-gnu-gcc -dM -E -x c /dev/null
 - x86_64-w64-mingw32-gcc -m64 -dM -E -x c /dev/null
 - strings `which gcc`
 - gcc --print-search-dirs
 - gcc --print-multiarch
 - pkg-config --cflags --libs cairo
 - pkg-config --cflags --libs pango
 - pkg-config --cflags --libs glib-2.0
 - pkg-config --cflags --libs gobject-2.0
 - pkg-config --cflags --libs gobject-introspection-1.0

@section Machine Modes
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
 - V4SI - Vector; 4 single integers
 - V8QI - Vector; 8 8-bit integers
 - BND32 - 32-bit pointer bound
 - BND64 - 64-bit pointer bound
 - word - Word-sized integer

@section Datamodels
 - "I" int type
 - "L" represents long type
 - "P" represents the pointer type

@section Datamodel Systems
 - IP16 Platforms: PDP-11 Unix
 - ILP32 Platforms: IBM370 and VAX Unix
 - ILP32LL/ILP32LL64 Platforms: Windows-32 and Convex
 - ILP64 Platforms: Solaris on SPARC64
 - LP64/I32LP64 Platforms: Solaris, Linux, BSD, OS X, and z/OS
 - LLP64/IL32P64 Platforms: Windows-64
 - SILP64 Platforms: Classic UNICOS

@section Datamodel Definitions
 - ILP32: int, long, pointer = 32;
 - LP32: short, int = 16; long, pointer = 32
 - ILP64: short = 16; int, long, long long, pointer = 64
 - LP64/I32LP64: short = 16; int = 32; long, long long, pointer = 64
 - LLP64/IL32P64/P64: short = 16; int, long = 32; long long, pointer = 64
 - SILP64: short, int, long, long long, pointer = 64

@section Datatype Info
 - __S<SIZE>_TYPE: signed
 - __U<SIZE>_TYPE: unsigned
 - 16: natural 16-bit type (always short)
 - 32: natural 32-bit type (always int)
 - 64: natural 64-bit type (long or long long)
 - LONG32: 32-bit type; traditionally long
 - WORD: natural type of WORDSIZE bits
 - LONGWORD: WORDSIZE bits; traditionally long
 - int is always 32 bits
 - long is always word/address size
 - long long is always 64 bits

@section Primary Fixed-point Datatypes
 - short _Fract
 - _Fract
 - long _Fract
 - short _Accum
 - _Accum
 - long _Accum

@section Saturating Fixed-point Datatypes
 - _Sat short _Fract
 - _Sat _Fract
 - _Sat long _Fract
 - _Sat short _Accum
 - _Sat _Accum
 - _Sat long _Accum

@section Accumulator Fixed-point Datatypes
 - short _Accum
 - _Accum
 - long _Accum
 - _Sat short Accum
 - _Sat _Accum
 - _Sat long Accum

@section Fixed-point Datatypes
 - short _Fract
 - _Fract
 - long _Fract
 - long long _Fract
 - unsigned short _Fract
 - unsigned _Fract
 - unsigned long _Fract
 - unsigned long long _Fract
 - _Sat short _Fract
 - _Sat _Fract
 - _Sat long _Fract
 - _Sat long long _Fract
 - _Sat unsigned short _Fract
 - _Sat unsigned _Fract
 - _Sat unsigned long _Fract
 - _Sat unsigned long long _Fract
 - short _Accum
 - _Accum
 - long _Accum
 - long long _Accum
 - unsigned short _Accum
 - unsigned _Accum
 - unsigned long _Accum
 - unsigned long long _Accum
 - _Sat short _Accum
 - _Sat _Accum
 - _Sat long _Accum
 - _Sat long long _Accum
 - _Sat unsigned short _Accum
 - _Sat unsigned _Accum
 - _Sat unsigned long _Accum
 - _Sat unsigned long long _Accum

@section Fixed-point Datatype Suffixes
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

@section Types of Numbers
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

@section Macros Documentation
 - feature_test_macros: http://man7.org/linux/man-pages/man7/feature_test_macros.7.html || execute "man feature_test_macros"
 - http://sourceforge.net/p/predef/wiki/Home/
 - https://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html
 - https://msdn.microsoft.com/en-us/library/b0084kay.aspx
 - http://clang.llvm.org/docs/LanguageExtensions.html

@section Cilk Documentation
 - https://www.cilkplus.org/
 - https://www.cilkplus.org/cilk-plus-tutorial
 - https://www.cilkplus.org/docs/doxygen/include-dir/
 - Intel Cilk Plus: https://software.intel.com/en-us/node/522579

@section Intel Documentation
 - Automatic Vectorization: https://software.intel.com/en-us/node/522569
 - Graphics Technology: https://software.intel.com/en-us/node/522438
 - High-Level Optimization (HLO): https://software.intel.com/en-us/node/522438
 - Intel Math Library: https://software.intel.com/en-us/node/522652
 - Interprocedural Optimization (IPO): https://software.intel.com/en-us/node/522666
 - OpenMP Support: https://software.intel.com/en-us/node/522678

@section Float-Point Documentation
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

@section Metric Units for Decimal Data Units
 - Value	Abbr	Name
 - 1000		kB		Kilobyte
 - 1000^2	MB		Megabyte
 - 1000^3	GB		Gigabyte
 - 1000^4	TB		Terabyte
 - 1000^5	PB		Petabyte
 - 1000^6	EB		Exabyte
 - 1000^7	ZB		Zettabyte
 - 1000^8	YB		Yottabyte

@section ISO/IEC 80000 Units for Binary Data Units
 - Value	Abbr	Name
 - 1024		KiB		Kibibyte
 - 1024^2	MiB		Mebibyte
 - 1024^3	GiB		Gibibyte
 - 1024^4	TiB		Tebibyte
 - 1024^5	PiB		Pebibyte
 - 1024^6	EiB		Exbibyte
 - 1024^7	ZiB		Zebibyte
 - 1024^8	YiB		Yobibyte

@section Floating-Point Constant Literals
 - 5.3876e4 = 53876
 - 4e-11 = 0.00000000004
 - 1e+5 = 100000
 - 7.321E-3 = 0.007321
 - 3.2E+4 = 32000
 - 0.5e-6 = 0.0000005
 - 0.45 = 0.45
 - 6.e10 = 60000000000
*/


/* DIAGNOSTICS */


#ifndef MACROS_DIAGNOSTICS_H
/** If defined, the macros diagnostics header is already included/present; the included macros tests to ensure that `int` is 4 bytes (32-bits) in size, the space character is 0x20 in ASCII hexadecimal, etc.; If a test fails, the compilation will stop and an error message will be provided */
#define MACROS_DIAGNOSTICS_H   (1)


#if (('a' != 97) || ('z' != 122) || ('A' != 65) || (' ' != 0x20))  // File encoding test
#   error   "Invalid character encoding (must be UTF-8)!"
#endif


// DATATYPE SIZES
_Static_assert((sizeof(char) == 1), "`char` datatype is not 8-bits!");
_Static_assert((sizeof(int) == 4), "`int` datatype is not 32-bits!");
_Static_assert((sizeof(float) == 4), "`float` datatype is not 32-bits!");
_Static_assert((sizeof(double) == 8), "`double` datatype is not 64-bits!");
_Static_assert(((sizeof(char*) == 4) || (sizeof(char*) == 8)), "The target system is not 32-bit or 64-bit!");


// DETERMINE CHARACTER-SET
#define HOST_CHARSET_UNKNOWN   0
#define HOST_CHARSET_ASCII   1
#define HOST_CHARSET_EBCDIC   2
#if ('\n' == 0xA && ' ' == 0x20 && '0' == 0x30 && 'A' == 0x41 && 'a' == 0x61 && '!' == 0x21)
#   define HOST_CHARSET   HOST_CHARSET_ASCII
#   define IS_HOST_CHARSET_ASCII   0x1
#   define IS_HOST_CHARSET_EBCDIC   0x0
#elif ('\n' == 0x15 && ' ' == 0x40 && '0' == 0xF0 && 'A' == 0xC1 && 'a' == 0x81 && '!' == 0x5A)
#   define HOST_CHARSET   HOST_CHARSET_EBCDIC
#   define IS_HOST_CHARSET_ASCII   0
#   define IS_HOST_CHARSET_EBCDIC   1
#   error   "The host character set is EBCDIC!"
#else
#   define HOST_CHARSET   HOST_CHARSET_UNKNOWN
#   error   "Unrecognized host character set!"
#endif


// OPTIMIZATION MACROS (__OPTIMIZE__)
#if (defined(SSO_OPT) && (!defined(OPT_SSO)))
#   define OPT_SSO   (1)
#endif
#if (defined(SPEED_OPT) && (!defined(OPT_SPEED)))
#   define OPT_SPEED   (1)
#endif
#if ((defined(OPT_SPEED) || defined(OPT_SSO)) && defined(OPT_ACCURACY))
#   error   "Cannot optimize for both speed and accuracy!"
#endif
#if (defined(OPT_SPEED) && (!defined(OPT_SSO)))
#   define OPT_SSO   (1)
#endif
#if ((defined(OPT_SIZE) || defined(PREFER_SIZE_OVER_SPEED) || defined(__OPTIMISE_SPACE)) && (!defined(__OPTIMIZE_SIZE__)))
#   define __OPTIMIZE_SIZE__   (2)
#elif ((defined(__OPTIMIZE_SIZE__) || defined(PREFER_SIZE_OVER_SPEED) || defined(__OPTIMISE_SPACE)) && (!defined(OPT_SIZE)))
#   define OPT_SIZE   (2)
#endif
#if ((defined(OPT_SPEED) || defined(OPT_SSO)) && defined(OPT_SIZE))
#   error   "Cannot optimize for both speed and size!"
#elif (defined(OPT_ACCURACY) && defined(OPT_SIZE))
#   error   "Cannot optimize for both accuracy and size!"
#endif
#if ((defined(OPT_SIZE) || defined(__OPTIMIZE_SIZE__)) && (!defined(SIZE_OPT)))
#   define SIZE_OPT   (1)
#endif
#if ((defined(__OPTIMIZE__) || defined(__OPTIMIZE_SIZE__) || defined(OPT_SIZE) || defined(PREFER_SIZE_OVER_SPEED)) && (!defined(OPTIMIZE_CODE)))
#   define OPTIMIZE_CODE   (1)
#endif
#if (defined(__OPTIMIZE__) && (!defined(IS_OPT_0)))
#   define IS_OPT_0   (__OPTIMIZE__ == 0)
#elif ((!defined(__OPTIMIZE__)) && (!defined(IS_OPT_0)))
#   define IS_OPT_0   (0)
#endif
#if (defined(__OPTIMIZE__) && (!defined(IS_OPT_1)))
#   define IS_OPT_1   (__OPTIMIZE__ == 1)
#elif ((!defined(__OPTIMIZE__)) && (!defined(IS_OPT_1)))
#   define IS_OPT_1   (0)
#endif
#if (defined(__OPTIMIZE__) && (!defined(IS_OPT_2)))
#   define IS_OPT_2   (__OPTIMIZE__ == 2)
#elif ((!defined(__OPTIMIZE__)) && (!defined(IS_OPT_2)))
#   define IS_OPT_2   (0)
#endif
#if (defined(__OPTIMIZE__) && (!defined(IS_OPT_OVER_0)) && (__OPTIMIZE__ > 0))
#   define IS_OPT_OVER_0   (1)
#elif ((!defined(__OPTIMIZE__)) && (!defined(IS_OPT_OVER_0)))
#   define IS_OPT_OVER_0   (0)
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


/* FILE SIGNATURES */


#ifndef FILE_SIGNATURE_MACROS_SEEN
/** This section defines constants for various file signatures. Each hex-pair makes one byte. Most of these signature values came from https://en.wikipedia.org/wiki/List_of_file_signatures */
#define FILE_SIGNATURE_MACROS_SEEN   (1)


#define __7Z   ({0x37, 0x7A, 0xBC, 0xAF, 0x27, 0x1C})
#define __BMP   ({0x42, 0x4D})
#define __DALVIK_EXECUTABLE   ({0x64, 0x65, 0x78, 0x0A, 0x30, 0x33, 0x35, 0x0})
#define __DMG   ({0x78, 0x1, 0x73, 0x0D, 0x62, 0x62, 0x60})
#define __GZIP   ({0x1F, 0x8B})
#define __FREE_LOSSLESS_AUDIO_CODEC   ({0x66, 0x4C, 0x61, 0x43})
#define __FREE_LOSSLESS_IMAGE_FORMAT   ({0x46, 0x4C, 0x49, 0x46})
#define __MATROSKA_MEDIA_CONTAINER   ({0x1A, 0x45, 0xDF, 0xA3})
#define __MICROSOFT_CABINET_FILE   ({0x4D, 0x53, 0x43, 0x46})
#define __MICROSOFT_OFFICE_DOCUMENTS   ({0xD0, 0xCF, 0x11, 0xE0, 0xA1, 0xB1, 0x1A, 0xE1})
#define __NES_ROM   ({0x4E, 0x45, 0x53, 0x1A})
#define __OGG   ({0x4F, 0x67, 0x67, 0x53})
#define __PDF   ({0x25, 0x50, 0x44, 0x46})
#define __POSTSCRIPT   ({0x25, 0x21, 0x50, 0x53})
#define __VMDK   ({0x4B, 0x44, 0x4D})
#define __XAR   ({0x78, 0x61, 0x72, 0x21})


#endif  // FILE_SIGNATURE_MACROS_SEEN


/* SPECIFICATIONS, FEATURES, & ARCHITECTURE MACROS */


#if (!(defined(_SPECIFICATIONS_H) || defined(_SPECIFICATIONS_H_)))
#define _SPECIFICATIONS_H   (1)
#define _SPECIFICATIONS_H_   (1)
#define _BASETSD_H_   (1)
#define _FEATURES_H   (1)  // <features.h>
#define _FEATURES_H_   (1)
#define ARCHITECTURE_MACROS_SEEN   (1)
#define ARCH_SPECIFIC_MACROS_SEEN   (1)
#define ARCH_MACROS_SEEN   (1)
#define _SYS_REG_H   (1)
#define _SYS_REG_H_   (1)
#define _UNISTD_H   (1)  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/unistd.h.html
#define _UNISTD_H_   (1)  // <unistd.h>
#define _LIBC_UNISTD_H   (1)
#define _LIBC_UNISTD_H_   (1)
#define _BSD_UNISTD_H   (1)
#define _BSD_UNISTD_H_   (1)
#define _FSSH_UNISTD_H   (1)
#define _LINUX_UNISTD_H_   (1)
#define _NEWLIB_UNISTD_H   (1)
#define _SYS_UNISTD_H   (1)
#define _LIBROOT_UNISTD_PRIVATE_H   (1)
#define _LIBROOT_UNISTD_PRIVATE_H_   (1)
#define unistd__INCLUDED   (1)
#define _FSSH_DEFS_H   (1)
#define _COMPAT_UNISTD_H_   (1)
#define _BITS_POSIX_OPT_H   (1)
#define _CONFIG_HAIKU_CONFIG_H   (1)
#ifndef STDC_PREDEF_H  // <stdc-predef.h>
#   define STDC_PREDEF_H   (1)
#endif
#ifndef _STDC_PREDEF_H  // <stdc-predef.h>
#   define _STDC_PREDEF_H   (1)
#endif
#ifndef _STDC_PREDEF_H_  // <stdc-predef.h>
#   define _STDC_PREDEF_H_   (1)
#endif


// C STANDARD LIBRARIES

#ifdef __GLIBC__
/** String name of the standard C library */
#   define STDLIB   "glibc"
/** Boolean macros indicating whether the standard C library is GLibc */
#   define IS_STDLIB_GLIBC   0x1
/** Boolean macros indicating whether the standard C library is GLibc */
#   define IS_GLIBC   0x1
/** Boolean macros indicating whether the standard C library is Musl */
#   define IS_STDLIB_MUSL   0x0
/** Boolean macros indicating whether the standard C library is Musl */
#   define IS_MUSL   0x0
#elif defined(__BIONIC__)
#   define STDLIB   "bionic"
#   define IS_STDLIB_GLIBC   0x0
#   define IS_GLIBC   0x0
#   define IS_STDLIB_MUSL   0x0
#   define IS_MUSL   0x0
#elif defined(__DIETLIBC__)
#   define STDLIB   "dietlibc"
#   define IS_STDLIB_GLIBC   0x0
#   define IS_GLIBC   0x0
#   define IS_STDLIB_MUSL   0x0
#   define IS_MUSL   0x0
#elif defined(__KLIBC__)
#   define STDLIB   "klibc"
#   define IS_STDLIB_GLIBC   0x0
#   define IS_GLIBC   0x0
#   define IS_STDLIB_MUSL   0x0
#   define IS_MUSL   0x0
#elif defined(__MUSL__)
#   define STDLIB   "musl"
#   define IS_STDLIB_GLIBC   0x0
#   define IS_GLIBC   0x0
#   define IS_STDLIB_MUSL   0x1
#   define IS_MUSL   0x1
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
#   define IS_STDLIB_GLIBC   0x0
#   define IS_GLIBC   0x0
#   define IS_STDLIB_MUSL   0x0
#   define IS_MUSL   0x0
#endif  // C STANDARD LIBRARIES
#undef  __GNU_LIBRARY__
#undef  __GLIBC__
#undef  __GLIBC_MINOR__
/** Compatible major version number of the GNU C library package; Use this macro to test for features in specific releases */
#define __GLIBC__   3
/** Compatible minor version number of the GNU C library package; Use this macros to test for features in specific releases */
#define __GLIBC_MINOR__   0
#ifndef ALLOW_OBSOLETE_CARBON
#   define ALLOW_OBSOLETE_CARBON   0
#endif
#ifndef ALLOW_OBSOLETE_CARBON_MACMEMORY
#   define ALLOW_OBSOLETE_CARBON_MACMEMORY   0
#endif
#ifndef ALLOW_OBSOLETE_CARBON_OSUTILS
#   define ALLOW_OBSOLETE_CARBON_OSUTILS   0
#endif


// C VERSION MACROS

#if (defined(__STDC__) && __STDC__)
/** Macros test for ANSI C */
#   define IS_ANSI   (1)
#else
/** Macros test for ANSI C */
#   define IS_ANSI   (0)
#endif
#ifdef __GNUC__
/** Boolean macros indicating whether the compiler is GNU GCC */
#   define IS_GCC   (1)
/** Boolean macros indicating whether the compiler is GNU GCC */
#   define IS_GNUC   (1)
#else
#   define IS_GCC   (0)
#   define IS_GNUC   (0)
#endif
#ifdef __STRICT_ANSI__
/** Macros test for strict ANSI C */
#   define IS_STRICT_ANSI   (1)
/** Macros test for strict ANSI C */
#   define IS_NOT_STRICT_ANSI   (0)
#else
/** Macros test for strict ANSI C */
#   define IS_STRICT_ANSI   (0)
/** Macros test for strict ANSI C */
#   define IS_NOT_STRICT_ANSI   (1)
#endif
#if ((!defined(__STDC_VERSION__)) || (!(defined(_ISOC99_SOURCE) || defined(_ISOC11_SOURCE))))
/** Macros test for Standard C */
#   define IS_NOT_STDC   (1)
#else
/** Macros test for Standard C */
#   define IS_NOT_STDC   (0)
#endif
#if (defined(_ISOC95_SOURCE) || defined(_ISOC99_SOURCE) || defined(_ISOC11_SOURCE))
/** Macros test for ISO C */
#   define IS_ISOC   (1)
#else
/** Macros test for ISO C */
#   define IS_ISOC   (0)
#endif
#if (defined(_ISOC99_SOURCE) || defined(_ISOC11_SOURCE))
/** Macros test for ISO C99 */
#   define IS_ISOC99   (1)
#else
/** Macros test for ISO C99 */
#   define IS_ISOC99   (0)
#endif
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ < 199409L))
/** Macros test for C standards under C94 */
#   define IS_BELOW_STDC_1994   (1)
#else
/** Macros test for C standards under C94 */
#   define IS_BELOW_STDC_1994   (0)
#endif
/** Macros test for C standards under C94 */
#define IS_UNDER_STDC_1994   IS_BELOW_STDC_1994
/** Macros test for C standards under C94 */
#define IS_STDC_BELOW_1994   IS_BELOW_STDC_1994
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199409L))
/** Macros test for C94 */
#   define IS_STDC_1994   (1)
#else
/** Macros test for C94 */
#   define IS_STDC_1994   (0)
#endif
#define IS_STDC_94   IS_STDC_1994
#define IS_STDC94   IS_STDC_1994
#define IS_C94   IS_STDC_1994
#define IS_C1994   IS_STDC_1994
#define IS_C_1994   IS_STDC_1994
#define IS_GNUC_1995   (IS_STDC_1995 && IS_GNUC)
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L))
/** Macros test for C99 or greater */
#   define IS_STDC_1999   (1)
#else
/** Macros test for C99 or greater */
#   define IS_STDC_1999   (0)
#endif
#define IS_STDC_99   IS_STDC_1999
#define IS_STDC99   IS_STDC_1999
#define IS_C99   IS_STDC_1999
#define IS_C1999   IS_STDC_1999
#define IS_C_1999   IS_STDC_1999
#define IS_GNUC_1999   (IS_STDC_1999 && IS_GNUC)
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ < 199901L))
/** Macros test for C Standards below C99 */
#   define IS_BELOW_STDC_1999   (1)
#else
/** Macros test for C Standards below C99 */
#   define IS_BELOW_STDC_1999   (0)
#endif
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ > 199901L))
/** Macros test for C Standards over C99 */
#   define IS_OVER_STDC_1999   (1)
#else
/** Macros test for C Standards over C99 */
#   define IS_OVER_STDC_1999   (0)
#endif
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ < 201112L))
/** Macros test for C Standards below C11 */
#   define IS_BELOW_STDC_2011   (1)
#else
/** Macros test for C Standards below C11 */
#   define IS_BELOW_STDC_2011   (0)
#endif
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ > 201112L))
/** Macros test for C Standards over C11 */
#   define IS_OVER_STDC_2011   (1)
#else
/** Macros test for C Standards over C11 */
#   define IS_OVER_STDC_2011   (0)
#endif
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201112L))
/** Macros test for exactly C11 (not below and not greater) */
#   define IS_EXACTLY_STDC_2011   (1)
#else
/** Macros test for exactly C11 (not below and not greater) */
#   define IS_EXACTLY_STDC_2011   (0)
#endif
/** Macros test for anything but C11 */
#define IS_NOT_STDC_2011   (!IS_EXACTLY_STDC_2011)
#if (defined(__STDC_VERSION__) && !(__STDC_VERSION__ == 201112L))
/** Macros test for anything but C11 */
#   define IS_NOT_EXACTLY_STDC_2011   (1)
#else
/** Macros test for anything but C11 */
#   define IS_NOT_EXACTLY_STDC_2011   (0)
#endif
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L))
/** Macros test for C11 or greater */
#   define IS_STDC_2011   (1)
#else
/** Macros test for C11 or greater */
#   define IS_STDC_2011   (0)
#endif
#define IS_GNUC_2011   (IS_STDC_2011 && IS_GNUC)
#define IS_ISO_STDC_2011   IS_STDC_2011
#define IS_C2011   IS_STDC_2011
#define IS_C_2011   IS_STDC_2011
#define IS_C11   IS_STDC_2011
#define IS_ISOC11   IS_STDC_2011
#define IS_ISOC11_SOURCE   IS_STDC_2011
// C PLUS PLUS
#ifdef __cplusplus
/** Macros test for C++ */
#   define IS_CPLUSPLUS   (0x1)
#else
/** Macros test for C++ */
#   define IS_CPLUSPLUS   (0x0)
#endif
#if IS_CPLUSPLUS
#   define C_PLUS_PLUS   (0x1)
#endif
/** Macros test for C++ */
#define IS_C_PLUS_PLUS   IS_CPLUSPLUS
/** Macros test for the absence of C++ */
#define IS_NOT_CPLUSPLUS   (!(IS_CPLUSPLUS))
#if (defined(__cplusplus) && (__cplusplus == 201103L))
/** Macros test for exactly C++11 */
#   define IS_EXACTLY_CPLUSPLUS_2011   (0x1)
#else
/** Macros test for exactly C++11 */
#   define IS_EXACTLY_CPLUSPLUS_2011   (0x0)
#endif
#if (defined(__cplusplus) && !(__cplusplus == 201103L))
/** Macros test for not C++11 */
#   define IS_NOT_EXACTLY_CPLUSPLUS_2011   (0x1)
#else
/** Macros test for not C++11 */
#   define IS_NOT_EXACTLY_CPLUSPLUS_2011   (0x0)
#endif
#if (defined(__cplusplus) && (__cplusplus < 201103L))
/** Macros test for C++ standards below C++11 */
#   define IS_BELOW_CPLUSPLUS_2011   (0x1)
#else
/** Macros test for C++ standards below C++11 */
#   define IS_BELOW_CPLUSPLUS_2011   (0x0)
#endif
#if (defined(__cplusplus) && (__cplusplus > 201103L))
/** Macros test for C++ standards over C++11 */
#   define IS_OVER_CPLUSPLUS_2011   (0x1)
#else
/** Macros test for C++ standards over C++11 */
#   define IS_OVER_CPLUSPLUS_2011   (0x0)
#endif
/** Macros test for the absence of C++11 */
#define IS_NOT_CPLUSPLUS_2011   (IS_NOT_CPLUSPLUS || IS_BELOW_CPLUSPLUS_2011)
#define IS_NOT_CPLUSPLUS11   IS_NOT_CPLUSPLUS_2011
#define IS_NOT_CPP2011   IS_NOT_CPLUSPLUS_2011
#define IS_NOT_CPP11   IS_NOT_CPLUSPLUS_2011
#if (defined(__cplusplus) && (__cplusplus >= 201103L))
/** Macros test for C++11 or greater */
#   define IS_CPLUSPLUS_2011   (0x1)
#else
/** Macros test for C++11 or greater */
#   define IS_CPLUSPLUS_2011   (0x0)
#endif
#define IS_CPP2011   IS_CPLUSPLUS_2011
#define IS_CPLUSPLUS2011   IS_CPLUSPLUS_2011
// OBJECTIVE C
#if (defined(__OBJC__) || defined(__OBJC_BOOL) || defined(__objc_INCLUDE_GNU))
/** Macros test for Objective-C */
#   define IS_OBJ_C   (0x1)
#else
/** Macros test for Objective-C */
#   define IS_OBJ_C   (0x0)
#endif
#if IS_OBJ_C
#   define OBJ_C   (0x1)
#endif
// OBJECTIVE C PLUS PLUS
#if ((IS_CPLUSPLUS) && (IS_OBJ_C))
/** Macros test for Objective-C++ */
#   define IS_OBJ_CPLUSPLUS   (0x1)
#else
/** Macros test for Objective-C++ */
#   define IS_OBJ_CPLUSPLUS   (0x0)
#endif
/** Macros test for Objective-C++ */
#define IS_OBJ_C_PLUS_PLUS   IS_OBJ_CPLUSPLUS
/** Macros test for Objective-C++ */
#define IS_OBJ_CPP   IS_OBJ_CPLUSPLUS
#if IS_OBJ_CPLUSPLUS
#   define OBJ_CPLUSPLUS   (0x1)
#   define OBJ_CPP   (0x1)
#endif
// MISCELLANEOUS C-STANDARD MACROS
#if IS_NOT_STDC_2011
#   error   "Support for C Standard 2011 (or newer) is required."
#endif
#ifndef __STDC_VERSION__  // C11
#   define __STDC_VERSION__   (201112L)
#endif
#ifndef __cplusplus
#   define __cplusplus   (201103L)  // C++11
#endif
typedef enum c_language_kind {
	clk_c = 0,  // C90, C94, C99, or C11
	clk_objc = 1,  // clk_c with ObjC features
	clk_cxx = 2,  // ANSI/ISO C++
	clk_objcxx = 3  // clk_cxx with ObjC features
} c_language_kind, c_language_kind_t, c_language_t;
#if IS_OBJ_C
/** Defines this library's C language type */
#   define c_language   clk_objc
#elif IS_OBJ_CPLUSPLUS
/** Defines this library's C language type */
#   define c_language   clk_objcxx
#elif IS_CPLUSPLUS
/** Defines this library's C language type */
#   define c_language   clk_cxx
#else
/** Defines this library's C language type */
#   define c_language   clk_c
#endif
/** Test if this library is using C++ */
#define c_dialect_cxx()   ((c_language & clk_cxx) != 0)
/** Test if this library is using Objective-C */
#define c_dialect_objc()   ((c_language & clk_objc) != 0)
#if ((defined(__STDC__) || IS_CPLUSPLUS) && (!defined(NO_ANSI_KEYWORDS)))
#   define _HAVE_STDC   (1)
#else
#   define _HAVE_STDC   (0)
#endif


// COMPILER TYPE

#if (defined(__llvm__) || defined(__LLVM__) || defined(__llvm) || defined(__LLVM))  // LLVM
/** Macros flag present if the current compiler is LLVM */
#   define COMPILER_LLVM   (1)
#endif
#if (defined(__BORLANDC__) || defined(__CODEGEARC__))  // Borland
/** Macros flag present if the current compiler is Borland */
#   define COMPILER_BORLAND   (1)
#elif (defined(_ACC_) || defined(__ACC__))  // ACC
/** Macros flag present if the current compiler is ACC */
#   define COMPILER_ACC   (1)
#elif defined(__CMB__)  // Altium MicroBlaze C
/** Macros flag present if the current compiler is Altium MicroBlaze C */
#   define COMPILER_CMB   (1)
#elif defined(__CHC__)  // Altium C-to-Hardware
/** Macros flag present if the current compiler is Altium C-to-Hardware */
#   define COMPILER_CHC   (1)
#elif defined(__ACK__)  // Amsterdam Compiler Kit
/** Macros flag present if the current compiler is the Amsterdam Compiler Kit */
#   define COMPILER_ACK   (1)
#elif (defined(__CC_ARM) && defined(__ARMCC_VERSION))  // ARM Compiler
/** Macros flag present if the current compiler is the ARM compiler */
#   define COMPILER_ARMCC   (1)
#   define COMPILER_ARM   (1)
#elif (defined(AZTEC_C) || defined(__AZTEC_C__))  // Aztec C
/** Macros flag present if the current compiler is Aztec C */
#   define COMPILER_AZTEC   (1)
#elif (defined(__POCC__) || defined(__PELLES_C__))  // Pelles C
/** Macros flag present if the current compiler is Pelles C */
#   define COMPILER_PELLES   (1)
/** Macros flag present if the current compiler is Pelles C */
#   define COMPILER_PELLES_C   (1)
#elif (defined(__clang__) || defined(__CLANG__) || defined(__clang) || defined(__clang_major__))  // Clang
/** Macros flag present if the current compiler is Clang */
#   define COMPILER_CLANG   (1)
/** Macros flag present if the current compiler is Clang */
#   define CLANG   (1)
#elif (defined(__GNUC__) && (!defined(__clang__)))  // GNU-GCC
/** Macros flag present if the current compiler is GNU-GCC */
#   define COMPILER_GNU_GCC   (1)
/** Macros flag present if the current compiler is GNU_GCC */
#   define GNU_GCC   (1)
#elif (defined(__HP_cc) || defined(__HP_cc__))  // HP ANSI C
#   define COMPILER_HP   (1)
#elif (defined(__IAR_SYSTEMS_ICC__) || defined(__IAR_SYSTEMS_ICC))  // IAR C
#   define COMPILER_IAR   (1)
#elif (defined(__ILEC400__) || defined(__ILEC__) || defined(__ilec__))  // ILE C
#   define COMPILER_ILEC   (1)
#elif (defined(__xlc__) || defined(__xlC__) || defined(__IBMC__) || defined(__IBMCPP__))  // IBM XL C
#   define COMPILER_XLC   (1)
#   define COMPILER_IBM_XLC   (1)
#   define COMPILER_IBM_C   (1)
#elif (defined(__INTEL_COMPILER) || defined(__ICC) || defined(__ECC) || defined(__ICL))  // Intel Compiler
#   define COMPILER_INTEL   (1)
#elif (defined(__LCC__) || defined(__LCC))  // Local C Compiler
#   define COMPILER_LLC   (1)
#elif (defined(__MINGW32__) || defined(__MINGW64__) || defined(__MINGW32_MAJOR_VERSION) || defined(__MINGW64_VERSION_MINOR))  // MinGW
/** Macros flag present if the current compiler is MingW */
#   define COMPILER_MINGW   (1)
#   define MINGW   (1)
#   ifdef __MINGW32__
#      define MINGW32   (1)
#   elif defined(__MINGW64__)
#      define MINGW64   (1)
#   endif
#elif (defined(_MSC_VER) || defined(_MSC_FULL_VER) || defined(_MSC_BUILD))  // Microsoft Visual C++
#   if (defined(_MSC_VER) && (_MSC_VER < 1300))
#      error   "This MSVC compiler is not supported!"
#   endif
#   define COMPILER_MICROSOFT   (1)
#   define MICROSOFT_VISUAL   (1)
#endif  // COMPILER
#if (defined(GNU_GCC) || defined(CLANG))  // GNUC
#   define COMPILER_GNUC   (1)
#   define GNUC   (1)
#endif
#if (defined(__CUDACC__) || defined(__NVCC__) || defined(__CUDACC_VER__) || defined(__CUDA_ARCH__))  // NVCC
/** Macros flag present if the current compiler is Cuda */
#   define COMPILER_CUDA   (1)
/** Macros flag present if the current compiler is NVCC */
#   define COMPILER_NVCC   (1)
#endif


// ASSEMBLER MACROS

#if ((!defined(IS_ASSEMBLER)) && (defined(__ASSEMBLER__) || defined(__ASSEMBLY__)))
#   define IS_ASSEMBLER   (1)
#   define IS_NOT_ASSEMBLER   (0)
#   define LANGUAGE_ASSEMBLY   (1)
#   define __LANGUAGE_ASSEMBLY   (1)
#   define __LANGUAGE_ASSEMBLY__   (1)
#   define _LANGUAGE_ASSEMBLY   (1)
#elif (!defined(IS_ASSEMBLER))
#   define IS_ASSEMBLER   (0)
#   define IS_NOT_ASSEMBLER   (1)
#   define LANGUAGE_ASSEMBLY   (0)
#   define __LANGUAGE_ASSEMBLY   (0)
#   define __LANGUAGE_ASSEMBLY__   (0)
#   define _LANGUAGE_ASSEMBLY   (0)
#endif


// OPERATING-SYSTEM MACROS CONSTANTS

#ifdef _WIN32_WCE  // Windows CE
#   define OSWINCE
#endif  // Windows CE
#ifdef __DragonFly__  // BSD Systems
/** Macros flag present if the target operating system is Dragonfly BSD */
#   define OSDRAGONFLY
#elif defined(__NetBSD__)
#   define OSNETBSD
#elif defined(__OpenBSD__)
/** Macros flag present if the target operating system is OpenBSD */
#   define OSOPENBSD
#elif (defined(__FreeBSD__) || defined(__FreeBSD_kernel__))
/** Macros flag present if the target operating system is FreeBSD */
#   define OSFREEBSD
#   define __KFBSD__   1
#endif  // BSD Systems
#if (defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SVR4_SOURCE) || defined(_SYSTYPE_SVR4))  // SVR4
#   define SVR4   (1)
#   define _SVID_SOURCE   (1)
#endif  // SVR4
#ifdef EPLAN9  // Operating-System
#   define OSPLAN9
#elif (defined(_AIX) || defined(__TOS_AIX__) || defined(_AIX3) || defined(_AIX32) || defined(_AIX41) || defined(_AIX43))  // AIX
#   define OSAIX
#elif (defined(__amigaos__) || defined(AMIGA) || defined(__AMIGA__))  // AmigaOS
#   define OSAMIGAOS
#elif (defined(__BEOS__) || defined(__beos__))  // BeOS
#   define OSBEOS
#elif (defined(_CRAY) || defined(__cray) || defined(__cray__) || defined(_UNICOS) || defined(__unicos) || defined(__unicos__))  // Unicos/Cray
#   define OSCRAY
#   define OSUNICOS
#elif (defined(__CYGWIN__) || defined(__CYGWIN32__))  // Cygwin
#   define OSCYGWIN
#elif (defined(__DGUX__) || defined(__dgux__) || defined(DGUX))  // DG/UX
#   define OSDGUX
#elif (defined(__MSDOS__) || defined(__msdos__) || defined(__msdos) || defined(__DOS__) || defined(__dos__) || defined(__dos) || defined(_MSDOS) || defined(_msdos))  // MS/DOS
#   define OSMSDOS
#   define OSDOS
#   error   "This library does not support DOS."
#elif (defined(_SEQUENT_) || defined(__sequent__) || defined(sequent))  // DYNIX/ptx
#   define OSDYNIX
#   define OSSEQUENT
#elif (defined(__ECOS) || defined(__ECOS__))  // eCos
#   define OSECOS
#elif (defined(__FREEVMS) || defined(__FREEVMS__) || defined(__freevms) || defined(__freevms__))  // FreeVMS
#   define OSFREEVMS
#elif (defined(__gnu_hurd__) || defined(__gnu_hurd) || defined(__hurd__))  // GNU-Hurd
#   define OSGNU
#   define OSHURD
#elif (defined(_hpux) || defined(hpux) || defined(__hpux) || defined(__hpux__) || defined(_HPUX_SOURCE))  // HP-Unix
#   define OSHPUX
#elif (defined(_junos) || defined(junos) || defined(__junos) || defined(__junos__) || defined(_juniper_os))  // Junos OS (Juniper Network Operating System)
#   define OSJUNOS
#   define OSJUNIPER
#elif (defined(__sgi) || defined(sgi) || defined(__sgi__) || defined(_SGI_SOURCE))  // IRIX
#   define OSIRIX
#   error   "This library does not support Irix."
#elif (defined(__lynx__) || defined(__Lynx__) || defined(__lynx) || defined(__Lynx))  // Lynx
#   define OSLYNX
#elif (defined(__minix) || defined(__minix__) || defined(__MINIX) || defined(__MINIX__))  // Minix
#   define OSMINIX
#elif (defined(__MORPHOS__) || defined(__morphos__) || defined(__MORPHOS) || defined(__morphos))  // MorphOS
#   define OSMORPHOS
#elif (defined(__mpexl) || defined(__mpexl__) || defined(__MPEXL__) || defined(mpexl))  // MPE/iX
#   define OSMPEIX
#elif (defined(__netware) || defined(__netware__) || defined(__NetWare__) || defined(__NetWare) || defined(__NETWARE__) || defined(__NETWARE))  // NetWare
#   define OSNETWARE
#elif (defined(__OpenVMS__) || defined(__OPENVMS__) || defined(__openvms__) || defined(__OpenVMS) || defined(__OPENVMS) || defined(__openvms))  // OpenVMS
#   define OSOPENVMS
#elif (defined(__TOS_OS2__) || defined(__OS2__) || defined(__os2__) || defined(__os2warp__) || defined(_OS2) || defined(OS2))  // OS2/Warp
#   define OSOS2WARP
#   error   "This library does not support OS2/Warp."
#elif (defined(__osf__) || defined(__osf))  // OSF
#   define OSOSF
#   error   "This library does not support OSF."
#elif (defined(__palmos__) || defined(__palmos) || defined(__garnet__) || defined(__garnet))  // Garnet/Palm OS
#   define OSGARNETOS
#   define OSPALMOS
#elif (defined(__PS3__) || defined(__PS3) || defined(__PS4__) || defined(__PS4))  // Sony Playstation
#   define OSPLAYSTATION
#   if (defined(__PS3__) || defined(__PS3))
#      define OSPLAYSTATION3
#      define OSPS3
#   elif (defined(__PS4__) || defined(__PS4))
#      define OSPLAYSTATION4
#      define OSPS4
#   endif
#elif (defined(__QNX__) || defined(__QNXNTO__))  // QNX
#   define OSQNX
#elif (defined(_SCO_DS) || defined(__SCO_C_DIALECT))  // SCO OpenServer
#   define OSSCO
#elif (defined(sinux) || defined(__sinux__) || defined(__sinux))  // SINIX/Reliant-UNIX
#   define OSSINIX
#elif (defined(__SYLLABLE__) || defined(__syllable__))  // Syllable
#   define OSSYLLABLE
#elif (defined(__symbian) || defined(symbian) || defined(__symbian__) || defined(__SYMBIAN__))  // Symbian
#   define OSSYMBIAN
#   error   "This library does not support Symbian."
#elif (defined(__ultrix) || defined(__ultrix__) || defined(ultrix))  // Ultrix
#   define OSULTRIX
#elif (defined(__unixware__) || defined(__UNIXWARE__) || defined(_UNIXWARE7))  // Unixware
#   define OSUNIXWARE
#elif (defined(__VXWORKS__) || defined(__vxworks__) || defined(__vxworks))  // VxWorks
#   define OSVXWORKS
#elif (defined(__WHIITE__) || defined(__whiite__) || defined(__whiite))  // WHIITE
#   define OSWHIITE
#   define OSGNU
#   define OSLINUX
#elif (defined(__XBOX__) || defined(__XBOX) || defined(__xbox__) || defined(__xbox) || defined(_X360) || defined(__X360) || defined(__X360__))  // Xbox
#   define OSXBOX
#   if (defined(_X360) || defined(__X360) || defined(__X360__))
#      define OSXBOX360
#   elif (defined(_XBOXONE) || defined(__XBOXONE) || defined(__XBOXONE__) || defined(_XBOX1) || defined(__XBOX1) || defined(__XBOX1__))
#      define OSXBOXONE
#      define OSXBOX1
#   endif
#elif (defined(__XEN__) || defined(__xen__) || defined(__xen) || defined(XENLOG_DEFAULT))  // Xen
#   define OSXEN
#   define OSXENHYPERVISOR
#   define HYPERVISOR_XEN
#   define IS_HYPERVISOR   (1)
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
#   define OSGNU
#   define OSLINUX
#elif (defined(__FreeBSD_kernel__ ) && defined(__GLIBC__ ))  // GNU-kFreeBSD
#   define OSGNU
#   define OSBSD
#   define _GNU_SOURCE
#elif ((defined(OSDRAGONFLY) || defined(OSNETBSD) || defined(OSOPENBSD) || defined(OSFREEBSD) || defined(_SYSTYPE_BSD) || defined(__bsdi__) || defined(__bsdi) || defined(bsdi) || defined(_SYSTYPE_BSD ) || defined(BSD)) && (!(defined(__APPLE__) || defined(macintosh) || defined(Macintosh))))  // BSD
#   define OSBSD
#   define _BSD_SOURCE
#   define _XOPEN_SOURCE   (700)
#   define _XOPEN_VERSION   (700)
#   define _XOPEN_SOURCE_EXTENDED   (1)
#elif (defined(sun) || defined(__sun) || defined(__SunOS_5_7) || defined(__SunOS_5_8))  // Solaris, SunOS, etc.
#   define OSSUN
#   ifdef SVR4  // Solaris
#      define OSSOLARIS
#   elif ((!defined(SVR4)) || defined(__SunOS_5_7) || defined(__SunOS_5_8))  // SunOS
#      define OSSUNOS
#   endif
#elif ((defined(__unix__) || defined(__unix) || defined(unix)) || (defined(__APPLE__) && defined(__MACH__)))  // Unix-systems
#   if (defined(macintosh) || defined(Macintosh) || defined(BOOST_OS_MACOS))  // MacOS
#      define OSMACOS
#   elif (defined(__APPLE__) && defined(__MACH__))  // OSX
#      define OSOSX
#   elif (defined(__APPLE__) && !defined(__MACH__))  // Apple system
#      define OSAPPLE
#   elif (defined(__MACH__) && !defined(__APPLE__))  // Nextstep
#      define OSNEXTSTEP
#   endif
#elif (defined(MINGW) || defined(__WINNT__) || defined(__WINNT) || defined(WINNT) || defined(__NT__) || defined(_WIN64) || defined(WIN64) || defined(_WIN32) || defined(WIN32) || defined(__WIN32__) || defined(__WIN32) || defined(BOOST_OS_WINDOWS) || defined(_UWIN) || defined(__TOS_WIN__) || defined(__WINDOWS__) || defined(OSWINCE) || defined(MICROSOFT_VISUAL) || defined(__MSVCRT__))  // Windows
#   define OSWINDOWS
#   ifdef __INTERIX  // Interix
#      define OSINTERIX
#   endif
#endif
#ifndef IS_HYPERVISOR
#   define IS_HYPERVISOR   (0)
#endif
#if ((!defined(OSVMS)) && (defined(__VMS_VERSION) || defined(__vms_version) || defined(__VMS_VER) || defined(__vms_ver) || defined(OSFREEVMS) || defined(OSOPENVMS)))
#   define OSVMS
#endif
#ifndef _XOPEN_XCU_VERSION
#   define _XOPEN_XCU_VERSION   (4)
#endif
#ifndef __KFBSD__
#   define __KFBSD__   (0)
#endif
// UNIX & POSIX
#if (defined(OSAIX) || defined(OSAPPLE) || defined(OSBSD) || defined(OSHPUX) || defined(OSINTERIX) || defined(OSIRIX) || defined(OSMACOS) || defined(OSNEXTSTEP) || defined(OSOSX) || defined(OSSCO) || defined(OSSINIX) || defined(OSSOLARIS) || defined(OSSUN) || defined(OSSUNOS) || defined(__hiuxmpp) || defined(SVR4) || ((defined(__unix__) || defined(__unix) || defined(unix)) || (defined(__APPLE__) && defined(__MACH__))))  // OSUNIX
/** Macros flag present if the target operating system is a Unix system */
#   define OSUNIX
#endif  // OSUNIX
#if (defined(OSUNIX) || defined(OSCYGWIN) || defined(OSECOS) || defined(OSHURD) || defined(OSLINUX) || defined(OSLYNX) || defined(OSMINIX) || defined(OSQNX) || defined(OSSYLLABLE))  // OSPOSIX
/** Macros flag present if the target operating system is a POSIX system */
#   define OSPOSIX
#endif  // OSPOSIX
#ifdef OSUNIX
#   define TARGET_OS_UNIX   (1)
#else
#   define TARGET_OS_UNIX   (0)
#endif
#ifdef OSPOSIX
/** Macros flag indicates if the target operating system is a POSIX system */
#   define TARGET_OS_POSIX   (1)
#else
/** Macros flag indicates if the target operating system is a POSIX system */
#   define TARGET_OS_POSIX   (0)
#endif
// MISCELLANEOUS OPERATING SYSTEM MACROS
#ifdef OSWINDOWS
#   define TARGET_OS_WIN   (1)
#else
#   define TARGET_OS_WIN   (0)
#endif
#ifdef OSOSX
#   define TARGET_OS_MAC   (1)
#else
#   define TARGET_OS_MAC   (0)
#endif


// RUNTIME MACROS

#ifdef __NEXT_RUNTIME__
#   define RUNTIME_NEXT   (1)
#else
#   define RUNTIME_NEXT   (0)
#endif
#ifdef OSGNU
#   define RUNTIME_GNU   (1)
#else
#   define RUNTIME_GNU   (0)
#endif


// PLATFORM & ARCHITECTURE FEATURES+TYPE

// ARM
#ifdef __ARM_ARCH_2__
#   define ARM_2   (1)
#endif
#if (defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__))
#   define ARM_3   (1)
#endif
#ifdef __ARM_ARCH_3M__
#   define ARM_3M   (1)
#endif
#if (defined(ARM_3) || defined(ARM_3M))
#   define ARM_3_SERIES   (1)
#endif
#if (defined(__ARM_ARCH_4__) || defined(_ARM_ARCH_4) || defined(__TARGET_ARM_4))
#   define ARM_4   (1)
#endif
#if (defined(__ARM_ARCH_4T__) || defined(_ARM_ARCH_4T) || defined(__TARGET_ARM_4T))
#   define ARM_4T   (1)
#endif
#if (defined(ARM_4) || defined(ARM_4T))
#   define ARM_4_SERIES   (1)
#endif
#ifdef __ARM_ARCH_5__
#   define ARM_5   (1)
#endif
#ifdef __ARM_ARCH_5E__
#   define ARM_5E   (1)
#endif
#if (defined(__ARM_ARCH_5T__) || defined(_ARM_ARCH_5T))
#   define ARM_5T   (1)
#endif
#ifdef __ARM_ARCH_5TE__
#   define ARM_5TE   (1)
#endif
#ifdef __ARM_ARCH_5TEJ__
#   define ARM_5TEJ   (1)
#endif
#if (defined(ARM_5) || defined(ARM_5E) || defined(ARM_5T) || defined(ARM_5TE) || defined(ARM_5TEJ))
#   define ARM_5_SERIES   (1)
#endif
#if (defined(__ARM_ARCH_6__) || defined(_ARM_ARCH_6))
#   define ARM_6   (1)
#endif
#ifdef __ARM_ARCH_6J__
#   define ARM_6J   (1)
#endif
#ifdef __ARM_ARCH_6K__
#   define ARM_6   (1)
#endif
#ifdef __ARM_ARCH_6Z__
#   define ARM_6Z   (1)
#endif
#ifdef __ARM_ARCH_6ZK__
#   define ARM_6ZK   (1)
#endif
#ifdef __ARM_ARCH_6ZM__
#   define ARM_6ZM   (1)
#endif
#ifdef __ARM_ARCH_6T2__  // Has Thumb2
#   define ARM_6T2   (1)
#endif
#if (defined(ARM_6) || defined(ARM_6J) || defined(ARM_6K) || defined(ARM_6Z) || defined(ARM_6ZK) || defined(ARM_6ZM) || defined(ARM_6T2))
#   define ARM_6_SERIES   (1)
#endif
#if (defined(__ARM_ARCH_7__) || defined(_ARM_ARCH_7))
#   define ARM_7   (1)
#endif
#ifdef __ARM_ARCH_7A__
#   define ARM_7A   (1)
#endif
#ifdef __ARM_ARCH_7R__
#   define ARM_7R   (1)
#endif
#ifdef __ARM_ARCH_7M__
#   define ARM_7M   (1)
#endif
#ifdef __ARM_ARCH_7S__
#   define ARM_7S   (1)
#endif
#ifdef __ARM_ARCH_7EM__
#   define ARM_7EM   (1)
#endif
#if (defined(ARM_7) || defined(ARM_7A) || defined(ARM_7R) || defined(ARM_7M) || defined(ARM_7S) || defined(ARM_7EM))
#   define ARM_7_SERIES   (1)
#endif
#if (defined(__ARM_ARCH_8__) || defined(_ARM_ARCH_8) || defined(__ARM_ARCH_8A__))
/** ARMv8 64-bit in AARCH32 */
#   define ARM_8   (1)
#   define ARM_8_SERIES   (1)
#endif
#if (defined(_ARM_ARCH_7) || defined(__ARM_ARCH_6T2__) || defined(_ARM_ARCH_T2))  // _ARM_ARCH_T2
#   define ARM_ARCH_T2   (1)
#endif
#if (defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__))  // NON_MMU_ARM
/** 7R, 7M, 7EM are for non-MMU ARM processors */
#   define NON_MMU_ARM   (1)
#endif  // NON_MMU_ARM
#if (defined(__ARM_NEON__) || defined(__ARM_NEON) || defined(__arm_neon__) || defined(__arm_neon) || defined(__TARGET_FEATURE_NEON))
#   define ARM_NEON   (1)
#   define SUPPORTS_ARM_NEON   (1)
#else
#   define SUPPORTS_ARM_NEON   (0)
#endif
#ifdef __ARM_FEATURE_DSP
#   define ARM_DSP   (1)
#   define SUPPORTS_ARM_DSP   (1)
#else
#   define SUPPORTS_ARM_DSP   (0)
#endif
#ifdef __ARM_FEATURE_SAT
#   define ARM_SAT   (1)
#   define SUPPORTS_ARM_SAT   (1)
#else
#   define SUPPORTS_ARM_SAT   (0)
#endif
#ifdef __ARM_FEATURE_SIMD32
#   define ARM_SIMD32   (1)
#   define SUPPORTS_ARM_SIMD32   (1)
#else
#   define SUPPORTS_ARM_SIMD32   (0)
#endif
#ifdef __ARM_FEATURE_IDIV
#   define ARM_IDIV   (1)
#   define SUPPORTS_ARM_IDIV   (1)
#else
#   define SUPPORTS_ARM_IDIV   (0)
#endif
#ifdef __ARM_WMMX
#   define ARM_WMMX   (1)
#   define SUPPORTS_ARM_WMMX   (1)
#   define CPU_WMMX   (1)
#else
#   define SUPPORTS_ARM_WMMX   (0)
#   define CPU_WMMX   (0)
#endif
#ifdef __ARM_FEATURE_CRYPTO
#   define ARM_CRYPTO   (1)
#   define SUPPORTS_ARM_CRYPTO   (1)
#else
#   define SUPPORTS_ARM_CRYPTO   (0)
#endif
#ifdef __ARM_FEATURE_CRC32
#   define ARM_CRC32   (1)
#   define SUPPORTS_ARM_CRC32   (1)
#else
#   define SUPPORTS_ARM_CRC32   (0)
#endif
#ifdef __ARM_FEATURE_DIRECTED_ROUNDING
#   define ARM_DIRECTED_ROUNDING   (1)
#   define SUPPORTS_ARM_DIRECTED_ROUNDING   (1)
#else
#   define SUPPORTS_ARM_DIRECTED_ROUNDING   (0)
#endif
#ifdef __ARM_FEATURE_NUMERIC_MAXMIN
#   define ARM_MAXMIN   (1)
#   define SUPPORTS_ARM_MAXMIN   (1)
#else
#   define SUPPORTS_ARM_MAXMIN   (0)
#endif
#ifdef __ARM_FP16_ARGS
#   define ARM_FP16_ARGS   (1)
#   define SUPPORTS_ARM_FP16_ARGS   (1)
#else
#   define SUPPORTS_ARM_FP16_ARGS   (0)
#endif
// POWERPC
#if (defined(__ppc64__) || defined(__ppc64) || defined(__powerpc64__) || defined(__PPC64__) || defined(_ARCH_PPC64) || defined(ppc64le) || defined(ppc64be) || defined(_ARCH_PPC64GRSQ) || defined(_ARCH_PPC64GR) || defined(_ARCH_PPC64) || defined(_ARCH_PWR4) || defined(_ARCH_PWR5))  // PPC64
#   define POWERPC64   (1)
#   define ARCHPOWERPC64   (1)
#endif  // PPC64
#if (defined(__ppc32__) || defined(__ppc32) || defined(__powerpc32__) || defined(__PPC32__) || defined(_ARCH_PPC32) || defined(ppc32le) || defined(ppc32be) || defined(_ARCH_PPC32GRSQ) || defined(_ARCH_PPC32GR) || defined(_ARCH_PPC32) || defined(_ARCH_PWR3))  // PPC32
#   define POWERPC32   (1)
#   define ARCHPOWERPC32   (1)
#endif  // PPC32
// SPARC
#if (defined(__sparc_v8__) || defined(__sparcv8) || defined(__supersparc__) || defined(__supersparc)) // SuperSparc & UltraSparc
#   define SUPERSPARC   (1)
#   define SUPER_SPARC   (1)
#elif (defined(__sparc_v9__) || defined(__sparcv9) || defined(__ultrasparc__) || defined(__ultrasparc__))
#   define ULTRASPARC   (1)
#   define ULTRA_SPARC   (1)
#endif // SuperSparc & UltraSparc
#if (defined(__sparc64__) || defined(__sparc64) || defined(__SPARC64__) || defined(ULTRASPARC))  // SPARC64
#   define SPARC64   (1)
#   define ARCHSPARC64   (1)
#endif  // SPARC64
// AMD & X86
#if (defined(__amd64__) || defined(__amd64) || defined(_M_AMD64))  // AMD64
#   define AMD64   (1)
#   define ARCHAMD64   (1)
#endif  // AMD64
#if ((defined(__x86_64) || defined(__x86_64__)) && defined(_X86_))
#   undef _X86_
#endif
#if (defined(i386) || defined(__i386) || defined(__i386__) || defined(__I386) || defined(__I386__) || defined(__386))
#   define I386    (1)
#endif
#undef _M_IX86
#if (defined(__i486__) || defined(__i486) || defined(__pentium__) || defined(__pentiumpro__) || defined(__pentium4__) || defined(__k8__) || defined(__athlon__) || defined(__k6__))
#   define I486    (1)
#   define _M_IX86   400
#elif (defined(__i586__) || defined(__i586))
#   define I586    (1)
#   define _M_IX86   500
#elif (defined(__i686__) || defined(__i686))
#   define I686    (1)
#   define _M_IX86   600
#endif
#ifdef __MMX__
#   define CPU_MMX   (1)
#else
#   define CPU_MMX   (0)
#endif
#ifdef __SSE__
#   define CPU_SSE   (1)
#   ifndef __SSE_MATH__
#      define __SSE_MATH__   (1)
#   endif
#else
#   define CPU_SSE   (0)
#endif
#ifdef __SSE2__
#   define CPU_SSE2   (1)
#   ifndef __SSE2_MATH__
#      define __SSE2_MATH__   (1)
#   endif
#else
#   define CPU_SSE2   (0)
#endif
#ifdef __SSE3__
#   define CPU_SSE3   (1)
#   ifndef __SSE3_MATH__
#      define __SSE3_MATH__   (1)
#   endif
#else
#   define CPU_SSE3   (0)
#endif
#ifdef __SSE4_1__
#   define CPU_SSE4_1   (1)
#   ifndef __SSE4_1_MATH__
#      define __SSE4_1_MATH__   (1)
#   endif
#else
#   define CPU_SSE4_1   (0)
#endif
#ifdef __SSE4_2__
#   define CPU_SSE4_2   (1)
#   ifndef __SSE4_2_MATH__
#      define __SSE4_2_MATH__   (1)
#   endif
#else
#   define CPU_SSE4_2   (0)
#endif
#ifdef __SSSE3__
#   define CPU_SSSE3   (1)
#   ifndef __SSSE3_MATH__
#      define __SSSE3_MATH__   (1)
#   endif
#else
#   define CPU_SSSE3   (0)
#endif
#ifdef __SSE2AVX__
#   define CPU_SSE2AVX   (1)
#   ifndef __SSE2AVX_MATH__
#      define __SSE2AVX_MATH__   (1)
#   endif
#else
#   define CPU_SSE2AVX   (0)
#endif
#ifdef __AVX__
#   define CPU_AVX   (1)
#   ifndef __AVX_MATH__
#      define __AVX_MATH__   (1)
#   endif
#else
#   define CPU_AVX   (0)
#endif
#if (defined(__AVX2__) || defined(__core_avx2__) || defined(__tune_core_avx2__) || defined(__core_avx2))
#   define CPU_AVX2   (1)
#   ifndef __AVX2_MATH__
#      define __AVX2_MATH__   (1)
#   endif
#else
#   define CPU_AVX2   (0)
#endif
#ifdef __AVX512BW__
#   define CPU_AVX512BW   (1)
#else
#   define CPU_AVX512BW   (0)
#endif
#ifdef __AVX512CD__
#   define CPU_AVX512CD   (1)
#else
#   define CPU_AVX512CD   (0)
#endif
#ifdef __AVX512DQ__
#   define CPU_AVX512DQ   (1)
#else
#   define CPU_AVX512DQ   (0)
#endif
#ifdef __AVX512ER__
#   define CPU_AVX512ER   (1)
#else
#   define CPU_AVX512ER   (0)
#endif
#ifdef __AVX512F__
#   define CPU_AVX512F   (1)
#else
#   define CPU_AVX512F   (0)
#endif
#ifdef __AVX512IFMA__
#   define CPU_AVX512IFMA   (1)
#else
#   define CPU_AVX512IFMA   (0)
#endif
#ifdef __AVX512PF__
#   define CPU_AVX512PF   (1)
#else
#   define CPU_AVX512PF   (0)
#endif
#ifdef __AVX512VBMI__
#   define CPU_AVX512VBMI   (1)
#else
#   define CPU_AVX512VBMI   (0)
#endif
#ifdef __AVX512VL__
#   define CPU_AVX512VL   (1)
#else
#   define CPU_AVX512VL   (0)
#endif
#ifdef __ADX__
#   define CPU_ADX   (1)
#else
#   define CPU_ADX   (0)
#endif
#ifdef __F16C__
#   define CPU_F16C   (1)
#else
#   define CPU_F16C   (0)
#endif
#ifdef __POPCNT__
#   define CPU_POPCNT   (1)
#else
#   define CPU_POPCNT   (0)
#endif
#ifdef __BMI__
#   define CPU_BMI   (1)
#else
#   define CPU_BMI   (0)
#endif
#ifdef __BMI2__
#   define CPU_BMI2   (1)
#else
#   define CPU_BMI2   (0)
#endif
#ifdef __AES__
#   define CPU_AES   (1)
#else
#   define CPU_AES   (0)
#endif
#ifdef __FMA__
#   define CPU_FMA   (1)
#else
#   define CPU_FMA   (0)
#endif
#ifdef __FXSR__
#   define CPU_FXSR   (1)
#else
#   define CPU_FXSR   (0)
#endif
#ifdef __LZCNT__
#   define CPU_LZCNT   (1)
#else
#   define CPU_LZCNT   (0)
#endif
#ifdef __RDRND__
#   define CPU_RDRND   (1)
#else
#   define CPU_RDRND   (0)
#endif
#ifdef __RDSEED__
#   define CPU_RDSEED   (1)
#else
#   define CPU_RDSEED   (0)
#endif
#ifdef __XSAVE__
#   define CPU_XSAVE   (1)
#else
#   define CPU_XSAVE   (0)
#endif
#ifdef __XSAVEOPT__
#   define CPU_XSAVEOPT   (1)
#else
#   define CPU_XSAVEOPT   (0)
#endif
#ifdef __PCLMUL__
#   define CPU_PCLMUL   (1)
#else
#   define CPU_PCLMUL   (0)
#endif
#ifdef __FSGSBASE__
#   define CPU_FSGSBASE   (1)
#else
#   define CPU_FSGSBASE   (0)
#endif
#ifdef __PRFCHW__
#   define CPU_PRFCHW   (1)
#else
#   define CPU_PRFCHW   (0)
#endif
#ifdef __MWAITX__
#   define CPU_MWAITX   (1)
#else
#   define CPU_MWAITX   (0)
#endif
#ifdef __PKU__
#   define CPU_PKU   (1)
#else
#   define CPU_PKU   (0)
#endif


// SYMMETRIC MULTI-PROCESSING (SMP)

#if (defined(CONFIG_SMP) && defined(__SMP__))
#   undef CONFIG_SMP
#elif (defined(CONFIG_SMP) && (!defined(__SMP__)))
#   define __SMP__   (1)
#   undef CONFIG_SMP
#endif
#if (defined(__SMP__) && __SMP__)
#   define IS_SMP   (1)
#   undef __SMP__
#   define __SMP__   (1)
#else
#   define IS_SMP   (0)
#   undef __SMP__
#endif


// MULTITHREADING & REENTRANCY MACROS

#if ((!defined(_REENT_SMALL)) && defined(_WANT_REENT_SMALL))
#   define _REENT_SMALL   (1)
#endif
#if ((!defined(USE_SMALL_REENT)) && defined(_REENT_SMALL))
#   define USE_SMALL_REENT   (_REENT_SMALL)
#endif
#ifndef _REENTRANT
#   define _REENTRANT   (1)
#endif
#ifndef IS_REENTRANT
#   define IS_REENTRANT   (_REENTRANT)
#endif
#if ((!defined(__USE_REENTRANT)) && (defined(_REENTRANT) || defined(_REENT_SMALL) || defined(_THREAD_SAFE)))
#   define __USE_REENTRANT   (1)
#elif (!defined(__USE_REENTRANT))
#   define __USE_REENTRANT   (0)
#endif
#ifndef SUPPORTS_REENTRANCY
/** Code is reentrant if it can be interrupted in the middle of execution and then safely called again before previous invocations complete execution (reentrancy differs from that of thread-safety in multi-threaded environments) */
#   define SUPPORTS_REENTRANCY   (__USE_REENTRANT)
#endif
#ifndef SINGLE_THREAD_P
/** Checks if the program is in single-thread mode and avoids all cancellation save/restore code */
#   define SINGLE_THREAD_P   (1)
#endif
#ifndef RTLD_SINGLE_THREAD_P
#   define RTLD_SINGLE_THREAD_P   (1)
#endif
#if ((!defined(SUPPORTS_RTEMS)) && defined(__rtems__))
/** Indicates support for POSIX 1003.1b (such as threads & mutexes) */
#   define SUPPORTS_RTEMS   (1)
#elif ((!defined(SUPPORTS_RTEMS)) && (!defined(__rtems__)))
/** Indicates support for POSIX 1003.1b (such as threads & mutexes) */
#   define SUPPORTS_RTEMS   (0)
#endif
#if ((!defined(SUPPORTS_THREADS)) && (SINGLE_THREAD_P || defined(__SINGLE_THREAD__)))
#   define SUPPORTS_THREADS   (0)
#elif (!defined(SUPPORTS_THREADS))
#   define SUPPORTS_THREADS   (1)
#endif


// FLOAT-POINT UNIT TYPE

#if ((defined(__SOFTFP__) || defined(_SOFT_FLOAT_) || defined(_SOFT_FLOAT) || defined(__TARGET_FPU_NONE) || defined(__mips_soft_float)) && (!(defined(__mcffpu__) || defined(__VFP_FP__) || defined(__ARM_FP) || defined(__UCLIBC_HAS_FPU__))))
/** Test if the platform emulates a FPU */
#   define IS_SOFT_FP   (1)
/** Defined if the platform emulates a FPU */
#   define SOFT_FP   (1)
/** Test if the platform has a physical FPU */
#   define IS_HARD_FP   (0)
#   define CPU_SOFTFP   (1)
#   define IS_SOFTFP   (1)
#   define IS_NOT_SOFTFP   (0)
#elif (defined(__TARGET_FPU_SOFTVFP) || defined(__TARGET_FPU_VFP) || defined(__SOFTVFP__))
/** Test if the platform emulates a FPU */
#   define IS_SOFT_FP   (1)
/** Defined if the platform emulates a FPU */
#   define SOFT_FP   (1)
/** Test if the platform has a physical FPU */
#   define IS_HARD_FP   (1)
#   define CPU_SOFTFP   (1)
#   define IS_SOFTFP   (1)
#   define IS_NOT_SOFTFP   (0)
#else
/** Test if the platform emulates a FPU */
#   define IS_SOFT_FP   (0)
/** Test if the platform has a physical FPU */
#   define IS_HARD_FP   (1)
/** Defined if the platform has a physical FPU */
#   define HARD_FP   (1)
#   define CPU_SOFTFP   (0)
#   define IS_SOFTFP   (0)
#   define IS_NOT_SOFTFP   (1)
#endif
#if (CPU_SOFTFP == 0)
#   define NO_SOFTFP   (1)
#else
#   define HAS_SOFTFP   (1)
#endif
#define ARCH_FLOATS_ARE_IEEE   (1)
#define arch_floats_are_IEEE   ARCH_FLOATS_ARE_IEEE
#define floats_are_IEEE   ARCH_FLOATS_ARE_IEEE
#define FLOATS_ARE_IEEE   ARCH_FLOATS_ARE_IEEE


// CPU ENDIANNESS

#if (defined(__THUMBEB__) || defined(__ARMEB__) || defined(__AARCH64EB__))
#   define ARM_BIG_ENDIAN    (1)
#elif (defined(__THUMBEL__) || defined(__ARMEL__) || defined(__AARCH64EL__))
#   define ARM_LITTLE_ENDIAN    (1)
#elif defined(__MICROBLAZEEB__)
#   define MICROBLAZE_BIG_ENDIAN    (1)
#elif defined(__MICROBLAZEEL__)
#   define MICROBLAZE_LITTLE_ENDIAN    (1)
#elif (defined(__MIPSEB__) || defined(_MIPSEB) || defined(__MIPSEB))
#   define MIPS_BIG_ENDIAN    (1)
#elif (defined(__MIPSEL__) || defined(_MIPSEL) || defined(__MIPSEL))
#   define MIPS_LITTLE_ENDIAN    (1)
#elif defined(ppc64be)
#   define POWERPC_BIG_ENDIAN    (1)
#   define POWERPC64_BIG_ENDIAN    (1)
#elif defined(ppc64le)
#   define POWERPC_LITTLE_ENDIAN    (1)
#   define POWERPC64_LITTLE_ENDIAN    (1)
#endif  // CPU Endianness


// CPU TYPE

#if (defined(__THUMBEB__) || defined(__THUMBEL__) || defined(__thumb) || defined(__thumb__) || defined(__THUMB) || defined(__THUMB__))
#   define ARM_THUMB1    (1)
#endif
#if (defined(__thumb2__) || defined(__thumb2) || defined(__THUMB2__) || defined(__THUMB2))
#   define ARM_THUMB2    (1)
#endif
#if (defined(ARM_THUMB1) || defined(ARM_THUMB2) || defined(__TARGET_FEATURE_THUMB) || (defined(__TARGET_ARCH_THUMB) && (__TARGET_ARCH_THUMB > 0)))
#   define ARM_THUMB    (1)
#endif
#if (defined(__x86_64__) || defined(__x86_64)|| defined(__X86_64__) || defined(_M_X64) || defined(AMD64))  // x86-64
#   define X86_64   (1)
#   define ARCHX86_64   (1)
#elif (defined(I386) || defined(I486) || defined(I586) || defined(I686) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__))  // x86
#   define X86   (1)
#   define I386   (1)
#   define ARCHX86   (1)
#   define ARCHI386   (1)
#elif (defined(__ALPHA__) || defined(__alpha) || defined(__alpha__) || defined(_M_ALPHA) || defined(__alpha_ev4__) || defined(__alpha_ev5__) || defined(__alpha_ev6__) || defined(__Alpha_AXP))  // Alpha
#   define ALPHA   (1)
#   define ARCHALPHA   (1)
#elif (defined(__ARC__) || defined(__arc) || defined(__arc__))  // Arc
#   define ARC   (1)
#   define ARCHARC   (1)
#elif (defined(__aarch64__) || defined(__aarch64) || defined(__AARCH64__) || defined(__AARCH64) || defined(__AARCH64EB__) || defined(__AARCH64EL__) || defined(__ARM_ARCH_ISA_A64))  // Aarch64 (ARM64)
#   define ARM64   (1)
#   define AARCH64   (1)
#   define ARCHARM64   (1)
#   define ARCHAARCH64   (1)
#elif (defined(__ARMEL__) || defined(__ARMEB__) || defined(__ARM_EABI__) || defined(__arm__) || defined(__ARM_ARCH) || defined(__arm) || defined(_ARM) || defined(_M_ARM) || defined(ARM_THUMB) || defined(ARM_THUMB1) || defined(ARM_THUMB2) || defined(__ARM_FEATURE_DSP) || defined(__TARGET_ARCH_ARM))
#   define ARM   (1)
#   define ARCHARM   (1)
#elif (defined(__avr) || defined(__avr__) || defined(__AVR__) || defined(__AVR) || defined(__AVRASM_VERSION__) || defined(__AVR_AT94K__))  // AVR
#   define AVR   (1)
#   define ARCHAVR   (1)
#elif (defined(__bfin) || defined(__bfin__) || defined(__BFIN__) || defined(__BFIN))  // Blackfin
#   define BLACKFIN   (1)
#   define ARCHBLACKFIN   (1)
#elif (defined(__coldfire) || defined(__coldfire__) || defined(__COLDFIRE__) || defined(__COLDFIRE) || defined(__mcoldfire__) || defined(__MCOLDFIRE__) || defined(__MCF5206__) || defined(__mcf5206__) || defined(__MCF5307__) || defined(__mcf5307__) || defined(__mcffpu__))  // Freescale ColdFire
#   define COLDFIRE   (1)
#   define ARCHCOLDFIRE   (1)
#elif (defined(__convex__) || defined(__convex) || defined(__convex_c1__) || defined(__convex_c2__) || defined(__convex_c32__) || defined(__convex_c34__) || defined(__convex_c38__))  // Convex
#   define CONVEX   (1)
#   define ARCHCONVEX   (1)
#elif (defined(__CRIS__) || defined(__cris) || defined(__cris__) || defined(__CRIS_arch_version))  // Cris
#   define CRIS   (1)
#   define ARCHCRIS   (1)
#elif (defined(__epiphany__) || defined(__epiphany) || defined(__EPIPHANY__))  // Epiphany
#   define EPIPHANY   (1)
#   define ARCHEPIPHANY   (1)
#elif (defined(__hppa__) || defined(__hppa) || defined(__HPPA__) || defined(_PA_RISC1_0) || defined(_PA_RISC1_1) || defined(__HPPA11__) || defined(__PA7100__) || defined(_PA_RISC2_0) || defined(__RISC2_0__) || defined(__HPPA20__) || defined(__PA8000__))  // HPPA
#   define HPPA   (1)
#   define ARCHHPPA   (1)
#elif (defined(__i960__) || defined(_I960) || defined(_I960_) || defined(__I960__) || defined(__i960) || defined(_M_I960) || defined(_ARCH_I960))  // i960
#   define I960   (1)
#   define ARCHI960   (1)
#elif (defined(__ia64__) || defined(_IA64) || defined(_IA64_) || defined(__IA64__) || defined(__ia64) || defined(_M_IA64) || defined(_ARCH_IA64) || defined(__itanium__))  // Itanium
#   define ITANIUM   (1)
#   define IA64   (1)
#   define ARCHITANIUM   (1)
#elif (defined(__MC68K__) || defined(__m68k__) || defined(__m68k) || defined(__m68000) || defined(__m68000__) || defined(m68000) || defined(M68000) || defined(__mc68000__) || defined(__MC68000__) || defined(__mc68010__) || defined(__mc68020__) || defined(__MC68020__) || defined(__mc68030__) || defined(__MC68030__) || defined(__mc68040__) || defined(__mc68060__))  // Motorola 68k
#   define M68K   (1)
#   define MOTOROLA   (1)
#   define ARCHM68K   (1)
#   define ARCHMOTOROLA   (1)
#elif (defined(__MICROBLAZE__) || defined(_M_MICROBLAZE) || defined(__microblaze) || defined(__microblaze__) || defined(MICROBLAZE_LITTLE_ENDIAN) || defined(MICROBLAZE_BIG_ENDIAN))  // Microblaze
#   define MICROBLAZE   (1)
#   define ARCHMICROBLAZE   (1)
#elif (defined(__MIPS__) || defined(_M_MIPS) || defined(__mips) || defined(__mips__) || defined(__MIPS64__) || defined(_M_MIPS64) || defined(__mips64) || defined(__mips64__) || defined(_MIPS_SIM) || defined(MIPS_LITTLE_ENDIAN) || defined(MIPS_BIG_ENDIAN) || defined(_MIPS_ISA) || defined(_R3000) || defined(_R4000) || defined(_R5900) || defined(_MIPS_ISA_MIPS1) || defined(_MIPS_ISA_MIPS2) || defined(_MIPS_ISA_MIPS3) || defined(_MIPS_ISA_MIPS4) || defined(__MIPS_ISA2__) || defined(__MIPS_ISA3__) || defined(__MIPS_ISA4__)|| defined(__mips16))  // Mips
#   define MIPS   (1)
#   define ARCHMIPS   (1)
#   ifdef __mips16
#      error   "16-bit MIPS is not supported!"
#   elif ((defined(__MIPS64__) || defined(_M_MIPS64) || defined(__mips64) || defined(__mips64__) || defined(_R4000) || defined(_MIPS_ISA_MIPS3) || defined(__MIPS_ISA3__) || defined(_MIPS_ISA_MIPS4) || defined(__MIPS_ISA4__)) || (__mips == 64))
#      define MIPS64   (1)
#      define ARCHMIPS64   (1)
#   else
#      define MIPS32   (1)
#      define ARCHMIPS32   (1)
#   endif
#elif (defined(__nios_little_endian__) || defined(__nios_big_endian__) || defined(__nios__) || defined(__NIOS__) || defined(__nios) || defined(__NIOS) || defined(nios) || defined(NIOS))  // NIOS
#   ifndef NIOS
#      define NIOS   (1)
#   endif
#   define ARCHNIOS   (1)
#elif (defined(__nios2_little_endian__) || defined(__nios2_big_endian__) || defined(__nios2__) || defined(__NIOS2__) || defined(__nios2) || defined(__NIOS2) || defined(nios2) || defined(NIOS2))  // NIOS II
#   ifndef NIOS2
#      define NIOS2   (1)
#   endif
#   define ARCHNIOS2   (1)
#elif (defined(__or1k__) || defined(_M_OR1K) || defined(__or1k) || defined(__OR1K__))  // Or1k
#   define OR1K   (1)
#   define ARCHOR1K   (1)
#elif (defined(__PARISC__) || defined(_M_PARISC) || defined(__parisc) || defined(__parisc__))  // Parisc
#   define PARISC   (1)
#   define ARCHPARISC   (1)
#elif (defined(__powerpc) || defined(__powerpc__) || defined(__POWERPC__) || defined(__ppc__) || defined(__ppc) || defined(POWERPC64) || defined(__PPC__) || defined(_ARCH_PPC) || defined(_M_PPC) || defined(__ppc601__) || defined(__ppc603__) || defined(__ppc604__) || defined(POWERPC_LITTLE_ENDIAN) || defined(POWERPC_BIG_ENDIAN) || defined(_ARCH_PPCGR) || defined(_ARCH_PWR) || defined(_ARCH_PWR2) || defined(_ARCH_PWR3) || defined(_ARCH_PWR5X) || defined(_POWER) || defined(_ARCH_PPC970) || defined(__PPCGECKO__) || defined(__PPCBROADWAY__) || defined(_XENON))  // PowerPC
#   define POWERPC   (1)
#   define ARCHPOWERPC   (1)
#elif (defined(__RS64__) || defined(_M_RS64) || defined(__rs64) || defined(__rs64__) || defined(_ARCH_RS64) || defined(_IBMR2) || defined(__THW_RS6000))  // RS64 (RS/6000)
#   define RS64   (1)
#   define ARCHRS64   (1)
#elif (defined(__RS64II__) || defined(_M_RS64II) || defined(__rs64ii) || defined(__rs64ii__) || defined(__RS64B__) || defined(_M_RS64B) || defined(__rs64b) || defined(__rs64b__) || defined(_ARCH_RS64B))  // RS64II
#   define RS64B   (1)
#   define RS64II   (1)
#   define ARCHRS64B   (1)
#   define ARCHRS64II   (1)
#elif (defined(__RS64III__) || defined(_M_RS64III) || defined(__rs64iii) || defined(__rs64iii__) || defined(__RS64C__) || defined(_M_RS64C) || defined(__rs64c) || defined(__rs64c__) || defined(_ARCH_RS64C))  // RS64III
#   define RS64C   (1)
#   define RS64III   (1)
#   define ARCHRS64C   (1)
#   define ARCHRS64III   (1)
#elif (defined(__s390x__) || defined(__s390x) || defined(__zarch__) || defined(__SYSC_ZARCH__))  // z/Architecture (SystemZ)
#   define S390X   (1)
#   define ZARCH   (1)
#   define SYSTEMZ   (1)
#   define ARCHS390X   (1)
#   define ARCHSYSTEMZ   (1)
#elif (defined(__THW_370__) || defined(__s390__) || defined(__s390) || defined(__systemz))  // System/390 (SystemZ)
#   define S390   (1)
#   define SYSTEM390   (1)
#   define SYSTEMZ   (1)
#   define ARCHS390   (1)
#elif (defined(__sparc__) || defined(__sparc32__) || defined(__SPARC__) || defined(__sparc) || defined(sparc) || defined(__sparclite__) || defined(__sparclite86x__) || defined(__sparclet__) || defined(SUPER_SPARC) || defined(ULTRA_SPARC) || defined(SPARC64))  // Sparc
#   define SPARC   (1)
#   define ARCHSPARC   (1)
#elif (defined(__SH__) || defined(_M_SH) || defined(__sh) || defined(__sh__) || defined(__superh__) || defined(__superh) || defined(__SUPERH__) || defined(__SUPERH) || defined(__sh1__) || defined(__sh2__) || defined(__sh3__) || defined(__sh4__) || defined(__sh5__) || defined(__SH1__) || defined(__SH2__) || defined(__SH3__) || defined(__SH4__) || defined(__SH5__))  // SuperH
#   define SH   (1)
#   define SUPERH   (1)
#   define ARCHSH   (1)
#   define ARCHSUPERH   (1)
#elif (defined(__TMS470__) || defined(__tms470__) || defined(__TMS470) || defined(__tms470))  // TMS470
#   define TMS470   (1)
#   define ARCHTMS470   (1)
#elif (defined(__VAX__) || defined(__vax__) || defined(__VAX) || defined(__vax) || defined(vax))  // VAX
#   define VAX   (1)
#   define ARCHVAX   (1)
#elif (defined(__XSTORMY__) || defined(__xstormy__) || defined(__XSTORMY) || defined(__xstormy) || defined(__xstormy16__) || defined(__XSTORMY16__))  // XStormy
#   define XSTORMY   (1)
#   define ARCHXSTORMY   (1)
#elif (defined(__XTENSA__) || defined(__xtensa__) || defined(__XTENSA) || defined(__xtensa))  // Xtensa
#   define XTENSA   (1)
#   define ARCHXTENSA   (1)
#elif (defined(__Z8000__) || defined(__z8000__) || defined(__Z8000) || defined(__z8000))  // Z8000
#   define Z8000   (1)
#   define ARCHZ8000   (1)
#endif  // CPU TYPE
#if (IS_SOFT_FP && defined(ARM) && (!defined(ARM_HAVE_VFP)))
#   define ARM_HAVE_VFP   (1)
#else
#   define ARM_HAVE_VFP   (0)
#endif


// CPU BIT-WIDTH

#if ((defined(MINGW64) || defined(X86_64) || defined(AMD64) || defined(ALPHA) || defined(ITANIUM) || defined(ARM64) || defined(MIPS64) || defined(POWERPC64) || defined(ZARCH) || defined(__LP64__) || defined(__LLP64__) || defined(_WIN64) || defined(WIN64) || defined(__64BIT__)) && !(defined(BLACKFIN) || defined(COLDFIRE) || defined(M68K) || defined(MICROBLAZE) || defined(NIOS) || defined(NIOS2) || defined(UNICORE) || defined(VAX) || defined(XTENSA)))  // 32-bit || 64-bit
/** Test if the system is 64-bit */
#   define IS_64   (1)
/** Test if the system is 32-bit */
#   define IS_32   (0)
/** Defined if the system is 64-bit */
#   define ENV64BIT   (1)
/** Defined if the system is 64-bit */
#   define TARGET_64BIT   (1)
/** Defined if the system is 64-bit */
#   define __HAIKU_ARCH_64_BIT   (1)
/** Defined if the system is 64-bit */
#   define HAIKU_ARCH_64_BIT   (1)
/** Defined if the system is 64-bit */
#   define HAIKU_HOST_PLATFORM_64_BIT   (1)
#   define FSSH_B_HAIKU_64_BIT   (1)
#   define B_HAIKU_64_BIT   (1)
#else  // 32-bit
/** Test if the system is 32-bit */
#   define IS_32   (1)
/** Test if the system is 64-bit */
#   define IS_64   (0)
/** Defined if the system is 32-bit */
#   define ENV32BIT   (1)
/** Defined if the system is 32-bit */
#   define TARGET_64BIT   (1)
/** Defined if the system is 32-bit */
#   define __HAIKU_ARCH_32_BIT   (1)
/** Defined if the system is 32-bit */
#   define HAIKU_ARCH_32_BIT   (1)
/** Defined if the system is 32-bit */
#   define HAIKU_HOST_PLATFORM_32_BIT   (1)
#   define FSSH_B_HAIKU_32_BIT   (1)
#   define B_HAIKU_32_BIT   (1)
#endif  // 32-bit || 64-bit
#if (defined(HAIKU_ARCH_64_BIT) && (!defined(HAIKU_ARCH_BITS)))
#   define HAIKU_ARCH_BITS   64
#elif (defined(HAIKU_ARCH_32_BIT) && (!defined(HAIKU_ARCH_BITS)))
#   define HAIKU_ARCH_BITS   32
#endif
#ifndef __HAIKU_ARCH_BITS
#   define __HAIKU_ARCH_BITS   HAIKU_ARCH_BITS
#endif
#ifndef HAIKU_ARCH_PHYSICAL_BITS
#   define HAIKU_ARCH_PHYSICAL_BITS   HAIKU_ARCH_BITS
#endif
#ifndef __HAIKU_ARCH_PHYSICAL_BITS
#   define __HAIKU_ARCH_PHYSICAL_BITS   HAIKU_ARCH_BITS
#endif
#if (HAIKU_ARCH_PHYSICAL_BITS == 32)
#   define HAIKU_ARCH_PHYSICAL_32_BIT   (1)
#   define __HAIKU_ARCH_PHYSICAL_32_BIT   (1)
#   define B_HAIKU_PHYSICAL_32_BIT   (1)
#   define B_HAIKU_PHYSICAL_BITS   (32)
#elif (HAIKU_ARCH_PHYSICAL_BITS == 64)
#   define HAIKU_ARCH_PHYSICAL_64_BIT   (1)
#   define __HAIKU_ARCH_PHYSICAL_64_BIT   (1)
#   define B_HAIKU_PHYSICAL_64_BIT   (1)
#   define B_HAIKU_PHYSICAL_BITS   (64)
#else
#   error   "Unsupported physical bitness!"
#endif


// CPU & PLATFORM INFO

#if (IS_64 && defined(SUPERH))  // SUPERH64
#   define SUPERH64   (1)
#endif  // SUPERH64
#if (defined(__pentium2__) || defined(__pentium2) || defined(_ARCH_PENTIUM2))
#   define PENTIUMII   (1)
#   define PENTIUM2   (1)
#endif
#if (defined(__pentiumpro__) || defined(__pentiumpro))
#   define PENTIUM_PRO   (1)
#endif
#if (defined(__haswell__) || defined(__haswell) || defined(__tune_haswell__))
#   define HASWELL   (1)
#endif
#if (defined(__broadwell__) || defined(__broadwell) || defined(__tune_broadwell__))
#   define BROADWELL   (1)
#endif
#if (defined(PENTIUM2) || defined(PENTIUM_PRO) || defined(__tune_sandybridge__) || defined(__tune_ivybridge__) || defined(HASWELL) || defined(BROADWELL) || defined(__tune_bonnell__) || defined(__tune_silvermont__) || defined(__tune_knl__) || defined(__tune_knight__))  // INTEL
#   define INTEL   (1)
#endif  // INTEL
#ifdef X86_64  // INTEL64
#   define INTEL64   (1)
#endif  // INTEL64
// INSTRUCTION SET DESIGN
#if (defined(ALPHA) || defined(AMBER) || defined(ARM64) || defined(ARM) || defined(AVR) || defined(BLACKFIN) || defined(MICROBLAZE) || defined(MIPS) || defined(NIOS) || defined(NIOS2) || defined(PARISC) || defined(PICOBLAZE) || defined(POWERPC) || defined(POWERPC64) || defined(SPARC) || defined(SUPERH) || defined(SUPERH64) || defined(UNICORE) || defined(XTENSA))
#   define RISC   (1)
#   define IS_RISC   (1)
#   define IS_CISC   (0)
#   define IS_EPIC   (0)
#elif (defined(COLDFIRE) || defined(M68K) || defined(SYSTEMZ) || defined(VAX) || defined(X86) || defined(X86_64) || defined(ZARCH))
#   define CISC   (1)
#   define IS_RISC   (0)
#   define IS_CISC   (1)
#   define IS_EPIC   (0)
#elif defined(ITANIUM)
/** Explicitly Parallel Instruction Computing (EPIC) */
#   define EPIC   (1)
#   define IS_RISC   (0)
#   define IS_CISC   (0)
#   define IS_EPIC   (1)
#else
#   error   "Add support for the target system (RISC/CISC)."
#endif
#ifdef __INTEL__
#   define __HAIKU_ARCH   "x86"
#   if (defined(__GNUC__) && (__GNUC__ == 2))
#      define __HAIKU_ARCH_ABI   "x86_gcc2"
#   else
#      define __HAIKU_ARCH_ABI   "x86"
#   endif
#   define __HAIKU_ARCH_X86   1
#   define __HAIKU_ARCH_PHYSICAL_BITS   64
#elif defined(X86_64)
#   define __HAIKU_ARCH   "x86_64"
#   define __HAIKU_ARCH_ABI   "x86_64"
#   define __HAIKU_ARCH_X86_64   1
#   ifndef HAIKU_ARCH_BITS
#      define HAIKU_ARCH_BITS   64
#   endif
#   ifndef __HAIKU_ARCH_BITS
#      define __HAIKU_ARCH_BITS   64
#   endif
#elif defined(POWERPC)
#   define __HAIKU_ARCH   "ppc"
#   define __HAIKU_ARCH_ABI   "ppc"
#   define __HAIKU_ARCH_PPC   1
#   define __HAIKU_ARCH_PHYSICAL_BITS   64
#   define __HAIKU_BIG_ENDIAN   1
#elif defined(M68K)
#   define __HAIKU_ARCH   "m68k"
#   define __HAIKU_ARCH_ABI   "m68k"
#   define __HAIKU_ARCH_M68K   1
#   define __HAIKU_BIG_ENDIAN   1
#elif defined(MIPS)
#   define __HAIKU_ARCH   "mipsel"
#   define __HAIKU_ARCH_ABI   "mipsel"
#   define __HAIKU_ARCH_MIPSEL   1
#elif defined(ARM)
#   define __HAIKU_ARCH   "arm"
#   define __HAIKU_ARCH_ABI   "arm"
#   define __HAIKU_ARCH_ARM   1
#elif defined(ARMEB)
#   define __HAIKU_ARCH   "armeb"
#   define __HAIKU_ARCH_ABI   "armeb"
#   define __HAIKU_ARCH_ARM   1
#   define __HAIKU_BIG_ENDIAN   1
#else
#   error   "Unsupported architecture!"
#endif
#if (defined(HAIKU_ARCH_X86) && defined(__GNUC__) && (__GNUC__ == 2))
/** BeOS R5 binary compatibility */
#   define HAIKU_BEOS_COMPATIBLE   (1)
/** BeOS R5 binary compatibility */
#   define __HAIKU_BEOS_COMPATIBLE   (1)
#endif
#ifndef HAIKU_ARCH_64_BIT
/** BeOS R5 compatible types */
#   define HAIKU_BEOS_COMPATIBLE_TYPES   (1)
/** BeOS R5 compatible types */
#   define __HAIKU_BEOS_COMPATIBLE_TYPES   (1)
#endif


// STACK PROTECTOR MACROS

#ifndef SSP_STRONG
#   ifndef __SSP_STRONG__
#      define SSP_STRONG   (1)
#      define __SSP_STRONG__   (1)
#   else
#      define SSP_STRONG   __SSP_STRONG__
#   endif
#endif
#if ((!defined(STACK_PROTECTOR_PRESENT)) && (defined(__SSP__) || defined(__SSP_ALL__) || defined(__SSP_STRONG__) || defined(__SSP_EXPLICIT__)))
#   define STACK_PROTECTOR_PRESENT   (1)
#elif (!defined(STACK_PROTECTOR_PRESENT))
#   define STACK_PROTECTOR_PRESENT   (0)
#endif
#ifndef IS_STACK_PROTECTOR_PRESENT
#   define IS_STACK_PROTECTOR_PRESENT   STACK_PROTECTOR_PRESENT
#endif
#if ((!defined(IS_STACK_PROTECTOR_STRONG)) && defined(__SSP_STRONG__))
#   define IS_STACK_PROTECTOR_STRONG   (1)
#elif (!defined(IS_STACK_PROTECTOR_STRONG))
#   define IS_STACK_PROTECTOR_STRONG   (0)
#endif
#if ((!defined(IS_STACK_PROTECTOR_EXPLICIT)) && defined(__SSP_EXPLICIT__))
#   define IS_STACK_PROTECTOR_EXPLICIT   (1)
#elif (!defined(IS_STACK_PROTECTOR_EXPLICIT))
#   define IS_STACK_PROTECTOR_EXPLICIT   (0)
#endif


// SANITIZER MACROS

#if ((!defined(SANITIZER_PRESENT)) && (defined(__SANITIZE_ADDRESS__) || defined(__SANITIZE_THREAD__)))
#   define SANITIZER_PRESENT   (1)
#elif (!defined(SANITIZER_PRESENT))
#   define SANITIZER_PRESENT   (0)
#endif
#ifndef IS_SANITIZER_PRESENT
#   define IS_SANITIZER_PRESENT   SANITIZER_PRESENT
#endif


// FEATURE & DATATYPE SUPPORT

#ifndef __STDC_ISO_10646__
/** Conforms to ISO/IEC 10646; International standard that defines a character set that is exactly equivalent to the Unicode repertoire; wchar_t uses Unicode 8.0.0. Version 8.0 of the Unicode Standard is synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published 2015-05-15) */
#   define __STDC_ISO_10646__   (201505L)  // wchar_t must be 32-bits
#endif
#ifndef __STDC_IEC_559__
/** Conforms to the ISO/IEC/IEEE 60559 (IEEE754/IEC559) standards; Industry standard for representing floating-point numbers; https://en.wikipedia.org/wiki/IEEE_754-1985 */
#   define __STDC_IEC_559__   (1)
#endif
#ifndef __GCC_IEC_559
/** Conforms to the ISO/IEC/IEEE 60559 (IEEE754/IEC559) standards; Industry standard for representing floating-point numbers; this does not indicate support for decimal floating point or the IEEE 754 binary16 and binary128 types */
#   define __GCC_IEC_559   (2)
#endif
#ifndef __STDC_IEC_559_COMPLEX__
/** Conforms to the ISO/IEC/IEEE 60559 (IEEE754/IEC559) standards for complex numbers; Industry standard for representing complex floating-point numbers */
#   define __STDC_IEC_559_COMPLEX__   (1)
#endif
#ifndef __GCC_IEC_559_COMPLEX
/** Conforms to the ISO/IEC/IEEE 60559 (IEEE754/IEC559) standards for complex numbers; Industry standard for representing complex floating-point numbers */
#   define __GCC_IEC_559_COMPLEX   (2)
#endif
#if ((!defined(BITS64)) && ((defined(_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS >= 64)) || defined(__UINT64_MAX__) || defined(__UINT_FAST64_MAX__)))
/** Indicates that 64-bit integer types are supported by the compiler */
#   define BITS64   (1)
#elif (!defined(BITS64))
#   define BITS64   (0)
#endif
// LIBGCC MACROS
#ifdef __LIBGCC_HAS_SF_MODE__
#   define LIBGCC2_HAS_SF_MODE   (1)
#else
#   define LIBGCC2_HAS_SF_MODE   (0)
#   define __LIBGCC_HAS_SF_MODE__   (0)
#endif
#ifdef __LIBGCC_HAS_DF_MODE__
#   define LIBGCC2_HAS_DF_MODE   (1)
#else
#   define LIBGCC2_HAS_DF_MODE   (0)
#   define __LIBGCC_HAS_DF_MODE__   (0)
#endif
#ifdef __LIBGCC_HAS_XF_MODE__
#   define LIBGCC2_HAS_XF_MODE   (1)
#else
#   define LIBGCC2_HAS_XF_MODE   (0)
#   define __LIBGCC_HAS_XF_MODE__   (0)
#endif
#ifdef __LIBGCC_HAS_TF_MODE__
#   define LIBGCC2_HAS_TF_MODE   (1)
#else
#   define LIBGCC2_HAS_TF_MODE   (0)
#   define __LIBGCC_HAS_TF_MODE__   (0)
#endif
// INTEGER DATATYPE SUPPORT
#if ((!defined(SUPPORTS_INT64)) && (defined(__UINT64_TYPE__) || defined(__INT64_TYPE__) || defined(__INT64_C_SUFFIX__) || defined(__INT64_C) || defined(__INT64_MAX__)))
/** Indicates that 64-bit integer types are supported by the compiler */
#   define SUPPORTS_INT64   (1)
#endif
#if ((defined(SIZEOF_INT128) || defined(__SIZEOF_INT128__) || defined(BOOST_HAS_INT128) || defined(__int128_t) || defined(__uint128_t) || defined(__uint128)) || (defined(_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS > 64)))
#   define HAVE_INT128   (1)
#else
#   define HAVE_INT128   (0)
#endif
#define INT128_UNSUPPORTED   HAVE_INT128
#define UINT128_UNSUPPORTED   HAVE_INT128
#define SUPPORTS_INT128   HAVE_INT128
#define SUPPORTS_UINT128   HAVE_INT128
#if ((defined(SIZEOF_INT256) || defined(__SIZEOF_INT256__) || defined(BOOST_HAS_INT256) || defined(__int256_t) || defined(__uint256_t) || defined(__uint256)) || (defined(_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS > 128)))
#   define HAVE_INT256   (1)
#else
#   define HAVE_INT256   (0)
#endif
#define INT256_UNSUPPORTED   HAVE_INT256
#define UINT256_UNSUPPORTED   HAVE_INT256
#define SUPPORTS_INT256   HAVE_INT256
#define SUPPORTS_UINT256   HAVE_INT256
#if ((defined(SIZEOF_INT512) || defined(__SIZEOF_INT512__) || defined(BOOST_HAS_INT512) || defined(__int512_t) || defined(__uint512_t) || defined(__uint512)) || (defined(_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS > 256)))
#   define HAVE_INT512   (1)
#else
#   define HAVE_INT512   (0)
#endif
#define INT512_SUPPORTED   HAVE_INT512
#define UINT512_SUPPORTED   HAVE_INT512
#define SUPPORTS_INT512   HAVE_INT512
#define SUPPORTS_UINT512   HAVE_INT512
#ifndef HAVE_LONG_LONG_INT
#   define HAVE_LONG_LONG_INT   (1)
#endif
#ifndef HAVE_LONG_INT
#   define HAVE_LONG_INT   (1)
#endif
#ifndef HAVE_INT64
#   define HAVE_INT64   (1)
#endif
#ifndef HAVE_INT32
#   define HAVE_INT32   (1)
#endif
#ifndef HAVE_INT16
#   define HAVE_INT16   (1)
#endif
#ifndef HAVE_INT8
#   define HAVE_INT8   (1)
#endif
#ifndef HAVE_INT4
#   define HAVE_INT4   (0)
#endif
#ifndef HAVE_INT2
#   define HAVE_INT2   (0)
#endif
// FLOAT-POINT DATATYPE SUPPORT
#if (defined(__SIZEOF_FLOAT8__) || defined(SIZEOF_FLOAT8) || defined(__ARM_FP8_FORMAT_IEEE) || defined(ARCHAVR))
#   define FLOAT8_SUPPORTED   (1)
#   define MINIFLOAT_SUPPORTED   (1)
#   define SUPPORTS_FLOAT8   (1)
#else
#   define FLOAT8_SUPPORTED   (0)
#   define MINIFLOAT_SUPPORTED   (0)
#   define SUPPORTS_FLOAT8   (0)
#endif
#if (defined(__SIZEOF_FLOAT16__) || defined(SIZEOF_FLOAT16) || defined(__ARM_FP16_FORMAT_IEEE) || defined(ARCHAVR))
#   define FLOAT16_SUPPORTED   (1)
#   define SUPPORTS_FLOAT16   (1)
#else
#   define FLOAT16_SUPPORTED   (0)
#   define SUPPORTS_FLOAT16   (0)
#endif
#if (defined(__SIZEOF_FLOAT24__) || defined(SIZEOF_FLOAT24) || defined(__ARM_FP24_FORMAT_IEEE) || defined(ARCHAVR))
#   define FLOAT24_SUPPORTED   (1)
#   define SUPPORTS_FLOAT24   (1)
#else
#   define FLOAT24_SUPPORTED   (0)
#   define SUPPORTS_FLOAT24   (0)
#endif
#if (defined(__SIZEOF_FLOAT32__) || defined(SIZEOF_FLOAT32) || defined(__SIZEOF_FLOAT__) || defined(SIZEOF_FLOAT))
#   define FLOAT32_SUPPORTED   (1)
#   define SUPPORTS_FLOAT32   (1)
#else
#   define FLOAT32_SUPPORTED   (0)
#   define SUPPORTS_FLOAT32   (0)
#endif
#if (defined(__SIZEOF_FLOAT80__) || defined(SIZEOF_FLOAT80))
#   define FLOAT80_SUPPORTED   (1)
#   define SUPPORTS_FLOAT80   (1)
#else
#   define FLOAT80_SUPPORTED   (0)
#   define SUPPORTS_FLOAT80   (0)
#endif
#if (defined(__SIZEOF_FLOAT96__) || defined(SIZEOF_FLOAT96))
#   define FLOAT96_SUPPORTED   (1)
#   define SUPPORTS_FLOAT96   (1)
#else
#   define FLOAT96_SUPPORTED   (0)
#   define SUPPORTS_FLOAT96   (0)
#endif
#if (defined(__SIZEOF_FLOAT128__) || defined(SIZEOF_FLOAT128))
/** 128-bit quad-precision floats may be supported via the synonymous datatypes tetra, float128_t, __float128, and float128 */
#   define FLOAT128_SUPPORTED   (1)
#   define SUPPORTS_FLOAT128   (1)
#else
/** 128-bit quad-precision floats may be supported via the synonymous datatypes tetra, float128_t, __float128, and float128 */
#   define FLOAT128_SUPPORTED   (0)
#   define SUPPORTS_FLOAT128   (0)
#endif
#if (defined(__SIZEOF_FLOAT256__) || defined(SIZEOF_FLOAT256))
/** 256-bit octa-precision floats may be supported via the synonymous datatypes float256_t, __float256, and float256 */
#   define FLOAT256_SUPPORTED   (1)
#   define SUPPORTS_FLOAT256   (1)
#else
/** 256-bit octa-precision floats may be supported via the synonymous datatypes float256_t, __float256, and float256 */
#   define FLOAT256_SUPPORTED   (0)
#   define SUPPORTS_FLOAT256   (0)
#endif
#if (defined(__SIZEOF_FLOAT512__) || defined(SIZEOF_FLOAT512))
/** 512-bit hexadeca-precision floats may be supported via the synonymous datatypes float512_t, __float512, and float512 */
#   define FLOAT512_SUPPORTED   (1)
#   define SUPPORTS_FLOAT512   (1)
#else
/** 512-bit hexadeca-precision floats may be supported via the synonymous datatypes float512_t, __float512, and float512 */
#   define FLOAT512_SUPPORTED   (0)
#   define SUPPORTS_FLOAT512   (0)
#endif
// STDFIX DATATYPE SUPPORT
#if (defined(__SFRACT_IBIT__) || defined(__SFRACT_MIN__) || defined(__SFRACT_MAX__) || defined(__USACCUM_EPSILON__) || defined(__USACCUM_MIN__))
#   define STDFIX_SUPPORTED   (1)
#   define SUPPORTS_STDFIX   (1)
#   define SUPPORTS_ACCUM   (1)
#   define SUPPORTS_FRACT   (1)
#   define SUPPORTS_SAT   (1)
#else
#   define STDFIX_SUPPORTED   (0)
#   define SUPPORTS_STDFIX   (0)
#   define SUPPORTS_ACCUM   (0)
#   define SUPPORTS_FRACT   (0)
#   define SUPPORTS_SAT   (0)
#endif
#ifdef LIBGCC2_GNU_PREFIX
#   define LIBGCC2_FIXEDBIT_GNU_PREFIX   (1)
#endif
// DECIMAL-FLOAT-POINT DATATYPE SUPPORT
#if (((!defined(__STDC_DEC_FP__)) && (!defined(__STDC_WANT_DEC_FP__))) && (defined(__FLT_DECIMAL_DIG__) || defined(__DBL_DECIMAL_DIG__) || defined(__LDBL_DECIMAL_DIG__) || defined(__DECIMAL_DIG__) || defined(__DEC32_MAX__)))
/** Conforms to the ISO/IEC/IEEE 60559 (IEEE754-2008/IEC559) standards for decimal floating-points; Industry standard for representing decimal floating-point numbers */
#   define __STDC_DEC_FP__   (1)
/** Conforms to the ISO/IEC/IEEE 60559 (IEEE754-2008/IEC559) standards for decimal floating-points; Industry standard for representing decimal floating-point numbers */
#   define __STDC_WANT_DEC_FP__   (1)
#endif
#if (defined(__STDC_DEC_FP__) || defined(__STDC_WANT_DEC_FP__) || defined(__IBM_DFP__))
/** If this equals 1, then decimal float-points are supported; Conforms to the ISO/IEC/IEEE 60559 (IEEE754-2008/IEC559) standards for decimal floating-points; Industry standard for representing decimal floating-point numbers */
#   define SUPPORTS_DECIMAL_FLOATS   (1)
#   define SUPPORTS_DECIMAL32   (1)
#   define SUPPORTS_DECIMAL64   (1)
#else
/** If this equals 1, then decimal float-points are supported; Conforms to the ISO/IEC/IEEE 60559 (IEEE754-2008/IEC559) standards for decimal floating-points; Industry standard for representing decimal floating-point numbers */
#   define SUPPORTS_DECIMAL_FLOATS   (0)
#   define SUPPORTS_DECIMAL32   (0)
#   define SUPPORTS_DECIMAL64   (0)
#endif
#if (SUPPORTS_DECIMAL_FLOATS && (defined(__LDBL_DECIMAL_DIG__) || defined(__DECIMAL_DIG__) || defined(__LDBL_DECIMAL_DIG__) || defined(__DEC128_MAX__) || defined(__DEC128_MAX_EXP__)))
/** If this equals 1, then long double decimal numbers (decimal128) are supported */
#   define SUPPORTS_DECIMAL_LONG_DOUBLE   (1)
/** If this equals 1, then long double decimal numbers (decimal128) are supported */
#   define SUPPORTS_DECIMAL128   (1)
#else
/** If this equals 1, then long double decimal numbers (decimal128) are supported */
#   define SUPPORTS_DECIMAL_LONG_DOUBLE   (0)
/** If this equals 1, then long double decimal numbers (decimal128) are supported */
#   define SUPPORTS_DECIMAL128   (0)
#endif
#if (SUPPORTS_DECIMAL_FLOATS && (defined(__SIZEOF_DECFLOAT256__) || defined(__DEC256_MAX__) || defined(__DEC256_MAX_EXP__)))
/** If this equals 1, then decimal256 are supported */
#   define SUPPORTS_DECIMAL256   (1)
#else
/** If this equals 1, then decimal256 are supported */
#   define SUPPORTS_DECIMAL256   (0)
#endif
#if (SUPPORTS_DECIMAL_FLOATS && (defined(__SIZEOF_DECFLOAT512__) || defined(__DEC512_MAX__) || defined(__DEC512_MAX_EXP__)))
/** If this equals 1, then decimal512 are supported */
#   define SUPPORTS_DECIMAL512   (1)
#else
/** If this equals 1, then decimal512 are supported */
#   define SUPPORTS_DECIMAL512   (0)
#endif
// COMPLEX DATATYPE SUPPORT
#if ((defined(__STDC_IEC_559_COMPLEX__) && (__STDC_IEC_559_COMPLEX__ > 0)) || (defined(__GCC_IEC_559_COMPLEX) && (__GCC_IEC_559_COMPLEX > 0)))
#   ifndef SUPPORTS_COMPLEX
#      define SUPPORTS_COMPLEX   (1)
#   endif
#   ifndef SUPPORTS_IMAGINARY
#      define SUPPORTS_IMAGINARY   (1)
#   endif
#   if (SUPPORTS_FLOAT128 && (!(defined(ARM) || defined(ARM64) || defined(X86) || defined(X86_64))))
#      define SUPPORTS_COMPLEX128   (1)
#      define SUPPORTS_COMPLEX_FLOAT128   (1)
#   else
#      define SUPPORTS_COMPLEX128   (0)
#      define SUPPORTS_COMPLEX_FLOAT128   (0)
#   endif
#   if SUPPORTS_FLOAT256
#      define SUPPORTS_COMPLEX256   (1)
#      define SUPPORTS_COMPLEX_FLOAT256   (1)
#   else
#      define SUPPORTS_COMPLEX256   (0)
#      define SUPPORTS_COMPLEX_FLOAT256   (0)
#   endif
#else
#   ifndef SUPPORTS_COMPLEX
#      define SUPPORTS_COMPLEX   (0)
#   endif
#   ifndef SUPPORTS_IMAGINARY
#      define SUPPORTS_IMAGINARY   (0)
#   endif
#   define SUPPORTS_COMPLEX128   (0)
#   define SUPPORTS_COMPLEX_FLOAT128   (0)
#   define SUPPORTS_COMPLEX256   (0)
#   define SUPPORTS_COMPLEX_FLOAT256   (0)
#endif
#if ((SUPPORTS_COMPLEX == 1) && (defined(__SIZEOF_COMPLEX_INT__)))
#   ifndef SUPPORTS_COMPLEX_INT
#      define SUPPORTS_COMPLEX_INT   (1)
#   endif
#   ifndef SUPPORTS_COMPLEX_INT16
#      define SUPPORTS_COMPLEX_INT16   (1)
#   endif
#   ifndef SUPPORTS_COMPLEX_INT32
#      define SUPPORTS_COMPLEX_INT32   (1)
#   endif
#   ifndef SUPPORTS_COMPLEX_INT64
#      define SUPPORTS_COMPLEX_INT64   (1)
#   endif
#   if (SUPPORTS_INT128 && (!(defined(ARM) || defined(ARM64) || defined(X86) || defined(X86_64))))
#      define SUPPORTS_COMPLEX_INT128   (1)
#   else
#      define SUPPORTS_COMPLEX_INT128   (0)
#   endif
#   if SUPPORTS_INT256
#      define SUPPORTS_COMPLEX_INT256   (1)
#   else
#      define SUPPORTS_COMPLEX_INT256   (0)
#   endif
#   if SUPPORTS_INT512
#      define SUPPORTS_COMPLEX_INT512   (1)
#   else
#      define SUPPORTS_COMPLEX_INT512   (0)
#   endif
#else
#   ifndef SUPPORTS_COMPLEX_INT
#      define SUPPORTS_COMPLEX_INT   (0)
#   endif
#   ifndef SUPPORTS_COMPLEX_INT16
#      define SUPPORTS_COMPLEX_INT16   (0)
#   endif
#   ifndef SUPPORTS_COMPLEX_INT32
#      define SUPPORTS_COMPLEX_INT32   (0)
#   endif
#   ifndef SUPPORTS_COMPLEX_INT64
#      define SUPPORTS_COMPLEX_INT64   (0)
#   endif
#   ifndef SUPPORTS_COMPLEX_INT128
#      define SUPPORTS_COMPLEX_INT128   (0)
#   endif
#   ifndef SUPPORTS_COMPLEX_INT256
#      define SUPPORTS_COMPLEX_INT256   (0)
#   endif
#   ifndef SUPPORTS_COMPLEX_INT512
#      define SUPPORTS_COMPLEX_INT512   (0)
#   endif
#endif
// CONDITION-CODE DATATYPE SUPPORT
#if (IS_RISC && (!defined(SUPPORTS_CONDITION_CODE)))
#   define SUPPORTS_CONDITION_CODE   (1)
#elif ((!(IS_RISC)) && (!defined(SUPPORTS_CONDITION_CODE)))
#   define SUPPORTS_CONDITION_CODE   (0)
#endif
// BLK DATATYPE SUPPORT
#ifdef MOTOROLA
#   define SUPPORTS_BLK   (1)
#else
#   define SUPPORTS_BLK   (0)
#endif
// MATH FEATURES SUPPORT
#ifndef __NO_MATH_INLINES
/** When compiling in strict ISO C compatible mode, inline functions must not be used since they do not set the `errno` variable correctly */
#   define __NO_MATH_INLINES   (0)
#endif
#ifndef NO_MATH_INLINES
/** When compiling in strict ISO C compatible mode, inline functions must not be used since they do not set the `errno` variable correctly */
#   define NO_MATH_INLINES   (0)
#endif
#if ((!defined(FAST_MATH)) && (defined(__FAST_MATH__) || defined(__fast_math__)))
#   define FAST_MATH   (1)
#else
#   undef __fast_math__
#   undef __FAST_MATH__
#   define FAST_MATH   (0)
#endif
#if ((!defined(FINITE_MATH_ONLY)) && (defined(__FINITE_MATH_ONLY__) && (__FINITE_MATH_ONLY__ > 0x0)))
#   define FINITE_MATH_ONLY   (1)
#else
#   undef __FINITE_MATH_ONLY__
#   define __FINITE_MATH_ONLY__   (0)
#   define FINITE_MATH_ONLY   (0)
#endif
#if (defined(__WANT_LONG_DOUBLE_FORMAT__) || (defined(__LONG_DOUBLE_128__) || defined(__LONG_DOUBLE_64__)))
#   undef __NO_LONG_DOUBLE_MATH
#   undef NO_LONG_DOUBLE_MATH
#   undef NO_LDOUBLE_MATH
#   undef __MATH_DECLARE_LDOUBLE
#   define __MATH_DECLARE_LDOUBLE   (0)
#endif  // MATH_DECLARE_LDOUBLE
#ifdef __LONG_DOUBLE_128__  // __WANT_LONG_DOUBLE_FORMAT__
#   undef __WANT_LONG_DOUBLE_FORMAT__
#   define __WANT_LONG_DOUBLE_FORMAT__   (128)
#elif defined(__LONG_DOUBLE_64__)
#   undef __WANT_LONG_DOUBLE_FORMAT__
#   define __WANT_LONG_DOUBLE_FORMAT__   (64)
#endif  // __WANT_LONG_DOUBLE_FORMAT__
// Signal that we do (or do not) have a `long double`; This enables/disables the declaration of all the `long double` functions
#if (defined(__NO_LONG_DOUBLE_MATH) || defined(NO_LONG_DOUBLE_MATH) || defined(NO_LDOUBLE_MATH))
#   undef __LONG_DOUBLE_MATH_OPTIONAL
#   undef LONG_DOUBLE_MATH_OPTIONAL
#   undef __MATH_DECLARE_LDOUBLE
#   undef __NO_LONG_DOUBLE_MATH
#   undef NO_LONG_DOUBLE_MATH
#   undef NO_LDOUBLE_MATH
#   define __LONG_DOUBLE_MATH_OPTIONAL   (0)
#   define LONG_DOUBLE_MATH_OPTIONAL   (0)
#   define __MATH_DECLARE_LDOUBLE   (0)
#   define __NO_LONG_DOUBLE_MATH   (1)
#   define NO_LONG_DOUBLE_MATH   (1)
#   define NO_LDOUBLE_MATH   (1)
#   define SUPPORTS_LONG_DOUBLE   (0)
#elif ((defined(__LONG_DOUBLE_MATH_OPTIONAL) || defined(LONG_DOUBLE_MATH_OPTIONAL) || defined(__MATH_DECLARE_LDOUBLE)) && (defined(__SIZEOF_LONG_DOUBLE__) || defined(SIZEOF_LONG_DOUBLE) || defined(__LONGDOUBLE64)))
#   undef __LONG_DOUBLE_MATH_OPTIONAL
#   undef LONG_DOUBLE_MATH_OPTIONAL
#   undef __MATH_DECLARE_LDOUBLE
#   undef __NO_LONG_DOUBLE_MATH
#   undef NO_LONG_DOUBLE_MATH
#   undef NO_LDOUBLE_MATH
#   define __LONG_DOUBLE_MATH_OPTIONAL   (1)
#   define LONG_DOUBLE_MATH_OPTIONAL   (1)
#   define __MATH_DECLARE_LDOUBLE   (1)
#   define __NO_LONG_DOUBLE_MATH   (0)
#   define NO_LONG_DOUBLE_MATH   (0)
#   define NO_LDOUBLE_MATH   (0)
#   define SUPPORTS_LONG_DOUBLE   (1)
#else
#   define __LONG_DOUBLE_MATH_OPTIONAL   (1)
#   define LONG_DOUBLE_MATH_OPTIONAL   (1)
#   define __MATH_DECLARE_LDOUBLE   (1)
#   define __NO_LONG_DOUBLE_MATH   (0)
#   define NO_LONG_DOUBLE_MATH   (0)
#   define NO_LDOUBLE_MATH   (0)
#   define SUPPORTS_LONG_DOUBLE   (1)
#endif  // SUPPORTS_LONG_DOUBLE
#if (SUPPORTS_LONG_DOUBLE && (defined(__LDBL_MAX_EXP__) && (__LDBL_MAX_EXP__ > 999999)))
#   error   "Float-point buffers are too small!"
#endif
// VARIOUS FEATURE SUPPORT
#ifndef __STDC_NO_THREADS__
/** No support for C11 <threads.h> */
#   define __STDC_NO_THREADS__   (1)
#endif
#ifndef __STDC_HOSTED__
/** Defined if the target has a hosted environment (complete standard C library) */
#   define __STDC_HOSTED__   (1)
#endif
#if ((!defined(IS_HOSTED)) && defined(__STDC_HOSTED__))
/** Returns 1 (true) if the target has a hosted environment (complete standard C library) */
#   define IS_HOSTED   (1)
#elif (!defined(IS_HOSTED))
/** Returns 1 (true) if the target has a hosted environment (complete standard C library) */
#   define IS_HOSTED   (0)
#endif
#ifndef __STD_UTF_8__
/** Values of type uchar8_t have UTF-8 encoding, otherwise, the encoding of uchar8_t is unspecified */
#   define __STD_UTF_8__   (1)
#endif
#ifndef __STDC_UTF_8__
/** Values of type uchar8_t have UTF-8 encoding, otherwise, the encoding of uchar8_t is unspecified */
#   define __STDC_UTF_8__   __STD_UTF_8__
#endif
#ifndef __STD_UTF_16__
/** Values of type char16_t have UTF-16 encoding, otherwise, the encoding of char16_t is unspecified */
#   define __STD_UTF_16__   (1)
#endif
#ifndef __STDC_UTF_16__
/** Values of type char16_t have UTF-16 encoding, otherwise, the encoding of char16_t is unspecified */
#   define __STDC_UTF_16__   __STD_UTF_16__
#endif
#ifndef __STD_UTF_32__
/** Values of type char32_t have UTF-32 encoding, otherwise, the encoding of char32_t is unspecified */
#   define __STD_UTF_32__   (1)
#endif
#ifndef __STDC_UTF_32__
/** Values of type char32_t have UTF-32 encoding, otherwise, the encoding of char32_t is unspecified */
#   define __STDC_UTF_32__   __STD_UTF_32__
#endif
#ifndef __STDC_UTF_64__
/** Values of type char64_t have UTF-64 encoding, otherwise, the encoding of char64_t is unspecified */
#   define __STDC_UTF_64__   __STD_UTF_64__
#endif
#if (!(defined(_LOOSE_KERNEL_NAMES) && defined(__KERNEL_STRICT_NAMES)))
/** Suppress kernel-name space pollution unless user expressedly asks for it */
#   define __KERNEL_STRICT_NAMES
#endif
#if ((!defined(SUPPORTS_ALIGN_SPECIFIER)) && (defined(__IBM__ALIGN) || defined(__GNUC__) || defined(COMPILER_ILEC)))
#   define SUPPORTS_ALIGN_SPECIFIER   (1)
#elif (!defined(SUPPORTS_ALIGN_SPECIFIER))
#   define SUPPORTS_ALIGN_SPECIFIER   (0)
#endif
#if ((!defined(SUPPORTS_ATTRIBUTES)) && (defined(__IBM_ATTRIBUTES) || defined(__GNUC__) || defined(COMPILER_ILEC)))
#   define SUPPORTS_ATTRIBUTES   (1)
#elif (!defined(SUPPORTS_ATTRIBUTES))
#   define SUPPORTS_ATTRIBUTES   (0)
#endif
#if ((!defined(SUPPORTS_EXTENSION_KEYWORD)) && (defined(__IBM_EXTENSION_KEYWORD) || defined(__GNUC__) || defined(COMPILER_ILEC)))
#   define SUPPORTS_EXTENSION_KEYWORD   (1)
#elif (!defined(SUPPORTS_EXTENSION_KEYWORD))
#   define SUPPORTS_EXTENSION_KEYWORD   (0)
#endif
#if ((!defined(SUPPORTS_INCLUDE_NEXT)) && (defined(__IBM_INCLUDE_NEXT) || defined(__GNUC__) || defined(COMPILER_ILEC)))
#   define SUPPORTS_INCLUDE_NEXT   (1)
#elif (!defined(SUPPORTS_INCLUDE_NEXT))
#   define SUPPORTS_INCLUDE_NEXT   (0)
#endif
#if ((!defined(SUPPORTS_VARIADIC_MACROS)) && (defined(__IBM_MACRO_WITH_VA_ARGS) || defined(__GNUC__) || defined(COMPILER_ILEC)))
#   define SUPPORTS_VARIADIC_MACROS   (1)
#elif (!defined(SUPPORTS_VARIADIC_MACROS))
#   define SUPPORTS_VARIADIC_MACROS   (0)
#endif
#if ((!defined(SUPPORTS_TYPEOF)) && (defined(__IBM_TYPEOF__) || defined(__GNUC__) || defined(COMPILER_ILEC)))
#   define SUPPORTS_TYPEOF   (1)
#elif (!defined(SUPPORTS_TYPEOF))
#   define SUPPORTS_TYPEOF   (0)
#endif


// SUPPORTED HEADERS

#define STDC_HEADERS   (1)
#define HAVE_ALLOCA   (1)
#define HAVE_ARPA_FTP_H   (1)
#define HAVE_ARPA_INET_H   (1)
#define HAVE_ARPA_NAMESER_H   (1)
#define HAVE_ARPA_TELNET_H   (1)
#define HAVE_ARPA_TFTP_H   (1)
#define HAVE_ASSERT_H   (1)
#define HAVE_ATOMIC_H   (1)
#define HAVE_CPIO_H   (1)
#define HAVE_CTYPE_H   (1)
#define HAVE_ERR_H   (0)
#define HAVE_ERRNO_H   (1)
#define HAVE_FENV_H   (1)
#define HAVE_FLOAT_H   (1)
#define HAVE_ICONV_H   (0)
#define HAVE_IFADDRS_H   (1)
#define HAVE_INTTYPES_H   (1)
#define HAVE_IPC_H   (1)
#define HAVE_ISO646_H   (1)
#define HAVE_LANGINFO_H   (1)
#define HAVE_LIMITS_H   (1)
#define HAVE_LOCALE_H   (1)
#define HAVE_MBCTYPE_H   (0)
#define HAVE_MATH_H   (1)
#define HAVE_MONETARY_H   (0)
#define HAVE_NET_ETHERNET_H   (1)
#define HAVE_NET_IF_H   (1)
#define HAVE_NET_IF_ARP_H   (1)
#define HAVE_NET_ROUTE_H   (1)
#define HAVE_NETINET_ICMP6_H   (1)
#define HAVE_NETINET_IF_ETHER_H   (1)
#define HAVE_NETINET_IN_H   (1)
#define HAVE_NETINET_TCP_H   (1)
#define HAVE_NL_TYPES_H   (1)
#define HAVE_NSCD_PROTO_H   (0)
#define HAVE_NSSWITCH_H   (0)
#define HAVE_OBSTACK_H   (1)
#define HAVE_PATHS_H   (1)
#define HAVE_POLL_H   (1)
#define HAVE_PPP_DEFS_H   (1)
#define HAVE_SETJMP_H   (1)
#define HAVE_SIGNAL_H   (0)
#define HAVE_STDALIGN_H   (1)
#define HAVE_STDARG_H   (1)
#define HAVE_STDATOMIC_H   (1)
#define HAVE_STDBOOL_H   (1)
#define HAVE_STDINT_H   (1)
#define HAVE_STDIO_H   (0)
#define HAVE_STDLIB_H   (0)
#define HAVE_STDNORETURN_H   (1)
#define HAVE_STRERROR_R   (0)
#define HAVE_STRING_H   (1)
#define HAVE_STRINGS_H   (1)
#define HAVE_STROPTS_H   (0)
#define HAVE_SYSLOG_H   (0)
#define HAVE_SYS_FANOTIFY_H   (1)
#define HAVE_SYS_INOTIFY_H   (1)
#define HAVE_SYS_IPC_H   (1)
#define HAVE_SYS_MMAN_H   (0)
#define HAVE_SYS_RESOURCE_H   (1)
#define HAVE_SYS_SEM_H   (1)
#define HAVE_SYS_SHM_H   (1)
#define HAVE_SYS_SENDFILE_H   (1)
#define HAVE_SYS_SIGNAL_H   (0)
#define HAVE_SYS_SOCKET_H   (1)
#define HAVE_SYS_STAT_H   (0)
#define HAVE_SYS_STATVFS_H   (0)
#define HAVE_SYS_TIME_H   (1)
#define HAVE_SYS_TIMES_H   (1)
#define HAVE_SYS_TYPES_H   (1)
#define HAVE_SYS_UIO_H   (1)
#define HAVE_SYS_UN_H   (1)
#define HAVE_TAR_H   (1)
#define HAVE_TGMATH_H   (1)
#define HAVE_TIME_H   (1)
#define HAVE_UCHAR_H   (1)
#define HAVE_ULIMIT_H   (1)
#define HAVE_UN_H   (1)
#define HAVE_UNISTD_H   (1)
#define HAVE_UTIME_H   (1)
#define HAVE_VADEFS_H   (1)
#define HAVE_VARARGS_H   (1)
#define HAVE_WCHAR_H   (0)
#define HAVE_WCTYPE_H   (1)
#define HAVE_XLOCALE_H   (1)
#define HAVE_MBSRTOWCS   (1)
#define HAVE_MBSTATE_T   (1)
#define HAVE_WCHAR_T   (1)


// NULL

#undef NULL
#if IS_CPLUSPLUS  // NULL
/** NULL; Void pointer */
#   define NULL   (0x0)
#else
/** NULL; Void pointer */
#   define NULL   ((void*)0x0)
#endif  // NULL
#ifndef _NULL
/** NULL; Void pointer */
#   define _NULL   NULL
#endif
#ifndef __null
/** NULL; Void pointer */
#   define __null   NULL
#endif
#ifndef __null__
/** NULL; Void pointer */
#   define __null__   NULL
#endif
#ifndef __DARWIN_NULL
/** NULL; Void pointer */
#   define __DARWIN_NULL   NULL
#endif
#ifndef DARWIN_NULL
/** NULL; Void pointer */
#   define DARWIN_NULL   NULL
#endif
#ifndef NIL
/** NULL; Void pointer */
#   define NIL   NULL
#endif
#ifndef nil
/** NULL; Void pointer */
#   define nil   NULL
#endif
#ifndef STMT_NIL
/** Expands to a syntactically valid empty statement */
#   define STMT_NIL   ((void)0x0)
#endif


// GNU, POSIX, XOPEN, & OTHER EXTENSIONS
/** Define to 1 to enable a few rarely used encodings */
#define ENABLE_EXTRA   (1)
#ifndef _ALL_SOURCE
/** Enable AIX 3 & Interix extensions */
#   define _ALL_SOURCE   (1)
#endif
#ifndef __EXTENSIONS__
/** Enable general Solaris extensions */
#   define __EXTENSIONS__   (1)
#endif
#ifndef _TANDEM_SOURCE
/** Enable HP NonStop extensions */
#   define _TANDEM_SOURCE   (1)
#endif
#ifndef _GNU_SOURCE  // _POSIX_SOURCE & _XOPEN_SOURCE
#   ifdef OSPOSIX  // Set special POSIX macros to include POSIX functionality
#      undef _POSIX_SOURCE
#      undef _POSIX_C_SOURCE
#      define _POSIX_SOURCE   (200809L)
#      define _POSIX_C_SOURCE   (200809L)
#   endif
#   ifdef OSUNIX  // Set special UNIX macros to include functionality described in the X/Open Portability Guide
#      define _XOPEN_SOURCE   (700)
#      define _XOPEN_VERSION   (700)
#      define _XOPEN_SOURCE_EXTENDED  // Include extra functions for X/Open Unix
#   endif
#endif  // _POSIX_SOURCE & _XOPEN_SOURCE
#if (defined(_BSD_SOURCE) || defined(_SVID_SOURCE))
#   undef  _DEFAULT_SOURCE
/** _BSD_SOURCE and _SVID_SOURCE are deprecated aliases for _DEFAULT_SOURCE; If _DEFAULT_SOURCE is present we do not issue a warning */
#   define _DEFAULT_SOURCE   (1)
#endif
// If _GNU_SOURCE was defined by the user, turn on all the other features
#ifdef _GNU_SOURCE  // Includes: ISO C89, ISO C99, POSIX.1, POSIX.2, BSD, SVID, X/Open, LFS, and GNU extensions
#   undef _ISOC95_SOURCE
#   define _ISOC95_SOURCE   (1)
#   undef _ISOC99_SOURCE
#   define _ISOC99_SOURCE   (1)
#   undef _ISOC11_SOURCE
#   define _ISOC11_SOURCE   (1)
#   undef _POSIX_SOURCE
#   define _POSIX_SOURCE   (1)
#   undef _POSIX_C_SOURCE
#   define _POSIX_C_SOURCE   (200809L)
#   undef _XOPEN_SOURCE
#   define _XOPEN_SOURCE   (700)
#   undef _XOPEN_SOURCE_EXTENDED
#   define _XOPEN_SOURCE_EXTENDED   (1)
#   undef _LARGEFILE64_SOURCE
#   define _LARGEFILE64_SOURCE   (1)
#   undef _DEFAULT_SOURCE
#   define _DEFAULT_SOURCE   (1)
#   undef _ATFILE_SOURCE
#   define _ATFILE_SOURCE   (1)
#   undef __USE_GNU
/** Adds features for ISO C89, ISO C99, POSIX.1, POSIX.2, BSD, SVID, X/Open, LFS, and GNU extensions */
#   define __USE_GNU   (1)
#endif
// If nothing (other than _GNU_SOURCE and _DEFAULT_SOURCE) is defined, define _DEFAULT_SOURCE
#if (defined(_DEFAULT_SOURCE) || (!defined(__STRICT_ANSI__) && (!(defined(_ISOC99_SOURCE) || defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) || defined(_XOPEN_SOURCE)))))
#   undef  _DEFAULT_SOURCE
#   define _DEFAULT_SOURCE   (1)
#endif
#if (defined(_ISOC11_SOURCE) || IS_C11)
/** This is to enable the ISO C11 extension */
#   define __USE_ISOC11   (1)
#endif
#if (IS_ISOC99 || IS_C99)
/** This is to enable the ISO C99 extension */
#   define __USE_ISOC99   (1)
#endif
// If none of the ANSI/POSIX macros are defined, or if _DEFAULT_SOURCE is defined, use POSIX.1-2008 (or another version depending on _XOPEN_SOURCE)
#ifdef _DEFAULT_SOURCE
#   if ((!defined(_POSIX_SOURCE)) && (!defined(_POSIX_C_SOURCE)))
#      define __USE_POSIX_IMPLICITLY   (1)
#   endif
#   undef  _POSIX_SOURCE
#   define _POSIX_SOURCE   (1)
#   undef  _POSIX_C_SOURCE
#   define _POSIX_C_SOURCE   (200809L)
#endif
#if ((!defined(__STRICT_ANSI__) || (defined(_XOPEN_SOURCE) && (_XOPEN_SOURCE - 0) >= 500)) && (!defined(_POSIX_SOURCE)) && (!defined(_POSIX_C_SOURCE)))
#   define _POSIX_SOURCE   (1)
#   if (defined(_XOPEN_SOURCE) && ((_XOPEN_SOURCE - 0) < 500))
#      define _POSIX_C_SOURCE   (2)
#   elif (defined(_XOPEN_SOURCE) && ((_XOPEN_SOURCE - 0) < 600))
#      define _POSIX_C_SOURCE   (199506L)
#   elif (defined(_XOPEN_SOURCE) && ((_XOPEN_SOURCE - 0) < 700))
#      define _POSIX_C_SOURCE   (200112L)
#   else
#      define _POSIX_C_SOURCE   (200809L)
#   endif
#   define __USE_POSIX_IMPLICITLY   (1)
#endif
#if (defined(_POSIX_SOURCE) || (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 1)) || defined(_XOPEN_SOURCE))
#   define __USE_POSIX   (1)
#endif
#if (defined(_POSIX_SOURCE) || (defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 2)) || defined(_XOPEN_SOURCE))
#   define __USE_POSIX2   (1)
#endif
#ifdef _POSIX_C_SOURCE
#   if ((_POSIX_C_SOURCE - 0) >= 199309L)
#      define __USE_POSIX199309   (1)
#   elif ((_POSIX_C_SOURCE - 0) >= 199506L)
#      define __USE_POSIX199506   (1)
#   elif ((_POSIX_C_SOURCE - 0) >= 200112L)
#      define __USE_XOPEN2K   1
#      undef __USE_ISOC95
#      define __USE_ISOC95   1
#      undef __USE_ISOC99
#      define __USE_ISOC99   1
#   elif ((_POSIX_C_SOURCE - 0) >= 200809L)
#      define __USE_XOPEN2K8   1
#      undef  _ATFILE_SOURCE
#      define _ATFILE_SOURCE   1
#   endif
#endif  // POSIX_C_SOURCE
#ifndef _POSIX_VERSION
#   define _POSIX_VERSION   (200809L)
#endif
#ifndef _POSIX2_VERSION
#   define _POSIX2_VERSION   (200809L)
#endif
#ifdef _XOPEN_SOURCE
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
#endif  // _XOPEN_SOURCE
#if (defined(_POSIX_VERSION) && (_POSIX_VERSION > 0))
#   define _XOPEN_XPG2   1
#   define _XOPEN_XPG3   1
#   define _XOPEN_XPG4   1
#   define _XOPEN_UNIX   1
#   define _XOPEN_ENH_I18N   1
#   define _XOPEN_CRYPT   1
#endif
#if (defined(_XOPEN_SOURCE ) && (!defined(__XSI_VISIBLE))) // __XSI_VISIBLE
#   if ((_XOPEN_SOURCE - 0) >= 700)
#      define __XSI_VISIBLE   700
#   elif ((_XOPEN_SOURCE - 0) >= 600)
#      define __XSI_VISIBLE   600
#   elif ((_XOPEN_SOURCE - 0) >= 500)
#      define __XSI_VISIBLE   500
#   endif
#endif  // __XSI_VISIBLE
#ifdef _POSIX_C_SOURCE
#   if (_POSIX_C_SOURCE >= 200809)
#      define __POSIX_VISIBLE   200809
#      define __ISO_C_VISIBLE   1999
#   elif (_POSIX_C_SOURCE >= 200112)
#      define __POSIX_VISIBLE   200112
#      define __ISO_C_VISIBLE   1999
#   elif (_POSIX_C_SOURCE >= 199506)
#      define __POSIX_VISIBLE   199506
#      define __ISO_C_VISIBLE   1990
#   elif (_POSIX_C_SOURCE >= 199309)
#      define __POSIX_VISIBLE   199309
#      define __ISO_C_VISIBLE   1990
#   elif (_POSIX_C_SOURCE >= 199209)
#      define __POSIX_VISIBLE   199209
#      define __ISO_C_VISIBLE   1990
#   elif (_POSIX_C_SOURCE >= 199009)
#      define __POSIX_VISIBLE   199009
#      define __ISO_C_VISIBLE   1990
#   else
#      define __POSIX_VISIBLE   198808
#      define __ISO_C_VISIBLE   0
#   endif  // _POSIX_C_SOURCE
#else
#   ifdef _ANSI_SOURCE
#      define __POSIX_VISIBLE   0
#      define __XSI_VISIBLE   0
#      define __BSD_VISIBLE   0
#      define __ISO_C_VISIBLE   1990
#   elif defined(_C99_SOURCE)
#      define __POSIX_VISIBLE   0
#      define __XSI_VISIBLE   0
#      define __BSD_VISIBLE   0
#      define __ISO_C_VISIBLE   1999
#   else  // Default environment
#      define __POSIX_VISIBLE   200809
#      define __XSI_VISIBLE   700
#      define __BSD_VISIBLE   1
#      define __ISO_C_VISIBLE   1999
#   endif
#endif
#ifndef __XPG_VISIBLE
#   define __XPG_VISIBLE   (700)
#endif
#ifndef __POSIX_VISIBLE
#   define __POSIX_VISIBLE   (200809)
#endif
#ifndef __ISO_C_VISIBLE
#   define __ISO_C_VISIBLE   (1999)
#endif
#ifndef __BSD_VISIBLE
#   define __BSD_VISIBLE   1
#endif
#ifndef __BIONIC__
#   define __BIONIC__   1
#endif
#ifndef __DARWIN_C_ANSI
/** Darwin extensions */
#   define __DARWIN_C_ANSI   (010000L)
#endif
#ifndef __DARWIN_C_FULL
/** Darwin extensions */
#   define __DARWIN_C_FULL   (900000L)
#endif
#ifdef _ANSI_SOURCE  // __DARWIN_C_LEVEL
#   define __DARWIN_C_LEVEL   __DARWIN_C_ANSI
#elif (defined(_POSIX_C_SOURCE) && (!defined(_DARWIN_C_SOURCE)) && (!defined(_NONSTD_SOURCE)))
#   define __DARWIN_C_LEVEL   _POSIX_C_SOURCE
#else
#   define __DARWIN_C_LEVEL   __DARWIN_C_FULL
#endif  // __DARWIN_C_LEVEL
#ifdef __DARWIN_ONLY_VERS_1050
/** _DARWIN_FEATURE_ONLY_VERS_1050 indicates that only those APIs updated in 10.5 exists; no pre-10.5 variants are available */
#   define _DARWIN_FEATURE_ONLY_VERS_1050   (1)
#endif
#if (defined(__DARWIN_ONLY_UNIX_CONFORMANCE) || (!defined(_DARWIN_FEATURE_ONLY_UNIX_CONFORMANCE)))
/** _DARWIN_FEATURE_ONLY_UNIX_CONFORMANCE indicates only UNIX conforming API are available (the legacy BSD APIs are not available) */
#   define _DARWIN_FEATURE_ONLY_UNIX_CONFORMANCE   (1)
#endif
#if (defined(__DARWIN_UNIX03) || (!defined(_DARWIN_FEATURE_UNIX_CONFORMANCE)))
/** _DARWIN_FEATURE_UNIX_CONFORMANCE indicates whether UNIX conformance is on, and specifies the conformance level (3 is SUSv3) */
#   define _DARWIN_FEATURE_UNIX_CONFORMANCE   (3)
#endif
#if (defined(__STRICT_ANSI__) && ((__STDC_VERSION__ - 0) < 199901L) && (!defined(__GNUG__)))
#   define __DARWIN_NO_LONG_LONG   (1)
#endif
#ifdef _LARGEFILE_SOURCE
#   define __USE_LARGEFILE   (1)
#endif
#ifdef _LARGEFILE64_SOURCE
#   define __USE_LARGEFILE64   (1)
#   define _FILE_OFFSET_BITS   (64)
#endif
#if (defined(_FILE_OFFSET_BITS) && (_FILE_OFFSET_BITS == 64))
#   define __USE_FILE_OFFSET64   (1)
#endif
#if (defined(_LARGEFILE64_SOURCE) || defined(__USE_LARGEFILE64) || defined(__USE_FILE_OFFSET64))
/** Indicates support for a 64-bit I/O interface, which allows large files and large file I/O; LFS symbols are also enabled */
#   define SUPPORTS_LARGEFILE64   (1)
#else
/** Indicates support for a 64-bit I/O interface, which allows large files and large file I/O; LFS symbols are also enabled */
#   define SUPPORTS_LARGEFILE64   (0)
#endif
#if (defined(_DEFAULT_SOURCE) && (!defined(__USE_MISC)))
#   define __USE_MISC   (1)
#endif
#if (defined(_ATFILE_SOURCE) && (!defined(__USE_ATFILE)))
#   define __USE_ATFILE   (1)
#endif
// If we do not have __REDIRECT, prototypes will be missing if __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64]
#if (defined(__USE_FILE_OFFSET64) && (!defined(__REDIRECT)))
#   define __USE_LARGEFILE   (1)
#   define __USE_LARGEFILE64   (1)
#endif
#if (defined(NODEBUG) || defined(NDEBUG) || (defined(DEBUG) && (!(DEBUG > 0))))
#   undef DEBUG
#   undef NODEBUG
#   undef NDEBUG
/** Enable/Disable Debugging */
#   define DEBUG   (0)
#   define NODEBUG   (1)
#   define NDEBUG   (1)
#else
#   undef DEBUG
#   undef NODEBUG
#   undef NDEBUG
/** Enable/Disable Debugging */
#   define DEBUG   (1)
#   define NODEBUG   (0)
#   define NDEBUG   (0)
#endif
#ifndef DIAGNOSTIC
#   define DIAGNOSTIC   DEBUG
#endif
#ifndef ATOMIC_DEBUG
#   define ATOMIC_DEBUG   DEBUG
#endif
#ifndef _FORTIFY_SOURCE
/** Adds lightweight checks that detect some buffer overflow errors */
#   define _FORTIFY_SOURCE   (1)
#elif (defined(MINGW) || (defined(OSWINDOWS) && ((!defined(_FORTIFY_SOURCE)) || (_FORTIFY_SOURCE != 0))))
#   define _FORTIFY_SOURCE   (0)  // Fix bug in MingW
#endif
#if (defined(_FORTIFY_SOURCE) && (_FORTIFY_SOURCE > 0) && defined(__OPTIMIZE__) && (__OPTIMIZE__ > 0))
#   if (_FORTIFY_SOURCE > 1)
/** Adds code that detects buffer-overflow errors */
#      define __USE_FORTIFY_LEVEL   (2)
#   else
/** Adds lightweight checks that detect some buffer-overflow errors */
#      define __USE_FORTIFY_LEVEL   (1)
#   endif
#else
/** Do not add code that detects buffer-overflow errors */
#   define __USE_FORTIFY_LEVEL   (0)
#endif
#if (defined(OPTIMIZE_CODE) && (!defined(OPT_SIZE)) && (!defined(__NO_INLINE__)) && defined(__extern_inline))
/** Decide whether we can define 'extern inline' functions in headers */
#   define __USE_EXTERN_INLINES   (1)
#endif
#if ((defined(_FORTIFY_SOURCE) && (_FORTIFY_SOURCE > 0)) && IS_OPT_OVER_0)
#   define __BIONIC_FORTIFY   (1)
#else
#   define __BIONIC_FORTIFY   (0)
#endif
#ifdef __BIONIC_FORTIFY
#   define BIONIC_FORTIFY   (__BIONIC_FORTIFY)
#endif


// POSIX & UNIX MACROS

#define BSD   (199506)
/** BSD 4.3 Compliant */
#define BSD4_3   (1)
/** BSD 4.4 Compliant */
#define BSD4_4   (1)
/** NeXTBSD version (year, month, release) */
#define NeXTBSD   (1995064)
/** NeXTBSD 4.0 */
#define NeXTBSD4_0   (0)
#define _POSIX_SEMAPHORES   (200112L)
#define _POSIX_THREADS   (200112L)
#define _POSIX_MAPPED_FILES   (200809L)
#define _POSIX_THREAD_PROCESS_SHARED   (200809L)
#define _POSIX_THREAD_ATTR_STACKADDR   (200112L)
#define _POSIX_THREAD_ATTR_STACKSIZE   (200809L)
#define _POSIX_THREAD_PRIORITY_SCHEDULING   (-1)
#define _POSIX_REALTIME_SIGNALS   (200809L)
#define _POSIX_MEMORY_PROTECTION   (200809L)
#define _POSIX_MONOTONIC_CLOCK   (200809L)
#define _POSIX_TIMERS   (200809L)
#define _POSIX_CPUTIME   (200809L)
#define _POSIX_THREAD_CPUTIME   (200809L)
#define _POSIX_ADVISORY_INFO   (-1)
#define _POSIX_ASYNCHRONOUS_IO   (-1)
#define _POSIX_BARRIERS   (-1)
#define _POSIX_CHOWN_RESTRICTED   (200112L)
#define _POSIX_CLOCK_SELECTION   (-1)
#define _POSIX_FSYNC   (200112L)
#define _POSIX_IPV6   (200112L)
/** Implementation supports job control */
#define _POSIX_JOB_CONTROL   (200112L)
#define _POSIX_MEMLOCK   (-1)
#define _POSIX_MEMLOCK_RANGE   (-1)
#define _POSIX_MESSAGE_PASSING   (-1)
#define _POSIX_NO_TRUNC   (200112L)
#define _POSIX_PRIORITIZED_IO   (-1)
#define _POSIX_PRIORITY_SCHEDULING   (-1)
#define _POSIX_RAW_SOCKETS   (-1)
#define _POSIX_READER_WRITER_LOCKS   (200112L)
#define _POSIX_REGEXP   (200112L)
#define _POSIX_SAVED_IDS   (200112L)
#define _POSIX_SHARED_MEMORY_OBJECTS   (-1)
#define _POSIX_SHELL   (200112L)
#define _POSIX_SPAWN   (-1)
#define _POSIX_SPIN_LOCKS   (-1)
#define _POSIX_SPORADIC_SERVER   (-1)
#define _POSIX_SYNCHRONIZED_IO   (-1)
#define _POSIX_THREAD_PRIO_INHERIT   (-1)
#define _POSIX_THREAD_PRIO_PROTECT   (-1)
#define _POSIX_THREAD_PRIORITY_SCHEDULING   (-1)
#define _POSIX_THREAD_SAFE_FUNCTIONS   (200112L)
#define _POSIX_THREAD_SPORADIC_SERVER   (-1)
#define _POSIX_TIMEOUTS   (-1)
#define _POSIX_TRACE   (-1)
#define _POSIX_TRACE_EVENT_FILTER   (-1)
#define _POSIX_TRACE_INHERIT   (-1)
#define _POSIX_TRACE_LOG   (-1)
#define _POSIX_TYPED_MEMORY_OBJECTS   (-1)
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
#ifndef _XOPEN_CRYPT
#   define _XOPEN_CRYPT   (1)
#endif
#ifndef _XOPEN_ENH_I18N
#   define _XOPEN_ENH_I18N   (1)
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
#ifndef _XOPEN_SHM
#   define _XOPEN_SHM   (1)
#endif
#ifndef _XOPEN_STREAMS
#   define _XOPEN_STREAMS   (-1)
#endif
#ifndef _XOPEN_UNIX
#   define _XOPEN_UNIX   (1)
#endif
// fsync_range values
/** Sync data and minimal metadata */
#define FDATASYNC   (0x10)
/** Sync data and metadata */
#define FFILESYNC   (0x20)
/** Flush disk caches after sync */
#define FDISKSYNC   (0x40)
// Access modes
#define FSSH_R_OK   (4)
#define FSSH_W_OK   (2)
#define FSSH_X_OK   (1)
#define FSSH_F_OK   (0)
#define R_OK   (4)
#define W_OK   (2)
#define X_OK   (1)
#define F_OK   (0)
// Standard file descriptors
#define FSSH_STDIN_FILENO   (0)
#define FSSH_STDOUT_FILENO   (1)
#define FSSH_STDERR_FILENO   (2)
// Macros for sync_file_range()
#define SYNC_FILE_RANGE_WAIT_BEFORE   (1)
#define SYNC_FILE_RANGE_WRITE   (2)
#define SYNC_FILE_RANGE_WAIT_AFTER   (4)
// POSIX 1003.1 names for file descriptors
#ifndef STDERR_FILENO
#   define STDIN_FILENO   (0)
#   define STDOUT_FILENO   (1)
#   define STDERR_FILENO   (2)
#endif
// lseek() constants
#ifndef FSSH_SEEK_SET
#   define FSSH_SEEK_SET   (0)
#endif
#ifndef FSSH_SEEK_CUR
#   define FSSH_SEEK_CUR   (1)
#endif
#ifndef FSSH_SEEK_END
#   define FSSH_SEEK_END   (2)
#endif
/** Set file offset to offset */
#define SEEK_SET   (0)
/** Set file offset to current plus offset */
#define SEEK_CUR   (1)
/** Set file offset to EOF plus offset */
#define SEEK_END   (2)
/** Seek to next data */
#define SEEK_DATA   (3)
/** Seek to next hole */
#define SEEK_HOLE   (4)
// Old BSD names for the same constants; just for compatibility
#ifndef L_SET
#   define L_SET   SEEK_SET
#endif
#ifndef L_INCR
#   define L_INCR   SEEK_CUR
#endif
#ifndef L_XTND
#   define L_XTND   SEEK_END
#endif
// Function arguments needed by lockf()
/** Unlock a previously locked region */
#define F_ULOCK   (0)
/** Lock a region for exclusive use */
#define F_LOCK   (1)
/** Test and lock a section for exclusive use */
#define F_TLOCK   (2)
/** Test a section for locks by other processes */
#define F_TEST   (3)


// POSIX MANDATED VALUES (<bits/posix1_lim.h>)

#define OPEN_MAX   (256)
#define MAX_ADDR_LEN   (7)
#define MAXLOGNAME   (255)
/** Minimum number of operations in one list I/O call */
#define _POSIX_AIO_LISTIO_MAX   (2)
/** Minimum number of operations in one list I/O call */
#define _POSIX_AIO_LIST_MAX   _POSIX_AIO_LISTIO_MAX
/** Minimum number of operations in one list I/O call */
#define AIO_LIST_MAX   _POSIX_AIO_LISTIO_MAX
/** Minimal number of outstanding asynchronous I/O operations */
#define _POSIX_AIO_MAX   (1)
/** Minimal number of outstanding asynchronous I/O operations */
#define AIO_MAX   _POSIX_AIO_MAX
#define AIO_PRIO_DELTA_MAX   (0)
/** Maximum length of arguments to `execve`, including environment */
#define _POSIX_ARG_MAX   (4096)
/** Minimal number of timer expiration overruns */
#define _POSIX_DELAYTIMER_MAX   (32)
/** Minimal number of timer expiration overruns */
#define DELAYTIMER_MAX   _POSIX_DELAYTIMER_MAX
/** Maximum length of a hostname (excluding terminating null) as returned from the GETHOSTNAME function */
#define _POSIX_HOST_NAME_MAX   (255)
/** Maximum link count of a file */
#define _POSIX_LINK_MAX   (8)
/** Maximum length of login name */
#define _POSIX_LOGIN_NAME_MAX   (9)
/** Number of bytes in a terminal canonical input queue */
#define _POSIX_MAX_CANON   (255)
/** Number of bytes for which space will be available in a terminal input queue */
#define _POSIX_MAX_INPUT   (255)
/** Maximum number of message queues open for a process */
#define _POSIX_MQ_OPEN_MAX   (8)
/** Maximum number of supported message priorities */
#define _POSIX_MQ_PRIO_MAX   (32)
/** Number of bytes in a filename */
#define _POSIX_NAME_MAX   (14)
/** Number of files one process can have open at once */
#define _POSIX_OPEN_MAX   (20)
#ifndef _POSIX_FD_SETSIZE
/** Number of descriptors that a process may examine with `pselect` or `select` */
#   define _POSIX_FD_SETSIZE   _POSIX_OPEN_MAX
#endif
#ifndef FD_SETSIZE
/** Number of descriptors that can fit in an `fd_set` */
#   define FD_SETSIZE   (1024)
#endif
/** Number of descriptors that can fit in an `fd_set` */
#define __DARWIN_FD_SETSIZE   FD_SETSIZE
#define DARWIN_FD_SETSIZE   FD_SETSIZE
/** Number of descriptors that can fit in an `fd_set` */
#define __FD_SETSIZE   FD_SETSIZE
/** Number of descriptors that can fit in an `fd_set` */
#define _FD_SETSIZE   FD_SETSIZE
/** Number of descriptors that can fit in an `fd_set` */
#define __FDSETSIZE   FD_SETSIZE
/** Number of simultaneous supplementary group IDs per process */
#define _POSIX_NGROUPS_MAX   (8)
#ifndef NGROUPS_MAX
/** Supplemental group IDs are available */
#   define NGROUPS_MAX   _POSIX_NGROUPS_MAX
#endif
/** Maximum simultaneous processes per real user ID */
#define _POSIX_CHILD_MAX   (25)
/** Number of bytes in a pathname */
#define _POSIX_PATH_MAX   (256)
/** Number of bytes than can be written atomically to a pipe */
#define _POSIX_PIPE_BUF   (512)
/** The number of repeated occurrences of a BRE permitted by the REGEXEC and REGCOMP functions when using the interval notation */
#define _POSIX_RE_DUP_MAX   (255)
/** Minimal number of realtime signals reserved for the application */
#define _POSIX_RTSIG_MAX   (8)
/** Number of semaphores a process can have */
#define _POSIX_SEM_NSEMS_MAX   (256)
/** Maximal value of a semaphore */
#define _POSIX_SEM_VALUE_MAX   (32767)
/** Number of pending realtime signals */
#define _POSIX_SIGQUEUE_MAX   (32)
/** Number of pending realtime signals */
#define SIGQUEUE_MAX   _POSIX_SIGQUEUE_MAX
/** Largest value of a `ssize_t` */
#define _POSIX_SSIZE_MAX   (32767)
/** Number of streams a process can have open at once */
#define _POSIX_STREAM_MAX   (8)
/** The number of bytes in a symbolic link */
#define _POSIX_SYMLINK_MAX   (255)
/** The number of symbolic links that can be traversed in the resolution of a pathname in the absence of a loop */
#define _POSIX_SYMLOOP_MAX   (8)
/** Number of timer for a process */
#define _POSIX_TIMER_MAX   (32)
/** Maximum number of characters in a tty name */
#define _POSIX_TTY_NAME_MAX   (9)
/** Maximum length of a timezone name (element of `tzname`) */
#define _POSIX_TZNAME_MAX   (6)
/** Maximum number of connections that can be queued on a socket */
#define _POSIX_QLIMIT   (1)
/** Maximum number of bytes that can be buffered on a socket for send or receive */
#define _POSIX_HIWAT   _POSIX_PIPE_BUF
/** Maximum number of elements in an `iovec` array */
#define _POSIX_UIO_MAXIOV   (16)
/** Maximum clock resolution in nanoseconds */
#define _POSIX_CLOCKRES_MIN   (20000000)
#define _POSIX_THREAD_DESTRUCTOR_ITERATIONS   (4)


// POSIX2 MANDATED VALUES 2 (<bits/posix2_lim.h>)

/** The maximum `ibase` and `obase` values allowed by the `bc` utility */
#define _POSIX2_BC_BASE_MAX   (99)
/** The maximum number of elements allowed in an array by the `bc` utility */
#define _POSIX2_BC_DIM_MAX   (2048)
/** The maximum `scale` value allowed by the `bc` utility */
#define _POSIX2_BC_SCALE_MAX   (99)
/** The maximum length of a string constant accepted by the `bc` utility */
#define _POSIX2_BC_STRING_MAX   (1000)
/** The maximum number of weights that can be assigned to an entry of the LC_COLLATE `order` keyword in the locale definition file */
#define _POSIX2_COLL_WEIGHTS_MAX   (2)
/** The maximum number of expressions that can be nested within parentheses by the `expr` utility */
#define _POSIX2_EXPR_NEST_MAX   (32)
/** The maximum length, in bytes, of an input line */
#define _POSIX2_LINE_MAX   (2048)
/** POSIX 1003.2 RE length limit; The maximum number of repeated occurrences of a regular expression permitted when using the interval notation `\{M,N\}` */
#define _POSIX2_RE_DUP_MAX   (255)
/** The maximum number of bytes in a character class name; There is no fixed limit */
#define _POSIX2_CHARCLASS_NAME_MAX   (14)
/** This value is defined like this in regex.h */
#define RE_DUP_MAX   (0x7fff)
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


// SUS REQUIREMENTS

/** The number of replenishment operations that may be simultaneously pending for a particular sporadic server scheduler */
#define _POSIX_SS_REPL_MAX   (4)
/** The number of data keys per process */
#define _POSIX_THREAD_KEYS_MAX   (128)
#define _POSIX_THREAD_THREADS_MAX   (64)
#define _POSIX_TRACE_EVENT_NAME_MAX   (30)
#define _POSIX_TRACE_NAME_MAX   (8)
#define _POSIX_TRACE_SYS_MAX   (8)
#define _POSIX_TRACE_USER_EVENT_MAX   (32)


// LIMITS FOR X/OPEN PORTABILITY (<bits/xopen_lim.h>)

/** Maximum number of bytes in a filename (not including the terminating null of a filename string) */
#define _XOPEN_NAME_MAX   (255)
/** Minimum number the implementation will accept as the maximum number of bytes in a pathname */
#define _XOPEN_PATH_MAX   (1024)
/** Maximum number of iovec structures that one process has available for use with readv() or writev() */
#define IOV_MAX   (1024)
/** Maximum number of `iovec` structures that one process has available for use with `readv` or writev` */
#define _XOPEN_IOV_MAX   (16)
/** Maximum value of `digit` in calls to the `printf` and `scanf` functions */
#define NL_ARGMAX   _POSIX_ARG_MAX
/** Maximum number of bytes in a `LANG` name */
#define NL_LANGMAX   _POSIX2_LINE_MAX
/** Maximum number of messages per set */
#define NL_MGSMAX   (1024)
/** Maximum number of bytes in a message */
#define NL_TEXTMAX   (1024)
/** Default process priority (nice value) */
#define NZERO   (20)
#ifdef HAVE_BROKEN_VDISABLE  // _POSIX_VDISABLE
#   undef  _POSIX_VDISABLE
/** Hack _POSIX_VDISABLE to \\377 since Ultrix does not honor _POSIX_VDISABLE (treats it as ^@); The symptom is that the ^@ keystroke immediately drops the core */
#   define _POSIX_VDISABLE   ((unsigned char)'\377')
#else
/** POSIX 1003.1 tty disabling character */
#   define _POSIX_VDISABLE   -1
#endif  // _POSIX_VDISABLE


// SYSCONF

#if (defined(OSBEOS) || defined(OSHAIKU))  // BeOS Values
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
/** From OpenSolaris; used by SEEK_DATA/SEEK_HOLE */
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
#else
#   define _SC_ARG_MAX   0x0
#   define _SC_BC_BASE_MAX   0x1
#   define _SC_BC_DIM_MAX   0x2
#   define _SC_BC_SCALE_MAX   0x3
#   define _SC_BC_STRING_MAX   0x4
#   define _SC_CHILD_MAX   0x5
#   define _SC_CLK_TCK   0x6
#   define _SC_COLL_WEIGHTS_MAX   0x7
#   define _SC_EXPR_NEST_MAX   0x8
#   define _SC_LINE_MAX   0x9
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


// STRING MANIPULATION MACROS

#define PASTE_NAME(a, b)   PASTE_NAME1(a, b)
#define PASTE_NAME1(a, b)   a##b
/** Used to test macros values */
#define DO_EXPAND(VAL)   ((VAL))
/** Used to test macros values */
#define EXPAND_MACROS(VAL)   DO_EXPAND(VAL)
#define CAT(x, y)   ((x) ## (y))
/** Concatenate macros values */
#define __CONCAT(x, y)   x ## y
#define CONCAT2(x, y)   x ## y
#define CONCAT1(x, y)   CONCAT2(x, y)
#define CONCAT(x, y)   CONCAT2(x, y)
#define C2_(X, Y)   X ## Y
#define C2(X, Y)   C2_(X, Y)
#define C3_(X, Y, Z)   X ## Y ## Z
#define C3(X, Y, Z)   C3_(X, Y, Z)
#define C4_(W, X, Y, Z)   W ## X ## Y ## Z
#define C4(W, X, Y, Z)   C4_(W, X, Y, Z)
/** Indirect stringification; Doing two levels allows the parameter to be a macro itself */
#define __stringify_1(x)    #x
/** Indirect stringification; Doing two levels allows the parameter to be a macro itself */
#define __stringify(x)      __stringify_1(x)
#define __STRING(x)   #x
#define __STRINGIFY(x)   #x
#define STRINGIFY(x)   #x
#define __MINGW64_STRINGIFY(x)   __STRINGIFY(x)
#define MINGW64_STRINGIFY(x)   __STRINGIFY(x)
#define S2(X)   #X
#define S(X)   S2(X)
#define _DIAG_STR1(s)   #s
#define _DIAG_STR(s)   _DIAG_STR1(s)
#define __STR2WSTR(str)   L##str
#define _STR2WSTR(str)   __STR2WSTR(str)
#define __FILEW__   _STR2WSTR(__FILE__)
#define __FUNCTIONW__   _STR2WSTR(__FUNCTION__)
#ifndef _
#   if (defined(HAVE_GETTEXT) && HAVE_GETTEXT)
#      define _(str)   gettext(str)
#   else
#      define _(str)   str
#   endif
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
/** Use the right prefix for global labels */
#define SYM(x)   CONCAT1(__USER_LABEL_PREFIX__, x)
/** Use the right prefix for registers */
#define REG(x)   CONCAT1(__REG_PREFIX__, x)
#define CX_STRINGIFY_ARG(contents)   #contents
#define CX_STRINGIFY(macro)   CX_STRINGIFY_ARG(macro)


// STACK INFO & WORDSIZE

#if (!(defined(_STACKINFO_H) || defined(_STACKINFO_H_) || defined(_BITS_WORDSIZE_H) || defined(_BITS_WORDSIZE_H_)))
#define _STACKINFO_H   (1)
#define _STACKINFO_H_   (1)
#define _BITS_WORDSIZE_H   (1)
#define _BITS_WORDSIZE_H_   (1)


#ifdef XTENSA  // _STACK_GROWS_*
#   define _STACK_GROWS_DOWN   (1)
#elif (defined(X86_64) || defined(X86) || defined(I386))
#   define _STACK_GROWS_DOWN   (1)
#elif defined(ALPHA)
#   define _STACK_GROWS_DOWN   (1)
#elif defined(ARM)
#   define _STACK_GROWS_DOWN   (1)
#elif defined(BLACKFIN)
#   define _STACK_GROWS_DOWN   (1)
#elif defined(ITANIUM)
#   define _STACK_GROWS_DOWN   (1)
#elif defined(M68K)
#   define _STACK_GROWS_DOWN   (1)
#elif defined(MICROBLAZE)
#   define _STACK_GROWS_DOWN   (1)
#elif defined(MIPS)
#   define _STACK_GROWS_DOWN   (1)
#elif defined(POWERPC)
#   define _STACK_GROWS_DOWN   (1)
#elif defined(SPARC)
#   define _STACK_GROWS_DOWN   (1)
#elif (defined(SUPERH) || defined(SUPERH64))
#   define _STACK_GROWS_DOWN   (1)
#else
#   define _STACK_GROWS_DOWN   (1)
#endif  // _STACK_GROWS_*


#ifdef _STACK_GROWS_DOWN
#   define STACK_DIRECTION   (-1)
#   define IS_STACK_DIRECTION_DOWN   (1)
#   define IS_STACK_DIRECTION_UP   (0)
#   define IS_STACK_DIRECTION_UKNOWN   (0)
#   define STACK_GROWS_DOWN   (1)
#   define STACK_GROWS_UP   (0)
#   define DOES_STACK_GROW_UP   (0)
#   define DOES_STACK_GROW_DOWN   (1)
#   define IS_STACK_DIRECTION_UKNOWN   (0)
#elif _STACK_GROWS_UP
#   define STACK_DIRECTION   (1)
#   define IS_STACK_DIRECTION_UP   (1)
#   define IS_STACK_DIRECTION_DOWN   (0)
#   define IS_STACK_DIRECTION_UKNOWN   (0)
#   define STACK_GROWS_UP   (1)
#   define STACK_GROWS_DOWN   (0)
#   define DOES_STACK_GROW_UP   (1)
#   define DOES_STACK_GROW_DOWN   (0)
#   define IS_STACK_DIRECTION_UKNOWN   (0)
#else  // Direction unknown
#   define STACK_DIRECTION   (0)
#   define IS_STACK_DIRECTION_UKNOWN   (1)
#   define IS_STACK_DIRECTION_DOWN   (0)
#   define IS_STACK_DIRECTION_UP   (0)
#   define DOES_STACK_GROW_UP   (-1)
#   define DOES_STACK_GROW_DOWN   (-1)
#endif
#define STACK_DIR   STACK_DIRECTION


#if IS_STACK_DIRECTION_DOWN
#   define FRAME_LEFT(frame, other)   ((char*)frame >= (char*)other)
#elif IS_STACK_DIRECTION_UP
#   define FRAME_LEFT(frame, other)   ((char*)frame <= (char*)other)
#else
#   error   "Define either _STACK_GROWS_DOWN or _STACK_GROWS_UP"
#endif


// DATAMODELS

#if (defined(_LP64) || defined(__LP64__) || defined(_I32LP64) || defined(__I32LP64__))
#   define DATAMODEL_LP64   (1)
#   define DATAMODEL_I32LP64   (1)
#   define TYPESIZE_PTR   (64)
#   define MKL_INT   signed long long
#   define MKL_LONG   signed long long
#   define __OFF_T_MATCHES_OFF64_T   (1)
#   define __INO_T_MATCHES_INO64_T   (1)
#   ifndef _INTEGRAL_MAX_BITS
#      define _INTEGRAL_MAX_BITS   (64)
#   endif
#elif (defined(_LP32) || defined(__LP32__))
#   define DATAMODEL_LP32   (1)
#   define TYPESIZE_PTR   (32)
#   define MKL_INT   signed int
#   ifndef _INTEGRAL_MAX_BITS
#      define _INTEGRAL_MAX_BITS   (32)
#   endif
#elif (defined(_ILP32) || defined(__ILP32__))
#   define DATAMODEL_ILP32   (1)
#   define TYPESIZE_PTR   (32)
#   define MKL_INT   signed int
#   ifndef _INTEGRAL_MAX_BITS
#      define _INTEGRAL_MAX_BITS   (32)
#   endif
#elif (defined(_ILP64) || defined(__ILP64__))
#   define DATAMODEL_ILP64   (1)
#   define TYPESIZE_PTR   (64)
#   define MKL_INT   signed long
#   define MKL_LONG   signed long long
#   ifndef _INTEGRAL_MAX_BITS
#      define _INTEGRAL_MAX_BITS   (64)
#   endif
#elif (defined(_LLP64) || defined(__LLP64__))
#   define DATAMODEL_LLP64   (1)
#   define TYPESIZE_PTR   (64)
#   define MKL_INT   signed int
#   define MKL_LONG   signed long long
#   ifndef _INTEGRAL_MAX_BITS
#      define _INTEGRAL_MAX_BITS   (64)
#   endif
#elif (defined(_SILP64) || defined(__SILP64__))
#   define DATAMODEL_SILP64   (1)
#   define TYPESIZE_PTR   (64)
#   define MKL_INT   signed long
#   define MKL_LONG   signed long
#   ifndef _INTEGRAL_MAX_BITS
#      define _INTEGRAL_MAX_BITS   (64)
#   endif
#else
#   error   "Unknown datamodel"
#endif
#define INTEGRAL_MAX_BITS   _INTEGRAL_MAX_BITS
#ifndef __DARWIN_64_BIT_INO_T
#   if ((defined(__INO_T_MATCHES_INO64_T) && (__INO_T_MATCHES_INO64_T > 0)) || (defined(__OFF_T_MATCHES_OFF64_T) && (__OFF_T_MATCHES_OFF64_T > 0)))
#      define __DARWIN_64_BIT_INO_T   (1)
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
/** _DARWIN_FEATURE_64_BIT_INODE indicates that the ino_t type is 64-bit, and structures modified for 64-bit inodes (like struct stat) will be used */
#   define _DARWIN_FEATURE_64_BIT_INODE   (1)
#endif
#if DARWIN_64_BIT_INO_T
/** _DARWIN_FEATURE_64_ONLY_BIT_INODE indicates that the ino_t type may only be 64-bit; there is no support for 32-bit ino_t when this macro is defined (and non-zero); There is no struct stat64 either, as the regular struct stat will already be the 64-bit version */
#   define _DARWIN_FEATURE_ONLY_64_BIT_INODE   (1)
#endif
#define SIZE_hh   -2
#define SIZE_h   -1
#define SIZE_def   0
#define SIZE_l   1
#define SIZE_L   2
#define SIZE_ll   3
#if ((!defined(KERNEL)) || (!defined(DATAMODEL_LP64)))
/** For 32-bit-specific linking code */
#   define KXLD_USER_OR_ILP32   1
#elif ((!defined(KERNEL)) || defined(DATAMODEL_LP64))
/** For 64-bit-specific linking code */
#   define KXLD_USER_OR_LP64   1
#elif ((!defined(KERNEL)) || defined(X86_64))
/** For x86_64-specific linking code */
#   define KXLD_USER_OR_X86_64   1
#elif ((!defined(KERNEL)) || defined(I386))
/** For i386-specific linking code */
#   define KXLD_USER_OR_I386   1
/** For linking code specific to architectures that support common symbols */
#   define KXLD_USER_OR_COMMON   1
/** For linking code specific to architectures that use MH_OBJECT */
#   define KXLD_USER_OR_OBJECT   1
#elif ((!defined(KERNEL)) || defined(ARM64))
/** For arm64-specific linking code */
#   define KXLD_USER_OR_ARM64   11
#elif ((!defined(KERNEL)) || defined(ARM))
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


// PLATFORM WORDSIZE

#ifndef __WORDSIZE
#   if (defined(X86_64) && (!defined(DATAMODEL_ILP32)))
#      define __WORDSIZE   (64)
#      define __WORDSIZE_TIME64_COMPAT32   (1)
#   elif (defined(X86_64) && defined(DATAMODEL_ILP32))
#      define __WORDSIZE   (32)
#      define __WORDSIZE_TIME64_COMPAT32   (1)
#   elif (defined(POWERPC64) || defined(SPARC64) || defined(ITANIUM))
#      define __WORDSIZE   (64)
#      define __WORDSIZE_TIME64_COMPAT32   (1)
#   elif (defined(DATAMODEL_LP64) || defined(DATAMODEL_LLP64))
#      define __WORDSIZE   (64)
#      define __WORDSIZE_TIME64_COMPAT32   (1)
#   elif (defined(ARM64) || defined(ARM_8) || defined(ULTRA_SPARC) || defined(ALPHA))
#      define __WORDSIZE   (64)
#      define __WORDSIZE_TIME64_COMPAT32   (1)
#   elif defined(S390X)
#      define __WORDSIZE   (64)
#   elif defined(MIPS)
#      define __WORDSIZE   (_MIPS_SZPTR)
#      if (_MIPS_SIM == _ABI64)
#         define __WORDSIZE_TIME64_COMPAT32   (1)
#      endif
#   elif defined(DATAMODEL_ILP32)
#      define __WORDSIZE   (32)
#   elif defined(__mips16)
#      define __WORDSIZE   (16)
#   else
#      define __WORDSIZE   (32)
#      define __WORDSIZE32_SIZE_ULONG   (1)
#   endif
#endif  // __WORDSIZE
#define WORDSIZE   __WORDSIZE
#define WORD_SIZE   __WORDSIZE
#define wsize   __WORDSIZE
#ifndef wmask
#   define wmask   (wsize - 1)
#endif
#ifndef W_TYPE_SIZE
#   define W_TYPE_SIZE   __WORDSIZE
#endif
#if (W_TYPE_SIZE == 8)
#   define Wtype_MAXp1_F   0x1p8f
#elif (W_TYPE_SIZE == 16)
#   define Wtype_MAXp1_F   0x1p16f
#elif (W_TYPE_SIZE == 32)
#   define Wtype_MAXp1_F   0x1p32f
#elif (W_TYPE_SIZE == 64)
#   define Wtype_MAXp1_F   0x1p64f
#else
#   error   "Expand the Wtype_MAXp1_F table."
#endif
#if (WORDSIZE == 64)
#   define IS_WORDSIZE_16   (0)
#   define IS_WORDSIZE_32   (0)
#   define IS_WORDSIZE_64   (1)
#   define WORDSIZE_IS_16   (0)
#   define WORDSIZE_IS_32   (0)
#   define WORDSIZE_IS_64   (1)
/** Number of storage units in a word; normally the size of a general-purpose register (a power of two from 1 or 8) */
#   define UNITS_PER_WORD   (8)
#elif (WORDSIZE == 32)
#   define IS_WORDSIZE_16   (0)
#   define IS_WORDSIZE_32   (1)
#   define IS_WORDSIZE_64   (0)
#   define WORDSIZE_IS_16   (0)
#   define WORDSIZE_IS_32   (1)
#   define WORDSIZE_IS_64   (0)
/** Number of storage units in a word; normally the size of a general-purpose register (a power of two from 1 or 8) */
#   define UNITS_PER_WORD   (4)
#elif (WORDSIZE == 16)
#   define IS_WORDSIZE_16   (1)
#   define IS_WORDSIZE_32   (0)
#   define IS_WORDSIZE_64   (0)
#   define WORDSIZE_IS_16   (1)
#   define WORDSIZE_IS_32   (0)
#   define WORDSIZE_IS_64   (0)
/** Number of storage units in a word; normally the size of a general-purpose register (a power of two from 1 or 8) */
#   define UNITS_PER_WORD   (2)
#else
#   error   "Invalid WORDSIZE value!"
#endif
#if IS_WORDSIZE_32
#   define ENTRY_ALIGN   (4)
#else
#   define ENTRY_ALIGN   (2)
#endif
#ifndef MIN_UNITS_PER_WORD
/** Minimum number of units in a word */
#   define MIN_UNITS_PER_WORD    UNITS_PER_WORD
#endif
#ifndef LIBGCC2_UNITS_PER_WORD
#   define LIBGCC2_UNITS_PER_WORD   UNITS_PER_WORD
#endif
#if (UNITS_PER_WORD == 8)
#   define __NW(a, b)   __ ## a ## di ## b
#   define __NDW(a, b)   __ ## a ## ti ## b
#elif (UNITS_PER_WORD == 4)
#   define __NW(a, b)   __ ## a ## si ## b
#   define __NDW(a, b)   __ ## a ## di ## b
#elif (UNITS_PER_WORD == 2)
#   define __NW(a, b)   __ ## a ## hi ## b
#   define __NDW(a, b)   __ ## a ## si ## b
#else
#   define __NW(a, b)   __ ## a ## qi ## b
#   define __NDW(a, b)   __ ## a ## hi ## b
#endif
#define __N(a)   __ ## a
#define __muldi3   __NDW(mul, 3)
#define __divdi3   __NDW(div, 3)
#define __udivdi3   __NDW(udiv, 3)
#define __moddi3   __NDW(mod, 3)
#define __umoddi3   __NDW(umod, 3)
#define __negdi2   __NDW(neg, 2)
#define __lshrdi3   __NDW(lshr, 3)
#define __ashldi3   __NDW(ashl, 3)
#define __ashrdi3   __NDW(ashr, 3)
#define __cmpdi2   __NDW(cmp, 2)
#define __ucmpdi2   __NDW(ucmp, 2)
#define __divmoddi4   __NDW(divmod, 4)
#define __udivmoddi4   __NDW(udivmod, 4)
#define __fixunstfDI   __NDW(fixunstf, )
#define __fixtfdi   __NDW(fixtf, )
#define __fixunsxfDI   __NDW(fixunsxf, )
#define __fixxfdi   __NDW(fixxf, )
#define __fixunsdfDI   __NDW(fixunsdf, )
#define __fixdfdi   __NDW(fixdf, )
#define __fixunssfDI   __NDW(fixunssf, )
#define __fixsfdi   __NDW(fixsf, )
#define __floatdixf   __NDW(float, xf)
#define __floatditf   __NDW(float, tf)
#define __floatdidf   __NDW(float, df)
#define __floatdisf   __NDW(float, sf)
#define __floatundixf   __NDW(floatun, xf)
#define __floatunditf   __NDW(floatun, tf)
#define __floatundidf   __NDW(floatun, df)
#define __floatundisf   __NDW(floatun, sf)
#define __fixunsxfSI   __NW(fixunsxf, )
#define __fixunstfSI   __NW(fixunstf, )
#define __fixunsdfSI   __NW(fixunsdf, )
#define __fixunssfSI   __NW(fixunssf, )
#define __absvSI2   __NW(absv, 2)
#define __addvSI3   __NW(addv, 3)
#define __subvSI3   __NW(subv, 3)
#define __mulvSI3   __NW(mulv, 3)
#define __negvSI2   __NW(negv, 2)
#define __absvDI2   __NDW(absv, 2)
#define __addvDI3   __NDW(addv, 3)
#define __subvDI3   __NDW(subv, 3)
#define __mulvDI3   __NDW(mulv, 3)
#define __negvDI2   __NDW(negv, 2)
#define __ffsSI2   __NW(ffs, 2)
#define __clzSI2   __NW(clz, 2)
#define __ctzSI2   __NW(ctz, 2)
#define __clrsbSI2   __NW(clrsb, 2)
#define __popcountSI2   __NW(popcount, 2)
#define __paritySI2   __NW(parity, 2)
#define __ffsDI2   __NDW(ffs, 2)
#define __clzDI2   __NDW(clz, 2)
#define __ctzDI2   __NDW(ctz, 2)
#define __clrsbDI2   __NDW(clrsb, 2)
#define __popcountDI2   __NDW(popcount, 2)
#define __parityDI2   __NDW(parity, 2)
#define __clz_tab   __N(clz_tab)
#define __bswapsi2   __N(bswapsi2)
#define __bswapdi2   __N(bswapdi2)
#define __udiv_w_sdiv   __N(udiv_w_sdiv)
#define __clear_cache   __N(clear_cache)
#define __enable_execute_stack   __N(enable_execute_stack)


// SIZEOF & ALIGNMENT OF DATATYPES

#ifndef NBBY
/** Number of bits in a byte; not all platforms use 8-bit bytes */
#   define NBBY   (8)
#endif
/** Number of bits in a byte; not all platforms use 8-bit bytes */
#define BITS_PER_UNIT   NBBY
/** Number of bits in a byte; not all platforms use 8-bit bytes */
#define __DARWIN_NBBY   NBBY
/** Number of bits in a byte; not all platforms use 8-bit bytes */
#define BITS_PER_BYTE   NBBY
/** Number of bytes in a byte (obviously 1); Some code depends on this symbol */
#define BYTES_PER_BYTE   (1)
/** Number of bits in a char */
#define BITS_PER_CHAR   (8)
/** Number of bytes in a char */
#define BYTES_PER_CHAR   (1)
#ifndef CHARBITS
/** Number of bits in a `char` */
#   define CHARBITS   (8)
#endif
#ifndef __CHAR_BIT__
/** Number of bits in a `char` */
#   define __CHAR_BIT__   CHARBITS
#endif
/** Number of bits in a `char` */
#ifndef CHAR_BIT
#   define CHAR_BIT   CHARBITS
#endif
#ifndef BITSPERBYTE
/** Some systems define this name instead of CHAR_BIT or CHARBITS */
#   define BITSPERBYTE   CHAR_BIT
#endif
/** Number of bytes in a char */
#define TYPESIZE_CHAR   BYTES_PER_CHAR
#ifndef SIZEOF_CHAR
/** Sizeof a char */
#   define SIZEOF_CHAR   BYTES_PER_CHAR
#endif
#ifndef __SIZEOF_CHAR__
/** Sizeof a char */
#   define __SIZEOF_CHAR__   BYTES_PER_CHAR
#endif
#ifndef SIZEOF_BYTE
/** Sizeof a byte */
#   define SIZEOF_BYTE   (1)
#endif
#ifndef __SIZEOF_BYTE__
/** Sizeof a byte */
#   define __SIZEOF_BYTE__   (1)
#endif
/** Number of bits in a short */
#define BITS_PER_SHORT   (16)
/** Number of bytes in a short */
#define BYTES_PER_SHORT   (2)
/** Number of bits in a short */
#define BITS_PER_SHORTINT   BITS_PER_SHORT
/** Number of bits in a short */
#define BITS_PER_SHORT_INT   BITS_PER_SHORTINT
/** Number of bits in a short */
#define SHORTBITS   BITS_PER_SHORT
/** Number of bytes in a short */
#define BYTES_PER_SHORT_INT   BYTES_PER_SHORT
/** Number of bytes in a short */
#define TYPESIZE_SHORT   BYTES_PER_SHORT
#ifdef __SIZEOF_SHORT__
#   ifndef SIZEOF_SHORT
#      define SIZEOF_SHORT   __SIZEOF_SHORT__
#   endif
#else
#   ifndef SIZEOF_SHORT
#      define SIZEOF_SHORT   TYPESIZE_SHORT
#   endif
#   ifndef __SIZEOF_SHORT__
#      define __SIZEOF_SHORT__   TYPESIZE_SHORT
#   endif
#endif
/** Number of bits in a long long */
#define BITS_PER_LONG_LONG_INT   (64)
/** Number of bits in a long long */
#define BITS_PER_LONG_LONG   BITS_PER_LONG_LONG_INT
/** Number of bytes in a long long */
#define BYTES_PER_LONG_LONG_INT   (8)
/** Number of bytes in a long long */
#define BYTES_PER_LONG_LONG   BYTES_PER_LONG_LONG_INT
#define TYPESIZE_LONG_LONG   BYTES_PER_LONG_LONG
#ifdef __SIZEOF_LONG_LONG__
#   ifndef SIZEOF_LONG_LONG
#      define SIZEOF_LONG_LONG   __SIZEOF_LONG_LONG__
#   endif
#else
#   ifndef SIZEOF_LONG_LONG
#      define SIZEOF_LONG_LONG   TYPESIZE_LONG_LONG
#   endif
#   ifndef __SIZEOF_LONG_LONG__
#      define __SIZEOF_LONG_LONG__   TYPESIZE_LONG_LONG
#   endif
#endif
#define PTRBITS   WORDSIZE
#define BITS_PER_MP_LIMB   WORDSIZE
#define BYTES_PER_MP_LIMB   (WORDSIZE / 8)
#ifndef BITS_PER_INT128
#   define BITS_PER_INT128   (128)
#endif
#ifndef BYTES_PER_INT128
#   define BYTES_PER_INT128   (16)
#endif
#ifndef TYPESIZE_INT128
#   define TYPESIZE_INT128   (16)
#endif
#ifndef __SIZEOF_INT128__
#   define __SIZEOF_INT128__   (16)
#endif
#ifndef SIZEOF_INT128
#   define SIZEOF_INT128   __SIZEOF_INT128__
#endif
#ifndef BITS_PER_UINT128
#   define BITS_PER_UINT128   (128)
#endif
#ifndef BYTES_PER_UINT128
#   define BYTES_PER_UINT128   (16)
#endif
#ifndef TYPESIZE_UINT128
#   define TYPESIZE_UINT128   (16)
#endif
#ifndef __SIZEOF_UINT128__
#   define __SIZEOF_UINT128__   (16)
#endif
#ifndef SIZEOF_UINT128
#   define SIZEOF_UINT128   __SIZEOF_UINT128__
#endif
#ifndef BITS_PER_INT256
#   define BITS_PER_INT256   (256)
#endif
#ifndef BYTES_PER_INT256
#   define BYTES_PER_INT256   (32)
#endif
#ifndef TYPESIZE_INT256
#   define TYPESIZE_INT256   (32)
#endif
#ifndef __SIZEOF_INT256__
#   define __SIZEOF_INT256__   (32)
#endif
#ifndef SIZEOF_INT256
#   define SIZEOF_INT256   __SIZEOF_INT256__
#endif
#ifndef BITS_PER_UINT256
#   define BITS_PER_UINT256   (256)
#endif
#ifndef BYTES_PER_UINT256
#   define BYTES_PER_UINT256   (32)
#endif
#ifndef TYPESIZE_UINT256
#   define TYPESIZE_UINT256   (32)
#endif
#ifndef __SIZEOF_UINT256__
#   define __SIZEOF_UINT256__   (32)
#endif
#ifndef SIZEOF_UINT256
#   define SIZEOF_UINT256   __SIZEOF_UINT256__
#endif
#ifndef BITS_PER_INT512
#   define BITS_PER_INT512   (512)
#endif
#ifndef BYTES_PER_INT512
#   define BYTES_PER_INT512   (64)
#endif
#ifndef TYPESIZE_INT512
#   define TYPESIZE_INT512   (64)
#endif
#ifndef __SIZEOF_INT512__
#   define __SIZEOF_INT512__   (64)
#endif
#ifndef SIZEOF_INT512
#   define SIZEOF_INT512   __SIZEOF_INT512__
#endif
#ifndef BITS_PER_UINT512
#   define BITS_PER_UINT512   (512)
#endif
#ifndef BYTES_PER_UINT512
#   define BYTES_PER_UINT512   (64)
#endif
#ifndef TYPESIZE_UINT512
#   define TYPESIZE_UINT512   (64)
#endif
#ifndef __SIZEOF_UINT512__
#   define __SIZEOF_UINT512__   (64)
#endif
#ifndef SIZEOF_UINT512
#   define SIZEOF_UINT512   __SIZEOF_UINT512__
#endif
#if SUPPORTS_LONG_DOUBLE
#   if (defined(__SIZEOF_LONG_DOUBLE__) && (__SIZEOF_LONG_DOUBLE__ == 10))
#      define IS_LDBL_80   (1)
#      define IS_LDBL_96   (0)
#      define IS_LDBL_128   (0)
#      define IS_LDBL_10_BYTES   (1)
#      define IS_LDBL_12_BYTES   (0)
#      define IS_LDBL_16_BYTES   (0)
#      define BITS_PER_LONG_DOUBLE   (80)
#      define BYTES_PER_LONG_DOUBLE   (10)
#   elif (defined(__SIZEOF_LONG_DOUBLE__) && (__SIZEOF_LONG_DOUBLE__ == 12))
#      define IS_LDBL_80   (0)
#      define IS_LDBL_96   (1)
#      define IS_LDBL_128   (0)
#      define IS_LDBL_10_BYTES   (0)
#      define IS_LDBL_12_BYTES   (1)
#      define IS_LDBL_16_BYTES   (0)
#      define BITS_PER_LONG_DOUBLE   (96)
#      define BYTES_PER_LONG_DOUBLE   (12)
#   elif (defined(__SIZEOF_LONG_DOUBLE__) && (__SIZEOF_LONG_DOUBLE__ == 16))
#      define IS_LDBL_80   (0)
#      define IS_LDBL_96   (0)
#      define IS_LDBL_128   (1)
#      define IS_LDBL_10_BYTES   (0)
#      define IS_LDBL_12_BYTES   (0)
#      define IS_LDBL_16_BYTES   (1)
#      define BITS_PER_LONG_DOUBLE   (128)
#      define BYTES_PER_LONG_DOUBLE   (16)
#   elif (!defined(__SIZEOF_LONG_DOUBLE__))
#      error   "`__SIZEOF_LONG_DOUBLE__` is not defined!"
#   else
#      error   "Invalid `long double` size!"
#   endif
#endif
#ifndef BITS_PER_LONG_DOUBLE
#   define BITS_PER_LONG_DOUBLE   (128)
#endif
#ifndef BYTES_PER_LONG_DOUBLE
#   define BYTES_PER_LONG_DOUBLE   (16)
#endif
#if SUPPORTS_LONG_DOUBLE
#   define TYPESIZE_LONG_DOUBLE   BYTES_PER_LONG_DOUBLE
#endif
#ifdef __SIZEOF_LONG_DOUBLE__
#   ifndef SIZEOF_LONG_DOUBLE
#      define SIZEOF_LONG_DOUBLE   __SIZEOF_LONG_DOUBLE__
#   endif
#else
#   ifndef SIZEOF_LONG_DOUBLE
#      define SIZEOF_LONG_DOUBLE   TYPESIZE_LONG_DOUBLE
#   endif
#   ifndef __SIZEOF_LONG_DOUBLE__
#      define __SIZEOF_LONG_DOUBLE__   TYPESIZE_LONG_DOUBLE
#   endif
#endif
#ifndef SIZEOF_XFTYPE
#   define SIZEOF_XFTYPE   (12)
#endif
#ifndef __SIZEOF_XFTYPE__
#   define __SIZEOF_XFTYPE__   (12)
#endif
#ifndef __SIZEOF_FLOAT64__
#   define __SIZEOF_FLOAT64__   (8)
#endif
#ifndef SIZEOF_FLOAT64
#   define SIZEOF_FLOAT64   (8)
#endif
#ifdef __SIZEOF_FLOAT80__
/** Represents the size of float80 (80-bit float) */
#   define SIZEOF_FLOAT80   __SIZEOF_FLOAT80__
#else
/** Represents the size of float80 (80-bit float) */
#   define __SIZEOF_FLOAT80__   (16)
/** Represents the size of float80 (80-bit float) */
#   define SIZEOF_FLOAT80   __SIZEOF_FLOAT80__
#endif
#ifndef TYPESIZE_FLOAT80
#   define TYPESIZE_FLOAT80   __SIZEOF_FLOAT80__
#endif
#ifdef __SIZEOF_FLOAT96__
#   define SIZEOF_FLOAT96   __SIZEOF_FLOAT96__
#else
#   define __SIZEOF_FLOAT96__   (12)
#   define SIZEOF_FLOAT96   __SIZEOF_FLOAT96__
#endif
#ifndef TYPESIZE_FLOAT96
#   define TYPESIZE_FLOAT96   __SIZEOF_FLOAT96__
#endif
#ifndef TYPESIZE_FLOAT128
#   define TYPESIZE_FLOAT128   (16)
#endif
#ifndef __SIZEOF_FLOAT128__
#   define __SIZEOF_FLOAT128__   (16)
#endif
#ifndef SIZEOF_FLOAT128
#   define SIZEOF_FLOAT128   (16)
#endif
#ifdef POWERPC64  // ARCH

#   define BYTES_PER_INT   4
#   define BYTES_PER_INT64   8
#   define BYTES_PER_LONG   8
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BYTES_PER_WORD   8
#   define BYTES_PER_DWORD   8
#   define BITS_PER_INT   32
#   define BITS_PER_INT64   64
#   define BITS_PER_LONG   64
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#   define BITS_PER_WORD   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_INT64_LOG2   6
#   define BITS_PER_LONG_LOG2   6
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define BITS_PER_WORD_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   8
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   8
#   define ALIGN_OF_WORD   8
#   define BYTES_PER_WORD_LOG2   3
#   define BYTES_PER_DWORD_LOG2   3

#elif defined(POWERPC)

#   define BYTES_PER_INT   4
#   define BYTES_PER_INT64   8
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BYTES_PER_WORD   4
#   define BYTES_PER_DWORD   8
#   define BITS_PER_INT   32
#   define BITS_PER_INT64   64
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#   define BITS_PER_WORD   32
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_INT64_LOG2   6
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define BITS_PER_WORD_LOG2   5
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   4
#   define ALIGN_OF_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define BYTES_PER_DWORD_LOG2   3

#elif defined(ALPHA)

#   define BYTES_PER_INT   4
#   define BYTES_PER_INT64   8
#   define BYTES_PER_LONG   8
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BYTES_PER_WORD   8
#   define BYTES_PER_DWORD   8
#   define BITS_PER_INT   32
#   define BITS_PER_INT64   64
#   define BITS_PER_LONG   64
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#   define BITS_PER_WORD   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_INT64_LOG2   6
#   define BITS_PER_LONG_LOG2   6
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define BITS_PER_WORD_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   8
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   8
#   define ALIGN_OF_WORD   8
#   define BYTES_PER_WORD_LOG2   3
#   define BYTES_PER_DWORD_LOG2   3

#elif defined(ITANIUM)

#   define BYTES_PER_INT   4
#   define BYTES_PER_INT64   8
#   define BYTES_PER_LONG   8
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BYTES_PER_WORD   8
#   define BYTES_PER_DWORD   8
#   define BITS_PER_INT   32
#   define BITS_PER_INT64   64
#   define BITS_PER_LONG   64
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#   define BITS_PER_WORD   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_INT64_LOG2   6
#   define BITS_PER_LONG_LOG2   6
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define BITS_PER_WORD_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   8
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   8
#   define ALIGN_OF_WORD   8
#   define BYTES_PER_WORD_LOG2   3
#   define BYTES_PER_DWORD_LOG2   3

#elif (defined(I386) && (!defined(X86_64)))

#   define BYTES_PER_INT   4
#   define BYTES_PER_INT64   8
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BYTES_PER_WORD   4
#   define BYTES_PER_DWORD   8
#   define BITS_PER_INT   32
#   define BITS_PER_INT64   64
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#   define BITS_PER_WORD   32
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_INT64_LOG2   6
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define BITS_PER_WORD_LOG2   5
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   4
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   4
#   define ALIGN_OF_POINTER   4
#   define ALIGN_OF_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define BYTES_PER_DWORD_LOG2   3

#elif (defined(X86_64) || defined(X86))

#   define IEEE_DOUBLE_BIG_ENDIAN   0
#   ifdef DATAMODEL_ILP32
#      define _LONG_LONG_LIMB
#      define BYTES_PER_INT   4
#      define BYTES_PER_INT64   8
#      define BYTES_PER_LONG   4
#      define BYTES_PER_FLOAT   4
#      define BYTES_PER_DOUBLE   8
#      define BYTES_PER_WORD   4
#      define BYTES_PER_DWORD   8
#      define BITS_PER_INT   32
#      define BITS_PER_INT64   64
#      define BITS_PER_LONG   32
#      define BITS_PER_FLOAT   32
#      define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#      define BITS_PER_WORD   32
#      define BITS_PER_BYTE_LOG2   3
#      define BITS_PER_SHORT_LOG2   4
#      define BITS_PER_INT_LOG2   5
#      define BITS_PER_INT64_LOG2   6
#      define BITS_PER_LONG_LOG2   5
#      define BITS_PER_FLOAT_LOG2   5
#      define BITS_PER_DOUBLE_LOG2   6
#      define BITS_PER_WORD_LOG2   5
#      define ALIGN_OF_SHORT   2
#      define ALIGN_OF_INT   4
#      define ALIGN_OF_LONG   4
#      define ALIGN_OF_INT64   8
#      define ALIGN_OF_FLOAT   4
#      define ALIGN_OF_DOUBLE   8
#      define ALIGN_OF_POINTER   4
#      define ALIGN_OF_WORD   4
#      define BYTES_PER_WORD_LOG2   2
#      define BYTES_PER_DWORD_LOG2   3
#   else
#      define BYTES_PER_INT   4
#      define BYTES_PER_INT64   8
#      define BYTES_PER_LONG   8
#      define BYTES_PER_FLOAT   4
#      define BYTES_PER_DOUBLE   8
#      define BYTES_PER_WORD   8
#      define BYTES_PER_DWORD   8
#      define BITS_PER_INT   32
#      define BITS_PER_INT64   64
#      define BITS_PER_LONG   64
#      define BITS_PER_FLOAT   32
#      define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#      define BITS_PER_WORD   64
#      define BITS_PER_BYTE_LOG2   3
#      define BITS_PER_SHORT_LOG2   4
#      define BITS_PER_INT_LOG2   5
#      define BITS_PER_INT64_LOG2   6
#      define BITS_PER_LONG_LOG2   6
#      define BITS_PER_FLOAT_LOG2   5
#      define BITS_PER_DOUBLE_LOG2   6
#      define BITS_PER_WORD_LOG2   6
#      define ALIGN_OF_SHORT   2
#      define ALIGN_OF_INT   4
#      define ALIGN_OF_LONG   8
#      define ALIGN_OF_INT64   8
#      define ALIGN_OF_FLOAT   4
#      define ALIGN_OF_DOUBLE   8
#      define ALIGN_OF_POINTER   8
#      define ALIGN_OF_WORD   8
#      define BYTES_PER_WORD_LOG2   3
#      define BYTES_PER_DWORD_LOG2   3
#   endif  // DATAMODEL_ILP32

#elif defined(SPARC)

#   define BYTES_PER_INT   4
#   define BYTES_PER_INT64  8
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT  4
#   define BYTES_PER_DOUBLE  8
#   define BYTES_PER_WORD   4
#   define BYTES_PER_DWORD  8
#   define BITS_PER_INT   32
#   define BITS_PER_INT64   64
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE  64
/** Number of bits in a word */
#   define BITS_PER_WORD   32
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2  4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_INT64_LOG2  6
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2  5
#   define BITS_PER_DOUBLE_LOG2   6
#   define BITS_PER_WORD_LOG2   5
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE  8
#   define ALIGN_OF_POINTER  4
#   define ALIGN_OF_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define BYTES_PER_DWORD_LOG2  3

#elif defined(MIPS)

#   if (_MIPS_SIM == _ABI64)
#      define _LONG_LONG_LIMB
#      define BYTES_PER_INT   4
#      define BYTES_PER_INT64   8
#      define BYTES_PER_LONG   8
#      define BYTES_PER_FLOAT   4
#      define BYTES_PER_DOUBLE   8
#      define BYTES_PER_WORD   8
#      define BYTES_PER_DWORD   8
#      define BITS_PER_INT   32
#      define BITS_PER_INT64   64
#      define BITS_PER_LONG   64
#      define BITS_PER_FLOAT   32
#      define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#      define BITS_PER_WORD   64
#      define BITS_PER_BYTE_LOG2   3
#      define BITS_PER_SHORT_LOG2   4
#      define BITS_PER_INT_LOG2   5
#      define BITS_PER_INT64_LOG2   6
#      define BITS_PER_LONG_LOG2   6
#      define BITS_PER_FLOAT_LOG2   5
#      define BITS_PER_DOUBLE_LOG2   6
#      define BITS_PER_WORD_LOG2   6
#      define ALIGN_OF_SHORT   2
#      define ALIGN_OF_INT   4
#      define ALIGN_OF_LONG   8
#      define ALIGN_OF_INT64   8
#      define ALIGN_OF_FLOAT   4
#      define ALIGN_OF_DOUBLE   8
#      define ALIGN_OF_POINTER   8
#      define ALIGN_OF_WORD   8
#      define BYTES_PER_WORD_LOG2   3
#      define BYTES_PER_DWORD_LOG2   3
#   else // _ABI64
#      define BYTES_PER_INT   4
#      define BYTES_PER_INT64   8
#      define BYTES_PER_LONG   4
#      define BYTES_PER_FLOAT   4
#      define BYTES_PER_DOUBLE   8
#      define BYTES_PER_WORD   4
#      define BYTES_PER_DWORD   8
#      define BITS_PER_INT   32
#      define BITS_PER_INT64   64
#      define BITS_PER_LONG   32
#      define BITS_PER_FLOAT   32
#      define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#      define BITS_PER_WORD   32
#      define BITS_PER_BYTE_LOG2   3
#      define BITS_PER_SHORT_LOG2   4
#      define BITS_PER_INT_LOG2   5
#      define BITS_PER_INT64_LOG2   6
#      define BITS_PER_LONG_LOG2   5
#      define BITS_PER_FLOAT_LOG2   5
#      define BITS_PER_DOUBLE_LOG2   6
#      define BITS_PER_WORD_LOG2   5
#      define ALIGN_OF_SHORT   2
#      define ALIGN_OF_INT   4
#      define ALIGN_OF_LONG   4
#      define ALIGN_OF_INT64   8
#      define ALIGN_OF_FLOAT   4
#      define ALIGN_OF_DOUBLE   8
#      define ALIGN_OF_POINTER   4
#      define ALIGN_OF_WORD   4
#      define BYTES_PER_WORD_LOG2   2
#      define BYTES_PER_DWORD_LOG2   3
#   endif  // MIPS _ABI64

#elif defined(ARM64)

#   define BYTES_PER_INT   4
#   define BYTES_PER_INT64   8
#   define BYTES_PER_LONG   8
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BYTES_PER_WORD   8
#   define BYTES_PER_DWORD   8
#   define BITS_PER_INT   32
#   define BITS_PER_INT64   64
#   define BITS_PER_LONG   64
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#   define BITS_PER_WORD   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_INT64_LOG2   6
#   define BITS_PER_LONG_LOG2   6
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define BITS_PER_WORD_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   8
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   8
#   define ALIGN_OF_WORD   8
#   define BYTES_PER_WORD_LOG2   3
#   define BYTES_PER_DWORD_LOG2   3

#elif defined(ARM)

#   define BYTES_PER_INT   4
#   define BYTES_PER_INT64   8
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BYTES_PER_WORD   4
#   define BYTES_PER_DWORD   8
#   define BITS_PER_INT   32
#   define BITS_PER_INT64   64
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#   define BITS_PER_WORD   32
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_INT64_LOG2   6
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define BITS_PER_WORD_LOG2   5
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   4
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   4
#   define ALIGN_OF_POINTER   4
#   define ALIGN_OF_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define BYTES_PER_DWORD_LOG2   3

#elif defined(HPPA)

#   define BYTES_PER_INT   4
#   define BYTES_PER_INT64   8
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BYTES_PER_WORD   4
#   define BYTES_PER_DWORD   8
#   define BITS_PER_INT   32
#   define BITS_PER_INT64   64
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#   define BITS_PER_WORD   32
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_INT64_LOG2   6
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define BITS_PER_WORD_LOG2   5
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   4
#   define ALIGN_OF_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define BYTES_PER_DWORD_LOG2   3

#elif defined(S390X)

#   define IEEE_DOUBLE_BIG_ENDIAN   0
#   define BYTES_PER_INT   4
#   define BYTES_PER_INT64   8
#   define BYTES_PER_LONG   8
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BYTES_PER_WORD   8
#   define BYTES_PER_DWORD   8
#   define BITS_PER_INT   32
#   define BITS_PER_INT64   64
#   define BITS_PER_LONG   64
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#   define BITS_PER_WORD   64
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_INT64_LOG2   6
#   define BITS_PER_LONG_LOG2   6
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define BITS_PER_WORD_LOG2   6
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   8
#   define ALIGN_OF_INT64   8
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   8
#   define ALIGN_OF_POINTER   8
#   define ALIGN_OF_WORD   8
#   define BYTES_PER_WORD_LOG2   3
#   define BYTES_PER_DWORD_LOG2   3

#elif defined(S390)

#   define IEEE_DOUBLE_BIG_ENDIAN   0
#   define BYTES_PER_INT   4
#   define BYTES_PER_INT64   8
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BYTES_PER_WORD   4
#   define BYTES_PER_DWORD   8
#   define BITS_PER_INT   32
#   define BITS_PER_INT64   64
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#   define BITS_PER_WORD   32
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_INT64_LOG2   6
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define BITS_PER_WORD_LOG2   5
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   4
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   4
#   define ALIGN_OF_POINTER   4
#   define ALIGN_OF_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define BYTES_PER_DWORD_LOG2   3

#elif defined(SUPERH)

#   define IEEE_DOUBLE_BIG_ENDIAN   0
#   define IEEE_DOUBLE_MIXED_ENDIAN   1
#   define BYTES_PER_INT   4
#   define BYTES_PER_INT64   8
#   define BYTES_PER_LONG   4
#   define BYTES_PER_FLOAT   4
#   define BYTES_PER_DOUBLE   8
#   define BYTES_PER_WORD   4
#   define BYTES_PER_DWORD   8
#   define BITS_PER_INT   32
#   define BITS_PER_INT64   64
#   define BITS_PER_LONG   32
#   define BITS_PER_FLOAT   32
#   define BITS_PER_DOUBLE   64
/** Number of bits in a word */
#   define BITS_PER_WORD   32
#   define BITS_PER_BYTE_LOG2   3
#   define BITS_PER_SHORT_LOG2   4
#   define BITS_PER_INT_LOG2   5
#   define BITS_PER_INT64_LOG2   6
#   define BITS_PER_LONG_LOG2   5
#   define BITS_PER_FLOAT_LOG2   5
#   define BITS_PER_DOUBLE_LOG2   6
#   define BITS_PER_WORD_LOG2   5
#   define ALIGN_OF_SHORT   2
#   define ALIGN_OF_INT   4
#   define ALIGN_OF_LONG   4
#   define ALIGN_OF_INT64   4
#   define ALIGN_OF_FLOAT   4
#   define ALIGN_OF_DOUBLE   4
#   define ALIGN_OF_POINTER   4
#   define ALIGN_OF_WORD   4
#   define BYTES_PER_WORD_LOG2   2
#   define BYTES_PER_DWORD_LOG2   3

#else
#   error   "Unknown CPU architecture!"
#endif  // ARCH
#ifndef MAX_BITS_PER_WORD
/** Maximum number of bits in a word */
#   define MAX_BITS_PER_WORD    BITS_PER_WORD
#endif
#if IS_WORDSIZE_32
#   define TYPESIZE_SIZE_T   BYTES_PER_INT
#   define TYPESIZE_PTRDIFF_T   BYTES_PER_INT
#   define TYPESIZE_INTMAX_T   BYTES_PER_LONG_INT
#else  // WORDSIZE == 64
#   define TYPESIZE_SIZE_T   BYTES_PER_LONG_INT
#   define TYPESIZE_PTRDIFF_T   BYTES_PER_LONG_INT
#   define TYPESIZE_INTMAX_T   BYTES_PER_LONG_LONG_INT
#endif
#if ((!defined(POINTER_SIZE)) && (defined(X86_64) || defined(ARM64) || defined(MIPS64) || defined(POWERPC64)))
/** Width of a pointer in bits */
#   define POINTER_SIZE    64
#   define __SIZEOF_POINTER__   8
#   define TYPESIZE_POINTER   8
#elif ((!defined(POINTER_SIZE)) && (defined(X86) || defined(I386) || defined(ARM) || defined(MIPS) || defined(POWERPC)))
/** Width of a pointer in bits */
#   define POINTER_SIZE    32
#   define __SIZEOF_POINTER__   4
#   define TYPESIZE_POINTER   4
#elif (!defined(POINTER_SIZE))
/** Width of a pointer in bits */
#   define POINTER_SIZE    (8 * TYPESIZE_PTRDIFF_T)
#   define __SIZEOF_POINTER__   TYPESIZE_PTRDIFF_T
#   define TYPESIZE_POINTER   TYPESIZE_PTRDIFF_T
#endif
#ifndef SIZEOF_POINTER
#   define SIZEOF_POINTER   __SIZEOF_POINTER__
#endif
#ifndef BYTES_PER_POINTER
#   define BYTES_PER_POINTER   __SIZEOF_POINTER__
#endif
#ifndef BYTES_PER_PTR
#   define BYTES_PER_PTR   TYPESIZE_POINTER
#endif
#ifndef BITS_PER_POINTER
#   define BITS_PER_POINTER   (8 * TYPESIZE_POINTER)
#endif
#ifndef SIZEOF_VOID_P
#   define SIZEOF_VOID_P   (sizeof(void*))
#endif
#ifndef SIZEOF_VOIDP
#   define SIZEOF_VOIDP   SIZEOF_VOID_P
#endif
#ifndef TYPESIZE_VOIDP
#   define TYPESIZE_VOIDP   SIZEOF_VOID_P
#endif
#ifndef BITS_PER_VOID_P
#   define BITS_PER_VOID_P   (8 * SIZEOF_VOID_P)
#endif
#ifndef SIZEOF_VOID
#   define SIZEOF_VOID   (sizeof(void))
#endif
#ifndef SIZEOF_VOID
#   define SIZEOF_VOID   SIZEOF_VOID
#endif
#ifndef TYPESIZE_VOID
#   define TYPESIZE_VOID   SIZEOF_VOID
#endif
#ifndef BITS_PER_VOID
#   define BITS_PER_VOID   (8 * SIZEOF_VOID)
#endif
#ifndef SIZEOF_NULL
#   define SIZEOF_NULL   (sizeof(NULL))
#endif
#ifndef SIZEOF_NULL
#   define SIZEOF_NULL   SIZEOF_NULL
#endif
#ifndef TYPESIZE_NULL
#   define TYPESIZE_NULL   SIZEOF_NULL
#endif
#ifndef BITS_PER_NULL
#   define BITS_PER_NULL   (8 * SIZEOF_NULL)
#endif
#ifndef __SIZEOF_SIZE_T__
#   define __SIZEOF_SIZE_T__   TYPESIZE_SIZE_T
#endif
#ifndef SIZEOF_SIZE_T
#   define SIZEOF_SIZE_T   TYPESIZE_SIZE_T
#endif
#ifndef BITS_PER_SIZE_T
#   define BITS_PER_SIZE_T   (8 * SIZEOF_SIZE_T)
#endif
/** Number of bits in size_t */
#define BITSIZEOF_SIZE_T   BITS_PER_SIZE_T
#ifndef __SIZE_WIDTH__
/** Number of bits in size_t */
#   define __SIZE_WIDTH__   BITS_PER_SIZE_T
#endif
/** Number of bits in ssize_t */
#define BITSIZEOF_SSIZE_T   BITS_PER_SIZE_T
#ifndef __SIZEOF_PTRDIFF_T__
#   define __SIZEOF_PTRDIFF_T__   TYPESIZE_PTRDIFF_T
#endif
#ifndef SIZEOF_PTRDIFF_T
#   define SIZEOF_PTRDIFF_T   TYPESIZE_PTRDIFF_T
#endif
/** Number of bits in ptrdiff_t */
#define BITS_PER_PTRDIFF_T   (SIZEOF_PTRDIFF_T * 8)
/** Number of bits in ptrdiff_t */
#define BITSIZEOF_PTRDIFF_T   BITS_PER_PTRDIFF_T
#ifndef __PTRDIFF_WIDTH__
/** Number of bits in ptrdiff_t */
#   define __PTRDIFF_WIDTH__   BITS_PER_PTRDIFF_T
#endif
#ifndef __POINTER_WIDTH__
/** Number of bits in a pointer */
#   define __POINTER_WIDTH__   BITS_PER_PTRDIFF_T
#endif
#ifndef INTBITS
#   define INTBITS   BITS_PER_INT
#endif
#ifndef TYPESIZE_INT
#   define TYPESIZE_INT   BYTES_PER_INT
#endif
#ifdef __SIZEOF_INT__
#   ifndef SIZEOF_INT
#      define SIZEOF_INT   __SIZEOF_INT__
#   endif
#else
#   ifndef SIZEOF_INT
#      define SIZEOF_INT   TYPESIZE_INT
#   endif
#   ifndef __SIZEOF_INT__
#      define __SIZEOF_INT__   TYPESIZE_INT
#   endif
#endif
/** Number of bits in a long */
#define __NFDBITS   BITS_PER_LONG
/** Number of bits per word of `fd_set` (some code assumes this is 32) */
#define NFDBITS   __NFDBITS
#define __DARWIN_NFDBITS   __NFDBITS
#define DARWIN_NFDBITS   __NFDBITS
/** Number of bits in a long */
#define BITS_PER_LONGINT   BITS_PER_LONG
/** Number of bits in a long */
#define LONGBITS   BITS_PER_LONG
/** Number of bits in a long */
#define BITS_PER_LONG_INT   BITS_PER_LONG
/** Number of bytes in a long */
#define BYTES_PER_LONG_INT   BYTES_PER_LONG
#define TYPESIZE_LONG   BYTES_PER_LONG
#define TYPESIZE_LONG_INT   BYTES_PER_LONG
#ifdef __SIZEOF_LONG__
#   ifndef SIZEOF_LONG
#      define SIZEOF_LONG   __SIZEOF_LONG__
#   endif
#else
#   ifndef SIZEOF_LONG
#      define SIZEOF_LONG   TYPESIZE_LONG
#   endif
#   ifndef __SIZEOF_LONG__
#      define __SIZEOF_LONG__   TYPESIZE_LONG
#   endif
#endif
/** Number of bits per long */
#define FDS_BITPERLONG   (8 * SIZEOF_LONG)
/** Number of bits per long */
#define BITPERLONG   FDS_BITPERLONG
#ifndef ARCH_SIZEOF_LONG
#   define ARCH_SIZEOF_LONG   SIZEOF_LONG
#endif
#ifndef FLOAT8BITS
#   define FLOAT8BITS   (8)
#endif
#ifndef BITS_PER_FLOAT8
#   define BITS_PER_FLOAT8   (8)
#endif
#ifndef BYTES_PER_FLOAT8
#   define BYTES_PER_FLOAT8   (1)
#endif
#define TYPESIZE_FLOAT8   (1)
#ifdef __SIZEOF_FLOAT8__
#   ifndef SIZEOF_FLOAT8
#      define SIZEOF_FLOAT8   __SIZEOF_FLOAT8__
#   endif
#else
#   ifndef SIZEOF_FLOAT8
#      define SIZEOF_FLOAT8   (1)
#   endif
#   ifndef __SIZEOF_FLOAT8__
#      define __SIZEOF_FLOAT8__   (1)
#   endif
#endif
#ifndef FLOAT16BITS
#   define FLOAT16BITS   (16)
#endif
#ifndef BITS_PER_FLOAT16
#   define BITS_PER_FLOAT16   (16)
#endif
#ifndef BYTES_PER_FLOAT16
#   define BYTES_PER_FLOAT16   (2)
#endif
#define TYPESIZE_FLOAT16   (2)
#ifdef __SIZEOF_FLOAT16__
#   ifndef SIZEOF_FLOAT16
#      define SIZEOF_FLOAT16   __SIZEOF_FLOAT16__
#   endif
#else
#   ifndef SIZEOF_FLOAT16
#      define SIZEOF_FLOAT16   (2)
#   endif
#   ifndef __SIZEOF_FLOAT16__
#      define __SIZEOF_FLOAT16__   (2)
#   endif
#endif
#ifndef __SIZEOF_FP16__
#   define __SIZEOF_FP16__   (2)
#endif
#ifndef SIZEOF_FP16
#   define SIZEOF_FP16   (2)
#endif
#ifndef FLOAT24BITS
#   define FLOAT24BITS   (24)
#endif
#ifndef BITS_PER_FLOAT24
#   define BITS_PER_FLOAT24   (24)
#endif
#ifndef BYTES_PER_FLOAT24
#   define BYTES_PER_FLOAT24   (3)
#endif
#define TYPESIZE_FLOAT24   (3)
#ifdef __SIZEOF_FLOAT24__
#   ifndef SIZEOF_FLOAT24
#      define SIZEOF_FLOAT24   __SIZEOF_FLOAT24__
#   endif
#else
#   ifndef SIZEOF_FLOAT24
#      define SIZEOF_FLOAT24   (3)
#   endif
#   ifndef __SIZEOF_FLOAT24__
#      define __SIZEOF_FLOAT24__   (3)
#   endif
#endif
#ifndef FLOATBITS
#   define FLOATBITS   BITS_PER_FLOAT
#endif
#define TYPESIZE_FLOAT   BYTES_PER_FLOAT
#ifdef __SIZEOF_FLOAT__
#   ifndef SIZEOF_FLOAT
#      define SIZEOF_FLOAT   __SIZEOF_FLOAT__
#   endif
#else
#   ifndef SIZEOF_FLOAT
#      define SIZEOF_FLOAT   TYPESIZE_FLOAT
#   endif
#   ifndef __SIZEOF_FLOAT__
#      define __SIZEOF_FLOAT__   TYPESIZE_FLOAT
#   endif
#endif
#ifndef SIZEOF_SFTYPE
#   define SIZEOF_SFTYPE   SIZEOF_FLOAT
#endif
#ifndef __SIZEOF_FLOAT32__
#   define __SIZEOF_FLOAT32__   __SIZEOF_FLOAT__
#endif
#ifndef SIZEOF_FLOAT32
#   define SIZEOF_FLOAT32   __SIZEOF_FLOAT__
#endif
/** Size of a double */
#define TYPESIZE_DOUBLE   BYTES_PER_DOUBLE
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
#ifndef DOUBLEBITS
#   define DOUBLEBITS   BITS_PER_DOUBLE
#endif
#ifndef SIZEOF_DFTYPE
#   define SIZEOF_DFTYPE   SIZEOF_DOUBLE
#endif
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
#ifndef TYPESIZE_WCHAR_T
#   define TYPESIZE_WCHAR_T   __SIZEOF_WCHAR_T__
#endif
#ifndef __WCHAR_WIDTH__
/** The bit-width of wchar_t */
#   define __WCHAR_WIDTH__   (__SIZEOF_WCHAR_T__ * 8)
#endif
#ifndef WCHAR_WIDTH
#   define WCHAR_WIDTH   __WCHAR_WIDTH__
#endif
/** Number of bits in wchar_t */
#define BITS_PER_WCHAR_T   (SIZEOF_WCHAR_T * 8)
/** Number of bits in wchar_t */
#define BITSIZEOF_WCHAR_T   (SIZEOF_WCHAR_T * 8)
#ifndef __SIZEOF_WINT_T__
#   define __SIZEOF_WINT_T__   BYTES_PER_INT
#endif
#ifndef SIZEOF_WINT_T
#   define SIZEOF_WINT_T   BYTES_PER_INT
#endif
#ifndef TYPESIZE_WINT_T
#   define TYPESIZE_WINT_T   BYTES_PER_INT
#endif
#ifndef __WINT_WIDTH__
/** The bit-width of wint_t */
#   define __WINT_WIDTH__   (BYTES_PER_INT * 0x8)
#endif
#ifndef WINT_WIDTH
#   define WINT_WIDTH   __WINT_WIDTH__
#endif
/** Number of bits in wint_t */
#define BITS_PER_WINT_T   (SIZEOF_WINT_T * 8)
/** Number of bits in wint_t */
#define BITSIZEOF_WINT_T   BITS_PER_WINT_T
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
#ifndef TYPESIZE_RUNE
#   define TYPESIZE_RUNE   __SIZEOF_RUNE__
#endif
/** Number of bits in Rune */
#define BITS_PER_RUNE   (SIZEOF_RUNE * 8)
/** Number of bits in Rune */
#define BITSIZEOF_RUNE   (SIZEOF_RUNE * 8)
#ifdef __SIZEOF_MBSTATE_T__
#   ifndef SIZEOF_MBSTATE_T
#      define SIZEOF_MBSTATE_T   __SIZEOF_MBSTATE_T__
#   endif
#else
#   ifndef SIZEOF_MBSTATE_T
#      define SIZEOF_MBSTATE_T   (64)
#   endif
#   ifndef __SIZEOF_MBSTATE_T__
#      define __SIZEOF_MBSTATE_T__   (64)
#   endif
#endif
/** Number of bits in mbstate_t */
#define BITS_PER_MBSTATE_T   (512)
#ifndef TYPESIZE_INTMAX
#   define TYPESIZE_INTMAX   TYPESIZE_INTMAX_T
#endif
#ifndef TYPESIZE_UINTMAX_T
#   define TYPESIZE_UINTMAX_T   TYPESIZE_INTMAX_T
#endif
#ifndef TYPESIZE_UINTMAX
#   define TYPESIZE_UINTMAX   TYPESIZE_UINTMAX_T
#endif
#ifndef BYTES_PER_INTMAX_T
#   define BYTES_PER_INTMAX_T   TYPESIZE_INTMAX_T
#endif
#ifndef BYTES_PER_INTMAX
#   define BYTES_PER_INTMAX   TYPESIZE_INTMAX_T
#endif
#ifndef BYTES_PER_UINTMAX_T
#   define BYTES_PER_UINTMAX_T   TYPESIZE_INTMAX_T
#endif
#ifndef BYTES_PER_UINTMAX
#   define BYTES_PER_UINTMAX   TYPESIZE_INTMAX_T
#endif
#if ((!defined(_LDBL_EQ_DBL)) && SUPPORTS_LONG_DOUBLE && (SIZEOF_DOUBLE == SIZEOF_LONG_DOUBLE))
#   define _LDBL_EQ_DBL   (1)
#   define LDBL_EQ_DBL   (1)
#endif
// DECIMAL FLOAT DATATYPE SIZES
#ifndef TYPESIZE_DECIMAL32
#   define TYPESIZE_DECIMAL32   (4)
#endif
#ifndef __SIZEOF_DECIMAL32__
#   define __SIZEOF_DECIMAL32__   (4)
#endif
#ifndef SIZEOF_DECIMAL32
#   define SIZEOF_DECIMAL32   (4)
#endif
#ifndef TYPESIZE_DECIMAL_FLOAT32
#   define TYPESIZE_DECIMAL_FLOAT32   (4)
#endif
#ifndef __SIZEOF_DECIMAL_FLOAT32__
#   define __SIZEOF_DECIMAL_FLOAT32__   (4)
#endif
#ifndef SIZEOF_DECIMAL_FLOAT32
#   define SIZEOF_DECIMAL_FLOAT32   (4)
#endif
#ifndef BYTES_PER_DECIMAL_FLOAT32
#   define BYTES_PER_DECIMAL_FLOAT32   (4)
#endif
#ifndef BITS_PER_DECIMAL_FLOAT32
#   define BITS_PER_DECIMAL_FLOAT32   (32)
#endif
#ifndef TYPESIZE_DECIMAL64
#   define TYPESIZE_DECIMAL64   (8)
#endif
#ifndef __SIZEOF_DECIMAL64__
#   define __SIZEOF_DECIMAL64__   (8)
#endif
#ifndef SIZEOF_DECIMAL64
#   define SIZEOF_DECIMAL64   (8)
#endif
#ifndef TYPESIZE_DECIMAL_FLOAT64
#   define TYPESIZE_DECIMAL_FLOAT64   (8)
#endif
#ifndef __SIZEOF_DECIMAL_FLOAT64__
#   define __SIZEOF_DECIMAL_FLOAT64__   (8)
#endif
#ifndef SIZEOF_DECIMAL_FLOAT64
#   define SIZEOF_DECIMAL_FLOAT64   (8)
#endif
#ifndef BYTES_PER_DECIMAL_FLOAT64
#   define BYTES_PER_DECIMAL_FLOAT64   (8)
#endif
#ifndef BITS_PER_DECIMAL_FLOAT64
#   define BITS_PER_DECIMAL_FLOAT64   (64)
#endif
#ifndef TYPESIZE_DECIMAL128
#   define TYPESIZE_DECIMAL128   (16)
#endif
#ifndef __SIZEOF_DECIMAL128__
#   define __SIZEOF_DECIMAL128__   (16)
#endif
#ifndef SIZEOF_DECIMAL128
#   define SIZEOF_DECIMAL128   (16)
#endif
#ifndef TYPESIZE_DECIMAL_FLOAT128
#   define TYPESIZE_DECIMAL_FLOAT128   (16)
#endif
#ifndef __SIZEOF_DECIMAL_FLOAT128__
#   define __SIZEOF_DECIMAL_FLOAT128__   (16)
#endif
#ifndef SIZEOF_DECIMAL_FLOAT128
#   define SIZEOF_DECIMAL_FLOAT128   (16)
#endif
#ifndef BYTES_PER_DECIMAL_FLOAT128
#   define BYTES_PER_DECIMAL_FLOAT128   (16)
#endif
#ifndef BITS_PER_DECIMAL_FLOAT128
#   define BITS_PER_DECIMAL_FLOAT128   (128)
#endif
#ifndef TYPESIZE_DECIMAL256
#   define TYPESIZE_DECIMAL256   (32)
#endif
#ifndef __SIZEOF_DECIMAL256__
#   define __SIZEOF_DECIMAL256__   (32)
#endif
#ifndef SIZEOF_DECIMAL256
#   define SIZEOF_DECIMAL256   (32)
#endif
#ifndef TYPESIZE_DECIMAL_FLOAT256
#   define TYPESIZE_DECIMAL_FLOAT256   (32)
#endif
#ifndef __SIZEOF_DECIMAL_FLOAT256__
#   define __SIZEOF_DECIMAL_FLOAT256__   (32)
#endif
#ifndef SIZEOF_DECIMAL_FLOAT256
#   define SIZEOF_DECIMAL_FLOAT256   (32)
#endif
#ifndef BYTES_PER_DECIMAL_FLOAT256
#   define BYTES_PER_DECIMAL_FLOAT256   (32)
#endif
#ifndef BITS_PER_DECIMAL_FLOAT256
#   define BITS_PER_DECIMAL_FLOAT256   (256)
#endif
#ifndef TYPESIZE_DECIMAL512
#   define TYPESIZE_DECIMAL512   (64)
#endif
#ifndef __SIZEOF_DECIMAL512__
#   define __SIZEOF_DECIMAL512__   (64)
#endif
#ifndef SIZEOF_DECIMAL512
#   define SIZEOF_DECIMAL512   (64)
#endif
#ifndef TYPESIZE_DECIMAL_FLOAT512
#   define TYPESIZE_DECIMAL_FLOAT512   (64)
#endif
#ifndef __SIZEOF_DECIMAL_FLOAT512__
#   define __SIZEOF_DECIMAL_FLOAT512__   (64)
#endif
#ifndef SIZEOF_DECIMAL_FLOAT512
#   define SIZEOF_DECIMAL_FLOAT512   (64)
#endif
#ifndef BYTES_PER_DECIMAL_FLOAT512
#   define BYTES_PER_DECIMAL_FLOAT512   (64)
#endif
#ifndef BITS_PER_DECIMAL_FLOAT512
#   define BITS_PER_DECIMAL_FLOAT512   (512)
#endif
// FRACTIONAL & ACCUM DATATYPE SIZES
#ifdef __SIZEOF_SHORT_FRACT__
#   ifndef SIZEOF_SHORT_FRACT
#      define SIZEOF_SHORT_FRACT   __SIZEOF_SHORT_FRACT__
#   endif
#else
#   ifndef SIZEOF_SHORT_FRACT
#      define SIZEOF_SHORT_FRACT   (1)
#   endif
#   ifndef __SIZEOF_SHORT_FRACT__
#      define __SIZEOF_SHORT_FRACT__   (1)
#   endif
#endif
/** Number of bytes in short Fract */
#define BYTES_PER_SHORT_FRACT   SIZEOF_SHORT_FRACT
/** Number of bits in short Fract */
#define BITS_PER_SHORT_FRACT   (SIZEOF_SHORT_FRACT * 8)
#ifdef __SIZEOF_FRACT__
#   ifndef SIZEOF_FRACT
#      define SIZEOF_FRACT   __SIZEOF_FRACT__
#   endif
#else
#   ifndef SIZEOF_FRACT
#      define SIZEOF_FRACT   (2)
#   endif
#   ifndef __SIZEOF_FRACT__
#      define __SIZEOF_FRACT__   (2)
#   endif
#endif
/** Number of bytes in Fract */
#define BYTES_PER_FRACT   SIZEOF_FRACT
/** Number of bits in Fract */
#define BITS_PER_FRACT   (SIZEOF_FRACT * 8)
#ifdef __SIZEOF_FX_T__
#   ifndef SIZEOF_FX_T
#      define SIZEOF_FX_T   __SIZEOF_FX_T__
#   endif
#else
#   ifndef SIZEOF_FX_T
#      define SIZEOF_FX_T   SIZEOF_FRACT
#   endif
#   ifndef __SIZEOF_FX_T__
#      define __SIZEOF_FX_T__   SIZEOF_FRACT
#   endif
#endif
#define BYTES_PER_FX_T   SIZEOF_FX_T
#define BITS_PER_FX_T   BITS_PER_FRACT
#ifdef __SIZEOF_LONG_FRACT__
#   ifndef SIZEOF_LONG_FRACT
#      define SIZEOF_LONG_FRACT   __SIZEOF_LONG_FRACT__
#   endif
#else
#   ifndef SIZEOF_LONG_FRACT
#      define SIZEOF_LONG_FRACT   (4)
#   endif
#   ifndef __SIZEOF_LONG_FRACT__
#      define __SIZEOF_LONG_FRACT__   (4)
#   endif
#endif
/** Number of bytes in long Fract */
#define BYTES_PER_LONG_FRACT   SIZEOF_LONG_FRACT
/** Number of bits in long Fract */
#define BITS_PER_LONG_FRACT   (SIZEOF_LONG_FRACT * 8)
#ifdef __SIZEOF_LONG_LONG_FRACT__
#   ifndef SIZEOF_LONG_LONG_FRACT
#      define SIZEOF_LONG_LONG_FRACT   __SIZEOF_LONG_LONG_FRACT__
#   endif
#else
#   ifndef SIZEOF_LONG_LONG_FRACT
#      define SIZEOF_LONG_LONG_FRACT   (8)
#   endif
#   ifndef __SIZEOF_LONG_LONG_FRACT__
#      define __SIZEOF_LONG_LONG_FRACT__   (8)
#   endif
#endif
/** Number of bytes in long Fract */
#define BYTES_PER_LONG_LONG_FRACT   SIZEOF_LONG_LONG_FRACT
/** Number of bits in long Fract */
#define BITS_PER_LONG_LONG_FRACT   (SIZEOF_LONG_LONG_FRACT * 8)
#ifdef __SIZEOF_SHORT_ACCUM__
#   ifndef SIZEOF_SHORT_ACCUM
#      define SIZEOF_SHORT_ACCUM   __SIZEOF_SHORT_ACCUM__
#   endif
#else
#   ifndef SIZEOF_SHORT_ACCUM
#      define SIZEOF_SHORT_ACCUM   (2)
#   endif
#   ifndef __SIZEOF_SHORT_ACCUM__
#      define __SIZEOF_SHORT_ACCUM__   (2)
#   endif
#endif
/** Number of bytes in short Accum */
#define BYTES_PER_SHORT_ACCUM   SIZEOF_SHORT_ACCUM
/** Number of bits in short Accum */
#define BITS_PER_SHORT_ACCUM   (SIZEOF_SHORT_ACCUM * 8)
#ifdef __SIZEOF_ACCUM__
#   ifndef SIZEOF_ACCUM
#      define SIZEOF_ACCUM   __SIZEOF_ACCUM__
#   endif
#else
#   ifndef SIZEOF_ACCUM
#      define SIZEOF_ACCUM   (4)
#   endif
#   ifndef __SIZEOF_ACCUM__
#      define __SIZEOF_ACCUM__   (4)
#   endif
#endif
/** Number of bytes in Accum */
#define BYTES_PER_ACCUM   SIZEOF_ACCUM
/** Number of bits in Accum */
#define BITS_PER_ACCUM   (SIZEOF_ACCUM * 8)
#ifdef __SIZEOF_LONG_ACCUM__
#   ifndef SIZEOF_LONG_ACCUM
#      define SIZEOF_LONG_ACCUM   __SIZEOF_LONG_ACCUM__
#   endif
#else
#   ifndef SIZEOF_LONG_ACCUM
#      define SIZEOF_LONG_ACCUM   (8)
#   endif
#   ifndef __SIZEOF_LONG_ACCUM__
#      define __SIZEOF_LONG_ACCUM__   (8)
#   endif
#endif
/** Number of bytes in long Accum */
#define BYTES_PER_LONG_ACCUM   SIZEOF_LONG_ACCUM
/** Number of bits in long Accum */
#define BITS_PER_LONG_ACCUM   (SIZEOF_LONG_ACCUM * 8)
#ifdef __SIZEOF_XINT_HR_T__
#   ifndef SIZEOF_XINT_HR_T
#      define SIZEOF_XINT_HR_T   __SIZEOF_XINT_HR_T__
#   endif
#else
#   ifndef SIZEOF_XINT_HR_T
#      define SIZEOF_XINT_HR_T   (2)
#   endif
#   ifndef __SIZEOF_XINT_HR_T__
#      define __SIZEOF_XINT_HR_T__   (2)
#   endif
#endif
#define BYTES_PER_XINT_HR_T   SIZEOF_XINT_HR_T
#define BITS_PER_XINT_HR_T   (16)
#ifdef __SIZEOF_XINT_UHR_T__
#   ifndef SIZEOF_XINT_UHR_T
#      define SIZEOF_XINT_UHR_T   __SIZEOF_XINT_UHR_T__
#   endif
#else
#   ifndef SIZEOF_XINT_UHR_T
#      define SIZEOF_XINT_UHR_T   (2)
#   endif
#   ifndef __SIZEOF_XINT_UHR_T__
#      define __SIZEOF_XINT_UHR_T__   (2)
#   endif
#endif
#define BYTES_PER_XINT_UHR_T   SIZEOF_XINT_UHR_T
#define BITS_PER_XINT_UHR_T   (16)
#ifdef __SIZEOF_XINT_HK_T__
#   ifndef SIZEOF_XINT_HK_T
#      define SIZEOF_XINT_HK_T   __SIZEOF_XINT_HK_T__
#   endif
#else
#   ifndef SIZEOF_XINT_HK_T
#      define SIZEOF_XINT_HK_T   (4)
#   endif
#   ifndef __SIZEOF_XINT_HK_T__
#      define __SIZEOF_XINT_HK_T__   (4)
#   endif
#endif
#define BYTES_PER_XINT_HK_T   SIZEOF_XINT_HK_T
#define BITS_PER_XINT_HK_T   (32)
#ifdef __SIZEOF_XINT_UHK_T__
#   ifndef SIZEOF_XINT_UHK_T
#      define SIZEOF_XINT_UHK_T   __SIZEOF_XINT_UHK_T__
#   endif
#else
#   ifndef SIZEOF_XINT_UHK_T
#      define SIZEOF_XINT_UHK_T   (4)
#   endif
#   ifndef __SIZEOF_XINT_UHK_T__
#      define __SIZEOF_XINT_UHK_T__   (4)
#   endif
#endif
#define BYTES_PER_XINT_UHK_T   SIZEOF_XINT_UHK_T
#define BITS_PER_XINT_UHK_T   (32)
#ifdef __SIZEOF_XINT_R_T__
#   ifndef SIZEOF_XINT_R_T
#      define SIZEOF_XINT_R_T   __SIZEOF_XINT_R_T__
#   endif
#else
#   ifndef SIZEOF_XINT_R_T
#      define SIZEOF_XINT_R_T   (4)
#   endif
#   ifndef __SIZEOF_XINT_R_T__
#      define __SIZEOF_XINT_R_T__   (4)
#   endif
#endif
#define BYTES_PER_XINT_R_T   SIZEOF_XINT_R_T
#define BITS_PER_XINT_R_T   (32)
#ifdef __SIZEOF_XINT_UR_T__
#   ifndef SIZEOF_XINT_UR_T
#      define SIZEOF_XINT_UR_T   __SIZEOF_XINT_UR_T__
#   endif
#else
#   ifndef SIZEOF_XINT_UR_T
#      define SIZEOF_XINT_UR_T   (4)
#   endif
#   ifndef __SIZEOF_XINT_UR_T__
#      define __SIZEOF_XINT_UR_T__   (4)
#   endif
#endif
#define BYTES_PER_XINT_UR_T   SIZEOF_XINT_UR_T
#define BITS_PER_XINT_UR_T   (32)
#ifdef __SIZEOF_XINT_K_T__
#   ifndef SIZEOF_XINT_K_T
#      define SIZEOF_XINT_K_T   __SIZEOF_XINT_K_T__
#   endif
#else
#   ifndef SIZEOF_XINT_K_T
#      define SIZEOF_XINT_K_T   (8)
#   endif
#   ifndef __SIZEOF_XINT_K_T__
#      define __SIZEOF_XINT_K_T__   (8)
#   endif
#endif
#define BYTES_PER_XINT_K_T   SIZEOF_XINT_K_T
#define BITS_PER_XINT_K_T   (64)
#ifdef __SIZEOF_XINT_UK_T__
#   ifndef SIZEOF_XINT_UK_T
#      define SIZEOF_XINT_UK_T   __SIZEOF_XINT_UK_T__
#   endif
#else
#   ifndef SIZEOF_XINT_UK_T
#      define SIZEOF_XINT_UK_T   (8)
#   endif
#   ifndef __SIZEOF_XINT_UK_T__
#      define __SIZEOF_XINT_UK_T__   (8)
#   endif
#endif
#define BYTES_PER_XINT_UK_T   SIZEOF_XINT_UK_T
#define BITS_PER_XINT_UK_T   (64)
#ifdef __SIZEOF_XINT_LR_T__
#   ifndef SIZEOF_XINT_LR_T
#      define SIZEOF_XINT_LR_T   __SIZEOF_XINT_LR_T__
#   endif
#else
#   ifndef SIZEOF_XINT_LR_T
#      define SIZEOF_XINT_LR_T   (8)
#   endif
#   ifndef __SIZEOF_XINT_LR_T__
#      define __SIZEOF_XINT_LR_T__   (8)
#   endif
#endif
#define BYTES_PER_XINT_LR_T   SIZEOF_XINT_LR_T
#define BITS_PER_XINT_LR_T   (64)
#ifdef __SIZEOF_XINT_ULR_T__
#   ifndef SIZEOF_XINT_ULR_T
#      define SIZEOF_XINT_ULR_T   __SIZEOF_XINT_ULR_T__
#   endif
#else
#   ifndef SIZEOF_XINT_ULR_T
#      define SIZEOF_XINT_ULR_T   (8)
#   endif
#   ifndef __SIZEOF_XINT_ULR_T__
#      define __SIZEOF_XINT_ULR_T__   (8)
#   endif
#endif
#define BYTES_PER_XINT_ULR_T   SIZEOF_XINT_ULR_T
#define BITS_PER_XINT_ULR_T   (64)
#ifdef __SIZEOF_INT_QI_T__
#   ifndef SIZEOF_INT_QI_T
#      define SIZEOF_INT_QI_T   __SIZEOF_INT_QI_T__
#   endif
#else
#   ifndef SIZEOF_INT_QI_T
#      define SIZEOF_INT_QI_T   (1)
#   endif
#   ifndef __SIZEOF_INT_QI_T__
#      define __SIZEOF_INT_QI_T__   (1)
#   endif
#endif
#define BYTES_PER_INT_QI_T   SIZEOF_INT_QI_T
#define BITS_PER_INT_QI_T   BITS_PER_CHAR
#ifdef __SIZEOF_INT_HI_T__
#   ifndef SIZEOF_INT_HI_T
#      define SIZEOF_INT_HI_T   __SIZEOF_INT_HI_T__
#   endif
#else
#   ifndef SIZEOF_INT_HI_T
#      define SIZEOF_INT_HI_T   SIZEOF_INT
#   endif
#   ifndef __SIZEOF_INT_HI_T__
#      define __SIZEOF_INT_HI_T__   SIZEOF_INT
#   endif
#endif
#define BYTES_PER_INT_HI_T   SIZEOF_INT_HI_T
#define BITS_PER_INT_HI_T   BITS_PER_INT
#ifdef __SIZEOF_INT_SI_T__
#   ifndef SIZEOF_INT_SI_T
#      define SIZEOF_INT_SI_T   __SIZEOF_INT_SI_T__
#   endif
#else
#   ifndef SIZEOF_INT_SI_T
#      define SIZEOF_INT_SI_T   SIZEOF_LONG
#   endif
#   ifndef __SIZEOF_INT_SI_T__
#      define __SIZEOF_INT_SI_T__   SIZEOF_LONG
#   endif
#endif
#define BYTES_PER_INT_SI_T   SIZEOF_INT_SI_T
#define BITS_PER_INT_SI_T   BITS_PER_LONG
#ifdef __SIZEOF_INT_DI_T__
#   ifndef SIZEOF_INT_DI_T
#      define SIZEOF_INT_DI_T   __SIZEOF_INT_DI_T__
#   endif
#else
#   ifndef SIZEOF_INT_DI_T
#      define SIZEOF_INT_DI_T   SIZEOF_LONG_LONG
#   endif
#   ifndef __SIZEOF_INT_DI_T__
#      define __SIZEOF_INT_DI_T__   SIZEOF_LONG_LONG
#   endif
#endif
#define BYTES_PER_INT_DI_T   SIZEOF_INT_DI_T
#define BITS_PER_INT_DI_T   BITS_PER_LONG_LONG
#ifdef __SIZEOF_UINT_QI_T__
#   ifndef SIZEOF_UINT_QI_T
#      define SIZEOF_UINT_QI_T   __SIZEOF_UINT_QI_T__
#   endif
#else
#   ifndef SIZEOF_UINT_QI_T
#      define SIZEOF_UINT_QI_T   (1)
#   endif
#   ifndef __SIZEOF_UINT_QI_T__
#      define __SIZEOF_UINT_QI_T__   (1)
#   endif
#endif
#define BYTES_PER_UINT_QI_T   SIZEOF_UINT_QI_T
#define BITS_PER_UINT_QI_T   BITS_PER_CHAR
#ifdef __SIZEOF_UINT_HI_T__
#   ifndef SIZEOF_UINT_HI_T
#      define SIZEOF_UINT_HI_T   __SIZEOF_UINT_HI_T__
#   endif
#else
#   ifndef SIZEOF_UINT_HI_T
#      define SIZEOF_UINT_HI_T   SIZEOF_INT
#   endif
#   ifndef __SIZEOF_UINT_HI_T__
#      define __SIZEOF_UINT_HI_T__   SIZEOF_INT
#   endif
#endif
#define BYTES_PER_UINT_HI_T   SIZEOF_UINT_HI_T
#define BITS_PER_UINT_HI_T   BITS_PER_INT
#ifdef __SIZEOF_UINT_SI_T__
#   ifndef SIZEOF_UINT_SI_T
#      define SIZEOF_UINT_SI_T   __SIZEOF_UINT_SI_T__
#   endif
#else
#   ifndef SIZEOF_UINT_SI_T
#      define SIZEOF_UINT_SI_T   SIZEOF_LONG
#   endif
#   ifndef __SIZEOF_UINT_SI_T__
#      define __SIZEOF_UINT_SI_T__   SIZEOF_LONG
#   endif
#endif
#define BYTES_PER_UINT_SI_T   SIZEOF_UINT_SI_T
#define BITS_PER_UINT_SI_T   BITS_PER_LONG
#ifdef __SIZEOF_UINT_DI_T__
#   ifndef SIZEOF_UINT_DI_T
#      define SIZEOF_UINT_DI_T   __SIZEOF_UINT_DI_T__
#   endif
#else
#   ifndef SIZEOF_UINT_DI_T
#      define SIZEOF_UINT_DI_T   SIZEOF_LONG_LONG
#   endif
#   ifndef __SIZEOF_UINT_DI_T__
#      define __SIZEOF_UINT_DI_T__   SIZEOF_LONG_LONG
#   endif
#endif
#define BYTES_PER_UINT_DI_T   SIZEOF_UINT_DI_T
#define BITS_PER_UINT_DI_T   BITS_PER_LONG_LONG
#ifdef __SIZEOF_INT_HR_T__
#   ifndef SIZEOF_INT_HR_T
#      define SIZEOF_INT_HR_T   __SIZEOF_INT_HR_T__
#   endif
#else
#   ifndef SIZEOF_INT_HR_T
#      define SIZEOF_INT_HR_T   SIZEOF_CHAR
#   endif
#   ifndef __SIZEOF_INT_HR_T__
#      define __SIZEOF_INT_HR_T__   SIZEOF_CHAR
#   endif
#endif
#define BYTES_PER_INT_HR_T   SIZEOF_INT_HR_T
#define BITS_PER_INT_HR_T   BITS_PER_CHAR
#ifdef __SIZEOF_INT_HK_T__
#   ifndef SIZEOF_INT_HK_T
#      define SIZEOF_INT_HK_T   __SIZEOF_INT_HK_T__
#   endif
#else
#   if (SIZEOF_INT == 4)
#      ifndef SIZEOF_INT_HK_T
#         define SIZEOF_INT_HK_T   SIZEOF_INT
#      endif
#      ifndef __SIZEOF_INT_HK_T__
#         define __SIZEOF_INT_HK_T__   SIZEOF_INT
#      endif
#   elif (SIZEOF_INT == 2)
#      ifndef SIZEOF_INT_HK_T
#         define SIZEOF_INT_HK_T   SIZEOF_SHORT
#      endif
#      ifndef __SIZEOF_INT_HK_T__
#         define __SIZEOF_INT_HK_T__   SIZEOF_SHORT
#      endif
#   else
#      ifndef SIZEOF_INT_HK_T
#         define SIZEOF_INT_HK_T   SIZEOF_LONG
#      endif
#      ifndef __SIZEOF_INT_HK_T__
#         define __SIZEOF_INT_HK_T__   SIZEOF_LONG
#      endif
#   endif
#endif
#define BYTES_PER_INT_HK_T   SIZEOF_INT_HK_T
#define BITS_PER_INT_HK_T   (SIZEOF_INT_HK_T * 8)
#ifdef __SIZEOF_INT_R_T__
#   ifndef SIZEOF_INT_R_T
#      define SIZEOF_INT_R_T   __SIZEOF_INT_R_T__
#   endif
#else
#   if (SIZEOF_INT == 4)
#      ifndef SIZEOF_INT_R_T
#         define SIZEOF_INT_R_T   SIZEOF_INT
#      endif
#      ifndef __SIZEOF_INT_R_T__
#         define __SIZEOF_INT_R_T__   SIZEOF_INT
#      endif
#   elif (SIZEOF_INT == 2)
#      ifndef SIZEOF_INT_R_T
#         define SIZEOF_INT_R_T   SIZEOF_SHORT
#      endif
#      ifndef __SIZEOF_INT_R_T__
#         define __SIZEOF_INT_R_T__   SIZEOF_SHORT
#      endif
#   else
#      ifndef SIZEOF_INT_R_T
#         define SIZEOF_INT_R_T   SIZEOF_LONG
#      endif
#      ifndef __SIZEOF_INT_R_T__
#         define __SIZEOF_INT_R_T__   SIZEOF_LONG
#      endif
#   endif
#endif
#define BYTES_PER_INT_R_T   SIZEOF_INT_R_T
#define BITS_PER_INT_R_T   (SIZEOF_INT_R_T * 8)
#ifdef __SIZEOF_INT_K_T__
#   ifndef SIZEOF_INT_K_T
#      define SIZEOF_INT_K_T   __SIZEOF_INT_K_T__
#   endif
#else
#   if ((SIZEOF_INT == 4) || (SIZEOF_INT == 2))
#      ifndef SIZEOF_INT_K_T
#         define SIZEOF_INT_K_T   SIZEOF_INT
#      endif
#      ifndef __SIZEOF_INT_K_T__
#         define __SIZEOF_INT_K_T__   SIZEOF_INT
#      endif
#   else
#      ifndef SIZEOF_INT_K_T
#         define SIZEOF_INT_K_T   SIZEOF_LONG_LONG
#      endif
#      ifndef __SIZEOF_INT_K_T__
#         define __SIZEOF_INT_K_T__   SIZEOF_LONG_LONG
#      endif
#   endif
#endif
#define BYTES_PER_INT_K_T   SIZEOF_INT_K_T
#define BITS_PER_INT_K_T   (SIZEOF_INT_K_T * 8)
#ifdef __SIZEOF_INT_LR_T__
#   ifndef SIZEOF_INT_LR_T
#      define SIZEOF_INT_LR_T   __SIZEOF_INT_LR_T__
#   endif
#else
#   if ((SIZEOF_INT == 4) || (SIZEOF_INT == 2))
#      ifndef SIZEOF_INT_LR_T
#         define SIZEOF_INT_LR_T   SIZEOF_LONG
#      endif
#      ifndef __SIZEOF_INT_LR_T__
#         define __SIZEOF_INT_LR_T__   SIZEOF_LONG
#      endif
#   else
#      ifndef SIZEOF_INT_LR_T
#         define SIZEOF_INT_LR_T   SIZEOF_LONG_LONG
#      endif
#      ifndef __SIZEOF_INT_LR_T__
#         define __SIZEOF_INT_LR_T__   SIZEOF_LONG_LONG
#      endif
#   endif
#endif
#define BYTES_PER_INT_LR_T   SIZEOF_INT_LR_T
#define BITS_PER_INT_LR_T   (SIZEOF_INT_LR_T * 8)
#ifdef __SIZEOF_INT_LK_T__
#   ifndef SIZEOF_INT_LK_T
#      define SIZEOF_INT_LK_T   __SIZEOF_INT_LK_T__
#   endif
#else
#   if ((SIZEOF_INT == 4) || (SIZEOF_INT == 2))
#      ifndef SIZEOF_INT_LK_T
#         define SIZEOF_INT_LK_T   SIZEOF_LONG_LONG
#      endif
#      ifndef __SIZEOF_INT_LK_T__
#         define __SIZEOF_INT_LK_T__   SIZEOF_LONG_LONG
#      endif
#   endif
#endif
#define BYTES_PER_INT_LK_T   SIZEOF_INT_LK_T
#define BITS_PER_INT_LK_T   (SIZEOF_INT_LK_T * 8)
#ifdef __SIZEOF_INT_LLK_T__
#   ifndef SIZEOF_INT_LLK_T
#      define SIZEOF_INT_LLK_T   __SIZEOF_INT_LLK_T__
#   endif
#else
#   if ((SIZEOF_INT == 4) || (SIZEOF_INT == 2))
#      ifndef SIZEOF_INT_LLK_T
#         define SIZEOF_INT_LLK_T   SIZEOF_LONG_LONG
#      endif
#      ifndef __SIZEOF_INT_LLK_T__
#         define __SIZEOF_INT_LLK_T__   SIZEOF_LONG_LONG
#      endif
#   endif
#endif
#define BYTES_PER_INT_LLK_T   SIZEOF_INT_LLK_T
#define BITS_PER_INT_LLK_T   (SIZEOF_INT_LLK_T * 8)
#ifdef __SIZEOF_INT_LLR_T__
#   ifndef SIZEOF_INT_LLR_T
#      define SIZEOF_INT_LLR_T   __SIZEOF_INT_LLR_T__
#   endif
#else
#   if ((SIZEOF_INT == 4) || (SIZEOF_INT == 2))
#      ifndef SIZEOF_INT_LLR_T
#         define SIZEOF_INT_LLR_T   SIZEOF_LONG_LONG
#      endif
#      ifndef __SIZEOF_INT_LLR_T__
#         define __SIZEOF_INT_LLR_T__   SIZEOF_LONG_LONG
#      endif
#   endif
#endif
#define BYTES_PER_INT_LLR_T   SIZEOF_INT_LLR_T
#define BITS_PER_INT_LLR_T   (SIZEOF_INT_LLR_T * 8)
#ifdef __SIZEOF_SATFX_T__
#   ifndef SIZEOF_SATFX_T
#      define SIZEOF_SATFX_T   __SIZEOF_SATFX_T__
#   endif
#else
#   ifndef SIZEOF_SATFX_T
#      define SIZEOF_SATFX_T   (2)
#   endif
#   ifndef __SIZEOF_SATFX_T__
#      define __SIZEOF_SATFX_T__   (2)
#   endif
#endif
#ifdef __SIZEOF_FX_R_T__
#   ifndef SIZEOF_FX_R_T
#      define SIZEOF_FX_R_T   __SIZEOF_FX_R_T__
#   endif
#else
#   ifndef SIZEOF_FX_R_T
#      define SIZEOF_FX_R_T   (2)
#   endif
#   ifndef __SIZEOF_FX_R_T__
#      define __SIZEOF_FX_R_T__   (2)
#   endif
#endif
#ifdef __SIZEOF_FX_UR_T__
#   ifndef SIZEOF_FX_UR_T
#      define SIZEOF_FX_UR_T   __SIZEOF_FX_UR_T__
#   endif
#else
#   ifndef SIZEOF_FX_UR_T
#      define SIZEOF_FX_UR_T   (2)
#   endif
#   ifndef __SIZEOF_FX_UR_T__
#      define __SIZEOF_FX_UR_T__   (2)
#   endif
#endif
#ifdef __SIZEOF_FX_HR_T__
#   ifndef SIZEOF_FX_HR_T
#      define SIZEOF_FX_HR_T   __SIZEOF_FX_HR_T__
#   endif
#else
#   ifndef SIZEOF_FX_HR_T
#      define SIZEOF_FX_HR_T   (1)
#   endif
#   ifndef __SIZEOF_FX_HR_T__
#      define __SIZEOF_FX_HR_T__   (1)
#   endif
#endif
#ifdef __SIZEOF_FX_UHR_T__
#   ifndef SIZEOF_FX_UHR_T
#      define SIZEOF_FX_UHR_T   __SIZEOF_FX_UHR_T__
#   endif
#else
#   ifndef SIZEOF_FX_UHR_T
#      define SIZEOF_FX_UHR_T   (1)
#   endif
#   ifndef __SIZEOF_FX_UHR_T__
#      define __SIZEOF_FX_UHR_T__   (1)
#   endif
#endif
#ifdef __SIZEOF_FX_LR_T__
#   ifndef SIZEOF_FX_LR_T
#      define SIZEOF_FX_LR_T   __SIZEOF_FX_LR_T__
#   endif
#else
#   ifndef SIZEOF_FX_LR_T
#      define SIZEOF_FX_LR_T   (4)
#   endif
#   ifndef __SIZEOF_FX_LR_T__
#      define __SIZEOF_FX_LR_T__   (4)
#   endif
#endif
#ifdef __SIZEOF_FX_ULR_T__
#   ifndef SIZEOF_FX_ULR_T
#      define SIZEOF_FX_ULR_T   __SIZEOF_FX_ULR_T__
#   endif
#else
#   ifndef SIZEOF_FX_ULR_T
#      define SIZEOF_FX_ULR_T   (4)
#   endif
#   ifndef __SIZEOF_FX_ULR_T__
#      define __SIZEOF_FX_ULR_T__   (4)
#   endif
#endif
#ifdef __SIZEOF_FX_K_T__
#   ifndef SIZEOF_FX_K_T
#      define SIZEOF_FX_K_T   __SIZEOF_FX_K_T__
#   endif
#else
#   ifndef SIZEOF_FX_K_T
#      define SIZEOF_FX_K_T   (4)
#   endif
#   ifndef __SIZEOF_FX_K_T__
#      define __SIZEOF_FX_K_T__   (4)
#   endif
#endif
#ifdef __SIZEOF_FX_UK_T__
#   ifndef SIZEOF_FX_UK_T
#      define SIZEOF_FX_UK_T   __SIZEOF_FX_UK_T__
#   endif
#else
#   ifndef SIZEOF_FX_UK_T
#      define SIZEOF_FX_UK_T   (4)
#   endif
#   ifndef __SIZEOF_FX_UK_T__
#      define __SIZEOF_FX_UK_T__   (4)
#   endif
#endif
#ifdef __SIZEOF_FX_HK_T__
#   ifndef SIZEOF_FX_HK_T
#      define SIZEOF_FX_HK_T   __SIZEOF_FX_HK_T__
#   endif
#else
#   ifndef SIZEOF_FX_HK_T
#      define SIZEOF_FX_HK_T   (2)
#   endif
#   ifndef __SIZEOF_FX_HK_T__
#      define __SIZEOF_FX_HK_T__   (2)
#   endif
#endif
#ifdef __SIZEOF_FX_UHK_T__
#   ifndef SIZEOF_FX_UHK_T
#      define SIZEOF_FX_UHK_T   __SIZEOF_FX_UHK_T__
#   endif
#else
#   ifndef SIZEOF_FX_UHK_T
#      define SIZEOF_FX_UHK_T   (2)
#   endif
#   ifndef __SIZEOF_FX_UHK_T__
#      define __SIZEOF_FX_UHK_T__   (2)
#   endif
#endif
#ifdef __SIZEOF_FX_LK_T__
#   ifndef SIZEOF_FX_LK_T
#      define SIZEOF_FX_LK_T   __SIZEOF_FX_LK_T__
#   endif
#else
#   ifndef SIZEOF_FX_LK_T
#      define SIZEOF_FX_LK_T   (8)
#   endif
#   ifndef __SIZEOF_FX_LK_T__
#      define __SIZEOF_FX_LK_T__   (8)
#   endif
#endif
#ifdef __SIZEOF_FX_ULK_T__
#   ifndef SIZEOF_FX_ULK_T
#      define SIZEOF_FX_ULK_T   __SIZEOF_FX_ULK_T__
#   endif
#else
#   ifndef SIZEOF_FX_ULK_T
#      define SIZEOF_FX_ULK_T   (8)
#   endif
#   ifndef __SIZEOF_FX_ULK_T__
#      define __SIZEOF_FX_ULK_T__   (8)
#   endif
#endif
// COMPLEX DATATYPE SIZES
#ifdef __SIZEOF_COMPLEX_FLOAT__
#   ifndef SIZEOF_COMPLEX_FLOAT
#      define SIZEOF_COMPLEX_FLOAT   __SIZEOF_COMPLEX_FLOAT__
#   endif
#else
#   ifndef SIZEOF_COMPLEX_FLOAT
#      define SIZEOF_COMPLEX_FLOAT   (8)
#   endif
#   ifndef __SIZEOF_COMPLEX_FLOAT__
#      define __SIZEOF_COMPLEX_FLOAT__   (8)
#   endif
#endif
/** Number of bytes in complex float */
#define BYTES_PER_COMPLEX_FLOAT   SIZEOF_COMPLEX_FLOAT
/** Number of bits in complex float */
#define BITS_PER_COMPLEX_FLOAT   (SIZEOF_COMPLEX_FLOAT * 8)
#ifndef TYPESIZE_COMPLEX
#   define TYPESIZE_COMPLEX   (SIZEOF_COMPLEX_FLOAT)
#endif
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
#      define SIZEOF_COMPLEX_DOUBLE   (16)
#   endif
#   ifndef __SIZEOF_COMPLEX_DOUBLE__
#      define __SIZEOF_COMPLEX_DOUBLE__   (16)
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
#      define SIZEOF_COMPLEX_LONG_DOUBLE   (32)
#   endif
#   ifndef __SIZEOF_COMPLEX_LONG_DOUBLE__
#      define __SIZEOF_COMPLEX_LONG_DOUBLE__   (32)
#   endif
#endif
/** Number of bytes in complex long double */
#define BYTES_PER_COMPLEX_LONG_DOUBLE   SIZEOF_COMPLEX_LONG_DOUBLE
/** Number of bits in complex long double */
#define BITS_PER_COMPLEX_LONG_DOUBLE   (SIZEOF_COMPLEX_LONG_DOUBLE * 8)
#ifndef TYPESIZE_I_FLOAT
#   define TYPESIZE_I_FLOAT   (8)
#endif
#ifndef __SIZEOF_I_FLOAT__
#   define __SIZEOF_I_FLOAT__   TYPESIZE_I_FLOAT
#endif
#ifndef SIZEOF_I_FLOAT
#   define SIZEOF_I_FLOAT   TYPESIZE_I_FLOAT
#endif
#ifndef BITS_PER_I_FLOAT
#   define BITS_PER_I_FLOAT   (32)
#endif
#ifndef TYPESIZE_I_DOUBLE
#   define TYPESIZE_I_DOUBLE   (16)
#endif
#ifndef __SIZEOF_I_DOUBLE__
#   define __SIZEOF_I_DOUBLE__   TYPESIZE_I_DOUBLE
#endif
#ifndef SIZEOF_I_DOUBLE
#   define SIZEOF_I_DOUBLE   TYPESIZE_I_DOUBLE
#endif
#ifndef BITS_PER_I_DOUBLE
#   define BITS_PER_I_DOUBLE   (64)
#endif
#ifndef TYPESIZE_I_LONG_DOUBLE
#   define TYPESIZE_I_LONG_DOUBLE   (32)
#endif
#ifndef __SIZEOF_I_LONG_DOUBLE__
#   define __SIZEOF_I_LONG_DOUBLE__   TYPESIZE_I_LONG_DOUBLE
#endif
#ifndef SIZEOF_I_LONG_DOUBLE
#   define SIZEOF_I_LONG_DOUBLE   TYPESIZE_I_LONG_DOUBLE
#endif
#ifndef BITS_PER_I_LONG_DOUBLE
#   define BITS_PER_I_LONG_DOUBLE   (128)
#endif
// POSIX THREAD DATATYPE SIZES
#ifdef X86_64
#   if IS_WORDSIZE_64
#      define __SIZEOF_PTHREAD_ATTR_T   56
#      define __SIZEOF_PTHREAD_MUTEX_T   40
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   56
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   32
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   else
#      define __SIZEOF_PTHREAD_ATTR_T   32
#      define __SIZEOF_PTHREAD_MUTEX_T   32
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   44
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   20
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   endif
#elif defined(POWERPC)
#   if IS_WORDSIZE_64
#      define __SIZEOF_PTHREAD_ATTR_T   56
#      define __SIZEOF_PTHREAD_MUTEX_T   40
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   56
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   32
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   else
#      define __SIZEOF_PTHREAD_ATTR_T   36
#      define __SIZEOF_PTHREAD_MUTEX_T   24
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   32
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   20
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   endif
#elif defined(ARM64)
#   define __SIZEOF_PTHREAD_ATTR_T   64
#   define __SIZEOF_PTHREAD_MUTEX_T   48
#   define __SIZEOF_PTHREAD_MUTEXATTR_T   8
#   define __SIZEOF_PTHREAD_COND_T   48
#   define __SIZEOF_PTHREAD_COND_COMPAT_T   48
#   define __SIZEOF_PTHREAD_CONDATTR_T   8
#   define __SIZEOF_PTHREAD_RWLOCK_T   56
#   define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#   define __SIZEOF_PTHREAD_BARRIER_T   32
#   define __SIZEOF_PTHREAD_BARRIERATTR_T   8
#elif defined(ARC)
#   if IS_WORDSIZE_64
#      define __SIZEOF_PTHREAD_ATTR_T   56
#      define __SIZEOF_PTHREAD_MUTEX_T   40
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   56
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   32
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   else
#      define __SIZEOF_PTHREAD_ATTR_T   36
#      define __SIZEOF_PTHREAD_MUTEX_T   24
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   32
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   20
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   endif
#elif defined(ALPHA)
#   define __SIZEOF_PTHREAD_ATTR_T   56
#   define __SIZEOF_PTHREAD_MUTEX_T   40
#   define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define __SIZEOF_PTHREAD_COND_T   48
#   define __SIZEOF_PTHREAD_CONDATTR_T   4
#   define __SIZEOF_PTHREAD_RWLOCK_T   56
#   define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#   define __SIZEOF_PTHREAD_BARRIER_T   32
#   define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#elif defined(HPPA)
#   define __SIZEOF_PTHREAD_ATTR_T   36
#   define __SIZEOF_PTHREAD_BARRIER_T   48
#   define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   define __SIZEOF_PTHREAD_COND_T   48
#   define __SIZEOF_PTHREAD_CONDATTR_T   4
#   define __SIZEOF_PTHREAD_MUTEX_T   48
#   define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define __SIZEOF_PTHREAD_RWLOCK_T   64
#   define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#elif defined(ITANIUM)
#   define __SIZEOF_PTHREAD_ATTR_T   56
#   define __SIZEOF_PTHREAD_MUTEX_T   40
#   define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define __SIZEOF_PTHREAD_COND_T   48
#   define __SIZEOF_PTHREAD_CONDATTR_T   4
#   define __SIZEOF_PTHREAD_RWLOCK_T   56
#   define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#   define __SIZEOF_PTHREAD_BARRIER_T   32
#   define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#elif defined(M68K)
#   define __SIZEOF_PTHREAD_ATTR_T   36
#   define __SIZEOF_PTHREAD_MUTEX_T   24
#   define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define __SIZEOF_PTHREAD_COND_T   48
#   define __SIZEOF_PTHREAD_CONDATTR_T   4
#   define __SIZEOF_PTHREAD_RWLOCK_T   32
#   define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#   define __SIZEOF_PTHREAD_BARRIER_T   20
#   define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#elif defined(MICROBLAZE)
#   define __SIZEOF_PTHREAD_ATTR_T   36
#   define __SIZEOF_PTHREAD_MUTEX_T   24
#   define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define __SIZEOF_PTHREAD_COND_T   48
#   define __SIZEOF_PTHREAD_COND_COMPAT_T   12
#   define __SIZEOF_PTHREAD_CONDATTR_T   4
#   define __SIZEOF_PTHREAD_RWLOCK_T   32
#   define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#   define __SIZEOF_PTHREAD_BARRIER_T   20
#   define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#elif defined(MIPS)
#   if (_MIPS_SIM == _ABI64)
#      define __SIZEOF_PTHREAD_ATTR_T   56
#      define __SIZEOF_PTHREAD_MUTEX_T   40
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   56
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   32
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   else
#      define __SIZEOF_PTHREAD_ATTR_T   36
#      define __SIZEOF_PTHREAD_MUTEX_T   24
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   32
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   20
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   endif
#elif defined(NIOS2)
#   define __SIZEOF_PTHREAD_ATTR_T   36
#   define __SIZEOF_PTHREAD_MUTEX_T   24
#   define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define __SIZEOF_PTHREAD_COND_T   48
#   define __SIZEOF_PTHREAD_CONDATTR_T   4
#   define __SIZEOF_PTHREAD_RWLOCK_T   32
#   define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#   define __SIZEOF_PTHREAD_BARRIER_T   20
#   define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#elif defined(S390)
#  if IS_WORDSIZE_64
#      define __SIZEOF_PTHREAD_ATTR_T   56
#      define __SIZEOF_PTHREAD_MUTEX_T   40
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   56
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   32
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   else
#      define __SIZEOF_PTHREAD_ATTR_T   36
#      define __SIZEOF_PTHREAD_MUTEX_T   24
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   32
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   20
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   endif
#elif defined(SPARC)
#   if IS_WORDSIZE_64
#      define __SIZEOF_PTHREAD_ATTR_T   56
#      define __SIZEOF_PTHREAD_MUTEX_T   40
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   56
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   32
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   else
#      define __SIZEOF_PTHREAD_ATTR_T   36
#      define __SIZEOF_PTHREAD_MUTEX_T   24
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   32
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   20
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   endif
#elif defined(SUPERH)
#   define __SIZEOF_PTHREAD_ATTR_T   36
#   define __SIZEOF_PTHREAD_MUTEX_T   24
#   define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define __SIZEOF_PTHREAD_COND_T   48
#   define __SIZEOF_PTHREAD_COND_COMPAT_T   12
#   define __SIZEOF_PTHREAD_CONDATTR_T   4
#   define __SIZEOF_PTHREAD_RWLOCK_T   32
#   define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#   define __SIZEOF_PTHREAD_BARRIER_T   20
#   define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#elif defined(TILE)
#   if IS_WORDSIZE_64
#      define __SIZEOF_PTHREAD_ATTR_T   56
#      define __SIZEOF_PTHREAD_MUTEX_T   40
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   56
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   32
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   else
#      define __SIZEOF_PTHREAD_ATTR_T   36
#      define __SIZEOF_PTHREAD_MUTEX_T   24
#      define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#      define __SIZEOF_PTHREAD_COND_T   48
#      define __SIZEOF_PTHREAD_CONDATTR_T   4
#      define __SIZEOF_PTHREAD_RWLOCK_T   32
#      define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#      define __SIZEOF_PTHREAD_BARRIER_T   20
#      define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#   endif
#elif defined(XTENSA)
#   define __SIZEOF_PTHREAD_ATTR_T   36
#   define __SIZEOF_PTHREAD_MUTEX_T   24
#   define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define __SIZEOF_PTHREAD_COND_T   48
#   define __SIZEOF_PTHREAD_COND_COMPAT_T   12
#   define __SIZEOF_PTHREAD_CONDATTR_T   4
#   define __SIZEOF_PTHREAD_RWLOCK_T   32
#   define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#   define __SIZEOF_PTHREAD_BARRIER_T   20
#   define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#else  // ARM, i386, & others
#   define __SIZEOF_PTHREAD_ATTR_T   36
#   define __SIZEOF_PTHREAD_MUTEX_T   24
#   define __SIZEOF_PTHREAD_MUTEXATTR_T   4
#   define __SIZEOF_PTHREAD_COND_T   48
#   define __SIZEOF_PTHREAD_CONDATTR_T   4
#   define __SIZEOF_PTHREAD_RWLOCK_T   32
#   define __SIZEOF_PTHREAD_RWLOCKATTR_T   8
#   define __SIZEOF_PTHREAD_BARRIER_T   20
#   define __SIZEOF_PTHREAD_BARRIERATTR_T   4
#endif
#ifndef __SIZEOF_PTHREAD_SPINLOCK_T
#   define __SIZEOF_PTHREAD_SPINLOCK_T   32
#endif
#ifndef SIZEOF_PTHREAD_SPINLOCK_T
#   define SIZEOF_PTHREAD_SPINLOCK_T   32
#endif
// DIV_T DATATYPE SIZES
#define SIZEOF_DIV_T   SIZEOF_INT
#define SIZEOF_LDIV_T   SIZEOF_LONG
#define SIZEOF_LLDIV_T   SIZEOF_LONG_LONG
// MISCELLANEOUS DATATYPE SIZES
#define SIZEOF_FD_MASK   SIZEOF_LONG
#define BITS_PER_FD_MASK   BITS_PER_LONG
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


// IEEE DOUBLE ENDIAN

#if (defined(ARM) || defined(ARM64))
#   ifdef ARM_BIG_ENDIAN
#      define IEEE_DOUBLE_MIXED_ENDIAN   0
#      define IEEE_DOUBLE_BIG_ENDIAN   1
#   elif defined(__VFP_FP__)
#      define IEEE_DOUBLE_MIXED_ENDIAN   0
#      define IEEE_DOUBLE_BIG_ENDIAN   0
#   else
#      define IEEE_DOUBLE_BIG_ENDIAN   0
#      define IEEE_DOUBLE_MIXED_ENDIAN   1
#   endif
#endif
#ifdef NIOS2
#   define IEEE_DOUBLE_BIG_ENDIAN   0
#endif


// MISCELLANEOUS PLATFORM INFO

#ifdef AARCH64  // _STRING_ARCH_unaligned
/** AArch64 implementations support efficient unaligned access */
#   define _STRING_ARCH_unaligned   1
#elif defined(M68K)
#   define _STRING_ARCH_unaligned   1
#elif (defined(X86) || defined(X86_64) || defined(I386))
#   define _STRING_ARCH_unaligned   1
#elif (defined(S390) || defined(S390X))
/** s390 processors can access unaligned multi-byte variables */
#   define _STRING_ARCH_unaligned   1
#else
/** Define to 1 if architecture can access unaligned multi-byte variables */
#   define _STRING_ARCH_unaligned   0
#endif  // _STRING_ARCH_unaligned
#define STRING_ARCH_unaligned   _STRING_ARCH_unaligned
#define string_arch_unaligned   _STRING_ARCH_unaligned


#ifndef smallint_type
#   define smallint_type   int
#endif
#ifndef smallint
#   define smallint   signed int
#endif
#ifndef smalluint
#   define smalluint   unsigned int
#endif
#if ((defined(X86_64) || defined(X86)) && (!defined(__SYSCALL_WORDSIZE)))
/** Both x86-64 and x32 use the 64-bit syscall interface */
#   define __SYSCALL_WORDSIZE   (64)
#   define SYSCALL_WORDSIZE   (64)
#endif
#ifndef HAVE_LONG_LONG
#   define HAVE_LONG_LONG   (1)
#endif
#ifndef __FD_ZERO_STOS
#   if WORDSIZE_IS_64
#      define __FD_ZERO_STOS   "stosq"
#   else
#      define __FD_ZERO_STOS   "stosl"
#   endif
#endif  // __FD_ZERO_STOS
#if ((!defined(__NO_LONG_DOUBLE_MATH)) && (!defined(__LONG_DOUBLE_MATH_OPTIONAL)))
#   if IS_WORDSIZE_32  // __LONG_DOUBLE_128__
#      define __LONG_DOUBLE_MATH_OPTIONAL   (0x1)
#      if (__LONG_DOUBLE_128__ != 0x1)
#         define __NO_LONG_DOUBLE_MATH   (0x1)
#      endif
#   endif  // __LONG_DOUBLE_128__
#endif


#endif  // STACK INFO & WORDSIZE


// ENDIAN (<endian.h>)

#if (!(defined(_ENDIAN_H) || defined(ENDIAN_H) || defined(_ENDIAN_H_)))
#define _ENDIAN_H   (1)
#define ENDIAN_H   (1)
#define _ENDIAN_H_   (1)
#define _BYTE_ORDER_H   (1)
#define _BYTE_ORDER_H_   (1)
#define _I386__ENDIAN_H_   (1)
#define _BSD_MACHINE_ENDIAN_H_   (1)
#define _MACHINE_ENDIAN_H   (1)
#define _MACHINE_ENDIAN_H_   (1)
#define _SYS_ENDIAN_H   (1)
#define _SYS_ENDIAN_H_   (1)
#define _SYS__ENDIAN_H_   (1)
#define _KLIBC_ENDIAN_H   (1)
#define _NLIBC_ENDIAN_H   (1)
#define _LINUX_BYTEORDER_BIG_ENDIAN_H   (1)
#define _LINUX_BYTEORDER_LITTLE_ENDIAN_H   (1)
#define _OS_OSENDIANHELPER_H   (1)
#define _HAIKU_BUILD_COMPATIBILITY_FREEBSD_ENDIAN   (1)
#define _HAIKU_BUILD_COMPATIBILITY_DARWIN_ENDIAN   (1)
#define _HAIKU_BUILD_COMPATIBILITY_SUNOS_ENDIAN   (1)
#define _FBSD_COMPAT_MACHINE_ENDIAN_H   (1)
#define _FBSD_COMPAT_MACHINE_ENDIAN_H_   (1)
#define _FBSD_COMPAT_SYS_ENDIAN_H   (1)
#define _FBSD_COMPAT_SYS_ENDIAN_H_   (1)


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
/** LSB first: i386, vax */
#define __DARWIN_LITTLE_ENDIAN   __ORDER_LITTLE_ENDIAN__
/** MSB first: 68000, ibm, net */
#define __DARWIN_BIG_ENDIAN   __ORDER_BIG_ENDIAN__
/** LSB first in word, MSW first in long */
#define __DARWIN_PDP_ENDIAN   __ORDER_PDP_ENDIAN__
#define __BIG_ENDIAN   __ORDER_BIG_ENDIAN__
#define _BIG_ENDIAN   __ORDER_BIG_ENDIAN__
#define __LITTLE_ENDIAN   __ORDER_LITTLE_ENDIAN__
#define _LITTLE_ENDIAN   __ORDER_LITTLE_ENDIAN__
/** PDP-endian (word-swapped/middle-endian) */
#define __PDP_ENDIAN   __ORDER_PDP_ENDIAN__
/** PDP-endian (word-swapped/middle-endian) */
#define _PDP_ENDIAN   __ORDER_PDP_ENDIAN__
#define BIG_ENDIAN   __ORDER_BIG_ENDIAN__
#define __DARWIN_BIG_ENDIAN   __ORDER_BIG_ENDIAN__
#define DARWIN_BIG_ENDIAN   __ORDER_BIG_ENDIAN__
#define LITTLE_ENDIAN   __ORDER_LITTLE_ENDIAN__
/** PDP-endian (word-swapped/middle-endian/mixed-endian) */
#define PDP_ENDIAN   __ORDER_PDP_ENDIAN__

#if (defined(MIPS_BIG_ENDIAN) || defined(ARM_BIG_ENDIAN) || defined(POWERPC64_BIG_ENDIAN) || defined(MICROBLAZE_BIG_ENDIAN) || defined(__nios_big_endian__) || defined(__nios2_big_endian__) || defined(AVR) || defined(COLDFIRE) || defined(PARISC) || defined(SYSTEMZ) || defined(ZARCH))
#   ifndef __BYTE_ORDER__
#      define __BYTE_ORDER__   __ORDER_BIG_ENDIAN__
#   endif
#elif (defined(MIPS_LITTLE_ENDIAN) || defined(ARM_LITTLE_ENDIAN) || defined(POWERPC64_LITTLE_ENDIAN) || defined(MICROBLAZE_LITTLE_ENDIAN) || defined(__nios_little_endian__) || defined(__nios2_little_endian__) || defined(BLACKFIN) || defined(UNICORE) || defined(VAX))
#   ifndef __BYTE_ORDER__
#      define __BYTE_ORDER__   __ORDER_LITTLE_ENDIAN__
#   endif
#endif


#ifndef __BYTE_ORDER__
#   define __BYTE_ORDER__   __ORDER_LITTLE_ENDIAN__
#endif
#ifndef __BYTE_ORDER
#   define __BYTE_ORDER   __BYTE_ORDER__
#endif
#ifndef _BYTE_ORDER
#   define _BYTE_ORDER   __BYTE_ORDER__
#endif
#ifndef BYTE_ORDER
#   define BYTE_ORDER   __BYTE_ORDER__
#endif
#ifndef __DARWIN_BYTE_ORDER
#   define __DARWIN_BYTE_ORDER   __BYTE_ORDER__
#endif
#ifndef DARWIN_BYTE_ORDER
#   define DARWIN_BYTE_ORDER   __BYTE_ORDER__
#endif
#if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#   define __LONG_LONG_PAIR(HI, LO)   LO, HI
#   undef BIG_ENDI
#   define LITTLE_ENDI   (1)
#   define HIGH_HALF   (1)
#   define LOW_HALF   (0)
#   define IS_LITTLE_ENDIAN   (1)
#   define IS_BIG_ENDIAN   (0)
#   define IS_PDP_ENDIAN   (0)
#   define ENDIAN_LITTLE   (1)
#   define ENDIANLITTLE   (1)
#   define B_HOST_IS_LENDIAN   (1)
#   define B_HOST_IS_BENDIAN   (0)
#   define FSSH_B_HOST_IS_LENDIAN   (1)
#   define FSSH_B_HOST_IS_BENDIAN   (0)
#   ifndef _QUAD_HIGHWORD
#      define _QUAD_HIGHWORD   (1)
#   endif
#   ifndef _QUAD_LOWWORD
#      define _QUAD_LOWWORD   (0)
#   endif
#   ifndef __LITTLE_ENDIAN_BITFIELD
#      define __LITTLE_ENDIAN_BITFIELD   (1)
#   endif
#elif (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#   define __LONG_LONG_PAIR(HI, LO)   HI, LO
#   define BIG_ENDI   (1)
#   undef LITTLE_ENDI
#   define HIGH_HALF   (0)
#   define LOW_HALF   (1)
#   define IS_BIG_ENDIAN   (1)
#   define IS_LITTLE_ENDIAN   (0)
#   define IS_PDP_ENDIAN   (0)
#   define ENDIAN_BIG   (1)
#   define ENDIANBIG   (1)
#   define B_HOST_IS_LENDIAN   (0)
#   define B_HOST_IS_BENDIAN   (1)
#   define FSSH_B_HOST_IS_LENDIAN   (0)
#   define FSSH_B_HOST_IS_BENDIAN   (1)
#   ifndef _QUAD_HIGHWORD
#      define _QUAD_HIGHWORD   (0)
#   endif
#   ifndef _QUAD_LOWWORD
#      define _QUAD_LOWWORD   (1)
#   endif
#   ifndef __BIG_ENDIAN_BITFIELD
#      define __BIG_ENDIAN_BITFIELD   (1)
#   endif
#elif (__BYTE_ORDER__ == __ORDER_PDP_ENDIAN__)
#   error   "PDP byte-order is not supported! Only little and big endianness are supported."
#   undef BIG_ENDI
#   undef LITTLE_ENDI
#   define IS_PDP_ENDIAN   (1)
#   define IS_LITTLE_ENDIAN   (0)
#   define IS_BIG_ENDIAN   (0)
#   define ENDIAN_PDP   (1)
#   define ENDIANPDP   (1)
#   ifndef __PDP_ENDIAN_BITFIELD
#      define __PDP_ENDIAN_BITFIELD   (1)
#   endif
#else
#   error   "UNKNOWN BYTE-ORDER/ENDIANNESS! Only little and big endianness are supported."
#endif
#if (!defined(__HAIKU_BIG_ENDIAN) && !defined(__HAIKU_LITTLE_ENDIAN))
#   if IS_LITTLE_ENDIAN
#      define HAIKU_LITTLE_ENDIAN   (1)
#      define __HAIKU_LITTLE_ENDIAN   (1)
#   elif IS_BIG_ENDIAN
#      define HAIKU_BIG_ENDIAN   (1)
#      define __HAIKU_BIG_ENDIAN   (1)
#   endif
#endif
#if (!defined(BFS_LITTLE_ENDIAN_ONLY) && !defined(BFS_BIG_ENDIAN_ONLY))
#   define BFS_LITTLE_ENDIAN_ONLY   (1)
#endif


#if (defined(ALPHA) || defined(ARM64) || defined(ARM) || defined(ITANIUM) || defined(MICROBLAZE) || defined(MIPS) || defined(POWERPC) || defined(POWERPC64) || defined(SPARC64) || defined(SUPERH) || defined(SUPERH64))
#   define BI_ENDIAN   (1)
#endif
#ifdef BI_ENDIAN
#   define IS_BI_ENDIAN   (1)
#else
#   define IS_BI_ENDIAN   (0)
#endif

#ifndef NETWORK_BYTE_ORDER
#   define NETWORK_BYTE_ORDER   __ORDER_BIG_ENDIAN__
#endif
#ifndef __NETWORK_BYTE_ORDER__
#   define __NETWORK_BYTE_ORDER__   __ORDER_BIG_ENDIAN__
#endif

#if IS_LITTLE_ENDIAN
#   define OSHostByteOrder()   OSLittleEndian
#elif IS_BIG_ENDIAN
#   define OSHostByteOrder()   OSBigEndian
#else
#   define OSHostByteOrder()   OSUnknownByteOrder
#endif
#if IS_BIG_ENDIAN
#   define _ISbit(bit)   (0x1 << (bit))
#elif IS_LITTLE_ENDIAN
#   define _ISbit(bit)   (((bit) < 0x8) ? ((0x1 << (bit)) << 0x8) : ((0x1 << (bit)) >> 0x8))
#else
#   error   "Edit `_ISbit` for the target byteorder."
#endif
#define ISbit(bit)   _ISbit((bit))
#define isbit(bit)   _ISbit((bit))
#define __isbit(bit)   _ISbit((bit))
#define __isbit__(bit)   _ISbit((bit))
#if IS_LITTLE_ENDIAN
#   define PADDED(x, y)   x, y
#elif IS_BIG_ENDIAN
#   define PADDED(x, y)   y, x
#else
#   error   "Edit `PADDED` for the target byteorder."
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
#   define IS_FLOAT_LITTLE_ENDIAN   (1)
#   define IS_FLOAT_BIG_ENDIAN   (0)
#elif (FLOAT_WORD_ORDER == __ORDER_BIG_ENDIAN__)
#   define IS_FLOAT_LITTLE_ENDIAN   (0)
#   define IS_FLOAT_BIG_ENDIAN   (1)
#endif


/** Swap directions */
typedef enum swap_action {
	B_SWAP_HOST_TO_LENDIAN,
	B_SWAP_HOST_TO_BENDIAN,
	B_SWAP_LENDIAN_TO_HOST,
	B_SWAP_BENDIAN_TO_HOST,
	B_SWAP_ALWAYS
} swap_action;


/** Swap directions */
typedef enum fssh_swap_action {
	FSSH_B_SWAP_HOST_TO_LENDIAN,
	FSSH_B_SWAP_HOST_TO_BENDIAN,
	FSSH_B_SWAP_LENDIAN_TO_HOST,
	FSSH_B_SWAP_BENDIAN_TO_HOST,
	FSSH_B_SWAP_ALWAYS
} fssh_swap_action;


/** Node Flavors */
typedef enum fssh_node_flavor {
	FSSH_B_FILE_NODE = 1,
	FSSH_B_SYMLINK_NODE = 2,
	FSSH_B_DIRECTORY_NODE = 4,
	FSSH_B_ANY_NODE = 7
} fssh_node_flavor_t;


#endif  // ENDIAN_H


// ARM

#if ((!(defined(_ARM_CDEFS_H) || defined(_ARM_CDEFS_H_))) && (defined(ARM) || defined(ARM64)))
#define _ARM_CDEFS_H   (1)
#define _ARM_CDEFS_H_   (1)
#define _ARM_IPCCONST_H_   (1)
#define _ARM_CONST_H   (1)
#define _EVBARM_TYPES_H_   (1)


#ifdef COMPILER_CLANG  // Ignore warnings that originate from the cross-compiler's system headers
#   pragma clang diagnostic ignored "-Wcast-align"
#   pragma clang diagnostic ignored "-Wcast-qual"
#   pragma clang diagnostic ignored "-Wconversion"
#   pragma clang diagnostic ignored "-Wformat-nonliteral"
#   pragma clang diagnostic ignored "-Wpadded"
#   pragma clang diagnostic ignored "-Wsign-conversion"
#   pragma clang diagnostic ignored "-Wswitch-default"
#   pragma clang diagnostic ignored "-Wtype-limits"
#   pragma clang diagnostic ignored "-Werror=unused-function"
#   pragma clang diagnostic ignored "-Wunused-function"
#elif defined(COMPILER_GNUC)
#   pragma GCC diagnostic ignored "-Wcast-align"
#   pragma GCC diagnostic ignored "-Wcast-qual"
#   pragma GCC diagnostic ignored "-Wconversion"
#   pragma GCC diagnostic ignored "-Wformat-nonliteral"
#   pragma GCC diagnostic ignored "-Wpadded"
#   pragma GCC diagnostic ignored "-Wsign-conversion"
#   pragma GCC diagnostic ignored "-Wswitch-default"
#   pragma GCC diagnostic ignored "-Wtype-limits"
#   pragma GCC diagnostic ignored "-Werror=unused-function"
#   pragma GCC diagnostic ignored "-Wunused-function"
#endif  // https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html

#if (defined(_ARM_ARCH_T2) || (!defined(ARM_THUMB) && (defined(_ARM_ARCH_6) || defined(__ARM_ARCH_5TE__) || defined(__ARM_ARCH_5TEJ__))))
#   define _ARM_ARCH_DWORD_OK   (1)
#endif
#ifdef __ARM_PCS_AAPCS64
#   define __ALIGNBYTES   (15)
#elif defined(__ARM_EABI__)
#   define __ALIGNBYTES   (BYTES_PER_LONG_LONG - 1)
#else
#   define __ALIGNBYTES   (31)
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
#define PRIxPADDR   "lx"
#define PRIxPSIZE   "lx"
#define PRIuPSIZE   "lu"
#define PRIxVADDR   "lx"
#define PRIxVSIZE   "lx"
#define PRIuVSIZE   "lu"
#define PRIxREGISTER   "x"

#define DEFAULT_HZ   (1000)
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


// X86, X86-64, AND I386 MACROS

#if (defined(X86_64) || defined(X86) || defined(INTEL))
#define _I386_IPCCONST_H_   (1)
#define _I386_CONST_H   (1)


// Processor Classes; CPU identification code depends on this starting at 0, and having an increment of one
#define CPUCLASS_386   0
#define CPUCLASS_486   1
#define CPUCLASS_586   2
#define CPUCLASS_686   3
// Kinds of Processors; Only the first 7 are used, as they are processors that might not have a cpuid instruction
/** Intel 80386SX */
#define CPU_386SX   0
/** Intel 80386DX */
#define CPU_386   1
/** Intel 80486SX */
#define CPU_486SX   2
/** Intel 80486DX */
#define CPU_486   3
/** Cyrix 486DLC */
#define CPU_486DLC   4
/** Cyrix/IBM 6x86 */
#define CPU_6x86   5
/** NexGen 586 */
#define CPU_NX586   6
/** Intel Pentium */
#define CPU_586   7
/** AMD Am486 and Am5x86 */
#define CPU_AM586   8
/** AMD K5 */
#define CPU_K5   9
/** NexGen 686 aka AMD K6 */
#define CPU_K6   10
/** Intel Pentium Pro */
#define CPU_686   11
/** IDT WinChip C6 */
#define CPU_C6   12
/** Transmeta TMx86 */
#define CPU_TMX86   13
// CPU vendors
#define CPUVENDOR_UNKNOWN   0
#define CPUVENDOR_INTEL   1
#define CPUVENDOR_CYRIX   2
#define CPUVENDOR_NEXGEN   3
#define CPUVENDOR_AMD   4
#define CPUVENDOR_IDT   5
#define CPUVENDOR_TRANSMETA   6
#define CPUVENDOR_VORTEX86   7
// Values returned by cpuid
/** Lowest that cpuid can return (486) */
#define CPU_MINFAMILY   4
/** Highest consecutive # we know (fake P4) */
#define CPU_MAXFAMILY   7
/** Family number for Pentium 4 */
#define CPU_FAMILY_P4   15
/** Clock freq (software settable on IBM-PC) */
#define DEFAULT_HZ   60


// I386 MACROS
#if ((!(defined(_I386_CDEFS_H) || defined(_I386_CDEFS_H_))) && defined(I386))
#define _I386_CDEFS_H_   (1)


#define __ALIGNBYTES   (BYTES_PER_INT - 1)
typedef struct label_t { int val[6]; }   label_t;

#ifdef _KERNEL
#   ifdef PAE
typedef unsigned long long   paddr_t;
typedef unsigned long long   psize_t;
#      define PRIxPADDR   "llx"
#      define PRIxPSIZE   "llx"
#      define PRIuPSIZE   "llu"
#   else
typedef unsigned long   paddr_t;
typedef unsigned long   psize_t;
#      define PRIxPADDR   "lx"
#      define PRIxPSIZE   "lx"
#      define PRIuPSIZE   "lu"
#   endif  // PAE
#else
typedef unsigned long long   paddr_t;
typedef unsigned long long   psize_t;
#   define PRIxPADDR   "llx"
#   define PRIxPSIZE   "llx"
#   define PRIuPSIZE   "llu"
#endif  // _KERNEL
typedef unsigned long   vaddr_t;
typedef unsigned long   vsize_t;
typedef int   pmc_evid_t;
typedef unsigned long long   pmc_ctr_t;
typedef unsigned char   __cpu_simple_lock_nv_t;
typedef volatile __cpu_simple_lock_nv_t   __cpu_simple_lock_t;
#define PRIxVADDR   "lx"
#define PRIxVSIZE   "lx"
#define PRIuVSIZE   "lu"
#define PRIxREGISTER   "x"

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
#   if ((!defined(XEN)) && (!defined(NO_PCI_MSI_MSIX)))
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
#if ((!(defined(_X86_BUSDEFS_H_) || defined(_X86_BUSDEFS_H) || defined(_X86_BUS_PRIVATE_H_))) && defined(X86))
#define _X86_BUSDEFS_H   (1)  // <x86/busdefs.h>
#define _X86_BUSDEFS_H_   (1)
#define _X86_BUS_PRIVATE_H   (1)
#define _X86_BUS_PRIVATE_H_   (1)
#define _X86_BUS_H   (1)
#define _X86_BUS_H_   (1)

// Values for the x86 bus space tag, not to be used directly by MI code
/** Space is i/o space */
#define X86_BUS_SPACE_IO   (0)
/** Space is mem space */
#define X86_BUS_SPACE_MEM   (1)
#define __BUS_SPACE_HAS_STREAM_METHODS   (1)
#ifdef BUS_SPACE_DEBUG
#   define BUS_SPACE_ALIGNED_ADDRESS(p, t)   ((((unsigned long)(p)) & (sizeof(t) - 1)) == 0)
#   define BUS_SPACE_ALIGNED_POINTER(p, t)   BUS_SPACE_ALIGNED_ADDRESS(p, t)
#else
#   define BUS_SPACE_ALIGNED_POINTER(p, t)   ALIGNED_POINTER(p, t)
#endif
#define BUS_DMA_TAG_VALID(__t)    ((__t) != NULL)


#endif  // X86_BUSDEFS_H


#if IS_WORDSIZE_64
#   define R15   0
#   define R14   1
#   define R13   2
#   define R12   3
#   define RBP   4
#   define RBX   5
#   define R11   6
#   define R10   7
#   define R9   8
#   define R8   9
#   define RAX   10
#   define RCX   11
#   define RDX   12
#   define RSI   13
#   define RDI   14
#   define ORIG_RAX   15
#   define RIP   16
#   define CS   17
#   define EFLAGS   18
#   define RSP   19
#   define SS   20
#   define FS_BASE   21
#   define GS_BASE   22
#   define DS   23
#   define ES   24
#   define FS   25
#   define GS   26
#else
#   define EBX   0
#   define ECX   1
#   define EDX   2
#   define ESI   3
#   define EDI   4
#   define EBP   5
#   define EAX   6
#   define DS   7
#   define ES   8
#   define FS   9
#   define GS   10
#   define ORIG_EAX   11
#   define EIP   12
#   define CS   13
#   define EFL   14
#   define UESP   15
#   define SS   16
#endif
#define rax   REG(rax)
#define rbx   REG(rbx)
#define rcx   REG(rcx)
#define rdx   REG(rdx)
#define rsi   REG(rsi)
#define rdi   REG(rdi)
#define rbp   REG(rbp)
#define rsp   REG(rsp)
#define r8    REG(r8)
#define r9    REG(r9)
#define r10   REG(r10)
#define r11   REG(r11)
#define r12   REG(r12)
#define r13   REG(r13)
#define r14   REG(r14)
#define r15   REG(r15)
#define eax   REG(eax)
#define ebx   REG(ebx)
#define ecx   REG(ecx)
#define edx   REG(edx)
#define esi   REG(esi)
#define edi   REG(edi)
#define ebp   REG(ebp)
#define esp   REG(esp)
#define st0   REG(st)
#define st1   REG(st(1))
#define st2   REG(st(2))
#define st3   REG(st(3))
#define st4   REG(st(4))
#define st5   REG(st(5))
#define st6   REG(st(6))
#define st7   REG(st(7))
#define ax   REG(ax)
#define bx   REG(bx)
#define cx   REG(cx)
#define dx   REG(dx)
#define ah   REG(ah)
#define bh   REG(bh)
#define ch   REG(ch)
#define dh   REG(dh)
#define al   REG(al)
#define bl   REG(bl)
#define cl   REG(cl)
#define dl   REG(dl)
#define sil   REG(sil)
#define mm1   REG(mm1)
#define mm2   REG(mm2)
#define mm3   REG(mm3)
#define mm4   REG(mm4)
#define mm5   REG(mm5)
#define mm6   REG(mm6)
#define mm7   REG(mm7)
#define xmm0   REG(xmm0)
#define xmm1   REG(xmm1)
#define xmm2   REG(xmm2)
#define xmm3   REG(xmm3)
#define xmm4   REG(xmm4)
#define xmm5   REG(xmm5)
#define xmm6   REG(xmm6)
#define xmm7   REG(xmm7)
#define cr0   REG(cr0)
#define cr1   REG(cr1)
#define cr2   REG(cr2)
#define cr3   REG(cr3)
#define cr4   REG(cr4)
#ifdef _I386MACH_NEED_SOTYPE_FUNCTION
#   define SOTYPE_FUNCTION(sym)   .type SYM(sym),@function
#else
#   define SOTYPE_FUNCTION(sym)
#endif
#ifndef _I386MACH_DISABLE_HW_INTERRUPTS
#   define __CLI
#   define __STI
#else
#   define __CLI   cli
#   define __STI   sti
#endif


#endif  // X86, X86-64, AND I386 MACROS


// MIPS MACROS

#if ((!defined(_MIPS_CDEFS_H_)) && (defined(MIPS) || defined(MIPS64)))
#define _MIPS_CDEFS_H_   (1)


#if (!(defined(_SGIDEFS_H) || defined(_SGIDEFS_H_)))  // <sgidefs.h>
#define _SGIDEFS_H   (1)
#define _SGIDEFS_H_   (1)


// Definitions for the ISA level
#define _MIPS_ISA_MIPS1   (1)
#define _MIPS_ISA_MIPS2   (2)
#define _MIPS_ISA_MIPS3   (3)
#define _MIPS_ISA_MIPS4   (4)
#define _MIPS_ISA_MIPS5   (5)
#define _MIPS_ISA_MIPS32   (6)
#define _MIPS_ISA_MIPS64   (7)
// Subprogram calling convention
#ifndef _ABIO32
#   define _ABIO32   (1)
#endif
#define _MIPS_SIM_ABI32   (_ABIO32)
#ifndef _ABIN32
#   define _ABIN32   (2)
#endif
#define _MIPS_SIM_NABI32   (_ABIN32)
#ifndef _ABI64
#   define _ABI64   (3)
#endif
#define _MIPS_SIM_ABI64   (_ABI64)
#ifndef _ABIO64
#   define _ABIO64   (4)
#endif


#endif  // SGIDEFS_H


// Machine Registers
#define EF_R0   6
#define EF_R1   7
#define EF_R2   8
#define EF_R3   9
#define EF_R4   10
#define EF_R5   11
#define EF_R6   12
#define EF_R7   13
#define EF_R8   14
#define EF_R9   15
#define EF_R10   16
#define EF_R11   17
#define EF_R12   18
#define EF_R13   19
#define EF_R14   20
#define EF_R15   21
#define EF_R16   22
#define EF_R17   23
#define EF_R18   24
#define EF_R19   25
#define EF_R20   26
#define EF_R21   27
#define EF_R22   28
#define EF_R23   29
#define EF_R24   30
#define EF_R25   31
#define EF_R26   32
#define EF_R27   33
#define EF_R28   34
#define EF_R29   35
#define EF_R30   36
#define EF_R31   37
#define EF_LO   38
#define EF_HI   39
#define EF_CP0_EPC   40
#define EF_CP0_BADVADDR   41
#define EF_CP0_STATUS   42
#define EF_CP0_CAUSE   43
#define EF_UNUSED0   44
#define EF_SIZE   180


#endif  // MIPS_CDEFS_H


// ANDROID MACROS

#ifdef OSANDROID


#ifndef ANDROID_API_LEVEL_H
#define ANDROID_API_LEVEL_H   (1)   // <api-level.h>


#ifndef __ANDROID_API__
/** Android API level */
#   define __ANDROID_API__   10
#endif


#endif  // ANDROID_API_LEVEL_H


#endif


// APPLE MACROS

#include "Availability.h"
#ifndef IOKIT_SERVER_VERSION
#   define IOKIT_SERVER_VERSION   (20150715)
#endif
#ifdef OSAPPLE


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


#endif


// LINUX MACROS

#if (defined(OSLINUX) && (!defined(_KERNEL_FEATURES_H)))  // FLAGS SIGNALLING KERNEL FEATURES
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


#ifdef X86_64  // AVAILABLE SYSCALLS


/** accept4 syscall */
#define __ASSUME_ACCEPT4_SYSCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x20621)
/** recvmmsg syscall */
#   define __ASSUME_RECVMMSG_SYSCALL   1
#endif
#if (__LINUX_KERNEL_VERSION >= 0x30000)
/** sendmmsg syscall */
#   define __ASSUME_SENDMMSG_SYSCALL   1
#endif
#if (__LINUX_KERNEL_VERSION >= 0x30100)
/** getcpu is a Linux syscall for x86-64 */
#   define __ASSUME_GETCPU_SYSCALL   1
#endif


#elif defined(I386)


#define __ASSUME_SOCKETCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x20621)
#   define __ASSUME_RECVMMSG_SYSCALL   1
#endif
#define __ASSUME_RECVMMSG_SYSCALL_WITH_SOCKETCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x30000)
#   define __ASSUME_SENDMMSG_SYSCALL   1
#endif
#define __ASSUME_SENDMMSG_SYSCALL_WITH_SOCKETCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x40300)
#   define __ASSUME_SOCKET_SYSCALL   1
#   define __ASSUME_SOCKETPAIR_SYSCALL   1
#   define __ASSUME_BIND_SYSCALL   1
#   define __ASSUME_CONNECT_SYSCALL   1
#   define __ASSUME_LISTEN_SYSCALL   1
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   define __ASSUME_ACCEPT4_FOR_ACCEPT_SYSCALL   1
#   define __ASSUME_GETSOCKOPT_SYSCALL   1
#   define __ASSUME_SETSOCKOPT_SYSCALL   1
#   define __ASSUME_GETSOCKNAME_SYSCALL   1
#   define __ASSUME_GETPEERNAME_SYSCALL   1
#   define __ASSUME_SENDTO_SYSCALL   1
#   define __ASSUME_SENDTO_FOR_SEND_SYSCALL   1
#   define __ASSUME_SENDMSG_SYSCALL   1
#   define __ASSUME_RECVFROM_SYSCALL   1
#   define __ASSUME_RECVFROM_FOR_RECV_SYSCALL   1
#   define __ASSUME_RECVMSG_SYSCALL   1
#   define __ASSUME_SHUTDOWN_SYSCALL   1
#endif


#elif defined(ARM64)


#define __ASSUME_ACCEPT4_SYSCALL   1
#define __ASSUME_RECVMMSG_SYSCALL   1
#define __ASSUME_SENDMMSG_SYSCALL   1


#elif defined(ARM)


#if (__LINUX_KERNEL_VERSION >= 0x20621)
#   define __ASSUME_RECVMMSG_SYSCALL   1
#endif
#if (__LINUX_KERNEL_VERSION >= 0x20624)
#   define __ASSUME_ACCEPT4_SYSCALL   1
#endif
#if (__LINUX_KERNEL_VERSION >= 0x30000)
#   define __ASSUME_SENDMMSG_SYSCALL   1
#endif
// The ARM kernel before 3.14.3 may or may not support futex_atomic_cmpxchg_inatomic, depending on kernel configuration
#if (__LINUX_KERNEL_VERSION < 0x30E03)
#   undef __ASSUME_FUTEX_LOCK_PI
#   undef __ASSUME_REQUEUE_PI
#   undef __ASSUME_SET_ROBUST_LIST
#endif


#elif defined(ALPHA)


#if (__LINUX_KERNEL_VERSION >= 0x30200)
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   define __ASSUME_SENDMMSG_SYSCALL   1
#endif
#undef __ASSUME_ST_INO_64_BIT
#undef __ASSUME_STATFS64
#define __ASSUME_STATFS64   0
#if (__LINUX_KERNEL_VERSION >= 0x20621)
#   define __ASSUME_RECVMMSG_SYSCALL   1
#elif (__LINUX_KERNEL_VERSION < 0x20621)
#   undef __ASSUME_FALLOCATE
#   undef __ASSUME_PREADV
#   undef __ASSUME_PWRITEV
#   undef __ASSUME_IN_NONBLOCK
#   undef __ASSUME_PIPE2
#   undef __ASSUME_EVENTFD2
#   undef __ASSUME_SIGNALFD4
#   undef __ASSUME_DUP3
#endif


#elif defined(HPPA)


#if (__LINUX_KERNEL_VERSION >= 0x20622)
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   define __ASSUME_RECVMMSG_SYSCALL   1
#endif
#if (__LINUX_KERNEL_VERSION >= 0x30100)
#   define __ASSUME_SENDMMSG_SYSCALL   1
#endif
#if (__LINUX_KERNEL_VERSION >= 0x30e00)
#   define __ASSUME_UTIMES   1
#endif
#if (__LINUX_KERNEL_VERSION < 0x20625)
#   undef __ASSUME_PRLIMIT64
#endif


#elif defined(ITANIUM)


#if (__LINUX_KERNEL_VERSION >= 0x20621)
#   define __ASSUME_RECVMMSG_SYSCALL   1
#endif
#if (__LINUX_KERNEL_VERSION >= 0x30000)
#   define __ASSUME_SENDMMSG_SYSCALL   1
#endif
#if (__LINUX_KERNEL_VERSION >= 0x30300)
#   define __ASSUME_ACCEPT4_SYSCALL   1
#endif


#elif defined(M68K)


#define __ASSUME_SOCKETCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x40300)
#   define __ASSUME_RECVMMSG_SYSCALL   1
#   define __ASSUME_SENDMMSG_SYSCALL   1
#   define __ASSUME_SOCKET_SYSCALL   1
#   define __ASSUME_SOCKETPAIR_SYSCALL   1
#   define __ASSUME_BIND_SYSCALL   1
#   define __ASSUME_CONNECT_SYSCALL   1
#   define __ASSUME_LISTEN_SYSCALL   1
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   define __ASSUME_ACCEPT4_FOR_ACCEPT_SYSCALL   1
#   define __ASSUME_GETSOCKOPT_SYSCALL   1
#   define __ASSUME_SETSOCKOPT_SYSCALL   1
#   define __ASSUME_GETSOCKNAME_SYSCALL   1
#   define __ASSUME_GETPEERNAME_SYSCALL   1
#   define __ASSUME_SENDTO_SYSCALL   1
#   define __ASSUME_SENDTO_FOR_SEND_SYSCALL   1
#   define __ASSUME_SENDMSG_SYSCALL   1
#   define __ASSUME_RECVFROM_SYSCALL   1
#   define __ASSUME_RECVFROM_FOR_RECV_SYSCALL  1
#   define __ASSUME_RECVMSG_SYSCALL   1
#   define __ASSUME_SHUTDOWN_SYSCALL   1
#endif
#if (__LINUX_KERNEL_VERSION < 0x30000)
#   undef __ASSUME_PSELECT
#   undef __ASSUME_PPOLL
#endif
#if (__LINUX_KERNEL_VERSION < 0x30a00)
#   undef __ASSUME_FUTEX_LOCK_PI
#   undef __ASSUME_REQUEUE_PI
#   undef __ASSUME_SET_ROBUST_LIST
#endif


#elif defined(MICROBLAZE)


#define __ASSUME_SOCKETCALL   1
#define __ASSUME_SOCKET_SYSCALL   1
#define __ASSUME_BIND_SYSCALL   1
#define __ASSUME_CONNECT_SYSCALL   1
#define __ASSUME_LISTEN_SYSCALL   1
#define __ASSUME_ACCEPT_SYSCALL   1
#define __ASSUME_GETSOCKNAME_SYSCALL   1
#define __ASSUME_GETPEERNAME_SYSCALL   1
#define __ASSUME_SOCKETPAIR_SYSCALL   1
#define __ASSUME_SEND_SYSCALL   1
#define __ASSUME_SENDTO_SYSCALL   1
#define __ASSUME_RECV_SYSCALL   1
#define __ASSUME_RECVFROM_SYSCALL   1
#define __ASSUME_SHUTDOWN_SYSCALL   1
#define __ASSUME_GETSOCKOPT_SYSCALL   1
#define __ASSUME_SETSOCKOPT_SYSCALL   1
#define __ASSUME_SENDMSG_SYSCALL   1
#define __ASSUME_RECVMSG_SYSCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x20621)
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   define __ASSUME_RECVMMSG_SYSCALL   1
#   define __ASSUME_FUTIMESAT   1
#elif (__LINUX_KERNEL_VERSION < 0x20621)
#   undef __ASSUME_FUTEX_LOCK_PI
#   undef __ASSUME_REQUEUE_PI
#   undef __ASSUME_SET_ROBUST_LIST
#endif
#define __ASSUME_RECVMMSG_SYSCALL_WITH_SOCKETCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x30300)
#   define __ASSUME_SENDMMSG_SYSCALL   1
#endif
#if (__LINUX_KERNEL_VERSION < 0x20625)
#   undef __ASSUME_PRLIMIT64
#endif
#if (__LINUX_KERNEL_VERSION < 0x30f00)
#   undef __ASSUME_PSELECT
#   undef __ASSUME_PREADV
#   undef __ASSUME_PWRITEV
#endif


#elif defined(MIPS)


#define __ASSUME_ACCEPT4_SYSCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x20621)
#   define __ASSUME_RECVMMSG_SYSCALL   1
#endif
#if (__LINUX_KERNEL_VERSION >= 0x30100)
#   define __ASSUME_SENDMMSG_SYSCALL   1
#endif
#if ((_MIPS_SIM == _ABIN32) && (__LINUX_KERNEL_VERSION < 0x20623))
#   undef __ASSUME_GETDENTS64_SYSCALL
#endif
// The MIPS kernel does not support futex_atomic_cmpxchg_inatomic if emulating LL/SC
#if ((__mips == 1) || defined(_MIPS_ARCH_R5900))
#   undef __ASSUME_FUTEX_LOCK_PI
#   undef __ASSUME_REQUEUE_PI
#   undef __ASSUME_SET_ROBUST_LIST
#endif


#elif defined(NIOS2)


#define __ASSUME_ACCEPT4_SYSCALL   1
#define __ASSUME_RECVMMSG_SYSCALL   1
#define __ASSUME_SENDMMSG_SYSCALL   1


#elif (defined(POWERPC) || defined(POWERPC64))


#define __ASSUME_SOCKETCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x20625)
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   define __ASSUME_RECVMMSG_SYSCALL   1
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
#endif
#if (__LINUX_KERNEL_VERSION >= 0x30000)
#   define __ASSUME_SENDMMSG_SYSCALL   1
#endif
#define __ASSUME_SENDMMSG_SYSCALL_WITH_SOCKETCALL   1


#elif (defined(S390) || defined(S390X))


#define __ASSUME_SOCKETCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x40300)
#   define __ASSUME_RECVMMSG_SYSCALL   1
#   define __ASSUME_SENDMMSG_SYSCALL   1
#   define __ASSUME_SOCKET_SYSCALL   1
#   define __ASSUME_SOCKETPAIR_SYSCALL   1
#   define __ASSUME_BIND_SYSCALL   1
#   define __ASSUME_CONNECT_SYSCALL   1
#   define __ASSUME_LISTEN_SYSCALL   1
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   define __ASSUME_ACCEPT4_FOR_ACCEPT_SYSCALL   1
#   define __ASSUME_GETSOCKOPT_SYSCALL   1
#   define __ASSUME_SETSOCKOPT_SYSCALL   1
#   define __ASSUME_GETSOCKNAME_SYSCALL   1
#   define __ASSUME_GETPEERNAME_SYSCALL   1
#   define __ASSUME_SENDTO_SYSCALL   1
#   define __ASSUME_SENDTO_FOR_SEND_SYSCALL   1
#   define __ASSUME_SENDMSG_SYSCALL   1
#   define __ASSUME_RECVFROM_SYSCALL   1
#   define __ASSUME_RECVFROM_FOR_RECV_SYSCALL   1
#   define __ASSUME_RECVMSG_SYSCALL   1
#   define __ASSUME_SHUTDOWN_SYSCALL   1
#endif


#elif defined(SPARC)


#define __ASSUME_SOCKETCALL   1
#define __ASSUME_ACCEPT4_SYSCALL   1
#define __ASSUME_ACCEPT4_SYSCALL_WITH_SOCKETCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x20621)
#   define __ASSUME_RECVMMSG_SYSCALL   1
#endif
#define __ASSUME_RECVMMSG_SYSCALL_WITH_SOCKETCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x30000)
#   define __ASSUME_SENDMMSG_SYSCALL   1
#endif
#define __ASSUME_SENDMMSG_SYSCALL_WITH_SOCKETCALL   1
// 32-bit SPARC kernels do not support futex_atomic_cmpxchg_inatomic
#if ((!defined(SPARC64)) && (!defined(ULTRA_SPARC)))
#   undef __ASSUME_FUTEX_LOCK_PI
#   undef __ASSUME_REQUEUE_PI
#   undef __ASSUME_SET_ROBUST_LIST
#endif


#elif defined(SUPERH)


#define __ASSUME_SOCKETCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x20625)
#   define __ASSUME_SOCKET_SYSCALL   1
#   define __ASSUME_BIND_SYSCALL   1
#   define __ASSUME_CONNECT_SYSCALL   1
#   define __ASSUME_LISTEN_SYSCALL   1
#   define __ASSUME_ACCEPT_SYSCALL   1
#   define __ASSUME_GETSOCKNAME_SYSCALL   1
#   define __ASSUME_GETPEERNAME_SYSCALL   1
#   define __ASSUME_SOCKETPAIR_SYSCALL 1
#   define __ASSUME_SEND_SYSCALL   1
#   define __ASSUME_SENDTO_SYSCALL  1
#   define __ASSUME_RECV_SYSCALL   1
#   define __ASSUME_RECVFROM_SYSCALL   1
#   define __ASSUME_SHUTDOWN_SYSCALL   1
#   define __ASSUME_GETSOCKOPT_SYSCALL   1
#   define __ASSUME_SETSOCKOPT_SYSCALL   1
#   define __ASSUME_SENDMSG_SYSCALL   1
#   define __ASSUME_RECVMSG_SYSCALL   1
#   define __ASSUME_ACCEPT4_SYSCALL   1
#   define __ASSUME_RECVMMSG_SYSCALL   1
#endif
#if (__LINUX_KERNEL_VERSION >= 0x30000)
#   define __ASSUME_SENDMMSG_SYSCALL   1
#endif
#define __ASSUME_SENDMMSG_SYSCALL_WITH_SOCKETCALL   1
#undef __ASSUME_ST_INO_64_BIT
#if (__LINUX_KERNEL_VERSION < 0x20625)
#   undef __ASSUME_PRLIMIT64
#endif


#elif defined(TILE)


#define __ASSUME_ACCEPT4_SYSCALL   1
#define __ASSUME_RECVMMSG_SYSCALL   1
#if (__LINUX_KERNEL_VERSION >= 0x30000)
#   define __ASSUME_SENDMMSG_SYSCALL   1
#endif
#define __ASSUME_ALIGNED_REGISTER_PAIRS   1


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

#ifndef _WIN32_WINNT
#   define _WIN32_WINNT   0x0400
#endif
#ifndef MP_WBITS
#   define MP_WBITS   (64U)
#endif
#if (defined(__WINESRC__) && (!defined(__ROS_LONG64__)) && (!defined(AMD64)))
#   define __ROS_LONG64__   (1)
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
#ifdef OSWINDOWS  // Path separators
#   define CHAR_PATH_SEPARATOR   '\\'
#   define WCHAR_PATH_SEPARATOR   L'\\'
#   define STRING_PATH_SEPARATOR   "\\"
#   define WSTRING_PATH_SEPARATOR   L"\\"
#else
#   define CHAR_PATH_SEPARATOR   '/'
#   define WCHAR_PATH_SEPARATOR   L'/'
#   define STRING_PATH_SEPARATOR   "/"
#   define WSTRING_PATH_SEPARATOR   L"/"
#endif  // Path separators
#if ((!defined(_WINDOWS_)) && defined(OSWINDOWS))
#define _WINDOWS_   (1)
#define _INC_WINDOWS   (1)
#define _WINDOWS_H   (1)
#define _WINDOWS_H_   (1)


#ifdef __OBJC__
#   pragma push_macro("interface")
#   undef interface
#   define interface   struct
#endif


#include <_mingw.h>
#include <sdkddkver.h>


#if (defined(RC_INVOKED) && (!defined(NOWINRES)))

#include <winresrc.h>

#else

#ifdef RC_INVOKED
#   define NOATOM
#   define NOGDI
#   define NOGDICAPMASKS
#   define NOMETAFILE
#   define NOMINMAX
#   define NOMSG
#   define NOOPENFILE
#   define NORASTEROPS
#   define NOSCROLL
#   define NOSOUND
#   define NOSYSMETRICS
#   define NOTEXTMETRIC
#   define NOWH
#   define NOCOMM
#   define NOKANJI
#   define NOCRYPT
#   define NOMCX
#endif
#ifndef RC_INVOKED
#   include <excpt.h>
#endif
#include <windef.h>
#include <winbase.h>
#include <wingdi.h>
#include <winuser.h>
#include <winnls.h>
#include <wincon.h>
#include <winver.h>
#include <winreg.h>
#include <winnetwk.h>
#include <virtdisk.h>
#ifndef WIN32_LEAN_AND_MEAN
#   include <cderr.h>
#   include <dde.h>
#   include <ddeml.h>
#   include <dlgs.h>
#   include <lzexpand.h>
#   include <mmsystem.h>
#   include <nb30.h>
#   include <rpc.h>
#   include <shellapi.h>
#   include <winperf.h>
#   if (defined(__USE_W32_SOCKETS) || !defined(OSCYGWIN))
#      include <winsock.h>
#   endif
#   ifndef NOCRYPT
#      include <wincrypt.h>
#      include <winefs.h>
#      include <winscard.h>
#   endif
#   ifndef NOUSER
#      ifndef NOGDI
#         include <winspool.h>
#         ifdef INC_OLE1
#            include <ole.h>
#         else
#            include <ole2.h>
#         endif
#         include <commdlg.h>
#      endif
#   endif
#endif
#ifndef OSCYGWIN
#   include <stralign.h>
#endif
#ifdef INC_OLE2
#   include <ole2.h>
#endif
#ifndef NOSERVICE
#   include <winsvc.h>
#endif
#ifndef NOMCX
#   include <mcx.h>
#endif
#ifndef NOIME
#   include <imm.h>
#endif
#endif  // (defined(RC_INVOKED) && (!defined(NOWINRES)))


#ifdef __OBJC__
#   pragma pop_macro("interface")
#endif


#endif  // _WINDOWS_
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


#endif  // SPECIFICATIONS, FEATURES, & ARCHITECTURE MACROS


/* STANDARD MACROS */


#ifndef STANDARD_MACROS_SEEN
#define STANDARD_MACROS_SEEN   (1)
#define _LIBC_NAMESPACE_H_   (1)
#define _LIBC_SYMBOLS_H   (1)
#define _LIBC_SYMBOLS_H_   (1)
#define _ANSIDECL_H   (1)
#define _ANSIDECL_H_   (1)
#define CX_MACROS_H   (1)
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


#ifdef GNU_GCC  // Hard-code some optimizations
#   pragma GCC optimize (3)
#   pragma GCC optimize ("no-exceptions")
#   pragma GCC optimize ("unroll-loops")
#   pragma GCC optimize ("wrapv")
/** ivdep: Vectorize loops */
#   define __IVDEP__
#elif defined(CLANG)
#   pragma clang optimize on
#elif defined(__INTEL_COMPILER)
#   pragma intel optimization_level 3
#endif  // Hard-code some optimizations


// COMPILER VERSION MACROS

#if (defined(__CUDACC_VER__) && (!defined(__NVCC_PREREQ)))  // __NVCC_PREREQ
/** Test if the NVCC compiler matches the specified version number */
#   define __NVCC_PREREQ(version)   ((__CUDACC_VER__) >= version)
#else
#   define __NVCC_PREREQ(major, minor)   (0x0)
#endif  // __NVCC_PREREQ
#if ((!defined(GCC_VERSION)) && defined(__GNUC__) && defined(__GNUC_MINOR__))
#   define GCC_VERSION   ((__GNUC__ * 1000) + __GNUC_MINOR__)
#endif
#if (defined(__GNUC__) && defined(__GNUC_MINOR__))  // GNUC_PREREQ
/** Test if the GNU-GCC compiler matches the specified version number */
#   define __GNUC_PREREQ(major, minor)   (((__GNUC__ << 16) + __GNUC_MINOR__) >= (((major) << 16) + (minor)))
#else
#   define __GNUC_PREREQ(major, minor)   (0x0)
#endif  // GNUC_PREREQ
/** Test if the GNU-GCC compiler matches the specified version number */
#define __GNUC_PREREQ__(major, minor)   __GNUC_PREREQ((major), (minor))
/** Test if the GNU-GCC compiler matches the specified version number */
#define GNUC_PREREQ(major, minor)   __GNUC_PREREQ((major), (minor))
#if (defined(COMPILER_CLANG) && defined(__clang_major__))  // CLANG_PREREQ
/** Test if the Clang compiler matches the specified version number */
#   define __CLANG_PREREQ(major, minor)   (((__clang_major__ << 16) + __clang_minor__) >= ((major) << 16) + (minor))
#else
#   define __CLANG_PREREQ(major, minor)   (0x0)
#endif  // CLANG_PREREQ
/** Test if the Clang compiler matches the specified version number */
#define __CLANG_PREREQ__(major, minor)   __CLANG_PREREQ((major), (minor))
/** Test if the Clang compiler matches the specified version number */
#define CLANG_PREREQ(major, minor)   __CLANG_PREREQ((major), (minor))
#if (defined(__GNUC__) && defined(__GNUC_MINOR__))  // __MINGW_GNUC_PREREQ
/** Test if the MinGW compiler matches the specified version number */
#   define __MINGW_GNUC_PREREQ(major, minor)   (__GNUC__ > (major) || ((__GNUC__ == (major)) && (__GNUC_MINOR__ >= (minor))))
#else
/** Test if the MinGW compiler matches the specified version number */
#   define __MINGW_GNUC_PREREQ(major, minor)   (0x0)
#endif  // __MINGW_GNUC_PREREQ
#define __MINGW_MSC_PREREQ(major, minor)   __MINGW_GNUC_PREREQ((major), (minor))
#define __MINGW_PREREQ(major, minor)   __MINGW_GNUC_PREREQ((major), (minor))
#define MINGW_MSC_PREREQ(major, minor)   __MINGW_GNUC_PREREQ((major), (minor))
#define MINGW_PREREQ(major, minor)   __MINGW_GNUC_PREREQ((major), (minor))
#define __MINGW_MSC_PREREQ__(major, minor)   __MINGW_GNUC_PREREQ((major), (minor))
#define __MINGW_PREREQ__(major, minor)   __MINGW_GNUC_PREREQ((major), (minor))
#ifdef MICROSOFT_VISUAL
/** Test if the Microsoft compiler matches the specified version number */
#   define __MSC_VER_PREREQ(major, minor)   (_MSC_VER >= ((major * 100) + (minor * 10)))
#endif
#define MSC_VER_PREREQ(major, minor)   __MSC_VER_PREREQ((major), (minor))
#define MSC_PREREQ(major, minor)   __MSC_VER_PREREQ((major), (minor))
#ifdef __GNUC__
#   define AT_LEAST_GCC2   (__GNUC_PREREQ(2, 0))
#   define AT_LEAST_GCC25   (__GNUC_PREREQ(2, 5))
#   define AT_LEAST_GCC26   (__GNUC_PREREQ(2, 6))
#   define AT_LEAST_GCC27   (__GNUC_PREREQ(2, 7))
#   define AT_LEAST_GCC28   (__GNUC_PREREQ(2, 8))
#   define AT_LEAST_GCC29   (__GNUC_PREREQ(2, 9))
#   define AT_LEAST_GCC2_92   (__GNUC_PREREQ(2, 92))
#   define AT_LEAST_GCC2_93   (__GNUC_PREREQ(2, 93))
#   define AT_LEAST_GCC2_94   (__GNUC_PREREQ(2, 94))
#   define AT_LEAST_GCC2_95   (__GNUC_PREREQ(2, 95))
#   define AT_LEAST_GCC2_96   (__GNUC_PREREQ(2, 96))
#   define AT_LEAST_GCC2_97   (__GNUC_PREREQ(2, 97))
#   define AT_LEAST_GCC2_98   (__GNUC_PREREQ(2, 98))
#   define AT_LEAST_GCC2_99   (__GNUC_PREREQ(2, 99))
#   define AT_LEAST_GCC3   (__GNUC_PREREQ(3, 0))
#   define AT_LEAST_GCC31   (__GNUC_PREREQ(3, 1))
#   define AT_LEAST_GCC32   (__GNUC_PREREQ(3, 2))
#   define AT_LEAST_GCC33   (__GNUC_PREREQ(3, 3))
#   define AT_LEAST_GCC34   (__GNUC_PREREQ(3, 4))
#   define AT_LEAST_GCC35   (__GNUC_PREREQ(3, 5))
#   define AT_LEAST_GCC36   (__GNUC_PREREQ(3, 6))
#   define AT_LEAST_GCC37   (__GNUC_PREREQ(3, 7))
#   define AT_LEAST_GCC38   (__GNUC_PREREQ(3, 8))
#   define AT_LEAST_GCC39   (__GNUC_PREREQ(3, 9))
#   define AT_LEAST_GCC4   (__GNUC_PREREQ(4, 0))
#   define AT_LEAST_GCC41   (__GNUC_PREREQ(4, 1))
#   define AT_LEAST_GCC42   (__GNUC_PREREQ(4, 2))
#   define AT_LEAST_GCC43   (__GNUC_PREREQ(4, 3))
#   define AT_LEAST_GCC44   (__GNUC_PREREQ(4, 4))
#   define AT_LEAST_GCC45   (__GNUC_PREREQ(4, 5))
#   define AT_LEAST_GCC46   (__GNUC_PREREQ(4, 6))
#   define AT_LEAST_GCC47   (__GNUC_PREREQ(4, 7))
#   define AT_LEAST_GCC48   (__GNUC_PREREQ(4, 8))
#   define AT_LEAST_GCC49   (__GNUC_PREREQ(4, 9))
#   define AT_LEAST_GCC5   (__GNUC_PREREQ(5, 0))
#   define AT_LEAST_GCC51   (__GNUC_PREREQ(5, 1))
#   define AT_LEAST_GCC52   (__GNUC_PREREQ(5, 2))
#   define AT_LEAST_GCC53   (__GNUC_PREREQ(5, 3))
#   define AT_LEAST_GCC54   (__GNUC_PREREQ(5, 4))
#   define AT_LEAST_GCC55   (__GNUC_PREREQ(5, 5))
#   define AT_LEAST_GCC56   (__GNUC_PREREQ(5, 6))
#   define AT_LEAST_GCC57   (__GNUC_PREREQ(5, 7))
#   define AT_LEAST_GCC58   (__GNUC_PREREQ(5, 8))
#   define AT_LEAST_GCC59   (__GNUC_PREREQ(5, 9))
#   define AT_LEAST_GCC6   (__GNUC_PREREQ(6, 0))
#   define AT_LEAST_GCC61   (__GNUC_PREREQ(6, 1))
#   define AT_LEAST_GCC62   (__GNUC_PREREQ(6, 2))
#   define AT_LEAST_GCC63   (__GNUC_PREREQ(6, 3))
#   define AT_LEAST_GCC64   (__GNUC_PREREQ(6, 4))
#   define AT_LEAST_GCC65   (__GNUC_PREREQ(6, 5))
#   define AT_LEAST_GCC66   (__GNUC_PREREQ(6, 6))
#   define AT_LEAST_GCC67   (__GNUC_PREREQ(6, 7))
#   define AT_LEAST_GCC68   (__GNUC_PREREQ(6, 8))
#   define AT_LEAST_GCC69   (__GNUC_PREREQ(6, 9))
#   define AT_LEAST_GCC7   (__GNUC_PREREQ(7, 0))
#else
#   define AT_LEAST_GCC2   0
#   define AT_LEAST_GCC25   0
#   define AT_LEAST_GCC26   0
#   define AT_LEAST_GCC27   0
#   define AT_LEAST_GCC28   0
#   define AT_LEAST_GCC29   0
#   define AT_LEAST_GCC2_92   0
#   define AT_LEAST_GCC2_93   0
#   define AT_LEAST_GCC2_94   0
#   define AT_LEAST_GCC2_95   0
#   define AT_LEAST_GCC2_96   0
#   define AT_LEAST_GCC2_97   0
#   define AT_LEAST_GCC2_98   0
#   define AT_LEAST_GCC2_99   0
#   define AT_LEAST_GCC3   0
#   define AT_LEAST_GCC31   0
#   define AT_LEAST_GCC32   0
#   define AT_LEAST_GCC33   0
#   define AT_LEAST_GCC34   0
#   define AT_LEAST_GCC35   0
#   define AT_LEAST_GCC36   0
#   define AT_LEAST_GCC37   0
#   define AT_LEAST_GCC38   0
#   define AT_LEAST_GCC39   0
#   define AT_LEAST_GCC4   0
#   define AT_LEAST_GCC41   0
#   define AT_LEAST_GCC42   0
#   define AT_LEAST_GCC43   0
#   define AT_LEAST_GCC44   0
#   define AT_LEAST_GCC45   0
#   define AT_LEAST_GCC46   0
#   define AT_LEAST_GCC47   0
#   define AT_LEAST_GCC48   0
#   define AT_LEAST_GCC49   0
#   define AT_LEAST_GCC5   0
#   define AT_LEAST_GCC51   0
#   define AT_LEAST_GCC52   0
#   define AT_LEAST_GCC53   0
#   define AT_LEAST_GCC54   0
#   define AT_LEAST_GCC55   0
#   define AT_LEAST_GCC56   0
#   define AT_LEAST_GCC57   0
#   define AT_LEAST_GCC58   0
#   define AT_LEAST_GCC59   0
#   define AT_LEAST_GCC6   0
#   define AT_LEAST_GCC61   0
#   define AT_LEAST_GCC62   0
#   define AT_LEAST_GCC63   0
#   define AT_LEAST_GCC64   0
#   define AT_LEAST_GCC65   0
#   define AT_LEAST_GCC66   0
#   define AT_LEAST_GCC67   0
#   define AT_LEAST_GCC68   0
#   define AT_LEAST_GCC69   0
#   define AT_LEAST_GCC7   0
#endif
#define AT_LEAST_GCC20   AT_LEAST_GCC2
#define AT_LEAST_GCC30   AT_LEAST_GCC3
#define AT_LEAST_GCC40   AT_LEAST_GCC4
#define AT_LEAST_GCC50   AT_LEAST_GCC5
#define AT_LEAST_GCC60   AT_LEAST_GCC6
#define AT_LEAST_GCC70   AT_LEAST_GCC7
#if (!(AT_LEAST_GCC48))
#   error   "GNU-GCC 4.8 or newer is required"
#endif


// C++ MACROS

#undef  __P
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
#   if ((IS_CPLUSPLUS || defined(__PCC__)) && (!defined(__inline)))
#      define __inline   inline
#   elif ((!defined(__GNUC__)) && (!defined(__inline)))
#      define   __inline
#   endif
#   define _DEFUN(name, arglist, args)   name(args)
#   define _DEFUN_VOID(name)   name(_NOARGS)
#   define _CAST_VOID   (void)
#   ifndef _PARAMS
#      define _PARAMS(paramlist)    paramlist
#   endif
#else  // Not _HAVE_STDC
#   ifndef __GNUC__
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
#ifdef __AUDIT__
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
#define CX_BEGIN_DECLS   __BEGIN_DECLS
#define CX_END_DECLS   __END_DECLS
#define _START_STD_C   __BEGIN_DECLS
#define _BEGIN_STD_C   __BEGIN_DECLS
#define _END_STD_C   __END_DECLS
#define _C_LIB_DECL   __BEGIN_DECLS
#define _END_C_LIB_DECL   __END_DECLS
#define _EXTERN_C   __BEGIN_DECLS
#define _END_EXTERN_C   __END_DECLS
#define GSSAPI_CPP_START   __BEGIN_DECLS
#define GSSAPI_CPP_END   __END_DECLS
#if (IS_CPLUSPLUS && (!defined(EXPORTED_CONST)))
#   define EXPORTED_CONST   extern const
#elif (!defined(EXPORTED_CONST))
#   define EXPORTED_CONST   const
#endif
#if AT_LEAST_GCC40  // __BEGIN_PUBLIC_DECLS
#   define __BEGIN_PUBLIC_DECLS   _Pragma("GCC visibility push(default)") __BEGIN_EXTERN_C
#   define __END_PUBLIC_DECLS   __END_EXTERN_C _Pragma("GCC visibility pop")
#   define __BEGIN_HIDDEN_DECLS   _Pragma("GCC visibility push(hidden)") __BEGIN_EXTERN_C
#   define __END_HIDDEN_DECLS   __END_EXTERN_C _Pragma("GCC visibility pop")
#else
#   define __BEGIN_PUBLIC_DECLS   __BEGIN_EXTERN_C
#   define __END_PUBLIC_DECLS   __END_EXTERN_C
#   define __BEGIN_HIDDEN_DECLS   __BEGIN_EXTERN_C
#   define __END_HIDDEN_DECLS   __END_EXTERN_C
#endif
#ifndef __CASTV
#   define __CASTV(__dt, __st)   __CAST(__dt, __CAST(void *, __st))
#endif
#ifndef CASTV
#   define CASTV(__dt, __st)   __CAST(__dt, __CAST(void *, __st))
#endif
#ifndef __CASTCV
#   define __CASTCV(__dt, __st)   __CAST(__dt, __CAST(const void *, __st))
#endif
#ifndef CASTCV
#   define CASTCV(__dt, __st)   __CAST(__dt, __CAST(const void *, __st))
#endif
#ifndef __cast__
#   define __cast__(_to)
#endif
#ifndef __CAST_AWAY_QUALIFIER
/** This macro casts away the qualifier from the variable; Note: Use at your own risk, removing qualifiers can result in catastrophic run-time failures */
#   define __CAST_AWAY_QUALIFIER(variable, qualifier, type)   (type) (long)(variable)
#endif
#ifndef CAST_AWAY_QUALIFIER
/** This macro casts away the qualifier from the variable; Note: Use at your own risk, removing qualifiers can result in catastrophic run-time failures */
#   define CAST_AWAY_QUALIFIER(variable, qualifier, type)   (type) (long)(variable)
#endif


// INCLUDE MACROS

#ifndef _STLP_MAKE_HEADER
#   define _STLP_MAKE_HEADER(path, header)   <path/header>
#endif
#ifndef _STLP_NATIVE_HEADER
#   ifndef _STLP_NATIVE_INCLUDE_PATH
#      define _STLP_NATIVE_INCLUDE_PATH   ../include
#   endif
#   define _STLP_NATIVE_HEADER(header)   _STLP_MAKE_HEADER(_STLP_NATIVE_INCLUDE_PATH, header)
#endif
#ifndef _STLP_NATIVE_C_HEADER
#   ifndef _STLP_NATIVE_C_INCLUDE_PATH
#      define _STLP_NATIVE_C_INCLUDE_PATH   _STLP_NATIVE_INCLUDE_PATH
#   endif
#   define _STLP_NATIVE_C_HEADER(header)   _STLP_MAKE_HEADER(_STLP_NATIVE_C_INCLUDE_PATH, header)
#endif
#ifndef _STLP_NATIVE_CPP_C_HEADER
#   ifndef _STLP_NATIVE_CPP_C_INCLUDE_PATH
#      define _STLP_NATIVE_CPP_C_INCLUDE_PATH   _STLP_NATIVE_INCLUDE_PATH
#   endif
#   define _STLP_NATIVE_CPP_C_HEADER(header)   _STLP_MAKE_HEADER(_STLP_NATIVE_CPP_C_INCLUDE_PATH, header)
#endif
#ifndef  _STLP_NATIVE_CPP_RUNTIME_HEADER
#   ifndef _STLP_NATIVE_CPP_RUNTIME_INCLUDE_PATH
#      define _STLP_NATIVE_CPP_RUNTIME_INCLUDE_PATH   _STLP_NATIVE_INCLUDE_PATH
#   endif
#   define _STLP_NATIVE_CPP_RUNTIME_HEADER(header)   _STLP_MAKE_HEADER(_STLP_NATIVE_CPP_RUNTIME_INCLUDE_PATH, header)
#endif
#ifndef STLP_NATIVE_CPP_RUNTIME_HEADER
#   define STLP_NATIVE_CPP_RUNTIME_HEADER(header)   _STLP_NATIVE_CPP_RUNTIME_HEADER((header))
#endif
#define HAIKU_ARCH_HEADER(header)   <arch/__HAIKU_ARCH/header>
#define __HAIKU_ARCH_HEADER(header)   HAIKU_ARCH_HEADER((header))
#define __HAIKU_ARCH_HEADER(header)   HAIKU_ARCH_HEADER((header))
#define HAIKU_SUBDIR_ARCH_HEADER(subdir, header)   <subdir/arch/__HAIKU_ARCH/header>
#define __HAIKU_SUBDIR_ARCH_HEADER(subdir, header)   HAIKU_SUBDIR_ARCH_HEADER((subdir), (header))


// AUTO_TYPE

#ifndef auto_type
#   define auto_type   __auto_type
#endif
#ifndef auto_t
#   define auto_t   __auto_type
#endif
#ifndef __auto_type__
#   define __auto_type__   __auto_type
#endif


// POINTER MACROS

#ifndef PTR
#   define PTR   void*
#endif


// NULL, NIL, & VOID MACROS STATEMENTS

#ifndef STMT_VOID
/** Expands to a syntactically valid empty statement, explicitly voiding its argument */
#   define STMT_VOID(x)   while (0x0) { (void)(x); }
#endif
#ifdef __GNUC__  // STMT_BEGIN
/** STMT_BEGIN is used to wrap blocks inside macros so that the macro can be used as if it were a single C statement */
#   define STMT_BEGIN   (void)({
/** STMT_END is used to wrap blocks inside macros so that the macro can be used as if it were a single C statement */
#   define STMT_END   })
#elif (defined(OSSUN) || defined(OSSOLARIS))  // Solaris & other Sun-Systems
/** STMT_BEGIN is used to wrap blocks inside macros so that the macro can be used as if it were a single C statement */
#   define STMT_BEGIN   if (0x1) {
/** STMT_END is used to wrap blocks inside macros so that the macro can be used as if it were a single C statement */
#   define STMT_END   } else STMT_NIL
#else
/** STMT_BEGIN is used to wrap blocks inside macros so that the macro can be used as if it were a single C statement */
#   define STMT_BEGIN   do {
/** STMT_END is used to wrap blocks inside macros so that the macro can be used as if it were a single C statement */
#   define STMT_END   } while (0x0)
#endif  // STMT_BEGIN


// SIZEOF MACROS FUNCTIONS

#ifndef usizeof
/** The type of sizeof may be (unsigned) long on some systems; Use the following macro for getting datatype sizes when expecting sizeof to return an int */
#   define usizeof(datatype)   ((unsigned)sizeof(datatype))
#endif



// ARRAY SIZES

#define ARRAYLEN(arrayname)   ((sizeof((arrayname)) / sizeof(*(arrayname))))
#define ARRAYITEMSIZE(arrayname)   sizeof(*(arrayname))
/** Return the size of a statically-allocated array */
#define GETARRAYSIZE(arrayname)   sizeof((arrayname))
/** Return the number of items in a statically-allocated array */
#define __arraycount(arrayname)   (sizeof((arrayname)) / sizeof((arrayname)[0]))
#ifndef nitems
/** Return the number of items in a statically-allocated array */
#   define nitems(arrayname)   __arraycount((arrayname))
#endif
/** Return the number of items in a statically-allocated array */
#define nelem(x)   __arraycount((arrayname))
/** Number of elements in an array */
#define CX_N_ELEMENTS(array)   __arraycount((array))


// BYTE & BIT OPERATION MACROS

/** Find least significant bit that is set; For example, a return value of "8" indicates that the LSB is in the bit position that represents a decimal value of eight */
#define __LOWEST_SET_BIT(__mask)   ((((__mask) - 0x1) & (__mask)) ^ (__mask))
/** Find least significant bit that is set; For example, a return value of "8" indicates that the LSB is in the bit position that represents a decimal value of eight */
#define LOWEST_SET_BIT(__mask)   ((((__mask) - 0x1) & (__mask)) ^ (__mask))
#define __SHIFTOUT(x, __mask)   (((x) & (__mask)) / LOWEST_SET_BIT(__mask))
#define __SHIFTIN(x, __mask)   ((x) * LOWEST_SET_BIT(__mask))
#define __SHIFTOUT_MASK(__mask)   __SHIFTOUT((__mask), (__mask))
#define __bitop(x, i, o)   ((x)[(i) / NBBY] o (0x1 << (i) % NBBY))
#define bitop(x, i, o)   ((x)[(i) / NBBY] o (0x1 << (i) % NBBY))
#define setbit(x, i)   ((x)[(i) / NBBY] |= (0x1 << ((i) % NBBY)))
#define clrbit(x, i)   ((x)[(i) / NBBY] &= (~(0x1 << ((i) % NBBY))))
#define isset(x, i)   ((x)[(i) / NBBY] & (0x1 << ((i) % NBBY)))
#define isclr(x, i)   (((x)[(i) / NBBY] & (0x1 << ((i) % NBBY))) == 0x0)
#define BITS2BYTES(x)   (((x) / 0x8) + (((x) % 0x8) ? 0x1 : 0x0))
#define SET(t, f)   ((t) |= (f))
#define ISSET(t, f)   ((t) & (f))
#define CLR(t, f)   ((t) &= ~(f))


// LOGIC GATES, MAX, MIN, ETC. MACROS

#ifdef __GNUC__
#   define CONSTRAIN(amount, low, high)   __extension__ ({ auto_type _amount = (amount); auto_type _low = (low);  auto_type _high = (high); ((_amount) < (_low) ? (_low) : ((_amount) > (_high) ? (_high) : (_amount)))})
#   define _MAX_INT(x, y)   __extension__ ({ int _x = (x), _y = (y); _x > _y ? _x : _y; })
#   define _MIN_INT(x, y)   __extension__ ({ int _x = (x), _y = (y); _x > _y ? _y : _x; })
#   define MAX(x, y)   __extension__ ({ auto_type _x = (x); auto_type _y = (y); _x > _y ? _x : _y; })
#   define MIN(x, y)   __extension__ ({ auto_type _x = (x); auto_type _y = (y); _x > _y ? _y : _x; })
#   define SWAP(x, y)   do { typeof(x) __tmp = (x); (x) = (y); (y) = __tmp; } while (0x0)
#   define AND(x, y)  __extension__ ({ auto_type _x = (x); auto_type _y = (y); (_x & _y); })
#   define AND3(x, y, z)  __extension__ ({ auto_type _x = (x); auto_type _y = (y); auto_type _z = (z); ((_x & _y) & _z); })
#   define OR(x, y)   __extension__ ({ auto_type _x = (x); auto_type _y = (y); (_x | _y); })
#   define NOT(x)   __extension__ ({ auto_type _x = (x); (~_x); })
#   define COMP2(x)   __extension__ ({ auto_type _x = (x); (~_x) + 1; })
#   define NAND(x, y)   __extension__ ({ auto_type _x = (x); auto_type _y = (y); ~(_x & _y); })
#   define NOR(x, y)   __extension__ ({ auto_type _x = (x); auto_type _y = (y); ~(_x | _y); })
#   define XOR(x, y)   __extension__ ({ auto_type _x = (x); auto_type _y = (y); (_x ^ _y); })
#   define XNOR(x, y)   __extension__ ({ auto_type _x = (x); auto_type _y = (y); ~(_x ^ _y); })
#   define NXOR(x, y)   __extension__ ({ auto_type _x = (x); auto_type _y = (y); ~(_x ^ _y); })
#else
#   define CONSTRAIN(amount, low, high)   ((amount) < (low) ? (low) : ((amount) > (high) ? (high) : (amount)))
#   define _MAX_INT(x, y)   (((y) > (x)) ? (int)(y) : (int)(x))
#   define _MIN_INT(x, y)   (((y) < (x)) ? (int)(y) : (int)(x))
#   define MAX(x, y)   (((y) > (x)) ? (y) : (x))
#   define MIN(x, y)   (((y) < (x)) ? (y) : (x))
#   define SWAP(x, y)   ((y) = (x), (x) = (y))
#   define AND(x, y)   ((x) & (y))
#   define AND3(x, y, z)   (((x) & (y)) & (z))
#   define OR(x, y)   ((x) | (y))
#   define NOT(x)   (~(x))
#   define COMP2(x)   ((~(x)) + 1)
#   define NAND(x, y)   (~((x) & (y)))
#   define NOR(x, y)   (~((x) | (y)))
#   define XOR(x, y)   ((x) ^ (y))
#   define XNOR(x, y)   (~((x) ^ (y)))
#   define NXOR(x, y)   (~((x) ^ (y)))
#endif  // LOGIC GATES, MAX, MIN, ETC. MACROS
#ifndef TYPE_BIT
#   define TYPE_BIT(type)   (sizeof(type) * 8)
#endif
#ifndef TYPE_SIGNED
#   define TYPE_SIGNED(type)   (((type)(-1)) < (type)(0))
#endif
#define TWOS_COMPLEMENT(x)   ((~(x)) + 1)
#define ORSWAP(x, y)   ((x) |= (y), (x) |= (y), (x) |= (y))
#define XORSWAP(x, y)   ((x) ^= (y), (x) ^= (y), (x) ^= (y))
#define constrain(amount, low, high)   CONSTRAIN((amount), (low), (high))
#define CX_MAX(x, y)   MAX((x), (y))
#define CX_MIN(x, y)   MIN((x), (y))
#define fssh_min_c(a, b)   ((a) > (b) ? (b) : (a))
#define fssh_max_c(a, b)   ((a) > (b) ? (a) : (b))
#define MAXVAL(t, b)    ((t)(((t)1 << ((b) - 1 - TYPE_SIGNED(t))) - 1 + ((t)1 << ((b) - 1 - TYPE_SIGNED(t)))))
#define MINVAL(t, b)   ((t)(TYPE_SIGNED(t) ? (-(TWOS_COMPLEMENT(b) - MAXVAL(t, b))) : 0))
#ifndef INT_STRLEN_MAXIMUM
#   define INT_STRLEN_MAXIMUM(type)   (((TYPE_BIT(type) - TYPE_SIGNED(type)) * 302) / 1000 + 1 + TYPE_SIGNED(type))
#endif
#define mix(a, b, c)   do { \
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
#define MIX(a, b, c)   mix((a), (b), (c))
#define P2ROUNDUP(x, align)   (-(-(x) & -(align)))
#define P2PHASEUP(x, align, phase)   ((phase) - (((phase) - (x)) & -(align)))


// BASIC MATH OPERATION MACROS

/** Return the absolute value of an integral value */
#define abs(x)   (((x) >= 0) ? (x) : (-(x)))
/** Return the absolute value of an integral value */
#define ABS(x)   abs((x), (y))
/** Return the absolute value of an integral value */
#define CX_ABS(x, y)   abs((x), (y))
/** Return the absolute value of the difference between two integral values */
#define absdiff(x, y)   (((x) > (y)) ? (x - y) : (y - x))
#ifndef gnu_abs
#   define gnu_abs(n)    abs((n))
#endif
#ifndef CLAMP
/** Computes the value of the first specified argument clamped to a range defined by the second and third specified arguments */
#   define CLAMP(x, low, high)   (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))
#endif
#define CX_CLAMP(x, low, high)   MIN((x), (low), (high))
#ifndef howmany
/** Macros for counting */
#   define howmany(x, y)   (((x) + ((y) - 1)) / (y))
#endif
#define __DARWIN_howmany(x, y)   howmany((x), (y))
#define DARWIN_howmany(x, y)   howmany((x), (y))
#ifndef __ispowerof2
/** Test if the value is a power of two */
#   define __ispowerof2(x)   ((((x) - 1) & (x)) == 0)
#endif
/** Test if the value is a power of two */
#define powerof2(n)   (!(((n) - 1) & (n)))
#define ROUND_UP_NEXT_128(x)   (((x) + 0b10000000) & 0b10000000)
#define ROUND_DOWN_128(x)   ((x) & 0b10000000)
/** Macros to avoid undefined behaviour that can arise if the amount of a shift is exactly equal to the size of the shifted operand */
#define SAFE_LEFT_SHIFT(op, amt)   (((amt) < (8 * sizeof(op))) ? ((op) << (amt)) : 0)
/** Macros to avoid undefined behaviour that can arise if the amount of a shift is exactly equal to the size of the shifted operand */
#define SAFE_RIGHT_SHIFT(op, amt)   (((amt) < (8 * sizeof(op))) ? ((op) >> (amt)) : 0)


// FRAME MACROS

#if (defined(__GNUC__) && (!defined(FIRST_FRAME_POINTER)))
/** Returns the address of the stack frame (return address) of the current function or of one of its callers */
#   define FIRST_FRAME_POINTER   __builtin_frame_address(0)
#endif
#ifndef CURRENT_STACK_FRAME
/** Get some notion of the current stack */
#   define CURRENT_STACK_FRAME   __extension__ ({ do { char __csf; &__csf; } while (0x0) })
#endif


// MISCELLANEOUS SIMPLE MACROS

#if AT_LEAST_GCC30
/** String identifier for the current code position */
#   define CX_CODE_POS   __FILE__ ":" CX_STRINGIFY(__LINE__) ":" __PRETTY_FUNCTION__ "()"
#else
/** String identifier for the current code position */
#   define CX_CODE_POS   __FILE__ ":" CX_STRINGIFY(__LINE__)
#endif
#if AT_LEAST_GCC30
#   define CX_GNUC_FUNCTION   __FUNCTION__
#   define CX_GNUC_PRETTY_FUNCTION   __PRETTY_FUNCTION__
#else
#   define CX_GNUC_FUNCTION   ""
#   define CX_GNUC_PRETTY_FUNCTION   ""
#endif
#ifdef __GNUC__
/** Current function identifier */
#   define CX_FUNC_NAME   ((const char*)(__PRETTY_FUNCTION__))
#elif (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 19901L))
/** Current function identifier */
#   define CX_FUNC_NAME   ((const char*)(__func__))
#else
/** Current function identifier */
#   define CX_FUNC_NAME   ((const char*)("???"))
#endif
/** Outputs `typedef struct NAME_s NAME_t;` */
#define DECLARE_STRUCT_TYPE(name)   typedef struct name##_s name##_t
#define WHERESTR   "[file %s, line %d]: "
#define WHEREARG   __FILE__, __LINE__
#define CODE_LOCATION   __FILE__, __LINE__
#define __USE(x)   ((void)(x))
/** Get the address of the object */
#define ADDRESS_FUNCTION(x)   &(x)
/** Get the address of the object */
#define GET_ADDRESS(x)   &(x)
#define uninitialized_var(x)   x = *(&(x))
/** Get the address of a variable and pass it on as a `void*` */
#define vp_pack(var)   ((void*)&var)
/** Get a void pointer and dereferences it to the specified datatype */
#define vp_unpack(var, type)   (*((type*)var))
/** Long zero */
#define __zerolong()   ((long)0x0L)
/** Long zero */
#define zerolong()   __zerolong()
/** Unsigned long zero */
#define __zeroul()   ((unsigned long)0x0UL)
/** Unsigned long zero */
#define zeroul()   __zeroul()
/** Long long zero */
#define __zeroll()   ((long long)0x0LL)
/** Long long zero */
#define zeroll()   __zeroll()
/** Unsigned long long zero */
#define __zeroull()   ((unsigned long long)0x0ULL)
/** Unsigned long long zero */
#define zeroull()   __zeroull()
#ifndef NONNUL
/** Test if the character is non-null */
#   define NONNUL(c)   ((c) != '\0')
#endif
#ifdef argv
#   define getprogname()   argv[0]
#elif defined(PROGRAM_NAME)
#   define getprogname()   PROGRAM_NAME
#else
#   define getprogname()   "PyBooster\0"
#endif
#define progname   getprogname()
#define program_name   getprogname()
#define __progname_full   getprogname()
#define __progname   getprogname()
#define __negative_p(x)   ((x) < 0x0)
/** Calculate the minimum signed integer value that can be represented with the given data */
#define __type_min_s(t)   (((0x1ULL << ((sizeof(t) * NBBY) - 1))))
/** Calculate the minimum signed integer value that can be represented with the given data */
#define type_min_s(t)   (((0x1ULL << ((sizeof(t) * NBBY) - 1))))
/** Calculate the maximum signed integer value that can be represented with the given data */
#define __type_max_s(t)   (~((0x1ULL << ((sizeof(t) * NBBY) - 1))))
/** Calculate the maximum signed integer value that can be represented with the given data */
#define type_max_s(t)   (~((0x1ULL << ((sizeof(t) * NBBY) - 1))))
/** Calculate the minimum unsigned integer value that can be represented with the given data */
#define __type_min_u(t)   (0x0ULL)
/** Calculate the minimum unsigned integer value that can be represented with the given data */
#define type_min_u(t)   (0x0ULL)
/** Calculate the maximum unsigned integer value that can be represented with the given data */
#define __type_max_u(t)   (~(0x0ULL))
/** Calculate the maximum unsigned integer value that can be represented with the given data */
#define type_max_u(t)   (~(0x0ULL))
/** Test if the given data is signed */
#define __type_is_signed(t)   ((__type_min_s(t) + ((t) * 1)) < ((t) * 1))
/** Test if the given data is signed */
#define type_is_signed(t)   ((__type_min_s(t) + ((t) * 1)) < ((t) * 1))
/** Calculate the minimum integer value that can be represented with the given data */
#define __type_min(t)   (__type_is_signed(t) ? __type_min_s(t) : __type_min_u(t))
/** Calculate the minimum integer value that can be represented with the given data */
#define type_min(t)   (__type_is_signed(t) ? __type_min_s(t) : __type_min_u(t))
/** Calculate the maximum integer value that can be represented with the given data */
#define __type_max(t)   (__type_is_signed(t) ? __type_max_s(t) : __type_max_u(t))
/** Calculate the maximum integer value that can be represented with the given data */
#define type_max(t)   (__type_is_signed(t) ? __type_max_s(t) : __type_max_u(t))
#ifndef ASM_LINE_SEP
/** The symbol used to separate assembly commands */
#   define ASM_LINE_SEP   ;
#endif
#ifdef HAVE_SECTION_QUOTES
#   define __sec_comment   "\"\n\t#\""
#else
#   define __sec_comment   "\n\t#"
#endif
#ifndef __SYMBOL_PREFIX
#   define __SYMBOL_PREFIX
#endif
#ifndef C_SYMBOL_NAME
#   define C_SYMBOL_NAME(name)   name
#endif
#if (defined(__MINGW_USE_UNDERSCORE_PREFIX) && (__MINGW_USE_UNDERSCORE_PREFIX == 1))
#   define __MINGW_IMP_SYMBOL(sym)   _imp__##sym
#   define __MINGW_USYMBOL(sym)   _##sym
#   define __MINGW_LSYMBOL(sym)   sym
#else
#   define __MINGW_IMP_SYMBOL(sym)   __imp_##sym
#   define __MINGW_USYMBOL(sym)   sym
#   define __MINGW_LSYMBOL(sym)   _##sym
#endif
#define HIDDEN(x)   _libc_##x
/** Expands to the internal, hidden name of a cancellation wrapper */
#define CANCEL(x)   _libc_##x##_cancel
/** Expands to the internal, hidden name of a non-cancellation wrapper */
#define WRAP(x)   _libc_##x##_wrap
#define HIDDEN_STRING(x)   "_libc_" __STRING(x)
#define WRAP_STRING(x)   "_libc_" __STRING(x) "_wrap"
#ifndef MODULE_NAME
#   define MODULE_NAME   "libc"
#endif


// BASIC "DEFINED()" MACROS

/** Test if the symbol is not defined */
#define not_defined(x)   (!defined((x)))
/** Test if the symbol is not defined */
#define ndefined(x)   not_defined((x))
/** Test if both symbols are not defined; returns false (or 0) if one or both symbols are defined */
#define neither_defined(x, y)   (!(defined((x)) || defined((y))))
/** Test if one or both symbols are defined; returns false (or 0) if both symbols are not defined */
#define either_defined(x, y)   (defined((x)) || defined((y)))
/** Test if one or both symbols are defined; returns false (or 0) if both symbols are not defined */
#define any_defined(x, y)   either_defined((x), (y))


// LANGUAGE CONSTRUCTS

/** A forever-running for-loop */
#define loop_forever   for (;;)
/** A forever-running for-loop */
#define LOOP_FOREVER   for (;;)
/** A forever-running for-loop */
#define forever   for (;;)
/** A forever-running for-loop */
#define FOREVER   for (;;)


// ATTRIBUTE, BUILTIN, AND SPECIFIER MACROS

#ifndef __GNUC__  // Remove __extension__ in non-GNU compiler
#   define __extension__
#endif
#ifndef __GNU_EXTENSION
#   define __GNU_EXTENSION   __extension__
#endif
#ifndef CX_GNUC_EXTENSION
#   define CX_GNUC_EXTENSION   __extension__
#endif
#if ((defined(__GNUC__) || defined(__GNUG__)) && (!defined(__MINGW_EXTENSION)))  // __MINGW_EXTENSION
#   define __MINGW_EXTENSION   __extension__
#elif (!defined(__MINGW_EXTENSION))
#   define __MINGW_EXTENSION
#endif  // __MINGW_EXTENSION
#ifndef __C89_NAMELESS
#   define __C89_NAMELESS   __MINGW_EXTENSION
#   define __C89_NAMELESSSTRUCTNAME
#   define __C89_NAMELESSUNIONNAME
#endif  // __C89_NAMELESS
#ifdef MICROSOFT_VISUAL  // __attribute__ & __declspec
#   define __attribute__(x)   __declspec((x))
#   define _ATTRIBUTE(x)   __declspec(x)
#   define __declspec__(x)   __declspec((x))
#   define _declspec(x)   __declspec((x))
#   define declspec(x)   __declspec((x))
#   define _TLS_QUAL   __declspec(thread)
#elif defined(__GNUC__)
#   define _ATTRIBUTE(x)   __attribute__(x)
#   define __declspec(x)   __attribute__((x))
#   define __declspec__(x)   __attribute__((x))
#   define _declspec(x)   __attribute__((x))
#   define declspec(x)   __attribute__((x))
#   define _TLS_QUAL
#else
#   define __attribute__(x)
#   define _ATTRIBUTE(x)
#   define __declspec(x)
#   define __declspec__(x)
#   define _declspec(x)
#   define declspec(x)
#   define _TLS_QUAL
#endif  // __attribute__ & __declspec
#if AT_LEAST_GCC28  // __statement
#   define __statement(x)   __extension__ { (x) }
#else
#   define __statement(x)   do { (x) } while (0x0);
#endif  // __statement
// ATOMIC
#if (IS_NOT_CPLUSPLUS && IS_BELOW_STDC_2011)  // _Atomic
#   define _Atomic   __attribute__((__atomic__))
#endif
#ifndef Atomic
#   define Atomic   _Atomic
#endif
#ifndef atomic
#   define atomic   _Atomic
#endif
#ifndef _atomic
#   define _atomic   _Atomic
#endif
// RESTRICT
#if AT_LEAST_GCC2_92  // restrict
#   define restrict   __restrict__
#elif (defined(_WIN32) && defined(COMPILER_MICROSOFT))  // As of MSVC 2013, restrict is supported with a non-standard keyword
#   ifndef restrict
#      define restrict   __restrict
#   endif
#elif IS_STDC_1999
#   define __restrict__   restrict
#elif defined(__lint__)
#   define restrict
#   define __restrict__
#endif  // restrict
#define _Restrict   restrict
#define __restrict   restrict
#define __restrict_arr   restrict
#define restrict_arr   restrict
// GENERIC & TYPEOF
#ifndef Generic
/** Alias for "_Generic" on systems that lack "Generic" */
#   define Generic    _Generic
#endif
#if (defined(__GNUC__) && (!defined(typeof)))  // __typeof
/** Alias for "__typeof__" on systems that lack "typeof" */
#   define typeof(OBJECT)   __typeof__((OBJECT))
#elif (!defined(__GNUC__) && (!defined(__typeof__)))
/** Alias for "typeof" on systems that lack "__typeof__" */
#   define __typeof__(OBJECT)   typeof((OBJECT))
#endif
#ifndef __typeof
#   define __typeof(OBJECT)   __typeof__((OBJECT))
#endif
#ifndef _typeof
#   define _typeof(OBJECT)   __typeof__((OBJECT))
#endif
#ifndef GetType
/** Alias for "typeof" */
#   define GetType   typeof
#endif
// __SIZEOF__
#ifndef __sizeof__
#   define __sizeof__(OBJECT)   sizeof((OBJECT))
#endif
#ifndef __sizeof
#   define __sizeof(OBJECT)   sizeof((OBJECT))
#endif
#ifndef _sizeof
#   define _sizeof(OBJECT)   sizeof((OBJECT))
#endif
// INLINE, FORCEINLINE, EXTERN_INLINE, & RELATED ATTRIBUTES
#if (defined(_WIN32) && defined(COMPILER_MICROSOFT))  // inline & forceinline
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
#      ifdef __GNUC__
/** Alias for "inline" on systems that lack "__forceinline" */
#         define __forceinline    inline __attribute__((__always_inline__))
#      else
/** Alias for "inline" on systems that lack "__forceinline" */
#         define __forceinline    inline
#      endif  // __GNUC__
#   endif  // __forceinline
#endif  // inline & forceinline
#ifndef forceinline  // forceinline
/** Alias for "__forceinline" on systems that lack "forceinline" */
#   define forceinline   __forceinline
#endif
#ifndef __header_always_inline  // __header_always_inline
/** Alias for "__forceinline" on systems that lack "__header_always_inline" */
#   define __header_always_inline   __forceinline
#endif
#ifndef header_always_inline  // header_always_inline
/** Alias for "__forceinline" on systems that lack "header_always_inline" */
#   define header_always_inline   __forceinline
#endif
#ifndef INLINE  // INLINE
/** Alias for "inline" on systems that lack "INLINE" */
#   define INLINE   inline
#endif
#ifndef __inline__
/** Alias for "inline" on systems that lack "__inline__" */
#   define __inline__    inline
#endif
#if AT_LEAST_GCC4  // noinline & always_inline
/** Do not inline function */
#   define __attribute_noinline__   __attribute__((__noinline__))
/** Do not inline function */
#   define __noinline   __attribute__((__noinline__))
#   define __always_inline    inline __attribute__((__always_inline__))
#else
#   define __attribute_noinline__
#   define __noinline
#   define __always_inline    inline
#endif  // noinline & always_inline
#define DECLSPEC_NOINLINE   __noinline
#define _NOINLINE   __noinline
#ifndef noinline
#   define noinline   __noinline
#endif
#define _NOINLINE_STATIC   __noinline static
#if (defined(__GNUC__) && ((defined(__GNUC_STDC_INLINE__) && (__GNUC_STDC_INLINE__ > 0)) || (defined(__GNUC_GNU_INLINE__) && (__GNUC_GNU_INLINE__ > 0))))  // __c99inline
/** Non-static C99 inline functions are optional bodies; They do not create global symbols if not used, but can be replaced if desirable */
#   define __c99inline   extern __attribute__((__gnu_inline__)) inline
#elif defined(__GNUC__)
/** Non-static C99 inline functions are optional bodies; They do not create global symbols if not used, but can be replaced if desirable */
#   define __c99inline   extern inline
#elif defined(__STDC_VERSION__)
/** Non-static C99 inline functions are optional bodies; They do not create global symbols if not used, but can be replaced if desirable */
#   define __c99inline   inline
#endif  // __c99inline
#ifndef __gnu_inline
#   define __gnu_inline   __c99inline
#endif
#define _GL_EXTERN_INLINE   __c99inline
#define __CRT_INLINE   __c99inline
#define __BIONIC_FORTIFY_INLINE   __c99inline
#define BITROTATE_INLINE   _GL_EXTERN_INLINE
#define __gmp_inline   inline
#define OS_INLINE   inline
#define __DARWIN_OS_INLINE   inline
#define DARWIN_OS_INLINE   inline
#ifndef __header_inline
#   define __header_inline   inline
#endif
#ifndef __ATOMIC_INLINE__
#   define __ATOMIC_INLINE__   static __always_inline
#endif
#if (((defined(__GNUC_STDC_INLINE__) && (__GNUC_STDC_INLINE__ > 0)) || IS_CPLUSPLUS) && (AT_LEAST_GCC43))  // __extern_inline & __extern_always_inline
/** Alias for "extern inline" */
#   define __extern_inline   extern inline __attribute__((__gnu_inline__))
/** Similar to "extern inline", but always inline */
#   define __extern_always_inline   extern inline __attribute__((__always_inline__, __gnu_inline__))
#else
/** Alias for "extern inline" */
#   define __extern_inline   extern inline
/** Similar to "extern inline", but always inline */
#   define __extern_always_inline   extern inline __attribute__((__always_inline__))
#endif  // __extern_inline & __extern_always_inline
/** Similar to "extern inline", but always inline */
#define extern_always_inline   __extern_always_inline
#ifndef extern_inline
/** Alias for "extern inline" */
#   define extern_inline   __extern_inline
#endif
#ifndef _EXTERN_INLINE
/** Alias for "extern inline" */
#   define _EXTERN_INLINE   __extern_inline
#endif
#ifndef __STDIO_INLINE
/** Alias for "extern inline" */
#   define __STDIO_INLINE   __extern_inline
#endif
#if (defined(__GNUC__) && (defined(__GNUC_STDC_INLINE__) && (__GNUC_STDC_INLINE__ > 0)))  // __static_inline
#   define __static_inline   static inline __attribute__((__gnu_inline__))
#else
#   define __static_inline   static inline
#endif  // __static_inline
#ifndef static_inline
#   define static_inline   __static_inline
#endif
#ifndef WINE_UNICODE_INLINE
#   define WINE_UNICODE_INLINE    static inline
#endif
#if AT_LEAST_GCC3  // __must_inline
#   define __must_inline   extern inline __attribute__((__always_inline__))
#else
#    define __must_inline   inline
#endif  // __must_inline
#ifndef must_inline
#   define must_inline   __must_inline
#endif
#if (defined(__GNUC__) && ((!defined(__GNUC_STDC_INLINE__)) || (__GNUC_STDC_INLINE__ == 0)))  // _ELIDABLE_INLINE
#   define _ELIDABLE_INLINE   extern inline __attribute__((__always_inline__))
#else
#   define _ELIDABLE_INLINE   static inline
#endif  // _ELIDABLE_INLINE
#ifndef ELIDABLE_INLINE
#   define ELIDABLE_INLINE   _ELIDABLE_INLINE
#endif
// VOLATILE
#if IS_ANSI
#   ifndef __volatile
/** Alias for "__volatile__" on systems that lack "__volatile" */
#      define __volatile    __volatile__
#   endif
#   ifndef volatile
/** Alias for "__volatile__" on systems that lack "volatile" */
#      define volatile    __volatile__
#   endif
#endif  // volatile
// ASM ATTRIBUTE
#if ((!defined(__GNUC__)) && (!defined(__asm__)))
/** Alias for "asm" on systems that lack "__asm__" */
#   define __asm__    asm
#elif (defined(__GNUC__) && (!defined(asm)))
/** Alias for "__asm__" on systems that lack "asm" */
#   define asm    __asm__
#endif
#ifndef __asm
/** Alias for "__asm__" on systems that lack "__asm" */
#   define __asm    __asm__
#endif
#define __ASMNAME2(prefix, cname)   __STRING(prefix) cname
#define __ASMNAME(cname)  __ASMNAME2(__USER_LABEL_PREFIX__, cname)
#define __REDIRECT(name, proto, alias)   name proto asm (__ASMNAME (#alias))
#ifndef vasm
#   define vasm   asm volatile
#endif
// STATIC_ASSERT
#ifndef static_assert
#   define static_assert(expr, diagnostic)   _Static_assert((expr), (diagnostic))
#endif
// BUILTIN_EXPECT
#define builtin_expect(x, y)   __builtin_expect((x), (y))
// X86 CALLING CONVENTIONS
#if (defined(I386) && (!defined(X86_64)) && defined(__GNUC__))  // https://en.wikipedia.org/wiki/X86_calling_conventions
#   ifndef __cdecl
/** __cdecl is used when we want varadic and non-varadic functions to have the same binary calling convention */
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
#else  // Meaningless on non-i386
#   ifndef __cdecl
/** __cdecl is used when we want varadic and non-varadic functions to have the same binary calling convention */
#      define __cdecl
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
#endif
#ifndef cdecl
#   define cdecl   __cdecl
#endif
#ifndef CDECL
#   define CDECL   __cdecl
#endif
#ifndef __CDECL__
#   define __CDECL__   __cdecl
#endif
#ifndef __CRTDECL
#   define __CRTDECL   __cdecl
#endif
#ifndef _cdecl
/** __cdecl is used when we want varadic and non-varadic functions to have the same binary calling convention */
#   define _cdecl   __cdecl
#endif
#ifndef WINAPIV
/** __cdecl is used when we want varadic and non-varadic functions to have the same binary calling convention */
#   define WINAPIV   __cdecl
#endif
#ifndef _fastcall
/** Passes the first two arguments (left to right) that fit into ECX and EDX, and the remaining arguments are pushed onto the stack (from right to left) */
#   define _fastcall   __fastcall
#endif
#ifndef fastcall
/** Passes the first two arguments (left to right) that fit into ECX and EDX, and the remaining arguments are pushed onto the stack (from right to left) */
#   define fastcall   __fastcall
#endif
#ifndef __msfastcall
/** Passes the first two arguments (left to right) that fit into ECX and EDX, and the remaining arguments are pushed onto the stack (from right to left) */
#   define __msfastcall   __fastcall
#endif
#ifndef _msfastcall
/** Passes the first two arguments (left to right) that fit into ECX and EDX, and the remaining arguments are pushed onto the stack (from right to left) */
#   define _msfastcall   __fastcall
#endif
#ifndef msfastcall
/** Passes the first two arguments (left to right) that fit into ECX and EDX, and the remaining arguments are pushed onto the stack (from right to left) */
#   define msfastcall   __fastcall
#endif
#ifndef _stdcall
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#   define _stdcall   __stdcall
#endif
#ifndef pascal
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#   define pascal   __stdcall
#endif
#ifndef PASCAL
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#   define PASCAL   __stdcall
#endif
#ifndef CALLBACK
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#   define CALLBACK   __stdcall
#endif
#ifndef WINAPI
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#   define WINAPI   __stdcall
#endif
#ifndef APIENTRY
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#   define APIENTRY   __stdcall
#endif
#ifndef stdcall
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#   define stdcall   __stdcall
#endif
#ifndef GSSAPI_CALLCONV
/** Assume that the called function pops off the stack space used to pass arguments, unless it takes a variable number of arguments */
#   define GSSAPI_CALLCONV   __stdcall
#endif
#ifndef _thiscall
/** Pass the first argument (if an integral) to the ECX register; The following arguments and arguments of other datatypes are passed to the stack; The called function pops the arguments off the stack; If the number of arguments is variable all arguments are pushed on the stack */
#   define _thiscall   __thiscall
#endif
#ifndef thiscall
/** Pass the first argument (if an integral) to the ECX register; The following arguments and arguments of other datatypes are passed to the stack; The called function pops the arguments off the stack; If the number of arguments is variable all arguments are pushed on the stack */
#   define thiscall   __thiscall
#endif
// NUX MACROS
/** If NUX_LOG_FILE_ANSI is set to 1, log files will be written in ASCII characters even when in UNICODE */
#define NUX_LOG_FILE_ANSI   (1)
#define NUX_VARARGS   __cdecl
#define NUX_CDECL   __cdecl
#define NUX_STDCALL   __stdcall
#define NUX_FASTCALL   __fastcall
#define NUX_THISCALL    __thiscall
#define NUX_INLINE   inline
#define NUX_FORCEINLINE   inline
#define NUX_FORCENOINLINE   __attribute__((__noinline__))
#if ((defined(I386) && !defined(X86_64)) && defined(__GNUC__) && CPU_SSE && (!defined(sseregparm)))
/** (x86-32 targets with SSE support only) Pass up to 3 floating-point arguments in SSE registers instead of on the stack; Functions that take a variable number of arguments continue to pass all of their floating-point arguments on the stack (x86-32 targets with SSE support only) */
#   define sseregparm   __attribute__((__sseregparm__))
#else
#   define sseregparm
#endif
#if IS_CPLUSPLUS
#   ifdef OSCYGWIN
#      define _EXFUN_NOTHROW(name, proto)   __cdecl name proto _NOTHROW
#      define _EXFUN(name, proto)   __cdecl name proto
#      define _EXPARM(name, proto)   (* __cdecl name) proto
#      define _EXFNPTR(name, proto)   (__cdecl * name) proto
#   else  // Not Cygwin
#      define _EXFUN_NOTHROW(name, proto) name proto _NOTHROW
#      define _EXFUN(name, proto)   name proto
#      define _EXPARM(name, proto)   (* name) proto
#      define _EXFNPTR(name, proto)   (* name) proto
#   endif  // Cygwin
#endif  // IS_CPLUSPLUS
#ifdef __GNUC__  // EXTERN_API & CALLBACK_API
#   define EXTERN_API(_type)   _type __cdecl
#   define EXTERN_API_C(_type)   _type __cdecl
#   define EXTERN_API_STDCALL(_type)   _type __stdcall
#   define EXTERN_API_C_STDCALL(_type)   _type __stdcall
#   define DEFINE_API(_type)   _type __cdecl
#   define DEFINE_API_C(_type)   _type __cdecl
#   define DEFINE_API_STDCALL(_type)   _type __stdcall
#   define DEFINE_API_C_STDCALL(_type)   _type __stdcall
#   define CALLBACK_API(_type, _name)   _type (__cdecl * _name)
#   define CALLBACK_API_C(_type, _name)   _type (__cdecl * _name)
#   define CALLBACK_API_STDCALL(_type, _name)   _type (__stdcall * _name)
#   define CALLBACK_API_C_STDCALL(_type, _name)   _type (__stdcall * _name)
#elif defined(MICROSOFT_VISUAL)
#   define EXTERN_API(_type)   __declspec(dllimport) _type __cdecl
#   define EXTERN_API_C(_type)   __declspec(dllimport) _type __cdecl
#   define EXTERN_API_STDCALL(_type)   __declspec(dllimport) _type __stdcall
#   define EXTERN_API_C_STDCALL(_type)   __declspec(dllimport) _type __stdcall
#   define DEFINE_API(_type)   __declspec(dllexport) _type __cdecl
#   define DEFINE_API_C(_type)   __declspec(dllexport) _type __cdecl
#   define DEFINE_API_STDCALL(_type)   __declspec(dllexport) _type __stdcall
#   define DEFINE_API_C_STDCALL(_type)   __declspec(dllexport) _type __stdcall
#   define CALLBACK_API(_type, _name)   _type (__cdecl * _name)
#   define CALLBACK_API_C(_type, _name)   _type (__cdecl * _name)
#   define CALLBACK_API_STDCALL(_type, _name)   _type (__stdcall * _name)
#   define CALLBACK_API_C_STDCALL(_type, _name)   _type (__stdcall * _name)
#else
#   define EXTERN_API(_type)   extern _type
#   define EXTERN_API_C(_type)   extern _type
#   define EXTERN_API_STDCALL(_type)   extern _type
#   define EXTERN_API_C_STDCALL(_type)   extern _type
#   define DEFINE_API(_type)   _type
#   define DEFINE_API_C(_type)   _type
#   define DEFINE_API_STDCALL(_type)   _type
#   define DEFINE_API_C_STDCALL(_type)   _type
#   define CALLBACK_API(_type, _name)   _type ( * _name)
#   define CALLBACK_API_C(_type, _name)   _type ( * _name)
#   define CALLBACK_API_STDCALL(_type, _name)   _type ( * _name)
#   define CALLBACK_API_C_STDCALL(_type, _name)   _type ( * _name)
#endif  // EXTERN_API & CALLBACK_API
// C++ ATTRIBUTES
#if IS_CPLUSPLUS  // _NOTHROW
#   if AT_LEAST_GCC33
#      define _NOTHROW   __attribute__((__nothrow__))
#   else
#      define _NOTHROW
#   endif
#else  // Not C++
#   define _NOTHROW
#endif  // _NOTHROW
#if IS_CPLUSPLUS  // C++ Specifiers and attributes
/** Alias for "thread_local" on systems that lack "_Thread_local" */
#   define _Thread_local   thread_local
#   define Thread_local   thread_local
#   define __THROW   throw()
#   define __THROWNL   throw()
#   define __NTH(fct)   fct throw()
#   define __MATH_INLINE   inline
#   define __REDIRECT_NTH(name, proto, alias)   name proto __THROW asm (__ASMNAME (#alias))
#   define __REDIRECT_NTHNL(name, proto, alias)   name proto __THROWNL asm (__ASMNAME (#alias))
#else  // C
/** Alias for "__thread" or "_Thread_local" on systems that lack "thread_local" */
#   define thread_local   __thread
#   define _Thread_local   __thread
#   define Thread_local   __thread
#   define __THROW
#   define __THROWNL
#   define __NTH(fct)   fct
#   define __MATH_INLINE   extern inline
#   define __REDIRECT_NTH(name, proto, alias)   name proto asm (__ASMNAME (#alias)) __THROW
#   define __REDIRECT_NTHNL(name, proto, alias)    name proto asm (__ASMNAME (#alias)) __THROWNL
#endif  // C++ Specifiers and attributes
// PACKED, ALIGNED, & SECTION
#if (defined(MICROSOFT_VISUAL) && (!AT_LEAST_GCC27))
#   define __aligned(x)   __declspec(align((x)))
#   define __attr_aligned(x)   __declspec(align((x)))
#   define align4   __declspec((align(4)))
#   define align8   __declspec((align(8)))
#   define align16   __declspec((align(16)))
#   define align32   __declspec((align(32)))
#elif (defined(__lint__) && (!AT_LEAST_GCC27))
#   define __aligned(x)
#   define __attr_aligned(x)
#   define align4
#   define align8
#   define align16
#   define align32
#elif (AT_LEAST_GCC27 || defined(__PCC__))
#   define __packed   __attribute__((__packed__))
#   ifndef __aligned
#      define __aligned(x)   __attribute__((__aligned__((x))))
#   endif
#   define __attr_aligned(x)   __attribute__((__aligned__((x))))
#   define auto_align   __attribute__((__aligned__))
#   define align4   __attribute__((__aligned__(4)))
#   define align8   __attribute__((__aligned__(8)))
#   define align16   __attribute__((__aligned__(16)))
#   define align32   __attribute__((__aligned__(32)))
#   define __section(x)   __attribute__((__section__((x))))
#else
#   define __aligned(x)
#   define __attr_aligned(x)
#   define __packed
#   define auto_align
#   define __section(x)
#   define align4
#   define align8
#   define align16
#   define align32
#endif
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
#ifdef AT_LEAST_GCC41
#   define __assume_aligned(a, ...)   __attribute__((__assume_aligned__(a, ## __VA_ARGS__)))
#else
#   define __assume_aligned(a, ...)
#endif
#define _FSSH_PACKED   __packed
#define attr_packed   __packed
#define ATTRIBUTE_PACKED   __packed
#define _VTE_GNUC_PACKED   __packed
#ifndef attr_aligned
#   define attr_aligned(x)   __attr_aligned((x))
#endif
// ALIGNMENT ATTRIBUTES
#if (AT_LEAST_GCC30 && (!defined(ATTRIBUTE_ALIGNED_ALIGNOF)))
#   define ATTRIBUTE_ALIGNED_ALIGNOF(param)   __attribute__((__aligned__(__alignof__(param))))
#else
#   define ATTRIBUTE_ALIGNED_ALIGNOF(param)
#endif
#if (AT_LEAST_GCC30 && (!defined(ATTR_ALIGNED_ALIGNOF)))
#   define ATTR_ALIGNED_ALIGNOF(param)   __attribute__((__aligned__(__alignof__(param))))
#endif
// FORMAT ATTRIBUTES
#if AT_LEAST_GCC4
#   define __formatfunc(t, f, a)   __attribute__((__format__(t, f, a)))
#   define __attribute_format_strfmon__(a, b)   __attribute__((__format__(__strfmon__, (a), (b))))
#   define __attribute_format_arg__(x)   __attribute__((__format_arg__(x)))
#   define ISC_FORMAT_PRINTF(a, b)   __attribute__((__format__(__printf__, a, b)))
#   define ATF_DEFS_ATTRIBUTE_FORMAT_PRINTF(a, b)   __attribute__((__format__(__printf__, a, b)))
#   define ATTRIBUTE_FORMAT_PRINTF(a, b)   __attribute__((__format__(__printf__, a, b)))
#   define __printflike(fmtarg, firstvararg)   __attribute__((__format__(__printf__, fmtarg, firstvararg)))
#   define CX_GNUC_PRINTF(fmt_idx, arg_idx)   __attribute__((__format__(__printf__, fmt_idx, arg_idx)))
#   define CX_GNUC_SCANF(fmt_idx, arg_idx)   __attribute__((__format__(__scanf__, fmt_idx, arg_idx)))
#   define CX_GNUC_FORMAT(arg_idx)   __attribute__((__format_arg__(arg_idx)))
/** Attribute to make GCC check printf-like arguments */
#   define printflike1   __attribute__((__format__(__printf__, 1, 2)))
/** Attribute to make GCC check printf-like arguments */
#   define printflike2   __attribute__((__format__(__printf__, 2, 3)))
/** Attribute to make GCC check printf-like arguments */
#   define printflike3   __attribute__((__format__(__printf__, 3, 4)))
/** Attribute to make GCC check printf-like arguments */
#   define printflike4   __attribute__((__format__(__printf__, 4, 5)))
/** Attribute to make GCC check printf-like arguments */
#   define printflike5   __attribute__((__format__(__printf__, 5, 6)))
#   define __scanflike(fmtarg, firstvararg)   __attribute__((__format__(__scanf__, fmtarg, firstvararg)))
#   define __format_arg(fmtarg)    __attribute__((__format_arg__(fmtarg)))
#   define ATTRIBUTE_PRINTF(m, n)   __attribute__((__format__(__printf__, m, n))) ATTRIBUTE_NONNULL(m)
#   define ATTRIBUTE_PRINTF_1   ATTRIBUTE_PRINTF(1, 2)
#   define ATTRIBUTE_PRINTF_2   ATTRIBUTE_PRINTF(2, 3)
#   define ATTRIBUTE_PRINTF_3   ATTRIBUTE_PRINTF(3, 4)
#   define ATTRIBUTE_PRINTF_4   ATTRIBUTE_PRINTF(4, 5)
#   define ATTRIBUTE_PRINTF_5   ATTRIBUTE_PRINTF(5, 6)
#   define ATTRIBUTE_NULL_PRINTF(m, n)   __attribute__((__format__(__printf__, m, n)))
#   define ATTRIBUTE_NULL_PRINTF_1   ATTRIBUTE_NULL_PRINTF(1, 2)
#   define ATTRIBUTE_NULL_PRINTF_2   ATTRIBUTE_NULL_PRINTF(2, 3)
#   define ATTRIBUTE_NULL_PRINTF_3   ATTRIBUTE_NULL_PRINTF(3, 4)
#   define ATTRIBUTE_NULL_PRINTF_4   ATTRIBUTE_NULL_PRINTF(4, 5)
#   define ATTRIBUTE_NULL_PRINTF_5   ATTRIBUTE_NULL_PRINTF(5, 6)
#else
#   define __formatfunc(t, f, a)
#   define __attribute_format_strfmon__(a, b)
#   define __attribute_format_arg__(x)
#   define ISC_FORMAT_PRINTF(a, b)
#   define ATF_DEFS_ATTRIBUTE_FORMAT_PRINTF(a, b)
#   define ATTRIBUTE_FORMAT_PRINTF(a, b)
#   define __printflike(fmtarg, firstvararg)
#   define CX_GNUC_PRINTF(fmt_idx, arg_idx)
#   define CX_GNUC_SCANF(fmt_idx, arg_idx)
#   define CX_GNUC_FORMAT(arg_idx)
#   define printflike1
#   define printflike2
#   define printflike3
#   define printflike4
#   define printflike5
#   define __scanflike(fmtarg, firstvararg)
#   define __format_arg(fmtarg)
#   define ATTRIBUTE_PRINTF(m, n)
#   define ATTRIBUTE_PRINTF_1
#   define ATTRIBUTE_PRINTF_2
#   define ATTRIBUTE_PRINTF_3
#   define ATTRIBUTE_PRINTF_4
#   define ATTRIBUTE_PRINTF_5
#   define ATTRIBUTE_NULL_PRINTF(m, n)
#   define ATTRIBUTE_NULL_PRINTF_1
#   define ATTRIBUTE_NULL_PRINTF_2
#   define ATTRIBUTE_NULL_PRINTF_3
#   define ATTRIBUTE_NULL_PRINTF_4
#   define ATTRIBUTE_NULL_PRINTF_5
#endif  // __formatfunc
#ifndef formatfunc
#   define formatfunc(t, f, a)   __formatfunc((t), (f), (a))
#endif
#define FORMAT_PRINTF_ATTRIBUTE(a, b)   ATTRIBUTE_FORMAT_PRINTF((a), (b))
#define ATTRIBUTE_FPTR_PRINTF(m, n)   ATTRIBUTE_PRINTF(m, n)
#define ATTRIBUTE_FPTR_PRINTF_1   ATTRIBUTE_FPTR_PRINTF(1, 2)
#define ATTRIBUTE_FPTR_PRINTF_2   ATTRIBUTE_FPTR_PRINTF(2, 3)
#define ATTRIBUTE_FPTR_PRINTF_3   ATTRIBUTE_FPTR_PRINTF(3, 4)
#define ATTRIBUTE_FPTR_PRINTF_4   ATTRIBUTE_FPTR_PRINTF(4, 5)
#define ATTRIBUTE_FPTR_PRINTF_5   ATTRIBUTE_FPTR_PRINTF(5, 6)
// HAS_BUILTIN, HAS_INCLUDE, HAS_INCLUDE_NEXT, HAS_FEATURE, ETC.
#ifndef __has_attribute
#   define __has_attribute(x)   0
#endif
#ifndef __has_builtin
#   define __has_builtin(x)   0
#endif
#ifndef __has_extension
#   define __has_extension(x)   0
#endif
#ifndef __has_feature
#   define __has_feature(x)   0
#endif
#ifndef __has_include
#   define __has_include(x)   0
#endif
#ifndef __has_include_next
#   define __has_include_next(x)   0
#endif
#undef __musl_has_extension
#define __musl_has_extension(x)   __has_extension(x)
#undef musl_has_extension
#define musl_has_extension(x)   __has_extension(x)
#if ((!defined(has_include)) && defined(__has_include))
/** Alias for "__has_include" */
#   define has_include(LIBRARY)    (__has_include(LIBRARY))
#endif
#if ((!defined(has_include_next)) && defined(__has_include_next))
/** Alias for "__has_include_next" */
#   define has_include_next(LIBRARY)    (__has_include_next(LIBRARY))
#   define HAVE_INCLUDE_NEXT   (1)
#endif
// ATTRIBUTE MACROS
#if AT_LEAST_GCC4
#   define ATTR_CAF   __attribute__((__always_inline__, __const__, __flatten__))
#   define ATTR_CAFN   __attribute__((__always_inline__, __const__, __flatten__, __nonnull__))
#   define ATTR_MALLOC   __attribute__((__malloc__))
#   define __attribute_const__   __attribute__((__const__))
/** Definition to shut the compiler up about unused arguments */
#   define __attribute_used__   __attribute__((__unused__))
/** Warn the developer that the function is deprecated */
#   define __attribute_deprecated__   __attribute__((__deprecated__))
/** If using fortification mode, warn about unused results of certain function calls which can lead to problems */
#   define __attribute_warn_unused_result__   __attribute__((__warn_unused_result__))
/** Fortify support */
#   define __bos(_ptr)   __builtin_object_size(_ptr, (__USE_FORTIFY_LEVEL > 1))
/** Fortify support */
#   define __bos0(_ptr)   __builtin_object_size(_ptr, 0)
#   define lzma_attr_alloc_size(x)   __attribute__((__alloc_size__(x)))
/** A set of commonly used function attributes */
#   define FUNC_ATTR   __attribute__((__always_inline__, __const__, __flatten__))
/** The function type used for static inlines */
#   define FUNC_TYPE   static inline
/** Determine the return address */
#   define RETURN_ADDRESS(nr)   __builtin_extract_return_addr(__builtin_return_address((nr)))
#   define __noprofile   __attribute__((__no_instrument_function__))
#   ifndef __glibc_likely
/** The expression is likely to be true */
#      define __glibc_likely(expression)   __builtin_expect((expression), 0x1)
#   endif
#   ifndef glibc_likely
/** The expression is likely to be true */
#      define glibc_likely(expression)   __builtin_expect((expression), 0x1)
#   endif
#   ifndef __glibc_unlikely
/** The expression is likely to be false */
#      define __glibc_unlikely(expression)   __builtin_expect((expression), 0x0)
#   endif
#   ifndef glibc_unlikely
/** The expression is likely to be false */
#      define glibc_unlikely(expression)   __builtin_expect((expression), 0x0)
#   endif
/** The expression is likely to be true */
#   define __predict_true(expression)   __builtin_expect(((expression) != 0x0), 0x1)
/** The expression is likely to be true */
#   define predict_true(expression)   __builtin_expect(((expression) != 0x0), 0x1)
/** The expression is likely to be false */
#   define __predict_false(expression)   __builtin_expect(((expression) != 0x0), 0x0)
/** The expression is likely to be false */
#   define predict_false(expression)   __builtin_expect(((expression) != 0x0), 0x0)
/** Evaluates to `expression` and hints that the value of `expression` will probably be true; In other words, "if (PREDICT_LIKELY(foo))" is the same as "if (foo)"; it tells the compiler that the branch will be taken most of the time; This can generate slightly better code with some CPUs */
#   define PREDICT_LIKELY(expression)   __builtin_expect((!!(expression)), 0x1)
/** Evaluates to `expression` and hints that the value of `expression` will probably be false; In other words, "if (PREDICT_UNLIKELY(foo))" is the same as "if (foo)"; it tells the compiler that the branch will usually not be taken; This can generate slightly better code with some CPUs */
#   define PREDICT_UNLIKELY(expression)   __builtin_expect((!!(expression)), 0x0)
/** Evaluates to `expression` and hints that the value of `expression` will probably be false; In other words, "if (PREDICT_UNLIKELY(foo))" is the same as "if (foo)"; it tells the compiler that the branch will usually not be taken; This can generate slightly better code with some CPUs */
#   define UNLIKELY(expression)   __builtin_expect((!!(expression)), 0x0)
/** Evaluates to `expression` and hints that the value of `expression` will probably equal `_val` This tells the compiler that the branch will be taken most of the time; This can generate slightly better code with some CPUs */
#   define LIKELY(expression, _val)   __builtin_expect((expression), (_val))
/** Evaluates to `expression` and hints that the value of `expression` will probably be false; this tells the compiler that the branch will usually not be taken; This can generate slightly better code with some CPUs */
#   define LIKELY_FALSE(expression)   __builtin_expect((expression), 0x0)
/** Evaluates to `expression` and hints that the value of `expression` will probably equal `_val` This tells the compiler that the branch will be taken most of the time; This can generate slightly better code with some CPUs */
#   define LIKELY_TRUE(expression)   __builtin_expect((expression), 0x1)
#else
#   define ATTR_CAF
#   define ATTR_CAFN
#   define ATTR_MALLOC
#   define __attribute_const__
#   define __attribute_used__
#   define __attribute_deprecated__
/** If using fortification mode, warn about unused results of certain function calls which can lead to problems */
#   define __attribute_warn_unused_result__
/** Fortify support */
#   define __bos(_ptr)
/** Fortify support */
#   define __bos0(_ptr)
#   define lzma_attr_alloc_size(x)
#   define FUNC_ATTR
#   define FUNC_TYPE   static
#   define RETURN_ADDRESS(nr)
#   define __noprofile
#   ifndef __glibc_likely
#      define __glibc_likely(expression)   ((expression))
#   endif
#   ifndef glibc_likely
#      define glibc_likely(expression)   ((expression))
#   endif
#   ifndef __glibc_unlikely
#      define __glibc_unlikely(expression)   ((expression))
#   endif
#   ifndef glibc_unlikely
#      define glibc_unlikely(expression)   ((expression))
#   endif
#   define __predict_true(expression)   (expression)
#   define predict_true(expression)   (expression)
#   define __predict_false(expression)   (expression)
#   define predict_false(expression)   (expression)
#   define PREDICT_LIKELY(expression)   ((expression))
#   define PREDICT_UNLIKELY(expression)   ((expression))
#   define UNLIKELY(expression)   ((expression))
#   define LIKELY(expression, _val)   ((expression))
#   define LIKELY_FALSE(expression)
#   define LIKELY_TRUE(expression)
#endif
#define __attribute_malloc__   ATTR_MALLOC
#define attr_malloc   ATTR_MALLOC
#define __mallocfunc   ATTR_MALLOC
#define __MINGW_ATTRIB_MALLOC   ATTR_MALLOC
#define _GL_ATTRIBUTE_MALLOC   ATTR_MALLOC
#define attribute_malloc   ATTR_MALLOC
#define CX_GNUC_MALLOC   ATTR_MALLOC
#define G_GNUC_MALLOC   ATTR_MALLOC
#define ATTR_CONST   __attribute_const__
#define CX_GNUC_CONST   __attribute_const__
#define __constfunc   __attribute_const__
#define constfunc   __attribute_const__
#define __MINGW_ATTRIB_CONST   __attribute_const__
/** Attribute alias for deprecated */
#define __attribute_dontuse__   __attribute_deprecated__
/** Attribute alias for deprecated */
#define __dontuse__   __attribute_deprecated__
/** Attribute alias for deprecated */
#define __MINGW_ATTRIB_DEPRECATED   __attribute_deprecated__
/** Attribute alias for deprecated */
#define __AVAILABILITY_INTERNAL_DEPRECATED   __attribute_deprecated__
/** Attribute alias for deprecated */
#define AVAILABILITY_INTERNAL_DEPRECATED   __attribute_deprecated__
/** Attribute alias for deprecated */
#define __deprecated   __attribute_deprecated__
/** Attribute alias for deprecated */
#define GSSAPI_DEPRECATED_FUNCTION(x)   __attribute_deprecated__
/** Definition to shut the compiler up about unused arguments */
#define attr_used   __attribute_used__
/** Definition to shut the compiler up about unused arguments */
#define attr_unused   __attribute_used__
/** Definition to shut the compiler up about unused arguments */
#define ATTR_UNUSED   __attribute_used__
/** Definition to shut the compiler up about unused arguments */
#define ATTRIBUTE_UNUSED   __attribute_used__
/** Definition to shut the compiler up about unused arguments */
#define CX_GNUC_UNUSED   __attribute_used__
/** Definition to shut the compiler up about unused arguments */
#define UNUSED   __attribute_used__
/** Definition to shut the compiler up about unused arguments */
#define _unused   __attribute_used__
/** Definition to shut the compiler up about unused arguments */
#define __unused   __attribute_used__
/** Definition to shut the compiler up about unused arguments */
#define __used   __attribute_used__
/** Definition to shut the compiler up about unused arguments */
#define ATF_DEFS_ATTRIBUTE_UNUSED   __attribute_used__
/** Definition to shut the compiler up about unused arguments */
#define __unusedfunc   __attribute_used__
/** Definition to shut the compiler up about unused arguments */
#define unusedfunc   __attribute_used__
/** Definition to shut the compiler up about unused arguments */
#define __MINGW_ATTRIB_UNUSED   __attribute_used__
/** Definition to shut the compiler up about unused arguments */
#define _GL_UNUSED_PARAMETER   __attribute_used__
#if (__USE_FORTIFY_LEVEL > 0)  // __wur
/** If using fortification mode, warn about unused results of certain function calls which can lead to problems */
#   define __wur   __attribute_warn_unused_result__
#else
#   define __wur
#endif  // __wur
#if DEBUG
/** Used in diagnostic code, but may be unused in non-diagnostic code */
#   define __diagused
/** Used in diagnostic code, but may be unused in non-diagnostic code */
#   define __debugused
#else
/** Used in diagnostic code, but may be unused in non-diagnostic code */
#   define __diagused   __attribute_used__
/** Used in diagnostic code, but may be unused in non-diagnostic code */
#   define __debugused   __attribute_used__
#endif
#if (AT_LEAST_GCC49 && (!defined(ATTRIBUTE_NO_SANITIZE_UNDEFINED)))
#   define ATTRIBUTE_NO_SANITIZE_UNDEFINED   __attribute__((__no_sanitize_undefined__))
#else
#   define ATTRIBUTE_NO_SANITIZE_UNDEFINED
#endif
#if ((!defined(OVERLOAD)) && defined(COMPILER_CLANG))
#   define OVERLOAD   __attribute__((__overloadable__))
#   define _TG_ATTRSp   __attribute__((__overloadable__))
#   define _TG_ATTRS   __attribute__((__overloadable__, __always_inline__))
#elif (!defined(OVERLOAD))
#   define OVERLOAD
#   define _TG_ATTRSp
#   define _TG_ATTRS   __attribute__((__always_inline__))
#endif
// UNREACHABLE
#if AT_LEAST_GCC45
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
// DEPRECATED_MSG
#if __has_feature(attribute_deprecated_with_message)
#   define __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)  __attribute__((__deprecated__(_msg)))
#   define DEPRECATED_ATTRIBUTE(_msg) __attribute__((__deprecated__(_msg)))
#   define DEPRECATED_MSG_ATTRIBUTE(_msg) __attribute__((__deprecated__(_msg)))
#   define __deprecated_msg(_msg) __attribute__((__deprecated__(_msg)))
#else
#   define __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)  __attribute__((__deprecated__))
#   define DEPRECATED_ATTRIBUTE   __attribute__((__deprecated__))
#   define DEPRECATED_MSG_ATTRIBUTE(_msg)   __attribute__((__deprecated__))
#   define __deprecated_msg(_msg)   __attribute__((__deprecated__))
#endif
#if __has_extension(enumerator_attributes)  // __deprecated_enum_msg
#   define __deprecated_enum_msg(_msg)   __deprecated_msg(_msg)
#else
#   define __deprecated_enum_msg(_msg)
#endif  // __deprecated_enum_msg
// WEAK_IMPORT & UNAVAILABLE
#if (AT_LEAST_GCC43 || ((defined(__MWERKS__) && (__MWERKS__ >= 0x3205)) && (MAC_OS_X_VERSION_MIN_REQUIRED >= 1020) && (!defined(INTEL))))
#   define WEAK_IMPORT_ATTRIBUTE   __attribute__((weak_import))
#   define __AVAILABILITY_INTERNAL_UNAVAILABLE   __attribute__((__unavailable__))
#   define __unavailable   __attribute__((__unavailable__))
#   define UNAVAILABLE_ATTRIBUTE   __attribute__((__unavailable__))
#   define __AVAILABILITY_INTERNAL_WEAK_IMPORT   __attribute__((__weak_import__))
#else
#   define WEAK_IMPORT_ATTRIBUTE
#   define __AVAILABILITY_INTERNAL_UNAVAILABLE
#   define __unavailable
#   define UNAVAILABLE_ATTRIBUTE
#   define __AVAILABILITY_INTERNAL_WEAK_IMPORT
#endif
// LONG DOUBLE COMPATABILITY
#if (defined(__LONG_DOUBLE_MATH_OPTIONAL) && defined(__NO_LONG_DOUBLE_MATH))  // __LDBL_REDIR1
#   define __LDBL_COMPAT   1
#   ifdef __REDIRECT
#      define __LDBL_REDIR1(name, proto, alias)   __REDIRECT(name, proto, alias)
#      define __LDBL_REDIR(name, proto)   __LDBL_REDIR1 (name, proto, __nldbl_##name)
#      define __LDBL_REDIR1_NTH(name, proto, alias) __REDIRECT_NTH (name, proto, alias)
#      define __LDBL_REDIR_NTH(name, proto)   __LDBL_REDIR1_NTH (name, proto, __nldbl_##name)
#      define __LDBL_REDIR1_DECL(name, alias)   extern typeof(name) name __asm (__ASMNAME (#alias));
#      define __LDBL_REDIR_DECL(name)   extern typeof(name) name __asm (__ASMNAME ("__nldbl_" #name));
#      define __REDIRECT_LDBL(name, proto, alias)   __LDBL_REDIR1(name, proto, __nldbl_##alias)
#      define __REDIRECT_NTH_LDBL(name, proto, alias)   __LDBL_REDIR1_NTH(name, proto, __nldbl_##alias)
#   endif  // __REDIRECT
#endif  // __LDBL_REDIR1
#if (!defined(__LDBL_COMPAT) || !defined(__REDIRECT))  // __LDBL_REDIR1
#   define __LDBL_REDIR1(name, proto, alias)   name proto
#   define __LDBL_REDIR(name, proto)   name proto
#   define __LDBL_REDIR1_NTH(name, proto, alias)   name proto __THROW
#   define __LDBL_REDIR_NTH(name, proto)   name proto __THROW
#   define __LDBL_REDIR_DECL(name)
#   ifdef __REDIRECT
#      define __REDIRECT_LDBL(name, proto, alias)   __REDIRECT(name, proto, alias)
#      define __REDIRECT_NTH_LDBL(name, proto, alias)   __REDIRECT_NTH(name, proto, alias)
#   endif
#endif  // __LDBL_REDIR1
// VISIBILITY
#if (defined(__PIC__) || defined(__GNUC__))  // ATTR_LIBC_VISIBILITY
/** Linkage decoration indicating that a symbol can be used from other compilation units, but not other libraries or executables */
#   define ATTR_LIBC_VISIBILITY   __attribute__((__visibility__("hidden")))
#else
#   define ATTR_LIBC_VISIBILITY
#endif
/** Linkage decoration indicating that a symbol can be used from other compilation units, but not other libraries or executables */
#define ATTR_VISIBILITY   ATTR_LIBC_VISIBILITY
#if ((!defined(__XNU_PRIVATE_EXTERN)) && defined(__GNUC__))  // XNU_PRIVATE_EXTERN
/** Linkage decoration indicating that a symbol can be used from other compilation units, but not other libraries or executables */
#   define __XNU_PRIVATE_EXTERN   ATTR_LIBC_VISIBILITY
#else
/** Linkage decoration indicating that a symbol can be used from other compilation units, but not other libraries or executables */
#   define __XNU_PRIVATE_EXTERN
#endif  // XNU_PRIVATE_EXTERN
#if AT_LEAST_GCC40  // __dso_public
#   define __dso_public   __attribute__((__visibility__("default")))
#   define __dso_hidden   __attribute__((__visibility__("hidden")))
#else
#   define __dso_public
#   define __dso_hidden
#endif
#if AT_LEAST_GCC42  // __dso_protected
#   define __dso_protected   __attribute__((__visibility__("protected")))
#else
#   define __dso_protected
#endif
/** Symbols used both internally and externally; This makes the compiler convert use of x to use _libc_x instead */
#define PROTO_NORMAL(x)   __dso_hidden typeof(x) x asm (HIDDEN_STRING(x))
/** Marks the symbol as deprecated */
#define PROTO_STD_DEPRECATED(x)   typeof(x) x __attribute__((__deprecated__))
/** Marks the symbol as both weak and deprecated */
#define PROTO_DEPRECATED(x)   typeof(x) x __attribute__((__deprecated__, __weak__))
/** Functions that have cancellation wrappers */
#define PROTO_CANCEL(x)   PROTO_NORMAL(x), CANCEL(x)
/** Functions that have wrappers */
#define PROTO_WRAP(x)   PROTO_NORMAL(x), WRAP(x)
/** Symbols that are exact clones of other symbols */
#define MAKE_CLONE(dst, src)   __dso_hidden typeof(dst) HIDDEN(dst) __attribute__((__alias__(HIDDEN_STRING((src)))))
// SPARSE ATTRIBUTES
#if (defined(__CHECKER__) || defined(__CHECK_ENDIAN__))
#   define __iomem   __attribute__((__noderef__, __address_space__(2)))
#   define __percpu   __attribute__((__noderef__, __address_space__(3)))
#   define __pmem   __attribute__((__noderef__, __address_space__(5)))
#   define __user   __attribute__((__noderef__, __address_space__(1)))
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
#   define __cond_lock(x, c)   ((c) ? ({ __acquire(x); 0x1; }) : 0x0)
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
/** Modifies an arithmetic type so that the only arithmetic options permitted are the ones that are strictly bitwise */
#define bitwise   __bitwise
/** Do not dereference */
#define noderef   __noderef
/** Warn if pointers tagged with different address spaces are mixed and if a pointer tagged with "noderef" is dereferenced */
#define address_space(x)  __address_space((x))
/** Issue a warning if a type is implicitly converted unless it is exactly the same type (changes in constness is permitted, presumably changes in volatility should be permitted as well) */
#define nocast  __nocast
// NONNULL, NULLABILITY, & PURE
#if (AT_LEAST_GCC35 && (!defined(ATTRIBUTE_SENTINEL)))
#   define ATTRIBUTE_SENTINEL   __attribute__((__sentinel__))
#else
#   define ATTRIBUTE_SENTINEL
#endif
#if (AT_LEAST_GCC33 && (!defined(_GL_ARG_NONNULL)))
/** _GL_ARG_NONNULL((n,...,m)) tells the compiler and static analyzer tools that the values passed as arguments n, ..., m must be non-NULL pointers; n = 1 stands for the first argument, n = 2 for the second argument, and so on */
#   define _GL_ARG_NONNULL(params)   __attribute__((__nonnull__ params))
#else
#   define _GL_ARG_NONNULL(params)
#endif  // _GL_ARG_NONNULL
#if (AT_LEAST_GCC33 && (!defined(_VTE_GNUC_NONNULL)))
/** Tells the compiler and static analyzer tools that the value passed as an argument must be a non-NULL pointer */
#   define _VTE_GNUC_NONNULL(position)   __attribute__((__nonnull__(position)))
#else
#   define _VTE_GNUC_NONNULL(position)
#endif  // _VTE_GNUC_NONNULL
#define __MINGW_ATTRIB_NONNULL(params)   _GL_ARG_NONNULL((params))
#if (!(__has_feature(nullability)))
#   define __null_unspecified(params)   __attribute__((__nonnull__ params))
#   define __nullable(params)   __attribute__((__nonnull__ params))
/** The functions input parameters are never NULL */
#   define NONNULL   __attribute__((__nonnull__))
#else
#   define __null_unspecified(params)
#   define __nullable(params)
/** The functions input parameters are never NULL */
#   define NONNULL
#endif
#define ATTRIBUTE_NONNULL(params)   __nullable((params))
#ifdef __GNUC__
/** The specified (numbered) arguments are not pointers to NULL; mark pointer parameters that must not be NULL */
#   define __nonnull(params)   __attribute__((__nonnull__ params))
/** The function is pure */
#   define __pure   __attribute__((__pure__))
/** The function is constant */
#   define CONST_FUNC   __attribute__((__const__))
#   define ATTRIBUTE_RETURNS_NONNULL   __attribute__((__returns_nonnull__))
/** The function does not accept nor return NULL */
#   define NONNULL_IO   __attribute__((__returns_nonnull__, __nonnull__))
#else
#   define __nonnull(params)
/** The function is pure */
#   define __pure
/** The function is constant */
#   define CONST_FUNC
#   define ATTRIBUTE_RETURNS_NONNULL
/** The function does not accept nor return NULL */
#   define NONNULL_IO
#endif
/** The function never returns NULL */
#define RETURNS_NONNULL   ATTRIBUTE_RETURNS_NONNULL
/** The function never returns NULL */
#define DOES_NOT_RETURN_NULL   ATTRIBUTE_RETURNS_NONNULL
/** The function never returns NULL */
#define NO_NULL_RET   ATTRIBUTE_RETURNS_NONNULL
/** The function never returns NULL */
#define NONNULL_RET   ATTRIBUTE_RETURNS_NONNULL
/** The function never returns NULL */
#define RET_NONNULL   ATTRIBUTE_RETURNS_NONNULL
/** The function is pure */
#define __purefunc   __pure
/** The function is pure */
#define purefunc   __pure
#define __attribute_pure__   __pure
#define attribute_pure   __pure
#define __MINGW_ATTRIB_PURE   __pure
#define CX_GNUC_PURE   __pure
#define G_GNUC_PURE   __pure
#define __pure2   __pure
// HOT & COLD FUNCTION ATTRIBUTES
#ifdef __GNUC__
#   define NOHOT   __attribute__((__cold__))
#   define COLD   __attribute__((__cold__))
#   define HOT   __attribute__((__hot__))
#else
#   define NOHOT
#   define COLD
#   define HOT
#endif  // HOT and COLD function attributes
#define ATTRIBUTE_COLD   COLD
#define ATTR_COLD   COLD
#define ATTRIBUTE_HOT   HOT
#define ATTR_HOT   HOT
// ATTRIBUTE_OPTIMIZE & SSP_STRONG
#if AT_LEAST_GCC44
#   define attribute_optimize(x)   __attribute__((optimize(x)))
#else
#   define attribute_optimize(x)
#endif
#ifdef HAVE_CC_INHIBIT_LOOP_TO_LIBCALL
/** Add the compiler optimization to inhibit loop transformation to library calls; This is used to avoid recursive calls in memset and memmove default implementations */
#   define inhibit_loop_to_libcall   __attribute__((__optimize__("-fno-tree-loop-distribute-patterns")))
#else
#   define inhibit_loop_to_libcall
#endif
// WARNDECL, WARNATTR, & ERRORDECL
#if AT_LEAST_GCC43
#   ifndef __warndecl
#      define __warndecl(name, msg)   extern void name (void) __attribute__((__warning__(msg)))
#   endif
#   ifndef __warnattr
#      define __warnattr(msg) __attribute__((__warning__(msg)))
#   endif
#   ifndef __errordecl
#      define __errordecl(name, msg)   extern void name (void) __attribute__((__error__(msg)))
#   endif
#else
#   ifndef __warndecl
#      define __warndecl(name, msg)   extern void name (void)
#   endif
#   ifndef __warnattr
#      define __warnattr(msg)
#   endif
#   ifndef __errordecl
#      define __errordecl(name, msg)   extern void name (void)
#   endif
#endif


// DATATYPE ATTRIBUTES

#ifndef VECTOR4
/** Used to make a vector datatype that is 4 bytes in length */
#   define VECTOR4   __attribute__((__vector_size__(4)))
#endif
#ifndef VECTOR8
/** Used to make a vector datatype that is 8 bytes in length */
#   define VECTOR8   __attribute__((__vector_size__(8)))
#endif
#ifndef VECTOR16
/** Used to make a vector datatype that is 16 bytes in length */
#   define VECTOR16   __attribute__((__vector_size__(16)))
#endif
#ifndef VECTOR32
/** Used to make a vector datatype that is 32 bytes in length */
#   define VECTOR32   __attribute__((__vector_size__(32)))
#endif
#ifndef VECTORSIZE4
/** Used to make a vector datatype that is 4 bytes in length */
#   define VECTORSIZE4   VECTOR4
#endif
#ifndef VECTORSIZE8
/** Used to make a vector datatype that is 8 bytes in length */
#   define VECTORSIZE8   VECTOR8
#endif
#ifndef VECTORSIZE16
/** Used to make a vector datatype that is 16 bytes in length */
#   define VECTORSIZE16   VECTOR16
#endif
#ifndef VECTORSIZE32
/** Used to make a vector datatype that is 32 bytes in length */
#   define VECTORSIZE32   VECTOR32
#endif
#ifndef __vector4
#   define __vector4   VECTOR4
#endif
#ifndef __vector8
#   define __vector8   VECTOR8
#endif
#ifndef __vector16
#   define __vector16   VECTOR16
#endif
#ifndef __vector32
#   define __vector32   VECTOR32
#endif


// ALIASES

#if (IS_NOT_ASSEMBLER && defined(__GNUC__))
// GCC understands weak symbols and aliases; use this interface where possible, instead of embedded assembly language
/** Define ALIASNAME as a strong alias for NAME */
#   define _strong_alias(name, aliasname)   extern typeof(name) aliasname __attribute__((alias (#name)));
#   define __strong_reference(sym, aliassym)   extern typeof(sym) aliassym __attribute__((__alias__(#sym)))
/** This comes between the return type and function name in a function definition to make that definition weak */
#   define weak_function   __attribute__((__weak__))
/** This comes between the return type and function name in a function definition to make that definition weak */
#   define weak_const_function   __attribute__((__weak__, __const__))
/** This comes between the return type and function name in a function definition to make that definition weak */
#   define const_weak_function   __attribute__((__weak__, __const__))
/** Define ALIASNAME as a weak alias for NAME. If weak aliases are not available, this defines a strong alias */
#   define _weak_alias(name, aliasname)   extern typeof(name) aliasname __attribute__((__weak__, alias (#name)));
#   define LFS64_2(x, y)   _weak_alias(x, y)
#   define LFS64(x)   LFS64_2(x, x##64)
/** Same as WEAK_ALIAS, but mark symbol as hidden */
#   define weak_hidden_alias(name, aliasname)   _weak_hidden_alias(name, aliasname)
/** Same as WEAK_ALIAS, but mark symbol as hidden */
#   define _weak_hidden_alias(name, aliasname)   extern typeof(name) aliasname __attribute__((weak, alias (#name), __visibility__("hidden")));
/** Declare SYMBOL as weak undefined symbol (resolved to 0 if not defined) */
#   define weak_extern(symbol)   _weak_extern(weak symbol)
/** Declare SYMBOL as weak undefined symbol (resolved to 0 if not defined) */
#   define _weak_extern(expr)   _Pragma(#expr)
#elif (IS_ASSEMBLER && defined(__GNUC__))  // IS_ASSEMBLER
#   ifdef HAVE_ASM_SET_DIRECTIVE
#      define _strong_alias(original, alias)   .globl C_SYMBOL_NAME (alias) ASM_LINE_SEP .set C_SYMBOL_NAME (alias), C_SYMBOL_NAME (original)
#      define strong_data_alias(original, alias)   _strong_alias(original, alias)
#   else
#      define _strong_alias(original, alias)   .globl C_SYMBOL_NAME (alias) ASM_LINE_SEP C_SYMBOL_NAME (alias) = C_SYMBOL_NAME (original)
#      define strong_data_alias(original, alias)   _strong_alias(original, alias)
#   endif
#   ifdef HAVE_ASM_WEAKEXT_DIRECTIVE
#      define _weak_alias(original, alias)   .weakext C_SYMBOL_NAME (alias), C_SYMBOL_NAME (original)
#      define weak_extern(symbol)   .weakext C_SYMBOL_NAME (symbol)
#   else
#      define _weak_alias(original, alias)   .weak C_SYMBOL_NAME (alias) ASM_LINE_SEP C_SYMBOL_NAME (alias) = C_SYMBOL_NAME (original)
#      define weak_extern(symbol)   .weak C_SYMBOL_NAME (symbol)
#   endif
#else
#   define _strong_alias(original, alias)
#   define __strong_reference(sym, aliassym)
#   define strong_data_alias(original, alias)
#   define LFS64_2(x, y)
#   define LFS64(x)   LFS64_2(x, x##64)
#   define _weak_alias(name, aliasname)
#   define weak_extern(symbol)
#   define weak_hidden_alias(name, aliasname)
#   define weak_function
#   define const_weak_function
#   define weak_const_function
#endif  // Aliases
#define __strict_weak_alias(alias, sym)   UNUSED static typeof(alias) *__weak_alias_##alias = &sym; __weak_alias(alias, sym)
/** Define ALIASNAME as a weak alias for NAME. If weak aliases are not available, this defines a strong alias */
#define weak_alias(name, aliasname)   _weak_alias((name), (aliasname))
/** Define ALIASNAME as a weak alias for NAME. If weak aliases are not available, this defines a strong alias */
#define __weak_alias(name, aliasname)   _weak_alias((name), (aliasname))
#define __weak_reference(name, aliasname)   _weak_alias((name), (aliasname))
#define weak_reference(name, aliasname)   _weak_alias((name), (aliasname))
/** No versions old versions to worry about */
#define SHLIB_COMPAT(lib, introduced, obsoleted)   0
/** No versions to worry about, just make this the global definition */
#define versioned_symbol(lib, local, symbol, version)   weak_alias(local, symbol)
/** Define ALIASNAME as a strong alias for NAME */
#define strong_alias(name, aliasname)   _strong_alias((name), (aliasname))
/** Define ALIASNAME as a strong alias for NAME */
#define __strong_alias(name, aliasname)   _strong_alias((name), (aliasname))
/** Define ALIASNAME as a strong alias for NAME */
#define __strong_alias__(name, aliasname)   _strong_alias((name), (aliasname))
#define strong_reference(sym, aliassym)   __strong_reference((sym), (aliassym))
#define _strong_reference(sym, aliassym)   __strong_reference((sym), (aliassym))
/** Export the symbol for both static and dynamic linking */
#define libc_sunrpc_symbol(name, aliasname, version)   strong_alias(name, aliasname)
/** Symbols reserved to or specified by ISO C; Defines `name` as a strong alias for _libc_x */
#define DEF_STRONG(name)   _strong_alias((name), HIDDEN((name)))
/** Symbols used internally and not in ISO C; Defines `name` as a weak alias for _libc_x */
#define DEF_WEAK(name)   _weak_alias((name), HIDDEN((name)))
/** Symbols that have a cancellation wrapper; Defines `name` as a weak alias for _libc_x_cancel */
#define DEF_CANCEL(name)   _weak_alias((name), CANCEL((name)))
/** Defines `name` as a weak alias for _libc_x_wrap */
#define DEF_WRAP(name)   _weak_alias((name), WRAP((name)))
/** Defines _thread_sys_x as a strong alias for _libc_x; This should only be needed for syscalls that have C instead of ASM stubs */
#define DEF_SYS(name)   _strong_alias(_thread_sys_##name, HIDDEN((name)))
#if __GNUC__  // strict_weak_alias
#   define __strict_weak_alias(alias, sym)   UNUSED static typeof(alias) *__weak_alias_##alias = &sym; __weak_alias(alias, sym)
#else
#   define __strict_weak_alias(alias, sym)   __weak_alias((alias), (sym))
#endif  // strict_weak_alias
#define strict_weak_alias(alias, sym)   __strict_weak_alias((alias), (sym))
#define _strict_weak_alias(alias, sym)   __strict_weak_alias((alias), (sym))
#define __alias(x)   __attribute__((__weak__, __alias__(x)))
/** Compiler macros to make an alias symbol */
#define __ALIAS(__t, __f, __p, __a)   __t __f __p __attribute__((__weak__, __alias__(#__a)));
// OPERATING SPECIFIC ATTRIBUTES
#if (defined(__GNUC__) && defined(OSWINDOWS))  // These attributes also work on Symbian
/** Reference a function or variable via a global pointer to a pointer that is set up by the DLL exporting the symbol; The attribute implies extern; On Microsoft Windows targets, the pointer name is formed by combining _imp__ and the function or variable name */
#   define dllimport   __attribute__((dllimport))
/** Provide a global pointer to a pointer in a DLL, so that it can be referenced with the dllimport attribute; On Microsoft Windows targets, the pointer name is formed by combining _imp__ and the function or variable name */
#   define dllexport   __attribute__((dllexport))
#else
#   define dllimport
#   define dllexport
#endif
#if (defined(MICROSOFT_VISUAL) && defined(_DLL))
/** On Windows, variables that may be in a DLL must be marked specially */
#   define DLL_VARIABLE   __declspec(dllimport)
#else
/** On Windows, variables that may be in a DLL must be marked specially */
#   define DLL_VARIABLE
#endif


// TARGET ATTRIBUTES AND MACROS

#ifdef __GNUC__
// PowerPC
#   define BUILD_power7   __attribute__((__target__("arch=power7")))
#   define BUILD_power8   __attribute__((__target__("arch=power8")))
#   define BUILD_power9   __attribute__((__target__("arch=power9")))
#   define BUILD_POWER7   __attribute__((__target__("arch=power7")))
#   define BUILD_POWER8   __attribute__((__target__("arch=power8")))
#   define BUILD_POWER9   __attribute__((__target__("arch=power9")))
// x86
#   define BUILD_CORE2   __attribute__((__target__("arch=core2")))
#   define BUILD_PENTIUM4   __attribute__((__target__("arch=pentium4")))
#   define BUILD_SANDYBRIDGE   __attribute__((__target__("arch=sandybridge")))
#   define BUILD_IVYBRIDGE   __attribute__((__target__("arch=ivybridge")))
#   define BUILD_HASWELL   __attribute__((__target__("arch=haswell")))
#   define BUILD_BROADWELL   __attribute__((__target__("arch=broadwell")))
#   define BUILD_SKYLAKE   __attribute__((__target__("arch=skylake")))
#   define BUILD_BONNELL   __attribute__((__target__("arch=bonnell")))
#   define BUILD_SILVERMONT   __attribute__((__target__("arch=silvermont")))
#   define BUILD_KNL   __attribute__((__target__("arch=knl")))
#   define BUILD_MMX   __attribute__((__target__("mmx")))
#   define BUILD_SSE   __attribute__((__target__("sse")))
#   define BUILD_SSE3   __attribute__((__target__("sse3")))
#   define BUILD_SSE4   __attribute__((__target__("sse4")))
#   define BUILD_AVX   __attribute__((__target__("avx")))
#   define BUILD_AVX2   __attribute__((__target__("avx2")))
#else
// PowerPC
#   define BUILD_power7
#   define BUILD_power8
#   define BUILD_power9
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
#   define BUILD_SSE
#   define BUILD_SSE3
#   define BUILD_SSE4
#   define BUILD_AVX
#   define BUILD_AVX2
#endif


// ARCHITECTURE SPECIFIC ATTRIBUTES AND MACROS

#ifdef ___AM29K__
#   define _FLOAT_RET   double
#endif
#ifdef AVR
#   define __SMALL_BITFIELDS
#   define _POINTER_INT   short
#endif
#if (defined(__GNUC__) && defined(I386))  // internal_function, REGPARM, & __compactcall
/** On some platforms, internal function calls are a bit faster by using a different calling convention */
#   define internal_function   __attribute__((__regparm__(3), __stdcall__))
#   define REGPARM(x)   __attribute__((__regparm__(x)))
/** Optional marker for size-optimised MD calling convention */
#   define __compactcall   __attribute__((__regparm__(3)))
#else
#   define internal_function
#   define REGPARM(x)
#   define   __compactcall
#endif  // internal_function, REGPARM, & __compactcall
#if ((defined(X86) || defined(X86_64) || defined(I386)) && IS_WORDSIZE_32)  // cleanup_fct_attribute
/** Extra attributes for the cleanup functions */
#   define __cleanup_fct_attribute   __attribute__((__regparm__(1)))
/** Extra attributes for the cleanup functions */
#   define cleanup_fct_attribute   __attribute__((__regparm__(1)))
#else
#   define __cleanup_fct_attribute
#   define cleanup_fct_attribute
#endif  // cleanup_fct_attribute
#ifdef MICROBLAZE
#   ifndef _REENT_SMALL
#      define _REENT_SMALL   (1)
#   endif
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
#if (defined(MIPS) && (!defined(__rtems__)))
#   define __ATTRIBUTE_IMPURE_PTR__   __attribute__((__section__(".sdata")))
#elif defined(__v850)
#   define __ATTRIBUTE_IMPURE_PTR__   __attribute__((__sda__))
#elif defined(__frv__)
#   define __ATTRIBUTE_IMPURE_PTR__   __attribute__((__section__(".sdata")))
#endif
#ifdef POWERPC
#   define __eh_pc_gcc_272   ((void*)0x0)
#   define __eh_type_gcc_272   ((void*)0x0)
#   define __eh_value_gcc_272   ((void*)0x0)
/** This is what egcs uses for its global data pointer */
#   define __eh_global_dataptr   ((void*)0x0)
#   ifdef _CALL_SYSV
#      define __ATTRIBUTE_IMPURE_PTR__   __attribute__((__section__(".sdata")))
#   endif
#   ifdef __SPE__
#      define _LONG_DOUBLE   double
#   endif
#   ifdef __GNUC__
#      define __pixel   __attribute__((__altivec__(pixel__))) unsigned short
#      define __vector   __attribute__((__altivec__(vector__)))
#   endif
#endif
#ifndef __pixel
#   define __pixel
#endif
#ifndef __vector
#   define __vector
#endif
#ifndef ATTR_VECTOR
#   define ATTR_VECTOR   __vector
#endif
#ifndef __ATTRIBUTE_IMPURE_PTR__
#   define __ATTRIBUTE_IMPURE_PTR__
#endif
#define SUPPORT_PRE_GM_10_5_EXECUTABLES   (POWERPC || I386)


// MISCELLANEOUS MICROSOFT-COMPILER & CLANG MACROS

#ifdef MICROSOFT_VISUAL  // _DECLSPEC_INTRIN_TYPE
#   define _DECLSPEC_INTRIN_TYPE   __declspec(intrin_type)
#else
#   define _DECLSPEC_INTRIN_TYPE
#endif
#if (defined(COMPILER_MICROSOFT) || defined(COMPILER_CLANG))  // DECLSPEC_HOTPATCH
/** Define to a function attribute for Microsoft hotpatch assembly prefix */
#   define DECLSPEC_HOTPATCH
#else
/** Define to a function attribute for Microsoft hotpatch assembly prefix */
#   define DECLSPEC_HOTPATCH   __attribute__((__ms_hook_prologue__))
#endif  // DECLSPEC_HOTPATCH


// MISCELLANEOUS GNU-GCC & CLANG MACROS

#if __GNUC__
#   define os_constant(x)   __builtin_constant_p((x))
/** A barrier to stop the optimizer from moving code or assume live register values */
#   define __insn_barrier()   asm volatile (";" : : : "memory")
#else
#   define os_constant(x)   ((long)0x0)
/** A barrier to stop the optimizer from moving code or assume live register values */
#   define __insn_barrier()
#endif
/** A barrier to stop the optimizer from moving code or assume live register values */
#define insn_barrier()   __insn_barrier()
#if (AT_LEAST_GCC2_97 || IS_STDC_1999)  // __flexarr
/** Flexible array members */
#   define __flexarr   []
#else
/** Flexible array members */
#   define __flexarr   [1]
#endif
#if AT_LEAST_GCC41  // returns_twice
#   define __returns_twice__   __attribute__((__returns_twice__))
#else
#   define __returns_twice__
#endif
#ifndef returns_twice
#   define returns_twice   __returns_twice__
#endif
#if AT_LEAST_GCC43  // __attribute_artificial__ & __attribute_alloc_size__
#   define attr_artificial   __attribute__((__artificial__))
/** Tell the compiler which arguments to an allocation function indicate the size of the allocation */
#   define __attribute_alloc_size__(...)   __attribute__((__alloc_size__(__VA_ARGS__)))
#else
/** Tell the compiler which arguments to an allocation function indicate the size of the allocation */
#   define __attribute_alloc_size__(...)
#endif
#define __attribute_artificial__   attr_artificial
#define __attribute_artificial   attr_artificial
/** Tell the compiler which arguments to an allocation function indicate the size of the allocation */
#define attribute_alloc_size(...)   __attribute_alloc_size__((__VA_ARGS__))
/** Tell the compiler which arguments to an allocation function indicate the size of the allocation */
#define attr_alloc_size(...)   __attribute_alloc_size__((__VA_ARGS__))
/** Tell the compiler which arguments to an allocation function indicate the size of the allocation */
#define _GL_ATTRIBUTE_ALLOC_SIZE(...)   __attribute_alloc_size__((__VA_ARGS__))
#if AT_LEAST_GCC45  // __noclone
#   define __noclone__   __attribute__((__noclone__))
#else
#   define __noclone__
#endif
#if AT_LEAST_GCC46  // All functions, except those with callbacks or those that synchronize memory, are leaf functions
#   define __LEAF   , __leaf__
#   define __LEAF_ATTR   __attribute__((__leaf__))
#else
#   define __LEAF
#   define __LEAF_ATTR
#endif
#ifdef COMPILER_CLANG  // PRAGMAS
/** Selectively ignore cast alignment warnings */
#   define __IGNORE_WCASTALIGN(x)   _Pragma("clang diagnostic push") \n _Pragma("clang diagnostic ignored \"-Wcast-align\"") \n  x; \n _Pragma("clang diagnostic pop")
/** Push diagnostic state */
#   define DIAG_PUSH_NEEDS_COMMENT _Pragma ("clang diagnostic push")
/** Pop diagnostic state */
#   define DIAG_POP_NEEDS_COMMENT _Pragma ("clang diagnostic pop")
/** Ignore the diagnostic OPTION */
#   define DIAG_IGNORE_NEEDS_COMMENT(version, _option)   _Pragma (_DIAG_STR(clang diagnostic ignored _option))
#elif defined(__GNUC__)
/** Selectively ignore cast alignment warnings */
#   define __IGNORE_WCASTALIGN(x)   _Pragma("gcc diagnostic push") \n _Pragma("gcc diagnostic ignored \"-Wcast-align\"") \n  x; \n _Pragma("gcc diagnostic pop")
/** Push diagnostic state */
#   define DIAG_PUSH_NEEDS_COMMENT _Pragma ("gcc diagnostic push")
/** Pop diagnostic state */
#   define DIAG_POP_NEEDS_COMMENT _Pragma ("gcc diagnostic pop")
/** Ignore the diagnostic OPTION */
#   define DIAG_IGNORE_NEEDS_COMMENT(version, _option)   _Pragma (_DIAG_STR(gcc diagnostic ignored _option))
#else
#   define __IGNORE_WCASTALIGN(x)  x;
#   define DIAG_PUSH_NEEDS_COMMENT
#   define DIAG_POP_NEEDS_COMMENT
#   define DIAG_IGNORE_NEEDS_COMMENT(version, _option)
#endif  // PRAGMAS
#define IGNORE_WCASTALIGN(x)   __IGNORE_WCASTALIGN((x))
#if (defined(__extern_always_inline) && !defined(__fortify_function))  // __fortify_function
#   define __fortify_function   __extern_always_inline __attribute_artificial__
#endif


// MISCELLANEOUS MACROS

#undef __UNCONST
/** The following macro is used to remove const cast-away warnings from `-Wcast-qual`; this should be used with caution because it can hide valid errors */
#define __UNCONST(a)   ((void*)(unsigned long)(const void*)(a))
#undef __UNVOLATILE
/** The following macro is used to remove the volatile cast-away warnings from `-Wcast-qual`; this should be used with caution because it can hide valid errors or warnings */
#define __UNVOLATILE(a)   ((void*)(unsigned long)(volatile void*)(a))
#if (defined(_KERNEL) && defined(NO_KERNEL_RCSIDS))  // __KERNEL_RCSID
#   undef __KERNEL_RCSID
#   define __KERNEL_RCSID(_n, _s)
#endif  // __KERNEL_RCSID
/** Compile Time Assertion */
#define __CTASSERT1(x, y, z)   typedef char y ## z[(x) ? 1 : (-1)] UNUSED
/** Compile Time Assertion */
#define __CTASSERT0(x, y, z)   __CTASSERT1(x, y, z)
#ifdef __COUNTER__
/** Compile Time Assertion */
#   define __CTASSERT(x)   __CTASSERT0(x, __ctassert, __COUNTER__)
#else
/** Compile Time Assertion */
#   define __CTASSERT99(x, a, b)   __CTASSERT0(x, __CONCAT(__ctassert, a), __CONCAT(_, b))
/** Compile Time Assertion */
#   define __CTASSERT(x)   __CTASSERT99(x, __INCLUDE_LEVEL__, __LINE__)
#endif
#define __IDSTRING(name, _string)   static const UNUSED char name[] = _string
#ifndef __COPYRIGHT
#   define __COPYRIGHT(x) __IDSTRING(copyright, x)
#endif
#ifndef __RCSID
#   define __RCSID(x) __IDSTRING(rcsid, x)
#endif
#ifndef __SCCSID
#   define __SCCSID(x) __IDSTRING(sccsid, x)
#endif
#ifndef __PROJECT_VERSION
#   define __PROJECT_VERSION(x)   __IDSTRING(project_version, x)
#endif
#ifndef __FBSDID
#   define __FBSDID(x)
#endif
/** Ignore the value of an expression when a cast to void does not suffice (in particular, for a call to a function declared with attribute warn_unused_result) */
#define ignore_value(x)   __extension__ ({ typeof(x) __ignored_value = (x); (void)__ignored_value; })
/** Return a pointer (void *const*) to the first element of SET */
#define symbol_set_first_element(set)   ((void* const*)(&__start_##set))
/** Return true if PTR (a void *const*) has been incremented past the last element in SET */
#define symbol_set_end_p(set, ptr)   ((ptr) >= (void* const*) &__stop_##set)
#define PTR_TO_INT(PTR)   ((size_t)((char*)(PTR) - (char*)NULL))


// ASSEMBLY MACROS

#define __CLOBBER_CC   : "cc"
#define CLOBBER_CC   : "cc"
#define __AND_CLOBBER_CC   , "cc"
#define AND_CLOBBER_CC   , "cc"
#ifdef __GNUC__
#   if IS_NOT_ASSEMBLER  // Move compatibility symbols out of the way by placing them all in a special section
#      define attribute_compat_text_section   __attribute__((__section__(".text.compat")))
#      define attribute_compat_data_section   __attribute__((__section__(".data.compat")))
#   else
#      define compat_text_section   .section ".text.compat", "ax";
#      define compat_data_section   .section ".data.compat", "aw";
#   endif
/** Marker used for indirection function symbols */
#   define libc_ifunc(name, expr)   extern void *name##_ifunc (void) asm (#name); void *name##_ifunc (void) { INIT_ARCH (); typeof(name) *res = expr; return res; } asm (".type " #name ", %gnu_indirect_function");
/** The body of the function is supposed to use __get_cpu_features which will, if necessary, initialize the data first */
#   define libm_ifunc(name, expr)   extern void *name##_ifunc (void) asm (#name); void *name##_ifunc (void) { typeof(name) *res = expr; return res; } asm (".type " #name ", %gnu_indirect_function");
#   define attribute_tls_model_ie   __attribute__((__tls_model__("initial-exec")))
#   define attribute_relro   __attribute__((__section__(".data.rel.ro")))
#   define attribute_hidden   __attribute__((__visibility__("hidden")))
/** Make SYMBOL, which is in the text segment, an element of SET */
#   define text_set_element(set, symbol)   _elf_set_element(set, symbol)
/** Make SYMBOL, which is in the data segment, an element of SET */
#   define data_set_element(set, symbol)   _elf_set_element(set, symbol)
/** Make SYMBOL, which is in the bss segment, an element of SET */
#   define bss_set_element(set, symbol)   _elf_set_element(set, symbol)
// These are all done the same way in ELF; There is a new section created for each set
#   ifdef SHARED
/** When building a shared library, make the set section writable, because it will need to be relocated at run time anyway */
#      define _elf_set_element(set, symbol)   static const void *__elf_set_##set##_element_##symbol##__ __attribute__((used, section (#set))) = &(symbol)
#   else
/** When building a shared library, make the set section writable, because it will need to be relocated at run time anyway */
#      define _elf_set_element(set, symbol)   static const void *const __elf_set_##set##_element_##symbol##__ __attribute__((used, section (#set))) = &(symbol)
#   endif
#else  // Not GNU-GCC
#   define libc_ifunc(name, expr)
#   define libm_ifunc(name, expr)
#   define attribute_compat_text_section
#   define attribute_compat_data_section
#   define compat_text_section
#   define compat_data_section
#   define attribute_tls_model_ie
#   define attribute_relro
#   define attribute_hidden
#   define text_set_element(set, symbol)
#   define data_set_element(set, symbol)
#   define bss_set_element(set, symbol)
#   define _elf_set_element(set, symbol)
#endif
#ifndef ATTRIBUTE_HIDDEN
#   define ATTRIBUTE_HIDDEN   attribute_hidden
#endif
#ifndef attr_hidden
#   define attr_hidden   attribute_hidden
#endif
#if IS_NOT_ASSEMBLER
#   define link_warning(symbol, msg)   asm (".section .gnu.warning." symbol "\n\t.string \"" msg "\"\n\t.previous");
#else
#   define link_warning(symbol,msg)   .section .gnu.warning.##symbol ; .string msg ; .previous
#endif
/** Define or declare a datum with TYPE for KEY; CLASS can be `static` for keys used in only one source file, empty for global definitions, or `extern` for global declarations */
#define __libc_tsd_define(CLASS, TYPE, KEY)   CLASS Thread_local TYPE __libc_tsd_##KEY attribute_tls_model_ie;
/** Return the `TYPE *` pointing to the current thread's datum for KEY */
#define __libc_tsd_address(TYPE, KEY)   (&__libc_tsd_##KEY)
/** Return the `TYPE` datum for KEY */
#define __libc_tsd_get(TYPE, KEY)   (__libc_tsd_##KEY)
/** Set the datum for KEY to VALUE */
#define __libc_tsd_set(TYPE, KEY, VALUE)   (__libc_tsd_##KEY = (VALUE))
#if (defined(SHARED) && (!defined(NO_HIDDEN)) && IS_ISOC)  // hidden
#   if IS_NOT_ASSEMBLER
#      define __hidden_proto_hiddenattr(attrs...)   __attribute__((__visibility__("hidden"), __VA_ARGS__))
#      define hidden_proto(name, ...)   __hidden_proto(name, , __GI_##name, __VA_ARGS__)
#      define hidden_tls_proto(name, ...)   __hidden_proto(name, Thread_local, __GI_##name, __VA_ARGS__)
#      define __hidden_proto(name, thread, internal, ...)   extern thread typeof(name) name asm (__hidden_asmname(#internal)) __hidden_proto_hiddenattr (attrs);
#      define __hidden_asmname(name)   __hidden_asmname1(__USER_LABEL_PREFIX__, name)
#      define __hidden_asmname1(prefix, name)   __hidden_asmname2(prefix, name)
#      define __hidden_asmname2(prefix, name)   #prefix name
#      define __hidden_ver1(local, internal, name)   extern typeof(name) __EI_##name asm(__hidden_asmname(#internal)); extern typeof(name) __EI_##name __attribute__((__alias__(__hidden_asmname(#local))))
#      define hidden_ver(local, name)   __hidden_ver1(local, __GI_##name, name);
#      define hidden_data_ver(local, name)   hidden_ver(local, name)
#      define hidden_def(name)   __hidden_ver1(__GI_##name, name, name);
#      define hidden_data_def(name)   hidden_def(name)
#      define hidden_weak(name)   __hidden_ver1(__GI_##name, name, name) __attribute__((__weak__));
#      define hidden_data_weak(name)   hidden_weak(name)
#      define hidden_nolink(name, lib, version)   __hidden_nolink1 (__GI_##name, __EI_##name, name, VERSION_##lib##_##version)
#      define __hidden_nolink1(local, internal, name, version)   __hidden_nolink2 (local, internal, name, version)
#      define __hidden_nolink2(local, internal, name, version)   extern typeof(name) internal __attribute__((alias (#local)));  __hidden_nolink3 (local, internal, #name "@" #version)
#      define __hidden_nolink3(local, internal, vername)   asm (".symver " #internal ", " vername);
#   else  // IS_ASSEMBLER
#      define hidden_def(name)   strong_alias(name, __GI_##name)
#      define hidden_weak(name)   hidden_def(name)
#      define hidden_ver(local, name)   strong_alias(local, __GI_##name)
#      define hidden_data_def(name)   strong_data_alias(name, __GI_##name)
#      define hidden_data_weak(name)   hidden_data_def(name)
#      define hidden_data_ver(local, name)   strong_data_alias(local, __GI_##name)
#      define HIDDEN_JUMPTARGET(name)   __GI_##name
#   endif  // IS_ASSEMBLER
#else  // (defined(SHARED) && !defined(NO_HIDDEN))
#   if (IS_NOT_ASSEMBLER && IS_ISOC)
#      define hidden_proto(name, ...)
#      define hidden_tls_proto(name, ...)
#   else
#      define HIDDEN_JUMPTARGET(name)   JUMPTARGET(name)
#   endif  // IS_ASSEMBLER
#   define hidden_weak(name)
#   define hidden_def(name)
#   define hidden_ver(local, name)
#   define hidden_data_weak(name)
#   define hidden_data_def(name)
#   define hidden_data_ver(local, name)
#   define hidden_nolink(name, lib, version)
#endif  // hidden
#define libc_hidden_proto(name, ...)   hidden_proto(name, __VA_ARGS__)
#define libc_hidden_tls_proto(name, ...)   hidden_tls_proto(name, __VA_ARGS__)
#define libc_hidden_def(name)   hidden_def(name)
#define libc_hidden_weak(name)   hidden_weak(name)
#define libc_hidden_ver(local, name)   hidden_ver(local, name)
#define libc_hidden_data_def(name)   hidden_data_def(name)
#define libc_hidden_data_weak(name)   hidden_data_weak(name)
#define libc_hidden_data_ver(local, name)   hidden_data_ver(local, name)
#define rtld_hidden_proto(name, ...)   hidden_proto(name, __VA_ARGS__)
#define rtld_hidden_tls_proto(name, ...)   hidden_tls_proto(name, __VA_ARGS__)
#define rtld_hidden_def(name)   hidden_def(name)
#define rtld_hidden_weak(name)   hidden_weak(name)
#define rtld_hidden_ver(local, name)   hidden_ver(local, name)
#define rtld_hidden_data_def(name)   hidden_data_def(name)
#define rtld_hidden_data_weak(name)   hidden_data_weak(name)
#define rtld_hidden_data_ver(local, name)   hidden_data_ver(local, name)
#define libm_hidden_proto(name, ...)   hidden_proto(name, __VA_ARGS__)
#define libm_hidden_tls_proto(name, ...)   hidden_tls_proto(name, __VA_ARGS__)
#define libm_hidden_def(name)   hidden_def(name)
#define libm_hidden_weak(name)   hidden_weak(name)
#define libm_hidden_ver(local, name)   hidden_ver(local, name)
#define libm_hidden_data_def(name)   hidden_data_def(name)
#define libm_hidden_data_weak(name)   hidden_data_weak(name)
#define libm_hidden_data_ver(local, name)   hidden_data_ver(local, name)
#define libmvec_hidden_proto(name, ...)   hidden_proto(name, __VA_ARGS__)
#define libmvec_hidden_tls_proto(name, ...)   hidden_tls_proto(name, __VA_ARGS__)
#define libmvec_hidden_def(name)   hidden_def(name)
#define libmvec_hidden_weak(name)   hidden_weak(name)
#define libmvec_hidden_ver(local, name)   hidden_ver(local, name)
#define libmvec_hidden_data_def(name)   hidden_data_def(name)
#define libmvec_hidden_data_weak(name)   hidden_data_weak(name)
#define libmvec_hidden_data_ver(local, name)   hidden_data_ver(local, name)
#define libresolv_hidden_proto(name, ...)   hidden_proto(name, __VA_ARGS__)
#define libresolv_hidden_tls_proto(name, ...)   hidden_tls_proto(name, __VA_ARGS__)
#define libresolv_hidden_def(name)   hidden_def(name)
#define libresolv_hidden_weak(name)   hidden_weak(name)
#define libresolv_hidden_ver(local, name)   hidden_ver(local, name)
#define libresolv_hidden_data_def(name)   hidden_data_def(name)
#define libresolv_hidden_data_weak(name)   hidden_data_weak(name)
#define libresolv_hidden_data_ver(local, name)   hidden_data_ver(local, name)
#define librt_hidden_proto(name, ...)   hidden_proto(name, __VA_ARGS__)
#define librt_hidden_tls_proto(name, ...)   hidden_tls_proto(name, __VA_ARGS__)
#define librt_hidden_def(name)   hidden_def(name)
#define librt_hidden_weak(name)   hidden_weak(name)
#define librt_hidden_ver(local, name)   hidden_ver(local, name)
#define librt_hidden_data_def(name)   hidden_data_def(name)
#define librt_hidden_data_weak(name)   hidden_data_weak(name)
#define librt_hidden_data_ver(local, name)   hidden_data_ver(local, name)
#define libdl_hidden_proto(name, ...)   hidden_proto(name, __VA_ARGS__)
#define libdl_hidden_tls_proto(name, ...)   hidden_tls_proto(name, __VA_ARGS__)
#define libdl_hidden_def(name)   hidden_def(name)
#define libdl_hidden_weak(name)   hidden_weak(name)
#define libdl_hidden_ver(local, name)   hidden_ver(local, name)
#define libdl_hidden_data_def(name)   hidden_data_def(name)
#define libdl_hidden_data_weak(name)   hidden_data_weak(name)
#define libdl_hidden_data_ver(local, name)   hidden_data_ver(local, name)
#define libnss_files_hidden_proto(name, ...)   hidden_proto(name, __VA_ARGS__)
#define libnss_files_hidden_tls_proto(name, ...)   hidden_tls_proto(name, __VA_ARGS__)
#define libnss_files_hidden_def(name)   hidden_def(name)
#define libnss_files_hidden_weak(name)   hidden_weak(name)
#define libnss_files_hidden_ver(local, name)   hidden_ver(local, name)
#define libnss_files_hidden_data_def(name)   hidden_data_def(name)
#define libnss_files_hidden_data_weak(name)   hidden_data_weak(name)
#define libnss_files_hidden_data_ver(local, name)   hidden_data_ver(local, name)
#define libnsl_hidden_proto(name, ...)   hidden_proto(name, __VA_ARGS__)
#define libnsl_hidden_tls_proto(name, ...)   hidden_tls_proto(name, __VA_ARGS__)
#define libnsl_hidden_def(name)   hidden_def(name)
#define libnsl_hidden_weak(name)   hidden_weak(name)
#define libnsl_hidden_ver(local, name)   hidden_ver(local, name)
#define libnsl_hidden_data_def(name)   hidden_data_def(name)
#define libnsl_hidden_data_weak(name)   hidden_data_weak(name)
#define libnsl_hidden_data_ver(local, name)   hidden_data_ver(local, name)
#define libnss_nisplus_hidden_proto(name, ...)   hidden_proto(name, __VA_ARGS__)
#define libnss_nisplus_hidden_tls_proto(name, ...)   hidden_tls_proto(name, __VA_ARGS__)
#define libnss_nisplus_hidden_def(name)   hidden_def(name)
#define libnss_nisplus_hidden_weak(name)   hidden_weak(name)
#define libnss_nisplus_hidden_ver(local, name)   hidden_ver(local, name)
#define libnss_nisplus_hidden_data_def(name)   hidden_data_def(name)
#define libnss_nisplus_hidden_data_weak(name)   hidden_data_weak(name)
#define libnss_nisplus_hidden_data_ver(local, name)   hidden_data_ver(local, name)
#define libutil_hidden_proto(name, ...)   hidden_proto(name, __VA_ARGS__)
#define libutil_hidden_tls_proto(name, ...)   hidden_tls_proto(name, __VA_ARGS__)
#define libutil_hidden_def(name)   hidden_def(name)
#define libutil_hidden_weak(name)   hidden_weak(name)
#define libutil_hidden_ver(local, name)   hidden_ver(local, name)
#define libutil_hidden_data_def(name)   hidden_data_def(name)
#define libutil_hidden_data_weak(name)   hidden_data_weak(name)
#define libutil_hidden_data_ver(local, name)   hidden_data_ver(local, name)
#define libc_hidden_builtin_proto(name, ...)   libc_hidden_proto(name, __VA_ARGS__)
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
#define libc_ifunc_hidden_def(name)   libc_ifunc_hidden_def1(__GI_##name, name)
#ifdef HAVE_ASM_PREVIOUS_DIRECTIVE
#   define __make_section_unallocated(section_string)   asm (".section " section_string "\n\t.previous");
#elif defined(HAVE_ASM_POPSECTION_DIRECTIVE)
#   define __make_section_unallocated(section_string)   asm (".pushsection " section_string "\n\t.popsection");
#else
#   define __make_section_unallocated(section_string)
#endif
#define libc_hidden_builtin_def(name)   libc_hidden_def(name)
#define libc_hidden_builtin_weak(name)   libc_hidden_weak(name)
#define libc_hidden_builtin_ver(local, name)   libc_hidden_ver(local, name)
#define ASM_GLOBAL_DIRECTIVE   .global


// LINK SET MACROS

#define __link_set_start(set)   (__start_link_set_##set)
#define __link_set_end(set)   (__stop_link_set_##set)
#define __link_set_count(set)   (__link_set_end(set) - __link_set_start(set))
#define __link_set_make_entry(set, sym)   static void const * const __link_set_##set##_sym_##sym __section("link_set_" #set) UNUSED = &sym
#define __link_set_make_entry2(set, sym, n)   static void const * const __link_set_##set##_sym_##sym##_##n __section("link_set_" #set) UNUSED = &sym[n]
#define __link_set_add_text(set, sym)   __link_set_make_entry(set, sym)
#define __link_set_add_rodata(set, sym)   __link_set_make_entry(set, sym)
#define __link_set_add_data(set, sym)   __link_set_make_entry(set, sym)
#define __link_set_add_bss(set, sym)   __link_set_make_entry(set, sym)
#define __link_set_add_text2(set, sym, n)   __link_set_make_entry2(set, sym, n)
#define __link_set_add_rodata2(set, sym, n)   __link_set_make_entry2(set, sym, n)
#define __link_set_add_data2(set, sym, n)   __link_set_make_entry2(set, sym, n)
#define __link_set_add_bss2(set, sym, n)   __link_set_make_entry2(set, sym, n)
#define __link_set_decl(set, ptype)   extern ptype * const __start_link_set_##set[]; extern ptype * const __stop_link_set_##set[]
/** Iterate over the link set `set`; Because a link set is an array of pointers, pvar must be declared as `type **pvar`, and the actual entry accessed as `*pvar` */
#define __link_set_foreach(pvar, set)   for (pvar = __link_set_start(set); pvar < __link_set_end(set); pvar++)
/** Access the link set entry at index `idx` from set `set` */
#define __link_set_entry(set, idx)   (__link_set_begin(set)[idx])


// SPECIAL HURD PROCESSES

#if (!(defined(HURD_PROCESSES_H) || defined(_HURD_PROCESSES_H) || defined(_HURD_PROCESSES_H_)))
#define HURD_PROCESSES_H   (1)
#define _HURD_PROCESSES_H   (1)
#define _HURD_PROCESSES_H_   (1)


#define HURD_PID_INIT   1
#define HURD_PID_STARTUP   2
#define HURD_PID_KERNEL   3
#define HURD_PID_PROC   4


#endif  // HURD_PROCESSES_H


// PYBOOSTER LIBRARY INTERFACE MACROS

#ifndef LIB_FUNC
#   ifdef LIB_NO_DYNAMIC
#      define LIB_FUNC   UNUSED
#   elif defined(LIB_NO_INLINE)
#      define LIB_FUNC   static UNUSED
#   else
#      define LIB_FUNC   static UNUSED
#   endif
#endif
#ifndef DECL_FUNC
#   ifdef LIB_FUNC
#      define DECL_FUNC   LIB_FUNC
#   else
#      define DECL_FUNC   static UNUSED
#   endif
#endif
#ifdef __GNUC__  // MATHX_FUNC_ATTR & MATH_FUNC_ATTR
#   define MATHX_FUNC_ATTR   __attribute__((__const__, __flatten__))
#   define MATH_FUNC_ATTR   __attribute__((__const__, __flatten__))
#else
#   define MATHX_FUNC_ATTR
#   define MATH_FUNC_ATTR
#endif


// CILK MACROS

#if ((!defined(cilk_spawn)) && (!defined(cilk_sync)))
/** Spawn a task that can execute in parallel */
#   define cilk_spawn   _Cilk_spawn
/** Wait for spawned tasks to complete */
#   define cilk_sync   _Cilk_sync
/** Execute iterations of a for loop in parallel */
#   define cilk_for   _Cilk_for
#endif


// HELPER FUNCTIONS, CONSTANTS, & VARIABLES

/** Calculate maximum length */
#define max_int_length(x)   ((int)((int)(((((int)(x)) * 8) - 1) * 0.30102999566398119521) + 14))
#define RELOC_HIDE(ptr, off)   do { unsigned long __ptr; asm (";" : "=r"(__ptr) : "0"(ptr)); (typeof(ptr))(__ptr + (off)); } while (0x0)
#define OPTIMIZER_HIDE_VAR(var)   asm (";" : "=r"(var) : "0"(var))
#define asm_volatile_goto(x)   do { asm goto((x)); asm (";"); } while (0x0)
#ifndef __native_word
#   define __native_word(t)   (sizeof(t) == SIZEOF_CHAR || sizeof(t) == SIZEOF_SHORT || sizeof(t) == SIZEOF_INT || sizeof(t) == SIZEOF_LONG || sizeof(t) == SIZEOF_LONG_LONG)
#endif
#ifndef is_native_word
#   define is_native_word(x)   __native_word((x))
#endif


#if (SUPPORTS_LONG_DOUBLE && (!defined(_LONG_DOUBLE)))
#   define _LONG_DOUBLE   long double
#   define LDOUBLE   long double
#endif


/** Defeat compiler optimizations that assume function addresses are never NULL */
LIB_FUNC int not_null_ptr(const void* restrict ptr) {
	const void* q;
	asm (";" : "=r"(q) : "0"(ptr));
	return (int)(q != 0);
}


static const UNUSED unsigned char integer_table[264] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
	25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
	25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
/** Pad chunk size */
#define PADSIZE   (16)
static const UNUSED char blanks[PADSIZE] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
static const UNUSED char zeroes[PADSIZE] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
#define _ALPHABET   "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0"
#define _alphabet   "abcdefghijklmnopqrstuvwxyz\0"
#define _numbers   "0123456789\0"
#define _digits   _numbers
#define _hexnumbers   "0123456789ABCDEFabcdef\0"
#define _hexdigits   _hexnumbers
static const UNUSED int positive_tens[8] = { 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
static const UNUSED char a64l_digits[] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static const UNUSED char digits[16] = "0123456789\0";
#define str_digit   digits
static const UNUSED char hexdigits[32] = _hexnumbers;
#define xdigits   hexdigits
static const UNUSED char xdigits_l[32] = "0123456789abcdef\0";
static const UNUSED char xdigits_u[32] = "0123456789ABCDEF\0";
#define hexdigits_l   xdigits_l
#define hexdigits_u   xdigits_u
static const UNUSED char ALPHABET[32] = _ALPHABET;
static const UNUSED char alphabet[32] = _alphabet;
/** Upper-case digits */
static const UNUSED char _itoa_upper_digits[64] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
/** Lower-case digits */
static const UNUSED char _itoa_lower_digits[64] = "0123456789abcdefghijklmnopqrstuvwxyz\0";
static const UNUSED char not_available[4] = "\377";
static const UNUSED char empty[] = "";
static const UNUSED char null_char[] = "\0";
/** The set of "direct characters": A-Z a-z 0-9 ' ( ) , - . / : ? space tab lf cr */
static const UNUSED unsigned char direct_tab[16] = {
	0, 0x26, 0, 0, 0x81, 0xf3, 0xff, 0x87, 0xfe, 0xff, 0xff, 7, 0xfe, 0xff, 0xff, 7
};
/** The set of "direct and optional direct characters": A-Z a-z 0-9 ' ( ) , - . / : ? space tab lf cr ! " # $ % & * ; < = > @ [ ] ^ _ ` { | } */
static const UNUSED unsigned char xdirect_tab[16] = {
	0, 0x26, 0, 0, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0x3f
};
/** The set of "extended base64 characters": A-Z a-z 0-9 + / - */
static const UNUSED unsigned char xbase64_tab[16] = {
	0, 0, 0, 0, 0, 0xa8, 0xff, 3, 0xfe, 0xff, 0xff, 7, 0xfe, 0xff, 0xff, 7
};
static const UNUSED int nibblemap[16] = { 4, 3, 3, 2, 3, 2, 2, 1, 3, 2, 2, 1, 2, 1, 1, 0 };
#define A64L_TABLE_BASE   0x2e
#define A64L_TABLE_SIZE   0x4d
static const UNUSED char a64l_table[0x4d] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
	0x40, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
	27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 0x40, 0x40, 0x40, 0x40, 0x40,
	0x40, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
	53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63
};
UNUSED char** environ = NULL;
#define __environ   environ
#define ___environ   environ
#define _environ   environ
#define environ   environ
UNUSED char** __env_map = NULL;
static UNUSED int exit_counter;
static UNUSED int slot;
static volatile UNUSED int lock[2];
extern UNUSED unsigned int __page_size;
extern UNUSED unsigned int __page_shift;


// MISCELLANEOUS GLOBAL CODE

#define __getpagesize()   ((unsigned int)__page_size)
#define getpagesize()   ((unsigned int)__page_size)
#define __getpageshift()   ((unsigned int)__page_shift)
#define getpageshift()   ((unsigned int)__page_shift)


#endif  // STANDARD_MACROS_SEEN


#include "MACROS2.h"
#include "MACROS3.h"

#!/usr/bin/make -f
# Makefile constants header (contains common code)
# Version 2016.03.18


## VERSION TIMESTAMP ##


__MODULE_VERSION__=\"`date +"%Y.%m.%d"`\"


## CONSTANTS ##


.PHONY : doxy

doxy :
	-@doxywizard ./Doxyfile; chmod --quiet 644 ./lib/Doxyfile

ifndef OS
	override OS::=
endif
LC_ALL::=en_US.UTF-8
LANG::=en_US.UTF-8
LANGUSA::=en
override SHELL::=/bin/sh
override INCLUDEGTK::=-I/usr/include/pygobject-3.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/gobject-introspection-1.0 -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12
override LINKGTK::=-lglib-2.0 -lgobject-2.0 -lgirepository-1.0 -lX11 -lcairo -lpango-1.0
override POSIX_INCLUDE::=-I/usr/include -I/usr/local/include
override POSIX_LINK::=-L/usr/lib -L/usr/local/lib
ifndef OMP_THREAD_LIMIT
	OMP_THREAD_LIMIT::=4
endif
override LLVM_WARN::=-Wall -Wextra -pedantic -Wformat -Werror=format-security -Wformat-nonliteral -Wformat-non-iso -Wformat-y2k -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wstrict-overflow=5 -Wuninitialized -Wshadow -Wpointer-arith -Wcast-align -Wcast-qual -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -Wconversion -Wbad-function-cast -Wmissing-include-dirs -Wswitch-enum -Wswitch-bool -Winit-self -Wundef -Wdate-time -Wpacked -Winvalid-pch -Wdisabled-optimization -Wstack-protector
override STRIP_PARAMS::=--strip-debug --strip-unneeded --discard-locals --remove-section=.eh_frame --remove-section=.eh_frame_hdr --remove-section=.note --remove-section=.note.ABI-tag --remove-section=.note.gnu.build-id --remove-section=.comment --remove-section=.gnu.version --remove-section=.jcr --remove-section=.line --remove-section=.stab --remove-section=.stabstr
override CHMOD::=chmod --quiet


## INCLUDES ##


armandroideabi_include::=-I/usr/arm-linux-androideabi/include
armandroideabi_lib::=-L/usr/arm-linux-androideabi/lib

armgnueabi_include::=-I/usr/arm-linux-gnueabi/include
armgnueabi_lib::=-L/usr/arm-linux-gnueabi/lib -L/usr/arm-linux-gnueabihf/libsf

armgnueabihf_include::=-I/usr/arm-linux-gnueabi/include
armgnueabihf_lib::=-L/usr/arm-linux-gnueabihf/lib

armgnueabisf_include::=-I/usr/arm-linux-gnueabi/include
armgnueabisf_lib::=-L/usr/arm-linux-gnueabi/lib -L/usr/arm-linux-gnueabihf/libsf

mingw32_include::=-I/usr/i686-w64-mingw32/include
mingw32_lib::=-L/usr/i686-w64-mingw32/lib

mingw64_include::=-I/usr/x86_64-w64-mingw32/include
mingw64_lib::=-L/usr/x86_64-w64-mingw32/lib


## WARNINGS ##


ifdef WARN
	ifeq ($(WARN),1)
		override WARN::=-Wall -Wextra -pedantic -Wformat -Werror=format-security -Wformat-nonliteral -Wformat-signedness -Wformat-y2k -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wstrict-overflow=5 -Wuninitialized -Wshadow -Wpointer-arith -Wcast-align -Wcast-qual -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -Wconversion -Wbad-function-cast -Wdouble-promotion -Wmissing-include-dirs -Wswitch-enum -Wswitch-bool -Wsync-nand -Winit-self -Wsuggest-final-types -Wsuggest-final-methods -Wundef -Wdate-time -Wjump-misses-init -Wlogical-op -Wopenmp-simd -Wpacked -Winvalid-pch -Wunsafe-loop-optimizations -Wvector-operation-performance -Wdisabled-optimization -Wstack-protector -Wswitch-default -Wpadded
	else ifeq ($(WARN),2)
		override WARN::=-Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wnested-externs -Winline -Wuninitialized -Wconversion -Wstrict-prototypes -Wbad-function-cast -Wdouble-promotion
	else ifeq ($(WARN),3)
		override WARN::=-Wtraditional
	else
		override WARN::=-Wall -Wextra -pedantic
	endif
else
	WARN::=-Wall -Wextra
endif


## OPTIMIZATION FLAGS ##


EXPERIMENT::=-fira-loop-pressure -floop-nest-optimize -floop-parallelize-all -ftree-parallelize-loops=4 -floop-strip-mine -fgraphite-identity -fdevirtualize-speculatively -fdevirtualize-at-ltrans -ffast-math -funsafe-math-optimizations -funsafe-loop-optimizations -fopenacc -fgnu-tm -fgcse-sm -fgcse-las -fmove-loop-invariants -fbranch-target-load-optimize2 -fmodulo-sched -fmodulo-sched-allow-regmoves -freschedule-modulo-scheduled-loops -fselective-scheduling -fselective-scheduling2 -fsel-sched-pipelining -fsel-sched-pipelining-outer-loops -fsel-sched-reschedule-pipelined
EXPERIMENT2::=-fno-exceptions -fmerge-all-constants -fno-stack-protector -funroll-all-loops
EXPERIMENT3::=-ffast-math -ftree-parallelize-loops=4 -fgcse-sm -fgcse-las -fmove-loop-invariants -fbranch-target-load-optimize2 -fopenmp $(EXPERIMENT)

ifdef XOPTMZ
	ifeq ($(XOPTMZ),1)
		override XOPTMZ::=-fno-signed-zeros -fno-math-errno -fno-signaling-nans -ftree-vectorize -ffinite-math-only -mlong-double-128
	else ifeq ($(XOPTMZ),2)
		override XOPTMZ::=-fno-signed-zeros -fno-rounding-math -fno-trapping-math -fno-math-errno -fno-signaling-nans -fcx-limited-range -ffinite-math-only
	else ifeq ($(XOPTMZ),3)
		override XOPTMZ::=-ffast-math -funsafe-loop-optimizations -minline-all-stringops -fomit-frame-pointer -maccumulate-outgoing-args
	else ifeq ($(XOPTMZ),4)
		override XOPTMZ::=-funsafe-math-optimizations
	else ifeq ($(XOPTMZ),5)
		override XOPTMZ::=-ffast-math
	else ifeq ($(XOPTMZ),6)
		override XOPTMZ::=-funsafe-loop-optimizations
	else ifeq ($(XOPTMZ),7)
		override XOPTMZ::=
	else ifeq ($(XOPTMZ),8)
		override XOPTMZ::=-minline-all-stringops -fomit-frame-pointer
	else ifeq ($(XOPTMZ),9)
		override XOPTMZ::=-maccumulate-outgoing-args
	else ifeq ($(XOPTMZ),10)
		override XOPTMZ::=-maccumulate-outgoing-args -minline-all-stringops -fno-signed-zeros -fno-math-errno -fno-signaling-nans -ftree-vectorize -ffinite-math-only -mlong-double-128 -fomit-frame-pointer
	else ifeq ($(XOPTMZ),11)
		override XOPTMZ::=-m8bit-idiv
	else
		override XOPTMZ::=
	endif
else
	XOPTMZ::=
endif


## CROSS-COMPILING ##


# Fix `CROSS_COMPILE`
ifdef CROSS_COMPILE
	ifeq ($(CROSS_COMPILE),x86_64)
		override CROSS_COMPILE::=x86-64
	else ifeq ($(CROSS_COMPILE),AMD64)
		override CROSS_COMPILE::=x86-64
	else ifeq ($(CROSS_COMPILE),64)
		override CROSS_COMPILE::=x86-64
	else ifeq ($(CROSS_COMPILE),64bit)
		override CROSS_COMPILE::=x86-64
	else ifeq ($(CROSS_COMPILE),32)
		override CROSS_COMPILE::=x86
	else ifeq ($(CROSS_COMPILE),32bit)
		override CROSS_COMPILE::=x86
	endif
endif

# Operating System
ifdef OS
	ifeq ($(OS),WINDOWS)
		override OS::=WIN
	endif
	ifeq ($(OS),WIN)
		ifeq ($(CROSS_COMPILE),x86)
			override BITS::=-m32 -DENV32BIT
			override CROSS_COMPILE::=win32
		else
			override BITS::=-m64 -DENV64BIT
			override CROSS_COMPILE::=win64
		endif
	else ifeq ($(OS),ANDROID)
		ifeq ($(CROSS_COMPILE),arm)
			override CROSS_COMPILE::=android
		else
			override CROSS_COMPILE::=androidx86
			override BITS::=-m32 -DENV32BIT
		endif
	else ifeq ($(OS),BSD)
		override OS::=POSIX
	else ifeq ($(OS),OSX)
		override OS::=POSIX
	endif
endif

ifdef CROSS_COMPILE
	override undefine CLANG
	override undefine LINKER
	override undefine STDLIB
	override undefine STRIP
	# Windows (i686)
	ifeq ($(CROSS_COMPILE),win32)
		override CROSS_COMPILE::=i686-w64-mingw32-
		override GCC_PREFIX::=i686-w64-mingw32
		override CC::=i686-w64-mingw32-gcc -m32 $(mingw32_include) -Wl,-rpath=$(mingw32_lib) -DENV32BIT
		override CBUILD::=i686-w64-mingw32-gcc
		override CHOST::=$(CBUILD)
		override STRIP::=i686-w64-mingw32-strip
		override LD::=i686-w64-mingw32-ld $(mingw32_lib)
		override AS::=i686-w64-mingw32-as
		override RANLIB::=i686-w64-mingw32-ranlib
		override AR::=i686-w64-mingw32-ar
		override NM::=i686-w64-mingw32-nm
		override DLLTOOL::=i686-w64-mingw32-dlltool
		override WINDRES::=i686-w64-mingw32-windres
		override INCLUDES+::= $(mingw32_include)
		override LIBS+::= $(mingw32_lib)
		override OS::=WIN
		override BITS::=-m32 -DENV32BIT
		override ARCH::=-mtune=generic
		override STDLIB::=STANDARD
	# Windows (x86-64)
	else ifeq ($(CROSS_COMPILE),win64)
		override CROSS_COMPILE::=x86_64-w64-mingw32-
		override GCC_PREFIX::=x86_64-w64-mingw32
		override CC::=x86_64-w64-mingw32-gcc -m64 $(mingw64_include) -Wl,-rpath=$(mingw64_lib) -DENV64BIT
		override CBUILD::=x86_64-w64-mingw32-gcc
		override CHOST::=$(CBUILD)
		override STRIP::=x86_64-w64-mingw32-strip
		override LD::=x86_64-w64-mingw32-ld $(mingw64_lib)
		override AS::=x86_64-w64-mingw32-as
		override RANLIB::=x86_64-w64-mingw32-ranlib
		override AR::=x86_64-w64-mingw32-ar
		override NM::=x86_64-w64-mingw32-nm
		override DLLTOOL::=x86_64-w64-mingw32-dlltool
		override WINDRES::=x86_64-w64-mingw32-windres
		override INCLUDES+::= $(mingw64_include)
		override LIBS+::= $(mingw64_lib)
		override OS::=WIN
		override BITS::=-m64 -DENV64BIT
		override ARCH::=-mtune=generic
		override STDLIB::=STANDARD
	# Android (ARM)
	else ifeq ($(CROSS_COMPILE),android)
		override CROSS_COMPILE::=arm-linux-androideabi-
		override GCC_PREFIX::=arm-linux-androideabi
		override CC::=arm-linux-androideabi-gcc $(armandroideabi_include) -Wl,-rpath=$(armandroideabi_lib)
		override CBUILD::=arm-linux-androideabi-gcc
		override CHOST::=$(CBUILD)
		override STRIP::=arm-linux-androideabi-strip
		override LD::=arm-linux-androideabi-ld $(armandroideabi_lib)
		override AS::=arm-linux-androideabi-as
		override RANLIB::=arm-linux-androideabi-ranlib
		override AR::=arm-linux-androideabi-ar
		override INCLUDES+::= $(armandroideabi_include)
		override LIBS+::= $(armgnueabisf_lib)
		override OS::=ANDROID
		override BITS::=-m32 -DENV32BIT
		override STDLIB::=STANDARD
		override ARCH_ARM::=ARM
	# (POSIX and/or Unix)
	# Linux
	else ifeq ($(OS),LINUX)
		# x86 and x86-64
		ifeq ($(CROSS_COMPILE),x86)
			override GCC_PREFIX::=x86-linux-gnu
			override CC::=x86-linux-gnu-gcc -m32
			override CBUILD::=x86-linux-gnu-gcc
			override CHOST::=$(CBUILD)
			override STRIP::=x86-linux-gnu-strip
			override LD::=x86-linux-gnu-ld
			override AS::=x86-linux-gnu-as
			override RANLIB::=x86-linux-gnu-ranlib
			override AR::=x86-linux-gnu-ar
			override OS::=POSIX
			override BITS::=-m32 -DENV32BIT
		else ifeq ($(CROSS_COMPILE),x86-64)
			override GCC_PREFIX::=x86_64-linux-gnu
			override CC::=x86_64-linux-gnu-gcc -m64
			override CBUILD::=x86_64-linux-gnu-gcc
			override CHOST::=$(CBUILD)
			override STRIP::=x86_64-linux-gnu-strip
			override LD::=x86_64-linux-gnu-ld
			override AS::=x86_64-linux-gnu-as
			override RANLIB::=x86_64-linux-gnu-ranlib
			override AR::=x86_64-linux-gnu-ar
			override OS::=POSIX
			override BITS::=-m64 -DENV64BIT
		# ARM
		else ifeq ($(CROSS_COMPILE),armhf)
			override CROSS_COMPILE::=arm-linux-gnueabihf-
			override GCC_PREFIX::=arm-linux-gnueabihf
			override CC::=arm-linux-gnueabihf-gcc $(armgnueabihf_include) -Wl,-rpath=$(armgnueabihf_lib)
			override CBUILD::=arm-linux-gnueabihf-gcc
			override CHOST::=$(CBUILD)
			override STRIP::=arm-linux-gnueabihf-strip
			override LD::=arm-linux-gnueabihf-ld $(armgnueabihf_lib)
			override AS::=arm-linux-gnueabihf-as
			override RANLIB::=arm-linux-gnueabihf-ranlib
			override AR::=arm-linux-gnueabihf-ar
			override INCLUDES+::= $(armgnueabihf_include)
			override LIBS+::= $(armgnueabihf_lib)
			override OS::=POSIX
			override BITS::=-m32 -DENV32BIT
			override ARCH_ARM::=ARM
		else ifeq ($(CROSS_COMPILE),arm)
			override CROSS_COMPILE::=arm-linux-gnueabihf-
			override GCC_PREFIX::=arm-linux-gnueabihf
			override CC::=arm-linux-gnueabihf-gcc $(armgnueabihf_include) -Wl,-rpath=$(armgnueabihf_lib)
			override CBUILD::=arm-linux-gnueabihf-gcc
			override CHOST::=$(CBUILD)
			override STRIP::=arm-linux-gnueabihf-strip
			override LD::=arm-linux-gnueabihf-ld $(armgnueabihf_lib)
			override AS::=arm-linux-gnueabihf-as
			override RANLIB::=arm-linux-gnueabihf-ranlib
			override AR::=arm-linux-gnueabihf-ar
			override INCLUDES+::= $(armgnueabihf_include)
			override LIBS+::= $(armgnueabihf_lib)
			override OS::=POSIX
			override BITS::=-m32 -DENV32BIT
			override ARCH_ARM::=ARM
		else ifeq ($(CROSS_COMPILE),armel)
			override CROSS_COMPILE::=arm-linux-gnueabi-
			override GCC_PREFIX::=arm-linux-gnueabi
			override CC::=arm-linux-gnueabi-gcc $(armgnueabi_include) -Wl,-rpath=$(armgnueabi_lib)
			override CBUILD::=arm-linux-gnueabi-gcc
			override CHOST::=$(CBUILD)
			override STRIP::=arm-linux-gnueabi-strip
			override LD::=arm-linux-gnueabi-ld $(armgnueabi_lib)
			override AS::=arm-linux-gnueabi-as
			override RANLIB::=arm-linux-gnueabi-ranlib
			override AR::=arm-linux-gnueabi-ar
			override INCLUDES+::= $(armgnueabi_include)
			override LIBS+::= $(armgnueabi_lib)
			override OS::=POSIX
			override BITS::=-m32 -DENV32BIT
			override ARCH_ARM::=ARM
		else ifeq ($(CROSS_COMPILE),armsf)
			override CROSS_COMPILE::=arm-linux-gnueabi-
			override GCC_PREFIX::=arm-linux-gnueabi
			override CC::=arm-linux-gnueabi-gcc $(armgnueabisf_include) -Wl,-rpath=$(armgnueabisf_lib)
			override CBUILD::=arm-linux-gnueabi-gcc
			override CHOST::=$(CBUILD)
			override STRIP::=arm-linux-gnueabi-strip
			override LD::=arm-linux-gnueabi-ld $(armgnueabisf_lib)
			override AS::=arm-linux-gnueabi-as
			override RANLIB::=arm-linux-gnueabi-ranlib
			override AR::=arm-linux-gnueabi-ar
			override INCLUDES+::= $(armgnueabisf_include)
			override LIBS+::= $(armgnueabisf_lib)
			override OS::=POSIX
			override BITS::=-m32 -DENV32BIT
			override ARCH_ARM::=ARM
		endif
	endif
endif
ifeq ($(OS),LINUX)
	override OS::=POSIX
endif


## PLATFORM ##


# Architecture flags
ifndef CROSS_COMPILE
	ifdef ARCH
		# Intel
		ifeq ($(ARCH),intel)
			override ARCH::=-mtune=intel
		else ifeq ($(ARCH),generic)
			override ARCH::=-mtune=generic
		else ifeq ($(ARCH),i686)
			override ARCH::=-march=i686
		else ifeq ($(ARCH),pentium4)
			override ARCH::=-march=pentium4
		else ifeq ($(ARCH),sandybridge)
			override ARCH::=-march=sandybridge
		else ifeq ($(ARCH),ivybridge)
			override ARCH::=-march=ivybridge
		else ifeq ($(ARCH),haswell)
			override ARCH::=-march=haswell -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld
		else ifeq ($(ARCH),broadwell)
			override ARCH::=-march=broadwell -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld
		else ifeq ($(ARCH),bonnell)
			override ARCH::=-march=bonnell -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld
		else ifeq ($(ARCH),silvermont)
			override ARCH::=-march=silvermont -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld
		else ifeq ($(ARCH),knight)
			override ARCH::=-march=knl -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld
		else ifeq ($(ARCH),knl)
			override ARCH::=-march=knl -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld
		# AMD
		else ifeq ($(ARCH),k6)
			override ARCH::=-march=k6
		else ifeq ($(ARCH),athlon)
			override ARCH::=-march=athlon
		else ifeq ($(ARCH),opteron)
			override ARCH::=-march=opteron
		# ARM
		else ifeq ($(ARCH),armv6)
			override ARCH::=-march=armv6
		else ifeq ($(ARCH),armv7)
			override ARCH::=-march=armv7
		else ifeq ($(ARCH),armv7-a)
			override ARCH::=-march=armv7-a
		else ifeq ($(ARCH),armv7-r)
			override ARCH::=-march=armv7-r
		else ifeq ($(ARCH),armv7-m)
			override ARCH::=-march=armv7-m
		else ifeq ($(ARCH),armv8-a)
			override ARCH::=-march=armv8-a
		else ifeq ($(ARCH),armv8-a+crc)
			override ARCH::=-march=armv8-a+crc
		else ifeq ($(ARCH),iwmmxt)
			override ARCH::=-march=iwmmxt
		# General
		else
			override ARCH::=
		endif
	else
		override ARCH::=
	endif
endif

# 32 or 64 bits
ifdef BITS
	ifeq ($(BITS),64)
		override BITS::=-m64 -DENV64BIT
	else ifeq ($(BITS),32)
		override BITS::=-m32 -DENV32BIT
	else
		override BITS::=
	endif
else
	BITS::=
endif

# ENDIANNESS
ifdef ENDIAN
	ifeq ($(ENDIAN),big)
		override ENDIAN::=-mbig-endian
	else
		override ENDIAN::=-mlittle-endian
	endif
else
	ENDIAN::=
endif

# Floating-point ABI
ifdef FLOATABI
	ifeq ($(FLOATABI),soft)
		override FLOATAB::I=-mfloat-abi=soft
	else ifeq ($(FLOATABI),softfp)
		override FLOATABI::=-mfloat-abi=softfp
	else
		override FLOATABI::=-mfloat-abi=hard
	endif
else
	FLOATABI::=
endif


## SECURITY ##


ifdef SECURITY
	ifeq ($(SECURITY),1)
		override POSIX_STACK_PROTECTOR::=-fstack-protector
	else ifeq ($(SECURITY),2)
		override POSIX_STACK_PROTECTOR::=-fstack-protector-strong
	else ifeq ($(SECURITY),3)
		override POSIX_STACK_PROTECTOR::=-fstack-protector-all
	else
		POSIX_STACK_PROTECTOR::=
	endif
else
	POSIX_STACK_PROTECTOR::=-fstack-protector
endif


## LINUX ##


# C-Standard
ifeq ($(OS),LINUX)
	ifdef STD
		# GNU
		ifeq ($(STD),gnu11)
			override STD::=-std=gnu11
		# C
		else
			override STD::=-std=c11
		endif
	else
		STD::=-std=c11
	endif
else
	STD::=-std=c11
endif


## MISCELLANEOUS ##


# Debugging flags
ifdef DEBUG
	ifeq ($(DEBUG),1)
		override DEBUG::=
	else ifeq ($(DEBUG),2)
		override DEBUG::=-DDEBUG -g -ggdb
	else
		ifeq ($(OS),WIN)
			override DEBUG::=-DNDEBUG -g0 -ggdb0 -s -Wl,-s
		else
			override DEBUG::=-DNDEBUG -g0 -ggdb0 -s -Wl,-s,-S -Wl,-gc-sections
		endif
	endif
else
	ifeq ($(OS),WIN)
		DEBUG::=-DNDEBUG -g0 -ggdb0 -s -Wl,-s
	else
		DEBUG::=-DNDEBUG -g0 -ggdb0 -s -Wl,-s,-S -Wl,-gc-sections
	endif
endif

# Alternate Standard C Library
ifdef STDLIB
	ifneq ($(STDLIB),STANDARD)
		override STDLIB::=
		ifdef UCLIBC
			override STDLIB::=-muclibc
		else ifdef BIONIC
			override STDLIB::==-mbionic
		else ifdef GLIBC
			override STDLIB::==-mglibc
		else ifdef MUSL
			ifndef CROSS_COMPILE
				override CC::==musl-gcc -D__MUSL__
			endif
		endif
	endif
	ifeq ($(STDLIB),STANDARD)
		override STDLIB::=
	endif
else
	STDLIB::=
endif

# Pthread
ifneq ($(OS),WIN)
	ifdef PTHREAD
		override ARCH+= -pthread -D__PTHREAD_ENABLED__
	endif
endif

# MOVBE (Assembly command)
ifdef MOVBE
	override ARCH+= -mmovbe -D__MOVBE__
endif

# Alternate linker
ifndef CROSS_COMPILE
	ifdef LINKER
		ifeq ($(LINKER),gold)
			override LD::=gold
			override LINKER::=-fuse-ld=gold -D__GOLD_LINKER__
		else ifeq ($(LINKER),bfd)
			override LD::=bfd
			override LINKER::=-fuse-ld=bfd -D__BFD_LINKER__
		else
			override LINKER::=
		endif
	else
		override LINKER::=
	endif
endif


ifeq ($(OS),WIN)
	override COMMON_OPT::= -O3 -funroll-loops
	override FLTO::=
	override FPIC::=
	override LDZ::=-Wl,-O3
	override LIBEXT::=dll
	override STACK::=-fno-stack-protector -D_FORTIFY_SOURCE=0
	override WIN::=-fms-extensions -mwin32 $(STACK)
	override WINCUI::=-mconsole $(WIN)
	override WINLIB::=-mdll $(WIN)
else
	ifdef CLANG
		override FLTO::=
		override LDZ::=
	else
		override FLTO::= -flto -fuse-linker-plugin
		override LDZ::=-Wl,-O3 -Wl,-z,relro,-z,now
	endif
	override COMMON_OPT::= -O3 -funroll-loops -ffunction-sections -fdata-sections
	override FPIC::=-fPIC
	override LIBEXT::=so
	override STACK::=
	override WIN::=
	override WINCUI::=
	override WINLIB::=
endif

ifndef STRIP
	override STRIP::=strip
endif


## PYTHON ##


override PYCFLAGS::=-DHAVE_GCC_UINT128_T -DHAVE_GCC_INT128_T -DHAVE_SSIZE_T -DPY_FORMAT_SIZE_T="z" -DPY_FORMAT_SSIZE_T="zi" -DPY_FORMAT_LONG_LONG="ll"

ifdef PYVERSION
	ifeq ($(PYVERSION),3.4)
		override PYVERSION::=3.4
		override CPYTHON::=34
	else ifeq ($(PYVERSION),3.5)
		override PYVERSION::=3.5
		override CPYTHON::=35
	else ifeq ($(PYVERSION),3.6)
		override PYVERSION::=3.6
		override CPYTHON::=36
	else ifeq ($(PYVERSION),3.7)
		override PYVERSION::=3.7
		override CPYTHON::=37
	else ifeq ($(PYVERSION),3.8)
		override PYVERSION::=3.8
		override CPYTHON::=38
	else
		override PYVERSION::=3.4
		override CPYTHON::=34
	endif
else
	PYVERSION::=3.4
	CPYTHON::=34
endif

ifndef PYINCLUDE
	PYINCLUDE::=-I/usr/include/python$(PYVERSION)m
else ifeq ($(PYINCLUDE),1)
	override PRIVATE_PYTHON::=1
else ifeq ($(PYINCLUDE),3.5)
	override PRIVATE_PYTHON::=1
endif

ifdef PRIVATE_PYTHON
	override PYINCLUDE::=-I./python
	override PYVERSION::=3.5
	override CPYTHON::=35
	override PYCFLAGS::=
	override SOABI::=cpython-$(CPYTHON)m
	override PYEXT::=.$(SOABI).so
endif

ifndef SOABI
	SOABI::=cpython-$(CPYTHON)m
	PYEXT::=.$(SOABI).so
endif


## SPECIAL LLVM+CLANG FEATURES ##


ifdef LLVM_PIE
	override LLVM_PIE::=-enable-pie
else
	override LLVM_PIE::=
endif
# *.c/*.cpp => *.ll (LLVM IR/Intermediate-Language file)
LLVM_INTERMEDIATE::=clang -Qunused-arguments $(LLVM_WARN) $(ARCH) $(BITS) $(STD) -O3 $(DEBUG) -fno-signed-zeros -fno-math-errno -funroll-loops -fstack-protector -pipe -fstrict-aliasing -fstrict-overflow -ffunction-sections -fdata-sections -S -emit-llvm
# *.c/*.cpp => *.bc (LLVM Bytecode file)
LLVM_BYTECODE::=clang -Qunused-arguments $(LLVM_WARN) $(ARCH) $(BITS) $(STD) -O3 $(DEBUG) -fno-signed-zeros -fno-math-errno -funroll-loops -fstack-protector -pipe -fstrict-aliasing -fstrict-overflow -ffunction-sections -fdata-sections -flto -emit-llvm -c
# LLVM Bytecode (*.bc) => LLVM AT&T Assembly (*.s)
LLVM_BC2ATTASM::=llc $(ARCH) -O=3 -data-sections $(LLVM_PIE) -filetype=asm --x86-asm-syntax=att
# LLVM Bytecode (*.bc) => LLVM INTEL Assembly (*.s)
LLVM_BC2INTELASM::=llc $(ARCH) -O=3 -data-sections $(LLVM_PIE) -filetype=asm --x86-asm-syntax=intel
# LLVM Bytecode (*.bc) => Object file (*.o)
LLVM_BC2OBJ::=llc $(ARCH) -O=3 -data-sections $(LLVM_PIE) -filetype=obj
# *.c/*.cpp => *.ast (Clang AST file)
CLANG_AST::=clang -Qunused-arguments $(LLVM_WARN) $(ARCH) $(BITS) $(STD) -O3 $(DEBUG) -fno-signed-zeros -fno-math-errno -funroll-loops -fstack-protector -pipe -fstrict-aliasing -fstrict-overflow -ffunction-sections -fdata-sections -S -emit-ast
# Run Clang preprocessor on src and output preprocessed code (*.i)
CLANG_PREPRO::=clang $(ARCH) $(STD) -E
# Pre-compiled headers (*.pch)
COMPILED_HEADERS::=clang $(ARCH) $(STD) -x c-header


# To execute LLVM *.bc files, run
# lli ./FILE.bc ARGS

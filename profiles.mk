#!/usr/bin/make -f
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @brief Makefile profile header (Usable on GNU/Linux only)
# @version 2016.03.20


include makefile_constants.mk


## PROFILES ##


ifndef OS
	override OS::=
endif

ifdef PROFILE
	override dcj::=$(PROFILE)
	override DCJ::=$(PROFILE)
endif

ifdef dcj
	ifeq ($(dcj),py)
		override dcj::=1
		override PYINCLUDE::=3.5
	endif
endif

ifdef dcj
	ifeq ($(dcj),1)
		# Standard Haswell Configuration (Linux64)
		override STD::=-std=c11
		override BITS::=-m64
		override DEBUG::=-DNDEBUG -g0 -ggdb0 -Wl,-gc-sections -s -Wl,-s,-S -DNOAUTHOR -DNOVERSION
		override FPIC::=-fPIC
		override SECURITY::=1
		override LIBEXT::=so
		PYVERSION::=3.4
		CPYTHON::=34
		override OS::=POSIX
		override ARCH::=-march=haswell
		# GNU-GCC
		ifndef CLANG
			ifdef MUSL
				override CC::=musl-gcc -D__MUSL__
			else
				override CC::=gcc
			endif
			override STRIP::=strip
			override LD::=ld
			override AS::=as
			override RANLIB::=ranlib
			override AR::=ar
			override LDZ::=-Wl,-O3 -Wl,-z,relro -Wl,-z,now
			override FLTO::=-flto -fuse-linker-plugin
			override WARN::=-Werror -Wall -Wextra -pedantic -Wformat -Werror=format-security -Wformat-nonliteral -Wformat-signedness -Wformat-y2k -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wstrict-overflow=5 -Wuninitialized -Wshadow -Wpointer-arith -Wcast-align -Wcast-qual -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -Wconversion -Wbad-function-cast -Wdouble-promotion -Wmissing-include-dirs -Wswitch-enum -Wswitch-bool -Wsync-nand -Winit-self -Wsuggest-final-types -Wsuggest-final-methods -Wundef -Wdate-time -Wjump-misses-init -Wlogical-op -Wopenmp-simd -Wpacked -Winvalid-pch -Wunsafe-loop-optimizations -Wvector-operation-performance -Wdisabled-optimization -Wstack-protector -Wswitch-default -Wpadded
			override XOPTMZ::=-fno-signed-zeros -fno-math-errno -fno-signaling-nans -ftree-vectorize -ffinite-math-only -mlong-double-128 -fomit-frame-pointer -momit-leaf-frame-pointer -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld -maccumulate-outgoing-args -minline-all-stringops -funsafe-loop-optimizations -fwrapv -fno-exceptions -floop-nest-optimize -floop-parallelize-all -ftree-parallelize-loops=4 -fira-loop-pressure -fmodulo-sched -fmodulo-sched-allow-regmoves -freschedule-modulo-scheduled-loops -fselective-scheduling -fselective-scheduling2 -fsel-sched-pipelining -fsel-sched-pipelining-outer-loops -fsel-sched-reschedule-pipelined
		# Clang
		else
			ifeq ($(CLANG),3.7)
				override CC::=clang-3.7 -Qunused-arguments
			else ifeq ($(CLANG),3.8)
				override CC::=clang-3.8 -Qunused-arguments
			else
				override CC::=clang -Qunused-arguments
			endif
			override STRIP::=strip
			override LD::=llvm-link
			override AS::=llvm-as
			override RANLIB::=llvm-ranlib
			override AR::=llvm-ar
			override LDZ::=
			override FLTO::=
			override WARN::=-Werror $(LLVM_WARN)
			override XOPTMZ::=-fno-signed-zeros -fno-math-errno -ftree-vectorize -ffinite-math-only -fomit-frame-pointer -momit-leaf-frame-pointer -mcrc -mcx16 -minline-all-stringops -fwrapv -fvectorize -fstrict-enums -fno-dollars-in-identifiers -Xanalyzer -strip-dead-debug-info -Xclang -vectorize-slp-aggressive
		endif
	else ifeq ($(dcj),2)
		# Standard Broadwell Configuration (Linux64)
		override STD::=-std=c11
		override BITS::=-m64
		override DEBUG::=-DNDEBUG -g0 -ggdb0 -Wl,-gc-sections -s -Wl,-s,-S -DNOAUTHOR -DNOVERSION
		override FPIC::=-fPIC
		override SECURITY::=1
		override LIBEXT::=so
		PYVERSION::=3.4
		CPYTHON::=34
		override OS::=POSIX
		override ARCH::=-march=broadwell
		# GNU-GCC
		ifndef CLANG
			ifdef MUSL
				override CC::=musl-gcc -D__MUSL__
			else
				override CC::=gcc
			endif
			override STRIP::=strip
			override LD::=ld
			override AS::=as
			override RANLIB::=ranlib
			override AR::=ar
			override LDZ::=-Wl,-O3 -Wl,-z,relro -Wl,-z,now
			override FLTO::=-flto -fuse-linker-plugin
			override WARN::=-Werror -Wall -Wextra -pedantic -Wformat -Werror=format-security -Wformat-nonliteral -Wformat-signedness -Wformat-y2k -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wstrict-overflow=5 -Wuninitialized -Wshadow -Wpointer-arith -Wcast-align -Wcast-qual -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -Wconversion -Wbad-function-cast -Wdouble-promotion -Wmissing-include-dirs -Wswitch-enum -Wswitch-bool -Wsync-nand -Winit-self -Wsuggest-final-types -Wsuggest-final-methods -Wundef -Wdate-time -Wjump-misses-init -Wlogical-op -Wopenmp-simd -Wpacked -Winvalid-pch -Wunsafe-loop-optimizations -Wvector-operation-performance -Wdisabled-optimization -Wstack-protector -Wswitch-default -Wpadded
			override XOPTMZ::=-fno-signed-zeros -fno-math-errno -fno-signaling-nans -ftree-vectorize -ffinite-math-only -mlong-double-128 -fomit-frame-pointer -momit-leaf-frame-pointer -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld -maccumulate-outgoing-args -minline-all-stringops -funsafe-loop-optimizations -fwrapv -fno-exceptions -floop-nest-optimize -floop-parallelize-all -ftree-parallelize-loops=4 -fira-loop-pressure -fmodulo-sched -fmodulo-sched-allow-regmoves -freschedule-modulo-scheduled-loops -fselective-scheduling -fselective-scheduling2 -fsel-sched-pipelining -fsel-sched-pipelining-outer-loops -fsel-sched-reschedule-pipelined
		# Clang
		else
			ifeq ($(CLANG),3.7)
				override CC::=clang-3.7 -Qunused-arguments
			else ifeq ($(CLANG),3.8)
				override CC::=clang-3.8 -Qunused-arguments
			else
				override CC::=clang -Qunused-arguments
			endif
			override STRIP::=strip
			override LD::=llvm-link
			override AS::=llvm-as
			override RANLIB::=llvm-ranlib
			override AR::=llvm-ar
			override LDZ::=
			override FLTO::=
			override WARN::=-Werror $(LLVM_WARN)
			override XOPTMZ::=-fno-signed-zeros -fno-math-errno -ftree-vectorize -ffinite-math-only -fomit-frame-pointer -momit-leaf-frame-pointer -mcrc -mcx16 -minline-all-stringops -fwrapv -fvectorize -fstrict-enums -fno-dollars-in-identifiers -Xanalyzer -strip-dead-debug-info -Xclang -vectorize-slp-aggressive
		endif
	else ifeq ($(dcj),3)
		# Standard Skylake Configuration (Linux64)
		override STD::=-std=c11
		override BITS::=-m64
		override DEBUG::=-DNDEBUG -g0 -ggdb0 -Wl,-gc-sections -s -Wl,-s,-S -DNOAUTHOR -DNOVERSION
		override FPIC::=-fPIC
		override SECURITY::=1
		override LIBEXT::=so
		PYVERSION::=3.4
		CPYTHON::=34
		override OS::=POSIX
		override ARCH::=-march=skylake
		# GNU-GCC
		ifndef CLANG
			ifdef MUSL
				override CC::=musl-gcc -D__MUSL__
			else
				override CC::=gcc
			endif
			override STRIP::=strip
			override LD::=ld
			override AS::=as
			override RANLIB::=ranlib
			override AR::=ar
			override LDZ::=-Wl,-O3 -Wl,-z,relro -Wl,-z,now
			override FLTO::=-flto -fuse-linker-plugin
			override WARN::=-Werror -Wall -Wextra -pedantic -Wformat -Werror=format-security -Wformat-nonliteral -Wformat-signedness -Wformat-y2k -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wstrict-overflow=5 -Wuninitialized -Wshadow -Wpointer-arith -Wcast-align -Wcast-qual -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -Wconversion -Wbad-function-cast -Wdouble-promotion -Wmissing-include-dirs -Wswitch-enum -Wswitch-bool -Wsync-nand -Winit-self -Wsuggest-final-types -Wsuggest-final-methods -Wundef -Wdate-time -Wjump-misses-init -Wlogical-op -Wopenmp-simd -Wpacked -Winvalid-pch -Wunsafe-loop-optimizations -Wvector-operation-performance -Wdisabled-optimization -Wstack-protector -Wswitch-default -Wpadded
			override XOPTMZ::=-fno-signed-zeros -fno-math-errno -fno-signaling-nans -ftree-vectorize -ffinite-math-only -mlong-double-128 -fomit-frame-pointer -momit-leaf-frame-pointer -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld -maccumulate-outgoing-args -minline-all-stringops -funsafe-loop-optimizations -fwrapv -fno-exceptions -floop-nest-optimize -floop-parallelize-all -ftree-parallelize-loops=4 -fira-loop-pressure -fmodulo-sched -fmodulo-sched-allow-regmoves -freschedule-modulo-scheduled-loops -fselective-scheduling -fselective-scheduling2 -fsel-sched-pipelining -fsel-sched-pipelining-outer-loops -fsel-sched-reschedule-pipelined
		# Clang
		else
			ifeq ($(CLANG),3.7)
				override CC::=clang-3.7 -Qunused-arguments
			else ifeq ($(CLANG),3.8)
				override CC::=clang-3.8 -Qunused-arguments
			else
				override CC::=clang -Qunused-arguments
			endif
			override STRIP::=strip
			override LD::=llvm-link
			override AS::=llvm-as
			override RANLIB::=llvm-ranlib
			override AR::=llvm-ar
			override LDZ::=
			override FLTO::=
			override WARN::=-Werror $(LLVM_WARN)
			override XOPTMZ::=-fno-signed-zeros -fno-math-errno -ftree-vectorize -ffinite-math-only -fomit-frame-pointer -momit-leaf-frame-pointer -mcrc -mcx16 -minline-all-stringops -fwrapv -fvectorize -fstrict-enums -fno-dollars-in-identifiers -Xanalyzer -strip-dead-debug-info -Xclang -vectorize-slp-aggressive
		endif
	else ifeq ($(dcj),4)
		# Standard Knight Configuration (Linux64)
		override STD::=-std=c11
		override BITS::=-m64
		override DEBUG::=-DNDEBUG -g0 -ggdb0 -Wl,-gc-sections -s -Wl,-s,-S -DNOAUTHOR -DNOVERSION
		override FPIC::=-fPIC
		override SECURITY::=1
		override LIBEXT::=so
		PYVERSION::=3.4
		CPYTHON::=34
		override OS::=POSIX
		override ARCH::=-march=knl
		# GNU-GCC
		ifndef CLANG
			ifdef MUSL
				override CC::=musl-gcc -D__MUSL__
			else
				override CC::=gcc
			endif
			override STRIP::=strip
			override LD::=ld
			override AS::=as
			override RANLIB::=ranlib
			override AR::=ar
			override LDZ::=-Wl,-O3 -Wl,-z,relro -Wl,-z,now
			override FLTO::=-flto -fuse-linker-plugin
			override WARN::=-Werror -Wall -Wextra -pedantic -Wformat -Werror=format-security -Wformat-nonliteral -Wformat-signedness -Wformat-y2k -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wstrict-overflow=5 -Wuninitialized -Wshadow -Wpointer-arith -Wcast-align -Wcast-qual -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -Wconversion -Wbad-function-cast -Wdouble-promotion -Wmissing-include-dirs -Wswitch-enum -Wswitch-bool -Wsync-nand -Winit-self -Wsuggest-final-types -Wsuggest-final-methods -Wundef -Wdate-time -Wjump-misses-init -Wlogical-op -Wopenmp-simd -Wpacked -Winvalid-pch -Wunsafe-loop-optimizations -Wvector-operation-performance -Wdisabled-optimization -Wstack-protector -Wswitch-default -Wpadded
			override XOPTMZ::=-fno-signed-zeros -fno-math-errno -fno-signaling-nans -ftree-vectorize -ffinite-math-only -mlong-double-128 -fomit-frame-pointer -momit-leaf-frame-pointer -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld -maccumulate-outgoing-args -minline-all-stringops -funsafe-loop-optimizations -fwrapv -fno-exceptions -floop-nest-optimize -floop-parallelize-all -ftree-parallelize-loops=4 -fira-loop-pressure -fmodulo-sched -fmodulo-sched-allow-regmoves -freschedule-modulo-scheduled-loops -fselective-scheduling -fselective-scheduling2 -fsel-sched-pipelining -fsel-sched-pipelining-outer-loops -fsel-sched-reschedule-pipelined
		# Clang
		else
			ifeq ($(CLANG),3.7)
				override CC::=clang-3.7 -Qunused-arguments
			else ifeq ($(CLANG),3.8)
				override CC::=clang-3.8 -Qunused-arguments
			else
				override CC::=clang -Qunused-arguments
			endif
			override STRIP::=strip
			override LD::=llvm-link
			override AS::=llvm-as
			override RANLIB::=llvm-ranlib
			override AR::=llvm-ar
			override LDZ::=
			override FLTO::=
			override WARN::=-Werror $(LLVM_WARN)
			override XOPTMZ::=-fno-signed-zeros -fno-math-errno -ftree-vectorize -ffinite-math-only -fomit-frame-pointer -momit-leaf-frame-pointer -mcrc -mcx16 -minline-all-stringops -fwrapv -fvectorize -fstrict-enums -fno-dollars-in-identifiers -Xanalyzer -strip-dead-debug-info -Xclang -vectorize-slp-aggressive
		endif
	else ifeq ($(dcj),athlon64-sse3)
		# Standard athlon64-SSE3 Configuration (Linux64)
		override STD::=-std=c11
		override BITS::=-m64
		override DEBUG::=-DNDEBUG -g0 -ggdb0 -Wl,-gc-sections -s -Wl,-s,-S -DNOAUTHOR -DNOVERSION
		override FPIC::=-fPIC
		override SECURITY::=1
		override LIBEXT::=so
		PYVERSION::=3.4
		CPYTHON::=34
		override OS::=POSIX
		override ARCH::=-march=athlon64-sse3
		# GNU-GCC
		ifndef CLANG
			ifdef MUSL
				override CC::=musl-gcc -D__MUSL__
			else
				override CC::=gcc
			endif
			override STRIP::=strip
			override LD::=ld
			override AS::=as
			override RANLIB::=ranlib
			override AR::=ar
			override LDZ::=-Wl,-O3 -Wl,-z,relro -Wl,-z,now
			override FLTO::=-flto -fuse-linker-plugin
			override WARN::=-Werror -Wall -Wextra -pedantic -Wformat -Werror=format-security -Wformat-nonliteral -Wformat-signedness -Wformat-y2k -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wstrict-overflow=5 -Wuninitialized -Wshadow -Wpointer-arith -Wcast-align -Wcast-qual -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -Wconversion -Wbad-function-cast -Wdouble-promotion -Wmissing-include-dirs -Wswitch-enum -Wswitch-bool -Wsync-nand -Winit-self -Wsuggest-final-types -Wsuggest-final-methods -Wundef -Wdate-time -Wjump-misses-init -Wlogical-op -Wopenmp-simd -Wpacked -Winvalid-pch -Wunsafe-loop-optimizations -Wvector-operation-performance -Wdisabled-optimization -Wstack-protector -Wswitch-default -Wpadded
			override XOPTMZ::=-fno-signed-zeros -fno-math-errno -fno-signaling-nans -ftree-vectorize -ffinite-math-only -mlong-double-128 -fomit-frame-pointer -momit-leaf-frame-pointer -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld -maccumulate-outgoing-args -minline-all-stringops -funsafe-loop-optimizations -fwrapv -fno-exceptions -floop-nest-optimize -floop-parallelize-all -ftree-parallelize-loops=4 -fira-loop-pressure -fmodulo-sched -fmodulo-sched-allow-regmoves -freschedule-modulo-scheduled-loops -fselective-scheduling -fselective-scheduling2 -fsel-sched-pipelining -fsel-sched-pipelining-outer-loops -fsel-sched-reschedule-pipelined
		# Clang
		else
			ifeq ($(CLANG),3.7)
				override CC::=clang-3.7 -Qunused-arguments
			else ifeq ($(CLANG),3.8)
				override CC::=clang-3.8 -Qunused-arguments
			else
				override CC::=clang -Qunused-arguments
			endif
			override STRIP::=strip
			override LD::=llvm-link
			override AS::=llvm-as
			override RANLIB::=llvm-ranlib
			override AR::=llvm-ar
			override LDZ::=
			override FLTO::=
			override WARN::=$(LLVM_WARN)
			override XOPTMZ::=-fno-signed-zeros -fno-math-errno -ftree-vectorize -ffinite-math-only -fomit-frame-pointer -momit-leaf-frame-pointer -mcx16 -minline-all-stringops -fwrapv -fvectorize -fstrict-enums -fno-dollars-in-identifiers -Xanalyzer -strip-dead-debug-info -Xclang -vectorize-slp-aggressive
		endif
	else ifeq ($(dcj),znver1)
		# Standard znver1 Configuration (Linux64)
		override STD::=-std=c11
		override BITS::=-m64
		override DEBUG::=-DNDEBUG -g0 -ggdb0 -Wl,-gc-sections -s -Wl,-s,-S -DNOAUTHOR -DNOVERSION
		override FPIC::=-fPIC
		override SECURITY::=1
		override LIBEXT::=so
		PYVERSION::=3.4
		CPYTHON::=34
		override OS::=POSIX
		override ARCH::=-march=znver1
		# GNU-GCC
		ifndef CLANG
			ifdef MUSL
				override CC::=musl-gcc -D__MUSL__
			else
				override CC::=gcc
			endif
			override STRIP::=strip
			override LD::=ld
			override AS::=as
			override RANLIB::=ranlib
			override AR::=ar
			override LDZ::=-Wl,-O3 -Wl,-z,relro -Wl,-z,now
			override FLTO::=-flto -fuse-linker-plugin
			override WARN::=-Werror -Wall -Wextra -pedantic -Wformat -Werror=format-security -Wformat-nonliteral -Wformat-signedness -Wformat-y2k -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wstrict-overflow=5 -Wuninitialized -Wshadow -Wpointer-arith -Wcast-align -Wcast-qual -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -Wconversion -Wbad-function-cast -Wdouble-promotion -Wmissing-include-dirs -Wswitch-enum -Wswitch-bool -Wsync-nand -Winit-self -Wsuggest-final-types -Wsuggest-final-methods -Wundef -Wdate-time -Wjump-misses-init -Wlogical-op -Wopenmp-simd -Wpacked -Winvalid-pch -Wunsafe-loop-optimizations -Wvector-operation-performance -Wdisabled-optimization -Wstack-protector -Wswitch-default -Wpadded
			override XOPTMZ::=-fno-signed-zeros -fno-math-errno -fno-signaling-nans -ftree-vectorize -ffinite-math-only -mlong-double-128 -fomit-frame-pointer -momit-leaf-frame-pointer -mavx -mmovbe -mcrc32 -msahf -mcx16 -mvzeroupper -mcld -maccumulate-outgoing-args -minline-all-stringops -funsafe-loop-optimizations -fwrapv -fno-exceptions -floop-nest-optimize -floop-parallelize-all -ftree-parallelize-loops=4 -fira-loop-pressure -fmodulo-sched -fmodulo-sched-allow-regmoves -freschedule-modulo-scheduled-loops -fselective-scheduling -fselective-scheduling2 -fsel-sched-pipelining -fsel-sched-pipelining-outer-loops -fsel-sched-reschedule-pipelined
		# Clang
		else
			ifeq ($(CLANG),3.7)
				override CC::=clang-3.7 -Qunused-arguments
			else ifeq ($(CLANG),3.8)
				override CC::=clang-3.8 -Qunused-arguments
			else
				override CC::=clang -Qunused-arguments
			endif
			override STRIP::=strip
			override LD::=llvm-link
			override AS::=llvm-as
			override RANLIB::=llvm-ranlib
			override AR::=llvm-ar
			override LDZ::=
			override FLTO::=
			override WARN::=$(LLVM_WARN)
			override XOPTMZ::=-fno-signed-zeros -fno-math-errno -ftree-vectorize -ffinite-math-only -fomit-frame-pointer -momit-leaf-frame-pointer -mcx16 -minline-all-stringops -fwrapv -fvectorize -fstrict-enums -fno-dollars-in-identifiers -Xanalyzer -strip-dead-debug-info -Xclang -vectorize-slp-aggressive
		endif
	# INTEL
	else ifeq ($(dcj),INTEL)
		override STD::=-std=c11
		override CC::=gcc
		override ARCH::=-mtune=intel
		override DEBUG::=-DNDEBUG -g0 -ggdb0 -s -Wl,-gc-sections -Wl,-s,-S -DNOAUTHOR -DNOVERSION
		override SECURITY::=1
		override XOPTMZ::=-fno-signed-zeros -fno-math-errno -fno-signaling-nans -ftree-vectorize -ffinite-math-only -fomit-frame-pointer -momit-leaf-frame-pointer -maccumulate-outgoing-args -minline-all-stringops -fwrapv -funsafe-loop-optimizations -fno-exceptions -fira-loop-pressure -fmodulo-sched -fmodulo-sched-allow-regmoves -freschedule-modulo-scheduled-loops -fselective-scheduling -fselective-scheduling2 -fsel-sched-pipelining -fsel-sched-pipelining-outer-loops -fsel-sched-reschedule-pipelined -floop-nest-optimize -floop-parallelize-all
		override WARN::=-Wall -Wextra -pedantic -Wformat -Werror=format-security -Wformat-nonliteral -Wformat-signedness -Wformat-y2k -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wstrict-overflow=5 -Wuninitialized -Wshadow -Wpointer-arith -Wcast-align -Wcast-qual -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -Wconversion -Wbad-function-cast -Wdouble-promotion -Wmissing-include-dirs -Wswitch-enum -Wswitch-bool -Wsync-nand -Winit-self -Wsuggest-final-types -Wsuggest-final-methods -Wundef -Wdate-time -Wjump-misses-init -Wlogical-op -Wopenmp-simd -Wpacked -Winvalid-pch -Wunsafe-loop-optimizations -Wdisabled-optimization -Wstack-protector -Wswitch-default -Wpadded
		PYVERSION::=3.4
		CPYTHON::=34
		override LIBEXT::=so
		ifeq ($(INTEL),32)
			override BITS::=-m32 -DENV32BIT
			override ARCH_I386::=I386
		else
			override BITS::=-m64 -mlong-double-128 -DENV64BIT
		endif
	# GENERICX86
	else ifeq ($(dcj),GENERICX86)
		override STD::=-std=c11
		override CC::=gcc
		override ARCH::=-mtune=generic
		override BITS::=-m32 -DENV32BIT
		override DEBUG::=-DNDEBUG -g0 -ggdb0 -s -Wl,-gc-sections -Wl,-s,-S -DNOAUTHOR -DNOVERSION
		override SECURITY::=1
		override XOPTMZ::=-fno-signed-zeros -fno-math-errno -fno-signaling-nans -ftree-vectorize -ffinite-math-only -fomit-frame-pointer -momit-leaf-frame-pointer -maccumulate-outgoing-args -minline-all-stringops -fwrapv -funsafe-loop-optimizations -fno-exceptions -fira-loop-pressure -fmodulo-sched -fmodulo-sched-allow-regmoves -freschedule-modulo-scheduled-loops -fselective-scheduling -fselective-scheduling2 -fsel-sched-pipelining -fsel-sched-pipelining-outer-loops -fsel-sched-reschedule-pipelined -floop-nest-optimize -floop-parallelize-all
		override WARN::=-Wall -Wextra -pedantic -Wformat -Werror=format-security -Wformat-nonliteral -Wformat-signedness -Wformat-y2k -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wstrict-overflow=5 -Wuninitialized -Wshadow -Wpointer-arith -Wcast-align -Wcast-qual -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -Wconversion -Wbad-function-cast -Wdouble-promotion -Wmissing-include-dirs -Wswitch-enum -Wswitch-bool -Wsync-nand -Winit-self -Wsuggest-final-types -Wsuggest-final-methods -Wundef -Wdate-time -Wjump-misses-init -Wlogical-op -Wopenmp-simd -Wpacked -Winvalid-pch -Wunsafe-loop-optimizations -Wdisabled-optimization -Wstack-protector -Wswitch-default -Wpadded
		PYVERSION::=3.4
		CPYTHON::=34
		override LIBEXT::=so
		override ARCH_I386::=I386
	# GENERICX86-64
	else ifeq ($(dcj),GENERICX86_64)
		override STD::=-std=c11
		override CC::=gcc
		override ARCH::=-mtune=generic
		override BITS::=-m64 -DENV64BIT
		override DEBUG::=-DNDEBUG -g0 -ggdb0 -s -Wl,-gc-sections -Wl,-s,-S -DNOAUTHOR -DNOVERSION
		override SECURITY::=1
		override XOPTMZ::=-fno-signed-zeros -fno-math-errno -fno-signaling-nans -ftree-vectorize -ffinite-math-only -fomit-frame-pointer -momit-leaf-frame-pointer -maccumulate-outgoing-args -minline-all-stringops -fwrapv -funsafe-loop-optimizations -fno-exceptions -fira-loop-pressure -fmodulo-sched -fmodulo-sched-allow-regmoves -freschedule-modulo-scheduled-loops -fselective-scheduling -fselective-scheduling2 -fsel-sched-pipelining -fsel-sched-pipelining-outer-loops -fsel-sched-reschedule-pipelined -floop-nest-optimize -floop-parallelize-all -mlong-double-128
		override WARN::=-Wall -Wextra -pedantic -Wformat -Werror=format-security -Wformat-nonliteral -Wformat-signedness -Wformat-y2k -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wstrict-overflow=5 -Wuninitialized -Wshadow -Wpointer-arith -Wcast-align -Wcast-qual -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -Wconversion -Wbad-function-cast -Wdouble-promotion -Wmissing-include-dirs -Wswitch-enum -Wswitch-bool -Wsync-nand -Winit-self -Wsuggest-final-types -Wsuggest-final-methods -Wundef -Wdate-time -Wjump-misses-init -Wlogical-op -Wopenmp-simd -Wpacked -Winvalid-pch -Wunsafe-loop-optimizations -Wdisabled-optimization -Wstack-protector -Wswitch-default -Wpadded
		PYVERSION::=3.4
		CPYTHON::=34
		override LIBEXT::=so
	# RPI
	else ifeq ($(dcj),rpi)
		override STD::=-std=c11
		override ARCH::=-march=armv6zk -mtune=arm1176jzf-s -mfloat-abi=hard -mlittle-endian -mfpu=vfp -marm -mtp=auto
		override BITS::=
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
		override INCLUDES+= $(armgnueabihf_include)
		override LIBS+= $(armgnueabihf_lib)
		override XOPTMZ::=-fno-signed-zeros -fno-math-errno -fno-signaling-nans -fomit-frame-pointer -fno-exceptions
		override DEBUG::=-DNDEBUG -g0 -ggdb0 -s -Wl,-gc-sections -Wl,-s,-S -DNOAUTHOR -DNOVERSION
		PYVERSION::=3.4
		CPYTHON::=34
		override LIBEXT::=so
		override FPIC::=-fPIC
		override LDZ::=-Wl,-z,relro,-z,now
		override FLTO::= -flto -fuse-linker-plugin
		override OS::=POSIX
		override ARCH_ARM::=ARM
		override WARN::=-Wall -Wextra -Wshadow -Wpointer-arith -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations -Winline -Wuninitialized -Wstrict-prototypes -Wbad-function-cast -Wdouble-promotion -Wstrict-overflow=5 -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -Wswitch-enum -Wswitch-bool -Wsync-nand -Winit-self -Wsuggest-final-types -Wsuggest-final-methods -Wundef -Wdate-time -Wjump-misses-init -Wlogical-op -Wopenmp-simd -Winvalid-pch -Wunsafe-loop-optimizations -Wdisabled-optimization -Wstack-protector -Wswitch-default -Wformat -Werror=format-security -Wformat-signedness -Wformat-y2k
	endif
endif

ifdef OPENMP
	override XOPTMZ+=-fopenmp
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

#!/usr/bin/make -f
# -*- coding: utf-8-unix; Mode: Makefile; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=makefile syntax=makefile.doxygen fileformat=unix tabstop=4 :
# kate: encoding utf-8; bom off; syntax makefile; indent-mode normal; eol unix; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Makefile compiling header
#' @file compiling.mk
#' @version 2020.01.01
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# CLANG FLAGS #


override CLANG_OPT::=-O3 -fforce-emit-vtables -fmerge-all-constants -fno-dollars-in-identifiers -fomit-frame-pointer -fstrict-enums -fstrict-float-cast-overflow -ftree-vectorize -funroll-loops -fvectorize -fwrapv -strip-dead-debug-info -Xanalyzer -Xclang
override CLANG_OPT_X86::=

override CLANG_WARN_GENERAL::=-Werror -Wall -Wextra -Wpedantic -Wmissing-declarations -Wmissing-prototypes -Wnested-externs -Wshadow
override CLANG_WARN::=$(CLANG_WARN_GENERAL) -Wbad-function-cast -Wcast-qual -Wconversion -Wdate-time -Wdisabled-optimization -Wformat -Wformat-non-iso -Wformat-nonliteral -Wformat-security -Wformat-y2k -Winit-self -Winline -Winvalid-pch -Wnull-pointer-arithmetic -Wpacked -Wpointer-arith -Wpragma-pack -Wredundant-decls -Wstack-protector -Wstrict-overflow=5 -Wstrict-prototypes -Wswitch-bool -Wswitch-enum -Wtautological-constant-compare -Wundef -Wuninitialized -Wunreachable-code -Wwrite-strings
override CLANG_WARN7::=-Wself-assign -Wself-assign-field -Wsuspicious-bzero -Wsuspicious-memaccess
override CLANG_WARN8::=-Wimplicit-float-conversion -Wimplicit-int-conversion $(CLANG_WARN7)
override CLANG_WARN9::=$(CLANG_WARN8)
override CLANG_WARN10::=-Wbitwise-conditional-parentheses -Wtautological-bitwise-compare -Wtautological-compare -Wtautological-overlap-compare $(CLANG_WARN9)
override CLANG_WARN11::=$(CLANG_WARN10)
override CLANG_WARN12::=$(CLANG_WARN10)

ifeq ($(GCC_MAJOR),7)
    override CLANG_WARN::=$(CLANG_WARN) $(CLANG_WARN7)
else ifeq ($(GCC_MAJOR),8)
    override CLANG_WARN::=$(CLANG_WARN) $(CLANG_WARN8)
else ifeq ($(GCC_MAJOR),9)
    override CLANG_WARN::=$(CLANG_WARN) $(CLANG_WARN9)
else ifeq ($(GCC_MAJOR),10)
    override CLANG_WARN::=$(CLANG_WARN) $(CLANG_WARN10)
else ifeq ($(GCC_MAJOR),11)
    override CLANG_WARN::=$(CLANG_WARN) $(CLANG_WARN11)
else ifeq ($(GCC_MAJOR),12)
    override CLANG_WARN::=$(CLANG_WARN) $(CLANG_WARN12)
endif


# GNU-GCC FLAGS #


override GCC_PARAMS::=--param ggc-min-expand=200 --param ggc-min-heapsize=393216 --param max-gcse-memory=134217728 --param max-cselib-memory-locations=1023 --param max-reload-search-insns=511 --param max-sched-ready-insns=511 --param large-function-growth=200 --param large-function-insns=3200 --param large-unit-insns=20000 --param max-inline-insns-auto=63 --param early-inlining-insns=16 --param inline-min-speedup=4 --param inline-unit-growth=40 --param ipcp-unit-growth=30 --param large-stack-frame=512 --param large-stack-frame-growth=1100
override GCC_PARAMS::=$(GCC_PARAMS) --param max-inline-insns-recursive=512 --param max-inline-insns-recursive-auto=512 --param max-inline-recursive-depth=16 --param max-inline-recursive-depth-auto=16 --param integer-share-limit=65536 --param gcse-unrestricted-cost=2 --param max-hoist-depth=64 --param max-unrolled-insns=256 --param max-average-unrolled-insns=128 --param max-unroll-times=16 --param avg-loop-niter=16 --param vect-max-version-for-alignment-checks=4 --param vect-max-version-for-alias-checks=8 --param max-iterations-to-track=2000 --param max-predicted-iterations=512 --param selsched-max-lookahead=128 --param prefetch-latency=128 --param simultaneous-prefetches=4 --param max-partial-antic-length=256 --param loop-invariant-max-bbs-in-loop=20000 --param loop-max-datarefs-for-datadeps=2000 --param ipa-cp-value-list-size=16
override GCC_OPT::=$(GCC_PARAMS) -O3 -funroll-loops -funroll-all-loops -funswitch-loops -floop-unroll-and-jam -floop-interchange -faggressive-loop-optimizations -funsafe-loop-optimizations -fira-loop-pressure -fbranch-target-load-optimize2 -fwrapv -fwrapv-pointer -fdelete-dead-exceptions -fno-keep-static-consts -fomit-frame-pointer -fstdarg-opt -ftree-vectorize -fmodulo-sched -fmodulo-sched-allow-regmoves -fselective-scheduling -fselective-scheduling2 -freschedule-modulo-scheduled-loops -fsel-sched-pipelining -fsel-sched-pipelining-outer-loops -fsel-sched-reschedule-pipelined -fgcse -fgcse-sm -fgcse-las -fgcse-after-reload -fdevirtualize-speculatively -fdevirtualize-at-ltrans -flive-range-shrinkage -fisolate-erroneous-paths-attribute -flimit-function-alignment
override GCC_OPT_SKYLAKE::=-maccumulate-outgoing-args -maes -mavx -mavx2 -mbmi -mbmi2 -mcld -mclflushopt -mcrc32 -mcx16 -mf16c -mfsgsbase -minline-all-stringops -mlong-double-128 -mmmx -mmovbe -momit-leaf-frame-pointer -mpclmul -mpopcnt -mrdrnd -mrdseed -mrecip -msahf -msse -msse2 -msse3 -msse4.1 -msse4.2 -mssse3 -mvzeroupper -mxsave -mxsavec -mxsaves -Wl,-z,ibtplt

ifndef ARCH
    ARCH::=
endif

ifeq ($(ARCH),intel)
    override ARCH::=-mtune=$(ARCH)
else ifeq ($(ARCH),generic)
    override ARCH::=-mtune=$(ARCH)
else ifeq ($(ARCH),haswell)
    override ARCH::=-march=$(ARCH) -mavx -mcld -mcrc32 -mcx16 -mmovbe -msahf -mvzeroupper
else ifeq ($(ARCH),broadwell)
    override ARCH::=-march=$(ARCH) -mavx -mcld -mcrc32 -mcx16 -mmovbe -msahf -mvzeroupper
else ifeq ($(ARCH),bonnell)
    override ARCH::=-march=$(ARCH) -mavx -mcld -mcrc32 -mcx16 -mmovbe -msahf -mvzeroupper
else ifeq ($(ARCH),silvermont)
    override ARCH::=-march=$(ARCH) -mavx -mcld -mcrc32 -mcx16 -mmovbe -msahf -mvzeroupper
else ifeq ($(ARCH),skylake)
    override ARCH::=-march=skylake
    override GCC_OPT::=$(GCC_OPT) $(GCC_OPT_SKYLAKE) $(ARCH)
else ifeq ($(ARCH),coffeelake)
    override ARCH::=-march=skylake
    override GCC_OPT::=$(GCC_OPT) $(GCC_OPT_SKYLAKE) $(ARCH)
else ifeq ($(ARCH),cannonlake)
    override ARCH::=-march=skylake
    override GCC_OPT::=$(GCC_OPT) $(GCC_OPT_SKYLAKE) $(ARCH)
else
    ifdef ARCH
        override ARCH::=-march=$(ARCH)
        override GCC_OPT::=$(GCC_OPT) $(ARCH)
    endif
endif

override GCC_WARN_GENERAL::=-Werror -Wall -Wextra -Wpedantic -Wmisleading-indentation -Wmissing-declarations -Wmissing-prototypes -Wshadow
override GCC_WARN::=$(GCC_WARN_GENERAL) -Waggregate-return -Walloc-zero -Warray-bounds -Wattribute-alias=2 -Wbad-function-cast -Wcast-align -Wcast-qual -Wconversion -Wdangling-else -Wdate-time -Wdisabled-optimization -Wdouble-promotion -Wduplicated-branches -Wduplicated-cond -Wformat -Wformat-nonliteral -Wformat-overflow=2 -Wformat-security -Wformat-signedness -Wformat-truncation=2 -Wformat-y2k -Winit-self -Winline -Winvalid-pch -Wjump-misses-init -Wlogical-op -Wnested-externs -Wopenmp-simd -Woverlength-strings -Wpacked -Wpadded -Wpointer-arith -Wredundant-decls -Wrestrict -Wshift-negative-value -Wstack-protector -Wstrict-aliasing=3 -Wstrict-prototypes -Wsuggest-attribute=const -Wsuggest-attribute=format -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wsuggest-final-methods -Wsuggest-final-types -Wswitch-bool -Wswitch-default -Wswitch-enum -Wswitch-unreachable -Wsync-nand -Wtrampolines -Wundef -Wuninitialized -Wunsafe-loop-optimizations -Wunused-const-variable=2 -Wunused-parameter -Wunused-result -Wvector-operation-performance -Wwrite-strings
override GCC_WARN8::=-Wmultistatement-macros -Wpacked-not-aligned -Wsizeof-pointer-div -Wstringop-truncation -Wsuggest-attribute=cold -Wsuggest-attribute=malloc
# -Wcast-align=strict
override GCC_WARN9::=-Wabsolute-value -Waddress-of-packed-member $(GCC_WARN8)

ifeq ($(GCC_MAJOR),7)
    override GCC_WARN::=$(GCC_WARN) $(GCC_WARN7)
else ifeq ($(GCC_MAJOR),8)
    override GCC_WARN::=$(GCC_WARN) $(GCC_WARN8)
else ifeq ($(GCC_MAJOR),9)
    override GCC_WARN::=$(GCC_WARN) $(GCC_WARN9)
else ifeq ($(GCC_MAJOR),10)
    override GCC_WARN::=$(GCC_WARN) $(GCC_WARN10)
endif


# WARNING FLAGS #


ifdef WARN
    ifeq ($(WARN),0)
        ifdef USECLANG
            override WARN::=$(CLANG_WARN)
        else
            override WARN::=$(GCC_WARN)
        endif
    else ifeq ($(WARN),1)
        ifdef USECLANG
            override WARN::=$(CLANG_WARN_GENERAL)
        else
            override WARN::=$(GCC_WARN_GENERAL)
        endif
    else ifeq ($(WARN),2)
        override WARN::=-Wtraditional
    else
        override WARN::=-Wall -Wextra -Wpedantic
    endif
else
    WARN::=-Wall -Wextra
endif


# C LANGUAGE STANDARD VERSION #


ifndef STD
    STD::=-std=c11
else
    ifeq ($(STD),gnu11)
        override STD::=-std=gnu11
    else ifeq ($(STD),gnu17)
        override STD::=-std=gnu17
    else ifeq ($(STD),gnu18)
        override STD::=-std=gnu18
    else ifeq ($(STD),c17)
        override STD::=-std=c17
    else ifeq ($(STD),c18)
        override STD::=-std=c18
    else
        override STD::=-std=c11
    endif
endif


# INCLUDES & LIBRARIES #


override POSIX_INCLUDE::=-I/usr/include -I/usr/local/include -I/opt/include
override POSIX_LINK::=-L/lib -L/usr/lib -L/usr/local/lib -L/opt/lib

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

ifeq ($(ABI),mingw32)
    ifeq ($(GCC_PREFIX),x86_64-w64-mingw32)
        override INCLUDE::=$(mingw64_include) $(INCLUDE)
        override LIBS::=$(mingw64_lib) $(LIBS)
    else
        override INCLUDE::=$(mingw32_include) $(INCLUDE)
        override LIBS::=$(mingw32_lib) $(LIBS)
    endif
else ifeq ($(OS),ANDROID)
    override INCLUDE::=$(armandroideabi_include) $(INCLUDE)
    override LIBS::=$(armgnueabisf_lib) $(LIBS)
else ifeq ($(OS),LINUX)
    ifeq ($(CPU_TYPE),armhf)
        override INCLUDE::=$(armgnueabihf_include) $(INCLUDE)
        override LIBS::=$(armgnueabihf_lib) $(LIBS)
    else ifeq ($(CPU_TYPE),arm)
        override INCLUDE::=$(armgnueabihf_include) $(INCLUDE)
        override LIBS::=$(armgnueabihf_lib) $(LIBS)
    else ifeq ($(CPU_TYPE),armel)
        override INCLUDE::=$(armgnueabi_include) $(INCLUDE)
        override LIBS::=$(armgnueabi_lib) $(LIBS)
    else ifeq ($(CPU_TYPE),armsf)
        override INCLUDE::=$(armgnueabi_include) $(INCLUDE)
        override LIBS::=$(armgnueabi_lib) $(LIBS)
    endif
endif

override SRCINCLUDE::=$(__MODULE_VERSION__) -I$(INCDIR)
ifdef INCLUDE
    ifeq ($(shell test -d $(HOME_INCLUDE) && printf 'true'),'true')
        override INCLUDE::=$(SRCINCLUDE) $(INCLUDE) $(POSIX_INCLUDE) $(HOME_INCLUDE)
    else
        override INCLUDE::=$(SRCINCLUDE) $(INCLUDE) $(POSIX_INCLUDE)
    endif
else
    ifeq ($(shell test -d $(HOME_INCLUDE) && printf 'true'),'true')
        override INCLUDE::=$(SRCINCLUDE) $(POSIX_INCLUDE) $(HOME_INCLUDE)
    else
        override INCLUDE::=$(SRCINCLUDE) $(POSIX_INCLUDE)
    endif
endif
ifdef LIBS
    ifeq ($(shell test -d $(HOME_LIB) && printf 'true'),'true')
        override LIBS::=$(LIBS) $(POSIX_LINK) $(HOME_LIB)
    else
        override LIBS::=$(LIBS) $(POSIX_LINK)
    endif
else
    ifeq ($(shell test -d $(HOME_LIB) && printf 'true'),'true')
        override LIBS::=$(POSIX_LINK) $(HOME_LIB)
    else
        override LIBS::=$(POSIX_LINK)
    endif
endif




# COMPILER DIAGNOSTICS #


ifdef DIAG
    ifeq ($(DIAG),0)
        override DIAG::=
    else ifeq ($(DIAG),)
        override DIAG::=
    else ifeq ($(DIAG),lto)
        # Output LTO statistics
        override DIAG::=-flto-report
    else ifeq ($(DIAG),mem)
        # Output memory statistics
        override DIAG::=-fmem-report
    else ifeq ($(DIAG),T)
        # Output compiler time (user, system)
        override DIAG::=-time
    else ifeq ($(DIAG),Tx)
        # Output detailed compiler time
        override DIAG::=-time -ftime-report
    else ifeq ($(DIAG),X)
        # Output compiler statistics
        override DIAG::=-time -ftime-report -fmem-report
    else ifeq ($(DIAG),L)
        # List linked files
        override DIAG::=-Wl,--trace,--verbose
    else ifeq ($(DIAG),o)
        override DIAG::=-Q --help=optimizers
    else ifeq ($(DIAG),opt)
        override DIAG::=-Q --help=optimizers
    else ifeq ($(DIAG),p)
        override DIAG::=-Q --help=params
    else ifeq ($(DIAG),t)
        override DIAG::=-Q --help=target
    else ifeq ($(DIAG),w)
        override DIAG::=-Q --help=common,warnings --help=c,warnings
    else ifeq ($(DIAG),all)
        override DIAG::=-Q --help=target --help=optimizers --help=common,warnings --help=c,warnings --help=params
    else ifeq ($(DIAG),a)
        override DIAG::=-Q --help=target --help=optimizers --help=common,warnings --help=c,warnings --help=params
    else
        override DIAG::=
    endif
else
    override DIAG::=
endif

ifdef DUMP
    ifeq ($(DUMP),const)
        # Dump functions with constants computed
        override DUMP::=-fdump-tree-original=$(TESTINGDIR)/dump_const.original
    else ifeq ($(DUMP),addr)
        # Dump addresses
        override DUMP::=-fdump-translation-unit-address=$(TESTINGDIR)/addr.dump
    else ifeq ($(DUMP),asmcons)
        # Dump fixed RTL statements that had unsatisfied in/out constraints
        override DUMP::=-dp -fdump-rtl-asmcons=$(TESTINGDIR)/asmcons.dump
    else ifeq ($(DUMP),graph)
        # Dump graphs
        override DUMP::=-fdump-tree-all-graph=$(TESTINGDIR)/dump_graph
    else
        override DUMP::=
    endif
else
    override DUMP::=
endif


# DEBUGGING #


override DCJ_DEBUG::=-DNDEBUG -DNOAUTHOR -DNOVERSION -g0 -ggdb0 -s -fno-verbose-asm
ifeq ($(OS),WINDOWS)
    override DCJ_DEBUG::=$(DCJ_DEBUG) -Wl,--strip-all
else
    override DCJ_DEBUG::=$(DCJ_DEBUG) -Wl,--discard-all,--discard-locals,--gc-sections,--strip-all,--strip-debug,--strip-discarded,--unresolved-symbols=report-all
endif

ifdef DEBUG
    ifeq ($(DEBUG),0)
        override DEBUG::=
        override DCJ_DEBUG::=
    else ifeq ($(DEBUG),1)
        override DEBUG::=-DDEBUG
        override DCJ_DEBUG::=
    else ifeq ($(DEBUG),2)
        override DEBUG::=-DDEBUG -Og -g2 -ggdb2 -fverbose-asm
        override DCJ_DEBUG::=
    else ifeq ($(DEBUG),3)
        override DEBUG::=-DDEBUG -Og -g3 -ggdb3 -fverbose-asm
        override DCJ_DEBUG::=
    else ifeq ($(DEBUG),4)
        override DEBUG::=-DNDEBUG -DNOAUTHOR -DNOVERSION -g1 -ggdb1 -fverbose-asm
        override DCJ_DEBUG::=
    else
        override DEBUG::=$(DCJ_DEBUG)
    endif
else
    DEBUG::=$(DCJ_DEBUG)
endif


# EXTRA OPTIMIZATION PARAMETERS #


ifdef USECLANG
    override COMPILER_XOPT::=-ffinite-math-only -fno-math-errno -fno-signed-zeros
else
    override COMPILER_XOPT::=-ffinite-math-only -fno-exceptions -fno-math-errno -fno-signaling-nans -fno-signed-zeros -fno-trapping-math
endif
ifdef XOPT
    ifeq ($(XOPT),0)
        override XOPT::=
    else ifeq ($(XOPT),1)
        override XOPT::=$(COMPILER_XOPT)
    else ifeq ($(XOPT),2)
        override XOPT::=$(COMPILER_XOPT) -funsafe-math-optimizations
    else ifeq ($(XOPT),3)
        override XOPT::=$(COMPILER_XOPT) -ffast-math
    else
        override XOPT::=
    endif
else
    XOPT::=
endif
ifdef dcj
    ifeq ($(dcj),1)
        ifdef USECLANG
            override XOPTMZ::=$(LLVM_OPT) $(LLVM_OPT_X86)
        else
            override XOPTMZ::=$(GCC_OPT) $(GCC_OPT_X86) -mfpmath=sse
        endif
    endif
    ifdef XOPTMZ
        override XOPTMZ::=$(XOPTMZ) $(XOPT)
    else
        override XOPTMZ::=$(XOPT)
    endif
else
    XOPTMZ::=$(XOPT)
endif

ifdef OPENMP
    override XOPTMZ::=$(XOPTMZ) -fopenmp
endif


# ASSEMBLER PARAMETERS #


override ASZ::=-Wa,-R,--fatal-warnings,--strip-local-absolute


# LINKING PARAMETERS #


override DCJ_LDZ::=-Wl,-O3,-z,relro,-z,now,--fatal-warnings,--hash-size=16368,--sort-common=descending
override WIN_LDZ::=-Wl,-O3,--fatal-warnings,--hash-size=16368

override LD_PARAMS::=

ifeq ($(OS),WINDOWS)
    ifndef LTO
        LTO::=
    endif
    override LDZ::=$(WIN_LDZ)
    override PIC::=
    override LIBEXT::=dll
    override WIN::=-fms-extensions -mwin32
    override WINCUI::=-mconsole $(WIN)
    override WINLIB::=-mdll $(WIN)
else
    ifndef LTO
        LTO::=-flto -fuse-linker-plugin
    endif
    override LDZ::=$(DCJ_LDZ)
    override PIC::=-fpic
    override LIBEXT::=so
    override WIN::=
    override WINCUI::=
    override WINLIB::=
endif
ifdef USECLANG
    override LTO::=
    override LDZ::=
endif

ifndef PYINCLUDE
    PYINCLUDE::=-I"/usr/include/python$(PYVERSION)m"
else ifeq ($(PYINCLUDE),1)
    override PRIVATE_PYTHON::=1
    override PYINCLUDE::=-I./python
    override PYCFLAGS::=
    override SOABI::="cpython-$(CPYTHON)m"
    override PYEXT::=".$(SOABI).$(LIBEXT)"
endif

ifndef SOABI
    SOABI::="cpython-$(CPYTHON)m"
    PYEXT::=".$(SOABI).$(LIBEXT)"
endif

# Alternate linker
ifdef LINKER
    ifeq ($(LINKER),bfd)
        override LD::=bfd -fuse-ld=bfd -D__BFD_LINKER__
    else ifeq ($(LINKER),gold)
        override LD::=gold -fuse-ld=gold -D__GOLD_LINKER__
    else ifeq ($(LINKER),lld)
        override LD::=lld
    else ifdef USECLANG
        override LINKER::=lld
        override LD::=lld
    else
        override LINKER::=$(GCC_PREFIX)ld
        override LD::=$(GCC_PREFIX)ld
    endif
    override LTO::=
else
    LINKER::=$(GCC_PREFIX)ld
    LD::=$(GCC_PREFIX)ld
endif


# SETUP ADDITIONAL PARAMETERS #


# Pthread
ifdef PTHREAD
    ifneq ($(OS),WINDOWS)
        override ARCH::=$(ARCH) -pthread -D__PTHREAD_ENABLED__
    endif
endif

# Stack Protector
ifdef SECURITY
    ifeq ($(SECURITY),1)
        override POSIX_STACK_PROTECTOR::=-fstack-protector
    else ifeq ($(SECURITY),2)
        override POSIX_STACK_PROTECTOR::=-fstack-protector-strong
    else ifeq ($(SECURITY),3)
        override POSIX_STACK_PROTECTOR::=-fstack-protector-all
    else
        override POSIX_STACK_PROTECTOR::=
    endif
else
    POSIX_STACK_PROTECTOR::=
endif
ifeq ($(OS),WINDOWS)
    override ARCH::=$(ARCH) -fno-stack-protector -D_FORTIFY_SOURCE=0
endif


# FINALIZE PARAMETERS #


ifdef OUTPUT
    override STARTUP::=
else
    ifeq ($(CPU_TYPE),x86_64)
        override STARTUP::=$(INCDIR)/start_x86_64.s
    else
        override STARTUP::=
    endif
endif

ifdef USECLANG
    override MINCODE::=-Wl,-U,main,--entry="_start" -DUSE_BAREBONES -DNEEDS_STARTUP -nostdlib -nodefaultlibs -nostartfiles -ffreestanding $(STARTUP)
else
    override MINCODE::=-Wl,--entry="_start" -DUSE_BAREBONES -DNEEDS_STARTUP -nostdlib -nodefaultlibs -nostartfiles -fno-hosted -ffreestanding -fno-tree-loop-distribute-patterns $(STARTUP)
endif

override COMMON_ARGUMENTS::=$(WARN) $(ARCH) $(BITS) $(STD) $(XOPTMZ) $(DEBUG) $(DIAG) $(DUMP)
override COMMON_POSIX_ARGUMENTS::=$(POSIX_STACK_PROTECTOR) -ffunction-sections -fdata-sections

ifdef USECLANG
    override SPOPT::=
else
    override SPOPT::=-fwhole-program
endif

override EXE_PARAMS::=$(INCLUDE) $(SPOPT) $(COMMON_ARGUMENTS) $(ASZ)
override STATIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(ASZ)

ifeq ($(OS),WINDOWS)
    override EXE_PARAMS::=$(EXE_PARAMS) $(WINLIB) $(LDZ)
    override MINEXE_PARAMS::=$(SRCINCLUDE) $(SPOPT) $(COMMON_ARGUMENTS) $(MINCODE) $(LDZ)
    override PIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ) -c $(PIC)
    override LIB_PARAMS::=$(__MODULE_VERSION__) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ)
    override STATIC_PARAMS::=$(STATIC_PARAMS) $(WINLIB) $(LDZ) -c $(PIC)
else
    override EXE_PARAMS::=$(EXE_PARAMS) $(COMMON_POSIX_ARGUMENTS) $(LDZ)
    override MINEXE_PARAMS::=$(SRCINCLUDE) $(SPOPT) $(LTO) -ffunction-sections -fdata-sections $(COMMON_ARGUMENTS) $(MINCODE) $(LDZ)
    override PIC_PARAMS::=$(INCLUDE) $(LTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(PIC)
    override LIB_PARAMS::=$(__MODULE_VERSION__) $(LTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) -Wl,--no-whole-archive $(LDZ) -shared
    override STATIC_PARAMS::=$(STATIC_PARAMS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(PIC)
endif

override CC::=$(CBUILD) $(INCLUDE) -Wl,--rpath="$(LIBS)"
override LD::=$(LD) $(LIBS)


# SPECIAL LLVM+CLANG FEATURES #


ifdef LLVM_PIE
    override LLVM_PIE::=-enable-pie
else
    LLVM_PIE::=
endif

# *.c/*.cpp => *.ll (LLVM IR/Intermediate-Language file)
LLVM_INTERMEDIATE::=$(CLANG) $(CLANG_WARN) $(ARCH) $(BITS) $(STD) -O3 $(DEBUG) -fdata-sections -ffunction-sections -fstack-protector -fstrict-aliasing -fstrict-overflow -funroll-loops -S -emit-llvm

# *.c/*.cpp => *.bc (LLVM Bytecode file); To execute LLVM *.bc files, run `lli ./FILE.bc ARGS`
LLVM_BYTECODE::=$(CLANG) $(CLANG_WARN) $(ARCH) $(BITS) $(STD) -O3 $(DEBUG) -fdata-sections -ffunction-sections -fstack-protector -fstrict-aliasing -fstrict-overflow -funroll-loops -emit-llvm -c

# LLVM Bytecode (*.bc) => LLVM AT&T Assembly (*.s)
LLVM_BC2ATTASM::=llc $(ARCH) -O=3 -data-sections $(LLVM_PIE) -filetype=asm --x86-asm-syntax=att

# LLVM Bytecode (*.bc) => LLVM INTEL Assembly (*.s)
LLVM_BC2INTELASM::=llc $(ARCH) -O=3 -data-sections $(LLVM_PIE) -filetype=asm --x86-asm-syntax=intel

# LLVM Bytecode (*.bc) => Object file (*.o)
LLVM_BC2OBJ::=llc $(ARCH) -O=3 -data-sections $(LLVM_PIE) -filetype=obj

# *.c/*.cpp => *.ast (Clang AST file)
CLANG_AST::=$(CLANG) $(CLANG_WARN) $(ARCH) $(BITS) $(STD) -O3 $(DEBUG) -fdata-sections -ffunction-sections -fstack-protector -fstrict-aliasing -fstrict-overflow -funroll-loops -S -emit-ast

# Run Clang preprocessor on src and output preprocessed code (*.i)
CLANG_PREPRO::=$(CLANG) $(ARCH) $(STD) -E

# Pre-compiled headers (*.pch)
COMPILED_HEADERS::=$(CLANG) $(ARCH) $(STD) -x c-header

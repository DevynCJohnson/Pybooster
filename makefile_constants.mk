#!/usr/bin/make -f
# -*- coding: utf-8-unix; Mode: Makefile; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=makefile syntax=makefile.doxygen fileformat=unix tabstop=4 :
# kate: encoding utf-8; bom off; syntax makefile; indent-mode normal; eol unix; indent-width 4; tab-width 4; remove-trailing-space on;
# @brief Makefile constants header (contains common code)
#' @file makefile
#' @version 2019.03.28
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# VERSION TIMESTAMP #


__VERSION__::=$(shell date +'%Y.%m.%d')
__TODAY__::=$(shell date +'%B %d, %Y')
__MODULE_VERSION__::=-D__MODULE_VERSION__=\"$(__VERSION__)\"


# PATHS #


override BINDIR::=/usr/bin
override BOOTDIR::=/boot
override DEBUGGINGDIR::=./testing
override DEVDIR::=/dev
override ETCDIR::=/etc
override GTKLANGSPECS2DIR::=/usr/share/gtksourceview-2.0/language-specs
override GTKLANGSPECS3DIR::=/usr/share/gtksourceview-3.0/language-specs
override LICENSESDIR::=/usr/share/common-licenses
override MANPAGEDIR::=/usr/share/man
override PIXMAPDIR::=/usr/share/pixmaps
override PYPATH::=/usr/lib/python
override SYSAPPDIR::=/usr/share/applications
override SYSBINDIR::=/bin
override SYSDOCDIR::=/usr/share/doc
override SYSINCLUDEDIR::=/usr/src/include
override SYSMENUDIR::=/usr/share/menu
override SYSMIMEDIR::=/usr/share/mime
override SYSNANORCDIR::=/usr/share/nano
override SYSTHEMEDIR::=/usr/share/icons
override TESTINGDIR::=$(DEBUGGINGDIR)


# CONSTANTS #


UID::=$(shell id -u)
UNAME::=$(shell uname | tr '[:lower:]' '[:upper:]')
UNAME_P::=$(shell uname -p)
USERNAME::=$(shell whoami)
ifndef OS
    OS::=$(UNAME)
endif
ifndef PLATFORM
    PLATFORM::=$(UNAME_P)
endif
override LANG::=$(shell locale | grep 'LANG=' | sed 's/LANG=//')
LC_ALL::=$(LANG)
override POSIX_INCLUDE::=-I/usr/include -I/usr/local/include -I/opt/include -I~/.local/include
override POSIX_LINK::=-L/lib -L/usr/lib -L/usr/local/lib -L/opt/lib -L~/.local/lib
ifndef OMP_THREAD_LIMIT
    OMP_THREAD_LIMIT::=4
endif
override LLVM_WARN::=-Werror -Wall -Wextra -Wpedantic -Wbad-function-cast -Wcast-qual -Wconversion -Wdate-time -Wdisabled-optimization -Wformat -Wformat-non-iso -Wformat-nonliteral -Wformat-security -Wformat-y2k -Winit-self -Winline -Winvalid-pch -Wmissing-declarations -Wmissing-include-dirs -Wmissing-prototypes -Wnested-externs -Wnull-pointer-arithmetic -Wpacked -Wpointer-arith -Wpragma-pack -Wredundant-decls -Wshadow -Wstack-protector -Wstrict-overflow=5 -Wstrict-prototypes -Wswitch-bool -Wswitch-enum -Wtautological-compare -Wtautological-constant-compare -Wundef -Wunreachable-code -Wuninitialized -Wwrite-strings
override LLVM_OPT::=-O3 -fforce-emit-vtables -fstrict-float-cast-overflow -funroll-loops -fwrapv -fomit-frame-pointer -ftree-vectorize -fvectorize -fstrict-enums -fno-dollars-in-identifiers -Xanalyzer -strip-dead-debug-info -Xclang
override LLVM_OPT_X86::=
override GCC_PARAMS::=--param ggc-min-expand=200 --param ggc-min-heapsize=393216 --param max-gcse-memory=134217728 --param sccvn-max-scc-size=20000 --param max-cselib-memory-locations=1023 --param max-reload-search-insns=511 --param max-sched-ready-insns=511 --param large-function-growth=200 --param large-function-insns=3200 --param large-unit-insns=20000 --param max-inline-insns-auto=63 --param early-inlining-insns=16 --param inline-min-speedup=4 --param inline-unit-growth=40 --param ipcp-unit-growth=30 --param large-stack-frame=512 --param large-stack-frame-growth=1100 --param max-inline-insns-recursive=512 --param max-inline-insns-recursive-auto=512 --param max-inline-recursive-depth=16 --param max-inline-recursive-depth-auto=16 --param integer-share-limit=65536 --param gcse-unrestricted-cost=2 --param max-hoist-depth=64 --param max-unrolled-insns=256 --param max-average-unrolled-insns=128 --param max-unroll-times=16 --param avg-loop-niter=16 --param vect-max-version-for-alignment-checks=4 --param vect-max-version-for-alias-checks=8 --param max-iterations-to-track=2000 --param max-predicted-iterations=512 --param selsched-max-lookahead=128 --param prefetch-latency=128 --param simultaneous-prefetches=4 --param max-partial-antic-length=256 --param loop-invariant-max-bbs-in-loop=20000 --param loop-max-datarefs-for-datadeps=2000 --param ipa-cp-value-list-size=16
override GCC_WARN::=-Werror -Wall -Wextra -Wpedantic -Waggregate-return -Walloc-zero -Wbad-function-cast -Wcast-align -Wcast-qual -Wconversion -Wdangling-else -Wdate-time -Wdisabled-optimization -Wdouble-promotion -Wduplicated-branches -Wduplicated-cond -Wformat -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat-truncation=2 -Wformat-y2k -Winit-self -Winline -Winvalid-pch -Wjump-misses-init -Wlogical-op -Wmisleading-indentation -Wmissing-attributes -Wmissing-declarations -Wmissing-include-dirs -Wmissing-prototypes -Wmultistatement-macros -Wnested-externs -Wopenmp-simd -Woverlength-strings -Wpacked -Wpacked-not-aligned -Wpadded -Wpointer-arith -Wredundant-decls -Wrestrict -Wshadow -Wshift-negative-value -Wstack-protector -Wstrict-aliasing=3 -Wstrict-prototypes -Wsuggest-attribute=const -Wsuggest-attribute=format -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wsuggest-final-methods -Wsuggest-final-types -Wswitch-bool -Wswitch-default -Wswitch-enum -Wswitch-unreachable -Wsync-nand -Wtrampolines -Wundef -Wuninitialized -Wunsafe-loop-optimizations -Wunused-const-variable=2 -Wunused-parameter -Wunused-result -Wvector-operation-performance -Wwrite-strings -Wwrite-strings
override GCC_OPT::=$(GCC_PARAMS) -O3 -funroll-loops -funroll-all-loops -funswitch-loops -floop-unroll-and-jam -floop-interchange -faggressive-loop-optimizations -funsafe-loop-optimizations -fira-loop-pressure -fbranch-target-load-optimize2 -fwrapv -fwrapv-pointer -fno-verbose-asm -fdelete-dead-exceptions -fno-keep-static-consts -fomit-frame-pointer -fstdarg-opt -ftree-vectorize -fmodulo-sched -fmodulo-sched-allow-regmoves -fselective-scheduling -fselective-scheduling2 -freschedule-modulo-scheduled-loops -fsel-sched-pipelining -fsel-sched-pipelining-outer-loops -fsel-sched-reschedule-pipelined -fgcse -fgcse-sm -fgcse-las -fgcse-after-reload -fdevirtualize-speculatively -fdevirtualize-at-ltrans -flive-range-shrinkage -fisolate-erroneous-paths-attribute -flimit-function-alignment
override GCC_OPT_X86::=-maccumulate-outgoing-args -maes -mavx -mavx2 -mbmi -mbmi2 -mcld -mcrc32 -mcx16 -mf16c -mfsgsbase -minline-all-stringops -mlong-double-128 -mmmx -mmovbe -momit-leaf-frame-pointer -mpclmul -mpopcnt -mrdrnd -mrecip -msahf -msse -msse2 -msse3 -msse4.1 -msse4.2 -mssse3 -mvzeroupper -Wl,-z,ibtplt
override DCJ_LDZ::=-Wl,-O3,-z,relro,-z,now,--fatal-warnings,--hash-size=16368,--sort-common=descending
override WIN_LDZ::=-Wl,-O3,--fatal-warnings,--hash-size=16368
override STRIP_PARAMS::=--strip-debug --strip-unneeded --discard-locals --remove-section=.eh_frame --remove-section=.eh_frame_hdr --remove-section=.note --remove-section=.note.ABI-tag --remove-section=.note.gnu.build-id --remove-section=.comment --remove-section=.gnu.version --remove-section=.jcr --remove-section=.line --remove-section=.stab --remove-section=.stabstr


# CONSTANT PATTERNS #


comma::=,
REMINDER_CMTS::=DEBUG|DEPRECATED|DISABLED|FINISH|FIX|FIXME|REPAIR|TESTING|TODEBUG|TODO|TOMV|TORM|XXX
OLD_REMINDERS::=DEBUG|DEPRECATED|DISABLED|FINISH|FIX|FIXME|REPAIR|TESTING|TODEBUG|TODO|TOMV|TORM|XXX
DOCCMT_KEYWORDS::=a addindex addtogroup anchor annotatedclasslist arg attention author authors b brief bug c callergraph callgraph category cite class classhierarchy code cond copybrief copydetails copydoc copyright date def defgroup define deprecated details diafile dir docbookonly dontinclude dot dotfile e else elseif em endcode endcond enddocbookonly enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endparblock endrtfonly endsecreflist enduml endverbatim endxmlonly enum example exception extends f[ f] file fn functionindex f{ f} header headerfile headerfilelist hidecallergraph hidecallgraph hideinitializer htmlinclude htmlonly idlexcept if ifnot image implements include includedoc includelineno ingroup inherit interface internal invariant l latexinclude latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] parblock post postheader pre private privatesection property protected protectedsection protocol public publicsection pure ref refitem related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa secreflist section see short showinitializer since skip skipline snippet snippetdoc snippetlineno startuml static struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version vhdlflow warning weakgroup xmlonly xrefitem


# COMMANDS #


ifdef ComSpec
    override COPY::=copy /Y
    override RM::=del /F /Q
else
    override COPY::=cp -f --preserve=mode
    override RM::=rm -f
endif
override CHMOD::=chmod -f
override CHMODR::=chmod -f -R
override CHOWN::=chown -f
override CHOWNR::=chown -f -R
override CPDIR::=cp -f --preserve=mode -r
override CURUSEROWNS::=$(CHOWNR) $(USERNAME):$(USERNAME)
override LNDIR::=ln -f -s
override LNHARD::=ln -f
override LNSOFT::=ln -f -s
override MKDIR::=mkdir -m 755
override MKDIRS::=mkdir -m 755 -p
override MOVE::=mv -f
override PYDOC::=python3 -m pydoc
override RMDIR::=rm -f -r
override is_UPDATEICONCACHE_present::=$(shell command -p -v gtk-update-icon-cache)
ifneq ($(is_UPDATEICONCACHE_present),'')
    override UPDATEICONCACHE::=gtk-update-icon-cache --force --include-image-data --quiet
else
    override UPDATEICONCACHE::=printf '\x1b[31mgtk-update-icon-cache: command not found!\x1b[0m\n' #
endif
override is_UPDATEDESKTOP_present::=$(shell command -p -v update-desktop-database)
override is_UPDATEMIME_present::=$(shell command -p -v update-mime-database)
ifneq ($(is_UPDATEDESKTOP_present),'')
    override UPDATEDESKTOP::=update-desktop-database
else
    override UPDATEDESKTOP::=printf '\x1b[31mupdate-desktop-database: command not found!\x1b[0m\n' #
endif
ifneq ($(is_UPDATEMIME_present),'')
    override UPDATEMIME::=update-mime-database
else
    override UPDATEMIME::=printf '\x1b[31mupdate-mime-database: command not found!\x1b[0m\n' #
endif
override is_XDGMIME_present::=$(shell command -p -v xdg-mime)
ifneq ($(is_XDGMIME_present),'')
    override XDGMIME::=xdg-mime
else
    override XDGMIME::=printf '\x1b[31mxdg-mime: command not found!\x1b[0m\n' #
endif


# VARIOUS UTILITIES #


ARFLAGS::=
FC::=fort77
FFLAGS::=-O 1
LEX::=lex
LFLAGS::=
YACC::=yacc
YFLAGS::=

override USECCACHE::=$(shell command -v ccache)
COMPILER_CLANG::=$(USECCACHE) clang
COMPILER_GCC::=$(USECCACHE) gcc
COMPILER_MUSL_GCC::=$(USECCACHE) musl-gcc
COMPILER_CCACHE::=$(USECCACHE)

# Flag used to indicate that Clang should be used
ifdef dcj
    ifeq ($(dcj),1c)
        override dcj::=1
        override USECLANG::=7
    endif
endif
ifdef USECLANG
    ifeq ($(USECLANG),)
        override CLANG::=7
    else ifeq ($(USECLANG),9)
        override CLANG::=9
    else ifeq ($(USECLANG),9.0)
        override CLANG::=9.0
    else ifeq ($(USECLANG),8)
        override CLANG::=8
    else ifeq ($(USECLANG),8.0)
        override CLANG::=8.0
    else ifeq ($(USECLANG),7)
        override CLANG::=7
    else ifeq ($(USECLANG),7.0)
        override CLANG::=7.0
    else ifeq ($(USECLANG),6)
        override CLANG::=6
    else ifeq ($(USECLANG),6.0)
        override CLANG::=6.0
    else ifeq ($(USECLANG),5)
        override CLANG::=5
    else ifeq ($(USECLANG),5.5)
        override CLANG::=5.5
    else ifeq ($(USECLANG),5.0)
        override CLANG::=5.0
    else
        override CLANG::=USECLANG
    endif
endif

# Command used to access Clang
ifdef CLANG
    ifeq ($(CLANG),)
        override CLANG::=clang -Qunused-arguments
    else
        override CLANG::=clang-$(CLANG) -Qunused-arguments
    endif
else
    CLANG::=clang -Qunused-arguments
endif


# INCLUDES #


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


# WARNINGS #


ifdef WARN
    ifeq ($(WARN),0)
        override WARN::=-Werror -Wall -Wextra -Wpedantic -Waggregate-return -Wbad-function-cast -Wcast-align -Wcast-qual -Wconversion -Wdate-time -Wdisabled-optimization -Wdouble-promotion -Wduplicated-cond -Wformat -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat-y2k -Winit-self -Winline -Winvalid-pch -Wjump-misses-init -Wlogical-op -Wmisleading-indentation -Wmissing-declarations -Wmissing-include-dirs -Wmissing-prototypes -Wnested-externs -Wopenmp-simd -Woverlength-strings -Wpacked -Wpadded -Wpointer-arith -Wredundant-decls -Wshadow -Wshift-negative-value -Wstack-protector -Wstrict-aliasing=3 -Wstrict-prototypes -Wsuggest-attribute=const -Wsuggest-attribute=format -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wsuggest-final-methods -Wsuggest-final-types -Wswitch-bool -Wswitch-default -Wswitch-enum -Wsync-nand -Wtrampolines -Wundef -Wuninitialized -Wunsafe-loop-optimizations -Wunused-const-variable=2 -Wunused-parameter -Wunused-result -Wvector-operation-performance -Wwrite-strings -Wwrite-strings
    else ifeq ($(WARN),1)
        override WARN::=-Wall -Wextra -Wpedantic -Wbad-function-cast -Wcast-align -Wcast-qual -Wconversion -Wdate-time -Wdisabled-optimization -Wdouble-promotion -Wformat -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat-y2k -Winit-self -Winline -Winvalid-pch -Wjump-misses-init -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wmissing-prototypes -Wnested-externs -Wopenmp-simd -Wpacked -Wpadded -Wpointer-arith -Wredundant-decls -Wshadow -Wstack-protector -Wstrict-prototypes -Wsuggest-final-methods -Wsuggest-final-types -Wswitch-bool -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wuninitialized -Wunsafe-loop-optimizations -Wvector-operation-performance -Wwrite-strings
    else ifeq ($(WARN),2)
        override WARN::=-Wtraditional
    else
        override WARN::=-Wall -Wextra -Wpedantic
    endif
else
    WARN::=-Wall -Wextra
endif


# CROSS-COMPILING #


# Set `CROSS_COMPILE`
ifdef CROSS_COMPILE
    override CROSS_COMPILE::=$(shell echo '$(CROSS_COMPILE)' | tr '[:lower:]' '[:upper:]')
    ifeq ($(CROSS_COMPILE),RPI)
        override dcj::=rpi
    else ifeq ($(CROSS_COMPILE),X86_64)
        override CROSS_COMPILE::=x86-64
    else ifeq ($(CROSS_COMPILE),X86-64)
        override CROSS_COMPILE::=x86-64
    else ifeq ($(CROSS_COMPILE),AMD64)
        override CROSS_COMPILE::=x86-64
    else ifeq ($(CROSS_COMPILE),64)
        override CROSS_COMPILE::=x86-64
    else ifeq ($(CROSS_COMPILE),64BIT)
        override CROSS_COMPILE::=x86-64
    else ifeq ($(CROSS_COMPILE),32)
        override CROSS_COMPILE::=x86
    else ifeq ($(CROSS_COMPILE),32BIT)
        override CROSS_COMPILE::=x86
    else ifeq ($(CROSS_COMPILE),X86)
        override CROSS_COMPILE::=x86
    endif
    ifeq ($(CROSS_COMPILE),x86-64)
        override PLATFORM::=x86-64
    else ifeq ($(CROSS_COMPILE),x86)
        override PLATFORM::=x86
    endif
endif

ifdef CROSS_COMPILE
    override undefine LINKER
    override undefine STDLIB
    # Windows
    ifeq ($(OS),WIN32)
        override OS::=WIN
        override CROSS_COMPILE::=x86
    else ifeq ($(OS),WIN64)
        override OS::=WIN
        override CROSS_COMPILE::=x86-64
    else ifeq ($(OS),WIN)
        override OS::=WIN
        override CROSS_COMPILE::=x86-64
    else ifeq ($(OS),WINDOWS_NT)
        override OS::=WIN
        override CROSS_COMPILE::=x86-64
    else ifndef MSVC
        ifeq ($(filter CYGWIN%,$(OS)),CYGWIN)
            override OS::=WIN
            override CROSS_COMPILE::=x86-64
        else ifeq ($(OS),CYGWIN32)
            override OS::=WIN
            override CROSS_COMPILE::=x86-64
        else ifeq ($(OS),CYGWIN64)
            override OS::=WIN
            override CROSS_COMPILE::=x86-64
        else ifeq ($(OS),INTERIX)
            override OS::=WIN
            override CROSS_COMPILE::=x86-64
        else ifeq ($(OS),MINGW32_NT)
            override OS::=WIN
            override CROSS_COMPILE::=x86
        else ifeq ($(OS),MINGW64_NT)
            override OS::=WIN
            override CROSS_COMPILE::=x86-64
        else ifeq ($(filter MINGW%,$(OS)),MINGW)
            override OS::=WIN
            override CROSS_COMPILE::=x86-64
        else ifeq ($(filter MSYS%,$(OS)),MSYS)
            override OS::=WIN
            override CROSS_COMPILE::=x86-64
        endif
    endif
    ifeq ($(OS),WIN)
        ifeq ($(CROSS_COMPILE),x86)
            override OS::=win32
        else
            override OS::=win64
        endif
        # Windows (i686)
        ifeq ($(CROSS_COMPILE),win32)
            override GCC_PREFIX::=i686-w64-mingw32
            override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=$(GCC_PREFIX)-
            override INCLUDE::=$(mingw32_include) $(INCLUDE)
            override LIBS::=$(mingw32_lib) $(LIBS)
            override CC::=$(CBUILD) -m32 $(INCLUDE) -Wl,--rpath="$(LIBS)" -DENV32BIT
            override LD::=$(CROSS_COMPILE)ld $(LIBS)
            override BITS::=32
        # Windows (x86-64)
        else ifeq ($(CROSS_COMPILE),win64)
            override GCC_PREFIX::=x86_64-w64-mingw32
            override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=$(GCC_PREFIX)-
            override INCLUDE::=$(INCLUDE) $(mingw64_include)
            override LIBS::=$(mingw64_lib) $(LIBS)
            override CC::=$(CBUILD) $(INCLUDE) -Wl,--rpath="$(LIBS)"
            override LD::=$(CROSS_COMPILE)ld $(LIBS)
            override BITS::=64
        endif
        override OS::=WIN
        override STDLIB::=STANDARD
    # (POSIX and/or Unix)
    # Android (ARM)
    else ifeq ($(CROSS_COMPILE),android)
        override GCC_PREFIX::=arm-linux-androideabi
        override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
        override CHOST::=$(CBUILD)
        override CROSS_COMPILE::=$(GCC_PREFIX)-
        override INCLUDE::=$(INCLUDE) $(armandroideabi_include)
        override LIBS::=$(armgnueabisf_lib) $(LIBS)
        override CC::=$(CBUILD) $(INCLUDE) -Wl,--rpath="$(LIBS)"
        override LD::=$(CROSS_COMPILE)ld $(LIBS)
        override OS::=ANDROID
        override STDLIB::=STANDARD
        override BITS::=32
    # Linux
    else ifeq ($(OS),LINUX)
        # x86 and x86-64
        ifeq ($(CROSS_COMPILE),x86)
            override GCC_PREFIX::=x86-linux-gnu
            override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=$(GCC_PREFIX)-
            override CC::=$(CBUILD)
            override BITS::=32
        else ifeq ($(CROSS_COMPILE),x86-64)
            override GCC_PREFIX::=x86_64-linux-gnu
            override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=$(GCC_PREFIX)-
            override CC::=$(CBUILD)
            override BITS::=64
        # ARM
        else ifeq ($(CROSS_COMPILE),armhf)
            override GCC_PREFIX::=arm-linux-gnueabihf
            override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=$(GCC_PREFIX)-
            override INCLUDE::=$(armgnueabihf_include) $(INCLUDE)
            override LIBS::=$(armgnueabihf_lib) $(LIBS)
            override CC::=$(CBUILD) $(INCLUDE) -Wl,--rpath="$(LIBS)"
            override LD::=$(CROSS_COMPILE)ld $(LIBS)
            override BITS::=32
        else ifeq ($(CROSS_COMPILE),arm)
            override GCC_PREFIX::=arm-linux-gnueabihf
            override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=$(GCC_PREFIX)-
            override INCLUDE::=$(armgnueabihf_include) $(INCLUDE)
            override LIBS::=$(armgnueabihf_lib) $(LIBS)
            override CC::=$(CBUILD) $(INCLUDE) -Wl,--rpath="$(LIBS)"
            override LD::=$(CROSS_COMPILE)ld $(LIBS)
            override BITS::=32
        else ifeq ($(CROSS_COMPILE),armel)
            override GCC_PREFIX::=arm-linux-gnueabi
            override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=$(GCC_PREFIX)-
            override INCLUDE::=$(armgnueabi_include) $(INCLUDE)
            override LIBS::=$(armgnueabi_lib) $(LIBS)
            override CC::=$(CBUILD) $(INCLUDE) -Wl,--rpath="$(LIBS)"
            override LD::=$(CROSS_COMPILE)ld $(LIBS)
            override BITS::=32
        else ifeq ($(CROSS_COMPILE),armsf)
            override GCC_PREFIX::=arm-linux-gnueabi
            override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=$(GCC_PREFIX)-
            override INCLUDE::=$(armgnueabi_include) $(INCLUDE)
            override LIBS::=$(armgnueabi_lib) $(LIBS)
            override CC::=$(CBUILD) $(INCLUDE) -Wl,--rpath="$(LIBS)"
            override LD::=$(CROSS_COMPILE)ld $(LIBS)
            override BITS::=32
        endif
        override OS::=POSIX
    endif
endif

# Operating System
ifdef OS
    ifeq ($(OS),BSD)
        override OS::=POSIX
    else ifeq ($(OS),DARWIN)
        override OS::=POSIX
    else ifeq ($(OS),DRAGONFLY)
        override OS::=POSIX
    else ifeq ($(OS),FREEBSD)
        override OS::=POSIX
    else ifeq ($(OS),GNU)
        override OS::=POSIX
    else ifeq ($(OS),GNU/KFREEBSD)
        override OS::=POSIX
    else ifeq ($(OS),LINUX)
        override OS::=POSIX
    else ifeq ($(OS),NETBSD)
        override OS::=POSIX
    else ifeq ($(OS),OPENBSD)
        override OS::=POSIX
    else ifeq ($(OS),OSX)
        override OS::=POSIX
        override ETCDIR::=/private
    else ifeq ($(OS),SOLARIS)
        override OS::=POSIX
    endif
endif


# DEBUGGING #


override DCJ_DEBUG::=-DNDEBUG -DNOAUTHOR -DNOVERSION -g0 -ggdb0 -s
ifeq ($(OS),WIN)
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
        override DEBUG::=-DDEBUG -g3 -ggdb3
        override DCJ_DEBUG::=
    else
        override DEBUG::=$(DCJ_DEBUG)
    endif
else
    DEBUG::=$(DCJ_DEBUG)
endif


# LINKING PARAMETERS #


ifeq ($(OS),WIN)
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

# Alternate linker
ifdef LINKER
    ifeq ($(LINKER),bfd)
        override LD::=bfd
        override LINKER::=-fuse-ld=bfd -D__BFD_LINKER__
        override LTO::=
    else ifeq ($(LINKER),gold)
        override LD::=gold
        override LINKER::=-fuse-ld=gold -D__GOLD_LINKER__
        override LTO::=
    else
        override LINKER::=
    endif
else
    LINKER::=
endif


# PROFILES #


ifdef PROFILE
    override dcj::=$(PROFILE)
else ifdef DCJ
    override dcj::=$(DCJ)
endif
ifdef dcj
    ifeq ($(dcj),py)
        override dcj::=1
    endif
endif

ifdef dcj
    override ASZ::=-Wa,-R,--fatal-warnings,--strip-local-absolute
    override SECURITY::=0
    override PYVERSION::=3.6
    override CPYTHON::=36
    override LC_ALL::=en_US.UTF-8
    override LANG::=en_US.UTF-8
    override LANGUSA::=en
    ifndef DIAG
        override DIAG::=T
    endif
    ifeq ($(dcj),1)
        # Standard Skylake Configuration (Linux64)
        override GCC_PREFIX::=x86_64-linux-gnu
        override ARCH::=-march=skylake
        override BITS::=64
        override PLATFORM::=x86-64
        override STD::=-std=c11
        override OS::=POSIX
        override DEBUG::=$(DCJ_DEBUG)
        override PIC::=-fpic
        ifndef USECLANG
            override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=$(GCC_PREFIX)-
            ifdef MUSL
                override CC::=musl-gcc -D__MUSL__
            else
                override CC::=$(CBUILD)
            endif
            override WARN::=$(GCC_WARN)
            override XOPTMZ::=$(GCC_OPT) $(GCC_OPT_X86) -mfpmath=sse
        else
            override CBUILD::=$(COMPILER_CCACHE) $(CLANG)
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=llvm-
            override CC::=$(CBUILD)
            override WARN::=$(LLVM_WARN)
            override XOPTMZ::=$(LLVM_OPT) $(LLVM_OPT_X86)
        endif
    else ifeq ($(dcj),broadwell)
        # Standard Broadwell Configuration (Linux64)
        override GCC_PREFIX::=x86_64-linux-gnu
        override ARCH::=-march=broadwell
        override BITS::=64
        override PLATFORM::=x86-64
        override STD::=-std=c11
        override OS::=POSIX
        override DEBUG::=$(DCJ_DEBUG)
        override PIC::=-fpic
        ifndef USECLANG
            override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=$(GCC_PREFIX)-
            ifdef MUSL
                override CC::=musl-gcc -D__MUSL__
            else
                override CC::=$(CBUILD)
            endif
            override WARN::=$(GCC_WARN)
            override XOPTMZ::=$(GCC_OPT) $(GCC_OPT_X86) -mfpmath=sse
        else
            override CBUILD::=$(COMPILER_CCACHE) $(CLANG)
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=llvm-
            override CC::=$(CBUILD)
            override WARN::=$(LLVM_WARN)
            override XOPTMZ::=$(LLVM_OPT) $(LLVM_OPT_X86)
        endif
    else ifeq ($(dcj),haswell)
        # Standard Haswell Configuration (Linux64)
        override GCC_PREFIX::=x86_64-linux-gnu
        override ARCH::=-march=haswell
        override BITS::=64
        override PLATFORM::=x86-64
        override STD::=-std=c11
        override OS::=POSIX
        override DEBUG::=$(DCJ_DEBUG)
        override PIC::=-fpic
        ifndef USECLANG
            override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=$(GCC_PREFIX)-
            ifdef MUSL
                override CC::=musl-gcc -D__MUSL__
            else
                override CC::=$(CBUILD)
            endif
            override WARN::=$(GCC_WARN)
            override XOPTMZ::=$(GCC_OPT) $(GCC_OPT_X86) -mfpmath=sse $(ASZ)
        else
            override CBUILD::=$(COMPILER_CCACHE) $(CLANG)
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=llvm-
            override CC::=$(CBUILD)
            override WARN::=$(LLVM_WARN)
            override XOPTMZ::=$(LLVM_OPT) $(LLVM_OPT_X86)
        endif
    else ifeq ($(dcj),cannonlake)
        # Standard Cannonlake Configuration (Linux64)
        override GCC_PREFIX::=x86_64-linux-gnu
        override ARCH::=-march=cannonlake
        override BITS::=64
        override PLATFORM::=x86-64
        override STD::=-std=c11
        override OS::=POSIX
        override DEBUG::=$(DCJ_DEBUG)
        override PIC::=-fpic
        ifndef USECLANG
            override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=$(GCC_PREFIX)-
            ifdef MUSL
                override CC::=musl-gcc -D__MUSL__
            else
                override CC::=$(CBUILD)
            endif
            override WARN::=$(GCC_WARN)
            override XOPTMZ::=$(GCC_OPT) $(GCC_OPT_X86) -mfpmath=sse
        else
            override CBUILD::=$(COMPILER_CCACHE) $(CLANG)
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=llvm-
            override CC::=$(CBUILD)
            override WARN::=$(LLVM_WARN)
            override XOPTMZ::=$(LLVM_OPT) $(LLVM_OPT_X86)
        endif
    # INTEL
    else ifeq ($(dcj),INTEL)
        override ARCH::=-mtune=intel
        ifeq ($(INTEL),32)
            override BITS::=32
            override PLATFORM::=x86
        else
            override BITS::=64
            override PLATFORM::=x86-64
        endif
        override STD::=-std=c11
        ifndef USECLANG
            ifdef MUSL
                override CBUILD::=$(COMPILER_CCACHE) musl-gcc
                override CC::=musl-gcc -D__MUSL__
            else
                override CBUILD::=$(COMPILER_CCACHE) gcc
                override CC::=$(CBUILD)
            endif
            override XOPTMZ::=$(GCC_OPT) -maccumulate-outgoing-args -minline-all-stringops -momit-leaf-frame-pointer
            override WARN::=$(GCC_WARN)
        else
            override CBUILD::=$(COMPILER_CCACHE) $(CLANG)
            override CC::=$(CBUILD)
            override XOPTMZ::=$(LLVM_OPT) -minline-all-stringops -momit-leaf-frame-pointer
            override WARN::=$(LLVM_WARN)
        endif
        override CHOST::=$(CBUILD)
        override DEBUG::=$(DCJ_DEBUG)
    # Generic x86
    else ifeq ($(dcj),GENERICX86)
        override ARCH::=-mtune=generic
        override BITS::=32
        override PLATFORM::=x86
        override STD::=-std=c11
        ifndef USECLANG
            ifdef MUSL
                override CBUILD::=$(COMPILER_CCACHE) musl-gcc
                override CC::=musl-gcc -D__MUSL__
            else
                override CBUILD::=$(COMPILER_CCACHE) gcc
                override CC::=$(CBUILD)
            endif
            override XOPTMZ::=$(GCC_OPT) -maccumulate-outgoing-args -minline-all-stringops -momit-leaf-frame-pointer
            override WARN::=$(GCC_WARN)
        else
            override CBUILD::=$(COMPILER_CCACHE) $(CLANG)
            override CC::=$(CBUILD)
            override XOPTMZ::=$(LLVM_OPT) -minline-all-stringops -momit-leaf-frame-pointer
            override WARN::=$(LLVM_WARN)
        endif
        override DEBUG::=$(DCJ_DEBUG)
    # Generic x86-64
    else ifeq ($(dcj),GENERICX86_64)
        override ARCH::=-mtune=generic
        override BITS::=64
        override PLATFORM::=x86-64
        override STD::=-std=c11
        ifndef USECLANG
            ifdef MUSL
                override CBUILD::=$(COMPILER_CCACHE) musl-gcc
                override CC::=musl-gcc -D__MUSL__
            else
                override CBUILD::=$(COMPILER_CCACHE) gcc
                override CC::=$(CBUILD)
            endif
            override XOPTMZ::=$(GCC_OPT) -maccumulate-outgoing-args -minline-all-stringops -momit-leaf-frame-pointer
            override WARN::=$(GCC_WARN)
        else
            override CBUILD::=$(COMPILER_CCACHE) $(CLANG)
            override CC::=$(CBUILD)
            override XOPTMZ::=$(LLVM_OPT) -minline-all-stringops -momit-leaf-frame-pointer
            override WARN::=$(LLVM_WARN)
        endif
        override DEBUG::=$(DCJ_DEBUG)
    # RPI
    else ifeq ($(dcj),rpi)
        override GCC_PREFIX::=arm-linux-gnueabihf
        override ENDIAN::=-mlittle-endian
        override FLOATABI::=-mfloat-abi=hard
        override ARCH::=-march=armv6zk -mtune=arm1176jzf-s $(ENDIAN) $(FLOATABI) -mfpu=vfp -marm -mtp=auto
        override BITS::=32
        override PLATFORM::=x86
        override STD::=-std=c11
        override INCLUDE::=$(armgnueabihf_include) $(INCLUDE)
        override LIBS::=$(armgnueabihf_lib) $(LIBS)
        override WARN::=-Wall -Wextra -Wshadow -Wpointer-arith -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations -Winline -Wuninitialized -Wstrict-prototypes -Wbad-function-cast -Wdouble-promotion -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -Wswitch-enum -Wswitch-bool -Wsync-nand -Winit-self -Wsuggest-final-types -Wsuggest-final-methods -Wundef -Wdate-time -Wjump-misses-init -Wlogical-op -Wopenmp-simd -Winvalid-pch -Wunsafe-loop-optimizations -Wdisabled-optimization -Wstack-protector -Wswitch-default -Wformat -Wformat-security -Wformat-signedness -Wformat-y2k
        override XOPTMZ::=-O3 -funroll-loops -fomit-frame-pointer
        ifndef USECLANG
            override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)-gcc
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=$(GCC_PREFIX)-
            ifdef MUSL
                override CC::=musl-gcc -D__MUSL__
            else
                override CC::=$(CBUILD)
            endif
        else
            override CBUILD::=$(COMPILER_CCACHE) $(CLANG)
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=llvm-
            override CC::=$(CBUILD)
        endif
        override CC::=$(CC) $(INCLUDE) -Wl,--rpath=$(LIBS)
        override LD::=$(CROSS_COMPILE)ld $(LIBS)
        override DEBUG::=$(DCJ_DEBUG)
        override PIC::=-fpic
        override OS::=POSIX
    # General x86-64 Linux
    else ifeq ($(dcj),x86_64)
        override GCC_PREFIX::=x86_64-linux-gnu
        override STD::=-std=c11
        override BITS::=64
        override PLATFORM::=x86-64
        override DEBUG::=$(DCJ_DEBUG)
        override OS::=POSIX
        override ARCH::=-mtune=intel
        ifndef USECLANG
            ifdef MUSL
                override CC::=musl-gcc -D__MUSL__
            else
                override CC::=gcc
            endif
            override WARN::=$(GCC_WARN)
            override XOPTMZ::=$(GCC_OPT) -maccumulate-outgoing-args -minline-all-stringops -mlong-double-128 -momit-leaf-frame-pointer
        else
            override CBUILD::=$(COMPILER_CCACHE) $(CLANG)
            override CHOST::=$(CBUILD)
            override CROSS_COMPILE::=llvm-
            override CC::=$(CBUILD)
            override WARN::=$(LLVM_WARN)
            override XOPTMZ::=$(LLVM_OPT) $(LLVM_OPT_X86)
        endif
    # End of profile presets
    endif
endif


# RESOLVE UNDEFINED COMMANDS #


ifdef CROSS_COMPILE
    override AR::=$(CROSS_COMPILE)ar
    override AS::=$(CROSS_COMPILE)as
    override NM::=$(CROSS_COMPILE)nm
    override RANLIB::=$(CROSS_COMPILE)ranlib
    ifndef LD
        ifdef USECLANG
            override LD::=link
        else
            override LD::=ld
        endif
    endif
    ifdef WIN
        override DLLTOOL::=$(CROSS_COMPILE)dlltool
        override WINDRES::=$(CROSS_COMPILE)windres
    endif
    ifndef STRIP
        STRIP::=$(CROSS_COMPILE)strip
    endif
else
    override AR::=ar
    override AS::=as
    override NM::=nm
    override RANLIB::=ranlib
    ifndef LD
        ifdef USECLANG
            override LD::=link
        else
            override LD::=ld
        endif
    endif
    ifdef WIN
        override DLLTOOL::=dlltool
        override WINDRES::=windres
    endif
    ifndef STRIP
        STRIP::=strip
    endif
endif
ifndef WIN
    override DLLTOOL::=
    override WINDRES::=
endif
override STRIP::=$(STRIP) $(STRIP_PARAMS)


# SETUP PARAMETERS #


# C-Standard
ifdef STD
    # GNU
    ifneq ($(STD),-std=c11)
        # GNU
        ifeq ($(STD),gnu11)
            override STD::=-std=gnu11
        # C
        else
            override STD::=-std=c11
        endif
    endif
else
    STD::=-std=c11
endif

# Alternate Standard C Library
ifdef STDLIB
    ifneq ($(STDLIB),STANDARD)
        override STDLIB::=
        ifdef BIONIC
            override STDLIB::=-mbionic
        else ifdef GLIBC
            override STDLIB::=-mglibc
        else ifdef MUSL
            ifndef CROSS_COMPILE
                override CC::=musl-gcc -D__MUSL__
            endif
        else ifdef UCLIBC
            override STDLIB::=-muclibc
        endif
    else ifeq ($(STDLIB),STANDARD)
        override STDLIB::=
    endif
else
    STDLIB::=
endif

# Architecture Flags
ifdef ARCH
    # Intel
    ifeq ($(ARCH),intel)
        override ARCH::=-mtune=$(ARCH)
    else ifeq ($(ARCH),generic)
        override ARCH::=-mtune=$(ARCH)
    else ifeq ($(ARCH),i686)
        override ARCH::=-march=$(ARCH)
        override PLATFORM::=x86
    else ifeq ($(ARCH),pentium4)
        override ARCH::=-march=$(ARCH)
    else ifeq ($(ARCH),sandybridge)
        override ARCH::=-march=$(ARCH)
    else ifeq ($(ARCH),ivybridge)
        override ARCH::=-march=$(ARCH)
    else ifeq ($(ARCH),haswell)
        override ARCH::=-march=$(ARCH) -mavx -mcld -mcrc32 -mcx16 -mmovbe -msahf -mvzeroupper
    else ifeq ($(ARCH),broadwell)
        override ARCH::=-march=$(ARCH) -mavx -mcld -mcrc32 -mcx16 -mmovbe -msahf -mvzeroupper
    else ifeq ($(ARCH),bonnell)
        override ARCH::=-march=$(ARCH) -mavx -mcld -mcrc32 -mcx16 -mmovbe -msahf -mvzeroupper
    else ifeq ($(ARCH),silvermont)
        override ARCH::=-march=$(ARCH) -mavx -mcld -mcrc32 -mcx16 -mmovbe -msahf -mvzeroupper
    else ifeq ($(ARCH),coffeelake)
        override ARCH::=-march=$(ARCH) -maes -mavx -mavx2 -mbmi -mbmi2 -mcld -mclflushopt -mcrc32 -mcx16 -mf16c -mfsgsbase -minline-all-stringops -mmmx -mmovbe -mpclmul -mpopcnt -mrdrnd -mrdseed -mrecip -msahf -msgx -msse -msse2 -msse3 -msse4.1 -msse4.2 -mssse3 -mvzeroupper -mxsave -mxsavec -mxsaves
    else ifeq ($(ARCH),skylake)
        override ARCH::=-march=$(ARCH) -maes -mavx -mavx2 -mbmi -mbmi2 -mcld -mclflushopt -mcrc32 -mcx16 -mf16c -mfsgsbase -minline-all-stringops -mmmx -mmovbe -mpclmul -mpopcnt -mrdrnd -mrdseed -mrecip -msahf -msgx -msse -msse2 -msse3 -msse4.1 -msse4.2 -mssse3 -mvzeroupper -mxsave -mxsavec -mxsaves
    else ifeq ($(ARCH),cannonlake)
        override ARCH::=-march=$(ARCH) -maes -mavx -mavx2 -mbmi -mbmi2 -mcld -mclflushopt -mcrc32 -mcx16 -mf16c -mfsgsbase -minline-all-stringops -mmmx -mmovbe -mpclmul -mpopcnt -mrdrnd -mrdseed -mrecip -msahf -msgx -msse -msse2 -msse3 -msse4.1 -msse4.2 -mssse3 -mvzeroupper -mxsave -mxsavec -mxsaves
    # AMD
    else ifeq ($(ARCH),k6)
        override ARCH::=-march=$(ARCH)
    else ifeq ($(ARCH),athlon)
        override ARCH::=-march=$(ARCH)
    else ifeq ($(ARCH),opteron)
        override ARCH::=-march=$(ARCH)
    # ARM
    else ifeq ($(ARCH),armv6)
        override ARCH::=-march=$(ARCH)
    else ifeq ($(ARCH),armv7)
        override ARCH::=-march=$(ARCH)
    else ifeq ($(ARCH),armv7-a)
        override ARCH::=-march=$(ARCH)
    else ifeq ($(ARCH),armv7-r)
        override ARCH::=-march=$(ARCH)
    else ifeq ($(ARCH),armv7-m)
        override ARCH::=-march=$(ARCH)
    else ifeq ($(ARCH),armv8-a)
        override ARCH::=-march=$(ARCH)
    else ifeq ($(ARCH),armv8-a+crc)
        override ARCH::=-march=$(ARCH)
    else ifeq ($(ARCH),iwmmxt)
        override ARCH::=-march=$(ARCH)
    endif
else
    ARCH::=
endif

# 32 or 64 bits
ifdef BITS
    ifeq ($(BITS),64)
        override BITS::=-m64
    else ifeq ($(BITS),32)
        override BITS::=-m32
    else
        override BITS::=-m64
    endif
else
    BITS::=
endif

# Endianness
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
        override FLOATABI::=-mfloat-abi=soft
    else ifeq ($(FLOATABI),softfp)
        override FLOATABI::=-mfloat-abi=softfp
    else
        override FLOATABI::=-mfloat-abi=hard
    endif
else
    FLOATABI::=
endif

# Pthread
ifneq ($(OS),WIN)
    ifdef PTHREAD
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
ifdef WIN
    override ARCH::=$(ARCH) -fno-stack-protector -D_FORTIFY_SOURCE=0
endif


# ADDITIONAL OPTIMIZATIONS #


# Set optional extra optimization parameters
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
ifdef XOPTMZ
    override XOPTMZ::=$(XOPTMZ) $(XOPT)
else
    XOPTMZ::=$(XOPT)
endif
ifdef OPENMP
    override XOPTMZ::=$(XOPTMZ) -fopenmp
endif


# PYTHON #


override PYCFLAGS::=-DHAVE_GCC_UINT128_T -DHAVE_GCC_INT128_T -DHAVE_SSIZE_T -DPY_FORMAT_SIZE_T="z" -DPY_FORMAT_SSIZE_T="zi" -DPY_FORMAT_LONG_LONG="ll"

ifndef PYVERSION
    PYVERSION::=3.6
    CPYTHON::=36
endif

ifdef PYVERSION
    ifeq ($(PYVERSION),3.4)
        override CPYTHON::=34
    else ifeq ($(PYVERSION),3.5)
        override CPYTHON::=35
    else ifeq ($(PYVERSION),3.6)
        override CPYTHON::=36
    else ifeq ($(PYVERSION),3.7)
        override CPYTHON::=37
    else ifeq ($(PYVERSION),3.8)
        override CPYTHON::=38
    else ifeq ($(PYVERSION),3.9)
        override CPYTHON::=39
    else
        override PYVERSION::=3.6
        override CPYTHON::=36
    endif
else
    PYVERSION::=3.6
    CPYTHON::=36
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


# FINALIZE PARAMETERS #


override INCDIR::=./include
ifdef OUTPUT
    ifeq ($(OUTPUT),asm)
        override STARTUP::=
    else
        override STARTUP::=
    endif
else
    ifeq ($(PLATFORM),x86-64)
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

override SRCINCLUDE::=$(__MODULE_VERSION__) -I$(INCDIR)
ifdef INCLUDE
    override INCLUDE::=$(SRCINCLUDE) $(INCLUDE)
else
    INCLUDE::=$(SRCINCLUDE)
endif

ifeq ($(OS),WIN)
    override EXE_PARAMS::=$(INCLUDE) $(SPOPT) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ)
    override MINEXE_PARAMS::=$(SRCINCLUDE) $(SPOPT) $(COMMON_ARGUMENTS) $(MINCODE) $(LDZ)
    override PIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ) -c $(PIC)
    override LIB_PARAMS::=$(__MODULE_VERSION__) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ)
    override STATIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ) -c $(PIC)
else
    override INCLUDE::=$(INCLUDE) $(POSIX_INCLUDE)
    override EXE_PARAMS::=$(INCLUDE) $(SPOPT) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ)
    override MINEXE_PARAMS::=$(SRCINCLUDE) $(SPOPT) $(LTO) -ffunction-sections -fdata-sections $(COMMON_ARGUMENTS) $(MINCODE) $(LDZ)
    override PIC_PARAMS::=$(INCLUDE) $(LTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(PIC)
    override LIB_PARAMS::=$(__MODULE_VERSION__) $(LTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) -Wl,--no-whole-archive $(LDZ) -shared
    override STATIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(PIC)
endif


# SPECIAL LLVM+CLANG FEATURES #


ifdef LLVM_PIE
    override LLVM_PIE::=-enable-pie
else
    LLVM_PIE::=
endif

# *.c/*.cpp => *.ll (LLVM IR/Intermediate-Language file)
LLVM_INTERMEDIATE::=$(CLANG) $(LLVM_WARN) $(ARCH) $(BITS) $(STD) -O3 $(DEBUG) -fdata-sections -ffunction-sections -fstack-protector -fstrict-aliasing -fstrict-overflow -funroll-loops -S -emit-llvm

# *.c/*.cpp => *.bc (LLVM Bytecode file); To execute LLVM *.bc files, run `lli ./FILE.bc ARGS`
LLVM_BYTECODE::=$(CLANG) $(LLVM_WARN) $(ARCH) $(BITS) $(STD) -O3 $(DEBUG) -fdata-sections -ffunction-sections -fstack-protector -fstrict-aliasing -fstrict-overflow -funroll-loops -emit-llvm -c

# LLVM Bytecode (*.bc) => LLVM AT&T Assembly (*.s)
LLVM_BC2ATTASM::=llc $(ARCH) -O=3 -data-sections $(LLVM_PIE) -filetype=asm --x86-asm-syntax=att

# LLVM Bytecode (*.bc) => LLVM INTEL Assembly (*.s)
LLVM_BC2INTELASM::=llc $(ARCH) -O=3 -data-sections $(LLVM_PIE) -filetype=asm --x86-asm-syntax=intel

# LLVM Bytecode (*.bc) => Object file (*.o)
LLVM_BC2OBJ::=llc $(ARCH) -O=3 -data-sections $(LLVM_PIE) -filetype=obj

# *.c/*.cpp => *.ast (Clang AST file)
CLANG_AST::=$(CLANG) $(LLVM_WARN) $(ARCH) $(BITS) $(STD) -O3 $(DEBUG) -fdata-sections -ffunction-sections -fstack-protector -fstrict-aliasing -fstrict-overflow -funroll-loops -S -emit-ast

# Run Clang preprocessor on src and output preprocessed code (*.i)
CLANG_PREPRO::=$(CLANG) $(ARCH) $(STD) -E

# Pre-compiled headers (*.pch)
COMPILED_HEADERS::=$(CLANG) $(ARCH) $(STD) -x c-header


# CHECKSUM COMMANDS #


.PHONY : genchecksums valchecksums


genchecksums :
	-@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Creating Checksums ==='
	$(RM) ./.checksums.b2b512 ./.checksums.rmd160 ./.checksums.sha1 ./.checksums.sha512 ./.checksums.whirlpool || true
	find . -mount -type f -not \( -name '.checksums.sha512' -o -path "./bin/*" -o -path "./debugging/*" -o -path "./testing/*" -o -path "./.git/*" \) -print0 | xargs -0 openssl dgst -sha512 > "${FOLDER}.checksums.sha512"
	find . -mount -type f -not \( -name '.checksums.whirlpool' -o -path "./bin/*" -o -path "./debugging/*" -o -path "./testing/*" -o -path "./.git/*" \) -print0 | xargs -0 openssl dgst -whirlpool > "${FOLDER}.checksums.whirlpool"
	find . -mount -type f -not \( -name '.checksums.rmd160' -o -path "./bin/*" -o -path "./debugging/*" -o -path "./testing/*" -o -path "./.git/*" \) -print0 | xargs -0 openssl dgst -ripemd160 > "${FOLDER}.checksums.rmd160"
	find . -mount -type f -not \( -name '.checksums.b2b512' -o -path "./bin/*" -o -path "./debugging/*" -o -path "./testing/*" -o -path "./.git/*" \) -print0 | xargs -0 openssl blake2b512 > "${FOLDER}.checksums.b2b512"
	find . -mount -type f -not \( -name '.checksums.sha1' -o -path "./bin/*" -o -path "./debugging/*" -o -path "./testing/*" -o -path "./.git/*" \) -print0 | xargs -0 openssl dgst -sha1 > "${FOLDER}.checksums.sha1"

valchecksums :
	-@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Validating Checksums ==='
	sha512sum --check --quiet --strict ./.checksums.sha512
	sha1sum --check --quiet --strict ./.checksums.sha1


# GIT COMMANDS #


.PHONY : cleangit commit commithash commithashes gitattr gitchanges gitignore gitlastchanges gitlinechanges gitlscommits gitlsconfigs gitlsfiles gitlsuncommitted gitstats gitundoadd lscontrib lstags newchanges news previewcleangit pushtags setkey signoff status tag treehashes uncommit xcommit xtag


commit :
	@printf 'Create a commit message: ' && read -r GITMSG && git commit --cleanup=strip --message="$$GITMSG" --signoff

commithash :
	@git log -1 --pretty=format:"%H"
	git log -1 --pretty=format:"%h"

commithashes :
	@git log --pretty=format:"%H"

cleangit : cleanall fixperm
	-@git reflog expire --all --expire=now --stale-fix
	git rm --cached -r --ignore-unmatch *
	git gc --prune=now --aggressive
	git add --all --refresh
	git fsck --dangling --full --name-objects --progress --strict --unreachable
	git gc --prune=now --aggressive

gitattr :
	@git check-attr --all ./*
	git check-attr --all ./*/*
	git check-attr --all ./*/*/*

gitchanges :
	@git show

gitignore :
	@git check-ignore ./*
	git check-ignore ./*/*
	git check-ignore ./*/*/*

gitlastchanges :
	@git show --summary

gitlinechanges :
	@git show --stat

gitlscommits :
	@git log --pretty=format:'%C(auto) %H | %s | %an | %ar%d'

gitlsconfigs :
	@git config --list

gitlsfiles :
	@git ls-files

gitlsuncommitted :
	@git diff

gitstats :
	-@gitstats ./ $(TESTINGDIR)/git/

gitundoadd :
	-@git reset

lscontrib :
	@git log --format='%aN <%aE>' | sort -n -r | uniq

lstags :
	@git tag

newchanges :
	@git diff HEAD~1

previewcleangit : cleanall fixperm
	-@git reflog expire --dry-run --all --expire=now --stale-fix
	git rm --dry-run --cached -r --ignore-unmatch *
	git prune --dry-run --verbose
	git add --dry-run --all --refresh

pushtags :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Pushing Tags ==='
	git push origin --tags

setkey :
	@git config --global user.signingkey $(key); git config --global commit.gpgsign true; git config --global gpg.program "$(shell which gpg)"

signoff :
	@git commit --amend --signoff

status :
	@git status --ahead-behind --branch --short --verbose

tag :
	@git tag -a 'v$(__VERSION__)' -m 'Stable Release (v$(__VERSION__))'

treehashes :
	@git log --pretty=format:"%T"

uncommit :
	@git reset --soft HEAD~

xcommit :
	@printf 'Create a commit message: ' && read -r GITMSG && git commit --cleanup=strip --message="$$GITMSG" --signoff

xtag :
	@git tag -s -a 'v$(__VERSION__)' -m 'Stable Release (v$(__VERSION__))'


# MISCELLANEOUS PROJECT COMMANDS #


.PHONY : changelogmd gnuchangelog news

changelogmd : ./tools/mkchangelogmd.sh
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Creating Markdown ChangeLog ==='
	$(RM) ./ChangeLog.md
	./tools/mkchangelogmd.sh

gnuchangelog : ./git/
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Creating GNU ChangeLog from Git ==='
	git log --pretty --numstat --summary | git2cl > GNU-ChangeLog

news :
	@([ -f ./ChangeLog ] && $(COPY) ./ChangeLog ./NEWS) || true

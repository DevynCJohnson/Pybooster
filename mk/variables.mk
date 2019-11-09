#!/usr/bin/make -f
# -*- coding: utf-8-unix; Mode: Makefile; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=makefile syntax=makefile.doxygen fileformat=unix tabstop=4 :
# kate: encoding utf-8; bom off; syntax makefile; indent-mode normal; eol unix; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Makefile containing logic to set needed target variables
#' @file variables.mk
#' @version 2019.11.09
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# AVAILABLE COMMANDS #


override COMPILER_CCACHE::=$(shell sh -c 'command -v ccache')
override UPDATEDESKTOP::=$(shell sh -c 'command -p -v update-desktop-database')
override UPDATEICONCACHE::=$(shell sh -c 'command -p -v gtk-update-icon-cache')
ifneq ($(UPDATEICONCACHE),'')
    override UPDATEICONCACHE::=$(UPDATEICONCACHE) --force --include-image-data --quiet
endif
override UPDATEICONCACHE::=$(shell sh -c 'command -p -v gtk-update-icon-cache')
override UPDATEMIME::=$(shell sh -c 'command -p -v update-mime-database')
override XDGMIME::=$(shell sh -c 'command -p -v xdg-mime')


# USER #


UID::=$(shell id -u)
USERNAME::=$(shell whoami)


# SYSTEM INFO & CROSS-COMPILING #


override CPU_COUNT::=$(shell nproc --all)
override UNAME::=$(shell uname | tr '[:lower:]' '[:upper:]')
ifdef ARCH
    override ARCH::=$(shell printf '%s' '$(ARCH)' | tr '[:upper:]' '[:lower:]')
endif
ifdef ENDIAN
    override ENDIAN::=$(shell printf '%s' '$(ENDIAN)' | tr '[:upper:]' '[:lower:]')
endif
override UNAME_P::=$(shell uname -p)
ifeq ($(UNAME_P),'')
    override UNAME_P::=$(shell arch)
endif

ifndef CPU_TYPE
    CPU_TYPE::=$(UNAME_P)
endif

ifdef ComSpec
    override OS::=WINDOWS
    override is_darwin::=
    override is_linux::=
    override is_solaris::=
    override is_windows::=WINDOWS
else
    ifndef OS
        OS::=$(UNAME)
    endif
    override is_darwin::=$(filter DARWIN,$(UNAME))
    override is_linux::=$(filter LINUX,$(UNAME))
    override is_solaris::=$(filter SOLARIS,$(UNAME))
    override is_windows::=$(filter WINDOWS,$(UNAME))
endif

ifndef OMP_THREAD_LIMIT
    OMP_THREAD_LIMIT::=$(CPU_COUNT)
endif


ifdef CROSS_COMPILE

    override CROSS_COMPILE::=$(subst _,-,$(shell printf '%s' '$(CROSS_COMPILE)' | tr '[:upper:]' '[:lower:]'))
    ifeq ($(CROSS_COMPILE),AMD64)
        override CROSS_COMPILE::=x86-64
    else ifeq ($(CROSS_COMPILE),64)
        override CROSS_COMPILE::=x86-64
    else ifeq ($(CROSS_COMPILE),64BIT)
        override CROSS_COMPILE::=x86-64
    else ifeq ($(CROSS_COMPILE),32)
        override CROSS_COMPILE::=x86
    else ifeq ($(CROSS_COMPILE),32BIT)
        override CROSS_COMPILE::=x86
    endif

    # Windows

    ifeq ($(OS),WIN32)
        override OS::=WINDOWS
        override CROSS_COMPILE::=x86
    else ifeq ($(OS),WIN64)
        override OS::=WINDOWS
        override CROSS_COMPILE::=x86-64
    else ifeq ($(OS),WIN)
        override OS::=WINDOWS
        override CROSS_COMPILE::=x86-64
    else ifeq ($(filter WIN%,$(OS)),WIN)
        override OS::=WINDOWS
        override CROSS_COMPILE::=x86-64
    else ifndef MSVC
        ifeq ($(filter CYGWIN%,$(OS)),CYGWIN)
            override OS::=WINDOWS
            override CROSS_COMPILE::=x86-64
        else ifeq ($(OS),CYGWIN32)
            override OS::=WINDOWS
            override CROSS_COMPILE::=x86-64
        else ifeq ($(OS),CYGWIN64)
            override OS::=WINDOWS
            override CROSS_COMPILE::=x86-64
        else ifeq ($(OS),INTERIX)
            override OS::=WINDOWS
            override CROSS_COMPILE::=x86-64
        else ifeq ($(OS),MINGW32_NT)
            override OS::=WINDOWS
            override CROSS_COMPILE::=x86
        else ifeq ($(OS),MINGW64_NT)
            override OS::=WINDOWS
            override CROSS_COMPILE::=x86-64
        else ifeq ($(filter MINGW%,$(OS)),MINGW)
            override OS::=WINDOWS
            override CROSS_COMPILE::=x86-64
        else ifeq ($(filter MSYS%,$(OS)),MSYS)
            override OS::=WINDOWS
            override CROSS_COMPILE::=x86-64
        endif
    endif

    override CPU_TYPE::=$(CROSS_COMPILE)
    ifeq ($(OS),WINDOWS)
        override is_darwin::=
        override is_linux::=
        override is_solaris::=
        override is_windows::=WINDOWS
    endif
endif


ifdef OS
    ifeq ($(OS),BSD)
        override OS_FAMILY::=POSIX
    else ifeq ($(OS),DARWIN)
        override OS_FAMILY::=POSIX
    else ifeq ($(OS),DRAGONFLY)
        override OS_FAMILY::=POSIX
    else ifeq ($(OS),FREEBSD)
        override OS_FAMILY::=POSIX
    else ifeq ($(OS),GNU)
        override OS_FAMILY::=POSIX
    else ifeq ($(OS),GNU/KFREEBSD)
        override OS_FAMILY::=POSIX
    else ifeq ($(OS),LINUX)
        override OS_FAMILY::=POSIX
    else ifeq ($(OS),NETBSD)
        override OS_FAMILY::=POSIX
    else ifeq ($(OS),OPENBSD)
        override OS_FAMILY::=POSIX
    else ifeq ($(OS),OSX)
        override OS_FAMILY::=POSIX
        override ETCDIR::=/private
    else ifeq ($(OS),SOLARIS)
        override OS_FAMILY::=POSIX
    else ifeq ($(OS),WINDOWS)
        override OS_FAMILY::=WINTEL
    endif
endif


# BIT WIDTH & ABI #


override ABI::=gnu
override BITS::=-m64 -DENV64BIT
ifndef BITS
    ifeq ($(CPU_TYPE),x86-64)
        override ABI::=gnu
        override BITS::=-m64 -DENV64BIT
    else ifeq ($(CPU_TYPE),arm)
        override ABI::=gnueabihf
        override BITS::=-m32 -DENV32BIT
    else ifeq ($(CPU_TYPE),armhf)
        override ABI::=gnueabihf
        override BITS::=-m32 -DENV32BIT
    else ifeq ($(CPU_TYPE),armsf)
        override ABI::=gnueabi
        override BITS::=-m32 -DENV32BIT
    else ifeq ($(CPU_TYPE),armel)
        override ABI::=gnueabi
        override BITS::=-m32 -DENV32BIT
    else ifeq ($(CPU_TYPE),x86)
        override ABI::=gnu
        override BITS::=-m32 -DENV32BIT
    endif
endif

ifeq ($(OS),WINDOWS)
    override ABI::=mingw32
else ifeq ($(OS),ANDROID)
    override ABI::=androideabi
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
    ifeq ($(FLOATABI),gnueabihf)
        override FLOATABI::=-mfloat-abi=hard
    else ifeq ($(ABI),gnueabi)
        override FLOATABI::=-mfloat-abi=soft
    else ifeq ($(FLOATABI),soft)
        override FLOATABI::=-mfloat-abi=soft
    else ifeq ($(FLOATABI),softfp)
        override FLOATABI::=-mfloat-abi=softfp
    else
        override FLOATABI::=-mfloat-abi=hard
    endif
else
    FLOATABI::=
endif


# SETUP COMPILER #


ifdef USECLANG
    override CLANG::=clang-$(USECLANG)
else
    override CLANG::=$(shell sh -c 'command -v clang')
endif
ifeq ($(shell sh -c 'command -v $(CLANG)'),'')
    override CLANG::=$(shell sh -c 'command -v clang')
endif

ifdef CLANG
    override CLANG::=$(COMPILER_CCACHE) $(CLANG) -Qunused-arguments
else
    override CLANG::=clang -Qunused-arguments
endif

ifdef BIONIC
    override STDLIB::=-mbionic
else ifdef GLIBC
    override STDLIB::=-mglibc
else ifdef UCLIBC
    override STDLIB::=-muclibc
endif

ifdef USECLANG
    override GCC_PREFIX::=llvm-
    override CBUILD::=$(CLANG)
    override STDLIB::=
else ifdef MUSL
    override GCC_PREFIX::=
    override CBUILD::=$(COMPILER_CCACHE) musl-gcc -D__MUSL__
    override STDLIB::=
else
    ifeq ($(ABI),mingw32)
        ifeq ($(CPU_TYPE),x86-64)
            override GCC_PREFIX::=x86_64-w64-mingw32-
        else
            override GCC_PREFIX::=i686-w64-mingw32-
        endif
    else
        override GCC_PREFIX::=$(subst -,_,$(CPU_TYPE))-$(shell printf '%s' '$(OS)' | tr '[:upper:]' '[:lower:]')-$(ABI)-
    endif
    override CBUILD::=$(COMPILER_CCACHE) $(GCC_PREFIX)gcc
endif

override CHOST::=$(CBUILD)
override CC::=$(CBUILD)

override GCC_MAJOR::=$(shell printf '%s' '__GNUC__' | $(CC) -E -x c - | tail -n 1)
override GCC_MINOR::=$(shell printf '%s' '__GNUC_MINOR__' | $(CC) -E -x c - | tail -n 1)
override GCC_PATCHLEVEL::=$(shell printf '%s' '__GNUC_PATCHLEVEL__' | $(CC) -E -x c - | tail -n 1)
override GCC_VERSION::=$(GCC_MAJOR).$(GCC_MINOR)


# SETUP OTHER TOOLS #


ifeq ($(OS),WINDOWS)
    override DLLTOOL::=$(GCC_PREFIX)dlltool
    override WINDRES::=$(GCC_PREFIX)windres
else
    override DLLTOOL::=
    override WINDRES::=
endif

ifdef GCC_PREFIX
    override AR::=$(GCC_PREFIX)ar
    override AS::=$(GCC_PREFIX)as
    override NM::=$(GCC_PREFIX)nm
    override RANLIB::=$(GCC_PREFIX)ranlib
    override STRIP::=$(GCC_PREFIX)strip
else
    override AR::=ar
    override AS::=as
    override NM::=nm
    override RANLIB::=ranlib
    override STRIP::=strip
endif
override STRIP::=$(STRIP) $(STRIP_PARAMS)

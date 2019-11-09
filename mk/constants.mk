#!/usr/bin/make -f
# -*- coding: utf-8-unix; Mode: Makefile; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=makefile syntax=makefile.doxygen fileformat=unix tabstop=4 :
# kate: encoding utf-8; bom off; syntax makefile; indent-mode normal; eol unix; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Makefile constants header (contains common code)
#' @file constants.mk
#' @version 2019.11.09
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
override HOME_INCLUDE::=~/.local/include
override HOME_LIB::=~/.local/lib
override INCDIR::=./include
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


# CONSTANT PATTERNS #


comma::=,
REMINDER_CMTS::=DEBUG|DEPRECATED|DISABLED|FINISH|FIX|FIXME|REPAIR|TESTING|TODEBUG|TODO|TOMV|TORM|XXX
OLD_REMINDERS::=DEBUG|DEPRECATED|DISABLED|FINISH|FIX|FIXME|REPAIR|TESTING|TODEBUG|TODO|TOMV|TORM|XXX
DOCCMT_KEYWORDS::=a addindex addtogroup anchor annotatedclasslist arg attention author authors b brief bug c callergraph callgraph category cite class classhierarchy code cond copybrief copydetails copydoc copyright date def defgroup define deprecated details diafile dir docbookonly dontinclude dot dotfile e else elseif em endcode endcond enddocbookonly enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endparblock endrtfonly endsecreflist enduml endverbatim endxmlonly enum example exception extends f[ f] file fn functionindex f{ f} header headerfile headerfilelist hidecallergraph hidecallgraph hideinitializer htmlinclude htmlonly idlexcept if ifnot image implements include includedoc includelineno ingroup inherit interface internal invariant l latexinclude latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] parblock post postheader pre private privatesection property protected protectedsection protocol public publicsection pure ref refitem related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa secreflist section see short showinitializer since skip skipline snippet snippetdoc snippetlineno startuml static struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version vhdlflow warning weakgroup xmlonly xrefitem


# COMMANDS #


ARFLAGS::=
DLLTOOL::=
FC::=fort77
FFLAGS::=-O 1
LEX::=lex
LFLAGS::=
WINDRES::=
YACC::=yacc
YFLAGS::=
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
override LNDIR::=ln -f -s
override LNHARD::=ln -f
override LNSOFT::=ln -f -s
override MKDIR::=mkdir -m 755
override MKDIRS::=mkdir -m 755 -p
override MOVE::=mv -f
override PYDOC::=python3 -m pydoc
override RMDIR::=rm -f -r


# COMMAND PARAMETERS #


override STRIP_PARAMS::=--strip-debug --strip-unneeded --discard-locals --remove-section=.eh_frame --remove-section=.eh_frame_hdr --remove-section=.note --remove-section=.note.ABI-tag --remove-section=.note.gnu.build-id --remove-section=.comment --remove-section=.gnu.version --remove-section=.jcr --remove-section=.line --remove-section=.stab --remove-section=.stabstr


# LOCALES #


override LANG::=$(strip $(subst LANG=, ,$(findstring LANG=,$(shell locale))))

ifeq ($(LANG),'')
    override LANG::=en_US.UTF-8
endif
override LC_ALL::=$(LANG)


# PRESET #


ifdef PRESET
    override dcj::=$(PRESET)
else ifdef DCJ
    override dcj::=$(DCJ)
endif
ifdef dcj
    ifeq ($(dcj),py)
        override dcj::=1
    endif
    ifeq ($(dcj),1c)
        override dcj::=1
        override USECLANG::=
    endif
endif

ifdef dcj
    ifeq ($(dcj),1)
        ifndef ARCH
            ARCH::=coffeelake
        endif
        ifndef DIAG
            DIAG::=T
        endif
        ifndef WARN
            WARN::=0
        endif
    endif
endif


# PYTHON #


override PYCFLAGS::=-DHAVE_GCC_UINT128_T -DHAVE_GCC_INT128_T -DHAVE_SSIZE_T -DPY_FORMAT_SIZE_T="z" -DPY_FORMAT_SSIZE_T="zi" -DPY_FORMAT_LONG_LONG="ll"

override PYTHON_MINOR::=$(strip $(firstword $(subst ., ,$(subst Python 3., ,$(shell python3 --version)))))

ifndef PYVERSION
    PYVERSION::=3.$(PYTHON_MINOR)
    CPYTHON::=3$(PYTHON_MINOR)
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
        override PYVERSION::=3.7
        override CPYTHON::=37
    endif
else
    PYVERSION::=3.$(PYTHON_MINOR)
    CPYTHON::=3$(PYTHON_MINOR)
endif

#!/usr/bin/make -f
# -*- coding: utf-8-unix; Mode: Makefile; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=makefile syntax=makefile.doxygen fileformat=unix tabstop=4 :
# kate: encoding utf-8; bom off; syntax makefile; indent-mode normal; eol unix; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;

.POSIX :
.ONESHELL :
override SHELL::=/bin/bash
.SHELLFLAGS::=-c

include makefile_constants.mk


# VARIABLES #


# Project Paths
override ACCDIR::=./accessory
override BIN::=./bin
override DOCDIR::=./doc
override PYEGGDIR::=./pyegg
override PYSRC::=./pylib
override EZWINSRC::=$(PYSRC)/ezwin
override INCDIR::=./include
override LANGSPECSDIR::=./accessory/language_specs
override MENUDIR::=$(ACCDIR)/menu_files
override SCRIPTSRCDIR::=./scripts
override THEMEDIR::=./themes
override TOOLSDIR::=./tools
override SRCDIR::=./src
override XKBDIR::=$(THEMEDIR)/XKB
override PYCACHE::=$(PYEGGDIR)/__pycache__/ $(SCRIPTSRCDIR)/__pycache__/
override MACROSPATH::=$(INCDIR)/Foundation.h $(INCDIR)/MACROS.h $(INCDIR)/MACROS2.h $(INCDIR)/MACROS3.h

# Install Paths
PYPATH::=/usr/lib/python
override INSTALLBINDIR::=/usr/bin
override INSTALLDOCDIR::=/usr/share/doc
override INSTALLHEADERSDIR::=/usr/src/include/pybooster
override INSTALLLANGSPECS2DIR::=/usr/share/gtksourceview-2.0/language-specs
override INSTALLLANGSPECS3DIR::=/usr/share/gtksourceview-3.0/language-specs
override PYBDIR::=/usr/lib/pybooster

# File Lists
override LIST_LANGSPECS::=coffeescript
override LIST_MATH_PROGRAMS::=cos fib isprime sin tan
override LIST_UTIL_PROGRAMS::=getpgid getsid microtime ostype statvfs typesize
override LIST_BIN_PROGRAMS::=$(LIST_MATH_PROGRAMS) $(LIST_UTIL_PROGRAMS)
override LIST_PYTHON_SCRIPTS::=cx_freeze3 cxfreeze3 easy_install3 pip3 pip3-upgrade-all py2dsc pymake pyreverse3 qt5py wpip
override LIST_DEV_SCRIPTS::=canalysis clint cmccabe code-analysis code-formatter exewalk file-analysis flake8 goanalysis luaanalysis pep257 pep8 progstrip pyanalysis py_directive_checker pydocgtk pyflakes2 pyflakes3 pyinspect pylint2 pylint3 pytest3 shanalysis systracer timeit timex transpile xmlanalysis yamlanalysis
override LIST_SCRIPT_PROGRAMS::=alphabetize_lines CamelCase char2num cleansystem genmathart getsysinfo lslibfunc minifyxml num2char prettifyxml refreshgrub replaceoddchars svgresizer termtest thumbnail-cleaner togglequotes win2unixlines
override LIST_PYTHON_LIBRARIES::=astronomy basic bitwise clibutil code_interpreter color compress convarea convlength convmass convspeed convtemp convtime convvolume cryptography electronics ezdisplay filemagic financial fs geo_services libchar libregex markup metric net neuralnet pipx pronouns religion science_data sing strtools system timeutil unix xmath
override LIST_PIP_DEPS::=autopep8 bandit bashate cx-Freeze docformatter flake8 flake8-mypy mccabe mypy mypy_extensions Pillow pycodestyle pydocstyle pyflakes3 pyinstaller pylint pylint-django vulture
override LIST_DEV_DEPS::=binwalk bsdiff cccc complexity cppcheck doxygen doxygen-gui flawfinder geany geany-plugin-addons geany-plugin-ctags geany-plugin-lineoperations gitlint glade kwstyle ltrace optipng pmccabe pngcrush pscan shc shellcheck splint strace uchardet undertaker vbindiff wamerican-insane
override LIST_MAIN_DEPS::=clang cloc colormake gcc licensecheck llvm make moreutils python3-gi python3-logilab-common python3-pip python3-pytest python3-pytest-pep8 sloccount wc xdg-utils xmllint

# Parameters
override SRCINCLUDE::=$(__MODULE_VERSION__) -I$(INCDIR)
ifdef INCLUDE
    override INCLUDE::=$(SRCINCLUDE) $(INCLUDE)
else
    INCLUDE::=$(SRCINCLUDE)
endif
override COMMON_ARGUMENTS::=$(WARN) $(ARCH) $(BITS) $(STD) $(XOPTMZ) $(DEBUG) $(DIAG) $(DUMP)
override COMMON_POSIX_ARGUMENTS::=$(POSIX_STACK_PROTECTOR) -ffunction-sections -fdata-sections
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
override MINCODE::=-DUSE_BAREBONES -DNEEDS_STARTUP -nostdlib -nodefaultlibs -nostartfiles -ffreestanding -fno-tree-loop-distribute-patterns $(STARTUP)

ifeq ($(OS),WIN)
    override EXE_PARAMS::=$(INCLUDE) -fwhole-program $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ)
    override MINEXE_PARAMS::=$(SRCINCLUDE) -fwhole-program $(COMMON_ARGUMENTS) $(MINCODE) $(LDZ)
    override PIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ) -c $(PIC)
    override LIB_PARAMS::=$(__MODULE_VERSION__) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ)
    override STATIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ) -c $(PIC)
else
    override INCLUDE::=$(INCLUDE) $(POSIX_INCLUDE)
    override EXE_PARAMS::=$(INCLUDE) -fwhole-program $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ)
    override MINEXE_PARAMS::=$(SRCINCLUDE) -fwhole-program $(LTO) -ffunction-sections -fdata-sections $(COMMON_ARGUMENTS) $(MINCODE) $(LDZ)
    override PIC_PARAMS::=$(INCLUDE) $(LTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(PIC)
    override LIB_PARAMS::=$(__MODULE_VERSION__) $(LTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) -Wl,--no-whole-archive $(LDZ) -shared
    override STATIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(PIC)
endif
override STRIP::=$(STRIP) $(STRIP_PARAMS)


# HELP #


help :
	@printf '\n\x1b[1;4;33m%s\x1b[0m\n\n' '* COMPILATION INSTRUCTIONS *'
	printf '%s\n%s\n' 'Everything:' '    make all'
	printf '%s\n%s\n' 'Everything (using Clang):' '    make all USECLANG=5.0  # Specify version'
	printf '%s\n%s\n' 'Strip Binaries:' '    make strip'
	printf '\n%s\n%s\n\n' 'Enable Pthread:' '    make all PTHREAD=1'
	printf '%s\n%s\n%s\n' 'Particular Architechure:' '    make all ARCH=intel' '    make all ARCH=intel BITS=64'
	printf '%s\n%s\n\n' '    make all ARCH=haswell' '    make all ARCH=armv7'
	printf '%s\n%s\n%s\n' 'Cross-Compile:' '    make all CROSS_COMPILE=armhf' '    make all CROSS_COMPILE=x86-64'
	printf '%s\n%s\n%s\n' '    make all CROSS_COMPILE=android' '    make all CROSS_COMPILE=rpi' '    NOTE: Windows may not be fully supported'
	printf '\n\n\x1b[1;4;33m%s\x1b[0m\n\n' '* INSTALL/UNINSTALL *'
	printf '%s\n%s\n' 'Install:' '    sudo make install'
	printf '%s\n%s\n' 'Uninstall:' '    sudo make uninstall'
	printf '%s\n%s\n' 'Install /usr/bin Utils:' '    sudo make install_programs'
	printf '%s\n%s\n' 'Install Additional Mimetypes:' '    sudo make install_mimetype_booster'
	printf '%s\n%s\n' 'Install C Libraries:' '    sudo make install_clib'
	printf '%s\n%s\n' 'Install Enhanced XCompose File:' '    make install_xcompose'
	printf '%s\n%s\n' 'Install Language Specification Files:' '    sudo make install_langspecs'
	printf '%s\n%s\n' 'Install Opticons:' '    sudo make install_opticons'
	printf '%s\n%s\n' 'Install Python Eggs:' '    sudo make install_pyeggs'
	printf '%s\n%s\n' 'Install Python Libraries:' '    sudo make install_pylib'
	printf '%s\n%s\n' 'Install Scripts:' '    sudo make install_scripts'
	printf '%s\n%s\n' 'Install System Shell Profile:' '    sudo make install_shrc'
	printf '%s\n%s\n' 'Install Themes & Icons:' '    sudo make install_themes'
	printf '%s\n%s\n' 'Install XKB Files:' '    sudo make install_xkb'
	printf '\n\n\x1b[1;4;33m%s\x1b[0m\n\n' '* PROJECT MANAGEMENT *'
	printf '%s\n%s\n' 'Backup Project:' '    make backup'
	printf '%s\n%s\n' 'Create 7z Backup:' '    make pkg7z'
	printf '%s\n%s\n' 'Create Zip Backup:' '    make pkgzip'
	printf '%s\n%s\n' 'Fix File Permissions:' '    make fixperm'
	printf '%s\n%s\n' 'Generate CTags:' '    make ctags'
	printf '%s\n%s\n' 'Generate All Documentation:' '    make doc'
	printf '%s\n%s\n' 'Generate C Documentation:' '    make docc'
	printf '%s\n%s\n' 'Generate Python Documentation:' '    make docpy'
	printf '%s\n%s\n' 'Package Release:' '    make pkg'
	printf '%s\n%s\n' 'Refresh Files (cleanall, fixperm, & upver):' '    make refresh'
	printf '%s\n%s\n' 'Syncronize Version Numbers:' '    make upver'
	printf '\n\n\x1b[1;4;33m%s\x1b[0m\n\n' '* CLEAN *'
	printf '%s\n%s\n' 'Clean Everything and Documentation:' '    make cleanfull'
	printf '%s\n%s\n' 'Clean Temp, Object, Cache, and Binary Files:' '    make cleanall'
	printf '%s\n%s\n' 'Remove Documentation:' '    make cleandoc'
	printf '%s\n%s\n' 'Remove Python Cache Files:' '    make rmcache'
	printf '%s\n%s\n' 'Remove Temp and Object Files:' '    make rmtmp'
	printf '%s\n%s\n' 'Remove Temp, Object, and Cache Files:' '    make clean'
	printf '\n\n\x1b[1;4;33m%s\x1b[0m\n\n' '* GIT *'
	printf '%s\n%s\n' 'Add Files to Git:' '    make addgit'
	printf '%s\n%s\n' 'Commit Changes to Git:' '    make commit'
	printf '%s\n%s\n' 'Push Changes to Git:' '    make push'
	printf '%s\n%s\n' 'Get Git Project Status:' '    make stat'
	printf '%s\n%s\n' 'Clean Git Project:' '    make cleangit'
	printf '%s\n%s\n' 'Dry-run Clean Git Project:' '    make previewcleangit'
	printf '\n\n\x1b[1;4;33m%s\x1b[0m\n\n' '* VARIABLES *'
	printf '%s\n%s\n%s\n' 'OS=string' '    POSIX: Linux, Unix, BSD, etc.' '    ANDROID: Android'
	printf '\n\n\x1b[1;4;33m%s\x1b[0m\n\n' '* ENABLE/DISABLE FEATURES/CODE *'
	printf '%s\n' '-DENABLE_BEOS_MACROS: Enable BeOS macros'
	printf '%s\n' '-DENABLE_ELF_HEADERS: Enable ELF headers containing macros, datatypes, etc.'
	printf '%s\n' '-DENABLE_EMBEDDED_DEVICE_DATATYPES: Enable embedded device datatypes'
	printf '%s\n' '-DENABLE_FORMAT_SPECIFIERS: Enable printf/scanf format specifiers'
	printf '%s\n' '-DENABLE_IIO_TYPES: Enable IIO datatypes'
	printf '%s\n' '-DENABLE_MACH_FEATURES: Enable Mach features'
	printf '%s\n' '-DENABLE_PRTYPES: Enable prtypes'
	printf '%s\n' '-DENABLE_XNU_DATATYPES: Enable XNU datatypes'
	printf '%s\n' '-DDISABLE_ANSI_SGR: Disable ANSI SGR features'
	printf '\n\n\x1b[1;4;33m%s\x1b[0m\n\n' '* TWEAK PRINTF *'
	printf '%s\n' '-DNO_PRINT_ACTION: Disable the `%n` (printf action) symbol'
	printf '%s\n' '-DNO_PRINT_M: Disable the `%m` (error code) symbol'
	printf '%s\n' '-DNO_PRINT_CHARS: Disable all character-related symbols'
	printf '%s\n' '-DNO_PRINT_FLOATS: Disable the `%f` and `%g` (float-points) symbols'
	printf '%s\n' '-DNO_PRINT_INTS: Disable all integer-related symbols'
	printf '%s\n' '-DNO_PRINT_STRINGS: Disable all string-related symbols'
	printf '%s\n' '-DNO_PRINT_WIDTH_PREC: Disable all width and precision related symbols'
	printf '%s\n' '-DPRINTF_BUF32: Set the size of the internal printf buffer to 32-bytes'
	printf '%s\n' '-DPRINTF_BUF64: Set the size of the internal printf buffer to 64-bytes'
	printf '%s\n' '-DPRINTF_BUF128: Set the size of the internal printf buffer to 128-bytes'
	printf '%s\n' '-DPRINTF_BUF256: Set the size of the internal printf buffer to 256-bytes'
	printf '%s\n' '-DPRINTF_BUF512: Set the size of the internal printf buffer to 512-bytes'
	printf '%s\n\n' '-DPRINTF_BUF1024: Set the size of the internal printf buffer to 1024-bytes'


default :
	@help


# PHONY #


# Build Commands
.PHONY : all byte programs math_programs
# Development
.PHONY : ctags debug_xkb pathcheck pathchk print_xkb strip svglint TAGS
# Documentation
.PHONY : cleandoc doc docc docpy doxy
# Packaging
.PHONY : backup pkg pkg7z pkglzma pkgSFX pkgxz pkgzip
# General Project Utilities
.PHONY : getdeps_deb getdeps_deb_all getdeps_pip upver
# Clean-up
.PHONY : clean cleanall cleanfull fixperm refresh rmcache rmtmp
# Git
.PHONY : cleangit commit gitac gitadd gitattr gitignore gitlsfiles gitstats gitx lscontrib previewcleangit stat submitall submitdev submitmaster sw2dev sw2master syncdev syncmaster
# Install
.PHONY : install install_bin install_clib install_geany_conf install_loginopticons install_mimetype_booster install_langspecs install_opticons install_program_analyzer install_programs install_pyeggs install_pylib install_scripts install_shrc install_themes install_xcompose install_xkb
# Uninstall
.PHONY : uninstall uninstall_bin uninstall_clib uninstall_loginopticons uninstall_mimetype_booster uninstall_langspecs uninstall_opticons uninstall_program_analyzer uninstall_programs uninstall_pyeggs uninstall_pylib uninstall_scripts uninstall_shrc uninstall_themes uninstall_xcompose uninstall_xkb


# BUILD COMMANDS #


all : programs byte

byte :
	@export PYTHONOPTIMIZE='2'
	python$(PYVERSION) -m compileall -q -f $(PYSRC)/

math_programs : $(addprefix $(BIN)/, $(LIST_MATH_PROGRAMS))

programs : $(addprefix $(BIN)/, $(LIST_UTIL_PROGRAMS)) math_programs


# DEVELOPMENT #


ctags : cleanall
	-@geany -P -g $(TOOLSDIR)/PyBooster.c.tags $(INCDIR)/MACRO*.h

TAGS : ctags

pathchk :
	@command -v pathchk >&2 > /dev/null && find ./* -exec pathchk -P '{}' +

pathcheck : pathchk

debug_xkb :
	@$(TOOLSDIR)/manage_usx.sh --debug

print_xkb :
	@$(TOOLSDIR)/manage_usx.sh --print

strip :
	-@$(STRIP) $(BIN)/*

svglint :
	@command -v xmllint >&2 > /dev/null && find $(THEMEDIR)/ -type f -name "*.svg" -exec xmllint --valid --nowarning --noout {} \;


# DOCUMENTATION #


cleandoc :
	-@$(RMDIR) $(DOCDIR)/pylib/* $(DOCDIR)/clib/*

doc : docc docpy

docc : cleandoc fixperm
	-@doxygen ./Doxyfile
	find $(DOCDIR) -mount -type d -exec $(CHMOD) 755 '{}' +
	find $(DOCDIR) -mount -type f -exec $(CHMOD) 644 '{}' +

docpy : cleandoc fixperm
	-@./tools/pydocgen.sh $(PYSRC) $(DOCDIR) $(LIST_PYTHON_LIBRARIES)
	find $(DOCDIR) -mount -type d -exec $(CHMOD) 755 '{}' +
	find $(DOCDIR) -mount -type f -exec $(CHMOD) 644 '{}' +

doxy :
	-@doxywizard ./Doxyfile
	$(CHMOD) 644 ./Doxyfile


# PACKAGING #


backup : rmtmp
	@cd .. && tar -cf - PyBooster | gzip -9 > ./PyBooster.tar.gz && cd ./PyBooster

pkg : rmtmp
	@cd .. && tar --exclude='.git' --exclude='.git*' -cf - PyBooster | gzip -9 > ./PyBooster_v$(__VERSION__).tar.gz && cd ./PyBooster

pkg7z : rmtmp
	@cd .. && command -v 7za >&2 > /dev/null && 7za a -xr!.git -xr!.git* -bb0 -bd -mx=9 -t7z ./PyBooster_v$(__VERSION__).7z PyBooster && cd ./PyBooster

pkglzma : rmtmp
	@cd .. && command -v lzma >&2 > /dev/null && tar --exclude='.git' --exclude='.git*' -cf - PyBooster | lzma -k -9 > ./PyBooster_v$(__VERSION__).tar.lzma && cd ./PyBooster

pkgSFX : rmtmp
	@cd .. && command -v 7za >&2 > /dev/null && 7za a -xr!.git -xr!.git* -bb0 -bd -sfx ./PyBooster_v$(__VERSION__).exe PyBooster && cd ./PyBooster

pkgxz : rmtmp
	@cd .. && command -v xz >&2 > /dev/null && tar --exclude='.git' --exclude='.git*' -cf - PyBooster | xz -k -9 > ./PyBooster_v$(__VERSION__).tar.xz && cd ./PyBooster

pkgzip : rmtmp
	@cd .. && command -v zip >&2 > /dev/null && zip -q -x *.git* -r ./PyBooster_v$(__VERSION__).zip PyBooster && cd ./PyBooster


# GENERAL PROJECT UTILITIES #


getdeps_deb : getdeps_pip
	@apt-get install $(LIST_MAIN_DEPS)
	# TODO: Add support for rpm/yum, brew, & dnf

getdeps_deb_all : getdeps_deb
	@apt-get install $(LIST_DEV_DEPS)

getdeps_pip :
	@(command -v pip3 >&2 > /dev/null && pip3 install $(LIST_PIP_DEPS)) || (command -v pip >&2 > /dev/null && pip install $(LIST_PIP_DEPS)) || true
	# TODO: Add support for easy_install

upver :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Updating Software Versions ==='
	# Batch Files #
	find . -mount -type f \( -name "*.bat" -o -name "*.btm" -o -name "*.cmd" -o -name "*.nt" \) -exec sed -i "s/^REM @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/REM @version $(__VERSION__)/" '{}' \;
	# C & JavaScript Source Code #
	find . -mount -type f \( -name "*.c" -o -name "*.h" -o -name "*.js" \) -exec sed -i "s/^@version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/@version $(__VERSION__)/" '{}' \;
	# Glade Files #
	find . -mount -type f -name "*.glade" -exec sed -i "s/^@version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/@version $(__VERSION__)/; s/^Version: 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/Version: $(__VERSION__)/" '{}' \;
	# Perl Scripts #
	find . -mount -type f \( -name "*.perl" -o -name "*.pl" \) -exec sed -i "s/^@version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/@version $(__VERSION__)/; s/^    @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/    @version $(__VERSION__)/;" '{}' \;
	# Python Scripts #
	find . -mount -type f -name "*.py" -exec sed -i "s/^__version__ = '20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__ = '$(__VERSION__)'/; s/^__version__ = r'20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__ = r'$(__VERSION__)'/; s/^__version__: str = '20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__: str = '$(__VERSION__)'/; s/^__version__: str = r'20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__: str = r'$(__VERSION__)'/; s/^@version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/@version $(__VERSION__)/; s/^Version: 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/Version: $(__VERSION__)/" '{}' \;
	find $(SCRIPTSRCDIR)/* -mount -type f -exec sed -i "s/^@version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/@version $(__VERSION__)/; s/^__version__: str = '20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__: str = '$(__VERSION__)'/; s/^__version__: str = r'20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__: str = r'$(__VERSION__)'/; s/^__version__ = '20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__ = '$(__VERSION__)'/; s/^__version__ = r'20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__ = r'$(__VERSION__)'/" '{}' \;
	# Shell Scripts #
	find . -mount -type f \( -name "*.awk" -o -name "*.sed" -o -name "*.sh" \) -exec sed -i "s/^# @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/# @version $(__VERSION__)/; s/^version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/version=$(__VERSION__)/; s/^readonly version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/readonly version=$(__VERSION__)/" '{}' \;
	find $(SCRIPTSRCDIR)/* -mount -type f -exec sed -i "s/^# @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/# @version $(__VERSION__)/; s/^version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/version=$(__VERSION__)/; s/^readonly version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/readonly version=$(__VERSION__)/" '{}' \;
	# Tools #
	find $(TOOLSDIR)/* -mount -type f -exec sed -i "s/^# @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/# @version $(__VERSION__)/; s/^version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/version=$(__VERSION__)/; s/^readonly version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/readonly version=$(__VERSION__)/" '{}' \;
	# XKB #
	find $(XKBDIR)/* -mount -type f -name "usx*" -exec sed -i "s/^\/\/ @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/\/\/ @version $(__VERSION__)/" '{}' \;
	find $(XKBDIR)/* -mount -type f -name "XCompose" -exec sed -i "s/^# @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/# @version $(__VERSION__)/" '{}' \;
	# Miscellaneous #
	find . -mount -type f -name "*.desktop" -exec sed -i "s/^Version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/Version=$(__VERSION__)/" '{}' \;
	find $(ACCDIR)/* -mount -type f \( -name "profile" -o -name "shell_ext" \) -exec sed -i "s/^# @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/# @version $(__VERSION__)/" '{}' \;


# CLEAN-UP #


clean : rmtmp rmcache

cleanall : rmtmp rmcache
	-@$(RM) $(BIN)/*

cleanfull : cleanall cleandoc

fixperm :
	-@find . -mount -type d -exec $(CHMOD) 755 '{}' +
	find $(PYEGGDIR)/* -mount -type f -name "*.py" -exec $(CHMOD) 755 '{}' +
	find . -mount -type f \( -name "*.c" -o -name "*.h" -o -name "*.desktop" -o -name "*.glade" -o -name "icon-theme.cache" -o -name "*.icon" -o -name "*.theme" -o -name "*.types" \) -exec $(CHMOD) 644 '{}' +
	find . -mount -type f \( -name "*AUTHORS" -o -name "CHANGELOG" -o -name "ChangeLog" -o -name "Doxyfile" -o -name "LICENSE" -o -name "THANKS" -o -name "TODO" -o -name "*.md" -o -name "README" -o -name "PKG-INFO" -o -name "*.rst" -o -name "*.cfg" \) -exec $(CHMOD) 644 '{}' +
	find . -mount -type f \( -name "*.bat" -o -name "*.btm" -o -name "*.cmd" -o -name "*.lang" -o -name "*.nt" -o -name "*.dtd" -o -name "*.mathml" -o -name "*.rng" -o -name "*.svg" -o -name "*.xlst" -o -name "*.xml" -o -name "*.xsd" \) -exec $(CHMOD) 644 '{}' +
	find $(THEMEDIR)/* -mount -type f -exec $(CHMOD) 644 '{}' +
	$(CHMOD) 644 $(DOCDIR)/pylib/*.txt $(DOCDIR)/clib/html/* $(DOCDIR)/clib/html/search/*
	$(CHMOD) 644 $(INCDIR)/* $(SRCDIR)/* $(PYSRC)/*.py $(EZWINSRC)/*.py
	$(CHMOD) 755 $(BIN)/* $(SCRIPTSRCDIR)/* $(TOOLSDIR)/*.sh
	$(CHMOD) 755 $(PYSRC)/ezdisplay.py $(EZWINSRC)/ezwin.py

rmcache :
	-@find . -mount -type d -name "__pycache__" -exec $(RMDIR) '{}' +

rmtmp :
	-@find . -mount -type f \( -name "*.o" -o -name "*.ast" -o -name "*.bc" -o -name "*.dump" -o -name "*.i" -o -name "*.ii" -o -name "*.ll" -o -name "*.original" -o -name "*.gch" -o -name "*.pch" -o -name "*.xkm" \) -delete
	find . -mount -type d \( -name "metrics" \) -exec $(RMDIR) '{}' + 2> /dev/null
	$(RM) $(BIN)/test_dev $(TESTINGDIR)/*

refresh : | cleanfull upver fixperm


# GIT COMMANDS #


cleangit : cleanall fixperm
	-@git reflog expire --all --expire=now --stale-fix
	git rm --cached -r --ignore-unmatch *
	git gc --prune=now --aggressive
	git add --all --refresh
	git fsck --dangling --full --name-objects --progress --strict --unreachable

commit :
	@printf '\nCreate a commit message: ' && read GITMSG && printf '\n' && git commit --cleanup=strip --message="$$GITMSG"

gitadd : cleanall fixperm
	@git add --all

gitac :
	@git checkout dev && git add --all && printf '\nCreate a commit message: ' && read GITMSG && printf '\n' && git commit --cleanup=strip --message="$$GITMSG"

gitx :
	@git checkout dev && git add --all && printf '\nCreate a commit message: ' && read GITMSG && printf '\n' && git commit --cleanup=strip --message="$$GITMSG"
	git push --force --progress --signed=false --verify origin dev

lscontrib :
	@git log --format='%aN <%aE>' | awk '{ arr[$0]++ } END { for (i in arr) { print arr[i], i; } }' | sort -n -r | cut -d ' ' -f 2-

previewcleangit : cleanall fixperm
	-@git reflog expire --dry-run --all --expire=now --stale-fix
	git rm --dry-run --cached -r --ignore-unmatch *
	git prune --dry-run --verbose
	git add --dry-run --all --refresh

stat : cleanall
	-@git status --ahead-behind --branch --short

submitall :
	@git checkout dev
	git push --progress --signed=false --verify origin dev
	git checkout master && git merge --commit dev && git push --progress --signed=false --verify origin master
	git checkout dev

submitdev :
	@git push --progress --signed=false --verify origin dev

submitmaster :
	@git push --progress --signed=false --verify origin master

sw2dev :
	@git checkout dev

sw2master :
	@git checkout master

syncdev :
	@git checkout dev
	git merge --commit master
	git checkout master

syncmaster :
	@git checkout master
	git merge --commit dev
	git checkout dev

gitattr :
	@git check-attr --all unspecified ./*
	git check-attr --all unspecified ./*/*
	git check-attr --all unspecified ./*/*/*

gitignore :
	@git check-ignore ./*
	git check-ignore ./*/*
	git check-ignore ./*/*/*

gitstats :
	@gitstats ./ $(TESTINGDIR)/git/

gitlsfiles :
	@git ls-files


# INSTALL/UNINSTALL #


install_clib : | rmtmp fixperm
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing C Libraries ==='
	([ -d $(INSTALLHEADERSDIR)/ ] && $(RMDIR) $(INSTALLHEADERSDIR)/) || true
	$(MKDIRS) $(INSTALLHEADERSDIR)/
	$(CHMOD) 755 $(INSTALLHEADERSDIR)/
	$(COPY) $(INCDIR)/* $(INSTALLHEADERSDIR)/
	find $(INSTALLHEADERSDIR)/ -type f -exec $(CHMOD) 644 '{}' +
	# Install Documentation
	([ -d $(DOCDIR)/clib/ ] && [ -d $(INSTALLDOCDIR)/ ] && [ ! -d $(INSTALLDOCDIR)/clib/ ] && $(MKDIR) $(INSTALLDOCDIR)/clib/) || true
	([ -d $(DOCDIR)/clib/ ] && [ -d $(INSTALLDOCDIR)/clib/ ] && $(CPDIR) $(DOCDIR)/clib/* $(INSTALLDOCDIR)/clib/) || true

uninstall_clib :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling C Libraries ==='
	([ -d $(INSTALLHEADERSDIR)/ ] && $(RMDIR) $(INSTALLHEADERSDIR)/) || true
	# Uninstall Documentation
	([ -d $(INSTALLDOCDIR)/clib/ ] && $(RMDIR) $(INSTALLDOCDIR)/clib/) || true

install_geany_conf :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Geany Configuration Files ==='
	$(CPDIR) $(ACCDIR)/geany/* ~/.config/geany/

install_programs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing /usr/bin Programs ==='
	$(COPY) $(addprefix $(BIN)/, $(LIST_UTIL_PROGRAMS)) $(addprefix $(BIN)/, $(LIST_MATH_PROGRAMS)) $(INSTALLBINDIR)/
	$(CHMOD) 755 $(addprefix $(INSTALLBINDIR)/, $(LIST_UTIL_PROGRAMS)) $(addprefix $(INSTALLBINDIR)/, $(LIST_MATH_PROGRAMS))

uninstall_programs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling /usr/bin Programs ==='
	$(RM) $(addprefix $(INSTALLBINDIR)/, $(LIST_UTIL_PROGRAMS)) $(addprefix $(INSTALLBINDIR)/, $(LIST_MATH_PROGRAMS))

install_bin : install_programs

uninstall_bin : uninstall_programs

install_loginopticons :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing LoginOpticons ==='
	([ -d $(SYSTHEMEDIR)/LoginOpticons/ ] && $(RMDIR) $(SYSTHEMEDIR)/LoginOpticons/) || true
	$(CPDIR) $(THEMEDIR)/LoginOpticons $(SYSTHEMEDIR)/
	$(UPDATEICONCACHE) $(SYSTHEMEDIR)/LoginOpticons/
	$(UPDATEMIME) $(SYSMIMEDIR)

uninstall_loginopticons :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling LoginOpticons ==='
	([ -d $(SYSTHEMEDIR)/LoginOpticons/ ] && $(RMDIR) $(SYSTHEMEDIR)/LoginOpticons/) || true
	$(UPDATEMIME) $(SYSMIMEDIR)

install_mimetype_booster :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Mimetypes ==='
	$(COPY) $(ACCDIR)/mime.types /etc/mime.types
	$(XDGMIME) install --mode system --novendor $(ACCDIR)/mimetype_booster.xml
	$(UPDATEMIME) $(SYSMIMEDIR)

uninstall_mimetype_booster :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Mimetypes ==='
	$(XDGMIME) uninstall --mode system $(SYSMIMEDIR)/packages/mimetype_booster.xml
	$(UPDATEMIME) $(SYSMIMEDIR)

install_langspecs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Language Specifications ==='
	([ -d $(INSTALLLANGSPECS2DIR)/ ] && $(COPY) $(addprefix $(LANGSPECSDIR)/, $(addsuffix .lang, $(LIST_LANGSPECS))) $(INSTALLLANGSPECS2DIR)/) || true
	([ -d $(INSTALLLANGSPECS3DIR)/ ] && $(COPY) $(addprefix $(LANGSPECSDIR)/, $(addsuffix .lang, $(LIST_LANGSPECS))) $(INSTALLLANGSPECS3DIR)/) || true

uninstall_langspecs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Language Specifications ==='
	([ -d $(INSTALLLANGSPECS2DIR)/ ] && $(RM) $(addprefix $(INSTALLLANGSPECS2DIR)/, $(addsuffix .lang, $(LIST_LANGSPECS)))) || true
	([ -d $(INSTALLLANGSPECS3DIR)/ ] && $(RM) $(addprefix $(INSTALLLANGSPECS3DIR)/, $(addsuffix .lang, $(LIST_LANGSPECS)))) || true

install_opticons :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Opticons ==='
	([ -d $(SYSTHEMEDIR)/Opticons/ ] && $(RMDIR) $(SYSTHEMEDIR)/Opticons/) || true
	$(CPDIR) $(THEMEDIR)/Opticons $(SYSTHEMEDIR)/
	[ -x "$(command -v update-alternatives)" ] && update-alternatives --install /etc/alternatives/start_icon start-here.svg $(SYSTHEMEDIR)/Opticons/places/start-here.svg 70
	$(UPDATEICONCACHE) $(SYSTHEMEDIR)/Opticons/
	$(UPDATEMIME) $(SYSMIMEDIR)

uninstall_opticons :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Opticons ==='
	([ -d $(SYSTHEMEDIR)/Opticons/ ] && $(RMDIR) $(SYSTHEMEDIR)/Opticons/ && $(UPDATEMIME) $(SYSMIMEDIR)) || true
	[ -x "$(command -v update-alternatives)" ] && update-alternatives --set start-here.svg /etc/alternatives/start-here.svg

install_pyeggs : | rmtmp fixperm
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Python Eggs ==='
	(pip3 uninstall flake8_optimal) || true
	cd $(PYEGGDIR)/flake8_optimal/ || exit 1
	python3 ./setup.py install
	$(RMDIR) ./__pycache__/ ./build/ ./dist/ ./flake8_optimal.egg-info/ || true
	cd ../..

uninstall_pyeggs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing LoginOpticons ==='
	command -v pip3 >&2 > /dev/null && pip3 uninstall flake8_optimal
	command -v pip3 >&2 > /dev/null || printf '%s\n' 'pip3: command not found!'

$(PYBDIR)/__init__.py : install_pylib

install_pylib : | rmtmp fixperm
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Python Libraries ==='
	([ -d $(PYBDIR)/ ] && $(RMDIR) $(PYBDIR)/) || true
	([ -d $(PYSRC)/__pycache__/ ] && $(RMDIR) $(PYSRC)/__pycache__/) || true
	([ -d $(PYSRC)/ezwin/__pycache__/ ] && $(RMDIR) $(PYSRC)/ezwin/__pycache__/) || true
	$(MKDIR) $(PYBDIR)/
	$(CPDIR) $(PYSRC)/* $(PYBDIR)/
	# Install Documentation
	([ -d $(DOCDIR)/pylib/ ] && [ -d $(INSTALLDOCDIR)/ ] && [ ! -d $(INSTALLDOCDIR)/pylib/ ] && $(MKDIR) $(INSTALLDOCDIR)/pylib/) || true
	([ -d $(DOCDIR)/pylib/ ] && [ -d $(INSTALLDOCDIR)/pylib/ ] && $(CPDIR) $(DOCDIR)/pylib/* $(INSTALLDOCDIR)/pylib/) || true
	# Set proper permissions
	$(CHMOD) 755 $(PYBDIR)/
	find $(PYBDIR)/ -type d -exec $(CHMOD) 755 '{}' +
	find $(PYBDIR)/ -type f -exec $(CHMOD) 644 '{}' +
	$(CHMOD) 755 $(PYBDIR)/ezdisplay.py $(PYBDIR)/ezwin/ezwin.py
	# Make a link (in PATH) to executable scripts
	$(RM) $(INSTALLBINDIR)/ezdisplay $(INSTALLBINDIR)/ezwin
	([ -d $(INSTALLBINDIR)/ ] && [ -d $(PYBDIR)/ ] && [ -r $(PYBDIR)/ezdisplay.py ] && $(LNSOFT) $(PYBDIR)/ezdisplay.py $(INSTALLBINDIR)/ezdisplay) || true
	([ -d $(INSTALLBINDIR)/ ] && [ -d $(PYBDIR)/ezwin/ ] && [ -r $(PYBDIR)/ezwin/ezwin.py ] && $(LNSOFT) $(PYBDIR)/ezwin/ezwin.py $(INSTALLBINDIR)/ezwin) || true
	# Make Pybooster accessible to Python3
	([ -d $(PYPATH)3.6/ ] && $(LNDIR) $(PYBDIR) $(PYPATH)3.6/pybooster) || true
	([ -d $(PYPATH)3.7/ ] && $(LNDIR) $(PYBDIR) $(PYPATH)3.7/pybooster) || true
	([ -d $(PYPATH)3.8/ ] && $(LNDIR) $(PYBDIR) $(PYPATH)3.8/pybooster) || true

uninstall_pylib : uninstall_program_analyzer uninstall_scripts
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Python Libraries ==='
	$(RM) $(INSTALLBINDIR)/ezdisplay $(INSTALLBINDIR)/ezwin
	([ -d $(PYBDIR)/ ] && $(RMDIR) $(PYBDIR)/) || true
	$(RM) $(PYPATH)3.6/pybooster $(PYPATH)3.7/pybooster $(PYPATH)3.8/pybooster
	# Uninstall Documentation
	([ -d $(INSTALLDOCDIR)/pylib/ ] && $(RMDIR) $(INSTALLDOCDIR)/pylib/) || true

install_program_analyzer : | fixperm $(PYBDIR)/__init__.py
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Program Analyzer ==='
	([ ! -d $(INSTALLBINDIR)/ ] && $(MKDIRS) $(INSTALLBINDIR)/) || true
	$(COPY) $(SCRIPTSRCDIR)/program-analyzer $(INSTALLBINDIR)/
	$(COPY) $(MENUDIR)/Program-Analyzer.desktop $(SYSAPPDIR)/
	$(COPY) $(MENUDIR)/program-analyzer $(SYSMENUDIR)/
	$(COPY) $(THEMEDIR)/Opticons/apps/program-analyzer.svg $(PIXMAPDIR)/

uninstall_program_analyzer :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Program Analyzer ==='
	$(RM) $(INSTALLBINDIR)/program-analyzer $(SYSAPPDIR)/Program-Analyzer.desktop $(SYSMENUDIR)/program-analyzer $(PIXMAPDIR)/program-analyzer.svg

install_scripts : $(PYBDIR)/__init__.py
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Scripts ==='
	([ ! -d $(INSTALLBINDIR)/ ] && $(MKDIRS) $(INSTALLBINDIR)/) || true
	$(COPY) -t $(INSTALLBINDIR)/ $(addprefix $(SCRIPTSRCDIR)/, $(LIST_SCRIPT_PROGRAMS)) $(addprefix $(SCRIPTSRCDIR)/, $(LIST_DEV_SCRIPTS)) $(addprefix $(SCRIPTSRCDIR)/, $(LIST_PYTHON_SCRIPTS))
	$(COPY) $(INSTALLBINDIR)/pyflakes3 /usr/bin/pyflakes
	$(COPY) $(INSTALLBINDIR)/pylint3 /usr/bin/pylint
	$(COPY) $(INSTALLBINDIR)/pylint3 /usr/local/bin/pylint
	$(COPY) $(INSTALLBINDIR)/pylint2 /usr/local/bin/pylint2
	$(COPY) $(INSTALLBINDIR)/pep8 /usr/local/bin/pep8
	$(COPY) $(INSTALLBINDIR)/pep8 /usr/local/bin/pycodestyle

uninstall_scripts :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Scripts ==='
	$(RM) $(addprefix $(INSTALLBINDIR)/, $(LIST_SCRIPT_PROGRAMS)) $(addprefix $(INSTALLBINDIR)/, $(LIST_DEV_SCRIPTS)) $(addprefix $(INSTALLBINDIR)/, $(LIST_PYTHON_SCRIPTS))
	$(RM) /usr/bin/pyflakes /usr/bin/pylint /usr/local/bin/pep8 /usr/local/bin/pycodestyle /usr/local/bin/pylint /usr/local/bin/pylint2

install_shrc :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Shell Profiles ==='
	$(COPY) /etc/profile /etc/profile.backup
	$(COPY) -t /etc/ $(ACCDIR)/profile $(ACCDIR)/shell_ext && $(CHMOD) 644 /etc/profile /etc/shell_ext
	([ -f /etc/bash.bashrc.backup ] && $(RM) /etc/bash.bashrc.backup) || true
	([ -f /etc/bash.bashrc ] && $(MOVE) /etc/bash.bashrc /etc/bash.bashrc.backup) || true
	$(LN) /etc/profile /etc/bash.bashrc
	$(CPDIR) $(ACCDIR)/shell_ext_modules /etc/shell_ext_modules

uninstall_shrc :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Shell Profiles ==='
	$(RM) /etc/bash.bashrc /etc/profile /etc/shell_ext
	$(MOVE) /etc/bash.bashrc.backup /etc/bash.bashrc
	$(MOVE) /etc/profile.backup /etc/profile
	$(RMDIR) /etc/shell_ext_modules

install_themes : install_loginopticons install_opticons

uninstall_themes : uninstall_loginopticons uninstall_opticons

install_xcompose :
	@$(COPY) $(XKBDIR)/XCompose ~/.XCompose

uninstall_xcompose :
	@$(RM) ~/.XCompose

install_xkb :
	@$(TOOLSDIR)/manage_usx.sh --install

uninstall_xkb :
	@$(TOOLSDIR)/manage_usx.sh --uninstall

# install_scripts calls install_pylib
install : | rmtmp fixperm install_clib install_programs install_mimetype_booster install_program_analyzer install_pyeggs install_scripts install_themes

# uninstall_pylib calls uninstall_scripts
uninstall : uninstall_clib uninstall_programs uninstall_mimetype_booster uninstall_program_analyzer uninstall_pyeggs uninstall_pylib uninstall_themes


# MATH PROGRAM RULES #


$(BIN)/cos : $(SRCDIR)/cos.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $< -o $@ && $(STRIP) $@

$(BIN)/fib : $(SRCDIR)/fib.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INTS -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF32 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $< -o $@ && $(STRIP) $@

$(BIN)/isprime : $(SRCDIR)/isprime.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INTS -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF32 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $< -o $@ && $(STRIP) $@

$(BIN)/sin : $(SRCDIR)/sin.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $< -o $@ && $(STRIP) $@

$(BIN)/tan : $(SRCDIR)/tan.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $< -o $@ && $(STRIP) $@


# UTILITY PROGRAM RULES #


$(BIN)/getpgid : $(SRCDIR)/getpgid.c $(MACROSPATH)
	$(CC) -DNO_PRINT_M -DNO_PRINT_FLOATS -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $< -o $@ && $(STRIP) $@

$(BIN)/getsid : $(SRCDIR)/getsid.c $(MACROSPATH)
	$(CC) -DNO_PRINT_M -DNO_PRINT_FLOATS -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $< -o $@ && $(STRIP) $@

$(BIN)/microtime : $(SRCDIR)/microtime.c $(MACROSPATH)
	$(CC) -DNO_PRINT_M -DNO_PRINT_FLOATS -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $< -o $@ && $(STRIP) $@

$(BIN)/ostype : $(SRCDIR)/ostype.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INTS -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF32 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $< -o $@ && $(STRIP) $@

$(BIN)/statvfs : $(SRCDIR)/statvfs.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF512 -DNO_SCAN_FLOATS -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $< -o $@ && $(STRIP) $@

$(BIN)/typesize : $(SRCDIR)/typesize.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF32 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $< -o $@ && $(STRIP) $@


# TEST PROGRAM RULES #


$(BIN)/test_dev : $(SRCDIR)/test_dev.c $(MACROSPATH)
	$(CC) -DPRINTF_BUF128 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $< -o $@ && $(STRIP) $@

$(TESTINGDIR)/test_dev.s : $(SRCDIR)/test_dev.c $(MACROSPATH)
	$(CC) -DPRINTF_BUF128 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(*F)\" $(MINEXE_PARAMS) -fverbose-asm -S $< -o $@

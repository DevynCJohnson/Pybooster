#!/usr/bin/make -f
# -*- coding: utf-8-unix; Mode: Makefile; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=makefile syntax=makefile.doxygen fileformat=unix tabstop=4 :
# kate: encoding utf-8; bom off; syntax makefile; indent-mode normal; eol unix; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Main project makefile
#' @file makefile
#' @version 2018.10.13
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/
#' @section SYMBOLS
#' $@ - The file name of the target of the rule
#' $% - The target member name, when the target is an archive member
#' $< - The name of the first prerequisite
#' $? - The names of all the prerequisites that are newer than the target (with spaces between them)
#' $^ - The names of all the prerequisites (with spaces between them)
#' $+ - This is like `$^`, but prerequisites listed more than once are duplicated in the order they were listed in the makefile
#' $* - The stem with which an implicit rule matches
#' $(@D) - The directory part of the file name of the target (with the trailing slash removed)
#' $(@F) - The file-within-directory part of the file name of the target
#' $(*D) - The directory part part of the stem
#' $(*F) - The file-within-directory part of the stem
#' $(%D) - The directory part part of the target archive member name
#' $(%F) - The file-within-directory part of the target archive member name
#' $(<D) - The directory part part of the first prerequisite
#' $(<F) - The file-within-directory part of the first prerequisite
#' $(^D) - Lists of the directory parts parts of all prerequisites
#' $(^F) - Lists of the file-within-directory parts of all prerequisites
#' $(?D) - Lists of the directory parts parts of all prerequisites that are newer than the target
#' $(?F) - Lists of the file-within-directory parts of all prerequisites that are newer than the target


.POSIX :
.ONESHELL :
override SHELL::=/bin/bash
.SHELLFLAGS::=-c

include makefile_constants.mk


# VARIABLES #


# Project Paths
override ACCDIR::=./accessory
override BIN::=./bin
override DBDIR::=./databases
override DOCDIR::=./doc
override PYEGGDIR::=./pyegg
override PYSRC::=./pylib
override EZWINSRC::=$(PYSRC)/ezwin
override GEANYDIR::=./geany
override INCDIR::=./include
override LANGSPECSDIR::=$(ACCDIR)/language_specs
override NANORCDIR::=$(ACCDIR)/nanorc
override MAN1DIR::=$(DOCDIR)/man1
override MANDIRS::=$(DOCDIR)/man*
override MENUDIR::=$(ACCDIR)/menu_files
override SCRIPTSRCDIR::=./scripts
override THEMEDIR::=./themes
override TOOLSDIR::=./tools
override SCHEMASDIR::=$(ACCDIR)/schemas
override SHRCDIR::=./shrc
override SRCDIR::=./src
override XKBDIR::=$(THEMEDIR)/XKB
override PYCACHE::=$(PYEGGDIR)/__pycache__/ $(SCRIPTSRCDIR)/__pycache__/
override MACROSPATH::=$(INCDIR)/Foundation.h $(INCDIR)/MACROS.h $(INCDIR)/MACROS2.h $(INCDIR)/MACROS3.h

# Install Paths
override INSTALLBINDIR::=$(BINDIR)
override INSTALLHEADERSDIR::=$(SYSINCLUDEDIR)/pybooster
override INSTALLRCMODDIR::=/etc/shell_ext_modules/
override PYBDIR::=/usr/lib/pybooster

# File Lists
override LIST_LANGSPECS::=coffeescript
override LIST_NANORC_FILES::=asm.nanorc autoconf.nanorc awk.nanorc changelog.nanorc cmake.nanorc c.nanorc css.nanorc debian.nanorc default.nanorc Dockerfile.nanorc elisp.nanorc email.nanorc fortran.nanorc gentoo.nanorc go.nanorc groff.nanorc guile.nanorc html.nanorc java.nanorc javascript.nanorc json.nanorc lua.nanorc makefile.nanorc man.nanorc mgp.nanorc mutt.nanorc nanohelp.nanorc nanorc.nanorc nftables.nanorc objc.nanorc ocaml.nanorc patch.nanorc perl.nanorc php.nanorc po.nanorc postgresql.nanorc pov.nanorc python.nanorc ruby.nanorc rust.nanorc sh.nanorc spec.nanorc tcl.nanorc texinfo.nanorc tex.nanorc xml.nanorc
override LIST_MATH_PROGRAMS::=acos acosh asin asinh atan atanh cbrt cos cosh fib isprime sin sinh sqrt tan tanh
override LIST_UTIL_PROGRAMS::=getpgid getsid microtime ostype statvfs typesize
override LIST_BIN_PROGRAMS::=$(LIST_MATH_PROGRAMS) $(LIST_UTIL_PROGRAMS)
override LIST_PYTHON_SCRIPTS::=cx_freeze3 cxfreeze3 easy_install3 pip3 pip3-upgrade-all py2dsc pymake pyreverse3 qt5py wpip
override LIST_DEV_SCRIPTS::=canalysis clint cmccabe code-analysis code-formatter coffeeanalysis cssanalysis exewalk file-analysis flake8 goanalysis insn_count jsanalysis jsonanalysis luaanalysis pep257 pep8 progstrip pyanalysis py_directive_checker pydocgtk pyflakes2 pyflakes3 pyinspect pylint2 pylint3 pytest3 RCompiler.R RTidy.R shanalysis systracer timeit todo-scanner transpile xmlanalysis yamlanalysis
override LIST_RC_MODULES::=aws_rc.sh crypto_rc.sh docker_rc.sh extras_rc.sh multimedia_rc.sh pkg_rc.sh
override LIST_SCRIPT_PROGRAMS::=alphabetize_lines bin2hex bin2num bin2oct CamelCase char2num cleansystem genmathart getsysinfo hex2num lslibfunc minifyxml num2bin num2char num2hex num2oct oct2num PascalCase pipebuf prettifyxml refreshgrub replaceoddchars svgresizer termtest thumbnail-cleaner togglequotes unicalc win2unixlines
override LIST_PYTHON_LIBRARIES::=astronomy basic bitwise boolean clibutil code_interpreter color compress convarea convlength convmass convspeed convtemp convtime convvolume cryptography datastruct electronics ezdisplay filemagic financial fs geo iterables libchar libregex markup metric multimedia net neuralnet pipx pronouns religion science_data sing strtools system timeutil unix xmath ymath
override LIST_PIP_DEPS::=autopep8 bandit bashate cx-Freeze docformatter flake8 flake8-mypy mccabe mypy mypy_extensions Pillow pyaml pycodestyle pydocstyle pyflakes pyinstaller pylint pylint-django vulture yaml yamllint
override LIST_DEV_DEPS::=binwalk bsdiff cccc complexity cppcheck doxygen doxygen-gui flawfinder geany geany-plugin-addons geany-plugin-ctags geany-plugin-lineoperations gitlint glade jsonlint kwstyle ltrace optipng pmccabe pngcrush pscan python3-demjson shc shellcheck splint strace uchardet undertaker vbindiff wamerican-insane yajl-tools
override LIST_MAIN_DEPS::=clang cloc colormake coreutils doschk gcc libxml2-utils licensecheck llvm make moreutils python-chardet python3-gi python3-logilab-common python3-pip python3-pytest python3-pytest-pep8 sloccount xdg-utils

# Search Parameters Used in Find

override CHMOD644_NO_SEARCH::=$(ACCDIR) $(BIN) $(DOCDIR) $(GEANYDIR) $(INCDIR) $(SCRIPTSRCDIR) $(SHRCDIR) $(SRCDIR) $(TESTINGDIR) $(THEMEDIR)
override LIST_CHMOD644_EXT::=*.auk *.awk *.b *.bat *.bf *.bison *.btm *.c *.cfg *.cmd *.cml *.coffee *.conf *.config *.cpp *.csv *.cu *.cuda *.d *.desktop *.dgml *.di *.dtd *.f *.F *.f03 *.F03 *.f08 *.F08 *.f77 *.F77 *.f90 *.F90 *.f95 *.F95 *.for *.fortan *.fpp *.ftn *.glade *.go *.golang *.h *.htm *.html *.hx *.icon *.js *.json *.lang *.less *.limbo *.lua *.m4 *.mathml *.matlab *.md *.mk *.ml *.mlab *.mli *.mll *.mly *.mml *.nt *.numpy *.octave *.php *.php4 *.php5 *.php6 *.php7 *.rb *.rng *.rst *.sass *.scss *.svg *.swg *.tcl *.theme *.types *.wasm *.xht *.xlst *.xml *.xsd *.xsl *.y *.yaml *.yml *.yy *.yy *AUTHORS .editorconfig .eslintrc .gitattributes .gitignore .gitlint .gitmodules .pylintrc CHANGELOG ChangeLog Doxyfile icon-theme.cache LICENSE PKG-INFO README THANKS TODO
override EXCLUDE_FROM_FIND::=-not \( -path "$(DBDIR)/*" -o -path "$(DOCDIR)/*" -o -path "$(GEANYDIR)/*" -o -path "$(SCHEMASDIR)/*" -o -path "$(THEMEDIR)/LoginOpticons/*" -o -path "$(THEMEDIR)/Opticons/*" \)

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
	printf '%s\n%s\n' 'Install NanoRC Files:' '    sudo make install_nanorc'
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
	printf '%s\n%s\n' 'Remove Cache Files:' '    make rmcache'
	printf '%s\n%s\n' 'Remove Temp and Object Files:' '    make rmtmp'
	printf '%s\n%s\n' 'Remove Temp, Object, and Cache Files:' '    make clean'
	printf '\n\n\x1b[1;4;33m%s\x1b[0m\n\n' '* GIT *'
	printf '%s\n%s\n' 'Add Files to Git:' '    make addgit'
	printf '%s\n%s\n' 'Commit Changes to Git:' '    make commit'
	printf '%s\n%s\n' 'Push Changes to Git:' '    make push'
	printf '%s\n%s\n' 'Get Git Project Status:' '    make stat'
	printf '%s\n%s\n' 'Clean Git Project:' '    make cleangit'
	printf '%s\n%s\n' 'Dry-run Clean Git Project:' '    make previewcleangit'
	printf '\n\n\x1b[1;4;33m%s\x1b[0m\n\n' '* MISCELLANEOUS *'
	printf '%s\n%s\n' 'Make the system more like OSX:' '    sudo make macify'
	printf '%s\n%s\n' 'Undo the effects of `macify`:' '    sudo make unmacify'
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
.PHONY : cleandoc doc docc docpy doxy manpages
# Packaging
.PHONY : backup pkg pkg7z pkglzma pkgSFX pkgxz pkgzip
# General Project Utilities
.PHONY : getdeps_deb getdeps_deb_all getdeps_pip update_doccmt_keywords update_reminders upver
# Clean-up
.PHONY : clean cleanall cleanfull fixperm refresh rmcache rmtmp
# Git
.PHONY : gitadd submitall submitdev submitmaster sw2dev sw2master syncdev syncmaster
# Install
.PHONY : install install_bin install_clib install_dev install_geany_conf install_loginopticons install_mimetype_booster install_langspecs install_nanorc install_opticons install_program_analyzer install_programs install_pyeggs install_pylib install_scripts install_shrc install_themes install_xcompose install_xkb
# Uninstall
.PHONY : uninstall uninstall_bin uninstall_clib uninstall_dev uninstall_loginopticons uninstall_mimetype_booster uninstall_langspecs uninstall_nanorc uninstall_opticons uninstall_program_analyzer uninstall_programs uninstall_pyeggs uninstall_pylib uninstall_scripts uninstall_shrc uninstall_themes uninstall_xcompose uninstall_xkb
# Miscellaneous
.PHONY : macify unmacify


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
	-@$(RMDIR) $(DOCDIR)/clib $(DOCDIR)/pylib

doc : docc docpy manpages

docc : fixperm
	-@([ -f $(DOCDIR)/index.html ] && unlink $(DOCDIR)/index.html) || true
	([ -d $(DOCDIR)/clib ] && $(RMDIR) $(DOCDIR)/clib) || true
	doxygen ./Doxyfile > /dev/null
	find $(DOCDIR) -mount -type d -exec $(CHMOD) 755 '{}' +
	find $(DOCDIR) -mount -type f -exec $(CHMOD) 644 '{}' +
	# Restructure Directory Hierarchy
	$(MV) $(DOCDIR)/clib/man $(DOCDIR)/
	$(MV) $(DOCDIR)/clib/html/* $(DOCDIR)/clib/
	$(RMDIR) $(DOCDIR)/clib/html
	# Create link to index.html
	cd $(DOCDIR) && $(LNSOFT) ./clib/index.html ./index.html && cd ..

docpy : fixperm
	-@([ -d $(DOCDIR)/pylib ] && $(RMDIR) $(DOCDIR)/pylib) || true
	./tools/pydocgen.sh $(PYSRC) $(DOCDIR) $(LIST_PYTHON_LIBRARIES) > /dev/null
	find $(DOCDIR) -mount -type d -exec $(CHMOD) 755 '{}' +
	find $(DOCDIR) -mount -type f -exec $(CHMOD) 644 '{}' +

doxy :
	-@doxywizard ./Doxyfile
	$(CHMOD) 644 ./Doxyfile

manpages :
	-@find $(MANDIRS) -mount -type f \( -name "*.1" -o -name "*.2" -o -name "*.3" -o -name "*.4" -o -name "*.5" -o -name "*.6" -o -name "*.7" -o -name "*.8" \) -print0 | xargs -0 gzip -9 -k


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
	@([ -d /etc/apt ] && [ -x "$(command -v apt-get)" ] && (apt-get install $(LIST_MAIN_DEPS) && printf 'If desired, execute `\x1b[4;33msudo add-apt-repository ppa:geany-dev/ppa\x1b[0m`\n' || true)) || \
	([ -d /etc/dnf ] && [ -x "$(command -v dnf)" ] && (dnf install $(LIST_MAIN_DEPS) || true)) || \
	([ -d /etc/portage ] && [ -x "$(command -v emerge)" ] && (emerge -a $(LIST_MAIN_DEPS) || true)) || true

getdeps_deb_all : getdeps_deb
	@apt-get install $(LIST_DEV_DEPS)

getdeps_pip :
	@(command -v pip3 >&2 > /dev/null && pip3 install $(LIST_PIP_DEPS)) || (command -v pip >&2 > /dev/null && pip install $(LIST_PIP_DEPS)) || true

update_doccmt_keywords :
	-@find $(GEANYDIR)/filedefs -type f -exec grep -l -F 'docComment=' {} + | xargs sed -i "s/docComment=.*/docComment=$(DOCCMT_KEYWORDS)/g"

update_reminders :
	-@find . -type f -exec grep -l -F '$(OLD_REMINDERS)' {} + | xargs sed -i "s/$(OLD_REMINDERS)/$(REMINDER_CMTS)/g"
	find . -type f -exec grep -l -F '$(subst |, \,, $(OLD_REMINDERS))' {} + | xargs sed -i "s/$(subst |, \,, $(OLD_REMINDERS))/$(subst |, \,, $(REMINDER_CMTS))/g"

upver :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Updating Software Versions ==='
	# Batch Files #
	find . -mount $(EXCLUDE_FROM_FIND) -type f \( -name "*.bat" -o -name "*.btm" -o -name "*.cmd" -o -name "*.nt" \) -print0 | xargs -0 sed -i "s/^REM @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/REM @version $(__VERSION__)/"
	# C & JavaScript Source Code #
	find . -mount $(EXCLUDE_FROM_FIND) -type f \( -name "*.c" -o -name "*.h" -o -name "*.js" \) -print0 | xargs -0 sed -i "s/^@version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/@version $(__VERSION__)/"
	# Glade Files #
	find . -mount -type f -name "*.glade" -print0 | xargs -0 sed -i "s/^@version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/@version $(__VERSION__)/; s/^Version: 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/Version: $(__VERSION__)/"
	# ManPage Files #
	find $(MANDIRS) -mount -type f \( -name "*.1" -o -name "*.2" -o -name "*.3" -o -name "*.4" -o -name "*.5" -o -name "*.6" -o -name "*.7" -o -name "*.8" \) -print0 | xargs -0 sed -i "s/ \".+\" \"Version: 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]\" / \"$(__TODAY__)\" \"Version: $(__VERSION__)\" /"
	# Perl Scripts #
	# find . -mount $(EXCLUDE_FROM_FIND) -type f \( -name "*.perl" -o -name "*.pl" \) -print0 | xargs -0 sed -i "s/^@version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/@version $(__VERSION__)/; s/^    @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/    @version $(__VERSION__)/;"
	# Python Scripts #
	find . -mount $(EXCLUDE_FROM_FIND) -type f -name "*.py" -print0 | xargs -0 sed -i "s/^__version__ = '20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__ = '$(__VERSION__)'/; s/^__version__ = r'20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__ = r'$(__VERSION__)'/; s/^__version__: str = '20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__: str = '$(__VERSION__)'/; s/^__version__: str = r'20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__: str = r'$(__VERSION__)'/; s/^@version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/@version $(__VERSION__)/; s/^Version: 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/Version: $(__VERSION__)/"
	find $(SCRIPTSRCDIR)/* -mount -type f -print0 | xargs -0 sed -i "s/^@version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/@version $(__VERSION__)/; s/^__version__: str = '20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__: str = '$(__VERSION__)'/; s/^__version__: str = r'20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__: str = r'$(__VERSION__)'/; s/^__version__ = '20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__ = '$(__VERSION__)'/; s/^__version__ = r'20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__ = r'$(__VERSION__)'/"
	# Shell Scripts, Calc Files, makefiles, R, & Conf/INI Files #
	find . -mount $(EXCLUDE_FROM_FIND) -type f \( -name "*.ash" -o -name "*.awk" -o -name "*.bash" -o -name "*.calc" -o -name "*.cfg" -o -name "*.conf" -o -name "*.config" -o -name "*.ini" -o -name "*.ksh" -o -name "makefile" -o -name "*.mk" -o -name "*.R" -o -name "*.nanorc" -o -name "*.sed" -o -name "*.sh" -o -name "*.zsh" -o -name "profile" -o -name "shell_ext" \) -print0 | xargs -0 sed -i "s/^# @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/# @version $(__VERSION__)/; s/^#' @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/#' @version $(__VERSION__)/; s/^version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/version=$(__VERSION__)/; s/^readonly version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/readonly version=$(__VERSION__)/"
	find $(SCRIPTSRCDIR)/* -mount -type f -print0 | xargs -0 sed -i "s/^# @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/# @version $(__VERSION__)/; s/^#' @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/#' @version $(__VERSION__)/; s/^version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/version=$(__VERSION__)/; s/^readonly version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/readonly version=$(__VERSION__)/"
	# XKB #
	find $(XKBDIR)/* -mount -type f -name "usx*" -print0 | xargs -0 sed -i "s/^\/\/ @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/\/\/ @version $(__VERSION__)/"
	find $(XKBDIR)/* -mount -type f -name "XCompose" -print0 | xargs -0 sed -i "s/^#' @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/#' @version $(__VERSION__)/"
	# Miscellaneous #
	find . -mount $(EXCLUDE_FROM_FIND) -type f -name "*.desktop" -print0 | xargs -0 sed -i "s/^Version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/Version=$(__VERSION__)/"
	find . -mount $(EXCLUDE_FROM_FIND) -type f -name "Doxy*" -print0 | xargs -0 sed -i "s/^PROJECT_NUMBER[ \t]*=[ \t]*20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/PROJECT_NUMBER=$(__VERSION__)/"


# CLEAN-UP #


clean : rmtmp rmcache

cleanall : rmtmp rmcache
	-@$(RM) $(BIN)/*

cleanfull : cleanall cleandoc

fixperm :
	-@find . -mount -type d -exec $(CHMOD) 755 '{}' +
	find . -mount -not \( -path "./debugging" $(addprefix -prune -o -path ", $(addsuffix ", $(CHMOD644_NO_SEARCH))) \) -type f \( -name ".csslintrc" $(addprefix -o -name ", $(addsuffix ", $(LIST_CHMOD644_EXT))) \) -exec $(CHMOD) 644 '{}' +
	find $(ACCDIR) $(GEANYDIR) $(THEMEDIR) -mount -type f -exec $(CHMOD) 644 '{}' +
	([ -d $(DOCDIR)/ ] && find $(DOCDIR) -mount -type f -exec $(CHMOD) 644 '{}' +) || true
	find $(PYEGGDIR) -mount -type f -name "*.py" -exec $(CHMOD) 755 '{}' +
	$(CHMOD) 644 $(DBDIR)/* $(INCDIR)/* $(SHRCDIR)/* $(SRCDIR)/* $(PYSRC)/*.py $(EZWINSRC)/*.py
	$(CHMOD) 755 $(BIN)/* $(SCRIPTSRCDIR)/* $(TOOLSDIR)/*.sh $(PYSRC)/ezdisplay.py $(EZWINSRC)/ezwin.py || true

rmcache :
	-@find . -mount -type d -name "__pycache__" -print0 | xargs -0 $(RMDIR)

rmtmp :
	-@find . -mount -type f \( -name "*.o" -o -name "*.ast" -o -name "*.bc" -o -name "*.dump" -o -name "*.i" -o -name "*.ii" -o -name "*.ll" -o -name "*.original" -o -name "*.gch" -o -name "*.pch" -o -name "*.xkm" \) -delete
	find . -mount -type d \( -name "metrics" \) -exec $(RMDIR) '{}' + 2> /dev/null
	$(RM) $(BIN)/test_dev
	$(RMDIR) $(TESTINGDIR)/*
	find $(MANDIRS) -mount -type f \( -name "*.1.gz" -o -name "*.2.gz" -o -name "*.3.gz" -o -name "*.4.gz" -o -name "*.5.gz" -o -name "*.6.gz" -o -name "*.7.gz" -o -name "*.8.gz" \) -delete

refresh : | cleanfull upver fixperm


# GIT COMMANDS #


gitadd : cleanall fixperm
	@git add --all

submitall :
	@git checkout dev
	git push --progress --verify origin dev
	git checkout master && git merge --commit dev && git push --progress --verify origin master
	git checkout dev

submitdev :
	@git push --progress --verify origin dev

submitmaster :
	@git push --progress --verify origin master

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
	git push --progress --verify origin master
	git checkout dev


# MISCELLANEOUS #


macify :
	-@if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(LNDIR) /etc /private

unmacify :
	-@if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	unlink /private


# INSTALL/UNINSTALL #


install_dev : install_langspecs install_nanorc install_program_analyzer install_pyeggs install_scripts

uninstall_dev : uninstall_langspecs uninstall_nanorc uninstall_pyeggs uninstall_pylib

install_clib : | rmtmp fixperm
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing C Libraries ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(INSTALLHEADERSDIR)/ ] && $(RMDIR) $(INSTALLHEADERSDIR)/) || true
	$(MKDIRS) $(INSTALLHEADERSDIR)/
	$(CHMOD) 755 $(INSTALLHEADERSDIR)/
	$(COPY) $(INCDIR)/* $(INSTALLHEADERSDIR)/
	find $(INSTALLHEADERSDIR)/ -type f -exec $(CHMOD) 644 '{}' +
	# Install Documentation
	([ -d $(DOCDIR)/clib/ ] && [ -d $(SYSDOCDIR)/ ] && [ ! -d $(SYSDOCDIR)/clib/ ] && $(MKDIR) $(SYSDOCDIR)/clib/) || true
	([ -d $(DOCDIR)/clib/ ] && [ -d $(SYSDOCDIR)/clib/ ] && $(CPDIR) $(DOCDIR)/clib/* $(SYSDOCDIR)/clib/) || true

uninstall_clib :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling C Libraries ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(INSTALLHEADERSDIR)/ ] && $(RMDIR) $(INSTALLHEADERSDIR)/) || true
	# Uninstall Documentation
	([ -d $(SYSDOCDIR)/clib/ ] && $(RMDIR) $(SYSDOCDIR)/clib/) || true

install_geany_conf :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Geany Configuration Files ==='
	$(RMDIR) ~/.config/geany/filedefs/ ~/.config/geany/templates/files/
	$(CPDIR) $(GEANYDIR)/* ~/.config/geany/
	$(CURUSEROWNS) ~/.config/geany/
	find ~/.config/geany/ -mount -type d -exec $(CHMODR) 750 '{}' +
	find ~/.config/geany/ -mount -type f -exec $(CHMODR) 640 '{}' +
	# sudo rm /usr/share/geany/templates/files/*

install_programs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing /usr/bin Programs ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(COPY) $(addprefix $(BIN)/, $(LIST_UTIL_PROGRAMS)) $(addprefix $(BIN)/, $(LIST_MATH_PROGRAMS)) $(INSTALLBINDIR)/
	$(CHMOD) 755 $(addprefix $(INSTALLBINDIR)/, $(LIST_UTIL_PROGRAMS)) $(addprefix $(INSTALLBINDIR)/, $(LIST_MATH_PROGRAMS))
	# Install ManPages
	for page in $(addsuffix .1, $(LIST_UTIL_PROGRAMS)) $(addsuffix .1, $(LIST_MATH_PROGRAMS)); do if [ -f "$(MAN1DIR)/$${page}" ]; then gzip -9 -k "$(MAN1DIR)/$${page}"; $(MOVE) "$(MAN1DIR)/$${page}.gz" $(MANPAGEDIR)/man1/; else continue; fi; done

uninstall_programs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling /usr/bin Programs ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) $(addprefix $(INSTALLBINDIR)/, $(LIST_UTIL_PROGRAMS)) $(addprefix $(INSTALLBINDIR)/, $(LIST_MATH_PROGRAMS))
	# Uninstall ManPages
	for page in $(addsuffix .1.gz, $(LIST_UTIL_PROGRAMS)) $(addsuffix .1.gz, $(LIST_MATH_PROGRAMS)); do if [ -f "$(MANPAGEDIR)/man1/$${page}" ]; then $(RM) "$(MAN1DIR)/man1/$${page}"; else continue; fi; done

install_bin : install_programs

uninstall_bin : uninstall_programs

install_loginopticons :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing LoginOpticons ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(SYSTHEMEDIR)/LoginOpticons/ ] && $(RMDIR) $(SYSTHEMEDIR)/LoginOpticons/) || true
	$(CPDIR) $(THEMEDIR)/LoginOpticons $(SYSTHEMEDIR)/
	$(UPDATEICONCACHE) $(SYSTHEMEDIR)/LoginOpticons/
	$(UPDATEMIME) $(SYSMIMEDIR)

uninstall_loginopticons :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling LoginOpticons ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(SYSTHEMEDIR)/LoginOpticons/ ] && $(RMDIR) $(SYSTHEMEDIR)/LoginOpticons/) || true
	$(UPDATEMIME) $(SYSMIMEDIR)

install_mimetype_booster :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Mimetypes ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(COPY) $(ACCDIR)/mime.types /etc/mime.types
	$(XDGMIME) install --mode system --novendor $(ACCDIR)/mimetype_booster.xml
	$(UPDATEMIME) $(SYSMIMEDIR)

uninstall_mimetype_booster :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Mimetypes ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(XDGMIME) uninstall --mode system $(SYSMIMEDIR)/packages/mimetype_booster.xml
	$(UPDATEMIME) $(SYSMIMEDIR)

install_langspecs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Language Specifications ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(GTKLANGSPECS2DIR)/ ] && $(COPY) -t $(GTKLANGSPECS2DIR)/ $(addprefix $(LANGSPECSDIR)/, $(addsuffix .lang, $(LIST_LANGSPECS)))) || true
	([ -d $(GTKLANGSPECS3DIR)/ ] && $(COPY) -t $(GTKLANGSPECS3DIR)/ $(addprefix $(LANGSPECSDIR)/, $(addsuffix .lang, $(LIST_LANGSPECS)))) || true

uninstall_langspecs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Language Specifications ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(GTKLANGSPECS2DIR)/ ] && $(RM) $(addprefix $(GTKLANGSPECS2DIR)/, $(addsuffix .lang, $(LIST_LANGSPECS)))) || true
	([ -d $(GTKLANGSPECS3DIR)/ ] && $(RM) $(addprefix $(GTKLANGSPECS3DIR)/, $(addsuffix .lang, $(LIST_LANGSPECS)))) || true

install_nanorc :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing NanoRC ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(SYSNANORCDIR)/ ] && $(COPY) -t $(SYSNANORCDIR)/ $(addprefix $(NANORCDIR)/, $(LIST_NANORC_FILES))) || true

uninstall_nanorc :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling NanoRC ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(SYSNANORCDIR)/ ] && $(RM) $(addprefix $(SYSNANORCDIR)/, $(LIST_NANORC_FILES))) || true

install_opticons :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Opticons ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(SYSTHEMEDIR)/Opticons/ ] && $(RMDIR) $(SYSTHEMEDIR)/Opticons/) || true
	$(CPDIR) $(THEMEDIR)/Opticons $(SYSTHEMEDIR)/
	[ -x "$(command -v update-alternatives)" ] && update-alternatives --install /etc/alternatives/start_icon start-here.svg $(SYSTHEMEDIR)/Opticons/places/start-here.svg 70
	$(UPDATEICONCACHE) $(SYSTHEMEDIR)/Opticons/
	$(UPDATEMIME) $(SYSMIMEDIR)

uninstall_opticons :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Opticons ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(SYSTHEMEDIR)/Opticons/ ] && $(RMDIR) $(SYSTHEMEDIR)/Opticons/ && $(UPDATEMIME) $(SYSMIMEDIR)) || true
	[ -x "$(command -v update-alternatives)" ] && update-alternatives --set start-here.svg /etc/alternatives/start-here.svg

install_pyeggs : | rmtmp fixperm
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Python Eggs ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	(pip3 uninstall flake8_optimal) || true
	cd $(PYEGGDIR)/flake8_optimal/ || exit 1
	python3 ./setup.py install
	$(RMDIR) ./__pycache__/ ./build/ ./dist/ ./flake8_optimal.egg-info/ || true
	cd ../..

uninstall_pyeggs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Python Eggs ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	command -v pip3 >&2 > /dev/null && pip3 uninstall flake8_optimal
	command -v pip3 >&2 > /dev/null || printf '%s\n' 'pip3: command not found!'

$(PYBDIR)/__init__.py : install_pylib

install_pylib : | rmtmp fixperm
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Python Libraries ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(PYBDIR)/ ] && $(RMDIR) $(PYBDIR)/) || true
	([ -d $(PYSRC)/__pycache__/ ] && $(RMDIR) $(PYSRC)/__pycache__/) || true
	([ -d $(PYSRC)/ezwin/__pycache__/ ] && $(RMDIR) $(PYSRC)/ezwin/__pycache__/) || true
	$(MKDIR) $(PYBDIR)/
	$(CPDIR) $(PYSRC)/* $(PYBDIR)/
	# Install Documentation
	([ -d $(DOCDIR)/pylib/ ] && [ -d $(SYSDOCDIR)/ ] && [ ! -d $(SYSDOCDIR)/pylib/ ] && $(MKDIR) $(SYSDOCDIR)/pylib/) || true
	([ -d $(DOCDIR)/pylib/ ] && [ -d $(SYSDOCDIR)/pylib/ ] && $(CPDIR) $(DOCDIR)/pylib/* $(SYSDOCDIR)/pylib/) || true
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
	([ -d $(PYPATH)3.9/ ] && $(LNDIR) $(PYBDIR) $(PYPATH)3.9/pybooster) || true

uninstall_pylib : uninstall_program_analyzer uninstall_scripts
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Python Libraries ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) $(INSTALLBINDIR)/ezdisplay $(INSTALLBINDIR)/ezwin
	([ -d $(PYBDIR)/ ] && $(RMDIR) $(PYBDIR)/) || true
	$(RM) $(PYPATH)3.6/pybooster $(PYPATH)3.7/pybooster $(PYPATH)3.8/pybooster $(PYPATH)3.9/pybooster
	# Uninstall Documentation
	([ -d $(SYSDOCDIR)/pylib/ ] && $(RMDIR) $(SYSDOCDIR)/pylib/) || true

install_program_analyzer : | fixperm $(PYBDIR)/__init__.py
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Program Analyzer ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ ! -d $(INSTALLBINDIR)/ ] && $(MKDIRS) $(INSTALLBINDIR)/) || true
	$(COPY) $(SCRIPTSRCDIR)/program-analyzer $(INSTALLBINDIR)/
	$(COPY) $(MENUDIR)/Program-Analyzer.desktop $(SYSAPPDIR)/
	$(COPY) $(MENUDIR)/program-analyzer $(SYSMENUDIR)/
	$(COPY) $(THEMEDIR)/Opticons/apps/program-analyzer.svg $(PIXMAPDIR)/

uninstall_program_analyzer :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Program Analyzer ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) $(INSTALLBINDIR)/program-analyzer $(SYSAPPDIR)/Program-Analyzer.desktop $(SYSMENUDIR)/program-analyzer $(PIXMAPDIR)/program-analyzer.svg

install_scripts : $(PYBDIR)/__init__.py
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Scripts ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ ! -d $(INSTALLBINDIR)/ ] && $(MKDIRS) $(INSTALLBINDIR)/) || true
	$(COPY) -t $(INSTALLBINDIR)/ $(addprefix $(SCRIPTSRCDIR)/, $(LIST_SCRIPT_PROGRAMS)) $(addprefix $(SCRIPTSRCDIR)/, $(LIST_DEV_SCRIPTS)) $(addprefix $(SCRIPTSRCDIR)/, $(LIST_PYTHON_SCRIPTS))
	$(COPY) $(INSTALLBINDIR)/pyflakes3 /usr/bin/pyflakes
	$(COPY) $(INSTALLBINDIR)/pylint3 /usr/bin/pylint
	$(COPY) $(INSTALLBINDIR)/pylint3 /usr/local/bin/pylint
	$(COPY) $(INSTALLBINDIR)/pylint2 /usr/local/bin/pylint2
	$(COPY) $(INSTALLBINDIR)/pep8 /usr/local/bin/pep8
	$(COPY) $(INSTALLBINDIR)/pep8 /usr/local/bin/pycodestyle
	# Install ManPages
	for page in $(addsuffix .1, $(LIST_SCRIPT_PROGRAMS)) $(addsuffix .1, $(LIST_DEV_SCRIPTS)) $(addsuffix .1, $(LIST_PYTHON_SCRIPTS)); do if [ -f "$(MAN1DIR)/$${page}" ]; then gzip -9 -k "$(MAN1DIR)/$${page}"; $(MOVE) "$(MAN1DIR)/$${page}.gz" $(MANPAGEDIR)/man1/; else continue; fi; done

uninstall_scripts :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Scripts ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) $(addprefix $(INSTALLBINDIR)/, $(LIST_SCRIPT_PROGRAMS)) $(addprefix $(INSTALLBINDIR)/, $(LIST_DEV_SCRIPTS)) $(addprefix $(INSTALLBINDIR)/, $(LIST_PYTHON_SCRIPTS))
	$(RM) /usr/bin/pyflakes /usr/bin/pylint /usr/local/bin/pep8 /usr/local/bin/pycodestyle /usr/local/bin/pylint /usr/local/bin/pylint2
	# Uninstall ManPages
	for page in $(addsuffix .1.gz, $(LIST_SCRIPT_PROGRAMS)) $(addsuffix .1.gz, $(LIST_DEV_SCRIPTS)) $(addsuffix .1.gz, $(LIST_PYTHON_SCRIPTS)); do if [ -f "$(MANPAGEDIR)/man1/$${page}" ]; then $(RM) "$(MAN1DIR)/man1/$${page}"; else continue; fi; done

install_shrc :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Shell Profiles ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	# Backup existing files
	([ -f /etc/bash.bashrc.backup ] && $(RM) /etc/bash.bashrc.backup) || true
	([ -f /etc/bash.bashrc ] && $(MOVE) /etc/bash.bashrc /etc/bash.bashrc.backup) || true
	([ -f /etc/profile.backup ] && $(RM) /etc/profile.backup) || true
	([ -f /etc/profile ] && $(MOVE) /etc/profile /etc/profile.backup) || true
	# Add new files
	$(COPY) -t /etc/ $(SHRCDIR)/profile && $(CHMOD) 644 /etc/profile
	$(LNHARD) /etc/profile /etc/bash.bashrc
	([ ! -d $(INSTALLRCMODDIR) ] && $(MKDIRS) $(INSTALLRCMODDIR)) || true
	$(COPY) -t $(INSTALLRCMODDIR) $(addprefix $(SHRCDIR)/, $(LIST_RC_MODULES))

uninstall_shrc :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Shell Profiles ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) /etc/bash.bashrc /etc/profile
	$(MOVE) /etc/bash.bashrc.backup /etc/bash.bashrc
	$(MOVE) /etc/profile.backup /etc/profile
	$(RMDIR) $(INSTALLRCMODDIR)

install_themes : install_loginopticons install_opticons

uninstall_themes : uninstall_loginopticons uninstall_opticons

install_xcompose :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing XCompose ==='
	$(COPY) $(XKBDIR)/XCompose ~/.XCompose

uninstall_xcompose :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling XCompose ==='
	$(RM) ~/.XCompose

install_xkb :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing XKB Keyboard Layouts ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(TOOLSDIR)/manage_usx.sh --install

uninstall_xkb :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling XKB Keyboard Layouts ==='
	if [ $(UID) != 0 ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(TOOLSDIR)/manage_usx.sh --uninstall

# install_scripts calls install_pylib
install : | rmtmp fixperm install_clib install_programs install_mimetype_booster install_program_analyzer install_pyeggs install_scripts install_themes

# uninstall_pylib calls uninstall_scripts
uninstall : uninstall_clib uninstall_programs uninstall_mimetype_booster uninstall_program_analyzer uninstall_pyeggs uninstall_pylib uninstall_themes


# MATH PROGRAM RULES #


$(BIN)/acos : $(BIN) $(SRCDIR)/acos.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/acosh : $(BIN) $(SRCDIR)/acosh.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/asin : $(BIN) $(SRCDIR)/asin.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/asinh : $(BIN) $(SRCDIR)/asinh.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/atan : $(BIN) $(SRCDIR)/atan.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/atanh : $(BIN) $(SRCDIR)/atanh.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/cbrt : $(BIN) $(SRCDIR)/cbrt.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/cos : $(BIN) $(SRCDIR)/cos.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/cosh : $(BIN) $(SRCDIR)/cosh.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/fib : $(BIN) $(SRCDIR)/fib.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INTS -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF32 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/isprime : $(BIN) $(SRCDIR)/isprime.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INTS -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF32 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/sin : $(BIN) $(SRCDIR)/sin.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/sinh : $(BIN) $(SRCDIR)/sinh.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/sqrt : $(BIN) $(SRCDIR)/sqrt.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/tan : $(BIN) $(SRCDIR)/tan.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/tanh : $(BIN) $(SRCDIR)/tanh.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@


# BUILD PREP #


$(BIN) :
	-@([ ! -d $(BIN)/ ] && $(MKDIR) $(BIN)) || true

$(TESTINGDIR) :
	-@([ ! -d $(TESTINGDIR)/ ] && $(MKDIR) $(TESTINGDIR)) || true


# UTILITY PROGRAM RULES #


$(BIN)/getpgid : $(BIN) $(SRCDIR)/getpgid.c $(MACROSPATH)
	$(CC) -DNO_PRINT_M -DNO_PRINT_FLOATS -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/getsid : $(BIN) $(SRCDIR)/getsid.c $(MACROSPATH)
	$(CC) -DNO_PRINT_M -DNO_PRINT_FLOATS -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/microtime : $(BIN) $(SRCDIR)/microtime.c $(MACROSPATH)
	$(CC) -DNO_PRINT_M -DNO_PRINT_FLOATS -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/ostype : $(BIN) $(SRCDIR)/ostype.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INTS -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF32 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/statvfs : $(BIN) $(SRCDIR)/statvfs.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF512 -DNO_SCAN_FLOATS -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/typesize : $(BIN) $(SRCDIR)/typesize.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF32 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@


# TEST PROGRAM RULES #


$(BIN)/test_dev : $(BIN) $(SRCDIR)/test_dev.c $(MACROSPATH)
	$(CC) -DPRINTF_BUF128 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(TESTINGDIR)/test_dev.s : $(TESTINGDIR) $(SRCDIR)/test_dev.c $(MACROSPATH)
	$(CC) -DPRINTF_BUF128 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(*F)\" $(MINEXE_PARAMS) -fverbose-asm -S $(SRCDIR)/$(@F).c -o $@

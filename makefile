#!/usr/bin/make -f
# -*- coding: utf-8-unix; Mode: Makefile; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=makefile syntax=makefile.doxygen fileformat=unix tabstop=4 :
# kate: encoding utf-8; bom off; syntax makefile; indent-mode normal; eol unix; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Main project makefile
#' @file makefile
#' @version 2020.07.04
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
#' $(*D) - The directory part of the stem
#' $(*F) - The file-within-directory part of the stem
#' $(%D) - The directory part of the target archive member name
#' $(%F) - The file-within-directory part of the target archive member name
#' $(<D) - The directory part of the first prerequisite
#' $(<F) - The file-within-directory part of the first prerequisite
#' $(^D) - Lists the directory parts of all prerequisites
#' $(^F) - Lists the file-within-directory parts of all prerequisites
#' $(?D) - Lists the directory parts of all prerequisites that are newer than the target
#' $(?F) - Lists the file-within-directory parts of all prerequisites that are newer than the target


.POSIX :
.ONESHELL :
override SHELL::=/bin/bash
.SHELLFLAGS::=-c


include ./mk/constants.mk
include ./mk/variables.mk
include ./mk/compiling.mk
include ./mk/project.mk


# VARIABLES #


# Project Paths
override ACCDIR::=./accessory
override BASEDIR::=$(shell pwd)
override BIN::=./bin
override DBDIR::=./databases
override DOCDIR::=./doc
override DEVHELPDIR::=$(DOCDIR)/devhelp
override PYEGGDIR::=./pyegg
override PYSRC::=./pylib
override EZWINSRC::=$(PYSRC)/ezwin
override GEANYDIR::=./geany
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
override MACROSPATH::=$(INCDIR)/Foundation.h $(INCDIR)/MACROS.h $(INCDIR)/MACROS2.h $(INCDIR)/MACROS3.h $(INCDIR)/MACROS_MATH.h $(INCDIR)/MACROS_MISC.h $(INCDIR)/MACROS_NET.h $(INCDIR)/math_tables.h $(INCDIR)/file_signatures.h $(INCDIR)/fs_constants.h $(INCDIR)/fspaths.h

# Install Paths
override INSTALLBINDIR::=$(BINDIR)
override INSTALLHEADERSDIR::=$(SYSINCLUDEDIR)/pybooster
override INSTALLRCMODDIR::=/etc/shell_ext_modules/
override PYBDIR::=/usr/lib/pybooster

# File Lists
override LIST_LANGSPECS::=coffeescript
override LIST_MATH_PROGRAMS::=acos acosh asin asinh atan atanh cbrt cos cosh fib isprime sin sinh sqrt tan tanh
override LIST_UTIL_PROGRAMS::=getpgid getsid microtime ostype statvfs typesize
override LIST_BIN_PROGRAMS::=$(LIST_MATH_PROGRAMS) $(LIST_UTIL_PROGRAMS)
override LIST_PYTHON_LIBRARIES::=astronomy basic bitwise boolean clibutil code_interpreter color compress convarea convlength convmass convspeed convtemp convtime convvolume cryptography datastruct electronics ezdisplay filemagic financial fs geo iterables libchar libregex markup metric multimedia net neuralnet pipx pronouns religion science_data sing strtools system timeutil unix xmath ymath
override LIST_PYTHON_SCRIPTS::=cx_freeze3 cxfreeze3 easy_install3 pip3 pip3-upgrade-all py2dsc pymake pyreverse3 qt5py wpip
override LIST_DEV_SCRIPTS::=canalysis clint cmccabe code-analysis code-formatter coffeeanalysis cssanalysis exewalk file-analysis flake8 goanalysis insn_count jsanalysis jsonanalysis luaanalysis pep257 pep8 phpanalysis pngshrink progstrip py_directive_checker pyanalysis pydocgtk pyflakes2 pyflakes3 pygraphcalls pygraphcalls3 pygraphclasses pygraphclasses3 pygraphimports pygraphimports3 pygraphmemusage pygraphprofile pyinspect pylint2 pylint3 pyprofile2 pyprofile3 pytest3 RCompiler.R RTidy.R run-in-git-proj shanalysis systracer timeit todo-scanner transpile xmlanalysis yamlanalysis
override LIST_RC_MODULES::=aws_rc.sh crypto_rc.sh docker_rc.sh extras_rc.sh multimedia_rc.sh net_rc.sh no_debugging_rc.sh pkg_rc.sh
override LIST_SCRIPT_PROGRAMS::=alphabetize_lines ampupcpu audio-hpss-spectrogram audio-melspectrogram audio-vocals-spectrogram audio-waveplot bin2hex bin2num bin2oct CamelCase char2num cleansystem deep_dreaming deep_dreaming_gaussian_pyramids flipchars genmathart getsysinfo google_translate hex2num holograph2str lslibfunc lsmoduleparams machine_learning man2devhelp minifyxml num2bin num2char num2hex num2oct oct2num PascalCase pipebuf prettifyxml refreshgrub replaceoddchars save_file_times set_access_time setfiletimes str2holograph svgresizer termtest thumbnail-cleaner togglequotes unicalc webget win2unixlines

override LIST_PIP_DEPS::=autopep8 bandit bashate beeprint chardet crimp cupy cx-Freeze docformatter flake8 flake8-2020 flake8-aaa flake8-alfred flake8-broken-line flake8-builtins flake8-coding flake8-comprehensions flake8-datetimez flake8-deprecated flake8-flask flake8-logging-format flake8-markdown flake8-mypy flake8-pyi flake8-super-call flake8-use-fstring gprof2dot isort logilab-common mccabe modulegraph modulegraph2 mypy mypy_extensions numpy pdbpp Pillow psrecord pyaml pycallgraph2 pycodestyle pydocstyle pyflakes pyinstaller pylint pylint-django pylint-flask pylint-flask-sqlalchemy pylint-import-requirements pylint-mongoengine pylint-requests pylint-sqlalchemy pylint-topology pylint-venv pytest pytest-django pytest-isort pytest-mongodb pytest-pdb pytest-pep257 pytest-pep8 pytest-pylint pytest-requests pytest-subprocess radon uncalled vulture yamllint
# Dependencies needed for development of the software in this repository
override LIST_DEV_DEPS::=abi-dumper astyle bindechexascii binwalk bsdiff cccc cgdb chrpath complexity cppcheck cscope doxygen doxygen-gui elfrc elfutils faketime flawfinder freebsd-buildutils gdb gettext gettext-base gettext-doc gettext-lint ghex giggle giggle-personal-details-plugin giggle-terminal-view-plugin gir1.2-dbusmenu-gtk3-0.4 gir1.2-gspell-1 gir1.2-gtk-3.0 gir1.2-gtksource-3.0 gir1.2-keybinder-3.0 gir1.2-webkit2-4.0 git-cola git-extras git-flow git-gui git2cl gitg gitinspector gitlint glade golint graphviz gtk-3-examples iamerican-insane intltool jsonlint kwstyle liwc ltrace meld mscgen optipng patch patchutils pax-utils pmccabe pngcrush pscan python3-demjson python3-dev qgit seed-webkit2 shc shellcheck splint strace ttf-unifont uchardet undertaker unifont unifont-bin universal-ctags universalindentgui vbindiff wamerican-insane xfonts-cyrillic xfonts-mplus xfonts-scalable xfonts-unifont xxdiff yajl-tools yamllint
override LIST_DEV_FONTS::=fonts-emojione fonts-font-awesome fonts-fork-awesome fonts-lao fonts-lato fonts-liberation fonts-liberation2 fonts-mononoki fonts-mplus fonts-nanum-extra fonts-noto-cjk fonts-noto-cjk-extra fonts-noto-color-emoji fonts-noto-core fonts-noto-extra fonts-noto-hinted fonts-noto-mono fonts-noto-ui-core fonts-noto-ui-extra fonts-octicons fonts-open-sans fonts-opensymbol fonts-oxygen fonts-roadgeek fonts-roboto-hinted fonts-roboto-slab fonts-roboto-unhinted fonts-stix fonts-symbola fonts-unfonts-core fonts-unfonts-extra
override LIST_DEV_LIBS::=libamtk-5-0 libamtk-5-dev libaspell-dev libenchant-dev libgit2-27 libgit2-dev libgladeui-2-6 libgladeui-dev libgspell-1-1 libgspell-1-dev libgtk-3-dev libgtkextra-3.0 libgtkextra-dev libgtkhex-3-0 libgtkhex-3-dev libgtkhotkey-dev libgtkhotkey1 libgtkimageview-dev libgtkimageview0 libgtkmathview-bin libgtkmathview-dev libgtkmathview0c2a libgtksourceview-3.0-1 libgtksourceview-3.0-common libgtksourceview-3.0-dev libgtksourceview-4-0 libgtksourceview-4-common libgtksourceview-4-dev libgtkspell3-3-0 libgtkspell3-3-dev libvte-2.91-0 libvte-2.91-dev libwebkit2gtk-4.0-37 libwebkit2gtk-4.0-dev libxfce4ui-glade
# Optional Developer Dependencies
override LIST_DEV_OPT_DEPS::=cleancss php-codesniffer phpmd
override LIST_PIP_OPT_DEPS::=cssmin
# Packages providing documentation that may be needed for development of the software in this repository
override LIST_DEV_DOCS::=apache2-doc bash-doc bison-doc caffe-doc coffeescript-doc cppreference-doc-en-html cython-doc doxygen-doc editorconfig-doc gdb-doc git-doc gle-doc graphviz-doc gstreamer1.0-doc libbash-doc libclutter-1.0-doc libclutter-gst-3.0-doc libclutter-gtk-1.0-doc libgirepository1.0-doc libgladeui-doc libgtk-3-doc libgtkdatabox-doc libgtkextra-3.0-doc libgtkglext1-doc libgtksourceview-3.0-doc libgtksourceview-4-doc libnotify-doc libpango1.0-doc librsvg2-doc libvte-2.91-doc libwebkit2gtk-4.0-doc make-doc nginx-doc octave-doc opencv-doc python-flask-doc python-flask-restful-doc python-flaskext.wtf-doc python-numpy-doc python-pycuda-doc python-setuptools-doc python-sklearn-doc python-werkzeug-doc python-wtforms-doc sqlite3-doc swig-doc swig3.0-doc theano-doc
# Dependencies needed to use most of the software in this repository
override LIST_MAIN_DEPS::=aspell bsdmainutils bsdutils calc clang cloc colormake coreutils curl debianutils devscripts doschk dot enchant exuberant-ctags gcc global hunspell id-utils inkscape ispell libxml2-utils licensecheck llvm make meson moreutils ncc ninja-build pysassc python3-gi python3-pip python3-pyscss python3-setuptools python3-wheel rename sloccount spell spellutils uuid wcalc wget xdg-utils xz-utils

# Search Parameters Used in Find

override CHMOD644_NO_SEARCH::=$(ACCDIR) $(BIN) $(DOCDIR) $(GEANYDIR) $(INCDIR) $(SCRIPTSRCDIR) $(SHRCDIR) $(SRCDIR) $(TESTINGDIR) $(THEMEDIR)
override LIST_CHMOD644_EXT::=*.auk *.awk *.b *.bat *.bf *.bison *.btm *.build *.c *.cfg *.cmd *.cml *.coffee *.conf *.config *.cpp *.css *.csv *.cu *.cuda *.cursor *.d *.desktop *.devhelp *.devhelp2 *.dgml *.di *.dtd *.f *.F *.F03 *.f03 *.f08 *.F08 *.F77 *.f77 *.F90 *.f90 *.f95 *.F95 *.for *.fortan *.fpp *.ftn *.glade *.go *.golang *.h *.htm *.html *.hx *.icon *.js *.json *.lang *.less *.limbo *.lua *.m4 *.mathml *.matlab *.md *.mk *.ml *.mlab *.mli *.mll *.mly *.mml *.nt *.numpy *.octave *.php *.php4 *.php5 *.php6 *.php7 *.rb *.reg *.rng *.rst *.sass *.scss *.svg *.swg *.tcl *.theme *.theme.in *.types *.wasm *.xht *.xlst *.xml *.xsd *.xsl *.y *.yaml *.yml *.yy *.yy *AUTHORS .editorconfig .eslintrc .gitattributes .gitignore .gitlint .gitmodules .pylintrc CHANGELOG ChangeLog Doxyfile icon-theme.cache LICENSE PKG-INFO README THANKS TODO
override EXCLUDE_FROM_FIND::=-not \( -path "$(DBDIR)/*" -o -path "$(DOCDIR)/*" -o -path "$(GEANYDIR)/*" -o -path "$(SCHEMASDIR)/*" -o -path "./screenshots/*" -o -path "$(THEMEDIR)/LoginOpticons/*" -o -path "$(THEMEDIR)/Opticons/*" -o -path "$(THEMEDIR)/Optimal-Cursors/Optimal-Cursors-White/*" -o -path "$(THEMEDIR)/Optimal-Cursors/Optimal-Cursors/*" -o -path "$(THEMEDIR)/OptiView/*" \)


# HELP #


help :
	@printf '\n\x1b[1;4;33m§ %s §\x1b[0m\n\n' 'COMPILATION INSTRUCTIONS'
	printf '%s\n\t%s\n' 'Everything:' 'make all'
	printf '%s\n\t%s\n' 'Everything (using Clang):' 'make all USECLANG=5.0  # Specify version'
	printf '%s\n\t%s\n' 'Strip Binaries:' 'make strip'
	printf '\n\n\x1b[1;4;33m§ %s §\x1b[0m\n\n' 'INSTALL/UNINSTALL'
	printf '%s\n\t%s\n' 'Install:' 'sudo make install'
	printf '%s\n\t%s\n' 'Uninstall:' 'sudo make uninstall'
	printf '%s\n\t%s\n' '/usr/bin Utils:' 'sudo make install_programs'
	printf '%s\n\t%s\n' 'Additional Mimetypes:' 'sudo make install_mimetype_booster'
	printf '%s\n\t%s\n' 'C Libraries:' 'sudo make install_clib'
	printf '%s\n\t%s\n' 'Color Kit:' 'sudo make install_color_kit'
	printf '%s\n\t%s\n' 'Desktop Entry Maker:' 'sudo make install_desktop_entry_maker'
	printf '%s\n\t%s\n' 'Devhelp Files:' 'sudo make install_devhelp'
	printf '%s\n\t%s\n' 'Enhanced XCompose File:' 'make install_xcompose'
	printf '%s\n\t%s\n' 'GitStats:' 'make install_gitstats'
	printf '%s\n\t%s\n' 'Language Specification Files:' 'sudo make install_langspecs'
	printf '%s\n\t%s\n' 'Linux Driver Module for Clevo Keyboard Backlights:' 'sudo make install_dkms_clevo_kbd_backlight'
	printf '%s\n\t%s\n' 'NanoRC Files:' 'sudo make install_nanorc'
	printf '%s\n\t%s\n' 'Opticons:' 'sudo make install_opticons'
	printf '%s\n\t%s\n' 'OptiView:' 'sudo make install_optiview'
	printf '%s\n\t%s\n' 'Optimal Cursors:' 'sudo make install_optimal_cursors'
	printf '%s\n\t%s\n' 'Python Eggs:' 'sudo make install_pyeggs'
	printf '%s\n\t%s\n' 'Python Libraries:' 'sudo make install_pylib'
	printf '%s\n\t%s\n' 'Scripts:' 'sudo make install_scripts'
	printf '%s\n\t%s\n' 'Shell RC Scripts:' 'sudo make install_shrc'
	printf '\t • %s\n' 'nogeo=1: Do not create geofiles under `/etc/` and disable geolocation features in `profile`'
	printf '\t • %s\n' 'nogeo=0: Enable and install geolocation features and files (Default)'
	printf '\t • %s\n' 'nogeo=-1: Do not create geofiles under `/etc/`, but enable geolocation features in `profile`'
	printf '\t • %s\n' 'nogeo=-2: Create geofiles under `/etc/`, but disable geolocation features in `profile`'
	printf '%s\n\t%s\n' 'Themes & Icons:' 'sudo make install_themes'
	printf '%s\n\t%s\n' 'Thunar Custom Actions:' 'sudo make install_uca'
	printf '%s\n\t%s\n' 'XKB Files:' 'sudo make install_xkb'
	printf '\n\n\x1b[1;4;33m§ %s §\x1b[0m\n\n' 'PROJECT MANAGEMENT'
	printf '%s\n\t%s\n' 'Backup Project:' 'make backup'
	printf '%s\n\t%s\n' 'Create 7z Backup:' 'make pkg7z'
	printf '%s\n\t%s\n' 'Create Zip Backup:' 'make pkgzip'
	printf '%s\n\t%s\n' 'Fix File Permissions:' 'make fixperm'
	printf '%s\n\t%s\n' 'Generate CTags:' 'make ctags'
	printf '%s\n\t%s\n' 'Generate All Documentation:' 'make doc'
	printf '%s\n\t%s\n' 'Generate C Documentation:' 'make docc'
	printf '%s\n\t%s\n' 'Generate Python Documentation:' 'make docpy'
	printf '%s\n\t%s\n' 'Package Release:' 'make pkg'
	printf '%s\n\t%s\n' 'Refresh Files (cleanall, fixperm, & upver):' 'make refresh'
	printf '%s\n\t%s\n' 'Synchronize Version Numbers:' 'make upver'
	printf '\n\n\x1b[1;4;33m§ %s §\x1b[0m\n\n' 'CLEAN'
	printf '%s\n\t%s\n' 'Clean Everything and Documentation:' 'make cleanfull'
	printf '%s\n\t%s\n' 'Clean Temp, Object, Cache, and Binary Files:' 'make cleanall'
	printf '%s\n\t%s\n' 'Remove Documentation:' 'make cleandoc'
	printf '%s\n\t%s\n' 'Remove Cache Files:' 'make rmcache'
	printf '%s\n\t%s\n' 'Remove Temp and Object Files:' 'make rmtmp'
	printf '%s\n\t%s\n' 'Remove Temp, Object, and Cache Files:' 'make clean'
	printf '\n\n\x1b[1;4;33m§ %s §\x1b[0m\n\n' 'MISCELLANEOUS'
	printf '%s\n\t%s\n' 'Fix various Nvidia issues:' 'sudo make fix_nvidia'
	printf '%s\n\t%s\n' 'Enable geolocation features in `profile`:' 'sudo make enable_geofiles'
	printf '%s\n\t%s\n' 'Disable geolocation features in `profile`:' 'sudo make disable_geofiles'
	printf '%s\n\t%s\n' 'Create geolocation files under `/etc/`:' 'sudo make install_geofiles'
	printf '%s\n\t%s\n' 'Remove geolocation files under `/etc/`:' 'sudo make uninstall_geofiles'
	printf '%s\n\t%s\n' 'Update geolocation files under `/etc/`:' 'sudo make update_geofiles'
	printf '%s\n\t%s\n' 'Make the system more like OSX:' 'sudo make macify'
	printf '%s\n\t%s\n' 'Undo the effects of `macify`:' 'sudo make unmacify'
	printf '%s\n\t%s\n' 'Replace the current /etc/apt/sources.list with a new list (Ubuntu only):' 'sudo make replace_repos'
	printf '%s\n\t%s\n' 'Make the system more secure:' 'sudo make secure'
	printf '%s\n\t%s\n' 'Fix the Thunar Archive Plugin (TAP):' 'sudo make fix_thunar_tap'
	printf '\n\n\x1b[1;4;33m§ %s §\x1b[0m\n\n' 'VARIABLES'
	printf '%s\n • %s\n • %s\n • %s\n' 'Specify OS:' 'OS=ANDROID' 'OS=LINUX' 'OS=POSIX'
	printf '%s\n • %s\n • %s\n' 'Specify Architechure:' 'ARCH=armv7' 'ARCH=haswell'
	printf ' • %s\n • %s\n • %s\n' 'ARCH=intel' 'ARCH=intel BITS=64' 'ARCH=skylake'
	printf '%s\n • %s\n • %s\n' 'Cross-Compile:' 'CROSS_COMPILE=android' 'CROSS_COMPILE=armhf'
	printf ' • %s\n • %s\n • %s\n' 'CROSS_COMPILE=rpi' 'CROSS_COMPILE=x86-64' 'NOTE: Windows may not be fully supported'
	printf '%s\n' 'Enable Pthread: PTHREAD=1'
	printf '\n\n\x1b[1;4;33m§ %s §\x1b[0m\n\n' 'ENABLE/DISABLE CODE & FEATURES'
	printf '%s\n' '-DENABLE_BEOS_MACROS: Enable BeOS macros'
	printf '%s\n' '-DENABLE_ELF_HEADERS: Enable ELF headers containing macros, datatypes, etc.'
	printf '%s\n' '-DENABLE_EMBEDDED_DEVICE_DATATYPES: Enable embedded device datatypes'
	printf '%s\n' '-DENABLE_FORMAT_SPECIFIERS: Enable printf/scanf format specifiers'
	printf '%s\n' '-DENABLE_IIO_TYPES: Enable IIO datatypes'
	printf '%s\n' '-DENABLE_MACH_FEATURES: Enable Mach features'
	printf '%s\n' '-DENABLE_PRTYPES: Enable prtypes'
	printf '%s\n' '-DENABLE_XNU_DATATYPES: Enable XNU datatypes'
	printf '%s\n' '-DDISABLE_ANSI_SGR: Disable ANSI SGR features'
	printf '%s\n' '-DDISABLE_NETWORK_HEADER: Disable the whole MACROS_NET.h file'
	printf '%s\n' '-DDISABLE_MISC_HEADER: Disable the whole MACROS_MISC.h file'
	printf '%s\n' '-DNO_SCAN_FLOATS: The `f` and `g` (float-points) symbols are disabled in `scanf()`'
	printf '%s\n' '-DNO_CHAR_TABLES: Disables many character tables like armscii, cjk_variants, nextstep, and more'
	printf '\n\n\x1b[1;4;33m§ %s §\x1b[0m\n\n' 'TWEAK PRINTF'
	printf '%s\n' '-DNO_PRINT_ACTION: Disable the `%n` (printf action) symbol'
	printf '%s\n' '-DNO_PRINT_M: Disable the `%m` (error code) symbol'
	printf '%s\n' '-DNO_PRINT_CHARS: Disable all character-related symbols'
	printf '%s\n' '-DNO_PRINT_FLOATS: Disable the `%f` and `%g` (float-points) symbols'
	printf '%s\n' '-DNO_PRINT_INTS: Disable all integer-related symbols'
	printf '%s\n' '-DNO_PRINT_INT128: Disable all 128-bit integer-related symbols'
	printf '%s\n' '-DNO_PRINT_STRINGS: Disable all string-related symbols'
	printf '%s\n' '-DNO_PRINT_WIDTH_PREC: Disable all width and precision related symbols'
	printf '%s\n' '-DPRINTF_BUF32: Set the size of the internal printf buffer to 32-bytes'
	printf '%s\n' '-DPRINTF_BUF64: Set the size of the internal printf buffer to 64-bytes'
	printf '%s\n' '-DPRINTF_BUF128: Set the size of the internal printf buffer to 128-bytes'
	printf '%s\n' '-DPRINTF_BUF256: Set the size of the internal printf buffer to 256-bytes'
	printf '%s\n' '-DPRINTF_BUF512: Set the size of the internal printf buffer to 512-bytes'
	printf '%s\n' '-DPRINTF_BUF1024: Set the size of the internal printf buffer to 1024-bytes'
	printf '%s\n\n' '-DPRINTF_BUF2048: Set the size of the internal printf buffer to 2048-bytes'


default :
	@help


# PHONY #


# Build Commands
.PHONY : all byte programs math_programs
# Development
.PHONY : ctags debug_xkb pathcheck pathchk print_xkb strip svglint TAGS
# Documentation
.PHONY : cleandoc doc docc docpy doxy manpages
# General Project Utilities
.PHONY : getdeps getdeps_all getdeps_pip getdocs setup_dev_gtk update_doccmt_keywords update_reminders upver
# Clean-up
.PHONY : clean cleanall cleanfull fixperm refresh rmcache rmtmp
# Git
.PHONY : gitadd presubmit submitall submitdev submitmaster sw2dev sw2master syncdev syncmaster
# Install DKMS Driver Modules
.PHONY : install_dkms_clevo_kbd_backlight
# Uninstall DKMS Driver Modules
.PHONY : uninstall_dkms_clevo_kbd_backlight
# Install
.PHONY : install install_bin install_clib install_color_kit install_desktop_entry_maker install_dev install_devhelp install_geany_conf install_gitstats install_langspecs install_loginopticons install_mimetype_booster install_nanorc install_opticons install_optimal_cursors install_optiview install_program_analyzer install_programs install_pyeggs install_pylib install_scripts install_shrc install_themes install_uca install_xcompose install_xkb
# Uninstall
.PHONY : uninstall uninstall_bin uninstall_clib uninstall_color_kit uninstall_desktop_entry_maker uninstall_dev uninstall_devhelp uninstall_gitstats uninstall_langspecs uninstall_loginopticons uninstall_mimetype_booster uninstall_opticons uninstall_optimal_cursors uninstall_optiview uninstall_program_analyzer uninstall_programs uninstall_pyeggs uninstall_pylib uninstall_scripts uninstall_shrc uninstall_themes uninstall_uca uninstall_xcompose uninstall_xkb
# Miscellaneous
.PHONY : disable_geofiles enable_geofiles fix_nvidia fix_thunar_tap install_geofiles macify replace_repos secure uninstall_geofiles unmacify update_geofiles


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
	./$(TOOLSDIR)/generate_ctags.sh

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
	-@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Cleaning Documentation Files ==='
	$(RMDIR) $(DOCDIR)/clib $(DOCDIR)/pylib

doc : docc docpy manpages

docc : fixperm
	-@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Generating C-Documentation ==='
	([ -f $(DOCDIR)/index.html ] && unlink $(DOCDIR)/index.html) || true
	([ -d $(DOCDIR)/clib ] && $(RMDIR) $(DOCDIR)/clib) || true
	doxygen ./Doxyfile > /dev/null
	find $(DOCDIR) -mount -type d -exec $(CHMOD) 755 '{}' +
	find $(DOCDIR) -mount -type f -exec $(CHMOD) 644 '{}' +
	# Restructure Directory Hierarchy
	([ ! -d $(DOCDIR)/man3/ ] && $(MKDIR) $(DOCDIR)/man3/) || true
	$(MOVE) $(DOCDIR)/clib/man/man3/* $(DOCDIR)/man3/
	$(MOVE) $(DOCDIR)/clib/html/* $(DOCDIR)/clib/
	$(RMDIR) $(DOCDIR)/clib/html $(DOCDIR)/clib/man
	# Create link to index.html
	cd $(DOCDIR) && $(LNSOFT) ./clib/index.html ./index.html && cd ..
	# Remove unneeded files
	$(RM) $(DOCDIR)/man3/*_PyBooster_include_.3

docpy : fixperm
	-@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Generating Python-Documentation ==='
	([ -d $(DOCDIR)/pylib ] && $(RMDIR) $(DOCDIR)/pylib) || true
	./tools/pydocgen.sh $(PYSRC) $(DOCDIR) $(LIST_PYTHON_LIBRARIES) > /dev/null
	find $(DOCDIR) -mount -type d -exec $(CHMOD) 755 '{}' +
	find $(DOCDIR) -mount -type f -exec $(CHMOD) 644 '{}' +

doxy :
	-@doxywizard ./Doxyfile
	$(CHMOD) 644 ./Doxyfile

manpages :
	-@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Compressing ManPages ==='
	find $(MANDIRS) -mount -type f \( -name "*.1" -o -name "*.2" -o -name "*.3" -o -name "*.4" -o -name "*.5" -o -name "*.6" -o -name "*.7" -o -name "*.8" \) -print0 | xargs -0 gzip -9 -k


# PACKAGING #


.PHONY : backup pkg pkg7z pkglzma pkgSFX pkgxz pkgzip


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


setup_dev_gtk :
	@gsettings set org.gtk.Settings.Debug enable-inspector-keybinding true


getdeps : getdeps_pip
	@([ -d /etc/apt ] && [ -x "$(command -v apt-get)" ] && (apt-get install $(LIST_MAIN_DEPS) && printf 'If desired, execute `\x1b[4;33msudo add-apt-repository ppa:geany-dev/ppa\x1b[0m`\n' || true)) || \
	([ -d /etc/dnf ] && [ -x "$(command -v dnf)" ] && (dnf install $(LIST_MAIN_DEPS) || true)) || \
	([ -d /etc/portage ] && [ -x "$(command -v emerge)" ] && (emerge -a $(LIST_MAIN_DEPS) || true)) || true

getdocs :
	@([ -d /etc/apt ] && [ -x "$(command -v apt-get)" ] && (apt-get install $(LIST_DEV_DOCS) || true)) || \
	([ -d /etc/dnf ] && [ -x "$(command -v dnf)" ] && (dnf install $(LIST_DEV_DOCS) || true)) || \
	([ -d /etc/portage ] && [ -x "$(command -v emerge)" ] && (emerge -a $(LIST_DEV_DOCS) || true)) || true

getdeps_all : getdeps getdocs
	@([ -d /etc/apt ] && [ -x "$(command -v apt-get)" ] && (apt-get install $(LIST_DEV_LIBS) $(LIST_DEV_DEPS) $(LIST_DEV_FONTS) || true)) || \
	([ -d /etc/dnf ] && [ -x "$(command -v dnf)" ] && (dnf install $(LIST_DEV_LIBS) $(LIST_DEV_DEPS) $(LIST_DEV_FONTS) || true)) || \
	([ -d /etc/portage ] && [ -x "$(command -v emerge)" ] && (emerge -a $(LIST_DEV_LIBS) $(LIST_DEV_DEPS) $(LIST_DEV_FONTS) || true)) || true

getdeps_pip :
	@(command -v pip3 >&2 > /dev/null && pip3 install $(LIST_PIP_DEPS)) || (command -v pip >&2 > /dev/null && pip install $(LIST_PIP_DEPS)) || true
	find /home -type f -name 'graphviz.py' -print0 2> /dev/null | xargs -0 grep -l -F 'Python Call Graph' | xargs sed -i "s|generated_message = r'Generated by Python Call Graph v%s' % __version__|generated_message = ''|" 2> /dev/null
	find /usr -type f -name 'graphviz.py' -print0 2> /dev/null | xargs -0 grep -l -F 'Python Call Graph' | xargs sed -i "s|generated_message = r'Generated by Python Call Graph v%s' % __version__|generated_message = ''|" 2> /dev/null

update_doccmt_keywords :
	-@find $(GEANYDIR)/filedefs -type f -exec grep -l -F 'docComment=' {} + | xargs sed -i "s/docComment=.*/docComment=$(DOCCMT_KEYWORDS)/g"

update_reminders :
	find . -type f -exec grep -l -F '$(OLD_REMINDERS)' {} + | xargs sed -i "s/$(OLD_REMINDERS)/$(REMINDER_CMTS)/g"
	find . -type f -exec grep -l -F '$(subst |,$(comma),$(OLD_REMINDERS))' {} + | xargs sed -i "s/$(subst |,$(comma),$(OLD_REMINDERS))/$(subst |,$(comma),$(REMINDER_CMTS))/g"

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
	find . -mount $(EXCLUDE_FROM_FIND) -type f \( -name "*.ash" -o -name "*.awk" -o -name "*.bash" -o -name "*.calc" -o -name "*.cfg" -o -name "*.conf" -o -name "*.config" -o -name "*.ini" -o -name "*.ksh" -o -name "makefile" -o -name "*.mk" -o -name "*.R" -o -name "*.nanorc" -o -name "*.sed" -o -name "*.sh" -o -name "*.tap" -o -name "*.zsh" -o -name "profile" -o -name "shell_ext" \) -print0 | xargs -0 sed -i "s/^# @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/# @version $(__VERSION__)/; s/^#' @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/#' @version $(__VERSION__)/; s/^version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/version=$(__VERSION__)/; s/^readonly version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/readonly version=$(__VERSION__)/"
	find $(SCRIPTSRCDIR)/* -mount -type f -print0 | xargs -0 sed -i "s/^# @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/# @version $(__VERSION__)/; s/^#' @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/#' @version $(__VERSION__)/; s/^version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/version=$(__VERSION__)/; s/^readonly version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/readonly version=$(__VERSION__)/"
	# Windows Registry Files #
	find . -mount $(EXCLUDE_FROM_FIND) -type f -name "*.reg" -print0 | xargs -0 sed -i "s/^; @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/; @version $(__VERSION__)/"
	# XKB #
	find $(XKBDIR)/* -mount -type f -name "usx*" -print0 | xargs -0 sed -i "s/^\/\/ @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/\/\/ @version $(__VERSION__)/"
	# Miscellaneous #
	find $(ACCDIR)/* -mount -type f -name "XCompose" -print0 | xargs -0 sed -i "s/^#' @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/#' @version $(__VERSION__)/"
	find ./dkms/* -mount -type f -name "dkms.conf" -print0 | xargs -0 sed -i "s/^PACKAGE_VERSION=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/PACKAGE_VERSION=$(__VERSION__)/"
	find ./dkms/* -mount -type f -name "Makefile" -print0 | xargs -0 sed -i "s/^VERSION := 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/VERSION := $(__VERSION__)/"
	find . -mount $(EXCLUDE_FROM_FIND) -type f -name "*.desktop" -print0 | xargs -0 sed -i "s/^Version=20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/Version=$(__VERSION__)/"
	find . -mount $(EXCLUDE_FROM_FIND) -type f -name "Doxy*" -print0 | xargs -0 sed -i "s/^PROJECT_NUMBER[ \t]*=[ \t]*20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/PROJECT_NUMBER=$(__VERSION__)/"


# CLEAN-UP #


clean : rmtmp rmcache

cleanall : rmtmp rmcache
	-@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Cleaning Temporary Files & Cache ==='
	$(RM) $(BIN)/*

cleanfull : cleanall cleandoc

fixperm :
	-@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Fixing File Permissions ==='
	find . -mount -type d -exec $(CHMOD) 755 '{}' +
	find . -mount -not \( -path "./debugging" $(addprefix -prune -o -path ", $(addsuffix ", $(CHMOD644_NO_SEARCH))) \) -type f \( -name ".csslintrc" $(addprefix -o -name ", $(addsuffix ", $(LIST_CHMOD644_EXT))) \) -exec $(CHMOD) 644 '{}' +
	find $(ACCDIR) $(GEANYDIR) $(THEMEDIR) -mount -type f -exec $(CHMOD) 644 '{}' +
	([ -d $(DOCDIR)/ ] && find $(DOCDIR) -mount -type f -exec $(CHMOD) 644 '{}' +) || true
	find $(PYEGGDIR) -mount -type f -name "*.py" -exec $(CHMOD) 755 '{}' +
	find $(THEMEDIR)/OptiView -mount -type f \( -name "*.build" -o -name "*.scss" -o -name "*.svg" -o -name "*.theme" -o -name "*.theme.in" \) -exec $(CHMOD) 644 '{}' +
	find $(THEMEDIR)/OptiView -mount -type f -name "*.sh" -exec $(CHMOD) 755 '{}' +
	$(CHMOD) 644 $(DBDIR)/* $(INCDIR)/* $(SHRCDIR)/* $(SRCDIR)/* $(PYSRC)/*.py $(EZWINSRC)/*.py "$(THEMEDIR)/Optimal-Cursors/src/cursorList"
	$(CHMOD) 755 $(BIN)/* $(SCRIPTSRCDIR)/* $(TOOLSDIR)/*.sh $(PYSRC)/ezdisplay.py $(EZWINSRC)/ezwin.py || true

rmcache :
	-@find . -mount -type d -name "__pycache__" -print0 | xargs -0 $(RMDIR)

rmtmp :
	-@find . -mount -type f \( -name "*.ast" -o -name "*.bc" -o -name "*.dll" -o -name "*.dump" -o -name "*.exp" -o -name "*.gch" -o -name "*.i" -o -name "*.ii" -o -name "*.lib" -o -name "*.ll" -o -name "*.mi" -o -name "*.mii" -o -name "*.o" -o -name "*.obj" -o -name "*.original" -o -name "*.pch" -o -name "*.xkm" \) -delete
	find . -mount -type d \( -name "metrics" \) -exec $(RMDIR) '{}' + 2> /dev/null
	$(RM) $(BIN)/test_dev
	$(RMDIR) $(TESTINGDIR)/*
	find $(MANDIRS) -mount -type f \( -name "*.1.gz" -o -name "*.2.gz" -o -name "*.3.gz" -o -name "*.4.gz" -o -name "*.5.gz" -o -name "*.6.gz" -o -name "*.7.gz" -o -name "*.8.gz" \) -delete

refresh : | cleanfull upver fixperm


# GIT COMMANDS #


gitadd : cleanall fixperm
	@git add --all

presubmit : cleanall fixperm pkgzip changelogmd news genchecksums valchecksums
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Committing Changes ==='
	git add --all
	git commit --cleanup=strip --message='Stable Release (v$(__VERSION__))' --signoff

submitall : presubmit
	@git checkout dev
	git push --progress --verify origin dev
	git checkout master && git merge --commit --signoff dev && git push --progress --verify origin master
	git checkout dev
	git tag -s -a 'v$(__VERSION__)' -m 'Stable Release (v$(__VERSION__))'
	git push origin --tags

submitdev : presubmit
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Pushing Changes ==='
	git push --progress --verify origin dev

submitmaster : presubmit
	@git push --progress --verify origin master

submitrel : presubmit xtag pushtags
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Pushing Changes (dev) ==='
	git push --progress --verify origin dev
	printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Syncing Master Branch ==='
	git checkout master
	git merge --commit --signoff dev
	git push --progress --verify origin master
	git checkout dev

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


fix_nvidia :
	-@if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(TOOLSDIR)/fix_nvidia.sh

fix_thunar_tap :
	-@if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	if [ -d /usr/lib/x86_64-linux-gnu/thunar-archive-plugin/ ]; then $(LNDIR) /usr/lib/x86_64-linux-gnu/thunar-archive-plugin/file-roller.tap /usr/lib/x86_64-linux-gnu/thunar-archive-plugin/org.gnome.FileRoller.tap; fi

enable_geofiles :
	-@if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -f /etc/geoprofile_disable ] && $(RM) /etc/geoprofile_disable) || true

disable_geofiles :
	-@if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ ! -f /etc/geoprofile_disable ] && touch /etc/geoprofile_disable) || true

install_geofiles :
	-@if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ ! -f /etc/area_code ] && ./scripts/webget ipinfo.io/phone > /etc/area_code) || true
	([ ! -f /etc/city ] && ./scripts/webget ipinfo.io/city > /etc/city) || true
	([ ! -f /etc/country ] && ./scripts/webget ipinfo.io/country > /etc/country) || true
	([ ! -f /etc/isp ] && ./scripts/webget ipinfo.io/isp > /etc/isp) || true
	([ ! -f /etc/location ] && ./scripts/webget ipinfo.io/loc > /etc/location) || true
	([ ! -f /etc/postal ] && ./scripts/webget ipinfo.io/postal > /etc/postal) || true
	([ ! -f /etc/region ] && ./scripts/webget ipinfo.io/region > /etc/region) || true

update_geofiles : uninstall_geofiles install_geofiles

uninstall_geofiles :
	-@if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) /etc/area_code /etc/city /etc/country /etc/isp /etc/location /etc/postal /etc/region

macify :
	-@if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(LNDIR) /etc /private

unmacify :
	-@if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	unlink /private

replace_repos :
	-@if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	if [ -f /etc/lsb-release ]; then . /etc/lsb-release; fi
	[ -f /etc/lsb-release ] && . /etc/lsb-release
	[ -z "$${DISTRIB_ID:-}" ] && [ "$${DISTRIB_ID:-}" == 'Ubuntu' ] && $(ACCDIR)/getgpgkeys.sh
	[ -z "$${DISTRIB_ID:-}" ] && [ "$${DISTRIB_ID:-}" == 'Ubuntu' ] && $(COPY) $(ACCDIR)/Ubuntu_Repos.list /etc/apt/sources.list
	[ -n "$${DISTRIB_CODENAME:-}" ] && [ "$${DISTRIB_ID:-}" == 'Ubuntu' ] && sed -i "s/cosmic/$${DISTRIB_CODENAME}/g" /etc/apt/sources.list;

secure :
	-@if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(TOOLSDIR)/secure_system.sh


# INSTALL DKMS DRIVER MODULES #


install_dkms_clevo_kbd_backlight :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Clevo Keyboard Backlight Driver ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	cd ./dkms/clevo_kbd_backlight/
	make build_install
	cd ../..
	groupadd --system clevo 2> /dev/null || true
	usermod --append --groups clevo ${USER} 2> /dev/null || true


# UNINSTALL DKMS DRIVER MODULES #


uninstall_dkms_clevo_kbd_backlight :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Clevo Keyboard Backlight Driver ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	cd ./dkms/clevo_kbd_backlight/
	make uninstall
	cd ../..


# INSTALL/UNINSTALL #


install_dev : install_langspecs install_nanorc install_program_analyzer install_pyeggs install_scripts

uninstall_dev : uninstall_langspecs uninstall_pyeggs uninstall_pylib

install_clib : | rmtmp fixperm
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing C Libraries ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
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
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(INSTALLHEADERSDIR)/ ] && $(RMDIR) $(INSTALLHEADERSDIR)/) || true
	# Uninstall Documentation
	([ -d $(SYSDOCDIR)/clib/ ] && $(RMDIR) $(SYSDOCDIR)/clib/) || true

install_color_kit : | fixperm $(PYBDIR)/__init__.py
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Color Kit ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ ! -d $(INSTALLBINDIR)/ ] && $(MKDIRS) $(INSTALLBINDIR)/) || true
	$(COPY) $(SCRIPTSRCDIR)/color-kit $(INSTALLBINDIR)/
	$(COPY) $(MENUDIR)/Color-Kit.desktop $(SYSAPPDIR)/
	$(COPY) $(MENUDIR)/color-kit $(SYSMENUDIR)/
	$(COPY) $(THEMEDIR)/Opticons/apps/color-kit.svg $(PIXMAPDIR)/

uninstall_color_kit :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Color Kit ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) $(INSTALLBINDIR)/color-kit $(SYSAPPDIR)/Color-Kit.desktop $(SYSMENUDIR)/color-kit $(PIXMAPDIR)/color-kit.svg

install_desktop_entry_maker : | fixperm
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Desktop Entry Maker ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ ! -d $(INSTALLBINDIR)/ ] && $(MKDIRS) $(INSTALLBINDIR)/) || true
	$(COPY) $(SCRIPTSRCDIR)/desktop-entry-maker $(INSTALLBINDIR)/
	$(COPY) $(MENUDIR)/Desktop-Entry-Maker.desktop $(SYSAPPDIR)/
	$(COPY) $(MENUDIR)/desktop-entry-maker $(SYSMENUDIR)/
	$(COPY) $(THEMEDIR)/Opticons/apps/menu-editor.svg $(PIXMAPDIR)/

uninstall_desktop_entry_maker :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Desktop Entry Maker ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) $(INSTALLBINDIR)/desktop-entry-maker $(SYSAPPDIR)/Desktop-Entry-Maker.desktop $(SYSMENUDIR)/desktop-entry-maker $(PIXMAPDIR)/menu-editor.svg

install_devhelp : | fixperm
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Devhelp Files ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	./tools/install_devhelp_docs.sh '$(DEVHELPDIR)'

uninstall_devhelp :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Devhelp Files ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) /usr/share/devhelp/books/bash/bash.devhelp2 /usr/share/devhelp/books/bash /usr/share/devhelp/books/clang/clang.devhelp2 /usr/share/devhelp/books/clang /usr/share/devhelp/books/dpdk/dpdk.devhelp2 /usr/share/devhelp/books/dpdk /usr/share/devhelp/books/gcc/gcc.devhelp2 /usr/share/devhelp/books/gcc /usr/share/devhelp/books/gdb/gdb.devhelp2 /usr/share/devhelp/books/gdb /usr/share/devhelp/books/llvm/llvm.devhelp2 /usr/share/devhelp/books/llvm /usr/share/devhelp/books/numpy/numpy.devhelp2 /usr/share/devhelp/books/numpy || true
	([ -d /usr/share/devhelp/books/manpages/ ] && $(SCRIPTSRCDIR)/man2devhelp uninstall) || true

install_geany_conf :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Geany Configuration Files ==='
	if [ "$(UID)" == '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are NOT required!\n\n' >&2; exit 1; fi
	$(RMDIR) ~/.config/geany/filedefs/ ~/.config/geany/templates/files/
	$(CPDIR) $(GEANYDIR)/* ~/.config/geany/
	$(CHOWNR) $(USERNAME):$(USERNAME) ~/.config/geany/
	find ~/.config/geany/ -mount -type d -exec $(CHMODR) 750 '{}' +
	find ~/.config/geany/ -mount -type f -exec $(CHMODR) 640 '{}' +
	# [ -d /usr/share/geany/templates/files ] && sudo rm /usr/share/geany/templates/files/*
	# [ -d /usr/local/share/geany/templates/files ] && sudo rm /usr/local/share/geany/templates/files/*

install_gitstats :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Gitstats ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(COPY) ./scripts/gitstats /usr/bin
	$(CHMOD) 755 /usr/bin/gitstats
	([ -d /usr/share/gitstats/ ] && $(RMDIR) /usr/share/gitstats/) || true
	$(MKDIR) /usr/share/gitstats
	$(COPY) ./accessory/gitstats/* /usr/share/gitstats
	$(CHMOD) +r /usr/share/gitstats/*.gif

uninstall_gitstats :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Gitstats ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) /usr/bin/gitstats
	$(RMDIR) /usr/share/gitstats


install_programs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing /usr/bin Programs ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(COPY) $(addprefix $(BIN)/, $(LIST_UTIL_PROGRAMS)) $(addprefix $(BIN)/, $(LIST_MATH_PROGRAMS)) $(INSTALLBINDIR)/
	$(CHMOD) 755 $(addprefix $(INSTALLBINDIR)/, $(LIST_UTIL_PROGRAMS)) $(addprefix $(INSTALLBINDIR)/, $(LIST_MATH_PROGRAMS))
	# Install ManPages
	for page in $(addsuffix .1, $(LIST_UTIL_PROGRAMS)) $(addsuffix .1, $(LIST_MATH_PROGRAMS)); do if [ -f "$(MAN1DIR)/$${page}" ]; then gzip -9 -k "$(MAN1DIR)/$${page}"; $(MOVE) "$(MAN1DIR)/$${page}.gz" $(MANPAGEDIR)/man1/; else continue; fi; done

uninstall_programs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling /usr/bin Programs ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) $(addprefix $(INSTALLBINDIR)/, $(LIST_UTIL_PROGRAMS)) $(addprefix $(INSTALLBINDIR)/, $(LIST_MATH_PROGRAMS))
	# Uninstall ManPages
	for page in $(addsuffix .1.gz, $(LIST_UTIL_PROGRAMS)) $(addsuffix .1.gz, $(LIST_MATH_PROGRAMS)); do if [ -f "$(MANPAGEDIR)/man1/$${page}" ]; then $(RM) "$(MAN1DIR)/man1/$${page}"; else continue; fi; done

install_bin : install_programs

uninstall_bin : uninstall_programs

install_loginopticons :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing LoginOpticons ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(SYSTHEMEDIR)/LoginOpticons/ ] && $(RMDIR) $(SYSTHEMEDIR)/LoginOpticons/) || true
	$(CPDIR) $(THEMEDIR)/LoginOpticons $(SYSTHEMEDIR)/
	$(UPDATEICONCACHE) $(SYSTHEMEDIR)/LoginOpticons/
	$(UPDATEMIME) $(SYSMIMEDIR)

uninstall_loginopticons :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling LoginOpticons ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(SYSTHEMEDIR)/LoginOpticons/ ] && $(RMDIR) $(SYSTHEMEDIR)/LoginOpticons/) || true
	$(UPDATEMIME) $(SYSMIMEDIR)

install_mimetype_booster :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Mimetypes ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(COPY) $(ACCDIR)/mime.types /etc/mime.types
	([ -f $(SYSMIMEDIR)/packages/apt.xml ] && $(RM) $(SYSMIMEDIR)/packages/apt.xml) || true
	([ -f $(SYSMIMEDIR)/packages/audacity.xml ] && $(RM) $(SYSMIMEDIR)/packages/audacity.xml) || true
	([ -f $(SYSMIMEDIR)/packages/cmakecache.xml ] && $(RM) $(SYSMIMEDIR)/packages/cmakecache.xml) || true
	([ -f $(SYSMIMEDIR)/packages/docutils.xml ] && $(RM) $(SYSMIMEDIR)/packages/docutils.xml) || true
	([ -f $(SYSMIMEDIR)/packages/fontforge.xml ] && $(RM) $(SYSMIMEDIR)/packages/fontforge.xml) || true
	([ -f $(SYSMIMEDIR)/packages/freedesktop.org.xml ] && $(RM) $(SYSMIMEDIR)/packages/freedesktop.org.xml) || true
	([ -f $(SYSMIMEDIR)/packages/gcr-crypto-types.xml ] && $(RM) $(SYSMIMEDIR)/packages/gcr-crypto-types.xml) || true
	([ -f $(SYSMIMEDIR)/packages/genius.xml ] && $(RM) $(SYSMIMEDIR)/packages/genius.xml) || true
	([ -f $(SYSMIMEDIR)/packages/libreoffice.xml ] && $(RM) $(SYSMIMEDIR)/packages/libreoffice.xml) || true
	([ -f $(SYSMIMEDIR)/packages/meld.xml ] && $(RM) $(SYSMIMEDIR)/packages/meld.xml) || true
	([ -f $(SYSMIMEDIR)/packages/mysql-workbench.xml ] && $(RM) $(SYSMIMEDIR)/packages/mysql-workbench.xml) || true
	([ -f $(SYSMIMEDIR)/packages/ngraph.xml ] && $(RM) $(SYSMIMEDIR)/packages/ngraph.xml) || true
	([ -f $(SYSMIMEDIR)/packages/remmina-mime.xml ] && $(RM) $(SYSMIMEDIR)/packages/remmina-mime.xml) || true
	([ -f $(SYSMIMEDIR)/packages/scilab.xml ] && $(RM) $(SYSMIMEDIR)/packages/scilab.xml) || true
	([ -f $(SYSMIMEDIR)/packages/view3dscene.xml ] && $(RM) $(SYSMIMEDIR)/packages/view3dscene.xml) || true
	([ -f $(SYSMIMEDIR)/packages/vinagre-mime.xml ] && $(RM) $(SYSMIMEDIR)/packages/vinagre-mime.xml) || true
	([ -f $(SYSMIMEDIR)/packages/virtualbox.xml ] && $(RM) $(SYSMIMEDIR)/packages/virtualbox.xml) || true
	$(XDGMIME) install --mode system --novendor $(ACCDIR)/mimetype_booster.xml
	$(RM) /home/*/.local/share/applications/mimeinfo.cache
	$(RMDIR) /home/*/.thumbnails/ /home/*/.cache/thumbnails/
	$(UPDATEDESKTOP) $(SYSAPPDIR)
	$(UPDATEMIME) -V $(SYSMIMEDIR)

uninstall_mimetype_booster :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Mimetypes ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(XDGMIME) uninstall --mode system $(SYSMIMEDIR)/packages/mimetype_booster.xml
	$(UPDATEMIME) $(SYSMIMEDIR)

install_langspecs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Language Specifications ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(GTKLANGSPECS2DIR)/ ] && $(COPY) -t $(GTKLANGSPECS2DIR)/ $(addprefix $(LANGSPECSDIR)/, $(addsuffix .lang, $(LIST_LANGSPECS)))) || true
	([ -d $(GTKLANGSPECS3DIR)/ ] && $(COPY) -t $(GTKLANGSPECS3DIR)/ $(addprefix $(LANGSPECSDIR)/, $(addsuffix .lang, $(LIST_LANGSPECS)))) || true

uninstall_langspecs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Language Specifications ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(GTKLANGSPECS2DIR)/ ] && $(RM) $(addprefix $(GTKLANGSPECS2DIR)/, $(addsuffix .lang, $(LIST_LANGSPECS)))) || true
	([ -d $(GTKLANGSPECS3DIR)/ ] && $(RM) $(addprefix $(GTKLANGSPECS3DIR)/, $(addsuffix .lang, $(LIST_LANGSPECS)))) || true

install_nanorc :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing NanoRC ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(SYSNANORCDIR)/ ] && $(COPY) -t $(SYSNANORCDIR)/ $(NANORCDIR)/*.nanorc) || true

install_opticons :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Opticons ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(SYSTHEMEDIR)/Opticons/ ] && $(RMDIR) $(SYSTHEMEDIR)/Opticons/) || true
	$(CPDIR) $(THEMEDIR)/Opticons $(SYSTHEMEDIR)/
	[ -x "$(command -v update-alternatives)" ] && update-alternatives --install /etc/alternatives/start_icon start-here.svg $(SYSTHEMEDIR)/Opticons/places/start-here.svg 70
	$(UPDATEICONCACHE) $(SYSTHEMEDIR)/Opticons/
	$(UPDATEMIME) $(SYSMIMEDIR)

uninstall_opticons :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Opticons ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(SYSTHEMEDIR)/Opticons/ ] && $(RMDIR) $(SYSTHEMEDIR)/Opticons/ && $(UPDATEMIME) $(SYSMIMEDIR)) || true
	[ -x "$(command -v update-alternatives)" ] && update-alternatives --set start-here.svg /etc/alternatives/start-here.svg

install_optiview :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing OptiView ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	(cd "$(THEMEDIR)/OptiView" && sh ./install.sh) || true

uninstall_optiview :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling OptiView ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RMDIR) /usr/share/themes/OptiView /usr/share/themes/OptiView-Dark /usr/share/themes/OptiView-shell || true

install_optimal_cursors :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Optimal-Cursors ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ ! -d $(SYSTHEMEDIR)/Optimal-Cursors/ ] && [ -f $(THEMEDIR)/Optimal-Cursors/build.sh ] && cd $(THEMEDIR)/Optimal-Cursors && chmod +x ./build.sh && ./build.sh 'uninstall' && ./build.sh 'all' && ./build.sh 'install') || true
	cd "$(BASEDIR)"

uninstall_optimal_cursors :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Optimal-Cursors ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(SYSTHEMEDIR)/Optimal-Cursors/ ] && [ -f $(THEMEDIR)/Optimal-Cursors/build.sh ] && cd $(THEMEDIR)/Optimal-Cursors && chmod +x ./build.sh && ./build.sh 'uninstall') || true
	cd "$(BASEDIR)"

install_pyeggs : | rmtmp fixperm
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Python Eggs ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	(pip3 uninstall flake8_optimal) || true
	cd $(PYEGGDIR)/flake8_optimal/ || exit 1
	python3 ./setup.py install
	$(RMDIR) ./__pycache__/ ./build/ ./dist/ ./flake8_optimal.egg-info/ || true
	cd ../..

uninstall_pyeggs :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Python Eggs ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	command -v pip3 >&2 > /dev/null && pip3 uninstall flake8_optimal
	command -v pip3 >&2 > /dev/null || printf '%s\n' 'pip3: command not found!'

$(PYBDIR)/__init__.py : install_pylib

install_pylib : | rmtmp fixperm
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Python Libraries ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ -d $(PYBDIR)/ ] && $(RMDIR) $(PYBDIR)/) || true
	([ -d $(PYSRC)/__pycache__/ ] && $(RMDIR) $(PYSRC)/__pycache__/) || true
	([ -d $(PYSRC)/ezwin/__pycache__/ ] && $(RMDIR) $(PYSRC)/ezwin/__pycache__/) || true
	$(MKDIR) $(PYBDIR)
	$(CPDIR) $(PYSRC)/* $(PYBDIR)
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
	([ -d $(PYBDIR)/pybooster ] && $(RM) $(PYBDIR)/pybooster) || true

uninstall_pylib : uninstall_program_analyzer uninstall_scripts
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Python Libraries ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) $(INSTALLBINDIR)/ezdisplay $(INSTALLBINDIR)/ezwin
	$(RM) $(PYPATH)3.6/pybooster $(PYPATH)3.7/pybooster $(PYPATH)3.8/pybooster $(PYPATH)3.9/pybooster
	([ -d $(PYBDIR) ] && $(RMDIR) $(PYBDIR)) || true
	# Uninstall Documentation
	([ -d $(SYSDOCDIR)/pylib/ ] && $(RMDIR) $(SYSDOCDIR)/pylib/) || true

install_program_analyzer : | fixperm $(PYBDIR)/__init__.py
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Program Analyzer ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	([ ! -d $(INSTALLBINDIR)/ ] && $(MKDIRS) $(INSTALLBINDIR)/) || true
	$(COPY) $(SCRIPTSRCDIR)/program-analyzer $(INSTALLBINDIR)/
	$(COPY) $(MENUDIR)/Program-Analyzer.desktop $(SYSAPPDIR)/
	$(COPY) $(MENUDIR)/program-analyzer $(SYSMENUDIR)/
	$(COPY) $(THEMEDIR)/Opticons/apps/program-analyzer.svg $(PIXMAPDIR)/

uninstall_program_analyzer :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Program Analyzer ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) $(INSTALLBINDIR)/program-analyzer $(SYSAPPDIR)/Program-Analyzer.desktop $(SYSMENUDIR)/program-analyzer $(PIXMAPDIR)/program-analyzer.svg

install_scripts : $(PYBDIR)/__init__.py
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Scripts ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
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
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) $(addprefix $(INSTALLBINDIR)/, $(LIST_SCRIPT_PROGRAMS)) $(addprefix $(INSTALLBINDIR)/, $(LIST_DEV_SCRIPTS)) $(addprefix $(INSTALLBINDIR)/, $(LIST_PYTHON_SCRIPTS))
	$(RM) /usr/bin/pyflakes /usr/bin/pylint /usr/local/bin/pep8 /usr/local/bin/pycodestyle /usr/local/bin/pylint /usr/local/bin/pylint2
	# Uninstall ManPages
	for page in $(addsuffix .1.gz, $(LIST_SCRIPT_PROGRAMS)) $(addsuffix .1.gz, $(LIST_DEV_SCRIPTS)) $(addsuffix .1.gz, $(LIST_PYTHON_SCRIPTS)); do if [ -f "$(MANPAGEDIR)/man1/$${page}" ]; then $(RM) "$(MAN1DIR)/man1/$${page}"; else continue; fi; done

ifdef nogeo
    ifeq ($(nogeo),1)
        override geodeps::=disable_geofiles
    else ifeq ($(nogeo),0)
        override geodeps::=enable_geofiles install_geofiles
    else ifeq ($(nogeo),-1)
        override geodeps::=enable_geofiles
    else ifeq ($(nogeo),-2)
        override geodeps::=disable_geofiles install_geofiles
    else
        override geodeps::=enable_geofiles install_geofiles
    endif
else
    override geodeps::=enable_geofiles install_geofiles
endif

install_shrc : $(geodeps)
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Shell Profiles ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	# Backup existing files
	([ -f /etc/bash.bashrc.backup ] && $(RM) /etc/bash.bashrc.backup) || true
	([ -f /etc/bash.bashrc ] && $(MOVE) /etc/bash.bashrc /etc/bash.bashrc.backup) || true
	([ -f /etc/profile.backup ] && $(RM) /etc/profile.backup) || true
	([ -f /etc/profile ] && $(MOVE) /etc/profile /etc/profile.backup) || true
	# Add new files
	([ -x "$(command -v apt)" ] && [ ! -x "$(command -v apt-get)" ] && $(LNHARD) "$(command -v apt)" "$(command -v apt-get)") || true
	([ -x "$(command -v apt-get)" ] && [ ! -x "$(command -v apt)" ] && $(LNHARD) "$(command -v apt-get)" "$(command -v apt)") || true
	$(COPY) -t /etc/ $(SHRCDIR)/profile && $(CHMOD) 644 /etc/profile
	$(LNHARD) /etc/profile /etc/bash.bashrc
	([ ! -d $(INSTALLRCMODDIR) ] && $(MKDIRS) $(INSTALLRCMODDIR)) || true
	$(COPY) -t $(INSTALLRCMODDIR) $(addprefix $(SHRCDIR)/, $(LIST_RC_MODULES))

uninstall_shrc :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Shell Profiles ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(RM) /etc/bash.bashrc /etc/profile
	$(MOVE) /etc/bash.bashrc.backup /etc/bash.bashrc
	$(MOVE) /etc/profile.backup /etc/profile
	$(RMDIR) $(INSTALLRCMODDIR)

install_themes : install_loginopticons install_opticons

uninstall_themes : uninstall_loginopticons uninstall_opticons

install_uca :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing Thunar Custom Actions ==='
	if [ "$(UID)" == '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are NOT required!\n\n' >&2; exit 1; fi
	([ -n $(shell bash -c 'command -p -v thunar') ] && $(COPY) $(ACCDIR)/uca.xml ~/.config/Thunar/uca.xml) || true

uninstall_uca :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling Thunar Custom Actions ==='
	if [ "$(UID)" == '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are NOT required!\n\n' >&2; exit 1; fi
	$(RM) ~/.config/Thunar/uca.xml

install_xcompose :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing XCompose ==='
	if [ "$(UID)" == '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are NOT required!\n\n' >&2; exit 1; fi
	$(COPY) $(ACCDIR)/XCompose ~/.XCompose

uninstall_xcompose :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling XCompose ==='
	if [ "$(UID)" == '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are NOT required!\n\n' >&2; exit 1; fi
	$(RM) ~/.XCompose

install_xkb :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Installing XKB Keyboard Layouts ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(TOOLSDIR)/manage_usx.sh --install

uninstall_xkb :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Uninstalling XKB Keyboard Layouts ==='
	if [ "$(UID)" != '0' ]; then printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2; exit 1; fi
	$(TOOLSDIR)/manage_usx.sh --uninstall

# install_scripts calls install_pylib
install : | rmtmp fixperm install_clib install_programs install_mimetype_booster install_program_analyzer install_pyeggs install_scripts install_themes

# uninstall_pylib calls uninstall_scripts
uninstall : uninstall_clib uninstall_programs uninstall_mimetype_booster uninstall_program_analyzer uninstall_pyeggs uninstall_pylib uninstall_themes


# MATH PROGRAM RULES #


$(BIN)/acos : $(BIN) $(SRCDIR)/acos.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/acosh : $(BIN) $(SRCDIR)/acosh.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/asin : $(BIN) $(SRCDIR)/asin.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/asinh : $(BIN) $(SRCDIR)/asinh.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/atan : $(BIN) $(SRCDIR)/atan.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/atanh : $(BIN) $(SRCDIR)/atanh.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/cbrt : $(BIN) $(SRCDIR)/cbrt.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/cos : $(BIN) $(SRCDIR)/cos.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/cosh : $(BIN) $(SRCDIR)/cosh.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/factorial : $(BIN) $(SRCDIR)/factorial.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_M -DNO_PRINT_CHARS -DNO_PRINT_FLOATS -DNO_PRINT_INT128 -DNO_PRINT_WIDTH_PREC -DNO_PRINT_STRINGS -DNO_PRINT_M -DPRINTF_BUF64 -DDDISABLE_ANSI_SGR -DNO_CHAR_TABLES -DNO_SCAN_FLOATS -DDISABLE_MISC_HEADER -DDISABLE_NETWORK_HEADER -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/fib : $(BIN) $(SRCDIR)/fib.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF32 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/isprime : $(BIN) $(SRCDIR)/isprime.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF32 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/popcount : $(BIN) $(SRCDIR)/popcount.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_M -DNO_PRINT_CHARS -DNO_PRINT_FLOATS -DNO_PRINT_INT128 -DNO_PRINT_WIDTH_PREC -DNO_PRINT_STRINGS -DNO_PRINT_M -DPRINTF_BUF32 -DDDISABLE_ANSI_SGR -DNO_CHAR_TABLES -DNO_SCAN_FLOATS -DDISABLE_MISC_HEADER -DDISABLE_NETWORK_HEADER -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/sin : $(BIN) $(SRCDIR)/sin.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/sinh : $(BIN) $(SRCDIR)/sinh.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/sqrt : $(BIN) $(SRCDIR)/sqrt.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/tan : $(BIN) $(SRCDIR)/tan.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/tanh : $(BIN) $(SRCDIR)/tanh.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/unfactorial : $(BIN) $(SRCDIR)/unfactorial.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_M -DNO_PRINT_CHARS -DNO_PRINT_FLOATS -DNO_PRINT_INT128 -DNO_PRINT_WIDTH_PREC -DNO_PRINT_STRINGS -DNO_PRINT_M -DPRINTF_BUF32 -DDDISABLE_ANSI_SGR -DNO_CHAR_TABLES -DNO_SCAN_FLOATS -DDISABLE_MISC_HEADER -DDISABLE_NETWORK_HEADER -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@


# BUILD PREP #


$(BIN) :
	-@([ ! -d $(BIN)/ ] && $(MKDIR) $(BIN)) || true

$(TESTINGDIR) :
	-@([ ! -d $(TESTINGDIR)/ ] && $(MKDIR) $(TESTINGDIR)) || true


# UTILITY PROGRAM RULES #


$(BIN)/getpgid : $(BIN) $(SRCDIR)/getpgid.c $(MACROSPATH)
	$(CC) -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INT128 -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/getsid : $(BIN) $(SRCDIR)/getsid.c $(MACROSPATH)
	$(CC) -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INT128 -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/microtime : $(BIN) $(SRCDIR)/microtime.c $(MACROSPATH)
	$(CC) -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INT128 -DPRINTF_BUF64 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/number_properties : $(BIN) $(SRCDIR)/number_properties.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_M -DNO_PRINT_CHARS -DNO_PRINT_WIDTH_PREC -DNO_PRINT_INT128 -DNO_PRINT_STRINGS -DNO_PRINT_M -DPRINTF_BUF512 -DDDISABLE_ANSI_SGR -DNO_CHAR_TABLES -DNO_SCAN_FLOATS -DDISABLE_MISC_HEADER -DDISABLE_NETWORK_HEADER -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/ostype : $(BIN) $(SRCDIR)/ostype.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INTS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF32 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/statvfs : $(BIN) $(SRCDIR)/statvfs.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF512 -DNO_SCAN_FLOATS -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@

$(BIN)/typesize : $(BIN) $(SRCDIR)/typesize.c $(MACROSPATH)
	$(CC) -DNO_PRINT_ACTION -DNO_PRINT_CHARS -DNO_PRINT_M -DNO_PRINT_FLOATS -DNO_PRINT_INT128 -DNO_PRINT_STRING -DNO_PRINT_WIDTH_PREC -DPRINTF_BUF32 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@


# TEST PROGRAM RULES #


$(BIN)/test_dev : $(BIN) $(SRCDIR)/test_dev.c $(MACROSPATH)
	$(CC) -DPRINTF_BUF128 -DNO_PRINT_INT128 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(@F)\" $(MINEXE_PARAMS) $(SRCDIR)/$(@F).c -o $@ && $(STRIP) $@ && md5sum --tag $@ && sha1sum --tag $@ && sha512sum --tag $@ && b2sum --tag $@

$(TESTINGDIR)/test_dev.s : $(TESTINGDIR) $(SRCDIR)/test_dev.c $(MACROSPATH)
	$(CC) -DPRINTF_BUF128 -DNO_PRINT_INT128 -D__SINGLE_THREAD__ -DPROGRAM_NAME=\"$(*F)\" $(MINEXE_PARAMS) -S $(SRCDIR)/$(@F).c -o $@

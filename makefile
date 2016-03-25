#!/usr/bin/make -f
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8


ifdef DCJ
	override dcj::=$(DCJ)
endif
ifdef PROFILE
	override dcj::=$(PROFILE)
endif
include profiles.mk


## VARIABLES ##


override CLIB::=./clib
override SWIGLIB::=./swiglib
override SWIGLUA::=$(SWIGLIB)/lua
override SWIGOCTAVE::=$(SWIGLIB)/octave
override SWIGPERL::=$(SWIGLIB)/perl
override SWIGPHP::=$(SWIGLIB)/php
override SWIGPIKE::=$(SWIGLIB)/pike
override SWIGRUBY::=$(SWIGLIB)/ruby
override SWIGTCL::=$(SWIGLIB)/tcl
override PYMODDIR::=./pybooster
override SRCDIR::=./src
PYPATH::=/usr/lib/python
override PYCLIB::=/opt/pybooster/clib
override SYSPYCLIB::=/usr/lib/pyclib
override INCLUDE::=-D__MODULE_VERSION__=$(__MODULE_VERSION__) -I$(SRCDIR)
override COMMON_ARGUMENTS::=$(WARN) $(ARCH) $(BITS) $(STD) -O3 $(XOPTMZ) $(DEBUG) -funroll-loops
override COMMON_SWIG_ARGUMENTS::=$(ARCH) $(BITS) $(STD) -O3 $(XOPTMZ) -g0 -ggdb0 -s -Wl,-s -funroll-loops
override COMMON_PY_ARGUMENTS::=$(PYINCLUDE) $(PYCFLAGS) -D_FORTIFY_SOURCE=2 -fwrapv
override COMMON_POSIX_ARGUMENTS::=$(POSIX_STACK_PROTECTOR) -ffunction-sections -fdata-sections
SWIG::=swig3.0 -fcompact

ifndef STRIP
	override STRIP::=strip
endif

ifeq ($(OS),WIN)
	override FPIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ) -c $(FPIC)

	override SWIG_FPIC_PARAMS::=$(INCLUDE) $(COMMON_SWIG_ARGUMENTS) $(WINLIB) $(LDZ) -c $(FPIC)

	override LIB_PARAMS::=-L$(CLIB) -D__MODULE_VERSION__=$(__MODULE_VERSION__) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ)

	override SWIG_LIB_PARAMS::=-L$(CLIB) -D__MODULE_VERSION__=$(__MODULE_VERSION__) $(COMMON_SWIG_ARGUMENTS) $(WINLIB) $(LDZ)

	override STATIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ) -c $(FPIC)

	override PY_FPIC_PARAMS::=$(INCLUDE) $(COMMON_PY_ARGUMENTS) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ) -c $(FPIC)

	override PY_LIB_PARAMS::=-L$(CLIB) -D__MODULE_VERSION__=$(__MODULE_VERSION__) $(COMMON_ARGUMENTS) $(WINLIB) -Wl,-Bsymbolic-functions $(LDZ)
else
	override INCLUDE+= $(POSIX_INCLUDE)

	override FPIC_PARAMS::=$(INCLUDE) $(FLTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(FPIC)

	override SWIG_FPIC_PARAMS::=$(INCLUDE) $(FLTO) $(COMMON_SWIG_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(FPIC)

	override LIB_PARAMS::=-L$(CLIB) -D__MODULE_VERSION__=$(__MODULE_VERSION__) $(FLTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) -Wl,-no-whole-archive $(LDZ) -shared

	override SWIG_LIB_PARAMS::=-L$(CLIB) -D__MODULE_VERSION__=$(__MODULE_VERSION__) $(FLTO) $(COMMON_SWIG_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) -Wl,-no-whole-archive $(LDZ) -shared

	override STATIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(FPIC)

	override PY_FPIC_PARAMS::=$(INCLUDE) $(FLTO) $(COMMON_PY_ARGUMENTS) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(FPIC)

	override PY_LIB_PARAMS::=-L$(CLIB) -D__MODULE_VERSION__=$(__MODULE_VERSION__) $(FLTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) -Wl,-no-whole-archive -Wl,-Bsymbolic-functions $(LDZ) -shared
endif

CLANG_AST+= $(INCLUDE)
LLVM_BYTECODE+= $(INCLUDE)
LLVM_INTERMEDIATE+= $(INCLUDE)


## HELP ##


help:
	@echo ""
	@echo Version $(__MODULE_VERSION__)
	@echo ""
	@echo "* COMPILATION INSTRUCTIONS *"
	@echo ""
	@echo ""
	@echo "Everything except SWIG wrappers:"
	@echo "    make all"
	@echo "Everything except SWIG wrappers (using Clang):"
	@echo "    make all CLANG=3.7  # specify version"
	@echo "All libraries (except SWIG wrappers):"
	@echo "    make library"
	@echo "SWIG wrappers:"
	@echo "    make wrappers"
	@echo "SWIG wrappers for TCL:"
	@echo "    make tcl_wrappers"
	@echo "Dynamic libraries:"
	@echo "    make lib"
	@echo "Python C libraries:"
	@echo "    make pylibc"
	@echo "Static libraries:"
	@echo "    make static"
	@echo "MUSL Dynamic and Static libraries:"
	@echo "    make lib MUSL=1"
	@echo "Strip libraries:"
	@echo "    make strip"
	@echo "Clang AST:"
	@echo "    make ast"
	@echo "LLVM IR/Intermediate-Language (*.c/*.cpp => *.ll):"
	@echo "    make llvm_ll"
	@echo "LLVM Bytecode (*.c/*.cpp => *.bc):"
	@echo "    make llvm_bc"
	@echo "Backup:"
	@echo "    make backup"
	@echo "Package Release:"
	@echo "    make package"
	@echo "Create Zip Backup:"
	@echo "    make packagezip"
	@echo "Create 7z Backup:"
	@echo "    make package7z"
	@echo "Documentation:"
	@echo "    make doc"
	@echo ""
	@echo "Enable Pthread:"
	@echo "    make all PTHREAD=1"
	@echo ""
	@echo "Particular architechure:"
	@echo "    make all ARCH=intel"
	@echo "    make all ARCH=intel BITS=64"
	@echo "    make all ARCH=haswell"
	@echo "    make all ARCH=armv7"
	@echo ""
	@echo "Cross-Compile:"
	@echo "    make all CROSS_COMPILE=armhf"
	@echo "    make all CROSS_COMPILE=armel"
	@echo "    make all CROSS_COMPILE=x86-64"
	@echo "    make all CROSS_COMPILE=android"
	@echo "    make all CROSS_COMPILE=rpi"
	@echo "    NOTE: Windows may not be fully supported"
	@echo ""
	@echo ""
	@echo "* INSTALL/UNINSTALL *"
	@echo ""
	@echo ""
	@echo "Install:"
	@echo "    sudo make install"
	@echo "Uninstall:"
	@echo "    sudo make uninstall"
	@echo ""
	@echo ""
	@echo "* CLEAN *"
	@echo ""
	@echo ""
	@echo "Remove documentation:"
	@echo "    make cleandoc"
	@echo "Remove __pycache__:"
	@echo "    make rmcache"
	@echo "Remove temp files:"
	@echo "    make rmtmp"
	@echo "Remove temp files and __pycache__:"
	@echo "    make clean"
	@echo "Clean everything:"
	@echo "    make cleanall"
	@echo ""
	@echo ""
	@echo "* VARIABLES *"
	@echo ""
	@echo ""
	@echo "OS=string"
	@echo "    POSIX: Linux, Unix, BSD, etc."
	@echo "    ANDROID: Android"
	@echo ""


default:
	help


## PHONY ##


# General
.PHONY : all backup byte clean cleanall cleanfull ctags everything fixperm install lib library most package package7z packagezip py pybuild pyclibc pylibc rmcache rmtmp rmwrap static strip uninstall
# Documentation
.PHONY : cleandoc doc doxy
# Git
.PHONY : commit gitall stat submit
# Clang/LLVM
.PHONY : ast llvm_bc llvm_bytecode llvm_intermediate llvm_ll
# SWIG
.PHONY : lua_wrappers octave_wrappers perl_wrappers php_wrappers pike_wrappers ruby_wrappers tcl_wrappers wrappers


## BUILD COMMANDS ##


ifeq ($(OS),WIN)
all : lib

else ifdef ARCH_ARM
all : | static lib

else ifdef ARCH_I386
all : | static lib

else
all : byte | static lib pylibc

endif

ifneq ($(OS),WIN)
everything : py ast llvm_bytecode llvm_intermediate | static lib

else
everything :

endif

most : pylibc | static lib

llvm_bc : llvm_bytecode

llvm_ll : llvm_intermediate

lib : libcompression libcryptx libchron libfuzzy_logic libgeometry libmathconstants libmathfunc libphysics libtone libtools libtypesize libx86_64_asm_func | libextra_datatypes libchemistry_types libchemistry

static : static_libcompression static_libcryptx static_libchron static_libfuzzy_logic static_libgeometry static_libmathconstants static_libmathfunc static_libphysics static_libtone static_libtools static_libx86_64_asm_func static_libtypesize | static_libextra_datatypes static_libchemistry_types static_libchemistry

library : pylibc | static lib

ifeq ($(OS),WIN)
py :

else ifdef ARCH_ARM
py :

else ifdef ARCH_I386
py :

else
py : pylibc byte

endif

pybuild : pylibc byte

pylibc : pychemistry pygeometry pymathconstants pymathfunc pyphysics pytools pytypesize | static

pyclibc : pylibc

strip :
	-@$(STRIP) $(STRIP_PARAMS) $(CLIB)/*.so && $(STRIP) $(STRIP_PARAMS) $(PYMODDIR)/*.so


## SPECIAL COMMANDS ##


backup : rmtmp
	@cd ../; tar -cf - PyBooster | gzip -9 > ./PyBooster.tar.gz; cd ./PyBooster

package : rmtmp
	@cd ../; tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`.tar.gz; cd ./PyBooster

package7z : rmtmp
	@cd ../; 7za a ./PyBooster_v`date +"%Y.%m.%d"`.7z PyBooster; cd ./PyBooster

packagezip : rmtmp
	@cd ../; zip -r ./PyBooster_v`date +"%Y.%m.%d"`.zip PyBooster; cd ./PyBooster

ctags : cleanall
	-@geany -P -g ./tools/PyBooster.c.tags $(SRCDIR)/*

doc : cleandoc rmwrap
	-@./makedoc.sh

doxy : rmwrap
	-@doxywizard ./Doxyfile; chmod --quiet 644 ./Doxyfile

rmtmp :
	-@rm -f $(SRCDIR)/*.o $(SRCDIR)/*.s $(SRCDIR)/*.bc $(SRCDIR)/*.ll $(SRCDIR)/*.ast $(SRCDIR)/*.i  $(SRCDIR)/*.ii $(SRCDIR)/*.pch $(SRCDIR)/*_wrap.c; rm -frd --one-file-system $(SRCDIR)/build/

rmcache :
	-@rm -frd --one-file-system $(PYMODDIR)/__pycache__/; rm -frd --one-file-system $(PYMODDIR)/ezwin/__pycache__/

rmwrap :
	-@rm -f $(SRCDIR)/*_wrap.c

clean : rmtmp rmcache

cleandoc :
	-@rm -frd ./doc/*

cleanall : rmtmp rmcache
	-@rm -f $(PYMODDIR)/*.so $(SWIGLIB)/*.so $(SWIGTCL)/*.so $(SWIGLIB)/*.dll $(SWIGTCL)/*.dll $(SWIGOCTAVE)/*.oct $(SWIGPERL)/*.pm $(SWIGPERL)/*.so $(SWIGPERL)/*.dll $(SWIGPHP)/*.php $(SWIGPHP)/*.so $(SWIGPHP)/*.dll $(SWIGPIKE)/*.so $(SWIGPIKE)/*.dll $(SWIGRUBY)/*.so $(SWIGRUBY)/*.dll $(SWIGLUA)/*.so $(SWIGLUA)/*.dll $(CLIB)/*.so $(PYMODDIR)/*.dll $(CLIB)/*.dll $(CLIB)/*.a

cleanfull : cleanall cleandoc

uninstall :
	rm -frd --one-file-system /opt/pybooster/*; rm -f /opt/bin/ezwin; rm -f /usr/lib/python$(PYVERSION)/pybooster $(SYSPYCLIB); rm -f /etc/ld.so.conf.d/pyclib.conf; ldconfig

install : rmtmp
	@echo "Beginning Installation (PyBooster)"; \
	# Prepare installation directory \
	rm -frd --one-file-system /opt/pybooster/*; \
	mkdir -p /opt/pybooster/clib /opt/pybooster/include; \
	mkdir -p /opt/pybooster/doc /opt/pybooster/ezwin; \
	mkdir -p /opt/pybooster/lua /opt/pybooster/ruby /opt/pybooster/tcl /opt/pybooster/octave; \
	mkdir -p /opt/pybooster/perl /opt/pybooster/php /opt/pybooster/pike; \
	# Copy files to installation directory \
	cp -Rf ./doc/* /opt/pybooster/doc; \
	cp -Rf $(PYMODDIR)/* /opt/pybooster/; \
	cp -Rf $(CLIB)/* /opt/pybooster/clib/; \
	cp -Rf $(SRCDIR)/*.h /opt/pybooster/include/; \
	cp $(SWIGLUA)/* /opt/pybooster/lua/ || true; \
	cp $(SWIGRUBY)/* /opt/pybooster/ruby/ || true; \
	cp $(SWIGTCL)/* /opt/pybooster/tcl/ || true; \
	cp $(SWIGOCTAVE)/* /opt/pybooster/octave/ || true; \
	cp $(SWIGPERL)/* /opt/pybooster/perl/ || true; \
	cp $(SWIGPHP)/* /opt/pybooster/php/ || true; \
	cp $(SWIGPIKE)/* /opt/pybooster/pike/ || true; \
	# Ensure that the proper permissions are set \
	$(CHMOD) 644 /opt/pybooster/doc/*; \
	$(CHMOD) 755 /opt/pybooster/doc/html; \
	$(CHMOD) 644 /opt/pybooster/doc/html/*; \
	$(CHMOD) 755 /opt/pybooster/doc/html/search; \
	$(CHMOD) 644 /opt/pybooster/doc/html/search/*; \
	$(CHMOD) 644 /opt/pybooster/*.py /opt/pybooster/*.glade; \
	$(CHMOD) 755 /opt/pybooster/*.so /opt/pybooster/*.dll; \
	$(CHMOD) 755 /opt/pybooster/tcl/*.so /opt/pybooster/tcl/*.dll || true; \
	$(CHMOD) 755 /opt/pybooster/octave/*.oct || true; \
	$(CHMOD) 755 /opt/pybooster/perl/*.pm /opt/pybooster/perl/*.so /opt/pybooster/perl/*.dll || true; \
	$(CHMOD) 755 /opt/pybooster/php/*.php /opt/pybooster/php/*.so /opt/pybooster/php/*.dll || true; \
	$(CHMOD) 755 /opt/pybooster/pike/*.so /opt/pybooster/pike/*.dll || true; \
	$(CHMOD) 755 /opt/pybooster/clib/*; \
	$(CHMOD) 644 /opt/pybooster/include/*; \
	$(CHMOD) 644 /opt/pybooster/__pycache__/* /opt/pybooster/ezwin/__pycache__/*; \
	$(CHMOD) 755 /opt/pybooster/ezwin/*.py; \
	$(CHMOD) 644 /opt/pybooster/ezwin/*.glade; \
	# Make a link to ezwin.py in /opt/bin/ \
	ln -fs -T /opt/pybooster/ezwin/ezwin.py /opt/bin/ezwin; \
	# Make Pybooster accessible to Python3 \
	ln -fs -T /opt/pybooster $(PYPATH)$(PYVERSION)/pybooster; \
	# Add PyCLib library \
	ln -fs -T $(PYCLIB) $(SYSPYCLIB); \
	sh -c "echo '$(SYSPYCLIB)' > /etc/ld.so.conf.d/pyclib.conf"; \
	ldconfig; \
	# END \
	echo ""; echo "Installation Complete!"; \

fixperm : rmtmp
	-@$(CHMOD) 644 ./doc/*.txt; \
	$(CHMOD) 755 ./doc/html; \
	$(CHMOD) 644 ./doc/html/*; \
	$(CHMOD) 755 ./doc/html/search; \
	$(CHMOD) 644 ./doc/html/search/*; \
	$(CHMOD) 644 $(SRCDIR)/*; \
	$(CHMOD) 644 $(PYMODDIR)/*.py $(PYMODDIR)/*.pyw $(PYMODDIR)/*.glade; \
	$(CHMOD) 755 $(PYMODDIR)/*.so $(CLIB)/*.so $(CLIB)/*.dll; \
	$(CHMOD) 755 $(SWIGLIB)/*.so $(SWIGTCL)/*.so $(SWIGLIB)/*.dll $(SWIGTCL)/*.dll; \
	$(CHMOD) 755 $(SWIGOCTAVE)/*.oct; \
	$(CHMOD) 755 $(SWIGPERL)/*.pm $(SWIGPERL)/*.so $(SWIGPERL)/*.dll; \
	$(CHMOD) 755 $(SWIGPHP)/*.php $(SWIGPHP)/*.so $(SWIGPHP)/*.dll; \
	$(CHMOD) 755 $(SWIGPIKE)/*.so $(SWIGPIKE)/*.dll; \
	$(CHMOD) 755 $(SWIGLUA)/*.so $(SWIGLUA)/*.dll; \
	$(CHMOD) 755 $(SWIGRUBY)/*.so $(SWIGRUBY)/*.dll; \
	$(CHMOD) 644 $(PYMODDIR)/__pycache__/* $(PYMODDIR)/ezwin/__pycache__/*; \
	$(CHMOD) 644 $(PYMODDIR)/ezwin/*.py $(PYMODDIR)/ezwin/*.glade; \


## GIT COMMANDS ##


gitall : cleanall
	-@git add -A

commit : | cleanall fixperm
	-@git commit -m "$(M)"

stat : cleanall
	-@git status -s

submit :
	git push origin master


## RULES ##


# SWIG #

wrappers : lua_wrappers pike_wrappers ruby_wrappers tcl_wrappers

lua_wrappers : lua_swig_mathconstants lua_swig_mathfunc

octave_wrappers : octave_swig_mathconstants octave_swig_mathfunc

perl_wrappers : perl_swig_mathfunc

php_wrappers : php_swig_mathfunc

pike_wrappers : pike_swig_mathconstants pike_swig_mathfunc

ruby_wrappers : ruby_swig_mathconstants ruby_swig_mathfunc

tcl_wrappers : tcl_swig_mathconstants tcl_swig_mathfunc

lua_swig_mathconstants :
	$(SWIG) -lua -o $(SRCDIR)/mathconstants_lua_wrap.c $(SRCDIR)/mathconstants.swg && $(CC) $(SWIG_FPIC_PARAMS) -I/usr/include/lua5.2 $(SRCDIR)/mathconstants_lua_wrap.c -o $(SRCDIR)/mathconstants_lua_wrap.o && $(CC) $(SWIG_LIB_PARAMS) -o $(SWIGLUA)/mathconstants.so $(SRCDIR)/mathconstants_lua_wrap.o -llua5.2 && $(STRIP) $(STRIP_PARAMS) $(SWIGLUA)/mathconstants.so

lua_swig_mathfunc : libmathfunc
	$(SWIG) -lua -o $(SRCDIR)/mathfunc_lua_wrap.c $(SRCDIR)/mathfunc.swg && $(CC) $(SWIG_FPIC_PARAMS) -I/usr/include/lua5.2 $(SRCDIR)/mathfunc_lua_wrap.c -o $(SRCDIR)/mathfunc_lua_wrap.o && $(CC) $(SWIG_LIB_PARAMS) -o $(SWIGLUA)/mathfunc.so $(SRCDIR)/mathfunc.o $(SRCDIR)/mathfunc_lua_wrap.o -llua5.2 -lm && $(STRIP) $(STRIP_PARAMS) $(SWIGLUA)/mathfunc.so

octave_swig_mathconstants :
	export CC="g++ -std=c++11"; $(SWIG) -octave -o $(SRCDIR)/mathconstants_octave_wrap.c $(SRCDIR)/mathconstants.swg && mkoctfile -I/usr/include -I/usr/include/octave-4.0.0 -s -Wl,-s -Wa,-std=c++11,-O3,-g0,-ggdb0,-funroll-loops $(SRCDIR)/mathconstants_octave_wrap.c -o $(SWIGOCTAVE)/mathconstants.oct

octave_swig_mathfunc : libmathfunc
	export CC="g++ -std=c++11"; $(SWIG) -octave -o $(SRCDIR)/mathfunc_octave_wrap.c $(SRCDIR)/mathfunc.swg && mkoctfile -I/usr/include -I/usr/include/octave-4.0.0 -s -Wl,-s -Wa,-std=c++11,-O3,-g0,-ggdb0,-funroll-loops -lm $(SRCDIR)/mathfunc_octave_wrap.c $(SRCDIR)/mathfunc.o -o $(SWIGOCTAVE)/mathfunc.oct

perl_swig_mathfunc : libmathfunc
	$(SWIG) -perl -o $(SRCDIR)/mathfunc_perl_wrap.c $(SRCDIR)/mathfunc.swg && mv $(SRCDIR)/mathfunc.pm $(SWIGPERL)/mathfunc.pm && $(CC) $(SWIG_FPIC_PARAMS) -I/usr/include/perl $(SRCDIR)/mathfunc_perl_wrap.c -o $(SRCDIR)/mathfunc_perl_wrap.o && $(CC) $(SWIG_LIB_PARAMS) -o $(SWIGPERL)/mathfunc.so $(SRCDIR)/mathfunc.o $(SRCDIR)/mathfunc_perl_wrap.o -lperl -lm && $(STRIP) $(STRIP_PARAMS) $(SWIGPERL)/mathfunc.so

php_swig_mathfunc : libmathfunc
	$(SWIG) -php -o $(SRCDIR)/mathfunc_php_wrap.c $(SRCDIR)/mathfunc.swg && mv $(SRCDIR)/mathfunc.php $(SWIGPHP)/mathfunc.php && $(CC) $(SWIG_FPIC_PARAMS) `php-config --includes` $(SRCDIR)/mathfunc_php_wrap.c -o $(SRCDIR)/mathfunc_php_wrap.o && $(CC) $(SWIG_LIB_PARAMS) -o $(SWIGPHP)/mathfunc.so $(SRCDIR)/mathfunc.o $(SRCDIR)/mathfunc_php_wrap.o -lphp -lm && $(STRIP) $(STRIP_PARAMS) $(SWIGPHP)/mathfunc.so

pike_swig_mathconstants :
	$(SWIG) -pike -o $(SRCDIR)/mathconstants_pike_wrap.c $(SRCDIR)/mathconstants.swg && $(CC) $(SWIG_FPIC_PARAMS) -I/usr/include/pike7.8 $(SRCDIR)/mathconstants_pike_wrap.c -o $(SRCDIR)/mathconstants_pike_wrap.o && $(CC) $(SWIG_LIB_PARAMS) -o $(SWIGPIKE)/mathconstants.so $(SRCDIR)/mathconstants_pike_wrap.o && $(STRIP) $(STRIP_PARAMS) $(SWIGPIKE)/mathconstants.so

pike_swig_mathfunc : libmathfunc
	$(SWIG) -pike -o $(SRCDIR)/mathfunc_pike_wrap.c $(SRCDIR)/mathfunc.swg && $(CC) $(SWIG_FPIC_PARAMS) -I/usr/include/pike7.8 $(SRCDIR)/mathfunc_pike_wrap.c -o $(SRCDIR)/mathfunc_pike_wrap.o && $(CC) $(SWIG_LIB_PARAMS) -o $(SWIGPIKE)/mathfunc.so $(SRCDIR)/mathfunc.o $(SRCDIR)/mathfunc_pike_wrap.o -lm && $(STRIP) $(STRIP_PARAMS) $(SWIGPIKE)/mathfunc.so

ruby_swig_mathconstants :
	$(SWIG) -ruby -o $(SRCDIR)/mathconstants_ruby_wrap.c $(SRCDIR)/mathconstants.swg && $(CC) $(SWIG_FPIC_PARAMS) -I/usr/include/ruby-2.1.0 -I/usr/include/$(GCC_PREFIX)/ruby-2.1.0 $(SRCDIR)/mathconstants_ruby_wrap.c -o $(SRCDIR)/mathconstants_ruby_wrap.o && $(CC) $(SWIG_LIB_PARAMS) -L/usr/lib/$(GCC_PREFIX) -o $(SWIGRUBY)/mathconstants.so $(SRCDIR)/mathconstants_ruby_wrap.o -lruby-2.1 && $(STRIP) $(STRIP_PARAMS) $(SWIGRUBY)/mathconstants.so

ruby_swig_mathfunc : libmathfunc
	$(SWIG) -ruby -o $(SRCDIR)/mathfunc_ruby_wrap.c $(SRCDIR)/mathfunc.swg && $(CC) $(SWIG_FPIC_PARAMS) -I/usr/include/ruby-2.1.0 -I/usr/include/$(GCC_PREFIX)/ruby-2.1.0 $(SRCDIR)/mathfunc_ruby_wrap.c -o $(SRCDIR)/mathfunc_ruby_wrap.o && $(CC) $(SWIG_LIB_PARAMS) -L/usr/lib/$(GCC_PREFIX) -o $(SWIGRUBY)/mathfunc.so $(SRCDIR)/mathfunc.o $(SRCDIR)/mathfunc_ruby_wrap.o -lruby-2.1 -lm && $(STRIP) $(STRIP_PARAMS) $(SWIGRUBY)/mathfunc.so

tcl_swig_mathconstants :
	$(SWIG) -tcl -o $(SRCDIR)/mathconstants_tcl_wrap.c $(SRCDIR)/mathconstants.swg && $(CC) $(SWIG_FPIC_PARAMS) -I/usr/include/tcl $(SRCDIR)/mathconstants_tcl_wrap.c -o $(SRCDIR)/mathconstants_tcl_wrap.o && $(CC) $(SWIG_LIB_PARAMS) -o $(SWIGTCL)/mathconstants.so $(SRCDIR)/mathconstants_tcl_wrap.o -ltcl && $(STRIP) $(STRIP_PARAMS) $(SWIGTCL)/mathconstants.so

tcl_swig_mathfunc : libmathfunc
	$(SWIG) -tcl -o $(SRCDIR)/mathfunc_tcl_wrap.c $(SRCDIR)/mathfunc.swg && $(CC) $(SWIG_FPIC_PARAMS) -I/usr/include/tcl $(SRCDIR)/mathfunc_tcl_wrap.c -o $(SRCDIR)/mathfunc_tcl_wrap.o && $(CC) $(SWIG_LIB_PARAMS) -o $(SWIGTCL)/mathfunc.so $(SRCDIR)/mathfunc.o $(SRCDIR)/mathfunc_tcl_wrap.o -ltcl -lm && $(STRIP) $(STRIP_PARAMS) $(SWIGTCL)/mathfunc.so


# LLVM/Clang #

ast :
	-$(CLANG_AST) $(SRCDIR)/chemistry.c -o $(SRCDIR)/chemistry.ast; $(CLANG_AST) $(SRCDIR)/chemistry_types.c -o $(SRCDIR)/chemistry_types.ast; $(CLANG_AST) $(SRCDIR)/compression.c -o $(SRCDIR)/compression.ast; $(CLANG_AST) $(SRCDIR)/cryptx.c -o $(SRCDIR)/cryptx.ast; $(CLANG_AST) $(SRCDIR)/chron.c -o $(SRCDIR)/chron.ast; $(CLANG_AST) $(SRCDIR)/extra_datatypes.c -o $(SRCDIR)/extra_datatypes.ast; $(CLANG_AST) $(SRCDIR)/fuzzy_logic.c -o $(SRCDIR)/fuzzy_logic.ast; $(CLANG_AST) $(SRCDIR)/geometry.c -o $(SRCDIR)/geometry.ast; $(CLANG_AST) $(SRCDIR)/mathconstants.c -o $(SRCDIR)/mathconstants.ast; $(CLANG_AST) $(SRCDIR)/mathfunc.c -o $(SRCDIR)/mathfunc.ast; $(CLANG_AST) $(SRCDIR)/physics.c -o $(SRCDIR)/physics.ast; $(CLANG_AST) $(SRCDIR)/tone.c -o $(SRCDIR)/tone.ast; $(CLANG_AST) $(SRCDIR)/tools.c -o $(SRCDIR)/tools.ast; $(CLANG_AST) $(SRCDIR)/typesize.c -o $(SRCDIR)/typesize.ast

llvm_bytecode :
	-$(LLVM_BYTECODE) $(SRCDIR)/chemistry.c -o $(SRCDIR)/chemistry.bc; $(LLVM_BYTECODE) $(SRCDIR)/chemistry_types.c -o $(SRCDIR)/chemistry_types.bc; $(LLVM_BYTECODE) $(SRCDIR)/compression.c -o $(SRCDIR)/compression.bc; $(LLVM_BYTECODE) $(SRCDIR)/cryptx.c -o $(SRCDIR)/cryptx.bc; $(LLVM_BYTECODE) $(SRCDIR)/chron.c -o $(SRCDIR)/chron.bc; $(LLVM_BYTECODE) $(SRCDIR)/extra_datatypes.c -o $(SRCDIR)/extra_datatypes.bc; $(LLVM_BYTECODE) $(SRCDIR)/fuzzy_logic.c -o $(SRCDIR)/fuzzy_logic.bc; $(LLVM_BYTECODE) $(SRCDIR)/geometry.c -o $(SRCDIR)/geometry.bc; $(LLVM_BYTECODE) $(SRCDIR)/mathconstants.c -o $(SRCDIR)/mathconstants.bc; $(LLVM_BYTECODE) $(SRCDIR)/mathfunc.c -o $(SRCDIR)/mathfunc.bc; $(LLVM_BYTECODE) $(SRCDIR)/physics.c -o $(SRCDIR)/physics.bc; $(LLVM_BYTECODE) $(SRCDIR)/tone.c -o $(SRCDIR)/tone.bc; $(LLVM_BYTECODE) $(SRCDIR)/tools.c -o $(SRCDIR)/tools.bc; $(LLVM_BYTECODE) $(SRCDIR)/typesize.c -o $(SRCDIR)/typesize.bc

llvm_intermediate :
	-$(LLVM_INTERMEDIATE) $(SRCDIR)/chemistry.c -o $(SRCDIR)/chemistry.ll; $(LLVM_INTERMEDIATE) $(SRCDIR)/chemistry_types.c -o $(SRCDIR)/chemistry_types.ll; $(LLVM_INTERMEDIATE) $(SRCDIR)/compression.c -o $(SRCDIR)/compression.ll; $(LLVM_INTERMEDIATE) $(SRCDIR)/cryptx.c -o $(SRCDIR)/cryptx.ll; $(LLVM_INTERMEDIATE) $(SRCDIR)/chron.c -o $(SRCDIR)/chron.ll; $(LLVM_INTERMEDIATE) $(SRCDIR)/extra_datatypes.c -o $(SRCDIR)/extra_datatypes.ll; $(LLVM_INTERMEDIATE) $(SRCDIR)/fuzzy_logic.c -o $(SRCDIR)/fuzzy_logic.ll; $(LLVM_INTERMEDIATE) $(SRCDIR)/geometry.c -o $(SRCDIR)/geometry.ll; $(LLVM_INTERMEDIATE) $(SRCDIR)/mathconstants.c -o $(SRCDIR)/mathconstants.ll; $(LLVM_INTERMEDIATE) $(SRCDIR)/mathfunc.c -o $(SRCDIR)/mathfunc.ll; $(LLVM_INTERMEDIATE) $(SRCDIR)/physics.c -o $(SRCDIR)/physics.ll; $(LLVM_INTERMEDIATE) $(SRCDIR)/tone.c -o $(SRCDIR)/tone.ll; $(LLVM_INTERMEDIATE) $(SRCDIR)/tools.c -o $(SRCDIR)/tools.ll; $(LLVM_INTERMEDIATE) $(SRCDIR)/typesize.c -o $(SRCDIR)/typesize.ll


# Library Compiling #

# To dynamically link, use "-lm"
libchemistry : | libchemistry_types
	$(CC) $(FPIC_PARAMS) $(SRCDIR)/chemistry.c -o $(SRCDIR)/chemistry.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libchemistry.$(LIBEXT) $(SRCDIR)/chemistry.o $(SRCDIR)/chemistry_types.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libchemistry.$(LIBEXT)


libchemistry_types :
	$(CC) $(FPIC_PARAMS) $(SRCDIR)/chemistry_types.c -o $(SRCDIR)/chemistry_types.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libchemistry_types.$(LIBEXT) $(SRCDIR)/chemistry_types.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libchemistry_types.$(LIBEXT)


libchron :
	$(CC) $(FPIC_PARAMS) $(SRCDIR)/chron.c -o $(SRCDIR)/chron.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libchron.$(LIBEXT) $(SRCDIR)/chron.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libchron.$(LIBEXT)


ifdef MUSL
libcompression :

else ifdef ARCH_ARM
libcompression :

else ifeq ($(OS),POSIX)
libcompression :
	-$(CC) $(FPIC_PARAMS) $(SRCDIR)/compression.c -o $(SRCDIR)/compression.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libcompression.$(LIBEXT) $(SRCDIR)/compression.o -Wl,-Bstatic -Wl,-Bdynamic -lz && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libcompression.$(LIBEXT)

else
libcompression :

endif


libcryptx :
	$(CC) $(FPIC_PARAMS) $(SRCDIR)/cryptx.c -o $(SRCDIR)/cryptx.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libcryptx.$(LIBEXT) $(SRCDIR)/cryptx.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libcryptx.$(LIBEXT)


libextra_datatypes :
	$(CC) $(FPIC_PARAMS) $(SRCDIR)/extra_datatypes.c -o $(SRCDIR)/extra_datatypes.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libextra_datatypes.$(LIBEXT) $(SRCDIR)/extra_datatypes.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libextra_datatypes.$(LIBEXT)


libfuzzy_logic :
	$(CC) $(FPIC_PARAMS) $(SRCDIR)/fuzzy_logic.c -o $(SRCDIR)/fuzzy_logic.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libfuzzy_logic.$(LIBEXT) $(SRCDIR)/fuzzy_logic.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libfuzzy_logic.$(LIBEXT)


libgeometry :
	$(CC) $(FPIC_PARAMS) $(SRCDIR)/geometry.c -o $(SRCDIR)/geometry.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libgeometry.$(LIBEXT) $(SRCDIR)/geometry.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libgeometry.$(LIBEXT)


libmathconstants :
	$(CC) $(FPIC_PARAMS) $(SRCDIR)/mathconstants.c -o $(SRCDIR)/mathconstants.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libmathconstants.$(LIBEXT) $(SRCDIR)/mathconstants.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libmathconstants.$(LIBEXT)


# To dynamically link, use "-lm"
libmathfunc :
	$(CC) $(FPIC_PARAMS) $(SRCDIR)/mathfunc.c -o $(SRCDIR)/mathfunc.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libmathfunc.$(LIBEXT) $(SRCDIR)/mathfunc.o -lm && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libmathfunc.$(LIBEXT)


libphysics :
	$(CC) $(FPIC_PARAMS) $(SRCDIR)/physics.c -o $(SRCDIR)/physics.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libphysics.$(LIBEXT) $(SRCDIR)/physics.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libphysics.$(LIBEXT)


ifdef MUSL
libtone :

else ifeq ($(OS),POSIX)
# To dynamically link, use "-ltone -lao -ldl -lm"
libtone :
	-$(CC) $(FPIC_PARAMS) $(SRCDIR)/tone.c -o $(SRCDIR)/tone.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libtone.$(LIBEXT) $(SRCDIR)/tone.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libtone.$(LIBEXT)
else
libtone :

endif


libtools :
	$(CC) $(FPIC_PARAMS) $(SRCDIR)/tools.c -o $(SRCDIR)/tools.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libtools.$(LIBEXT) $(SRCDIR)/tools.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libtools.$(LIBEXT)


libtypesize :
	$(CC) $(FPIC_PARAMS) $(SRCDIR)/typesize.c -o $(SRCDIR)/typesize.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libtypesize.$(LIBEXT) $(SRCDIR)/typesize.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libtypesize.$(LIBEXT)


libx86_64_asm_func :
	$(CC) $(FPIC_PARAMS) $(SRCDIR)/x86_64_asm_func.c -o $(SRCDIR)/x86_64_asm_func.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libx86_64_asm_func.$(LIBEXT) $(SRCDIR)/x86_64_asm_func.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libx86_64_asm_func.$(LIBEXT)


# Static Library Compiling #

# To statically link, use "-Wl,-Bdynamic -lm"
static_libchemistry : | static_libchemistry_types
	$(CC) $(STATIC_PARAMS) $(SRCDIR)/chemistry.c -o $(SRCDIR)/chemistry.o && ar rcs -o $(CLIB)/libchemistry.a $(SRCDIR)/chemistry.o $(CLIB)/libchemistry_types.a


static_libchemistry_types :
	$(CC) $(STATIC_PARAMS) $(SRCDIR)/chemistry_types.c -o $(SRCDIR)/chemistry_types.o && ar rcs -o $(CLIB)/libchemistry_types.a $(SRCDIR)/chemistry_types.o


static_libchron :
	$(CC) $(STATIC_PARAMS) $(SRCDIR)/chron.c -o $(SRCDIR)/chron.o && ar rcs -o $(CLIB)/libchron.a $(SRCDIR)/chron.o


ifdef MUSL
static_libcompression :

else ifdef ARCH_ARM
static_libcompression :

else ifeq ($(OS),POSIX)
# To statically link, use "-Wl,-Bstatic -lz -Wl,-Bdynamic"
static_libcompression :
	-$(CC) $(STATIC_PARAMS) $(SRCDIR)/compression.c -o $(SRCDIR)/compression.o && ar rcs -o $(CLIB)/libcompression.a $(SRCDIR)/compression.o

else
static_libcompression :

endif


static_libcryptx :
	$(CC) $(STATIC_PARAMS) $(SRCDIR)/cryptx.c -o $(SRCDIR)/cryptx.o && ar rcs -o $(CLIB)/libcryptx.a $(SRCDIR)/cryptx.o


static_libextra_datatypes :
	$(CC) $(STATIC_PARAMS) $(SRCDIR)/extra_datatypes.c -o $(SRCDIR)/extra_datatypes.o && ar rcs -o $(CLIB)/libextra_datatypes.a $(SRCDIR)/extra_datatypes.o


static_libfuzzy_logic :
	$(CC) $(STATIC_PARAMS) $(SRCDIR)/fuzzy_logic.c -o $(SRCDIR)/fuzzy_logic.o && ar rcs -o $(CLIB)/libfuzzy_logic.a $(SRCDIR)/fuzzy_logic.o


static_libgeometry :
	$(CC) $(STATIC_PARAMS) $(SRCDIR)/geometry.c -o $(SRCDIR)/geometry.o && ar rcs -o $(CLIB)/libgeometry.a $(SRCDIR)/geometry.o


static_libmathconstants :
	$(CC) $(STATIC_PARAMS) $(SRCDIR)/mathconstants.c -o $(SRCDIR)/mathconstants.o && ar rcs -o $(CLIB)/libmathconstants.a $(SRCDIR)/mathconstants.o


# To statically link, use "-Wl,-Bdynamic -lm"
static_libmathfunc :
	$(CC) $(STATIC_PARAMS) $(SRCDIR)/mathfunc.c -o $(SRCDIR)/mathfunc.o && ar rcs -o $(CLIB)/libmathfunc.a $(SRCDIR)/mathfunc.o


static_libphysics :
	$(CC) $(STATIC_PARAMS) $(SRCDIR)/physics.c -o $(SRCDIR)/physics.o && ar rcs -o $(CLIB)/libphysics.a $(SRCDIR)/physics.o


ifdef MUSL
static_libtone :

else ifeq ($(OS),POSIX)
# To statically link, use "-Wl,-Bstatic -ltone -lao -Wl,-Bdynamic -ldl -lm"
static_libtone :
	-$(CC) $(STATIC_PARAMS) $(SRCDIR)/tone.c -o $(SRCDIR)/tone.o && ar rcs -o $(CLIB)/libtone.a $(SRCDIR)/tone.o

else
static_libtone :

endif


static_libtools :
	$(CC) $(STATIC_PARAMS) $(SRCDIR)/tools.c -o $(SRCDIR)/tools.o && ar rcs -o $(CLIB)/libtools.a $(SRCDIR)/tools.o


static_libtypesize :
	$(CC) $(STATIC_PARAMS) $(SRCDIR)/typesize.c -o $(SRCDIR)/typesize.o && ar rcs -o $(CLIB)/libtypesize.a $(SRCDIR)/typesize.o


static_libx86_64_asm_func :
	$(CC) $(STATIC_PARAMS) $(SRCDIR)/x86_64_asm_func.c -o $(SRCDIR)/x86_64_asm_func.o && ar rcs -o $(CLIB)/libx86_64_asm_func.a $(SRCDIR)/x86_64_asm_func.o


# Python Byte Compiling #

byte :
	-export PYTHONOPTIMIZE="2"; python$(PYVERSION) -m compileall -q -f $(PYMODDIR)/


# Python C-Extension Compiling #

pychemistry : | static_libchemistry
	$(CC) $(PY_FPIC_PARAMS) $(SRCDIR)/pychemistry.c -o $(SRCDIR)/pychemistry.o && $(CC) $(PY_LIB_PARAMS) $(SRCDIR)/pychemistry.o -Wl,-Bstatic -lchemistry -Wl,-Bdynamic -lm -o $(PYMODDIR)/chemistry$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(PYMODDIR)/chemistry$(PYEXT)


pygeometry :
	$(CC) $(PY_FPIC_PARAMS) $(SRCDIR)/pygeometry.c -o $(SRCDIR)/pygeometry.o && $(CC) $(PY_LIB_PARAMS) $(SRCDIR)/pygeometry.o -o $(PYMODDIR)/geometry$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(PYMODDIR)/geometry$(PYEXT)


pymathconstants : | static_libmathconstants
	$(CC) $(PY_FPIC_PARAMS) $(SRCDIR)/pymathconstants.c -o $(SRCDIR)/pymathconstants.o && $(CC) $(PY_LIB_PARAMS) $(SRCDIR)/pymathconstants.o $(CLIB)/libmathconstants.a -o $(PYMODDIR)/mathconstants$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(PYMODDIR)/mathconstants$(PYEXT)


pymathfunc : | static_libmathfunc
	$(CC) $(PY_FPIC_PARAMS) $(SRCDIR)/pymathfunc.c -o $(SRCDIR)/pymathfunc.o && $(CC) $(PY_LIB_PARAMS) $(SRCDIR)/pymathfunc.o -Wl,-Bstatic -lmathfunc -Wl,-Bdynamic -lm -o $(PYMODDIR)/mathfunc$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(PYMODDIR)/mathfunc$(PYEXT)


pyphysics : | static_libphysics
	$(CC) $(PY_FPIC_PARAMS) $(SRCDIR)/pyphysics.c -o $(SRCDIR)/pyphysics.o && $(CC) $(PY_LIB_PARAMS) $(SRCDIR)/pyphysics.o $(CLIB)/libphysics.a -o $(PYMODDIR)/physics$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(PYMODDIR)/physics$(PYEXT)


pytools : | static_libtools static_libx86_64_asm_func
	$(CC) $(PY_FPIC_PARAMS) $(SRCDIR)/pytools.c -o $(SRCDIR)/pytools.o && $(CC) $(PY_LIB_PARAMS) $(SRCDIR)/pytools.o $(CLIB)/libtools.a $(CLIB)/libx86_64_asm_func.a -o $(PYMODDIR)/tools$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(PYMODDIR)/tools$(PYEXT)


pytypesize : | static_libtypesize
	$(CC) $(PY_FPIC_PARAMS) $(SRCDIR)/pytypesize.c -o $(SRCDIR)/pytypesize.o && $(CC) $(PY_LIB_PARAMS) $(SRCDIR)/pytypesize.o $(CLIB)/libtypesize.a -o $(PYMODDIR)/typesize$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(PYMODDIR)/typesize$(PYEXT)

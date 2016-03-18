#!/usr/bin/make -f
# Makefile for pylibc and PyBooster
# Version 2016.03.18


ifdef DCJ
	override dcj::=$(DCJ)
endif
ifdef PROFILE
	override dcj::=$(PROFILE)
endif
include profiles.mk


## VARIABLES ##


override DIR::=./lib
override CLIBDIR::=/clib
override CLIB::=$(DIR)$(CLIBDIR)
override CLIBSRCDIR::=/clib-src
override CLIBSRC::=$(DIR)$(CLIBSRCDIR)
PYPATH::=/usr/lib/python
override PYCLIB::=/opt/pybooster$(CLIBDIR)
override SYSPYCLIB::=/usr/lib/pyclib
override INCLUDE::=-D__MODULE_VERSION__=$(__MODULE_VERSION__) -I$(DIR) -I$(CLIBSRC)
override COMMON_ARGUMENTS::=$(WARN) $(ARCH) $(BITS) $(STD) -O3 $(XOPTMZ) $(DEBUG) -funroll-loops
override COMMON_PY_ARGUMENTS::=$(PYINCLUDE) $(PYCFLAGS) -D_FORTIFY_SOURCE=2 -fwrapv
override COMMON_POSIX_ARGUMENTS::=$(POSIX_STACK_PROTECTOR) -ffunction-sections -fdata-sections

ifndef STRIP
	override STRIP::=strip
endif

ifeq ($(OS),WIN)
	override FPIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ) -c $(FPIC)

	override LIB_PARAMS::=-L$(DIR) -L$(CLIB) -D__MODULE_VERSION__=$(__MODULE_VERSION__) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ)

	override STATIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ) -c $(FPIC)

	override PY_FPIC_PARAMS::=$(INCLUDE) $(COMMON_PY_ARGUMENTS) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ) -c $(FPIC)

	override PY_LIB_PARAMS::=-L$(DIR) -L$(CLIB) -D__MODULE_VERSION__=$(__MODULE_VERSION__) $(COMMON_ARGUMENTS) $(WINLIB) -Wl,-Bsymbolic-functions $(LDZ)
else
	override INCLUDE+= $(POSIX_INCLUDE)
	override FPIC_PARAMS::=$(INCLUDE) $(FLTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(FPIC)

	override LIB_PARAMS::=-L$(DIR) -L$(CLIB) -D__MODULE_VERSION__=$(__MODULE_VERSION__) $(FLTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) -Wl,-no-whole-archive $(LDZ) -shared

	override STATIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(FPIC)

	override PY_FPIC_PARAMS::=$(INCLUDE) $(FLTO) $(COMMON_PY_ARGUMENTS) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(FPIC)

	override PY_LIB_PARAMS::=-L$(DIR) -L$(CLIB) -D__MODULE_VERSION__=$(__MODULE_VERSION__) $(FLTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) -Wl,-no-whole-archive -Wl,-Bsymbolic-functions $(LDZ) -shared
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
	@echo "Everything:"
	@echo "    make all"
	@echo "Everything (using Clang):"
	@echo "    make all CLANG=3.7  # specify version"
	@echo "All libraries:"
	@echo "    make library"
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


.PHONY : all ast backup byte clean cleanall commit doc everything fixperm gitall install lib library llvm_bc llvm_bytecode llvm_intermediate llvm_ll most package package7z packagezip py pybuild pyclibc pylibc rmcache rmtmp stat static strip submit uninstall


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
	$(STRIP) $(STRIP_PARAMS) $(CLIB)/*.so && $(STRIP) $(STRIP_PARAMS) $(DIR)/*.so


## SPECIAL COMMANDS ##


backup : rmtmp
	cd ../; tar -cf - PyBooster | gzip -9 > ./PyBooster.tar.gz; cd ./PyBooster

package : rmtmp
	@cd ../; tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`.tar.gz; cd ./PyBooster

package7z : rmtmp
	@cd ../; 7za a ./PyBooster_v`date +"%Y.%m.%d"`.7z PyBooster; cd ./PyBooster

packagezip : rmtmp
	cd ../; zip -r ./PyBooster_v`date +"%Y.%m.%d"`.zip PyBooster; cd ./PyBooster

doc :
	-@./makedoc.sh

rmtmp :
	-@rm -f $(DIR)/*.o $(CLIBSRC)/*.o $(DIR)/*.s $(CLIBSRC)/*.s $(DIR)/*.bc $(CLIBSRC)/*.bc $(DIR)/*.ll $(CLIBSRC)/*.ll $(DIR)/*.ast $(CLIBSRC)/*.ast $(DIR)/*.i $(CLIBSRC)/*.i  $(DIR)/*.ii $(CLIBSRC)/*.ii $(DIR)/*.pch $(CLIBSRC)/*.pch; rm -frd --one-file-system $(DIR)/build/ $(CLIBSRC)/build/

rmcache :
	-@rm -frd --one-file-system $(DIR)/__pycache__/; rm -frd --one-file-system $(DIR)/ezwin/__pycache__/

clean : rmtmp rmcache

cleandoc :
	-@rm -frd $(DIR)/doc/*

cleanall : clean
	@rm -f $(DIR)/*.so $(CLIB)/*.so $(CLIB)/*.dll $(CLIB)/*.a $(DIR)/*.pyc $(DIR)/*.pyo

uninstall :
	rm -frd --one-file-system /opt/pybooster/*; rm -f /opt/bin/ezwin; rm -f /usr/lib/python$(PYVERSION)/pybooster $(SYSPYCLIB); rm -f /etc/ld.so.conf.d/pyclib.conf; ldconfig

install : rmtmp
	cd $(DIR); \
	# Prepare installation directory \
	rm -frd --one-file-system /opt/pybooster/*; \
	mkdir -vp /opt/pybooster$(CLIBDIR) /opt/pybooster$(CLIBSRCDIR); \
	mkdir -vp /opt/pybooster/doc /opt/pybooster/ezwin; \
	# Copy files to installation directory \
	cp -vRf ./* /opt/pybooster/; \
	# Ensure that the proper permissions are set \
	$(CHMOD) 644 /opt/pybooster/doc/*; \
	$(CHMOD) 644 /opt/pybooster/*.py; \
	$(CHMOD) 644 /opt/pybooster/*.glade; \
	$(CHMOD) 755 /opt/pybooster/*.so; \
	$(CHMOD) 755 /opt/pybooster$(CLIBDIR)/*; \
	$(CHMOD) 644 /opt/pybooster$(CLIBSRCDIR)/*; \
	$(CHMOD) 644 /opt/pybooster/__pycache__/*; \
	$(CHMOD) 644 /opt/pybooster/ezwin/__pycache__/*; \
	$(CHMOD) 755 /opt/pybooster/ezwin/*.py; \
	$(CHMOD) 644 /opt/pybooster/ezwin/*.glade; \
	# Make a link to ezwin.py in /opt/bin/ \
	ln -fsv -T /opt/pybooster/ezwin/ezwin.py /opt/bin/ezwin; \
	# Make Pybooster accessible to Python3 \
	ln -fsv -T /opt/pybooster $(PYPATH)$(PYVERSION)/pybooster; \
	# Add PyCLib library \
	ln -fsv -T $(PYCLIB) $(SYSPYCLIB); \
	sh -c "echo '$(SYSPYCLIB)' > /etc/ld.so.conf.d/pyclib.conf"; \
	ldconfig; \
	# END \
	echo ""; echo "Installation Complete (PyBooster)!"; \

fixperm : rmtmp
	$(CHMOD) 644 $(DIR)/doc/*.txt; \
	$(CHMOD) 755 $(DIR)/doc/html; \
	$(CHMOD) 644 $(DIR)/doc/html/*; \
	$(CHMOD) 755 $(DIR)/doc/html/search; \
	$(CHMOD) 644 $(DIR)/doc/html/search/*; \
	$(CHMOD) 644 $(DIR)/*.py; \
	$(CHMOD) 644 $(DIR)/*.glade; \
	$(CHMOD) 755 $(DIR)/*.so; \
	$(CHMOD) 755 $(DIR)/*.dll; \
	$(CHMOD) 755 $(DIR)$(CLIBDIR)/*; \
	$(CHMOD) 644 $(DIR)$(CLIBSRCDIR)/*; \
	$(CHMOD) 644 $(DIR)/__pycache__/*; \
	$(CHMOD) 644 $(DIR)/ezwin/__pycache__/*; \
	$(CHMOD) 755 $(DIR)/ezwin/*.py; \
	$(CHMOD) 644 $(DIR)/ezwin/*.glade; \


## GIT COMMANDS ##


gitall : clean
	git add -A

commit : | clean fixperm
	git commit -m "$(M)"

stat : clean
	git status -s

submit :
	git push origin master


## RULES ##


# LLVM/Clang

ast :
	-$(CLANG_AST) $(CLIBSRC)/chemistry.c -o $(CLIBSRC)/chemistry.ast; $(CLANG_AST) $(CLIBSRC)/chemistry_types.c -o $(CLIBSRC)/chemistry_types.ast; $(CLANG_AST) $(CLIBSRC)/compression.c -o $(CLIBSRC)/compression.ast; $(CLANG_AST) $(CLIBSRC)/cryptx.c -o $(CLIBSRC)/cryptx.ast; $(CLANG_AST) $(CLIBSRC)/chron.c -o $(CLIBSRC)/chron.ast; $(CLANG_AST) $(CLIBSRC)/extra_datatypes.c -o $(CLIBSRC)/extra_datatypes.ast; $(CLANG_AST) $(CLIBSRC)/fuzzy_logic.c -o $(CLIBSRC)/fuzzy_logic.ast; $(CLANG_AST) $(CLIBSRC)/geometry.c -o $(CLIBSRC)/geometry.ast; $(CLANG_AST) $(CLIBSRC)/mathconstants.c -o $(CLIBSRC)/mathconstants.ast; $(CLANG_AST) $(CLIBSRC)/mathfunc.c -o $(CLIBSRC)/mathfunc.ast; $(CLANG_AST) $(CLIBSRC)/physics.c -o $(CLIBSRC)/physics.ast; $(CLANG_AST) $(CLIBSRC)/tone.c -o $(CLIBSRC)/tone.ast; $(CLANG_AST) $(CLIBSRC)/tools.c -o $(CLIBSRC)/tools.ast; $(CLANG_AST) $(CLIBSRC)/typesize.c -o $(CLIBSRC)/typesize.ast

llvm_bytecode :
	-$(LLVM_BYTECODE) $(CLIBSRC)/chemistry.c -o $(CLIBSRC)/chemistry.bc; $(LLVM_BYTECODE) $(CLIBSRC)/chemistry_types.c -o $(CLIBSRC)/chemistry_types.bc; $(LLVM_BYTECODE) $(CLIBSRC)/compression.c -o $(CLIBSRC)/compression.bc; $(LLVM_BYTECODE) $(CLIBSRC)/cryptx.c -o $(CLIBSRC)/cryptx.bc; $(LLVM_BYTECODE) $(CLIBSRC)/chron.c -o $(CLIBSRC)/chron.bc; $(LLVM_BYTECODE) $(CLIBSRC)/extra_datatypes.c -o $(CLIBSRC)/extra_datatypes.bc; $(LLVM_BYTECODE) $(CLIBSRC)/fuzzy_logic.c -o $(CLIBSRC)/fuzzy_logic.bc; $(LLVM_BYTECODE) $(CLIBSRC)/geometry.c -o $(CLIBSRC)/geometry.bc; $(LLVM_BYTECODE) $(CLIBSRC)/mathconstants.c -o $(CLIBSRC)/mathconstants.bc; $(LLVM_BYTECODE) $(CLIBSRC)/mathfunc.c -o $(CLIBSRC)/mathfunc.bc; $(LLVM_BYTECODE) $(CLIBSRC)/physics.c -o $(CLIBSRC)/physics.bc; $(LLVM_BYTECODE) $(CLIBSRC)/tone.c -o $(CLIBSRC)/tone.bc; $(LLVM_BYTECODE) $(CLIBSRC)/tools.c -o $(CLIBSRC)/tools.bc; $(LLVM_BYTECODE) $(CLIBSRC)/typesize.c -o $(CLIBSRC)/typesize.bc

llvm_intermediate :
	-$(LLVM_INTERMEDIATE) $(CLIBSRC)/chemistry.c -o $(CLIBSRC)/chemistry.ll; $(LLVM_INTERMEDIATE) $(CLIBSRC)/chemistry_types.c -o $(CLIBSRC)/chemistry_types.ll; $(LLVM_INTERMEDIATE) $(CLIBSRC)/compression.c -o $(CLIBSRC)/compression.ll; $(LLVM_INTERMEDIATE) $(CLIBSRC)/cryptx.c -o $(CLIBSRC)/cryptx.ll; $(LLVM_INTERMEDIATE) $(CLIBSRC)/chron.c -o $(CLIBSRC)/chron.ll; $(LLVM_INTERMEDIATE) $(CLIBSRC)/extra_datatypes.c -o $(CLIBSRC)/extra_datatypes.ll; $(LLVM_INTERMEDIATE) $(CLIBSRC)/fuzzy_logic.c -o $(CLIBSRC)/fuzzy_logic.ll; $(LLVM_INTERMEDIATE) $(CLIBSRC)/geometry.c -o $(CLIBSRC)/geometry.ll; $(LLVM_INTERMEDIATE) $(CLIBSRC)/mathconstants.c -o $(CLIBSRC)/mathconstants.ll; $(LLVM_INTERMEDIATE) $(CLIBSRC)/mathfunc.c -o $(CLIBSRC)/mathfunc.ll; $(LLVM_INTERMEDIATE) $(CLIBSRC)/physics.c -o $(CLIBSRC)/physics.ll; $(LLVM_INTERMEDIATE) $(CLIBSRC)/tone.c -o $(CLIBSRC)/tone.ll; $(LLVM_INTERMEDIATE) $(CLIBSRC)/tools.c -o $(CLIBSRC)/tools.ll; $(LLVM_INTERMEDIATE) $(CLIBSRC)/typesize.c -o $(CLIBSRC)/typesize.ll


# Library Compiling

# To dynamically link, use "-lm"
libchemistry : | libchemistry_types
	$(CC) $(FPIC_PARAMS) $(CLIBSRC)/chemistry.c -o $(CLIBSRC)/chemistry.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libchemistry.$(LIBEXT) $(CLIBSRC)/chemistry.o $(CLIBSRC)/chemistry_types.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libchemistry.$(LIBEXT)


libchemistry_types :
	$(CC) $(FPIC_PARAMS) $(CLIBSRC)/chemistry_types.c -o $(CLIBSRC)/chemistry_types.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libchemistry_types.$(LIBEXT) $(CLIBSRC)/chemistry_types.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libchemistry_types.$(LIBEXT)


libchron :
	$(CC) $(FPIC_PARAMS) $(CLIBSRC)/chron.c -o $(CLIBSRC)/chron.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libchron.$(LIBEXT) $(CLIBSRC)/chron.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libchron.$(LIBEXT)


ifdef MUSL
libcompression :

else ifdef ARCH_ARM
libcompression :

else ifeq ($(OS),POSIX)
libcompression :
	-$(CC) $(FPIC_PARAMS) $(CLIBSRC)/compression.c -o $(CLIBSRC)/compression.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libcompression.$(LIBEXT) $(CLIBSRC)/compression.o -Wl,-Bstatic -Wl,-Bdynamic -lz && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libcompression.$(LIBEXT)

else
libcompression :

endif


libcryptx :
	$(CC) $(FPIC_PARAMS) $(CLIBSRC)/cryptx.c -o $(CLIBSRC)/cryptx.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libcryptx.$(LIBEXT) $(CLIBSRC)/cryptx.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libcryptx.$(LIBEXT)


libextra_datatypes :
	$(CC) $(FPIC_PARAMS) $(CLIBSRC)/extra_datatypes.c -o $(CLIBSRC)/extra_datatypes.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libextra_datatypes.$(LIBEXT) $(CLIBSRC)/extra_datatypes.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libextra_datatypes.$(LIBEXT)


libfuzzy_logic :
	$(CC) $(FPIC_PARAMS) $(CLIBSRC)/fuzzy_logic.c -o $(CLIBSRC)/fuzzy_logic.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libfuzzy_logic.$(LIBEXT) $(CLIBSRC)/fuzzy_logic.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libfuzzy_logic.$(LIBEXT)


libgeometry :
	$(CC) $(FPIC_PARAMS) $(CLIBSRC)/geometry.c -o $(CLIBSRC)/geometry.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libgeometry.$(LIBEXT) $(CLIBSRC)/geometry.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libgeometry.$(LIBEXT)


libmathconstants :
	$(CC) $(FPIC_PARAMS) $(CLIBSRC)/mathconstants.c -o $(CLIBSRC)/mathconstants.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libmathconstants.$(LIBEXT) $(CLIBSRC)/mathconstants.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libmathconstants.$(LIBEXT)


# To dynamically link, use "-lm"
libmathfunc :
	$(CC) $(FPIC_PARAMS) $(CLIBSRC)/mathfunc.c -o $(CLIBSRC)/mathfunc.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libmathfunc.$(LIBEXT) $(CLIBSRC)/mathfunc.o -lm && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libmathfunc.$(LIBEXT)


libphysics :
	$(CC) $(FPIC_PARAMS) $(CLIBSRC)/physics.c -o $(CLIBSRC)/physics.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libphysics.$(LIBEXT) $(CLIBSRC)/physics.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libphysics.$(LIBEXT)


ifdef MUSL
libtone :

else ifeq ($(OS),POSIX)
# To dynamically link, use "-ltone -lao -ldl -lm"
libtone :
	-$(CC) $(FPIC_PARAMS) $(CLIBSRC)/tone.c -o $(CLIBSRC)/tone.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libtone.$(LIBEXT) $(CLIBSRC)/tone.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libtone.$(LIBEXT)
else
libtone :

endif


libtools :
	$(CC) $(FPIC_PARAMS) $(CLIBSRC)/tools.c -o $(CLIBSRC)/tools.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libtools.$(LIBEXT) $(CLIBSRC)/tools.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libtools.$(LIBEXT)


libtypesize :
	$(CC) $(FPIC_PARAMS) $(CLIBSRC)/typesize.c -o $(CLIBSRC)/typesize.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libtypesize.$(LIBEXT) $(CLIBSRC)/typesize.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libtypesize.$(LIBEXT)


libx86_64_asm_func :
	$(CC) $(FPIC_PARAMS) $(CLIBSRC)/x86_64_asm_func.c -o $(CLIBSRC)/x86_64_asm_func.o && $(CC) $(LIB_PARAMS) -o $(CLIB)/libx86_64_asm_func.$(LIBEXT) $(CLIBSRC)/x86_64_asm_func.o && $(STRIP) $(STRIP_PARAMS) $(CLIB)/libx86_64_asm_func.$(LIBEXT)


# Static Library Compiling

# To statically link, use "-Wl,-Bdynamic -lm"
static_libchemistry : | static_libchemistry_types
	$(CC) $(STATIC_PARAMS) $(CLIBSRC)/chemistry.c -o $(CLIBSRC)/chemistry.o && ar rcs -o $(CLIB)/libchemistry.a $(CLIBSRC)/chemistry.o $(CLIB)/libchemistry_types.a


static_libchemistry_types :
	$(CC) $(STATIC_PARAMS) $(CLIBSRC)/chemistry_types.c -o $(CLIBSRC)/chemistry_types.o && ar rcs -o $(CLIB)/libchemistry_types.a $(CLIBSRC)/chemistry_types.o


static_libchron :
	$(CC) $(STATIC_PARAMS) $(CLIBSRC)/chron.c -o $(CLIBSRC)/chron.o && ar rcs -o $(CLIB)/libchron.a $(CLIBSRC)/chron.o


ifdef MUSL
static_libcompression :

else ifdef ARCH_ARM
static_libcompression :

else ifeq ($(OS),POSIX)
# To statically link, use "-Wl,-Bstatic -lz -Wl,-Bdynamic"
static_libcompression :
	-$(CC) $(STATIC_PARAMS) $(CLIBSRC)/compression.c -o $(CLIBSRC)/compression.o && ar rcs -o $(CLIB)/libcompression.a $(CLIBSRC)/compression.o

else
static_libcompression :

endif


static_libcryptx :
	$(CC) $(STATIC_PARAMS) $(CLIBSRC)/cryptx.c -o $(CLIBSRC)/cryptx.o && ar rcs -o $(CLIB)/libcryptx.a $(CLIBSRC)/cryptx.o


static_libextra_datatypes :
	$(CC) $(STATIC_PARAMS) $(CLIBSRC)/extra_datatypes.c -o $(CLIBSRC)/extra_datatypes.o && ar rcs -o $(CLIB)/libextra_datatypes.a $(CLIBSRC)/extra_datatypes.o


static_libfuzzy_logic :
	$(CC) $(STATIC_PARAMS) $(CLIBSRC)/fuzzy_logic.c -o $(CLIBSRC)/fuzzy_logic.o && ar rcs -o $(CLIB)/libfuzzy_logic.a $(CLIBSRC)/fuzzy_logic.o


static_libgeometry :
	$(CC) $(STATIC_PARAMS) $(CLIBSRC)/geometry.c -o $(CLIBSRC)/geometry.o && ar rcs -o $(CLIB)/libgeometry.a $(CLIBSRC)/geometry.o


static_libmathconstants :
	$(CC) $(STATIC_PARAMS) $(CLIBSRC)/mathconstants.c -o $(CLIBSRC)/mathconstants.o && ar rcs -o $(CLIB)/libmathconstants.a $(CLIBSRC)/mathconstants.o


# To statically link, use "-Wl,-Bdynamic -lm"
static_libmathfunc :
	$(CC) $(STATIC_PARAMS) $(CLIBSRC)/mathfunc.c -o $(CLIBSRC)/mathfunc.o && ar rcs -o $(CLIB)/libmathfunc.a $(CLIBSRC)/mathfunc.o


static_libphysics :
	$(CC) $(STATIC_PARAMS) $(CLIBSRC)/physics.c -o $(CLIBSRC)/physics.o && ar rcs -o $(CLIB)/libphysics.a $(CLIBSRC)/physics.o


ifdef MUSL
static_libtone :

else ifeq ($(OS),POSIX)
# To statically link, use "-Wl,-Bstatic -ltone -lao -Wl,-Bdynamic -ldl -lm"
static_libtone :
	-$(CC) $(STATIC_PARAMS) $(CLIBSRC)/tone.c -o $(CLIBSRC)/tone.o && ar rcs -o $(CLIB)/libtone.a $(CLIBSRC)/tone.o

else
static_libtone :

endif


static_libtools :
	$(CC) $(STATIC_PARAMS) $(CLIBSRC)/tools.c -o $(CLIBSRC)/tools.o && ar rcs -o $(CLIB)/libtools.a $(CLIBSRC)/tools.o


static_libtypesize :
	$(CC) $(STATIC_PARAMS) $(CLIBSRC)/typesize.c -o $(CLIBSRC)/typesize.o && ar rcs -o $(CLIB)/libtypesize.a $(CLIBSRC)/typesize.o


static_libx86_64_asm_func :
	$(CC) $(STATIC_PARAMS) $(CLIBSRC)/x86_64_asm_func.c -o $(CLIBSRC)/x86_64_asm_func.o && ar rcs -o $(CLIB)/libx86_64_asm_func.a $(CLIBSRC)/x86_64_asm_func.o


# Python Byte Compiling

byte :
	-export PYTHONOPTIMIZE="2"; python$(PYVERSION) -m compileall -q -f $(DIR)/


# Python C-Extension Compiling

pychemistry : | static_libchemistry
	$(CC) $(PY_FPIC_PARAMS) $(CLIBSRC)/pychemistry.c -o $(CLIBSRC)/pychemistry.o && $(CC) $(PY_LIB_PARAMS) $(CLIBSRC)/pychemistry.o -Wl,-Bstatic -lchemistry -Wl,-Bdynamic -lm -o $(DIR)/chemistry$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(DIR)/chemistry$(PYEXT)


pygeometry :
	$(CC) $(PY_FPIC_PARAMS) $(CLIBSRC)/pygeometry.c -o $(CLIBSRC)/pygeometry.o && $(CC) $(PY_LIB_PARAMS) $(CLIBSRC)/pygeometry.o -o $(DIR)/geometry$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(DIR)/geometry$(PYEXT)


pymathconstants : | static_libmathconstants
	$(CC) $(PY_FPIC_PARAMS) $(CLIBSRC)/pymathconstants.c -o $(CLIBSRC)/pymathconstants.o && $(CC) $(PY_LIB_PARAMS) $(CLIBSRC)/pymathconstants.o $(CLIB)/libmathconstants.a -o $(DIR)/mathconstants$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(DIR)/mathconstants$(PYEXT)


pymathfunc : | static_libmathfunc
	$(CC) $(PY_FPIC_PARAMS) $(CLIBSRC)/pymathfunc.c -o $(CLIBSRC)/pymathfunc.o && $(CC) $(PY_LIB_PARAMS) $(CLIBSRC)/pymathfunc.o -Wl,-Bstatic -lmathfunc -Wl,-Bdynamic -lm -o $(DIR)/mathfunc$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(DIR)/mathfunc$(PYEXT)


pyphysics : | static_libphysics
	$(CC) $(PY_FPIC_PARAMS) $(CLIBSRC)/pyphysics.c -o $(CLIBSRC)/pyphysics.o && $(CC) $(PY_LIB_PARAMS) $(CLIBSRC)/pyphysics.o $(CLIB)/libphysics.a -o $(DIR)/physics$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(DIR)/physics$(PYEXT)


pytools : | static_libtools static_libx86_64_asm_func
	$(CC) $(PY_FPIC_PARAMS) $(CLIBSRC)/pytools.c -o $(CLIBSRC)/pytools.o && $(CC) $(PY_LIB_PARAMS) $(CLIBSRC)/pytools.o $(CLIB)/libtools.a $(CLIB)/libx86_64_asm_func.a -o $(DIR)/tools$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(DIR)/tools$(PYEXT)


pytypesize : | static_libtypesize
	$(CC) $(PY_FPIC_PARAMS) $(CLIBSRC)/pytypesize.c -o $(CLIBSRC)/pytypesize.o && $(CC) $(PY_LIB_PARAMS) $(CLIBSRC)/pytypesize.o $(CLIB)/libtypesize.a -o $(DIR)/typesize$(PYEXT) && $(STRIP) $(STRIP_PARAMS) $(DIR)/typesize$(PYEXT)

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


override BIN::=./bin
override SRCDIR::=./src
override UTILSRCDIR::=./utilsrc
override PYSRC::=./pylib
override EZWINSRC::=$(PYSRC)/ezwin
override INCLUDE::=-D__MODULE_VERSION__=$(__MODULE_VERSION__) -I$(SRCDIR)
override COMMON_ARGUMENTS::=$(WARN) $(ARCH) $(BITS) $(STD) -O3 $(XOPTMZ) $(DEBUG) -funroll-loops
override COMMON_POSIX_ARGUMENTS::=$(POSIX_STACK_PROTECTOR) -ffunction-sections -fdata-sections

ifndef STRIP
	override STRIP::=strip
endif


ifeq ($(OS),WIN)
	override EXE_PARAMS::=$(INCLUDE) -fwhole-program $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ)

	override FPIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ) -c $(FPIC)

	override LIB_PARAMS::=-L$(CLIB) -D__MODULE_VERSION__=$(__MODULE_VERSION__) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ)

	override STATIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(WINLIB) $(LDZ) -c $(FPIC)
else
	override INCLUDE+= $(POSIX_INCLUDE)

	override EXE_PARAMS::=$(INCLUDE) -fwhole-program $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ)

	override FPIC_PARAMS::=$(INCLUDE) $(FLTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(FPIC)

	override LIB_PARAMS::=-L$(CLIB) -D__MODULE_VERSION__=$(__MODULE_VERSION__) $(FLTO) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) -Wl,-no-whole-archive $(LDZ) -shared

	override STATIC_PARAMS::=$(INCLUDE) $(COMMON_ARGUMENTS) $(COMMON_POSIX_ARGUMENTS) $(LDZ) -c $(FPIC)
endif


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
	@echo "    make all CLANG=4.0  # specify version"
	@echo "Strip binaries:"
	@echo "    make strip"
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
	@echo "Remove temp files:"
	@echo "    make rmtmp"
	@echo "Remove temp files:"
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
.PHONY : all backup clean cleanall cleanfull ctags fixperm install package package7z packagezip rmcache rmtmp strip uninstall upver
# Documentation
.PHONY : cleandoc doc doxy
# Git
.PHONY : commit gitall stat submit
# Programs
.PHONY : cos fib getpgid microtime typesize


## BUILD COMMANDS ##


all : cos fib getpgid microtime typesize


strip :
	-@$(STRIP) $(STRIP_PARAMS) $(BIN)/*


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
	-@geany -P -g ./tools/PyBooster.c.tags $(SRCDIR)/MACROS.h

doc : cleandoc
	-@./makedoc.sh

doxy :
	-@doxywizard ./Doxyfile; $(CHMOD) 644 ./Doxyfile

upver :
	@cd ./tools/; ./update_version.sh; cd ..;

rmtmp :
	-@rm -f $(SRCDIR)/*.o $(SRCDIR)/*.s $(SRCDIR)/*.bc $(SRCDIR)/*.ll $(SRCDIR)/*.ast $(SRCDIR)/*.i  $(SRCDIR)/*.ii $(SRCDIR)/*.pch $(UTILSRCDIR)/*.o $(UTILSRCDIR)/*.s $(UTILSRCDIR)/*.bc $(UTILSRCDIR)/*.ll $(UTILSRCDIR)/*.ast $(UTILSRCDIR)/*.i  $(UTILSRCDIR)/*.ii $(UTILSRCDIR)/*.pch

rmcache :
	-@rm -frd --one-file-system $(PYSRC)/__pycache__/ $(PYSRC)/ezwin/__pycache__/

clean : rmtmp rmcache

cleandoc :
	-@rm -frd ./doc/*

cleanall : rmtmp
	-@rm -f $(BIN)/*

cleanfull : cleanall cleandoc

uninstall :
	@echo "Beginning Uninstall (PyBooster)"; \
	rm -frd --one-file-system /opt/pybooster/* /opt/bin/PyTools/*; \
	rm -f /opt/bin/ezwin; \
	rm -f /opt/bin/cos /opt/bin/fib /opt/bin/getpgid /opt/bin/microtime /opt/bin/typesize; \
	rm -f $(PYPATH)$(PYVERSION)/pybooster; \
	ldconfig; \
	# END \
	echo ""; echo "Uninstall Complete!"; \

install : rmtmp
	@echo "Beginning Installation (PyBooster)"; \
	# Prepare installation directory \
	rm -frd --one-file-system /opt/pybooster/*; \
	mkdir --mode=755 -p /opt/pybooster/bin/ /opt/pybooster/doc/; \
	mkdir --mode=755 -p /opt/pybooster/ezwin/; \
	# Add files \
	cp -Rf ./doc/* /opt/pybooster/doc; \
	cp $(BIN)/* /opt/bin/; \
	cp -Rf $(PYSRC)/* /opt/pybooster/; \
	# Install PyTools \
	cd ./tools/PyTools/; \
	./INSTALL.sh; \
	cd ../..; \
	# Set proper permissions \
	$(CHMOD) 755 /opt/pybooster/bin/*; \
	$(CHMOD) 644 /opt/pybooster/ /opt/pybooster/*.py; \
	$(CHMOD) 644 /opt/pybooster/ezwin/*.py; \
	$(CHMOD) 644 /opt/pybooster/*.glade /opt/pybooster/ezwin/*.glade; \
	# Make a link to ezwin.py in /opt/bin/ \
	ln -fs -T /opt/pybooster/ezwin/ezwin.py /opt/bin/ezwin; \
	# Make Pybooster accessible to Python3 \
	ln -fs -T /opt/pybooster/ $(PYPATH)$(PYVERSION)/pybooster; \
	# END \
	echo ""; echo "Installation Complete!"; \

fixperm : rmtmp
	-@$(CHMOD) 644 ./doc/*.txt; \
	$(CHMOD) 755 ./doc/html; \
	$(CHMOD) 644 ./doc/html/*; \
	$(CHMOD) 755 ./doc/html/search; \
	$(CHMOD) 644 ./doc/html/search/*; \
	$(CHMOD) 755 $(SRCDIR) $(UTILSRCDIR); \
	$(CHMOD) 644 $(SRCDIR)/* $(UTILSRCDIR)/*; \
	$(CHMOD) 755 $(BIN)/ $(BIN)/*; \
	$(CHMOD) 755 $(PYSRC)/; \
	$(CHMOD) 644 $(PYSRC)/*.py $(EZWINSRC)/*.py; \
	$(CHMOD) 644 $(PYSRC)/*.glade $(EZWINSRC)/*.glade; \


## GIT COMMANDS ##


gitall : cleanall
	-@git add -A

commit : | cleanall fixperm
	-@git commit -m "$(M)"

stat : cleanall
	-@git status -s

submit :
	git push origin master


## PROGRAM RULES ##


cos :
	$(CC) -DNO_PRINT_M -DNO_PRINT_INTS $(EXE_PARAMS) $(UTILSRCDIR)/cos.c -o $(BIN)/cos && $(STRIP) $(STRIP_PARAMS) $(BIN)/cos

fib :
	$(CC) -DNO_PRINT_M -DNO_PRINT_FLOATS $(EXE_PARAMS) $(UTILSRCDIR)/fib.c -o $(BIN)/fib && $(STRIP) $(STRIP_PARAMS) $(BIN)/fib

getpgid :
	$(CC) -DNO_PRINT_M -DNO_PRINT_FLOATS $(EXE_PARAMS) $(UTILSRCDIR)/getpgid.c -o $(BIN)/getpgid && $(STRIP) $(STRIP_PARAMS) $(BIN)/getpgid
# -nostdlib -lgcc -nodefaultlibs -nostartfiles

microtime :
	$(CC) -DNO_PRINT_M -DNO_PRINT_FLOATS $(EXE_PARAMS) $(UTILSRCDIR)/microtime.c -o $(BIN)/microtime && $(STRIP) $(STRIP_PARAMS) $(BIN)/microtime

typesize :
	$(CC) -DNO_PRINT_M -DNO_PRINT_FLOATS $(EXE_PARAMS) $(UTILSRCDIR)/typesize.c -o $(BIN)/typesize && $(STRIP) $(STRIP_PARAMS) $(BIN)/typesize

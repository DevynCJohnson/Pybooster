#!/usr/bin/make -f
# -*- coding: utf-8-unix; Mode: Makefile; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=makefile syntax=makefile.doxygen fileformat=unix tabstop=4 :
# kate: encoding utf-8; bom off; syntax makefile; indent-mode normal; eol unix; indent-width 4; tab-width 4; remove-trailing-space on;

.POSIX :
.ONESHELL :
override SHELL::=/bin/sh
.SHELLFLAGS::=-c


## BUILD COMMANDS ##


.PHONY : all clean doc install rmtmp strip uninstall

all : lib py

strip :
	@strip --strip-debug --strip-unneeded ./*.so


## SPECIAL COMMANDS ##


doc :
	@./makedoc.sh

install : rmtmp
	@./INSTALL.sh

uninstall :
	@rm -rd --one-file-system /PATH/*
	rm -f /FILEPATH

clean : rmtmp
	@rm -f *.pyc *.pyo *.so
	rm -fr --one-file-system ./DIR/

rmtmp :
	@rm -f *.o
	rm -fr --one-file-system ./build/


## RULES ##


LIBRARY :
	gcc -Wall -pedantic -O3 -Wl,-O3 -gtoggle -g0 -funroll-all-loops -pipe -ffunction-sections -fdata-sections -minline-all-stringops -c -fPIC FILE.c -o FILE.o && gcc -Wall -pedantic -O3 -Wl,-O3 -gtoggle -g0 -funroll-all-loops -pipe -ffunction-sections -fdata-sections -minline-all-stringops -shared -o FILE.so FILE.o && strip --strip-debug --strip-unneeded ./FILE.so

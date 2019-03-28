// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief Output the name of the current operating-system
@file ostype.c
@version 2019.03.28
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section COMPILE
gcc -Wall -Wextra -Wpedantic -O3 -Wl,-O3 -g0 -ggdb0 -s -fwhole-program -funroll-loops -ffunction-sections -fdata-sections -std=c11 -o ./ostype ./ostype.c && strip --remove-section=.note --remove-section=.comment --strip-debug --strip-unneeded ./ostype

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This software is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
*/


#include "MACROS.h"


#if (defined(__APPLE__) && defined(__MACH__))
#   include <TargetConditionals.h>
#endif


noreturn int main(void) {
	// IBM AIX
#   ifdef OSAIX
	puts_no_output("AIX");
	// OSX, iOS, NeXTSTEP, and Darwin
#   elif (defined(__APPLE__) && defined(__MACH__))
#      if ((TARGET_IPHONE_SIMULATOR == 1) || (TARGET_OS_IPHONE == 1))
	puts_no_output("iOS");
#      elif (TARGET_OS_MAC == 1)
	puts_no_output("OSX");
#      endif
#   elif ((!defined(__APPLE__)) && defined(__MACH__))
	puts_no_output("NeXTSTEP");
	// BSD (DragonFly BSD, FreeBSD, OpenBSD, NetBSD)
#   elif (defined(__unix__) && defined(OSBSD))
#      ifdef OSDRAGONFLY
	puts_no_output("DragonFly");
#      elif defined(OSFREEBSD)
	puts_no_output("FreeBSD");
#      elif defined(OSNETBSD)
	puts_no_output("NetBSD");
#      elif defined(OSOPENBSD)
	puts_no_output("OpenBSD");
#      else
	puts_no_output("BSD");
#      endif
	// HP-UX (Hewlett-Packard Unix)
#   elif defined(OSHPUX)
	puts_no_output("HP-UX");
	// Linux
#   elif defined(OSANDROID)
	puts_no_output("Android");
#   elif defined(OSLINUX)
	puts_no_output("Linux");
	// Solaris
#   elif (defined(OSSOLARIS))
	puts_no_output("Solaris");
	// Cygwin
#   elif (defined(OSCYGWIN))
	puts_no_output("Cygwin");
	// MingW
#   elif defined(MINGW64)
	puts_no_output("MingW on Microsoft Windows (64-bit)");
#   elif defined(MINGW32)
	puts_no_output("MingW on Microsoft Windows (32-bit)");
	// Windows
#   elif defined(_WIN64)
	puts_no_output("Microsoft Windows (64-bit)");
#   elif defined(_WIN32)
	puts_no_output("Microsoft Windows (32-bit)");
#   endif
	fast_exit(EXIT_SUCCESS);
}

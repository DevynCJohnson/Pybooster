// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief Returns the Process Group ID
@file getpgid.c
@version 2018.08.23
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section COMPILE
gcc -Wall -Wextra -Wpedantic -O3 -Wl,-O3 -g0 -ggdb0 -s -fwhole-program -funroll-loops -ffunction-sections -fdata-sections -std=c11 -o ./getpgid ./getpgid.c && strip --remove-section=.note --remove-section=.comment --strip-debug --strip-unneeded ./getpgid

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This software is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
*/


#include "MACROS.h"


noreturn int main(rargc, rargv) {
	if (PREDICT_UNLIKELY(argc > 2)) {
		puts_err_no_output("Expected one parameter!");
		fast_exit(EXIT_FAILURE);
	} else if (argc == 1) {
		puti((int)getpgid(0));
		fast_exit(EXIT_SUCCESS);
	}
	register const int pid = (int)atol(argv[1]);
	puti((int)getpgid(pid));
	fast_exit(EXIT_SUCCESS);
}

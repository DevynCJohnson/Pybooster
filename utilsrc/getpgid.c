// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file getpgid.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief getpgid() - returns the Process Group ID
@version 2017.07.15

@section COMPILE
gcc -Wall -Wextra -pedantic -O3 -Wl,-O3 -g0 -ggdb0 -s -fwhole-program -funroll-loops -pthread -pipe -ffunction-sections -fdata-sections -std=gnu11 -o ./getpgid ./getpgid.c && strip --remove-section=.note --remove-section=.comment --strip-debug --strip-unneeded ./getpgid

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.
*/


#include "MACROS.h"


int main(int argc, char* argv[]) {
	if (argc > 2) {
		fprintf(stderr, "Expected one parameter or no parameters, but was given %d\n", (argc - 1));
		exit(EXIT_FAILURE);
	} else if (argc == 1) {
		fprintf(stdout, "%i\n", getpgid(0));
		exit(EXIT_SUCCESS);
	}
	register const int pid = (int)atol(argv[1]);
	fprintf(stdout, "%i\n", getpgid(pid));
	exit(EXIT_SUCCESS);
}

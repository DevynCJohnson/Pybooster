// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file microtime.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Measure execution time
@version 2017.07.15
@usage ./microtime  # Return the current time in microseconds

@section COMPILE
 - gcc -Wall -Wextra -pedantic -O3 -Wl,-O3 -g0 -ggdb0 -s -fwhole-program -funroll-loops -pthread -pipe -ffunction-sections -fdata-sections -std=c11 -o ./microtime ./microtime.c && strip --remove-section=.note --remove-section=.comment --strip-debug --strip-unneeded ./microtime
 -  gcc -march=haswell -Wall -Wextra -pedantic -ffast-math -ftree-vectorize -O3 -Wl,-O3 -g0 -ggdb0 -s -fwhole-program -funroll-loops -pthread -pipe -ffunction-sections -fdata-sections -std=c11 ./microtime.c -o ./microtime && strip --remove-section=.note --remove-section=.comment --strip-debug --strip-unneeded ./microtime

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


int main(void) {
	struct timeval now;
	gettimeofday(&now, NULL);
	char testptr[64] = { 0 };
	ulltostr((ullint)((1000000UL * (ulint)now.tv_sec) + (ulint)now.tv_usec), testptr, 10);
	puts(testptr);
	return 0;
}

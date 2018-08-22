// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief Measure execution time
@file microtime.c
@version 2018.08.22
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@usage ./microtime  # Return the current time in microseconds

@section COMPILE
gcc -Wall -Wextra -Wpedantic -O3 -Wl,-O3 -g0 -ggdb0 -s -fwhole-program -funroll-loops -ffunction-sections -fdata-sections -std=c11 -o ./microtime ./microtime.c && strip --remove-section=.note --remove-section=.comment --strip-debug --strip-unneeded ./microtime

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


noreturn int main(void) {
	struct timeval align32 now = { 0 };
	gettimeofday(&now, NULL);
	putu64((uint64_t)((1000000UL * (ulint)now.tv_sec) + (ulint)now.tv_usec));
	fast_exit(EXIT_SUCCESS);
}

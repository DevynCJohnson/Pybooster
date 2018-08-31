// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief Print the size of each datatype
@file typesize.c
@version 2018.08.31
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section COMPILE
gcc -Wall -Wextra -Wpedantic -O3 -Wl,-O3 -g0 -ggdb0 -s -fwhole-program -funroll-loops -ffunction-sections -fdata-sections -std=c11 -o ./typesize ./typesize.c && strip --remove-section=.note --remove-section=.comment --strip-debug --strip-unneeded ./typesize

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
	// Get Datatype Size
	const ulint signedcharsize = (ulint)sizeof(signed char);
	const ulint unsignedcharsize = (ulint)sizeof(unsigned char);
	const ulint signedintsize = (ulint)sizeof(signed int);
	const ulint unsignedintsize = (ulint)sizeof(unsigned int);
	const ulint signedshortintsize = (ulint)sizeof(signed short int);
	const ulint unsignedshortintsize = (ulint)sizeof(unsigned short int);
	const ulint signedlongintsize = (ulint)sizeof(signed long int);
	const ulint unsignedlongintsize = (ulint)sizeof(unsigned long int);
	const ulint signedlonglongintsize = (ulint)sizeof(signed long long int);
	const ulint unsignedlonglongintsize = (ulint)sizeof(unsigned long long int);
	const ulint floatsize = (ulint)sizeof(float);
	const ulint doublesize = (ulint)sizeof(double);
	const ulint longdoublesize = (ulint)sizeof(long double);
#   if SUPPORTS_COMPLEX
	const ulint complexfloatsize = (ulint)sizeof(complex_float);
	const ulint complexdoublesize = (ulint)sizeof(complex_double);
	const ulint complexlongdoublesize = (ulint)sizeof(complex_long_double);
#   endif
	const ulint boolsize = (ulint)sizeof(_Bool);
	const ulint sizetsize = (ulint)sizeof(size_t);
#   if defined(_POSIX_VERSION)
	const ulint ssizetsize = (ulint)sizeof(ssize_t);
#   endif
	const ulint ptrsize = (ulint)sizeof(char*);
	const ulint adrsize = (ulint)sizeof(&ptrsize);
	const ulint filesize = (ulint)sizeof(FILE);
	// Display Sizes
	printf("Signed Char: %lu\n", signedcharsize);
	printf("Unsigned Char: %lu\n", unsignedcharsize);
	printf("Signed Int: %lu\n", signedintsize);
	printf("Unsigned Int: %lu\n", unsignedintsize);
	printf("Signed Short Int: %lu\n", signedshortintsize);
	printf("Unsigned Short Int: %lu\n", unsignedshortintsize);
	printf("Signed Long Int: %lu\n", signedlongintsize);
	printf("Unsigned Long Int: %lu\n", unsignedlongintsize);
	printf("Signed Long Long Int: %lu\n", signedlonglongintsize);
	printf("Unsigned Long Long Int: %lu\n", unsignedlonglongintsize);
	printf("Float: %lu\n", floatsize);
	printf("Double: %lu\n", doublesize);
	printf("Long Double: %lu\n", longdoublesize);
#   if SUPPORTS_COMPLEX
	printf("Complex Float: %lu\n", complexfloatsize);
	printf("Complex Double: %lu\n", complexdoublesize);
	printf("Complex Long Double: %lu\n", complexlongdoublesize);
#   endif
	printf("_Bool: %lu\n", boolsize);
	printf("size_t: %lu\n", sizetsize);
#   if defined(_POSIX_VERSION)
	printf("ssize_t: %lu\n", ssizetsize);
#   endif
	printf("Char*: %lu\n", ptrsize);
	printf("&Address: %lu\n", adrsize);
	printf("FILE: %lu\n", filesize);
	fast_exit(EXIT_SUCCESS);
}

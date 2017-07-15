// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file typesize.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Print the size of each datatype
@version 2017.07.15

@section COMPILE
gcc -Wall -Wextra -pedantic -O3 -Wl,-O3 -g0 -ggdb0 -s -fwhole-program -funroll-loops -pthread -pipe -ffunction-sections -fdata-sections -std=c11 -o ./typesize ./typesize.c && strip --remove-section=.note --remove-section=.comment --strip-debug --strip-unneeded ./typesize

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
	// Get Datatype Size
	const ulint charsize = (ulint)sizeof(char);
	const ulint signedcharsize = (ulint)sizeof(signed char);
	const ulint unsignedcharsize = (ulint)sizeof(unsigned char);
	const ulint intsize = (ulint)sizeof(int);
	const ulint signedintsize = (ulint)sizeof(signed int);
	const ulint unsignedintsize = (ulint)sizeof(unsigned int);
	const ulint shortintsize = (ulint)sizeof(short int);
	const ulint signedshortintsize = (ulint)sizeof(signed short int);
	const ulint unsignedshortintsize = (ulint)sizeof(unsigned short int);
	const ulint longintsize = (ulint)sizeof(long int);
	const ulint signedlongintsize = (ulint)sizeof(signed long int);
	const ulint unsignedlongintsize = (ulint)sizeof(unsigned long int);
	const ulint longlongintsize = (ulint)sizeof(long long int);
	const ulint signedlonglongintsize = (ulint)sizeof(signed long long int);
	const ulint unsignedlonglongintsize = (ulint)sizeof(unsigned long long int);
	const ulint floatsize = (ulint)sizeof(float);
	const ulint doublesize = (ulint)sizeof(double);
	const ulint longdoublesize = (ulint)sizeof(long double);
	const ulint floatcomplexsize = (ulint)sizeof(float _Complex);
	const ulint doublecomplexsize = (ulint)sizeof(double _Complex);
	const ulint longdoublecomplexsize = (ulint)sizeof(long double _Complex);
	const ulint boolsize = (ulint)sizeof(_Bool);
	const ulint sizetsize = (ulint)sizeof(size_t);
#   if defined(_POSIX_VERSION)
	const ulint ssizetsize = (ulint)sizeof(ssize_t);
#   endif
	const ulint ptrsize = (ulint)sizeof(char*);
	const ulint adrsize = (ulint)sizeof(&ptrsize);
	// Display Sizes
	fprintf(stdout, "Char: %lu\n", charsize);
	fprintf(stdout, "Signed Char: %lu\n", signedcharsize);
	fprintf(stdout, "Unsigned Char: %lu\n", unsignedcharsize);
	fprintf(stdout, "Int: %lu\n", intsize);
	fprintf(stdout, "Signed Int: %lu\n", signedintsize);
	fprintf(stdout, "Unsigned Int: %lu\n", unsignedintsize);
	fprintf(stdout, "Short Int: %lu\n", shortintsize);
	fprintf(stdout, "Signed Short Int: %lu\n", signedshortintsize);
	fprintf(stdout, "Unsigned Short Int: %lu\n", unsignedshortintsize);
	fprintf(stdout, "Long Int: %lu\n", longintsize);
	fprintf(stdout, "Signed Long Int: %lu\n", signedlongintsize);
	fprintf(stdout, "Unsigned Long Int: %lu\n", unsignedlongintsize);
	fprintf(stdout, "Long Long Int: %lu\n", longlongintsize);
	fprintf(stdout, "Signed Long Long Int: %lu\n", signedlonglongintsize);
	fprintf(stdout, "Unsigned Long Long Int: %lu\n", unsignedlonglongintsize);
	fprintf(stdout, "Float: %lu\n", floatsize);
	fprintf(stdout, "Double: %lu\n", doublesize);
	fprintf(stdout, "Long Double: %lu\n", longdoublesize);
	fprintf(stdout, "Float Complex: %lu\n", floatcomplexsize);
	fprintf(stdout, "Double Complex: %lu\n", doublecomplexsize);
	fprintf(stdout, "Long Double Complex: %lu\n", longdoublecomplexsize);
	fprintf(stdout, "_Bool: %lu\n", boolsize);
	fprintf(stdout, "size_t: %lu\n", sizetsize);
#   if defined(_POSIX_VERSION)
	fprintf(stdout, "ssize_t: %lu\n", ssizetsize);
#   endif
	fprintf(stdout, "Char*: %lu\n", ptrsize);
	fprintf(stdout, "&adrsize: %lu\n", adrsize);
	return 0;
}

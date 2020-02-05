// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
/**
@brief Print the various properties (in CSV format) of a given number or print all of them within a range
@file number_properties.c
@version 2020.02.05
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

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


/**
@brief Calculate the various properties of the given number and print the data in CSV format to stdout

@param[in] calc_num The number to analyze
@return Void
*/
void calc_properties(const uint64_t calc_num) {
	// Binary Bit Properties
	const uint32_t prop_ffs = (uint32_t)ffs64(calc_num);
	const uint32_t prop_fls = (uint32_t)fls64(calc_num);
	const int32_t prop_ctz = (int32_t)ctz64(calc_num);
	const uint64_t prop_bit_length = bit_length(calc_num);
	const uint32_t prop_pcnt = popcount64(calc_num);
	// Number Theory Properties
	const int32_t prop_is_mersennenumber = (int32_t)ismersennenumber(calc_num);
	const int32_t prop_is_prime = (int32_t)isprime(calc_num);
	const uint64_t prop_unfactorial = unfactorial(calc_num);
	// Operations
	const double prop_sqrt = sqrt((double)calc_num);
	const double prop_cbrt = cbrt((double)calc_num);
	const double prop_triangular_root = triangular_root(calc_num);
	const double prop_hexagonal_root = hexagonal_root(calc_num);
	const double prop_heptagonal_root = heptagonal_root(calc_num);
	const double prop_log2 = log2((double)calc_num);
	const double prop_log10 = log10((double)calc_num);
	// Trigonometry
	const double prop_cos = cos((double)calc_num);
	const double prop_sin = sin((double)calc_num);
	(void)fprintf(
		stdout,
#   if IS_WORDSIZE_64
		"%lu,%u,%u,%d,%lu,%u,%d,%d,%lu,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
#   else
		"%llu,%u,%u,%d,%llu,%u,%d,%d,%llu,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
#   endif
		calc_num, prop_ffs, prop_fls, prop_ctz, prop_bit_length, prop_pcnt, prop_is_mersennenumber, prop_is_prime, prop_unfactorial, prop_sqrt, prop_cbrt, prop_triangular_root, prop_hexagonal_root, prop_heptagonal_root, prop_log2, prop_log10, prop_cos, prop_sin
	);
}


// TODO: Make a matrix struct that will be used to store the values and print the data at the end; This will permit vectorization


noreturn int main(rargc, rargv) {
	if (argc != 1 && argc != 2) {
		puts_err_no_output("Only one or no parameters are accepted!");
		fast_exit(EXIT_FAILURE);
	}
	puts_no_output("Number,FFS,FLS,BitLength,Popcount,IsMersenne,IsPrime,Unfactorial,Sqrt,Cbrt,TriangularRoot,HexagonalRoot,HeptagonalRoot,Log2,Log10,cos,sin");
	if (argc == 2) {  // Calculate the properties of the one given number
		calc_properties((uint64_t)atoull(argv[1]));
		fast_exit(EXIT_SUCCESS);
	}
	// Print the properties of all numbers between 0 and `UINT64_MAX`
	register uint64_t calc_num = UINT64_MAX;
	for (; calc_num; calc_num--) {
		calc_properties(calc_num);
	}
	fast_exit(EXIT_SUCCESS);
}

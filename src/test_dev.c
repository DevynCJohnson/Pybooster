// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief Test code used in MACROS*.h
@file test_dev.c
@version 2018.09.11
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
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
*/


#include "MACROS.h"


#ifdef COMPILER_CLANG
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wformat"
#   pragma clang diagnostic ignored "-Wformat-extra-args"
#elif defined(COMPILER_GNU_GCC)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wformat"
#   pragma GCC diagnostic ignored "-Wformat-extra-args"
#endif


#define START_ERROR   "\x1b[31m"
#define END_ERROR   "\x1b[0m"
#define OPEN_TEST_HEADER   "\n\x1b[1;4;33m======= "
#define CLOSE_TEST_HEADER   " =======\x1b[0m\n\n"
#define OPEN_SUB_TEST_HEADER   "\x1b[1;34m"
#define CLOSE_SUB_TEST_HEADER   END_ERROR
#define DEV_PROMPT_FUNC(func, str)   do { if (prompt_ynq(str)) { putsnl(); func; puts2nl(); } } while (0x0)
#define DEV_TEST_BUF_OUTPUT3(testbuf, testbufsize, func, inval, inparam, info_str, expected_str)   do { bzero(testbuf, testbufsize); do_sync(); func(inval, testbuf, inparam); puts_no_output("* " info_str "; Expect - `" expected_str "` *"); puts_no_output(testbuf); putsnl(); } while (0x0)


/* FUNCTIONS */

/** General Code Tests */
static void test_code(rargv_t _argv[]) {
	puts_no_output(OPEN_TEST_HEADER "TEST CODE" CLOSE_TEST_HEADER);
	// Setup
#   define SIZEOF_TEST_NUM_BUF   64
	char num_buf[SIZEOF_TEST_NUM_BUF] = { 0 };
	// Test atoll() & argv[1]
	puts_no_output("* Test atoll() & argv[1]; Expect - argv[1] *");
	const long long input_num = (long long)atoll(_argv[1]);
	puti((int)input_num);
	putsnl();
	// Test ulltodec()
	puts_no_output("* Test ulltodec(); Expect - `255` *");
	ulltodec(255ULL, num_buf);
	puts_no_output(num_buf);
	putsnl();
	// Test ltodec()
	puts_no_output("* Test ltodec(); Expect - `127` *");
	ltodec(127LL, num_buf);
	puts_no_output(num_buf);
	putsnl();
	// Test utooct()
	puts_no_output("* Test utooct(); Expect - `377` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	utooct(255U, num_buf);
	puts_no_output(num_buf);
	putsnl();
	// Test utohex()
	puts_no_output("* Test utohex(); Expect - `FF` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	utohex(255U, 1, num_buf);
	puts_no_output(num_buf);
	putsnl();
	// Test itohex()
	puts_no_output("* Test itohex(); Expect - `-FF` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	itohex(-255, 1, num_buf);
	puts_no_output(num_buf);
	putsnl();
	// Test dtostr(3.14159)
	puts_no_output("* Test dtostr(3.14159); Expect - `3.14159` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(3.14159, num_buf, 0, 5, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test dtostr(3.1415926535897932384626433832795028841971693993751058209749445923)
	puts_no_output("* Test dtostr(); Expect - `3.1415926535897932384626433832795028841971693993751058209749445923` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(3.1415926535897932384626433832795028841971693993751058209749445923, num_buf, 0, 64, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test dtostr(0.0)
	puts_no_output("* Test dtostr(0.0); Expect - `0.0` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(0.0, num_buf, 0, 1, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test dtostr(+0.0)
	puts_no_output("* Test dtostr(+0.0); Expect - `0.0` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(+0.0, num_buf, 0, 1, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test dtostr(-0.0)
	puts_no_output("* Test dtostr(-0.0); Expect - `-0.0` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(-0.0, num_buf, 0, 1, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test dtostr(NAN)
	puts_no_output("* Test dtostr(NAN); Expect - `nan` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(NAN, num_buf, 0, 1, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test dtostr(NANS)
	puts_no_output("* Test dtostr(NANS); Expect - `-NAN` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(NANS, num_buf, 0, 1, 'F');
	puts_no_output(num_buf);
	putsnl();
	// Test dtostr(INF)
	puts_no_output("* Test dtostr(INF); Expect - `INF` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(INF, num_buf, 0, 1, 'F');
	puts_no_output(num_buf);
	putsnl();
	// Test dtostr(NINF)
	puts_no_output("* Test dtostr(NINF); Expect - `-inf` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(NINF, num_buf, 0, 1, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test dtostr(HUGE_VAL)
	puts_no_output("* Test dtostr(HUGE_VAL); Expect - `inf` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(HUGE_VAL, num_buf, 0, 1, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test dtostr(DBL_EPSILON)
	puts_no_output("* Test dtostr(DBL_EPSILON); Expect - `0.00000000000000022204460492503128603514246415350832` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(DBL_EPSILON, num_buf, 0, 50, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test dtostr(10000.0)
	puts_no_output("* Test dtostr(10000.0); Expect - `10000.0` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(10000.0, num_buf, 0, 1, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test dtostr(10000)
	puts_no_output("* Test dtostr(10000.0); Expect - `10000` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(10000.0, num_buf, 0, 0, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test dtoa()
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, 3.14159, 5, "Test dtoa() using 3.14159 & 5", "3.14158");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, -3.14159, 5, "Test dtoa() using -3.14159 & 5", "-3.14158");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, 3.14159, 3, "Test dtoa() using 3.14159 & 3", "3.141");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, 3.14159, 7, "Test dtoa() using 3.14159 & 7", "3.1415899");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, 233.107, 7, "Test dtoa() using 233.107 & 7", "233.1069999");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, 1025.0077, 7, "Test dtoa() using 1025.0077 & 7", "1025.0077000");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, HUGE, 7, "Test dtoa() using HUGE & 7", "1.0E+300");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, TINY, 7, "Test dtoa() using TINY & 7", "1.0E-300");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, NAN, 7, "Test dtoa() using NAN & 7", "NAN");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, INF, 7, "Test dtoa() using INF & 7", "INF");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, NANS, 7, "Test dtoa() using NANS & 7", "NANS");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, NINF, 7, "Test dtoa() using NINF & 7", "NINF");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, DBL_EPSILON, 20, "Test dtoa() using DBL_EPSILON & 20", "0.00000000000000022204");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, DBL_MIN, 20, "Test dtoa() using DBL_MIN & 20", "0.00000000000000000000");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoa, DBL_TRUE_MIN, 20, "Test dtoa() using DBL_TRUE_MIN & 20", "0.00000000000000000000");
	// Test dtoe()
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoe, PI, 5, "Test dtoe() using PI & 5", "3.14159e0");
	DEV_TEST_BUF_OUTPUT3(num_buf, SIZEOF_TEST_NUM_BUF, dtoe, -3.14159265, 5, "Test dtoe() using -3.14159265 & 5", "-3.14159e0");
	// Test stof()
	puts_no_output("* Test stof(); Expect - `3.14159` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	const char* float_str = "3.14159";
	(void)dtostr((double)stof(float_str), num_buf, 0, 5, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test atof()
	puts_no_output("* Test atof(); Expect - `3.14159` *");
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(atof(float_str), num_buf, 0, 5, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test atof("NaN")
	puts_no_output("* Test atof(\"NaN\"); Expect - `nan` *");
	const char* nan_str = "NaN";
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(atof(nan_str), num_buf, 0, 5, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test atof("inf")
	puts_no_output("* Test atof(\"inf\"); Expect - `inf` *");
	const char* inf_str = "inf";
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(atof(inf_str), num_buf, 0, 5, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test atof("-inf")
	puts_no_output("* Test atof(\"-inf\"); Expect - `-inf` *");
	const char* ninf_str = "-inf";
	bzero(num_buf, SIZEOF_TEST_NUM_BUF);
	(void)dtostr(atof(ninf_str), num_buf, 0, 5, 0);
	puts_no_output(num_buf);
	putsnl();
	// Test isprime()
	puts_no_output("* Test isprime() & puti(); Expect - `0` or `1` *");
	const int bool_prime = islonglongprime(input_num);
	puti(bool_prime);
	putsnl();
	// Test putchar()
	puts_no_output("* Test putchar(); Expect - `$5` *");
	(void)putchar('$');
	(void)putchar('5');
	puts_no_output("\n");
	// Test putc()
	puts_no_output("* Test putc(); Expect - `$5` *");
	(void)putc('$', stdout);
	(void)putc('5', stdout);
	puts_no_output("\n");
	// Test putwc()
	puts_no_output("* Test putwc(); Expect - `$5` *");
	(void)putwc(L'$', stdout);
	(void)putwc(L'5', stdout);
	// End
	puts_no_output("\n");
	return;
}


/** Test strlen functions */
static void test_strlen(void) {
	puts_no_output(OPEN_TEST_HEADER "STRING LENGTH" CLOSE_TEST_HEADER);
	// Tests
	puts_no_output("* Test strlen(\"Test\"); Expect - `4` *");
	puti((int)strlen("Test"));
	putsnl();
	puts_no_output("* Test strlen(\"\"); Expect - `0` *");
	puti((int)strlen(""));
	putsnl();
	puts_no_output("* Test strlen(\"Test\\0 two\"); Expect - `4` *");
	puti((int)strlen("Test\0 two"));
	putsnl();
	puts_no_output("* Test strlen(\"\\U0001F916\"); Expect - `4` *");
	puti((int)strlen("\U0001F916"));
	putsnl();
	puts_no_output("* Test strlen(\"Σ\"); Expect - `2`");
	puti((int)strlen("Σ"));
	putsnl();
	puts_no_output("* Test utf8len(\"\\U0001F916\"); Expect - `4` *");
	puti((int)utf8len("\U0001F916"));
	putsnl();
	puts_no_output("* Test utf8len(\"Σ\"); Expect - `2` *");
	puti((int)utf8len("Σ"));
	putsnl();
	puts_no_output("* Test utf8len(u8\"Σ\"); Expect - `2` *");
	puti((int)utf8len(u8"Σ"));
	putsnl();
	puts_no_output("* Test utf8len(\"\\U000003A3\"); Expect - `2` *");
	puti((int)utf8len("\U000003A3"));
	putsnl();
	puts_no_output("* Test utf32len(U\"Σ\"); Expect - `1` *");
	puti((int)utf32len(U"Σ"));
	putsnl();
	puts_no_output("* Test utf32len(U\"\\U0001F916\"); Expect - `1` *");
	puti((int)utf32len(U"\U0001F916"));
	putsnl();
	// End
	return;
}


/** Test printf() */
static void test_printf(rargv_t _argv[]) {
	puts_no_output(OPEN_TEST_HEADER "PRINTF()" CLOSE_TEST_HEADER);
	// Setup
	int printf_status = 0;
	const int printf_n = 0;
	const size_t printf_szn = 0;
	const size_t size_t_num = (size_t)255;
	const ssize_t ssize_t_num = (ssize_t)-255;
	const ptrdiff_t ptrdiff_t_num = (ptrdiff_t)-257;
	const uintmax_t uintmax_t_num = (uintmax_t)511;
	const intmax_t intmax_t_num = (intmax_t)-511;
	const long long input_num = (long long)atoll(_argv[1]);
	const int bool_prime = islonglongprime(input_num);
	char test_string[25] = { 'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 'c', 'h', 'a', 'r', '[', ']', ' ', 's', 't', 'r', 'i', 'n', 'g', '.', '\0' };
	const char* test_const_string = "This is a const char* string.";
	// Tests
	puts_no_output("* Test %llu & %d; Expect - `Is argv[1] prime = #` *");
	printf_status = printf("Is %llu prime = %d\n", (unsigned long long)input_num, bool_prime);
	puts_no_output("\t- Printf() exit status (should be between 15 & 17):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %zu; Expect - `255` *");
	printf_status = printf("%zu\n", size_t_num);
	puts_no_output("\t- Printf() exit status (should be 4):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %zd; Expect - `-255` *");
	printf_status = printf("%zd\n", ssize_t_num);
	puts_no_output("\t- Printf() exit status (should be 5):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %zi; Expect - `-255` *");
	printf_status = printf("%zi\n", ssize_t_num);
	puts_no_output("\t- Printf() exit status (should be 5):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %ti; Expect - `-257` *");
	printf_status = printf("%ti\n", ptrdiff_t_num);
	puts_no_output("\t- Printf() exit status (should be 5):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %ji & %n; Expect - `-511` *");
	printf_status = printf("%ji\n%n", intmax_t_num, &printf_n);
	puts_no_output("\t- Printf() exit status (should be 5):");
	puti(printf_status);
	puts_no_output("\t- Printf() %n value (should be 5):");
	puti(printf_n);
	putsnl();
	puts_no_output("* Test %ju & %zn; Expect - `511` *");
	printf_status = printf("%ju\n%zn", uintmax_t_num, &printf_szn);
	puts_no_output("\t- Printf() exit status (should be 4):");
	puti(printf_status);
	puts_no_output("\t- Printf() %zn value (should be 4):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %p; Expect an address value *");
	printf_status = printf("%p\n", &uintmax_t_num);
	puts_no_output("\t- Printf() exit status (should be greater than 10):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %%; Expect - `%` *");
	printf_status = printf("%%\n");
	puts_no_output("\t- Printf() exit status (should be 2):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %% & %c; Expect - `%X` *");
	printf_status = printf("%%%c\n", 'X');
	puts_no_output("\t- Printf() exit status (should be 3):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %c, %lc, %llc, & %U; Expect - `W X Y Z` *");
	printf_status = printf("%c %lc %llc %U\n", 'W', L'X', 'Y', U'Z');
	puts_no_output("\t- Printf() exit status (should be 8):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %3U; Expect - `   Z` *");
	printf_status = printf("%3U\n", 'Z');
	puts_no_output("\t- Printf() exit status (should be 5):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %s; Expect - `This is a const char* string.` *");
	printf_status = printf("%s\n", test_const_string);
	puts_no_output("\t- Printf() exit status (should be 30):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %s; Expect - `This is a char[] string.` *");
	printf_status = printf("%s\n", test_string);
	puts_no_output("\t- Printf() exit status (should be 25):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %m, set_errno(), & clr_errno(); Expect - `Stale NFS file handle` *");
	set_errno(ESTALE);
	printf_status = printf("%m\n");
	clr_errno();
	puts_no_output("\t- Printf() exit status (should be 22):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %m & %i; Expect - `101 - Cannot read disk label` *");
	set_errno(ERDLAB);
	printf_status = printf("%i - %m\n", ERDLAB);
	clr_errno();
	puts_no_output("\t- Printf() exit status (should be 29):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %f; Expect - `3` *");
	printf_status = printf("%f\n", 3.14159);
	puts_no_output("\t- Printf() exit status (should be 2):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %.5f; Expect - `3.14159` *");
	printf_status = printf("%.5f\n", 3.14159);
	puts_no_output("\t- Printf() exit status (should be 8):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %d, %b, %x, %X, & %o; Expect - `DEC: 127; BIN: 00000000000000000000000001111111; HEX: 7f; HEX: 7F; OCT: 177;` *");
	printf_status = printf("DEC: %d; BIN: %b; HEX: %x; HEX: %X; OCT: %o;\n", 127, 127, 127, 127, 127);
	puts_no_output("\t- Printf() exit status (should be 77):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %d, %#b, %#x, %#X, & %#o; Expect - `DEC: 126; BIN: 0b00000000000000000000000001111110; HEX: 0x7e; HEX: 0X7E; OCT: 0176;` *");
	printf_status = printf("DEC: %d; BIN: %#b; HEX: %#x; HEX: %#X; OCT: %#o;\n", 126, 126, 126, 126, 126);
	puts_no_output("\t- Printf() exit status (should be 84):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %8d, %8#x, & %8#o; Expect - `DEC:      126; HEX:     0x7e; OCT:     0176;` *");
	printf_status = printf("DEC: %8d; HEX: %8#x; OCT: %8#o;\n", 126, 126, 126);
	puts_no_output("\t- Printf() exit status (should be 45):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %8#d, %16#b, %6#x, & %8#o; Expect - `DEC:    126.0; BIN: 0b00000000000000000000000001111110; HEX:   0x7e; OCT:     0176;` *");
	printf_status = printf("DEC: %8#d; BIN: %16#b; HEX: %6#x; OCT: %8#o;\n", 126, 126, 126, 126);
	puts_no_output("\t- Printf() exit status (should be 84):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %2.8#d, %*#b, %7.3#x, & %*.4#o; Expect - `DEC: 00000126.0; BIN: 0b00000000000000000000000001111110; HEX:   0x07e; OCT:    00176;` *");
	printf_status = printf("DEC: %2.8#d; BIN: %*#b; HEX: %7.3#x; OCT: %*.4#o;\n", 126, 8, 126, 126, 8, 126);
	puts_no_output("\t- Printf() exit status (should be 87):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %.8d %.8X; Expect - `00000255 000000FF` *");
	printf_status = printf("%.8d %.8X\n", 255, 255);
	puts_no_output("\t- Printf() exit status (should be 18):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test %.8d %.0X %O; Expect - `00000255  -377` *");
	printf_status = printf("%.8d %.0X %O\n", 255, 255, -255);
	puts_no_output("\t- Printf() exit status (should be 15):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test string padding; Expect the two columns to be identical *");
	printf(":%s:", "Hello, world!");
	puts("\t\t = \t:Hello, world!:");
	printf(":%15s:", "Hello, world!");
	puts("\t = \t:  Hello, world!:");
	printf(":%.10s:", "Hello, world!");
	puts("\t\t = \t:Hello, wor:");
	printf(":%-10s:", "Hello, world!");
	puts("\t\t = \t:Hello, world!:");
	printf(":%-15s:", "Hello, world!");
	puts("\t = \t:Hello, world!  :");
	printf(":%.15s:", "Hello, world!");
	puts("\t\t = \t:Hello, world!:");
	printf(":%15.10s:", "Hello, world!");
	puts("\t = \t:     Hello, wor:");
	printf(":%-15.10s:", "Hello, world!");
	puts("\t = \t:Hello, wor     :");
	putsnl();
	// End
	putsnl();
	return;
}


/** Test Ctype Functions */
static void test_ctypes(void) {
	puts_no_output(OPEN_TEST_HEADER "CTYPE TESTS" CLOSE_TEST_HEADER);
	BOOLEAN_TEST_RESULTS(_tolower('A'), 'a');
	BOOLEAN_TEST_RESULTS(_tolower('B'), 'b');
	BOOLEAN_TEST_RESULTS(_tolower('a'), 'a');
	BOOLEAN_TEST_RESULTS(_tolower('_'), '_');
	BOOLEAN_TEST_RESULTS(_tolower(' '), ' ');
	BOOLEAN_TEST_RESULTS(_tolower('1'), '1');
	BOOLEAN_TEST_RESULTS(_tolower('!'), '!');
	BOOLEAN_TEST_RESULTS(_tolower('}'), '}');
	BOOLEAN_TEST_RESULTS(_tolower('\n'), '\n');
	BOOLEAN_TEST_RESULTS(_tolower('\0'), '\0');
	BOOLEAN_TEST_RESULTS(_toupper('a'), 'A');
	BOOLEAN_TEST_RESULTS(_toupper('b'), 'B');
	BOOLEAN_TEST_RESULTS(_toupper('A'), 'A');
	BOOLEAN_TEST_RESULTS(_toupper('_'), '_');
	BOOLEAN_TEST_RESULTS(_toupper(' '), ' ');
	BOOLEAN_TEST_RESULTS(_toupper('1'), '1');
	BOOLEAN_TEST_RESULTS(_toupper('!'), '!');
	BOOLEAN_TEST_RESULTS(_toupper('}'), '}');
	BOOLEAN_TEST_RESULTS(_toupper('\n'), '\n');
	BOOLEAN_TEST_RESULTS(_toupper('\0'), '\0');
	BOOLEAN_TEST_RESULTS(invertcase('a'), 'A');
	BOOLEAN_TEST_RESULTS(invertcase('b'), 'B');
	BOOLEAN_TEST_RESULTS(invertcase('A'), 'a');
	BOOLEAN_TEST_RESULTS(invertcase('_'), '_');
	BOOLEAN_TEST_RESULTS(invertcase(' '), ' ');
	BOOLEAN_TEST_RESULTS(invertcase('1'), '1');
	BOOLEAN_TEST_RESULTS(invertcase('!'), '!');
	BOOLEAN_TEST_RESULTS(invertcase('}'), '}');
	BOOLEAN_TEST_RESULTS(invertcase('\n'), '\n');
	BOOLEAN_TEST_RESULTS(invertcase('\0'), '\0');
	BOOLEAN_TEST_RESULTS(alphapos('a'), 1);
	BOOLEAN_TEST_RESULTS(alphapos('A'), 1);
	BOOLEAN_TEST_RESULTS(alphapos('z'), 26);
	BOOLEAN_TEST_RESULTS(alphapos('Z'), 26);
	BOOLEAN_TEST_RESULTS(is_digit('Z'), 0);
	BOOLEAN_TEST_RESULTS(is_digit('a'), 0);
	BOOLEAN_TEST_RESULTS(is_digit('A'), 0);
	BOOLEAN_TEST_RESULTS(is_digit('0'), 1);
	BOOLEAN_TEST_RESULTS(is_digit('1'), 1);
	BOOLEAN_TEST_RESULTS(is_digit('9'), 1);
	BOOLEAN_TEST_RESULTS(ISUPPER('9'), 0);
	BOOLEAN_TEST_RESULTS(ISUPPER('a'), 0);
	BOOLEAN_TEST_RESULTS(ISUPPER('A'), 1);
	BOOLEAN_TEST_RESULTS(ISUPPER('Z'), 1);
	BOOLEAN_TEST_RESULTS(ISUPPER('?'), 0);
	BOOLEAN_TEST_RESULTS(ISUPPER('_'), 0);
	BOOLEAN_TEST_RESULTS(ISUPPER(' '), 0);
	BOOLEAN_TEST_RESULTS(ISUPPER('.'), 0);
	BOOLEAN_TEST_RESULTS(ISUPPER('@'), 0);
	BOOLEAN_TEST_RESULTS(ISUPPER('^'), 0);
	BOOLEAN_TEST_RESULTS(ISUPPER('['), 0);
	BOOLEAN_TEST_RESULTS(ISUPPER('\\'), 0);
	return;
}


/** Test Unicode Support */
static void test_unicode(void) {
	puts_no_output(OPEN_TEST_HEADER "UNICODE SUPPORT" CLOSE_TEST_HEADER);
	// Setup
	int printf_status = 0;
	// Tests
	puts_no_output("* Test printf(\"€Ω\\n\"); Expect - `€Ω` *");
	printf_status = printf("€Ω\n");
	puts_no_output("\t- Printf() exit status (should be 6):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test printf(\"\\xc3\\xa9\\n\"); Expect - `é` *");
	printf_status = printf("\xc3\xa9\n");
	puts_no_output("\t- Printf() exit status (should be 3):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test printf(\"Ӂ = \\U000004C1\\n\"); Expect - `Ӂ = Ӂ` *");
	printf_status = printf("Ӂ = \U000004C1\n");
	puts_no_output("\t- Printf() exit status (should be 8):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test printf(\"%llc\\n\", U'Ӂ'); Expect - `Ӂ` *");
	printf_status = printf("%llc\n", U'Ӂ');
	puts_no_output("\t- Printf() exit status (should be 3):");
	puti(printf_status);
	putsnl();
	puts_no_output("* Test puts(\"Ω\"); Expect - `Ω` *");
	puts_no_output("Ω");
	putsnl();
	puts_no_output("* Test puts(\"€\"); Expect - `€` *");
	puts_no_output("€");
	putsnl();
	puts_no_output("* Test puts(\"\\U000000A5\"); Expect - `¥` *");
	puts_no_output("\U000000A5");
	putsnl();
	puts_no_output("* Test puts() for Unicode v10.0; Expect - `ↂ  ↹  ⋙  ∜  ⌨  ⓱  ☺  🤖  \U0001F9E6` *");
	puts_no_output("ↂ  ↹  ⋙  ∜  ⌨  ⓱  ☺  \U0001F916  \U0001F9E6");
	putsnl();
	puts_no_output("* Test putchar(L'€'); Expect unknown symbol `�` *");
	(void)putchar(L'€');
	puts_no_output("\n");
	puts_no_output("* Test putchar(u'€'); Expect unknown symbol `�` *");
	(void)putchar(u'€');
	puts_no_output("\n");
	puts_no_output("* Test putchar(U'€'); Expect unknown symbol `�` *");
	(void)putchar(U'€');
	puts_no_output("\n");
	puts_no_output("* Test putc(L'€', stdout); Expect unknown symbol `�` *");
	(void)putc(L'€', stdout);
	puts_no_output("\n");
	puts_no_output("* Test putc(u'€', stdout); Expect unknown symbol `�` *");
	(void)putc(u'€', stdout);
	puts_no_output("\n");
	puts_no_output("* Test putc(U'€', stdout); Expect unknown symbol `�` *");
	(void)putc(U'€', stdout);
	puts_no_output("\n");
	puts_no_output("* Test putwc(L'€', stdout); Expect unknown symbol `�` *");
	(void)putwc(L'€', stdout);
	puts_no_output("\n");
	puts_no_output("* Test putwc(u'€', stdout); Expect unknown symbol `�` *");
	(void)putwc(u'€', stdout);
	puts_no_output("\n");
	puts_no_output("* Test putwc(U'€', stdout); Expect unknown symbol `�` *");
	(void)putwc(U'€', stdout);
	putsnl();
	return;
}


/** Display Characters 1-255 */
static void test_display_ansi_characters(void) {
	puts_no_output(OPEN_TEST_HEADER "ANSI SUPPORT" CLOSE_TEST_HEADER);
	for (register int i = 1; i < 256; i++) {
		(void)printf(SET_ANSI_SGR_FG_COLOR(255, 153, 51) "%d:" ANSI_SGR_RESET " %c\n", (int)i, (char)i);
	}
	return;
}


/** Display ANSI SGR Colors */
static void test_ansi_sgr(void) {
	puts_no_output(OPEN_TEST_HEADER "ANSI SGR SUPPORT" CLOSE_TEST_HEADER);
	puts_no_output("style ; foreground ; background\n");
	register int style = 0;
	register int fg, bg;
	for (; style <= 9; style++) {
		for (fg = 30; (fg <= 37) || (fg >= 89 && fg <= 97); fg++) {
			for (bg = 40; (bg <= 47) || (bg >= 99 && bg <= 107); bg++) {
				(void)printf("\x1b[%d;%d;%dm%d;%d;%d \x1b[0m", style, fg, bg, style, fg, bg);
				if (bg == 47) { bg = 99; }
			}
			if (fg == 37) { fg = 89; }
			putsnl();
		}
	}
	return;
}


/** Test Macros Functions */
static void test_macros(void) {
	puts_no_output(OPEN_TEST_HEADER "MACROS TESTS" CLOSE_TEST_HEADER);
	// Macros: Test datatype
	BOOLEAN_TEST_RESULTS(issigned(SHRT_MIN), 1);
	BOOLEAN_TEST_RESULTS(issigned(SHRT_MAX), 1);
	BOOLEAN_TEST_RESULTS(issigned(LLONG_MIN), 1);
	BOOLEAN_TEST_RESULTS(issigned(ULLONG_MAX), 0);
	BOOLEAN_TEST_RESULTS(issigned(0), 1);
	BOOLEAN_TEST_RESULTS(issigned(0ULL), 0);
	BOOLEAN_TEST_RESULTS(__type_is_signed(long), 1);
	BOOLEAN_TEST_RESULTS(__type_is_signed(unsigned long), 0);
	VAL2_TEST_RESULTS(TYPEBITS(LONG_MIN), 32, 64);
	BOOLEAN_TEST_RESULTS(TYPEBITS(float), 32);
	BOOLEAN_TEST_RESULTS(type_min_s(int), INT32_T_MIN);
	BOOLEAN_TEST_RESULTS(type_min_s(char), CHAR_MIN);
	BOOLEAN_TEST_RESULTS(type_max_s(int), INT32_T_MAX);
	BOOLEAN_TEST_RESULTS(type_max_s(long), LONG_MAX);
	BOOLEAN_TEST_RESULTS(type_max_s(short), SHRT_MAX);
	BOOLEAN_TEST_RESULTS(type_max_s(char), CHAR_MAX);
	BOOLEAN_TEST_RESULTS(type_min(int), INT32_T_MIN);
	BOOLEAN_TEST_RESULTS(type_min(char), CHAR_MIN);
	BOOLEAN_TEST_RESULTS(type_max(int), INT32_T_MAX);
	BOOLEAN_TEST_RESULTS(type_max(short), SHRT_MAX);
	BOOLEAN_TEST_RESULTS(type_max(char), CHAR_MAX);
	BOOLEAN_TEST_RESULTS_U(type_min_u(uint32_t), UINT32_T_MIN);
	BOOLEAN_TEST_RESULTS_U(type_min_u(unsigned char), 0);
	BOOLEAN_TEST_RESULTS_U(type_max_u(uint32_t), UINT32_T_MAX);
	BOOLEAN_TEST_RESULTS_U(type_max_u(unsigned char), UCHAR_MAX);
	BOOLEAN_TEST_RESULTS_U(type_min(uint32_t), UINT32_T_MIN);
	BOOLEAN_TEST_RESULTS_U(type_min(unsigned char), 0);
	BOOLEAN_TEST_RESULTS_U(type_max(uint32_t), UINT32_T_MAX);
	BOOLEAN_TEST_RESULTS_U(type_max(unsigned char), UCHAR_MAX);
	BOOLEAN_TEST_RESULTS(is_native_word(long), 1);
	BOOLEAN_TEST_RESULTS(is_native_word(long double), 0);
	BOOLEAN_TEST_RESULTS(pointer_type(long*), 1);
	BOOLEAN_TEST_RESULTS(pointer_type(double), 0);
	BOOLEAN_TEST_RESULTS(TYPE_SIGNED(int), 1);
	BOOLEAN_TEST_RESULTS(TYPE_SIGNED(uint64_t), 0);
	BOOLEAN_TEST_RESULTS(__type_fit_s(char, 3), 1);
	BOOLEAN_TEST_RESULTS(__type_fit_s(int, 3), 1);
	BOOLEAN_TEST_RESULTS(__type_fit_s(int, 1073741824), 1);
	BOOLEAN_TEST_RESULTS(__type_fit_u(unsigned char, 1073741824), 0);
	BOOLEAN_TEST_RESULTS(__type_fit_u(unsigned int, 1073741824), 1);
	BOOLEAN_TEST_RESULTS(__type_fit_u(unsigned int, 36028798092705792), 0);
	BOOLEAN_TEST_RESULTS(__type_fit(char, 3), 1);
	BOOLEAN_TEST_RESULTS(__type_fit(unsigned char, 3), 1);
	BOOLEAN_TEST_RESULTS(__type_fit(int, 3), 1);
	BOOLEAN_TEST_RESULTS(__type_fit(int, 1073741824), 1);
	BOOLEAN_TEST_RESULTS(__type_fit(uint32_t, 1073741824), 1);
	BOOLEAN_TEST_RESULTS(__type_fit(char, 1073741824), 0);
	BOOLEAN_TEST_RESULTS(__type_fit(uint32_t, -1073741824), 0);
	BOOLEAN_TEST_RESULTS(__type_fit(int32_t, -1073741824), 1);
	// Macros: Test bit-twiddling
	BOOLEAN_TEST_RESULTS(FIND_LOWEST_SET_BIT(4), 4);
	BOOLEAN_TEST_RESULTS(FIND_LOWEST_SET_BIT(35684608), 256);
	BOOLEAN_TEST_RESULTS(find_lowest_set_bit(35684608), 9);
	BOOLEAN_TEST_RESULTS(set1bit(3), 8);
	BOOLEAN_TEST_RESULTS(setbit(5, 3), 13);
	BOOLEAN_TEST_RESULTS(setbitfield(2, 8), 508);
	BOOLEAN_TEST_RESULTS(clrbit(16, 4), 0);
	BOOLEAN_TEST_RESULTS(isset(16, 4), 1);
	BOOLEAN_TEST_RESULTS(isclr(32, 7), 1);
	BOOLEAN_TEST_RESULTS(unsetbit(2147516417, 31), 32769);
	BOOLEAN_TEST_RESULTS(UNSETBIT(2147516417, 2147483648), 32769);
	BOOLEAN_TEST_RESULTS(togglebit(2147516417, 31), 32769);
	BOOLEAN_TEST_RESULTS(TOGGLEBIT(2147516417, 2147483648), 32769);
	BOOLEAN_TEST_RESULTS(turnofflsb(2147516424), 2147516416);
	BOOLEAN_TEST_RESULTS(isolatelsb(2147516424), 8);
	BOOLEAN_TEST_RESULTS(propagatelsb(2147516424), 2147516431);
	BOOLEAN_TEST_RESULTS(isolatelsb0bit(2147516424), 1);
	BOOLEAN_TEST_RESULTS(setlsb0bit(1073774601), 1073774603);
	BOOLEAN_TEST_RESULTS(reversebyte(96), 6);
	BOOLEAN_TEST_RESULTS(reversebyte(48), 12);
	BOOLEAN_TEST_RESULTS(swap_odd_and_even_bits(48), 48);
	BOOLEAN_TEST_RESULTS(swap_odd_and_even_bits(80), 160);
	BOOLEAN_TEST_RESULTS(swap_consecutive_pairs(48), 192);
	BOOLEAN_TEST_RESULTS(swap_nibbles(48), 3);
	BOOLEAN_TEST_RESULTS(swap_bytes(48), 12288);
	BOOLEAN_TEST_RESULTS(swap_2byte_long_pairs(48), 3145728);
	BOOLEAN_TEST_RESULTS(has_nullbyte(2048), 1);
	BOOLEAN_TEST_RESULTS(has_nullbyte(33818752), 0);
	BOOLEAN_TEST_RESULTS(has_nullbyte(37750912), 0);
	BOOLEAN_TEST_RESULTS(hasvalue(33818752, 4), 1);
	BOOLEAN_TEST_RESULTS(sex(4), 0);
	BOOLEAN_TEST_RESULTS(sex(-4), -1);
	BOOLEAN_TEST_RESULTS(sex(-255), -1);
	BOOLEAN_TEST_RESULTS(sex(-257), -1);
	BOOLEAN_TEST_RESULTS(set_leading_ones_8bit(2), 192);
	BOOLEAN_TEST_RESULTS(set_leading_ones_8bit(6), 252);
	BOOLEAN_TEST_RESULTS(set_leading_ones_8bit(7), 254);
	// Macros: Test math macros
	BOOLEAN_TEST_RESULTS(abs(3.14159), 3.14159);
	BOOLEAN_TEST_RESULTS(abs(-3.14159), 3.14159);
	BOOLEAN_TEST_RESULTS(abs(-7), 7);
	BOOLEAN_TEST_RESULTS(abs(37), 37);
	BOOLEAN_TEST_RESULTS(abs(8070450532516364288), 8070450532516364288);
	BOOLEAN_TEST_RESULTS(abs(-8070450532516364288), 8070450532516364288);
	BOOLEAN_TEST_RESULTS(CLAMP(37, 3, 7), 7);
	BOOLEAN_TEST_RESULTS(CLAMP(37, 3, 47), 37);
	BOOLEAN_TEST_RESULTS(CLAMP(37, 3, -47), -47);
	BOOLEAN_TEST_RESULTS(CLAMP(3.14159, 3, 4), 3.14159);
	BOOLEAN_TEST_RESULTS(CLAMP(3.14159, 1, 3), 3);
	BOOLEAN_TEST_RESULTS(__ispowerof2(2), 1);
	BOOLEAN_TEST_RESULTS(__ispowerof2(4), 1);
	BOOLEAN_TEST_RESULTS(__ispowerof2(15), 0);
	BOOLEAN_TEST_RESULTS(__ispowerof2(1), 1);
	BOOLEAN_TEST_RESULTS(__ispowerof2(1024), 1);
	BOOLEAN_TEST_RESULTS(powerof2(1024), 1);
	BOOLEAN_TEST_RESULTS(powerof2(15), 0);
	BOOLEAN_TEST_RESULTS(howmany(100, 5), 20);
	BOOLEAN_TEST_RESULTS(are_signs_opposite(100, 5), 0);
	BOOLEAN_TEST_RESULTS(are_signs_opposite(-37, 9), 1);
	BOOLEAN_TEST_RESULTS(P2ROUNDUP(37, 6), 38);
	BOOLEAN_TEST_RESULTS(P2ROUNDUP(38, 6), 38);
	BOOLEAN_TEST_RESULTS(P2ROUNDUP(39, 6), 40);
	BOOLEAN_TEST_RESULTS(_MAX_INT(39, 6), 39);
	BOOLEAN_TEST_RESULTS(_MAX_INT(-7, 37), 37);
	BOOLEAN_TEST_RESULTS(_MIN_INT(39, 6), 6);
	BOOLEAN_TEST_RESULTS(_MIN_INT(-7, 37), -7);
	return;
}


/** Test Generic Macros Functions */
static void test_generic_macros(void) {
	puts_no_output(OPEN_TEST_HEADER "GENERIC MACROS TESTS" CLOSE_TEST_HEADER);
	const UNUSED char* cchar_ptr = "Test";
	register const UNUSED signed short cshrt_var = 3;
	volatile UNUSED float vfloat_var = 3.14159F;
	atomic UNUSED float afloat_var = 3.14159F;
	volatile UNUSED double vdouble_var = 3.14159;
	const UNUSED double cdouble_var = 3.14159;
	BOOLEAN_TEST_RESULTS(IS_CHAR(cchar_ptr), 0);
	BOOLEAN_TEST_RESULTS(IS_STRING(cchar_ptr), 1);
	BOOLEAN_TEST_RESULTS(IS_INT(3), 1);
	BOOLEAN_TEST_RESULTS(IS_SHORT(3), 0);
	BOOLEAN_TEST_RESULTS(IS_SHORT(cshrt_var), 1);
	BOOLEAN_TEST_RESULTS(IS_FLT(3.14159F), 1);
	BOOLEAN_TEST_RESULTS(IS_FLT(3), 0);
	BOOLEAN_TEST_RESULTS(IS_FLT(vfloat_var), 1);
	BOOLEAN_TEST_RESULTS(IS_FLT(afloat_var), 1);
	BOOLEAN_TEST_RESULTS(IS_FLT(vdouble_var), 0);
	BOOLEAN_TEST_RESULTS(IS_DBL(3.14159F), 0);
	BOOLEAN_TEST_RESULTS(IS_DBL(3), 0);
	BOOLEAN_TEST_RESULTS(IS_DBL(vfloat_var), 0);
	BOOLEAN_TEST_RESULTS(IS_DBL(vdouble_var), 1);
	BOOLEAN_TEST_RESULTS(IS_DBL(cdouble_var), 1);
	BOOLEAN_TEST_RESULTS(is_scalar(cchar_ptr), 0);
	BOOLEAN_TEST_RESULTS(is_scalar(cdouble_var), 1);
	return;
}


/** Test Float-point Macros Functions */
static void test_float_points(void) {
	puts_no_output(OPEN_TEST_HEADER "FLOAT-POINT TESTS" CLOSE_TEST_HEADER);
	BOOLEAN_TEST_RESULTS(SIGNF(-3.14159F), 1);
	BOOLEAN_TEST_RESULTS(EXPF(-3.14159F), 128);
	BOOLEAN_TEST_RESULTS(MANTF(-3.14159F), 4788176);
	return;
}


/** List the sizes of various datatypes in bytes */
static void list_data_sizes(void) {
	puts_no_output(OPEN_TEST_HEADER "LIST DATATYPE SIZES" CLOSE_TEST_HEADER);
	puts_no_output(OPEN_SUB_TEST_HEADER "* Basic Datatypes *\n" CLOSE_SUB_TEST_HEADER);
	printf("_Bool: %zu\n", sizeof(_Bool));
	printf("Char: %zu\n", sizeof(char));
	printf("Short Int: %zu\n", sizeof(short));
	printf("Int: %zu\n", sizeof(int));
	printf("Long Int: %zu\n", sizeof(long));
	printf("Long Long Int: %zu\n", sizeof(long long));
	printf("Float: %zu\n", sizeof(float));
	printf("Double: %zu\n", sizeof(double));
#   if SUPPORTS_LONG_DOUBLE
	printf("Long Double: %zu\n", sizeof(long double));
#   endif
#   if SUPPORTS_COMPLEX
	puts_no_output("\n" OPEN_SUB_TEST_HEADER "* Complex Datatypes *" CLOSE_SUB_TEST_HEADER "\n");
	printf("Complex Float: %zu\n", sizeof(complex_float));
	printf("Complex Double: %zu\n", sizeof(complex_double));
#      if SUPPORTS_COMPLEX_LDBL
	printf("Complex Long Double: %zu\n", sizeof(complex_long_double));
#      endif
#   endif
	puts_no_output("\n" OPEN_SUB_TEST_HEADER "* Special Datatypes *" CLOSE_SUB_TEST_HEADER "\n");
	const size_t ptrsize = sizeof(char*);
	printf("size_t: %zu\n", sizeof(size_t));
	printf("ssize_t: %zu\n", sizeof(ssize_t));
	printf("Char*: %zu\n", ptrsize);
	printf("&Address: %zu\n", sizeof(&ptrsize));
	printf("FILE: %zu\n", sizeof(FILE));
	puts_no_output("\n" OPEN_SUB_TEST_HEADER "* Machine Datatypes *" CLOSE_SUB_TEST_HEADER "\n");
	printf("PTRtype: %zu\n", sizeof(PTRtype));
	printf("HWtype: %zu\n", sizeof(HWtype));
	printf("Wtype: %zu\n", sizeof(Wtype));
	printf("DWtype: %zu\n", sizeof(DWtype));
	printf("Unwind: %zu\n", sizeof(_Unwind_Word));
	printf("QItype: %zu\n", sizeof(QItype));
	printf("HItype: %zu\n", sizeof(HItype));
	printf("SItype: %zu\n", sizeof(SItype));
	printf("DItype: %zu\n", sizeof(DItype));
#   if SUPPORTS_TITYPE
	printf("TItype: %zu\n", sizeof(TItype));
#   endif
	printf("SFtype: %zu\n", sizeof(SFtype));
	printf("DFtype: %zu\n", sizeof(DFtype));
#   if SUPPORTS_XFTYPE
	printf("XFtype: %zu\n", sizeof(XFtype));
#   endif
#   if SUPPORTS_TFTYPE
	printf("TFtype: %zu\n", sizeof(TFtype));
#   endif
	return;
}


/** List the ranges of various datatypes */
static void list_data_ranges(void) {
	puts_no_output(OPEN_TEST_HEADER "LIST DATATYPE RANGES" CLOSE_TEST_HEADER);
	// char
	printf("SCHAR_MIN: %hhi\n", SCHAR_MIN);
	printf("SCHAR_MAX: %hhi\n", SCHAR_MAX);
	printf("UCHAR_MAX: %hhu\n", UCHAR_MAX);
	// short
	printf("SHRT_MIN: %hi\n", SHRT_MIN);
	printf("SHRT_MAX: %hi\n", SHRT_MAX);
	printf("USHRT_MAX: %hu\n", USHRT_MAX);
	// int
	printf("INT_MIN: %i\n", INT_MIN);
	printf("INT_MAX: %i\n", INT_MAX);
	printf("UINT_MAX: %u\n", UINT_MAX);
	// long
	printf("LONG_MIN: %li\n", LONG_MIN);
	printf("LONG_MAX: %li\n", LONG_MAX);
	printf("ULONG_MAX: %lu\n", ULONG_MAX);
	// long long
	printf("LLONG_MIN: %lli\n", LLONG_MIN);
	printf("LLONG_MAX: %lli\n", LLONG_MAX);
	printf("ULLONG_MAX: %llu\n", ULLONG_MAX);
	return;
}


#ifdef ARCHX86
/** Test x86 Intrinsics */
static void test_x86_intrinsics(void) {
	puts_no_output(OPEN_TEST_HEADER "X86 INTRINSICS" CLOSE_TEST_HEADER);
	// Setup
	char num_buf[32] = { 0 };
	// Test rdtsc()
	puts_no_output("* Test rdtsc(); Expect unsigned int64_t value *");
	ulltodec(rdtsc(), num_buf);
	puts_no_output(num_buf);
	putsnl();
	// Test rdtscp()
	puts_no_output("* Test rdtscp(); Expect unsigned int64_t value *");
	ulltodec(rdtscp(), num_buf);
	puts_no_output(num_buf);
	putsnl();
	// Test get_vendor_id()
	puts_no_output("* Test get_vendor_id(); Expect a string *");
	puts_no_output(get_vendor_id());
	putsnl();
	// Test get_cpu_stepping()
	puts_no_output("* Test get_cpu_stepping(); Expect an integer *");
	puti(get_cpu_stepping());
	putsnl();
	// Test is_psn_aval()
	puts_no_output("* Test is_psn_aval(); Expect an integer *");
	puti(is_psn_aval());
	putsnl();
	// Test is_movbe_aval()
	puts_no_output("* Test is_movbe_aval(); Expect an integer *");
	puti(is_movbe_aval());
	putsnl();
	// Test is_popcnt_aval()
	puts_no_output("* Test is_popcnt_aval(); Expect an integer *");
	puti(is_popcnt_aval());
	putsnl();
	// Test is_rdrnd_aval()
	puts_no_output("* Test is_rdrnd_aval(); Expect an integer *");
	puti(is_rdrnd_aval());
	putsnl();
	// Test is_sse42_aval()
	puts_no_output("* Test is_sse42_aval(); Expect an integer *");
	puti(is_sse42_aval());
	putsnl();
	// Test is_avx_aval()
	puts_no_output("* Test is_avx_aval(); Expect an integer *");
	puti(is_avx_aval());
	putsnl();
	// Test is_aes_aval()
	puts_no_output("* Test is_aes_aval(); Expect an integer *");
	puti(is_aes_aval());
	putsnl();
	// Test in_place_zero()
	unsigned long long xornum = 255ULL;
	puts_no_output("* Test in_place_zero(); Expect `0` *");
	puti((int)in_place_zero(xornum));
	return;
}
#endif


/** Main Testing Function */
noreturn int main(rargc, rargv) {
	TWO_ARGS_REQUIRED_F;
	START_TIME();  // DEBUG: Time execution
	test_code(argv);
	test_strlen();
	test_printf(argv);
	END_TIME();  // DEBUG: Time execution
	puts2nl();
	do_sync();
	DEV_PROMPT_FUNC(test_ctypes(), "Perform ctype tests?");
	DEV_PROMPT_FUNC(test_unicode(), "Perform Unicode test?");
	DEV_PROMPT_FUNC(test_display_ansi_characters(), "Perform ANSI character display test?");
	DEV_PROMPT_FUNC(test_ansi_sgr(), "Perform ANSI SGR test?");
	DEV_PROMPT_FUNC(test_macros(), "Perform macros tests?");
	DEV_PROMPT_FUNC(test_generic_macros(), "Perform Generic macros tests?");
	DEV_PROMPT_FUNC(test_float_points(), "Perform float-point tests?");
	DEV_PROMPT_FUNC(pause_prompt(), "Perform pause test?");
	DEV_PROMPT_FUNC(wait_progress_indicator(10), "Perform progress indicator test?");
	DEV_PROMPT_FUNC(wait_progress_bar(10), "Perform progress bar test?");
	DEV_PROMPT_FUNC(list_data_sizes(), "List datatype sizes (in bytes)?");
	DEV_PROMPT_FUNC(list_data_ranges(), "List datatype ranges?");
#   ifdef ARCHX86
	DEV_PROMPT_FUNC(test_x86_intrinsics(), "Perform x86 intrinsic tests?");
#   endif
	puts_no_output(ANSI_SGR_FG_BGREEN "TESTS COMPLETE" ANSI_SGR_END "\n\n");
	// Exit
	fast_exit(EXIT_SUCCESS);
}


#ifdef COMPILER_CLANG
#   pragma clang diagnostic pop
#elif defined(COMPILER_GNU_GCC)
#   pragma GCC diagnostic pop
#endif

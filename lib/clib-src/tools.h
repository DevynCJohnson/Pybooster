// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file tools.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Miscellaneous Functions (header)
@version 2016.03.18

@section DESCRIPTION
Various functions that do not fit in other categories.
Such functions include string manipulations, file I/O, boolean tests, etc.

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


#ifndef FILE_TOOLS_SEEN
#define FILE_TOOLS_SEEN


#include "MACROS.h"

#ifdef OSPOSIX
#   include <sys/stat.h>  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_stat.h.html
#endif


/* STD-STRING AND STD-CTYPES ALTERNATIVES */
#ifdef __GNUC__
int islower_ascii(const int x) __attribute__((const, flatten));
int isupper_ascii(const int x) __attribute__((const, flatten));
int isalnumx(const int x) __attribute__((const, flatten));
int isalphax(const int x) __attribute__((const, flatten));
int isasciix(const int x) __attribute__((const, flatten));
int isblankx(const int x) __attribute__((const, flatten));
int iscntrl_ascii(const int x) __attribute__((const, flatten));
int isdigit_ascii(const int x) __attribute__((const, flatten));
int isgraph_ascii(const int x) __attribute__((const, flatten));
int isprintx(const int x) __attribute__((const, flatten));
int ispunct_ascii(const int x) __attribute__((const, flatten));
int isspace_ascii(const int x) __attribute__((const, flatten));
int isxdigit_ascii(const int x) __attribute__((const, flatten));
int tolowerx(const int x) __attribute__((const, flatten));
int toupperx(const int x) __attribute__((const, flatten));
size_t strlenx(const char *__restrict__ str) __attribute__((const, flatten));
size_t strlenx_uint8(const uint8_t *__restrict__ str) __attribute__((const, flatten));
size_t strlen_utf32(const uint32_t *__restrict__ utf32str) __attribute__((const, flatten));
size_t bytelen_utf32(const uint32_t *__restrict__ utf32str) __attribute__((const, flatten));
char *strdupx(const char *__restrict__ s) __attribute__((flatten, nonnull));
char *STPCPY(char *__restrict__ dst, const char *__restrict__ src) __attribute__((flatten, nonnull));
char *STPCPYX(char *__restrict__ dst, const char *__restrict__ src, const size_t srclen) __attribute__((flatten, nonnull));
char *STPNCPY(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen) __attribute__((flatten, nonnull));
char *STRCAT(char *__restrict__ dst, const char *__restrict__ src) __attribute__((flatten, nonnull));
char *STRCATX(char *__restrict__ dst, const char *__restrict__ src, const size_t dstlen, const size_t srclen) __attribute__((flatten, nonnull));
size_t STRLCAT(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen) __attribute__((flatten, nonnull));
size_t STRLCPY(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen) __attribute__((flatten, nonnull));
char *STRNCAT(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen) __attribute__((flatten, nonnull));
char *STRCPY(char *__restrict__ dst, const char *__restrict__ src) __attribute__((flatten, nonnull));
char *STRCPYX(char *__restrict__ dst, const char *__restrict__ src, const size_t srclen) __attribute__((flatten, nonnull));
char *STRNCPY(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen) __attribute__((flatten, nonnull));
char *STRNCPYX(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen, const size_t srclen) __attribute__((flatten, nonnull));
#else
int islower_ascii(const int x);
int isupper_ascii(const int x);
int isalnumx(const int x);
int isalphax(const int x);
int isasciix(const int x);
int isblankx(const int x);
int iscntrl_ascii(const int x);
int isdigit_ascii(const int x);
int isgraph_ascii(const int x);
int isprintx(const int x);
int ispunct_ascii(const int x);
int isspace_ascii(const int x);
int isxdigit_ascii(const int x);
int tolowerx(const int x);
int toupperx(const int x);
size_t strlenx(const char *__restrict__ str);
size_t strlenx_uint8(const uint8_t *__restrict__ str);
size_t strlen_utf32(const uint32_t *__restrict__ utf32str);
size_t bytelen_utf32(const uint32_t *__restrict__ utf32str);
char *strdupx(const char *__restrict__ s);
char *STPCPY(char *__restrict__ dst, const char *__restrict__ src);
char *STPCPYX(char *__restrict__ dst, const char *__restrict__ src, const size_t srclen);
char *STPNCPY(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen);
char *STRCAT(char *__restrict__ dst, const char *__restrict__ src);
char *STRCATX(char *__restrict__ dst, const char *__restrict__ src, const size_t dstlen, const size_t srclen);
size_t STRLCAT(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen);
size_t STRLCPY(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen);
char *STRNCAT(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen);
char *STRCPY(char *__restrict__ dst, const char *__restrict__ src);
char *STRCPYX(char *__restrict__ dst, const char *__restrict__ src, const size_t srclen);
char *STRNCPY(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen);
char *STRNCPYX(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen, const size_t srclen);
#endif
/* FILE IO */
#ifdef __GNUC__
int fileexists(const char *__restrict__ filename) __attribute__((flatten, nonnull));
int filewritable(const char *__restrict__ filename) __attribute__((flatten, nonnull));
ulint getfilesize(const char *__restrict__ filename) __attribute__((flatten, nonnull));
size_t getfilesize_t(const char *__restrict__ filename) __attribute__((flatten, nonnull));
uint64_t filesize64(const char *__restrict__ filename) __attribute__((flatten, nonnull));
char *getfile(const char *__restrict__ filename) __attribute__((flatten, nonnull));
char *getfile_sizet(const char *__restrict__ filename, const size_t filesize) __attribute__((flatten, nonnull));
uint8_t *getbinfile(const char *__restrict__ filename) __attribute__((flatten, nonnull));
uint8_t *getbinfile_sizet(const char *__restrict__ filename, const size_t filesize) __attribute__((flatten, nonnull));
void writefile(const char *__restrict__ filename, uint8_t *data, const size_t filesize) __attribute__((flatten));
void writefilebuf(const char *__restrict__ filename, char *data, const size_t filesize) __attribute__((flatten));
void appendfile(const char *__restrict__ filename, uint8_t *data, const size_t datasize) __attribute__((flatten, nonnull));
void appendfilebuf(const char *__restrict__ filename, char *data, const size_t datasize) __attribute__((flatten, nonnull));
void hide_data_in_file(const char *__restrict__ filename, const uint8_t *__restrict__ data, const size_t datasize) __attribute__((flatten, nonnull));
size_t get_size_of_hidden_data(const char *__restrict__ filename) __attribute__((flatten, nonnull));
uint8_t *get_hidden_data_from_file(const char *__restrict__ filename) __attribute__((flatten, nonnull));
#else
int fileexists(const char *__restrict__ filename);
int filewritable(const char *__restrict__ filename);
ulint getfilesize(const char *__restrict__ filename);
size_t getfilesize_t(const char *__restrict__ filename);
uint64_t filesize64(const char *__restrict__ filename);
char *getfile(const char *__restrict__ filename);
char *getfile_sizet(const char *__restrict__ filename, const size_t filesize);
uint8_t *getbinfile(const char *__restrict__ filename);
uint8_t *getbinfile_sizet(const char *__restrict__ filename, const size_t filesize);
void writefile(const char *__restrict__ filename, uint8_t *data, const size_t filesize);
void writefilebuf(const char *__restrict__ filename, char *data, const size_t filesize);
void appendfile(const char *__restrict__ filename, uint8_t *data, const size_t datasize);
void appendfilebuf(const char *__restrict__ filename, char *data, const size_t datasize);
void hide_data_in_file(const char *__restrict__ filename, const uint8_t *__restrict__ data, const size_t datasize);
size_t get_size_of_hidden_data(const char *__restrict__ filename);
uint8_t *get_hidden_data_from_file(const char *__restrict__ filename);
#endif
/* FILE INTEGRITY */
#ifdef __GNUC__
uint8_t filebitparity64(const char *__restrict__ filename) __attribute__((flatten, nonnull));
uint16_t fileadler16(const char *__restrict__ filename) __attribute__((flatten, nonnull));
uint32_t fileadler32(const char *__restrict__ filename) __attribute__((flatten, nonnull));
uint64_t fileadler64(const char *__restrict__ filename) __attribute__((flatten, nonnull));
uint64_t fileantiadler64(const char *__restrict__ filename) __attribute__((flatten, nonnull));
uint64_t fileantiadler64rev2(const char *__restrict__ filename) __attribute__((flatten, nonnull));
uint16_t filefletcher16(const char *__restrict__ filename) __attribute__((flatten, nonnull));
uint16_t filefletcher16fast(const char *__restrict__ filename) __attribute__((flatten, nonnull));
uint32_t filefletcher32(const char *__restrict__ filename) __attribute__((flatten, nonnull));
uint32_t filefletcher32fast(const char *__restrict__ filename) __attribute__((flatten, nonnull));
uint32_t filecollier32(const char *__restrict__ filename) __attribute__((flatten, nonnull));
#else
uint8_t filebitparity64(const char *__restrict__ filename);
uint16_t fileadler16(const char *__restrict__ filename);
uint16_t filefletcher16fast(const char *__restrict__ filename);
uint32_t fileadler32(const char *__restrict__ filename);
uint64_t fileadler64(const char *__restrict__ filename);
uint64_t fileantiadler64(const char *__restrict__ filename);
uint64_t fileantiadler64rev2(const char *__restrict__ filename);
uint16_t filefletcher16(const char *__restrict__ filename);
uint32_t filefletcher32(const char *__restrict__ filename);
uint32_t filefletcher32fast(const char *__restrict__ filename);
uint32_t filecollier32(const char *__restrict__ filename);
#endif
/* STRING CONVERSIONS */
#ifdef __GNUC__
void lowercasestr(char *__restrict__ str) __attribute__((flatten, nonnull));
void uppercasestr(char *__restrict__ str) __attribute__((flatten, nonnull));
void lowercasestrx(char *__restrict__ str, const size_t len) __attribute__((flatten, nonnull));
void uppercasestrx(char *__restrict__ str, const size_t len) __attribute__((flatten, nonnull));
#else
void lowercasestr(char *__restrict__ str);
void uppercasestr(char *__restrict__ str);
void lowercasestrx(char *__restrict__ str, const size_t len);
void uppercasestrx(char *__restrict__ str, const size_t len);
#endif
/* STRING BOOLEAN TESTS */
#ifdef __GNUC__
int char_in_str(const char *__restrict__ str, const char _char) __attribute__((flatten, nonnull, const));
int str_in_str(const char *__restrict__ str, const char *__restrict__ substr) __attribute__((flatten, nonnull, const));
int space_in_str(const char *__restrict__ str) __attribute__((flatten, nonnull, const));
int isstrlowercase(const char *__restrict__ str) __attribute__((flatten, nonnull, const));
int isstruppercase(const char *__restrict__ str) __attribute__((flatten, nonnull, const));
int isstralnum(const char *__restrict__ str) __attribute__((flatten, nonnull, const));
int isstralpha(const char *__restrict__ str) __attribute__((flatten, nonnull, const));
int isstrnum(const char *__restrict__ str) __attribute__((flatten, nonnull, const));
int isstrgraphical(const char *__restrict__ str) __attribute__((flatten, nonnull, const));
int isstrprintable(const char *__restrict__ str) __attribute__((flatten, nonnull, const));
int isstrpunctuation(const char *__restrict__ str) __attribute__((flatten, nonnull, const));
int isstrwhitespace(const char *__restrict__ str) __attribute__((flatten, nonnull, const));
int isstrhex(const char *__restrict__ str) __attribute__((flatten, nonnull, const));
int isodd(const int num) __attribute__((flatten, const));
int iseven(const int num) __attribute__((flatten, const));
int islongodd(const long num) __attribute__((flatten, const));
int islongeven(const long num) __attribute__((flatten, const));
int isuint64odd(const uint64_t num) __attribute__((flatten, const));
int isuint64even(const uint64_t num) __attribute__((flatten, const));
#else
int char_in_str(const char *__restrict__ str, const char _char);
int str_in_str(const char *__restrict__ str, const char *__restrict__ substr);
int space_in_str(const char *__restrict__ str);
int isstrlowercase(const char *__restrict__ str);
int isstruppercase(const char *__restrict__ str);
int isstralnum(const char *__restrict__ str);
int isstralpha(const char *__restrict__ str);
int isstrnum(const char *__restrict__ str);
int isstrgraphical(const char *__restrict__ str);
int isstrprintable(const char *__restrict__ str);
int isstrpunctuation(const char *__restrict__ str);
int isstrwhitespace(const char *__restrict__ str);
int isstrhex(const char *__restrict__ str);
int isodd(const int num);
int iseven(const int num);
int islongodd(const long num);
int islongeven(const long num);
int isuint64odd(const uint64_t num);
int isuint64even(const uint64_t num);
#endif
/* FIND AND REPLACE/REMOVE */
void inplace_strsub(char *orig_string, const char *__restrict__ find, const char *__restrict__ sub_with);
char *strreplace(char *orig_string, const char *find, const char *replace_with);
char *strreplace_once(char *orig_string, const char *find, const char *replace_with);
char *rmgravequote(char *orig_string);
void strrmquotes(char *line);
/* SYSTEM INFO */
#if (defined(__GNUC__) || defined(__clang__) || defined(__CC_ARM) || defined(__INTEL_COMPILER) || defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__) || defined(__TINYC__))
#   ifdef __GNUC__
const char *getarch(void) __attribute__((returns_nonnull));
const char *getos(void) __attribute__((returns_nonnull));
const char *endianness(void) __attribute__((returns_nonnull));
#      ifdef __ANDROID_API__
int androidapi(void) __attribute__((const));
#      endif
#      ifdef BSD
int bsdversion(void) __attribute__((const));
#      endif
int isandroid(void) __attribute__((const));
int isaix(void) __attribute__((const));
int isptr64bit(void) __attribute__((const));
#   else
const char *getarch(void);
const char *getos(void);
const char *endianness(void);
#      ifdef __ANDROID_API__
int androidapi(void);
#      endif
#      ifdef BSD
int bsdversion(void);
#      endif
int isandroid(void);
int isaix(void);
int isptr64bit(void);
#   endif
#endif
#ifdef OSPOSIX
#   ifdef __GNUC__
char *getsyshostname(void) __attribute__((returns_nonnull));
#   else
char *getsyshostname(void);
#   endif
#endif
/* LIBRARY INFO */
const char *getcompilername(void);
#if (defined(__GNUC__) || defined(__clang__) || defined(__CC_ARM) || defined(__INTEL_COMPILER) || defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__) || defined(__TINYC__))
#   ifdef __GNUC__
const char *getcompilerversion(void) __attribute__((const, returns_nonnull));
#   else
const char *getcompilerversion(void);
#   endif
#endif
#ifdef __GNUC__
long CSTD(void) __attribute__((const));
#   ifdef _POSIX_VERSION
long POSIXSTD(void) __attribute__((const));
#   endif
#   ifdef _XOPEN_VERSION
int SUSVER(void) __attribute__((const));
#   endif
#   ifdef __LSB_VERSION__
int LSBVER(void) __attribute__((const));
#   endif
int islibelf(void) __attribute__((const));
#else
long CSTD(void);
#   ifdef _POSIX_VERSION
long POSIXSTD(void);
#   endif
#   ifdef _XOPEN_VERSION
int SUSVER(void);
#   endif
#   ifdef __LSB_VERSION__
int LSBVER(void);
#   endif
int islibelf(void);
#endif
/* MISCELLANEOUS */
void printline(void);
#ifdef __GNUC__
void xorswap(int *__restrict__ x, int *__restrict__ y) __attribute__((nonnull));
void xorswap_sll(sllint *__restrict__ x, sllint *__restrict__ y) __attribute__((nonnull));
#else
void xorswap(int *__restrict__ x, int *__restrict__ y);
void xorswap_sll(sllint *__restrict__ x, sllint *__restrict__ y);
#endif


#endif

// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file compression.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Compression Functions (header)
@version 2016.03.09

@section DESCRIPTION
This library provides compression and decompression functions

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


#ifndef FILE_COMPRESSION_SEEN
#define FILE_COMPRESSION_SEEN


#include "MACROS.h"

#ifdef OSPOSIX
#   include <sys/stat.h>
#endif
#ifdef __has_include
#   if __has_include(<zlib.h>)
#      include <zlib.h>
#   else
#      error   "<zlib.h> was not found!"
#   endif
#else
#   include <zlib.h>
#endif
#if (defined(MSDOS) || defined(OS2) || defined(OSWINDOWS) || defined(__CYGWIN__))
#  define SET_BINARY_MODE(file)   setmode(fileno((file)), O_BINARY)
#else
#  define SET_BINARY_MODE(file)
#endif
#define CHUNK   (262144)  // 2^18
//#define Z_NO_COMPRESSION   0
//#define Z_BEST_SPEED   1
//#define Z_BEST_COMPRESSION   (
//#define Z_DEFAULT_COMPRESSION   (-1)
//#define zlib_version    zlibVersion()


/* FUNCTIONS */
#ifdef __GNUC__
static ulint getfilesize(const char *filename) __attribute__((flatten));
int zlib_compress_stream(FILE *source, FILE *dest, const int level) __attribute__((flatten));
int zlib_compress_file(char *source_filename, char *dest_filename, const int level) __attribute__((flatten));
int zlib_decompress_stream(FILE *source, FILE *dest) __attribute__((flatten));
int zlib_decompress_file(char *source_filename, char *dest_filename) __attribute__((flatten));
void zlib_err(const int ret) __attribute__((flatten));
#else
static ulint getfilesize(const char *filename);
int zlib_compress_stream(FILE *source, FILE *dest, const int level);
int zlib_compress_file(char *source_filename, char *dest_filename, const int level);
int zlib_decompress_stream(FILE *source, FILE *dest);
int zlib_decompress_file(char *source_filename, char *dest_filename);
void zlib_err(const int ret);
#endif


#endif

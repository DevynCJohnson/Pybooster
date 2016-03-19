// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file chemistry.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Chemistry-related Functions (header)
@version 2016.03.18

@section DESCRIPTION
Chemistry-specific functions that perform calculations or truth-tests

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


#ifndef FILE_CHEMISTRY_SEEN
#define FILE_CHEMISTRY_SEEN


#include "MACROS.h"

#include <math.h>
#include "chemistry_types.h"


/* CONSTANTS */
extern const char elementlist[128][16];
/* FUNCTIONS */
#ifdef __GNUC__
double pka(const double ka) __attribute__((const, flatten));
double pkb(const double kb) __attribute__((const, flatten));
int iselement(const char *__restrict__ name) __attribute__((const, flatten, nonnull));
#else
double pka(const double ka);
double pkb(const double kb);
int iselement(const char *__restrict__ name);
#endif


#endif

// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file fuzzy_logic.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Fuzzy Logic (header)
@version 2016.03.20

@section DESCRIPTION
Light-weight Fuzzy-Logic library and conversions between fuzzy and boolean datatypes

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


#ifndef FILE_FUZZY_LOGIC_SEEN
#define FILE_FUZZY_LOGIC_SEEN


#include "MACROS.h"


/* SPECIAL MACROS */
#define FAND(x, y)  (fuzzymin(2, (x), (y)))
#define FOR(x, y)  (fuzzymax(2, (x), (y)))
#define FNEG(x)  (100 - (x))
#define FNOT(x)  (100 - (x))
#define FNAND(x, y)  (100 - fuzzymin(2, (x), (y)))
#define FNOR(x, y)  (100 - fuzzymax(2, (x), (y)))
#define FXOR(x, y)  (fuzzymin(2, (100 - fuzzymin(2, (x), (y))), fuzzymax(2, (x), (y))))
#define FXNOR(x, y)  (fuzzymin(2, fuzzymin(2, (x), (y)), (100 - (fuzzymax(2, (x), (y))))))
#define FNXOR(x, y)  (fuzzymin(2, fuzzymin(2, (x), (y)), (100 - (fuzzymax(2, (x), (y))))))
/* TYPES */
/** Fuzzy-Logic Datatype (signed integer) */
typedef signed int   fuzzy;
/* VALUES */
extern const fuzzy unknown;  // Unable to process; No known logic
extern const fuzzy undefined;  // Illogical; Has no determined value
extern const fuzzy indeterminate;  // Vague; Has several values; Meaningless
extern const fuzzy false_f;  // False
extern const fuzzy impossible;  // False
extern const fuzzy uncertain;  // Probably false
extern const fuzzy unlikely;  // Higher probability of being false than true
extern const fuzzy possible;  // Could be true or false; either-or
extern const fuzzy likely;  // Higher probability of being true than false
extern const fuzzy certain;  // Probably true
extern const fuzzy true_f;  // True
extern const fuzzy definite;  // True
extern const fuzzy absolutely;  // True
/* FUNCTIONS */
fuzzy bool2fuzzy(const bool logic);
bool fuzzy2bool(const fuzzy logic);
int fuzzymax(const int count, ...);
int fuzzymin(const int count, ...);
int mno(const int count, ...);


#endif

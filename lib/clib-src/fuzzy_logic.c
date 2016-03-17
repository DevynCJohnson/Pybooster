// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file fuzzy_logic.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Fuzzy Logic
@version 2016.03.09

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


#include "fuzzy_logic.h"


/* VALUES */


/** Unable to process; No known logic */
const fuzzy unknown = -100;
/** Illogical; Has no determined value */
const fuzzy undefined = -50;
/** Vague; Has several values; Meaningless */
const fuzzy indeterminate = -1;
/** False */
const fuzzy false_f = 0;
/** False */
const fuzzy impossible = 0;
/** Probably false */
const fuzzy uncertain = 10;
/** Higher probability of being false than true */
const fuzzy unlikely = 25;
/** Could be true or false; either-or */
const fuzzy possible = 50;
/** Higher probability of being true than false */
const fuzzy likely = 75;
/** Probably true */
const fuzzy certain = 90;
/** True */
const fuzzy true_f = 100;
/** True */
const fuzzy definite = 100;
/** True */
const fuzzy absolutely = 100;


/* FUNCTIONS */


/** Convert boolean-logic to fuzzy-logic */
fuzzy bool2fuzzy(const bool logic) {
    if (logic == 0x00) { return false_f; }
    return true_f;
}


/** Convert fuzzy-logic to boolean-logic */
bool fuzzy2bool(const fuzzy logic) {
    return (bool)(logic >= 50);
}


/** Return the largest (maximum) number */
int fuzzymax(const int count, ...) {
    va_list varargs;
    register int ans, i, num;
    va_start(varargs, count);
    ans = va_arg(varargs, int);
    for (i = 1; i < count; ++i) {
        num = va_arg(varargs, int);
        ans = (ans > num ? ans : num);
    }
    va_end(varargs);
    return ans;
}


/** Return the smallest (minimum) number */
int fuzzymin(const int count, ...) {
    va_list varargs;
    register int ans, i, num;
    va_start(varargs, count);
    ans = va_arg(varargs, int);
    for (i = 1; i < count; ++i) {
        num = va_arg(varargs, int);
        ans = (ans < num ? ans : num);
    }
    va_end(varargs);
    return ans;
}


/** Minimal Negation Operator (just one false) - Return result */
int mno(const int count, ...) {
    va_list varargs;
    register int ans = 0x00, x, y, z;
    va_start(varargs, count);
    switch (count) {
        case 1:
            ans = 100 - (int)va_arg(varargs, int);
            break;
        case 2:
            x = va_arg(varargs, int);
            y = va_arg(varargs, int);
            ans = fuzzymax(2, (fuzzymin(2, (100 - x), y)), (fuzzymin(2, x, (100 - y))));
            break;
        case 3:
            x = va_arg(varargs, int);
            y = va_arg(varargs, int);
            z = va_arg(varargs, int);
            ans = fuzzymax(3, (fuzzymin(3, (100 - x), y, z)), (fuzzymin(3, x, (100 - y), z)), (fuzzymin(3, x, y, (100 - z))));
            break;
        default: break;
    }
    va_end(varargs);
    return ans;
}

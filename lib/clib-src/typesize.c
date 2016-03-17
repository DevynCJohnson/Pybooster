// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file typesize.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Get the size (in bytes) of various C data-types
@version 2016.03.09

@section DESCRIPTION
Functions that return the size (in bytes) of commonly used (and rare) C data-types

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


#include "typesize.h"


/* FLOAT STRUCTURE */


#ifdef FLT_RADIX
/** Return the base (radix) of a float */
int floatradix(void) {
    return FLT_RADIX;
}
#endif


/* LIMITS */


/** Return the number of bits that makes a 'char' */
signed int getcharbits(void) {
    return CHAR_BIT;
}


/** Return the minimum value of 'signed char' */
signed int getminsignedcharval(void) {
    return SCHAR_MIN;
}


/** Return the maximum value of 'signed char' */
signed int getmaxsignedcharval(void) {
    return SCHAR_MAX;
}


/** Return the maximum value of 'unsigned char' */
signed int getmaxunsignedcharval(void) {
    return UCHAR_MAX;
}


/** Return the minimum value of 'char' */
signed int getmincharval(void) {
    return CHAR_MIN;
}


/** Return the maximum value of 'char' */
signed int getmaxcharval(void) {
    return CHAR_MAX;
}


/** Return the maximum number of bytes in a multibyte character */
signed int getmaxmbchar(void) {
    return MB_LEN_MAX;
}


/** Return the minimum value of 'short' */
signed long int getminshortval(void) {
    return SHRT_MIN;
}


/** Return the maximum value of 'short' */
signed long int getmaxshortval(void) {
    return SHRT_MAX;
}


/** Return the maximum value of 'unsigned short' */
signed long int getmaxunsignedshortval(void) {
    return USHRT_MAX;
}


/** Return the minimum value of 'int' */
slint getminintval(void) {
    return INT_MIN;
}


/** Return the maximum value of 'int' */
slint getmaxintval(void) {
    return INT_MAX;
}


/** Return the maximum value of 'unsigned int' */
ulint getmaxunsignedintval(void) {
    return UINT_MAX;
}


/** Return the minimum value of 'long int' */
slint getminlongintval(void) {
    return LONG_MIN;
}


/** Return the maximum value of 'long int' */
slint getmaxlongintval(void) {
    return LONG_MAX;
}


/** Return the maximum value of 'unsigned long int' */
ulint getmaxunsignedlongintval(void) {
    return ULONG_MAX;
}


/** Return the minimum value of 'long long int' */
sllint getminlonglongintval(void) {
    return LLONG_MIN;
}


/** Return the maximum value of 'long long int' */
sllint getmaxlonglongintval(void) {
    return LLONG_MAX;
}


/** Return the maximum value of 'unsigned long long int' */
ullint getmaxunsignedlonglongintval(void) {
    return ULLONG_MAX;
}


/** Return the maximum value of 'wchar_t' */
ullint getmaxwchartval(void) {
    return WCHAR_MAX;
}


/** Return the minimum value of 'wchar_t' */
sllint getminwchartval(void) {
    return WCHAR_MIN;
}


/* CHAR */


/** Get the size of char */
unsigned getcharsize(void) {
    return (unsigned)sizeof(char);
}


/** Get the size of signed char */
unsigned getsignedcharsize(void) {
    return (unsigned)sizeof(signed char);
}


/** Get the size of unsigned char */
unsigned getunsignedcharsize(void) {
    return (unsigned)sizeof(unsigned char);
}


/** Get the size of wchar_t */
unsigned getwchartsize(void) {
    return (unsigned)sizeof(wchar_t);
}


/* INT */


/** Get the size of int */
unsigned getintsize(void) {
    return (unsigned)sizeof(int);
}


/** Get the size of signed */
unsigned getsignedsize(void) {
    return (unsigned)sizeof(signed);
}


/** Get the size of signed int */
unsigned getsignedintsize(void) {
    return (unsigned)sizeof(signed int);
}


/** Get the size of unsigned */
unsigned getunsignedsize(void) {
    return (unsigned)sizeof(unsigned);
}


/** Get the size of unsigned int */
unsigned getunsignedintsize(void) {
    return (unsigned)sizeof(unsigned int);
}


/** Get the size of short */
unsigned getshortsize(void) {
    return (unsigned)sizeof(short);
}


/** Get the size of short int */
unsigned getshortintsize(void) {
    return (unsigned)sizeof(short int);
}


/** Get the size of signed short */
unsigned getsignedshortsize(void) {
    return (unsigned)sizeof(signed short);
}


/** Get the size of signed short int */
unsigned getsignedshortintsize(void) {
    return (unsigned)sizeof(signed short int);
}


/** Get the size of unsigned short */
unsigned getunsignedshortsize(void) {
    return (unsigned)sizeof(unsigned short);
}


/** Get the size of unsigned short int */
unsigned getunsignedshortintsize(void) {
    return (unsigned)sizeof(unsigned short int);
}


/** Get the size of wint_t */
unsigned getwinttsize(void) {
    return (unsigned)sizeof(wint_t);
}


/* LONG */


/** Get the size of long */
unsigned getlongsize(void) {
    return (unsigned)sizeof(long);
}


/** Get the size of long int */
unsigned getlongintsize(void) {
    return (unsigned)sizeof(long int);
}


/** Get the size of signed long */
unsigned getsignedlongsize(void) {
    return (unsigned)sizeof(signed long);
}


/** Get the size of signed long int */
unsigned getsignedlongintsize(void) {
    return (unsigned)sizeof(signed long int);
}


/** Get the size of unsigned long */
unsigned getunsignedlongsize(void) {
    return (unsigned)sizeof(unsigned long);
}


/** Get the size of unsigned long int */
unsigned getunsignedlongintsize(void) {
    return (unsigned)sizeof(unsigned long int);
}


/** Get the size of long long */
unsigned getlonglongsize(void) {
    return (unsigned)sizeof(long long);
}


/** Get the size of long long int */
unsigned getlonglongintsize(void) {
    return (unsigned)sizeof(long long int);
}


/** Get the size of signed long long int */
unsigned getsignedlonglongsize(void) {
    return (unsigned)sizeof(signed long long int);
}


/** Get the size of signed long long */
unsigned getsignedlonglongintsize(void) {
    return (unsigned)sizeof(signed long long);
}


/** Get the size of unsigned long long */
unsigned getunsignedlonglongsize(void) {
    return (unsigned)sizeof(unsigned long long);
}


/** Get the size of unsigned long long int */
unsigned getunsignedlonglongintsize(void) {
    return (unsigned)sizeof(unsigned long long int);
}


/* FLOAT */


/** Get the size of float */
unsigned getfloatsize(void) {
    return (unsigned)sizeof(float);
}


#ifdef __float80
/** Get the size of __float80 */
unsigned getfloat80size(void) {
    return (unsigned)sizeof(__float80);
}
#endif


#ifdef __float128
/** Get the size of __float128 */
unsigned getfloat128size(void) {
    return (unsigned)sizeof(__float128);
}
#endif


/* DOUBLE */


/** Get the size of double */
unsigned getdoublesize(void) {
    return (unsigned)sizeof(double);
}


/** Get the size of long double */
unsigned getlongdoublesize(void) {
    return (unsigned)sizeof(long double);
}


/* COMPLEX */


/** Get the size of float _Imaginary (1.0Fi) */
unsigned getfloatimaginarysize(void) {
    return (unsigned)sizeof((__extension__ 1.0Fi));
}


/** Get the size of double _Imaginary (1.0i) */
unsigned getdoubleimaginarysize(void) {
    return (unsigned)sizeof((__extension__ 1.0i));
}


/** Get the size of long double _Imaginary (1.0Li) */
unsigned getlongdoubleimaginarysize(void) {
    return (unsigned)sizeof((__extension__ 1.0Li));
}


/** Get the size of float complex */
unsigned getcomplexsize(void) {
    return (unsigned)sizeof(float complex);
}


/** Get the size of float complex */
unsigned getfloatcomplexsize(void) {
    return (unsigned)sizeof(float complex);
}


/** Get the size of double complex */
unsigned getdoublecomplexsize(void) {
    return (unsigned)sizeof(double complex);
}


/** Get the size of long double complex */
unsigned getlongdoublecomplexsize(void) {
    return (unsigned)sizeof(long double complex);
}


/* POINTERS */


/** Get the size of ptr */
unsigned getptrsize(void) {
    return (unsigned)sizeof(char*);
}


/** Get the size of ptrdiff_t */
unsigned getptrdifftsize(void) {
    return (unsigned)sizeof(ptrdiff_t);
}


/* MISC */


/** Get the size of quaternion */
unsigned getquaternionsize(void) {
    return (unsigned)sizeof(struct { double R, i, j, k; });
}


#ifndef __MUSL__
/** Get the size of FILE */
unsigned getFILEsize(void) {
    return (unsigned)sizeof(FILE);
}
#endif


/** Get the size of EOF */
unsigned geteofsize(void) {
    return (unsigned)sizeof(EOF);
}


/** Get the size of WEOF */
unsigned getweofsize(void) {
    return (unsigned)sizeof(WEOF);
}


/** Get the size of bool */
unsigned getboolsize(void) {
    return (unsigned)sizeof(bool);
}


/** Get the size of size_t */
unsigned getsizetsize(void) {
    return (unsigned)sizeof(size_t);
}


#ifdef SYS_TYPES_INCLUDED
/** Get the size of clock_t */
unsigned getclocktsize(void) {
    return (unsigned)sizeof(clock_t);
}


/** Get the size of dev_t */
unsigned getdevtsize(void) {
    return (unsigned)sizeof(dev_t);
}


/** Get the size of gid_t */
unsigned getgidtsize(void) {
    return (unsigned)sizeof(gid_t);
}


/** Get the size of nlink_t */
unsigned getnlinktsize(void) {
    return (unsigned)sizeof(nlink_t);
}


/** Get the size of fsblkcnt_t */
unsigned getfsblkcnttsize(void) {
    return (unsigned)sizeof(fsblkcnt_t);
}


/** Get the size of fsfilcnt_t */
unsigned getfsfilcnttsize(void) {
    return (unsigned)sizeof(fsfilcnt_t);
}


/** Get the size of off_t */
unsigned getofftsize(void) {
    return (unsigned)sizeof(off_t);
}
#endif

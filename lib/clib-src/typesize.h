// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file typesize.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Get the size (in bytes) of various C data-types (header)
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


#ifndef FILE_TYPESIZE_SEEN
#define FILE_TYPESIZE_SEEN


#include "MACROS.h"


/* FLOAT STRUCTURE */
#ifdef FLT_RADIX
int floatradix(void);
#endif
/* LIMITS */
signed int getcharbits(void);
signed int getminsignedcharval(void);
signed int getmaxsignedcharval(void);
signed int getmaxunsignedcharval(void);
signed int getmincharval(void);
signed int getmaxcharval(void);
signed int getmaxmbchar(void);
signed long int getminshortval(void);
signed long int getmaxshortval(void);
signed long int getmaxunsignedshortval(void);
slint getminintval(void);
slint getmaxintval(void);
ulint getmaxunsignedintval(void);
slint getminlongintval(void);
slint getmaxlongintval(void);
ulint getmaxunsignedlongintval(void);
sllint getminlonglongintval(void);
sllint getmaxlonglongintval(void);
ullint getmaxunsignedlonglongintval(void);
ullint getmaxwchartval(void);
sllint getminwchartval(void);
/* CHAR */
unsigned getcharsize(void);
unsigned getsignedcharsize(void);
unsigned getunsignedcharsize(void);
unsigned getwchartsize(void);
unsigned getwinttsize(void);
/* INT */
unsigned getintsize(void);
unsigned getsignedsize(void);
unsigned getsignedintsize(void);
unsigned getunsignedsize(void);
unsigned getunsignedintsize(void);
unsigned getshortsize(void);
unsigned getshortintsize(void);
unsigned getsignedshortsize(void);
unsigned getsignedshortintsize(void);
unsigned getunsignedshortsize(void);
unsigned getunsignedshortintsize(void);
/* LONG */
unsigned getlongintsize(void);
unsigned getsignedlongsize(void);
unsigned getsignedlongintsize(void);
unsigned getunsignedlongsize(void);
unsigned getunsignedlongintsize(void);
unsigned getlongsize(void);
unsigned getlonglongsize(void);
unsigned getlonglongintsize(void);
unsigned getsignedlonglongsize(void);
unsigned getsignedlonglongintsize(void);
unsigned getunsignedlonglongsize(void);
unsigned getunsignedlonglongintsize(void);
/* FLOAT */
unsigned getfloatsize(void);
#ifdef __float80
unsigned getfloat80size(void);
#endif
#ifdef __float128
unsigned getfloat128size(void);
#endif
/* DOUBLE */
unsigned getdoublesize(void);
unsigned getlongdoublesize(void);
/* COMPLEX */
unsigned getfloatimaginarysize(void);
unsigned getdoubleimaginarysize(void);
unsigned getlongdoubleimaginarysize(void);
unsigned getcomplexsize(void);
unsigned getfloatcomplexsize(void);
unsigned getdoublecomplexsize(void);
unsigned getlongdoublecomplexsize(void);
/* POINTERS */
unsigned getptrsize(void);
unsigned getptrdifftsize(void);
/* MISC */
unsigned getquaternionsize(void);
#ifndef __MUSL__
unsigned getFILEsize(void);
#endif
unsigned geteofsize(void);
unsigned getweofsize(void);
unsigned getboolsize(void);
unsigned getsizetsize(void);
#ifdef SYS_TYPES_INCLUDED
unsigned getclocktsize(void);
unsigned getdevtsize(void);
unsigned getgidtsize(void);
unsigned getnlinktsize(void);
unsigned getfsblkcnttsize(void);
unsigned getfsfilcnttsize(void);
unsigned getofftsize(void);
#endif


#endif

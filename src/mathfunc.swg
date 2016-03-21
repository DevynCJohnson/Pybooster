// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file mathfunc.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@brief SWIG wrapper for mathfunc.c
@version 2016.03.21
*/


/* SWIG Renaming */


/* %rename(NEWNAME) ORIG_NAME; */


/* Header files and function declarations */


%module mathfunc
%{
/*
%include "mathfunc.h"
#include <math.h>
*/
#include "MACROS.h"

#ifdef __GNUC__
unsigned int fib(const unsigned int num) __attribute__((const, flatten));
#else
unsigned int fib(const unsigned int num);
#endif

%}


/* SWIG Declarations */


unsigned int fib(const unsigned int num);

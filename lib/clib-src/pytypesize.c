// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file pytypesize.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Get the size (in bytes) of various C data-types
@version 2016.03.18

@section DESCRIPTION
This is a Python3 module that uses functions from typesize.c
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


#include "PY_MACROS.h"
#include "typesize.h"

#define MODNAME   "typesize"
#define MODINIT   PyMODINIT_FUNC PyInit_typesize(void)
MODINIT __attribute__((flatten));


/* FUNCTION DEFINITIONS */


/* FLOAT STRUCTURE */
#ifdef FLT_RADIX
static PyObject *typesize_floatradix(void);
#endif
/* CHAR */
static PyObject *typesize_getcharsize(void);
static PyObject *typesize_getsignedcharsize(void);
static PyObject *typesize_getunsignedcharsize(void);
/* INT */
static PyObject *typesize_getintsize(void);
static PyObject *typesize_getsignedsize(void);
static PyObject *typesize_getsignedintsize(void);
static PyObject *typesize_getunsignedsize(void);
static PyObject *typesize_getunsignedintsize(void);
static PyObject *typesize_getshortsize(void);
static PyObject *typesize_getshortintsize(void);
static PyObject *typesize_getsignedshortsize(void);
static PyObject *typesize_getsignedshortintsize(void);
static PyObject *typesize_getunsignedshortsize(void);
static PyObject *typesize_getunsignedshortintsize(void);
/* LONG */
static PyObject *typesize_getlongsize(void);
static PyObject *typesize_getlongintsize(void);
static PyObject *typesize_getsignedlongsize(void);
static PyObject *typesize_getsignedlongintsize(void);
static PyObject *typesize_getunsignedlongsize(void);
static PyObject *typesize_getunsignedlongintsize(void);
static PyObject *typesize_getlonglongsize(void);
static PyObject *typesize_getlonglongintsize(void);
static PyObject *typesize_getsignedlonglongsize(void);
static PyObject *typesize_getsignedlonglongintsize(void);
static PyObject *typesize_getunsignedlonglongsize(void);
static PyObject *typesize_getunsignedlonglongintsize(void);
/* FLOAT */
static PyObject *typesize_getfloatsize(void);
#ifdef __float80
static PyObject *typesize_getfloat80size(void);
#endif
#ifdef __float128
static PyObject *typesize_getfloat128size(void);
#endif
/* DOUBLE */
static PyObject *typesize_getdoublesize(void);
static PyObject *typesize_getlongdoublesize(void);
/* COMPLEX */
static PyObject *typesize_getfloatimaginarysize(void);
static PyObject *typesize_getdoubleimaginarysize(void);
static PyObject *typesize_getlongdoubleimaginarysize(void);
static PyObject *typesize_getfloatcomplexsize(void);
static PyObject *typesize_getdoublecomplexsize(void);
static PyObject *typesize_getlongdoublecomplexsize(void);
/* POINTERS */
static PyObject *typesize_getptrsize(void);
static PyObject *typesize_getptrdifftsize(void);
/* MISC */
static PyObject *typesize_getquaternionsize(void);
static PyObject *typesize_geteofsize(void);
static PyObject *typesize_getweofsize(void);
static PyObject *typesize_getboolsize(void);
static PyObject *typesize_getsizetsize(void);
#ifdef SYS_TYPES_INCLUDED
static PyObject *typesize_getclocktsize(void);
static PyObject *typesize_getdevtsize(void);
static PyObject *typesize_getgidtsize(void);
static PyObject *typesize_getnlinktsize(void);
static PyObject *typesize_getfsblkcnttsize(void);
static PyObject *typesize_getfsfilcnttsize(void);
static PyObject *typesize_getofftsize(void);
#endif


/* DOCSTRINGS */


static char module_docstring[128] =
    "Get the size (in bytes) of various C data-types as well as data limits and more";
/* FLOAT STRUCTURE */
#ifdef FLT_RADIX
PyDoc_STRVAR(typesize_floatradix_docstring,
    "floatradix() -> int\nReturn the base (radix) of a float");
#endif
/* CHAR */
PyDoc_STRVAR(typesize_getcharsize_docstring,
    "getcharsize() -> int\nGet the size of char");
PyDoc_STRVAR(typesize_getsignedcharsize_docstring,
    "getsignedcharsize() -> int\nGet the size of signed char");
PyDoc_STRVAR(typesize_getunsignedcharsize_docstring,
    "getunsignedcharsize() -> int\nGet the size of unsigned char");
/* INT */
PyDoc_STRVAR(typesize_getintsize_docstring,
    "getintsize() -> int\nGet the size of int");
PyDoc_STRVAR(typesize_getsignedsize_docstring,
    "getsignedsize() -> int\nGet the size of signed");
PyDoc_STRVAR(typesize_getsignedintsize_docstring,
    "getsignedintsize() -> int\nGet the size of signed int");
PyDoc_STRVAR(typesize_getunsignedsize_docstring,
    "getunsignedsize() -> int\nGet the size of unsigned");
PyDoc_STRVAR(typesize_getunsignedintsize_docstring,
    "getunsignedintsize() -> int\nGet the size of unsigned int");
PyDoc_STRVAR(typesize_getshortsize_docstring,
    "getshortsize() -> int\nGet the size of short");
PyDoc_STRVAR(typesize_getshortintsize_docstring,
    "getshortintsize() -> int\nGet the size of short int");
PyDoc_STRVAR(typesize_getsignedshortsize_docstring,
    "getsignedshortsize() -> int\nGet the size of signed short");
PyDoc_STRVAR(typesize_getsignedshortintsize_docstring,
    "getsignedshortintsize() -> int\nGet the size of signed short int");
PyDoc_STRVAR(typesize_getunsignedshortsize_docstring,
    "getunsignedshortsize() -> int\nGet the size of unsigned short");
PyDoc_STRVAR(typesize_getunsignedshortintsize_docstring,
    "getunsignedshortintsize() -> int\nGet the size of unsigned short int");
/* LONG */
PyDoc_STRVAR(typesize_getlongsize_docstring,
    "getlongsize() -> int\nGet the size of int");
PyDoc_STRVAR(typesize_getlongintsize_docstring,
    "getlongintsize() -> int\nGet the size of long int");
PyDoc_STRVAR(typesize_getsignedlongsize_docstring,
    "getsignedlongsize() -> int\nGet the size of signed long");
PyDoc_STRVAR(typesize_getsignedlongintsize_docstring,
    "getsignedlongintsize() -> int\nGet the size of signed long int");
PyDoc_STRVAR(typesize_getunsignedlongsize_docstring,
    "getunsignedlongsize() -> int\nGet the size of unsigned long");
PyDoc_STRVAR(typesize_getunsignedlongintsize_docstring,
    "getunsignedlongintsize() -> int\nGet the size of unsigned long int");
PyDoc_STRVAR(typesize_getlonglongsize_docstring,
    "getlonglongsize() -> int\nGet the size of long long");
PyDoc_STRVAR(typesize_getlonglongintsize_docstring,
    "getlonglongintsize() -> int\nGet the size of long long int");
PyDoc_STRVAR(typesize_getsignedlonglongsize_docstring,
    "getsignedlonglongsize() -> int\nGet the size of signed long long");
PyDoc_STRVAR(typesize_getsignedlonglongintsize_docstring,
    "getsignedlonglongintsize() -> int\nGet the size of signed long long int");
PyDoc_STRVAR(typesize_getunsignedlonglongsize_docstring,
    "getunsignedlonglongsize() -> int\nGet the size of unsigned long long");
PyDoc_STRVAR(typesize_getunsignedlonglongintsize_docstring,
    "getunsignedlonglongintsize() -> int\nGet the size of unsigned long long int");
/* FLOAT */
PyDoc_STRVAR(typesize_getfloatsize_docstring,
    "getfloatsize() -> int\nGet the size of float");
#ifdef __float80
PyDoc_STRVAR(typesize_getfloat80size_docstring,
    "getfloat80size() -> int\nGet the size of __float80");
#endif
#ifdef __float128
PyDoc_STRVAR(typesize_getfloat128size_docstring,
    "getfloat128size() -> int\nGet the size of __float128");
#endif
/* DOUBLE */
PyDoc_STRVAR(typesize_getdoublesize_docstring,
    "getdoublesize() -> int\nGet the size of double");
PyDoc_STRVAR(typesize_getlongdoublesize_docstring,
    "getlongdoublesize() -> int\nGet the size of long double");
/* COMPLEX */
PyDoc_STRVAR(typesize_getfloatimaginarysize_docstring,
    "getfloatimaginarysize() -> int\nGet the size of float _Imaginary (1.0Fi)");
PyDoc_STRVAR(typesize_getdoubleimaginarysize_docstring,
    "getdoubleimaginarysize() -> int\nGet the size of double _Imaginary (1.0i)");
PyDoc_STRVAR(typesize_getlongdoubleimaginarysize_docstring,
    "getlongdoubleimaginarysize() -> int\nGet the size of long double _Imaginary (1.0Li)");
PyDoc_STRVAR(typesize_getfloatcomplexsize_docstring,
    "getfloatcomplexsize() -> int\nGet the size of float complex");
PyDoc_STRVAR(typesize_getdoublecomplexsize_docstring,
    "getdoublecomplexsize() -> int\nGet the size of double complex");
PyDoc_STRVAR(typesize_getlongdoublecomplexsize_docstring,
    "getlongdoublecomplexsize() -> int\nGet the size of long double complex");
/* POINTERS */
PyDoc_STRVAR(typesize_getptrsize_docstring,
    "getptrsize() -> int\nGet the size of ptr");
PyDoc_STRVAR(typesize_getptrdifftsize_docstring,
    "getptrdifftsize() -> int\nGet the size of ptrdiff_t");
/* MISC */
PyDoc_STRVAR(typesize_getquaternionsize_docstring,
    "getquaternionsize() -> int\nGet the size of quaternion");
PyDoc_STRVAR(typesize_geteofsize_docstring,
    "geteofsize() -> int\nGet the size of EOF");
PyDoc_STRVAR(typesize_getweofsize_docstring,
    "getweofsize() -> int\nGet the size of WEOF");
PyDoc_STRVAR(typesize_getboolsize_docstring,
    "getboolsize() -> int\nGet the size of bool");
PyDoc_STRVAR(typesize_getsizetsize_docstring,
    "getsizetsize() -> int\nGet the size of size_t");
#ifdef SYS_TYPES_INCLUDED
PyDoc_STRVAR(typesize_getclocktsize_docstring,
    "getclocktsize() -> int\nGet the size of clock_t");
PyDoc_STRVAR(typesize_getdevtsize_docstring,
    "getdevtsize() -> int\nGet the size of dev_t");
PyDoc_STRVAR(typesize_getgidtsize_docstring,
    "getgidtsize() -> int\nGet the size of gid_t");
PyDoc_STRVAR(typesize_getnlinktsize_docstring,
    "getnlinktsize() -> int\nGet the size of nlink_t");
PyDoc_STRVAR(typesize_getfsblkcnttsize_docstring,
    "getfsblkcnttsize() -> int\nGet the size of fsblkcnt_t");
PyDoc_STRVAR(typesize_getfsfilcnttsize_docstring,
    "getfsfilcnttsize() -> int\nGet the size of fsfilcnt_t");
PyDoc_STRVAR(typesize_getofftsize_docstring,
    "getofftsize() -> int\nGet the size of off_t");
#endif


/* MODULE SPECIFICATION */


static PyMethodDef module_methods[64] = {  // Method Table
    /* FLOAT STRUCTURE */
#   ifdef FLT_RADIX
    {"floatradix", (PyCFunction)typesize_floatradix, METH_NOARGS, typesize_floatradix_docstring},
#   endif
    /* CHAR */
    {"getcharsize", (PyCFunction)typesize_getcharsize, METH_NOARGS, typesize_getcharsize_docstring},
    {"getsignedcharsize", (PyCFunction)typesize_getsignedcharsize, METH_NOARGS, typesize_getsignedcharsize_docstring},
    {"getunsignedcharsize", (PyCFunction)typesize_getunsignedcharsize, METH_NOARGS, typesize_getunsignedcharsize_docstring},
    /* INT */
    {"getintsize", (PyCFunction)typesize_getintsize, METH_NOARGS, typesize_getintsize_docstring},
    {"getsignedsize", (PyCFunction)typesize_getsignedsize, METH_NOARGS, typesize_getsignedsize_docstring},
    {"getsignedintsize", (PyCFunction)typesize_getsignedintsize, METH_NOARGS, typesize_getsignedintsize_docstring},
    {"getunsignedsize", (PyCFunction)typesize_getunsignedsize, METH_NOARGS, typesize_getunsignedsize_docstring},
    {"getunsignedintsize", (PyCFunction)typesize_getunsignedintsize, METH_NOARGS, typesize_getunsignedintsize_docstring},
    {"getshortsize", (PyCFunction)typesize_getshortsize, METH_NOARGS, typesize_getshortsize_docstring},
    {"getshortintsize", (PyCFunction)typesize_getshortintsize, METH_NOARGS, typesize_getshortintsize_docstring},
    {"getsignedshortsize", (PyCFunction)typesize_getsignedshortsize, METH_NOARGS, typesize_getsignedshortsize_docstring},
    {"getsignedshortintsize", (PyCFunction)typesize_getsignedshortintsize, METH_NOARGS, typesize_getsignedshortintsize_docstring},
    {"getunsignedshortsize", (PyCFunction)typesize_getunsignedshortsize, METH_NOARGS, typesize_getunsignedshortsize_docstring},
    {"getunsignedshortintsize", (PyCFunction)typesize_getunsignedshortintsize, METH_NOARGS, typesize_getunsignedshortintsize_docstring},
    /* LONG */
    {"getlongsize", (PyCFunction)typesize_getlongsize, METH_NOARGS, typesize_getlongsize_docstring},
    {"getlongintsize", (PyCFunction)typesize_getlongintsize, METH_NOARGS, typesize_getlongintsize_docstring},
    {"getsignedlongsize", (PyCFunction)typesize_getsignedlongsize, METH_NOARGS, typesize_getsignedlongsize_docstring},
    {"getsignedlongintsize", (PyCFunction)typesize_getsignedlongintsize, METH_NOARGS, typesize_getsignedlongintsize_docstring},
    {"getunsignedlongsize", (PyCFunction)typesize_getunsignedlongsize, METH_NOARGS, typesize_getunsignedlongsize_docstring},
    {"getunsignedlongintsize", (PyCFunction)typesize_getunsignedlongintsize, METH_NOARGS, typesize_getunsignedlongintsize_docstring},
    {"getlonglongsize", (PyCFunction)typesize_getlonglongsize, METH_NOARGS, typesize_getlonglongsize_docstring},
    {"getlonglongintsize", (PyCFunction)typesize_getlonglongintsize, METH_NOARGS, typesize_getlonglongintsize_docstring},
    {"getsignedlonglongsize", (PyCFunction)typesize_getsignedlonglongsize, METH_NOARGS, typesize_getsignedlonglongsize_docstring},
    {"getsignedlonglongintsize", (PyCFunction)typesize_getsignedlonglongintsize, METH_NOARGS, typesize_getsignedlonglongintsize_docstring},
    {"getunsignedlonglongsize", (PyCFunction)typesize_getunsignedlonglongsize, METH_NOARGS, typesize_getunsignedlonglongsize_docstring},
    {"getunsignedlonglongintsize", (PyCFunction)typesize_getunsignedlonglongintsize, METH_NOARGS, typesize_getunsignedlonglongintsize_docstring},
    /* FLOAT */
    {"getfloatsize", (PyCFunction)typesize_getfloatsize, METH_NOARGS, typesize_getfloatsize_docstring},
#   ifdef __float80
    {"getfloat80size", (PyCFunction)typesize_getfloat80size, METH_NOARGS, typesize_getfloat80size_docstring},
#   endif
#   ifdef __float128
    {"getfloat128size", (PyCFunction)typesize_getfloat128size, METH_NOARGS, typesize_getfloat128size_docstring},
#   endif
    /* DOUBLE */
    {"getdoublesize", (PyCFunction)typesize_getdoublesize, METH_NOARGS, typesize_getdoublesize_docstring},
    {"getlongdoublesize", (PyCFunction)typesize_getlongdoublesize, METH_NOARGS, typesize_getlongdoublesize_docstring},
    /* COMPLEX */
    {"getfloatimaginarysize", (PyCFunction)typesize_getfloatimaginarysize, METH_NOARGS, typesize_getfloatimaginarysize_docstring},
    {"getdoubleimaginarysize", (PyCFunction)typesize_getdoubleimaginarysize, METH_NOARGS, typesize_getdoubleimaginarysize_docstring},
    {"getlongdoubleimaginarysize", (PyCFunction)typesize_getlongdoubleimaginarysize, METH_NOARGS, typesize_getlongdoubleimaginarysize_docstring},
    {"getfloatcomplexsize", (PyCFunction)typesize_getfloatcomplexsize, METH_NOARGS, typesize_getfloatcomplexsize_docstring},
    {"getdoublecomplexsize", (PyCFunction)typesize_getdoublecomplexsize, METH_NOARGS, typesize_getdoublecomplexsize_docstring},
    {"getlongdoublecomplexsize", (PyCFunction)typesize_getlongdoublecomplexsize, METH_NOARGS, typesize_getlongdoublecomplexsize_docstring},
    /* POINTERS */
    {"getptrsize", (PyCFunction)typesize_getptrsize, METH_NOARGS, typesize_getptrsize_docstring},
    {"getptrdifftsize", (PyCFunction)typesize_getptrdifftsize, METH_NOARGS, typesize_getptrdifftsize_docstring},
    /* MISC */
    {"getquaternionsize", (PyCFunction)typesize_getquaternionsize, METH_NOARGS, typesize_getquaternionsize_docstring},
    {"geteofsize", (PyCFunction)typesize_geteofsize, METH_NOARGS, typesize_geteofsize_docstring},
    {"getweofsize", (PyCFunction)typesize_getweofsize, METH_NOARGS, typesize_getweofsize_docstring},
    {"getboolsize", (PyCFunction)typesize_getboolsize, METH_NOARGS, typesize_getboolsize_docstring},
    {"getsizetsize", (PyCFunction)typesize_getsizetsize, METH_NOARGS, typesize_getsizetsize_docstring},
#   ifdef SYS_TYPES_INCLUDED
    {"getclocktsize", (PyCFunction)typesize_getclocktsize, METH_NOARGS, typesize_getclocktsize_docstring},
    {"getdevtsize", (PyCFunction)typesize_getdevtsize, METH_NOARGS, typesize_getdevtsize_docstring},
    {"getgidtsize", (PyCFunction)typesize_getgidtsize, METH_NOARGS, typesize_getgidtsize_docstring},
    {"getnlinktsize", (PyCFunction)typesize_getnlinktsize, METH_NOARGS, typesize_getnlinktsize_docstring},
    {"getfsblkcnttsize", (PyCFunction)typesize_getfsblkcnttsize, METH_NOARGS, typesize_getfsblkcnttsize_docstring},
    {"getfsfilcnttsize", (PyCFunction)typesize_getfsfilcnttsize, METH_NOARGS, typesize_getfsfilcnttsize_docstring},
    {"getofftsize", (PyCFunction)typesize_getofftsize, METH_NOARGS, typesize_getofftsize_docstring},
#   endif
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef module = {  // Module Definition
    PyModuleDef_HEAD_INIT,
    MODNAME,  // Module name
    module_docstring,  // Module docstring
    -1,  // Module size
    module_methods,  // Module methods
    NULL,  // Module reload
    NULL,  // Module traverse
    NULL,  // Module clear
    NULL  // Module free
};


/**
From http://www.cplusplus.com/reference/cfloat/

A floating-point number is composed of four elements:

 * SIGN: either negative or non-negative
 * BASE (RADIX): which expresses the different numbers that can be represented with a single digit (2 for binary, 10 for decimal, 16 for hexadecimal, and so on)
 * SIGNIFICAND (MANTISSA): which is a series of digits of the aforementioned base. The number of digits in this series is what is known as precision.
 * EXPONENT (CHARACTERISTIC or SCALE): which represents the offset of the significand, affecting the value in the following way ->
 * value of floating-point = SIGNIFICAND * (BASE ^ EXPONENT)
*/
MODINIT {  // Initialize module
    PyObject *m;
    m = PyModule_Create(&module);
#   ifndef NOAUTHOR
    PyModule_AddStringConstant(m, "__author__", __author__);
#   endif
#   ifndef NOVERSION
    PyModule_AddStringConstant(m, "__version__", __version__);
#   endif
    // FLOAT-POINTS
#   ifdef FLT_RADIX
    PyModule_AddObject(m, "FLT_RADIX", int2int((FLT_RADIX)));  // Base for all floating-point types
    PyModule_AddObject(m, "FLT_MANT_DIG", int2int((FLT_MANT_DIG)));  // Precision of significand, i.e. the number of digits that conform the significand
    PyModule_AddObject(m, "DBL_MANT_DIG", int2int((DBL_MANT_DIG)));  // Precision of significand, i.e. the number of digits that conform the significand
    PyModule_AddObject(m, "LDBL_MANT_DIG", int2int((LDBL_MANT_DIG)));  // Precision of significand, i.e. the number of digits that conform the significand
    PyModule_AddObject(m, "FLT_DIG ", int2int((FLT_DIG )));  // Number of decimal digits that can be rounded into a floating-point and back without change in the number of decimal digits
    PyModule_AddObject(m, "DBL_DIG", int2int((DBL_DIG)));  // Number of decimal digits that can be rounded into a floating-point and back without change in the number of decimal digits
    PyModule_AddObject(m, "LDBL_DIG", int2int((LDBL_DIG)));  // Number of decimal digits that can be rounded into a floating-point and back without change in the number of decimal digits
    PyModule_AddObject(m, "FLT_MIN_EXP", int2int((FLT_MIN_EXP)));  // Minimum negative integer value for the exponent that generates a normalized floating-point number
    PyModule_AddObject(m, "DBL_MIN_EXP", int2int((DBL_MIN_EXP)));  // Minimum negative integer value for the exponent that generates a normalized floating-point number
    PyModule_AddObject(m, "LDBL_MIN_EXP", int2int((LDBL_MIN_EXP)));  // Minimum negative integer value for the exponent that generates a normalized floating-point number
    PyModule_AddObject(m, "FLT_MIN_10_EXP", int2int((FLT_MIN_10_EXP)));  // Minimum negative integer value for the exponent of a base-10 expression that would generate a normalized floating-point number
    PyModule_AddObject(m, "DBL_MIN_10_EXP", int2int((DBL_MIN_10_EXP)));  // Minimum negative integer value for the exponent of a base-10 expression that would generate a normalized floating-point number
    PyModule_AddObject(m, "LDBL_MIN_10_EXP", int2int((LDBL_MIN_10_EXP)));  // Minimum negative integer value for the exponent of a base-10 expression that would generate a normalized floating-point number
    PyModule_AddObject(m, "FLT_MAX_EXP", long2int((FLT_MAX_EXP)));  // Maximum integer value for the exponent that generates a normalized floating-point number
    PyModule_AddObject(m, "DBL_MAX_EXP ", long2int((DBL_MAX_EXP )));  // Maximum integer value for the exponent that generates a normalized floating-point number
    PyModule_AddObject(m, "LDBL_MAX_EXP", long2int((LDBL_MAX_EXP)));  // Maximum integer value for the exponent that generates a normalized floating-point number
    PyModule_AddObject(m, "FLT_MAX_10_EXP", long2int((FLT_MAX_10_EXP)));  // Maximum integer value for the exponent of a base-10 expression that would generate a normalized floating-point number
    PyModule_AddObject(m, "DBL_MAX_10_EXP", long2int((DBL_MAX_10_EXP)));  // Maximum integer value for the exponent of a base-10 expression that would generate a normalized floating-point number
    PyModule_AddObject(m, "LDBL_MAX_10_EXP", long2int((LDBL_MAX_10_EXP)));  // Maximum integer value for the exponent of a base-10 expression that would generate a normalized floating-point number
    PyModule_AddObject(m, "FLT_MAX", float2float(((double)FLT_MAX)));  // Maximum finite representable floating-point number
    PyModule_AddObject(m, "DBL_MAX ", double2float((DBL_MAX )));  // Maximum finite representable floating-point number
    //PyModule_AddObject(m, "LDBL_MAX", double2float((LDBL_MAX)));  // Maximum finite representable floating-point number
    PyModule_AddObject(m, "FLT_EPSILON", double2float((FLT_EPSILON)));  // Difference between 1 and the least value greater than 1 that is representable
    PyModule_AddObject(m, "DBL_EPSILON", double2float((DBL_EPSILON)));  // Difference between 1 and the least value greater than 1 that is representable
    PyModule_AddObject(m, "LDBL_EPSILON", double2float((LDBL_EPSILON)));  // Difference between 1 and the least value greater than 1 that is representable
    PyModule_AddObject(m, "FLT_MIN", double2float((FLT_MIN)));  // Minimum representable floating-point number
    PyModule_AddObject(m, "DBL_MIN", double2float((DBL_MIN)));  // Minimum representable floating-point number
    //PyModule_AddObject(m, "LDBL_MIN", double2float((LDBL_MIN)));  // Minimum representable floating-point number
    PyModule_AddObject(m, "FLT_ROUNDS", long2int((FLT_ROUNDS)));
    PyModule_AddObject(m, "FLT_EVAL_METHOD", ulint2int((FLT_EVAL_METHOD)));
    PyModule_AddObject(m, "DECIMAL_DIG", ulint2int((DECIMAL_DIG)));
#   endif
    // SIZES
    PyModule_AddObject(m, "INT_SIZE", size2int(sizeof(int)));
    PyModule_AddObject(m, "LONG_LONG_SIZE", size2int(sizeof(long long)));
    PyModule_AddObject(m, "FLOAT_SIZE", size2int(sizeof(float)));
    PyModule_AddObject(m, "DOUBLE_SIZE", size2int(sizeof(double)));
    PyModule_AddObject(m, "LONG_DOUBLE_SIZE", size2int(sizeof(long double)));
    // LIMITS
    PyModule_AddObject(m, "CHAR_BIT", int2int(CHAR_BIT));
    PyModule_AddObject(m, "SCHAR_MIN", char2int(SCHAR_MIN));
    PyModule_AddObject(m, "SCHAR_MAX", char2int(SCHAR_MAX));
    PyModule_AddObject(m, "UCHAR_MAX", uchar2int(UCHAR_MAX));
    PyModule_AddObject(m, "CHAR_MIN", char2int(CHAR_MIN));
    PyModule_AddObject(m, "CHAR_MAX", uchar2int(CHAR_MAX));
    PyModule_AddObject(m, "MB_LEN_MAX", int2int(MB_LEN_MAX));
    PyModule_AddObject(m, "SHRT_MIN", short2int(SHRT_MIN));
    PyModule_AddObject(m, "SHRT_MAX", short2int(SHRT_MAX));
    PyModule_AddObject(m, "USHRT_MAX", ushort2int(USHRT_MAX));
    PyModule_AddObject(m, "INT_MIN", int2int(INT_MIN));
    PyModule_AddObject(m, "INT_MAX", int2int(INT_MAX));
    PyModule_AddObject(m, "UINT_MAX", uint2int(UINT_MAX));
    PyModule_AddObject(m, "LONG_MIN", long2int(LONG_MIN));
    PyModule_AddObject(m, "LONG_MAX", long2int(LONG_MAX));
    PyModule_AddObject(m, "ULONG_MAX", ulint2int(ULONG_MAX));
    PyModule_AddObject(m, "LLONG_MIN", ll2int(LLONG_MIN));
    PyModule_AddObject(m, "LLONG_MAX", ll2int(LLONG_MAX));
    PyModule_AddObject(m, "ULLONG_MAX", ull2int(ULLONG_MAX));
    PyModule_AddObject(m, "WCHAR_MAX", ull2int(WCHAR_MAX));
    PyModule_AddObject(m, "WCHAR_MIN", ll2int(WCHAR_MIN));
    PyModule_AddObject(m, "RAND_MAX", int2int(RAND_MAX));
    PyModule_AddObject(m, "TMP_MAX", int2int(TMP_MAX));
    PyModule_AddObject(m, "L_tmpnam", int2int(L_tmpnam));
    PyModule_AddObject(m, "FOPEN_MAX", int2int(FOPEN_MAX));
    PyModule_AddObject(m, "FILENAME_MAX", int2int(FILENAME_MAX));
    PyModule_AddObject(m, "BUFSIZ", int2int(BUFSIZ));
    PyModule_AddObject(m, "INTMAX_MIN", ll2int(INTMAX_MIN));
    PyModule_AddObject(m, "INTMAX_MAX", ll2int(INTMAX_MAX));
    PyModule_AddObject(m, "UINTMAX_MAX", ull2int(UINTMAX_MAX));
    PyModule_AddObject(m, "INT8_MIN", int2int(INT8_MIN));
    PyModule_AddObject(m, "INT16_MIN", int2int(INT16_MIN));
    PyModule_AddObject(m, "INT32_MIN", int2int(INT32_MIN));
    PyModule_AddObject(m, "INT64_MIN", ll2int(INT64_MIN));
    PyModule_AddObject(m, "INT8_MAX", int2int(INT8_MAX));
    PyModule_AddObject(m, "INT16_MAX", int2int(INT16_MAX));
    PyModule_AddObject(m, "INT32_MAX", long2int(INT32_MAX));
    PyModule_AddObject(m, "INT64_MAX", ll2int(INT64_MAX));
    PyModule_AddObject(m, "UINT8_MAX", uint2int(UINT8_MAX));
    PyModule_AddObject(m, "UINT16_MAX", uint2int(UINT16_MAX));
    PyModule_AddObject(m, "UINT32_MAX", uint2int(UINT32_MAX));
    PyModule_AddObject(m, "UINT64_MAX", ull2int(UINT64_MAX));
    PyModule_AddObject(m, "INTPTR_MIN", ll2int(INTPTR_MIN));
    PyModule_AddObject(m, "INTPTR_MAX", ll2int(INTPTR_MAX));
    PyModule_AddObject(m, "UINTPTR_MAX", ull2int(UINTPTR_MAX));
    PyModule_AddObject(m, "SIZE_MAX", ull2int(SIZE_MAX));
    PyModule_AddObject(m, "PTRDIFF_MIN", ll2int(PTRDIFF_MIN));
    PyModule_AddObject(m, "PTRDIFF_MAX", ull2int(PTRDIFF_MAX));
    PyModule_AddObject(m, "SIG_ATOMIC_MIN", int2int(SIG_ATOMIC_MIN));
    PyModule_AddObject(m, "SIG_ATOMIC_MAX", int2int(SIG_ATOMIC_MAX));
    PyModule_AddObject(m, "WINT_MIN", int2int(WINT_MIN));
    PyModule_AddObject(m, "WINT_MAX", int2int(WINT_MAX));
    if (m == (PyObject *)NULL) return NULL;
    return m;
}


/* C CODE */


/* FLOAT STRUCTURE */


#ifdef FLT_RADIX
static PyObject *typesize_floatradix(void) {
    return int2int(((int)FLT_RADIX));
}
#endif


/* CHAR */


static PyObject *typesize_getcharsize(void) {
    return size2int(sizeof(char));
}


static PyObject *typesize_getsignedcharsize(void) {
    return size2int(sizeof(signed char));
}


static PyObject *typesize_getunsignedcharsize(void) {
    return size2int(sizeof(unsigned char));
}


/* INT */


static PyObject *typesize_getintsize(void) {
    return size2int(sizeof(int));
}


static PyObject *typesize_getsignedsize(void) {
    return size2int(sizeof(signed));
}


static PyObject *typesize_getsignedintsize(void) {
    return size2int(sizeof(signed int));
}


static PyObject *typesize_getunsignedsize(void) {
    return size2int(sizeof(unsigned));
}


static PyObject *typesize_getunsignedintsize(void) {
    return size2int(sizeof(unsigned int));
}


static PyObject *typesize_getshortsize(void) {
    return size2int(sizeof(short));
}


static PyObject *typesize_getshortintsize(void) {
    return size2int(sizeof(short int));
}


static PyObject *typesize_getsignedshortsize(void) {
    return size2int(sizeof(signed short));
}


static PyObject *typesize_getsignedshortintsize(void) {
    return size2int(sizeof(signed short int));
}


static PyObject *typesize_getunsignedshortsize(void) {
    return size2int(sizeof(unsigned short));
}


static PyObject *typesize_getunsignedshortintsize(void) {
    return size2int(sizeof(unsigned short int));
}


/* LONG */


static PyObject *typesize_getlongsize(void) {
    return size2int(sizeof(long));
}


static PyObject *typesize_getlongintsize(void) {
    return size2int(sizeof(long int));
}


static PyObject *typesize_getsignedlongsize(void) {
    return size2int(sizeof(signed long));
}


static PyObject *typesize_getsignedlongintsize(void) {
    return size2int(sizeof(signed long int));
}


static PyObject *typesize_getunsignedlongsize(void) {
    return size2int(sizeof(unsigned long));
}


static PyObject *typesize_getunsignedlongintsize(void) {
    return size2int(sizeof(unsigned long int));
}


static PyObject *typesize_getlonglongsize(void) {
    return size2int(sizeof(long long));
}


static PyObject *typesize_getlonglongintsize(void) {
    return size2int(sizeof(long long int));
}


static PyObject *typesize_getsignedlonglongsize(void) {
    return size2int(sizeof(signed long long int));
}


static PyObject *typesize_getsignedlonglongintsize(void) {
    return size2int(sizeof(signed long long));
}


static PyObject *typesize_getunsignedlonglongsize(void) {
    return size2int(sizeof(unsigned long long));
}


static PyObject *typesize_getunsignedlonglongintsize(void) {
    return size2int(sizeof(unsigned long long int));
}


/* FLOAT */


static PyObject *typesize_getfloatsize(void) {
    return size2int(sizeof(float));
}


#ifdef __float80
static PyObject *typesize_getfloat80size(void) {
    return size2int(sizeof(__float80));
}
#endif


#ifdef __float128
static PyObject *typesize_getfloat128size(void) {
    return size2int(sizeof(__float128));
}
#endif


/* DOUBLE */


static PyObject *typesize_getdoublesize(void) {
    return size2int(sizeof(double));
}


static PyObject *typesize_getlongdoublesize(void) {
    return size2int(sizeof(long double));
}


/* COMPLEX */


static PyObject *typesize_getfloatimaginarysize(void) {
    return size2int(sizeof((__extension__ 1.0Fi)));
}


static PyObject *typesize_getdoubleimaginarysize(void) {
    return size2int(sizeof((__extension__ 1.0i)));
}


static PyObject *typesize_getlongdoubleimaginarysize(void) {
    return size2int(sizeof((__extension__ 1.0Li)));
}


static PyObject *typesize_getfloatcomplexsize(void) {
    return size2int(sizeof(float complex));
}


static PyObject *typesize_getdoublecomplexsize(void) {
    return size2int(sizeof(double complex));
}


static PyObject *typesize_getlongdoublecomplexsize(void) {
    return size2int(sizeof(long double complex));
}


/* POINTERS */


static PyObject *typesize_getptrsize(void) {
    return size2int(sizeof(char*));
}


static PyObject *typesize_getptrdifftsize(void) {
    return size2int(sizeof(ptrdiff_t));
}


/* MISC */


static PyObject *typesize_getquaternionsize(void) {
    return size2int(sizeof(struct { double R, i, j, k; }));
}


static PyObject *typesize_geteofsize(void) {
    return size2int(sizeof(EOF));
}


static PyObject *typesize_getweofsize(void) {
    return size2int(sizeof(WEOF));
}


static PyObject *typesize_getboolsize(void) {
    return size2int(sizeof(bool));
}


static PyObject *typesize_getsizetsize(void) {
    return size2int(sizeof(size_t));
}


#ifdef SYS_TYPES_INCLUDED


static PyObject *typesize_getclocktsize(void) {
    return size2int(sizeof(clock_t));
}


static PyObject *typesize_getdevtsize(void) {
    return size2int(sizeof(dev_t));
}


static PyObject *typesize_getgidtsize(void) {
    return size2int(sizeof(gid_t));
}


static PyObject *typesize_getnlinktsize(void) {
    return size2int(sizeof(nlink_t));
}


static PyObject *typesize_getfsblkcnttsize(void) {
    return size2int(sizeof(fsblkcnt_t));
}


static PyObject *typesize_getfsfilcnttsize(void) {
    return size2int(sizeof(fsfilcnt_t));
}


static PyObject *typesize_getofftsize(void) {
    return size2int(sizeof(off_t));
}


#endif

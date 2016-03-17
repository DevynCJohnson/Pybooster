// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file PY_MACROS.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Standard Python Header Macros (header)
@version 2016.03.09

@section DESCRIPTION
This file defines constants used by Python modules that are coded in C.
All C-coded Python modules must include this header file.

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


/* MACROS CHECKS */

#ifdef __MUSL__
#   error   musl is not supported!
#endif

#ifndef __MODULE_VERSION__
#   error   __MODULE_VERSION__ is missing! Use -D__MODULE_VERSION__=%DATE%
#endif


// Ignore warnings that only the Python developers can repair
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Wswitch-default"
#ifdef __clang__
#   pragma GCC diagnostic ignored "-Wuninitialized"
#endif


/* MACROS */

#include "MACROS.h"

#include <Python.h>

#define __author__   "Devyn Collier Johnson"
#define __version__   __MODULE_VERSION__


#if (defined(__GNUC__) && !defined(__clang__))  // Hard-code some optimizations
#   pragma GCC optimize (3)
#   pragma GCC optimize ("fast-math")
#   pragma GCC optimize ("no-exceptions")
#   pragma GCC optimize ("unroll-loops")
#   pragma GCC optimize ("wrapv")
#elif defined(__clang__)
#   pragma clang optimize on
#elif defined(__INTEL_COMPILER)
#   pragma intel optimization_level 3
#endif


/* ALIASES */

/* MISC */
#define SELFARGS   PyObject *self, PyObject *args
#define FUNCARGS   PyObject *Py_UNUSED(self), PyObject *args
/* BOOLEAN TESTS */
#define isFloat(x)   (PyFloat_CheckExact((x)))  // Is PyFloatObject
#define isComplex(x)   (PyComplex_Check((x)))  // Is PyComplexObject
#define isLong(x)   (PyLong_CheckExact((x)))  // Is PyLongObject
/* ERROR MESSAGES */
#define ERR_2ARGS   PyErr_SetString(PyExc_ValueError, "Function expected two arguments.")
#define ERR_3ARGS   PyErr_SetString(PyExc_ValueError, "Function expected three arguments.")
#define ERR_4ARGS   PyErr_SetString(PyExc_ValueError, "Function expected four arguments.")
#define ERR_5ARGS   PyErr_SetString(PyExc_ValueError, "Function expected five arguments.")
#define ERR_6ARGS   PyErr_SetString(PyExc_ValueError, "Function expected six arguments.")
#define ERR_2TUP   PyErr_SetString(PyExc_TypeError, "Function expected two tuples.")
#define ERR_2NUMTUP   PyErr_SetString(PyExc_TypeError, "Function expected two numbers per tuple.")
#define ERR_2FLOAT   PyErr_SetString(PyExc_TypeError, "Function expected two floats.")
#define ERR_3FLOAT   PyErr_SetString(PyExc_TypeError, "Function expected three floats.")
#define ERR_POSITIVE_INT   PyErr_SetString(PyExc_ValueError, "Function expected a positive integer.")
#define ERR_LARGE_NUM   PyErr_SetString(PyExc_ValueError, "The given value is too large.")
/* ERROR TESTING */
#define ERROR_TRIGGER   (!PyErr_Occurred())
#define ERROR_OCCURRED   (PyErr_Occurred())
#define ERROR_TEST   if (PyErr_Occurred())
#define MATH_ERROR(x, y)   if ((x) == (y)) PyErr_SetString(PyExc_ValueError, "ERROR: Invalid number!");
/* TEST ARGUMENTS */
#define ASSERT_STRING_ARG(x)   if (!PyArg_ParseTuple(args, "s", &((x)))) return NULL
#define ASSERT_2STRING_ARG(x, y)   if (!PyArg_ParseTuple(args, "ss", &((x)), &((y)))) return NULL
#define ASSERT_3STRING_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "sss", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4STRING_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "ssss", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_STRINGNULL_ARG(x)   if (!PyArg_ParseTuple(args, "z", &((x)))) return NULL
#define ASSERT_2STRINGNULL_ARG(x, y)   if (!PyArg_ParseTuple(args, "zz", &((x)), &((y)))) return NULL
#define ASSERT_3STRINGNULL_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "zzz", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4STRINGNULL_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "zzzz", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_BYTESLIKE_ARG(x)   if (!PyArg_ParseTuple(args, "y", &((x)))) return NULL
#define ASSERT_2BYTESLIKE_ARG(x, y)   if (!PyArg_ParseTuple(args, "yy", &((x)), &((y)))) return NULL
#define ASSERT_3BYTESLIKE_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "yyy", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4BYTESLIKE_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "yyyy", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_BYTESOBJECT_ARG(x)   if (!PyArg_ParseTuple(args, "S", &((x)))) return NULL
#define ASSERT_2BYTESOBJECT_ARG(x, y)   if (!PyArg_ParseTuple(args, "SS", &((x)), &((y)))) return NULL
#define ASSERT_3BYTESOBJECT_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "SSS", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4BYTESOBJECT_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "SSSS", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_BYTEARRAY_ARG(x)   if (!PyArg_ParseTuple(args, "Y", &((x)))) return NULL
#define ASSERT_2BYTEARRAY_ARG(x, y)   if (!PyArg_ParseTuple(args, "YY", &((x)), &((y)))) return NULL
#define ASSERT_3BYTEARRAY_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "YYY", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4BYTEARRAY_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "YYYY", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_UNICODE_ARG(x)   if (!PyArg_ParseTuple(args, "u", &((x)))) return NULL
#define ASSERT_2UNICODE_ARG(x, y)   if (!PyArg_ParseTuple(args, "uu", &((x)), &((y)))) return NULL
#define ASSERT_3UNICODE_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "uuu", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4UNICODE_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "uuuu", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_UNICODENULL_ARG(x)   if (!PyArg_ParseTuple(args, "Z", &((x)))) return NULL
#define ASSERT_2UNICODENULL_ARG(x, y)   if (!PyArg_ParseTuple(args, "ZZ", &((x)), &((y)))) return NULL
#define ASSERT_3UNICODENULL_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "ZZZ", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4UNICODENULL_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "ZZZZ", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_UNICODEOBJECT_ARG(x)   if (!PyArg_ParseTuple(args, "U", &((x)))) return NULL
#define ASSERT_2UNICODEOBJECT_ARG(x, y)   if (!PyArg_ParseTuple(args, "UU", &((x)), &((y)))) return NULL
#define ASSERT_3UNICODEOBJECT_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "UUU", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4UNICODEOBJECT_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "UUUU", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_FLOAT_ARG(x)   if (!PyArg_ParseTuple(args, "f", &((x)))) return NULL
#define ASSERT_2FLOAT_ARG(x, y)   if (!PyArg_ParseTuple(args, "ff", &((x)), &((y)))) return NULL
#define ASSERT_3FLOAT_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "fff", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4FLOAT_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "ffff", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_DOUBLE_ARG(x)   if (!PyArg_ParseTuple(args, "d", &((x)))) return NULL
#define ASSERT_2DOUBLE_ARG(x, y)   if (!PyArg_ParseTuple(args, "dd", &((x)), &((y)))) return NULL
#define ASSERT_3DOUBLE_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "ddd", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4DOUBLE_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "dddd", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_COMPLEX_ARG(x)   if (!PyArg_ParseTuple(args, "D", &((x)))) return NULL
#define ASSERT_2COMPLEX_ARG(x, y)   if (!PyArg_ParseTuple(args, "DD", &((x)), &((y)))) return NULL
#define ASSERT_3COMPLEX_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "DDD", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4COMPLEX_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "DDDD", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_BOOL_ARG(x)   if (!PyArg_ParseTuple(args, "p", &((x)))) return NULL
#define ASSERT_2BOOL_ARG(x, y)   if (!PyArg_ParseTuple(args, "pp", &((x)), &((y)))) return NULL
#define ASSERT_3BOOL_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "ppp", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4BOOL_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "pppp", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_SIZE_T_ARG(x)   if (!PyArg_ParseTuple(args, "n", &((x)))) return NULL
#define ASSERT_2SIZE_T_ARG(x, y)   if (!PyArg_ParseTuple(args, "nn", &((x)), &((y)))) return NULL
#define ASSERT_3SIZE_T_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "nnn", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4SIZE_T_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "nnnn", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_UNSIGNEDCHAR_ARG(x)   if (!PyArg_ParseTuple(args, "b", &((x)))) return NULL
#define ASSERT_2UNSIGNEDCHAR_ARG(x, y)   if (!PyArg_ParseTuple(args, "bb", &((x)), &((y)))) return NULL
#define ASSERT_3UNSIGNEDCHAR_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "bbb", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4UNSIGNEDCHAR_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "bbbb", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_SHORTINT_ARG(x)   if (!PyArg_ParseTuple(args, "h", &((x)))) return NULL
#define ASSERT_2SHORTINT_ARG(x, y)   if (!PyArg_ParseTuple(args, "hh", &((x)), &((y)))) return NULL
#define ASSERT_3SHORTINT_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "hhh", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4SHORTINT_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "hhhh", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_INT_ARG(x)   if (!PyArg_ParseTuple(args, "i", &((x)))) return NULL
#define ASSERT_2INT_ARG(x, y)   if (!PyArg_ParseTuple(args, "ii", &((x)), &((y)))) return NULL
#define ASSERT_3INT_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "iii", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4INT_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "iiii", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_LONG_ARG(x)   if (!PyArg_ParseTuple(args, "l", &((x)))) return NULL
#define ASSERT_2LONG_ARG(x, y)   if (!PyArg_ParseTuple(args, "ll", &((x)), &((y)))) return NULL
#define ASSERT_3LONG_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "lll", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4LONG_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "llll", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_LONGLONG_ARG(x)   if (!PyArg_ParseTuple(args, "L", &((x)))) return NULL
#define ASSERT_2LONGLONG_ARG(x, y)   if (!PyArg_ParseTuple(args, "LL", &((x)), &((y)))) return NULL
#define ASSERT_3LONGLONG_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "LLL", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4LONGLONG_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "LLLL", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_USHORTINT_ARG(x)   if (!PyArg_ParseTuple(args, "H", &((x)))) return NULL
#define ASSERT_2USHORTINT_ARG(x, y)   if (!PyArg_ParseTuple(args, "HH", &((x)), &((y)))) return NULL
#define ASSERT_3USHORTINT_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "HHH", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4USHORTINT_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "HHHH", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_UINT_ARG(x)   if (!PyArg_ParseTuple(args, "I", &((x)))) return NULL
#define ASSERT_2UINT_ARG(x, y)   if (!PyArg_ParseTuple(args, "II", &((x)), &((y)))) return NULL
#define ASSERT_3UINT_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "III", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4UINT_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "IIII", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_ULONG_ARG(x)   if (!PyArg_ParseTuple(args, "k", &((x)))) return NULL
#define ASSERT_2ULONG_ARG(x, y)   if (!PyArg_ParseTuple(args, "kk", &((x)), &((y)))) return NULL
#define ASSERT_3ULONG_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "kkk", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4ULONG_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "kkkk", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_ULONGLONG_ARG(x)   if (!PyArg_ParseTuple(args, "K", &((x)))) return NULL
#define ASSERT_2ULONGLONG_ARG(x, y)   if (!PyArg_ParseTuple(args, "KK", &((x)), &((y)))) return NULL
#define ASSERT_3ULONGLONG_ARG(x, y, z)   if (!PyArg_ParseTuple(args, "KKK", &((x)), &((y)), &((z)))) return NULL
#define ASSERT_4ULONGLONG_ARG(x, y, z, v)   if (!PyArg_ParseTuple(args, "KKKK", &((x)), &((y)), &((z)), &((v)))) return NULL
#define ASSERT_2ARGS   if (PyTuple_Size(args) != 2 && (ERROR_TRIGGER)) { ERR_2ARGS; return NULL; }
#define ASSERT_3ARGS   if (PyTuple_Size(args) != 3 && (ERROR_TRIGGER)) { ERR_3ARGS; return NULL; }
#define ASSERT_4ARGS   if (PyTuple_Size(args) != 4 && (ERROR_TRIGGER)) { ERR_4ARGS; return NULL; }
#define ASSERT_5ARGS   if (PyTuple_Size(args) != 5 && (ERROR_TRIGGER)) { ERR_5ARGS; return NULL; }
#define ASSERT_6ARGS   if (PyTuple_Size(args) != 6 && (ERROR_TRIGGER)) { ERR_6ARGS; return NULL; }
#define ASSERT_2FLOATS(x, y)   if (isFloat(((x))) || isFloat(((y)))) { ERR_2FLOAT; }
#define ASSERT_3FLOATS(x, y, z)   if (isFloat(((x))) || isFloat(((y))) || isFloat(((z)))) { ERR_3FLOAT; }
/* TYPE CONVERSION */
// Python 2 C
#define FLOAT2DOUBLE(x)   (PyFloat_AsDouble(((x))))  // Python float 2 C double
#define FLOAT2DOUBLE_NO_ERR(x)   (PyFloat_AS_DOUBLE(((x))))  // Python float 2 C double (no error checking)
#define COMPLEXREAL2DOUBLE(x)   (PyComplex_RealAsDouble(((x))))  // Python complex (real portion) 2 C double
#define COMPLEXIMAG2DOUBLE(x)   (PyComplex_ImagAsDouble(((x))))  // Python complex (imaginary portion) 2 C double
#define YEAR2INT(x)   (PyDateTime_GET_YEAR(((x))))  // Python year 2 C int
#define MONTH2INT(x)   (PyDateTime_GET_MONTH(((x))))  // Python month 2 C int
#define DAY2INT(x)   (PyDateTime_GET_DAY(((x))))  // Python day 2 C int
#define DATE_HOUR2INT(x)   (PyDateTime_DATE_GET_HOUR(((x))))  // Python hour 2 C int
#define DATE_MINUTE2INT(x)   (PyDateTime_DATE_GET_MINUTE(((x))))  // Python minute 2 C int
#define DATE_SECOND2INT(x)   (PyDateTime_DATE_GET_SECOND(((x))))  // Python second 2 C int
#define DATE_MICROSECOND2INT(x)   (PyDateTime_DATE_GET_MICROSECOND(((x))))  // Python microsecond 2 C int
#define TIME_HOUR2INT(x)   (PyDateTime_TIME_GET_HOUR(((x))))  // Python hour 2 C int
#define TIME_MINUTE2INT(x)   (PyDateTime_TIME_GET_MINUTE(((x))))  // Python minute 2 C int
#define TIME_SECOND2INT(x)   (PyDateTime_TIME_GET_SECOND(((x))))  // Python second 2 C int
#define TIME_MICROSECOND2INT(x)   (PyDateTime_TIME_GET_MICROSECOND(((x))))  // Python microsecond 2 C int
// C 2 Python
#define returnbool(x)   if (((x))) { Py_RETURN_TRUE; } else { Py_RETURN_FALSE; }  // Return Python bool
#define chararray2str(x)   (Py_BuildValue("s", ((x))))  // C char array 2 Python str Py_BuildValue("s", x)
#define double2int(x)   (PyLong_FromDouble(((x))))  // C double (int part) 2 Python int
#define double2float(x)   (PyFloat_FromDouble(((x))))  // C double 2 Python float Py_BuildValue("d", x)
#define float2float(x)   (Py_BuildValue("f", ((x))))  // C float 2 Python float
#define complex2complex(x)   (Py_BuildValue("D", ((x))))  // C complex 2 Python complex
#define char2int(x)   (Py_BuildValue("b", ((x))))  // C signed char 2 Python int
#define uchar2int(x)   (Py_BuildValue("B", ((x))))  // C unsigned char 2 Python int
#define short2int(x)   (Py_BuildValue("h", ((x))))  // C signed short 2 Python int
#define ushort2int(x)   (Py_BuildValue("H", ((x))))  // C unsigned short 2 Python int
#define int2int(x)   (Py_BuildValue("i", ((x))))  // C int 2 Python int
#define uint2int(x)   (Py_BuildValue("I", ((x))))  // C unsigned int 2 Python int
#define long2int(x)   (PyLong_FromLong(((x))))  // C long 2 Python int Py_BuildValue("l", x)
#define lint2int(x)   (PyLong_FromLong(((x))))  // C long 2 Python int Py_BuildValue("l", x)
#define slint2int(x)   (PyLong_FromLong(((x))))  // C long 2 Python int Py_BuildValue("l", x)
#define ulint2int(x)   (PyLong_FromUnsignedLong(((x))))  // C unsigned long 2 Python int Py_BuildValue("k", x)
#define ul2int(x)   (PyLong_FromUnsignedLong(((x))))  // C unsigned long 2 Python int Py_BuildValue("k", x)
#define ll2int(x)   (PyLong_FromLongLong(((x))))  // C long long 2 Python int Py_BuildValue("L", x)
#define sll2int(x)   (PyLong_FromLongLong(((x))))  // C long long 2 Python int Py_BuildValue("L", x)
#define ull2int(x)   (PyLong_FromUnsignedLongLong(((x))))  // C unsigned long long 2 Python int Py_BuildValue("K", x)
#define ullint2int(x)   (PyLong_FromUnsignedLongLong(((x))))  // C unsigned long long 2 Python int
#define size2int(x)   (PyLong_FromSize_t(((x))))  // C size_t 2 Python int
#define ssize2int(x)   (PyLong_FromSsize_t(((x))))  // C Ssize_t 2 Python intPy_BuildValue("K", x)
#define STR(x)   (PyUnicode_FromString(((x))))  // C char array 2 Python str
#define bytestr(x)   (PyUnicode_AsUTF8String(Py_BuildValue("s", ((x)))))  // C char array 2 Python byte-str (b'STRING')
#define pystr(x, y)   (PyUnicode_FromKindAndData(PyUnicode_1BYTE_KIND, ((x)), (Py_ssize_t)((y))))

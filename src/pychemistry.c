// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file pychemistry.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Chemistry-related Functions
@version 2016.03.20

@section DESCRIPTION
This is a Python3 module that uses functions from chemistry.c
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


#include "PY_MACROS.h"
#include "chemistry.h"

#define MODNAME   "chemistry"
#define MODINIT   PyMODINIT_FUNC PyInit_chemistry(void)
MODINIT __attribute__((flatten, hot));


/* FUNCTION DEFINITIONS */


#ifdef __GNUC__
static PyObject *chemistry_pka(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *chemistry_pkb(FUNCARGS) __attribute__((const, flatten, nonnull));
static PyObject *chemistry_iselement(FUNCARGS) __attribute__((const, flatten, nonnull));
#else
static PyObject *chemistry_pka(FUNCARGS);
static PyObject *chemistry_pkb(FUNCARGS);
static PyObject *chemistry_iselement(FUNCARGS);
#endif


/* DOCSTRINGS */


static char module_docstring[32] =
    "Chemistry-related Functions";
PyDoc_STRVAR(chemistry_pka_docstring,
    "pka(ka: float) -> float\nCalculate the pKa from Ka (Acid Dissociation Constant)");
PyDoc_STRVAR(chemistry_pkb_docstring,
    "pkb(kb: float) -> float\nCalculate the pKb from Kb (Base Dissociation Constant)");
PyDoc_STRVAR(chemistry_iselement_docstring,
    "iselement(name: str) -> bool\nCheck if the string is a name of a chemical element");


/* MODULE SPECIFICATION */


static PyMethodDef module_methods[4] = {  // Method Table
    {"pka", (PyCFunction)chemistry_pka, METH_VARARGS, chemistry_pka_docstring},
    {"pkb", (PyCFunction)chemistry_pkb, METH_VARARGS, chemistry_pkb_docstring},
    {"iselement", (PyCFunction)chemistry_iselement, METH_VARARGS, chemistry_iselement_docstring},
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


MODINIT {  // Initialize module
    PyObject *m;
    m = PyModule_Create(&module);
#   ifndef NOAUTHOR
    PyModule_AddStringConstant(m, "__author__", __author__);
#   endif
#   ifndef NOVERSION
    PyModule_AddStringConstant(m, "__version__", __version__);
#   endif
    if (m == (PyObject *)NULL) return NULL;
    return m;
}


/* C CODE */


static PyObject *chemistry_pka(FUNCARGS) {
    const double ka;
    ASSERT_DOUBLE_ARG(ka);
    return double2float(pka(ka));
}


static PyObject *chemistry_pkb(FUNCARGS) {
    const double kb;
    ASSERT_DOUBLE_ARG(kb);
    return double2float(pkb(kb));
}


static PyObject *chemistry_iselement(FUNCARGS) {
    char *name;
    ASSERT_STRING_ARG(name);
    if (iselement(name)) { Py_RETURN_TRUE; }
    Py_RETURN_FALSE;
}

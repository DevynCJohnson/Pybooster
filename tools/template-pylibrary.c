// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file FILE.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief SUMMARY
@version 2016.03.09

@section DESCRIPTION
TEXT

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


#include "template_header.h"
#include "PY_MACROS.h"

#define MODNAME "MODNAME"
#define MODINIT PyMODINIT_FUNC PyInit_MODNAME(void)
MODINIT __attribute__((flatten, hot));;


/* FUNCTION DEFINITIONS */


static PyObject *MODNAME_FUNC(SELFARGS);


/* DOCSTRINGS */


static char module_docstring[32] =
    "DESCRIPTION";
PyDoc_STRVAR(MODNAME_FUNC_docstring,
    "FUNC(distance: float, time: float) -> float\nDESCRIPTION");


/* MODULE SPECIFICATION */


static PyMethodDef module_methods[2] = {  // Method Table
    {"FUNC", (PyCFunction)MODNAME_FUNC, METH_VARARGS, MODNAME_FUNC_docstring},
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


static PyObject *MODNAME_FUNC(SELFARGS) {
    PyObject *VAR;
    return double2float(VAR);
}

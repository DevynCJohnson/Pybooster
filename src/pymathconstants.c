// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file pymathconstants.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Math Constants
@version 2016.03.20

@section DESCRIPTION
This is a Python3 module that uses functions from mathconstants.c
Both common and rare mathematical and number constants are provided in many datatypes.

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
#include "MATH_MACROS.h"

#define MODNAME   "mathconstants"
#define MODINIT   PyMODINIT_FUNC PyInit_mathconstants(void)
MODINIT __attribute__((flatten, hot));


/* DOCSTRINGS */


static char module_docstring[64] = "Math Constants\nProvides PI, E, PHI, LOG_PI, and more constants";


/* MODULE SPECIFICATION */


static struct PyModuleDef module = {  // Module Definition
    PyModuleDef_HEAD_INIT,
    MODNAME,  // Module name
    module_docstring,  // Module docstring
    -1,  // Module size
    NULL,  // Module methods
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
    // CONSTANTS
    PyModule_AddObject(m, "ARTIN_CONSTANT", double2float(ARTIN_CONSTANT));
    PyModule_AddObject(m, "ATOMIC_UNIT_OF_CHARGE", double2float(ATOMIC_UNIT_OF_CHARGE));
    PyModule_AddObject(m, "ATOMIC_UNIT_OF_CURRENT", double2float(ATOMIC_UNIT_OF_CURRENT));
    PyModule_AddObject(m, "ATOMIC_UNIT_OF_FORCE", double2float(ATOMIC_UNIT_OF_FORCE));
    PyModule_AddObject(m, "AVOGADRO_CONSTANT", double2float(AVOGADRO_CONSTANT));
    PyModule_AddObject(m, "BERNSTEINS_CONSTANT", double2float(BERNSTEINS_CONSTANT));
    PyModule_AddObject(m, "BOHR_RADIUS", double2float(BOHR_RADIUS));
    PyModule_AddObject(m, "BOLTZMANN_CONSTANT", double2float(BOLTZMANN_CONSTANT));
    PyModule_AddObject(m, "CHAMPERNOWNE_CONSTANT", double2float(CHAMPERNOWNE_CONSTANT));
    PyModule_AddObject(m, "CHEBYSHEV_CONSTANT", double2float(CHEBYSHEV_CONSTANT));
    PyModule_AddObject(m, "COMPTON_WAVELENGTH", double2float(COMPTON_WAVELENGTH));
    PyModule_AddObject(m, "DEG2RAD", double2float(DEG2RAD));
    PyModule_AddObject(m, "DELIAN_CONSTANT", double2float(DELIAN_CONSTANT));
    PyModule_AddObject(m, "DEUTERON_G_FACTOR", double2float(DEUTERON_G_FACTOR));
    PyModule_AddObject(m, "DEUTERON_MASS", double2float(DEUTERON_MASS));
    PyModule_AddObject(m, "DEUTERON_MOLAR_MASS", double2float(DEUTERON_MOLAR_MASS));
    PyModule_AddObject(m, "DOUBLE_FACTORIAL_CONSTANT", double2float(DOUBLE_FACTORIAL_CONSTANT));
    PyModule_AddObject(m, "E", double2float(E));
    PyModule_AddObject(m, "ELECTRON_G_FACTOR", double2float(ELECTRON_G_FACTOR));
    PyModule_AddObject(m, "ELECTRON_MASS", double2float(ELECTRON_MASS));
    PyModule_AddObject(m, "ELECTRON_VOLT", double2float(ELECTRON_VOLT));
    PyModule_AddObject(m, "ELECTRON_MUON_MASS_RATIO", double2float(ELECTRON_MUON_MASS_RATIO));
    PyModule_AddObject(m, "ELECTRON_NEUTRON_MAGNETIC_MOMENT_RATIO", double2float(ELECTRON_NEUTRON_MAGNETIC_MOMENT_RATIO));
    PyModule_AddObject(m, "ERFC_CONTFRAC_CUTOFF", double2float(ERFC_CONTFRAC_CUTOFF));
    PyModule_AddObject(m, "ERFC_CONTFRAC_TERMS", double2float(ERFC_CONTFRAC_TERMS));
    PyModule_AddObject(m, "ERF_SERIES_CUTOFF", double2float(ERF_SERIES_CUTOFF));
    PyModule_AddObject(m, "ERF_SERIES_TERMS", double2float(ERF_SERIES_TERMS));
    PyModule_AddObject(m, "EULERS_CONSTANT", double2float(EULERS_CONSTANT));
    PyModule_AddObject(m, "EXPONENTIAL_FACTORIAL_CONSTANT", double2float(EXPONENTIAL_FACTORIAL_CONSTANT));
    PyModule_AddObject(m, "GOLDEN_ANGLE", double2float(GOLDEN_ANGLE));
    PyModule_AddObject(m, "GOLDEN_RATIO", double2float(GOLDEN_RATIO));
    PyModule_AddObject(m, "HYPERBOLIC_TANGENT_OF_1", double2float(HYPERBOLIC_TANGENT_OF_1));
    PyModule_AddObject(m, "INVERSE_E", double2float(INVERSE_E));
    PyModule_AddObject(m, "INVERSE_PI", double2float(INVERSE_PI));
    PyModule_AddObject(m, "I_SQUARED", long2int(I_SQUARED));
    PyModule_AddObject(m, "LN_E", double2float(LN_E));
    PyModule_AddObject(m, "LN2", double2float(LN2));
    PyModule_AddObject(m, "LOG10_E", double2float(LOG10_E));
    PyModule_AddObject(m, "LOG10_PI", double2float(LOG10_PI));
    PyModule_AddObject(m, "LOG_E", double2float(LOG_E));
    PyModule_AddObject(m, "LOG_PI", double2float(LOG_PI));
    PyModule_AddObject(m, "MURATA_CONSTANT", double2float(MURATA_CONSTANT));
    PyModule_AddObject(m, "OMEGA", double2float(OMEGA));
    PyModule_AddObject(m, "PARIS_CONSTANT", double2float(PARIS_CONSTANT));
    PyModule_AddObject(m, "PI", double2float(PI));
    PyModule_AddObject(m, "PI", double2float(PI));
    PyModule_AddObject(m, "PI", double2float(PI));
    PyModule_AddObject(m, "PI2", double2float(PI2));
    PyModule_AddObject(m, "PI4", double2float(PI4));
    PyModule_AddObject(m, "PI_4_3", double2float(PI_4_3));
    PyModule_AddObject(m, "PI_SQUARED", double2float(PI_SQUARED));
    PyModule_AddObject(m, "PI_1_3", double2float(PI_1_3));
    PyModule_AddObject(m, "PI_2_3", double2float(PI_2_3));
    PyModule_AddObject(m, "PI_SQUARED_1_4", double2float(PI_SQUARED_1_4));
    PyModule_AddObject(m, "RAD2DEG", double2float(RAD2DEG));
    PyModule_AddObject(m, "RIGHT_ANGLE_DEG", double2float(RIGHT_ANGLE_DEG));
    PyModule_AddObject(m, "SALEM_NUMBER", double2float(SALEM_NUMBER));
    PyModule_AddObject(m, "SQRT_2", double2float(SQRT_2));
    PyModule_AddObject(m, "SQRT_3", double2float(SQRT_3));
    PyModule_AddObject(m, "SQRT_3_DIV_4", double2float(SQRT_3_DIV_4));
    PyModule_AddObject(m, "SQRT_5", double2float(SQRT_5));
    PyModule_AddObject(m, "SQRT_6", double2float(SQRT_6));
    PyModule_AddObject(m, "SQRT_7", double2float(SQRT_7));
    PyModule_AddObject(m, "SQRT_8", double2float(SQRT_8));
    PyModule_AddObject(m, "SQRT_10", double2float(SQRT_10));
    PyModule_AddObject(m, "SQRT_11", double2float(SQRT_11));
    PyModule_AddObject(m, "SQRT_12", double2float(SQRT_12));
    PyModule_AddObject(m, "SQRT_13", double2float(SQRT_13));
    PyModule_AddObject(m, "SQRT_14", double2float(SQRT_14));
    PyModule_AddObject(m, "SQRT_15", double2float(SQRT_15));
    PyModule_AddObject(m, "SQRT_16", double2float(SQRT_16));
    PyModule_AddObject(m, "SQRT_17", double2float(SQRT_17));
    PyModule_AddObject(m, "SQRT_19", double2float(SQRT_19));
    PyModule_AddObject(m, "SQRT_20", double2float(SQRT_20));
    PyModule_AddObject(m, "SQRT_21", double2float(SQRT_21));
    PyModule_AddObject(m, "SQRT_22", double2float(SQRT_22));
    PyModule_AddObject(m, "SQRT_23", double2float(SQRT_23));
    PyModule_AddObject(m, "SQRT_24", double2float(SQRT_24));
    PyModule_AddObject(m, "SQRT_E", double2float(SQRT_E));
    PyModule_AddObject(m, "SQRT_PI", double2float(SQRT_PI));
    PyModule_AddObject(m, "TAN_E", double2float(TAN_E));
    PyModule_AddObject(m, "TAN_PI", double2float(TAN_PI));
    PyModule_AddObject(m, "TWIN_PRIMES_CONSTANT", double2float(TWIN_PRIMES_CONSTANT));
    PyModule_AddObject(m, "VARDI_CONSTANT", double2float(VARDI_CONSTANT));
    PyModule_AddObject(m, "ZERO", double2float(ZERO));
    // ALIASES
    PyModule_AddObject(m, "ARCHIMEDES_CONSTANT", double2float(PI));
    PyModule_AddObject(m, "EULERS_NUMBER", double2float(E));
    PyModule_AddObject(m, "PHI", double2float(GOLDEN_RATIO));
    PyModule_AddObject(m, "PYTHAGORAS_CONSTANT", double2float(SQRT_2));
    // SYMBOLS
    PyModule_AddObject(m, "PI_SYM", STR("π\0"));
    if (m == (PyObject *)NULL) return NULL;
    return m;
}

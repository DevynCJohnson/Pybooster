// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file pychemistry.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Chemistry Functions from chemistry.c
@version 2016.03.25

@section DESCRIPTION
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
    PyModule_AddObject(m, "HYDROGEN_ATOMIC_MASS", double2float(1.0079));
    PyModule_AddObject(m, "HELIUM_ATOMIC_MASS", double2float(4.0026));
    PyModule_AddObject(m, "LITHIUM_ATOMIC_MASS", double2float(6.941));
    PyModule_AddObject(m, "BERYLLIUM_ATOMIC_MASS", double2float(9.0122));
    PyModule_AddObject(m, "BORON_ATOMIC_MASS", double2float(10.811));
    PyModule_AddObject(m, "CARBON_ATOMIC_MASS", double2float(12.0107));
    PyModule_AddObject(m, "NITROGEN_ATOMIC_MASS", double2float(14.0067));
    PyModule_AddObject(m, "OXYGEN_ATOMIC_MASS", double2float(15.9994));
    PyModule_AddObject(m, "FLUORINE_ATOMIC_MASS", double2float(18.9984));
    PyModule_AddObject(m, "NEON_ATOMIC_MASS", double2float(20.1797));
    PyModule_AddObject(m, "SODIUM_ATOMIC_MASS", double2float(22.9897));
    PyModule_AddObject(m, "MAGNESIUM_ATOMIC_MASS", double2float(24.305));
    PyModule_AddObject(m, "ALUMINIUM_ATOMIC_MASS", double2float(26.9815));
    PyModule_AddObject(m, "SILICON_ATOMIC_MASS", double2float(28.0855));
    PyModule_AddObject(m, "PHOSPHORUS_ATOMIC_MASS", double2float(30.9738));
    PyModule_AddObject(m, "SULFUR_ATOMIC_MASS", double2float(32.065));
    PyModule_AddObject(m, "CHLORINE_ATOMIC_MASS", double2float(35.453));
    PyModule_AddObject(m, "ARGON_ATOMIC_MASS", double2float(39.948));
    PyModule_AddObject(m, "POTASSIUM_ATOMIC_MASS", double2float(39.0983));
    PyModule_AddObject(m, "CALCIUM_ATOMIC_MASS", double2float(40.078));
    PyModule_AddObject(m, "SCANDIUM_ATOMIC_MASS", double2float(44.9559));
    PyModule_AddObject(m, "TITANIUM_ATOMIC_MASS", double2float(47.867));
    PyModule_AddObject(m, "VANADIUM_ATOMIC_MASS", double2float(50.9415));
    PyModule_AddObject(m, "CHROMIUM_ATOMIC_MASS", double2float(51.9961));
    PyModule_AddObject(m, "MANGANESE_ATOMIC_MASS", double2float(54.938));
    PyModule_AddObject(m, "IRON_ATOMIC_MASS", double2float(55.845));
    PyModule_AddObject(m, "COBALT_ATOMIC_MASS", double2float(58.9332));
    PyModule_AddObject(m, "NICKEL_ATOMIC_MASS", double2float(58.6934));
    PyModule_AddObject(m, "COPPER_ATOMIC_MASS", double2float(63.546));
    PyModule_AddObject(m, "ZINC_ATOMIC_MASS", double2float(65.39));
    PyModule_AddObject(m, "GALLIUM_ATOMIC_MASS", double2float(69.723));
    PyModule_AddObject(m, "GERMANIUM_ATOMIC_MASS", double2float(72.64));
    PyModule_AddObject(m, "ARSENIC_ATOMIC_MASS", double2float(74.9216));
    PyModule_AddObject(m, "SELENIUM_ATOMIC_MASS", double2float(78.96));
    PyModule_AddObject(m, "BROMINE_ATOMIC_MASS", double2float(79.904));
    PyModule_AddObject(m, "KRYPTON_ATOMIC_MASS", double2float(83.8));
    PyModule_AddObject(m, "RUBIDIUM_ATOMIC_MASS", double2float(85.4678));
    PyModule_AddObject(m, "STRONTIUM_ATOMIC_MASS", double2float(87.62));
    PyModule_AddObject(m, "YTTRIUM_ATOMIC_MASS", double2float(88.9059));
    PyModule_AddObject(m, "ZIRCONIUM_ATOMIC_MASS", double2float(91.224));
    PyModule_AddObject(m, "NIOBIUM_ATOMIC_MASS", double2float(92.9064));
    PyModule_AddObject(m, "MOLYBDENUM_ATOMIC_MASS", double2float(95.94));
    PyModule_AddObject(m, "TECHNETIUM_ATOMIC_MASS", double2float(98));
    PyModule_AddObject(m, "RUTHENIUM_ATOMIC_MASS", double2float(101.07));
    PyModule_AddObject(m, "RHODIUM_ATOMIC_MASS", double2float(102.9055));
    PyModule_AddObject(m, "PALLADIUM_ATOMIC_MASS", double2float(106.42));
    PyModule_AddObject(m, "SILVER_ATOMIC_MASS", double2float(107.8682));
    PyModule_AddObject(m, "CADMIUM_ATOMIC_MASS", double2float(112.411));
    PyModule_AddObject(m, "INDIUM_ATOMIC_MASS", double2float(114.818));
    PyModule_AddObject(m, "TIN_ATOMIC_MASS", double2float(118.71));
    PyModule_AddObject(m, "ANTIMONY_ATOMIC_MASS", double2float(121.76));
    PyModule_AddObject(m, "TELLURIUM_ATOMIC_MASS", double2float(127.6));
    PyModule_AddObject(m, "IODINE_ATOMIC_MASS", double2float(126.9045));
    PyModule_AddObject(m, "XENON_ATOMIC_MASS", double2float(131.293));
    PyModule_AddObject(m, "CESIUM_ATOMIC_MASS", double2float(132.9055));
    PyModule_AddObject(m, "BARIUM_ATOMIC_MASS", double2float(137.327));
    PyModule_AddObject(m, "LANTHANUM_ATOMIC_MASS", double2float(138.9055));
    PyModule_AddObject(m, "CERIUM_ATOMIC_MASS", double2float(140.116));
    PyModule_AddObject(m, "PRASEODYMIUM_ATOMIC_MASS", double2float(140.9077));
    PyModule_AddObject(m, "NEODYMIUM_ATOMIC_MASS", double2float(144.24));
    PyModule_AddObject(m, "PROMETHIUM_ATOMIC_MASS", double2float(145));
    PyModule_AddObject(m, "SAMARIUM_ATOMIC_MASS", double2float(150.36));
    PyModule_AddObject(m, "EUROPIUM_ATOMIC_MASS", double2float(151.964));
    PyModule_AddObject(m, "GADOLINIUM_ATOMIC_MASS", double2float(157.25));
    PyModule_AddObject(m, "TERBIUM_ATOMIC_MASS", double2float(158.9253));
    PyModule_AddObject(m, "DYSPROSIUM_ATOMIC_MASS", double2float(162.5));
    PyModule_AddObject(m, "HOLMIUM_ATOMIC_MASS", double2float(164.9303));
    PyModule_AddObject(m, "ERBIUM_ATOMIC_MASS", double2float(167.259));
    PyModule_AddObject(m, "THULIUM_ATOMIC_MASS", double2float(168.9342));
    PyModule_AddObject(m, "YTTERBIUM_ATOMIC_MASS", double2float(173.04));
    PyModule_AddObject(m, "LUTETIUM_ATOMIC_MASS", double2float(174.967));
    PyModule_AddObject(m, "HAFNIUM_ATOMIC_MASS", double2float(178.49));
    PyModule_AddObject(m, "TANTALUM_ATOMIC_MASS", double2float(180.9479));
    PyModule_AddObject(m, "TUNGSTEN_ATOMIC_MASS", double2float(183.84));
    PyModule_AddObject(m, "RHENIUM_ATOMIC_MASS", double2float(186.207));
    PyModule_AddObject(m, "OSMIUM_ATOMIC_MASS", double2float(190.23));
    PyModule_AddObject(m, "IRIDIUM_ATOMIC_MASS", double2float(192.217));
    PyModule_AddObject(m, "PLATINUM_ATOMIC_MASS", double2float(195.078));
    PyModule_AddObject(m, "GOLD_ATOMIC_MASS", double2float(196.9665));
    PyModule_AddObject(m, "MERCURY_ATOMIC_MASS", double2float(200.59));
    PyModule_AddObject(m, "THALLIUM_ATOMIC_MASS", double2float(204.3833));
    PyModule_AddObject(m, "LEAD_ATOMIC_MASS", double2float(207.2));
    PyModule_AddObject(m, "BISMUTH_ATOMIC_MASS", double2float(208.9804));
    PyModule_AddObject(m, "POLONIUM_ATOMIC_MASS", double2float(209));
    PyModule_AddObject(m, "ASTATINE_ATOMIC_MASS", double2float(210));
    PyModule_AddObject(m, "RADON_ATOMIC_MASS", double2float(222));
    PyModule_AddObject(m, "FRANCIUM_ATOMIC_MASS", double2float(223));
    PyModule_AddObject(m, "RADIUM_ATOMIC_MASS", double2float(226));
    PyModule_AddObject(m, "ACTINIUM_ATOMIC_MASS", double2float(227));
    PyModule_AddObject(m, "THORIUM_ATOMIC_MASS", double2float(232.0381));
    PyModule_AddObject(m, "PROTACTINIUM_ATOMIC_MASS", double2float(231.0359));
    PyModule_AddObject(m, "URANIUM_ATOMIC_MASS", double2float(238.0289));
    PyModule_AddObject(m, "NEPTUNIUM_ATOMIC_MASS", double2float(237.0));
    PyModule_AddObject(m, "PLUTONIUM_ATOMIC_MASS", double2float(244.0));
    PyModule_AddObject(m, "AMERICIUM_ATOMIC_MASS", double2float(243.0));
    PyModule_AddObject(m, "CURIUM_ATOMIC_MASS", double2float(247.0));
    PyModule_AddObject(m, "BERKELIUM_ATOMIC_MASS", double2float(247.0));
    PyModule_AddObject(m, "CALIFORNIUM_ATOMIC_MASS", double2float(251.0));
    PyModule_AddObject(m, "EINSTEINIUM_ATOMIC_MASS", double2float(252.0));
    PyModule_AddObject(m, "FERMIUM_ATOMIC_MASS", double2float(257.0));
    PyModule_AddObject(m, "MENDELEVIUM_ATOMIC_MASS", double2float(258.0));
    PyModule_AddObject(m, "NOBELIUM_ATOMIC_MASS", double2float(259.0));
    PyModule_AddObject(m, "LAWRENCIUM_ATOMIC_MASS", double2float(262.0));
    PyModule_AddObject(m, "RUTHERFORDIUM_ATOMIC_MASS", double2float(261.0));
    PyModule_AddObject(m, "DUBNIUM_ATOMIC_MASS", double2float(262.0));
    PyModule_AddObject(m, "SEABORGIUM_ATOMIC_MASS", double2float(266.0));
    PyModule_AddObject(m, "BOHRIUM_ATOMIC_MASS", double2float(264.0));
    PyModule_AddObject(m, "HASSIUM_ATOMIC_MASS", double2float(277.0));
    PyModule_AddObject(m, "MEITNERIUM_ATOMIC_MASS", double2float(268.0));
    PyModule_AddObject(m, "DARMSTADTIUM_ATOMIC_MASS", double2float(281.0));
    PyModule_AddObject(m, "ROENTGENIUM_ATOMIC_MASS", double2float(282.0));
    PyModule_AddObject(m, "COPERNICIUM_ATOMIC_MASS", double2float(285.0));
    PyModule_AddObject(m, "UNUNTRIUM_ATOMIC_MASS", double2float(286.0));
    PyModule_AddObject(m, "FLEROVIUM_ATOMIC_MASS", double2float(289.0));
    PyModule_AddObject(m, "UNUNPENTIUM_ATOMIC_MASS", double2float(289.0));
    PyModule_AddObject(m, "LIVERMORIUM_ATOMIC_MASS", double2float(293.0));
    PyModule_AddObject(m, "UNUNSEPTIUM_ATOMIC_MASS", double2float(294.0));
    PyModule_AddObject(m, "UNUNOCTIUM_ATOMIC_MASS", double2float(294.0));
    PyModule_AddObject(m, "UNUNENNIUM_ATOMIC_MASS", double2float(315.0));
    PyModule_AddObject(m, "UNBINILIUM_ATOMIC_MASS", double2float(320.0));
    PyModule_AddObject(m, "UNBIUNIUM_ATOMIC_MASS", double2float(321.0));
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

// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file chemistry.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Chemistry-related Functions
@version 2016.03.18

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


#include "chemistry.h"


/* CONSTANTS */


/** Array containing the names of the Periodic Table of Elements */
const char elementlist[128][16] = {
    "hydrogen",
    "helium",
    "lithium",
    "beryllium",
    "boron",
    "carbon",
    "nitrogen",
    "oxygen",
    "fluorine",
    "neon",
    "sodium",
    "magnesium",
    "aluminium",
    "silicon",
    "phosphorus",
    "sulfur",
    "chlorine",
    "argon",
    "potassium",
    "calcium",
    "scandium",
    "titanium",
    "vanadium",
    "chromium",
    "manganese",
    "iron",
    "cobalt",
    "nickel",
    "copper",
    "zinc",
    "gallium",
    "germanium",
    "arsenic",
    "selenium",
    "bromine",
    "krypton",
    "rubidium",
    "strontium",
    "yttrium",
    "zirconium",
    "niobium",
    "molybdenum",
    "technetium",
    "ruthenium",
    "rhodium",
    "palladium",
    "silver",
    "cadmium",
    "indium",
    "tin",
    "antimony",
    "tellurium",
    "iodine",
    "xenon",
    "cesium",
    "barium",
    "lanthanum",
    "cerium",
    "praseodymium",
    "neodymium",
    "promethium",
    "samarium",
    "europium",
    "gadolinium",
    "terbium",
    "dysprosium",
    "holmium",
    "erbium",
    "thulium",
    "ytterbium",
    "lutetium",
    "hafnium",
    "tantalum",
    "tungsten",
    "rhenium",
    "osmium",
    "iridium",
    "platinum",
    "gold",
    "mercury",
    "thallium",
    "lead",
    "bismuth",
    "polonium",
    "astatine",
    "radon",
    "francium",
    "radium",
    "actinium",
    "thorium",
    "protactinium",
    "uranium",
    "neptunium",
    "plutonium",
    "americium",
    "curium",
    "berkelium",
    "californium",
    "einsteinium",
    "fermium",
    "mendelevium",
    "nobelium",
    "lawrencium",
    "rutherfordium",
    "dubnium",
    "seaborgium",
    "bohrium",
    "hassium",
    "meitnerium",
    "darmstadtium",
    "roentgenium",
    "copernicium",
    "ununtrium",
    "flerovium",
    "ununpentium",
    "livermorium",
    "ununseptium",
    "ununoctium",
    "ununennium",
    "unbinilium",
    "unbiunium",
};


/* HELPER FUNCTIONS */


#ifdef __GNUC__
static size_t strlenx(const char *__restrict__ str) __attribute__((const, flatten));
#else
static size_t strlenx(const char *__restrict__ str);
#endif
/** Private Function: Returns the length of a string */
static size_t strlenx(const char *__restrict__ str) {
    register const char *s;
    for (s = str; *s; ++s);
    return (size_t)(s - str);
}


/* FUNCTIONS */


/**
    Calculate the pKa from Ka (Acid Dissociation Constant)

    Chemistry Explanation\n
    [HA] = [H+] + [A-]; Molar concentrations\n
    Ka = ([H+][A-]) / [HA]\n
    Ka = ([X][0.01M+X]) / (0.02M-X); Ka = 10^-5M\n
    X = 0.00001 * (0.02 / 0.01) = 2*(10^-5) = [H+]\n
    pH = -log(2*(10^-5)) = 4.7

    @param[in] ka    Acid Dissociation Constant
    @returns pka value
*/
double pka(const double ka) {
    return (0.0 - log10(ka));
}


/**
    Calculate the pKb from Kb (Base Dissociation Constant)

    @param[in] kb    Base Dissociation Constant
    @returns pkb value
*/
double pkb(const double kb) {
    return (0.0 - log10(kb));
}


/**
    Check if the given string is a name of a chemical element

    @param[in] name    String to test
    @retval 0    False: This is not a name of a chemical element
    @retval 1    True: This is a name of a chemical element
*/
int iselement(const char *__restrict__ name) {
    register const size_t len = strlenx(name);
    if (len < 3 || len > 13) { return 0; }  // Optimization trick due to the shortest and longest element names
    char elementname[16] = { 0 };
    memmove(elementname, name, len);
    register size_t i;
#   ifdef __IVDEP__
#   pragma GCC ivdep
    for (i = len; --i;) { elementname[i] = ((elementname[i] > 0x5A || elementname[i] < 0x41) ? elementname[i] : (char)((uint8_t)elementname[i] + 0x20u)); }
#   elif defined(__INTEL_COMPILER)
#   pragma ivdep
    for (i = len; --i;) { elementname[i] = ((elementname[i] > 0x5A || elementname[i] < 0x41) ? elementname[i] : (char)((uint8_t)elementname[i] + 0x20u)); }
#   elif defined(__clang__)
#   pragma clang loop unroll(full) vectorize(enable)
    for (i = len; --i;) { elementname[i] = ((elementname[i] > 0x5A || elementname[i] < 0x41) ? elementname[i] : (char)((uint8_t)elementname[i] + 0x20u)); }
#   else
    for (i = len; --i;) { elementname[i] = ((elementname[i] > 0x5A || elementname[i] < 0x41) ? elementname[i] : (char)((uint8_t)elementname[i] + 0x20u)); }
#   endif
    elementname[0] = ((elementname[0] > 0x5A || elementname[0] < 0x41) ? elementname[0] : (char)((uint8_t)elementname[0] + 0x20u));
#   ifdef __IVDEP__
#   pragma GCC ivdep
    for (i = 0x0; i < 120; ++i) {
        if (((strlenx(elementlist[i])) == len) && (strncmp(elementname, elementlist[i], len) == 0x0)) {
            return 1;
        }
    }
#   elif defined(__INTEL_COMPILER)
#   pragma ivdep
    for (i = 0x0; i < 120; ++i) {
        if (((strlenx(elementlist[i])) == len) && (strncmp(elementname, elementlist[i], len) == 0x0)) {
            return 1;
        }
    }
#   elif defined(__clang__)
#   pragma clang loop unroll(full) vectorize(enable)
    for (i = 0x0; i < 120; ++i) {
        if (((strlenx(elementlist[i])) == len) && (strncmp(elementname, elementlist[i], len) == 0x0)) {
            return 1;
        }
    }
#   else
    for (i = 0x0; i < 120; ++i) {
        if (((strlenx(elementlist[i])) == len) && (strncmp(elementname, elementlist[i], len) == 0x0)) {
            return 1;
        }
    }
#   endif
    return 0;
}

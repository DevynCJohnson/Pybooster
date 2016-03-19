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
    for (i = len; --i;) {
        if (elementname[i] < 'A' || elementname[i] > 'Z') {  // elementname[i] is not uppercase
            if (elementname[i] < 'a' || elementname[i] > 'z') { return 0; }  // Not a letter
            else { continue; }
        }
        // No element name contains 'j' or 'q'
        switch (elementname[i]) {  // elementname[0] is uppercase
            case 'N': elementname[i] = 'n'; break;
            case 'U': elementname[i] = 'u'; break;
            case 'I': elementname[i] = 'i'; break;
            case 'M': elementname[i] = 'm'; break;
            case 'O': elementname[i] = 'o'; break;
            case 'E': elementname[i] = 'e'; break;
            case 'R': elementname[i] = 'r'; break;
            case 'S': elementname[i] = 's'; break;
            case 'T': elementname[i] = 't'; break;
            case 'B': elementname[i] = 'b'; break;
            case 'C': elementname[i] = 'c'; break;
            case 'D': elementname[i] = 'd'; break;
            case 'L': elementname[i] = 'l'; break;
            default:
                switch (elementname[i]) {
                    case 'F': elementname[i] = 'f'; break;
                    case 'A': elementname[i] = 'a'; break;
                    case 'P': elementname[i] = 'p'; break;
                    case 'G': elementname[i] = 'g'; break;
                    case 'K': elementname[i] = 'k'; break;
                    case 'H': elementname[i] = 'h'; break;
                    case 'V': elementname[i] = 'v'; break;
                    case 'W': elementname[i] = 'w'; break;
                    case 'Y': elementname[i] = 'y'; break;
                    case 'Z': elementname[i] = 'z'; break;
                    default: elementname[i] = 'x'; break;
                }
                break;
        }
    }
    // Convert the final character in the string
    if (elementname[0] < 'A' || elementname[0] > 'Z') {  // elementname[0] is not uppercase
        if (elementname[0] < 'a' || elementname[0] > 'z') { return 0; }  // Not a letter
    } else {  // elementname[0] is uppercase
        // No element name contains 'j' or 'q', and none begins with a 'w'
        switch (elementname[0]) {
            case 'N': elementname[0] = 'n'; break;
            case 'O': elementname[0] = 'o'; break;
            case 'L': elementname[0] = 'l'; break;
            case 'M': elementname[0] = 'm'; break;
            case 'B': elementname[0] = 'b'; break;
            case 'C': elementname[0] = 'c'; break;
            case 'E': elementname[0] = 'e'; break;
            case 'R': elementname[0] = 'r'; break;
            case 'S': elementname[0] = 's'; break;
            case 'T': elementname[0] = 't'; break;
            case 'U': elementname[0] = 'u'; break;
            default:
                switch (elementname[0]) {
                    case 'I': elementname[0] = 'i'; break;
                    case 'F': elementname[0] = 'f'; break;
                    case 'D': elementname[0] = 'd'; break;
                    case 'A': elementname[0] = 'a'; break;
                    case 'P': elementname[0] = 'p'; break;
                    case 'G': elementname[0] = 'g'; break;
                    case 'K': elementname[0] = 'k'; break;
                    case 'H': elementname[0] = 'h'; break;
                    case 'V': elementname[0] = 'v'; break;
                    case 'X': elementname[0] = 'x'; break;
                    case 'Z': elementname[0] = 'z'; break;
                    default: elementname[0] = 'y'; break;
                }
                break;
        }
    }
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

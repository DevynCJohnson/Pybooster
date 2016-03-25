// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file chemistry.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Chemistry-related Functions (header)
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


#ifndef FILE_CHEMISTRY_SEEN
#define FILE_CHEMISTRY_SEEN


#include "MACROS.h"

#include <math.h>
#include "chemistry_types.h"


/* CHEMISTRY MACROS */
#define HYDROGEN_MOLAR_MASS   (1.0079)
#define HELIUM_MOLAR_MASS   (4.0026)
#define LITHIUM_MOLAR_MASS   (6.941)
#define BERYLLIUM_MOLAR_MASS   (9.0122)
#define BORON_MOLAR_MASS   (10.811)
#define CARBON_MOLAR_MASS   (12.0107)
#define NITROGEN_MOLAR_MASS   (14.0067)
#define OXYGEN_MOLAR_MASS   (15.9994)
#define FLUORINE_MOLAR_MASS   (18.9984)
#define NEON_MOLAR_MASS   (20.1797)
#define SODIUM_MOLAR_MASS   (22.9897)
#define MAGNESIUM_MOLAR_MASS   (24.305)
#define ALUMINIUM_MOLAR_MASS   (26.9815)
#define SILICON_MOLAR_MASS   (28.0855)
#define PHOSPHORUS_MOLAR_MASS   (30.9738)
#define SULFUR_MOLAR_MASS   (32.065)
#define CHLORINE_MOLAR_MASS   (35.453)
#define ARGON_MOLAR_MASS   (39.948)
#define POTASSIUM_MOLAR_MASS   (39.0983)
#define CALCIUM_MOLAR_MASS   (40.078)
#define SCANDIUM_MOLAR_MASS   (44.9559)
#define TITANIUM_MOLAR_MASS   (47.867)
#define VANADIUM_MOLAR_MASS   (50.9415)
#define CHROMIUM_MOLAR_MASS   (51.9961)
#define MANGANESE_MOLAR_MASS   (54.938)
#define IRON_MOLAR_MASS   (55.845)
#define COBALT_MOLAR_MASS   (58.9332)
#define NICKEL_MOLAR_MASS   (58.6934)
#define COPPER_MOLAR_MASS   (63.546)
#define ZINC_MOLAR_MASS   (65.39)
#define GALLIUM_MOLAR_MASS   (69.723)
#define GERMANIUM_MOLAR_MASS   (72.64)
#define ARSENIC_MOLAR_MASS   (74.9216)
#define SELENIUM_MOLAR_MASS   (78.96)
#define BROMINE_MOLAR_MASS   (79.904)
#define KRYPTON_MOLAR_MASS   (83.8)
#define RUBIDIUM_MOLAR_MASS   (85.4678)
#define STRONTIUM_MOLAR_MASS   (87.62)
#define YTTRIUM_MOLAR_MASS   (88.9059)
#define ZIRCONIUM_MOLAR_MASS   (91.224)
#define NIOBIUM_MOLAR_MASS   (92.9064)
#define MOLYBDENUM_MOLAR_MASS   (95.94)
#define TECHNETIUM_MOLAR_MASS   (98)
#define RUTHENIUM_MOLAR_MASS   (101.07)
#define RHODIUM_MOLAR_MASS   (102.9055)
#define PALLADIUM_MOLAR_MASS   (106.42)
#define SILVER_MOLAR_MASS   (107.8682)
#define CADMIUM_MOLAR_MASS   (112.411)
#define INDIUM_MOLAR_MASS   (114.818)
#define TIN_MOLAR_MASS   (118.71)
#define ANTIMONY_MOLAR_MASS   (121.76)
#define TELLURIUM_MOLAR_MASS   (127.6)
#define IODINE_MOLAR_MASS   (126.9045)
#define XENON_MOLAR_MASS   (131.293)
#define CESIUM_MOLAR_MASS   (132.9055)
#define BARIUM_MOLAR_MASS   (137.327)
#define LANTHANUM_MOLAR_MASS   (138.9055)
#define CERIUM_MOLAR_MASS   (140.116)
#define PRASEODYMIUM_MOLAR_MASS   (140.9077)
#define NEODYMIUM_MOLAR_MASS   (144.24)
#define PROMETHIUM_MOLAR_MASS   (145)
#define SAMARIUM_MOLAR_MASS   (150.36)
#define EUROPIUM_MOLAR_MASS   (151.964)
#define GADOLINIUM_MOLAR_MASS   (157.25)
#define TERBIUM_MOLAR_MASS   (158.9253)
#define DYSPROSIUM_MOLAR_MASS   (162.5)
#define HOLMIUM_MOLAR_MASS   (164.9303)
#define ERBIUM_MOLAR_MASS   (167.259)
#define THULIUM_MOLAR_MASS   (168.9342)
#define YTTERBIUM_MOLAR_MASS   (173.04)
#define LUTETIUM_MOLAR_MASS   (174.967)
#define HAFNIUM_MOLAR_MASS   (178.49)
#define TANTALUM_MOLAR_MASS   (180.9479)
#define TUNGSTEN_MOLAR_MASS   (183.84)
#define RHENIUM_MOLAR_MASS   (186.207)
#define OSMIUM_MOLAR_MASS   (190.23)
#define IRIDIUM_MOLAR_MASS   (192.217)
#define PLATINUM_MOLAR_MASS   (195.078)
#define GOLD_MOLAR_MASS   (196.9665)
#define MERCURY_MOLAR_MASS   (200.59)
#define THALLIUM_MOLAR_MASS   (204.3833)
#define LEAD_MOLAR_MASS   (207.2)
#define BISMUTH_MOLAR_MASS   (208.9804)
#define POLONIUM_MOLAR_MASS   (209)
#define ASTATINE_MOLAR_MASS   (210)
#define RADON_MOLAR_MASS   (222)
#define FRANCIUM_MOLAR_MASS   (223)
#define RADIUM_MOLAR_MASS   (226)
#define ACTINIUM_MOLAR_MASS   (227)
#define THORIUM_MOLAR_MASS   (232.0381)
#define PROTACTINIUM_MOLAR_MASS   (231.0359)
#define URANIUM_MOLAR_MASS   (238.0289)
#define NEPTUNIUM_MOLAR_MASS   (237.0)
#define PLUTONIUM_MOLAR_MASS   (244.0)
#define AMERICIUM_MOLAR_MASS   (243.0)
#define CURIUM_MOLAR_MASS   (247.0)
#define BERKELIUM_MOLAR_MASS   (247.0)
#define CALIFORNIUM_MOLAR_MASS   (251.0)
#define EINSTEINIUM_MOLAR_MASS   (252.0)
#define FERMIUM_MOLAR_MASS   (257.0)
#define MENDELEVIUM_MOLAR_MASS   (258.0)
#define NOBELIUM_MOLAR_MASS   (259.0)
#define LAWRENCIUM_MOLAR_MASS   (262.0)
#define RUTHERFORDIUM_MOLAR_MASS   (261.0)
#define DUBNIUM_MOLAR_MASS   (262.0)
#define SEABORGIUM_MOLAR_MASS   (266.0)
#define BOHRIUM_MOLAR_MASS   (264.0)
#define HASSIUM_MOLAR_MASS   (277.0)
#define MEITNERIUM_MOLAR_MASS   (268.0)
#define DARMSTADTIUM_MOLAR_MASS   (281.0)
#define ROENTGENIUM_MOLAR_MASS   (282.0)
#define COPERNICIUM_MOLAR_MASS   (285.0)
#define UNUNTRIUM_MOLAR_MASS   (286.0)
#define FLEROVIUM_MOLAR_MASS   (289.0)
#define UNUNPENTIUM_MOLAR_MASS   (289.0)
#define LIVERMORIUM_MOLAR_MASS   (293.0)
#define UNUNSEPTIUM_MOLAR_MASS   (294.0)
#define UNUNOCTIUM_MOLAR_MASS   (294.0)
#define UNUNENNIUM_MOLAR_MASS   (315.0)
#define UNBINILIUM_MOLAR_MASS   (320.0)
#define UNBIUNIUM_MOLAR_MASS   (321.0)
/* CONSTANTS */
extern const char elementlist[128][16];
/* FUNCTIONS */
#ifdef __GNUC__
double pka(const double ka) __attribute__((const, flatten));
double pkb(const double kb) __attribute__((const, flatten));
int iselement(const char *__restrict__ name) __attribute__((const, flatten, nonnull));
#else
double pka(const double ka);
double pkb(const double kb);
int iselement(const char *__restrict__ name);
#endif


#endif

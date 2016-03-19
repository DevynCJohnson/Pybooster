// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file chemistry_types.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Chemistry-related Data-types (header)
@version 2016.03.18

@section DESCRIPTION
Various chemistry-specific datatypes from amino-acids, to elements, to quarks, to subatomic particles
Data-types use lower-case letters
Enum tags use upper-case letters

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


#ifndef FILE_CHEMISTRY_TYPES_SEEN
#define FILE_CHEMISTRY_TYPES_SEEN


#include "MACROS.h"


/* SUBATOMIC PARTICLES */
/** Datatype representing subatomic-particles */
typedef struct {
    char name[16];
    char symbol[4];
    signed int charge;
    double parity;
    double spin;
} subatomicparticle;

extern const subatomicparticle electron;
extern const subatomicparticle proton;
extern const subatomicparticle neutron;

/** Datatype representing quarks */
typedef struct {
    char name[15];
    char symbol;
    double charge;
    float mass;  // GeV/c^2
    float spin;
} quark;

extern const quark up;
extern const quark down;
extern const quark top;
extern const quark bottom;
extern const quark charm;
extern const quark strange;

/* PERIODIC TABLE */
/**
    Datatype representing atoms\n
    To get a value from an atom, use the format 'ATOM_NAME.ATTRIBUTE'.
    For instance, to get the atomic-mass of 'Hydrogen', use 'hydrogen.atomicmass'.\n
    atom hydrogen = {"HYDROGEN", "H", 1, 1.008};\n
    hydrogen.name -> "HYDROGEN"\n
    hydrogen.symbol -> "H"\n
    hydrogen.atomicnumber -> 1\n
    hydrogen.atomicmass -> 1.008
*/
typedef struct {
    char name[16];
    char symbol[4];
    unsigned int atomicnumber;
    double atomicmass;
} atom;

/** Enum representing the elements of the Periodic Table */
typedef enum {
    HYDROGEN = 1,
    HELIUM = 2,
    LITHIUM = 3,
    BERYLLIUM = 4,
    BORON = 5,
    CARBON = 6,
    NITROGEN = 7,
    OXYGEN = 8,
    FLUORINE = 9,
    NEON = 10,
    SODIUM = 11,
    MAGNESIUM = 12,
    ALUMINIUM = 13,
    SILICON = 14,
    PHOSPHORUS = 15,
    SULFUR = 16,
    CHLORINE = 17,
    ARGON = 18,
    POTASSIUM = 19,
    CALCIUM = 20,
    SCANDIUM = 21,
    TITANIUM = 22,
    VANADIUM = 23,
    CHROMIUM = 24,
    MANGANESE = 25,
    IRON = 26,
    COBALT = 27,
    NICKEL = 28,
    COPPER = 29,
    ZINC = 30,
    GALLIUM = 31,
    GERMANIUM = 32,
    ARSENIC = 33,
    SELENIUM = 34,
    BROMINE = 35,
    KRYPTON = 36,
    RUBIDIUM = 37,
    STRONTIUM = 38,
    YTTRIUM = 39,
    ZIRCONIUM = 40,
    NIOBIUM = 41,
    MOLYBDENUM = 42,
    TECHNETIUM = 43,
    RUTHENIUM = 44,
    RHODIUM = 45,
    PALLADIUM = 46,
    SILVER = 47,
    CADMIUM = 48,
    INDIUM = 49,
    TIN = 50,
    ANTIMONY = 51,
    TELLURIUM = 52,
    IODINE = 53,
    XENON = 54,
    CESIUM = 55,
    BARIUM = 56,
    LANTHANUM = 57,
    CERIUM = 58,
    PRASEODYMIUM = 59,
    NEODYMIUM = 60,
    PROMETHIUM = 61,
    SAMARIUM = 62,
    EUROPIUM = 63,
    GADOLINIUM = 64,
    TERBIUM = 65,
    DYSPROSIUM = 66,
    HOLMIUM = 67,
    ERBIUM = 68,
    THULIUM = 69,
    YTTERBIUM = 70,
    LUTETIUM = 71,
    HAFNIUM = 72,
    TANTALUM = 73,
    TUNGSTEN = 74,
    RHENIUM = 75,
    OSMIUM = 76,
    IRIDIUM = 77,
    PLATINUM = 78,
    GOLD = 79,
    MERCURY = 80,
    THALLIUM = 81,
    LEAD = 82,
    BISMUTH = 83,
    POLONIUM = 84,
    ASTATINE = 85,
    RADON = 86,
    FRANCIUM = 87,
    RADIUM = 88,
    ACTINIUM = 89,
    THORIUM = 90,
    PROTACTINIUM = 91,
    URANIUM = 92,
    NEPTUNIUM = 93,
    PLUTONIUM = 94,
    AMERICIUM = 95,
    CURIUM = 96,
    BERKELIUM = 97,
    CALIFORNIUM = 98,
    EINSTEINIUM = 99,
    FERMIUM = 100,
    MENDELEVIUM = 101,
    NOBELIUM = 102,
    LAWRENCIUM = 103,
    RUTHERFORDIUM = 104,
    DUBNIUM = 105,
    SEABORGIUM = 106,
    BOHRIUM = 107,
    HASSIUM = 108,
    MEITNERIUM = 109,
    DARMSTADTIUM = 110,
    ROENTGENIUM = 111,
    COPERNICIUM = 112,
    UNUNTRIUM = 113,
    FLEROVIUM = 114,
    UNUNPENTIUM = 115,
    LIVERMORIUM = 116,
    UNUNSEPTIUM = 117,
    UNUNOCTIUM = 118,
    UNUNENNIUM = 119,
    UNBINILIUM = 120,
    UNBIUNIUM = 121,
} elements;

/* ATOMS */
extern const atom hydrogen;
extern const atom helium;
extern const atom lithium;
extern const atom beryllium;
extern const atom boron;
extern const atom carbon;
extern const atom nitrogen;
extern const atom oxygen;
extern const atom fluorine;
extern const atom neon;
extern const atom sodium;
extern const atom magnesium;
extern const atom aluminium;
extern const atom silicon;
extern const atom phosphorus;
extern const atom sulfur;
extern const atom chlorine;
extern const atom argon;
extern const atom potassium;
extern const atom calcium;
extern const atom scandium;
extern const atom titanium;
extern const atom vanadium;
extern const atom chromium;
extern const atom manganese;
extern const atom iron;
extern const atom cobalt;
extern const atom nickel;
extern const atom copper;
extern const atom zinc;
extern const atom gallium;
extern const atom germanium;
extern const atom arsenic;
extern const atom selenium;
extern const atom bromine;
extern const atom krypton;
extern const atom rubidium;
extern const atom strontium;
extern const atom yttrium;
extern const atom zirconium;
extern const atom niobium;
extern const atom molybdenum;
extern const atom technetium;
extern const atom ruthenium;
extern const atom rhodium;
extern const atom palladium;
extern const atom silver;
extern const atom cadmium;
extern const atom indium;
extern const atom tin;
extern const atom antimony;
extern const atom tellurium;
extern const atom iodine;
extern const atom xenon;
extern const atom cesium;
extern const atom barium;
extern const atom lanthanum;
extern const atom cerium;
extern const atom praseodymium;
extern const atom neodymium;
extern const atom promethium;
extern const atom samarium;
extern const atom europium;
extern const atom gadolinium;
extern const atom terbium;
extern const atom dysprosium;
extern const atom holmium;
extern const atom erbium;
extern const atom thulium;
extern const atom ytterbium;
extern const atom lutetium;
extern const atom hafnium;
extern const atom tantalum;
extern const atom tungsten;
extern const atom rhenium;
extern const atom osmium;
extern const atom iridium;
extern const atom platinum;
extern const atom gold;
extern const atom mercury;
extern const atom thallium;
extern const atom lead;
extern const atom bismuth;
extern const atom polonium;
extern const atom astatine;
extern const atom radon;
extern const atom francium;
extern const atom radium;
extern const atom actinium;
extern const atom thorium;
extern const atom protactinium;
extern const atom uranium;
extern const atom neptunium;
extern const atom plutonium;
extern const atom americium;
extern const atom curium;
extern const atom berkelium;
extern const atom californium;
extern const atom einsteinium;
extern const atom fermium;
extern const atom mendelevium;
extern const atom nobelium;
extern const atom lawrencium;
extern const atom rutherfordium;
extern const atom dubnium;
extern const atom seaborgium;
extern const atom bohrium;
extern const atom hassium;
extern const atom meitnerium;
extern const atom darmstadtium;
extern const atom roentgenium;
extern const atom copernicium;
extern const atom ununtrium;
extern const atom flerovium;
extern const atom ununpentium;
extern const atom livermorium;
extern const atom ununseptium;
extern const atom ununoctium;
extern const atom ununennium;
extern const atom unbinilium;
extern const atom unbiunium;

/* STATES OF MATTER */
/** Enum representing the classical states of matter */
typedef enum {
    SOLID = 1,
    LIQUID = 2,
    GAS = 4,
    PLASMA = 8,
} classicmatterstates;

/* NUCLEOBASES */
/**
    Datatype representing nucleobases\n
    nucleobase cytosine = {"CYTOSINE", "C", "pyrimidine", "c1cnc(=O)[nH]c1N"};\n
    cytosine.name -> "CYTOSINE"\n
    cytosine.symbol -> "C"\n
    cytosine.type -> "pyrimidine"\n
    cytosine.smiles -> "c1cnc(=O)[nH]c1N"\n
    SMILES = Simplified Molecular-Input Line-Entry System
*/
typedef struct {
    char name[16];
    char symbol[2];
    char type[16];
    char smiles[32];  // Simplified Molecular-Input Line-Entry System
} nucleobase;

extern const nucleobase adenine;
extern const nucleobase cytosine;
extern const nucleobase guanine;
extern const nucleobase thymine;
extern const nucleobase uracil;
extern const char IUPAC_NOTATION[32][2][8];

/* AMINO ACIDS */
/**
    Datatype representing amino-acids\n
    aminoacid alanine = {"ALANINE", "Ala", "A", "O=C(O)[C@@H](N)C"};\n
    alanine.name -> "ALANINE"\n
    alanine.symbol -> "Ala"  // Long abbreviation\n
    alanine.sym -> "A"  // Short abbreviation\n
    alanine.smiles -> "O=C(O)[C@@H](N)C"\n
    SMILES = Simplified Molecular-Input Line-Entry System
*/
typedef struct {
    char name[32];
    char symbol[4];  // Long abbreviation
    char sym[2];  // Short abbreviation
    char smiles[128];  // Simplified Molecular-Input Line-Entry System
} aminoacid;

extern const aminoacid alanine;
extern const aminoacid arginine;
extern const aminoacid asparagine;
extern const aminoacid aspartic_acid;
extern const aminoacid cysteine;
extern const aminoacid glutamic_acid;
extern const aminoacid glutamine;
extern const aminoacid glycine;
extern const aminoacid histidine;
extern const aminoacid isoleucine;
extern const aminoacid leucine;
extern const aminoacid lysine;
extern const aminoacid methionine;
extern const aminoacid phenylalanine;
extern const aminoacid proline;
extern const aminoacid pyrrolysine;
extern const aminoacid selenocysteine;
extern const aminoacid serine;
extern const aminoacid threonine;
extern const aminoacid tryptophan;
extern const aminoacid tyrosine;
extern const aminoacid valine;

/* CODONS */
#ifndef OSWINDOWS
/**
    Datatype representing codons
    UAA, UGA, UAG = STOP\n
    AUG = START
*/
typedef struct {
    char sequence[8];
    const aminoacid *const amino;
} codon;

extern const codon AAA;
extern const codon AAC;
extern const codon AAG;
extern const codon AAU;
extern const codon ACA;
extern const codon ACC;
extern const codon ACG;
extern const codon ACU;
extern const codon AGA;
extern const codon AGC;
extern const codon AGG;
extern const codon AGU;
extern const codon AUA;
extern const codon AUC;
extern const codon AUG;
extern const codon AUU;
extern const codon CAA;
extern const codon CAC;
extern const codon CAG;
extern const codon CAU;
extern const codon CCA;
extern const codon CCC;
extern const codon CCG;
extern const codon CCU;
extern const codon CGA;
extern const codon CGC;
extern const codon CGG;
extern const codon CGU;
extern const codon CUA;
extern const codon CUC;
extern const codon CUG;
extern const codon CUU;
extern const codon GAA;
extern const codon GAC;
extern const codon GAG;
extern const codon GAU;
extern const codon GCA;
extern const codon GCC;
extern const codon GCG;
extern const codon GCU;
extern const codon GGA;
extern const codon GGC;
extern const codon GGG;
extern const codon GGU;
extern const codon GUA;
extern const codon GUC;
extern const codon GUG;
extern const codon GUU;
extern const codon UAC;
extern const codon UAU;
extern const codon UCA;
extern const codon UCC;
extern const codon UCG;
extern const codon UCU;
extern const codon UGC;
extern const codon UGG;
extern const codon UGU;
extern const codon UUA;
extern const codon UUC;
extern const codon UUG;
extern const codon UUU;
#endif

#endif

// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file chemistry_types.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Chemistry-related Data-types
@version 2016.03.20

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


#include "chemistry_types.h"


/* SUBATOMIC PARTICLES */


/** Constant representing an electron */
const subatomicparticle electron = {"ELECTRON", "e-", -1, 1.0, 0.5};
/** Constant representing an proton */
const subatomicparticle proton = {"PROTON", "p", 1, 1.0, 0.5};
/** Constant representing an neutron */
const subatomicparticle neutron = {"NEUTRON", "n", 0, 1.0, 0.5};

const quark up = {"UP\0\0", 'u', 0.666667, 0.0023F, 0.5F};
const quark down = {"DOWN\0\0", 'd', -0.333333, 0.0048F, 0.5F};
const quark top = {"TOP\0\0", 't', 0.666667, 173.0700F, 0.5F};
const quark bottom = {"BOTTOM\0\0", 'b', -0.333333, 4.1800F, 0.5F};
const quark charm = {"CHARM\0\0", 'c', 0.666667, 1.275F, 0.5F};
const quark strange = {"STRANGE\0\0", 's', -0.333333, 0.0950F, 0.5F};


/* ATOMS */


const atom hydrogen = {"HYDROGEN", "H", 1, 1.0079};
const atom helium = {"HELIUM", "He", 2, 4.0026};
const atom lithium = {"LITHIUM", "Li", 3, 6.941};
const atom beryllium = {"BERYLLIUM", "Be", 4, 9.0122};
const atom boron = {"BORON", "B", 5, 10.811};
const atom carbon = {"CARBON", "C", 6, 12.0107};
const atom nitrogen = {"NITROGEN", "N", 7, 14.0067};
const atom oxygen = {"OXYGEN", "O", 8, 15.9994};
const atom fluorine = {"FLUORINE", "F", 9, 18.9984};
const atom neon = {"NEON", "Ne", 10, 20.1797};
const atom sodium = {"SODIUM", "Na", 11, 22.9897};
const atom magnesium = {"MAGNESIUM", "Mg", 12, 24.305};
const atom aluminium = {"ALUMINIUM", "Al", 13, 26.9815};
const atom silicon = {"SILICON", "Si", 14, 28.0855};
const atom phosphorus = {"PHOSPHORUS", "P", 15, 30.9738};
const atom sulfur = {"SULFUR", "S", 16, 32.065};
const atom chlorine = {"CHLORINE", "Cl", 17, 35.453};
const atom argon = {"ARGON", "Ar", 18, 39.948};
const atom potassium = {"POTASSIUM", "K", 19, 39.0983};
const atom calcium = {"CALCIUM", "Ca", 20, 40.078};
const atom scandium = {"SCANDIUM", "Sc", 21, 44.9559};
const atom titanium = {"TITANIUM", "Ti", 22, 47.867};
const atom vanadium = {"VANADIUM", "V", 23, 50.9415};
const atom chromium = {"CHROMIUM", "Cr", 24, 51.9961};
const atom manganese = {"MANGANESE", "Mn", 25, 54.938};
const atom iron = {"IRON", "Fe", 26, 55.845};
const atom cobalt = {"COBALT", "Co", 27, 58.9332};
const atom nickel = {"NICKEL", "Ni", 28, 58.6934};
const atom copper = {"COPPER", "Cu", 29, 63.546};
const atom zinc = {"ZINC", "Zn", 30, 65.39};
const atom gallium = {"GALLIUM", "Ga", 31, 69.723};
const atom germanium = {"GERMANIUM", "Ge", 32, 72.64};
const atom arsenic = {"ARSENIC", "As", 33, 74.9216};
const atom selenium = {"SELENIUM", "Se", 34, 78.96};
const atom bromine = {"BROMINE", "Br", 35, 79.904};
const atom krypton = {"KRYPTON", "Kr", 36, 83.8};
const atom rubidium = {"RUBIDIUM", "Rb", 37, 85.4678};
const atom strontium = {"STRONTIUM", "Sr", 38, 87.62};
const atom yttrium = {"YTTRIUM", "Y", 39, 88.9059};
const atom zirconium = {"ZIRCONIUM", "Zr", 40, 91.224};
const atom niobium = {"NIOBIUM", "Nb", 41, 92.9064};
const atom molybdenum = {"MOLYBDENUM", "Mo", 42, 95.94};
const atom technetium = {"TECHNETIUM", "Tc", 43, 98};
const atom ruthenium = {"RUTHENIUM", "Ru", 44, 101.07};
const atom rhodium = {"RHODIUM", "Rh", 45, 102.9055};
const atom palladium = {"PALLADIUM", "Pd", 46, 106.42};
const atom silver = {"SILVER", "Ag", 47, 107.8682};
const atom cadmium = {"CADMIUM", "Cd", 48, 112.411};
const atom indium = {"INDIUM", "In", 49, 114.818};
const atom tin = {"TIN", "Sn", 50, 118.71};
const atom antimony = {"ANTIMONY", "Sb", 51, 121.76};
const atom tellurium = {"TELLURIUM", "Te", 52, 127.6};
const atom iodine = {"IODINE", "I", 53, 126.9045};
const atom xenon = {"XENON", "Xe", 54, 131.293};
const atom cesium = {"CESIUM", "Cs", 55, 132.9055};
const atom barium = {"BARIUM", "Ba", 56, 137.327};
const atom lanthanum = {"LANTHANUM", "La", 57, 138.9055};
const atom cerium = {"CERIUM", "Ce", 58, 140.116};
const atom praseodymium = {"PRASEODYMIUM", "Pr", 59, 140.9077};
const atom neodymium = {"NEODYMIUM", "Nd", 60, 144.24};
const atom promethium = {"PROMETHIUM", "Pm", 61, 145};
const atom samarium = {"SAMARIUM", "Sm", 62, 150.36};
const atom europium = {"EUROPIUM", "Eu", 63, 151.964};
const atom gadolinium = {"GADOLINIUM", "Gd", 64, 157.25};
const atom terbium = {"TERBIUM", "Tb", 65, 158.9253};
const atom dysprosium = {"DYSPROSIUM", "Dy", 66, 162.5};
const atom holmium = {"HOLMIUM", "Ho", 67, 164.9303};
const atom erbium = {"ERBIUM", "Er", 68, 167.259};
const atom thulium = {"THULIUM", "Tm", 69, 168.9342};
const atom ytterbium = {"YTTERBIUM", "Yb", 70, 173.04};
const atom lutetium = {"LUTETIUM", "Lu", 71, 174.967};
const atom hafnium = {"HAFNIUM", "Hf", 72, 178.49};
const atom tantalum = {"TANTALUM", "Ta", 73, 180.9479};
const atom tungsten = {"TUNGSTEN", "W", 74, 183.84};
const atom rhenium = {"RHENIUM", "Re", 75, 186.207};
const atom osmium = {"OSMIUM", "Os", 76, 190.23};
const atom iridium = {"IRIDIUM", "Ir", 77, 192.217};
const atom platinum = {"PLATINUM", "Pt", 78, 195.078};
const atom gold = {"GOLD", "Au", 79, 196.9665};
const atom mercury = {"MERCURY", "Hg", 80, 200.59};
const atom thallium = {"THALLIUM", "Tl", 81, 204.3833};
const atom lead = {"LEAD", "Pb", 82, 207.2};
const atom bismuth = {"BISMUTH", "Bi", 83, 208.9804};
const atom polonium = {"POLONIUM", "Po", 84, 209};
const atom astatine = {"ASTATINE", "At", 85, 210};
const atom radon = {"RADON", "Rn", 86, 222};
const atom francium = {"FRANCIUM", "Fr", 87, 223};
const atom radium = {"RADIUM", "Ra", 88, 226};
const atom actinium = {"ACTINIUM", "Ac", 89, 227};
const atom thorium = {"THORIUM", "Th", 90, 232.0381};
const atom protactinium = {"PROTACTINIUM", "Pa", 91, 231.0359};
const atom uranium = {"URANIUM", "U", 92, 238.0289};
const atom neptunium = {"NEPTUNIUM", "Np", 93, 237.0};
const atom plutonium = {"PLUTONIUM", "Pu", 94, 244.0};
const atom americium = {"AMERICIUM", "Am", 95, 243.0};
const atom curium = {"CURIUM", "Cm", 96, 247.0};
const atom berkelium = {"BERKELIUM", "Bk", 97, 247.0};
const atom californium = {"CALIFORNIUM", "Cf", 98, 251.0};
const atom einsteinium = {"EINSTEINIUM", "Es", 99, 252.0};
const atom fermium = {"FERMIUM", "Fm", 100, 257.0};
const atom mendelevium = {"MENDELEVIUM", "Md", 101, 258.0};
const atom nobelium = {"NOBELIUM", "No", 102, 259.0};
const atom lawrencium = {"LAWRENCIUM", "Lr", 103, 262.0};
const atom rutherfordium = {"RUTHERFORDIUM", "Rf", 104, 261.0};
const atom dubnium = {"DUBNIUM", "Db", 105, 262.0};
const atom seaborgium = {"SEABORGIUM", "Sg", 106, 266.0};
const atom bohrium = {"BOHRIUM", "Bh", 107, 264.0};
const atom hassium = {"HASSIUM", "Hs", 108, 277.0};
const atom meitnerium = {"MEITNERIUM", "Mt", 109, 268.0};
const atom darmstadtium = {"DARMSTADTIUM", "Ds", 110, 281.0};
const atom roentgenium = {"ROENTGENIUM", "Rg", 111, 282.0};
const atom copernicium = {"COPERNICIUM", "Cn", 112, 285.0};
const atom ununtrium = {"UNUNTRIUM", "Uut", 113, 286.0};
const atom flerovium = {"FLEROVIUM", "Fl", 114, 289.0};
const atom ununpentium = {"UNUNPENTIUM", "Uup", 115, 289.0};
const atom livermorium = {"LIVERMORIUM", "Lv", 116, 293.0};
const atom ununseptium = {"UNUNSEPTIUM", "Uus", 117, 294.0};
const atom ununoctium = {"UNUNOCTIUM", "Uuo", 118, 294.0};
const atom ununennium = {"UNUNENNIUM", "Uue", 119, 315.0};
const atom unbinilium = {"UNBINILIUM", "Ubn", 120, 320.0};
const atom unbiunium = {"UNBIUNIUM", "Ubu", 121, 321.0};


/* NUCLEOBASES */


const nucleobase adenine = {"ADENINE", "A", "purine", "n1c(c2c(nc1)ncn2)N"};
const nucleobase cytosine = {"CYTOSINE", "C", "pyrimidine", "c1cnc(=O)[nH]c1N"};
const nucleobase guanine = {"GUANINE", "G", "purine", "c1[nH]c2c(n1)c(=O)[nH]c(n2)N"};
/** Found in DNA, but not RNA */
const nucleobase thymine = {"THYMINE", "T", "pyrimidine", "Cc1c[nH]c(=O)[nH]c1=O"};
/** Found in RNA, but not DNA */
const nucleobase uracil = {"URACIL", "U", "pyrimidine", "O=C1NC=CC(=O)N1"};


/** Standardized set of letters representing certain nucleic acid sequences */
const char IUPAC_NOTATION[32][2][8] = {
    {"A", "A"},
    {"C", "C"},
    {"G", "G"},
    {"T", "T"},
    {"U", "U"},
    {"W", "AT"},
    {"S", "CG"},
    {"M", "AC"},
    {"K", "GT"},
    {"R", "AG"},
    {"Y", "CT"},
    {"B", "CGT"},
    {"D", "AGT"},
    {"H", "ACT"},
    {"V", "ACG"},
    {"N", "ACGTU"},
    {"-", "ACGTU"},
};


/* AMINO ACIDS */


const aminoacid alanine = {"ALANINE", "Ala", "A", "O=C(O)[C@@H](N)C"};
const aminoacid arginine = {"ARGININE", "Arg", "R", "NC(CCC[nH]:c(:[nH]):[nH2])c(:[o]):[oH]"};
const aminoacid asparagine = {"ASPARAGINE", "Asn", "N", "C([C@@H](C(=O)O)N)C(=O)N"};
const aminoacid aspartic_acid = {"ASPARTIC ACID", "Asp", "D", "C(C(C(=O)O)N)C(=O)O"};
const aminoacid cysteine = {"CYSTEINE", "Cys", "C", "C([C@@H](C(=O)O)N)S"};
const aminoacid glutamic_acid = {"GLUTAMIC ACID", "Glu", "E", "C(CC(=O)O)C(C(=O)O)N"};
const aminoacid glutamine = {"GLUTAMINE", "Gln", "Q", "O=C(N)CCC(N)C(=O)O"};
const aminoacid glycine = {"GLYCINE", "Gly", "G", "C(C(=O)O)N"};
const aminoacid histidine = {"HISTIDINE", "His", "H", "O=C([C@H](CC1=CNC=N1)N)O"};
const aminoacid isoleucine = {"ISOLEUCINE", "Ile", "I", "CC[C@H](C)[C@@H](C(=O)O)N"};
const aminoacid leucine = {"LEUCINE", "Leu", "L", "CC(C)C[C@@H](C(=O)O)N"};
const aminoacid lysine = {"LYSINE", "Lys", "K", "C(CCN)CC(C(=O)O)N"};
const aminoacid methionine = {"METHIONINE", "Met", "M", "CSCCC(C(=O)O)N"};
const aminoacid phenylalanine = {"PHENYLALANINE", "Phe", "F", "N[C@@H](CC1=CC=CC=C1)C(O)=O"};
const aminoacid proline = {"PROLINE", "Pro", "P", "OC(=O)C1CCCN1"};
const aminoacid pyrrolysine = {"PYRROLYSINE", "Pyl", "O", "O=C(NCCCC[C@@H](C(=O)O)N)[C@@H]1/N=C\\C[C@H]1C"};
const aminoacid selenocysteine = {"SELENOCYSTEINE", "Sec", "U", "O=C(O)[C@@H](N)C[SeH]"};
const aminoacid serine = {"SERINE", "Ser", "S", "C([C@@H](C(=O)O)N)O"};
const aminoacid threonine = {"THREONINE", "Thr", "T", "C[C@H]([C@@H](C(=O)O)N)O"};
const aminoacid tryptophan = {"TRYPTOPHAN", "Trp", "W", "c1ccc2c(c1)c(c[nH]2)C[C@@H](C(=O)O)N"};
const aminoacid tyrosine = {"TYROSINE", "Tyr", "Y", "N[C@@H](Cc1ccc(O)cc1)C(O)=O"};
const aminoacid valine = {"VALINE", "Val", "V", "CC(C)[C@@H](C(=O)O)N"};


/* CODONS */


#ifndef OSWINDOWS
const codon AAA = {"AAA\0\0\0\0", &lysine};
const codon AAC = {"AAC\0\0\0\0", &asparagine};
const codon AAG = {"AAG\0\0\0\0", &lysine};
const codon AAU = {"AAU\0\0\0\0", &asparagine};
const codon ACA = {"ACA\0\0\0\0", &threonine};
const codon ACC = {"ACC\0\0\0\0", &threonine};
const codon ACG = {"ACG\0\0\0\0", &threonine};
const codon ACU = {"ACU\0\0\0\0", &threonine};
const codon AGA = {"AGA\0\0\0\0", &arginine};
const codon AGC = {"AGC\0\0\0\0", &serine};
const codon AGG = {"AGG\0\0\0\0", &arginine};
const codon AGU = {"AGU\0\0\0\0", &serine};
const codon AUA = {"AUA\0\0\0\0", &isoleucine};
const codon AUC = {"AUC\0\0\0\0", &isoleucine};
/**
    AUG = START codon
    UAA = STOP codon
    UGA = STOP codon
    UAG = STOP codon
*/
const codon AUG = {"AUG\0\0\0\0", &methionine};
const codon AUU = {"AUU\0\0\0\0", &isoleucine};
const codon CAA = {"CAA\0\0\0\0", &glutamine};
const codon CAC = {"CAC\0\0\0\0", &histidine};
const codon CAG = {"CAG\0\0\0\0", &glutamine};
const codon CAU = {"CAU\0\0\0\0", &histidine};
const codon CCA = {"CCA\0\0\0\0", &proline};
const codon CCC = {"CCC\0\0\0\0", &proline};
const codon CCG = {"CCG\0\0\0\0", &proline};
const codon CCU = {"CCU\0\0\0\0", &proline};
const codon CGA = {"CGA\0\0\0\0", &arginine};
const codon CGC = {"CGC\0\0\0\0", &arginine};
const codon CGG = {"CGG\0\0\0\0", &arginine};
const codon CGU = {"CGU\0\0\0\0", &arginine};
const codon CUA = {"CUA\0\0\0\0", &leucine};
const codon CUC = {"CUC\0\0\0\0", &leucine};
const codon CUG = {"CUG\0\0\0\0", &leucine};
const codon CUU = {"CUU\0\0\0\0", &leucine};
const codon GAA = {"GAA\0\0\0\0", &glutamic_acid};
const codon GAC = {"GAC\0\0\0\0", &aspartic_acid};
const codon GAG = {"GAG\0\0\0\0", &glutamic_acid};
const codon GAU = {"GAU\0\0\0\0", &aspartic_acid};
const codon GCA = {"GCA\0\0\0\0", &alanine};
const codon GCC = {"GCC\0\0\0\0", &alanine};
const codon GCG = {"GCG\0\0\0\0", &alanine};
const codon GCU = {"GCU\0\0\0\0", &alanine};
const codon GGA = {"GGA\0\0\0\0", &glycine};
const codon GGC = {"GGC\0\0\0\0", &glycine};
const codon GGG = {"GGG\0\0\0\0", &glycine};
const codon GGU = {"GGU\0\0\0\0", &glycine};
const codon GUA = {"GUA\0\0\0\0", &valine};
const codon GUC = {"GUC\0\0\0\0", &valine};
const codon GUG = {"GUG\0\0\0\0", &valine};
const codon GUU = {"GUU\0\0\0\0", &valine};
const codon UAC = {"UAC\0\0\0\0", &tyrosine};
const codon UAU = {"UAU\0\0\0\0", &tyrosine};
const codon UCA = {"UCA\0\0\0\0", &serine};
const codon UCC = {"UCC\0\0\0\0", &serine};
const codon UCG = {"UCG\0\0\0\0", &serine};
const codon UCU = {"UCU\0\0\0\0", &serine};
const codon UGC = {"UGC\0\0\0\0", &cysteine};
const codon UGG = {"UGG\0\0\0\0", &tryptophan};
const codon UGU = {"UGU\0\0\0\0", &cysteine};
const codon UUA = {"UUA\0\0\0\0", &leucine};
const codon UUC = {"UUC\0\0\0\0", &phenylalanine};
const codon UUG = {"UUG\0\0\0\0", &leucine};
const codon UUU = {"UUU\0\0\0\0", &phenylalanine};
#endif

#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Common regular expression patterns

@file libregex.py
@package pybooster.libregex
@version 2018.10.02
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This software is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
"""


__all__: list = [
    # GENERAL PATTERNS #
    r'BINNUM',
    r'EMAIL',
    r'EXPNUM',
    r'GREEK_ALL',
    r'HEXESCTAG',
    r'HEXESCURI',
    r'HEXNUM',
    r'LEADING_TRAILING_WHITESPACE',
    r'LEADING_WHITESPACE',
    r'OCTNUM',
    r'ODD_WHITESPACE',
    r'PHONE',
    r'TRAILING_WHITESPACE',
    r'TRAILING_ZEROS',
    r'WHITESPACE',
    r'WHITESPACE_NEWLINE',
    # UNICODE CHARACTER BLOCKS #
    r'BASIC_LATIN',
    r'C0_CONTROLS',
    r'LATIN_1_SUPPLEMENT',
    r'LATIN_EXTENDED_A',
    r'LATIN_EXTENDED_B',
    r'IPA_EXTENSIONS',
    r'SPACING_MODIFIER_LETTERS',
    r'COMBINING_DIACRITICAL_MARKS',
    r'GREEK_AND_COPTIC',
    r'CYRILLIC',
    r'CYRILLIC_SUPPLEMENT',
    r'ARMENIAN',
    r'HEBREW',
    r'ARABIC',
    r'SYRIAC',
    r'ARABIC_SUPPLEMENT',
    r'THAANA',
    r'NKO',
    r'SAMARITAN',
    r'MANDAIC',
    r'SYRIAC_SUPPLEMENT',
    r'ARABIC_EXTENDED_A',
    r'DEVANAGARI',
    r'BENGALI',
    r'GURMUKHI',
    r'GUJARATI',
    r'ORIYA',
    r'TAMIL',
    r'TELUGU',
    r'KANNADA',
    r'MALAYALAM',
    r'SINHALA',
    r'THAI',
    r'LAO',
    r'TIBETAN',
    r'MYANMAR',
    r'GEORGIAN',
    r'HANGUL_JAMO',
    r'ETHIOPIC',
    r'ETHIOPIC_SUPPLEMENT',
    r'CHEROKEE',
    r'UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS',
    r'OGHAM',
    r'RUNIC',
    r'TAGALOG',
    r'HANUNOO',
    r'BUHID',
    r'TAGBANWA',
    r'KHMER',
    r'MONGOLIAN',
    r'UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED',
    r'LIMBU',
    r'TAI_LE',
    r'NEW_TAI_LUE',
    r'KHMER_SYMBOLS',
    r'BUGINESE',
    r'TAI_THAM',
    r'COMBINING_DIACRITICAL_MARKS_EXTENDED',
    r'BALINESE',
    r'SUNDANESE',
    r'BATAK',
    r'LEPCHA',
    r'OL_CHIKI',
    r'CYRILLIC_EXTENDED_C',
    r'GEORGIAN_EXTENDED',
    r'SUNDANESE_SUPPLEMENT',
    r'VEDIC_EXTENSIONS',
    r'PHONETIC_EXTENSIONS',
    r'PHONETIC_EXTENSIONS_SUPPLEMENT',
    r'COMBINING_DIACRITICAL_MARKS_SUPPLEMENT',
    r'LATIN_EXTENDED_ADDITIONAL',
    r'GREEK_EXTENDED',
    r'GENERAL_PUNCTUATION',
    r'SUPERSCRIPTS_AND_SUBSCRIPTS',
    r'CURRENCY_SYMBOLS',
    r'COMBINING_DIACRITICAL_MARKS_FOR_SYMBOLS',
    r'LETTERLIKE_SYMBOLS',
    r'NUMBER_FORMS',
    r'ARROWS',
    r'MATHEMATICAL_OPERATORS',
    r'MISCELLANEOUS_TECHNICAL',
    # XML SOURCE CODE PATTERNS #
    r'CHARREF',
    r'INCOMPLETE_REF',
    r'ENTITY_REF',
    r'CHAR_REF',
    r'CHAR_REF2',
    # C SOURCE CODE PATTERNS #
    r'DATATYPES',
    r'DEVELOPER_NOTE',
    r'MACROS',
    r'PRINTF_FMT'
]


try:  # Regular Expression module
    from regex import compile as rgxcompile
except ImportError:
    from re import compile as rgxcompile


# GENERAL PATTERNS #


BINNUM = rgxcompile(r'0[bB][01]+')
EMAIL = rgxcompile(r'[A-Za-z0-9_\-!#\$%\' <>&"\(\),:;@\[\\\]\*\+/=\?\^`\{\|\}~\.]+@[A-Za-z0-9\-]\.[A-Za-z0-9\-]+')
EXPNUM = rgxcompile(r'[eE][-+]?[0-9]+')
GREEK_ALL = rgxcompile(r'[\u0370-\u03FF \u1F00-\u1FFF]+')
HEXESCTAG = rgxcompile(r'&#x[A-Fa-f0-9]+;')
HEXESCURI = rgxcompile(r'%[A-Fa-f0-9]+')
HEXNUM = rgxcompile(r'0[xX][A-Fa-f0-9]+')
OCTNUM = rgxcompile(r'0[oO][0-7]+')
ODD_WHITESPACE = rgxcompile(r'[\xA0\u1680\u180E\u2000-\u200D\u2028\u2029\u202F\u205F\u2060\u3000\U0000FEFF]+')
PHONE = rgxcompile(r'[\(]?[0-9]{3}[\)]?[\- ]?[0-9]{3}[\- ]?[0-9]{4}')
LEADING_TRAILING_WHITESPACE = rgxcompile(r'(^\s+)|(\s+$)')
LEADING_WHITESPACE = rgxcompile(r'^\s+')
TRAILING_ZEROS = rgxcompile(r'\d*\.(\d*?)(0+)$')
TRAILING_WHITESPACE = rgxcompile(r'\s+$')
WHITESPACE = rgxcompile(r'\s+')
WHITESPACE_NEWLINE = rgxcompile(r'\s*(\f|\r|\n)+\s*')


# UNICODE CHARACTER BLOCKS #


# TODO: Add all unicode blocks https://en.wikipedia.org/wiki/Unicode_block

BASIC_LATIN = rgxcompile(r'[\x00-\x7F]+')
C0_CONTROLS = rgxcompile(r'[\x00-\x1F\x7F]+')
LATIN_1_SUPPLEMENT = rgxcompile(r'[\x80-\xFF]+')
LATIN_EXTENDED_A = rgxcompile(r'[\u0100-\u017F]+')
LATIN_EXTENDED_B = rgxcompile(r'[\u0180-\u024F]+')
IPA_EXTENSIONS = rgxcompile(r'[\u0250-\u02AF]+')
SPACING_MODIFIER_LETTERS = rgxcompile(r'[\u02B0-\u02FF]+')
COMBINING_DIACRITICAL_MARKS = rgxcompile(r'[\u0300-\u036F]+')
GREEK_AND_COPTIC = rgxcompile(r'[\u0370-\u03FF]+')
CYRILLIC = rgxcompile(r'[\u0400-\u04FF]+')
CYRILLIC_SUPPLEMENT = rgxcompile(r'[\u0400-\u052F]+')
ARMENIAN = rgxcompile(r'[\u0530-\u058F]+')
HEBREW = rgxcompile(r'[\u0590-\u05FF]+')
ARABIC = rgxcompile(r'[\u0600-\u06FF]+')
SYRIAC = rgxcompile(r'[\u0700-\u074F]+')
ARABIC_SUPPLEMENT = rgxcompile(r'[\u0750-\u077F]+')
THAANA = rgxcompile(r'[\u0780-\u07BF]+')
NKO = rgxcompile(r'[\u07C0-\u07FF]+')
SAMARITAN = rgxcompile(r'[\u0800-\u083F]+')
MANDAIC = rgxcompile(r'[\u0840-\u085F]+')
SYRIAC_SUPPLEMENT = rgxcompile(r'[\u0860-\u086F]+')
ARABIC_EXTENDED_A = rgxcompile(r'[\u08A0-\u08FF]+')
DEVANAGARI = rgxcompile(r'[\u0900-\u097F]+')
BENGALI = rgxcompile(r'[\u0980-\u09FF]+')
GURMUKHI = rgxcompile(r'[\u0A00-\u0A7F]+')
GUJARATI = rgxcompile(r'[\u0A80-\u0AFF]+')
ORIYA = rgxcompile(r'[\u0B00-\u0B7F]+')
TAMIL = rgxcompile(r'[\u0B80-\u0BFF]+')
TELUGU = rgxcompile(r'[\u0C00-\u0C7F]+')
KANNADA = rgxcompile(r'[\u0C80-\u0CFF]+')
MALAYALAM = rgxcompile(r'[\u0D00-\u0D7F]+')
SINHALA = rgxcompile(r'[\u0D80-\u0DFF]+')
THAI = rgxcompile(r'[\u0E00-\u0E7F]+')
LAO = rgxcompile(r'[\u0E80-\u0EFF]+')
TIBETAN = rgxcompile(r'[\u0F00-\u0FFF]+')
MYANMAR = rgxcompile(r'[\u1000-\u109F]+')
GEORGIAN = rgxcompile(r'[\u10A0-\u10FF]+')
HANGUL_JAMO = rgxcompile(r'[\u1100-\u11FF]+')
ETHIOPIC = rgxcompile(r'[\u1200-\u137F]+')
ETHIOPIC_SUPPLEMENT = rgxcompile(r'[\u1380-\u139F]+')
CHEROKEE = rgxcompile(r'[\u13A0-\u13FF]+')
UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS = rgxcompile(r'[\u1400-\u167F]+')
OGHAM = rgxcompile(r'[\u1680-\u169F]+')
RUNIC = rgxcompile(r'[\u16A0-\u16FF]+')
TAGALOG = rgxcompile(r'[\u1700-\u171F]+')
HANUNOO = rgxcompile(r'[\u1720-\u173F]+')
BUHID = rgxcompile(r'[\u1740-\u175F]+')
TAGBANWA = rgxcompile(r'[\u1760-\u177F]+')
KHMER = rgxcompile(r'[\u1780-\u17FF]+')
MONGOLIAN = rgxcompile(r'[\u1800-\u18AF]+')
UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED = rgxcompile(r'[\u18B0-\u18FF]+')
LIMBU = rgxcompile(r'[\u1900-\u194F]+')
TAI_LE = rgxcompile(r'[\u1950-\u197F]+')
NEW_TAI_LUE = rgxcompile(r'[\u1980-\u19DF]+')
KHMER_SYMBOLS = rgxcompile(r'[\u19E0-\u19FF]+')
BUGINESE = rgxcompile(r'[\u1A00-\u1A1F]+')
TAI_THAM = rgxcompile(r'[\u1A20-\u1AAF]+')
COMBINING_DIACRITICAL_MARKS_EXTENDED = rgxcompile(r'[\u1AB0-\u1AFF]+')
BALINESE = rgxcompile(r'[\u1B00-\u1B7F]+')
SUNDANESE = rgxcompile(r'[\u1B80-\u1BBF]+')
BATAK = rgxcompile(r'[\u1BC0-\u1BFF]+')
LEPCHA = rgxcompile(r'[\u1C00-\u1C4F]+')
OL_CHIKI = rgxcompile(r'[\u1C50-\u1C7F]+')
CYRILLIC_EXTENDED_C = rgxcompile(r'[\u1C80-\u1C8F]+')
GEORGIAN_EXTENDED = rgxcompile(r'[\u1C90-\u1CBF]+')
SUNDANESE_SUPPLEMENT = rgxcompile(r'[\u1CC0-\u1CCF]+')
VEDIC_EXTENSIONS = rgxcompile(r'[\u1CD0-\u1CFF]+')
PHONETIC_EXTENSIONS = rgxcompile(r'[\u1D00-\u1D7F]+')
PHONETIC_EXTENSIONS_SUPPLEMENT = rgxcompile(r'[\u1D80-\u1DBF]+')
COMBINING_DIACRITICAL_MARKS_SUPPLEMENT = rgxcompile(r'[\u1DC0-\u1DFF]+')
LATIN_EXTENDED_ADDITIONAL = rgxcompile(r'[\u1E00-\u1EFF]+')
GREEK_EXTENDED = rgxcompile(r'[\u1F00-\u1FFF]+')
GENERAL_PUNCTUATION = rgxcompile(r'[\u2000-\u206F]+')
SUPERSCRIPTS_AND_SUBSCRIPTS = rgxcompile(r'[\u2070-\u209F]+')
CURRENCY_SYMBOLS = rgxcompile(r'[\u20A0-\u20CF]+')
COMBINING_DIACRITICAL_MARKS_FOR_SYMBOLS = rgxcompile(r'[\u20D0-\u20FF]+')
LETTERLIKE_SYMBOLS = rgxcompile(r'[\u2100-\u214F]+')
NUMBER_FORMS = rgxcompile(r'[\u2150-\u218F]+')
ARROWS = rgxcompile(r'[\u2190-\u21FF]+')
MATHEMATICAL_OPERATORS = rgxcompile(r'[\u2200-\u22FF]+')
MISCELLANEOUS_TECHNICAL = rgxcompile(r'[\u2300-\u23FF]+')


# XML SOURCE CODE PATTERNS #


CHARREF = rgxcompile(r'&(#[0-9]+;|#[xX]+[0-9A-Fa-f]+;|[A-Za-z0-9]+;)')
INCOMPLETE_REF = rgxcompile('&[#]?[0-9A-Za-z]+')
ENTITY_REF = rgxcompile('&[0-9A-Za-z]+;')
CHAR_REF = rgxcompile('&#(?:[0-9]+|[Xx][0-9A-Fa-f]+);')
CHAR_REF2 = rgxcompile(
    r'&(#[0-9]+;?'
    r'|#[xX][0-9a-fA-F]+;?'
    r'|[^\t\n\f <&#;]{1,32};?)'
)


# C SOURCE CODE PATTERNS #


DATATYPES: str = r'((((signed|unsigned|)( |)(short|long|long long|)( |)int)|(_BOOL|_Decimal128|_Decimal32|_Decimal64|bool|char|decimal128|decimal32|decimal64|double|enum|FILE|float|float128|float128_t|float64_t|int|int128_t|int16_t|int32_t|int64_t|int8_t|long double|PyObject|string|struct|uint128_t|uint16_t|uint32_t|uint64_t|uint8_t|union|wchar|)|(slint|sllint|ulint|ullint))(\*| \*|\* | \* |))'


DEVELOPER_NOTE = rgxcompile(r'(//|/\*|/\*\*)( |)(DEBUG|FINISH|FIX|FIXME|REPAIR|TODO|TOMV|TORM|XXX)(:| |$)')


MACROS: str = r'(assert|define|elif|else|endif|error|ident|if|ifdef|ifndef|import|include|include_next|line|pragma|sccs|unassert|undef|warning)'


PRINTF_FMT: str = r'''\
(%                       # Literal "%"
(?:                      # First option
(?:[-+0 #]{0,5})         # Optional flags
(?:\d+|\*)?              # Width
(?:\.(?:\d+|\*))?        # Precision
(?:h|l|ll|w|I|I32|I64)?  # Size
[cCdiouxXeEfgGaAnpsSZ]   # Type
) | (%%))                # Literal "%%"
'''

#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Common regular expression patterns

@file libregex.py
@package pybooster.libregex
@version 2018.09.11
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
GREEK_ALL = rgxcompile(r'[\x0370-\x03FF\x1F00-\x1FFF]+')
HEXESCTAG = rgxcompile(r'&#x[A-Fa-f0-9]+;')
HEXESCURI = rgxcompile(r'%[A-Fa-f0-9]+')
HEXNUM = rgxcompile(r'0[xX][A-Fa-f0-9]+')
OCTNUM = rgxcompile(r'0[oO][0-7]+')
ODD_WHITESPACE = rgxcompile(r'[\xA0\x1680\x180E\x2000-\x200D\x2028\x2029\x202F\x205F\x2060\x3000\xFEFF]+')
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
LATIN_1_SUPPLEMENT = rgxcompile(r'[\x80-\xFF]+')
LATIN_EXTENDED_A = rgxcompile(r'[\x0100-\x017F]+')
LATIN_EXTENDED_B = rgxcompile(r'[\x0180-\x024F]+')
IPA_EXTENSIONS = rgxcompile(r'[\x0250-\x02AF]+')
SPACING_MODIFIER_LETTERS = rgxcompile(r'[\x02B0-\x02FF]+')
COMBINING_DIACRITICAL_MARKS = rgxcompile(r'[\x0300-\x036F]+')
GREEK_AND_COPTIC = rgxcompile(r'[\x0370-\x03FF]+')
CYRILLIC = rgxcompile(r'[\x0400-\x04FF]+')
CYRILLIC_SUPPLEMENT = rgxcompile(r'[\x0400-\x052F]+')
ARMENIAN = rgxcompile(r'[\x0530-\x058F]+')
HEBREW = rgxcompile(r'[\x0590-\x05FF]+')
ARABIC = rgxcompile(r'[\x0600-\x06FF]+')
SYRIAC = rgxcompile(r'[\x0700-\x074F]+')
ARABIC_SUPPLEMENT = rgxcompile(r'[\x0750-\x077F]+')


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

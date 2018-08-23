#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Common regular expression patterns

@file libregex.py
@package pybooster.libregex
@version 2018.08.23
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


__all__ = [
    # GENERAL PATTERNS #
    r'HEXESCTAG',
    r'HEXESCURI',
    r'LEADING_TRAILING_WHITESPACE',
    r'LEADING_WHITESPACE',
    r'TRAILING_ZEROS',
    r'TRAILING_WHITESPACE',
    r'WHITESPACE',
    r'WHITESPACE_NEWLINE',
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


HEXESCTAG = rgxcompile(r'&#x([A-Fa-f0-9]+);')
HEXESCURI = rgxcompile(r'%([A-Fa-f0-9]+)')
LEADING_TRAILING_WHITESPACE = rgxcompile(r'(^\s+)|(\s+$)')
LEADING_WHITESPACE = rgxcompile(r'^\s+')
TRAILING_ZEROS = rgxcompile(r'\d*\.(\d*?)(0+)$')
TRAILING_WHITESPACE = rgxcompile(r'\s+$')
WHITESPACE = rgxcompile(r'\s+')
WHITESPACE_NEWLINE = rgxcompile(r'\s*(\f|\r|\n)+\s*')


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


DATATYPES = r'((((signed|unsigned|)( |)(short|long|long long|)( |)int)|(_BOOL|_Decimal128|_Decimal32|_Decimal64|bool|char|decimal128|decimal32|decimal64|double|enum|FILE|float|float128|float128_t|float64_t|int|int128_t|int16_t|int32_t|int64_t|int8_t|long double|PyObject|string|struct|uint128_t|uint16_t|uint32_t|uint64_t|uint8_t|union|wchar|)|(slint|sllint|ulint|ullint))(\*| \*|\* | \* |))'


DEVELOPER_NOTE = rgxcompile(r'(//|/\*|/\*\*)( |)(DEBUG|FINISH|FIX|FIXME|REPAIR|TODO|TOMV|TORM|XXX)(:| |$)')


MACROS = r'(assert|define|elif|else|endif|error|ident|if|ifdef|ifndef|import|include|include_next|line|pragma|sccs|unassert|undef|warning)'


PRINTF_FMT = r'''\
(%                       # Literal "%"
(?:                      # First option
(?:[-+0 #]{0,5})         # Optional flags
(?:\d+|\*)?              # Width
(?:\.(?:\d+|\*))?        # Precision
(?:h|l|ll|w|I|I32|I64)?  # Size
[cCdiouxXeEfgGaAnpsSZ]   # Type
) | (%%))                # Literal "%%"
'''

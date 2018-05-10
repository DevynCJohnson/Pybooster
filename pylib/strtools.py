#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Functions for various character and string manipulations

@file strtools.py
@package pybooster.strtools
@version 2018.04.27
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This library contains
 - Constants for various characters and character ranges
 - Functions for various character and string manipulations

@section VARIABLES
 - _refnum: stores an HTML reference number as a string (&#38;)
 - _name: stores an unicode character name
 - _char: stores a single character or an escape sequence
 - _str: stores a string/text
 - _int: stores an integer
 - _hex: stores a hex sequence as an integer, str, or escape sequence
 - _oct: stores an octal sequence as an integer, str, or escape sequence
 - _bin: stores a binary sequence as an integer, str, or escape sequence
 - _bytes: stores a bytes-type object
 - _dict: specify a dictionary
 - _search: a value to find
 - _assert: indicate that some condition be met
 - _numbase: specify the base of the number ('2'=binary; '16'=hex; etc.)
 - _escape: boolean; "True" (the default) makes a function escape the output
 - _endian: specify endian (little/big); default is the native value
 - _encoding: specify encoding; the default value is "utf8"

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


from ast import literal_eval
from sys import byteorder

try:  # Regular Expression module
    import regex as re  # noqa: E402  # pylint: disable=C0411
except ImportError:
    import re  # noqa: E402  # pylint: disable=C0411

from pybooster.libchar import (
    BRAILLE,
    GREEK_ALL,
    LOWER_LIMIT_ASCII_CTRL,
    LOWER_LIMIT_ASCII_EXT,
    LOWER_LIMIT_ASCII_PRNT,
    NUMBER_LIST,
    ORDINAL_LIST,
    PLAIN_TEXT,
    UPPER_LIMIT_ASCII_CTRL,
    UPPER_LIMIT_ASCII_EXT,
    UPPER_LIMIT_ASCII_PRNT,
    UPPER_LIMIT_UNICODE,
    UPPER_LIMIT_UTF8
)
from pybooster.markup import CHAR_REF, ENTITY_REF


__all__ = [
    # STRING MANIPULATIONS #
    r'endletters',
    r'firstletters',
    r'lastletters',
    r'middleletters',
    r'insert_character',
    r'num2ordinal',
    r'ordinal2num',
    r'cap',
    r'formal',
    r'lowercase',
    r'sentence',
    r'togglecase',
    r'uppercase',
    r'explode',
    r'implode',
    r'rmcurlycommas',
    r'replacecurlycommas',
    r'rmcurlyquotes',
    r'replacecurlyquotes',
    r'rmpunct',
    r'splitsentencesstr',
    r'sqlstr',
    r'presentlist',
    # MISCELLANEOUS FUNCTIONS #
    r'fval',
    r'noescape',
    # BOOLEAN TESTS #
    r'isascii',
    r'isstrascii',
    r'isctrlascii',
    r'isstrctrlascii',
    r'isprntascii',
    r'isstrprntascii',
    r'isextascii',
    r'isstrextascii',
    r'isgreek',
    r'isstrgreek',
    r'hasgreek',
    r'isbraille',
    r'isstrbraille',
    r'hasbraille',
    r'isutf8',
    r'isutf16',
    r'isunicode',
    r'hashexescape',
    r'testref',
    r'is_palindrome',
    # LENGTHS #
    r'utf7len',
    r'utf8len',
    r'utf16len',
    r'utf32len',
    # ESCAPE MANIPULATIONS #
    r'findescapes',
    r'shrink_esc_utf16to8',
    r'shrink_esc_utf32to8',
    r'shrink_esc_utf32to16',
    r'noescutf8hex',
    r'expandhexescape',
    r'char2noeschex',
    r'str2noeschex',
    r'str2hexcolon',
    r'rmbyteshexesc',
    r'rplbyteshexesc',
    # X 2 CHARACTER #
    r'int2char',
    r'hexstr2char',
    r'hexint2char',
    r'octstr2char',
    r'octint2char',
    r'binstr2char',
    r'binint2char',
    r'name2char',
    # X 2 INTEGER #
    r'char2int',
    r'refnum2int',
    r'ncr2int',
    # X 2 UTF* #
    r'utf8convchar2hexescape',
    r'utf8convchar2hexstr',
    r'utf8convchar2uri',
    r'utf8convchar2intstr',
    r'int2utf16',
    r'int2utf32',
    # X 2 HEX #
    r'char2hexstr',
    r'hex2unicodehex',
    r'hex2cssnot',
    # X 2 MISC #
    r'char2intstr',
    r'str2bytes',
    r'bytes2str',
    r'int2hexbytes',
    r'hexstr2bytearray',
    # BUBBLE TEXT #
    r'text2bubble',
    r'bubble2text',
    # SQUARE TEXT #
    r'text2square',
    r'square2text'
]


# GLOBALS #


TRANS_BUBBLE2TEST = str.maketrans(r'ⒶⒷⒸⒹⒺⒻⒼⒽⒾⒿⓀⓁⓂⓃⓄⓅⓆⓇⓈⓉⓊⓋⓌⓍⓎⓏⓐⓑⓒⓓⓔⓕⓖⓗⓘⓙⓚⓛⓜⓝⓞⓟⓠⓡⓢⓣⓤⓥⓦⓧⓨⓩ ⓪①②③④⑤⑥⑦⑧⑨', r'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 0123456789')
TRANS_TEXT2BUBBLE = str.maketrans(r'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 0123456789', r'ⒶⒷⒸⒹⒺⒻⒼⒽⒾⒿⓀⓁⓂⓃⓄⓅⓆⓇⓈⓉⓊⓋⓌⓍⓎⓏⓐⓑⓒⓓⓔⓕⓖⓗⓘⓙⓚⓛⓜⓝⓞⓟⓠⓡⓢⓣⓤⓥⓦⓧⓨⓩ ⓪①②③④⑤⑥⑦⑧⑨')


# STRING MANIPULATIONS #


def endletters(_str: str) -> str:
    """Keep the first and last letter of a single word

    >>> endletters('Test')
    'Tt'
    """
    return _str[:1] + _str[-1:]


def firstletters(_str: str) -> str:
    """Remove the last letter of a single word

    >>> firstletters('Test')
    'Tes'
    """
    return _str[:-1]


def lastletters(_str: str) -> str:
    """Remove the first letter of a single word

    >>> lastletters('Test')
    'est'
    """
    return _str[1:]


def middleletters(_str: str) -> str:
    """Remove the first and last letter of a single word

    >>> middleletters('Test')
    'es'
    """
    return _str[1:-1]


def insert_character(_str: str, _char: str, index: int) -> str:
    """Insert a character at the specified point of a string"""
    return _str[:index] + _char + _str[index:]


def num2ordinal(_str: str) -> str:
    """Convert numbers to ordinals

    >>> num2ordinal('21')
    'twenty-first'
    """
    for _key in NUMBER_LIST:
        if _str == _key:
            _str = _str.lower().replace(_key, NUMBER_LIST[_key])
    return _str


def ordinal2num(_str: str) -> str:
    """Convert ordinals to numbers

    >>> ordinal2num('twenty-first')
    '21'
    """
    for _key in ORDINAL_LIST:
        if _str == _key:
            _str = _str.lower().replace(_key, ORDINAL_LIST[_key])
    return _str


def cap(_str: str) -> str:
    """Capitalize the beginning of each word

    >>> cap('this is a test.')
    'This Is A Test.'
    """
    return _str.title()


def formal(_str: str) -> str:
    """Change the capitalization to the format used in titles

    >>> formal('this is a test.')
    'This Is A Test.'
    """
    return _str.title()


def lowercase(_str: str) -> str:
    """Turn a string in lowercase

    >>> lowercase('THIS IS A TEST.')
    'this is a test.'
    """
    return _str.lower()


def sentence(_str: str) -> str:
    """Capitalization the beginning of each sentence

    >>> sentence('this IS A TEST.')
    'This is a test.'
    """
    return _str.capitalize()


def togglecase(_str: str) -> str:
    """Convert uppercase to lowercase and vice versa

    >>> togglecase('this IS A TEST.')
    'THIS is a test.'
    """
    return _str.swapcase()


def uppercase(_str: str) -> str:
    """Turn a string in all caps

    >>> uppercase('this is a test.')
    'THIS IS A TEST.'
    """
    return _str.upper()


def explode(_str: str) -> str:
    """Insert a space between each character

    >>> explode('this is a test.')
    ' t h i s   i s   a   t e s t . '
    """
    return re.sub('(.?)', r' \1 ', _str).replace(r'  ', r' ')


def implode(_str: str) -> str:
    """Remove a space from between each character

    >>> implode('this is a test.')
    'thisisatest.'
    >>> implode(' t h i s   i s   a   t e s t . ')
    'this is a test.'
    """
    return re.sub('(.?) (.?)', r'\1\2', _str).replace(r'  ', r' ')


def rmcurlycommas(_str: str) -> str:
    """Remove curly commas (፣ ، 、 ، ◌̦ ︐ ︑ ꛵ ᠂ ‍̓ )

    >>> rmcurlycommas('This is، a test.')
    'This is a test.'
    """
    return _str.replace(r'،', r'').replace(r'、', r'').replace(r'،', r'').replace(r'◌̦', r'').replace(r'︐', r'').replace(r'︑', r'').replace(r'᠂', r'').replace(r'‍̓', r'').replace(r'‍፣', r'').replace(r'‍꛵', r'')


def replacecurlycommas(_str: str) -> str:
    """Replace curly commas with a regular comma (፣ ، 、 ، ◌̦ ︐ ︑ ꛵ ᠂ ‍̓ )

    >>> replacecurlycommas('This is، a test.')
    'This is, a test.'
    """
    return _str.replace(r'،', r',').replace(r'、', r',').replace(r'،', r',').replace(r'◌̦', r',').replace(r'︐', r',').replace(r'︑', r',').replace(r'᠂', r',').replace(r'‍̓', r',').replace(r'‍፣', r',').replace(r'‍꛵', r',')


def rmcurlyquotes(_str: str) -> str:
    """Remove curly quotes (“ ” ‘ ’ ” ′ ″ ‴ ″)

    >>> rmcurlyquotes('This is a “test”.')
    'This is a test.'
    """
    return _str.replace(r'“', r'').replace(r'”', r'').replace(r'‘', r'').replace(r'’', r'').replace(r'′', r'').replace(r'″', r'').replace(r'‴', r'').replace(r'″', r'')


def replacecurlyquotes(_str: str) -> str:
    """Replace curly quotes with straight-quotes (“ ” ‘ ’ ” ′ ″ ‴ ″)

    >>> replacecurlyquotes('This is a “test”.')
    'This is a "test".'
    """
    return _str.replace(r'“', r'"').replace(r'”', r'"').replace(r'‘', r'\'').replace(r'’', r'\'').replace(r'′', r'\'').replace(r'″', r'"').replace(r'‴', r'"').replace(r'″', r'"')


def rmspecialwhitespace(_str: str) -> str:
    r"""Remove special white-space characters

    >>> rmspecialwhitespace('This\u202F is a test.')
    'This is a test.'
    """
    return _str.replace('\u00A0', r'').replace('\u1680', r'').replace('\u16EB', r'').replace('\u16EC', r'').replace('\u180E', r'').replace('\u2000', r'').replace('\u2001', r'').replace('\u2002', r'').replace('\u2003', r'').replace('\u2004', r'').replace('\u2005', r'').replace('\u2006', r'').replace('\u2007', r'').replace('\u2008', r'').replace('\u2009', r'').replace('\u200A', r'').replace('\u200B', r'').replace('\u202F', r'').replace('\u205F', r'').replace('\u3000', r'').replace('\uFEFF', r'')


def replacespecialwhitespace(_str: str) -> str:
    r"""Replace special white-space characters

    >>> replacespecialwhitespace('This\u202Fis a test.')
    'This is a test.'
    """
    return _str.replace('\u00A0', r' ').replace('\u1680', r' ').replace('\u16EB', r' ').replace('\u16EC', r' ').replace('\u180E', r' ').replace('\u2000', r' ').replace('\u2001', r' ').replace('\u2002', r' ').replace('\u2003', r' ').replace('\u2004', r' ').replace('\u2005', r' ').replace('\u2006', r' ').replace('\u2007', r' ').replace('\u2008', r' ').replace('\u2009', r' ').replace('\u200A', r' ').replace('\u200B', r' ').replace('\u202F', r' ').replace('\u205F', r' ').replace('\u3000', r' ').replace('\uFEFF', r' ')


def rmpunct(_str: str) -> str:
    """Remove end-of-sentence punctuation

    >>> rmpunct('this is a test.')
    'this is a test'
    >>> rmpunct('‽word¿ text.')
    'word text'
    """
    return _str.replace(r';', r'').replace(r',', r'').replace(r'.', r'').replace(r'¿', r'').replace(r'¡', r'').replace(r'‽', r'').replace(r'⸮', r'').replace(r'?', r'').replace(r'!', r'').replace(r'…', r'')


def splitsentencesstr(_str_of_sentences: str) -> list:
    """Split a string by sentence"""
    _array = re.split(r'[\.\?﹖？!﹗！;…¿¡‽⸮⁇⁈⁉‼]*', _str_of_sentences)
    inputarray = []
    for i in _array:
        i = i.strip()
        if i:
            inputarray.append(i)
    return inputarray


def sqlstr(_obj, _strength: int = 0) -> str:
    """Convert an object to a string and format the string to protect against SQL-Injection Attacks

    _strength indicates what characters should be removed or escaped
    0 = (Default) Remove curly quotes, commas, and brackets; escape quotes, slashes, and dashes
    1 = Same as 0, but removes characters instead of escaping
    2 = Same as 1, but remove additional characters such as .?!#;&%^:
    3 = Only keep ASCII letters and space
    """
    _obj = str(_obj)
    if _strength >= 3:  # Only keep ASCII letters and space
        _out = r''
        for i in _obj:
            if i.isalpha() or i == r' ':
                _out += i
        return _out
    _obj = _obj.replace(r'{', r'').replace(r'}', r'').replace('\\', r'')
    _obj = _obj.replace(r'“', r'').replace(r'”', r'').replace(r'‘', r'').replace(r'’', r'').replace(r'、', r'').replace(r'،', r'')  # Curly Quotes and Commas
    if not _strength:  # _strength == 0
        return _obj.replace(r'"', r'&quot;').replace('\'', r'&#39;').replace(r'`', r'&#96;').replace(r'--', r'-')
    else:  # _strength >= 1
        _obj = _obj.replace(r'"', r'').replace('\'', r'').replace(r'`', r'').replace(r'-', r'')
    if _strength >= 2:
        return _obj.replace(r'%', r'').replace(r'^', r'').replace(r':', r'').replace(r'#', r'').replace(r';', r'').replace(r'&', r'').replace(r'.', r'').replace(r'?', r'').replace(r'!', r'')
    return _obj


def presentlist(_list: list) -> str:
    """Convert a list to a string without the brackets and quotes"""
    return str(_list).replace('\'', r'').replace(r'[', r'').replace(r']', r'')


# MISCELLANEOUS FUNCTIONS #


def fval(_dict: dict, _search) -> str:
    """Search a dictionary by value and stop on first instance

    This searches key values that are tuples, lists, or strings.
    Returns the key (if found); else returns empty string
    """
    for key, val in _dict.items():
        if isinstance(val, str) and val == _search:
            return key
        elif _search in val:
            return key
    return r''


def noescape(_hex: str) -> str:
    r"""Remove escapes from a single character hex string

    >>> noescape('\\U00000026')
    '&'
    >>> noescape('\\u0026')
    '&'
    >>> noescape('\\x26')
    '&'
    """
    if r'\U' in _hex and len(_hex) == 10:
        _int = int(_hex.replace(r'\U', r''), 16)
        _hex = hex(_int).replace('0x', r'')
        return literal_eval('"\\U{0}"'.format(_hex[:].zfill(8)))
    elif r'\u' in _hex and len(_hex) == 6:
        _int = int(_hex.replace(r'\u', r''), 16)
        _hex = hex(_int).replace('0x', r'')
        return literal_eval('"\\u{0}"'.format(_hex[:].zfill(4)))
    elif r'\x' in _hex and (len(_hex) % 4) == 0:
        _utf8_strict = '.decode(\'utf8\', \'strict\')'
        if _hex.count(r'\x') == 4:
            _hex = _hex.split(r'\x')[1:]
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\\x{0[2]}\\x{0[3]}\'' + _utf8_strict
            return literal_eval(_eval_str.format(_hex))
        elif _hex.count(r'\x') == 3:
            _hex = _hex.split('\\x')[1:]
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\\x{0[2]}\'' + _utf8_strict
            return literal_eval(_eval_str.format(_hex))
        elif _hex.count(r'\x') == 2:
            _hex = _hex.split('\\x')[1:]
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\'' + _utf8_strict
            return literal_eval(_eval_str.format(_hex))
        elif _hex.count(r'\x') == 1:
            _int = int(_hex.replace(r'\x', r''), 16)
            _hex = hex(_int).replace('0x', r'')[:].zfill(2)
            return literal_eval('\'\\x{0}\''.format(_hex))
        raise Exception(r'Invalid input passed to noescape()!')
    elif isinstance(_hex, str) and len(_hex) == 1:
        return _hex
    raise Exception(r'Invalid input passed to noescape()!')


# BOOLEAN TESTS #


def isascii(_str: str) -> bool:
    """Test if a character is within the Ascii limit

    >>> isascii('B')
    True
    >>> isascii('b')
    True
    >>> isascii('1')
    True
    >>> isascii('€')
    False
    >>> isascii('ἀ')
    False
    >>> isascii('€')
    False
    """
    try:
        return 0 <= ord(_str) < UPPER_LIMIT_ASCII_EXT
    except SyntaxError:
        return False


def isstrascii(_str: str) -> bool:
    """Test if a string is within the Ascii limit

    >>> isstrascii('B')
    True
    >>> isstrascii('b')
    True
    >>> isstrascii('123')
    True
    >>> isstrascii('qwerty')
    True
    >>> isstrascii('ἀ')
    False
    >>> isstrascii('€')
    False
    >>> isstrascii('123ἀqwerty')
    False
    """
    return all(False for x in _str if not isascii(x))


def isctrlascii(_str: str) -> bool:
    r"""Test if a character is within the Control Ascii limit

    >>> isctrlascii('\r')
    True
    >>> isctrlascii('\n')
    True
    >>> isctrlascii('\a')
    True
    >>> isctrlascii('\0')
    True
    >>> isctrlascii('ἀ')
    False
    >>> isctrlascii('€')
    False
    """
    try:
        return LOWER_LIMIT_ASCII_CTRL <= ord(_str) <= UPPER_LIMIT_ASCII_CTRL
    except SyntaxError:
        return False


def isstrctrlascii(_str: str) -> bool:
    r"""Test if a string is within the Control Ascii limit

    >>> isstrctrlascii('\r')
    True
    >>> isstrctrlascii('\a')
    True
    >>> isstrctrlascii('\a\0')
    True
    >>> isstrctrlascii('qwerty\n')
    False
    >>> isstrctrlascii('ἀ')
    False
    >>> isstrctrlascii('qwerty')
    False
    >>> isstrctrlascii('€')
    False
    """
    return all(False for x in _str if not isctrlascii(x))


def isprntascii(_str: str) -> bool:
    """Test if a character is within the Printable Ascii limit

    >>> isprntascii('1')
    True
    >>> isprntascii('q')
    True
    >>> isprntascii('€')
    False
    """
    try:
        return LOWER_LIMIT_ASCII_PRNT <= ord(_str) <= UPPER_LIMIT_ASCII_PRNT
    except SyntaxError:
        return False


def isstrprntascii(_str: str) -> bool:
    """Test if a string is within the Printable Ascii limit

    >>> isstrprntascii('1')
    True
    >>> isstrprntascii('123')
    True
    >>> isstrprntascii('qwerty')
    True
    >>> isstrprntascii('€')
    False
    >>> isstrprntascii('€qwerty')
    False
    """
    return all(False for x in _str if not isprntascii(x))


def isextascii(_str: str) -> bool:
    """Test if a character is within the Extended Ascii limit"""
    try:
        return LOWER_LIMIT_ASCII_EXT <= ord(_str) < UPPER_LIMIT_ASCII_EXT
    except SyntaxError:
        return False


def isstrextascii(_str: str) -> bool:
    """Test if a string is within the Extended Ascii limit"""
    return all(False for x in _str if not isextascii(x))


def isgreek(_str: str) -> bool:
    """Test if the character is a Greek letter

    >>> isgreek('Γ')
    True
    >>> isgreek('Α')
    True
    >>> isgreek('ᾁ')
    True
    >>> isgreek('ὴ')
    True
    >>> isgreek('q')
    False
    >>> isgreek('0')
    False
    """
    if _str in GREEK_ALL:
        return True
    return False


def isstrgreek(_str: str) -> bool:
    """Test if the string is a string of Greek letters

    >>> isstrgreek('ΓὟᾬἄαξχΦᾁᾂὴ')
    True
    >>> isstrgreek('Γ')
    True
    >>> isstrgreek('Α')
    True
    >>> isstrgreek('αξχΦᾁᾂὴ')
    True
    >>> isstrgreek('qwerty')
    False
    >>> isstrgreek('0123')
    False
    >>> isstrgreek('qwertyΓὟᾬἄαξχΦᾁᾂὴ')
    False
    >>> isstrgreek('0123ΓὟᾬἄαξχΦᾁᾂὴ')
    False
    """
    return all(False for x in _str if x not in GREEK_ALL)


def hasgreek(_str: str) -> bool:
    """Test if the string contain Greek letters

    >>> hasgreek('ἀἁἂαβγδεζ')
    True
    >>> hasgreek('qwerty')
    False
    >>> hasgreek('0123')
    False
    >>> hasgreek('qwertyἀἁἂαβγδεζ')
    True
    >>> hasgreek('0123ἀἁἂαβγδεζ')
    True
    """
    return any(True for x in _str if x in GREEK_ALL)


def isbraille(_str: str) -> bool:
    """Test if the character is a Braille character

    >>> isbraille('⠀')
    True
    >>> isbraille('⠃')
    True
    >>> isbraille('q')
    False
    >>> isbraille('0')
    False
    """
    if _str in BRAILLE:
        return True
    return False


def isstrbraille(_str: str) -> bool:
    """Test if the string is a string of Braille characters

    >>> isstrbraille('⠀⠁⠂⠃')
    True
    >>> isstrbraille('⠀')
    True
    >>> isstrbraille('qwerty')
    False
    >>> isstrbraille('0123')
    False
    >>> isstrbraille('qwerty⠀⠁⠂⠃ᾂὴ')
    False
    >>> isstrbraille('0123ΓὟᾬ⠀⠁⠂⠃')
    False
    """
    return all(False for x in _str if x not in BRAILLE)


def hasbraille(_str: str) -> bool:
    """Test if the string contain Braille characters

    >>> hasbraille('ἀἁ⠀⠁⠂⠃δεζ')
    True
    >>> hasbraille('qwerty⠀⠁⠂⠃ἀαβγζ')
    True
    >>> hasbraille('0123ἀβ⠀⠁⠂⠃εζ')
    True
    >>> hasbraille('qwerty')
    False
    >>> hasbraille('0123')
    False
    """
    return any(True for x in _str if x in BRAILLE)


def isutf8(_str: str) -> bool:
    """Test if a string is within the UTF8 limit

    >>> isutf8('a')
    True
    >>> isutf8('ἀ')
    True
    """
    try:
        if _str.encode(r'utf-8'):
            return True
    except SyntaxError:
        return False
    return False


def isutf16(_str: str) -> bool:
    """Test if a string is within the UTF16 limit"""
    try:
        if _str.encode(r'utf-16'):
            return True
    except SyntaxError:
        return False
    return False


def isunicode(_str: str) -> bool:  # noqa: C901
    """Test if a string is within the Unicode limit"""
    assert isinstance(_str, (str, bytes)), \
        r'An invalid datatype was passed to isunicode()!'
    _utfstrict = '.decode(\'utf8\', \'strict\')'
    _fmt = 'b\'\\x{0[0]}\\x{0[1]}\\x{0[2]}\'' + _utfstrict
    if len(_str) == 10 and r'\U' in _str:
        _int = int(_str.replace(r'\U', r''), 16)
        return _int <= UPPER_LIMIT_UNICODE
    elif len(_str) == 6 and r'\u' in _str:
        _int = int(_str.replace(r'\u', r''), 16)
        return _int <= UPPER_LIMIT_UNICODE
    elif _str.count(r'\x') == 1 and (len(_str) % 4) == 0:
        _int = int(_str.replace(r'\x', r'0x'), 16)
        return _int <= UPPER_LIMIT_UNICODE
    elif _str.count(r'\x') >= 2 and (len(_str) % 4) == 0:
        try:
            literal_eval(_fmt.format(_str.split(r'\x')[1:]))
        except SyntaxError:
            return False
        return True
    elif isinstance(_str, bytes):
        try:
            _str.decode(r'utf8', r'strict')
        except SyntaxError:
            return False
        return True
    elif len(_str) == 1:
        try:
            if _str.encode(r'utf-16', r'strict'):
                return True
        except SyntaxError:
            return False
    return False


def hashexescape(_str: str) -> bool:  # noqa: C901  # pylint: disable=R0912,R0915
    """Test if the string contains a character hex escape"""
    if r'\U' in _str:
        _ct = _str.count(r'\U')
        _start = 0
        while _ct != 0:
            _start = _str.find(r'\U', _start) + 2
            _end = _start + 8
            _skip = False
            for i in _str[_start:_end]:
                if i in r'0123456789ABCDEFabcdef':
                    continue
                _skip = True
                break
            if not _skip:
                return True
            _ct -= 1
            _start = _end
    if r'\u' in _str:
        _ct = _str.count(r'\u')
        _start = 0
        while _ct != 0:
            _start = _str.find(r'\u', _start) + 2
            _end = _start + 4
            _skip = False
            for i in _str[_start:_end]:
                if i in r'0123456789ABCDEFabcdef':
                    continue
                _skip = True
                break
            if not _skip:
                return True
            _ct -= 1
            _start = _end
    if r'\X' in _str:
        _ct = _str.count(r'\X')
        _start = 0
        while _ct != 0:
            _start = _str.find(r'\X', _start) + 2
            _end = _start + 2
            _skip = False
            for i in _str[_start:_end]:
                if i in r'0123456789ABCDEFabcdef':
                    continue
                _skip = True
                break
            if not _skip:
                return True
            _ct -= 1
            _start = _end
    if r'\x' in _str:
        _ct = _str.count(r'\x')
        _start = 0
        while _ct != 0:
            _start = _str.find(r'\x', _start) + 2
            _end = _start + 2
            _skip = False
            for i in _str[_start:_end]:
                if i in r'0123456789ABCDEFabcdef':
                    continue
                _skip = True
                break
            if not _skip:
                return True
            _ct -= 1
            _start = _end
    return False


def testref(_data: str) -> bool:
    """Test if the string contains a character reference"""
    return CHAR_REF.search(_data) is not None or ENTITY_REF.search(_data) is not None


def is_palindrome(_str: str) -> bool:
    """Test if the given string is a palidrome

    >>> is_palindrome('racecar')
    True
    >>> is_palindrome('some text')
    False
    """
    return _str == _str[::-1]


# LENGTHS #


def utf7len(_str: str) -> int:
    """Get the UTF7 byte-size of a string"""
    return len(_str.encode(r'utf-7'))


def utf8len(_str: str) -> int:
    """Get the UTF8 byte-size of a string

    Each byte in a UTF-8 byte-sequence consists of two parts:
     - Marker Bits (the most significant bits): sequence of zero to four 1 bits followed by a 0
     - Payload Bits: x being payload bits
    Examples:
     - U-00000000 ... U-0000007F	0xxxxxxx
     - U-00000080 ... U-000007FF	110xxxxx 10xxxxxx
     - U-00000800 ... U-0000FFFF	1110xxxx 10xxxxxx 10xxxxxx
     - U-00010000 ... U-0010FFFF	11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    """
    return len(_str.encode(r'utf-8'))


def utf16len(_str: str) -> int:
    """Get the UTF16 byte-size of a string"""
    return len(_str.encode(r'utf-16'))


def utf32len(_str: str) -> int:
    """Get the UTF32 byte-size of a string"""
    return len(_str.encode(r'utf-32'))


# ESCAPE MANIPULATIONS #


def findescapes(_str: str) -> list:
    r"""Find character hex escapes in a string

    Return a list of the escapes
    Return an empty list if none are found

    >>> findescapes('This is a \\u202f test.')
    ['\\u202f', [...]]
    """
    def _search(_char: str, _num: int):
        """Find hexadecimal characters"""
        _ct = _str.count(_char)
        _start = 0
        while _ct != 0:
            _start = _str.find(_char, _start) + 2
            _end = _start + _num
            _skip = False
            for i in _str[_start:_end]:
                if i in r'0123456789ABCDEFabcdef':
                    continue
                _skip = True
                break
            _ct -= 1
            if _skip:
                _start = _end
                continue
            _out.append(_char + _str[_start:_end])
            _start = _end
        return _out

    _out = []
    if r'\U' in _str:
        _out.append(_search(r'\U', 8))
    if r'\u' in _str:
        _out.append(_search(r'\u', 4))
    if r'\x' in _str:
        _out.append(_search(r'\x', 2))
    if r'\X' in _str:
        _out.append(_search(r'\X', 2))
    return _out


def shrink_esc_utf16to8(_hex: str) -> str:
    r"""Shrink a 16-bit hex escape to a 8-bit hex escape (\\uhhhh) => (\\xhh)

    >>> shrink_esc_utf16to8('\\u002f')
    '\\x2f'
    """
    if r'\u00' in _hex and len(_hex) == 6:
        return _hex.replace(r'\u00', r'\x')
    raise Exception(_hex + r' cannot be shrunk to a 8-bit hex escape!')


def shrink_esc_utf32to8(_hex: str) -> str:
    r"""Shrink a 32-bit hex escape to a 8-bit hex escape (\\Uhhhhhhhh) => (\\xhh)

    >>> shrink_esc_utf32to8('\\U0000002f')
    '\\x2f'
    """
    if r'\U000000' in _hex and len(_hex) == 10:
        return _hex.replace(r'\U000000', r'\x')
    raise Exception(_hex + r' cannot be shrunk to a 8-bit hex escape!')


def shrink_esc_utf32to16(_hex: str) -> str:
    r"""Shrink a 32-bit hex escape to a 16-bit hex escape (\\Uhhhhhhhh) => (\\uhhhh)

    >>> shrink_esc_utf32to16('\\U0000002f')
    '\\u002f'
    """
    if r'\U0000' in _hex and len(_hex) == 10:
        return _hex.replace(r'\U0000', r'\u')
    raise Exception(_hex + r' cannot be shrunk to a 16-bit hex escape!')


def rmbyteshexesc(_str: bytes) -> str:
    r"""Remove hex escapes from byte strings and return  as a string

    >>> rmbyteshexesc(b'\x80abc')
    'abc'
    """
    return _str.decode(r'utf-8', r'ignore')


def rplbyteshexesc(_str: bytes) -> str:
    r"""Replace hex escapes in byte strings and return as a string

    >>> rplbyteshexesc(b'\x26abc')
    '&abc'
    """
    return _str.decode(r'utf-8', r'ignore')


def noescutf8hex(_hex: str) -> str:
    r"""Remove escapes from UTF-8 hex strings (\\x26)

    >>> noescutf8hex('\\x26')
    '&'
    """
    if r'\x' in _hex and (len(_hex) % 4) is 0:
        _utf8_strict = '.decode(\'utf8\', \'strict\')'
        if _hex.count('\\') == 3:
            _hex = _hex.split(r'\x')[1:]
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\\x{0[2]}\'' + _utf8_strict
            return literal_eval(_eval_str.format(_hex))
        elif _hex.count('\\') == 2:
            _hex = _hex.split(r'\x')[1:]
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\'' + _utf8_strict
            return literal_eval(_eval_str.format(_hex))
        elif _hex.count('\\') == 4:
            _hex = _hex.split(r'\x')[1:]
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\\x{0[2]}\\x{0[3]}\'' + _utf8_strict
            return literal_eval(_eval_str.format(_hex))
        elif _hex.count('\\') == 1:
            _int = int(_hex.replace(r'\x', r''), 16)
            _hex = hex(_int).replace(r'0x', r'')[:].zfill(2)
            return literal_eval('\'\\x{0}\''.format(_hex))
    if isinstance(_hex, str) and len(_hex) is 1:
        return _hex
    raise ValueError(r'Invalid input passed to noescutf8hex()!')


def expandhexescape(_hex: str) -> str:
    r"""Convert a 16-bit hex escape to a 32-bit hex escape (\\uhhhh) => (\\Uhhhhhhhh)

    >>> expandhexescape('\\u202f')
    '\\U0000202f'
    """
    if r'\u' in _hex and len(_hex) == 6:
        return _hex.replace(r'\u', r'\U0000')
    raise Exception(_hex + r' cannot be converted to a 32-bit hex escape!')


def char2noeschex(_char: str) -> str:
    """Convert a character to a hex string lacking divisions or escapes

    >>> char2noeschex('&')
    '26'
    """
    return r'{:02x}'.format(ord(_char))


def str2noeschex(_char: str) -> str:
    """Convert a string to a hex string lacking divisions or escapes

    >>> str2noeschex('This is a test.')
    '54686973206973206120746573742e'
    """
    return r''.join(r'{:02x}'.format(ord(i)) for i in _char)


def str2hexcolon(_str: str) -> str:
    """Convert a string to a hex string divided into pairs by colons

    >>> str2hexcolon('This is a test.')
    '54:68:69:73:20:69:73:20:61:20:74:65:73:74:2e'
    """
    return r':'.join(r'{:02x}'.format(ord(i)) for i in _str)


# X 2 CHARACTER


def int2char(_int, _numbase: str = r'10', _escape: bool = True) -> str:
    r"""Convert an integer (as a str or int type) to a character

    The integer may be decimal, hex, octal, or binary
    By default, the returned value is escaped unicode (\U0000000)
    int2char(_int, _numbase, _escape) => str
    _int - number to convert to a character
    _numbase - Specify the int's base (2, 8, 10, 16)
    _escape - False = No escapes; True = Escapes

    >>> int2char(38)
    '\\U00000026'
    >>> int2char('38')
    '\\U00000026'
    >>> int2char('0x26')
    '\\U00000026'
    >>> int2char(0x26)
    '\\U00000026'
    >>> int2char('26', '16')
    '\\U00000026'
    >>> int2char('26', '16', False)
    '&'
    """
    if isinstance(_int, str):
        if r'0x' in _int or _numbase == r'16' or _numbase == r'hex':
            _int = int(_int, 16)
        elif r'0b' in _int or _numbase == r'2' or _numbase == r'bin':
            _int = int(_int, 2)
        elif r'0o' in _int or _numbase == r'8' or _numbase == r'oct':
            _int = int(_int, 8)
        else:
            _int = int(_int, 10)
    if isinstance(_int, int):
        if _escape:
            _int = hex(_int).replace(r'0x', r'')[:].zfill(8)
            return r'\U{0}'.format(_int)
        else:
            if LOWER_LIMIT_ASCII_CTRL <= _int <= UPPER_LIMIT_UTF8:
                return chr(_int)
            elif UPPER_LIMIT_UTF8 < _int <= UPPER_LIMIT_UNICODE:
                _int = hex(_int).replace(r'0x', r'')
                return literal_eval('"\\U{0}"'.format(_int[:].zfill(8)))
            raise ValueError(r'An out-of-range integer passed to int2char()!')
    raise TypeError(r'Invalid datatype passed to int2char()!')


def hexstr2char(_hex: str, _escape: bool = True) -> str:
    r"""Convert a hex number (as a string) to a character

    >>> hexstr2char('0x26')
    '\\U00000026'
    >>> hexstr2char(0x26)
    '\\U00000026'
    >>> hexstr2char('26', False)
    '&'
    """
    return int2char(_hex, r'16', _escape)


def hexint2char(_hex: int, _escape: bool = True) -> str:
    r"""Convert a hex integer to a character

    >>> hexint2char(0x26)
    '\\U00000026'
    >>> hexint2char(0x26, False)
    '&'
    """
    return int2char(_hex, r'16', _escape)


def octstr2char(_oct: str, _escape: bool = True) -> str:
    r"""Convert an octal number (as a string) to a character

    >>> octstr2char('0o46')
    '\\U00000026'
    >>> octstr2char(0o46)
    '\\U00000026'
    >>> octstr2char('46', False)
    '&'
    """
    return int2char(_oct, r'8', _escape)


def octint2char(_oct: int, _escape: bool = True) -> str:
    r"""Convert an octal integer to a character

    >>> octint2char(0o46)
    '\\U00000026'
    >>> octint2char(0o46, False)
    '&'
    """
    return int2char(_oct, r'8', _escape)


def binstr2char(_bin: str, _escape: bool = True) -> str:
    r"""Convert a binary number (as a string) to a character

    >>> binstr2char('0b100110')
    '\\U00000026'
    >>> binstr2char(0b100110)
    '\\U00000026'
    >>> binstr2char('100110', False)
    '&'
    """
    return int2char(_bin, r'2', _escape)


def binint2char(_bin: int, _escape: bool = True) -> str:
    r"""Convert an binary integer to a character

    >>> binint2char(0b100110)
    '\\U00000026'
    >>> binint2char(0b100110, False)
    '&'
    """
    return int2char(_bin, r'2', _escape)


def name2char(_name: str) -> str:
    """Convert a Unicode name to a character

    If the name is invalid, an empty string is returned
    """
    try:
        return literal_eval('"\\N{1}{0}{2}"'.format(_name.upper(), r'{', r'}'))
    except SyntaxError:
        return r''


# X 2 INTEGER #


def char2int(_char: str) -> int:
    """Convert a character to an integer"""
    return ord(_char)


def refnum2int(_refnum: str) -> int:
    """Convert Decimal-NCR/HTML-Entity (&#38;) to an integer"""
    assert r'&#' in _refnum and r';' in _refnum, \
        r'The entered value is not a HTML entity number (&#38;)!'
    _refnum = _refnum.replace(r'&#', r'').replace(r';', r'')
    return int(_refnum, 10)


def ncr2int(_refnum: str) -> int:
    """Provide a decorator for refnum2int()"""
    return refnum2int(_refnum)


# X 2 UTF* #


def utf8convchar2hexescape(_char: str) -> str:
    r"""Convert a character to a UTF-8 hex string (\xc3\x9e)"""
    _char = str(_char.encode(r'utf_8', r'strict'))
    _char = _char.replace(r'b', r'').replace('\'', r'')
    return r'{0}'.format(_char)


def utf8convchar2hexstr(_char: str) -> str:
    """Convert a character to a hex string (0xc30x9e)"""
    _char = str(_char.encode(r'utf_8', r'strict')).replace(r'b', r'')
    _char = _char.replace('\'', r'').replace(r'\x', r'0x')
    return r'{0}'.format(_char)


def utf8convchar2uri(_char: str) -> str:
    """Convert a character to an URI escaped hex sequence (%c3%9e)"""
    _char = str(_char.encode(r'utf_8', r'strict')).replace(r'b', r'')
    _char = _char.replace('\'', r'').replace(r'\x', r'%')
    return r'{0}'.format(_char)


def utf8convchar2intstr(_char: str) -> int:
    """Convert a character to an integer string (& => 38)"""
    _char = str(_char.encode(r'utf_8', r'strict')).replace(r'b', r'')
    _char = _char.replace('\'', r'').replace(r'\x', r'0x')
    _char = r'{0}'.format(_char.split(r'0x'))
    return r''.join(r'{0}'.format(str(int(i, 16)) for i in _char))


def int2utf16(_int: int, _endian: str = byteorder) -> str:
    """Convert an integer to a character"""
    if 0 <= _int <= UPPER_LIMIT_UNICODE:
        if _endian == r'little':
            return (_int).to_bytes(4, _endian).decode(r'utf-16-le', r'strict')
        elif _endian == r'big':
            return (_int).to_bytes(4, _endian).decode(r'utf-16-be', r'strict')
        return (_int).to_bytes(4, r'little').decode(r'utf-16', r'strict')
    raise ValueError(r'Integer value out of valid Unicode range (0 - {0})!'.format(UPPER_LIMIT_UNICODE))


def int2utf32(_int: int, _endian: str = byteorder) -> str:
    """Convert an integer to a character"""
    if 0 <= _int <= UPPER_LIMIT_UNICODE:
        return (_int).to_bytes(4, _endian).decode(r'utf-32', r'strict')
    raise ValueError(r'Integer value out of valid Unicode range (0 - {0})!'.format(UPPER_LIMIT_UNICODE))


# X 2 HEX #


def char2hexstr(_char: str) -> str:
    """Convert a character(s) to hex-numbers as a str"""
    if len(_char) is 1:
        return hex(ord(_char))
    elif len(_char) > 1:
        _out = r''
        for i in _char:
            _out = _out + hex(ord(i))
        return _out
    raise ValueError(r'Invalid data passed to char2hexstr()!')


def hex2unicodehex(_hex: str or int) -> str:
    """Convert hexadecimal to Unicode+Hex Notation"""
    if isinstance(_hex, str):
        if r'0x' in _hex:
            _hex = _hex.replace(r'0x', r'')
        if r'\x' in _hex:
            _hex = _hex.replace(r'\x', r'')
        if r'\U' in _hex:
            _hex = _hex.replace(r'\U000', r'').replace(r'\U00', r'')
            _hex = _hex.replace(r'\U0', r'').replace(r'\U', r'')
        if r'\u' in _hex:
            _hex = _hex.replace(r'\u00', r'').replace(r'\u0', r'')
            _hex = _hex.replace(r'\u', r'')
        if r'\0' in _hex:
            _hex = _hex.replace(r'\0', r'')
        if r'&#x' in _hex:
            _hex = _hex.replace(r'&#x', r'').replace(r';', r'')
        return r'U+{0}'.format(_hex)
    elif isinstance(_hex, int):
        _hex = hex(_hex).replace(r'0x', r'')
        return r'U+{0}'.format(_hex)
    raise TypeError(r'Invalid datatype passed to hex2unicodehex()!')


def hex2cssnot(_hex: str or int) -> str:
    r"""Convert hexadecimal to CSS Notation (\01D4C3)"""
    if isinstance(_hex, str):
        if r'0x' in _hex:
            _hex = _hex.replace(r'0x', r'')
        if r'\x' in _hex:
            _hex = _hex.replace(r'\x', r'')
        if r'\U' in _hex:
            _hex = _hex.replace(r'\U000', r'').replace(r'\U00', r'')
            _hex = _hex.replace(r'\U0', r'').replace(r'\U', r'')
        if r'\u' in _hex:
            _hex = _hex.replace(r'\u00', r'').replace(r'\u0', r'')
            _hex = _hex.replace(r'\u', r'')
        if r'U+' in _hex:
            _hex = _hex.replace(r'U+', r'')
        if r'&#x' in _hex:
            _hex = _hex.replace(r'&#x', r'').replace(r';', r'')
        return r'\0{0}'.format(_hex)
    elif isinstance(_hex, int):
        _hex = hex(_hex).replace(r'0x', r'')
        return r'\0{0}'.format(_hex)
    raise TypeError(r'Invalid datatype passed to hex2cssnot()!')


# X 2 MISC #


def char2intstr(_char: str) -> int:
    """Convert a character(s) to decimal integers as a str"""
    if len(_char) is 1:
        return str(ord(_char))
    elif len(_char) > 1:
        _out = ''
        for i in _char:
            _out += str(ord(i))
        return _out
    raise ValueError(r'Invalid data input in char2intstr()!')


def str2bytes(_str: str, _encoding: str = r'utf8') -> bytes:
    """Convert strings to bytes"""
    return _str.encode(_encoding, r'strict')


def bytes2str(_bytes: bytes, _encoding: str = r'utf8') -> str:
    """Convert bytes to strings"""
    return _bytes.decode(_encoding, r'strict')


def int2hexbytes(_int: int, _length: int = 2, _endian: str = r'little', _signed: bool = False) -> str:
    """Convert int to bytes represented as an escaped hex string

    If byteorder is "big", the most significant byte is at the beginning of the byte array.
    If byteorder is "little", the most significant byte is at the end of the byte array.
    """
    return _int.to_bytes(_length, _endian, signed=_signed)


def hexstr2bytearray(_hex: str) -> bytearray:
    """Convert a hex string to a bytearray"""
    return bytearray.fromhex(_hex)


# BUBBLE TEXT #


def text2bubble(_str: str) -> str:
    """Convert a plain-text string to bubble text

    >>> text2bubble('This (str) is a sample test.')
    'Ⓣⓗⓘⓢ (⃝ ⓢⓣⓡ)⃝  ⓘⓢ ⓐ ⓢⓐⓜⓟⓛⓔ ⓣⓔⓢⓣ.⃝ '
    >>> text2bubble('Testing various characters: €, *, Ω, ᾲ, and ⛽.')
    'Ⓣⓔⓢⓣⓘⓝⓖ ⓥⓐⓡⓘⓞⓤⓢ ⓒⓗⓐⓡⓐⓒⓣⓔⓡⓢ:⃝  €⃝ ,⃝  *⃝ ,⃝  Ω⃝ ,⃝  ᾲ⃝ ,⃝  ⓐⓝⓓ ⛽⃝ .⃝ '
    """
    _out = ''
    for i in _str:
        if i not in PLAIN_TEXT:
            i = i + '\u20dd '
        _out = _out + i
    return _out.translate(TRANS_TEXT2BUBBLE)


def bubble2text(_str: str) -> str:
    """Convert bubble text to a plain-text string

    >>> bubble2text('Ⓣⓗⓘⓢ ⓘⓢ ⓐ ⓣⓔⓢⓣ.⃝')
    'This is a test.'
    >>> bubble2text('Ⓣⓗⓘⓢ ⓘⓢ ⓐ ⓢⓔⓒⓞⓝⓓ (⃝ ②ⓝⓓ)⃝  ⓣⓔⓢⓣ.⃝ ')
    'This is a second (2nd) test.'
    >>> bubble2text('Ⓣⓔⓢⓣⓘⓝⓖ ⓥⓐⓡⓘⓞⓤⓢ ⓒⓗⓐⓡⓐⓒⓣⓔⓡⓢ:⃝  €⃝ ,⃝  *⃝ ,⃝  Ω⃝ ,⃝  ᾲ⃝ ,⃝  ⓐⓝⓓ ⛽⃝ .⃝ ')
    'Testing various characters: €, *, Ω, ᾲ, and ⛽.'
    """
    _str = _str.replace('\u202f', r'').replace(r'\u202f', r'').replace(r'.⃝', r'.').replace(r'?⃝', r'?').replace(r'!⃝', r'!').replace(r'¿⃝', r'¿')
    return _str.translate(TRANS_BUBBLE2TEST).replace('\u20dd ', r'').replace(r'\u20dd', r'').strip()


# SQUARE TEXT #


def text2square(_str: str, square_spaces: bool = False) -> str:
    """Convert a plain-text string to square text

    >>> text2square('This (str) is a sample test.', True)
    'T⃞ h⃞ i⃞ s⃞  ⃞ (⃞ s⃞ t⃞ r⃞ )⃞  ⃞ i⃞ s⃞  ⃞ a⃞  ⃞ s⃞ a⃞ m⃞ p⃞ l⃞ e⃞  ⃞ t⃞ e⃞ s⃞ t⃞ .⃞ '
    >>> text2square('This (str) is a sample test.')
    'T⃞ h⃞ i⃞ s⃞   (⃞ s⃞ t⃞ r⃞ )⃞   i⃞ s⃞   a⃞   s⃞ a⃞ m⃞ p⃞ l⃞ e⃞   t⃞ e⃞ s⃞ t⃞ .⃞ '
    >>> text2square('Testing various characters: €, *, Ω, ᾲ, and ⛽.')
    'T⃞ e⃞ s⃞ t⃞ i⃞ n⃞ g⃞   v⃞ a⃞ r⃞ i⃞ o⃞ u⃞ s⃞   c⃞ h⃞ a⃞ r⃞ a⃞ c⃞ t⃞ e⃞ r⃞ s⃞ :⃞   €⃞ ,⃞   *⃞ ,⃞   Ω⃞ ,⃞   ᾲ⃞ ,⃞   a⃞ n⃞ d⃞   ⛽⃞ .⃞ '
    """
    _out = r''
    for i in _str:
        _out = _out + i + '\u20de '
    if not square_spaces:
        return _out.replace(' \u20de', r' ')
    return _out


def square2text(_str: str) -> str:
    """Convert square text to a plain-text string

    >>> square2text('T⃞ h⃞ i⃞ s⃞  ⃞ (⃞ s⃞ t⃞ r⃞ )⃞  ⃞ i⃞ s⃞  ⃞ a⃞  ⃞ s⃞ a⃞ m⃞ p⃞ l⃞ e⃞  ⃞ t⃞ e⃞ s⃞ t⃞ .⃞ ')
    'This (str) is a sample test.'
    >>> square2text('T⃞ h⃞ i⃞ s⃞   (⃞ s⃞ t⃞ r⃞ )⃞   i⃞ s⃞   a⃞   s⃞ a⃞ m⃞ p⃞ l⃞ e⃞   t⃞ e⃞ s⃞ t⃞ .⃞ ')
    'This (str) is a sample test.'
    >>> square2text('T⃞ e⃞ s⃞ t⃞ i⃞ n⃞ g⃞   v⃞ a⃞ r⃞ i⃞ o⃞ u⃞ s⃞   c⃞ h⃞ a⃞ r⃞ a⃞ c⃞ t⃞ e⃞ r⃞ s⃞ :⃞   €⃞ ,⃞   *⃞ ,⃞   Ω⃞ ,⃞   ᾲ⃞ ,⃞   a⃞ n⃞ d⃞   ⛽⃞ .⃞ ')
    'Testing various characters: €, *, Ω, ᾲ, and ⛽.'
    """
    return _str.replace('\u202f', r'').replace(r'\u202f', r'').replace('\u20de ', r'').replace(r'\u20de', r'').replace(r'  ', r' ')

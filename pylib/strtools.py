#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Functions for various character and string manipulations

@file strtools.py
@package pybooster.strtools
@version 2018.11.11
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
from typing import List, Union

from pybooster.boolean import ishex
from pybooster.libchar import (
    BRAILLE,
    GREEK_ALL,
    LOWER_LIMIT_ASCII_CTRL,
    LOWER_LIMIT_ASCII_EXT,
    LOWER_LIMIT_ASCII_PRNT,
    NUMBER_LIST,
    ORDINAL_LIST,
    PLAIN_TEXT,
    TRANS_BUBBLE2TEST,
    TRANS_TEXT2BUBBLE,
    FULLWIDTH2REGULAR,
    UPPER_LIMIT_ASCII_CTRL,
    UPPER_LIMIT_ASCII_EXT,
    UPPER_LIMIT_ASCII_PRNT,
    UPPER_LIMIT_UNICODE,
    UPPER_LIMIT_UTF8
)
from pybooster.libregex import CHAR_REF, ENTITY_REF, HEXESCTAG, HEXESCURI

try:  # Regular Expression module
    from regex import compile as rgxcompile, split as rgxsplit, sub as resub
except ImportError:
    from re import compile as rgxcompile, split as rgxsplit, sub as resub


__all__: list = [
    # CASE STRING MANIPULATIONS #
    r'cap',
    r'formal',
    r'lowercase',
    r'sentence',
    r'togglecase',
    r'uppercase',
    r'camelcase2pascalcase',
    r'camelcase2snakecase',
    r'pascalcase2camelcase',
    r'pascalcase2snakecase',
    r'snakecase2camelcase',
    r'snakecase2pascalcase',
    # OTHER STRING MANIPULATIONS #
    r'endletters',
    r'firstletters',
    r'lastletters',
    r'middleletters',
    r'insstr',
    r'num2ordinal',
    r'ordinal2num',
    r'explode',
    r'implode',
    r'replace_odd_chars',
    r'stripunicode',
    r'rmcurlycommas',
    r'replacecurlycommas',
    r'rmcurlyquotes',
    r'replacecurlyquotes',
    r'rmspecialwhitespace',
    r'replacespecialwhitespace',
    r'rmpunct',
    r'splitsentences',
    r'sqlstr',
    r'presentlist',
    # BOOLEAN TESTS #
    r'isascii',
    r'isctrlascii',
    r'isprntascii',
    r'isextascii',
    r'isgreek',
    r'hasgreek',
    r'isbraille',
    r'hasbraille',
    r'isunicode',
    r'hashexescape',
    r'testref',
    r'is_palindrome',
    # ESCAPE MANIPULATIONS #
    r'findescapes',
    r'shrink_esc_utf16to8',
    r'shrink_esc_utf32to8',
    r'shrink_esc_utf32to16',
    r'noescutf8hex',
    r'noescape',
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
    # X 2 STRING #
    r'str2hexesc',
    r'str2uri',
    r'str2intstr',
    r'int2utf16',
    r'int2utf32',
    r'char2num',
    r'str2hexstr',
    r'hex2unicodehex',
    r'hex2cssnot',
    # X 2 BYTES #
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


# CASE STRING MANIPULATIONS #


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


def camelcase2pascalcase(string: str) -> str:
    """Convert string from camelCase to PascalCase

    >>> camelcase2pascalcase('testString')
    'TestString'
    >>> camelcase2pascalcase('testString anotherString')
    'TestString AnotherString'
    >>> camelcase2pascalcase('testString anotherString thirdSymbol')
    'TestString AnotherString ThirdSymbol'
    """
    return r' '.join([_word[0].upper() + _word[1:] for _word in string.split(r' ')])


def camelcase2snakecase(string: str) -> str:
    """Convert string from camelCase to snake_case

    >>> camelcase2snakecase('testString')
    'test_string'
    >>> camelcase2snakecase('testString anotherString')
    'test_string another_string'
    """
    words: List[str] = []
    from_char_position: int = 0
    for current_char_position, char in enumerate(string):
        if char.isupper() and from_char_position < current_char_position:
            words.append(string[from_char_position:current_char_position].lower())
            from_char_position = current_char_position
    words.append(string[from_char_position:].lower())
    return r'_'.join(words)


def pascalcase2camelcase(string: str) -> str:
    """Convert string from PascalCase to camelCase

    >>> pascalcase2camelcase('TestString')
    'testString'
    >>> pascalcase2camelcase('TestString AnotherString')
    'testString anotherString'
    >>> pascalcase2camelcase('TestString AnotherString ThirdSymbol')
    'testString anotherString thirdSymbol'
    """
    return r' '.join([_word[0].lower() + _word[1:] for _word in string.split(r' ')])


def pascalcase2snakecase(string: str) -> str:
    """Convert string from PascalCase to snake_case

    >>> pascalcase2snakecase('TestString')
    'test_string'
    >>> pascalcase2snakecase('TestString AnotherString')
    'test_string another_string'
    >>> pascalcase2snakecase('TestString AnotherString ThirdSymbol')
    'test_string another_string third_symbol'
    """
    words: List[str] = []
    from_char_position: int = 0
    for current_char_position, char in enumerate(string):
        if char.isupper() and from_char_position < current_char_position:
            words.append(string[from_char_position:current_char_position].lower())
            from_char_position = current_char_position
    words.append(string[from_char_position:].lower())
    return r'_'.join(words).replace(r' _', r' ')


def snakecase2camelcase(string: str) -> str:
    """Convert string from snake_case to camelCase

    >>> snakecase2camelcase('test_string')
    'testString'
    >>> snakecase2camelcase('test_string another_string')
    'testString anotherString'
    >>> snakecase2camelcase('test_string another_string thirD_Symbol')
    'testString anotherString thirdSymbol'
    """
    split_string: List[str] = string.split(r'_')
    return split_string[0].lower() + r''.join([_str.capitalize() for _str in split_string[1:]])


def snakecase2pascalcase(string: str) -> str:
    """Convert string from snake_case to PascalCase

    >>> snakecase2pascalcase('test_string')
    'TestString'
    >>> snakecase2pascalcase('test_string another_string')
    'TestString AnotherString'
    >>> snakecase2pascalcase('test_string another_string third_Symbol')
    'TestString AnotherString ThirdSymbol'
    """
    split_string: List[str] = string.split(r'_')
    _string: str = split_string[0].capitalize() + r''.join([_str.capitalize() for _str in split_string[1:]])
    if r' ' in _string:
        split_string = _string.split(r' ')
        return split_string[0] + r' ' + r' '.join([_str[0].upper() + _str[1:] for _str in split_string[1:]])
    return split_string[0].capitalize() + r''.join([_str.capitalize() for _str in split_string[1:]])


# OTHER STRING MANIPULATIONS #


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


def insstr(_str: str, _char: str, index: int) -> str:
    """Insert a string at the specified point of another string

    >>> insstr('This is a test.', 'random ', 10)
    'This is a random test.'
    """
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


def explode(_str: str) -> str:
    """Insert a space between each character

    >>> explode('this is a test.')
    't h i s   i s   a   t e s t .'
    """
    return resub('(.?)', r' \1 ', _str).replace(r'  ', r' ').strip()


def implode(_str: str) -> str:
    """Remove a space from between each character

    >>> implode('this is a test.')
    'thisisatest.'
    >>> implode(' t h i s   i s   a   t e s t . ')
    'this is a test.'
    >>> implode('t h i s   i s   a   t e s t .')
    'this is a test.'
    """
    return resub('(.?) (.?)', r'\1\2', _str).replace(r'  ', r' ').strip()


def replace_odd_chars(_data: str) -> str:
    r"""Replace odd characters with plain characters (i.e. replace non-breaking space with ASCII space)

    >>> replace_odd_chars('This\u200Cis a\u180Etest\u16EB')
    'This is a test.'
    """
    # Commas
    _data = _data.replace('\u060C', r',').replace('\u1802', r',').replace('\u3001', r',').replace('\uFE10', r',').replace('\uFE11', r',').replace('\u200D\u0313', r',').replace('\u200D\u1363', r',').replace('\u200D\uA6f5', r',')
    # Single-Quotes
    _data = _data.replace('\u2018', '\u0027').replace('\u2019', '\u0027').replace('\u2032', '\u0027')
    # Double-Quotes
    _data = _data.replace('\u201C', r'"').replace('\u201D', r'"').replace('\u2033', r'"').replace('\u2034', r'"')
    # Newlines
    _data = _data.replace('\u0085', '\n')
    # Spaces
    _data = _data.replace('\u0082', r' ').replace('\u0083', r' ').replace('\u00A0', r' ').replace('\u180E', r' ').replace('\u2000', r' ').replace('\u2001', r' ').replace('\u2002', r' ').replace('\u2003', r' ').replace('\u2004', r' ').replace('\u2005', r' ').replace('\u2006', r' ').replace('\u2007', r' ').replace('\u2008', r' ').replace('\u2009', r' ').replace('\u200A', r' ').replace('\u200B', r' ').replace('\u200C', r' ').replace('\u202F', r' ').replace('\u205F', r' ').replace('\u3000', r' ').replace('\uFEFF', r' ')
    # Dashes, Hyphens, & Tildes
    _data = _data.replace('\u00AD', r'-').replace('\u1680', r'-').replace('\u2010', r'-').replace('\u2011', r'-').replace('\u2012', r'-').replace('\u2013', r'-').replace('\u2014', r'-').replace('\u2015', r'-').replace('\u203E', r'-').replace('\u2053', r'~')
    # Slashes
    _data = _data.replace('\u2044', r'/').replace('\u20E5', '\u005C').replace('\u2215', r'/').replace('\u2216', '\u005C').replace('\u244A', '\u005C\u005C').replace('\u29F5', '\u005C').replace('\u29F6', r'/').replace('\u29F7', '\u005C').replace('\u29F8', r'/').replace('\u29F9', '\u005C')
    # Colons & Semicolons
    _data = _data.replace('\u16EC', r':').replace('\uFE13', r':').replace('\uFE14', r';')
    # Parenthesis & Brackets
    _data = _data.replace('\u2045', '\u005B').replace('\u2046', '\u005D')
    # Periods, Exclamation-Points, & Question-Marks
    _data = _data.replace('\u16EB', r'.').replace('\uFE15', r'!').replace('\uFE16', r'?').replace('\u203C', r'!!').replace('\u203D', r'!?').replace('\u2047', r'??').replace('\u2048', r'?!').replace('\u2049', r'!?')
    # Full-Width Characters
    _data = _data.translate(FULLWIDTH2REGULAR)
    # Other Characters
    return _data.replace('\u204E', r'*').replace('\u2042', r'***').replace('\u204E', r'*').replace('\u2051', r'**')


def stripunicode(_str: str) -> str:
    """Replace unicode characters with a question-mark (?)

    >>> stripunicode('Testing (¶ö⁉) for success.')
    'Testing (???) for success.'
    """
    chars: list = []
    for i in _str:
        if ord(i) > 0x7F:
            chars.append(r'?')
        else:
            chars.append(i)
    return r''.join(chars)


def rmcurlycommas(_str: str) -> str:
    """Remove curly commas

    >>> rmcurlycommas('This is، a test.')
    'This is a test.'
    """
    return _str.replace('\u060C', r'').replace('\u0326', r'').replace('\u1802', r'').replace('\u3001', r'').replace('\uFE10', r'').replace('\uFE11', r'').replace('\u200D\u0313', r'').replace('\u200D\u1363', r'').replace('\u200D\uA6F5', r'')


def replacecurlycommas(_str: str) -> str:
    """Replace curly commas with a regular comma

    >>> replacecurlycommas('This is، a test.')
    'This is, a test.'
    """
    return _str.replace('\u060C', r',').replace('\u0326', r',').replace('\u1802', r',').replace('\u3001', r',').replace('\uFE10', r',').replace('\uFE11', r',').replace('\u200D\u0313', r',').replace('\u200D\u1363', r',').replace('\u200D\uA6F5', r',')


def rmcurlyquotes(_str: str) -> str:
    """Remove curly quotes

    >>> rmcurlyquotes('This is a “test”.')
    'This is a test.'
    """
    return _str.replace('\u201C', r'').replace('\u201D', r'').replace('\u2033', r'').replace('\u2034', r'').replace('\u2018', r'').replace('\u2019', r'').replace('\u2032', r'')


def replacecurlyquotes(_str: str) -> str:
    """Replace curly quotes with straight-quotes

    >>> replacecurlyquotes('This is a “test”.')
    'This is a "test".'
    """
    return _str.replace('\u201C', r'"').replace('\u201D', r'"').replace('\u2033', r'"').replace('\u2034', r'"').replace('\u2018', '\u0027').replace('\u2019', '\u0027').replace('\u2032', '\u0027')


def rmspecialwhitespace(_str: str) -> str:
    r"""Remove special white-space characters

    >>> rmspecialwhitespace('This\u202F is a test.')
    'This is a test.'
    """
    return _str.replace('\u0082', r'').replace('\u0083', r'').replace('\u00A0', r'').replace('\u180E', r'').replace('\u2000', r'').replace('\u2001', r'').replace('\u2002', r'').replace('\u2003', r'').replace('\u2004', r'').replace('\u2005', r'').replace('\u2006', r'').replace('\u2007', r'').replace('\u2008', r'').replace('\u2009', r'').replace('\u200A', r'').replace('\u200B', r'').replace('\u200C', r'').replace('\u202F', r'').replace('\u205F', r'').replace('\u3000', r'').replace('\uFEFF', r'')


def replacespecialwhitespace(_str: str) -> str:
    r"""Replace special white-space characters

    >>> replacespecialwhitespace('This\u202Fis a test.')
    'This is a test.'
    """
    return _str.replace('\u0082', r' ').replace('\u0083', r' ').replace('\u00A0', r' ').replace('\u180E', r' ').replace('\u2000', r' ').replace('\u2001', r' ').replace('\u2002', r' ').replace('\u2003', r' ').replace('\u2004', r' ').replace('\u2005', r' ').replace('\u2006', r' ').replace('\u2007', r' ').replace('\u2008', r' ').replace('\u2009', r' ').replace('\u200A', r' ').replace('\u200B', r' ').replace('\u200C', r' ').replace('\u202F', r' ').replace('\u205F', r' ').replace('\u3000', r' ').replace('\uFEFF', r' ')


def rmpunct(_str: str) -> str:
    """Remove end-of-sentence punctuation

    >>> rmpunct('this is a test.')
    'this is a test'
    >>> rmpunct('‽word¿ text.')
    'word text'
    """
    return _str.replace(r';', r'').replace(r',', r'').replace(r'.', r'').replace(r'¿', r'').replace(r'¡', r'').replace(r'‽', r'').replace(r'⸮', r'').replace(r'?', r'').replace(r'!', r'').replace(r'…', r'')


def splitsentences(_str_of_sentences: str) -> list:
    """Split a string by sentence

    >>> splitsentences('This is a test. This should be a separate item in the list. Did it work?')
    ['This is a test', 'This should be a separate item in the list', 'Did it work']
    """
    _array = rgxsplit(r'[\.\?﹖？!﹗！;…¿¡‽⸮⁇⁈⁉‼]*', _str_of_sentences)
    inputarray: list = []
    for i in _array:
        i = i.strip()
        if i:
            inputarray.append(i)
    return inputarray


def sqlstr(_obj: str, _strength: int = 0) -> str:
    """Format a string to protect against SQL-Injection Attacks

    _strength indicates what characters should be removed or escaped
    0 = (Default) Remove curly quotes, commas, and brackets; escape quotes, slashes, and dashes
    1 = Same as 0, but removes characters instead of escaping
    2 = Same as 1, but remove additional characters such as .?!#;&%^:
    3 = Only keep ASCII letters and space

    >>> sqlstr('This is a lengthy & thorough test: ¶ 2 + 2 = 4 ¶ {r"key": "value", r"test": "^ -- (`)"} ¶ ')
    'This is a lengthy & thorough test: ¶ 2 + 2 = 4 ¶ r&quot;key&quot;: &quot;value&quot;, r&quot;test&quot;: &quot;^ - (&#96;)&quot; ¶ '
    >>> sqlstr('This is a lengthy & thorough test: ¶ 2 + 2 = 4 ¶ {r"key": "value", r"test": "^ -- (`)"} ¶ ', 1)
    'This is a lengthy & thorough test: ¶ 2 + 2 = 4 ¶ rkey: value, rtest: ^  () ¶ '
    >>> sqlstr('This is a lengthy & thorough test: ¶ 2 + 2 = 4 ¶ {r"key": "value", r"test": "^ -- (`)"} ¶ ', _strength=2)
    'This is a lengthy  thorough test ¶ 2 + 2 = 4 ¶ rkey value, rtest   () ¶ '
    >>> sqlstr('This is a lengthy & thorough test: ¶ 2 + 2 = 4 ¶ {r"key": "value", r"test": "^ -- (`)"} ¶ ', 3)
    'This is a lengthy  thorough test        rkey value rtest     '
    """
    if not isinstance(_obj, str):
        return r''
    if _strength >= 3:  # Only keep ASCII letters and space
        return r''.join([i for i in _obj if i.isalpha() or i == r' '])
    _obj = _obj.replace(r'{', r'').replace(r'}', r'').replace('\\', r'')
    _obj = rmcurlyquotes(rmcurlycommas(_obj))  # Curly Quotes and Commas
    if not _strength:  # _strength == 0
        return _obj.replace(r'"', r'&quot;').replace('\'', r'&#39;').replace(r'`', r'&#96;').replace(r'--', r'-')
    _obj = _obj.replace(r'"', r'').replace('\'', r'').replace(r'`', r'').replace(r'-', r'')  # _strength >= 1
    if _strength >= 2:
        return _obj.replace(r'%', r'').replace(r'^', r'').replace(r':', r'').replace(r'#', r'').replace(r';', r'').replace(r'&', r'').replace(r'.', r'').replace(r'?', r'').replace(r'!', r'')
    return _obj


def presentlist(_list: list) -> str:
    """Convert a list to a string without the brackets and quotes

    >>> presentlist([1, 2, 3])
    '1, 2, 3'
    >>> presentlist(['1', '2', '3'])
    '1, 2, 3'
    """
    return str(_list).replace('\'', r'').replace(r'[', r'').replace(r']', r'')


# BOOLEAN TESTS #


def isascii(_str: str) -> bool:
    """Test if a string is within the Ascii limit

    >>> isascii('B')
    True
    >>> isascii('b')
    True
    >>> isascii('123')
    True
    >>> isascii('qwerty')
    True
    >>> isascii('ἀ')
    False
    >>> isascii('€')
    False
    >>> isascii('123ἀqwerty')
    False
    """
    return all(False for x in _str if not 0 <= ord(x) < UPPER_LIMIT_ASCII_EXT)


def isctrlascii(_str: str) -> bool:
    r"""Test if a string is within the Control Ascii limit

    >>> isctrlascii('\r')
    True
    >>> isctrlascii('\a')
    True
    >>> isctrlascii('\n')
    True
    >>> isctrlascii('\0')
    True
    >>> isctrlascii('\a\0')
    True
    >>> isctrlascii('qwerty\n')
    False
    >>> isctrlascii('ἀ')
    False
    >>> isctrlascii('qwerty')
    False
    >>> isctrlascii('€')
    False
    """
    return all(False for x in _str if not LOWER_LIMIT_ASCII_CTRL <= ord(x) <= UPPER_LIMIT_ASCII_CTRL)


def isprntascii(_str: str) -> bool:
    """Test if a string is within the Printable Ascii limit

    >>> isprntascii('1')
    True
    >>> isprntascii('123')
    True
    >>> isprntascii('qwerty')
    True
    >>> isprntascii('€')
    False
    >>> isprntascii('€qwerty')
    False
    """
    return all(False for x in _str if not LOWER_LIMIT_ASCII_PRNT <= ord(x) <= UPPER_LIMIT_ASCII_PRNT)


def isextascii(_str: str) -> bool:
    """Test if a string is within the Extended Ascii limit

    >>> isextascii('á')
    True
    >>> isextascii('¶')
    True
    >>> isextascii('Ω')
    False
    >>> isextascii('μ')
    False
    >>> isextascii('Ö')
    True
    >>> isextascii('©')
    True
    >>> isextascii('Д')
    False
    """
    return all(False for x in _str if not LOWER_LIMIT_ASCII_EXT <= ord(x) < UPPER_LIMIT_ASCII_EXT)


def isgreek(_str: str) -> bool:
    """Test if the string is a string of Greek letters

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
    >>> isgreek('ΓὟᾬἄαξχΦᾁᾂὴ')
    True
    >>> isgreek('αξχΦᾁᾂὴ')
    True
    >>> isgreek('qwerty')
    False
    >>> isgreek('0123')
    False
    >>> isgreek('qwertyΓὟᾬἄαξχΦᾁᾂὴ')
    False
    >>> isgreek('0123ΓὟᾬἄαξχΦᾁᾂὴ')
    False
    """
    return all(False for x in _str if x not in GREEK_ALL)


def hasgreek(_str: str) -> bool:
    """Test if the string contains Greek letters

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
    """Test if the string is a string of Braille characters

    >>> isbraille('⠀⠁⠂⠃')
    True
    >>> isbraille('⠃')
    True
    >>> isbraille('q')
    False
    >>> isbraille('0')
    False
    >>> isbraille('⠀')
    True
    >>> isbraille('qwerty')
    False
    >>> isbraille('0123')
    False
    >>> isbraille('qwerty⠀⠁⠂⠃ᾂὴ')
    False
    >>> isbraille('0123ΓὟᾬ⠀⠁⠂⠃')
    False
    """
    return all(False for x in _str if x not in BRAILLE)


def hasbraille(_str: str) -> bool:
    """Test if the string contains Braille characters

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


def isunicode(_str: Union[bytes, str]) -> bool:  # noqa: C901
    r"""Test if a string is within the Unicode limit

    >>> isunicode('&')
    True
    >>> isunicode('\n')
    True
    >>> isunicode('𮯠')
    True
    >>> isunicode(r'\U10fffe')
    False
    >>> isunicode('\\U10ffff')
    False
    >>> isunicode('\\U110000')
    False
    """
    if not isinstance(_str, (str, bytes)):
        raise Exception(r'An invalid datatype was passed to isunicode()!')
    elif isinstance(_str, bytes):
        try:
            _str.decode(r'utf8', r'strict')
        except SyntaxError:
            return False
        return True
    elif len(_str) == 10 and r'\U' in _str:
        return int(_str.replace(r'\U', r''), 16) <= UPPER_LIMIT_UNICODE
    elif len(_str) == 6 and r'\u' in _str:
        return int(_str.replace(r'\u', r''), 16) <= UPPER_LIMIT_UNICODE
    elif _str.count(r'\x') == 1 and (len(_str) % 4) == 0:
        return int(_str.replace(r'\x', r'0x'), 16) <= UPPER_LIMIT_UNICODE
    elif _str.count(r'\x') >= 2 and (len(_str) % 4) == 0:
        try:
            literal_eval('b\'\\x{0[0]}\\x{0[1]}\\x{0[2]}\'.decode(\'utf8\', \'strict\')'.format(_str.split(r'\x')[1:]))
        except SyntaxError:
            return False
        return True
    elif len(_str) == 1:
        try:
            _str.encode(r'utf-16', r'strict')
        except SyntaxError:
            return False
        return True
    return False


def hashexescape(_str: str) -> bool:  # noqa: C901  # pylint: disable=R0912,R0915
    r"""Test if the string contains a character hex escape

    >>> hashexescape('\\U0002ebe0')
    True
    >>> hashexescape('\\u00b6')
    True
    >>> hashexescape('\\xb6')
    True
    >>> hashexescape('This is a test with \\.')
    False
    """
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
    elif r'\u' in _str:
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
    elif r'\X' in _str:
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
    elif r'\x' in _str:
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
    """Test if the string contains a character reference

    >>> testref('&#38;')
    True
    >>> testref('&amp;')
    True
    >>> testref('This is a test.')
    False
    """
    return CHAR_REF.search(_data) is not None or ENTITY_REF.search(_data) is not None


def is_palindrome(_str: str) -> bool:
    """Test if the given string is a palidrome

    >>> is_palindrome('racecar')
    True
    >>> is_palindrome('some text')
    False
    """
    return _str == _str[::-1]


# ESCAPE MANIPULATIONS #


def _search(_char: str, _num: int, _str: str, _out: list) -> list:
    """Find hexadecimal characters"""
    _ct: int = _str.count(_char)
    _start: int = 0
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


def findescapes(_str: str) -> list:
    r"""Find character hex escapes in a string

    Return a list of the escapes
    Return an empty list if none are found

    >>> findescapes('This is a \\u202f test.')
    ['\\u202f', [...]]
    """
    _out: list = []
    if r'\U' in _str:
        _out.append(_search(r'\U', 8, _str, _out))
    if r'\u' in _str:
        _out.append(_search(r'\u', 4, _str, _out))
    if r'\x' in _str:
        _out.append(_search(r'\x', 2, _str, _out))
    if r'\X' in _str:
        _out.append(_search(r'\X', 2, _str, _out))
    return _out


def shrink_esc_utf16to8(_hex: str) -> str:
    r"""Shrink a 16-bit hex escape to a 8-bit hex escape (\\uhhhh) => (\\xhh)

    >>> shrink_esc_utf16to8('\\u002f')
    '\\x2f'
    """
    if r'\u00' in _hex and len(_hex) == 6:
        return _hex.replace(r'\u00', r'\x')
    if r'\x' in _hex and len(_hex) == 4:
        return _hex
    raise Exception(_hex + r' cannot be shrunk to a 8-bit hex escape!')


def shrink_esc_utf32to8(_hex: str) -> str:
    r"""Shrink a 32-bit hex escape to a 8-bit hex escape (\\Uhhhhhhhh) => (\\xhh)

    >>> shrink_esc_utf32to8('\\U0000002f')
    '\\x2f'
    """
    if r'\U000000' in _hex and len(_hex) == 10:
        return _hex.replace(r'\U000000', r'\x')
    if r'\x' in _hex and len(_hex) == 4:
        return _hex
    raise Exception(_hex + r' cannot be shrunk to a 8-bit hex escape!')


def shrink_esc_utf32to16(_hex: str) -> str:
    r"""Shrink a 32-bit hex escape to a 16-bit hex escape (\\Uhhhhhhhh) => (\\uhhhh)

    >>> shrink_esc_utf32to16('\\U0000002f')
    '\\u002f'
    """
    if r'\U0000' in _hex and len(_hex) == 10:
        return _hex.replace(r'\U0000', r'\u')
    if r'\u' in _hex and len(_hex) == 6:
        return _hex
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
    >>> noescutf8hex('\\x40')
    '@'
    """
    if r'\x' in _hex and (len(_hex) % 4) is 0:
        _utf8_strict = '.decode(\'utf8\', \'strict\')'
        if _hex.count('\\') == 3:
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\\x{0[2]}\'' + _utf8_strict
            return literal_eval(_eval_str.format(_hex.split(r'\x')[1:]))
        if _hex.count('\\') == 2:
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\'' + _utf8_strict
            return literal_eval(_eval_str.format(_hex.split(r'\x')[1:]))
        if _hex.count('\\') == 4:
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\\x{0[2]}\\x{0[3]}\'' + _utf8_strict
            return literal_eval(_eval_str.format(_hex.split(r'\x')[1:]))
        if _hex.count('\\') == 1:
            _hex = hex(int(_hex.replace(r'\x', r''), 16)).replace(r'0x', r'')[:].zfill(2)
            return literal_eval('\'\\x{0}\''.format(_hex))
    if isinstance(_hex, str) and len(_hex) is 1:
        return _hex
    raise ValueError(r'Invalid input passed to noescutf8hex()!')


def noescape(_hex: str) -> str:
    r"""Remove escapes from a single-character hexadecimal string

    >>> noescape('\\U00000026')
    '&'
    >>> noescape('\\u0026')
    '&'
    >>> noescape('\\x26')
    '&'
    >>> noescutf8hex('\\x40')
    '@'
    """
    if r'\U' in _hex and len(_hex) == 10:
        _hex = hex(int(_hex.replace(r'\U', r''), 16)).replace('0x', r'')
        return literal_eval('"\\U{0}"'.format(_hex[:].zfill(8)))
    if r'\u' in _hex and len(_hex) == 6:
        _hex = hex(int(_hex.replace(r'\u', r''), 16)).replace('0x', r'')
        return literal_eval('"\\u{0}"'.format(_hex[:].zfill(4)))
    if r'\x' in _hex and (len(_hex) % 4) == 0:
        return noescutf8hex(_hex)
    if isinstance(_hex, str) and len(_hex) == 1:
        return _hex
    raise Exception(r'Invalid input passed to noescape()!')


def expandhexescape(_hex: str) -> str:
    r"""Convert a 16-bit hex escape to a 32-bit hex escape (\\uhhhh) => (\\Uhhhhhhhh)

    >>> expandhexescape('\\u202f')
    '\\U0000202f'
    >>> expandhexescape('\\U0000202f')
    '\\U0000202f'
    """
    if r'\u' in _hex and len(_hex) == 6:
        return _hex.replace(r'\u', r'\U0000')
    if r'\U' in _hex and len(_hex) == 10:
        return _hex
    raise Exception(_hex + r' cannot be converted to a 32-bit hex escape!')


def char2noeschex(_char: str) -> str:
    """Convert a character to a hex string lacking delimiters

    >>> char2noeschex('&')
    '26'
    >>> char2noeschex('@')
    '40'
    """
    return r'{:02x}'.format(ord(_char))


def str2noeschex(_char: str) -> str:
    """Convert a string to a hex string lacking delimiters

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


def int2char(_int: Union[int, str], _numbase: str = r'10', _escape: bool = True) -> str:
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
            return r'\U{0}'.format(hex(_int).replace(r'0x', r'')[:].zfill(8))
        if LOWER_LIMIT_ASCII_CTRL <= _int <= UPPER_LIMIT_UTF8:
            return chr(_int)
        if UPPER_LIMIT_UTF8 < _int <= UPPER_LIMIT_UNICODE:
            return literal_eval('"\\U{0}"'.format(hex(_int).replace(r'0x', r'')[:].zfill(8)))
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
    r"""Convert a Unicode name to a character

    If the name is invalid, an empty string is returned

    >>> name2char('GREEK CAPITAL LETTER DELTA')
    'Δ'
    """
    try:
        return literal_eval('"\\N{1}{0}{2}"'.format(_name.upper(), r'{', r'}'))
    except SyntaxError:
        return r''


def num2char(_str: str) -> str:
    r"""Replace numerical character representations (as a string) with the respective characters

    >>> num2char('\\U00000026')
    '&'
    >>> num2char('\\u0026')
    '&'
    >>> num2char('\\x26')
    '&'
    >>> num2char(' \\u0040 ')
    ' @ '
    >>> num2char('This is a test: \\u0040 .')
    'This is a test: @ .'
    >>> num2char('\\U0001f9e6')
    '🧦'
    >>> num2char('0001f9e6')
    '🧦'
    >>> num2char('1f9e6')
    '🧦'
    >>> num2char('0x1f9e6')
    '🧦'
    >>> num2char('0x2ebe0')
    '𮯠'
    >>> num2char('&#x2ebe0;')
    '𮯠'
    >>> num2char('U+1f6f8')
    '🛸'
    >>> num2char('%1f6f8')
    '🛸'
    >>> num2char('\\x26&#x2ebe0;U+1f6f8')
    '&𮯠🛸'
    """
    _pattern = rgxcompile(r'([0-9A-Fa-f]*)(.*)')
    if r'&#x' in _str:
        _str = HEXESCTAG.sub(r'0x\1', _str)
    if r'%' in _str:
        _str = HEXESCURI.sub(r'0x\1', _str)
    _data = rgxsplit(r'\\u|\\U|\\x|0x|U\+|U(?!\+)', _str)
    _out: list = []
    for _char in _data:
        _postpend = r''
        _null = r''
        if not _char:
            continue
        try:
            _null, _char, _postpend = rgxsplit(r'¶ж¶', _pattern.sub(r'¶ж¶\1¶ж¶\2', _char))
            del _null
            if ishex(_char):
                _out.append(chr(int(_char, 16)) + _postpend)
                continue
            _out.append(_char + _postpend)
            continue
        except ValueError:
            _out.append(_char + _postpend)
            continue
    return r''.join(_out)


# X 2 INTEGER #


def char2int(_char: str) -> int:
    """Convert a character to an integer

    >>> char2int('&')
    38
    >>> char2int('a')
    97
    >>> char2int('Z')
    90
    """
    return ord(_char)


def refnum2int(_refnum: str) -> int:
    """Convert Decimal-NCR/HTML-Entity to an integer

    >>> refnum2int('&#38;')
    38
    """
    _refnum = _refnum.strip()
    if not _refnum.startswith(r'&#') or not _refnum.endswith(r';'):
        raise Exception(r'The entered value is not a HTML entity number (&#38;)!')
    return int(_refnum.replace(r'&#', r'').replace(r';', r''), 10)


# X 2 STRING #


def str2hexesc(_str: str) -> str:
    r"""Convert a string to a UTF-8 hex string (\xc3\x9e)

    >>> str2hexesc('&')
    '\\x26'
    >>> str2hexesc('&@')
    '\\x26\\x40'
    """
    if not _str:
        raise ValueError(r'Invalid data passed to str2hexesc()!')
    return r''.join(r'{0}'.format(hex(ord(i)).replace(r'0x', r'\x')) for i in _str)


def str2uri(_str: str) -> str:
    """Convert a string to an URI escaped hex sequence (%c3%9e)

    >>> str2uri('&')
    '%26'
    >>> str2uri('Ã')
    '%c3'
    >>> str2uri('ర')
    '%c30'
    >>> str2uri('&Ãర')
    '%26%c3%c30'
    """
    if not _str:
        raise ValueError(r'Invalid data passed to str2uri()!')
    return r''.join(r'{0}'.format(hex(ord(i)).replace(r'0x', r'%')) for i in _str)


def str2intstr(_str: str) -> str:
    """Convert a string to an integer string (& => 38)

    >>> str2intstr('&')
    '38'
    >>> str2intstr('@')
    '64'
    >>> str2intstr('&@')
    '38 64'
    >>> str2intstr('Ω')
    '937'
    >>> str2intstr('¶')
    '182'
    """
    if not _str:
        raise ValueError(r'Invalid data passed to str2intstr()!')
    return r' '.join(r'{0}'.format(str(ord(i))) for i in _str)


def int2utf16(_int: int, _endian: str = r'little') -> str:
    r"""Convert an integer to a character

    >>> int2utf16(38)
    '&\x00'
    """
    if 0 <= _int <= UPPER_LIMIT_UNICODE:
        if _endian == r'little':
            return (_int).to_bytes(4, _endian).decode(r'utf-16-le', r'strict')
        if _endian == r'big':
            return (_int).to_bytes(4, _endian).decode(r'utf-16-be', r'strict')
        return (_int).to_bytes(4, r'little').decode(r'utf-16', r'strict')
    raise ValueError(r'Integer value out of valid Unicode range (0 - {0})!'.format(UPPER_LIMIT_UNICODE))


def int2utf32(_int: int, _endian: str = r'little') -> str:
    """Convert an integer to a character

    >>> int2utf32(38)
    '&'
    """
    if 0 <= _int <= UPPER_LIMIT_UNICODE:
        return (_int).to_bytes(4, _endian).decode(r'utf-32', r'strict')
    raise ValueError(r'Integer value out of valid Unicode range (0 - {0})!'.format(UPPER_LIMIT_UNICODE))


def char2num(_char: str, _upcase: bool = False) -> str:
    r"""Convert characters to unicode escapes of a proper length

    >>> char2num('&')
    '\\u0026'
    >>> char2num('@')
    '\\u0040'
    >>> char2num('&@')
    '\\u0026\\u0040'
    >>> char2num('🧦')
    '\\U0001f9e6'
    >>> char2num('&🧦@')
    '\\u0026\\U0001f9e6\\u0040'
    >>> char2num('𮯠')
    '\\U0002ebe0'
    >>> char2num('&🧦@', _upcase=True)
    '\\u0026\\U0001F9E6\\u0040'
    >>> char2num('𮯠', True)
    '\\U0002EBE0'
    """
    if not _char:
        raise ValueError(r'Invalid data passed to char2num()!')
    _out: str = r''
    for i in _char:
        _tmp = hex(ord(i)).replace(r'0x', r'')
        if len(_tmp) > 8:
            raise ValueError(r'Invalid data passed to char2num()!')
        elif len(_tmp) > 4:
            while len(_tmp) != 8:
                _tmp = r'0' + _tmp
            _out += r'\U' + _tmp.upper() if _upcase else r'\U' + _tmp
            continue
        while len(_tmp) != 4:
            _tmp = r'0' + _tmp
        _out += r'\u' + _tmp.upper() if _upcase else r'\u' + _tmp
    return _out


def str2hexstr(_str: str) -> str:
    """Convert a string to a hexadecimal string (0xc30x9e)

    >>> str2hexstr('&')
    '0x26'
    >>> str2hexstr('Ã')
    '0xc3'
    >>> str2hexstr('ర')
    '0xc30'
    >>> str2hexstr('&@')
    '0x260x40'
    >>> str2hexstr('¶')
    '0xb6'
    """
    if not _str:
        raise ValueError(r'Invalid data passed to str2hexstr()!')
    return r''.join(r'{0}'.format(hex(ord(i))) for i in _str)


def hex2unicodehex(_hex: Union[int, str]) -> str:
    r"""Convert hexadecimal to Unicode+Hex Notation (U+02EBE0)

    >>> hex2unicodehex('0x01D4C3')
    'U+01D4C3'
    >>> hex2unicodehex('\\x26')
    'U+26'
    >>> hex2unicodehex(0x26)
    'U+26'
    >>> hex2unicodehex('\\u0040')
    'U+40'
    >>> hex2unicodehex('\\002ebe0')
    'U+02EBE0'
    """
    if isinstance(_hex, str):
        if r'0x' in _hex or r'\x' in _hex:
            _hex = _hex.replace(r'0x', r'').replace(r'\x', r'')
        elif r'\U' in _hex or r'\u' in _hex:
            _hex = _hex.replace(r'\U000', r'').replace(r'\U00', r'').replace(r'\U0', r'').replace(r'\U', r'')
            _hex = _hex.replace(r'\u00', r'').replace(r'\u0', r'').replace(r'\u', r'')
        elif r'\0' in _hex or r'&#x' in _hex:
            _hex = _hex.replace(r'\0', r'').replace(r'&#x', r'').replace(r';', r'')
        return r'U+{0}'.format(_hex.upper())
    elif isinstance(_hex, int):
        return r'U+{0}'.format(hex(_hex).replace(r'0x', r'').upper())
    raise TypeError(r'Invalid datatype passed to hex2unicodehex()!')


def hex2cssnot(_hex: Union[int, str]) -> str:
    r"""Convert hexadecimal to CSS Notation (\01D4C3)

    >>> hex2cssnot('0x01D4C3')
    '\\001D4C3'
    >>> hex2cssnot('\\x26')
    '\\026'
    >>> hex2cssnot(0x26)
    '\\026'
    >>> hex2cssnot('\\u0040')
    '\\040'
    >>> hex2cssnot('U+02ebe0')
    '\\002EBE0'
    """
    if isinstance(_hex, str):
        if r'0x' in _hex or r'\x' in _hex:
            _hex = _hex.replace(r'0x', r'').replace(r'\x', r'')
        elif r'\U' in _hex:
            _hex = _hex.replace(r'\U000', r'').replace(r'\U00', r'').replace(r'\U0', r'').replace(r'\U', r'')
        elif r'\u' in _hex:
            _hex = _hex.replace(r'\u00', r'').replace(r'\u0', r'').replace(r'\u', r'')
        elif r'U+' in _hex or r'&#x' in _hex:
            _hex = _hex.replace(r'U+', r'').replace(r'&#x', r'').replace(r';', r'')
        return r'\0{0}'.format(_hex.upper())
    elif isinstance(_hex, int):
        return r'\0{0}'.format(hex(_hex).replace(r'0x', r'').upper())
    raise TypeError(r'Invalid datatype passed to hex2cssnot()!')


# X 2 BYTES #


def str2bytes(_str: str, _encoding: str = r'utf8') -> bytes:
    r"""Convert strings to bytes

    >>> str2bytes('&')
    b'&'
    >>> str2bytes('&@')
    b'&@'
    >>> str2bytes('¶')
    b'\xc2\xb6'
    """
    return _str.encode(_encoding, r'strict')


def bytes2str(_bytes: bytes, _encoding: str = r'utf8') -> str:
    """Convert bytes to strings

    >>> bytes2str(b'&')
    '&'
    >>> bytes2str(b'&@')
    '&@'
    """
    return _bytes.decode(_encoding, r'strict')


def int2hexbytes(_int: int, _length: int = 2, _endian: str = r'little', _signed: bool = False) -> bytes:
    r"""Convert int to bytes represented as an escaped hex string

    If `_endian` is "big", then the most significant byte is at the beginning of the byte array.
    If `_endian` is "little", then the most significant byte is at the end of the byte array.

    >>> int2hexbytes(38)
    b'&\x00'
    >>> int2hexbytes(64)
    b'@\x00'
    >>> int2hexbytes(64, _endian=r'big')
    b'\x00@'
    >>> int2hexbytes(6438)
    b'&\x19'
    >>> int2hexbytes(6438, _endian=r'big')
    b'\x19&'
    """
    return _int.to_bytes(_length, _endian, signed=_signed)


def hexstr2bytearray(_hex: str) -> bytearray:
    r"""Convert a hex string to a bytearray

    >>> hexstr2bytearray('2640')
    bytearray(b'&@')
    >>> hexstr2bytearray('0001f9e6')
    bytearray(b'\x00\x01\xf9\xe6')
    >>> hexstr2bytearray('1f9e6')
    bytearray(b'\x01\xf9\xe6')
    """
    _tmp: str = r'0' + _hex if len(_hex) % 2 != 0 else _hex
    return bytearray.fromhex(_tmp)


# BUBBLE TEXT #


def text2bubble(_str: str) -> str:
    """Convert a plain-text string to bubble text

    >>> text2bubble('This (str) is a sample test.')
    'Ⓣⓗⓘⓢ (⃝ⓢⓣⓡ)⃝ ⓘⓢ ⓐ ⓢⓐⓜⓟⓛⓔ ⓣⓔⓢⓣ⊙'
    >>> text2bubble('Testing various characters: €, *, Ω, ᾲ, and ⛽.')
    'Ⓣⓔⓢⓣⓘⓝⓖ ⓥⓐⓡⓘⓞⓤⓢ ⓒⓗⓐⓡⓐⓒⓣⓔⓡⓢ:⃝ €⃝,⃝ ⊛,⃝ Ω⃝,⃝ ᾲ⃝,⃝ ⓐⓝⓓ ⛽⃝⊙'
    """
    _str2: str = _str.replace('\u202f', r'').strip()
    return r''.join(i + r'⃝' if i not in PLAIN_TEXT else i for i in _str2).translate(TRANS_TEXT2BUBBLE)


def bubble2text(_str: str) -> str:
    """Convert bubble text to a plain-text string

    >>> bubble2text('Ⓣⓗⓘⓢ ⓘⓢ ⓐ ⓣⓔⓢⓣ⊙')
    'This is a test.'
    >>> bubble2text('Ⓣⓗⓘⓢ ⓘⓢ ⓐ ⓢⓔⓒⓞⓝⓓ (⃝②ⓝⓓ)⃝ ⓣⓔⓢⓣ⊙')
    'This is a second (2nd) test.'
    >>> bubble2text('Ⓣⓔⓢⓣⓘⓝⓖ ⓥⓐⓡⓘⓞⓤⓢ ⓒⓗⓐⓡⓐⓒⓣⓔⓡⓢ:⃝ €⃝,⃝ ⊛,⃝ Ω⃝,⃝ ᾲ⃝,⃝ ⓐⓝⓓ ⛽⃝⊙')
    'Testing various characters: €, *, Ω, ᾲ, and ⛽.'
    """
    return _str.replace('\u202f', r'').replace(r'⃝', r'').translate(TRANS_BUBBLE2TEST)


# SQUARE TEXT #


def text2square(_str: str, square_spaces: bool = False) -> str:
    """Convert a plain-text string to square text

    >>> text2square('This (str) is a sample test.', True)
    'T⃞h⃞i⃞s⃞ ⃞(⃞s⃞t⃞r⃞)⃞ ⃞i⃞s⃞ ⃞a⃞ ⃞s⃞a⃞m⃞p⃞l⃞e⃞ ⃞t⃞e⃞s⃞t⃞.⃞'
    >>> text2square('This (str) is a sample test.')
    'T⃞h⃞i⃞s⃞  (⃞s⃞t⃞r⃞)⃞  i⃞s⃞  a⃞  s⃞a⃞m⃞p⃞l⃞e⃞  t⃞e⃞s⃞t⃞.⃞'
    >>> text2square('Testing various characters: €, *, Ω, ᾲ, and ⛽.')
    'T⃞e⃞s⃞t⃞i⃞n⃞g⃞  v⃞a⃞r⃞i⃞o⃞u⃞s⃞  c⃞h⃞a⃞r⃞a⃞c⃞t⃞e⃞r⃞s⃞:⃞  €⃞,⃞  *⃞,⃞  Ω⃞,⃞  ᾲ⃞,⃞  a⃞n⃞d⃞  ⛽⃞.⃞'
    """
    _str2: str = _str.replace('\u202f', r'').strip()
    return r''.join(i if i == r' ' and not square_spaces else i + '\u20de' for i in _str2)


def square2text(_str: str) -> str:
    """Convert square text to a plain-text string

    >>> square2text('T⃞h⃞i⃞s⃞ ⃞(⃞s⃞t⃞r⃞)⃞ ⃞i⃞s⃞ ⃞a⃞ ⃞s⃞a⃞m⃞p⃞l⃞e⃞ ⃞t⃞e⃞s⃞t⃞.⃞')
    'This (str) is a sample test.'
    >>> square2text('T⃞h⃞i⃞s⃞  (⃞s⃞t⃞r⃞)⃞  i⃞s⃞  a⃞  s⃞a⃞m⃞p⃞l⃞e⃞  t⃞e⃞s⃞t⃞.⃞')
    'This (str) is a sample test.'
    >>> square2text('T⃞e⃞s⃞t⃞i⃞n⃞g⃞  v⃞a⃞r⃞i⃞o⃞u⃞s⃞  c⃞h⃞a⃞r⃞a⃞c⃞t⃞e⃞r⃞s⃞:⃞  €⃞,⃞  *⃞,⃞  Ω⃞,⃞  ᾲ⃞,⃞  a⃞n⃞d⃞  ⛽⃞.⃞')
    'Testing various characters: €, *, Ω, ᾲ, and ⛽.'
    """
    return _str.replace('\u202f', r'').replace(r'⃞', r'').replace(r'  ', r' ')

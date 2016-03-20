#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""@brief Functions for various string and character manipulations
@file strtools.py
@package pybooster.strtools
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@version 2016.03.20

@section DESCRIPTION
This library contains
 - Constants for various characters and character ranges
 - Functions for various string and character manipulations
 - Ascii, Hex (\\x*), UTF-8 (\\u*), UTF-16BE/UTF-32 (\\U*), HTML-Entities (&#*;)

C-escapes = JS-escapes = HTML-named-ref = decimal ncr = hex ncr\n
'\\U0001d4c3' = '\\ud835\\udcc3' = &nscr; =  &#120003; =  &#x1D4C3;\n
'\\U0001d4a9' = '\\ud835\\udca9' = &Nscr; = &#119977; = &#x1D4A9;\n

unicode+hex = 0x notation = css = utf16 = utf8 = uri%\n
U+1D4C3 = 0x1D4C3 = \01D4C3 = D835 DCC3 = F0 9D 93 83 = %F0%9D%93%83\n
U+1D4A9 = 0x1D4A9 = \01D4A9 = D835 DCA9 = F0 9D 92 A9 = %F0%9D%92%A9\n

@section VARIABLES
 - _refnum: stores an HTML reference number as a string (&#38;)
 - _refname: stores an HTML name entity as a string (&amp;)
 - _name: stores an unicode character name
 - _char: stores a single character or an escape sequence (\\x26)
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

The PyBooster Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.
"""


# pylint: disable=C0302,R0912,R0915,W0105,W0123


from sys import byteorder

try:  # Regular Expression module
    import regex as re  # noqa  # pylint: disable=C0411
except ImportError:
    import re  # noqa  # pylint: disable=C0411


__all__ = [
    # CONSTANTS
    'ORDINAL_LIST',
    'NUMBER_LIST',
    'INCOMPLETE_REF',
    'ENTITY_REF',
    'CHAR_REF',
    'CHAR_REF2',
    'LEADING_SURROGATE',
    'TRAILING_SURROGATE',
    'LOWER_LIMIT_ASCII_CTRL',
    'UPPER_LIMIT_ASCII_CTRL',
    'LOWER_LIMIT_ASCII_PRNT',
    'UPPER_LIMIT_ASCII_PRNT',
    'LOWER_LIMIT_ASCII_EXT',
    'UPPER_LIMIT_ASCII_EXT',
    'LOWER_LIMIT_MS_LATIN1',
    'UPPER_LIMIT_MS_LATIN1',
    'UPPER_LIMIT_UTF8',
    'UPPER_LIMIT_UNICODE',
    'PRINTABLE',
    'ESCTAB',
    'UNESCTAB',
    # CHARACTER SHAPES
    'BUBBLE',
    'SQUARE',
    # TRANSLATION CONSTANTS
    'BUBBLE_TEXT',
    'PLAIN_TEXT',
    # TRANSLATION TABLES
    'TRANS_TAB_BUBBLE2TEST',
    'TRANS_TAB_TEXT2BUBBLE',
    # HTML UNICODE
    'CODES',
    'HTML5_REF',
    'NAME2INT',
    'INVALID_CHARREFS',
    # CHARACTER LISTS
    'ARROWS',
    'ASTROLOGY',
    'BRAILLE',
    'CARDS',
    'CHESS',
    'CHESS_BLACK',
    'CHESS_WHITE',
    'CONTROL_SYM',
    'CONTROL_SYM_NAME',
    'CURRENCY',
    'CYRILLIC_ALPHABET',
    'DICE',
    'END_PUNCT',
    'FACES',
    'INTELLECTUAL_PROPERTY',
    'LOGIC',
    'MATH',
    'MUSIC',
    'PARENTHESIS_CHAR',
    'PLANETS',
    'PLAYING_CARDS',
    'PLAYING_CARDS_52',
    'PLAYING_CARDS_56',
    'CARDS_ACE',
    'CARDS_2',
    'CARDS_3',
    'CARDS_4',
    'CARDS_5',
    'CARDS_6',
    'CARDS_7',
    'CARDS_8',
    'CARDS_9',
    'CARDS_10',
    'CARDS_JACK',
    'CARDS_QUEEN',
    'CARDS_KING',
    'CARDS_JOKER',
    'CARDS_CHEVALIER',
    'RECYCLE',
    'SCIENCE',
    'SUPERSCRIPT_NUM',
    'ZODIAC',
    'ZODIAC_SIGNS',
    # GREEK CHARACTERS
    'GREEK_UPPER',
    'GREEK_LOWER',
    'GREEK_ARCHAIC_UPPER',
    'GREEK_ARCHAIC_LOWER',
    'GREEK_ACCENT_UPPER',
    'GREEK_ACCENT_LOWER',
    'GREEK',
    'GREEK_ARCHAIC',
    'GREEK_ACCENT',
    'GREEK_EXTENDED',
    'GREEK_ALL',
    # MISCELLANEOUS SYMBOLS
    'AIRPLANE',
    'BIOHAZARD',
    'CARD_REVERSE',
    'DOWN',
    'EJECT',
    'FUEL_PUMP',
    'KEYBOARD',
    'LEFT',
    'LOADING',
    'MEDICINE',
    'OHMS',
    'RADIATION',
    'RIGHT',
    'TELEPHONE',
    'TOXIC',
    'UP',
    'WARNING',
    # STRING MANIPULATIONS
    'endletters',
    'firstletters',
    'lastletters',
    'middleletters',
    'insert_character',
    'num2ordinal',
    'ordinal2num',
    'cap',
    'formal',
    'lowercase',
    'sentence',
    'togglecase',
    'uppercase',
    'explode',
    'implode',
    'rmcurlycommas',
    'replacecurlycommas',
    'rmcurlyquotes',
    'replacecurlyquotes',
    'rmpunct',
    'splitsentencesstr',
    'sqlstr',
    'presentlist',
    # MISCELLANEOUS FUNCTIONS
    'fval',
    'fvalhtml',
    'noescape',
    # BOOLEAN TESTS
    'isascii',
    'isstrascii',
    'isctrlascii',
    'isstrctrlascii',
    'isprntascii',
    'isstrprntascii',
    'isextascii',
    'isstrextascii',
    'isgreek',
    'isstrgreek',
    'hasgreek',
    'isbraille',
    'isstrbraille',
    'hasbraille',
    'isutf8',
    'isutf16',
    'isunicode',
    'hashexescape',
    'testref',
    # LENGTHS
    'utf7len',
    'utf8len',
    'utf16len',
    'utf32len',
    # ESCAPE MANIPULATIONS
    'shrink_esc_utf16to8',
    'shrink_esc_utf32to8',
    'shrink_esc_utf32to16',
    'escape',
    'unescape',
    'htmlentities',
    'findescapes',
    'htmlescape',
    'htmlunescape',
    'noescutf8hex',
    'expandhexescape',
    'char2noeschex',
    'str2noeschex',
    'str2hexcolon',
    'rmbyteshexesc',
    'rplbyteshexesc',
    # X 2 CHARACTER
    'int2char',
    'hexstr2char',
    'hexint2char',
    'octstr2char',
    'octint2char',
    'binstr2char',
    'binint2char',
    'refname2char',
    'refnum2char',
    'ncr2char',
    'hexncr2char',
    'name2char',
    # X 2 INTEGER
    'char2int',
    'refnum2int',
    'ncr2int',
    # X 2 UTF*
    'utf8convchar2hexescape',
    'utf8convchar2hexstr',
    'utf8convchar2uri',
    'utf8convchar2intstr',
    'int2utf16',
    'int2utf32',
    # X 2 HEX
    'char2hexstr',
    'hex2unicodehex',
    'hex2cssnot',
    # X 2 HTML REFERENCE NUMBER (NCR)
    'refname2refnum',
    'refname2ncr',
    'int2refnum',
    'int2ncr',
    # X 2 HTML ENTITY NAME
    'refnum2refname',
    'ncr2refname',
    # X 2 MISC
    'char2intstr',
    'str2bytes',
    'bytes2str',
    'int2hexbytes',
    'hexstr2bytearray',
    # BUBBLE TEXT
    'text2bubble',
    'bubble2text',
    # SQUARE TEXT
    'text2square',
    'square2text',
]


# CONSTANTS


ORDINAL_LIST = {
    r'tenth': r'10',
    r'eleventh': r'11',
    r'twelfth': r'12',
    r'thirteenth': r'13',
    r'fourteenth': r'14',
    r'fifteenth': r'15',
    r'sixteenth': r'16',
    r'seventeenth': r'17',
    r'eighteenth': r'18',
    r'ninteenth': r'19',
    r'twentieth': r'20',
    r'twenty-first': r'21',
    r'twenty-second': r'22',
    r'twenty-third': r'23',
    r'twenty-fourth': r'24',
    r'first': r'1',
    r'second': r'2',
    r'third': r'3',
    r'fourth': r'4',
    r'fifth': r'5',
    r'sixth': r'6',
    r'seventh': r'7',
    r'eighth': r'8',
    r'ninth': r'9',
}


NUMBER_LIST = {
    r'10': r'tenth',
    r'11': r'eleventh',
    r'12': r'twelfth',
    r'13': r'thirteenth',
    r'14': r'fourteenth',
    r'15': r'fifteenth',
    r'16': r'sixteenth',
    r'17': r'seventeenth',
    r'18': r'eighteenth',
    r'19': r'ninteenth',
    r'20': r'twentieth',
    r'21': r'twenty-first',
    r'22': r'twenty-second',
    r'23': r'twenty-third',
    r'24': r'twenty-fourth',
    r'1': r'first',
    r'2': r'second',
    r'3': r'third',
    r'4': r'fourth',
    r'5': r'fifth',
    r'6': r'sixth',
    r'7': r'seventh',
    r'8': r'eighth',
    r'9': r'ninth',
}


INCOMPLETE_REF = re.compile('&[#]?[0-9A-Za-z]+')
ENTITY_REF = re.compile('&[0-9A-Za-z]+;')
CHAR_REF = re.compile('&#(?:[0-9]+|[Xx][0-9A-Fa-f]+);')
CHAR_REF2 = re.compile(
    r'&(#[0-9]+;?'
    r'|#[xX][0-9a-fA-F]+;?'
    r'|[^\t\n\f <&#;]{1,32};?)'
)
LEADING_SURROGATE = re.compile(r'[\ud800-\udbff]')
TRAILING_SURROGATE = re.compile(r'[\udc00-\udfff]')

LOWER_LIMIT_ASCII_CTRL = 0  # ASCII Control Characters (Lower Limit)
UPPER_LIMIT_ASCII_CTRL = 31  # ASCII Control Characters (Upper Limit)
LOWER_LIMIT_ASCII_PRNT = 32  # ASCII Printable Characters (Lower Limit)
UPPER_LIMIT_ASCII_PRNT = 127  # ASCII Printable Characters (Upper Limit)
LOWER_LIMIT_ASCII_EXT = 128  # Extended ASCII Characters (Lower Limit)
UPPER_LIMIT_ASCII_EXT = 255  # Extended ASCII Characters (Upper Limit)
LOWER_LIMIT_MS_LATIN1 = 129  # Microsoft-Windows Latin-1 extended characters (Lower Limit)
UPPER_LIMIT_MS_LATIN1 = 159  # Microsoft-Windows Latin-1 extended characters (Upper Limit)
UPPER_LIMIT_UTF8 = 65535  # Upper Limit of UTF-8
UPPER_LIMIT_UNICODE = 1114111  # Upper Limit of Unicode


PRINTABLE = {
    # dec: ('hex', 'oct', 'char'),
    32: ('20', '040', r' '),
    33: ('21', '041', r'!'),
    34: ('22', '042', '\x22'),
    35: ('23', '043', r'#'),
    36: ('24', '044', r'$'),
    37: ('25', '045', r'%'),
    38: ('26', '046', r'&'),
    39: ('27', '047', '\x27'),
    40: ('28', '050', '\x28'),
    41: ('29', '051', '\x29'),
    42: ('2A', '052', r'*'),
    43: ('2B', '053', r'+'),
    44: ('2C', '054', '\x2C'),
    45: ('2D', '055', r'-'),
    46: ('2E', '056', r'.'),
    47: ('2F', '057', '\x2F'),
    48: ('30', '060', '0'),
    49: ('31', '061', '1'),
    50: ('32', '062', '2'),
    51: ('33', '063', '3'),
    52: ('34', '064', '4'),
    53: ('35', '065', '5'),
    54: ('36', '066', '6'),
    55: ('37', '067', '7'),
    56: ('38', '070', '8'),
    57: ('39', '071', '9'),
    58: ('3A', '072', r':'),
    59: ('3B', '073', r';'),
    60: ('3C', '074', '\x3C'),
    61: ('3D', '075', r'='),
    62: ('3E', '076', '\x3E'),
    63: ('3F', '077', r'?'),
    64: ('40', '100', r'@'),
    65: ('41', '101', 'A'),
    66: ('42', '102', 'B'),
    67: ('43', '103', 'C'),
    68: ('44', '104', 'D'),
    69: ('45', '105', 'E'),
    70: ('46', '106', 'F'),
    71: ('47', '107', 'G'),
    72: ('48', '110', 'H'),
    73: ('49', '111', 'I'),
    74: ('4A', '112', 'J'),
    75: ('4B', '113', 'K'),
    76: ('4C', '114', 'L'),
    77: ('4D', '115', 'M'),
    78: ('4E', '116', 'N'),
    79: ('4F', '117', 'O'),
    80: ('50', '120', 'P'),
    81: ('51', '121', 'Q'),
    82: ('52', '122', 'R'),
    83: ('53', '123', 'S'),
    84: ('54', '124', 'T'),
    85: ('55', '125', 'U'),
    86: ('56', '126', 'V'),
    87: ('57', '127', 'W'),
    88: ('58', '130', 'X'),
    89: ('59', '131', 'Y'),
    90: ('5A', '132', 'Z'),
    91: ('5B', '133', '\x5B'),
    92: ('5C', '134', '\x5C'),
    93: ('5D', '135', '\x5D'),
    94: ('5E', '136', r'^'),
    95: ('5F', '137', r'_'),
    96: ('60', '140', '\x60'),
    97: ('61', '141', 'a'),
    98: ('62', '142', 'b'),
    99: ('63', '143', 'c'),
    100: ('64', '144', 'd'),
    101: ('65', '145', 'e'),
    102: ('66', '146', 'f'),
    103: ('67', '147', 'g'),
    104: ('68', '150', 'h'),
    105: ('69', '151', 'I'),
    106: ('6A', '152', 'j'),
    107: ('6B', '153', 'k'),
    108: ('6C', '154', 'l'),
    109: ('6D', '155', 'm'),
    110: ('6E', '156', 'n'),
    111: ('6F', '157', 'o'),
    112: ('70', '160', 'p'),
    113: ('71', '161', 'q'),
    114: ('72', '162', 'r'),
    115: ('73', '163', 's'),
    116: ('74', '164', 't'),
    117: ('75', '165', 'u'),
    118: ('76', '166', 'v'),
    119: ('77', '167', 'w'),
    120: ('78', '170', 'x'),
    121: ('79', '171', 'y'),
    122: ('7A', '172', 'z'),
    123: ('7B', '173', '\x7B'),
    124: ('7C', '174', r'|'),
    125: ('7D', '175', '\x7D'),
    126: ('7E', '176', r'~')
}


ESCTAB = {
    '"': '&#34;',
    '\'': '&#39;',
    '(': '&#40;',
    ')': '&#41;',
    '[': '&#91;',
    ']': '&#93;',
    '{': '&#123;',
    '}': '&#125;',
    '\\': '&#92;'
}


UNESCTAB = {
    '&#34;': r'"',
    '&#39;': r'\'',
    '&#40;': r'(',
    '&#41;': r')',
    '&#91;': r'[',
    '&#93;': r']',
    '&#123;': r'{',
    '&#125;': r'}',
    '&#92;': r'\\'
}


# CHARACTER SHAPES


BUBBLE = '\u20dd'
SQUARE = '\u20de'


# TRANSLATION CONSTANTS


BUBBLE_TEXT = r'ⒶⒷⒸⒹⒺⒻⒼⒽⒾⒿⓀⓁⓂⓃⓄⓅⓆⓇⓈⓉⓊⓋⓌⓍⓎⓏⓐⓑⓒⓓⓔⓕⓖⓗⓘⓙⓚⓛⓜⓝⓞⓟⓠⓡⓢⓣⓤⓥⓦⓧⓨⓩ ⓪①②③④⑤⑥⑦⑧⑨'
PLAIN_TEXT = r'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 0123456789'


# TRANSLATION TABLES


TRANS_TAB_BUBBLE2TEST = str.maketrans(BUBBLE_TEXT, PLAIN_TEXT)
TRANS_TAB_TEXT2BUBBLE = str.maketrans(PLAIN_TEXT, BUBBLE_TEXT)


# HTML UNICODE


"""
The values in CODES includes the HTML entity names and numbers.
The characters used as keys are encoded in UTF8 (\\u) or UTF-16BE (\\U).

HTML5_REF maps the names of HTML5 character references to characters.

NAME2INT maps character names to hexadecimal integers.

INVALID_CHARREFS maps hexadecimal integers to characters that should not be used in HTML5.
"""
CODES = {
    # Unicode-hex: (Decimal, Name)
    '\u0442': ('&#1090;', '&tcy;'),
    '\u2220\u20d2': ('&#8736;&#8402;', '&nang;'),
    '\u22cf': ('&#8911;', '&cuwed;'),
    '\u2131': ('&#8497;', '&Fscr;'),
    '\U0001d511': ('&Nfr;'),
    '\u2235': ('&#8757;', '&because;'),
    '\u297d': ('&#10621;', '&rfisht;'),
    '\ud835\udd57': ('&#120151;', '&fopf;'),
    '\u03c1': ('&#961;', '&rho;'),
    '\u2ae7': ('&#10983;', '&Barv;'),
    '\u2ada': ('&#10970;', '&topfork;'),
    '\u22aa': ('&#8874;', '&Vvdash;'),
    '\u2a4c': ('&#10828;', '&ccups;'),
    '\ud835\udd66': ('&#120166;'),
    '\ud835\udd16': ('&#120086;'),
    '\u0429': ('&#1065;', '&SHCHcy;'),
    '\u226a\u0338': ('&#8810;&#824;', '&NotLessLess;'),
    '\u222b': ('&#8747;', '&Integral;'),
    '\u0173': ('&#371;', '&uogon;'),
    '\u2a45': ('&#10821;', '&cupor;'),
    '\u03bf': ('&#959;', '&omicron;'),
    '\u00d4': ('&#212;', '&Ocirc;'),
    '\u2a7d': ('&#10877;', '&LessSlantEqual;'),
    '\ud835\udcca': ('&#120010;'),
    '\u03d2': ('&#978;', '&upsih;'),
    '\ud835\udd23': ('&#120099;', '&ffr;'),
    '\u0075': ('&#117;'),
    '\ud835\udd62': ('&#120162;'),
    '\U0001d4ca': ('&uscr;'),
    '\ud835\udcce': ('&#120014;', '&yscr;'),
    '\u2158': ('&#8536;', '&frac45;'),
    '\u0021': ('&#33;', '&excl;'),
    '\u22d7': ('&#8919;', '&gtrdot;'),
    '\u0133': ('&#307;', '&ijlig;'),
    '\u22be': ('&#8894;', '&angrtvb;'),
    '\u2267': ('&#8807;', '&GreaterFullEqual;'),
    '\u2251': ('&#8785;', '&eDot;'),
    '\u00d8': ('&#216;', '&Oslash;'),
    '\u00c4': ('&#196;', '&Auml;'),
    '\u03b6': ('&#950;', '&zeta;'),
    '\u25f8': ('&#9720;', '&ultri;'),
    '\u22a1': ('&#8865;', '&sdotb;'),
    '\u00a5': ('&#165;', '&yen;'),
    '\u222f': ('&#8751;', '&DoubleContourIntegral;'),
    '\u22bd': ('&#8893;', '&barvee;'),
    '\u03b7': ('&#951;', '&eta;'),
    '\ud835\udd07': ('&#120071;', '&Dfr;'),
    '\u0427': ('&#1063;', '&CHcy;'),
    '\u0052': ('&#82;'),
    '\u0111': ('&#273;', '&dstrok;'),
    '\u2534': ('&#9524;', '&boxhu;'),
    '\u21a3': ('&#8611;', '&rightarrowtail;'),
    '\u22ee': ('&#8942;', '&vellip;'),
    '\u2127': ('&#8487;', '&mho;'),
    '\u22c1': ('&#8897;', '&xvee;'),
    '\u226e': ('&#8814;', '&NotLess;'),
    '\u0137': ('&#311;', '&kcedil;'),
    '\u012a': ('&#298;', '&Imacr;'),
    '\ud835\udd11': ('&#120081;'),
    '\u2abe': ('&#10942;', '&supdot;'),
    '\u22c9': ('&#8905;', '&ltimes;'),
    '\U0001d4b4': ('&Yscr;'),
    '\U0001d4c9': ('&tscr;'),
    '\u02d9': ('&#729;', '&dot;'),
    '\u017d': ('&#381;', '&Zcaron;'),
    '\u2137': ('&#8503;', '&gimel;'),
    '\u2939': ('&#10553;', '&larrpl;'),
    '\u25fb': ('&#9723;', '&EmptySmallSquare;'),
    '\u2a95': ('&#10901;', '&eqslantless;'),
    '\u00b0': ('&#176;', '&deg;'),
    '\u2a27': ('&#10791;', '&plustwo;'),
    '\u0106': ('&#262;', '&Cacute;'),
    '\u22d5': ('&#8917;', '&epar;'),
    '\u005d': ('&#93;', '&rsqb;', '&rbrack;'),
    '\ud835\udd37': ('&#120119;', '&zfr;'),
    '\u2262': ('&#8802;', '&NotCongruent;'),
    '\u03a6': ('&#934;', '&Phi;'),
    '\u0037': ('&#55;'),
    '\u2ab7': ('&#10935;', '&precapprox;'),
    '\u0435': ('&#1077;', '&iecy;'),
    '\u039a': ('&#922;', '&Kappa;'),
    '\u2310': ('&#8976;', '&bnot;'),
    '\u03c3': ('&#963;', '&sigma;'),
    '\u0138': ('&#312;', '&kgreen;'),
    '\u2ac6': ('&#10950;', '&supseteqq;'),
    '\u2283\u20d2': ('&#8835;&#8402;', '&vnsup;'),
    '\u23e2': ('&#9186;', '&trpezium;'),
    '\u00b6': ('&#182;', '&para;'),
    '\u2247': ('&#8775;', '&NotTildeFullEqual;'),
    '\u2717': ('&#10007;', '&cross;'),
    '\u226a\u20d2': ('&#8810;&#8402;', '&nLt;'),
    '\u00ca': ('&#202;', '&Ecirc;'),
    '\u23dc': ('&#9180;', '&OverParenthesis;'),
    '\u2a78': ('&#10872;', '&equivDD;'),
    '\u2ac6\u0338': ('&#10950;&#824;', '&nsupseteqq;'),
    '\u22f5': ('&#8949;', '&isindot;'),
    '\u003c': ('&#60;', '&lt;'),
    '\u27ed': ('&#10221;', '&roang;'),
    '\u00bd': ('&half;', '&#189;', '&frac12;'),
    '\u2568': ('&#9576;', '&boxhU;'),
    '\u221d': ('&#8733;', '&vprop;'),
    '\u0045': ('&#69;'),
    '\u2275': ('&#8821;', '&NotGreaterTilde;'),
    '\u2243': ('&#8771;', '&TildeEqual;'),
    '\u201e': ('&#8222;', '&ldquor;'),
    '\u0158': ('&#344;', '&Rcaron;'),
    '\u29c2': ('&#10690;', '&cirscir;'),
    '\u230e': ('&#8974;', '&urcrop;'),
    '\ud835\udd08': ('&#120072;'),
    '\u2a91': ('&#10897;', '&lgE;'),
    '\u03a9': ('&#937;', '&Omega;'),
    '\u00c3': ('&#195;', '&Atilde;'),
    '\u2a4a': ('&#10826;', '&cupcup;'),
    '\u2a2e': ('&#10798;', '&roplus;'),
    '\u2acc\ufe00': ('&#10956;&#65024;', '&vsupnE;'),
    '\u230d': ('&#8973;', '&dlcrop;'),
    '\u212d': ('&#8493;', '&Cfr;'),
    '\u2663': ('&#9827;', '&clubsuit;'),
    '\u21bd': ('&#8637;', '&lhard;'),
    '\u017e': ('&#382;', '&zcaron;'),
    '\u00cd': ('&#205;', '&Iacute;'),
    '\u2a6f': ('&#10863;', '&apacir;'),
    '\u043a': ('&#1082;', '&kcy;'),
    '\u00e3': ('&#227;', '&atilde;'),
    '\u03c9': ('&#969;', '&omega;'),
    '\ud835\udccf': ('&#120015;'),
    '\u00d7': ('&#215;', '&times;'),
    '\u2a2d': ('&#10797;', '&loplus;'),
    '\u2995': ('&#10645;', '&gtlPar;'),
    '\U0001d4a6': ('&Kscr;'),
    '\u2159': ('&#8537;', '&frac16;'),
    '\u0136': ('&#310;', '&Kcedil;'),
    '\u294b': ('&#10571;', '&ldrushar;'),
    '\u2211': ('&#8721;', '&sum;'),
    '\u22d9': ('&#8921;', '&ggg;'),
    '\u294f': ('&#10575;', '&RightUpDownVector;'),
    '\ufb01': ('&#64257;', '&filig;'),
    '\u2553': ('&#9555;', '&boxDr;'),
    '\u2244': ('&#8772;', '&nsimeq;'),
    '\u2280': ('&#8832;', '&nprec;'),
    '\ud835\udd36': ('&#120118;', '&yfr;'),
    '\u2a58': ('&#10840;', '&andslope;'),
    '\u2a17': ('&#10775;', '&intlarhk;'),
    '\u2ab6': ('&#10934;', '&succneqq;'),
    '\u229f': ('&#8863;', '&minusb;'),
    '\u2606': ('&#9734;', '&star;'),
    '\u2293': ('&#8851;', '&SquareIntersection;'),
    '\u260e': ('&#9742;', '&phone;'),
    '\u0439': ('&#1081;', '&jcy;'),
    '\u0169': ('&#361;', '&utilde;'),
    '\u0455': ('&#1109;', '&dscy;'),
    '\ud835\udd1a': ('&#120090;'),
    '\U0001d4b9': ('&dscr;'),
    '\u291e': ('&#10526;', '&rarrfs;'),
    '\u22f7': ('&#8951;', '&notinvb;'),
    '\u2aad': ('&#10925;', '&late;'),
    '\u040f': ('&#1039;', '&DZcy;'),
    '\U0001d54c': ('&Uopf;'),
    '\ud835\udd20': ('&#120096;'),
    '\u2190': ('&#8592;', '&slarr;'),
    '\ud835\udcb2': ('&#119986;'),
    '\u2713': ('&#10003;', '&checkmark;'),
    '\u0436': ('&#1078;', '&zhcy;'),
    '\u22b9': ('&#8889;', '&hercon;'),
    '\u212f': ('&#8495;', '&escr;'),
    '\u2a75': ('&#10869;', '&Equal;'),
    '\u2524': ('&#9508;', '&boxvl;'),
    '\u21d4': ('&#8660;', '&Leftrightarrow;'),
    '\u2a93': ('&#10899;', '&lesges;'),
    '\u201a': ('&#8218;', '&sbquo;'),
    '\u2290': ('&#8848;', '&SquareSuperset;'),
    '\U0001d4c0': ('&kscr;'),
    '\u0076': ('&#118;'),
    '\u2157': ('&#8535;', '&frac35;'),
    '\U0001d567': ('&vopf;'),
    '\u002b': ('&#43;', '&plus;'),
    '\u2423': ('&#9251;', '&blank;'),
    '\u2008': ('&#8200;', '&puncsp;'),
    '\u2992': ('&#10642;', '&rangd;'),
    '\u2a8d': ('&#10893;', '&lsime;'),
    '\u2130': ('&#8496;', '&expectation;'),
    '\ud835\udd5f': ('&#120159;'),
    '\u2a8a': ('&#10890;', '&gnapprox;'),
    '\u25be': ('&#9662;', '&dtrif;'),
    '\u27c8': ('&#10184;', '&bsolhsub;'),
    '\u2aad\ufe00': ('&#10925;&#65024;', '&lates;'),
    '\u2ac2': ('&#10946;', '&supmult;'),
    '\u295f': ('&#10591;', '&DownRightTeeVector;'),
    '\u200e': ('&#8206;', '&lrm;'),
    '\u29e3': ('&#10723;', '&eparsl;'),
    '\u2a8f': ('&#10895;', '&lsimg;'),
    '\u013e': ('&#318;', '&lcaron;'),
    '\u2abd': ('&#10941;', '&subdot;'),
    '\u2926': ('&#10534;', '&swarhk;'),
    '\u22fe': ('&#8958;', '&notnivb;'),
    '\u2111': ('&#8465;', '&imagpart;'),
    '\u0104': ('&#260;', '&Aogon;'),
    '\u2231': ('&#8753;', '&cwint;'),
    '\u042f': ('&#1071;', '&YAcy;'),
    '\ud835\udd6a': ('&#120170;'),
    '\u2ad6': ('&#10966;', '&supsup;'),
    '\u2ad8': ('&#10968;', '&supdsub;'),
    '\U0001d55c': ('&kopf;'),
    '\u2a6d': ('&#10861;', '&congdot;'),
    '\u2196': ('&#8598;', '&UpperLeftArrow;'),
    '\u2061': ('&#8289;', '&ApplyFunction;'),
    '\u03be': ('&#958;', '&xi;'),
    '\u2902': ('&#10498;', '&nvlArr;'),
    '\ud835\udcc9': ('&#120009;'),
    '\u2961': ('&#10593;', '&LeftDownTeeVector;'),
    '\u22db': ('&#8923;', '&gtreqless;'),
    '\u25b3': ('&#9651;', '&xutri;'),
    '\u2298': ('&#8856;', '&osol;'),
    '\u29dd': ('&#10717;', '&infintie;'),
    '\u0050': ('&#80;'),
    '\u03c7': ('&#967;', '&chi;'),
    '\ud835\udd29': ('&#120105;', '&lfr;'),
    '\u22d8': ('&#8920;', '&Ll;'),
    '\u22e6': ('&#8934;', '&lnsim;'),
    '\u2968': ('&#10600;', '&ruluhar;'),
    '\u22f0': ('&#8944;', '&utdot;'),
    '\u0407': ('&#1031;', '&YIcy;'),
    '\u0027': ('&#39;', '&apos;'),
    '\u21aa': ('&#8618;', '&rarrhk;'),
    '\u2323': ('&#8995;', '&ssmile;'),
    '\U0001d50a': ('&Gfr;'),
    '\u0117': ('&#279;', '&edot;'),
    '\U0001d565': ('&topf;'),
    '\u039c': ('&#924;', '&Mu;'),
    '\u005f': ('&#95;', '&UnderBar;', '&lowbar;'),
    '\u0424': ('&#1060;', '&Fcy;'),
    '\u2559': ('&#9561;', '&boxUr;'),
    '\u00a9': ('&#169;', '&copy;'),
    '\u013a': ('&#314;', '&lacute;'),
    '\u012b': ('&#299;', '&imacr;'),
    '\u25b9': ('&#9657;', '&triangleright;'),
    '\u0417': ('&#1047;', '&Zcy;'),
    '\u29cf': ('&#10703;', '&LeftTriangleBar;'),
    '\u2223': ('&#8739;', '&VerticalBar;'),
    '\u2948': ('&#10568;', '&harrcir;'),
    '\u03bc': ('&#956;', '&mu;'),
    '\u000a': ('&#10;', '&NewLine;'),
    '\u039b': ('&#923;', '&Lambda;'),
    '\ud835\udd54': ('&#120148;'),
    '\u226b\u0338': ('&#8811;&#824;', '&NotGreaterGreater;'),
    '\u0154': ('&#340;', '&Racute;'),
    '\U0001d55b': ('&jopf;'),
    '\ud835\udd1f': ('&#120095;'),
    '\u015b': ('&#347;', '&sacute;'),
    '\u2557': ('&#9559;', '&boxDL;'),
    '\ud835\udd52': ('&#120146;', '&aopf;'),
    '\u00a1': ('&#161;', '&iexcl;'),
    '\u2265': ('&#8805;', '&GreaterEqual;'),
    '\ufb02': ('&#64258;', '&fllig;'),
    '\u25b8': ('&#9656;', '&rtrif;'),
    '\u233f': ('&#9023;', '&solbar;'),
    '\u25ef': ('&#9711;', '&xcirc;'),
    '\u22c7': ('&#8903;', '&divonx;'),
    '\u0124': ('&#292;', '&Hcirc;'),
    '\u2aae': ('&#10926;', '&bumpE;'),
    '\u03c8': ('&#968;', '&psi;'),
    '\u224e': ('&#8782;', '&HumpDownHump;'),
    '\u2a23': ('&#10787;', '&plusacir;'),
    '\u2a83': ('&#10883;', '&lesdotor;'),
    '\u291b': ('&#10523;', '&lAtail;'),
    '\u0402': ('&#1026;', '&DJcy;'),
    '\u2119': ('&#8473;', '&primes;'),
    '\u0160': ('&#352;', '&Scaron;'),
    '\ud835\udd0a': ('&#120074;'),
    '\u226a': ('&#8810;', '&NestedLessLess;'),
    '\u2154': ('&#8532;', '&frac23;'),
    '\ud835\udd2d': ('&#120109;'),
    '\U0001d51a': ('&Wfr;'),
    '\u2034': ('&#8244;', '&tprime;'),
    '\u2288': ('&#8840;', '&nsubseteq;'),
    '\u29ae': ('&#10670;', '&angmsdag;'),
    '\u2a26': ('&#10790;', '&plussim;'),
    '\u02dc': ('&#732;', '&tilde;'),
    '\u0024': ('&#36;', '&dollar;'),
    '\u22d4': ('&#8916;', '&pitchfork;'),
    '\u21ba': ('&#8634;', '&olarr;'),
    '\u27e7': ('&#10215;', '&robrk;'),
    '\u2aa5': ('&#10917;', '&gla;'),
    '\u2ad5': ('&#10965;', '&subsub;'),
    '\u21d5': ('&#8661;', '&vArr;'),
    '\u00d3': ('&#211;', '&Oacute;'),
    '\u0418': ('&#1048;', '&Icy;'),
    '\u2253': ('&#8787;', '&risingdotseq;'),
    '\u2955': ('&#10581;', '&RightDownVectorBar;'),
    '\u2a44': ('&#10820;', '&capand;'),
    '\u2035': ('&#8245;', '&bprime;'),
    '\ud835\udcb6': ('&#119990;', '&ascr;'),
    '\ud835\udcc5': ('&#120005;'),
    '\U0001d4c3': ('&#120003;', '&nscr;'),
    '\u211a': ('&#8474;', '&rationals;'),
    '\U0001d55a': ('&iopf;'),
    '\U0001d521': ('&dfr;'),
    '\u0414': ('&#1044;', '&Dcy;'),
    '\u2a6a': ('&#10858;', '&simdot;'),
    '\u0143': ('&#323;', '&Nacute;'),
    '\u0146': ('&#326;', '&ncedil;'),
    '\ud835\udd40': ('&#120128;', '&Iopf;'),
    '\u298d': ('&#10637;', '&lbrkslu;'),
    '\u2ac3': ('&#10947;', '&subedot;'),
    '\u2518': ('&#9496;', '&boxul;'),
    '\ud835\udd64': ('&#120164;', '&sopf;'),
    '\u2218': ('&#8728;', '&SmallCircle;'),
    '\u0159': ('&#345;', '&rcaron;'),
    '\u21fd': ('&#8701;', '&loarr;'),
    '\u222a\ufe00': ('&#8746;&#65024;', '&cups;'),
    '\U0001d4bd': ('&hscr;'),
    '\u2591': ('&#9617;', '&blk14;'),
    '\u2916': ('&#10518;', '&Rarrtl;'),
    '\u25b1': ('&#9649;', '&fltns;'),
    '\u201c': ('&#8220;', '&OpenCurlyDoubleQuote;'),
    '\U0001d55f': ('&nopf;'),
    '\u23de': ('&#9182;', '&OverBrace;'),
    '\u2025': ('&#8229;', '&nldr;'),
    '\u0062': ('&#98;'),
    '\u2a98': ('&#10904;', '&egsdot;'),
    '\u002e': ('&#46;', '&period;'),
    '\u0164': ('&#356;', '&Tcaron;'),
    '\u2952': ('&#10578;', '&LeftVectorBar;'),
    '\u0152': ('&#338;', '&OElig;'),
    '\u0115': ('&#277;'),
    '\u2a73': ('&#10867;', '&Esim;'),
    '\u291c': ('&#10524;', '&rAtail;'),
    '\u22d8\u0338': ('&#8920;&#824;', '&nLl;'),
    '\ud835\udd4d': ('&#120141;'),
    '\U0001d554': ('&copf;'),
    '\u2261': ('&#8801;', '&equiv;'),
    '\u228f': ('&#8847;', '&SquareSubset;'),
    '\u0171': ('&#369;', '&udblac;'),
    '\u22c0': ('&#8896;', '&xwedge;'),
    '\u011b': ('&#283;', '&ecaron;'),
    '\u295d': ('&#10589;', '&RightDownTeeVector;'),
    '\u041a': ('&#1050;', '&Kcy;'),
    '\u0040': ('&#64;', '&commat;'),
    '\u00e8': ('&#232;', '&egrave;'),
    '\u228e': ('&#8846;', '&uplus;'),
    '\u23e7': ('&#9191;', '&elinters;'),
    '\u0156': ('&#342;', '&Rcedil;'),
    '\u292a': ('&#10538;', '&swnwar;'),
    '\u003b': ('&#59;', '&semi;'),
    '\u2aa2\u0338': ('&#10914;&#824;', '&NotNestedGreaterGreater;'),
    '\u2273': ('&#8819;', '&gtrsim;'),
    '\u2a97': ('&#10903;', '&elsdot;'),
    '\u2268\ufe00': ('&#8808;&#65024;', '&lvnE;'),
    '\u03a1': ('&#929;', '&Rho;'),
    '\u2203': ('&#8707;', '&Exists;'),
    '\ud835\udcb0': ('&#119984;', '&Uscr;'),
    '\ud835\udd2b': ('&#120107;'),
    '\u00ba': ('&#186;', '&ordm;'),
    '\u00c2': ('&#194;', '&Acirc;'),
    '\u002c': ('&#44;', '&comma;'),
    '\u27c9': ('&#10185;', '&suphsol;'),
    '\ud835\udcbd': ('&#119997;'),
    '\u00dd': ('&#221;', '&Yacute;'),
    '\U0001d4be': ('&iscr;'),
    '\u2aaf': ('&#10927;', '&preceq;'),
    '\u0441': ('&#1089;', '&scy;'),
    '\ud835\udccd': ('&#120013;', '&xscr;'),
    '\ud835\udcc1': ('&#120001;'),
    '\U0001d562': ('&qopf;'),
    '\u222e': ('&#8750;', '&oint;'),
    '\u2aa8': ('&#10920;', '&lescc;'),
    '\U0001d504': ('&Afr;'),
    '\ufb04': ('&#64260;', '&ffllig;'),
    '\u2229': ('&#8745;', '&cap;'),
    '\u2266': ('&#8806;', '&LessFullEqual;'),
    '\u2772': ('&#10098;', '&lbbrk;'),
    '\u2958': ('&#10584;', '&LeftUpVectorBar;'),
    '\u201d': ('&#8221;', '&rdquor;'),
    '\u2ac1': ('&#10945;', '&submult;'),
    '\u2963': ('&#10595;', '&uHar;'),
    '\u00a7': ('&#167;', '&sect;'),
    '\ud835\udcbb': ('&#119995;', '&fscr;'),
    '\u010e': ('&#270;', '&Dcaron;'),
    '\u29b6': ('&#10678;', '&omid;'),
    '\u2a85': ('&#10885;', '&lessapprox;'),
    '\u040e': ('&#1038;', '&Ubrcy;'),
    '\U0001d4a9': ('&#119977;', '&Nscr;'),
    '\u2292': ('&#8850;', '&SquareSupersetEqual;'),
    '\U0001d518': ('&Ufr;'),
    '\ud835\udd38': ('&#120120;', '&Aopf;'),
    '\u21e4': ('&#8676;', '&LeftArrowBar;'),
    '\u0101': ('&#257;', '&amacr;'),
    '\u227f\u0338': ('&#8831;&#824;', '&NotSucceedsTilde;'),
    '\u2a37': ('&#10807;', '&Otimes;'),
    '\u2033': ('&#8243;', '&Prime;'),
    '\u2a49': ('&#10825;', '&capbrcup;'),
    '\u03b8': ('&#952;', '&theta;'),
    '\u0399': ('&#921;', '&Iota;'),
    '\u0110': ('&#272;', '&Dstrok;'),
    '\u00be': ('&#190;', '&frac34;'),
    '\u0168': ('&#360;', '&Utilde;'),
    '\ud835\udca2': ('&#119970;'),
    '\u22bb': ('&#8891;', '&veebar;'),
    '\u041f': ('&#1055;', '&Pcy;'),
    '\u2ad7': ('&#10967;', '&suphsub;'),
    '\u0457': ('&#1111;', '&yicy;'),
    '\u226b\u20d2': ('&#8811;&#8402;', '&nGt;'),
    '\ud835\udd32': ('&#120114;', '&ufr;'),
    '\U0001d49f': ('&Dscr;'),
    '\u21d1': ('&#8657;', '&Uparrow;'),
    '\u27ec': ('&#10220;', '&loang;'),
    '\u2265\u20d2': ('&#8805;&#8402;', '&nvge;'),
    '\ud835\udd3c': ('&#120124;'),
    '\u22cb': ('&#8907;', '&lthree;'),
    '\u210d': ('&#8461;', '&quaternions;'),
    '\u2245': ('&#8773;', '&TildeFullEqual;'),
    '\u012c': ('&#300;'),
    '\u2580': ('&#9600;', '&uhblk;'),
    '\u2a82': ('&#10882;', '&gesdoto;'),
    '\u041d': ('&#1053;', '&Ncy;'),
    '\u22e0': ('&#8928;', '&nprcue;'),
    '\u21db': ('&#8667;', '&Rrightarrow;'),
    '\u0068': ('&#104;'),
    '\u2953': ('&#10579;', '&RightVectorBar;'),
    '\U0001d4c8': ('&sscr;'),
    '\u295b': ('&#10587;', '&RightTeeVector;'),
    '\u00f0': ('&#240;', '&eth;'),
    '\u228b': ('&#8843;', '&supsetneq;'),
    '\u2156': ('&#8534;', '&frac25;'),
    '\u0446': ('&#1094;', '&tscy;'),
    '\u22c6': ('&#8902;', '&Star;'),
    '\u21ce': ('&#8654;', '&nLeftrightarrow;'),
    '\u01f5': ('&#501;', '&gacute;'),
    '\u22eb': ('&#8939;', '&ntriangleright;'),
    '\u211b': ('&#8475;', '&Rscr;'),
    '\u0398': ('&#920;', '&Theta;'),
    '\u02c7': ('&#711;', '&Hacek;'),
    '\u03b3': ('&#947;', '&gamma;'),
    '\u0128': ('&#296;', '&Itilde;'),
    '\u22cd': ('&#8909;', '&bsime;'),
    '\u2202\u0338': ('&#8706;&#824;', '&npart;'),
    '\U0001d53b': ('&Dopf;'),
    '\u2979': ('&#10617;', '&subrarr;'),
    '\ud835\udd0d': ('&#120077;'),
    '\ufb03': ('&#64259;', '&ffilig;'),
    '\U0001d520': ('&cfr;'),
    '\u29a7': ('&#10663;', '&uwangle;'),
    '\u013d': ('&#317;', '&Lcaron;'),
    '\u2210': ('&#8720;', '&Coproduct;'),
    '\u00a3': ('&#163;', '&pound;'),
    '\u0044': ('&#68;'),
    '\u224a': ('&#8778;', '&approxeq;'),
    '\ud835\udd28': ('&#120104;'),
    '\u2234': ('&#8756;', '&therefore;'),
    '\u00d5': ('&#213;', '&Otilde;'),
    '\u0392': ('&#914;', '&Beta;'),
    '\u00cf': ('&#207;', '&Iuml;'),
    '\u2a70': ('&#10864;', '&apE;'),
    '\u2315': ('&#8981;', '&telrec;'),
    '\u00f6': ('&#246;', '&ouml;'),
    '\u22cc': ('&#8908;', '&rthree;'),
    '\u043b': ('&#1083;', '&lcy;'),
    '\u25ca': ('&#9674;', '&lozenge;'),
    '\u223d\u0331': ('&#8765;&#817;', '&race;'),
    '\u2a33': ('&#10803;', '&smashp;'),
    '\u2256': ('&#8790;', '&eqcirc;'),
    '\ud835\udd19': ('&#120089;'),
    '\u2592': ('&#9618;', '&blk12;'),
    '\u2720': ('&#10016;', '&maltese;'),
    '\u2a14': ('&#10772;', '&npolint;'),
    '\u017b': ('&#379;', '&Zdot;'),
    '\u203e': ('&#8254;', '&OverBar;'),
    '\u017c': ('&#380;', '&zdot;'),
    '\u299d': ('&#10653;', '&angrtvbd;'),
    '\u00ee': ('&#238;', '&icirc;'),
    '\u015a': ('&#346;', '&Sacute;'),
    '\ud835\udd42': ('&#120130;'),
    '\u2a5c': ('&#10844;', '&andd;'),
    '\u23b4': ('&#9140;', '&tbrk;'),
    '\u03d1': ('&#977;', '&vartheta;'),
    '\u2905': ('&#10501;', '&Map;'),
    '\u22e2': ('&#8930;', '&nsqsube;'),
    '\u0396': ('&#918;', '&Zeta;'),
    '\u296f': ('&#10607;', '&ReverseUpEquilibrium;'),
    '\u00ce': ('&#206;', '&Icirc;'),
    '\u2773': ('&#10099;', '&rbbrk;'),
    '\u00e1': ('&#225;', '&aacute;'),
    '\u0411': ('&#1041;', '&Bcy;'),
    '\u006b': ('&#107;'),
    '\u293c': ('&#10556;', '&curarrm;'),
    '\u00e4': ('&#228;', '&auml;'),
    '\ud835\udd13': ('&#120083;'),
    '\u042e': ('&#1070;', '&YUcy;'),
    '\u29c5': ('&#10693;', '&bsolb;'),
    '\u005c': ('&#92;', '&bsol;'),
    '\u225f': ('&#8799;', '&questeq;'),
    '\u00b9': ('&#185;', '&sup1;'),
    '\u297b': ('&#10619;', '&suplarr;'),
    '\u2225': ('&#8741;', '&spar;'),
    '\u2220': ('&#8736;', '&angle;'),
    '\ud835\udd1e': ('&#120094;'),
    '\u2969': ('&#10601;', '&rdldhar;'),
    '\u21ff': ('&#8703;', '&hoarr;'),
    '\u226b': ('&#8811;', '&NestedGreaterGreater;'),
    '\u2551': ('&#9553;', '&boxV;'),
    '\u0163': ('&#355;', '&tcedil;'),
    '\u2224': ('&#8740;', '&nsmid;'),
    '\u00c5': ('&#197;', '&Aring;'),
    '\u00e6': ('&#230;', '&aelig;'),
    '\u2212': ('&#8722;', '&minus;'),
    '\u2a7a': ('&#10874;', '&gtcir;'),
    '\u21b2': ('&#8626;', '&ldsh;'),
    '\u2266\u0338': ('&#8806;&#824;', '&nleqq;'),
    '\u29b3': ('&#10675;', '&raemptyv;'),
    '\u00ea': ('&#234;', '&ecirc;'),
    '\u014c': ('&#332;', '&Omacr;'),
    '\u20dc': ('&#8412;', '&DotDot;'),
    '\u0070': ('&#112;'),
    '\u0035': ('&#53;'),
    '\u29ad': ('&#10669;', '&angmsdaf;'),
    '\u2214': ('&#8724;', '&plusdo;'),
    '\u25a1': ('&#9633;', '&square;'),
    '\u00b4': ('&DiacriticalAcute;', '&#180;', '&acute;'),
    '\u2985': ('&#10629;', '&lopar;'),
    '\ud835\udd58': ('&#120152;', '&gopf;'),
    '\u0139': ('&#313;', '&Lacute;'),
    '\u228a': ('&#8842;', '&subsetneq;'),
    '\u2aa4': ('&#10916;', '&glj;'),
    '\u0141': ('&#321;', '&Lstrok;'),
    '\u29ac': ('&#10668;', '&angmsdae;'),
    '\u27e8': ('&#10216;', '&LeftAngleBracket;'),
    '\u298b': ('&#10635;', '&lbrke;'),
    '\u0130': ('&#304;', '&Idot;'),
    '\u015e': ('&#350;', '&Scedil;'),
    '\u2a55': ('&#10837;', '&andand;'),
    '\u0157': ('&#343;', '&rcedil;'),
    '\u0134': ('&#308;', '&Jcirc;'),
    '\U0001d4aa': ('&Oscr;'),
    '\u2269\ufe00': ('&#8809;&#65024;', '&gvnE;'),
    '\u2a84': ('&#10884;', '&gesdotol;'),
    '\u0065': ('&#101;'),
    '\u2155': ('&#8533;', '&frac15;'),
    '\u0022': ('&#34;', '&quot;'),
    '\u22a8': ('&#8872;', '&vDash;'),
    '\u2a38': ('&#10808;', '&odiv;'),
    '\u29a8': ('&#10664;', '&angmsdaa;'),
    '\u21ac': ('&#8620;', '&rarrlp;'),
    '\u2ae6': ('&#10982;', '&Vdashl;'),
    '\u29bf': ('&#10687;', '&ofcir;'),
    '\U0001d4c6': ('&qscr;'),
    '\u297c': ('&#10620;', '&lfisht;'),
    '\ud835\udcb8': ('&#119992;'),
    '\ud835\udccc': ('&#120012;', '&wscr;'),
    '\u290c': ('&#10508;', '&lbarr;'),
    '\u2276': ('&#8822;', '&lg;'),
    '\u0395': ('&#917;', '&Epsilon;'),
    '\u2ae4': ('&#10980;', '&DoubleLeftTee;'),
    '\u040c': ('&#1036;', '&KJcy;'),
    '\u2945': ('&#10565;', '&rarrpl;'),
    '\u2043': ('&#8259;', '&hybull;'),
    '\u2ac0': ('&#10944;', '&supplus;'),
    '\ud835\udd61': ('&#120161;'),
    '\ud835\udd5a': ('&#120154;'),
    '\u0165': ('&#357;', '&tcaron;', '&#577;'),
    '\u0038': ('&#56;'),
    '\u2a96': ('&#10902;', '&eqslantgtr;'),
    '\u2135': ('&#8501;', '&aleph;'),
    '\u2322': ('&#8994;', '&sfrown;'),
    '\u231f': ('&#8991;', '&lrcorner;'),
    '\u044e': ('&#1102;', '&yucy;'),
    '\u041c': ('&#1052;', '&Mcy;'),
    '\u2971': ('&#10609;', '&erarr;'),
    '\U0001d54d': ('&Vopf;'),
    '\u2a06': ('&#10758;', '&xsqcup;'),
    '\u29c9': ('&#10697;', '&boxbox;'),
    '\u22fb': ('&#8955;', '&xnis;'),
    '\u2004': ('&#8196;', '&emsp13;'),
    '\u224d\u20d2': ('&#8781;&#8402;', '&nvap;'),
    '\u0077': ('&#119;'),
    '\u0109': ('&#265;', '&ccirc;'),
    '\u0142': ('&#322;', '&lstrok;'),
    '\u22d9\u0338': ('&#8921;&#824;', '&nGg;'),
    '\u2044': ('&#8260;', '&frasl;'),
    '\u2abb': ('&#10939;', '&Pr;'),
    '\ud835\udc9f': ('&#119967;'),
    '\u2153': ('&#8531;', '&frac13;'),
    '\u00f5': ('&#245;', '&otilde;'),
    '\u0043': ('&#67;'),
    '\u2aaf\u0338': ('&#10927;&#824;', '&npreceq;'),
    '\u2a57': ('&#10839;', '&orslope;'),
    '\u2a00': ('&#10752;', '&xodot;'),
    '\ud835\udcbe': ('&#119998;'),
    '\u014b': ('&#331;', '&eng;'),
    '\U0001d4c5': ('&pscr;'),
    '\u0053': ('&#83;'),
    '\u00b3': ('&#179;', '&sup3;'),
    '\u210a': ('&#8458;', '&gscr;'),
    '\u215a': ('&#8538;', '&frac56;'),
    '\u0058': ('&#88;'),
    '\u2267\u0338': ('&#8807;&#824;', '&NotGreaterFullEqual;'),
    '\u0444': ('&#1092;', '&fcy;'),
    '\u2062': ('&#8290;', '&it;'),
    '\u2248': ('&#8776;', '&TildeTilde;'),
    '\u0393': ('&#915;', '&Gamma;'),
    '\ud835\udd2e': ('&#120110;'),
    '\u0028': ('&#40;', '&lpar;'),
    '\u00f9': ('&#249;', '&ugrave;'),
    '\u29cd': ('&#10701;', '&trisb;'),
    '\u2569': ('&#9577;', '&boxHU;'),
    '\u007d': ('&#125;', '&rcub;', '&rbrace;'),
    '\u29eb': ('&#10731;', '&lozf;'),
    '\ud835\udd4f': ('&#120143;', '&Xopf;'),
    '\u296d': ('&#10605;', '&lrhard;'),
    '\u2993': ('&#10643;', '&lparlt;'),
    '\u003d\u20e5': ('&#61;&#8421;', '&bne;'),
    '\u2237': ('&#8759;', '&Proportion;'),
    '\U0001d56a': ('&yopf;'),
    '\u2198': ('&#8600;', '&searrow;'),
    '\u00c7': ('&#199;', '&Ccedil;'),
    '\u2593': ('&#9619;', '&blk34;'),
    '\u2a88': ('&#10888;', '&gneq;'),
    '\u2a40': ('&#10816;', '&capdot;'),
    '\u0170': ('&#368;', '&Udblac;'),
    '\u0023': ('&#35;', '&num;'),
    '\u2264\u20d2': ('&#8804;&#8402;', '&nvle;'),
    '\u296e': ('&#10606;', '&UpEquilibrium;'),
    '\u205f\u200a': ('&#8287;&#8202;', '&ThickSpace;'),
    '\u200b': ('&#8203;', '&ZeroWidthSpace;'),
    '\U0001d555': ('&dopf;'),
    '\u2216': ('&#8726;', '&ssetmn;'),
    '\u2305': ('&#8965;', '&barwedge;'),
    '\u00d6': ('&#214;', '&Ouml;'),
    '\u2145': ('&#8517;', '&DD;'),
    '\u0063': ('&#99;'),
    '\u043f': ('&#1087;', '&pcy;'),
    '\u2a12': ('&#10770;', '&rppolint;'),
    '\u0020': ('&#32;'),
    '\u2a79': ('&#10873;', '&ltcir;'),
    '\u200c': ('&zwnj;'),
    '\u2976': ('&#10614;', '&ltlarr;'),
    '\u0404': ('&#1028;', '&Jukcy;'),
    '\u22b2': ('&#8882;', '&vltri;'),
    '\u294e': ('&#10574;', '&LeftRightVector;'),
    '\u2a31': ('&#10801;', '&timesbar;'),
    '\u255a': ('&#9562;', '&boxUR;'),
    '\u03a7': ('&#935;', '&Chi;'),
    '\u0178': ('&#376;', '&Yuml;'),
    '\U0001d522': ('&efr;'),
    '\u00eb': ('&#235;', '&euml;'),
    '\u291d': ('&#10525;', '&larrfs;'),
    '\u2306': ('&#8966;', '&doublebarwedge;'),
    '\u014e': ('&#334;'),
    '\u296a': ('&#10602;', '&lharul;'),
    '\u29b1': ('&#10673;', '&demptyv;'),
    '\u0127': ('&#295;', '&hstrok;'),
    '\u29f6': ('&#10742;', '&dsol;'),
    '\u226c': ('&#8812;', '&twixt;'),
    '\u013b': ('&#315;', '&Lcedil;'),
    '\u21c9': ('&#8649;', '&rrarr;'),
    '\u044d': ('&#1101;', '&ecy;'),
    '\u219f': ('&#8607;', '&Uarr;'),
    '\u237c': ('&#9084;', '&angzarr;'),
    '\U0001d51f': ('&bfr;'),
    '\u2a81': ('&#10881;', '&lesdoto;'),
    '\u22c5': ('&#8901;', '&sdot;'),
    '\u2255': ('&#8789;', '&eqcolon;'),
    '\U0001d4cf': ('&zscr;'),
    '\u2257': ('&#8791;', '&cire;'),
    '\u004d': ('&#77;'),
    '\u22b6': ('&#8886;', '&origof;'),
    '\u29aa': ('&#10666;', '&angmsdac;'),
    '\u224c': ('&#8780;', '&bcong;'),
    '\u255d': ('&#9565;', '&boxUL;'),
    '\u2a6e': ('&#10862;', '&easter;'),
    '\u2105': ('&#8453;', '&incare;'),
    '\u2193': ('&#8595;', '&ShortDownArrow;'),
    '\u0061': ('&#97;'),
    '\ud835\udcaf': ('&#119983;'),
    '\U0001d519': ('&Vfr;'),
    '\u2191': ('&#8593;', '&uparrow;'),
    '\u21ae': ('&#8622;', '&nleftrightarrow;'),
    '\u00fa': ('&#250;', '&uacute;'),
    '\u0009': ('&#9;', '&Tab;'),
    '\u016d': ('&#365;', '&ubreve;'),
    '\u222a': ('&#8746;', '&cup;'),
    '\u2567': ('&#9575;', '&boxHu;'),
    '\u00ec': ('&#236;', '&igrave;'),
    '\u223b': ('&#8763;', '&homtht;'),
    '\u00ac': ('&#172;', '&not;'),
    '\u25bd': ('&#9661;', '&xdtri;'),
    '\u2acf': ('&#10959;', '&csub;'),
    '\ud835\udcb3': ('&#119987;', '&Xscr;'),
    '\u2605': ('&#9733;', '&starf;'),
    '\u2a7c': ('&#10876;', '&gtquest;'),
    '\u29a9': ('&#10665;', '&angmsdab;'),
    '\u0118': ('&#280;', '&Eogon;'),
    '\u2281': ('&#8833;', '&nsucc;'),
    '\u02db': ('&#731;', '&ogon;'),
    '\ud835\udcb7': ('&#119991;', '&bscr;'),
    '\u29c1': ('&#10689;', '&ogt;'),
    '\u2060': ('&#8288;', '&NoBreak;'),
    '\u2abc': ('&#10940;', '&Sc;'),
    '\u21c5': ('&#8645;', '&UpArrowDownArrow;'),
    '\u039e': ('&#926;', '&Xi;'),
    '\u2282': ('&#8834;', '&subset;'),
    '\U0001d52f': ('&rfr;'),
    '\u2102': ('&#8450;', '&Copf;'),
    '\u22ce': ('&#8910;', '&cuvee;'),
    '\ud835\udd27': ('&#120103;'),
    '\ud835\udcac': ('&#119980;', '&Qscr;'),
    '\u0129': ('&#297;', '&itilde;'),
    '\u2960': ('&#10592;', '&LeftUpTeeVector;'),
    '\u22d0': ('&#8912;', '&Subset;'),
    '\u2a48': ('&#10824;', '&cupbrcap;'),
    '\u297e': ('&#10622;', '&ufisht;'),
    '\u0114': ('&#276;'),
    '\u21cf': ('&#8655;', '&nRightarrow;'),
    '\u256c': ('&#9580;', '&boxVH;'),
    '\u290d': ('&#10509;', '&rbarr;'),
    '\u2a66': ('&#10854;', '&sdote;'),
    '\u007c': ('&#124;', '&VerticalLine;', '&vert;', '&verbar;'),
    '\ud835\udd46': ('&#120134;', '&Oopf;'),
    '\u015c': ('&#348;', '&Scirc;'),
    '\u25f9': ('&#9721;', '&urtri;'),
    '\u2294': ('&#8852;', '&SquareUnion;'),
    '\u21b6': ('&#8630;', '&curvearrowleft;'),
    '\u007b': ('&#123;', '&lcub;', '&lbrace;'),
    '\u0434': ('&#1076;', '&dcy;'),
    '\u25ad': ('&#9645;', '&rect;'),
    '\u2ac5\u0338': ('&#10949;&#824;', '&nsubseteqq;'),
    '\u29d0': ('&#10704;', '&RightTriangleBar;'),
    '\u2758': ('&#10072;', '&VerticalSeparator;'),
    '\u227a': ('&#8826;', '&Precedes;'),
    '\u011d': ('&#285;', '&gcirc;'),
    '\u29dc': ('&#10716;', '&iinfin;'),
    '\u222c': ('&#8748;', '&Int;'),
    '\U0001d52b': ('&nfr;'),
    '\u03a4': ('&#932;', '&Tau;'),
    '\u0409': ('&#1033;', '&LJcy;'),
    '\u2aa0': ('&#10912;', '&simgE;'),
    '\u23df': ('&#9183;', '&UnderBrace;'),
    '\u03b1': ('&#945;', '&alpha;'),
    '\u293d': ('&#10557;', '&cularrp;'),
    '\u266e': ('&#9838;', '&natural;'),
    '\u014a': ('&#330;', '&ENG;'),
    '\u2309': ('&#8969;', '&RightCeiling;'),
    '\u2ac5': ('&#10949;', '&subseteqq;'),
    '\u21d0': ('&#8656;', '&Leftarrow;'),
    '\u006d': ('&#109;'),
    '\u25c3': ('&#9667;', '&triangleleft;'),
    '\ud835\udcb5': ('&#119989;', '&Zscr;'),
    '\u2991': ('&#10641;', '&langd;'),
    '\u0103': ('&#259;', '&abreve;'),
    '\u29a5': ('&#10661;', '&range;'),
    '\u2919': ('&#10521;', '&latail;'),
    '\u2254': ('&#8788;', '&coloneq;'),
    '\ud835\udcbf': ('&#119999;', '&jscr;'),
    '\u2970': ('&#10608;', '&RoundImplies;'),
    '\u0072': ('&#114;'),
    '\u27f6': ('&#10230;', '&xrarr;'),
    '\ud835\udd5b': ('&#120155;'),
    '\ud835\udd68': ('&#120168;', '&wopf;'),
    '\u0416': ('&#1046;', '&ZHcy;'),
    '\u2039': ('&#8249;', '&lsaquo;'),
    '\u2a7e\u0338': ('&#10878;&#824;', '&NotGreaterSlantEqual;'),
    '\u0440': ('&#1088;', '&rcy;'),
    '\u2013': ('&#8211;', '&ndash;'),
    '\u29bc': ('&#10684;', '&odsold;'),
    '\u21d7': ('&#8663;', '&neArr;'),
    '\U0001d516': ('&#120112;', '&Sfr;'),
    '\u2146': ('&#8518;', '&DifferentialD;'),
    '\u2010': ('&#8208;', '&hyphen;'),
    '\u2a87': ('&#10887;', '&lneq;'),
    '\u223a': ('&#8762;', '&mDDot;'),
    '\u2adb': ('&#10971;', '&mlcp;'),
    '\u253c': ('&#9532;', '&boxvh;'),
    '\u0125': ('&#293;', '&hcirc;'),
    '\u220f': ('&#8719;', '&Product;'),
    '\u0047': ('&#71;'),
    '\u00d0': ('&#208;', '&ETH;'),
    '\u00e5': ('&#229;', '&aring;'),
    '\u0153': ('&#339;', '&oelig;'),
    '\u228d': ('&#8845;', '&cupdot;'),
    '\u2032': ('&#8242;', '&prime;'),
    '\u299c': ('&#10652;', '&vangrt;'),
    '\u22a3': ('&#8867;', '&LeftTee;'),
    '\u25bf': ('&#9663;', '&triangledown;'),
    '\u2a3a': ('&#10810;', '&triminus;'),
    '\u0405': ('&#1029;', '&DScy;'),
    '\u255f': ('&#9567;', '&boxVr;'),
    '\u004c': ('&#76;'),
    '\u2205': ('&#8709;', '&varnothing;'),
    '\u2242\u0338': ('&#8770;&#824;', '&NotEqualTilde;'),
    '\u005a': ('&#90;'),
    '\ud835\udd60': ('&#120160;', '&oopf;'),
    '\u0067': ('&#103;'),
    '\u2a77': ('&#10871;', '&eDDot;'),
    '\u0113': ('&#275;', '&emacr;'),
    '\u0174': ('&#372;', '&Wcirc;'),
    '\u2282\u20d2': ('&#8834;&#8402;', '&vnsub;'),
    '\u2022': ('&#8226;', '&bullet;'),
    '\u0071': ('&#113;'),
    '\u2956': ('&#10582;', '&DownLeftVectorBar;'),
    '\u00df': ('&#223;', '&szlig;'),
    '\u015d': ('&#349;', '&scirc;'),
    '\u2642': ('&#9794;', '&male;'),
    '\u230a': ('&#8970;', '&lfloor;'),
    '\u2afd': ('&#11005;', '&parsl;'),
    '\u0069': ('&#105;'),
    '\u22f2': ('&#8946;', '&disin;'),
    '\ud835\udcc7': ('&#120007;', '&rscr;'),
    '\u00f8': ('&#248;', '&oslash;'),
    '\u215b': ('&#8539;', '&frac18;'),
    '\u29b2': ('&#10674;', '&cemptyv;'),
    '\U0001d541': ('&Jopf;'),
    '\U0001d534': ('&wfr;'),
    '\u2015': ('&#8213;', '&horbar;'),
    '\u2a53': ('&#10835;', '&And;'),
    '\u2240': ('&#8768;', '&wreath;'),
    '\u014f': ('&#335;'),
    '\u00f3': ('&#243;', '&oacute;'),
    '\ud835\udd3e': ('&#120126;', '&Gopf;'),
    '\u25b4': ('&#9652;', '&utrif;'),
    '\u25fa': ('&#9722;', '&lltri;'),
    '\u2a5a': ('&#10842;', '&andv;'),
    '\u212c': ('&#8492;', '&Bscr;'),
    '\u2192': ('&#8594;', '&srarr;'),
    '\u21ab': ('&#8619;', '&looparrowleft;'),
    '\u295a': ('&#10586;', '&LeftTeeVector;'),
    '\u224b\u0338': ('&#8779;&#824;', '&napid;'),
    '\u2272': ('&#8818;', '&lsim;'),
    '\u2a70\u0338': ('&#10864;&#824;', '&napE;'),
    '\ud835\udd31': ('&#120113;', '&tfr;'),
    '\u2920': ('&#10528;', '&rarrbfs;'),
    '\u2588': ('&#9608;', '&block;'),
    '\u0112': ('&#274;', '&Emacr;'),
    '\U0001d4a5': ('&Jscr;'),
    '\u291a': ('&#10522;', '&ratail;'),
    '\u00a0': ('&#160;', '&nbsp;', '&NonBreakingSpace;'),
    '\u2aab': ('&#10923;', '&lat;'),
    '\u2201': ('&#8705;', '&complement;'),
    '\u03a3': ('&#931;', '&Sigma;'),
    '\u0079': ('&#121;'),
    '\u298e': ('&#10638;', '&rbrksld;'),
    '\u21d9': ('&#8665;', '&swArr;'),
    '\u2138': ('&#8504;', '&daleth;'),
    '\u2a2a': ('&#10794;', '&minusdu;'),
    '\ud835\udd24': ('&#120100;', '&gfr;'),
    '\u2269': ('&#8809;', '&gneqq;'),
    '\u2af3': ('&#10995;', '&parsim;'),
    '\u016e': ('&#366;', '&Uring;'),
    '\u223d': ('&#8765;', '&bsim;'),
    '\u255e': ('&#9566;', '&boxvR;'),
    '\u03d6': ('&#982;', '&varpi;'),
    '\u2a9f': ('&#10911;', '&simlE;'),
    '\u2287': ('&#8839;', '&supseteq;'),
    '\u2aa7': ('&#10919;', '&gtcc;'),
    '\U0001d50d': ('&Jfr;'),
    '\u22a7': ('&#8871;', '&models;'),
    '\u29b7': ('&#10679;', '&opar;'),
    '\u0425': ('&#1061;', '&KHcy;'),
    '\u296c': ('&#10604;', '&rharul;'),
    '\u2aef': ('&#10991;', '&cirmid;'),
    '\u21a9': ('&#8617;', '&larrhk;'),
    '\u2a16': ('&#10774;', '&quatint;'),
    '\u224b': ('&#8779;', '&apid;'),
    '\u012d': ('&#301;'),
    '\u2229\ufe00': ('&#8745;&#65024;', '&caps;'),
    '\U0001d514': ('&Qfr;'),
    '\u03c0': ('&#960;', '&pi;'),
    '\u2afd\u20e5': ('&#11005;&#8421;', '&nparsl;'),
    '\u2996': ('&#10646;', '&ltrPar;'),
    '\U0001d52a': ('&mfr;'),
    '\u2a7d\u0338': ('&#10877;&#824;', '&NotLessSlantEqual;'),
    '\u299a': ('&#10650;', '&vzigzag;'),
    '\u2112': ('&#8466;', '&Lscr;'),
    '\u006f': ('&#111;'),
    '\u2935': ('&#10549;', '&cudarrr;'),
    '\u297f': ('&#10623;', '&dfisht;'),
    '\u221e': ('&#8734;', '&infin;'),
    '\u2a22': ('&#10786;', '&pluscir;'),
    '\u27fc': ('&#10236;', '&xmap;'),
    '\u0135': ('&#309;', '&jcirc;'),
    '\u2286': ('&#8838;', '&SubsetEqual;'),
    '\u03c6': ('&#966;', '&phi;'),
    '\u2913': ('&#10515;', '&DownArrowBar;'),
    '\u2a10': ('&#10768;', '&cirfnint;'),
    '\u2297': ('&#8855;', '&otimes;'),
    '\u0177': ('&#375;', '&ycirc;'),
    '\u22f5\u0338': ('&#8949;&#824;', '&notindot;'),
    '\u21dd': ('&#8669;', '&zigrarr;'),
    '\u00a6': ('&#166;', '&brvbar;'),
    '\u298c': ('&#10636;', '&rbrke;'),
    '\u2aac\ufe00': ('&#10924;&#65024;', '&smtes;'),
    '\u00c9': ('&#201;', '&Eacute;'),
    '\u0036': ('&#54;'),
    '\u2208': ('&#8712;', '&isinv;'),
    '\u210b': ('&#8459;', '&Hscr;'),
    '\u00db': ('&#219;', '&Ucirc;'),
    '\u00e2': ('&#226;', '&acirc;'),
    '\u25ab': ('&#9643;', '&EmptyVerySmallSquare;'),
    '\u0413': ('&#1043;', '&Gcy;'),
    '\u002d': ('&#45;'),
    '\u221a': ('&#8730;', '&Sqrt;'),
    '\u22de': ('&#8926;', '&curlyeqprec;'),
    '\u2221': ('&#8737;', '&measuredangle;'),
    '\u2313': ('&#8979;', '&profsurf;'),
    '\ud835\udd21': ('&#120097;'),
    '\u2204': ('&#8708;', '&NotExists;'),
    '\u21c8': ('&#8648;', '&uuarr;'),
    '\u02dd': ('&#733;', '&DiacriticalDoubleAcute;'),
    '\u2277': ('&#8823;', '&gtrless;'),
    '\ud835\udd10': ('&#120080;', '&Mfr;'),
    '\u21d6': ('&#8662;', '&nwArr;'),
    '\u00e7': ('&#231;', '&ccedil;'),
    '\u2133': ('&#8499;', '&phmmat;'),
    '\u22f9\u0338': ('&#8953;&#824;', '&notinE;'),
    '\u2aed': ('&#10989;', '&bNot;'),
    '\u2316': ('&#8982;', '&target;'),
    '\u2284': ('&#8836;', '&nsub;'),
    '\u2aac': ('&#10924;', '&smte;'),
    '\u2003': ('&#8195;', '&emsp;'),
    '\u25ae': ('&#9646;', '&marker;'),
    '\u042c': ('&#1068;', '&SOFTcy;'),
    '\ud835\udd34': ('&#120116;'),
    '\U0001d4af': ('&Tscr;'),
    '\u2290\u0338': ('&#8848;&#824;', '&NotSquareSuperset;'),
    '\u204f': ('&#8271;', '&bsemi;'),
    '\u29c0': ('&#10688;', '&olt;'),
    '\u221f': ('&#8735;', '&angrt;'),
    '\u0120': ('&#288;', '&Gdot;'),
    '\u0066\u006a': ('&#102;&#106;', '&fjlig;'),
    '\u2197': ('&#8599;', '&UpperRightArrow;'),
    '\u007e': ('&#126;'),
    '\u003e': ('&#62;', '&gt;'),
    '\u2ad4': ('&#10964;', '&supsub;'),
    '\u2230': ('&#8752;', '&Cconint;'),
    '\u22b7': ('&#8887;', '&imof;'),
    '\u256b': ('&#9579;', '&boxVh;'),
    '\u2950': ('&#10576;', '&DownLeftRightVector;'),
    '\u0192': ('&#402;', '&fnof;'),
    '\u0122': ('&#290;', '&Gcedil;'),
    '\u00c8': ('&#200;', '&Egrave;'),
    '\u00f4': ('&#244;', '&ocirc;'),
    '\u29e5': ('&#10725;', '&eqvparsl;'),
    '\u21b7': ('&#8631;', '&curvearrowright;'),
    '\u22c2': ('&#8898;', '&xcap;'),
    '\u21c4': ('&#8644;', '&rlarr;'),
    '\u2283': ('&#8835;', '&supset;'),
    '\u203a': ('&#8250;', '&rsaquo;'),
    '\U0001d49c': ('&Ascr;'),
    '\u256a': ('&#9578;', '&boxvH;'),
    '\u002f': ('&#47;', '&sol;'),
    '\u223e\u0333': ('&acE;'),
    '\u0131': ('&#305;', '&inodot;'),
    '\u0423': ('&#1059;', '&Ucy;'),
    '\u00a2': ('&#162;', '&cent;'),
    '\u0454': ('&#1108;', '&jukcy;'),
    '\u0452': ('&#1106;', '&djcy;'),
    '\u2228': ('&#8744;', '&vee;'),
    '\u0108': ('&#264;', '&Ccirc;'),
    '\ud835\udccb': ('&#120011;', '&vscr;'),
    '\u2236': ('&#8758;', '&ratio;'),
    '\u0176': ('&#374;', '&Ycirc;'),
    '\u2990': ('&#10640;', '&rbrkslu;'),
    '\ud835\udcb4': ('&#119988;'),
    '\u2021': ('&#8225;', '&ddagger;'),
    '\u210f': ('&#8463;', '&plankv;'),
    '\u00b7': ('&#183;', '&middot;'),
    '\u2550': ('&#9552;', '&boxH;'),
    '\u27f8': ('&#10232;', '&xlArr;'),
    '\u00bb': ('&#187;', '&raquo;'),
    '\u2270': ('&#8816;', '&NotLessEqual;'),
    '\u2a34': ('&#10804;', '&lotimes;'),
    '\u2238': ('&#8760;', '&minusd;'),
    '\u222d': ('&#8749;', '&tint;'),
    '\u21ad': ('&#8621;', '&leftrightsquigarrow;'),
    '\u219b': ('&#8603;', '&nrightarrow;'),
    '\u2285': ('&#8837;', '&nsup;'),
    '\u012e': ('&#302;', '&Iogon;'),
    '\u2a0d': ('&#10765;', '&fpartint;'),
    '\u22a0': ('&#8864;', '&timesb;'),
    '\u21a5': ('&#8613;', '&UpTeeArrow;'),
    '\u010f': ('&#271;', '&dcaron;'),
    '\u0433': ('&#1075;', '&gcy;'),
    '\u03d5': ('&#981;', '&varphi;'),
    '\u0119': ('&#281;', '&eogon;'),
    '\u2226': ('&#8742;', '&nspar;'),
    '\u29b9': ('&#10681;', '&operp;'),
    '\u226d': ('&#8813;', '&NotCupCap;'),
    '\u045a': ('&#1114;', '&njcy;'),
    '\u2924': ('&#10532;', '&nearhk;'),
    '\u03bb': ('&#955;', '&lambda;'),
    '\u0422': ('&#1058;', '&Tcy;'),
    '\u29bb': ('&#10683;', '&olcross;'),
    '\u00d9': ('&#217;', '&Ugrave;'),
    '\U0001d4b2': ('&Wscr;'),
    '\U0001d50e': ('&Kfr;'),
    '\u29c3': ('&#10691;', '&cirE;'),
    '\U0001d53c': ('&#120150;', '&Eopf;'),
    '\u00f1': ('&#241;', '&ntilde;'),
    '\u2ab5': ('&#10933;', '&prnE;'),
    '\u0151': ('&#337;', '&odblac;'),
    '\u22f6': ('&#8950;', '&notinvc;'),
    '\u2ae9': ('&#10985;', '&vBarv;'),
    '\u00b2': ('&#178;', '&sup2;'),
    '\u2560': ('&#9568;', '&boxVR;'),
    '\u2209': ('&#8713;', '&notinva;'),
    '\u2136': ('&#8502;', '&beth;'),
    '\u00de': ('&#222;', '&THORN;'),
    '\u23b6': ('&#9142;', '&bbrktbrk;'),
    '\u2acc': ('&#10956;', '&supsetneqq;'),
    '\u039d': ('&#925;', '&Nu;'),
    '\u2252': ('&#8786;', '&fallingdotseq;'),
    '\u21c7': ('&#8647;', '&llarr;'),
    '\u2ac7': ('&#10951;', '&subsim;'),
    '\u0428': ('&#1064;', '&SHcy;'),
    '\u2a46': ('&#10822;', '&cupcap;'),
    '\u0029': ('&#41;', '&rpar;'),
    '\u016a': ('&#362;', '&Umacr;'),
    '\u22a9': ('&#8873;', '&Vdash;'),
    '\U0001d542': ('&Kopf;'),
    '\u22e8': ('&#8936;', '&prnsim;'),
    '\u219d\u0338': ('&#8605;&#824;', '&nrarrw;'),
    '\ud835\udcc8': ('&#120008;'),
    '\u2954': ('&#10580;', '&RightUpVectorBar;'),
    '\u010b': ('&#267;', '&cdot;'),
    '\u22ba': ('&#8890;', '&intercal;'),
    '\u23dd': ('&#9181;', '&UnderParenthesis;'),
    '\u2a99': ('&#10905;', '&el;'),
    '\u03a0': ('&#928;', '&Pi;'),
    '\u29ce': ('&#10702;', '&rtriltri;'),
    '\U0001d517': ('&Tfr;'),
    '\u2962': ('&#10594;', '&lHar;'),
    '\U0001d4b8': ('&cscr;'),
    '\u205f': ('&#8287;', '&MediumSpace;'),
    '\u2a29': ('&#10793;', '&mcomma;'),
    '\u2951': ('&#10577;', '&LeftUpDownVector;'),
    '\u2002': ('&#8194;', '&ensp;'),
    '\u044b': ('&#1099;', '&ycy;'),
    '\u03b9': ('&#953;', '&iota;'),
    '\U0001d51e': ('&afr;'),
    '\u2020': ('&#8224;', '&dagger;'),
    '\u2294\ufe00': ('&#8852;&#65024;', '&sqcups;'),
    '\u20db': ('&#8411;', '&TripleDot;'),
    '\u01b5': ('&#437;', '&imped;'),
    '\u0073': ('&#115;'),
    '\u2aec': ('&#10988;', '&Not;'),
    '\u0140': ('&#320;', '&lmidot;'),
    '\u0121': ('&#289;', '&gdot;'),
    '\u210e': ('&#8462;', '&planckh;'),
    '\u2912': ('&#10514;', '&UpArrowBar;'),
    '\u231c': ('&#8988;', '&ulcorner;'),
    '\ud835\udc9c': ('&#119964;'),
    '\u2666': ('&#9830;', '&diams;'),
    '\u006e': ('&#110;'),
    '\u211c': ('&#8476;', '&Rfr;'),
    '\u045b': ('&#1115;', '&tshcy;'),
    '\u227b': ('&#8827;', '&Succeeds;'),
    '\u0421': ('&#1057;', '&Scy;'),
    '\u29be': ('&#10686;', '&olcir;'),
    '\u00b5': ('&#181;', '&micro;'),
    '\u2232': ('&#8754;', '&cwconint;'),
    '\u00a8': ('&#168;', '&uml;'),
    '\u0162': ('&#354;', '&Tcedil;'),
    '\u00cc': ('&#204;', '&Igrave;'),
    '\ud835\udd1c': ('&#120092;', '&Yfr;'),
    '\u004a': ('&#74;'),
    '\u2500': ('&#9472;', '&HorizontalLine;'),
    '\u2016': ('&#8214;', '&Vert;'),
    '\u011c': ('&#284;', '&Gcirc;'),
    '\u0145': ('&#325;', '&Ncedil;'),
    '\u043e': ('&#1086;', '&ocy;'),
    '\u291f': ('&#10527;', '&larrbfs;'),
    '\u007a': ('&#122;'),
    '\u2640': ('&#9792;', '&female;'),
    '\u21d2': ('&#8658;', '&Rightarrow;'),
    '\u2a8c': ('&#10892;', '&gtreqqless;'),
    '\u2063': ('&#8291;', '&InvisibleComma;'),
    '\u22f4': ('&#8948;', '&isins;'),
    '\u00fd': ('&#253;', '&yacute;'),
    '\u229a': ('&#8858;', '&ocir;'),
    '\u041e': ('&#1054;', '&Ocy;'),
    '\u2911': ('&#10513;', '&DDotrahd;'),
    '\u00af': ('&#175;', '&macr;', '&strns;'),
    '\u227f': ('&#8831;', '&succsim;'),
    '\u2a39': ('&#10809;', '&triplus;'),
    '\u250c': ('&#9484;', '&boxdr;'),
    '\u219a': ('&#8602;', '&nleftarrow;'),
    '\u003d': ('&#61;', '&equals;'),
    '\u2296': ('&#8854;', '&ominus;'),
    '\u2195': ('&#8597;', '&varr;'),
    '\u21cd': ('&#8653;', '&nLeftarrow;'),
    '\ud835\udd3b': ('&#120123;'),
    '\u21be': ('&#8638;', '&upharpoonright;'),
    '\u2ad0': ('&#10960;', '&csup;'),
    '\u2936': ('&#10550;', '&ldca;'),
    '\u0048': ('&#72;'),
    '\u0430': ('&#1072;', '&acy;'),
    '\u2565': ('&#9573;', '&boxhD;'),
    '\u2584': ('&#9604;', '&lhblk;'),
    '\u27fa': ('&#10234;', '&xhArr;'),
    '\u2200': ('&#8704;', '&forall;'),
    '\u2a54': ('&#10836;', '&Or;'),
    '\u29f4': ('&#10740;', '&RuleDelayed;'),
    '\u0175': ('&#373;', '&wcirc;'),
    '\u010a': ('&#266;', '&Cdot;'),
    '\u290f': ('&#10511;', '&rBarr;'),
    '\ud835\udd12': ('&#120082;', '&Ofr;'),
    '\u22fa': ('&#8954;', '&nisd;'),
    '\u2ab8': ('&#10936;', '&succapprox;'),
    '\u22f3': ('&#8947;', '&isinsv;'),
    '\u29e4': ('&#10724;', '&smeparsl;'),
    '\u012f': ('&#303;', '&iogon;'),
    '\u2925': ('&#10533;', '&searhk;'),
    '\u2a43': ('&#10819;', '&ncap;'),
    '\u2ab4': ('&#10932;', '&scE;'),
    '\u21a0': ('&#8608;', '&twoheadrightarrow;'),
    '\u29cf\u0338': ('&#10703;&#824;', '&NotLeftTriangleBar;'),
    '\u2a01': ('&#10753;', '&xoplus;'),
    '\u21bc': ('&#8636;', '&lharu;'),
    '\u2a2f': ('&#10799;', '&Cross;'),
    '\u0031': ('&#49;'),
    '\u2904': ('&#10500;', '&nvHarr;'),
    '\U0001d505': ('&Bfr;'),
    '\u22ca': ('&#8906;', '&rtimes;'),
    '\u21c6': ('&#8646;', '&lrarr;'),
    '\u2986': ('&#10630;', '&ropar;'),
    '\u22b0': ('&#8880;', '&prurel;'),
    '\u2a7b': ('&#10875;', '&ltquest;'),
    '\u003f': ('&#63;', '&quest;'),
    '\u2a3b': ('&#10811;', '&tritime;'),
    '\u03b4': ('&#948;', '&delta;'),
    '\u22ad': ('&#8877;', '&nvDash;'),
    '\u2014': ('&#8212;', '&mdash;'),
    '\u2959': ('&#10585;', '&LeftDownVectorBar;'),
    '\u0026': ('&#38;', '&amp;'),
    '\u2233': ('&#8755;', '&CounterClockwiseContourIntegral;'),
    '\u03ba': ('&#954;', '&kappa;'),
    '\u27e6': ('&#10214;', '&lobrk;'),
    '\u2a9e': ('&#10910;', '&simg;'),
    '\u2910': ('&#10512;', '&RBarr;'),
    '\u2ab0\u0338': ('&#10928;&#824;', '&nsucceq;'),
    '\u2514': ('&#9492;', '&boxur;'),
    '\u2aa1\u0338': ('&#10913;&#824;', '&NotNestedLessLess;'),
    '\u0451': ('&#1105;', '&iocy;'),
    '\u0116': ('&#278;', '&Edot;'),
    '\u21b5': ('&#8629;', '&crarr;'),
    '\u044a': ('&#1098;', '&hardcy;'),
    '\u013c': ('&#316;', '&lcedil;'),
    '\ud835\udd44': ('&#120132;'),
    '\u227c': ('&#8828;', '&PrecedesSlantEqual;'),
    '\u039f': ('&#927;', '&Omicron;'),
    '\U0001d53d': ('&Fopf;'),
    '\u2a42': ('&#10818;', '&ncup;'),
    '\ud835\udd65': ('&#120165;'),
    '\u03c5': ('&#965;', '&upsilon;'),
    '\u004b': ('&#75;'),
    '\ud835\udcae': ('&#119982;'),
    '\u0060': ('&#96;', '&grave;', '&DiacriticalGrave;'),
    '\u2abf': ('&#10943;', '&subplus;'),
    '\u0126': ('&#294;', '&Hstrok;'),
    '\ud835\udcc0': ('&#120000;'),
    '\u2268': ('&#8808;', '&lneqq;'),
    '\u2564': ('&#9572;', '&boxHd;'),
    '\u2a5b': ('&#10843;', '&orv;'),
    '\ud835\udd14': ('&#120084;'),
    '\ud835\udd35': ('&#120117;', '&xfr;'),
    '\u0459': ('&#1113;', '&ljcy;'),
    '\u2ad2': ('&#10962;', '&csupe;'),
    '\u2278': ('&#8824;', '&ntlg;'),
    '\u21bf': ('&#8639;', '&upharpoonleft;'),
    '\u00bf': ('&#191;', '&iquest;'),
    '\u2aee': ('&#10990;', '&rnmid;'),
    '\u220c': ('&#8716;', '&NotReverseElement;'),
    '\ud835\udd09': ('&#120073;', '&Ffr;'),
    '\u2a47': ('&#10823;', '&capcup;'),
    '\u2566': ('&#9574;', '&boxHD;'),
    '\u29b0': ('&#10672;', '&bemptyv;'),
    '\u2973': ('&#10611;', '&larrsim;'),
    '\u03dd': ('&#989;', '&gammad;'),
    '\ud835\udd0f': ('&#120079;', '&Lfr;'),
    '\u225a': ('&#8794;', '&veeeq;'),
    '\u200d': ('&#8205;', '&zwj;'),
    '\u2af0': ('&#10992;', '&midcir;'),
    '\u2ab3': ('&#10931;', '&prE;'),
    '\ud835\udca6': ('&#119974;'),
    '\u266f': ('&#9839;', '&sharp;'),
    '\u2279': ('&#8825;', '&ntgl;'),
    '\u0449': ('&#1097;', '&shchcy;'),
    '\u00cb': ('&#203;', '&Euml;'),
    '\u045c': ('&#1116;', '&kjcy;'),
    '\u25b5': ('&#9653;', '&utri;'),
    '\u2967': ('&#10599;', '&ldrdhar;'),
    '\u23b5': ('&#9141;', '&UnderBracket;'),
    '\u251c': ('&#9500;', '&boxvr;'),
    '\u002a': ('&#42;', '&midast;', '&ast;'),
    '\ud835\udcc6': ('&#120006;'),
    '\u215e': ('&#8542;', '&frac78;'),
    '\u2005': ('&#8197;', '&emsp14;'),
    '\u2289': ('&#8841;', '&nsupseteq;'),
    '\u22da': ('&#8922;', '&LessEqualGreater;'),
    '\u00aa': ('&#170;', '&ordf;'),
    '\u2929': ('&#10537;', '&tosa;'),
    '\u22df': ('&#8927;', '&curlyeqsucc;'),
    '\u2965': ('&#10597;', '&dHar;'),
    '\u296b': ('&#10603;', '&llhard;'),
    '\ud835\udcc2': ('&#120002;', '&mscr;'),
    '\u0149': ('&#329;', '&napos;'),
    '\u016b': ('&#363;', '&umacr;'),
    '\u0100': ('&#256;', '&Amacr;'),
    '\u0412': ('&#1042;', '&Vcy;'),
    '\u00ef': ('&#239;', '&iuml;'),
    '\u219d': ('&#8605;', '&rightsquigarrow;'),
    '\u290e': ('&#10510;', '&lBarr;'),
    '\u2a0c': ('&#10764;', '&qint;'),
    '\u03c4': ('&#964;', '&tau;'),
    '\u010d': ('&#269;', '&ccaron;'),
    '\ud835\udd6b': ('&#120171;', '&zopf;'),
    '\u0150': ('&#336;', '&Odblac;'),
    '\u00d1': ('&#209;', '&Ntilde;'),
    '\u22da\ufe00': ('&#8922;&#65024;', '&lesg;'),
    '\u03f6': ('&#1014;', '&bepsi;'),
    '\u295e': ('&#10590;', '&DownLeftTeeVector;'),
    '\u0147': ('&#327;', '&Ncaron;'),
    '\U0001d561': ('&popf;'),
    '\U0001d513': ('&Pfr;'),
    '\u2227': ('&#8743;', '&wedge;'),
    '\U0001d55e': ('&mopf;'),
    '\u0408': ('&#1032;', '&Jsercy;'),
    '\u29a4': ('&#10660;', '&ange;'),
    '\u0161': ('&#353;', '&scaron;'),
    '\ud835\udd4a': ('&#120138;'),
    '\u2a6d\u0338': ('&#10861;&#824;', '&ncongdot;'),
    '\u2972': ('&#10610;', '&simrarr;'),
    '\u231e': ('&#8990;', '&llcorner;'),
    '\u00ae': ('&#174;', '&reg;'),
    '\ud835\udd4c': ('&#120140;'),
    '\U0001d4ae': ('&Sscr;'),
    '\u2264': ('&#8804;', '&leq;'),
    '\u22b3': ('&#8883;', '&vrtri;'),
    '\u2ad9': ('&#10969;', '&forkv;'),
    '\u00f2': ('&#242;', '&ograve;'),
    '\u005e': ('&#94;', '&Hat;'),
    '\u0066': ('&#102;'),
    '\u2134': ('&#8500;', '&oscr;'),
    '\ud835\udd53': ('&#120147;'),
    '\u0237': ('&#567;', '&jmath;'),
    '\U0001d553': ('&bopf;'),
    '\u0032': ('&#50;'),
    '\u0078': ('&#120;'),
    '\u211e': ('&#8478;', '&rx;'),
    '\u24c8': ('&#9416;', '&oS;'),
    '\u27eb': ('&#10219;', '&Rang;'),
    '\u2308': ('&#8968;', '&LeftCeiling;'),
    '\u2ad1': ('&#10961;', '&csube;'),
    '\u2a04': ('&#10756;', '&xuplus;'),
    '\u223f': ('&#8767;', '&acd;'),
    '\u2299': ('&#8857;', '&odot;'),
    '\u0041': ('&#65;'),
    '\u2274': ('&#8820;', '&NotLessTilde;'),
    '\U0001d569': ('&xopf;'),
    '\u215d': ('&#8541;', '&frac58;'),
    '\u0107': ('&#263;', '&cacute;'),
    '\u0056': ('&#86;'),
    '\ud835\udd04': ('&#120068;'),
    '\u0166': ('&#358;', '&Tstrok;'),
    '\u0049': ('&#73;'),
    '\u2558': ('&#9560;', '&boxuR;'),
    '\u22d6': ('&#8918;', '&ltdot;'),
    '\u2928': ('&#10536;', '&toea;'),
    '\u042b': ('&#1067;', '&Ycy;'),
    '\u010c': ('&#268;', '&Ccaron;'),
    '\u2122': ('&#8482;', '&trade;'),
    '\u2975': ('&#10613;', '&rarrap;'),
    '\u03f0': ('&#1008;', '&varkappa;'),
    '\u21d8': ('&#8664;', '&seArr;'),
    '\u224f\u0338': ('&#8783;&#824;', '&NotHumpEqual;'),
    '\ud835\udd5e': ('&#120158;'),
    '\u0030': ('&#48;'),
    '\u2aaa': ('&#10922;', '&smt;'),
    '\u29b5': ('&#10677;', '&ohbar;'),
    '\u220b': ('&#8715;', '&SuchThat;'),
    '\u2978': ('&#10616;', '&gtrarr;'),
    '\u27ff': ('&#10239;', '&dzigrarr;'),
    '\u2118': ('&#8472;', '&wp;'),
    '\u25ec': ('&#9708;', '&tridot;'),
    '\u227e': ('&#8830;', '&prsim;'),
    '\u29af': ('&#10671;', '&angmsdah;'),
    '\u2563': ('&#9571;', '&boxVL;'),
    '\u2a86': ('&#10886;', '&gtrapprox;'),
    '\u2903': ('&#10499;', '&nvrArr;'),
    '\u2a8b': ('&#10891;', '&lesseqqgtr;'),
    '\u231d': ('&#8989;', '&urcorner;'),
    '\u27ea': ('&#10218;', '&Lang;'),
    '\u229d': ('&#8861;', '&odash;'),
    '\u22fc': ('&#8956;', '&nis;'),
    '\u2250': ('&#8784;', '&esdot;'),
    '\ud835\udcaa': ('&#119978;'),
    '\u2556': ('&#9558;', '&boxDl;'),
    '\ud835\udd2c': ('&#120108;', '&ofr;'),
    '\u00c6': ('&#198;', '&AElig;'),
    '\u0443': ('&#1091;', '&ucy;'),
    '\ud835\udd33': ('&#120115;', '&vfr;'),
    '\u215c': ('&#8540;', '&frac38;'),
    '\u2312': ('&#8978;', '&profline;'),
    '\u011a': ('&#282;', '&Ecaron;'),
    '\u0179': ('&#377;', '&Zacute;'),
    '\u2202': ('&#8706;', '&PartialD;'),
    '\u2259': ('&#8793;', '&wedgeq;'),
    '\u294a': ('&#10570;', '&lurdshar;'),
    '\u22a5': ('&#8869;', '&UpTee;'),
    '\u2261\u20e5': ('&#8801;&#8421;', '&bnequiv;'),
    '\u02d8': ('&#728;', '&breve;'),
    '\u0046': ('&#70;'),
    '\u226f': ('&#8815;', '&NotGreater;'),
    '\u223c': ('&#8764;', '&Tilde;'),
    '\u03b5': ('&#949;', '&epsilon;'),
    '\u0132': ('&#306;', '&IJlig;'),
    '\u0123': ('&#291;'),
    '\u22ac': ('&#8876;', '&nvdash;'),
    '\u232e': ('&#9006;', '&profalar;'),
    '\u017f': ('&#383;'),
    '\u2923': ('&#10531;', '&nwarhk;'),
    '\ud835\udd5c': ('&#120156;'),
    '\u21c2': ('&#8642;', '&RightDownVector;'),
    '\u27e9': ('&#10217;', '&RightAngleBracket;'),
    '\u005b': ('&#91;', '&lsqb;', '&lbrack;'),
    '\u298f': ('&#10639;', '&lbrksld;'),
    '\u013f': ('&#319;', '&Lmidot;'),
    '\u2246': ('&#8774;', '&simne;'),
    '\u22b4\u20d2': ('&#8884;&#8402;', '&nvltrie;'),
    '\u21a2': ('&#8610;', '&leftarrowtail;'),
    '\u015f': ('&#351;', '&scedil;'),
    '\u2124': ('&#8484;', '&Zopf;'),
    '\u224f': ('&#8783;', '&HumpEqual;'),
    '\u2ab0': ('&#10928;', '&succeq;'),
    '\ud835\udd17': ('&#120087;'),
    '\u228b\ufe00': ('&#8843;&#65024;', '&vsupne;'),
    '\u22bf': ('&#8895;', '&lrtri;'),
    '\u2115': ('&#8469;', '&Nopf;'),
    '\u0403': ('&#1027;', '&GJcy;'),
    '\u2a02': ('&#10754;', '&xotime;'),
    '\u03b2': ('&#946;', '&beta;'),
    '\u2554': ('&#9556;', '&boxDR;'),
    '\u2a5f': ('&#10847;', '&wedbar;'),
    '\u0448': ('&#1096;', '&shcy;'),
    '\u22b4': ('&#8884;', '&trianglelefteq;'),
    '\u045e': ('&#1118;', '&ubrcy;'),
    '\u0039': ('&#57;'),
    '\u0172': ('&#370;', '&Uogon;'),
    '\U0001d52d': ('&pfr;'),
    '\u21a7': ('&#8615;', '&mapstodown;'),
    '\u22e1': ('&#8929;', '&nsccue;'),
    '\u21da': ('&#8666;', '&Lleftarrow;'),
    '\u22af': ('&#8879;', '&nVDash;'),
    '\u00b8': ('&#184;', '&cedil;', '&Cedilla;'),
    '\u03a8': ('&#936;', '&Psi;'),
    '\u29c4': ('&#10692;', '&solb;'),
    '\u224d': ('&#8781;', '&CupCap;'),
    '\u228a\ufe00': ('&#8842;&#65024;', '&vsubne;'),
    '\ud835\udcb9': ('&#119993;'),
    '\u22b5\u20d2': ('&#8885;&#8402;', '&nvrtrie;'),
    '\u2acb': ('&#10955;', '&subsetneqq;'),
    '\u21cb': ('&#8651;', '&ReverseEquilibrium;'),
    '\u00e9': ('&#233;', '&eacute;'),
    '\U0001d4c1': ('&lscr;'),
    '\u229b': ('&#8859;', '&oast;'),
    '\u2a74': ('&#10868;', '&Colone;'),
    '\u0432': ('&#1074;', '&vcy;'),
    '\u2a8e': ('&#10894;', '&gsime;'),
    '\u2117': ('&#8471;', '&copysr;'),
    '\u2a7e': ('&#10878;', '&GreaterSlantEqual;'),
    '\u2007': ('&#8199;', '&numsp;'),
    '\u0401': ('&#1025;', '&IOcy;'),
    '\u2ab9': ('&#10937;', '&prnap;'),
    '\u255b': ('&#9563;', '&boxuL;'),
    '\u2966': ('&#10598;', '&luruhar;'),
    '\u2ac8': ('&#10952;', '&supsim;'),
    '\ud835\udd18': ('&#120088;'),
    '\ud835\udd63': ('&#120163;', '&ropf;'),
    '\u22c4': ('&#8900;', '&diamond;'),
    '\u2aa2': ('&#10914;', '&GreaterGreater;'),
    '\u29a6': ('&#10662;', '&dwangle;'),
    '\u2a36': ('&#10806;', '&otimesas;'),
    '\u040b': ('&#1035;', '&TSHcy;'),
    '\u0453': ('&#1107;', '&gjcy;'),
    '\u2242': ('&#8770;', '&esim;'),
    '\u2949': ('&#10569;', '&Uarrocir;'),
    '\u0438': ('&#1080;', '&icy;'),
    '\u22b5': ('&#8885;', '&trianglerighteq;'),
    '\u003c\u20d2': ('&#60;&#8402;', '&nvlt;'),
    '\u22e9': ('&#8937;', '&succnsim;'),
    '\U0001d544': ('&Mopf;'),
    '\u2a3c': ('&#10812;', '&iprod;'),
    '\u004f': ('&#79;'),
    '\u229e': ('&#8862;', '&plusb;'),
    '\u22d1': ('&#8913;', '&Supset;'),
    '\u00fe': ('&#254;', '&thorn;'),
    '\u2260': ('&#8800;', '&NotEqual;'),
    '\u2295': ('&#8853;', '&oplus;'),
    '\u2a13': ('&#10771;', '&scpolint;'),
    '\ud835\udd4b': ('&#120139;', '&Topf;'),
    '\u0437': ('&#1079;', '&zcy;'),
    '\u2a56': ('&#10838;', '&oror;'),
    '\u22c3': ('&#8899;', '&xcup;'),
    '\u29ab': ('&#10667;', '&angmsdad;'),
    '\u2a5d': ('&#10845;', '&ord;'),
    '\u016f': ('&#367;', '&uring;'),
    '\u0155': ('&#341;', '&racute;'),
    '\u2a89': ('&#10889;', '&lnapprox;'),
    '\u00ab': ('&#171;', '&laquo;'),
    '\u2af1': ('&#10993;', '&topcir;'),
    '\u2aa1': ('&#10913;', '&LessLess;'),
    '\u2a80': ('&#10880;', '&gesdot;'),
    '\u29de': ('&#10718;', '&nvinfin;'),
    '\u2a7f': ('&#10879;', '&lesdot;'),
    '\u2a3f': ('&#10815;', '&amalg;'),
    '\u0456': ('&#1110;', '&iukcy;'),
    '\u2250\u0338': ('&#8784;&#824;', '&nedot;'),
    '\ud835\udd43': ('&#120131;', '&Lopf;'),
    '\u014d': ('&#333;', '&omacr;'),
    '\u042a': ('&#1066;', '&HARDcy;'),
    '\u21fe': ('&#8702;', '&roarr;'),
    '\u2110': ('&#8464;', '&Iscr;'),
    '\u27f7': ('&#10231;', '&xharr;'),
    '\u006a': ('&#106;'),
    '\u2957': ('&#10583;', '&DownRightVectorBar;'),
    '\u22ed': ('&#8941;', '&ntrianglerighteq;'),
    '\u041b': ('&#1051;', '&Lcy;'),
    '\u0148': ('&#328;', '&ncaron;'),
    '\u2964': ('&#10596;', '&rHar;'),
    '\u0447': ('&#1095;', '&chcy;'),
    '\u2128': ('&#8488;', '&Zfr;'),
    '\u22e3': ('&#8931;', '&nsqsupe;'),
    '\u2222': ('&#8738;', '&angsph;'),
    '\u2a25': ('&#10789;', '&plusdu;'),
    '\u0415': ('&#1045;', '&IEcy;'),
    '\u25c2': ('&#9666;', '&ltrif;'),
    '\u22f9': ('&#8953;', '&isinE;'),
    '\u0410': ('&#1040;', '&Acy;'),
    '\u21c3': ('&#8643;', '&LeftDownVector;'),
    '\u043d': ('&#1085;', '&ncy;'),
    '\u2938': ('&#10552;', '&cudarrl;'),
    '\u043c': ('&#1084;', '&mcy;'),
    '\u042d': ('&#1069;', '&Ecy;'),
    '\u004e': ('&#78;'),
    '\u2041': ('&#8257;', '&caret;'),
    '\u29b4': ('&#10676;', '&laemptyv;'),
    '\u2207': ('&#8711;', '&nabla;'),
    '\u03f1': ('&#1009;', '&varrho;'),
    '\u2a71': ('&#10865;', '&eplus;'),
    '\u2a24': ('&#10788;', '&simplus;'),
    '\u03bd': ('&#957;', '&nu;'),
    '\u2974': ('&#10612;', '&rarrsim;'),
    '\u00a4': ('&#164;', '&curren;'),
    '\U0001d4a2': ('&Gscr;'),
    '\u227d': ('&#8829;', '&SucceedsSlantEqual;'),
    '\u22ec': ('&#8940;', '&ntrianglelefteq;'),
    '\u22a2': ('&#8866;', '&vdash;'),
    '\u22ea': ('&#8938;', '&ntriangleleft;'),
    '\u00dc': ('&#220;', '&Uuml;'),
    '\ud835\udd50': ('&#120144;'),
    '\u2291': ('&#8849;', '&SquareSubsetEqual;'),
    '\u2af2': ('&#10994;', '&nhpar;'),
    '\u2933': ('&#10547;', '&rarrc;'),
    '\u2019': ('&#8217;', '&rsquor;'),
    '\u255c': ('&#9564;', '&boxUl;'),
    '\ud835\udd3d': ('&#120125;'),
    '\U0001d527': ('&jfr;'),
    '\u2510': ('&#9488;', '&boxdl;'),
    '\u00ad': ('&#173;', '&shy;'),
    '\ud835\udd55': ('&#120149;'),
    '\u22d2': ('&#8914;', '&Cap;'),
    '\u21c0': ('&#8640;', '&RightVector;'),
    '\u230f': ('&#8975;', '&ulcrop;'),
    '\u2336': ('&#9014;', '&topbot;'),
    '\u2026': ('&#8230;', '&mldr;'),
    '\u2736': ('&#10038;', '&sext;'),
    '\u0102': ('&#258;', '&Abreve;'),
    '\u2ac4': ('&#10948;', '&supedot;'),
    '\u224e\u0338': ('&#8782;&#824;', '&NotHumpDownHump;'),
    '\u223c\u20d2': ('&#8764;&#8402;', '&nvsim;'),
    '\u2249': ('&#8777;', '&NotTildeTilde;'),
    '\u0419': ('&#1049;', '&Jcy;'),
    '\u003e\u20d2': ('&#62;&#8402;', '&nvgt;'),
    '\u2acb\ufe00': ('&#10955;&#65024;', '&vsubnE;'),
    '\u200f': ('&#8207;', '&rlm;'),
    '\u2555': ('&#9557;', '&boxdL;'),
    '\u210c': ('&#8460;', '&Poincareplane;'),
    '\u2057': ('&#8279;', '&qprime;'),
    '\u2aeb': ('&#10987;', '&Vbar;'),
    '\u2552': ('&#9554;', '&boxdR;'),
    '\u2a15': ('&#10773;', '&pointint;'),
    '\u03a5': ('&#933;', '&Upsilon;'),
    '\u23b1': ('&#9137;', '&rmoustache;'),
    '\u2113': ('&#8467;', '&ell;'),
    '\u0105': ('&#261;', '&aogon;'),
    '\u2a9d': ('&#10909;', '&siml;'),
    '\u2213': ('&#8723;', '&mp;'),
    '\u2a50': ('&#10832;', '&ccupssm;'),
    '\u211d': ('&#8477;', '&Ropf;'),
    '\u2116': ('&#8470;', '&numero;'),
    '\ud835\udcab': ('&#119979;', '&Pscr;'),
    '\u2148': ('&#8520;', '&ImaginaryI;'),
    '\U0001d566': ('&uopf;'),
    '\u25cb': ('&#9675;', '&cir;'),
    '\u0445': ('&#1093;', '&khcy;'),
    '\u21a1': ('&#8609;', '&Darr;'),
    '\u22d3': ('&#8915;', '&Cup;'),
    '\u0391': ('&#913;', '&Alpha;'),
    '\u0458': ('&#1112;', '&jsercy;'),
    '\u011f': ('&#287;', '&gbreve;'),
    '\u20ac': ('&#8364;', '&euro;'),
    '\ud835\udd69': ('&#120169;'),
    '\u2a90': ('&#10896;', '&gsiml;'),
    '\u2933\u0338': ('&#10547;&#824;', '&nrarrc;'),
    '\u2a94': ('&#10900;', '&gesles;'),
    '\u223e': ('&#8766;', '&mstpos;'),
    '\u22db\ufe00': ('&#8923;&#65024;', '&gesl;'),
    '\u2271': ('&#8817;', '&NotGreaterEqual;'),
    '\u0057': ('&#87;'),
    '\u017a': ('&#378;', '&zacute;'),
    '\u21a4': ('&#8612;', '&mapstoleft;'),
    '\u0055': ('&#85;'),
    '\u21ca': ('&#8650;', '&downdownarrows;'),
    '\ud835\udd26': ('&#120102;'),
    '\u21b0': ('&#8624;', '&lsh;'),
    '\ud835\udd25': ('&#120101;'),
    '\ud835\udc9e': ('&#119966;', '&Cscr;'),
    '\u21cc': ('&#8652;', '&rlhar;'),
    '\U0001d52e': ('&qfr;'),
    '\ud835\udd5d': ('&#120157;'),
    '\u2030': ('&#8240;', '&permil;'),
    '\u2a72': ('&#10866;', '&pluse;'),
    '\u0406': ('&#1030;', '&Iukcy;'),
    '\u2665': ('&#9829;', '&heartsuit;'),
    '\u006c': ('&#108;'),
    '\u25fc': ('&#9724;', '&FilledSmallSquare;'),
    '\u2199': ('&#8601;', '&swarrow;'),
    '\u21d3': ('&#8659;', '&Downarrow;'),
    '\u0051': ('&#81;'),
    '\u232d': ('&#9005;', '&cylcty;'),
    '\u02da': ('&#730;', '&ring;'),
    '\u21e5': ('&#8677;', '&RightArrowBar;'),
    '\u2a4d': ('&#10829;', '&ccaps;'),
    '\u21c1': ('&#8641;', '&rightharpoondown;'),
    '\u252c': ('&#9516;', '&boxhd;'),
    '\u228f\u0338': ('&#8847;&#824;', '&NotSquareSubset;'),
    '\ud835\udd05': ('&#120069;'),
    '\u0064': ('&#100;'),
    '\U0001d508': ('&Efr;'),
    '\u2009': ('&#8201;', '&ThinSpace;'),
    '\u00ff': ('&#255;', '&yuml;'),
    '\u00b1': ('&plusmn;', '&#177;', '&pm;'),
    '\u044c': ('&#1100;', '&softcy;'),
    '\u00e0': ('&#224;', '&agrave;'),
    '\u0034': ('&#52;'),
    '\ud835\udca5': ('&#119973;'),
    '\u266a': ('&#9834;', '&sung;'),
    '\u23b0': ('&#9136;', '&lmoustache;'),
    '\u0420': ('&#1056;', '&Rcy;'),
    '\u0397': ('&#919;', '&Eta;'),
    '\u0025': ('&#37;', '&percnt;', '&percent;'),
    '\U0001d54a': ('&Sopf;'),
    '\u22b8': ('&#8888;', '&mumap;'),
    '\u0167': ('&#359;', '&tstrok;'),
    '\u22fd': ('&#8957;', '&notnivc;'),
    '\u21b3': ('&#8627;', '&rdsh;'),
    '\u2293\ufe00': ('&#8851;&#65024;', '&sqcaps;'),
    '\u225c': ('&#8796;', '&trie;'),
    '\u011e': ('&#286;', '&Gbreve;'),
    '\u219e': ('&#8606;', '&twoheadleftarrow;'),
    '\u0074': ('&#116;'),
    '\ud835\udcb1': ('&#119985;', '&Vscr;'),
    '\u0431': ('&#1073;', '&bcy;'),
    '\u2194': ('&#8596;', '&leftrightarrow;'),
    '\u22a4': ('&#8868;', '&top;'),
    '\U0001d526': ('&ifr;'),
    '\u22ab': ('&#8875;', '&VDash;'),
    '\u233d': ('&#9021;', '&ovbar;'),
    '\u22c8': ('&#8904;', '&bowtie;'),
    '\u22ae': ('&#8878;', '&nVdash;'),
    '\ud835\udd2f': ('&#120111;'),
    '\u016c': ('&#364;', '&Ubreve;'),
    '\u25aa': ('&#9642;', '&squf;'),
    '\u2129': ('&#8489;', '&iiota;'),
    '\U0001d525': ('&hfr;'),
    '\ud835\udd41': ('&#120129;'),
    '\ud835\udd2a': ('&#120106;'),
    '\u2aa6': ('&#10918;', '&ltcc;'),
    '\u2a11': ('&#10769;', '&awint;'),
    '\u0426': ('&#1062;', '&TScy;'),
    '\u00c1': ('&#193;', '&Aacute;'),
    '\u00c0': ('&#192;', '&Agrave;'),
    '\u2562': ('&#9570;', '&boxVl;'),
    '\u2ae8': ('&#10984;', '&vBar;'),
    '\ud835\udd1b': ('&#120091;', '&Xfr;'),
    '\u0144': ('&#324;', '&nacute;'),
    '\u03c2': ('&#962;', '&varsigma;'),
    '\u040a': ('&#1034;', '&NJcy;'),
    '\U0001d550': ('&Yopf;'),
    '\u2927': ('&#10535;', '&nwnear;'),
    '\u22f1': ('&#8945;', '&dtdot;'),
    '\ud835\udd67': ('&#120167;'),
    '\u21b1': ('&#8625;', '&rsh;'),
    '\ud835\udd39': ('&#120121;', '&Bopf;'),
    '\u22e7': ('&#8935;', '&gnsim;'),
    '\U0001d528': ('&kfr;'),
    '\ud835\udd0e': ('&#120078;'),
    '\u2a35': ('&#10805;', '&rotimes;'),
    '\u21a6': ('&#8614;', '&RightTeeArrow;'),
    '\u03f5': ('&#1013;', '&varepsilon;'),
    '\u2a9a': ('&#10906;', '&eg;'),
    '\u200a': ('&#8202;', '&VeryThinSpace;'),
    '\u2502': ('&#9474;', '&boxv;'),
    '\u2a4b': ('&#10827;', '&capcap;'),
    '\u0311': ('&#785;', '&DownBreve;'),
    '\u2217': ('&#8727;', '&lowast;'),
    '\ud835\udd22': ('&#120098;'),
    '\u22ef': ('&#8943;', '&ctdot;'),
    '\u21f5': ('&#8693;', '&duarr;'),
    '\u2937': ('&#10551;', '&rdca;'),
    '\U0001d55d': ('&lopf;'),
    '\u00fc': ('&#252;', '&uuml;'),
    '\u00d2': ('&#210;', '&Ograve;'),
    '\u2018': ('&#8216;', '&OpenCurlyQuote;'),
    '\u295c': ('&#10588;', '&RightUpTeeVector;'),
    '\u0033': ('&#51;'),
    '\u2241': ('&#8769;', '&nsim;'),
    '\u2aba': ('&#10938;', '&succnapprox;'),
    '\u0054': ('&#84;'),
    '\u044f': ('&#1103;', '&yacy;'),
    '\u00bc': ('&#188;', '&frac14;'),
    '\u03dc': ('&#988;', '&Gammad;'),
    '\u0059': ('&#89;'),
    '\u2a30': ('&#10800;', '&timesd;'),
    '\u00da': ('&#218;', '&Uacute;'),
    '\ud835\udd4e': ('&#120142;', '&Wopf;'),
    '\u0042': ('&#66;'),
    '\ud835\udd59': ('&#120153;', '&hopf;'),
    '\u2147': ('&#8519;', '&exponentiale;'),
    '\u2660': ('&#9824;', '&spadesuit;'),
    '\u230c': ('&#8972;', '&drcrop;'),
    '\ufb00': ('&#64256;', '&fflig;'),
    '\u2561': ('&#9569;', '&boxvL;'),
    '\u2a92': ('&#10898;', '&glE;'),
    '\u00f7': ('&#247;', '&divide;'),
    '\u27f5': ('&#10229;', '&xlarr;'),
    '\u045f': ('&#1119;', '&dzcy;'),
    '\u230b': ('&#8971;', '&RightFloor;'),
    '\u29d0\u0338': ('&#10704;&#824;', '&NotRightTriangleBar;'),
    '\u2ad3': ('&#10963;', '&subsup;'),
    '\u21bb': ('&#8635;', '&orarr;'),
    '\u2994': ('&#10644;', '&rpargt;'),
    '\u2aa9': ('&#10921;', '&gescc;'),
    '\u003a': ('&#58;', '&colon;'),
    '\u00fb': ('&#251;', '&ucirc;'),
    '\u266d': ('&#9837;', '&flat;'),
    '\u27f9': ('&#10233;', '&xrArr;'),
    '\u02c6': ('&#710;', '&circ;'),
    '\u2031': ('&#8241;', '&pertenk;'),
    '\u0394': ('&#916;', '&Delta;'),
    '\u00ed': ('&#237;', '&iacute;')
}


HTML5_REF = {
    'Aacute': '\xc1',
    'aacute': '\xe1',
    'Aacute;': '\xc1',
    'aacute;': '\xe1',
    'Abreve;': '\u0102',
    'abreve;': '\u0103',
    'ac;': '\u223e',
    'acd;': '\u223f',
    'acE;': '\u223e\u0333',
    'Acirc': '\xc2',
    'acirc': '\xe2',
    'Acirc;': '\xc2',
    'acirc;': '\xe2',
    'acute': '\xb4',
    'acute;': '\xb4',
    'Acy;': '\u0410',
    'acy;': '\u0430',
    'AElig': '\xc6',
    'aelig': '\xe6',
    'AElig;': '\xc6',
    'aelig;': '\xe6',
    'af;': '\u2061',
    'Afr;': '\U0001d504',
    'afr;': '\U0001d51e',
    'Agrave': '\xc0',
    'agrave': '\xe0',
    'Agrave;': '\xc0',
    'agrave;': '\xe0',
    'alefsym;': '\u2135',
    'aleph;': '\u2135',
    'Alpha;': '\u0391',
    'alpha;': '\u03b1',
    'Amacr;': '\u0100',
    'amacr;': '\u0101',
    'amalg;': '\u2a3f',
    'AMP': '&',
    'amp': '&',
    'AMP;': '&',
    'amp;': '&',
    'And;': '\u2a53',
    'and;': '\u2227',
    'andand;': '\u2a55',
    'andd;': '\u2a5c',
    'andslope;': '\u2a58',
    'andv;': '\u2a5a',
    'ang;': '\u2220',
    'ange;': '\u29a4',
    'angle;': '\u2220',
    'angmsd;': '\u2221',
    'angmsdaa;': '\u29a8',
    'angmsdab;': '\u29a9',
    'angmsdac;': '\u29aa',
    'angmsdad;': '\u29ab',
    'angmsdae;': '\u29ac',
    'angmsdaf;': '\u29ad',
    'angmsdag;': '\u29ae',
    'angmsdah;': '\u29af',
    'angrt;': '\u221f',
    'angrtvb;': '\u22be',
    'angrtvbd;': '\u299d',
    'angsph;': '\u2222',
    'angst;': '\xc5',
    'angzarr;': '\u237c',
    'Aogon;': '\u0104',
    'aogon;': '\u0105',
    'Aopf;': '\U0001d538',
    'aopf;': '\U0001d552',
    'ap;': '\u2248',
    'apacir;': '\u2a6f',
    'apE;': '\u2a70',
    'ape;': '\u224a',
    'apid;': '\u224b',
    'apos;': "'",
    'ApplyFunction;': '\u2061',
    'approx;': '\u2248',
    'approxeq;': '\u224a',
    'Aring': '\xc5',
    'aring': '\xe5',
    'Aring;': '\xc5',
    'aring;': '\xe5',
    'Ascr;': '\U0001d49c',
    'ascr;': '\U0001d4b6',
    'Assign;': '\u2254',
    'ast;': '*',
    'asymp;': '\u2248',
    'asympeq;': '\u224d',
    'Atilde': '\xc3',
    'atilde': '\xe3',
    'Atilde;': '\xc3',
    'atilde;': '\xe3',
    'Auml': '\xc4',
    'auml': '\xe4',
    'Auml;': '\xc4',
    'auml;': '\xe4',
    'awconint;': '\u2233',
    'awint;': '\u2a11',
    'backcong;': '\u224c',
    'backepsilon;': '\u03f6',
    'backprime;': '\u2035',
    'backsim;': '\u223d',
    'backsimeq;': '\u22cd',
    'Backslash;': '\u2216',
    'Barv;': '\u2ae7',
    'barvee;': '\u22bd',
    'Barwed;': '\u2306',
    'barwed;': '\u2305',
    'barwedge;': '\u2305',
    'bbrk;': '\u23b5',
    'bbrktbrk;': '\u23b6',
    'bcong;': '\u224c',
    'Bcy;': '\u0411',
    'bcy;': '\u0431',
    'bdquo;': '\u201e',
    'becaus;': '\u2235',
    'Because;': '\u2235',
    'because;': '\u2235',
    'bemptyv;': '\u29b0',
    'bepsi;': '\u03f6',
    'bernou;': '\u212c',
    'Bernoullis;': '\u212c',
    'Beta;': '\u0392',
    'beta;': '\u03b2',
    'beth;': '\u2136',
    'between;': '\u226c',
    'Bfr;': '\U0001d505',
    'bfr;': '\U0001d51f',
    'bigcap;': '\u22c2',
    'bigcirc;': '\u25ef',
    'bigcup;': '\u22c3',
    'bigodot;': '\u2a00',
    'bigoplus;': '\u2a01',
    'bigotimes;': '\u2a02',
    'bigsqcup;': '\u2a06',
    'bigstar;': '\u2605',
    'bigtriangledown;': '\u25bd',
    'bigtriangleup;': '\u25b3',
    'biguplus;': '\u2a04',
    'bigvee;': '\u22c1',
    'bigwedge;': '\u22c0',
    'bkarow;': '\u290d',
    'blacklozenge;': '\u29eb',
    'blacksquare;': '\u25aa',
    'blacktriangle;': '\u25b4',
    'blacktriangledown;': '\u25be',
    'blacktriangleleft;': '\u25c2',
    'blacktriangleright;': '\u25b8',
    'blank;': '\u2423',
    'blk12;': '\u2592',
    'blk14;': '\u2591',
    'blk34;': '\u2593',
    'block;': '\u2588',
    'bne;': '=\u20e5',
    'bnequiv;': '\u2261\u20e5',
    'bNot;': '\u2aed',
    'bnot;': '\u2310',
    'Bopf;': '\U0001d539',
    'bopf;': '\U0001d553',
    'bot;': '\u22a5',
    'bottom;': '\u22a5',
    'bowtie;': '\u22c8',
    'boxbox;': '\u29c9',
    'boxDL;': '\u2557',
    'boxDl;': '\u2556',
    'boxdL;': '\u2555',
    'boxdl;': '\u2510',
    'boxDR;': '\u2554',
    'boxDr;': '\u2553',
    'boxdR;': '\u2552',
    'boxdr;': '\u250c',
    'boxH;': '\u2550',
    'boxh;': '\u2500',
    'boxHD;': '\u2566',
    'boxHd;': '\u2564',
    'boxhD;': '\u2565',
    'boxhd;': '\u252c',
    'boxHU;': '\u2569',
    'boxHu;': '\u2567',
    'boxhU;': '\u2568',
    'boxhu;': '\u2534',
    'boxminus;': '\u229f',
    'boxplus;': '\u229e',
    'boxtimes;': '\u22a0',
    'boxUL;': '\u255d',
    'boxUl;': '\u255c',
    'boxuL;': '\u255b',
    'boxul;': '\u2518',
    'boxUR;': '\u255a',
    'boxUr;': '\u2559',
    'boxuR;': '\u2558',
    'boxur;': '\u2514',
    'boxV;': '\u2551',
    'boxv;': '\u2502',
    'boxVH;': '\u256c',
    'boxVh;': '\u256b',
    'boxvH;': '\u256a',
    'boxvh;': '\u253c',
    'boxVL;': '\u2563',
    'boxVl;': '\u2562',
    'boxvL;': '\u2561',
    'boxvl;': '\u2524',
    'boxVR;': '\u2560',
    'boxVr;': '\u255f',
    'boxvR;': '\u255e',
    'boxvr;': '\u251c',
    'bprime;': '\u2035',
    'Breve;': '\u02d8',
    'breve;': '\u02d8',
    'brvbar': '\xa6',
    'brvbar;': '\xa6',
    'Bscr;': '\u212c',
    'bscr;': '\U0001d4b7',
    'bsemi;': '\u204f',
    'bsim;': '\u223d',
    'bsime;': '\u22cd',
    'bsol;': '\\',
    'bsolb;': '\u29c5',
    'bsolhsub;': '\u27c8',
    'bull;': '\u2022',
    'bullet;': '\u2022',
    'bump;': '\u224e',
    'bumpE;': '\u2aae',
    'bumpe;': '\u224f',
    'Bumpeq;': '\u224e',
    'bumpeq;': '\u224f',
    'Cacute;': '\u0106',
    'cacute;': '\u0107',
    'Cap;': '\u22d2',
    'cap;': '\u2229',
    'capand;': '\u2a44',
    'capbrcup;': '\u2a49',
    'capcap;': '\u2a4b',
    'capcup;': '\u2a47',
    'capdot;': '\u2a40',
    'CapitalDifferentialD;': '\u2145',
    'caps;': '\u2229\ufe00',
    'caret;': '\u2041',
    'caron;': '\u02c7',
    'Cayleys;': '\u212d',
    'ccaps;': '\u2a4d',
    'Ccaron;': '\u010c',
    'ccaron;': '\u010d',
    'Ccedil': '\xc7',
    'ccedil': '\xe7',
    'Ccedil;': '\xc7',
    'ccedil;': '\xe7',
    'Ccirc;': '\u0108',
    'ccirc;': '\u0109',
    'Cconint;': '\u2230',
    'ccups;': '\u2a4c',
    'ccupssm;': '\u2a50',
    'Cdot;': '\u010a',
    'cdot;': '\u010b',
    'cedil': '\xb8',
    'cedil;': '\xb8',
    'Cedilla;': '\xb8',
    'cemptyv;': '\u29b2',
    'cent': '\xa2',
    'cent;': '\xa2',
    'CenterDot;': '\xb7',
    'centerdot;': '\xb7',
    'Cfr;': '\u212d',
    'cfr;': '\U0001d520',
    'CHcy;': '\u0427',
    'chcy;': '\u0447',
    'check;': '\u2713',
    'checkmark;': '\u2713',
    'Chi;': '\u03a7',
    'chi;': '\u03c7',
    'cir;': '\u25cb',
    'circ;': '\u02c6',
    'circeq;': '\u2257',
    'circlearrowleft;': '\u21ba',
    'circlearrowright;': '\u21bb',
    'circledast;': '\u229b',
    'circledcirc;': '\u229a',
    'circleddash;': '\u229d',
    'CircleDot;': '\u2299',
    'circledR;': '\xae',
    'circledS;': '\u24c8',
    'CircleMinus;': '\u2296',
    'CirclePlus;': '\u2295',
    'CircleTimes;': '\u2297',
    'cirE;': '\u29c3',
    'cire;': '\u2257',
    'cirfnint;': '\u2a10',
    'cirmid;': '\u2aef',
    'cirscir;': '\u29c2',
    'ClockwiseContourIntegral;': '\u2232',
    'CloseCurlyDoubleQuote;': '\u201d',
    'CloseCurlyQuote;': '\u2019',
    'clubs;': '\u2663',
    'clubsuit;': '\u2663',
    'Colon;': '\u2237',
    'colon;': ':',
    'Colone;': '\u2a74',
    'colone;': '\u2254',
    'coloneq;': '\u2254',
    'comma;': ',',
    'commat;': '@',
    'comp;': '\u2201',
    'compfn;': '\u2218',
    'complement;': '\u2201',
    'complexes;': '\u2102',
    'cong;': '\u2245',
    'congdot;': '\u2a6d',
    'Congruent;': '\u2261',
    'Conint;': '\u222f',
    'conint;': '\u222e',
    'ContourIntegral;': '\u222e',
    'Copf;': '\u2102',
    'copf;': '\U0001d554',
    'coprod;': '\u2210',
    'Coproduct;': '\u2210',
    'COPY': '\xa9',
    'copy': '\xa9',
    'COPY;': '\xa9',
    'copy;': '\xa9',
    'copysr;': '\u2117',
    'CounterClockwiseContourIntegral;': '\u2233',
    'crarr;': '\u21b5',
    'Cross;': '\u2a2f',
    'cross;': '\u2717',
    'Cscr;': '\U0001d49e',
    'cscr;': '\U0001d4b8',
    'csub;': '\u2acf',
    'csube;': '\u2ad1',
    'csup;': '\u2ad0',
    'csupe;': '\u2ad2',
    'ctdot;': '\u22ef',
    'cudarrl;': '\u2938',
    'cudarrr;': '\u2935',
    'cuepr;': '\u22de',
    'cuesc;': '\u22df',
    'cularr;': '\u21b6',
    'cularrp;': '\u293d',
    'Cup;': '\u22d3',
    'cup;': '\u222a',
    'cupbrcap;': '\u2a48',
    'CupCap;': '\u224d',
    'cupcap;': '\u2a46',
    'cupcup;': '\u2a4a',
    'cupdot;': '\u228d',
    'cupor;': '\u2a45',
    'cups;': '\u222a\ufe00',
    'curarr;': '\u21b7',
    'curarrm;': '\u293c',
    'curlyeqprec;': '\u22de',
    'curlyeqsucc;': '\u22df',
    'curlyvee;': '\u22ce',
    'curlywedge;': '\u22cf',
    'curren': '\xa4',
    'curren;': '\xa4',
    'curvearrowleft;': '\u21b6',
    'curvearrowright;': '\u21b7',
    'cuvee;': '\u22ce',
    'cuwed;': '\u22cf',
    'cwconint;': '\u2232',
    'cwint;': '\u2231',
    'cylcty;': '\u232d',
    'Dagger;': '\u2021',
    'dagger;': '\u2020',
    'daleth;': '\u2138',
    'Darr;': '\u21a1',
    'dArr;': '\u21d3',
    'darr;': '\u2193',
    'dash;': '\u2010',
    'Dashv;': '\u2ae4',
    'dashv;': '\u22a3',
    'dbkarow;': '\u290f',
    'dblac;': '\u02dd',
    'Dcaron;': '\u010e',
    'dcaron;': '\u010f',
    'Dcy;': '\u0414',
    'dcy;': '\u0434',
    'DD;': '\u2145',
    'dd;': '\u2146',
    'ddagger;': '\u2021',
    'ddarr;': '\u21ca',
    'DDotrahd;': '\u2911',
    'ddotseq;': '\u2a77',
    'deg': '\xb0',
    'deg;': '\xb0',
    'Del;': '\u2207',
    'Delta;': '\u0394',
    'delta;': '\u03b4',
    'demptyv;': '\u29b1',
    'dfisht;': '\u297f',
    'Dfr;': '\U0001d507',
    'dfr;': '\U0001d521',
    'dHar;': '\u2965',
    'dharl;': '\u21c3',
    'dharr;': '\u21c2',
    'DiacriticalAcute;': '\xb4',
    'DiacriticalDot;': '\u02d9',
    'DiacriticalDoubleAcute;': '\u02dd',
    'DiacriticalGrave;': '`',
    'DiacriticalTilde;': '\u02dc',
    'diam;': '\u22c4',
    'Diamond;': '\u22c4',
    'diamond;': '\u22c4',
    'diamondsuit;': '\u2666',
    'diams;': '\u2666',
    'die;': '\xa8',
    'DifferentialD;': '\u2146',
    'digamma;': '\u03dd',
    'disin;': '\u22f2',
    'div;': '\xf7',
    'divide': '\xf7',
    'divide;': '\xf7',
    'divideontimes;': '\u22c7',
    'divonx;': '\u22c7',
    'DJcy;': '\u0402',
    'djcy;': '\u0452',
    'dlcorn;': '\u231e',
    'dlcrop;': '\u230d',
    'dollar;': '$',
    'Dopf;': '\U0001d53b',
    'dopf;': '\U0001d555',
    'Dot;': '\xa8',
    'dot;': '\u02d9',
    'DotDot;': '\u20dc',
    'doteq;': '\u2250',
    'doteqdot;': '\u2251',
    'DotEqual;': '\u2250',
    'dotminus;': '\u2238',
    'dotplus;': '\u2214',
    'dotsquare;': '\u22a1',
    'doublebarwedge;': '\u2306',
    'DoubleContourIntegral;': '\u222f',
    'DoubleDot;': '\xa8',
    'DoubleDownArrow;': '\u21d3',
    'DoubleLeftArrow;': '\u21d0',
    'DoubleLeftRightArrow;': '\u21d4',
    'DoubleLeftTee;': '\u2ae4',
    'DoubleLongLeftArrow;': '\u27f8',
    'DoubleLongLeftRightArrow;': '\u27fa',
    'DoubleLongRightArrow;': '\u27f9',
    'DoubleRightArrow;': '\u21d2',
    'DoubleRightTee;': '\u22a8',
    'DoubleUpArrow;': '\u21d1',
    'DoubleUpDownArrow;': '\u21d5',
    'DoubleVerticalBar;': '\u2225',
    'DownArrow;': '\u2193',
    'Downarrow;': '\u21d3',
    'downarrow;': '\u2193',
    'DownArrowBar;': '\u2913',
    'DownArrowUpArrow;': '\u21f5',
    'DownBreve;': '\u0311',
    'downdownarrows;': '\u21ca',
    'downharpoonleft;': '\u21c3',
    'downharpoonright;': '\u21c2',
    'DownLeftRightVector;': '\u2950',
    'DownLeftTeeVector;': '\u295e',
    'DownLeftVector;': '\u21bd',
    'DownLeftVectorBar;': '\u2956',
    'DownRightTeeVector;': '\u295f',
    'DownRightVector;': '\u21c1',
    'DownRightVectorBar;': '\u2957',
    'DownTee;': '\u22a4',
    'DownTeeArrow;': '\u21a7',
    'drbkarow;': '\u2910',
    'drcorn;': '\u231f',
    'drcrop;': '\u230c',
    'Dscr;': '\U0001d49f',
    'dscr;': '\U0001d4b9',
    'DScy;': '\u0405',
    'dscy;': '\u0455',
    'dsol;': '\u29f6',
    'Dstrok;': '\u0110',
    'dstrok;': '\u0111',
    'dtdot;': '\u22f1',
    'dtri;': '\u25bf',
    'dtrif;': '\u25be',
    'duarr;': '\u21f5',
    'duhar;': '\u296f',
    'dwangle;': '\u29a6',
    'DZcy;': '\u040f',
    'dzcy;': '\u045f',
    'dzigrarr;': '\u27ff',
    'Eacute': '\xc9',
    'eacute': '\xe9',
    'Eacute;': '\xc9',
    'eacute;': '\xe9',
    'easter;': '\u2a6e',
    'Ecaron;': '\u011a',
    'ecaron;': '\u011b',
    'ecir;': '\u2256',
    'Ecirc': '\xca',
    'ecirc': '\xea',
    'Ecirc;': '\xca',
    'ecirc;': '\xea',
    'ecolon;': '\u2255',
    'Ecy;': '\u042d',
    'ecy;': '\u044d',
    'eDDot;': '\u2a77',
    'Edot;': '\u0116',
    'eDot;': '\u2251',
    'edot;': '\u0117',
    'ee;': '\u2147',
    'efDot;': '\u2252',
    'Efr;': '\U0001d508',
    'efr;': '\U0001d522',
    'eg;': '\u2a9a',
    'Egrave': '\xc8',
    'egrave': '\xe8',
    'Egrave;': '\xc8',
    'egrave;': '\xe8',
    'egs;': '\u2a96',
    'egsdot;': '\u2a98',
    'el;': '\u2a99',
    'Element;': '\u2208',
    'elinters;': '\u23e7',
    'ell;': '\u2113',
    'els;': '\u2a95',
    'elsdot;': '\u2a97',
    'Emacr;': '\u0112',
    'emacr;': '\u0113',
    'empty;': '\u2205',
    'emptyset;': '\u2205',
    'EmptySmallSquare;': '\u25fb',
    'emptyv;': '\u2205',
    'EmptyVerySmallSquare;': '\u25ab',
    'emsp13;': '\u2004',
    'emsp14;': '\u2005',
    'emsp;': '\u2003',
    'ENG;': '\u014a',
    'eng;': '\u014b',
    'ensp;': '\u2002',
    'Eogon;': '\u0118',
    'eogon;': '\u0119',
    'Eopf;': '\U0001d53c',
    'eopf;': '\U0001d556',
    'epar;': '\u22d5',
    'eparsl;': '\u29e3',
    'eplus;': '\u2a71',
    'epsi;': '\u03b5',
    'Epsilon;': '\u0395',
    'epsilon;': '\u03b5',
    'epsiv;': '\u03f5',
    'eqcirc;': '\u2256',
    'eqcolon;': '\u2255',
    'eqsim;': '\u2242',
    'eqslantgtr;': '\u2a96',
    'eqslantless;': '\u2a95',
    'Equal;': '\u2a75',
    'equals;': '=',
    'EqualTilde;': '\u2242',
    'equest;': '\u225f',
    'Equilibrium;': '\u21cc',
    'equiv;': '\u2261',
    'equivDD;': '\u2a78',
    'eqvparsl;': '\u29e5',
    'erarr;': '\u2971',
    'erDot;': '\u2253',
    'Escr;': '\u2130',
    'escr;': '\u212f',
    'esdot;': '\u2250',
    'Esim;': '\u2a73',
    'esim;': '\u2242',
    'Eta;': '\u0397',
    'eta;': '\u03b7',
    'ETH': '\xd0',
    'eth': '\xf0',
    'ETH;': '\xd0',
    'eth;': '\xf0',
    'Euml': '\xcb',
    'euml': '\xeb',
    'Euml;': '\xcb',
    'euml;': '\xeb',
    'euro;': '\u20ac',
    'excl;': '!',
    'exist;': '\u2203',
    'Exists;': '\u2203',
    'expectation;': '\u2130',
    'ExponentialE;': '\u2147',
    'exponentiale;': '\u2147',
    'fallingdotseq;': '\u2252',
    'Fcy;': '\u0424',
    'fcy;': '\u0444',
    'female;': '\u2640',
    'ffilig;': '\ufb03',
    'fflig;': '\ufb00',
    'ffllig;': '\ufb04',
    'Ffr;': '\U0001d509',
    'ffr;': '\U0001d523',
    'filig;': '\ufb01',
    'FilledSmallSquare;': '\u25fc',
    'FilledVerySmallSquare;': '\u25aa',
    'fjlig;': 'fj',
    'flat;': '\u266d',
    'fllig;': '\ufb02',
    'fltns;': '\u25b1',
    'fnof;': '\u0192',
    'Fopf;': '\U0001d53d',
    'fopf;': '\U0001d557',
    'ForAll;': '\u2200',
    'forall;': '\u2200',
    'fork;': '\u22d4',
    'forkv;': '\u2ad9',
    'Fouriertrf;': '\u2131',
    'fpartint;': '\u2a0d',
    'frac12': '\xbd',
    'frac12;': '\xbd',
    'frac13;': '\u2153',
    'frac14': '\xbc',
    'frac14;': '\xbc',
    'frac15;': '\u2155',
    'frac16;': '\u2159',
    'frac18;': '\u215b',
    'frac23;': '\u2154',
    'frac25;': '\u2156',
    'frac34': '\xbe',
    'frac34;': '\xbe',
    'frac35;': '\u2157',
    'frac38;': '\u215c',
    'frac45;': '\u2158',
    'frac56;': '\u215a',
    'frac58;': '\u215d',
    'frac78;': '\u215e',
    'frasl;': '\u2044',
    'frown;': '\u2322',
    'Fscr;': '\u2131',
    'fscr;': '\U0001d4bb',
    'gacute;': '\u01f5',
    'Gamma;': '\u0393',
    'gamma;': '\u03b3',
    'Gammad;': '\u03dc',
    'gammad;': '\u03dd',
    'gap;': '\u2a86',
    'Gbreve;': '\u011e',
    'gbreve;': '\u011f',
    'Gcedil;': '\u0122',
    'Gcirc;': '\u011c',
    'gcirc;': '\u011d',
    'Gcy;': '\u0413',
    'gcy;': '\u0433',
    'Gdot;': '\u0120',
    'gdot;': '\u0121',
    'gE;': '\u2267',
    'ge;': '\u2265',
    'gEl;': '\u2a8c',
    'gel;': '\u22db',
    'geq;': '\u2265',
    'geqq;': '\u2267',
    'geqslant;': '\u2a7e',
    'ges;': '\u2a7e',
    'gescc;': '\u2aa9',
    'gesdot;': '\u2a80',
    'gesdoto;': '\u2a82',
    'gesdotol;': '\u2a84',
    'gesl;': '\u22db\ufe00',
    'gesles;': '\u2a94',
    'Gfr;': '\U0001d50a',
    'gfr;': '\U0001d524',
    'Gg;': '\u22d9',
    'gg;': '\u226b',
    'ggg;': '\u22d9',
    'gimel;': '\u2137',
    'GJcy;': '\u0403',
    'gjcy;': '\u0453',
    'gl;': '\u2277',
    'gla;': '\u2aa5',
    'glE;': '\u2a92',
    'glj;': '\u2aa4',
    'gnap;': '\u2a8a',
    'gnapprox;': '\u2a8a',
    'gnE;': '\u2269',
    'gne;': '\u2a88',
    'gneq;': '\u2a88',
    'gneqq;': '\u2269',
    'gnsim;': '\u22e7',
    'Gopf;': '\U0001d53e',
    'gopf;': '\U0001d558',
    'grave;': '`',
    'GreaterEqual;': '\u2265',
    'GreaterEqualLess;': '\u22db',
    'GreaterFullEqual;': '\u2267',
    'GreaterGreater;': '\u2aa2',
    'GreaterLess;': '\u2277',
    'GreaterSlantEqual;': '\u2a7e',
    'GreaterTilde;': '\u2273',
    'Gscr;': '\U0001d4a2',
    'gscr;': '\u210a',
    'gsim;': '\u2273',
    'gsime;': '\u2a8e',
    'gsiml;': '\u2a90',
    'GT': '>',
    'gt': '>',
    'GT;': '>',
    'Gt;': '\u226b',
    'gt;': '>',
    'gtcc;': '\u2aa7',
    'gtcir;': '\u2a7a',
    'gtdot;': '\u22d7',
    'gtlPar;': '\u2995',
    'gtquest;': '\u2a7c',
    'gtrapprox;': '\u2a86',
    'gtrarr;': '\u2978',
    'gtrdot;': '\u22d7',
    'gtreqless;': '\u22db',
    'gtreqqless;': '\u2a8c',
    'gtrless;': '\u2277',
    'gtrsim;': '\u2273',
    'gvertneqq;': '\u2269\ufe00',
    'gvnE;': '\u2269\ufe00',
    'Hacek;': '\u02c7',
    'hairsp;': '\u200a',
    'half;': '\xbd',
    'hamilt;': '\u210b',
    'HARDcy;': '\u042a',
    'hardcy;': '\u044a',
    'hArr;': '\u21d4',
    'harr;': '\u2194',
    'harrcir;': '\u2948',
    'harrw;': '\u21ad',
    'Hat;': '^',
    'hbar;': '\u210f',
    'Hcirc;': '\u0124',
    'hcirc;': '\u0125',
    'hearts;': '\u2665',
    'heartsuit;': '\u2665',
    'hellip;': '\u2026',
    'hercon;': '\u22b9',
    'Hfr;': '\u210c',
    'hfr;': '\U0001d525',
    'HilbertSpace;': '\u210b',
    'hksearow;': '\u2925',
    'hkswarow;': '\u2926',
    'hoarr;': '\u21ff',
    'homtht;': '\u223b',
    'hookleftarrow;': '\u21a9',
    'hookrightarrow;': '\u21aa',
    'Hopf;': '\u210d',
    'hopf;': '\U0001d559',
    'horbar;': '\u2015',
    'HorizontalLine;': '\u2500',
    'Hscr;': '\u210b',
    'hscr;': '\U0001d4bd',
    'hslash;': '\u210f',
    'Hstrok;': '\u0126',
    'hstrok;': '\u0127',
    'HumpDownHump;': '\u224e',
    'HumpEqual;': '\u224f',
    'hybull;': '\u2043',
    'hyphen;': '\u2010',
    'Iacute': '\xcd',
    'iacute': '\xed',
    'Iacute;': '\xcd',
    'iacute;': '\xed',
    'ic;': '\u2063',
    'Icirc': '\xce',
    'icirc': '\xee',
    'Icirc;': '\xce',
    'icirc;': '\xee',
    'Icy;': '\u0418',
    'icy;': '\u0438',
    'Idot;': '\u0130',
    'IEcy;': '\u0415',
    'iecy;': '\u0435',
    'iexcl': '\xa1',
    'iexcl;': '\xa1',
    'iff;': '\u21d4',
    'Ifr;': '\u2111',
    'ifr;': '\U0001d526',
    'Igrave': '\xcc',
    'igrave': '\xec',
    'Igrave;': '\xcc',
    'igrave;': '\xec',
    'ii;': '\u2148',
    'iiiint;': '\u2a0c',
    'iiint;': '\u222d',
    'iinfin;': '\u29dc',
    'iiota;': '\u2129',
    'IJlig;': '\u0132',
    'ijlig;': '\u0133',
    'Im;': '\u2111',
    'Imacr;': '\u012a',
    'imacr;': '\u012b',
    'image;': '\u2111',
    'ImaginaryI;': '\u2148',
    'imagline;': '\u2110',
    'imagpart;': '\u2111',
    'imath;': '\u0131',
    'imof;': '\u22b7',
    'imped;': '\u01b5',
    'Implies;': '\u21d2',
    'in;': '\u2208',
    'incare;': '\u2105',
    'infin;': '\u221e',
    'infintie;': '\u29dd',
    'inodot;': '\u0131',
    'Int;': '\u222c',
    'int;': '\u222b',
    'intcal;': '\u22ba',
    'integers;': '\u2124',
    'Integral;': '\u222b',
    'intercal;': '\u22ba',
    'Intersection;': '\u22c2',
    'intlarhk;': '\u2a17',
    'intprod;': '\u2a3c',
    'InvisibleComma;': '\u2063',
    'InvisibleTimes;': '\u2062',
    'IOcy;': '\u0401',
    'iocy;': '\u0451',
    'Iogon;': '\u012e',
    'iogon;': '\u012f',
    'Iopf;': '\U0001d540',
    'iopf;': '\U0001d55a',
    'Iota;': '\u0399',
    'iota;': '\u03b9',
    'iprod;': '\u2a3c',
    'iquest': '\xbf',
    'iquest;': '\xbf',
    'Iscr;': '\u2110',
    'iscr;': '\U0001d4be',
    'isin;': '\u2208',
    'isindot;': '\u22f5',
    'isinE;': '\u22f9',
    'isins;': '\u22f4',
    'isinsv;': '\u22f3',
    'isinv;': '\u2208',
    'it;': '\u2062',
    'Itilde;': '\u0128',
    'itilde;': '\u0129',
    'Iukcy;': '\u0406',
    'iukcy;': '\u0456',
    'Iuml': '\xcf',
    'iuml': '\xef',
    'Iuml;': '\xcf',
    'iuml;': '\xef',
    'Jcirc;': '\u0134',
    'jcirc;': '\u0135',
    'Jcy;': '\u0419',
    'jcy;': '\u0439',
    'Jfr;': '\U0001d50d',
    'jfr;': '\U0001d527',
    'jmath;': '\u0237',
    'Jopf;': '\U0001d541',
    'jopf;': '\U0001d55b',
    'Jscr;': '\U0001d4a5',
    'jscr;': '\U0001d4bf',
    'Jsercy;': '\u0408',
    'jsercy;': '\u0458',
    'Jukcy;': '\u0404',
    'jukcy;': '\u0454',
    'Kappa;': '\u039a',
    'kappa;': '\u03ba',
    'kappav;': '\u03f0',
    'Kcedil;': '\u0136',
    'kcedil;': '\u0137',
    'Kcy;': '\u041a',
    'kcy;': '\u043a',
    'Kfr;': '\U0001d50e',
    'kfr;': '\U0001d528',
    'kgreen;': '\u0138',
    'KHcy;': '\u0425',
    'khcy;': '\u0445',
    'KJcy;': '\u040c',
    'kjcy;': '\u045c',
    'Kopf;': '\U0001d542',
    'kopf;': '\U0001d55c',
    'Kscr;': '\U0001d4a6',
    'kscr;': '\U0001d4c0',
    'lAarr;': '\u21da',
    'Lacute;': '\u0139',
    'lacute;': '\u013a',
    'laemptyv;': '\u29b4',
    'lagran;': '\u2112',
    'Lambda;': '\u039b',
    'lambda;': '\u03bb',
    'Lang;': '\u27ea',
    'lang;': '\u27e8',
    'langd;': '\u2991',
    'langle;': '\u27e8',
    'lap;': '\u2a85',
    'Laplacetrf;': '\u2112',
    'laquo': '\xab',
    'laquo;': '\xab',
    'Larr;': '\u219e',
    'lArr;': '\u21d0',
    'larr;': '\u2190',
    'larrb;': '\u21e4',
    'larrbfs;': '\u291f',
    'larrfs;': '\u291d',
    'larrhk;': '\u21a9',
    'larrlp;': '\u21ab',
    'larrpl;': '\u2939',
    'larrsim;': '\u2973',
    'larrtl;': '\u21a2',
    'lat;': '\u2aab',
    'lAtail;': '\u291b',
    'latail;': '\u2919',
    'late;': '\u2aad',
    'lates;': '\u2aad\ufe00',
    'lBarr;': '\u290e',
    'lbarr;': '\u290c',
    'lbbrk;': '\u2772',
    'lbrace;': '{',
    'lbrack;': '[',
    'lbrke;': '\u298b',
    'lbrksld;': '\u298f',
    'lbrkslu;': '\u298d',
    'Lcaron;': '\u013d',
    'lcaron;': '\u013e',
    'Lcedil;': '\u013b',
    'lcedil;': '\u013c',
    'lceil;': '\u2308',
    'lcub;': '{',
    'Lcy;': '\u041b',
    'lcy;': '\u043b',
    'ldca;': '\u2936',
    'ldquo;': '\u201c',
    'ldquor;': '\u201e',
    'ldrdhar;': '\u2967',
    'ldrushar;': '\u294b',
    'ldsh;': '\u21b2',
    'lE;': '\u2266',
    'le;': '\u2264',
    'LeftAngleBracket;': '\u27e8',
    'LeftArrow;': '\u2190',
    'Leftarrow;': '\u21d0',
    'leftarrow;': '\u2190',
    'LeftArrowBar;': '\u21e4',
    'LeftArrowRightArrow;': '\u21c6',
    'leftarrowtail;': '\u21a2',
    'LeftCeiling;': '\u2308',
    'LeftDoubleBracket;': '\u27e6',
    'LeftDownTeeVector;': '\u2961',
    'LeftDownVector;': '\u21c3',
    'LeftDownVectorBar;': '\u2959',
    'LeftFloor;': '\u230a',
    'leftharpoondown;': '\u21bd',
    'leftharpoonup;': '\u21bc',
    'leftleftarrows;': '\u21c7',
    'LeftRightArrow;': '\u2194',
    'Leftrightarrow;': '\u21d4',
    'leftrightarrow;': '\u2194',
    'leftrightarrows;': '\u21c6',
    'leftrightharpoons;': '\u21cb',
    'leftrightsquigarrow;': '\u21ad',
    'LeftRightVector;': '\u294e',
    'LeftTee;': '\u22a3',
    'LeftTeeArrow;': '\u21a4',
    'LeftTeeVector;': '\u295a',
    'leftthreetimes;': '\u22cb',
    'LeftTriangle;': '\u22b2',
    'LeftTriangleBar;': '\u29cf',
    'LeftTriangleEqual;': '\u22b4',
    'LeftUpDownVector;': '\u2951',
    'LeftUpTeeVector;': '\u2960',
    'LeftUpVector;': '\u21bf',
    'LeftUpVectorBar;': '\u2958',
    'LeftVector;': '\u21bc',
    'LeftVectorBar;': '\u2952',
    'lEg;': '\u2a8b',
    'leg;': '\u22da',
    'leq;': '\u2264',
    'leqq;': '\u2266',
    'leqslant;': '\u2a7d',
    'les;': '\u2a7d',
    'lescc;': '\u2aa8',
    'lesdot;': '\u2a7f',
    'lesdoto;': '\u2a81',
    'lesdotor;': '\u2a83',
    'lesg;': '\u22da\ufe00',
    'lesges;': '\u2a93',
    'lessapprox;': '\u2a85',
    'lessdot;': '\u22d6',
    'lesseqgtr;': '\u22da',
    'lesseqqgtr;': '\u2a8b',
    'LessEqualGreater;': '\u22da',
    'LessFullEqual;': '\u2266',
    'LessGreater;': '\u2276',
    'lessgtr;': '\u2276',
    'LessLess;': '\u2aa1',
    'lesssim;': '\u2272',
    'LessSlantEqual;': '\u2a7d',
    'LessTilde;': '\u2272',
    'lfisht;': '\u297c',
    'lfloor;': '\u230a',
    'Lfr;': '\U0001d50f',
    'lfr;': '\U0001d529',
    'lg;': '\u2276',
    'lgE;': '\u2a91',
    'lHar;': '\u2962',
    'lhard;': '\u21bd',
    'lharu;': '\u21bc',
    'lharul;': '\u296a',
    'lhblk;': '\u2584',
    'LJcy;': '\u0409',
    'ljcy;': '\u0459',
    'Ll;': '\u22d8',
    'll;': '\u226a',
    'llarr;': '\u21c7',
    'llcorner;': '\u231e',
    'Lleftarrow;': '\u21da',
    'llhard;': '\u296b',
    'lltri;': '\u25fa',
    'Lmidot;': '\u013f',
    'lmidot;': '\u0140',
    'lmoust;': '\u23b0',
    'lmoustache;': '\u23b0',
    'lnap;': '\u2a89',
    'lnapprox;': '\u2a89',
    'lnE;': '\u2268',
    'lne;': '\u2a87',
    'lneq;': '\u2a87',
    'lneqq;': '\u2268',
    'lnsim;': '\u22e6',
    'loang;': '\u27ec',
    'loarr;': '\u21fd',
    'lobrk;': '\u27e6',
    'LongLeftArrow;': '\u27f5',
    'Longleftarrow;': '\u27f8',
    'longleftarrow;': '\u27f5',
    'LongLeftRightArrow;': '\u27f7',
    'Longleftrightarrow;': '\u27fa',
    'longleftrightarrow;': '\u27f7',
    'longmapsto;': '\u27fc',
    'LongRightArrow;': '\u27f6',
    'Longrightarrow;': '\u27f9',
    'longrightarrow;': '\u27f6',
    'looparrowleft;': '\u21ab',
    'looparrowright;': '\u21ac',
    'lopar;': '\u2985',
    'Lopf;': '\U0001d543',
    'lopf;': '\U0001d55d',
    'loplus;': '\u2a2d',
    'lotimes;': '\u2a34',
    'lowast;': '\u2217',
    'lowbar;': '_',
    'LowerLeftArrow;': '\u2199',
    'LowerRightArrow;': '\u2198',
    'loz;': '\u25ca',
    'lozenge;': '\u25ca',
    'lozf;': '\u29eb',
    'lpar;': '(',
    'lparlt;': '\u2993',
    'lrarr;': '\u21c6',
    'lrcorner;': '\u231f',
    'lrhar;': '\u21cb',
    'lrhard;': '\u296d',
    'lrm;': '\u200e',
    'lrtri;': '\u22bf',
    'lsaquo;': '\u2039',
    'Lscr;': '\u2112',
    'lscr;': '\U0001d4c1',
    'Lsh;': '\u21b0',
    'lsh;': '\u21b0',
    'lsim;': '\u2272',
    'lsime;': '\u2a8d',
    'lsimg;': '\u2a8f',
    'lsqb;': '[',
    'lsquo;': '\u2018',
    'lsquor;': '\u201a',
    'Lstrok;': '\u0141',
    'lstrok;': '\u0142',
    'LT': '<',
    'lt': '<',
    'LT;': '<',
    'Lt;': '\u226a',
    'lt;': '<',
    'ltcc;': '\u2aa6',
    'ltcir;': '\u2a79',
    'ltdot;': '\u22d6',
    'lthree;': '\u22cb',
    'ltimes;': '\u22c9',
    'ltlarr;': '\u2976',
    'ltquest;': '\u2a7b',
    'ltri;': '\u25c3',
    'ltrie;': '\u22b4',
    'ltrif;': '\u25c2',
    'ltrPar;': '\u2996',
    'lurdshar;': '\u294a',
    'luruhar;': '\u2966',
    'lvertneqq;': '\u2268\ufe00',
    'lvnE;': '\u2268\ufe00',
    'macr': '\xaf',
    'macr;': '\xaf',
    'male;': '\u2642',
    'malt;': '\u2720',
    'maltese;': '\u2720',
    'Map;': '\u2905',
    'map;': '\u21a6',
    'mapsto;': '\u21a6',
    'mapstodown;': '\u21a7',
    'mapstoleft;': '\u21a4',
    'mapstoup;': '\u21a5',
    'marker;': '\u25ae',
    'mcomma;': '\u2a29',
    'Mcy;': '\u041c',
    'mcy;': '\u043c',
    'mdash;': '\u2014',
    'mDDot;': '\u223a',
    'measuredangle;': '\u2221',
    'MediumSpace;': '\u205f',
    'Mellintrf;': '\u2133',
    'Mfr;': '\U0001d510',
    'mfr;': '\U0001d52a',
    'mho;': '\u2127',
    'micro': '\xb5',
    'micro;': '\xb5',
    'mid;': '\u2223',
    'midast;': '*',
    'midcir;': '\u2af0',
    'middot': '\xb7',
    'middot;': '\xb7',
    'minus;': '\u2212',
    'minusb;': '\u229f',
    'minusd;': '\u2238',
    'minusdu;': '\u2a2a',
    'MinusPlus;': '\u2213',
    'mlcp;': '\u2adb',
    'mldr;': '\u2026',
    'mnplus;': '\u2213',
    'models;': '\u22a7',
    'Mopf;': '\U0001d544',
    'mopf;': '\U0001d55e',
    'mp;': '\u2213',
    'Mscr;': '\u2133',
    'mscr;': '\U0001d4c2',
    'mstpos;': '\u223e',
    'Mu;': '\u039c',
    'mu;': '\u03bc',
    'multimap;': '\u22b8',
    'mumap;': '\u22b8',
    'nabla;': '\u2207',
    'Nacute;': '\u0143',
    'nacute;': '\u0144',
    'nang;': '\u2220\u20d2',
    'nap;': '\u2249',
    'napE;': '\u2a70\u0338',
    'napid;': '\u224b\u0338',
    'napos;': '\u0149',
    'napprox;': '\u2249',
    'natur;': '\u266e',
    'natural;': '\u266e',
    'naturals;': '\u2115',
    'nbsp': '\xa0',
    'nbsp;': '\xa0',
    'nbump;': '\u224e\u0338',
    'nbumpe;': '\u224f\u0338',
    'ncap;': '\u2a43',
    'Ncaron;': '\u0147',
    'ncaron;': '\u0148',
    'Ncedil;': '\u0145',
    'ncedil;': '\u0146',
    'ncong;': '\u2247',
    'ncongdot;': '\u2a6d\u0338',
    'ncup;': '\u2a42',
    'Ncy;': '\u041d',
    'ncy;': '\u043d',
    'ndash;': '\u2013',
    'ne;': '\u2260',
    'nearhk;': '\u2924',
    'neArr;': '\u21d7',
    'nearr;': '\u2197',
    'nearrow;': '\u2197',
    'nedot;': '\u2250\u0338',
    'NegativeMediumSpace;': '\u200b',
    'NegativeThickSpace;': '\u200b',
    'NegativeThinSpace;': '\u200b',
    'NegativeVeryThinSpace;': '\u200b',
    'nequiv;': '\u2262',
    'nesear;': '\u2928',
    'nesim;': '\u2242\u0338',
    'NestedGreaterGreater;': '\u226b',
    'NestedLessLess;': '\u226a',
    'NewLine;': '\n',
    'nexist;': '\u2204',
    'nexists;': '\u2204',
    'Nfr;': '\U0001d511',
    'nfr;': '\U0001d52b',
    'ngE;': '\u2267\u0338',
    'nge;': '\u2271',
    'ngeq;': '\u2271',
    'ngeqq;': '\u2267\u0338',
    'ngeqslant;': '\u2a7e\u0338',
    'nges;': '\u2a7e\u0338',
    'nGg;': '\u22d9\u0338',
    'ngsim;': '\u2275',
    'nGt;': '\u226b\u20d2',
    'ngt;': '\u226f',
    'ngtr;': '\u226f',
    'nGtv;': '\u226b\u0338',
    'nhArr;': '\u21ce',
    'nharr;': '\u21ae',
    'nhpar;': '\u2af2',
    'ni;': '\u220b',
    'nis;': '\u22fc',
    'nisd;': '\u22fa',
    'niv;': '\u220b',
    'NJcy;': '\u040a',
    'njcy;': '\u045a',
    'nlArr;': '\u21cd',
    'nlarr;': '\u219a',
    'nldr;': '\u2025',
    'nlE;': '\u2266\u0338',
    'nle;': '\u2270',
    'nLeftarrow;': '\u21cd',
    'nleftarrow;': '\u219a',
    'nLeftrightarrow;': '\u21ce',
    'nleftrightarrow;': '\u21ae',
    'nleq;': '\u2270',
    'nleqq;': '\u2266\u0338',
    'nleqslant;': '\u2a7d\u0338',
    'nles;': '\u2a7d\u0338',
    'nless;': '\u226e',
    'nLl;': '\u22d8\u0338',
    'nlsim;': '\u2274',
    'nLt;': '\u226a\u20d2',
    'nlt;': '\u226e',
    'nltri;': '\u22ea',
    'nltrie;': '\u22ec',
    'nLtv;': '\u226a\u0338',
    'nmid;': '\u2224',
    'NoBreak;': '\u2060',
    'NonBreakingSpace;': '\xa0',
    'Nopf;': '\u2115',
    'nopf;': '\U0001d55f',
    'not': '\xac',
    'Not;': '\u2aec',
    'not;': '\xac',
    'NotCongruent;': '\u2262',
    'NotCupCap;': '\u226d',
    'NotDoubleVerticalBar;': '\u2226',
    'NotElement;': '\u2209',
    'NotEqual;': '\u2260',
    'NotEqualTilde;': '\u2242\u0338',
    'NotExists;': '\u2204',
    'NotGreater;': '\u226f',
    'NotGreaterEqual;': '\u2271',
    'NotGreaterFullEqual;': '\u2267\u0338',
    'NotGreaterGreater;': '\u226b\u0338',
    'NotGreaterLess;': '\u2279',
    'NotGreaterSlantEqual;': '\u2a7e\u0338',
    'NotGreaterTilde;': '\u2275',
    'NotHumpDownHump;': '\u224e\u0338',
    'NotHumpEqual;': '\u224f\u0338',
    'notin;': '\u2209',
    'notindot;': '\u22f5\u0338',
    'notinE;': '\u22f9\u0338',
    'notinva;': '\u2209',
    'notinvb;': '\u22f7',
    'notinvc;': '\u22f6',
    'NotLeftTriangle;': '\u22ea',
    'NotLeftTriangleBar;': '\u29cf\u0338',
    'NotLeftTriangleEqual;': '\u22ec',
    'NotLess;': '\u226e',
    'NotLessEqual;': '\u2270',
    'NotLessGreater;': '\u2278',
    'NotLessLess;': '\u226a\u0338',
    'NotLessSlantEqual;': '\u2a7d\u0338',
    'NotLessTilde;': '\u2274',
    'NotNestedGreaterGreater;': '\u2aa2\u0338',
    'NotNestedLessLess;': '\u2aa1\u0338',
    'notni;': '\u220c',
    'notniva;': '\u220c',
    'notnivb;': '\u22fe',
    'notnivc;': '\u22fd',
    'NotPrecedes;': '\u2280',
    'NotPrecedesEqual;': '\u2aaf\u0338',
    'NotPrecedesSlantEqual;': '\u22e0',
    'NotReverseElement;': '\u220c',
    'NotRightTriangle;': '\u22eb',
    'NotRightTriangleBar;': '\u29d0\u0338',
    'NotRightTriangleEqual;': '\u22ed',
    'NotSquareSubset;': '\u228f\u0338',
    'NotSquareSubsetEqual;': '\u22e2',
    'NotSquareSuperset;': '\u2290\u0338',
    'NotSquareSupersetEqual;': '\u22e3',
    'NotSubset;': '\u2282\u20d2',
    'NotSubsetEqual;': '\u2288',
    'NotSucceeds;': '\u2281',
    'NotSucceedsEqual;': '\u2ab0\u0338',
    'NotSucceedsSlantEqual;': '\u22e1',
    'NotSucceedsTilde;': '\u227f\u0338',
    'NotSuperset;': '\u2283\u20d2',
    'NotSupersetEqual;': '\u2289',
    'NotTilde;': '\u2241',
    'NotTildeEqual;': '\u2244',
    'NotTildeFullEqual;': '\u2247',
    'NotTildeTilde;': '\u2249',
    'NotVerticalBar;': '\u2224',
    'npar;': '\u2226',
    'nparallel;': '\u2226',
    'nparsl;': '\u2afd\u20e5',
    'npart;': '\u2202\u0338',
    'npolint;': '\u2a14',
    'npr;': '\u2280',
    'nprcue;': '\u22e0',
    'npre;': '\u2aaf\u0338',
    'nprec;': '\u2280',
    'npreceq;': '\u2aaf\u0338',
    'nrArr;': '\u21cf',
    'nrarr;': '\u219b',
    'nrarrc;': '\u2933\u0338',
    'nrarrw;': '\u219d\u0338',
    'nRightarrow;': '\u21cf',
    'nrightarrow;': '\u219b',
    'nrtri;': '\u22eb',
    'nrtrie;': '\u22ed',
    'nsc;': '\u2281',
    'nsccue;': '\u22e1',
    'nsce;': '\u2ab0\u0338',
    'Nscr;': '\U0001d4a9',
    'nscr;': '\U0001d4c3',
    'nshortmid;': '\u2224',
    'nshortparallel;': '\u2226',
    'nsim;': '\u2241',
    'nsime;': '\u2244',
    'nsimeq;': '\u2244',
    'nsmid;': '\u2224',
    'nspar;': '\u2226',
    'nsqsube;': '\u22e2',
    'nsqsupe;': '\u22e3',
    'nsub;': '\u2284',
    'nsubE;': '\u2ac5\u0338',
    'nsube;': '\u2288',
    'nsubset;': '\u2282\u20d2',
    'nsubseteq;': '\u2288',
    'nsubseteqq;': '\u2ac5\u0338',
    'nsucc;': '\u2281',
    'nsucceq;': '\u2ab0\u0338',
    'nsup;': '\u2285',
    'nsupE;': '\u2ac6\u0338',
    'nsupe;': '\u2289',
    'nsupset;': '\u2283\u20d2',
    'nsupseteq;': '\u2289',
    'nsupseteqq;': '\u2ac6\u0338',
    'ntgl;': '\u2279',
    'Ntilde': '\xd1',
    'ntilde': '\xf1',
    'Ntilde;': '\xd1',
    'ntilde;': '\xf1',
    'ntlg;': '\u2278',
    'ntriangleleft;': '\u22ea',
    'ntrianglelefteq;': '\u22ec',
    'ntriangleright;': '\u22eb',
    'ntrianglerighteq;': '\u22ed',
    'Nu;': '\u039d',
    'nu;': '\u03bd',
    'num;': '#',
    'numero;': '\u2116',
    'numsp;': '\u2007',
    'nvap;': '\u224d\u20d2',
    'nVDash;': '\u22af',
    'nVdash;': '\u22ae',
    'nvDash;': '\u22ad',
    'nvdash;': '\u22ac',
    'nvge;': '\u2265\u20d2',
    'nvgt;': '>\u20d2',
    'nvHarr;': '\u2904',
    'nvinfin;': '\u29de',
    'nvlArr;': '\u2902',
    'nvle;': '\u2264\u20d2',
    'nvlt;': '<\u20d2',
    'nvltrie;': '\u22b4\u20d2',
    'nvrArr;': '\u2903',
    'nvrtrie;': '\u22b5\u20d2',
    'nvsim;': '\u223c\u20d2',
    'nwarhk;': '\u2923',
    'nwArr;': '\u21d6',
    'nwarr;': '\u2196',
    'nwarrow;': '\u2196',
    'nwnear;': '\u2927',
    'Oacute': '\xd3',
    'oacute': '\xf3',
    'Oacute;': '\xd3',
    'oacute;': '\xf3',
    'oast;': '\u229b',
    'ocir;': '\u229a',
    'Ocirc': '\xd4',
    'ocirc': '\xf4',
    'Ocirc;': '\xd4',
    'ocirc;': '\xf4',
    'Ocy;': '\u041e',
    'ocy;': '\u043e',
    'odash;': '\u229d',
    'Odblac;': '\u0150',
    'odblac;': '\u0151',
    'odiv;': '\u2a38',
    'odot;': '\u2299',
    'odsold;': '\u29bc',
    'OElig;': '\u0152',
    'oelig;': '\u0153',
    'ofcir;': '\u29bf',
    'Ofr;': '\U0001d512',
    'ofr;': '\U0001d52c',
    'ogon;': '\u02db',
    'Ograve': '\xd2',
    'ograve': '\xf2',
    'Ograve;': '\xd2',
    'ograve;': '\xf2',
    'ogt;': '\u29c1',
    'ohbar;': '\u29b5',
    'ohm;': '\u03a9',
    'oint;': '\u222e',
    'olarr;': '\u21ba',
    'olcir;': '\u29be',
    'olcross;': '\u29bb',
    'oline;': '\u203e',
    'olt;': '\u29c0',
    'Omacr;': '\u014c',
    'omacr;': '\u014d',
    'Omega;': '\u03a9',
    'omega;': '\u03c9',
    'Omicron;': '\u039f',
    'omicron;': '\u03bf',
    'omid;': '\u29b6',
    'ominus;': '\u2296',
    'Oopf;': '\U0001d546',
    'oopf;': '\U0001d560',
    'opar;': '\u29b7',
    'OpenCurlyDoubleQuote;': '\u201c',
    'OpenCurlyQuote;': '\u2018',
    'operp;': '\u29b9',
    'oplus;': '\u2295',
    'Or;': '\u2a54',
    'or;': '\u2228',
    'orarr;': '\u21bb',
    'ord;': '\u2a5d',
    'order;': '\u2134',
    'orderof;': '\u2134',
    'ordf': '\xaa',
    'ordf;': '\xaa',
    'ordm': '\xba',
    'ordm;': '\xba',
    'origof;': '\u22b6',
    'oror;': '\u2a56',
    'orslope;': '\u2a57',
    'orv;': '\u2a5b',
    'oS;': '\u24c8',
    'Oscr;': '\U0001d4aa',
    'oscr;': '\u2134',
    'Oslash': '\xd8',
    'oslash': '\xf8',
    'Oslash;': '\xd8',
    'oslash;': '\xf8',
    'osol;': '\u2298',
    'Otilde': '\xd5',
    'otilde': '\xf5',
    'Otilde;': '\xd5',
    'otilde;': '\xf5',
    'Otimes;': '\u2a37',
    'otimes;': '\u2297',
    'otimesas;': '\u2a36',
    'Ouml': '\xd6',
    'ouml': '\xf6',
    'Ouml;': '\xd6',
    'ouml;': '\xf6',
    'ovbar;': '\u233d',
    'OverBar;': '\u203e',
    'OverBrace;': '\u23de',
    'OverBracket;': '\u23b4',
    'OverParenthesis;': '\u23dc',
    'par;': '\u2225',
    'para': '\xb6',
    'para;': '\xb6',
    'parallel;': '\u2225',
    'parsim;': '\u2af3',
    'parsl;': '\u2afd',
    'part;': '\u2202',
    'PartialD;': '\u2202',
    'Pcy;': '\u041f',
    'pcy;': '\u043f',
    'percnt;': '%',
    'period;': '.',
    'permil;': '\u2030',
    'perp;': '\u22a5',
    'pertenk;': '\u2031',
    'Pfr;': '\U0001d513',
    'pfr;': '\U0001d52d',
    'Phi;': '\u03a6',
    'phi;': '\u03c6',
    'phiv;': '\u03d5',
    'phmmat;': '\u2133',
    'phone;': '\u260e',
    'Pi;': '\u03a0',
    'pi;': '\u03c0',
    'pitchfork;': '\u22d4',
    'piv;': '\u03d6',
    'planck;': '\u210f',
    'planckh;': '\u210e',
    'plankv;': '\u210f',
    'plus;': '+',
    'plusacir;': '\u2a23',
    'plusb;': '\u229e',
    'pluscir;': '\u2a22',
    'plusdo;': '\u2214',
    'plusdu;': '\u2a25',
    'pluse;': '\u2a72',
    'PlusMinus;': '\xb1',
    'plusmn': '\xb1',
    'plusmn;': '\xb1',
    'plussim;': '\u2a26',
    'plustwo;': '\u2a27',
    'pm;': '\xb1',
    'Poincareplane;': '\u210c',
    'pointint;': '\u2a15',
    'Popf;': '\u2119',
    'popf;': '\U0001d561',
    'pound': '\xa3',
    'pound;': '\xa3',
    'Pr;': '\u2abb',
    'pr;': '\u227a',
    'prap;': '\u2ab7',
    'prcue;': '\u227c',
    'prE;': '\u2ab3',
    'pre;': '\u2aaf',
    'prec;': '\u227a',
    'precapprox;': '\u2ab7',
    'preccurlyeq;': '\u227c',
    'Precedes;': '\u227a',
    'PrecedesEqual;': '\u2aaf',
    'PrecedesSlantEqual;': '\u227c',
    'PrecedesTilde;': '\u227e',
    'preceq;': '\u2aaf',
    'precnapprox;': '\u2ab9',
    'precneqq;': '\u2ab5',
    'precnsim;': '\u22e8',
    'precsim;': '\u227e',
    'Prime;': '\u2033',
    'prime;': '\u2032',
    'primes;': '\u2119',
    'prnap;': '\u2ab9',
    'prnE;': '\u2ab5',
    'prnsim;': '\u22e8',
    'prod;': '\u220f',
    'Product;': '\u220f',
    'profalar;': '\u232e',
    'profline;': '\u2312',
    'profsurf;': '\u2313',
    'prop;': '\u221d',
    'Proportion;': '\u2237',
    'Proportional;': '\u221d',
    'propto;': '\u221d',
    'prsim;': '\u227e',
    'prurel;': '\u22b0',
    'Pscr;': '\U0001d4ab',
    'pscr;': '\U0001d4c5',
    'Psi;': '\u03a8',
    'psi;': '\u03c8',
    'puncsp;': '\u2008',
    'Qfr;': '\U0001d514',
    'qfr;': '\U0001d52e',
    'qint;': '\u2a0c',
    'Qopf;': '\u211a',
    'qopf;': '\U0001d562',
    'qprime;': '\u2057',
    'Qscr;': '\U0001d4ac',
    'qscr;': '\U0001d4c6',
    'quaternions;': '\u210d',
    'quatint;': '\u2a16',
    'quest;': '?',
    'questeq;': '\u225f',
    'QUOT': '"',
    'quot': '"',
    'QUOT;': '"',
    'quot;': '"',
    'rAarr;': '\u21db',
    'race;': '\u223d\u0331',
    'Racute;': '\u0154',
    'racute;': '\u0155',
    'radic;': '\u221a',
    'raemptyv;': '\u29b3',
    'Rang;': '\u27eb',
    'rang;': '\u27e9',
    'rangd;': '\u2992',
    'range;': '\u29a5',
    'rangle;': '\u27e9',
    'raquo': '\xbb',
    'raquo;': '\xbb',
    'Rarr;': '\u21a0',
    'rArr;': '\u21d2',
    'rarr;': '\u2192',
    'rarrap;': '\u2975',
    'rarrb;': '\u21e5',
    'rarrbfs;': '\u2920',
    'rarrc;': '\u2933',
    'rarrfs;': '\u291e',
    'rarrhk;': '\u21aa',
    'rarrlp;': '\u21ac',
    'rarrpl;': '\u2945',
    'rarrsim;': '\u2974',
    'Rarrtl;': '\u2916',
    'rarrtl;': '\u21a3',
    'rarrw;': '\u219d',
    'rAtail;': '\u291c',
    'ratail;': '\u291a',
    'ratio;': '\u2236',
    'rationals;': '\u211a',
    'RBarr;': '\u2910',
    'rBarr;': '\u290f',
    'rbarr;': '\u290d',
    'rbbrk;': '\u2773',
    'rbrace;': '}',
    'rbrack;': ']',
    'rbrke;': '\u298c',
    'rbrksld;': '\u298e',
    'rbrkslu;': '\u2990',
    'Rcaron;': '\u0158',
    'rcaron;': '\u0159',
    'Rcedil;': '\u0156',
    'rcedil;': '\u0157',
    'rceil;': '\u2309',
    'rcub;': '}',
    'Rcy;': '\u0420',
    'rcy;': '\u0440',
    'rdca;': '\u2937',
    'rdldhar;': '\u2969',
    'rdquo;': '\u201d',
    'rdquor;': '\u201d',
    'rdsh;': '\u21b3',
    'Re;': '\u211c',
    'real;': '\u211c',
    'realine;': '\u211b',
    'realpart;': '\u211c',
    'reals;': '\u211d',
    'rect;': '\u25ad',
    'REG': '\xae',
    'reg': '\xae',
    'REG;': '\xae',
    'reg;': '\xae',
    'ReverseElement;': '\u220b',
    'ReverseEquilibrium;': '\u21cb',
    'ReverseUpEquilibrium;': '\u296f',
    'rfisht;': '\u297d',
    'rfloor;': '\u230b',
    'Rfr;': '\u211c',
    'rfr;': '\U0001d52f',
    'rHar;': '\u2964',
    'rhard;': '\u21c1',
    'rharu;': '\u21c0',
    'rharul;': '\u296c',
    'Rho;': '\u03a1',
    'rho;': '\u03c1',
    'rhov;': '\u03f1',
    'RightAngleBracket;': '\u27e9',
    'RightArrow;': '\u2192',
    'Rightarrow;': '\u21d2',
    'rightarrow;': '\u2192',
    'RightArrowBar;': '\u21e5',
    'RightArrowLeftArrow;': '\u21c4',
    'rightarrowtail;': '\u21a3',
    'RightCeiling;': '\u2309',
    'RightDoubleBracket;': '\u27e7',
    'RightDownTeeVector;': '\u295d',
    'RightDownVector;': '\u21c2',
    'RightDownVectorBar;': '\u2955',
    'RightFloor;': '\u230b',
    'rightharpoondown;': '\u21c1',
    'rightharpoonup;': '\u21c0',
    'rightleftarrows;': '\u21c4',
    'rightleftharpoons;': '\u21cc',
    'rightrightarrows;': '\u21c9',
    'rightsquigarrow;': '\u219d',
    'RightTee;': '\u22a2',
    'RightTeeArrow;': '\u21a6',
    'RightTeeVector;': '\u295b',
    'rightthreetimes;': '\u22cc',
    'RightTriangle;': '\u22b3',
    'RightTriangleBar;': '\u29d0',
    'RightTriangleEqual;': '\u22b5',
    'RightUpDownVector;': '\u294f',
    'RightUpTeeVector;': '\u295c',
    'RightUpVector;': '\u21be',
    'RightUpVectorBar;': '\u2954',
    'RightVector;': '\u21c0',
    'RightVectorBar;': '\u2953',
    'ring;': '\u02da',
    'risingdotseq;': '\u2253',
    'rlarr;': '\u21c4',
    'rlhar;': '\u21cc',
    'rlm;': '\u200f',
    'rmoust;': '\u23b1',
    'rmoustache;': '\u23b1',
    'rnmid;': '\u2aee',
    'roang;': '\u27ed',
    'roarr;': '\u21fe',
    'robrk;': '\u27e7',
    'ropar;': '\u2986',
    'Ropf;': '\u211d',
    'ropf;': '\U0001d563',
    'roplus;': '\u2a2e',
    'rotimes;': '\u2a35',
    'RoundImplies;': '\u2970',
    'rpar;': ')',
    'rpargt;': '\u2994',
    'rppolint;': '\u2a12',
    'rrarr;': '\u21c9',
    'Rrightarrow;': '\u21db',
    'rsaquo;': '\u203a',
    'Rscr;': '\u211b',
    'rscr;': '\U0001d4c7',
    'Rsh;': '\u21b1',
    'rsh;': '\u21b1',
    'rsqb;': ']',
    'rsquo;': '\u2019',
    'rsquor;': '\u2019',
    'rthree;': '\u22cc',
    'rtimes;': '\u22ca',
    'rtri;': '\u25b9',
    'rtrie;': '\u22b5',
    'rtrif;': '\u25b8',
    'rtriltri;': '\u29ce',
    'RuleDelayed;': '\u29f4',
    'ruluhar;': '\u2968',
    'rx;': '\u211e',
    'Sacute;': '\u015a',
    'sacute;': '\u015b',
    'sbquo;': '\u201a',
    'Sc;': '\u2abc',
    'sc;': '\u227b',
    'scap;': '\u2ab8',
    'Scaron;': '\u0160',
    'scaron;': '\u0161',
    'sccue;': '\u227d',
    'scE;': '\u2ab4',
    'sce;': '\u2ab0',
    'Scedil;': '\u015e',
    'scedil;': '\u015f',
    'Scirc;': '\u015c',
    'scirc;': '\u015d',
    'scnap;': '\u2aba',
    'scnE;': '\u2ab6',
    'scnsim;': '\u22e9',
    'scpolint;': '\u2a13',
    'scsim;': '\u227f',
    'Scy;': '\u0421',
    'scy;': '\u0441',
    'sdot;': '\u22c5',
    'sdotb;': '\u22a1',
    'sdote;': '\u2a66',
    'searhk;': '\u2925',
    'seArr;': '\u21d8',
    'searr;': '\u2198',
    'searrow;': '\u2198',
    'sect': '\xa7',
    'sect;': '\xa7',
    'semi;': ';',
    'seswar;': '\u2929',
    'setminus;': '\u2216',
    'setmn;': '\u2216',
    'sext;': '\u2736',
    'Sfr;': '\U0001d516',
    'sfr;': '\U0001d530',
    'sfrown;': '\u2322',
    'sharp;': '\u266f',
    'SHCHcy;': '\u0429',
    'shchcy;': '\u0449',
    'SHcy;': '\u0428',
    'shcy;': '\u0448',
    'ShortDownArrow;': '\u2193',
    'ShortLeftArrow;': '\u2190',
    'shortmid;': '\u2223',
    'shortparallel;': '\u2225',
    'ShortRightArrow;': '\u2192',
    'ShortUpArrow;': '\u2191',
    'shy': '\xad',
    'shy;': '\xad',
    'Sigma;': '\u03a3',
    'sigma;': '\u03c3',
    'sigmaf;': '\u03c2',
    'sigmav;': '\u03c2',
    'sim;': '\u223c',
    'simdot;': '\u2a6a',
    'sime;': '\u2243',
    'simeq;': '\u2243',
    'simg;': '\u2a9e',
    'simgE;': '\u2aa0',
    'siml;': '\u2a9d',
    'simlE;': '\u2a9f',
    'simne;': '\u2246',
    'simplus;': '\u2a24',
    'simrarr;': '\u2972',
    'slarr;': '\u2190',
    'SmallCircle;': '\u2218',
    'smallsetminus;': '\u2216',
    'smashp;': '\u2a33',
    'smeparsl;': '\u29e4',
    'smid;': '\u2223',
    'smile;': '\u2323',
    'smt;': '\u2aaa',
    'smte;': '\u2aac',
    'smtes;': '\u2aac\ufe00',
    'SOFTcy;': '\u042c',
    'softcy;': '\u044c',
    'sol;': '/',
    'solb;': '\u29c4',
    'solbar;': '\u233f',
    'Sopf;': '\U0001d54a',
    'sopf;': '\U0001d564',
    'spades;': '\u2660',
    'spadesuit;': '\u2660',
    'spar;': '\u2225',
    'sqcap;': '\u2293',
    'sqcaps;': '\u2293\ufe00',
    'sqcup;': '\u2294',
    'sqcups;': '\u2294\ufe00',
    'Sqrt;': '\u221a',
    'sqsub;': '\u228f',
    'sqsube;': '\u2291',
    'sqsubset;': '\u228f',
    'sqsubseteq;': '\u2291',
    'sqsup;': '\u2290',
    'sqsupe;': '\u2292',
    'sqsupset;': '\u2290',
    'sqsupseteq;': '\u2292',
    'squ;': '\u25a1',
    'Square;': '\u25a1',
    'square;': '\u25a1',
    'SquareIntersection;': '\u2293',
    'SquareSubset;': '\u228f',
    'SquareSubsetEqual;': '\u2291',
    'SquareSuperset;': '\u2290',
    'SquareSupersetEqual;': '\u2292',
    'SquareUnion;': '\u2294',
    'squarf;': '\u25aa',
    'squf;': '\u25aa',
    'srarr;': '\u2192',
    'Sscr;': '\U0001d4ae',
    'sscr;': '\U0001d4c8',
    'ssetmn;': '\u2216',
    'ssmile;': '\u2323',
    'sstarf;': '\u22c6',
    'Star;': '\u22c6',
    'star;': '\u2606',
    'starf;': '\u2605',
    'straightepsilon;': '\u03f5',
    'straightphi;': '\u03d5',
    'strns;': '\xaf',
    'Sub;': '\u22d0',
    'sub;': '\u2282',
    'subdot;': '\u2abd',
    'subE;': '\u2ac5',
    'sube;': '\u2286',
    'subedot;': '\u2ac3',
    'submult;': '\u2ac1',
    'subnE;': '\u2acb',
    'subne;': '\u228a',
    'subplus;': '\u2abf',
    'subrarr;': '\u2979',
    'Subset;': '\u22d0',
    'subset;': '\u2282',
    'subseteq;': '\u2286',
    'subseteqq;': '\u2ac5',
    'SubsetEqual;': '\u2286',
    'subsetneq;': '\u228a',
    'subsetneqq;': '\u2acb',
    'subsim;': '\u2ac7',
    'subsub;': '\u2ad5',
    'subsup;': '\u2ad3',
    'succ;': '\u227b',
    'succapprox;': '\u2ab8',
    'succcurlyeq;': '\u227d',
    'Succeeds;': '\u227b',
    'SucceedsEqual;': '\u2ab0',
    'SucceedsSlantEqual;': '\u227d',
    'SucceedsTilde;': '\u227f',
    'succeq;': '\u2ab0',
    'succnapprox;': '\u2aba',
    'succneqq;': '\u2ab6',
    'succnsim;': '\u22e9',
    'succsim;': '\u227f',
    'SuchThat;': '\u220b',
    'Sum;': '\u2211',
    'sum;': '\u2211',
    'sung;': '\u266a',
    'sup1': '\xb9',
    'sup1;': '\xb9',
    'sup2': '\xb2',
    'sup2;': '\xb2',
    'sup3': '\xb3',
    'sup3;': '\xb3',
    'Sup;': '\u22d1',
    'sup;': '\u2283',
    'supdot;': '\u2abe',
    'supdsub;': '\u2ad8',
    'supE;': '\u2ac6',
    'supe;': '\u2287',
    'supedot;': '\u2ac4',
    'Superset;': '\u2283',
    'SupersetEqual;': '\u2287',
    'suphsol;': '\u27c9',
    'suphsub;': '\u2ad7',
    'suplarr;': '\u297b',
    'supmult;': '\u2ac2',
    'supnE;': '\u2acc',
    'supne;': '\u228b',
    'supplus;': '\u2ac0',
    'Supset;': '\u22d1',
    'supset;': '\u2283',
    'supseteq;': '\u2287',
    'supseteqq;': '\u2ac6',
    'supsetneq;': '\u228b',
    'supsetneqq;': '\u2acc',
    'supsim;': '\u2ac8',
    'supsub;': '\u2ad4',
    'supsup;': '\u2ad6',
    'swarhk;': '\u2926',
    'swArr;': '\u21d9',
    'swarr;': '\u2199',
    'swarrow;': '\u2199',
    'swnwar;': '\u292a',
    'szlig': '\xdf',
    'szlig;': '\xdf',
    'Tab;': '\t',
    'target;': '\u2316',
    'Tau;': '\u03a4',
    'tau;': '\u03c4',
    'tbrk;': '\u23b4',
    'Tcaron;': '\u0164',
    'tcaron;': '\u0165',
    'Tcedil;': '\u0162',
    'tcedil;': '\u0163',
    'Tcy;': '\u0422',
    'tcy;': '\u0442',
    'tdot;': '\u20db',
    'telrec;': '\u2315',
    'Tfr;': '\U0001d517',
    'tfr;': '\U0001d531',
    'there4;': '\u2234',
    'Therefore;': '\u2234',
    'therefore;': '\u2234',
    'Theta;': '\u0398',
    'theta;': '\u03b8',
    'thetasym;': '\u03d1',
    'thetav;': '\u03d1',
    'thickapprox;': '\u2248',
    'thicksim;': '\u223c',
    'ThickSpace;': '\u205f\u200a',
    'thinsp;': '\u2009',
    'ThinSpace;': '\u2009',
    'thkap;': '\u2248',
    'thksim;': '\u223c',
    'THORN': '\xde',
    'thorn': '\xfe',
    'THORN;': '\xde',
    'thorn;': '\xfe',
    'Tilde;': '\u223c',
    'tilde;': '\u02dc',
    'TildeEqual;': '\u2243',
    'TildeFullEqual;': '\u2245',
    'TildeTilde;': '\u2248',
    'times': '\xd7',
    'times;': '\xd7',
    'timesb;': '\u22a0',
    'timesbar;': '\u2a31',
    'timesd;': '\u2a30',
    'tint;': '\u222d',
    'toea;': '\u2928',
    'top;': '\u22a4',
    'topbot;': '\u2336',
    'topcir;': '\u2af1',
    'Topf;': '\U0001d54b',
    'topf;': '\U0001d565',
    'topfork;': '\u2ada',
    'tosa;': '\u2929',
    'tprime;': '\u2034',
    'TRADE;': '\u2122',
    'trade;': '\u2122',
    'triangle;': '\u25b5',
    'triangledown;': '\u25bf',
    'triangleleft;': '\u25c3',
    'trianglelefteq;': '\u22b4',
    'triangleq;': '\u225c',
    'triangleright;': '\u25b9',
    'trianglerighteq;': '\u22b5',
    'tridot;': '\u25ec',
    'trie;': '\u225c',
    'triminus;': '\u2a3a',
    'TripleDot;': '\u20db',
    'triplus;': '\u2a39',
    'trisb;': '\u29cd',
    'tritime;': '\u2a3b',
    'trpezium;': '\u23e2',
    'Tscr;': '\U0001d4af',
    'tscr;': '\U0001d4c9',
    'TScy;': '\u0426',
    'tscy;': '\u0446',
    'TSHcy;': '\u040b',
    'tshcy;': '\u045b',
    'Tstrok;': '\u0166',
    'tstrok;': '\u0167',
    'twixt;': '\u226c',
    'twoheadleftarrow;': '\u219e',
    'twoheadrightarrow;': '\u21a0',
    'Uacute': '\xda',
    'uacute': '\xfa',
    'Uacute;': '\xda',
    'uacute;': '\xfa',
    'Uarr;': '\u219f',
    'uArr;': '\u21d1',
    'uarr;': '\u2191',
    'Uarrocir;': '\u2949',
    'Ubrcy;': '\u040e',
    'ubrcy;': '\u045e',
    'Ubreve;': '\u016c',
    'ubreve;': '\u016d',
    'Ucirc': '\xdb',
    'ucirc': '\xfb',
    'Ucirc;': '\xdb',
    'ucirc;': '\xfb',
    'Ucy;': '\u0423',
    'ucy;': '\u0443',
    'udarr;': '\u21c5',
    'Udblac;': '\u0170',
    'udblac;': '\u0171',
    'udhar;': '\u296e',
    'ufisht;': '\u297e',
    'Ufr;': '\U0001d518',
    'ufr;': '\U0001d532',
    'Ugrave': '\xd9',
    'ugrave': '\xf9',
    'Ugrave;': '\xd9',
    'ugrave;': '\xf9',
    'uHar;': '\u2963',
    'uharl;': '\u21bf',
    'uharr;': '\u21be',
    'uhblk;': '\u2580',
    'ulcorn;': '\u231c',
    'ulcorner;': '\u231c',
    'ulcrop;': '\u230f',
    'ultri;': '\u25f8',
    'Umacr;': '\u016a',
    'umacr;': '\u016b',
    'uml': '\xa8',
    'uml;': '\xa8',
    'UnderBar;': '_',
    'UnderBrace;': '\u23df',
    'UnderBracket;': '\u23b5',
    'UnderParenthesis;': '\u23dd',
    'Union;': '\u22c3',
    'UnionPlus;': '\u228e',
    'Uogon;': '\u0172',
    'uogon;': '\u0173',
    'Uopf;': '\U0001d54c',
    'uopf;': '\U0001d566',
    'UpArrow;': '\u2191',
    'Uparrow;': '\u21d1',
    'uparrow;': '\u2191',
    'UpArrowBar;': '\u2912',
    'UpArrowDownArrow;': '\u21c5',
    'UpDownArrow;': '\u2195',
    'Updownarrow;': '\u21d5',
    'updownarrow;': '\u2195',
    'UpEquilibrium;': '\u296e',
    'upharpoonleft;': '\u21bf',
    'upharpoonright;': '\u21be',
    'uplus;': '\u228e',
    'UpperLeftArrow;': '\u2196',
    'UpperRightArrow;': '\u2197',
    'Upsi;': '\u03d2',
    'upsi;': '\u03c5',
    'upsih;': '\u03d2',
    'Upsilon;': '\u03a5',
    'upsilon;': '\u03c5',
    'UpTee;': '\u22a5',
    'UpTeeArrow;': '\u21a5',
    'upuparrows;': '\u21c8',
    'urcorn;': '\u231d',
    'urcorner;': '\u231d',
    'urcrop;': '\u230e',
    'Uring;': '\u016e',
    'uring;': '\u016f',
    'urtri;': '\u25f9',
    'Uscr;': '\U0001d4b0',
    'uscr;': '\U0001d4ca',
    'utdot;': '\u22f0',
    'Utilde;': '\u0168',
    'utilde;': '\u0169',
    'utri;': '\u25b5',
    'utrif;': '\u25b4',
    'uuarr;': '\u21c8',
    'Uuml': '\xdc',
    'uuml': '\xfc',
    'Uuml;': '\xdc',
    'uuml;': '\xfc',
    'uwangle;': '\u29a7',
    'vangrt;': '\u299c',
    'varepsilon;': '\u03f5',
    'varkappa;': '\u03f0',
    'varnothing;': '\u2205',
    'varphi;': '\u03d5',
    'varpi;': '\u03d6',
    'varpropto;': '\u221d',
    'vArr;': '\u21d5',
    'varr;': '\u2195',
    'varrho;': '\u03f1',
    'varsigma;': '\u03c2',
    'varsubsetneq;': '\u228a\ufe00',
    'varsubsetneqq;': '\u2acb\ufe00',
    'varsupsetneq;': '\u228b\ufe00',
    'varsupsetneqq;': '\u2acc\ufe00',
    'vartheta;': '\u03d1',
    'vartriangleleft;': '\u22b2',
    'vartriangleright;': '\u22b3',
    'Vbar;': '\u2aeb',
    'vBar;': '\u2ae8',
    'vBarv;': '\u2ae9',
    'Vcy;': '\u0412',
    'vcy;': '\u0432',
    'VDash;': '\u22ab',
    'Vdash;': '\u22a9',
    'vDash;': '\u22a8',
    'vdash;': '\u22a2',
    'Vdashl;': '\u2ae6',
    'Vee;': '\u22c1',
    'vee;': '\u2228',
    'veebar;': '\u22bb',
    'veeeq;': '\u225a',
    'vellip;': '\u22ee',
    'Verbar;': '\u2016',
    'verbar;': '|',
    'Vert;': '\u2016',
    'vert;': '|',
    'VerticalBar;': '\u2223',
    'VerticalLine;': '|',
    'VerticalSeparator;': '\u2758',
    'VerticalTilde;': '\u2240',
    'VeryThinSpace;': '\u200a',
    'Vfr;': '\U0001d519',
    'vfr;': '\U0001d533',
    'vltri;': '\u22b2',
    'vnsub;': '\u2282\u20d2',
    'vnsup;': '\u2283\u20d2',
    'Vopf;': '\U0001d54d',
    'vopf;': '\U0001d567',
    'vprop;': '\u221d',
    'vrtri;': '\u22b3',
    'Vscr;': '\U0001d4b1',
    'vscr;': '\U0001d4cb',
    'vsubnE;': '\u2acb\ufe00',
    'vsubne;': '\u228a\ufe00',
    'vsupnE;': '\u2acc\ufe00',
    'vsupne;': '\u228b\ufe00',
    'Vvdash;': '\u22aa',
    'vzigzag;': '\u299a',
    'Wcirc;': '\u0174',
    'wcirc;': '\u0175',
    'wedbar;': '\u2a5f',
    'Wedge;': '\u22c0',
    'wedge;': '\u2227',
    'wedgeq;': '\u2259',
    'weierp;': '\u2118',
    'Wfr;': '\U0001d51a',
    'wfr;': '\U0001d534',
    'Wopf;': '\U0001d54e',
    'wopf;': '\U0001d568',
    'wp;': '\u2118',
    'wr;': '\u2240',
    'wreath;': '\u2240',
    'Wscr;': '\U0001d4b2',
    'wscr;': '\U0001d4cc',
    'xcap;': '\u22c2',
    'xcirc;': '\u25ef',
    'xcup;': '\u22c3',
    'xdtri;': '\u25bd',
    'Xfr;': '\U0001d51b',
    'xfr;': '\U0001d535',
    'xhArr;': '\u27fa',
    'xharr;': '\u27f7',
    'Xi;': '\u039e',
    'xi;': '\u03be',
    'xlArr;': '\u27f8',
    'xlarr;': '\u27f5',
    'xmap;': '\u27fc',
    'xnis;': '\u22fb',
    'xodot;': '\u2a00',
    'Xopf;': '\U0001d54f',
    'xopf;': '\U0001d569',
    'xoplus;': '\u2a01',
    'xotime;': '\u2a02',
    'xrArr;': '\u27f9',
    'xrarr;': '\u27f6',
    'Xscr;': '\U0001d4b3',
    'xscr;': '\U0001d4cd',
    'xsqcup;': '\u2a06',
    'xuplus;': '\u2a04',
    'xutri;': '\u25b3',
    'xvee;': '\u22c1',
    'xwedge;': '\u22c0',
    'Yacute': '\xdd',
    'yacute': '\xfd',
    'Yacute;': '\xdd',
    'yacute;': '\xfd',
    'YAcy;': '\u042f',
    'yacy;': '\u044f',
    'Ycirc;': '\u0176',
    'ycirc;': '\u0177',
    'Ycy;': '\u042b',
    'ycy;': '\u044b',
    'yen': '\xa5',
    'yen;': '\xa5',
    'Yfr;': '\U0001d51c',
    'yfr;': '\U0001d536',
    'YIcy;': '\u0407',
    'yicy;': '\u0457',
    'Yopf;': '\U0001d550',
    'yopf;': '\U0001d56a',
    'Yscr;': '\U0001d4b4',
    'yscr;': '\U0001d4ce',
    'YUcy;': '\u042e',
    'yucy;': '\u044e',
    'yuml': '\xff',
    'Yuml;': '\u0178',
    'yuml;': '\xff',
    'Zacute;': '\u0179',
    'zacute;': '\u017a',
    'Zcaron;': '\u017d',
    'zcaron;': '\u017e',
    'Zcy;': '\u0417',
    'zcy;': '\u0437',
    'Zdot;': '\u017b',
    'zdot;': '\u017c',
    'zeetrf;': '\u2128',
    'ZeroWidthSpace;': '\u200b',
    'Zeta;': '\u0396',
    'zeta;': '\u03b6',
    'Zfr;': '\u2128',
    'zfr;': '\U0001d537',
    'ZHcy;': '\u0416',
    'zhcy;': '\u0436',
    'zigrarr;': '\u21dd',
    'Zopf;': '\u2124',
    'zopf;': '\U0001d56b',
    'Zscr;': '\U0001d4b5',
    'zscr;': '\U0001d4cf',
    'zwj;': '\u200d',
    'zwnj;': '\u200c',
}


NAME2INT = {
    'AElig': 0x00c6,  # latin capital letter AE = latin capital ligature AE, U+00C6 ISOlat1
    'Aacute': 0x00c1,  # latin capital letter A with acute, U+00C1 ISOlat1
    'Acirc': 0x00c2,  # latin capital letter A with circumflex, U+00C2 ISOlat1
    'Agrave': 0x00c0,  # latin capital letter A with grave = latin capital letter A grave, U+00C0 ISOlat1
    'Alpha': 0x0391,  # greek capital letter alpha, U+0391
    'Aring': 0x00c5,  # latin capital letter A with ring above = latin capital letter A ring, U+00C5 ISOlat1
    'Atilde': 0x00c3,  # latin capital letter A with tilde, U+00C3 ISOlat1
    'Auml': 0x00c4,  # latin capital letter A with diaeresis, U+00C4 ISOlat1
    'Beta': 0x0392,  # greek capital letter beta, U+0392
    'Ccedil': 0x00c7,  # latin capital letter C with cedilla, U+00C7 ISOlat1
    'Chi': 0x03a7,  # greek capital letter chi, U+03A7
    'Dagger': 0x2021,  # double dagger, U+2021 ISOpub
    'Delta': 0x0394,  # greek capital letter delta, U+0394 ISOgrk3
    'ETH': 0x00d0,  # latin capital letter ETH, U+00D0 ISOlat1
    'Eacute': 0x00c9,  # latin capital letter E with acute, U+00C9 ISOlat1
    'Ecirc': 0x00ca,  # latin capital letter E with circumflex, U+00CA ISOlat1
    'Egrave': 0x00c8,  # latin capital letter E with grave, U+00C8 ISOlat1
    'Epsilon': 0x0395,  # greek capital letter epsilon, U+0395
    'Eta': 0x0397,  # greek capital letter eta, U+0397
    'Euml': 0x00cb,  # latin capital letter E with diaeresis, U+00CB ISOlat1
    'Gamma': 0x0393,  # greek capital letter gamma, U+0393 ISOgrk3
    'Iacute': 0x00cd,  # latin capital letter I with acute, U+00CD ISOlat1
    'Icirc': 0x00ce,  # latin capital letter I with circumflex, U+00CE ISOlat1
    'Igrave': 0x00cc,  # latin capital letter I with grave, U+00CC ISOlat1
    'Iota': 0x0399,  # greek capital letter iota, U+0399
    'Iuml': 0x00cf,  # latin capital letter I with diaeresis, U+00CF ISOlat1
    'Kappa': 0x039a,  # greek capital letter kappa, U+039A
    'Lambda': 0x039b,  # greek capital letter lambda, U+039B ISOgrk3
    'Mu': 0x039c,  # greek capital letter mu, U+039C
    'Ntilde': 0x00d1,  # latin capital letter N with tilde, U+00D1 ISOlat1
    'Nu': 0x039d,  # greek capital letter nu, U+039D
    'OElig': 0x0152,  # latin capital ligature OE, U+0152 ISOlat2
    'Oacute': 0x00d3,  # latin capital letter O with acute, U+00D3 ISOlat1
    'Ocirc': 0x00d4,  # latin capital letter O with circumflex, U+00D4 ISOlat1
    'Ograve': 0x00d2,  # latin capital letter O with grave, U+00D2 ISOlat1
    'Omega': 0x03a9,  # greek capital letter omega, U+03A9 ISOgrk3
    'Omicron': 0x039f,  # greek capital letter omicron, U+039F
    'Oslash': 0x00d8,  # latin capital letter O with stroke = latin capital letter O slash, U+00D8 ISOlat1
    'Otilde': 0x00d5,  # latin capital letter O with tilde, U+00D5 ISOlat1
    'Ouml': 0x00d6,  # latin capital letter O with diaeresis, U+00D6 ISOlat1
    'Phi': 0x03a6,  # greek capital letter phi, U+03A6 ISOgrk3
    'Pi': 0x03a0,  # greek capital letter pi, U+03A0 ISOgrk3
    'Prime': 0x2033,  # double prime = seconds = inches, U+2033 ISOtech
    'Psi': 0x03a8,  # greek capital letter psi, U+03A8 ISOgrk3
    'Rho': 0x03a1,  # greek capital letter rho, U+03A1
    'Scaron': 0x0160,  # latin capital letter S with caron, U+0160 ISOlat2
    'Sigma': 0x03a3,  # greek capital letter sigma, U+03A3 ISOgrk3
    'THORN': 0x00de,  # latin capital letter THORN, U+00DE ISOlat1
    'Tau': 0x03a4,  # greek capital letter tau, U+03A4
    'Theta': 0x0398,  # greek capital letter theta, U+0398 ISOgrk3
    'Uacute': 0x00da,  # latin capital letter U with acute, U+00DA ISOlat1
    'Ucirc': 0x00db,  # latin capital letter U with circumflex, U+00DB ISOlat1
    'Ugrave': 0x00d9,  # latin capital letter U with grave, U+00D9 ISOlat1
    'Upsilon': 0x03a5,  # greek capital letter upsilon, U+03A5 ISOgrk3
    'Uuml': 0x00dc,  # latin capital letter U with diaeresis, U+00DC ISOlat1
    'Xi': 0x039e,  # greek capital letter xi, U+039E ISOgrk3
    'Yacute': 0x00dd,  # latin capital letter Y with acute, U+00DD ISOlat1
    'Yuml': 0x0178,  # latin capital letter Y with diaeresis, U+0178 ISOlat2
    'Zeta': 0x0396,  # greek capital letter zeta, U+0396
    'aacute': 0x00e1,  # latin small letter a with acute, U+00E1 ISOlat1
    'acirc': 0x00e2,  # latin small letter a with circumflex, U+00E2 ISOlat1
    'acute': 0x00b4,  # acute accent = spacing acute, U+00B4 ISOdia
    'aelig': 0x00e6,  # latin small letter ae = latin small ligature ae, U+00E6 ISOlat1
    'agrave': 0x00e0,  # latin small letter a with grave = latin small letter a grave, U+00E0 ISOlat1
    'alefsym': 0x2135,  # alef symbol = first transfinite cardinal, U+2135 NEW
    'alpha': 0x03b1,  # greek small letter alpha, U+03B1 ISOgrk3
    'amp': 0x0026,  # ampersand, U+0026 ISOnum
    'and': 0x2227,  # logical and = wedge, U+2227 ISOtech
    'ang': 0x2220,  # angle, U+2220 ISOamso
    'aring': 0x00e5,  # latin small letter a with ring above = latin small letter a ring, U+00E5 ISOlat1
    'asymp': 0x2248,  # almost equal to = asymptotic to, U+2248 ISOamsr
    'atilde': 0x00e3,  # latin small letter a with tilde, U+00E3 ISOlat1
    'auml': 0x00e4,  # latin small letter a with diaeresis, U+00E4 ISOlat1
    'bdquo': 0x201e,  # double low-9 quotation mark, U+201E NEW
    'beta': 0x03b2,  # greek small letter beta, U+03B2 ISOgrk3
    'brvbar': 0x00a6,  # broken bar = broken vertical bar, U+00A6 ISOnum
    'bull': 0x2022,  # bullet = black small circle, U+2022 ISOpub
    'cap': 0x2229,  # intersection = cap, U+2229 ISOtech
    'ccedil': 0x00e7,  # latin small letter c with cedilla, U+00E7 ISOlat1
    'cedil': 0x00b8,  # cedilla = spacing cedilla, U+00B8 ISOdia
    'cent': 0x00a2,  # cent sign, U+00A2 ISOnum
    'chi': 0x03c7,  # greek small letter chi, U+03C7 ISOgrk3
    'circ': 0x02c6,  # modifier letter circumflex accent, U+02C6 ISOpub
    'clubs': 0x2663,  # black club suit = shamrock, U+2663 ISOpub
    'cong': 0x2245,  # approximately equal to, U+2245 ISOtech
    'copy': 0x00a9,  # copyright sign, U+00A9 ISOnum
    'crarr': 0x21b5,  # downwards arrow with corner leftwards = carriage return, U+21B5 NEW
    'cup': 0x222a,  # union = cup, U+222A ISOtech
    'curren': 0x00a4,  # currency sign, U+00A4 ISOnum
    'dArr': 0x21d3,  # downwards double arrow, U+21D3 ISOamsa
    'dagger': 0x2020,  # dagger, U+2020 ISOpub
    'darr': 0x2193,  # downwards arrow, U+2193 ISOnum
    'deg': 0x00b0,  # degree sign, U+00B0 ISOnum
    'delta': 0x03b4,  # greek small letter delta, U+03B4 ISOgrk3
    'diams': 0x2666,  # black diamond suit, U+2666 ISOpub
    'divide': 0x00f7,  # division sign, U+00F7 ISOnum
    'eacute': 0x00e9,  # latin small letter e with acute, U+00E9 ISOlat1
    'ecirc': 0x00ea,  # latin small letter e with circumflex, U+00EA ISOlat1
    'egrave': 0x00e8,  # latin small letter e with grave, U+00E8 ISOlat1
    'empty': 0x2205,  # empty set = null set = diameter, U+2205 ISOamso
    'emsp': 0x2003,  # em space, U+2003 ISOpub
    'ensp': 0x2002,  # en space, U+2002 ISOpub
    'epsilon': 0x03b5,  # greek small letter epsilon, U+03B5 ISOgrk3
    'equiv': 0x2261,  # identical to, U+2261 ISOtech
    'eta': 0x03b7,  # greek small letter eta, U+03B7 ISOgrk3
    'eth': 0x00f0,  # latin small letter eth, U+00F0 ISOlat1
    'euml': 0x00eb,  # latin small letter e with diaeresis, U+00EB ISOlat1
    'euro': 0x20ac,  # euro sign, U+20AC NEW
    'exist': 0x2203,  # there exists, U+2203 ISOtech
    'fnof': 0x0192,  # latin small f with hook = function = florin, U+0192 ISOtech
    'forall': 0x2200,  # for all, U+2200 ISOtech
    'frac12': 0x00bd,  # vulgar fraction one half = fraction one half, U+00BD ISOnum
    'frac14': 0x00bc,  # vulgar fraction one quarter = fraction one quarter, U+00BC ISOnum
    'frac34': 0x00be,  # vulgar fraction three quarters = fraction three quarters, U+00BE ISOnum
    'frasl': 0x2044,  # fraction slash, U+2044 NEW
    'gamma': 0x03b3,  # greek small letter gamma, U+03B3 ISOgrk3
    'ge': 0x2265,  # greater-than or equal to, U+2265 ISOtech
    'gt': 0x003e,  # greater-than sign, U+003E ISOnum
    'hArr': 0x21d4,  # left right double arrow, U+21D4 ISOamsa
    'harr': 0x2194,  # left right arrow, U+2194 ISOamsa
    'hearts': 0x2665,  # black heart suit = valentine, U+2665 ISOpub
    'hellip': 0x2026,  # horizontal ellipsis = three dot leader, U+2026 ISOpub
    'iacute': 0x00ed,  # latin small letter i with acute, U+00ED ISOlat1
    'icirc': 0x00ee,  # latin small letter i with circumflex, U+00EE ISOlat1
    'iexcl': 0x00a1,  # inverted exclamation mark, U+00A1 ISOnum
    'igrave': 0x00ec,  # latin small letter i with grave, U+00EC ISOlat1
    'image': 0x2111,  # blackletter capital I = imaginary part, U+2111 ISOamso
    'infin': 0x221e,  # infinity, U+221E ISOtech
    'int': 0x222b,  # integral, U+222B ISOtech
    'iota': 0x03b9,  # greek small letter iota, U+03B9 ISOgrk3
    'iquest': 0x00bf,  # inverted question mark = turned question mark, U+00BF ISOnum
    'isin': 0x2208,  # element of, U+2208 ISOtech
    'iuml': 0x00ef,  # latin small letter i with diaeresis, U+00EF ISOlat1
    'kappa': 0x03ba,  # greek small letter kappa, U+03BA ISOgrk3
    'lArr': 0x21d0,  # leftwards double arrow, U+21D0 ISOtech
    'lambda': 0x03bb,  # greek small letter lambda, U+03BB ISOgrk3
    'lang': 0x2329,  # left-pointing angle bracket = bra, U+2329 ISOtech
    'laquo': 0x00ab,  # left-pointing double angle quotation mark = left pointing guillemet, U+00AB ISOnum
    'larr': 0x2190,  # leftwards arrow, U+2190 ISOnum
    'lceil': 0x2308,  # left ceiling = apl upstile, U+2308 ISOamsc
    'ldquo': 0x201c,  # left double quotation mark, U+201C ISOnum
    'le': 0x2264,  # less-than or equal to, U+2264 ISOtech
    'lfloor': 0x230a,  # left floor = apl downstile, U+230A ISOamsc
    'lowast': 0x2217,  # asterisk operator, U+2217 ISOtech
    'loz': 0x25ca,  # lozenge, U+25CA ISOpub
    'lrm': 0x200e,  # left-to-right mark, U+200E NEW RFC 2070
    'lsaquo': 0x2039,  # single left-pointing angle quotation mark, U+2039 ISO proposed
    'lsquo': 0x2018,  # left single quotation mark, U+2018 ISOnum
    'lt': 0x003c,  # less-than sign, U+003C ISOnum
    'macr': 0x00af,  # macron = spacing macron = overline = APL overbar, U+00AF ISOdia
    'mdash': 0x2014,  # em dash, U+2014 ISOpub
    'micro': 0x00b5,  # micro sign, U+00B5 ISOnum
    'middot': 0x00b7,  # middle dot = Georgian comma = Greek middle dot, U+00B7 ISOnum
    'minus': 0x2212,  # minus sign, U+2212 ISOtech
    'mu': 0x03bc,  # greek small letter mu, U+03BC ISOgrk3
    'nabla': 0x2207,  # nabla = backward difference, U+2207 ISOtech
    'nbsp': 0x00a0,  # no-break space = non-breaking space, U+00A0 ISOnum
    'ndash': 0x2013,  # en dash, U+2013 ISOpub
    'ne': 0x2260,  # not equal to, U+2260 ISOtech
    'ni': 0x220b,  # contains as member, U+220B ISOtech
    'not': 0x00ac,  # not sign, U+00AC ISOnum
    'notin': 0x2209,  # not an element of, U+2209 ISOtech
    'nsub': 0x2284,  # not a subset of, U+2284 ISOamsn
    'ntilde': 0x00f1,  # latin small letter n with tilde, U+00F1 ISOlat1
    'nu': 0x03bd,  # greek small letter nu, U+03BD ISOgrk3
    'oacute': 0x00f3,  # latin small letter o with acute, U+00F3 ISOlat1
    'ocirc': 0x00f4,  # latin small letter o with circumflex, U+00F4 ISOlat1
    'oelig': 0x0153,  # latin small ligature oe, U+0153 ISOlat2
    'ograve': 0x00f2,  # latin small letter o with grave, U+00F2 ISOlat1
    'oline': 0x203e,  # overline = spacing overscore, U+203E NEW
    'omega': 0x03c9,  # greek small letter omega, U+03C9 ISOgrk3
    'omicron': 0x03bf,  # greek small letter omicron, U+03BF NEW
    'oplus': 0x2295,  # circled plus = direct sum, U+2295 ISOamsb
    'or': 0x2228,  # logical or = vee, U+2228 ISOtech
    'ordf': 0x00aa,  # feminine ordinal indicator, U+00AA ISOnum
    'ordm': 0x00ba,  # masculine ordinal indicator, U+00BA ISOnum
    'oslash': 0x00f8,  # latin small letter o with stroke, = latin small letter o slash, U+00F8 ISOlat1
    'otilde': 0x00f5,  # latin small letter o with tilde, U+00F5 ISOlat1
    'otimes': 0x2297,  # circled times = vector product, U+2297 ISOamsb
    'ouml': 0x00f6,  # latin small letter o with diaeresis, U+00F6 ISOlat1
    'para': 0x00b6,  # pilcrow sign = paragraph sign, U+00B6 ISOnum
    'part': 0x2202,  # partial differential, U+2202 ISOtech
    'permil': 0x2030,  # per mille sign, U+2030 ISOtech
    'perp': 0x22a5,  # up tack = orthogonal to = perpendicular, U+22A5 ISOtech
    'phi': 0x03c6,  # greek small letter phi, U+03C6 ISOgrk3
    'pi': 0x03c0,  # greek small letter pi, U+03C0 ISOgrk3
    'piv': 0x03d6,  # greek pi symbol, U+03D6 ISOgrk3
    'plusmn': 0x00b1,  # plus-minus sign = plus-or-minus sign, U+00B1 ISOnum
    'pound': 0x00a3,  # pound sign, U+00A3 ISOnum
    'prime': 0x2032,  # prime = minutes = feet, U+2032 ISOtech
    'prod': 0x220f,  # n-ary product = product sign, U+220F ISOamsb
    'prop': 0x221d,  # proportional to, U+221D ISOtech
    'psi': 0x03c8,  # greek small letter psi, U+03C8 ISOgrk3
    'quot': 0x0022,  # quotation mark = APL quote, U+0022 ISOnum
    'rArr': 0x21d2,  # rightwards double arrow, U+21D2 ISOtech
    'radic': 0x221a,  # square root = radical sign, U+221A ISOtech
    'rang': 0x232a,  # right-pointing angle bracket = ket, U+232A ISOtech
    'raquo': 0x00bb,  # right-pointing double angle quotation mark = right pointing guillemet, U+00BB ISOnum
    'rarr': 0x2192,  # rightwards arrow, U+2192 ISOnum
    'rceil': 0x2309,  # right ceiling, U+2309 ISOamsc
    'rdquo': 0x201d,  # right double quotation mark, U+201D ISOnum
    'real': 0x211c,  # blackletter capital R = real part symbol, U+211C ISOamso
    'reg': 0x00ae,  # registered sign = registered trade mark sign, U+00AE ISOnum
    'rfloor': 0x230b,  # right floor, U+230B ISOamsc
    'rho': 0x03c1,  # greek small letter rho, U+03C1 ISOgrk3
    'rlm': 0x200f,  # right-to-left mark, U+200F NEW RFC 2070
    'rsaquo': 0x203a,  # single right-pointing angle quotation mark, U+203A ISO proposed
    'rsquo': 0x2019,  # right single quotation mark, U+2019 ISOnum
    'sbquo': 0x201a,  # single low-9 quotation mark, U+201A NEW
    'scaron': 0x0161,  # latin small letter s with caron, U+0161 ISOlat2
    'sdot': 0x22c5,  # dot operator, U+22C5 ISOamsb
    'sect': 0x00a7,  # section sign, U+00A7 ISOnum
    'shy': 0x00ad,  # soft hyphen = discretionary hyphen, U+00AD ISOnum
    'sigma': 0x03c3,  # greek small letter sigma, U+03C3 ISOgrk3
    'sigmaf': 0x03c2,  # greek small letter final sigma, U+03C2 ISOgrk3
    'sim': 0x223c,  # tilde operator = varies with = similar to, U+223C ISOtech
    'spades': 0x2660,  # black spade suit, U+2660 ISOpub
    'sub': 0x2282,  # subset of, U+2282 ISOtech
    'sube': 0x2286,  # subset of or equal to, U+2286 ISOtech
    'sum': 0x2211,  # n-ary sumation, U+2211 ISOamsb
    'sup': 0x2283,  # superset of, U+2283 ISOtech
    'sup1': 0x00b9,  # superscript one = superscript digit one, U+00B9 ISOnum
    'sup2': 0x00b2,  # superscript two = superscript digit two = squared, U+00B2 ISOnum
    'sup3': 0x00b3,  # superscript three = superscript digit three = cubed, U+00B3 ISOnum
    'supe': 0x2287,  # superset of or equal to, U+2287 ISOtech
    'szlig': 0x00df,  # latin small letter sharp s = ess-zed, U+00DF ISOlat1
    'tau': 0x03c4,  # greek small letter tau, U+03C4 ISOgrk3
    'there4': 0x2234,  # therefore, U+2234 ISOtech
    'theta': 0x03b8,  # greek small letter theta, U+03B8 ISOgrk3
    'thetasym': 0x03d1,  # greek small letter theta symbol, U+03D1 NEW
    'thinsp': 0x2009,  # thin space, U+2009 ISOpub
    'thorn': 0x00fe,  # latin small letter thorn with, U+00FE ISOlat1
    'tilde': 0x02dc,  # small tilde, U+02DC ISOdia
    'times': 0x00d7,  # multiplication sign, U+00D7 ISOnum
    'trade': 0x2122,  # trade mark sign, U+2122 ISOnum
    'uArr': 0x21d1,  # upwards double arrow, U+21D1 ISOamsa
    'uacute': 0x00fa,  # latin small letter u with acute, U+00FA ISOlat1
    'uarr': 0x2191,  # upwards arrow, U+2191 ISOnum
    'ucirc': 0x00fb,  # latin small letter u with circumflex, U+00FB ISOlat1
    'ugrave': 0x00f9,  # latin small letter u with grave, U+00F9 ISOlat1
    'uml': 0x00a8,  # diaeresis = spacing diaeresis, U+00A8 ISOdia
    'upsih': 0x03d2,  # greek upsilon with hook symbol, U+03D2 NEW
    'upsilon': 0x03c5,  # greek small letter upsilon, U+03C5 ISOgrk3
    'uuml': 0x00fc,  # latin small letter u with diaeresis, U+00FC ISOlat1
    'weierp': 0x2118,  # script capital P = power set = Weierstrass p, U+2118 ISOamso
    'xi': 0x03be,  # greek small letter xi, U+03BE ISOgrk3
    'yacute': 0x00fd,  # latin small letter y with acute, U+00FD ISOlat1
    'yen': 0x00a5,  # yen sign = yuan sign, U+00A5 ISOnum
    'yuml': 0x00ff,  # latin small letter y with diaeresis, U+00FF ISOlat1
    'zeta': 0x03b6,  # greek small letter zeta, U+03B6 ISOgrk3
    'zwj': 0x200d,  # zero width joiner, U+200D NEW RFC 2070
    'zwnj': 0x200c,  # zero width non-joiner, U+200C NEW RFC 2070
}


INVALID_CHARREFS = {
    0x00: '\ufffd',  # REPLACEMENT CHARACTER
    0x0d: '\r',      # CARRIAGE RETURN
    0x80: '\u20ac',  # EURO SIGN
    0x81: '\x81',    # <control>
    0x82: '\u201a',  # SINGLE LOW-9 QUOTATION MARK
    0x83: '\u0192',  # LATIN SMALL LETTER F WITH HOOK
    0x84: '\u201e',  # DOUBLE LOW-9 QUOTATION MARK
    0x85: '\u2026',  # HORIZONTAL ELLIPSIS
    0x86: '\u2020',  # DAGGER
    0x87: '\u2021',  # DOUBLE DAGGER
    0x88: '\u02c6',  # MODIFIER LETTER CIRCUMFLEX ACCENT
    0x89: '\u2030',  # PER MILLE SIGN
    0x8a: '\u0160',  # LATIN CAPITAL LETTER S WITH CARON
    0x8b: '\u2039',  # SINGLE LEFT-POINTING ANGLE QUOTATION MARK
    0x8c: '\u0152',  # LATIN CAPITAL LIGATURE OE
    0x8d: '\x8d',    # <control>
    0x8e: '\u017d',  # LATIN CAPITAL LETTER Z WITH CARON
    0x8f: '\x8f',    # <control>
    0x90: '\x90',    # <control>
    0x91: '\u2018',  # LEFT SINGLE QUOTATION MARK
    0x92: '\u2019',  # RIGHT SINGLE QUOTATION MARK
    0x93: '\u201c',  # LEFT DOUBLE QUOTATION MARK
    0x94: '\u201d',  # RIGHT DOUBLE QUOTATION MARK
    0x95: '\u2022',  # BULLET
    0x96: '\u2013',  # EN DASH
    0x97: '\u2014',  # EM DASH
    0x98: '\u02dc',  # SMALL TILDE
    0x99: '\u2122',  # TRADE MARK SIGN
    0x9a: '\u0161',  # LATIN SMALL LETTER S WITH CARON
    0x9b: '\u203a',  # SINGLE RIGHT-POINTING ANGLE QUOTATION MARK
    0x9c: '\u0153',  # LATIN SMALL LIGATURE OE
    0x9d: '\x9d',    # <control>
    0x9e: '\u017e',  # LATIN SMALL LETTER Z WITH CARON
    0x9f: '\u0178',  # LATIN CAPITAL LETTER Y WITH DIAERESIS
}


# CHARACTER LISTS


ARROWS = (
    r'←', r'↑', r'→', r'↓', r'↔', r'↕', r'↖', r'↗', r'↘', r'↙', r'↜', r'↝', r'↞', r'↟', r'↠',
    r'↡', r'↢', r'↣', r'↤', r'↥', r'↦', r'↧', r'↨', r'↩', r'↪', r'↫', r'↬', r'↭', r'↯', r'↰',
    r'↱', r'↲', r'↳', r'↴', r'↵', r'↶', r'↷', r'↸', r'↹', r'↺', r'↻', r'↼', r'↽', r'↾', r'↿',
    r'⇀', r'⇁', r'⇂', r'⇃', r'⇄', r'⇅', r'⇆', r'⇇', r'⇈', r'⇉', r'⇊', r'⇋', r'⇌', r'⇐', r'⇑',
    r'⇒', r'⇓', r'⇔', r'⇕', r'⇖', r'⇗', r'⇘', r'⇙', r'⇚', r'⇛', r'⇜', r'⇝', r'⇞', r'⇟', r'⇠',
    r'⇡', r'⇢', r'⇣', r'⇤', r'⇥', r'⇦', r'⇧', r'⇨', r'⇩', r'⇪', r'⇫', r'⇬', r'⇭', r'⇮', r'⇯',
    r'⇰', r'⇱', r'⇲', r'⇳', r'⇴', r'⇵', r'⇶', r'⇷', r'⇸', r'⇹', r'⇺', r'⇻', r'⇼', r'⇽', r'⇾',
    r'⇿', r'⏎', r'➔', r'➘', r'➙', r'➚', r'➛', r'➜', r'➝', r'➞', r'➟', r'➠', r'➡', r'➢', r'➣',
    r'➤', r'➥', r'➦', r'➧', r'➨', r'➩', r'➪', r'➫', r'➬', r'➭', r'➮', r'➯', r'➱', r'➲', r'➳',
    r'➴', r'➵', r'➶', r'➷', r'➸', r'➹', r'➺', r'➻', r'➼', r'➽', r'➾', r'⟲', r'⟳', r'⟴', r'⟵',
    r'⟶', r'⟷', r'⟸', r'⟹', r'⟺', r'⟻', r'⟼', r'⟽', r'⟾', r'⟿', r'⤀', r'⤁', r'⤂', r'⤃',
    r'⤄', r'⤅', r'⤆', r'⤇', r'⤈', r'⤉', r'⤊', r'⤋', r'⤌', r'⤍', r'⤎', r'⤏', r'⤐', r'⤑',
    r'⤒', r'⤓', r'⤔', r'⤕', r'⤖', r'⤗', r'⤘', r'⤙', r'⤚', r'⤛', r'⤜', r'⤝', r'⤞', r'⤟',
    r'⤠', r'⤡', r'⤢', r'⤣', r'⤤', r'⤥', r'⤦', r'⤧', r'⤨', r'⤩', r'⤪', r'⤫', r'⤬', r'⤭',
    r'⤮', r'⤯', r'⤰', r'⤱', r'⤲', r'⤳', r'⤴', r'⤵', r'⤶', r'⤷', r'⤸', r'⤹', r'⤺', r'⤻',
    r'⤼', r'⤽', r'⤾', r'⤿', r'⥀', r'⥁', r'⥂', r'⥃', r'⥄', r'⥅', r'⥆', r'⥇', r'⥈', r'⥉',
    r'⥊', r'⥋', r'⥌', r'⥍', r'⥎', r'⥏', r'⥐', r'⥑', r'⥒', r'⥓', r'⥔', r'⥕', r'⥖', r'⥗',
    r'⥘', r'⥙', r'⥚', r'⥛', r'⥜', r'⥝', r'⥞', r'⥟', r'⥠', r'⥡', r'⥢', r'⥣', r'⥤', r'⥥',
    r'⥦', r'⥧', r'⥨', r'⥩', r'⥪', r'⥫', r'⥬', r'⥭', r'⥮', r'⥯', r'⥰', r'⥱', r'⥲', r'⥳',
    r'⥴', r'⥵', r'⥶', r'⥷', r'⥸', r'⥹', r'⥺', r'⥻', r'⬀', r'⬁', r'⬂', r'⬃', r'⬄', r'⬅',
    r'⬆', r'⬇', r'⬈', r'⬉', r'⬊', r'⬋', r'⬌', r'⬍', r'⬎', r'⬏', r'⬐', r'⬑'
)


ASTROLOGY = (r'☉', r'☽', r'☿', r'♀', r'♁', r'♂', r'⚳', r'♃', r'♄', r'♅', r'⛢', r'♆', r'♇')


BRAILLE = (
    r'⠀', r'⠁', r'⠂', r'⠃', r'⠄', r'⠅', r'⠆', r'⠇', r'⠈', r'⠉', r'⠊', r'⠋', r'⠌', r'⠍', r'⠎',
    r'⠏', r'⠐', r'⠑', r'⠒', r'⠓', r'⠔', r'⠕', r'⠖', r'⠗', r'⠘', r'⠙', r'⠚', r'⠛', r'⠜', r'⠝',
    r'⠞', r'⠟', r'⠠', r'⠡', r'⠢', r'⠣', r'⠤', r'⠥', r'⠦', r'⠧', r'⠨', r'⠩', r'⠪', r'⠫', r'⠬',
    r'⠭', r'⠮', r'⠯', r'⠰', r'⠱', r'⠲', r'⠳', r'⠴', r'⠵', r'⠶', r'⠷', r'⠸', r'⠹', r'⠺', r'⠻',
    r'⠼', r'⠽', r'⠾', r'⠿', r'⡀', r'⡁', r'⡂', r'⡃', r'⡄', r'⡅', r'⡆', r'⡇', r'⡈', r'⡉', r'⡊',
    r'⡋', r'⡌', r'⡍', r'⡎', r'⡏', r'⡐', r'⡑', r'⡒', r'⡓', r'⡔', r'⡕', r'⡖', r'⡗', r'⡘', r'⡙',
    r'⡚', r'⡛', r'⡜', r'⡝', r'⡞', r'⡟', r'⡠', r'⡡', r'⡢', r'⡣', r'⡤', r'⡥', r'⡦', r'⡧', r'⡨',
    r'⡩', r'⡪', r'⡫', r'⡬', r'⡭', r'⡮', r'⡯', r'⡰', r'⡱', r'⡲', r'⡳', r'⡴', r'⡵', r'⡶', r'⡷',
    r'⡸', r'⡹', r'⡺', r'⡻', r'⡼', r'⡽', r'⡾', r'⡿', r'⢀', r'⢁', r'⢂', r'⢃', r'⢄', r'⢅', r'⢆',
    r'⢇', r'⢈', r'⢉', r'⢊', r'⢋', r'⢌', r'⢍', r'⢎', r'⢏', r'⢐', r'⢑', r'⢒', r'⢓', r'⢔', r'⢕',
    r'⢖', r'⢗', r'⢘', r'⢙', r'⢚', r'⢛', r'⢜', r'⢝', r'⢞', r'⢟', r'⢠', r'⢡', r'⢢', r'⢣', r'⢤',
    r'⢥', r'⢦', r'⢧', r'⢨', r'⢩', r'⢪', r'⢫', r'⢬', r'⢭', r'⢮', r'⢯', r'⢰', r'⢱', r'⢲', r'⢳',
    r'⢴', r'⢵', r'⢶', r'⢷', r'⢸', r'⢹', r'⢺', r'⢻', r'⢼', r'⢽', r'⢾', r'⢿', r'⣀', r'⣁', r'⣂',
    r'⣃', r'⣄', r'⣅', r'⣆', r'⣇', r'⣈', r'⣉', r'⣊', r'⣋', r'⣌', r'⣍', r'⣎', r'⣏', r'⣐', r'⣑',
    r'⣒', r'⣓', r'⣔', r'⣕', r'⣖', r'⣗', r'⣘', r'⣙', r'⣚', r'⣛', r'⣜', r'⣝', r'⣞', r'⣟', r'⣠',
    r'⣡', r'⣢', r'⣣', r'⣤', r'⣥', r'⣦', r'⣧', r'⣨', r'⣩', r'⣪', r'⣫', r'⣬', r'⣭', r'⣮', r'⣯',
    r'⣰', r'⣱', r'⣲', r'⣳', r'⣴', r'⣵', r'⣶', r'⣷', r'⣸', r'⣹', r'⣺', r'⣻', r'⣼', r'⣽', r'⣾',
    r'⣿'
)


CARDS = (r'♠', r'♡', r'♢', r'♣', r'♤', r'♥', r'♦', r'♧')


CHESS = (r'♔', r'♕', r'♖', r'♗', r'♘', r'♙', r'♚', r'♛', r'♜', r'♝', r'♞', r'♟')


CHESS_BLACK = (r'♚', r'♛', r'♜', r'♝', r'♞', r'♟')


CHESS_WHITE = (r'♔', r'♕', r'♖', r'♗', r'♘', r'♙')


CONTROL_SYM = (
    r'␀', r'␁', r'␂', r'␃', r'␄', r'␅', r'␆', r'␇', r'␈', r'␉', r'␊', r'␋', r'␌', r'␍', r'␎',
    r'␏', r'␐', r'␑', r'␒', r'␓', r'␔', r'␕', r'␖', r'␗', r'␘', r'␙', r'␚', r'␛', r'␜', r'␝',
    r'␞', r'␟', r'␠', r'␡'
)


CONTROL_SYM_NAME = {
    'NUL': '␀',
    'SOH': '␁',
    'STX': '␂',
    'ETX': '␃',
    'EOT': '␄',
    'ENQ': '␅',
    'ACK': '␆',
    'BEL': '␇',
    'BS': '␈',
    'HT': '␉',
    'LF': '␊',
    'VT': '␋',
    'FF': '␌',
    'CR': '␍',
    'SO': '␎',
    'SI': '␏',
    'DLE': '␐',
    'DC1': '␑',
    'DC2': '␒',
    'DC3': '␓',
    'DC4': '␔',
    'NAK': '␕',
    'SYN': '␖',
    'ETB': '␗',
    'CAN': '␘',
    'EM': '␙',
    'SUB': '␚',
    'ESC': '␛',
    'GS': '␜',
    'FS': '␝',
    'RS': '␞',
    'US': '␟',
    'SP': '␠',
    'DEL': '␡'
}


CURRENCY = (
    r'¤', r'₳', r'฿', r'₵', r'¢', r'₡', r'₢', r'$', r'₫', r'₯', r'₠', r'€', r'ƒ', r'₣',
    r'₲', r'₴', r'₭', r'₺', r'ℳ', r'₥', r'₦', r'₧', r'₱', r'₰', r'£', r'៛', r'₽', r'₹',
    r'₨', r'₪', r'৳', r'₸', r'₮', r'₩', r'¥'
)


CYRILLIC_ALPHABET = (
    r'А', r'Б', r'В', r'Г', r'Д', r'Е', r'Ё', r'Ж', r'З', r'И', r'Й', r'К', r'Л', r'М',
    r'Н', r'О', r'П', r'Р', r'С', r'Т', r'У', r'Ф', r'Х', r'Ц', r'Ч',
    r'а', r'б', r'в', r'г', r'д', r'е', r'ё', r'ж', r'з', r'и', r'й', r'к', r'л', r'м',
    r'н', r'о', r'п', r'р', r'с', r'т', r'у', r'ф', r'х', r'ц', r'ч'
)


DICE = (r'⚀', r'⚁', r'⚂', r'⚃', r'⚄', r'⚅')


END_PUNCT = (r'…', r'¿', r'¡', r'‽', r'⸮')


FACES = (
    r'😁', r'😂', r'😃', r'😄', r'😅', r'😆', r'😇', r'😈', r'😉', r'😊', r'😋', r'😌', r'😍',
    r'😎', r'😏', r'😐', r'😒', r'😓', r'😔', r'😖', r'😘', r'😚', r'😜', r'😝', r'😞', r'😠',
    r'😡', r'😢', r'😣', r'😥', r'😨', r'😩', r'😪', r'😫', r'😭', r'😰', r'😱', r'😲', r'😳',
    r'😵', r'😶', r'😷', r'😸', r'😹', r'😺', r'😻', r'😼', r'😽', r'😾', r'😿', r'🙀', r'🙁',
    r'🙂', r'🙃', r'🙄', r'🙅', r'🙆', r'🙇', r'🙈', r'🙉', r'🙊', r'🙋', r'🙌', r'🙍', r'🙎',
    r'🙏', r'👦', r'👧', r'👨', r'👩', r'👮', r'👯', r'👰', r'👱', r'👲', r'👳', r'👴', r'👵',
    r'👶', r'👷', r'👸', r'👹', r'👺', r'👼', r'👽', r'👾', r'👿', r'💀', r'💁', r'💂'
)


INTELLECTUAL_PROPERTY = (r'©', r'℗', r'®', r'℠', r'™')


LOGIC = (r'⇒', r'→', r'⊃', r'⇔', r'≡', r'↔', r'¬', r'∥', r'⊕', r'⊻', r'⊥', r'∃', r'≔', r'≡', r'⊢', r'⊨')


MATH = (
    r'÷', r'×', r'±', r'∓', r'√', r'∛', r'∜', r'∫', r'∮', r'∯', r'∰', r'∴', r'∵', r'∝', r'∞',
    r'≈', r'≅', r'♎', r'π', r'≪', r'≫', r'≤', r'≥', r'≦', r'≧'
)


MUSIC = (
    r'𝄀', r'𝄁', r'𝄂', r'𝄃', r'𝄄', r'𝄅', r'𝄆', r'𝄇', r'𝄈', r'𝄉', r'𝄊', r'𝄋', r'𝄌', r'𝄍', r'𝄎', r'𝄏',
    r'𝄐', r'𝄑', r'𝄒', r'𝄓', r'𝄔', r'𝄕', r'𝄖', r'𝄗', r'𝄘', r'𝄙', r'𝄚', r'𝄛', r'𝄜', r'𝄝', r'𝄞',
    r'𝄟', r'𝄠', r'𝄡', r'𝄢', r'𝄣', r'𝄤', r'𝄥', r'𝄦', r'𝄩', r'𝄪', r'𝄫', r'𝄬', r'𝄭', r'𝄮', r'𝄯',
    r'𝄰', r'𝄱', r'𝄲', r'𝄳', r'𝄴', r'𝄵', r'𝄶', r'𝄷', r'𝄸', r'𝄹', r'𝄺', r'𝄻', r'𝄼', r'𝄽', r'𝄾',
    r'𝄿', r'𝅀', r'𝅁', r'𝅂', r'𝅃', r'𝅄', r'𝅅', r'𝅆', r'𝅇', r'𝅈', r'𝅉', r'𝅊', r'𝅋', r'𝅌', r'𝅍', r'𝅎',
    r'𝅏', r'𝅐', r'𝅑', r'𝅒', r'𝅓', r'𝅔', r'𝅕', r'𝅖', r'𝅗', r'𝅘', r'𝅚', r'𝅛', r'𝅜', r'𝅝', r'𝅗𝅥', r'♩',
    r'♪', r'♫', r'♬', r'𝅘𝅥', r'𝅘𝅥𝅮', r'𝅘𝅥𝅯', r'𝅘𝅥𝅰', r'𝅘𝅥𝅱', r'𝅘𝅥𝅲', r'𝅥', r'𝅦', r'𝅧', r'𝅨', r'𝅩', r'𝅪', r'𝅫',
    r'𝅬', r'𝅭', r'𝅮', r'𝅯', r'𝅰', r'𝅱', r'𝅲', r'𝅻', r'𝅼', r'𝅽', r'𝅾', r'𝅿', r'𝆀', r'𝆁', r'𝆂', r'𝆃', r'𝆄', r'𝆅',
    r'𝆆', r'𝆇', r'𝆈', r'𝆉', r'𝆊', r'𝆋', r'𝆌', r'𝆍', r'𝆎', r'𝆏', r'𝆐', r'𝆑', r'𝆒', r'𝆓', r'𝆔', r'𝆕',
    r'𝆖', r'𝆗', r'𝆘', r'𝆙', r'𝆚', r'𝆛', r'𝆜', r'𝆝', r'𝆞', r'𝆟', r'𝆠', r'𝆡', r'𝆢', r'𝆣', r'𝆤', r'𝆥',
    r'𝆦', r'𝆧', r'𝆨', r'𝆩', r'𝆪', r'𝆫', r'𝆬', r'𝆭', r'𝆮', r'𝆯', r'𝆰', r'𝆱', r'𝆲', r'𝆳', r'𝆴', r'𝆵',
    r'𝆶', r'𝆷', r'𝆸', r'𝆹', r'𝆺', r'𝆹𝅥', r'𝆺𝅥', r'𝆹𝅥𝅮', r'𝆺𝅥𝅮', r'𝆹𝅥𝅯', r'𝆺𝅥𝅯', r'𝇁', r'𝇂', r'𝇃', r'𝇄', r'𝇅', r'𝇆',
    r'𝇇', r'𝇈', r'𝇉', r'𝇊', r'𝇋', r'𝇌', r'𝇍', r'𝇎', r'𝇏', r'𝇐', r'𝇑', r'𝇒', r'𝇓', r'𝇔', r'𝇕', r'𝇖',
    r'𝇗', r'𝇘', r'𝇙', r'𝇚', r'𝇛', r'𝇜', r'𝇝', r'𝇞', r'𝇟'
)


PARENTHESIS_CHAR = (
    r'⑴', r'⑵', r'⑶', r'⑷', r'⑸', r'⑹', r'⑺', r'⑻', r'⑼', r'⑽', r'⑾', r'⑿', r'⒀',
    r'⒁', r'⒂', r'⒃', r'⒄', r'⒅', r'⒆', r'⒇', r'⒜', r'⒝', r'⒞', r'⒟', r'⒠', r'⒡',
    r'⒢', r'⒣', r'⒤', r'⒥', r'⒦', r'⒧', r'⒨', r'⒩', r'⒪', r'⒫', r'⒬', r'⒭', r'⒮',
    r'⒯', r'⒰', r'⒱', r'⒲', r'⒳', r'⒴', r'⒵'
)


PLANETS = {
    'SUN': '☉',
    'MOON': '☽',
    'MERCURY': '☿',
    'VENUS': '♀',
    'EARTH': '♁',
    'MARS': '♂',
    'CERES': '⚳',
    'JUPITER': '♃',
    'SATURN': '♄',
    'URANUS': '♅',
    'NEPTUNE': '♆',
    'PLUTO': '♇'
}


PLAYING_CARDS = (
    r'🂡', r'🂱', r'🃁', r'🃑',
    r'🂢', r'🂲', r'🃂', r'🃒',
    r'🂣', r'🂳', r'🃃', r'🃓',
    r'🂤', r'🂴', r'🃄', r'🃔',
    r'🂥', r'🂵', r'🃅', r'🃕',
    r'🂦', r'🂶', r'🃆', r'🃖',
    r'🂧', r'🂷', r'🃇', r'🃗',
    r'🂨', r'🂸', r'🃈', r'🃘',
    r'🂩', r'🂹', r'🃉', r'🃙',
    r'🂪', r'🂺', r'🃊', r'🃚',
    r'🂫', r'🂻', r'🃋', r'🃛',
    r'🂭', r'🂽', r'🃍', r'🃝',
    r'🂮', r'🂾', r'🃎', r'🃞'
)


PLAYING_CARDS_52 = (
    r'🂡', r'🂱', r'🃁', r'🃑',
    r'🂢', r'🂲', r'🃂', r'🃒',
    r'🂣', r'🂳', r'🃃', r'🃓',
    r'🂤', r'🂴', r'🃄', r'🃔',
    r'🂥', r'🂵', r'🃅', r'🃕',
    r'🂦', r'🂶', r'🃆', r'🃖',
    r'🂧', r'🂷', r'🃇', r'🃗',
    r'🂨', r'🂸', r'🃈', r'🃘',
    r'🂩', r'🂹', r'🃉', r'🃙',
    r'🂪', r'🂺', r'🃊', r'🃚',
    r'🂫', r'🂻', r'🃋', r'🃛',
    r'🂭', r'🂽', r'🃍', r'🃝',
    r'🂮', r'🂾', r'🃎', r'🃞',
    r'🃏', r'🃟'
)


PLAYING_CARDS_56 = (
    r'🂡', r'🂱', r'🃁', r'🃑',
    r'🂢', r'🂲', r'🃂', r'🃒',
    r'🂣', r'🂳', r'🃃', r'🃓',
    r'🂤', r'🂴', r'🃄', r'🃔',
    r'🂥', r'🂵', r'🃅', r'🃕',
    r'🂦', r'🂶', r'🃆', r'🃖',
    r'🂧', r'🂷', r'🃇', r'🃗',
    r'🂨', r'🂸', r'🃈', r'🃘',
    r'🂩', r'🂹', r'🃉', r'🃙',
    r'🂪', r'🂺', r'🃊', r'🃚',
    r'🂫', r'🂻', r'🃋', r'🃛',
    r'🂭', r'🂽', r'🃍', r'🃝',
    r'🂮', r'🂾', r'🃎', r'🃞',
    r'🃏', r'🃟',
    r'🂬', r'🂼', r'🃌', r'🃜'  # Chevalier/Knight
)


CARDS_ACE = (r'🂡', r'🂱', r'🃁', r'🃑')


CARDS_2 = (r'🂢', r'🂲', r'🃂', r'🃒')


CARDS_3 = (r'🂣', r'🂳', r'🃃', r'🃓')


CARDS_4 = (r'🂤', r'🂴', r'🃄', r'🃔')


CARDS_5 = (r'🂥', r'🂵', r'🃅', r'🃕')


CARDS_6 = (r'🂦', r'🂶', r'🃆', r'🃖')


CARDS_7 = (r'🂧', r'🂷', r'🃇', r'🃗')


CARDS_8 = (r'🂨', r'🂸', r'🃈', r'🃘')


CARDS_9 = (r'🂩', r'🂹', r'🃉', r'🃙')


CARDS_10 = (r'🂪', r'🂺', r'🃊', r'🃚')


CARDS_JACK = (r'🂫', r'🂻', r'🃋', r'🃛')


CARDS_QUEEN = (r'🂭', r'🂽', r'🃍', r'🃝')


CARDS_KING = (r'🂮', r'🂾', r'🃎', r'🃞')


CARDS_JOKER = (r'🃏', r'🃟')


CARDS_CHEVALIER = (r'🂬', r'🂼', r'🃌', r'🃜')  # Chevalier/Knight


RECYCLE = (r'♲', r'♳', r'♴', r'♵', r'♶', r'♷', r'♸', r'♹', r'♺', r'♻', r'♼', r'♽')


SCIENCE = (r'⚕', r'⚗', r'⚘', r'⚙', r'⚛', r'☢', r'☣', r'☤', r'⌬')


SUPERSCRIPT_NUM = (r'¹', r'²', r'³', r'⁴', r'⁵', r'⁶', r'⁷', r'⁸', r'⁹')


ZODIAC = (r'♈', r'♉', r'♊', r'♋', r'♌', r'♍', r'♎', r'♏', r'♐', r'♑', r'♒', r'♓')


ZODIAC_SIGNS = {
    'Aries': '♈',
    'Taurus': '♉',
    'Gemini': '♊',
    'Cancer': '♋',
    'Leo': '♌',
    'Virgo': '♍',
    'Libra': '♎',
    'Scorpio': '♏',
    'Sagittarius': '♐',
    'Capricorn': '♑',
    'Aquarius': '♒',
    'Pisces': '♓'
}


# GREEK CHARACTERS


GREEK_UPPER = (
    r'Α', r'Β', r'Γ', r'Δ', r'Ε', r'Ζ', r'Η', r'Θ', r'Ι', r'Κ', r'Λ', r'Μ', r'Ν',
    r'Ξ', r'Ο', r'Π', r'Ρ', r'Σ', r'Τ', r'Υ', r'Φ', r'Χ', r'Ψ', r'Ω'
)


GREEK_LOWER = (
    r'α', r'β', r'γ', r'δ', r'ε', r'ζ', r'η', r'θ', r'ι', r'κ', r'λ', r'μ', r'ν',
    r'ξ', r'ο', r'π', r'ρ', r'σ', r'ς', r'τ', r'υ', r'φ', r'χ', r'ψ', r'ω'
)


GREEK_ARCHAIC_UPPER = (r'Ϝ', r'Ϛ', r'Ϟ', r'Ϙ', r'Ϡ')


GREEK_ARCHAIC_LOWER = (r'ϝ', r'ϛ', r'ϟ', r'ϙ', r'ϡ', r'ϳ', r'ϗ', r'϶')


GREEK_ACCENT_UPPER = (
    r'Ἀ', r'Ἁ', r'Ἂ', r'Ἃ', r'Ἄ', r'Ἅ', r'Ἆ', r'Ἇ',
    r'ᾈ', r'ᾉ', r'ᾊ', r'ᾋ', r'ᾌ', r'ᾍ', r'ᾎ', r'ᾏ', r'Ᾰ', r'Ᾱ', r'Ὰ', r'Ά', r'ᾼ',
    r'Ἐ', r'Ἑ', r'Ἒ', r'Ἓ', r'Ἔ', r'Ἕ', r'Ὲ', r'Έ',
    r'Ἠ', r'Ἡ', r'Ἢ', r'Ἣ', r'Ἤ', r'Ἥ', r'Ἦ', r'Ἧ',
    r'ᾘ', r'ᾙ', r'ᾚ', r'ᾛ', r'ᾜ', r'ᾝ', r'ᾞ', r'ᾟ', r'Ὴ', r'Ή', r'ῌ',
    r'Ἰ', r'Ἱ', r'Ἲ', r'Ἳ', r'Ἴ', r'Ἵ', r'Ἶ', r'Ἷ', r'Ῐ', r'Ῑ', r'Ὶ', r'Ί',
    r'Ὀ', r'Ὁ', r'Ὂ', r'Ὃ', r'Ὄ', r'Ὅ', r'Ὸ', r'Ό',
    r'Ῥ',
    r'Ὑ', r'Ὓ', r'Ὕ', r'Ὗ', r'Ῠ', r'Ῡ', r'Ὺ', r'Ύ',
    r'Ὠ', r'Ὡ', r'Ὢ', r'Ὣ', r'Ὤ', r'Ὥ', r'Ὦ', r'Ὧ',
    r'ᾨ', r'ᾩ', r'ᾪ', r'ᾫ', r'ᾬ', r'ᾭ', r'ᾮ', r'ᾯ', r'Ὼ', r'Ώ', r'ῼ',
)


GREEK_ACCENT_LOWER = (
    r'ἀ', r'ἁ', r'ἂ', r'ἃ', r'ἄ', r'ἅ', r'ἆ', r'ἇ', r'ὰ', r'ά',
    r'ᾀ', r'ᾁ', r'ᾂ', r'ᾃ', r'ᾄ', r'ᾅ', r'ᾆ', r'ᾇ', r'ᾰ', r'ᾱ', r'ᾲ', r'ᾳ', r'ᾴ', r'ᾶ', r'ᾷ',
    r'ἐ', r'ἑ', r'ἒ', r'ἓ', r'ἔ', r'ἕ', r'ὲ', r'έ',
    r'ἠ', r'ἡ', r'ἢ', r'ἣ', r'ἤ', r'ἥ', r'ἦ', r'ἧ', r'ὴ', r'ή', r'ῆ',
    r'ᾐ', r'ᾑ', r'ᾒ', r'ᾓ', r'ᾔ', r'ᾕ', r'ᾖ', r'ᾗ', r'ῂ', r'ῃ', r'ῄ', r'ῇ',
    r'ἰ', r'ἱ', r'ἲ', r'ἳ', r'ἴ', r'ἵ', r'ἶ', r'ἷ',
    r'ὶ', r'ί', r'ῐ', r'ῑ', r'ῒ', r'ΐ', r'ῖ', r'ῗ',
    r'ὀ', r'ὁ', r'ὂ', r'ὃ', r'ὄ', r'ὅ', r'ὸ', r'ό',
    r'ῤ', r'ῥ',
    r'ὐ', r'ὑ', r'ὒ', r'ὓ', r'ὔ', r'ὕ', r'ὖ', r'ὗ',
    r'ὺ', r'ύ', r'ῠ', r'ῡ', r'ῢ', r'ΰ', r'ῦ', r'ῧ',
    r'ὠ', r'ὡ', r'ὢ', r'ὣ', r'ὤ', r'ὥ', r'ὦ', r'ὧ', r'ὼ', r'ώ', r'ῶ',
    r'ᾠ', r'ᾡ', r'ᾢ', r'ᾣ', r'ᾤ', r'ᾥ', r'ᾦ', r'ᾧ', r'ῲ', r'ῳ', r'ῴ', r'ῷ'
)


GREEK = (
    r'Α', r'Β', r'Γ', r'Δ', r'Ε', r'Ζ', r'Η', r'Θ', r'Ι', r'Κ', r'Λ', r'Μ', r'Ν',
    r'Ξ', r'Ο', r'Π', r'Ρ', r'Σ', r'Τ', r'Υ', r'Φ', r'Χ', r'Ψ', r'Ω',
    r'α', r'β', r'γ', r'δ', r'ε', r'ζ', r'η', r'θ', r'ι', r'κ', r'λ', r'μ', r'ν',
    r'ξ', r'ο', r'π', r'ρ', r'σ', r'ς', r'τ', r'υ', r'φ', r'χ', r'ψ', r'ω'
)


GREEK_ARCHAIC = (r'Ϝ', r'Ϛ', r'Ϟ', r'Ϙ', r'Ϡ', r'ϝ', r'ϛ', r'ϟ', r'ϙ', r'ϡ', r'ϳ', r'ϗ', r'϶')


GREEK_ACCENT = (
    r'Ἀ', r'Ἁ', r'Ἂ', r'Ἃ', r'Ἄ', r'Ἅ', r'Ἆ', r'Ἇ',
    r'ᾈ', r'ᾉ', r'ᾊ', r'ᾋ', r'ᾌ', r'ᾍ', r'ᾎ', r'ᾏ', r'Ᾰ', r'Ᾱ', r'Ὰ', r'Ά', r'ᾼ',
    r'Ἐ', r'Ἑ', r'Ἒ', r'Ἓ', r'Ἔ', r'Ἕ', r'Ὲ', r'Έ',
    r'Ἠ', r'Ἡ', r'Ἢ', r'Ἣ', r'Ἤ', r'Ἥ', r'Ἦ', r'Ἧ',
    r'ᾘ', r'ᾙ', r'ᾚ', r'ᾛ', r'ᾜ', r'ᾝ', r'ᾞ', r'ᾟ', r'Ὴ', r'Ή', r'ῌ',
    r'Ἰ', r'Ἱ', r'Ἲ', r'Ἳ', r'Ἴ', r'Ἵ', r'Ἶ', r'Ἷ', r'Ῐ', r'Ῑ', r'Ὶ', r'Ί',
    r'Ὀ', r'Ὁ', r'Ὂ', r'Ὃ', r'Ὄ', r'Ὅ', r'Ὸ', r'Ό',
    r'Ῥ',
    r'Ὑ', r'Ὓ', r'Ὕ', r'Ὗ', r'Ῠ', r'Ῡ', r'Ὺ', r'Ύ',
    r'Ὠ', r'Ὡ', r'Ὢ', r'Ὣ', r'Ὤ', r'Ὥ', r'Ὦ', r'Ὧ',
    r'ᾨ', r'ᾩ', r'ᾪ', r'ᾫ', r'ᾬ', r'ᾭ', r'ᾮ', r'ᾯ', r'Ὼ', r'Ώ', r'ῼ',
    r'ἀ', r'ἁ', r'ἂ', r'ἃ', r'ἄ', r'ἅ', r'ἆ', r'ἇ', r'ὰ', r'ά',
    r'ᾀ', r'ᾁ', r'ᾂ', r'ᾃ', r'ᾄ', r'ᾅ', r'ᾆ', r'ᾇ', r'ᾰ', r'ᾱ', r'ᾲ', r'ᾳ', r'ᾴ', r'ᾶ', r'ᾷ',
    r'ἐ', r'ἑ', r'ἒ', r'ἓ', r'ἔ', r'ἕ', r'ὲ', r'έ',
    r'ἠ', r'ἡ', r'ἢ', r'ἣ', r'ἤ', r'ἥ', r'ἦ', r'ἧ', r'ὴ', r'ή', r'ῆ',
    r'ᾐ', r'ᾑ', r'ᾒ', r'ᾓ', r'ᾔ', r'ᾕ', r'ᾖ', r'ᾗ', r'ῂ', r'ῃ', r'ῄ', r'ῇ',
    r'ἰ', r'ἱ', r'ἲ', r'ἳ', r'ἴ', r'ἵ', r'ἶ', r'ἷ',
    r'ὶ', r'ί', r'ῐ', r'ῑ', r'ῒ', r'ΐ', r'ῖ', r'ῗ',
    r'ὀ', r'ὁ', r'ὂ', r'ὃ', r'ὄ', r'ὅ', r'ὸ', r'ό',
    r'ῤ', r'ῥ',
    r'ὐ', r'ὑ', r'ὒ', r'ὓ', r'ὔ', r'ὕ', r'ὖ', r'ὗ',
    r'ὺ', r'ύ', r'ῠ', r'ῡ', r'ῢ', r'ΰ', r'ῦ', r'ῧ',
    r'ὠ', r'ὡ', r'ὢ', r'ὣ', r'ὤ', r'ὥ', r'ὦ', r'ὧ', r'ὼ', r'ώ', r'ῶ',
    r'ᾠ', r'ᾡ', r'ᾢ', r'ᾣ', r'ᾤ', r'ᾥ', r'ᾦ', r'ᾧ', r'ῲ', r'ῳ', r'ῴ', r'ῷ'
)


GREEK_EXTENDED = (
    r'Ἀ', r'Ἁ', r'Ἂ', r'Ἃ', r'Ἄ', r'Ἅ', r'Ἆ', r'Ἇ',
    r'ᾈ', r'ᾉ', r'ᾊ', r'ᾋ', r'ᾌ', r'ᾍ', r'ᾎ', r'ᾏ', r'Ᾰ', r'Ᾱ', r'Ὰ', r'Ά', r'ᾼ',
    r'Ἐ', r'Ἑ', r'Ἒ', r'Ἓ', r'Ἔ', r'Ἕ', r'Ὲ', r'Έ',
    r'Ἠ', r'Ἡ', r'Ἢ', r'Ἣ', r'Ἤ', r'Ἥ', r'Ἦ', r'Ἧ',
    r'ᾘ', r'ᾙ', r'ᾚ', r'ᾛ', r'ᾜ', r'ᾝ', r'ᾞ', r'ᾟ', r'Ὴ', r'Ή', r'ῌ',
    r'Ἰ', r'Ἱ', r'Ἲ', r'Ἳ', r'Ἴ', r'Ἵ', r'Ἶ', r'Ἷ', r'Ῐ', r'Ῑ', r'Ὶ', r'Ί',
    r'Ὀ', r'Ὁ', r'Ὂ', r'Ὃ', r'Ὄ', r'Ὅ', r'Ὸ', r'Ό',
    r'Ῥ',
    r'Ὑ', r'Ὓ', r'Ὕ', r'Ὗ', r'Ῠ', r'Ῡ', r'Ὺ', r'Ύ',
    r'Ὠ', r'Ὡ', r'Ὢ', r'Ὣ', r'Ὤ', r'Ὥ', r'Ὦ', r'Ὧ',
    r'ᾨ', r'ᾩ', r'ᾪ', r'ᾫ', r'ᾬ', r'ᾭ', r'ᾮ', r'ᾯ', r'Ὼ', r'Ώ', r'ῼ',
    r'ἀ', r'ἁ', r'ἂ', r'ἃ', r'ἄ', r'ἅ', r'ἆ', r'ἇ', r'ὰ', r'ά',
    r'ᾀ', r'ᾁ', r'ᾂ', r'ᾃ', r'ᾄ', r'ᾅ', r'ᾆ', r'ᾇ', r'ᾰ', r'ᾱ', r'ᾲ', r'ᾳ', r'ᾴ', r'ᾶ', r'ᾷ',
    r'ἐ', r'ἑ', r'ἒ', r'ἓ', r'ἔ', r'ἕ', r'ὲ', r'έ',
    r'ἠ', r'ἡ', r'ἢ', r'ἣ', r'ἤ', r'ἥ', r'ἦ', r'ἧ', r'ὴ', r'ή', r'ῆ',
    r'ᾐ', r'ᾑ', r'ᾒ', r'ᾓ', r'ᾔ', r'ᾕ', r'ᾖ', r'ᾗ', r'ῂ', r'ῃ', r'ῄ', r'ῇ',
    r'ἰ', r'ἱ', r'ἲ', r'ἳ', r'ἴ', r'ἵ', r'ἶ', r'ἷ',
    r'ὶ', r'ί', r'ῐ', r'ῑ', r'ῒ', r'ΐ', r'ῖ', r'ῗ',
    r'ὀ', r'ὁ', r'ὂ', r'ὃ', r'ὄ', r'ὅ', r'ὸ', r'ό',
    r'ῤ', r'ῥ',
    r'ὐ', r'ὑ', r'ὒ', r'ὓ', r'ὔ', r'ὕ', r'ὖ', r'ὗ',
    r'ὺ', r'ύ', r'ῠ', r'ῡ', r'ῢ', r'ΰ', r'ῦ', r'ῧ',
    r'ὠ', r'ὡ', r'ὢ', r'ὣ', r'ὤ', r'ὥ', r'ὦ', r'ὧ', r'ὼ', r'ώ', r'ῶ',
    r'ᾠ', r'ᾡ', r'ᾢ', r'ᾣ', r'ᾤ', r'ᾥ', r'ᾦ', r'ᾧ', r'ῲ', r'ῳ', r'ῴ', r'ῷ'
)


GREEK_ALL = (
    r'Α', r'Β', r'Γ', r'Δ', r'Ε', r'Ζ', r'Η', r'Θ', r'Ι', r'Κ', r'Λ', r'Μ', r'Ν',
    r'Ξ', r'Ο', r'Π', r'Ρ', r'Σ', r'Τ', r'Υ', r'Φ', r'Χ', r'Ψ', r'Ω',
    r'α', r'β', r'γ', r'δ', r'ε', r'ζ', r'η', r'θ', r'ι', r'κ', r'λ', r'μ', r'ν',
    r'ξ', r'ο', r'π', r'ρ', r'σ', r'ς', r'τ', r'υ', r'φ', r'χ', r'ψ', r'ω',
    r'Ϝ', r'Ϛ', r'Ϟ', r'Ϙ', r'Ϡ', r'ϝ', r'ϛ', r'ϟ', r'ϙ', r'ϡ', r'ϳ', r'ϗ', r'϶',
    r'Ἀ', r'Ἁ', r'Ἂ', r'Ἃ', r'Ἄ', r'Ἅ', r'Ἆ', r'Ἇ',
    r'ᾈ', r'ᾉ', r'ᾊ', r'ᾋ', r'ᾌ', r'ᾍ', r'ᾎ', r'ᾏ', r'Ᾰ', r'Ᾱ', r'Ὰ', r'Ά', r'ᾼ',
    r'Ἐ', r'Ἑ', r'Ἒ', r'Ἓ', r'Ἔ', r'Ἕ', r'Ὲ', r'Έ',
    r'Ἠ', r'Ἡ', r'Ἢ', r'Ἣ', r'Ἤ', r'Ἥ', r'Ἦ', r'Ἧ',
    r'ᾘ', r'ᾙ', r'ᾚ', r'ᾛ', r'ᾜ', r'ᾝ', r'ᾞ', r'ᾟ', r'Ὴ', r'Ή', r'ῌ',
    r'Ἰ', r'Ἱ', r'Ἲ', r'Ἳ', r'Ἴ', r'Ἵ', r'Ἶ', r'Ἷ', r'Ῐ', r'Ῑ', r'Ὶ', r'Ί',
    r'Ὀ', r'Ὁ', r'Ὂ', r'Ὃ', r'Ὄ', r'Ὅ', r'Ὸ', r'Ό',
    r'Ῥ',
    r'Ὑ', r'Ὓ', r'Ὕ', r'Ὗ', r'Ῠ', r'Ῡ', r'Ὺ', r'Ύ',
    r'Ὠ', r'Ὡ', r'Ὢ', r'Ὣ', r'Ὤ', r'Ὥ', r'Ὦ', r'Ὧ',
    r'ᾨ', r'ᾩ', r'ᾪ', r'ᾫ', r'ᾬ', r'ᾭ', r'ᾮ', r'ᾯ', r'Ὼ', r'Ώ', r'ῼ',
    r'ἀ', r'ἁ', r'ἂ', r'ἃ', r'ἄ', r'ἅ', r'ἆ', r'ἇ', r'ὰ', r'ά',
    r'ᾀ', r'ᾁ', r'ᾂ', r'ᾃ', r'ᾄ', r'ᾅ', r'ᾆ', r'ᾇ', r'ᾰ', r'ᾱ', r'ᾲ', r'ᾳ', r'ᾴ', r'ᾶ', r'ᾷ',
    r'ἐ', r'ἑ', r'ἒ', r'ἓ', r'ἔ', r'ἕ', r'ὲ', r'έ',
    r'ἠ', r'ἡ', r'ἢ', r'ἣ', r'ἤ', r'ἥ', r'ἦ', r'ἧ', r'ὴ', r'ή', r'ῆ',
    r'ᾐ', r'ᾑ', r'ᾒ', r'ᾓ', r'ᾔ', r'ᾕ', r'ᾖ', r'ᾗ', r'ῂ', r'ῃ', r'ῄ', r'ῇ',
    r'ἰ', r'ἱ', r'ἲ', r'ἳ', r'ἴ', r'ἵ', r'ἶ', r'ἷ',
    r'ὶ', r'ί', r'ῐ', r'ῑ', r'ῒ', r'ΐ', r'ῖ', r'ῗ',
    r'ὀ', r'ὁ', r'ὂ', r'ὃ', r'ὄ', r'ὅ', r'ὸ', r'ό',
    r'ῤ', r'ῥ',
    r'ὐ', r'ὑ', r'ὒ', r'ὓ', r'ὔ', r'ὕ', r'ὖ', r'ὗ',
    r'ὺ', r'ύ', r'ῠ', r'ῡ', r'ῢ', r'ΰ', r'ῦ', r'ῧ',
    r'ὠ', r'ὡ', r'ὢ', r'ὣ', r'ὤ', r'ὥ', r'ὦ', r'ὧ', r'ὼ', r'ώ', r'ῶ',
    r'ᾠ', r'ᾡ', r'ᾢ', r'ᾣ', r'ᾤ', r'ᾥ', r'ᾦ', r'ᾧ', r'ῲ', r'ῳ', r'ῴ', r'ῷ'
)


# MISCELLANEOUS SYMBOLS


AIRPLANE = r'✈'
BIOHAZARD = r'☣'
CARD_REVERSE = r'🂠'
DOWN = r'↓'
EJECT = r'⏏'
FUEL_PUMP = r'⛽'
KEYBOARD = r'⌨'
LEFT = r'←'
LOADING = r'⌛'
MEDICINE = r'☤'
OHMS = r'Ω'
RADIATION = r'☢'
RIGHT = r'→'
TELEPHONE = r'☏'
TOXIC = r'☠'
UP = r'↑'
WARNING = r'⚠'


# STRING MANIPULATIONS


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
    return _str.replace('“', '"').replace('”', '"').replace('‘', r'\'').replace('’', r'\'').replace('′', r'\'').replace('″', '"').replace('‴', '"').replace('″', '"')


def rmspecialwhitespace(_str: str) -> str:
    """Remove special white-space characters

    >>> rmspecialwhitespace('This\u202F is a test.')
    'This is a test.'
    """
    return _str.replace('\u00A0', r'').replace('\u1680', r'').replace('\u16EB', r'').replace('\u16EC', r'').replace('\u180E', r'').replace('\u2000', r'').replace('\u2001', r'').replace('\u2002', r'').replace('\u2003', r'').replace('\u2004', r'').replace('\u2005', r'').replace('\u2006', r'').replace('\u2007', r'').replace('\u2008', r'').replace('\u2009', r'').replace('\u200A', r'').replace('\u200B', r'').replace('\u202F', r'').replace('\u205F', r'').replace('\u3000', r'').replace('\uFEFF', r'')


def replacespecialwhitespace(_str: str) -> str:
    """Replace special white-space characters

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
        if len(i):
            inputarray.append(i)
    return inputarray


def sqlstr(_obj, _strength: int=0) -> str:
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
            if i.isalpha() or i is r' ':
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


# MISCELLANEOUS FUNCTIONS


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
    return ''


def fvalhtml(_search: str, _type: str) -> str:
    """Search a dict by value to find the paired value; Stop on first instance

    For example, this finds '&#38;' or '&amp;' and returns the other value
    Returns HTML entity if found; else return empty string
    """
    _tuples = CODES.values()
    for v in _tuples:
        if not isinstance(v, (tuple, list)) or _search not in v:
            continue
        elif len(v) < 2 or len(v) > 4:
            continue
        if v[0] != _search:
            if (_type is 'name' and '#' not in v[0]) or (_type is 'num' and '&#' in v[0]):
                return v[0]
        elif v[1] != _search:
            if (_type is 'name' and '#' not in v[1]) or (_type is 'num' and '&#' in v[1]):
                return v[1]
        elif len(v) is 3 and v[2] != _search:
            if (_type is 'name' and '#' not in v[2]) or (_type is 'num' and '&#' in v[2]):
                return v[2]
        elif len(v) is 4 and v[3] != _search:
            if (_type is 'name' and '#' not in v[3]) or (_type is 'num' and '&#' in v[3]):
                return v[3]
    return r''


def noescape(_hex: str) -> str:
    """Remove escapes from a single character hex string (\\U00000026, \\u0026, \\x26)"""
    if '\\U' in _hex and len(_hex) is 10:
        _int = int(_hex.replace('\\U', r''), 16)
        _hex = hex(_int).replace('0x', r'')
        return eval('"\\U{0}"'.format(_hex[:].zfill(8)))
    elif '\\u' in _hex and len(_hex) is 6:
        _int = int(_hex.replace('\\u', r''), 16)
        _hex = hex(_int).replace('0x', r'')
        return eval('"\\u{0}"'.format(_hex[:].zfill(4)))
    elif '\\x' in _hex and (len(_hex) % 4) is 0:
        _utf8_strict = '.decode(\'utf8\', \'strict\')'
        if _hex.count('\\x') is 4:
            _hex = _hex.split('\\x')[1:]
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\\x{0[2]}\\x{0[3]}\'' + _utf8_strict
            return eval(_eval_str.format(_hex))
        elif _hex.count('\\x') is 3:
            _hex = _hex.split('\\x')[1:]
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\\x{0[2]}\'' + _utf8_strict
            return eval(_eval_str.format(_hex))
        elif _hex.count('\\x') is 2:
            _hex = _hex.split('\\x')[1:]
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\'' + _utf8_strict
            return eval(_eval_str.format(_hex))
        elif _hex.count('\\x') is 1:
            _int = int(_hex.replace('\\x', r''), 16)
            _hex = hex(_int).replace('0x', r'')[:].zfill(2)
            return eval('\'\\x{0}\''.format(_hex))
        else:
            raise Exception(r'Invalid input passed to noescape()!')
    elif isinstance(_hex, str) and len(_hex) is 1:
        return _hex
    else:
        raise Exception(r'Invalid input passed to noescape()!')


# BOOLEAN TESTS


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
    """Test if a character is within the Control Ascii limit

    >>> isctrlascii('\\r')
    True
    >>> isctrlascii('\\n')
    True
    >>> isctrlascii('\\a')
    True
    >>> isctrlascii('\\0')
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
    """Test if a string is within the Control Ascii limit

    >>> isstrctrlascii('\\r')
    True
    >>> isstrctrlascii('\\a')
    True
    >>> isstrctrlascii('\\a\\0')
    True
    >>> isstrctrlascii('qwerty\\n')
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
    """Is this a string of Greek letters

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
    """Does this string contain Greek letters

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
    """Is this a string of Braille characters

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
    """Does this string contain Braille characters

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
        if len(_str.encode('utf-8')):
            return True
    except SyntaxError:
        return False


def isutf16(_str: str) -> bool:  # flake8: noqa
    """Test if a string is within the UTF16 limit"""
    try:
        if len(_str.encode('utf-16')):
            return True
    except SyntaxError:
        return False


def isunicode(_str: str) -> bool:  # flake8: noqa
    """Test if a string is within the Unicode limit"""
    assert isinstance(_str, (str, bytes)), \
        'An invalid datatype was passed to isunicode()!'
    _utfstrict = '.decode(\'utf8\', \'strict\')'
    _fmt = 'b\'\\x{0[0]}\\x{0[1]}\\x{0[2]}\'' + _utfstrict
    if len(_str) is 10 and '\\U' in _str:
        _int = int(_str.replace('\\U', ''), 16)
        return _int <= UPPER_LIMIT_UNICODE
    elif len(_str) is 6 and '\\u' in _str:
        _int = int(_str.replace('\\u', ''), 16)
        return _int <= UPPER_LIMIT_UNICODE
    elif _str.count('\\x') is 1 and (len(_str) % 4) is 0:
        _int = int(_str.replace('\\x', '0x'), 16)
        return _int <= UPPER_LIMIT_UNICODE
    elif _str.count('\\x') >= 2 and (len(_str) % 4) is 0:
        try:
            eval(_fmt.format(_str.split('\\x')[1:]))
        except SyntaxError:
            return False
        return True
    elif isinstance(_str, bytes):
        try:
            _str.decode('utf8', 'strict')
        except SyntaxError:
            return False
        return True
    elif len(_str) is 1:
        try:
            if len(_str.encode('utf-16', 'strict')):
                return True
        except SyntaxError:
            return False
    return False


def hashexescape(_str: str) -> bool:  # flake8: noqa
    """Test if the string contains a character hex escape"""
    if '\\U' in _str:
        _ct = _str.count('\\U')
        _start = 0
        while _ct != 0:
            _start = _str.find('\\U', _start) + 2
            _end = _start + 8
            _skip = False
            for i in _str[_start:_end]:
                if i in '0123456789ABCDEFabcdef':
                    continue
                _skip = True
                break
            if not _skip:
                return True
            _ct -= 1
            _start = _end
    if '\\u' in _str:
        _ct = _str.count('\\u')
        _start = 0
        while _ct != 0:
            _start = _str.find('\\u', _start) + 2
            _end = _start + 4
            _skip = False
            for i in _str[_start:_end]:
                if i in '0123456789ABCDEFabcdef':
                    continue
                _skip = True
                break
            if not _skip:
                return True
            _ct -= 1
            _start = _end
    if '\\X' in _str:
        _ct = _str.count('\\X')
        _start = 0
        while _ct != 0:
            _start = _str.find('\\X', _start) + 2
            _end = _start + 2
            _skip = False
            for i in _str[_start:_end]:
                if i in '0123456789ABCDEFabcdef':
                    continue
                _skip = True
                break
            if not _skip:
                return True
            _ct -= 1
            _start = _end
    if '\\x' in _str:
        _ct = _str.count('\\x')
        _start = 0
        while _ct != 0:
            _start = _str.find('\\x', _start) + 2
            _end = _start + 2
            _skip = False
            for i in _str[_start:_end]:
                if i in '0123456789ABCDEFabcdef':
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


# LENGTHS


"""
Each byte in a UTF-8 byte-sequence consists of two parts -
 - marker bits (the most significant bits) - sequence of zero to four 1 bits followed by a 0
 - payload bits - x being payload bits


 - U-00000000 ... U-0000007F 	0xxxxxxx
 - U-00000080 ... U-000007FF 	110xxxxx 10xxxxxx
 - U-00000800 ... U-0000FFFF 	1110xxxx 10xxxxxx 10xxxxxx
 - U-00010000 ... U-0010FFFF 	11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
"""


def utf7len(_str: str) -> int:
    """Get the UTF7 byte-size of a string"""
    return len(_str.encode('utf-7'))


def utf8len(_str: str) -> int:
    """Get the UTF8 byte-size of a string"""
    return len(_str.encode('utf-8'))


def utf16len(_str: str) -> int:
    """Get the UTF16 byte-size of a string"""
    return len(_str.encode('utf-16'))


def utf32len(_str: str) -> int:
    """Get the UTF32 byte-size of a string"""
    return len(_str.encode('utf-32'))


# ESCAPE MANIPULATIONS


def shrink_esc_utf16to8(_hex: str) -> str:
    r"""Shrink a 16-bit hex escape to a 8-bit hex escape (\\uhhhh) => (\\xhh)

    >>> shrink_esc_utf16to8('\\u002f')
    '\\x2f'
    """
    if '\\u00' in _hex and len(_hex) is 6:
        return _hex.replace('\\u00', '\\x')
    raise Exception(_hex + r' cannot be shrunk to a 8-bit hex escape!')


def shrink_esc_utf32to8(_hex: str) -> str:
    r"""Shrink a 32-bit hex escape to a 8-bit hex escape (\\Uhhhhhhhh) => (\\xhh)

    >>> shrink_esc_utf32to8('\\U0000002f')
    '\\x2f'
    """
    if '\\U000000' in _hex and len(_hex) is 10:
        return _hex.replace('\\U000000', '\\x')
    raise Exception(_hex + r' cannot be shrunk to a 8-bit hex escape!')


def shrink_esc_utf32to16(_hex: str) -> str:
    r"""Shrink a 32-bit hex escape to a 16-bit hex escape (\\Uhhhhhhhh) => (\\uhhhh)

    >>> shrink_esc_utf32to16('\\U0000002f')
    '\\u002f'
    """
    if '\\U0000' in _hex and len(_hex) is 10:
        return _hex.replace('\\U0000', '\\u')
    raise Exception(_hex + r' cannot be shrunk to a 16-bit hex escape!')


def rmbyteshexesc(_str: bytes) -> str:
    """Remove hex escapes (b'\\x80abc' => abc) from byte strings; return str

    >>> rmbyteshexesc(b'\\x80abc')
    'abc'
    """
    return _str.decode('utf-8', 'ignore')


def rplbyteshexesc(_str: bytes) -> str:
    """Replace hex escapes (b'\\x26abc' => &abc) in byte strings; return str

    >>> rplbyteshexesc(b'\\x26abc')
    '&abc'
    """
    return _str.decode('utf-8', 'ignore')


def escape(_str):
    """Escape special characters that cause syntax errors

    >>> escape('String with "special" characters')
    'String with &#34;special&#34; characters'
    """
    return ''.join(ESCTAB.get(_c, _c) for _c in _str)


def unescape(_str):
    """Unescape special characters that cause syntax errors

    >>> unescape('String with &#34;special&#34; characters')
    'String with "special" characters'
    """
    _str = _str.replace(r'&#34;', r'"').replace(r'&#39;', r'\'').replace(r'&#91;', r'[').replace(r'&#40;', r'(').replace(r'&#41;', r')').replace(r'&#93;', r']')
    return _str.replace(r'&#123;', r'{').replace(r'&#125;', r'}').replace(r'&#92;', r'\\')


def findescapes(_str: str) -> list:
    r"""Find character hex escapes in a string

    Return a list of the escapes
    Return an empty list if none are found

    >>> findescapes('This is a \\u202f test.')
    ['\\u202f', [...]]
    """

    def _search(_char: str, _num: int):
        """Find hex characters"""
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
    if '\\U' in _str:
        _out.append(_search('\\U', 8))
    if '\\u' in _str:
        _out.append(_search('\\u', 4))
    if '\\x' in _str:
        _out.append(_search('\\x', 2))
    if '\\X' in _str:
        _out.append(_search('\\X', 2))
    return _out


def htmlentities(_data: str) -> str:
    r"""Replace HTML Reference Entities with characters

    >>> htmlentities('This &apos;is&apos; a test (&pi;, &dollar;, &#98;).')
    "This 'is' a test (π, $, b)."
    """
    for i in re.findall(CHAR_REF, _data):
        _data = _data.replace(i, refnum2char(i))
    for i in re.findall(ENTITY_REF, _data):
        _data = _data.replace(i, refname2char(i))
    return _data


def htmlescape(_str: str, quote: bool=True):
    """Replace special characters "&", "<", and ">" to HTML-escapes

    If the optional flag quote is true (default), double quote (") and
    single quote (') characters are also escaped.

    >>> htmlescape('This <b>is</b> a "test" (&).')
    'This &lt;b&gt;is&lt;/b&gt; a &quot;test&quot; (&amp;).'
    >>> htmlescape('This <b>is</b> a "test" (&).', False)
    'This &lt;b&gt;is&lt;/b&gt; a "test" (&amp;).'
    """
    _str = _str.replace(r'&', r'&amp;').replace(r'<', r'&lt;').replace(r'>', r'&gt;')
    if quote:
        _str = _str.replace('"', r'&quot;').replace('\'', r'&#39;')
    return _str


def htmlunescape(_str: str):
    """Unescape &, ', ", <, and >

    >>> htmlunescape('This &#x3c;b&#62;is&lt;/b&gt; a &#34;test&quot; (&amp;).')
    'This <b>is</b> a "test" (&).'
    >>> htmlunescape('This &lt;b&gt;is&lt;/b&gt; a &quot;test&quot; (&amp;).')
    'This <b>is</b> a "test" (&).'
    """
    if '&' not in _str:
        return _str
    _str = _str.replace(r'&#x27;', r'\'').replace(r'&#39;', r'\'').replace(r'&apos;', r'\'')
    _str = _str.replace(r'&#x22;', '"').replace(r'&#34;', '"').replace(r'&quot;', '"')
    _str = _str.replace(r'&#x3c;', r'<').replace(r'&#60;', r'<').replace(r'&lt;', r'<')
    _str = _str.replace(r'&#x3e;', r'>').replace(r'&#62;', r'>').replace(r'&gt;', r'>')
    _str = _str.replace(r'&x26;', r'&').replace(r'&#38;', r'&').replace(r'&amp;', r'&')
    return _str


def noescutf8hex(_hex: str) -> str:
    r"""Remove escapes from UTF-8 hex strings (\\x26)

    >>> noescutf8hex('\\x26')
    '&'
    """
    if '\\x' in _hex and (len(_hex) % 4) is 0:
        _utf8_strict = '.decode(\'utf8\', \'strict\')'
        if _hex.count('\\') == 3:
            _hex = _hex.split('\\x')[1:]
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\\x{0[2]}\'' + _utf8_strict
            return eval(_eval_str.format(_hex))
        elif _hex.count('\\') == 2:
            _hex = _hex.split('\\x')[1:]
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\'' + _utf8_strict
            return eval(_eval_str.format(_hex))
        elif _hex.count('\\') == 4:
            _hex = _hex.split('\\x')[1:]
            _eval_str = 'b\'\\x{0[0]}\\x{0[1]}\\x{0[2]}\\x{0[3]}\'' + _utf8_strict
            return eval(_eval_str.format(_hex))
        elif _hex.count('\\') == 1:
            _int = int(_hex.replace('\\x', ''), 16)
            _hex = hex(_int).replace('0x', '')[:].zfill(2)
            return eval('\'\\x{0}\''.format(_hex))
    if isinstance(_hex, str) and len(_hex) is 1:
        return _hex
    raise ValueError('Invalid input passed to noescutf8hex()!')


def expandhexescape(_hex: str) -> str:
    r"""Convert a 16-bit hex escape to a 32-bit hex escape (\\uhhhh) => (\\Uhhhhhhhh)

    >>> expandhexescape('\\u202f')
    '\\U0000202f'
    """
    if '\\u' in _hex and len(_hex) is 6:
        return _hex.replace('\\u', '\\U0000')
    raise Exception(_hex + r' cannot be converted to a 32-bit hex escape!')


def char2noeschex(_char: str) -> str:
    """Convert a character to a hex string lacking divisions or escapes

    >>> char2noeschex('&')
    '26'
    """
    return '{:02x}'.format(ord(_char))


def str2noeschex(_char: str) -> str:
    """Convert a string to a hex string lacking divisions or escapes

    >>> str2noeschex('This is a test.')
    '54686973206973206120746573742e'
    """
    return ''.join('{:02x}'.format(ord(i)) for i in _char)


def str2hexcolon(_str: str) -> str:
    """Convert a string to a hex string divided into pairs by colons

    >>> str2hexcolon('This is a test.')
    '54:68:69:73:20:69:73:20:61:20:74:65:73:74:2e'
    """
    return ':'.join('{:02x}'.format(ord(i)) for i in _str)


# X 2 CHARACTER


def int2char(_int, _numbase: str='10', _escape: bool=True) -> str:
    """Convert an integer (as a str or int type) to a character

    The integer may be decimal, hex, octal, or binary
    By default, the returned value is escaped unicode (\\U0000000)
    int2char(_int, _numbase, _escape) => str
    _int - number to convert to a character
    _numbase - Specify the int's base (2, 8, 10, 16)
    _escape - False = No escapes; True = Escapes
    int2char(38) => \\U00000026
    int2char('38') => \\U00000026
    int2char('0x26') => \\U00000026
    int2char(0x26) => \\U00000026
    int2char('26', '16') => \\U00000026
    int2char('26', '16', False) => &
    """
    if isinstance(_int, str):
        if '0x' in _int or _numbase is '16' or _numbase is 'hex':
            _int = int(_int, 16)
        elif '0b' in _int or _numbase is '2' or _numbase is 'bin':
            _int = int(_int, 2)
        elif '0o' in _int or _numbase is '8' or _numbase is 'oct':
            _int = int(_int, 8)
        else:
            _int = int(_int, 10)
    if isinstance(_int, int):
        if _escape:
            _int = hex(_int).replace('0x', '')[:].zfill(8)
            return '\\U{0}'.format(_int)
        else:
            if LOWER_LIMIT_ASCII_CTRL <= _int <= UPPER_LIMIT_UTF8:
                return chr(_int)
            elif UPPER_LIMIT_UTF8 < _int <= UPPER_LIMIT_UNICODE:
                _int = hex(_int).replace('0x', '')
                return eval('"\\U{0}"'.format(_int[:].zfill(8)))
            raise ValueError(r'An out-of-range integer passed to int2char()!')
    raise TypeError(r'Invalid datatype passed to int2char()!')


def hexstr2char(_hex: str, _escape: bool=True) -> str:
    """Convert a hex number (as a string) to a character

    hexstr2char('0x26') => \\U00000026
    hexstr2char(0x26) => \\U00000026
    hexstr2char('26', False) => &
    """
    return int2char(_hex, '16', _escape)


def hexint2char(_hex: int, _escape: bool=True) -> str:
    """Convert a hex integer to a character

    hexint2char(0x26) => \\U00000026
    hexint2char(0x26, False) => &
    """
    return int2char(_hex, '16', _escape)


def octstr2char(_oct: str, _escape: bool=True) -> str:
    """Convert an octal number (as a string) to a character

    octstr2char('0o46') => \\U00000026
    octstr2char(0o46) => \\U00000026
    octstr2char('46', False) => &
    """
    return int2char(_oct, '8', _escape)


def octint2char(_oct: int, _escape: bool=True) -> str:
    """Convert an octal integer to a character

    octint2char(0o46) => \\U00000026
    octint2char(0o46, False) => &
    """
    return int2char(_oct, '8', _escape)


def binstr2char(_bin: str, _escape: bool=True) -> str:
    """Convert a binary number (as a string) to a character

    binstr2char('0b100110') => \\U00000026
    binstr2char(0b100110) => \\U00000026
    binstr2char('100110', False) => &
    """
    return int2char(_bin, '2', _escape)


def binint2char(_bin: int, _escape: bool=True) -> str:
    """Convert an binary integer to a character

    binint2char(0b100110) => \\U00000026
    binint2char(0b100110, False) => &
    """
    return int2char(_bin, '2', _escape)


def refname2char(_refname: str, _escape: bool=True) -> str:
    """Convert HTML entity name (&amp;) to character (&)"""
    assert '#' not in _refname, \
        'The entered value is not a HTML entity name (&amp;)!'
    if _escape:
        return fval(CODES, _refname)
    else:
        return noescape(fval(CODES, _refname))


def refnum2char(_refnum: str, _escape: bool=True) -> str:
    """Convert HTML entity number (&#38; or &#x26;) to character (&)"""
    assert _refnum.startswith('&#') and _refnum.endswith(';'), \
        'The entered value is not in Hex NCR format (&#x26;)!'
    if 'x' not in _refnum:
        _refnum = int(_refnum.replace(r'&#', r'').replace(r';', r''), 10)
        rawhexstr = hex(_refnum).replace(r'0x', r'')
    else:
        rawhexstr = _refnum.replace(r'&#x', r'').replace(r';', r'')
    if _escape:
        return eval('"\\U{0}"'.format(rawhexstr[:].zfill(8)))
    else:
        return '\\U{0}'.format(rawhexstr[:].zfill(8))


def ncr2char(_refname: str) -> str:
    """Wrapper for refnum2char()"""
    return refnum2char(_refname)


def hexncr2char(_refname: str) -> str:
    """Wrapper for refnum2char()"""
    return refnum2char(_refname)


def name2char(_name: str) -> str:
    """Convert a Unicode name to a character

    If the name is invalid, an empty string is returned
    """
    try:
        _out = eval('"\\N{1}{0}{2}"'.format(_name.upper(), '{', '}'))
    except SyntaxError:
        return r''
    return _out


# X 2 INTEGER


def char2int(_char: str) -> int:
    """Convert a character to an integer"""
    return ord(_char)


def refnum2int(_refnum: str) -> int:
    """Convert Decimal-NCR/HTML-Entity (&#38;) to an integer"""
    assert '&#' in _refnum and ';' in _refnum, \
        'The entered value is not a HTML entity number (&#38;)!'
    _refnum = _refnum.replace(r'&#', r'').replace(r';', r'')
    return int(_refnum, 10)


def ncr2int(_refnum: str) -> int:
    """Decorator for refnum2int()"""
    return refnum2int(_refnum)


# X 2 UTF*


def utf8convchar2hexescape(_char: str) -> str:
    """Convert a character to a UTF-8 hex string (\\xc3\\x9e)"""
    _char = str(_char.encode('utf_8', 'strict'))
    _char = _char.replace(r'b', r'').replace('\'', r'')
    return '{0}'.format(_char)


def utf8convchar2hexstr(_char: str) -> str:
    """Convert a character to a hex string (0xc30x9e)"""
    _char = str(_char.encode('utf_8', 'strict')).replace(r'b', r'')
    _char = _char.replace('\'', r'').replace('\\x', r'0x')
    return '{0}'.format(_char)


def utf8convchar2uri(_char: str) -> str:
    """Convert a character to an URI escaped hex sequence (%c3%9e)"""
    _char = str(_char.encode('utf_8', 'strict')).replace(r'b', r'')
    _char = _char.replace('\'', r'').replace('\\x', r'%')
    return '{0}'.format(_char)


def utf8convchar2intstr(_char: str) -> int:
    """Convert a character to an integer string (& => 38)"""
    _char = str(_char.encode('utf_8', 'strict')).replace('b', '')
    _char = _char.replace('\'', r'').replace('\\x', r'0x')
    _char = '{0}'.format(_char.split(r'0x'))
    return ''.join('{0}'.format(str(int(i, 16)) for i in _char))


def int2utf16(_int: int, _endian: str=byteorder) -> str:
    """Convert an integer to a character"""
    if 0 <= _int <= UPPER_LIMIT_UNICODE:
        if _endian is 'little':
            return (_int).to_bytes(4, _endian).decode('utf-16-le', 'strict')
        elif _endian is 'big':
            return (_int).to_bytes(4, _endian).decode('utf-16-be', 'strict')
        else:
            return (_int).to_bytes(4, 'little').decode('utf-16', 'strict')
    raise ValueError('Integer value out of valid Unicode range (0 - {0})!'.format(UPPER_LIMIT_UNICODE))


def int2utf32(_int: int, _endian: str=byteorder) -> str:
    """Convert an integer to a character"""
    if 0 <= _int <= UPPER_LIMIT_UNICODE:
        return (_int).to_bytes(4, _endian).decode('utf-32', 'strict')
    raise ValueError('Integer value out of valid Unicode range (0 - {0})!'.format(UPPER_LIMIT_UNICODE))


# X 2 HEX


def char2hexstr(_char: str) -> str:
    """Convert a character(s) to hex-numbers as a str"""
    if len(_char) is 1:
        return hex(ord(_char))
    elif len(_char) > 1:
        _out = ''
        for i in _char:
            _out = _out + hex(ord(i))
        return _out
    raise ValueError(r'Invalid data passed to char2hexstr()!')


def hex2unicodehex(_hex: str or int) -> str:
    """Convert hexadecimal to Unicode+Hex Notation"""
    if isinstance(_hex, str):
        if '0x' in _hex:
            _hex = _hex.replace('0x', r'')
        if '\\x' in _hex:
            _hex = _hex.replace('\\x', r'')
        if '\\U' in _hex:
            _hex = _hex.replace('\\U000', r'').replace('\\U00', r'')
            _hex = _hex.replace('\\U0', r'').replace('\\U', r'')
        if '\\u' in _hex:
            _hex = _hex.replace('\\u00', r'').replace('\\u0', r'')
            _hex = _hex.replace('\\u', r'')
        if '\\0' in _hex:
            _hex = _hex.replace('\\0', r'')
        if '&#x' in _hex:
            _hex = _hex.replace('&#x', r'').replace(';', r'')
        return 'U+{0}'.format(_hex)
    elif isinstance(_hex, int):
        _hex = hex(_hex).replace('0x', r'')
        return 'U+{0}'.format(_hex)
    raise TypeError(r'Invalid datatype passed to hex2unicodehex()!')


def hex2cssnot(_hex: str or int) -> str:
    """Convert hexadecimal to CSS Notation (\01D4C3)"""
    if isinstance(_hex, str):
        if '0x' in _hex:
            _hex = _hex.replace('0x', r'')
        if '\\x' in _hex:
            _hex = _hex.replace('\\x', r'')
        if '\\U' in _hex:
            _hex = _hex.replace('\\U000', r'').replace('\\U00', r'')
            _hex = _hex.replace('\\U0', r'').replace('\\U', r'')
        if '\\u' in _hex:
            _hex = _hex.replace('\\u00', r'').replace('\\u0', r'')
            _hex = _hex.replace('\\u', r'')
        if 'U+' in _hex:
            _hex = _hex.replace('U+', r'')
        if '&#x' in _hex:
            _hex = _hex.replace('&#x', r'').replace(';', r'')
        return '\\0{0}'.format(_hex)
    elif isinstance(_hex, int):
        _hex = hex(_hex).replace('0x', r'')
        return '\\0{0}'.format(_hex)
    raise TypeError(r'Invalid datatype passed to hex2cssnot()!')


# X 2 HTML REFERENCE NUMBER (NCR)


def refname2refnum(_refname: str):
    """Convert HTML entity name (&amp;) to Decimal-NCR/HTML-Entity (&#38;)"""
    assert '#' not in _refname, \
        'The entered value is not a HTML entity name (&amp;)!'
    return fvalhtml(_refname, 'num')


def refname2ncr(_refname: str) -> str:
    """Alias for refname2refnum()"""
    return refname2refnum(_refname)


def int2refnum(_int: int) -> str:
    """Convert an integer to Decimal-NCR/HTML-Entity (&#38;)"""
    if 0 <= _int <= UPPER_LIMIT_UNICODE:
        return '&#{0};'.format(_int)
    raise ValueError('Integer value out of valid Unicode range (0 - {0})!'.format(UPPER_LIMIT_UNICODE))


def int2ncr(_int: int) -> str:
    """Wrapper for int2refnum()"""
    return int2refnum(_int)


# X 2 HTML ENTITY NAME


def refnum2refname(_refnum: str) -> str:
    """Convert Decimal-NCR/HTML-Entity (&#38;) to HTML entity name (&amp;)"""
    assert '&#' in _refnum and ';' in _refnum, \
        'The entered value is not a HTML entity number (&#38;)!'
    return fvalhtml(_refnum, 'name')


def ncr2refname(_refnum: str) -> str:
    """Wrapper for refnum2refname()"""
    return refnum2refname(_refnum)


# X 2 MISC


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


def str2bytes(_str: str, _encoding: str='utf8') -> bytes:
    """Convert strings to bytes"""
    return _str.encode(_encoding, 'strict')


def bytes2str(_bytes: bytes, _encoding: str='utf8') -> str:
    """Convert bytes to strings"""
    return _bytes.decode(_encoding, 'strict')


def int2hexbytes(_int: int, _length: int=2, _endian: str='little', _signed: bool=False) -> str:
    """Convert int to bytes represented as an escaped hex string
    If byteorder is "big", the most significant byte is at the beginning of the byte array.
    If byteorder is "little", the most significant byte is at the end of the byte array.
    """
    return _int.to_bytes(_length, _endian, signed=_signed)


def hexstr2bytearray(_hex: str) -> bytearray:
    """Convert a hex string to a bytearray"""
    return bytearray.fromhex(_hex)


# BUBBLE TEXT


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
    return _out.translate(TRANS_TAB_TEXT2BUBBLE)


def bubble2text(_str: str) -> str:
    """Convert bubble text to a plain-text string

    >>> bubble2text('Ⓣⓗⓘⓢ ⓘⓢ ⓐ ⓣⓔⓢⓣ.⃝')
    'This is a test.'
    >>> bubble2text('Ⓣⓗⓘⓢ ⓘⓢ ⓐ ⓢⓔⓒⓞⓝⓓ (⃝ ②ⓝⓓ)⃝  ⓣⓔⓢⓣ.⃝ ')
    'This is a second (2nd) test.'
    >>> bubble2text('Ⓣⓔⓢⓣⓘⓝⓖ ⓥⓐⓡⓘⓞⓤⓢ ⓒⓗⓐⓡⓐⓒⓣⓔⓡⓢ:⃝  €⃝ ,⃝  *⃝ ,⃝  Ω⃝ ,⃝  ᾲ⃝ ,⃝  ⓐⓝⓓ ⛽⃝ .⃝ ')
    'Testing various characters: €, *, Ω, ᾲ, and ⛽.'
    """
    _str = _str.replace('\u202f', r'').replace('\\u202f', r'')
    return _str.translate(TRANS_TAB_BUBBLE2TEST).replace('\u20dd ', r'').replace('\u20dd', r'')


# SQUARE TEXT


def text2square(_str: str, square_spaces: bool=False) -> str:
    """Convert a plain-text string to square text

    >>> text2square('This (str) is a sample test.', True)
    'T⃞ h⃞ i⃞ s⃞  ⃞ (⃞ s⃞ t⃞ r⃞ )⃞  ⃞ i⃞ s⃞  ⃞ a⃞  ⃞ s⃞ a⃞ m⃞ p⃞ l⃞ e⃞  ⃞ t⃞ e⃞ s⃞ t⃞ .⃞ '
    >>> text2square('This (str) is a sample test.')
    'T⃞ h⃞ i⃞ s⃞   (⃞ s⃞ t⃞ r⃞ )⃞   i⃞ s⃞   a⃞   s⃞ a⃞ m⃞ p⃞ l⃞ e⃞   t⃞ e⃞ s⃞ t⃞ .⃞ '
    >>> text2square('Testing various characters: €, *, Ω, ᾲ, and ⛽.')
    'T⃞ e⃞ s⃞ t⃞ i⃞ n⃞ g⃞   v⃞ a⃞ r⃞ i⃞ o⃞ u⃞ s⃞   c⃞ h⃞ a⃞ r⃞ a⃞ c⃞ t⃞ e⃞ r⃞ s⃞ :⃞   €⃞ ,⃞   *⃞ ,⃞   Ω⃞ ,⃞   ᾲ⃞ ,⃞   a⃞ n⃞ d⃞   ⛽⃞ .⃞ '
    """
    _out = ''
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
    return _str.replace('\u202f', r'').replace('\\u202f', r'').replace('\u20de ', r'').replace('\u20de', r'').replace(r'  ', r' ')

#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Common regular expression patterns

@file libregex.py
@package pybooster.libregex
@version 2018.12.28
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


try:  # Regular Expression module
    from regex import compile as rgxcompile
except ImportError:
    from re import compile as rgxcompile


__all__: list = [
    # GENERAL PATTERNS #
    r'BINNUM',
    r'EMAIL',
    r'EXPNUM',
    r'GREEK_ALL',
    r'HEXESCCSS',
    r'HEXESCPERL',
    r'HEXESCRUBY',
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
    r'C1_CONTROLS',
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
    r'CONTROL_PICTURES',
    r'OPTICAL_CHARACTER_RECOGNITION',
    r'ENCLOSED_ALPHANUMERICS',
    r'BOX_DRAWING',
    r'BLOCK_ELEMENTS',
    r'GEOMETRIC_SHAPES',
    r'MISCELLANEOUS_SYMBOLS',
    r'DINGBATS',
    r'MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A',
    r'SUPPLEMENTAL_ARROWS_A',
    r'BRAILLE_PATTERNS',
    r'SUPPLEMENTAL_ARROWS_B',
    r'MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B',
    r'SUPPLEMENTAL_MATHEMATICAL_OPERATORS',
    r'MISCELLANEOUS_SYMBOLS_AND_ARROWS',
    r'GLAGOLITIC',
    r'LATIN_EXTENDED_C',
    r'COPTIC',
    r'GEORGIAN_SUPPLEMENT',
    r'TIFINAGH',
    r'ETHIOPIC_EXTENDED',
    r'CYRILLIC_EXTENDED_A',
    r'SUPPLEMENTAL_PUNCTUATION',
    r'CJK_RADICALS_SUPPLEMENT',
    r'KANGXI_RADICALS',
    r'IDEOGRAPHIC_DESCRIPTION_CHARACTERS',
    r'CJK_SYMBOLS_AND_PUNCTUATION',
    r'HIRAGANA',
    r'KATAKANA',
    r'BOPOMOFO',
    r'HANGUL_COMPATIBILITY_JAMO',
    r'KANBUN',
    r'BOPOMOFO_EXTENDED',
    r'CJK_STROKES',
    r'KATAKANA_PHONETIC_EXTENSIONS',
    r'ENCLOSED_CJK_LETTERS_AND_MONTHS',
    r'CJK_COMPATIBILITY',
    r'CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A',
    r'YIJING_HEXAGRAM_SYMBOLS',
    r'CJK_UNIFIED_IDEOGRAPHS',
    r'YI_SYLLABLES',
    r'YI_RADICALS',
    r'LISU',
    r'VAI',
    r'CYRILLIC_EXTENDED_B',
    r'BAMUM',
    r'MODIFIER_TONE_LETTERS',
    r'LATIN_EXTENDED_D',
    r'SYLOTI_NAGRI',
    r'COMMON_INDIC_NUMBER_FORMS',
    r'PHAGS_PA',
    r'SAURASHTRA',
    r'DEVANAGARI_EXTENDED',
    r'KAYAH_LI',
    r'REJANG',
    r'HANGUL_JAMO_EXTENDED_A',
    r'JAVANESE',
    r'MYANMAR_EXTENDED_B',
    r'CHAM',
    r'MYANMAR_EXTENDED_A',
    r'TAI_VIET',
    r'MEETEI_MAYEK_EXTENSIONS',
    r'ETHIOPIC_EXTENDED_A',
    r'LATIN_EXTENDED_E',
    r'CHEROKEE_SUPPLEMENT',
    r'MEETEI_MAYEK',
    r'HANGUL_SYLLABLES',
    r'HANGUL_JAMO_EXTENDED_B',
    r'HIGH_SURROGATES',
    r'HIGH_PRIVATE_USE_SURROGATES',
    r'LOW_SURROGATES',
    r'PRIVATE_USE_AREA',
    r'CJK_COMPATIBILITY_IDEOGRAPHS',
    r'ALPHABETIC_PRESENTATION_FORMS',
    r'ARABIC_PRESENTATION_FORMS_A',
    r'VARIATION_SELECTORS',
    r'VERTICAL_FORMS',
    r'COMBINING_HALF_MARKS',
    r'CJK_COMPATIBILITY_FORMS',
    r'SMALL_FORM_VARIANTS',
    r'ARABIC_PRESENTATION_FORMS_B',
    r'HALFWIDTH_AND_FULLWIDTH_FORMS',
    r'SPECIALS',
    r'LINEAR_B_SYLLABARY',
    r'LINEAR_B_IDEOGRAMS',
    r'AEGEAN_NUMBERS',
    r'ANCIENT_GREEK_NUMBERS',
    r'ANCIENT_SYMBOLS',
    r'PHAISTOS_DISC',
    r'LYCIAN',
    r'CARIAN',
    r'COPTIC_EPACT_NUMBERS',
    r'OLD_ITALIC',
    r'GOTHIC',
    r'OLD_PERMIC',
    r'UGARITIC',
    r'OLD_PERSIAN',
    r'DESERET',
    r'SHAVIAN',
    r'OSMANYA',
    r'OSAGE',
    r'ELBASAN',
    r'CAUCASIAN_ALBANIAN',
    r'LINEAR_A',
    r'CYPRIOT_SYLLABARY',
    r'IMPERIAL_ARAMAIC',
    r'PALMYRENE',
    r'NABATAEAN',
    r'HATRAN',
    r'PHOENICIAN',
    r'LYDIAN',
    r'MEROITIC_HIEROGLYPHS',
    r'MEROITIC_CURSIVE',
    r'KHAROSHTHI',
    r'OLD_SOUTH_ARABIAN',
    r'OLD_NORTH_ARABIAN',
    r'MANICHAEAN',
    r'AVESTAN',
    r'INSCRIPTIONAL_PARTHIAN',
    r'INSCRIPTIONAL_PAHLAVI',
    r'PSALTER_PAHLAVI',
    r'OLD_TURKIC',
    r'OLD_HUNGARIAN',
    r'HANIFI_ROHINGYA',
    r'RUMI_NUMERAL_SYMBOLS',
    r'OLD_SOGDIAN',
    r'SOGDIAN',
    r'BRAHMI',
    r'KAITHI',
    r'SORA_SOMPENG',
    r'CHAKMA',
    r'MAHAJANI',
    r'SHARADA',
    r'SINHALA_ARCHAIC_NUMBERS',
    r'KHOJKI',
    r'MULTANI',
    r'KHUDAWADI',
    r'GRANTHA',
    r'NEWA',
    r'TIRHUTA',
    r'SIDDHAM',
    r'MODI',
    r'MONGOLIAN_SUPPLEMENT',
    r'TAKRI',
    r'AHOM',
    r'DOGRA',
    r'WARANG_CITI',
    r'ZANABAZAR_SQUARE',
    r'SOYOMBO',
    r'PAU_CIN_HAU',
    r'BHAIKSUKI',
    r'MARCHEN',
    r'MASARAM_GONDI',
    r'GUNJALA_GONDI',
    r'MAKASAR',
    r'CUNEIFORM',
    r'CUNEIFORM_NUMBERS_AND_PUNCTUATION',
    r'EARLY_DYNASTIC_CUNEIFORM',
    r'EGYPTIAN_HIEROGLYPHS',
    r'ANATOLIAN_HIEROGLYPHS',
    r'BAMUM_SUPPLEMENT',
    r'MRO',
    r'BASSA_VAH',
    r'PAHAWH_HMONG',
    r'MEDEFAIDRIN',
    r'MIAO',
    r'IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION',
    r'TANGUT',
    r'TANGUT_COMPONENTS',
    r'KANA_SUPPLEMENT',
    r'KANA_EXTENDED_A',
    r'NUSHU',
    r'DUPLOYAN',
    r'SHORTHAND_FORMAT_CONTROLS',
    r'BYZANTINE_MUSICAL_SYMBOLS',
    r'MUSICAL_SYMBOLS',
    r'ANCIENT_GREEK_MUSICAL_NOTATION',
    r'MAYAN_NUMERALS',
    r'TAI_XUAN_JING_SYMBOLS',
    r'COUNTING_ROD_NUMERALS',
    r'MATHEMATICAL_ALPHANUMERIC_SYMBOLS',
    r'SUTTON_SIGNWRITING',
    r'GLAGOLITIC_SUPPLEMENT',
    r'MENDE_KIKAKUI',
    r'ADLAM',
    r'INDIC_SIYAQ_NUMBERS',
    r'ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS',
    r'MAHJONG_TILES',
    r'DOMINO_TILES',
    r'PLAYING_CARDS',
    r'ENCLOSED_ALPHANUMERIC_SUPPLEMENT',
    r'ENCLOSED_IDEOGRAPHIC_SUPPLEMENT',
    r'MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS',
    r'EMOTICONS',
    r'ORNAMENTAL_DINGBATS',
    r'TRANSPORT_AND_MAP_SYMBOLS',
    r'ALCHEMICAL_SYMBOLS',
    r'GEOMETRIC_SHAPES_EXTENDED',
    r'SUPPLEMENTAL_ARROWS_C',
    r'SUPPLEMENTAL_SYMBOLS_AND_PICTOGRAPHS',
    r'CHESS_SYMBOLS',
    r'CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B',
    r'CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C',
    r'CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D',
    r'CJK_UNIFIED_IDEOGRAPHS_EXTENSION_E',
    r'CJK_UNIFIED_IDEOGRAPHS_EXTENSION_F',
    r'CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT',
    r'TAGS',
    r'VARIATION_SELECTORS_SUPPLEMENT',
    r'SUPPLEMENTARY_PRIVATE_USE_AREA_A',
    r'SUPPLEMENTARY_PRIVATE_USE_AREA_B',
    r'BMP',
    r'SMP',
    r'SIP',
    r'SSP',
    r'PUA_A',
    r'PUA_B',
    r'CONTROL_CHARS',
    r'REGIONAL_INDICATOR',
    r'EMOJI_MODIFIER_FITZPATRICK',
    r'INTERLINEAR_ANNOTATIONS',
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


# GENERAL PATTERNS #


BINNUM = rgxcompile(r'0[bB]([01]+)')
EMAIL = rgxcompile(r'([A-Za-z0-9_\-!#\$%\' <>&"\(\),:;@\[\\\]\*\+/=\?\^`\{\|\}~\.]+)@([A-Za-z0-9\-]+)\.([A-Za-z0-9\-]+)')
EXPNUM = rgxcompile(r'[eE]([-+]?)([0-9]+)')
GREEK_ALL = rgxcompile(r'[\u0370-\u03FF \u1F00-\u1FFF]+')
HEXESCCSS = rgxcompile(r'\\([A-Fa-f0-9]+)')
HEXESCPERL = rgxcompile(r'[\\]?x\u007B([A-Fa-f0-9]+)\u007D')
HEXESCRUBY = rgxcompile(r'[\\]?u\{([A-Fa-f0-9]+)\}')
HEXESCTAG = rgxcompile(r'&#x([A-Fa-f0-9]+);')
HEXESCURI = rgxcompile(r'%([A-Fa-f0-9]+)')
HEXNUM = rgxcompile(r'0[xX]([A-Fa-f0-9]+)')
OCTNUM = rgxcompile(r'0[oO]([0-7]+)')
ODD_WHITESPACE = rgxcompile(r'[\xA0\u1680\u180E\u2000-\u200D\u2028\u2029\u202F\u205F\u2060\u3000\U0000FEFF]+')
PHONE = rgxcompile(r'[\(]?[0-9]{3}[\)]?[\- ]?[0-9]{3}[\- ]?[0-9]{4}')
LEADING_TRAILING_WHITESPACE = rgxcompile(r'(^\s+)|(\s+$)')
LEADING_WHITESPACE = rgxcompile(r'^(\s+)')
TRAILING_ZEROS = rgxcompile(r'\d*\.(\d*?)(0+)$')
TRAILING_WHITESPACE = rgxcompile(r'(\s+)$')
WHITESPACE = rgxcompile(r'(\s+)')
WHITESPACE_NEWLINE = rgxcompile(r'\s*(\f|\r|\n)+\s*')


# UNICODE CHARACTER BLOCKS #


BASIC_LATIN = rgxcompile(r'([\x00-\x7F]+)')
C0_CONTROLS = rgxcompile(r'([\x00-\x1F]+)')
C1_CONTROLS = rgxcompile(r'([\x80-\x9F]+)')
LATIN_1_SUPPLEMENT = rgxcompile(r'([\x80-\xFF]+)')
LATIN_EXTENDED_A = rgxcompile(r'([\u0100-\u017F]+)')
LATIN_EXTENDED_B = rgxcompile(r'([\u0180-\u024F]+)')
IPA_EXTENSIONS = rgxcompile(r'([\u0250-\u02AF]+)')
SPACING_MODIFIER_LETTERS = rgxcompile(r'([\u02B0-\u02FF]+)')
COMBINING_DIACRITICAL_MARKS = rgxcompile(r'([\u0300-\u036F]+)')
GREEK_AND_COPTIC = rgxcompile(r'([\u0370-\u03FF]+)')
CYRILLIC = rgxcompile(r'([\u0400-\u04FF]+)')
CYRILLIC_SUPPLEMENT = rgxcompile(r'([\u0400-\u052F]+)')
ARMENIAN = rgxcompile(r'([\u0530-\u058F]+)')
HEBREW = rgxcompile(r'([\u0590-\u05FF]+)')
ARABIC = rgxcompile(r'([\u0600-\u06FF]+)')
SYRIAC = rgxcompile(r'([\u0700-\u074F]+)')
ARABIC_SUPPLEMENT = rgxcompile(r'([\u0750-\u077F]+)')
THAANA = rgxcompile(r'([\u0780-\u07BF]+)')
NKO = rgxcompile(r'([\u07C0-\u07FF]+)')
SAMARITAN = rgxcompile(r'([\u0800-\u083F]+)')
MANDAIC = rgxcompile(r'([\u0840-\u085F]+)')
SYRIAC_SUPPLEMENT = rgxcompile(r'([\u0860-\u086F]+)')
ARABIC_EXTENDED_A = rgxcompile(r'([\u08A0-\u08FF]+)')
DEVANAGARI = rgxcompile(r'([\u0900-\u097F]+)')
BENGALI = rgxcompile(r'([\u0980-\u09FF]+)')
GURMUKHI = rgxcompile(r'([\u0A00-\u0A7F]+)')
GUJARATI = rgxcompile(r'([\u0A80-\u0AFF]+)')
ORIYA = rgxcompile(r'([\u0B00-\u0B7F]+)')
TAMIL = rgxcompile(r'([\u0B80-\u0BFF]+)')
TELUGU = rgxcompile(r'([\u0C00-\u0C7F]+)')
KANNADA = rgxcompile(r'([\u0C80-\u0CFF]+)')
MALAYALAM = rgxcompile(r'([\u0D00-\u0D7F]+)')
SINHALA = rgxcompile(r'([\u0D80-\u0DFF]+)')
THAI = rgxcompile(r'([\u0E00-\u0E7F]+)')
LAO = rgxcompile(r'([\u0E80-\u0EFF]+)')
TIBETAN = rgxcompile(r'([\u0F00-\u0FFF]+)')
MYANMAR = rgxcompile(r'([\u1000-\u109F]+)')
GEORGIAN = rgxcompile(r'([\u10A0-\u10FF]+)')
HANGUL_JAMO = rgxcompile(r'([\u1100-\u11FF]+)')
ETHIOPIC = rgxcompile(r'([\u1200-\u137F]+)')
ETHIOPIC_SUPPLEMENT = rgxcompile(r'([\u1380-\u139F]+)')
CHEROKEE = rgxcompile(r'([\u13A0-\u13FF]+)')
UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS = rgxcompile(r'([\u1400-\u167F]+)')
OGHAM = rgxcompile(r'([\u1680-\u169F]+)')
RUNIC = rgxcompile(r'([\u16A0-\u16FF]+)')
TAGALOG = rgxcompile(r'([\u1700-\u171F]+)')
HANUNOO = rgxcompile(r'([\u1720-\u173F]+)')
BUHID = rgxcompile(r'([\u1740-\u175F]+)')
TAGBANWA = rgxcompile(r'([\u1760-\u177F]+)')
KHMER = rgxcompile(r'([\u1780-\u17FF]+)')
MONGOLIAN = rgxcompile(r'([\u1800-\u18AF]+)')
UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED = rgxcompile(r'([\u18B0-\u18FF]+)')
LIMBU = rgxcompile(r'([\u1900-\u194F]+)')
TAI_LE = rgxcompile(r'([\u1950-\u197F]+)')
NEW_TAI_LUE = rgxcompile(r'([\u1980-\u19DF]+)')
KHMER_SYMBOLS = rgxcompile(r'([\u19E0-\u19FF]+)')
BUGINESE = rgxcompile(r'([\u1A00-\u1A1F]+)')
TAI_THAM = rgxcompile(r'([\u1A20-\u1AAF]+)')
COMBINING_DIACRITICAL_MARKS_EXTENDED = rgxcompile(r'([\u1AB0-\u1AFF]+)')
BALINESE = rgxcompile(r'([\u1B00-\u1B7F]+)')
SUNDANESE = rgxcompile(r'([\u1B80-\u1BBF]+)')
BATAK = rgxcompile(r'([\u1BC0-\u1BFF]+)')
LEPCHA = rgxcompile(r'([\u1C00-\u1C4F]+)')
OL_CHIKI = rgxcompile(r'([\u1C50-\u1C7F]+)')
CYRILLIC_EXTENDED_C = rgxcompile(r'([\u1C80-\u1C8F]+)')
GEORGIAN_EXTENDED = rgxcompile(r'([\u1C90-\u1CBF]+)')
SUNDANESE_SUPPLEMENT = rgxcompile(r'([\u1CC0-\u1CCF]+)')
VEDIC_EXTENSIONS = rgxcompile(r'([\u1CD0-\u1CFF]+)')
PHONETIC_EXTENSIONS = rgxcompile(r'([\u1D00-\u1D7F]+)')
PHONETIC_EXTENSIONS_SUPPLEMENT = rgxcompile(r'([\u1D80-\u1DBF]+)')
COMBINING_DIACRITICAL_MARKS_SUPPLEMENT = rgxcompile(r'([\u1DC0-\u1DFF]+)')
LATIN_EXTENDED_ADDITIONAL = rgxcompile(r'([\u1E00-\u1EFF]+)')
GREEK_EXTENDED = rgxcompile(r'([\u1F00-\u1FFF]+)')
GENERAL_PUNCTUATION = rgxcompile(r'([\u2000-\u206F]+)')
SUPERSCRIPTS_AND_SUBSCRIPTS = rgxcompile(r'([\u2070-\u209F]+)')
CURRENCY_SYMBOLS = rgxcompile(r'([\u20A0-\u20CF]+)')
COMBINING_DIACRITICAL_MARKS_FOR_SYMBOLS = rgxcompile(r'([\u20D0-\u20FF]+)')
LETTERLIKE_SYMBOLS = rgxcompile(r'([\u2100-\u214F]+)')
NUMBER_FORMS = rgxcompile(r'([\u2150-\u218F]+)')
ARROWS = rgxcompile(r'([\u2190-\u21FF]+)')
MATHEMATICAL_OPERATORS = rgxcompile(r'([\u2200-\u22FF]+)')
MISCELLANEOUS_TECHNICAL = rgxcompile(r'([\u2300-\u23FF]+)')
CONTROL_PICTURES = rgxcompile(r'([\u2400-\u243F]+)')
OPTICAL_CHARACTER_RECOGNITION = rgxcompile(r'([\u2440-\u245F]+)')
ENCLOSED_ALPHANUMERICS = rgxcompile(r'([\u2460-\u24FF]+)')
BOX_DRAWING = rgxcompile(r'([\u2500-\u257F]+)')
BLOCK_ELEMENTS = rgxcompile(r'([\u2580-\u259F]+)')
GEOMETRIC_SHAPES = rgxcompile(r'([\u25A0-\u25FF]+)')
MISCELLANEOUS_SYMBOLS = rgxcompile(r'([\u2600-\u26FF]+)')
DINGBATS = rgxcompile(r'([\u2700-\u27BF]+)')
MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A = rgxcompile(r'([\u27C0-\u27EF]+)')
SUPPLEMENTAL_ARROWS_A = rgxcompile(r'([\u27F0-\u27FF]+)')
BRAILLE_PATTERNS = rgxcompile(r'([\u2800-\u28FF]+)')
SUPPLEMENTAL_ARROWS_B = rgxcompile(r'([\u2900-\u297F]+)')
MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B = rgxcompile(r'([\u2980-\u29FF]+)')
SUPPLEMENTAL_MATHEMATICAL_OPERATORS = rgxcompile(r'([\u2A00-\u2AFF]+)')
MISCELLANEOUS_SYMBOLS_AND_ARROWS = rgxcompile(r'([\u2B00-\u2BFF]+)')
GLAGOLITIC = rgxcompile(r'([\u2C00-\u2C5F]+)')
LATIN_EXTENDED_C = rgxcompile(r'([\u2C60-\u2C7F]+)')
COPTIC = rgxcompile(r'([\u2C80-\u2CFF]+)')
GEORGIAN_SUPPLEMENT = rgxcompile(r'([\u2D00-\u2D2F]+)')
TIFINAGH = rgxcompile(r'([\u2D30-\u2D7F]+)')
ETHIOPIC_EXTENDED = rgxcompile(r'([\u2D80-\u2DDF]+)')
CYRILLIC_EXTENDED_A = rgxcompile(r'([\u2DE0-\u2DFF]+)')
SUPPLEMENTAL_PUNCTUATION = rgxcompile(r'([\u2E00-\u2E7F]+)')
CJK_RADICALS_SUPPLEMENT = rgxcompile(r'([\u2E80-\u2EFF]+)')
KANGXI_RADICALS = rgxcompile(r'([\u2F00-\u2FDF]+)')
IDEOGRAPHIC_DESCRIPTION_CHARACTERS = rgxcompile(r'([\u2FF0-\u2FFF]+)')
CJK_SYMBOLS_AND_PUNCTUATION = rgxcompile(r'([\u3000-\u303F]+)')
HIRAGANA = rgxcompile(r'([\u3040-\u309F]+)')
KATAKANA = rgxcompile(r'([\u30A0-\u30FF]+)')
BOPOMOFO = rgxcompile(r'([\u3100-\u312F]+)')
HANGUL_COMPATIBILITY_JAMO = rgxcompile(r'([\u3130-\u318F]+)')
KANBUN = rgxcompile(r'([\u3190-\u319F]+)')
BOPOMOFO_EXTENDED = rgxcompile(r'([\u31A0-\u31BF]+)')
CJK_STROKES = rgxcompile(r'([\u31C0-\u31EF]+)')
KATAKANA_PHONETIC_EXTENSIONS = rgxcompile(r'([\u31F0-\u31FF]+)')
ENCLOSED_CJK_LETTERS_AND_MONTHS = rgxcompile(r'([\u3200-\u32FF]+)')
CJK_COMPATIBILITY = rgxcompile(r'([\u3300-\u33FF]+)')
CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A = rgxcompile(r'([\u3400-\u4DBF]+)')
YIJING_HEXAGRAM_SYMBOLS = rgxcompile(r'([\u4DC0-\u4DFF]+)')
CJK_UNIFIED_IDEOGRAPHS = rgxcompile(r'([\u4E00-\u9FFF]+)')
YI_SYLLABLES = rgxcompile(r'([\uA000-\uA48F]+)')
YI_RADICALS = rgxcompile(r'([\uA490-\uA4CF]+)')
LISU = rgxcompile(r'([\uA4D0-\uA4FF]+)')
VAI = rgxcompile(r'([\uA500-\uA63F]+)')
CYRILLIC_EXTENDED_B = rgxcompile(r'([\uA640-\uA69F]+)')
BAMUM = rgxcompile(r'([\uA6A0-\uA6FF]+)')
MODIFIER_TONE_LETTERS = rgxcompile(r'([\uA700-\uA71F]+)')
LATIN_EXTENDED_D = rgxcompile(r'([\uA720-\uA7FF]+)')
SYLOTI_NAGRI = rgxcompile(r'([\uA800-\uA82F]+)')
COMMON_INDIC_NUMBER_FORMS = rgxcompile(r'([\uA830-\uA83F]+)')
PHAGS_PA = rgxcompile(r'([\uA840-\uA87F]+)')
SAURASHTRA = rgxcompile(r'([\uA880-\uA8DF]+)')
DEVANAGARI_EXTENDED = rgxcompile(r'([\uA8E0-\uA8FF]+)')
KAYAH_LI = rgxcompile(r'([\uA900-\uA92F]+)')
REJANG = rgxcompile(r'([\uA930-\uA95F]+)')
HANGUL_JAMO_EXTENDED_A = rgxcompile(r'([\uA960-\uA97F]+)')
JAVANESE = rgxcompile(r'([\uA980-\uA9DF]+)')
MYANMAR_EXTENDED_B = rgxcompile(r'([\uA9E0-\uA9FF]+)')
CHAM = rgxcompile(r'([\uAA00-\uAA5F]+)')
MYANMAR_EXTENDED_A = rgxcompile(r'([\uAA60-\uAA7F]+)')
TAI_VIET = rgxcompile(r'([\uAA80-\uAADF]+)')
MEETEI_MAYEK_EXTENSIONS = rgxcompile(r'([\uAAE0-\uAAFF]+)')
ETHIOPIC_EXTENDED_A = rgxcompile(r'([\uAB00-\uAB2F]+)')
LATIN_EXTENDED_E = rgxcompile(r'([\uAB30-\uAB6F]+)')
CHEROKEE_SUPPLEMENT = rgxcompile(r'([\uAB70-\uABBF]+)')
MEETEI_MAYEK = rgxcompile(r'([\uABC0-\uABFF]+)')
HANGUL_SYLLABLES = rgxcompile(r'([\uAC00-\uD7AF]+)')
HANGUL_JAMO_EXTENDED_B = rgxcompile(r'([\uD7B0-\uD7FF]+)')
HIGH_SURROGATES = rgxcompile(r'([\uD800-\uDB7F]+)')
HIGH_PRIVATE_USE_SURROGATES = rgxcompile(r'([\uDB80-\uDBFF]+)')
LOW_SURROGATES = rgxcompile(r'([\uDC00-\uDFFF]+)')
PRIVATE_USE_AREA = rgxcompile(r'([\uE000-\uF8FF]+)')
CJK_COMPATIBILITY_IDEOGRAPHS = rgxcompile(r'([\uF900-\uFAFF]+)')
ALPHABETIC_PRESENTATION_FORMS = rgxcompile(r'([\uFB00-\uFB4F]+)')
ARABIC_PRESENTATION_FORMS_A = rgxcompile(r'([\uFB50-\uFDFF]+)')
VARIATION_SELECTORS = rgxcompile(r'([\uFE00-\uFE0F]+)')
VERTICAL_FORMS = rgxcompile(r'([\uFE10-\uFE1F]+)')
COMBINING_HALF_MARKS = rgxcompile(r'([\uFE20-\uFE2F]+)')
CJK_COMPATIBILITY_FORMS = rgxcompile(r'([\uFE30-\uFE4F]+)')
SMALL_FORM_VARIANTS = rgxcompile(r'([\uFE50-\uFE6F]+)')
ARABIC_PRESENTATION_FORMS_B = rgxcompile(r'([\uFE70-\uFEFF]+)')
HALFWIDTH_AND_FULLWIDTH_FORMS = rgxcompile(r'([\uFF00-\uFFEF]+)')
SPECIALS = rgxcompile(r'([\uFFF0-\uFFFF]+)')
LINEAR_B_SYLLABARY = rgxcompile(r'([\U00010000-\U0001007F]+)')
LINEAR_B_IDEOGRAMS = rgxcompile(r'([\U00010080-\U000100FF]+)')
AEGEAN_NUMBERS = rgxcompile(r'([\U00010100-\U0001013F]+)')
ANCIENT_GREEK_NUMBERS = rgxcompile(r'([\U00010140-\U0001018F]+)')
ANCIENT_SYMBOLS = rgxcompile(r'([\U00010190-\U000101CF]+)')
PHAISTOS_DISC = rgxcompile(r'([\U000101D0-\U000101FF]+)')
LYCIAN = rgxcompile(r'([\U00010280-\U0001029F]+)')
CARIAN = rgxcompile(r'([\U000102A0-\U000102DF]+)')
COPTIC_EPACT_NUMBERS = rgxcompile(r'([\U000102E0-\U000102FF]+)')
OLD_ITALIC = rgxcompile(r'([\U00010300-\U0001032F]+)')
GOTHIC = rgxcompile(r'([\U00010330-\U0001034F]+)')
OLD_PERMIC = rgxcompile(r'([\U00010350-\U0001037F]+)')
UGARITIC = rgxcompile(r'([\U00010380-\U0001039F]+)')
OLD_PERSIAN = rgxcompile(r'([\U000103A0-\U000103DF]+)')
DESERET = rgxcompile(r'([\U00010400-\U0001044F]+)')
SHAVIAN = rgxcompile(r'([\U00010450-\U0001047F]+)')
OSMANYA = rgxcompile(r'([\U00010480-\U000104AF]+)')
OSAGE = rgxcompile(r'([\U000104B0-\U000104FF]+)')
ELBASAN = rgxcompile(r'([\U00010500-\U0001052F]+)')
CAUCASIAN_ALBANIAN = rgxcompile(r'([\U00010530-\U0001056F]+)')
LINEAR_A = rgxcompile(r'([\U00010600-\U0001077F]+)')
CYPRIOT_SYLLABARY = rgxcompile(r'([\U00010800-\U0001083F]+)')
IMPERIAL_ARAMAIC = rgxcompile(r'([\U00010840-\U0001085F]+)')
PALMYRENE = rgxcompile(r'([\U00010860-\U0001087F]+)')
NABATAEAN = rgxcompile(r'([\U00010880-\U000108AF]+)')
HATRAN = rgxcompile(r'([\U000108E0-\U000108FF]+)')
PHOENICIAN = rgxcompile(r'([\U00010900-\U0001091F]+)')
LYDIAN = rgxcompile(r'([\U00010920-\U0001093F]+)')
MEROITIC_HIEROGLYPHS = rgxcompile(r'([\U00010980-\U0001099F]+)')
MEROITIC_CURSIVE = rgxcompile(r'([\U000109A0-\U000109FF]+)')
KHAROSHTHI = rgxcompile(r'([\U00010A00-\U00010A5F]+)')
OLD_SOUTH_ARABIAN = rgxcompile(r'([\U00010A60-\U00010A7F]+)')
OLD_NORTH_ARABIAN = rgxcompile(r'([\U00010A80-\U00010A9F]+)')
MANICHAEAN = rgxcompile(r'([\U00010AC0-\U00010AFF]+)')
AVESTAN = rgxcompile(r'([\U00010B00-\U00010B3F]+)')
INSCRIPTIONAL_PARTHIAN = rgxcompile(r'([\U00010B40-\U00010B5F]+)')
INSCRIPTIONAL_PAHLAVI = rgxcompile(r'([\U00010B60-\U00010B7F]+)')
PSALTER_PAHLAVI = rgxcompile(r'([\U00010B80-\U00010BAF]+)')
OLD_TURKIC = rgxcompile(r'([\U00010C00-\U00010C4F]+)')
OLD_HUNGARIAN = rgxcompile(r'([\U00010C80-\U00010CFF]+)')
HANIFI_ROHINGYA = rgxcompile(r'([\U00010D00-\U00010D3F]+)')
RUMI_NUMERAL_SYMBOLS = rgxcompile(r'([\U00010E60-\U00010E7F]+)')
OLD_SOGDIAN = rgxcompile(r'([\U00010F00-\U00010F2F]+)')
SOGDIAN = rgxcompile(r'([\U00010F30-\U00010F6F]+)')
BRAHMI = rgxcompile(r'([\U00011000-\U0001107F]+)')
KAITHI = rgxcompile(r'([\U00011080-\U000110CF]+)')
SORA_SOMPENG = rgxcompile(r'([\U000110D0-\U000110FF]+)')
CHAKMA = rgxcompile(r'([\U00011100-\U0001114F]+)')
MAHAJANI = rgxcompile(r'([\U00011150-\U0001117F]+)')
SHARADA = rgxcompile(r'([\U00011180-\U000111DF]+)')
SINHALA_ARCHAIC_NUMBERS = rgxcompile(r'([\U000111E0-\U000111FF]+)')
KHOJKI = rgxcompile(r'([\U00011200-\U0001124F]+)')
MULTANI = rgxcompile(r'([\U00011280-\U000112AF]+)')
KHUDAWADI = rgxcompile(r'([\U000112B0-\U000112FF]+)')
GRANTHA = rgxcompile(r'([\U00011300-\U0001137F]+)')
NEWA = rgxcompile(r'([\U00011400-\U0001147F]+)')
TIRHUTA = rgxcompile(r'([\U00011480-\U000114DF]+)')
SIDDHAM = rgxcompile(r'([\U00011580-\U000115FF]+)')
MODI = rgxcompile(r'([\U00011600-\U0001165F]+)')
MONGOLIAN_SUPPLEMENT = rgxcompile(r'([\U00011660-\U0001167F]+)')
TAKRI = rgxcompile(r'([\U00011680-\U000116CF]+)')
AHOM = rgxcompile(r'([\U00011700-\U0001173F]+)')
DOGRA = rgxcompile(r'([\U00011800-\U0001184F]+)')
WARANG_CITI = rgxcompile(r'([\U000118A0-\U000118FF]+)')
ZANABAZAR_SQUARE = rgxcompile(r'([\U00011A00-\U00011A4F]+)')
SOYOMBO = rgxcompile(r'([\U00011A50-\U00011AAF]+)')
PAU_CIN_HAU = rgxcompile(r'([\U00011AC0-\U00011AFF]+)')
BHAIKSUKI = rgxcompile(r'([\U00011C00-\U00011C6F]+)')
MARCHEN = rgxcompile(r'([\U00011C70-\U00011CBF]+)')
MASARAM_GONDI = rgxcompile(r'([\U00011D00-\U00011D5F]+)')
GUNJALA_GONDI = rgxcompile(r'([\U00011D60-\U00011DAF]+)')
MAKASAR = rgxcompile(r'([\U00011EE0-\U00011EFF]+)')
CUNEIFORM = rgxcompile(r'([\U00012000-\U000123FF]+)')
CUNEIFORM_NUMBERS_AND_PUNCTUATION = rgxcompile(r'([\U00012400-\U0001247F]+)')
EARLY_DYNASTIC_CUNEIFORM = rgxcompile(r'([\U00012480-\U0001254F]+)')
EGYPTIAN_HIEROGLYPHS = rgxcompile(r'([\U00013000-\U0001342F]+)')
ANATOLIAN_HIEROGLYPHS = rgxcompile(r'([\U00014400-\U0001467F]+)')
BAMUM_SUPPLEMENT = rgxcompile(r'([\U00016800-\U00016A3F]+)')
MRO = rgxcompile(r'([\U00016A40-\U00016A6F]+)')
BASSA_VAH = rgxcompile(r'([\U00016AD0-\U00016AFF]+)')
PAHAWH_HMONG = rgxcompile(r'([\U00016B00-\U00016B8F]+)')
MEDEFAIDRIN = rgxcompile(r'([\U00016E40-\U00016E9F]+)')
MIAO = rgxcompile(r'([\U00016F00-\U00016F9F]+)')
IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION = rgxcompile(r'([\U00016FE0-\U00016FFF]+)')
TANGUT = rgxcompile(r'([\U00017000-\U000187FF]+)')
TANGUT_COMPONENTS = rgxcompile(r'([\U00018800-\U00018AFF]+)')
KANA_SUPPLEMENT = rgxcompile(r'([\U0001B000-\U0001B0FF]+)')
KANA_EXTENDED_A = rgxcompile(r'([\U0001B100-\U0001B12F]+)')
NUSHU = rgxcompile(r'([\U0001B170-\U0001B2FF]+)')
DUPLOYAN = rgxcompile(r'([\U0001BC00-\U0001BC9F]+)')
SHORTHAND_FORMAT_CONTROLS = rgxcompile(r'([\U0001BCA0-\U0001BCAF]+)')
BYZANTINE_MUSICAL_SYMBOLS = rgxcompile(r'([\U0001D000-\U0001D0FF]+)')
MUSICAL_SYMBOLS = rgxcompile(r'([\U0001D100-\U0001D1FF]+)')
ANCIENT_GREEK_MUSICAL_NOTATION = rgxcompile(r'([\U0001D200-\U0001D24F]+)')
MAYAN_NUMERALS = rgxcompile(r'([\U0001D2E0-\U0001D2FF]+)')
TAI_XUAN_JING_SYMBOLS = rgxcompile(r'([\U0001D300-\U0001D35F]+)')
COUNTING_ROD_NUMERALS = rgxcompile(r'([\U0001D360-\U0001D37F]+)')
MATHEMATICAL_ALPHANUMERIC_SYMBOLS = rgxcompile(r'([\U0001D400-\U0001D7FF]+)')
SUTTON_SIGNWRITING = rgxcompile(r'([\U0001D800-\U0001DAAF]+)')
GLAGOLITIC_SUPPLEMENT = rgxcompile(r'([\U0001E000-\U0001E02F]+)')
MENDE_KIKAKUI = rgxcompile(r'([\U0001E800-\U0001E8DF]+)')
ADLAM = rgxcompile(r'([\U0001E900-\U0001E95F]+)')
INDIC_SIYAQ_NUMBERS = rgxcompile(r'([\U0001EC70-\U0001ECBF]+)')
ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS = rgxcompile(r'([\U0001EE00-\U0001EEFF]+)')
MAHJONG_TILES = rgxcompile(r'([\U0001F000-\U0001F02F]+)')
DOMINO_TILES = rgxcompile(r'([\U0001F030-\U0001F09F]+)')
PLAYING_CARDS = rgxcompile(r'([\U0001F0A0-\U0001F0FF]+)')
ENCLOSED_ALPHANUMERIC_SUPPLEMENT = rgxcompile(r'([\U0001F100-\U0001F1FF]+)')
ENCLOSED_IDEOGRAPHIC_SUPPLEMENT = rgxcompile(r'([\U0001F200-\U0001F2FF]+)')
MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS = rgxcompile(r'([\U0001F300-\U0001F5FF]+)')
EMOTICONS = rgxcompile(r'([\U0001F600-\U0001F64F]+)')
ORNAMENTAL_DINGBATS = rgxcompile(r'([\U0001F650-\U0001F67F]+)')
TRANSPORT_AND_MAP_SYMBOLS = rgxcompile(r'([\U0001F680-\U0001F6FF]+)')
ALCHEMICAL_SYMBOLS = rgxcompile(r'([\U0001F700-\U0001F77F]+)')
GEOMETRIC_SHAPES_EXTENDED = rgxcompile(r'([\U0001F780-\U0001F7FF]+)')
SUPPLEMENTAL_ARROWS_C = rgxcompile(r'([\U0001F800-\U0001F8FF]+)')
SUPPLEMENTAL_SYMBOLS_AND_PICTOGRAPHS = rgxcompile(r'([\U0001F900-\U0001F9FF]+)')
CHESS_SYMBOLS = rgxcompile(r'([\U0001FA00-\U0001FA6F]+)')
CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B = rgxcompile(r'([\U00020000-\U0002A6DF]+)')
CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C = rgxcompile(r'([\U0002A700-\U0002B73F]+)')
CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D = rgxcompile(r'([\U0002B740-\U0002B81F]+)')
CJK_UNIFIED_IDEOGRAPHS_EXTENSION_E = rgxcompile(r'([\U0002B820-\U0002CEAF]+)')
CJK_UNIFIED_IDEOGRAPHS_EXTENSION_F = rgxcompile(r'([\U0002CEB0-\U0002EBEF]+)')
CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT = rgxcompile(r'([\U0002F800-\U0002FA1F]+)')
TAGS = rgxcompile(r'([\U000E0000-\U000E007F]+)')
VARIATION_SELECTORS_SUPPLEMENT = rgxcompile(r'([\U000E0100-\U000E01EF]+)')
SUPPLEMENTARY_PRIVATE_USE_AREA_A = rgxcompile(r'([\U000F0000-\U000FFFFF]+)')
SUPPLEMENTARY_PRIVATE_USE_AREA_B = rgxcompile(r'([\U00100000-\U0010FFFF]+)')
BMP = rgxcompile(r'([\u0000-\uFFFF]+)')
SMP = rgxcompile(r'([\U00010000-\U0001FA6F]+)')
SIP = rgxcompile(r'([\U00020000-\U0002FA1F]+)')
SSP = rgxcompile(r'([\U000E0000-\U000E01EF]+)')
PUA_A = rgxcompile(r'([\U000F0000-\U000FFFFF]+)')
PUA_B = rgxcompile(r'([\U00100000-\U0010FFFF]+)')
CONTROL_CHARS = rgxcompile(r'([\x00-\x1F\x7F-\x9F]+)')
REGIONAL_INDICATOR = rgxcompile(r'([\U0001F1E6-\U0001F1FF]+)')
EMOJI_MODIFIER_FITZPATRICK = rgxcompile(r'([\U0001F3FB-\U0001F3FF]+)')
INTERLINEAR_ANNOTATIONS = rgxcompile(r'([\uFFF9-\uFFFB]+)')
BIDI_CONTROL_CHARACTERS = rgxcompile(r'([\u061C\u200E\u200F\u202A-\u202E\u2066-\u2069]+)')


# XML SOURCE CODE PATTERNS #


CHARREF = rgxcompile(r'&(#[0-9]+;|#[xX]+[0-9A-Fa-f]+;|[A-Za-z0-9]+;)')
INCOMPLETE_REF = rgxcompile('&[#]?[0-9A-Za-z]+')
ENTITY_REF = rgxcompile('&([0-9A-Za-z]+);')
CHAR_REF = rgxcompile('&#(?:[0-9]+|[Xx][0-9A-Fa-f]+);')
CHAR_REF2 = rgxcompile(
    r'&(#[0-9]+;?'
    r'|#[xX][0-9a-fA-F]+;?'
    r'|[^\t\n\f <&#;]{1,32};?)'
)


# C SOURCE CODE PATTERNS #


DATATYPES: str = r'((((signed|unsigned|)( |)(short|long|long long|)( |)int)|(_BOOL|_Decimal128|_Decimal32|_Decimal64|bool|char|decimal128|decimal32|decimal64|double|enum|FILE|float|float128|float128_t|float64_t|int|int128_t|int16_t|int32_t|int64_t|int8_t|long double|PyObject|string|struct|uint128_t|uint16_t|uint32_t|uint64_t|uint8_t|union|wchar|)|(slint|sllint|ulint|ullint))(\*| \*|\* | \* |))'


DEVELOPER_NOTE = rgxcompile(r'(//|/\*|/\*\*)( |)(DEBUG|DEPRECATED|FINISH|FIX|FIXME|REPAIR|TESTING|TODEBUG|TODO|TOMV|TORM|XXX)(:| |$)')


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

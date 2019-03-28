// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief RUNE character set
@file rune_tables.h
@version 2019.03.28
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
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
*/


/** Alpha ranges; Only covers ranges not in lower||upper */
static const UNUSED Rune align64 _alpha2[320] = {
	0xd8, 0xf6,  // Ø - ö
	0xf8, 0x1f5,  // ø - ǵ
	0x250, 0x2a8,  // ɐ - ʨ
	0x38e, 0x3a1,  // Ύ - Ρ
	0x3a3, 0x3ce,  // Σ - ώ
	0x3d0, 0x3d6,  // ϐ - ϖ
	0x3e2, 0x3f3,  // Ϣ - ϳ
	0x490, 0x4c4,  // Ґ - ӄ
	0x561, 0x587,  // ա - և
	0x5d0, 0x5ea,  // א - ת
	0x5f0, 0x5f2,  // װ - ײ
	0x621, 0x63a,  // ء - غ
	0x640, 0x64a,  // ـ - ي
	0x671, 0x6b7,  // ٱ - ڷ
	0x6ba, 0x6be,  // ں - ھ
	0x6c0, 0x6ce,  // ۀ - ێ
	0x6d0, 0x6d3,  // ې - ۓ
	0x905, 0x939,  // अ - ह
	0x958, 0x961,  // क़ - ॡ
	0x985, 0x98c,  // অ - ঌ
	0x98f, 0x990,  // এ - ঐ
	0x993, 0x9a8,  // ও - ন
	0x9aa, 0x9b0,  // প - র
	0x9b6, 0x9b9,  // শ - হ
	0x9dc, 0x9dd,  // ড় - ঢ়
	0x9df, 0x9e1,  // য় - ৡ
	0x9f0, 0x9f1,  // ৰ - ৱ
	0xa05, 0xa0a,  // ਅ - ਊ
	0xa0f, 0xa10,  // ਏ - ਐ
	0xa13, 0xa28,  // ਓ - ਨ
	0xa2a, 0xa30,  // ਪ - ਰ
	0xa32, 0xa33,  // ਲ - ਲ਼
	0xa35, 0xa36,  // ਵ - ਸ਼
	0xa38, 0xa39,  // ਸ - ਹ
	0xa59, 0xa5c,  // ਖ਼ - ੜ
	0xa85, 0xa8b,  // અ - ઋ
	0xa8f, 0xa91,  // એ - ઑ
	0xa93, 0xaa8,  // ઓ - ન
	0xaaa, 0xab0,  // પ - ર
	0xab2, 0xab3,  // લ - ળ
	0xab5, 0xab9,  // વ - હ
	0xb05, 0xb0c,  // ଅ - ଌ
	0xb0f, 0xb10,  // ଏ - ଐ
	0xb13, 0xb28,  // ଓ - ନ
	0xb2a, 0xb30,  // ପ - ର
	0xb32, 0xb33,  // ଲ - ଳ
	0xb36, 0xb39,  // ଶ - ହ
	0xb5c, 0xb5d,  // ଡ଼ - ଢ଼
	0xb5f, 0xb61,  // ୟ - ୡ
	0xb85, 0xb8a,  // அ - ஊ
	0xb8e, 0xb90,  // எ - ஐ
	0xb92, 0xb95,  // ஒ - க
	0xb99, 0xb9a,  // ங - ச
	0xb9e, 0xb9f,  // ஞ - ட
	0xba3, 0xba4,  // ண - த
	0xba8, 0xbaa,  // ந - ப
	0xbae, 0xbb5,  // ம - வ
	0xbb7, 0xbb9,  // ஷ - ஹ
	0xc05, 0xc0c,  // అ - ఌ
	0xc0e, 0xc10,  // ఎ - ఐ
	0xc12, 0xc28,  // ఒ - న
	0xc2a, 0xc33,  // ప - ళ
	0xc35, 0xc39,  // వ - హ
	0xc60, 0xc61,  // ౠ - ౡ
	0xc85, 0xc8c,  // ಅ - ಌ
	0xc8e, 0xc90,  // ಎ - ಐ
	0xc92, 0xca8,  // ಒ - ನ
	0xcaa, 0xcb3,  // ಪ - ಳ
	0xcb5, 0xcb9,  // ವ - ಹ
	0xce0, 0xce1,  // ೠ - ೡ
	0xd05, 0xd0c,  // അ - ഌ
	0xd0e, 0xd10,  // എ - ഐ
	0xd12, 0xd28,  // ഒ - ന
	0xd2a, 0xd39,  // പ - ഹ
	0xd60, 0xd61,  // ൠ - ൡ
	0xe01, 0xe30,  // ก - ะ
	0xe32, 0xe33,  // า - ำ
	0xe40, 0xe46,  // เ - ๆ
	0xe5a, 0xe5b,  // ๚ - ๛
	0xe81, 0xe82,  // ກ - ຂ
	0xe87, 0xe88,  // ງ - ຈ
	0xe94, 0xe97,  // ດ - ທ
	0xe99, 0xe9f,  // ນ - ຟ
	0xea1, 0xea3,  // ມ - ຣ
	0xeaa, 0xeab,  // ສ - ຫ
	0xead, 0xeae,  // ອ - ຮ
	0xeb2, 0xeb3,  // າ - ຳ
	0xec0, 0xec4,  // ເ - ໄ
	0xedc, 0xedd,  // ໜ - ໝ
	0xf18, 0xf19,  // ༘ - ༙
	0xf40, 0xf47,  // ཀ - ཇ
	0xf49, 0xf69,  // ཉ - ཀྵ
	0x10d0, 0x10f6,  // ა - ჶ
	0x1100, 0x1159,  // ᄀ - ᅙ
	0x115f, 0x11a2,  // ᅟ - ᆢ
	0x11a8, 0x11f9,  // ᆨ - ᇹ
	0x1e00, 0x1e9b,  // Ḁ - ẛ
	0x1f50, 0x1f57,  // ὐ - ὗ
	0x1f80, 0x1fb4,  // ᾀ - ᾴ
	0x1fb6, 0x1fbc,  // ᾶ - ᾼ
	0x1fc2, 0x1fc4,  // ῂ - ῄ
	0x1fc6, 0x1fcc,  // ῆ - ῌ
	0x1fd0, 0x1fd3,  // ῐ - ΐ
	0x1fd6, 0x1fdb,  // ῖ - Ί
	0x1fe0, 0x1fec,  // ῠ - Ῥ
	0x1ff2, 0x1ff4,  // ῲ - ῴ
	0x1ff6, 0x1ffc,  // ῶ - ῼ
	0x210a, 0x2113,  // ℊ - ℓ
	0x2115, 0x211d,  // ℕ - ℝ
	0x2120, 0x2122,  // ℠ - ™
	0x212a, 0x2131,  // K - ℱ
	0x2133, 0x2138,  // ℳ - ℸ
	0x3041, 0x3094,  // ぁ - ゔ
	0x30a1, 0x30fa,  // ァ - ヺ
	0x3105, 0x312c,  // ㄅ - ㄬ
	0x3131, 0x318e,  // ㄱ - ㆎ
	0x3192, 0x319f,  // ㆒ - ㆟
	0x3260, 0x327b,  // ㉠ - ㉻
	0x328a, 0x32b0,  // ㊊ - ㊰
	0x32d0, 0x32fe,  // ㋐ - ㋾
	0x3300, 0x3357,  // ㌀ - ㍗
	0x3371, 0x3376,  // ㍱ - ㍶
	0x337b, 0x3394,  // ㍻ - ㎔
	0x3399, 0x339e,  // ㎙ - ㎞
	0x33a9, 0x33ad,  // ㎩ - ㎭
	0x33b0, 0x33c1,  // ㎰ - ㏁
	0x33c3, 0x33c5,  // ㏃ - ㏅
	0x33c7, 0x33d7,  // ㏇ - ㏗
	0x33d9, 0x33dd,  // ㏙ - ㏝
	0x4e00, 0x9fff,  // 一 - 鿿
	0xac00, 0xd7a3,  // 가 - 힣
	0xf900, 0xfb06,  // 豈 - ﬆ
	0xfb13, 0xfb17,  // ﬓ - ﬗ
	0xfb1f, 0xfb28,  // ײַ - ﬨ
	0xfb2a, 0xfb36,  // שׁ - זּ
	0xfb38, 0xfb3c,  // טּ - לּ
	0xfb40, 0xfb41,  // נּ - סּ
	0xfb43, 0xfb44,  // ףּ - פּ
	0xfb46, 0xfbb1,  // צּ - ﮱ
	0xfbd3, 0xfd3d,  // ﯓ - ﴽ
	0xfd50, 0xfd8f,  // ﵐ - ﶏ
	0xfd92, 0xfdc7,  // ﶒ - ﷇ
	0xfdf0, 0xfdf9,  // ﷰ - ﷹ
	0xfe70, 0xfe72,  // ﹰ - ﹲ
	0xfe76, 0xfefc,  // ﹶ - ﻼ
	0xff66, 0xff6f,  // ｦ - ｯ
	0xff71, 0xff9d,  // ｱ - ﾝ
	0xffa0, 0xffbe,  // ﾠ - ﾾ
	0xffc2, 0xffc7,  // ￂ - ￇ
	0xffca, 0xffcf,  // ￊ - ￏ
	0xffd2, 0xffd7,  // ￒ - ￗ
	0xffda, 0xffdc  // ￚ - ￜ
};


/** Alpha singlets; Only covers ranges not in lower||upper */
static const UNUSED Rune align64 _alpha1[32] = {
	0xaa,  // ª
	0xb5,  // µ
	0xba,  // º
	0x3da,  // Ϛ
	0x3dc,  // Ϝ
	0x3de,  // Ϟ
	0x3e0,  // Ϡ
	0x6d5,  // ە
	0x9b2,  // ল
	0xa5e,  // ਫ਼
	0xa8d,  // ઍ
	0xae0,  // ૠ
	0xb9c,  // ஜ
	0xcde,  // ೞ
	0xe4f,  // ๏
	0xe84,  // ຄ
	0xe8a,  // ຊ
	0xe8d,  // ຍ
	0xea5,  // ລ
	0xea7,  // ວ
	0xeb0,  // ະ
	0xebd,  // ຽ
	0x1fbe,  // ι
	0x207f,  // ⁿ
	0x20a8,  // ₨
	0x2102,  // ℂ
	0x2107,  // ℇ
	0x2124,  // ℤ
	0x2126,  // Ω
	0x2128,  // ℨ
	0xfb3e,  // מּ
	0xfe74  // ﹴ
};


/** Space ranges */
static const UNUSED Rune align64 _space2[16] = {
	9, 0xa,  // tab and newline
	0x20, 0x20,  // space
	0xa0, 0xa0,
	0x2000, 0x200b,
	0x2028, 0x2029,
	0x3000, 0x3000,
	0xfeff, 0xfeff
};


/** Lower case ranges; 3rd col is conversion excess 500 */
static const UNUSED Rune align64 _toupper2[128] = {
	0x61, 0x7a, 468,  // a-z A-Z
	0xe0, 0xf6, 468,  // à-ö À-Ö
	0xf8, 0xfe, 468,  // ø-þ Ø-Þ
	0x256, 0x257, 295,  // ɖ-ɗ Ɖ-Ɗ
	0x258, 0x259, 298,  // ɘ-ə Ǝ-Ə
	0x28a, 0x28b, 283,  // ʊ-ʋ Ʊ-Ʋ
	0x3ad, 0x3af, 463,  // έ-ί Έ-Ί
	0x3b1, 0x3c1, 468,  // α-ρ Α-Ρ
	0x3c3, 0x3cb, 468,  // σ-ϋ Σ-Ϋ
	0x3cd, 0x3ce, 437,  // ύ-ώ Ύ-Ώ
	0x430, 0x44f, 468,  // а-я А-Я
	0x451, 0x45c, 420,  // ё-ќ Ё-Ќ
	0x45e, 0x45f, 420,  // ў-џ Ў-Џ
	0x561, 0x586, 452,  // ա-ֆ Ա-Ֆ
	0x1f00, 0x1f07, 508,  // ἀ-ἇ Ἀ-Ἇ
	0x1f10, 0x1f15, 508,  // ἐ-ἕ Ἐ-Ἕ
	0x1f20, 0x1f27, 508,  // ἠ-ἧ Ἠ-Ἧ
	0x1f30, 0x1f37, 508,  // ἰ-ἷ Ἰ-Ἷ
	0x1f40, 0x1f45, 508,  // ὀ-ὅ Ὀ-Ὅ
	0x1f60, 0x1f67, 508,  // ὠ-ὧ Ὠ-Ὧ
	0x1f70, 0x1f71, 574,  // ὰ-ά Ὰ-Ά
	0x1f72, 0x1f75, 586,  // ὲ-ή Ὲ-Ή
	0x1f76, 0x1f77, 600,  // ὶ-ί Ὶ-Ί
	0x1f78, 0x1f79, 628,  // ὸ-ό Ὸ-Ό
	0x1f7a, 0x1f7b, 612,  // ὺ-ύ Ὺ-Ύ
	0x1f7c, 0x1f7d, 626,  // ὼ-ώ Ὼ-Ώ
	0x1f80, 0x1f87, 508,  // ᾀ-ᾇ ᾈ-ᾏ
	0x1f90, 0x1f97, 508,  // ᾐ-ᾗ ᾘ-ᾟ
	0x1fa0, 0x1fa7, 508,  // ᾠ-ᾧ ᾨ-ᾯ
	0x1fb0, 0x1fb1, 508,  // ᾰ-ᾱ Ᾰ-Ᾱ
	0x1fd0, 0x1fd1, 508,  // ῐ-ῑ Ῐ-Ῑ
	0x1fe0, 0x1fe1, 508,  // ῠ-ῡ Ῠ-Ῡ
	0x2170, 0x217f, 484,  // ⅰ-ⅿ Ⅰ-Ⅿ
	0x24d0, 0x24e9, 474,  // ⓐ-ⓩ Ⓐ-Ⓩ
	0xff41, 0xff5a, 468  // ａ-ｚ Ａ-Ｚ
};


/** Lower case singlets; 2nd col is conversion excess 500 */
static const UNUSED Rune align64 _toupper1[768] = {
	0xff, 621,  // ÿ Ÿ
	0x101, 499,  // ā Ā
	0x103, 499,  // ă Ă
	0x105, 499,  // ą Ą
	0x107, 499,  // ć Ć
	0x109, 499,  // ĉ Ĉ
	0x10b, 499,  // ċ Ċ
	0x10d, 499,  // č Č
	0x10f, 499,  // ď Ď
	0x111, 499,  // đ Đ
	0x113, 499,  // ē Ē
	0x115, 499,  // ĕ Ĕ
	0x117, 499,  // ė Ė
	0x119, 499,  // ę Ę
	0x11b, 499,  // ě Ě
	0x11d, 499,  // ĝ Ĝ
	0x11f, 499,  // ğ Ğ
	0x121, 499,  // ġ Ġ
	0x123, 499,  // ģ Ģ
	0x125, 499,  // ĥ Ĥ
	0x127, 499,  // ħ Ħ
	0x129, 499,  // ĩ Ĩ
	0x12b, 499,  // ī Ī
	0x12d, 499,  // ĭ Ĭ
	0x12f, 499,  // į Į
	0x131, 268,  // ı I
	0x133, 499,  // ĳ Ĳ
	0x135, 499,  // ĵ Ĵ
	0x137, 499,  // ķ Ķ
	0x13a, 499,  // ĺ Ĺ
	0x13c, 499,  // ļ Ļ
	0x13e, 499,  // ľ Ľ
	0x140, 499,  // ŀ Ŀ
	0x142, 499,  // ł Ł
	0x144, 499,  // ń Ń
	0x146, 499,  // ņ Ņ
	0x148, 499,  // ň Ň
	0x14b, 499,  // ŋ Ŋ
	0x14d, 499,  // ō Ō
	0x14f, 499,  // ŏ Ŏ
	0x151, 499,  // ő Ő
	0x153, 499,  // œ Œ
	0x155, 499,  // ŕ Ŕ
	0x157, 499,  // ŗ Ŗ
	0x159, 499,  // ř Ř
	0x15b, 499,  // ś Ś
	0x15d, 499,  // ŝ Ŝ
	0x15f, 499,  // ş Ş
	0x161, 499,  // š Š
	0x163, 499,  // ţ Ţ
	0x165, 499,  // ť Ť
	0x167, 499,  // ŧ Ŧ
	0x169, 499,  // ũ Ũ
	0x16b, 499,  // ū Ū
	0x16d, 499,  // ŭ Ŭ
	0x16f, 499,  // ů Ů
	0x171, 499,  // ű Ű
	0x173, 499,  // ų Ų
	0x175, 499,  // ŵ Ŵ
	0x177, 499,  // ŷ Ŷ
	0x17a, 499,  // ź Ź
	0x17c, 499,  // ż Ż
	0x17e, 499,  // ž Ž
	0x17f, 200,  // ſ S
	0x183, 499,  // ƃ Ƃ
	0x185, 499,  // ƅ Ƅ
	0x188, 499,  // ƈ Ƈ
	0x18c, 499,  // ƌ Ƌ
	0x192, 499,  // ƒ Ƒ
	0x199, 499,  // ƙ Ƙ
	0x1a1, 499,  // ơ Ơ
	0x1a3, 499,  // ƣ Ƣ
	0x1a5, 499,  // ƥ Ƥ
	0x1a8, 499,  // ƨ Ƨ
	0x1ad, 499,  // ƭ Ƭ
	0x1b0, 499,  // ư Ư
	0x1b4, 499,  // ƴ Ƴ
	0x1b6, 499,  // ƶ Ƶ
	0x1b9, 499,  // ƹ Ƹ
	0x1bd, 499,  // ƽ Ƽ
	0x1c5, 499,  // ǅ Ǆ
	0x1c6, 498,  // ǆ Ǆ
	0x1c8, 499,  // ǈ Ǉ
	0x1c9, 498,  // ǉ Ǉ
	0x1cb, 499,  // ǋ Ǌ
	0x1cc, 498,  // ǌ Ǌ
	0x1ce, 499,  // ǎ Ǎ
	0x1d0, 499,  // ǐ Ǐ
	0x1d2, 499,  // ǒ Ǒ
	0x1d4, 499,  // ǔ Ǔ
	0x1d6, 499,  // ǖ Ǖ
	0x1d8, 499,  // ǘ Ǘ
	0x1da, 499,  // ǚ Ǚ
	0x1dc, 499,  // ǜ Ǜ
	0x1df, 499,  // ǟ Ǟ
	0x1e1, 499,  // ǡ Ǡ
	0x1e3, 499,  // ǣ Ǣ
	0x1e5, 499,  // ǥ Ǥ
	0x1e7, 499,  // ǧ Ǧ
	0x1e9, 499,  // ǩ Ǩ
	0x1eb, 499,  // ǫ Ǫ
	0x1ed, 499,  // ǭ Ǭ
	0x1ef, 499,  // ǯ Ǯ
	0x1f2, 499,  // ǲ Ǳ
	0x1f3, 498,  // ǳ Ǳ
	0x1f5, 499,  // ǵ Ǵ
	0x1fb, 499,  // ǻ Ǻ
	0x1fd, 499,  // ǽ Ǽ
	0x1ff, 499,  // ǿ Ǿ
	0x201, 499,  // ȁ Ȁ
	0x203, 499,  // ȃ Ȃ
	0x205, 499,  // ȅ Ȅ
	0x207, 499,  // ȇ Ȇ
	0x209, 499,  // ȉ Ȉ
	0x20b, 499,  // ȋ Ȋ
	0x20d, 499,  // ȍ Ȍ
	0x20f, 499,  // ȏ Ȏ
	0x211, 499,  // ȑ Ȑ
	0x213, 499,  // ȓ Ȓ
	0x215, 499,  // ȕ Ȕ
	0x217, 499,  // ȗ Ȗ
	0x253, 290,  // ɓ Ɓ
	0x254, 294,  // ɔ Ɔ
	0x25b, 297,  // ɛ Ɛ
	0x260, 295,  // ɠ Ɠ
	0x263, 293,  // ɣ Ɣ
	0x268, 291,  // ɨ Ɨ
	0x269, 289,  // ɩ Ɩ
	0x26f, 289,  // ɯ Ɯ
	0x272, 287,  // ɲ Ɲ
	0x283, 282,  // ʃ Ʃ
	0x288, 282,  // ʈ Ʈ
	0x292, 281,  // ʒ Ʒ
	0x3ac, 462,  // ά Ά
	0x3cc, 436,  // ό Ό
	0x3d0, 438,  // ϐ Β
	0x3d1, 443,  // ϑ Θ
	0x3d5, 453,  // ϕ Φ
	0x3d6, 446,  // ϖ Π
	0x3e3, 499,  // ϣ Ϣ
	0x3e5, 499,  // ϥ Ϥ
	0x3e7, 499,  // ϧ Ϧ
	0x3e9, 499,  // ϩ Ϩ
	0x3eb, 499,  // ϫ Ϫ
	0x3ed, 499,  // ϭ Ϭ
	0x3ef, 499,  // ϯ Ϯ
	0x3f0, 414,  // ϰ Κ
	0x3f1, 420,  // ϱ Ρ
	0x461, 499,  // ѡ Ѡ
	0x463, 499,  // ѣ Ѣ
	0x465, 499,  // ѥ Ѥ
	0x467, 499,  // ѧ Ѧ
	0x469, 499,  // ѩ Ѩ
	0x46b, 499,  // ѫ Ѫ
	0x46d, 499,  // ѭ Ѭ
	0x46f, 499,  // ѯ Ѯ
	0x471, 499,  // ѱ Ѱ
	0x473, 499,  // ѳ Ѳ
	0x475, 499,  // ѵ Ѵ
	0x477, 499,  // ѷ Ѷ
	0x479, 499,  // ѹ Ѹ
	0x47b, 499,  // ѻ Ѻ
	0x47d, 499,  // ѽ Ѽ
	0x47f, 499,  // ѿ Ѿ
	0x481, 499,  // ҁ Ҁ
	0x491, 499,  // ґ Ґ
	0x493, 499,  // ғ Ғ
	0x495, 499,  // ҕ Ҕ
	0x497, 499,  // җ Җ
	0x499, 499,  // ҙ Ҙ
	0x49b, 499,  // қ Қ
	0x49d, 499,  // ҝ Ҝ
	0x49f, 499,  // ҟ Ҟ
	0x4a1, 499,  // ҡ Ҡ
	0x4a3, 499,  // ң Ң
	0x4a5, 499,  // ҥ Ҥ
	0x4a7, 499,  // ҧ Ҧ
	0x4a9, 499,  // ҩ Ҩ
	0x4ab, 499,  // ҫ Ҫ
	0x4ad, 499,  // ҭ Ҭ
	0x4af, 499,  // ү Ү
	0x4b1, 499,  // ұ Ұ
	0x4b3, 499,  // ҳ Ҳ
	0x4b5, 499,  // ҵ Ҵ
	0x4b7, 499,  // ҷ Ҷ
	0x4b9, 499,  // ҹ Ҹ
	0x4bb, 499,  // һ Һ
	0x4bd, 499,  // ҽ Ҽ
	0x4bf, 499,  // ҿ Ҿ
	0x4c2, 499,  // ӂ Ӂ
	0x4c4, 499,  // ӄ Ӄ
	0x4c8, 499,  // ӈ Ӈ
	0x4cc, 499,  // ӌ Ӌ
	0x4d1, 499,  // ӑ Ӑ
	0x4d3, 499,  // ӓ Ӓ
	0x4d5, 499,  // ӕ Ӕ
	0x4d7, 499,  // ӗ Ӗ
	0x4d9, 499,  // ә Ә
	0x4db, 499,  // ӛ Ӛ
	0x4dd, 499,  // ӝ Ӝ
	0x4df, 499,  // ӟ Ӟ
	0x4e1, 499,  // ӡ Ӡ
	0x4e3, 499,  // ӣ Ӣ
	0x4e5, 499,  // ӥ Ӥ
	0x4e7, 499,  // ӧ Ӧ
	0x4e9, 499,  // ө Ө
	0x4eb, 499,  // ӫ Ӫ
	0x4ef, 499,  // ӯ Ӯ
	0x4f1, 499,  // ӱ Ӱ
	0x4f3, 499,  // ӳ Ӳ
	0x4f5, 499,  // ӵ Ӵ
	0x4f9, 499,  // ӹ Ӹ
	0x1e01, 499,  // ḁ Ḁ
	0x1e03, 499,  // ḃ Ḃ
	0x1e05, 499,  // ḅ Ḅ
	0x1e07, 499,  // ḇ Ḇ
	0x1e09, 499,  // ḉ Ḉ
	0x1e0b, 499,  // ḋ Ḋ
	0x1e0d, 499,  // ḍ Ḍ
	0x1e0f, 499,  // ḏ Ḏ
	0x1e11, 499,  // ḑ Ḑ
	0x1e13, 499,  // ḓ Ḓ
	0x1e15, 499,  // ḕ Ḕ
	0x1e17, 499,  // ḗ Ḗ
	0x1e19, 499,  // ḙ Ḙ
	0x1e1b, 499,  // ḛ Ḛ
	0x1e1d, 499,  // ḝ Ḝ
	0x1e1f, 499,  // ḟ Ḟ
	0x1e21, 499,  // ḡ Ḡ
	0x1e23, 499,  // ḣ Ḣ
	0x1e25, 499,  // ḥ Ḥ
	0x1e27, 499,  // ḧ Ḧ
	0x1e29, 499,  // ḩ Ḩ
	0x1e2b, 499,  // ḫ Ḫ
	0x1e2d, 499,  // ḭ Ḭ
	0x1e2f, 499,  // ḯ Ḯ
	0x1e31, 499,  // ḱ Ḱ
	0x1e33, 499,  // ḳ Ḳ
	0x1e35, 499,  // ḵ Ḵ
	0x1e37, 499,  // ḷ Ḷ
	0x1e39, 499,  // ḹ Ḹ
	0x1e3b, 499,  // ḻ Ḻ
	0x1e3d, 499,  // ḽ Ḽ
	0x1e3f, 499,  // ḿ Ḿ
	0x1e41, 499,  // ṁ Ṁ
	0x1e43, 499,  // ṃ Ṃ
	0x1e45, 499,  // ṅ Ṅ
	0x1e47, 499,  // ṇ Ṇ
	0x1e49, 499,  // ṉ Ṉ
	0x1e4b, 499,  // ṋ Ṋ
	0x1e4d, 499,  // ṍ Ṍ
	0x1e4f, 499,  // ṏ Ṏ
	0x1e51, 499,  // ṑ Ṑ
	0x1e53, 499,  // ṓ Ṓ
	0x1e55, 499,  // ṕ Ṕ
	0x1e57, 499,  // ṗ Ṗ
	0x1e59, 499,  // ṙ Ṙ
	0x1e5b, 499,  // ṛ Ṛ
	0x1e5d, 499,  // ṝ Ṝ
	0x1e5f, 499,  // ṟ Ṟ
	0x1e61, 499,  // ṡ Ṡ
	0x1e63, 499,  // ṣ Ṣ
	0x1e65, 499,  // ṥ Ṥ
	0x1e67, 499,  // ṧ Ṧ
	0x1e69, 499,  // ṩ Ṩ
	0x1e6b, 499,  // ṫ Ṫ
	0x1e6d, 499,  // ṭ Ṭ
	0x1e6f, 499,  // ṯ Ṯ
	0x1e71, 499,  // ṱ Ṱ
	0x1e73, 499,  // ṳ Ṳ
	0x1e75, 499,  // ṵ Ṵ
	0x1e77, 499,  // ṷ Ṷ
	0x1e79, 499,  // ṹ Ṹ
	0x1e7b, 499,  // ṻ Ṻ
	0x1e7d, 499,  // ṽ Ṽ
	0x1e7f, 499,  // ṿ Ṿ
	0x1e81, 499,  // ẁ Ẁ
	0x1e83, 499,  // ẃ Ẃ
	0x1e85, 499,  // ẅ Ẅ
	0x1e87, 499,  // ẇ Ẇ
	0x1e89, 499,  // ẉ Ẉ
	0x1e8b, 499,  // ẋ Ẋ
	0x1e8d, 499,  // ẍ Ẍ
	0x1e8f, 499,  // ẏ Ẏ
	0x1e91, 499,  // ẑ Ẑ
	0x1e93, 499,  // ẓ Ẓ
	0x1e95, 499,  // ẕ Ẕ
	0x1ea1, 499,  // ạ Ạ
	0x1ea3, 499,  // ả Ả
	0x1ea5, 499,  // ấ Ấ
	0x1ea7, 499,  // ầ Ầ
	0x1ea9, 499,  // ẩ Ẩ
	0x1eab, 499,  // ẫ Ẫ
	0x1ead, 499,  // ậ Ậ
	0x1eaf, 499,  // ắ Ắ
	0x1eb1, 499,  // ằ Ằ
	0x1eb3, 499,  // ẳ Ẳ
	0x1eb5, 499,  // ẵ Ẵ
	0x1eb7, 499,  // ặ Ặ
	0x1eb9, 499,  // ẹ Ẹ
	0x1ebb, 499,  // ẻ Ẻ
	0x1ebd, 499,  // ẽ Ẽ
	0x1ebf, 499,  // ế Ế
	0x1ec1, 499,  // ề Ề
	0x1ec3, 499,  // ể Ể
	0x1ec5, 499,  // ễ Ễ
	0x1ec7, 499,  // ệ Ệ
	0x1ec9, 499,  // ỉ Ỉ
	0x1ecb, 499,  // ị Ị
	0x1ecd, 499,  // ọ Ọ
	0x1ecf, 499,  // ỏ Ỏ
	0x1ed1, 499,  // ố Ố
	0x1ed3, 499,  // ồ Ồ
	0x1ed5, 499,  // ổ Ổ
	0x1ed7, 499,  // ỗ Ỗ
	0x1ed9, 499,  // ộ Ộ
	0x1edb, 499,  // ớ Ớ
	0x1edd, 499,  // ờ Ờ
	0x1edf, 499,  // ở Ở
	0x1ee1, 499,  // ỡ Ỡ
	0x1ee3, 499,  // ợ Ợ
	0x1ee5, 499,  // ụ Ụ
	0x1ee7, 499,  // ủ Ủ
	0x1ee9, 499,  // ứ Ứ
	0x1eeb, 499,  // ừ Ừ
	0x1eed, 499,  // ử Ử
	0x1eef, 499,  // ữ Ữ
	0x1ef1, 499,  // ự Ự
	0x1ef3, 499,  // ỳ Ỳ
	0x1ef5, 499,  // ỵ Ỵ
	0x1ef7, 499,  // ỷ Ỷ
	0x1ef9, 499,  // ỹ Ỹ
	0x1f51, 508,  // ὑ Ὑ
	0x1f53, 508,  // ὓ Ὓ
	0x1f55, 508,  // ὕ Ὕ
	0x1f57, 508,  // ὗ Ὗ
	0x1fb3, 509,  // ᾳ ᾼ
	0x1fc3, 509,  // ῃ ῌ
	0x1fe5, 507,  // ῥ Ῥ
	0x1ff3, 509  // ῳ ῼ
};


/** Upper case ranges; 3rd col is conversion excess 500 */
static const UNUSED Rune align64 _tolower2[128] = {
	0x41, 0x5a, 532,  // A-Z a-z
	0xc0, 0xd6, 532,  // À-Ö à-ö
	0xd8, 0xde, 532,  // Ø-Þ ø-þ
	0x189, 0x18a, 705,  // Ɖ-Ɗ ɖ-ɗ
	0x18e, 0x18f, 702,  // Ǝ-Ə ɘ-ə
	0x1b1, 0x1b2, 717,  // Ʊ-Ʋ ʊ-ʋ
	0x388, 0x38a, 537,  // Έ-Ί έ-ί
	0x38e, 0x38f, 563,  // Ύ-Ώ ύ-ώ
	0x391, 0x3a1, 532,  // Α-Ρ α-ρ
	0x3a3, 0x3ab, 532,  // Σ-Ϋ σ-ϋ
	0x401, 0x40c, 580,  // Ё-Ќ ё-ќ
	0x40e, 0x40f, 580,  // Ў-Џ ў-џ
	0x410, 0x42f, 532,  // А-Я а-я
	0x531, 0x556, 548,  // Ա-Ֆ ա-ֆ
	0x10a0, 0x10c5, 548,  // Ⴀ-Ⴥ ა-ჵ
	0x1f08, 0x1f0f, 492,  // Ἀ-Ἇ ἀ-ἇ
	0x1f18, 0x1f1d, 492,  // Ἐ-Ἕ ἐ-ἕ
	0x1f28, 0x1f2f, 492,  // Ἠ-Ἧ ἠ-ἧ
	0x1f38, 0x1f3f, 492,  // Ἰ-Ἷ ἰ-ἷ
	0x1f48, 0x1f4d, 492,  // Ὀ-Ὅ ὀ-ὅ
	0x1f68, 0x1f6f, 492,  // Ὠ-Ὧ ὠ-ὧ
	0x1f88, 0x1f8f, 492,  // ᾈ-ᾏ ᾀ-ᾇ
	0x1f98, 0x1f9f, 492,  // ᾘ-ᾟ ᾐ-ᾗ
	0x1fa8, 0x1faf, 492,  // ᾨ-ᾯ ᾠ-ᾧ
	0x1fb8, 0x1fb9, 492,  // Ᾰ-Ᾱ ᾰ-ᾱ
	0x1fba, 0x1fbb, 426,  // Ὰ-Ά ὰ-ά
	0x1fc8, 0x1fcb, 414,  // Ὲ-Ή ὲ-ή
	0x1fd8, 0x1fd9, 492,  // Ῐ-Ῑ ῐ-ῑ
	0x1fda, 0x1fdb, 400,  // Ὶ-Ί ὶ-ί
	0x1fe8, 0x1fe9, 492,  // Ῠ-Ῡ ῠ-ῡ
	0x1fea, 0x1feb, 388,  // Ὺ-Ύ ὺ-ύ
	0x1ff8, 0x1ff9, 372,  // Ὸ-Ό ὸ-ό
	0x1ffa, 0x1ffb, 374,  // Ὼ-Ώ ὼ-ώ
	0x2160, 0x216f, 516,  // Ⅰ-Ⅿ ⅰ-ⅿ
	0x24b6, 0x24cf, 526,  // Ⓐ-Ⓩ ⓐ-ⓩ
	0xff21, 0xff3a, 532  // Ａ-Ｚ ａ-ｚ
};


/** Upper case singlets; 2nd col is conversion excess 500 */
static const UNUSED Rune align64 _tolower1[768] = {
	0x100, 501,  // Ā ā
	0x102, 501,  // Ă ă
	0x104, 501,  // Ą ą
	0x106, 501,  // Ć ć
	0x108, 501,  // Ĉ ĉ
	0x10a, 501,  // Ċ ċ
	0x10c, 501,  // Č č
	0x10e, 501,  // Ď ď
	0x110, 501,  // Đ đ
	0x112, 501,  // Ē ē
	0x114, 501,  // Ĕ ĕ
	0x116, 501,  // Ė ė
	0x118, 501,  // Ę ę
	0x11a, 501,  // Ě ě
	0x11c, 501,  // Ĝ ĝ
	0x11e, 501,  // Ğ ğ
	0x120, 501,  // Ġ ġ
	0x122, 501,  // Ģ ģ
	0x124, 501,  // Ĥ ĥ
	0x126, 501,  // Ħ ħ
	0x128, 501,  // Ĩ ĩ
	0x12a, 501,  // Ī ī
	0x12c, 501,  // Ĭ ĭ
	0x12e, 501,  // Į į
	0x130, 301,  // İ i
	0x132, 501,  // Ĳ ĳ
	0x134, 501,  // Ĵ ĵ
	0x136, 501,  // Ķ ķ
	0x139, 501,  // Ĺ ĺ
	0x13b, 501,  // Ļ ļ
	0x13d, 501,  // Ľ ľ
	0x13f, 501,  // Ŀ ŀ
	0x141, 501,  // Ł ł
	0x143, 501,  // Ń ń
	0x145, 501,  // Ņ ņ
	0x147, 501,  // Ň ň
	0x14a, 501,  // Ŋ ŋ
	0x14c, 501,  // Ō ō
	0x14e, 501,  // Ŏ ŏ
	0x150, 501,  // Ő ő
	0x152, 501,  // Œ œ
	0x154, 501,  // Ŕ ŕ
	0x156, 501,  // Ŗ ŗ
	0x158, 501,  // Ř ř
	0x15a, 501,  // Ś ś
	0x15c, 501,  // Ŝ ŝ
	0x15e, 501,  // Ş ş
	0x160, 501,  // Š š
	0x162, 501,  // Ţ ţ
	0x164, 501,  // Ť ť
	0x166, 501,  // Ŧ ŧ
	0x168, 501,  // Ũ ũ
	0x16a, 501,  // Ū ū
	0x16c, 501,  // Ŭ ŭ
	0x16e, 501,  // Ů ů
	0x170, 501,  // Ű ű
	0x172, 501,  // Ų ų
	0x174, 501,  // Ŵ ŵ
	0x176, 501,  // Ŷ ŷ
	0x178, 379,  // Ÿ ÿ
	0x179, 501,  // Ź ź
	0x17b, 501,  // Ż ż
	0x17d, 501,  // Ž ž
	0x181, 710,  // Ɓ ɓ
	0x182, 501,  // Ƃ ƃ
	0x184, 501,  // Ƅ ƅ
	0x186, 706,  // Ɔ ɔ
	0x187, 501,  // Ƈ ƈ
	0x18b, 501,  // Ƌ ƌ
	0x190, 703,  // Ɛ ɛ
	0x191, 501,  // Ƒ ƒ
	0x193, 705,  // Ɠ ɠ
	0x194, 707,  // Ɣ ɣ
	0x196, 711,  // Ɩ ɩ
	0x197, 709,  // Ɨ ɨ
	0x198, 501,  // Ƙ ƙ
	0x19c, 711,  // Ɯ ɯ
	0x19d, 713,  // Ɲ ɲ
	0x1a0, 501,  // Ơ ơ
	0x1a2, 501,  // Ƣ ƣ
	0x1a4, 501,  // Ƥ ƥ
	0x1a7, 501,  // Ƨ ƨ
	0x1a9, 718,  // Ʃ ʃ
	0x1ac, 501,  // Ƭ ƭ
	0x1ae, 718,  // Ʈ ʈ
	0x1af, 501,  // Ư ư
	0x1b3, 501,  // Ƴ ƴ
	0x1b5, 501,  // Ƶ ƶ
	0x1b7, 719,  // Ʒ ʒ
	0x1b8, 501,  // Ƹ ƹ
	0x1bc, 501,  // Ƽ ƽ
	0x1c4, 502,  // Ǆ ǆ
	0x1c5, 501,  // ǅ ǆ
	0x1c7, 502,  // Ǉ ǉ
	0x1c8, 501,  // ǈ ǉ
	0x1ca, 502,  // Ǌ ǌ
	0x1cb, 501,  // ǋ ǌ
	0x1cd, 501,  // Ǎ ǎ
	0x1cf, 501,  // Ǐ ǐ
	0x1d1, 501,  // Ǒ ǒ
	0x1d3, 501,  // Ǔ ǔ
	0x1d5, 501,  // Ǖ ǖ
	0x1d7, 501,  // Ǘ ǘ
	0x1d9, 501,  // Ǚ ǚ
	0x1db, 501,  // Ǜ ǜ
	0x1de, 501,  // Ǟ ǟ
	0x1e0, 501,  // Ǡ ǡ
	0x1e2, 501,  // Ǣ ǣ
	0x1e4, 501,  // Ǥ ǥ
	0x1e6, 501,  // Ǧ ǧ
	0x1e8, 501,  // Ǩ ǩ
	0x1ea, 501,  // Ǫ ǫ
	0x1ec, 501,  // Ǭ ǭ
	0x1ee, 501,  // Ǯ ǯ
	0x1f1, 502,  // Ǳ ǳ
	0x1f2, 501,  // ǲ ǳ
	0x1f4, 501,  // Ǵ ǵ
	0x1fa, 501,  // Ǻ ǻ
	0x1fc, 501,  // Ǽ ǽ
	0x1fe, 501,  // Ǿ ǿ
	0x200, 501,  // Ȁ ȁ
	0x202, 501,  // Ȃ ȃ
	0x204, 501,  // Ȅ ȅ
	0x206, 501,  // Ȇ ȇ
	0x208, 501,  // Ȉ ȉ
	0x20a, 501,  // Ȋ ȋ
	0x20c, 501,  // Ȍ ȍ
	0x20e, 501,  // Ȏ ȏ
	0x210, 501,  // Ȑ ȑ
	0x212, 501,  // Ȓ ȓ
	0x214, 501,  // Ȕ ȕ
	0x216, 501,  // Ȗ ȗ
	0x386, 538,  // Ά ά
	0x38c, 564,  // Ό ό
	0x3e2, 501,  // Ϣ ϣ
	0x3e4, 501,  // Ϥ ϥ
	0x3e6, 501,  // Ϧ ϧ
	0x3e8, 501,  // Ϩ ϩ
	0x3ea, 501,  // Ϫ ϫ
	0x3ec, 501,  // Ϭ ϭ
	0x3ee, 501,  // Ϯ ϯ
	0x460, 501,  // Ѡ ѡ
	0x462, 501,  // Ѣ ѣ
	0x464, 501,  // Ѥ ѥ
	0x466, 501,  // Ѧ ѧ
	0x468, 501,  // Ѩ ѩ
	0x46a, 501,  // Ѫ ѫ
	0x46c, 501,  // Ѭ ѭ
	0x46e, 501,  // Ѯ ѯ
	0x470, 501,  // Ѱ ѱ
	0x472, 501,  // Ѳ ѳ
	0x474, 501,  // Ѵ ѵ
	0x476, 501,  // Ѷ ѷ
	0x478, 501,  // Ѹ ѹ
	0x47a, 501,  // Ѻ ѻ
	0x47c, 501,  // Ѽ ѽ
	0x47e, 501,  // Ѿ ѿ
	0x480, 501,  // Ҁ ҁ
	0x490, 501,  // Ґ ґ
	0x492, 501,  // Ғ ғ
	0x494, 501,  // Ҕ ҕ
	0x496, 501,  // Җ җ
	0x498, 501,  // Ҙ ҙ
	0x49a, 501,  // Қ қ
	0x49c, 501,  // Ҝ ҝ
	0x49e, 501,  // Ҟ ҟ
	0x4a0, 501,  // Ҡ ҡ
	0x4a2, 501,  // Ң ң
	0x4a4, 501,  // Ҥ ҥ
	0x4a6, 501,  // Ҧ ҧ
	0x4a8, 501,  // Ҩ ҩ
	0x4aa, 501,  // Ҫ ҫ
	0x4ac, 501,  // Ҭ ҭ
	0x4ae, 501,  // Ү ү
	0x4b0, 501,  // Ұ ұ
	0x4b2, 501,  // Ҳ ҳ
	0x4b4, 501,  // Ҵ ҵ
	0x4b6, 501,  // Ҷ ҷ
	0x4b8, 501,  // Ҹ ҹ
	0x4ba, 501,  // Һ һ
	0x4bc, 501,  // Ҽ ҽ
	0x4be, 501,  // Ҿ ҿ
	0x4c1, 501,  // Ӂ ӂ
	0x4c3, 501,  // Ӄ ӄ
	0x4c7, 501,  // Ӈ ӈ
	0x4cb, 501,  // Ӌ ӌ
	0x4d0, 501,  // Ӑ ӑ
	0x4d2, 501,  // Ӓ ӓ
	0x4d4, 501,  // Ӕ ӕ
	0x4d6, 501,  // Ӗ ӗ
	0x4d8, 501,  // Ә ә
	0x4da, 501,  // Ӛ ӛ
	0x4dc, 501,  // Ӝ ӝ
	0x4de, 501,  // Ӟ ӟ
	0x4e0, 501,  // Ӡ ӡ
	0x4e2, 501,  // Ӣ ӣ
	0x4e4, 501,  // Ӥ ӥ
	0x4e6, 501,  // Ӧ ӧ
	0x4e8, 501,  // Ө ө
	0x4ea, 501,  // Ӫ ӫ
	0x4ee, 501,  // Ӯ ӯ
	0x4f0, 501,  // Ӱ ӱ
	0x4f2, 501,  // Ӳ ӳ
	0x4f4, 501,  // Ӵ ӵ
	0x4f8, 501,  // Ӹ ӹ
	0x1e00, 501,  // Ḁ ḁ
	0x1e02, 501,  // Ḃ ḃ
	0x1e04, 501,  // Ḅ ḅ
	0x1e06, 501,  // Ḇ ḇ
	0x1e08, 501,  // Ḉ ḉ
	0x1e0a, 501,  // Ḋ ḋ
	0x1e0c, 501,  // Ḍ ḍ
	0x1e0e, 501,  // Ḏ ḏ
	0x1e10, 501,  // Ḑ ḑ
	0x1e12, 501,  // Ḓ ḓ
	0x1e14, 501,  // Ḕ ḕ
	0x1e16, 501,  // Ḗ ḗ
	0x1e18, 501,  // Ḙ ḙ
	0x1e1a, 501,  // Ḛ ḛ
	0x1e1c, 501,  // Ḝ ḝ
	0x1e1e, 501,  // Ḟ ḟ
	0x1e20, 501,  // Ḡ ḡ
	0x1e22, 501,  // Ḣ ḣ
	0x1e24, 501,  // Ḥ ḥ
	0x1e26, 501,  // Ḧ ḧ
	0x1e28, 501,  // Ḩ ḩ
	0x1e2a, 501,  // Ḫ ḫ
	0x1e2c, 501,  // Ḭ ḭ
	0x1e2e, 501,  // Ḯ ḯ
	0x1e30, 501,  // Ḱ ḱ
	0x1e32, 501,  // Ḳ ḳ
	0x1e34, 501,  // Ḵ ḵ
	0x1e36, 501,  // Ḷ ḷ
	0x1e38, 501,  // Ḹ ḹ
	0x1e3a, 501,  // Ḻ ḻ
	0x1e3c, 501,  // Ḽ ḽ
	0x1e3e, 501,  // Ḿ ḿ
	0x1e40, 501,  // Ṁ ṁ
	0x1e42, 501,  // Ṃ ṃ
	0x1e44, 501,  // Ṅ ṅ
	0x1e46, 501,  // Ṇ ṇ
	0x1e48, 501,  // Ṉ ṉ
	0x1e4a, 501,  // Ṋ ṋ
	0x1e4c, 501,  // Ṍ ṍ
	0x1e4e, 501,  // Ṏ ṏ
	0x1e50, 501,  // Ṑ ṑ
	0x1e52, 501,  // Ṓ ṓ
	0x1e54, 501,  // Ṕ ṕ
	0x1e56, 501,  // Ṗ ṗ
	0x1e58, 501,  // Ṙ ṙ
	0x1e5a, 501,  // Ṛ ṛ
	0x1e5c, 501,  // Ṝ ṝ
	0x1e5e, 501,  // Ṟ ṟ
	0x1e60, 501,  // Ṡ ṡ
	0x1e62, 501,  // Ṣ ṣ
	0x1e64, 501,  // Ṥ ṥ
	0x1e66, 501,  // Ṧ ṧ
	0x1e68, 501,  // Ṩ ṩ
	0x1e6a, 501,  // Ṫ ṫ
	0x1e6c, 501,  // Ṭ ṭ
	0x1e6e, 501,  // Ṯ ṯ
	0x1e70, 501,  // Ṱ ṱ
	0x1e72, 501,  // Ṳ ṳ
	0x1e74, 501,  // Ṵ ṵ
	0x1e76, 501,  // Ṷ ṷ
	0x1e78, 501,  // Ṹ ṹ
	0x1e7a, 501,  // Ṻ ṻ
	0x1e7c, 501,  // Ṽ ṽ
	0x1e7e, 501,  // Ṿ ṿ
	0x1e80, 501,  // Ẁ ẁ
	0x1e82, 501,  // Ẃ ẃ
	0x1e84, 501,  // Ẅ ẅ
	0x1e86, 501,  // Ẇ ẇ
	0x1e88, 501,  // Ẉ ẉ
	0x1e8a, 501,  // Ẋ ẋ
	0x1e8c, 501,  // Ẍ ẍ
	0x1e8e, 501,  // Ẏ ẏ
	0x1e90, 501,  // Ẑ ẑ
	0x1e92, 501,  // Ẓ ẓ
	0x1e94, 501,  // Ẕ ẕ
	0x1ea0, 501,  // Ạ ạ
	0x1ea2, 501,  // Ả ả
	0x1ea4, 501,  // Ấ ấ
	0x1ea6, 501,  // Ầ ầ
	0x1ea8, 501,  // Ẩ ẩ
	0x1eaa, 501,  // Ẫ ẫ
	0x1eac, 501,  // Ậ ậ
	0x1eae, 501,  // Ắ ắ
	0x1eb0, 501,  // Ằ ằ
	0x1eb2, 501,  // Ẳ ẳ
	0x1eb4, 501,  // Ẵ ẵ
	0x1eb6, 501,  // Ặ ặ
	0x1eb8, 501,  // Ẹ ẹ
	0x1eba, 501,  // Ẻ ẻ
	0x1ebc, 501,  // Ẽ ẽ
	0x1ebe, 501,  // Ế ế
	0x1ec0, 501,  // Ề ề
	0x1ec2, 501,  // Ể ể
	0x1ec4, 501,  // Ễ ễ
	0x1ec6, 501,  // Ệ ệ
	0x1ec8, 501,  // Ỉ ỉ
	0x1eca, 501,  // Ị ị
	0x1ecc, 501,  // Ọ ọ
	0x1ece, 501,  // Ỏ ỏ
	0x1ed0, 501,  // Ố ố
	0x1ed2, 501,  // Ồ ồ
	0x1ed4, 501,  // Ổ ổ
	0x1ed6, 501,  // Ỗ ỗ
	0x1ed8, 501,  // Ộ ộ
	0x1eda, 501,  // Ớ ớ
	0x1edc, 501,  // Ờ ờ
	0x1ede, 501,  // Ở ở
	0x1ee0, 501,  // Ỡ ỡ
	0x1ee2, 501,  // Ợ ợ
	0x1ee4, 501,  // Ụ ụ
	0x1ee6, 501,  // Ủ ủ
	0x1ee8, 501,  // Ứ ứ
	0x1eea, 501,  // Ừ ừ
	0x1eec, 501,  // Ử ử
	0x1eee, 501,  // Ữ ữ
	0x1ef0, 501,  // Ự ự
	0x1ef2, 501,  // Ỳ ỳ
	0x1ef4, 501,  // Ỵ ỵ
	0x1ef6, 501,  // Ỷ ỷ
	0x1ef8, 501,  // Ỹ ỹ
	0x1f59, 492,  // Ὑ ὑ
	0x1f5b, 492,  // Ὓ ὓ
	0x1f5d, 492,  // Ὕ ὕ
	0x1f5f, 492,  // Ὗ ὗ
	0x1fbc, 491,  // ᾼ ᾳ
	0x1fcc, 491,  // ῌ ῃ
	0x1fec, 493,  // Ῥ ῥ
	0x1ffc, 491  // ῼ ῳ
};


/** Title characters are those between upper and lower case */
static const UNUSED Rune align64 _totitle1[16] = {
	0x1c4, 501,  // Ǆ ǅ
	0x1c6, 499,  // ǆ ǅ
	0x1c7, 501,  // Ǉ ǈ
	0x1c9, 499,  // ǉ ǈ
	0x1ca, 501,  // Ǌ ǋ
	0x1cc, 499,  // ǌ ǋ
	0x1f1, 501,  // Ǳ ǲ
	0x1f3, 499  // ǳ ǲ
};

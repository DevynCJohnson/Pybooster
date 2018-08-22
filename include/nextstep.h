// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief Nextstep character set
@file nextstep.h
@version 2018.08.22
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
*/


static const UNUSED unsigned short align64 nextstep_2uni[128] = {
	0x00a0, 0x00c0, 0x00c1, 0x00c2, 0x00c3, 0x00c4, 0x00c5, 0x00c7,
	0x00c8, 0x00c9, 0x00ca, 0x00cb, 0x00cc, 0x00cd, 0x00ce, 0x00cf,
	0x00d0, 0x00d1, 0x00d2, 0x00d3, 0x00d4, 0x00d5, 0x00d6, 0x00d9,
	0x00da, 0x00db, 0x00dc, 0x00dd, 0x00de, 0x00b5, 0x00d7, 0x00f7,
	0x00a9, 0x00a1, 0x00a2, 0x00a3, 0x2044, 0x00a5, 0x0192, 0x00a7,
	0x00a4, 0x2019, 0x201c, 0x00ab, 0x2039, 0x203a, 0xfb01, 0xfb02,
	0x00ae, 0x2013, 0x2020, 0x2021, 0x00b7, 0x00a6, 0x00b6, 0x2022,
	0x201a, 0x201e, 0x201d, 0x00bb, 0x2026, 0x2030, 0x00ac, 0x00bf,
	0x00b9, 0x02cb, 0x00b4, 0x02c6, 0x02dc, 0x00af, 0x02d8, 0x02d9,
	0x00a8, 0x00b2, 0x02da, 0x00b8, 0x00b3, 0x02dd, 0x02db, 0x02c7,
	0x2014, 0x00b1, 0x00bc, 0x00bd, 0x00be, 0x00e0, 0x00e1, 0x00e2,
	0x00e3, 0x00e4, 0x00e5, 0x00e7, 0x00e8, 0x00e9, 0x00ea, 0x00eb,
	0x00ec, 0x00c6, 0x00ed, 0x00aa, 0x00ee, 0x00ef, 0x00f0, 0x00f1,
	0x0141, 0x00d8, 0x0152, 0x00ba, 0x00f2, 0x00f3, 0x00f4, 0x00f5,
	0x00f6, 0x00e6, 0x00f9, 0x00fa, 0x00fb, 0x0131, 0x00fc, 0x00fd,
	0x0142, 0x00f8, 0x0153, 0x00df, 0x00fe, 0x00ff, 0xfffd, 0xfffd
};


static const UNUSED unsigned char align64 nextstep_page00[96] = {
	0x80, 0xa1, 0xa2, 0xa3, 0xa8, 0xa5, 0xb5, 0xa7,
	0xc8, 0xa0, 0xe3, 0xab, 0xbe, 0x00, 0xb0, 0xc5,
	0x00, 0xd1, 0xc9, 0xcc, 0xc2, 0x9d, 0xb6, 0xb4,
	0xcb, 0xc0, 0xeb, 0xbb, 0xd2, 0xd3, 0xd4, 0xbf,
	0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0xe1, 0x87,
	0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x9e,
	0xe9, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0xfb,
	0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xf1, 0xdb,
	0xdc, 0xdd, 0xde, 0xdf, 0xe0, 0xe2, 0xe4, 0xe5,
	0xe6, 0xe7, 0xec, 0xed, 0xee, 0xef, 0xf0, 0x9f,
	0xf9, 0xf2, 0xf3, 0xf4, 0xf6, 0xf7, 0xfc, 0xfd
};


static const UNUSED unsigned char align64 nextstep_page01[104] = {
	0x00, 0xf5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xe8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xea, 0xfa, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xa6, 0x00, 0x00, 0x00, 0x00, 0x00
};


static const UNUSED unsigned char align64 nextstep_page02[32] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0xcf,
	0x00, 0x00, 0x00, 0xc1, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xc6, 0xc7, 0xca, 0xce, 0xc4, 0xcd, 0x00, 0x00
};


static const UNUSED unsigned char nextstep_page20[56] = {
	0x00, 0x00, 0x00, 0xb1, 0xd0, 0x00, 0x00, 0x00,
	0x00, 0xa9, 0xb8, 0x00, 0xaa, 0xba, 0xb9, 0x00,
	0xb2, 0xb3, 0xb7, 0x00, 0x00, 0x00, 0xbc, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xac, 0xad, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xa4, 0x00, 0x00, 0x00
};


static const UNUSED unsigned char nextstep_pagefb[8] = {
	0, 0xae, 0xaf, 0, 0, 0, 0, 0
};

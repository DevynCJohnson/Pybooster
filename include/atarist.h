// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief Atari 16/32 Character Set
@file atarist.h
@version 2018.12.28
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This file defines code/character tables

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


static const UNUSED unsigned short align64 atarist_2uni[128] = {
	0x00c7, 0x00fc, 0x00e9, 0x00e2, 0x00e4, 0x00e0, 0x00e5, 0x00e7,
	0x00ea, 0x00eb, 0x00e8, 0x00ef, 0x00ee, 0x00ec, 0x00c4, 0x00c5,
	0x00c9, 0x00e6, 0x00c6, 0x00f4, 0x00f6, 0x00f2, 0x00fb, 0x00f9,
	0x00ff, 0x00d6, 0x00dc, 0x00a2, 0x00a3, 0x00a5, 0x00df, 0x0192,
	0x00e1, 0x00ed, 0x00f3, 0x00fa, 0x00f1, 0x00d1, 0x00aa, 0x00ba,
	0x00bf, 0x2310, 0x00ac, 0x00bd, 0x00bc, 0x00a1, 0x00ab, 0x00bb,
	0x00e3, 0x00f5, 0x00d8, 0x00f8, 0x0153, 0x0152, 0x00c0, 0x00c3,
	0x00d5, 0x00a8, 0x00b4, 0x2020, 0x00b6, 0x00a9, 0x00ae, 0x2122,
	0x0133, 0x0132, 0x05d0, 0x05d1, 0x05d2, 0x05d3, 0x05d4, 0x05d5,
	0x05d6, 0x05d7, 0x05d8, 0x05d9, 0x05db, 0x05dc, 0x05de, 0x05e0,
	0x05e1, 0x05e2, 0x05e4, 0x05e6, 0x05e7, 0x05e8, 0x05e9, 0x05ea,
	0x05df, 0x05da, 0x05dd, 0x05e3, 0x05e5, 0x00a7, 0x2227, 0x221e,
	0x03b1, 0x03b2, 0x0393, 0x03c0, 0x03a3, 0x03c3, 0x00b5, 0x03c4,
	0x03a6, 0x0398, 0x03a9, 0x03b4, 0x222e, 0x03c6, 0x2208, 0x2229,
	0x2261, 0x00b1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00f7, 0x2248,
	0x00b0, 0x2219, 0x00b7, 0x221a, 0x207f, 0x00b2, 0x00b3, 0x00af
};


static const UNUSED unsigned char align64 atarist_page00[96] = {
	0x00, 0xad, 0x9b, 0x9c, 0x00, 0x9d, 0x00, 0xdd,
	0xb9, 0xbd, 0xa6, 0xae, 0xaa, 0x00, 0xbe, 0xff,
	0xf8, 0xf1, 0xfd, 0xfe, 0xba, 0xe6, 0xbc, 0xfa,
	0x00, 0x00, 0xa7, 0xaf, 0xac, 0xab, 0x00, 0xa8,
	0xb6, 0x00, 0x00, 0xb7, 0x8e, 0x8f, 0x92, 0x80,
	0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xa5, 0x00, 0x00, 0x00, 0xb8, 0x99, 0x00,
	0xb2, 0x00, 0x00, 0x00, 0x9a, 0x00, 0x00, 0x9e,
	0x85, 0xa0, 0x83, 0xb0, 0x84, 0x86, 0x91, 0x87,
	0x8a, 0x82, 0x88, 0x89, 0x8d, 0xa1, 0x8c, 0x8b,
	0x00, 0xa4, 0x95, 0xa2, 0x93, 0xb1, 0x94, 0xf6,
	0xb3, 0x97, 0xa3, 0x96, 0x81, 0x00, 0x00, 0x98
};


static const UNUSED unsigned char align64 atarist_page01[104] = {
	0x00, 0x00, 0xc1, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xb5, 0xb4, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x9f, 0x00, 0x00, 0x00, 0x00, 0x00
};


static const UNUSED unsigned char align64 atarist_page03[56] = {
	0x00, 0x00, 0x00, 0xe2, 0x00, 0x00, 0x00, 0x00,
	0xe9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xe4, 0x00, 0x00, 0xe8, 0x00,
	0x00, 0xea, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0xe1, 0x00, 0xeb, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xe3, 0x00, 0x00, 0xe5, 0xe7, 0x00, 0xed, 0x00
};


static const UNUSED unsigned char align64 atarist_page05[32] = {
	0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9,
	0xca, 0xcb, 0xd9, 0xcc, 0xcd, 0xda, 0xce, 0xd8,
	0xcf, 0xd0, 0xd1, 0xdb, 0xd2, 0xdc, 0xd3, 0xd4,
	0xd5, 0xd6, 0xd7, 0x00, 0x00, 0x00, 0x00, 0x00
};


static const UNUSED unsigned char align64 atarist_page22[96] = {
	0xee, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xf9, 0xfb, 0x00, 0x00, 0x00, 0xdf, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xde,
	0x00, 0xef, 0x00, 0x00, 0x00, 0x00, 0xec, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xf7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xf0, 0x00, 0x00, 0xf3, 0xf2, 0x00, 0x00
};


static const UNUSED unsigned char align64 atarist_page23[24] = {
	0xa9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xf4, 0xf5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

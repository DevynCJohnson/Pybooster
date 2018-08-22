// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief VISCII Character Set Table
@file viscii.h
@version 2018.08.22
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This file defines the VISCII (Vietnamese Standard Code for Information Interchange) character-set tables

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


static const UNUSED unsigned short align64 viscii_2uni_1[32] = {
	// 0x0
	0, 1, 0x1eb2, 3, 4, 0x1eb4, 0x1eaa, 7,
	8, 9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf,
	// 0x10
	0x10, 0x11, 0x12, 0x13, 0x1ef6, 0x15, 0x16, 0x17,
	0x18, 0x1ef8, 0x1a, 0x1b, 0x1c, 0x1d, 0x1ef4, 0x1f
};


static const UNUSED unsigned short align64 viscii_2uni_2[128] = {
	// 0x80
	0x1ea0, 0x1eae, 0x1eb0, 0x1eb6, 0x1ea4, 0x1ea6, 0x1ea8, 0x1eac,
	0x1ebc, 0x1eb8, 0x1ebe, 0x1ec0, 0x1ec2, 0x1ec4, 0x1ec6, 0x1ed0,
	// 0x90
	0x1ed2, 0x1ed4, 0x1ed6, 0x1ed8, 0x1ee2, 0x1eda, 0x1edc, 0x1ede,
	0x1eca, 0x1ece, 0x1ecc, 0x1ec8, 0x1ee6, 0x168, 0x1ee4, 0x1ef2,
	// 0xa0
	0xd5, 0x1eaf, 0x1eb1, 0x1eb7, 0x1ea5, 0x1ea7, 0x1ea9, 0x1ead,
	0x1ebd, 0x1eb9, 0x1ebf, 0x1ec1, 0x1ec3, 0x1ec5, 0x1ec7, 0x1ed1,
	// 0xb0
	0x1ed3, 0x1ed5, 0x1ed7, 0x1ee0, 0x1a0, 0x1ed9, 0x1edd, 0x1edf,
	0x1ecb, 0x1ef0, 0x1ee8, 0x1eea, 0x1eec, 0x1a1, 0x1edb, 0x1af,
	// 0xc0
	0xc0, 0xc1, 0xc2, 0xc3, 0x1ea2, 0x102, 0x1eb3, 0x1eb5,
	0xc8, 0xc9, 0xca, 0x1eba, 0xcc, 0xcd, 0x0128, 0x1ef3,
	// 0xd0
	0x110, 0x1ee9, 0xd2, 0xd3, 0xd4, 0x1ea1, 0x1ef7, 0x1eeb,
	0x1eed, 0xd9, 0xda, 0x1ef9, 0x1ef5, 0xdd, 0x1ee1, 0x1b0,
	// 0xe0
	0xe0, 0xe1, 0xe2, 0xe3, 0x1ea3, 0x103, 0x1eef, 0x1eab,
	0xe8, 0xe9, 0xea, 0x1ebb, 0xec, 0xed, 0x129, 0x1ec9,
	// 0xf0
	0x111, 0x1ef1, 0xf2, 0xf3, 0xf4, 0xf5, 0x1ecf, 0x1ecd,
	0x1ee5, 0xf9, 0xfa, 0x169, 0x1ee7, 0xfd, 0x1ee3, 0x1eee
};


static const UNUSED unsigned char align64 viscii_page00[248] = {
	0xc0, 0xc1, 0xc2, 0xc3, 0x0, 0x0, 0x0, 0x0,  // 0xc0-0xc7
	0xc8, 0xc9, 0xca, 0x0, 0xcc, 0xcd, 0x0, 0x0,  // 0xc8-0xcf
	0x0, 0x0, 0xd2, 0xd3, 0xd4, 0xa0, 0x0, 0x0,  // 0xd0-0xd7
	0x0, 0xd9, 0xda, 0x0, 0x0, 0xdd, 0x0, 0x0,  // 0xd8-0xdf
	0xe0, 0xe1, 0xe2, 0xe3, 0x0, 0x0, 0x0, 0x0,  // 0xe0-0xe7
	0xe8, 0xe9, 0xea, 0x0, 0xec, 0xed, 0x0, 0x0,  // 0xe8-0xef
	0x0, 0x0, 0xf2, 0xf3, 0xf4, 0xf5, 0x0, 0x0,  // 0xf0-0xf7
	0x0, 0xf9, 0xfa, 0x0, 0x0, 0xfd, 0x0, 0x0,  // 0xf8-0xff
	// 0x100
	0x0, 0x0, 0xc5, 0xe5, 0x0, 0x0, 0x0, 0x0,  // 0x0-0x7
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x8-0xf
	0xd0, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x10-0x17
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x18-0x1f
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x20-0x27
	0xce, 0xee, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x28-0x2f
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x30-0x37
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x38-0x3f
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x40-0x47
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x48-0x4f
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x50-0x57
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x58-0x5f
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x60-0x67
	0x9d, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x68-0x6f
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x70-0x77
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x78-0x7f
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x80-0x87
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x88-0x8f
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x90-0x97
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0x98-0x9f
	0xb4, 0xbd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0xa0-0xa7
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf,  // 0xa8-0xaf
	0xdf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0  // 0xb0-0xb7
};


static const UNUSED unsigned char align64 viscii_page1e[96] = {
	0x80, 0xd5, 0xc4, 0xe4, 0x84, 0xa4, 0x85, 0xa5,  // 0xa0-0xa7
	0x86, 0xa6, 0x6, 0xe7, 0x87, 0xa7, 0x81, 0xa1,  // 0xa8-0xaf
	0x82, 0xa2, 0x2, 0xc6, 0x5, 0xc7, 0x83, 0xa3,  // 0xb0-0xb7
	0x89, 0xa9, 0xcb, 0xeb, 0x88, 0xa8, 0x8a, 0xaa,  // 0xb8-0xbf
	0x8b, 0xab, 0x8c, 0xac, 0x8d, 0xad, 0x8e, 0xae,  // 0xc0-0xc7
	0x9b, 0xef, 0x98, 0xb8, 0x9a, 0xf7, 0x99, 0xf6,  // 0xc8-0xcf
	0x8f, 0xaf, 0x90, 0xb0, 0x91, 0xb1, 0x92, 0xb2,  // 0xd0-0xd7
	0x93, 0xb5, 0x95, 0xbe, 0x96, 0xb6, 0x97, 0xb7,  // 0xd8-0xdf
	0xb3, 0xde, 0x94, 0xfe, 0x9e, 0xf8, 0x9c, 0xfc,  // 0xe0-0xe7
	0xba, 0xd1, 0xbb, 0xd7, 0xbc, 0xd8, 0xff, 0xe6,  // 0xe8-0xef
	0xb9, 0xf1, 0x9f, 0xcf, 0x1e, 0xdc, 0x14, 0xd6,  // 0xf0-0xf7
	0x19, 0xdb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0  // 0xf8-0xff
};

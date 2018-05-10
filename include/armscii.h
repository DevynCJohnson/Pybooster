// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief ArmSCII Character Set Table
@file armscii.h
@version 2018.04.27
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This file defines the ArmSCII (Armenian Standard Code for Information Interchange) character-set tables

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


static const UNUSED unsigned short align64 armscii_8_2uni[96] = {
	0xa0, 0xfffd, 0x587, 0x589, 0x29, 0x28, 0xbb, 0xab,
	0x2014, 0x2e, 0x55d, 0x2c, 0x2d, 0x58a, 0x2026, 0x55c,
	0x55b, 0x55e, 0x531, 0x561, 0x532, 0x562, 0x533, 0x563,
	0x534, 0x564, 0x535, 0x565, 0x536, 0x566, 0x537, 0x567,
	0x538, 0x568, 0x539, 0x569, 0x53a, 0x56a, 0x53b, 0x56b,
	0x53c, 0x56c, 0x53d, 0x56d, 0x53e, 0x56e, 0x53f, 0x56f,
	0x540, 0x570, 0x541, 0x571, 0x542, 0x572, 0x543, 0x573,
	0x544, 0x574, 0x545, 0x575, 0x546, 0x576, 0x547, 0x577,
	0x548, 0x578, 0x549, 0x579, 0x54a, 0x57a, 0x54b, 0x57b,
	0x54c, 0x57c, 0x54d, 0x57d, 0x54e, 0x57e, 0x54f, 0x57f,
	0x550, 0x580, 0x551, 0x581, 0x552, 0x582, 0x553, 0x583,
	0x554, 0x584, 0x555, 0x585, 0x556, 0x586, 0x55a, 0xfffd
};


static const UNUSED unsigned char align64 armscii_8_page00[8] = {
	0xa5, 0xa4, 0x2a, 0x2b, 0xab, 0xac, 0xa9, 0x2f
};


static const UNUSED unsigned char align64 armscii_8_page00_1[32] = {
	0xa0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0xa0-0xa7
	0x0, 0x0, 0x0, 0xa7, 0x0, 0x0, 0x0, 0x0,  // 0xa8-0xaf
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // 0xb0-0xb7
	0x0, 0x0, 0x0, 0xa6, 0x0, 0x0, 0x0, 0x0  // 0xb8-0xbf
};


static const UNUSED unsigned char align64 armscii_8_page05[96] = {
	0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe,  // 0x30-0x37
	0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce,  // 0x38-0x3f
	0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0xde,  // 0x40-0x47
	0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee,  // 0x48-0x4f
	0xf0, 0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0,  // 0x50-0x57
	0, 0, 0xfe, 0xb0, 0xaf, 0xaa, 0xb1, 0,  // 0x58-0x5f
	0, 0xb3, 0xb5, 0xb7, 0xb9, 0xbb, 0xbd, 0xbf,  // 0x60-0x67
	0xc1, 0xc3, 0xc5, 0xc7, 0xc9, 0xcb, 0xcd, 0xcf,  // 0x68-0x6f
	0xd1, 0xd3, 0xd5, 0xd7, 0xd9, 0xdb, 0xdd, 0xdf,  // 0x70-0x77
	0xe1, 0xe3, 0xe5, 0xe7, 0xe9, 0xeb, 0xed, 0xef,  // 0x78-0x7f
	0xf1, 0xf3, 0xf5, 0xf7, 0xf9, 0xfb, 0xfd, 0xa2,  // 0x80-0x87
	0, 0xa3, 0xad, 0, 0, 0, 0, 0  // 0x88-0x8f
};


static const UNUSED unsigned char align64 armscii_8_page20[24] = {
	0, 0, 0, 0, 0xa8, 0, 0, 0,  // 0x10-0x17
	0, 0, 0, 0, 0, 0, 0, 0,  // 0x18-0x1f
	0, 0, 0, 0, 0, 0, 0xae, 0  // 0x20-0x27
};

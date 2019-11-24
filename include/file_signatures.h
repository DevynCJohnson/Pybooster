// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
/**
@brief Macros Header for file signatures
@file file_signatures.h
@version 2019.11.23
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


/* FILE SIGNATURES */


#ifndef FILE_SIGNATURES_H
/** This section defines constants for various file signatures. Each hex-pair makes one byte. Most of these signature values came from https://en.wikipedia.org/wiki/List_of_file_signatures */
#define FILE_SIGNATURES_H   (1)


#define __7Z   ({0x37, 0x7a, 0xbc, 0xaf, 0x27, 0x1c})
#define __BMP   ({0x42, 0x4d})
#define __DALVIK_EXECUTABLE   ({0x64, 0x65, 0x78, 0xa, 0x30, 0x33, 0x35, 0})
#define __DMG   ({0x78, 0x1, 0x73, 0x0d, 0x62, 0x62, 0x60})
#define __GZIP   ({0x1f, 0x8b})
#define __FREE_LOSSLESS_AUDIO_CODEC   ({0x66, 0x4c, 0x61, 0x43})
#define __FREE_LOSSLESS_IMAGE_FORMAT   ({0x46, 0x4c, 0x49, 0x46})
#define __MATROSKA_MEDIA_CONTAINER   ({0x1a, 0x45, 0xdf, 0xa3})
#define __MICROSOFT_CABINET_FILE   ({0x4d, 0x53, 0x43, 0x46})
#define __MICROSOFT_OFFICE_DOCUMENTS   ({0xd0, 0xcf, 0x11, 0xe0, 0xa1, 0xb1, 0x1a, 0xe1})
#define __NES_ROM   ({0x4e, 0x45, 0x53, 0x1a})
#define __OGG   ({0x4f, 0x67, 0x67, 0x53})
#define __PDF   ({0x25, 0x50, 0x44, 0x46})
#define __POSTSCRIPT   ({0x25, 0x21, 0x50, 0x53})
#define __VMDK   ({0x4b, 0x44, 0x4d})
#define __XAR   ({0x78, 0x61, 0x72, 0x21})


#endif  // FILE_SIGNATURES_H

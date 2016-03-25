// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file FILE_SIGNATURE_MACROS.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief File Signature Macros Constants (header)
@version 2016.03.25

@section DESCRIPTION
This file defines constants for various file signatures.
Each hex-pair makes one byte.
Most of these signature values came from https://en.wikipedia.org/wiki/List_of_file_signatures

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.
*/


#ifndef FILE_SIGNATURE_MACROS_SEEN
#define FILE_SIGNATURE_MACROS_SEEN


#define __7Z   ({0x37, 0x7A, 0xBC, 0xAF, 0x27, 0x1C})
#define __BMP   ({0x42, 0x4D})
#define __DALVIK_EXECUTABLE   ({0x64, 0x65, 0x78, 0x0A, 0x30, 0x33, 0x35, 0x00})
#define __DMG   ({0x78, 0x01, 0x73, 0x0D, 0x62, 0x62, 0x60})
#define __GZIP   ({0x1F, 0x8B})
#define __FREE_LOSSLESS_AUDIO_CODEC   ({0x66, 0x4C, 0x61, 0x43})
#define __FREE_LOSSLESS_IMAGE_FORMAT   ({0x46, 0x4C, 0x49, 0x46})
#define __MATROSKA_MEDIA_CONTAINER   ({0x1A, 0x45, 0xDF, 0xA3})
#define __MICROSOFT_CABINET_FILE   ({0x4D, 0x53, 0x43, 0x46})
#define __MICROSOFT_OFFICE_DOCUMENTS   ({0xD0, 0xCF, 0x11, 0xE0, 0xA1, 0xB1, 0x1A, 0xE1})
#define __NES_ROM   ({0x4E, 0x45, 0x53, 0x1A})
#define __OGG   ({0x4F, 0x67, 0x67, 0x53})
#define __PDF   ({0x25, 0x50, 0x44, 0x46})
#define __POSTSCRIPT   ({0x25, 0x21, 0x50, 0x53})
#define __VMDK   ({0x4B, 0x44, 0x4D})
#define __XAR   ({0x78, 0x61, 0x72, 0x21})


#endif

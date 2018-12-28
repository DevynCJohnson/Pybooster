// #!/usr/bin/env rhino
// -*- coding: utf-8-unix; Mode: Javascript; indent-tabs-mode: nil; tab-width: 2 -*-
// vim: set fileencoding=utf-8 filetype=javascript syn=javascript.doxygen fileformat=unix tabstop=2 expandtab :
// kate: encoding utf-8; bom off; syntax javascript; indent-mode normal; eol unix; replace-tabs on; indent-width 2; tab-width 2; remove-trailing-space on; line-numbers on;
/**
@brief Various functions that manipulate strings
@file libstr.js
@package libstr
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
*/


/** Return the UTF16 high surrogate for the given code point integer */
function getHighSurrogate(code_point) {
  return Math.floor((Code_Point - 0x10000) / 0x400) + 0xD800
};


/** Return the UTF16 low surrogate for the given code point integer */
function getLowSurrogate(code_point) {
  return (Code_Point - 0x10000) % 0x400 + 0xDC00
};


/** Convert a UTF16 character (as a high and low surrogate integer pair) to a code-point */
function utf16HexToCodePoint(high_surrogate, low_surrogate) {
  return (high_surrogate - 0xD800) * 0x400 + low_surrogate - 0xDC00 + 0x10000;
};


/** Convert a UTF16 character (as a high and low surrogate integer pair) to the symbol as a string */
function utf16HexToSymbol(high_surrogate, low_surrogate) {
  return String.fromCodePoint(utf16HexToCodePoint(high_surrogate, low_surrogate));
};

// #!/usr/bin/env rhino
// -*- coding: utf-8-unix; Mode: Javascript; indent-tabs-mode: nil; tab-width: 2 -*-
// vim: set fileencoding=utf-8 filetype=javascript syn=javascript.doxygen fileformat=unix tabstop=2 expandtab :
// kate: encoding utf-8; bom off; syntax javascript; indent-mode normal; eol unix; replace-tabs on; indent-width 2; tab-width 2; remove-trailing-space on; line-numbers on;
/**
@brief Miscellaneous time and date functions and prototypes
@file libtime.js
@package libtime
@version 2019.02.08
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


Date.prototype.mmddyyyy = function() {
  let mm = this.getMonth() + 1;
  let dd = this.getDate();
  return [(mm > 9 ? '' : '0') + mm, (dd > 9 ? '' : '0') + dd, this.getFullYear()].join('');
};


Date.prototype.mm_dd_yyyy = function() {
  let mm = this.getMonth() + 1;
  let dd = this.getDate();
  return [(mm > 9 ? '' : '0') + mm, '/', (dd > 9 ? '' : '0') + dd, '/', this.getFullYear()].join('');
};


Date.prototype.yyyymmdd = function() {
  let mm = this.getMonth() + 1;
  let dd = this.getDate();
  return [this.getFullYear(), (mm > 9 ? '' : '0') + mm, (dd > 9 ? '' : '0') + dd].join('');
};


Date.prototype.yyyy_mm_dd = function() {
  let mm = this.getMonth() + 1;
  let dd = this.getDate();
  return [this.getFullYear(), '/', (mm > 9 ? '' : '0') + mm, '/', (dd > 9 ? '' : '0') + dd].join('');
};



Date.prototype.mmyyyy = function() {
  let mm = this.getMonth() + 1;
  return [(mm > 9 ? '' : '0') + mm, this.getFullYear()].join('');
};


Date.prototype.mm_yyyy = function() {
  let mm = this.getMonth() + 1;
  return [(mm > 9 ? '' : '0') + mm, '/', this.getFullYear()].join('');
};

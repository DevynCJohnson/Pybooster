// #!/usr/bin/env rhino
// -*- coding: utf-8-unix; Mode: Javascript; indent-tabs-mode: nil; tab-width: 2 -*-
// vim: set fileencoding=utf-8 filetype=javascript syn=javascript.doxygen fileformat=unix tabstop=2 expandtab :
// kate: encoding utf-8; bom off; syntax javascript; indent-mode normal; eol unix; replace-tabs on; indent-width 2; tab-width 2; remove-trailing-space on; line-numbers on;
/**
@brief Various functions that can be used in an HTML/web-browser environment
@file libhtml.js
@package libhtml
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


'use strict';


/** Test if the environment supports pseudoclasses */
function isPseudoSupported(pseudo) {
  if (pseudo) { return false; }
  var ss = document.styleSheets[0];
  if (!ss) {
    let ele = document.createElement('style');
    document.head.appendChild(ele);
    ss = document.styleSheets[0];
    document.head.removeChild(ele);
  }
  try {
    if (!(/^:/).test(pseudoClass)) { pseudoClass = ':' + pseudoClass; }
    ss.insertRule('html' + pseudoClass + '{}', 0);
    ss.deleteRule(0);
    return true;
  } catch(e) { return false; }
};


/** Test if the Caps-Lock key was pressed given the event */
function wasCapsLockPressed(evt) {
  kc = evt.keyCode ? evt.keyCode : evt.which;
  sk = evt.shiftKey ? evt.shiftKey : ((kc === 16) ? true : false);
  if (((kc >= 65 && kc <= 90) && !sk) || ((kc >= 97 && kc <= 122) && sk)) { return true; }
  return false;
}

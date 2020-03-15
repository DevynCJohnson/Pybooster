// #!/usr/bin/env rhino
// -*- coding: utf-8-unix; Mode: Javascript; indent-tabs-mode: nil; tab-width: 2 -*-
// vim: set fileencoding=utf-8 filetype=javascript syn=javascript.doxygen fileformat=unix tabstop=2 expandtab :
// kate: encoding utf-8; bom off; syntax javascript; indent-mode normal; eol unix; replace-tabs on; indent-width 2; tab-width 2; remove-trailing-space on;
/**
@brief Miscellaneous functions
@file libutils.js
@package libutils
@version 2020.03.15
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


'use strict';


/** Copy an array */
function copyArray(aObject) {
  if (!aObject) { return aObject; }
  let bObject = [];
  for (const k in aObject) {
    let v = aObject[k];
    bObject[k] = (typeof v === 'object') ? copyArray(v) : v;
  }
  return bObject;
}


/** Test if the given data contains nothing */
function isempty(data) {
  if (data === undefined || data === null || !data || (typeof data === 'string' && data.length === 0)) { return true; }
  return false;
}


/** Test if the given data does not contain nothing */
function isnotempty(data) {
  if (data !== undefined && data !== null && ((typeof data === 'number' && data > 0) || data.length > 0)) { return true; }
  return false
}


/** Test if the given data is not undefined nor null */
function isnotvoid(data) {
  if (data !== undefined && data !== null) { return true; }
  return false;
}


/** Test if the given data is a valid text string */
function istext(data) {
  if (isnotempty(data) && (typeof data === 'string') && data.trim() !== '') { return true; }
  return false;
}


/** Test if the given data is undefined or null */
function isvoid(data){
  if (data === undefined || data === null) { return true; }
  return false;
}


/** Convenience function proving an easy way to create popup notifications */
function notify_user(msg, title='Notification', icon_path='') {
  if (isempty(msg)) { return; }
  try {
    const notify_options = {body: msg, icon: icon_path, lang: 'en-US', renotify: true, silent: true};
    if (Notification.permission === 'granted') {
      const notification = new Notification(title, notify_options);
    } else if (Notification.permission !== 'denied') {
      Notification.requestPermission().then(
        function(permission) {
          if (permission === 'granted') { const notification = new Notification(title, notify_options); }
        }
      );
    }
  } catch (err) {}
}


/** Provide a save-as dialog for the URI */
function saveAs(uri, title='Download File') {
  let _link = document.createElement('a');
  if (typeof _link.download === 'string') {
    _link.href = uri;
    _link.setAttribute('download', _title);
    document.body.appendChild(_link);
    _link.click();
    document.body.removeChild(_link);
  } else { window.open(uri, '_blank'); }
}


/** Speak the given message */
function speak(msg) {
  if (isempty(msg)) { return; }
  try {
    let utterThis = new SpeechSynthesisUtterance(msg);
    utterThis.lang = 'en-US';
    window.speechSynthesis.speak(utterThis);
    window.speechSynthesis.resume();
  } catch (err) {}
}


/** Stop all vibrations */
function stop_vibrating() {
  try { window.navigator.vibrate(0); } catch (err) {}
}


/** Produce a UUIDv1 string */
function uuidv1() {
  return 'xxxxxxxx-xxxx-1xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, c => { const r = (Math.random() * 16) | 0; return (c === 'x' ? r : (r & 3 | 8)).toString(16); });
}


/** Produce a UUIDv4 string */
function uuidv4() {
  return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, c => { const r = ((Math.random() * 16) | 0); return (c == 'x' ? r : (r & 3 | 8)).toString(16); });
}


/** Trigger a vibration */
function vibrate() {
  try { window.navigator.vibrate(200); } catch (err) {}
}


/** Trigger a vibration used to indicate an error */
function vibrate_error() {
  try {
    window.navigator.vibrate([100, 50, 100, 50, 100, 50, 100]);
  } catch (err) {}
}

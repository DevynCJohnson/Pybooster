// #!/usr/bin/env rhino
// -*- coding: utf-8-unix; Mode: Javascript; indent-tabs-mode: nil; tab-width: 2 -*-
// vim: set fileencoding=utf-8 filetype=javascript syn=javascript.doxygen fileformat=unix tabstop=2 expandtab :
// kate: encoding utf-8; bom off; syntax javascript; indent-mode normal; eol unix; replace-tabs on; indent-width 2; tab-width 2; remove-trailing-space on;
/**
@brief Various functions that can be used in an HTML/web-browser environment
@file libhtml.js
@package libhtml
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


/* PROTOTYPES */


/** Delete an element */
Element.prototype.remove = function() { this.parentElement.removeChild(this); }


/** Delete an element and its children */
NodeList.prototype.remove = HTMLCollection.prototype.remove = function() {
  for (let i = this.length - 1; i >= 0; i--) {
    if (this[i] && this[i].parentElement) {
      this[i].parentElement.removeChild(this[i]);
    }
  }
}


/* FUNCTIONS */


/** Add a class to all elements of the given tag name */
function addClass2Tag(_class, _tag) {
  [].forEach.call(document.getElementsByTagName(_tag), function(elem) { elem.classList.add(_class); });
}


/** Call the phone number contained in the given element (by ID) */
function call_phone(ele_id) {
  const phone_str = document.getElementById(ele_id).value;
  if (phone_str) {
    const fixedphone = phone_str.replace(/\(/g, '').replace(/\)/g, '').replace(/ /g, '').replace(/-/g, '').trim();
    if (fixedphone.length === 10 || fixedphone.length === 11) { window.open('tel:' + fixedphone, '_blank'); }
  }
}


/** Copy the clicked text from the given element */
function click2copy(elem) {
  let range = document.createRange();
  range.selectNode(elem);
  window.getSelection().addRange(range);
  document.execCommand('copy');
}


/** Delete all elements with the given class globally */
function delByClass(_class) {
  [].forEach.call(document.querySelectorAll('.' + _class), function(elem) { elem.classList.remove(elem); });
}


/** Exit Fullscreen */
function exitFullscreen() {
  if (document.exitFullscreen) {
    document.exitFullscreen();
  } else if (document.mozCancelFullScreen) {  /* Firefox */
    document.mozCancelFullScreen();
  } else if (document.webkitExitFullscreen) {  /* Chrome, Opera, and Safari */
    document.webkitExitFullscreen();
  } else if (document.msExitFullscreen) {  /* IE/Edge */
    document.msExitFullscreen();
  }
}


/** Hide elements given by the idenfifier globally */
function hideGlobally(identifier) {
  [].forEach.call(document.querySelectorAll(identifier), function(elem) { elem.hidden = true; });
}


/** Test if the specified class is present */
function isClassPresent(_class) {
  if (document.querySelectorAll('.' + _class).length > 0) { return true; }
  return false;
}


/** Test if the specified ID is present */
function isIdPresent(_id) {
  if (document.querySelectorAll('#' + _id).length > 0) { return true; }
  return false;
}


/** Test if the environment supports pseudoclasses */
function isPseudoSupported(pseudo) {
  if (pseudo) { return false; }
  let ss = document.styleSheets[0];
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


/** Test if the specified tag is present */
function isTagPresent(tag) {
  if (document.getElementsByTagName(tag).length > 0) { return true; }
  return false;
}


/** View in fullscreen */
function openFullscreen() {
  const elem = document.documentElement;
  if (elem.requestFullscreen) {
    elem.requestFullscreen();
  } else if (elem.mozRequestFullScreen) {  /* Firefox */
    elem.mozRequestFullScreen();
  } else if (elem.webkitRequestFullscreen) {  /* Chrome, Opera, and Safari */
    elem.webkitRequestFullscreen();
  } else if (elem.msRequestFullscreen) {  /* IE/Edge */
    elem.msRequestFullscreen();
  }
}


/** Unhide elements given by the idenfifier globally */
function unhideGlobally(identifier) {
  [].forEach.call(document.querySelectorAll(identifier), function(elem) { elem.hidden = false; });
}


/** Test if the Caps-Lock key was pressed given the event */
function wasCapsLockPressed(evt) {
  const kc = evt.keyCode ? evt.keyCode : evt.which;
  const sk = evt.shiftKey ? evt.shiftKey : ((kc === 16) ? true : false);
  if (((kc >= 65 && kc <= 90) && !sk) || ((kc >= 97 && kc <= 122) && sk)) { return true; }
  return false;
}


/* COOKIE FUNCTIONS */


/** Delete a cookie by name */
function delete_cookie(ckiename) {
  document.cookie = ckiename + '=;samesite=strict;max-age=1;expires=Thu, 01 Jan 1970 00:00:01 GMT;';
}


/** Retrieve the specified cookie by name */
function getCookie(name) {
  const value = '; ' + document.cookie;
  if (value.length <= 4) { return null; }
  const parts = value.split('; ' + name + '=');
  if (parts.length > 1) {
    return parts.pop().split(';').shift();
  }
  return null;
}


/** Test if a cookie is present */
function hasCookie(name){
  if (getCookie(name) !== null) { return true; }
  return false;
}


/** Test if a cookie is present */
function isCookiePresent(name) {
  const value = '; ' + document.cookie;
  if (value.length <= 4) { return false; }
  const parts = value.split('; ' + name + '=');
  if (parts.length > 1) { return true; }
  return false;
}


/** Set the value of a cookie (new or existing) */
function setCookie(ckiename, ckieval) {
  let timenow = new Date();
  timenow.setSeconds(timenow.getSeconds() + 86400);
  document.cookie = ckiename + '=' + ckieval + ';samesite=strict;max-age=86400;expires=' + timenow.toUTCString();
}


/* PERSISTENT FUNCTIONS */


/** Clear the persistent data for the specified form (by ID) */
function clearPersistentForm(formID) {
  [].forEach.call(document.querySelectorAll(formID + ' input'), function(_elem) {
    sessionStorage.removeItem(formID + '__' + _elem.name);
  });
  [].forEach.call(document.querySelectorAll(formID + ' select'), function(_elem) {
    sessionStorage.removeItem(formID + '__' + _elem.name);
  });
  [].forEach.call(document.querySelectorAll(formID + ' textarea'), function(_elem) {
    sessionStorage.removeItem(formID + '__' + _elem.name);
  });
  [].forEach.call(document.querySelectorAll(formID + ' output'), function(_elem) {
    sessionStorage.removeItem(formID + '__' + _elem.name);
  });
  return true;
}


/** Load persistent data into the specified form (by ID) */
function loadPersistentForm(formID) {
  if (sessionStorage.length < 1) { return false; }
  [].forEach.call(document.querySelectorAll(formID + ' input'), function(_elem) {
    if (_elem.name !== 'csrfmiddlewaretoken' && !['button', 'submit', 'reset'].includes(_elem.type)) {
      _elem.value = sessionStorage.getItem(formID + '__' + _elem.name);
    }
  });
  [].forEach.call(document.querySelectorAll(formID + ' select'), function(_elem) {
    _elem.value=sessionStorage.getItem(formID + '__' + _elem.name)
  });
  [].forEach.call(document.querySelectorAll(formID + ' textarea'), function(_elem) {
    _elem.value = sessionStorage.getItem(formID + '__' + _elem.name);
  });
  [].forEach.call(document.querySelectorAll(formID + ' output'), function(_elem) {
    _elem.value = sessionStorage.getItem(formID + '__' + _elem.name);
  });
  return true;
}


/** Store the data from the specified form (by ID) into persistent data */
function savePersistentForm(formID) {
  [].forEach.call(document.querySelectorAll(formID + ' input'), function(_elem) {
    if (_elem.name !== 'csrfmiddlewaretoken' && !['button', 'submit', 'reset'].includes(_elem.type)) {
      sessionStorage.setItem(formID + '__' + _elem.name, _elem.value);
    }
  });
  [].forEach.call(document.querySelectorAll(formID + ' select'), function(_elem) {
    sessionStorage.setItem(formID + '__' + _elem.name, _elem.value);
  });
  [].forEach.call(document.querySelectorAll(formID + ' textarea'), function(_elem) {
    sessionStorage.setItem(formID + '__' + _elem.name, _elem.value);
  });
  [].forEach.call(document.querySelectorAll(formID + ' output'), function(_elem) {
    sessionStorage.setItem(formID + '__' + _elem.name, _elem.value);
  });
  return true;
}


/* URL FUNCTIONS */


/** Retrieve the value of the specified URL parameter */
function getRequestParam(paramName) {
  const items = document.location.search.substr(1).split('&');
  const item_len = items.length;
  for (let index = 0; index < item_len; index++) {
    let tmp = items[index].split('=');
    if (tmp[0] === paramName) {
      return decodeURIComponent(tmp[1]);
    }
  }
  return null;
}


/** Go to the current URL, but with the specified parameter and value set */
function gotoUrlParam(paramName, paramValue) {
  if (isParamNotInUrl(paramName)){
    document.location.href = CURRENT_URL + '?' + paramName + '=' + paramValue;
  } else {
    let new_url = new URL(document.URL);
    new_url.searchParams.set(paramName, paramValue);
    document.location.href = new_url.href;
  }
}


/** Test if the specified parameter is in the URL */
function isParamInUrl(data) {
  try {
    if (isempty(data) || data.trim() === '') { return false; }
  } catch (err) { return false; }
  return CURRENT_URL.indexOf(data + '=') !== -1;
}


/** Test if the specified parameter is not in the URL */
function isParamNotInUrl(data) {
  return !isParamInUrl(data);
}


/** Remove the specified URL parameter */
function removeRequestParam(paramName) {
  let urlparts = document.location.split('?').url;
  if (urlparts.length < 1) {
    return document.location.url;
  }
  const prefix = encodeURIComponent(paramName) + '=';
  let pars = urlparts[1].split(/[&;]/g);
  for (let i = pars.length; i-- > 0;) {
    if (pars[i].lastIndexOf(prefix, 0) !== -1) {
      pars.splice(i, 1);
    }
  }
  return urlparts[0] + (pars.length > 0 ? '?' + pars.join('&') : '');
}

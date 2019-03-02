// #!/usr/bin/env rhino
// -*- coding: utf-8-unix; Mode: Javascript; indent-tabs-mode: nil; tab-width: 2 -*-
// vim: set fileencoding=utf-8 filetype=javascript syn=javascript.doxygen fileformat=unix tabstop=2 expandtab :
// kate: encoding utf-8; bom off; syntax javascript; indent-mode normal; eol unix; replace-tabs on; indent-width 2; tab-width 2; remove-trailing-space on; line-numbers on;
/**
@brief Miscellaneous functions used to communicate with the server
@file libajax.js
@package libutils
@version 2019.03.01
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


/** Stringify a JavaScript object */
function JSONx_stringify(jsonobj, ilevel = 0) {
  return JSON.stringify(jsonobj, function(jsonobj, xobj) {
    let objstr;
    return ((xobj instanceof Function) || (typeof xobj === 'function')) ? (objstr = xobj.toString(), ((objstr.length < 8) || ('function' !== objstr.substring(0, 8))) ? '_NuFrRa_' + objstr : objstr) : xobj instanceof RegExp ? '_PxEgEr_' + xobj : xobj;
  }, ilevel);
}


/** Parse/Unstringify a JavaScript object */
function JSONx_parse(jsonobj, boolval) {
  let xobj = boolval ? /^(\d{4})-(\d{2})-(\d{2})T(\d{2}):(\d{2}):(\d{2}(?:\.\d*)?)Z$/ : !1;
  return JSON.parse(jsonobj, function(jsonobj, cobj) {
    if ((typeof cobj !== 'string') || (cobj.length < 8)) { return cobj }
    let estr = cobj.substring(0, 8);
    return (xobj && cobj.match(xobj)) ? new Date(cobj) : (estr === 'function') ? eval('(' + cobj + ')') : ((estr === '_PxEgEr_') || (estr === '_NuFrRa_')) ? eval(cobj.slice(8)) : cobj;
  });
}


/** Clone a JavaScript object */
function JSONx_clone(obj2clone) {
  return JSONx_parse(JSONx_stringify(obj2clone, 0), true);
}


/** Get the value of the specified query parameter in the URL */
function getRequestParam(paramName) {
  let result = null;
  var tmp = [];
  let items = location.search.substr(1).split('&');
  let item_len = items.length;
  for (let index = 0; index < item_len; index++) {
    tmp = items[index].split('=');
    if (tmp[0] === paramName) { result = decodeURIComponent(tmp[1]); }
  }
  return result;
}


/**
@brief Create a specific `alert()` box message depending on the given HTTP status code
@param httpcode A string or integer representing the HTTP status code
*/
function httpAlert(httpcode) {
  let _httpcode = parseInt(httpcode, 10);
  if (typeof _httpcode !== 'number') { throw 'The provided HTTP status code could not be converted to an integer!'; }
  switch (this.status) {
    case 200: alert('OK: Succesfully received request'); break;
    case 204: alert('No Content: Succesfully received request; nothing needed to report back'); break;
    case 205: alert('Reset Content: Succesfully received request; refresh the screen to see changes'); break;
    case 400: alert('Bad Request: Invalid or malformed request sent to the server'); break;
    case 401: alert('Unauthorized: Permission denied'); break;
    case 402: alert('Payment Required'); break;
    case 403: alert('Forbidden: Invalid permissions'); break;
    case 404: alert('Not Found: Unable to reach the endpoint'); break;
    case 405: alert('Method Not Allowed: The endpoint does not accept the given method type'); break;
    case 406: alert('Not Acceptable: The endpoint is read-only'); break;
    case 408: alert('Request Timeout: The client took too long to submit the request'); break;
    case 411: alert('Length Required: The submitted data is not long enough'); break;
    case 413: alert('Payload Too Large: The request is too large for the server to accept'); break;
    case 414: alert('URI Too Long: The URI in the request is too long'); break;
    case 429: alert('Too Many Requests'); break;
    case 431: alert('Request Header Fields Too Large'); break;
    case 440: alert('Login Time-out: The session expired; login again'); break;
    case 500: alert('Internal Server Error: The server is experiencing issues'); break;
    case 501: alert('Not Implemented: The server does not recognize the request'); break;
    case 503: alert('Service Unavailable: The server is currently unavailable'); break;
    case 521: alert('Web Server Is Down'); break;
    default: alert('Status Code: ' + this.status.toString() + '\nThere appears to be some unknown issue. Please, try again.');
  }
}


/**
@brief Submit the given data via POST to the specified URL
@param _data The data to send (via POST) to the server
@param addr The URI address to send the POST
@param timeout The number of milliseconds before terminating the request (Optional)
@param retvar The object that will receive the response and status code
@param mimetype The mimetype of the submitted data (Default: text/plain)
@param encoding The encoding of the submitted data (Default: charset=UTF-8)
@param csrftoken Optional CSRF-Token
@param user Username (Optional)
@param csrftoken Password (Optional)
*/
function sendData(_json_data, addr, retvar, mimetype = 'application/json', encoding = 'charset=UTF-8', timeout = 2000, csrftoken = '', user = null, pswd = null) {
  if (!_json_data) { throw 'The provided data is empty!'; }
  if (!timeout) { timeout = 2000; }
  let postRequest = new XMLHttpRequest();
  postRequest.open('POST', addr, true, user, pswd);
  postRequest.setRequestHeader('Content-Type', mimetype + ';' + encoding);
  postRequest.timeout = timeout;
  if (csrftoken) { postRequest.setRequestHeader('X-CSRFToken', csrftoken); }
  postRequest.onload = function() {
    retvar = {response: this.response, status: this.status};
  }
  postRequest.onerror = function() {
    console.log('There appears to be some unknown issue submitting the POST!');
    retvar = {response: this.response, status: this.status};
  }
  postRequest.onabort = function() {
    console.log('POST aborted due to timeout');
    retvar = {response: this.response, status: this.status};
  }
  postRequest.send(JSONx_stringify({csrfmiddlewaretoken: csrftoken, sentData: _json_data}));
}

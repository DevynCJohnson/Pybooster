#!/usr/bin/env php
<?php
// -*- coding: utf-8-unix; Mode: PHP; indent-tabs-mode: t; php-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=php fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax php; indent-mode phpstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief PHP library containing color-related functions
@file colorlib.php
@version 2019.01.24
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


/**
@brief Convert HEX (#222222) to RGB (rgb(40, 208, 219))
@param[string] $color Hexadecimal color notation as a string
@return string RGB notation
*/
function hex2rgb($color) {
	$default = 'rgb(0,0,0)';
	if (empty($color)) { return $default; }
	if ($color[0] === '#') { $color = substr($color, 1); }
	$clrlen = strlen($color);
	if ($clrlen !== 3 && $clrlen !== 6) {
		return $default;
	} elseif ($clrlen === 6) {
		$hex = array($color[0] . $color[1], $color[2] . $color[3], $color[4] . $color[5]);
	} elseif ($clrlen === 3) {
		$hex = array($color[0] . $color[0], $color[1] . $color[1], $color[2] . $color[2]);
	}
	$rgb = array_map('hexdec', $hex);
	return 'rgb(' . implode(',', $rgb) . '';
}


/**
@brief Convert HEX (#222222) to RGBA (rgba(40, 208, 219, 0.7))
@param[string] $color Hexadecimal color notation as a string
@return string RGBA notation
*/
function hex2rgba($color) {
	$default = 'rgb(0,0,0)';
	if (empty($color)) { return $default; }
	if ($color[0] === '#') { $color = substr($color, 1); }
	$clrlen = strlen($color);
	if ($clrlen !== 3 && $clrlen !== 6) {
		return $default;
	} elseif ($clrlen === 6) {
		$hex = array($color[0] . $color[1], $color[2] . $color[3], $color[4] . $color[5]);
	} elseif ($clrlen === 3) {
		$hex = array($color[0] . $color[0], $color[1] . $color[1], $color[2] . $color[2]);
	}
	$rgb = array_map('hexdec', $hex);
	if (abs($opacity) > 1) { $opacity = 1.0; }
	return 'rgba(' . implode(',', $rgb) . ',' . $opacity . '';
}


?>

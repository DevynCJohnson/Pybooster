#!/usr/bin/env php
<?php
// -*- coding: utf-8-unix; Mode: PHP; indent-tabs-mode: t; php-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=php fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax php; indent-mode phpstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief PHP library containing string-related functions
@file strlib.php
@version 2019.01.25
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
@brief Returns number of vowels in provided string
@param[string] $string The string in which to count vowels
@return integer The number of vowels in the given string
*/
function countVowels($string) {
	preg_match_all('/[aeiou]/i', $string, $matches);
	return count($matches[0]);
}


/**
@brief Decapitalizes the first letter of a string
@param[string] $string The string in which to decapitalize
@return string The decapitalized string
*/
function decapitalize($string) {
	return lcfirst($string);
}


/**
@brief Check if a string ends with the given substring `substr`
@param[string] $mainstr The string to test
@param[string] $substr The sought-after substring
@return boolean
*/
function endsWith($mainstr, $substr) {
	return strrpos($mainstr, $substr) === (strlen($mainstr) - strlen($substr));
}


/**
@brief Returns the string between the first instance of `start` and `end`
@param[string] $mainstr The string to test
@param[string] $start The first substring to find
@param[string] $end The ending substring to find
@return string
*/
function firstStringBetween($mainstr, $start, $end) {
	return trim(strstr(strstr($mainstr, $start), $end, true), $start . $end);
}


/**
@brief Compare two strings and returns `true` if both strings are anagrams; otherwise, return `false`
@param[string] $str1 The first string to test
@param[string] $str2 The second string to test
@return string
*/
function isAnagram($str1, $str2) {
	return count_chars($str1, 1) === count_chars($str2, 1);
}


/**
@brief Check if a substring exists in the given string
@param[string] $str The main string in which to search
@param[string] $substr The sought-after substring
@return boolean
*/
function isContains($str, $substr) {
	return strpos($str, $substr);
}


/**
@brief Returns `true` if the given string is lower case; otherwise, return `false`
@param[string] $str The string in which to test
@return boolean
*/
function isLowerCase($str) {
	return $str === strtolower($str);
}


/**
@brief Returns `true` if the given string is upper case; otherwise, return `false`
@param[string] $str The string in which to test
@return boolean
*/
function isUpperCase($str) {
	return $str === strtoupper($str);
}


/**
@brief Returns `true` if the given string is a palindrome; otherwise, return `false`
@param[string] $str The string in which to test
@return boolean
*/
function palindrome($str) {
	return $str === strrev($str);
}


/**
@brief Check if a string starts with a given substring
@param[string] $str The string in which to test
@param[string] $substr The substring to find
@return boolean
*/
function startsWith($str, $substr) {
	return 0 === strpos($str, $substr);
}


?>

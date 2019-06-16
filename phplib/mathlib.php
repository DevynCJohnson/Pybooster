#!/usr/bin/env php
<?php
// -*- coding: utf-8-unix; Mode: PHP; indent-tabs-mode: t; php-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=php fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax php; indent-mode phpstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
/**
@brief PHP library containing math functions
@file mathlib.php
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
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
*/


/**
@brief Returns the average of two or more numbers
@param[array] $items An array of numbers
@return float The average of the given array
*/
function average(...$items) {
	return count($items) === 0 ? 0 : array_sum($items) / count($items);
}


/**
@brief Clamps `num` within the inclusive range specified by the boundary values `start` and `end`
@param[number] $num The number to clamp
@param[number] $start The starting boundary
@param[number] $end The ending boundary
@return float
*/
function clamp($num, $start, $end) {
	return max(min($num, max($start, $end)), min($start, $end));
}


/**
@brief Calculates the factorial of an integer
@param[integer] $num The initial integer
@return integer
*/
function factorial($num) {
	if ($num <= 1) { return 1; }
	$ans = $num;
	for ($i = $num; $i != 1; $i--) {
		$ans *= ($i - 1);
	}
	return $ans;
}


/**
@brief Generates an array (containing the Fibonacci sequence) up until the `num`th term
@param[integer] $num The `num`th Fibonacci number to obtain
@return integer
*/
function fibonacci($num) {
	$seq = [0, 1];
	for ($i = 2; $i < $num; $i++) {
		$seq[$i] = $seq[$i-1] + $seq[$i-2];
	}
	return $seq;
}


/**
@brief Calculates the greatest common divisor between two or more numbers
@param[integer] $numbers The set of numbers to process
@return integer
*/
function gcd(...$numbers) {
	if (count($numbers) > 2) { return array_reduce($numbers, 'gcd'); }
	$ans = $numbers[0] % $numbers[1];
	return $ans === 0 ? abs($numbers[1]) : gcd($numbers[1], $ans);
}


/**
@brief Checks if the provided integer is a prime number
@param[integer] $num The integer to test
@return boolean
*/
function isPrime($num) {
	$boundary = floor(sqrt($num));
	for ($i = 2; $i <= $boundary; $i++) {
		if ($num % $i === 0) { return false; }
	}
	return $num >= 2;
}


/**
@brief Returns the least common multiple of two or more numbers
@param[integer] $numbers The set of numbers to process
@return integer
*/
function lcm(...$numbers) {
	$ans = $numbers[0];
	for ($i = 1; $i < count($numbers); $i++) {
		$ans = ((($numbers[$i] * $ans)) / (gcd($numbers[$i], $ans)));
	}
	return $ans;
}


/**
@brief Returns the median of an array of numbers
@param[integer] $numbers The set of numbers to process
@return integer
*/
function median($numbers) {
	sort($numbers);
	$totalNumbers = count($numbers);
	$mid = floor($totalNumbers / 2);
	return ($totalNumbers % 2) === 0 ? ($numbers[$mid - 1] + $numbers[$mid]) / 2 : $numbers[$mid];
}


?>

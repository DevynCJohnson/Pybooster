// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file chron.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Time Functions
@version 2016.03.09

@section DESCRIPTION
Functions pertaining to time

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


#include "chron.h"


/* FUNCTIONS */


#ifdef OSPOSIX
/**
    Return the current time in microseconds since the epoch

    @returns current microseconds since the epoch
*/
ulint time_microseconds(void) {
    gettimeofday(&now, NULL);
    return (ulint)((1000000UL * (ulint)now.tv_sec) + (ulint)now.tv_usec);
}
#endif


/**
    Return the current time in seconds since the epoch

    @returns current seconds since the epoch
*/
ulint time_seconds(void) {
    time_t timer;
    return (ulint)time(&timer);
}

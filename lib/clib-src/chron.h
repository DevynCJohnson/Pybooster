// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file chron.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Time Functions (header)
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


#ifndef FILE_CHRONO_SEEN
#define FILE_CHRONO_SEEN


#include "MACROS.h"

#include <time.h>  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/time.h.html
#ifdef OSPOSIX
#   include <sys/time.h>  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_time.h.html
#endif


/* STRUCTS */
struct timeval now;
/* FUNCTIONS */
#ifdef OSPOSIX
ulint time_microseconds(void);
#endif
ulint time_seconds(void);


#endif

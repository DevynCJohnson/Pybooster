// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file tone.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Play tones (header)
@version 2016.03.09

@section DESCRIPTION
This library provides functions that produce tones using libao

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


#ifndef FILE_TONE_SEEN
#define FILE_TONE_SEEN


#include "MACROS.h"

#include <math.h>
#ifdef __has_include
#   if __has_include(<ao/ao.h>)
#      include <ao/ao.h>
#   else
#      error   "<ao/ao.h> was not found!"
#   endif
#else
#   include <ao/ao.h>
#endif


#define BUF_SIZE   (4096)

typedef struct {
    int buf_size;
    char buffer[BUF_SIZE];
    int sample;
} tone;

/* SOUND FORMAT */
ao_sample_format defaultsoundformat(void);
ao_sample_format setsoundformat(const int bits, const int channels, const int rate);
/* INITIALIZE DRIVER */
ao_device *initdriver(ao_sample_format format);
/* TONE GENERATORS */
tone generatetone(const float freq, ao_sample_format format);
tone tone440hz(ao_sample_format format);
tone tone1000hz(ao_sample_format format);
/* PLAY SOUND */
int playsound(void);
int playtone(const float freq);


#endif

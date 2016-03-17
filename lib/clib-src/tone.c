// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file tone.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Play tones
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


#include "tone.h"


/* SOUND FORMAT */


/** Setup the default sound format */
ao_sample_format defaultsoundformat(void) {
    ao_sample_format format;
    memset(&format, 0x0, sizeof(ao_sample_format));
    format.bits = 0x0f;  // 16
    format.channels = 0x02;  // 2
    format.rate = 0xac44;  // 44100
    format.byte_format = (AO_FMT_LITTLE);
    return format;
}


/** Setup sound format (bits, channels, rate) */
ao_sample_format setsoundformat(const int bits, const int channels, const int rate) {
    ao_sample_format format;
    memset(&format, 0, sizeof(ao_sample_format));
    format.bits = bits;
    format.channels = channels;
    format.rate = rate;
    format.byte_format = (AO_FMT_LITTLE);
    return format;
}


/* INITIALIZE DRIVER */


/** Setup and open default driver */
ao_device *initdriver(ao_sample_format format) {
    ao_device *device;
    device = ao_open_live(ao_default_driver_id(), &format, NULL);
    return device;
}


/* TONE GENERATORS */


/** Generate a tone lasting one second; remember to use `free(sound.buffer);` */
tone generatetone(const float freq, ao_sample_format format) {
    tone sound;
    sound.buf_size = (format.bits >> 3) * format.channels * format.rate;
    register int i;
    register float _val;
    for (i = 0; i < format.rate; ++i) {
        _val = (((float)i / (float)format.rate) * (float)6.283185F);
        sound.sample = (int)((float)24576.0F * sinf(freq * _val));  // amplitude * sin_wave
        sound.buffer[4 * i] = sound.buffer[4 * i + 2] = (char)(sound.sample & 0xff);
        sound.buffer[4 * i + 1] = sound.buffer[4 * i + 3] = (char)((sound.sample >> 0x08) & 0xff);
    }
    return sound;
}


/** Generate a 440Hz tone lasting one second; remember to use `free(sound.buffer);` */
tone tone440hz(ao_sample_format format) {
    tone sound;
    sound.buf_size = format.bits / 8 * format.channels * format.rate;
    register int i;
    register float _val;
    for (i = 0; i < format.rate; ++i) {
        _val = (((float)i / (float)format.rate) * (float)2764.601532F);
        sound.sample = (int)((float)24576.0F * sinf(_val));
        sound.buffer[4 * i] = sound.buffer[4 * i + 2] = (char)(sound.sample & 0xff);
        sound.buffer[4 * i + 1] = sound.buffer[4 * i + 3] = (char)((sound.sample >> 0x08) & 0xff);
    }
    return sound;
}


/** Generate a 1000Hz tone lasting one second; remember to use `free(sound.buffer);` */
tone tone1000hz(ao_sample_format format) {
    tone sound;
    sound.buf_size = (((format.bits / 8) * format.channels) * format.rate);
    register int i;
    register float _val;
    for (i = 0; i < format.rate; ++i) {
        _val = (((float)i / (float)format.rate) * (float)6283.18530F);
        sound.sample = (int)((float)24576.0F * sinf(_val));
        sound.buffer[4 * i] = sound.buffer[4 * i + 2] = (char)(sound.sample & 0xff);
        sound.buffer[4 *i + 1] = sound.buffer[4 * i + 3] = (char)((sound.sample >> 0x08) & 0xff);
    }
    return sound;
}


/* PLAY SOUND */


/** Play a sound (440Hz tone for one second); return `1` if unable to open device */
int playsound(void) {
    ao_device *device;
    ao_sample_format format;
    tone sound;
    ao_initialize();
    memset(&format, 0, sizeof(ao_sample_format));
    format.bits = 0x0f;  // 16
    format.channels = 0x02;  // 2
    format.rate = 0xac44;  // 44100
    format.byte_format = AO_FMT_LITTLE;
    device = ao_open_live(ao_default_driver_id(), &format, NULL);
    if (device == NULL) { return 1; }
    sound = tone440hz(format);
    ao_play(device, sound.buffer, (unsigned int)sound.buf_size);
    ao_close(device);
    ao_shutdown();
    return 0;
}


/** Play a tone at the specified frequency; return `1` if unable to open device */
int playtone(const float freq) {
    ao_device *device;
    ao_sample_format format;
    tone sound;
    ao_initialize();
    format = defaultsoundformat();
    device = initdriver(format);
    if (device == NULL) { return 1; }
    sound = generatetone(freq, format);
    ao_play(device, sound.buffer, (unsigned int)sound.buf_size);
    ao_close(device);
    ao_shutdown();
    return 0;
}

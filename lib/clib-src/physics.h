// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file physics.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Physics Functions (header)
@version 2016.03.18

@section DESCRIPTION
Functions related to physics calculations

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


#ifndef FILE_PHYSICS_SEEN
#define FILE_PHYSICS_SEEN


#include "MACROS.h"


/* CONSTANTS */
extern const double ATMOSPHERIC_PRESSURE;  // kPa
extern const long double ATMOSPHERIC_PRESSUREl;  // kPa
extern const double ESCAPE_VELOCITY;  // m/s
extern const long double ESCAPE_VELOCITYl;  // m/s
extern const double G;  // m/s2
extern const long double Gl;  // m/s2
/* EQUATIONS */
double density(const double mass, const double volume);
double pressure(const double force, const double area);
double distance(const double speed, const double time);
double speed(const double distance, const double time);
double acceleration_given_velocity(const double velocity_change, const double time);
double acceleration_given_force(const double force, const double mass);
double momentum(const double mass, const double velocity);
double force(const double mass, const double acceleration);
double impulse(const double force, const double time);
double impulse_given_mass_velocity(const double mass, const double velocity);
double work(const double force, const double distance);
double power(const double force, const double distance, const double time);
double power_given_work_time(const double work, const double time);
double kinetic_energy(const double mass, const double velocity);
double potential_energy(const double mass_kg, const double height_meters);
double gravitational_intensity(const double distance);
double instantaneous_speed(const double acceleration, const double time);
double freefall_velocity(const double time_sec);
double freefall_distance(const double time_sec);


#endif

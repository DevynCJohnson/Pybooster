// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file physics.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Physics Functions
@version 2016.03.09

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


#include "physics.h"


/* CONSTANTS */


/** Earth's Atmospheric Pressure */
const double ATMOSPHERIC_PRESSURE = 101.0;  // kPa
/** Earth's Atmospheric Pressure */
const long double ATMOSPHERIC_PRESSUREl = 101.0L;  // kPa
/** Earth's Escape Velocity */
const double ESCAPE_VELOCITY = 8000000.0;  // m/s
/** Earth's Escape Velocity */
const long double ESCAPE_VELOCITYl = 8000000.0L;  // m/s
/** Earth's Gravitational Constant */
const double G = 9.8;  // m/s2
/** Earth's Gravitational Constant */
const long double Gl = 9.8L;  // m/s2


/* EQUATIONS */


/**
    Return density given mass and volume

    @param[in] mass
    @param[in] volume
    @returns Density
*/
double density(const double mass, const double volume) {
    return (mass / volume);
}


/**
    Return pressure given force and area

    @param[in] force
    @param[in] area    Area of the acting force
    @returns Pressure
*/
double pressure(const double force, const double area) {
    return (force / area);
}


/**
    Return distance given speed and time

    @param[in] speed
    @param[in] time
    @returns Distance
*/
double distance(const double speed, const double time) {
    return (speed * time);
}


/**
    Return speed/velocity given the distance and time

    @param[in] distance
    @param[in] time
    @returns Speed
*/
double speed(const double distance, const double time) {
    return (distance / time);
}


/**
    Return the acceleration given time and change in velocity

    @param[in] velocity_change
    @param[in] time
    @returns Acceleration
*/
double acceleration_given_velocity(const double velocity_change, const double time) {
    return (velocity_change / time);
}


/**
    Return the acceleration given force and mass

    @param[in] force
    @param[in] mass
    @returns Acceleration
*/
double acceleration_given_force(const double force, const double mass) {
    return (force / mass);
}


/**
    Return momentum given mass and velocity

    @param[in] mass
    @param[in] velocity    Amount of directional speed of the mass
    @returns Momentum
*/
double momentum(const double mass, const double velocity) {
    return (mass * velocity);
}


/**
    Return the force given mass and acceleration

    @param[in] mass
    @param[in] acceleration    Amount of acceleration of the mass
    @returns Force
*/
double force(const double mass, const double acceleration) {
    return (mass * acceleration);
}


/**
    Return impulse given force and time

    @param[in] force
    @param[in] time    Amount of time the force was exerted
    @returns Impulse
*/
double impulse(const double force, const double time) {
    return (force * time);
}


/**
    Return impulse given velocity and a change in mass

    @param[in] mass
    @param[in] velocity
    @returns Impulse
*/
double impulse_given_mass_velocity(const double mass, const double velocity) {
    return (mass * velocity);
}


/**
    Return work given force and distance

    @param[in] force
    @param[in] distance    Amount of distance the force was exerted
    @returns Work exerted
*/
double work(const double force, const double distance) {
    return (force * distance);
}


/**
    Return power given force, distance, and time

    @param[in] force
    @param[in] distance    Amount of distance the force was exerted
    @param[in] time    Amount of time the force was exerted
    @returns Power (Watts)
*/
double power(const double force, const double distance, const double time) {
    return ((force * distance) / time);
}


/**
    Return power given work and time

    @param[in] work    Work (Newtons)
    @param[in] time    Amount of time the work was exerted
    @returns Power (Watts)
*/
double power_given_work_time(const double work, const double time) {
    return (work / time);
}


/**
    Return the kinetic-energy given mass and velocity

    @param[in] mass    Mass of some object
    @param[in] velocity    Velocity of the object
    @returns Kinetic energy of an object at a given velocity and mass
*/
double kinetic_energy(const double mass, const double velocity) {
    return (0.500 * mass * velocity * velocity);
}


/**
    Return potential-energy given mass (kg) and height (meters) of an object on Earth

    @param[in] mass_kg    Mass of some object
    @param[in] height_meters    height from some surface
    @returns Potential energy of an object on Earth at a given height and mass
*/
double potential_energy(const double mass_kg, const double height_meters) {
    return (mass_kg * G * height_meters);
}


/**
    Return gravitational intensity given distance

    @param[in] distance    Distance between two objects
    @returns Gravitational intensity at the given distance
*/
double gravitational_intensity(const double distance) {
    return (1.0 / (distance * distance));
}


/**
    Return instantaneous speed given acceleration and time

    @param[in] acceleration    Acceleration at the given time
    @param[in] time    Time of the given instance
    @returns Speed at the given time and acceleration
*/
double instantaneous_speed(const double acceleration, const double time) {
    return (acceleration * time);
}


/**
    Return the freefall velocity given time (seconds)

    @param[in] time_sec    Time since falling
    @returns Free-fall velocity at the given time
*/
double freefall_velocity(const double time_sec) {
    return (G * time_sec);
}


/**
    Return distance fallen during freefall given time (seconds)

    @param[in] time_sec    Time since falling
    @returns Distance fallen at the given time
*/
double freefall_distance(const double time_sec) {
    return (0.500 * G * time_sec * time_sec);
}

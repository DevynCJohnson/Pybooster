// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
/**
@brief Macros Header for ANSI SGR Codes
@file ansi_sgr_codes.h
@version 2019.11.23
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


/* ANSI SGR CODES */


#if (!(defined(ANSI_SGR_CODES_H) || defined(_ANSI_SGR_CODES_H) || defined(_ANSI_SGR_CODES_H_)))
#define ANSI_SGR_CODES_H   (1)
#define _ANSI_SGR_CODES_H   (1)
#define _ANSI_SGR_CODES_H_   (1)


/* EFFECTS */

/** @defgroup ANSI_SGR_Effects Macros for various ANSI SGR Effects
@{ */  // (FB){

#ifndef DISABLE_ANSI_SGR
/** Reset ANSI SGR (Select Graphic Rendition) Settings */
#   define ANSI_SGR_RESET   "\x1b[0m"
/** Reset ANSI SGR (Select Graphic Rendition) Settings */
#   define ANSI_SGR_END   "\x1b[0m"
/** ANSI SGR (Select Graphic Rendition): Bold */
#   define ANSI_SGR_BOLD   "\x1b[1m"
/** ANSI SGR (Select Graphic Rendition): Bold/Faint Off */
#   define ANSI_SGR_BOLD_OFF   "\x1b[22m"
/** ANSI SGR (Select Graphic Rendition): Faint */
#   define ANSI_SGR_FAINT   "\x1b[2m"
/** ANSI SGR (Select Graphic Rendition): Italic */
#   define ANSI_SGR_ITALIC   "\x1b[3m"
/** ANSI SGR (Select Graphic Rendition): Italic Off */
#   define ANSI_SGR_ITALIC_OFF   "\x1b[23m"
/** ANSI SGR (Select Graphic Rendition): Underline */
#   define ANSI_SGR_UNDERLINE   "\x1b[4m"
/** ANSI SGR (Select Graphic Rendition): Underline Off */
#   define ANSI_SGR_UNDERLINE_OFF   "\x1b[24m"
/** ANSI SGR (Select Graphic Rendition): Conceal */
#   define ANSI_SGR_CONCEAL   "\x1b[8m"
/** ANSI SGR (Select Graphic Rendition): Reveal (Conceal Off) */
#   define ANSI_SGR_REVEAL   "\x1b[28m"
/** ANSI SGR (Select Graphic Rendition): Crossed-Out */
#   define ANSI_SGR_CROSSEDOUT   "\x1b[9m"
/** ANSI SGR (Select Graphic Rendition): Crossed-Out Off */
#   define ANSI_SGR_CROSSEDOUT_OFF   "\x1b[29m"
/** ANSI SGR (Select Graphic Rendition): Swap foreground and background */
#   define ANSI_SGR_SWAP_FG_BG   "\x1b[7m"
#else
#   define ANSI_SGR_RESET
#   define ANSI_SGR_END
#   define ANSI_SGR_BOLD
#   define ANSI_SGR_BOLD_OFF
#   define ANSI_SGR_FAINT
#   define ANSI_SGR_ITALIC
#   define ANSI_SGR_ITALIC_OFF
#   define ANSI_SGR_UNDERLINE
#   define ANSI_SGR_UNDERLINE_OFF
#   define ANSI_SGR_CONCEAL
#   define ANSI_SGR_REVEAL
#   define ANSI_SGR_CROSSEDOUT
#   define ANSI_SGR_CROSSEDOUT_OFF
#   define ANSI_SGR_SWAP_FG_BG
#endif

/** @} */  // }


/* COLORS */

/** @defgroup ANSI_SGR_Colors Macros for various ANSI SGR Colors
@{ */  // (FB){

#ifndef DISABLE_ANSI_SGR
/** ANSI SGR (Select Graphic Rendition): Foreground Black */
#   define ANSI_SGR_FG_BLACK   "\x1b[30m"
/** ANSI SGR (Select Graphic Rendition): Foreground Red */
#   define ANSI_SGR_FG_RED   "\x1b[31m"
/** ANSI SGR (Select Graphic Rendition): Foreground Green */
#   define ANSI_SGR_FG_GREEN   "\x1b[32m"
/** ANSI SGR (Select Graphic Rendition): Foreground Yellow */
#   define ANSI_SGR_FG_YELLOW   "\x1b[33m"
/** ANSI SGR (Select Graphic Rendition): Foreground Blue */
#   define ANSI_SGR_FG_BLUE   "\x1b[34m"
/** ANSI SGR (Select Graphic Rendition): Foreground Magenta */
#   define ANSI_SGR_FG_MAGENTA   "\x1b[35m"
/** ANSI SGR (Select Graphic Rendition): Foreground Cyan */
#   define ANSI_SGR_FG_CYAN   "\x1b[36m"
/** ANSI SGR (Select Graphic Rendition): Foreground White */
#   define ANSI_SGR_FG_WHITE   "\x1b[37m"
/** ANSI SGR (Select Graphic Rendition): Foreground Black & Bold */
#   define ANSI_SGR_FG_BBLACK   "\x1b[1;30m"
/** ANSI SGR (Select Graphic Rendition): Foreground Red & Bold */
#   define ANSI_SGR_FG_BRED   "\x1b[1;31m"
/** ANSI SGR (Select Graphic Rendition): Foreground Green & Bold */
#   define ANSI_SGR_FG_BGREEN   "\x1b[1;32m"
/** ANSI SGR (Select Graphic Rendition): Foreground Yellow & Bold */
#   define ANSI_SGR_FG_BYELLOW   "\x1b[1;33m"
/** ANSI SGR (Select Graphic Rendition): Foreground Blue & Bold */
#   define ANSI_SGR_FG_BBLUE   "\x1b[1;34m"
/** ANSI SGR (Select Graphic Rendition): Foreground Magenta & Bold */
#   define ANSI_SGR_FG_BMAGENTA   "\x1b[1;35m"
/** ANSI SGR (Select Graphic Rendition): Foreground Cyan & Bold */
#   define ANSI_SGR_FG_BCYAN   "\x1b[1;36m"
/** ANSI SGR (Select Graphic Rendition): Foreground White & Bold */
#   define ANSI_SGR_FG_BWHITE   "\x1b[1;37m"
/** ANSI SGR (Select Graphic Rendition): Background Black */
#   define ANSI_SGR_BG_BLACK   "\x1b[40m"
/** ANSI SGR (Select Graphic Rendition): Background Red */
#   define ANSI_SGR_BG_RED   "\x1b[41m"
/** ANSI SGR (Select Graphic Rendition): Background Green */
#   define ANSI_SGR_BG_GREEN   "\x1b[42m"
/** ANSI SGR (Select Graphic Rendition): Background Yellow */
#   define ANSI_SGR_BG_YELLOW   "\x1b[43m"
/** ANSI SGR (Select Graphic Rendition): Background Blue */
#   define ANSI_SGR_BG_BLUE   "\x1b[44m"
/** ANSI SGR (Select Graphic Rendition): Background Magenta */
#   define ANSI_SGR_BG_MAGENTA   "\x1b[45m"
/** ANSI SGR (Select Graphic Rendition): Background Cyan */
#   define ANSI_SGR_BG_CYAN   "\x1b[46m"
/** ANSI SGR (Select Graphic Rendition): Background White */
#   define ANSI_SGR_BG_WHITE   "\x1b[47m"
/** ANSI SGR (Select Graphic Rendition): Background Bright Black */
#   define ANSI_SGR_BG_BRIGHT_BLACK   "\x1b[100m"
/** ANSI SGR (Select Graphic Rendition): Background Bright Red */
#   define ANSI_SGR_BG_BRIGHT_RED   "\x1b[101m"
/** ANSI SGR (Select Graphic Rendition): Background Bright Green */
#   define ANSI_SGR_BG_BRIGHT_GREEN   "\x1b[102m"
/** ANSI SGR (Select Graphic Rendition): Background Bright Yellow */
#   define ANSI_SGR_BG_BRIGHT_YELLOW   "\x1b[103m"
/** ANSI SGR (Select Graphic Rendition): Background Bright Blue */
#   define ANSI_SGR_BG_BRIGHT_BLUE   "\x1b[104m"
/** ANSI SGR (Select Graphic Rendition): Background Bright Magenta */
#   define ANSI_SGR_BG_BRIGHT_MAGENTA   "\x1b[105m"
/** ANSI SGR (Select Graphic Rendition): Background Bright Cyan */
#   define ANSI_SGR_BG_BRIGHT_CYAN   "\x1b[106m"
/** ANSI SGR (Select Graphic Rendition): Background Bright White */
#   define ANSI_SGR_BG_BRIGHT_WHITE   "\x1b[107m"
/** ANSI SGR (Select Graphic Rendition): Select RGB foreground color */
#   define SET_ANSI_SGR_FG_COLOR(r, g, b)   "\x1b[38;2;" S(r) ";" S(g) ";" S(b) "m"
/** ANSI SGR (Select Graphic Rendition): Select RGB background color */
#   define SET_ANSI_SGR_BG_COLOR(r, g, b)   "\x1b[48;2;" S(r) ";" S(g) ";" S(b) "m"
/** ANSI SGR (Select Graphic Rendition): Move cursor to start-of-line */
#   define ANSI_SGR_CUR_START   "\x1b[1000D"
#else
#   define ANSI_SGR_FG_BLACK
#   define ANSI_SGR_FG_RED
#   define ANSI_SGR_FG_GREEN
#   define ANSI_SGR_FG_YELLOW
#   define ANSI_SGR_FG_BLUE
#   define ANSI_SGR_FG_MAGENTA
#   define ANSI_SGR_FG_CYAN
#   define ANSI_SGR_FG_WHITE
#   define ANSI_SGR_FG_BBLACK
#   define ANSI_SGR_FG_BRED
#   define ANSI_SGR_FG_BGREEN
#   define ANSI_SGR_FG_BYELLOW
#   define ANSI_SGR_FG_BBLUE
#   define ANSI_SGR_FG_BMAGENTA
#   define ANSI_SGR_FG_BCYAN
#   define ANSI_SGR_FG_BWHITE
#   define ANSI_SGR_BG_BLACK
#   define ANSI_SGR_BG_RED
#   define ANSI_SGR_BG_GREEN
#   define ANSI_SGR_BG_YELLOW
#   define ANSI_SGR_BG_BLUE
#   define ANSI_SGR_BG_MAGENTA
#   define ANSI_SGR_BG_CYAN
#   define ANSI_SGR_BG_WHITE
#   define ANSI_SGR_BG_BRIGHT_BLACK
#   define ANSI_SGR_BG_BRIGHT_RED
#   define ANSI_SGR_BG_BRIGHT_GREEN
#   define ANSI_SGR_BG_BRIGHT_YELLOW
#   define ANSI_SGR_BG_BRIGHT_BLUE
#   define ANSI_SGR_BG_BRIGHT_MAGENTA
#   define ANSI_SGR_BG_BRIGHT_CYAN
#   define ANSI_SGR_BG_BRIGHT_WHITE
#   define SET_ANSI_SGR_FG_COLOR(r, g, b)
#   define SET_ANSI_SGR_BG_COLOR(r, g, b)
#   define ANSI_SGR_CUR_START   "\x1b[1000D"
#endif

/** @} */  // }


/* LENGTH OF ANSI STRINGS */

#ifndef DISABLE_ANSI_SGR
/** The string length of ANSI reset property */
#   define ANSI_SGR_END_LEN   4
/** The string length of ANSI foreground property */
#   define ANSI_SGR_FG_LEN   5
/** The string length of ANSI foreground+bold property */
#   define ANSI_SGR_FG_BOLD_LEN   7
/** The string length of ANSI cursor-start-of-line property */
#   define ANSI_SGR_CUR_START_LEN   7
#else
#   define ANSI_SGR_END_LEN   0
#   define ANSI_SGR_FG_LEN   0
#   define ANSI_SGR_FG_BOLD_LEN   0
#   define ANSI_SGR_CUR_START_LEN   0
#endif


#endif  // ANSI_SGR_CODES_H

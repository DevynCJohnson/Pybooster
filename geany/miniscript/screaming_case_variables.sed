#!/usr/bin/sed -E -f
# -*- coding: utf-8-unix; Mode: Sed; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=sed syn=sed.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax sed; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Change variables being defined to SCREAMING_CASE
#' @file screaming_case_variables
#' @version 2018.10.06
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>


s|^(.+)([ \t]*)=([ \t]*)(.+)$|\U\1\E\2=\3\4|

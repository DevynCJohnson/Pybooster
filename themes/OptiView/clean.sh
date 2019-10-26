#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Clean-up the Theme Project
#' @file clean.sh
#' @version 2019.10.26
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


[ -d ./build ] && rm -f -r ./build

rm -f ./gtk/src/OptiView/gtk-2.0/assets/*.png ./gtk/src/OptiView/gtk-3.0/assets/*.png ./gtk/src/OptiView-Dark/gtk-2.0/assets/*.png ./unity/*.png ./xfwm4/src/OptiView/*.png ./xfwm4/src/OptiView-Dark/*.png || true

exit 0

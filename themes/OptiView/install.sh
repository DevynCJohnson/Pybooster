#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Install the Theme
#' @file install.sh
#' @version 2019.10.26
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


TOPDIR="$(pwd)"


sh ./clean.sh

sh -c 'cd ./gtk/src/OptiView/gtk-2.0 && sh ./render-assets.sh' &
cd ./gtk/src/OptiView/gtk-3.0 && sh ./render-assets.sh
cd "$TOPDIR" || exit 1
sh -c 'cd ./unity && sh ./render-assets.sh' &
cd ./xfwm4/src/OptiView && sh ./render-assets.sh
cd "$TOPDIR" || exit 1
sh -c 'cd ./gtk/src/OptiView-Dark/gtk-2.0 && sh ./render-assets.sh' &
cd ./xfwm4/src/OptiView-Dark && sh ./render-assets.sh

wait

cd "$TOPDIR" || exit 1

sudo rm -f -r /usr/share/themes/OptiView /usr/share/themes/OptiView-Dark /usr/share/themes/OptiView-shell || true
meson build && sudo ninja -C build install
sh ./clean.sh

#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Install the Theme
#' @file install.sh
#' @version 2019.12.21
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


TOPDIR="$(pwd)"


sh ./clean.sh


[ ! -x "$(command -v meson)" ] && { printf 'ERROR: `meson` not found!\n' >&2; exit 1; }
[ ! -x "$(command -v ninja)" ] && { printf 'ERROR: `ninja` not found!\n' >&2; exit 1; }
[ ! -x "$(command -v inkscape)" ] && { printf 'ERROR: `inkscape` not found!\n' >&2; exit 1; }
[ ! -x "$(command -v pysassc)" ] && { printf 'ERROR: `pysassc` not found!\n' >&2; exit 1; }
[ ! -x "$(command -v pngcrush)" ] && { printf 'WARNING: `pngcrush` is strongly recommended, but not required!\n' >&2; }
[ ! -x "$(command -v rename)" ] && { printf 'WARNING: `rename` is strongly recommended, but not required!\n' >&2; }


sh -c 'cd ./gtk/src/OptiView/gtk-2.0 && sh ./render-assets.sh' &
sh -c 'cd ./gtk/src/OptiView/gtk-3.0 && sh ./render-assets.sh' &
sh -c 'cd ./unity && sh ./render-assets.sh' &
sh -c 'cd ./xfwm4/src/OptiView && sh ./render-assets.sh' &
wait
cd "$TOPDIR" || exit 1
sh -c 'cd ./gtk/src/OptiView-Dark/gtk-2.0 && sh ./render-assets.sh' &
sh -c 'cd ./xfwm4/src/OptiView-Dark && sh ./render-assets.sh' &

wait

cd "$TOPDIR" || exit 1

sudo rm -f -r /usr/share/themes/OptiView /usr/share/themes/OptiView-Dark /usr/share/themes/OptiView-shell || true
meson build && sudo ninja -C build install && sh ./clean.sh

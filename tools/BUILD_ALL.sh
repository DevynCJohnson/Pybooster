#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
# @brief Automated building (displays gnome-terminal)
# @file BUILD_ALL.sh
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @version 2018.04.27
# @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


cd .. || exit 1

if [ -x "$(command -v gnome-terminal)" ]; then
    gnome-terminal --hide-menubar --title=Building_Project -e './tools/build.sh'
elif [ -x "$(command -v uxterm)" ]; then
    uxterm -title Building_Project -e './tools/build.sh'
elif [ -x "$(command -v xterm)" ]; then
    xterm -title Building_Project -e './tools/build.sh'
else
    printf 'Unable to find a terminal application\n' >&2
    exit 1
fi

exit 0

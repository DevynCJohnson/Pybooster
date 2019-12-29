#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Change various system settings to fix some issues with the proprietary Nvidia driver
#' @file fix_nvidia.sh
#' @version 2019.12.28
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# MAIN #


if [ ! "$(id -u)" -eq 0 ]; then
    exec sudo -- "$0"
else
    { getent group nvidia-persistenced 2>&1 > /dev/null; } || groupadd -g 143 nvidia-persistenced
    { getent passwd nvidia-persistenced 2>&1 > /dev/null; } || useradd -c 'NVIDIA Persistence Daemon' -u 143 -g nvidia-persistenced -d '/' -s /sbin/nologin nvidia-persistenced
    getent group root | grep -F -q -v 'nvidia-persistenced' && usermod -a -G root nvidia-persistenced
    getent group nvidia-persistenced | grep -F -q -v 'root' && usermod -a -G nvidia-persistenced root
fi

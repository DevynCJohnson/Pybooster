#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Convert ChangeLog to ChnageLog.md
#' @file mkchangelogmd.sh
#' @version 2019.03.28
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# MAIN #


if [ ! -r './ChangeLog' ] || [ ! -f './ChangeLog' ]; then
    printf 'ERROR: ./ChangeLog was not found or is not readable!\n' >&2
    exit 1
else
    sed -E -e 's|^[ \t]*\* ([^:]+):  (.+)$|- **\1:**  \2|; s|^([0-9]{4})\-([0-9]{2})\-([0-9]{2}) (.+) <(.+)>$|# \1-\2-\3 \4 <[\5](mailto:\5)>|;' > ./ChangeLog.md < ./ChangeLog
fi

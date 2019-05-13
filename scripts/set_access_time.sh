#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Set the access-time of the file equal to the modification-time
#' @file set_access_time
#' @version 2019.05.12
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


if [ -z "${1:-}" ]; then
    printf 'ERROR: One parameter is required!\n' >&2
    exit 1
elif [ "$1" = '--help' ] || [ "$1" = 'help' ] || [ "$1" = '-h' ]; then
    printf 'Specify the pathname of a directory in which to change the access-times of files.\n'
    exit 0
elif [ ! -d "${1:-}" ]; then
    printf 'ERROR: The given path must be a directory!\n' >&2
    exit 1
fi


find "${1}" -type f -print | while read -r filename; do
    touch -m -a -d "$(stat --format '%y' "${filename}")" "${filename}"
done


exit 0

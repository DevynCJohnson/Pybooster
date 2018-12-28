#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Generate documentation for Python using PyDoc
#' @file pydocgen.sh
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @version 2018.12.28
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


if [ ! -d "$1" ] || [ -z "$1" ]; then
    printf 'The first parameter must be the source directory!\n' >&2
    exit 1
elif [ ! -d "$2" ] || [ -z "$2" ]; then
    printf 'The second parameter must be the destination directory!\n' >&2
    exit 1
elif [ -z "$3" ]; then
    printf 'There must be parameters after the second parameter!\n' >&2
    exit 1
elif [ ! -x "$(command -v python3)" ]; then
    printf 'python3: command not found\n\n' >&2
    exit 1
fi

DOCDIR="$2"
[ ! -d "${DOCDIR}/pylib/" ] && mkdir "${DOCDIR}/pylib/"
cd "$1" || (printf 'Unable to change directory to "%s"!\n' "$1" >&2 && exit 1)
shift 2

for module in "$@"; do
    if [ ! -r "${module}.py" ]; then
        printf '%s: The specified file is non-readable or non-existent!\n' "$module" >&2
        continue
    fi
    python3 -m pydoc "$module" > ".${DOCDIR}/pylib/${module}.txt"
done


printf 'Finished generating Python documentaion\n'
exit 0

#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
# @brief Automated building using Clang
# @file build_clang.sh
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @version 2018.04.27
# @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


if [ -x "$(command -v clang-9.0)" ]; then
    CLANG_VERSION=9.0
elif [ -x "$(command -v clang-9)" ]; then
    CLANG_VERSION=9
elif [ -x "$(command -v clang-8.0)" ]; then
    CLANG_VERSION=8.0
elif [ -x "$(command -v clang-8)" ]; then
    CLANG_VERSION=8
elif [ -x "$(command -v clang-7.0)" ]; then
    CLANG_VERSION=7.0
elif [ -x "$(command -v clang-7)" ]; then
    CLANG_VERSION=7
elif [ -x "$(command -v clang-6.0)" ]; then
    CLANG_VERSION=6.0
elif [ -x "$(command -v clang-6)" ]; then
    CLANG_VERSION=6
elif [ -x "$(command -v clang-5.5)" ]; then
    CLANG_VERSION=5.5
elif [ -x "$(command -v clang-5.0)" ]; then
    CLANG_VERSION=5.0
elif [ -x "$(command -v clang-5)" ]; then
    CLANG_VERSION=5
elif [ -x "$(command -v clang-4.0)" ]; then
    CLANG_VERSION=4.0
elif [ -x "$(command -v clang-4)" ]; then
    CLANG_VERSION=4
else
    printf 'clang: command not found!\n' >&2
    exit 1
fi

export CC="clang-${CLANG_VERSION}"
export CXX="clang++-${CLANG_VERSION}"

make clean
make -j8 dcj=1 CLANG="${CLANG_VERSION}" all
make rmtmp

printf '\nDONE; Press enter to exit\n'
read -r

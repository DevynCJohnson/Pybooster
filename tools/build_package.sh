#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
# @brief Automated building and packaging of PyBooster
# @file build_package.sh
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @version 2018.09.11
# @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


cd .. || exit 1
make rmtmp


build_package() {
    make -j8 dcj="$1" DIAG=0 all && cd .. && tar --exclude='.git' --exclude='.git*' -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_"${2}".tar.gz && cd ./PyBooster && printf '\n%s\n' "Packaged ${3} Build"
    make rmtmp
}


build_cross_package() {
    make -j8 OS="$1" CROSS_COMPILE="$2" DIAG=0 all && cd .. && tar --exclude='.git' --exclude='.git*' -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_"${3}".tar.gz && cd ./PyBooster && printf '\n%s\n' "Packaged ${4} Build"
    make rmtmp
}


## LINUX X86 ##


build_package 'haswell' 'Linux_Haswell64' 'Linux Haswell (64-bit)'

build_package 'broadwell' 'Linux_Broadwell64' 'Linux Broadwell (64-bit)'

build_package 'skylake' 'Linux_Skylake64' 'Linux Skylake (64-bit)'

build_package 'athlon64-sse3' 'Linux_Athlon64' 'Linux Athlon64 (SSE3)'

build_package 'znver1' 'Linux_AMD64_Family_17h' 'Linux AMD64 (AMD Family 17h)'

build_package 'GENERICX86' 'Linux_Generic_x86_32' 'Generic x86-32'

build_package 'GENERICX86_64' 'Linux_Generic_x86_64' 'Generic x86-64'


## LINUX ARM ##


build_cross_package 'LINUX' 'armel' 'Linux_ARMEL' 'Linux ARMEL'

build_cross_package 'LINUX' 'armhf' 'Linux_ARMHF' 'Linux ARMHF'

build_cross_package 'LINUX' 'rpi' 'Linux_RPi' 'Linux RPi'


## WINDOWS ##


build_cross_package 'WIN' 'win32' 'WIN32' 'Windows x86-32'

build_cross_package 'WIN' 'win64' 'WIN64' 'Windows x86-64'


## DONE ##


printf '\nDONE; Press enter to exit\n'
read -r

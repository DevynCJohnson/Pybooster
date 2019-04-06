#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Retreieve the repository keys
#' @file getgpgkeys.sh
#' @version 2019.04.06
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# SETUP #


if [ ! "$(id -u)" -eq 0 ]; then
    exec sudo -- "$0"
    exit $?
fi

[ ! "$(id -u)" -eq 0 ] && printf 'Root permissions are required!\n' >&2 && exit 1
[ ! -x "$(command -v apt-key)" ] && printf '"apt-key" is required to be present in "\u0024PATH"!\n' >&2 && exit 1


if [ -x "$(command -v wget)" ]; then
    _webget(){ wget -q -O - "${1}"; }
elif [ -x "$(command -v curl)" ]; then
    _webget(){ curl -s "${1}"; }
else
    printf '"wget" or "curl" are required to be present in "\u0024PATH"!\n' >&2 && exit 1
fi


# GET KEYS #


_webget https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -  # Clang and LLVM
_webget https://deb.opera.com/archive.key | apt-key add -  # Opera
_webget https://deb.torproject.org/torproject.org/A3C4F0F979CAA22CDBA8F512EE8CBC9E886DDD89.asc | apt-key add -  # Tor
_webget https://dl.google.com/linux/linux_signing_key.pub | apt-key add -  # Google
_webget https://download.docker.com/linux/ubuntu/gpg | apt-key add -  # Docker
_webget https://repo.skype.com/data/SKYPE-GPG-KEY | sudo apt-key add -  # Skype
_webget https://syncthing.net/release-key.txt | apt-key add -  # Syncthing
_webget https://winswitch.org/gpg.asc | apt-key add -  # WinSwitch & Xpra
_webget https://www.postgresql.org/media/keys/ACCC4CF8.asc | apt-key add -  # PostgreSQL
apt-key adv --keyserver ha.pool.sks-keyservers.net --recv-keys A4A9406876FCBD3C456770C88C718D3B5072E1F5  # MySQL
apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 931FF8E79F0876134EDDBDCCA87FF9DF48BF1C90  # Spotify
apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 9DA31620334BD75D9DCB49F368818C72E52529D4  # MongoDB
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 125E48D66C5B656D41D67EEB7B5C8CB04AB5A282  # GPU Info
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 165D673674A995B3E64BF0CF4F191A5A8844C542  # Xorg Edgers
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 2388FF3BE10A76F638F80723FCAE110B1118213C  # Nvidia Graphics Drivers
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 304B1387D4C3A038E93F11E251339601186060AE  # AntumDeluge Debreate
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 36E81C9267FD1383FCC4490983FBA1751378B444  # LibreOffice
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 3A68BA40877059E65867971771240B8FB3641232  # Geany
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 4FA44A478284A18C1BA4A9CAD530E028F59EAE4D  # NoobsLab
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 7B2C3B0889BF5709A105D03AC2518248EEA14886  # Webupd8Team
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 8141A328E64AC6C85D337D03EFD5FA852F20733F  # FingerPrint
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 94978FBE03F23B4439166BF2A02ACCC9C6DAEA80  # Boomaga
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 98703123E0F52B2BE16D586EF13930B14BB9F05F  # SABnzbd
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys AE73297AC7B05AC2D05C88D24B4583F5325C1FAC  # PyCharm
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys B34505EA326FEAEA07E3618DEF4186FE247510BE  # Mozilla Daily Build
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys B7A8ED84DF6AFA37B620BFB2E2B7D64D93330B78  # Highly Explosive
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys BEC4D34EA23B1DA104D3F98450B027516CAEE58D  # Gambas
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys D3D40176F86D5ECBC376357EB95F00C17A51D6F2  # Geary
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys D3DF85B5E00DD3EEEC00C1950CD0F565F8CDAB41  # Minetest
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys E2355710884EB80144EAB769ADA83EDC62D7EDF8  # Color Emoji Fonts
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys E4DFEC907DEDA4B8A670E8042836CB0A8AC93F7A  # Kubuntu
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys FB97E9C3A97F85C095AEA7903BDAAC08614C4B38  # Gimp
apt-key adv --keyserver keyserver.ubuntu.com --recv-keys FE2D607711EDD0FF4D069EC70F6444BB6902FCAF  # Stacer


exit 0

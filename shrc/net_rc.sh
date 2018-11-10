#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Shell RC script providing aliases and functions for network-related tasks
#' @file net_rc.sh
#' @version 2018.11.10
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# FIREWALL #


if [ -x "$(command -v iptables)" ]; then
    #' Clear firewall counters
    alias clrfwcnts='sudo iptables -Z'
    #' List firewall rules
    alias lsfwrules='sudo iptables -L -n -v'
    #' Remove all firewall rules
    alias rmfwrules='sudo iptables --flush'
elif [ -x "$(command -v ufw)" ]; then
    #' List firewall rules
    alias lsfwrules='sudo ufw status verbose'
    #' Remove all firewall rules
    alias rmfwrules='sudo ufw reset'
fi

if [ -x "$(command -v firewall-cmd)" ]; then
    #' Reload firewall
    alias reloadfw='sudo firewall-cmd --reload'
elif [ -x "$(command -v ufw)" ]; then
    #' Reload firewall
    alias reloadfw='sudo ufw reload'
fi


#' Save/Backup firewall rules
backupfwrules() {
    if [ -n "${1:-}" ] && [ -d "${1}" ]; then
        if [[ ! "${1}" =~ ^.+/$ ]]; then
            _output_dir="${1}/"
        else
            _output_dir="${1}"
        fi
        [ -x "$(command -v iptables-save)" ] && sudo iptables-save > "${_output_dir}Firewall_IPv4.bak"
        [ -x "$(command -v ip6tables-save)" ] && sudo ip6tables-save > "${_output_dir}Firewall_IPv6.bak"
        [ -x "$(command -v iptables-restore-translate)" ] && sudo iptables-restore-translate -f "${_output_dir}Firewall_IPv4.bak" > "${_output_dir}Firewall_IPv4.nft"
    else
        [ -x "$(command -v iptables-save)" ] && sudo iptables-save > "${HOME}/Firewall_IPv4.bak"
        [ -x "$(command -v ip6tables-save)" ] && sudo ip6tables-save > "${HOME}/Firewall_IPv6.bak"
        [ -x "$(command -v iptables-restore-translate)" ] && sudo iptables-restore-translate -f "${HOME}/Firewall_IPv4.bak" > "${HOME}/Firewall_IPv4.nft"
    fi
}


#' Restore saved firewall rules
restorefwrules() {
    if [ -n "${1:-}" ] && [ -d "${1}" ]; then
        if [[ ! "${1}" =~ ^.+/$ ]]; then
            _input_dir="${1}/"
        else
            _input_dir="${1}"
        fi
        [ -x "$(command -v iptables-save)" ] && sudo iptables-save > "${_input_dir}Firewall_IPv4.bak"
        [ -x "$(command -v ip6tables-save)" ] && sudo ip6tables-save > "${_input_dir}Firewall_IPv6.bak"
        [ -x "$(command -v nft)" ] && [ -r "${_input_dir}Firewall_IPv4.nft" ] && sudo nft -f "${_input_dir}Firewall_IPv4.nft"
    else
        [ -x "$(command -v iptables-save)" ] && sudo iptables-save > "${HOME}/Firewall_IPv4.bak"
        [ -x "$(command -v ip6tables-save)" ] && sudo ip6tables-save > "${HOME}/Firewall_IPv6.bak"
        [ -x "$(command -v nft)" ] && [ -r "${HOME}/Firewall_IPv4.nft" ] && sudo nft -f "${HOME}/Firewall_IPv4.nft"
    fi
}


# NETWORK ALIASES #


#' Alias for ipconfig to call ifconfig
[ -x "$(command -v ifconfig)" ] && [ -z "$(command -v ipconfig)" ] && alias ipconfig='ifconfig'
#' Shorten `sudo iptables` to `ipt`
[ -x "$(command -v iptables)" ] && alias ipt='sudo iptables'
#' List all available network interfaces
[ -d /sys/class/net/ ] && alias lsnet='ls /sys/class/net/ | awk NF'
#' List all currently open ports
[ -x "$(command -v netstat)" ] && alias lsopenports='netstat -a -l -n -p -t -u'
#' Test if the network as access to the Internet
[ -x "$(command -v ping)" ] && alias testnet='ping -c 1 dcjtech.info || ping -c 1 duckduckgo.com'

if [ -x "$(command -v curl)" ]; then
    #' Test the response speed of the specified website
    alias testwebtime="curl -s -w 'Testing Website Response Time: %{url_effective}\n\nLookup Time:\t\t%{time_namelookup}\nConnect Time:\t\t%{time_connect}\nPre-transfer Time:\t%{time_pretransfer}\nStart-transfer Time:\t%{time_starttransfer}\n\nTotal Time:\t\t%{time_total}\n' -o /dev/null"
    #' Display the web header of the specified website
    alias webheader='curl -I'
fi

if [ -x "$(command -v wget)" ]; then
    #' Download the file at the specified web address
    alias download='wget --no-cache --no-cookies --no-cookies --no-dns-cache --quiet'
fi


# NETWORK CONTROL #


if [ -x "$(command -v nmcli)" ]; then
    #' Disable networking
    alias netOff='nmcli networking off'
    #' Enable networking
    alias netOn='nmcli networking on'
    #' Disable wireless networking
    alias radioOff='nmcli radio all off'
    #' Enable wireless networking
    alias radioOn='nmcli radio all on'
    #' Disable WiFi
    alias wifiOff='nmcli radio wifi off'
    #' Enable WiFi
    alias wifiOn='nmcli radio wifi on'
    #' Disable WWAN
    alias wwanOff='nmcli radio wwan off'
    #' Enable WWAN
    alias wwanOn='nmcli radio wwan on'
    #' List available WiFi hotspots (with details)
    alias wifiScan='nmcli dev wifi'
fi


# DOWNLOAD FUNCTIONS #


#' Download & extract Bzip2
downloadbzip() { wget -c "$1" -O - | tar -jx; }
#' Download & extract Gzip
downloadgzip() { wget -c "$1" -O - | tar -xz; }
#' Download & extract XZ
downloadxz() { wget -c "$1" -O - | tar -Jx; }

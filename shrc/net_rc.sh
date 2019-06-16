#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Shell RC script providing aliases and functions for network-related tasks
#' @file net_rc.sh
#' @version 2019.03.28
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
    if [ "$(id -u)" != '0' ]; then
        printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2
    elif [ -n "${1:-}" ] && [ -d "${1}" ]; then
        if [[ ! "${1}" =~ ^.+/$ ]]; then
            _output_dir="${1}/"
        else
            _output_dir="${1}"
        fi
        [ -x "$(command -v iptables-save)" ] && iptables-save > "${_output_dir}Firewall_IPv4.bak"
        [ -x "$(command -v ip6tables-save)" ] && ip6tables-save > "${_output_dir}Firewall_IPv6.bak"
        [ -x "$(command -v iptables-restore-translate)" ] && iptables-restore-translate -f "${_output_dir}Firewall_IPv4.bak" > "${_output_dir}Firewall_IPv4.nft"
    else
        [ -x "$(command -v iptables-save)" ] && iptables-save > "${HOME}/Firewall_IPv4.bak"
        [ -x "$(command -v ip6tables-save)" ] && ip6tables-save > "${HOME}/Firewall_IPv6.bak"
        [ -x "$(command -v iptables-restore-translate)" ] && iptables-restore-translate -f "${HOME}/Firewall_IPv4.bak" > "${HOME}/Firewall_IPv4.nft"
    fi
}


#' Restore saved firewall rules
restorefwrules() {
    if [ "$(id -u)" != '0' ]; then
        printf '\x1b[1;31mERROR\x1b[0m: Root privileges are required!\n\n' >&2
    elif [ -n "${1:-}" ] && [ -d "${1}" ]; then
        if [[ ! "${1}" =~ ^.+/$ ]]; then
            _input_dir="${1}/"
        else
            _input_dir="${1}"
        fi
        [ -x "$(command -v iptables-save)" ] && iptables-save > "${_input_dir}Firewall_IPv4.bak"
        [ -x "$(command -v ip6tables-save)" ] && ip6tables-save > "${_input_dir}Firewall_IPv6.bak"
        [ -x "$(command -v nft)" ] && [ -r "${_input_dir}Firewall_IPv4.nft" ] && nft -f "${_input_dir}Firewall_IPv4.nft"
    else
        [ -x "$(command -v iptables-save)" ] && iptables-save > "${HOME}/Firewall_IPv4.bak"
        [ -x "$(command -v ip6tables-save)" ] && ip6tables-save > "${HOME}/Firewall_IPv6.bak"
        [ -x "$(command -v nft)" ] && [ -r "${HOME}/Firewall_IPv4.nft" ] && nft -f "${HOME}/Firewall_IPv4.nft"
    fi
}


# NETWORK ALIASES #


#' Alias for ipconfig to call ifconfig
[ -n "$(command -v ifconfig)" ] && [ -z "$(command -v ipconfig)" ] && alias ipconfig='ifconfig'
#' Shorten `sudo iptables` to `ipt`
[ -n "$(command -v iptables)" ] && alias ipt='sudo iptables'
#' List all available network interfaces
[ -d /sys/class/net/ ] && alias lsnet='ls /sys/class/net/ | awk NF'
#' List all currently open ports
[ -n "$(command -v netstat)" ] && alias lsopenports='netstat -a -l -n -p -t -u'
#' Test if the network as access to the Internet
[ -n "$(command -v ping)" ] && alias testnet='ping -c 1 dcjtech.info || ping -c 1 duckduckgo.com'

if [ -x "$(command -v curl)" ]; then
    #' Test the response speed of the specified website
    alias testwebtime="curl -s -w 'Testing Website Response Time: %{url_effective}\\n\\nLookup Time:\\t\\t%{time_namelookup}\\nConnect Time:\\t\\t%{time_connect}\\nPre-transfer Time:\\t%{time_pretransfer}\\nStart-transfer Time:\\t%{time_starttransfer}\\n\\nTotal Time:\\t\\t%{time_total}\\n' -o /dev/null"
    #' Display the web header of the specified website
    alias webheader='curl -I'
fi

if [ -x "$(command -v wget)" ]; then
    #' Download the file at the specified web address
    alias download='wget --no-cache --no-cookies --no-cookies --no-dns-cache --quiet'
fi


# NETWORK FUNTIONS #


#' Return an error if the Internet is unreachable; otherwise, return nothing
chkinternet() {
    httpget DCJTech.info > /dev/null 2>&1 || { httpget DuckDuckGo.com > /dev/null 2>&1 || { printf 'ERROR: No active internet connection\n' >&2; return 1; } }
}


#' Obtain a list of the DNS servers used by this system
getdnsips() {
    if [ -r /etc/resolv.conf ]; then
        grep -i '^nameserver' /etc/resolv.conf | cut -d ' ' -f 2
    else
        printf 'getdnsips: The file "/etc/resolv.conf" does not exist or is not readable!\n' >&2
        return 1
    fi
}


#' Fetch the LAN IP address
getlanip() {
    if [ -n "$(command -v ifconfig)" ]; then
        ifconfig | grep -E -o 'inet (addr:)?([0-9]*\.){3}[0-9]*' | grep -v '127.0.0.1' | cut -d ' ' -f 2
    elif [ -n "$(command -v ip)" ]; then
        ip addr show | grep -E -o 'inet (addr:)?([0-9]*\.){3}[0-9]*' | grep -v '127.0.0.1' | cut -d ' ' -f 2
    else
        printf 'getlanip: Unable to find the IP address of the LAN!' >&2
        return 1
    fi
}


#' Fetch the WAN IP address
getwanip() {
    httpget ipinfo.io/ip  # httpget https://api.ipify.org?format=json | grep -Eo '[0-9.]*'
}


#' Fetch the IP address of the Router
getrouterip() {
    if [ -n "$(command -v netstat)" ]; then
        netstat -r -n | grep '^0.0.0.0' | cut -d ' ' -f 2
    elif [ -n "$(command -v ip)" ]; then
        ip route | grep '^default\svia' | head -1 | cut -d ' ' -f 3
    else
        printf 'getrouterip: Unable to find the IP address of the router!' >&2
        return 1
    fi
}


#' Display a list of the MAC addresses on the system
lsmacs() {
    if [ -n "$(command -v ifconfig)" ]; then
        ifconfig | grep -o -E '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}' | sort
    elif [ -n "$(command -v ip)" ]; then
        ip addr show | grep -o -E '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}' | grep -v '00:00:00:00:00:00' | grep -v 'ff:ff:ff:ff:ff:ff' | sort | uniq
    else
        printf 'lsmacs: Unable to find the MAC addresses of the system!' >&2
        return 1
    fi
}


#' Fetch the the name of the ISP for the WAN
whoismyisp() {
    httpget ipinfo.io/org | cut -d ' ' -f 2-
}


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
downloadbzip() { wget --no-cache --no-cookies --no-dns-cache --quiet -c "$1" -O - | tar -jx; }
#' Download & extract Gzip
downloadgzip() { wget --no-cache --no-cookies --no-dns-cache --quiet -c "$1" -O - | tar -xz; }
#' Download & extract XZ
downloadxz() { wget --no-cache --no-cookies --no-dns-cache --quiet -c "$1" -O - | tar -Jx; }
#' Download & extract Zip
downloadzip() { wget --no-cache --no-cookies --no-dns-cache --quiet -c "$1" -O new.zip && unzip -q -q new.zip && rm new.zip; }


# WEATHER #


#' Display the forecasted weather for the current location
weatherhere() {
    [ -z "${COUNTRY:-}" ] && COUNTRY="$(httpget ipinfo.io/country)" && export COUNTRY
    if [ "$COUNTRY" = 'US' ]; then
        [ -z "${CITY:-}" ] && CITY="$(httpget ipinfo.io/city)" && export CITY
        [ -z "${REGION:-}" ] && REGION="$(httpget ipinfo.io/region)"
        [ "$(echo "$REGION" | wc -w)" == '2' ] && REGION="$(echo "$REGION" | grep -E -o '[A-Z]*' | tr -d '[:space:]')" && export REGION
        [ -z "${locale:-}" ] && locale="$(echo "$LANG" | cut -c 1-2)"
        httpget "${locale:en}.wttr.in/$CITY,$REGION"
    else
        [ -z "${LOCATION:-}" ] && LOCATION="$(httpget ipinfo.io/loc)" && export LOCATION
        httpget "${locale:en}.wttr.in/$LOCATION"
    fi
}


#' Display the forecasted weather for the specified location
#' param[in] $1 Specify the location using format "city,state" or "lat,lon"; Use quotes if the specified location name contains a space character
weatherat() {
    args="$(echo "$@" | tr " " + )"
    httpget "$locale.wttr.in/${args}"
}

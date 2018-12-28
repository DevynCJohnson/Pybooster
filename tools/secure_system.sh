#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Change various system settings to increase the system's security
#' @file secure_system.sh
#' @version 2018.12.28
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# FUNCTIONS #


apply_iptables_rules() {
    # Initial Setup
    iptables -P INPUT DROP
    iptables -P OUTPUT ACCEPT
    iptables -P FORWARD DROP
    iptables -A INPUT -m state --state NEW,ESTABLISHED -j ACCEPT
    # Drop Invalid Packets
    iptables -A INPUT -m state --state INVALID -j DROP
    iptables -A FORWARD -m state --state INVALID -j DROP
    iptables -A OUTPUT -m state --state INVALID -j DROP
    # Drop Fragments
    iptables -A INPUT -f -j DROP
    # Drop Null Packets
    iptables -A INPUT -p tcp --tcp-flags ALL NONE -j DROP
    # Drop ICMP (Ping) Packets
    iptables -A INPUT -p icmp -m icmp --icmp-type 8 -j DROP
    # Do not respond to pings
    iptables -A OUTPUT -p icmp --icmp-type echo-reply -j DROP
    # Drop LAND (Local Area Network Denial) Packets
    iptables -A INPUT -s 127.0.0.0/8 -j DROP
    # Drop Smurf-Attacks
    iptables -A INPUT -p icmp -m icmp --icmp-type address-mask-request -j DROP
    iptables -A INPUT -p icmp -m icmp --icmp-type timestamp-request -j DROP
    iptables -A INPUT -p icmp -m limit --limit 2/second --limit-burst 2 -j ACCEPT
    iptables -A INPUT -p icmp -j DROP
    iptables -A INPUT -p tcp -m tcp --tcp-flags RST RST -m limit --limit 2/second --limit-burst 2 -j ACCEPT
    # Drop Spank DoS Attacks
    iptables -A INPUT -s 0.0.0.0/8 -j DROP
    iptables -A INPUT -d 0.0.0.0/8 -j DROP
    iptables -A INPUT -s 224.0.0.0/4 -j DROP
    iptables -A INPUT -d 224.0.0.0/4 -j DROP
    iptables -A INPUT -s 239.255.255.0/24 -j DROP
    iptables -A INPUT -d 239.255.255.0/24 -j DROP
    iptables -A INPUT -s 240.0.0.0/5 -j DROP
    iptables -A INPUT -d 240.0.0.0/5 -j DROP
    iptables -A INPUT -s 255.255.255.255 -j DROP
    iptables -A INPUT -d 255.255.255.255 -j DROP
    # Drop SYN Flood Packets
    iptables -A INPUT -p tcp -m state --state NEW -m limit --limit 2/second --limit-burst 2 -j ACCEPT
    iptables -A INPUT -p tcp -m state --state NEW -j DROP
    # Drop XMAS Packets (all flags of any protocol are set)
    iptables -A INPUT -p tcp --tcp-flags ALL FIN,PSH,URG -j DROP
    iptables -A INPUT -p tcp --tcp-flags ALL ALL -j DROP
    # Block Packets used by Port-Scans
    iptables -A INPUT -p tcp --tcp-flags ACK,FIN FIN -j DROP
    iptables -A INPUT -p tcp --tcp-flags ACK,PSH PSH -j DROP
    iptables -A INPUT -p tcp --tcp-flags ACK,URG URG -j DROP
    iptables -A INPUT -p tcp --tcp-flags ALL FIN -j DROP
    iptables -A INPUT -p tcp --tcp-flags ALL NONE -j DROP
    iptables -A INPUT -p tcp --tcp-flags ALL SYN,FIN -j DROP
    iptables -A INPUT -p tcp --tcp-flags ALL SYN,RST,ACK,FIN,URG -j DROP
    iptables -A INPUT -p tcp --tcp-flags ALL URG,PSH,FIN -j DROP
    iptables -A INPUT -p tcp --tcp-flags ALL URG,PSH,SYN,FIN -j DROP
    iptables -A INPUT -p tcp --tcp-flags FIN,RST FIN,RST -j DROP
    iptables -A INPUT -p tcp --tcp-flags SYN,ACK,FIN,RST RST -m limit --limit 1/s -j ACCEPT
    iptables -A INPUT -p tcp --tcp-flags SYN,ACK SYN,ACK -m state --state NEW -j DROP
    iptables -A INPUT -p tcp --tcp-flags SYN,FIN SYN,FIN -j DROP
    iptables -A INPUT -p tcp --tcp-flags SYN,RST SYN,RST -j DROP
    # Drop Various Attacks
    iptables -A INPUT -p tcp --tcp-flags FIN,SYN FIN,SYN -j DROP
    iptables -A INPUT -p tcp --tcp-flags FIN,SYN,RST,PSH,ACK,URG FIN -j DROP
    iptables -A INPUT -p tcp --tcp-flags FIN,SYN,RST,PSH,ACK,URG FIN,PSH,URG -j DROP
    iptables -A INPUT -p tcp --tcp-flags FIN,SYN,RST,PSH,ACK,URG FIN,SYN,RST,PSH,ACK,URG -j DROP
    iptables -A INPUT -p tcp --tcp-flags FIN,SYN,RST,PSH,ACK,URG NONE -j DROP
}


# MAIN #


if [ ! "$(id -u)" -eq 0 ]; then
    exec sudo -- "$0"
else
    if [ -x "$(command -v iptables)" ]; then
        apply_iptables_rules
    fi
fi

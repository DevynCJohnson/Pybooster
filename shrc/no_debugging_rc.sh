#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Shell RC script providing environment variables that disable/reduce various debugging and logging activities
#' @file no_debugging_rc.sh
#' @version 2019.03.16
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


if [ ! -f /etc/allow_debugging ] || { [ -n "${HOME:-}" ] && [ ! -f "${HOME:-}/.local/allow_debugging" ]; }; then


    export EGL_LOG_LEVEL=fatal
    export G_DBUS_DEBUG=''
    export G_DEBUG=''
    export G_ENABLE_DIAGNOSTIC=0
    export G_MESSAGES_DEBUG=''
    export GDK_DEBUG=''
    export GST_DEBUG=0
    export GTK_DEBUG=''
    export NO_AT_BRIDGE=1
    export ORC_DEBUG=0


fi

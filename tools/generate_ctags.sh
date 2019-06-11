#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Create the CTags files for use by Geany
#' @file generate_ctags.sh
#' @version 2019.06.10
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>


export TAG_DEST='./geany/tags/'

if [ -n "${CFLAGS:-}" ]; then
    tmp_store_cflags="$CFLAGS"
else
    tmp_store_cflags=''
fi


if [ -d /usr/include/apache2/ ]; then
    export CFLAGS='-I/usr/include/apr-1.0 -I/usr/include/apache2'
    geany --generate-tags "${TAG_DEST}httpd.c.tags" /usr/include/apache2/*.h
fi


if [ -f /usr/include/libxslt/xslt.h ]; then
    export CFLAGS='-I/usr/include/libxml2'
    geany --generate-tags "${TAG_DEST}libxslt.c.tags" /usr/include/libxslt/xslt.h
fi


if [ -f /usr/include/libmongoc-1.0/mongoc.h ]; then
    export CFLAGS='-I/usr/include/libmongoc-1.0 -I/usr/include/libbson-1.0'
    geany --generate-tags "${TAG_DEST}libmongoc.c.tags" /usr/include/libmongoc-1.0/mongoc.h
fi


if [ -d /usr/include/dpdk/ ]; then
    export CFLAGS='-I/usr/include/dpdk'
    geany --generate-tags "${TAG_DEST}dpdk.c.tags" /usr/include/dpdk/*.h
fi


export CFLAGS="${tmp_store_cflags}"


if [ -d /usr/include/clang/ ]; then
    header_files='/usr/include/stdc-predef.h /usr/include/stdint.h /usr/include/inttypes.h /usr/include/limits.h /usr/include/math_constants.h /usr/include/ctype.h /usr/include/unistd.h /usr/include/ulimit.h /usr/include/stdlib.h /usr/include/stdio.h /usr/include/builtin_types.h /usr/include/math.h /usr/include/math_functions.h /usr/include/malloc.h /usr/include/wchar.h /usr/include/wctype.h /usr/include/wordexp.h /usr/include/uchar.h /usr/include/time.h /usr/include/tgmath.h /usr/include/sysexits.h /usr/include/syscall.h /usr/include/string.h /usr/include/complex.h /usr/include/cpio.h /usr/include/dirent.h /usr/include/elf.h /usr/include/endian.h /usr/include/errno.h /usr/include/getopt.h'
    if [ -d /usr/include/clang/8/include/ ]; then
        geany --generate-tags "${TAG_DEST}stdc11.c.tags" /usr/include/clang/8/include/*.h "$header_files"
    elif [ -d /usr/include/clang/7/include/ ]; then
        geany --generate-tags "${TAG_DEST}stdc11.c.tags" /usr/include/clang/7/include/*.h "$header_files"
    elif [ -d /usr/include/clang/6/include/ ]; then
        geany --generate-tags "${TAG_DEST}stdc11.c.tags" /usr/include/clang/6/include/*.h "$header_files"
    else
        geany --generate-tags "${TAG_DEST}stdc11.c.tags" "$header_files"
    fi
fi


[ -d /usr/include/python3.6/ ] && geany --generate-tags "${TAG_DEST}python-3.6.c.tags" /usr/include/python3.6/*.h

[ -f /usr/include/readline/readline.h ] && geany --generate-tags "${TAG_DEST}readline.c.tags" /usr/include/readline/readline.h

[ -d /usr/include/openssl/ ] && geany --no-preprocessing --generate-tags "${TAG_DEST}openssl-1.1.1.c.tags" /usr/include/openssl/*.h

[ -f /usr/include/uuid/uuid.h ] && geany --generate-tags "${TAG_DEST}uuid.c.tags" /usr/include/uuid/uuid.h

[ -f /usr/include/curses.h ] && geany --generate-tags "${TAG_DEST}curses.c.tags" /usr/include/curses.h

[ -f /usr/include/ncurses.h ] && geany --generate-tags "${TAG_DEST}ncurses.c.tags" /usr/include/ncurses.h

[ -d /usr/include/libxml2/ ] && geany --no-preprocessing --generate-tags "${TAG_DEST}libxml-2.c.tags" /usr/include/libxml2/*/*.h

[ -f /usr/include/zlib.h ] && geany --generate-tags "${TAG_DEST}zlib.c.tags" /usr/include/zlib.h

[ -f /usr/include/libudev.h ] && geany --generate-tags "${TAG_DEST}libudev.c.tags" /usr/include/libudev.h

[ -f /usr/include/bzlib.h ] && geany --generate-tags "${TAG_DEST}bzlib.c.tags" /usr/include/bzlib.h

[ -d /usr/include/xcb/xcb.h ] && geany --generate-tags "${TAG_DEST}xcb.c.tags" /usr/include/xcb/xcb.h

[ -f /usr/include/pcap.h ] && geany --generate-tags "${TAG_DEST}pcap.c.tags" /usr/include/pcap.h

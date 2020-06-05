#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Install additional DevHelp manuals
#' @file install_devhelp_docs.sh
#' @version 2020.05.25
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


if [ -z "${1:-}" ]; then
    printf 'ERROR: A parameter specifying the directory containing the Devhelp files is required!\n' >&2
    exit 1
elif [ "$1" = '--help' ] || [ "$1" = 'help' ] || [ "$1" = '-h' ]; then
    printf 'Specify the path to the directory containing the Devhelp files.\n'
    exit 0
fi

DEVHELPDIR="${1:-}"


# FUNCTIONS #


install_devhelp_docs() {
    # BASH
    { [ -d /usr/share/doc/bash/ ] && [ ! -d /usr/share/devhelp/books/bash ] && ln -f -s /usr/share/doc/bash /usr/share/devhelp/books/bash && cp -f --preserve=mode "${DEVHELPDIR}/bash.devhelp2" /usr/share/devhelp/books/bash/; } &
    # Debian
    { [ -d /usr/share/debian-reference/ ] && [ ! -d /usr/share/devhelp/books/debian ] && ln -f -s /usr/share/debian-reference /usr/share/devhelp/books/debian && cp -f --preserve=mode "${DEVHELPDIR}/debian.devhelp2" /usr/share/devhelp/books/debian/; } &
    { [ -d /usr/share/doc/debian-kernel-handbook/kernel-handbook.html/ ] && [ ! -d /usr/share/devhelp/books/debian-kernel ] && ln -f -s /usr/share/doc/debian-kernel-handbook/kernel-handbook.html/ /usr/share/devhelp/books/debian-kernel && cp -f --preserve=mode "${DEVHELPDIR}/debian-kernel.devhelp2" /usr/share/devhelp/books/debian-kernel/; } &
    # DPDK
    { [ -d /usr/share/doc/dpdk/ ] && [ ! -d /usr/share/devhelp/books/dpdk ] && ln -f -s /usr/share/doc/dpdk /usr/share/devhelp/books/dpdk && cp -f --preserve=mode "${DEVHELPDIR}/dpdk.devhelp2" /usr/share/devhelp/books/dpdk/; } &
    # GDB
    { [ -d /usr/share/doc/gdb-doc/html/ ] && [ ! -d /usr/share/devhelp/books/gdb ] && ln -f -s /usr/share/doc/gdb-doc/html /usr/share/devhelp/books/gdb && cp -f --preserve=mode "${DEVHELPDIR}/gdb.devhelp2" /usr/share/devhelp/books/gdb/; } &
    # Clang
    { if [ ! -d /usr/share/devhelp/books/clang ]; then
        if [ -d /usr/share/doc/clang-10-doc/html ]; then
            ln -f -s /usr/share/doc/clang-10-doc/html /usr/share/devhelp/books/clang && cp -f --preserve=mode "${DEVHELPDIR}/clang.devhelp2" /usr/share/devhelp/books/clang/
        elif [ -d /usr/share/doc/clang-9-doc/html ]; then
            ln -f -s /usr/share/doc/clang-9-doc/html /usr/share/devhelp/books/clang && cp -f --preserve=mode "${DEVHELPDIR}/clang.devhelp2" /usr/share/devhelp/books/clang/
        elif [ -d /usr/share/doc/clang-8-doc/html ]; then
            ln -f -s /usr/share/doc/clang-8-doc/html /usr/share/devhelp/books/clang && cp -f --preserve=mode "${DEVHELPDIR}/clang.devhelp2" /usr/share/devhelp/books/clang/
        elif [ -d /usr/share/doc/clang-7-doc/html ]; then
            ln -f -s /usr/share/doc/clang-7-doc/html /usr/share/devhelp/books/clang && cp -f --preserve=mode "${DEVHELPDIR}/clang.devhelp2" /usr/share/devhelp/books/clang/
        elif [ -d /usr/share/doc/clang-6-doc/html ]; then
            ln -f -s /usr/share/doc/clang-6-doc/html /usr/share/devhelp/books/clang && cp -f --preserve=mode "${DEVHELPDIR}/clang.devhelp2" /usr/share/devhelp/books/clang/
        fi
    fi; } &
    # LLVM
    { if [ ! -d /usr/share/devhelp/books/llvm ]; then
        if [ -d /usr/share/doc/llvm-10-doc/html ]; then
            ln -f -s /usr/share/doc/llvm-10-doc/html /usr/share/devhelp/books/llvm && cp -f --preserve=mode "${DEVHELPDIR}/llvm.devhelp2" /usr/share/devhelp/books/llvm/
        elif [ -d /usr/share/doc/llvm-9-doc/html ]; then
            ln -f -s /usr/share/doc/llvm-9-doc/html /usr/share/devhelp/books/llvm && cp -f --preserve=mode "${DEVHELPDIR}/llvm.devhelp2" /usr/share/devhelp/books/llvm/
        elif [ -d /usr/share/doc/llvm-8-doc/html ]; then
            ln -f -s /usr/share/doc/llvm-8-doc/html /usr/share/devhelp/books/llvm && cp -f --preserve=mode "${DEVHELPDIR}/llvm.devhelp2" /usr/share/devhelp/books/llvm/
        elif [ -d /usr/share/doc/llvm-7-doc/html ]; then
            ln -f -s /usr/share/doc/llvm-7-doc/html /usr/share/devhelp/books/llvm && cp -f --preserve=mode "${DEVHELPDIR}/llvm.devhelp2" /usr/share/devhelp/books/llvm/
        elif [ -d /usr/share/doc/llvm-6-doc/html ]; then
            ln -f -s /usr/share/doc/llvm-6-doc/html /usr/share/devhelp/books/llvm && cp -f --preserve=mode "${DEVHELPDIR}/llvm.devhelp2" /usr/share/devhelp/books/llvm/
        fi
    fi; } &
    # GCC
    { if [ ! -d /usr/share/devhelp/books/gcc ]; then
        if [ -d /usr/share/doc/gcc-10-base ]; then
            ln -f -s /usr/share/doc/gcc-10-base /usr/share/devhelp/books/gcc && cp -f --preserve=mode "${DEVHELPDIR}/gcc.devhelp2" /usr/share/devhelp/books/gcc/
        elif [ -d /usr/share/doc/gcc-9-base ]; then
            ln -f -s /usr/share/doc/gcc-9-base /usr/share/devhelp/books/gcc && cp -f --preserve=mode "${DEVHELPDIR}/gcc.devhelp2" /usr/share/devhelp/books/gcc/
        elif [ -d /usr/share/doc/gcc-8-base ]; then
            ln -f -s /usr/share/doc/gcc-8-base /usr/share/devhelp/books/gcc && cp -f --preserve=mode "${DEVHELPDIR}/gcc.devhelp2" /usr/share/devhelp/books/gcc/
        elif [ -d /usr/share/doc/gcc-7-base ]; then
            ln -f -s /usr/share/doc/gcc-7-base /usr/share/devhelp/books/gcc && cp -f --preserve=mode "${DEVHELPDIR}/gcc.devhelp2" /usr/share/devhelp/books/gcc/
        elif [ -d /usr/share/doc/gcc-6-base ]; then
            ln -f -s /usr/share/doc/gcc-6-base /usr/share/devhelp/books/gcc && cp -f --preserve=mode "${DEVHELPDIR}/gcc.devhelp2" /usr/share/devhelp/books/gcc/
        fi
    fi; } &
    # Flask
    { [ ! -d /usr/share/devhelp/books/flask ] && [ -d /usr/share/doc/python-flask-doc/html ] && ln -f -s /usr/share/doc/python-flask-doc/html /usr/share/devhelp/books/flask && cp -f --preserve=mode "${DEVHELPDIR}/flask.devhelp2" /usr/share/devhelp/books/flask/; } &
    # Fontforge
    { [ -d /usr/share/doc/fontforge/ ] && [ ! -d /usr/share/devhelp/books/fontforge ] && ln -f -s /usr/share/doc/fontforge /usr/share/devhelp/books/fontforge && cp -f --preserve=mode "${DEVHELPDIR}/fontforge.devhelp2" /usr/share/devhelp/books/fontforge/; } &
    # libgegl
    { [ -d /usr/share/doc/libgegl/ ] && [ ! -d /usr/share/devhelp/books/libgegl ] && ln -f -s /usr/share/doc/libgegl /usr/share/devhelp/books/libgegl && cp -f --preserve=mode "${DEVHELPDIR}/libgegl.devhelp2" /usr/share/devhelp/books/libgegl/; } &
    # libmpfr
    { [ -d /usr/share/doc/libmpfr-doc/ ] && [ ! -d /usr/share/devhelp/books/libmpfr ] && ln -f -s /usr/share/doc/libmpfr-doc /usr/share/devhelp/books/libmpfr && cp -f --preserve=mode "${DEVHELPDIR}/libmpfr.devhelp2" /usr/share/devhelp/books/libmpfr/; } &
    # mesa-common-dev
    { [ -d /usr/share/doc/mesa-common-dev/ ] && [ ! -d /usr/share/devhelp/books/mesa-common-dev ] && ln -f -s /usr/share/doc/mesa-common-dev /usr/share/devhelp/books/mesa-common-dev && cp -f --preserve=mode "${DEVHELPDIR}/mesa-common-dev.devhelp2" /usr/share/devhelp/books/mesa-common-dev/; } &
    # Numpy
    { [ -d /usr/share/doc/python-numpy-doc/html/ ] && [ ! -d /usr/share/devhelp/books/numpy ] && ln -f -s /usr/share/doc/python-numpy-doc/html/ /usr/share/devhelp/books/numpy && cp -f --preserve=mode "${DEVHELPDIR}/numpy.devhelp2" /usr/share/devhelp/books/numpy/; } &
    # PHP
    { [ -d /usr/share/doc/php/ ] && [ ! -d /usr/share/devhelp/books/php ] && ln -f -s /usr/share/doc/php/ /usr/share/devhelp/books/php && cp -f --preserve=mode "${DEVHELPDIR}/php.devhelp2" /usr/share/devhelp/books/php/; } &
    # SQLAlchemy
    { [ ! -d /usr/share/devhelp/books/sqlalchemy ] && [ -d /usr/share/doc/python-sqlalchemy-doc/html ] && ln -f -s /usr/share/doc/python-sqlalchemy-doc/html /usr/share/devhelp/books/sqlalchemy && cp -f --preserve=mode "${DEVHELPDIR}/sqlalchemy.devhelp2" /usr/share/devhelp/books/sqlalchemy/; } &
    # Werkzeug
    { [ ! -d /usr/share/devhelp/books/werkzeug ] && [ -d /usr/share/doc/python-werkzeug-doc/html ] && ln -f -s /usr/share/doc/python-werkzeug-doc/html /usr/share/devhelp/books/werkzeug && cp -f --preserve=mode "${DEVHELPDIR}/werkzeug.devhelp2" /usr/share/devhelp/books/werkzeug/; } &
    # Xapian
    { [ ! -d /usr/share/devhelp/books/xapian ] && [ -d /usr/share/doc/python3-xapian/html ] && ln -f -s /usr/share/doc/python3-xapian/html /usr/share/devhelp/books/xapian && cp -f --preserve=mode "${DEVHELPDIR}/xapian.devhelp2" /usr/share/devhelp/books/xapian/; } &

    # End
    wait
}


repair_devhelp_docs() {
    # gtkglext
    [ -f /usr/share/gtk-doc/html/gtkglext/gtkglext.devhelp.gz ] && gunzip /usr/share/gtk-doc/html/gtkglext/gtkglext.devhelp.gz && sed -i -e 's| link="index.html" author="" name="gtkglext">| link="index.html" author="" name="gtkglext" language="C" version="2">|;s|<function |<keyword type="function" |;' /usr/share/gtk-doc/html/gtkglext/gtkglext.devhelp && mv /usr/share/gtk-doc/html/gtkglext/gtkglext.devhelp /usr/share/gtk-doc/html/gtkglext/gtkglext.devhelp2 && gzip /usr/share/gtk-doc/html/gtkglext/gtkglext.devhelp2
    # pygobject
    [ -f /usr/share/gtk-doc/html/pygobject/pygobject.devhelp ] && sed -i -e 's| link="index.html" author="" name="gtkglext">| link="index.html" author="" name="gtkglext" version="2">|;s|<function |<keyword type="function" |;' /usr/share/gtk-doc/html/pygobject/pygobject.devhelp && mv /usr/share/gtk-doc/html/pygobject/pygobject.devhelp /usr/share/gtk-doc/html/pygobject/pygobject.devhelp2
    # CPP-Reference
    [ -f /usr/share/devhelp/books/cppreference-doxygen-local.tag.xml ] && cp /usr/share/devhelp/books/cppreference-doxygen-local.tag.xml /usr/share/devhelp/books/cppreference-doc-en-c && cp /usr/share/devhelp/books/cppreference-doxygen-web.tag.xml /usr/share/devhelp/books/cppreference-doc-en-c && mv /usr/share/devhelp/books/cppreference-doxygen-local.tag.xml /usr/share/devhelp/books/cppreference-doc-en-cpp && mv /usr/share/devhelp/books/cppreference-doxygen-web.tag.xml /usr/share/devhelp/books/cppreference-doc-en-cpp
    # Python3.6
    [ -f /usr/share/devhelp/books/python3.6/python3.6.devhelp.gz ] && gunzip /usr/share/devhelp/books/python3.6/python3.6.devhelp.gz && sed -i -e 's|<book title="Python 3.6 Documentation" name="Python 3.6" version="3.6" link="index.html">|<book title="Python 3.6 Documentation" name="Python 3.6" language="Python" version="2" link="index.html">|;s|<function |<keyword type="function" |;' /usr/share/devhelp/books/python3.6/python3.6.devhelp && mv /usr/share/devhelp/books/python3.6/python3.6.devhelp /usr/share/devhelp/books/python3.6/python3.6.devhelp2 && gzip /usr/share/devhelp/books/python3.6/python3.6.devhelp2
    # Python3.7
    [ -f /usr/share/devhelp/books/python3.7/python3.7.devhelp.gz ] && gunzip /usr/share/devhelp/books/python3.7/python3.7.devhelp.gz && sed -i -e 's|<book title="Python 3.7 Documentation" name="Python 3.7" version="3.7" link="index.html">|<book title="Python 3.7 Documentation" name="Python 3.7" language="Python" version="2" link="index.html">|;s|<function |<keyword type="function" |;' /usr/share/devhelp/books/python3.7/python3.7.devhelp && mv /usr/share/devhelp/books/python3.7/python3.7.devhelp /usr/share/devhelp/books/python3.7/python3.7.devhelp2 && gzip /usr/share/devhelp/books/python3.7/python3.7.devhelp2
    # Python3.8
    [ -f /usr/share/devhelp/books/python3.8/python3.8.devhelp.gz ] && gunzip /usr/share/devhelp/books/python3.8/python3.8.devhelp.gz && sed -i -e 's|<book title="Python 3.8 Documentation" name="Python 3.8" version="3.8" link="index.html">|<book title="Python 3.8 Documentation" name="Python 3.8" language="Python" version="2" link="index.html">|;s|<function |<keyword type="function" |;' /usr/share/devhelp/books/python3.8/python3.8.devhelp && mv /usr/share/devhelp/books/python3.8/python3.8.devhelp /usr/share/devhelp/books/python3.8/python3.8.devhelp2 && gzip /usr/share/devhelp/books/python3.8/python3.8.devhelp2
    # Python3.9
    [ -f /usr/share/devhelp/books/python3.9/python3.9.devhelp.gz ] && gunzip /usr/share/devhelp/books/python3.9/python3.9.devhelp.gz && sed -i -e 's|<book title="Python 3.9 Documentation" name="Python 3.9" version="3.9" link="index.html">|<book title="Python 3.9 Documentation" name="Python 3.9" language="Python" version="2" link="index.html">|;s|<function |<keyword type="function" |;' /usr/share/devhelp/books/python3.9/python3.9.devhelp && mv /usr/share/devhelp/books/python3.9/python3.9.devhelp /usr/share/devhelp/books/python3.9/python3.9.devhelp2 && gzip /usr/share/devhelp/books/python3.9/python3.9.devhelp2

    # End
    wait
}


# MAIN #


if [ ! -d /usr/share/doc/ ]; then
    printf 'ERROR: The /usr/share/doc/ directory was not found!\n' >&2
    exit 1
fi

if [ ! "$(id -u)" -eq 0 ]; then
    exec sudo -- "${0} ${1:-}"
else
    install_devhelp_docs
    repair_devhelp_docs
fi

exit 0

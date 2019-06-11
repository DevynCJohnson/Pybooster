#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Create the CTags files for use by Geany
#' @file generate_ctags.sh
#' @version 2019.06.10
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @section NOTES
#'
#' Run `pkg-config --cflags-only-I PKG_NAME` to retrieve the needed CFLAGS


# SETUP


export TAG_DEST='./geany/tags/'

if [ -n "${CFLAGS:-}" ]; then
    tmp_store_cflags="$CFLAGS"
else
    tmp_store_cflags=''
fi


clang_version=
if [ -d /usr/include/clang/8/include/ ]; then
    clang_version='8'
elif [ -d /usr/include/clang/7/include/ ]; then
    clang_version='7'
elif [ -d /usr/include/clang/6/include/ ]; then
    clang_version='6'
fi


# STANDARD C LIBRARY


header_files='/usr/include/stdc-predef.h /usr/include/stdint.h /usr/include/inttypes.h /usr/include/limits.h /usr/include/assert.h /usr/include/math_constants.h /usr/include/ctype.h /usr/include/unistd.h /usr/include/ulimit.h /usr/include/stdlib.h /usr/include/stdio.h /usr/include/builtin_types.h /usr/include/math.h /usr/include/malloc.h /usr/include/wchar.h /usr/include/wctype.h /usr/include/wordexp.h /usr/include/uchar.h /usr/include/time.h /usr/include/tgmath.h /usr/include/sysexits.h /usr/include/syscall.h /usr/include/string.h /usr/include/complex.h /usr/include/cpio.h /usr/include/dirent.h /usr/include/elf.h /usr/include/endian.h /usr/include/errno.h /usr/include/getopt.h /usr/include/libgen.h /usr/include/string.h /usr/include/strings.h /usr/include/syslog.h /usr/include/tar.h /usr/include/monetary.h /usr/include/locale.h /usr/include/aio.h /usr/include/alloca.h'

if [ -n "${clang_version:-}" ]; then
    export CFLAGS='-I/usr/include/clang/${clang_version}/include -D__x86_64__ -D__MMX__'
    geany --generate-tags "${TAG_DEST}std.c.tags" /usr/include/clang/${clang_version}/include/iso646.h /usr/include/clang/${clang_version}/include/float.h /usr/include/clang/${clang_version}/include/stdalign.h /usr/include/clang/${clang_version}/include/stdatomic.h ${header_files}
    export CFLAGS=''
    geany --no-preprocessing --generate-tags "${TAG_DEST}Intel_Intrinsics.c.tags" /usr/include/clang/${clang_version}/include/*intrin.h /usr/include/clang/${clang_version}/include/altivec.h /usr/include/clang/${clang_version}/include/arm64intr.h /usr/include/clang/${clang_version}/include/arm_neon.h /usr/include/clang/${clang_version}/include/cpuid.h /usr/include/clang/${clang_version}/include/mm3dnow.h /usr/include/clang/${clang_version}/include/__wmmintrin_aes.h /usr/include/clang/${clang_version}/include/__wmmintrin_pclmul.h
else
    geany --generate-tags "${TAG_DEST}std.c.tags" ${header_files}
    # TODO: Remove anonymous enums (anon_enum_*), structs (anon_enum_*), and unions (anon_union_*)
fi


# OTHER LIBRARIES


if [ -d /usr/include/apache2/ ]; then
    export CFLAGS='-I/usr/include/apr-1.0 -I/usr/include/apache2'
    geany --generate-tags "${TAG_DEST}httpd.c.tags" /usr/include/apache2/*.h
fi


if [ -f /usr/include/cairo/cairo.h ]; then
    export CFLAGS='-I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16'
    geany --generate-tags "${TAG_DEST}cairo.c.tags" /usr/include/cairo/cairo.h
fi


if [ -d /usr/include/dpdk/ ]; then
    export CFLAGS='-I/usr/include/dpdk'
    geany --generate-tags "${TAG_DEST}dpdk.c.tags" /usr/include/dpdk/*.h
fi


if [ -f /usr/include/fuse.h ]; then
    export CFLAGS='-D_FILE_OFFSET_BITS=64 -I/usr/include/fuse'
    geany --generate-tags "${TAG_DEST}fuse.c.tags" /usr/include/fuse.h
fi


if [ -d /usr/include/geany/ ]; then
    export CFLAGS='-I/usr/include/geany -I/usr/include/geany/tagmanager -I/usr/include/geany/scintilla -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/cairo -I/usr/include/libdrm -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/fribidi -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include'
    geany --generate-tags "${TAG_DEST}geanyplugin.c.tags" /usr/include/geany/geanyplugin.h
fi


if [ -f /usr/include/libgit2-glib-1.0/libgit2-glib/ggit.h ]; then
    export CFLAGS='-I/usr/include/libgit2-glib-1.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include'
    geany --generate-tags "${TAG_DEST}libgit2-glib-1.0.c.tags" /usr/include/libgit2-glib-1.0/libgit2-glib/ggit.h
fi


if [ -f /usr/include/libmongoc-1.0/mongoc.h ]; then
    export CFLAGS='-I/usr/include/libmongoc-1.0 -I/usr/include/libbson-1.0'
    geany --generate-tags "${TAG_DEST}libmongoc.c.tags" /usr/include/libmongoc-1.0/mongoc.h
fi


if [ -f /usr/include/libxslt/xslt.h ]; then
    export CFLAGS='-I/usr/include/libxml2'
    geany --generate-tags "${TAG_DEST}libxslt.c.tags" /usr/include/libxslt/xslt.h
fi


if [ -f /usr/include/webkitgtk-3.0/webkit/webkit.h ]; then
    export CFLAGS='-I/usr/include/webkitgtk-3.0 -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/cairo -I/usr/include/libdrm -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/fribidi -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libsoup-2.4 -I/usr/include/libxml2 -I/usr/include/webkitgtk-3.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include'
    geany --generate-tags "${TAG_DEST}webkit-3.0.c.tags" /usr/include/webkitgtk-3.0/webkit/webkit.h
fi


if [ -d /usr/include/wine-development/wine/ ]; then
    export CFLAGS='-I/usr/include/wine-development/wine -I/usr/include/wine-development/wine/msvcrt -I/usr/include/wine-development/wine/windows'
    geany --no-preprocessing --generate-tags "${TAG_DEST}wine.c.tags" /usr/include/wine-development/wine/*.h /usr/include/wine-development/wine/msvcrt/*.h /usr/include/wine-development/wine/windows/*.h
fi


export CFLAGS="${tmp_store_cflags}"


[ -d /usr/include/libxml2/ ] && geany --no-preprocessing --generate-tags "${TAG_DEST}libxml-2.c.tags" /usr/include/libxml2/*/*.h
[ -d /usr/include/linux/ ] && geany --no-preprocessing --generate-tags "${TAG_DEST}Linux_Kernel.c.tags" /usr/include/linux/*.h
[ -d /usr/include/mpi/ ] && geany --generate-tags "${TAG_DEST}mpi.c.tags" /usr/include/openmpi/cupti_openmpi.h
[ -d /usr/include/openacc/ ] && geany --generate-tags "${TAG_DEST}openacc.c.tags" /usr/include/openacc/cupti_openacc.h
[ -d /usr/include/opencv2/ ] && geany --generate-tags "${TAG_DEST}opencv2.c.tags" /usr/include/opencv2/opencv.hpp
[ -d /usr/include/openssl/ ] && geany --no-preprocessing --generate-tags "${TAG_DEST}openssl-1.1.1.c.tags" /usr/include/openssl/*.h
[ -d /usr/include/python3.6m/ ] && geany --generate-tags "${TAG_DEST}python-3.6.c.tags" /usr/include/python3.6m/*.h
[ -d /usr/include/xcb/xcb.h ] && geany --generate-tags "${TAG_DEST}xcb.c.tags" /usr/include/xcb/xcb.h
[ -f /usr/include/bzlib.h ] && geany --generate-tags "${TAG_DEST}bzlib.c.tags" /usr/include/bzlib.h
[ -f /usr/include/cfortran.h ] && geany --generate-tags "${TAG_DEST}cfortran.c.tags" /usr/include/cfortran.h
[ -f /usr/include/cublas.h ] && geany --generate-tags "${TAG_DEST}cublas.c.tags" /usr/include/cublas.h
[ -f /usr/include/cuda.h ] && geany --generate-tags "${TAG_DEST}cuda-10.c.tags" /usr/include/cuda.h
[ -f /usr/include/cudaEGL.h ] && geany --generate-tags "${TAG_DEST}cudaEGL.c.tags" /usr/include/cudaEGL.h
[ -f /usr/include/cudaGL.h ] && geany --generate-tags "${TAG_DEST}cudaGL.c.tags" /usr/include/cudaGL.h
[ -f /usr/include/cufft.h ] && geany --generate-tags "${TAG_DEST}cufft.c.tags" /usr/include/cufft.h
[ -f /usr/include/curses.h ] && geany --generate-tags "${TAG_DEST}curses.c.tags" /usr/include/curses.h
[ -f /usr/include/fstab.h ] && geany --generate-tags "${TAG_DEST}fstab.c.tags" /usr/include/fstab.h
[ -f /usr/include/gconv.h ] && geany --generate-tags "${TAG_DEST}gconv.c.tags" /usr/include/gconv.h
[ -f /usr/include/gmpxx.h ] && geany --generate-tags "${TAG_DEST}gmpxx.c.tags" /usr/include/gmpxx.h
[ -f /usr/include/hwloc.h ] && geany --generate-tags "${TAG_DEST}hwloc.c.tags" /usr/include/hwloc.h
[ -f /usr/include/libssh2.h ] && geany --generate-tags "${TAG_DEST}libssh2.c.tags" /usr/include/libssh2.h
[ -f /usr/include/libudev.h ] && geany --generate-tags "${TAG_DEST}libudev.c.tags" /usr/include/libudev.h
[ -f /usr/include/lz4.h ] && geany --generate-tags "${TAG_DEST}lz4.c.tags" /usr/include/lz4.h
[ -f /usr/include/ncurses.h ] && geany --generate-tags "${TAG_DEST}ncurses.c.tags" /usr/include/ncurses.h
[ -f /usr/include/pcap.h ] && geany --generate-tags "${TAG_DEST}pcap.c.tags" /usr/include/pcap.h
[ -f /usr/include/pcre.h ] && geany --generate-tags "${TAG_DEST}pcre.c.tags" /usr/include/pcre.h
[ -f /usr/include/pcreposix.h ] && geany --generate-tags "${TAG_DEST}pcreposix.c.tags" /usr/include/pcreposix.h
[ -f /usr/include/readline/readline.h ] && geany --generate-tags "${TAG_DEST}readline.c.tags" /usr/include/readline/readline.h
[ -f /usr/include/uuid/uuid.h ] && geany --generate-tags "${TAG_DEST}uuid.c.tags" /usr/include/uuid/uuid.h
[ -f /usr/include/vulkan/vulkan.h ] && geany --generate-tags "${TAG_DEST}vulkan.c.tags" /usr/include/vulkan/vulkan.h
[ -f /usr/include/wayland-egl.h ] && geany --generate-tags "${TAG_DEST}wayland-egl.c.tags" /usr/include/wayland-egl.h
[ -f /usr/include/wayland-server.h ] && geany --generate-tags "${TAG_DEST}wayland-server.c.tags" /usr/include/wayland-server.h
[ -f /usr/include/wine-development/wine/windows/winddef.h ] && geany --no-preprocessing --generate-tags "${TAG_DEST}winddef.c.tags" /usr/include/wine-development/wine/windows/winddef.h
[ -f /usr/include/wine-development/wine/windows/windows.h ] && geany --no-preprocessing --generate-tags "${TAG_DEST}windows.c.tags" /usr/include/wine-development/wine/windows/windows.h
[ -f /usr/include/x265.h ] && geany --generate-tags "${TAG_DEST}x265.c.tags" /usr/include/x265.h
[ -f /usr/include/xvid.h ] && geany --generate-tags "${TAG_DEST}xvid.c.tags" /usr/include/xvid.h
[ -f /usr/include/zip.h ] && geany --generate-tags "${TAG_DEST}zip.c.tags" /usr/include/zip.h
[ -f /usr/include/zlib.h ] && geany --generate-tags "${TAG_DEST}zlib.c.tags" /usr/include/zlib.h
[ -f /usr/include/zlib.h ] && geany --generate-tags "${TAG_DEST}zlib.c.tags" /usr/include/zlib.h

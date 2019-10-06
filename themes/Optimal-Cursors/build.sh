#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Build script for the Optimal Cursors
#' @file build.sh
#' @version 2019.10.05
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# xfconf-query --channel xsettings --property /Gtk/CursorThemeSize --set 96


trap 'pkill -P $$; kill $$' INT


#' Generate x1-sized cursors
create_x1() {
    find . -name "*.svg" -type f -exec sh -c 'inkscape -z -e "../x1/${0%.svg}.png" -w 32 -h 32 $0 > /dev/null' {} \;
}


#' Generate x1.25-sized cursors
create_x1_25() {
    find . -name "*.svg" -type f -exec sh -c 'inkscape -z -e "../x1_25/${0%.svg}.png" -w 40 -h 40 $0 > /dev/null' {} \;
}


#' Generate x1.5-sized cursors
create_x1_5() {
    find . -name "*.svg" -type f -exec sh -c 'inkscape -z -e "../x1_5/${0%.svg}.png" -w 48 -h 48 $0 > /dev/null' {} \;
}


#' Generate x2-sized cursors
create_x2() {
    find . -name "*.svg" -type f -exec sh -c 'inkscape -z -e "../x2/${0%.svg}.png" -w 64 -h 64 $0 > /dev/null' {} \;
}


#' Generate x3-sized cursors
create_x3() {
    find . -name "*.svg" -type f -exec sh -c 'inkscape -z -e "../x3/${0%.svg}.png" -w 96 -h 96 $0 > /dev/null' {} \;
}


#' Generate x4-sized cursors
create_x4() {
    find . -name "*.svg" -type f -exec sh -c 'inkscape -z -e "../x4/${0%.svg}.png" -w 128 -h 128 $0 > /dev/null' {} \;
}


#' Clean up generated files
clean_up() {
    cd "$source_code" || (printf 'ERROR: Failed to change to the %s directory!\n' "$source_code" >&2; exit 1)
    rm -f -r x1 x1_25 x1_5 x2 x3 x4 || true
    cd .. || (printf 'ERROR: Failed to change one directory up!\n' >&2; exit 1)
    if [ -n "${1:-}" ] && [ "$1" = 'black' ]; then
        [ -d ./Optimal-Cursors ] && rm -f -r ./Optimal-Cursors
    elif [ -n "${1:-}" ] && [ "$1" = 'white' ]; then
        [ -d './Optimal-Cursors-White' ] && rm -f -r './Optimal-Cursors-White'
    elif [ -n "${1:-}" ] && [ "$1" = 'all' ]; then
        [ -d ./Optimal-Cursors ] && rm -f -r ./Optimal-Cursors
        [ -d './Optimal-Cursors-White' ] && rm -f -r './Optimal-Cursors-White'
    fi
}


#' Generate Pixmaps from SVG Files
generate_x11_cursors() {

    # Setup Directories & Pathes

    cd "$source_code" || (printf 'ERROR: Failed to change to the %s directory!\n' "$source_code" >&2; exit 1)
    if [ -n "${1:-}" ] && [ "$1" = 'white' ]; then
        builddir="${source_code}/../Optimal-Cursors-White"
        svgdir='svg-white'
    else
        builddir="${source_code}/../Optimal-Cursors"
        svgdir='svg'
    fi
    output="${builddir}/cursors"
    shortcuts="${source_code}/cursorList"
    [ ! -d "$builddir" ] && mkdir "$builddir"
    if [ -n "${1:-}" ] && [ "$1" = 'white' ]; then
        printf '[Icon Theme]\nName=Optimal-Cursors-White\nInherits=DMZ-White\n' > "${builddir}/index.theme"
    else
        printf '[Icon Theme]\nName=Optimal-Cursors\nInherits=DMZ-Black\n' > "${builddir}/index.theme"
    fi
    [ ! -d "$output" ] && mkdir "$output"
    mkdir -p x1 x1_25 x1_5 x2 x3 x4
    cd "${source_code}/${svgdir}" || (printf 'ERROR: Failed to change to the %s directory!\n' "${source_code}/${svgdir}" >&2; exit 1)

    # Convert SVG Images to PNG

    create_x1 &
    create_x1_25 &
    create_x1_5 &
    create_x2 &
    create_x3 &
    create_x4 &
    wait
    cd "$source_code" || (printf 'ERROR: Failed to change to the %s directory!\n' "$source_code" >&2; exit 1)

    # Generate Cursors

    printf 'Generating Cursor Theme\n'
    for cursor_file in config/*.cursor; do
        BASENAME="${cursor_file##*/}"
        xcursorgen "$cursor_file" "${output}/${BASENAME%.*}"
    done
    printf 'Finished Generating Cursor Theme\n'
    cd "$output" || (printf 'ERROR: Failed to change to the %s directory!\n' "$output" >&2; exit 1)

    # Generate Aliases

    printf 'Generating Shortcuts\n'
    while read -r shortcut; do
        source_file="${shortcut#* }"
        target_file="${shortcut% *}"
        [ -e "$target_file" ] && continue
        ln -r -s "$source_file" "$target_file"
    done < "$shortcuts"
    printf 'Finished Generating Shortcuts\n'
    cd "$PWD" || (printf 'ERROR: Failed to change to the %s directory!\n' "$PWD" >&2; exit 1)
}


# MAIN #


if [ ! -x "$(command -v xcursorgen)" ]; then
    printf 'ERROR: "xcursorgen" is required to run this script!\n' >&2
    exit 1
elif [ ! -x "$(command -v inkscape)" ]; then
    printf 'ERROR: "inkscape" is required to run this script!\n' >&2
    exit 1
fi


source_code="${PWD}/src"


if [ -n "${1:-}" ] && [ "$1" = 'clean' ]; then  # Clean up
    clean_up 'all'
elif [ -n "${1:-}" ] && [ "$1" = 'white' ]; then
    clean_up 'white'
    generate_x11_cursors 'white'
elif [ -n "${1:-}" ] && [ "$1" = 'all' ]; then
    clean_up 'black'
    generate_x11_cursors
    clean_up 'white'
    generate_x11_cursors 'white'
elif [ -n "${1:-}" ] && [ "$1" = 'install' ]; then
    clean_up
    rm -f -r /usr/share/icons/Optimal-Cursors-White /usr/share/icons/Optimal-Cursors
    [ -d ./Optimal-Cursors ] && cp -f --preserve=mode -r ./Optimal-Cursors /usr/share/icons
    [ -d ./Optimal-Cursors-White ] && cp -f --preserve=mode -r ./Optimal-Cursors-White /usr/share/icons
    clean_up 'all'
elif [ -n "${1:-}" ] && [ "$1" = 'uninstall' ]; then
    clean_up
    rm -f -r /usr/share/icons/Optimal-Cursors-White /usr/share/icons/Optimal-Cursors
    clean_up 'all'
else
    clean_up 'all'
    generate_x11_cursors
fi


clean_up

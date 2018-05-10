#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
# @brief Install, test, and manage the US Extended (USX) XKB
# @file manage_usx.sh
# @version 2018.04.27
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# EXECUTE AS ROOT #


readonly SETKEYBOARD="-compat 'usx_compat(full_compat)' -geometry 'usx_geometry(usx_keyboard)' -keycodes 'usx_keycodes(pc105x)' -symbols 'usx(default)' -types 'usx_types(basic_types)' -model pc105x -variant keys -option -layout usx"
if [ ! "$(id -u)" -eq 0 ]; then
    if [ "$*" = 'print' ] || [ "$*" = '--print' ] || [ "$*" = '-p' ]; then
        sh -c "setxkbmap ${SETKEYBOARD} -print | xkbcomp - - | xkbprint -color - - | ps2pdf - > ~/Keyboard_Level_1_2.pdf"
        sh -c "setxkbmap ${SETKEYBOARD} -print | xkbcomp - - | xkbprint -ll 3 -color - - | ps2pdf - > ~/Keyboard_Level_3_4.pdf"
        sh -c "setxkbmap ${SETKEYBOARD} -print | xkbcomp - - | xkbprint -ll 5 -color - - | ps2pdf - > ~/Keyboard_Level_5_6.pdf"
        exit 0
    fi
    exec sudo -- "$0" "$@"
    exit 0
fi


# VARIABLES #


readonly XKBDIR='/usr/share/X11/xkb'
readonly KEYMAP_PATH='/usr/share/X11/xkb/keymaps'
readonly XKBMAPFILE="${KEYMAP_PATH}/usx_keymap.xkbmap"
readonly BASE_FILE="${XKBDIR}/rules/base"
readonly BASE_LST_FILE="${XKBDIR}/rules/base.lst"
readonly BASE_XML_FILE="${XKBDIR}/rules/base.xml"
readonly EVDEV_FILE="${XKBDIR}/rules/evdev"
readonly EVDEV_LST_FILE="${XKBDIR}/rules/evdev.lst"
readonly EVDEV_XML_FILE="${XKBDIR}/rules/evdev.xml"
readonly BASE_TMP='/tmp/base_temp'
readonly BASE_LST_TMP='/tmp/base_temp.lst'
readonly BASE_XML_TMP='/tmp/base_temp.xml'
readonly EVDEV_TMP='/tmp/evdev_temp'
readonly EVDEV_LST_TMP='/tmp/evdev_temp.lst'
readonly EVDEV_XML_TMP='/tmp/evdev_temp.xml'
readonly XKM_CACHE="/var/lib/xkb/*.xkm"
readonly NEW_XKB_PATH='./themes/XKB/'


# FUNCTIONS #


activate_usx() {
    if [ -f "$XKBMAPFILE" ]; then
        if [ -f /etc/default/keyboard ]; then
            awk '{ sub("^[ \t]*XKBLAYOUT[ \t]*=.*$", "XKBLAYOUT=usx"); sub("^[ \t]*XKBVARIANT[ \t]*=.*$", "XKBVARIANT="); sub("^[ \t]*XKBMODEL[ \t]*=.*$", "XKBMODEL=pc105x"); print $0}' /etc/default/keyboard > /tmp/keyboard_etc && mv -f /tmp/keyboard_etc /etc/default/keyboard
            grep -q 'XKBLAYOUT=usx$' /etc/default/keyboard || echo 'XKBLAYOUT=usx' >> /etc/default/keyboard
            grep -q 'XKBVARIANT=$' /etc/default/keyboard || echo 'XKBVARIANT=' >> /etc/default/keyboard
            grep -q 'XKBMODEL=pc105x$' /etc/default/keyboard || echo 'XKBMODEL=pc105x' >> /etc/default/keyboard
        fi
        sh -c "setxkbmap ${SETKEYBOARD} -v 10"
        CleanUp
        [ -f /etc/X11/xinit/xinputrc ] && (grep -Fq "setxkbmap ${SETKEYBOARD}" /etc/X11/xinit/xinputrc || echo "setxkbmap ${SETKEYBOARD}" >> /etc/X11/xinit/xinputrc)
    else
        printf '%s\n' 'It appears that the USX keyboard is not installed.'
    fi
}


CleanUp() {
    tr -s '\t\n' '\t\n' < "$BASE_FILE" > "$BASE_TMP" && mv -f "$BASE_TMP" "$BASE_FILE" && chmod -f 644 "$BASE_FILE"
    tr -s '\t\n' '\t\n' < "$BASE_LST_FILE" > "$BASE_LST_TMP" && mv -f "$BASE_LST_TMP" "$BASE_LST_FILE" && chmod -f 644 "$BASE_LST_FILE"
    tr -s '\n' '\n' < "$BASE_XML_FILE" > "$BASE_XML_TMP" && mv -f "$BASE_XML_TMP" "$BASE_XML_FILE" && chmod -f 644 "$BASE_XML_FILE"
    tr -s '\t\n' '\t\n' < "$EVDEV_FILE" > "$EVDEV_TMP" && mv -f "$EVDEV_TMP" "$EVDEV_FILE" && chmod -f 644 "$EVDEV_FILE"
    tr -s '\t\n' '\t\n' < "$EVDEV_LST_FILE" > "$EVDEV_LST_TMP" && mv -f "$EVDEV_LST_TMP" "$EVDEV_LST_FILE" && chmod -f 644 "$EVDEV_LST_FILE"
    tr -s '\n' '\n' < "$EVDEV_XML_FILE" > "$EVDEV_XML_TMP" && mv -f "$EVDEV_XML_TMP" "$EVDEV_XML_FILE" && chmod -f 644 "$EVDEV_XML_FILE"
    [ -f "${NEW_XKB_PATH}stdin.xkm" ] && rm -f "${NEW_XKB_PATH}stdin.xkm"
    [ -f ./stdin.xkm ] && rm -f ./stdin.xkm
}


debug_keyboard() {
    if [ -f "$XKBMAPFILE" ]; then
        if [ -x "$(command -v setxkbmap)" ] && [ -x "$(command -v xkbcomp)" ]; then
            sh -c "setxkbmap ${SETKEYBOARD} -print | xkbcomp -w 10 -"
            [ -f "${NEW_XKB_PATH}stdin.xkm" ] && rm -f "${NEW_XKB_PATH}stdin.xkm"
            [ -f ./stdin.xkm ] && rm -f ./stdin.xkm
        else
            printf '%s\n' 'Debugging requires setxkbmap and xkbcomp to be installed.'
        fi
    else
        printf '%s\n' 'It appears that the USX keyboard is not installed.'
    fi
}


rm_xkm_cache() {
    [ -f "$XKM_CACHE" ] && rm -f "$XKM_CACHE"
    [ -x "$(command -v dpkg-reconfigure)" ] && dpkg-reconfigure xkb-data
}


Install_usx() {
    # Add USX XKB Files
    [ -d "$XKBDIR" ] && [ ! -d "$KEYMAP_PATH" ] && mkdir -m 755 "$KEYMAP_PATH"
    [ -d "${XKBDIR}/compat" ] && cp -f "${NEW_XKB_PATH}usx_compat" "${XKBDIR}/compat/usx_compat" && chmod -f 644 "${XKBDIR}/compat/usx_compat"
    [ -d "${XKBDIR}/geometry" ] && cp -f "${NEW_XKB_PATH}usx_geometry" "${XKBDIR}/geometry/usx_geometry" && chmod -f 644 "${XKBDIR}/geometry/usx_geometry"
    [ -d "${XKBDIR}/keycodes" ] && cp -f "${NEW_XKB_PATH}usx_keycodes" "${XKBDIR}/keycodes/usx_keycodes" && chmod -f 644 "${XKBDIR}/keycodes/usx_keycodes"
    [ -d "$KEYMAP_PATH" ] && cp -f "${NEW_XKB_PATH}/usx_keymap.xkbmap" "${KEYMAP_PATH}/usx_keymap.xkbmap" && chmod -f 644 "${KEYMAP_PATH}/usx_keymap.xkbmap"
    [ -d "${XKBDIR}/symbols" ] && cp -f "${NEW_XKB_PATH}usx" "${XKBDIR}/symbols/usx" && chmod -f 644 "${XKBDIR}/symbols/usx"
    [ -d "${XKBDIR}/types" ] && cp -f "${NEW_XKB_PATH}usx_types" "${XKBDIR}/types/usx_types" && chmod -f 644 "${XKBDIR}/types/usx_types"
    # Modifiy base
    [ -f "$BASE_FILE" ] && (grep -q 'pc105x[ \t]*=[ \t]*usx_geometry(usx_keyboard)' "$BASE_FILE" || (awk '{ sub("![ \t]*model[ \t]*=[ \t]*geometry[ \t]*", "! model = geometry\n  pc105x = usx_geometry(usx_keyboard)\n"); print $0}' "$BASE_FILE" | tr -s '\t\n' '\t\n' > "$BASE_TMP" && mv -f "$BASE_TMP" "$BASE_FILE"))
    # Modifiy base.lst
    [ -f "$BASE_LST_FILE" ] && (grep -q 'usx[ \t]*English[ \t]*(Extended)' "$BASE_LST_FILE" || (sed 's/! layout/! layout\n  usx    English (Extended)\n/' "$BASE_LST_FILE" > "$BASE_LST_TMP" && mv -f "$BASE_LST_TMP" "$BASE_LST_FILE"))
    [ -f "$BASE_LST_FILE" ] && (grep -q 'pc105x[ \t]*Generic[ \t]*105-key[ \t]*PC (Extended)' "$BASE_LST_FILE" || (sed 's/! model/! model\n  pc105x    Generic 105-key PC (Extended)\n/' "$BASE_LST_FILE" > "$BASE_LST_TMP" && mv -f "$BASE_LST_TMP" "$BASE_LST_FILE"))
    # Modifiy base.xml
    [ -f "$BASE_XML_FILE" ] && (grep -Fq '<name>usx</name>' "$BASE_XML_FILE" || (sed 's/<\/layoutList>/<layout><configItem><name>usx<\/name><shortDescription>en<\/shortDescription><description>English (Extended)<\/description><languageList><iso639Id>eng<\/iso639Id><\/languageList><\/configItem><variantList\/><\/layout>\n<\/layoutList>/' "$BASE_XML_FILE" > "$BASE_XML_TMP" && mv -f "$BASE_XML_TMP" "$BASE_XML_FILE"))
    [ -f "$BASE_XML_FILE" ] && (grep -Fq '<name>pc105x</name>' "$BASE_XML_FILE" || (sed 's/<\/modelList>/<model><configItem><name>pc105x<\/name><description>Generic 105-key PC (Extended)<\/description><vendor>Generic<\/vendor><\/configItem><\/model>\n<\/modelList>/' "$BASE_XML_FILE" > "$BASE_XML_TMP" && mv -f "$BASE_XML_TMP" "$BASE_XML_FILE"))
    # Modifiy evdev.lst
    [ -f "$EVDEV_LST_FILE" ] && (grep -q 'usx[ \t]*English[ \t]*(Extended)' "$EVDEV_LST_FILE" || (sed 's/! layout/! layout\n  usx    English (Extended)\n/' "$EVDEV_LST_FILE" > "$EVDEV_LST_TMP" && mv -f "$EVDEV_LST_TMP" "$EVDEV_LST_FILE"))
    [ -f "$EVDEV_LST_FILE" ] && (grep -q 'pc105x[ \t]*Generic[ \t]*105-key[ \t]*PC[ \t]*(Extended)' "$EVDEV_LST_FILE" || (sed 's/! model/! model\n  pc105x    Generic 105-key PC (Extended)\n/' "$EVDEV_LST_FILE" > "$EVDEV_LST_TMP" && mv -f "$EVDEV_LST_TMP" "$EVDEV_LST_FILE"))
    # Modifiy evdev.xml
    [ -f "$EVDEV_XML_FILE" ] && (grep -Fq '<name>usx</name>' "$EVDEV_XML_FILE" || (sed 's/<\/layoutList>/<layout><configItem><name>usx<\/name><shortDescription>en<\/shortDescription><description>English (Extended)<\/description><languageList><iso639Id>eng<\/iso639Id><\/languageList><\/configItem><variantList\/><\/layout>\n<\/layoutList>/' "$EVDEV_XML_FILE" > "$EVDEV_XML_TMP" && mv -f "$EVDEV_XML_TMP" "$EVDEV_XML_FILE"))
    [ -f "$EVDEV_XML_FILE" ] && (grep -Fq '<name>pc105x</name>' "$EVDEV_XML_FILE" || (sed 's/<\/modelList>/<model><configItem><name>pc105x<\/name><description>Generic 105-key PC (Extended)<\/description><vendor>Generic<\/vendor><\/configItem><\/model>\n<\/modelList>/' "$EVDEV_XML_FILE" > "$EVDEV_XML_TMP" && mv -f "$EVDEV_XML_TMP" "$EVDEV_XML_FILE"))
    # Modifiy evdev
    [ -f "$EVDEV_FILE" ] && (grep -q 'pc105x[ \t]*=[ \t]*usx_geometry(usx_keyboard)' "$EVDEV_FILE" || (awk '{ sub("![ \t]*model[ \t]*=[ \t]*geometry[ \t]*", "! model = geometry\n  pc105x = usx_geometry(usx_keyboard)\n"); print $0}' "$EVDEV_FILE" > "$EVDEV_TMP" && mv -f "$EVDEV_TMP" "$EVDEV_FILE"))
    CleanUp
    # Remove XKB Cache
    rm_xkm_cache
    # Compile Keymap
    if [ -x "$(command -v xkbcomp)" ]; then
        xkbcomp "${KEYMAP_PATH}/usx_keymap.xkbmap" "${KEYMAP_PATH}/usx_keymap.xkm"
    else
        printf '%s\n' 'Compiling keymaps requires xkbcomp.'
    fi
}


Uninstall_usx() {
    # Revert System XInputRC
    [ -f /etc/X11/xinit/xinputrc ] && grep -Fq "setxkbmap ${SETKEYBOARD}" /etc/X11/xinit/xinputrc && sed "/setxkbmap ${SETKEYBOARD}/d" /etc/X11/xinit/xinputrc > /tmp/xinputrc_temp && mv -f /tmp/xinputrc_temp /etc/X11/xinit/xinputrc
    # Remove USX XKB Files
    [ -f "${XKBDIR}/compat/usx_compat" ] && rm -f "${XKBDIR}/compat/usx_compat"
    [ -f "${XKBDIR}/geometry/usx_geometry" ] && rm -f "${XKBDIR}/geometry/usx_geometry"
    [ -f "${XKBDIR}/keycodes/usx_keycodes" ] && rm -f "${XKBDIR}/keycodes/usx_keycodes"
    [ -f "${KEYMAP_PATH}/usx_keymap.xkbmap" ] && rm -f "${KEYMAP_PATH}/usx_keymap.xkbmap"
    [ -f "${KEYMAP_PATH}/usx_keymap.xkm" ] && rm -f "${KEYMAP_PATH}/usx_keymap.xkm"
    [ -f "${XKBDIR}/symbols/usx" ] && rm -f "${XKBDIR}/symbols/usx"
    [ -f "${XKBDIR}/types/usx_types" ] && rm -f "${XKBDIR}/types/usx_types"
    # Revert base
    [ -f "$BASE_FILE" ] && grep -q 'pc105x\|usx' "$BASE_FILE" && sed '/[ tab]*pc105x[ tab]*=[ tab]*usx_geometry(usx_keyboard)[ tab]*/d; s/   / /g' "$BASE_FILE" > "$BASE_TMP" && mv -f "$BASE_TMP" "$BASE_FILE"
    # Revert base.lst
    [ -f "$BASE_LST_FILE" ] && grep -q 'usx[ \t]*English[ \t]*(Extended)' "$BASE_LST_FILE" && sed '/[ tab]*usx[ tab]*English[ tab]*(Extended)[ tab]*/d' "$BASE_LST_FILE" > "$BASE_LST_TMP" && mv -f "$BASE_LST_TMP" "$BASE_LST_FILE"
    [ -f "$BASE_LST_FILE" ] && grep -q 'pc105x[ \t]*Generic[ \t]*105-key[ \t]*PC[ \t]*(Extended)' "$BASE_LST_FILE" && sed '/[ tab]*pc105x[ tab]*Generic[ tab]*105-key[ tab]*PC[ tab]*(Extended)[ tab]*/d' "$BASE_LST_FILE" > "$BASE_LST_TMP" && mv -f "$BASE_LST_TMP" "$BASE_LST_FILE"
    # Revert base.xml
    [ -f "$BASE_XML_FILE" ] && grep -Fq '<name>usx</name>' "$BASE_XML_FILE" && sed '/[ tab]*<layout>[ tab]*<configItem>[ tab]*<name>usx<\/name>[ tab]*<shortDescription>en<\/shortDescription>[ tab]*<description>English (Extended)<\/description>[ tab]*<languageList>[ tab]*<iso639Id>eng<\/iso639Id>[ tab]*<\/languageList>[ tab]*<\/configItem>[ tab]*<variantList\/>[ tab]*<\/layout>/d' "$BASE_XML_FILE" > "$BASE_XML_TMP" && mv -f "$BASE_XML_TMP" "$BASE_XML_FILE"
    [ -f "$BASE_XML_FILE" ] && grep -Fq '<name>pc105x</name>' "$BASE_XML_FILE" && sed '/[ tab]*<model>[ tab]*<configItem>[ tab]*<name>pc105x<\/name>[ tab]*<description>Generic[ tab]*105-key[ tab]*PC[ tab]*(Extended)<\/description>[ tab]*<vendor>Generic<\/vendor>[ tab]*<\/configItem>[ tab]*<\/model>/d' "$BASE_XML_FILE" > "$BASE_XML_TMP" && mv -f "$BASE_XML_TMP" "$BASE_XML_FILE"
    # Revert evdev
    [ -f "$EVDEV_FILE" ] && grep -q 'pc105x\|usx' "$EVDEV_FILE" && sed '/[ tab]*pc105x[ tab]*=[ tab]*usx_geometry(usx_keyboard)[ tab]*/d; s/   / /g' "$EVDEV_FILE" > "$EVDEV_TMP" && mv -f "$EVDEV_TMP" "$EVDEV_FILE"
    # Revert evdev.lst
    [ -f "$EVDEV_LST_FILE" ] && grep -q 'usx[ \t]*English[ \t]*(Extended)' "$EVDEV_LST_FILE" && sed '/[ tab]*usx[ tab]*English[ tab]*(Extended)[ tab]*/d' "$EVDEV_LST_FILE" > "$EVDEV_LST_TMP" && mv -f "$EVDEV_LST_TMP" "$EVDEV_LST_FILE"
    [ -f "$EVDEV_LST_FILE" ] && grep -q 'pc105x[ \t]*Generic[ \t]*105-key[ \t]*PC[ \t]*(Extended)' "$EVDEV_LST_FILE" && sed '/[ tab]*pc105x[ tab]*Generic[ tab]*105-key[ tab]*PC[ tab]*(Extended)[ tab]*/d' "$EVDEV_LST_FILE" > "$EVDEV_LST_TMP" && mv -f "$EVDEV_LST_TMP" "$EVDEV_LST_FILE"
    # Revert evdev.xml
    [ -f "$EVDEV_XML_FILE" ] && grep -Fq '<name>usx</name>' "$EVDEV_XML_FILE" && sed '/[ tab]*<layout>[ tab]*<configItem>[ tab]*<name>usx<\/name>[ tab]*<shortDescription>en<\/shortDescription>[ tab]*<description>English (Extended)<\/description>[ tab]*<languageList>[ tab]*<iso639Id>eng<\/iso639Id>[ tab]*<\/languageList>[ tab]*<\/configItem>[ tab]*<variantList\/>[ tab]*<\/layout>/d' "$EVDEV_XML_FILE" > "$EVDEV_XML_TMP" && mv -f "$EVDEV_XML_TMP" "$EVDEV_XML_FILE"
    [ -f "$EVDEV_XML_FILE" ] && grep -Fq '<name>pc105x</name>' "$EVDEV_XML_FILE" && sed '/[ tab]*<model>[ tab]*<configItem>[ tab]*<name>pc105x<\/name>[ tab]*<description>Generic[ tab]*105-key[ tab]*PC[ tab]*(Extended)<\/description>[ tab]*<vendor>Generic<\/vendor>[ tab]*<\/configItem>[ tab]*<\/model>/d' "$EVDEV_XML_FILE" > "$EVDEV_XML_TMP" && mv -f "$EVDEV_XML_TMP" "$EVDEV_XML_FILE"
    # Clean Up Files
    CleanUp
    # Remove XKB Cache
    rm_xkm_cache
}


# GETOPT #


GOPT="$(getopt -o AaCcDdFfHhIiPpUu --long activate,cache,debug,fix,help,install,print,test,uninstall -- "$@")"
eval set -- "$GOPT"

while true; do
    case "$1" in
        -h|-H|--help)  # Display help info
            printf '%s\n' '=====  Install USX X11 Keyboard  ====='
            printf '%s\n' 'Usage: ./manage_usx.sh [-i|-u]'
            printf '%s\n' 'Options:'
            printf '%s\n' '-h,--help               Display help info'
            printf '%s\n' '-a,--activate           Activate USX Keyboard'
            printf '%s\n' '-c,--cache              Clear XKB cache'
            printf '%s\n' '-d,--debug              Debug USX Keyboard'
            printf '%s\n' '-f,--fix                Set the keyboard bacx to US'
            printf '%s\n' '-i,--install            Install the USX XKB Layout'
            printf '%s\n' '-p,--print              Print the USX XKB Layout as a PDF'
            printf '%s\n' '-u,--uninstall          Uninstall the USX XKB Layout'
            exit 0
        ;;
        -a|-A|--activate)  # Activate USX Keyboard
            activate_usx
            exit 0
        ;;
        -c|-C|--cache)  # Clear XKB Cache
            rm_xkm_cache
            exit 0
        ;;
        -d|-D|--debug|--test)  # Debug USX Keyboard
            debug_keyboard
            exit 0
        ;;
        -f|-F|--fix)  # Fix Keyboard
            setxkbmap -symbols 'pc+us+us:2+inet(evdev)+level3(ralt_switch)+compose(rctrl)' -types 'complete' -compat 'complete' -model pc105 -v 10
            exit 0
        ;;
        -i|-I|--install)  # Install
            Install_usx
            exit 0
        ;;
        -p|-P|--print)  # Print
            if [ -f "$XKBMAPFILE" ]; then
                sh -c "setxkbmap ${SETKEYBOARD} -print | xkbcomp - - | xkbprint -color - - | ps2pdf - > ~/Keyboard_Level_1_2.pdf"
                sh -c "setxkbmap ${SETKEYBOARD} -print | xkbcomp - - | xkbprint -ll 3 -color - - | ps2pdf - > ~/Keyboard_Level_3_4.pdf"
                sh -c "setxkbmap ${SETKEYBOARD} -print | xkbcomp - - | xkbprint -ll 5 -color - - | ps2pdf - > ~/Keyboard_Level_5_6.pdf"
                [ -f "${NEW_XKB_PATH}stdin.xkm" ] && rm -f "${NEW_XKB_PATH}stdin.xkm"
                [ -f ./stdin.xkm ] && rm -f ./stdin.xkm
                exit 0
            else
                printf 'It appears that the USX keyboard is not installed.\n'
            fi
        ;;
        -u|-U|--uninstall)  # Uninstall
            Uninstall_usx
            exit 0
        ;;
        --)  # End
            shift
            break
        ;;
        *)  # Unknown/non-registered parameter
            printf 'Unknown parameter!\nUsage: ./manage_usx.sh [-i|-u]\n' >&2
            exit 1
        ;;
    esac
done


exit 0

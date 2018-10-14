#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Shell RC script providing miscellaneous aliases and functions
#' @file extras_rc.sh
#' @version 2018.10.02
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# ALIASES #


# Compression Utility Aliases

[ -x "$(command -v 7z)" ] && [ ! -x "$(command -v un7z)" ] && alias un7z='7z e'
[ -x "$(command -v bunzip2)" ] && [ ! -x "$(command -v unbzip2)" ] && alias unbzip2='bunzip2'
[ -x "$(command -v gunzip)" ] && [ ! -x "$(command -v ungzip)" ] && alias ungzip='gunzip'
[ -x "$(command -v lzop)" ] && [ ! -x "$(command -v unlzop)" ] && alias unlzop='lzop -d'
[ -x "$(command -v msexpand)" ] && [ ! -x "$(command -v unmscompress)" ] && alias unmscompress='msexpand'
[ -x "$(command -v p7zip)" ] && [ ! -x "$(command -v unp7zip)" ] && alias unp7zip='p7zip --decompress'
[ -x "$(command -v runzip)" ] && [ ! -x "$(command -v unrzip)" ] && alias unrzip='runzip'
[ -x "$(command -v tar)" ] && [ ! -x "$(command -v untar)" ] && alias untar='tar --extract -f' && alias untgz='tar -xzf'

# Filesystem Maneuvering Aliases

alias ..='cd ..'
alias ...='cd ../..'
alias ....='cd ../../..'
alias .....='cd ../../../..'
alias .3='cd ../../..'
alias .4='cd ../../../..'
alias back='cd -'
alias cd..='cd ..'
alias dirs='ls -d */'
alias ff.='find . -type f -name'
alias ff='find / -type f -name'
alias gotoetc='cd /etc'
alias gohome='cd ${HOME}'
alias gotologs='cd /var/log'
alias l.='ls -d .*'
alias l='ls -C -F'
alias la='ls -A'
alias lb='ls -a -B -i -l'
alias ll='ls -a -l -F'
alias lr='ls -a -l -F -R'
alias lsl='if [ -x "$(command -v less)" ]; then ls -A -F -h -l | less; else ls -A -F -h -l | more; fi'
alias lsz='ls -a -l -F -S -W'
alias ltm='ls -a -l -F -t'

# File Manipulation Aliases

[ -z "$(command -v cptree)" ] && alias cptree='cp -R'
[ -z "$(command -v cpdir)" ] && alias cpdir='cp -R'
[ -z "$(command -v del)" ] && alias del='rm'
[ -z "$(command -v hardlink)" ] && alias hardlink='ln'
if [ -n "$(command -v chattr)" ]; then
    alias mkimmutable='chattr +i'
    alias mkmutable='chattr -i'
fi
[ -z "$(command -v rmtree)" ] && alias rmtree='rm -f -r'
[ -z "$(command -v shred)" ] && alias bleach='shred -f -u' && alias rrm='shred -f -u'
[ -z "$(command -v softlink)" ] && alias softlink='ln -s'
[ -z "$(command -v softln)" ] && alias softln='ln -s'
[ -z "$(command -v trash)" ] && alias trash='mv -f -t "${HOME}/.local/share/Trash"'

# Kernel Module Management Aliases

if [ -x "$(command -v modprobe)" ] && [ -d "/lib/modules/${KRELEASE}" ]; then
    [ -d "/lib/modules/${KRELEASE}/kernel/fs" ] && alias lsavalfsmods='ls "/lib/modules/${KRELEASE}/kernel/fs"'
    [ -d "/lib/modules/${KRELEASE}/updates/dkms" ] && alias loadvboxmods='sudo modprobe --all "/lib/modules/${KRELEASE}/updates/dkms/vbox"*'
    [ -d "/lib/modules/${KRELEASE}/updates/dkms" ] && alias unloadvboxmods='sudo modprobe -r --all "/lib/modules/${KRELEASE}/updates/dkms/vbox"*'
    [ -d "/lib/modules/${KRELEASE}/kernel/fs/reiserfs" ] && alias loadreiserfs='sudo modprobe reiserfs'
    [ -d "/lib/modules/${KRELEASE}/kernel/fs/reiserfs" ] && alias unloadreiserfs='sudo modprobe -r reiserfs'
    [ -d "/lib/modules/${KRELEASE}/kernel/fs/xfs" ] && alias loadxfs='sudo modprobe xfs'
    [ -d "/lib/modules/${KRELEASE}/kernel/fs/xfs" ] && alias unloadxfs='sudo modprobe -r xfs'
    [ -d "/lib/modules/${KRELEASE}/kernel/drivers/wacom" ] && alias loadwacom='sudo modprobe wacom'
    [ -d "/lib/modules/${KRELEASE}/kernel/drivers/wacom" ] && alias unloadwacom='sudo modprobe -r wacom'
fi

# Network Aliases

[ -x "$(command -v ping)" ] && alias testnet='ping -c 1 dcjtech.info || ping -c 1 duckduckgo.com'
if [ -x "$(command -v curl)" ]; then
    alias testwebtime="curl -s -w 'Testing Website Response Time: %{url_effective}\n\nLookup Time:\t\t%{time_namelookup}\nConnect Time:\t\t%{time_connect}\nPre-transfer Time:\t%{time_pretransfer}\nStart-transfer Time:\t%{time_starttransfer}\n\nTotal Time:\t\t%{time_total}\n' -o /dev/null http://www.google.com"
    alias webheaders='curl -I'
elif [ -x "$(command -v wget)" ]; then
    alias download='wget --quiet --no-dns-cache --no-cache --no-cookies --no-cookies'
fi
[ -n "$(command -v ifconfig)" ] && [ -z "$(command -v ipconfig)" ] && alias ipconfig='ifconfig'
[ -x "$(command -v iptables)" ] && alias ipt='sudo iptables'
if [ -x "$(command -v nmcli)" ]; then
    alias netOff='nmcli networking off'
    alias netOn='nmcli networking on'
    alias radioOff='nmcli radio all off'
    alias radioOn='nmcli radio all on'
    alias wifiOff='nmcli radio wifi off'
    alias wifiOn='nmcli radio wifi on'
    alias wwanOff='nmcli radio wwan off'
    alias wwanOn='nmcli radio wwan on'
    alias wifiScan='nmcli dev wifi'
fi
[ -x "$(command -v netstat)" ] && alias viewopenports='netstat -a -l -n -p -t -u'

# Settings Manipulation Aliases

if [ -x "$(command -v dconf)" ]; then
    alias backupdconf='dconf dump / > "${HOME}/gsettings.dump"'
    alias restoredconf='dconf load <'
fi
if [ -x "$(command -v gsettings)" ]; then
    alias backupgset='gsettings list-recursively > "${HOME}/gsettings.lst"'
    # Recognised values of XDG_CURRENT_DESKTOP: gnome, kde, xfce, lxde, & mate
    if ([ -n "${XDG_SESSION_DESKTOP:-}" ] && [ "$XDG_SESSION_DESKTOP" = 'mate' ]) || ([ -n "${XDG_CURRENT_DESKTOP:-}" ] && [ "$XDG_CURRENT_DESKTOP" = 'MATE' ]); then
        alias setgtktheme='gsettings set org.mate.desktop.interface gtk-theme'
    elif ([ -n "${XDG_SESSION_DESKTOP:-}" ] && [ "$XDG_SESSION_DESKTOP" = 'gnome' ]) || ([ -n "${XDG_CURRENT_DESKTOP:-}" ] && [ "$XDG_CURRENT_DESKTOP" = 'GNOME' ]); then
        alias setgtktheme='gsettings set org.gnome.desktop.interface gtk-theme'
    elif ([ -n "${XDG_CURRENT_DESKTOP:-}" ] && [ "$XDG_CURRENT_DESKTOP" = 'XFCE' ]); then
        alias setgtktheme='xfconf-query -c xsettings -p /Net/ThemeName -s'
    fi
fi

# String Manipulation Aliases

#' Convert string to lowercase
alias lowercase="tr '[:upper:]' '[:lower:]'"
#' Recursively search the specified/current directory for the specified string
alias rfind='grep -r -F'
#' Remove the first X columns
alias rm1stxcols='cut -d " " -f'
#' Convert string to uppercase
alias uppercase="tr '[:lower:]' '[:upper:]'"

# String Search Aliases

#' Find files that begin with a Python hashpling
alias findpypling='grep -F "#!/usr/bin/env python" ./*'
alias findr='grep -I -i -n -q -r -s --mmap .*'
alias findrx='grep -E -I -n -q -r -s --mmap .*'

# System Control Aliases

[ -x "$(command -v fstrim)" ] && alias cleanssd='sudo fstrim -a -v'  #' Clean unused blocks on SSD drives
if [ "$(id -u)" -eq 0 ] && [ -f /proc/sys/vm/drop_caches ]; then
    alias freepagecache='echo 1 > /proc/sys/vm/drop_caches'
    alias freeinodes='echo 2 > /proc/sys/vm/drop_caches'
    alias freeramcache='echo 3 > /proc/sys/vm/drop_caches'
fi
[ -x "$(command -v swapon)" ] && alias freeswap='sudo swapoff -a && sleep 2 && sudo swapon -a'
alias killjobs='kill "$(jobs -ps)" 2> /dev/null'
[ -x "$(command -v systemctl)" ] && alias lsenabledservices='systemctl list-unit-files | grep -F "enabled"'
[ -x "$(command -v free)" ] && alias meminfo='free -m -l -t'
[ -x "$(command -v xset)" ] && alias monitoroff='xset dpms force off'
alias powerdown='sudo shutdown -h now'
alias poweroff='sudo shutdown -h now'
alias reboot='history -c; sudo shutdown -r now'
alias resudo='sudo -v'
alias sedo='sudo -E'
alias unmount='sudo umount'
alias viewmount='mount | column -t'

# Terminal Control Aliases

alias CLEAR='clear'
alias clr='clear'
alias CLR='clear'
#' @alias clsh Clear the terminal and history prior to exiting
if [ "$PROFILE_SHELL" = 'bash' ]; then
    alias clsh='clear; history -c; echo "" > ${HOME}/.bash_history; exit'
elif [ "$PROFILE_SHELL" = 'fish' ]; then
    alias clsh='clear; history -c; echo "" > ${HOME}/.local/share/fish/fish_history; exit'
elif [ "$PROFILE_SHELL" = 'zsh' ]; then
    alias clsh='clear; history -c; echo "" > ${HOME}/.zsh_history; exit'
elif [ -w "${HOME}/.sh_history" ]; then
    alias clsh='clear; history -c; echo "" > ${HOME}/.sh_history; exit'
else
    alias clsh='clear; history -c; exit'
fi
alias findalias='alias | grep -i -F'
alias findfunc='set | grep -i -F'
alias lsfuncs='set | grep -F "()"'
alias viewpath='echo "$PATH"'

# Miscellaneous Aliases

if [ -x "$(command -v notify-send)" ]; then
    alias alert='notify-send --urgency=low -i "Alert"'
else
    alias alert='printf "Alert\n"'
fi
alias ConsoleMessage='echo'
[ -x "$(command -v du)" ] && [ -x "$(command -v less)" ] && alias du.='du -a -c -h | sort -h | less'  #' Show the disk usage of each directory
[ -x "$(command -v df)" ] && [ -x "$(command -v less)" ] && alias df.='df -a -h -T | less'  #' Show disk usage for each filesystem
alias mkae='make'
[ -x "$(command -v compiz)" ] && alias rgui='pidof compiz && killall -SIGHUP compiz'  #' Restart Compiz (fixes memory leak)
alias rless='less -r'
alias lessn='less -N'
alias today="date +%m/%d/%y"

if [ -d /etc/bash_completion.d/ ] && [ -d /usr/share/bash-completion/completions/ ]; then
    #' List all BASH auto-completion scripts
    alias lsbashautocomp='ls /usr/share/bash-completion/completions/ /etc/bash_completion.d/'
elif [ -d /etc/bash_completion.d/ ]; then
    #' List all BASH auto-completion scripts
    alias lsbashautocomp='ls /etc/bash_completion.d/'
elif [ -d /usr/share/bash-completion/completions/ ]; then
    #' List all BASH auto-completion scripts
    alias lsbashautocomp='ls /usr/share/bash-completion/completions/'
fi


# FUNCTIONS #


# File Manipulation Functions

if [ "$PLATFORM" = 'linux' ] || [ "$PLATFORM" = 'cygwin' ]; then
    #' Copy the ownership and permissions of one file to another
    copyFileOwnership() {
        if [ -z "$1" ] || [ -z "$2" ]; then
            printf 'ERROR: A parameter is required!\n' >&2
        else
            chmod --reference="$1" "$2"
            chown --reference="$1" "$2"
        fi
    }
fi

#' Find an executable script with the given name (without regex) and open it with cat
fcat() {
    if [ -z "$1" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
        printf 'Find an executable script with the given name (without regex) and open it with cat\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Find an executable script with the given name (without regex) and open it with cat\n'
    elif [ -r "$(which "${1}")" ]; then
        floc="$(which "${1}")"
        if file -b -L --mime "$floc" | grep -q '^text'; then
            cat "$floc"
        else
            printf 'ERROR: The file is not a plain-text script!\n' >&2
        fi
    else
        printf 'ERROR: The script was not found!\n' >&2
    fi
}

#' Find a directory with the given name (without regex); searches from CWD if no directory is specified
finddir() {
    if [ -z "$1" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
        printf 'Find a directory with the given name (without regex); searches from CWD if no directory is specified\nUsage: finddir DIR_NAME [LOOK_IN_DIR]\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Find a directory with the given name (without regex); searches from CWD if no directory is specified\nUsage: finddir DIR_NAME [LOOK_IN_DIR]\n'
    elif [ -n "${2:-}" ] && [ -d "$2" ]; then
        find "$2" -mount -type d -name "$1" -exec printf '%s\n' '{}' + 2> /dev/null
    else
        find . -mount -type d -name "$1" -exec printf '%s\n' '{}' + 2> /dev/null
    fi
}

#' Find a directory with the given name (with regex); searches from / if no directory is specified
finddirx() {
    if [ -z "$1" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
        printf 'Find a directory with the given name (with regex); searches from / if no directory is specified\nUsage: finddirx DIR_NAME [LOOK_IN_DIR]\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Find a directory with the given name (with regex); searches from / if no directory is specified\nUsage: finddirx DIR_NAME [LOOK_IN_DIR]\n'
    elif [ -n "${2:-}" ] && [ -d "$2" ]; then
        find "$2" -type d -regextype awk -regex ".*/${1}" -exec printf '%s\n' '{}' + 2> /dev/null
    else
        find / -type d -regextype awk -regex ".*/${1}" -exec printf '%s\n' '{}' + 2> /dev/null
    fi
}

#' Find a file with the given name (without regex); searches from CWD if no directory is specified
findfile() {
    if [ -z "$1" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
        printf 'Find a file with the given name (without regex); searches from CWD if no directory is specified\nUsage: findfile FILE_NAME [LOOK_IN_DIR]\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Find a file with the given name (without regex); searches from CWD if no directory is specified\nUsage: findfile FILE_NAME [LOOK_IN_DIR]\n'
    elif [ -n "${2:-}" ] && [ -d "$2" ]; then
        find "$2" -mount -type f -name "$1" -exec printf '%s\n' '{}' + 2> /dev/null
    else
        find . -mount -type f -name "$1" -exec printf '%s\n' '{}' + 2> /dev/null
    fi
}

#' Find a file with the given name (with regex); searches from / if no directory is specified
findfilex() {
    if [ -z "$1" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
        printf 'Find a file with the given name (with regex); searches from / if no directory is specified\nUsage: findfilex FILE_NAME [LOOK_IN_DIR]\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Find a file with the given name (with regex); searches from / if no directory is specified\nUsage: findfilex FILE_NAME [LOOK_IN_DIR]\n'
    elif [ -n "${2:-}" ] && [ -d "$2" ]; then
        find "$2" -type f -regextype awk -regex ".*/${1}" -exec printf '%s\n' '{}' + 2> /dev/null
    else
        find / -type f -regextype awk -regex ".*/${1}" -exec printf '%s\n' '{}' + 2> /dev/null
    fi
}

#' Find file and directory names (recursively) containing the specified pattern and rename the file/directory using the replacement text in-place if the found pattern in the current directory (unless specified otherwise)
#' @param[in] $1 Text pattern to find in the file/directory names
#' @param[in] $2 New text that will replace the found pattern
#' @param[in] $3 (Optional) Directory to search recursively
findrename() {
    if [ -n "${1:-}" ] && ([ "${1}" = '-h' ] || [ "${1}" = '--help' ]) && [ -z "${2:-}" ]; then
        printf 'USAGE: findrename "FIND" "REPLACE" [DIRECTORY]\n'
    elif [ -z "${1:-}" ] || [ -z "${2:-}" ]; then
        printf 'ERROR: Expected at least two parameters ("Find" & "Replace with")!\n' >&2
    else
        if [ -n "${3:-}" ] && [ -d "${3}" ]; then
            filenames="$(find "${3}" -name "*${1}*" -print)"
        elif [ -z "${3:-}" ]; then
            filenames="$(find . -name "*${1}*" -print)"
        fi
        echo "${filenames}"
        for filename in ${filenames}; do
            mv "${filename}" "${filename//${1}/${2}}"
        done
    fi
}

#' Find and replace text recursively in the current directory (unless specified otherwise)
#' @param[in] $1 Text pattern to find
#' @param[in] $2 New text that will replace the found pattern
#' @param[in] $3 (Optional) Directory to search recursively
findrep() {
    # shellcheck disable=SC2038
    if [ -n "${1:-}" ] && ([ "${1}" = '-h' ] || [ "${1}" = '--help' ]) && [ -z "${2:-}" ]; then
        printf 'USAGE: findrep "FIND" "REPLACE" [DIRECTORY]\n'
    elif [ -z "${1:-}" ] || [ -z "${2:-}" ]; then
        printf 'ERROR: Expected at least two parameters ("Find" & "Replace with")!\n' >&2
    else
        if [ -n "${3:-}" ] && [ -d "${3}" ]; then
            find "${3}" -type f -exec grep -l -F "${1}" {} + | xargs sed -i "s|${1}|${2}|g"
        elif [ -z "${3:-}" ]; then
            find . -type f -exec grep -l -F "${1}" {} + | xargs sed -i "s|${1}|${2}|g"
        fi
    fi
}

#' Removes files that match the given regex pattern
rmfiles() {
    if [ -z "$1" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
        printf 'Removes files that match the given regex pattern\n--preview will print filenames instead of deleting them\nUsage: rmfiles [--preview] PATTERN [LOOK_IN_DIR]\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Removes files that match the given regex pattern\n--preview will print filenames instead of deleting them\nUsage: rmfiles [--preview] PATTERN [LOOK_IN_DIR]\n'
    elif [ "$1" = '--test' ] || [ "$1" = '-t' ] || [ "$1" = '--preview' ]; then
        if [ -n "${3:-}" ] && [ -d "$3" ]; then
            find "$3" -type f -regextype awk -regex ".*/${2}" -exec printf '%s\n' '{}' + 2> /dev/null
        elif [ -n "${2:-}" ]; then
            find . -type f -regextype awk -regex ".*/${2}" -exec printf '%s\n' '{}' + 2> /dev/null
        else
            printf 'ERROR: Parameters are missing or invalid!\n' >&2
        fi
    elif [ -n "${2:-}" ] && [ -d "$2" ]; then
        find "$2" -type f -regextype awk -regex ".*/${1}" -print0 | xargs -0 -I % rm -f % 2> /dev/null
    else
        find . -type f -regextype awk -regex ".*/${1}" -print0 | xargs -0 -I % rm -f % 2> /dev/null
    fi
}

#' Find and delete Python cache directories recursively in the current directory (unless specified otherwise)
#' @param[in] $1 (Optional) Directory to search recursively
rmpycache() {
    if [ -n "${1:-}" ] && ([ "${1}" = '-h' ] || [ "${1}" = '--help' ]) && [ -z "${2:-}" ]; then
        printf 'USAGE: rmpycache [DIRECTORY]\n'
    else
        if [ -n "${1:-}" ] && [ -d "${1}" ]; then
            find "${1}" -mount -type d -name "__pycache__" -print0 | xargs -0 rm -f -r
        elif [ -z "${1:-}" ]; then
            find . -mount -type d -name "__pycache__" -print0 | xargs -0 rm -f -r
        fi
    fi
}

#' Search for a filename in $PATH
searchInPath() {
    if [ -z "$1" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
    else
        for searchIn in ${PATH//:/ }; do
            find "$searchIn" -mount -type f -name "$1" -exec printf '%s\n' '{}' +
        done
    fi
}
alias findinpath=searchInPath

#' Search for a filename in $PKG_CONFIG_PATH
searchInPkgPath() {
    if [ -z "$1" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
    else
        for searchIn in ${PKG_CONFIG_PATH//:/ }; do
            find "$searchIn" -mount -type f -name "$1" -exec printf '%s\n' '{}' +
        done
    fi
}

# Mail Functions

if [ -x "$(command -v mail)" ]; then
    #' Send an email to somebody
    #' @param[in] $1 Subject line
    #' @param[in] $2 Body message
    #' @param[in] $3 Recipient (Mail to email address)
    email() {
        if [ -z "${NAME:-}" ]; then
            if [ -n "${USERNAME:-}" ]; then
                NAME="${USERNAME}"
            elif [ -x "$(command -v whoami)" ]; then
                NAME="$(whoami)"
            else
                printf 'ERROR: Unable to find the name of the sender (global variable "NAME" is missing)!\n' >&2
            fi
        fi
        if [ -z "${1:-}" ] || [ -z "${2:-}" ] || [ -z "${3:-}" ] || [ -z "${EMAIL:-}" ]; then
            printf 'ERROR: This command requires three parameters (Subject-line, Body-msg, & recipient) & the global variable "Email" set to the desired email address for the sender!\n' >&2
        else
            echo "${2}" | mail -a "FROM: ${NAME} <${EMAIL}>" -s "${1}" "${3}"
        fi
    }

    #' Email a file to somebody
    #' @param[in] $1 Subject line
    #' @param[in] $2 File path
    #' @param[in] $3 Recipient (Mail to email address)
    email_file() {
        if [ -z "${NAME:-}" ]; then
            if [ -n "${USERNAME:-}" ]; then
                NAME="${USERNAME}"
            elif [ -x "$(command -v whoami)" ]; then
                NAME="$(whoami)"
            else
                printf 'ERROR: Unable to find the name of the sender (global variable "NAME" is missing)!\n' >&2
            fi
        fi
        if [ -z "${1:-}" ] || [ -z "${2:-}" ] || [ -z "${3:-}" ] || [ -z "${EMAIL:-}" ]; then
            printf 'ERROR: This command requires three parameters (Subject-line, File-location, & Destination email address) & the global variable "Email" set to the desired email address for the sender!\n' >&2
        elif [ ! -r "${2}" ] || [ ! -f "${2}" ]; then
            printf 'ERROR: The attached file either does not exist, does not have the needed permissions, or is not a file!\n' >&2
        else
            mail -A "${2}" -a "FROM: ${NAME} <${EMAIL}>" -s "${1}" "${3}"
        fi
    }
fi

# Networking Functions

#' Determine if the network is up by looking for any non-loopback internet network interfaces
CheckForNetwork() {
    if [ -z "${NETWORKUP:-}" ]; then
        test="$(ifconfig -a inet 2> /dev/null | sed -n -e '/127.0.0.1/d' -e '/0.0.0.0/d' -e '/inet/p' | wc -l)"
        if [ "${test}" -gt 0 ]; then
            NETWORKUP='-YES-'
        else
            NETWORKUP='-NO-'
        fi
    fi
    unset test
}

downloadtar() { wget -c "$1" -O - | tar -xz; }

# Patch Functions

#' Apply a patch given a file name and the pathname of the patch
applypatch() {
    if [ -z "$1" ] && [ -z "$2" ] && [ ! -f "$1" ] && [ ! -f "$2" ]; then
        printf 'ERROR: Two file names are required!\n' >&2
    elif [ ! -x "$(command -v patch)" ]; then
        printf 'ERROR: The "patch" command was not found!\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Apply a patch given a file name (first) and then the pathname of the patch\n'
    elif [ -f "$1" ] && [ -f "$2" ]; then
        patch "$1" < "$2"
    fi
}

#' Create a patch given two file names
createpatch() {
    if [ -z "$1" ] && [ -z "$2" ] && [ ! -f "$1" ] && [ ! -f "$2" ]; then
        printf 'ERROR: Two file names are required!\n' >&2
    elif [ ! -x "$(command -v diff)" ]; then
        printf 'ERROR: The "diff" command was not found!\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Create a patch given two file names\n'
    elif [ -f "$1" ] && [ -f "$2" ]; then
        curdir="$(dirname "${BASH_SOURCE[0]}")"
        diff -u "$1" "$2" > "${curdir}/patch.diff"
    fi
}

#' Reverse the effects of a patch given a file name and the pathname of the patch
reversepatch() {
    if [ -z "$1" ] && [ -z "$2" ] && [ ! -f "$1" ] && [ ! -f "$2" ]; then
        printf 'ERROR: Two file names are required!\n' >&2
    elif [ ! -x "$(command -v patch)" ]; then
        printf 'ERROR: The "patch" command was not found!\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Reverse the effects of a patch given a file name and the pathname of the patch\n'
    elif [ -f "$1" ] && [ -f "$2" ]; then
        patch -R "$1" < "$2"
    fi
}

#' Show the unique lines of two files given two file names
uniquelines() {
    if [ -z "$1" ] && [ -z "$2" ] && [ ! -f "$1" ] && [ ! -f "$2" ]; then
        printf 'ERROR: Two file names are required!\n' >&2
    elif [ ! -x "$(command -v comm)" ]; then
        printf 'ERROR: The "comm" command was not found!\n' >&2
    elif [ ! -x "$(command -v sort)" ]; then
        printf 'ERROR: The "sort" command was not found!\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Show the unique lines of two files given two file names\n'
    elif [ -f "$1" ] && [ -f "$2" ]; then
        tmpfile1="/tmp/$(rndfname).tmp"
        tmpfile2="/tmp/$(rndfname).tmp"
        sort "$1" > "$tmpfile1"
        sort "$2" > "$tmpfile2"
        comm -3 "${tmpfile1}" "${tmpfile2}"
        rm "$tmpfile1" "$tmpfile2"
    fi
}

# Process Control Functions

#' Return the PID of a process (if found)
GetPID() {
    program="$1"
    pidfile="${PIDFILE:=/var/run/${program}.pid}"
    pid=''
    unset program
    if [ -r "$pidfile" ]; then
        pid="$(head -1 "$pidfile")"
        if [ ! "$(kill -0 "$pid" 2> /dev/null)" ]; then
            printf 'Bad pid file %s; deleting.\n' "$pidfile"
            pid=''
            rm -f "$pidfile"
        fi
    fi
    unset pidfile
    if [ -n "$pid" ]; then
        printf '%s\n' "$pid"
        unset pid
        return 0
    fi
    unset pid
    return 1
}

if [ -x "$(command -v ps)" ]; then
    #' Return the top 10 cpu-resource-consuming processes
    pscpu10() { echo '  PID USER     TTY      STAT %CPU %MEM COMMAND' && ps -e -o pid,user,tname,stat,pcpu,pmem,comm | awk '{ if (NR != 1) { print } }' | sort -nr -k 5 | awk 'FNR <= 10' && echo '  PID USER     TTY      STAT %CPU %MEM COMMAND'; }
    #' Return the top 10 memory-consuming processes
    psmem10() { echo '  PID USER     TTY      STAT %CPU %MEM COMMAND' && ps -e -o pid,user,tname,stat,pcpu,pmem,comm | awk '{ if (NR != 1) { print } }' | sort -nr -k 6 | awk 'FNR <= 10' && echo '  PID USER     TTY      STAT %CPU %MEM COMMAND'; }
fi

# String Manipulation Functions

if [ -x "$(command -v mawk)" ]; then
    #' Use a faster Awk implementation (if available)
    fawk() { mawk "${1}"; }
    #' Remove blank lines from a stream of text
    noblanks() { mawk NF; }
elif [ -x "$(command -v nawk)" ]; then
    #' Use a faster Awk implementation (if available)
    fawk() { nawk "${1}"; }
    #' Remove blank lines from a stream of text
    noblanks() { nawk NF; }
else
    #' Use a faster Awk implementation (if available)
    fawk() { awk "${1}"; }
    #' Remove blank lines from a stream of text
    noblanks() { awk NF; }
fi

if [ -x "$(command -v gawk)" ]; then
    #' Output a random word from the specified file (the file is left unchanged)
    getrandword() { gawk 'BEGIN { srand(systime() + PROCINFO["pid"]) } { gsub(/[^[:alpha:]]/, " "); for (i=1; i<=NF; i++) { if (length($i) > 3) { a[++j] = $i; } } } END { print a[int(j * rand())]; }' "${1}"; }
fi

# System Control Functions

if [ -r /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor ]; then
    #' Set the CPU to performance mode (helper function)
    ampupcpu_helper() {
        for FILE in /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor; do
            [ ! -w "$FILE" ] && break
            [ -w "$FILE" ] && echo -n performance > "$FILE"
        done
    }

    #' Set the CPU to performance mode
    ampupcpu() {
        sudo -H sh -c "ampupcpu_helper"
    }
fi

#' Check hardware sensors
chkhw() {
    [ -x "$(command -v inxi)" ] && inxi -B -s -x -x -x
    [ -x "$(command -v acpi)" ] && acpi -i -s -V
    [ -x "$(command -v nvidia-smi)" ] && nvidia-smi -q -d "POWER,TEMPERATURE" | awk 'NR > 6'
    [ -x "$(command -v sensors)" ] && sensors
}

#' Display amount of GPU memory
gpumeminfo() {
    if [ -x "$(command -v glxinfo)" ]; then
        glxinfo | grep -o -E 'Total available memory: [0-9]+[ \t]*.+' | cut -d ' ' -f 4,5
    elif [ -f /var/log/Xorg.0.log ]; then
        grep -o -E 'Memory:.+' /var/log/Xorg.0.log | cut -d ' ' -f 2,3
    fi
}

[ -x "$(command -v systemctl)" ] && enabledservices() { systemctl list-unit-files | grep -F 'enabled' | awk '{ print $1 }' | sort; }

if [ -n "$(command -v StartService)" ] && [ -n "$(command -v RestartService)" ]; then
    #' Generic Action Handler
    RunService() {
        case "$1" in
            start) StartService;;
            stop) StopService;;
            restart) RestartService;;
            *) printf '%s: unknown argument: %s\n' "$0" "$1";;
        esac
    }
fi

#' Set the system's hostname
sethostname() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
    else
        sudo hostname "${1}"
        sudo sh -c "${1} > /etc/hostname"
    fi
}

# Miscellaneous Functions

if [ -x "$(command -v awk)" ]; then
    #' Create table listing command usage with percentages
    cmdusage() {
        history | awk '{ CMD[$2]++; count++; } END { for (a in CMD) print CMD[a] " " CMD[a] / count * 100 "% " a; }' | grep -F -v './' | column -c3 -s ' ' -t | sort -n -r | nl | head -n10
    }

    #' Test the terminal's ability to produce colors
    colortest() {
        awk 'BEGIN {
            for (column = 0; column < 256; column++) {
                g = ((column * 510) / 255);
                if (g > 255) { g = 510 - g; }
                printf "\033[48;2;%d;%d;%dm%s\033[0m", 255 - column, g, column, " ";
            }
            printf "\n";
        }'
    }
fi

[ "$PLATFORM" = 'linux' ] && findmod() { find "/lib/modules/${KRELEASE}" | grep -F -i "$1"; }

#' Search for information on the given command by trying multiple info commands (such as man and info)
ihelp() {
    while [ -n "${1:-}" ]; do
        man "${1}" 2> /dev/null && break
        info "${1}" 2> /dev/null && break
        "${1}" --help 2> /dev/null && break
        printf 'ERROR: Unable to find information on %s!\n' "${1}" >&2
        break
    done
}

lastval() { printf '%s\n' "$?"; }

if [ -x "$(command -v pathchk)" ]; then
    #' Test if the files in the given directory are using Posix-compliant pathnames
    testpathnames() {
        if [ -n "$1" ] && [ -d "$1" ]; then
            find "$1" -exec pathchk -p -P '{}' +
        else
            find ./ -exec pathchk -p -P '{}' +
        fi
    }

    #' Test if the files in the given directory are using valid pathnames
    validatepathnames() {
        if [ -n "$1" ] && [ -d "$1" ]; then
            find "$1" -exec pathchk '{}' +
        else
            find ./ -exec pathchk '{}' +
        fi
    }
fi

if [ -d /usr/share/nano ]; then
    #' List all programming languages supported by Nano
    lsnanolangs() {
        find /usr/share/nano/* -type f -name "*.nanorc" -exec printf "%s\n" '{}' +
    }
    #' Regenerate the ALL.nanorc file
    refreshnanorc() {
        find /usr/share/nano/* -type f -name "*.nanorc" -exec printf "include %s\n" '{}' + | sudo tee /usr/share/nano/ALL.nanorc
    }
elif [ -d /usr/local/share/nano ]; then
    #' List all programming languages supported by Nano
    lsnanolangs() {
        find /usr/local/share/nano/* -type f -name "*.nanorc" -exec printf "%s\n" '{}' +
    }
    #' Regenerate the ALL.nanorc file
    refreshnanorc() {
        find /usr/local/share/nano/* -type f -name "*.nanorc" -exec printf "include %s\n" '{}' + | sudo tee /usr/local/share/nano/ALL.nanorc
    }
fi

#' Create a random filename
rndfname() { date +%Y%m%u%d%H%M%S%s%N; }

if [ -x "$(command -v R)" ]; then
    #' Execute compiled R file (*.Rc)
    Rexe() { R -q --slave -e "library('compiler'); loadcmp(${RC_FILE})"; }
fi

if [ -x "$(command -v gsettings)" ]; then
    #' Set the desktop wallpaper to the specified image
    setwallpaper() {
        if [ -z "$1" ]; then
            printf 'ERROR: A parameter is required!\n' >&2
        elif [ ! -r "$1" ]; then
            printf '%s: The specified file is non-readable or non-existent!\n' "$1" >&2
        else
            if ([ -n "${XDG_SESSION_DESKTOP:-}" ] && [ "$XDG_SESSION_DESKTOP" = 'mate' ]) || ([ -n "${XDG_CURRENT_DESKTOP:-}" ] && [ "$XDG_CURRENT_DESKTOP" = 'MATE' ]); then  # Mate
                gsettings set org.mate.desktop.background picture-filename "$1"
                gsettings set org.mate.desktop.screensaver picture-uri "$1"
            elif ([ -n "${XDG_SESSION_DESKTOP:-}" ] && [ "$XDG_SESSION_DESKTOP" = 'gnome' ]) || ([ -n "${XDG_CURRENT_DESKTOP:-}" ] && [ "$XDG_CURRENT_DESKTOP" = 'GNOME' ]); then  # GNOME
                gsettings set org.gnome.desktop.background picture-uri "$1"
                gsettings set org.gnome.desktop.screensaver picture-uri "$1"
            elif ([ -n "${XDG_CURRENT_DESKTOP:-}" ] && [ "$XDG_CURRENT_DESKTOP" = 'XFCE' ]); then  # XFCE
                xfconf-query --channel xfce4-desktop --property /backdrop/screen0/monitor0/image-path --set "$1"
            fi
        fi
    }
fi

if [ -x "$(command -v sqlite3)" ]; then
    #' Vacuum the specified SQLite database files
    sqlvacuum() {
        for file in "$@"; do
            if [ ! -r "$file" ]; then
                printf '%s: The specified file is non-readable or non-existent!\n' "$file" >&2 && continue
            else
                echo 'vacuum;' | sqlite3 "$file"
            fi
        done
    }
fi


# AUTOCOMPLETE #


if [ "$PROFILE_SHELL" = 'bash' ] && [ -n "${SHELL_IS_INTERACTIVE:-}" ] && [ -n "$(command -v mapfile)" ] && [ -n "$(command -v complete)" ]; then
    # Source/Import the Bash autocompletion feature
    if [ -r /etc/bash_completion ]; then
        . /etc/bash_completion
    elif [ -r /usr/share/bash-completion/bash_completion ]; then
        . /usr/share/bash-completion/bash_completion
    fi
    # Autocomplete make targets
    if [ -n "$(command -v make)" ]; then
        _make_target_tmp() { make -pqs | sed '/^.+:=.*$/d; /^#.*$/d; /^\-.*$/d;' | grep -o -E '^[a-zA-Z0-9_\-]+:.*$' | cut -d ':' -f 1 | awk "/^${1}/"; }
        _make_target_autocomplete() { tmpfile="/tmp/$(rndfname).tmp"; _make_target_tmp "$2" > "$tmpfile"; mapfile -t COMPREPLY < "$tmpfile"; rm "$tmpfile"; }
        if [ -n "$(command -v _make_autocomplete)" ]; then
            complete -F _make_target_autocomplete -o nospace make
            readonly -f _make_target_autocomplete
        fi
    fi
fi

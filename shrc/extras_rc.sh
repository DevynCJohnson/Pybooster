#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Shell RC script providing miscellaneous aliases and functions
#' @file extras_rc.sh
#' @version 2020.01.26
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
[ -x "$(command -v unzip)" ] && [ ! -x "$(command -v unzip)" ] && alias unzip='unzip -q -q'

# Filesystem Maneuvering Aliases

alias ..='cd ..'
alias ...='cd ../..'
alias ....='cd ../../..'
alias .....='cd ../../../..'
alias ......='cd ../../../../..'
alias .......='cd ../../../../../..'
alias .3='cd ../../..'
alias .4='cd ../../../..'
alias .5='cd ../../../../..'
alias .6='cd ../../../../../..'
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
alias lsl='if [ -n "$(command -v less)" ]; then ls -A -F -h -l | less; else ls -A -F -h -l | more; fi'
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
alias rmemptydir='find . -type d -empty -delete'
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

# Settings Manipulation Aliases

if [ -x "$(command -v dconf)" ]; then
    alias backupdconf='dconf dump / > "${HOME}/gsettings.dump"'
    alias restoredconf='dconf load <'
fi
[ -x "$(command -v gsettings)" ] && alias backupgset='gsettings list-recursively > "${HOME}/gsettings.lst"'
if [ "$DESKENV" = 'gnome' ]; then
    [ -x "$(command -v gsettings)" ] && alias setgtktheme='gsettings set org.gnome.desktop.interface gtk-theme'
elif [ "$DESKENV" = 'mate' ]; then
    [ -x "$(command -v gsettings)" ] && alias setgtktheme='gsettings set org.mate.desktop.interface gtk-theme'
elif [ "$DESKENV" = 'xfce' ]; then
    [ -x "$(command -v xfconf-query)" ] && alias setgtktheme='xfconf-query -c xsettings -p /Net/ThemeName -s'
    [ -x "$(command -v gsettings)" ] && alias setgtktheme='gsettings set org.gnome.desktop.interface gtk-theme'
fi

# String Manipulation Aliases

#' Convert string to lowercase
alias lowercase="tr '[:upper:]' '[:lower:]'"
#' Recursively search the specified/current directory for the specified string
alias rfind='grep -n -r -F'
#' Recursively search the specified/current directory for the specified string and only lists the filenames containing the string
alias rfindls='grep -l -r -F'
#' Remove the first X columns
alias rm1stxcols='cut -d " " -f'
#' Convert string to uppercase
alias uppercase="tr '[:lower:]' '[:upper:]'"

# String Search Aliases

#' Find files that begin with a Python hashpling
alias findpypling='grep -F "#!/usr/bin/env python" ./*'
alias findr='grep -I -i -n -q -r -s .*'
alias findrx='grep -E -I -n -q -r -s .*'

# System Control Aliases

[ -x "$(command -v fstrim)" ] && alias cleanssd='sudo fstrim -a -v'  #' Clean unused blocks on SSD drives
if [ "$(id -u)" -eq 0 ] && [ -f /proc/sys/vm/drop_caches ]; then
    alias freepagecache='echo 1 > /proc/sys/vm/drop_caches'
    alias freeinodes='echo 2 > /proc/sys/vm/drop_caches'
    alias freeramcache='echo 3 > /proc/sys/vm/drop_caches'
fi
[ -x "$(command -v swapon)" ] && alias freeswap='sudo swapoff -a && sleep 2 && sudo swapon -a'
alias killjobs='kill "$(jobs -ps)" 2> /dev/null'
[ -f /sys/devices/system/clocksource/clocksource0/available_clocksource ] && alias lsclocks='cat /sys/devices/system/clocksource/clocksource0/available_clocksource'
alias lsmount='mount | column -t'
[ -x "$(command -v free)" ] && alias meminfo='free -m -l -t'
[ -x "$(command -v xset)" ] && alias monitoroff='xset dpms force off'
alias powerdown='sudo shutdown -h now'
alias poweroff='sudo shutdown -h now'
alias quickclean='sudo rm -f -r /var/log/ && sudo rm -f /var/backups/*.gz'
alias reboot='history -c; sudo shutdown -r now'
alias resudo='sudo -v'
alias sedo='sudo -E'
alias unmount='sudo umount'
alias viewhugepages='grep --color=never -F -i huge /proc/meminfo'

# Terminal Control Aliases

alias CLEAR='clear'
alias clr='clear'
alias CLR='clear'
#' @alias fclr Clear the terminal and history before changing directory to home
alias fclr='cd ~; history -c; clear'
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
alias findalias='alias | cut -d " " -f 2 | cut -d "=" -f 1 | grep -i -F'
alias findfunc='declare -F | cut -d " " -f 3 | grep -i -F'
alias lsfuncs='declare -F | cut -d " " -f 3'
[ -x "$(command -v compgen)" ] && alias lskeywords='compgen -k'
[ -x "$(command -v compgen)" ] && alias lsbuiltins='compgen -b'
alias lsmethods='alias | cut -d " " -f 2 | cut -d "=" -f 1; declare -F | cut -d " " -f 3'
alias viewpath='echo "$PATH"'

# Miscellaneous Aliases

alias ConsoleMessage='echo'
[ -x "$(command -v du)" ] && [ -n "$(command -v less)" ] && alias du.='du -a -c -h | sort -h | less'  #' Show the disk usage of each directory
[ -x "$(command -v df)" ] && [ -n "$(command -v less)" ] && alias df.='df -a -h -T | less'  #' Show disk usage for each filesystem
alias mkae='make'
[ -x "$(command -v compiz)" ] && alias rgui='pidof compiz && killall -SIGHUP compiz'  #' Restart Compiz (fixes memory leak)
alias py2path='python2.7 -c "import site; site._script()"'
alias pypath='python3 -m site'
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
        if [ -z "$1" ] || [ -z "${2:-}" ]; then
            printf 'ERROR: A parameter is required!\n' >&2
        else
            chmod --reference="$1" "$2"
            chown --reference="$1" "$2"
        fi
    }
fi

#' Find an executable script with the given name (without regex) and open it with cat
fcat() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
        printf 'Find an executable script with the given name (without regex) and open it with cat\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Find an executable script with the given name (without regex) and open it with cat\n'
    elif [ -r "$(command -v "${1}")" ]; then
        floc="$(command -v "${1}")"
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
    if [ -z "${1:-}" ]; then
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

#' Find a directory with the given name (with regex); searches from CWD if no directory is specified
finddirx() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
        printf 'Find a directory with the given name (with regex); searches from CWD if no directory is specified\nUsage: finddirx DIR_NAME [LOOK_IN_DIR]\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Find a directory with the given name (with regex); searches from CWD if no directory is specified\nUsage: finddirx DIR_NAME [LOOK_IN_DIR]\n'
    elif [ -n "${2:-}" ] && [ -d "$2" ]; then
        find "$2" -type d -regextype awk -regex ".*/${1}|${1}" -exec printf '%s\n' '{}' + 2> /dev/null
    else
        find . -type d -regextype awk -regex ".*/${1}|${1}" -exec printf '%s\n' '{}' + 2> /dev/null
    fi
}

#' Find a file with the given name (without regex); searches from CWD if no directory is specified
findfile() {
    if [ -z "${1:-}" ]; then
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

#' Find a file with the given name (with regex); searches from CWD if no directory is specified
findfilex() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
        printf 'Find a file with the given name (with regex); searches from CWD if no directory is specified\nUsage: findfilex FILE_NAME [LOOK_IN_DIR]\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Find a file with the given name (with regex); searches from CWD if no directory is specified\nUsage: findfilex FILE_NAME [LOOK_IN_DIR]\n'
    elif [ -n "${2:-}" ] && [ -d "$2" ]; then
        find "$2" -type f -regextype awk -regex ".*/${1}|${1}" -exec printf '%s\n' '{}' + 2> /dev/null
    else
        find . -type f -regextype awk -regex ".*/${1}|${1}" -exec printf '%s\n' '{}' + 2> /dev/null
    fi
}

#' @brief Locate all files in the specified (or current) directory that have the specified mimetype
#' @param[in] $1 Specify mimetype using a string or flag
#' @param[in] $2 Optional parameter for specifying the directory; The default is the current directory
#' @usage findmime -zip /home
findmime() {
    _dir="."
    [ -d "${2:-}" ] && _dir="$2"
    [ ! -d "${_dir:-}" ] && _dir="$(pwd)"
    if [ -z "${1:-}" ]; then
        printf 'ERROR: No mimetype was specified!\n' >&2
        return 1
    fi
    _opt=''
    case "${1:-}" in
        # Archive
        '-tar') _opt='application/x\-tar';;
        # Compressed
        '-gzip') _opt='application/gzip';;
        '-rar') _opt='application/x\-rar';;
        '-zip') _opt='application/zip';;
        # Documents
        '-csv') _opt='text/csv';;
        '-office') _opt='application/vnd\.openxmlformats\-officedocument';;
        '-pdf') _opt='application/pdf';;
        '-txt') _opt='text/plain';;
        # Executables
        '-bin') _opt=' charset=binary';;
        '-elf') _opt='application/x\-(executable|sharedlib)';;
        '-exe') _opt='application/x\-executable';;
        '-macho') _opt='application/x\-mach\-binary';;
        '-msi') _opt='application/vnd\.ms\-office';;
        '-oct') _opt='application/octet-stream';;
        '-pe') _opt='application/x\-dosexec';;
        '-pie') _opt='application/x\-pie\-executable';;
        # Images
        '-image') _opt='image/*';;
        '-jpg'|'-jpeg') _opt='image/jpeg';;
        # Multimedia
        '-audio') _opt='audio/*';;
        '-video') _opt='video/*';;
        # Other
        '-deb') _opt='application/vnd.debian.binary-package';;
        # Fallback
        *) _opt="${2}";;
    esac
    # Buffering Results
    IFS=''
    fileslist="$(find "${_dir}" -type f -exec printf '%s' '{}' +)"
    if [ -n "${fileslist}" ]; then
        if [ "${_opt}" != ' charset=binary' ]; then
            for i in ${fileslist}; do
                filetype="$(file -b -N --mime-type "${i}")"
                [ -z "${filetype##$_opt}" ] && echo "${i#./*}"
            done
        else
            for i in ${fileslist}; do
                filetype="$(file -b -i "${i}" | cut -d ';' -f 2)"
                [ "${filetype}" = ' charset=binary' ] && echo "${i#./*}"
            done
        fi
    else
        return 2
    fi
}

#' Find file and directory names (recursively) containing the specified pattern and rename the file/directory using the replacement text in-place if the found pattern in the current directory (unless specified otherwise)
#' @param[in] $1 Text pattern to find in the file/directory names
#' @param[in] $2 New text that will replace the found pattern
#' @param[in] $3 (Optional) Directory to search recursively
findrename() {
    if [ -n "${1:-}" ] && { [ "${1}" = '-h' ] || [ "${1}" = '--help' ]; } && [ -z "${2:-}" ]; then
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
            newfilename="$(echo "${filename}" | sed "s|${1}|${2}|g")"
            mv "${filename}" "${newfilename}"
        done
    fi
}

#' Find and replace text (with Regex support) recursively in the current directory (unless specified otherwise)
#' @param[in] $1 Text pattern to find (ERE)
#' @param[in] $2 New text that will replace the found pattern
#' @param[in] $3 (Optional) Directory to search recursively
findrep() {
    # shellcheck disable=SC2038
    if [ -n "${1:-}" ] && { [ "${1}" = '-h' ] || [ "${1}" = '--help' ]; } && [ -z "${2:-}" ]; then
        printf 'USAGE: findrep "FIND" "REPLACE" [DIRECTORY]\n'
    elif [ -z "${1:-}" ] || [ -z "${2:-}" ]; then
        printf 'ERROR: Expected at least two parameters ("Find" & "Replace with")!\n' >&2
    else
        if [ -n "${3:-}" ] && [ -d "${3}" ]; then
            grep -l -r -E -Z "${1}" "${3}" | xargs -0 sed -i -e "s|${1}|${2}|g"
        elif [ -z "${3:-}" ]; then
            grep -l -r -E -Z "${1}" . | xargs -0 sed -i -e "s|${1}|${2}|g"
        fi
    fi
}

#' Removes files that match the given regex pattern
rmfiles() {
    if [ -z "${1:-}" ]; then
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
    if [ -n "${1:-}" ] && { [ "${1}" = '-h' ] || [ "${1}" = '--help' ]; } && [ -z "${2:-}" ]; then
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
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
    else
        IFS=':'
        for searchIn in ${PATH}; do
            find "${searchIn}" -name "$1" -executable
        done
    fi
}
alias findinpath=searchInPath

#' Search for a filename in $PKG_CONFIG_PATH
searchInPkgPath() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
    else
        IFS=':'
        for searchIn in ${PKG_CONFIG_PATH}; do
            find "${searchIn}" -name "$1" -type f
        done
    fi
}

#' Gzip-equivalent of `less`
zless(){ zcat "${1}" | less; }

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
            elif [ -n "$(command -v whoami)" ]; then
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
            elif [ -n "$(command -v whoami)" ]; then
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

# Math Functions

#' Convert a string to a hexadecimal sequence
#' DocTest
#' str2hex 'This is a test.'
#' >>> 54 68 69 73 20 69 73 20 61 20 74 65 73 74 2e
#' str2hex -x 'This is a test.'
#' >>> \x54\x68\x69\x73\x20\x69\x73\x20\x61\x20\x74\x65\x73\x74\x2e
#' str2hex -0x 'This is a test.'
#' >>> 0x54 0x68 0x69 0x73 0x20 0x69 0x73 0x20 0x61 0x20 0x74 0x65 0x73 0x74 0x2e
#' str2hex -c 'This is a test.'
#' >>> { 0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 0x74, 0x65, 0x73, 0x74, 0x2e }
str2hex() {
    [ "$#" -eq 0 ] && return 1
    [ -z "${1:-}" ] && return 1
    case "${1}" in
        '-x') printf '%s\n' "$(printf '%s' "${2}" | hexdump -v -e '/1 "%02x"' | sed 's|..|\\x&|g' | tr -d '\n')";;
        '-0x') printf '%s\n' "$(printf '%s' "${2}" | hexdump -v -e '/1 "0x%02x "' | sed 's|\(.*\) |\1|' | tr -d '\n')";;
        '-c') printf '{ %s }\n' "$(printf '%s' "${2}" | hexdump -v -e '/1 "0x%02x, "' | sed 's|\(.*\), |\1|' | tr -d '\n')";;
        *) printf '%s\n' "$(printf '%s' "$1" | hexdump -v -e '/1 "%02x "' | sed 's|\(.*\) |\1|' | tr -d '\n')";;
    esac
}


#' Shift the first parameter to the left by the number given in the second parameter
shl() {
    [ "$#" -lt 2 ] && return 1
    echo "$(($1 << $2))"
}


#' Shift the first parameter to the right by the number given in the second parameter
shr() {
    [ "$#" -lt 2 ] && return 1
    echo "$(($1 >> $2))"
}

#' Return the exclusive-or of two parameter
xor() {
    [ "$#" -lt 2 ] && return 1
    echo "$(($1 ^ $2))"
}

# Patch Functions

#' Apply a patch given a file name and the pathname of the patch
applypatch() {
    if [ -z "${1:-}" ] && [ -z "${2:-}" ] && [ ! -f "$1" ] && [ ! -f "$2" ]; then
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
    if [ -z "${1:-}" ] && [ -z "${2:-}" ] && [ ! -f "$1" ] && [ ! -f "$2" ]; then
        printf 'ERROR: Two file names are required!\n' >&2
    elif [ ! -x "$(command -v diff)" ]; then
        printf 'ERROR: The "diff" command was not found!\n' >&2
    elif [ "$1" = "-h" ] || [ "$1" = "--help" ] || [ "$1" = "-?" ]; then
        printf 'Create a patch given two file names\n'
    elif [ -f "$1" ] && [ -f "$2" ]; then
        diff -u "$1" "$2"
    fi
}

#' Reverse the effects of a patch given a file name and the pathname of the patch
reversepatch() {
    if [ -z "${1:-}" ] && [ -z "${2:-}" ] && [ ! -f "$1" ] && [ ! -f "$2" ]; then
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
    if [ -z "${1:-}" ] && [ -z "${2:-}" ] && [ ! -f "$1" ] && [ ! -f "$2" ]; then
        printf 'ERROR: Two file names are required!\n' >&2
    elif [ ! -x "$(command -v comm)" ]; then
        printf 'ERROR: The "comm" command was not found!\n' >&2
    elif [ -z "$(command -v sort)" ]; then
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
    pidfile="${PIDFILE:=/var/run/${1:-}.pid}"
    pid=''
    if [ -r "$pidfile" ]; then
        pid="$(head -1 "$pidfile")"
        if [ ! "$(kill -0 "$pid" 2> /dev/null)" ]; then
            printf 'Bad pid file %s; deleting.\n' "$pidfile"
            pid=''
            rm -f "$pidfile"
        fi
    fi
    unset pidfile
    if [ -n "${pid:-}" ]; then
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
    fawk() { mawk "${1:-}"; }
    #' Remove blank lines from a stream of text
    noblanks() { mawk NF; }
    #' Trim whitespace
    trimwsp() { echo "${1:-}" | mawk '{$1=$1};1'; }
elif [ -x "$(command -v nawk)" ]; then
    #' Use a faster Awk implementation (if available)
    fawk() { nawk "${1:-}"; }
    #' Remove blank lines from a stream of text
    noblanks() { nawk NF; }
    #' Trim whitespace
    trimwsp() { echo "${1:-}" | nawk '{$1=$1};1'; }
else
    #' Use a faster Awk implementation (if available)
    fawk() { awk "${1:-}"; }
    #' Remove blank lines from a stream of text
    noblanks() { awk NF; }
    #' Trim whitespace
    trimwsp() { echo "${1:-}" | awk '{$1=$1};1'; }
fi

if [ -x "$(command -v gawk)" ]; then
    #' Output a random word from the specified file (the file is left unchanged)
    getrandword() { gawk 'BEGIN { srand(systime() + PROCINFO["pid"]) } { gsub(/[^[:alpha:]]/, " "); for (i=1; i<=NF; i++) { if (length($i) > 3) { a[++j] = $i; } } } END { print a[int(j * rand())]; }' "${1}"; }
fi

# System Control Functions

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

if [ -x "$(command -v systemctl)" ]; then
    lsservices() { systemctl --all list-unit-files | sed -E -e 's|.+ unit files listed.+||' | awk NF | sort; }
    services_bad() { systemctl --all list-unit-files | grep -F 'bad' | cut -d ' ' -f 1 | sort; }
    services_disabled() { systemctl --all list-unit-files | grep -F 'disabled' | cut -d ' ' -f 1 | sort; }
    services_enabled() { systemctl --all list-unit-files | grep -F 'enabled' | cut -d ' ' -f 1 | sort; }
    services_enabledruntime() { systemctl --all list-unit-files | grep -F 'enabled-runtime' | cut -d ' ' -f 1 | sort; }
    services_generated() { systemctl --all list-unit-files | grep -F 'generated' | cut -d ' ' -f 1 | sort; }
    services_indirect() { systemctl --all list-unit-files | grep -F 'indirect' | cut -d ' ' -f 1 | sort; }
    services_linked() { systemctl --all list-unit-files | grep -F 'linked' | cut -d ' ' -f 1 | sort; }
    services_linkedruntime() { systemctl --all list-unit-files | grep -F 'linked-runtime' | cut -d ' ' -f 1 | sort; }
    services_masked() { systemctl --all list-unit-files | grep -F 'masked' | cut -d ' ' -f 1 | sort; }
    services_maskedruntime() { systemctl --all list-unit-files | grep -F 'masked-runtime' | cut -d ' ' -f 1 | sort; }
    services_static() { systemctl --all list-unit-files | grep -F 'static' | cut -d ' ' -f 1 | sort; }
    services_transient() { systemctl --all list-unit-files | grep -F 'transient' | cut -d ' ' -f 1 | sort; }
    lsjobs() { systemctl --all list-jobs; }
    lssockets() { systemctl --all list-sockets; }
    lstimers() { systemctl --all list-timers; }
    lsunits() { systemctl --all list-units; }
    sysctlprops() { systemctl show; }
    servicedeps() { systemctl --all list-dependencies; }
    servicedisable() { [ -n "${1:-}" ] && sudo systemctl disable "${@:-}"; }
    serviceenable() { [ -n "${1:-}" ] && sudo systemctl enable "${@:-}"; }
    servicelog() { journalctl -xe; }
    servicereload() { [ -n "${1:-}" ] && sudo systemctl reload "${@:-}"; }
    servicerestart() { [ -n "${1:-}" ] && sudo systemctl restart "${@:-}"; }
    servicesrebuild() { sudo systemctl daemon-reload; }
    servicestart() { [ -n "${1:-}" ] && sudo systemctl start "${@:-}"; }
    servicestat() { [ -n "${1:-}" ] && sudo systemctl status "${@:-}"; }
    servicestop() { [ -n "${1:-}" ] && sudo systemctl stop "${@:-}"; }
    isserviceactive() { [ -n "${1:-}" ] && systemctl is-active "${1:-}"; }
    isservicefailed() { [ -n "${1:-}" ] && systemctl is-failed "${1:-}"; }
fi

if [ -n "$(command -v StartService)" ] && [ -n "$(command -v RestartService)" ]; then
    #' Generic Action Handler
    RunService() {
        case "$1" in
            'start') StartService;;
            'stop') StopService;;
            'restart') RestartService;;
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


#' View active CPU mitigation
viewmit() {
    [ -d /sys/devices/system/cpu/vulnerabilities/ ] && grep 'Mitigation' /sys/devices/system/cpu/vulnerabilities/*
}

#' View CPU vulnerabilities
viewvul() {
    [ -d /sys/devices/system/cpu/vulnerabilities/ ] && ls /sys/devices/system/cpu/vulnerabilities/
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

#' Calculate the number of days between to dates
datediff() {
    d1=$(date -d "$1" +%s)
    d2=$(date -d "$2" +%s)
    printf '%s days\n' $(( (d1 - d2) / 86400 ))
}

#' Convert seconds since the Epoch to the format of the current system locale
epoch2date() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: No input provided!\n' >&2
    else
        date -d "@${1}"
    fi
}

#' Create a Git tag
gittag(){ git tag -s -a "v$(date +'%Y.%m.%d')" -m "${1}"; }

#' Delete a Git tag both locally and remotely
del_git_tag(){ git tag --delete "${1}"; git push origin ":refs/tags/${1}"; }

#' Easily send messages to the wall
msg(){ echo "${1}" | wall; }

#' Calculate the distance between two times
timediff() {
    d1=$(date -d "${1}:00" +%s)
    d2=$(date -d "${2}:00" +%s)
    result=$(( (d1 - d2) / 60 ))
    if [ -x "$(command -v wcalc)" ]; then
        printf '%s hours \n' "$(wcalc "${result} / 60")" | sed 's| = ||'
    elif [ -x "$(command -v calc)" ]; then
        printf '%s hours \n' "$(calc -c -d -- "${result} / 60" | cut -f 2)" | sed 's| = ||'
    else
        printf 'ERROR: "calc" or "wcalc" must be installed!\n' >&2
    fi
}

# shellcheck disable=SC2039
findmethod() { alias | cut -d ' ' -f 2 | cut -d '=' -f 1 | grep -i -F "$1"; [ -n "$(command -v declare)" ] && declare -F | cut -d ' ' -f 3 | grep -i -F "$1"; }

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
        find /usr/share/nano/* -type f -name "*.nanorc" -exec printf '%s\n' '{}' +
    }
    #' Regenerate the ALL.nanorc file
    refreshnanorc() {
        find /usr/share/nano/* -type f -name "*.nanorc" -exec printf 'include %s\n' '{}' + | sudo tee /usr/share/nano/ALL.nanorc
    }
elif [ -d /usr/local/share/nano ]; then
    #' List all programming languages supported by Nano
    lsnanolangs() {
        find /usr/local/share/nano/* -type f -name "*.nanorc" -exec printf '%s\n' '{}' +
    }
    #' Regenerate the ALL.nanorc file
    refreshnanorc() {
        find /usr/local/share/nano/* -type f -name "*.nanorc" -exec printf 'include %s\n' '{}' + | sudo tee /usr/local/share/nano/ALL.nanorc
    }
fi

#' Convert a manpage to HTML format
manpage2html(){
    if [ -n "${1:-}" ] && [ -n "${2:-}" ]; then
        _sectionLower="$(printf '%s' "${2}" | tr '[:upper:]' '[:lower:]')"
        _section="$(printf '%s' "${2}" | awk '{ string=substr($0, 1, 1); print string; }' | tr '[:upper:]' '[:lower:]')"
        { [ ! -d "/usr/share/man/man${_section}" ] || [ ! -f "/usr/share/man/man${_section}/${1}.${_sectionLower}.gz" ]; } && { printf 'ERROR: Manpage not found!\n' >&2; exit 1; }
        man --html=cat "/usr/share/man/man${_section}/${1}.${_sectionLower}.gz" | awk '{ if (NR > 2) { print $0; } }'
    elif [ -n "${1:-}" ]; then
        _manfile="$(find /usr/share/man/ -type f -wholename "*/man[1-8]/${1}.*.gz" -exec printf '%s\n' '{}' + | sort | tr '\n' ' ' | cut -d ' ' -f 1)"
        if [ -z "${_manfile:-}" ]; then
            printf 'ERROR: The manpage was not found!\n' >&2
            exit 1
        fi
        man --html=cat "${_manfile}" | awk '{ if (NR > 2) { print $0; } }'
    else
        printf 'ERROR: At least one parameter is required!\n' >&2
    fi
}

#' Create a random filename
rndfname() { date +%Y%m%u%d%H%M%S%s%N; }

if [ -x "$(command -v R)" ]; then
    #' Execute compiled R file (*.Rc)
    Rexe() { R -q --slave -e "library('compiler'); loadcmp(${RC_FILE})"; }
fi

#' Set the desktop wallpaper to the specified image
setwallpaper() {
    if [ -z "$1" ]; then
        printf 'ERROR: A parameter is required!\n' >&2
    elif [ ! -r "$1" ]; then
        printf '%s: The specified file is non-readable or non-existent!\n' "$1" >&2
    else
        case "$DESKTYPE" in
            'gnome')
                gsettings set org.gnome.desktop.background picture-uri "$1"
                gsettings set org.gnome.desktop.screensaver picture-uri "$1"
            ;;
            'mate')
                gsettings set org.mate.desktop.background picture-filename "$1"
                gsettings set org.mate.desktop.screensaver picture-uri "$1"
            ;;
            'xfce')
                xfconf-query --channel xfce4-desktop --property /backdrop/screen0/monitor0/image-path --set "$1"
            ;;
            *)
                printf 'ERROR: Currently, setwallpaper does not support your desktop environment!\n' >&2
                exit 1
            ;;
        esac
    fi
}

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

#' Update the XDG databases for the current user
updatexdg() {
    [ -x "$(command -v update-desktop-database)" ] && update-desktop-database "${HOME}/.local/share/applications/"
    [ -x "$(command -v update-mime-database)" ] && update-mime-database "${HOME}/.local/share/mime/"
}

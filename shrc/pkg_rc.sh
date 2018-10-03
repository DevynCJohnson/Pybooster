#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Shell RC script providing universal aliases for various package management commands
#' @file pkg_rc.sh
#' @version 2018.10.02
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# PACKAGE MANAGEMENT #


[ "$PROFILE_SHELL" = 'bash' ] && set -a

if [ "$PLATFORM" = 'darwin' ] && [ "$PLATFORM" != 'gnu' ]; then  # Apple/Darwin Package Managers
    # TODO: Add MacPorts and Fink
    if [ -n "$(command -v brew)" ]; then  # MacOS Homebrew
        cleanrepocache() { brew cleanup; }
        clrpkg() { brew prune; }
        getpkgsrc() { brew fetch "${@//;// }"; }
        lsrepos() { brew tap; }
        mkbrewpkg() { brew create "${@//;// }"; }
        pkginfo() { brew info formula "${@//;// }"; }
        pkginstall() { brew install "${@//;// }"; }
        pkglsaval() { brew list --unbrewed; }
        pkglsinst() { brew list; }
        pkglsleaves() { brew leaves; }
        pkglsup() { brew outdated; }
        pkgreinstall() { brew reinstall "${@//;// }"; }
        pkguninstall() { brew uninstall "${@//;// }"; }
        pkgupdate() { ([ -n "${*:-}" ] && brew upgrade "${@//;// }") || ([ -z "${*:-}" ] && brew upgrade); }
        refreshman() { brew man; }
        refreshrepo() { brew update --force; }
        repocheck() { brew doctor; }
        repofinddebian() { brew search --debian "${@//;// }"; }
        repofindfedora() { brew search --fedora "${@//;// }"; }
        repofindfink() { brew search --fink "${@//;// }"; }
        repofindmacports() { brew search --macports "${@//;// }"; }
        repofindopensuse() { brew search --opensuse "${@//;// }"; }
        repofindubuntu() { brew search --ubuntu "${@//;// }"; }
        repoinfo() { brew tap-info; }
        writebrewfile() { brew bundle cleanup; }
    fi
elif [ -d /etc/apt ] && [ -x "$(command -v apt-get)" ]; then  # Debian Linux Apt
    cleanrepocache() { sudo apt-get clean; }
    clrpkg() { sudo apt-get autoremove; }
    [ -n "$(command -v apt-cache)" ] && findpkg() { apt-cache search "$1"; }
    getPkgChlog() { apt-get changelog "${@//;// }"; }
    getpkgsrc() { apt-get source --download-only "${@//;// }"; }
    pkginstall() { sudo apt-get install "${@//;// }"; }
    pkglsall() { apt-cache --no-generate pkgnames "${1:-}"; }
    pkglsavalup() { sudo apt-get -u upgrade --assume-no; }
    pkgreinstall() { sudo apt-get install --reinstall "${@//;// }"; }
    pkguninstall() { sudo apt-get purge "${@//;// }"; }
    pkgupdate() { sudo apt-get install --only-upgrade "${@//;// }"; }
    refreshrepo() { sudo apt-get update; }
    repocheck() { sudo apt-get check; }
    sysupdate() { sudo apt-get dist-upgrade; }
    if [ -x "$(command -v add-apt-repository)" ]; then
        addrepo() { sudo add-apt-repository "${@//;// }"; }
        rmrepo() { sudo add-apt-repository --remove "${@//;// }"; }
    fi
    if [ -x "$(command -v dpkg)" ]; then
        alias filepkgorigin='dpkg-query -S'
        alias filesfrompkg='dpkg-query -L'
        alias pkglsinst='dpkg --list | grep ^i'
    fi
    [ -x "$(command -v dpkg-query)" ] && alias pkgfind='dpkg-query --list'
elif [ -d /etc/dnf ] && [ -x "$(command -v dnf)" ]; then  # Fedora DNF
    cleanrepocache() { sudo dnf clean all; }
    clrpkg() { sudo dnf autoremove; }
    pkgdowngrade() { sudo dnf downgrade "${@//;// }"; }
    pkginfo() { dnf info "${@//;// }"; }
    pkginstall() { sudo dnf install "${@//;// }"; }
    pkglsall() { dnf list all; }
    pkglsaval() { dnf list available; }
    pkglsinst() { dnf list installed; }
    pkglsup() { dnf list updates; }
    pkgreinstall() { sudo dnf reinstall "${@//;// }"; }
    pkguninstall() { sudo dnf remove "${@//;// }"; }
    pkgupdate() { sudo dnf upgrade "${@//;// }"; }
    refreshrepo() { sudo dnf clean expire-cache && sudo dnf check-update; }
    repocheck() { sudo dnf check; }
    sysupdate() { sudo dnf upgrade --refresh; }
elif [ -d /etc/portage ] && [ -x "$(command -v emerge)" ]; then  # Gentoo Emerge
    cleanrepocache() { eclean distfiles; }
    clrpkg() { eclean --depclean; }
    getPkgChlog() { equery changes -f "${@//;// }"; }
    pkginstall() { emerge -a "${@//;// }"; }
    pkglsall() { emerge -ep world; }
    pkglsinst() { emerge -ep world; }
    pkglsup() { emerge -uDNp world; }
    pkgreinstall() { emerge -1O "${@//;// }"; }
    pkguninstall() { emerge -C "${@//;// }"; }
    refreshrepo() { emerge --sync && layman -S; }
    repocheck() { emerge -uDN world; }
    sysupdate() { emerge -u world; }
elif [ -f /etc/opkg.conf ] && [ -x "$(command -v opkg)" ]; then  # OpenWrt Opkg
    pkginstall() { opkg install "${@//;// }"; }
    pkglstaval() { opkg list; }
    pkglstinst() { opkg list-installed; }
    pkglstup() { opkg list-upgradable; }
    pkguninstall() { opkg remove "${@//;// }"; }
    pkgupdate() { opkg upgrade "${@//;// }"; }
    refreshrepo() { opkg update; }
elif [ -d /etc/pacman ] && [ -x "$(command -v pacman)" ]; then  # Arch Linux Pacman
    cleanrepocache() { pacman -Scc; }
    clrpkg() { pacman -Rs -; }
    getPkgChlog() { pacman -Qc "${@//;// }"; }
    pkginstall() { pacman -S "${@//;// }"; }
    pkglsaval() { pacman -Sl; }
    pkglsinst() { pacman -Qqe; }
    pkglsup() { pacman -Qu; }
    pkgreinstall() { pacman -S "${@//;// }"; }
    pkguninstall() { pacman -Rs "${@//;// }"; }
    pkgupdate() { pacman -Syu "${@//;// }"; }
    refreshrepo() { pacman -Sy; }
    repocheck() { pacman -Dk; }
    sysupdate() { pacman -Syu; }
elif [ "$OSFAMILY" = 'sun' ] && [ -x "$(command -v pkg)" ]; then  # Solaris IPS (pkg)
    pkginstall() { pkg install "${@//;// }"; }
    pkglsinst() { pkg list; }
    pkguninstall() { pkg uninstall "${@//;// }"; }
    pkgupdate() { pkg upgrade "${@//;// }"; }
    repocheck() { pkg verify; }
    sysupdate() { pkg update; }
elif [ "$OSFAMILY" = 'sun' ] && [ -x "$(command -v pkgutil)" ]; then  # Solaris pkgutil
    pkginstall() { pkgutil --install "${@//;// }"; }
    pkgreinstall() { pkgutil --force --install "${@//;// }"; }
    pkguninstall() { pkgutil --remove "${@//;// }"; }
    pkgupdate() { pkgutil --upgrade "${@//;// }"; }
    refreshrepo() { pkgutil --catalog; }
    repocheck() { pkgutil --syscheck; }
elif [ -d /etc/yum ] && [ -x "$(command -v yum)" ]; then  # RedHat Linux Yum
    cleanrepocache() { sudo yum clean all; }
    cleanrpmdb() { sudo yum clean rpmdb; }
    clrpkg() { sudo yum autoremove; }
    getPkgChlog() { yum changelog "${@//;// }"; }
    pkgdowngrade() { sudo yum downgrade "${@//;// }"; }
    pkginfo() { yum info "${@//;// }"; }
    pkginstall() { sudo yum install "${@//;// }"; }
    pkglsall() { yum list all; }
    pkglsaval() { yum list available; }
    pkglsinst() { yum list installed; }
    pkglsup() { yum list updates; }
    pkgreinstall() { sudo yum reinstall "${@//;// }"; }
    pkguninstall() { sudo yum remove "${@//;// }"; }
    pkgupdate() { sudo yum update "${@//;// }"; }
    refreshrepo() { sudo yum makecache; }
    repocheck() { sudo yum check; }
    sysupdate() { sudo yum upgrade; }
elif [ -d /etc/zypp ] && [ -x "$(command -v zypper)" ]; then  # OpenSUSE Zypper
    cleanrepocache() { zypper clean; }
    clrpkg() { zypper remove --clean-deps; }
    getPkgChlog() { rpm -q --changelog "${@//;// }"; }
    pkginstall() { zypper install "${@//;// }"; }
    pkglsall() { zypper packages; }
    pkglsinst() { zypper search --installed-only; }
    pkglsup() { zypper list-updates; }
    pkgreinstall() { zypper install --force "${@//;// }"; }
    pkguninstall() { zypper remove "${@//;// }"; }
    refreshrepo() { zypper refresh; }
    repocheck() { zypper verify; }
    sysupdate() { zypper update; }
fi

[ "$PROFILE_SHELL" = 'bash' ] && set +a


# NPM (JAVASCRIPT) PACKAGE MANAGEMENT #


if [ -x "$(command -v npm)" ]; then
    alias cleanjscache='sudo -H npm cache clean'
    alias jsinstall='sudo -H npm install -g'
    alias jspkglsinst='npm -g ls --depth 0'
    alias jsrepocheck='sudo -H npm doctor'
    alias jsuninstall='sudo -H npm uninstall -g'
    alias jsupdate='sudo -H npm update -g'
fi


# PEAR (PHP) PACKAGE MANAGEMENT #


if [ -x "$(command -v pear)" ]; then
    alias phpinstall='sudo -H pear install'
    alias phppkglsinst='pear list'
    alias phpuninstall='sudo -H pear uninstall'
    alias phpupdate='sudo -H pear upgrade'
fi


# PIP (PYTHON) PACKAGE MANAGEMENT #


if [ -x "$(command -v pip3)" ]; then  # Python3
    alias findpypkg='pip3 search'
    alias genpyreqfile='pip3 freeze > ./requirements.txt'
    alias getpypkgsrc='pip3 download'
    alias pyinstall='sudo -H pip3 install'
    alias pypkglsinst='pip3 list --format=columns'
    alias pypkglsnonreq='pip3 list --not-required --format=columns'
    alias pypkglsup='pip3 list -o --format=columns'
    alias pypkglsusr='pip3 list --user --format=columns'
    alias pyreinstall='sudo -H pip3 install --upgrade --force-reinstall'
    alias pyrepocheck='sudo -H pip3 check'
    alias pyuninstall='sudo -H pip3 uninstall'
    alias pyupdate='sudo -H pip3 install -U'
    pysysupdate() { sudo -H sh -c "pip3 freeze --local | grep -v '^\-e' | cut -d '=' -f 1 | xargs -n1 pip3 install -U"; }
fi
if [ -x "$(command -v pip2)" ] && [ -x "$(command -v python2)" ]; then  # Python2
    alias findpy2pkg='pip2 search'
    alias genpy2reqfile='pip2 freeze > ./requirements.txt'
    alias getpy2pkgsrc='pip2 download'
    alias py2install='sudo -H pip2 install'
    alias py2pkglsinst='pip2 list --format=columns'
    alias py2pkglsnonreq='pip2 list --not-required --format=columns'
    alias py2pkglsup='pip2 list -o --format=columns'
    alias py2pkglsusr='pip2 list --user --format=columns'
    alias py2reinstall='sudo -H pip2 install --upgrade --force-reinstall'
    alias py2repocheck='sudo -H pip2 check'
    alias py2uninstall='sudo -H pip2 uninstall'
    alias py2update='sudo -H pip2 install -U'
    py2sysupdate() { sudo -H sh -c "pip2 freeze --local | grep -v '^\-e' | cut -d '=' -f 1 | xargs -n1 pip2 install -U"; }
fi


# R PACKAGE MANAGEMENT #


if [ -x "$(command -v R)" ]; then
    rinstall() { sudo R -e "install.packages(c('${1}'), lib='/usr/local/lib/R/site-library', repos='http://cran.rstudio.com/')"; }
fi


# INTERACTIVE SHELL #


# If not running interactively, then do not do anything
if [ -z "${PS1}" ]; then
    export isinteractive='false'
    return
else
    case "$-" in
        *i*) export isinteractive='true';;
        *) export isinteractive='false'; return;;
    esac
fi


# AUTOCOMPLETE #


if [ "$PROFILE_SHELL" = 'bash' ] && [ "$isinteractive" = 'true' ] && [ -n "$(command -v mapfile)" ] && [ -n "$(command -v complete)" ]; then
    # Autocomplete package names for the system's package installation, uninstallation, and reinstallation commands
    if [ -n "$(command -v pkglsall)" ] && [ -n "$(command -v pkginstall)" ]; then
        _pkginstall_autocomplete() { tmpfile="/tmp/$(rndfname).tmp"; pkglsall "$2" > "$tmpfile"; mapfile -t COMPREPLY < "$tmpfile"; rm "$tmpfile"; }
        if [ -n "$(command -v _pkginstall_autocomplete)" ]; then
            complete -F _pkginstall_autocomplete -o nospace pkginstall
            complete -F _pkginstall_autocomplete -o nospace pkguninstall
            complete -F _pkginstall_autocomplete -o nospace pkgreinstall
            readonly -f _pkginstall_autocomplete
        fi
    fi
    # Autocomplete Python package names for pip3
    if [ -n "$(command -v pip3)" ]; then
        _pip_tmp() { pip3 list --format=columns | awk '{ if (NR > 2) { print } }' | cut -d ' ' -f 1 | awk "/^${1}/"; }
        _pip3_autocomplete() { tmpfile="/tmp/$(rndfname).tmp"; _pip_tmp "$2" > "$tmpfile"; mapfile -t COMPREPLY < "$tmpfile"; rm "$tmpfile"; }
        if [ -n "$(command -v _pip3_autocomplete)" ]; then
            complete -F _pip3_autocomplete -o nospace pyinstall
            complete -F _pip3_autocomplete -o nospace pyreinstall
            complete -F _pip3_autocomplete -o nospace pyuninstall
            complete -F _pip3_autocomplete -o nospace pyupdate
            readonly -f _pip3_autocomplete
        fi
    fi
fi

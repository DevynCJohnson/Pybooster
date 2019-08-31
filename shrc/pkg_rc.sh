#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Shell RC script providing universal aliases for various package management commands
#' @file pkg_rc.sh
#' @version 2019.08.31
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# PACKAGE MANAGEMENT #


[ "$PROFILE_SHELL" = 'bash' ] && set -a

if [ "$PLATFORM" = 'darwin' ] && [ "$PLATFORM" != 'gnu' ]; then  # Apple/Darwin Package Managers
    if [ -n "$(command -v brew)" ]; then  # MacOS Homebrew
        cleanrepocache() { brew cleanup; }
        clrpkg() { brew prune; }
        getpkgsrc() { brew fetch "${@}"; }
        lsrepos() { brew tap; }
        mkbrewpkg() { brew create "${@}"; }
        pkginfo() { brew info formula "${@}"; }
        pkginstall() { brew install "${@}"; }
        pkglsaval() { brew list --unbrewed; }
        pkglsinst() { brew list; }
        pkglsleaves() { brew leaves; }
        pkglsup() { brew outdated; }
        pkgreinstall() { brew reinstall "${@}"; }
        pkguninstall() { brew uninstall "${@}"; }
        pkgupdate() { brew upgrade "${@}"; }
        refreshman() { brew man; }
        refreshrepo() { brew update --force; }
        repocheck() { brew doctor; }
        repofinddebian() { brew search --debian "${@}"; }
        repofindfedora() { brew search --fedora "${@}"; }
        repofindfink() { brew search --fink "${@}"; }
        repofindmacports() { brew search --macports "${@}"; }
        repofindopensuse() { brew search --opensuse "${@}"; }
        repofindubuntu() { brew search --ubuntu "${@}"; }
        repoinfo() { brew tap-info; }
        sysupgrade() { brew upgrade; }
        writebrewfile() { brew bundle cleanup; }
    elif [ -n "$(command -v fink)" ]; then  # MacOS Fink
        cleanrepocache() { fink cleanup; }
        pkgfind() { fink list "${1}"; }
        pkginstall() { fink install "${@}"; }
        pkglsinst() { fink list; }
        pkgreinstall() { fink reinstall "${@}"; }
        pkguninstall() { fink purge "${@}"; }
        pkgupdate() { fink update "${@}"; }
        refreshrepo() { fink index; }
        sysupgrade() { fink index; fink update-all; }
    elif [ -n "$(command -v fink)" ]; then  # MacOS MacPorts
        cleanrepocache() { port reclaim; }
        filesfrompkg() { port contents "${1}"; }
        pkgfind() { port list "${1}"; }
        pkginstall() { port install "${@}"; }
        pkglsavalup() { port outdated; }
        pkglsdeps() { port dependents; }
        pkglsinst() { port installed; }
        pkgreinstall() { port uninstall "${@}"; port install "${@}"; }
        pkguninstall() { port uninstall "${@}"; }
        pkgupdate() { port upgrade "${@}"; }
        refreshrepo() { port sync; }
        repocheck() { port diagnose; }
        sysupgrade() { port selfupdate; port upgrade outdated; }
    fi
elif [ -d /etc/apt ] && { [ -x "$(command -v apt)" ] || [ -x "$(command -v apt-get)" ]; }; then  # Debian Linux Apt
    cleanrepocache() { sudo apt-get clean; }
    clrpkg() { sudo apt-get autoremove; }
    [ -n "$(command -v apt-cache)" ] && findpkg() { apt-cache search "$1"; }
    fixApt() { [ -d /var/cache/apt/archives/partial/ ] && sudo chown -R _apt:root /var/cache/apt/archives/partial/ && sudo chmod -R 770 /var/cache/apt/archives/partial/; [ -x "$(command -v appstreamcli)" ] && appstreamcli refresh-cache > /dev/null; }
    getPkgChlog() { apt-get changelog "${@}"; }
    getpkgsrc() { apt-get source --download-only "${@}"; }
    pkginstall() { sudo apt-get install "${@}"; }
    pkglsall() { apt-cache --no-generate pkgnames "${1:-}"; }
    pkglsavalup() { sudo apt-get -u upgrade --assume-no; }
    pkgreinstall() { sudo apt-get install --reinstall "${@}"; }
    pkguninstall() { sudo apt-get purge "${@}"; }
    pkgupdate() { sudo apt-get install --only-upgrade "${@}"; }
    refreshrepo() { [ -d /var/cache/apt/archives/partial/ ] && sudo chown -R _apt:root /var/cache/apt/archives/partial/ && sudo chmod -R 770 /var/cache/apt/archives/partial/; [ -x "$(command -v appstreamcli)" ] && appstreamcli refresh-cache > /dev/null; sudo apt-get update; }
    repocheck() { sudo apt-get check; }
    sysupdate() { [ -d /var/cache/apt/archives/partial/ ] && sudo chown -R _apt:root /var/cache/apt/archives/partial/ && sudo chmod -R 770 /var/cache/apt/archives/partial/; sudo apt-get dist-upgrade; }
    sysupgrade() { [ -d /var/cache/apt/archives/partial/ ] && sudo chown -R _apt:root /var/cache/apt/archives/partial/ && sudo chmod -R 770 /var/cache/apt/archives/partial/; sudo apt-get update && sudo apt-get upgrade; sudo apt-get dist-upgrade && apt-get autoremove; sudo do-release-upgrade -d; }
    chgdistrocodename() { [ -d /etc/apt/ ] && sudo sh -c "sed -i 's|${1}|${2}|g' /etc/apt/sources.list && find /etc/apt/sources.list.d/*.list -type f -print0 | xargs -0 grep -l -F ${1} | xargs sed -i 's|${1}|${2}|g'" 2> /dev/null; }
    if [ -x "$(command -v add-apt-repository)" ]; then
        addrepo() { sudo add-apt-repository "${@}"; }
        rmrepo() { sudo add-apt-repository --remove "${@}"; }
    fi
    if [ -x "$(command -v dpkg)" ]; then
        if [ -x "$(command -v dpkg-query)" ]; then
            filepkgorigin() {
                if [ -n "${1:-}" ]; then
                    dpkg-query -S "${1}"
                else
                    printf 'ERROR: One parameter is required!\n' >&2
                fi
            }
            filesfrompkg() {
                if [ -n "${1:-}" ]; then
                    dpkg-query -L "${1}"
                else
                    printf 'ERROR: One parameter is required!\n' >&2
                fi
            }
            pkgfind() {
                if [ -n "${1:-}" ]; then
                    dpkg-query --list "${1}"
                else
                    printf 'ERROR: One parameter is required!\n' >&2
                fi
            }
        fi
        pkglsinst() {
            if [ -n "${1:-}" ]; then
                dpkg-query --list | grep ^i | grep -i -F -e "${1}"
            else
                dpkg-query --list | grep ^i
            fi
        }
        pkglshold() { dpkg --get-selections | grep hold; }
        #' List removed packages that still have remaining/persistent configuration files
        pkglsrc() { dpkg -l | grep ^rc; }
        #' List half-installed packages
        pkglshalfinst() { dpkg -l | grep ^.h; }
    fi
elif [ -d /etc/dnf ] && [ -x "$(command -v dnf)" ]; then  # Fedora DNF
    cleanrepocache() { sudo dnf clean all; }
    clrpkg() { sudo dnf autoremove; }
    pkgdowngrade() { sudo dnf downgrade "${@}"; }
    pkginfo() { dnf info "${@}"; }
    pkginstall() { sudo dnf install "${@}"; }
    pkglsall() { dnf list all; }
    pkglsaval() { dnf list available; }
    pkglsinst() { dnf list installed; }
    pkglsup() { dnf list updates; }
    pkgreinstall() { sudo dnf reinstall "${@}"; }
    pkguninstall() { sudo dnf remove "${@}"; }
    pkgupdate() { sudo dnf upgrade "${@}"; }
    refreshrepo() { sudo dnf clean expire-cache && sudo dnf check-update; }
    repocheck() { sudo dnf check; }
    sysupdate() { sudo dnf upgrade --refresh; }
elif [ -d /etc/portage ] && [ -x "$(command -v emerge)" ]; then  # Gentoo Emerge
    cleanrepocache() { eclean distfiles; }
    clrpkg() { eclean --depclean; }
    getPkgChlog() { equery changes -f "${@}"; }
    pkginstall() { emerge -a "${@}"; }
    pkglsall() { emerge -ep world; }
    pkglsinst() { emerge -ep world; }
    pkglsup() { emerge -uDNp world; }
    pkgreinstall() { emerge -1O "${@}"; }
    pkguninstall() { emerge -C "${@}"; }
    refreshrepo() { emerge --sync && layman -S; }
    repocheck() { emerge -uDN world; }
    sysupdate() { emerge -u world; }
elif [ -f /etc/opkg.conf ] && [ -x "$(command -v opkg)" ]; then  # OpenWrt Opkg
    pkginstall() { opkg install "${@}"; }
    pkglstaval() { opkg list; }
    pkglstinst() { opkg list-installed; }
    pkglstup() { opkg list-upgradable; }
    pkguninstall() { opkg remove "${@}"; }
    pkgupdate() { opkg upgrade "${@}"; }
    refreshrepo() { opkg update; }
elif [ -d /etc/pacman ] && [ -x "$(command -v pacman)" ]; then  # Arch Linux Pacman
    cleanrepocache() { pacman -Scc; }
    clrpkg() { pacman -Rs -; }
    getPkgChlog() { pacman -Qc "${@}"; }
    pkginstall() { pacman -S "${@}"; }
    pkglsaval() { pacman -Sl; }
    pkglsinst() { pacman -Qqe; }
    pkglsup() { pacman -Qu; }
    pkgreinstall() { pacman -S "${@}"; }
    pkguninstall() { pacman -Rs "${@}"; }
    pkgupdate() { pacman -Syu "${@}"; }
    refreshrepo() { pacman -Sy; }
    repocheck() { pacman -Dk; }
    sysupdate() { pacman -Syu; }
elif [ "$OSFAMILY" = 'sun' ] && [ -x "$(command -v pkg)" ]; then  # Solaris IPS (pkg)
    pkginstall() { pkg install "${@}"; }
    pkglsinst() { pkg list; }
    pkguninstall() { pkg uninstall "${@}"; }
    pkgupdate() { pkg upgrade "${@}"; }
    repocheck() { pkg verify; }
    sysupdate() { pkg update; }
elif [ "$OSFAMILY" = 'sun' ] && [ -x "$(command -v pkgutil)" ]; then  # Solaris pkgutil
    pkginstall() { pkgutil --install "${@}"; }
    pkgreinstall() { pkgutil --force --install "${@}"; }
    pkguninstall() { pkgutil --remove "${@}"; }
    pkgupdate() { pkgutil --upgrade "${@}"; }
    refreshrepo() { pkgutil --catalog; }
    repocheck() { pkgutil --syscheck; }
elif [ -d /etc/yum ] && [ -x "$(command -v yum)" ]; then  # RedHat Linux Yum
    cleanrepocache() { sudo yum clean all; }
    cleanrpmdb() { sudo yum clean rpmdb; }
    clrpkg() { sudo yum autoremove; }
    getPkgChlog() { yum changelog "${@}"; }
    pkgdowngrade() { sudo yum downgrade "${@}"; }
    pkginfo() { yum info "${@}"; }
    pkginstall() { sudo yum install "${@}"; }
    pkglsall() { yum list all; }
    pkglsaval() { yum list available; }
    pkglsinst() { yum list installed; }
    pkglsup() { yum list updates; }
    pkgreinstall() { sudo yum reinstall "${@}"; }
    pkguninstall() { sudo yum remove "${@}"; }
    pkgupdate() { sudo yum update "${@}"; }
    refreshrepo() { sudo yum makecache; }
    repocheck() { sudo yum check; }
    sysupdate() { sudo yum upgrade; }
elif [ -d /etc/zypp ] && [ -x "$(command -v zypper)" ]; then  # OpenSUSE Zypper
    cleanrepocache() { zypper clean; }
    clrpkg() { zypper remove --clean-deps; }
    getPkgChlog() { rpm -q --changelog "${@}"; }
    pkginstall() { zypper install "${@}"; }
    pkglsall() { zypper packages; }
    pkglsinst() { zypper search --installed-only; }
    pkglsup() { zypper list-updates; }
    pkgreinstall() { zypper install --force "${@}"; }
    pkguninstall() { zypper remove "${@}"; }
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
elif [ -x "$(command -v yarn)" ]; then
    alias cleanjscache='sudo -H yarn autoclean --force && yarn cache clean'
    alias jsinstall='sudo -H yarn global add'
    alias jspkglsinst='yarn versions'
    alias jsuninstall='sudo -H yarn global remove'
    alias jsupdate='sudo -H yarn global upgrade'
elif [ -x "$(command -v bower)" ]; then
    alias cleanjscache='sudo -H bower cache clean'
    alias jsinstall='sudo -H bower install'
    alias jspkglsinst='bower list'
    alias jsuninstall='sudo -H bower uninstall'
    alias jsupdate='sudo -H bower update'
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
    pysysupdate() { sudo -H sh -c "pip3 freeze --local | grep -v -e '^\\-e' | cut -d '=' -f 1 | xargs -n1 pip3 install -U"; }
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
    py2sysupdate() { sudo -H sh -c "pip2 freeze --local | grep -v -e '^\\-e' | cut -d '=' -f 1 | xargs -n1 pip2 install -U"; }
fi


# R PACKAGE MANAGEMENT #


if [ -x "$(command -v R)" ]; then
    rinstall() { sudo R -e "install.packages(c('${1}'), lib='/usr/local/lib/R/site-library', repos='http://cran.rstudio.com/')"; }
fi


# AUTOCOMPLETE #


if [ "$PROFILE_SHELL" = 'bash' ] && [ -n "${SHELL_IS_INTERACTIVE:-}" ] && [ -n "$(command -v mapfile)" ] && [ -n "$(command -v complete)" ]; then
    # Autocomplete package names for the system's package installation, uninstallation, and reinstallation commands
    if [ -n "$(command -v pkglsall)" ] && [ -n "$(command -v pkginstall)" ] && [ -z "$(command -v _pkginstall_autocomplete)" ]; then
        # shellcheck disable=SC2039
        _pkginstall_autocomplete() { tmpfile="$(mktemp /tmp/autocomplete_XXXXXXXX.tmp)"; pkglsall "$2" > "$tmpfile"; mapfile -t COMPREPLY < "$tmpfile"; rm "$tmpfile"; }
        # shellcheck disable=SC2039
        complete -F _pkginstall_autocomplete -o nospace pkginstall
        # shellcheck disable=SC2039
        complete -F _pkginstall_autocomplete -o nospace pkguninstall
        # shellcheck disable=SC2039
        complete -F _pkginstall_autocomplete -o nospace pkgreinstall
        # shellcheck disable=SC2039
        readonly -f _pkginstall_autocomplete
    fi
    # Autocomplete Python package names for pip3
    if [ -n "$(command -v pip3)" ] && [ -z "$(command -v _pip3_autocomplete)" ]; then
        _pip_tmp() { pip3 list --format=columns | awk '{ if (NR > 2) { print } }' | cut -d ' ' -f 1 | awk "/^${1}/"; }
        # shellcheck disable=SC2039
        _pip3_autocomplete() { tmpfile="$(mktemp /tmp/autocomplete_XXXXXXXX.tmp)"; _pip_tmp "$2" > "$tmpfile"; mapfile -t COMPREPLY < "$tmpfile"; rm "$tmpfile"; }
        # shellcheck disable=SC2039
        complete -F _pip3_autocomplete -o nospace pyinstall
        # shellcheck disable=SC2039
        complete -F _pip3_autocomplete -o nospace pyreinstall
        # shellcheck disable=SC2039
        complete -F _pip3_autocomplete -o nospace pyuninstall
        # shellcheck disable=SC2039
        complete -F _pip3_autocomplete -o nospace pyupdate
        # shellcheck disable=SC2039
        readonly -f _pip3_autocomplete
    fi
fi

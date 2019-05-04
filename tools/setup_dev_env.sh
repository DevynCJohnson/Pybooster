#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Install the packages needed for Devyn's development environment
#' @file setup_dev_env.sh
#' @version 2019.05.04
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# FUNCTIONS #


install_deb_pkgs() {
    if [ -x "$(command -v apt-get)" ]; then
        apt-get --quiet --yes install apcalc astyle bc bcpp binwalk bsdiff cccc cflow cgdb clang cloc colormake complexity coreutils cppcheck cppreference-doc-en-html csstidy debmake devhelp doschk doxygen doxygen-gui flawfinder gcc gdb git-cola git-doc git-extras git-flow git-gui gitk gitlint gitstats glade indent jsonlint kwstyle libxml2-utils licensecheck llvm ltrace make moreutils openssl optipng patchutils perltidy pmccabe pngcrush pscan python3-chardet python3-demjson python3-gi python3-logilab-common python3-pip python3-pytest python3-pytest-pep8 qgit shc shellcheck sloccount speedcrunch splint strace tidy uchardet uncrustify undertaker universalindentgui vbindiff wamerican-insane wcalc xdg-utils xmlindent xxdiff xxdiff-scripts xxgdb yajl-tools
        apt-get --quiet --yes install geany geany-plugin-addons geany-plugin-automark geany-plugin-codenav geany-plugin-commander geany-plugin-ctags geany-plugin-defineformat geany-plugin-doc geany-plugin-extrasel geany-plugin-gendoc geany-plugin-insertnum geany-plugin-keyrecord geany-plugin-latex geany-plugin-lineoperations geany-plugin-lua geany-plugin-macro geany-plugin-miniscript geany-plugin-numberedbookmarks geany-plugin-overview geany-plugin-pairtaghighlighter geany-plugin-pg geany-plugin-pohelper geany-plugin-prettyprinter geany-plugin-prj geany-plugin-projectorganizer geany-plugin-shiftcolumn geany-plugin-spellcheck geany-plugin-tableconvert geany-plugin-treebrowser geany-plugin-vc geany-plugin-workbench geany-plugin-xmlsnippets
    else
        printf 'ERROR: "apt-get" was not found!\n' >&2
        exit 1
    fi
}


install_pip_pkgs() {
    if [ -x "$(command -v pip3)" ]; then
        pip3 install --compile --force-reinstall --quiet --upgrade autopep8 bandit bashate crimp cx-Freeze docformatter flake8 flake8-aaa flake8-alfred flake8-assertive flake8-assign-and-return flake8-breakpoint flake8-builtins flake8-comprehensions flake8-copyright flake8-debugger flake8-deprecated flake8-logging-format flake8-mypy flake8-pie flake8-polyfill flake8-pyi flake8-return flake8-self flake8-tuple mccabe mypy mypy_extensions Pillow proselint pyaml pycodestyle pydocstyle pyflakes pyinstaller pylint pylint-django radon uncalled vulture yamllint
    else
        printf 'ERROR: "pip3" was not found!\n' >&2
        exit 1
    fi
}


# MAIN #


if [ ! "$(id -u)" -eq 0 ]; then
    exec sudo -H -- "$0"
else
    install_deb_pkgs
    install_pip_pkgs
fi

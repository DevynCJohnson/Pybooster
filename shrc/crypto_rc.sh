#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Shell RC script providing cryptograhpic aliases & functions
#' @file crypto_rc.sh
#' @version 2018.10.02
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


if [ -x "$(command -v openssl)" ]; then


# CRYPTOGRAPHY ALIASES #


alias Crypto_brainpool512='openssl ecparam -name brainpoolP512t1 -genkey'
alias Crypto_c2tnb431r1='openssl ecparam -name c2tnb431r1 -genkey'
alias Crypto_prime256='openssl ecparam -name prime256v1 -genkey'
alias Crypto_secp521='openssl ecparam -name secp521r1 -genkey'
alias Crypto_sect571k1='openssl ecparam -name sect571k1 -genkey'
alias Crypto_sect571r1='openssl ecparam -name sect571r1 -genkey'
alias CryptoCurves='openssl ecparam -list_curves'
alias CryptoPrime='openssl prime -generate -bits'
alias CryptoPswd='openssl passwd'
alias CryptoRand='openssl rand -base64'
alias md2='openssl dgst -md2'
alias md5='openssl dgst -md5'
alias mdc2='openssl dgst -mdc2'
alias rmd160='openssl dgst -rmd160'
alias sha1='openssl dgst -sha1'
alias sha224='openssl dgst -sha224'
alias sha256='openssl dgst -sha256'
alias sha384='openssl dgst -sha384'
alias sha512='openssl dgst -sha512'


# CRYPTOGRAPHIC FUNCTIONS #


if [ -r /dev/urandom ]; then
    #' Generate a random string using the specified number of bytes retrieved from /dev/urandom
    CryptoRandStr() { head -c "$1" /dev/urandom | openssl enc -base64; }
fi


fi

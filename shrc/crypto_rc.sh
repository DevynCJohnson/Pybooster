#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Shell RC script providing cryptograhpic aliases & functions
#' @file crypto_rc.sh
#' @version 2018.12.28
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# SETUP #


# Use the RDRAND OpenSSL engine if available
OPENSSL_ENGINE=''
if [ -x "$(command -v openssl)" ] && (openssl engine | grep -q rdrand); then
    readonly RDRAND_ENGINE=1
    readonly OPENSSL_ENGINE='-engine rdrand'
else
    readonly RDRAND_ENGINE=0
    readonly OPENSSL_ENGINE=''
fi


# CRYPTOGRAPHY ALIASES #


if [ -x "$(command -v openssl)" ]; then
    alias blake512='openssl dgst -blake2b512'  #' Produce the Blake2B512 checksum for the given data
    alias md5='openssl dgst -md5'  #' Produce the MD5 checksum for the given data
    alias sha1='openssl dgst -sha1'  #' Produce the SHA1 checksum for the given data
    alias sha224='openssl dgst -sha224'  #' Produce the SHA224 checksum for the given data
    alias sha256='openssl dgst -sha256'  #' Produce the SHA256 checksum for the given data
    alias sha384='openssl dgst -sha384'  #' Produce the SHA384 checksum for the given data
    alias sha512='openssl dgst -sha512'  #' Produce the SHA512 checksum for the given data
elif [ -x "$(command -v md5sum)" ] && [ -x "$(command -v sha512sum)" ]; then
    alias blake512='b2sum --tag'  #' Produce the Blake2B512 checksum for the given data
    alias md5='md5sum --tag'  #' Produce the MD5 checksum for the given data
    alias sha1='sha1sum --tag'  #' Produce the SHA1 checksum for the given data
    alias sha224='sha224sum --tag'  #' Produce the SHA224 checksum for the given data
    alias sha256='sha256sum --tag'  #' Produce the SHA256 checksum for the given data
    alias sha384='sha384sum --tag'  #' Produce the SHA384 checksum for the given data
    alias sha512='sha512sum --tag'  #' Produce the SHA512 checksum for the given data
fi


if [ -x "$(command -v openssl)" ]; then
    alias lsgpgkeys='gpg --fingerprint; gpg --list-keys'  #' List all GPG keys
    alias refreshgpgkeys='gpg --refresh-keys; gpg --update-trustdb'  #' Refresh and update the GPG keys and TrustDB
fi


if [ -x "$(command -v openssl)" ]; then


# Key Generators

alias rsa1024='openssl genrsa 1024'  #' Generate a random 1024-bit RSA private key
alias rsa2048='openssl genrsa 2048'  #' Generate a random 2048-bit RSA private key
alias rsa4096='openssl genrsa 4096'  #' Generate a random 4096-bit RSA private key
alias rsa8192='openssl genrsa 8192'  #' Generate a random 8192-bit RSA private key
alias rsa16384='openssl genrsa 16384'  #' Generate a random 16384-bit RSA private key
alias rsa1024file='openssl genrsa -out rsa1024pri.pem 1024'  #' Generate a file containing a random 1024-bit RSA private key
alias rsa2048file='openssl genrsa -out rsa2048pri.pem 2048'  #' Generate a file containing a random 2048-bit RSA private key
alias rsa4096file='openssl genrsa -out rsa4096pri.pem 4096'  #' Generate a file containing a random 4096-bit RSA private key
alias rsa8192file='openssl genrsa -out rsa8192pri.pem 8192'  #' Generate a file containing a random 8192-bit RSA private key
alias rsa16384file='openssl genrsa -out rsa16384pri.pem 16384'  #' Generate a file containing a random 16384-bit RSA private key

# Elliptic-Curve Key Generators

alias brainpool512_der='openssl rand ${OPENSSL_ENGINE:-} 8192 2>&1 | sed -E -e "s|engine .+||; /^$/d;" | openssl ecparam ${OPENSSL_ENGINE:-} -outform DER -name brainpoolP512t1 -genkey -out ec_brainpoolP512t1_pri.der 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate a private elliptic-curve key in DER format (brainpoolP512t1)
alias brainpool512='openssl ecparam ${OPENSSL_ENGINE:-} -outform PEM -name brainpoolP512t1 -genkey -out ec_brainpoolP512t1_pri.pem 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate a private elliptic-curve key (brainpoolP512t1)
alias brainpool512x='openssl ecparam ${OPENSSL_ENGINE:-} -outform PEM -name brainpoolP512t1 -genkey 2>&1 | sed -E -e "s|engine .+||; /^$/d;" | openssl ec ${OPENSSL_ENGINE:-} -bf-ofb -out ec_brainpoolP512t1_pri.pem 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate an encrypted private elliptic-curve key (brainpoolP512t1)
alias c2tnb431r1='openssl ecparam ${OPENSSL_ENGINE:-} -outform PEM -name c2tnb431r1 -genkey -out ec_c2tnb431r1_pri.pem 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate a private elliptic-curve key (c2tnb431r1)
alias prime256='openssl ecparam ${OPENSSL_ENGINE:-} -outform PEM -name prime256v1 -genkey -out ec_prime256_pri.pem 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate a private elliptic-curve key (prime256v1)
alias secp521='openssl ecparam ${OPENSSL_ENGINE:-} -outform PEM -name secp521r1 -genkey -out ec_secp521r1_pub.pem 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate a private elliptic-curve key (secp521r1)
alias sect571k1='openssl ecparam ${OPENSSL_ENGINE:-} -outform PEM -name sect571k1 -genkey -out ec_sect571k1_pub.pem 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate a private elliptic-curve key (sect571k1)
alias sect571r1='openssl ecparam ${OPENSSL_ENGINE:-} -outform PEM -name sect571r1 -genkey -out ec_sect571r1_pub.pem 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate a private elliptic-curve key (sect571r1)
alias wtls12='openssl ecparam ${OPENSSL_ENGINE:-} -outform PEM -name wap-wsg-idm-ecid-wtls12 -genkey -out ec_wap_wsg_idm_ecid_wtls12_pub.pem 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate a private elliptic-curve key (wap-wsg-idm-ecid-wtls12)

# Digests

alias b2b512='openssl blake2b512 | cut -d " " -f 2'  #' Produce the Blake2B512 checksum for the given data
alias b2s256='openssl dgst -blake2s256 | cut -d " " -f 2'  #' Produce the Blake2S256 checksum for the given data
alias gost='openssl gost | cut -d " " -f 2'  #' Produce the GOST checksum for the given data
alias md2='openssl dgst -md2 | cut -d " " -f 2'  #' Produce the MD2 checksum for the given data
alias md4='openssl dgst -md4 | cut -d " " -f 2'  #' Produce the MD4 checksum for the given data
alias mdc2='openssl dgst -mdc2 | cut -d " " -f 2'  #' Produce the MD5 checksum for the given data
alias rmd160='openssl dgst -ripemd160 | cut -d " " -f 2'  #' Produce the RIPEMD160 checksum for the given data
alias sha3='openssl sha3-512 | cut -d " " -f 2'  #' Produce the SHA3-512 checksum for the given data
alias shake128='openssl dgst -shake128 | cut -d " " -f 2'  #' Produce the SHAKE128 checksum for the given data
alias sm3='openssl dgst -sm3 | cut -d " " -f 2'  #' Produce the SM3 checksum for the given data
alias whirlpool='openssl dgst -whirlpool | cut -d " " -f 2'  #' Produce the Whirlpool checksum for the given data

# Random

alias rand4096base64='openssl rand ${OPENSSL_ENGINE:-} -base64 4096 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate 4096 bytes of base64-encoded random data
alias randbase64='openssl rand ${OPENSSL_ENGINE:-} -base64 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate base64-encoded random data (specify the number of random bytes to generate)
alias randbin1024='openssl rand ${OPENSSL_ENGINE:-} 1024 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate 1024 bytes of random data
alias randbin2048='openssl rand ${OPENSSL_ENGINE:-} 2048 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate 2048 bytes of random data
alias randbin4096='openssl rand ${OPENSSL_ENGINE:-} 4096 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate 4096 bytes of random data
alias randbin8192='openssl rand ${OPENSSL_ENGINE:-} 8192 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate 8192 bytes of random data
alias randbin16384='openssl rand ${OPENSSL_ENGINE:-} 16384 2>&1 | sed -E -e "s|engine .+||; /^$/d;"'  #' Generate 16384 bytes of random data
alias randprime='openssl prime -generate -bits'  #' Generate a random prime number (specify the bit-length)
alias randhexprime='openssl prime -generate -hex -bits'  #' Generate a random prime number encoded in hexadecimal (specify the bit-length)
alias randprime64='openssl prime -generate -bits 64'  #' Generate a random 64-bit prime number
alias randhexprime64='openssl prime -generate -bits 64 -hex'  #' Generate a random 64-bit prime number encoded in hexadecimal
alias randprime128='openssl prime -generate -bits 128'  #' Generate a random 128-bit prime number
alias randhexprime128='openssl prime -generate -bits 128 -hex'  #' Generate a random 128-bit prime number encoded in hexadecimal
alias randprime256='openssl prime -generate -bits 256'  #' Generate a random 256-bit prime number
alias randhexprime256='openssl prime -generate -bits 256 -hex'  #' Generate a random 256-bit prime number encoded in hexadecimal
alias randprime512='openssl prime -generate -bits 512'  #' Generate a random 512-bit prime number
alias randhexprime512='openssl prime -generate -bits 512 -hex'  #' Generate a random 512-bit prime number encoded in hexadecimal
alias randprime1024='openssl prime -generate -bits 1024'  #' Generate a random 1024-bit prime number
alias randhexprime1024='openssl prime -generate -bits 1024 -hex'  #' Generate a random 1024-bit prime number encoded in hexadecimal
alias randprime2048='openssl prime -generate -bits 2048'  #' Generate a random 2048-bit prime number
alias randhexprime2048='openssl prime -generate -bits 2048 -hex'  #' Generate a random 2048-bit prime number encoded in hexadecimal
alias randprime4096='openssl prime -generate -bits 4096'  #' Generate a random 4096-bit prime number
alias randhexprime4096='openssl prime -generate -bits 4096 -hex'  #' Generate a random 4096-bit prime number encoded in hexadecimal
alias randprime8192='openssl prime -generate -bits 8192'  #' Generate a random 8192-bit prime number
alias randhexprime8192='openssl prime -generate -bits 8192 -hex'  #' Generate a random 8192-bit prime number encoded in hexadecimal
alias randprime16384='openssl prime -generate -bits 16384'  #' Generate a random 16384-bit prime number
alias randhexprime16384='openssl prime -generate -bits 16384 -hex'  #' Generate a random 16384-bit prime number encoded in hexadecimal

# Random Digests

alias randb2s256='openssl rand ${OPENSSL_ENGINE:-} 8192 2>&1 | sed -E -e "s|engine .+||; /^$/d;" | openssl dgst -blake2s256 | cut -d " " -f 2'  #' Generate a random BLAKE2S256 hash
alias randgost='openssl rand ${OPENSSL_ENGINE:-} 8192 2>&1 | sed -E -e "s|engine .+||; /^$/d;" | openssl gost | cut -d " " -f 2'  #' Generate a random GOST hash
alias randmd4='openssl rand ${OPENSSL_ENGINE:-} 8192 2>&1 | sed -E -e "s|engine .+||; /^$/d;" | openssl dgst -md4 | cut -d " " -f 2'  #' Generate a random MD4 hash
alias randmd5='openssl rand ${OPENSSL_ENGINE:-} 8192 2>&1 | sed -E -e "s|engine .+||; /^$/d;" | openssl dgst -md5 | cut -d " " -f 2'  #' Generate a random MD5 hash
alias randrmd160='openssl rand ${OPENSSL_ENGINE:-} 8192 2>&1 | sed -E -e "s|engine .+||; /^$/d;" | openssl dgst -ripemd160 | cut -d " " -f 2'  #' Generate a random RIPEMD160 hash
alias randsha256='openssl rand ${OPENSSL_ENGINE:-} 8192 2>&1 | sed -E -e "s|engine .+||; /^$/d;" | openssl dgst -sha256 | cut -d " " -f 2'  #' Generate a random SHA256 hash
alias randsha512='openssl rand ${OPENSSL_ENGINE:-} 8192 2>&1 | sed -E -e "s|engine .+||; /^$/d;" | openssl dgst -sha512 | cut -d " " -f 2'  #' Generate a random SHA512 hash
alias randshake128='openssl rand ${OPENSSL_ENGINE:-} 8192 2>&1 | sed -E -e "s|engine .+||; /^$/d;" | openssl dgst -shake128 | cut -d " " -f 2'  #' Generate a random SHAKE128 hash
alias randshake256='openssl rand ${OPENSSL_ENGINE:-} 8192 2>&1 | sed -E -e "s|engine .+||; /^$/d;" | openssl dgst -shake256 | cut -d " " -f 2'  #' Generate a random SHAKE256 hash
alias randsm3='openssl rand ${OPENSSL_ENGINE:-} 8192 2>&1 | sed -E -e "s|engine .+||; /^$/d;" | openssl dgst -sm3 | cut -d " " -f 2'  #' Generate a random SM3 hash
alias randwhirlpool='openssl rand ${OPENSSL_ENGINE:-} 8192 2>&1 | sed -E -e "s|engine .+||; /^$/d;" | openssl dgst -whirlpool | cut -d " " -f 2'  #' Generate a random Whirlpool hash

# Miscellaneous

alias CryptoCurves='openssl ecparam -list_curves'  #' List available OpenSSL elliptic-curves
alias cryptoisprime='openssl prime'  #' Test if the given number is prime
alias cryptoishexprime='openssl prime -hex'  #' Test if the given hexadecimal number is prime
alias cryptpswd='openssl passwd'  #' Generate a random crypt-style password
alias shadowpswd='openssl passwd -1'  #' Generate a random shadow-style password
alias lsciphers='openssl list -cipher-commands && openssl list -cipher-algorithms'  #' List all supported OpenSSL ciphers
alias lscryptocurves='openssl ecparam -list_curves'  #' List available OpenSSL elliptic-curves
alias lsdigests='openssl list -digest-commands && openssl list -digest-algorithms'  #' List all supported OpenSSL digests
alias lspublickeys='openssl list -public-key-algorithms'  #' List all supported OpenSSL public-key types
alias opensslbm='openssl speed'  #' Benchmark for OpenSSL


fi  # command -v openssl


# CRYPTOGRAPHIC FUNCTIONS #


if [ -x "$(command -v openssl)" ]; then


if [ -r /dev/urandom ]; then
    #' Generate a random string using the specified number of bytes retrieved from /dev/urandom
    #' @param[in] $1 The number of bytes desired in the random string
    CryptoRandStr() { head -c "$1" /dev/urandom | openssl enc -base64; }
fi


#' Function used to select an encryption type based on the provided input string
#' @param[in] $1 The desired encryption type
_enctype_input() {
    case "${1:-}" in
        # AES
        'aes-128-cbc') enctype='-aes-128-cbc';;
        'aes-128-ecb' | 'aes-128') enctype='-aes-128-ecb';;
        'aes-192-cbc') enctype='-aes-192-cbc';;
        'aes-192-ecb' | 'aes-192') enctype='-aes-192-ecb';;
        'aes-256-cbc') enctype='-aes-256-cbc';;
        'aes-256-ecb' | 'aes-256' | 'aes') enctype='-aes-256-ecb';;
        # ARIA
        'aria-128-cbc') enctype='-aria-128-cbc';;
        'aria-128-cfb') enctype='-aria-128-cfb';;
        'aria-128-cfb1') enctype='-aria-128-cfb1';;
        'aria-128-cfb8') enctype='-aria-128-cfb8';;
        'aria-128-ctr') enctype='-aria-128-ctr';;
        'aria-128-ecb' | 'aria-128') enctype='-aria-128-ecb';;
        'aria-128-ofb') enctype='-aria-128-ofb';;
        'aria-192-cbc') enctype='-aria-192-cbc';;
        'aria-192-cfb') enctype='-aria-192-cfb';;
        'aria-192-cfb1') enctype='-aria-192-cfb1';;
        'aria-192-cfb8') enctype='-aria-192-cfb8';;
        'aria-192-ctr') enctype='-aria-192-ctr';;
        'aria-192-ecb' | 'aria-192') enctype='-aria-192-ecb';;
        'aria-192-ofb') enctype='-aria-192-ofb';;
        'aria-256-cbc') enctype='-aria-256-cbc';;
        'aria-256-cfb') enctype='-aria-256-cfb';;
        'aria-256-cfb1') enctype='-aria-256-cfb1';;
        'aria-256-cfb8') enctype='-aria-256-cfb8';;
        'aria-256-ctr') enctype='-aria-256-ctr';;
        'aria-256-ecb' | 'aria-256' | 'aria') enctype='-aria-256-ecb';;
        'aria-256-ofb') enctype='-aria-256-ofb';;
        # BLOWFISH
        'bf-cbc' | 'blowfish-cbc') enctype='-bf-cbc';;
        'bf-cfb' | 'blowfish-cfb') enctype='-bf-cfb';;
        'bf-ecb' | 'blowfish-ecb' | 'bf' | 'blowfish') enctype='-bf-ecb';;
        'bf-ofb' | 'blowfish-ofb') enctype='-bf-ofb';;
        # CAMELLIA
        'camellia-128-cbc') enctype='-camellia-128-cbc';;
        'camellia-128-ecb' | 'camellia-128') enctype='-camellia-128-ecb';;
        'camellia-192-cbc') enctype='-camellia-192-cbc';;
        'camellia-192-ecb' | 'camellia-192') enctype='-camellia-192-ecb';;
        'camellia-256-cbc') enctype='-camellia-256-cbc';;
        'camellia-256-ecb' | 'camellia-256' | 'camellia') enctype='-camellia-256-ecb';;
        # CAST
        'cast-cbc') enctype='-cast-cbc';;
        # CAST5
        'cast5-cbc') enctype='-cast5-cbc';;
        'cast5-cfb') enctype='-cast5-cfb';;
        'cast5-ecb' | 'cast' | 'cast5') enctype='-cast5-ecb';;
        'cast5-ofb') enctype='-cast5-ofb';;
        # CHACHA
        'chacha20' | 'chacha') enctype='-chacha20';;
        # DES3
        'des-ede3-cbc' | 'des3' | 'des-ede3') enctype='-des-ede3-cbc';;
        'des-ede3-cfb') enctype='-des-ede3-cfb';;
        'des-ede3-ofb') enctype='-des-ede3-ofb';;
        'desx-cbc' | 'desx') enctype='-desx-cbc';;
        # RC2
        'rc2-cbc') enctype='-rc2-cbc';;
        'rc2-cfb') enctype='-rc2-cfb';;
        'rc2-ecb' | 'rc2') enctype='-rc2-ecb';;
        'rc2-ofb') enctype='-rc2-ofb';;
        # SM4
        'sm4-cbc') enctype='-sm4-cbc';;
        'sm4-cfb') enctype='-sm4-cfb';;
        'sm4-ctr') enctype='-sm4-ctr';;
        'sm4-ecb' | 'sm4') enctype='-sm4-ecb';;
        'sm4-ofb') enctype='-sm4-ofb';;
        *) enctype='-aes-256-ecb';;
    esac
    echo "${enctype}"
}


#' Encrypt the file using the specified encryption type
#' @param[in] $1 The file to encrypt
#' @param[in] $2 The encryption type (Optional); the default is AES-256
encrypt() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: No parameters were given!\n' >&2
    elif [ ! -f "${1:-}" ]; then
        printf 'ERROR: The first parameter must be a file!\n' >&2
    else
        enctype="$(_enctype_input "${1:-}")"
        openssl enc -a -A -pbkdf2 -e "${enctype}" -in "${1}"
    fi
}


#' Decrypt the file using the specified encryption type
#' @param[in] $1 The file to encrypt
#' @param[in] $2 The encryption type (Optional); the default is AES-256
decrypt() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: No parameters were given!\n' >&2
    elif [ ! -f "${1:-}" ]; then
        printf 'ERROR: The first parameter must be a file!\n' >&2
    else
        enctype="$(_enctype_input "${1:-}")"
        openssl enc -a -A -pbkdf2 -d "${enctype}" -in "${1}"
    fi
}


#' Convert a PKCS8 file to a traditional encrypted EC format; The new file will have `ecx_` prepended to the filename
#' @param[in] $1 The private elliptic-curve key file to convert
#' @param[in] $2 The encryption type (Optional); the default is Blowfish-OFB
pkcs8_2_encrypted_ec() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: No parameters were given!\n' >&2
    elif [ ! -f "${1:-}" ]; then
        printf 'ERROR: The first parameter must be a file!\n' >&2
    else
        if [ -z "${2:-}" ]; then
            enctype="$(_enctype_input "-bf-ofb")"
        else
            enctype="$(_enctype_input "${2:-}")"
        fi
        openssl ec "${enctype}" -in "${1:-}" -out "ecx_$(printf '%s' "${1##*/}" | sed -E -e "s|^ec_||;")"
    fi
}


#' Convert an encrypted EC formatted file to a PKCS8 file; The new file will have `ec_` prepended to the filename
#' @param[in] $1 The private PKCS8 key file to convert
encrypted_ec_2_pkcs8() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: No parameters were given!\n' >&2
    elif [ ! -f "${1:-}" ]; then
        printf 'ERROR: The first parameter must be a file!\n' >&2
    else
        openssl ec -in "${1:-}" -out "ec_$(printf '%s' "${1##*/}" | sed -E -e "s|^ecx_||;")"
    fi
}


#' Create the public key from the given private elliptic-curve key
#' @param[in] $1 The private elliptic-curve key
ecpub() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: No parameters were given!\n' >&2
    elif [ ! -f "${1:-}" ]; then
        printf 'ERROR: The first parameter must be a file!\n' >&2
    else
        filename="${1##*/}"
        openssl ec -in "${1:-}" -pubout -out "${filename/_pri.pem/}_pub.pem"
    fi
}


#' Create an elliptic-curve key-pair and an encrypted version of the private key
#' @param[in] $1 The type of elliptic-curve
#' @param[in] $2 The type of encryption (Optional)
geneckeys() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: No parameters were given!\n' >&2
    else
        # shellcheck disable=SC2086
        openssl ecparam ${OPENSSL_ENGINE:-} -outform PEM -name ${1} -genkey -out "ec_${1:-}_pri.pem" 2>&1 | sed -E -e "s|engine .+||; /^$/d;" || return 1
        if [ -z "${2:-}" ]; then
            enctype="$(_enctype_input "bf-ofb")"
        else
            enctype="$(_enctype_input "${2:-}")"
        fi
        openssl ec "${enctype}" -in "ec_${1:-}_pri.pem" -out "ecx_${1:-}_pub.pem" || return 1
        openssl ec -in "ec_${1:-}_pri.pem" -pubout -out "ec_${1:-}_pub.pem" || return 1
    fi
}


#' Create an X509 certificate (The private key, public key, and a special copy for a server)
#' @param[in] $1 The type of elliptic-curve
#' @param[in] $2 The expiration time in days
mkx509() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: No parameters were given!\n' >&2
    elif [ -z "${2:-}" ]; then
        printf 'ERROR: The second parameter is missing!\n' >&2
    else
        # shellcheck disable=SC2086
        openssl ecparam ${OPENSSL_ENGINE:-} -outform PEM -param_enc explicit -name ${1} -genkey -out x509_pri.pem 2>&1 | sed -E -e "s|engine .+||; /^$/d;"
        openssl req -new -x509 -key x509_pri.pem -out x509_pub.pem -days "${2}"
        cat x509_pri.pem x509_pub.pem > x509_server.pem
    fi
}


#' Generate a 1024-bit public RSA key from the specified private key or generate a new private key if none is given
#' @param[in] $1 The private key file
#' @param[in] $2 The generated public key
rsa1024pub() {
    if [ -z "${1:-}" ]; then
        openssl genrsa -out rsa1024pri.pem 1024 && openssl rsa -in rsa1024pri.pem -pubout -out rsa1024pub.pem
    elif [ -f "${1}" ] && [ -r "${1}" ]; then
        if [ -z "${2:-}" ]; then
            outputfile='rsa1024pub.pem'
        else
            outputfile="${2:-}"
        fi
        openssl rsa  -in "${1}" -pubout > "$outputfile"
    else
        printf 'ERROR: The specified pathname is not a readable file!\n' >&2
    fi
}


#' Generate a 2048-bit public RSA key from the specified private key or generate a new private key if none is given
#' @param[in] $1 The private key file
#' @param[in] $2 The generated public key
rsa2048pub() {
    if [ -z "${1:-}" ]; then
        openssl genrsa -out rsa2048pri.pem 2048 && openssl rsa -in rsa2048pri.pem -pubout -out rsa2048pub.pem
    elif [ -f "${1}" ] && [ -r "${1}" ]; then
        if [ -z "${2:-}" ]; then
            outputfile='rsa2048pub.pem'
        else
            outputfile="${2:-}"
        fi
        openssl rsa -in "${1}" -pubout > "$outputfile"
    else
        printf 'ERROR: The specified pathname is not a readable file!\n' >&2
    fi
}


#' Generate a 4096-bit public RSA key from the specified private key or generate a new private key if none is given
#' @param[in] $1 The private key file
#' @param[in] $2 The generated public key
rsa4096pub() {
    if [ -z "${1:-}" ]; then
        openssl genrsa -out rsa4096pri.pem 4096 && openssl rsa -in rsa4096pri.pem -pubout -out rsa4096pub.pem
    elif [ -f "${1}" ] && [ -r "${1}" ]; then
        if [ -z "${2:-}" ]; then
            outputfile='rsa4096pub.pem'
        else
            outputfile="${2:-}"
        fi
        openssl rsa -in "${1}" -pubout > "$outputfile"
    else
        printf 'ERROR: The specified pathname is not a readable file!\n' >&2
    fi
}


#' Generate a 8192-bit public RSA key from the specified private key or generate a new private key if none is given
#' @param[in] $1 The private key file
#' @param[in] $2 The generated public key
rsa8192pub() {
    if [ -z "${1:-}" ]; then
        openssl genrsa -out rsa8192pri.pem 8192 && openssl rsa -in rsa8192pri.pem -pubout -out rsa8192pub.pem
    elif [ -f "${1}" ] && [ -r "${1}" ]; then
        if [ -z "${2:-}" ]; then
            outputfile='rsa8192pub.pem'
        else
            outputfile="${2:-}"
        fi
        openssl rsa -in "${1}" -pubout > "$outputfile"
    else
        printf 'ERROR: The specified pathname is not a readable file!\n' >&2
    fi
}


#' Generate a 16384-bit public RSA key from the specified private key or generate a new private key if none is given
#' @param[in] $1 The private key file
#' @param[in] $2 The generated public key
rsa16384pub() {
    if [ -z "${1:-}" ]; then
        openssl genrsa -out rsa16384pri.pem 16384 && openssl rsa -in rsa16384pri.pem -pubout -out rsa16384pub.pem
    elif [ -f "${1}" ] && [ -r "${1}" ]; then
        if [ -z "${2:-}" ]; then
            outputfile='rsa16384pub.pem'
        else
            outputfile="${2:-}"
        fi
        openssl rsa -in "${1}" -pubout > "$outputfile"
    else
        printf 'ERROR: The specified pathname is not a readable file!\n' >&2
    fi
}


#' Generate a new password-protected private key file and a 1024-bit public RSA key file in the current directory
#' @param[in] $1 The type of encryption (Optional); the default is AES-256
rsapswd1024() {
    enctype="$(_enctype_input "${1:-}")"
    read -p 'RSA Password: ' -s -r scrtpswd
    clear
    openssl genrsa "${enctype}" -passout pass:"${scrtpswd}" -out rsa1024pri.pem 1024 && openssl rsa -passin pass:"${scrtpswd}" -in rsa1024pri.pem -pubout -out rsa1024pub.pem
    unset enctype scrtpswd
    clear
}


#' Generate a new password-protected private key file and a 2048-bit public RSA key file in the current directory
#' @param[in] $1 The type of encryption (Optional); the default is AES-256
rsapswd2048() {
    enctype="$(_enctype_input "${1:-}")"
    read -p 'RSA Password: ' -s -r scrtpswd
    clear
    openssl genrsa "${enctype}" -passout pass:"${scrtpswd}" -out rsa2048pri.pem 2048 && openssl rsa -passin pass:"${scrtpswd}" -in rsa2048pri.pem -pubout -out rsa2048pub.pem
    unset enctype scrtpswd
    clear
}


#' Generate a new password-protected private key file and a 4096-bit public RSA key file in the current directory
#' @param[in] $1 The type of encryption (Optional); the default is AES-256
rsapswd4096() {
    enctype="$(_enctype_input "${1:-}")"
    read -p 'RSA Password: ' -s -r scrtpswd
    clear
    openssl genrsa "${enctype}" -passout pass:"${scrtpswd}" -out rsa4096pri.pem 4096 && openssl rsa -passin pass:"${scrtpswd}" -in rsa4096pri.pem -pubout -out rsa4096pub.pem
    unset enctype scrtpswd
    clear
}


#' Generate a new password-protected private key file and a 8192-bit public RSA key file in the current directory
#' @param[in] $1 The type of encryption (Optional); the default is AES-256
rsapswd8192() {
    enctype="$(_enctype_input "${1:-}")"
    read -p 'RSA Password: ' -s -r scrtpswd
    clear
    openssl genrsa "${enctype}" -passout pass:"${scrtpswd}" -out rsa8192pri.pem 8192 && openssl rsa -passin pass:"${scrtpswd}" -in rsa8192pri.pem -pubout -out rsa8192pub.pem
    unset enctype scrtpswd
    clear
}


#' Generate a new password-protected private key file and a 16384-bit public RSA key file in the current directory
#' @param[in] $1 The type of encryption (Optional); the default is AES-256
rsapswd16384() {
    enctype="$(_enctype_input "${1:-}")"
    read -p 'RSA Password: ' -s -r scrtpswd
    clear
    openssl genrsa "${enctype}" -passout pass:"${scrtpswd}" -out rsa16384pri.pem 16384 && openssl rsa -passin pass:"${scrtpswd}" -in rsa16384pri.pem -pubout -out rsa16384pub.pem
    unset enctype scrtpswd
    clear
}


#' Make a file containing random Base64 data; The filename will be the MD5 checksum of the contents and the filesize will be 5500 bytes
#' @param[in] $1 The name of the file to generate containing random data
mkrandfile() {
    if [ -z "${1:-}" ] && [ -d "./" ] && [ -w "./" ]; then
        fdata="$(openssl rand -base64 4096)"
        fname="$(echo "${fdata}" | openssl dgst -md5 | cut -d " " -f 2)"
        echo "${fdata}" > "./${fname}"
    elif [ -d "${1}" ] && [ -w "${1}" ]; then
        fdata="$(openssl rand -base64 4096)"
        fname="$(echo "${fdata}" | openssl dgst -md5 | cut -d " " -f 2)"
        [[ ! "${1}" =~ ^.+/$ ]] && fname="/${fname}"
        echo "${fdata}" > "${1}${fname}"
    else
        printf 'ERROR: The specified path is not a directory!\n' >&2
    fi
}


fi  # command -v openssl


if [ -x "$(command -v openssl)" ]; then

    #' Create BSD-style checksum files for the whole directory structure
    #' @param[in] $1 The directory path to checksum
    genchecksums() {
        if [ -z "${1:-}" ]; then
            FOLDER='./'
        elif [ -d "${1}" ]; then
            FOLDER="${1}"
        else
            printf 'ERROR: The specified path is not a directory!\n' >&2
        fi
        if [ -n "${FOLDER:-}" ]; then
            if [[ ! "$FOLDER" =~ ^.+/$ ]]; then
                FOLDER="${FOLDER}/"
            fi
            find "${FOLDER}" -mount -type f -not -name 'checksums.md5' -print0 | xargs -0 openssl dgst -md5 > "${FOLDER}checksums.md5"
            find "${FOLDER}" -mount -type f -not -name 'checksums.sha1' -print0 | xargs -0 openssl dgst -sha1 > "${FOLDER}checksums.sha1"
            find "${FOLDER}" -mount -type f -not -name 'checksums.sha224' -print0 | xargs -0 openssl dgst -sha224 > "${FOLDER}checksums.sha224"
            find "${FOLDER}" -mount -type f -not -name 'checksums.sha384' -print0 | xargs -0 openssl dgst -sha384 > "${FOLDER}checksums.sha384"
            find "${FOLDER}" -mount -type f -not -name 'checksums.sha512' -print0 | xargs -0 openssl dgst -sha512 > "${FOLDER}checksums.sha512"
            find "${FOLDER}" -mount -type f -not -name 'checksums.b512' -print0 | xargs -0 openssl dgst -blake2b512 > "${FOLDER}checksums.b512"
        fi

    }

elif [ -x "$(command -v md5sum)" ] && [ -x "$(command -v sha512sum)" ]; then

    #' Create BSD-style checksum files for the whole directory structure
    #' @param[in] $1 The directory path to checksum
    genchecksums() {
        if [ -z "${1:-}" ]; then
            FOLDER='./'
        elif [ -d "${1}" ]; then
            FOLDER="${1}"
        else
            printf 'ERROR: The specified path is not a directory!\n' >&2
        fi
        if [ -n "${FOLDER:-}" ]; then
            if [[ ! "$FOLDER" =~ ^.+/$ ]]; then
                FOLDER="${FOLDER}/"
            fi
            find "${FOLDER}" -mount -type f -not -name 'checksums.md5' -print0 | xargs -0 md5sum --tag > "${FOLDER}checksums.md5"
            find "${FOLDER}" -mount -type f -not -name 'checksums.sha1' -print0 | xargs -0 sha1sum --tag > "${FOLDER}checksums.sha1"
            find "${FOLDER}" -mount -type f -not -name 'checksums.sha224' -print0 | xargs -0 sha224sum --tag > "${FOLDER}checksums.sha224"
            find "${FOLDER}" -mount -type f -not -name 'checksums.sha384' -print0 | xargs -0 sha384sum --tag > "${FOLDER}checksums.sha384"
            find "${FOLDER}" -mount -type f -not -name 'checksums.sha512' -print0 | xargs -0 sha512sum --tag > "${FOLDER}checksums.sha512"
            if [ -x "$(command -v b2sum)" ]; then
                find "${FOLDER}" -mount -type f -not -name 'checksums.b512' -print0 | xargs -0 b2sum --tag > "${FOLDER}checksums.b512"
            fi
        fi
    }

    #' Validate checksum files in the specified directory
    #' @param[in] $1 The directory path to validate
    valchecksums() {
        if [ -z "${1:-}" ]; then
            FOLDER='./'
        elif [ -d "${1}" ]; then
            FOLDER="${1}"
        else
            printf 'ERROR: The specified path is not a directory!\n' >&2
        fi
        if [ -n "${FOLDER:-}" ]; then
            if [[ ! "$FOLDER" =~ ^.+/$ ]]; then
                FOLDER="${FOLDER}/"
            fi
            md5sum --check --quiet --strict "${FOLDER}checksums.md5"
            sha1sum --check --quiet --strict "${FOLDER}checksums.sha1"
            sha224sum --check --quiet --strict "${FOLDER}checksums.sha224"
            sha384sum --check --quiet --strict "${FOLDER}checksums.sha384"
            sha512sum --check --quiet --strict "${FOLDER}checksums.sha512"
            if [ -x "$(command -v b2sum)" ]; then
                b2sum --check --quiet --strict "${FOLDER}checksums.b512"
            fi
        fi
    }

fi


if [ -x "$(command -v gpg)" ]; then

    #' Produce a GPG key pair
    #' @param[in] $1 The name of the GPG key without the file extension
    gengpg() {
        # Create Private Key
        gpg --full-gen-key
        # Verify Presence of Private Key
        if [ -z "${1:-}" ] || [ ! -r "${1}" ]; then
            printf 'ERROR: The specified GPG name does not exist!\n' >&2
        else
            # Create Public Key
            gpg -a --output "${HOME}/.gnupg/${1}.gpg" --export "${1}"
            gpg --import "${HOME}/.gnupg/${1}.gpg"
        fi
    }

fi


if [ -x "$(command -v ssh-keygen)" ] && [ -x "$(command -v ssh-add)" ]; then

    #' Produce an 8192-bit RSA SSH key pair
    gensshkey() {
        # Create Key Pair
        ssh-keygen -b 8192 -t rsa -C 'General SSH Key' -f ~/.ssh/general_ssh
        # Add Key to SSH-Agent
        ssh-add ~/.ssh/general_ssh
    }


    #' Produce the id_rsa SSH key files as an 8192-bit RSA SSH key pair
    gensshrsakey() {
        # Create Key Pair
        ssh-keygen -b 8192 -t rsa -C 'Standard SSH Key' -f ~/.ssh/id_rsa
        # Add Key to SSH-Agent
        ssh-add ~/.ssh/id_rsa
    }

fi

#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Shell RC script providing cryptograhpic aliases & functions
#' @file crypto_rc.sh
#' @version 2018.10.13
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

alias brainpool512='openssl ecparam ${OPENSSL_ENGINE:-} -name brainpoolP512t1 -genkey'  #' Generate an elliptic-curve key (brainpoolP512t1)
alias c2tnb431r1='openssl ecparam ${OPENSSL_ENGINE:-} -name c2tnb431r1 -genkey'  #' Generate an elliptic-curve key (c2tnb431r1)
alias prime256='openssl ecparam ${OPENSSL_ENGINE:-} -name prime256v1 -genkey'  #' Generate an elliptic-curve key (prime256v1)
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
alias secp521='openssl ecparam ${OPENSSL_ENGINE:-} -name secp521r1 -genkey'  #' Generate an elliptic-curve key (secp521r1)
alias sect571k1='openssl ecparam ${OPENSSL_ENGINE:-} -name sect571k1 -genkey'  #' Generate an elliptic-curve key (sect571k1)
alias sect571r1='openssl ecparam ${OPENSSL_ENGINE:-} -name sect571r1 -genkey'  #' Generate an elliptic-curve key (sect571r1)
alias wtls12='openssl ecparam ${OPENSSL_ENGINE:-} -name wap-wsg-idm-ecid-wtls12 -genkey'  #' Generate an elliptic-curve key (wap-wsg-idm-ecid-wtls12)

# Digests

alias b2s256='openssl dgst -blake2s256'  #' Produce the Blake2S256 checksum for the given data
alias gost='openssl dgst -gost'  #' Produce the GOST checksum for the given data
alias md2='openssl dgst -md2'  #' Produce the MD2 checksum for the given data
alias md4='openssl dgst -md4'  #' Produce the MD4 checksum for the given data
alias mdc2='openssl dgst -mdc2'  #' Produce the MD5 checksum for the given data
alias rmd160='openssl dgst -rmd160'  #' Produce the RMD160 checksum for the given data

# Random

alias rand4096base64='openssl rand ${OPENSSL_ENGINE:-} -base64 4096'  #' Generate 4096 bytes of base64-encoded random data
alias randbase64='openssl rand ${OPENSSL_ENGINE:-} -base64'  #' Generate base64-encoded random data (specify the number of random bytes to generate)
alias randbin1024='openssl rand ${OPENSSL_ENGINE:-} 1024'  #' Generate 1024 bytes of random data
alias randbin2048='openssl rand ${OPENSSL_ENGINE:-} 2048'  #' Generate 2048 bytes of random data
alias randbin4096='openssl rand ${OPENSSL_ENGINE:-} 4096'  #' Generate 4096 bytes of random data
alias randbin8192='openssl rand ${OPENSSL_ENGINE:-} 8192'  #' Generate 8192 bytes of random data
alias randbin16384='openssl rand ${OPENSSL_ENGINE:-} 16384'  #' Generate 16384 bytes of random data
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

# Random Digest
alias randb2s256='openssl rand ${OPENSSL_ENGINE:-} 8192 | openssl dgst -blake2s256 | cut -d " " -f 2'  #' Generate a random BLAKE2S256 hash
alias randmd4='openssl rand ${OPENSSL_ENGINE:-} 8192 | openssl dgst -md4 | cut -d " " -f 2'  #' Generate a random MD4 hash
alias randmd5='openssl rand ${OPENSSL_ENGINE:-} 8192 | openssl dgst -md5 | cut -d " " -f 2'  #' Generate a random MD5 hash
alias randsha256='openssl rand ${OPENSSL_ENGINE:-} 8192 | openssl dgst -sha256 | cut -d " " -f 2'  #' Generate a random SHA256 hash
alias randsha512='openssl rand ${OPENSSL_ENGINE:-} 8192 | openssl dgst -sha512 | cut -d " " -f 2'  #' Generate a random SHA512 hash

# Miscellaneous

alias CryptoCurves='openssl ecparam -list_curves'  #' List available elliptic-curves
alias cryptoisprime='openssl prime'  #' Test if the given number is prime
alias cryptoishexprime='openssl prime -hex'  #' Test if the given hexadecimal number is prime
alias cryptpswd='openssl passwd'  #' Generate a random crypt-style password
alias shadowpswd='openssl passwd -1'  #' Generate a random shadow-style password


fi  # command -v openssl


# CRYPTOGRAPHIC FUNCTIONS #


if [ -x "$(command -v openssl)" ]; then


if [ -r /dev/urandom ]; then
    #' Generate a random string using the specified number of bytes retrieved from /dev/urandom
    CryptoRandStr() { head -c "$1" /dev/urandom | openssl enc -base64; }
fi


#' Generate a 1024-bit public RSA key from the specified private key or generate a new private key if none is given
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


#' Generate a new password-protect new private key fle and a 1024-bit public RSA key file in the current directory
rsapswd1024() {
    case "$1" in
        'aria') enctype='-aria256';;
        'camellia') enctype='-camellia256';;
        'des' | 'des3') enctype='-des3';;
        'idea') enctype='-idea';;
        *) enctype='-aes256';;
    esac
    read -p 'RSA Password: ' -s -r scrtpswd
    clear
    openssl genrsa "${enctype}" -passout pass:"${scrtpswd}" -out rsa1024pri.pem 1024 && openssl rsa -passin pass:"${scrtpswd}" -in rsa1024pri.pem -pubout -out rsa1024pub.pem
    unset enctype scrtpswd
    clear
}


#' Generate a new password-protect new private key fle and a 2048-bit public RSA key file in the current directory
rsapswd2048() {
    case "$1" in
        'aria') enctype='-aria256';;
        'camellia') enctype='-camellia256';;
        'des' | 'des3') enctype='-des3';;
        'idea') enctype='-idea';;
        *) enctype='-aes256';;
    esac
    read -p 'RSA Password: ' -s -r scrtpswd
    clear
    openssl genrsa "${enctype}" -passout pass:"${scrtpswd}" -out rsa2048pri.pem 2048 && openssl rsa -passin pass:"${scrtpswd}" -in rsa2048pri.pem -pubout -out rsa2048pub.pem
    unset enctype scrtpswd
    clear
}


#' Generate a new password-protect new private key fle and a 4096-bit public RSA key file in the current directory
rsapswd4096() {
    case "$1" in
        'aria') enctype='-aria256';;
        'camellia') enctype='-camellia256';;
        'des' | 'des3') enctype='-des3';;
        'idea') enctype='-idea';;
        *) enctype='-aes256';;
    esac
    read -p 'RSA Password: ' -s -r scrtpswd
    clear
    openssl genrsa "${enctype}" -passout pass:"${scrtpswd}" -out rsa4096pri.pem 4096 && openssl rsa -passin pass:"${scrtpswd}" -in rsa4096pri.pem -pubout -out rsa4096pub.pem
    unset enctype scrtpswd
    clear
}


#' Generate a new password-protect new private key fle and a 8192-bit public RSA key file in the current directory
rsapswd8192() {
    case "$1" in
        'aria') enctype='-aria256';;
        'camellia') enctype='-camellia256';;
        'des' | 'des3') enctype='-des3';;
        'idea') enctype='-idea';;
        *) enctype='-aes256';;
    esac
    read -p 'RSA Password: ' -s -r scrtpswd
    clear
    openssl genrsa "${enctype}" -passout pass:"${scrtpswd}" -out rsa8192pri.pem 8192 && openssl rsa -passin pass:"${scrtpswd}" -in rsa8192pri.pem -pubout -out rsa8192pub.pem
    unset enctype scrtpswd
    clear
}


#' Generate a new password-protect new private key fle and a 16384-bit public RSA key file in the current directory
rsapswd16384() {
    case "$1" in
        'aria') enctype='-aria256';;
        'camellia') enctype='-camellia256';;
        'des' | 'des3') enctype='-des3';;
        'idea') enctype='-idea';;
        *) enctype='-aes256';;
    esac
    read -p 'RSA Password: ' -s -r scrtpswd
    clear
    openssl genrsa "${enctype}" -passout pass:"${scrtpswd}" -out rsa16384pri.pem 16384 && openssl rsa -passin pass:"${scrtpswd}" -in rsa16384pri.pem -pubout -out rsa16384pub.pem
    unset enctype scrtpswd
    clear
}


#' Make a file containing random Base64 data; The filename will be the MD5 checksum of the contents and the filesize will be 5500 bytes
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

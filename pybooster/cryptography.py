#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""@brief Various cryptography functions
@file cryptography.py
@package pybooster.cryptography
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@version 2016.03.20

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

The PyBooster Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.
"""


from itertools import cycle


__all__ = [
    # FUNCTIONS
    'encrypt_xor',
    'decrypt_xor',
    'encrypt_xor_bytes_key_str',
    'decrypt_xor_str_key_bytes',
    'decrypt_xor_str_key_str',
    'encrypt_xor_str_key_bytes',
    'decrypt_xor_bytes_key_bytes',
    'decrypt_xor_bytes_key_str',
]


# FUNCTIONS


def encrypt_xor(_data: bytes) -> bytearray:
    """XOR Encryption

    Return the encrypted data as a bytearray
    Decrypt with decrypt_xor()
    """
    return bytearray([b ^ 0xA8 for b in bytearray(_data)])


def decrypt_xor(_data: bytearray) -> str:
    """XOR Decryption

    Return the decrypted data as a str
    Encrypt with encrypt_xor()
    """
    return str(bytearray([b ^ 0xA8 for b in bytearray(_data)]), 'utf-8')


def encrypt_xor_bytes_key_str(_data: bytes, _key: str) -> str:
    """XOR encryption with custom key

    Encrypt the bytes and return the data as a str
    Decrypt with decrypt_xor_str_key_bytes()
    """
    return ''.join(chr(a ^ ord(b)) for (a, b) in zip(_data, cycle(_key)))


def decrypt_xor_str_key_bytes(_data: str, _key: str) -> bytes:
    """XOR decryption with custom key

    Decrypt the str and return the data as bytes
    Encrypt with encrypt_xor_bytes_key_str()
    """
    return ''.join(chr(a ^ ord(b)) for (a, b) in zip(_data.encode('utf-8'), cycle(_key))).encode('utf-8')


def decrypt_xor_str_key_str(_data: str, _key: str) -> str:
    """XOR decryption with custom key

    Decrypt the str and return the data as a str
    Encrypt with encrypt_xor_bytes_key_str()
    """
    return ''.join(chr(a ^ ord(b)) for (a, b) in zip(_data.encode('utf-8'), cycle(_key)))


def encrypt_xor_str_key_bytes(_data: str, _key: str) -> bytes:
    """XOR encryption with custom key

    Return the encrypted str data as bytes
    Encrypt the str and return the data as bytes
    Decrypt with decrypt_xor_bytes_key_bytes() or decrypt_xor_bytes_key_str()
    """
    return ''.join(chr(a ^ ord(b)) for (a, b) in zip(_data.encode('utf-8'), cycle(_key))).encode('utf-8')


def decrypt_xor_bytes_key_bytes(_data: bytes, _key: str) -> bytes:
    """XOR decryption with custom key

    Decrypt the bytes and return the data as bytes
    Encrypt with encrypt_xor_str_key_bytes()
    """
    return ''.join(chr(a ^ ord(b)) for (a, b) in zip(_data, cycle(_key))).encode('utf-8')


def decrypt_xor_bytes_key_str(_data: bytes, _key: str) -> str:
    """XOR decryption with custom key

    Decrypt the bytes and return the data as a str
    Encrypt with encrypt_xor_str_key_bytes()
    """
    return ''.join(chr(a ^ ord(b)) for (a, b) in zip(_data, cycle(_key)))

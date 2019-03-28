#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Various cryptography functions

@file cryptography.py
@package pybooster.cryptography
@version 2019.03.28
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This software is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
"""


from binascii import crc32, crc_hqx
from hashlib import md5
from itertools import cycle


__all__: list = [
    # ENCRYPTION/DECRYPTION #
    r'encrypt_xor',
    r'decrypt_xor',
    r'encrypt_xor_bytes_key_str',
    r'decrypt_xor_str_key_bytes',
    r'encrypt_xor_str_key_str',
    r'decrypt_xor_str_key_str',
    r'encrypt_xor_str_key_bytes',
    r'decrypt_xor_bytes_key_bytes',
    r'decrypt_xor_bytes_key_str',
    # CHECKSUMS #
    r'md5sum',
    r'get_checksums'
]


# ENCRYPTION/DECRYPTION #


def encrypt_xor(_data: str) -> bytearray:
    r"""Return the xor-encrypted data (of the given string) as a bytearray; Decrypt with decrypt_xor()

    >>> encrypt_xor(r'This is a test.')
    bytearray(b'\xfc\xc0\xc1\xdb\x88\xc1\xdb\x88\xc9\x88\xdc\xcd\xdb\xdc\x86')
    """
    return bytearray([_bytes ^ 0xA8 for _bytes in bytearray(bytes(_data, encoding=r'utf-8'))])


def decrypt_xor(_data: bytearray) -> str:
    r"""Return the xor-decrypted data (of the given byte-array) as a string; Encrypt with encrypt_xor()

    >>> decrypt_xor(bytearray(b'\xfc\xc0\xc1\xdb\x88\xc1\xdb\x88\xc9\x88\xdc\xcd\xdb\xdc\x86'))
    'This is a test.'
    """
    return str(bytearray([_bytes ^ 0xA8 for _bytes in bytearray(_data)]), r'utf-8')


def encrypt_xor_bytes_key_str(_data: bytes, _key: str) -> str:
    r"""XOR-Encrypt the bytes using the given key and return the data as a string; Decrypt with decrypt_xor_str_key_bytes()

    >>> encrypt_xor_bytes_key_str(br'This is a test.', r'Coffee')
    '\x17\x07\x0f\x15E\x0c0O\x07F\x11\x000\x1bH'
    """
    return r''.join(chr(a ^ ord(b)) for (a, b) in zip(_data, cycle(_key)))


def decrypt_xor_str_key_bytes(_data: str, _key: str) -> bytes:
    r"""XOR-Decrypt the string using the given key and return the data as bytes; Encrypt with encrypt_xor_bytes_key_str()

    >>> decrypt_xor_str_key_bytes('\x17\x07\x0f\x15E\x0c0O\x07F\x11\x000\x1bH', r'Coffee')
    b'This is a test.'
    """
    return r''.join(chr(a ^ ord(b)) for (a, b) in zip(_data.encode(r'utf-8'), cycle(_key))).encode(r'utf-8')


def encrypt_xor_str_key_str(_data: str, _key: str) -> str:
    r"""XOR-Encrypt the string using the given key and return the data as a string; Decrypt with decrypt_xor_str_key_bytes()

    >>> encrypt_xor_str_key_str(r'This is a test.', r'Coffee')
    '\x17\x07\x0f\x15E\x0c0O\x07F\x11\x000\x1bH'
    """
    return r''.join(chr(a ^ ord(b)) for (a, b) in zip(bytes(_data, encoding=r'utf-8'), cycle(_key)))


def decrypt_xor_str_key_str(_data: str, _key: str) -> str:
    r"""XOR-Decrypt the string using the given key and return the data as a string; Encrypt with encrypt_xor_str_key_str()

    >>> decrypt_xor_str_key_str('\x17\x07\x0f\x15E\x0c0O\x07F\x11\x000\x1bH', r'Coffee')
    'This is a test.'
    """
    return r''.join(chr(a ^ ord(b)) for (a, b) in zip(_data.encode(r'utf-8'), cycle(_key)))


def encrypt_xor_str_key_bytes(_data: str, _key: str) -> bytes:
    r"""Return the xor-encrypted string data as bytes using the given key; Decrypt with decrypt_xor_bytes_key_bytes() or decrypt_xor_bytes_key_str()

    >>> encrypt_xor_str_key_bytes(r'This is a test.', r'Coffee')
    b'\x17\x07\x0f\x15E\x0c0O\x07F\x11\x000\x1bH'
    """
    return r''.join(chr(a ^ ord(b)) for (a, b) in zip(_data.encode(r'utf-8'), cycle(_key))).encode(r'utf-8')


def decrypt_xor_bytes_key_bytes(_data: bytes, _key: str) -> bytes:
    r"""XOR-Decrypt the bytes using the given key and return the data as bytes; Encrypt with encrypt_xor_str_key_bytes()

    >>> decrypt_xor_bytes_key_bytes(b'\x17\x07\x0f\x15E\x0c0O\x07F\x11\x000\x1bH', r'Coffee')
    b'This is a test.'
    """
    return r''.join(chr(a ^ ord(b)) for (a, b) in zip(_data, cycle(_key))).encode(r'utf-8')


def decrypt_xor_bytes_key_str(_data: bytes, _key: str) -> str:
    r"""XOR-Decrypt the bytes using the given key and return the data as a string; Encrypt with encrypt_xor_str_key_bytes()

    >>> decrypt_xor_bytes_key_str(b'\x17\x07\x0f\x15E\x0c0O\x07F\x11\x000\x1bH', r'Coffee')
    'This is a test.'
    """
    return r''.join(chr(a ^ ord(b)) for (a, b) in zip(_data, cycle(_key)))


# CHECKSUMS #


def md5sum(byte_str: bytes) -> str:
    """Generate the MD5 checksum for the given byte string

    >>> md5sum(bytes(r'This is a test', r'utf8'))
    'ce114e4501d2f4e2dcea3e17b546f339'
    >>> md5sum(bytes(r'This is a test.', r'utf8'))
    '120ea8a25e5d487bf68b5f7096440019'
    >>> md5sum(br'This is a test.')
    '120ea8a25e5d487bf68b5f7096440019'
    """
    return md5(byte_str).hexdigest()


def get_checksums(_data: object) -> dict:
    """Generate a dictionary containing various checksum values for the given data

    >>> get_checksums(br'This is a test.')
    {'CRC32': 94035228, 'CRC16': 50568}
    """
    _bytedata: bytes = bytes(str(_data), encoding=r'utf-8')
    return {r'CRC32': crc32(_bytedata), r'CRC16': crc_hqx(_bytedata, 0)}

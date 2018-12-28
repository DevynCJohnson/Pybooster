#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Interface to the magic library (libmagic)

@file filemagic.py
@package pybooster.filemagic
@version 2018.12.28
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
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
"""


# pylint: disable=C0103


from collections import namedtuple
import ctypes
from ctypes import c_void_p, c_char_p, c_int, c_size_t, Structure, POINTER
from ctypes.util import find_library
from typing import Optional, Sized


__all__: list = [
    # FLAG CONSTANTS #
    r'MAGIC_NONE',
    r'MAGIC_DEBUG',
    r'MAGIC_SYMLINK',
    r'MAGIC_COMPRESS',
    r'MAGIC_DEVICES',
    r'MAGIC_MIME_TYPE',
    r'MAGIC_CONTINUE',
    r'MAGIC_CHECK',
    r'MAGIC_PRESERVE_ATIME',
    r'MAGIC_RAW',
    r'MAGIC_ERROR',
    r'MAGIC_MIME_ENCODING',
    r'MAGIC_MIME',
    r'MAGIC_APPLE',
    r'MAGIC_NO_CHECK_COMPRESS',
    r'MAGIC_NO_CHECK_TAR',
    r'MAGIC_NO_CHECK_SOFT',
    r'MAGIC_NO_CHECK_APPTYPE',
    r'MAGIC_NO_CHECK_ELF',
    r'MAGIC_NO_CHECK_TEXT',
    r'MAGIC_NO_CHECK_CDF',
    r'MAGIC_NO_CHECK_TOKENS',
    r'MAGIC_NO_CHECK_ENCODING',
    r'MAGIC_NO_CHECK_BUILTIN',
    r'MAGIC_EXTENSION',
    r'MAGIC_NODESC',
    r'MAGIC_COMPRESS_TRANSP',
    r'FileMagic',
    # DATATYPES #
    r'MagicSet',
    r'magic_t',
    # CLASSES #
    r'Magic',
    # DETECTION TYPE OBJECTS #
    r'NONE_MAGIC',
    r'MIME_MAGIC',
    r'MIME_ENCODING',
    r'MIME_TYPE'
]


# MAGIC #


LIBMAGIC = {}  # type: ignore
LIBMAGIC[r'magic'] = ctypes.cdll.LoadLibrary(find_library(r'magic'))  # type: ignore

# FLAG CONSTANTS #
MAGIC_NONE: int = 0
MAGIC_DEBUG: int = 1
MAGIC_SYMLINK: int = 2
MAGIC_COMPRESS: int = 4
MAGIC_DEVICES: int = 8
MAGIC_MIME_TYPE: int = 16
MAGIC_CONTINUE: int = 32
MAGIC_CHECK: int = 64
MAGIC_PRESERVE_ATIME: int = 128
MAGIC_RAW: int = 256
MAGIC_ERROR: int = 512
MAGIC_MIME_ENCODING: int = 1024
MAGIC_MIME: int = 1040
MAGIC_APPLE: int = 2048
MAGIC_NO_CHECK_COMPRESS: int = 4096
MAGIC_NO_CHECK_TAR: int = 8192
MAGIC_NO_CHECK_SOFT: int = 16384
MAGIC_NO_CHECK_APPTYPE: int = 32768
MAGIC_NO_CHECK_ELF: int = 65536
MAGIC_NO_CHECK_TEXT: int = 131072
MAGIC_NO_CHECK_CDF: int = 262144
MAGIC_NO_CHECK_TOKENS: int = 1048576
MAGIC_NO_CHECK_ENCODING: int = 2097152
MAGIC_NO_CHECK_BUILTIN: int = 4173824
MAGIC_EXTENSION: int = 16777216
MAGIC_NODESC: int = 16780304
MAGIC_COMPRESS_TRANSP: int = 33554432

FileMagic = namedtuple(r'FileMagic', (r'mime_type', r'encoding', r'name'))


# DATATYPES #


class MagicSet(Structure):  # noqa: N801  # pylint: disable=R0903
    """Class used to create magic_t"""

    _fields_ = []  # type: ignore


magic_t = POINTER(MagicSet)

_open = LIBMAGIC[r'magic'].magic_open
_open.restype = magic_t
_open.argtypes = [c_int]

_close = LIBMAGIC[r'magic'].magic_close
_close.restype = None
_close.argtypes = [magic_t]

_load = LIBMAGIC[r'magic'].magic_load
_load.restype = c_int
_load.argtypes = [magic_t, c_char_p]

_compile = LIBMAGIC[r'magic'].magic_compile
_compile.restype = c_int
_compile.argtypes = [magic_t, c_char_p]

_file = LIBMAGIC[r'magic'].magic_file
_file.restype = c_char_p
_file.argtypes = [magic_t, c_char_p]

_descriptor = LIBMAGIC[r'magic'].magic_descriptor
_descriptor.restype = c_char_p
_descriptor.argtypes = [magic_t, c_int]

_buffer = LIBMAGIC[r'magic'].magic_buffer
_buffer.restype = c_char_p
_buffer.argtypes = [magic_t, c_void_p, c_size_t]

_setflags = LIBMAGIC[r'magic'].magic_setflags
_setflags.restype = c_int
_setflags.argtypes = [magic_t, c_int]

_check = LIBMAGIC[r'magic'].magic_check
_check.restype = c_int
_check.argtypes = [magic_t, c_char_p]

_list = LIBMAGIC[r'magic'].magic_list
_list.restype = c_int
_list.argtypes = [magic_t, c_char_p]

_error = LIBMAGIC[r'magic'].magic_error
_error.restype = c_char_p
_error.argtypes = [magic_t]

_errno = LIBMAGIC[r'magic'].magic_errno
_errno.restype = c_int
_errno.argtypes = [magic_t]


# CLASSES #


class Magic():
    """Functions in libmagic"""

    def __init__(self, ms: object) -> None:
        """Initialize magic"""
        self._magic_t = ms

    @staticmethod
    def __tostr(string: object) -> Optional[str]:
        """Convert an object into a string"""
        if string is None:
            return None
        if isinstance(string, str):
            return string
        return str(string, encoding=r'utf-8')  # type: ignore

    @staticmethod
    def __tobytes(_bytes: object) -> Optional[bytes]:
        """Convert an object into bytes"""
        if _bytes is None:
            return None
        if isinstance(_bytes, bytes):
            return _bytes
        return bytes(_bytes, encoding=r'utf-8')  # type: ignore

    def compile(self, dbs: Optional[str]) -> int:
        """Compile entries in the colon separated list of database files passed as argument or the default database file if no argument. The compiled files created are named from the basename(1) of each file argument with ".mgc" appended to it. Returns 0 on success and -1 on failure"""
        return _compile(self._magic_t, Magic.__tobytes(dbs))

    def load(self, filename: Optional[str] = None) -> int:
        """Must be called to load entries in the colon separated list of database files passed as argument or the default database file if no argument before any magic queries can be performed. Returns 0 on success and -1 on failure"""
        return _load(self._magic_t, Magic.__tobytes(filename))

    def setflags(self, flags: int) -> int:
        """Set flags on the magic object which determine how magic checking behaves; a bitwise OR of the flags described in libmagic(3), but without the MAGIC_ prefix. Returns -1 on systems that do not support utime(2) or utimes(2) when PRESERVE_ATIME is set"""
        return _setflags(self._magic_t, flags)

    def close(self) -> None:
        """Close the magic database and deallocates any resources used"""
        _close(self._magic_t)

    def file(self, filename: Optional[str]) -> Optional[str]:
        """Return a textual description of the contents of the argument passed as a filename or `None` (if an error occurred and the MAGIC_ERROR flag is set). A call to errno() will return the numeric error code"""
        return Magic.__tostr(_file(self._magic_t, Magic.__tobytes(filename)))

    def descriptor(self, _fd: object) -> Optional[str]:
        """Return a textual description of the contents of the argument passed as a file descriptor or `None` (if an error occurred and the MAGIC_ERROR flag is set). A call to errno() will return the numeric error code"""
        return Magic.__tostr(_descriptor(self._magic_t, _fd))

    def buffer(self, buf: Sized) -> Optional[str]:
        """Return a textual description of the contents of the argument passed as a buffer or `None` (if an error occurred and the MAGIC_ERROR flag is set). A call to errno() will return the numeric error code"""
        return Magic.__tostr(_buffer(self._magic_t, buf, len(buf)))

    def check(self, dbs: Optional[str]) -> int:
        """Check the validity of entries in the colon separated list of database files passed as argument or the default database file if no argument. Returns 0 on success and -1 on failure"""
        return _check(self._magic_t, Magic.__tobytes(dbs))

    def list(self, dbs: Optional[str]) -> int:
        """Check the validity of entries in the colon separated list of database files passed as argument or the default database file if no argument. Returns 0 on success and -1 on failure"""
        return _list(self._magic_t, Magic.__tobytes(dbs))

    def error(self) -> Optional[str]:
        """Return a textual explanation of the last error or None if there was no error"""
        return Magic.__tostr(_error(self._magic_t))

    def errno(self) -> int:
        """Return a numeric error code. If return value is 0, an internal magic error occurred. If return value is non-zero, the value is an OS error code. Use the errno module or os.strerror() can be used to provide detailed error information"""
        return _errno(self._magic_t)


# DETECTION TYPE OBJECTS #


NONE_MAGIC = Magic(_open(MAGIC_NONE | MAGIC_SYMLINK | MAGIC_PRESERVE_ATIME | MAGIC_NO_CHECK_ELF))
NONE_MAGIC.load()
MIME_MAGIC = Magic(_open(MAGIC_MIME | MAGIC_SYMLINK | MAGIC_PRESERVE_ATIME))
MIME_MAGIC.load()
MIME_ENCODING = Magic(_open(MAGIC_MIME_ENCODING | MAGIC_SYMLINK | MAGIC_PRESERVE_ATIME))
MIME_ENCODING.load()
MIME_TYPE = Magic(_open(MAGIC_MIME_TYPE | MAGIC_SYMLINK | MAGIC_PRESERVE_ATIME))
MIME_TYPE.load()

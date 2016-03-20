#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""@brief Compression Algorithms and Interfaces
@file compress.py
@package pybooster.compress
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


import bz2
import gzip
import lzma
import tarfile


__all__ = [
    # GZIP
    'getgzip',
    'write2gzip',
    'creategzipfile',
    'gzipvar',
    'getgzipvar',
    # BZIP
    'getbzip',
    'write2bzip',
    'createbzipfile',
    'bzipvar',
    'getbzipvar',
    # LZMA
    'getlzma',
    'write2lzma',
    'createlzmafile',
    'lzmavar',
    'getbzipvar',
    # XZ
    'getxz',
    'write2xz',
    'createxzfile',
    'xzvar',
    'getxzvar',
    # TAR
    'gettar',
    'write2tar',
    'extracttar',
    'createtarfile',
]


# GZIP

#    Use the format `open(FILE, mode='rt')`
def getgzip(_filename: str) -> str:
    """Open and get the contents of a gzip file"""
    with gzip.open(_filename, 'rb') as _file:
        data = _file.read()
    return bytes.decode(data)


def write2gzip(_filename: str, _write: str) -> None:
    """Compress data using gzip and write it to a file"""
    with gzip.open(_filename, 'wb') as _file:
        _file.write(str(_write).encode(r'utf-8'))
    return


def creategzipfile(_filename: str) -> None:
    """Gzip an existing file"""
    with gzip.open(_filename, 'rb') as _filein:
        with gzip.open(_filename + r'.gz', 'wb') as _fileout:
            _fileout.writelines(_filein)
    return


def gzipvar(data: str, _encoding: str='utf-8') -> bytes:
    """Gzip the contents of a variable"""
    return gzip.compress(str(data).encode(_encoding))


def getgzipvar(data: bytes) -> str:
    """Get the contents of a Gzipped variable"""
    return bytes.decode(gzip.decompress(data))


# BZIP2


def getbzip(_filename: str) -> str:
    """Open and get the contents of a bzip2 file"""
    with bz2.open(_filename, 'rb') as _file:
        data = _file.read()
    return bytes.decode(data)


def write2bzip(_filename: str, _write: str) -> None:
    """Compress data using bzip2 and write it to a file"""
    with bz2.open(_filename, 'wb', 9) as _file:
        _file.write(str(_write).encode('utf-8'))
    return


def createbzipfile(_filename: str) -> None:
    """Bzip an existing file"""
    with bz2.open(_filename, 'rb') as _filein:
        with bz2.open(_filename + r'.bz', 'wb', 9) as _fileout:
            _fileout.writelines(_filein)
    return


def bzipvar(data: str, _encoding: str='utf-8') -> bytes:
    """Bzip the contents of a variable"""
    return bz2.compress(str(data).encode(_encoding), 9)


def getbzipvar(data: bytes) -> str:
    """Get the contents of a Bzipped variable"""
    return bytes.decode(bz2.decompress(data))


# LZMA


def getlzma(_filename: str) -> str:
    """Open and get the contents of a LZMA file"""
    with lzma.open(_filename, 'rb') as _file:
        data = _file.read()
    return bytes.decode(data)


def write2lzma(_filename: str, _write: str) -> None:
    """Compress data using LZMA and write it to a file"""
    with lzma.open(_filename, 'wb', format=lzma.FORMAT_ALONE, filters={'id': lzma.FILTER_LZMA1}) as _file:
        _file.write(str(_write).encode('utf-8'))
    return


def createlzmafile(_filename: str) -> None:
    """LZMA an existing file"""
    with lzma.open(_filename, 'rb') as _filein:
        with lzma.open(_filename + r'.lzma', 'wb', format=lzma.FORMAT_ALONE, filters={'id': lzma.FILTER_LZMA1}) as _fileout:
            _fileout.writelines(_filein)
    return


def lzmavar(data: str, _encoding: str='utf-8') -> bytes:
    """LZMA the contents of a variable"""
    data = str(data).encode(_encoding)
    return lzma.compress(data, format=lzma.FORMAT_ALONE, filters={'id': lzma.FILTER_LZMA1})


def getlzmavar(data: bytes) -> str:
    """Get the contents of a LZMA variable"""
    return bytes.decode(lzma.decompress(data))


# XZ


def getxz(_filename: str) -> str:
    """Open and get the contents of a XZ file"""
    with lzma.open(_filename, 'rb') as _file:
        data = _file.read()
    return bytes.decode(data)


def write2xz(_filename: str, _write: str) -> None:
    """Compress data using XZ and write it to a file"""
    with lzma.open(_filename, 'wb', format=lzma.FORMAT_XZ, filters={'id': lzma.FILTER_LZMA2}) as _file:
        _file.write(str(_write).encode('utf-8'))
    return


def createxzfile(_filename: str) -> None:
    """XZ an existing file"""
    with lzma.open(_filename, 'rb') as _filein:
        with lzma.open(_filename + r'.xz', 'wb', format=lzma.FORMAT_XZ, filters={'id': lzma.FILTER_LZMA2}) as _fileout:
            _fileout.writelines(_filein)
    return


def xzvar(data: str, _encoding: str='utf-8') -> bytes:
    """XZ the contents of a variable"""
    data = str(data).encode(_encoding)
    return lzma.compress(data, format=lzma.FORMAT_XZ, filters={'id': lzma.FILTER_LZMA2})


def getxzvar(data: bytes) -> str:
    """Get the contents of a XZ variable"""
    return bytes.decode(lzma.decompress(data))


# TAR


def gettar(_filename: str) -> str:
    """Open and get the contents of a tar file"""
    with tarfile.open(_filename, 'r') as _file:
        data = _file.read()
    return data


def write2tar(_filename: str, _write: str) -> None:
    """Archive data using tar and write it to a file"""
    with tarfile.open(_filename, 'w', 9) as _file:
        _file.write(str(_write))
    return


def extracttar(_filename: str) -> None:
    """Extract files from a Tar file in the directory"""
    with tarfile.open(_filename, 'r') as _file:
        _file.extractall()
    return


def createtarfile(_filenames: list, _tarfile: str) -> None:
    """Tar existing files into the specified Tar-file"""
    with tarfile.open(_tarfile, 'w') as _file:
        for _files in _filenames:
            _file.add(_files)
    return

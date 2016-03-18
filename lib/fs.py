#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""
Created by Devyn Collier Johnson
<DevynCJohnson@Gmail.com>
LGPLv3 License
-- --
PyBooster - Various Extras for Python3
pybooster.fs
-- --
Filesystem and file related functions
-- --
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

from binascii import b2a_qp, hexlify
from glob import glob
from os import path, remove
from shutil import rmtree
from sys import stdin, stdout


__all__ = [
    # CONSTANTS
    'GIGABYTE',
    'GIGIBYTE',
    # PERMISSIONS
    'convumask',
    # FILE AND FILESYSTEM INFO
    'lsfiles',
    # GET FILE AND PATHNAMES
    'getfileext',
    'getfilename',
    'getfilenameext',
    'getfilenameexttup',
    'getfilepath',
    'getfilepathext',
    'getfilepathextlist',
    # PATH MANIPULATIONS
    'expandhome',
    # READ FILE CONTENTS
    'getfile',
    'getfilehexbytes',
    'getfilehexbytesstr',
    'getfilehexbytes_spaced',
    'getfilebinbytes',
    'getfilebinwords',
    'getfilehexstr',
    'getfilehexstr2',
    'getfileraw_list',
    'getfile_list',
    'getfiles',
    'getfiles_list',
    'printfile',
    'firstchars',
    'pyhead',
    # READ/GET DATA
    'readstream',
    'readpipe',
    'getstdin',
    # WRITE/SEND DATA
    'append2file',
    'write2file',
    'writebin2file',
    'writestr2binfile',
    'pyheadstdin',
    # REMOVE DATA FROM FILESYSTEM
    'rmfile',
    'rmdir',
]

__author__ = 'Devyn Collier Johnson'
__copyright__ = 'LGPLv3'
__version__ = '2016.03.18'


# CONSTANTS

GIGABYTE = 1000000000  # Gigabyte (Base 10)
GIGIBYTE = 1073741824  # Gigibyte (Base 2)


# FILE AND FILESYSTEM INFO


def lsfiles(_path: str, _extension: str) -> list:
    """List files in the specified directory with named file extension"""
    return glob(path.join(_path, _extension))


# PERMISSIONS


def convumask(_oct) -> str:
    """Convert file permissions/umask (644 -> 'rw-r--r--')
    From octal permissions notation (int, str, or list of str+int)
    To Posix permissions notation as a str
    Input may be in any of the following forms -
    > '644', 644, '0644', 0644, [6, 4, 4], ['6', '4', '4'],
    > [6, '4', 4], [0, 6, 4, 4], ['0', '6', '4', '4'], [0, '6', '4', 4]
    >>> convumask(644)
    'rw-r--r--'
    >>> convumask('644')
    'rw-r--r--'
    >>> convumask(654)
    'rw-r-xr--'
    """
    _bits = ([4, 'r'], [2, 'w'], [1, 'x'])
    _mode = []
    if isinstance(_oct, int):
        _oct = str(_oct)
    for _int in _oct[-3:]:
        for i in _bits:
            if bool(int(_int) & i[0]):
                _mode.append(i[1])
            else:
                _mode.append('-')
    return ''.join(_mode)


# GET FILE AND PATHNAMES


def getfileext(_filename: str) -> str:
    """Get the file's extension
    >>> getfileext('/etc/mime.types')
    'types'
    >>> getfileext('/bin/sh')
    ''
    """
    if '.' not in _filename:
        return ''
    return _filename.split('.')[-1]


def getfilename(_pathname: str) -> str:
    """Return the filename without path or extension
    The path and extension are removed from the given string
    >>> getfilename('/etc/mime.types')
    'mime'
    >>> getfilename('/bin/sh')
    'sh'
    """
    return path.splitext(path.split(_pathname)[1])[0]


def getfilenameext(_pathname: str) -> str:
    """Return the filename with extension, but without path
    The path is removed from the given string
    >>> getfilenameext('/etc/mime.types')
    'mime.types'
    >>> getfilenameext('/bin/sh')
    'sh'
    """
    return path.split(_pathname)[1]


def getfilenameexttup(_pathname: str) -> tuple:
    """Return the filename (as a tuple) without path
    The path is removed from the given string
    >>> getfilenameexttup('/etc/mime.types')
    ('mime', '.types')
    >>> getfilenameexttup('/bin/sh')
    ('sh', '')
    """
    return path.splitext(path.split(_pathname)[1])


def getfilepath(_pathname: str) -> str:
    """Return the path without filename
    The filename is removed from the given string
    >>> getfilepath('/etc/mime.types')
    '/etc'
    >>> getfilepath('/bin/sh')
    '/bin'
    """
    return path.split(_pathname)[0]


def getfilepathext(_pathname: str) -> tuple:
    """Return the path and filename+extension as a tuple
    >>> getfilepathext('/etc/mime.types')
    ('/etc', 'mime.types')
    >>> getfilepathext('/bin/sh')
    ('/bin', 'sh')
    """
    return path.split(_pathname)


def getfilepathextlist(_pathname: str) -> list:
    """Return the path, filename, and extension as a list
    >>> getfilepathextlist('/etc/mime.types')
    ['/etc', 'mime', '.types']
    >>> getfilepathextlist('/bin/sh')
    ['/bin', 'sh', '']
    """
    _out = []
    _out.append(path.split(_pathname)[0])
    _out.append(path.splitext(path.split(_pathname)[1])[0])
    _out.append(path.splitext(path.split(_pathname)[1])[1])
    return _out


# PATH MANIPULATIONS


def expandhome(_pathname: str) -> str:
    """Replace 'HOME', '$HOME', or '~' with the literal value
    Supported OS 'HOME' shortcuts -
    * Linux, POSIX, Unix, and Unixoid systems
    * Windows (MS and Pirated)
    * OS X (Apple)
    >>> expandhome('~/file')
    '/home/username/file'
    >>> expandhome('HOME/file')
    '/home/username/file'
    >>> expandhome('$HOME/file')
    '/home/username/file'
    """
    if _pathname.startswith('HOME'):
        return _pathname.replace('HOME', path.expanduser('~'), 1)
    elif _pathname.startswith('/HOME'):
        return _pathname.replace('/HOME', path.expanduser('~'), 1)
    elif '$HOME' in _pathname:
        return _pathname.replace('$HOME', path.expanduser('~'), 1)
    elif '~' in _pathname:
        return _pathname.replace('~', path.expanduser('~'), 1)
    return _pathname


# READ FILE CONTENTS


def getfile(_filename: str) -> str:
    """Get file contents and return as a str"""
    _out = []
    with open(_filename, mode='rt', encoding='utf-8') as _file:
        _out.append(''.join(_file.readlines()).strip())
    return ''.join(_out)


def getfilehexbytes(_filename: str) -> bytes:
    """Get file contents as bytes in hex"""
    _file = open(_filename, 'rb')
    with _file:
        _hex = hexlify(_file.read())
    return _hex


def getfilehexbytesstr(_filename: str) -> str:
    """Get file contents as a str of bytes in hex"""
    _file = open(_filename, 'rb')
    with _file:
        _hex = hexlify(_file.read())
    return str(_hex, 'utf-8')


def getfilehexbytes_spaced(_filename: str) -> str:
    """Get file contents as a str of bytes in hex with spaces between each byte"""
    _file = open(_filename, 'rb')
    with _file:
        _hex = hexlify(_file.read())
    _hex = str(_hex, 'utf-8')
    index = 2
    while index != len(_hex):
        _hex = _hex[:index] + ' ' + _hex[index:]
        index += 3
    return _hex


def getfilebinbytes(_filename: str) -> str:
    """Get file contents and return binary as str"""
    _file = open(_filename, 'rb')
    with _file:
        _hex = bin(int(hexlify(_file.read()), 16))[2:].zfill(8)
    return _hex


def getfilebinwords(_filename: str) -> bytes:
    """Get file contents and return a byte-str of binary words"""
    _file = open(_filename, 'rb')
    with _file:
        _hex = _file.read()
    return _hex


def getfilehexstr(_filename: str) -> str:
    """Get file contents and return a str of hex"""
    _file = open(_filename, 'rb')
    with _file:
        _hex = b2a_qp(_file.read())
    return ''.join(chr(int(x)) for x in _hex)


def getfilehexstr2(_filename: str) -> str:
    """Get file contents and return a str of hex"""
    _file = open(_filename, 'rb')
    with _file:
        _hex = b2a_qp(_file.read())
    return ''.join(chr(int(x)) for x in _hex).replace('=', '').replace('\n', '').replace('\t', '').replace(' ', '').replace('\r', '')


def getfileraw_list(_filename: str) -> list:
    """Get file contents as a list of byte-objects"""
    _out = ''
    with open(_filename, mode='rb') as _file:
        _out = _file.readlines()
    return _out


def getfile_list(_filename: str) -> list:
    """Get file contents and return as a list"""
    with open(_filename, mode='rt', encoding='utf-8') as _file:
        _out = _file.readlines()
    return _out


def getfiles(_filelist: list) -> str:
    """Get the contents of multiple files
    Return a str containing each file's content
    Example Usage -
    getfiles1(['file0', 'file1', 'file2'])
    Output - 'file0 contents file1 contents file2 contents'
    """
    _out = ''
    for _filepath in _filelist:
        _data = []
        _filepath = path.expanduser(_filepath)
        with open(_filepath, mode='rt', encoding='utf-8') as _file:
            _data.append(''.join(_file.readlines()).strip())
        _out = _out + _data[0]
    return _out


def getfiles_list(*_pathnames: str) -> list:
    """Get the contents of multiple files
    Return a list containing items as strings
    The contents of one file is placed in one entry
    Example Usage -
    getfiles(['file0', 'file1', 'file2'])
    Output - ['file0 contents', 'file1 contents', 'file2 contents']
    """
    _out = []
    for _filepath in _pathnames:
        _data = []
        _filepath = path.expanduser(_filepath)
        with open(_filepath, mode='rt', encoding='utf-8') as _file:
            _data.append(''.join(_file.readlines()).strip())
        _out.append(_data[0])
    return _out


def printfile(_filepath: str):
    """Print the contents of a file"""
    print(''.join(line.split(':', 1)[0] for line in open(_filepath, mode='rt', encoding='utf-8')))


def firstchars(_filepath: str, _numchars: int=10) -> str:
    """Return the first x characters in a file"""
    _getfilelines = ''.join(line.split(':', 1)[0] for line in open(_filepath, mode='rt', encoding='utf-8'))
    return ''.join(_getfilelines[:_numchars])


def pyhead(_filepath: str, _numlines: int=10) -> str:
    """Emulates the Unix "head" command"""
    _lines = []
    _ct = 0
    for line in open(_filepath, mode='rt', encoding='utf-8'):
        _lines.append(line)
        _ct += 1
        if _ct == _numlines:
            return ''.join(_lines)


# READ/GET DATA


def readstream(open_file_stream) -> str:
    """Get data from an open file stream"""
    return ''.join(open_file_stream.readlines()).strip()


def readpipe() -> str:
    """Read from a pipe"""
    while True:
        _input = ''
        _data = stdin.read(1)
        while _data:
            _input += _data
            _data = stdin.read(1)
        return str(_input)


def getstdin() -> str:
    """Get data from stdin"""
    return ''.join(stdin.readlines()).strip()


# WRITE/SEND DATA


def append2file(_filename: str, _write) -> None:
    """Send data to new file or append to an existing file"""
    with open(_filename, mode='a', encoding='utf-8') as _file:
        _file.write(str(_write))
    return None


def write2file(_filename: str, _write) -> None:
    """Send data to new file or overwrite file"""
    with open(_filename, mode='w', encoding='utf-8') as _file:
        _file.write(str(_write))
    return None


def writebin2file(_filename: str, _write: bytes) -> None:
    """Write binary data to a new file or overwrite the file"""
    with open(_filename, mode='wb') as _file:
        _file.write(_write)
    return None


def writestr2binfile(_filename: str, _write: str) -> None:
    """Write a string as binary data to a new file or overwrite the file"""
    with open(_filename, mode='wb') as _file:
        _file.write(str(_write).encode('utf-8'))
    return None


def pyheadstdin() -> None:
    """Pyhead for stdin/stdout
    Emulates the Unix "head" command
    """
    stdout.write(''.join(stdin.readlines()[:10]))
    return None


# REMOVE DATA FROM FILESYSTEM


def rmfile(_file: str) -> bool:
    """Try to remove a file
    Return True on success or False on failure
    """
    if path.isfile(_file):
        try:
            remove(_file)
        except OSError as _err:
            print('Error: {} - {}.'.format(_err.filename, _err.strerror))
            return False
    else:
        print('Error: {} file not found'.format(_file))
        return False
    return True


def rmdir(_dir: str) -> bool:
    """Try to remove a directory
    Return True on success and False on failure
    """
    if path.isdir(_dir):
        try:
            rmtree(_dir)
        except OSError as _err:
            print('Error: {} - {}.'.format(_err.filename, _err.strerror))
            return False
    else:
        print('Error: {} directory not found'.format(_dir))
        return False
    return True

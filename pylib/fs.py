#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Filesystem and file related functions

@file fs.py
@package pybooster.fs
@version 2018.11.11
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


from binascii import b2a_qp, hexlify
from codecs import open as codec_opener
from glob import glob
from os import access as fileaccess, remove, R_OK, W_OK
from os.path import (
    dirname,
    expanduser,
    isdir,
    isfile,
    join as join_path,
    lexists as pathexists,
    normcase,
    realpath,
    split as path_split,
    splitext as path_splitext
)
from shutil import rmtree
from sys import stderr, stdin, stdout
from typing import Any, List, Tuple, Union


__all__: list = [
    # CONSTANTS #
    r'GIGABYTE',
    r'GIGIBYTE',
    # VALIDATION #
    r'doesfileexist',
    r'ensurefileexists',
    # FILE & FILESYSTEM INFO #
    r'lsfiles',
    # PERMISSIONS #
    r'convumask',
    # GET FILE & PATHNAMES #
    r'getscriptdir',
    r'getfileext',
    r'getfilename',
    r'getfilenameext',
    r'getfilenameexttup',
    r'getfilepath',
    r'getfilepathext',
    r'getfilepathextlist',
    # PATH MANIPULATIONS #
    r'expandhome',
    # READ FILE CONTENTS #
    r'getfile',
    r'getfilehexbytes',
    r'getfilehexbytesstr',
    r'getfilehexbytes_spaced',
    r'getfilebinbytes',
    r'getfilebinwords',
    r'getfilehexstr',
    r'getfilehexstr2',
    r'getfileraw_list',
    r'getfile_list',
    r'getfiles',
    r'getfiles_list',
    r'printfile',
    r'firstchars',
    # READ/GET DATA #
    r'getdata',
    r'getstdin',
    # WRITE/SEND DATA #
    r'writedata',
    r'append2file',
    r'write2file',
    r'writebin2file',
    r'writestr2binfile',
    r'head',
    # REMOVE DATA FROM FILESYSTEM #
    r'rmfile',
    r'rmdir'
]


# CONSTANTS #


GIGABYTE = 1000000000  # Gigabyte (Base 10)
GIGIBYTE = 1073741824  # Gigibyte (Base 2)


# VALIDATION #


def doesfileexist(_filename: str) -> bool:
    """Test that the specified file exists"""
    if not pathexists(_filename) or not isfile(_filename):
        return False
    if isdir(_filename):
        return False
    if not fileaccess(_filename, R_OK):
        return False
    return True


def ensurefileexists(_filename: str) -> None:
    """Ensure that the specified file exists; if not, then raise an exception"""
    if not pathexists(_filename) or not isfile(_filename):
        stderr.write(_filename + ': The specified file is non-readable or non-existent!\n')
    elif isdir(_filename):
        stderr.write(_filename + ': This "file" is actually a directory!\n')
    elif not fileaccess(_filename, R_OK):
        stderr.write(r'Permission Error: Unable to write to "' + _filename + '"!\n')
    else:
        return
    raise SystemExit(1)


# FILE & FILESYSTEM INFO #


def lsfiles(_path: str, _extension: str) -> list:
    """List files in the specified directory with named file extension"""
    return glob(join_path(_path, _extension))


# PERMISSIONS #


def convumask(_oct: Union[int, list, str]) -> str:
    """Convert file permissions/umask (644 -> 'rw-r--r--')

    From octal permissions notation (int, str, or list of str+int)
    To Posix permissions notation as a str

    Input may be in any of the following forms:
    > '644', 644, '0644', 0644, [6, 4, 4], ['6', '4', '4'],
    > [6, '4', 4], [0, 6, 4, 4], ['0', '6', '4', '4'], [0, '6', '4', 4]

    >>> convumask(644)
    'rw-r--r--'
    >>> convumask('644')
    'rw-r--r--'
    >>> convumask(654)
    'rw-r-xr--'
    >>> convumask([7, 6, 4])
    'rwxrw-r--'
    """
    _bits: Tuple[List[Any], List[Any], List[Any]] = ([4, r'r'], [2, r'w'], [1, r'x'])
    _mode: list = []
    if isinstance(_oct, int):
        _oct = str(_oct)
    for _int in _oct[-3:]:
        for i in _bits:
            if bool(int(_int) & i[0]):
                _mode.append(i[1])
            else:
                _mode.append(r'-')
    return r''.join(_mode)


# GET FILE & PATHNAMES #


def getscriptdir() -> str:
    """Get the directory path of the currently running script"""
    return normcase(dirname(realpath(normcase(__file__))))


def getfileext(_filename: str) -> str:
    """Get the file's extension

    >>> getfileext('/etc/mime.types')
    'types'
    >>> getfileext('/bin/sh')
    ''
    """
    return r'' if r'.' not in _filename else _filename.split(r'.')[-1]


def getfilename(_pathname: str) -> str:
    """Return the filename without path or extension

    The path and extension are removed from the given string

    >>> getfilename('/etc/mime.types')
    'mime'
    >>> getfilename('/bin/sh')
    'sh'
    """
    return path_splitext(path_split(_pathname)[1])[0]


def getfilenameext(_pathname: str) -> str:
    """Return the filename with extension, but without path

    The path is removed from the given string

    >>> getfilenameext('/etc/mime.types')
    'mime.types'
    >>> getfilenameext('/bin/sh')
    'sh'
    """
    return path_split(_pathname)[1]


def getfilenameexttup(_pathname: str) -> tuple:
    """Return the filename (as a tuple) without path

    >>> getfilenameexttup('/etc/mime.types')
    ('mime', '.types')
    >>> getfilenameexttup('/bin/sh')
    ('sh', '')
    """
    return path_splitext(path_split(_pathname)[1])


def getfilepath(_pathname: str) -> str:
    """Return the path without filename

    >>> getfilepath(r'/etc/mime.types')
    '/etc'
    >>> getfilepath('/bin/sh')
    '/bin'
    """
    return path_split(_pathname)[0]


def getfilepathext(_pathname: str) -> tuple:
    """Return the path and filename+extension as a tuple

    >>> getfilepathext('/etc/mime.types')
    ('/etc', 'mime.types')
    >>> getfilepathext('/bin/sh')
    ('/bin', 'sh')
    """
    return path_split(_pathname)


def getfilepathextlist(_pathname: str) -> list:
    """Return the path, filename, and extension as a list

    >>> getfilepathextlist('/etc/mime.types')
    ['/etc', 'mime', '.types']
    >>> getfilepathextlist('/bin/sh')
    ['/bin', 'sh', '']
    """
    return [path_split(_pathname)[0], path_splitext(path_split(_pathname)[1])[0], path_splitext(path_split(_pathname)[1])[1]]


# PATH MANIPULATIONS #


def expandhome(_pathname: str) -> str:
    """Replace '${HOME}', '$HOME', or '~' with the literal value

    Supported OS 'HOME' shortcuts:
     - Linux, POSIX, Unix, and Unixoid systems
     - Windows (MS and Pirated)
     - OS X (Apple)

    >>> expandhome('~/.bashrc')
    '/home/collier/.bashrc'
    >>> expandhome('${HOME}/.bashrc')
    '/home/collier/.bashrc'
    >>> expandhome('$HOME/.bashrc')
    '/home/collier/.bashrc'
    """
    if _pathname.startswith(r'${HOME}'):
        return _pathname.replace(r'${HOME}', expanduser(r'~'), 1)
    if r'$HOME' in _pathname:
        return _pathname.replace(r'$HOME', expanduser(r'~'), 1)
    if r'~' in _pathname:
        return _pathname.replace(r'~', expanduser(r'~'), 1)
    return _pathname


# READ FILE CONTENTS #


def getfile(_filename: str) -> str:
    """Get file contents and return as a str"""
    with open(_filename, mode=r'rt', encoding=r'utf-8') as _file:
        return r''.join(_file.readlines()).strip()


def getfilehexbytes(_filename: str) -> bytes:
    """Get file contents as bytes in hex"""
    with open(_filename, mode=r'rb', encoding=r'utf-8') as _file:
        return hexlify(_file.read())


def getfilehexbytesstr(_filename: str) -> str:
    """Get file contents as a str of bytes in hex"""
    with open(_filename, mode=r'rb') as _file:
        return str(hexlify(_file.read()), r'utf-8')


def getfilehexbytes_spaced(_filename: str) -> str:
    """Get file contents as a str of bytes in hex with spaces between each byte"""
    with open(_filename, mode=r'rb') as _file:
        _hex = str(hexlify(_file.read()), r'utf-8')
    index = 2
    while index != len(_hex):
        _hex = _hex[:index] + r' ' + _hex[index:]
        index += 3
    return _hex


def getfilebinbytes(_filename: str) -> str:
    """Get file contents and return binary as str"""
    with open(_filename, mode=r'rb') as _file:
        return bin(int(hexlify(_file.read()), 16))[2:].zfill(8)


def getfilebinwords(_filename: str) -> bytes:
    """Get file contents and return a byte-str of binary words"""
    with open(_filename, mode=r'rb') as _file:
        return _file.read()


def getfilehexstr(_filename: str) -> str:
    """Get file contents and return a str of hex"""
    with open(_filename, mode=r'rb') as _file:
        _hex = b2a_qp(_file.read())
    return r''.join(chr(int(x)) for x in _hex)


def getfilehexstr2(_filename: str) -> str:
    """Get file contents and return a str of hex"""
    with open(_filename, mode=r'rb') as _file:
        _hex = b2a_qp(_file.read())
    return r''.join(chr(int(x)) for x in _hex).replace(r'=', r'').replace('\n', r'').replace('\t', r'').replace(r' ', r'').replace('\r', r'')


def getfileraw_list(_filename: str) -> list:
    """Get file contents as a list of byte-objects"""
    with open(_filename, mode=r'rb') as _file:
        return _file.readlines()


def getfile_list(_filename: str) -> list:
    """Get file contents and return as a list"""
    with open(_filename, mode=r'rt', encoding=r'utf-8') as _file:
        return _file.readlines()


def getfiles(_filelist: list) -> str:
    """Get the contents of multiple files

    Return a str containing each file's content
    Example Usage - getfiles1(['file0', 'file1', 'file2'])
    Output - 'file0 contents file1 contents file2 contents'
    """
    _out: str = r''
    for _filepath in _filelist:
        _filepath = expanduser(_filepath)
        with open(_filepath, mode=r'rt', encoding=r'utf-8') as _file:
            _out += r''.join(_file.readlines()).strip()
    return _out


def getfiles_list(*_pathnames: str) -> list:
    """Get the contents of multiple files

    Return a list containing items as strings
    The contents of one file is placed in one entry

    Example Usage - getfiles(['file0', 'file1', 'file2'])
    Output - ['file0 contents', 'file1 contents', 'file2 contents']
    """
    _out: list = []
    for _filepath in _pathnames:
        _data: list = []
        _filepath = expanduser(_filepath)
        with open(_filepath, mode=r'rt', encoding=r'utf-8') as _file:
            _data.append(r''.join(_file.readlines()).strip())
        _out.append(_data[0])
    return _out


def printfile(_filepath: str) -> None:
    """Print the contents of a file"""
    stdout.write(r''.join(line.split(r':', 1)[0] for line in open(_filepath, mode=r'rt', encoding=r'utf-8')) + '\n')


def firstchars(_filepath: str, _numchars: int = 10) -> str:
    """Return the first x characters in a file"""
    return r''.join(r''.join(line.split(r':', 1)[0] for line in open(_filepath, mode=r'rt', encoding=r'utf-8'))[:_numchars])


# READ/GET DATA #


def getdata(_filename: str, _encoding: str = r'utf-8') -> str:
    """Get file/pipe contents and return as a str"""
    try:
        _out: str = r''
        if _filename:  # Input file specified
            ensurefileexists(_filename)
            with codec_opener(_filename, mode=r'r', encoding=_encoding, buffering=1) as _file:
                return r''.join(_file.readlines())
        else:  # Piping used
            return r''.join(stdin.readlines())
        return _out
    except (LookupError, UnicodeError):
        stderr.write('Unable to determine and process data encoding!\n')
        raise SystemExit(1)


def getstdin() -> str:
    """Get data from stdin"""
    return r''.join(stdin.readlines()).strip()


# WRITE/SEND DATA #


def writedata(_filename: str, _write: str, _encoding: str = r'utf-8') -> None:
    """Send data to new file, overwrite file, or send to stdout"""
    if _filename:
        if isfile(_filename) and not fileaccess(_filename, W_OK) and not isdir(_filename):
            stderr.write(r'Permission Error: Unable to write to "' + _filename + '"!\n')
            raise SystemExit(1)
        with codec_opener(_filename, mode=r'w', encoding=_encoding, buffering=1) as _file:
            _file.write(_write)
    else:
        stdout.write(_write)


def append2file(_filename: str, _write: object) -> None:
    """Send data to new file or append to an existing file"""
    with open(_filename, mode=r'at', encoding=r'utf-8') as _file:
        _file.write(str(_write, encoding=r'utf-8'))  # type: ignore


def write2file(_filename: str, _write: object) -> None:
    """Send data to new file or overwrite file"""
    with open(_filename, mode=r'wt', encoding=r'utf-8') as _file:
        _file.write(str(_write, encoding=r'utf-8'))  # type: ignore


def writebin2file(_filename: str, _write: bytes) -> None:
    """Write binary data to a new file or overwrite the file"""
    with open(_filename, mode=r'wb') as _file:
        _file.write(_write)


def writestr2binfile(_filename: str, _write: str) -> None:
    """Write a string as binary data to a new file or overwrite the file"""
    with open(_filename, mode=r'wb') as _file:
        _file.write(str(_write).encode(r'utf-8'))


def head(_filepath: str = r'', _numlines: int = 10) -> str:
    """Emulates the Unix `head` command (without parameters)"""
    if not _filepath:
        retstr = r''.join(stdin.readlines()[:_numlines]) + '\n'
        stdout.write(retstr)
        return retstr
    _lines = []
    _ct = 0
    for line in open(_filepath, mode=r'rt', encoding=r'utf-8'):
        _lines.append(line)
        _ct += 1
        if _ct == _numlines:
            return r''.join(_lines)
    return r''.join(_lines)


# REMOVE DATA FROM FILESYSTEM #


def rmfile(_file: str) -> bool:
    """Try to remove a file; Return True on success or False on failure"""
    if isfile(_file):
        try:
            remove(_file)
        except OSError as _err:
            stderr.write('Error: {} - {}\n'.format(_err.filename, _err.strerror))
            return False
    else:
        stderr.write('Error: {} file not found\n'.format(_file))
        return False
    return True


def rmdir(_dir: str) -> bool:
    """Try to remove a directory; Return True on success and False on failure"""
    if isdir(_dir):
        try:
            rmtree(_dir)
        except OSError as _err:
            stderr.write('Error: {} - {}\n'.format(_err.filename, _err.strerror))
            return False
    else:
        stderr.write('Error: {} directory not found\n'.format(_dir))
        return False
    return True

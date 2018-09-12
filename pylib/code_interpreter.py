#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Interpret various computer languages using installed interpreters

@file code_interpreter.py
@package pybooster.code_interpreter
@version 2018.09.11
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


from subprocess import getoutput  # nosec
from sys import stdout


__all__: list = [
    # CLISP #
    r'execclispfile',
    # COFFEESCRIPT #
    r'execcoffeescript',
    # JAVASCRIPT #
    r'execjs',
    r'execjsfile',
    # LUA #
    r'execlua',
    r'execluafile',
    # PERL #
    r'execperl',
    r'execperlfile',
    r'initperl',
    # PHP #
    r'execphp',
    r'execphpfile',
    # RUBY #
    r'execruby',
    r'execrubyfile',
    # SCALA #
    r'execscala',
    r'execscala',
    # SHELL #
    r'execsh',
    r'execshfile',
    r'initsh'
]


# CLISP #


def execclispfile(_filename: str) -> str:
    """Execute a CLisp file given as a str and return the output as a str"""
    return getoutput(r'clisp ' + _filename)


# COFFEESCRIPT #


def execcoffeescript(_code: str) -> str:
    """Execute Coffeescript code given as a str and return the output as a str"""
    return getoutput('coffeescript --eval \'' + _code.replace('\'', '\\\'') + '\'')


# JAVASCRIPT #


def execjs(_code: str) -> str:
    """Execute JavaScript code given as a str and return the output as a str"""
    return getoutput('jsc -e \'' + _code.replace('\'', '\\\'') + '\'')


def execjsfile(_filename: str) -> str:
    """Execute a JavaScript file given as a str and return the output as a str"""
    return getoutput(r'jsc -e ' + _filename)


# LUA #


def execlua(_code: str) -> str:
    """Execute Lua code given as a str and return the output as a str"""
    return getoutput('lua -e \'' + _code.replace('\'', '\\\'') + '\'')


def execluafile(_filename: str) -> str:
    """Execute a Lua script given as a str and return the output as a str"""
    return getoutput(r'lua ' + _filename)


# PERL #


def execperl(_code: str) -> str:
    """Execute Perl code given as a str and return the output as a str"""
    return getoutput('perl -e \'' + _code.replace('\'', '\\\'') + '\'')


def execperlfile(_filename: str) -> str:
    """Execute a Perl script given as a str and return the output as a str"""
    return getoutput(r'perl ' + _filename)


def initperl() -> None:
    """Run a Perl REP-Loop (Read-Evaluate-Print-Loop)"""
    _input = ''
    while 1:
        _input = input(r'Perl > ').replace('\'', '\\\'')  # nosec
        if _input == 'exit' or _input == 'quit':
            break
        _output = getoutput('perl -e \'' + _input + '\'')
        stdout.write(_output + '\n')
    return


# PHP #


def execphp(_code: str) -> str:
    """Execute PHP code given as a str and return the output as a str"""
    return getoutput('php -r \'' + _code.replace('\'', '\\\'') + '\'')


def execphpfile(_filename: str) -> str:
    """Execute a PHP script given as a str and return the output as a str"""
    return getoutput(r'php -f ' + _filename)


# RUBY #


def execruby(_code: str) -> str:
    """Execute Ruby code given as a str and return the output as a str"""
    return getoutput('ruby -e \'' + _code.replace('\'', '\\\'') + '\'')


def execrubyfile(_filename: str) -> str:
    """Execute a Ruby script given as a str and return the output as a str"""
    return getoutput(r'ruby ' + _filename)


# SCALA #


def execscala(_code: str) -> str:
    """Execute Scala code given as a str and return the output as a str"""
    return getoutput('scala -e \'' + _code.replace('\'', '\\\'') + '\'')


def execscalafile(_filename: str) -> str:
    """Execute a Scala file given as a str and return the output as a str"""
    return getoutput(r'scala ' + _filename)


# SHELL #


def execsh(_code: str) -> str:
    """Execute Shell code given as a str and return the output as a str"""
    return getoutput('sh -c \'' + _code.replace('\'', '\\\'') + '\'')


def execshfile(_filename: str) -> str:
    """Execute a Shell script given as a str and return the output as a str"""
    return getoutput(r'sh ' + _filename)


def initsh() -> None:
    """Run a shell REP-Loop (Read-Evaluate-Print-Loop)"""
    _input = r''
    while 1:
        _input = input(r'Shell: $ ').replace('\'', '\\\'')  # nosec
        if _input == r'exit' or _input == r'quit':
            break
        _output = getoutput('sh -c \'' + _input + '\'')
        stdout.write(_output + '\n')
    return

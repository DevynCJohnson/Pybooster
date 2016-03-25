#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
"""@brief Flake8 Plugin
@file Clint
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@version 2016.03.22

@section DESCRIPTION
 - dj** = Devyn Collier Johnson's Personal Flake8 Checks
 - MG** = Magic Comments
 - T000 = Todo Note
 - V*** = Vague
 - X*** = Inconsistency
 - Z*** = Optimize

physical_line - all lines (including comments)\n
logical_line - literal code


@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This library is free software; you can redistribute it and/or
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


try:
    import regex as re  # noqa  # pylint: disable=C0411
except ImportError:
    import re  # noqa  # pylint: disable=C0411

import pep8


__version__ = '2016.03.22'


# Patterns
NOQA_CHECK = re.compile(r'# no(?:qa|pep8)( [A-Z0-9]+|)\b', re.I)
REGEX_BLIND_EXCEPT = re.compile(r'(except:)')
REGEX_DCJ_VERSION = re.compile(r'(__version__ = \'20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]\')')
REGEX_EMAIL = re.compile(r'(__email__ = )')
REGEX_INPUT_STR = re.compile(r'(str\(input\()')
REGEX_INVALID_MAIN = re.compile(r'(if __name__ is \'__main__\':)')
REGEX_VALID_EMAIL = re.compile(r'(__email__ = \'[A-Za-z0-9\-]+@[A-Za-z0-9\-]+\.[A-Za-z0-9]+\')')
REGEX_EXCEPTAS = re.compile(r'(except [A-Za-z0-9_ \(\)\,]+ as [A-Za-z0-9_]+:)')
REGEX_EXIT = re.compile(r'(sys\.exit|exit)\([0-9\-]*\)')
REGEX_GTK_ADDFROMSTRING = re.compile(r'(.+\.add_from_string\([A-Za-z0-9_\'"]+\))')
REGEX_HASHPLING = re.compile(r'((#!/usr/bin/|#!/bin/).+)')
REGEX_LEN_ZERO = re.compile(r'(if len\([A-Za-z0-9_ \+]+\) (\!=|is not) 0:)')
REGEX_LEN_IS_ZERO = re.compile(r'(if len\([A-Za-z0-9_ \+]+\) (==|is) 0:)')
REGEX_LICENSE = re.compile(r'(__license__ = )')
REGEX_NOTE = re.compile(r'# (TODO|FIXME|FIX|REPAIR|FINISH|DEBUG|XXX)', re.I)
REGEX_OPEN = re.compile(r'(open\(.+\))')
REGEX_PRINT_FUNCTION = re.compile(r'(?<!def\s)\bprint\b\s*\([^)]*\)')
REGEX_PRINT_STATEMENT = re.compile(r'(?<![=\s])\s*\bprint\b\s+[^(=]')
REGEX_SELFSELF = re.compile(r'(([A-Za-z0-9_\( ]+||[ ]+|\t)self\.self(?![A-Za-z0-9_]+))')
REGEX_VERSION = re.compile(r'(__version__ = )')
REGEX_VIM = re.compile(r'(# vim( |):( |)fileencoding( |)=( |)(utf\-8|utf8|utf|.*))', re.I)


# Decorators


def decor_hooks(_func):
    """Decorate flake8 extension functions"""
    _func.name = r'flake8_optimal'  # _func.__name__
    _func.version = __version__
    _func.code = _func.__name__.upper()
    return _func


# Classes


class CopyrightChecker(object):
    name = r'CopyrightChecker'
    version = __version__
    code = r'V002'

    def __init__(self, tree, filename):
        self.tree = tree
        self.filename = filename

    @classmethod
    def add_options(cls, parser):
        parser.add_option(
            '--check-copyright', action='store_true',
            help='Checks for copyright notices in every file.'
        )
        parser.config_options.append('check-copyright')
        parser.add_option(
            '--min-file-size-copyright', default=0, action='store', type='int',
            help='Minimum number of characters in a file before requiring a copyright notice.'
        )
        parser.config_options.append('min-file-size-copyright')
        parser.add_option(
            '--author-copyright', default='', action='store',
            help='Checks for a specific author in the copyright notice.'
        )
        parser.config_options.append('author-copyright')
        parser.add_option(
            '--regexp-copyright', default=r'Copyright\s+(\(C\)\s+|\(c\)\s+)?\d{4}\s+%(author)s', action='store',
            help='Changes the copyright regular expression to look for.'
        )
        parser.config_options.append('regexp-copyright')

    @classmethod
    def parse_options(cls, options):
        cls.check_copyright = options.check_copyright
        cls.min_file_size_copyright = options.min_file_size_copyright
        cls.author_copyright = options.author_copyright
        cls.regexp_copyright = options.regexp_copyright

    def run(self):
        if not self.check_copyright:
            return
        toread = max(1024, self.min_file_size_copyright)
        top_of_file = open(self.filename, mode='rt').read(toread)
        if len(top_of_file) < self.min_file_size_copyright:
            return
        author = self.author_copyright if self.author_copyright else r'.*'
        re_copyright = re.compile(self.regexp_copyright % {'author': author}, re.I)
        if not re_copyright.search(top_of_file):
            yield 0, 0, 'V002 : Copyright notice not present', type(self)


class MagicCommentChecker(object):
    """Add '# -*- coding: utf-8 -*-' to the second-line of the script"""
    name = r'MagicComment'
    version = __version__

    def __init__(self, tree, filename):
        self.filename = filename
        self.tree = tree

    @classmethod
    def add_options(cls, parser):
        parser.add_option(
            '--valid-encodings', default='utf-8', action='store',
            help='Acceptable source code encodings for `coding:` magic comment'
        )
        parser.config_options.append('valid-encodings')

    @classmethod
    def parse_options(cls, options):
        cls.encodings = [e.strip().lower() for e in options.valid_encodings.split(',')]

    def run(self):  # noqa C901
        """PEP-263 states that a magic comment must be placed into the source files either as first or second line in the file"""
        try:
            # `# -*- coding: utf-8 -*-`
            with open(self.filename, mode='rt') as _file:
                lines = _file.readlines()[:2]
                if not len(lines):
                    raise StopIteration()
                for lineno, line in enumerate(lines, start=1):
                    matched = re.search(r'coding[:=]\s*([-\w.]+)', line, re.I)
                    if matched:
                        if matched.group(1).lower() not in self.encodings:
                            yield lineno, 0, 'MG02 : Unknown encoding found in coding magic comment', type(self)
                        break
                else:
                    yield 0, 0, 'MG01 : Coding magic comment not found', type(self)
            # `# vim:fileencoding=utf-8`
            with open(self.filename, mode='rt') as _file:
                lines = _file.readlines()[:3]
                if not len(lines):
                    raise StopIteration()
                for lineno, line in enumerate(lines, start=2):
                    matched_vim = re.search(r'# vim:fileencoding=[A-Z0-9\-]+', line, re.I)
                    if matched_vim:
                        break
                else:
                    yield 0, 0, 'MG03 : `# vim:fileencoding=utf-8` magic comment not found', type(self)
        except IOError:
            pass


# Functions (Vague)


@decor_hooks
def v001(logical_line: str, noqa=None):
    """Vague: Specify the exception type"""
    if noqa:
        return None
    _match = REGEX_BLIND_EXCEPT.search(logical_line)
    if _match:
        yield _match.start(), r'V001 : Blind except'
        return None


# Functions (Inconsistency)


@decor_hooks
def x001(logical_line: str, noqa=None):
    """Inconsistency: `__license__` should be `__copyright__`"""
    if noqa:
        return None
    _match = REGEX_LICENSE.search(logical_line)
    if _match and logical_line.startswith(r'__license__'):
        yield _match.start(), r'X001 : `__license__` should be `__copyright__`'
        return None


@decor_hooks
def x002(logical_line: str, noqa=None):
    """Inconsistency: `__email__` does not appear to contain an email-address"""
    if noqa:
        return None
    _match = REGEX_VALID_EMAIL.search(logical_line)
    _match2 = REGEX_EMAIL.search(logical_line)
    if logical_line.startswith(r'__email__ = ') and not _match:
        yield _match2.start(), r'X002 : `__email__` should contain a valid email-address'
        return None


@decor_hooks
def x003(logical_line: str, noqa=None):
    """Inconsistency: `if __name__ is '__main__':`"""
    if noqa:
        return None
    _match = REGEX_INVALID_MAIN.search(logical_line)
    if _match:
        yield _match.start(), 'X003 : Test for main using `if __name__ == \'__main__\':`'
        return None


@decor_hooks
def x004(logical_line: str, noqa=None):
    """Inconsistency: Explicitly declare `mode` when using `open()`
    Use the format `open(FILE, mode='rt', encoding='utf-8')`
    """
    if noqa:
        return None
    _match = REGEX_OPEN.search(logical_line)
    if r'gzip.open' in logical_line or r'bz2.open' in logical_line or r'lzma.open' in logical_line or r'tarfile.open' in logical_line:
        return None
    elif r'urlopen' in logical_line or r'Popen' in logical_line or r'_open' in logical_line:
        return None
    elif _match and r', mode=' not in logical_line:
        yield _match.start(), r'X004 : `open()` missing `mode=`'
        return None


@decor_hooks
def x005(logical_line: str, noqa=None):
    """Inconsistency: Explicitly declare text or binary mode when using `open()`
    Use the format `open(FILE, mode='rt', encoding='utf-8')`
    """
    if noqa:
        return None
    _match = REGEX_OPEN.search(logical_line)
    if r'gzip.open' in logical_line or r'bz2.open' in logical_line or r'lzma.open' in logical_line or r'tarfile.open' in logical_line:
        return None
    elif r'urlopen' in logical_line or r'Popen' in logical_line or r'_open' in logical_line:
        return None
    elif _match and (', mode=\'r\'' in logical_line or ', mode=\'w\'' in logical_line or ', mode=\'a\'' in logical_line or ', mode=\'x\'' in logical_line):
        yield _match.start(), 'X005 : `mode=` in `open()` does not specify text or binary'
        return None


@decor_hooks
def x006(logical_line: str, noqa=None):
    """Inconsistency: When declaring a UTF8 encoding in `open()`, use `encoding='utf-8'`"""
    if noqa:
        return None
    _match = REGEX_OPEN.search(logical_line)
    if r'gzip.open' in logical_line or r'bz2.open' in logical_line or r'lzma.open' in logical_line or r'tarfile.open' in logical_line:
        return None
    elif r'urlopen' in logical_line or r'Popen' in logical_line or r'_open' in logical_line:
        return None
    elif _match and ('encoding=\'utf8\'' in logical_line or 'encoding=\'UTF8\'' in logical_line or'encoding=\'Utf8\'' in logical_line):
        yield _match.start(), r'X006 : Invalid encoding value'
        return None


@decor_hooks
def x007(logical_line: str, noqa=None):
    """Inconsistency: `self.self` usually causes bugs and is not intended"""
    if noqa:
        return None
    _match = REGEX_SELFSELF.search(logical_line)
    if _match:
        yield _match.start(), r'X007 : `self.self` found'
        return None


@decor_hooks
def x008(logical_line: str, noqa=None):
    """Inconsistency: When using `except ExceptionType as VAR:`, name the variable `_err`"""
    if noqa:
        return None
    _match = REGEX_EXCEPTAS.search(logical_line)
    if _match and r'as _err:' not in logical_line:
        yield _match.start(), r'X008 : `except ExceptionType as VAR:` not using `_err`'
        return None


@decor_hooks
def x009(physical_line: str):
    """Inconsistency: Use `#!/usr/bin/env python3` as the hashpling"""
    _match = REGEX_HASHPLING.search(physical_line)
    if _match and physical_line.startswith(r'#!/usr/') and r'#!/usr/bin/env python3' not in physical_line:
        return _match.start(), r'X009 : Invalid hashpling'


@decor_hooks
def x010(physical_line: str):
    """Inconsistency: Use `# vim:fileencoding=utf-8` as the third line of the script"""
    _match = REGEX_VIM.search(physical_line)
    if _match and physical_line.lower().startswith(r'# vim') and r'# vim:fileencoding=utf-8' not in physical_line:
        return _match.start(), r'X010 : Invalid `# vim:fileencoding=utf-8`'


# Functions (Optimize)


@decor_hooks
def z001(logical_line: str, noqa=None):
    """Optimize: Only use `print()` if you truly want that data to be sent to stdout"""
    if noqa:
        return None
    _match = REGEX_PRINT_STATEMENT.search(logical_line)
    if _match:
        yield _match.start(), r'Z001 : `print` statement found'
        return None
    _match = REGEX_PRINT_FUNCTION.search(logical_line)
    if _match:
        yield _match.start(), r'Z001 : `print` function found'
        return None


@decor_hooks
def z002(logical_line: str, noqa=None):
    """Optimize: Change `.add_from_string(` to `.add_from_string(buffer=`"""
    if noqa:
        return None
    _match = REGEX_GTK_ADDFROMSTRING.search(logical_line)
    if _match:
        yield _match.start(), r'Z002 : `add_from_string()` missing `buffer=`'
        return None


@decor_hooks
def z003(logical_line: str, noqa=None):
    """Optimize: Use `raise SystemExit()` to exit application"""
    if noqa:
        return None
    _match = REGEX_EXIT.search(logical_line)
    if _match:
        yield _match.start(), r'Z003 : Use of `exit()` or `sys.exit()`'
        return None


@decor_hooks
def z004(logical_line: str, noqa=None):
    """Optimize: `input()` returns a string, so using `str()` is pointless"""
    if noqa:
        return None
    _match = REGEX_INPUT_STR.search(logical_line)
    if _match:
        yield _match.start(), r'Z004 : Unneeded string conversion with `input()`'
        return None


@decor_hooks
def z005(logical_line: str, noqa=None):
    """Optimize: `if len(X):` will be `False` if length is 0"""
    if noqa:
        return None
    _match = REGEX_LEN_ZERO.search(logical_line)
    if _match:
        yield _match.start(), r'Z005 : Shorten to `if len(X):`'
        return None


@decor_hooks
def z006(logical_line: str, noqa=None):
    """Optimize: `if len(X):` will be `True` if length is not 0"""
    if noqa:
        return None
    _match = REGEX_LEN_IS_ZERO.search(logical_line)
    if _match:
        yield _match.start(), r'Z006 : Shorten to `if not len(X):`'
        return None


# Functions (MISC)


@decor_hooks
def check_todo_notes(physical_line: str):
    """Note: Do not forget that this `todo` note still needs to be finished"""
    if pep8.noqa(physical_line):
        return None
    _match = REGEX_NOTE.search(physical_line)
    if _match:
        return _match.start(), r'T000 : Todo note found'


# Functions (DCJ)


@decor_hooks
def dj01(logical_line: str, noqa=None):
    """Inconsistency: `__version__` should use the format `YYYY.MM.DD`"""
    if noqa:
        return None
    _match = REGEX_DCJ_VERSION.search(logical_line)
    _match2 = REGEX_VERSION.search(logical_line)
    if _match:
        yield _match2.start(), r'DJ01 : Shorten to `if not len(X):`'
        return None

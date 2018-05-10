#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Flake8 plugin

@file flake8_optimal.py
@version 2018.04.27
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
 - dj** = Devyn Collier Johnson's Personal Flake8 Checks
 - MG** = Magic Comments
 - T000 = Todo Note
 - V*** = Vague
 - X*** = Inconsistency
 - Z*** = Optimize

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This software is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this software.
"""


from pycodestyle import noqa as pynoqa

try:
    import regex as re  # noqa: E402  # pylint: disable=C0411
except ImportError:
    import re  # noqa: E402  # pylint: disable=C0411


__version__ = r'2018.04.27'


# PATTERNS #


REGEX_DCJ_VERSION = re.compile(r'__version__ = r\'20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]\'')
REGEX_INPUT_STR = re.compile(r'str\(input\(')
REGEX_VALID_EMAIL = re.compile(r'__email__ = \'[\w\-\.]+@[\w\-]+\.[\w]+\'')
REGEX_EXCEPTAS = re.compile(r'except [\w \(\)\,]+ as [\w]+:')
REGEX_EXIT = re.compile(r'(sys\.exit|exit)\([0-9\-]*\)')
REGEX_GTK_ADDFROMSTRING = re.compile(r'.+\.add_from_string\([\w\'"]+\)')
REGEX_HASHPLING = re.compile(r'^(#!/usr/bin/|#!/bin/).+$')
REGEX_LEN_ZERO = re.compile(r'if len\([\w \+]+\) (\!=|is not) 0:')
REGEX_LEN_IS_ZERO = re.compile(r'if len\([\w \+]+\) (==|is) 0:')
REGEX_NOTE = re.compile(r'# (TODO|FIXME|FIX|REPAIR|FINISH|DEBUG|XXX):', re.I)
REGEX_NOTE_CASE = re.compile(r'# (TODO|FIXME|FIX|REPAIR|FINISH|DEBUG|XXX):')
REGEX_OPEN = re.compile(r'open\(.+\)')
REGEX_OPEN_ARGS = re.compile(r'(mode=\'|encoding=\').+')
REGEX_PRINT_FUNCTION = re.compile(r'(?<!def\s)\bprint\b\s*\([^)]*\)')
REGEX_PRINT_STATEMENT = re.compile(r'(?<![=\s])\s*\bprint\b\s+[^(=]')
REGEX_SELFSELF = re.compile(r'(([\w\( ]+||[ ]+|\t)self\.self(?![\w]+))')


# DECORATORS #


def decor_hooks(_func: object) -> object:
    """Decorate flake8 extension functions"""
    _func.name = r'flake8_optimal'
    _func.version = __version__
    _func.code = _func.__name__.upper()
    return _func


# CLASSES #


class CopyrightChecker(object):
    """Flake8 plugin for ensuring that the copyright notice is present"""

    name = r'CopyrightChecker'
    version = __version__
    code = r'V002'

    def __init__(self, tree: object, filename: str) -> None:
        """Initialize flake8 copyright-checker"""
        self.tree = tree
        self.filename = filename

    @classmethod
    def add_options(cls: type, parser: object) -> None:
        """Options for the flake8 copyright-checker"""
        parser.add_option(
            r'--check-copyright',
            action=r'store_true',
            parse_from_config=True,
            comma_separated_list=True,
            help=r'Checks for copyright notices in every file.'
        )
        parser.add_option(
            r'--min-file-size-copyright',
            default=0, action=r'store',
            type=r'int',
            parse_from_config=True,
            comma_separated_list=True,
            help=r'Minimum number of characters in a file before requiring a copyright notice.'
        )
        parser.add_option(
            r'--author-copyright',
            default=r'',
            action=r'store',
            parse_from_config=True,
            comma_separated_list=True,
            help=r'Checks for a specific author in the copyright notice.'
        )
        parser.add_option(
            r'--regexp-copyright',
            default=r'Copyright\s+(\(C\)\s+|\(c\)\s+)?\d{4}\s+%(author)s',
            action=r'store',
            parse_from_config=True,
            comma_separated_list=True,
            help=r'Changes the regular expression for the desired copyright format.'
        )

    @classmethod
    def parse_options(cls: type, options: object) -> None:
        """Parse options for the flake8 copyright-checker"""
        cls.check_copyright = options.check_copyright
        cls.min_file_size_copyright = options.min_file_size_copyright
        cls.author_copyright = options.author_copyright
        cls.regexp_copyright = options.regexp_copyright

    def run(self) -> None:
        """Execute the flake8 copyright-checker"""
        if not self.check_copyright:
            return
        toread = max(1024, self.min_file_size_copyright)
        top_of_file = open(self.filename, mode=r'rt').read(toread)
        if len(top_of_file) < self.min_file_size_copyright:
            return
        author = self.author_copyright if self.author_copyright else r'.*'
        re_copyright = re.compile(self.regexp_copyright % {r'author': author}, re.I)
        if not re_copyright.search(top_of_file):
            yield 0, 0, r'V002 : Copyright notice not present', type(self)


class MagicCommentChecker(object):
    """Flake8 plugin to ensure magic-comments are present and correctly formatted"""

    name = r'MagicComment'
    version = __version__
    code = r'MG0'

    def __init__(self, tree: object, filename: str) -> None:
        """Initialize flake8 magic-comment-checker"""
        self.filename = filename
        self.tree = tree

    @classmethod
    def add_options(cls: type, parser: object) -> None:
        """Options for the flake8 magic-comment-checker"""
        parser.add_option(
            r'--valid-encodings',
            default=r'utf-8,utf-8-dos,utf-8-mac,utf-8-unix',
            action=r'store',
            parse_from_config=True,
            comma_separated_list=True,
            help=r'Acceptable source code encodings for Magic-Emacs-Comment'
        )

    @classmethod
    def parse_options(cls: type, options: object) -> None:
        """Parse options for the flake8 magic-comment-checker"""
        cls.encodings = [e.strip().lower() for e in options.valid_encodings]

    def run(self) -> None:  # noqa: C901  # pylint: disable=R0912
        """PEP-263 states that a magic comment must be placed into the source files either as first or second line in the file"""
        try:
            with open(self.filename, mode=r'rt') as _file:
                lines = _file.readlines()[:4]
        except IndexError:
            yield 0, 0, r'??? : The file appears to contain five or less lines!', type(self)
        except IOError:
            yield 0, 0, r'??? : Unable to open file!', type(self)
        except UnicodeDecodeError:
            with open(self.filename, mode=r'rt', encoding=r'utf-8') as _file:
                lines = _file.readlines()[:4]
        # Magic-Emacs-Comment
        matched = re.search(r'^# \-\*\- coding: ([a-z0-9\-]+); Mode: Python; indent\-tabs\-mode: nil; tab\-width: 4 \-\*\-$', lines[1])
        if matched:
            if matched.group(1).lower() not in self.encodings:
                yield 2, 0, r'MG02 : Unknown encoding found in Magic-Emacs-Comment', type(self)
            elif not matched:
                yield 0, 0, r'MG01 : Magic-Emacs-Comment is either not found, misplaced, or ill-formed', type(self)
        # Magic-Vim-Comment
        matched_vim = re.search(r'^# vim: set fileencoding=[a-z0-9\-]+ filetype=python syntax=python\.doxygen fileformat=(dos|mac|unix) tabstop=4 expandtab :$', lines[2])
        if not matched_vim:
            yield 0, 0, r'MG03 : Magic-Vim-Comment is either not found, misplaced, or ill-formed', type(self)
        # Magic-Kate-Comment
        matched_vim = re.search(r'^# kate: encoding [a-z0-9\-]+; bom (on|off); syntax python; indent\-mode python; eol (dos|mac|unix); replace\-tabs off; indent\-width 4; tab\-width 4;(|[a-z \-;]+)$', lines[3])
        if not matched_vim:
            yield 0, 0, r'MG04 : Magic-Kate-Comment is either not found, misplaced, or ill-formed', type(self)


# FUNCTIONS (VAGUE) #


@decor_hooks
def v001(logical_line: str, noqa: bool = False) -> None:
    """Vague: Specify the exception type"""
    if noqa:
        return None
    _match = logical_line.find(r'except:')
    if _match != -1:
        yield _match, r'V001 : Blind except (specify the exception type)'
    return None


# FUNCTIONS (INCONSISTENCY) #


@decor_hooks
def x001(logical_line: str, noqa: bool = False) -> None:
    """Inconsistency: `__license__` should be `__copyright__`"""
    if not noqa and logical_line.startswith(r'__license__ = '):
        yield 0, r'X001 : `__license__` should be `__copyright__`'
    return None


@decor_hooks
def x002(physical_line: str) -> tuple or None:
    """Inconsistency: `__email__` does not appear to contain an email-address"""
    if pynoqa(physical_line):
        return None
    _match = REGEX_VALID_EMAIL.search(physical_line)
    if physical_line.startswith(r'__email__ = ') and not _match:
        return (0, r'X002 : `__email__` should contain a valid email-address')
    return None


@decor_hooks
def x003(physical_line: str) -> tuple or None:
    """Inconsistency: `if __name__ is '__main__':`"""
    if pynoqa(physical_line):
        return None
    elif physical_line.startswith('if __name__ is \'__main__\':'):
        return (0, 'X003 : Test for main using `if __name__ == \'__main__\':`')
    return None


@decor_hooks
def x004(logical_line: str, noqa: bool = False) -> None:
    """Inconsistency: Explicitly declare `mode` when using `open()`

    Use the format `open(FILE, mode=r'rt', encoding=r'utf-8')`
    """
    if noqa or any(_test in logical_line for _test in [r'gzip.open', r'bz2.open', r'lzma.open', r'tarfile.open', r'urlopen', r'Popen', r'_open']) or r', mode=' in logical_line:
        return None
    _match = REGEX_OPEN.search(logical_line)
    if _match:
        yield _match.start(), r'X004 : `open()` missing `mode=`'
    return None


@decor_hooks
def x005(logical_line: str, noqa: bool = False) -> None:
    """Inconsistency: Explicitly declare text or binary mode when using `open()`

    Use the format `open(FILE, mode='rt', encoding='utf-8')`
    """
    if noqa or any(_test in logical_line for _test in [r'gzip.open', r'bz2.open', r'lzma.open', r'tarfile.open', r'urlopen', r'Popen', r'_open']):
        return None
    _match = REGEX_OPEN.search(logical_line)
    if _match and r'mode=' in logical_line and any(r', mode=' + _test in logical_line for _test in ['\'r\'', '\'w\'', '\'a\'', '\'x\'']):
        yield _match.start(), r'X005 : `mode=` in `open()` does not specify text nor binary'
    return None


@decor_hooks
def x006(logical_line: str, noqa: bool = False) -> None:
    """Inconsistency: When declaring a UTF8 encoding in `open()`, use `encoding='utf-8'`"""
    if noqa or any(_test in logical_line for _test in [r'gzip.open', r'bz2.open', r'lzma.open', r'tarfile.open', r'urlopen', r'Popen', r'_open']):
        return None
    _match = REGEX_OPEN.search(logical_line)
    if _match and 'encoding=\'utf8\'' in logical_line.lower():
        yield _match.start(), r'X006 : Invalid encoding value'
    return None


@decor_hooks
def x007(logical_line: str, noqa: bool = False) -> None:
    """Inconsistency: `self.self` usually causes bugs and is not intended"""
    if noqa:
        return None
    _match = REGEX_SELFSELF.search(logical_line)
    if _match:
        yield _match.start(), r'X007 : `self.self` found'
    return None


@decor_hooks
def x008(logical_line: str, noqa: bool = False) -> None:
    """Inconsistency: When using `except ExceptionType as VAR:`, name the variable `_err`"""
    if noqa:
        return None
    _match = REGEX_EXCEPTAS.search(logical_line)
    if _match and r'as _err:' not in logical_line:
        yield _match.start(), r'X008 : `except ExceptionType as VAR:` not using `_err`'
    return None


@decor_hooks
def x009(physical_line: str) -> tuple or None:
    """Inconsistency: Use `#!/usr/bin/env python3` as the hashpling"""
    if pynoqa(physical_line):
        return None
    _match = REGEX_HASHPLING.search(physical_line)
    if _match and physical_line.strip() != r'#!/usr/bin/env python3':
        return (0, r'X009 : Invalid hashpling')
    return None


# FUNCTIONS (OPTIMIZE) #


@decor_hooks
def z001(logical_line: str, noqa: bool = False) -> None:
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
def z002(logical_line: str, noqa: bool = False) -> None:
    """Optimize: Change `.add_from_string(` to `.add_from_string(buffer=`"""
    if noqa:
        return None
    _match = REGEX_GTK_ADDFROMSTRING.search(logical_line)
    if _match:
        yield _match.start(), r'Z002 : `add_from_string()` missing `buffer=`'
    return None


@decor_hooks
def z003(logical_line: str, noqa: bool = False) -> None:
    """Optimize: Use `raise SystemExit()` to exit application"""
    if noqa:
        return None
    _match = REGEX_EXIT.search(logical_line)
    if _match:
        yield _match.start(), r'Z003 : Use `raise SystemExit()` to exit application'
    return None


@decor_hooks
def z004(logical_line: str, noqa: bool = False) -> None:
    """Optimize: `input()` returns a string, so using `str()` is pointless"""
    if noqa:
        return None
    _match = REGEX_INPUT_STR.search(logical_line)
    if _match:
        yield _match.start(), r'Z004 : Unneeded string conversion with `input()`'
    return None


@decor_hooks
def z005(logical_line: str, noqa: bool = False) -> None:
    """Optimize: `if X:` will be `False` if the object has a zero length"""
    if noqa:
        return None
    _match = REGEX_LEN_ZERO.search(logical_line)
    if _match:
        yield _match.start(), r'Z005 : Shorten to `if X:`'
    return None


@decor_hooks
def z006(logical_line: str, noqa: bool = False) -> None:
    """Optimize: `if X:` will be `True` if the object does not have a zero length"""
    if noqa:
        return None
    _match = REGEX_LEN_IS_ZERO.search(logical_line)
    if _match:
        yield _match.start(), r'Z006 : Shorten to `if not X:`'
    return None


@decor_hooks
def z007(logical_line: str, noqa: bool = False) -> None:
    """Optimize: Use `r` before single-quote in `mode` and `encoding` argument values"""
    if noqa:
        return None
    _match = REGEX_OPEN_ARGS.search(logical_line)
    if _match:
        yield _match.start(), r'Z007 : Use `r` before single-quote in `mode` and `encoding` argument values'
    return None


@decor_hooks
def z008(logical_line: str, noqa: bool = False) -> None:
    """Optimize: Import pycodestyle instead of pep8"""
    if not noqa and (r'import pep8' in logical_line or r'from pep8' in logical_line):
        yield 0, r'Z008 : Import pycodestyle instead of pep8'
    return None


@decor_hooks
def z009(logical_line: str, noqa: bool = False) -> None:
    """Optimize: Import pydocstyle instead of pep257"""
    if not noqa and (r'import pep257' in logical_line or r'from pep257' in logical_line):
        yield 0, r'Z009 : Import pydocstyle instead of pep257'
    return None


# FUNCTIONS (MISC) #


@decor_hooks
def check_todo_notes(physical_line: str) -> tuple or None:
    """Note: Do not forget that this `todo` note still needs to be finished"""
    if pynoqa(physical_line):
        return None
    _match = REGEX_NOTE.search(physical_line)
    if _match:
        col = _match.start()
        return (col, r'T000 : Todo note found')
    return None


# FUNCTIONS (DCJ) #


@decor_hooks
def dj01(physical_line: str) -> tuple or None:
    """Inconsistency: `__version__` should use the format `__version__ = r'YYYY.MM.DD'`"""
    if pynoqa(physical_line):
        return None
    elif physical_line.startswith(r'__version__ = ') and not REGEX_DCJ_VERSION.search(physical_line):
        return (0, 'DJ01 : `__version__` should use the format `__version__ = r\'YYYY.MM.DD\'`')
    return None


@decor_hooks
def dj02(physical_line: str) -> tuple or None:
    """Inconsistency: Use all caps for Todo-comments"""
    if pynoqa(physical_line):
        return None
    _match = REGEX_NOTE.search(physical_line)
    _match2 = REGEX_NOTE_CASE.search(physical_line)
    if _match and not _match2:
        return (_match.start(), r'DJ02 : Use all caps for Todo-comments')
    return None

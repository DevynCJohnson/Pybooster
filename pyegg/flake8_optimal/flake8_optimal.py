#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Flake8 plugin used to scan for various inconsistencies and issues.

@file flake8_optimal.py
@version 2020.03.29
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


from typing import Callable, Generator, Optional, Tuple

from pycodestyle import noqa as pynoqa

try:  # Regular Expression module
    from regex import compile as rgxcompile, IGNORECASE, search as rgxsearch
except ImportError:
    from re import compile as rgxcompile, IGNORECASE, search as rgxsearch


__docformat__: str = r'restructuredtext en'
__version__: str = r'2020.03.29'


# PATTERNS #


PY_HASHPLINGS: set = {r'#!/usr/bin/env python4', r'#!/usr/bin/env python4.0', r'#!/usr/bin/env python4.1', r'#!/usr/bin/env python4.2', r'#!/usr/bin/env python4.3', r'#!/usr/bin/env python3', r'#!/usr/bin/env python3.3', r'#!/usr/bin/env python3.4', r'#!/usr/bin/env python3.5', r'#!/usr/bin/env python3.6', r'#!/usr/bin/env python3.7', '#!/usr/bin/env python3.8', '#!/usr/bin/env python3.9', r'#!/usr/bin/env python2', r'#!/usr/bin/env python2.7', r'#!/usr/bin/env python'}
REGEX_DCJ_VERSION = rgxcompile(r'__version__ = r\'20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]\'')
REGEX_INPUT_STR = rgxcompile(r'str\(input\(')
REGEX_VALID_EMAIL = rgxcompile(r'__email__ = \'[\w\-\.]+@[\w\-]+\.[\w]+\'')
REGEX_EXCEPTAS = rgxcompile(r'except [\w \(\)\,]+ as [\w]+:')
REGEX_EXIT = rgxcompile(r'[ \t\(\[]*(sys\.exit|exit|sysexit|_Exit)\(.*\)')
REGEX_GTK_ADDFROMSTRING = rgxcompile(r'.+\.add_from_string\([\w\'"]+\)')
REGEX_HASHPLING = rgxcompile(r'^(#!/usr/bin/env|#!/usr/bin/|#!/bin/).+$')
REGEX_LEN_ZERO = rgxcompile(r'if len\([\w \+]+\) (\!=|is not) 0:')
REGEX_LEN_IS_ZERO = rgxcompile(r'if len\([\w \+]+\) (==|is) 0:')
REGEX_NOTE = rgxcompile(r'# (DEBUG|DEPRECATED|DISABLED|FINISH|FIX|FIXME|REPAIR|TESTING|TODEBUG|TODO|TOMV|TORM|XXX):', flags=IGNORECASE)
REGEX_NOTE_CASE = rgxcompile(r'# (DEBUG|DEPRECATED|DISABLED|FINISH|FIX|FIXME|REPAIR|TESTING|TODEBUG|TODO|TOMV|TORM|XXX): ')
REGEX_OPEN = rgxcompile(r'open\(.+\)')
REGEX_OPEN_ARGS = rgxcompile(r'(mode=\'|encoding=\').+')
REGEX_PRINT_FUNCTION = rgxcompile(r'(?<!def\s)\bprint\b\s*\([^)]*\)')
REGEX_PRINT_STATEMENT = rgxcompile(r'(?<![=\s])\s*\bprint\b\s+[^(=]')
REGEX_SELFSELF = rgxcompile(r'(([\w\( ]+||[ ]+|\t)self\.self(?![\w]+))')


# DECORATORS #


def logical_hook(_func: Callable[[str, bool], Generator[Tuple[int, str], None, None]]) -> Callable[[str, bool], Generator[Tuple[int, str], None, None]]:
    """Decorate flake8 extension functions that read the logical lines."""
    _func.name = r'flake8_optimal'  # type: ignore
    _func.version = __version__  # type: ignore
    _func.code = _func.__name__.upper()  # type: ignore
    return _func


def physical_hook(_func: Callable[[str], Optional[Tuple[int, str]]]) -> Callable[[str], Optional[Tuple[int, str]]]:
    """Decorate flake8 extension functions that read the physical lines."""
    _func.name = r'flake8_optimal'  # type: ignore
    _func.version = __version__  # type: ignore
    _func.code = _func.__name__.upper()  # type: ignore
    return _func


# CLASSES #


class CopyrightChecker():
    """Flake8 plugin for ensuring that the copyright notice is present."""

    name: str = r'CopyrightChecker'
    version: str = __version__
    code: str = r'V002'

    def __init__(self: object, tree: object, filename: str) -> None:
        """Initialize flake8 copyright-checker."""
        self.tree = tree
        self.filename = filename

    @classmethod
    def add_options(cls: object, parser: object) -> None:
        """Options for the flake8 copyright-checker."""
        parser.add_option(  # noqa: T484
            r'--check-copyright',
            action=r'store_true',
            parse_from_config=True,
            comma_separated_list=True,
            help=r'Checks for copyright notices in every file.'
        )
        parser.add_option(  # noqa: T484
            r'--min-file-size-copyright',
            default=0, action=r'store',
            type=r'int',
            parse_from_config=True,
            comma_separated_list=True,
            help=r'Minimum number of characters in a file before requiring a copyright notice.'
        )
        parser.add_option(  # noqa: T484
            r'--author-copyright',
            default=r'',
            action=r'store',
            parse_from_config=True,
            comma_separated_list=True,
            help=r'Checks for a specific author in the copyright notice.'
        )
        parser.add_option(  # noqa: T484
            r'--regexp-copyright',
            default=r'Copyright\s+(\(C\)\s+|\(c\)\s+)?\d{4}\s+%(author)s',
            action=r'store',
            parse_from_config=True,
            comma_separated_list=True,
            help=r'Changes the regular expression for the desired copyright format.'
        )

    @classmethod
    def parse_options(cls: object, options: object) -> None:
        """Parse options for the flake8 copyright-checker."""
        cls.check_copyright = options.check_copyright  # noqa: T484
        cls.min_file_size_copyright = options.min_file_size_copyright  # noqa: T484
        cls.author_copyright = options.author_copyright  # noqa: T484
        cls.regexp_copyright = options.regexp_copyright  # noqa: T484

    def run(self: object) -> Generator[Tuple[int, int, str, type], None, None]:
        """Execute the flake8 copyright-checker."""
        if not self.check_copyright:  # noqa: T484
            return
        toread = max(1024, self.min_file_size_copyright)  # noqa: T484
        top_of_file = open(self.filename, mode=r'rt').read(toread)  # noqa: T484
        if len(top_of_file) < self.min_file_size_copyright:  # noqa: T484
            return
        author = self.author_copyright if self.author_copyright else r'.*'  # noqa: T484
        re_copyright = rgxcompile(self.regexp_copyright % {r'author': author}, flags=IGNORECASE)  # noqa: T484
        if not re_copyright.search(top_of_file):
            yield 0, 0, r'V002 : Copyright notice not present', type(self)


class MagicCommentChecker():
    """Flake8 plugin to ensure magic-comments are present and correctly formatted."""

    name: str = r'MagicComment'
    version: str = __version__
    code: str = r'MG0'

    def __init__(self: object, tree: object, filename: str) -> None:
        """Initialize flake8 magic-comment-checker."""
        self.filename = filename
        self.tree = tree

    @classmethod
    def add_options(cls: object, parser: object) -> None:
        """Options for the flake8 magic-comment-checker."""
        parser.add_option(  # noqa: T484
            r'--valid-encodings',
            default=r'utf-8,utf-8-dos,utf-8-mac,utf-8-unix',
            action=r'store',
            parse_from_config=True,
            comma_separated_list=True,
            help=r'Acceptable source code encodings for Magic-Emacs-Comment'
        )

    @classmethod
    def parse_options(cls: object, options: object) -> None:
        """Parse options for the flake8 magic-comment-checker."""
        cls.encodings = [e.strip().casefold() for e in options.valid_encodings]  # noqa: T484

    def run(self: object) -> Generator[Tuple[int, int, str, object], None, None]:  # noqa: C901,T484  # pylint: disable=R0912
        """PEP-263 states that a magic comment must be placed into the source files either as first or second line in the file."""
        try:
            with open(self.filename, mode=r'rt') as _file:  # noqa: T484
                lines = _file.readlines()[:4]
        except IndexError:
            yield 0, 0, r'??? : The file appears to contain five or less lines!', type(self)
        except IOError:
            yield 0, 0, r'??? : Unable to open file!', type(self)
        except UnicodeDecodeError:
            with open(self.filename, mode=r'rt', encoding=r'utf-8') as _file:  # noqa: T484
                lines = _file.readlines()[:4]
        # Magic-Emacs-Comment
        matched = rgxsearch(r'^# \-\*\- coding: ([a-z0-9\-]+); Mode: Python; indent\-tabs\-mode: nil; tab\-width: 4 \-\*\-$', lines[1])
        if matched:
            if matched.group(1).casefold() not in self.encodings:  # noqa: T484
                yield 2, 0, r'MG02 : Unknown encoding found in Magic-Emacs-Comment', type(self)
            elif not matched:
                yield 0, 0, r'MG01 : Magic-Emacs-Comment is either not found, misplaced, or ill-formed', type(self)
        # Magic-Vim-Comment
        matched_vim = rgxsearch(r'^# vim: set fileencoding=[a-z0-9\-]+ filetype=python syntax=python\.doxygen fileformat=(dos|mac|unix) tabstop=4 expandtab :$', lines[2])
        if not matched_vim:
            yield 0, 0, r'MG03 : Magic-Vim-Comment is either not found, misplaced, or ill-formed', type(self)
        # Magic-Kate-Comment
        matched_vim = rgxsearch(r'^# kate: encoding [a-z0-9\-]+; bom (on|off); syntax python; indent\-mode python; eol (dos|mac|unix); replace\-tabs off; indent\-width 4; tab\-width 4;(|[a-z \-;]+)$', lines[3])
        if not matched_vim:
            yield 0, 0, r'MG04 : Magic-Kate-Comment is either not found, misplaced, or ill-formed', type(self)


# FUNCTIONS (VAGUE) #


@logical_hook
def v001(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Vague: Specify the exception type."""
    if noqa:
        return None
    _match = logical_line.find(r'except:')
    if _match != -1:
        yield _match, r'V001 : Blind except (specify the exception type)'
    return None


# FUNCTIONS (INCONSISTENCY) #


@logical_hook
def x001(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Inconsistency: `__license__` should be `__copyright__`."""
    if not noqa and logical_line.startswith(r'__license__ = '):
        yield 0, r'X001 : `__license__` should be `__copyright__`'


@physical_hook
def x002(physical_line: str) -> Optional[Tuple[int, str]]:
    """Inconsistency: `__email__` does not appear to contain an email-address."""
    if pynoqa(physical_line):
        return None
    _match = REGEX_VALID_EMAIL.search(physical_line)
    if physical_line.startswith(r'__email__ = ') and not _match:
        return (0, r'X002 : `__email__` should contain a valid email-address')
    return None


@physical_hook
def x003(physical_line: str) -> Optional[Tuple[int, str]]:
    """Inconsistency: `if __name__ is '__main__':`."""
    if pynoqa(physical_line):
        return None
    if physical_line.startswith('if __name__ is \'__main__\':'):
        return (0, 'X003 : Test for main using `if __name__ == \'__main__\':`')
    return None


@logical_hook
def x004(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Inconsistency: Explicitly declare `mode` when using `open()`.

    Use the format `open(FILE, mode=r'rt', encoding=r'utf-8')`
    """
    if noqa or any(_test in logical_line for _test in {r'gzip.open', r'bz2.open', r'lzma.open', r'tarfile.open', r'urlopen', r'Popen', r'_open'}) or r', mode=' in logical_line:
        return None
    _match = REGEX_OPEN.search(logical_line)
    if _match:
        yield _match.start(), r'X004 : `open()` missing `mode=`'
    return None


@logical_hook
def x005(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Inconsistency: Explicitly declare text or binary mode when using `open()`.

    Use the format `open(FILE, mode='rt', encoding='utf-8')`
    """
    if noqa or any(_test in logical_line for _test in {r'gzip.open', r'bz2.open', r'lzma.open', r'tarfile.open', r'urlopen', r'Popen', r'_open'}):
        return None
    _match = REGEX_OPEN.search(logical_line)
    if _match and r'mode=' in logical_line and any(fr', mode={_test}' in logical_line for _test in {'\'r\'', '\'w\'', '\'a\'', '\'x\''}):
        yield _match.start(), r'X005 : `mode=` in `open()` does not specify text nor binary'
    return None


@logical_hook
def x006(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Inconsistency: When declaring a UTF8 encoding in `open()`, use `encoding='utf-8'`."""
    if noqa or any(_test in logical_line for _test in {r'gzip.open', r'bz2.open', r'lzma.open', r'tarfile.open', r'urlopen', r'Popen', r'_open'}):
        return None
    _match = REGEX_OPEN.search(logical_line)
    if _match and 'encoding=\'utf8\'' in logical_line.casefold():
        yield _match.start(), r'X006 : Invalid encoding value'
    return None


@logical_hook
def x007(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Inconsistency: `self.self` usually causes bugs and is not intended."""
    if noqa:
        return None
    _match = REGEX_SELFSELF.search(logical_line)
    if _match:
        yield _match.start(), r'X007 : `self.self` found'
    return None


@logical_hook
def x008(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Inconsistency: When using `except ExceptionType as VAR:`, name the variable `_err`."""
    if noqa:
        return None
    _match = REGEX_EXCEPTAS.search(logical_line)
    if _match and r'as _err:' not in logical_line:
        yield _match.start(), r'X008 : `except ExceptionType as VAR:` not using `_err`'
    return None


@physical_hook
def x009(physical_line: str) -> Optional[Tuple[int, str]]:
    """Inconsistency: Use `#!/usr/bin/env python3` as the hashpling."""
    if pynoqa(physical_line):
        return None
    _match = REGEX_HASHPLING.search(physical_line)
    _physical_line = physical_line.strip()
    if _match and _physical_line not in PY_HASHPLINGS:
        return (0, r'X009 : Invalid hashpling')
    return None


# FUNCTIONS (OPTIMIZE) #


@logical_hook
def z001(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Optimize: Use `stdout.write()` or `stderr.write()` instead of the print function/statement."""
    if noqa:
        return None
    _match = REGEX_PRINT_STATEMENT.search(logical_line)
    if _match:
        yield _match.start(), r'Z001 : Use `stdout.write()` or `stderr.write()` instead of the print function/statement'
        return None
    _match = REGEX_PRINT_FUNCTION.search(logical_line)
    if _match:
        yield _match.start(), r'Z001 : Use `stdout.write()` or `stderr.write()` instead of the print function/statement'
    return None


@logical_hook
def z002(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Optimize: Change `.add_from_string(` to `.add_from_string(buffer=`."""
    if noqa:
        return None
    _match = REGEX_GTK_ADDFROMSTRING.search(logical_line)
    if _match:
        yield _match.start(), r'Z002 : `add_from_string()` missing `buffer=`'
    return None


@logical_hook
def z003(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Optimize: Use `raise SystemExit()` to exit application."""
    if noqa:
        return None
    _match = REGEX_EXIT.search(logical_line)
    if logical_line.strip().startswith(r'def '):
        return None
    if _match and r'raise SystemExit(' not in logical_line and r'xit(self)' not in logical_line:
        yield _match.start(), r'Z003 : Use `raise SystemExit()` to exit application'
    return None


@logical_hook
def z004(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Optimize: `input()` returns a string, so using `str()` is pointless."""
    if noqa:
        return None
    _match = REGEX_INPUT_STR.search(logical_line)
    if _match:
        yield _match.start(), r'Z004 : Unneeded string conversion with `input()`'
    return None


@logical_hook
def z005(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Optimize: `if X:` will be `False` if the object has a zero length."""
    if noqa:
        return None
    _match = REGEX_LEN_ZERO.search(logical_line)
    if _match:
        yield _match.start(), r'Z005 : Shorten to `if X:`'
    return None


@logical_hook
def z006(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Optimize: `if X:` will be `True` if the object does not have a zero length."""
    if noqa:
        return None
    _match = REGEX_LEN_IS_ZERO.search(logical_line)
    if _match:
        yield _match.start(), r'Z006 : Shorten to `if not X:`'
    return None


@logical_hook
def z007(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Optimize: Use `r` before single-quote in `mode` and `encoding` argument values."""
    if noqa:
        return None
    _match = REGEX_OPEN_ARGS.search(logical_line)
    if _match:
        yield _match.start(), r'Z007 : Use `r` before single-quote in `mode` and `encoding` argument values'
    return None


@logical_hook
def z008(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Optimize: Import pycodestyle instead of pep8."""
    if not noqa and (r'import pep8' in logical_line or r'from pep8' in logical_line):
        yield 0, r'Z008 : Import pycodestyle instead of pep8'


@logical_hook
def z009(logical_line: str, noqa: bool = False) -> Generator[Tuple[int, str], None, None]:
    """Optimize: Import pydocstyle instead of pep257."""
    if not noqa and (r'import pep257' in logical_line or r'from pep257' in logical_line):
        yield 0, r'Z009 : Import pydocstyle instead of pep257'


# FUNCTIONS (MISC) #


@physical_hook
def check_todo_notes(physical_line: str) -> Optional[Tuple[int, str]]:
    """Note: Do not forget that this `todo` note still needs to be finished."""
    if pynoqa(physical_line):
        return None
    _match = REGEX_NOTE.search(physical_line)
    if _match:
        col = _match.start()
        return (col, r'T000 : Todo note found')
    return None


# FUNCTIONS (DCJ) #


@physical_hook
def dj01(physical_line: str) -> Optional[Tuple[int, str]]:
    """Inconsistency: `__version__` should use the format `__version__ = r'YYYY.MM.DD'`."""
    if pynoqa(physical_line):
        return None
    if physical_line.startswith(r'__version__ = ') and not REGEX_DCJ_VERSION.search(physical_line):
        return (0, 'DJ01 : `__version__` should use the format `__version__ = r\'YYYY.MM.DD\'`')
    return None


@physical_hook
def dj02(physical_line: str) -> Optional[Tuple[int, str]]:
    """Inconsistency: Use all caps for Todo-comments."""
    if pynoqa(physical_line):
        return None
    _match = REGEX_NOTE.search(physical_line)
    _match2 = REGEX_NOTE_CASE.search(physical_line)
    if _match and not _match2:
        return (_match.start(), r'DJ02 : Use all caps for Todo-comments')
    return None

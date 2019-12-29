#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief CxFreeze setup file for Desktop-Entry-Maker

@file setup_desktop_entry_maker.py
@version 2019.06.01
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section SETUP

python3 ./setup.py build && strip --strip-debug --strip-unneeded --remove-section=.comment --remove-section=.note ./build/exe.linux-x86_64-3.6/*.so* && strip --strip-debug --strip-unneeded --remove-section=.comment --remove-section=.note ./build/exe.linux-x86_64-3.6/desktop-entry-maker && makeself --complevel 9 --noprogress --nowait --nox11 ./build/exe.linux-x86_64-3.6/ ./desktop-entry-maker.run "Loading desktop-entry-maker" ./desktop-entry-maker

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


from os import environ
from os.path import dirname, join as joinpath
from time import strftime
from sys import path, platform

from cx_Freeze import Executable, setup


# GLOBALS #


DEBUG: bool = False
PYTHONOPTIMIZE: bool = True
PLAT = r'Win32GUI' if platform == r'win32' else None


# ENVIRONMENT #


environ['PYTHONOPTIMIZE'] = 'True'
environ['GI_TYPELIB_PATH'] = '/usr/lib/girepository-1.0'
environ['PATH'] = (
    environ['PATH'] +
    r':/lib' +
    r':/lib64' +
    r':/lib/x86_64-linux-gnu' +
    r':/usr/lib' +
    r':/usr/lib/x86_64-linux-gnu' +
    r':/usr/share/libc-bin' +
    r':/usr/share/gtk-engines' +
    r':/usr/share/gtk-3.0' +
    r':/usr/lib/girepository-1.0' +
    r':/usr/lib/python3/dist-packages' +
    r':/usr/lib/python3/dist-packages/gi' +
    r':/usr/lib/python3/dist-packages/gi/overrides' +
    r':/usr/share/gtksourceview-3.0' +
    r':/usr/share/libtimezonemap'
)


# MAIN SETUP #


def get_version() -> str:
    """Get the version number from the script"""
    with open(r'../scripts/desktop-entry-maker', mode=r'rt', encoding=r'utf-8') as _file:
        for _line in _file:
            if _line.startswith(r'        version='):
                _line = _line.replace(r'        version=', r'').replace('r\'', r'').replace(r',', r'')
                return _line.replace('\'', r'').strip().replace(r'.0', r'.')
    return strftime(r'%Y.%m.%d').replace(r'.0', r'.')


if __name__ == '__main__':
    setup(
        name=r'Desktop-Entry-Maker',
        version=get_version(),
        author=r'Devyn Collier Johnson',
        author_email=r'DevynCJohnson@Gmail.com',
        license=r'LGPLv3',
        url=r'http://dcjtech.info/',
        description=r'Create Desktop Entry Files',
        classifiers=[
            r'Development Status :: 5 - Production/Stable',
            r'Environment :: X11 Applications :: GTK',
            r'Intended Audience :: Developers',
            r'Intended Audience :: End Users/Desktop',
            r'License :: OSI Approved :: GNU Lesser General Public License v3 or later (LGPLv3+)',
            r'Operating System :: OS Independent',
            r'Programming Language :: Python :: 3',
            r'Programming Language :: Python :: Implementation :: CPython',
            r'Topic :: Desktop Environment',
            r'Topic :: System',
            r'Topic :: System :: Systems Administration',
            r'Topic :: Utilities'
        ],
        executables=[
            Executable(
                script=r'../desktop-entry-maker',
                initScript=None,
                base=PLAT,
                targetName=None,
                icon=joinpath(dirname(__file__), r'../themes/Opticons/apps/menueditor.svg'),
                shortcutName=None,
                shortcutDir=None,
                copyright=r'LGPLv3',
                trademarks=None
            )
        ],
        options={
            r'build_exe': {
                r'packages': [r'gi.overrides', r'gi.repository'],
                r'optimize': 2,
                r'path': path + [
                    r'/usr/lib/girepository-1.0',
                    r'/usr/lib/python3/dist-packages/gi/',
                    r'/usr/lib/python3/dist-packages/gi/overrides',
                    r'/usr/share/gtk-3.0',
                    r'/usr/share/gtk-engines'
                ]
            }
        }
    )

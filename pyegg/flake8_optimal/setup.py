#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Setup file for Flake8-Optimal plugin.

@file setup.py
@version 2020.03.29
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section Installation
python3 ./setup.py install

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


from os.path import dirname, join as joinpath

from setuptools import setup

from flake8_optimal import __version__


def read(fname: str) -> str:
    """Return the contents of the specified file as a string."""
    return open(joinpath(dirname(__file__), fname), mode=r'rt', encoding=r'utf-8').read()


if __name__ == '__main__':
    setup(
        name=r'flake8_optimal',
        version=__version__,
        author=r'Devyn Collier Johnson',
        author_email=r'DevynCJohnson@Gmail.com',
        license=r'LGPLv3',
        url=r'https://github.com/DevynCJohnson/Pybooster',
        description=r'Extension for flake8 that finds various inconsistencies and suggests optimized code',
        long_description=read(r'README.rst'),
        keywords=[r'flake8', r'optimize', r'optimal', r'inconsistencies', r'inconsistency', r'standardize'],
        platforms=r'any',
        py_modules=[r'flake8_optimal'],
        python_requires=r'>=3.7',
        install_requires=[r'flake8'],
        tests_require=[r'flake8>=3.4'],
        zip_safe=False,
        classifiers=[
            r'Development Status :: 5 - Production/Stable',
            r'Environment :: Console',
            r'Intended Audience :: Developers',
            r'License :: OSI Approved :: GNU Lesser General Public License v3 or later (LGPLv3+)',
            r'Operating System :: OS Independent',
            r'Programming Language :: Python :: 3',
            r'Programming Language :: Python :: Implementation :: CPython',
            r'Topic :: Software Development :: Libraries :: Python Modules',
            r'Topic :: Software Development :: Quality Assurance'
        ],
        entry_points={
            r'flake8.extension': [
                r'MG0 = flake8_optimal:MagicCommentChecker',
                r'V001 = flake8_optimal:v001',
                r'V002 = flake8_optimal:CopyrightChecker',
                r'X001 = flake8_optimal:x001',
                r'X002 = flake8_optimal:x002',
                r'X003 = flake8_optimal:x003',
                r'X004 = flake8_optimal:x004',
                r'X005 = flake8_optimal:x005',
                r'X006 = flake8_optimal:x006',
                r'X007 = flake8_optimal:x007',
                r'X008 = flake8_optimal:x008',
                r'X009 = flake8_optimal:x009',
                r'Z001 = flake8_optimal:z001',
                r'Z002 = flake8_optimal:z002',
                r'Z003 = flake8_optimal:z003',
                r'Z004 = flake8_optimal:z004',
                r'Z005 = flake8_optimal:z005',
                r'Z006 = flake8_optimal:z006',
                r'Z007 = flake8_optimal:z007',
                r'Z008 = flake8_optimal:z008',
                r'Z009 = flake8_optimal:z009',
                r'T000 = flake8_optimal:check_todo_notes',
                r'DJ01 = flake8_optimal:dj01',
                r'DJ02 = flake8_optimal:dj02'
            ]
        }
    )

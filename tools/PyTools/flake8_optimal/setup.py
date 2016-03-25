#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8

# sudo python3 ./setup.py install

from __future__ import with_statement

from setuptools import setup


def get_version():
    """Get the version number from the script"""
    try:
        with open(r'flake8_optimal.py', mode='rt', encoding='utf-8') as _file:
            for _line in _file:
                if _line.startswith(r'__version__'):
                    return eval(_line.split(r'=')[-1])
    except FileNotFoundError:
        with open(r'./flake8_optimal/flake8_optimal.py', mode='rt', encoding='utf-8') as _file:
            for _line in _file:
                if _line.startswith(r'__version__'):
                    return eval(_line.split(r'=')[-1])


install_requires = [r'flake8']
test_requires = [r'flake8>=2.0']

setup(
    name='flake8_optimal',
    version=get_version(),
    description='Find various inconsistencies and suggest optimized code',
    long_description='Extension for flake8 that finds various inconsistencies and suggests optimized code',
    keywords='flake8 optimize optimal inconsistencies inconsistency',
    author='Devyn Collier Johnson',
    author_email='DevynCJohnson@Gmail.com',
    url='',
    license='LGPLv3',
    py_modules=['flake8_optimal'],
    zip_safe=False,
    entry_points={
        'flake8.extension': [
            'MG0 = flake8_optimal:MagicCommentChecker',
            'V001 = flake8_optimal:v001',
            'V002 = flake8_optimal:CopyrightChecker',
            'X001 = flake8_optimal:x001',
            'X002 = flake8_optimal:x002',
            'X003 = flake8_optimal:x003',
            'X004 = flake8_optimal:x004',
            'X005 = flake8_optimal:x005',
            'X006 = flake8_optimal:x006',
            'X007 = flake8_optimal:x007',
            'X008 = flake8_optimal:x008',
            'X009 = flake8_optimal:x009',
            'X010 = flake8_optimal:x010',
            'Z001 = flake8_optimal:z001',
            'Z002 = flake8_optimal:z002',
            'Z003 = flake8_optimal:z003',
            'Z004 = flake8_optimal:z004',
            'Z005 = flake8_optimal:z005',
            'Z006 = flake8_optimal:z006',
            'T000 = flake8_optimal:check_todo_notes',
            'DJ01 = flake8_optimal:dj01',
        ],
    },
    install_requires=install_requires,
    tests_require=test_requires,
    classifiers=[
        'Development Status :: 5 - Production/Stable',
        'Environment :: Console',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: LGPL3 License',
        'Operating System :: OS Independent',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3',
        'Topic :: Software Development :: Libraries :: Python Modules',
        'Topic :: Software Development :: Quality Assurance',
    ],
)

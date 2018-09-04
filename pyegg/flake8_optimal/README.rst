Flake8 Optimal Plugin
=====================

Extension for flake8 that finds various inconsistencies and suggests optimized code

This module provides a plugin for ``flake8``, the Python code checker.

Error Codes:
dj** = Devyn Collier Johnson's Personal Flake8 Checks
MG** = Magic Comments
T000 = Todo Note
V*** = Vague
X*** = Inconsistency
Z*** = Optimize


Installation
------------

You can install or upgrade ``flake8_optimal`` with these commands::

  $ pip install flake8_optimal
  $ pip install --upgrade flake8_optimal


Plugin for Flake8
-----------------

When both ``flake8`` and ``flake8_optimal`` are installed, the plugin is
available in ``flake8``::

    $ flake8 --version
    3.5.0 (CopyrightChecker: 2018.04.27, MagicComment: 2018.04.27, flake8-mypy: 17.8.0, flake8_optimal: 2018.04.27, mccabe: 0.6.1, pycodestyle: 2.3.1, pyflakes: 1.6.0) CPython 3.6.3 on Linux


Changes
-------

2018.03.09 - 2018-03-09
```````````````````````
* Added the "TESTING" todo note for the scanner to find (T000)

2018.11.05 - 2018-11-05
```````````````````````
* Added additional todo notes for the scanner to find (T000)
* Added additional forms of exit for the scanner to find (Z003)
* Reworded message for Z001

2018.27.04 - 2018-27-04
```````````````````````
* Fixed unicode decoding issues
* Optimized the magic-comment checker

2018.25.04 - 2018-25-04
```````````````````````
* Added Z009 and applied some optimizations

2017.11.04 - 2017-11-04
```````````````````````
* Optimizations to flake8_optimal.py and setup.py

2017.10.29 - 2017-10-29
```````````````````````
* Modified MagicCommentChecker

2017.10.28 - 2017-10-28
```````````````````````
* Add more checks

2017.10.21 - 2017-10-21
```````````````````````
* Compatible with Flake8 v3
* Optimizations

2017.07.16 - 2017-07-16
```````````````````````
* Fixes

2016.03.18 - 2016-03-18
```````````````````````
* Fixes

2016.01.14 - 2016-01-14
```````````````````````
* First release

Flake8 Optimal Plugin
=====================

Extension for flake8 that finds various inconsistencies and suggests optimized code

This module provides a plugin for ``flake8``, the Python code checker.

Error Codes
-----------

* dj** = Devyn Collier Johnson's Personal Flake8 Checks
* MG** = Magic Comments
* T000 = Todo Note
* V*** = Vague
* X*** = Inconsistency
* Z*** = Optimize


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
    3.7.7 (CopyrightChecker: 2019.07.14, MagicComment: 2019.07.14, aaa: 0.6.2, flake8-comprehensions: 2.1.0, flake8-eradicate: 0.2.0, flake8-mypy: 17.8.0, flake8-pyi: 19.3.0, flake8_builtins: 1.4.1, flake8_coding: 1.3.2, flake8_deprecated: 1.2, flake8_optimal: 2019.07.14, logging-format: 0.6.0, mccabe: 0.6.1, pycodestyle: 2.5.0, pyflakes: 2.1.1, radon: 3.0.3, warn-symbols: 1.1.1) CPython 3.7.3 on Linux


Changes
-------

2019.07.14 - 2019-07-14
```````````````````````
* Mild tweaks & adjustments

2018.10.07 - 2018-10-07
```````````````````````
* Added __docformat__

2018.10.02 - 2018-10-02
```````````````````````
* Replaced "I" with "IGNORECASE" for the newest standards
* Added additional valid hashpling patterns (X009)

2018.10.01 - 2018-10-01
```````````````````````
* Added "#!/usr/bin/env python2" as a valid hashpling (X009)

2018.09.03 - 2018-09-03
```````````````````````
* Added the "TESTING" todo note for the scanner to find (T000)

2018.05.11 - 2018-05-11
```````````````````````
* Added additional todo notes for the scanner to find (T000)
* Added additional forms of exit for the scanner to find (Z003)
* Reworded message for Z001

2018.04.27 - 2018-04-27
```````````````````````
* Fixed unicode decoding issues
* Optimized the magic-comment checker

2018.04.25 - 2018-04-25
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

@echo off
REM -*- coding: utf-8-dos; Mode: Batch; indent-tabs-mode: nil; tab-width: 4 -*-
REM vim: set fileencoding=utf-8 filetype=batch syn=batch.doxygen fileformat=dos tabstop=4 expandtab :
REM kate: encoding utf-8; bom off; syntax batch; indent-mode normal; eol dos; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
REM @brief Doxygen filter for Python (https://pypi.python.org/pypi/doxypypy/)
REM @file py_filter.bat
REM @version 2018.09.11
REM @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
REM @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


python3 -m doxypypy.doxypypy -a -c %1

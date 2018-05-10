#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
# @brief Doxygen filter for Python (https://pypi.python.org/pypi/doxypypy/)
# @file py_filter.sh
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @version 2018.04.27
# @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


python3 -m doxypypy.doxypypy -a -c "$1"

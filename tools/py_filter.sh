#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @brief Doxygen filter for Python (https://pypi.python.org/pypi/doxypypy/)


python3 -m doxypypy.doxypypy -a -c $1

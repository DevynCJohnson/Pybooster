#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @brief Install dependencies and recommended packages for PyBooster


# System (Debian-based)
apt-get install libao-common python3-pip python3-gi python3-gi-cairo  # PyGObject (gi.repository)

# Python3
pip3 install psutil || pip install psutil

#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# Created by Devyn Collier Johnson
# <DevynCJohnson@Gmail.com>
# -- --
# Install dependencies and recommended packages for PyBooster

# System (Debian-based)
apt-get install libao-common python3-pip python3-gi python3-gi-cairo  # PyGObject (gi.repository)

# Python3
pip3 install psutil || pip install psutil

exit 0

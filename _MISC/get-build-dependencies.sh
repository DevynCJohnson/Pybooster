#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# Created by Devyn Collier Johnson
# <DevynCJohnson@Gmail.com>
# -- --
# Install dependencies needed to compile PyBooster

# System (Debian-based)
apt-get install gcc clang llvm python3 python3-dev python3-pip python3-astroid libao-dev

pip3 install --upgrade astkit astroid flake8 mccabe pep8 pylint pytest

exit 0

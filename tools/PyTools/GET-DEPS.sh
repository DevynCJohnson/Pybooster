#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @brief Install needed software (Debian)


# Install
apt-get install geany python3-pip python3-gi llvm clang
apt-get install cppcheck splint kwstyle glade
pip install pydoc
pip install flake8
pip install pep8
pip install pylint

# Finished
echo ""
echo "Installed dependencies (PyTools)!"

exit 0

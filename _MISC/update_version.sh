#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @brief Update the version numbers in a project


cd ..

VERSION=2016.03.18


find ./lib/ -name "*.py" -exec sed -i "s/^__version__ = '20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]'/__version__ = '$VERSION'/" '{}' \;

find ./lib/ -name "*.py" -exec sed -i "s/^@version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/@version $VERSION/" '{}' \;

find ./lib/clib-src/ -name "*.c" -exec sed -i "s/^@version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/@version $VERSION/" '{}' \;

find ./lib/clib-src/ -name "*.h" -exec sed -i "s/^@version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/@version $VERSION/" '{}' \;

find . -name "*.mk" -exec sed -i "s/^# @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/# @version $VERSION/" '{}' \;

find . -name "*.sh" -exec sed -i "s/^# @version 20[0-9][0-9]\.[0-1][0-9]\.[0-3][0-9]/# @version $VERSION/" '{}' \;

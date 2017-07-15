#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>


CLANG_VERSION=4.0

export CC="clang-$CLANG_VERSION"
export CXX="clang++-$CLANG_VERSION"

make clean

make -j3 dcj=1 CLANG="$CLANG_VERSION" all

make rmtmp

echo ''
echo 'DONE; Press enter to exit'
echo ''
read

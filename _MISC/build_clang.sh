#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>


CLANG_VERSION=3.7

export CC="clang-$CLANG_VERSION"
export CXX="clang++-$CLANG_VERSION"

make clean

make -j4 all dcj=1 CLANG="$CLANG_VERSION" && make -j4 pybuild dcj=py CLANG="$CLANG_VERSION"

make rmtmp

echo ''
echo 'DONE; Press enter to exit'
echo ''
read

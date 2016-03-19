#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>


make clean

make -j4 all dcj=1 && make -j4 pybuild dcj=py

make rmtmp

echo ''
echo 'DONE; Press enter to exit'
echo ''
read

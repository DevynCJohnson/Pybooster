#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>


make clean

make -j3 dcj=1 all

make rmtmp

echo ''
echo 'DONE; Press enter to exit'
echo ''
read

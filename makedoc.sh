#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @brief Generate PyBooster documentation


rm -frd ./doc/*

doxygen ./Doxyfile

chmod --quiet 644 ./doc/*.txt
chmod --quiet 755 ./doc/html/
chmod --quiet 644 ./doc/html/*
chmod --quiet 755 ./doc/html/search
chmod --quiet 644 ./doc/html/search/*

#!/usr/bin/make -f
# -*- coding: utf-8-unix; Mode: Makefile; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=makefile syntax=makefile.doxygen fileformat=unix tabstop=4 :
# kate: encoding utf-8; bom off; syntax makefile; indent-mode normal; eol unix; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;


obj-m := ./src/clevo_kbd_backlight.o

PWD := $(shell pwd)
KDIR := /lib/modules/$(shell uname -r)/build
VERSION := 2019.03.29


all:
	@make -C $(KDIR) M=$(PWD) modules

clean:
	@make -C $(KDIR) M=$(PWD) clean

install:
	@make -C $(KDIR) M=$(PWD) modules_install

dkmsadd:
	@cp -R . /usr/src/clevo_kbd_backlight-$(VERSION)
	dkms add -m clevo_kbd_backlight -v $(VERSION)

dkmsremove:
	@dkms remove -m clevo_kbd_backlight -v $(VERSION) --all
	rm -f -r /usr/src/clevo_kbd_backlight-$(VERSION)

build: uninstall dkmsadd
	@dkms build -m clevo_kbd_backlight -v $(VERSION)

build_install: build
	@dkms install -m clevo_kbd_backlight -v $(VERSION)

build_install_load: build_install
	@modprobe clevo_kbd_backlight || true

install:
	@dkms install -m clevo_kbd_backlight -v $(VERSION)

uninstall:
	@modprobe -r clevo_kbd_backlight || true
	dkms remove -m clevo_kbd_backlight -v $(VERSION) --all || true

load:
	@modprobe clevo_kbd_backlight || true

unload:
	@modprobe -r clevo_kbd_backlight || true

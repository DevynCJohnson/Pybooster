// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
/**
@brief Return filesystem statistics
@file statvfs.c
@version 2019.12.29
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section COMPILE
gcc -Wall -Wextra -Wpedantic -O3 -Wl,-O3 -g0 -ggdb0 -s -fwhole-program -funroll-loops -ffunction-sections -fdata-sections -std=c17 -o ./statvfs ./statvfs.c && strip --remove-section=.note --remove-section=.comment --strip-debug --strip-unneeded ./statvfs

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This software is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
*/


#include "MACROS.h"


noreturn int main(rargc, rargv) {
	register int ret;
	struct statvfs buf = { 0 };
	if (argc != 2) {
		puts_err_no_output("Expected one parameter!");
		fast_exit(EXIT_FAILURE);
	} else if ((0 == (strncmp(argv[1], "/", 1))) || (0 == (strncmp(argv[1], "./", 2)))) {
		const char* path = argv[1];
		ret = statvfs(path, &buf);
	} else {
		register int fd = atoi(argv[1]);
		ret = fstatvfs(fd, &buf);
	}
	if (ret != 0) { fast_exit(ret); }
	register const unsigned long long storagesize = (unsigned long long)(buf.f_blocks * buf.f_frsize);
	register const unsigned long long freespace = (unsigned long long)(buf.f_bfree * buf.f_frsize);
	register const unsigned long long usedspace = storagesize - freespace;
	printf("Filesystem ID: %lu\nMount Flags: %lu\nMax Filename Length: %lu\nFilesystem Size (based on fragments): %lu\nFragment Size (bytes): %lu\nBlock Size (bytes): %lu\nFree Blocks: %lu\nFree Blocks (non-root users): %lu\nTotal Inodes: %lu\nFree Inodes: %lu\nFree Inodes (non-root users): %lu\nStorage Size (bytes): %llu\nFree Space (bytes): %llu\nUsed Space (bytes): %llu\n", buf.f_fsid, buf.f_flag, buf.f_namemax, buf.f_blocks, buf.f_frsize, buf.f_bsize, buf.f_bfree, buf.f_bavail, buf.f_files, buf.f_ffree, buf.f_favail, storagesize, freespace, usedspace);
	fast_exit(EXIT_SUCCESS);
}

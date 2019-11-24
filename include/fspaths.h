// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
/**
@brief Macros Header for filesystem paths
@file fspaths.h
@version 2019.11.23
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This file defines various paths to specific directories and files

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


/* PATHS (<paths.h>) */


#if (!(defined(PATHS_H) || defined(_PATHS_H_) || defined(SYS_PATHS_H) || defined(_SYS_PATHS_H_)))  // https://docs.oracle.com/cd/E36784_01/html/E36873/paths.h-3head.html
#define PATHS_H   (1)
#define _PATHS_H   (1)
#define _PATHS_H_   (1)
#define SYS_PATHS_H   (1)
#define _SYS_PATHS_H   (1)
#define _SYS_PATHS_H_   (1)


/** The default search path for locating catalogs */
#define DEF_NLSPATH   "/usr/share/catalogs"
#define ETHER_FILE_NAME   "/etc/ethers"
#define FREEBSD_DYNAMIC_LINKER32   "/libexec/ld-elf32.so.1"
#define FREEBSD_DYNAMIC_LINKER64   "/libexec/ld-elf.so.1"
#define _PATH_BSHELL   "/bin/sh"
#define PATH_BSHELL   _PATH_BSHELL
#define _PATH_CONSOLE   "/dev/console"
#define _PATH_CSHELL   "/bin/csh"
#define PATH_CSHELL   _PATH_CSHELL
#define _PATH_DATANAME   "data"
#define _PATH_DEFPATH   "/usr/local/bin:/bin:/usr/bin"
#define _PATH_DEV   "/dev/"
#define _PATH_DEVDB   "/var/run/dev.db"
/** Path to dev-null */
#define _PATH_DEVNULL   "/dev/null"
/** Path to dev-null */
#define PATH_DEVNULL   _PATH_DEVNULL
#define _PATH_DRUM   "/dev/drum"
#define _PATH_ELF_HINTS   "/var/run/ld-elf.so.hints"
#define _PATH_ETHERS   ETHER_FILE_NAME
/** Provides support for system wide forks */
#define _PATH_FORKSPECIFIER    "/..namedfork/"
#define _PATH_KLOG   "/proc/kmsg"
#define _PATH_KMEM   "/dev/kmem"
#define _PATH_LASTLOG   "/var/log/lastlog"
#define _PATH_MAILDIR   "/var/mail"
#define _PATH_MAN   "/usr/share/man"
#define _PATH_MEM   "/dev/mem"
#define _PATH_MNTTAB    "/etc/fstab"
#define _PATH_MOUNTED   "/etc/mtab"
#define _PATH_NOLOGIN   "/etc/nologin"
#define _PATH_NS_CONF   "/etc/nsswitch.conf"
#define _PATH_PRESERVE   "/var/lib"
#define _PATH_PTMDEV   "/dev/ptm"
/** Prefix for master pseudo terminal nodes */
#define _PATH_PTY   "/dev/pty"
#define _PATH_RSRCNAME   "rsrc"
#define _PATH_RSRCFORKSPEC   "/..namedfork/rsrc"
#define _PATH_RWHODIR   "/var/spool/rwho"
#define _PATH_SENDMAIL  "/usr/sbin/sendmail"
#define _PATH_SHADOW   "/etc/shadow"
#define _PATH_SHELL   "/bin/sh"
#define _PATH_SHELLS   "/etc/shells"
#define _PATH_STDPATH   "/bin:/usr/bin:/sbin:/usr/sbin"
#define _PATH_TTY   "/dev/tty"
#define _PATH_UNIX   "/boot/vmlinux"
#define _PATH_UTMP   "/dev/null/utmp"
#define _PATH_VI   "/usr/bin/vi"
#define _PATH_WTMP   "/dev/null/wtmp"
#define _PATH_TMP   "/tmp/"
#define _PATH_VARDB   "/var/lib/misc/"
#define _PATH_VARRUN   "/var/run/"
#define _PATH_VARTMP   "/var/tmp/"
#define P_tmpdir   _PATH_TMP


// PATH SEPARATORS

#ifdef OSWINDOWS
#   define CHAR_PATH_SEPARATOR   '\\'
#   define WCHAR_PATH_SEPARATOR   L'\\'
#   define STRING_PATH_SEPARATOR   "\\"
#   define WSTRING_PATH_SEPARATOR   L"\\"
#else
#   define CHAR_PATH_SEPARATOR   '/'
#   define WCHAR_PATH_SEPARATOR   L'/'
#   define STRING_PATH_SEPARATOR   "/"
#   define WSTRING_PATH_SEPARATOR   L"/"
#endif


#endif  // PATHS_H

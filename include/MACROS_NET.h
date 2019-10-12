// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
/**
@brief Standard Macros Header Providing Networking Capabilities
@file MACROS_NET.h
@version 2019.10.11
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This file defines various datatypes, macros, functions, etc. pertaining to networking

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


/* SOCKETS (<sys/socket.h>) */


#if (!(defined(_SYS_SOCKET_H) || defined(_SYS_SOCKET_H_) || defined(__BITS_SOCKET_H) || defined(_BITS_SOCKET_H) || defined(_BITS_SOCKET_H_) || defined(_HURD_HURDSOCKET_H)))  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_socket.h.html
#define SYS_SOCKET_H   (1)
#define _SYS_SOCKET_H   (1)
#define _SYS_SOCKET_H_   (1)
#define BITS_SOCKET_H   (1)
#define _BITS_SOCKET_H   (1)
#define _BITS_SOCKET_H_   (1)
#define __BITS_SOCKET_H   (1)
#define __BITS_SOCKET_H_   (1)
#define _HURD_HURDSOCKET_H   (1)  // <hurdsocket.h>


#define SHUT_RD   0
#define SHUT_WR   1
#define SHUT_RDWR   2
#ifndef SOCK_STREAM
#   define SOCK_STREAM   1
#   define SOCK_DGRAM   2
#endif
#define SOCK_RAW   3
#define SOCK_RDM   4
#define SOCK_SEQPACKET   5
#define SOCK_DCCP   6
#define SOCK_PACKET   10
#ifndef SOCK_CLOEXEC
#   define SOCK_CLOEXEC   02000000
#   define SOCK_NONBLOCK   04000
#endif
#define PF_UNSPEC   0
#define PF_LOCAL   1
#define PF_UNIX   PF_LOCAL
#define PF_FILE   PF_LOCAL
#define PF_INET   2
#define PF_AX25   3
#define PF_IPX   4
#define PF_APPLETALK   5
#define PF_NETROM   6
#define PF_BRIDGE   7
#define PF_ATMPVC   8
#define PF_X25   9
#define PF_INET6   10
#define PF_ROSE   11
#define PF_DECnet   12
#define PF_NETBEUI   13
#define PF_SECURITY   14
#define PF_KEY   15
#define PF_NETLINK   16
#define PF_ROUTE   PF_NETLINK
#define PF_PACKET   17
#define PF_ASH   18
#define PF_ECONET   19
#define PF_ATMSVC   20
#define PF_RDS   21
#define PF_SNA   22
#define PF_IRDA   23
#define PF_PPPOX   24
#define PF_WANPIPE   25
#define PF_LLC   26
#define PF_IB   27
#define PF_MPLS   28
#define PF_CAN   29
#define PF_TIPC   30
#define PF_BLUETOOTH   31
#define PF_IUCV   32
#define PF_RXRPC   33
#define PF_ISDN   34
#define PF_PHONET   35
#define PF_IEEE802154   36
#define PF_CAIF   37
#define PF_ALG   38
#define PF_NFC   39
#define PF_VSOCK   40
#define PF_MAX   41
#define AF_UNSPEC   PF_UNSPEC
#define AF_LOCAL   PF_LOCAL
#define AF_UNIX   AF_LOCAL
#define AF_FILE   AF_LOCAL
#define AF_INET   PF_INET
#define AF_AX25   PF_AX25
#define AF_IPX   PF_IPX
#define AF_APPLETALK   PF_APPLETALK
#define AF_NETROM   PF_NETROM
#define AF_BRIDGE   PF_BRIDGE
#define AF_ATMPVC   PF_ATMPVC
#define AF_X25   PF_X25
#define AF_INET6   PF_INET6
#define AF_ROSE   PF_ROSE
#define AF_DECnet   PF_DECnet
#define AF_NETBEUI   PF_NETBEUI
#define AF_SECURITY   PF_SECURITY
#define AF_KEY   PF_KEY
#define AF_NETLINK   PF_NETLINK
#define AF_ROUTE   PF_ROUTE
#define AF_PACKET   PF_PACKET
#define AF_ASH   PF_ASH
#define AF_ECONET   PF_ECONET
#define AF_ATMSVC   PF_ATMSVC
#define AF_RDS   PF_RDS
#define AF_SNA   PF_SNA
#define AF_IRDA   PF_IRDA
#define AF_PPPOX   PF_PPPOX
#define AF_WANPIPE   PF_WANPIPE
#define AF_LLC   PF_LLC
#define AF_IB   PF_IB
#define AF_MPLS   PF_MPLS
#define AF_CAN   PF_CAN
#define AF_TIPC   PF_TIPC
#define AF_BLUETOOTH   PF_BLUETOOTH
#define AF_IUCV   PF_IUCV
#define AF_RXRPC   PF_RXRPC
#define AF_ISDN   PF_ISDN
#define AF_PHONET   PF_PHONET
#define AF_IEEE802154   PF_IEEE802154
#define AF_CAIF   PF_CAIF
#define AF_ALG   PF_ALG
#define AF_NFC   PF_NFC
#define AF_VSOCK   PF_VSOCK
#define AF_MAX   PF_MAX
#ifndef SO_DEBUG
#   define SO_DEBUG   1
#   define SO_REUSEADDR   2
#   define SO_TYPE   3
#   define SO_ERROR   4
#   define SO_DONTROUTE   5
#   define SO_BROADCAST   6
#   define SO_SNDBUF   7
#   define SO_RCVBUF   8
#   define SO_KEEPALIVE   9
#   define SO_OOBINLINE   10
#   define SO_NO_CHECK   11
#   define SO_PRIORITY   12
#   define SO_LINGER   13
#   define SO_BSDCOMPAT   14
#   define SO_REUSEPORT   15
#   define SO_PASSCRED   16
#   define SO_PEERCRED   17
#   define SO_RCVLOWAT   18
#   define SO_SNDLOWAT   19
#   define SO_RCVTIMEO   20
#   define SO_SNDTIMEO   21
#   define SO_ACCEPTCONN   30
#   define SO_SNDBUFFORCE   32
#   define SO_RCVBUFFORCE   33
#   define SO_PROTOCOL   38
#   define SO_DOMAIN   39
#endif
#define SO_SECURITY_AUTHENTICATION   22
#define SO_SECURITY_ENCRYPTION_TRANSPORT   23
#define SO_SECURITY_ENCRYPTION_NETWORK   24
#define SO_BINDTODEVICE   25
#define SO_ATTACH_FILTER   26
#define SO_DETACH_FILTER   27
#define SO_GET_FILTER   SO_ATTACH_FILTER
#define SO_PEERNAME   28
#define SO_TIMESTAMP   29
#define SCM_TIMESTAMP   SO_TIMESTAMP
#define SO_PEERSEC   31
#define SO_PASSSEC   34
#define SO_TIMESTAMPNS   35
#define SCM_TIMESTAMPNS   SO_TIMESTAMPNS
#define SO_MARK   36
#define SO_TIMESTAMPING   37
#define SCM_TIMESTAMPING   SO_TIMESTAMPING
#define SO_RXQ_OVFL   40
#define SO_WIFI_STATUS   41
#define SCM_WIFI_STATUS   SO_WIFI_STATUS
#define SO_PEEK_OFF   42
#define SO_NOFCS   43
#define SO_LOCK_FILTER   44
#define SO_SELECT_ERR_QUEUE   45
#define SO_BUSY_POLL   46
#define SO_MAX_PACING_RATE   47
#define SO_BPF_EXTENSIONS   48
#define SO_INCOMING_CPU   49
#define SO_ATTACH_BPF   50
#define SO_DETACH_BPF   SO_DETACH_FILTER
#ifndef SOL_SOCKET
#   define SOL_SOCKET   1
#endif
#define SOL_IP   0
#define SOL_IPV6   41
#define SOL_ICMPV6   58
#define SOL_RAW   255
#define SOL_DECNET   261
#define SOL_X25   262
#define SOL_PACKET   263
#define SOL_ATM   264
#define SOL_AAL   265
#define SOL_IRDA   266
/** Maximum queue length specifiable by listen(2) */
#define SOMAXCONN   128
#define MSG_OOB   1
#define MSG_DONTROUTE   4
#define MSG_CTRUNC   8
#define MSG_PROXY   0x10
#define MSG_TRUNC   0x20
#define MSG_DONTWAIT   0x40
#define MSG_EOR   0x80
#define MSG_WAITALL   0x100
#define MSG_FIN   0x200
#define MSG_SYN   0x400
#define MSG_CONFIRM   0x800
#define MSG_RST   0x1000
#define MSG_ERRQUEUE   0x2000
#define MSG_NOSIGNAL   0x4000
#define MSG_MORE   0x8000
#define MSG_WAITFORONE   0x10000
#define MSG_FASTOPEN   0x20000000
#define MSG_CMSG_CLOEXEC   0x40000000
#define SCM_RIGHTS   1
#define SCM_CREDENTIALS   2
#define NET_RT_DUMP   1
#define NET_RT_FLAGS   2
#define NET_RT_OOIFLIST   3
#define NET_RT_OIFLIST   4
#define NET_RT_IFLIST   5
#define NET_RT_MAXID   6


typedef struct ucred {
	pid_t pid;
	uid_t uid;
	gid_t gid;
} ucred_t;


typedef struct linger { int l_onoff, l_linger; }   linger_t;


typedef struct attr_packed sockaddr {
	uint8_t sa_len;
	sa_family_t sa_family;
	char sa_data[14];
} sockaddr_t;


typedef struct attr_packed sockaddr_storage {
	sa_family_t ss_family;
	unsigned long __ss_align;
	char __ss_padding[126 * SIZEOF_LONG];
} sockaddr_storage_t;


#ifdef ARCHAARCH64


typedef struct msghdr {
	void* msg_name;
	socklen_t msg_namelen;
	struct iovec* msg_iov;
#   if IS_BIG_ENDIAN
	int __pad1, msg_iovlen;
#   else
	int msg_iovlen, __pad1;
#   endif
	void* msg_control;
#   if IS_BIG_ENDIAN
	int __pad2;
	socklen_t msg_controllen;
#   else
	socklen_t msg_controllen;
	int __pad2;
#   endif
	int msg_flags;
} msghdr_t;


typedef struct cmsghdr {
#   if IS_BIG_ENDIAN
	int __pad1;
	socklen_t cmsg_len;
#   else
	socklen_t cmsg_len;
	int __pad1;
#   endif
	int cmsg_level, cmsg_type;
} cmsghdr_t;


#elif defined(ARCHX86)


typedef struct attr_packed msghdr {
	void* msg_name;
	socklen_t msg_namelen;
	struct iovec* msg_iov;
	int msg_iovlen, __pad1;
	void* msg_control;
	socklen_t msg_controllen, __pad2;
	int msg_flags;
} msghdr_t;


typedef struct cmsghdr {
	socklen_t cmsg_len;
	int __pad1, cmsg_level, cmsg_type;
} cmsghdr_t;


#elif defined(ARCHMIPS)


typedef struct msghdr {
	void* msg_name;
	socklen_t msg_namelen;
	struct iovec* msg_iov;
	int msg_iovlen;
	void* msg_control;
	socklen_t msg_controllen;
	int msg_flags;
} msghdr_t;


typedef struct cmsghdr {
	socklen_t cmsg_len;
	int cmsg_level, cmsg_type;
} cmsghdr_t;


#   define SOCK_STREAM   2
#   define SOCK_DGRAM   1
#   define SOL_SOCKET   65535
#   define SO_DEBUG   1
#   define SO_REUSEADDR   0x4
#   define SO_KEEPALIVE   0x8
#   define SO_DONTROUTE   0x10
#   define SO_BROADCAST   0x20
#   define SO_LINGER   0x80
#   define SO_OOBINLINE   0x100
#   define SO_REUSEPORT   0x200
#   define SO_SNDBUF   0x1001
#   define SO_RCVBUF   0x1002
#   define SO_SNDLOWAT   0x1003
#   define SO_RCVLOWAT   0x1004
#   define SO_RCVTIMEO   0x1006
#   define SO_SNDTIMEO   0x1005
#   define SO_ERROR   0x1007
#   define SO_TYPE   0x1008
#   define SO_ACCEPTCONN   0x1009
#   define SO_PROTOCOL   0x1028
#   define SO_DOMAIN   0x1029
#   define SO_NO_CHECK   11
#   define SO_PRIORITY   12
#   define SO_BSDCOMPAT   14
#   define SO_PASSCRED   17
#   define SO_PEERCRED   18
#   define SO_SNDBUFFORCE   31
#   define SO_RCVBUFFORCE   33
#   define SOCK_NONBLOCK   0200
#   define SOCK_CLOEXEC   02000000


#elif defined(ARCHPOWERPC)


typedef struct msghdr {
	void* msg_name;
	socklen_t msg_namelen;
	struct iovec* msg_iov;
	int msg_iovlen;
	void* msg_control;
	socklen_t msg_controllen;
	int msg_flags;
} msghdr_t;


typedef struct cmsghdr {
	socklen_t cmsg_len;
	int cmsg_level, cmsg_type;
} cmsghdr_t;


#   define SO_DEBUG   1
#   define SO_REUSEADDR   2
#   define SO_TYPE   3
#   define SO_ERROR   4
#   define SO_DONTROUTE   5
#   define SO_BROADCAST   6
#   define SO_SNDBUF   7
#   define SO_RCVBUF   8
#   define SO_KEEPALIVE   9
#   define SO_OOBINLINE   10
#   define SO_NO_CHECK   11
#   define SO_PRIORITY   12
#   define SO_LINGER   13
#   define SO_BSDCOMPAT   14
#   define SO_REUSEPORT   15
#   define SO_RCVLOWAT   16
#   define SO_SNDLOWAT   17
#   define SO_RCVTIMEO   18
#   define SO_SNDTIMEO   19
#   define SO_PASSCRED   20
#   define SO_PEERCRED   21
#   define SO_ACCEPTCONN   30
#   define SO_SNDBUFFORCE   32
#   define SO_RCVBUFFORCE   33
#   define SO_PROTOCOL   38
#   define SO_DOMAIN   39


#else


typedef struct msghdr {
	void* msg_name;
	socklen_t msg_namelen;
	struct iovec* msg_iov;
	int msg_iovlen;
	void* msg_control;
	socklen_t msg_controllen;
	int msg_flags;
} msghdr_t;


typedef struct cmsghdr {
	socklen_t cmsg_len;
	int cmsg_level, cmsg_type;
} cmsghdr_t;


#endif  // ARCH


typedef struct mmsghdr {
	struct msghdr msg_hdr;
	unsigned int msg_len;
} mmsghdr_t;


#define CMSG_ALIGN(len)   (((len) + SIZEOF_SIZE_T - 1) & (size_t)(~(SIZEOF_SIZE_T - 1)))
#define CMSG_SPACE(len)   (CMSG_ALIGN(len) + CMSG_ALIGN(sizeof(struct cmsghdr)))
#define CMSG_LEN(len)   (CMSG_ALIGN(sizeof(struct cmsghdr)) + (len))
#define __CMSG_LEN(cmsg)   (((cmsg)->cmsg_len + SIZEOF_LONG - 1) & (~(long)(SIZEOF_LONG - 1)))
#define CMSG_NEXT(cmsg)   ((unsigned char*)(cmsg) + __CMSG_LEN(cmsg))
#define __CMSG_NEXT(cmsg)   CMSG_NEXT((cmsg))
#define MHDR_END(mhdr)   ((unsigned char*)(mhdr)->msg_control + (mhdr)->msg_controllen)
#define __MHDR_END(cmsg)   MHDR_END((cmsg))
#define CMSG_DATA(cmsg)   ((unsigned char*)(((struct cmsghdr*)(cmsg)) + 1))
#define __CMSG_DATA(cmsg)   CMSG_DATA((cmsg))
#define CMSG_NXTHDR(mhdr, cmsg)   ((cmsg)->cmsg_len < sizeof(struct cmsghdr) ? (struct cmsghdr*)0 : (__CMSG_NEXT(cmsg) + sizeof(struct cmsghdr) >= __MHDR_END(mhdr) ? (struct cmsghdr*)0 : ((struct cmsghdr*)__CMSG_NEXT(cmsg))))
#define CMSG_FIRSTHDR(mhdr)   ((size_t)(mhdr)->msg_controllen >= sizeof(struct cmsghdr) ? (struct cmsghdr*)(mhdr)->msg_control : (struct cmsghdr*)0)
/** Returns a duplicate of ADDR->sun_path with LEN limitation; This should to be used whenever reading a unix socket address, to cope with sun_path possibly not including a trailing `NULL` */
#define _hurd_sun_path_dupa(addr, len)   strndupa((addr)->sun_path, (len) - offsetof(struct sockaddr_un, sun_path))


LIB_FUNC ssize_t sendmsg(const int fd, const struct msghdr* msg, const int flags) {
#   if (LONG_MAX > INT_MAX)
	struct msghdr h = { 0 };
	struct cmsghdr chbuf[86] = { { 0 } }, *c = NULL;
	if (msg) {
		h = *msg;
		h.__pad1 = 0;
		h.__pad2 = 0;
		msg = &h;
		if (h.msg_controllen) {
			if (h.msg_controllen > 1024) {
				set_errno(ENOMEM);
				return -1;
			}
			memcpy_no_output(chbuf, h.msg_control, h.msg_controllen);
			h.msg_control = chbuf;
			for (c = CMSG_FIRSTHDR(&h); c; c = CMSG_NXTHDR(&h, c)) { c->__pad1 = 0; }
		}
	}
#   endif
	return (ssize_t)syscall6(SYS_sendmsg, fd, (long)msg, flags, 0, 0, 0);
}


LIB_FUNC int sendmmsg(const int fd, struct mmsghdr* msgvec, unsigned int vlen, unsigned int flags) {
#   if (LONG_MAX > INT_MAX)
	if (vlen > IOV_MAX) { vlen = IOV_MAX; }
	else if (!vlen) { return 0; }
	register int i;
	for (i = 0; i < (int)vlen; i++) {
		register ssize_t r = sendmsg(fd, &msgvec[i].msg_hdr, (int)flags);
		if (r < 0) { return (i ? i : -1); }
		msgvec[i].msg_len = (unsigned int)r;
	}
	return (i ? i : -1);
#   else
	return (int)syscall4(SYS_sendmmsg, fd, (long)msgvec, vlen, flags);
#   endif
}


LIB_FUNC int recvmmsg(const int fd, struct mmsghdr* msgvec, const unsigned int vlen, const unsigned int flags, struct timespec* timeout) {
#   if (LONG_MAX > INT_MAX)
	struct mmsghdr* mh = msgvec;
	register unsigned int i;
	for (i = vlen; i; i--, mh++) {
		mh->msg_hdr.__pad1 = 0;
		mh->msg_hdr.__pad2 = 0;
	}
#   endif
	return (int)syscall5(SYS_recvmmsg, fd, (long)msgvec, vlen, flags, (long)timeout);
}


LIB_FUNC ssize_t recvmsg(const int fd, struct msghdr* msg, const int flags) {
#   if (LONG_MAX > INT_MAX)
	struct msghdr h = { 0 }, *orig = msg;
	if (msg) {
		h = *msg;
		h.__pad1 = 0;
		h.__pad2 = 0;
		msg = &h;
	}
#   endif
	const ssize_t r = (ssize_t)syscall6(SYS_recvmsg, fd, (long)msg, flags, 0, 0, 0);
#   if (LONG_MAX > INT_MAX)
	if (orig) { *orig = h; }
#   endif
	return r;
}


LIB_FUNC int socket(const int domain, const int type, const int protocol) {
	int s = (int)syscall6(SYS_socket, domain, type, protocol, 0, 0, 0);
	if (s < 0 && (eq_errno(EINVAL) || eq_errno(EPROTONOSUPPORT)) && (type & (SOCK_CLOEXEC|SOCK_NONBLOCK))) {
		s = (int)syscall6(SYS_socket, domain, (long)(type & (~(SOCK_CLOEXEC | SOCK_NONBLOCK))), protocol, 0, 0, 0);
		if (s < 0) { return s; }
		else if (type & SOCK_CLOEXEC) { syscall3(SYS_fcntl, s, F_SETFD, FD_CLOEXEC); }
		if (type & SOCK_NONBLOCK) { syscall3(SYS_fcntl, s, F_SETFL, O_NONBLOCK); }
	}
	return s;
}


LIB_FUNC int socketpair(const int domain, const int type, const int protocol, int fd[2]) {
	int r = (int)syscall6(SYS_socketpair, domain, type, protocol, (long)fd, 0, 0);
	if (r < 0 && (eq_errno(EINVAL) || eq_errno(EPROTONOSUPPORT)) && (type & (SOCK_CLOEXEC | SOCK_NONBLOCK))) {
		r = (int)syscall6(SYS_socketpair, domain, (long)(type & (~(SOCK_CLOEXEC | SOCK_NONBLOCK))), protocol, (long)fd, 0, 0);
		if (r < 0) { return r; }
		else if (type & SOCK_CLOEXEC) {
			syscall3(SYS_fcntl, (long)fd[0], F_SETFD, FD_CLOEXEC);
			syscall3(SYS_fcntl, (long)fd[1], F_SETFD, FD_CLOEXEC);
		}
		if (type & SOCK_NONBLOCK) {
			syscall3(SYS_fcntl, (long)fd[0], F_SETFL, O_NONBLOCK);
			syscall3(SYS_fcntl, (long)fd[1], F_SETFL, O_NONBLOCK);
		}
	}
	return r;
}


LIB_FUNC int shutdown(const int fd, const int how) {
	return (int)syscall6(SYS_shutdown, fd, how, 0, 0, 0, 0);
}


LIB_FUNC int bind(const int fd, const struct sockaddr* addr, const socklen_t len) {
	return (int)syscall6(SYS_bind, fd, (long)addr, (long)len, 0, 0, 0);
}


LIB_FUNC int connect(const int fd, const struct sockaddr* addr, const socklen_t len) {
	return (int)syscall6(SYS_connect, fd, (long)addr, (long)len, 0, 0, 0);
}


LIB_FUNC int listen(const int fd, const int backlog) {
	return (int)syscall6(SYS_listen, fd, backlog, 0, 0, 0, 0);
}


LIB_FUNC int accept(const int fd, struct sockaddr* restrict addr, socklen_t* restrict len) {
	return (int)syscall6(SYS_accept, fd, (long)addr, (long)len, 0, 0, 0);
}


LIB_FUNC int accept4(const int fd, struct sockaddr* restrict addr, socklen_t* restrict len, const int flag) {
	if (!flag) { return accept(fd, addr, len); }
	register int ret = (int)syscall6(SYS_accept4, fd, (long)addr, (long)len, flag, 0, 0);
	if (ret >= 0 || (neq_errno(ENOSYS) && neq_errno(EINVAL))) { return ret; }
	ret = (int)accept(fd, addr, len);
	if (ret < 0) { return ret; }
	if (flag & SOCK_CLOEXEC) { syscall3(SYS_fcntl, ret, F_SETFD, FD_CLOEXEC); }
	else if (flag & SOCK_NONBLOCK) { syscall3(SYS_fcntl, ret, F_SETFL, O_NONBLOCK); }
	return ret;
}


LIB_FUNC int getsockname(const int fd, struct sockaddr* restrict addr, socklen_t* restrict len) {
	return (int)syscall6(SYS_getsockname, fd, (long)addr, (long)len, 0, 0, 0);
}
#define roken_getsockname(fd, addr, len)   getsockname((fd) , (addr), (len))


LIB_FUNC int getpeername(const int fd, struct sockaddr* restrict addr, socklen_t* restrict len) {
	return (int)syscall6(SYS_getpeername, fd, (long)addr, (long)len, 0, 0, 0);
}


LIB_FUNC int getsockopt(const int fd, const int level, const int optname, void* restrict optval, socklen_t* restrict optlen) {
	return (int)syscall6(SYS_getsockopt, fd, level, optname, (long)optval, (long)optlen, 0);
}


LIB_FUNC ssize_t sendto(const int fd, const void* buf, const size_t len, const int flags, const struct sockaddr* addr, const socklen_t alen) {
	return (ssize_t)syscall6(SYS_sendto, fd, (long)buf, (long)len, flags, (long)addr, (long)alen);
}


LIB_FUNC ssize_t send(const int fd, const void* buf, const size_t len, const int flags) {
	return (ssize_t)sendto(fd, buf, len, flags, 0, 0);
}


LIB_FUNC ssize_t recvfrom(const int fd, void* restrict buf, const size_t len, const int flags, struct sockaddr* restrict addr, socklen_t* restrict alen) {
	return (ssize_t)syscall6(SYS_recvfrom, fd, (long)buf, (long)len, flags, (long)addr, (long)alen);
}
#define _recvfrom(fd, buf, len, flags, addr, alen)   recvfrom((fd), (buf), (len), (flags), (addr), (alen))
#define __recvfrom(fd, buf, len, flags, addr, alen)   recvfrom((fd), (buf), (len), (flags), (addr), (alen))


LIB_FUNC ssize_t recv(const int fd, void* buf, const size_t len, const int flags) {
	return (ssize_t)recvfrom(fd, buf, len, flags, 0, 0);
}
#define _recv(fd, buf, len, flags)   recv((fd), (buf), (len), (flags))
#define __recv(fd, buf, len, flags)   recv((fd), (buf), (len), (flags))


LIB_FUNC int setsockopt(const int fd, const int level, const int optname, const void* optval, const socklen_t optlen) {
	return (int)syscall6(SYS_setsockopt, fd, level, optname, (long)optval, optlen, 0);
}


LIB_FUNC int sockatmark(const int s) {
	int ret;
	if (ioctl(s, SIOCATMARK, &ret) < 0) { return -1; }
	return ret;
}


#endif  // SYS_SOCKET_H


/* SOCKETS LOCAL INTERFACES (<net/if.h>) */


#if (!(defined(NET_IF_H) || defined(_NET_IF_H) || defined(_NET_IF_H_) || defined(NETLINK_H)))  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/net_if.h.html
#define NET_IF_H   (1)
#define _NET_IF_H   (1)
#define _NET_IF_H_   (1)
#define NETLINK_H   (1)
#define _NETLINK_H   (1)
#define _NETLINK_H_   (1)


#define IFADDRS_HASH_SIZE   64
#define IF_NAMESIZE   16
#define IFHWADDRLEN   6
#define IFNAMSIZ   IF_NAMESIZE
#define IFF_UP   1
#define IFF_BROADCAST   2
#define IFF_DEBUG   4
#define IFF_LOOPBACK   8
#define IFF_POINTOPOINT   0x10
#define IFF_NOTRAILERS   0x20
#define IFF_RUNNING   0x40
#define IFF_NOARP   0x80
#define IFF_PROMISC   0x100
#define IFF_ALLMULTI   0x200
#define IFF_MASTER   0x400
#define IFF_SLAVE   0x800
#define IFF_MULTICAST   0x1000
#define IFF_PORTSEL   0x2000
#define IFF_AUTOMEDIA   0x4000
#define IFF_DYNAMIC   0x8000
#define IFF_LOWER_UP   0x10000
#define IFF_DORMANT   0x20000
#define IFF_ECHO   0x40000
#define IFF_VOLATILE   (IFF_LOOPBACK | IFF_POINTOPOINT | IFF_BROADCAST | IFF_ECHO|IFF_MASTER | IFF_SLAVE | IFF_RUNNING | IFF_LOWER_UP | IFF_DORMANT)
#define NETLINK_ROUTE   0
#define NLM_F_REQUEST   1
#define NLM_F_MULTI   2
#define NLM_F_ACK   4
#define NLM_F_ROOT   0x100
#define NLM_F_MATCH   0x200
#define NLM_F_ATOMIC   0x400
#define NLM_F_DUMP   (NLM_F_ROOT | NLM_F_MATCH)
#define NLMSG_NOOP   1
#define NLMSG_ERROR   2
#define NLMSG_DONE   3
#define NLMSG_OVERRUN   4
#define IFLA_ADDRESS   1
#define IFLA_BROADCAST   2
#define IFLA_IFNAME   3
#define IFLA_STATS   7
#define IFA_ADDRESS   1
#define IFA_LOCAL   2
#define IFA_LABEL   3
#define IFA_BROADCAST   4
#define RTM_NEWLINK   16
#define RTM_GETLINK   18
#define RTM_GETADDR   22


typedef struct nlmsghdr {
	uint32_t nlmsg_len;
	uint16_t nlmsg_type, nlmsg_flags;
	uint32_t nlmsg_seq, nlmsg_pid;
} nlmsghdr_t;


typedef struct rtattr { unsigned short rta_len, rta_type; }   rtattr_t;
typedef struct rtgenmsg { unsigned char rtgen_family; }   rtgenmsg_t;


typedef struct ifinfomsg {
	unsigned char ifi_family, __ifi_pad;
	unsigned short ifi_type;
	int ifi_index;
	unsigned int ifi_flags, ifi_change;
} ifinfomsg_t;


typedef struct ifaddrmsg {
	uint8_t ifa_family, ifa_prefixlen, ifa_flags, ifa_scope;
	uint32_t ifa_index;
} ifaddrmsg_t;


typedef struct attr_packed ifnamemap {
	unsigned int hash_next, index;
	unsigned char namelen;
	char name[IFNAMSIZ];
} ifnamemap_t;


typedef struct attr_packed ifnameindexctx {
	unsigned int num, allocated, str_bytes;
	struct ifnamemap* list;
	unsigned int hash[IFADDRS_HASH_SIZE];
} ifnameindexctx_t;


typedef struct attr_packed if_nameindex {
	unsigned int if_index;
	char* if_name;
} if_nameindex_t;


typedef struct attr_packed ifmap {
	unsigned long mem_start, mem_end;
	unsigned short base_addr;
	unsigned char irq, dma, port;
} ifmap_t;


typedef struct ifreq {
	union ifr_ifrn_union { char ifrn_name[IFNAMSIZ]; } ifr_ifrn;
	union attr_packed ifr_ifru_union {
		struct sockaddr ifru_addr, ifru_dstaddr, ifru_broadaddr, ifru_netmask, ifru_hwaddr;
		short ifru_flags;
		int ifru_ivalue, ifru_mtu;
		struct ifmap ifru_map;
		char ifru_slave[IFNAMSIZ], ifru_newname[IFNAMSIZ];
		void* ifru_data;
	} ifr_ifru;
} ifreq_t;
#define ifr_name   ifr_ifrn.ifrn_name
#define ifr_hwaddr   ifr_ifru.ifru_hwaddr
#define ifr_addr   ifr_ifru.ifru_addr
#define ifr_dstaddr   ifr_ifru.ifru_dstaddr
#define ifr_broadaddr   ifr_ifru.ifru_broadaddr
#define ifr_netmask   ifr_ifru.ifru_netmask
#define ifr_flags   ifr_ifru.ifru_flags
#define ifr_metric   ifr_ifru.ifru_ivalue
#define ifr_mtu   ifr_ifru.ifru_mtu
#define ifr_map   ifr_ifru.ifru_map
#define ifr_slave   ifr_ifru.ifru_slave
#define ifr_data   ifr_ifru.ifru_data
#define ifr_ifindex   ifr_ifru.ifru_ivalue
#define ifr_bandwidth   ifr_ifru.ifru_ivalue
#define ifr_qlen   ifr_ifru.ifru_ivalue
#define ifr_newname   ifr_ifru.ifru_newname
#define _IOT_ifreq   _IOT(_IOTS(char), IFNAMSIZ, _IOTS(char), 16, 0, 0)
#define _IOT_ifreq_short   _IOT(_IOTS(char), IFNAMSIZ, _IOTS(short), 1, 0, 0)
#define _IOT_ifreq_int   _IOT(_IOTS(char), IFNAMSIZ, _IOTS(int), 1, 0, 0)


typedef struct attr_packed ifconf {
	int ifc_len;
	union __union_ifconf {
		void* ifcu_buf;
		struct ifreq* ifcu_req;
	} ifc_ifcu;
} ifconf_t;
#define ifc_buf   ifc_ifcu.ifcu_buf
#define ifc_req   ifc_ifcu.ifcu_req
#define _IOT_ifconf   _IOT(_IOTS(struct ifconf),1, 0, 0, 0, 0)


#define NETLINK_ALIGN(len)   ((uint32_t)((len) + 3) & (uint32_t)(~3))
#define NLMSG_DATA(nlh)   ((void*)((char*)(nlh) + sizeof(struct nlmsghdr)))
#define NLMSG_DATALEN(nlh)   ((nlh)->nlmsg_len - sizeof(struct nlmsghdr))
#define NLMSG_DATAEND(nlh)   ((char*)(nlh) + (nlh)->nlmsg_len)
#define NLMSG_NEXT(nlh)   (struct nlmsghdr*)((char*)(nlh) + NETLINK_ALIGN((nlh)->nlmsg_len))
#define NLMSG_OK(nlh, end)   ((size_t)((char*)(end) - (char*)(nlh)) >= sizeof(struct nlmsghdr))
#define RTA_DATA(rta)   ((void*)((char*)(rta) + sizeof(struct rtattr)))
#define RTA_DATALEN(rta)   ((rta)->rta_len - sizeof(struct rtattr))
#define RTA_DATAEND(rta)   ((char*)(rta) + (rta)->rta_len)
#define RTA_NEXT(rta)   (struct rtattr*)((char*)(rta) + NETLINK_ALIGN((rta)->rta_len))
#define RTA_OK(nlh, end)   ((size_t)((char*)(end) - (char*)(rta)) >= sizeof(struct rtattr))
#define NLMSG_RTA(nlh, len)   ((void*)((char*)(nlh) + sizeof(struct nlmsghdr) + NETLINK_ALIGN(len)))
#define NLMSG_RTAOK(rta, nlh)   RTA_OK(rta, NLMSG_DATAEND(nlh))


LIB_FUNC void if_freenameindex(struct if_nameindex* idx) {
	free(idx);
}


LIB_FUNC unsigned int if_nametoindex(const char* name) {
	struct ifreq ifr = { .ifr_ifrn = { { 0 } } };
	int fd = 0;
	if ((fd = socket(AF_UNIX, (SOCK_DGRAM | SOCK_CLOEXEC), 0)) < 0) { return 0; }
	strncpy_no_output(ifr.ifr_name, name, sizeof(ifr.ifr_name));
	const int r = ioctl(fd, SIOCGIFINDEX, &ifr);
	syscall1(SYS_close, fd);
	return (unsigned int)(r < 0 ? 0 : ifr.ifr_ifindex);
}


LIB_FUNC char* if_indextoname(const unsigned int index, char* name) {
	struct ifreq ifr = { .ifr_ifrn = { { 0 } } };
	int fd = 0;
	if ((fd = socket(AF_UNIX, (SOCK_DGRAM | SOCK_CLOEXEC), 0)) < 0) { return 0; }
	ifr.ifr_ifindex = (int)index;
	const int r = ioctl(fd, SIOCGIFNAME, &ifr);
	syscall1(SYS_close, fd);
	return (r < 0 ? 0 : strncpy(name, ifr.ifr_name, IF_NAMESIZE));
}


LIB_FUNC int __netlink_enumerate(const int fd, const unsigned int seq, const int type, const int af, int (*cb)(void* _ctx, struct nlmsghdr* h), void* _ctx) {
	struct nlmsghdr* h = NULL;
	union __union_netlink_enumerate {
		uint8_t buf[8192];
		struct attr_packed {
			struct nlmsghdr nlh;
			struct rtgenmsg g;
		} req;
		struct nlmsghdr reply;
	} u = { .buf = { 0 } };
	u.req.nlh.nlmsg_len = sizeof(u.req);
	u.req.nlh.nlmsg_type = (uint16_t)type;
	u.req.nlh.nlmsg_flags = (NLM_F_DUMP | NLM_F_REQUEST);
	u.req.nlh.nlmsg_seq = seq;
	u.req.g.rtgen_family = (unsigned char)af;
	int r = (int)send(fd, &u.req, sizeof(u.req), 0);
	if (r < 0) { return r; }
	register int ret = -1;
	until_break {
		r = (int)recv(fd, u.buf, sizeof(u.buf), MSG_DONTWAIT);
		if (r <= 0) { return -1; }
		for (h = &u.reply; NLMSG_OK(h, (void*)&u.buf[r]); h = NLMSG_NEXT(h)) {
			if (h->nlmsg_type == NLMSG_DONE) { return 0; }
			else if (h->nlmsg_type == NLMSG_ERROR) { return -1; }
			ret = cb(_ctx, h);
			if (ret) { return ret; }
		}
	}
}
#define netlink_enumerate(fd, seq, type, af, cb, _ctx)   __netlink_enumerate((fd), (seq), (type), (af), (cb), (_ctx))


LIB_FUNC int __rtnetlink_enumerate(const int link_af, const int addr_af, int (*cb)(void* _ctx, struct nlmsghdr* h), void* _ctx) {
	const int fd = socket(PF_NETLINK, (SOCK_RAW | SOCK_CLOEXEC), NETLINK_ROUTE);
	if (fd < 0) { return -1; }
	int r = __netlink_enumerate(fd, 1, RTM_GETLINK, link_af, cb, _ctx);
	if (!r) { r = __netlink_enumerate(fd, 2, RTM_GETADDR, addr_af, cb, _ctx); }
	syscall1(SYS_close, fd);
	return r;
}
#define rtnetlink_enumerate(link_af, addr_af, cb, _ctx)   __rtnetlink_enumerate((link_af), (addr_af), (cb), (_ctx))


LIB_FUNC int netlink_msg_to_nameindex(void* pctx, struct nlmsghdr* h) {
	struct ifnameindexctx* _ctx = pctx;
	struct ifnamemap* map = NULL;
	struct rtattr* rta = NULL;
	int index, type;
	if (h->nlmsg_type == RTM_NEWLINK) {
		struct ifinfomsg* ifi = NLMSG_DATA(h);
		index = ifi->ifi_index;
		type = IFLA_IFNAME;
		rta = NLMSG_RTA(h, sizeof(*ifi));
	} else {
		struct ifaddrmsg* ifa = NLMSG_DATA(h);
		index = (int)ifa->ifa_index;
		type = IFA_LABEL;
		rta = NLMSG_RTA(h, sizeof(*ifa));
	}
	unsigned int i = 0;
	int namelen, bucket;
	for (; NLMSG_RTAOK(rta, h); rta = RTA_NEXT(rta)) {
		if (rta->rta_type != type) { continue; }
		namelen = (int)(RTA_DATALEN(rta) - 1);
		if (namelen > IFNAMSIZ) { return 0; }
		bucket = index % IFADDRS_HASH_SIZE;
		i = _ctx->hash[bucket];
		while (i) {
			map = &_ctx->list[i - 1];
			if ((int)map->index == index && map->namelen == namelen && memcmp(map->name, RTA_DATA(rta), (size_t)namelen) == 0) { return 0; }
			i = map->hash_next;
		}
		if (_ctx->num >= _ctx->allocated) {
			const size_t a = (size_t)(_ctx->allocated ? (_ctx->allocated * 2 + 1) : 8);
			if (a > SIZE_MAX / sizeof(*map)) { return -1; }
			map = realloc(_ctx->list, a * sizeof(*map));
			if (!map) { return -1; }
			_ctx->list = map;
			_ctx->allocated = (unsigned int)a;
		}
		map = &_ctx->list[_ctx->num];
		map->index = (unsigned int)index;
		map->namelen = (unsigned char)namelen;
		memcpy_no_output(map->name, RTA_DATA(rta), (size_t)namelen);
		_ctx->str_bytes += (unsigned int)(namelen + 1);
		_ctx->num++;
		map->hash_next = _ctx->hash[bucket];
		_ctx->hash[bucket] = _ctx->num;
		return 0;
	}
	return 0;
}


LIB_FUNC struct if_nameindex* if_nameindex(void) {
	struct ifnameindexctx _ctx, *ctx2 = &_ctx;
	struct if_nameindex *ifs = 0, *d = NULL;
	struct ifnamemap* s = NULL;
	char* p = NULL;
	int cs = 0;
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &cs);
	memset_no_output(ctx2, 0, sizeof(*ctx2));
	if (__rtnetlink_enumerate(AF_UNSPEC, AF_INET, netlink_msg_to_nameindex, ctx2) < 0) {
		pthread_setcancelstate(cs, 0);
		free(ctx2->list);
		set_errno(ENOBUFS);
		return ifs;
	}
	ifs = malloc(sizeof(struct if_nameindex[ctx2->num + 1]) + ctx2->str_bytes);
	if (!ifs) {
		pthread_setcancelstate(cs, 0);
		free(ctx2->list);
		set_errno(ENOBUFS);
		return ifs;
	}
	p = (char*)(ifs + ctx2->num + 1);
	int i = (int)ctx2->num;
	for (d = ifs, s = ctx2->list; i; i--, s++, d++) {
		d->if_index = s->index;
		d->if_name = p;
		memcpy_no_output(p, s->name, s->namelen);
		p += s->namelen;
		*p++ = 0;
	}
	d->if_index = 0;
	d->if_name = 0;
	pthread_setcancelstate(cs, 0);
	free(ctx2->list);
	set_errno(ENOBUFS);
	return ifs;
}


#endif  // NET_IF_H


/* IFADDRS (<ifaddrs.h>) */


#if (!(defined(IFADDRS_H) || defined(_IFADDRS_H) || defined(_IFADDRS_H_)))
#define IFADDRS_H   (1)
#define _IFADDRS_H   (1)
#define _IFADDRS_H_   (1)


typedef struct attr_packed ifaddrs {
	struct ifaddrs* ifa_next;  //!< Next item in list
	const char* ifa_name;  //!< Name of interface
	unsigned int ifa_flags;  //!< Flags from SIOCGIFFLAGS
	struct sockaddr* ifa_addr;  //!< Address of interface
	struct sockaddr* ifa_netmask;  //!< Netmask of interface
	struct sockaddr* ifa_dstaddr;
	void* ifa_data;  //!< Address-specific data
} ifaddrs_t;
#define ifa_broadaddr   ifa_dstaddr


/** Routing statistics */
struct rtstat {
	short rts_badredirect, rts_dynamic, rts_newgateway, rts_unreach, rts_wildcard;
};


/** These numbers are used by reliable protocols for determining retransmission behavior and are included in the routing structure */
struct rt_metrics {
	unsigned long rmx_locks, rmx_mtu, rmx_hopcount, rmx_expire;
	unsigned long rmx_recvpipe, rmx_sendpipe, rmx_ssthresh, rmx_rtt;
	unsigned long rmx_rttvar, rmx_pksent;
	unsigned long rmx_filler[4];
};


/** Structures for routing messages */
struct rt_msghdr {
	unsigned short rtm_hdrlen, rtm_msglen;
	unsigned char rtm_version, rtm_type;
	unsigned short rtm_index;
	int rtm_flags, rtm_addrs;
	pid_t rtm_pid;
	int rtm_seq, rtm_errno, rtm_use;
	unsigned long rtm_inits;
	struct rt_metrics rtm_rmx;
};


/** Structure describing information about an interface which may be of interest to management entities */
struct attr_packed if_data {
	unsigned char ifi_type, ifi_physical, ifi_addrlen;
	unsigned char ifi_hdrlen, ifi_recvquota, ifi_xmitquota;
	unsigned long ifi_mtu, ifi_metric, ifi_baudrate;
	unsigned long ifi_ipackets, ifi_ierrors, ifi_opackets;
	unsigned long ifi_oerrors, ifi_collisions, ifi_ibytes;
	unsigned long ifi_obytes, ifi_imcasts, ifi_omcasts;
	unsigned long ifi_iqdrops, ifi_noproto, ifi_hwassist, ifi_unused;
	struct timeval ifi_lastchange;
};


/** Message format for use in obtaining information about interfaces from getkerninfo and the routing socket */
struct if_msghdr {
	unsigned short ifm_msglen;
	unsigned char ifm_version, ifm_type;
	int ifm_addrs, ifm_flags;
	unsigned short ifm_index;
	struct if_data ifm_data;
};


/** Message format for use in obtaining information about interface addresses from getkerninfo and the routing socket */
struct attr_packed ifa_msghdr {
	unsigned short ifam_msglen;
	unsigned char ifam_version, ifam_type;
	int ifam_addrs, ifam_flags;
	unsigned short ifam_index;
	int ifam_metric;
};


/** Structure of a Link-Level sockaddr */
struct sockaddr_dl {
	unsigned char sdl_len, sdl_family;
	unsigned short sdl_index;
	unsigned char sdl_type, sdl_nlen, sdl_alen, sdl_slen;
	char sdl_data[46];
};


#define SA_RLEN(sa)   ((sa)->sa_len ? (((sa)->sa_len + SALIGN) & (~SALIGN)) : (SALIGN + 1))
/** Route usable */
#define RTF_UP   1
/** Destination is a gateway */
#define RTF_GATEWAY   2
/** Host entry (net otherwise) */
#define RTF_HOST   4
/** Host or net unreachable */
#define RTF_REJECT   8
/** Created dynamically (by redirect) */
#define RTF_DYNAMIC   0x10
/** Modified dynamically (by redirect) */
#define RTF_MODIFIED   0x20
/** Message confirmed */
#define RTF_DONE   0x40
/** Unused */
#define RTF_DELCLONE   0x80
/** Generate new routes on use */
#define RTF_CLONING   0x100
/** External daemon resolves name */
#define RTF_XRESOLVE   0x200
/** Generated by link layer (e.g. ARP) */
#define RTF_LLINFO   0x400
/** Manually added */
#define RTF_STATIC   0x800
/** Just discard pkts (during updates) */
#define RTF_BLACKHOLE   0x1000
/** Protocol specific routing flag */
#define RTF_PROTO2   0x4000
/** Protocol specific routing flag */
#define RTF_PROTO1   0x8000
/** Protocol requires cloning */
#define RTF_PRCLONING   0x10000
/** Route generated through cloning */
#define RTF_WASCLONED   0x20000
/** Protocol specific routing flag */
#define RTF_PROTO3   0x40000
/** Future use */
#define RTF_PINNED   0x100000
/** Route represents a local address */
#define RTF_LOCAL   0x200000
/** Route represents a bcast address */
#define RTF_BROADCAST   0x400000
/** Route represents a mcast address */
#define RTF_MULTICAST   0x800000
#define RTA_MASKS   (RTA_NETMASK | RTA_IFA | RTA_BRD)
/** Up the ante and ignore older versions */
#define RTM_VERSION   5
// Message types
/** Add Route */
#define RTM_ADD   1
/** Delete Route */
#define RTM_DELETE   2
/** Change Metrics or flags */
#define RTM_CHANGE   3
/** Report Metrics */
#define RTM_GET   4
/** Kernel Suspects Partitioning */
#define RTM_LOSING   5
/** Told to use different route */
#define RTM_REDIRECT   6
/** Lookup failed on this address */
#define RTM_MISS   7
/** Fix specified metrics */
#define RTM_LOCK   8
/** Caused by SIOCADDRT */
#define RTM_OLDADD   9
/** Caused by SIOCDELRT */
#define RTM_OLDDEL   0xa
/** Req to resolve dst to LL addr */
#define RTM_RESOLVE   0xb
/** Address being added to iface */
#define RTM_NEWADDR   0xc
/** Address being removed from iface */
#define RTM_DELADDR   0xd
/** Iface going up/down etc. */
#define RTM_IFINFO   0xe
/** Mcast group membership being added to if */
#define RTM_NEWMADDR   0xf
/** Mcast group membership being deleted */
#define RTM_DELMADDR   0x10
/** Iface arrival/departure */
#define RTM_IFANNOUNCE   0x11
// Bitmask values for rtm_inits and rmx_locks
/** Init or lock _mtu */
#define RTV_MTU   1
/** Init or lock _hopcount */
#define RTV_HOPCOUNT   2
/** Init or lock _expire */
#define RTV_EXPIRE   4
/** Init or lock _recvpipe */
#define RTV_RPIPE   8
/** Init or lock _sendpipe */
#define RTV_SPIPE   0x10
/** Init or lock _ssthresh */
#define RTV_SSTHRESH   0x20
/** Init or lock _rtt */
#define RTV_RTT   0x40
/** Init or lock _rttvar */
#define RTV_RTTVAR   0x80
// Bitmask values for rtm_addrs
/** Destination sockaddr present */
#define RTA_DST   1
/** Gateway sockaddr present */
#define RTA_GATEWAY   2
/** Netmask sockaddr present */
#define RTA_NETMASK   4
/** Cloning mask sockaddr present */
#define RTA_GENMASK   8
/** Interface name sockaddr present */
#define RTA_IFP   0x10
/** Interface addr sockaddr present */
#define RTA_IFA   0x20
/** Sockaddr for author of redirect */
#define RTA_AUTHOR   0x40
/** For NEWADDR, broadcast or p-p dest addr */
#define RTA_BRD   0x80
// Index offsets for sockaddr array for alternate internal encoding
/** Destination sockaddr present */
#define RTAX_DST   0
/** Gateway sockaddr present */
#define RTAX_GATEWAY   1
/** Netmask sockaddr present */
#define RTAX_NETMASK   2
/** Cloning mask sockaddr present */
#define RTAX_GENMASK   3
/** Interface name sockaddr present */
#define RTAX_IFP   4
/** Interface addr sockaddr present */
#define RTAX_IFA   5
/** Sockaddr for author of redirect */
#define RTAX_AUTHOR   6
/** For NEWADDR, broadcast or p-p dest addr */
#define RTAX_BRD   7
/** Size of array to allocate */
#define RTAX_MAX   8


LIB_FUNC int getifaddrs(struct ifaddrs** pif) {
	size_t needed = 0;
	char *buf = NULL, *bufp = NULL, *next = NULL, *p = NULL, *p0 = NULL, *names = NULL;
	struct ifaddrs* cif = NULL;
	struct rt_msghdr* rtm = NULL;
	struct if_msghdr* ifm = NULL;
	struct ifa_msghdr* ifam = NULL;
	struct sockaddr_dl* dl = NULL;
	struct sockaddr* sa = NULL;
	register unsigned short index = 0;
	struct ifaddrs *ifa = NULL, *ift = NULL;
	int align64 mib[6] = { CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST, 0 };
	until_break {
		if (sysctl(mib, 6, NULL, &needed, NULL, 0) == -1) {
			free(buf);
			return -1;
		}
		else if (needed == 0) { break; }
		else if ((bufp = realloc(buf, needed)) == NULL) {
			free(buf);
			return -1;
		}
		buf = bufp;
		if (sysctl(mib, 6, buf, &needed, NULL, 0) == -1) {
			if (eq_errno(ENOMEM)) { continue; }
			free(buf);
			return -1;
		}
		break;
	}
	next = buf;
	rtm = (struct rt_msghdr*)next;
	register int i = 0, dcnt = 0, icnt = 1, ncnt = 0;
	size_t len = 0, alen = 0, dlen = 0;
	for (; next < (buf + needed); next += rtm->rtm_msglen) {
		rtm = (struct rt_msghdr*)next;
		if (rtm->rtm_version != RTM_VERSION) { continue; }
		switch (rtm->rtm_type) {
			case RTM_IFINFO:
				ifm = (struct if_msghdr*)rtm;
				if (ifm->ifm_addrs & RTA_IFP) {
					index = ifm->ifm_index;
					++icnt;
					dl = (struct sockaddr_dl*)(next + rtm->rtm_hdrlen);
					dcnt += SA_RLEN((struct sockaddr*)dl) + ALIGNBYTES;
					dcnt += (int)sizeof(ifm->ifm_data);
					ncnt += dl->sdl_nlen + 1;
				} else { index = 0; }
				break;
			case RTM_NEWADDR:
				ifam = (struct ifa_msghdr*)rtm;
				if (index && ifam->ifam_index != index) { abort(); }
				else if (index == 0 || (ifam->ifam_addrs & RTA_MASKS) == 0) { break; }
				p = next + rtm->rtm_hdrlen;
				++icnt;
				alen = 0;
				for (p0 = p, i = 0; i < RTAX_MAX; i++) {
					if ((RTA_MASKS & ifam->ifam_addrs & (1 << i)) == 0) { continue; }
					sa = (struct sockaddr*)p;
					len = (size_t)SA_RLEN(sa);
					if (i == RTAX_IFA) {
						alen = len;
						break;
					}
					p += len;
				}
				for (p = p0, i = 0; i < RTAX_MAX; i++) {
					if ((RTA_MASKS & ifam->ifam_addrs & (1 << i)) == 0) { continue; }
					sa = (struct sockaddr*)p;
					len = (size_t)SA_RLEN(sa);
					if (i == RTAX_NETMASK && sa->sa_len == 0) { dcnt += (int)alen; }
					else { dcnt += (int)len; }
					p += len;
				}
				break;
			default: break;
		}
	}
	if (icnt + dcnt + ncnt == 1) {
		*pif = NULL;
		free(buf);
		return 0;
	}
	char* data = (char*)malloc((size_t)((sizeof(struct ifaddrs) * (size_t)icnt) + (size_t)dcnt + (size_t)ncnt));
	if (data == NULL) {
		free(buf);
		return -1;
	}
	ifa = (struct ifaddrs*)data;
	data += (int)(sizeof(struct ifaddrs) * (size_t)icnt);
	names = data + dcnt;
	memset(ifa, 0, sizeof(struct ifaddrs) * (size_t)icnt);
	ift = ifa;
	index = 0;
	for (next = buf; next < buf + needed; next += rtm->rtm_msglen) {
		rtm = (struct rt_msghdr*)next;
		if (rtm->rtm_version != RTM_VERSION) { continue; }
		switch (rtm->rtm_type) {
			case RTM_IFINFO:
				ifm = (struct if_msghdr*)rtm;
				if (ifm->ifm_addrs & RTA_IFP) {
					index = ifm->ifm_index;
					dl = (struct sockaddr_dl*)(next + rtm->rtm_hdrlen);
					cif = ift;
					ift->ifa_name = names;
					ift->ifa_flags = (unsigned int)ifm->ifm_flags;
					memcpy_no_output(names, dl->sdl_data, dl->sdl_nlen);
					names[dl->sdl_nlen] = 0;
					names += dl->sdl_nlen + 1;
					ift->ifa_addr = (struct sockaddr*)data;
					memcpy_no_output(data, dl, ((struct sockaddr*)dl)->sa_len);
					data += SA_RLEN((struct sockaddr*)dl);
					ift->ifa_data = data = (void*)ALIGN(data);
					dlen = rtm->rtm_hdrlen - offsetof(struct if_msghdr, ifm_data);
					if (dlen > sizeof(ifm->ifm_data)) { dlen = sizeof(ifm->ifm_data); }
					memcpy_no_output(data, &ifm->ifm_data, dlen);
	 				data += sizeof(ifm->ifm_data);
					ift = (ift->ifa_next = ift + 1);
				} else { index = 0; }
				break;
			case RTM_NEWADDR:
				ifam = (struct ifa_msghdr*)rtm;
				if (index && ifam->ifam_index != index) { abort(); }
				if (index == 0 || (ifam->ifam_addrs & RTA_MASKS) == 0) { break; }
				ift->ifa_name = cif->ifa_name;
				ift->ifa_flags = cif->ifa_flags;
				ift->ifa_data = NULL;
				p = next + rtm->rtm_hdrlen;
				alen = 0;
				for (p0 = p, i = 0; i < RTAX_MAX; i++) {
					if ((RTA_MASKS & ifam->ifam_addrs & (1 << i)) == 0) { continue; }
					sa = (struct sockaddr*)p;
					len = (size_t)SA_RLEN(sa);
					if (i == RTAX_IFA) {
						alen = len;
						break;
					}
					p += len;
				}
				for (p = p0, i = 0; i < RTAX_MAX; i++) {
					if ((RTA_MASKS & ifam->ifam_addrs & (1 << i)) == 0) { continue; }
					sa = (struct sockaddr*)p;
					len = (size_t)SA_RLEN(sa);
					switch (i) {
						case RTAX_IFA:
							ift->ifa_addr = (struct sockaddr*)data;
							memcpy_no_output(data, p, len);
							data += len;
							break;
						case RTAX_NETMASK:
							ift->ifa_netmask = (struct sockaddr*)data;
							if (sa->sa_len == 0) {
								memset(data, 0, alen);
								data += alen;
								break;
							}
							memcpy_no_output(data, p, len);
							data += len;
							break;
						case RTAX_BRD:
							ift->ifa_broadaddr = (struct sockaddr*)data;
							memcpy_no_output(data, p, len);
							data += len;
							break;
						default: break;
					}
					p += len;
				}
				ift = (ift->ifa_next = ift + 1);
				break;
			default: break;
		}
	}
	free(buf);
	if (--ift >= ifa) {
		ift->ifa_next = NULL;
		*pif = ifa;
	} else {
		*pif = NULL;
		free(ifa);
	}
	return 0;
}


LIB_FUNC void freeifaddrs(struct ifaddrs* ifp) {
	if (ifp != NULL) { free(ifp); }
}


#endif  // IFADDRS_H


/* ETHERNET PROTOCOL TYPES (<net/ethernet.h> & <net/ethertypes.h>) */


#if (!(defined(NET_ETHERNET_H) || defined(_NET_ETHERNET_H) || defined(_NET_ETHERNET_H_) || defined(_NET_ETHERTYPES_H) || defined(_NET_ETHERTYPES_H_)))
/** According to "assigned numbers", the Ethernet protocol numbers are also used as ARP protocol type numbers. Additional sources of information:
 - http://www.mit.edu/~map/Ethernet/Ethernet.txt
 - ftp://venera.isi.edu/in-notes/iana/assignments/ethernet-numbers
*/
#define NET_ETHERNET_H   (1)
#define _NET_ETHERNET_H   (1)
#define _NET_ETHERNET_H_   (1)
#define NET_ETHERTYPES_H   (1)
#define _NET_ETHERTYPES_H   (1)
#define _NET_ETHERTYPES_H_   (1)


#ifndef ETH_ALEN
#   define ETH_ALEN   6
#endif
#define ETHER_ADDR_LEN   ETH_ALEN
#define ETHER_TYPE_LEN   2
#define ETHER_CRC_LEN   4
#define ETHER_HDR_LEN   ETH_HLEN
#define ETHER_MIN_LEN   (ETH_ZLEN + ETHER_CRC_LEN)
#define ETHER_MAX_LEN   (ETH_FRAME_LEN + ETHER_CRC_LEN)
#define ETHER_IS_VALID_LEN(foo)   ((foo) >= ETHER_MIN_LEN && (foo) <= ETHER_MAX_LEN)
#define ETHERTYPE_NTRAILER   16
#define ETHERMTU   ETH_DATA_LEN
#define ETHERMIN   (ETHER_MIN_LEN - ETHER_HDR_LEN - ETHER_CRC_LEN)
/** IEEE 802.3 packet */
#define ETHERTYPE_8023   4
// 0x0101 - 0x1ff: Experimental
/** Xerox PUP protocol */
#define ETHERTYPE_PUP   0x200
/** PUP Address Translation */
#define ETHERTYPE_PUPAT   0x200
// 0x400: Nixdorf
#define ETHERTYPE_SPRITE   0x500
/** XNS */
#define ETHERTYPE_NS   0x600
/** XNS Address Translation (3Mb only) */
#define ETHERTYPE_NSAT   0x601
/** DLOG */
#define ETHERTYPE_DLOG1   0x660
/** DLOG */
#define ETHERTYPE_DLOG2   0x661
/** IP protocol */
#define ETHERTYPE_IP   0x800
/** X.75 Internet */
#define ETHERTYPE_X75   0x801
/** NBS Internet */
#define ETHERTYPE_NBS   0x802
/** ECMA Internet */
#define ETHERTYPE_ECMA   0x803
/** CHAOSnet */
#define ETHERTYPE_CHAOS   0x804
/** X.25 Level 3 */
#define ETHERTYPE_X25   0x805
/** Address resolution protocol */
#define ETHERTYPE_ARP   0x806
/** XNS Compatibility */
#define ETHERTYPE_NSCOMPAT   0x807
/** Frame Relay ARP (RFC1701) */
#define ETHERTYPE_FRARP   0x808
// 0x81c: Private Symbolics
// 0x888 - 0x88a: Xyplex
/** Ungermann-Bass network debugger */
#define ETHERTYPE_UBDEBUG   0x900
/** Xerox IEEE802.3 PUP */
#define ETHERTYPE_IEEEPUP   0xa00
/** Xerox IEEE802.3 PUP Address Translation */
#define ETHERTYPE_IEEEPUPAT   0xa01
/** Banyan VINES */
#define ETHERTYPE_VINES   0xbad
/** Banyan VINES Loopback */
#define ETHERTYPE_VINESLOOP   0xbae
/** Banyan VINES Echo */
#define ETHERTYPE_VINESECHO   0xbaf
// 0x1000 - 0x100f: Berkeley Trailer
/** Trailer packet */
#define ETHERTYPE_TRAIL   0x1000
/** DCA - Multicast */
#define ETHERTYPE_DCA   0x1234
/** VALID system protocol */
#define ETHERTYPE_VALID   0x1600
/** Artificial Horizons ("Aviator" dogfight simulator on SunOS) */
#define ETHERTYPE_DOGFIGHT   0x1989
/** Datapoint Corporation (RCL lan protocol) */
#define ETHERTYPE_RCL   0x1995
// The following 3C0x types are unregistered
/** 3Com NBP virtual circuit datagram (like XNS SPP) */
#define ETHERTYPE_NBPVCD   0x3c00
/** 3Com NBP System control datagram */
#define ETHERTYPE_NBPSCD   0x3c01
/** 3Com NBP Connect request (virtual cct) */
#define ETHERTYPE_NBPCREQ   0x3c02
/** 3Com NBP Connect response */
#define ETHERTYPE_NBPCRSP   0x3c03
/** 3Com NBP Connect complete */
#define ETHERTYPE_NBPCC   0x3c04
/** 3Com NBP Close request (virtual cct) */
#define ETHERTYPE_NBPCLREQ   0x3c05
/** 3Com NBP Close response */
#define ETHERTYPE_NBPCLRSP   0x3c06
/** 3Com NBP Datagram (like XNS IDP) */
#define ETHERTYPE_NBPDG   0x3c07
/** 3Com NBP Datagram broadcast */
#define ETHERTYPE_NBPDGB   0x3c08
/** 3Com NBP Claim NetBIOS name */
#define ETHERTYPE_NBPCLAIM   0x3c09
/** 3Com NBP Delete Netbios name */
#define ETHERTYPE_NBPDLTE   0x3c0a
/** 3Com NBP Remote adaptor status request */
#define ETHERTYPE_NBPRAS   0x3c0b
/** 3Com NBP Remote adaptor response */
#define ETHERTYPE_NBPRAR   0x3c0c
/** 3Com NBP Reset */
#define ETHERTYPE_NBPRST   0x3c0d
/** PCS Basic Block Protocol */
#define ETHERTYPE_PCS   0x4242
/** Information Modes Little Big LAN diagnostic */
#define ETHERTYPE_IMLBLDIAG   0x424c
/** THD - Diddle */
#define ETHERTYPE_DIDDLE   0x4321
/** Information Modes Little Big LAN */
#define ETHERTYPE_IMLBL   0x4c42
/** BBN Simnet Private */
#define ETHERTYPE_SIMNET   0x5208
/** DEC Unassigned, experimental */
#define ETHERTYPE_DECEXPER   0x6000
/** DEC MOP dump/load */
#define ETHERTYPE_MOPDL   0x6001
/** DEC MOP remote console */
#define ETHERTYPE_MOPRC   0x6002
/** DEC DECNET Phase IV route */
#define ETHERTYPE_DECnet   0x6003
/** libpcap, tcpdump */
#define ETHERTYPE_DN   ETHERTYPE_DECnet
/** DEC LAT */
#define ETHERTYPE_LAT   0x6004
/** DEC diagnostic protocol */
#define ETHERTYPE_DECDIAG   0x6005
/** DEC customer protocol */
#define ETHERTYPE_DECCUST   0x6006
/** DEC LAVC, SCA */
#define ETHERTYPE_SCA   0x6007
/** DEC AMBER */
#define ETHERTYPE_AMBER   0x6008
/** DEC MUMPS */
#define ETHERTYPE_DECMUMPS   0x6009
// 0x6010 - 0x6014: 3Com Corporation
/** Trans Ether Bridging (RFC1701)*/
#define ETHERTYPE_TRANSETHER   0x6558
/** Raw Frame Relay (RFC1701) */
#define ETHERTYPE_RAWFR   0x6559
/** Ungermann-Bass download */
#define ETHERTYPE_UBDL   0x7000
/** Ungermann-Bass NIUs */
#define ETHERTYPE_UBNIU   0x7001
/** Ungermann-Bass diagnostic/loopback */
#define ETHERTYPE_UBDIAGLOOP   0x7002
/** Ungermann-Base (NMC to/from UB Bridge) */
#define ETHERTYPE_UBNMC   0x7003
/** Ungermann-Bass Bridge Spanning Tree */
#define ETHERTYPE_UBBST   0x7005
/** OS/9 Microware */
#define ETHERTYPE_OS9   0x7007
/** OS/9 Net */
#define ETHERTYPE_OS9NET   0x7009
// 0x7020 - 0x7029: LRT (England; now Sintrom)
/** Racal-Interlan */
#define ETHERTYPE_RACAL   0x7030
/** Prime NTS (Network Terminal Service) */
#define ETHERTYPE_PRIMENTS   0x7031
/** Cabletron */
#define ETHERTYPE_CABLETRON   0x7034
/** Cronus VLN */
#define ETHERTYPE_CRONUSVLN   0x8003
/** Cronus Direct */
#define ETHERTYPE_CRONUS   0x8004
/** HP Probe */
#define ETHERTYPE_HP   0x8005
/** Nestar */
#define ETHERTYPE_NESTAR   0x8006
/** AT&T/Stanford (local use) */
#define ETHERTYPE_ATTSTANFORD   0x8008
/** Excelan */
#define ETHERTYPE_EXCELAN   0x8010
/** SGI diagnostic type */
#define ETHERTYPE_SG_DIAG   0x8013
/** SGI network games */
#define ETHERTYPE_SG_NETGAMES   0x8014
/** SGI reserved type */
#define ETHERTYPE_SG_RESV   0x8015
/** SGI bounce server */
#define ETHERTYPE_SG_BOUNCE   0x8016
/** Apollo DOMAIN */
#define ETHERTYPE_APOLLODOMAIN   0x8019
/** Tymeshare */
#define ETHERTYPE_TYMSHARE   0x802e
/** Tigan, Incorporated */
#define ETHERTYPE_TIGAN   0x802f
/** Reverse addr resolution protocol */
#define ETHERTYPE_REVARP   0x8035
/** Aeonic Systems */
#define ETHERTYPE_AEONIC   0x8036
/** IPX (Novell Netware) */
#define ETHERTYPE_IPXNEW   0x8037
/** DEC LANBridge */
#define ETHERTYPE_LANBRIDGE   0x8038
/** DEC DSM/DDP */
#define ETHERTYPE_DSMD   0x8039
/** DEC Argonaut Console */
#define ETHERTYPE_ARGONAUT   0x803a
/** DEC VAXELN */
#define ETHERTYPE_VAXELN   0x803b
/** DEC DNS Naming Service */
#define ETHERTYPE_DECDNS   0x803c
/** DEC Ethernet Encryption */
#define ETHERTYPE_ENCRYPT   0x803d
/** DEC Distributed Time Service */
#define ETHERTYPE_DECDTS   0x803e
/** DEC LAN Traffic Monitor */
#define ETHERTYPE_DECLTM   0x803f
/** DEC PATHWORKS DECnet NETBIOS Emulation */
#define ETHERTYPE_DECNETBIOS   0x8040
/** DEC Local Area System Transport */
#define ETHERTYPE_DECLAST   0x8041
// 0x8042: DEC Unassigned
/** Planning Research Corporation */
#define ETHERTYPE_PLANNING   0x8044
// 0x8046 - 0x8047: AT&T
/** DEC Availability Manager for Distributed Systems DECamds */
#define ETHERTYPE_DECAM   0x8048
/** ExperData */
#define ETHERTYPE_EXPERDATA   0x8049
/** Stanford V Kernel exp. */
#define ETHERTYPE_VEXP   0x805b
/** Stanford V Kernel prod. */
#define ETHERTYPE_VPROD   0x805c
/** Evans & Sutherland */
#define ETHERTYPE_ES   0x805d
/** Little Machines */
#define ETHERTYPE_LITTLE   0x8060
/** Counterpoint Computers */
#define ETHERTYPE_COUNTERPOINT   0x8062
// 0x8065 - 0x8066: University of Mass @ Amherst
/** Veeco Integrated Auto. */
#define ETHERTYPE_VEECO   0x8067
/** General Dynamics */
#define ETHERTYPE_GENDYN   0x8068
/** AT&T */
#define ETHERTYPE_ATT   0x8069
/** Autophon */
#define ETHERTYPE_AUTOPHON   0x806a
/** ComDesign */
#define ETHERTYPE_COMDESIGN   0x806c
/** Compugraphic Corporation */
#define ETHERTYPE_COMPUGRAPHIC   0x806d
// 0x806e - 0x8077: Landmark Graphics Corporation
/** Matra */
#define ETHERTYPE_MATRA   0x807a
/** Dansk Data Elektronik */
#define ETHERTYPE_DDE   0x807b
/** Merit Internodal or University of Michigan */
#define ETHERTYPE_MERIT   0x807c
/** 0x807d - 0x807f: Vitalink Communications */
/** Vitalink TransLAN III Management */
#define ETHERTYPE_VLTLMAN   0x8080
// 0x8081 - 0x8083: Counterpoint Computers
// 0x8088 - 0x808a: Xyplex
/** AppleTalk */
#define ETHERTYPE_ATALK   0x809b
/** AppleTalk (Old NetBSD) */
#define ETHERTYPE_AT   0x809b
/** AppleTalk (HP-UX) */
#define ETHERTYPE_APPLETALK   ETHERTYPE_ATALK
// 0x809c - 0x809e: Datability
/** Spider Systems Ltd. */
#define ETHERTYPE_SPIDER   0x809f
// 0x80a3: Nixdorf
// 0x80a4 - 0x80b3: Siemens Gammasonics Inc.
// 0x80c0 - 0x80c3: DCA (Digital Comm. Assoc.) Data Exchange Cluster
// 0x80c4 - 0x80c5: Banyan Systems
/** Pacer Software */
#define ETHERTYPE_PACER   0x80c6
/** Applitek Corporation */
#define ETHERTYPE_APPLITEK   0x80c7
// 0x80c8 - 0x80cc: Intergraph Corporation
// 0x80cd - 0x80ce: Harris Corporation
// 0x80cf - 0x80d2: Taylor Instrument
// 0x80d3 - 0x80d4: Rosemount Corporation
/** IBM SNA Services over Ethernet */
#define ETHERTYPE_SNA   0x80d5
/** Varian Associates */
#define ETHERTYPE_VARIAN   0x80dd
// 0x80de - 0x80df: TRFS (Integrated Solutions Transparent Remote File System)
// 0x80e0 - 0x80e3: Allen-Bradley
// 0x80e4 - 0x80f0: Datability
/** Retix */
#define ETHERTYPE_RETIX   0x80f2
/** AppleTalk AARP */
#define ETHERTYPE_AARP   0x80f3
// 0x80f4 - 0x80f5: Kinetics
/** Apollo Computer */
#define ETHERTYPE_APOLLO   0x80f7
/** IEEE 802.1Q VLAN tagging */
#define ETHERTYPE_VLAN   0x8100
// 0x80ff - 0x8101: Wellfleet Communications
/** Wellfleet; BOFL (Breath OF Life) pkts [every 5-10 secs.] */
#define ETHERTYPE_BOFL   0x8102
/** Wellfleet Communications */
#define ETHERTYPE_WELLFLEET   0x8103
// 0x8107 - 0x8109: Private Symbolics
/** Talaris */
#define ETHERTYPE_TALARIS   0x812b
/** Waterloo Microsystems Incorporated */
#define ETHERTYPE_WATERLOO   0x8130
/** Hayes Microcomputers */
#define ETHERTYPE_HAYES   0x8130
/** VG Laboratory Systems */
#define ETHERTYPE_VGLAB   0x8131
// 0x8132 - 0x8137: Bridge Communications
/** Novell; old NetWare IPX (ECONFIG E option) */
#define ETHERTYPE_IPX   0x8137
/** Novell, Incorporated */
#define ETHERTYPE_NOVELL   0x8138
// 0x8139 - 0x813d: KTI
/** M/MUMPS data sharing */
#define ETHERTYPE_MUMPS   0x813f
/** Vrije Universiteit (NL) Amoeba 4 RPC (obsolete) */
#define ETHERTYPE_AMOEBA   0x8145
/** Vrije Universiteit (NL) FLIP (Fast Local Internet Protocol) */
#define ETHERTYPE_FLIP   0x8146
/** Vrije Universiteit (NL); reserved */
#define ETHERTYPE_VURESERVED   0x8147
/** Logicraft */
#define ETHERTYPE_LOGICRAFT   0x8148
/** Network Computing Devices */
#define ETHERTYPE_NCD   0x8149
/** Alpha Micro */
#define ETHERTYPE_ALPHA   0x814a
/** SNMP over Ethernet (see RFC1089) */
#define ETHERTYPE_SNMP   0x814c
// 0x814d - 0x814e: BIIN
/** Technically Elite Concepts */
#define ETHERTYPE_TEC   0x814f
/** Rational Corp */
#define ETHERTYPE_RATIONAL   0x8150
// 0x8151 - 0x8153: Qualcomm
// 0x815c - 0x815e: Computer Protocol Pty Ltd
// 0x8164 - 0x8166: Charles River Data Systems
/** Protocol Engines XTP */
#define ETHERTYPE_XTP   0x817d
/** SGI/Time Warner prop. */
#define ETHERTYPE_SGITW   0x817e
/** HIPPI-FP encapsulation */
#define ETHERTYPE_HIPPI_FP   0x8180
/** Scheduled Transfer STP, HIPPI-ST */
#define ETHERTYPE_STP   0x8181
// 0x8182 - 0x8183: Reserved for HIPPI-6400
// 0x8184 - 0x818c: SGI prop.
/** Motorola */
#define ETHERTYPE_MOTOROLA   0x818d
/** PowerLAN NetBIOS/NetBEUI (PC) */
#define ETHERTYPE_NETBEUI   0x8191
// 0x819a - 0x81a3: RAD Network Devices
// 0x81b7 - 0x81b9: Xyplex
// 0x81cc - 0x81d5: Apricot Computers
// 0x81d6 - 0x81dd: Artisoft Lantastic
// 0x81e6 - 0x81ef: Polygon
// 0x81f0 - 0x81f2: Comsat Labs
// 0x81f3 - 0x81f5: SAIC
// 0x81f6 - 0x81f8: VG Analytical
// 0x8203 - 0x8205: QNX Software Systems Ltd.
// 0x8221 - 0x8222: Ascom Banking Systems
// 0x823e - 0x8240: Advanced Encryption Systems
// 0x8263 - 0x826a: Charles River Data Systems
// 0x827f - 0x8282: Athena Programming
// 0x829a - 0x829b: Inst Ind Info Tech
// 0x829c - 0x82ab: Taurus Controls
// 0x82ac - 0x8693: Walker Richer & Quinn
/** Accton Technologies (unregistered) */
#define ETHERTYPE_ACCTON   0x8390
/** Talaris multicast */
#define ETHERTYPE_TALARISMC   0x852b
/** Kalpana */
#define ETHERTYPE_KALPANA   0x8582
// 0x8694 - 0x869d: Idea Courier
// 0x869e - 0x86a1: Computer Network Tech
// 0x86a3 - 0x86ac: Gateway Communications
/** SECTRA */
#define ETHERTYPE_SECTRA   0x86db
/** IP protocol version 6 */
#define ETHERTYPE_IPV6   0x86dd
/** Delta Controls */
#define ETHERTYPE_DELTACON   0x86de
/** ATOMIC */
#define ETHERTYPE_ATOMIC   0x86df
// 0x86e0 - 0x86ef: Landis & Gyr Powers
// 0x8700 - 0x8710: Motorola
/** Control Technology Inc. RDP Without IP */
#define ETHERTYPE_RDP   0x8739
/** Control Technology Inc. Mcast Industrial Ctrl Proto. */
#define ETHERTYPE_MICP   0x873a
// 0x873b - 0x873c: Control Technology Inc. Proprietary
/** TCP/IP Compression (RFC1701) */
#define ETHERTYPE_TCPCOMP   0x876b
/** IP Autonomous Systems (RFC1701) */
#define ETHERTYPE_IPAS   0x876c
/** Secure Data (RFC1701) */
#define ETHERTYPE_SECUREDATA   0x876d
/** 802.3x flow control packet */
#define ETHERTYPE_FLOWCONTROL   0x8808
/** Slow protocols */
#define ETHERTYPE_SLOWPROTOCOLS   0x8809
/** PPP (obsolete by PPPOE) */
#define ETHERTYPE_PPP   0x880b
/** Hitachi Cable (Optoelectronic Systems Laboratory) */
#define ETHERTYPE_HITACHI   0x8820
/** MPLS Unicast */
#define ETHERTYPE_MPLS   0x8847
/** MPLS Multicast */
#define ETHERTYPE_MPLS_MCAST   0x8848
/** Axis Communications AB proprietary bootstrap/config */
#define ETHERTYPE_AXIS   0x8856
/** PPP Over Ethernet Discovery Stage */
#define ETHERTYPE_PPPOEDISC   0x8863
/** PPP Over Ethernet Session Stage */
#define ETHERTYPE_PPPOE   0x8864
/** HP LanProbe test */
#define ETHERTYPE_LANPROBE   0x8888
/** EAPOL PAE/802.1x */
#define ETHERTYPE_PAE   0x888e
/** ATA over Ethernet */
#define ETHERTYPE_AOE   0x88a2
/** Fibre Channel over Ethernet */
#define ETHERTYPE_FCOE   0x8906
/** Loopback */
#define ETHERTYPE_LOOPBACK   0x9000
/** DEC MOP loopback */
#define ETHERTYPE_LBACK   ETHERTYPE_LOOPBACK
/** 3Com (Formerly Bridge Communications), XNS Systems Management */
#define ETHERTYPE_XNSSM   0x9001
/** 3Com (Formerly Bridge Communications), TCP/IP Systems Management */
#define ETHERTYPE_TCPSM   0x9002
/** 3Com (Formerly Bridge Communications), loopback detection */
#define ETHERTYPE_BCLOOP   0x9003
/** DECNET; Used by VAX 6220 DEBNI */
#define ETHERTYPE_DEBNI   0xaaaa
/** Sonix Arpeggio */
#define ETHERTYPE_SONIX   0xfaf5
/** BBN VITAL-LanBridge cache wakeups */
#define ETHERTYPE_VITAL   0xff00
// 0xff00 - 0xffOf: ISC Bunker Ramo
/** Maximum valid ethernet type; reserved */
#define ETHERTYPE_MAX   0xffff


typedef struct ether_addr { uint8_t ether_addr_octet[ETH_ALEN]; }   ether_addr_t;


typedef struct attr_packed etherent {
	const char* e_name;
	struct ether_addr e_addr;
} etherent_t;


typedef struct ether_header {
	uint8_t ether_dhost[ETH_ALEN], ether_shost[ETH_ALEN];
	uint16_t ether_type;
} ether_header_t;


#endif  // NET_ETHERNET_H


/* <net/if_arp.h> */


#if (!(defined(NET_IF_ARP_H) || defined(_NET_IF_ARP_H) || defined(_NET_IF_ARP_H_)))
#define NET_IF_ARP_H   (1)
#define _NET_IF_ARP_H   (1)
#define _NET_IF_ARP_H_   (1)


#define ARPOP_REQUEST   1
#define ARPOP_REPLY   2
#define ARPOP_RREQUEST   3
#define ARPOP_RREPLY   4
#define ARPOP_InREQUEST   8
#define ARPOP_InREPLY   9
#define ARPOP_NAK   10
#define ARPHRD_NETROM   0
#define ARPHRD_ETHER   1
#define ARPHRD_EETHER   2
#define ARPHRD_AX25   3
#define ARPHRD_PRONET   4
#define ARPHRD_CHAOS   5
#define ARPHRD_IEEE802   6
#define ARPHRD_ARCNET   7
#define ARPHRD_APPLETLK   8
#define ARPHRD_DLCI   15
#define ARPHRD_ATM   19
#define ARPHRD_METRICOM   23
#define ARPHRD_IEEE1394   24
#define ARPHRD_EUI64   27
#define ARPHRD_INFINIBAND   32
#define ARPHRD_SLIP   256
#define ARPHRD_CSLIP   257
#define ARPHRD_SLIP6   258
#define ARPHRD_CSLIP6   259
#define ARPHRD_RSRVD   260
#define ARPHRD_ADAPT   264
#define ARPHRD_ROSE   270
#define ARPHRD_X25   271
#define ARPHRD_HWX25   272
#define ARPHRD_CAN   280
#define ARPHRD_PPP   512
#define ARPHRD_CISCO   513
#define ARPHRD_HDLC   ARPHRD_CISCO
#define ARPHRD_LAPB   516
#define ARPHRD_DDCMP   517
#define ARPHRD_RAWHDLC   518
#define ARPHRD_TUNNEL   768
#define ARPHRD_TUNNEL6   769
#define ARPHRD_FRAD   770
#define ARPHRD_SKIP   771
#define ARPHRD_LOOPBACK   772
#define ARPHRD_LOCALTLK   773
#define ARPHRD_FDDI   774
#define ARPHRD_BIF   775
#define ARPHRD_SIT   776
#define ARPHRD_IPDDP   777
#define ARPHRD_IPGRE   778
#define ARPHRD_PIMREG   779
#define ARPHRD_HIPPI   780
#define ARPHRD_ASH   781
#define ARPHRD_ECONET   782
#define ARPHRD_IRDA   783
#define ARPHRD_FCPP   784
#define ARPHRD_FCAL   785
#define ARPHRD_FCPL   786
#define ARPHRD_FCFABRIC   787
#define ARPHRD_IEEE802_TR   800
#define ARPHRD_IEEE80211   801
#define ARPHRD_IEEE80211_PRISM   802
#define ARPHRD_IEEE80211_RADIOTAP   803
#define ARPHRD_IEEE802154   804
#define ARPHRD_IEEE802154_MONITOR   805
#define ARPHRD_PHONET   820
#define ARPHRD_PHONET_PIPE   821
#define ARPHRD_CAIF   822
#define ARPHRD_IP6GRE   823
#define ARPHRD_NETLINK   824
#define ARPHRD_VOID   0xffff
#define ARPHRD_NONE   0xfffe
#define ATF_COM   2
#define ATF_PERM   4
#define ATF_PUBL   8
#define ATF_USETRAILERS   0x10
#define ATF_NETMASK   0x20
#define ATF_DONTPUB   0x40
#define ATF_MAGIC   0x80
#define ARPD_UPDATE   1
#define ARPD_LOOKUP   2
#define ARPD_FLUSH   3


typedef struct arphdr {
	uint16_t ar_hrd, ar_pro;
	uint8_t ar_hln, ar_pln;
	uint16_t ar_op;
} arphdr_t;


typedef struct attr_packed arpreq {
	struct sockaddr arp_pa, arp_ha;
	int arp_flags;
	struct sockaddr arp_netmask;
	char arp_dev[16];
} arpreq_t;


typedef struct attr_packed arpreq_old {
	struct sockaddr arp_pa, arp_ha;
	int arp_flags;
	struct sockaddr arp_netmask;
} arpreq_old_t;


typedef struct attr_packed arpd_request {
	unsigned short req;
	uint32_t ip;
	unsigned long dev, stamp, updated;
	unsigned char ha[MAX_ADDR_LEN];
} arpd_request_t;


#endif  // NET_IF_ARP_H


/* INTERNET ADDRESS FAMILY (<netinet/in.h>) */


#if (!(defined(NETINET_IN_H) || defined(_NETINET_IN_H) || defined(_NETINET_IN_H_)))  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/netinet_in.h.html
#define NETINET_IN_H   (1)
#define _NETINET_IN_H   (1)
#define _NETINET_IN_H_   (1)


typedef uint16_t   in_port_t;
/** Base type for Internet address */
typedef uint32_t   in_addr_t;
/** Internet address */
typedef struct in_addr { in_addr_t s_addr; }   in_addr;


#ifndef INET_ADDRSTRLEN
#   define INET_ADDRSTRLEN   16
#endif
#ifndef INET6_ADDRSTRLEN
#   define INET6_ADDRSTRLEN   46
#endif
#define IPPROTO_IP   0
#define IPPROTO_HOPOPTS   0
#define IPPROTO_ICMP   1
#define IPPROTO_IGMP   2
#define IPPROTO_IPIP   4
#define IPPROTO_TCP   6
#define IPPROTO_EGP   8
#define IPPROTO_PUP   12
#define IPPROTO_UDP   17
#define IPPROTO_IDP   22
#define IPPROTO_TP   29
#define IPPROTO_DCCP   33
#define IPPROTO_IPV6   41
#define IPPROTO_ROUTING   43
#define IPPROTO_FRAGMENT   44
#define IPPROTO_RSVP   46
#define IPPROTO_GRE   47
#define IPPROTO_ESP   50
#define IPPROTO_AH   51
#define IPPROTO_ICMPV6   58
#define IPPROTO_NONE   59
#define IPPROTO_DSTOPTS   60
#define IPPROTO_MTP   92
#define IPPROTO_BEETPH   94
#define IPPROTO_ENCAP   98
#define IPPROTO_PIM   103
#define IPPROTO_COMP   108
#define IPPROTO_SCTP   132
#define IPPROTO_MH   135
#define IPPROTO_UDPLITE   136
#define IPPROTO_MPLS   137
#define IPPROTO_RAW   255
#define IPPROTO_MAX   256
#define INADDR_ANY   ((in_addr_t)0)
#define INADDR_BROADCAST   ((in_addr_t)UINT32_MAX)
#define INADDR_NONE   ((in_addr_t)UINT32_MAX)
#define INADDR_LOOPBACK   ((in_addr_t)0x7f000001)
#define INADDR_UNSPEC_GROUP   ((in_addr_t)0xe0000000)
#define INADDR_ALLHOSTS_GROUP   ((in_addr_t)0xe0000001)
#define INADDR_ALLRTRS_GROUP   ((in_addr_t)0xe0000002)
#define INADDR_MAX_LOCAL_GROUP   ((in_addr_t)0xe00000ff)
#define IN6ADDR_ANY_INIT   { { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } } }
#define IN6ADDR_LOOPBACK_INIT   { { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } } }
#define IN6_IS_ADDR_UNSPECIFIED(a)   (((uint32_t*)(a))[0] == 0 && ((uint32_t*)(a))[1] == 0 && ((uint32_t*)(a))[2] == 0 && ((uint32_t*)(a))[3] == 0)
#define IN6_IS_ADDR_LOOPBACK(a)   (((uint32_t*)(a))[0] == 0 && ((uint32_t*)(a))[1] == 0 && ((uint32_t*)(a))[2] == 0 && ((uint8_t*)(a))[12] == 0 && ((uint8_t*)(a))[13] == 0 && ((uint8_t*)(a))[14] == 0 && ((uint8_t*)(a))[15] == 1 )
#define IN6_IS_ADDR_MULTICAST(a)   (((uint8_t*)(a))[0] == 0xff)
#define IN6_IS_ADDR_LINKLOCAL(a)   ((((uint8_t*)(a))[0]) == 0xfe && (((uint8_t*)(a))[1] & 0xc0) == 0x80)
#define IN6_IS_ADDR_SITELOCAL(a)   ((((uint8_t*)(a))[0]) == 0xfe && (((uint8_t*)(a))[1] & 0xc0) == 0xc0)
#define IN6_IS_ADDR_V4MAPPED(a)   (((uint32_t*)(a))[0] == 0 && ((uint32_t*)(a))[1] == 0 && ((uint8_t*)(a))[8] == 0 && ((uint8_t*)(a))[9] == 0 && ((uint8_t*)(a))[10] == 0xff && ((uint8_t*)(a))[11] == 0xff)
#define IN6_IS_ADDR_V4COMPAT(a)   (((uint32_t*)(a))[0] == 0 && ((uint32_t*)(a))[1] == 0 && ((uint32_t*)(a))[2] == 0 && ((uint8_t*)(a))[15] > 1)
#define IN6_IS_ADDR_MC_NODELOCAL(a)   (IN6_IS_ADDR_MULTICAST(a) && ((((uint8_t*)(a))[1] & 0xf) == 0x1))
#define IN6_IS_ADDR_MC_LINKLOCAL(a)   (IN6_IS_ADDR_MULTICAST(a) && ((((uint8_t*)(a))[1] & 0xf) == 0x2))
#define IN6_IS_ADDR_MC_SITELOCAL(a)   (IN6_IS_ADDR_MULTICAST(a) && ((((uint8_t*)(a))[1] & 0xf) == 0x5))
#define IN6_IS_ADDR_MC_ORGLOCAL(a)   (IN6_IS_ADDR_MULTICAST(a) && ((((uint8_t*)(a))[1] & 0xf) == 0x8))
#define IN6_IS_ADDR_MC_GLOBAL(a)   (IN6_IS_ADDR_MULTICAST(a) && ((((uint8_t*)(a))[1] & 0xf) == 0xe))
#define __ARE_4_EQUAL(a, b)   (!((0[a] - 0[b]) | (1[a]-1[b]) | (2[a] - 2[b]) | (3[a] - 3[b])))
#define IN6_ARE_ADDR_EQUAL(a, b)   __ARE_4_EQUAL((const uint32_t*)(a), (const uint32_t*)(b))
#define IN_CLASSA(a)   ((((in_addr_t)(a)) & 0x80000000) == 0)
#define IN_CLASSA_NET   0xff000000
#define IN_CLASSA_NSHIFT   24
#define IN_CLASSA_HOST   (UINT32_MAX & (~IN_CLASSA_NET))
#define IN_CLASSA_MAX   128
#define IN_CLASSB(a)   ((((in_addr_t)(a)) & 0xc0000000) == 0x80000000)
#define IN_CLASSB_NET   0xffff0000
#define IN_CLASSB_NSHIFT   16
#define IN_CLASSB_HOST   (UINT32_MAX & (~IN_CLASSB_NET))
#define IN_CLASSB_MAX   65536
#define IN_CLASSC(a)   ((((in_addr_t)(a)) & 0xe0000000) == 0xc0000000)
#define IN_CLASSC_NET   0xffffff00
#define IN_CLASSC_NSHIFT   8
#define IN_CLASSC_HOST   (UINT32_MAX & (~IN_CLASSC_NET))
#define IN_CLASSD(a)   ((((in_addr_t)(a)) & 0xf0000000) == 0xe0000000)
#define IN_MULTICAST(a)   IN_CLASSD(a)
#define IN_EXPERIMENTAL(a)   ((((in_addr_t)(a)) & 0xe0000000) == 0xe0000000)
#define IN_BADCLASS(a)   ((((in_addr_t)(a)) & 0xf0000000) == 0xf0000000)
#define IN_LOOPBACKNET   127
#define IP_TOS   1
#define IP_TTL   2
#define IP_HDRINCL   3
#define IP_OPTIONS   4
#define IP_ROUTER_ALERT   5
#define IP_RECVOPTS   6
#define IP_RETOPTS   7
#define IP_PKTINFO   8
#define IP_PKTOPTIONS   9
#define IP_PMTUDISC   10
#define IP_MTU_DISCOVER   10
#define IP_RECVERR   11
#define IP_RECVTTL   12
#define IP_RECVTOS   13
#define IP_MTU   14
#define IP_FREEBIND   15
#define IP_IPSEC_POLICY   16
#define IP_XFRM_POLICY   17
#define IP_PASSSEC   18
#define IP_TRANSPARENT   19
#define IP_ORIGDSTADDR   20
#define IP_RECVORIGDSTADDR   IP_ORIGDSTADDR
#define IP_MINTTL   21
#define IP_NODEFRAG   22
#define IP_CHECKSUM   23
#define IP_BIND_ADDRESS_NO_PORT   24
#define IP_MULTICAST_IF   32
#define IP_MULTICAST_TTL   33
#define IP_MULTICAST_LOOP   34
#define IP_ADD_MEMBERSHIP   35
#define IP_DROP_MEMBERSHIP   36
#define IP_UNBLOCK_SOURCE   37
#define IP_BLOCK_SOURCE   38
#define IP_ADD_SOURCE_MEMBERSHIP   39
#define IP_DROP_SOURCE_MEMBERSHIP   40
#define IP_MSFILTER   41
#define IP_MULTICAST_ALL   49
#define IP_UNICAST_IF   50
#define IP_RECVRETOPTS   IP_RETOPTS
#define IP_PMTUDISC_DONT   0
#define IP_PMTUDISC_WANT   1
#define IP_PMTUDISC_DO   2
#define IP_PMTUDISC_PROBE   3
#define IP_PMTUDISC_INTERFACE   4
#define IP_PMTUDISC_OMIT   5
#define IP_DEFAULT_MULTICAST_TTL   1
#define IP_DEFAULT_MULTICAST_LOOP   1
#define IP_MAX_MEMBERSHIPS   20
#define MCAST_JOIN_GROUP   42
#define MCAST_BLOCK_SOURCE   43
#define MCAST_UNBLOCK_SOURCE   44
#define MCAST_LEAVE_GROUP   45
#define MCAST_JOIN_SOURCE_GROUP   46
#define MCAST_LEAVE_SOURCE_GROUP   47
#define MCAST_MSFILTER   48
#define MCAST_EXCLUDE   0
#define MCAST_INCLUDE   1
#define IPV6_ADDRFORM   1
#define IPV6_2292PKTINFO   2
#define IPV6_2292HOPOPTS   3
#define IPV6_2292DSTOPTS   4
#define IPV6_2292RTHDR   5
#define IPV6_2292PKTOPTIONS   6
#define IPV6_CHECKSUM   7
#define IPV6_2292HOPLIMIT   8
#define IPV6_NEXTHOP   9
#define IPV6_AUTHHDR   10
#define IPV6_UNICAST_HOPS   16
#define IPV6_MULTICAST_IF   17
#define IPV6_MULTICAST_HOPS   18
#define IPV6_MULTICAST_LOOP   19
#define IPV6_JOIN_GROUP   20
#define IPV6_LEAVE_GROUP   21
#define IPV6_ROUTER_ALERT   22
#define IPV6_MTU_DISCOVER   23
#define IPV6_MTU   24
#define IPV6_RECVERR   25
#define IPV6_V6ONLY   26
#define IPV6_JOIN_ANYCAST   27
#define IPV6_LEAVE_ANYCAST   28
#define IPV6_IPSEC_POLICY   34
#define IPV6_XFRM_POLICY   35
#define IPV6_RECVPKTINFO   49
#define IPV6_PKTINFO   50
#define IPV6_RECVHOPLIMIT   51
#define IPV6_HOPLIMIT   52
#define IPV6_RECVHOPOPTS   53
#define IPV6_HOPOPTS   54
#define IPV6_RTHDRDSTOPTS   55
#define IPV6_RECVRTHDR   56
#define IPV6_RTHDR   57
#define IPV6_RECVDSTOPTS   58
#define IPV6_DSTOPTS   59
#define IPV6_RECVPATHMTU   60
#define IPV6_PATHMTU   61
#define IPV6_DONTFRAG   62
#define IPV6_RECVTCLASS   66
#define IPV6_TCLASS   67
#define IPV6_AUTOFLOWLABEL   70
#define IPV6_ADDR_PREFERENCES   72
#define IPV6_MINHOPCOUNT   73
#define IPV6_ORIGDSTADDR   74
#define IPV6_RECVORIGDSTADDR   IPV6_ORIGDSTADDR
#define IPV6_TRANSPARENT   75
#define IPV6_UNICAST_IF   76
#define IPV6_ADD_MEMBERSHIP   IPV6_JOIN_GROUP
#define IPV6_DROP_MEMBERSHIP   IPV6_LEAVE_GROUP
#define IPV6_RXHOPOPTS   IPV6_HOPOPTS
#define IPV6_RXDSTOPTS   IPV6_DSTOPTS
#define IPV6_PMTUDISC_DONT   0
#define IPV6_PMTUDISC_WANT   1
#define IPV6_PMTUDISC_DO   2
#define IPV6_PMTUDISC_PROBE   3
#define IPV6_PMTUDISC_INTERFACE 4
#define IPV6_PMTUDISC_OMIT   5
#define IPV6_PREFER_SRC_TMP   1
#define IPV6_PREFER_SRC_PUBLIC   2
#define IPV6_PREFER_SRC_PUBTMP_DEFAULT   0x100
#define IPV6_PREFER_SRC_COA   4
#define IPV6_PREFER_SRC_HOME   0x400
#define IPV6_PREFER_SRC_CGA   8
#define IPV6_PREFER_SRC_NONCGA   0x800
#define IPV6_RTHDR_LOOSE   0
#define IPV6_RTHDR_STRICT   1
#define IPV6_RTHDR_TYPE_0   0


typedef struct sockaddr_in {
	sa_family_t sin_family;
	in_port_t sin_port;
	struct in_addr sin_addr;
	uint8_t sin_zero[8];
} sockaddr_in_t;


typedef struct in6_addr {
	union in6_union {
		uint8_t __s6_addr[16];
		uint16_t __s6_addr16[8];
		uint32_t __s6_addr32[4];
	} __in6_union;
} in6_addr_t;
#define s6_addr   __in6_union.__s6_addr
#define s6_addr16   __in6_union.__s6_addr16
#define s6_addr32   __in6_union.__s6_addr32
static const UNUSED struct in6_addr in6addr_any, in6addr_loopback;


typedef struct sockaddr_in6 {
	sa_family_t sin6_family;
	in_port_t sin6_port;
	uint32_t sin6_flowinfo;
	struct in6_addr sin6_addr;
	uint32_t sin6_scope_id;
} sockaddr_in6_t;


typedef struct ipv6_mreq {
	struct in6_addr ipv6mr_multiaddr;
	unsigned ipv6mr_interface;
} ipv6_mreq_t;


typedef struct ip_opts {
	struct in_addr ip_dst;
	char ip_opts[40];
} ip_opts_t;


typedef struct ip_mreq {
	struct in_addr imr_multiaddr, imr_interface;
} ip_mreq_t;


typedef struct ip_mreqn {
	struct in_addr imr_multiaddr, imr_address;
	int imr_ifindex;
} ip_mreqn_t;


typedef struct ip_mreq_source {
	struct in_addr imr_multiaddr, imr_interface, imr_sourceaddr;
} ip_mreq_source_t;


typedef struct ip_msfilter {
	struct in_addr imsf_multiaddr, imsf_interface;
	uint32_t imsf_fmode, imsf_numsrc;
	struct in_addr imsf_slist[1];
} ip_msfilter_t;
#define IP_MSFILTER_SIZE(numsrc)   (sizeof(struct ip_msfilter) - sizeof(struct in_addr) + (numsrc) * sizeof(struct in_addr))


typedef struct attr_packed group_req {
	uint32_t gr_interface;
	struct sockaddr_storage gr_group;
} group_req_t;


typedef struct group_source_req {
	uint32_t gsr_interface;
	struct sockaddr_storage gsr_group, gsr_source;
} group_source_req_t;


typedef struct attr_packed group_filter {
	uint32_t gf_interface;
	struct sockaddr_storage gf_group;
	uint32_t gf_fmode, gf_numsrc;
	struct sockaddr_storage gf_slist[1];
} group_filter_t;
#define GROUP_FILTER_SIZE(numsrc)   (sizeof(struct group_filter) - sizeof(struct sockaddr_storage) + (numsrc) * sizeof(struct sockaddr_storage))


typedef struct in_pktinfo {
	int ipi_ifindex;
	struct in_addr ipi_spec_dst, ipi_addr;
} in_pktinfo_t;


typedef struct in6_pktinfo {
	struct in6_addr ipi6_addr;
	unsigned ipi6_ifindex;
} in6_pktinfo_t;


typedef struct ip6_mtuinfo {
	struct sockaddr_in6 ip6m_addr;
	uint32_t ip6m_mtu;
} ip6_mtuinfo_t;


#endif  // NETINET_IN_H


/* <netinet/ifether.h> */


#if (!(defined(NETINET_IF_ETHER_H) || defined(_NETINET_IF_ETHER_H) || defined(_NETINET_IF_ETHER_H_)))
#define _NETINET_IF_ETHER_H   (1)
#define _NETINET_IF_ETHER_H_   (1)


#ifndef ETH_ALEN
#   define ETH_ALEN   6
#endif
#define ETH_HLEN   14
#define ETH_ZLEN   60
#define ETH_DATA_LEN   1500
#define ETH_FRAME_LEN   1514
#define ETH_FCS_LEN   4
#define ETH_P_LOOP   0x60
#define ETH_P_PUP   0x200
#define ETH_P_PUPAT   0x201
#define ETH_P_IP   0x800
#define ETH_P_X25   0x805
#define ETH_P_ARP   0x806
#define ETH_P_BPQ   0x8ff
#define ETH_P_IEEEPUP   0xa00
#define ETH_P_IEEEPUPAT   0xa01
#define ETH_P_BATMAN   0x4305
#define ETH_P_DEC   0x6000
#define ETH_P_DNA_DL   0x6001
#define ETH_P_DNA_RC   0x6002
#define ETH_P_DNA_RT   0x6003
#define ETH_P_LAT   0x6004
#define ETH_P_DIAG   0x6005
#define ETH_P_CUST   0x6006
#define ETH_P_SCA   0x6007
#define ETH_P_TEB   0x6558
#define ETH_P_RARP   0x8035
#define ETH_P_ATALK   0x809b
#define ETH_P_AARP   0x80f3
#define ETH_P_8021Q   0x8100
#define ETH_P_IPX   0x8137
#define ETH_P_IPV6   0x86dd
#define ETH_P_PAUSE   0x8808
#define ETH_P_SLOW   0x8809
#define ETH_P_WCCP   0x883e
#define ETH_P_MPLS_UC   0x8847
#define ETH_P_MPLS_MC   0x8848
#define ETH_P_ATMMPOA   0x884c
#define ETH_P_PPP_DISC   0x8863
#define ETH_P_PPP_SES   0x8864
#define ETH_P_LINK_CTL   0x886c
#define ETH_P_ATMFATE   0x8884
#define ETH_P_PAE   0x888e
#define ETH_P_AOE   0x88a2
#define ETH_P_8021AD   0x88a8
#define ETH_P_802_EX1   0x88b5
#define ETH_P_TIPC   0x88ca
#define ETH_P_8021AH   0x88e7
#define ETH_P_MVRP   0x88f5
#define ETH_P_1588   0x88f7
#define ETH_P_PRP   0x88fb
#define ETH_P_FCOE   0x8906
#define ETH_P_TDLS   0x890d
#define ETH_P_FIP   0x8914
#define ETH_P_80221   0x8917
#define ETH_P_LOOPBACK   0x9000
#define ETH_P_QINQ1   0x9100
#define ETH_P_QINQ2   0x9200
#define ETH_P_QINQ3   0x9300
#define ETH_P_EDSA   0xdada
#define ETH_P_AF_IUCV   0xfbfb
#define ETH_P_802_3_MIN   0x600
#define ETH_P_802_3   1
#define ETH_P_AX25   2
#define ETH_P_ALL   3
#define ETH_P_802_2   4
#define ETH_P_SNAP   5
#define ETH_P_DDCMP   6
#define ETH_P_WAN_PPP   7
#define ETH_P_PPP_MP   8
#define ETH_P_LOCALTALK   9
#define ETH_P_CAN   0xc
#define ETH_P_CANFD   0xd
#define ETH_P_PPPTALK   0x10
#define ETH_P_TR_802_2   0x11
#define ETH_P_MOBITEX   0x15
#define ETH_P_CONTROL   0x16
#define ETH_P_IRDA   0x17
#define ETH_P_ECONET   0x18
#define ETH_P_HDLC   0x19
#define ETH_P_ARCNET   0x1a
#define ETH_P_DSA   0x1b
#define ETH_P_TRAILER   0x1c
#define ETH_P_PHONET   0xf5
#define ETH_P_IEEE802154   0xf6
#define ETH_P_CAIF   0xf7


typedef struct ethhdr {
	uint8_t h_dest[ETH_ALEN], h_source[ETH_ALEN];
	uint16_t h_proto;
} ethhdr_t;


typedef struct ether_arp {
	struct arphdr ea_hdr;
	uint8_t arp_sha[ETH_ALEN], arp_spa[4], arp_tha[ETH_ALEN], arp_tpa[4];
} ether_arp_t;
#define arp_hrd   ea_hdr.ar_hrd
#define arp_pro   ea_hdr.ar_pro
#define arp_hln   ea_hdr.ar_hln
#define arp_pln   ea_hdr.ar_pln
#define arp_op   ea_hdr.ar_op
#define ETHER_MAP_IP_MULTICAST(ipaddr, enaddr)   do { (enaddr)[0] = 1; (enaddr)[1] = 0; (enaddr)[2] = 0x5e; (enaddr)[3] = ((uint8_t*)ipaddr)[1] & 0x7f; (enaddr)[4] = ((uint8_t*)ipaddr)[2]; (enaddr)[5] = ((uint8_t*)ipaddr)[3]; } while (0x0)


#endif  // NETINET_IF_ETHER_H


/* <net/route.h> */


#if (!(defined(NET_ROUTE_H) || defined(_NET_ROUTE_H) || defined(_NET_ROUTE_H_)))
#define NET_ROUTE_H   (1)
#define _NET_ROUTE_H   (1)
#define _NET_ROUTE_H_   (1)


#define RTF_UP   1
#define RTF_GATEWAY   2
#define RTF_HOST   4
#define RTF_REINSTATE   8
#define RTF_DYNAMIC   0x10
#define RTF_MODIFIED   0x20
#define RTF_MTU   0x40
#define RTF_MSS   RTF_MTU
#define RTF_WINDOW   0x80
#define RTF_IRTT   0x100
#define RTF_NOFORWARD   0x1000
#define RTF_THROW   0x2000
#define RTF_NOPMTUDISC   0x4000
#define RTF_DEFAULT   0x10000
#define RTF_ALLONLINK   0x20000
#define RTF_ADDRCONF   0x40000
#define RTF_LINKRT   0x100000
#define RTF_NONEXTHOP   0x200000
#define RTF_CACHE   0x1000000
#define RTF_FLOW   0x2000000
#define RTF_POLICY   0x4000000
#define RTCF_VALVE   0x200000
#define RTCF_MASQ   0x400000
#define RTCF_NAT   0x800000
#define RTCF_DOREDIRECT   0x1000000
#define RTCF_LOG   0x2000000
#define RTCF_DIRECTSRC   0x4000000
#define RTF_INTERFACE   0x40000000
#define RTF_NAT   0x8000000
#define RTF_ADDRCLASSMASK   0xf8000000
#define RT_ADDRCLASS(flags)   ((uint32_t) flags >> 23)
#define RT_TOS(tos)   ((tos) & IPTOS_TOS_MASK)
#define RT_LOCALADDR(flags)   ((flags & RTF_ADDRCLASSMASK) == (RTF_LOCAL | RTF_INTERFACE))
#define RT_CLASS_UNSPEC   0
#define RT_CLASS_DEFAULT   253
#define RT_CLASS_MAIN   254
#define RT_CLASS_LOCAL   255
#define RT_CLASS_MAX   255
#define RTMSG_ACK   NLMSG_ACK
#define RTMSG_OVERRUN   NLMSG_OVERRUN
#define RTMSG_NEWDEVICE   0x11
#define RTMSG_DELDEVICE   0x12
#define RTMSG_NEWROUTE   0x21
#define RTMSG_DELROUTE   0x22
#define RTMSG_NEWRULE   0x31
#define RTMSG_DELRULE   0x32
#define RTMSG_CONTROL   0x40
#define RTMSG_AR_FAILED   0x51


typedef struct attr_packed rtentry {
	unsigned long rt_pad1;
	struct sockaddr rt_dst, rt_gateway, rt_genmask;
	unsigned short rt_flags;
	short rt_pad2;
	unsigned long rt_pad3;
	unsigned char rt_tos, rt_class;
	short rt_pad4[(SIZEOF_LONG / 2) - 1];
	short rt_metric;
	char* rt_dev;
	unsigned long rt_mtu, rt_window;
	unsigned short rt_irtt;
} rtentry_t;
#define rt_mss   rt_mtu


typedef struct attr_packed in6_rtmsg {
	struct in6_addr rtmsg_dst, rtmsg_src, rtmsg_gateway;
	uint32_t rtmsg_type;
	uint16_t rtmsg_dst_len, rtmsg_src_len;
	uint32_t rtmsg_metric;
	unsigned long rtmsg_info;
	uint32_t rtmsg_flags;
	int rtmsg_ifindex;
} in6_rtmsg_t;


#endif  // NET_ROUTE_H


/* SUN SOCKET & UNIX DOMAIN SOCKETS (<un.h> & <sys/un.h>) */


#if (!(defined(SYS_UN_H) || defined(_SYS_UN_H) || defined(_SYS_UN_H_)))  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_un.h.html
#define SYS_UN_H   (1)
#define _SYS_UN_H   (1)
#define _SYS_UN_H_   (1)


typedef struct sockaddr_un {
	sa_family_t sun_family;
	char sun_path[108];
} sockaddr_un_t;
#define SUN_LEN(s)   (2 + strlen((s)->sun_path))


#endif  // SYS_UN_H


/* <arpa/nameser.h> & <arpa/nameser_compat.h> */


#if (!(defined(ARPA_NAMESER_H) || defined(_ARPA_NAMESER_H) || defined(_ARPA_NAMESER_H_) || defined(_ARPA_NAMESER_COMPAT_H) || defined(_ARPA_NAMESER_COMPAT_H_)))
#define ARPA_NAMESER_H   (1)
#define _ARPA_NAMESER_H   (1)
#define _ARPA_NAMESER_H_   (1)
#define _ARPA_NAMESER_COMPAT_H   (1)
#define _ARPA_NAMESER_COMPAT_H_   (1)


#define __NAMESER   19991006
#define NS_PACKETSZ   512
#define NS_MAXDNAME   1025
#define NS_MAXMSG   65535
#define NS_MAXCDNAME   255
#define NS_MAXLABEL   63
#define NS_HFIXEDSZ   12
#define NS_QFIXEDSZ   4
#define NS_RRFIXEDSZ   10
#define NS_INT32SZ   4
#define NS_INT16SZ   2
#define NS_INT16SZ2   4
#define NS_INT8SZ   1
#define NS_INADDRSZ   4
#define NS_IN6ADDRSZ   16
#define NS_CMPRSFLGS   0xc0
#define NS_DEFAULTPORT   53
#define NS_TSIG_FUDGE   300
#define NS_TSIG_TCP_COUNT   100
#define NS_TSIG_ALG_HMAC_MD5   "HMAC-MD5.SIG-ALG.REG.INT"
#define NS_TSIG_ERROR_NO_TSIG   -10
#define NS_TSIG_ERROR_NO_SPACE   -11
#define NS_TSIG_ERROR_FORMERR   -12
#define NS_KEY_TYPEMASK   0xc000
#define NS_KEY_TYPE_AUTH_CONF   0
#define NS_KEY_TYPE_CONF_ONLY   0x8000
#define NS_KEY_TYPE_AUTH_ONLY   0x4000
#define NS_KEY_TYPE_NO_KEY  0xc000
#define NS_KEY_NO_AUTH   0x8000
#define NS_KEY_NO_CONF   0x4000
#define NS_KEY_RESERVED2   0x2000
#define NS_KEY_EXTENDED_FLAGS   0x1000
#define NS_KEY_RESERVED4   0x800
#define NS_KEY_RESERVED5   0x400
#define NS_KEY_NAME_TYPE   0x300
#define NS_KEY_NAME_USER   0x
#define NS_KEY_NAME_ENTITY  0x200
#define NS_KEY_NAME_ZONE   0x100
#define NS_KEY_NAME_RESERVED   0x300
#define NS_KEY_RESERVED8   0x80
#define NS_KEY_RESERVED9   0x40
#define NS_KEY_RESERVED10   0x20
#define NS_KEY_RESERVED11   0x10
#define NS_KEY_SIGNATORYMASK   0xf
#define NS_KEY_RESERVED_BITMASK   (NS_KEY_RESERVED2 | NS_KEY_RESERVED4 | NS_KEY_RESERVED5 | NS_KEY_RESERVED8 | NS_KEY_RESERVED9 | NS_KEY_RESERVED10 | NS_KEY_RESERVED11)
#define NS_KEY_RESERVED_BITMASK2   0xffff
#define NS_ALG_MD5RSA   1
#define NS_ALG_DH   2
#define NS_ALG_DSA   3
#define NS_ALG_DSS   NS_ALG_DSA
#define NS_ALG_EXPIRE_ONLY   253
#define NS_ALG_PRIVATE_OID   254
#define NS_KEY_PROT_TLS   1
#define NS_KEY_PROT_EMAIL   2
#define NS_KEY_PROT_DNSSEC   3
#define NS_KEY_PROT_IPSEC   4
#define NS_KEY_PROT_ANY   255
#define NS_MD5RSA_MIN_BITS   512
#define NS_MD5RSA_MAX_BITS   4096
#define NS_MD5RSA_MAX_BYTES   (((NS_MD5RSA_MAX_BITS + 7) >> 3) * 2 + 3)
#define NS_MD5RSA_MAX_BASE64   (((NS_MD5RSA_MAX_BYTES + 2) / 3) * 4)
#define NS_MD5RSA_MIN_SIZE   ((NS_MD5RSA_MIN_BITS + 7) >> 3)
#define NS_MD5RSA_MAX_SIZE   ((NS_MD5RSA_MAX_BITS + 7) >> 3)
#define NS_DSA_SIG_SIZE   41
#define NS_DSA_MIN_SIZE   213
#define NS_DSA_MAX_BYTES   405
#define NS_SIG_TYPE   0
#define NS_SIG_ALG   2
#define NS_SIG_LABELS   3
#define NS_SIG_OTTL   4
#define NS_SIG_EXPIR   8
#define NS_SIG_SIGNED   12
#define NS_SIG_FOOT   16
#define NS_SIG_SIGNER   18
#define NS_NXT_BITS   8
#define NS_NXT_BIT_SET(n, p)   (p[(n) / NS_NXT_BITS] |= (0x80 >> ((n) % NS_NXT_BITS)))
#define NS_NXT_BIT_CLEAR(n, p)   (p[(n) / NS_NXT_BITS] &= (~(0x80 >> ((n) % NS_NXT_BITS))))
#define NS_NXT_BIT_ISSET(n, p)   (p[(n) / NS_NXT_BITS] & (0x80 >> ((n) % NS_NXT_BITS)))
#define NS_NXT_MAX   127
#define NS_OPT_DNSSEC_OK   0x8000U
#define NS_OPT_NSID   3
#define NS_GET16(s, cp)   (void)((s) = (uint16_t)ns_get16(((cp) += 2) - 2))
#define NS_GET32(l, cp)   (void)((l) = (uint32_t)ns_get32(((cp) += 4) - 4))
#define NS_PUT16(s, cp)   ns_put16((s), ((cp) += 2) - 2)
#define NS_PUT32(l, cp)   ns_put32((l), ((cp) += 4) - 4)
#define __BIND   19950621
#define PACKETSZ   NS_PACKETSZ
#define MAXDNAME   NS_MAXDNAME
#define MAXCDNAME   NS_MAXCDNAME
#define MAXLABEL   NS_MAXLABEL
#define HFIXEDSZ   NS_HFIXEDSZ
#define QFIXEDSZ   NS_QFIXEDSZ
#define RRFIXEDSZ   NS_RRFIXEDSZ
#define INT32SZ   NS_INT32SZ
#define INT16SZ   NS_INT16SZ
#define INT8SZ   NS_INT8SZ
#define INADDRSZ   NS_INADDRSZ
#define IN6ADDRSZ   NS_IN6ADDRSZ
#define INDIR_MASK   NS_CMPRSFLGS
#define NAMESERVER_PORT   NS_DEFAULTPORT
#define S_ZONE   ns_s_zn
#define S_PREREQ   ns_s_pr
#define S_UPDATE   ns_s_ud
#define S_ADDT   ns_s_ar
#define QUERY   ns_o_query
#define IQUERY   ns_o_iquery
#define STATUS   ns_o_status
#define NS_NOTIFY_OP   ns_o_notify
#define NS_UPDATE_OP   ns_o_update
#define NOERROR   ns_r_noerror
#define FORMERR   ns_r_formerr
#define SERVFAIL   ns_r_servfail
#define NXDOMAIN   ns_r_nxdomain
#define NOTIMP   ns_r_notimpl
#define REFUSED   ns_r_refused
#define YXDOMAIN   ns_r_yxdomain
#define YXRRSET   ns_r_yxrrset
#define NXRRSET   ns_r_nxrrset
#define NOTAUTH   ns_r_notauth
#define NOTZONE   ns_r_notzone
#define DELETE   ns_uop_delete
#define ADD   ns_uop_add
#define T_A   ns_t_a
#define T_NS   ns_t_ns
#define T_MD   ns_t_md
#define T_MF   ns_t_mf
#define T_CNAME   ns_t_cname
#define T_SOA   ns_t_soa
#define T_MB   ns_t_mb
#define T_MG   ns_t_mg
#define T_MR   ns_t_mr
#define T_NULL   ns_t_null
#define T_WKS   ns_t_wks
#define T_PTR   ns_t_ptr
#define T_HINFO   ns_t_hinfo
#define T_MINFO   ns_t_minfo
#define T_MX   ns_t_mx
#define T_TXT   ns_t_txt
#define T_RP   ns_t_rp
#define T_AFSDB   ns_t_afsdb
#define T_X25   ns_t_x25
#define T_ISDN   ns_t_isdn
#define T_RT   ns_t_rt
#define T_NSAP   ns_t_nsap
#define T_NSAP_PTR  ns_t_nsap_ptr
#define T_SIG   ns_t_sig
#define T_KEY   ns_t_key
#define T_PX   ns_t_px
#define T_GPOS   ns_t_gpos
#define T_AAAA   ns_t_aaaa
#define T_LOC   ns_t_loc
#define T_NXT   ns_t_nxt
#define T_EID   ns_t_eid
#define T_NIMLOC   ns_t_nimloc
#define T_SRV   ns_t_srv
#define T_ATMA   ns_t_atma
#define T_NAPTR   ns_t_naptr
#define T_A6   ns_t_a6
#define T_DNAME   ns_t_dname
#define T_TSIG   ns_t_tsig
#define T_IXFR   ns_t_ixfr
#define T_AXFR   ns_t_axfr
#define T_MAILB   ns_t_mailb
#define T_MAILA   ns_t_maila
#define T_ANY   ns_t_any
#define C_IN   ns_c_in
#define C_CHAOS   ns_c_chaos
#define C_HS   ns_c_hs
#define C_NONE   ns_c_none
#define C_ANY   ns_c_any
#define GETSHORT   NS_GET16
#define GETLONG   NS_GET32
#define PUTSHORT   NS_PUT16
#define PUTLONG   NS_PUT32


typedef enum __ns_sect {
	ns_s_qd = 0,
	ns_s_zn = 0,
	ns_s_an = 1,
	ns_s_pr = 1,
	ns_s_ns = 2,
	ns_s_ud = 2,
	ns_s_ar = 3,
	ns_s_max = 4
} ns_sect;


typedef enum __ns_flag {
	ns_f_qr, ns_f_opcode,
	ns_f_aa, ns_f_tc, ns_f_rd,
	ns_f_ra, ns_f_z, ns_f_ad,
	ns_f_cd, ns_f_rcode, ns_f_max
} ns_flag;


typedef enum __ns_opcode {
	ns_o_query = 0,
	ns_o_iquery = 1,
	ns_o_status = 2,
	ns_o_notify = 4,
	ns_o_update = 5,
	ns_o_max = 6
} ns_opcode;


typedef enum __ns_rcode {
	ns_r_noerror = 0,
	ns_r_formerr = 1,
	ns_r_servfail = 2,
	ns_r_nxdomain = 3,
	ns_r_notimpl = 4,
	ns_r_refused = 5,
	ns_r_yxdomain = 6,
	ns_r_yxrrset = 7,
	ns_r_nxrrset = 8,
	ns_r_notauth = 9,
	ns_r_notzone = 10,
	ns_r_max = 11,
	ns_r_badvers = 16,
	ns_r_badsig = 16,
	ns_r_badkey = 17,
	ns_r_badtime = 18
} ns_rcode;


typedef enum __ns_update_operation {
	ns_uop_delete = 0,
	ns_uop_add = 1,
	ns_uop_max = 2
} ns_update_operation;


struct attr_packed ns_tsig_key {
	char name[NS_MAXDNAME], alg[NS_MAXDNAME];
	unsigned char* data;
	int len;
};
typedef struct ns_tsig_key   ns_tsig_key;


struct attr_packed ns_tcp_tsig_state {
	int counter;
	struct dst_key* key;
	void* ctx;
	unsigned char sig[NS_PACKETSZ];
	int siglen;
};
typedef struct ns_tcp_tsig_state ns_tcp_tsig_state;


typedef enum __ns_class {
	ns_c_invalid = 0,
	ns_c_in = 1,
	ns_c_2 = 2,
	ns_c_chaos = 3,
	ns_c_hs = 4,
	ns_c_none = 254,
	ns_c_any = 255,
	ns_c_max = 65536
} ns_class;


typedef enum __ns_key_types {
	ns_kt_rsa = 1,
	ns_kt_dh = 2,
	ns_kt_dsa = 3,
	ns_kt_private = 254
} ns_key_types;


typedef enum __ns_cert_types {
	cert_t_pkix = 1,
	cert_t_spki = 2,
	cert_t_pgp = 3,
	cert_t_url = 253,
	cert_t_oid = 254
} ns_cert_types;


typedef struct attr_packed __ns_msg {
	const unsigned char *_msg, *_eom;
	uint16_t _id, flags, _counts[ns_s_max];
	const unsigned char* _sections[ns_s_max];
	ns_sect _sect;
	int _rrnum;
	const unsigned char* _msg_ptr;
} ns_msg;
struct _ns_flagdata { int mask, shift; };
const struct _ns_flagdata _ns_flagdata[16] = {
	{ 0x8000, 15 }, { 0x7800, 11 }, { 0x400, 10 }, { 0x200, 9 },
	{ 0x100, 8 }, { 0x80, 7 }, { 0x40, 6 }, { 0x20, 5 }, { 0x10, 4 }, { 0xf, 0 },
	{ 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }
};
#define ns_msg_id(handle)   ((handle)._id + 0)
#define ns_msg_base(handle)   ((handle)._msg + 0)
#define ns_msg_end(handle)   ((handle)._eom + 0)
#define ns_msg_size(handle)   ((handle)._eom - (handle)._msg)
#define ns_msg_count(handle, section)   ((handle)._counts[section] + 0)
#define ns_msg_getflag(handle, flag)   (((handle).flags & _ns_flagdata[flag].mask) >> _ns_flagdata[flag].shift)


typedef struct attr_packed __ns_rr {
	char name[NS_MAXDNAME];
	uint16_t type, rr_class;
	uint32_t ttl;
	uint16_t rdlength;
	const unsigned char* rdata;
} ns_rr;
#define ns_rr_name(rr)   (((rr).name[0] != '\0') ? (rr).name : ".")
#define ns_rr_type(rr)   ((ns_type)((rr).type + 0))
#define ns_rr_class(rr)   ((ns_class)((rr).rr_class + 0))
#define ns_rr_ttl(rr)   ((rr).ttl + 0)
#define ns_rr_rdlen(rr)   ((rr).rdlength + 0)
#define ns_rr_rdata(rr)   ((rr).rdata + 0)


typedef enum __ns_type {
	ns_t_invalid = 0,
	ns_t_a = 1,
	ns_t_ns = 2,
	ns_t_md = 3,
	ns_t_mf = 4,
	ns_t_cname = 5,
	ns_t_soa = 6,
	ns_t_mb = 7,
	ns_t_mg = 8,
	ns_t_mr = 9,
	ns_t_null = 10,
	ns_t_wks = 11,
	ns_t_ptr = 12,
	ns_t_hinfo = 13,
	ns_t_minfo = 14,
	ns_t_mx = 15,
	ns_t_txt = 16,
	ns_t_rp = 17,
	ns_t_afsdb = 18,
	ns_t_x25 = 19,
	ns_t_isdn = 20,
	ns_t_rt = 21,
	ns_t_nsap = 22,
	ns_t_nsap_ptr = 23,
	ns_t_sig = 24,
	ns_t_key = 25,
	ns_t_px = 26,
	ns_t_gpos = 27,
	ns_t_aaaa = 28,
	ns_t_loc = 29,
	ns_t_nxt = 30,
	ns_t_eid = 31,
	ns_t_nimloc = 32,
	ns_t_srv = 33,
	ns_t_atma = 34,
	ns_t_naptr = 35,
	ns_t_kx = 36,
	ns_t_cert = 37,
	ns_t_a6 = 38,
	ns_t_dname = 39,
	ns_t_sink = 40,
	ns_t_opt = 41,
	ns_t_apl = 42,
	ns_t_tkey = 249,
	ns_t_tsig = 250,
	ns_t_ixfr = 251,
	ns_t_axfr = 252,
	ns_t_mailb = 253,
	ns_t_maila = 254,
	ns_t_any = 255,
	ns_t_zxfr = 256,
	ns_t_max = 65536
} ns_type;
#define ns_t_qt_p(t)   (ns_t_xfr_p(t) || (t) == ns_t_any || (t) == ns_t_mailb || (t) == ns_t_maila)
#define ns_t_mrr_p(t)   ((t) == ns_t_tsig || (t) == ns_t_opt)
#define ns_t_rr_p(t)   (!ns_t_qt_p(t) && !ns_t_mrr_p(t))
#define ns_t_udp_p(t)   ((t) != ns_t_axfr && (t) != ns_t_zxfr)
#define ns_t_xfr_p(t)   ((t) == ns_t_axfr || (t) == ns_t_ixfr || (t) == ns_t_zxfr)


typedef struct _HEADER_struct {
	unsigned id:16;
#   if IS_BIG_ENDIAN
	unsigned qr:1;
	unsigned opcode:4;
	unsigned aa:1;
	unsigned tc:1;
	unsigned rd:1;
	unsigned ra:1;
	unsigned unused:1;
	unsigned ad:1;
	unsigned cd:1;
	unsigned rcode:4;
#   else  // LITTLE_ENDIAN
	unsigned rd:1;
	unsigned tc:1;
	unsigned aa:1;
	unsigned opcode:4;
	unsigned qr:1;
	unsigned rcode:4;
	unsigned cd:1;
	unsigned ad:1;
	unsigned unused:1;
	unsigned ra:1;
#   endif
	unsigned qdcount:16;
	unsigned ancount:16;
	unsigned nscount:16;
	unsigned arcount:16;
} HEADER;


LIB_FUNC unsigned int ns_get16(const unsigned char* cp) {
	return ((unsigned int)(cp[0] << 8) | (unsigned int)cp[1]);
}


LIB_FUNC unsigned long ns_get32(const unsigned char* cp) {
	return (unsigned long)((unsigned long)(cp[0] << 24) | (unsigned long)(cp[1] << 16) | (unsigned long)(cp[2] << 8) | (unsigned long)cp[3]);
}


LIB_FUNC void ns_put16(const unsigned int s, unsigned char* cp) {
	*cp++ = (unsigned char)(s >> 8);
	*cp++ = (unsigned char)s;
}


LIB_FUNC void ns_put32(const unsigned long l, unsigned char* cp) {
	*cp++ = (unsigned char)(l >> 24);
	*cp++ = (unsigned char)(l >> 16);
	*cp++ = (unsigned char)(l >> 8);
	*cp++ = (unsigned char)l;
}


LIB_FUNC int dn_skipname(const unsigned char* cur, const unsigned char* eom) {
	const unsigned char* orig = cur;
	while (cur < eom) {
		if ((*cur & 0xc) == 0xc) {
			if (cur + 1 < eom) { return (int)(cur - orig + 2); }
			else { return -1; }
		} else if (*cur == 0) { return (int)(cur - orig + 1); }
		else if ((cur + *cur + 1) < eom) { cur += (*cur + 1); }
		else { return -1; }
	}
	return -1;
}


LIB_FUNC int ns_skiprr(const unsigned char* ptr, const unsigned char* eom, ns_sect section, int count) {
	const unsigned char* p = ptr;
	int r;
	while (count--) {
		r = dn_skipname(p, eom);
		if ((r < 0) || ((r + NS_INT16SZ2) > (eom - p))) { set_errno(EMSGSIZE); return -1; }
		p += r + NS_INT16SZ2;
		if (section != ns_s_qd) {
			if (NS_INT32SZ + NS_INT16SZ > eom - p) { set_errno(EMSGSIZE); return -1; }
			p += NS_INT32SZ;
			NS_GET16(r, p);
			if (r > eom - p) { set_errno(EMSGSIZE); return -1; }
			p += r;
		}
	}
	return (int)(p - ptr);
}


LIB_FUNC int ns_initparse(const unsigned char* msg, const int msglen, ns_msg* handle) {
	int r = 0;
	handle->_msg = msg;
	handle->_eom = msg + msglen;
	if (msglen < (2 + ns_s_max) * NS_INT16SZ) { set_errno(EMSGSIZE); return -1; }
	NS_GET16(handle->_id, msg);
	NS_GET16(handle->flags, msg);
	int i = 0;
	for (; i < ns_s_max; i++) { NS_GET16(handle->_counts[i], msg); }
	for (i = 0; i < ns_s_max; i++) {
		if (handle->_counts[i]) {
			handle->_sections[i] = msg;
			r = ns_skiprr(msg, handle->_eom, (ns_sect)i, handle->_counts[i]);
			if (r < 0) { return -1; }
			msg += r;
		} else { handle->_sections[i] = NULL; }
	}
	if (msg != handle->_eom) { set_errno(EMSGSIZE); return -1; }
	handle->_sect = ns_s_max;
	handle->_rrnum = -1;
	handle->_msg_ptr = NULL;
	return 0;
}


/** Return length of decoded data or -1 */
LIB_FUNC int dns_decodename(const unsigned char* packet, const unsigned int offset, unsigned char* dest, const unsigned int maxlen, const unsigned char* behindpacket) {
	const unsigned char* tmp;
	const unsigned char* max = dest + maxlen;
	const unsigned char* after = packet + offset;
	register int ok = 0;
	for (tmp = after; maxlen > 0 && *tmp; ) {
		if (tmp >= behindpacket) { return -1; }
		else if ((*tmp >> 6) == 3) {
			unsigned int ofs = ((unsigned int)(*tmp & 0x3f) << 8) | (*(tmp + 1));
			if (ofs >= (unsigned int)offset) { return -1; }
			if (after < tmp + 2) { after = tmp + 2; }
			tmp = packet + ofs;
			ok = 0;
		} else if ((*tmp >> 6) == 0) {
			unsigned int duh;
			if ((dest + *tmp + 1) > max) { return -1; }
			else if ((tmp + *tmp + 1) >= behindpacket) { return -1; }
			for (duh = *tmp; duh > 0; --duh) { *dest++ = *++tmp; }
			*dest++ = '.';
			ok = 1;
			++tmp;
			if (tmp > after) { after = tmp; if (!*tmp) { ++after; } }
		} else { return -1; }
	}
	if (ok) { --dest; }
	*dest = 0;
	return (int)(after - packet);
}
#define __dns_decodename(packet, offset, dest, maxlen, behindpacket)   dns_decodename((packet), (offset), (dest), (maxlen), (behindpacket))


LIB_FUNC int dn_expand(const unsigned char* msg, const unsigned char* eomorig, const unsigned char* comp_dn, unsigned char* exp_dn, const int length) {
	return (dns_decodename(msg, (unsigned int)(comp_dn - msg), exp_dn, (unsigned int)length, eomorig) - (int)(comp_dn - msg));
}


LIB_FUNC int ns_name_uncompress(const unsigned char* msg, const unsigned char* eom, const unsigned char* src, char* dst, const size_t dstsiz) {
	const int r = dn_expand(msg, eom, src, (unsigned char*)dst, (int)dstsiz);
	if (r < 0) { set_errno(EMSGSIZE); }
	return r;
}


LIB_FUNC int ns_parserr(ns_msg* handle, ns_sect section, int rrnum, ns_rr* rr) {
	if (section < 0 || section >= ns_s_max) { set_errno(ENODEV); return -1; }
	else if (section != handle->_sect) {
		handle->_sect = section;
		handle->_rrnum = 0;
		handle->_msg_ptr = handle->_sections[section];
	}
	if (rrnum == -1) { rrnum = handle->_rrnum; }
	if (rrnum < 0 || rrnum >= handle->_counts[section]) { set_errno(ENODEV); return -1; }
	else if (rrnum < handle->_rrnum) {
		handle->_rrnum = 0;
		handle->_msg_ptr = handle->_sections[section];
	}
	register int r;
	if (rrnum > handle->_rrnum) {
		r = ns_skiprr(handle->_msg_ptr, handle->_eom, section, rrnum - handle->_rrnum);
		if (r < 0) { return -1; }
		handle->_msg_ptr += r;
		handle->_rrnum = rrnum;
	}
	r = ns_name_uncompress(handle->_msg, handle->_eom, handle->_msg_ptr, rr->name, NS_MAXDNAME);
	if (r < 0) { return -1; }
	handle->_msg_ptr += r;
	if (NS_INT16SZ2 > handle->_eom - handle->_msg_ptr) { set_errno(EMSGSIZE); return -1; }
	NS_GET16(rr->type, handle->_msg_ptr);
	NS_GET16(rr->rr_class, handle->_msg_ptr);
	if (section != ns_s_qd) {
		if (NS_INT32SZ + NS_INT16SZ > handle->_eom - handle->_msg_ptr) { set_errno(EMSGSIZE); return -1; }
		NS_GET32(rr->ttl, handle->_msg_ptr);
		NS_GET16(rr->rdlength, handle->_msg_ptr);
		if (rr->rdlength > handle->_eom - handle->_msg_ptr) { set_errno(EMSGSIZE); return -1; }
		rr->rdata = handle->_msg_ptr;
		handle->_msg_ptr += rr->rdlength;
	} else {
		rr->ttl = 0;
		rr->rdlength = 0;
		rr->rdata = NULL;
	}
	handle->_rrnum++;
	if (handle->_rrnum > handle->_counts[section]) {
		handle->_sect = section + 1;
		if (handle->_sect == ns_s_max) {
			handle->_rrnum = -1;
			handle->_msg_ptr = NULL;
		} else { handle->_rrnum = 0; }
	}
	return 0;
}


#endif  // ARPA_NAMESER_H


/* INTERNET OPERATIONS (<arpa/inet.h>) */


#if (!(defined(ARPA_INET_H) || defined(_ARPA_INET_H) || defined(_ARPA_INET_H_)))  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/arpa_inet.h.html
#define ARPA_INET_H   (1)
#define _ARPA_INET_H   (1)
#define _ARPA_INET_H_   (1)


#ifndef INET_ADDRSTRLEN
#   define INET_ADDRSTRLEN   16
#endif
#ifndef INET6_ADDRSTRLEN
#   define INET6_ADDRSTRLEN   46
#endif


LIB_FUNC char* inet_ntoa(struct in_addr in) {
	static char buf[16] = { 0 };
	unsigned char* a = (void*)&in;
	snprintf(buf, sizeof(buf), "%d.%d.%d.%d", a[0], a[1], a[2], a[3]);
	return buf;
}


/** Internet network address interpretation routine */
LIB_FUNC in_addr_t inet_network(const char* cp) {
	in_addr_t val, base, n;
	char c;
	in_addr_t parts[4] = { 0 }, *pp = parts;
	int i, _digit;
goto_inet_network_again:
	val = 0; base = 10; _digit = 0;
	if (*cp == '0') { _digit = 1, base = 8, cp++; }
	if (*cp == 'x' || *cp == 'X') { base = 16, cp++; }
	while ((c = *cp) != 0) {
		if (isdigit((unsigned char)c)) {
			if (base == 8U && (c == '8' || c == '9')) { return INADDR_NONE; }
			val = (val * base) + (in_addr_t)(c - '0');
			++cp;
			_digit = 1;
			continue;
		}
		if (base == 16U && isxdigit((unsigned char)c)) {
			val = (in_addr_t)(val << 4) + (in_addr_t)(c + 10 - (islower((unsigned char)c) ? 'a' : 'A'));
			++cp;
			_digit = 1;
			continue;
		}
		break;
	}
	if (!_digit) { return INADDR_NONE; }
	else if (pp >= parts + 4 || val > 0xffU) { return INADDR_NONE; }
	else if (*cp == '.') {
		*pp++ = val, cp++;
		goto goto_inet_network_again;
	}
	if (*cp && (!isspace(*cp & 0xff))) { return INADDR_NONE; }
	*pp++ = val;
	n = (in_addr_t)(pp - parts);
	if (n > 4U) { return INADDR_NONE; }
	for (val = 0, i = 0; i < (int)n; i++) {
		val <<= 8;
		val |= parts[i] & 0xff;
	}
	return val;
}
#define __inet_network(cp)   inet_network((cp))


LIB_FUNC int inet_pton(const int af, char* restrict s, void* restrict a0) {
	unsigned char* a = a0;
	int i, j, v, d, brk = -1, need_v4 = 0;
	if (af == AF_INET) {
		for (i = 0; i < 4; i++) {
			for (v = j = 0; j < 3 && isdigit(s[j]); j++) { v = 10 * v + s[j] - '0'; }
			if (j == 0 || (j > 1 && s[0] == '0') || v > 255) { return 0; }
			a[i] = (unsigned char)v;
			if (s[j] == 0 && i == 3) { return 1; }
			else if (s[j] != '.') { return 0; }
			s += j + 1;
		}
		return 0;
	} else if (af != AF_INET6) {
		set_errno(EAFNOSUPPORT);
		return -1;
	} else if (*s == ':' && *++s != ':') { return 0; }
	uint16_t ip[8] = { 0 };
	for (i = 0; ; i++) {
		if (s[0] == ':' && brk < 0) {
			brk = i;
			ip[i & 7] = 0;
			if (!(*++s)) { break; }
			if (i == 7) { return 0; }
			continue;
		}
		for (v = j = 0; j < 4 && (d = hexval((unsigned int)s[j])) >= 0; j++) { v = 16 * v + d; }
		if (j == 0) { return 0; }
		ip[i & 7] = (uint16_t)v;
		if (!s[j] && (brk >= 0 || i == 7)) { break; }
		else if (i == 7) { return 0; }
		if (s[j] != ':') {
			if (s[j] != '.' || (i < 6 && brk < 0)) { return 0; }
			need_v4 = 1;
			i++;
			break;
		}
		s += j + 1;
	}
	if (brk >= 0) {
		memmove_no_output((ip + brk + 7 - i), (ip + brk), (size_t)(2 * (i + 1 - brk)));
		for (j = 0; j < 7 - i; j++) { ip[brk + j] = 0; }
	}
	for (j = 0; j < 8; j++) {
		*a++ = (unsigned char)(ip[j] >> 8);
		*a++ = (unsigned char)ip[j];
	}
	if (need_v4 && inet_pton(AF_INET, (void*)s, (a - 4)) <= 0) { return 0; }
	return 1;
}


LIB_FUNC const char* inet_ntop(const int af, const void* restrict a0, char* restrict s, const socklen_t sock_len) {
	const unsigned char* a = a0;
	int i, j, max, best;
	char buf[100] = { 0 };
	switch (af) {
		case AF_INET:
			if (snprintf(s, sock_len, "%d.%d.%d.%d", a[0], a[1], a[2], a[3]) < (int)sock_len) { return s; }
			break;
		case AF_INET6:
			if (memcmp(a, "\0\0\0\0\0\0\0\0\0\0\377\377", 12)) {
				snprintf(buf, sizeof(buf), "%x:%x:%x:%x:%x:%x:%x:%x", (unsigned int)(256 * a[0] + a[1]), (unsigned int)(256 * a[2] + a[3]), (unsigned int)(256 * a[4] + a[5]), (unsigned int)(256 * a[6] + a[7]), (unsigned int)(256 * a[8] + a[9]), (unsigned int)(256 * a[10] + a[11]), (unsigned int)(256 * a[12] + a[13]), (unsigned int)(256 * a[14] + a[15]));
			} else {
				snprintf(buf, sizeof(buf), "%x:%x:%x:%x:%x:%x:%d.%d.%d.%d", (unsigned int)(256 * a[0] + a[1]), (unsigned int)(256 * a[2] + a[3]), (unsigned int)(256 * a[4] + a[5]), (unsigned int)(256 * a[6] + a[7]), (unsigned int)(256 * a[8] + a[9]), (unsigned int)(256 * a[10] + a[11]), (int)a[12], (int)a[13], (int)a[14], (int)a[15]);
			}
			for (i = best = 0, max = 2; buf[i]; i++) {
				if (i && buf[i] != ':') { continue; }
				j = (int)strspn((buf + i), ":0");
				if (j > max) { best = i, max = j; }
			}
			if (max > 2) {
				buf[best] = buf[best + 1] = ':';
				memmove_no_output((buf + best + 2), (buf + best + max), (size_t)(i - best - max + 1));
			}
			if (strlen(buf) < sock_len) { return strcpy(s, buf); }
			break;
		default:
			set_errno(EAFNOSUPPORT);
			return 0;
	}
	set_errno(ENOSPC);
	return 0;
}


LIB_FUNC int inet_aton(const char* s0, struct in_addr* dest) {
	const char* s = s0;
	unsigned char* d = (unsigned char*)dest;
	unsigned long a[4] = { 0 };
	const char** restrict z = NULL;
	int i = 0;
	for (; i < 4; i++) {
		a[i] = strtoul(s, z, 0);
		if (*z == s || (**z && **z != '.') || (!isdigit(*s))) { return 0; }
		else if (!*z) { break; }
		s = (*z + 1);
	}
	switch (i) {
		case 0:
			a[1] = a[0] & 0xffffff;
			a[0] >>= 24;
			break;
		case 1:
			a[2] = a[1] & 0xffff;
			a[1] >>= 16;
			break;
		case 2:
			a[3] = a[2] & 0xff;
			a[2] >>= 8;
			break;
		default:  // 4
			return 0;
	}
	for (i = 0; i < 4; i++) {
		if (a[i] > 255) { return 0; }
		d[i] = (unsigned char)a[i];
	}
	return 1;
}
#define __inet_aton(s0, dest)   inet_aton((s0), (dest))


LIB_FUNC in_addr_t inet_addr(const char* p) {
	struct in_addr a;
	if ((!inet_aton(p, &a))) { return (in_addr_t)-1; }
	return a.s_addr;
}


/** Formulate an Internet address from network + host; Used in building addresses stored in the ifnet structure */
LIB_FUNC struct in_addr inet_makeaddr(const in_addr_t net, const in_addr_t host) {
	struct in_addr a;
	if (net < 128U) { a.s_addr = (net << IN_CLASSA_NSHIFT) | (host & IN_CLASSA_HOST); }
	else if (net < 65536U) { a.s_addr = (net << IN_CLASSB_NSHIFT) | (host & IN_CLASSB_HOST); }
	else if (net < 16777216L) { a.s_addr = (net << IN_CLASSC_NSHIFT) | (host & IN_CLASSC_HOST); }
	else { a.s_addr = net | host; }
	a.s_addr = htonl(a.s_addr);
	return a;
}
#define __inet_makeaddr(net, host)   inet_makeaddr((net), (host))


/** Return the local network address portion of an Internet address; handles class a/b/c network number formats */
LIB_FUNC in_addr_t inet_lnaof(const struct in_addr in) {
	in_addr_t i = ntohl(in.s_addr);
	if (IN_CLASSA(i)) { return ((i) & IN_CLASSA_HOST); }
	else if (IN_CLASSB(i)) { return ((i) & IN_CLASSB_HOST); }
	return ((i) & IN_CLASSC_HOST);
}
#define __inet_lnaof(in)   inet_lnaof((in))


/** Return the network number from an Internet address; this handles class a, b, and c network numbers */
LIB_FUNC in_addr_t inet_netof(const struct in_addr in) {
	in_addr_t i = ntohl(in.s_addr);
	if (IN_CLASSA(i)) { return (((i)&IN_CLASSA_NET) >> IN_CLASSA_NSHIFT); }
	else if (IN_CLASSB(i)) { return (((i)&IN_CLASSB_NET) >> IN_CLASSB_NSHIFT); }
	return (((i)&IN_CLASSC_NET) >> IN_CLASSC_NSHIFT);
}
#define __inet_netof(in)   inet_netof((in))


/** Format an in_addr_t network number into presentation format */
LIB_FUNC char* inet_neta(in_addr_t src, char* dst, size_t size) {
	char* odst = dst;
	char* tp;
	while (src & UINT32_MAX) {
		unsigned char b = (unsigned char)((uint32_t)(src & 0xff000000) >> 24);
		src <<= 8;
		if (b) {
			if (size < sizeof("255.")) { set_errno(EMSGSIZE); return NULL; }
			tp = dst;
			dst += sprintf(dst, "%u", b);
			if (src != 0L) {
				*dst++ = '.';
				*dst = '\0';
			}
			size -= (size_t)(dst - tp);
		}
	}
	if (dst == odst) {
		if (size < sizeof("0.0.0.0")) { set_errno(EMSGSIZE); return NULL; }
		strcpy_no_output(dst, "0.0.0.0");
	}
	return odst;
}
#define __inet_neta(src, dst, size)   inet_neta((src), (dst), (size))


/** Convert IPv4 network number from network to presentation format; This always generates a CIDR style result */
LIB_FUNC char* inet_net_ntop_ipv4(const unsigned char* src, const int bits, char* dst, size_t size) {
	char* odst = dst;
	char* t;
	if (bits < 0 || bits > 32) {
		set_errno(EINVAL);
		return NULL;
	} else if (bits == 0) {
		if (size < sizeof("0")) { set_errno(EMSGSIZE); return NULL; }
		*dst++ = '0';
		size--;
		*dst = '\0';
	}
	unsigned int m;
	register int b;
	// Format whole octets
	for (b = bits / 8; b > 0; b--) {
		if (size <= sizeof("255.")) { set_errno(EMSGSIZE); return NULL; }
		t = dst;
		dst += sprintf(dst, "%u", *src++);
		if (b > 1) {
			*dst++ = '.';
			*dst = '\0';
		}
		size -= (size_t)(dst - t);
	}
	// Format partial octet
	b = bits % 8;
	if (b > 0) {
		if (size <= sizeof(".255")) { set_errno(EMSGSIZE); return NULL; }
		t = dst;
		if (dst != odst) { *dst++ = '.'; }
		m = (unsigned int)((unsigned int)((1 << b) - 1) << (unsigned int)(8 - b));
		dst += sprintf(dst, "%u", (*src & m));
		size -= (size_t)(dst - t);
	}
	// Format CIDR /width
	if (size <= sizeof("/32")) { set_errno(EMSGSIZE); return NULL; }
	dst += sprintf(dst, "/%u", (unsigned int)bits);
	return odst;
}


/** Convert IPv6 network number from network to presentation format; This always generates a CIDR style result */
LIB_FUNC char* inet_net_ntop_ipv6(const unsigned char* src, const int bits, char* dst, const size_t size) {
	int b, i, p, words, zero_s, zero_l, tmp_zero_s, tmp_zero_l, is_ipv4 = 0;
	unsigned char inbuf[16] = { 0 };
	char outbuf[sizeof("xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:255.255.255.255/128")];
	char* cp;
	unsigned char* s;
	if (bits < 0 || bits > 128) { set_errno(EINVAL); return NULL; }
	cp = outbuf;
	if (bits == 0) {
		*cp++ = ':';
		*cp++ = ':';
		*cp = '\0';
	} else {  // Copy src to private buffer; Zero host portion
		p = ((bits + 7) / 8);
		memcpy_no_output(inbuf, src, (size_t)p);
		memset_no_output((inbuf + p), 0, (size_t)(16 - p));
		b = bits % 8;
		if (b != 0) {
			inbuf[p - 1] = (unsigned char)(inbuf[p - 1] & ((unsigned char)((unsigned int)(~0) << (unsigned int)(8 - b))));
		}
		s = inbuf;
		words = (bits + 15) / 16;  // Number of words needed to be displayed in output
		if (words == 1) { words = 2; }
		// Find the longest substring of zero's
		zero_s = zero_l = tmp_zero_s = tmp_zero_l = 0;
		for (i = 0; i < (words * 2); i += 2) {
			if ((s[i] | s[i + 1]) == 0) {
				if (tmp_zero_l == 0) { tmp_zero_s = i / 2; }
				++tmp_zero_l;
			} else if (tmp_zero_l && zero_l < tmp_zero_l) {
				zero_s = tmp_zero_s;
				zero_l = tmp_zero_l;
				tmp_zero_l = 0;
			}
		}
		if (tmp_zero_l && zero_l < tmp_zero_l) {
			zero_s = tmp_zero_s;
			zero_l = tmp_zero_l;
		}
		if (zero_l != words && zero_s == 0 && ((zero_l == 6) || ((zero_l == 5 && s[10] == 0xff && s[11] == 0xff) || ((zero_l == 7 && s[14] != 0 && s[15] != 1))))) { is_ipv4 = 1; }
		for (p = 0; p < words; p++) {  // Format whole words
			if (zero_l != 0 && p >= zero_s && p < zero_s + zero_l) {  // Skip some zeros
				if (p == zero_s || p == (words - 1)) { *cp++ = ':'; }
				++s;
				++s;
				continue;
			}
			if (is_ipv4 && p > 5 ) {
				*cp++ = ((p == 6) ? ':' : '.');
				cp += sprintf(cp, "%u", *s++);
				if (p != 7 || bits > 120) {
					*cp++ = '.';
					cp += sprintf(cp, "%u", *s++);
				}
			} else {
				if (cp != outbuf) { *cp++ = ':'; }
				cp += sprintf(cp, "%x", (unsigned int)(*s * 256 + s[1]));
				s += 2;
			}
		}
	}
	// Format CIDR /width
	sprintf(cp, "/%u", (unsigned int)bits);
	if (strlen(outbuf) + 1 > size) { set_errno(EMSGSIZE); return NULL; }
	strcpy_no_output(dst, outbuf);
	return (dst);
}
#define __inet_net_ntop_ipv6(src, bits, dst, size)   inet_net_ntop_ipv6((src), (bits), (dst), (size))


/** Convert network number from network to presentation format; This always generates a CIDR style result */
LIB_FUNC char* inet_net_ntop(const int af, const void* src, const int bits, char* dst, const size_t size) {
	switch (af) {
		case AF_INET:
			return inet_net_ntop_ipv4(src, bits, dst, size);
		case AF_INET6:
			return inet_net_ntop_ipv6(src, bits, dst, size);
		default:
			set_errno(EAFNOSUPPORT);
			return NULL;
	}
	UNREACHABLE
}


/** Convert an IPv4 network number from presentation to network format; accepts hex octets, hex strings, decimal octets, and CIDR */
LIB_FUNC int inet_net_pton_ipv4(const char* src, unsigned char* dst, size_t size) {
	int n, ch, tmp = 0, dirty, bits;
	const unsigned char* odst = dst;
	ch = *src++;
	if (ch == '0' && (src[0] == 'x' || src[0] == 'X') && isascii((unsigned char)(src[1])) && isxdigit((unsigned char)(src[1]))) {  // Hexadecimal: Eat nybble string
		if (size <= 0U) { set_errno(EMSGSIZE); return -1; }
		dirty = 0;
		++src;
		while ((ch = *src++) != '\0' && isascii(ch) && isxdigit(ch)) {
			if (isupper(ch)) { ch = tolower(ch); }
			n = (int)(strchr(xdigits_l, ch) - xdigits_l);
			assert(n >= 0 && n <= 15);
			if (dirty == 0) { tmp = n; }
			else { tmp = (tmp << 4) | n; }
			if (++dirty == 2) {
				if (size-- <= 0U) { set_errno(EMSGSIZE); return -1; }
				*dst++ = (unsigned char)tmp;
				dirty = 0;
			}
		}
		if (dirty) {  // Odd trailing nibble
			if (size-- <= 0U) { set_errno(EMSGSIZE); return -1; }
			*dst++ = (unsigned char)(tmp << 4);
		}
	} else if (isascii(ch) && isdigit(ch)) {  // Decimal: eat dotted digit string
		loop_forever {
			tmp = 0;
			do {
				n = (int)(strchr(digits, ch) - digits);
				assert(n >= 0 && n <= 9);
				tmp *= 10;
				tmp += n;
				if (tmp > 255) { set_errno(ENOENT); return -1; }
			} while ((ch = *src++) != '\0' && isascii(ch) && isdigit(ch));
			if (size-- <= 0U) { set_errno(EMSGSIZE); return -1; }
			*dst++ = (unsigned char)tmp;
			if (ch == '\0' || ch == '/') { break; }
			else if (ch != '.') { set_errno(ENOENT); return -1; }
			ch = *src++;
			if ((!isascii(ch)) || (!isdigit(ch))) { set_errno(ENOENT); return -1; }
		}
	}
	bits = -1;
	if (ch == '/' && isascii((unsigned char)(src[0])) &&
		isdigit((unsigned char)(src[0])) && dst > odst) {  // CIDR width specifier; Nothing can follow it
		ch = *src++;
		bits = 0;
		do {
			n = (int)(strchr(digits, ch) - digits);
			assert(n >= 0 && n <= 9);
			bits *= 10;
			bits += n;
			if (bits > 32) { set_errno(ENOENT); return -1; }
		} while ((ch = *src++) != '\0' && isascii(ch) && isdigit(ch));
		if (ch != '\0') { set_errno(ENOENT); return -1; }
	}
	if (ch != '\0') { set_errno(ENOENT); return -1; }
	else if (dst == odst) { set_errno(ENOENT); return -1; }  // If nothing was written to the destination, no was found address
	else if (bits == -1) {  // If no CIDR spec was given, infer width from net class
		if (*odst >= 240) { bits = 32; }  // Class E
		else if (*odst >= 224) { bits = 8; }  // Class D
		else if (*odst >= 192) { bits = 24; }  // Class C
		else if (*odst >= 128) { bits = 16; }  // Class B
		else { bits = 8; }  // Class A
		if (bits < ((dst - odst) * 8)) { bits = (int)((dst - odst) * 8); }
		if (bits == 8 && *odst == 224) { bits = 4; }  // If there are no additional bits specified for a class D address, then adjust bits to 4
	}
	while (bits > ((dst - odst) * 8)) {  // Extend network to cover the actual mask
		if (size-- <= 0U) { set_errno(EMSGSIZE); return -1; }
		*dst++ = '\0';
	}
	return bits;
}


LIB_FUNC int getbits(const char* src, int* bitsp) {
	register int n = 0, val = 0;
	char ch;
	while ((ch = *src++) != '\0') {
		const char* pch = strchr(digits, ch);
		if (pch != NULL) {
			if (n++ != 0 && val == 0) { return 0; }
			val = (val * 10) + (int)(pch - digits);
			if (val > 128) { return 0; }
			continue;
		}
		return 0;
	}
	if (n == 0) { return 0; }
	*bitsp = val;
	return 1;
}


LIB_FUNC int getv4(const char* src, unsigned char* dst, int* bitsp) {
	unsigned char* odst = dst;
	register int n = 0;
	unsigned int val = 0;
	char ch;
	while ((ch = *src++) != '\0') {
		const char* pch = strchr(digits, ch);
		if (pch != NULL) {
			if (n++ != 0 && val == 0) { return 0; }
			val = (val * 10) + (unsigned int)(pch - digits);
			if (val > 255) { return 0; }
			continue;
		}
		if (ch == '.' || ch == '/') {
			if (dst - odst > 3) { return 0; }
			*dst++ = (unsigned char)val;
			if (ch == '/') { return getbits(src, bitsp); }
			val = 0;
			n = 0;
			continue;
		}
		return 0;
	}
	if (n == 0) { return 0; }
	else if ((dst - odst) > 3) { return 0; }
	else { *dst++ = (unsigned char)val; return 1; }
	UNREACHABLE
}


LIB_FUNC int inet_net_pton_ipv6(const char* src, unsigned char* dst, const size_t size) {
	unsigned char tmp[NS_IN6ADDRSZ] = { 0 }, *tp, *endp, *colonp;
	const char* xdigits;
	int ch, words, ipv4, saw_xdigit = 0, digits = 0, bits = -1;
	unsigned int val = 0;
	memset((tp = tmp), '\0', NS_IN6ADDRSZ);
	endp = tp + NS_IN6ADDRSZ;
	colonp = NULL;
	if (*src == ':' && (*++src != ':')) { set_errno(ENOENT); return -1; }  // Leading :: requires some special handling
	const char* curtok = src;
	saw_xdigit = 0;
	ipv4 = 0;
	while ((ch = *src++) != '\0') {
		const char* pch;
		if ((pch = strchr((xdigits = xdigits_l), ch)) == NULL) { pch = strchr((xdigits = xdigits_u), ch); }
		if (pch != NULL) {
			val <<= 4;
			val |= (unsigned int)(pch - xdigits);
			if (++digits > 4) { set_errno(ENOENT); return -1; }
			saw_xdigit = 1;
			continue;
		} else if (ch == ':') {
			curtok = src;
			if (!saw_xdigit) {
				if (colonp) { set_errno(ENOENT); return -1; }
				colonp = tp;
				continue;
			} else if (*src == '\0') { set_errno(ENOENT); return -1; }
			else if (tp + NS_INT16SZ > endp) { return 0; }
			*tp++ = (unsigned char)((val >> 8) & 0xff);
			*tp++ = (unsigned char)(val & 0xff);
			saw_xdigit = 0;
			digits = 0;
			val = 0;
			continue;
		} else if (ch == '.' && ((tp + NS_INADDRSZ) <= endp) && getv4(curtok, tp, &bits) > 0) {
			tp += NS_INADDRSZ;
			saw_xdigit = 0;
			ipv4 = 1;
			break;
		} else if (ch == '/' && getbits(src, &bits) > 0) { break; }
		set_errno(ENOENT);
		return -1;
	}
	if (saw_xdigit) {
		if (tp + NS_INT16SZ > endp) { set_errno(ENOENT); return -1; }
		*tp++ = (unsigned char)((val >> 8) & 0xff);
		*tp++ = (unsigned char)(val & 0xff);
	}
	if (bits == -1) { bits = 128; }
	words = (bits + 15) / 16;
	if (words < 2) { words = 2; }
	if (ipv4) { words = 8; }
	endp = (tmp + (words + words));
	if (colonp != NULL) {  // Shift by hand (because memmove cannot handle overlapping regions)
		if (tp == endp) { set_errno(ENOENT); return -1; }
		register int i, for_n = (int)(tp - colonp);
		for (i = 1; i <= for_n; i++) {
			endp[- i] = colonp[for_n - i];
			colonp[for_n - i] = 0;
		}
		tp = endp;
	}
	if (tp != endp) { set_errno(ENOENT); return -1; }
	const size_t bytes = (size_t)((bits + 7) / 8);
	if (bytes > size) { set_errno(EMSGSIZE); return -1; }
	memcpy_no_output(dst, tmp, bytes);
	return bits;
}


/** Convert network number from presentation to network format; accepts hex octets, hex strings, decimal octets, and CIDR */
LIB_FUNC int inet_net_pton(const int af, const char* src, void* dst, const size_t size) {
	switch (af) {
		case AF_INET:
			return inet_net_pton_ipv4(src, dst, size);
		case AF_INET6:
			return inet_net_pton_ipv6(src, dst, size);
		default:
			set_errno(EAFNOSUPPORT);
			return -1;
	}
	UNREACHABLE
}
#define __inet_net_pton(af, src, dst, size)   inet_net_pton((af), (src), (dst), (size))


#endif  // ARPA_INET_H


/* FTP (<arpa/ftp.h>) */


#if (!(defined(ARPA_FTP_H) || defined(_ARPA_FTP_H) || defined(_ARPA_FTP_H_)))
#define ARPA_FTP_H   (1)
#define _ARPA_FTP_H   (1)
#define _ARPA_FTP_H_   (1)


#define PRELIM   1
#define COMPLETE   2
#define CONTINUE   3
#define TRANSIENT   4
#define ERROR   5
#define TYPE_A   1
#define TYPE_E   2
#define TYPE_I   3
#define TYPE_L   4
#define FORM_N   1
#define FORM_T   2
#define FORM_C   3
#define STRU_F   1
#define STRU_R   2
#define STRU_P   3
#define MODE_S   1
#define MODE_B   2
#define MODE_C   3
#define REC_ESC   '\377'
#define REC_EOR   '\001'
#define REC_EOF   '\002'
#define BLK_EOR   0x80
#define BLK_EOF   0x40
#define BLK_ERRORS   0x20
#define BLK_RESTART   0x10
#define BLK_BYTECOUNT   2
#ifdef FTP_NAMES
static const UNUSED char* modenames[4][16] = { "0", "Stream", "Block", "Compressed" };
static const UNUSED char* strunames[4][8] = { "0", "File", "Record", "Page" };
static const UNUSED char* typenames[8][8] = { "0", "ASCII", "EBCDIC", "Image", "Local" };
static const UNUSED char* formnames[4][32] = { "0", "Nonprint", "Telnet", "Carriage-control" };
#endif


#endif  // ARPA_FTP_H


/* ICMP6 (<netinet/icmp6.h>) */


#if (!(defined(NETINET_ICMP6_H) || defined(_NETINET_ICMP6_H) || defined(_NETINET_ICMP6_H_)))
#define NETINET_ICMP6_H   (1)
#define _NETINET_ICMP6_H   (1)
#define _NETINET_ICMP6_H_   (1)


#define RPM_PCO_ADD   1
#define RPM_PCO_CHANGE   2
#define RPM_PCO_SETGLOBAL   3
#define MLD_LISTENER_QUERY   130
#define MLD_LISTENER_REPORT   131
#define MLD_LISTENER_REDUCTION   132
#if IS_BIG_ENDIAN
#   define ICMP6_RR_PCOUSE_FLAGS_DECRVLTIME   0x80000000
#   define ICMP6_RR_PCOUSE_FLAGS_DECRPLTIME   0x40000000
#   define ICMP6_RR_RESULT_FLAGS_OOB   2
#   define ICMP6_RR_RESULT_FLAGS_FORBIDDEN   1
#else
#   define ICMP6_RR_PCOUSE_FLAGS_DECRVLTIME   0x80
#   define ICMP6_RR_PCOUSE_FLAGS_DECRPLTIME   0x40
#   define ICMP6_RR_RESULT_FLAGS_OOB   0x200
#   define ICMP6_RR_RESULT_FLAGS_FORBIDDEN   0x100
#endif
#define ICMP6_FILTER   1
#define ICMP6_FILTER_BLOCK   1
#define ICMP6_FILTER_PASS   2
#define ICMP6_FILTER_BLOCKOTHERS   3
#define ICMP6_FILTER_PASSONLY   4
#define ICMP6_DST_UNREACH   1
#define ICMP6_PACKET_TOO_BIG   2
#define ICMP6_TIME_EXCEEDED   3
#define ICMP6_PARAM_PROB   4
#define ICMP6_INFOMSG_MASK   0x80
#define ICMP6_ECHO_REQUEST   128
#define ICMP6_ECHO_REPLY   129
#define ICMP6_RR_PCOUSE_RAFLAGS_ONLINK   0x20
#define ICMP6_RR_PCOUSE_RAFLAGS_AUTO   0x10
#define ICMP6_ROUTER_RENUMBERING   138
#define ICMP6_RR_FLAGS_TEST   0x80
#define ICMP6_RR_FLAGS_REQRESULT   0x40
#define ICMP6_RR_FLAGS_FORCEAPPLY   0x20
#define ICMP6_RR_FLAGS_SPECSITE   0x10
#define ICMP6_RR_FLAGS_PREVDONE   8
#define ICMP6_DST_UNREACH_NOROUTE   0
#define ICMP6_DST_UNREACH_ADMIN   1
#define ICMP6_DST_UNREACH_BEYONDSCOPE   2
#define ICMP6_DST_UNREACH_ADDR   3
#define ICMP6_DST_UNREACH_NOPORT   4
#define ICMP6_TIME_EXCEED_TRANSIT   0
#define ICMP6_TIME_EXCEED_REASSEMBLY   1
#define ICMP6_PARAMPROB_HEADER   0
#define ICMP6_PARAMPROB_NEXTHEADER   1
#define ICMP6_PARAMPROB_OPTION   2
#if IS_BIG_ENDIAN
#   define ND_NA_FLAG_ROUTER   0x80000000
#   define ND_NA_FLAG_SOLICITED   0x40000000
#   define ND_NA_FLAG_OVERRIDE   0x20000000
#else
#   define ND_NA_FLAG_ROUTER   0x80
#   define ND_NA_FLAG_SOLICITED   0x40
#   define ND_NA_FLAG_OVERRIDE   0x20
#endif
#define ND_ROUTER_SOLICIT   133
#define ND_ROUTER_ADVERT   134
#define ND_NEIGHBOR_SOLICIT   135
#define ND_NEIGHBOR_ADVERT   136
#define ND_REDIRECT   137
#define ND_RA_FLAG_MANAGED   0x80
#define ND_RA_FLAG_OTHER   0x40
#define ND_RA_FLAG_HOME_AGENT   0x20
#define ND_OPT_SOURCE_LINKADDR   1
#define ND_OPT_TARGET_LINKADDR   2
#define ND_OPT_PREFIX_INFORMATION   3
#define ND_OPT_REDIRECTED_HEADER   4
#define ND_OPT_MTU   5
#define ND_OPT_RTR_ADV_INTERVAL   7
#define ND_OPT_HOME_AGENT_INFO   8
#define ND_OPT_PI_FLAG_ONLINK   0x80
#define ND_OPT_PI_FLAG_AUTO   0x40
#define ND_OPT_PI_FLAG_RADDR   0x20


typedef struct icmp6_filter { uint32_t icmp6_filt[8]; }   icmp6_filter_t;


#define ICMP6_FILTER_WILLPASS(type, filterp)   ((((filterp)->icmp6_filt[(type) >> 5]) & (1 << ((type) & 31))) == 0)
#define ICMP6_FILTER_WILLBLOCK(type, filterp)   ((((filterp)->icmp6_filt[(type) >> 5]) & (1 << ((type) & 31))) != 0)
#define ICMP6_FILTER_SETPASS(type, filterp)   ((((filterp)->icmp6_filt[(type) >> 5]) &= (~(1 << ((type) & 31)))))
#define ICMP6_FILTER_SETBLOCK(type, filterp)   ((((filterp)->icmp6_filt[(type) >> 5]) |= (1 << ((type) & 31))))
#define ICMP6_FILTER_SETPASSALL(filterp)   memset(filterp, 0, sizeof(struct icmp6_filter));
#define ICMP6_FILTER_SETBLOCKALL(filterp)   memset(filterp, 0xff, sizeof(struct icmp6_filter));


typedef struct icmp6_hdr {
	uint8_t icmp6_type, icmp6_code;
	uint16_t icmp6_cksum;
	union _icmp6_dataun {
		uint32_t icmp6_un_data32[1];
		uint16_t icmp6_un_data16[2];
		uint8_t icmp6_un_data8[4];
	} icmp6_dataun;
} icmp6_hdr_t;
#define icmp6_data32   icmp6_dataun.icmp6_un_data32
#define icmp6_data16   icmp6_dataun.icmp6_un_data16
#define icmp6_data8   icmp6_dataun.icmp6_un_data8
#define icmp6_pptr   icmp6_data32[0]
#define icmp6_mtu   icmp6_data32[0]
#define icmp6_id   icmp6_data16[0]
#define icmp6_seq   icmp6_data16[1]
#define icmp6_maxdelay   icmp6_data16[0]


typedef struct nd_router_solicit { struct icmp6_hdr nd_rs_hdr; }   nd_router_solicit_t;
#define nd_rs_type   nd_rs_hdr.icmp6_type
#define nd_rs_code   nd_rs_hdr.icmp6_code
#define nd_rs_cksum   nd_rs_hdr.icmp6_cksum
#define nd_rs_reserved   nd_rs_hdr.icmp6_data32[0]


typedef struct nd_router_advert {
	struct icmp6_hdr nd_ra_hdr;
	uint32_t nd_ra_reachable, nd_ra_retransmit;
} nd_router_advert_t;
#define nd_ra_type   nd_ra_hdr.icmp6_type
#define nd_ra_code   nd_ra_hdr.icmp6_code
#define nd_ra_cksum   nd_ra_hdr.icmp6_cksum
#define nd_ra_curhoplimit   nd_ra_hdr.icmp6_data8[0]
#define nd_ra_flags_reserved   nd_ra_hdr.icmp6_data8[1]
#define nd_ra_router_lifetime   nd_ra_hdr.icmp6_data16[1]


typedef struct nd_neighbor_solicit {
	struct icmp6_hdr nd_ns_hdr;
	struct in6_addr nd_ns_target;
} nd_neighbor_solicit_t;
#define nd_ns_type   nd_ns_hdr.icmp6_type
#define nd_ns_code   nd_ns_hdr.icmp6_code
#define nd_ns_cksum   nd_ns_hdr.icmp6_cksum
#define nd_ns_reserved   nd_ns_hdr.icmp6_data32[0]


typedef struct nd_neighbor_advert {
	struct icmp6_hdr nd_na_hdr;
	struct in6_addr nd_na_target;
} nd_neighbor_advert_t;
#define nd_na_type   nd_na_hdr.icmp6_type
#define nd_na_code   nd_na_hdr.icmp6_code
#define nd_na_cksum   nd_na_hdr.icmp6_cksum
#define nd_na_flags_reserved     nd_na_hdr.icmp6_data32[0]


typedef struct nd_redirect {
	struct icmp6_hdr nd_rd_hdr;
	struct in6_addr nd_rd_target, nd_rd_dst;
} nd_redirect_t;
#define nd_rd_type   nd_rd_hdr.icmp6_type
#define nd_rd_code   nd_rd_hdr.icmp6_code
#define nd_rd_cksum   nd_rd_hdr.icmp6_cksum
#define nd_rd_reserved   nd_rd_hdr.icmp6_data32[0]


typedef struct nd_opt_hdr { uint8_t nd_opt_type, nd_opt_len; }   nd_opt_hdr_t;


typedef struct nd_opt_prefix_info {
	uint8_t nd_opt_pi_type, nd_opt_pi_len, nd_opt_pi_prefix_len, nd_opt_pi_flags_reserved;
	uint32_t nd_opt_pi_valid_time, nd_opt_pi_preferred_time, nd_opt_pi_reserved2;
	struct in6_addr nd_opt_pi_prefix;
} nd_opt_prefix_info_t;


typedef struct nd_opt_rd_hdr {
	uint8_t nd_opt_rh_type, nd_opt_rh_len;
	uint16_t nd_opt_rh_reserved1;
	uint32_t nd_opt_rh_reserved2;
} nd_opt_rd_hdr_t;


typedef struct nd_opt_mtu {
	uint8_t nd_opt_mtu_type, nd_opt_mtu_len;
	uint16_t nd_opt_mtu_reserved;
	uint32_t nd_opt_mtu_mtu;
} nd_opt_mtu_t;


typedef struct mld_hdr { struct icmp6_hdr mld_icmp6_hdr; struct in6_addr mld_addr; }   mld_hdr_t;
#define mld_type   mld_icmp6_hdr.icmp6_type
#define mld_code   mld_icmp6_hdr.icmp6_code
#define mld_cksum   mld_icmp6_hdr.icmp6_cksum
#define mld_maxdelay   mld_icmp6_hdr.icmp6_data16[0]
#define mld_reserved   mld_icmp6_hdr.icmp6_data16[1]


typedef struct icmp6_router_renum {
	struct icmp6_hdr rr_hdr;
	uint8_t rr_segnum, rr_flags;
	uint16_t rr_maxdelay;
	uint32_t rr_reserved;
} icmp6_router_renum_t;
#define rr_type   rr_hdr.icmp6_type
#define rr_code   rr_hdr.icmp6_code
#define rr_cksum   rr_hdr.icmp6_cksum
#define rr_seqnum   rr_hdr.icmp6_data32[0]


typedef struct rr_pco_match {
	uint8_t rpm_code, rpm_len, rpm_ordinal, rpm_matchlen, rpm_minlen, rpm_maxlen;
	uint16_t rpm_reserved;
	struct in6_addr rpm_prefix;
} rr_pco_match_t;


typedef struct rr_pco_use {
	uint8_t rpu_uselen, rpu_keeplen, rpu_ramask, rpu_raflags;
	uint32_t rpu_vltime, rpu_pltime, rpu_flags;
	struct in6_addr rpu_prefix;
} rr_pco_use_t;


typedef struct rr_result {
	uint16_t rrr_flags;
	uint8_t rrr_ordinal, rrr_matchedlen;
	uint32_t rrr_ifid;
	struct in6_addr rrr_prefix;
} rr_result_t;


typedef struct nd_opt_adv_interval {
	uint8_t nd_opt_adv_interval_type, nd_opt_adv_interval_len;
	uint16_t nd_opt_adv_interval_reserved;
	uint32_t nd_opt_adv_interval_ival;
} nd_opt_adv_interval_t;


typedef struct nd_opt_home_agent_info {
	uint8_t nd_opt_home_agent_info_type, nd_opt_home_agent_info_len;
	uint16_t nd_opt_home_agent_info_reserved, nd_opt_home_agent_info_preference, nd_opt_home_agent_info_lifetime;
} nd_opt_home_agent_info_t;


#endif  // NETINET_ICMP6_H


/* PPP/P2P: POINT-TO-POINT PROTOCOL (<ppp.h>) */


#if (!(defined(PPP_DEFS_H) || defined(_PPP_DEFS_H) || defined(_PPP_DEFS_H_)))
#define PPP_DEFS_H   (1)
#define _PPP_DEFS_H   (1)
#define _PPP_DEFS_H_   (1)


#define PPP_ADDRESS(p)   (((unsigned char*)(p))[0])
#define PPP_CONTROL(p)   (((unsigned char*)(p))[1])
#define PPP_PROTOCOL(p)   ((((unsigned char*)(p))[2] << 8) + ((unsigned char*)(p))[3])
// Basic PPP frame
/** Octets for standard ppp header */
#define PPP_HDRLEN   4
/** Octets for FCS */
#define PPP_FCSLEN   2
/** Default MRU = max length of info field */
#define PPP_MRU   1500
// Significant octet values
/** All-Stations broadcast address */
#define PPP_ALLSTATIONS   0xff
/** Unnumbered Information */
#define PPP_UI   3
/** Flag Sequence */
#define PPP_FLAG   0x7e
/** Asynchronous Control Escape */
#define PPP_ESCAPE   0x7d
/** Asynchronous transparency modifier */
#define PPP_TRANS   0x20
// Protocol field values
/** Internet Protocol */
#define PPP_IP   0x21
/** Xerox NS */
#define PPP_XNS   0x25
/** AppleTalk Protocol */
#define PPP_AT   0x29
/** IPX Datagram (RFC1552) */
#define PPP_IPX   0x2b
/** VJ compressed TCP */
#define PPP_VJC_COMP   0x2d
/** VJ uncompressed TCP */
#define PPP_VJC_UNCOMP   0x2f
/** Compressed packet */
#define PPP_COMP   0xfd
/** IP Control Protocol */
#define PPP_IPCP   0x8021
/** AppleTalk Control Protocol */
#define PPP_ATCP   0x8029
/** IPX Control Protocol (RFC1552) */
#define PPP_IPXCP   0x802b
/** Compression Control Protocol */
#define PPP_CCP   0x80fd
/** Link Control Protocol */
#define PPP_LCP   0xc021
/** Password Authentication Protocol */
#define PPP_PAP   0xc023
/** Link Quality Report protocol */
#define PPP_LQR   0xc025
/** Cryptographic Handshake Authentication Protocol */
#define PPP_CHAP   0xc223
/** Callback Control Protocol */
#define PPP_CBCP   0xc029
/** Internet Protocol version 6*/
#define PPP_IPV6   0x57
/** IPv6 Control Protocol */
#define PPP_IPV6CP   0x8057
// Values for FCS calculations
/** Initial FCS value */
#define PPP_INITFCS   0xffff
/** Good final FCS value */
#define PPP_GOODFCS   0xf0b8


/** Calculate FCS; RFC1331 */
static const UNUSED unsigned short fcstab[256] = {
	0, 0x1189, 0x2312, 0x329b, 0x4624, 0x57ad, 0x6536, 0x74bf,
	0x8c48, 0x9dc1, 0xaf5a, 0xbed3, 0xca6c, 0xdbe5, 0xe97e, 0xf8f7,
	0x1081, 0x0108, 0x3393, 0x221a, 0x56a5, 0x472c, 0x75b7, 0x643e,
	0x9cc9, 0x8d40, 0xbfdb, 0xae52, 0xdaed, 0xcb64, 0xf9ff, 0xe876,
	0x2102, 0x308b, 0x0210, 0x1399, 0x6726, 0x76af, 0x4434, 0x55bd,
	0xad4a, 0xbcc3, 0x8e58, 0x9fd1, 0xeb6e, 0xfae7, 0xc87c, 0xd9f5,
	0x3183, 0x200a, 0x1291, 0x0318, 0x77a7, 0x662e, 0x54b5, 0x453c,
	0xbdcb, 0xac42, 0x9ed9, 0x8f50, 0xfbef, 0xea66, 0xd8fd, 0xc974,
	0x4204, 0x538d, 0x6116, 0x709f, 0x0420, 0x15a9, 0x2732, 0x36bb,
	0xce4c, 0xdfc5, 0xed5e, 0xfcd7, 0x8868, 0x99e1, 0xab7a, 0xbaf3,
	0x5285, 0x430c, 0x7197, 0x601e, 0x14a1, 0x0528, 0x37b3, 0x263a,
	0xdecd, 0xcf44, 0xfddf, 0xec56, 0x98e9, 0x8960, 0xbbfb, 0xaa72,
	0x6306, 0x728f, 0x4014, 0x519d, 0x2522, 0x34ab, 0x0630, 0x17b9,
	0xef4e, 0xfec7, 0xcc5c, 0xddd5, 0xa96a, 0xb8e3, 0x8a78, 0x9bf1,
	0x7387, 0x620e, 0x5095, 0x411c, 0x35a3, 0x242a, 0x16b1, 0x0738,
	0xffcf, 0xee46, 0xdcdd, 0xcd54, 0xb9eb, 0xa862, 0x9af9, 0x8b70,
	0x8408, 0x9581, 0xa71a, 0xb693, 0xc22c, 0xd3a5, 0xe13e, 0xf0b7,
	0x0840, 0x19c9, 0x2b52, 0x3adb, 0x4e64, 0x5fed, 0x6d76, 0x7cff,
	0x9489, 0x8500, 0xb79b, 0xa612, 0xd2ad, 0xc324, 0xf1bf, 0xe036,
	0x18c1, 0x0948, 0x3bd3, 0x2a5a, 0x5ee5, 0x4f6c, 0x7df7, 0x6c7e,
	0xa50a, 0xb483, 0x8618, 0x9791, 0xe32e, 0xf2a7, 0xc03c, 0xd1b5,
	0x2942, 0x38cb, 0x0a50, 0x1bd9, 0x6f66, 0x7eef, 0x4c74, 0x5dfd,
	0xb58b, 0xa402, 0x9699, 0x8710, 0xf3af, 0xe226, 0xd0bd, 0xc134,
	0x39c3, 0x284a, 0x1ad1, 0x0b58, 0x7fe7, 0x6e6e, 0x5cf5, 0x4d7c,
	0xc60c, 0xd785, 0xe51e, 0xf497, 0x8028, 0x91a1, 0xa33a, 0xb2b3,
	0x4a44, 0x5bcd, 0x6956, 0x78df, 0x0c60, 0x1de9, 0x2f72, 0x3efb,
	0xd68d, 0xc704, 0xf59f, 0xe416, 0x90a9, 0x8120, 0xb3bb, 0xa232,
	0x5ac5, 0x4b4c, 0x79d7, 0x685e, 0x1ce1, 0x0d68, 0x3ff3, 0x2e7a,
	0xe70e, 0xf687, 0xc41c, 0xd595, 0xa12a, 0xb0a3, 0x8238, 0x93b1,
	0x6b46, 0x7acf, 0x4854, 0x59dd, 0x2d62, 0x3ceb, 0x0e70, 0x1ff9,
	0xf78f, 0xe606, 0xd49d, 0xc514, 0xb1ab, 0xa022, 0x92b9, 0x8330,
	0x7bc7, 0x6a4e, 0x58d5, 0x495c, 0x3de3, 0x2c6a, 0x1ef1, 0x0f78
};


static const UNUSED char* snames[8] = {
	"Sclosed", "Sclosing", "Sreqsent", "Sackrcvd", "Sacksent", "Sopened"
};


#define PPP_FCS(fcs, c)   (((fcs) >> 8) ^ fcstab[((fcs) ^ (c)) & 0xff])
/** Extended asyncmap - allows any character to be escaped */
typedef uint32_t   ext_accm[8];


enum NPmode {
	NPMODE_PASS,  //!< Pass the packet through
	NPMODE_DROP,  //!< Silently drop the packet
	NPMODE_ERROR,  //!< Return an error
	NPMODE_QUEUE  //!< Save it up for later
};


typedef struct pppstat {
	unsigned int ppp_ibytes;  //!< Bytes received
	unsigned int ppp_ipackets;  //!< Packets received
	unsigned int ppp_ierrors;  //!< Receive errors
	unsigned int ppp_obytes;  //!< Bytes sent
	unsigned int ppp_opackets;  //!< Packets sent
	unsigned int ppp_oerrors;  //!< Transmit errors
} pppstat_t;


typedef struct vjstat {
	unsigned int vjs_packets;  //!< Outbound packets
	unsigned int vjs_compressed;  //!< Outbound compressed packets
	unsigned int vjs_searches;  //!< Searches for connection state
	unsigned int vjs_misses;  //!< Times could not find conn. state
	unsigned int vjs_uncompressedin;  //!< Inbound uncompressed packets
	unsigned int vjs_compressedin;  //!< Inbound compressed packets
	unsigned int vjs_errorin;  //!< Inbound unknown type packets
	unsigned int vjs_tossed;  //!< Inbound packets tossed because of error
} vjstat_t;


typedef struct ppp_stats {
	struct pppstat p;  //!< Basic PPP statistics
	struct vjstat vj;  //!< VJ header compression statistics
} ppp_stats_t;


typedef struct compstat {
	unsigned int unc_bytes;  //!< Total uncompressed bytes
	unsigned int unc_packets;  //!< Total uncompressed packets
	unsigned int comp_bytes;  //!< Compressed bytes
	unsigned int comp_packets;  //!< Compressed packets
	unsigned int inc_bytes;  //!< Incompressible bytes
	unsigned int inc_packets;  //!< Incompressible packets
	unsigned int ratio;  //!< Recent compression ratio << 8
} compstat_t;


typedef struct ppp_comp_stats {
	struct compstat c;  //!< Packet compression statistics
	struct compstat d;  //!< Packet decompression statistics
} ppp_comp_stats_t;


/** Records the time in seconds since the last NP packet was sent or received */
typedef struct ppp_idle {
	time_t xmit_idle;  //!< Time since last NP packet sent
	time_t recv_idle;  //!< Time since last NP packet received
} ppp_idle_t;


#endif  // PPP_DEFS_H


/* TCP: INTERNET TRANSMISSION CONTROL PROTOCOL (<netinet/tcp.h>) */


#if (!(defined(NETINET_TCP_H) || defined(_NETINET_TCP_H) || defined(_NETINET_TCP_H_)))  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/netinet_tcp.h.html
#define NETINET_TCP_H   (1)
#define _NETINET_TCP_H   (1)
#define _NETINET_TCP_H_   (1)


/** Avoid coalescing of small segments */
#define TCP_NODELAY   1
#define TCP_MAXSEG   2
#define TCP_CORK   3
#define TCP_KEEPIDLE   4
#define TCP_KEEPINTVL   5
#define TCP_KEEPCNT   6
#define TCP_SYNCNT   7
#define TCP_LINGER2   8
#define TCP_DEFER_ACCEPT   9
#define TCP_WINDOW_CLAMP   10
#define TCP_INFO   11
#define TCP_QUICKACK   12
#define TCP_CONGESTION   13
#define TCP_MD5SIG   14
#define TCP_THIN_LINEAR_TIMEOUTS   16
#define TCP_THIN_DUPACK   17
#define TCP_USER_TIMEOUT   18
#define TCP_REPAIR   19
#define TCP_REPAIR_QUEUE   20
#define TCP_QUEUE_SEQ   21
#define TCP_REPAIR_OPTIONS   22
#define TCP_FASTOPEN   23
#define TCP_TIMESTAMP   24
#define TCP_NOTSENT_LOWAT   25
#define TCP_CC_INFO   26
#define TCP_SAVE_SYN   27
#define TCP_SAVED_SYN   28
#define TCP_ESTABLISHED   1
#define TCP_SYN_SENT   2
#define TCP_SYN_RECV   3
#define TCP_FIN_WAIT1   4
#define TCP_FIN_WAIT2   5
#define TCP_TIME_WAIT   6
#define TCP_CLOSE   7
#define TCP_CLOSE_WAIT   8
#define TCP_LAST_ACK   9
#define TCP_LISTEN   10
#define TCP_CLOSING   11
#define TCPOPT_EOL   0
#define TCPOPT_NOP   1
#define TCPOPT_MAXSEG   2
#define TCPOPT_WINDOW   3
#define TCPOPT_SACK_PERMITTED   4
#define TCPOPT_SACK   5
#define TCPOPT_TIMESTAMP   8
#define TCPOLEN_SACK_PERMITTED   2
#define TCPOLEN_WINDOW   3
#define TCPOLEN_MAXSEG   4
#define TCPOLEN_TIMESTAMP   10
#define SOL_TCP   6
#define TH_FIN   1
#define TH_SYN   2
#define TH_RST   4
#define TH_PUSH   8
#define TH_ACK   0x10
#define TH_URG   0x20
#define TCPI_OPT_TIMESTAMPS   1
#define TCPI_OPT_SACK   2
#define TCPI_OPT_WSCALE   4
#define TCPI_OPT_ECN   8
#define TCP_CA_Open   0
#define TCP_CA_Disorder   1
#define TCP_CA_CWR   2
#define TCP_CA_Recovery   3
#define TCP_CA_Loss   4
#define TCP_MD5SIG_MAXKEYLEN   80


typedef uint32_t   tcp_seq;


typedef struct tcphdr {
#ifdef _GNU_SOURCE
#   if IS_GNUC
	__extension__
#   endif
	union __union_tcphdr { struct {
		uint16_t source, dest;
		uint32_t seq, ack_seq;
#   if IS_LITTLE_ENDIAN
		uint16_t res1:4;
		uint16_t doff:4;
		uint16_t fin:1;
		uint16_t syn:1;
		uint16_t rst:1;
		uint16_t psh:1;
		uint16_t ack:1;
		uint16_t urg:1;
		uint16_t res2:2;
#   else
		uint16_t doff:4;
		uint16_t res1:4;
		uint16_t res2:2;
		uint16_t urg:1;
		uint16_t ack:1;
		uint16_t psh:1;
		uint16_t rst:1;
		uint16_t syn:1;
		uint16_t fin:1;
#   endif
		uint16_t window, check, urg_ptr;
	};
	struct {
#endif
		uint16_t th_sport, th_dport;
		uint32_t th_seq, th_ack;
#   if IS_LITTLE_ENDIAN
		uint8_t th_x2:4;
		uint8_t th_off:4;
#   else
		uint8_t th_off:4;
		uint8_t th_x2:4;
#   endif
		uint8_t th_flags;
		uint16_t th_win, th_sum, th_urp;
#   ifdef _GNU_SOURCE
	}; } tcphdr_union;
#   endif
} tcphdr_t;


typedef struct attr_packed tcp_info {
	uint8_t tcpi_state, tcpi_ca_state;
	uint8_t tcpi_retransmits, tcpi_probes, tcpi_backoff, tcpi_options;
	uint8_t tcpi_snd_wscale:4, tcpi_rcv_wscale:4;
	uint32_t tcpi_rto, tcpi_ato, tcpi_snd_mss;
	uint32_t tcpi_rcv_mss, tcpi_unacked, tcpi_sacked;
	uint32_t tcpi_lost, tcpi_retrans, tcpi_fackets;
	uint32_t tcpi_last_data_sent, tcpi_last_ack_sent, tcpi_last_data_recv;
	uint32_t tcpi_last_ack_recv, tcpi_pmtu, tcpi_rcv_ssthresh;
	uint32_t tcpi_rtt, tcpi_rttvar, tcpi_snd_ssthresh;
	uint32_t tcpi_snd_cwnd, tcpi_advmss, tcpi_reordering;
	uint32_t tcpi_rcv_rtt, tcpi_rcv_space, tcpi_total_retrans;
	uint64_t tcpi_pacing_rate, tcpi_max_pacing_rate, tcpi_bytes_acked, tcpi_bytes_received;
	uint32_t tcpi_segs_out, tcpi_segs_in;
} tcp_info_t;


typedef struct attr_packed tcp_md5sig {
	struct sockaddr_storage tcpm_addr;
	uint16_t __tcpm_pad1, tcpm_keylen;
	uint32_t __tcpm_pad2;
	uint8_t tcpm_key[TCP_MD5SIG_MAXKEYLEN];
} tcp_md5sig_t;


#endif  // NETINET_TCP_H


/* TELNET <arpa/telnet.h> */


#if (!(defined(ARPA_TELNET_H) || defined(_ARPA_TELNET_H) || defined(_ARPA_TELNET_H_)))
#define ARPA_TELNET_H   (1)
#define _ARPA_TELNET_H   (1)
#define _ARPA_TELNET_H_   (1)


#define IAC   255
#define DONT   254
#define DO   253
#define WONT   252
#define WILL   251
#define SB   250
#define GA   249
#define EL   248
#define EC   247
#define AYT   246
#define AO   245
#define IP   244
#define BREAK   243
#define DM   242
#define NOP   241
#define SE   240
#define EOR   239
#define TELOPT_ABORT   238
#define TELNET_ABORT   238
#define SUSP   237
#define xEOF   236
#define SYNCH   242
#define telcmds   ((char [32][8]) { "EOF", "SUSP", "ABORT", "EOR", "SE", "NOP", "DMARK", "BRK", "IP", "AO", "AYT", "EC", "EL", "GA", "SB", "WILL", "WONT", "DO", "DONT", "IAC", "\0", "\0" })
#define TELCMD_FIRST   xEOF
#define TELCMD_LAST   IAC
#define TELCMD_OK(x)   ((unsigned int)(x) <= TELCMD_LAST && (unsigned int)(x) >= TELCMD_FIRST)
#define TELCMD(x)   telcmds[(x) - TELCMD_FIRST]
enum TELOPT_CODES {
	TELOPT_BINARY = 0,
	TELOPT_ECHO = 1,
	TELOPT_RCP = 2,
	TELOPT_SGA = 3,
	TELOPT_NAMS = 4,
	TELOPT_STATUS = 5,
	TELOPT_TM = 6,
	TELOPT_RCTE = 7,
	TELOPT_NAOL = 8,
	TELOPT_NAOP = 9,
	TELOPT_NAOCRD = 10,
	TELOPT_NAOHTS = 11,
	TELOPT_NAOHTD = 12,
	TELOPT_NAOFFD = 13,
	TELOPT_NAOVTS = 14,
	TELOPT_NAOVTD = 15,
	TELOPT_NAOLFD = 16,
	TELOPT_XASCII = 17,
	TELOPT_LOGOUT = 18,
	TELOPT_BM = 19,
	TELOPT_DET = 20,
	TELOPT_SUPDUP = 21,
	TELOPT_SUPDUPOUTPUT = 22,
	TELOPT_SNDLOC = 23,
	TELOPT_TTYPE = 24,
	TELOPT_EOR = 25,
	TELOPT_TUID = 26,
	TELOPT_OUTMRK = 27,
	TELOPT_TTYLOC = 28,
	TELOPT_3270REGIME = 29,
	TELOPT_X3PAD = 30,
	TELOPT_NAWS = 31,
	TELOPT_TSPEED = 32,
	TELOPT_LFLOW = 33,
	TELOPT_LINEMODE = 34,
	TELOPT_XDISPLOC = 35,
	TELOPT_OLD_ENVIRON = 36,
/** Authenticate */
	TELOPT_AUTHENTICATION = 37,
	TELOPT_ENCRYPT = 38,
	TELOPT_NEW_ENVIRON = 39,
	TELOPT_EXOPL = 255
};
#define NTELOPTS   (1 + TELOPT_NEW_ENVIRON)
#define TELQUAL_IS   0
#define TELQUAL_SEND   1
#define TELQUAL_INFO   2
#define TELQUAL_REPLY   2
#define TELQUAL_NAME   3
#define LFLOW_OFF   0
#define LFLOW_ON   1
#define LFLOW_RESTART_ANY   2
#define LFLOW_RESTART_XON   3
#define LM_MODE   1
#define LM_FORWARDMASK   2
#define LM_SLC   3
#define MODE_EDIT   1
#define MODE_TRAPSIG   2
#define MODE_ACK   4
#define MODE_SOFT_TAB   8
#define MODE_LIT_ECHO   0x10
#define MODE_MASK   0x1f
#define MODE_FLOW   0x100
#define MODE_ECHO   0x200
#define MODE_INBIN   0x400
#define MODE_OUTBIN   0x800
#define MODE_FORCE   0x1000
enum SLC_CODES {
	SLC_SYNCH = 1,
	SLC_BRK = 2,
	SLC_IP = 3,
	SLC_AO = 4,
	SLC_AYT = 5,
	SLC_EOR = 6,
	SLC_ABORT = 7,
	SLC_EOF = 8,
	SLC_SUSP = 9,
	SLC_EC = 10,
	SLC_EL = 11,
	SLC_EW = 12,
	SLC_RP = 13,
	SLC_LNEXT = 14,
	SLC_XON = 15,
	SLC_XOFF = 16,
	SLC_FORW1 = 17,
	SLC_FORW2 = 18
};
#define NSLC   18
#ifdef TELOPTS
static const UNUSED char* telopts[NTELOPTS + 1] = {
	"BINARY", "ECHO", "RCP", "SUPPRESS GO AHEAD", "NAME",
	"STATUS", "TIMING MARK", "RCTE", "NAOL", "NAOP",
	"NAOCRD", "NAOHTS", "NAOHTD", "NAOFFD", "NAOVTS",
	"NAOVTD", "NAOLFD", "EXTEND ASCII", "LOGOUT", "BYTE MACRO",
	"DATA ENTRY TERMINAL", "SUPDUP", "SUPDUP OUTPUT",
	"SEND LOCATION", "TERMINAL TYPE", "END OF RECORD",
	"TACACS UID", "OUTPUT MARKING", "TTYLOC",
	"3270 REGIME", "X.3 PAD", "NAWS", "TSPEED", "LFLOW",
	"LINEMODE", "XDISPLOC", "OLD-ENVIRON", "AUTHENTICATION", "ENCRYPT", "NEW-ENVIRON", 0
};
#   define TELOPT_FIRST   TELOPT_BINARY
#   define TELOPT_LAST   TELOPT_NEW_ENVIRON
#   define TELOPT_OK(x)   ((unsigned int)(x) <= TELOPT_LAST)
#   define TELOPT(x)   telopts[(x) - TELOPT_FIRST]
#endif
#define SLC_NAMELIST   "0", "SYNCH", "BRK", "IP", "AO", "AYT", "EOR", "ABORT", "EOF", "SUSP", "EC", "EL", "EW", "RP", "LNEXT", "XON", "XOFF", "FORW1", "FORW2", "\0"
static const UNUSED char* slc_names[32] = { SLC_NAMELIST };
#ifndef SLC_NAMES
#   define SLC_NAMES   SLC_NAMELIST
#endif
#define SLC_NAME_OK(x)   ((unsigned int)(x) <= NSLC)
#define SLC_NAME(x)   slc_names[x]
#define SLC_NOSUPPORT   0
#define SLC_CANTCHANGE   1
#define SLC_VARIABLE   2
#define SLC_DEFAULT   3
#define SLC_LEVELBITS   3
#define SLC_FUNC   0
#define SLC_FLAGS   1
#define SLC_VALUE   2
#define SLC_ACK   0x80
#define SLC_FLUSHIN   0x40
#define SLC_FLUSHOUT   0x20
#define OLD_ENV_VAR   1
#define OLD_ENV_VALUE   0
#define NEW_ENV_VAR   0
#define NEW_ENV_VALUE   1
#define ENV_ESC   2
#define ENV_USERVAR   3
#define AUTH_WHO_CLIENT   0
#define AUTH_WHO_SERVER   1
#define AUTH_WHO_MASK   1
#define AUTH_HOW_ONE_WAY   0
#define AUTH_HOW_MUTUAL   2
#define AUTH_HOW_MASK   2
#define AUTHTYPE_NULL   0
#define AUTHTYPE_KERBEROS_V4   1
#define AUTHTYPE_KERBEROS_V5   2
#define AUTHTYPE_SPX   3
#define AUTHTYPE_MINK   4
#define AUTHTYPE_CNT   5
#define AUTHTYPE_TEST   99
static const UNUSED char* authtype_names[8] = { "NULL", "KERBEROS_V4", "KERBEROS_V5", "SPX", "MINK", 0 };
#define AUTHTYPE_NAME_OK(x)   ((unsigned int)(x) < AUTHTYPE_CNT)
#define AUTHTYPE_NAME(x)   authtype_names[x]
#define ENCRYPT_IS   0
#define ENCRYPT_SUPPORT   1
#define ENCRYPT_REPLY   2
#define ENCRYPT_START   3
#define ENCRYPT_END   4
#define ENCRYPT_REQSTART   5
#define ENCRYPT_REQEND   6
#define ENCRYPT_ENC_KEYID   7
#define ENCRYPT_DEC_KEYID   8
#define ENCRYPT_CNT   9
#define ENCTYPE_ANY   0
#define ENCTYPE_DES_CFB64   1
#define ENCTYPE_DES_OFB64   2
#define ENCTYPE_CNT   3
static const UNUSED char* encrypt_names[16] = { "IS", "SUPPORT", "REPLY", "START", "END", "REQUEST-START", "REQUEST-END", "ENC-KEYID", "DEC-KEYID", 0 };
static const UNUSED char* enctype_names[4] = { "ANY", "DES_CFB64", "DES_OFB64", 0 };
#define ENCRYPT_NAME_OK(x)   ((unsigned int)(x) < ENCRYPT_CNT)
#define ENCRYPT_NAME(x)   encrypt_names[x]
#define ENCTYPE_NAME_OK(x)   ((unsigned int)(x) < ENCTYPE_CNT)
#define ENCTYPE_NAME(x)   enctype_names[x]


#endif  // ARPA_TELNET_H


/* TRIVIAL FILE TRANSFER PROTOCOL (<arpa/tftp.h>) */


#if (!(defined(ARPA_TFTP_H) || defined(_ARPA_TFTP_H) || defined(_ARPA_TFTP_H_)))
#define ARPA_TFTP_H   (1)
#define _ARPA_TFTP_H   (1)
#define _ARPA_TFTP_H_   (1)


/** Data segment size */
#define SEGSIZE   512
// Packet types
/** Read request */
#define RRQ   1
/** Write request */
#define WRQ   2
/** Data packet */
#define DATA   3
/** Acknowledgement */
#define ACK   4
/** Error code */
#define ERROR   5
/** Option acknowledgement */
#define OACK   6
// Error codes
/** Not defined */
#define EUNDEF   0
/** File not found */
#define ENOTFOUND   1
/** Access violation */
#define EACCESS   2
/** Disk full or allocation exceeded */
#define ENOSPACE   3
/** Illegal TFTP operation */
#define EBADOP   4
/** Unknown transfer ID */
#define EBADID   5
/** File already exists */
#define EEXISTS   6
/** No such user */
#define ENOUSER   7
/** Option negotiation failed */
#define EOPTNEG   8


typedef struct attr_packed tftphdr {
	unsigned short th_opcode;  //!< Packet type
	union th_u_union {
		unsigned short tu_block;  //!< Block #
		unsigned short tu_code;  //!< Error code
		char tu_stuff[1];  //!< Request packet stuff
	} th_u;
	char th_data[1];  //!< Data or error string
} tftphdr_t;
#define th_block   th_u.tu_block
#define th_code   th_u.tu_code
#define th_stuff   th_u.tu_stuff
#define th_msg   th_data


#endif  // ARPA_TFTP_H


/* <nss.h> */


#if (!(defined(NSS_H) || defined(_NSS_H) || defined(_NSS_H_)))
#define NSS_H   (1)
#define _NSS_H   (1)
#define _NSS_H_   (1)


/** Possible results of lookup using a nss_* function */
typedef enum nss_status {
	NSS_STATUS_TRYAGAIN = -2,
	NSS_STATUS_UNAVAIL,
	NSS_STATUS_NOTFOUND,
	NSS_STATUS_SUCCESS,
	NSS_STATUS_RETURN
} nss_status_t;


/** Data structure used for the `gethostbyname4_r` function */
struct gaih_addrtuple {
	struct gaih_addrtuple* next;
	char* name;
	int family;
	uint32_t addr[4];
	uint32_t scopeid;
};


#endif


/* <nss/nsswitch.h> & <nsswitch.h> */


#if (!(defined(NSSWITCH_H) || defined(_NSSWITCH_H) || defined(_NSSWITCH_H_) || defined(_NSS_NSSWITCH_H) || defined(_NSS_NSSWITCH_H_)))
#define NSSWITCH_H   (1)
#define _NSSWITCH_H   (1)
#define _NSSWITCH_H_   (1)
#define NSS_NSSWITCH_H   (1)
#define _NSS_NSSWITCH_H   (1)
#define _NSS_NSSWITCH_H_   (1)


#define NSS_MODULE_INTERFACE_VERSION   0
#define NS_CONTINUE   0
#define NS_RETURN   1
/** Maximum number of NSS aliases */
#define MAX_NR_ALIASES   48
/** Maximum number of NSS addresses */
#define MAX_NR_ADDRS   48
// nsswitch.conf status codes and nsdispatch(3) return values
enum NSSWITCH_STATUS_CODE {
/** Entry was found */
	NS_SUCCESS = 1,
/** Source not responding, or corrupt */
	NS_UNAVAIL = 2,
/** Source responded 'no such entry' */
	NS_NOTFOUND = 4,
/** Source busy, may respond to retrys */
	NS_TRYAGAIN = 8,
/** Bitmask to get the status flags */
	NS_STATUSMASK = 0xff,
/** Force all methods to be invoked; Internal nsdispatch(3) flag that is not settable in nsswitch.conf(5) */
	NS_FORCEALL = 0x100
};
/** Local files */
#define NSSRC_FILES   "files"
/** DNS; IN for hosts, HS for others */
#define NSSRC_DNS   "dns"
/** YP/NIS */
#define NSSRC_NIS   "nis"
/** passwd (group in YP compat mode) */
#define NSSRC_COMPAT   "compat"
// Currently implemented databases
#define NSDB_HOSTS   "hosts"
#define NSDB_GROUP   "group"
#define NSDB_GROUP_COMPAT   "group_compat"
#define NSDB_NETGROUP   "netgroup"
#define NSDB_NETWORKS   "networks"
#define NSDB_PASSWD   "passwd"
#define NSDB_PASSWD_COMPAT   "passwd_compat"
#define NSDB_SHELLS   "shells"
// Suggested databases
#define NSDB_ALIASES   "aliases"
#define NSDB_AUTH   "auth"
#define NSDB_AUTOMOUNT   "automount"
#define NSDB_BOOTPARAMS   "bootparams"
#define NSDB_ETHERS   "ethers"
#define NSDB_EXPORTS   "exports"
#define NSDB_NETMASKS   "netmasks"
#define NSDB_PHONES   "phones"
#define NSDB_PRINTCAP   "printcap"
#define NSDB_PROTOCOLS   "protocols"
#define NSDB_REMOTE   "remote"
#define NSDB_RPC   "rpc"
#define NSDB_SENDMAILVARS   "sendmailvars"
#define NSDB_SERVICES   "services"
#define NSDB_TERMCAP   "termcap"
#define NSDB_TTYS   "ttys"
// Macros to help build an ns_dtab[]
#define NS_FILES_CB(F, C)   { NSSRC_FILES,  F,  UNCONST(C) },
#define NS_COMPAT_CB(F, C)   { NSSRC_COMPAT, F,  UNCONST(C) },
#ifdef HESIOD
#   define NS_DNS_CB(F, C)   { NSSRC_DNS,  F,  UNCONST(C) },
#else
#   define NS_DNS_CB(F, C)
#endif
#ifdef YP
#   define NS_NIS_CB(F, C)   { NSSRC_NIS,  F,  UNCONST(C) },
#else
#   define NS_NIS_CB(F, C)
#endif
#define NS_NULL_CB   { .src = NULL },


/** Actions performed after lookup finished */
typedef enum lookup_actions { NSS_ACTION_CONTINUE, NSS_ACTION_RETURN }   lookup_actions;


typedef struct service_library {
	const char* name;  //!< Name of service (files, dns, nis, etc.)
	void* lib_handle;  //!< Pointer to the loaded shared library
	struct service_library* next;  //!< Link to the next entry
} service_library;


/** ns_dtab `callback` function */
typedef int (*nss_method)(void*, void*, va_list);


/** nsswitch dispatch table; Contains an entry for each source and the appropriate function to call */
typedef struct ns_dtab {
	const char* src;
	nss_method callback;
	void* cb_data;
} ns_dtab;


/** nsswitch source; Used by the nsparser routines to store a mapping between a source and its dispatch control flags for a given database */
typedef struct attr_packed __ns_src { const char* name; uint32_t flags; }   ns_src;


// Default sourcelists (if nsswitch.conf is missing, corrupt, or if the requested database does not have an entry)
// static UNUSED ns_src __nsdefaultsrc[];
// static UNUSED ns_src __nsdefaultcompat[];
// static UNUSED ns_src __nsdefaultcompat_forceall[];
// static UNUSED ns_src __nsdefaultfiles[];
// static UNUSED ns_src __nsdefaultfiles_forceall[];
// static UNUSED ns_src __nsdefaultnis[];
// static UNUSED ns_src __nsdefaultnis_forceall[];


/** nsswitch method table; An nsswitch module provides a mapping from (database name, method name) tuples to the nss_method and associated callback data */
typedef struct ns_mtab {
	const char* database;
	const char* name;
	nss_method method;
	void* mdata;
} ns_mtab;


/** Module un-registration function called at module unload */
typedef void (*nss_module_unregister_fn)(ns_mtab*, unsigned int);


/** Module registration function called at module load */
typedef ns_mtab *(*nss_module_register_fn)(const char*, unsigned int*, nss_module_unregister_fn*);


/** For each database in /etc/nsswitch.conf there is a ns_dbt, with its name and a list of ns_src's containing the source information */
typedef struct attr_packed ns_dbt {
	const char* name;  //!< Name of database
	ns_src* srclist;  //!< List of sources
	unsigned int srclistsize;  //!< Size of srclist
} ns_dbt;


/** nsswitch module */
typedef struct attr_packed ns_mod {
	const char* name;  //!< module name
	void* handle;  //!< Handle from dlopen()
	ns_mtab* mtab;  //!< Method table
	unsigned int mtabsize;  //!< size of mtab
	nss_module_unregister_fn unregister;  //!< Called to unload module
} ns_mod;


/** Datatype for mapping a function name to a function pointer */
typedef struct known_function { const char* fct_name; void* fct_ptr; }   known_function;


typedef int (*lookup_function)(const char*, struct etherent*, char*, int, int*);


typedef struct attr_packed service_user {
	struct service_user* next;
	lookup_actions actions[5];
	service_library* library;
	struct entry* known;
	char* name;
} service_user;


/* TODO: Add nsswitch.h functions
int nsdispatch(void*, const ns_dtab[], const char*, const char*, const ns_src[], ...);
int _nsdbtaddsrc(ns_dbt*, const ns_src*);
void _nsdbtdump(const ns_dbt*);
int _nsdbtput(const ns_dbt*);
void _nsyyerror(const char*);
int _nsyylex(void);
*/


#endif  // NSSWITCH_H


/* <netinet/ether.h> */


#if (!(defined(NETINET_ETHER_H) || defined(_NETINET_ETHER_H) || defined(_NETINET_ETHER_H_)))
#define NETINET_ETHER_H   (1)
#define _NETINET_ETHER_H   (1)
#define _NETINET_ETHER_H_   (1)


#ifndef ETHER_LINE_LEN
#   define ETHER_LINE_LEN   256
#endif


LIB_FUNC struct ether_addr* ether_aton_r(const char* restrict asc, struct ether_addr* restrict addr) {
	register size_t cnt = 0;
	register unsigned int number = 0;
	register char ch = '\0';
	for (; cnt < 6; ++cnt) {
		ch = (char)_tolower(*asc++);
		if ((ch < '0' || ch > '9') && (ch < 'a' || ch > 'f')) { return NULL; }
		number = (unsigned int)((isdigit(ch)) ? (ch - '0') : (ch - 'a' + 10));
		ch = (char)_tolower(*asc);
		if ((cnt < 5 && ch != ':') || (cnt == 5 && ch != '\0' && !isspace(ch))) {
			++asc;
			if ((ch < '0' || ch > '9') && (ch < 'a' || ch > 'f')) { return NULL; }
			number <<= 4;
			number += (unsigned int)(isdigit(ch) ? (ch - '0') : (ch - 'a' + 10));
			ch = *asc;
			if (cnt < 5 && ch != ':') { return NULL; }
		}
		addr->ether_addr_octet[cnt] = (unsigned char)number;
		++asc;
	}
	return addr;
}


LIB_FUNC struct ether_addr* ether_aton(const char* restrict asc) {
	static struct ether_addr result = { 0 };
	return ether_aton_r(asc, &result);
}


/** Returns a pointer to the part of the line with the start of the hostname, or NULL if it could not parse the line */
LIB_FUNC const char* __ether_line(const char* restrict line, struct ether_addr* restrict addr) {
	struct ether_addr* res = ether_aton_r(line, addr);
	if (!res) { return NULL; }
	while (*line && (*line != ' ') && (*line != '\t')) { line++; }
	while (*line && ((*line == ' ')	|| (*line == '\t'))) { line++; }
	return ((*line) ? line : NULL);
}


/** Strips out the comment before calling __ether_line */
LIB_FUNC const char* __ether_line_w(char* restrict line, struct ether_addr* restrict addr) {
	char* end = strchr_nc(line, '#');
	if (!end) { end = strchr_nc(line, '\n'); }
	else if (end) { *end = '\0'; }
	return __ether_line(line, addr);
}


LIB_FUNC int ether_line(const char* line, struct ether_addr* addr, char* hostname) {
	const char* name = __ether_line(line, addr);
	if (!name) { return -1; }
	while (*name) {
		if ((*name == '#') || isspace(*name)) { break; }
		*hostname++ = *name++;
	}
	*hostname = '\0';
	return 0;
}


LIB_FUNC char* ether_ntoa_r(const struct ether_addr* addr, char* buf) {
	sprintf(buf, "%x:%x:%x:%x:%x:%x", addr->ether_addr_octet[0], addr->ether_addr_octet[1], addr->ether_addr_octet[2], addr->ether_addr_octet[3], addr->ether_addr_octet[4], addr->ether_addr_octet[5]);
	return buf;
}


LIB_FUNC char* ether_ntoa(const struct ether_addr* addr) {
	static char asc[18] = { 0 };
	return ether_ntoa_r(addr, asc);
}


LIB_FUNC int ether_ntohost(char* hostname, const struct ether_addr* addr) {
	int res = -1;
	FILE* fp = fopen(ETHER_FILE_NAME, "r");
	if (!fp) { return -1; }
	char buf[ETHER_LINE_LEN] = { 0 };
	while (fgets(buf, ETHER_LINE_LEN, fp)) {
		struct ether_addr tmp_addr;
		const char* cp = __ether_line_w(buf, &tmp_addr);
		if (!cp) { continue; }
		else if (memcmp(addr, &tmp_addr, sizeof(tmp_addr))) { continue; }
		strcpy_no_output(hostname, cp);
		res = 0;
		break;
	}
	fclose(fp);
	return res;
}


LIB_FUNC int ether_hostton(const char* hostname, struct ether_addr* addr) {
	int res = -1;
	FILE* fp = fopen(ETHER_FILE_NAME, "r");
	if (!fp) { return -1; }
	char buf[ETHER_LINE_LEN] = { 0 };
	while (fgets(buf, ETHER_LINE_LEN, fp)) {
		const char* cp = __ether_line_w(buf, addr);
		if (!cp) { continue; }
		else if (strcasecmp(hostname, cp)) { continue; }
		res = 0;
		break;
	}
	fclose(fp);
	return res;
}


#endif  // NETINET_ETHER_H


/* NSCD (<nscd/nscd_proto.h>) */


#if (!(defined(NSCD_PROTO_H) || defined(_NSCD_PROTO_H) || defined(_NSCD_PROTO_H_)))
#define NSCD_PROTO_H   (1)
#define _NSCD_PROTO_H   (1)
#define _NSCD_PROTO_H_   (1)


/** Interval in which we transfer retry to contact the NSCD */
#define NSS_NSCD_RETRY   100
// Variables for communication between NSCD handler functions and NSS
// static UNUSED int __nss_not_use_nscd_passwd;
// static UNUSED int __nss_not_use_nscd_group;
// static UNUSED int __nss_not_use_nscd_hosts;
// static UNUSED int __nss_not_use_nscd_services;
// static UNUSED int __nss_not_use_nscd_netgroup;


/* TODO: Add nscd_proto.h functions
struct nscd_ai_result;
static int __nscd_getpwnam_r (const char *name, struct passwd *resultbuf, char *buffer, size_t buflen, struct passwd **result);
static int __nscd_getpwuid_r (uid_t uid, struct passwd *resultbuf, char *buffer,  size_t buflen, struct passwd **result);
static int __nscd_getgrnam_r (const char *name, struct group *resultbuf, char *buffer, size_t buflen, struct group **result);
static int __nscd_getgrgid_r (gid_t gid, struct group *resultbuf, char *buffer,  size_t buflen, struct group **result);
static int __nscd_gethostbyname_r (const char *name, struct hostent *resultbuf, char *buffer, size_t buflen, struct hostent **result, int *h_errnop);
static int __nscd_gethostbyname2_r (const char *name, int af, struct hostent *resultbuf, char *buffer, size_t buflen, struct hostent **result, int *h_errnop);
static int __nscd_gethostbyaddr_r (const void *addr, socklen_t len, int type, struct hostent *resultbuf, char *buffer, size_t buflen, struct hostent **result, int *h_errnop);
static int __nscd_getai (const char *key, struct nscd_ai_result **result, int *h_errnop);
static int __nscd_getgrouplist (const char *user, gid_t group, long *size, gid_t **groupsp, long limit);
static int __nscd_getservbyname_r (const char *name, const char *proto, struct servent *result_buf, char *buf, size_t buflen, struct servent **result);
static int __nscd_getservbyport_r (int port, const char *proto, struct servent *result_buf, char *buf, size_t buflen, struct servent **result);
static int __nscd_innetgr (const char *netgroup, const char *host, const char *user, const char *domain);
static int __nscd_setnetgrent (const char *group, struct __netgrent *datap);
*/


#endif  // NSCD_PROTO_H


DIAG_FUNCTIONS

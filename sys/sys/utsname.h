/*	$NetBSD: utsname.h,v 1.13 2005/12/11 12:25:21 christos Exp $	*/

/*-
 * Copyright (c) 1994
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chuck Karish of Mindcraft, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)utsname.h	8.1 (Berkeley) 1/4/94
 */

#ifndef	_SYS_UTSNAME_H_
#define	_SYS_UTSNAME_H_

#include <sys/featuretest.h>

#define	_SYS_NMLN	256

#if defined(_NETBSD_SOURCE)
#define	SYS_NMLN	_SYS_NMLN
#endif

struct utsname {
	char	sysname[_SYS_NMLN];	/* Name of this OS. */
	char	nodename[_SYS_NMLN];	/* Name of this network node. */
	char	release[_SYS_NMLN];	/* Release level. */
	char	version[_SYS_NMLN];	/* Version level. */
	char	machine[_SYS_NMLN];	/* Hardware type. */
#if defined(__minix)
	char	arch[_SYS_NMLN];
#endif /* defined(__minix) */
};

#include <sys/cdefs.h>

__BEGIN_DECLS
int	uname(struct utsname *);
#if defined(__minix)
int 	sysuname(int _req, int _field, char *_value, size_t _len);
#endif /* defined(__minix) */
__END_DECLS

#if defined(__minix)
/* req: Get or set a string. */
#define _UTS_GET	0
#define _UTS_SET	1

/* field: What field to get or set.  These values can't be changed lightly. */
#define _UTS_ARCH	0
#define _UTS_KERNEL	1
#define _UTS_MACHINE	2
#define _UTS_HOSTNAME	3
#define _UTS_NODENAME	4
#define _UTS_RELEASE	5
#define _UTS_VERSION	6
#define _UTS_SYSNAME	7
#define _UTS_BUS	8
#define _UTS_MAX	9	/* Number of strings. */
#endif /* defined(__minix) */

#endif	/* !_SYS_UTSNAME_H_ */

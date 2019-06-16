/* -*- coding: utf-8-unix; Mode: Asm; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vim: set fileencoding=utf-8 filetype=asm syntax=asm asmsyntax=gas fileformat=unix tabstop=4 : */
/* kate: encoding utf-8; bom off; syntax gas; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; */

.globl _start

_start:
	movq %rsp, %rbp  /* Setup a new stack frame */
	popq %rdi  /* %rdi = argc */
	movq %rsp, %rsi  /* %rsi = argv */
	pushq %rdi  /* Align stack */
	leaq 8(%rsi, %rdi, 8), %rdx  /* %rdx = envp = (8*rdi)+%rsi+8 */
	call main
	/* EXIT */
	movl $1, %eax
	xorl %ebx, %ebx
	int $0x80

.size _start, . - _start

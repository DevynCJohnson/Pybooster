[keywords]
directives=%1 %10 %2 %3 %4 %5 %6 %7 %8 %9 %endmacro %macro .bss .byte .cseg .data .db .def .device .dseg .dw .endmacro .equ .eseg .exit .include .list .listmac .macro .nolist .org .set .text _start byte db equ equivalent extern global globl list movsb nolist org page resb section stosb text word
instructions=aaa aad aam aas adc add addst adiw and andi asr bclr bld brbc brbs brcc brcs breq brge brhc brhs brid brie brlo brlt brmi brne brpl brsh brtc brts brvc brvs bset bst bt call cbi cbr clc cld clh cli cln clr cls clt clv clz cmp com cp cpc cpi cpse dec dek div divst eor hlt icall ijmp imul in inc ink int iret ja jae jb jbe jc jcxz je jecxz jez jg jge jgz jl jle jlz jmp jna jnae jnb jnbe jnc jne jng jnge jnl jnle jno jnp jns jnz jo jp jpe jpo js jsr jz lad ld ldd ldi lds ldx lea leaq lia loop loope loopne loopnz loopz lpm lsa lsl lsr mov movl movq movs movsb movsd movsw movsx movw mul mulst neg nop not or ori out pop popa popac popad popfd popq push pusha pushac pushad pushf pushfd rcall rep ret reti rjmp rol ror sbb sbc sbci sbi sbic sbis sbiw sbr sbrc sbrs sec seh sei sen ser ses set sev sez shl shr sleep spi st stc std stos stosb stosd stosw sts sub subi subst swap test tst wdr xchg xlat xor xorl
registers=ah al ax bh bl bp bx ch cl cx dh di dl dx eax ebp ebx ecx edi edx esi esp r0 r1 r10 r11 r12 r13 r14 r15 r16 r17 r18 r19 r2 r20 r21 r22 r23 r24 r25 r26 r27 r28 r29 r3 r30 r31 r4 r5 r6 r7 r8 r9 si sp

[lexer_properties]
code.page=65001
fold.asm.comment.explicit=1
fold.asm.comment.multiline=1
fold.asm.explicit.anywhere=1
fold.asm.explicit.end=/* } */
fold.asm.explicit.start=/* (FB){ */
fold.asm.syntax.based=1
lexer.cpp.track.preprocessor=0
lexer.cpp.update.preprocessor=1
preprocessor.end.$(file.patterns.cpp)=endif
preprocessor.middle.$(file.patterns.cpp)=else elif
preprocessor.start.$(file.patterns.cpp)=if ifdef ifndef
preprocessor.symbol.$(file.patterns.cpp)=#
session.bookmarks=1
session.folds=1
styling.within.preprocessor=1

[settings]
lexer_filetype=asm
extension=s
mime_type=text/plain
comment_open=/*
comment_close=*/
comment_use_indent=false
context_action_cmd=

[indentation]
type=0
width=4

[build-menu]
EX_00_LB=_Build & Execute
EX_00_CM=nasm -f elf %d/%f -o %d/%e.o && ld %d/%e.o -o %d/%e && ./%e
EX_00_WD=
EX_01_LB=
EX_01_CM=
EX_01_WD=
FT_01_LB=_as
FT_01_CM=as --warn --64 --strip-local-absolute "%d/%f" -o "%e"
FT_01_WD=

[build_settings]
compiler=nasm "%d/%f"

// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
/**
@brief Standard Macros Header Providing Miscellaneous Code
@file MACROS_MISC.h
@version 2019.03.28
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This file defines miscellaneous datatypes, macros, functions, etc.

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


/* ALPHA OPCODE TABLE (<alpha.h>) */


#if ((!defined(OPCODE_ALPHA_H)) && defined(ARCHALPHA))
#define OPCODE_ALPHA_H   (1)


// Values defined for the flags field of a struct alpha_opcode

/** Base architecture */
#define AXP_OPCODE_BASE   1
/** EV4 specific PALcode insns */
#define AXP_OPCODE_EV4   2
/** EV5 specific PALcode insns */
#define AXP_OPCODE_EV5   4
/** EV6 specific PALcode insns */
#define AXP_OPCODE_EV6   8
/** Byte/word extension (amask bit 0) */
#define AXP_OPCODE_BWX   0x100
/** "Count" extension (amask bit 1) */
#define AXP_OPCODE_CIX   0x200
/** Multimedia extension (amask bit 8) */
#define AXP_OPCODE_MAX   0x400
#define AXP_OPCODE_NOPAL   (~(AXP_OPCODE_EV4 | AXP_OPCODE_EV5 | AXP_OPCODE_EV6))
/** A macro to extract the major opcode from an instruction */
#define AXP_OP(i)   (((i) >> 26) & 0x3f)
/** The total number of major opcodes */
#define AXP_NOPS   0x40


// Values defined for the flags field of a struct alpha_operand

/** Mask for selecting the type for typecheck purposes */
#define AXP_OPERAND_TYPECHECK_MASK   (AXP_OPERAND_PARENS | AXP_OPERAND_COMMA | AXP_OPERAND_IR | AXP_OPERAND_FPR | AXP_OPERAND_RELATIVE | AXP_OPERAND_SIGNED | AXP_OPERAND_UNSIGNED)
/** This operand does not actually exist in the assembler input; This is used to support extended mnemonics, for which two operands fields are identical */
#define AXP_OPERAND_FAKE   1
/** The operand should be wrapped in parentheses rather than separated from the previous by a comma; This is used for the load and store instructions which want their operands to look like "Ra,disp(Rb)" */
#define AXP_OPERAND_PARENS   2
/** Used in combination with PARENS, this supresses the supression of the comma; This is used for "jmp Ra,(Rb),hint" */
#define AXP_OPERAND_COMMA   4
/** This operand names an integer register */
#define AXP_OPERAND_IR   010
/** This operand names a floating point register */
#define AXP_OPERAND_FPR   020
/** This operand is a relative branch displacement; The disassembler prints these symbolically if possible */
#define AXP_OPERAND_RELATIVE   040
/** This operand takes signed values */
#define AXP_OPERAND_SIGNED   0100
/** This operand takes unsigned values; This exists primarily so that a flags value of 0 can be treated as end-of-arguments */
#define AXP_OPERAND_UNSIGNED   0200
/** Supress overflow detection on this field; This is used for hints */
#define AXP_OPERAND_NOOVERFLOW   0400
/** Mask for optional argument default value */
#define AXP_OPERAND_OPTIONAL_MASK   07000
/** This operand defaults to zero; This is used for jump hints */
#define AXP_OPERAND_DEFAULT_ZERO   01000
/** This operand should default to the first (real) operand and is used in conjunction with AXP_OPERAND_OPTIONAL; This allows "and $0,3,$0" to be written as "and $0,3", etc. */
#define AXP_OPERAND_DEFAULT_FIRST   02000
/** Similarly, this operand should default to the second (real) operand; This allows "negl $0" instead of "negl $0,$0" */
#define AXP_OPERAND_DEFAULT_SECOND   04000


// Register common names

enum ALPHA_REGISTERS {
	AXP_REG_V0 = 0,
	AXP_REG_T0 = 1,
	AXP_REG_T1 = 2,
	AXP_REG_T2 = 3,
	AXP_REG_T3 = 4,
	AXP_REG_T4 = 5,
	AXP_REG_T5 = 6,
	AXP_REG_T6 = 7,
	AXP_REG_T7 = 8,
	AXP_REG_S0 = 9,
	AXP_REG_S1 = 10,
	AXP_REG_S2 = 11,
	AXP_REG_S3 = 12,
	AXP_REG_S4 = 13,
	AXP_REG_S5 = 14,
	AXP_REG_FP = 15,
	AXP_REG_A0 = 16,
	AXP_REG_A1 = 17,
	AXP_REG_A2 = 18,
	AXP_REG_A3 = 19,
	AXP_REG_A4 = 20,
	AXP_REG_A5 = 21,
	AXP_REG_T8 = 22,
	AXP_REG_T9 = 23,
	AXP_REG_T10 = 24,
	AXP_REG_T11 = 25,
	AXP_REG_RA = 26,
	AXP_REG_PV = 27,
	AXP_REG_T12 = 27,
	AXP_REG_AT = 28,
	AXP_REG_GP = 29,
	AXP_REG_SP = 30,
	AXP_REG_ZERO = 31
};


struct alpha_opcode {
	const char* name;
	unsigned int opcode, mask, flags;
	unsigned char operands[4];
};


typedef struct attr_packed alpha_operand {
	unsigned int bits:5;
	unsigned int shift:5;
	signed int default_reloc:16;
	unsigned int flags:16;
	unsigned int (*insert)(unsigned instruction, int op, const char** errmsg);
	int (*extract)(unsigned instruction, int* invalid);
} alpha_operand_t;


extern const UNUSED struct alpha_opcode alpha_opcodes[];
extern const UNUSED unsigned int alpha_num_opcodes;
extern const UNUSED struct alpha_operand alpha_operands[];
extern const UNUSED unsigned int alpha_num_operands;


#endif  // OPCODE_ALPHA_H


/* ELF TYPES, STRUCTURES, & MACROS (<elf.h>, <sys/elf_common.h>, <elf-hints.h>, <sys/elf32.h>, and <sys/elf64.h>) */


#if ((!(defined(ELF_H) || defined(_ELF_H) || defined(_ELF_H_) || defined(_SYS_ELF_COMMON_H_) || defined(_SYS_ELF32_H_) || defined(_SYS_ELF64_H_) || defined(ELF_HINTS_H) || defined(_ELF_HINTS_H) || defined(_ELF_HINTS_H_))) && defined(ALLOW_HEADER_ELF_H))
#define ELF_H   (1)
#define _ELF_H   (1)
#define _ELF_H_   (1)
#define _SYS_ELF32_H_   (1)
#define _SYS_ELF64_H_   (1)
#define _SYS_ELF_COMMON_H_   (1)
#define ELF_HINTS_H   (1)
#define _ELF_HINTS_H   (1)
#define _ELF_HINTS_H_   (1)


#define ELFHINTS_MAGIC   0x746e6845
#define __ELF_NATIVE_CLASS   __WORDSIZE

#if (defined(ARCHALPHA) || (defined(ARCHS390X) && IS_WORDSIZE_64))
/** Linux/Alpha is exceptional as it has .hash section with 64 bit entries */
typedef uint64_t   Elf_Symndx;
#else
/** Hash table entries usually have a size of 32 bits */
typedef uint32_t   Elf_Symndx;
#endif


/** Hints file produced by ldconfig */
typedef struct elfhints_hdr {
	uint32_t magic;  //!< Magic number
	uint32_t version;  //!< File version
	uint32_t strtab;  //!< Offset of string table in file
	uint32_t strsize;  //!< Size of string table
	uint32_t dirlist;  //!< Offset of directory list in string table
	uint32_t dirlistlen;  //!< strlen(dirlist)
	uint32_t spare[26];  //!< Room for expansion
} elfhints_hdr_t;


typedef uint16_t   Elf32_Half;
typedef uint16_t   Elf64_Half;
typedef uint32_t   Elf32_Word;
typedef int32_t   Elf32_Sword;
typedef uint32_t   Elf64_Word;
typedef int32_t   Elf64_Sword;
typedef uint64_t   Elf32_Xword;
typedef int64_t   Elf32_Sxword;
typedef uint64_t   Elf64_Xword;
typedef int64_t   Elf64_Sxword;
#define Elf32_Addr   Elf32_Word
#define Elf64_Addr   Elf64_Xword
/** Elf file offset (32-bit Elf) */
typedef uint32_t   Elf32_Off;
/** Elf file offset (64-bit Elf) */
typedef uint64_t   Elf64_Off;
/** 16-bit section indices in Elf files (32-bit Elf) */
typedef uint16_t   Elf32_Section;
/** 16-bit section indices in Elf files (64-bit Elf) */
typedef uint16_t   Elf64_Section;
/** Elf file version symbol information (32-bit Elf) */
typedef uint16_t   Elf32_Versym;
/** Elf file version symbol information (64-bit Elf) */
typedef uint16_t   Elf64_Versym;
/** Entries found in sections of type SHT_MIPS_CONFLICT */
typedef uint32_t   Elf32_Conflict;


#define EI_NIDENT   (0x10)
// Extract and insert information held in ELF fields
#define ELF32_ST_BIND(val)   (((unsigned char)(val)) >> 4)
#define ELF32_ST_TYPE(val)   ((val) & 0xf)
#define ELF32_ST_INFO(bind, type)   (((bind) << 4) + ((type) & 0xf))
#define ELF32_ST_VISIBILITY(o)   ((o) & 3)
#define ELF64_ST_VISIBILITY(o)   ELF32_ST_VISIBILITY(o)
// Macros to construct move records
#define ELF32_M_SYM(info)   ((info) >> 8)
#define ELF32_M_SIZE(info)   ((unsigned char)(info))
#define ELF32_M_INFO(sym, size)   (((sym) << 8) + (unsigned char)(size))
#define ELF64_M_SYM(info)   ELF32_M_SYM (info)
#define ELF64_M_SIZE(info)   ELF32_M_SIZE (info)
#define ELF64_M_INFO(sym, size)   ELF32_M_INFO (sym, size)
// Extract and insert information held in the r_info field
#define ELF32_R_SYM(val)   ((val) >> 8)
#define ELF32_R_TYPE(val)   ((val) & 0xff)
#define ELF32_R_INFO(sym, type)   (((sym) << 8) + ((type) & 0xff))
#define ELF64_R_SYM(i)   ((i) >> 0x20)
#define ELF64_R_TYPE(i)   ((i) & UINT32_MAX)
#define ELF64_R_INFO(sym,type)   ((((Elf64_Xword)(sym)) << 0x20) + (type))
// Legal values for p_flags (segment flags)
/** Segment is executable */
#define PF_X   1
/** Segment is writable */
#define PF_W   2
/** Segment is readable */
#define PF_R   4
/** Enable  PAGEEXEC */
#define PF_PAGEEXEC   0x10
/** Disable PAGEEXEC */
#define PF_NOPAGEEXEC   0x20
/** Enable  SEGMEXEC */
#define PF_SEGMEXEC   0x40
/** Disable SEGMEXEC */
#define PF_NOSEGMEXEC   0x80
/** Enable  MPROTECT */
#define PF_MPROTECT   0x100
/** Disable MPROTECT */
#define PF_NOMPROTECT   0x200
/** Enable  RANDEXEC */
#define PF_RANDEXEC   0x400
/** Disable RANDEXEC */
#define PF_NORANDEXEC   0x800
/** Enable  EMUTRAMP */
#define PF_EMUTRAMP   0x1000
/** Disable EMUTRAMP */
#define PF_NOEMUTRAMP   0x2000
/** Enable  RANDMMAP */
#define PF_RANDMMAP   0x4000
/** Disable RANDMMAP */
#define PF_NORANDMMAP   0x8000
/** OS-specific */
#define PF_MASKOS   0x0ff00000
/** Processor-specific */
#define PF_MASKPROC   0xf0000000
// Legal values for DT_MIPS_FLAGS Elf32_Dyn entry
/** No flags */
#define RHF_NONE   0
/** Use quickstart */
#define RHF_QUICKSTART   1
/** Hash size not power of 2 */
#define RHF_NOTPOT   2
/** Ignore LD_LIBRARY_PATH */
#define RHF_NO_LIBRARY_REPLACEMENT 4
#define RHF_NO_MOVE   8
#define RHF_SGI_ONLY   0x10
#define RHF_GUARANTEE_INIT   0x20
#define RHF_DELTA_C_PLUS_PLUS   0x40
#define RHF_GUARANTEE_START_INIT   0x80
#define RHF_PIXIE   0x100
#define RHF_DEFAULT_DELAY_LOAD   0x200
#define RHF_REQUICKSTART   0x400
#define RHF_REQUICKSTARTED   0x800
#define RHF_CORD   0x1000
#define RHF_NO_UNRES_UNDEF   0x2000
#define RHF_RLD_ORDER_SAFE   0x4000
// Legal values for l_flags
#define LL_NONE   0
/** Require exact match */
#define LL_EXACT_MATCH   1
/** Ignore interface version */
#define LL_IGNORE_INT_VER 2
#define LL_REQUIRE_MINOR  4
#define LL_EXPORTS   8
#define LL_DELAY_LOAD   0x10
#define LL_DELTA   0x20


/** ELF file header */
typedef struct _Elf32_Ehdr {
	unsigned char e_ident[EI_NIDENT];  //!< Magic number and other info
	Elf32_Half e_type;  //!< Object file type
	Elf32_Half e_machine;  //!< Architecture
	Elf32_Word e_version;  //!< Object file version
	Elf32_Addr e_entry;  //!< Entry point virtual address
	Elf32_Off e_phoff;  //!< Program header table file offset
	Elf32_Off e_shoff;  //!< Section header table file offset
	Elf32_Word e_flags;  //!< Processor-specific flags
	Elf32_Half e_ehsize;  //!< ELF header size in bytes
	Elf32_Half e_phentsize;  //!< Program header table entry size
	Elf32_Half e_phnum;  //!< Program header table entry count
	Elf32_Half e_shentsize;  //!< Section header table entry size
	Elf32_Half e_shnum;  //!< Section header table entry count
	Elf32_Half e_shstrndx;  //!< Section header string table index
} Elf32_Ehdr;

/** ELF file header */
typedef struct _Elf64_Ehdr {
	unsigned char e_ident[EI_NIDENT];  //!< Magic number and other info
	Elf64_Half e_type;  //!< Object file type
	Elf64_Half e_machine;  //!< Architecture
	Elf64_Word e_version;  //!< Object file version
	Elf64_Addr e_entry;  //!< Entry point virtual address
	Elf64_Off e_phoff;  //!< Program header table file offset
	Elf64_Off e_shoff;  //!< Section header table file offset
	Elf64_Word e_flags;  //!< Processor-specific flags
	Elf64_Half e_ehsize;  //!< ELF header size in bytes
	Elf64_Half e_phentsize;  //!< Program header table entry size
	Elf64_Half e_phnum;  //!< Program header table entry count
	Elf64_Half e_shentsize;  //!< Section header table entry size
	Elf64_Half e_shnum;  //!< Section header table entry count
	Elf64_Half e_shstrndx;  //!< Section header string table index
} Elf64_Ehdr;

#define EI_MAG0   0  //!< File identification byte 0 index
#define ELFMAG0   0x7f  //!< Magic number byte 0
#define EI_MAG1   1  //!< File identification byte 1 index
#define ELFMAG1   'E'  //!< Magic number byte 1
#define EI_MAG2   2  //!< File identification byte 2 index
#define ELFMAG2   'L'  //!< Magic number byte 2
#define EI_MAG3   3  //!< File identification byte 3 index
#define ELFMAG3   'F'  //!< Magic number byte 3
#define ELFMAG   "\177ELF"
#define SELFMAG   4
#if IS_LITTLE_ENDIAN
#   define ELFMAG_U32   ((uint32_t)(ELFMAG0 + 0x100 * (ELFMAG1 + (0x100 * (ELFMAG2 + 0x100 * ELFMAG3)))))
#else  // BIG_ENDIAN
#   define ELFMAG_U32   ((uint32_t)((((ELFMAG0 * 0x100) + ELFMAG1) * 0x100 + ELFMAG2) * 0x100 + ELFMAG3))
#endif

/** File class byte index */
#define EI_CLASS   4
/** Invalid class */
#define ELFCLASSNONE   0
/** 32-bit objects */
#define ELFCLASS32   1
/** 64-bit objects */
#define ELFCLASS64   2
#define ELFCLASSNUM   3
/** Data encoding byte index */
#define EI_DATA   5
/** Invalid data encoding */
#define ELFDATANONE   0
/** 2's complement, little endian */
#define ELFDATA2LSB   1
/** 2's complement, big endian */
#define ELFDATA2MSB   2
#define ELFDATANUM   3
/** File version byte index */
#define EI_VERSION   6
/** OS ABI identification */
#define EI_OSABI   7
/** UNIX System V ABI */
#define ELFOSABI_NONE   0
/** Alias */
#define ELFOSABI_SYSV   0
/** HP-UX */
#define ELFOSABI_HPUX   1
/** NetBSD */
#define ELFOSABI_NETBSD   2
/** Linux */
#define ELFOSABI_LINUX   3
/** GNU/Hurd */
#define ELFOSABI_HURD   4
/** Sun Solaris */
#define ELFOSABI_SOLARIS   6
/** IBM AIX */
#define ELFOSABI_AIX   7
/** SGI Irix */
#define ELFOSABI_IRIX   8
/** FreeBSD */
#define ELFOSABI_FREEBSD   9
/** Compaq TRU64 UNIX */
#define ELFOSABI_TRU64   10
/** Novell Modesto */
#define ELFOSABI_MODESTO   11
/** OpenBSD */
#define ELFOSABI_OPENBSD   12
/** OpenVMS */
#define ELFOSABI_OPENVMS   13
/** Hewlett-Packard Non-Stop Kernel */
#define ELFOSABI_NSK   14
/** Amiga Research OS */
#define ELFOSABI_AROS   15
/** ARM */
#define ELFOSABI_ARM   97
/** Standalone (embedded) application */
#define ELFOSABI_STANDALONE   255
/** ABI version */
#define EI_ABIVERSION   8
/** Byte index of padding bytes */
#define EI_PAD   9
// Legal values for e_type (object file type)
/** No file type */
#define ET_NONE   0
/** Relocatable file */
#define ET_REL   1
/** Executable file */
#define ET_EXEC   2
/** Shared object file */
#define ET_DYN   3
/** Core file */
#define ET_CORE   4
/** Number of defined types */
#define ET_NUM   5
/** OS-specific range start */
#define ET_LOOS   0xfe00
/** OS-specific range end */
#define ET_HIOS   0xfeff
/** Processor-specific range start */
#define ET_LOPROC   0xff00
/** Processor-specific range end */
#define ET_HIPROC   0xffff
// Legal values for e_machine (architecture)
/** No machine */
#define EM_NONE   0
/** AT&T WE 32100 */
#define EM_M32   1
/** SUN SPARC */
#define EM_SPARC   2
/** Intel 80386 */
#define EM_386   3
/** Motorola m68k family */
#define EM_68K   4
/** Motorola m88k family */
#define EM_88K   5
/** Intel 80486 */
#define EM_486   6
/** Intel 80860 */
#define EM_860   7
/** MIPS R3000 big-endian */
#define EM_MIPS   8
/** IBM System/370 */
#define EM_S370   9
/** MIPS R3000 little-endian */
#define EM_MIPS_RS3_LE   10
/** HPPA */
#define EM_PARISC   15
/** Fujitsu VPP500 */
#define EM_VPP500   17
/** Sun's "v8plus" */
#define EM_SPARC32PLUS   18
/** Intel 80960 */
#define EM_960   19
/** PowerPC */
#define EM_PPC   20
/** PowerPC 64-bit */
#define EM_PPC64   21
/** IBM S390 */
#define EM_S390   22
/** NEC V800 series */
#define EM_V800   36
/** Fujitsu FR20 */
#define EM_FR20   37
/** TRW RH-32 */
#define EM_RH32   38
/** Motorola M*Core */
#define EM_MCORE   39
/** Old name for MCore */
#define EM_RCE   39
/** ARM */
#define EM_ARM   40
/** Digital Alpha */
#define EM_FAKE_ALPHA   41
/** Renesas SH */
#define EM_SH   42
/** SPARC v9 64-bit */
#define EM_SPARCV9   43
/** Siemens Tricore */
#define EM_TRICORE   44
/** Argonaut RISC Core */
#define EM_ARC   45
/** Renesas H8/300 */
#define EM_H8_300   46
/** Renesas H8/300H */
#define EM_H8_300H   47
/** Renesas H8S */
#define EM_H8S   48
/** Renesas H8/500 */
#define EM_H8_500   49
/** Intel Merced */
#define EM_IA_64   50
/** Stanford MIPS-X */
#define EM_MIPS_X   51
/** Motorola Coldfire */
#define EM_COLDFIRE   52
/** Motorola M68HC12 */
#define EM_68HC12   53
/** Fujitsu MMA Multimedia Accelerator*/
#define EM_MMA   54
/** Siemens PCP */
#define EM_PCP   55
/** Sony nCPU embeeded RISC */
#define EM_NCPU   56
/** Denso NDR1 microprocessor */
#define EM_NDR1   57
/** Motorola Start*Core processor */
#define EM_STARCORE   58
/** Toyota ME16 processor */
#define EM_ME16   59
/** STMicroelectronic ST100 processor */
#define EM_ST100   60
/** Advanced Logic Corp. Tinyj emb.fam*/
#define EM_TINYJ   61
/** AMD x86-64 architecture */
#define EM_X86_64   62
/** Sony DSP Processor */
#define EM_PDSP   63
/** Siemens FX66 microcontroller */
#define EM_FX66   66
/** STMicroelectronics ST9+ 8/16 mc */
#define EM_ST9PLUS   67
/** STmicroelectronics ST7 8 bit mc */
#define EM_ST7   68
/** Motorola MC68HC16 microcontroller */
#define EM_68HC16   69
/** Motorola MC68HC11 microcontroller */
#define EM_68HC11   70
/** Motorola MC68HC08 microcontroller */
#define EM_68HC08   71
/** Motorola MC68HC05 microcontroller */
#define EM_68HC05   72
/** Silicon Graphics SVx */
#define EM_SVX   73
/** STMicroelectronics ST19 8 bit mc */
#define EM_ST19   74
/** Digital VAX */
#define EM_VAX   75
/** Axis Communications 32-bit embedded processor */
#define EM_CRIS   76
/** Infineon Technologies 32-bit embedded processor */
#define EM_JAVELIN   77
/** Element 14 64-bit DSP Processor */
#define EM_FIREPATH   78
/** LSI Logic 16-bit DSP Processor */
#define EM_ZSP   79
/** Donald Knuth's educational 64-bit processor */
#define EM_MMIX   80
/** Harvard University machine-independent object files */
#define EM_HUANY   81
/** SiTera Prism */
#define EM_PRISM   82
/** Atmel AVR 8-bit microcontroller */
#define EM_AVR   83
/** Fujitsu FR30 */
#define EM_FR30   84
/** Mitsubishi D10V */
#define EM_D10V   85
/** Mitsubishi D30V */
#define EM_D30V   86
/** NEC v850 */
#define EM_V850   87
/** Renesas M32R */
#define EM_M32R   88
/** Matsushita MN10300 */
#define EM_MN10300   89
/** Matsushita MN10200 */
#define EM_MN10200   90
/** picoJava */
#define EM_PJ   91
/** OpenRISC 32-bit embedded processor */
#define EM_OPENRISC   92
/** ARC Cores Tangent-A5 */
#define EM_ARC_A5   93
/** Tensilica Xtensa Architecture */
#define EM_XTENSA   94
/** Ubicom IP2022 micro controller */
#define EM_IP2K   101
/** National Semiconductor CompactRISC */
#define EM_CR   103
/** TI msp430 micro controller */
#define EM_MSP430   105
/** Analog Devices Blackfin */
#define EM_BLACKFIN   106
/** Altera Nios II soft-core processor */
#define EM_ALTERA_NIOS2   113
/** National Semiconductor CRX */
#define EM_CRX   114
#define EM_NUM   95
#define EM_TI_C6000   140
// Unofficial Values
/** picoJava */
#define EM_PJ_OLD   99
/** Cygnus PowerPC ELF backend */
#define EM_CYGNUS_POWERPC 0x9025
/** Old version of Sparc v9, from before the ABI */
#define EM_OLD_SPARCV9   11
/** Old version of PowerPC */
#define EM_PPC_OLD   17
/** Temporary number for the OpenRISC processor (deprecated) */
#define EM_OR32   0x8472
/** Renesas M32C and M16C */
#define EM_M32C   0xfeb0
/** Cygnus M32R ELF backend */
#define EM_CYGNUS_M32R   0x9041
/** old S/390 backend magic number */
#define EM_S390_OLD   0xa390
/** D10V backend magic number */
#define EM_CYGNUS_D10V   0x7650
/** D30V backend magic number */
#define EM_CYGNUS_D30V   0x7676
/** V850 backend magic number */
#define EM_CYGNUS_V850   0x9080
/** mn10200 and mn10300 backend magic numbers */
#define EM_CYGNUS_MN10200   0xdead
#define EM_CYGNUS_MN10300   0xbeef
/** FR30 magic number - no EABI available */
#define EM_CYGNUS_FR30   0x3330
/** AVR magic number */
#define EM_AVR_OLD   0x1057
/** OpenRISC magic number */
#define EM_OPENRISC_OLD   0x3426
/** DLX magic number */
#define EM_DLX   0x5aa5
#define EM_XSTORMY16   0xad45
/** FRV magic number */
#define EM_CYGNUS_FRV   0x5441
/** Ubicom IP2xxx */
#define EM_IP2K_OLD   0x8217
/** Morpho MT */
#define EM_MT   0x2530
/** MSP430 magic number */
#define EM_MSP430_OLD   0x1059
/** Vitesse IQ2000 */
#define EM_IQ2000   0xfeba
/** Old, unofficial value for Xtensa */
#define EM_XTENSA_OLD   0xabc7
/** Alpha backend magic number */
#define EM_ALPHA   0x9026
/** NIOS magic number - no EABI available */
#define EM_NIOS32   0xfebb
/** AVR32 magic number from ATMEL */
#define EM_AVR32   0x18ad
/** V850 backend magic number */
#define EM_CYGNUS_V850   0x9080
/** Xilinx Microblaze (unofficial); Note that there is now an official microblaze magic number, but all the toolchains currently in existence use the old number */
#define EM_MICROBLAZE_OLD   0xbaab
/** Xilinx Microblaze (official) */
#define EM_MICROBLAZE   189
// Legal values for e_version (version)
/** Invalid ELF version */
#define EV_NONE   0
/** Current version */
#define EV_CURRENT   1
#define EV_NUM   2

/** Elf Section Header */
typedef struct _Elf32_Shdr {
	Elf32_Word sh_name;  //!< Section name (string tbl index)
	Elf32_Word sh_type;  //!< Section type
	Elf32_Word sh_flags;  //!< Section flags
	Elf32_Addr sh_addr;  //!< Section virtual addr at execution
	Elf32_Off sh_offset;  //!< Section file offset
	Elf32_Word sh_size;  //!< Section size in bytes
	Elf32_Word sh_link;  //!< Link to another section
	Elf32_Word sh_info;  //!< Additional section information
	Elf32_Word sh_addralign;  //!< Section alignment
	Elf32_Word sh_entsize;  //!< Entry size if section holds table
} Elf32_Shdr;

/** Elf Section Header */
typedef struct _Elf64_Shdr {
	Elf64_Word sh_name;  //!< Section name (string tbl index)
	Elf64_Word sh_type;  //!< Section type
	Elf64_Xword sh_flags;  //!< Section flags
	Elf64_Addr sh_addr;  //!< Section virtual addr at execution
	Elf64_Off sh_offset;  //!< Section file offset
	Elf64_Xword sh_size;  //!< Section size in bytes
	Elf64_Word sh_link;  //!< Link to another section
	Elf64_Word sh_info;  //!< Additional section information
	Elf64_Xword sh_addralign;  //!< Section alignment
	Elf64_Xword sh_entsize;  //!< Entry size if section holds table
} Elf64_Shdr;

// Special Section Indices
/** Undefined section */
#define SHN_UNDEF   0
/** Start of reserved indices */
#define SHN_LORESERVE   0xff00
/** Start of processor-specific */
#define SHN_LOPROC   0xff00
/** Order section before all others (Solaris) */
#define SHN_BEFORE   0xff00
/** Order section after all others (Solaris) */
#define SHN_AFTER   0xff01
/** End of processor-specific */
#define SHN_HIPROC   0xff1f
/** Start of OS-specific */
#define SHN_LOOS   0xff20
/** End of OS-specific */
#define SHN_HIOS   0xff3f
/** Associated symbol is absolute */
#define SHN_ABS   0xfff1
/** Associated symbol is common */
#define SHN_COMMON   0xfff2
/** Index is in extra table */
#define SHN_XINDEX   0xffff
/** End of reserved indices */
#define SHN_HIRESERVE   0xffff
// Legal values for sh_type (section type)
/** Section header table entry unused */
#define SHT_NULL   0
/** Program data */
#define SHT_PROGBITS   1
/** Symbol table */
#define SHT_SYMTAB   2
/** String table */
#define SHT_STRTAB   3
/** Relocation entries with addends */
#define SHT_RELA   4
/** Symbol hash table */
#define SHT_HASH   5
/** Dynamic linking information */
#define SHT_DYNAMIC   6
/** Notes */
#define SHT_NOTE   7
/** Program space with no data (bss) */
#define SHT_NOBITS   8
/** Relocation entries, no addends */
#define SHT_REL   9
/** Reserved */
#define SHT_SHLIB   10
/** Dynamic linker symbol table */
#define SHT_DYNSYM   11
/** Array of constructors */
#define SHT_INIT_ARRAY   14
/** Array of destructors */
#define SHT_FINI_ARRAY   15
/** Array of pre-constructors */
#define SHT_PREINIT_ARRAY 16
/** Section group */
#define SHT_GROUP   17
/** Extended section indeces */
#define SHT_SYMTAB_SHNDX   18
/** Number of defined types */
#define SHT_NUM   19
/** Start OS-specific */
#define SHT_LOOS   0x60000000
/** GNU-style hash table */
#define SHT_GNU_HASH   0x6ffffff6
/** Prelink library list */
#define SHT_GNU_LIBLIST   0x6ffffff7
/** Checksum for DSO content */
#define SHT_CHECKSUM   0x6ffffff8
/** Sun-specific low bound */
#define SHT_LOSUNW   0x6ffffffa
#define SHT_SUNW_move   0x6ffffffa
#define SHT_SUNW_COMDAT   0x6ffffffb
#define SHT_SUNW_syminfo  0x6ffffffc
/** Version definition section */
#define SHT_GNU_verdef   0x6ffffffd
/** Version needs section */
#define SHT_GNU_verneed   0x6ffffffe
/** Version symbol table */
#define SHT_GNU_versym   0x6fffffff
/** Sun-specific high bound */
#define SHT_HISUNW   0x6fffffff
/** End OS-specific type */
#define SHT_HIOS   0x6fffffff
/** Start of processor-specific */
#define SHT_LOPROC   0x70000000
/** End of processor-specific */
#define SHT_HIPROC   0x7fffffff
/** Start of application-specific */
#define SHT_LOUSER   0x80000000
/** End of application-specific */
#define SHT_HIUSER   0x8fffffff
// Legal values for sh_flags (section flags)
/** Writable */
#define SHF_WRITE   (1)
/** Occupies memory during execution */
#define SHF_ALLOC   (2)
/** Executable */
#define SHF_EXECINSTR   (4)
/** Might be merged */
#define SHF_MERGE   (0x10)
/** Contains nul-terminated strings */
#define SHF_STRINGS   (0x20)
/** `sh_info` contains SHT index */
#define SHF_INFO_LINK   (0x40)
/** Preserve order after combining */
#define SHF_LINK_ORDER   (0x80)
/** Non-standard OS specific handling required */
#define SHF_OS_NONCONFORMING (0x100)
/** Section is member of a group */
#define SHF_GROUP   (0x200)
/** Section hold thread-local data */
#define SHF_TLS   (0x400)
/** OS-specific */
#define SHF_MASKOS   (0x0ff00000)
/** Processor-specific */
#define SHF_MASKPROC   (0xf0000000)
/** Special ordering requirement (Solaris) */
#define SHF_ORDERED   (0x40000000)
/** Section is excluded unless referenced or allocated (Solaris) */
#define SHF_EXCLUDE   (0x80000000)
// Section group handling
/** Mark group as COMDAT */
#define GRP_COMDAT   (1)

/** Symbol table entry */
typedef struct _Elf32_Sym {
	Elf32_Word st_name;  //!< Symbol name (string tbl index)
	Elf32_Addr st_value;  //!< Symbol value
	Elf32_Word st_size;  //!< Symbol size
	unsigned char st_info;  //!< Symbol type and binding
	unsigned char st_other;  //!< Symbol visibility
	Elf32_Section st_shndx;  //!< Section index
} Elf32_Sym;

/** Symbol table entry */
typedef struct _Elf64_Sym {
	Elf64_Word st_name;  //!< Symbol name (string tbl index)
	unsigned char st_info;  //!< Symbol type and binding
	unsigned char st_other;  //!< Symbol visibility
	Elf64_Section st_shndx;  //!< Section index
	Elf64_Addr st_value;  //!< Symbol value
	Elf64_Xword st_size;  //!< Symbol size
} Elf64_Sym;

/** The syminfo section (if available) contains additional information about every dynamic symbol */
typedef struct _Elf32_Syminfo {
	Elf32_Half si_boundto;  //!< Direct bindings, symbol bound to
	Elf32_Half si_flags;  //!< Per symbol flags
} Elf32_Syminfo;

/** The syminfo section (if available) contains additional information about every dynamic symbol */
typedef struct _Elf64_Syminfo {
	Elf64_Half si_boundto;  //!< Direct bindings, symbol bound to
	Elf64_Half si_flags;  //!< Per symbol flags
} Elf64_Syminfo;

// Possible values for si_boundto
/** Symbol bound to self */
#define SYMINFO_BT_SELF   0xffff
/** Symbol bound to parent */
#define SYMINFO_BT_PARENT   0xfffe
/** Beginning of reserved entries */
#define SYMINFO_BT_LOWRESERVE   0xff00
// Possible bitmasks for si_flags
/** Direct bound symbol */
#define SYMINFO_FLG_DIRECT   1
/** Pass-thru symbol for translator */
#define SYMINFO_FLG_PASSTHRU   2
/** Symbol is a copy-reloc */
#define SYMINFO_FLG_COPY   4
/** Symbol bound to object to be lazy loaded */
#define SYMINFO_FLG_LAZYLOAD   8
// Syminfo version values
#define SYMINFO_NONE   0
#define SYMINFO_CURRENT   1
#define SYMINFO_NUM   2
// Both Elf32_Sym and Elf64_Sym use the same one-byte st_info field
#define ELF64_ST_BIND(val)   ELF32_ST_BIND(val)
#define ELF64_ST_TYPE(val)   ELF32_ST_TYPE(val)
#define ELF64_ST_INFO(bind, type)   ELF32_ST_INFO((bind), (type))
// Legal values for ST_BIND subfield of st_info (symbol binding)
#define STB_GNU_UNIQUE   10
/** Local symbol */
#define STB_LOCAL   0
/** Global symbol */
#define STB_GLOBAL   1
/** Weak symbol */
#define STB_WEAK   2
#define OK_BINDS   1030
/** Number of defined types */
#define STB_NUM   3
/** Start of OS-specific */
#define STB_LOOS   10
/** End of OS-specific */
#define STB_HIOS   12
/** Start of processor-specific */
#define STB_LOPROC   13
/** End of processor-specific */
#define STB_HIPROC   15
// Legal values for ST_TYPE subfield of st_info (symbol type)
/** Symbol type is unspecified */
#define STT_NOTYPE   0
/** Symbol is a data object */
#define STT_OBJECT   1
/** Symbol is a code object */
#define STT_FUNC   2
/** Symbol associated with a section */
#define STT_SECTION   3
/** Symbol's name is file name */
#define STT_FILE   4
/** Symbol is a common data object */
#define STT_COMMON   5
#define OK_TYPES   39
/** Symbol is thread-local data object */
#define STT_TLS   6
/** Number of defined types */
#define STT_NUM   7
/** Start of OS-specific */
#define STT_LOOS   10
#define STT_GNU_IFUNC   10
/** End of OS-specific */
#define STT_HIOS   12
/** Start of processor-specific */
#define STT_LOPROC   13
/** End of processor-specific */
#define STT_HIPROC   15
/** End of a chain; Symbol table indices are found in the hash buckets and chain table of a symbol hash table section; This special index value indicates the end of a chain, meaning no further symbols are found in that bucket */
#define STN_UNDEF   0

// Symbol visibility specification encoded in the st_other field
/** Default symbol visibility rules */
#define STV_DEFAULT   0
/** Processor specific hidden class */
#define STV_INTERNAL   1
/** Sym unavailable in other modules */
#define STV_HIDDEN   2
/** Not preemptible, not exported */
#define STV_PROTECTED   3

/** Relocation table entry without addend (in section of type SHT_REL) */
typedef struct _Elf32_Rel {
	Elf32_Addr r_offset;  //!< Address
	Elf32_Word r_info;  //!< Relocation type and symbol index
} Elf32_Rel;

/** Relocation table entry without addend (in section of type SHT_REL) */
typedef struct _Elf64_Rel {  //!< Used on Sparc v9, MIPS, and Alpha
	Elf64_Addr r_offset;  //!< Address
	Elf64_Xword r_info;  //!< Relocation type and symbol index
} Elf64_Rel;

/** Relocation table entry with addend (in section of type SHT_RELA) */
typedef struct _Elf32_Rela {
	Elf32_Addr r_offset;  //!< Address
	Elf32_Word r_info;  //!< Relocation type and symbol index
	Elf32_Sword r_addend;  //!< Addend
} Elf32_Rela;

/** Relocation table entry with addend (in section of type SHT_RELA) */
typedef struct _Elf64_Rela {
	Elf64_Addr r_offset;  //!< Address
	Elf64_Xword r_info;  //!< Relocation type and symbol index
	Elf64_Sxword r_addend;  //!< Addend
} Elf64_Rela;

/** Program Segment Header */
typedef struct _Elf32_Phdr {
	Elf32_Word p_type;  //!< Segment type
	Elf32_Off p_offset;  //!< Segment file offset
	Elf32_Addr p_vaddr;  //!< Segment virtual address
	Elf32_Addr p_paddr;  //!< Segment physical address
	Elf32_Word p_filesz;  //!< Segment size in file
	Elf32_Word p_memsz;  //!< Segment size in memory
	Elf32_Word p_flags;  //!< Segment flags
	Elf32_Word p_align;  //!< Segment alignment
} Elf32_Phdr;

/** Program Segment Header */
typedef struct _Elf64_Phdr {
	Elf64_Word p_type;  //!< Segment type
	Elf64_Word p_flags;  //!< Segment flags
	Elf64_Off p_offset;  //!< Segment file offset
	Elf64_Addr p_vaddr;  //!< Segment virtual address
	Elf64_Addr p_paddr;  //!< Segment physical address
	Elf64_Xword p_filesz;  //!< Segment size in file
	Elf64_Xword p_memsz;  //!< Segment size in memory
	Elf64_Xword p_align;  //!< Segment alignment
} Elf64_Phdr;

// Legal values for p_type (segment type)
/** Program header table entry unused */
#define PT_NULL   0
/** Loadable program segment */
#define PT_LOAD   1
/** Dynamic linking information */
#define PT_DYNAMIC   2
/** Program interpreter */
#define PT_INTERP   3
/** Auxiliary information */
#define PT_NOTE   4
/** Reserved */
#define PT_SHLIB   5
/** Entry for header table itself */
#define PT_PHDR   6
/** Thread-local storage segment */
#define PT_TLS   7
/** Number of defined types */
#define PT_NUM   8
/** Start of OS-specific */
#define PT_LOOS   0x60000000
/** GCC .eh_frame_hdr segment */
#define PT_GNU_EH_FRAME   0x6474e550
/** Indicates stack executability */
#define PT_GNU_STACK   0x6474e551
/** Read-only after relocation */
#define PT_GNU_RELRO   0x6474e552
/** Indicates PaX flag markings */
#define PT_PAX_FLAGS   0x65041580
#define PT_LOSUNW   0x6ffffffa
/** Sun Specific segment */
#define PT_SUNWBSS   0x6ffffffa
/** Stack segment */
#define PT_SUNWSTACK   0x6ffffffb
#define PT_HISUNW   0x6fffffff
/** End of OS-specific */
#define PT_HIOS   0x6fffffff
/** Start of processor-specific */
#define PT_LOPROC   0x70000000
/** End of processor-specific */
#define PT_HIPROC   0x7fffffff
// Legal values for note segment descriptor types for core files
/** Contains copy of prstatus struct */
#define NT_PRSTATUS   1
/** Contains copy of fpregset struct */
#define NT_FPREGSET   2
/** Contains copy of prpsinfo struct */
#define NT_PRPSINFO   3
/** Contains copy of prxregset struct */
#define NT_PRXREG   4
/** Contains copy of task structure */
#define NT_TASKSTRUCT   4
/** String from sysinfo(SI_PLATFORM) */
#define NT_PLATFORM   5
/** Contains copy of auxv array */
#define NT_AUXV   6
/** Contains copy of gwindows struct */
#define NT_GWINDOWS   7
/** Contains copy of asrset struct */
#define NT_ASRS   8
/** Contains copy of pstatus struct */
#define NT_PSTATUS   10
/** Contains copy of psinfo struct */
#define NT_PSINFO   13
/** Contains copy of prcred struct */
#define NT_PRCRED   14
/** Contains copy of utsname struct */
#define NT_UTSNAME   15
/** Contains copy of lwpstatus struct */
#define NT_LWPSTATUS   16
/** Contains copy of lwpinfo struct */
#define NT_LWPSINFO   17
/** Contains copy of fprxregset struct */
#define NT_PRFPXREG   20
// Legal values for the note segment descriptor types for object files
/** Contains a version string */
#define NT_VERSION   1

/** Dynamic Section Entry */
typedef struct _Elf32_Dyn {
	Elf32_Sword d_tag;  //!< Dynamic entry type
	union __union_Elf32_Dyn {
		Elf32_Word d_val;  //!< Integer value
		Elf32_Addr d_ptr;  //!< Address value
	} d_un;
} Elf32_Dyn;

/** Dynamic Section Entry */
typedef struct _Elf64_Dyn {
	Elf64_Sxword d_tag;  //!< Dynamic entry type
	union __union_Elf64_Dyn {
		Elf64_Xword d_val;  //!< Integer value
		Elf64_Addr d_ptr;  //!< Address value
	} d_un;
} Elf64_Dyn;

// Legal values for d_tag (dynamic entry type)
/** Marks end of dynamic section */
#define DT_NULL   0
/** Name of needed library */
#define DT_NEEDED   1
/** Size in bytes of PLT relocs */
#define DT_PLTRELSZ   2
/** Processor defined value */
#define DT_PLTGOT   3
/** Address of symbol hash table */
#define DT_HASH   4
/** Address of string table */
#define DT_STRTAB   5
/** Address of symbol table */
#define DT_SYMTAB   6
/** Address of Rela relocs */
#define DT_RELA   7
/** Total size of Rela relocs */
#define DT_RELASZ   8
/** Size of one Rela reloc */
#define DT_RELAENT   9
/** Size of string table */
#define DT_STRSZ   10
/** Size of one symbol table entry */
#define DT_SYMENT   11
/** Address of init function */
#define DT_INIT   12
/** Address of termination function */
#define DT_FINI   13
/** Name of shared object */
#define DT_SONAME   14
/** Library search path (deprecated) */
#define DT_RPATH   15
/** Start symbol search here */
#define DT_SYMBOLIC   16
/** Address of Rel relocs */
#define DT_REL   17
/** Total size of Rel relocs */
#define DT_RELSZ   18
/** Size of one Rel reloc */
#define DT_RELENT   19
/** Type of reloc in PLT */
#define DT_PLTREL   20
/** For debugging; unspecified */
#define DT_DEBUG   21
/** Reloc might modify .text */
#define DT_TEXTREL   22
/** Address of PLT relocs */
#define DT_JMPREL   23
/** Process relocations of object */
#define DT_BIND_NOW   24
/** Array with addresses of init fct */
#define DT_INIT_ARRAY   25
/** Array with addresses of fini fct */
#define DT_FINI_ARRAY   26
/** Size in bytes of DT_INIT_ARRAY */
#define DT_INIT_ARRAYSZ   27
/** Size in bytes of DT_FINI_ARRAY */
#define DT_FINI_ARRAYSZ   28
/** Library search path */
#define DT_RUNPATH   29
/** Flags for the object being loaded */
#define DT_FLAGS   30
/** Start of encoded range */
#define DT_ENCODING   32
/** Array with addresses of preinit fct */
#define DT_PREINIT_ARRAY   32
/** size in bytes of DT_PREINIT_ARRAY */
#define DT_PREINIT_ARRAYSZ   33
/** Number used */
#define DT_NUM   34
/** Start of OS-specific */
#define DT_LOOS   0x6000000d
/** End of OS-specific */
#define DT_HIOS   0x6ffff000
/** Start of processor-specific */
#define DT_LOPROC   0x70000000
/** End of processor-specific */
#define DT_HIPROC   0x7fffffff
/** Most used by any processor */
#define DT_PROCNUM   DT_MIPS_NUM
// DT_* entries which fall between DT_VALRNGHI & DT_VALRNGLO use the Dyn.d_un.d_val field of the Elf*_Dyn structure. This follows Sun's approach
#define DT_VALRNGLO   0x6ffffd00
/** Prelinking timestamp */
#define DT_GNU_PRELINKED   0x6ffffdf5
/** Size of conflict section */
#define DT_GNU_CONFLICTSZ   0x6ffffdf6
/** Size of library list */
#define DT_GNU_LIBLISTSZ   0x6ffffdf7
#define DT_CHECKSUM   0x6ffffdf8
#define DT_PLTPADSZ   0x6ffffdf9
#define DT_MOVEENT   0x6ffffdfa
#define DT_MOVESZ   0x6ffffdfb
/** Feature selection (DTF_*) */
#define DT_FEATURE_1   0x6ffffdfc
/** Flags for DT_* entries, effecting the following DT_* entry */
#define DT_POSFLAG_1   0x6ffffdfd
/** Size of syminfo table (in bytes) */
#define DT_SYMINSZ   0x6ffffdfe
/** Entry size of syminfo */
#define DT_SYMINENT   0x6ffffdff
#define DT_VALRNGHI   0x6ffffdff
/** Reverse order */
#define DT_VALTAGIDX(tag)   (DT_VALRNGHI - (tag))
#define DT_VALNUM   12
// DT_* entries which fall between DT_ADDRRNGHI & DT_ADDRRNGLO use the Dyn.d_un.d_ptr field of the Elf*_Dyn structure. If any adjustment is made to the ELF object after it has been built these entries will need to be adjusted
#define DT_ADDRRNGLO   0x6ffffe00
/** GNU-style hash table */
#define DT_GNU_HASH   0x6ffffef5
/** Start of conflict section */
#define DT_GNU_CONFLICT   0x6ffffef8
/** Library list */
#define DT_GNU_LIBLIST   0x6ffffef9
/** Configuration information */
#define DT_CONFIG   0x6ffffefa
/** Dependency auditing */
#define DT_DEPAUDIT   0x6ffffefb
/** Object auditing */
#define DT_AUDIT   0x6ffffefc
/** PLT padding */
#define DT_PLTPAD   0x6ffffefd
/** Move table */
#define DT_MOVETAB   0x6ffffefe
/** Syminfo table */
#define DT_SYMINFO   0x6ffffeff
#define DT_ADDRRNGHI   0x6ffffeff
/** Reverse order */
#define DT_ADDRTAGIDX(tag)   (DT_ADDRRNGHI - (tag))
#define DT_ADDRNUM   10
// The versioning entry types
// GNU Extensions
#define DT_VERSYM   0x6ffffff0
#define DT_RELACOUNT   0x6ffffff9
#define DT_RELCOUNT   0x6ffffffa
// These were chosen by Sun
/** State flags, see DF_1_* below */
#define DT_FLAGS_1   0x6ffffffb
/** Address of version definition table */
#define DT_VERDEF   0x6ffffffc
/** Number of version definitions */
#define DT_VERDEFNUM   0x6ffffffd
/** Address of table with needed versions */
#define DT_VERNEED   0x6ffffffe
/** Number of needed versions */
#define DT_VERNEEDNUM   0x6fffffff
/** Reverse order! */
#define DT_VERSIONTAGIDX(tag)   (DT_VERNEEDNUM - (tag))
#define DT_VERSIONTAGNUM   16
// Sun added these machine-independent extensions in the "processor-specific" range
#define DT_AUXILIARY   0x7ffffffd  /* Shared object to load before self */
#define DT_FILTER   0x7fffffff  /* Shared object to get values from */
#define DT_EXTRATAGIDX(tag)   ((Elf32_Word) - ((Elf32_Sword)(tag) << 1 >> 1) - 1)
#define DT_EXTRANUM   3
// Values of `d_un.d_val` in the DT_FLAGS entry
/** Object may use DF_ORIGIN */
#define DF_ORIGIN   1
/** Symbol resolutions starts here */
#define DF_SYMBOLIC   2
/** Object contains text relocations */
#define DF_TEXTREL   4
/** No lazy binding for this object */
#define DF_BIND_NOW   8
/** Module uses the static TLS model */
#define DF_STATIC_TLS   0x10
// State flags selectable in the `d_un.d_val` element of the DT_FLAGS_1 entry in the dynamic section
/** Set RTLD_NOW for this object */
#define DF_1_NOW   1
/** Set RTLD_GLOBAL for this object */
#define DF_1_GLOBAL   2
/** Set RTLD_GROUP for this object */
#define DF_1_GROUP   4
/** Set RTLD_NODELETE for this object */
#define DF_1_NODELETE   8
/** Trigger filtee loading at runtime */
#define DF_1_LOADFLTR   0x10
/** Set RTLD_INITFIRST for this object*/
#define DF_1_INITFIRST   0x20
/** Set RTLD_NOOPEN for this object */
#define DF_1_NOOPEN   0x40
/** $ORIGIN must be handled */
#define DF_1_ORIGIN   0x80
/** Direct binding enabled */
#define DF_1_DIRECT   0x100
#define DF_1_TRANS   0x200
/** Object is used to interpose */
#define DF_1_INTERPOSE   0x400
/** Ignore default lib search path */
#define DF_1_NODEFLIB   0x800
/** Object cannot be dldumped */
#define DF_1_NODUMP   0x1000
/** Configuration alternative created */
#define DF_1_CONFALT   0x2000
/** Filtee terminates filters search */
#define DF_1_ENDFILTEE   0x4000
/** Disp reloc applied at build time */
#define DF_1_DISPRELDNE   0x8000
/** Disp reloc applied at run-time */
#define DF_1_DISPRELPND   0x10000
// Flags for the feature selection in DT_FEATURE_1
#define DTF_1_PARINIT   1
#define DTF_1_CONFEXP   2
// Flags in the DT_POSFLAG_1 entry effecting only the next DT_* entry
/** Lazyload following object */
#define DF_P1_LAZYLOAD   1
/** Symbols from next object are not generally available */
#define DF_P1_GROUPPERM   2

/** Version Definition Section */
typedef struct _Elf32_Verdef {
	Elf32_Half vd_version;  //!< Version revision
	Elf32_Half vd_flags;  //!< Version information
	Elf32_Half vd_ndx;  //!< Version Index
	Elf32_Half vd_cnt;  //!< Number of associated aux entries
	Elf32_Word vd_hash;  //!< Version name hash value
	Elf32_Word vd_aux;  //!< Offset in bytes to verdaux array
	Elf32_Word vd_next;  //!< Offset in bytes to next verdef entry
} Elf32_Verdef;

/** Version Definition Section */
typedef struct _Elf64_Verdef {
	Elf64_Half vd_version;  //!< Version revision
	Elf64_Half vd_flags;  //!< Version information
	Elf64_Half vd_ndx;  //!< Version Index
	Elf64_Half vd_cnt;  //!< Number of associated aux entries
	Elf64_Word vd_hash;  //!< Version name hash value
	Elf64_Word vd_aux;  //!< Offset in bytes to verdaux array
	Elf64_Word vd_next;  //!< Offset in bytes to next verdef entry
} Elf64_Verdef;

// Legal values for vd_version (version revision)
/** No version */
#define VER_DEF_NONE   0
/** Current version */
#define VER_DEF_CURRENT   1
/** Given version number */
#define VER_DEF_NUM   2
// Legal values for vd_flags (version information flags)
/** Version definition of file itself */
#define VER_FLG_BASE   1
/** Weak version identifier */
#define VER_FLG_WEAK   2
// Versym symbol index values
/** Symbol is local */
#define VER_NDX_LOCAL   0
/** Symbol is global */
#define VER_NDX_GLOBAL   1
/** Beginning of reserved entries */
#define VER_NDX_LORESERVE   0xff00
/** Symbol is to be eliminated */
#define VER_NDX_ELIMINATE   0xff01

/** Auxialiary Version Information */
typedef struct _Elf32_Verdaux {
	Elf32_Word vda_name;  //!< Version or dependency names
	Elf32_Word vda_next;  //!< Offset in bytes to next verdaux entry
} Elf32_Verdaux;

/** Auxialiary Version Information */
typedef struct _Elf64_Verdaux {
	Elf64_Word vda_name;  //!< Version or dependency names
	Elf64_Word vda_next;  //!< Offset in bytes to next verdaux entry
} Elf64_Verdaux;

/** Version Dependency Section */
typedef struct _Elf32_Verneed {
	Elf32_Half vn_version;  //!< Version of structure
	Elf32_Half vn_cnt;  //!< Number of associated aux entries
	Elf32_Word vn_file;  //!< Offset of filename for this dependency
	Elf32_Word vn_aux;  //!< Offset in bytes to vernaux array
	Elf32_Word vn_next;  //!< Offset in bytes to next verneed entry
} Elf32_Verneed;

/** Version Dependency Section */
typedef struct _Elf64_Verneed {
	Elf64_Half vn_version;  //!< Version of structure
	Elf64_Half vn_cnt;  //!< Number of associated aux entries
	Elf64_Word vn_file;  //!< Offset of filename for this dependency
	Elf64_Word vn_aux;  //!< Offset in bytes to vernaux array
	Elf64_Word vn_next;  //!< Offset in bytes to next verneed entry
} Elf64_Verneed;

// Legal values for vn_version (version revision)
/** No version */
#define VER_NEED_NONE   (0)
/** Current version */
#define VER_NEED_CURRENT   (1)
/** Given version number */
#define VER_NEED_NUM   (2)

/** Auxiliary Needed Version Information */
typedef struct _Elf32_Vernaux {
	Elf32_Word vna_hash;  //!< Hash value of dependency name
	Elf32_Half vna_flags;  //!< Dependency specific information
	Elf32_Half vna_other;  //!< Unused
	Elf32_Word vna_name;  //!< Dependency name string offset
	Elf32_Word vna_next;  //!< Offset in bytes to next vernaux entry
} Elf32_Vernaux;

/** Auxiliary Needed Version Information */
typedef struct _Elf64_Vernaux {
	Elf64_Word vna_hash;  //!< Hash value of dependency name
	Elf64_Half vna_flags;  //!< Dependency specific information
	Elf64_Half vna_other;  //!< Unused
	Elf64_Word vna_name;  //!< Dependency name string offset
	Elf64_Word vna_next;  //!< Offset in bytes to next vernaux entry
} Elf64_Vernaux;

/** Auxiliary Vector */
typedef struct Elf32_auxv {
	uint32_t a_type;  //!< Entry type
	union __union_Elf32_auxv {
		uint32_t a_val;  //!< Integer value
	} a_un;
} Elf32_auxv_t;

/** Auxiliary Vector */
typedef struct Elf64_auxv {
	uint64_t a_type;  //!< Entry type
	union __union_Elf64_auxv {
		uint64_t a_val;  //!< Integer value
	} a_un;
} Elf64_auxv_t;

// Legal values for a_type (entry type)
/** End of vector */
#define AT_NULL   0
/** Entry should be ignored */
#define AT_IGNORE   1
/** File descriptor of program */
#define AT_EXECFD   2
/** Program headers for program */
#define AT_PHDR   3
/** Size of program header entry */
#define AT_PHENT   4
/** Number of program headers */
#define AT_PHNUM   5
/** System page size */
#define AT_PAGESZ   6
/** Base address of interpreter */
#define AT_BASE   7
/** Flags */
#define AT_FLAGS   8
/** Entry point of program */
#define AT_ENTRY   9
/** Program is not ELF */
#define AT_NOTELF   10
/** Real uid */
#define AT_UID   11
/** Effective uid */
#define AT_EUID   12
/** Real gid */
#define AT_GID   13
/** Effective gid */
#define AT_EGID   14
/** Frequency of times() */
#define AT_CLKTCK   17
// Some more special a_type values describing the hardware
/** String identifying platform */
#define AT_PLATFORM   15
/** Machine dependent hints about processor capabilities */
#define AT_HWCAP   16
/** FPU control word; This entry gives some information about the FPU initialization performed by the kernel */
#define AT_FPUCW   18
// Cache Block Sizes
/** Data cache block size */
#define AT_DCACHEBSIZE   19
/** Instruction cache block size */
#define AT_ICACHEBSIZE   20
/** Unified cache block size */
#define AT_UCACHEBSIZE   21
// A special ignored value for PPC, used by the kernel to control the interpretation of the AUXV. Must be > 16
/** Entry should be ignored */
#define AT_IGNOREPPC   22
/** Boolean (was exec setuid-like) */
#define AT_SECURE   23
// Pointer to the global system page used for system calls
#define AT_SYSINFO   32
#define AT_SYSINFO_EHDR   33
// Shapes of the caches; Bits 0-3 contains associativity; bits 4-7 contains log2 of line size; mask those to get cache size
#define AT_L1I_CACHESHAPE   34
#define AT_L1D_CACHESHAPE   35
#define AT_L2_CACHESHAPE   36
#define AT_L3_CACHESHAPE   37

/** Note Section Contents; Each entry in the note section begins with a header of a fixed form */
typedef struct _Elf32_Nhdr {
	Elf32_Word n_namesz;  //!< Length of the note's name
	Elf32_Word n_descsz;  //!< Length of the note's descriptor
	Elf32_Word n_type;  //!< Type of the note
} Elf32_Nhdr;

typedef struct _Elf64_Nhdr {
	Elf64_Word n_namesz;  //!< Length of the note's name
	Elf64_Word n_descsz;  //!< Length of the note's descriptor
	Elf64_Word n_type;  //!< Type of the note
} Elf64_Nhdr;

// Known Names of Notes
/** Solaris entries in the note section have this name */
#define ELF_NOTE_SOLARIS   "SUNW Solaris"
/** Note entries for GNU systems have this name */
#define ELF_NOTE_GNU   "GNU"
// Defined Types of Notes for Solaris
/** Value of descriptor (one word) is desired pagesize for the binary */
#define ELF_NOTE_PAGESIZE_HINT   1
// Defined Note Types for GNU Systems
/** ABI information
The descriptor consists of words:
 - word 0: OS descriptor
 - word 1: major version of the ABI
 - word 2: minor version of the ABI
 - word 3: subminor version of the ABI
*/
#define ELF_NOTE_ABI   1
// Known OSes; These value can appear in word 0 of an ELF_NOTE_ABI note section entry
#define ELF_NOTE_OS_LINUX   0
#define ELF_NOTE_OS_GNU   1
#define ELF_NOTE_OS_SOLARIS2   2
#define ELF_NOTE_OS_FREEBSD   3

/** Move records */
typedef struct attr_packed _Elf32_Move {
	Elf32_Xword m_value;  //!< Symbol value
	Elf32_Word m_info;  //!< Size and index
	Elf32_Word m_poffset;  //!< Symbol offset
	Elf32_Half m_repeat;  //!< Repeat count
	Elf32_Half m_stride;  //!< Stride info
} Elf32_Move;

typedef struct attr_packed _Elf64_Move {
	Elf64_Xword m_value;  //!< Symbol value
	Elf64_Xword m_info;  //!< Size and index
	Elf64_Xword m_poffset;  //!< Symbol offset
	Elf64_Half m_repeat;  //!< Repeat count
	Elf64_Half m_stride;  //!< Stride info
} Elf64_Move;

/* MOTOROLA 68K SPECIFIC DEFINITIONS */
// Values for Elf32_Ehdr.e_flags
#define EF_CPU32   0x810000
/* M68K RELOCATIONS */
/** No reloc */
#define R_68K_NONE   0
/** Direct 32 bit */
#define R_68K_32   1
/** Direct 16 bit */
#define R_68K_16   2
/** Direct 8 bit */
#define R_68K_8   3
/** PC relative 32 bit */
#define R_68K_PC32   4
/** PC relative 16 bit */
#define R_68K_PC16   5
/** PC relative 8 bit */
#define R_68K_PC8   6
/** 32 bit PC relative GOT entry */
#define R_68K_GOT32   7
/** 16 bit PC relative GOT entry */
#define R_68K_GOT16   8
/** 8 bit PC relative GOT entry */
#define R_68K_GOT8   9
/** 32 bit GOT offset */
#define R_68K_GOT32O   10
/** 16 bit GOT offset */
#define R_68K_GOT16O   11
/** 8 bit GOT offset */
#define R_68K_GOT8O   12
/** 32 bit PC relative PLT address */
#define R_68K_PLT32   13
/** 16 bit PC relative PLT address */
#define R_68K_PLT16   14
/** 8 bit PC relative PLT address */
#define R_68K_PLT8   15
/** 32 bit PLT offset */
#define R_68K_PLT32O   16
/** 16 bit PLT offset */
#define R_68K_PLT16O   17
/** 8 bit PLT offset */
#define R_68K_PLT8O   18
/** Copy symbol at runtime */
#define R_68K_COPY   19
/** Create GOT entry */
#define R_68K_GLOB_DAT   20
/** Create PLT entry */
#define R_68K_JMP_SLOT   21
/** Adjust by program base */
#define R_68K_RELATIVE   22
#define R_68K_NUM   23

/* INTEL 80386 SPECIFIC DEFINITIONS */
/* I386 RELOCATIONS */
/** No reloc */
#define R_386_NONE   0
/** Direct 32 bit */
#define R_386_32   1
/** PC relative 32 bit */
#define R_386_PC32   2
/** 32 bit GOT entry */
#define R_386_GOT32   3
/** 32 bit PLT address */
#define R_386_PLT32   4
/** Copy symbol at runtime */
#define R_386_COPY   5
/** Create GOT entry */
#define R_386_GLOB_DAT   6
/** Create PLT entry */
#define R_386_JMP_SLOT   7
/** Adjust by program base */
#define R_386_RELATIVE   8
/** 32 bit offset to GOT */
#define R_386_GOTOFF   9
/** 32 bit PC relative offset to GOT */
#define R_386_GOTPC   10
#define R_386_32PLT   11
/** Offset in static TLS block */
#define R_386_TLS_TPOFF   14
/** Address of GOT entry for static TLS block offset */
#define R_386_TLS_IE   15
/** GOT entry for static TLS block offset */
#define R_386_TLS_GOTIE   16
/** Offset relative to static TLS block */
#define R_386_TLS_LE   17
/** Direct 32 bit for GNU version of general dynamic thread local data */
#define R_386_TLS_GD   18
/** Direct 32 bit for GNU version of local dynamic thread local data in LE code */
#define R_386_TLS_LDM   19
#define R_386_16   20
#define R_386_PC16   21
#define R_386_8   22
#define R_386_PC8   23
/** Direct 32 bit for general dynamic thread local data */
#define R_386_TLS_GD_32   24
/** Tag for pushl in GD TLS code */
#define R_386_TLS_GD_PUSH   25
/** Relocation for call to __tls_get_addr() */
#define R_386_TLS_GD_CALL   26
/** Tag for popl in GD TLS code */
#define R_386_TLS_GD_POP   27
/** Direct 32 bit for local dynamic thread local data in LE code */
#define R_386_TLS_LDM_32   28
/** Tag for pushl in LDM TLS code */
#define R_386_TLS_LDM_PUSH   29
/** Relocation for call to __tls_get_addr() in LDM code */
#define R_386_TLS_LDM_CALL   30
/** Tag for popl in LDM TLS code */
#define R_386_TLS_LDM_POP   31
/** Offset relative to TLS block */
#define R_386_TLS_LDO_32   32
/** GOT entry for negated static TLS block offset */
#define R_386_TLS_IE_32   33
/** Negated offset relative to static TLS block */
#define R_386_TLS_LE_32   34
/** ID of module containing symbol */
#define R_386_TLS_DTPMOD32   35
/** Offset in TLS block */
#define R_386_TLS_DTPOFF32   36
/** Negated offset in static TLS block */
#define R_386_TLS_TPOFF32   37
#define R_386_NUM   38

/* BLACKFIN SPECIFIC DEFINITIONS */
#define R_BFIN_UNUSED0   0
#define R_BFIN_PCREL5M2   1
#define R_BFIN_UNUSED1   2
#define R_BFIN_PCREL10   3
#define R_BFIN_PCREL12_JUMP   4
#define R_BFIN_RIMM16   5
#define R_BFIN_LUIMM16   6
#define R_BFIN_HUIMM16   7
#define R_BFIN_PCREL12_JUMP_S   8
#define R_BFIN_PCREL24_JUMP_X   9
#define R_BFIN_PCREL24   0xa
#define R_BFIN_UNUSEDB   0xb
#define R_BFIN_UNUSEDC   0xc
#define R_BFIN_PCREL24_JUMP_L   0xd
#define R_BFIN_PCREL24_CALL_X   0xe
#define R_BFIN_var_eq_symb   0xf
#define R_BFIN_BYTE_DATA   0x10
#define R_BFIN_BYTE2_DATA   0x11
#define R_BFIN_BYTE4_DATA   0x12
#define R_BFIN_PCREL11   0x13
#define R_BFIN_GOT17M4   0x14
#define R_BFIN_GOTHI   0x15
#define R_BFIN_GOTLO   0x16
#define R_BFIN_FUNCDESC   0x17
#define R_BFIN_FUNCDESC_GOT17M4   0x18
#define R_BFIN_FUNCDESC_GOTHI   0x19
#define R_BFIN_FUNCDESC_GOTLO   0x1a
#define R_BFIN_FUNCDESC_VALUE   0x1b
#define R_BFIN_FUNCDESC_GOTOFF17M4   0x1c
#define R_BFIN_FUNCDESC_GOTOFFHI   0x1d
#define R_BFIN_FUNCDESC_GOTOFFLO   0x1e
#define R_BFIN_GOTOFF17M4   0x1f
#define R_BFIN_GOTOFFHI   0x20
#define R_BFIN_GOTOFFLO   0x21
#define EF_BFIN_PIC   1
#define EF_BFIN_FDPIC   2
#define EF_BFIN_CODE_IN_L1   0x10
#define EF_BFIN_DATA_IN_L1   0x20

/* FR-V SPECIFIC DEFINITIONS */
/** No reloc */
#define R_FRV_NONE   0
/** Direct 32 bit */
#define R_FRV_32   1
/** Canonical function descriptor address */
#define R_FRV_FUNCDESC   14
/** Private function descriptor initialization */
#define R_FRV_FUNCDESC_VALUE   18
// gpr support
/** mask for # of gprs */
#define EF_FRV_GPR_MASK   3
/** -mgpr-32 */
#define EF_FRV_GPR_32   1
/** -mgpr-64 */
#define EF_FRV_GPR_64   2
// fpr support
/** mask for # of fprs */
#define EF_FRV_FPR_MASK   0xc
/** -mfpr-32 */
#define EF_FRV_FPR_32   4
/** -mfpr-64 */
#define EF_FRV_FPR_64   8
/** -msoft-float */
#define EF_FRV_FPR_NONE   0xc
#define EF_FRV_PIC   0x100
#define EF_FRV_FDPIC   0x8000

/* SUN SPARC SPECIFIC DEFINITIONS */
// Legal values for ST_TYPE subfield of st_info (symbol type)
/** Global register reserved to app */
#define STT_SPARC_REGISTER   13
// Values for Elf64_Ehdr.e_flags
#define EF_SPARCV9_MM   3
#define EF_SPARCV9_TSO   0
#define EF_SPARCV9_PSO   1
#define EF_SPARCV9_RMO   2
/** Little endian data */
#define EF_SPARC_LEDATA   0x800000
#define EF_SPARC_EXT_MASK   0xffff00
/** Generic V8+ features */
#define EF_SPARC_32PLUS   0x100
/** Sun UltraSPARC1 extensions */
#define EF_SPARC_SUN_US1   0x200
/** HAL R1 extensions */
#define EF_SPARC_HAL_R1   0x400
/** Sun UltraSPARCIII extensions */
#define EF_SPARC_SUN_US3   0x800

/* SPARC RELOCATIONS */
/** No reloc */
#define R_SPARC_NONE   0
/** Direct 8 bit */
#define R_SPARC_8   1
/** Direct 16 bit */
#define R_SPARC_16   2
/** Direct 32 bit */
#define R_SPARC_32   3
/** PC relative 8 bit */
#define R_SPARC_DISP8   4
/** PC relative 16 bit */
#define R_SPARC_DISP16   5
/** PC relative 32 bit */
#define R_SPARC_DISP32   6
/** PC relative 30 bit shifted */
#define R_SPARC_WDISP30   7
/** PC relative 22 bit shifted */
#define R_SPARC_WDISP22   8
/** High 22 bit */
#define R_SPARC_HI22   9
/** Direct 22 bit */
#define R_SPARC_22   10
/** Direct 13 bit */
#define R_SPARC_13   11
/** Truncated 10 bit */
#define R_SPARC_LO10   12
/** Truncated 10 bit GOT entry */
#define R_SPARC_GOT10   13
/** 13 bit GOT entry */
#define R_SPARC_GOT13   14
/** 22 bit GOT entry shifted */
#define R_SPARC_GOT22   15
/** PC relative 10 bit truncated */
#define R_SPARC_PC10   16
/** PC relative 22 bit shifted */
#define R_SPARC_PC22   17
/** 30 bit PC relative PLT address */
#define R_SPARC_WPLT30   18
/** Copy symbol at runtime */
#define R_SPARC_COPY   19
/** Create GOT entry */
#define R_SPARC_GLOB_DAT   20
/** Create PLT entry */
#define R_SPARC_JMP_SLOT   21
/** Adjust by program base */
#define R_SPARC_RELATIVE   22
/** Direct 32 bit unaligned */
#define R_SPARC_UA32   23

/* ADDITIONAL SPARC64 RELOCATIONS */
/** Direct 32 bit ref to PLT entry */
#define R_SPARC_PLT32   24
/** High 22 bit PLT entry */
#define R_SPARC_HIPLT22   25
/** Truncated 10 bit PLT entry */
#define R_SPARC_LOPLT10   26
/** PC rel 32 bit ref to PLT entry */
#define R_SPARC_PCPLT32   27
/** PC rel high 22 bit PLT entry */
#define R_SPARC_PCPLT22   28
/** PC rel trunc 10 bit PLT entry */
#define R_SPARC_PCPLT10   29
/** Direct 10 bit */
#define R_SPARC_10   30
/** Direct 11 bit */
#define R_SPARC_11   31
/** Direct 64 bit */
#define R_SPARC_64   32
/** 10bit with secondary 13bit addend */
#define R_SPARC_OLO10   33
/** Top 22 bits of direct 64 bit */
#define R_SPARC_HH22   34
/** High middle 10 bits */
#define R_SPARC_HM10   35
/** Low middle 22 bits */
#define R_SPARC_LM22   36
/** Top 22 bits of pc rel 64 bit */
#define R_SPARC_PC_HH22   37
/** High middle 10 bit */
#define R_SPARC_PC_HM10   38
/** Low miggle 22 bits */
#define R_SPARC_PC_LM22   39
/** PC relative 16 bit shifted */
#define R_SPARC_WDISP16   40
/** PC relative 19 bit shifted */
#define R_SPARC_WDISP19   41
/** Direct 7 bit */
#define R_SPARC_7   43
/** Direct 5 bit */
#define R_SPARC_5   44
/** Direct 6 bit */
#define R_SPARC_6   45
/** PC relative 64 bit */
#define R_SPARC_DISP64   46
/** Direct 64 bit ref to PLT entry */
#define R_SPARC_PLT64   47
/** High 22 bit complemented */
#define R_SPARC_HIX22   48
/** Truncated 11 bit complemented */
#define R_SPARC_LOX10   49
/** Direct high 12 of 44 bit */
#define R_SPARC_H44   50
/** Direct mid 22 of 44 bit */
#define R_SPARC_M44   51
/** Direct low 10 of 44 bit */
#define R_SPARC_L44   52
/** Global register usage */
#define R_SPARC_REGISTER   53
/** Direct 64 bit unaligned */
#define R_SPARC_UA64   54
/** Direct 16 bit unaligned */
#define R_SPARC_UA16   55
#define R_SPARC_TLS_GD_HI22   56
#define R_SPARC_TLS_GD_LO10   57
#define R_SPARC_TLS_GD_ADD   58
#define R_SPARC_TLS_GD_CALL   59
#define R_SPARC_TLS_LDM_HI22   60
#define R_SPARC_TLS_LDM_LO10   61
#define R_SPARC_TLS_LDM_ADD   62
#define R_SPARC_TLS_LDM_CALL   63
#define R_SPARC_TLS_LDO_HIX22   64
#define R_SPARC_TLS_LDO_LOX10   65
#define R_SPARC_TLS_LDO_ADD   66
#define R_SPARC_TLS_IE_HI22   67
#define R_SPARC_TLS_IE_LO10   68
#define R_SPARC_TLS_IE_LD   69
#define R_SPARC_TLS_IE_LDX   70
#define R_SPARC_TLS_IE_ADD   71
#define R_SPARC_TLS_LE_HIX22   72
#define R_SPARC_TLS_LE_LOX10   73
#define R_SPARC_TLS_DTPMOD32   74
#define R_SPARC_TLS_DTPMOD64   75
#define R_SPARC_TLS_DTPOFF32   76
#define R_SPARC_TLS_DTPOFF64   77
#define R_SPARC_TLS_TPOFF32   78
#define R_SPARC_TLS_TPOFF64   79
#define R_SPARC_NUM   80
// For Sparc64, legal values for d_tag of Elf64_Dyn
#define DT_SPARC_REGISTER   0x70000001
#define DT_SPARC_NUM   2
// Bits present in AT_HWCAP, primarily for Sparc32
/** CPU supports flush insn */
#define HWCAP_SPARC_FLUSH   1
#define HWCAP_SPARC_STBAR   2
#define HWCAP_SPARC_SWAP   4
#define HWCAP_SPARC_MULDIV   8
/** The cpu is v9, so v8plus is ok */
#define HWCAP_SPARC_V9   16
#define HWCAP_SPARC_ULTRA3   32

/* MIPS R3000 SPECIFIC DEFINITIONS */
// Legal values for e_flags field of Elf32_Ehdr
/** A .noreorder directive was used */
#define EF_MIPS_NOREORDER   1
/** Contains PIC code */
#define EF_MIPS_PIC   2
/** Uses PIC calling sequence */
#define EF_MIPS_CPIC   4
#define EF_MIPS_XGOT   8
#define EF_MIPS_64BIT_WHIRL 16
#define EF_MIPS_ABI2   32
#define EF_MIPS_ABI_ON32   64
/** MIPS architecture level */
#define EF_MIPS_ARCH   0xf0000000
// Legal values for MIPS architecture level
/** -mips1 code */
#define EF_MIPS_ARCH_1   0
/** -mips2 code */
#define EF_MIPS_ARCH_2   0x10000000
/** -mips3 code */
#define EF_MIPS_ARCH_3   0x20000000
/** -mips4 code */
#define EF_MIPS_ARCH_4   0x30000000
/** -mips5 code */
#define EF_MIPS_ARCH_5   0x40000000
/** MIPS32 code */
#define EF_MIPS_ARCH_32   0x60000000
/** MIPS64 code */
#define EF_MIPS_ARCH_64   0x70000000
// The following are non-official names and should not be used
/** -mips1 code */
#define E_MIPS_ARCH_1   0
/** -mips2 code */
#define E_MIPS_ARCH_2   0x10000000
/** -mips3 code */
#define E_MIPS_ARCH_3   0x20000000
/** -mips4 code */
#define E_MIPS_ARCH_4   0x30000000
/** -mips5 code */
#define E_MIPS_ARCH_5   0x40000000
/** MIPS32 code */
#define E_MIPS_ARCH_32   0x60000000
/** MIPS64 code */
#define E_MIPS_ARCH_64   0x70000000
// Special section indices
/** Allocated common symbols */
#define SHN_MIPS_ACOMMON   0xff00
/** Allocated test symbols */
#define SHN_MIPS_TEXT   0xff01
/** Allocated data symbols */
#define SHN_MIPS_DATA   0xff02
/** Small common symbols */
#define SHN_MIPS_SCOMMON   0xff03
/** Small undefined symbols */
#define SHN_MIPS_SUNDEFINED   0xff04
// Legal values for sh_type field of Elf32_Shdr
/** Shared objects used in link */
#define SHT_MIPS_LIBLIST   0x70000000
#define SHT_MIPS_MSYM   0x70000001
/** Conflicting symbols */
#define SHT_MIPS_CONFLICT   0x70000002
/** Global data area sizes */
#define SHT_MIPS_GPTAB   0x70000003
/** Reserved for SGI/MIPS compilers */
#define SHT_MIPS_UCODE   0x70000004
/** MIPS ECOFF debugging information */
#define SHT_MIPS_DEBUG   0x70000005
/** Register usage information */
#define SHT_MIPS_REGINFO   0x70000006
#define SHT_MIPS_PACKAGE   0x70000007
#define SHT_MIPS_PACKSYM   0x70000008
#define SHT_MIPS_RELD   0x70000009
#define SHT_MIPS_IFACE   0x7000000b
#define SHT_MIPS_CONTENT   0x7000000c
/** Miscellaneous options */
#define SHT_MIPS_OPTIONS   0x7000000d
#define SHT_MIPS_SHDR   0x70000010
#define SHT_MIPS_FDESC   0x70000011
#define SHT_MIPS_EXTSYM   0x70000012
#define SHT_MIPS_DENSE   0x70000013
#define SHT_MIPS_PDESC   0x70000014
#define SHT_MIPS_LOCSYM   0x70000015
#define SHT_MIPS_AUXSYM   0x70000016
#define SHT_MIPS_OPTSYM   0x70000017
#define SHT_MIPS_LOCSTR   0x70000018
#define SHT_MIPS_LINE   0x70000019
#define SHT_MIPS_RFDESC   0x7000001a
#define SHT_MIPS_DELTASYM   0x7000001b
#define SHT_MIPS_DELTAINST   0x7000001c
#define SHT_MIPS_DELTACLASS   0x7000001d
/** DWARF debugging information */
#define SHT_MIPS_DWARF   0x7000001e
#define SHT_MIPS_DELTADECL   0x7000001f
#define SHT_MIPS_SYMBOL_LIB   0x70000020
/** Event section */
#define SHT_MIPS_EVENTS   0x70000021
#define SHT_MIPS_TRANSLATE   0x70000022
#define SHT_MIPS_PIXIE   0x70000023
#define SHT_MIPS_XLATE   0x70000024
#define SHT_MIPS_XLATE_DEBUG   0x70000025
#define SHT_MIPS_WHIRL   0x70000026
#define SHT_MIPS_EH_REGION   0x70000027
#define SHT_MIPS_XLATE_OLD   0x70000028
#define SHT_MIPS_PDR_EXCEPTION 0x70000029
// Legal values for sh_flags field of Elf32_Shdr
/** Must be part of global data area */
#define SHF_MIPS_GPREL   0x10000000
#define SHF_MIPS_MERGE   0x20000000
#define SHF_MIPS_ADDR   0x40000000
#define SHF_MIPS_STRINGS   0x80000000
#define SHF_MIPS_NOSTRIP   0x8000000
#define SHF_MIPS_LOCAL   0x4000000
#define SHF_MIPS_NAMES   0x2000000
#define SHF_MIPS_NODUPE   0x1000000
// Symbol tables
// MIPS specific values for `st_other`
#define STO_MIPS_DEFAULT   0
#define STO_MIPS_INTERNAL   1
#define STO_MIPS_HIDDEN   2
#define STO_MIPS_PROTECTED   3
#define STO_MIPS_PLT   8
#define STO_MIPS_SC_ALIGN_UNUSED   0xff
// MIPS specific values for `st_info`
#define STB_MIPS_SPLIT_COMMON   13

/** Entries found in sections of type SHT_MIPS_GPTAB */
typedef union _Elf32_gptab {
	struct {
		Elf32_Word gt_current_g_value;  //!< -G value used for compilation
		Elf32_Word gt_unused;  //!< Not used
	} gt_header;  //!< First entry in section
	struct {
		Elf32_Word gt_g_value;  //!< If this value were used for -G
		Elf32_Word gt_bytes;  //!< This many bytes would be used
	} gt_entry;  //!< Subsequent entries in section
} Elf32_gptab;

/** Entry found in sections of type SHT_MIPS_REGINFO */
typedef struct _Elf32_RegInfo {
	Elf32_Word ri_gprmask;  //!< General registers used
	Elf32_Word ri_cprmask[4];  //!< Coprocessor registers used
	Elf32_Sword ri_gp_value;  //!< $gp register value
} Elf32_RegInfo;

/** Entries found in sections of type SHT_MIPS_OPTIONS */
typedef struct _Elf_Options {
	unsigned char kind;  //!< Determines interpretation of the variable part of descriptor
	unsigned char size;  //!< Size of descriptor, including header
	Elf32_Section section;  //!< Section header index of section affected, 0 for global options
	Elf32_Word info;  //!< Kind-specific information
} Elf_Options;

// Values for `kind` field in Elf_Options
/** Undefined */
#define ODK_NULL   0
/** Register usage information */
#define ODK_REGINFO   1
/** Exception processing options */
#define ODK_EXCEPTIONS   2
/** Section padding options */
#define ODK_PAD   3
/** Hardware workarounds performed */
#define ODK_HWPATCH   4
/** record the fill value used by the linker */
#define ODK_FILL   5
/** reserve space for desktop tools to write */
#define ODK_TAGS   6
/** HW workaround; 'AND' bits when merging */
#define ODK_HWAND   7
/** HW workaround; 'OR' bits when merging */
#define ODK_HWOR   8
// Values for `info` in Elf_Options for ODK_EXCEPTIONS entries
/** FPE's which MUST be enabled */
#define OEX_FPU_MIN   0x1f
/** FPE's which MAY be enabled */
#define OEX_FPU_MAX   0x1f00
/** page zero must be mapped */
#define OEX_PAGE0   0x10000
/** Force sequential memory mode? */
#define OEX_SMM   0x20000
/** Force floating point debug mode? */
#define OEX_FPDBUG   0x40000
#define OEX_PRECISEFP   OEX_FPDBUG
/** Dismiss invalid address faults? */
#define OEX_DISMISS   0x80000
#define OEX_FPU_INVAL   0x10
#define OEX_FPU_DIV0   8
#define OEX_FPU_OFLO   4
#define OEX_FPU_UFLO   2
#define OEX_FPU_INEX   1
// Masks for `info` in Elf_Options for an ODK_HWPATCH entry
/** R4000 end-of-page patch */
#define OHW_R4KEOP   1
/** may need R8000 prefetch patch */
#define OHW_R8KPFETCH   2
/** R5000 end-of-page patch */
#define OHW_R5KEOP   4
/** R5000 cvt.[ds].l bug; clean=1 */
#define OHW_R5KCVTL   8
#define OPAD_PREFIX   1
#define OPAD_POSTFIX   2
#define OPAD_SYMBOL   4

/** Entry found in `.options` section */
typedef struct _Elf_Options_Hw {
	Elf32_Word hwp_flags1, hwp_flags2;
} Elf_Options_Hw;

// Masks for `info` in ElfOptions for ODK_HWAND and ODK_HWOR entries
#define OHWA0_R4KEOP_CHECKED   (1)
#define OHWA1_R4KEOP_CLEAN   (2)

/* MIPS RELOCATIONS */
/** No reloc */
#define R_MIPS_NONE   0
/** Direct 16 bit */
#define R_MIPS_16   1
/** Direct 32 bit */
#define R_MIPS_32   2
/** PC relative 32 bit */
#define R_MIPS_REL32   3
/** Direct 26 bit shifted */
#define R_MIPS_26   4
/** High 16 bit */
#define R_MIPS_HI16   5
/** Low 16 bit */
#define R_MIPS_LO16   6
/** GP relative 16 bit */
#define R_MIPS_GPREL16   7
/** 16 bit literal entry */
#define R_MIPS_LITERAL   8
/** 16 bit GOT entry */
#define R_MIPS_GOT16   9
/** PC relative 16 bit */
#define R_MIPS_PC16   10
/** 16 bit GOT entry for function */
#define R_MIPS_CALL16   11
/** GP relative 32 bit */
#define R_MIPS_GPREL32   12
#define R_MIPS_SHIFT5   16
#define R_MIPS_SHIFT6   17
#define R_MIPS_64   18
#define R_MIPS_GOT_DISP   19
#define R_MIPS_GOT_PAGE   20
#define R_MIPS_GOT_OFST   21
#define R_MIPS_GOT_HI16   22
#define R_MIPS_GOT_LO16   23
#define R_MIPS_SUB   24
#define R_MIPS_INSERT_A   25
#define R_MIPS_INSERT_B   26
#define R_MIPS_DELETE   27
#define R_MIPS_HIGHER   28
#define R_MIPS_HIGHEST   29
#define R_MIPS_CALL_HI16   30
#define R_MIPS_CALL_LO16   31
#define R_MIPS_SCN_DISP   32
#define R_MIPS_REL16   33
#define R_MIPS_ADD_IMMEDIATE   34
#define R_MIPS_PJUMP   35
#define R_MIPS_RELGOT   36
#define R_MIPS_JALR   37
/** Module number 32 bit */
#define R_MIPS_TLS_DTPMOD32   38
/** Module-relative offset 32 bit */
#define R_MIPS_TLS_DTPREL32   39
/** Module number 64 bit */
#define R_MIPS_TLS_DTPMOD64   40
/** Module-relative offset 64 bit */
#define R_MIPS_TLS_DTPREL64   41
/** 16 bit GOT offset for GD */
#define R_MIPS_TLS_GD   42
/** 16 bit GOT offset for LDM */
#define R_MIPS_TLS_LDM   43
/** Module-relative offset, high 16 bits */
#define R_MIPS_TLS_DTPREL_HI16   44
/** Module-relative offset, low 16 bits */
#define R_MIPS_TLS_DTPREL_LO16   45
/** 16 bit GOT offset for IE */
#define R_MIPS_TLS_GOTTPREL   46
/** TP-relative offset, 32 bit */
#define R_MIPS_TLS_TPREL32   47
/** TP-relative offset, 64 bit */
#define R_MIPS_TLS_TPREL64   48
/** TP-relative offset, high 16 bits */
#define R_MIPS_TLS_TPREL_HI16   49
/** TP-relative offset, low 16 bits */
#define R_MIPS_TLS_TPREL_LO16   50
#define R_MIPS_GLOB_DAT   51
#define R_MIPS_COPY   126
#define R_MIPS_JUMP_SLOT   127
#define R_MIPS_NUM   128
// Legal values for p_type field of Elf32_Phdr
/** Register usage information */
#define PT_MIPS_REGINFO   0x70000000
/** Runtime procedure table */
#define PT_MIPS_RTPROC   0x70000001
#define PT_MIPS_OPTIONS   0x70000002
// Special program header types
#define PF_MIPS_LOCAL   0x10000000
// Legal values for d_tag field of Elf32_Dyn
/** Runtime linker interface version */
#define DT_MIPS_RLD_VERSION   0x70000001
/** Timestamp */
#define DT_MIPS_TIME_STAMP   0x70000002
/** Checksum */
#define DT_MIPS_ICHECKSUM   0x70000003
/** Version string (string tbl index) */
#define DT_MIPS_IVERSION   0x70000004
/** Flags */
#define DT_MIPS_FLAGS   0x70000005
/** Base address */
#define DT_MIPS_BASE_ADDRESS 0x70000006
#define DT_MIPS_MSYM   0x70000007
/** Address of CONFLICT section */
#define DT_MIPS_CONFLICT   0x70000008
/** Address of LIBLIST section */
#define DT_MIPS_LIBLIST   0x70000009
/** Number of local GOT entries */
#define DT_MIPS_LOCAL_GOTNO   0x7000000a
/** Number of CONFLICT entries */
#define DT_MIPS_CONFLICTNO   0x7000000b
/** Number of LIBLIST entries */
#define DT_MIPS_LIBLISTNO   0x70000010
/** Number of DYNSYM entries */
#define DT_MIPS_SYMTABNO   0x70000011
/** First external DYNSYM */
#define DT_MIPS_UNREFEXTNO   0x70000012
/** First GOT entry in DYNSYM */
#define DT_MIPS_GOTSYM   0x70000013
/** Number of GOT page table entries */
#define DT_MIPS_HIPAGENO   0x70000014
/** Address of run time loader map */
#define DT_MIPS_RLD_MAP   0x70000016
/** Delta C++ class definition */
#define DT_MIPS_DELTA_CLASS   0x70000017
/** Number of entries in DT_MIPS_DELTA_CLASS */
#define DT_MIPS_DELTA_CLASS_NO   0x70000018
/** Delta C++ class instances */
#define DT_MIPS_DELTA_INSTANCE   0x70000019
/** Number of entries in DT_MIPS_DELTA_INSTANCE */
#define DT_MIPS_DELTA_INSTANCE_NO   0x7000001a
/** Delta relocations */
#define DT_MIPS_DELTA_RELOC   0x7000001b
/** Number of entries in DT_MIPS_DELTA_RELOC */
#define DT_MIPS_DELTA_RELOC_NO   0x7000001c
/** Delta symbols that Delta relocations refer to */
#define DT_MIPS_DELTA_SYM   0x7000001d
/** Number of entries in DT_MIPS_DELTA_SYM */
#define DT_MIPS_DELTA_SYM_NO   0x7000001e
/** Delta symbols that hold the class declaration */
#define DT_MIPS_DELTA_CLASSSYM   0x70000020
/** Number of entries in DT_MIPS_DELTA_CLASSSYM */
#define DT_MIPS_DELTA_CLASSSYM_NO   0x70000021
/** Flags indicating for C++ flavor */
#define DT_MIPS_CXX_FLAGS   0x70000022
#define DT_MIPS_PIXIE_INIT   0x70000023
#define DT_MIPS_SYMBOL_LIB   0x70000024
#define DT_MIPS_LOCALPAGE_GOTIDX   0x70000025
#define DT_MIPS_LOCAL_GOTIDX   0x70000026
#define DT_MIPS_HIDDEN_GOTIDX   0x70000027
#define DT_MIPS_PROTECTED_GOTIDX   0x70000028
/** Address of .options */
#define DT_MIPS_OPTIONS   0x70000029
/** Address of .interface */
#define DT_MIPS_INTERFACE   0x7000002a
#define DT_MIPS_DYNSTR_ALIGN   0x7000002b
/** Size of the .interface section */
#define DT_MIPS_INTERFACE_SIZE   0x7000002c
/** Address of rld_text_rsolve function stored in GOT */
#define DT_MIPS_RLD_TEXT_RESOLVE_ADDR   0x7000002d
/** Default suffix of dso to be added by rld on dlopen() calls */
#define DT_MIPS_PERF_SUFFIX   0x7000002e
/** (O32)Size of compact rel section */
#define DT_MIPS_COMPACT_SIZE   0x7000002f
/** GP value for aux GOTs */
#define DT_MIPS_GP_VALUE   0x70000030
/** Address of aux .dynamic */
#define DT_MIPS_AUX_DYNAMIC   0x70000031
/** The address of .got.plt in an executable using the new non-PIC ABI */
#define DT_MIPS_PLTGOT   0x70000032
/** The base of the PLT in an executable using the new non-PIC ABI if that PLT is writable; For a non-writable PLT, this is omitted or has a zero value */
#define DT_MIPS_RWPLT   0x70000034
#define DT_MIPS_NUM   0x35

/** Entries found in sections of type SHT_MIPS_LIBLIST */
typedef struct _Elf32_Lib {
	Elf32_Word l_name;  //!< Name (string table index)
	Elf32_Word l_time_stamp;  //!< Timestamp
	Elf32_Word l_checksum;  //!< Checksum
	Elf32_Word l_version;  //!< Interface version
	Elf32_Word l_flags;  //!< Flags
} Elf32_Lib;

/** Entries found in sections of type SHT_MIPS_LIBLIST */
typedef struct _Elf64_Lib {
	Elf64_Word l_name;  //!< Name (string table index)
	Elf64_Word l_time_stamp;  //!< Timestamp
	Elf64_Word l_checksum;  //!< Checksum
	Elf64_Word l_version;  //!< Interface version
	Elf64_Word l_flags;  //!< Flags
} Elf64_Lib;

/* HPPA SPECIFIC DEFINITIONS */
// Legal values for e_flags field of Elf32_Ehdr
/** Trap nil pointer dereference */
#define EF_PARISC_TRAPNIL   0x10000
/** Program uses arch. extensions */
#define EF_PARISC_EXT   0x20000
/** Program expects little endian */
#define EF_PARISC_LSB   0x40000
/** Program expects wide mode */
#define EF_PARISC_WIDE   0x80000
/** No kernel assisted branch prediction */
#define EF_PARISC_NO_KABP   0x100000
/** Allow lazy swapping */
#define EF_PARISC_LAZYSWAP   0x400000
/** Architecture version */
#define EF_PARISC_ARCH   0xffff
// Defined values for `e_flags & EF_PARISC_ARCH' are:
/** PA-RISC 1.0 big-endian */
#define EFA_PARISC_1_0   0x20b
/** PA-RISC 1.1 big-endian */
#define EFA_PARISC_1_1   0x210
/** PA-RISC 2.0 big-endian */
#define EFA_PARISC_2_0   0x214
// Additional Section Indices
/** Section for tenatively declared symbols in ANSI C */
#define SHN_PARISC_ANSI_COMMON   0xff00
/** Common blocks in huge model */
#define SHN_PARISC_HUGE_COMMON   0xff01
// Legal values for sh_type field of Elf32_Shdr
/** Contains product specific ext */
#define SHT_PARISC_EXT   0x70000000
/** Unwind information */
#define SHT_PARISC_UNWIND   0x70000001
/** Debug info for optimized code */
#define SHT_PARISC_DOC   0x70000002
// Legal values for sh_flags field of Elf32_Shdr
/** Section with short addressing */
#define SHF_PARISC_SHORT   0x20000000
/** Section far from gp */
#define SHF_PARISC_HUGE   0x40000000
/** Static branch prediction code */
#define SHF_PARISC_SBP   0x80000000
// Legal values for ST_TYPE subfield of st_info (symbol type)
/** Millicode function entry point */
#define STT_PARISC_MILLICODE   13
#define STT_HP_OPAQUE   (STT_LOOS + 1)
#define STT_HP_STUB   (STT_LOOS + 2)

/* HPPA RELOCATIONS */
/** No reloc */
#define R_PARISC_NONE   0
/** Direct 32-bit reference */
#define R_PARISC_DIR32   1
/** Left 21 bits of eff. address */
#define R_PARISC_DIR21L   2
/** Right 17 bits of eff. address */
#define R_PARISC_DIR17R   3
/** 17 bits of eff. address */
#define R_PARISC_DIR17F   4
/** Right 14 bits of eff. address */
#define R_PARISC_DIR14R   6
/** 32-bit rel. address */
#define R_PARISC_PCREL32   9
/** Left 21 bits of rel. address */
#define R_PARISC_PCREL21L   10
/** Right 17 bits of rel. address */
#define R_PARISC_PCREL17R   11
/** 17 bits of rel. address */
#define R_PARISC_PCREL17F   12
/** Right 14 bits of rel. address */
#define R_PARISC_PCREL14R   14
/** Left 21 bits of rel. address */
#define R_PARISC_DPREL21L   18
/** Right 14 bits of rel. address */
#define R_PARISC_DPREL14R   22
/** GP-relative, left 21 bits */
#define R_PARISC_GPREL21L   26
/** GP-relative, right 14 bits */
#define R_PARISC_GPREL14R   30
/** LT-relative, left 21 bits */
#define R_PARISC_LTOFF21L   34
/** LT-relative, right 14 bits */
#define R_PARISC_LTOFF14R   38
/** 32 bits section rel. address */
#define R_PARISC_SECREL32   41
/** No relocation, set segment base */
#define R_PARISC_SEGBASE   48
/** 32 bits segment rel. address */
#define R_PARISC_SEGREL32   49
/** PLT rel. address, left 21 bits */
#define R_PARISC_PLTOFF21L   50
/** PLT rel. address, right 14 bits */
#define R_PARISC_PLTOFF14R   54
/** 32 bits LT-rel. function pointer */
#define R_PARISC_LTOFF_FPTR32   57
/** LT-rel. fct ptr, left 21 bits */
#define R_PARISC_LTOFF_FPTR21L   58
/** LT-rel. fct ptr, right 14 bits */
#define R_PARISC_LTOFF_FPTR14R   62
/** 64 bits function address */
#define R_PARISC_FPTR64   64
/** 32 bits function address */
#define R_PARISC_PLABEL32   65
/** 64 bits PC-rel. address */
#define R_PARISC_PCREL64   72
/** 22 bits PC-rel. address */
#define R_PARISC_PCREL22F   74
/** PC-rel. address, right 14 bits */
#define R_PARISC_PCREL14WR   75
/** PC rel. address, right 14 bits */
#define R_PARISC_PCREL14DR   76
/** 16 bits PC-rel. address */
#define R_PARISC_PCREL16F   77
/** 16 bits PC-rel. address */
#define R_PARISC_PCREL16WF   78
/** 16 bits PC-rel. address */
#define R_PARISC_PCREL16DF   79
/** 64 bits of eff. address */
#define R_PARISC_DIR64   80
/** 14 bits of eff. address */
#define R_PARISC_DIR14WR   83
/** 14 bits of eff. address */
#define R_PARISC_DIR14DR   84
/** 16 bits of eff. address */
#define R_PARISC_DIR16F   85
/** 16 bits of eff. address */
#define R_PARISC_DIR16WF   86
/** 16 bits of eff. address */
#define R_PARISC_DIR16DF   87
/** 64 bits of GP-rel. address */
#define R_PARISC_GPREL64   88
/** GP-rel. address, right 14 bits */
#define R_PARISC_GPREL14WR   91
/** GP-rel. address, right 14 bits */
#define R_PARISC_GPREL14DR   92
/** 16 bits GP-rel. address */
#define R_PARISC_GPREL16F   93
/** 16 bits GP-rel. address */
#define R_PARISC_GPREL16WF   94
/** 16 bits GP-rel. address */
#define R_PARISC_GPREL16DF   95
/** 64 bits LT-rel. address */
#define R_PARISC_LTOFF64   96
/** LT-rel. address, right 14 bits */
#define R_PARISC_LTOFF14WR   99
/** LT-rel. address, right 14 bits */
#define R_PARISC_LTOFF14DR   100
/** 16 bits LT-rel. address */
#define R_PARISC_LTOFF16F   101
/** 16 bits LT-rel. address */
#define R_PARISC_LTOFF16WF   102
/** 16 bits LT-rel. address */
#define R_PARISC_LTOFF16DF   103
/** 64 bits section rel. address */
#define R_PARISC_SECREL64   104
/** 64 bits segment rel. address */
#define R_PARISC_SEGREL64   112
/** PLT-rel. address, right 14 bits */
#define R_PARISC_PLTOFF14WR   115
/** PLT-rel. address, right 14 bits */
#define R_PARISC_PLTOFF14DR   116
/** 16 bits LT-rel. address */
#define R_PARISC_PLTOFF16F   117
/** 16 bits PLT-rel. address */
#define R_PARISC_PLTOFF16WF   118
/** 16 bits PLT-rel. address */
#define R_PARISC_PLTOFF16DF   119
/** 64 bits LT-rel. function ptr */
#define R_PARISC_LTOFF_FPTR64   120
/** LT-rel. fct. ptr., right 14 bits */
#define R_PARISC_LTOFF_FPTR14WR   123
/** LT-rel. fct. ptr., right 14 bits */
#define R_PARISC_LTOFF_FPTR14DR   124
/** 16 bits LT-rel. function ptr */
#define R_PARISC_LTOFF_FPTR16F   125
/** 16 bits LT-rel. function ptr */
#define R_PARISC_LTOFF_FPTR16WF   126
/** 16 bits LT-rel. function ptr */
#define R_PARISC_LTOFF_FPTR16DF   127
#define R_PARISC_LORESERVE   128
/** Copy relocation */
#define R_PARISC_COPY   128
/** Dynamic reloc, imported PLT */
#define R_PARISC_IPLT   129
/** Dynamic reloc, exported PLT */
#define R_PARISC_EPLT   130
/** 32 bits TP-rel. address */
#define R_PARISC_TPREL32   153
/** TP-rel. address, left 21 bits */
#define R_PARISC_TPREL21L   154
/** TP-rel. address, right 14 bits */
#define R_PARISC_TPREL14R   158
/** LT-TP-rel. address, left 21 bits */
#define R_PARISC_LTOFF_TP21L   162
/** LT-TP-rel. address, right 14 bits */
#define R_PARISC_LTOFF_TP14R   166
/** 14 bits LT-TP-rel. address */
#define R_PARISC_LTOFF_TP14F   167
/** 64 bits TP-rel. address */
#define R_PARISC_TPREL64   216
/** TP-rel. address, right 14 bits */
#define R_PARISC_TPREL14WR   219
/** TP-rel. address, right 14 bits */
#define R_PARISC_TPREL14DR   220
/** 16 bits TP-rel. address */
#define R_PARISC_TPREL16F   221
/** 16 bits TP-rel. address */
#define R_PARISC_TPREL16WF   222
/** 16 bits TP-rel. address */
#define R_PARISC_TPREL16DF   223
/** 64 bits LT-TP-rel. address */
#define R_PARISC_LTOFF_TP64   224
/** LT-TP-rel. address, right 14 bits */
#define R_PARISC_LTOFF_TP14WR   227
/** LT-TP-rel. address, right 14 bits */
#define R_PARISC_LTOFF_TP14DR   228
/** 16 bits LT-TP-rel. address */
#define R_PARISC_LTOFF_TP16F   229
/** 16 bits LT-TP-rel. address */
#define R_PARISC_LTOFF_TP16WF   230
/** 16 bits LT-TP-rel. address */
#define R_PARISC_LTOFF_TP16DF   231
#define R_PARISC_HIRESERVE   255
// Legal values for p_type field of Elf32_Phdr/Elf64_Phdr
#define PT_HP_TLS   (PT_LOOS)
#define PT_HP_CORE_NONE   (PT_LOOS + 1)
#define PT_HP_CORE_VERSION   (PT_LOOS + 2)
#define PT_HP_CORE_KERNEL   (PT_LOOS + 3)
#define PT_HP_CORE_COMM   (PT_LOOS + 4)
#define PT_HP_CORE_PROC   (PT_LOOS + 5)
#define PT_HP_CORE_LOADABLE   (PT_LOOS + 6)
#define PT_HP_CORE_STACK   (PT_LOOS + 7)
#define PT_HP_CORE_SHM   (PT_LOOS + 8)
#define PT_HP_CORE_MMF   (PT_LOOS + 9)
#define PT_HP_PARALLEL   (PT_LOOS + 0x10)
#define PT_HP_FASTBIND   (PT_LOOS + 0x11)
#define PT_HP_OPT_ANNOT   (PT_LOOS + 0x12)
#define PT_HP_HSL_ANNOT   (PT_LOOS + 0x13)
#define PT_HP_STACK   (PT_LOOS + 0x14)
#define PT_PARISC_ARCHEXT   0x70000000
#define PT_PARISC_UNWIND   0x70000001
// Legal values for p_flags field of Elf32_Phdr/Elf64_Phdr
#define PF_PARISC_SBP   0x08000000
#define PF_HP_PAGE_SIZE   0x100000
#define PF_HP_FAR_SHARED   0x200000
#define PF_HP_NEAR_SHARED   0x400000
#define PF_HP_CODE   0x1000000
#define PF_HP_MODIFY   0x2000000
#define PF_HP_LAZYSWAP   0x4000000
#define PF_HP_SBP   0x8000000

/* ALPHA SPECIFIC DEFINITIONS */
// Legal values for e_flags field of Elf64_Ehdr
/** All addresses must be < 2GB */
#define EF_ALPHA_32BIT   1
/** Relocations for relaxing exist */
#define EF_ALPHA_CANRELAX   2
// Legal values for sh_type field of Elf64_Shdr
/** Concerned with ECOFF debugging info */
#define SHT_ALPHA_DEBUG   0x70000001
/** Concerned with ECOFF debugging info */
#define SHT_ALPHA_REGINFO   0x70000002
// Legal values for sh_flags field of Elf64_Shdr
#define SHF_ALPHA_GPREL   0x10000000
// Legal values for st_other field of Elf64_Sym
/** No PV required */
#define STO_ALPHA_NOPV   0x80
/** PV only used for initial ldgp */
#define STO_ALPHA_STD_GPLOAD   0x88

/* ALPHA RELOCATIONS */
/** No reloc */
#define R_ALPHA_NONE   0
/** Direct 32 bit */
#define R_ALPHA_REFLONG   1
/** Direct 64 bit */
#define R_ALPHA_REFQUAD   2
/** GP relative 32 bit */
#define R_ALPHA_GPREL32   3
/** GP relative 16 bit w/optimization */
#define R_ALPHA_LITERAL   4
/** Optimization hint for LITERAL */
#define R_ALPHA_LITUSE   5
/** Add displacement to GP */
#define R_ALPHA_GPDISP   6
/** PC+4 relative 23 bit shifted */
#define R_ALPHA_BRADDR   7
/** PC+4 relative 16 bit shifted */
#define R_ALPHA_HINT   8
/** PC relative 16 bit */
#define R_ALPHA_SREL16   9
/** PC relative 32 bit */
#define R_ALPHA_SREL32   10
/** PC relative 64 bit */
#define R_ALPHA_SREL64   11
/** GP relative 32 bit, high 16 bits */
#define R_ALPHA_GPRELHIGH   17
/** GP relative 32 bit, low 16 bits */
#define R_ALPHA_GPRELLOW   18
/** GP relative 16 bit */
#define R_ALPHA_GPREL16   19
/** Copy symbol at runtime */
#define R_ALPHA_COPY   24
/** Create GOT entry */
#define R_ALPHA_GLOB_DAT   25
/** Create PLT entry */
#define R_ALPHA_JMP_SLOT   26
/** Adjust by program base */
#define R_ALPHA_RELATIVE   27
#define R_ALPHA_TLS_GD_HI   28
#define R_ALPHA_TLSGD   29
#define R_ALPHA_TLS_LDM   30
#define R_ALPHA_DTPMOD64   31
#define R_ALPHA_GOTDTPREL   32
#define R_ALPHA_DTPREL64   33
#define R_ALPHA_DTPRELHI   34
#define R_ALPHA_DTPRELLO   35
#define R_ALPHA_DTPREL16   36
#define R_ALPHA_GOTTPREL   37
#define R_ALPHA_TPREL64   38
#define R_ALPHA_TPRELHI   39
#define R_ALPHA_TPRELLO   40
#define R_ALPHA_TPREL16   41
#define R_ALPHA_NUM   46
// Magic values of the LITUSE relocation addend
#define LITUSE_ALPHA_ADDR   0
#define LITUSE_ALPHA_BASE   1
#define LITUSE_ALPHA_BYTOFF   2
#define LITUSE_ALPHA_JSR   3
#define LITUSE_ALPHA_TLS_GD   4
#define LITUSE_ALPHA_TLS_LDM   5
// Legal values for d_tag of Elf64_Dyn
#define DT_ALPHA_PLTRO   (DT_LOPROC)
#define DT_ALPHA_NUM   1

/* POWERPC SPECIFIC DECLARATIONS */
// Values for Elf32/64_Ehdr.e_flags
/** PowerPC embedded flag */
#define EF_PPC_EMB   0x80000000
// Cygnus local bits
/** PowerPC -mrelocatable flag*/
#define EF_PPC_RELOCATABLE   0x10000
/** PowerPC -mrelocatable-lib flag */
#define EF_PPC_RELOCATABLE_LIB   0x8000
// PowerPC relocations defined by the ABIs
#define R_PPC_NONE   0
/** 32bit absolute address */
#define R_PPC_ADDR32   1
/** 26bit address, 2 bits ignored */
#define R_PPC_ADDR24   2
/** 16bit absolute address */
#define R_PPC_ADDR16   3
/** lower 16bit of absolute address */
#define R_PPC_ADDR16_LO   4
/** high 16bit of absolute address */
#define R_PPC_ADDR16_HI   5
/** adjusted high 16bit */
#define R_PPC_ADDR16_HA   6
/** 16bit address, 2 bits ignored */
#define R_PPC_ADDR14   7
#define R_PPC_ADDR14_BRTAKEN   8
#define R_PPC_ADDR14_BRNTAKEN   9
/** PC relative 26 bit */
#define R_PPC_REL24   10
/** PC relative 16 bit */
#define R_PPC_REL14   11
#define R_PPC_REL14_BRTAKEN   12
#define R_PPC_REL14_BRNTAKEN   13
#define R_PPC_GOT16   14
#define R_PPC_GOT16_LO   15
#define R_PPC_GOT16_HI   16
#define R_PPC_GOT16_HA   17
#define R_PPC_PLTREL24   18
#define R_PPC_COPY   19
#define R_PPC_GLOB_DAT   20
#define R_PPC_JMP_SLOT   21
#define R_PPC_RELATIVE   22
#define R_PPC_LOCAL24PC   23
#define R_PPC_UADDR32   24
#define R_PPC_UADDR16   25
#define R_PPC_REL32   26
#define R_PPC_PLT32   27
#define R_PPC_PLTREL32   28
#define R_PPC_PLT16_LO   29
#define R_PPC_PLT16_HI   30
#define R_PPC_PLT16_HA   31
#define R_PPC_SDAREL16   32
#define R_PPC_SECTOFF   33
#define R_PPC_SECTOFF_LO   34
#define R_PPC_SECTOFF_HI   35
#define R_PPC_SECTOFF_HA   36
// PowerPC relocations defined for the TLS access ABI
/** none (sym+add)tls */
#define R_PPC_TLS   67
/** word32 (sym+add)dtpmod */
#define R_PPC_DTPMOD32   68
/** half16* (sym+add)tprel */
#define R_PPC_TPREL16   69
/** half16 (sym+add)tprell */
#define R_PPC_TPREL16_LO   70
/** half16 (sym+add)tprelh */
#define R_PPC_TPREL16_HI   71
/** half16 (sym+add)tprelha */
#define R_PPC_TPREL16_HA   72
/** word32 (sym+add)tprel */
#define R_PPC_TPREL32   73
/** half16* (sym+add)dtprel */
#define R_PPC_DTPREL16   74
/** half16 (sym+add)dtprell */
#define R_PPC_DTPREL16_LO   75
/** half16 (sym+add)dtprelh */
#define R_PPC_DTPREL16_HI   76
/** half16 (sym+add)dtprelha */
#define R_PPC_DTPREL16_HA   77
/** word32 (sym+add)dtprel */
#define R_PPC_DTPREL32   78
/** half16* (sym+add)gottlsgd */
#define R_PPC_GOT_TLSGD16   79
/** half16 (sym+add)gottlsgdl */
#define R_PPC_GOT_TLSGD16_LO   80
/** half16 (sym+add)gottlsgdh */
#define R_PPC_GOT_TLSGD16_HI   81
/** half16 (sym+add)gottlsgdha */
#define R_PPC_GOT_TLSGD16_HA   82
/** half16* (sym+add)gottlsld */
#define R_PPC_GOT_TLSLD16   83
/** half16 (sym+add)gottlsldl */
#define R_PPC_GOT_TLSLD16_LO   84
/** half16 (sym+add)gottlsldh */
#define R_PPC_GOT_TLSLD16_HI   85
/** half16 (sym+add)gottlsldha */
#define R_PPC_GOT_TLSLD16_HA   86
/** half16* (sym+add)gottprel */
#define R_PPC_GOT_TPREL16   87
/** half16 (sym+add)gottprell */
#define R_PPC_GOT_TPREL16_LO   88
/** half16 (sym+add)gottprelh */
#define R_PPC_GOT_TPREL16_HI   89
/** half16 (sym+add)gottprelha */
#define R_PPC_GOT_TPREL16_HA   90
/** half16* (sym+add)gotdtprel */
#define R_PPC_GOT_DTPREL16   91
/** half16* (sym+add)gotdtprell */
#define R_PPC_GOT_DTPREL16_LO   92
/** half16* (sym+add)gotdtprelh */
#define R_PPC_GOT_DTPREL16_HI   93
/** half16* (sym+add)gotdtprelha */
#define R_PPC_GOT_DTPREL16_HA   94
#define R_PPC_NUM   95
// The remaining relocs are from the Embedded ELF ABI, and are not in the SVR4 ELF ABI
#define R_PPC_EMB_NADDR32   101
#define R_PPC_EMB_NADDR16   102
#define R_PPC_EMB_NADDR16_LO   103
#define R_PPC_EMB_NADDR16_HI   104
#define R_PPC_EMB_NADDR16_HA   105
#define R_PPC_EMB_SDAI16   106
#define R_PPC_EMB_SDA2I16   107
#define R_PPC_EMB_SDA2REL   108
/** 16 bit offset in SDA */
#define R_PPC_EMB_SDA21   109
#define R_PPC_EMB_MRKREF   110
#define R_PPC_EMB_RELSEC16   111
#define R_PPC_EMB_RELST_LO   112
#define R_PPC_EMB_RELST_HI   113
#define R_PPC_EMB_RELST_HA   114
#define R_PPC_EMB_BIT_FLD   115
/** 16 bit relative offset in SDA */
#define R_PPC_EMB_RELSDA   116
// Diab tool relocations
/** like EMB_SDA21, but lower 16 bit */
#define R_PPC_DIAB_SDA21_LO   180
/** like EMB_SDA21, but high 16 bit */
#define R_PPC_DIAB_SDA21_HI   181
/** like EMB_SDA21, adjusted high 16 */
#define R_PPC_DIAB_SDA21_HA   182
/** like EMB_RELSDA, but lower 16 bit */
#define R_PPC_DIAB_RELSDA_LO   183
/** like EMB_RELSDA, but high 16 bit */
#define R_PPC_DIAB_RELSDA_HI   184
/** like EMB_RELSDA, adjusted high 16 */
#define R_PPC_DIAB_RELSDA_HA   185
// GNU relocs used in PIC code sequences
/** word32 (sym+add-.) */
#define R_PPC_REL16   249
/** half16 (sym+add-.)@l */
#define R_PPC_REL16_LO   250
/** half16 (sym+add-.)@h */
#define R_PPC_REL16_HI   251
/** half16 (sym+add-.)@ha */
#define R_PPC_REL16_HA   252
/** Phony reloc to handle any old TOC16 references that may still be in object files */
#define R_PPC_TOC16   255
// PowerPC specific values for the Dyn d_tag field
#define DT_PPC_GOT   (DT_LOPROC)
#define DT_PPC_NUM   1
// PowerPC64 relocations defined by the ABIs
#define R_PPC64_NONE   R_PPC_NONE
/** 32bit absolute address */
#define R_PPC64_ADDR32   R_PPC_ADDR32
/** 26bit address, word aligned */
#define R_PPC64_ADDR24   R_PPC_ADDR24
/** 16bit absolute address */
#define R_PPC64_ADDR16   R_PPC_ADDR16
/** lower 16bits of address */
#define R_PPC64_ADDR16_LO   R_PPC_ADDR16_LO
/** high 16bits of address */
#define R_PPC64_ADDR16_HI   R_PPC_ADDR16_HI
/** adjusted high 16bits */
#define R_PPC64_ADDR16_HA   R_PPC_ADDR16_HA
/** 16bit address, word aligned */
#define R_PPC64_ADDR14   R_PPC_ADDR14
#define R_PPC64_ADDR14_BRTAKEN   R_PPC_ADDR14_BRTAKEN
#define R_PPC64_ADDR14_BRNTAKEN   R_PPC_ADDR14_BRNTAKEN
/** PC-rel. 26 bit, word aligned */
#define R_PPC64_REL24   R_PPC_REL24
/** PC relative 16 bit */
#define R_PPC64_REL14   R_PPC_REL14
#define R_PPC64_REL14_BRTAKEN   R_PPC_REL14_BRTAKEN
#define R_PPC64_REL14_BRNTAKEN   R_PPC_REL14_BRNTAKEN
#define R_PPC64_GOT16   R_PPC_GOT16
#define R_PPC64_GOT16_LO   R_PPC_GOT16_LO
#define R_PPC64_GOT16_HI   R_PPC_GOT16_HI
#define R_PPC64_GOT16_HA   R_PPC_GOT16_HA
#define R_PPC64_COPY   R_PPC_COPY
#define R_PPC64_GLOB_DAT   R_PPC_GLOB_DAT
#define R_PPC64_JMP_SLOT   R_PPC_JMP_SLOT
#define R_PPC64_RELATIVE   R_PPC_RELATIVE
#define R_PPC64_UADDR32   R_PPC_UADDR32
#define R_PPC64_UADDR16   R_PPC_UADDR16
#define R_PPC64_REL32   R_PPC_REL32
#define R_PPC64_PLT32   R_PPC_PLT32
#define R_PPC64_PLTREL32   R_PPC_PLTREL32
#define R_PPC64_PLT16_LO   R_PPC_PLT16_LO
#define R_PPC64_PLT16_HI   R_PPC_PLT16_HI
#define R_PPC64_PLT16_HA   R_PPC_PLT16_HA
#define R_PPC64_SECTOFF   R_PPC_SECTOFF
#define R_PPC64_SECTOFF_LO   R_PPC_SECTOFF_LO
#define R_PPC64_SECTOFF_HI   R_PPC_SECTOFF_HI
#define R_PPC64_SECTOFF_HA   R_PPC_SECTOFF_HA
/** word30 (S + A - P) >> 2 */
#define R_PPC64_ADDR30   37
/** doubleword64 S + A */
#define R_PPC64_ADDR64   38
/** half16 #higher(S + A) */
#define R_PPC64_ADDR16_HIGHER   39
/** half16 #highera(S + A) */
#define R_PPC64_ADDR16_HIGHERA   40
/** half16 #highest(S + A) */
#define R_PPC64_ADDR16_HIGHEST   41
/** half16 #highesta(S + A) */
#define R_PPC64_ADDR16_HIGHESTA   42
/** doubleword64 S + A */
#define R_PPC64_UADDR64   43
/** doubleword64 S + A - P */
#define R_PPC64_REL64   44
/** doubleword64 L + A */
#define R_PPC64_PLT64   45
/** doubleword64 L + A - P */
#define R_PPC64_PLTREL64   46
/** half16* S + A - .TOC */
#define R_PPC64_TOC16   47
/** half16 #lo(S + A - .TOC.) */
#define R_PPC64_TOC16_LO   48
/** half16 #hi(S + A - .TOC.) */
#define R_PPC64_TOC16_HI   49
/** half16 #ha(S + A - .TOC.) */
#define R_PPC64_TOC16_HA   50
/** doubleword64 .TOC */
#define R_PPC64_TOC   51
/** half16* M + A */
#define R_PPC64_PLTGOT16   52
/** half16 #lo(M + A) */
#define R_PPC64_PLTGOT16_LO   53
/** half16 #hi(M + A) */
#define R_PPC64_PLTGOT16_HI   54
/** half16 #ha(M + A) */
#define R_PPC64_PLTGOT16_HA   55
/** half16ds* (S + A) >> 2 */
#define R_PPC64_ADDR16_DS   56
/** half16ds  #lo(S + A) >> 2 */
#define R_PPC64_ADDR16_LO_DS   57
/** half16ds* (G + A) >> 2 */
#define R_PPC64_GOT16_DS   58
/** half16ds  #lo(G + A) >> 2 */
#define R_PPC64_GOT16_LO_DS   59
/** half16ds  #lo(L + A) >> 2 */
#define R_PPC64_PLT16_LO_DS   60
/** half16ds* (R + A) >> 2 */
#define R_PPC64_SECTOFF_DS   61
/** half16ds  #lo(R + A) >> 2 */
#define R_PPC64_SECTOFF_LO_DS   62
/** half16ds* (S + A - .TOC.) >> 2 */
#define R_PPC64_TOC16_DS   63
/** half16ds  #lo(S + A - .TOC.) >> 2 */
#define R_PPC64_TOC16_LO_DS   64
/** half16ds* (M + A) >> 2 */
#define R_PPC64_PLTGOT16_DS   65
/** half16ds  #lo(M + A) >> 2 */
#define R_PPC64_PLTGOT16_LO_DS   66
// PowerPC64 relocations defined for the TLS access ABI
/** none (sym+add)tls */
#define R_PPC64_TLS   67
/** doubleword64 (sym+add)dtpmod */
#define R_PPC64_DTPMOD64   68
/** half16* (sym+add)tprel */
#define R_PPC64_TPREL16   69
/** half16 (sym+add)tprell */
#define R_PPC64_TPREL16_LO   70
/** half16 (sym+add)tprelh */
#define R_PPC64_TPREL16_HI   71
/** half16 (sym+add)tprelha */
#define R_PPC64_TPREL16_HA   72
/** doubleword64 (sym+add)tprel */
#define R_PPC64_TPREL64   73
/** half16* (sym+add)dtprel */
#define R_PPC64_DTPREL16   74
/** half16 (sym+add)dtprell */
#define R_PPC64_DTPREL16_LO   75
/** half16 (sym+add)dtprelh */
#define R_PPC64_DTPREL16_HI   76
/** half16 (sym+add)dtprelha */
#define R_PPC64_DTPREL16_HA   77
/** doubleword64 (sym+add)dtprel */
#define R_PPC64_DTPREL64   78
/** half16* (sym+add)gottlsgd */
#define R_PPC64_GOT_TLSGD16   79
/** half16 (sym+add)gottlsgdl */
#define R_PPC64_GOT_TLSGD16_LO   80
/** half16 (sym+add)gottlsgdh */
#define R_PPC64_GOT_TLSGD16_HI   81
/** half16 (sym+add)gottlsgdha */
#define R_PPC64_GOT_TLSGD16_HA   82
/** half16* (sym+add)gottlsld */
#define R_PPC64_GOT_TLSLD16   83
/** half16 (sym+add)gottlsldl */
#define R_PPC64_GOT_TLSLD16_LO   84
/** half16 (sym+add)gottlsldh */
#define R_PPC64_GOT_TLSLD16_HI   85
/** half16 (sym+add)gottlsldha */
#define R_PPC64_GOT_TLSLD16_HA   86
/** half16ds* (sym+add)gottprel */
#define R_PPC64_GOT_TPREL16_DS   87
/** half16ds (sym+add)gottprell */
#define R_PPC64_GOT_TPREL16_LO_DS 88
/** half16 (sym+add)gottprelh */
#define R_PPC64_GOT_TPREL16_HI   89
/** half16 (sym+add)gottprelha */
#define R_PPC64_GOT_TPREL16_HA   90
/** half16ds* (sym+add)gotdtprel */
#define R_PPC64_GOT_DTPREL16_DS   91
/** half16ds (sym+add)gotdtprell */
#define R_PPC64_GOT_DTPREL16_LO_DS   92
/** half16 (sym+add)gotdtprelh */
#define R_PPC64_GOT_DTPREL16_HI   93
/** half16 (sym+add)gotdtprelha */
#define R_PPC64_GOT_DTPREL16_HA   94
/** half16ds* (sym+add)tprel */
#define R_PPC64_TPREL16_DS   95
/** half16ds (sym+add)tprell */
#define R_PPC64_TPREL16_LO_DS   96
/** half16 (sym+add)tprelhigher */
#define R_PPC64_TPREL16_HIGHER   97
/** half16 (sym+add)tprelhighera */
#define R_PPC64_TPREL16_HIGHERA   98
/** half16 (sym+add)tprelhighest */
#define R_PPC64_TPREL16_HIGHEST   99
/** half16 (sym+add)tprelhighesta */
#define R_PPC64_TPREL16_HIGHESTA 100
/** half16ds* (sym+add)dtprel */
#define R_PPC64_DTPREL16_DS   101
/** half16ds (sym+add)dtprell */
#define R_PPC64_DTPREL16_LO_DS   102
/** half16 (sym+add)dtprelhigher */
#define R_PPC64_DTPREL16_HIGHER   103
/** half16 (sym+add)dtprelhighera */
#define R_PPC64_DTPREL16_HIGHERA   104
/** half16 (sym+add)dtprelhighest */
#define R_PPC64_DTPREL16_HIGHEST   105
/** half16 (sym+add)dtprelhighesta */
#define R_PPC64_DTPREL16_HIGHESTA   106
#define R_PPC64_NUM   107
// PowerPC64 specific values for the Dyn d_tag field
#define DT_PPC64_GLINK   (DT_LOPROC)
#define DT_PPC64_OPD   (DT_LOPROC + 1)
#define DT_PPC64_OPDSZ   (DT_LOPROC + 2)
#define DT_PPC64_NUM   3

/* ARM SPECIFIC DECLARATIONS */
// Processor specific flags for the ELF header e_flags field
#define EF_ARM_RELEXEC   1
#define EF_ARM_HASENTRY   2
#define EF_ARM_INTERWORK   4
#define EF_ARM_APCS_26   8
#define EF_ARM_APCS_FLOAT   0x10
#define EF_ARM_PIC   0x20
/** 8-bit structure alignment is in use */
#define EF_ARM_ALIGN8   0x40
#define EF_ARM_NEW_ABI   0x80
#define EF_ARM_OLD_ABI   0x100
// Other constants defined in the ARM ELF spec. version B-01
#define EF_ARM_SYMSARESORTED   4
#define EF_ARM_DYNSYMSUSESEGIDX   8
#define EF_ARM_MAPSYMSFIRST   0x10
#define EF_ARM_EABIMASK   0XFF000000
#define EF_ARM_EABI_VERSION(flags)   ((flags) & EF_ARM_EABIMASK)
#define EF_ARM_EABI_UNKNOWN   0
#define EF_ARM_EABI_VER1   0x1000000
#define EF_ARM_EABI_VER2   0x2000000
// Additional symbol types for Thumb
#define STT_ARM_TFUNC   0xd
// ARM-specific values for sh_flags
/** Section contains an entry point */
#define SHF_ARM_ENTRYSECT   0x10000000
/** Section may be multiply defined in the input to a link step */
#define SHF_ARM_COMDEF   0x80000000
// ARM-specific program header flags
/** Segment contains the location addressed by the static base */
#define PF_ARM_SB   0x10000000
// Processor specific values for the Phdr p_type field
/** .ARM.exidx segment */
#define PT_ARM_EXIDX   0x70000001

/* ARM RELOCATIONS */
/** No reloc */
#define R_ARM_NONE   0
/** PC relative 26 bit branch */
#define R_ARM_PC24   1
/** Direct 32 bit */
#define R_ARM_ABS32   2
/** PC relative 32 bit */
#define R_ARM_REL32   3
#define R_ARM_PC13   4
/** Direct 16 bit */
#define R_ARM_ABS16   5
/** Direct 12 bit */
#define R_ARM_ABS12   6
#define R_ARM_THM_ABS5   7
/** Direct 8 bit */
#define R_ARM_ABS8   8
#define R_ARM_SBREL32   9
#define R_ARM_THM_PC22   10
#define R_ARM_THM_PC8   11
#define R_ARM_AMP_VCALL9   12
#define R_ARM_SWI24   13
#define R_ARM_THM_SWI8   14
#define R_ARM_XPC25   15
#define R_ARM_THM_XPC22   16
#define R_ARM_TLS_DTPMOD32   17
#define R_ARM_TLS_DTPOFF32   18
#define R_ARM_TLS_TPOFF32   19
/** Copy symbol at runtime */
#define R_ARM_COPY   20
/** Create GOT entry */
#define R_ARM_GLOB_DAT   21
/** Create PLT entry */
#define R_ARM_JUMP_SLOT   22
/** Adjust by program base */
#define R_ARM_RELATIVE   23
/** 32 bit offset to GOT */
#define R_ARM_GOTOFF   24
/** 32 bit PC relative offset to GOT */
#define R_ARM_GOTPC   25
/** 32 bit GOT entry */
#define R_ARM_GOT32   26
/** 32 bit PLT address */
#define R_ARM_PLT32   27
#define R_ARM_ALU_PCREL_7_0   32
#define R_ARM_ALU_PCREL_15_8   33
#define R_ARM_ALU_PCREL_23_15   34
#define R_ARM_LDR_SBREL_11_0   35
#define R_ARM_ALU_SBREL_19_12   36
#define R_ARM_ALU_SBREL_27_20   37
#define R_ARM_GNU_VTENTRY   100
#define R_ARM_GNU_VTINHERIT   101
/** thumb unconditional branch */
#define R_ARM_THM_PC11   102
/** thumb conditional branch */
#define R_ARM_THM_PC9   103
#define R_ARM_TLS_GD32   104
#define R_ARM_TLS_LDM32   105
#define R_ARM_TLS_LDO32   106
#define R_ARM_TLS_IE32   107
#define R_ARM_TLS_LE32   108
#define R_ARM_TLS_LDO12   109
#define R_ARM_TLS_LE12   110
#define R_ARM_TLS_IE12GP   111
#define R_ARM_RXPC25   249
#define R_ARM_RSBREL32   250
#define R_ARM_THM_RPC22   251
#define R_ARM_RREL32   252
#define R_ARM_RABS22   253
#define R_ARM_RPC24   254
#define R_ARM_RBASE   255
#define R_ARM_NUM   256

/* IA-64 SPECIFIC DECLARATIONS */
// Processor specific flags for the Ehdr e_flags field
/** os-specific flags */
#define EF_IA_64_MASKOS   0xf
/** 64-bit ABI */
#define EF_IA_64_ABI64   0x10
/** arch. version mask */
#define EF_IA_64_ARCH   0xff000000
// Processor specific values for the Phdr p_type field
/** arch extension bits */
#define PT_IA_64_ARCHEXT   (PT_LOPROC)
/** ia64 unwind bits */
#define PT_IA_64_UNWIND   (PT_LOPROC + 1)
#define PT_IA_64_HP_OPT_ANOT   (PT_LOOS + 0x12)
#define PT_IA_64_HP_HSL_ANOT   (PT_LOOS + 0x13)
#define PT_IA_64_HP_STACK   (PT_LOOS + 0x14)
// Processor specific flags for the Phdr p_flags field
/** spec insns w/o recovery */
#define PF_IA_64_NORECOV   0x80000000
// Processor specific values for the Shdr sh_type field
/** Extension bits */
#define SHT_IA_64_EXT   (SHT_LOPROC)
/** Unwind bits */
#define SHT_IA_64_UNWIND   (SHT_LOPROC + 1)
// Processor specific flags for the Shdr sh_flags field
/** Section near gp */
#define SHF_IA_64_SHORT   0x10000000
/** Spec insns w/o recovery */
#define SHF_IA_64_NORECOV   0x20000000
// Processor specific values for the Dyn d_tag field
#define DT_IA_64_PLT_RESERVE   (DT_LOPROC)
#define DT_IA_64_NUM   1

/* IA-64 RELOCATIONS */
/** none */
#define R_IA64_NONE   0
/** symbol + addend, add imm14 */
#define R_IA64_IMM14   0x21
/** symbol + addend, add imm22 */
#define R_IA64_IMM22   0x22
/** symbol + addend, mov imm64 */
#define R_IA64_IMM64   0x23
/** symbol + addend, data4 MSB */
#define R_IA64_DIR32MSB   0x24
/** symbol + addend, data4 LSB */
#define R_IA64_DIR32LSB   0x25
/** symbol + addend, data8 MSB */
#define R_IA64_DIR64MSB   0x26
/** symbol + addend, data8 LSB */
#define R_IA64_DIR64LSB   0x27
/** gprel(sym + add), add imm22 */
#define R_IA64_GPREL22   0x2a
/** gprel(sym + add), mov imm64 */
#define R_IA64_GPREL64I   0x2b
/** gprel(sym + add), data4 MSB */
#define R_IA64_GPREL32MSB   0x2c
/** gprel(sym + add), data4 LSB */
#define R_IA64_GPREL32LSB   0x2d
/** gprel(sym + add), data8 MSB */
#define R_IA64_GPREL64MSB   0x2e
/** gprel(sym + add), data8 LSB */
#define R_IA64_GPREL64LSB   0x2f
/** ltoff(sym + add), add imm22 */
#define R_IA64_LTOFF22   0x32
/** ltoff(sym + add), mov imm64 */
#define R_IA64_LTOFF64I   0x33
/** pltoff(sym + add), add imm22 */
#define R_IA64_PLTOFF22   0x3a
/** pltoff(sym + add), mov imm64 */
#define R_IA64_PLTOFF64I   0x3b
/** pltoff(sym + add), data8 MSB */
#define R_IA64_PLTOFF64MSB   0x3e
/** pltoff(sym + add), data8 LSB */
#define R_IA64_PLTOFF64LSB   0x3f
/** fptr(sym + add), mov imm64 */
#define R_IA64_FPTR64I   0x43
/** fptr(sym + add), data4 MSB */
#define R_IA64_FPTR32MSB   0x44
/** fptr(sym + add), data4 LSB */
#define R_IA64_FPTR32LSB   0x45
/** fptr(sym + add), data8 MSB */
#define R_IA64_FPTR64MSB   0x46
/** fptr(sym + add), data8 LSB */
#define R_IA64_FPTR64LSB   0x47
/** pcrel(sym + add), brl */
#define R_IA64_PCREL60B   0x48
/** pcrel(sym + add), ptb, call */
#define R_IA64_PCREL21B   0x49
/** pcrel(sym + add), chk.s */
#define R_IA64_PCREL21M   0x4a
/** pcrel(sym + add), fchkf */
#define R_IA64_PCREL21F   0x4b
/** pcrel(sym + add), data4 MSB */
#define R_IA64_PCREL32MSB   0x4c
/** pcrel(sym + add), data4 LSB */
#define R_IA64_PCREL32LSB   0x4d
/** pcrel(sym + add), data8 MSB */
#define R_IA64_PCREL64MSB   0x4e
/** pcrel(sym + add), data8 LSB */
#define R_IA64_PCREL64LSB   0x4f
/** ltoff(fptr(s+a)), imm22 */
#define R_IA64_LTOFF_FPTR22   0x52
/** ltoff(fptr(s+a)), imm64 */
#define R_IA64_LTOFF_FPTR64I   0x53
/** ltoff(fptr(s+a)), data4 MSB */
#define R_IA64_LTOFF_FPTR32MSB   0x54
/** ltoff(fptr(s+a)), data4 LSB */
#define R_IA64_LTOFF_FPTR32LSB   0x55
/** ltoff(fptr(s+a)), data8 MSB */
#define R_IA64_LTOFF_FPTR64MSB   0x56
/** ltoff(fptr(s+a)), data8 LSB */
#define R_IA64_LTOFF_FPTR64LSB   0x57
/** segrel(sym + add), data4 MSB */
#define R_IA64_SEGREL32MSB   0x5c
/** segrel(sym + add), data4 LSB */
#define R_IA64_SEGREL32LSB   0x5d
/** segrel(sym + add), data8 MSB */
#define R_IA64_SEGREL64MSB   0x5e
/** segrel(sym + add), data8 LSB */
#define R_IA64_SEGREL64LSB   0x5f
/** secrel(sym + add), data4 MSB */
#define R_IA64_SECREL32MSB   0x64
/** secrel(sym + add), data4 LSB */
#define R_IA64_SECREL32LSB   0x65
/** secrel(sym + add), data8 MSB */
#define R_IA64_SECREL64MSB   0x66
/** secrel(sym + add), data8 LSB */
#define R_IA64_SECREL64LSB   0x67
/** data 4 + REL */
#define R_IA64_REL32MSB   0x6c
/** data 4 + REL */
#define R_IA64_REL32LSB   0x6d
/** data 8 + REL */
#define R_IA64_REL64MSB   0x6e
/** data 8 + REL */
#define R_IA64_REL64LSB   0x6f
/** symbol + addend, data4 MSB */
#define R_IA64_LTV32MSB   0x74
/** symbol + addend, data4 LSB */
#define R_IA64_LTV32LSB   0x75
/** symbol + addend, data8 MSB */
#define R_IA64_LTV64MSB   0x76
/** symbol + addend, data8 LSB */
#define R_IA64_LTV64LSB   0x77
/** pcrel(sym + add), 21bit inst */
#define R_IA64_PCREL21BI   0x79
/** pcrel(sym + add), 22bit inst */
#define R_IA64_PCREL22   0x7a
/** pcrel(sym + add), 64bit inst */
#define R_IA64_PCREL64I   0x7b
/** dynamic reloc, imported PLT, MSB */
#define R_IA64_IPLTMSB   0x80
/** dynamic reloc, imported PLT, LSB */
#define R_IA64_IPLTLSB   0x81
/** copy relocation */
#define R_IA64_COPY   0x84
/** Addend and symbol difference */
#define R_IA64_SUB   0x85
/** LTOFF22, relaxable */
#define R_IA64_LTOFF22X   0x86
/** Use of LTOFF22X */
#define R_IA64_LDXMOV   0x87
/** tprel(sym + add), imm14 */
#define R_IA64_TPREL14   0x91
/** tprel(sym + add), imm22 */
#define R_IA64_TPREL22   0x92
/** tprel(sym + add), imm64 */
#define R_IA64_TPREL64I   0x93
/** tprel(sym + add), data8 MSB */
#define R_IA64_TPREL64MSB   0x96
/** tprel(sym + add), data8 LSB */
#define R_IA64_TPREL64LSB   0x97
/** ltoff(tprel(s+a)), imm2 */
#define R_IA64_LTOFF_TPREL22   0x9a
/** dtpmod(sym + add), data8 MSB */
#define R_IA64_DTPMOD64MSB   0xa6
/** dtpmod(sym + add), data8 LSB */
#define R_IA64_DTPMOD64LSB   0xa7
/** ltoff(dtpmod(sym + add)), imm22 */
#define R_IA64_LTOFF_DTPMOD22   0xaa
/** dtprel(sym + add), imm14 */
#define R_IA64_DTPREL14   0xb1
/** dtprel(sym + add), imm22 */
#define R_IA64_DTPREL22   0xb2
/** dtprel(sym + add), imm64 */
#define R_IA64_DTPREL64I   0xb3
/** dtprel(sym + add), data4 MSB */
#define R_IA64_DTPREL32MSB   0xb4
/** dtprel(sym + add), data4 LSB */
#define R_IA64_DTPREL32LSB   0xb5
/** dtprel(sym + add), data8 MSB */
#define R_IA64_DTPREL64MSB   0xb6
/** dtprel(sym + add), data8 LSB */
#define R_IA64_DTPREL64LSB   0xb7
/** ltoff(dtprel(s+a)), imm22 */
#define R_IA64_LTOFF_DTPREL22   0xba

/* SH SPECIFIC DECLARATIONS */
/** If set, this is a symbol pointing to SHmedia code, which will be branched to, so add 1 to the symbol value */
#define STO_SH5_ISA32   (4)

/* SH RELOCATIONS */
#define R_SH_NONE   0
#define R_SH_DIR32   1
#define R_SH_REL32   2
#define R_SH_DIR8WPN   3
#define R_SH_IND12W   4
#define R_SH_DIR8WPL   5
#define R_SH_DIR8WPZ   6
#define R_SH_DIR8BP   7
#define R_SH_DIR8W   8
#define R_SH_DIR8L   9
#define R_SH_SWITCH16   25
#define R_SH_SWITCH32   26
#define R_SH_USES   27
#define R_SH_COUNT   28
#define R_SH_ALIGN   29
#define R_SH_CODE   30
#define R_SH_DATA   31
#define R_SH_LABEL   32
#define R_SH_SWITCH8   33
#define R_SH_GNU_VTINHERIT   34
#define R_SH_GNU_VTENTRY   35
#define R_SH_TLS_GD_32   144
#define R_SH_TLS_LD_32   145
#define R_SH_TLS_LDO_32   146
#define R_SH_TLS_IE_32   147
#define R_SH_TLS_LE_32   148
#define R_SH_TLS_DTPMOD32   149
#define R_SH_TLS_DTPOFF32   150
#define R_SH_TLS_TPOFF32   151
#define R_SH_GOT32   160
#define R_SH_PLT32   161
#define R_SH_COPY   162
#define R_SH_GLOB_DAT   163
#define R_SH_JMP_SLOT   164
#define R_SH_RELATIVE   165
#define R_SH_GOTOFF   166
#define R_SH_GOTPC   167
#define R_SH_RELATIVE_LOW16   197
#define R_SH_RELATIVE_MEDLOW16   198
#define R_SH_IMM_LOW16   246
#define R_SH_IMM_LOW16_PCREL   247
#define R_SH_IMM_MEDLOW16   248
#define R_SH_IMM_MEDLOW16_PCREL   249
#define R_SH_NUM   256

/* ADDITIONAL S390 RELOCATIONS */
/** No reloc */
#define R_390_NONE   0
/** Direct 8 bit */
#define R_390_8   1
/** Direct 12 bit */
#define R_390_12   2
/** Direct 16 bit */
#define R_390_16   3
/** Direct 32 bit */
#define R_390_32   4
/** PC relative 32 bit */
#define R_390_PC32   5
/** 12 bit GOT offset */
#define R_390_GOT12   6
/** 32 bit GOT offset */
#define R_390_GOT32   7
/** 32 bit PC relative PLT address */
#define R_390_PLT32   8
/** Copy symbol at runtime */
#define R_390_COPY   9
/** Create GOT entry */
#define R_390_GLOB_DAT   10
/** Create PLT entry */
#define R_390_JMP_SLOT   11
/** Adjust by program base */
#define R_390_RELATIVE   12
/** 32 bit offset to GOT */
#define R_390_GOTOFF32   13
/** 32 bit PC relative offset to GOT */
#define R_390_GOTPC   14
/** 16 bit GOT offset */
#define R_390_GOT16   15
/** PC relative 16 bit */
#define R_390_PC16   16
/** PC relative 16 bit shifted by 1 */
#define R_390_PC16DBL   17
/** 16 bit PC rel. PLT shifted by 1 */
#define R_390_PLT16DBL   18
/** PC relative 32 bit shifted by 1 */
#define R_390_PC32DBL   19
/** 32 bit PC rel. PLT shifted by 1 */
#define R_390_PLT32DBL   20
/** 32 bit PC rel. GOT shifted by 1 */
#define R_390_GOTPCDBL   21
/** Direct 64 bit */
#define R_390_64   22
/** PC relative 64 bit */
#define R_390_PC64   23
/** 64 bit GOT offset */
#define R_390_GOT64   24
/** 64 bit PC relative PLT address */
#define R_390_PLT64   25
/** 32 bit PC rel. to GOT entry >> 1 */
#define R_390_GOTENT   26
/** 16 bit offset to GOT */
#define R_390_GOTOFF16   27
/** 64 bit offset to GOT */
#define R_390_GOTOFF64   28
/** 12 bit offset to jump slot */
#define R_390_GOTPLT12   29
/** 16 bit offset to jump slot */
#define R_390_GOTPLT16   30
/** 32 bit offset to jump slot */
#define R_390_GOTPLT32   31
/** 64 bit offset to jump slot */
#define R_390_GOTPLT64   32
/** 32 bit rel. offset to jump slot */
#define R_390_GOTPLTENT   33
/** 16 bit offset from GOT to PLT */
#define R_390_PLTOFF16   34
/** 32 bit offset from GOT to PLT */
#define R_390_PLTOFF32   35
/** 16 bit offset from GOT to PLT */
#define R_390_PLTOFF64   36
/** Tag for load insn in TLS code */
#define R_390_TLS_LOAD   37
/** Tag for function call in general dynamic TLS code */
#define R_390_TLS_GDCALL   38
/** Tag for function call in local dynamic TLS code */
#define R_390_TLS_LDCALL   39
/** Direct 32 bit for general dynamic thread local data */
#define R_390_TLS_GD32   40
/** Direct 64 bit for general dynamic thread local data */
#define R_390_TLS_GD64   41
/** 12 bit GOT offset for static TLS block offset */
#define R_390_TLS_GOTIE12   42
/** 32 bit GOT offset for static TLS block offset */
#define R_390_TLS_GOTIE32   43
/** 64 bit GOT offset for static TLS block offset */
#define R_390_TLS_GOTIE64   44
/** Direct 32 bit for local dynamic thread local data in LE code */
#define R_390_TLS_LDM32   45
/** Direct 64 bit for local dynamic thread local data in LE code */
#define R_390_TLS_LDM64   46
/** 32 bit address of GOT entry for negated static TLS block offset */
#define R_390_TLS_IE32   47
/** 64 bit address of GOT entry for negated static TLS block offset */
#define R_390_TLS_IE64   48
/** 32 bit rel. offset to GOT entry for negated static TLS block offset */
#define R_390_TLS_IEENT   49
/** 32 bit negated offset relative to static TLS block */
#define R_390_TLS_LE32   50
/** 64 bit negated offset relative to static TLS block */
#define R_390_TLS_LE64   51
/** 32 bit offset relative to TLS block */
#define R_390_TLS_LDO32   52
/** 64 bit offset relative to TLS block */
#define R_390_TLS_LDO64   53
/** ID of module containing symbol */
#define R_390_TLS_DTPMOD   54
/** Offset in TLS block */
#define R_390_TLS_DTPOFF   55
/** Negated offset in static TLS block */
#define R_390_TLS_TPOFF   56
/** Direct 20 bit */
#define R_390_20   57
/** 20 bit GOT offset */
#define R_390_GOT20   58
/** 20 bit offset to jump slot */
#define R_390_GOTPLT20   59
/** 20 bit GOT offset for static TLS block offset */
#define R_390_TLS_GOTIE20   60
#define R_390_NUM   61

/* CRIS FLAGS */
#define EF_CRIS_VARIANT_MASK   0xe
#define EF_CRIS_VARIANT_ANY_V0_V10   0
#define EF_CRIS_VARIANT_V32   2
#define EF_CRIS_VARIANT_COMMON_V10_V32   4

/* CRIS RELOCATIONS */
#define R_CRIS_NONE   0
#define R_CRIS_8   1
#define R_CRIS_16   2
#define R_CRIS_32   3
#define R_CRIS_8_PCREL   4
#define R_CRIS_16_PCREL   5
#define R_CRIS_32_PCREL   6
#define R_CRIS_GNU_VTINHERIT   7
#define R_CRIS_GNU_VTENTRY   8
#define R_CRIS_COPY   9
#define R_CRIS_GLOB_DAT   10
#define R_CRIS_JUMP_SLOT   11
#define R_CRIS_RELATIVE   12
#define R_CRIS_16_GOT   13
#define R_CRIS_32_GOT   14
#define R_CRIS_16_GOTPLT   15
#define R_CRIS_32_GOTPLT   16
#define R_CRIS_32_GOTREL   17
#define R_CRIS_32_PLT_GOTREL   18
#define R_CRIS_32_PLT_PCREL   19
#define R_CRIS_NUM   20

/* AMD/X86-64 RELOCATIONS */
/** No reloc */
#define R_X86_64_NONE   0
/** Direct 64 bit */
#define R_X86_64_64   1
/** PC relative 32 bit signed */
#define R_X86_64_PC32   2
/** 32 bit GOT entry */
#define R_X86_64_GOT32   3
/** 32 bit PLT address */
#define R_X86_64_PLT32   4
/** Copy symbol at runtime */
#define R_X86_64_COPY   5
/** Create GOT entry */
#define R_X86_64_GLOB_DAT   6
/** Create PLT entry */
#define R_X86_64_JUMP_SLOT   7
/** Adjust by program base */
#define R_X86_64_RELATIVE   8
/** 32 bit signed PC relative offset to GOT */
#define R_X86_64_GOTPCREL   9
/** Direct 32 bit zero extended */
#define R_X86_64_32   10
/** Direct 32 bit sign extended */
#define R_X86_64_32S   11
/** Direct 16 bit zero extended */
#define R_X86_64_16   12
/** 16 bit sign extended pc relative */
#define R_X86_64_PC16   13
/** Direct 8 bit sign extended */
#define R_X86_64_8   14
/** 8 bit sign extended pc relative */
#define R_X86_64_PC8   15
/** ID of module containing symbol */
#define R_X86_64_DTPMOD64   16
/** Offset in module's TLS block */
#define R_X86_64_DTPOFF64   17
/** Offset in initial TLS block */
#define R_X86_64_TPOFF64   18
/** 32 bit signed PC relative offset to two GOT entries for GD symbol */
#define R_X86_64_TLSGD   19
/** 32 bit signed PC relative offset to two GOT entries for LD symbol */
#define R_X86_64_TLSLD   20
/** Offset in TLS block */
#define R_X86_64_DTPOFF32   21
/** 32 bit signed PC relative offset to GOT entry for IE symbol */
#define R_X86_64_GOTTPOFF   22
/** Offset in initial TLS block */
#define R_X86_64_TPOFF32   23
#define R_X86_64_NUM   24

/* AM33 RELOCATIONS */
/** No reloc */
#define R_MN10300_NONE   0
/** Direct 32 bit */
#define R_MN10300_32   1
/** Direct 16 bit */
#define R_MN10300_16   2
/** Direct 8 bit */
#define R_MN10300_8   3
/** PC-relative 32-bit */
#define R_MN10300_PCREL32   4
/** PC-relative 16-bit signed */
#define R_MN10300_PCREL16   5
/** PC-relative 8-bit signed */
#define R_MN10300_PCREL8   6
/** Ancient C++ vtable garbage */
#define R_MN10300_GNU_VTINHERIT   7
/** Collection annotation */
#define R_MN10300_GNU_VTENTRY   8
/** Direct 24 bit */
#define R_MN10300_24   9
/** 32-bit PCrel offset to GOT */
#define R_MN10300_GOTPC32   10
/** 16-bit PCrel offset to GOT */
#define R_MN10300_GOTPC16   11
/** 32-bit offset from GOT */
#define R_MN10300_GOTOFF32   12
/** 24-bit offset from GOT */
#define R_MN10300_GOTOFF24   13
/** 16-bit offset from GOT */
#define R_MN10300_GOTOFF16   14
/** 32-bit PCrel to PLT entry */
#define R_MN10300_PLT32   15
/** 16-bit PCrel to PLT entry */
#define R_MN10300_PLT16   16
/** 32-bit offset to GOT entry */
#define R_MN10300_GOT32   17
/** 24-bit offset to GOT entry */
#define R_MN10300_GOT24   18
/** 16-bit offset to GOT entry */
#define R_MN10300_GOT16   19
/** Copy symbol at runtime */
#define R_MN10300_COPY   20
/** Create GOT entry */
#define R_MN10300_GLOB_DAT   21
/** Create PLT entry */
#define R_MN10300_JMP_SLOT   22
/** Adjust by program base */
#define R_MN10300_RELATIVE   23
#define R_MN10300_NUM   24

/* M32R RELOCATIONS */
/** No reloc */
#define R_M32R_NONE   0
/** Direct 16 bit */
#define R_M32R_16   1
/** Direct 32 bit */
#define R_M32R_32   2
/** Direct 24 bit */
#define R_M32R_24   3
/** PC relative 10 bit shifted */
#define R_M32R_10_PCREL   4
/** PC relative 18 bit shifted */
#define R_M32R_18_PCREL   5
/** PC relative 26 bit shifted */
#define R_M32R_26_PCREL   6
/** High 16 bit with unsigned low */
#define R_M32R_HI16_ULO   7
/** High 16 bit with signed low */
#define R_M32R_HI16_SLO   8
/** Low 16 bit */
#define R_M32R_LO16   9
/** 16 bit offset in SDA */
#define R_M32R_SDA16   10
#define R_M32R_GNU_VTINHERIT   11
#define R_M32R_GNU_VTENTRY   12
// M32R relocs use SHT_RELA
/** Direct 16 bit */
#define R_M32R_16_RELA   33
/** Direct 32 bit */
#define R_M32R_32_RELA   34
/** Direct 24 bit */
#define R_M32R_24_RELA   35
/** PC relative 10 bit shifted */
#define R_M32R_10_PCREL_RELA   36
/** PC relative 18 bit shifted */
#define R_M32R_18_PCREL_RELA   37
/** PC relative 26 bit shifted */
#define R_M32R_26_PCREL_RELA   38
/** High 16 bit with unsigned low */
#define R_M32R_HI16_ULO_RELA   39
/** High 16 bit with signed low */
#define R_M32R_HI16_SLO_RELA   40
/** Low 16 bit */
#define R_M32R_LO16_RELA   41
/** 16 bit offset in SDA */
#define R_M32R_SDA16_RELA   42
#define R_M32R_RELA_GNU_VTINHERIT   43
#define R_M32R_RELA_GNU_VTENTRY   44
/** 24 bit GOT entry */
#define R_M32R_GOT24   48
/** 26 bit PC relative to PLT shifted */
#define R_M32R_26_PLTREL   49
/** Copy symbol at runtime */
#define R_M32R_COPY   50
/** Create GOT entry */
#define R_M32R_GLOB_DAT   51
/** Create PLT entry */
#define R_M32R_JMP_SLOT   52
/** Adjust by program base */
#define R_M32R_RELATIVE   53
/** 24 bit offset to GOT */
#define R_M32R_GOTOFF   54
/** 24 bit PC relative offset to GOT */
#define R_M32R_GOTPC24   55
/** High 16 bit GOT entry with unsigned low */
#define R_M32R_GOT16_HI_ULO   56
/** High 16 bit GOT entry with signed low */
#define R_M32R_GOT16_HI_SLO   57
/** Low 16 bit GOT entry */
#define R_M32R_GOT16_LO   58
/** High 16 bit PC relative offset to GOT with unsigned low */
#define R_M32R_GOTPC_HI_ULO   59
/** High 16 bit PC relative offset to GOT with signed low */
#define R_M32R_GOTPC_HI_SLO   60
/** Low 16 bit PC relative offset to GOT */
#define R_M32R_GOTPC_LO   61
/** High 16 bit offset to GOT with unsigned low */
#define R_M32R_GOTOFF_HI_ULO   62
/** High 16 bit offset to GOT with signed low */
#define R_M32R_GOTOFF_HI_SLO   63
/** Low 16 bit offset to GOT */
#define R_M32R_GOTOFF_LO   64
/** Keep this the last entry */
#define R_M32R_NUM   256

/* I960 RELOCATIONS */
#define R_960_NONE   0
#define R_960_12   1
#define R_960_32   2
#define R_960_IP24   3
#define R_960_SUB   4
#define R_960_OPTCALL   5
#define R_960_OPTCALLX   6
#define R_960_OPTCALLXA   7
#define R_960_NUM   8

/* V850 RELOCATIONS */
#define R_V850_NONE   0
#define R_V850_9_PCREL   1
#define R_V850_22_PCREL   2
#define R_V850_HI16_S   3
#define R_V850_HI16   4
#define R_V850_LO16   5
#define R_V850_32   6
#define R_V850_16   7
#define R_V850_8   8
/** For ld.b, st.b, set1, clr1, not1, tst1, movea, movhi */
#define R_V850_SDA_16_16_OFFSET   9
/** For ld.w, ld.h, ld.hu, st.w, st.h */
#define R_V850_SDA_15_16_OFFSET   10
/** For ld.b, st.b, set1, clr1, not1, tst1, movea, movhi */
#define R_V850_ZDA_16_16_OFFSET   11
/** For ld.w, ld.h, ld.hu, st.w, st.h */
#define R_V850_ZDA_15_16_OFFSET   12
/** For sst.w, sld.w */
#define R_V850_TDA_6_8_OFFSET   13
/** For sst.h, sld.h */
#define R_V850_TDA_7_8_OFFSET   14
/** For sst.b, sld.b */
#define R_V850_TDA_7_7_OFFSET   15
/** For set1, clr1, not1, tst1, movea, movhi */
#define R_V850_TDA_16_16_OFFSET   16
// CYGNUS LOCAL v850e
/** For sld.hu */
#define R_V850_TDA_4_5_OFFSET   17
/** For sld.bu */
#define R_V850_TDA_4_4_OFFSET   18
/** For ld.bu */
#define R_V850_SDA_16_16_SPLIT_OFFSET   19
/** For ld.bu */
#define R_V850_ZDA_16_16_SPLIT_OFFSET   20
/** For callt */
#define R_V850_CALLT_6_7_OFFSET   21
/** For callt */
#define R_V850_CALLT_16_16_OFFSET   22
// END CYGNUS LOCAL
#define R_V850_GNU_VTINHERIT   23
#define R_V850_GNU_VTENTRY   24
#define R_V850_NUM   25

/* ATMEL AVR32 RELOCATIONS */
#define R_AVR32_NONE   0
#define R_AVR32_32   1
#define R_AVR32_16   2
#define R_AVR32_8   3
#define R_AVR32_32_PCREL   4
#define R_AVR32_16_PCREL   5
#define R_AVR32_8_PCREL   6
#define R_AVR32_DIFF32   7
#define R_AVR32_DIFF16   8
#define R_AVR32_DIFF8   9
#define R_AVR32_GOT32   10
#define R_AVR32_GOT16   11
#define R_AVR32_GOT8   12
#define R_AVR32_21S   13
#define R_AVR32_16U   14
#define R_AVR32_16S   15
#define R_AVR32_8S   16
#define R_AVR32_8S_EXT   17
#define R_AVR32_22H_PCREL   18
#define R_AVR32_18W_PCREL   19
#define R_AVR32_16B_PCREL   20
#define R_AVR32_16N_PCREL   21
#define R_AVR32_14UW_PCREL   22
#define R_AVR32_11H_PCREL   23
#define R_AVR32_10UW_PCREL   24
#define R_AVR32_9H_PCREL   25
#define R_AVR32_9UW_PCREL   26
#define R_AVR32_HI16   27
#define R_AVR32_LO16   28
#define R_AVR32_GOTPC   29
#define R_AVR32_GOTCALL   30
#define R_AVR32_LDA_GOT   31
#define R_AVR32_GOT21S   32
#define R_AVR32_GOT18SW   33
#define R_AVR32_GOT16S   34
#define R_AVR32_GOT7UW   35
#define R_AVR32_32_CPENT   36
#define R_AVR32_CPCALL   37
#define R_AVR32_16_CP   38
#define R_AVR32_9W_CP   39
#define R_AVR32_RELATIVE   40
#define R_AVR32_GLOB_DAT   41
#define R_AVR32_JMP_SLOT   42
#define R_AVR32_ALIGN   43
#define R_AVR32_NUM   44
/** Total size of GOT in bytes (dynamic tag) */
#define DT_AVR32_GOTSZ   0x70000001

/* RENESAS H8/300 RELOCATIONS */
#define R_H8_NONE   0
#define R_H8_DIR32   1
#define R_H8_DIR32_28   2
#define R_H8_DIR32_24   3
#define R_H8_DIR32_16   4
#define R_H8_DIR32U   6
#define R_H8_DIR32U_28   7
#define R_H8_DIR32U_24   8
#define R_H8_DIR32U_20   9
#define R_H8_DIR32U_16   10
#define R_H8_DIR24   11
#define R_H8_DIR24_20   12
#define R_H8_DIR24_16   13
#define R_H8_DIR24U   14
#define R_H8_DIR24U_20   15
#define R_H8_DIR24U_16   16
#define R_H8_DIR16   17
#define R_H8_DIR16U   18
#define R_H8_DIR16S_32   19
#define R_H8_DIR16S_28   20
#define R_H8_DIR16S_24   21
#define R_H8_DIR16S_20   22
#define R_H8_DIR16S   23
#define R_H8_DIR8   24
#define R_H8_DIR8U   25
#define R_H8_DIR8Z_32   26
#define R_H8_DIR8Z_28   27
#define R_H8_DIR8Z_24   28
#define R_H8_DIR8Z_20   29
#define R_H8_DIR8Z_16   30
#define R_H8_PCREL16   31
#define R_H8_PCREL8   32
#define R_H8_BPOS   33
#define R_H8_PCREL32   34
#define R_H8_GOT32O   35
#define R_H8_GOT16O   36
#define R_H8_DIR16A8   59
#define R_H8_DIR16R8   60
#define R_H8_DIR24A8   61
#define R_H8_DIR24R8   62
#define R_H8_DIR32A16   63
#define R_H8_ABS32   65
#define R_H8_ABS32A16   127
#define R_H8_NUM   128

/* NIOS RELOCATIONS */
#define R_NIOS_NONE   0
/** A 32 bit absolute relocation */
#define R_NIOS_32   1
/** A LO-16 5 bit absolute relocation */
#define R_NIOS_LO16_LO5   2
/** A LO-16 top 11 bit absolute relocation */
#define R_NIOS_LO16_HI11   3
/** A HI-16 5 bit absolute relocation */
#define R_NIOS_HI16_LO5   4
/** A HI-16 top 11 bit absolute relocation */
#define R_NIOS_HI16_HI11   5
/** A 6 bit relative relocation */
#define R_NIOS_PCREL6   6
/** An 8 bit relative relocation */
#define R_NIOS_PCREL8   7
/** An 11 bit relative relocation */
#define R_NIOS_PCREL11   8
/** A 16 bit absolute relocation */
#define R_NIOS_16   9
/** Low 5-bits of absolute relocation in halfwords */
#define R_NIOS_H_LO5   10
/** Top 11 bits of 16-bit absolute relocation in halfwords */
#define R_NIOS_H_HI11   11
/** Low 5 bits of top 16-bits of 32-bit absolute relocation in halfwords */
#define R_NIOS_H_XLO5   12
/** Top 11 bits of top 16-bits of 32-bit absolute relocation in halfwords */
#define R_NIOS_H_XHI11   13
/** Half-word h value */
#define R_NIOS_H_16   14
/** Word h value */
#define R_NIOS_H_32   15
/** GNU extension to record C++ vtable hierarchy */
#define R_NIOS_GNU_VTINHERIT   200
/** GNU extension to record C++ vtable member usage */
#define R_NIOS_GNU_VTENTRY   201
#define R_NIOS_NUM   202

/* NIOS II RELOCATIONS */
#define R_NIOS2_NONE   0
#define R_NIOS2_S16   1
#define R_NIOS2_U16   2
#define R_NIOS2_PCREL16   3
#define R_NIOS2_CALL26   4
#define R_NIOS2_IMM5   5
#define R_NIOS2_CACHE_OPX   6
#define R_NIOS2_IMM6   7
#define R_NIOS2_IMM8   8
#define R_NIOS2_HI16   9
#define R_NIOS2_LO16   10
#define R_NIOS2_HIADJ16   11
#define R_NIOS2_BFD_RELOC_32   12
#define R_NIOS2_BFD_RELOC_16   13
#define R_NIOS2_BFD_RELOC_8   14
#define R_NIOS2_GPREL   15
#define R_NIOS2_GNU_VTINHERIT   16
#define R_NIOS2_GNU_VTENTRY   17
#define R_NIOS2_UJMP   18
#define R_NIOS2_CJMP   19
#define R_NIOS2_CALLR   20
#define R_NIOS2_ALIGN   21
#define R_NIOS2_NUM   22

/* XTENSA-SPECIFIC DECLARATIONS */
// Xtensa values for the Dyn d_tag field
#define DT_XTENSA_GOT_LOC_OFF   (DT_LOPROC)
#define DT_XTENSA_GOT_LOC_SZ   (DT_LOPROC + 1)
#define DT_XTENSA_NUM   2
// Xtensa relocations
#define R_XTENSA_NONE   0
#define R_XTENSA_32   1
#define R_XTENSA_RTLD   2
#define R_XTENSA_GLOB_DAT   3
#define R_XTENSA_JMP_SLOT   4
#define R_XTENSA_RELATIVE   5
#define R_XTENSA_PLT   6
#define R_XTENSA_OP0   8
#define R_XTENSA_OP1   9
#define R_XTENSA_OP2   10
#define R_XTENSA_ASM_EXPAND   11
#define R_XTENSA_ASM_SIMPLIFY   12
#define R_XTENSA_GNU_VTINHERIT   15
#define R_XTENSA_GNU_VTENTRY   16
#define R_XTENSA_DIFF8   17
#define R_XTENSA_DIFF16   18
#define R_XTENSA_DIFF32   19
#define R_XTENSA_SLOT0_OP   20
#define R_XTENSA_SLOT1_OP   21
#define R_XTENSA_SLOT2_OP   22
#define R_XTENSA_SLOT3_OP   23
#define R_XTENSA_SLOT4_OP   24
#define R_XTENSA_SLOT5_OP   25
#define R_XTENSA_SLOT6_OP   26
#define R_XTENSA_SLOT7_OP   27
#define R_XTENSA_SLOT8_OP   28
#define R_XTENSA_SLOT9_OP   29
#define R_XTENSA_SLOT10_OP   30
#define R_XTENSA_SLOT11_OP   31
#define R_XTENSA_SLOT12_OP   32
#define R_XTENSA_SLOT13_OP   33
#define R_XTENSA_SLOT14_OP   34
#define R_XTENSA_SLOT0_ALT   35
#define R_XTENSA_SLOT1_ALT   36
#define R_XTENSA_SLOT2_ALT   37
#define R_XTENSA_SLOT3_ALT   38
#define R_XTENSA_SLOT4_ALT   39
#define R_XTENSA_SLOT5_ALT   40
#define R_XTENSA_SLOT6_ALT   41
#define R_XTENSA_SLOT7_ALT   42
#define R_XTENSA_SLOT8_ALT   43
#define R_XTENSA_SLOT9_ALT   44
#define R_XTENSA_SLOT10_ALT   45
#define R_XTENSA_SLOT11_ALT   46
#define R_XTENSA_SLOT12_ALT   47
#define R_XTENSA_SLOT13_ALT   48
#define R_XTENSA_SLOT14_ALT   49
#define R_XTENSA_NUM   50

/* C6X SPECIFIC RELOCS */
#define R_C6000_NONE   0
#define R_C6000_ABS32   1
#define R_C6000_ABS16   2
#define R_C6000_ABS8   3
#define R_C6000_PCR_S21   4
#define R_C6000_PCR_S12   5
#define R_C6000_PCR_S10   6
#define R_C6000_PCR_S7   7
#define R_C6000_ABS_S16   8
#define R_C6000_ABS_L16   9
#define R_C6000_ABS_H16   10
#define R_C6000_SBR_U15_B   11
#define R_C6000_SBR_U15_H   12
#define R_C6000_SBR_U15_W   13
#define R_C6000_SBR_S16   14
#define R_C6000_SBR_L16_B   15
#define R_C6000_SBR_L16_H   16
#define R_C6000_SBR_L16_W   17
#define R_C6000_SBR_H16_B   18
#define R_C6000_SBR_H16_H   19
#define R_C6000_SBR_H16_W   20
#define R_C6000_SBR_GOT_U15_W   21
#define R_C6000_SBR_GOT_L16_W   22
#define R_C6000_SBR_GOT_H16_W   23
#define R_C6000_DSBT_INDEX   24
#define R_C6000_PREL31   25
#define R_C6000_COPY   26
#define R_C6000_JUMP_SLOT   27
#define R_C6000_SBR_GOT32   28
#define R_C6000_PCR_H16   29
#define R_C6000_PCR_L16   30
#define R_C6000_ALIGN   253
#define R_C6000_FPHEAD   254
#define R_C6000_NOCMP   255
/* C6X SPECIFIC VALUES FOR THE DYN D_TAG FIELD */
#define DT_C6000_DSBT_BASE   (DT_LOPROC)
#define DT_C6000_DSBT_SIZE   (DT_LOPROC + 1)
#define DT_C6000_PREEMPTMAP   (DT_LOPROC + 2)
#define DT_C6000_DSBT_INDEX   (DT_LOPROC + 3)
#define DT_C6000_NUM   4

/* MICROBLAZE SPECIFIC RELOCS */
#define R_MICROBLAZE_NONE   0
#define R_MICROBLAZE_32   1
#define R_MICROBLAZE_32_PCREL   2
#define R_MICROBLAZE_64_PCREL   3
#define R_MICROBLAZE_32_PCREL_LO   4
#define R_MICROBLAZE_64   5
#define R_MICROBLAZE_32_LO   6
#define R_MICROBLAZE_SRO32   7
#define R_MICROBLAZE_SRW32   8
#define R_MICROBLAZE_64_NONE   9
#define R_MICROBLAZE_32_SYM_OP_SYM   10
#define R_MICROBLAZE_GNU_VTINHERIT   11
#define R_MICROBLAZE_GNU_VTENTRY   12
/** PC-relative GOT offset */
#define R_MICROBLAZE_GOTPC_64   13
/** GOT entry offset */
#define R_MICROBLAZE_GOT_64   14
/** PLT offset; PC-relative */
#define R_MICROBLAZE_PLT_64   15
/** Adjust by program base */
#define R_MICROBLAZE_REL   16
/** Create PLT entry */
#define R_MICROBLAZE_JUMP_SLOT   17
/** Create GOT entry */
#define R_MICROBLAZE_GLOB_DAT   18
/** Offset relative to GOT */
#define R_MICROBLAZE_GOTOFF_64   19
/** Offset relative to GOT */
#define R_MICROBLAZE_GOTOFF_32   20
/** Runtime copy */
#define R_MICROBLAZE_COPY   21
#define R_MICROBLAZE_NUM   22


#if LONG_EQ_32BITS
typedef Elf32_Ehdr   Ehdr;
typedef Elf32_Phdr   Phdr;
typedef Elf32_Sym   Sym;
typedef Elf32_Verdef   Verdef;
typedef Elf32_Verdaux   Verdaux;
#else
typedef Elf64_Ehdr   Ehdr;
typedef Elf64_Phdr   Phdr;
typedef Elf64_Sym   Sym;
typedef Elf64_Verdef   Verdef;
typedef Elf64_Verdaux   Verdaux;
#endif


LIB_FUNC int checkver(Verdef* restrict def, int vsym, const char* restrict vername, const char* restrict strings) {
	vsym &= 0x7fff;
	loop_forever {
		if (!(def->vd_flags & VER_FLG_BASE) && (def->vd_ndx & 0x7fff) == vsym) { break; }
		else if (def->vd_next == 0) { return 0; }
		def = (Verdef*)((char*)def + def->vd_next);
	}
	Verdaux* aux = (Verdaux*)((char*)def + def->vd_aux);
	return (int)(!strcmp(vername, (strings + aux->vda_name)));
}


LIB_FUNC void* __vdsosym(const char* vername, const char* name) {
	size_t i;
	for (i = 0; libc.auxv[i] != AT_SYSINFO_EHDR; i += 2) { if (!libc.auxv[i]) { return 0; } }
	Ehdr* eh = (void*)libc.auxv[i + 1];
	Phdr* ph = (void*)((char*)eh + eh->e_phoff);
	size_t* dynv = 0;
	register size_t base;
	for (i = 0; i < eh->e_phnum; i++, ph = (void*)((char*)ph + eh->e_phentsize)) {
		if (ph->p_type == PT_LOAD) { base = (size_t)eh + ph->p_offset - ph->p_vaddr; }
		else if (ph->p_type == PT_DYNAMIC) { dynv = (void*)((char*)eh + ph->p_offset); }
	}
	if (!dynv || base == (size_t)-1) { return 0; }
	char* strings = 0;
	Sym* syms = 0;
	uint32_t* hashtab = 0;
	uint16_t* versym = 0;
	Verdef* verdef = 0;
	for (i = 0; dynv[i]; i += 2) {
		void* p = (void*)(base + dynv[i + 1]);
		switch (dynv[i]) {
			case DT_STRTAB: strings = p; break;
			case DT_SYMTAB: syms = p; break;
			case DT_HASH: hashtab = p; break;
			case DT_VERSYM: versym = p; break;
			case DT_VERDEF: verdef = p; break;
			default: break;
		}
	}
	if (!strings || !syms || !hashtab) { return 0; }
	else if (!verdef) { versym = 0; }
	for (i = 0; i < hashtab[1]; i++) {
		if (!(1 << (syms[i].st_info & 0xf) & OK_TYPES)) { continue; }
		else if (!(1 << (syms[i].st_info >> 4) & OK_BINDS)) { continue; }
		else if (!syms[i].st_shndx) { continue; }
		else if (strcmp(name, strings + syms[i].st_name)) { continue; }
		else if (versym && (!checkver(verdef, versym[i], vername, strings))) { continue; }
		return (void*)(base + syms[i].st_value);
	}
	return 0;
}


#endif  // ELF_H


/* MD4 (<md4.h>) */


#if (!(defined(_MD4_H) || defined(_MD4_H_) || defined(_SYS_MD4_H) || defined(_SYS_MD4_H_)))
#define _MD4_H   (1)
#define _MD4_H_   (1)
#define _SYS_MD4_H   (1)
#define _SYS_MD4_H_   (1)


/** MD4 context */
typedef struct MD4Context {
	uint32_t state[4];  //!< State (ABCD)
	uint32_t count[2];  //!< Number of bits, modulo 2^64 (lsb first)
	unsigned char buffer[64];  //!< Input buffer
} MD4_CTX;


/* TODO: Add MD4 functions
void MD4Init(MD4_CTX *);
void MD4Update(MD4_CTX *, const unsigned char *, unsigned int);
void MD4Pad(MD4_CTX *);
void MD4Final(unsigned char [16], MD4_CTX *);
char* MD4End(MD4_CTX *, char *);
char* MD4File(const char *, char *);
char* MD4Data(const unsigned char *, unsigned int, char *);
*/


#endif  // MD4_H


/* MD5 (<md5.h>) */


#if (!(defined(_SYS_MD5_H) || defined(_SYS_MD5_H_) || defined(_MD5_H) || defined(_MD5_H_)))
#define _MD5_H   (1)
#define _MD5_H_   (1)
#define _SYS_MD5_H   (1)
#define _SYS_MD5_H_   (1)


#define MD5_BLOCK_LENGTH   64
#define MD5_DIGEST_LENGTH   16
#define MD5_DIGEST_STRING_LENGTH   ((MD5_DIGEST_LENGTH * 2) + 1)


/** MD5 context */
typedef struct MD5Context {
	uint32_t state[4];  //!< State (ABCD)
	uint32_t count[2];  //!< Number of bits, modulo 2^64 (lsb first)
	unsigned char buffer[64];  //!< Input buffer
} MD5_CTX;


typedef int16_t   md5_int16;
#define md5_int16_t   md5_int16
typedef uint16_t   md5_uint16;
#define md5_uint16_t   md5_uint16
typedef int32_t   md5_int32;
#define md5_int32_t   md5_int32
typedef uint32_t   md5_uint32;
#define md5_uint32_t   md5_uint32
typedef intptr_t   md5_intptr;
typedef uintptr_t   md5_uintptr;
/** Structure to save state of computation between the single steps */
typedef struct md5_ctx {
	md5_uint32 A, B, C, D;
	md5_uint32 total[2];
	md5_uint32 buflen;
	char ATTR_ALIGN_TO(md5_uint32) buffer[128];
} md5_ctx_t;


/* TODO: Add MD5 Functions
void MD5Init (MD5_CTX *);
extern void md5_init_ctx(struct md5_ctx *ctx);
void MD5Update (MD5_CTX *, const unsigned char *, unsigned int);
void MD5Final (unsigned char [16], MD5_CTX *);
char* MD5End(MD5_CTX *, char *);
char* MD5File(const char *, char *);
char* MD5FileChunk(const char *, char *, off_t, off_t);
char* MD5Data(const unsigned char *, unsigned int, char *);
extern void md5_process_block(const void *buffer, size_t len, struct md5_ctx *ctx);
extern void md5_process_bytes(const void *buffer, size_t len, struct md5_ctx *ctx);
extern void *md5_finish_ctx(struct md5_ctx *ctx, void *resbuf);
extern void *md5_read_ctx(const struct md5_ctx *ctx, void *resbuf);
extern int md5_stream(FILE *stream, void *resblock);
extern void *md5_buffer(const char *buffer, size_t len, void *resblock);
*/


#endif  // SYS_MD5_H

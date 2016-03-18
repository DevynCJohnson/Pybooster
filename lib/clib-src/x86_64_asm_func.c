// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file x86_64_asm_func.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief x86-64 Assembly Functions
@version 2016.03.18

@section DESCRIPTION
C-functions containing inlined x86-64 Assembly (AT&T syntax)

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.
*/


#include "x86_64_asm_func.h"


/* GET GPU INFO */


#ifdef __amd64__
/** Return the name of the system's AMD GPU device (if detected and known) */
const char *amd_gpu(void) {
#ifdef __WinterPark__
    return "WinterPark";
#elif defined(__BeaverCreek__)
    return "BeaverCreek";
#elif defined(__Turks__)
    return "Turks";
#elif defined(__Caicos__)
    return "Caicos";
#elif defined(__Tahiti__)
    return "Tahiti";
#elif defined(__Pitcairn__)
    return "Pitcairn";
#elif defined(__Capeverde__)
    return "Capeverde";
#elif defined(__Cayman__)
    return "Cayman";
#elif defined(__Barts__)
    return "Barts";
#elif defined(__Cypress__)
    return "Cypress";
#elif defined(__Juniper__)
    return "Juniper";
#elif defined(__Redwood__)
    return "Redwood";
#elif defined(__Cedar__)
    return "Cedar";
#elif defined(__ATI_RV770__)
    return "ATI_RV770";
#elif defined(__ATI_RV730__)
    return "ATI_RV730";
#elif defined(__ATI_RV710__)
    return "ATI_RV710";
#elif defined(__Loveland__)
    return "Loveland";
#elif defined(__Hawaii__)
    return "Hawaii";
#else
    return "Unknown";
#endif
}
#endif


#if (defined(ENV64BIT) && (defined(__x86_64__) || defined(__x86_64))) && !(defined(ENV32BIT))


/* GET CPU INFO */


/** The rdtsc (Read Time-Stamp Counter) instruction is used to determine how many CPU ticks occurred since the processor was reset */
ullint rdtsc(void) {
    register ullint cpu_ticks;
    __asm__ volatile ("rdtsc;" : "=A" ( cpu_ticks ));  // `=A` is `edx:eax`
    return cpu_ticks;
}


/** Return the vendor ID of the x86 CPU (Assumes little-endian) */
const char *get_vendor_id(void) {
    int ebx, edx, ecx;
    __asm__ (
        "movl $0,%%eax;"
        "cpuid;"
        "movl %%ecx,%0;"
        "movl %%edx,%1;"
        "movl %%ebx,%2;"
        : "=r" ( ebx ), "=r" ( edx ), "=r" ( ecx )  // Output C variable
        :  // No input variables
        : "ebx", "edx", "ecx"  // Clobbered Register
    );
    static char vendor[16];
    vendor[13] = '\0';
    vendor[12] = '\0';
    vendor[11] = (char)((ebx >> 24) & 0xFF);
    vendor[10] = (char)((ebx >> 16) & 0xFF);
    vendor[9] = (char)((ebx >> 8) & 0xFF);
    vendor[8] = (char)(ebx & 0xFF);
    vendor[7] = (char)((edx >> 24) & 0xFF);
    vendor[6] = (char)((edx >> 16) & 0xFF);
    vendor[5] = (char)((edx >> 8) & 0xFF);
    vendor[4] = (char)(edx & 0xFF);
    vendor[3] = (char)((ecx >> 24) & 0xFF);
    vendor[2] = (char)((ecx >> 16) & 0xFF);
    vendor[1] = (char)((ecx >> 8) & 0xFF);
    vendor[0] = (char)(ecx & 0xFF);
    return vendor;
}


/** Get the stepping value of the CPU */
signed int get_cpu_stepping(void) {
    register signed int stepping;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000001111,%%eax;"
        "movl %%eax,%0;"
        : "=r" ( stepping )  // Output C variable
    );
    return stepping;
}


#ifdef __BMI2__


/** Get the CPU Model */
signed int get_cpu_model(void) {
    register signed int model;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000011110000000011110000,%%eax;"
        "shrl $4,%%eax;"
        "xorb %%bl,%%bl;"
        "xchgb %%al,%%bl;"
        "shrl $8,%%eax;"
        "addb %%bl,%%al;"
        "movl %%eax,%0;"
        : "=r" ( model )  // Output C variable
    );
    return model;
}


/** Get the list of instructions supported by the CPU */
ulint get_cpu_features(void) {
    register ulint features;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "rolq $64,%%rdx;"
        "movq %%rcx,%%rdx;"
        "movq %%rdx,%0;"
        : "=r" ( features )  // Output C variable
    );
    return features;
}


/* BOOLEAN TESTS FOR FEATURES */


/** Test if the CPU supports `fpu` */
int is_fpu_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000000001,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `vme` (Virtual 8086 Mode Extensions, such as VIF, VIP, and PIV) */
int is_vme_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000000010,%%edx;"
        "sarl $1,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `de` (Debugging extensions (CR4 bit 3)) */
int is_de_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000000100,%%edx;"
        "sarl $2,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `pse` (Page Size Extension) */
int is_pse_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000001000,%%edx;"
        "sarl $3,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `tsc` (Time Stamp Counter) */
int is_tsc_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000010000,%%edx;"
        "sarl $4,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `msr` (Model-specific registers) */
int is_msr_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000100000,%%edx;"
        "sarl $5,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `pae` (Physical Address Extension) */
int is_pae_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000001000000,%%edx;"
        "sarl $6,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `mce` (Machine Check Exception) */
int is_mce_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000010000000,%%edx;"
        "sarl $7,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `cx8` (CMPXCHG8/compare-and-swap instruction) */
int is_cx8_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000100000000,%%edx;"
        "sarl $8,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `apic` (Onboard Advanced Programmable Interrupt Controller) */
int is_apic_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000001000000000,%%edx;"
        "sarl $9,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `sep` (SYSENTER and SYSEXIT Instructions) */
int is_sep_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000100000000000,%%edx;"
        "sarl $11,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `mtrr` (Memory Type Range Registers) */
int is_mtrr_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000001000000000000,%%edx;"
        "sarl $12,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `pge` (Page Global Enable bit in CR4) */
int is_pge_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000010000000000000,%%edx;"
        "sarl $13,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `mca` (Machine check architecture) */
int is_mca_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000100000000000000,%%edx;"
        "sarl $14,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `cmov` (Conditional move and FCMOV instructions) */
int is_cmov_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000001000000000000000,%%edx;"
        "sarl $15,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `pat` (Page Attribute Table) */
int is_pat_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000010000000000000000,%%edx;"
        "sarl $16,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `pse-36` (36-bit page size extension) */
int is_pse36_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000100000000000000000,%%edx;"
        "sarl $17,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `psn` (Processor Serial Number) */
int is_psn_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000001000000000000000000,%%edx;"
        "sarl $18,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `clfsh` (CLFLUSH instruction (SSE2)) */
int is_clfsh_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000010000000000000000000,%%edx;"
        "sarl $19,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `ds` (Debug store: save trace of executed jumps) */
int is_ds_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000001000000000000000000000,%%edx;"
        "sarl $21,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `acpi` (Onboard thermal control MSRs for ACPI) */
int is_acpi_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000010000000000000000000000,%%edx;"
        "sarl $22,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `mmx` (MMX Instructions) */
int is_mmx_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000100000000000000000000000,%%edx;"
        "sarl $23,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `fxsr` (FXSAVE, FXRESTOR instructions, CR4 bit 9) */
int is_fxsr_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000001000000000000000000000000,%%edx;"
        "sarl $24,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `sse` (SSE instructions) */
int is_sse_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000010000000000000000000000000,%%edx;"
        "sarl $25,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `sse2` (SSE2 Instructions) */
int is_sse2_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000100000000000000000000000000,%%edx;"
        "sarl $26,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `ss` (CPU cache supports self-snoop) */
int is_ss_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00001000000000000000000000000000,%%edx;"
        "sarl $27,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `htt` (Hyper-threading) */
int is_htt_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00010000000000000000000000000000,%%edx;"
        "sarl $28,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `tm` (Thermal monitor automatically limits temperature) */
int is_tm_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00100000000000000000000000000000,%%edx;"
        "sarl $29,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `ia64` (IA64 processor emulating x86) */
int is_ia64_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b01000000000000000000000000000000,%%edx;"
        "sarl $30,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `pbe` (Pending Break Enable (PBE# pin) wakeup support) */
int is_pbe_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b10000000000000000000000000000000,%%edx;"
        "sarl $31,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `sse3` (Prescott New Instructions-SSE3 (PNI)) */
int is_sse3_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000000001,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `pclmulqdq` (PCLMULQDQ support) */
int is_pclmulqdq_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000000010,%%edx;"
        "sarl $1,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `dtes64` (64-bit debug store (edx bit 21)) */
int is_dtes64_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000000100,%%edx;"
        "sarl $2,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `monitor` (MONITOR and MWAIT instructions (SSE3)) */
int is_monitor_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000001000,%%edx;"
        "sarl $3,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `ds-cpl` (CPL qualified debug store) */
int is_dscpl_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000010000,%%edx;"
        "sarl $4,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `vmx` (Virtual Machine eXtensions) */
int is_vmx_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000100000,%%edx;"
        "sarl $5,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `smx` (Safer Mode Extensions (LaGrande)) */
int is_smx_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000001000000,%%edx;"
        "sarl $6,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `est` (Enhanced SpeedStep) */
int is_est_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000010000000,%%edx;"
        "sarl $7,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `tm2` (Thermal Monitor 2) */
int is_tm2_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000100000000,%%edx;"
        "sarl $8,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `ssse3` (Supplemental SSE3 Instructions) */
int is_ssse3_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000001000000000,%%edx;"
        "sarl $9,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `cnxt-id` (L1 Context ID) */
int is_cnxtid_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000010000000000,%%edx;"
        "sarl $10,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `sdbg` (Silicon Debug interface) */
int is_sdbg_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000010000000000000,%%edx;"
        "sarl $11,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `fma` (Fused multiply-add (FMA3)) */
int is_fma_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000001000000000000,%%edx;"
        "sarl $12,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `cx16` (CMPXCHG16B Instruction) */
int is_cx16_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000010000000000000,%%edx;"
        "sarl $13,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `xtpr` (Can disable sending task priority messages) */
int is_xtpr_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000100000000000000,%%edx;"
        "sarl $14,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `pdcm` (Perfmon & debug capability) */
int is_pdcm_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000001000000000000000,%%edx;"
        "sarl $15,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `pcid` (Process context identifiers (CR4 bit 17)) */
int is_pcid_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000100000000000000000,%%edx;"
        "sarl $17,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `dca` (Direct cache access for DMA writes) */
int is_dca_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000001000000000000000000,%%edx;"
        "sarl $18,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `sse41` (SSE4.1 Instructions) */
int is_sse41_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000010000000000000000000,%%edx;"
        "sarl $19,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `sse42` (SSE4.2 Instructions) */
int is_sse42_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000100000000000000000000,%%edx;"
        "sarl $20,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `x2apic` (x2APIC support) */
int is_x2apic_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000001000000000000000000000,%%edx;"
        "sarl $21,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `movbe` (MOVBE instruction (big-endian)) */
int is_movbe_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000010000000000000000000000,%%edx;"
        "sarl $22,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `popcnt` (POPCNT Instruction) */
int is_popcnt_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000100000000000000000000000,%%edx;"
        "sarl $23,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `tsc-deadline` (APIC supports one-shot operation using a TSC deadline value) */
int is_tscdeadline_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000001000000000000000000000000,%%edx;"
        "sarl $24,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `aes` (AES instruction set) */
int is_aes_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000010000000000000000000000000,%%edx;"
        "sarl $25,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `xsave` (XSAVE, XRESTOR, XSETBV, XGETBV)xx */
int is_xsave_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000100000000000000000000000000,%%edx;"
        "sarl $26,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the OS supports `xsave` (CPU cache supports self-snoop) */
int is_osxsave_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00001000000000000000000000000000,%%edx;"
        "sarl $27,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `avx` (Advanced Vector Extensions) */
int is_avx_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00010000000000000000000000000000,%%edx;"
        "sarl $28,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `f16c` (F16C (half-precision) FP support) */
int is_f16c_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00100000000000000000000000000000,%%edx;"
        "sarl $29,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `rdrnd` (RDRAND (on-chip random number generator) support) */
int is_rdrnd_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b01000000000000000000000000000000,%%edx;"
        "roll $2,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the system is running in a hypervisor (always 0 on a real CPU, but also with some hypervisors) */
int is_hypervisor_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b10000000000000000000000000000000,%%edx;"
        "roll $1,%%edx;"
        "movl %%edx,%0;"
        : "=r" ( truth )  // Output C variable
    );
    return truth;
}


/** Test if the CPU supports `fsgsbase` */
int is_fsgsbase_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000000000000000001,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `IA32_TSC_ADJUST` */
int is_ia32_tsc_adjust_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000000000000000010,%%ebx;"
        "sarl $1,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `sgx` (Software Guard Extensions) */
int is_sgx_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000000000000000100,%%ebx;"
        "sarl $2,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `bmi1` (Bit Manipulation Instruction Set 1) */
int is_bmi1_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000000000000001000,%%ebx;"
        "sarl $3,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `hle` (Bit Manipulation Instruction Set 1) */
int is_hle_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000000000000010000,%%ebx;"
        "sarl $4,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `avx2` (Advanced Vector Extensions 2) */
int is_avx2_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000000000000100000,%%ebx;"
        "sarl $5,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `smep` (Supervisor-Mode Execution Prevention) */
int is_smep_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000000000010000000,%%ebx;"
        "sarl $7,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `bmi2` (Bit Manipulation Instruction Set 2) */
int is_bmi2_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000000000100000000,%%ebx;"
        "sarl $8,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `erms` (Enhanced REP MOVSB/STOSB) */
int is_erms_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000000001000000000,%%ebx;"
        "sarl $9,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `invpcid` (INVPCID Instruction) */
int is_invpcid_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000000010000000000,%%ebx;"
        "sarl $10,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `rtm` (Transactional Synchronization Extensions) */
int is_rtm_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000000100000000000,%%ebx;"
        "sarl $11,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `pqm` (Platform Quality of Service Monitoring) */
int is_pqm_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000001000000000000,%%ebx;"
        "sarl $12,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `mpx` (Intel Memory Protection Extensions) */
int is_mpx_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000100000000000000,%%ebx;"
        "sarl $14,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `pqe` (Platform Quality of Service Enforcement) */
int is_pqe_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000001000000000000000,%%ebx;"
        "sarl $15,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `avx512f` (AVX-512) */
int is_avx512f_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000010000000000000000,%%ebx;"
        "sarl $16,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `avx512dq` (AVX-512 Doubleword and Quadword Instructions) */
int is_avx512dq_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000100000000000000000,%%ebx;"
        "sarl $17,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `rdseed` (RDSEED Instruction) */
int is_rdseed_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000001000000000000000000,%%ebx;"
        "sarl $18,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `adx` (Intel Multi-Precision Add-Carry Instruction Extensions) */
int is_adx_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000010000000000000000000,%%ebx;"
        "sarl $19,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `smap` (Supervisor Mode Access Prevention) */
int is_smap_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000100000000000000000000,%%ebx;"
        "sarl $20,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `avx512ifma` (AVX-512 Integer Fused Multiply-Add Instructions) */
int is_avx512ifma_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000001000000000000000000000,%%ebx;"
        "sarl $21,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `pcommit` (PCOMMIT Instruction) */
int is_pcommit_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000010000000000000000000000,%%ebx;"
        "sarl $22,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `clflushopt` (CLFLUSHOPT Instruction) */
int is_clflushopt_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000100000000000000000000000,%%ebx;"
        "sarl $23,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `clwb` (CLWB Instruction) */
int is_clwb_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000001000000000000000000000000,%%ebx;"
        "sarl $24,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports Intel Processor Trace */
int is_processor_trace_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000010000000000000000000000000,%%ebx;"
        "sarl $25,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `avx512pf` (AVX-512 Prefetch Instructions) */
int is_avx512pf_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000100000000000000000000000000,%%ebx;"
        "sarl $26,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `avx512er` (AVX-512 Exponential and Reciprocal Instructions) */
int is_avx512er_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00001000000000000000000000000000,%%ebx;"
        "sarl $27,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `avx512cd` (AVX-512 Conflict Detection Instructions) */
int is_avx512cd_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00010000000000000000000000000000,%%ebx;"
        "sarl $28,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `sha` (Intel SHA extensions) */
int is_sha_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00100000000000000000000000000000,%%ebx;"
        "sarl $29,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `avx512bw` (AVX-512 Byte and Word Instructions) */
int is_avx512bw_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b01000000000000000000000000000000,%%ebx;"
        "sarl $30,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `avx512vl` (AVX-512 Vector Length Extensions) */
int is_avx512vl_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b10000000000000000000000000000000,%%ebx;"
        "sarl $31,%%ebx;"
        "movl %%ebx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `prefetchwt1` (PREFETCHWT1 Instruction) */
int is_prefetchwt1_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000000000000000001,%%ecx;"
        "movl %%ecx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


/** Test if the CPU supports `avx512vbmi` (AVX-512 Vector Bit Manipulation Instructions) */
int is_avx512vbmi_aval(void) {
    register int truth;
    __asm__ (
        "movl $0x07,%%eax;"
        "movl $0x0,%%ecx;"
        "cpuid;"
        "andl $0b00000000000000000000000000000010,%%ecx;"
        "sarl $1,%%ecx;"
        "movl %%ecx,%0;"
        : "=r" ( truth )
    );
    return truth;
}


#endif


/** Test if this library is using BMI2 */
int is_bmi2_lib(void) {
#ifdef __BMI2__
    return 1;
#else
    return 0;
#endif
}


/** Test if this library is using AVX */
int is_avx_lib(void) {
#ifdef __AVX__
    return 1;
#else
    return 0;
#endif
}


/** Test if this library is using AVX2 */
int is_avx2_lib(void) {
#ifdef __AVX2__
    return 1;
#else
    return 0;
#endif
}


/** Test if this library is using XOP */
int is_xop_lib(void) {
#ifdef __XOP__
    return 1;
#else
    return 0;
#endif
}


/* GENERAL FUNCTIONS */


/** Turn the number to zero in-place */
ullint in_place_zero(ullint num) {
    __asm__ volatile (  // AT&T Style Assembly
        "xor %0,%0;"
        : "=r" ( num )  // %0: Output to C variable
        : "r" ( num )  // %1: Input C variable
        :  // Clobbered Register
    );
    return num;
}


/** XOR the two numbers */
ullint asm_xor_ull(ullint num1, ullint num2) {
    register ullint xor_num;
    __asm__ (  // AT&T Style Assembly
        "mov %1,%%rax;"
        "xor %2,%%rax;"
        "mov %%rax,%0;"
        : "=r" ( xor_num )  // %0: Output to C variable
        : "r" ( num1 ), "r" ( num2 )  // %1 & %2: Input C variable
        :  // Clobbered Register
    );
    return xor_num;
}


#ifdef __BMI2__
/** Get a random number from the rdrand assembly instruction */
ulint rdrnd(void) {
    if ((is_rdrnd_aval()) == 0) return (ulint)0;
    register ulint rand_num;
    __asm__ volatile ( "rdrand %0;" : "=r" ( rand_num ) );
    return rand_num;
}
#endif


#endif


/** Do nothing (not faster than Python's `pass` command) */
void asm_nop(void) {
    __asm__ volatile ("nop;");
    return;
}

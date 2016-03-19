// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file pytools.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Miscellaneous Functions (from tools.c and x86_64_asm_func.c)
@version 2016.03.18

@section DESCRIPTION
This is a Python3 module that uses functions from tools.c
Various functions that do not fit in other categories.
Such functions include string manipulations, file I/O, boolean tests, etc.

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


#include "PY_MACROS.h"
#include "tools.h"
#include "x86_64_asm_func.h"

#define MODNAME   "tools"
#define MODINIT   PyMODINIT_FUNC PyInit_tools(void)
MODINIT __attribute__((flatten, hot));


/* FUNCTION DEFINITIONS */


#ifdef __GNUC__
static PyObject *tools_lowercasestr(FUNCARGS) __attribute__((flatten, nonnull));
static PyObject *tools_lowercasestr15(FUNCARGS) __attribute__((flatten, nonnull));
static PyObject *tools_uppercasestr(FUNCARGS) __attribute__((flatten, nonnull));
static PyObject *tools_isstrlowercase(FUNCARGS) __attribute__((flatten));
static PyObject *tools_isstruppercase(FUNCARGS) __attribute__((flatten));
static PyObject *tools_isstralnum(FUNCARGS) __attribute__((flatten));
static PyObject *tools_isstralpha(FUNCARGS) __attribute__((flatten));
static PyObject *tools_isstrnum(FUNCARGS) __attribute__((flatten));
static PyObject *tools_isstrgraphical(FUNCARGS) __attribute__((flatten));
static PyObject *tools_isstrprintable(FUNCARGS) __attribute__((flatten));
static PyObject *tools_isstrpunctuation(FUNCARGS) __attribute__((flatten));
static PyObject *tools_isstrwhitespace(FUNCARGS) __attribute__((flatten));
static PyObject *tools_isstrhex(FUNCARGS) __attribute__((flatten));
static PyObject *tools_strreplace(FUNCARGS) __attribute__((flatten));
static PyObject *tools_strreplace_once(FUNCARGS) __attribute__((flatten));
static PyObject *tools_rmgravequote(FUNCARGS) __attribute__((flatten));
#else
static PyObject *tools_lowercasestr(FUNCARGS);
static PyObject *tools_lowercasestr15(FUNCARGS);
static PyObject *tools_uppercasestr(FUNCARGS);
static PyObject *tools_isstrlowercase(FUNCARGS);
static PyObject *tools_isstruppercase(FUNCARGS);
static PyObject *tools_isstralnum(FUNCARGS);
static PyObject *tools_isstralpha(FUNCARGS);
static PyObject *tools_isstrnum(FUNCARGS);
static PyObject *tools_isstrgraphical(FUNCARGS);
static PyObject *tools_isstrprintable(FUNCARGS);
static PyObject *tools_isstrpunctuation(FUNCARGS);
static PyObject *tools_isstrwhitespace(FUNCARGS);
static PyObject *tools_isstrhex(FUNCARGS);
static PyObject *tools_strreplace(FUNCARGS);
static PyObject *tools_strreplace_once(FUNCARGS);
static PyObject *tools_rmgravequote(FUNCARGS);
#endif
#if (defined(ENV64BIT) && (defined(__x86_64__) || defined(__x86_64)))
static PyObject *tools_rdtsc(void);
static PyObject *tools_get_vendor_id(void);
static PyObject *tools_get_cpu_stepping(void);
#   ifdef __BMI2__
static PyObject *tools_is_fpu_aval(void);
static PyObject *tools_is_rdseed_aval(void);
static PyObject *tools_is_est_aval(void);
static PyObject *tools_is_avx_aval(void);
static PyObject *tools_is_smx_aval(void);
static PyObject *tools_is_xtpr_aval(void);
static PyObject *tools_is_rtm_aval(void);
static PyObject *tools_is_mpx_aval(void);
static PyObject *tools_is_movbe_aval(void);
static PyObject *tools_is_pge_aval(void);
static PyObject *tools_is_vme_aval(void);
static PyObject *tools_is_cmov_aval(void);
static PyObject *tools_is_ds_aval(void);
static PyObject *tools_is_de_aval(void);
static PyObject *tools_is_acpi_aval(void);
static PyObject *tools_is_sgx_aval(void);
static PyObject *tools_is_invpcid_aval(void);
static PyObject *tools_is_rdrnd_aval(void);
static PyObject *tools_is_vmx_aval(void);
static PyObject *tools_is_hypervisor_aval(void);
static PyObject *tools_is_monitor_aval(void);
static PyObject *tools_is_pse_aval(void);
static PyObject *tools_is_fma_aval(void);
static PyObject *tools_is_popcnt_aval(void);
static PyObject *tools_is_tm_aval(void);
static PyObject *tools_is_clflushopt_aval(void);
static PyObject *tools_is_erms_aval(void);
static PyObject *tools_is_sse_aval(void);
static PyObject *tools_is_dscpl_aval(void);
static PyObject *tools_is_tsc_aval(void);
static PyObject *tools_is_tscdeadline_aval(void);
static PyObject *tools_is_sep_aval(void);
static PyObject *tools_is_hle_aval(void);
static PyObject *tools_is_adx_aval(void);
static PyObject *tools_is_sdbg_aval(void);
static PyObject *tools_is_htt_aval(void);
static PyObject *tools_is_apic_aval(void);
static PyObject *tools_is_cnxtid_aval(void);
static PyObject *tools_is_pqe_aval(void);
static PyObject *tools_is_pcid_aval(void);
static PyObject *tools_is_pbe_aval(void);
static PyObject *tools_is_smap_aval(void);
static PyObject *tools_is_fxsr_aval(void);
static PyObject *tools_is_psn_aval(void);
static PyObject *tools_is_dca_aval(void);
static PyObject *tools_is_pcommit_aval(void);
static PyObject *tools_is_clwb_aval(void);
static PyObject *tools_is_aes_aval(void);
static PyObject *tools_is_xsave_aval(void);
static PyObject *tools_is_smep_aval(void);
static PyObject *tools_is_pqm_aval(void);
static PyObject *tools_is_fsgsbase_aval(void);
static PyObject *tools_is_clfsh_aval(void);
static PyObject *tools_is_mmx_aval(void);
static PyObject *tools_is_ss_aval(void);
static PyObject *tools_is_msr_aval(void);
static PyObject *tools_is_pat_aval(void);
static PyObject *tools_is_processor_trace_aval(void);
static PyObject *tools_is_pdcm_aval(void);
static PyObject *tools_is_mca_aval(void);
static PyObject *tools_is_mce_aval(void);
static PyObject *tools_is_osxsave_aval(void);
static PyObject *tools_is_pae_aval(void);
static PyObject *tools_is_sha_aval(void);
static PyObject *tools_is_mtrr_aval(void);
static PyObject *tools_is_pclmulqdq_aval(void);
static PyObject *tools_is_avx512pf_aval(void);
static PyObject *tools_is_dtes64_aval(void);
static PyObject *tools_is_sse3_aval(void);
static PyObject *tools_is_tm2_aval(void);
static PyObject *tools_is_avx512dq_aval(void);
static PyObject *tools_is_sse42_aval(void);
static PyObject *tools_is_cx16_aval(void);
static PyObject *tools_is_x2apic_aval(void);
static PyObject *tools_is_ssse3_aval(void);
static PyObject *tools_is_avx512vbmi_aval(void);
static PyObject *tools_is_pse36_aval(void);
static PyObject *tools_is_avx512ifma_aval(void);
static PyObject *tools_is_avx512er_aval(void);
static PyObject *tools_is_avx512cd_aval(void);
static PyObject *tools_is_ia64_aval(void);
static PyObject *tools_is_prefetchwt1_aval(void);
static PyObject *tools_is_ia32_tsc_adjust_aval(void);
static PyObject *tools_is_sse2_aval(void);
static PyObject *tools_is_cx8_aval(void);
static PyObject *tools_is_bmi2_aval(void);
static PyObject *tools_is_avx512vl_aval(void);
static PyObject *tools_is_avx512f_aval(void);
static PyObject *tools_is_bmi1_aval(void);
static PyObject *tools_is_avx2_aval(void);
static PyObject *tools_is_avx512bw_aval(void);
static PyObject *tools_is_sse41_aval(void);
static PyObject *tools_is_f16c_aval(void);
#   endif
#endif
static PyObject *tools_nop(void);
static PyObject *tools_endianness(void);
#if (defined(__GNUC__) || defined(__CC_ARM) || defined(__INTEL_COMPILER) || defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__) || defined(__TINYC__))
static PyObject *tools_getarch(void);
static PyObject *tools_getos(void);
#endif
static PyObject *tools_isandroid(void);
static PyObject *tools_CSTD(void);
#ifdef _POSIX_VERSION
static PyObject *tools_POSIXSTD(void);
#endif
#ifdef OSPOSIX
static PyObject *tools_getsyshostname(void);
#endif
static PyObject *tools_printline(void);


/* DOCSTRINGS */


static char module_docstring[32] = "Miscellaneous Functions";
PyDoc_STRVAR(tools_lowercasestr_docstring,
    "lowercasestr(STR: str) -> str\nConvert a string to all lowercase letters");
PyDoc_STRVAR(tools_lowercasestr15_docstring,
    "lowercasestr15(STR: str) -> str\nConvert a string 15-character string to all lowercase letters");
PyDoc_STRVAR(tools_uppercasestr_docstring,
    "uppercasestr(STR: str) -> str\nConvert a string to all uppercase letters");
PyDoc_STRVAR(tools_isstrlowercase_docstring,
    "isstrlowercase(STR: str) -> bool\nCheck if the string only contains lowercase letters");
PyDoc_STRVAR(tools_isstruppercase_docstring,
    "isstruppercase(STR: str) -> bool\nCheck if the string only contains uppercase letters");
PyDoc_STRVAR(tools_isstralnum_docstring,
    "isstralnum(STR: str) -> bool\nCheck if the string only contains alphanumeric characters");
PyDoc_STRVAR(tools_isstralpha_docstring,
    "isstralpha(STR: str) -> bool\nCheck if the string only contains alphabetic characters");
PyDoc_STRVAR(tools_isstrnum_docstring,
    "isstrnum(STR: str) -> bool\nCheck if the string only contains numbers");
PyDoc_STRVAR(tools_isstrgraphical_docstring,
    "isstrgraphical(STR: str) -> bool\nCheck if the string only contains printable characters and not whitespace");
PyDoc_STRVAR(tools_isstrprintable_docstring,
    "isstrprintable(STR: str) -> bool\nCheck if the string only contains printable characters");
PyDoc_STRVAR(tools_isstrpunctuation_docstring,
    "isstrpunctuation(STR: str) -> bool\nCheck if the string only contains punctuation characters");
PyDoc_STRVAR(tools_isstrwhitespace_docstring,
    "isstrwhitespace(STR: str) -> bool\nCheck if the string only contains whitespace characters");
PyDoc_STRVAR(tools_isstrhex_docstring,
    "isstrhex(STR: str) -> bool\nCheck if the string only contains hexadecimal characters");
PyDoc_STRVAR(tools_strreplace_docstring,
    "strreplace(orig_string: str, find: str, replace_with: str) -> str\nFind and replace all occurrences of \"find\" with \"replace_with\"");
PyDoc_STRVAR(tools_strreplace_once_docstring,
    "strreplace_once(orig_string: str, find: str, replace_with: str) -> str\nReplace first occurrence of \"find\" with \"replace_with\"");
PyDoc_STRVAR(tools_rmgravequote_docstring,
    "rmgravequote(string: str) -> str\nFind and remove grave-quotes (`)");
#if (defined(ENV64BIT) && (defined(__x86_64__) || defined(__x86_64)))
PyDoc_STRVAR(tools_rdtsc_docstring,
    "rdtsc() -> int\nThe rdtsc (Read Time-Stamp Counter) instruction is used to determine how many CPU ticks occurred since the processor was reset");
PyDoc_STRVAR(tools_get_vendor_id_docstring,
    "get_vendor_id() -> str\nReturn the vendor ID of the x86 CPU (Assumes little-endian)");
PyDoc_STRVAR(tools_get_cpu_stepping_docstring,
    "get_cpu_stepping() -> int\nGet the stepping value of the CPU");
#ifdef __BMI2__
PyDoc_STRVAR(tools_is_fpu_aval_docstring,
    "is_fpu_aval() -> bool\nTest if the CPU supports `fpu`");
PyDoc_STRVAR(tools_is_rdseed_aval_docstring,
    "is_rdseed_aval() -> bool\nTest if the CPU supports `rdseed` (RDSEED Instruction)");
PyDoc_STRVAR(tools_is_est_aval_docstring,
    "is_est_aval() -> bool\nTest if the CPU supports `est` (Enhanced SpeedStep)");
PyDoc_STRVAR(tools_is_avx_aval_docstring,
    "is_avx_aval() -> bool\nTest if the CPU supports `avx` (Advanced Vector Extensions)");
PyDoc_STRVAR(tools_is_smx_aval_docstring,
    "is_smx_aval() -> bool\nTest if the CPU supports `smx` (Safer Mode Extensions (LaGrande))");
PyDoc_STRVAR(tools_is_xtpr_aval_docstring,
    "is_xtpr_aval() -> bool\nTest if the CPU supports `xtpr` (Can disable sending task priority messages)");
PyDoc_STRVAR(tools_is_rtm_aval_docstring,
    "is_rtm_aval() -> bool\nTest if the CPU supports `rtm` (Transactional Synchronization Extensions)");
PyDoc_STRVAR(tools_is_mpx_aval_docstring,
    "is_mpx_aval() -> bool\nTest if the CPU supports `mpx` (Intel Memory Protection Extensions)");
PyDoc_STRVAR(tools_is_movbe_aval_docstring,
    "is_movbe_aval() -> bool\nTest if the CPU supports `movbe` (MOVBE instruction (big-endian))");
PyDoc_STRVAR(tools_is_pge_aval_docstring,
    "is_pge_aval() -> bool\nTest if the CPU supports `pge` (Page Global Enable bit in CR4)");
PyDoc_STRVAR(tools_is_vme_aval_docstring,
    "is_vme_aval() -> bool\nTest if the CPU supports `vme` (Virtual 8086 Mode Extensions, such as VIF, VIP, and PIV)");
PyDoc_STRVAR(tools_is_cmov_aval_docstring,
    "is_cmov_aval() -> bool\nTest if the CPU supports `cmov` (Conditional move and FCMOV instructions)");
PyDoc_STRVAR(tools_is_ds_aval_docstring,
    "is_ds_aval() -> bool\nTest if the CPU supports `ds` (Debug store: save trace of executed jumps)");
PyDoc_STRVAR(tools_is_de_aval_docstring,
    "is_de_aval() -> bool\nTest if the CPU supports `de` (Debugging extensions (CR4 bit 3))");
PyDoc_STRVAR(tools_is_acpi_aval_docstring,
    "is_acpi_aval() -> bool\nTest if the CPU supports `acpi` (Onboard thermal control MSRs for ACPI)");
PyDoc_STRVAR(tools_is_sgx_aval_docstring,
    "is_sgx_aval() -> bool\nTest if the CPU supports `sgx` (Software Guard Extensions)");
PyDoc_STRVAR(tools_is_invpcid_aval_docstring,
    "is_invpcid_aval() -> bool\nTest if the CPU supports `invpcid` (INVPCID Instruction)");
PyDoc_STRVAR(tools_is_rdrnd_aval_docstring,
    "is_rdrnd_aval() -> bool\nTest if the CPU supports `rdrnd` (RDRAND (on-chip random number generator) support)");
PyDoc_STRVAR(tools_is_vmx_aval_docstring,
    "is_vmx_aval() -> bool\nTest if the CPU supports `vmx` (Virtual Machine eXtensions)");
PyDoc_STRVAR(tools_is_hypervisor_aval_docstring,
    "is_hypervisor_aval() -> bool\nTest if the system is running in a hypervisor (always 0 on a real CPU, but also with some hypervisors)");
PyDoc_STRVAR(tools_is_monitor_aval_docstring,
    "is_monitor_aval() -> bool\nTest if the CPU supports `monitor` (MONITOR and MWAIT instructions (SSE3))");
PyDoc_STRVAR(tools_is_pse_aval_docstring,
    "is_pse_aval() -> bool\nTest if the CPU supports `pse` (Page Size Extension)");
PyDoc_STRVAR(tools_is_fma_aval_docstring,
    "is_fma_aval() -> bool\nTest if the CPU supports `fma` (Fused multiply-add (FMA3))");
PyDoc_STRVAR(tools_is_popcnt_aval_docstring,
    "is_popcnt_aval() -> bool\nTest if the CPU supports `popcnt` (POPCNT Instruction)");
PyDoc_STRVAR(tools_is_tm_aval_docstring,
    "is_tm_aval() -> bool\nTest if the CPU supports `tm` (Thermal monitor automatically limits temperature)");
PyDoc_STRVAR(tools_is_clflushopt_aval_docstring,
    "is_clflushopt_aval() -> bool\nTest if the CPU supports `clflushopt` (CLFLUSHOPT Instruction)");
PyDoc_STRVAR(tools_is_erms_aval_docstring,
    "is_erms_aval() -> bool\nTest if the CPU supports `erms` (Enhanced REP MOVSB/STOSB)");
PyDoc_STRVAR(tools_is_sse_aval_docstring,
    "is_sse_aval() -> bool\nTest if the CPU supports `sse` (SSE instructions)");
PyDoc_STRVAR(tools_is_dscpl_aval_docstring,
    "is_dscpl_aval() -> bool\nTest if the CPU supports `ds-cpl` (CPL qualified debug store)");
PyDoc_STRVAR(tools_is_tsc_aval_docstring,
    "is_tsc_aval() -> bool\nTest if the CPU supports `tsc` (Time Stamp Counter)");
PyDoc_STRVAR(tools_is_tscdeadline_aval_docstring,
    "is_tscdeadline_aval() -> bool\nTest if the CPU supports `tsc-deadline` (APIC supports one-shot operation using a TSC deadline value)");
PyDoc_STRVAR(tools_is_sep_aval_docstring,
    "is_sep_aval() -> bool\nTest if the CPU supports `sep` (SYSENTER and SYSEXIT Instructions)");
PyDoc_STRVAR(tools_is_hle_aval_docstring,
    "is_hle_aval() -> bool\nTest if the CPU supports `hle` (Bit Manipulation Instruction Set 1)");
PyDoc_STRVAR(tools_is_adx_aval_docstring,
    "is_adx_aval() -> bool\nTest if the CPU supports `adx` (Intel Multi-Precision Add-Carry Instruction Extensions)");
PyDoc_STRVAR(tools_is_sdbg_aval_docstring,
    "is_sdbg_aval() -> bool\nTest if the CPU supports `sdbg` (Silicon Debug interface)");
PyDoc_STRVAR(tools_is_htt_aval_docstring,
    "is_htt_aval() -> bool\nTest if the CPU supports `htt` (Hyper-threading)");
PyDoc_STRVAR(tools_is_apic_aval_docstring,
    "is_apic_aval() -> bool\nTest if the CPU supports `apic` (Onboard Advanced Programmable Interrupt Controller)");
PyDoc_STRVAR(tools_is_cnxtid_aval_docstring,
    "is_cnxtid_aval() -> bool\nTest if the CPU supports `cnxt-id` (L1 Context ID)");
PyDoc_STRVAR(tools_is_pqe_aval_docstring,
    "is_pqe_aval() -> bool\nTest if the CPU supports `pqe` (Platform Quality of Service Enforcement)");
PyDoc_STRVAR(tools_is_pcid_aval_docstring,
    "is_pcid_aval() -> bool\nTest if the CPU supports `pcid` (Process context identifiers (CR4 bit 17))");
PyDoc_STRVAR(tools_is_pbe_aval_docstring,
    "is_pbe_aval() -> bool\nTest if the CPU supports `pbe` (Pending Break Enable (PBE# pin) wakeup support)");
PyDoc_STRVAR(tools_is_smap_aval_docstring,
    "is_smap_aval() -> bool\nTest if the CPU supports `smap` (Supervisor Mode Access Prevention)");
PyDoc_STRVAR(tools_is_fxsr_aval_docstring,
    "is_fxsr_aval() -> bool\nTest if the CPU supports `fxsr` (FXSAVE, FXRESTOR instructions, CR4 bit 9)");
PyDoc_STRVAR(tools_is_psn_aval_docstring,
    "is_psn_aval() -> bool\nTest if the CPU supports `psn` (Processor Serial Number)");
PyDoc_STRVAR(tools_is_dca_aval_docstring,
    "is_dca_aval() -> bool\nTest if the CPU supports `dca` (Direct cache access for DMA writes)");
PyDoc_STRVAR(tools_is_pcommit_aval_docstring,
    "is_pcommit_aval() -> bool\nTest if the CPU supports `pcommit` (PCOMMIT Instruction)");
PyDoc_STRVAR(tools_is_clwb_aval_docstring,
    "is_clwb_aval() -> bool\nTest if the CPU supports `clwb` (CLWB Instruction)");
PyDoc_STRVAR(tools_is_aes_aval_docstring,
    "is_aes_aval() -> bool\nTest if the CPU supports `aes` (AES instruction set)");
PyDoc_STRVAR(tools_is_xsave_aval_docstring,
    "is_xsave_aval() -> bool\nTest if the CPU supports `xsave` (XSAVE, XRESTOR, XSETBV, XGETBV)");
PyDoc_STRVAR(tools_is_smep_aval_docstring,
    "is_smep_aval() -> bool\nTest if the CPU supports `smep` (Supervisor-Mode Execution Prevention)");
PyDoc_STRVAR(tools_is_pqm_aval_docstring,
    "is_pqm_aval() -> bool\nTest if the CPU supports `pqm` (Platform Quality of Service Monitoring)");
PyDoc_STRVAR(tools_is_fsgsbase_aval_docstring,
    "is_fsgsbase_aval() -> bool\nTest if the CPU supports `fsgsbase`");
PyDoc_STRVAR(tools_is_clfsh_aval_docstring,
    "is_clfsh_aval() -> bool\nTest if the CPU supports `clfsh` (CLFLUSH instruction (SSE2))");
PyDoc_STRVAR(tools_is_mmx_aval_docstring,
    "is_mmx_aval() -> bool\nTest if the CPU supports `mmx` (MMX Instructions)");
PyDoc_STRVAR(tools_is_ss_aval_docstring,
    "is_ss_aval() -> bool\nTest if the CPU supports `ss` (CPU cache supports self-snoop)");
PyDoc_STRVAR(tools_is_msr_aval_docstring,
    "is_msr_aval() -> bool\nTest if the CPU supports `msr` (Model-specific registers)");
PyDoc_STRVAR(tools_is_pat_aval_docstring,
    "is_pat_aval() -> bool\nTest if the CPU supports `pat` (Page Attribute Table)");
PyDoc_STRVAR(tools_is_processor_trace_aval_docstring,
    "is_processor_trace_aval() -> bool\nTest if the CPU supports Intel Processor Trace");
PyDoc_STRVAR(tools_is_pdcm_aval_docstring,
    "is_pdcm_aval() -> bool\nTest if the CPU supports `pdcm` (Perfmon & debug capability)");
PyDoc_STRVAR(tools_is_mca_aval_docstring,
    "is_mca_aval() -> bool\nTest if the CPU supports `mca` (Machine check architecture)");
PyDoc_STRVAR(tools_is_mce_aval_docstring,
    "is_mce_aval() -> bool\nTest if the CPU supports `mce` (Machine Check Exception)");
PyDoc_STRVAR(tools_is_osxsave_aval_docstring,
    "is_osxsave_aval() -> bool\nTest if the OS supports `xsave` (CPU cache supports self-snoop)");
PyDoc_STRVAR(tools_is_pae_aval_docstring,
    "is_pae_aval() -> bool\nTest if the CPU supports `pae` (Physical Address Extension)");
PyDoc_STRVAR(tools_is_sha_aval_docstring,
    "is_sha_aval() -> bool\nTest if the CPU supports `sha` (Intel SHA extensions)");
PyDoc_STRVAR(tools_is_mtrr_aval_docstring,
    "is_mtrr_aval() -> bool\nTest if the CPU supports `mtrr` (Memory Type Range Registers)");
PyDoc_STRVAR(tools_is_pclmulqdq_aval_docstring,
    "is_pclmulqdq_aval() -> bool\nTest if the CPU supports `pclmulqdq` (PCLMULQDQ support)");
PyDoc_STRVAR(tools_is_avx512pf_aval_docstring,
    "is_avx512pf_aval() -> bool\nTest if the CPU supports `avx512pf` (AVX-512 Prefetch Instructions)");
PyDoc_STRVAR(tools_is_dtes64_aval_docstring,
    "is_dtes64_aval() -> bool\nTest if the CPU supports `dtes64` (64-bit debug store (edx bit 21))");
PyDoc_STRVAR(tools_is_sse3_aval_docstring,
    "is_sse3_aval() -> bool\nTest if the CPU supports `sse3` (Prescott New Instructions-SSE3 (PNI))");
PyDoc_STRVAR(tools_is_tm2_aval_docstring,
    "is_tm2_aval() -> bool\nTest if the CPU supports `tm2` (Thermal Monitor 2)");
PyDoc_STRVAR(tools_is_avx512dq_aval_docstring,
    "is_avx512dq_aval() -> bool\nTest if the CPU supports `avx512dq` (AVX-512 Doubleword and Quadword Instructions)");
PyDoc_STRVAR(tools_is_sse42_aval_docstring,
    "is_sse42_aval() -> bool\nTest if the CPU supports `sse42` (SSE4.2 Instructions)");
PyDoc_STRVAR(tools_is_cx16_aval_docstring,
    "is_cx16_aval() -> bool\nTest if the CPU supports `cx16` (CMPXCHG16B Instruction)");
PyDoc_STRVAR(tools_is_x2apic_aval_docstring,
    "is_x2apic_aval() -> bool\nTest if the CPU supports `x2apic` (x2APIC support)");
PyDoc_STRVAR(tools_is_ssse3_aval_docstring,
    "is_ssse3_aval() -> bool\nTest if the CPU supports `ssse3` (Supplemental SSE3 Instructions)");
PyDoc_STRVAR(tools_is_avx512vbmi_aval_docstring,
    "is_avx512vbmi_aval() -> bool\nTest if the CPU supports `avx512vbmi` (AVX-512 Vector Bit Manipulation Instructions)");
PyDoc_STRVAR(tools_is_pse36_aval_docstring,
    "is_pse36_aval() -> bool\nTest if the CPU supports `pse-36` (36-bit page size extension)");
PyDoc_STRVAR(tools_is_avx512ifma_aval_docstring,
    "is_avx512ifma_aval() -> bool\nTest if the CPU supports `avx512ifma` (AVX-512 Integer Fused Multiply-Add Instructions)");
PyDoc_STRVAR(tools_is_avx512er_aval_docstring,
    "is_avx512er_aval() -> bool\nTest if the CPU supports `avx512er` (AVX-512 Exponential and Reciprocal Instructions)");
PyDoc_STRVAR(tools_is_avx512cd_aval_docstring,
    "is_avx512cd_aval() -> bool\nTest if the CPU supports `avx512cd` (AVX-512 Conflict Detection Instructions)");
PyDoc_STRVAR(tools_is_ia64_aval_docstring,
    "is_ia64_aval() -> bool\nTest if the CPU supports `ia64` (IA64 processor emulating x86)");
PyDoc_STRVAR(tools_is_prefetchwt1_aval_docstring,
    "is_prefetchwt1_aval() -> bool\nTest if the CPU supports `prefetchwt1` (PREFETCHWT1 Instruction)");
PyDoc_STRVAR(tools_is_ia32_tsc_adjust_aval_docstring,
    "is_ia32_tsc_adjust_aval() -> bool\nTest if the CPU supports `IA32_TSC_ADJUST`");
PyDoc_STRVAR(tools_is_sse2_aval_docstring,
    "is_sse2_aval() -> bool\nTest if the CPU supports `sse2` (SSE2 Instructions)");
PyDoc_STRVAR(tools_is_cx8_aval_docstring,
    "is_cx8_aval() -> bool\nTest if the CPU supports `cx8` (CMPXCHG8/compare-and-swap instruction)");
PyDoc_STRVAR(tools_is_bmi2_aval_docstring,
    "is_bmi2_aval() -> bool\nTest if the CPU supports `bmi2` (Bit Manipulation Instruction Set 2)");
PyDoc_STRVAR(tools_is_avx512vl_aval_docstring,
    "is_avx512vl_aval() -> bool\nTest if the CPU supports `avx512vl` (AVX-512 Vector Length Extensions)");
PyDoc_STRVAR(tools_is_avx512f_aval_docstring,
    "is_avx512f_aval() -> bool\nTest if the CPU supports `avx512f` (AVX-512)");
PyDoc_STRVAR(tools_is_bmi1_aval_docstring,
    "is_bmi1_aval() -> bool\nTest if the CPU supports `bmi1` (Bit Manipulation Instruction Set 1)");
PyDoc_STRVAR(tools_is_avx2_aval_docstring,
    "is_avx2_aval() -> bool\nTest if the CPU supports `avx2` (Advanced Vector Extensions 2)");
PyDoc_STRVAR(tools_is_avx512bw_aval_docstring,
    "is_avx512bw_aval() -> bool\nTest if the CPU supports `avx512bw` (AVX-512 Byte and Word Instructions)");
PyDoc_STRVAR(tools_is_sse41_aval_docstring,
    "is_sse41_aval() -> bool\nTest if the CPU supports `sse41` (SSE4.1 Instructions)");
PyDoc_STRVAR(tools_is_f16c_aval_docstring,
    "is_f16c_aval() -> bool\nTest if the CPU supports `f16c` (F16C (half-precision) FP support)");
#endif
#endif
PyDoc_STRVAR(tools_nop_docstring,
    "nop() -> None\nDo nothing (faster than Python's `pass` command)");
PyDoc_STRVAR(tools_endianness_docstring,
    "endianness() -> str\nReturn the system's endianness");
#if (defined(__GNUC__) || defined(__CC_ARM) || defined(__INTEL_COMPILER) || defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__) || defined(__TINYC__))
PyDoc_STRVAR(tools_getarch_docstring,
    "getarch() -> str\nGet the system's architecture type");
PyDoc_STRVAR(tools_getos_docstring,
    "getos() -> str\nGet the system's operating-system name");
#endif
PyDoc_STRVAR(tools_isandroid_docstring,
    "isandroid() -> bool\nTest if this system is Android");
PyDoc_STRVAR(tools_CSTD_docstring,
    "CSTD() -> int\nReturn the value of the current C Standard");
#ifdef _POSIX_VERSION
PyDoc_STRVAR(tools_POSIXSTD_docstring,
    "POSIXSTD() -> int\nReturn the value of the current POSIX Standard");
#endif
#ifdef OSPOSIX
PyDoc_STRVAR(tools_getsyshostname_docstring,
    "getsyshostname() -> str\nReturn the system's hostname");
#endif
PyDoc_STRVAR(tools_printline_docstring,
    "printline() -> None\nPrint a newline character");


/* MODULE SPECIFICATION */


static PyMethodDef module_methods[128] = {  // Method Table
    {"lowercasestr", (PyCFunction)tools_lowercasestr, METH_VARARGS, tools_lowercasestr_docstring},
    {"lowercasestr15", (PyCFunction)tools_lowercasestr15, METH_VARARGS, tools_lowercasestr15_docstring},
    {"uppercasestr", (PyCFunction)tools_uppercasestr, METH_VARARGS, tools_uppercasestr_docstring},
    {"isstrlowercase", (PyCFunction)tools_isstrlowercase, METH_VARARGS, tools_isstrlowercase_docstring},
    {"isstruppercase", (PyCFunction)tools_isstruppercase, METH_VARARGS, tools_isstruppercase_docstring},
    {"isstralnum", (PyCFunction)tools_isstralnum, METH_VARARGS, tools_isstralnum_docstring},
    {"isstralpha", (PyCFunction)tools_isstralpha, METH_VARARGS, tools_isstralpha_docstring},
    {"isstrnum", (PyCFunction)tools_isstrnum, METH_VARARGS, tools_isstrnum_docstring},
    {"isstrgraphical", (PyCFunction)tools_isstrgraphical, METH_VARARGS, tools_isstrgraphical_docstring},
    {"isstrprintable", (PyCFunction)tools_isstrprintable, METH_VARARGS, tools_isstrprintable_docstring},
    {"isstrpunctuation", (PyCFunction)tools_isstrpunctuation, METH_VARARGS, tools_isstrpunctuation_docstring},
    {"isstrwhitespace", (PyCFunction)tools_isstrwhitespace, METH_VARARGS, tools_isstrwhitespace_docstring},
    {"isstrhex", (PyCFunction)tools_isstrhex, METH_VARARGS, tools_isstrhex_docstring},
    {"strreplace", (PyCFunction)tools_strreplace, METH_VARARGS, tools_strreplace_docstring},
    {"strreplace_once", (PyCFunction)tools_strreplace_once, METH_VARARGS, tools_strreplace_once_docstring},
    {"rmgravequote", (PyCFunction)tools_rmgravequote, METH_VARARGS, tools_rmgravequote_docstring},
#if defined(ENV64BIT) && (defined(__x86_64__) || defined(__x86_64))
    {"rdtsc", (PyCFunction)tools_rdtsc, METH_NOARGS, tools_rdtsc_docstring},
    {"get_vendor_id", (PyCFunction)tools_get_vendor_id, METH_NOARGS, tools_get_vendor_id_docstring},
    {"get_cpu_stepping", (PyCFunction)tools_get_cpu_stepping, METH_NOARGS, tools_get_cpu_stepping_docstring},
#ifdef __BMI2__
    {"is_fpu_aval", (PyCFunction)tools_is_fpu_aval, METH_NOARGS, tools_is_fpu_aval_docstring},
    {"is_rdseed_aval", (PyCFunction)tools_is_rdseed_aval, METH_NOARGS, tools_is_rdseed_aval_docstring},
    {"is_est_aval", (PyCFunction)tools_is_est_aval, METH_NOARGS, tools_is_est_aval_docstring},
    {"is_avx_aval", (PyCFunction)tools_is_avx_aval, METH_NOARGS, tools_is_avx_aval_docstring},
    {"is_smx_aval", (PyCFunction)tools_is_smx_aval, METH_NOARGS, tools_is_smx_aval_docstring},
    {"is_xtpr_aval", (PyCFunction)tools_is_xtpr_aval, METH_NOARGS, tools_is_xtpr_aval_docstring},
    {"is_rtm_aval", (PyCFunction)tools_is_rtm_aval, METH_NOARGS, tools_is_rtm_aval_docstring},
    {"is_mpx_aval", (PyCFunction)tools_is_mpx_aval, METH_NOARGS, tools_is_mpx_aval_docstring},
    {"is_movbe_aval", (PyCFunction)tools_is_movbe_aval, METH_NOARGS, tools_is_movbe_aval_docstring},
    {"is_pge_aval", (PyCFunction)tools_is_pge_aval, METH_NOARGS, tools_is_pge_aval_docstring},
    {"is_vme_aval", (PyCFunction)tools_is_vme_aval, METH_NOARGS, tools_is_vme_aval_docstring},
    {"is_cmov_aval", (PyCFunction)tools_is_cmov_aval, METH_NOARGS, tools_is_cmov_aval_docstring},
    {"is_ds_aval", (PyCFunction)tools_is_ds_aval, METH_NOARGS, tools_is_ds_aval_docstring},
    {"is_de_aval", (PyCFunction)tools_is_de_aval, METH_NOARGS, tools_is_de_aval_docstring},
    {"is_acpi_aval", (PyCFunction)tools_is_acpi_aval, METH_NOARGS, tools_is_acpi_aval_docstring},
    {"is_sgx_aval", (PyCFunction)tools_is_sgx_aval, METH_NOARGS, tools_is_sgx_aval_docstring},
    {"is_invpcid_aval", (PyCFunction)tools_is_invpcid_aval, METH_NOARGS, tools_is_invpcid_aval_docstring},
    {"is_rdrnd_aval", (PyCFunction)tools_is_rdrnd_aval, METH_NOARGS, tools_is_rdrnd_aval_docstring},
    {"is_vmx_aval", (PyCFunction)tools_is_vmx_aval, METH_NOARGS, tools_is_vmx_aval_docstring},
    {"is_hypervisor_aval", (PyCFunction)tools_is_hypervisor_aval, METH_NOARGS, tools_is_hypervisor_aval_docstring},
    {"is_monitor_aval", (PyCFunction)tools_is_monitor_aval, METH_NOARGS, tools_is_monitor_aval_docstring},
    {"is_pse_aval", (PyCFunction)tools_is_pse_aval, METH_NOARGS, tools_is_pse_aval_docstring},
    {"is_fma_aval", (PyCFunction)tools_is_fma_aval, METH_NOARGS, tools_is_fma_aval_docstring},
    {"is_popcnt_aval", (PyCFunction)tools_is_popcnt_aval, METH_NOARGS, tools_is_popcnt_aval_docstring},
    {"is_tm_aval", (PyCFunction)tools_is_tm_aval, METH_NOARGS, tools_is_tm_aval_docstring},
    {"is_clflushopt_aval", (PyCFunction)tools_is_clflushopt_aval, METH_NOARGS, tools_is_clflushopt_aval_docstring},
    {"is_erms_aval", (PyCFunction)tools_is_erms_aval, METH_NOARGS, tools_is_erms_aval_docstring},
    {"is_sse_aval", (PyCFunction)tools_is_sse_aval, METH_NOARGS, tools_is_sse_aval_docstring},
    {"is_dscpl_aval", (PyCFunction)tools_is_dscpl_aval, METH_NOARGS, tools_is_dscpl_aval_docstring},
    {"is_tsc_aval", (PyCFunction)tools_is_tsc_aval, METH_NOARGS, tools_is_tsc_aval_docstring},
    {"is_tscdeadline_aval", (PyCFunction)tools_is_tscdeadline_aval, METH_NOARGS, tools_is_tscdeadline_aval_docstring},
    {"is_sep_aval", (PyCFunction)tools_is_sep_aval, METH_NOARGS, tools_is_sep_aval_docstring},
    {"is_hle_aval", (PyCFunction)tools_is_hle_aval, METH_NOARGS, tools_is_hle_aval_docstring},
    {"is_adx_aval", (PyCFunction)tools_is_adx_aval, METH_NOARGS, tools_is_adx_aval_docstring},
    {"is_sdbg_aval", (PyCFunction)tools_is_sdbg_aval, METH_NOARGS, tools_is_sdbg_aval_docstring},
    {"is_htt_aval", (PyCFunction)tools_is_htt_aval, METH_NOARGS, tools_is_htt_aval_docstring},
    {"is_apic_aval", (PyCFunction)tools_is_apic_aval, METH_NOARGS, tools_is_apic_aval_docstring},
    {"is_cnxtid_aval", (PyCFunction)tools_is_cnxtid_aval, METH_NOARGS, tools_is_cnxtid_aval_docstring},
    {"is_pqe_aval", (PyCFunction)tools_is_pqe_aval, METH_NOARGS, tools_is_pqe_aval_docstring},
    {"is_pcid_aval", (PyCFunction)tools_is_pcid_aval, METH_NOARGS, tools_is_pcid_aval_docstring},
    {"is_pbe_aval", (PyCFunction)tools_is_pbe_aval, METH_NOARGS, tools_is_pbe_aval_docstring},
    {"is_smap_aval", (PyCFunction)tools_is_smap_aval, METH_NOARGS, tools_is_smap_aval_docstring},
    {"is_fxsr_aval", (PyCFunction)tools_is_fxsr_aval, METH_NOARGS, tools_is_fxsr_aval_docstring},
    {"is_psn_aval", (PyCFunction)tools_is_psn_aval, METH_NOARGS, tools_is_psn_aval_docstring},
    {"is_dca_aval", (PyCFunction)tools_is_dca_aval, METH_NOARGS, tools_is_dca_aval_docstring},
    {"is_pcommit_aval", (PyCFunction)tools_is_pcommit_aval, METH_NOARGS, tools_is_pcommit_aval_docstring},
    {"is_clwb_aval", (PyCFunction)tools_is_clwb_aval, METH_NOARGS, tools_is_clwb_aval_docstring},
    {"is_aes_aval", (PyCFunction)tools_is_aes_aval, METH_NOARGS, tools_is_aes_aval_docstring},
    {"is_xsave_aval", (PyCFunction)tools_is_xsave_aval, METH_NOARGS, tools_is_xsave_aval_docstring},
    {"is_smep_aval", (PyCFunction)tools_is_smep_aval, METH_NOARGS, tools_is_smep_aval_docstring},
    {"is_pqm_aval", (PyCFunction)tools_is_pqm_aval, METH_NOARGS, tools_is_pqm_aval_docstring},
    {"is_fsgsbase_aval", (PyCFunction)tools_is_fsgsbase_aval, METH_NOARGS, tools_is_fsgsbase_aval_docstring},
    {"is_clfsh_aval", (PyCFunction)tools_is_clfsh_aval, METH_NOARGS, tools_is_clfsh_aval_docstring},
    {"is_mmx_aval", (PyCFunction)tools_is_mmx_aval, METH_NOARGS, tools_is_mmx_aval_docstring},
    {"is_ss_aval", (PyCFunction)tools_is_ss_aval, METH_NOARGS, tools_is_ss_aval_docstring},
    {"is_msr_aval", (PyCFunction)tools_is_msr_aval, METH_NOARGS, tools_is_msr_aval_docstring},
    {"is_pat_aval", (PyCFunction)tools_is_pat_aval, METH_NOARGS, tools_is_pat_aval_docstring},
    {"is_processor_trace_aval", (PyCFunction)tools_is_processor_trace_aval, METH_NOARGS, tools_is_processor_trace_aval_docstring},
    {"is_pdcm_aval", (PyCFunction)tools_is_pdcm_aval, METH_NOARGS, tools_is_pdcm_aval_docstring},
    {"is_mca_aval", (PyCFunction)tools_is_mca_aval, METH_NOARGS, tools_is_mca_aval_docstring},
    {"is_mce_aval", (PyCFunction)tools_is_mce_aval, METH_NOARGS, tools_is_mce_aval_docstring},
    {"is_osxsave_aval", (PyCFunction)tools_is_osxsave_aval, METH_NOARGS, tools_is_osxsave_aval_docstring},
    {"is_pae_aval", (PyCFunction)tools_is_pae_aval, METH_NOARGS, tools_is_pae_aval_docstring},
    {"is_sha_aval", (PyCFunction)tools_is_sha_aval, METH_NOARGS, tools_is_sha_aval_docstring},
    {"is_mtrr_aval", (PyCFunction)tools_is_mtrr_aval, METH_NOARGS, tools_is_mtrr_aval_docstring},
    {"is_pclmulqdq_aval", (PyCFunction)tools_is_pclmulqdq_aval, METH_NOARGS, tools_is_pclmulqdq_aval_docstring},
    {"is_avx512pf_aval", (PyCFunction)tools_is_avx512pf_aval, METH_NOARGS, tools_is_avx512pf_aval_docstring},
    {"is_dtes64_aval", (PyCFunction)tools_is_dtes64_aval, METH_NOARGS, tools_is_dtes64_aval_docstring},
    {"is_sse3_aval", (PyCFunction)tools_is_sse3_aval, METH_NOARGS, tools_is_sse3_aval_docstring},
    {"is_tm2_aval", (PyCFunction)tools_is_tm2_aval, METH_NOARGS, tools_is_tm2_aval_docstring},
    {"is_avx512dq_aval", (PyCFunction)tools_is_avx512dq_aval, METH_NOARGS, tools_is_avx512dq_aval_docstring},
    {"is_sse42_aval", (PyCFunction)tools_is_sse42_aval, METH_NOARGS, tools_is_sse42_aval_docstring},
    {"is_cx16_aval", (PyCFunction)tools_is_cx16_aval, METH_NOARGS, tools_is_cx16_aval_docstring},
    {"is_x2apic_aval", (PyCFunction)tools_is_x2apic_aval, METH_NOARGS, tools_is_x2apic_aval_docstring},
    {"is_ssse3_aval", (PyCFunction)tools_is_ssse3_aval, METH_NOARGS, tools_is_ssse3_aval_docstring},
    {"is_avx512vbmi_aval", (PyCFunction)tools_is_avx512vbmi_aval, METH_NOARGS, tools_is_avx512vbmi_aval_docstring},
    {"is_pse36_aval", (PyCFunction)tools_is_pse36_aval, METH_NOARGS, tools_is_pse36_aval_docstring},
    {"is_avx512ifma_aval", (PyCFunction)tools_is_avx512ifma_aval, METH_NOARGS, tools_is_avx512ifma_aval_docstring},
    {"is_avx512er_aval", (PyCFunction)tools_is_avx512er_aval, METH_NOARGS, tools_is_avx512er_aval_docstring},
    {"is_avx512cd_aval", (PyCFunction)tools_is_avx512cd_aval, METH_NOARGS, tools_is_avx512cd_aval_docstring},
    {"is_ia64_aval", (PyCFunction)tools_is_ia64_aval, METH_NOARGS, tools_is_ia64_aval_docstring},
    {"is_prefetchwt1_aval", (PyCFunction)tools_is_prefetchwt1_aval, METH_NOARGS, tools_is_prefetchwt1_aval_docstring},
    {"is_ia32_tsc_adjust_aval", (PyCFunction)tools_is_ia32_tsc_adjust_aval, METH_NOARGS, tools_is_ia32_tsc_adjust_aval_docstring},
    {"is_sse2_aval", (PyCFunction)tools_is_sse2_aval, METH_NOARGS, tools_is_sse2_aval_docstring},
    {"is_cx8_aval", (PyCFunction)tools_is_cx8_aval, METH_NOARGS, tools_is_cx8_aval_docstring},
    {"is_bmi2_aval", (PyCFunction)tools_is_bmi2_aval, METH_NOARGS, tools_is_bmi2_aval_docstring},
    {"is_avx512vl_aval", (PyCFunction)tools_is_avx512vl_aval, METH_NOARGS, tools_is_avx512vl_aval_docstring},
    {"is_avx512f_aval", (PyCFunction)tools_is_avx512f_aval, METH_NOARGS, tools_is_avx512f_aval_docstring},
    {"is_bmi1_aval", (PyCFunction)tools_is_bmi1_aval, METH_NOARGS, tools_is_bmi1_aval_docstring},
    {"is_avx2_aval", (PyCFunction)tools_is_avx2_aval, METH_NOARGS, tools_is_avx2_aval_docstring},
    {"is_avx512bw_aval", (PyCFunction)tools_is_avx512bw_aval, METH_NOARGS, tools_is_avx512bw_aval_docstring},
    {"is_sse41_aval", (PyCFunction)tools_is_sse41_aval, METH_NOARGS, tools_is_sse41_aval_docstring},
    {"is_f16c_aval", (PyCFunction)tools_is_f16c_aval, METH_NOARGS, tools_is_f16c_aval_docstring},
#endif
#endif
    {"nop", (PyCFunction)tools_nop, METH_NOARGS, tools_nop_docstring},
    {"endianness", (PyCFunction)tools_endianness, METH_NOARGS, tools_endianness_docstring},
#if (defined(__GNUC__) || defined(__CC_ARM) || defined(__INTEL_COMPILER) || defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__) || defined(__TINYC__))
    {"getarch", (PyCFunction)tools_getarch, METH_NOARGS, tools_getarch_docstring},
    {"getos", (PyCFunction)tools_getos, METH_NOARGS, tools_getos_docstring},
#endif
    {"isandroid", (PyCFunction)tools_isandroid, METH_NOARGS, tools_isandroid_docstring},
    {"CSTD", (PyCFunction)tools_CSTD, METH_NOARGS, tools_CSTD_docstring},
#ifdef _POSIX_VERSION
    {"POSIXSTD", (PyCFunction)tools_POSIXSTD, METH_NOARGS, tools_POSIXSTD_docstring},
#endif
#ifdef OSPOSIX
    {"getsyshostname", (PyCFunction)tools_getsyshostname, METH_NOARGS, tools_getsyshostname_docstring},
#endif
    {"printline", (PyCFunction)tools_printline, METH_NOARGS, tools_printline_docstring},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef module = {  // Module Definition
    PyModuleDef_HEAD_INIT,
    MODNAME,  // Module name
    module_docstring,  // Module docstring
    -1,  // Module size
    module_methods,  // Module methods
    NULL,  // Module reload
    NULL,  // Module traverse
    NULL,  // Module clear
    NULL  // Module free
};


MODINIT {  // Initialize module
    PyObject *m;
    m = PyModule_Create(&module);
#   ifndef NOAUTHOR
    PyModule_AddStringConstant(m, "__author__", __author__);
#   endif
#   ifndef NOVERSION
    PyModule_AddStringConstant(m, "__version__", __version__);
#   endif
    if (m == (PyObject *)NULL) return NULL;
    return m;
}


/* C CODE */


/* STRING CONVERSIONS */


static PyObject *tools_lowercasestr(FUNCARGS) {
    char *str;
    ASSERT_STRING_ARG(str);
    if (str != (char *)NULL) {
        register size_t i;
        for (i = strlenx(str); --i;) {
            if (str[i] < 'A' || str[i] > 'Z') { continue; }  // str[i] is not uppercase
            switch (str[i]) {
                case 'A': str[i] = 'a'; break;
                case 'B': str[i] = 'b'; break;
                case 'C': str[i] = 'c'; break;
                case 'D': str[i] = 'd'; break;
                case 'E': str[i] = 'e'; break;
                case 'R': str[i] = 'r'; break;
                case 'S': str[i] = 's'; break;
                case 'T': str[i] = 't'; break;
                case 'F': str[i] = 'f'; break;
                case 'H': str[i] = 'h'; break;
                case 'I': str[i] = 'i'; break;
                case 'L': str[i] = 'l'; break;
                case 'M': str[i] = 'm'; break;
                default:
                    switch (str[i]) {
                        case 'N': str[i] = 'n'; break;
                        case 'O': str[i] = 'o'; break;
                        case 'P': str[i] = 'p'; break;
                        case 'Q': str[i] = 'q'; break;
                        case 'G': str[i] = 'g'; break;
                        case 'J': str[i] = 'j'; break;
                        case 'K': str[i] = 'k'; break;
                        case 'U': str[i] = 'u'; break;
                        case 'V': str[i] = 'v'; break;
                        case 'W': str[i] = 'w'; break;
                        case 'X': str[i] = 'x'; break;
                        case 'Y': str[i] = 'y'; break;
                        case 'Z': str[i] = 'z'; break;
                        default: break;
                    }
                    break;
            }
        }
        switch (str[0]) {  // Final character to convert
            case '.':
            case ' ': break;
            case 'A': str[0] = 'a'; break;
            case 'B': str[0] = 'b'; break;
            case 'C': str[0] = 'c'; break;
            case 'D': str[0] = 'd'; break;
            case 'E': str[0] = 'e'; break;
            case 'R': str[0] = 'r'; break;
            case 'S': str[0] = 's'; break;
            case 'T': str[0] = 't'; break;
            case 'F': str[0] = 'f'; break;
            case 'H': str[0] = 'h'; break;
            case 'I': str[0] = 'i'; break;
            case 'L': str[0] = 'l'; break;
            case 'M': str[0] = 'm'; break;
            default:
                switch (str[0]) {
                    case 'N': str[0] = 'n'; break;
                    case 'O': str[0] = 'o'; break;
                    case 'P': str[0] = 'p'; break;
                    case 'Q': str[0] = 'q'; break;
                    case 'G': str[0] = 'g'; break;
                    case 'J': str[0] = 'j'; break;
                    case 'K': str[0] = 'k'; break;
                    case 'U': str[0] = 'u'; break;
                    case 'V': str[0] = 'v'; break;
                    case 'W': str[0] = 'w'; break;
                    case 'X': str[0] = 'x'; break;
                    case 'Y': str[0] = 'y'; break;
                    case 'Z': str[0] = 'z'; break;
                    default: break;
                }
                break;
        }
    }
    return STR(str);
}


static PyObject *tools_lowercasestr15(FUNCARGS) {
    char *str;
    ASSERT_STRING_ARG(str);
    if (str != (char *)NULL) {
        str[0] = ((str[0] > 0x5A || str[0] < 0x41) ? str[0] : (char)((uint8_t)str[0] + 0x20u));
        str[1] = ((str[1] > 0x5A || str[1] < 0x41) ? str[1] : (char)((uint8_t)str[1] + 0x20u));
        str[2] = ((str[2] > 0x5A || str[2] < 0x41) ? str[2] : (char)((uint8_t)str[2] + 0x20u));
        str[3] = ((str[3] > 0x5A || str[3] < 0x41) ? str[3] : (char)((uint8_t)str[3] + 0x20u));
        str[4] = ((str[4] > 0x5A || str[4] < 0x41) ? str[4] : (char)((uint8_t)str[4] + 0x20u));
        str[5] = ((str[5] > 0x5A || str[5] < 0x41) ? str[5] : (char)((uint8_t)str[5] + 0x20u));
        str[6] = ((str[6] > 0x5A || str[6] < 0x41) ? str[6] : (char)((uint8_t)str[6] + 0x20u));
        str[7] = ((str[7] > 0x5A || str[7] < 0x41) ? str[7] : (char)((uint8_t)str[7] + 0x20u));
        str[8] = ((str[8] > 0x5A || str[8] < 0x41) ? str[8] : (char)((uint8_t)str[8] + 0x20u));
        str[9] = ((str[9] > 0x5A || str[9] < 0x41) ? str[9] : (char)((uint8_t)str[9] + 0x20u));
        str[10] = ((str[10] > 0x5A || str[10] < 0x41) ? str[10] : (char)((uint8_t)str[10] + 0x20u));
        str[11] = ((str[11] > 0x5A || str[11] < 0x41) ? str[11] : (char)((uint8_t)str[11] + 0x20u));
        str[12] = ((str[12] > 0x5A || str[12] < 0x41) ? str[12] : (char)((uint8_t)str[12] + 0x20u));
        str[13] = ((str[13] > 0x5A || str[13] < 0x41) ? str[13] : (char)((uint8_t)str[13] + 0x20u));
        str[14] = ((str[14] > 0x5A || str[14] < 0x41) ? str[14] : (char)((uint8_t)str[14] + 0x20u));
        str[15] = '\0';
    }
    return STR(str);
}


static PyObject *tools_uppercasestr(FUNCARGS) {
    char *str;
    ASSERT_STRING_ARG(str);
    if (str != (char *)NULL) {
        register size_t i;
        for (i = strlenx(str); --i;) {
            if (str[i] < 'a' || str[i] > 'z') { continue; }  // str[i] is not lowercase
            switch (str[i]) {
                case 'a': str[i] = 'A'; break;
                case 'b': str[i] = 'B'; break;
                case 'c': str[i] = 'C'; break;
                case 'd': str[i] = 'D'; break;
                case 'e': str[i] = 'E'; break;
                case 'r': str[i] = 'R'; break;
                case 's': str[i] = 'S'; break;
                case 't': str[i] = 'T'; break;
                case 'f': str[i] = 'F'; break;
                case 'h': str[i] = 'H'; break;
                case 'i': str[i] = 'I'; break;
                case 'l': str[i] = 'L'; break;
                case 'm': str[i] = 'M'; break;
                default:
                    switch (str[i]) {
                        case 'n': str[i] = 'N'; break;
                        case 'o': str[i] = 'O'; break;
                        case 'p': str[i] = 'P'; break;
                        case 'q': str[i] = 'Q'; break;
                        case 'g': str[i] = 'G'; break;
                        case 'j': str[i] = 'J'; break;
                        case 'k': str[i] = 'K'; break;
                        case 'u': str[i] = 'U'; break;
                        case 'v': str[i] = 'V'; break;
                        case 'w': str[i] = 'W'; break;
                        case 'x': str[i] = 'X'; break;
                        case 'y': str[i] = 'Y'; break;
                        case 'z': str[i] = 'Z'; break;
                        default: break;
                    }
                    break;
            }
        }
        switch (str[0]) {  // Final character to convert
            case '.':
            case ' ': break;
            case 'a': str[0] = 'A'; break;
            case 'b': str[0] = 'B'; break;
            case 'c': str[0] = 'C'; break;
            case 'd': str[0] = 'D'; break;
            case 'e': str[0] = 'E'; break;
            case 'r': str[0] = 'R'; break;
            case 's': str[0] = 'S'; break;
            case 't': str[0] = 'T'; break;
            case 'f': str[0] = 'F'; break;
            case 'h': str[0] = 'H'; break;
            case 'i': str[0] = 'I'; break;
            case 'l': str[0] = 'L'; break;
            case 'm': str[0] = 'M'; break;
            default:
                switch (str[0]) {
                    case 'n': str[0] = 'N'; break;
                    case 'o': str[0] = 'O'; break;
                    case 'p': str[0] = 'P'; break;
                    case 'q': str[0] = 'Q'; break;
                    case 'g': str[0] = 'G'; break;
                    case 'j': str[0] = 'J'; break;
                    case 'k': str[0] = 'K'; break;
                    case 'u': str[0] = 'U'; break;
                    case 'v': str[0] = 'V'; break;
                    case 'w': str[0] = 'W'; break;
                    case 'x': str[0] = 'X'; break;
                    case 'y': str[0] = 'Y'; break;
                    case 'z': str[0] = 'Z'; break;
                    default: break;
                }
                break;
        }
    }
    return STR(str);
}


/* STRING BOOLEAN TESTS */


static PyObject *tools_isstrlowercase(FUNCARGS) {
    const char *str;
    ASSERT_STRING_ARG(str);
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (ISLOWERASCII(str[i - 0x01]) == 0x0) { Py_RETURN_FALSE; } }
    Py_RETURN_TRUE;
}


static PyObject *tools_isstruppercase(FUNCARGS) {
    const char *str;
    ASSERT_STRING_ARG(str);
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (ISUPPERASCII(str[i - 0x01]) == 0) Py_RETURN_FALSE; }
    Py_RETURN_TRUE;
}


static PyObject *tools_isstralnum(FUNCARGS) {
    const char *str;
    ASSERT_STRING_ARG(str);
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (ISALNUM(str[i - 0x01]) == 0) Py_RETURN_FALSE; }
    Py_RETURN_TRUE;
}


static PyObject *tools_isstralpha(FUNCARGS) {
    const char *str;
    ASSERT_STRING_ARG(str);
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (ISALPHA(str[i - 0x01]) == 0) Py_RETURN_FALSE; }
    Py_RETURN_TRUE;
}


static PyObject *tools_isstrnum(FUNCARGS) {
    const char *str;
    ASSERT_STRING_ARG(str);
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (ISDIGIT(str[i - 0x01]) == 0) Py_RETURN_FALSE; }
    Py_RETURN_TRUE;
}


static PyObject *tools_isstrgraphical(FUNCARGS) {
    const char *str;
    ASSERT_STRING_ARG(str);
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (ISGRAPH(str[i - 0x01]) == 0) Py_RETURN_FALSE; }
    Py_RETURN_TRUE;
}


static PyObject *tools_isstrprintable(FUNCARGS) {
    const char *str;
    ASSERT_STRING_ARG(str);
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (ISPRINT(str[i - 0x01]) == 0) Py_RETURN_FALSE; }
    Py_RETURN_TRUE;
}


static PyObject *tools_isstrpunctuation(FUNCARGS) {
    const char *str;
    ASSERT_STRING_ARG(str);
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (ISPUNCT(str[i - 0x01]) == 0) Py_RETURN_FALSE; }
    Py_RETURN_TRUE;
}


static PyObject *tools_isstrwhitespace(FUNCARGS) {
    const char *str;
    ASSERT_STRING_ARG(str);
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (ISSPACE(str[i - 0x01]) == 0) Py_RETURN_FALSE; }
    Py_RETURN_TRUE;
}


static PyObject *tools_isstrhex(FUNCARGS) {
    const char *str;
    ASSERT_STRING_ARG(str);
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (ISXDIGIT(str[i - 0x01]) == 0) Py_RETURN_FALSE; }
    Py_RETURN_TRUE;
}


/* FIND AND REPLACE/REMOVE */


static PyObject *tools_strreplace(FUNCARGS) {
    char *orig_string, *find, *replace_with;
    ASSERT_3STRING_ARG(orig_string, find, replace_with);
    register size_t len_size = strlenx(orig_string);
    if (len_size > 0x400) PyErr_SetString(PyExc_ValueError, "ERROR: String too large!");
    register const ulint find_size = strlenx(find);
    if (!(len_size) || !(find_size)) PyErr_SetString(PyExc_ValueError, "ERROR: A parameter is NULL!");
    else if ((strstr(orig_string, find) == NULL)) return STR(orig_string);  // Is find in orig_string
    static char buffer[0x400];  // 0x400 == 1024
    strncpy(buffer, orig_string, len_size);
    buffer[len_size] = '\0';
    register char *after_find, *p;
    char after_find_buffer[0x400];
    register const size_t rpl_size = strlenx(replace_with);
    for (p = strstr(buffer, find); (p = strstr(buffer, find));) {
        buffer[(size_t)(p - buffer)] = '\0';
        after_find = (char *)(p + find_size);
        len_size = strlenx(after_find);
        strncpy(after_find_buffer, after_find, len_size);
        strncat(buffer, replace_with, rpl_size);
        strncat(buffer, after_find_buffer, len_size);
    }
    return STR((buffer));
}


static PyObject *tools_strreplace_once(FUNCARGS) {
    char *orig_string, *find, *replace_with;
    ASSERT_3STRING_ARG(orig_string, find, replace_with);
    return STR((strreplace_once(orig_string, find, replace_with)));
}


static PyObject *tools_rmgravequote(FUNCARGS) {
    char *orig_string;
    ASSERT_STRING_ARG(orig_string);
    return STR((rmgravequote(orig_string)));
}


/* ASSEMBLY-RELATED COMMANDS */


#if (defined(ENV64BIT) && (defined(__x86_64__) || defined(__x86_64)))


static PyObject *tools_rdtsc(void) {
    //register ullint cpu_ticks;
    register ullint cpu_ticks;
    __asm__ volatile ("rdtsc;" : "=A" ( cpu_ticks ));  // `=A` is `edx:eax`
    return ull2int(cpu_ticks);
}


static PyObject *tools_get_vendor_id(void) {
    return pystr(get_vendor_id(), 12);
}


static PyObject *tools_get_cpu_stepping(void) {
    register signed int stepping;
    __asm__ (
        "movl $0x01,%%eax;"
        "cpuid;"
        "andl $0b00000000000000000000000000001111,%%eax;"
        "movl %%eax,%0;"
        : "=r" ( stepping )  // Output C variable
    );
    return int2int(stepping);
}


#ifdef __BMI2__
static PyObject *tools_is_fpu_aval(void) {
    if (!is_fpu_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_rdseed_aval(void) {
    if (!is_rdseed_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_est_aval(void) {
    if (!is_est_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_avx_aval(void) {
    if (!is_avx_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_smx_aval(void) {
    if (!is_smx_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_xtpr_aval(void) {
    if (!is_xtpr_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_rtm_aval(void) {
    if (!is_rtm_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_mpx_aval(void) {
    if (!is_mpx_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_movbe_aval(void) {
    if (!is_movbe_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_pge_aval(void) {
    if (!is_pge_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_vme_aval(void) {
    if (!is_vme_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_cmov_aval(void) {
    if (!is_cmov_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_ds_aval(void) {
    if (!is_ds_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_de_aval(void) {
    if (!is_de_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_acpi_aval(void) {
    if (!is_acpi_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_sgx_aval(void) {
    if (!is_sgx_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_invpcid_aval(void) {
    if (!is_invpcid_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_rdrnd_aval(void) {
    if (!is_rdrnd_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_vmx_aval(void) {
    if (!is_vmx_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_hypervisor_aval(void) {
    if (!is_hypervisor_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_monitor_aval(void) {
    if (!is_monitor_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_pse_aval(void) {
    if (!is_pse_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_fma_aval(void) {
    if (!is_fma_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_popcnt_aval(void) {
    if (!is_popcnt_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_tm_aval(void) {
    if (!is_tm_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_clflushopt_aval(void) {
    if (!is_clflushopt_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_erms_aval(void) {
    if (!is_erms_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_sse_aval(void) {
    if (!is_sse_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_dscpl_aval(void) {
    if (!is_dscpl_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_tsc_aval(void) {
    if (!is_tsc_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_tscdeadline_aval(void) {
    if (!is_tscdeadline_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_sep_aval(void) {
    if (!is_sep_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_hle_aval(void) {
    if (!is_hle_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_adx_aval(void) {
    if (!is_adx_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_sdbg_aval(void) {
    if (!is_sdbg_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_htt_aval(void) {
    if (!is_htt_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_apic_aval(void) {
    if (!is_apic_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_cnxtid_aval(void) {
    if (!is_cnxtid_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_pqe_aval(void) {
    if (!is_pqe_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_pcid_aval(void) {
    if (!is_pcid_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_pbe_aval(void) {
    if (!is_pbe_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_smap_aval(void) {
    if (!is_smap_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_fxsr_aval(void) {
    if (!is_fxsr_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_psn_aval(void) {
    if (!is_psn_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_dca_aval(void) {
    if (!is_dca_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_pcommit_aval(void) {
    if (!is_pcommit_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_clwb_aval(void) {
    if (!is_clwb_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_aes_aval(void) {
    if (!is_aes_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_xsave_aval(void) {
    if (!is_xsave_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_smep_aval(void) {
    if (!is_smep_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_pqm_aval(void) {
    if (!is_pqm_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_fsgsbase_aval(void) {
    if (!is_fsgsbase_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_clfsh_aval(void) {
    if (!is_clfsh_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_mmx_aval(void) {
    if (!is_mmx_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_ss_aval(void) {
    if (!is_ss_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_msr_aval(void) {
    if (!is_msr_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_pat_aval(void) {
    if (!is_pat_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_processor_trace_aval(void) {
    if (!is_processor_trace_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_pdcm_aval(void) {
    if (!is_pdcm_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_mca_aval(void) {
    if (!is_mca_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_mce_aval(void) {
    if (!is_mce_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_osxsave_aval(void) {
    if (!is_osxsave_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_pae_aval(void) {
    if (!is_pae_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_sha_aval(void) {
    if (!is_sha_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_mtrr_aval(void) {
    if (!is_mtrr_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_pclmulqdq_aval(void) {
    if (!is_pclmulqdq_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_avx512pf_aval(void) {
    if (!is_avx512pf_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_dtes64_aval(void) {
    if (!is_dtes64_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_sse3_aval(void) {
    if (!is_sse3_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_tm2_aval(void) {
    if (!is_tm2_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_avx512dq_aval(void) {
    if (!is_avx512dq_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_sse42_aval(void) {
    if (!is_sse42_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_cx16_aval(void) {
    if (!is_cx16_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_x2apic_aval(void) {
    if (!is_x2apic_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_ssse3_aval(void) {
    if (!is_ssse3_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_avx512vbmi_aval(void) {
    if (!is_avx512vbmi_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_pse36_aval(void) {
    if (!is_pse36_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_avx512ifma_aval(void) {
    if (!is_avx512ifma_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_avx512er_aval(void) {
    if (!is_avx512er_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_avx512cd_aval(void) {
    if (!is_avx512cd_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_ia64_aval(void) {
    if (!is_ia64_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_prefetchwt1_aval(void) {
    if (!is_prefetchwt1_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_ia32_tsc_adjust_aval(void) {
    if (!is_ia32_tsc_adjust_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_sse2_aval(void) {
    if (!is_sse2_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_cx8_aval(void) {
    if (!is_cx8_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_bmi2_aval(void) {
    if (!is_bmi2_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_avx512vl_aval(void) {
    if (!is_avx512vl_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_avx512f_aval(void) {
    if (!is_avx512f_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_bmi1_aval(void) {
    if (!is_bmi1_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_avx2_aval(void) {
    if (!is_avx2_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_avx512bw_aval(void) {
    if (!is_avx512bw_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_sse41_aval(void) {
    if (!is_sse41_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}


static PyObject *tools_is_f16c_aval(void) {
    if (!is_f16c_aval()) Py_RETURN_FALSE;
    Py_RETURN_TRUE;
}
#endif


#endif


static PyObject *tools_nop(void) {
    __asm__ volatile ("nop;");
    Py_RETURN_NONE;
}


/* SYSTEM INFO */


static PyObject *tools_endianness(void) {
    return STR((endianness()));
}


#if (defined(__GNUC__) || defined(__CC_ARM) || defined(__INTEL_COMPILER) || defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__) || defined(__TINYC__))


static PyObject *tools_getarch(void) {
#if (defined(__arm__) || defined(__arm) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT))
    return STR("ARM");
#elif defined(__aarch64__)
    return STR("ARM64");
#elif (defined(__x86_64__) || defined(__x86_64) || defined(_WIN64) || defined(__MINGW64__) || defined(_M_X64))
    return STR("x86-64");
#elif (defined(__amd64__) || defined(__amd64) || defined(_M_AMD64))
    return STR("AMD64");
#elif (defined(i386) || defined(__i386) || defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__) || defined(__IA32__) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__386))
    return STR("x86");
#elif (defined(__ia64__) || defined(_IA64) || defined(__IA64__) || defined(__ia64) || defined(_M_IA64) || defined(__itanium__))
    return STR("Itanium");
#elif (defined(__ppc64__) || defined(ppc64le) || defined(__powerpc64__) || defined(__PPC64__) || defined(_ARCH_PPC64))
    return STR("PowerPC64");
#elif (defined(__ppc__) || defined(__powerpc__) || defined(__PPC__) || defined(_ARCH_PPC) || defined(__POWERPC__) || defined(__powerpc))
    return STR("PowerPC");
#elif (defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA))
    return STR("Alpha");
#elif (defined(__bfin) || defined(__BFIN__))
    return STR("Blackfin");
#elif defined(__convex__)
    return STR("Convex");
#elif (defined(__mips__) || defined(__mips) || defined(mips) || defined(__MIPS__))
    return STR("MIPS");
#elif (defined(__sparc__) || defined(__sparc))
    return STR("SPARC");
#else
    return STR("Unknown");
#endif
}


static PyObject *tools_getos(void) {
#if defined(__ANDROID__)
    return STR("Android");
#elif defined(__CYGWIN__) || defined(__CYGWIN32__)
    return STR("Cygwin");
#elif defined(__gnu_hurd__)
    return STR("GNU/Hurd");
#elif defined(__FreeBSD_kernel__ ) && defined(__GLIBC__ )
    return STR("GNU/kFreeBSD");
#elif defined(__gnu_linux__)
    return STR("GNU/Linux");
#elif (defined(__linux__) || defined(linux) || defined(__linux) || defined(BOOST_OS_LINUX))
    return STR("Linux");
#elif (defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__))
    return STR("Solaris");
#elif (defined(sun) || defined(__sun)) && !(defined(__SVR4) || defined(__svr4__))
    return STR("SunOS");
#elif (defined(sun) || defined(__sun))
    return STR("Sun System");
#elif defined(__DragonFly__)
    return STR("DragonFlyBSD");
#elif (defined(__FreeBSD__) || defined(__FreeBSD_kernel__))
    return STR("FreeBSD");
#elif defined(__NetBSD__)
    return STR("NetBSD");
#elif defined(__OpenBSD__)
    return STR("OpenBSD");
#elif (defined(BSD) || defined(_SYSTYPE_BSD) || defined(__bsdi__))
    return STR("BSD");
#elif (defined(macintosh) || defined(Macintosh) || defined(BOOST_OS_MACOS))
    return STR("MacOS");
#elif (defined(__APPLE__) && defined(__MACH__))
    return STR("OSX");
#elif (defined(__APPLE__) && !defined(__MACH__))
    return STR("Apple");
#elif (defined(__MACH__) && !defined(__APPLE__))
    return STR("NextStep");
#elif (defined(__MINGW32__) || defined(__MINGW64__) || defined(__WINNT__) || defined(__NT__) || defined(_WIN64) || defined(_WIN32) || defined(WIN32) || defined(__WIN32__) || defined(BOOST_OS_WINDOWS) || defined(_UWIN) || defined(__TOS_WIN__) || defined(__WINDOWS__) || defined(_WIN32_WCE) || defined(_MSC_VER))
    return STR("Windows");
#elif defined(_AIX)
    return STR("AIX");
#elif (defined(__amigaos__) || defined(AMIGA))
    return STR("AmigaOS");
#elif defined(aegis)
    return STR("Apollo AEGIS");
#elif defined(__BEOS__)
    return STR("BeOS");
#elif (defined(__bg__) || defined(__THW_BLUEGENE__))
    return STR("Blue Gene");
#elif defined(__ECOS)
    return STR("eCos");
#elif (defined(_hpux) || defined(hpux) || defined(__hpux))
    return STR("HP-UX");
#elif (defined(sgi) || defined(__sgi))
    return STR("IRIX");
#elif defined(__Lynx__)
    return STR("LynxOS");
#elif defined(__minix)
    return STR("Minix");
#elif defined(__MORPHOS__)
    return STR("MorphOS");
#elif defined(EPLAN9)
    return STR("Plan 9");
#elif (defined(__QNX__) || defined(__QNXNTO__))
    return STR("QNX");
#elif (defined(ultrix) || defined(__ultrix) || defined(__ultrix__))
    return STR("Ultrix");
#elif (defined(_CRAY) || defined(__crayx1) || defined(_UNICOS))
    return STR("UNICOS");
#elif defined(_UNIXWARE7)
    return STR("UnixWare");
#elif (defined(__VXWORKS__) || defined(__vxworks))
    return STR("VxWorks");
#elif (defined(__unix__) || defined(unix) || defined(__unix))
    return STR("Unix");
#else
    return STR("Unknown");
#endif
}


#endif


static PyObject *tools_isandroid(void) {
#ifdef __ANDROID__
    Py_RETURN_TRUE;
#else
    Py_RETURN_FALSE;
#endif
}


static PyObject *tools_CSTD(void) {
    return long2int(((long)__STDC_VERSION__));
}


#ifdef _POSIX_VERSION
static PyObject *tools_POSIXSTD(void) {
    return long2int(((long)(_POSIX_VERSION)));
}
#endif


#ifdef OSPOSIX
static PyObject *tools_getsyshostname(void) {
    static char hostname[32] = { 0 };
    if (gethostname(hostname, sizeof(hostname)) != 0x00) {
        hostname[0] = '?';
        hostname[1] = '\0';
    }
    return STR((hostname));
}
#endif


/* MISCELLANEOUS */


static PyObject *tools_printline(void) {
    fputs("\n\n", stdout);
    fflush(stdout);
    Py_RETURN_NONE;
}

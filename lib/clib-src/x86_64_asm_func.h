// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file x86_64_asm_func.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief x86-64 Assembly Functions (header)
@version 2016.03.09

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


#ifndef FILE_X86_64_ASM_FUNC_SEEN
#define FILE_X86_64_ASM_FUNC_SEEN


#include "MACROS.h"


#if (defined(ENV64BIT) && (defined(__x86_64__) || defined(__x86_64)))
/* GET GPU INFO */
#ifdef __amd64__
const char *amd_gpu(void);
#endif
/* GET CPU INFO */
ullint rdtsc(void);
const char *get_vendor_id(void);
signed int get_cpu_stepping(void);
#ifdef __BMI2__
signed int get_cpu_model(void);
ulint get_cpu_features(void);
/* BOOLEAN TESTS FOR FEATURES */
int is_fpu_aval(void);
int is_vme_aval(void);
int is_de_aval(void);
int is_pse_aval(void);
int is_tsc_aval(void);
int is_msr_aval(void);
int is_pae_aval(void);
int is_mce_aval(void);
int is_cx8_aval(void);
int is_apic_aval(void);
int is_sep_aval(void);
int is_mtrr_aval(void);
int is_pge_aval(void);
int is_mca_aval(void);
int is_cmov_aval(void);
int is_pat_aval(void);
int is_pse36_aval(void);
int is_psn_aval(void);
int is_clfsh_aval(void);
int is_ds_aval(void);
int is_acpi_aval(void);
int is_mmx_aval(void);
int is_fxsr_aval(void);
int is_sse_aval(void);
int is_sse2_aval(void);
int is_ss_aval(void);
int is_htt_aval(void);
int is_tm_aval(void);
int is_ia64_aval(void);
int is_pbe_aval(void);
int is_sse3_aval(void);
int is_pclmulqdq_aval(void);
int is_dtes64_aval(void);
int is_monitor_aval(void);
int is_dscpl_aval(void);
int is_vmx_aval(void);
int is_smx_aval(void);
int is_est_aval(void);
int is_tm2_aval(void);
int is_ssse3_aval(void);
int is_cnxtid_aval(void);
int is_sdbg_aval(void);
int is_fma_aval(void);
int is_cx16_aval(void);
int is_xtpr_aval(void);
int is_pdcm_aval(void);
int is_pcid_aval(void);
int is_dca_aval(void);
int is_sse41_aval(void);
int is_sse42_aval(void);
int is_x2apic_aval(void);
int is_movbe_aval(void);
int is_popcnt_aval(void);
int is_tscdeadline_aval(void);
int is_aes_aval(void);
int is_xsave_aval(void);
int is_osxsave_aval(void);
int is_avx_aval(void);
int is_f16c_aval(void);
int is_rdrnd_aval(void);
int is_hypervisor_aval(void);
int is_fsgsbase_aval(void);
int is_ia32_tsc_adjust_aval(void);
int is_sgx_aval(void);
int is_bmi1_aval(void);
int is_hle_aval(void);
int is_avx2_aval(void);
int is_smep_aval(void);
int is_bmi2_aval(void);
int is_erms_aval(void);
int is_invpcid_aval(void);
int is_rtm_aval(void);
int is_pqm_aval(void);
int is_mpx_aval(void);
int is_pqe_aval(void);
int is_avx512f_aval(void);
int is_avx512dq_aval(void);
int is_rdseed_aval(void);
int is_adx_aval(void);
int is_smap_aval(void);
int is_avx512ifma_aval(void);
int is_pcommit_aval(void);
int is_clflushopt_aval(void);
int is_clwb_aval(void);
int is_processor_trace_aval(void);
int is_avx512pf_aval(void);
int is_avx512er_aval(void);
int is_avx512cd_aval(void);
int is_sha_aval(void);
int is_avx512bw_aval(void);
int is_avx512vl_aval(void);
int is_prefetchwt1_aval(void);
int is_avx512vbmi_aval(void);
#endif
int is_bmi2_lib(void);
int is_avx_lib(void);
int is_avx2_lib(void);
int is_xop_lib(void);
/* GENERAL FUNCTIONS */
ullint in_place_zero(ullint num);
ullint asm_xor_ull(ullint num1, ullint num2);
#ifdef __BMI2__
ulint rdrnd(void);
#endif
#endif
void asm_nop(void);


#endif

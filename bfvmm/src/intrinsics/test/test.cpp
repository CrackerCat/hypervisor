//
// Bareflank Hypervisor
//
// Copyright (C) 2015 Assured Information Security, Inc.
// Author: Rian Quinn        <quinnr@ainfosec.com>
// Author: Brendan Kerrigan  <kerriganb@ainfosec.com>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#include <test.h>

intrinsics_ut::intrinsics_ut()
{
}

bool
intrinsics_ut::init()
{
    return true;
}

bool
intrinsics_ut::fini()
{
    return true;
}

bool
intrinsics_ut::list()
{
    this->test_gdt_reg_set_get();
    this->test_gdt_reg_base_set_get();
    this->test_gdt_reg_limit_set_get();
    this->test_gdt_constructor_no_size();
    this->test_gdt_constructor_zero_size();
    this->test_gdt_constructor_size();
    this->test_gdt_base();
    this->test_gdt_limit();
    this->test_gdt_set_base_zero_index();
    this->test_gdt_set_base_invalid_index();
    this->test_gdt_set_base_tss_at_end_of_gdt();
    this->test_gdt_set_base_descriptor_success();
    this->test_gdt_set_base_tss_success();
    this->test_gdt_base_zero_index();
    this->test_gdt_base_invalid_index();
    this->test_gdt_base_tss_at_end_of_gdt();
    this->test_gdt_base_descriptor_success();
    this->test_gdt_base_tss_success();
    this->test_gdt_set_limit_zero_index();
    this->test_gdt_set_limit_invalid_index();
    this->test_gdt_set_limit_descriptor_success();
    this->test_gdt_limit_zero_index();
    this->test_gdt_limit_invalid_index();
    this->test_gdt_limit_descriptor_success();
    this->test_gdt_limit_descriptor_in_bytes_success();
    this->test_gdt_set_access_rights_zero_index();
    this->test_gdt_set_access_rights_invalid_index();
    this->test_gdt_set_access_rights_descriptor_success();
    this->test_gdt_access_rights_zero_index();
    this->test_gdt_access_rights_invalid_index();
    this->test_gdt_access_rights_descriptor_success();

    this->test_idt_reg_set_get();
    this->test_idt_reg_base_set_get();
    this->test_idt_reg_limit_set_get();
    this->test_idt_constructor_no_size();
    this->test_idt_constructor_zero_size();
    this->test_idt_constructor_size();
    this->test_idt_base();
    this->test_idt_limit();

    this->test_general_msr_access();
    this->test_ia32_feature_control();
    this->test_ia32_feature_control_lock_bit();
    this->test_ia32_feature_control_enable_vmx_inside_smx();
    this->test_ia32_feature_control_enable_vmx_outside_smx();
    this->test_ia32_feature_control_senter_local_function_enables();
    this->test_ia32_feature_control_senter_gloabl_function_enable();
    this->test_ia32_feature_control_sgx_launch_control_enable();
    this->test_ia32_feature_control_sgx_global_enable();
    this->test_ia32_feature_control_lmce();
    this->test_ia32_sysenter_cs();
    this->test_ia32_sysenter_esp();
    this->test_ia32_sysenter_eip();
    this->test_ia32_debugctl();
    this->test_ia32_debugctl_lbr();
    this->test_ia32_debugctl_btf();
    this->test_ia32_debugctl_tr();
    this->test_ia32_debugctl_bts();
    this->test_ia32_debugctl_btint();
    this->test_ia32_debugctl_bt_off_os();
    this->test_ia32_debugctl_bt_off_user();
    this->test_ia32_debugctl_freeze_lbrs_on_pmi();
    this->test_ia32_debugctl_freeze_perfmon_on_pmi();
    this->test_ia32_debugctl_enable_uncore_pmi();
    this->test_ia32_debugctl_freeze_while_smm();
    this->test_ia32_debugctl_rtm_debug();
    this->test_ia32_debugctl_reserved();
    this->test_ia32_pat();
    this->test_ia32_pat_pa0();
    this->test_ia32_pat_pa1();
    this->test_ia32_pat_pa2();
    this->test_ia32_pat_pa3();
    this->test_ia32_pat_pa4();
    this->test_ia32_pat_pa5();
    this->test_ia32_pat_pa6();
    this->test_ia32_pat_pa7();
    this->test_ia32_perf_global_ctrl();
    this->test_ia32_perf_global_ctrl_pmc0();
    this->test_ia32_perf_global_ctrl_pmc1();
    this->test_ia32_perf_global_ctrl_pmc2();
    this->test_ia32_perf_global_ctrl_pmc3();
    this->test_ia32_perf_global_ctrl_pmc4();
    this->test_ia32_perf_global_ctrl_pmc5();
    this->test_ia32_perf_global_ctrl_pmc6();
    this->test_ia32_perf_global_ctrl_pmc7();
    this->test_ia32_perf_global_ctrl_fixed_ctr0();
    this->test_ia32_perf_global_ctrl_fixed_ctr1();
    this->test_ia32_perf_global_ctrl_fixed_ctr2();
    this->test_ia32_vmx_basic();
    this->test_ia32_vmx_basic_revision_id();
    this->test_ia32_vmx_basic_vmxon_vmcs_region_size();
    this->test_ia32_vmx_basic_physical_address_width();
    this->test_ia32_vmx_basic_dual_monitor_mode_support();
    this->test_ia32_vmx_basic_memory_type();
    this->test_ia32_vmx_basic_ins_outs_exit_information();
    this->test_ia32_vmx_basic_true_based_controls();
    this->test_ia32_vmx_misc();
    this->test_ia32_vmx_misc_preemption_timer_decrement();
    this->test_ia32_vmx_misc_store_efer_lma_on_vm_exit();
    this->test_ia32_vmx_misc_activity_state_hlt_support();
    this->test_ia32_vmx_misc_activity_state_shutdown_support();
    this->test_ia32_vmx_misc_activity_state_wait_for_sipi_support();
    this->test_ia32_vmx_misc_processor_trace_support();
    this->test_ia32_vmx_misc_rdmsr_in_smm_support();
    this->test_ia32_vmx_misc_cr3_targets();
    this->test_ia32_vmx_misc_max_num_msr_load_store_on_exit();
    this->test_ia32_vmx_misc_vmxoff_blocked_smi_support();
    this->test_ia32_vmx_misc_vmwrite_all_fields_support();
    this->test_ia32_vmx_misc_injection_with_instruction_length_of_zero();
    this->test_ia32_vmx_cr0_fixed0();
    this->test_ia32_vmx_cr0_fixed1();
    this->test_ia32_vmx_cr4_fixed0();
    this->test_ia32_vmx_cr4_fixed1();
    this->test_ia32_vmx_procbased_ctls2();
    this->test_ia32_vmx_procbased_ctls2_virtualize_apic_accesses();
    this->test_ia32_vmx_procbased_ctls2_enable_ept();
    this->test_ia32_vmx_procbased_ctls2_descriptor_table_exiting();
    this->test_ia32_vmx_procbased_ctls2_enable_rdtscp();
    this->test_ia32_vmx_procbased_ctls2_virtualize_x2apic_mode();
    this->test_ia32_vmx_procbased_ctls2_enable_vpid();
    this->test_ia32_vmx_procbased_ctls2_wbinvd_exiting();
    this->test_ia32_vmx_procbased_ctls2_unrestricted_guest();
    this->test_ia32_vmx_procbased_ctls2_apic_register_virtualization();
    this->test_ia32_vmx_procbased_ctls2_virtual_interrupt_delivery();
    this->test_ia32_vmx_procbased_ctls2_pause_loop_exiting();
    this->test_ia32_vmx_procbased_ctls2_rdrand_exiting();
    this->test_ia32_vmx_procbased_ctls2_enable_invpcid();
    this->test_ia32_vmx_procbased_ctls2_enable_vm_functions();
    this->test_ia32_vmx_procbased_ctls2_vmcs_shadowing();
    this->test_ia32_vmx_procbased_ctls2_rdseed_exiting();
    this->test_ia32_vmx_procbased_ctls2_enable_pml();
    this->test_ia32_vmx_procbased_ctls2_ept_violation_ve();
    this->test_ia32_vmx_procbased_ctls2_enable_xsaves_xrstors();
    this->test_ia32_vmx_ept_vpid_cap();
    this->test_ia32_vmx_ept_vpid_cap_execute_only_translation();
    this->test_ia32_vmx_ept_vpid_cap_page_walk_length_of_4();
    this->test_ia32_vmx_ept_vpid_cap_memory_type_uncacheable_supported();
    this->test_ia32_vmx_ept_vpid_cap_memory_type_write_back_supported();
    this->test_ia32_vmx_ept_vpid_cap_pde_2mb_support();
    this->test_ia32_vmx_ept_vpid_cap_pdpte_1mb_support();
    this->test_ia32_vmx_ept_vpid_cap_invept_support();
    this->test_ia32_vmx_ept_vpid_cap_accessed_dirty_support();
    this->test_ia32_vmx_ept_vpid_cap_invept_single_context_support();
    this->test_ia32_vmx_ept_vpid_cap_invept_all_context_support();
    this->test_ia32_vmx_ept_vpid_cap_invvpid_support();
    this->test_ia32_vmx_ept_vpid_cap_invvpid_individual_address_support();
    this->test_ia32_vmx_ept_vpid_cap_invvpid_single_context_support();
    this->test_ia32_vmx_ept_vpid_cap_invvpid_all_context_support();
    this->test_ia32_vmx_ept_vpid_cap_invvpid_single_context_retaining_globals_support();
    this->test_ia32_vmx_true_pinbased_ctls();
    this->test_ia32_vmx_true_pinbased_ctls_external_interrupt_exiting();
    this->test_ia32_vmx_true_pinbased_ctls_nmi_exiting();
    this->test_ia32_vmx_true_pinbased_ctls_virtual_nmis();
    this->test_ia32_vmx_true_pinbased_ctls_activate_vmx_preemption_timer();
    this->test_ia32_vmx_true_pinbased_ctls_process_posted_interrupts();
    this->test_ia32_vmx_true_procbased_ctls();
    this->test_ia32_vmx_true_procbased_ctls_interrupt_window_exiting();
    this->test_ia32_vmx_true_procbased_ctls_use_tsc_offsetting();
    this->test_ia32_vmx_true_procbased_ctls_hlt_exiting();
    this->test_ia32_vmx_true_procbased_ctls_invlpg_exiting();
    this->test_ia32_vmx_true_procbased_ctls_mwait_exiting();
    this->test_ia32_vmx_true_procbased_ctls_rdpmc_exiting();
    this->test_ia32_vmx_true_procbased_ctls_rdtsc_exiting();
    this->test_ia32_vmx_true_procbased_ctls_cr3_load_exiting();
    this->test_ia32_vmx_true_procbased_ctls_cr3_store_exiting();
    this->test_ia32_vmx_true_procbased_ctls_cr8_load_exiting();
    this->test_ia32_vmx_true_procbased_ctls_cr8_store_exiting();
    this->test_ia32_vmx_true_procbased_ctls_use_tpr_shadow();
    this->test_ia32_vmx_true_procbased_ctls_nmi_window_exiting();
    this->test_ia32_vmx_true_procbased_ctls_mov_dr_exiting();
    this->test_ia32_vmx_true_procbased_ctls_unconditional_io_exiting();
    this->test_ia32_vmx_true_procbased_ctls_use_io_bitmaps();
    this->test_ia32_vmx_true_procbased_ctls_monitor_trap_flag();
    this->test_ia32_vmx_true_procbased_ctls_use_msr_bitmaps();
    this->test_ia32_vmx_true_procbased_ctls_monitor_exiting();
    this->test_ia32_vmx_true_procbased_ctls_pause_exiting();
    this->test_ia32_vmx_true_procbased_ctls_activate_secondary_controls();
    this->test_ia32_vmx_true_exit_ctls();
    this->test_ia32_vmx_true_exit_ctls_save_debug_controls();
    this->test_ia32_vmx_true_exit_ctls_host_address_space_size();
    this->test_ia32_vmx_true_exit_ctls_load_ia32_perf_global_ctrl();
    this->test_ia32_vmx_true_exit_ctls_acknowledge_interrupt_on_exit();
    this->test_ia32_vmx_true_exit_ctls_save_ia32_pat();
    this->test_ia32_vmx_true_exit_ctls_load_ia32_pat();
    this->test_ia32_vmx_true_exit_ctls_save_ia32_efer();
    this->test_ia32_vmx_true_exit_ctls_load_ia32_efer();
    this->test_ia32_vmx_true_exit_ctls_save_vmx_preemption_timer_value();
    this->test_ia32_vmx_true_entry_ctls();
    this->test_ia32_vmx_true_entry_ctls_load_debug_controls();
    this->test_ia32_vmx_true_entry_ctls_ia_32e_mode_guest();
    this->test_ia32_vmx_true_entry_ctls_entry_to_smm();
    this->test_ia32_vmx_true_entry_ctls_deactivate_dual_monitor_treatment();
    this->test_ia32_vmx_true_entry_ctls_load_ia32_perf_global_ctrl();
    this->test_ia32_vmx_true_entry_ctls_load_ia32_pat();
    this->test_ia32_vmx_true_entry_ctls_load_ia32_efer();
    this->test_ia32_vmx_vmfunc();
    this->test_ia32_efer();
    this->test_ia32_efer_sce();
    this->test_ia32_efer_lme();
    this->test_ia32_efer_lma();
    this->test_ia32_efer_nxe();
    this->test_ia32_efer_reserved();
    this->test_ia32_fs_base();
    this->test_ia32_gs_base();

    this->test_rflags_x64();
    this->test_rflags_x64_carry_flag();
    this->test_rflags_x64_parity_flag();
    this->test_rflags_x64_auxiliary_carry_flag();
    this->test_rflags_x64_zero_flag();
    this->test_rflags_x64_sign_flag();
    this->test_rflags_x64_trap_flag();
    this->test_rflags_x64_interrupt_enable_flag();
    this->test_rflags_x64_direction_flag();
    this->test_rflags_x64_overflow_flag();
    this->test_rflags_x64_privilege_level();
    this->test_rflags_x64_nested_task();
    this->test_rflags_x64_resume_flag();
    this->test_rflags_x64_virtual_8086_mode();
    this->test_rflags_x64_alignment_check_access_control();
    this->test_rflags_x64_virtual_interupt_flag();
    this->test_rflags_x64_virtual_interupt_pending();
    this->test_rflags_x64_id_flag();
    this->test_rflags_x64_reserved();
    this->test_rflags_x64_always_disabled();
    this->test_rflags_x64_always_enabled();

    this->test_cr0_intel_x64();
    this->test_cr0_intel_x64_protection_enable();
    this->test_cr0_intel_x64_monitor_coprocessor();
    this->test_cr0_intel_x64_emulation();
    this->test_cr0_intel_x64_task_switched();
    this->test_cr0_intel_x64_extension_type();
    this->test_cr0_intel_x64_numeric_error();
    this->test_cr0_intel_x64_write_protect();
    this->test_cr0_intel_x64_alignment_mask();
    this->test_cr0_intel_x64_not_write_through();
    this->test_cr0_intel_x64_cache_disable();
    this->test_cr0_intel_x64_paging();
    this->test_cr3_intel_x64();
    this->test_cr4_intel_x64();
    this->test_cr4_intel_x64_v8086_mode_extensions();
    this->test_cr4_intel_x64_protected_mode_virtual_interrupts();
    this->test_cr4_intel_x64_time_stamp_disable();
    this->test_cr4_intel_x64_debugging_extensions();
    this->test_cr4_intel_x64_page_size_extensions();
    this->test_cr4_intel_x64_physical_address_extensions();
    this->test_cr4_intel_x64_machine_check_enable();
    this->test_cr4_intel_x64_page_global_enable();
    this->test_cr4_intel_x64_performance_monitor_counter_enable();
    this->test_cr4_intel_x64_osfxsr();
    this->test_cr4_intel_x64_osxmmexcpt();
    this->test_cr4_intel_x64_vmx_enable_bit();
    this->test_cr4_intel_x64_smx_enable_bit();
    this->test_cr4_intel_x64_fsgsbase_enable_bit();
    this->test_cr4_intel_x64_pcid_enable_bit();
    this->test_cr4_intel_x64_osxsave();
    this->test_cr4_intel_x64_smep_enable_bit();
    this->test_cr4_intel_x64_smap_enable_bit();
    this->test_cr4_intel_x64_protection_key_enable_bit();

    this->test_srs_x64_es();
    this->test_srs_x64_es_rpl();
    this->test_srs_x64_es_ti();
    this->test_srs_x64_es_index();
    this->test_srs_x64_cs();
    this->test_srs_x64_cs_rpl();
    this->test_srs_x64_cs_ti();
    this->test_srs_x64_cs_index();
    this->test_srs_x64_ss();
    this->test_srs_x64_ss_rpl();
    this->test_srs_x64_ss_ti();
    this->test_srs_x64_ss_index();
    this->test_srs_x64_ds();
    this->test_srs_x64_ds_rpl();
    this->test_srs_x64_ds_ti();
    this->test_srs_x64_ds_index();
    this->test_srs_x64_fs();
    this->test_srs_x64_fs_rpl();
    this->test_srs_x64_fs_ti();
    this->test_srs_x64_fs_index();
    this->test_srs_x64_gs();
    this->test_srs_x64_gs_rpl();
    this->test_srs_x64_gs_ti();
    this->test_srs_x64_gs_index();
    this->test_srs_x64_ldtr();
    this->test_srs_x64_ldtr_rpl();
    this->test_srs_x64_ldtr_ti();
    this->test_srs_x64_ldtr_index();
    this->test_srs_x64_tr();
    this->test_srs_x64_tr_rpl();
    this->test_srs_x64_tr_ti();
    this->test_srs_x64_tr_index();

    this->test_portio_x64_byte();
    this->test_portio_x64_word();

    this->test_vmx_intel_x64_vmxon_nullptr();
    this->test_vmx_intel_x64_vmxon_failure();
    this->test_vmx_intel_x64_vmxon_success();
    this->test_vmx_intel_x64_vmxoff_failure();
    this->test_vmx_intel_x64_vmxoff_success();
    this->test_vmx_intel_x64_vmclear_nullptr();
    this->test_vmx_intel_x64_vmclear_failure();
    this->test_vmx_intel_x64_vmclear_success();
    this->test_vmx_intel_x64_vmload_nullptr();
    this->test_vmx_intel_x64_vmload_failure();
    this->test_vmx_intel_x64_vmload_success();
    this->test_vmx_intel_x64_vmreset_nullptr();
    this->test_vmx_intel_x64_vmreset_failure();
    this->test_vmx_intel_x64_vmreset_success();
    this->test_vmx_intel_x64_vmread_failure();
    this->test_vmx_intel_x64_vmwrite_failure();
    this->test_vmx_intel_x64_vmread_vmwrite_succcess();
    this->test_vmx_intel_x64_vmlaunch_failure();
    this->test_vmx_intel_x64_vmlaunch_success();

    this->test_cpuid_x64_cpuid();
    this->test_cpuid_x64_cpuid_eax();
    this->test_cpuid_x64_cpuid_ebx();
    this->test_cpuid_x64_cpuid_ecx();
    this->test_cpuid_x64_cpuid_edx();
    this->test_cpuid_x64_cpuid_addr_size_phys();
    this->test_cpuid_x64_cpuid_addr_size_linear();
    this->test_cpuid_x64_cpuid_feature_information_ecx_sse3();
    this->test_cpuid_x64_cpuid_feature_information_ecx_pclmulqdq();
    this->test_cpuid_x64_cpuid_feature_information_ecx_dtes64();
    this->test_cpuid_x64_cpuid_feature_information_ecx_monitor();
    this->test_cpuid_x64_cpuid_feature_information_ecx_ds_cpl();
    this->test_cpuid_x64_cpuid_feature_information_ecx_vmx();
    this->test_cpuid_x64_cpuid_feature_information_ecx_smx();
    this->test_cpuid_x64_cpuid_feature_information_ecx_eist();
    this->test_cpuid_x64_cpuid_feature_information_ecx_tm2();
    this->test_cpuid_x64_cpuid_feature_information_ecx_ssse3();
    this->test_cpuid_x64_cpuid_feature_information_ecx_cnxt_id();
    this->test_cpuid_x64_cpuid_feature_information_ecx_sdbg();
    this->test_cpuid_x64_cpuid_feature_information_ecx_fma();
    this->test_cpuid_x64_cpuid_feature_information_ecx_cmpxchg16b();
    this->test_cpuid_x64_cpuid_feature_information_ecx_xtpr_update_control();
    this->test_cpuid_x64_cpuid_feature_information_ecx_pdcm();
    this->test_cpuid_x64_cpuid_feature_information_ecx_pcid();
    this->test_cpuid_x64_cpuid_feature_information_ecx_dca();
    this->test_cpuid_x64_cpuid_feature_information_ecx_sse41();
    this->test_cpuid_x64_cpuid_feature_information_ecx_sse42();
    this->test_cpuid_x64_cpuid_feature_information_ecx_x2apic();
    this->test_cpuid_x64_cpuid_feature_information_ecx_movbe();
    this->test_cpuid_x64_cpuid_feature_information_ecx_popcnt();
    this->test_cpuid_x64_cpuid_feature_information_ecx_tsc_deadline();
    this->test_cpuid_x64_cpuid_feature_information_ecx_aesni();
    this->test_cpuid_x64_cpuid_feature_information_ecx_xsave();
    this->test_cpuid_x64_cpuid_feature_information_ecx_osxsave();
    this->test_cpuid_x64_cpuid_feature_information_ecx_avx();
    this->test_cpuid_x64_cpuid_feature_information_ecx_f16c();
    this->test_cpuid_x64_cpuid_feature_information_ecx_rdrand();

    this->test_pm_x64_halt();
    this->test_pm_x64_stop();

    this->test_cache_x64_invd();
    this->test_cache_x64_wbinvd();

    this->test_debug_x64_dr7();

    return true;
}

int
main(int argc, char *argv[])
{
    return RUN_ALL_TESTS(intrinsics_ut);
}

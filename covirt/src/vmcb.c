#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/io.h>

#include "reg_utils.h"
#include "vmcb.h"

extern void * __global_Host_Reg_Store; 
extern void * __global_Guest_Reg_Store;
extern void * __global_VMCB_VA;
extern phys_addr_t __global_VMCB_PA;
// extern phys_addr_t __global_VM_HSAVE_PA;

// #include "vmcb.h"

/*
	VMRUN will pull the info from the VMCB to initialize the guest with.
	We are simply putting our desired values in here.
	Note: This is slightly different from a regular VMM, as this state isn't
	going to be the default "just booted" state. This will essentially be
	the state of our currently running host.
*/
static void store_guest_cpu_info(vmcb_t * vmcb, uint64_t rip, uint64_t rsp, uint64_t rax, uint64_t rflags){
	// rip, rsp, rflags, rax are going to be provided as the VMCB will load them
	// rflags and the other general purpose registers will be saved and restored separately
	
	desc_ptr idtr;
	desc_ptr gdtr;

	// Store CS, RIP [Done]
	vmcb->state_save_area.cs.selector = get_cs();
	vmcb->state_save_area.rip = rip;  // RIP

	// Store RFLAGS, RAX [Done]
	vmcb->state_save_area.rflags = rflags;  // RFLAGS
	vmcb->state_save_area.rax = rax;	// RAX

	// Store SS, RSP [Done]
	vmcb->state_save_area.ss.selector = get_ss();
	vmcb->state_save_area.rsp = rsp;	// RSP

	// Store CR0, CR2, CR3, CR4, EFER [Done]
	vmcb->state_save_area.cr0 = get_cr0();
	vmcb->state_save_area.cr2 = get_cr2();
	vmcb->state_save_area.cr3 = get_cr3();
	vmcb->state_save_area.cr4 = get_cr4();
	vmcb->state_save_area.efer = read_msr(EFER_MSR);
	 
	// Store INTERRUPT_SHADOW
	
	vmcb->control_area.gisw.interrupt_shadow = 0;  // If I don't know what an interrupt shadow is.. it must not be important O_O

	// Store IDTR, GDTR [Done]
	idtr = get_idtr();
	vmcb->state_save_area.idtr.base = idtr.base;
	vmcb->state_save_area.idtr.limit = idtr.limit;

	gdtr = get_gdtr();
	vmcb->state_save_area.gdtr.base = gdtr.base;
	vmcb->state_save_area.gdtr.limit = gdtr.limit;

	// Store ES and DS [Not fully done, we'll need to modify the get_es and get_ds functions]

	vmcb->state_save_area.es.selector = get_es();
	vmcb->state_save_area.ds.selector = get_ds();
	
	// Store DR6 and DR7 [Done]
	vmcb->state_save_area.dr6 = get_dr6();
	vmcb->state_save_area.dr7 = get_dr7();

	// Store V_TPR (task priority register (cr8)) [Done]

	vmcb->control_area.guest_int_ctrl.V_TPR = get_vtpr();

	// Store V_IRQ (Is the virual guest pending IRQ) [Done]

	vmcb->control_area.guest_int_ctrl.V_IRQ = 0;  // For now

	// Store CPL [Done]

	vmcb->state_save_area.cpl = 0;  // Have it run in kernel mode as usual.

	// Setup the guest ASID (can't be 0)
	vmcb->control_area.guest_asid = 1;
}

/*
	This is our wrapper for all VMCB operations.
		- For some reason (that reason being my poor planning) we're also setting the VM_HSAVE_PA MSR from here
		- Allocate and initialize the VMCB state-save
		- Initialize the VMCB Control Area too
*/
phys_addr_t vmcb_init(uint64_t rip, uint64_t rsp, uint64_t rax, uint64_t rflags) {
	// Does this need to be "volatile void *"?
    vmcb_t * vmcb_ptr;
	phys_addr_t phys_vmcb_ptr;

	// Allocate VMCB Region
	vmcb_ptr = (vmcb_t *)kzalloc(VMCB_SIZE, GFP_KERNEL);
	if (!vmcb_ptr){
		printk("Failed to allocate VMCB\n");
		return -1;
	}
	
	printk("VMCB allocated at %px\n", vmcb_ptr);
	store_guest_cpu_info(vmcb_ptr, rip, rsp, rax, rflags);
    // kzfree((const void *) vmcb_ptr);
    phys_vmcb_ptr = virt_to_phys((void *) vmcb_ptr);

	printk("Physical VMCB %llx\n", phys_vmcb_ptr);
	__global_VMCB_VA = (void *) vmcb_ptr; 
	__global_VMCB_PA = phys_vmcb_ptr;

	debug_vmcb(__global_VMCB_VA);
	//*((int64_t *)vmcb_ptr + 14) = 0;
	// printk("INIT EC: %lld\n", *((int64_t *)vmcb_ptr + 14));
	// printk("Exit Code location: %px\n", &(vmcb_ptr->control_area.EXIT_CODE));
	// printk("DR Writes location: %px\n", &(vmcb_ptr->control_area.dr_writes));
	return phys_vmcb_ptr;
}

void handle_vmexit(void){
	// vmcb_t * vmcb = (vmcb_t *) __global_VMCB_VA;
	// printk("EXIT CODE: %lld\n", *((int64_t *)vmcb + 14));
	// printk("EXIT INFO1: %llx\n", vmcb->control_area.EXIT_INFO1);
	// printk("EXIT INFO2: %llx\n", vmcb->control_area.EXIT_INFO2);
	// printk("EXIT INT INFO: %llx\n", vmcb->control_area.EXIT_INT_INFO);
	return;	
}

void debug_vmcb(vmcb_t * vmcb){
	int ssa_offset = 0x400;

	printk("----- BEGIN VMCB DEBUG OUTPUT -----\n");
	printk("VMCB Virt Addr: %px\n", vmcb);
	printk("VMCB Phys Addr: %llx\n", virt_to_phys(vmcb));
	// WARNING: I don't actually look inside of the structs of each of these just yet.
	// This means that the offsets within certain structs could still be wrong.
	// In other words, these checks are not exhaustive.
	check_entry_offset(0x000, (uint64_t) &vmcb->control_area.cr_reads, "CR READS");
	check_entry_offset(0x004, (uint64_t) &vmcb->control_area.dr_reads, "DR READS");
	check_entry_offset(0x008, (uint64_t) &vmcb->control_area.exception_vectors, "Exception Vectors");
	check_entry_offset(0x00C, (uint64_t) &vmcb->control_area.instr_intercepts, "Instr Intercepts");
	check_entry_offset(0x010, (uint64_t) &vmcb->control_area.svm_instr_intercepts, "SVM Instr Intercepts");
	check_entry_offset(0x014, (uint64_t) &vmcb->control_area.mm_instr_intercepts, "MM Instr Intercepts");
	check_entry_offset(0x018, (uint64_t) &vmcb->control_area.rsvd0, "RSVD0");
	check_entry_offset(0x03C, (uint64_t) &vmcb->control_area.pause_filter_threshold, "Pause filter thresh");
	check_entry_offset(0x03E, (uint64_t) &vmcb->control_area.pause_filter_count, "Pause filter count");
	check_entry_offset(0x040, (uint64_t) &vmcb->control_area.IOPM_BASE_PA, "IOPM_BASE_PA");
	check_entry_offset(0x048, (uint64_t) &vmcb->control_area.MSRPM_BASE_PA, "MSRPM_BASE_PA");
	check_entry_offset(0x050, (uint64_t) &vmcb->control_area.TSC_OFFSET, "TSC_OFFSET");

	check_entry_offset(0x058, (uint64_t) &vmcb->control_area.guest_asid, "guest_asid");
	check_entry_offset(0x05C, (uint64_t) &vmcb->control_area.TLB_CONTROL, "TLB_CONTROL");
	
	check_entry_offset(0x060, (uint64_t) &vmcb->control_area.guest_int_ctrl, "guest_int_ctrl");

	// Made a random struct here for reasons [gisw]
	check_entry_offset(0x068, (uint64_t) &vmcb->control_area.gisw, "gisw");

	check_entry_offset(0x070, (uint64_t) &vmcb->control_area.EXIT_CODE, "EXIT_CODE");
	check_entry_offset(0x078, (uint64_t) &vmcb->control_area.EXIT_INFO1, "EXIT_INFO1");
	check_entry_offset(0x080, (uint64_t) &vmcb->control_area.EXIT_INFO2, "EXIT_INFO2");
	check_entry_offset(0x088, (uint64_t) &vmcb->control_area.EXIT_INT_INFO, "EXITINTINFO");

	// Made a random struct here for reasons [misc_enable]
	check_entry_offset(0x090, (uint64_t) &vmcb->control_area.misc_enable, "misc_enable");

	check_entry_offset(0x098, (uint64_t) &vmcb->control_area.avic_apic_bar, "avic_apic_bar");
	check_entry_offset(0x0A0, (uint64_t) &vmcb->control_area.GHCB_PA, "GHCB_PA");

	check_entry_offset(0x0A8, (uint64_t) &vmcb->control_area.EVENTINJ, "EVENTINJ");
	check_entry_offset(0x0B0, (uint64_t) &vmcb->control_area.N_CR3, "N_CR3");

	// Made a random struct here for reasons [more_ves]
	check_entry_offset(0x0B8, (uint64_t) &vmcb->control_area.more_ves, "more_ves");

	check_entry_offset(0x0C0, (uint64_t) &vmcb->control_area.clean_bits, "clean_bits");

	check_entry_offset(0x0C8, (uint64_t) &vmcb->control_area.nRIP, "nRIP");

	// Made a random struct here for reasons [instr_fetch_info]
	check_entry_offset(0x0D0, (uint64_t) &vmcb->control_area.instr_fetch_info, "instr_fetch_info");

	check_entry_offset(0x0E0, (uint64_t) &vmcb->control_area.apic_info, "apic_info");
	
	check_entry_offset(0x0F0, (uint64_t) &vmcb->control_area.avic_log_info, "avic_log_info");

	check_entry_offset(0x0F8, (uint64_t) &vmcb->control_area.avic_phys_info, "avic_phys_info");

	check_entry_offset(0x108, (uint64_t) &vmcb->control_area.vmsa_info, "vmsa_info");

	printk("Control area kinda done checking... \n");

	check_entry_offset(ssa_offset + 0x000, (uint64_t) &vmcb->state_save_area.es, "es");
	check_entry_offset(ssa_offset + 0x010, (uint64_t) &vmcb->state_save_area.cs, "cs");
	check_entry_offset(ssa_offset + 0x020, (uint64_t) &vmcb->state_save_area.ss, "ss");
	check_entry_offset(ssa_offset + 0x030, (uint64_t) &vmcb->state_save_area.ds, "ds");
	check_entry_offset(ssa_offset + 0x040, (uint64_t) &vmcb->state_save_area.fs, "fs");
	check_entry_offset(ssa_offset + 0x050, (uint64_t) &vmcb->state_save_area.gs, "gs");
	check_entry_offset(ssa_offset + 0x060, (uint64_t) &vmcb->state_save_area.gdtr, "gdtr");
	check_entry_offset(ssa_offset + 0x070, (uint64_t) &vmcb->state_save_area.ldtr, "ldtr");
	check_entry_offset(ssa_offset + 0x080, (uint64_t) &vmcb->state_save_area.idtr, "idtr");
	check_entry_offset(ssa_offset + 0x090, (uint64_t) &vmcb->state_save_area.tr, "tr");

	check_entry_offset(ssa_offset + 0x0CB, (uint64_t) &vmcb->state_save_area.cpl, "cpl");

	check_entry_offset(ssa_offset + 0x0D0, (uint64_t) &vmcb->state_save_area.efer, "efer");

	check_entry_offset(ssa_offset + 0x148, (uint64_t) &vmcb->state_save_area.cr4, "cr4");
	check_entry_offset(ssa_offset + 0x150, (uint64_t) &vmcb->state_save_area.cr3, "cr3");
	check_entry_offset(ssa_offset + 0x158, (uint64_t) &vmcb->state_save_area.cr0, "cr0");
	check_entry_offset(ssa_offset + 0x160, (uint64_t) &vmcb->state_save_area.dr7, "dr7");
	check_entry_offset(ssa_offset + 0x168, (uint64_t) &vmcb->state_save_area.dr6, "dr6");
	check_entry_offset(ssa_offset + 0x170, (uint64_t) &vmcb->state_save_area.rflags, "rflags");
	check_entry_offset(ssa_offset + 0x178, (uint64_t) &vmcb->state_save_area.rip, "rip");

	check_entry_offset(ssa_offset + 0x1D8, (uint64_t) &vmcb->state_save_area.rsp, "rsp");
	check_entry_offset(ssa_offset + 0x1E0, (uint64_t) &vmcb->state_save_area.s_cet, "s_cet");
	check_entry_offset(ssa_offset + 0x1E8, (uint64_t) &vmcb->state_save_area.ssp, "ssp");
	check_entry_offset(ssa_offset + 0x1F0, (uint64_t) &vmcb->state_save_area.isst_addr, "isst_addr");
	check_entry_offset(ssa_offset + 0x1F8, (uint64_t) &vmcb->state_save_area.rax, "rax");
	check_entry_offset(ssa_offset + 0x200, (uint64_t) &vmcb->state_save_area.star, "star");
	check_entry_offset(ssa_offset + 0x208, (uint64_t) &vmcb->state_save_area.lstar, "lstar");
	check_entry_offset(ssa_offset + 0x210, (uint64_t) &vmcb->state_save_area.cstar, "cstar");
	check_entry_offset(ssa_offset + 0x218, (uint64_t) &vmcb->state_save_area.sfmask, "sfmask");
	check_entry_offset(ssa_offset + 0x220, (uint64_t) &vmcb->state_save_area.kernel_gs_base, "kernel_gs_base");
	check_entry_offset(ssa_offset + 0x228, (uint64_t) &vmcb->state_save_area.sysenter_cs, "sysenter_cs");
	check_entry_offset(ssa_offset + 0x230, (uint64_t) &vmcb->state_save_area.sysenter_esp, "sysenter_esp");
	check_entry_offset(ssa_offset + 0x238, (uint64_t) &vmcb->state_save_area.sysenter_eip, "sysenter_eip");
	check_entry_offset(ssa_offset + 0x240, (uint64_t) &vmcb->state_save_area.cr2, "cr2");

	check_entry_offset(ssa_offset + 0x268, (uint64_t) &vmcb->state_save_area.g_pat, "g_pat");
	check_entry_offset(ssa_offset + 0x270, (uint64_t) &vmcb->state_save_area.dbgctl, "dbgctl");
	check_entry_offset(ssa_offset + 0x278, (uint64_t) &vmcb->state_save_area.br_from, "br_from");
	check_entry_offset(ssa_offset + 0x280, (uint64_t) &vmcb->state_save_area.br_to, "br_to");
	check_entry_offset(ssa_offset + 0x288, (uint64_t) &vmcb->state_save_area.last_excp_from, "last_excp_from");

	check_entry_offset(ssa_offset + 0x2E0, (uint64_t) &vmcb->state_save_area.spec_ctrl, "spec_ctrl");

	printk("State-save area kinda done checking... \n");

	printk("----- END VMCB DEBUG OUTPUT -----\n");
}

// A helper we'll use for checking that our VMCB struct is accurate.
void check_entry_offset(uint16_t offset, uint64_t e_ptr, char * name){
	// The VMCB is only like 4KB (0x1000) wide. Offsets shouldn't be going past this. 
	if ((e_ptr & 0xfff) != offset){
		printk("VMCB_T INCORRECT. %s is at offset 0x%x, should be at 0x%x\n", name, (uint16_t)(e_ptr & 0xfff), offset);
	}
	return;
}

#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/io.h>

#include "reg_utils.h"
#include "vmcb.h"

/*
	VMRUN will pull the info from the VMCB to initialize the guest with.
	We are simply putting our desired values in here.
	Note: This is slightly different from a regular VMM, as this state isn't
	going to be the default "just booted" state. This will essentially be
	the state of our currently running host.
*/
static void store_guest_cpu_info(vmcb_t * vmcb){
	desc_ptr idtr;
	desc_ptr gdtr;

	// Store CS, RIP

	// Store RFLAGS, RAX

	// Store SS, RSP

	// Store CR0, CR2, CR3, CR4, EFER [Done]
	vmcb->state_save_area.cr0 = get_cr0();
	vmcb->state_save_area.cr3 = get_cr3();
	vmcb->state_save_area.cr4 = get_cr4();
	vmcb->state_save_area.efer = read_msr(EFER_MSR);
	// Store INTERRUPT_SHADOW
	
	// Store IDTR, GDTR [Done]
	idtr = get_idtr();
	vmcb->state_save_area.idtr.base = idtr.base;
	vmcb->state_save_area.idtr.limit = idtr.limit;

	gdtr = get_gdtr();
	vmcb->state_save_area.gdtr.base = gdtr.base;
	vmcb->state_save_area.gdtr.limit = gdtr.limit;

	// Store ES and DS

	// Store DR6 and DR7

	// Store V_TPR

	// Store V_IRQ

	// Store CPL

}

/*
	This is our wrapper for all VMCB operations.
		- For some reason (that reason being my poor planning) we're also setting the VM_HSAVE_PA MSR from here
		- Allocate and initialize the VMCB state-save
		- Initialize the VMCB Control Area too
*/
phys_addr_t vmcb_init() {
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
    // kzfree((const void *) vmcb_ptr);
    phys_vmcb_ptr = virt_to_phys((void *) vmcb_ptr);
	return phys_vmcb_ptr;
}
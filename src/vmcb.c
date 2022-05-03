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
	vmcb->state_save_area.cs = get_cs();

	// Store RFLAGS, RAX

	// Store SS, RSP
	vmcb->state_save_area.ss = get_ss();

	// Store CR0, CR2, CR3, CR4, EFER [Done]
	vmcb->state_save_area.cr0 = get_cr0();
	vmcb->state_save_area.cr2 = get_cr2();
	vmcb->state_save_area.cr3 = get_cr3();
	vmcb->state_save_area.cr4 = get_cr4();
	vmcb->state_save_area.efer = read_msr(EFER_MSR);
	 
	// Store INTERRUPT_SHADOW
	
	vmcb->control_area.interrupt_shadow = 0;  // If I don't know what an interrupt shadow is.. it must not be important O_O

	// Store IDTR, GDTR [Done]
	idtr = get_idtr();
	vmcb->state_save_area.idtr.base = idtr.base;
	vmcb->state_save_area.idtr.limit = idtr.limit;

	gdtr = get_gdtr();
	vmcb->state_save_area.gdtr.base = gdtr.base;
	vmcb->state_save_area.gdtr.limit = gdtr.limit;

	// Store ES and DS [Not fully done, we'll need to modify the get_es and get_ds functions]

	vmcb->state_save_area.es = get_es();
	vmcb->state_save_area.ds = get_ds();
	
	// Store DR6 and DR7 [Done]
	vmcb->state_save_area.dr6 = get_dr6();
	vmcb->state_save_area.dr7 = get_dr7();

	// Store V_TPR (task priority register (cr8)) [Done]

	vmcb->control_area.guest_int_ctrl.V_TPR = get_vtpr();

	// Store V_IRQ (Is the virual guest pending IRQ) [Done]

	vmcb->control_area.guest_int_ctrl.V_IRQ = 0;  // For now

	// Store CPL [Done]

	vmcb->state_save_area.cpl = 0;  // Have it run in kernel mode as usual.

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


void debug_vmcb(vmcb_t * vmcb){
	printk("----- BEGIN VMCB DEBUG OUTPUT -----\n");
	printk("VMCB Virt Addr: %px\n", vmcb);
	printk("VMCB Phys Addr: %llx\n", virt_to_phys(vmcb));
	printk("----- END VMCB DEBUG OUTPUT -----\n");
}

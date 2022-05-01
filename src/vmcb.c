#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/io.h>

#include "svmrun.h"
#include "reg_utils.h"
#include "svm_utils.h"
#include "vmcb.h"

static void vm_hsave_pa_init(void){
	void * vm_hsave_va;
	phys_addr_t vm_hsave_pa;
	uint32_t hi;
	uint32_t lo;
	
	// Allocate VM_HSAVE_PA MSR (C001_0117)
	vm_hsave_va = kzalloc(0x1000, GFP_KERNEL);
	vm_hsave_pa = virt_to_phys(vm_hsave_va);
	hi = vm_hsave_pa & UPPER_4;
	lo = vm_hsave_pa & LOWER_4;
	write_msr(VM_HSAVE_PA_MSR, hi, lo);
}

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
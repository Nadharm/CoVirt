#include <linux/kernel.h>
#include <linux/slab.h>

#include "svmrun.h"

#define VMCB_ALIGN 0x1000  // 4KB aligned
#define VMCB_SIZE 0x400  // 1024 Bytes


// Reference: [AMD V2 15.5.1]

// At this point, we assume running at CPL 0 & EFER.SVME == 1

// VMRUN takes VMCB (physical address loaded into RAX)

// VMCB: 4KB-aligned page. Contains:
// • a list of instructions or events in the guest (e.g., write to CR3) to intercept,
// • various control bits that specify the execution environment of the guest or that indicate special
//   actions to be taken before running guest code, and
// • guest processor state (such as control registers, etc.)

// VMRUN stores host processor state information in the host state-save area
//  - AMD DOCs specify the saved host state
//  - VM_HSAVE_PA MSR: Specifies the physical address in main memory where the state-save area is.
// VMRUN loads guest state from VMCB state-save area
//  - AMD DOCs specify the loaded guest state
// VMRUN reads additional control bits from the VMCB (guest TLB flushing, injecting virtual int, etc.)
// VMRUN checks the guest state (if illegal: exit to host)

/*
static void vmcb_constructor(void * vmcb_ptr){
    // for now we do nothing...
    printk("CONSTRUCTOR: VMCB Address %px\n", vmcb_ptr);
}

// This is a buggy version. Some notes:
// kmem_cache_create will create multiple allocations, not just one.
int vmrun(void){
    struct kmem_cache * vmcb_aligned_cache;
    void * vmcb_ptr;

    vmcb_aligned_cache = kmem_cache_create("vmcb_aligned_cache", VMCB_SIZE, VMCB_ALIGN, GFP_KERNEL, vmcb_constructor);
    if (!vmcb_aligned_cache){
		printk("FAILED TO ALLOCATE VMCB\n");
		return 1;
	}
	vmcb_ptr = kmem_cache_alloc(vmcb_aligned_cache, KM_NOSLEEP);
    printk("VMCB Address %px\n", vmcb_ptr);
    return 0;
}
*/

int vmrun(void){
	void * vmcb_ptr;
	// I don't know if we'll want GFP_KERNEL here.
	// Also, because this is a power of 2-sized block, kzalloc gives us the natural 4kb-alignment by default.
	vmcb_ptr = kzalloc(VMCB_SIZE, GFP_KERNEL);
	if (!vmcb_ptr){
		printk("Failed to allocate VMCB\n");
		return -1;
	}
	printk("VMCB allocated at %px\n", vmcb_ptr);
	// kzfree((const void *) vmcb_ptr);
	return 0;
}

#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/io.h>

#include "svmrun.h"
#include "msr_ops.h"
#include "vmcb.h"

#define VMCB_ALIGN 0x1000  // 4KB aligned
#define VMCB_SIZE 0x1000  // 1024 Bytes
#define EFER_MSR 0xC0000080 // Address of EFER MSR
#define VM_HSAVE_PA_MSR	0xC0010117 // The PA of host state save goes here
#define SVME 1 << 12

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
// VMRUN checks the guest state (if illegal: exit to host

int vmrun(void){
	// Does this need to be "volatile void *"?
	void * vm_hsave_va;
	phys_addr_t vm_hsave_pa;
    vmcb_t * vmcb_ptr;
	phys_addr_t phys_vmcb_ptr;
	uint64_t cur_efer;
	uint64_t new_efer;
	uint32_t hi;
	uint32_t lo;

	// Set EFER.SVME to 1 
	cur_efer = read_msr(EFER_MSR);
	printk("Current EFER = %016llx\n", cur_efer);
	new_efer = cur_efer | SVME;
	hi = new_efer & 0xFFFFFFFF00000000;
	lo = new_efer & 0x00000000FFFFFFFF;
	write_msr(EFER_MSR, hi, lo);
	printk("New EFER = %016llx\n", new_efer);
	
	cur_efer = read_msr(EFER_MSR);
	printk("Current EFER = %016llx\n", cur_efer);
	if (cur_efer & SVME){
		printk("EFER.SVME modification SUCCESS!\n");
	} else {
		printk("EFER.SVME modification FAILED\n");
		return -1;
	}

	// Allocate VM_HSAVE_PA MSR (C001_0117)
	vm_hsave_va = kzalloc(0x1000, GFP_KERNEL);
	vm_hsave_pa = virt_to_phys(vm_hsave_va);
	hi = vm_hsave_pa & UPPER_4;
	lo = vm_hsave_pa & LOWER_4;
	write_msr(VM_HSAVE_PA_MSR, hi, lo);

	// Allocate VMCB Region
	vmcb_ptr = (vmcb_t *)kzalloc(VMCB_SIZE, GFP_KERNEL);
	if (!vmcb_ptr){
		printk("Failed to allocate VMCB\n");
		return -1;
	}

	printk("VMCB allocated at %px\n", vmcb_ptr);
    // kzfree((const void *) vmcb_ptr);
    phys_vmcb_ptr = virt_to_phys((void *) vmcb_ptr);

    //__asm__ __volatile__ ("VMRUN" : : "a"(phys_vmcb_ptr));

	return 0;
}

#include <linux/kernel.h>
#include <linux/cpumask.h>

#include "vmcb.h"
#include "svm_utils.h"

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

	// We'll need to setup the VMCB for every single CPU. Maybe we'll start with a single core CPU.
	// for_each_cpu(cpu, mask){
		// init_vm_hsave_pa();
		phys_addr_t phys_vmcb_ptr = vmcb_init();
	//	__asm__ __volatile__ ("VMRUN" : : "a"(phys_vmcb_ptr));

	// We'll need a loop here, right? Handing the VMExits over to a handler.
	// }
	return 0;
}

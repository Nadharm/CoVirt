#include <linux/kernel.h>
#include <linux/cpumask.h>

#include "vmcb.h"
#include "svm_utils.h"
#include "constants.h"
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

phys_addr_t phys_vmcb_ptr;

int vm_setup(void){

	// We'll need to setup the VMCB for every single CPU. Maybe we'll start with a single core CPU.
	// for_each_cpu(cpu, mask){
		// init_vm_hsave_pa();
		//phys_vmcb_ptr = vmcb_init();

	// We'll need a loop here, right? Handing the VMExits over to a handler.
	// }
	return 0;
}

//__asm__ __volatile__ ("VMRUN" : : "a"(phys_vmcb_ptr));











//When the VMRUN instruction exits (back to the host), an exit/reason code is stored in the EXIT_CODE field in the VMCB
//I am not sure whether we need to put it here.
//This is a table to find specific handler due to the
static int
svm_exit_code (vmcb_t * vmcb)
{
	switch (vmcb->control_area.EXIT_CODE) {
	case VMEXIT_EXCP14:	/* Page fault */
		break;
	case VMEXIT_CR0_READ:
		//do_cr0_read();//next step to finish the handler
		break;
	case VMEXIT_CR0_WRITE:
		break;
	case VMEXIT_CR3_READ:
		break;
	case VMEXIT_CR3_WRITE:
		break;
	case VMEXIT_CR4_READ:
		break;
	case VMEXIT_CR4_WRITE:
		break;
	case VMEXIT_IOIO:
		break;
	case VMEXIT_INVLPG:
		break;
	case VMEXIT_TASK_SWITCH:
		break;
	case VMEXIT_INTR:
		break;
	case VMEXIT_MSR:
		break;
	case VMEXIT_NPF:
		break;
	case VMEXIT_VMMCALL:
		break;
	case VMEXIT_INIT:
		break;
	case VMEXIT_NMI:
		break;
	case VMEXIT_CPUID:
		break;
	case VMEXIT_CLGI:
		break;
	case VMEXIT_STGI:
		break;
	case VMEXIT_VMRUN:
		break;
	case VMEXIT_INVLPGA:
		break;
	default:
		//unsupported vmexit types
		//maybe like panic function
		//now I just return -1 as error
		return -1;
	}
}






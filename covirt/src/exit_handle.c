#include <linux/kernel.h>

#include "exit_handle.h"
#include "vmcb.h"
#include "svm_utils.h"
#include "apic.h"

extern void * __global_Host_Reg_Store; 
extern void * __global_Guest_Reg_Store;
extern void * __global_VMCB_VA;
extern phys_addr_t __global_VMCB_PA;

void handle_phys_int(void){
    vmcb_t * vmcb = (vmcb_t *) __global_VMCB_VA;
    // get_current_irrs();
    // get_current_isrs();
    printk("Handling phys int..");
    if(is_timer_interrupt()){
        vmcb->control_area.guest_int_ctrl.V_INTR_PRIO = 4;
        vmcb->control_area.guest_int_ctrl.V_INTR_VEC = 236;
        vmcb->control_area.guest_int_ctrl.V_IRQ = 1;
        vmcb->control_area.EVENTINJ = 236 + (0 << 8) + (0 << 11) + (1 << 31);
    } else {
        printk("Holy crap, not a timer interrupt\n");
    }
    return;
}


void handle_vmexit(void){
	vmcb_t * vmcb = (vmcb_t *) __global_VMCB_VA;
	uint64_t exitcode = (uint64_t) vmcb->control_area.EXIT_CODE;
	//printk("Hit exit handler....\n");
	//printk("EXIT CODE: 0x%llx\n", exitcode);
	//printk("EXIT INFO1: 0x%llx\n", vmcb->control_area.EXIT_INFO1);
	//printk("EXIT INFO2: 0x%llx\n", vmcb->control_area.EXIT_INFO2);
	//printk("EXIT INT INFO: 0x%llx\n", vmcb->control_area.EXIT_INT_INFO);

	switch(exitcode){

		case VMEXIT_IOIO:
			printk("IO Interrupt\n");
			printk("EXIT INFO1: 0x%llx\n", vmcb->control_area.EXIT_INFO1);
			break;
		case VMEXIT_INTR:
			////printk("Physical Interrupt\n");
			// For performance we may want to deal with TIMER interrupts separately.
			handle_phys_int();
			break;
		case VMEXIT_CPUID:
			printk("CPUID Instruction Intercept\n");
			vmcb->state_save_area.rax = 0xffffffff;
			*(uint64_t *)(__global_Guest_Reg_Store + 32) = 0x20796548;
			*(uint64_t *)(__global_Guest_Reg_Store + 40) = 0x72656854;
			*(uint64_t *)(__global_Guest_Reg_Store + 48) = 0x293A2065;
			//vmcb->state_save_area.rbx = 0xAAAAAAAA;
			//vmcb->state_save_area.rcx = 0xBBBBBBBB;
			//vmcb->state_save_area.rdx = 0xcafebaee;
			break;
		case VMEXIT_RDTSC:
			printk("RDTSC Instruction Intercept\n");
			// This is just a test:
			vmcb->state_save_area.rax = 0xdeadbeef;
			vmcb->control_area.instr_intercepts.RDTSC = 0;
			debug_vmcb(vmcb);
			break;
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
        case VMEXIT_INVLPG:
            break;
        case VMEXIT_TASK_SWITCH:
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
        case VMEXIT_CLGI:
            break;
        case VMEXIT_STGI:
            break;
        case VMEXIT_VMRUN:
            break;
        case VMEXIT_INVLPGA:
            break;
		default:
			// We better not hit this
			break;
	}
	
	// If the exit was caused by an instr_interrupt
	if(exitcode >= 0x65 && exitcode <= 0x7f){
		vmcb->state_save_area.rip = vmcb->control_area.nRIP;
	}

	vmcb->control_area.EXIT_CODE = 0;
	vmcb->control_area.EXIT_INFO1 = 0;
	vmcb->control_area.EXIT_INFO2 = 0;
	vmcb->control_area.EXIT_INT_INFO = 0;

	return;	
}





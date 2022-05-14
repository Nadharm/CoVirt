#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/delay.h>

#include "svm_utils.h"
#include "svm.h"
#include "reg_utils.h"

// Defined as globals for now, this is where we'll store the additional guest + host states
void * __global_Host_Reg_Store; 
void * __global_Guest_Reg_Store;
void * __global_VMCB_VA;
phys_addr_t __global_VMCB_PA;
phys_addr_t __global_VM_HSAVE_PA;

extern void VM_Setup_and_Run(void);

static int __init test_init(void) 
{

	// TODO: find a way to organize this so it works w/ the guest RIP nicely (if that even matters idk)
	// Needs to do these for all CPUs
	svm_check(); // Return 0 if SVM possible
	enable_svm(); // Return 0 on success
	init_vm_hsave_pa();

	__global_Host_Reg_Store = kzalloc(128, GFP_KERNEL);  // only need like 128 bytes for now
	__global_Guest_Reg_Store = kzalloc(128, GFP_KERNEL);  // only neeed like 128 bytes for now

	mdelay(3000);
	VM_Setup_and_Run();	
	__asm__ __volatile__("nop");
	printk("IN GUEST: Hi, we're here!\n");
	printk("Now triggering a VMEXIT...\n");
	//get_cr0();
	// Maybe we'll have this be a wrapper that hits VMRUN for all CPUs separately.
	// vmrun();
	return 0;
}

static void __exit test_exit(void)
{
	printk("Goodbye World\n");
}


module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nadharm Dhiantravan");
MODULE_DESCRIPTION("CoVirt :D");
MODULE_VERSION("0.0");

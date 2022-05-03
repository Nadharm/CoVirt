#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include "svm_utils.h"
#include "svm.h"

static int __init test_init(void) 
{

	// TODO: find a way to organize this so it works w/ the guest RIP nicely (if that even matters idk)
	// Needs to do these for all CPUs
	// svm_check(); // Return 0 if SVM possible
	// enable_svm(); // Return 0 on success

	// Maybe we'll have this be a wrapper that hits VMRUN for all CPUs separately.
	vmrun();
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

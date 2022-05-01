#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include "svm_utils.h"
#include "svmrun.h"

static int __init test_init(void) 
{
	svm_check(); // Return 0 if SVM possible
	enable_svm(); // Return 0 on success
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
MODULE_DESCRIPTION("Check for SVM availability");
MODULE_VERSION("0.0");

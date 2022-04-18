#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include "msr_ops.h"

#define SVM_FF 0x4  // SVM Feature Flag
#define VM_CR 0xC0010114  // VM_CR MSR

static int svm_check(void);  // Will prob move this to a helper

static int __init test_init(void) 
{
	svm_check();
	return 0;
}

static void __exit test_exit(void)
{
	printk("Goodbye World\n");
}

static int svm_check(void) {
	/* (AMD64 Docs Volume 2):
	if (CPUID Fn8000_0001_ECX[SVM] == 0)
		return SVM_NOT_AVAIL;
	if (VM_CR.SVMDIS == 0)
		return SVM_ALLOWED;
	if (CPUID Fn8000_000A_EDX[SVML]==0)
		return SVM_DISABLED_AT_BIOS_NOT_UNLOCKABLE
		// the user must change a platform firmware setting to enable SVM
	else return SVM_DISABLED_WITH_KEY;
		// SVMLock may be unlockable; consult platform firmware or TPM to obtain the key.
	*/

	unsigned int op = 0x80000001;  // Specified function number for CPUID instruction
	unsigned int eax = 0;
	unsigned int ebx = 0;
	unsigned int ecx = 0;
	unsigned int edx = 0;
	
	cpuid(op, &eax, &ebx, &ecx, &edx);

	if (ecx & SVM_FF) {		// Feature flag bit pos for SVM: ECX[2] (0100b)
		printk("STATUS CHECK: SVM Enabled.\n");
	} else {
		printk("STATUS CHECK: SVM NOT Enabled.\n");
		return 1;
	}

	// Reading VM_CR
	printk("RDMSR on VM_CR...\n");
	
	ecx = 0xFFFF; 
	edx = 0;
	eax = 0;

	read_msr(&ecx, &edx, &eax);

	printk("EDX: %u\n", edx);
	printk("EAX: %u\n", eax);

	return 0;
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nadharm Dhiantravan");
MODULE_DESCRIPTION("Check for SVM availability");
MODULE_VERSION("0.0");

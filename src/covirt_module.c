#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include "msr_ops.h"
#include "svmrun.h"

#define SVM_FF 1 << 2 // SVM Feature Flag
#define SVML_FF 1 << 2 // SVML Feature Flag
#define VM_CR 0xC0010114  // VM_CR MSR
#define VMCR_SVMDIS 1 << 4  // SVMDIS bit in VM_CR MSR
#define VMCR_Lock 1 << 3  // Lock bit in VM_CR MSR


static int svm_check(void);  // Will prob move this to a helper

static int __init test_init(void) 
{
	svm_check();
	vmrun();
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

	///
	// CPUID to check whether SVM is enabled.
	unsigned int op = 0x80000001;  // Specified function number for CPUID instruction
	unsigned int eax = 0;
	unsigned int ebx = 0;
	unsigned int ecx = 0;
	unsigned int edx = 0;

	uint64_t vmcr_msr;
	
	cpuid(op, &eax, &ebx, &ecx, &edx);

	if (ecx & SVM_FF) {		// Feature flag bit pos for SVM: ECX[2] (0100b)
		printk("STATUS CHECK: SVM Enabled.\n");
	} else {
		printk("STATUS CHECK: SVM NOT Enabled.\n");
		return 1;
	}
	
	///
	// Reading VM_CR to check for whether SVM is DISabled
	// IF SVM.DIS == 1, EFER.SVME must be 0, thus we aren't able to do VMRUN.

	printk("RDMSR on VM_CR...\n");

	ecx = VM_CR;
	vmcr_msr = read_msr(ecx);

	printk("VMCR MSR: %016llx\n", vmcr_msr);
	
	if (!(vmcr_msr & VMCR_SVMDIS)){
		printk("VMCR.SVMDIS: SVM Allowed (EFER.SVME Writeable)\n");
	} else {
		printk("VMCR.SVMDIS: SVM NOT Allowed (EFER.SVME MBZ)\n");
	}

	if (!(vmcr_msr & VMCR_Lock)){
		printk("VMCR.Lock = 0 (VMCR bits 3 + 4 unlocked)\n");
	} else {
		printk("VMCR.SVMDIS = 1 (VMCR bits 3 + 4 locked)\n");
	}


	op = 0x8000000A;
	eax = 0;
	ecx = 0;
	ebx = 0;
	edx = 0;
	cpuid(op, &eax, &ebx, &ecx, &edx);

	if (edx & SVML_FF) {
		printk("SVM disabled with key, may be unlockable.\n");
	} else {
		printk("SVM Disabled at BIOS, Not Unlockable\n");
		return -1;
	}

	return 0;
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nadharm Dhiantravan");
MODULE_DESCRIPTION("Check for SVM availability");
MODULE_VERSION("0.0");

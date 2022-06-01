#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/io.h>

#include "reg_utils.h"
#include "svm_utils.h"

#ifdef DEBUG_ENABLED
# define DEBUG_PRINT(...) printk(__VA_ARGS__)
#else
# define DEBUG_PRINT(...) do {} while (0)
#endif

extern phys_addr_t __global_VM_HSAVE_PA;
/*
    Check if this machine is capable of SVM. If not, we can't proceed.
*/
int svm_check(void) {
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
		DEBUG_PRINT("STATUS CHECK: SVM Available.\n");
	} else {
		DEBUG_PRINT("STATUS CHECK: SVM NOT Available.\n");
		return -1;
	}
	
	///
	// Reading VM_CR to check for whether SVM is DISabled
	// IF SVM.DIS == 1, EFER.SVME must be 0, thus we aren't able to do VMRUN.

	DEBUG_PRINT("RDMSR on VM_CR...\n");

	ecx = VM_CR;
	vmcr_msr = read_msr(ecx);

	DEBUG_PRINT("VMCR MSR: %016llx\n", vmcr_msr);
	
	if (!(vmcr_msr & VMCR_SVMDIS)){
		DEBUG_PRINT("VMCR.SVMDIS: SVM Allowed (EFER.SVME Writeable)\n");
	} else {
		DEBUG_PRINT("VMCR.SVMDIS: SVM NOT Allowed (EFER.SVME MBZ)\n");
	}

	if (!(vmcr_msr & VMCR_Lock)){
		DEBUG_PRINT("VMCR.Lock = 0 (VMCR bits 3 + 4 unlocked)\n");
	} else {
		DEBUG_PRINT("VMCR.SVMDIS = 1 (VMCR bits 3 + 4 locked)\n");
	}

	op = 0x8000000A;
	eax = 0;
	ecx = 0;
	ebx = 0;
	edx = 0;
	cpuid(op, &eax, &ebx, &ecx, &edx);

	if (edx & SVML_FF) {
		DEBUG_PRINT("SVM disabled with key, may be unlockable.\n");
	} else {
		DEBUG_PRINT("SVM Disabled at BIOS, Not Unlockable\n");
		//return -1;
	}

	if (edx & (0x1 << 3)){
		DEBUG_PRINT("NRIPS ENABLED.\n");
	} else {
		DEBUG_PRINT("NRIPS DISABLED.\n");
	}

	return 0;
}

/*
    All this does it flip the EFER.SVME bit to 1 to enable SVM.
*/
int enable_svm(void){
    uint64_t cur_efer;
	uint64_t new_efer;
	uint32_t hi;
	uint32_t lo;

    // Set EFER.SVME to 1 
	cur_efer = read_msr(EFER_MSR);
	DEBUG_PRINT("Current EFER = %016llx\n", cur_efer);
	new_efer = cur_efer | _SVME;
	hi = new_efer & 0xFFFFFFFF00000000;
	lo = new_efer & 0x00000000FFFFFFFF;
	write_msr(EFER_MSR, hi, lo);
	DEBUG_PRINT("New EFER = %016llx\n", new_efer);
	
	cur_efer = read_msr(EFER_MSR);
	DEBUG_PRINT("Current EFER = %016llx\n", cur_efer);
	if (cur_efer & _SVME){
		DEBUG_PRINT("EFER.SVME modification SUCCESS!\n");
        return 0;
	} else {
		DEBUG_PRINT("EFER.SVME modification FAILED\n");
		return -1;
	}
}

/*
	VMRUN will save the Host state at the physical address in VM_HSAVE_PA MSR.
	This function just allocates that memory and puts it into that MSR.

	Not the best place to have this function, but since it's state-saving related
	we'll keep it here for now.
*/
void init_vm_hsave_pa(void){
	void * vm_hsave_va;
	phys_addr_t vm_hsave_pa;
	uint32_t hi;
	uint32_t lo;

	vm_hsave_pa = read_msr(VM_HSAVE_PA_MSR);
	DEBUG_PRINT("BEFORE CHANGE: VM_HSAVE_PA MSR = %lldx\n", vm_hsave_pa);
	// Allocate VM_HSAVE_PA MSR (C001_0117)
	vm_hsave_va = kzalloc(0x1000, GFP_KERNEL);
	vm_hsave_pa = virt_to_phys(vm_hsave_va);
	hi = vm_hsave_pa & UPPER_4;
	lo = vm_hsave_pa & LOWER_4;
	write_msr(VM_HSAVE_PA_MSR, hi, lo);

	vm_hsave_pa = read_msr(VM_HSAVE_PA_MSR);

	__global_VM_HSAVE_PA = vm_hsave_pa;
	DEBUG_PRINT("AFTER CHANGE: VM_HSAVE_PA MSR = %lldx\n", vm_hsave_pa);
}
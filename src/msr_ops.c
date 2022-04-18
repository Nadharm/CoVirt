#include <linux/kernel.h>

#include "msr_ops.h"

void read_msr(unsigned int * ecx, unsigned int * edx, unsigned int * eax){
	__asm__ __volatile__ (
			"mov %2, %%ecx \n"
			"rdmsr \n"
			"mov %%edx, %0 \n"
			"mov %%eax, %1 \n"
			: "=d"(*edx), "=a"(*eax)
			: "i"(0xC0010114)
			: "ecx" // do we need to clobber edx and eax because of rdmsr?
			);
}

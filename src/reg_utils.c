#include <linux/kernel.h>

#include "svm_utils.h"
#include "reg_utils.h"
#include "vmcb.h"

uint64_t read_msr (uint32_t msr)
{
	uint32_t lo, hi;
	asm volatile("rdmsr" : "=a"(lo), "=d"(hi) : "c"(msr));
	return (((uint64_t) hi << 32) | lo);
}

// Might make a wrapper for this
void write_msr (uint32_t msr, uint32_t hi, uint32_t lo)
{
	__asm__ __volatile__ ("wrmsr" : : "d"(hi), "a"(lo), "c"(msr));
}

uint64_t get_cr0(void)
{
	uint64_t cr0;
	__asm__ __volatile__("mov %%cr0, %0" : "=r"(cr0));
	return cr0;
}

uint64_t get_cr3(void)
{
	uint64_t cr3;
	__asm__ __volatile__("mov %%cr3, %0" : "=r"(cr3));
	return cr3;
}

uint64_t get_cr4(void)
{
	uint64_t cr4;
	__asm__ __volatile__("mov %%cr4, %0" : "=r"(cr4));
	return cr4;
}

desc_ptr get_idtr(void)
{
	desc_ptr idtr;
	__asm__ __volatile__("sidt %0" : "=m"(idtr));
	return idtr;
}

desc_ptr get_gdtr(void)
{
	desc_ptr gdtr;
	__asm__ __volatile__("sgdt %0" : "=m"(gdtr));
	return gdtr;
}

// salb_t get_es(void){
// 	salb_t es;

// }
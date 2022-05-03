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

uint64_t get_cr2(void)
{
	uint64_t cr2;
	__asm__ __volatile__("mov %%cr2, %0" : "=r"(cr2));
	return cr2;
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

segment_t get_es(void){
 	segment_t es;
	__asm__ __volatile__("mov %%es, %0" : "=m"(es->selector));
	
	// TODO: What to fill the Attrib, Limit, Base as? Default values?
	// Does this even matter?

	return es;
}

segment_t get_ds(void){
 	segment_t ds;
	__asm__ __volatile__("mov %%ds, %0" : "=m"(ds->selector));
	
	// TODO: What to fill the Attrib, Limit, Base as? Default values?
	// Does this even matter?

	return ds;
}

segment_t get_ss(void){
 	segment_t ss;
	__asm__ __volatile__("mov %%ss, %0" : "=m"(ss->selector));
	
	// TODO: What to fill the Attrib, Limit, Base as? Default values?
	// Does this even matter?

	return ss;
}

segment_t get_cs(void){
 	segment_t cs;
	__asm__ __volatile__("mov %%cs, %0" : "=m"(cs->selector));
	
	// TODO: What to fill the Attrib, Limit, Base as? Default values?
	// Does this even matter?

	return cs;
}

uint64_t get_dr6(void) {
	uint64_t dr6;
	__asm__ __volatile__("mov %%dr6, %0": "=m"(dr6));
	return dr6;
}
uint64_t get_dr7(void) {
	uint64_t dr7;
	__asm__ __volatile__("mov %%dr7, %0": "=m"(dr7));
	return dr7;
}

uint8_t get_vtpr(void){
	uint64_t cr8;
	uint8_t vtpr;  // Yes, i know the TPR is only 4 bits, but VMCB struct has 8 bits reserved for VMCB.
	__asm__ __volatile__("mov %%cr8, %0": "=m"(cr8));
	vtpr = cr8 & 0x0F;  // Happy? [3:0] = TPR, [7:4] = SBZ
	return vtpr;
}

// uint8_t get_virq(void){
// 	return 0;  // For now
// }
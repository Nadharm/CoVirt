#include <linux/kernel.h>

#include "svm_utils.h"
#include "reg_utils.h"
// #include "vmcb.h"

#ifdef DEBUG_ENABLED
# define DEBUG_PRINT(...) printk(__VA_ARGS__)
#else
# define DEBUG_PRINT(...) do {} while (0)
#endif

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

uint16_t get_es(void){
 	uint16_t es;
	__asm__ __volatile__("mov %%es, %0" : "=m"(es));
	return es;
}

uint16_t get_ds(void){
 	uint16_t ds;
	__asm__ __volatile__("mov %%ds, %0" : "=m"(ds));
	return ds;
}

uint16_t get_ss(void){
 	uint16_t ss;
	__asm__ __volatile__("mov %%ss, %0" : "=m"(ss));
	return ss;
}

uint16_t get_cs(void){
 	uint16_t cs;
	__asm__ __volatile__("mov %%cs, %0" : "=m"(cs));
	return cs;
}

uint16_t get_fs(void){
 	uint16_t fs;
	__asm__ __volatile__("mov %%fs, %0" : "=m"(fs));
	DEBUG_PRINT("FS: %x\n", fs);
	return fs;
}

uint16_t get_gs(void){
 	uint16_t gs;
	__asm__ __volatile__("mov %%gs, %0" : "=m"(gs));
	return gs;
}

uint64_t get_dr6(void) {
	uint64_t dr6;
	__asm__ __volatile__("mov %%dr6, %0": "=a"(dr6));
	return dr6;
}
uint64_t get_dr7(void) {
	uint64_t dr7;
	__asm__ __volatile__("mov %%dr7, %0": "=a"(dr7));
	return dr7;
}

uint8_t get_vtpr(void){
	uint64_t cr8;
	uint8_t vtpr;  // Yes, i know the TPR is only 4 bits, but VMCB struct has 8 bits reserved for VMCB.
	__asm__ __volatile__("mov %%cr8, %0": "=a"(cr8));
	vtpr = cr8 & 0x0F;  // Happy? [3:0] = TPR, [7:4] = SBZ
	return vtpr;
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

uint16_t get_ldtr(void)
{
	uint16_t ldtr;
	__asm__ __volatile__("sldt %0" : "=m"(ldtr));
	return ldtr;
}

uint16_t get_tr(void){
 	uint16_t tr;
	__asm__ __volatile__("str %0" : "=m"(tr));
	return tr;
}

// uint8_t get_virq(void){
// 	return 0;  // For now
// }


// Segment Descriptor Operations (NOT REGISTERS)

// This could be done a little bit better because we already grab the gdtr and ldtr for the VMCB.
// Whatever, doesn't matter. 
uint64_t get_descriptor(seg_sel_t seg_sel){
	// We'll just return 
	desc_ptr gdtr = get_gdtr();
	uint16_t selector_index = seg_sel.val & 0xfff8;  // This will be the offset into the descriptor table.
	long * descriptor_ptr;  // Keep getting a dumb error regarding the uint64_t pointer, so i'm using a long (8 bytes)
	if (seg_sel.TI == 0){
		// Table Index == 0 => Global descriptor table
		descriptor_ptr = (long *) (gdtr.base + selector_index);
		// DEBUG_PRINT("GDTR BASE: %llx\n", gdtr.base);
		// DEBUG_PRINT("Selector Index: %d\n", selector_index);
		// DEBUG_PRINT("Descriptor: %llx\n", *descriptor_ptr);
		return (uint64_t) *descriptor_ptr;
	} 
	// else {
	// 	// Table Index == 1 => Local Descriptor Table
	// 	sys_desc_t ldtr = get_ldtr(gdtr);
	// 	descriptor_ptr = (long *) (ldtr.base + selector_index);
	// 	return (uint64_t) *descriptor_ptr;
	// }
	DEBUG_PRINT("\n\nLOOKING FOR SOMETHING IN LDT\n\n");
	return 0;
}


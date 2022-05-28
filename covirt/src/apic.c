#include <linux/kernel.h>
#include <asm/io.h>

#include "apic.h"
#include "reg_utils.h"


// APIC MSR
#define APIC_BASE_MSR 	0x01b				// Base Address MSR
#define APIC_BASE_MASK 	0xFFFFFFFFFF << 12  // Base Address Mask (for APIC only)
#define APIC_BSC_MASK	0x1 << 8			// Is this the Bootstrap Core
#define APIC_EN_MASK	0x1 << 11			// APIC enabled
#define x2APIC_ENABLE	0x1 << 10			// x2APIC enabled


void __iomem * mapped;

struct apic_ba_reg get_apic_info(void){
	struct apic_ba_reg bar;
	uint64_t bar_raw;
	bar_raw = read_msr(APIC_BASE_MSR);
	bar.base_addr = bar_raw & APIC_BASE_MASK;
	bar.bsc = !!(bar_raw & APIC_BSC_MASK);
	bar.enabled = !!(bar_raw & APIC_EN_MASK);
	bar.x2apic = !!(bar_raw & x2APIC_ENABLE);
	return bar;
}

void print_apic_info(void){
	struct apic_ba_reg bar;
	bar = get_apic_info();
	phys_addr_t base_addr = bar.base_addr;
	printk("xAPIC base address: %llx\n", bar.base_addr);
	printk("Is bootstrap core: %x\n", bar.bsc);
	printk("Is APIC Enabled: %x\n", bar.enabled);
	printk("Is x2APIC Enabled: %x\n", bar.x2apic);
	
}

uint64_t get_current_isrs(void){
	// APIC offsets 100h-170h
	int i = 0;
	for (i = 0; i < 8; i++){
		printk("ISR %x: 0x%x\n", i, ioread32(mapped + 0x100 + (0x10 * i)));
	}
	return 0;
}

uint64_t get_current_irrs(void){
	// APIC offsets 100h-170h
	int i = 0;
	for (i = 0; i < 8; i++){
		printk("IRR %x: 0x%x\n", i, ioread32(mapped + 0x200 + (0x10 * i)));
	}
	return 0;
}

void setup_apic_mapping(void){
	struct apic_ba_reg bar;
	bar = get_apic_info();
	phys_addr_t base_addr = bar.base_addr;

	mapped = ioremap(base_addr, 0x8);
	return;
}

// uint64_t get_vec_to_send(void){
// 	// Need to see what the highest current IRR is

// 	// This may or may not be necessary, as APIC may already decide this.
// 	// Need to see what if there is an ISR
// 	// If ISR:
// 	// 		If IRR > highest ISR: Insert
// 	// 		If IRR <= highest ISR: Prob no insert

// }

/*
	void __iomem * mapped = ioremap(base_addr + 0x350, 0x8);

	if(mapped == NULL){
		printk("nullpointer\n");
	} else {
		uint64_t value = * (uint64_t*)mapped;
		printk("LINT0: %llx\n", value); // 0xffffffff
	}

	mapped = ioremap(base_addr + 0x360, 0x8);

	if(mapped == NULL){
		printk("nullpointer\n");
	} else {
		uint64_t value = * (uint64_t*)mapped;
		printk("LINT1: %llx\n", value); // 0xffffffff
	}
*/



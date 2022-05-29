#include <linux/kernel.h>

void print_apic_info(void);

//// This is for xAPIC

// Apic Base Address Register
struct apic_ba_reg {
	uint64_t base_addr;
	uint8_t bsc; // Is this the boot strap core
	uint8_t enabled; // Is APIC enabled
	uint8_t x2apic;
} __attribute__((packed));

struct apic_ba_reg get_apic_info(void);

uint64_t get_current_isrs(void);
uint64_t get_current_irrs(void);
void setup_apic_mapping(void);
uint16_t is_timer_interrupt(void);


//// This is for x2APIC


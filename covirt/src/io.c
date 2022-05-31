#include <linux/slab.h>

#include "io.h"

void * setup_iopm(void){
    void * iopm_va = (void *)kzalloc(0x3000, GFP_KERNEL);
    
    // Intercept IO on 0x60
	*((uint8_t *)iopm_va + 12) = 0x1;  

	printk("IOPM BASE VA: %llx\n", iopm_va);
    return iopm_va;
}
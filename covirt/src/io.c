#include <linux/slab.h>

#include "io.h"

#ifdef DEBUG_ENABLED
# define DEBUG_PRINT(...) printk(__VA_ARGS__)
#else
# define DEBUG_PRINT(...) do {} while (0)
#endif

void * setup_iopm(void){
    void * iopm_va = (void *)kzalloc(0x3000, GFP_KERNEL);
    
    // Intercept IO on 0x60 (Only keyboard information)
	*((uint8_t *)iopm_va + 12) = 0x1;  

	DEBUG_PRINT("IOPM BASE VA: %llx\n", iopm_va);
    return iopm_va;
}
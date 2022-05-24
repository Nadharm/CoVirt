#include <linux/kernel.h>
#include <stdio.h>
#include <stdlib.h>

static inline void native_cpuid(u_int32_t *eax, u_int32_t *ebx,
                                u_int32_t *ecx, u_int32_t *edx)
{
        /* ecx is often an input as well as an output. */
        asm volatile("cpuid"
            : "=a" (*eax),
              "=b" (*ebx),
              "=c" (*ecx),
              "=d" (*edx)
            : "0" (*eax), "2" (*ecx));
}

/*
static int cpu_info_print(void){
    unsigned int cpu = 0;
    struct cpuinfo_x86 *c;
	const char *vendor = NULL;
	c = &cpu_data(cpu);
	if (c->x86_vendor < X86_VENDOR_NUM) {
		vendor = "Unknown";
	} else {
		if (c->cpuid_level >= 0)
			vendor = c->x86_vendor_id;
	}

	if (vendor && !strstr(c->x86_model_id, vendor))
		pr_cont("%s ", vendor);

	if (c->x86_model_id[0])
		pr_cont("%s", c->x86_model_id);
	else
		pr_cont("%d86", c->x86);

	pr_cont(" (family: 0x%x, model: 0x%x", c->x86, c->x86_model);

	if (c->x86_stepping || c->cpuid_level >= 0)
		pr_cont(", stepping: 0x%x)\n", c->x86_stepping);
	else
		pr_cont(")\n");
    return 0;
}
*/

int test_cpuid_vendor(void);  // Testing CPUID function + Vendor output

int main(void){
    printf("Beginning Unit Tests...\n\n");

    test_cpuid_vendor();
	//cpu_info_print();
}

int test_cpuid_vendor(void){
    u_int32_t eax; 
    u_int32_t ebx; 
    u_int32_t ecx; 
    u_int32_t edx; 

    int i;

    printf("CPUID Test (Print Vendor Name) -----\n");
    eax = 0x00000000;
    native_cpuid(&eax, &ebx, &ecx, &edx);

    for (i = 0; i < 4; i++){
        printf("%c", ((ebx >> (i * 8)) & 0xFF));
    }
    for (i = 0; i < 4; i++){
        printf("%c", ((edx >> (i * 8)) & 0xFF));
    }
    for (i = 0; i < 4; i++){
        printf("%c", ((ecx >> (i * 8)) & 0xFF));
    }
    printf("\n\n");
}


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

int test_cpuid_vendor(void);  // Testing CPUID function + Vendor output

int main(void){
    printf("Beginning Unit Tests...\n\n");

    test_cpuid_vendor();
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
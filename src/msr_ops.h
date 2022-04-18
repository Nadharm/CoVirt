// Load contents of 64-bit MSR specified by ECX register into registers EDX:EAX
// High order bits go to EDX, Low order bits go to EAX
void read_msr(unsigned int * ecx, unsigned int * edx, unsigned int * eax);

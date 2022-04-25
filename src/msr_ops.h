// Load contents of 64-bit MSR specified by ECX register into registers EDX:EAX
// High order bits go to EDX, Low order bits go to EAX
uint64_t read_msr(uint32_t msr);

void write_msr(uint32_t msr, uint32_t hi, uint32_t lo);

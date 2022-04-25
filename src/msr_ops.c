#include <linux/kernel.h>

#include "msr_ops.h"

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
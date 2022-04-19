#include <linux/kernel.h>

#include "msr_ops.h"

uint64_t read_msr (uint32_t msr)
{
	uint32_t lo, hi;
	asm volatile("rdmsr" : "=a"(lo), "=d"(hi) : "c"(msr));
	return (((uint64_t) hi << 32) | lo);
}

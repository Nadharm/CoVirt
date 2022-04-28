#include <linux/kernel>

/* This will contain the structures defining our VMCB */

typedef struct salb {
	uint16_t selector;
	uint16_t attrib;
	uint32_t limit;
	uint64_t base;  // Only lower 32 bits are implemented
} __attribute__((packed)) salb_t;  // I need a better name for this...


// We'll eventually want to have structs defined for each type.
typedef union efer {
	uint64_t val;
	// TODO: Struct here
} efer_t; 

typedef struct state_save_area {
		salb_t es;
		salb_t cs;
		salb_t ss;
		salb_t ds;
		salb_t fs;
		salb_t gs;
		salb_t gdtr;
		salb_t ldtr;
		salb_t idtr;
		salb_t tr;
		
		char rsvd0[43];  // 43 bytes reserved

		char cpl;

		char rsvd1[4];  // 4 bytes reserved
		
		uint64_t efer;  // TODO: Somewhere, make a struct for efer

		char rsvd2[112];  // 112 bytes reserved
		
		// TODO: we'll want structs for all of these as well
		uint64_t cr4;
		uint64_t cr3;
		uint64_t cr0;
		uint64_t dr7;
		uint64_t dr6;
		uint64_t rflags;
		uint64_t rip;

		char rsvd3 [88];  // 88 bytes reserved
		
		uint64_t rsp;
		uint64_t s_cet;
		uint64_t ssp;
		uint64_t isst_addr;
		uint64_t rax;
		uint64_t star;
		uint64_t lstar;
		uint64_t cstar;
		uint64_t sfmask;
		uint64_t kernel_gs_base;
		uint64_t sysenter_cs;
		uint64_t sysenter_esp;
		uint64_t sysenter_eip;
		uint64_t cr2;

		char rsvd4[32];  // 32 bytes reserved

		uint64_t g_pat;
		uint64_t dbgctl;
		uint64_t br_from;
		uint64_t br_to;
		uint64_t last_excp_from;

		char rsvd5[72];  // 72 bytes reserved

		uint64_t spec_ctrl;

		// 0x2E8 -> End of VMCB Reserved
} __attribute__((packed)) state_save_area_t;


typedef struct vmcb {
	// VMCB divided into two areas.
	// Control Area: control bits
	// State Save Area: saved guest state

	// Control Area at offset 0x00 from start of VMCB
	//control_area_t control_area;
	
	// State Save Area at offset 0x400 from start of VMCB
	state_save_area_t state_save_area;
	
	// This SEV_ES will be an issue...

} __attribute__((packed)) vmcb_t;



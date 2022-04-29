#include <linux/kernel>

/* This will contain the structures defining our VMCB */

typedef struct salb {
	uint16_t selector;
	uint16_t attrib;
	uint32_t limit;
	uint64_t base;  // Only lower 32 bits are implemented
} __attribute__((packed)) salb_t;  // I need a better name for this...

typedef struct ctrl_reg {
	int cr0 : 1;
	int cr1 : 1;
	int cr2 : 1;
	int cr3 : 1;
	int cr4 : 1;
	int cr5 : 1;
	int cr6 : 1;
	int cr7 : 1;
	int cr8 : 1;
	int cr9 : 1;
	int cr10 : 1;
	int cr11 : 1;
	int cr12 : 1;
	int cr13 : 1;
	int cr14 : 1;
} __attribute__((packed)) ctrl_reg_t;

typedef struct debug_reg {
 // TODO
} __attribute__((packed)) debug_reg_t; 

// We'll eventually want to have structs defined for each type.
typedef union efer {
	uint64_t val;
	// TODO: Struct here
} efer_t; 

typedef struct control_area {
	ctrl_reg_t cr_reads;	
	ctrl_reg_t cr_writes;

} control_area_t;

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
	// TODO: control_area_t control_area;
	
	// State Save Area at offset 0x400 from start of VMCB
	state_save_area_t state_save_area;
	
	// This SEV_ES will be an issue...

} __attribute__((packed)) vmcb_t;



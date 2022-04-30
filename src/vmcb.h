#include <linux/kernel>

/* This will contain the structures defining our VMCB */

typedef struct salb {
	uint16_t selector;
	uint16_t attrib;
	uint32_t limit;
	uint64_t base;  // Only lower 32 bits are implemented
} __attribute__((packed)) salb_t;  // I need a better name for this...

typedef struct ctrl_reg {
	int CR0 	: 1;
	int CR1 	: 1;
	int CR2 	: 1;
	int CR3 	: 1;
	int CR4 	: 1;
	int CR5 	: 1;
	int CR6 	: 1;
	int CR7 	: 1;
	int CR8		: 1;
	int CR9 	: 1;
	int CR10 	: 1;
	int CR11 	: 1;
	int CR12 	: 1;
	int CR13 	: 1;
	int CR14 	: 1;
	int CR15 	: 1;
} __attribute__((packed)) ctrl_reg_t;

typedef struct debug_reg {
	int DR0		: 1;
	int DR1		: 1;
	int DR2		: 1;
	int DR3		: 1;
	int DR4		: 1;
	int DR5		: 1;
	int DR6		: 1;
	int DR7		: 1;
	int DR8		: 1;
	int DR9		: 1;
	int DR10	: 1;
	int DR11	: 1;
	int DR12	: 1;
	int DR13	: 1;
	int DR14	: 1;
	int DR15	: 1;
} __attribute__((packed)) debug_reg_t; 

typedef struct excp_vecs {
	// AMD Volume 2 Section 8.2
	// interrupt vector | name | cause
	// "EX<NUM>" = reserved/undefined vector

	int DE		: 1; // (0) Divide-by-Zero
	int	DB 		: 1; // (1) Debug ; Instruction + data accesses
	int NMI		: 1; // (2) External Non-maskable interrupt
	int BP		: 1; // (3) Breakpoint ; INT3 instruction
	int OF		: 1; // (4) Overflow ; INTO instruction
	int BR		: 1; // (5) Bound-range ; BOUND instruction
	int UD		: 1; // (6) Invalid opcode/instruction
	int NM		: 1; // (7) Device not avail ; x87 instructions
	int DF 		: 1; // (8) Double fault ; exception during handling of another fault
	int EX9		: 1; // 
	int TS		: 1; // (10) Invalid TSS ; task-state segment access + task switch
	int NP 		: 1; // (11) Segment-Not-Present 
	int SS 		: 1; // (12) Stack ; ss register loads and stack references
	int GP		: 1; // (13) General-Protection ; mem accesses + protection checks
	int PF		: 1; // (14) Page Fault ; mem accessses when paging enabled
	int EX15	: 1;
	int MF		: 1; // (16) x87 floating point exception pending ;
	int AC		: 1; // (17) alignment check ; misaligned mem addr
	int MC		: 1; // (18) machine check; model specific
	int XF		: 1; // (19) SIMD Floating-point ; SSE floating-point instructions
	int EX20	: 1;
	int CP 		: 1; // (21) Control-Protection Exception ; RET/IRET or other control transfer
	int EX22	: 1;
	int EX23	: 1;
	int EX24	: 1;
	int EX25	: 1;
	int EX26	: 1;
	int EX27	: 1;
	int HV		: 1; // (28) Hypervisor Injection ; Event injection 
	int VC		: 1; // (29) VMM Communication Exception ; Virtualization Event
	int SX		: 1; // (30) Security Exception ; Security-sensitive event in host 
	int EX31	: 1;

} __attribute__((packed)) excp_vecs_t;

typedef struct instr_intercepts {
	int INTR		: 1;  // physical maskable interrupt
	int NMI			: 1;
	int SMI			: 1;
	int INIT		: 1;
	int VINTR		: 1;  // virtual maskable interrupt
	int CR0			: 1;  // intercept CR0 writes on bits other than CR0.TS or CR0.MP
	int IDTR_RD		: 1;
	int GDTR_RD 	: 1;
	int LDTR_RD 	: 1;
	int TR_RD 		: 1;
	int IDTR_WR		: 1;
	int GDTR_WR		: 1;
	int LDTR_WR		: 1;
	int TR_WR		: 1;
	int RDTSC		: 1;
	int RDPMC		: 1;
	int PUSHF		: 1;
	int POPF		: 1; 
	int CPUID		: 1;
	int RSM			: 1;
	int IRET		: 1; 
	int INTn		: 1;
	int INVD		: 1;
	int PAUSE		: 1;
	int HLT			: 1;
	int INVLPG		: 1;
	int INVLPGA		: 1;
	int IOIO_PROT	: 1;  // IN/OUT access of selected ports
	int MSR_PROT	: 1;  // intercept RDMSR/WRMSR access to selected MSRs
	int TASK_SWITCH	: 1;  // intercept task switches
	int FERR_FREEZE	: 1;  // intercept processor "frezing" during legacy FERR handling
	int SHUTDOWN	: 1;  // intercept shutdown events
} __attribute__((packed)) instr_intercepts_t;

typedef struct svm_instr_intercepts {
	int VMRUN			: 1; // [0]
	int VMMCALL			: 1; // [1]
	int VMLOAD			: 1; // [2]
	int VMSAVE			: 1; // [3]
	int STGI			: 1; // [4]
	int CLGI			: 1; // [5]
	int SKINIT			: 1; // [6]
	int RDTSCP			: 1; // [7]
	int ICEBP			: 1; // [8]
	int WBN_INST		: 1; // [9] WBINVD + WBNOINVD
	int MONITOR			: 1; // [10] MONITOR/MONITORX
	int MWAIT			: 1; // [11] MWAIT/MWAITX Unconditionally
	int MWAIT_IF_ARMED	: 1; // [12] MWAIT/MWAITX if monitor hardware armed
	int XSETBV			: 1; // [13]
	int RDPRU			: 1; // [14]
	int EFER_WR			: 1; // [15] Write of EFER (occurs after guest instruction finishes)
	ctrl_reg_t CR_WR	: 1; // [16:31] Writes to CR0-15. Isn't this redundant?
} __attribute__((packed)) svm_instr_intercepts_t;


// We'll eventually want to have structs defined for each type.
typedef union efer {
	uint64_t val;
	// TODO: Struct here
} efer_t; 

typedef struct control_area {
	// 0x000
	ctrl_reg_t cr_reads;	
	ctrl_reg_t cr_writes;

	// 0x004
	debug_reg_t dr_reads;
	debug_reg_t dr_writes;

	// 0x008
	excp_vecs_t exception_vectors;

	// 0x00C
	instr_intercepts_t instr_intercepts;

	// 0x010
	svm_instr_intercepts_t svm_instr_intercepts;


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



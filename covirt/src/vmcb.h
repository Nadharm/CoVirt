#include <linux/kernel.h>

/* This file contains:
  - The structures defining our VMCB
  - Relevant types (although we may want to move this into a separate file)
  - Declarations for VMCB-related functions (state save, setup, etc.)
*/

#define VMCB_SIZE 				0x1000 // 4K
#define VMCB_CTRL_AREA_OFFSET	0x000
#define VMCB_CTRL_AREA_SIZE 	0x400
#define VMCB_SS_AREA_OFFSET		0x400
#define VMCB_SS_AREA_SIZE		0x2E8

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
	ctrl_reg_t CR_WR; // [16:31] Writes to CR0-15. Isn't this redundant?
} __attribute__((packed)) svm_instr_intercepts_t;

typedef struct mm_instr_intercepts {
	int INVLPGB			: 1; // [0] All INVLPGB Instructions
	int IL_INVLPGB		: 1; // [1] Invalid INVLPGB Instructions
	int INVPCID			: 1; // [2]
	int MCOMMIT			: 1; // [3]
	int TLBSYNC			: 1; // [4] Presence of this bit indicated by CPUID Fn8000_0000A_EDX[24] = 1
	int rsvd 			: 27; // [5-31] Reserved, SBZ
} __attribute__((packed)) mm_instr_intercepts_t;

typedef union tlb_control {
	char val;
	struct {
		int do_nothing 		: 1; // [0] Do nothing
		int flush_tlb		: 1; // [1] Flush the entire TLB on VMRUN (only use for legacy Hypervisors)
		int rsvd0			: 1; // [2] Reserved
		int flush_currrent	: 1; // [3] Flush this guest's TLB entries
		int rsvd1			: 3; // [4-6] Reserved
		int flush_non_glob	: 1; // [7] Flush this guest's non-global TLB entries
	} __attribute__((packed));
} __attribute__((packed)) tlb_control_t;

typedef struct guest_int_ctrl {
	int V_TPR		: 8; // Virtual TPR for the guest. [3:0] for the VTPR, [7:4] SBZ
	int V_IRQ		: 1; // If nonzero, virtual INTR is pending. Written to VMCB @ VMEXIT. Ignored on VMRUN if AVIC enabled.
	int VGIF		: 1; // (0 - Virtual Intr masked, 1 - Virtual Intr unmasked)
	int rsvd0		: 6; // Reserved, SBZ
	int V_INTR_PRIO	: 4; // Priority for virtual interrupt (ignored on VMRUN when AVIC enabled)
	int V_IGN_TPR	: 1; // If nonzero, the current virtual interrupt ignores the virtual TPR
	int rsvd1		: 3; // Reserved, SBZ
	int V_INTR_MASK	: 1; // Virtualizing masking of INTR
	int AMD_VGIF	: 1; // AMD Virutal GIF Enabled (0 - Disabled, 1 - Enabled)
	int rsvd2		: 5; // Reserved, SBZ
	int AVIC_ENABLE	: 1; // AVIC Enable
	int V_INTR_VEC	: 8; // Vector to use for this interrupt (ignored on VMRUN w/ AVIC Enabled)
	int rsvd3		: 24; // Reserved, SBZ
} __attribute__((packed)) guest_int_ctrl_t; 

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

	// 0x014
	mm_instr_intercepts_t mm_instr_intercepts;

	// 0x018
	char rsvd0[36];  // 0x018 - 0x03B reserved

	// 0x03C
	uint16_t pause_filter_threshold;
	uint16_t pause_filter_count;

	// 0x040
	uint64_t IOPM_BASE_PA;  // Physical base addr of IOPM (bits 11:0 ignored)
	uint64_t MSRPM_BASE_PA; // Physical base addr of MSRPM (bits 11:0 ignored)
	uint64_t TSC_OFFSET; // Timestamp Counter offset (added to RDTSC + RDTSCP)

	// 0x058 
	uint32_t guest_asid;
	tlb_control_t TLB_CONTROL;
	char rsvd1[24];

	// 0x060
	guest_int_ctrl_t guest_int_ctrl;

	// 0x068
	int interrupt_shadow 		: 1; // Guest is in an interrupt shadow
	int guest_interrupt_mask	: 1; // Valud of RFLAGS.IF bit for the guest. Written back to VMCB on VMEXIT.
	uint64_t rsvd2				: 62; // Reserved, SBZ

	// 0x070
	int64_t EXIT_CODE;
	uint64_t EXIT_INFO1;
	uint64_t EXIT_INFO2;
	uint64_t EXIT_INT_INFO; // TODO: Struct for this

	// 0x090
	// I want a struct for this but idk if they're all even related... >:(
	int NP_Enable 			: 1; // Enable Nested Paging
	int SEV_Enable			: 1; // Enable Secure Encrypted Virtualization (SEV)
	int Encrypt_SEV_Enable	: 1; // Enable Encrypted State for SEV
	int GM_Execute_Trap		: 1; // Guest Mode Execute Trap (huh?)
	int SSSCheckEn			: 1; // Enable Supervisor Shadow Stack restrictions in Nested PTs. CPUID Fn8000_000A_EDX[19]
	int Virt_Trans_Encr		: 1; // Virtual Transparent Encryption
	int rsvd3 				: 1; // Reserved, SBZ
	int INVLPGB_TLBSYNC_EN	: 1; // Enable INVLPGB + TLBSYNC (If 0 -> #UD on instruction call)
	uint64_t rsvd4			: 56; // Reserved, SBZ

	// 0x098
	uint64_t AVIC_APIC_BAR	: 52; // AVIC APIC BAR (idk what this is either) 
	uint64_t rsvd5			: 12; // I do know that this is reserved, sbz tho!

	// 0x0A0
	uint64_t GHCB_PA; // Guest Physical Address of GHCB
	uint64_t EVENTINJ; // Event Injection 
	uint64_t N_CR3; // Nested page table CR3 to use for nested paging

	//0x0B8
	int LBR_VIRT_ENABLE		: 1; // 1 - Enable LBR Virtualization hardware acceleration
	int VIRT_SAVE_LOAD		: 1; // 1 - Enable Virtualized VMSAVE/VMLOAD
	uint64_t rsvd6			: 62; // Reserved, SBZ

	// 0x0C0
	uint32_t clean_bits;
	uint32_t rsvd7;

	// 0x0C8
	uint64_t nRIP; // Next sequential instruction pointer

	// 0x0D0 (wtf is this)
	uint8_t num_bytes_fetched;
	uint8_t guest_instruction_bytes[15]; 

	//0x0E0
	uint64_t APIC_BACKING_PAGE_PTR	: 52;
	uint64_t rsvd99					: 12;

	//0x0E8
	char rsvd8[8];

	// 0x0F0
	uint64_t rsvd9					: 12;
	uint64_t AVIC_LOGICAL_TABLE_PTR : 40; 
	uint64_t rsvd10					: 12;

	// 0x0F8
	uint64_t AVIC_PHYS_MAX_IDX		: 8;
	uint64_t rsvd11					: 4;
	uint64_t AVIC_PHYS_TABLE_PTR	: 40;
	uint64_t rsvd12					: 12;

	// 0x100
	uint64_t rsvd13;

	// 0x108
	uint64_t rsvd14					: 12;
	uint64_t VMSA_PTR				: 40;
	uint64_t rsvd15					: 12;

	// 0x110 - 0x3DF Reserved, SBZ
	char rsvd16[720];

	// 0x3E0 - 0x3FF
	// RESERVED FOR HOST
	char rsvd17[VMCB_CTRL_AREA_SIZE - 0x3E0];
} __attribute__((packed)) control_area_t;

typedef struct segment {
	uint16_t selector;
	uint16_t attrib;
	uint32_t limit;
	uint64_t base;
} __attribute__((packed)) segment_t;  // I need a better name for this...

typedef struct state_save_area {
		segment_t es;
		segment_t cs;
		segment_t ss;
		segment_t ds;
		segment_t fs;
		segment_t gs;
		segment_t gdtr;  // Selector + Attrib Reserved. Only lower 16 bits for Limit.
		segment_t ldtr;  
		segment_t idtr;  // Selector + Attrib Reserved. Only lower 16 bits for Limit.
		segment_t tr;
		
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

		// 0x2E0
		uint64_t spec_ctrl;

		// 0x2E8 -> End of VMCB Reserved
		char rsvd_to_end[VMCB_SIZE - (0x2E8 + VMCB_SS_AREA_OFFSET)];
} __attribute__((packed)) state_save_area_t;


typedef struct vmcb {
	// VMCB divided into two areas.
	// Control Area: control bits
	// State Save Area: saved guest state

	// Control Area at offset 0x00 from start of VMCB
	control_area_t control_area;
	
	// State Save Area at offset 0x400 from start of VMCB
	state_save_area_t state_save_area;
	
	// This SEV_ES may be an issue...

} __attribute__((packed)) vmcb_t;


/*
	VMCB Function Declarations
*/

phys_addr_t vmcb_init(uint64_t rip, uint64_t rsp, uint64_t rax, uint64_t rflags);  // Will perform all set up for the VMCB and return its physical address.

void debug_vmcb(vmcb_t * vmcb);  // Print out the VMCB contents

void handle_vmexit(void);
// Load contents of 64-bit MSR specified by ECX register into registers EDX:EAX
// High order bits go to EDX, Low order bits go to EAX
#define UPPER_4 0xFFFFFFFF00000000
#define LOWER_4 0x00000000FFFFFFFF
#define EFER_MSR 0xC0000080 // Address of EFER MSR
#define VM_HSAVE_PA_MSR	0xC0010117 // The PA of host state save goes here
#define SVM_FF 1 << 2 // SVM Feature Flag
#define SVML_FF 1 << 2 // SVML Feature Flag
#define VM_CR 0xC0010114  // VM_CR MSR
#define VMCR_SVMDIS 1 << 4  // SVMDIS bit in VM_CR MSR
#define VMCR_Lock 1 << 3  // Lock bit in VM_CR MSR
#define _SVME 1 << 12  // EFER.SVME Bit

// Should probably use Linux's desc_ptr but idk who cares
typedef struct descriptor_ptr {
    uint16_t limit;
    uint64_t base;
} __attribute__((packed)) desc_ptr;

// RFLAGS register, maybe put here?Not sure
typedef struct rflags_reg {
    uint64_t CF        : 1; //[0] carry flag
    uint64_t rsvd0     : 1; //[1] reserved 
    uint64_t PF        : 1; //[2] Parity Flag
    uint64_t rsvd1     : 1; //[3] reserved
    uint64_t AF        : 1; //[4] Auxiliary Flag
    uint64_t rsvd2     : 1; //[5] reserved
    uint64_t ZF        : 1; //[6] Zero Flag
    uint64_t SF        : 1; //[7] Sign Flag
    uint64_t TF        : 1; //[8] Trap Flag
    uint64_t IF        : 1; //[9] Interrupt Flag
    uint64_t DF        : 1; //[10] Direction Flag
    uint64_t OF        : 1; //[11] Overflow Flag
    uint64_t IOPL      : 2; //[12-13] I/O Privilege Level
    uint64_t NT        : 1; //[14] Nested Task
    uint64_t rsvd3     : 1; //[15] reserved
    uint64_t RF        : 1; //[16] Resume Flag
    uint64_t VM        : 1; //[17] Virtual-8086 Mode
    uint64_t AC        : 1; //[18] Alignment Check
    uint64_t VIF       : 1; //[19] Virtual Interrupt Flag
    uint64_t VIP       : 1; //[20] Virtual Interrupt Pending
    uint64_t ID        : 1; //[21] ID Flag
    uint64_t rsvd4     : 42;  //[22-63] reserved
} __attribute__((packed)) rflags_reg_t;


// EFER register, maybe put here?Not sure
typedef struct efer_reg {
    uint64_t SCE       : 1; //[0] System Call Extensions
    uint64_t rsvd0     : 7; //[1-7] reserved 
    uint64_t LME       : 1; //[8] Long Mode Enable
    uint64_t rsvd1     : 1; //[9] reserved
    uint64_t LMA       : 1; //[10] Long Mode Active
    uint64_t NXE       : 1; //[11] No-Execute Enable
    uint64_t SVME      : 1; //[12] Secure Virtual Machine Enable
    uint64_t LMSLE     : 1; //[13] Long Mode Segment Limit Enable
    uint64_t FFXSR     : 1; //[14] Fast FXSAVE/FXRSTOR
    uint64_t TCE       : 1; //[15] Translation Cache Extension
    uint64_t rsvd2     : 1; //[16] reserved
    uint64_t MCOMMIT   : 1; //[17] Enable MCOMMIT instruction 
    uint64_t INTWB     : 1; //[18] Interruptible WBINVD/WBNOINVD enable
    uint64_t rsvd3     : 1; //[19] reserved
    uint64_t UAIE      : 1; //[20] Upper Address Ignore Enable
    uint64_t rsvd4     : 43; //[21-63] reserved
} __attribute__((packed)) efer_reg_t;


uint64_t read_msr(uint32_t msr);
void write_msr(uint32_t msr, uint32_t hi, uint32_t lo);

uint64_t get_cr0(void);
uint64_t get_cr2(void);
uint64_t get_cr3(void);
uint64_t get_cr4(void);

desc_ptr get_idtr(void);
desc_ptr get_gdtr(void);

uint16_t get_cs(void);
uint16_t get_es(void);
uint16_t get_ds(void);
uint16_t get_ss(void);

uint64_t get_dr6(void);
uint64_t get_dr7(void);

uint8_t get_vtpr(void);  // This is 8 bits, even though the V_TPR is 4 bits. This is because of the VMCB CA's stucture. 
// uint8_t get_virq(void);  // This actually is only 1 bit
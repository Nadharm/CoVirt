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

// SYSCALL and SYSRET MSRs
#define STAR_MSR    0xC0000081
#define LSTAR_MSR   0xC0000082
#define CSTAR_MSR   0xC0000083
#define SFMASK_MSR  0xC0000084

// SYSENTER and SYSEXIT (Legacy Mode Only)
#define SYSENTER_CS_MSR     0x174
#define SYSENTER_ESP_MSR    0x175
#define SYSENTER_EIP_MSR    0x176

// Used for SWAPGS
#define KernelGSBase_MSR    0xC0000102

// Should probably use Linux's desc_ptr but idk who cares
typedef struct descriptor_ptr {
    uint16_t limit;
    uint64_t base;
} __attribute__((packed)) desc_ptr;

typedef struct __128bit {
    uint64_t low;
    uint64_t high;
} __attribute__((packed)) __128bit_t;

typedef struct sys_desc {
    uint16_t selector;
    uint16_t attributes;
    uint32_t limit;
    uint64_t base;
} __attribute__((packed)) sys_desc_t;

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
typedef union efer_reg {
    uint64_t val;
    struct {
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
    } __attribute__((packed)); 
} __attribute__((packed)) efer_reg_t;

typedef union cr0_reg {
    uint64_t val;
    struct {
        uint64_t PE     : 1;  // [0] Protection Enabled
        uint64_t MP     : 1;  // [1] Monitor Coprocessor
        uint64_t EM     : 1;  // [2] Emulation
        uint64_t TS     : 1;  // [3] Task Switched
        uint64_t ET     : 1;  // [4] Extension Type
        uint64_t NE     : 1;  // [5] Numeric Error
        uint64_t rsvd0  : 10; // [6:15] rsvd, do not change
        uint64_t WP     : 1;  // [16] Write Protect
        uint64_t rsvd1  : 1;  // [17] reserved, do not change
        uint64_t AM     : 1;  // [18] alignment mask
        uint64_t rsvd2  : 10; // [19:28] reserved, do not change
        uint64_t NW     : 1;  // [29] Not writethrough
        uint64_t CD     : 1;  // [30] Cache Disable
        uint64_t PG     : 1;  // [31] Paging
        uint64_t rsvd3  : 32; // [32:63]
    } __attribute__((packed));
} __attribute__((packed)) cr0_reg_t;

// TODO: CR2 Register (AMD VOL 2, 3.1.2)
/* 
typedef struct cr2_reg {
} __attribute__((packed)) cr2_reg_t;
*/
//CR2_reg are used for page-fault linear address, maybe don't need the struct for this.



// TODO: CR3 Register (AMD VOL 2, 3.1.2)
/* 
typedef struct cr3_reg {
} __attribute__((packed)) cr3_reg_t;
*/
//CR3 used for page table (this is in long mode)
typedef union cr3_reg {
    uint64_t val;
    struct {
        uint64_t rsvd0      : 3;  //[0-2] reserved
        uint64_t PWT        : 1;  //[3] Page-Level Writethrough (PWT) Bit. see volume 2 P151
        uint64_t PCD        : 1;  //[4] Page-Level Cache Disable (PCD) Bit.
        uint64_t rsvd1      : 7;  //[5-11] reserved
        uint64_t TBA0       : 20; //[12-31] 4-level table base address 
        uint64_t TBA1       : 20; //[32-51] 4-level table base address
        uint64_t rsvd2      : 12;  //[52-63] reserved and MBZ(must be zero)
    } __attribute__((packed));
} __attribute__((packed)) cr3_reg_t;






// TODO: CR4 Register (AMD VOL 2, 3.1.2)
/*
typedef struct cr4_reg {
} __attribute__((packed)) cr4_reg_t;
*/
//CR4 register
typedef union cr4_reg {
    uint64_t val;
    struct {
        uint64_t VME        : 1; //[0] Virtual-8086 Mode Extensions
        uint64_t PVI        : 1; //[1] Protected-Mode Virtual Interrupts
        uint64_t TSD        : 1; //[2] Time Stamp Disable
        uint64_t DE         : 1; //[3] Debugging Extensions
        uint64_t PSE        : 1; //[4] Page Size Extensions
        uint64_t PAE        : 1; //[5] Physical-Address Extension
        uint64_t MCE        : 1; //[6] Machine Check Enable
        uint64_t PGE        : 1; //[7] Page-Global Enable
        uint64_t PCE        : 1; //[8] Performance-Monitoring Counter Enable
        uint64_t OSFXSR     : 1; //[9] Operating System FXSAVE/FXRSTOR Support
        uint64_t OSXMMEXCPT : 1; //[10] Operating System Unmasked Exception Support
        uint64_t UMIP       : 1; //[11] User Mode Instruction Prevention
        uint64_t rsvd0      : 4; //[12-15] reserved, MBZ(must be zero)
        uint64_t FSGSBASE   : 1; //[16] Enable RDFSBASE, RDGSBASE, WRFSBASE, and WRGSBASE instructions
        uint64_t PCIDE      : 1; //[17] Process Context Identifier Enable
        uint64_t OSXSAVE    : 1; //[18] XSAVE and Processor Extended States Enable Bit
        uint64_t rsvd1      : 1; //[19] reserved
        uint64_t SMEP       : 1; //[20] Supervisor Mode Execution Prevention
        uint64_t SMAP       : 1; //[21] Supervisor Mode Access Protection
        uint64_t PKE        : 1; //[22] Protection Key Enable
        uint64_t CET        : 1; //[23] Control-flow Enforcement Technology
        uint64_t rsvd2      : 40; //[24-63] reserved, MBZ
    } __attribute__((packed));
} __attribute__((packed)) cr4_reg_t;







// TODO: CS (Code-Segment) Descriptors (AMD VOL 2, 4.8.1)

//see volume 2 Page 76 
//cs register has 16bit value which can be loaded to segement selector, this segement selector points to cs descriptor in the GDT(Global descriptor table)
//for cs
typedef union seg_sel {
    uint16_t val;
    struct {
        uint16_t RPL    : 2;  //[0-1] Requestor Privilege Level
        uint16_t TI     : 1;  //[2] Table Indicator TI=0 ->Global, TI=1 ->Local
        uint16_t SI     : 13; //[3-15]  Selector Index
    } __attribute__((packed));
} __attribute__((packed)) seg_sel_t;

// cs descripter has 2 doublwords(32 bits), and when in 64-bit long mode only D, L, P, DPL, C works
typedef union cs_descriptor {
    uint64_t val;
    struct {
        uint64_t SL0    : 16; //[0-15]first doubleword start. SegmentLimit[15:0] 
        uint64_t BA0    : 16; //[16-31]first doubleword end. Base address[15:0]
        uint64_t BA1    : 8;  //[0-7]second doubleword start. Base address[23:16]
        uint64_t A      : 1;  //[8] access
        uint64_t R      : 1;  //[9] Read
        uint64_t C      : 1;  //[10] conform
        uint64_t rsvd0  : 1;  //[11] for Type[8-11] must be 1
        uint64_t rsvd1  : 1;  //[12] S bit must be 1 
        uint64_t DPL    : 2;  //[13-14] Descriptor Privilege-Level (DPL) Field.
        uint64_t P      : 1;  //[15] Present
        uint64_t SL1    : 4;  //[16-19] SegmentLimit[19:16]
        uint64_t AVL    : 1;  //[20] Available To Software (AVL) Bit.
        uint64_t L      : 1;  //[21] Long (L) Attribute Bit 
        uint64_t D      : 1;  //[22] Code-Segment Default-Operand Size (D) Bit
        uint64_t G      : 1;  //[23] Granularity (G) Bit.
        uint64_t BA2    : 8;  //[24-31]second doubleword end. Base address[31:24]
    } __attribute__((packed));
} __attribute__((packed)) cs_descriptor_t;



// TODO: There are other system registers, but idk if we'll need them atm...


uint64_t read_msr(uint32_t msr);
void write_msr(uint32_t msr, uint32_t hi, uint32_t lo);

uint64_t get_cr0(void);
uint64_t get_cr2(void);
uint64_t get_cr3(void);
uint64_t get_cr4(void);

desc_ptr get_idtr(void);
desc_ptr get_gdtr(void);

uint64_t get_descriptor(seg_sel_t seg_sel);

uint16_t get_cs(void);
uint16_t get_es(void);
uint16_t get_ds(void);
uint16_t get_ss(void);
uint16_t get_fs(void);
uint16_t get_gs(void);

uint16_t get_ldtr(void);
uint16_t get_tr(void);

uint64_t get_dr6(void);
uint64_t get_dr7(void);

uint8_t get_vtpr(void);  // This is 8 bits, even though the V_TPR is 4 bits. This is because of the VMCB CA's stucture. 
// uint8_t get_virq(void);  // This actually is only 1 bit


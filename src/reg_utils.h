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
#define SVME 1 << 12  // EFER.SVME Bit

// Should probably use Linux's desc_ptr but idk who cares
typedef struct descriptor_ptr {
    uint16_t limit;
    uint64_t base;
} __attribute__((packed)) desc_ptr;

uint64_t read_msr(uint32_t msr);
void write_msr(uint32_t msr, uint32_t hi, uint32_t lo);

uint64_t get_cr0(void);
uint64_t get_cr2(void);
uint64_t get_cr3(void);
uint64_t get_cr4(void);

desc_ptr get_idtr(void);
desc_ptr get_gdtr(void);

segment_t get_cs(void);
segment_t get_es(void);
segment_t get_ds(void);
segment_t get_ss(void);

uint64_t get_dr6(void);
uint64_t get_dr7(void);

uint8_t get_vtpr(void);  // This is 8 bits, even though the V_TPR is 4 bits. This is because of the VMCB CA's stucture. 
// uint8_t get_virq(void);  // This actually is only 1 bit
.extern vmcb_init
.extern handle_vmexit

.extern void * __global_Host_Reg_Store; 
.extern void * __global_Guest_Reg_Store;
.extern void * __global_VMCB_VA;
.extern phys_addr_t __global_VMCB_PA;
.extern phys_addr_t __global_VM_HSAVE_PA;

#define Save_SVM_Registers(location) 	\
	pushq	%rax; 				\
	movq	location, %rax;		\
	movq	%rdi, (%rax);		\
	movq	%rsi, 8(%rax);		\
	movq	%rbp, 16(%rax);		\
	movq	$0, 24(%rax);		\
	movq 	%rbx, 32(%rax);		\
	movq 	%rdx, 40(%rax);		\
	movq 	%rcx, 48(%rax);		\
								\
	movq	%r8, 64(%rax);		\
	movq	%r9, 72(%rax);		\
	movq	%r10, 80(%rax);		\
	movq	%r11, 88(%rax);		\
	movq	%r12, 96(%rax);		\
	movq	%r13, 104(%rax);	\
	movq	%r14, 112(%rax);	\
	movq	%r15, 120(%rax);	\
	popq 	%rax;			
	

#define Restore_SVM_Registers(location) \
	push	%rax;			\
	mov	location, %rax;		\
	mov	(%rax), %rdi;		\
	mov	8(%rax), %rsi;		\
	mov	16(%rax), %rbp;		\
	mov	32(%rax), %rbx;		\
	mov	40(%rax), %rdx;		\
	mov 48(%rax), %rcx;		\
							\
	mov	64(%rax), %r8;		\
	mov	72(%rax), %r9;		\
	mov	80(%rax), %r10;		\
	mov	88(%rax), %r11;		\
	mov	96(%rax), %r12;		\
	mov	104(%rax), %r13;	\
	mov	112(%rax), %r14;	\
	mov	120(%rax), %r15;	\
	pop	%rax;

#define PUSHA				\
	pushq %rbp;			\
	pushq %rbx;			\
	pushq %r8;			\
	pushq %r9;			\
	pushq %r10;			\
	pushq %r11;			\
	pushq %r12;			\
	pushq %r13;			\
	pushq %r14;			\
	pushq %r15;			


#define POPA				\
	popq %r15;			\
	popq %r14;			\
	popq %r13;			\
	popq %r12;			\
	popq %r11;			\
	popq %r10;			\
	popq %r9;			\
	popq %r8;			\
	popq %rbx;			\
	popq %rbp;			



.text

.globl VM_Setup_and_Run

VM_Setup_and_Run:
	Save_SVM_Registers(__global_Guest_Reg_Store)
	clgi

	pushq %rbp					//
	movq %rsp, %rbp				//

	// vmcb_init
	movq 8(%rbp), %rdi			// [Arg 1] Move Saved Return Address to %rdi
	leaq 8(%rbp), %rsi		// [Arg 2] Move original %rsp to %rsi
	movq %rax, %rdx				// [Arg 3] Move %rax to %rdx
	pushfq						// Push RFLAGS
	popq %rcx					// [Arg 4] Pop RFLAGS into %rcx
	call vmcb_init				// Initialize the Guest VMCB

	
run_loop:
	// VM_HSAVE_PA MSR already setup

	Save_SVM_Registers(__global_Host_Reg_Store);

	Restore_SVM_Registers(__global_Guest_Reg_Store);

	movq (__global_VMCB_PA), %rax	// Move the VMCB Physical Address into RAX so VMRUN can use it.

	//vmload;
	vmrun;
	//vmsave;

	Save_SVM_Registers(__global_Guest_Reg_Store);

	Restore_SVM_Registers(__global_Host_Reg_Store);

	call handle_vmexit

	jmp run_loop 

	// We shouldn't hit here I don't think...
	movq %rbp, %rsp
	popq %rbp
	ret

/*

    Initial Entry(Guest Start Addr): 
        - Last thing done in module
    Trampoline:
        - Initial RIP supplied to Initial Entry()
        - 

*/
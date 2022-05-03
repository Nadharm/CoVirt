.global trampoline
trampoline:


#define Save_SVM_Registers(location) 	\
	pushq	%rax; 			\
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
	mov 	48(%rax), %rcx;		\
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


/*

    Initial Entry(Guest Start Addr): 
        - Last thing done in module
    Trampoline:
        - Initial RIP supplied to Initial Entry()
        - 

*/
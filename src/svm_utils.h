#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/io.h>

int svm_check(void);  // Check if SVM is available or a possibility
int enable_svm(void);  // Turn on SVM (flip EFER.SVME to 1)

void init_vm_hsave_pa(void);  // TODO: Move this somewhere else? O_O
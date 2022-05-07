obj-m += covirt_module.o
covirt_module-objs += src/covirt_module.o src/reg_utils.o src/svm.o src/svm_utils.o src/vmcb.o src/low_level.o

all:
	make -C $(KERNEL_ROOT) M=$(PWD) modules
	
clean:
	make -C $(KERNEL_ROOT) M=$(PWD) clean

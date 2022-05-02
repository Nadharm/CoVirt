obj-m += covirt_module.o
covirt_module-objs += src/covirt_module.o src/reg_utils.o src/svm.o src/svm_utils.o src/vmcb.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

obj-m += covirt_module.o
covirt_module-objs += src/covirt_module.o src/msr_ops.o src/svmrun.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

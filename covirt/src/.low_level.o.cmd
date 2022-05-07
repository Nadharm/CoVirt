cmd_/home/osiris/CoVirt/covirt/src/low_level.o := gcc -Wp,-MMD,/home/osiris/CoVirt/covirt/src/.low_level.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-linux-gnu/9/include -I/home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include -I./arch/x86/include/generated -I/home/osiris/CoVirt/testing_playground/linux-5.13/include -I./include -I/home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi -I./arch/x86/include/generated/uapi -I/home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi -I./include/generated/uapi -include /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/compiler-version.h -include /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/kconfig.h -D__KERNEL__ -fmacro-prefix-map=/home/osiris/CoVirt/testing_playground/linux-5.13/= -D__ASSEMBLY__ -fno-PIE -m64  -DMODULE  -c -o /home/osiris/CoVirt/covirt/src/low_level.o /home/osiris/CoVirt/covirt/src/low_level.S

source_/home/osiris/CoVirt/covirt/src/low_level.o := /home/osiris/CoVirt/covirt/src/low_level.S

deps_/home/osiris/CoVirt/covirt/src/low_level.o := \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/compiler-version.h \
    $(wildcard include/config/CC_VERSION_TEXT) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/kconfig.h \
    $(wildcard include/config/CPU_BIG_ENDIAN) \
    $(wildcard include/config/BOOGER) \
    $(wildcard include/config/FOO) \

/home/osiris/CoVirt/covirt/src/low_level.o: $(deps_/home/osiris/CoVirt/covirt/src/low_level.o)

$(deps_/home/osiris/CoVirt/covirt/src/low_level.o):

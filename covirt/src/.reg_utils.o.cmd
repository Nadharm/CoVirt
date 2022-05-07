cmd_/home/osiris/CoVirt/covirt/src/reg_utils.o := gcc -Wp,-MMD,/home/osiris/CoVirt/covirt/src/.reg_utils.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-linux-gnu/9/include -I/home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include -I./arch/x86/include/generated -I/home/osiris/CoVirt/testing_playground/linux-5.13/include -I./include -I/home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi -I./arch/x86/include/generated/uapi -I/home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi -I./include/generated/uapi -include /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/compiler-version.h -include /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/kconfig.h -include /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/compiler_types.h -D__KERNEL__ -fmacro-prefix-map=/home/osiris/CoVirt/testing_playground/linux-5.13/= -Wall -Wundef -Werror=strict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -fno-PIE -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Wno-format-security -std=gnu89 -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -fcf-protection=none -m64 -falign-jumps=1 -falign-loops=1 -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3 -mskip-rax-setup -mtune=generic -mno-red-zone -mcmodel=kernel -Wno-sign-compare -fno-asynchronous-unwind-tables -mindirect-branch=thunk-extern -mindirect-branch-register -fno-jump-tables -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-address-of-packed-member -O2 --param=allow-store-data-races=0 -Wframe-larger-than=2048 -fstack-protector-strong -Wimplicit-fallthrough -Wno-unused-but-set-variable -Wno-unused-const-variable -fomit-frame-pointer -fno-stack-clash-protection -Wdeclaration-after-statement -Wvla -Wno-pointer-sign -Wno-stringop-truncation -Wno-array-bounds -Wno-stringop-overflow -Wno-restrict -Wno-maybe-uninitialized -fno-strict-overflow -fno-stack-check -fconserve-stack -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -Wno-packed-not-aligned  -DMODULE  -DKBUILD_BASENAME='"reg_utils"' -DKBUILD_MODNAME='"covirt_module"' -D__KBUILD_MODNAME=kmod_covirt_module -c -o /home/osiris/CoVirt/covirt/src/reg_utils.o /home/osiris/CoVirt/covirt/src/reg_utils.c

source_/home/osiris/CoVirt/covirt/src/reg_utils.o := /home/osiris/CoVirt/covirt/src/reg_utils.c

deps_/home/osiris/CoVirt/covirt/src/reg_utils.o := \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/compiler-version.h \
    $(wildcard include/config/CC_VERSION_TEXT) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/kconfig.h \
    $(wildcard include/config/CPU_BIG_ENDIAN) \
    $(wildcard include/config/BOOGER) \
    $(wildcard include/config/FOO) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/compiler_types.h \
    $(wildcard include/config/HAVE_ARCH_COMPILER_H) \
    $(wildcard include/config/CC_HAS_ASM_INLINE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/compiler_attributes.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/compiler-gcc.h \
    $(wildcard include/config/RETPOLINE) \
    $(wildcard include/config/ARCH_USE_BUILTIN_BSWAP) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/kernel.h \
    $(wildcard include/config/PREEMPT_VOLUNTARY) \
    $(wildcard include/config/PREEMPT_DYNAMIC) \
    $(wildcard include/config/PREEMPT_) \
    $(wildcard include/config/DEBUG_ATOMIC_SLEEP) \
    $(wildcard include/config/SMP) \
    $(wildcard include/config/MMU) \
    $(wildcard include/config/PROVE_LOCKING) \
    $(wildcard include/config/PANIC_TIMEOUT) \
    $(wildcard include/config/TRACING) \
    $(wildcard include/config/FTRACE_MCOUNT_RECORD) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/align.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/const.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/vdso/const.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/const.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/limits.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/limits.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/types.h \
    $(wildcard include/config/HAVE_UID16) \
    $(wildcard include/config/UID16) \
    $(wildcard include/config/ARCH_DMA_ADDR_T_64BIT) \
    $(wildcard include/config/PHYS_ADDR_T_64BIT) \
    $(wildcard include/config/64BIT) \
    $(wildcard include/config/ARCH_32BIT_USTAT_F_TINODE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/types.h \
  arch/x86/include/generated/uapi/asm/types.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/asm-generic/types.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/int-ll64.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/asm-generic/int-ll64.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi/asm/bitsperlong.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/bitsperlong.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/asm-generic/bitsperlong.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/posix_types.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/stddef.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/stddef.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/compiler_types.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/posix_types.h \
    $(wildcard include/config/X86_32) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi/asm/posix_types_64.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/asm-generic/posix_types.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/vdso/limits.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/linkage.h \
    $(wildcard include/config/ARCH_USE_SYM_ANNOTATIONS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/stringify.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/export.h \
    $(wildcard include/config/MODVERSIONS) \
    $(wildcard include/config/MODULE_REL_CRCS) \
    $(wildcard include/config/HAVE_ARCH_PREL32_RELOCATIONS) \
    $(wildcard include/config/MODULES) \
    $(wildcard include/config/TRIM_UNUSED_KSYMS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/compiler.h \
    $(wildcard include/config/TRACE_BRANCH_PROFILING) \
    $(wildcard include/config/PROFILE_ALL_BRANCHES) \
    $(wildcard include/config/STACK_VALIDATION) \
  arch/x86/include/generated/asm/rwonce.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/rwonce.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/kasan-checks.h \
    $(wildcard include/config/KASAN_GENERIC) \
    $(wildcard include/config/KASAN_SW_TAGS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/kcsan-checks.h \
    $(wildcard include/config/KCSAN) \
    $(wildcard include/config/KCSAN_IGNORE_ATOMICS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/linkage.h \
    $(wildcard include/config/X86_64) \
    $(wildcard include/config/X86_ALIGNMENT_16) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/bitops.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/bits.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/vdso/bits.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/build_bug.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/kernel.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/sysinfo.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/bitops.h \
    $(wildcard include/config/X86_CMOV) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/alternative.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/asm.h \
    $(wildcard include/config/KPROBES) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/rmwcc.h \
    $(wildcard include/config/CC_HAS_ASM_GOTO) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/barrier.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/nops.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/barrier.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/bitops/find.h \
    $(wildcard include/config/GENERIC_FIND_FIRST_BIT) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/bitops/sched.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/arch_hweight.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/cpufeatures.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/required-features.h \
    $(wildcard include/config/X86_MINIMUM_CPU_FAMILY) \
    $(wildcard include/config/MATH_EMULATION) \
    $(wildcard include/config/X86_PAE) \
    $(wildcard include/config/X86_CMPXCHG64) \
    $(wildcard include/config/X86_USE_3DNOW) \
    $(wildcard include/config/X86_P6_NOP) \
    $(wildcard include/config/MATOM) \
    $(wildcard include/config/PARAVIRT_XXL) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/disabled-features.h \
    $(wildcard include/config/X86_SMAP) \
    $(wildcard include/config/X86_UMIP) \
    $(wildcard include/config/X86_INTEL_MEMORY_PROTECTION_KEYS) \
    $(wildcard include/config/X86_5LEVEL) \
    $(wildcard include/config/PAGE_TABLE_ISOLATION) \
    $(wildcard include/config/X86_SGX) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/bitops/const_hweight.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/bitops/instrumented-atomic.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/instrumented.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/bitops/instrumented-non-atomic.h \
    $(wildcard include/config/KCSAN_ASSUME_PLAIN_WRITES_ATOMIC) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/bitops/instrumented-lock.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/bitops/le.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi/asm/byteorder.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/byteorder/little_endian.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/byteorder/little_endian.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/swab.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/swab.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi/asm/swab.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/byteorder/generic.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/bitops/ext2-atomic-setbit.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/log2.h \
    $(wildcard include/config/ARCH_HAS_ILOG2_U32) \
    $(wildcard include/config/ARCH_HAS_ILOG2_U64) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/math.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/div64.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/div64.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/minmax.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/typecheck.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/printk.h \
    $(wildcard include/config/MESSAGE_LOGLEVEL_DEFAULT) \
    $(wildcard include/config/CONSOLE_LOGLEVEL_DEFAULT) \
    $(wildcard include/config/CONSOLE_LOGLEVEL_QUIET) \
    $(wildcard include/config/EARLY_PRINTK) \
    $(wildcard include/config/PRINTK_NMI) \
    $(wildcard include/config/PRINTK) \
    $(wildcard include/config/DYNAMIC_DEBUG) \
    $(wildcard include/config/DYNAMIC_DEBUG_CORE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/init.h \
    $(wildcard include/config/STRICT_KERNEL_RWX) \
    $(wildcard include/config/STRICT_MODULE_RWX) \
    $(wildcard include/config/LTO_CLANG) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/kern_levels.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/cache.h \
    $(wildcard include/config/ARCH_HAS_CACHE_LINE_SIZE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/cache.h \
    $(wildcard include/config/X86_L1_CACHE_SHIFT) \
    $(wildcard include/config/X86_INTERNODE_CACHE_SHIFT) \
    $(wildcard include/config/X86_VSMP) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/ratelimit_types.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/param.h \
  arch/x86/include/generated/uapi/asm/param.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/param.h \
    $(wildcard include/config/HZ) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/asm-generic/param.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/spinlock_types.h \
    $(wildcard include/config/DEBUG_SPINLOCK) \
    $(wildcard include/config/DEBUG_LOCK_ALLOC) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/spinlock_types.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/qspinlock_types.h \
    $(wildcard include/config/NR_CPUS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/qrwlock_types.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/lockdep_types.h \
    $(wildcard include/config/PROVE_RAW_LOCK_NESTING) \
    $(wildcard include/config/PREEMPT_LOCK) \
    $(wildcard include/config/LOCKDEP) \
    $(wildcard include/config/LOCK_STAT) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/rwlock_types.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/dynamic_debug.h \
    $(wildcard include/config/JUMP_LABEL) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/jump_label.h \
    $(wildcard include/config/HAVE_ARCH_JUMP_LABEL_RELATIVE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/jump_label.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/static_call_types.h \
    $(wildcard include/config/HAVE_STATIC_CALL) \
    $(wildcard include/config/HAVE_STATIC_CALL_INLINE) \
  /home/osiris/CoVirt/covirt/src/svm_utils.h \
  /home/osiris/CoVirt/covirt/src/reg_utils.h \

/home/osiris/CoVirt/covirt/src/reg_utils.o: $(deps_/home/osiris/CoVirt/covirt/src/reg_utils.o)

$(deps_/home/osiris/CoVirt/covirt/src/reg_utils.o):

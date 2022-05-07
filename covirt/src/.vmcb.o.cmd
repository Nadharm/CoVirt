cmd_/home/osiris/CoVirt/covirt/src/vmcb.o := gcc -Wp,-MMD,/home/osiris/CoVirt/covirt/src/.vmcb.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-linux-gnu/9/include -I/home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include -I./arch/x86/include/generated -I/home/osiris/CoVirt/testing_playground/linux-5.13/include -I./include -I/home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi -I./arch/x86/include/generated/uapi -I/home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi -I./include/generated/uapi -include /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/compiler-version.h -include /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/kconfig.h -include /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/compiler_types.h -D__KERNEL__ -fmacro-prefix-map=/home/osiris/CoVirt/testing_playground/linux-5.13/= -Wall -Wundef -Werror=strict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -fno-PIE -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Wno-format-security -std=gnu89 -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -fcf-protection=none -m64 -falign-jumps=1 -falign-loops=1 -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3 -mskip-rax-setup -mtune=generic -mno-red-zone -mcmodel=kernel -Wno-sign-compare -fno-asynchronous-unwind-tables -mindirect-branch=thunk-extern -mindirect-branch-register -fno-jump-tables -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-address-of-packed-member -O2 --param=allow-store-data-races=0 -Wframe-larger-than=2048 -fstack-protector-strong -Wimplicit-fallthrough -Wno-unused-but-set-variable -Wno-unused-const-variable -fomit-frame-pointer -fno-stack-clash-protection -Wdeclaration-after-statement -Wvla -Wno-pointer-sign -Wno-stringop-truncation -Wno-array-bounds -Wno-stringop-overflow -Wno-restrict -Wno-maybe-uninitialized -fno-strict-overflow -fno-stack-check -fconserve-stack -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -Wno-packed-not-aligned  -DMODULE  -DKBUILD_BASENAME='"vmcb"' -DKBUILD_MODNAME='"covirt_module"' -D__KBUILD_MODNAME=kmod_covirt_module -c -o /home/osiris/CoVirt/covirt/src/vmcb.o /home/osiris/CoVirt/covirt/src/vmcb.c

source_/home/osiris/CoVirt/covirt/src/vmcb.o := /home/osiris/CoVirt/covirt/src/vmcb.c

deps_/home/osiris/CoVirt/covirt/src/vmcb.o := \
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
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/slab.h \
    $(wildcard include/config/DEBUG_SLAB) \
    $(wildcard include/config/DEBUG_OBJECTS) \
    $(wildcard include/config/FAILSLAB) \
    $(wildcard include/config/MEMCG_KMEM) \
    $(wildcard include/config/KASAN) \
    $(wildcard include/config/HAVE_HARDENED_USERCOPY_ALLOCATOR) \
    $(wildcard include/config/SLAB) \
    $(wildcard include/config/SLUB) \
    $(wildcard include/config/SLOB) \
    $(wildcard include/config/ZONE_DMA) \
    $(wildcard include/config/NUMA) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/gfp.h \
    $(wildcard include/config/HIGHMEM) \
    $(wildcard include/config/ZONE_DMA32) \
    $(wildcard include/config/ZONE_DEVICE) \
    $(wildcard include/config/PM_SLEEP) \
    $(wildcard include/config/CONTIG_ALLOC) \
    $(wildcard include/config/CMA) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/mmdebug.h \
    $(wildcard include/config/DEBUG_VM) \
    $(wildcard include/config/DEBUG_VIRTUAL) \
    $(wildcard include/config/DEBUG_VM_PGFLAGS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/bug.h \
    $(wildcard include/config/GENERIC_BUG) \
    $(wildcard include/config/BUG_ON_DATA_CORRUPTION) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/bug.h \
    $(wildcard include/config/DEBUG_BUGVERBOSE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/instrumentation.h \
    $(wildcard include/config/DEBUG_ENTRY) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/bug.h \
    $(wildcard include/config/BUG) \
    $(wildcard include/config/GENERIC_BUG_RELATIVE_POINTERS) \
    $(wildcard include/config/CFI_CLANG) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/mmzone.h \
    $(wildcard include/config/FORCE_MAX_ZONEORDER) \
    $(wildcard include/config/MEMORY_ISOLATION) \
    $(wildcard include/config/ZSMALLOC) \
    $(wildcard include/config/SHADOW_CALL_STACK) \
    $(wildcard include/config/SWAP) \
    $(wildcard include/config/TRANSPARENT_HUGEPAGE) \
    $(wildcard include/config/MEMCG) \
    $(wildcard include/config/SPARSEMEM) \
    $(wildcard include/config/MEMORY_HOTPLUG) \
    $(wildcard include/config/COMPACTION) \
    $(wildcard include/config/DISCONTIGMEM) \
    $(wildcard include/config/FLAT_NODE_MEM_MAP) \
    $(wildcard include/config/PAGE_EXTENSION) \
    $(wildcard include/config/DEFERRED_STRUCT_PAGE_INIT) \
    $(wildcard include/config/HAVE_MEMORYLESS_NODES) \
    $(wildcard include/config/NEED_MULTIPLE_NODES) \
    $(wildcard include/config/FLATMEM) \
    $(wildcard include/config/SPARSEMEM_VMEMMAP) \
    $(wildcard include/config/SPARSEMEM_EXTREME) \
    $(wildcard include/config/HAVE_ARCH_PFN_VALID) \
    $(wildcard include/config/HOLES_IN_ZONE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/spinlock.h \
    $(wildcard include/config/PREEMPTION) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/preempt.h \
    $(wildcard include/config/PREEMPT_RT) \
    $(wildcard include/config/PREEMPT_COUNT) \
    $(wildcard include/config/DEBUG_PREEMPT) \
    $(wildcard include/config/TRACE_PREEMPT_TOGGLE) \
    $(wildcard include/config/PREEMPT_NOTIFIERS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/list.h \
    $(wildcard include/config/DEBUG_LIST) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/poison.h \
    $(wildcard include/config/ILLEGAL_POINTER_VALUE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/preempt.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/percpu.h \
    $(wildcard include/config/X86_64_SMP) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/percpu.h \
    $(wildcard include/config/HAVE_SETUP_PER_CPU_AREA) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/threads.h \
    $(wildcard include/config/BASE_SMALL) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/percpu-defs.h \
    $(wildcard include/config/DEBUG_FORCE_WEAK_PER_CPU) \
    $(wildcard include/config/AMD_MEM_ENCRYPT) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/thread_info.h \
    $(wildcard include/config/THREAD_INFO_IN_TASK) \
    $(wildcard include/config/GENERIC_ENTRY) \
    $(wildcard include/config/HAVE_ARCH_WITHIN_STACK_FRAMES) \
    $(wildcard include/config/HARDENED_USERCOPY) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/restart_block.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/time64.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/math64.h \
    $(wildcard include/config/ARCH_SUPPORTS_INT128) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/vdso/math64.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/vdso/time64.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/time.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/time_types.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/errno.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/errno.h \
  arch/x86/include/generated/uapi/asm/errno.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/asm-generic/errno.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/asm-generic/errno-base.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/current.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/thread_info.h \
    $(wildcard include/config/VM86) \
    $(wildcard include/config/X86_IOPL_IOPERM) \
    $(wildcard include/config/FRAME_POINTER) \
    $(wildcard include/config/COMPAT) \
    $(wildcard include/config/IA32_EMULATION) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/page.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/page_types.h \
    $(wildcard include/config/PHYSICAL_START) \
    $(wildcard include/config/PHYSICAL_ALIGN) \
    $(wildcard include/config/DYNAMIC_PHYSICAL_MASK) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/mem_encrypt.h \
    $(wildcard include/config/ARCH_HAS_MEM_ENCRYPT) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/mem_encrypt.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi/asm/bootparam.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/screen_info.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/screen_info.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/apm_bios.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/apm_bios.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/ioctl.h \
  arch/x86/include/generated/uapi/asm/ioctl.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/ioctl.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/asm-generic/ioctl.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/edd.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/edd.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/ist.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi/asm/ist.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/video/edid.h \
    $(wildcard include/config/X86) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/video/edid.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/page_64_types.h \
    $(wildcard include/config/DYNAMIC_MEMORY_LAYOUT) \
    $(wildcard include/config/RANDOMIZE_BASE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/kaslr.h \
    $(wildcard include/config/RANDOMIZE_MEMORY) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/page_64.h \
    $(wildcard include/config/X86_VSYSCALL_EMULATION) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/range.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/memory_model.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/pfn.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/getorder.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/cpufeature.h \
    $(wildcard include/config/X86_FEATURE_NAMES) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/processor.h \
    $(wildcard include/config/X86_VMX_FEATURE_NAMES) \
    $(wildcard include/config/STACKPROTECTOR) \
    $(wildcard include/config/X86_DEBUGCTLMSR) \
    $(wildcard include/config/CPU_SUP_AMD) \
    $(wildcard include/config/XEN) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/processor-flags.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi/asm/processor-flags.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/math_emu.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/ptrace.h \
    $(wildcard include/config/PARAVIRT) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/segment.h \
    $(wildcard include/config/XEN_PV) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi/asm/ptrace.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi/asm/ptrace-abi.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/proto.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi/asm/ldt.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi/asm/sigcontext.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/pgtable_types.h \
    $(wildcard include/config/MEM_SOFT_DIRTY) \
    $(wildcard include/config/HAVE_ARCH_USERFAULTFD_WP) \
    $(wildcard include/config/PGTABLE_LEVELS) \
    $(wildcard include/config/PROC_FS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/pgtable_64_types.h \
    $(wildcard include/config/DEBUG_KMAP_LOCAL_FORCE_MAP) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/sparsemem.h \
    $(wildcard include/config/NUMA_KEEP_MEMINFO) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/msr.h \
    $(wildcard include/config/TRACEPOINTS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/msr-index.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/cpumask.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/cpumask.h \
    $(wildcard include/config/CPUMASK_OFFSTACK) \
    $(wildcard include/config/HOTPLUG_CPU) \
    $(wildcard include/config/DEBUG_PER_CPU_MAPS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/bitmap.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/string.h \
    $(wildcard include/config/BINARY_PRINTF) \
    $(wildcard include/config/FORTIFY_SOURCE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/string.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/string.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/string_64.h \
    $(wildcard include/config/ARCH_HAS_UACCESS_FLUSHCACHE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/atomic.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/atomic.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/cmpxchg.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/cmpxchg_64.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/atomic64_64.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/atomic-arch-fallback.h \
    $(wildcard include/config/GENERIC_ATOMIC64) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/atomic-instrumented.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/atomic-long.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi/asm/msr.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/tracepoint-defs.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/static_key.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/desc_defs.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/special_insns.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/irqflags.h \
    $(wildcard include/config/TRACE_IRQFLAGS) \
    $(wildcard include/config/IRQSOFF_TRACER) \
    $(wildcard include/config/PREEMPT_TRACER) \
    $(wildcard include/config/DEBUG_IRQFLAGS) \
    $(wildcard include/config/TRACE_IRQFLAGS_SUPPORT) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/irqflags.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/nospec-branch.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/objtool.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/msr-index.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/unwind_hints.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/orc_types.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/fpu/types.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/vmxfeatures.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/vdso/processor.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/personality.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/personality.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/err.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/bottom_half.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/lockdep.h \
    $(wildcard include/config/DEBUG_LOCKING_API_SELFTESTS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/smp.h \
    $(wildcard include/config/UP_LATE_INIT) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/smp_types.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/llist.h \
    $(wildcard include/config/ARCH_HAVE_NMI_SAFE_CMPXCHG) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/smp.h \
    $(wildcard include/config/X86_LOCAL_APIC) \
    $(wildcard include/config/DEBUG_NMI_SELFTEST) \
  arch/x86/include/generated/asm/mmiowb.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/mmiowb.h \
    $(wildcard include/config/MMIOWB) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/spinlock.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/paravirt.h \
    $(wildcard include/config/PARAVIRT_SPINLOCKS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/qspinlock.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/qspinlock.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/qrwlock.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/qrwlock.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/rwlock.h \
    $(wildcard include/config/PREEMPT) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/spinlock_api_smp.h \
    $(wildcard include/config/INLINE_SPIN_LOCK) \
    $(wildcard include/config/INLINE_SPIN_LOCK_BH) \
    $(wildcard include/config/INLINE_SPIN_LOCK_IRQ) \
    $(wildcard include/config/INLINE_SPIN_LOCK_IRQSAVE) \
    $(wildcard include/config/INLINE_SPIN_TRYLOCK) \
    $(wildcard include/config/INLINE_SPIN_TRYLOCK_BH) \
    $(wildcard include/config/UNINLINE_SPIN_UNLOCK) \
    $(wildcard include/config/INLINE_SPIN_UNLOCK_BH) \
    $(wildcard include/config/INLINE_SPIN_UNLOCK_IRQ) \
    $(wildcard include/config/INLINE_SPIN_UNLOCK_IRQRESTORE) \
    $(wildcard include/config/GENERIC_LOCKBREAK) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/rwlock_api_smp.h \
    $(wildcard include/config/INLINE_READ_LOCK) \
    $(wildcard include/config/INLINE_WRITE_LOCK) \
    $(wildcard include/config/INLINE_READ_LOCK_BH) \
    $(wildcard include/config/INLINE_WRITE_LOCK_BH) \
    $(wildcard include/config/INLINE_READ_LOCK_IRQ) \
    $(wildcard include/config/INLINE_WRITE_LOCK_IRQ) \
    $(wildcard include/config/INLINE_READ_LOCK_IRQSAVE) \
    $(wildcard include/config/INLINE_WRITE_LOCK_IRQSAVE) \
    $(wildcard include/config/INLINE_READ_TRYLOCK) \
    $(wildcard include/config/INLINE_WRITE_TRYLOCK) \
    $(wildcard include/config/INLINE_READ_UNLOCK) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK) \
    $(wildcard include/config/INLINE_READ_UNLOCK_BH) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK_BH) \
    $(wildcard include/config/INLINE_READ_UNLOCK_IRQ) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK_IRQ) \
    $(wildcard include/config/INLINE_READ_UNLOCK_IRQRESTORE) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK_IRQRESTORE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/wait.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/wait.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/numa.h \
    $(wildcard include/config/NODES_SHIFT) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/seqlock.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/mutex.h \
    $(wildcard include/config/MUTEX_SPIN_ON_OWNER) \
    $(wildcard include/config/DEBUG_MUTEXES) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/osq_lock.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/debug_locks.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/ww_mutex.h \
    $(wildcard include/config/DEBUG_WW_MUTEX_SLOWPATH) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/nodemask.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/pageblock-flags.h \
    $(wildcard include/config/HUGETLB_PAGE) \
    $(wildcard include/config/HUGETLB_PAGE_SIZE_VARIABLE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/page-flags-layout.h \
    $(wildcard include/config/KASAN_HW_TAGS) \
    $(wildcard include/config/NUMA_BALANCING) \
  include/generated/bounds.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/mm_types.h \
    $(wildcard include/config/HAVE_ALIGNED_STRUCT_PAGE) \
    $(wildcard include/config/USERFAULTFD) \
    $(wildcard include/config/HAVE_ARCH_COMPAT_MMAP_BASES) \
    $(wildcard include/config/MEMBARRIER) \
    $(wildcard include/config/AIO) \
    $(wildcard include/config/MMU_NOTIFIER) \
    $(wildcard include/config/ARCH_WANT_BATCHED_UNMAP_TLB_FLUSH) \
    $(wildcard include/config/IOMMU_SUPPORT) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/mm_types_task.h \
    $(wildcard include/config/SPLIT_PTLOCK_CPUS) \
    $(wildcard include/config/ARCH_ENABLE_SPLIT_PMD_PTLOCK) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/tlbbatch.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/auxvec.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/auxvec.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/uapi/asm/auxvec.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/rbtree.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/rcupdate.h \
    $(wildcard include/config/PREEMPT_RCU) \
    $(wildcard include/config/TINY_RCU) \
    $(wildcard include/config/TASKS_RCU_GENERIC) \
    $(wildcard include/config/RCU_STALL_COMMON) \
    $(wildcard include/config/NO_HZ_FULL) \
    $(wildcard include/config/RCU_NOCB_CPU) \
    $(wildcard include/config/TASKS_RCU) \
    $(wildcard include/config/TASKS_RCU_TRACE) \
    $(wildcard include/config/TASKS_RUDE_RCU) \
    $(wildcard include/config/TREE_RCU) \
    $(wildcard include/config/DEBUG_OBJECTS_RCU_HEAD) \
    $(wildcard include/config/PROVE_RCU) \
    $(wildcard include/config/RCU_BOOST) \
    $(wildcard include/config/ARCH_WEAK_RELEASE_ACQUIRE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/rcutree.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/rwsem.h \
    $(wildcard include/config/RWSEM_SPIN_ON_OWNER) \
    $(wildcard include/config/DEBUG_RWSEMS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/completion.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/swait.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/uprobes.h \
    $(wildcard include/config/UPROBES) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/uprobes.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/notifier.h \
    $(wildcard include/config/TREE_SRCU) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/srcu.h \
    $(wildcard include/config/TINY_SRCU) \
    $(wildcard include/config/SRCU) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/workqueue.h \
    $(wildcard include/config/DEBUG_OBJECTS_WORK) \
    $(wildcard include/config/FREEZER) \
    $(wildcard include/config/SYSFS) \
    $(wildcard include/config/WQ_WATCHDOG) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/timer.h \
    $(wildcard include/config/DEBUG_OBJECTS_TIMERS) \
    $(wildcard include/config/NO_HZ_COMMON) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/ktime.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/time.h \
    $(wildcard include/config/POSIX_TIMERS) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/time32.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/timex.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/uapi/linux/timex.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/timex.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/tsc.h \
    $(wildcard include/config/X86_TSC) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/vdso/time32.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/vdso/time.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/jiffies.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/vdso/jiffies.h \
  include/generated/timeconst.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/vdso/ktime.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/timekeeping.h \
    $(wildcard include/config/GENERIC_CMOS_UPDATE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/clocksource_ids.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/debugobjects.h \
    $(wildcard include/config/DEBUG_OBJECTS_FREE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/rcu_segcblist.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/srcutree.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/rcu_node_tree.h \
    $(wildcard include/config/RCU_FANOUT) \
    $(wildcard include/config/RCU_FANOUT_LEAF) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/mmu.h \
    $(wildcard include/config/MODIFY_LDT_SYSCALL) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/page-flags.h \
    $(wildcard include/config/ARCH_USES_PG_UNCACHED) \
    $(wildcard include/config/MEMORY_FAILURE) \
    $(wildcard include/config/IDLE_PAGE_TRACKING) \
    $(wildcard include/config/THP_SWAP) \
    $(wildcard include/config/KSM) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/memory_hotplug.h \
    $(wildcard include/config/ARCH_HAS_ADD_PAGES) \
    $(wildcard include/config/HAVE_ARCH_NODEDATA_EXTENSION) \
    $(wildcard include/config/HAVE_BOOTMEM_INFO_NODE) \
    $(wildcard include/config/MEMORY_HOTREMOVE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/mmzone.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/mmzone_64.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/topology.h \
    $(wildcard include/config/USE_PERCPU_NUMA_NODE_ID) \
    $(wildcard include/config/SCHED_SMT) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/arch_topology.h \
    $(wildcard include/config/GENERIC_ARCH_TOPOLOGY) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/percpu.h \
    $(wildcard include/config/NEED_PER_CPU_EMBED_FIRST_CHUNK) \
    $(wildcard include/config/NEED_PER_CPU_PAGE_FIRST_CHUNK) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/topology.h \
    $(wildcard include/config/SCHED_MC_PRIO) \
    $(wildcard include/config/ACPI_CPPC_LIB) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/mpspec.h \
    $(wildcard include/config/EISA) \
    $(wildcard include/config/X86_MPPARSE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/mpspec_def.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/x86_init.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/apicdef.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/topology.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/overflow.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/percpu-refcount.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/kasan.h \
    $(wildcard include/config/KASAN_STACK) \
    $(wildcard include/config/KASAN_VMALLOC) \
    $(wildcard include/config/KASAN_INLINE) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/io.h \
    $(wildcard include/config/MTRR) \
    $(wildcard include/config/X86_PAT) \
  arch/x86/include/generated/asm/early_ioremap.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/early_ioremap.h \
    $(wildcard include/config/GENERIC_EARLY_IOREMAP) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/iomap.h \
    $(wildcard include/config/HAS_IOPORT_MAP) \
    $(wildcard include/config/PCI) \
    $(wildcard include/config/GENERIC_IOMAP) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/pci_iomap.h \
    $(wildcard include/config/NO_GENERIC_PCI_IOPORT_MAP) \
    $(wildcard include/config/GENERIC_PCI_IOMAP) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/asm-generic/io.h \
    $(wildcard include/config/GENERIC_IOREMAP) \
    $(wildcard include/config/VIRT_TO_BUS) \
    $(wildcard include/config/GENERIC_DEVMEM_IS_ALLOWED) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/logic_pio.h \
    $(wildcard include/config/INDIRECT_PIO) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/fwnode.h \
  /home/osiris/CoVirt/testing_playground/linux-5.13/include/linux/vmalloc.h \
    $(wildcard include/config/HAVE_ARCH_HUGE_VMALLOC) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/vmalloc.h \
    $(wildcard include/config/HAVE_ARCH_HUGE_VMAP) \
  /home/osiris/CoVirt/testing_playground/linux-5.13/arch/x86/include/asm/pgtable_areas.h \
  /home/osiris/CoVirt/covirt/src/reg_utils.h \
  /home/osiris/CoVirt/covirt/src/vmcb.h \

/home/osiris/CoVirt/covirt/src/vmcb.o: $(deps_/home/osiris/CoVirt/covirt/src/vmcb.o)

$(deps_/home/osiris/CoVirt/covirt/src/vmcb.o):

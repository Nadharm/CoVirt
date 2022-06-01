#!/bin/bash

export PLAY="`pwd`/../testing_playground"
export KERNEL_ROOT="$PLAY/obj/linux-basic"

echo "Testing playground: $PLAY"
echo "Kernel Root: $KERNEL_ROOT"

make clean KERNEL_ROOT=$KERNEL_ROOT
make KERNEL_ROOT=$KERNEL_ROOT
if [ $? = 0 ]
then
	gcc -static -o unit_tester src/unit_tester.c
	if [ $? = 0 ]
	then	
		cp unit_tester $PLAY/initramfs/busybox/unit_tester
		cp turn_off_logging.sh $PLAY/initramfs/busybox/turn_off_logging.sh
		cp covirt_module.ko $PLAY/initramfs/busybox/covirt_module.ko
		cd $PLAY/initramfs/busybox
		find . -print0 | cpio --null -ov --format=newc | gzip -9 > $PLAY/obj/initramfs-busybox.cpio.gz
		cd $PLAY

		# Important things:
		# -enable-kvm (enables KVM)
		# -cpu host (specifies that we want the spun up box to act like an L1/another host. This enables things like NRIP_SAVE)
		#qemu-system-x86_64 -cpu host,-x2apic -enable-kvm -m 2048 -smp 1 -kernel $PLAY/obj/linux-basic/arch/x86_64/boot/bzImage -initrd obj/initramfs-busybox.cpio.gz -s -append "console=ttyS0 nokaslr" -nographic

		qemu-system-x86_64 -display gtk -cpu host,-x2apic -enable-kvm -m 2048 -smp 1 -kernel $PLAY/obj/linux-basic/arch/x86_64/boot/bzImage -initrd obj/initramfs-busybox.cpio.gz -s -append "nokaslr"

		#sudo qemu-system-x86_64 -enable-kvm -m 2048 -smp 1 -kernel ~/playground/obj/linux-basic/arch/x86_64/boot/bzImage -initrd ~/ramdisk.img -s -append "console=ttyS0 nokaslr" -nographic
	fi
fi

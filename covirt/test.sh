#!/bin/bash

export PLAY="`pwd`/../testing_playground"
export KERNEL_ROOT="$PLAY/obj/linux-basic"

echo "Testing playground: $PLAY"
echo "Kernel Root: $KERNEL_ROOT"

make clean KERNEL_ROOT=$KERNEL_ROOT
make KERNEL_ROOT=$KERNEL_ROOT
if [ $? = 0 ]
then
		
	cp covirt_module.ko $PLAY/initramfs/busybox/covirt_module.ko
	cd $PLAY/initramfs/busybox
	find . -print0 | cpio --null -ov --format=newc | gzip -9 > $PLAY/obj/initramfs-busybox.cpio.gz
	cd $PLAY

	sudo qemu-system-x86_64 -enable-kvm -m 2048 -smp 1 -kernel $PLAY/obj/linux-basic/arch/x86_64/boot/bzImage -initrd obj/initramfs-busybox.cpio.gz -s -append "console=ttyS0 nokaslr" -nographic

	#sudo qemu-system-x86_64 -enable-kvm -m 2048 -smp 1 -kernel ~/playground/obj/linux-basic/arch/x86_64/boot/bzImage -initrd ~/ramdisk.img -s -append "console=ttyS0 nokaslr" -nographic
fi

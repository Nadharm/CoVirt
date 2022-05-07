#!/bin/bash

# Taken from Peter's guide. Ty <3

mkdir testing_playground
cd testing_playground
export PLAY=`pwd`

wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.13.tar.xz
tar xf linux-5.13.tar.xz
ln -s linux-5.13 linux

wget https://busybox.net/downloads/busybox-1.33.2.tar.bz2
tar xf busybox-1.33.2.tar.bz2
ln -s busybox-1.33.2 busybox

mkdir -pv obj/busybox

cd busybox
make O=../obj/busybox defconfig

make O=../obj/busybox menuconfig

# This will bring up a menu system.  Navigate to Settings -> Build static binary (no shared libs)  Turn this option on.   Then exit and be sure to say "yes" when it asks you to save your configuration.

cd $PLAY/obj/busybox
make
make install

cd $PLAY
mkdir -pv initramfs/busybox

cd initramfs/busybox
mkdir -pv {bin,sbin,etc,proc,sys,usr/{bin,sbin}}

cp -av $PLAY/obj/busybox/_install/* .

cp $PLAY/init-temp ./init

chmod +x init

find . -print0 | cpio --null -ov --format=newc | gzip -9 > $PLAY/obj/initramfs-busybox.cpio.gz

cd $PLAY/linux
make O=../obj/linux-basic x86_64_defconfig

cd $PLAY/linux
make O=../obj/linux-basic menuconfig

cd $PLAY/linux
make O=../obj/linux-basic -j 4


# Example Run:
# cd $PLAY
# qemu-system-x86_64 -m 2048 -smp 4 -kernel obj/linux-basic/arch/x86_64/boot/bzImage -initrd obj/initramfs-busybox.cpio.gz


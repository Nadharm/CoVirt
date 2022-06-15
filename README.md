# CoVirt

### STATUS: Functional, still horribly organized and written

A toy virtual-machine based rootkit designed for Linux Kernel v5.13.0 using AMD-V (SVM).

Currently implemented "malicious" services:
* Keylogger
https://user-images.githubusercontent.com/52044930/173870279-a584f691-bc97-42dc-b649-1dd83c478b8a.mp4

* CPUID Instruction intercept
https://user-images.githubusercontent.com/52044930/173870229-c773d6e6-6d13-47c7-bc31-063a0e91abd9.mp4


## Test/run w/ QEMU/KVM + BusyBox
WARNING: This is going to build a 5.13.0 Linux kernel.

You'll need QEMU ofc, so go install that first.

Build Linux Kernel, setup initrd w/ BusyBox

IMPORTANT CONFIG:

BusyBox: 
* "Build static binary" to [Y]

Linux Kernel:
* DYNAMIC_DEBUG to [Y]es
* DYNAMIC_DEBUG_CORE to [Y]es
* GDB_SCRIPTS to [Y]es

```
./setup_playground.sh
```

Now, to test the "covirt_module.ko".
```
cd covirt
sudo ./test.sh  // sudo required for KVM (I believe..)
```

This will bring up the QEMU/KVM system

To run the module:
```
insmod ./covirt_module.ko
```

Note: Messing with the QEMU launch script will probably break stuff

## General Design

Outline for our basic SVM-based hypervisor/vmm implementation (used https://app.diagrams.net to make it :D):

![Alt text](./CoVirt%20Setup%20Diagram.png?raw=true "CoVirt Setup Diagram")

It's not the best outline, but it gets the point across (I hope) and it was made as a guide for development.

References:
- https://www.amd.com/system/files/TechDocs/24593.pdf
- https://www.amd.com/system/files/TechDocs/24594.pdf
- https://github.com/PeterDinda/palacios
- https://www.microsoft.com/en-us/research/wp-content/uploads/2016/02/subvirt.pdf
- "Blue Pill" by Joanna Rutkowska
- https://nixhacker.com/developing-hypervisior-from-scratch-part-1/

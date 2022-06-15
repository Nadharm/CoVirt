# CoVirt (a virtual-machine based rootkit)

## A toy virtual-machine based rootkit designed for Linux Kernel v5.13.0 using AMD-V (SVM).

## Table of Contents

1. [Introduction](#introduction)
2. [Malicious Service Demos](#malicious-service-demos)
3. [How to run/test it out](#test-it-out)
4. [General Design Diagram (this is pretty sick, go look at it)](#general-design)
5. [References](#references)

## Introduction

A hypervisor (virtual machine monitor/VMM) sits logically below a guest operating system (virtual machine/VM), managing access to and emulating certain pieces of hardware for said guest. Ideally, this guest OS would operate no differently than it would directly on top of real hardware, making it unaware of its virtualized state. Due to this privileged position and inherent difficulty of detection, hypervisors present an interesting platform upon which to build malicious services.

CoVirt (our virtual-machine based rootkit) can be simply thought of as "lifting" the rest of the kernel up, and "sliding underneath" to dynamically virtualize it. It basically asserts itself as the hypervisor for the running operating system and forces the rest of the kernel to run on top of it. Currently, once it establishes itself as the hypervisor, CoVirt is able to perform a couple "malicious" services (just basic proof-of-concepts). 

## "Malicious" service demos
**The maliciously implemented services are operating at the hypervisor-level (NOT kernel-level).**

* Keylogger (just set it to output the buffer at 100 bytes, but adding data exfiltration over a network is very possible)

https://user-images.githubusercontent.com/52044930/173870279-a584f691-bc97-42dc-b649-1dd83c478b8a.mp4

* CPUID Instruction intercept (just did it for function number 0x0)

https://user-images.githubusercontent.com/52044930/173870229-c773d6e6-6d13-47c7-bc31-063a0e91abd9.mp4


## Test it out
Our testing environment is just a QEMU/KVM + BusyBox box. 

WARNING: This is going to build a 5.13.0 Linux kernel. If you want to just use your current linux kernel instead of building a new one, you'll need set the KERNEL_ROOT variable to point to the root of your kernel source tree thing. I will maybe add support to streamline this, as it would be rather quick to do, but I'm lazy and no one's actually going to look at this. 

You'll need QEMU ofc, so go install that first.

1. Build Linux Kernel, setup initrd w/ BusyBox

I made this script to automate most of the process. It'll basically just compile BusyBox and a 5.13 kernel for you. Kinda important to make sure your directory setup is the same as mine, as the "test.sh" script relies on that if that's how you'll want to run.
```
./setup_playground.sh
```

IMPORTANT CONFIG:

BusyBox: 
* "Build static binary" to [Y]

Linux Kernel (only needed if you want to debug/develop, although the init binary used for BusyBox might depend on these... I'm way too lazy to check).
* DYNAMIC_DEBUG to [Y]es
* DYNAMIC_DEBUG_CORE to [Y]es
* GDB_SCRIPTS to [Y]es


2. Now, to test the "covirt_module.ko".
```
cd covirt
sudo ./test.sh  // sudo required for KVM (I believe... I promise it's nothing malicious, but check it out yourself if you really care.)
```

This will bring up the QEMU/KVM system


3. To run the module:
```
insmod ./covirt_module.ko
```


4. Modify the Makefile in covirt/ to alter the options/malicious services you're interested in.
```
...
DEBUG_ENABLED = 1
KEYLOGGER = 0
FAKE_CPUID = 1
...
```

Note: Messing with the QEMU launch script will probably break stuff


## General Design

Outline for our basic SVM-based hypervisor/vmm implementation (used https://app.diagrams.net to make it :D):

![Alt text](./CoVirt%20Setup%20Diagram.png?raw=true "CoVirt Setup Diagram")

It's not the best outline, but it gets the point across (I hope) and it was made as a guide for development.

## References:
- https://www.amd.com/system/files/TechDocs/24593.pdf
- https://www.amd.com/system/files/TechDocs/24594.pdf
- https://github.com/PeterDinda/palacios
- https://www.microsoft.com/en-us/research/wp-content/uploads/2016/02/subvirt.pdf
- "Blue Pill" by Joanna Rutkowska
- https://nixhacker.com/developing-hypervisior-from-scratch-part-1/

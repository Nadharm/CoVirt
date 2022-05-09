# CoVirt

### STATUS: Horribly written + broken beyond belief

A toy virtual-machine based rootkit designed for Linux Kernel v5.13.0 using AMD-V (SVM).

## Test/run w/ QEMU
WARNING: This is going to build a 5.13.0 Linux kernel. Make sure you have enough space.

You'll need QEMU ofc, so go install that first.

Build Linux Kernel, setup initrd w/ BusyBox

IMPORTANT CONFIG:

BusyBox: 
"Build static binary" to [Y]

Linux Kernel:
DYNAMIC_DEBUG to [Y]es
DYNAMIC_DEBUG_CORE to [Y]es
GDB_SCRIPTS to [Y]es

```
./setup_playground.sh
```

Now, to test the "covirt_module.ko".
```
cd covirt
./test.sh
```

This will bring up QEMU. I've set "-no-graphic" on, but feel free to change this.

To run the module:
```
insmod ./covirt_module.ko
```

### Debugging stuff
I'll probably automate this step at some point, but for now...

Before loading the module, within QEMU:
```
echo 8 > /proc/sys/kernel/printk
echo 'file kernel/module.c +p' > /sys/kernel/debug/dynamic_debug/control
```

## TODO:
```
Stuff that needs to get done ASAP.

We'll deal with a single-core environment for now.

N:
    - Set up the state-save area of the VMCB
    - Store non-VMCB state (such as general purpose registers)
    - Figure out how to manage RIP to redirect "guest" execution [I think this is done]
Y:
    - Look into post-VMEXIT operation. 
    - Set up the Control Area in the VMCB
```

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

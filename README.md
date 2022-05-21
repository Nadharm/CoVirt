# CoVirt

### STATUS: Minimally Function, still horribly organized and written

A toy virtual-machine based rootkit designed for Linux Kernel v5.13.0 using AMD-V (SVM).

## Test/run w/ QEMU + KVM
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
"-cpu host" is set so that the spun up box will act as an L1 (I think...)

To run the module:
```
insmod ./covirt_module.ko
```

### Debugging stuff

If you installed the kernel with the GDB_SCRIPTS enabled, you can do this:
```
$ add-auto-load-safe-path <path-to-CoVirt>/CoVirt/testing_playground/linux-5.13/scripts/gdb/vmlinux-gdb.py
```

If you chose to set up the Testing Playground, from CoVirt/covirt:
```
$ gdb ../testing_playground/obj/linux-basic/vmlinux
(gdb) target remote:1234
```

After insmod-ing the kernel module, run this so you can reference symbols directly
```
(gdb) lx-symbols
```

```
# These two lines have been added to the qemu run script, leaving them here for possible future reference
# They're just for increasing output and stuff.
# echo 8 > /proc/sys/kernel/printk
# echo 'file kernel/module.c +p' > /sys/kernel/debug/dynamic_debug/control
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

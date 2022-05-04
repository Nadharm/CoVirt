# CoVirt

A toy virtual-machine based rootkit designed for Linux Kernel v5.13.0 using AMD-V (SVM).

### TODO:
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

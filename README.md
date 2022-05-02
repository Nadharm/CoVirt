# CoVirt

A virtual-machine based rootkit designed for Linux Kernel v5.13.0 using AMD-V (SVM).

I'm just using the README as a scratchspace for now :D

The basic outline for how this is going to work and some issues:

1. Check for SVM availability
2. Enable SVM

3. Create the VMCB
4. Store the "Guest" state into VMCB
    - Which parts of these need to be per-CPU and what would that look like?
    - What do we put in RSP and RIP (basically how do we get the kernel to continue execution like normal)
5. Set the Control Area for VMCB

6. Set the VA_HSAVE_PA MSR to VMRUN to save the Host (our VMBR) state.
    - Is this something we need to allocate and set?
    - Is this a per-CPU thing as well?

7. After this, we need to hit "VMRUN" (on each CPU right?)
    
8. Perform our VMEXIT checks and intercepts

9. Start to implement malicious functionality

10. Find out ways to detect our VMBR and then counter them.
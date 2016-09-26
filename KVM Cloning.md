(Normal: first pass.  Italic: next iteration.  Strikethrough: Likely not being implemented.)

Management
==========

- KVM_CREATE_VM -- Create a new kvm instance
- KVM_CREATE_VCPU -- Create a new VCPU
- KVM_RUN -- VMEnter VCPU

MSRs
====

- *KVM_GET_MSR_INDEX_LIST -- Get list of MSRs supported*
- *KVM_GET_MSRS/KVM_SET_MSRS -- Get/set one or more MSRs*

General CPU
===========

- *KVM_SET_BOOT_CPU_ID -- Set bootstrap VCPU id*
- *KVM_GET_SUPPORTED_CPUID -- Gets cpuid flags supported by CPU and kvm*
- *KVM_GET_EMULATED_CPUID -- Gets cpuid flags emulated by kvm*
- KVM_SET_CPUID
- KVM_SET_TSC_KHZ/KVM_GET_TSC_KHZ -- Set tsc frequency for VM
- KVM_SET_GUEST_DEBUG -- Enable/disable debugging

Interrupts
==========

- KVM_INTERRUPT -- Inject hardware interrupt
- KVM_NMI -- Injects an NMI
- KVM_SIGNAL_MSI -- Inject MSI
- KVM_SMI -- Inject SMI
- KVM_GET_VCPU_EVENTS/KVM_SET_VCPU_EVENTS -- Get/set exceptions, interrupts, etc
- *KVM_CREATE_IRQCHIP -- Create kernel-mode interrupt controller*
- *KVM_IRQ_LINE -- Sets interrupt line state*
- *KVM_GET_IRQCHIP/KVM_SET_IRQCHIP -- Get/set interrupt controller state*
- *KVM_SET_GSI_ROUTING -- Sets routing of PCI GSIs to interrupt controller*
- *KVM_GET_LAPIC/KVM_SET_LAPIC -- Gets/sets APIC registers*
- *KVM_CREATE_PIT2 -- Creates kernel-mode PIT2 device*
- *KVM_GET_PIT2/KVM_SET_PIT2 -- Gets/sets PIT2 state*
- *KVM_REINJECT_CONTROL -- Configures PIT reinjections*
- *KVM_IRQFD -- Allows an eventfd to directly trigger a guest interrupt*

Memory
======

- *KVM_GET_DIRTY_LOG -- Get bitmap of dirty pages for region*
- KVM_TRANSLATE -- Translate guest vaddr to guest paddr
- KVM_SET_USER_MEMORY_REGION -- Create/update physical memory slots
- *KVM_SET_IDENTITY_MAP_ADDR -- Unknown*
- KVM_IOEVENTFD -- Maps an event handler to pio/mmio

CPU State
=========

Set methods here should be lazy, only pushing state to the CPU when it's about to run again.  This will limit the number of roundtrips that need to be made through the kernel.

- KVM_GET_REGS/KVM_SET_REGS
- KVM_GET_ONE_REG/KVM_SET_ONE_REG -- Gets/sets a single register
- KVM_GET_SREGS/KVM_SET_SREGS
- KVM_GET_FPU/KVM_SET_FPU
- KVM_GET_XSAVE/KVM_SET_XSAVE -- Get/set XSAVE struct
- KVM_GET_XCRS/KVM_SET_XCRS -- Get/set XCRs
- KVM_GET_DEBUGREGS/KVM_SET_DEBUGREGS
- *KVM_SET_TSS_ADDR -- Sets the paddr of the TSS*
- *KVM_GET_MP_STATE/KVM_SET_MP_STATE -- Gets/sets multiprocessing state*

Virtual Devices
===============

- *KVM_CREATE_DEVICE -- Creates a new virtual device*
- *KVM_HAS_DEVICE_ATTR/KVM_GET_DEVICE_ATTR/KVM_SET_DEVICE_ATTR -- Check/get/set device attribute*

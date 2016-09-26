#include "libhyper.hpp"

Hypervisor::Hypervisor() {
#ifdef MAC
	bailout(hv_vm_create(HV_VM_DEFAULT));
#else
	unsupported();
#endif
}

Hypervisor::~Hypervisor() {
	for(auto cpu : cpus)
		delete cpu;

#ifdef MAC
	bailout(hv_vm_destroy());
#else
	unsupported();
#endif
}

VCpu *Hypervisor::createVCpu() {
	auto vcpu = new VCpu(this);
	cpus.push_back(vcpu);
	return vcpu;
}

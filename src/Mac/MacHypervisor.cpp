#include <libhyper.hpp>

MacHypervisor::MacHypervisor() {
    bailout(hv_vm_create(HV_VM_DEFAULT));
}

MacHypervisor::~MacHypervisor() {
    for(auto cpu : cpus)
	    delete cpu;
    
    bailout(hv_vm_destroy());
}

VCpu *MacHypervisor::createVCpu() {
	auto vcpu = new MacVCpu(this);
	cpus.push_back(vcpu);
	return vcpu;
}

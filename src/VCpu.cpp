#include <libhyper.hpp>

VCpu::VCpu(Hypervisor *_hv) {
	hv = _hv;

#ifdef MAC
	bailout(hv_vcpu_create(&pvcpu, HV_VCPU_DEFAULT));
#else
	unsupported();
#endif
}

VCpu::~VCpu() {
#ifdef MAC
	bailout(hv_vcpu_destroy(pvcpu));
#else
	unsupported();
#endif
}
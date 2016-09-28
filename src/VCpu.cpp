#include <libhyper.hpp>

VCpu::VCpu(Hypervisor *_hv) : rax(this) {
	hv = _hv;
}

VCpu::~VCpu() {
	cout << "Killing vcpu" << endl;
}

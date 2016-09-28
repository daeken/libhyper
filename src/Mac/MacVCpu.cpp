#include <libhyper.hpp>

MacVCpu::MacVCpu(Hypervisor *hv) : VCpu(hv) {
    memset(&gprDirty, 0, sizeof(gprDirty));
	bailout(hv_vcpu_create(&pvcpu, HV_VCPU_DEFAULT));
}

MacVCpu::~MacVCpu() {
	bailout(hv_vcpu_destroy(pvcpu));
}

uint64_t MacVCpu::gpr(uint8_t num) {
	if(!gprRead[num]) {
		gprRead[num] = true;
		//hv_vcpu_read_register(pvcpu, num, &gprs[num]); // XXX: Translate register number to OS X registers 
	}
	return gprs[num];
}

void MacVCpu::gpr(uint8_t num, uint64_t value) {
	gprs[num] = value;
	gprDirty[num] = true;
}

void MacVCpu::run() {
	for(auto i = 0; i < 16; ++i) {
		if(gprDirty[i]) {
			// hv_vcpu_write_register(pvcpu, i, gprs[i]); // XXX: Translate register number to OS X registers
		}
		gprDirty[i] = gprRead[i] = false;
	}
}

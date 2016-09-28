#pragma once

#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>

#define VCPU_CLASS MacVCpu

class MacVCpu : public VCpu {
public:
    MacVCpu(Hypervisor *);
    ~MacVCpu();

	uint64_t gpr(uint8_t num);
	void gpr(uint8_t num, uint64_t value);

	void run();
private:
	bool gprRead[16];
	bool gprDirty[16];

	hv_vcpuid_t pvcpu;
};

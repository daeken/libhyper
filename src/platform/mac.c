#include "libhyper.h"

int libhyper_platform_init() {
	debug("Initializing Mac\n");
	if(hv_vm_create(HV_VM_DEFAULT))
		return -1;
	return 0;
}

int libhyper_platform_destroy() {
	debug("Destroying Mac\n");
	if(hv_vm_destroy())
		return -1;
	return 0;
}

int libhyper_platform_vcpu_create(vcpu_t *vcpu) {
	if(hv_vcpu_create(&vcpu->pvcpu, HV_VCPU_DEFAULT))
		return -1;
	return 0;
}

int libhyper_platform_vcpu_destroy(vcpu_t *vcpu) {
	if(hv_vcpu_destroy(vcpu->pvcpu))
		return -1;
	return 0;
}

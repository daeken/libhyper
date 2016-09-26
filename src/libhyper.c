#include "libhyper.h"

int libhyper_init() {
	debug("Initializing libhyper\n");
	return libhyper_platform_init();
}

int libhyper_destroy() {
	debug("Destroying libhyper\n");
	int ret = libhyper_platform_destroy();

	return ret;
}

vcpu_t *libhyper_vcpu_create() {
	vcpu_t *vcpu = malloc(sizeof(vcpu_t));
	if(vcpu == NULL)
		goto error;
	if(libhyper_platform_vcpu_create(vcpu))
		goto error;
	return vcpu;

error:
	if(vcpu)
		free(vcpu);
	return NULL;
}

int libhyper_vcpu_destroy(vcpu_t *vcpu) {
	if(!vcpu)
		return 0;

	if(libhyper_platform_vcpu_destroy(vcpu))
		goto error;
	return 0;

error:
	free(vcpu);
	return -1;
}

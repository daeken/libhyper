#ifndef __LIBHYPER_H__
#define __LIBHYPER_H__

#include <stdlib.h>

#ifdef DEBUG
#include <stdio.h>
#define debug(args...) printf(args);
#else
#define debug(args...)
#endif

#ifdef MAC
#include "platform/mac.h"
#endif

typedef struct vcpu_s {
	platform_vcpu_t pvcpu;
} vcpu_t;

int libhyper_init();
int libhyper_destroy();
vcpu_t *libhyper_vcpu_create();
int libhyper_vcpu_destroy(vcpu_t *vcpu);

int libhyper_platform_init();
int libhyper_platform_destroy();
int libhyper_platform_vcpu_create(vcpu_t *vcpu);
int libhyper_platform_vcpu_destroy(vcpu_t *vcpu);

#endif

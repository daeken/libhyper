#pragma once

#ifdef MAC
#include <Hypervisor/hv.h>
#include <Hypervisor/hv_vmx.h>
#endif

#include <list>
#include <iostream>
using namespace std;

#define bailout(x) do { if(x) { cout << "Failed " << #x << endl; exit(1); } } while(0) // XXX: Exceptions
#define unsupported() do { cout << "Unsupported operation. " << __FILE__ << ":" << __LINE__; exit(1); } while(0)

class Hypervisor;
class VCpu;

class VCpu {
public:
	VCpu(Hypervisor *);
	~VCpu();

private:
	Hypervisor *hv;

#ifdef MAC
	hv_vcpuid_t pvcpu;
#endif
};

class Hypervisor {
public:
	Hypervisor();
	~Hypervisor();

	VCpu *createVCpu();

private:
	list<VCpu *> cpus;
};

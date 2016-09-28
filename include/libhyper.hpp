#pragma once

#include <list>
#include <iostream>
#include <stdint.h>
using namespace std;

#define bailout(x) do { if(x) { cout << "Failed " << #x << endl; exit(1); } } while(0) // XXX: Exceptions
#define unsupported() do { cout << "Unsupported operation. " << __FILE__ << ":" << __LINE__ << endl; exit(1); } while(0)

class Hypervisor;
class VCpu;

class VCpu {
private:
	template <uint8_t num>
	class Register {
		VCpu *vcpu;
	
	public:
		Register(VCpu *vcpu) : vcpu(vcpu) {}
		Register<num>& operator=(const uint64_t value) {
			vcpu->gpr(num, value); 
			return *this;
		}
		operator uint64_t() const {
			return vcpu->gpr(num);
		}
	};
public:
	VCpu(Hypervisor *);
	virtual ~VCpu();

	virtual uint64_t gpr(uint8_t num) = 0;
	virtual void gpr(uint8_t num, uint64_t value) = 0;

	void run();

	Register<0> rax;

protected:
	Hypervisor *hv;
	uint64_t gprs[16];
};

class Hypervisor {
public:
	Hypervisor();
	~Hypervisor();

	VCpu *createVCpu();

protected:
	list<VCpu *> cpus;
};

#ifdef MAC
#include <Mac.hpp>
#endif

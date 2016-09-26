#include <iostream>

#include <libhyper.hpp>

int main() {
	cout << "Starting test" << endl;

	Hypervisor *hv = new Hypervisor();

	VCpu *cpu0 = hv->createVCpu();

	delete hv;

	return 0;
}

#include <iostream>

#include <libhyper.hpp>

int main() {
	cout << "Starting test" << endl;

	auto hv = new Hypervisor();
	auto vcpu0 = hv->createVCpu();

	cout << vcpu0->rax << endl;
	vcpu0->rax = 15;
	cout << vcpu0->rax << endl;

	delete hv;

	return 0;
}

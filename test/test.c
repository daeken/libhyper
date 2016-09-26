#include <libhyper.h>

#define bailout(x) do { printf(#x "\n"); if(x) { printf("Bailout: " #x "\n"); return -1; } } while(0)
#define pbailout(x) do { printf(#x "\n"); if(!(x)) { printf("Bailout.\n"); return -1; } } while(0)

int main() {
	printf("Starting test.\n");

	bailout(libhyper_init());

	vcpu_t *vcpu;

	pbailout(vcpu = libhyper_vcpu_create());

	bailout(libhyper_vcpu_destroy(vcpu));

	bailout(libhyper_destroy());

	return 0;
}

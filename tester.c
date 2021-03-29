#include "swifft16/swifft-avx2-16.c"

//! \brief Measure RDTSC at start of segment
//! \returns the RDTSC measurement
inline uint64_t rdtsc_start() {
        uint32_t low, high;
        __asm__ __volatile__ (
                "xorl %%eax,%%eax \n    cpuid"
                ::: "%rax", "%rbx", "%rcx", "%rdx" );
        __asm__ __volatile__ (
                "lfence;rdtsc" : "=a" (low), "=d" (high));
                return (uint64_t)high << 32 | low;
}

//! \brief Measure RDTSC at end of segment
//! \returns the RDTSC measurement
inline uint64_t rdtsc_stop() {
        uint32_t low, high;
        __asm__ __volatile__ (
                "lfence;rdtsc" : "=a" (low), "=d" (high));
        __asm__ __volatile__ (
                "xorl %%eax,%%eax \n    cpuid"
                ::: "%rax", "%rbx", "%rcx", "%rdx" );
                return (uint64_t)high << 32 | low;
}


int main(int argc, char **argv)
{
	int xbyte[16][4] align = {0};
	vec A[16][4] align = {0};
	u8 key[72] align = {0};

	memset(Y, 0, sizeof(vec)*16*4);

	int n = 1000000;
	uint64_t t0 = rdtsc_start();
	for (int i=0; i<n; i++) {
		SWIFFT(xbyte, A, key);
	}
	uint64_t t1 = rdtsc_stop();
	float cycles_per_round = 1.0*(t1 - t0)/n;
	float cycles_per_byte = cycles_per_round / 128;
	printf("%d SWIFFT16 rounds: cycles/round=%f cycles/byte=%f\n", n, cycles_per_round, cycles_per_byte);

	return 0;
}

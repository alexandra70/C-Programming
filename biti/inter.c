#include<stdio.h>
#include<limits.h>

#define SET_SIZE 100  
#define int_size 32
int main() {

	unsigned int n, m = 0;
	scanf("%u", &n);
 
	unsigned int numar_nou = UINT_MAX - n;
	
	unsigned int mask = 0;
	for (int i = 0; i < int_size; i++) {

		mask = 1 << i;

		if (n & mask) {
			continue;
		}
		else {
			m += mask;
			continue;
		}
	}


	printf("%u  %u\n", m, numar_nou);

	return 0;

}

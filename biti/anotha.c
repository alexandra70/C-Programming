#include<stdio.h>
#include<limits.h>

#define SET_SIZE 100  
#define int_size 32

int solo(int n) {

	int bits = 0;
	int numar;

	for (int i = 0; i < n; i++) {
		scanf("%d", &numar);
		if ((bits << (31 - numar) >> 31) == 0) {
			bits += 1 << numar;
		}

		else {
			bits -= 1 << numar;
		}
	}
	printf("%d\n", bits);

	int k = 0;
	while (bits > 1) {
		bits = bits >> 1;
		k++;
	}
	return k;
}

int follow_up(int n) {

	int numar;
	int bits = 0;
	int k = 0;

	for (int i = 0; i < (2*n - 1); i++) {
		scanf("%d", &numar);
		if ((bits << (31 - numar) >> 31) == 0) {
			bits += 1 << numar;
		}
		else {
			bits -= 1 << numar;
		}

	}

	while (bits > 1) {
		bits = bits >> 1;
		k++;
	}
	return k;
}

void follow_up2(int n) {

	int numar;
	int bits = 0;
	int k = 0;

	for (int i = 0; i < (2*n + 2); i++) {
		scanf("%d", &numar);
		if ((bits << (31 - numar) >> 31) == 0) {
			bits += 1 << numar;
		}
		else {
			bits -= 1 << numar;
		}

	}

	for(int i = 0; i < int_size; i++){
		int mask = 1 << i;
		int res = mask & bits;
		if (res) {
			while (res > 1) {
				res = res >> 1;
				k++;
			}
			printf("%d ", k);
			k = 0;
		}
	}
	printf("\n");
}


int main() {

	int n;
	scanf("%d", &n);

	/*int k = solo(n);
	printf("%d\n", k);
	
	int kk = follow_up(n);
	printf("%d\n", kk);*/

	follow_up2(n);

	return 0;

}

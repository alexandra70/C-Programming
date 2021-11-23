#include<stdio.h>

//#define MAX 10


//int verifica(int n, )
int main() {
	int n;
	scanf("%d", &n);

	int v[100];

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int ok = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 0) {
			ok ++;
		}
	}
	//printf("%d\n", ok);
	if (ok == n) {
		printf("1");
	}
	else
		printf("0");

	printf("\n");
	return 0;
}
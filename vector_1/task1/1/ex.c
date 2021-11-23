#include<stdio.h>

//#define MAX 10

int main() {
	int n;
	scanf("%d", &n);


	int v[100];

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	//for (int i = 0; i < n; i++) {
	//	printf("%d ", v[i]);
	//}

	for (int i = 0; i < n; i++) {
		if (v[i] % v[n - 1] == 0) {
			printf("%d ", v[i]);
		}
	
	}
	printf("\n");

	return 0;
}
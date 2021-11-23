#include<stdio.h>

#define MAX 100
int main() {
	int n, k;
	scanf("%d", &n);

	int v[MAX];
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			printf("%d ", v[i]);
		}
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		if (i % 2 ) {
			printf("%d ", v[i]);
		}
	}
	
	//printf("\n");
	return 0;

}
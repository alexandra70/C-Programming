#include<stdio.h>

#define MAX 100
int main() {
	int n, k;
	scanf("%d", &n);

	int v[100];
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	scanf("%d", &k);
	//1 2 3 4
	//2 3 4
	if (k >= 0 && k <= n) {
		for (int i = k; i < n; i++) {
			v[i] = v[i + 1];
		}
		n--;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	//printf("\n");
	return 0;

}
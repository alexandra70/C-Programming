#include<stdio.h>

//#define MAX 10

int main() {
	int n;
	scanf("%d", &n);

	int min = 1000;
	int max = 0;
	int v[100];

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int k = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] < v[i + 1]) {
			k++;
			//printf("%d\n", k);
		}
	}
	//printf("%d\n", k);

	if ((k == n) || (k == (n - 1))) {
		printf("1\n");
	}

	else
		printf("0\n");
	return 0;
}
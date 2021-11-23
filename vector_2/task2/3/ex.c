#include<stdio.h>

#define MAX 100
int main() {
	int n;
	scanf("%d", &n);

	int v[100];
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int k, schimb;
	scanf("%d", &k);

	//printf("\n");

	for (int i = 0; i < k; i++) {
		for (int j = i; j < k; j++) {
			if (v[i] > v[j]) {
				schimb = v[i];
				v[i] = v[j];
				v[j] = schimb;
			}
		}
	}
	for (int i = k; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (v[i] < v[j]) {
				schimb = v[i];
				v[i] = v[j];
				v[j] = schimb;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);

	}
	printf("\n");
		return 0;
	
}
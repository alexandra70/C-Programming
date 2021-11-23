#include<stdio.h>


#define MAX 100


int main() {
	int n;
	int prim = 1;
	scanf("%d", &n);

	int v[MAX];
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 2; j < v[i]/2; j++) {
			if (v[i] % j == 0)
				prim = 0;
			else
				printf("%d", v[i]);
		}
	}

	return 0;

}
#include<stdio.h>

//#define MAX 10


//int verifica(int n, )
int main() {
	int n;
	scanf("%d", &n);


	int v[100];
	int a, b;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	//printf("\n");
	int k;
	scanf("%d", &k);
	
	for (int j = 0; j < k; j++) {
		for (int i = 0; i < n-1; i++) {
			int schimb = v[i];
			v[i] = v[i + 1];
			v[i + 1] = schimb;
		}
	}

	//printf("%d\n", ok);
	//printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}

	printf("\n");
	
	return 0;
}
#include<stdlib.h>
#include<stdio.h>

#define INCR 100


int** alloc_matrix(int n, int m) {

	int** a = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		//a[i] = (int*)malloc(m * sizeof(int));
		a[i] = calloc(m, sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) {
				a[i][j] = 1;
			}
		}
	}

	return a;
}

void print_matrix(int** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main() {

	int n;
	int m;
	scanf("%d%d", &n, &m);

	int** a = alloc_matrix(n, m);



	print_matrix(a, n, m);


	for (int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);


	return 0;
}

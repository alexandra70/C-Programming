/*
S� se scrie un program care cite�te de la tastatur� dou� matrice :
una inferior triunghiular�(toate elementele de deasupra diagonalei
principale sunt nule), �i cealalt� superior triunghiular�.Ele vor fi
reprezentate �n memorie c�t mai compact cu putin��(far� a stoca �i
zerourile de deasupra, respectiv dedesubtul diagonalei).Se va calcula
apoi produsul celor matrice, �i se va afi�a.
*/
#include<stdio.h>
#include<stdlib.h>


int main() {
	int n;
	scanf("%d", &n);

	int** a = (int**)malloc(n * sizeof(int*));
	int** b = (int **)malloc(n * sizeof(int*));


	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++) {	
			if (i < j)
				a[i][j] = 0;
			else
				scanf("%d", &a[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	for (int i = 0; i < n; i++) {

		b[i] = (int*)malloc(n * sizeof(int));

		for (int j = 0; j < n; j++) {
			if (j < i) {
				b[i][j] = 0;
			}
			else
				scanf("%d", &b[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", b[i][j]);
		}
		printf("\n");
	}
	int** c = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		c[i] = (int*)calloc(n, sizeof(int));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
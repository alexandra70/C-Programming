/*
1. Scrieþi un program care citeºte de la tastaturã un numãr natural n 
ºi construieºte în memorie o
 matrice cu n linii ºi n coloane ale cãrei elemente vor primi 
 valori dupã cum urmeazã:

elementele aflate pe diagonala principalã a matricei vor primi valoarea 0

elementele de pe prima coloanã	 cu excepþia celui aflat pe diagonala
principalã vor primi valoarea n

elementele de pe a doua coloanã	 cu excepþia celui aflat pe 
diagonala principalã vor primi valoarea n-1
…
elementele de pe ultima coloanã	 cu excepþia celui aflat pe 
diagonala principalã vor primi valoarea 1



*/

#include<stdio.h>

#define MAX 1000

void print_matrix(int a[MAX][MAX], int n)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

}

void make_matrix(int a[MAX][MAX], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				a[i][j] = 0;
			}
			else if (i != j) {
					a[i][j] = n - j;
				
			}
		}
	}
}

int main() {

	int n, matrix[MAX][MAX];

	scanf("%d", &n);

	make_matrix(matrix, n);

	print_matrix(matrix, n);

	return 0;
}


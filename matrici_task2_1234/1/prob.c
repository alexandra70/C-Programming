/*
1. Scrie�i un program care cite�te de la tastatur� un num�r natural n 
�i construie�te �n memorie o
 matrice cu n linii �i n coloane ale c�rei elemente vor primi 
 valori dup� cum urmeaz�:

elementele aflate pe diagonala principal� a matricei vor primi valoarea 0

elementele de pe prima coloan�	 cu excep�ia celui aflat pe diagonala
principal� vor primi valoarea n

elementele de pe a doua coloan�	 cu excep�ia celui aflat pe 
diagonala principal� vor primi valoarea n-1
�
elementele de pe ultima coloan�	 cu excep�ia celui aflat pe 
diagonala principal� vor primi valoarea 1



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


/*
2. Scrie�i un program care cite�te de la tastatur� dou� numere naturale nenule 
n �i m �i construie�te
 �n memorie o matrice cu n linii �i m coloane astfel �nc�t	 
 parcurg�nd tabloul linie cu linie de sus
 �n jos �i fiecare linie de la st�nga la dreapta	
 s� se ob�in� �irul primelor n*m p�trate perfecte impare
	 ordonat strict cresc�tor.

*/

#include<stdio.h>

#define MAX 1000

void print_matrix(int a[MAX][MAX], int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

}

void make_matrix(int a[MAX][MAX], int n, int m) {
	
	a[0][0] = 1;
	for (int i = 0; i < n; i++) {
		a[i][0] = (2 * m * i + 1);
		for (int j = 0; j < m; j++) {

			a[i][j + 1] = a[i][j] + 2;

		}
	}
}

void square_matrix(int a[MAX][MAX], int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = a[i][j] * a[i][j];
		}
	}
}

int main() {

	int n, m, matrix[MAX][MAX];

	scanf("%d%d", &n, &m);

	make_matrix(matrix, n, m);

	square_matrix(matrix, n, m);

	print_matrix(matrix, n, n);

	return 0;
}


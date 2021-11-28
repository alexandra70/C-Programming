/*
2. Scrieþi un program care citeºte de la tastaturã douã numere naturale nenule 
n ºi m ºi construieºte
 în memorie o matrice cu n linii ºi m coloane astfel încât	 
 parcurgând tabloul linie cu linie de sus
 în jos ºi fiecare linie de la stânga la dreapta	
 sã se obþinã ºirul primelor n*m pãtrate perfecte impare
	 ordonat strict crescãtor.

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


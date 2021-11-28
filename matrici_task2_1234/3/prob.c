/*

3. Scrieþi un program care citeºte de la tastaturã douã numere naturale 
nenule n ºi m ºi care construieºte
 în memorie ºi apoi afiºeazã o matrice A cu n linii ºi m coloane 
 astfel încât prin parcurgerea acesteia linie
 cu linie de sus în jos ºi fiecare linie de la stânga la dreapta	 
 se obþin în ordine descrescãtoare toate
 numerele naturale de la 1 la m*n.

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

void make_matrix_continue(int a[MAX][MAX], int n, int m) {

	int k = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = k++;

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

void sort_vector(int a[MAX][MAX], int n, int m) {

	int v[MAX * MAX];
	int  k = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v[k++] = a[i][j];
		}
	}

	for (int k = 0; k < n * m; k++) {
		for (int q = k; q < n * m; q++) {
			if (v[k] < v[q]) {
				int schimb = v[k];
				v[k] = v[q];
				v[q] = schimb;

			}

		}
	}
	//for (int k = 0; k < n * m; k++)
		//printf("%d ", v[k]);
	//printf("\n");

	k = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = v[k++];
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}*/

}


int main() {

	int n, m, matrix[MAX][MAX];

	scanf("%d%d", &n, &m);

	make_matrix_continue(matrix, n, m);

	//square_matrix(matrix, n, m);

	//print_matrix(matrix, n, n);

	sort_vector(matrix, n, m);

	print_matrix(matrix, n, m);

	return 0;
}


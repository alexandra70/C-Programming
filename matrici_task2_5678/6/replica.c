/*
6. Se citeste o matrice cu N linii si M coloane.
Urmeaza Q query-uri de forma: x1 y1 x2 y2.
Sa se afiseze suma elementelor dintre cele 2 pozitii.

Input               Output
3 3                 12
1 2 3               28
4 5 6
7 8 9
2
0 0 1 1
1 1 2 2

*/

#include<stdio.h>

#define MAX 1000


void read_the_matrix(int mat[MAX][MAX], int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

}
void read_the_query(int query[MAX][MAX], int interogare) {

	for (int i = 0; i < interogare; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &query[i][j]);
		}
	}

}

void print_matrix(int mat[MAX][MAX], int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (j == m - 1) {
				printf("%d", mat[i][j]);
			}
			else
				printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

}

void inter(int matrix[MAX][MAX], int query[MAX][MAX], int n, int m, int interogare) {
	
	int a ,b;
	for (int i = 0; i < interogare; i++) {

		int suma = 0;

		int a = query[i][0];
		int b = query[i][1];
		int c = query[i][2];
		int d = query[i][3];

		for (int f = a; f <= c; f++) {
			for (int l = b; l <= d; l++) {
				suma += matrix[f][l];
			}
		}

		printf("%d", suma);

		printf("\n");
	}
	
}


int main() {

	int n, m, matrix[MAX][MAX], query[MAX][MAX];

	int interogare;

	scanf("%d%d", &n, &m);

	read_the_matrix(matrix, n, m);

	scanf("%d", &interogare);

	read_the_query(query, interogare);

	//print_matrix(matrix, n, m);

	inter(matrix, query, n, m, interogare);
	

	return 0;
}


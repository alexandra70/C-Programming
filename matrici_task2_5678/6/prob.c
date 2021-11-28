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

void read_the_matrix(int mat[MAX][MAX], int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	 
}

void transform_the_query_into_sum(int query[MAX][MAX], int matrix[MAX][MAX], int interogare) {


	for (int i = 0; i < interogare; i++) {

		int j = 0;
		int x1 = query[i][j];
		int y1 = query[i][j + 1];
		int x2 = query[i][j + 2];
		int y2 = query[i][j + 3];

		int suma;
		//printf("%d ", x1);
		//printf("%d ", y1);
		//printf("%d ", x2);
		//printf("%d\n", y2);
		//printf("%d ", matrix[x1][y1]);
		//printf("%d ", matrix[x2][y2]);

		int suma_pe_linie = 0;

		for (int a = x1; a <= x2; a++) {
			suma = 0;
			for (int b = y1; b <= y2; b++) {

				suma += matrix[a][b];
				//printf("elem-%d ", matrix[a][b]);
				//printf("suma-%d ", suma);
				

			}
			suma_pe_linie += suma;
			//printf("suma-%d ", suma_pe_linie);
			//printf("\n");
		}
		printf("%d", suma_pe_linie);
		printf("\n");
	}

}

int main() {

	int n, m, matrix[MAX][MAX], query[MAX][MAX], x, y;

	int interogare;

	scanf("%d%d", &n, &m);

	read_the_matrix(matrix, n, m);

	scanf("%d", &interogare);

	read_the_query(query, interogare);

	//print_matrix(matrix, n, m);

	//print_matrix(query, interogare, 4);

	transform_the_query_into_sum(query, matrix, interogare);

	return 0;
}


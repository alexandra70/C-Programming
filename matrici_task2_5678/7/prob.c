/*

7. Se citeste o matrice cu N linii si M coloane.
Sa se afiseze matricea in zig-zag (pe linii)

Input               Output
3 3
1 2 3               1 2 3 6 5 4 7 8 9
4 5 6
7 8 9

*/

#include<stdio.h>
#define MAX 1000

void print_matrix(int mat[MAX][MAX], int n, int m) {

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

void print(int mod[MAX][MAX], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (j == m - 1 && i == n-1) {
				printf("%d", mod[i][j]);
			}
			else 
			printf("%d ", mod[i][j]);
		}
	}
	printf("\n");
}

void read_the_matrix(int mat[MAX][MAX], int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
}

void modif_the_matrix(int mod[MAX][MAX], int mat[MAX][MAX], int n, int m) {

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i % 2 == 0) {
				mod[i][j] = mat[i][j];
				//printf("%d ", mod[i][j]);
			}

			if (i % 2 != 0) {
				mod[i][j] = mat[i][m-1-j];
				//printf("%d --- where to find %d ", mat[i][j], k);
			}
			//printf("%d ", mat[i][j]);
		}
		//printf("\n");
	}
}


int main() {

	int n, m, matrix[MAX][MAX], mod[MAX][MAX] = { 0 };

	scanf("%d%d", &n, &m);

	read_the_matrix(matrix, n, m);

	//print_matrix(matrix, n, m);

	modif_the_matrix(mod, matrix, n, m);
	
	print(mod, n, m);

	return 0;
}


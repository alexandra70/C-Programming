/*

5. Se citeste o matrice cu N linii si M coloane.
Sa se creeze si printeze o noua matrice ce reprezinta
matricea initiala rotita cu 90 de grade
 in sensul acelor de ceasornic. (Extra: Cum s-ar rezolva problema
 daca nu am avea voie cu memorie suplimentara(in place)?)

Input
4 4                 Output
11 12 13 14         41 31 21 11
21 22 23 24         42 32 22 12
31 32 33 34         43 33 23 13
41 42 43 44         44 34 24 14



*/

#include<stdio.h>

#define MAX 1000

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

void read__the_matrix(int mat[MAX][MAX], int n, int m) {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

}


void make_the_matrix(int mat[MAX][MAX], int n, int m) {

	//facem patrate
	//schimbam intre ele 
	for (int i = 0; i < n / 2; i++) {
		for (int j = i; j < n - i - 1; j++) {

			//mat[i][j] sus top line
			//mat[j][n-i-1] right column
			//mat[n-i-1][n-j-1] under line
			//mat[n-j-1][i] left column

			int retin_ceva_ce_se_pierde_altfel = mat[i][j];
			mat[i][j] = mat[n - j - 1][i];
			mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
			mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
			mat[j][n - i - 1] = retin_ceva_ce_se_pierde_altfel;

		}

	}
}

int main() {

	int n, m, matrix[MAX][MAX];

	scanf("%d%d", &n, &m);
	
	read__the_matrix(matrix, n, m);

	make_the_matrix(matrix, n, m);

	if (n == m) {
		print_matrix(matrix, n, n);
	}

	if(n > m){
		print_matrix(matrix, m, n);
	}

	if (n < m) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d", matrix[j][i]);
			}
			printf("\n");
		}
	}
	

	return 0;
}


/*

4. Scrieþi un program care citeºte de la tastaturã trei numere naturale 
n	 a	 b ºi construieºte în memorie
 o matrice cu n linii ºi n coloane formatã numai din valori
 0	1	2	 3 ºi 4 astfel încât:
 elementele aflate pe linia a sau coloana b sunt egale cu 0	 
 cele aflate deasupra liniei a ºi la stânga coloanei b sunt egale cu 1
 cele aflate deasupra liniei a ºi la dreapta coloanei b sunt egale cu 2	
 cele aflate sub linia a ºi la stânga coloanei b sunt egale cu 3
 iar elementele aflate sub linia a ºi la dreapta coloanei b sunt egale cu 4.



*/

#include<stdio.h>

#define MAX 1000

void print_matrix(int mat[MAX][MAX], int n)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

}

void make_the_matrix(int mat[MAX][MAX], int n, int a, int b) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[a][j] = 0;
			if (j == b) {
				mat[i][b] = 0;
			}
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			mat[i][j] = 1;
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = b + 1; j < n; j++) {
			mat[i][j] = 2;
		}
	}

	for (int i = a + 1; i < n; i++) {
		for (int j = 0; j < b; j++) {
			mat[i][j] = 3;
		}
	}

	for (int i = a + 1; i < n; i++) {
		for (int j = b + 1; j < n; j++) {
			mat[i][j] = 4;
		}
	}
}

int main() {

	int n, a, b, matrix[MAX][MAX];

	scanf("%d%d%d", &n, &a, &b);
	
	make_the_matrix(matrix, n, a, b);

	print_matrix(matrix, n);

	return 0;
}


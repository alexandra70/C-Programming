/*								
7. Se citesc o matrice cu N linii si M coloane si un 
intreg d. Daca d este 0	 sa se afiseze suma elementelor 
pe coloane. Daca d este 1	 sa se afiseze suma elementelor 
pe linii. Daca d este 0	 rezultateul va fi afisat pe o singura 
linie. Daca d este 1	 rezultatul va fi afisat pe o 
singura coloana.|"				
								
Input								
2 3 0           Output								
10 2 21         20 35 22								
10 33 1								

*/

#include<stdio.h>

#define MAX 1000
#define MIN -1000
void read_matrix(int a[MAX][MAX], int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &a[i][j]);

}

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

void suma_linie(int a[MAX][MAX], int n, int m) {

	int i, j, suma = 0;
	for (i = 0; i < n; i++) {
		suma = 0;
		for (j = 0; j < m; j++) {
			suma += a[i][j];
			if (j == m - 1) {
				printf("%d ", suma);
			}
		}
		//printf("%d ", suma);
		//printf("\n");
	}
}

void suma_coloana(int a[MAX][MAX], int n, int m) {

	int i, j, suma = 0;
	for (j = 0; j < m; j++) {
		suma = 0;
		for (i = 0; i < n; i++) {
			suma += a[i][j];
			//if (i == n - 1) {
				//printf("%d", suma);
			//}
		}
		printf("%d", suma);
	}
	printf(" \n");
}

int main() {

	int n, m, matrix[MAX][MAX], d;
	scanf("%d%d%d", &n, &m, &d);

	read_matrix(matrix, n, m);

	if (d == 1) {
		suma_linie(matrix, n, m);
	}

	if (d == 0) {
		suma_coloana(matrix, n, m);
	}

	print_matrix(matrix, n, m);

	return 0;
}


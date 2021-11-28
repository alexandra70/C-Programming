/*6. Se citeste o matrice cu N linii si M coloane si un numar C 
reprezentand indicele unei coloane.Toate numerele de pe acea 
coloana vor fi inlocuite
cu maximul de pe linia din care fac parte.

Input
3 4 2           Output
0 10 12 2       0 10 12 2
4 5 21 89       4 5 89 89
10 12 9 3       10 12 12 3


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

int main() {

	int n, m, matrix[MAX][MAX], c;
	scanf("%d%d%d", &n, &m, &c);

	read_matrix(matrix, n, m);
	int prinde_j, max = MIN;

	for (int i = 0; i < n; i++) {
		max = MIN;
		for (int j = 0; j < m; j++) {
			if (max < matrix[i][j]) {
				max = matrix[i][j];
				prinde_j = j;
			}
		}
		matrix[i][c] = max;
	}
	print_matrix(matrix, n, m);
	
	return 0;
}


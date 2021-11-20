//1. Se citesc n si m	 reprezentand numarul de 
//linii	 respectiv de coloane ale unei matrici.Apoi se citesc
//elementele matricii.Sã se determine câte linii ale matricei 
//au toate elementele egale. 				


#include<stdio.h>

#define MAX 100

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

	int n, m, matrix[MAX][MAX], linie = 0, sum = 0;
	scanf("%d%d", &n, &m);
	int stop_line = m - 1;
	read_matrix(matrix, n, m);
	//printf("\n");
	for (int i = 0; i < n; i++){
		sum = 0;
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == matrix[i][j + 1]) {
				sum++;
				//printf("aici -%d %d- %d %d %d\n",i, j, matrix[i][j], matrix[i][j+1], sum);
			}
			else
				continue;
		}
		if(sum == stop_line)
			linie++;
	}
	//printf("\n");

	//print_matrix(matrix, n, m);
	printf("%d\n", linie);
	//printf("%d\n", sum);
	return 0;
}

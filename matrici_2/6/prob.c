//  5. Se citeste o matrice cu N linii si M coloane. Pentru liniile
//  pare sa se afize minimul	 iar pentru cele impare sa se afiseze maximul.							
//  Fiecare minim / maxim va fi printat pe o linie separata 
//  in formatul “nr_linie : min = x” pentru linii pare	 
//  “nr_linie : max = y” pentru linii impare
//  iar index - ul nr_linie va incepe de la 1	 
//  reprezentarea tabloului incepand de la 0.

/*Input
3 3             Output
1 2 3           1 : min = 1
4 5 6           2 : max = 6
7 10 12         3 : min = 7
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

	int n, m, matrix[MAX][MAX], is_odd[MAX];
	scanf("%d%d", &n, &m);

	read_matrix(matrix, n, m);

	int min = MAX;
	int max = MIN;
	int retin_min[MAX];

	for (int i = 0; i < n; i++) {
		min = 1000;
		max = -1000;
		for (int j = 0; j < m; j++) {

			if (max < matrix[i][j]) {
				max = matrix[i][j];
			}

			if (min > matrix[i][j]) {
				min = matrix[i][j];
			}

		}

		if (i % 2 == 0) {
			printf("%d: min = %d\n", i + 1, min);
		}
		if (i % 2 != 0) {
			printf("%d: max = %d\n", i + 1, max);
		}
	}
	//print_matrix(matrix, n, m);
	return 0;
}


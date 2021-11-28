//4. Se citesc n si m	 reprezentand numarul de linii	 respectiv 
//de coloane ale unei matrici. Apoi se citesc elementele matricii.								
//Determinați indicele liniei care conține un număr maxim 
//de elemente pare.Dacă există mai multe linii cu număr 
//maxim de elemente pare
//se vor afișa toți indicii	 în ordine crescătoare.

#include<stdio.h>

#define MAX 100
#define MIN -1000
void read_matrix(int a[MAX][MAX], int n, int m)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

}

void print_matrix(int a[MAX][MAX], int n, int m)
{
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		//printf("\n");
	}

}

int main() {

	int n, m, matrix[MAX][MAX], is_odd[MAX];
	scanf("%d%d", &n, &m);

	int count_odd[n];

	int max = MIN;

	read_matrix(matrix, n, m);

	for (int i = 0; i < n; i++) {
		is_odd[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		int magic = 0;
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] % 2 == 0) {
				magic++;
			}
		}
		is_odd[i] = magic;
	}

	for (int i = 0; i < n; i++) {
		if (is_odd[i] > max)
			max = is_odd[i];
	}

	int k;

	for (int i = 0; i < n; i++) {
		if (is_odd[i] == max) {
			k = i;
			printf("%d ", k);
		}
	}
	printf("\n");

	return 0;
}


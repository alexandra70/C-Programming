#include <stdio.h>
#include <stdlib.h>


int** get_matrix(int n, int m)
{
	int i, j;
	int** mat;

	mat = malloc(n * sizeof(int*));
	if (mat == NULL) {
		return NULL;
	}

	for (i = 0; i < n; i++) {
		mat[i] = calloc(m, sizeof(int));
		if (mat[i] == NULL) {
			for (j = 0; j < i; j++) {
				free(mat[j]);
			}

			free(mat);
			return NULL;
		}
	}

	return mat;
}

int realo(int*** mat, int n, int m) {
	
	int k = n + 1;

	*mat = realloc(*mat, k * sizeof(int*));
	if (*mat == NULL) {
		printf("problems\n");
	}
	for (int i = 0; i < k-1; i++) {
		(*mat)[i] = realloc((*mat)[i], m*sizeof(int));
		if ((*mat)[i] == NULL) {
			printf("orice");
		}
	}
	for (int i = n; i < k; i++) {
		(*mat)[i] = calloc(m, sizeof(int));
	}

	return k;
}

int* move(int** mat, int i, int n) {

	int* vector = (int*)malloc(n * sizeof(int));
	for (int j = 0; j < n; j++) {
		vector[j] = mat[i][j];
	}

	return vector;
}


void free_matrix(int*** mat, int n)
{
	int i;

	for (i = 0; i < n; i++) {
		free((*mat)[i]);
	}

	free(*mat);
	*mat = NULL;
}

void read_matrix(int** mat, int n, int m)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
}

void sum_lines(int** mat, int n, int m)
{
	int i, j, sum;

	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j < m; j++) {
			sum += mat[i][j];
		}
		printf("Suma elementelor de pe linia %d este %d\n", i, sum);
	}
}

void print_matrix(int** mat, int n, int m)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

}

int main(void)
{
	int n, m;
	int** matrix;


	scanf("%d%d", &n, &m);

	matrix = get_matrix(n, m);


	if (matrix == NULL) {
		printf("Allocation error\n");
		return 1;
	}


	read_matrix(matrix, n, m);
	print_matrix(matrix, n, m);
	sum_lines(matrix, n, m);

	printf("LINIA PE CARE O PUNEM IN VECTOR: ");
	int i;
	scanf("%d", &i);
	int* vector = move(matrix, i, m);
	for (int j = 0; j < m; j++) {
		printf("%d ", vector[j]);
	}
	printf("\n\n");

	int k = realo(&matrix, n, m);

	print_matrix(matrix, k, m);
	printf("\n\n");
	for (int i = 0; i < m; i++) 
		matrix[k-1][i] = vector[i];
	

	print_matrix(matrix, k, m);

	free_matrix(&matrix, k);

	return 0;
}

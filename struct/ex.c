#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ALLOC 100
/*
* 
O matrice rarã (cu circa 90% din elemente 0) este pãstratã economic sub forma
unei structuri, care conþine urmãtoarele câmpuri:


int L,C - numãrul de linii/coloane al matricei rare
int N - numãrul de elemente nenule
int LIN[] - vectorul ce pãstreazã liniile în care se aflã elemente nenule
int COL[] - vectorul ce pãstreazã coloanele în care se aflã elemente nenule
float X[] - vectorul ce pãstreazã elementele nenule


Sã se defineascã funcþii pentru:


[1p] citirea unei matrice rare
[1p] afiºarea unei matrice rare (ca o matrice, cu tot cu zerouri)
[2p] adunarea a douã matrice rare.

*/

typedef struct {

	int l, c;
	int n;
	int* lin;
	int* col;
	float* x;

} Matrix;

void free_mat(Matrix** mat) {

	free((*mat)->lin);
	free((*mat)->col);
	free((*mat)->x);
	free(*mat);

}

Matrix* alloc_Matrix() {

	Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));

	if (!matrix) {
		fprintf(stderr, "error");
		return NULL;
	}

	matrix->lin = (int *)malloc(ALLOC * sizeof(int));
	if (!matrix->lin) {
		
		free(matrix->lin);
		fprintf(stderr, "error");
		return NULL;
	}

	matrix->col = (int*)malloc(ALLOC * sizeof(int));

	matrix->x = (float*)malloc(ALLOC * sizeof(int));

	matrix->n = 0;
	matrix->l = 0;
	matrix->c = 0;

	return matrix;

}

int read_data(Matrix* matrix) {

	scanf("%d", &matrix->l);
	scanf("%d", &matrix->c);
	int val;
	int n = 0;

	for (int i = 0; i < matrix->l; i++) {
		for (int j = 0; j < matrix->c; j++) {
			scanf("%d", &val);
			if (val != 0) {
				//number of elements
				matrix->lin[n] = i;
				matrix->col[n] = j;
				matrix->x[n] = val;
				n++;
			}
		}
	}
	return n;
}

void print_matrix(Matrix* matrix, int n) {

	
	int val = 0;

	for (int i = 0; i < matrix->l; i++) {

		for (int j = 0; j < matrix->c; j++) {

			for (int k = 0; k < n; k++) {
				if (i == matrix->lin[k] && j == matrix->col[k]) {
					printf("%.f ", matrix->x[k]);
					val = 0;
					break;
				}

				else
					val = 1;
			}

			if (val)
				printf("0 ");
			val = 0;
		}

		printf("\n");
	}
}

Matrix* add_matrix(Matrix* first_mat, Matrix* second_mat) {


	
	if (first_mat->l != second_mat->l && first_mat->c != second_mat->c) {
		printf("cant add them--the size does not conicide\n");
		return NULL;
	}

	Matrix* initial = alloc_Matrix();
	initial->c = first_mat->c;
	initial->l = first_mat->l;
	
	int i = 0;
	int j = 0;
	int pozi = first_mat->lin[i] * first_mat->c + first_mat->col[i];
	int pozj = second_mat->lin[j] * second_mat->c + second_mat->col[j];

	while (i < first_mat->n && j < second_mat->n) {
		if (pozi == pozj) {
			initial->x[initial->n] = first_mat->x[i] + second_mat->x[j];
			initial->lin[initial->n] = first_mat->lin[i];
			initial->col[initial->n] = first_mat->col[i];
			initial->n++;
			i++;
			j++;
		}
		else if (pozi < pozj) {
			initial->x[initial->n] = first_mat->x[i];
			initial->lin[initial->n] = first_mat->lin[i];
			initial->col[initial->n] = first_mat->col[i];
			initial->n++;
			i++;
		}
		else {
			initial->x[initial->n] = second_mat->x[j];
			initial->lin[initial->n] = second_mat->lin[j];
			initial->col[initial->n] = second_mat->col[j];
			initial->n++;
			j++;
		}
		pozi = first_mat->lin[i] * first_mat->c + first_mat->col[i];
		pozj = second_mat->lin[j] * second_mat->c + second_mat->col[j];
	}

	while (i < first_mat->n) {
		initial->x[initial->n] = first_mat->x[i];
		initial->lin[initial->n] = first_mat->lin[i];
		initial->col[initial->n] = first_mat->col[i];
		initial->n++;
		i++;
	}

	while (j < second_mat->n) {
		initial->x[initial->n] = second_mat->x[j];
		initial->lin[initial->n] = second_mat->lin[j];
		initial->col[initial->n] = second_mat->col[j];
		initial->n++;
		j++;
	}


	return initial;
}



int main() {

	Matrix* matrix = alloc_Matrix();
	Matrix* second = alloc_Matrix();

	matrix->n = read_data(matrix);

	second->n = read_data(second);

	print_matrix(matrix, matrix->n);
	printf("-----------\n");
	print_matrix(second, second->n);

	printf("-----------\n");

	Matrix* add = add_matrix(matrix, second);

	print_matrix(add, add->n);

	printf("-----------\n");

	free_mat(&matrix);
	free_mat(&second);
	free_mat(&add);

	return 0;
}
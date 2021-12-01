#include<stdio.h>
#define N 4
int main() {

	int a[N][N] = { {1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16}
	};

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	int row = 0;
	int max_row = N - 1;
	int col = 0;
	int max_col = N - 1;
	int prev = a[row+1][col];

	while (row <= max_row && col <= max_col) {

		for (int i = col; i <= max_col; i++) {
			int current = a[row][i];
			a[row][i] = prev;
			prev = current;
		}
	
		for (int i = row + 1; i <= max_row; i++) {
			int current = a[i][max_col];
			a[i][max_col] = prev;
			prev = current;
		}
	
		for (int i = max_col - 1; i >= col; i--) {
			int current = a[max_col][i];
			a[max_col][i] = prev;
			prev = current;
		}
		
		for (int i = max_row - 1 ; i >= row; i--) {
			int current = a[i][col];
			a[i][col] = prev;
			prev = current;
		}

		col++;
		row++;
		max_col--;
		max_row--;
		
		
		
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}


	return 0;
}
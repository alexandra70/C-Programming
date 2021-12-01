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

	int left = 0;
	int right = N - 1;
	int top = 0;
	int down = N - 1;
	int direction = 0;

	while (left <= right && top <= down) {

		if (direction == 0) {
			//right -> left
			for (int i = left; i <= right; i++)
				printf("%d ", a[top][i]);
			top++;
		}

		if (direction == 1) {
			for (int i = top; i <= down; i++)
				printf("%d ", a[i][right]);
			right--;
		}

		if (direction == 2) {
			for (int i = right; i >= left; i--)
				printf("%d ", a[down][i]);
			down--;
		}

		if (direction == 3) {
			for (int i = down; i >= top; i--)
				printf("%d ", a[i][left]);
			left++;
		}

		direction = (direction + 1) % 4;

	}


	return 0;
}
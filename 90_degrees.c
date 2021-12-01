#include<stdio.h>
#define N 4

void normal(int a[N][N]) {

	for (int x = 0; x < N / 2; x++) {
		//linii pana la mijloc
		for (int y = x; y < N - 1 - x; y++) {
			int tmp = a[x][y];
			a[x][y] = a[N - 1 - y][x];
			a[N - 1 - y][x] = a[N - 1 - x][N - 1 - y];
			a[N - 1 - x][N - 1 - y] = a[y][N - 1 - x];
			a[y][N - 1 - x] = tmp;
		}
	}

	return;
}

void anti(int a[N][N]) {
	//anti-clockwise
	//cate patrate avem de parcurs
	for (int x = 0; x < N / 2; x++) {
		//linii pana la mijloc
		for (int y = x; y < N - 1 - x; y++) {
			int tmp = a[x][y];
			a[x][y] = a[y][N - 1 - x];
			a[y][N - 1 - x] = a[N - 1 - x][N - 1 - y];
			a[N - 1 - x][N - 1 - y] = a[N - 1 - y][x];
			a[N - 1 - y][x] = tmp;
		}
	}
	return;
}

void print(int a[N][N]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return;
}
int main() {

	int a[N][N] = { {1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16}
	};

	print(a);

	anti(a);
	print(a);

	normal(a);
	print(a);

	return 0;
}
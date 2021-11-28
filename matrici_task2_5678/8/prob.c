/*

8. Se citeste un vector de dimensiune N*N. 
Sa se creeze si sa se afiseze matricea spirala provenita din acesta.

Input                         Output
3                             1 2 3
1 2 3 4 5 6 7 8 9             8 9 4
							  7 6 5

*/

#include<stdio.h>




void spiralo( int n) {

	
	int i = 0;
	int j = 0;
	int c = 0;

	int matrix[n][n];

	for (c = 0; c < n / 2 + 1; c++) {
		i = c;
		j = c;
		for (j = c; j < n - c; j++) {
			scanf("%d", &matrix[i][j]);
		}
		j--;
		for (i = c + 1; i < n - c; i++) {
			scanf("%d", &matrix[i][j]);
		}
		i--;
		j--;
		for (; j >= c; j--) {
			scanf("%d", &matrix[i][j]);
		}
		j++;
		i--;
		for (; i > c; i--) {
			scanf("%d", &matrix[i][j]);
		}
		
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n-1; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("%d\n", matrix[i][j]);
	}


}



int main() {

	int n;
	
	scanf("%d", &n);
	
	spiralo(n);
	
	return 0;
}


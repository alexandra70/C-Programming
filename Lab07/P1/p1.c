#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
/*Problema 1
----------
Sa se sorteze un vector de numere intregi folosind o metoda la 
alegere(bubble sort, insertion sort, etc).

void sort(int* v, int n);

Ex: v1 = [5, 2, 9, 1, 4], n = 5->v1 = [1, 2, 4, 5, 9];
Nu se va permite accesul elementelor folosind operatorul[].
*/


void sort(int* v, int n) {

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (*(v + i) > * (v + j)) {
				int exs = *(v + i);
				*(v + i) = *(v + j);
				*(v + j) = exs;
			}
		}
	}
	
}

int main() {

	int n;
	scanf("%d", &n);
	
	int* v = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", v + i);
	}
	sort(v, n);

	for (int i = 0; i < n; i++) {
		printf("%d ", *(v + i));
	}
	printf("\n");
	return 0;

}

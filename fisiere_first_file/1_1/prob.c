#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* 
1. Se da un fisier ce contine doua siruri de numere intregi, ambele 
sortate. Sa se creeze fisierul data.out ce contine valorile interclasate
din cele doua siruri. Pe prima linie se afiseaza numarul de elemente
ale sirului interclasat, iar pe a doua linie se afiseaza sirul dupa
interclasare.

data.in
4
-1 2 10 15
3
1 1 7

data.out
7
-1 1 1 2 7 10 15

*/

#define MAX 50

void ordored(int** arr, int nr) {

	int exchg;

	for (int k = 0; k < nr; k++) {
		for (int i = k + 1; i < nr; i++) {
			if ((*arr)[k] > (*arr)[i]) {
				exchg = (*arr)[k];
				(*arr)[k] = (*arr)[i];
				(*arr)[i] = exchg;
			}
		}
	}

}

int read_array(int** arr) {

	int n;
	int m;

	scanf("%d", &n);

	for (int p = 0; p < n; p++) 
		scanf("%d", &(*arr)[p]);

	scanf("%d", &m);

	for (int p = n; p < m + n; p++) 
		scanf("%d", &(*arr)[p]);
	
	int total = m + n;
	
	return total;
}

int main()
{

	char file_out[] = "data.out";

	FILE* out = fopen(file_out, "wt");

	if (!out) {
		fprintf(stderr, "error %s->", file_out);
		return -1;
	}

	int* arr = malloc(MAX * sizeof(int));

	int j = read_array(&arr);

	ordored(&arr, j);

	fprintf(out, "%d\n", j);

	for (int k = 0; k < j; k++) {
		if (k == (j - 1)) {
			fprintf(out, "%d\n", arr[k]);
		}
		else {
			fprintf(out, "%d ", arr[k]);
		}
	}

	free(arr);
	fclose(out);
	
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define SENTENCE 100000

/*

1. Numim element majoritar un element care apare de cel putin [n/2] + 1
ori intr-un fisier. Gasiti elementul majoritar dintr-un fisier fara a
folosi memorie suplimentara (vectori). Se garanteza ca mereu va exista
un element majoritar.

data.in	data.out
5	1
2 1 1 3 1
6	10
10 10 20 20 10 10


*/
int majority_element() {

	int n;
	int elem;
	int m;
	int count = 0;

	fscanf(stdin, "%d", &n);

	for (int i = 0; i < n; i++) {
		fscanf(stdin, "%d", &elem);
		if (count == 0) {
			m = elem;
			count = 1;
		}
		else {
			if (m == elem)
				count++;
			else
				count--;
		}
	}

	return m;
}

int main()
{

	char file_out[] = "data.out";

	FILE* out = fopen(file_out, "wt");

	if (!out) {
		fprintf(stderr, "error %s->", file_out);
		return -1;
	}

	int m = majority_element();

	fprintf(out, "%d", m);
	fprintf(out, "\n");

	fclose(out);

	return 0;


}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5000
#define ELEM 2

/*

3. Se da un fisier binar cu numere intregi. Nu se specifica numarul de
numere din fisier, deci va trebui gasita o modalitate de a afla cate 
numere avem in fisier. Apoi, se doreste aflarea sumei numerelor din 
fisier. Aceasta se va afisa in fisierul data.out.

data.in
<binary data>

data.out
<a number as text>

*/
int array_sum() {

	int* v = (int*)calloc(MAX, sizeof(int));

	int i = 0;
	int sum = 0;
	int k;

	while (fread(&v[i], sizeof(int), 1, stdin)) {
		i++;
	}

	v = (int*)realloc(v, i * sizeof(int));

	for (int j = 0; j < i; j++) {
		sum += v[j];
	}

	return sum;

}

int main()
{

	char file_out[] = "data.out";

	FILE* out;

	if ((out = fopen(file_out, "wt")) == NULL) {
		fprintf(stderr, "error %s->", file_out);
		return -1;
	}


	int sum = array_sum();

	printf("%d\n", sum);

	fprintf(out, "%d\n", sum);

	fclose(out);

	return 0;

}
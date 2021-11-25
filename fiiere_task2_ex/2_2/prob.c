#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500
#define ELEM 2

/*

2. Se da un fi?ier binar cu numere întregi. Nu se specifica num?rul de 
numere din fi?ier, deci va trebui g?sita o modalitate de a afla cate 
numere avem în fi?ier. Apoi, se dore?te aflarea celui mai frecvent 
element dintre cele citite (în caz de egalitate se afi?eaz? cel mai mic
num?r).

data.in	data.out
<binary data>	<a number as text>

*/
int frequency_number() {

	int* v = (int*)calloc(MAX, sizeof(int));
	
	int i = 0;

	while (fread(&v[i], sizeof(int), 1, stdin)) 
		i++;

	int** frequency_array = (int**)malloc(i*sizeof(int*));

	for (int j = 0; j < i; j++) {
		frequency_array[j] = (int*)calloc(ELEM, sizeof(int));
		frequency_array[j][0] = v[j];
	}

	int appe = 1;
	for (int j = 0; j < i; j++) {
		for (int k = j + 1; k < i; k++) {
			if (v[j] == v[k]) {
				appe++;
			}
		}
		frequency_array[j][1] = appe;

		appe = 1;
	}

	int max = frequency_array[0][1];
	int wanted = frequency_array[0][0];
	
	for (int j = 1; j < i; j++) {

		if (max == frequency_array[j][1]) {
			if (frequency_array[j][0] < wanted) 
				wanted = frequency_array[j][0];
		}

		if (max < frequency_array[j][1]) {
			max = frequency_array[j][1];
			wanted = frequency_array[j][0];
		}
	}

	for (int j = 0; j < i; j++) 
		free(frequency_array[j]);

	free(frequency_array);
	free(v);

	return wanted;
}

int main()
{

	char file_out[] = "data.out";

	FILE* out;

	if ((out = fopen(file_out, "wt")) == NULL) {
		fprintf(stderr, "error %s->", file_out);
		return -1;
	}
	

	int m = frequency_number();

	printf("%d\n", m);

	fprintf(out, "%d\n", m);

	fclose(out);

	return 0;

}
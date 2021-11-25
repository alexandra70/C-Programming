#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15
#define ELEM 2

/*

4.  Se citeste de la tastatura 2 numere, K si N, iar apoi un vector cu N
numere naturale. Se doreste formarea a K fisiere cu numele “output0.txt”,
“output1.txt” … “output(K-1).txt”, iar in fiecare din aceste fisiere sa
scriem doar acele numere care dau restul i la impartirea cu K.
Exemplu: Daca avem K=5, vom forma 5 fisiere de iesire (de la 
“output0.txt” pana la “output4.txt”).   De exemplu, fisierul 
“output0.txt” poate avea numerele “20 5 90 55”, iar fisierul 
“output3.txt” poate contine “23 58 103 3”, in functie de numerele citite
de la tastatura.


char filename[] = "file.txt";
 FILE *fp = fopen(filename,"r");
char str[80];
strcpy(str, "these ");
strcat(str, "strings ");
strcat(str, "are ");
strcat(str, "concatenated.");
char nume[20];
strcpy(nume, "output");
itoa(nr, nr_ca_string); //aici nr_ca_string e alocat dinainte ca char*
strcat(nume,nr_ca_string);
strcat(nume, ".txt");
*/
int array_sum() {

	int sum = 0;

	return sum;

}

int main()
{

	int k;
	int n;

	scanf("%d%d", &k, &n);

	int* array = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}

	char* filename = (char*)malloc(MAX * sizeof(char));
	char* convert = (char*)malloc(ELEM * sizeof(char));
	FILE* file;

	for (int i = 0; i < k; i++) {
		strcpy(filename, "output");
		sprintf(convert, "%d", i);
		strcat(filename, convert);
		strcat(filename, ".txt");
		printf("%s\n", filename);
		
		if ((file = fopen(filename, "wt")) == NULL) {
			fprintf(stderr, "error %s->", filename);
			return -1;
		}

		for (int j = 0; j < n; j++) {
			if (array[j] % k == i) 
				fprintf(file, "%d ", array[j]);
		}

		fclose(file);

	}

	return 0;

}
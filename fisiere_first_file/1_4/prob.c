#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define SENTENCE 100000

/*

4. Avem 2 fisiere text (data1.in si data2.in). Se doreste adaugarea
continutului celui de-al doilea fisier la sfarsitul primului 
(concatenarea fisierelor) si salvarea intr-un al treilea fisier 
(data.out). Fisierele de intrare vor ramane nemodificate.
Fisierul de intrare va ramane nemodificat.

*/


int main()
{
	char fp[] = "data1.in";
	char ft[] = "data2.in";
	char file_out[] = "data.out";

	FILE* input_one = fopen(fp, "rt");
	FILE* input_two = fopen(ft, "rt");
	FILE* out = fopen(file_out, "wt");


	if (!input_one) {
		fprintf(stderr, "error %s->", fp);
		return -1;
	}

	if (!input_two) {
		fprintf(stderr, "error %s->", ft);
		return -1;
	}

	if (!out) {
		fprintf(stderr, "error %s->", file_out);
		return -1;
	}

	char* first = (char*)malloc(SENTENCE);

	char* second = (char*)malloc(SENTENCE);

	char* additional = (char*)malloc(SENTENCE);

	while (fgets(additional, SENTENCE, input_one)) {
		if (strlen(additional) != 1)
			strcat(first, additional);
	}

	while (fgets(additional, SENTENCE, input_two)) {
		if (strlen(additional) != 1)
			strcat(second, additional);
	}

	fprintf(out, "%s", first);
	fprintf(out, "%s", second);

	printf("%s", first);
	printf("-------");
	printf("%s", second);

	free(first);
	free(second);
	free(additional);

	fclose(out);

	return 0;


}
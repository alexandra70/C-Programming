#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
#define SENTENCE 1000
#define SEPARATORS " \t"
/*

3. Sa se elimine dintr-un fisier toate spatiile, taburile, si liniile 
vide consecutive. Rezultatul se va scrie intr-un nou fisier numit 
“data.out”. Fisierul de intrare va ramane nemodificat.

*/


char* new_file(char* str) {
	
	char* word;
	char* sent = (char*)malloc(SENTENCE);
	word = strtok(str, SEPARATORS);

	while(word){

		strcat(sent, word);
		word = strtok(NULL, SEPARATORS);

	}

	return sent;
}

int main()
{

	char file_out[] = "data.out";

	FILE* out = fopen(file_out, "wt");

	if (!out) {
		fprintf(stderr, "error %s->", file_out);
		return -1;
	}

	char* comp = (char*)malloc(SENTENCE);

	char* str = (char*)malloc(SENTENCE);

	char* additional = (char*)malloc(SENTENCE);

	while (fgets(additional, SENTENCE, stdin)) {
		if(strlen(additional) != 1)
			strcat(str, additional);
	}

	comp = new_file(str);
	printf("%s", comp);
	
	fprintf(out, "%s", comp);


	fclose(out);

	return 0;
}
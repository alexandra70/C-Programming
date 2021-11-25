#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

2. Se da un fisier text si doua cuvinte cuv1 si cuv2. Inlocuiti toate 
aparitiile cuvantului cuv1  cu cuvantul cuv2. cuv1 si cuv2 pot contine
doar caractere alfanumerice (fara spatii sau newline). Textul poate 
contine orice caracter valid si se poate extinde pe mai multe linii.

data.in					data.out
mere						Ana are pere si pere (multe pere).
pere							Cate pere ai?
Ana are mere si pere (multe mere).	<newline>
Cate mere ai?
aa	a a a a bbb bbba bbabb
bbb
a a a a aa aaa bbabb

*/

#define MAX 50
#define SENTENCE 10000

char* existence(char* sentence, char* first, char* second) {

	char* duplicate = strdup(sentence);

	if (duplicate == NULL) {
		printf("ERROR");
		return NULL;
	}

	char* new_sentence = (char*)malloc(SENTENCE);
	char* aux = (char*)malloc(SENTENCE);
	int len_sentence = strlen(sentence);
	int len_first = strlen(first);
	int len_second = strlen(second);
	int diferenta = len_second - len_first;
	int index = 0;
	int hold = 0;

	for (int i = 0; i < len_sentence - len_first + 1; i++) {
		if (strncmp(sentence + i, first, len_first) == 0) {
			strcpy(aux, sentence + i + len_first);
			strcpy(sentence + i, second);
			strcpy(sentence + i + len_second, aux);
			len_sentence += diferenta;
		}
	}
	free(duplicate);
	return sentence;
}

void chop(char** word) {

	(*word)[strlen(*word) - 1] = '\0'; 

}

int main()
{

	char file_out[] = "data.out";

	FILE* out = fopen(file_out, "wt");

	if (!out) {
		fprintf(stderr, "error %s->", file_out);
		return -1;
	}

	char* first = malloc(MAX * sizeof(char));
	char* second = malloc(MAX * sizeof(char));
	char* sentence = malloc(SENTENCE * sizeof(char));
	char* additional = malloc(SENTENCE * sizeof(char));

	fgets(first, MAX, stdin);
	fgets(second, MAX, stdin);

	chop(&first);
	chop(&second);

	while (fgets(sentence, SENTENCE, stdin) != NULL) {
		additional = strcat(additional, sentence);
	}

	char* ne = malloc(SENTENCE * sizeof(char));

	ne = existence(additional, first, second);

	printf("%s", additional);
	fprintf(out, "%s", ne);

	fclose(out);

	return 0;

}
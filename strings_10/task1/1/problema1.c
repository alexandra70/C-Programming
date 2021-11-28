#include <stdio.h>                                                                                                                                                                                                   
#include <string.h>                                                                                                                                                                                                  
#include <ctype.h>
#include <stdlib.h>                                                                                                                                                                                                   

#define SEPARATORS " ,."                                                                                                                                                                                             
#define max_len 200
#define max_words 200
#define max_len_matrix 200
#define ISOLATORS " "


/*

id|enunt|exemplu
1|"Se citeste de la tastatura un cuvant format din litere mici si mare
ale alfabetului englez (fara whitespace) si un caracter (cuvantul are
mai putin de 100 de caractere). Sa se inlocuiasca fiecare aparitie a
caracterului in cuvantul intial cu numarul de aparitii ale caracterului
pana in momentul respectiv."|"

"INPUT:						OUTPUT"
"Antananarivo					Ant1n2n3rivo"
a
"
*/


int read_str(char** str) {

	char c;
	int i = 0;
	while (scanf("%c", &c)) {
		if (c == '\n') {
			str[i] = 0;
			break;
		}
		else
			(*str)[i] = c;
		i++;
	}
	
	return strlen(*str);

}


char* discover_char(char* tmp, char wanted) {

	

	int length = strlen(tmp);
	int i = 0;
	char* here = strchr(tmp, wanted);
	
	int count = 0;
	
	while (here != NULL) {
		count++;
		i = length - strlen(here);
		if (count > 9) {
			//tmp = realloc(tmp, strlen(tmp) + 2);
			length++;
			for (int j = length; j > i; j--) {
				tmp[j] = tmp[j - 1];
			}
			tmp[i + 1] = count % 10 + '0';
			tmp[i] = count / 10 + '0';
		}
		else {
			tmp[i] = count + '0';
		}
		here = strchr(tmp, wanted);
	}

	

	return tmp;
}

int main() {
	
	char* string = (char*)calloc(max_len, sizeof(char));

	char compare;

	scanf("%s\n%c", string, &compare);

	printf("%s\n", discover_char(string, compare));

	return 0;
}


/*

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SEPARATORS " ,."
#define max_len 200
#define max_words 200
#define max_len_matrix 200
#define ISOLATORS " "


id|enunt|exemplu
1|"Se citeste de la tastatura un cuvant format din litere mici si mare
ale alfabetului englez (fara whitespace) si un caracter (cuvantul are
mai putin de 100 de caractere). Sa se inlocuiasca fiecare aparitie a
caracterului in cuvantul intial cu numarul de aparitii ale caracterului
pana in momentul respectiv."|"

"INPUT:						OUTPUT"
"Antananarivo					Ant1n2n3rivo"
a
"

int read_str(char** str) {

	char c;
	int i = 0;
	while (scanf("%c", &c)) {
		if (c == '\n')
			break;
		else
			(*str)[i] = c;
		i++;
	}
	return strlen(*str);

}

char* discover_char(char** str, char* wanted) {

	char* tmp = strdup(*str);
	if (tmp == NULL)
		return NULL;

	int length = strlen(*str);
	int i = 0;
	char* here = strstr(tmp, wanted);
	int count = 0;
	//printf(" ");

	while (here != NULL) {
		count++;
		i = length - strlen(here);
		if (count > 9) {
			length++;
			for (int j = length; j > i; j--) {
				tmp[j] = tmp[j - 1];
			}
			tmp[i + 1] = count % 10 + '0';
			tmp[i] = count / 10 + '0';
		}
		else
			tmp[i] = count + '0';

		here = strstr(tmp, wanted);
	}

	strcpy((*str), tmp);
	free(tmp);
	free(here);

	return (*str);
}

int main() {

	char* string = (char*)malloc(max_len * sizeof(char));

	read_str(&string);

	char* compare = (char*)malloc(10 * sizeof(char));
	read_str(&compare);
	printf("%s\n", discover_char(&string, compare));

	free(string);
	free(compare);


	return 0;
}

*/
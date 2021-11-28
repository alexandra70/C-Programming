#include <stdio.h>                                                                                                                                                                                                   
#include <string.h>                                                                                                                                                                                                  
#include <ctype.h>
#include <stdlib.h>                                                                                                                                                                                                   

#define SEPARATORS " ,."                                                                                                                                                                                             
#define max_len 200
#define max_words 200
#define max_len_matrix 200

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
			tmp[i+1] = count % 10 + '0';
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
/*
2|Sa citeste un numar natural N (1 <= N <= 50) urmat de N cuvinte cu lungimea"
cel mult 50. Sa se sorteze cuvintele in ordine lexicografica."|"

"INPUT:						OUTPUT"
"4						Ana"
"are						are"
"Ana						banane"
"mere						mere"
banane
"
*/


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

int read_more(char*** str, int n) {

	*str = (char**)malloc(max_words * sizeof(char*));
	char copy[100];
	int i = 0;

	while(n){
		scanf("%s", copy);
		(*str)[i] = (char*)malloc(max_len_matrix * sizeof(char));
		strcpy((*str)[i], copy);
		i++;
		n--;
	}   
	*str = realloc(*str, sizeof(char*) * i);
	
	for (int j = 0; j < i; j++) {
		for (int k = j + 1; k < i; k++) {
			if (strcmp((*str)[j], (*str)[k]) > 0) {
				char* tmp = (*str)[j];
				(*str)[j] = (*str)[k];
				(*str)[k] = tmp;
			}
		}
	}
	
	return i;
}

/*
3|Se citeste de la tastatura o propozitie (cuvinte separate prin unul
sau mai" multe spatii	 care se termina cu un semn de punctuatie: '.'
'!' sau '?').Pe urmatoarea linie se citeste un cuvant. Sa se determine
de cate ori apare cuvantul in propozitia data."|"

"INPUT						OUTPUT"
"Am mancat o  para si o banana in paralel.	1"

Atentie! Prefixul “para” din paralel nu se numara.
"
"
*/

int main() {
	/*
	char* string = (char*)malloc(max_len * sizeof(char));

	read_str(&string);
	
	char* compare = (char*)malloc(10 * sizeof(char));
	read_str(&compare);
	printf("%s\n", discover_char(&string, compare));

	free(string);
	free(compare);

	*/

	int n;
	scanf("%d", &n);
	char** mat;
	int len = read_more(&mat, n);

	for (int i = 0; i < len; i++) 
		printf("%s\n", mat[i]);
	
	for (int i = 0; i < len; i++)
		free(mat[i]);

	free(mat);
	


	return 0;
}



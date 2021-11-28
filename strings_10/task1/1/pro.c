#include <stdio.h>                                                                                                                                                                                                   
#include <string.h>                                                                                                                                                                                                  
#include <ctype.h>
#include <stdlib.h>    
#define max_size 100
#define SEPARATORS " ,."
/*
Folosind funcþia strtok, citiþi un ºir de caractere, apoi un cuvânt ºi
afiºaþi pe ecran numãrul de apariþii al cuvântului în ºir.
*/

int occurrence(char* vectorchar[], char* say) {

	int occur = 0;
	char* tmp = strdup(*vectorchar);
	if (tmp == NULL) 
		printf("error");
	
	char* word = strtok(tmp, SEPARATORS);

	while (word) {

		if (strcmp(word, say) == 0) {
			occur++;
		}

		word = strtok(NULL, SEPARATORS);

	}
	free(tmp);

	return occur;
}

/*
Folosind funcþiile din <string.h> înlocuiþi într - un text dat o 
secventã de caractere cu altã secvenþã de caractere, date la intrare.
*/

char* replace(char* vectorchar[], char* replacement, int replace_here) {

	char* replica = strdup(*vectorchar);
	if (replica == NULL) 
		printf("error");

	//char* word = strtok(replica, SEPARATORS);
	if (strlen(replacement) > strlen(*vectorchar)) {
		printf("ERROR");
		return NULL;
	}
	else
		memcpy(*vectorchar, replacement, strlen(replacement));

	return (*vectorchar);
}

/* 
Sã se citeascã o succesiune de cuvinte.Sã se creeze o funcþie :
care sã ordoneze cuvintele
crescãtor
1.dupã lungimea acestora.
2.alfabetic
*/

void lengtho(char* vectorschar[], int n) {

	char* tmp = strdup(*vectorschar);
	if (tmp == NULL)
		printf("eroare");

	char* word = strtok(tmp, " ");
	char** mat = (char**)malloc(n * sizeof(char*));
	int i = 0;

	while (word) {
		mat[i] = (char*)malloc((strlen(word)) * sizeof(char));
		strcpy(mat[i], word);
		i++;
		word = strtok(NULL, " ");
	}

	for (int j = 0; j < i; j++) {
		for (int k = j + 1; k < i; k++) {
			if (strlen(mat[j]) >  strlen(mat[k])) {
				char* tmp = mat[j];
				mat[j] = mat[k];
				mat[k] = tmp;
			}
		}

	}

	for (int j = 0; j < i; j++) {
		if (j == i - 1) {
			mat[j][strlen(mat[j])] = '\n';
			break;
		}
		else
			mat[j][strlen(mat[j])] = ' ';
	}

	for (int j = 0; j < i; j++) {
		if (j == 0) {
			strcpy((*vectorschar), mat[j]);
		}
		else
			strcat((*vectorschar), mat[j]);
	}

	free(tmp);

	for (int j = 0; j < i; j++)
		free(mat[i]);
	free(mat);

}

void ordCresc(char* vectorschar[], int n) {

	char* tmp = strdup(*vectorschar);
	if (tmp == NULL)
		printf("eroare");

	char* word = strtok(tmp, " ");
	char** mat = (char**)malloc(n * sizeof(char*));
	int i = 0;

	while (word) {
		mat[i] = (char*)malloc((strlen(word)) * sizeof(char));
		strcpy(mat[i], word);
		i++;
		word = strtok(NULL, " ");
	}

	for (int j = 0; j < i; j++) {
		for (int k = j + 1; k < i; k++) {
			if (strcmp(mat[j], mat[k]) > 0) {
				char* tmp = mat[j];
				mat[j] = mat[k];
				mat[k] = tmp;
			}
		}

	}

	for (int j = 0; j < i; j++) {
		if (j == i - 1) {
			//mat[j][strlen(mat[j])] = '\n';
			break;
		}
		else
			mat[j][strlen(mat[j])] = ' ';
	}

	for (int j = 0; j < i; j++) {
		if (j == 0) {
			strcpy((*vectorschar), mat[j]);
		}
		else
			strcat((*vectorschar), mat[j]);
	}
	
	free(tmp);

	for (int j = 0; j < i; j++) 
		free(mat[i]);
	free(mat);

}

char* read_str(char** str) {

	char c;
	int i = 0;
	while (scanf("%c", &c)) {
		if (c != '\n') {
			(*str)[i] = c;
			i++;
		}
		else
			break;
	}
	*str = realloc((*str), i * sizeof(char));

	return (*str);

}

/*
Sã se determine dacã o propozitie este palindromã. O propozitie
este palindromã daca cititã de la prima literã panã la ultima are
aceeasi succesiune ca cititã de la ultima literã pânã la prima. Nu
conteaza dacã sunt litere mici sau mari.
Exemplu: ele fac cafele
*/

void reflect_tsamet(char* vectorchar[], int n) {

	char* duplicate = strdup(*vectorchar);
	if (duplicate == NULL)
		printf("eroare alocare");

	int count = 0;
	int spaces = 0;
	int length = strlen(*vectorchar);
	int i = 0;
	int j = length - 1;

	while(i < length && j >= 0){
		if (duplicate[i] == ' ') {
			spaces++;
			i++;
		}
		if (duplicate[j] == ' ') {
			j--;
		}
		if (duplicate[i] == duplicate[j])
			count++;
		j--;
		i++;
	}
	printf("->>%d %d\n %d \n", count, spaces, length);
	if ((count + spaces) == length) {
		printf("correctly mirrored\n");
	}
	else
		printf("wrongly mirrored\n");


}

/*
Folosind funcþia strtok, citiþi un ºir de caractere ºi afiºaþi 
pe ecran cuvintele sale constituente.
*/

char* strtoko(char* vectorchar[], int n) {

	char* duplicate = strdup(*vectorchar);
	if (duplicate == NULL)
		printf("error");

	char* copy = malloc(strlen(*vectorchar)*sizeof(char));
	if (copy == NULL)
		printf("error");

	char* word = strtok(duplicate, SEPARATORS);
	int i = 0;

	while (word) {
		if (i == 0)
			strcpy(copy, word);
		else
			strcat(copy, word);
		i++;
		word = strtok(NULL, SEPARATORS);
	}

	free(duplicate);

	return copy;
}

int main() {

	/*char* well_oriented = (char*)malloc(max_size * sizeof(char));
	well_oriented = read_str(&well_oriented);

	printf("%s\n", well_oriented);

	ordCresc(&well_oriented, 10);

	printf("alphabetic->%s\n", well_oriented);

	lengtho(&well_oriented, 10);

	printf("after length->%s", well_oriented);
	
	char* well_oriented_two = (char*)malloc(max_size * sizeof(char));
	well_oriented_two = read_str(&well_oriented_two);

	reflect_tsamet(&well_oriented_two, 7);

	free(well_oriented);

	char* here_with = (char*)malloc(max_size * sizeof(char));
	here_with = read_str(&here_with);
	
	strtoko(&here_with, 10);

	printf("STRTOK RESULT-->%s", here_with);

	char* here_with_two = (char*)malloc(max_size * sizeof(char));
	here_with_two = read_str(&here_with_two);

	char* annexed = (char*)malloc(max_size * sizeof(char));
	annexed = read_str(&annexed);

	printf("OCCURRENCES OF WORD %s -> %d\n", annexed , occurrence(&here_with_two, annexed));
	*/

	char*here_with_three = (char*)malloc(max_size * sizeof(char));
	here_with_three = read_str(&here_with_three);

	char* annexed_two = (char*)malloc(max_size * sizeof(char));
	annexed_two = read_str(&annexed_two);

	replace(&here_with_three, annexed_two, 8);
	printf("%s", here_with_three);

	return 0;
}
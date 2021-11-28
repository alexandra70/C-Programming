#include <stdio.h>                                                                                                                                                                                                   
#include <string.h>                                                                                                                                                                                                  
#include <ctype.h>
#include <stdlib.h>                                                                                                                                                                                                   

#define SEPARATORS " ,."                                                                                                                                                                                             
#define max_len 20
#define max_age 100
#define max_interogation 10


void add_to_list(char**** matrix, char* nume, char* forename, char* age, int *begin) {

	if (strlen((*matrix)[*begin][0]) == 0) {
		strcpy((*matrix)[*begin][0], nume);
		strcpy((*matrix)[*begin][1], forename);
		strcpy((*matrix)[*begin][2], age);
	}
	
	(*begin)++;
}

void ordered_by_name(char****matrix, char* nume, int begin) {

	for (int i = 0; i < begin; i++) {
		for (int j = i; j < begin; j++) {
			if (strcmp((*matrix)[i][0], (*matrix)[j][0]) > 0) {
				/*char* wordo;
				strcpy(wordo, (*matrix)[i][0]);
				strcpy((*matrix)[i][0], (*matrix)[j][0]);
				strcpy((*matrix)[j][0], wordo);*/
				char** wordo = (*matrix)[i];
				(*matrix)[i] = (*matrix)[j];
				(*matrix)[j] = wordo;
				
			}
		}
	}

}

void ordered_by_forename(char**** matrix, char* nume, int begin) {

	for (int i = 0; i < begin; i++) {
		for (int j = i; j < begin; j++) {
			if (strcmp((*matrix)[i][1], (*matrix)[j][1]) > 0) {
				char** wordo = (*matrix)[i];
				(*matrix)[i] = (*matrix)[j];
				(*matrix)[j] = wordo;

			}
		}
	}

}

void ordered_by_age(char**** matrix, char* age, int begin) {

	for (int i = 0; i < begin; i++) {
		for (int j = i; j < begin; j++) {
			int val_i = atoi((*matrix)[i][2]);
			int val_j = atoi((*matrix)[j][2]);
			if (val_i > val_j) {
				char** wordo = (*matrix)[i];
				(*matrix)[i] = (*matrix)[j];
				(*matrix)[j] = wordo;

			}
		}
	}
}

int read(char* sentence) {

	char chr;
	int i = 0;

	while (scanf("%c", &chr)) {
		if (chr == '\n')
			break;
		else {
			sentence[i] = chr;
			i++;
		}
	}
	sentence[i] = '\0';

	return i;
}

void free_data(char*** matrix, int begin) {

	for (int i = 0; i < begin; i++) {
		for (int j = 0; j < 3; j++)
			free(matrix[i][j]);
		free(matrix[i]);
	}

	free(matrix);

}

int main() {

	int n;
	scanf("%d", &n);
	scanf("\n");
	

	char* nume = malloc(max_len * sizeof(char));
	char* forename = malloc(max_len * sizeof(char));
	char* age = malloc(100 * sizeof(char));
	int begin = 0;

	char*** matrix = (char***)malloc(max_interogation * sizeof(char**));
	for (int i = 0; i < max_interogation; i++) {
		matrix[i] = (char**)malloc(max_len * 3 * sizeof(char*));
		for (int j = 0; j < 3; j++)
			matrix[i][j] = (char*)malloc(max_len * sizeof(char));
	}

	while (n > 0) {
		read(nume);
		read(forename);
		read(age);
		add_to_list(&matrix, nume, forename, age, &begin);
		n--;
	}

	printf("-----------\n");
	ordered_by_name(&matrix, nume, begin);
	
	for (int i = 0; i < begin; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%s\n", matrix[i][j]);
		}
		printf("-----NEXT-student-----\n");
	}

	printf("-----------\n");
	ordered_by_forename(&matrix, forename, begin);

	for (int i = 0; i < begin; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%s\n", matrix[i][j]);
		}
		printf("-----NEXT-student-----\n");
	}
	
	printf("-----------\n");
	ordered_by_age(&matrix, age, begin);

	for (int i = 0; i < begin; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%s\n", matrix[i][j]);
		}
		printf("-----NEXT-student-----\n");
	}

	
	free(nume);
	free(forename);
	free(age);

	free_data(matrix, begin);

	return 0;
}
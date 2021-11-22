#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOC 50
#define NOTE 2
#define INTEROGATION 20
#define MAX_NR 100

/*
În registrul Uni-Struct, fiecărui elev îi corespunde o înregistrare care reține:

numele acestuia (maxim 50 de caractere),

clasa în care acesta se află (o valoare de tipul unsigned int),

rezultatul obținut la materia cea mai apropaiata (ca semnificație) de programare.


Tipul rezultatului diferă în funcție de clasa în care elevul se află, astfel:

elevii din clasele primare (1-4), primesc un calificativ (FB, B, S, I) 
reprezentat ca un șir maxim 9 caractere;

elevii din toate celelalte clase primesc note, care vor fi reținute cu
ajutorul unui câmp de tip float.
Scrieți un program care citește de la tastatură astfel de înregistrări,
până la inserarea șirului de caractere “stop” în locul numelui unuia dintre
elevi, apoi afișează toți studenții din registru, alături de toate informațiile
despre ei, în ordinea lexicografică a numelor cu care sunt înregistrați.

Folosiți un vector de structuri pentru a stoca toate informațiile despre elevi.
Faceți eficient reținerea unei singure valori pentru rezultatul parcurgerii 
materiei în cadrul structurii.

*/

typedef union{

	float adult_note;
	char child_note[3];

} Note;

typedef struct {

	char* name;
	unsigned int the_class;
	Note note;
	
} Student;


Student* alloc() {

	Student* student = (Student*)malloc(MAX_NR * sizeof(Student));

	if (!student) {
		fprintf(stderr, "eroare");
		return NULL;
	}

	for (int i = 0; i < MAX_NR; i++) 
		student[i].name = (char*)malloc(ALLOC * sizeof(char));

	return student;
}


void read(Student* student, int* count) {
	
	int i = 0;

	while (strncmp(fgets(student[(*count)].name, 50, stdin), "stop", 4) != 0) {
		
		scanf("%d\n", &student[(*count)].the_class);
	
		if (student[(*count)].the_class < 5) 		
			fgets(student[(*count)].note.child_note, 5, stdin);

		else 
			scanf("%f\n", &student[(*count)].note.adult_note);
		
		(*count)++;

	}
}

void order(Student* student, int count) {

	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if (strcmp(student[i].name, student[j].name) > 0) {

				Student tmp = student[i];
				student[i] = student[j];
				student[j] = tmp;
			}
		}
	}
}

void print(Student* student, int nr_of_students) {

	for (int i = 0; i < nr_of_students; i++) {

		printf("%s", student[i].name);
		printf("%d\n", student[i].the_class);
		if (student[i].the_class < 5)
			printf("%s", student[i].note.child_note);
		else
			printf("%.f\n", student[i].note.adult_note);
	}

}

int main() {

	int number_of_students = 0;

	Student* student = alloc();
	
	read(student, &number_of_students);

	//print(student, number_of_students);

	student = realloc(student, number_of_students * sizeof(Student));

	order(student, number_of_students);

	for (int i = 0; i < strlen(student[number_of_students - 1].note.child_note); i++) {
		if (student[number_of_students - 1].note.child_note[i] == '\n') {
			
			student[number_of_students - 1].note.child_note[i + 1] = '\0';
			break;
		}
	}

	print(student, number_of_students);

	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define MAX_SIZE 10000
/*

În limbajul C, şirurile de caractere sunt reprezentate în memorie
ca o succesiune de valori de tip char terminate printr-un caracter
special NULL ('\0'). Șirurile de caractere sunt pasate ca parametri
printr-un pointer la primul caracter din şir, şi sunt prelucrate 
până când se întâlneşte caracterul nul, indiferent care este lungimea
reală a zonei alocate. Astfel, un anumit vector de caractere de 
lungime N poate stoca şiruri de caractere de lungime între 0 şi N-1
(pentru că nu considerăm şi caracterul nul ca făcând parte din 
conţinutul şirului).
[1p] Să se scrie o funcţie care calculează lungimea unui şir de 
caractere dat ca parametru
int str_length(char *s);

*/

int str_length(char* s) {

	int i = 0;
	int len = 1;
	s = (char*)malloc(MAX_SIZE * sizeof(char));


	for (int i = 0; i < len + 1; i++) {
		scanf("%c", &s[i]);
		if (s[i] == '\0') {
			break;
		}
		if (s[i] == '\n')
			break;
		len++;
	}
	
	return len;

}
/*
Să se scrie o funcţie pentru ştergerea(eliminarea) a n 
caractere dintr - o poziţie dată a unui şir ce returnează 
adresa șirului de caractere modificat
*/

char* strdel(char* s, int pos, int n) {

	for (int i = 0; i < strlen(s); i++) {
		if((n + i) < strlen(s)) {
			s[pos + i] = s[n + i + 1];
		}
	}

	s = (char*)realloc(s, (strlen(s) - n + pos) * sizeof(char));

	return s;
}
/*

Să se scrie o funcţie pentru inserarea unui şir s2 
într - o poziţie dată pos dintr - un şir s1.Se va presupune
că există suficient loc în vectorul lui s1 pentru a face loc
şirului s2.Funcţia returnează adresa şirului s1.
*/

char* strins(char* s1, int pos, char* s2) {

	int len1 = strlen(s1) - 1;
	int len2 = strlen(s2) - 1;

	char* cop = (char*)malloc(MAX_SIZE * sizeof(char));
	strcpy(cop, s1);

	pos++;//pos is not from 0 inndex

	for (int i = pos; i < len1 + len2 + 1; i++) 
		s1[i + len2] = cop[i];
	
	int j = 0;

	for (int i = pos; i < pos + (len2 + 1); i++) {

		if (s2[j] == '\n')
			break;

		else {
			s1[i] = s2[j];
			printf("+%c+", s2[j]);
			j++;
		}

	}

	return s1;
}
/*
Scrieţi o funcţie care stabileşte dacă un şir dat(format din 
caractere alfanumerice) este egal cu o mască, ce poate 
conţine caractere alfanumerice şi caracterul special '?'.
Se consideră că acest caracter înlocuieşte orice alt caracter
alfanumeric.De exemplu, “abcde” este echivalent cu ” ? bc ? e”.
*/

int eq_mask(char* sir, char* masca) {

	int found = 0;

	if (strlen(sir) == strlen(masca)) {
		for (int i = 0; i < strlen(sir); i++) {

			if (sir[i] == masca[i])
				found++;

			if (masca[i] == '?')
				found++;

		}
	}

	else
		printf("->they have to be the same size\n");

	if (found == strlen(sir)) 
		return 1;
	
	else
		return 0;

}
/*
Scrieţi o funcţie care stabileşte dacă un cuvânt dat se găseşte sau 
nu într - un tablou de cuvinte.
*/

int eqcuv(char* cuv, char** tablou) {

	int i = 0;
	int j = 0;
	while (tablou[i] != "\0") {
		i++;
		if (cuv == tablou[i]) {
			return 1;
		}
		else
			return 0;
	}


}

int true_make(char* cuv, char** tablou) {
	
	int find = 0;

	for (int i = 0; i < 3; i++) {

		for (int l = 0; cuv[l] != '\0'; l++) {
			if (cuv[l] == '\n') {
				cuv[l] = '\0';
				break;
			}
		}
		if (strcmp(cuv, tablou[i]) == 0) {
			find++;
		}
		else
			continue;

	}
	if (find) 
		return 0;
	else
		return 1;
	
}

char* inpstr(char* s) {

	s = (char*)malloc(MAX_SIZE * sizeof(char));
	int find = 0;

	for (int i = 0; i < strlen(s) + 1; i++) {
		scanf("%c", &s[i]);
		if (s[i] == '\n') {
			if (i == 0) {
				find = 1;
				continue;
			}
			else
				break;
		}
	}
	return s;
}

int main() {
	/
	char* s;
	s = inpstr(s);

	int pos, n;
	printf("FOR REDUCTION:");
	scanf("%d%d", &pos, &n);

	s = strdel(s, pos, n);
	printf("%s", s);
	
	int poz;
	scanf("%d", &poz);

	printf("FOR TASK 2:\n");
	printf("INTRO STRING 1:");
	char* str1 = inpstr(str1);
	printf("INTRO STRING 2:");
	char* str2 = inpstr(str2);

	str1 = strins(str1, poz, str2);
	printf("%s", str1);

	char* sirulet;
	sirulet = inpstr(sirulet);

	char* masca;
	masca = inpstr(masca);

	int value = eq_mask(sirulet, masca);

	if (value == 1)
		printf("SIRURI EGALE\n");

	else
		printf("SIRURI INEGALE\n");

	char* tablou[100] = { "curs1", "curs2", "curs3" };
	char* cuv1 = "curs2";
	char* cuv2 = "curs5";
	 
	printf("curs2 %s in tablou\n", (eqcuv(cuv1, tablou)) ? "este" : "nu este");
	printf("curs5 %s in tablou\n", (eqcuv(cuv2, tablou)) ? "este" : "nu este");

	printf("FIRST WORD:");
	char* word = inpstr(word);
	printf("SECOND ONE:");
	char* word2 = inpstr(word2);

	char** table = (char**)malloc(100 * sizeof(char*));

	printf("CUVINTE: ");
	for (int i = 0; i < 3; i++) {
		table[i] = (char*)malloc(MAX_SIZE * sizeof(char));
		
		scanf("%s", table[i]);
	}
	
	int a = true_make(word, table);

	if (a == 0) 
		printf("cuvantul este in tablou\n");
	
	else 
		printf("cuvantul nu este in tablou\n");

	return 0;

}

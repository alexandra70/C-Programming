/*Un num�r lung(cu o valoare mult mai mare dec�t maximul reprezentabil pe
un tip de date �ntreg standard din C), poate fi reprezentat ca un vector
char* v de cifre(considerate valori de tip char), �n felul urm�tor :
v[0] reprezint� num�rul de cifre ale num�rului lung.Lungimea vectorului
�n memorie va fi v[0] + 1.
v[i], unde i este de la 1 la v[0], reprezint� a i - a cifr� a num�rului,
�n ordinea cresc�toare a semnificativit��ii.Astfel v[1] reprezint� cifra 
unit��ilor, v[2] cifra zecilor, etc.O reprezentare eficient� va avea �ntotdeauna
ultima cifr� v[v[0]] nenul�(altfel num�rul de cifre ar fi putut fi mai mic 
�i reprezentarea mai compact�).
[1p] a) Scrie�i o func�ie care construie�te vectorul de cifre asociat unui
num�r �ntreg simplu(de tipul int) :
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100


char* build_number(int value) {

	char* v = (char*)malloc((value + 1) * sizeof(char));
	char* number = (char*)malloc((value) * sizeof(char));
	scanf("%s", number);

	for (int i = 0; i <= value + 1; i++) {
		if (i == 0)
			v[0] = value;
		if(i) {	
			v[i] = number[value - i];
		}
		
	}

	return (v+1);
}
/*
Scrie�i o func�ie care adun� dou� numere lungi �i �ntoarce ca rezultat
un alt num�r lung :
*/

char* add_numbers(char* a, char* b) {
	
	int len;
	char* add;
	int rest = 0;

	if (strlen(a) >= strlen(b)) {
		len = strlen(a);
		add = (char*)malloc(len * sizeof(char));

		for (int i = 0; i < strlen(b); i++) {
			if ((((int)(a[i] + b[i]) - 48)) + rest <= 57) {
				add[i] = ((char)((int)(a[i] + b[i]) - 48 + rest));
				rest = 0;
			}

			else {
				add[i] = (char)(((int)(a[i] + b[i]) - 48 - 48 + rest) % 10 + 48);
				rest = 1;
			}
		}

		for (int i = strlen(b); i < len; i++) {
			if ((int)((int)a[i] + rest) + rest <= 57) {
				add[i] = (char)((int)a[i] + rest);
				rest = 0;
			}
			if ((int)((int)a[i] + rest) > 57) {

				add[i] = (char)(((int)a[i] + rest) % 10);
				rest = 1;
			}
		}

	}
		
	else {
		len = strlen(b);
		add = (char*)malloc(len * sizeof(char));
		for (int i = 0; i < strlen(a); i++) {
			if ((((int)(a[i] + b[i]) - 48)) + rest <= 57) {
				add[i] = ((char)((int)(a[i] + b[i]) - 48 + rest));
				rest = 0;
			}

			else {		
				add[i] = (char)(((a[i] + b[i]) - '0' - '0' + rest) % 10 + '0' );
				rest = 1;
			}
		}
		for (int i = strlen(a); i < len; i++) {
			if ((int)((int)b[i] + rest) + rest <= 57) {
				add[i] = (char)((int)b[i] + rest);
				rest = 0;
			}
			if ((int)((int)b[i] + rest) > 57) {
				
				add[i] = (char)(((int)b[i] + rest) % 10);
				rest = 1;
			}

		}
	}
	if (rest == 1) {
		add = realloc(add, len + 1);
		add[len] = (char)('1');
	}
	
	return add;
}


int main() {

	int value;
	printf("NUMBER LEN:->");
	scanf("%d", &value);

	char* v;

	v = build_number(value);

	printf("%s\n", v);

	int val1, val2;
	printf("NUMBER LEN FOR FIRST NR:->");
	scanf("%d", &val1);
	printf("NUMBER LEN FOR SECOND NR:->");
	scanf("%d", &val2);

	char* a = (char*)malloc((value) * sizeof(char));
	a = build_number(val1);
	char* b = (char*)malloc((value) * sizeof(char));
	b = build_number(val2);
	printf("formate:->\n");
	printf("%s\n", a);
	printf("%s\n", b);

	char* add;
	add = add_numbers(a, b);
	
	for (int i = strlen(add) - 1; i >= 0; i--) {
		printf("%c", add[i]);	
	}
	printf("\n");
	
	free(add);
	
	
	return 0;
}
/*
Scrieþi un program care calculeazã ºirul Fibonacci 
folosind numere lungi.Se cer primii 100 de termeni ai ºirului,
afiºaþi pe câte o linie în parte.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* add_numbers(char* a, char* b) {

	int len = 0;
	if (strlen(a) >= strlen(b)) {
		len = strlen(a);
	}
	else
		len = strlen(b);
	int rest = 0;

	char* add = malloc(len * sizeof(char));

	int c = strlen(a);
	int r = strlen(b);

	for (int i = 0; i < len; i++) {
		if ((c - i - 1) >= 0) {
			if ((r - i - 1) < 0) {
				if (a[c - i - 1] + rest > 57) {
					add[i] = (a[c - i - 1] - 48 + rest) % 10 + 48;
					rest = 1;
					continue;
				}
				else {
					add[i] = a[c - i - 1] + rest;
					rest = 0;
					continue;
				}
			}
		}

		if ((r - i - 1) >= 0) {
			if (c - i - 1 >= 0) {
				if ((a[c - i - 1] + b[r - i - 1] - 48 + rest) > 57) {
					add[i] = (b[r - i - 1] + a[c - i - 1] - 96 + rest) % 10 + 48;
					rest = 1;
					continue;
				}
				else {
					add[i] = b[r - i - 1] + a[c - i - 1] - 48 + rest;
					rest = 0;
					continue;
				}
			}
			else {
				if (b[r - i - 1] + rest > 57) {
					add[i] = (b[r - i - 1] - 48 + rest) % 10 + 48;
					rest = 1;
					continue;
				}
				else {
					add[i] = b[r - i - 1] + rest;
					rest = 0;
					continue;
				}
			}
		}
	}


	if (rest == 1) {
		add = realloc(add, len + 1);
		add[strlen(add)] = '1';
	}
	
	int final_len = strlen(add);
	char* copy = malloc(final_len * sizeof(char));

	for (int i = 0; i < final_len; i++) {
		copy[final_len - 1 - i] = add[i];	
	}

	strcpy(add, copy);
	free(copy);

	return add;

}

//b devine suma dintre el si anteriorul lui 

void fiboboi(char** a, char** b) {

	char* suma = add_numbers(*a, *b);
	strcpy(*a, *b);
	strcpy(*b, suma);	
	printf("SUM %s ", suma);
	printf("\n");
	
}
char* multiply_numbers(char* a, char* b) {

	int lol = atoi(b);
	char* suma = "0";
	int prod = 0;
	for (int i = 0; i < lol; i++) {
		suma = add_numbers(suma, a);
	}
	return suma;
}
/*
Scrieþi un program care calculeazã factorialul numerelor de la
1 la 50, afiºând câte un numãr pe fiecare linie.
*/

void facto(int n) {

	char* fact = "1";
	char* stay_one = "1";
	char* you_have_to_change = "1";
	for (int i = 1; i < n + 1; i++) {

		fact = multiply_numbers(fact, you_have_to_change);
		you_have_to_change = add_numbers(you_have_to_change, stay_one);
		printf("fact - %s yhtc - %s  \n", fact, you_have_to_change);
	}

}

int main() {

	int len1, len2;
	scanf("%d%d", &len1, &len2);

	char* a = malloc(len1 * sizeof(char));
	char* b = malloc(len2 * sizeof(char));

	printf("INTRO NUMBA:");
	scanf("%s", a);
	scanf("%s", b);

	char* add = add_numbers(a, b);

	for (int i = 0; i < strlen(add); i++) {
		printf("%c", add[i]);
	}
	printf("SUM %s\nSUM %s\n", a, b);
	for (int i = 0; i < 7; i++) {
		
		fiboboi(&a, &b);
	}

	char* any = multiply_numbers(a, b);
	printf("%s\n", any);
	
	printf("INRO n->");
	int n;
	scanf("%d", &n);
	facto(n);


	free(a);
	free(b);
	free(add);
	return 0;
}
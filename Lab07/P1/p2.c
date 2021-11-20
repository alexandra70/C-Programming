#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
/*Problema 2
----------

Sa se scrie o functie care are urmatoarea declaratie: 

	void filter (int (*f) (int), int *v, int *n).

Functia trebuie sa modifice vectorul v, pastrand in vector doar
elementele pentru care f intoarce “Adevarat” (il codificati cum doriti).

	n reprezinta lungimea vectorului si se va modifica dupa apelul 
	functiei la noua dimensiune a vectorului.

Va trebui sa se scrie si o functie f pentru a testa functionalitatea 
 (de exemplu sa verifice daca un element este par sau nu -> int isEven(int x) )."

Aceasta problema nu contine teste.
*/


void filter(int (*f) (int), int* v, int* n){

	int m = (int)*n;
	//printf("%d\n", m);

	int* w = (int*) malloc(m * sizeof(int));
	int j = 0;


	for (int i = 0; i < m; i++) {
		
		if ((*f)(v[i])) {
			w[j] = v[i];
			j++;
			//printf("%d ", v[i]);
		}
		else
			continue;
	}
	for (int i = 0; i < j; i++) {

		v[i] = w[i];
	}
	m = j;

	//printf("\n");
	//printf("%d\n", m);
	*n = m;
	//printf("%d\n", *n);
}

int isEvan(int x) {
	if (x % 2 == 0) {
		return 1;
	}
	else
		return 0;
}

int main() {

	int n;
	scanf("%d", &n);

	int* v = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", v + i);
	}

	filter(isEvan , v, &n);

	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}


	return 0;

}

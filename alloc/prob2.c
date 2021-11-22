/*
* 
Sã se scrie un program care citeºte de la tastaturã un numãr pozitiv n
împreunã cu alt numãr pozitiv max. Programul va aloca apoi dinamic un vector
de întregi de n elemente, pe care îl va iniþializa cu numere aleatoare în
intervalul [0..max-1]. Sortaþi vectorul, folosind metoda preferatã,
afiºându-i conþinutul atât înainte, cât ºi dupã ce sortarea a avut loc.

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void alloc(int** v, int n, int max) {

	*v = (int*)malloc(n * sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		int r = rand() % (max - 1);
		(*v)[i] = r;
	}

}

void sort(int** v, int n) {

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((*v)[i] > (*v)[j]) {
				int exch = (*v)[i];
				(*v)[i] = (*v)[j];
				(*v)[j] = exch;
			}
		}
	}
}

void printo(int* v, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main() {

	int* v;
	int n;
	int m;

	scanf("%d%d", &n, &m);

	alloc(&v, n, m);
	printo(v, n);
	
	sort(&v, n);
	printo(v, n);

	return 0;
}

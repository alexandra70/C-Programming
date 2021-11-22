/*
* 
S� se scrie un program care cite�te de la tastatur� un num�r pozitiv n
�mpreun� cu alt num�r pozitiv max. Programul va aloca apoi dinamic un vector
de �ntregi de n elemente, pe care �l va ini�ializa cu numere aleatoare �n
intervalul [0..max-1]. Sorta�i vectorul, folosind metoda preferat�,
afi��ndu-i con�inutul at�t �nainte, c�t �i dup� ce sortarea a avut loc.

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

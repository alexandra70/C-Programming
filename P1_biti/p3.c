#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
/*Bonus
-----

Sã se scrie o funcþie pentru calculul integralei definite pe un
interval dat [a,b] a unei funcþii
oarecare (cu rezultat real) f(x), prin metoda trapezelor, cu un
numãr dat de paºi.

	double calculateIntegral(double (*func) (double x), double a,
	double b, int n ).
	
	f -> functia pe care aplicam integrala. Primeste parametrul x
	si intoarce f(x).
	a si b sunt capetele intervalului (a < b mereu);
	n este numarul de subintervale egale in care dorim sa impartim
	intervalul [a, b].

Cu cat n este mai mare, cu atat functia va returna o valoare mai precisa.

Aceasta problema nu contine teste.

*/


double calculateIntegral(double (*func) (double x), double a, double b, int n) {

	double h;
	h = (b - a) /n;

	double sum = (*func)(a) + (*func)(b);

	for (int i = 1; i < n; i++) {
		sum += 2 * (*func)(a + i * h);
	}

	double res = (sum * h) / 2;
	return res;
}


double f(double x) {

	return x;
	
}

int main() {

	int n;
	double a;
	double b;
	scanf("%d %lf %lf", &n, &a, &b);

	double res = calculateIntegral(f, a, b, n);

	printf("%lf\n", res);

	return 0;

}

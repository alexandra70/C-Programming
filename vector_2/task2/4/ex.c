#include<stdio.h>

#define MAX 100
int main() {
	int n;
	scanf("%d", &n);

	int v[100];
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int primul, ultimul;
	for (int i = 0; i < n; i++) {
		if (v[i] % 2) {
			primul = i;
			break;
		}
	}
	for (int i = n; i > 0; i--) {
		if (v[i] % 2) {
			ultimul = i;
			break;
		}
	}

	int suma = 0;

	for (int i = primul; i <= ultimul; i++) {
		suma = suma + v[i];
	}
	printf("%d\n", suma);
	return 0;

}
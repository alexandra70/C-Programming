#include<stdio.h>

//#define MAX 10

int main() {
	int n;
	scanf("%d", &n);

	int min=1000;
	int max= 0;
	int v[100];

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	//for (int i = 0; i < n; i++) {
	//	printf("%d ", v[i]);
	//}

	for (int i = 0; i < n; i++) {
		
		if (v[i] < min) {
			min = v[i];

		}
		if (v[i] > max) {
			max = v[i];
		}

	}


	int verifica;
	int k = 0;
	verifica = max - min;

	for (int i = 0; i < n; i++) {
		if (v[i] == verifica)
			k++;
		else
			continue;
	}
	//printf("%d\n", min);
	//printf("%d\n", max);
	//printf("%d\n", verifica);
	printf("%d", k);
	printf("\n");

	return 0;
}
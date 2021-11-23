#include<stdio.h>
#include<math.h>
//7. Aplicati o functie pe fiecare element al 
//unui vector dat. (elementele sunt numere intregi
//la fel si rezultatele).
//Ex: n = 5	 v = [1	2	3	4	 5] si k = 2 se va afisa[2	4	6	8	 10].
//n = 5	 v = [1	2	3	4	 5] si k = 3 se va afisa[1	4	9	16	 25].

#define MAX 100
int main() {
	int n, k;
	scanf("%d", &n);

	int v[MAX];
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	scanf("%d", &k);

	if (k == 0) {
		for (int i = 0; i < n; i++) {
			v[i]++;
			printf("%d ", v[i]);
		}
	}
	//printf("\n");

	if (k == 1) {
		for (int i = 0; i < n; i++) {
			v[i] *= 2;
			printf("%d ", v[i]);
		}
	}

	if (k == 2) {
		for (int i = 0; i < n; i++) {
			v[i]/=2;
			printf("%d ", v[i]);
		}
	}

	if (k == 3) {
		for (int i = 0; i < n; i++) {
			v[i] = v[i]*v[i];
			printf("%d ", v[i]);
		}
	}

	float a[MAX];

	if (k == 4) {
		for (int i = 0; i < n; i++) {
			a[i] = sqrt(v[i]);
			printf("%f ", a[i]);
		}
	}

	return 0;

}
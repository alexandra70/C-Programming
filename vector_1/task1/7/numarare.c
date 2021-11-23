#include<stdio.h>

int sortare(int n, int v[100]){
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (v[i] > v[j]) {
				int schimb = v[i];
				v[i] = v[j];
				v[j] = schimb;
			}
		}
	}
	return *v;
}


int main() {

	int n;
	scanf("%d", &n);

	int v[100];

	for (int i = 0; i < n; i++) 
		scanf("%d", &v[i]);
	
	sortare(n, v);
	int suma = 1, copy[100];
	for (int i = 0; i < n; i++) {
		
		if (v[i] == v[i + 1]) {
			suma++;
			copy[i] = suma;
			//printf("%d ", suma);
			continue;
		}
		else if (v[i] != v[i + 1]) {
			suma = 1;
			copy[i] = suma;
			//printf("%d ", suma);
		}
		
	}

	printf("\n");

	
	for (int i = 0; i < n; i++) {
		if (v[i] != v[i + 1] )
			printf("%d ", v[i]);
		//if (copy[i] != copy[i + 1])
			//return 0;
			//printf("%d\n", copy[i]);
		
	}

	printf("\n");
	for (int i = 0; i < n-1; i++) {
		
			printf("%d ", copy[i]);
	}
	return 0;
}
#include<stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	long vector[100] = { 1,1 };
	//first 2 elements of the vector are 1 and 1, so
	//aka v[0] = 1;
	//v[1] = 1;
	for (int i = 2; i < n; i++) {
		vector[i] = vector[i - 1] + vector[i - 2];
		//printf("%ld ", vector[i]);

	}
	for (int i = 0; i < n; i++) {
		printf("%ld ", vector[i]);

	}
	return 0;
}

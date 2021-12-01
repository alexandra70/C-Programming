#include<stdio.h>

#define MAX 6


int binary_search(int n, int v[n], int x){
	
	int first = 0;//index sort of
	int last = n - 1;//last index for calculating the middle
	int mid;

	while (first <= last) {
		mid = first + (last - first) / 2;

		if (v[mid] == x) {
			return mid;//am gasit
		}
		if (v[mid] > x)
			last = mid - 1;
		else if (v[mid] < x) {
			first = mid + 1;
		}
	}

	return -1;//nu am gasit nimic

}


int main() {
	int NeOprim = 0;
	int vector[MAX];
	int x, n; //cat nr am si valoarea pe care o caut

	scanf("%d\n", &x);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &vector[i]);
	}

	

	int a = binary_search(n, vector, x);
	printf("%d", a);

	return 0;


}
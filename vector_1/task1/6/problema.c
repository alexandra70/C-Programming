#include<stdio.h>


int main() {
	int n;
	scanf("%d", &n);

	int v[100];

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	
	int k, intro;
	scanf("%d  %d",  &intro, &k);
	
	
	//for (int i = 0; i < n; i++) {
		//pastram = v[k];
	//}
	//printf("%d ", pastram);


	for(int i = 0; i < n; i++) {
		
		if (i == k) {
			n++;
		}
		
		//v[k] = k;
		
	}
	for (int j = n; j > k; j--) {
		v[j] = v[j - 1];
		
	}


	v[k] = intro;

	for(int i = 0; i < n; i++) {
			
		printf("%d ", v[i]);
	}

	printf("\n");



	return 0;
}
#include<stdio.h>


#define MAX 6
//cautam in vector chestii - mai exact x
int main() {
	int NeOprim = 0;
	int vector[MAX];
	int x;//ce cautam
	//int i;

	scanf("%d", &x);

	for (int i = 0; i < MAX; i++) {
		scanf("%d", &vector[i]);
	}

	for (int i = 0; i < MAX; i++) {
		if (vector[i] == x) {
			NeOprim = 1;//am gasit
			break;
		}
		else
			continue;
	}

	if (NeOprim) {
		printf("am gasit %d", x);
	}
	else
		printf("nop, nop");

	return 0;
	 

}
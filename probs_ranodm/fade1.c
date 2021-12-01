#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int numarul, puterea;
	printf("INTRODUCETI O VALOARE INTRE 0 SI 5---->");

	scanf("%d", &numarul);
	
	puterea = 1;

	switch (numarul) {
	case 5:
		puterea = numarul*numarul;
		printf("%d\n", puterea);
		break;
	case 4:
		puterea = numarul*numarul;
		printf("%d\n", puterea);
		break;
	case 3:
		puterea = numarul*numarul;
		printf(" %d\n", puterea);
		break;
	case 2:
		puterea = numarul*numarul;
		printf("%d\n", puterea);
		break;
	case 1:
		puterea = 1;
		printf("%d\n", puterea);
		break;
	case 0:
		puterea = 1;
		printf("\n %d\n", puterea);
		break;

	default:
			printf("Nu este in in intervalul 0 - 5");
	}
	return 0;
}
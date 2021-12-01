#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	
	
	char c;
	
	printf("Alege o optinune a. b. c");
	scanf("%c", &c);

	switch (c) {
	case 'a':
		printf("afisare");
		break;
	case 's':
		printf("steregere");
		break;
	case 'e':
		printf("exit");
		break;
	default:
		printf("Ooptinune inexistenta");
		break;
	}

	return 0;
}
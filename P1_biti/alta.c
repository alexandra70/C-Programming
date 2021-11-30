#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define MAX_SIZE 100


char* inpstr(char* s) {

	int i = 0;

	s = (char*)malloc(MAX_SIZE * sizeof(char));
	if (s == NULL)
		printf("esec\n");

	while( scanf("%c", &s[i]) == 1){
		if (s[i] == '\n')
			break;
		i++;
	}

	printf("%d", i);
	return s;
}



int main() {

	char* s1; 
	s1 = inpstr(s1);
	
	char* s2;	
	s2 = inpstr(s2);



	return 0;

}

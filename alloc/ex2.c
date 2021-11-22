#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* copy_string(char* s) {
	
	char* d;

	int length = strlen(s) + 1; //++ '\0'

	d = (char*)malloc(length * sizeof(char));

	if (d == "\0") {
		return NULL;
	}

	else
		strcpy(d, s);

	return d;
}
//modific vectorul de pointeri si functia returneaza nr de siruri citite;
int readstr(char** vp) {
	
	int i = 0;
	char sir[80];
	char* p;

	while (scanf("%s", sir) == 1) {
		p = malloc(strlen(sir) + 1);
		strcpy(p, sir);
		//pun in vector p;
		vp[i] = p;
		i++;
	}

	return i;
}

void printstr(char** vp, int i) {

	for (int j = 0; j < i; j++) {
		printf("%s\n", vp[j]);
	}

}

void sortstr(char** vp, int i) {
	
	char* exch;
	
	for (int j = 0; j < i; j++) {
		for (int x = j + 1; x < i - 1; x++) {
			if (strcmp(vp[j], vp[x]) > 0) {
				exch = vp[j];
				vp[j] = vp[x];
				vp[x] = exch;
			}
			/*if (strcmp(vp[x], vp[x + 1]) > 0) {
				exch = vp[x];
				vp[x] = vp[x+1];
				vp[x+1] = exch;
			}*/
		}
	}

}

int main() {

	char s[80];
	char* d;
	int task;
	scanf("%d", &task);

	if (task == 1) {
		do {
			if (fgets(s, 80, stdin) == "\0") {
				break;
			}

			//copy the string into d
			d = copy_string(s);
			if (d != "\0") {
				fputs(d, stdout);
				free(d);
			}
			else {
				printf("alloc has gone wrong");
				return 1;
			}

		} while (1);
	}
	//Vector de pointeri la ºiruri alocate dinamic
	if (task == 2) {

		int n;
		char* vp[1000];

		n = readstr(vp);
		sortstr(vp, n);
		printstr(vp, n);
	}

	return 0;
}

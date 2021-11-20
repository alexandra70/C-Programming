#include<stdio.h>
#define SET_SIZE 100  

typedef unsigned char SET[SET_SIZE]; 

int is_even(int n) {
	int shift = 1;
	
	if ((shift & n) == 0) {
		printf("is\n");
	}
	else
		printf("isn't\n");
}

int pow2(int n) {
	int p = 0;
	p = 1 << n;

	return p;
}
int flip_bits(int n) {
	return ~n;
}

void print_bits(int n) {
	int number;
	for (int i = 0; i < 32; i++) {
		number = 1 << (31 - i);
		if ((n & number) != 0) {
			printf("1");
		}
		else
			printf("0");
	}
	printf("\n");
}

int is_power2(int n) {

	int mask;
	int find = 0;

	for (int i = 0; i < 32; i++) {
		mask = 1 << (31 - i);
		if ((mask & n) != 0) {
			find++;
		}
		else
			continue;
	}
	if (find == 1)
		printf("is power");
	else
		printf("isn't");

	printf("\n");
}

void insert_in_set(SET s, unsigned int n) {
	int mask;
	for (int i = 0; i < 32; i++) {
		mask = 1 << (31 - i);
		if ((mask & n))
			s[i] = 1;
		else
			s[i] = 0;
	}
	for (int i = 0; i < 32; i++) {
		printf("%d", s[i]);
	}
	printf("\n");
}

void delete_from_set(SET s, unsigned int n) {
	int mask;
	for (int i = 0; i < 32; i++) {
		mask = 1 << (31 - i);
		if ((mask & n)) 
			s[i] = 0;
	}
	for (int i = 0; i < 32; i++) {
		printf("%d", s[i]);
	}
	printf("\n");
}
void delete_all_from_set(SET s) {
	for (int i = 0; i < 32; i++) {
		if (s[i] == 1) {
			s[i] = 0;
		}
		else
			continue;
	}
}
void print_set(SET s) {

	for (int i = 0; i < 32; i++) 
		printf("%d", s[i]);
	printf("\n");

}
int card_set(SET s) {

	int find = 0;

	for (int i = 0; i < 32; i++) {
		if (s[i]) {
			find++;
		}
		else
			continue;
	}
	return find;
}

int is_empty_set(SET s) {

	int find = 0;

	for (int i = 0; i < 32; i++) {
		if (s[i]) {
			find++;
		}
		else
			continue;
	}
	if (find == 0)
		return 1;
	else
		return 0;
}

int read_set(SET s) {
	
	int n;
	scanf("%d", &n);
	
	int elem;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &elem);
		int mask;
		for (int j = 0; j < 32; j++) {
			mask = 1 << (31 - j);
			if ((mask & elem))
				s[j] = 1;
		}
	}

	return n;
}
int main() {

	int n;
	SET s;

	for (int i = 0; i < SET_SIZE; i++) {
		printf("%d\n", s[i]);
	}

	int elemente = read_set(s);
	printf("%d\n", elemente);

	print_set(s);

	/*
	int n2;
	scanf("%d", &n2);

	is_even(n);

	int m = pow2(n);
	printf("%d\n", m);

	int flip = flip_bits(n);
	printf("%d\n", flip);
	
	print_bits(n);

	is_power2(n);

	SET s;

	for (int i = 0; i < 32; i++) {
		s[i] = 0;
	}

	insert_in_set(s, n);

	insert_in_set(s, n2);

	delete_from_set(s, n);

	delete_all_from_set(s);

	print(s);

	card_set(s);

	int find = card_set(s);
	printf("%d\n", find);

	int state = is_empty_set(s);
	printf("RETURN THE STATE:");
	printf(" %d\n", state);
	*/

	return 0;

}
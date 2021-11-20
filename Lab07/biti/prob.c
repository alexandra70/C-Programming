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

void insert_in_set(SET s, unsigned int n) {
	
	int c = n;
	int i = c / 8;
	int j = c % 8;

	s[i] += 1 << j;
	
}

void delete_from_set(SET s, unsigned int n) {
	
	int c = n;
	int i = c / 8;
	int j = c % 8;

	s[i] -= 1 << j;


}

int is_in_set(SET s, unsigned int n) {

	int i = n / 8;
	int j = n % 8;

	if (((s[i] << (7 - j)) >> 7))
		printf("1\n");
	else
		printf("0\n");

}


void delete_all_from_set(SET s) {

	for (int i = 0; i < SET_SIZE; i++) 
		s[i] = 0;
}

void print_set(SET s) {
	int matrix[SET_SIZE][8];

	for (int i = 0; i < SET_SIZE; i++) {
		for (int j = 0; j < 8; j++) {
			int mask = 1 << (7 - j);
			if ((s[i] & mask))
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < SET_SIZE; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}

}
int card_set(SET s) {

	int find = 0;

	for (int i = 0; i < SET_SIZE; i++) {
		if (s[i]) {
			for (int j = 0; j < 8; j++) {
				int numar;
				numar = 1 << j;
				if ((s[i] & numar) == 0)
					continue;
				else
					find++;
			}
		}
		else
			continue;
	}
	return find;
}

int is_empty_set(SET s) {

	int find = 0;

	for (int i = 0; i < SET_SIZE; i++) {
		if (s[i]) {
			find = 1;
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

	int numar;

	for (int k = 0; k < n; k++) {
		scanf("%d", &numar);
		int i = numar / 8;
		int j = numar % 8;

		if((s[i] >> j) % 2 == 0)
			s[i] += (1 << j);
		
	}

	return n;
}

void merge_set(SET a, SET b, SET c) {

	for (int i = 0; i < SET_SIZE; i++) {
		for (int j = 0; j < 8; j++) {
			if (((a[i] >> j) % 2) != 0) {
				c[i] += 1 << j;
			}

			if (((c[i] >> j) % 2) != 0)
				continue;
			else {
				if (((b[i] >> j) % 2) != 0) {
					c[i] += 1 << j;
				}
			}
		}
	}
}

void intersect_set(SET a, SET b, SET c) {

	for (int i = 0; i < SET_SIZE; i++) {
		for (int j = 0; j < 8; j++) {
			if ((((a[i] >> j) % 2) != 0) && (((b[i] >> j) % 2) != 0))
				c[i] += 1 << j;
			else
				continue;

		}
	}

}


void diff_set(SET a, SET b, SET c) {

	for (int i = 0; i < SET_SIZE; i++) {
		for (int j = 0; j < 8; j++) {
			if ((((a[i] >> j) % 2) != 0) && (((b[i] >> j) % 2) != 0))
				continue;
			if (((a[i] >> j) % 2) != 0) 
				c[i] += 1 << j;
		}
	}
}


int msb(int n) {

	int number = 0;//prima putere a lui 2
	int power = 1;

	while (n > power) {
		if (number == 0) 
			power = 1;
		else 
			power = 1 << number;//nr la putere
		number++;
	}
	if (n == power) {
		printf("%d\n", (power));
	}
	else
		printf("%d\n", power >> 1);
}

int lsb(int n) {

	int mask = 1;
	int less_sbit = 0;

	if ((n & mask)) {
		less_sbit = 1;
		printf("%d\n", less_sbit);
	}
	else
		printf("%d\n", less_sbit);

}

int main() {

	int no;
	scanf("%d", &no);

	msb(no);
	
	lsb(no);

	SET s;
	SET a;
	SET b;
	SET c;

	print_set(a);
	printf("------------\n");
	print_set(b);

	delete_all_from_set(a);
	delete_all_from_set(b);
	delete_all_from_set(c);

	print_set(a);
	printf("-----LIMIT BEFORE READ-------\n");
	print_set(b);

	int n, m;
	n = read_set(a);
	printf("limit\n");
	m = read_set(b);

	print_set(a);
	printf("------LIMIT AFTER READ------\n");
	print_set(b);

	merge_set(a, b, c);

	printf("------MERGE-SET------\n");
	print_set(c);

	delete_all_from_set(c);
	intersect_set(a, b, c);

	printf("------INTERSECT------\n");
	print_set(c);

	delete_all_from_set(c);
	diff_set(a, b, c);

	printf("------DIFF------\n");
	print_set(c);

	return 0;

}

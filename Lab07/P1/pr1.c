#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*�n reprezentarea unui num�r �ntreg pe mai mul�i octe�i(de exemplu
un short sau un int), se pune problema ordinii �n care apar
octe�ii �n memorie.Astfel, exist� dou� moduri de reprezentare :
Big - endian(�n care primul octet din memorie este cel mai semnificativ)
Little - endian(�n care primul octet din memorie este cel mai 
pu�in semnificativ)
Se cere s� se scrie un program care s� determine endianess - 
ul calculatorului pe care este compilat �i rulat, �i s� afi�eze 
un mesaj corespunz�tor pe ecran.*/



int main() {


	int num = 1;


	if (*(char*)&num == 1)
	{
		printf("\nLittle-Endian\n");
	}
	else
	{
		printf("Big-Endian\n");
	}


	return 0;

}

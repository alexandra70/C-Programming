#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*În reprezentarea unui numãr întreg pe mai mulþi octeþi(de exemplu
un short sau un int), se pune problema ordinii în care apar
octeþii în memorie.Astfel, existã douã moduri de reprezentare :
Big - endian(în care primul octet din memorie este cel mai semnificativ)
Little - endian(în care primul octet din memorie este cel mai 
puþin semnificativ)
Se cere sã se scrie un program care sã determine endianess - 
ul calculatorului pe care este compilat ºi rulat, ºi sã afiºeze 
un mesaj corespunzãtor pe ecran.*/



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

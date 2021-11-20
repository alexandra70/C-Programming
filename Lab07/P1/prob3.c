#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<math.h>

#define MAX_SIZE 100
#define mini 1.0
#define maxi 10.0
#define jump 0.1
/*
* 
Scrieþi un program care afiºeazã valorile functiilor sqrt, 
sin, cos, tan, exp ºi log, în intervalul[1..10], cu pasul 0.1.
În acest scop, se creeazã un tablou de pointeri la aceste funcþii
ºi se apeleazã funcþiile în mod indirect prin aceºti pointeri.

*/

int loop = 1;

double listf(double (*f) (double), double min, double max, double pas) {

    double func;
    
    if (loop == 1) {
        for (double x = min; x <= max; x += pas) {
            func = (*f)(x);
            printf("func cos(%lf) is equal = > %.10lf\n", x, func);
        }
    }
    if (loop == 2) {

        for (double x = min; x <= max; x += pas) {
            func = (*f)(x);
            printf("func sin(%lf) is equal = > %.10lf\n", x, func);
        }
    }
    if (loop == 3) {

        for (double x = min; x <= max; x += pas) {
            func = (*f)(x);
            printf("func tan(%lf) is equal = > %.10lf\n", x, func);
        }
    }
    if (loop == 4) {

        for (double x = min; x <= max; x += pas) {
            func = (*f)(x);
            printf("func exp(%lf) is equal = > %.10lf\n", x, func);
        }
    }
    if (loop == 5) {

        for (double x = min; x <= max; x += pas) {
            func = (*f)(x);
            printf("func log(%lf) is equal = > %.10lf\n", x, func);
        }
    }
    if (loop == 6) {

        for (double x = min; x <= max; x += pas) {
            func = (*f)(x);
            printf("func sqrt(%lf) is equal = > %.10lf\n", x, func);
        }
    }

    loop++;
    
    return func;
}

int main(void) {

    listf(cos, mini, maxi, jump);

    listf(sin, mini, maxi, jump);

    listf(tan, mini, maxi, jump);

    listf(exp, mini, maxi, jump);

    listf(log, mini, maxi, jump);

    listf(sqrt, mini, maxi, jump);

    return 0;
}
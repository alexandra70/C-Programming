#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int nr, i,n;
    int prim = 1;

    scanf("%d", &n);
    for (nr = 1; nr <= n; nr++) {
        prim = 1;

        if (nr == 1)
            continue;

        if (nr % 5 == 4) 
            nr = nr + 1;
        
        int rest;

        rest = nr % 10;
        /*switch (rest) {
        case '1':
            printf("%d", nr);
            break;
            
        case '2':
            printf("%d", nr / 10);
            break;

        case '3':
            goto e;

        case '5':
            n = n + 1;
            break;
        }*/
        if (rest == 1)
            printf("%d\n", nr);
        else if (rest == 2)
            printf("%d\n", nr / 10);
        //else if (rest == 3)
           // goto e;
        else if (rest == 5)
            n++;
        
        e:
        for (i = 2; i <= nr/2; i++) {
            if (nr % i == 0) {
                //printf("%d ", i);
                prim = 0;
                break;
            }
        }

        if (prim) {
            printf("Numarul %d este prim\n", nr);
        }

        if (prim == 0) {
            printf("Numarul %d nu este prim\n", nr);
        }

        printf("\n");
    }
    return 0;
}
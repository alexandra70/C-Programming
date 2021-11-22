#include <stdio.h>
#include <stdlib.h>
int n;
char* build_number(int value) {
    int i;
    char* point = malloc(value * sizeof(char*) + 1);
    point[0] = (char)value;
    scanf("%s", point + 1);
    return point;
}
char* add_numbers(char* a, char* b) {

    int i;
    for (i = 1; i <= n; i++) {
        if (a[i] + b[i] - 48 > '9') {
            a[i] = (char)(((int)a[i] + (int)b[i] - 48) % 10 - 48);
            a[i + 1] = (char)((int)a[i + 1] + 1 - 48);

        }
        else
            a[i] = (char)((int)a[i] + (int)b[i] - 48);
    }
    return a;

}
int main()
{
    int i;
    char* v, * w;
    scanf("%d", &n);
    v = (char*)malloc(n * sizeof(char*) + 1);
    v = build_number(n);
    v[0] = n;
    printf("%s", v + 1);
    printf("\n");
    w = (char*)malloc(n * sizeof(char*) + 1);
    w[0] = n;
    w = build_number(n);
    w = add_numbers(w, v);

    printf("%s", w + 1);

    free(v);
    free(w);
    return 0;
}
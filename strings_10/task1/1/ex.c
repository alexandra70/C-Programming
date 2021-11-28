#include <stdio.h>                                                                                                                                                                                                   
#include <string.h>                                                                                                                                                                                                  
#include <ctype.h>
#include <stdlib.h>                                                                                                                                                                                                   

#define SEPARATORS " ,."                                                                                                                                                                                             

int count_lowercases_words(char* str)
{
    char* tmp_str = strdup(str);//duplicare sir = strdup
    unsigned int count = 0;

    if (tmp_str == NULL) {
        printf("Eroare la alocare\n");
        return -1;
    }

    char* word = strtok(tmp_str, SEPARATORS);//strtok = imparte sirul in separatori
    while (word) { // dc e orice numa null nu fa ce vrei
        unsigned int i;

        for (i = 0; i < strlen(word); i++) {
            if (isupper(word[i])) {
                break;
            }
        }

        if (i == strlen(word)) {
            count++;
        }

        word = strtok(NULL, SEPARATORS);
    }

    free(tmp_str);//eliberare pt strdup
    return count;
}

/*
Sa se realizeze o functie care intoarce un sir de caractere compus
din cuvintele care incep cu litera mare.
*/

char* enclosed(char* str) {

    char* copy = strdup(str);

    if (copy == NULL) {
        printf("error");
        return NULL;
    }

    int max = strlen(copy);
    char* herewith = malloc(max *sizeof(char));

    char* word = strtok(copy, SEPARATORS);

    while (word) {

        for (int i = 0; i < strlen(word); i++) {
            if (isupper(word[i]) <= 0)
                break;
            else {
                strcat(herewith, word);
                break;
            }

        }

        word = strtok(NULL, SEPARATORS);

    }

    free(copy);

    return herewith;
}

/*
Sa se numere cate cuvinte au cel putin un caracter din sirul “api”.
*/

int cout_api(char* str) {
    
    int count = 0;
    char* copy = strdup(str);
    char api[] = "api";

    if (copy == NULL) {
        printf("Error");
        return -1;
    }

    char* word = strtok(copy, SEPARATORS);
   
    while (word) {
       
        for (int j = 0; j < strlen(api); j++) {
            if (strchr(word, api[j])) {
                count++;
                break;
            }
        }
        
        word = strtok(NULL, SEPARATORS);
    }

    free(copy);

    return count;
}

int main(void)
{
    char sentence[] = "Ana are mere, pere si gutui. Gigel nu are nimic.";

    printf("%d\n", count_lowercases_words(sentence));

    printf("%d\n", cout_api(sentence));

    printf("%s\n", enclosed(sentence));

    return 0;
}
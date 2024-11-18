#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <time.h>
#include "mystring.h"

#define PROMPT "> "
#define DELIM " \t"

char* process(char*);

int main(void){
    char* input = readline(PROMPT);
    while(input != NULL){
        printf("input  - \"%s\"\n", input);
        clock_t start = clock();
        char* output = process(input);
        clock_t end = clock();
        long double time = (long double)(end - start) / CLOCKS_PER_SEC;
        printf("output - \"%s\"\n", output);
        printf("time   - %.6Lf\n", time);
        free(input);
        free(output);
        input = readline(PROMPT);
        if (input == NULL)
            printf("Exiting from programm\n");
    }
    return 0;
}
 
char* process(char* input){
    char* input_copy = mystrdup(input);
    int l = mystrlen(input);
    char* modified;
    modified = calloc((10 * l), sizeof(char));     
    char* word = mystrtok(input_copy, DELIM);
    int n = 0;
    while (word != NULL){
        int wlen = mystrlen(word);
        if (wlen > 0){
            mystrncpy(modified + n, word, wlen * sizeof(char));
            n += wlen;
            modified[n] = ' ';
            n++;
            if (wlen <= 9){
                modified[n] = (char)(wlen + 48);
                n++;
            }
            if (wlen >= 10 && wlen <= 99){
                int dec = wlen / 10;
                modified[n] = (char)(dec + 48);
                n++;
                int ed = wlen % 10;
                modified[n] = (char)(ed + 48);
                n++;
            }
            if (wlen >= 100){
                int sot = wlen / 100;
                modified[n] = (char)(sot + 48); 
                n++;
                int dec = (wlen / 10) % 10;
                modified[n] = (char)(dec + 48);
                n++;
                int ed = wlen  % 10;
                modified[n] = (char)(ed + 48);
                n++;
            }
            modified[n] = ' ';
            n++;
        }
        word = mystrtok(NULL, DELIM);
    }
    free(input_copy);
    if (n > 0)
        n--;
    modified[n] = '\0';
    modified = realloc(modified, (n + 1) * sizeof(char));
    return modified;
}
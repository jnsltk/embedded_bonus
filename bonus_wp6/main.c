#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 200
#define WORD_N 5

int main(void) {
    char *str;
    char *buffer = malloc(sizeof(char) * WORD_SIZE * WORD_N);

    str = fgets(buffer, WORD_SIZE * WORD_N, stdin);
    if (str == NULL) {
        free(buffer);
        printf("Error: fgets failed\n");
        return 1;
    }

    char *delim = " ";
    char *token;
    char **words = malloc(sizeof(char *) * WORD_N);
    
    token = strtok(str, delim);

    int i = 0;
    while (token) {
        words[i] = token;
        token = strtok(NULL, delim);
        if (++i > WORD_N) {
            printf("Error: too many words\n");
            free(buffer);
            free(words);
            return 1;
        }
    }

    for (i = 0; i < WORD_N; i++) {
        printf("%s\n", words[i]);
    }
    
    free(words);
    free(buffer);
    return 0;
}

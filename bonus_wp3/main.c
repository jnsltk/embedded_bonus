#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_matrix(int ***matrix, int *rows, int *cols);
int get_size(int *rows, int *cols);
int *get_int_input(int size);

int main(int argc, char **argv) {
    int rows;
    int cols;

    int *m_size = get_int_input(2);

    if (m_size == NULL) {
        return 2;
    }

    rows = m_size[0];
    cols = m_size[1];

    free(m_size);

    int *a = get_int_input(cols);

    if (a == NULL) {
        return 2;
    }

    for (char i = 0; i < cols; i++) {
        printf("%d ", a[i]);
    }

    free(a);
    return 0;

    int **matrix1 = (int **) malloc(sizeof(int *) * cols);
    for (char i = 0; i < 4; i++) {
        matrix1[i] = (int *) malloc(sizeof(int *) * rows);
    }

    int **matrix2 = (int **) malloc(sizeof(int *) * cols);
    for (char i = 0; i < 4; i++) {
        matrix2[i] = (int *) malloc(sizeof(int *) * rows);
    }

    // int result[array_y][array_x];
    // for (char i = 0; i < array_y; i++) {
    //     for (char j = 0; j < array_x; j++) {
    //         result[i][j] = matrix1[i][j] + matrix2[i][j];
    //     }
    // }

    // for (char i = 0; i < array_y; i++) {
    //     for (char j = 0; j < array_x; j++) {
    //         printf("%d ", result[i][j]);
    //     }
    //     putchar('\n');
    // }
}

void input_matrix(int ***matrix, int *rows, int *cols) {}

int *get_int_input(int size) {
    char a[100], *result;
    int *b = malloc(sizeof(int) * size);

    if ((result = fgets(a, sizeof(a), stdin)) == NULL)
        printf("Invalid input!\n");

    char *p = strtok(a, " ");

    char i = 0;
    while (p != NULL) {
        char *end;
        b[i++] = strtol(p, &end, 10);
        if (p == end) {
            printf("Invalid input\n");
            return NULL;
        }
        if (i > size) {
            printf("Wrong number of digits! Please enter exactly %d!\n", size);
            return NULL;
        }
        p = strtok(NULL, " ");
    }
    if (i < size) {
        printf("Wrong number of digits! Please enter exactly %d!\n", size);
        return NULL;
    }

    return b;
}

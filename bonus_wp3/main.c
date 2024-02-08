#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *get_int_input(int size);
int ***init_matrix(int rows, int cols, int *a);
int ***add_matrices(int ***matrix1, int ***matrix2, int rows, int cols, int *a);
void print_matrix(int ***matrix, int rows, int cols);
void free_matrix(int ***matrix, int rows);

int main(int argc, char **argv) {
    int rows;
    int cols;

    printf("Input the size: ");
    int *m_size = get_int_input(2);

    if (m_size == NULL) {
        return 0;
    }

    rows = m_size[0];
    cols = m_size[1];

    free(m_size);

    if (rows == 1 && cols == 1) {
        printf("Invalid matrix!");
        return 0;
    }

    printf("Input elements of matrix 1: ");
    int *a = get_int_input(cols * rows);

    if (a == NULL) {
        return 0;
    }

    printf("Input elements of matrix 2: ");
    int *b = get_int_input(cols * rows);

    if (b == NULL) {
        return 0;
    }

    int ***matrix1 = init_matrix(rows, cols, a);
    int ***matrix2 = init_matrix(rows, cols, b);

    int *c = malloc(sizeof(int) * rows * cols);

    int ***res_matrix = add_matrices(matrix1, matrix2, rows, cols, c);

    printf("\nThe sum is: \n");
    print_matrix(res_matrix, rows, cols);

    free_matrix(matrix1, rows);
    free_matrix(matrix2, rows);
    free_matrix(res_matrix, rows);

    free(a);
    free(b);
    free(c);
    return 0;
}

int *get_int_input(int size) {
    char a[100], *result;
    int *b = malloc(sizeof(int) * size);

    if ((result = fgets(a, sizeof(a), stdin)) == NULL)
        printf("Invalid input!\n");

    char *s = " \n";

    char *p = strtok(a, s);

    char i = 0;
    while (p != NULL) {
        char *end;
        b[i++] = strtol(p, &end, 10);
        if (p == end) {
            printf("Invalid input\n");
            return NULL;
        }
        if (i > size + 1) {
            printf("Invalid input! Please enter exactly %d digits!\n", size);
            return NULL;
        }
        p = strtok(NULL, s);
    }
    if (i < size) {
        printf("Invalid input! Please enter exactly %d digits!\n", size);
        return NULL;
    }

    return b;
}

int ***init_matrix(int rows, int cols, int *a) {
    int ***matrix = malloc(sizeof(int **) * rows);
    for (char i = 0; i < rows; i++)
        matrix[i] = malloc(sizeof(int **) * cols);

    char k = 0;
    for (char i = 0; i < rows; i++) {
        for (char j = 0; j < cols; j++) {
            matrix[i][j] = &a[k];
            k++;
        }
    }
    return matrix;
}

int ***add_matrices(int ***matrix1, int ***matrix2, int rows, int cols, int *a) {
    int ***res_matrix = malloc(sizeof(int **) * rows);
    for (char i = 0; i < rows; i++)
        res_matrix[i] = malloc(sizeof(int **) * cols);

    char k = 0;
    for (char i = 0; i < rows; i++) {
        for (char j = 0; j < cols; j++) {
            a[k] = *matrix1[i][j] + *matrix2[i][j];
            res_matrix[i][j] = &a[k];
            k++;
        }
    }
    return res_matrix;
}

void print_matrix(int ***matrix, int rows, int cols) {
    for (char i = 0; i < rows; i++) {
        for (char j = 0; j < cols; j++) {
            printf("%d ", *matrix[i][j]);
        }
        putchar('\n');
    }
}

void free_matrix(int ***matrix, int rows) {
    for (char i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

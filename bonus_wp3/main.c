#include <stdio.h>
int matrix1[4][4] = {{1, 2}, {4, 5}};
int matrix2[4][4] = {{9, 8}, {6, 5}};

unsigned char array_x = 2;
unsigned char array_y = 2;

void get_input(unsigned char matrix_size, int matrix[4][4]);

int main(int argc, char **argv) {
    char c;
    char i = 0;
    int n = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            printf("%d ", n);
            n = 0;
            i++;
            continue;
        } else if (c == '\n') {
            printf("%d\n", n);
            i++;
            break;
        } else if (n != 0) {
            n *= 10;
        }
        n += c - 48;
    }
    printf("%d\n", i);
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

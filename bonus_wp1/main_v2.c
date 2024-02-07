#include <stdio.h>
#include <stdlib.h>

void print_binary (unsigned int n)
{
    if (n >> 1) {
        print_binary(n >> 1);
    }
    putchar('0' + (n & 1));
}

int main (int argc, char **argv) 
{
    signed int n = atoi(argv[1]);
    printf("0b");
    print_binary(n);
    putchar('\n');
    return 0;
}

#include <stdio.h> // include stdio.h library
#include <stdlib.h> // include stdlib.h library
#include <string.h> // include string.h library

// ------------------ Function Prototypes ------------------

// Function to calculate the factorial of a number
int factorial(int n);
// Function to swap two characters
void swap(char *c1, char *c2);
// Function to permutate a string
void permutate(char *str, int s, int e, char **perm_array, int *i);

// ------------------ Main Function ------------------
int main(int argc, char **argv) {
    if (argc < 2) { // if the number of arguments is less than 2
        printf("Usage: %s <string>\n", argv[0]); // print the usage of the program
        return 1; // return 1 to indicate an error
    }

    char *str = argv[1]; // get the string from the command line arguments
    int str_len = strlen(str); // get the length of the string
    int perm_count = factorial(str_len); // calculate the number of permutations

    char **perm_array = malloc(perm_count * sizeof(char *)); // allocate memory for the permutations

    int i = 0; // initialize the index to 0
    permutate(str, 0, str_len - 1, perm_array, &i); // permutate the string

    for (int i = 0; i < perm_count; i++) { // loop through the array of permutations
        printf("%d: %s\n", i + 1, perm_array[i]); // print the permutation
    }

    for (int i = 0; i < perm_count; i++) { // loop through the array of permutations
        free(perm_array[i]); // free the memory of each permutation
    }
    free(perm_array); // free the memory of the array of permutations

    return 0; // return 0 to indicate success
}

// ------------------ Function Definitions ------------------

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) { // if n is 0
        return 1; // return 1
    }
    return n * factorial(n - 1); // return n times the factorial of n - 1
}

// Function to swap two characters
void swap(char *c1, char *c2) {
    char temp = *c1; // create a temporary variable to store the value of c1
    *c1 = *c2; // set the value of c1 to the value of c2
    *c2 = temp; // set the value of c2 to the value of the temporary variable
}

// Function to permutate a string
void permutate(char *str, int s, int e, char **perm_array, int *i) {
    // Base case
    if (s == e) { // if s is equal to e
        str[e + 1] = '\0'; // set the character at index e + 1 to the null character
        perm_array[*i] = strdup(str); // copy the string to the array of permutations
        *i += 1; // increment the index
        return; // return
    }

    int j; // declare a variable j to store the index
    for (j = s; j <= e; j++) { // loop through the string from s to e
        swap(str + s, str + j); // swap the characters at index s and j
        permutate(str, s + 1, e, perm_array, i); // permutate the string from s + 1 to e
        swap(str + s, str + j); // swap the characters at index s and j
    };
}

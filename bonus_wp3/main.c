// Include the standard input/output library
#include <stdio.h>
// Include the standard library
#include <stdlib.h>
// Include the string library
#include <string.h>

// --- Function Declarations ---

// Function to get the input from the user
int *get_int_input(int size);
// Function to initialize the matrix
int ***init_matrix(int rows, int cols, int *a);
// Function to add the matrices together
int ***add_matrices(int ***matrix1, int ***matrix2, int rows, int cols, int *a);
// Function to print the matrix
void print_matrix(int ***matrix, int rows, int cols);
// Function to free the memory allocated for the matrix
void free_matrix(int ***matrix, int rows);

// --- Main Function ---
int main(int argc, char **argv) {
    // Declare number of rows
    int rows;
    // Declare number of columns
    int cols;

    printf("Input the size: ");
    // Get the size of the matrix from the user
    int *m_size = get_int_input(2);

    // If the size is NULL, return 0, since the input is invalid
    if (m_size == NULL) {
        // Return 0 to stop the program
        return 0;
    }

    // Set rows to the first number from the input
    rows = m_size[0];
    // Set cols to the second number from the input
    cols = m_size[1];

    // Free the memory allocated for the array containing size of the matrix
    free(m_size);

    // If the rows and cols are less than 1, return 0, since the matrix is invalid
    if (rows == 1 && cols == 1) {
        printf("Invalid matrix!");
        // Return 0 to stop the program
        return 0;
    }

    printf("Input elements of matrix 1: ");
    // Get the input for the elements of the first matrix
    int *a = get_int_input(cols * rows);

    // If the input is NULL, return 0, since the input is invalid
    if (a == NULL) {
        // Return 0 to stop the program
        return 0;
    }

    printf("Input elements of matrix 2: ");
    // Get the input for the elements of the second matrix
    int *b = get_int_input(cols * rows);

    // If the input is NULL, return 0, since the input is invalid
    if (b == NULL) {
        // Return 0 to stop the program
        return 0;
    }

    // Initialize matrix1 with the elements from the first input
    int ***matrix1 = init_matrix(rows, cols, a);
    // Initialize matrix2 with the elements from the second input
    int ***matrix2 = init_matrix(rows, cols, b);

    // Allocate memory for the elements in the result matrix
    int *c = malloc(sizeof(int) * rows * cols);

    // Add the matrices together
    int ***res_matrix = add_matrices(matrix1, matrix2, rows, cols, c);

    printf("\nThe sum is: \n");
    // Print the result matrix
    print_matrix(res_matrix, rows, cols);

    // Free the memory allocated for matrix1
    free_matrix(matrix1, rows);
    // Free the memory allocated for matrix2
    free_matrix(matrix2, rows);
    // Free the memory allocated for the result matrix
    free_matrix(res_matrix, rows);

    free(a); // Free the memory allocated for the first input
    free(b); // Free the memory allocated for the second input
    free(c); // Free the memory allocated for the result matrix
    return 0; // Return 0 to stop the program
}

// --- Function Definitions ---

// Function to get the input from the user
int *get_int_input(int size) {
    // Declare an array to store the input, and a pointer to store the result
    // (Making the assumption that the input will not be longer than 100 characters)
    char a[100], *result;
    // Allocate memory for the array to store the input converted to integers
    int *b = malloc(sizeof(int) * size);

    // Get the input from the user and store it in the array, if the input is invalid, print an error message
    if ((result = fgets(a, sizeof(a), stdin)) == NULL)
        printf("Invalid input!\n");

    // Declare a string to store the delimiters
    char *s = " \n";

    // Split the input into tokens
    char *p = strtok(a, s);

    // Declare a counter to keep track of the number of elements
    char i = 0;
    // While there are tokens left
    while (p != NULL) {
        // Declare a pointer to store the end of the string
        char *end;
        // Convert the token to an integer and store it in the array of integers
        b[i++] = strtol(p, &end, 10);
        // If the pointer is equal to the end of the string, the input is invalid
        if (p == end) {
            printf("Invalid input\n");
            // Return NULL to indicate that the input is invalid
            return NULL;
        }
        // If the counter is greater than the size, the input is invalid
        if (i > size + 1) {
            printf("Invalid input! Please enter exactly %d digits!\n", size);
            // Return NULL to indicate that the input is invalid
            return NULL;
        }
        // Get the next token
        p = strtok(NULL, s);
    }
    // If the counter is less than the size, the input is invalid
    if (i < size) {
        printf("Invalid input! Please enter exactly %d digits!\n", size);
        // Return NULL to indicate that the input is invalid
        return NULL;
    }

    // Return the array of integers
    return b;
}

// Function to initialize the matrix with the input from the user
int ***init_matrix(int rows, int cols, int *a) {
    // Allocate memory for the matrix
    int ***matrix = malloc(sizeof(int **) * rows);
    for (char i = 0; i < rows; i++) // Loop through the rows...
        // ...and allocate memory for the columns
        matrix[i] = malloc(sizeof(int **) * cols);

    // Declare a counter to keep track of the position in the input array
    char k = 0;
    // Loop through the rows
    for (char i = 0; i < rows; i++) {
        // Loop through the columns
        for (char j = 0; j < cols; j++) {
            // Set the element in the matrix to the corresponding element in the input array
            matrix[i][j] = &a[k];
            // Increment the counter
            k++;
        }
    }
    // Return the matrix
    return matrix;
}

// Function to add the matrices together
int ***add_matrices(int ***matrix1, int ***matrix2, int rows, int cols, int *a) {
    // Allocate memory for the result matrix
    int ***res_matrix = malloc(sizeof(int **) * rows);
    for (char i = 0; i < rows; i++) // Loop through the rows...
        // ...and allocate memory for the columns
        res_matrix[i] = malloc(sizeof(int **) * cols);

    // Declare a counter to keep track of the position in the array
    char k = 0;
    // Loop through the rows
    for (char i = 0; i < rows; i++) {
        // Loop through the columns
        for (char j = 0; j < cols; j++) {
            // Set the element in the array of results to the sum of the corresponding elements in the input matrices
            a[k] = *matrix1[i][j] + *matrix2[i][j];
            // Set the element in the result matrix to the corresponding element in the array
            res_matrix[i][j] = &a[k];
            // Increment the counter
            k++;
        }
    }
    // Return the result matrix
    return res_matrix;
}

// Function to print the matrix
void print_matrix(int ***matrix, int rows, int cols) {
    // Loop through the rows
    for (char i = 0; i < rows; i++) {
        // Loop through the columns
        for (char j = 0; j < cols; j++) {
            printf("%d ", *matrix[i][j]);
        }
        putchar('\n');
    }
}

// Function to free the memory allocated for the matrix
void free_matrix(int ***matrix, int rows) {
    // Loop through the rows
    for (char i = 0; i < rows; i++)
        // Free the memory allocated for the columns
        free(matrix[i]);
    // Free the memory allocated for the rows
    free(matrix);
}

// Include the standard input/output library for using putchar and printf
#include <stdio.h>
// Include the C standard library for using atoi to convert the argument string to int
#include <stdlib.h>
#include <math.h>

// Main function of the program
int main (int argc, char** argv) {
    // Check if there's an argument provided
    if (argc == 1) {
        printf("Error: No number provided. Please provide a number as a command line argument.\n");
        // Exit program without error code
        return 0;
    }

    // Parse integer from argument passed in
    unsigned int n = atoi(argv[1]);
    // Check if argument provided is a number (atoi returns 0 if NaN)
    if (n == 0) {
        printf("Error: Invalid number.\n");
        // Exit program without error code
        return 0;
    }
    // Calculate the number of bits in the provided number, and shift 1 left by
    // that amount, so that it serves as a mask for checking bits from left to right.
    unsigned int max = 1 << ((int) log2(n) + 1);

    // Declare variable to keep track of 1's
    int ones = 0;
    // Declare variable to keep track of 0's
    int zeros = 0;

    printf("Number: %d\nBinary: 0b", n);
 
    // Run loop while max is not zero (while constantly shifting it right by one bit)
    while (max != 0) {
        // Check if the value of the bit at the current location is one of zero
        if (n & max) {
            // If value is one, output 1 to console
            putchar('1');
            // Increment number of 1's
            ones++;

        // Otherwise value has to be zero
        } else {
            // Check if current zero is leading zero or not
            if (ones != 0) {
                // If not leading zero, output 0 to console
                putchar('0');
                // Increment number of 0's
                zeros++;
            }
        }
        // Shift max right by one bit, so next loop will check the next bit. If shifted all the way, max will equal 0, so loop will stop
        max >>= 1;
    }

    printf("\nNumber of 0s: %d\n", zeros);
    printf("Number of 1s: %d\n", ones);

    // Return zero to show successful execution
    return 0;
}

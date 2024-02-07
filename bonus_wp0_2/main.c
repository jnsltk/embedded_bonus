// Include standard input output header
#include <stdio.h>

// Include string.h header
#include <string.h>

// Main function in the program
int main(int argc, char *argv[]) {
    // Check if an argument is provided
    if (argc == 1) 
    {
        printf("No command line argument provided, please provide a name.\n");
        // Return 0 to show successful execution 
        return 0;
    } 

    // Get the length of the name that is provided as an argument
    const int nameLen = strlen(argv[1]);

    // Check if name is under 3 characters
    if (nameLen < 3) 
    {
        printf("Name too short, min 3 characters\n");
    }
    // Check if name is over 50 characters
    else if (nameLen > 50) 
    {
        printf("Name too long, max 50 characters\n");
    }
    // If the name is within the min-max limit, greet user
    else
    {
        printf("Hello %s, how is your day today?\n", argv[1]);
    }
    // Return 0 to show successful execution 
    return 0;
}

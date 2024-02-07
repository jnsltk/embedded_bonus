// include standard input and output header for taking input
#include <stdio.h>
// include standard library for malloc, etc.
#include <stdlib.h>
// include string.h for memset, etc.
#include <string.h>
// include time.h for delay implementation
#include <time.h>

// define enum type weeks
typedef enum { Week1, Week2, Week3, Week4, Week5 } weeks;
// define enum type days
typedef enum { Mon, Tue, Wed, Thu, Fri, Sat, Sun } days;

// ===================== Function declarations ========================

// declare get_num function to take user input
int get_num();
// declare print_date to print the week and the day of the week
void print_date(weeks *week, days *day);
// declare delay, to wait between prints
void delay(unsigned int s);

// main function of the program
int main(void) {
    // declare index i for weeks
    weeks i;
    // declare index j for days
    days j;

    // get input on week number and assign it to index i
    i = get_num();
    // decrement i by one, since the enum is zero based
    i = i - 1;
    // check for the validity of the input
    if (i < 0 || i > 4) {
        puts("invalid week");
        // stop execution if invalid
        return 0;
    }
    // get input on week number and assign it to index j
    j = get_num();
    // decrement j by one, since the enum is zero based
    j = j - 1;
    // check for the validity of the input
    if (j < 0 || j > 6) {
        puts("invalid day");
        // stop execution if invalid
        return 0;
    }
    // run outer while loop for weeks, until i is equal to week 5 (from week 1 to week 5)
    while (i <= Week5) {
        // run inner while loop for days, until j is equal to sunday (from monday to sunday)
        while (j <= Sun) {
            // delay execution by 1 second as per assignment description
            delay(1);
            // call print date function to print the week and the day
            print_date(&i, &j);
            // increment j by one, i.e. move on to next day
            j++;
        }
        // after the whole week has been printed, set j back to 0, i.e. Monday
        j = 0;
        // incerement i by one, i.e. move on to next week
        i++;
    }
    // upon successful execution return 0
    return 0;
}

// function to take input from user
int get_num() {
    // declare n, the value that will be returned
    int n;
    // declare and allocate memory to an input buffer for the fgets function.
    // the size of the memory needed is the size of the type char times the maximum expected
    // characters (with some wiggle room)
    char *input_buff = malloc(sizeof(char) * 4);
    // set the newly assigned memory to zero -- INITIALIZE MEMORY
    memset(input_buff, 0, 8);

    // declare string where input will be stored and assign it to NULL
    char *input = NULL;
    // run a loop while input is empty
    while (input == NULL) {
        // read input from stdin into the buffer, if the reading was successful the returned value
        // from fgets which is the input string is assigned to input
        input = fgets(input_buff, 4, stdin);

        // defines pointer which will point to where the string stopped parsing
        char *p_end = NULL;
        // get long from input string and assign (and cast) it to n
        n = strtol(input, &p_end, 10);
        // if p_end still points to input, something went wrong, so continue loop
        if (input == p_end) {
            // ensure loop condition not met
            input = NULL;
        }
    }
    // free assigned memory
    free(input_buff);
    // return the parsed integer
    return n;
}

// Print the week number and the day of the week
void print_date(weeks *week, days *day) {
    // declare the name of the week
    char *week_name;

    // check which week it is
    switch (*week) {
    // if it is week 1
    case Week1:
        // assign the week to string
        week_name = "Week 1";
        // break out of switch statement
        break;
    // if it is week 2
    case Week2:
        // assign the week to string
        week_name = "Week 2";
        break;
    // if it is week 3
    case Week3:
        // assign the week to string
        week_name = "Week 3";
        // break out of switch statement
        break;
    // if it is week 4
    case Week4:
        // assign the week to string
        week_name = "Week 4";
        // break out of switch statement
        break;
    // if it is week 5
    case Week5:
        // assign the week to string
        week_name = "Week 5";
        // break out of switch statement
        break;
    }

    // declare the name of the week
    char *day_name;

    // check the day of the week
    switch (*day) {
    // if it is week Monday
    case Mon:
        // assign the day to string
        day_name = "Monday";
        // break out of switch statement
        break;
    // if it is week Tuesday
    case Tue:
        // assign the day to string
        day_name = "Tuesday";
        // break out of switch statement
        break;
    // if it is week Wednesday
    case Wed:
        // assign the day to string
        day_name = "Wednesday";
        // break out of switch statement
        break;
    // if it is week Thursday
    case Thu:
        // assign the day to string
        day_name = "Thursday";
        // break out of switch statement
        break;
    // if it is week Friday
    case Fri:
        // assign the day to string
        day_name = "Friday";
        // break out of switch statement
        break;
    // if it is week Saturday
    case Sat:
        // assign the day to string
        day_name = "Saturday";
        // break out of switch statement
        break;
    // if it is week Sunday
    case Sun:
        // assign the day to string
        day_name = "Sunday";
        // break out of switch statement
        break;
    }

    printf("%s, %s\n", week_name, day_name);
}

// implement delay function that delays execution by the amount of seconds passed in as int
void delay(unsigned int s) {
    // take the current system time
    unsigned int start = time(0);
    // loop until the current time doesn't match the start time plus the desired delay
    while (time(0) < start + s)
        ;
}

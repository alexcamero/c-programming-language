#include <stdio.h>

/* 
5-6 Rewrite appropriate programs from earlier chapters with pointers instead of array indexing. Good possibilities include (the ones I'll do) getline, atoi, itoa, reverse, strindex, and getop.

atoi(a, i) takes a character array a and writes the integer the string represents to i, function returns 0 if the string doesn't represent an integer, 1 if it does
*/

#define MAXLINE 1000

int my_atoi(char *a, int *i);

int main() {
    int i;
    if (my_atoi("87", &i)) {
        printf("expected: 87; actual: %d\n", i);
    } else {
        printf("unexpected result for '87'");
    }
    if (my_atoi("-87", &i)) {
        printf("expected: -87; actual: %d\n", i);
    } else {
        printf("unexpected result for '-87'");
    }
    if (my_atoi("00987", &i)) {
        printf("expected: 987; actual: %d\n", i);
    } else {
        printf("unexpected result for '987'");
    }
    if (my_atoi("-00987", &i)) {
        printf("expected: -987; actual: %d\n", i);
    } else {
        printf("unexpected result for '-00987'");
    }
    if (my_atoi("           -00987", &i)) {
        printf("expected: -987; actual: %d\n", i);
    } else {
        printf("unexpected result for '           -00987'");
    }
    if (my_atoi("\n\t   9876543", &i)) {
        printf("expected: 9876543; actual: %d\n", i);
    } else {
        printf("unexpected result for '\\n\\t   9876543'");
    }
    if (my_atoi("-87A", &i)) {
        printf("unexpected result for '-87A'");
    } else {
        printf("expected: 9876543; actual: %d\n", i);
    }
    if (my_atoi("    tr5", &i)) {
        printf("unexpected result for '    tr5'");
    } else {
        printf("expected: 9876543; actual: %d\n", i);
    }
    return 0;
}

int my_atoi(char *a, int *i) {
    // skip leading whitespace
    while (*a == ' ' || *a == '\r' || *a == '\t' || *a == '\n') {
        a++;
    }
    // check if negative
    int negative = 0;
    if (*a == '-') {
        negative = 1;
        a++;
    }
    // build the integer
    int n = 0;
    while (*a != '\0') {
        if (*a <= '9' && *a >= '0') {
            n = (10 * n) + *a - '0';
            a++;
        } else {
            // exit with 0 without changing i if encounters unexpected character
            return 0;
        }
    }
    // adjust if negative
    if (negative) {
        n *= -1;
    }
    // store in i and exit with 1
    *i = n;
    return 1;
}
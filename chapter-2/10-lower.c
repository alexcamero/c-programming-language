#include <stdio.h>

/* Problem 2-10 Using a conditional expression rewrite the function lower that converts a character to lowercase if it is an uppercase letter or leaves it unchanged if not. */

char lower(char c);

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        putchar(lower(c));
    }
    return 0;
}

char lower(char c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
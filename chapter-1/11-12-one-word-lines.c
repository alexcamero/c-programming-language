#include <stdio.h>

/* Problem 1-11 asks about how to test the word count program. 
I would submit texts with many tabs and lines and also some without.
I would submit textx with many consecutive tabs/new lines.
I would submit texts where I could count the words to verify. */

/* Problem 1-12 wants a program that prints the input one word per line. */

int main() {
    #define IN 1
    #define OUT 0

    int state, c;
    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        } else {
            putchar(c);
            state = IN;
        }
    }
}
#include <stdio.h>

int main() {
    /* Problem 1-8 wants a program that counts blanks, tabs, and newlines in input text */

    long b, t, nl;
    int c;
    b = 0;
    t = 0;
    nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            b++;
        }
        if (c == '\t') {
            t++;
        }
        if (c == '\n') {
            nl++;
        }
    }

    printf("There were %ld blanks, %ld tabs, and %ld new lines.\n", b, t, nl);
}
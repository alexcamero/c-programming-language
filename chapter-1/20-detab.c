#include <stdio.h>

/* Problem 1-20 replace tabs with fixed number N of spaces */

#define N 4

int main() {

    int i;
    char c;

    while((c = getchar()) != EOF) {
        if (c == '\t') {
            for (i=0; i<N; i++) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }

    putchar('\n');

    return 0;
}
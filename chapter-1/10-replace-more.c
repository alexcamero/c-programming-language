#include <stdio.h>

/* Problem 1-10: replace tabs with \t, backspaces with \b, and backslash with \\. 
This and some before are a little wonky since technically the book has 
not gotten to 'else' just yet so I'm avoiding using it. Same with or/and.  */

int main() {
    int c, x;
    x = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
            x = 1;
        }
        if (c == '\b') {
            putchar('\\');
            putchar('b');
            x = 1;
        }
        if (c == '\\') {
            putchar('\\');
            putchar('\\');
            x = 1;
        }
        if (x != 1) {
            putchar(c);
        }
        x = 0;
    }
}
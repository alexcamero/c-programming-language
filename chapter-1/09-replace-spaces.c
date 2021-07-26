#include <stdio.h>

/* Problem 1-9 asks to return text with multiple consecutive white spaces replaced with a single space. */

int main() {
    int c, white;
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            if (white == 1) {
                putchar(' ');
                white = 0;
            }
            putchar(c);
        }
        if (c == ' ') {
            white = 1;
        }
    }
}
#include <stdio.h>

#define CUTOFF 80


int main() {

    int length;
    char line[CUTOFF + 1], c;
    length = 0;

    while ((c = getchar()) != EOF) {
        if (length < CUTOFF) {
            line[length] = c;
            length ++;
        } else if (length == CUTOFF) {
            line[CUTOFF] = '\0';
            length++;
            printf("%s", line);
            putchar(c);
        } else if (length > CUTOFF) {
            putchar(c);
        }
        if (c == '\n') {
            length = 0;
        }
    }

    return 0;
}
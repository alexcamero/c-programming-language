#include <stdio.h>

/* Problem 1-21 replace string of blanks by number of tabs and blanks to acheive same result */

#define N 4 /* assume N blanks equals 1 tab */

#define SPACES 1 /* denote whether in spaces run or not */
#define NOT 0

int main() {

    char c;
    int i, j, state;

    i = 0;
    state = NOT;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && state == NOT) {
            putchar(c);
        } else if (c == ' ') {
            i++;
            state = SPACES;
        } else {
            for (j = 0; j < i/N; j++) {
                putchar('\t');
            }
            for (j = 0; j < i - (i/N); j++) {
                putchar(' ');
            }
            putchar(c);
            state = NOT;
            i = 0;
        }
    }

    putchar('\n');

    return 0;
}
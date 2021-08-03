#include <stdio.h>

/* Problem 2-2 rewrite the loop -- for( i=0; i<lim-1 && (c = getchar()) != '\n' && c != EOF; i++) {s[i] = c;} --  without ||s or &&s */

#define LIM 40

int main() {
    int lim = LIM;
    int ok = 1;
    char c, s[100];

    int i = 0;

    while (ok) {
        if (i < lim - 1) {
            if ((c = getchar()) != '\n') {
                if (c != EOF) {
                    s[i] = c;
                    i++;
                } else {
                    ok = 0;
                }
            } else {
                ok = 0;
            }
        } else {
            ok = 0;
        }
    }

    return 0;
}
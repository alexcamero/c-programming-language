#include <stdio.h>
#include <ctype.h>

/* 
4-11 Rewrite getop (from the book's version of Reverse Polish Calculator) to not use ungetch by using static variable.
*/

#define MAXLINE 100
#define NUMBER '0'

int getop(char s[]);

int main() {
    return 0;
}

int getop(char s[]) {
    int i, c;
    static char buf[MAXLINE];
    static int bufp = 0;
    while ((s[0] = c = (bufp > 0) ? buf[--bufp] : getchar()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;
    }
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = (bufp > 0) ? buf[--bufp] : getchar()));
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = (bufp > 0) ? buf[--bufp] : getchar()));
    }
    s[i] = '\0';
    if (c != EOF) {
        if (bufp >= MAXLINE) {
            printf("ungetch: too many characters\n");
        } else {
            buf[bufp++] = c;
        }
    }
    return NUMBER;
}
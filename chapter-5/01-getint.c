#include <stdio.h>
#include <ctype.h>

/* 
5-1 Fix getint (from book) to not treat '+' or '-' not followed by a digit as a valid rep of 0. Push such a character back on the input.
*/

#define MAXLINE 100

int getch(void);
void ungetch(int);
int getint(int *pn);

char buf[MAXLINE];
int bufp = 0; 

int main() {
    int response, answer;
    response = getint(&answer);
    if (response) {
        printf("%d\n", answer);
    } else {
        printf("Sorry, not a number.\n");
    }
    return 0;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= MAXLINE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int getint(int *pn) {
    int c, sign;
    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}
#include <stdio.h>

/* 
4-7 Write ungets that pushes an entire string back to the input.
*/

#define MAXLINE 100

int getch(void);
void ungetch(int);
void ungets(char s[]);

char buf[MAXLINE];
int bufp = 0; 

int main() {
    int i;
    char c, line[MAXLINE];
    for (i = 0; i < MAXLINE; i++) {
        line[i] = '\0';
    }
    i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
        if (i == MAXLINE) {
            printf("too long\n");
            return 0;
        }
    }
    ungets(line);
    i = 0;
    while ((c = line[i++]) != '\0') {
        putchar(c);
    }
    putchar('\n');
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

void ungets(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        ungetch(s[i++]);
    }
}
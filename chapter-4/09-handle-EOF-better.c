#include <stdio.h>

/* 
4-9 Change getch and ungetch to handle a pushed-back EOF correctly.

    Honestly, I'm not exactly sure what they're looking for here since if these functions are both blind to EOF's special character status, then there's nothing to change. So it seems like it depends on the context in which they're used and not that the functions are incorrect per se. So I assume that the issue they're identifying is that ungetch should bump up the counter if EOF is received? But the function in the chapter that is calling these functions appears to handle EOF so I'm not sure.
*/

#define MAXLINE 100

int getch(void);
void ungetch(int);

char buf[MAXLINE];
int bufp = 0; 

int main() {
    return 0;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (c == EOF) {
        return;
    }
    if (bufp >= MAXLINE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
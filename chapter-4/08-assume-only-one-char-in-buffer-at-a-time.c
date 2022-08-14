#include <stdio.h>

/* 
4-8 Modify getch and ungetch if we can assume there is never more than one character of pushback.
*/

int getch(void);
void ungetch(int);

char buf;
int buffer = 0;

int main() {
    return 0;
}

int getch(void) {
    if (buffer) {
        buffer = 0;
        return buf;
    }
    return getchar();
}

void ungetch(int c) {
    buf = c;
    buffer = 1;
}
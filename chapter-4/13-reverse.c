#include <stdio.h>

/* 4-13 Write a recursive version of the function reverse that reverses a string in place */

#define MAXLINE 100

void reverse(char*);

int main() {
    char c, line[MAXLINE];
    int i;
    for (i = 0; i < MAXLINE; i++) {
        line[i] = '\0';
    }
    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            reverse(line);
            printf("%s\n", line);
            for (i = 0; i < MAXLINE; i++) {
                line[i] = '\0';
            }
            i = 0;
        } else {
            line[i++] = c;
        }
    }
    return 0;
}

void reverse(char s[]) {
    if (s[0] == '\0' || s[1] == '\0') {
        return;
    }
    /* break into two halves */
    char lower[MAXLINE], upper[MAXLINE];
    int i = 0, length = 0;
    while (s[i++] != '\0') {
        length++;
        lower[i-1] = s[i-1];
    }
    for (i = length / 2; i < length; i++) {
        upper[i - (length / 2)] = lower[i];
    }
    lower[length / 2] = '\0';
    upper[i - (length / 2)] = '\0';
    /* recursive calls to reverse each half */
    reverse(lower);
    reverse(upper);
    /* s = upper + lower */
    for (i = 0; i < length; i++) {
        s[i] = i < length - (length / 2) ? upper[i] : lower[i - length + (length / 2)];
    }
}
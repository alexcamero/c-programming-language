#include <stdio.h>

/* Problem 1-16 change the provided longest line program so that it returns arbitrarily large
lengths as well as the truncated longest line */

#define MAXLINE 41 /* One more than the maximum line you want to see */

int getTheLine(char line[], int maxline);
void copyIt(char to[], char from[]);

int main() {

    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    while ((len = getTheLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copyIt(longest, line);
        }
    }

    if (max > 0) {
        printf("%s", longest);
        if (max > MAXLINE) {
            printf("\n");
        }
        printf("The longest line has %d characters.\n", max);
    }

    return 0;
}

int getTheLine(char s[], int lim) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < lim - 1) {
            s[i] = c;
        }
    }

    if (i < lim - 1 && c == '\n') {
        s[i] = c;
        i++;
        s[i] = '\0';
    } else if (c == '\n') {
        s[i] = '\0';
        i++;
    } else {
        s[i] = '\0';
    }
    
    return i;
}

void copyIt(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
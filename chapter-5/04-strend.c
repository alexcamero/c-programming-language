#include <stdio.h>

/* 
5-4 Write strend(s, t) that returns 1 if string t appears at the end of string s, 0 otherwise
*/

#define MAXSTRING 1000

int strend(char *s, char *t);
int strlength(char *s);

int main() {
    char s[MAXSTRING] = "this is s";
    int result = strend(s, " s");
    printf("%d\n", result);
    result = strend(s, "nope");
    printf("%d\n", result);
    result = strend(s, "s is s");
    printf("%d\n", result);
    return 0;
}

int strend(char *s, char *t) {
    int start = strlength(s) - strlength(t);
    if (start < 0) {
        return 0;
    }
    for (s += start; *t != '\0' && *s++ == *t++; )
        ;
    if (*s == *t) {
        return 1;
    }
    return 0;
}

int strlength(char *s) {
    char *start = s;
    while (*s++)
        ;
    return s - start - 1;
}
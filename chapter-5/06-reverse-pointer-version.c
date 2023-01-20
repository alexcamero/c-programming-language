#include <stdio.h>

/* 
5-6 Rewrite appropriate programs from earlier chapters with pointers instead of array indexing. Good possibilities include (the ones I'll do) getline, atoi, itoa, reverse, strindex, and getop.

reverse(s) reverses string s in place
*/

#define MAXLINE 1000

void my_reverse(char *s);

int main() {
    char a[MAXLINE];
    char *s = a;
    while ((*s = getchar()) != EOF) {
        if (*s++ == '\n') {
            *(--s) = '\0';
            s = a;
            my_reverse(s);
            printf("%s\n", s);
            *s = '\0';
        }
    }
    return 0;
}

void my_reverse(char *s) {
    char *a = s;
    char temp;
    while (*s != '\0') {
        s++;
    }
    while (a < --s) {
        temp = *s;
        *s = *a;
        *a++ = temp;
    }
}
#include <stdio.h>

/* 
5-6 Rewrite appropriate programs from earlier chapters with pointers instead of array indexing. Good possibilities include (the ones I'll do) getline, atoi, itoa, reverse, strindex, and getop.

strindex(s, t) returns first index of string t in string s, -1 if doesn't appear
*/

#define MAXLINE 1000

int my_strindex(char *s, char *t);

int main() {
    char a[MAXLINE], b[MAXLINE], c;
    char *s = a, *t = b;
    int state = 0;
    printf("s: ");
    while ((c = getchar()) != EOF) {
        switch(state) {
            case 0:
                if (c == '\n') {
                    printf("t: ");
                    state = 1;
                } else {
                    *s++ = c;
                }
                break;
            case 1:
                if (c == '\n') {
                    *s = '\0';
                    *t = '\0';
                    s = a;
                    t = b;
                    printf("index: %d\n", my_strindex(s, t));
                    state = 0;
                    printf("s: ");
                } else {
                    *t++ = c;
                }
                break;
            default:
                printf("ERROR: state %d not recognized\n", state);
                return 0;
        }
    }
    return 0;
}

int my_strindex(char *s, char *t) {
    char *start_s = s, *start_t = t;
    for (char *tracker = start_s; *tracker != '\0'; tracker++) {
        s = tracker;
        t = start_t;
        while (*s != '\0' && *s++ == *t++) {
            if (*t == '\0') {
                return tracker - start_s;
            }
        }
    }
    return -1;
}
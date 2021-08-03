#include <stdio.h>

/* Problem 2-4 squeeze(s1, s2) deletes any character from string s1 that appears in string s2 */

/* Problem 2-5 any(s1, s2) returns the value of the first location of any character in s2 found in s1 */

#define CHECK 0
#define MAIN 1

int is_in(char x, char s[]); /* checks if x is in string s */
void squeeze(char s1[], char s2[]);
int any(char s1[], char s2[]);

/* main just provides a way to interactively test the functions. Enter s2 first, then s1, and you will get the result of squeeze and of any */

int main() {

    char t[100], s[1000], c;
    int i = 0, j = CHECK, a;

    while ((c = getchar()) != EOF) {
        if (c != '\n' && j == CHECK) {
            t[i++] = c;
        } else if (c != '\n') {
            s[i++] = c;
        } else if (j == CHECK) {
            t[i] = '\0';
            i = 0;
            j = MAIN;
        } else if (j == MAIN) {
            s[i] = '\0';
            a = any(s, t);
            squeeze(s, t);
            printf("Index of first character: %d\nSqueezed line: %s\n", a, s);
            i = 0;
            j = CHECK;
        }
    }

    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j = 0;

    for (i = 0; s1[i] != '\0'; i++) {
        if (!is_in(s1[i], s2)) {
            s1[j++] = s1[i];
        }
    }

    s1[j] = '\0';
}

int is_in(char x, char s[]) {
    int i;
    for (i = 0; s[i] != '\0' && s[i] != x; i++) {
        ;
    }
    return s[i] == x;
}

int any(char s1[], char s2[]) {
    int i, index = -1;

    for (i = 0; s1[i] != '\0' && !is_in(s1[i], s2); i++) {
        ;
    }

    if (s1[i] != '\0') {
        index = i;
    }

    return index;
}
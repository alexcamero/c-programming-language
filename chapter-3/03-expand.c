#include <stdio.h>

/* Problem 3-3 write a function expand(s1, s2) that expands shorthand notations in s1 like a-z or a-h or a-z0-9 or a-zA-Z into the corresponding lists in s2 */

#define SIZE 1000 /* max size of strings */

enum states {OUT, START, DASH}; /* track state */
enum typeOfChar {OTHER, LOWER, UPPER, NUM}; /* track type of character */

void expand(char s1[], char s2[]);
int alphanumeric(char c);

int main() {
    int i = 0;
    char c, s1[SIZE], s2[SIZE];
    while ((c = getchar()) != EOF) {
        s1[i++] = c;
    }
    expand(s1,s2);
    printf("\n%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[]) {
    int i, j = 0, state = OUT;
    char buff;

    for (i = 0; s1[i] != '\0'; i++) {
        switch (state) {
            case OUT:
                if (alphanumeric(s1[i])) {
                    buff = s1[i];
                    state = START;     
                } else {
                    s2[j++] = s1[i];
                }
                break;
            case START:
                if (s1[i] == '-') {
                    state = DASH;
                } else {
                    s2[j++] = buff;
                    if (alphanumeric(s1[i])) {
                        buff = s1[i];
                    } else {
                        s2[j++] = s1[i];
                        state = OUT;
                    }
                }
                break;
            case DASH:
                if (alphanumeric(buff) == alphanumeric(s1[i])) {
                    if (s1[i] > buff) {
                        for (; buff < s1[i]; buff++) {
                            s2[j++] = buff;
                        }
                    } else {
                        for (; buff > s1[i]; buff--) {
                            s2[j++] = buff;
                        }
                    }
                    state = START;
                } else {
                    s2[j++] = buff;
                    s2[j++] = '-';
                    if (alphanumeric(s1[i])) {
                        buff = s1[i];
                        state = START;
                    } else {
                        s2[j++] = s1[i];
                        state = OUT;
                    }
                }
                break;
        }
    }

    if (state >= START) {
        s2[j++] = buff;
    }
    if (state == DASH) {
        s2[j++] = '-';
    }

    s2[j] = '\0';
}

int alphanumeric(char c) {
    if (c >= 'a' && c <= 'z') {
        return LOWER;
    }
    if (c >= 'A' && c <= 'Z') {
        return UPPER;
    }
    if (c >= '0' && c <= '9') {
        return NUM;
    }
    return OTHER;
}
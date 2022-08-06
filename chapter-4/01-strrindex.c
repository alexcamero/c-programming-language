#include <stdio.h>

/* write function strrindex(s, t) that returns the rightmost position of string t in string s or -1 if not found */

#define MAXLENGTH 100

int strrindex(char s[], char t[]);

int main() {
    char c, needle[MAXLENGTH], haystack[MAXLENGTH];
    int i = 0;
    for (i = 0; i < MAXLENGTH; i++) {
        needle[i] = '\0';
        haystack[i] = '\0';
    }
    i = 0;
    while ((c = getchar()) != '\n') {
        needle[i++] = c;
    }
    i = 0;
    while ((c = getchar()) != '\n') {
        haystack[i++] = c;
    }
    printf("\n*** %d ***\n", strrindex(haystack, needle));
    return 0;
}

int strrindex(char s[], char t[]) {
    int i, j, k = 0;
    int best = -1;
    while (s[i++] != '\0') {
        j = 0;
        k = i-1;
        while (t[j] != '\0' && s[k] != '\0' && t[j++] == s[k++]) {
            if (t[j] == '\0') {
                best = i-1;
            }
        }
    }
    return best;
}
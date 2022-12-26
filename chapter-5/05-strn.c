#include <stdio.h>

/* 
5-5 Write the following versions of the functions strncpy, strncat, and strncmp: strncpy(s, t, n) copies at most the first n characters og string t to string s; strncat(s, t, n) concatenates at most the first n characters of string t to the end of string s; and strncmp compares at most the first n characters of string t to string s.
*/

#define MAXSTRING 1000

void my_strncpy(char *s, char *t, unsigned int n);
void my_strncat(char *s, char *t, unsigned int n);
int my_strncmp(char *s, char *t, unsigned int n);
void clear(char *s);

int main() {
    char s[MAXSTRING];
    /* strncpy tests */
    my_strncpy(s, "hey there", 100);
    printf("\"%s\" = \"%s\"\n", s, "hey there");
    clear(s);
    my_strncpy(s, "wait, hey, how are you?", 1);
    printf("\"%s\" = \"%s\"\n", s, "w");
    clear(s);
    my_strncpy(s, "hey there", 5);
    printf("\"%s\" = \"%s\"\n", s, "hey t");
    clear(s);
    my_strncpy(s, "hey there", 0);
    printf("\"%s\" = \"%s\"\n", s, "");
    clear(s);
    /* strncat tests */
    my_strncpy(s, "hey there", 100);
    my_strncat(s, ", buddy!", 100);
    printf("\"%s\" = \"%s\"\n", s, "hey there, buddy!");
    clear(s);
    my_strncpy(s, "hey there", 100);
    my_strncat(s, ", buddy!", 5);
    printf("\"%s\" = \"%s\"\n", s, "hey there, bud");
    clear(s);
    my_strncpy(s, "hey there", 100);
    my_strncat(s, ", friend!", 3);
    printf("\"%s\" = \"%s\"\n", s, "hey there, f");
    clear(s);
    my_strncpy(s, "hey there", 100);
    my_strncat(s, ", friend!", 1);
    printf("\"%s\" = \"%s\"\n", s, "hey there,");
    clear(s);
    my_strncpy(s, "hey there", 100);
    my_strncat(s, ", friend!", 0);
    printf("\"%s\" = \"%s\"\n", s, "hey there");
    /* strncmp tests */
    printf("%d = 0\n", my_strncmp("abcdef", "abcdef", 100));
    printf("%d < 0\n", my_strncmp("aaa", "bbb", 100));
    printf("%d < 0\n", my_strncmp("a", "b", 100));
    printf("%d < 0\n", my_strncmp("agifdhghhksdgh", "b", 100));
    printf("%d < 0\n", my_strncmp("aaaaa", "cdfgfhgdhdfhdfh", 100));
    printf("%d < 0\n", my_strncmp("abcdef", "abcdeg", 100));
    printf("%d < 0\n", my_strncmp("abcdef", "abcdefg", 100));
    printf("%d < 0\n", my_strncmp("", "abcdeg", 100));
    printf("%d < 0\n", my_strncmp("abbxyz", "abcdeg", 100));
    printf("%d > 0\n", my_strncmp("bbb", "aaa", 100));
    printf("%d > 0\n", my_strncmp("b", "a", 100));
    printf("%d > 0\n", my_strncmp("b", "agifdhghhksdgh", 100));
    printf("%d > 0\n", my_strncmp("cdfgfhgdhdfhdfh", "aaaaa", 100));
    printf("%d > 0\n", my_strncmp("abcdeg", "abcdef", 100));
    printf("%d > 0\n", my_strncmp("abcdefg", "abcdef", 100));
    printf("%d > 0\n", my_strncmp("abcdeg", "", 100));
    printf("%d > 0\n", my_strncmp("abcdeg", "abbxyz", 100));
    printf("%d = 0\n", my_strncmp("", "", 100));
    printf("%d = 0\n", my_strncmp("", "", 1));
    printf("%d = 0\n", my_strncmp("", "", 0));
    printf("%d = 0\n", my_strncmp("abcdeg", "abbxyz", 2));
    printf("%d = 0\n", my_strncmp("abcdeg", "abbxyz", 1));
    printf("%d > 0\n", my_strncmp("abcdeg", "abbxyz", 3));
    printf("%d < 0\n", my_strncmp("aabcdeg", "abbxyz", 2));
    printf("%d = 0\n", my_strncmp("dafasfsFsf", "abbxyz", 0));
    printf("%d < 0\n", my_strncmp("r", "zxy", 2));
    printf("%d < 0\n", my_strncmp("z", "zxy", 2));
    printf("%d > 0\n", my_strncmp("zxy", "r", 2));
    printf("%d > 0\n", my_strncmp("zxy", "z", 2));
    printf("%d = 0\n", my_strncmp("a", "b", 0));
    return 0;
}

void my_strncpy(char *s, char *t, unsigned int n) {
    unsigned int i;
    for (i = 0; (*s++ = *t++); i++) {
        if (i == n) {
            *--s = '\0';
            break;
        }
    }
}

void my_strncat(char *s, char *t, unsigned int n) {
    while (*s) {
        s++;
    }
    my_strncpy(s, t, n);
}

int my_strncmp(char *s, char *t, unsigned int n) {
    if (n == 0) {
        return 0;
    }
    unsigned int i;
    for (i = 0; *s++ == *t++; i++) {
        if (i == n-1 || (*(s-1) == '\0' && *(t-1) == '\0')) {
            return 0;
        }
    }
    return *--s - *--t;
}

void clear(char *s) {
    *s = '\0';
}
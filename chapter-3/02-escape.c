#include <stdio.h>

/* Problem 3-2 write a program escape(s, t) that copies string t to s but replaces \n and \t characters with their escape sequences. Then do the reverse. */

#define SIZE 500

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
    char c, s[SIZE], t[SIZE];
    int i = 0;

    while ((c = getchar()) != EOF) {
        t[i++] = c;
    }
    t[i] = '\0';

    escape(s,t);

    printf("\n\nEscaped:\n%s\n\n", s);

    unescape(t, s);

    printf("Unescaped:\n%s\n\n", s);
    return 0;
}

void escape(char s[], char t[]) {
    int i, j = 0;

    for (i = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }

    s[j] = '\0';

}

void unescape(char s[], char t[]) {
    int i, j = 0;

    for (i = 0; s[j] != '\0'; i++) {
        switch (s[j]) {
            case '\\':
                switch (s[j+1]) {
                    case 'n':
                        t[i] = '\n';
                        j += 2;
                        break;
                    case 't':
                        t[i] = '\t';
                        j += 2;
                        break;
                    default:
                        t[i] = s[j++];
                        break;
                }
                break;
            default:
                t[i] = s[j++];
                break;
        }
    }

    t[i] = '\0';
    
}
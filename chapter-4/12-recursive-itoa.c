#include <stdio.h>

/* 4-12 Write recursive version of itoa, convert integer to string */

#define MAXLINE 100

char* itoa(int);

int main() {
    printf("%s\n", itoa(987601234));
    return 0;
}

char* itoa(int n) {
    static char string_n[MAXLINE];
    static int i = 0;
    if (n < 0) {
        string_n[i++] = '-';
        n = -n;
    }
    if (n / 10) {
        itoa(n / 10);
    }
    string_n[i++] = '0' + (n % 10);
    return string_n;
}
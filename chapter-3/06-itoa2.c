#include <stdio.h>
#include <limits.h>

/* Problem 3-6 Revise itoa to accept a third argument of minimum field width so that padding is added to the string if not long enough */

#define SIZE 800

void itoa(int n, char s[], int ml);
void reverse(char s[]);
void test(int x, int ml);

int main() {
    test(45, 100);
    test(-364837, 3);
    test(0, 200);
    test(INT_MIN, 150);

    return 0;
}

void itoa(int n, char s[], int ml) {
    int i, sign, temp;
    i = 0;
    if ((sign = n) <= 0) {
        temp = -(n / 10);
        s[0] = -(n + temp * 10) + '0';
        n = temp;
        i++;
    }

    while (n > 0) {
        s[i++] = n % 10 + '0';
        n /= 10;
    }

    if (sign < 0) {
        s[i++] = '-';
    }

    for (; i < ml; i++) {
        s[i] = ' ';
    }

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {

    int i, len;

    /* get length */
    for (i = 0; s[i] != '\0'; i++) {
        ;
    }
    len = i;

    /* reverse the string */
    char temp;
    for (i = 0; i < len / 2; i++) {
        temp = s[len - 1 - i];
        s[len - 1 - i] = s[i];
        s[i] = temp;
    }

}

void test(int x, int ml) {
    char s[SIZE];
    itoa(x, s, ml);
    printf("\n%d with min-width %d:\n%s\n", x, ml, s);
}
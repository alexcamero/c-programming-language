#include <stdio.h>
#include <limits.h>

/* Problem 3-5 write function itob(n, b, s) that converts integer n to a string s in base b character representation (like hexidcimal if b=16) */

#define SIZE 2000 /* max string length */

void itob(int n, int b, char s[]);
char convert_digit(int n); /* return character representation of n with A-Z overflow */
void reverse(char s[]);
void test(int x, int b);

int main() {
    test(10, 2);
    test(-17, 2);
    test(INT_MIN, 2);
    test(0, 2);
    test(56413, 10);
    test(-90, 10);
    test(INT_MIN, 10);
    test(0, 10);
    test(3, 3);
    test(-82, 3);
    test(INT_MIN, 3);
    test(0, 3);
    test(15, 16);
    test(-18, 16);
    test(0, 16);
    test(73625, 30);
    test(-8242617, 30);

    return 0;
}

void itob(int n, int b, char s[]) {

    int i, sign, temp1, temp2;
    i = 0;
    if ((sign = n) <= 0) {
        temp1 = -(n / b);
        temp2 = -(n + temp1 * b);
        s[0] = convert_digit(temp2);

        n = temp1;
        i++;
    }

    while (n > 0) {
        s[i++] = convert_digit(n % b);
        n /= b;
    }

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}

char convert_digit(int n) {
    return (n < 10) ? n + '0' : n - 10 + 'A';
}

void reverse(char s[]) {

    int i, len;

    for (i = 0; s[i] != '\0'; i++) {
        ;
    }
    len = i;

    char temp;
    for (i = 0; i < len / 2; i++) {
        temp = s[len - 1 - i];
        s[len - 1 - i] = s[i];
        s[i] = temp;
    }

}

void test(int x, int b) {
    char s[SIZE];
    itob(x, b, s);
    printf("\n%d = %s  (%d)\n", x, s, b);
}
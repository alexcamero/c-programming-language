#include <stdio.h>
#include <limits.h>

/* Problem 3-4 the version of itoa given in the text does not work for the largest negative integer in 2's complement. Explain why and then fix the function. */

#define SIZE 20 /* limit on string length */

void itoa_og(int n, char s[]); /* original function from text */
void itoa_fixed(int n, char s[]); /* solution to assignment */
void reverse(char s[]); /* reverse string s */
void test(int x);

int main() {

    test(98765);
    test(-4567);
    test(2);
    test(-8);
    test(INT_MIN);
    test(0);

    return 0;
}

void itoa_og(int n, char s[]) {

    int i, sign;

    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
}

/* the original version above does not work for the largest negative number since there is no corresponding positive integer with the same absolute value so taking the negative results in an error or at least unpredictable behavior.

To fix the issue I took care of the ones digit when the number is negative separately. It would have been less convoluted if the remainder operator could be used on negative numbers without unpredictable behavior, but the book indicates that this is machine dependent so I avoided using it. */

void itoa_fixed(int n, char s[]) {

    int i, sign, temp;
    i = 0;
    if ((sign = n) <= 0) {
        /* Let temp contain the positive version of all digits after the ones */
        temp = -(n / 10);
        /* take away all but the ones place of n, make positive, store character at beginning of s */
        s[0] = -(n + temp * 10) + '0';
        /* make n everything that remains */
        n = temp;
        /* bump up i */
        i++;
    }
    /* switch to a while loop since we don't always do the first step anymore */
    while (n > 0) {
        s[i++] = n % 10 + '0';
        n /= 10;
    }

    if (sign < 0) {
        s[i++] = '-';
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

void test(int x) {
    char s[SIZE], t[SIZE];
    itoa_og(x, s);
    itoa_fixed(x, t);
    printf("%d\n%s\n%s\n\n", x, s, t);
}
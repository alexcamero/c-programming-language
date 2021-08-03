#include <stdio.h>
#include <limits.h>

/* Problem 2-8 Write a function rightrot(x, n) that returns the value of the integer x rotated to the right by n bit positions */

int rightrot(unsigned int x, int n);
int int_bits();

int main() {
    int j, i;
    j = int_bits();
    unsigned int m, p;
    m = UINT_MAX;
    p = 1;
    for (i = 1; i < j; i++) {
        p *= 2;
    }
    printf("%u = %u\n", m, rightrot(m, 10));
    printf("%u = %u\n", m, rightrot(m, 13));
    printf("%u = %u\n", 9324, rightrot(9324, 0));
    printf("%u = %u\n", 0, rightrot(0, 9));
    printf("%u = %u\n", p, rightrot(1, 1));
    printf("%u = %u\n", p+1, rightrot(6, 2));
    return 0;
}

int rightrot(unsigned int x, int n) {
    /* Grab the bottom n bits to move to the top */
    unsigned int mask, top;
    mask = ~(~0 << n);
    top = x & mask;

    /* Find length j of binary rep of unsigned ints */
    int j;
    j = int_bits();

    /* Move the bottom bits to the top */
    top <<= (j - n);

    /* Move x to the right, combine, and return */
    return (x >> n) | top;
}

int int_bits() {
    /* return the number of bits in an unsigned int */
    unsigned int i = UINT_MAX;
    int j = 0;
    while (i > 0) {
        i = (i - 1)/2;
        j++;
    }
    return j;
}
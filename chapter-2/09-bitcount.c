#include <stdio.h>

/* Problem 2-9 In 2's complement number system x &= (x-1) deletes the right-most 1-bit in x. Explain why. Use the observation to write a faster bitcount function, a function that counts the 1 bits in an unsigned int */

/* Answer to the question: the binary rep of x-1 is identical to x until the position of x's right-most 1 at which point x is 10...0 (by definition) and x-1 is 01...1. Therefore, x & (x-1) is the same as x until this position since before that the operands are either both 1 or both 0. Starting with this position and moving to the right x & (x-1) is 0 in every position since x and x-1 are always opposite bits. So x & (x-1) is equal to x everywhere but the position where x had its first 1. */

int bitcount(unsigned x);

int main() {
    printf("%d = %d\n", 0, bitcount(0));
    printf("%d = %d\n", 1, bitcount(512));
    printf("%d = %d\n", 2, bitcount(3));
    printf("%d = %d\n", 3, bitcount(19));
    printf("%d = %d\n", 4, bitcount(1061));
    return 0;
}

int bitcount(unsigned x) {
    int i=0;
    while (x != 0) {
        x &= (x-1);
        i++;
    }
    return i;
}
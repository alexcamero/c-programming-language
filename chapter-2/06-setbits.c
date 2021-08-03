#include <stdio.h>

/* Problem 2-6 setbits(x, p, n, y) return int x after replacing the n bits starting at position p with the first n bits of int y.
Expect setbits(185, 6, 4, 90) = 209 */

int setbits(int x, int p, int n, int y);

int main() {
    printf("%d\n", setbits(185, 6, 4, 90));
    return 0;
}

int setbits(int x, int p, int n, int y) {
    int z;
    z = ~(~0 << n) << (p + 1 - n);
    return (~z & x) | (z & (y << (p + 1 - n)));
}
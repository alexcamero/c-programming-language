#include <stdio.h>

/* Problem 2-7 write function invert(x, p, n) that inverts the n bits of x starting at the pth bit.
Expect invert(185, 6, 4) = 193 */

int invert(int x, int p, int n);

int main() {
    printf("%d\n", invert(185, 6, 4));
    return 0;
}

int invert(int x, int p, int n) {
    return x ^ (~(~0 << n) << (p + 1 - n));
}
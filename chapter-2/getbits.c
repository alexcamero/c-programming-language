#include <stdio.h>

/* Not a problem, just want to see if I can make the function before the book reveals how: getbits(x,p,n) returns the integer given by taking the n bits starting in the pth position and going to the right (indexing starts on the right-most position at 0). For example, getbits(22, 4, 3) = 5 since 22 has binary rep 010110 and the three bits starting at position 4 and moving to the right are 101 which represents 5 in binary. */

int getbits(int x, int p, int n);

int main() {
    printf("%d\n", getbits(22,4,3));
    return 0;
}

int getbits(int x, int p, int n) {

    /* find the integer y that has an all-ones binary rep of length n */
    int i, y = 0;
    for (i = 0; i < n; i++) {
        y = 2 * y + 1;
    }

    /* left-shift y by p + 1 - n positions so that it masks the correct bits of x */
    y = y << (p + 1 - n);

    /* mask x with y */
    y = x & y;

    /* right-shift back by p + 1 - n positions to get the result */
    y = y >> (p + 1 - n);
    return y;
}

/* Ok, the solution in the book is nicer since it avoids the loop by just right-shifting the complement of 0 n times */
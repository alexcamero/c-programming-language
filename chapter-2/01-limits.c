#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Problem 2-1 Write a program to determine the ranges of char short, int, and long variables, both signed and unsigned, by grabbing constants from headers and by direct computation. Determine ranges of various floating point types. */

int main() {

    long rec;

    /* CHAR */
    printf("CHAR\nHeader:\nUnsigned Min %d\nUnsigned Max %d\nSigned Min %d\nSigned Max %d\n", 0, UCHAR_MAX, SCHAR_MIN, SCHAR_MAX);

    signed char c;
    c = -1;

    while(c < 0) {
        rec = c;
        c = c * 2;
    }

    c = rec;

    printf("Computed:\nUnsigned Min %d\nUnsigned Max %d\nSigned Min %d\nSigned Max %d\n\n", 0, -2 * c - 1, c, -1 - c);

    /* SHORT */
    printf("SHORT\nHeader:\nUnsigned Min %d\nUnsigned Max %d\nSigned Min %d\nSigned Max %d\n", 0, USHRT_MAX, SHRT_MIN, SHRT_MAX);

    signed short s;
    s = -1;

    while(s < 0) {
        rec = s;
        s = s * 2;
    }

    s = rec;

    printf("Computed:\nUnsigned Min %d\nUnsigned Max %d\nSigned Min %d\nSigned Max %d\n\n", 0, -2 * s - 1, s, -1 - s);

    /* INT */
    printf("INT\nHeader:\nUnsigned Min %d\nUnsigned Max %u\nSigned Min %d\nSigned Max %d\n", 0, UINT_MAX, INT_MIN, INT_MAX);

    signed int i;
    i = -1;

    while(i < 0) {
        rec = i;
        i = i * 2;
    }

    i = rec;

    printf("Computed:\nUnsigned Min %d\nUnsigned Max %u\nSigned Min %d\nSigned Max %d\n\n", 0, -2 * i - 1, i, -1 - i);

    /* LONG */
    printf("LONG\nHeader:\nUnsigned Min %d\nUnsigned Max %lu\nSigned Min %ld\nSigned Max %ld\n", 0, ULONG_MAX, LONG_MIN, LONG_MAX);

    signed long l;
    l = -1;

    while(l < 0) {
        rec = l;
        l = l * 2;
    }

    l = rec;

    printf("Computed:\nUnsigned Min %d\nUnsigned Max %lu\nSigned Min %ld\nSigned Max %ld\n\n", 0, -2 * l - 1, l, -1 - l);

    /* FLOAT */
    printf("FLOAT\nHeader:\nMin %.10e\nMax %.10e\n\n", FLT_EPSILON, FLT_MAX);

    /* DOUBLE */
    printf("DOUBLE\nHeader:\nMin %.10e\nMax %.10e\n", DBL_EPSILON, DBL_MAX);



    return 0;
}
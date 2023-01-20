#include <stdio.h>

/* 
5-6 Rewrite appropriate programs from earlier chapters with pointers instead of array indexing. Good possibilities include (the ones I'll do) getline, atoi, itoa, reverse, strindex, and getop.

itoa(i, a) takes an integer i and converts to a string that gets stored in character array a
*/

#define MAXLINE 1000

void my_itoa(int i, char *a);

int main() {
    char a[MAXLINE];
    my_itoa(87, a);
    printf("expected: 87; actual: %s\n", a);
    my_itoa(87001, a);
    printf("expected: 87001; actual: %s\n", a);
    my_itoa(9, a);
    printf("expected: 9; actual: %s\n", a);
    my_itoa(0, a);
    printf("expected: 0; actual: %s\n", a);
    my_itoa(-4, a);
    printf("expected: -4; actual: %s\n", a);
    my_itoa(-98711, a);
    printf("expected: -98711; actual: %s\n", a);
    my_itoa(-19, a);
    printf("expected: -19; actual: %s\n", a);
    return 0;
}

void my_itoa(int i, char *a) {
    // set up auxiliary array
    char aux[MAXLINE];
    char *b = aux;
    // handle negative
    if (i < 0) {
        *a++ = '-';
        *b++ = '0' + ((10 * (i/10)) - i);
        i = (i/10) * -1;
    } else if (i == 0) {
        *b++ = '0';
    }
    // gather characters
    while (b - aux < MAXLINE && i > 0) {
        *b++ = '0' + (i % 10);
        i /= 10;
    }
    // reverse string
    while (b-- > aux) {
        *a++ = *b;
    }
    *a = '\0';
}
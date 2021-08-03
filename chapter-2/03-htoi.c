#include <stdio.h>

/* Problem 2-3 Convert string of hex digits (with optional "0x" or "0X") to integer */

int htoi(char hex[]);

int main() {

    printf("18 = %d\n", htoi("12"));
    printf("10 = %d\n", htoi("A"));
    printf("270 = %d\n", htoi("10E"));
    printf("2575 = %d\n", htoi("0xA0f"));
    printf("10 = %d\n", htoi("0XA"));

    return 0;
}

int htoi(char hex[]) {
    int i = 0, n = 0, d;

    /* Deal with optional start */
    if ((hex[0] != '\0') && (hex[1] != '\0')) {
        if ((hex[0] == '0') && ((hex[1] == 'x') || (hex[1] == 'X'))) {
            i = 2;
        }
    }

    
    while (hex[i] != '\0') {
        /* Convert characters to numbers */
        if (hex[i] >= '0' && hex[i] <= '9') {
            d = hex[i] - '0';
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            d = hex[i] - 'a' + 10;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            d = hex[i] - 'A' + 10;
        }

        /* Keep count */
        n = 16 * n + d;

        /* Bump */
        i++;
    }

    return n;
}
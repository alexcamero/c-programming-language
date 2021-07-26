#include <stdio.h>

/* Problem 1-14 asks for histogram of the frequency of characters in input */

int main() {

    /* Count characters */

    int c, i, chars[128];

    for (i = 0; i < 128; i++) {
        chars[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        chars[c]++;
    }

    /* Get maximum frequency */

    int max_freq;
    max_freq = 0;

    for (i = 0; i < 128; i++) {
        if (max_freq < chars[i]) {
            max_freq = chars[i];
        }
    }

    /* Find max length for ticks */

    int width, temp;
    width = 1;
    temp = max_freq / 10;

    while (temp != 0) {
        width++;
        temp = temp / 10;
    }

    /* add some space */

    width = width + 2;


    /* Establish tick intervals */

    #define SCREEN 150

    int step;
    step = 1;

    while (step * SCREEN < max_freq) {
        step++;
    }

    /* Make horizontal histogram */

    int label, spaces, j;

    printf("Character |");
    
    for (i = 0; i < SCREEN / width; i++) {
        label = (i + 1) * width * step;
        spaces = width - 1;
        while (label != 0) {
            spaces--;
            label = label / 10;
        }
        label = (i + 1) * width * step;
        for (j = 0; j < spaces; j++) {
            printf(" ");
        }
        printf("%d|", label);
    }

    printf("\n");

    for (i = 0; i < 11 + SCREEN; i++) {
        printf("-");
    }

    printf("\n");

    for (i = 0; i < 128; i++) {
        printf("%10d|", i);
        for (j = 0; j < SCREEN; j++) {
            if (chars[i] >= step * (j+1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

}
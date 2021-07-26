#include <stdio.h>

/* Problem 1-13: make a histogram of lengths of words in the input */

int main() {

    /* Initialize variables */

    #define IN 1
    #define OUT 0
    #define MAX 20 /* Maximum word length */

    int c, len, state, i, j, num_words;
    state = OUT;
    num_words = len = 0;

    float word_lengths[MAX + 2];

    for (i = 0; i < MAX + 2; i++) {
        word_lengths[i] = 0.0;
    }

    /* Count and record */

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (len <= MAX) {
                    word_lengths[len]++;
                } else {
                    word_lengths[MAX + 1]++;
                }
                num_words++;
                len = 0;
                state = OUT;
            }
        } else {
            state = IN;
            len++;
        }
    }

    /* Normalize results to percentages of total words */

    for (i = 0; i < MAX + 2; i++) {
        word_lengths[i] = 100.0 * (word_lengths[i] / num_words);
    }

    /* Print vertical histogram */

    for (i = 100; i >= 0; i = i - 10) {
        printf("%3d|", i);
        for (j = 0; j < MAX + 2; j++) {
            if (word_lengths[j] >= i) {
                printf(" ** ");
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }

    printf("    ");

    for (j = 0; j < MAX + 2; j++) {
        printf("----");
    }

    printf("\n    ");

    for (j = 0; j < MAX + 1; j++) {
        printf(" %2d ", j);
    }

    printf("More\n");


}
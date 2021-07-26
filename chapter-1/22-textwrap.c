#include <stdio.h>

/* "Problem 1-22 Write a program to 'fold' long input lines into two or more 
shorter lines after the last non-blank character that occurs before the n-th column
of input. Make sure your program does something intelligent with very long lines,
and if there are no blanks or tabs before the specified column."

To be honest, I'm having trouble understanding what this one is asking for.
It seems like it's wanting me to take all of the long line that occurs after 
the last non-whitespace character before position n and split it up into at least two
additional lines? But that doesn't make much sense. And then it qualifies that
something intelligent should happen if there are no blanks or tabs at all before
the nth position when that shouldn't really make a difference according to my reading
of the first part.

So I'm just going to make a program to wrap the text for lines that run on to long
in a way that makes sense to me: if there is a space within a few characters prior
to the Nth column (say K characters), then it should start a new line with the next
non-whitespace, and if no, then it should hyphenate whatever word is there
between two lines. */

#define N 40 /* number of columns to break at */
#define K 5 /* acceptable number of spots to go back to find a natural breaking space */

int main() {
    char buffer[N], c;
    int i, j;

    i = 0;

    while((c = getchar()) != EOF) {
        if (i < N && c != '\n') {
            buffer[i] = c;
            i++;
        } else if (c == '\n') {
            for (j = 0; j < i; j++) {
                putchar(buffer[j]);
            }
            putchar(c);
            i = 0;
        } else if (i == N) {
            i = N - 1;
            while (buffer[i] != ' ' && buffer[i] != '\t' && N - 1 - i < K) {
                i--;
            }
            if (N - 1 - i != K) {
                for (j = 0; j <= i; j++) {
                    putchar(buffer[j]);
                }
                for (j = i + 1; j < N; j++) {
                    buffer[j - i - 1] = buffer[j];
                }
                i = N - i - 1;
            } else {
                for (j = 0; j < N; j++) {
                    putchar(buffer[j]);
                }
                putchar('-');
                i = 0;
            }
            putchar('\n');
            buffer[i] = c;
            i++;
        }
    }

    for (j = 0; j<i; j++) {
        putchar(buffer[j]);
    }

    putchar('\n');
    return 0;
}
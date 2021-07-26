#include <stdio.h>

/* Problems 1-6 and 1-7. Hit CTRL-D in the shell after sending an empty input to trigger the EOF when trying it out. */

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        printf("Value: %d\n", c != EOF);
    }
    printf("Value: %d\n", c != EOF);
    printf("and EOF's value is %d\n", c);
}
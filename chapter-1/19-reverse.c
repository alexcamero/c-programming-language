#include <stdio.h>

/* Problem 1-9 Write a function that reverses a string and use it to reverse input one line at a time */

#define MAXBUFFER 1000
#define ERROR -1
#define FINE 1

void reverse(char s[], int length);
void reset_array(char arr[], int length);

int main() {

    char buffer[MAXBUFFER], c;
    int i, state;

    i = 0;
    state = FINE;

    while ((c = getchar()) != EOF) {
        if (c == '\n' && state == ERROR) {
            reset_array(buffer, MAXBUFFER);
            i = 0;
            state = FINE;
        } else if (state == ERROR) {
            ;
        } else if (c == '\n') {
            reverse(buffer, i);
            printf("%s\n", buffer);
            i = 0;
            reset_array(buffer, MAXBUFFER);
        } else if (c != '\n') {
            buffer[i] = c;
            i++;
            if (i >= MAXBUFFER) {
                state = ERROR;
                printf("***** ERROR: The line was too long. *****\n");
            }
        }
    }

    /* pickup the last line if it didn't end in \n */

    if (i > 0 && i < MAXBUFFER) {
        reverse(buffer, i);
        printf("%s\n", buffer);
    }
    
    return 0;
}

void reverse(char s[], int length) {
    char temp;
    int i;

    for (i=0; i<length/2; i++) {
        temp = s[length - i - 1];
        s[length - i - 1] = s[i];
        s[i] = temp;
    }

}

void reset_array(char arr[], int length) {
    int i;

    for (i=0; i<length; i++) {
        arr[i] = '\0';
    }
}
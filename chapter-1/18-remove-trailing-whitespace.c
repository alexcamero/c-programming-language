#include <stdio.h>

/* Problem 1-18 remove trailing blanks, tabs from each line of input an
remove blank lines completely */

#define MAXBUFFER 40 /* maximum amount of whitespace to log before overload */
#define NEWLINE 1
#define OLDLINE 0
#define ERROR -1

void reset_array(char arr[]);

int main() {

    char c, buffer[MAXBUFFER];
    reset_array(buffer);

    int state, buffer_size;
    state = NEWLINE;
    buffer_size = 0;

    while ((c = getchar()) != EOF) {
        if (state == ERROR && c != '\n') {
            ;
        } else if (c != '\n' && c != '\t' && c != ' ') {
            state = OLDLINE;
            printf("%s", buffer);
            reset_array(buffer);
            buffer_size = 0;
            putchar(c);
        } else if (c == '\n') {
            if (state == ERROR) {
                state = NEWLINE;
                reset_array(buffer);
                buffer_size = 0;
                putchar(c);
            }
            if (state == OLDLINE) {
                state = NEWLINE;
                printf("%s", buffer);
                reset_array(buffer);
                buffer_size = 0;
                putchar(c);
            }
        } else if (c == '\t' || c == ' ') {
            if (buffer_size < MAXBUFFER) {
                buffer[buffer_size] = c;
                buffer_size++;
            } else {
                printf("***** ERROR: Buffer is full. This line cannot be fixed. *****");
                state = ERROR;
            }
        }
    }
    putchar('\n');
    return 0;
}

void reset_array(char arr[]) {
    int i;

    for (i=0; i<MAXBUFFER;i++) {
        arr[i] = '\0';
    }
}
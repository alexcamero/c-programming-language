#include <stdio.h>

/* Problem 1-23 Remove comments from C code */

#define OUT 0 /* input is not inside string or character or comment */
#define STRING 1 /* input is currently inside double quotes, but not inside a comment or single quotes */
#define CHAR 2 /* input is currently inside single quotes, but not inside a comment or double quotes */
#define COMMENT_START 3 /* Comment potentially starting */
#define COMMENT 4 /* input is inside of a comment */
#define COMMENT_END 5 /* Comment is potentially ending */

int main() {

    char c, b;
    int state;

    state = OUT;

    while((c = getchar()) != EOF) {
        if (c == '/') {
            if (state == STRING || state == CHAR) {
                putchar(c);
            } else if (state == COMMENT_START) {
                putchar(b);
                putchar(c);
                state = OUT;
            } else if (state == OUT) {
                b = c;
                state = COMMENT_START;
            } else if (state == COMMENT_END) {
                state = OUT;
            }
        } else if (c == '*') {
            if (state == COMMENT_START || state == COMMENT_END) {
                state = COMMENT;
            } else if (state == OUT || state == STRING || state == CHAR) {
                putchar(c);
            } else if (state == COMMENT) {
                state = COMMENT_END;
            }
        } else if (c == '"') {
            if (state == OUT) {
                putchar(c);
                state = STRING;
            } else if (state == STRING) {
                putchar(c);
                state = OUT;
            } else if (state == CHAR) {
                putchar(c);
            } else if (state == COMMENT_START) {
                putchar(b);
                putchar(c);
                state = OUT;
            } else if (state == COMMENT_END) {
                state = COMMENT;
            }
        } else if (c == '\'') {
            if (state == OUT) {
                putchar(c);
                state = CHAR;
            } else if (state == STRING) {
                putchar(c);
            } else if (state == CHAR) {
                putchar(c);
                state = OUT;
            } else if (state == COMMENT_START) {
                putchar(b);
                putchar(c);
                state = OUT;
            } else if (state == COMMENT_END) {
                state = COMMENT;
            }
        } else {
            if (state == OUT || state == STRING || state == CHAR) {
                putchar(c);
            } else if (state == COMMENT_START || state == COMMENT_END) {
                putchar(b);
                putchar(c);
                state = OUT;
            }
        }
    }
    putchar('\n');
    return 0;
}
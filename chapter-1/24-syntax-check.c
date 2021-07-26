#include <stdio.h>

/* Problem 1-24 Check C code for rudimentary syntax errors - unbalanced parenthesis, 
brackets, braces, comments, single quotes, and double quotes.
Also, validate escape sequences */

#define OUT 0
#define COMMENT 1
#define START_COMMENT 2
#define END_COMMENT 3
#define STRING 5
#define CHAR 5
#define ESCAPE 6
#define ERROR 1
#define NO_ERROR 0

int char_lookup(char x);
int val_lookup(char x);

int main() {
    int i, check[3], lines, x, state, state_escape, state_error;

    lines = 0;
    state = state_escape = OUT;
    state_error = NO_ERROR;

    for (i=0; i<3; i++) {
        check[i] = 0;
    }

    char c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            lines++;
        } else if (state_escape == ESCAPE) {
            if (c != '0' && c != 'a' && c != 'b' && c != 'e' && c != 'f' && c != 'n' && c != 'r' && c != 't' && c != 'v' && c != '\\' && c != '\'' && c != '\"' && c != '\?') {
                printf("ERROR Line %d: \\%c is not a valid escape.\n", lines, c);
                state_error = ERROR;
            }
            state_escape = OUT;
        } else if (state == OUT) {
            if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}') {
                x = char_lookup(c);
                check[x] = check[x] + val_lookup(c);
                if (check[x] < 0) {
                    printf("ERROR Line %d: Loose %c.\n", lines, c);
                    state_error = ERROR;
                }
            } else if (c == '"') {
                state = STRING;
            } else if (c == '\'') {
                state = CHAR;
            } else if (c == '/') {
                state = START_COMMENT;
            }
        } else if (state == START_COMMENT) {
            if (c == '*') {
                state = COMMENT;
            } else {
                state = OUT;
            }
        } else if (state == END_COMMENT) {
            if (c == '/') {
                state = OUT;
            } else {
                state = COMMENT;
            }
        } else if (state == COMMENT) {
            if (c == '*') {
                state = END_COMMENT;
            }
        } else if (state == STRING || state == CHAR) {
            if (c == '\\') {
                state_escape = ESCAPE;
            } else if (state == STRING && c == '\"') {
                state = OUT;
            } else if (state == CHAR && c == '\'') {
                state = OUT;
            }
        }
    }

    if (state == STRING) {
        printf("ERROR: Unclosed \".\n");
        state_error = ERROR;
    } else if (state == CHAR) {
        printf("ERROR: Unclosed \'.\n");
        state_error = ERROR;
    } else if (state == COMMENT || state == END_COMMENT) {
        printf("ERROR: Unclosed comment.\n");
        state_error = ERROR;
    }

    if (check[0] != 0) {
        printf("ERROR: Unclosed ().\n");
        state_error = ERROR;
    }
    if (check[1] != 0) {
        printf("ERROR: Unclosed [].\n");
        state_error = ERROR;
    }
    if (check[2] != 0) {
        printf("ERROR: Unclosed {}.\n");
        state_error = ERROR;
    }

    if (state_error == ERROR) {
        printf("Finished with errors.\n");
    } else {
        printf("Finished. No errors noticed.\n");
    }

    return 0;
}

int char_lookup(char x) {
    int result;
    if (x == '(' || x == ')') {
        result = 0;
    } else if (x == '[' || x == ']') {
        result = 1;
    } else if (x == '{' || x == '}') {
        result = 2;
    } else {
        result = -1;
    }

    return result;
}

int val_lookup(char x) {

    int result;

    if (x == '(' || x == '[' || x == '{') {
        result = 1;
    } else {
        result = -1;
    }
    return result;

}
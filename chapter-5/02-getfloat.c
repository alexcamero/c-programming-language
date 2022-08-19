#include <stdio.h>
#include <ctype.h>

/* 
5-2 Write getfloat that parses input as float.
*/

#define MAXLINE 100

char buffer[MAXLINE];
int buffer_len = 0;

int getfloat(double *pn);

int main() {
    int response;
    double answer;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            response = getfloat(&answer);
            if (response) {
                printf("%f\n", answer);
            } else {
                printf("Sorry, not a number.\n");
            }
            buffer_len = 0;
        } else {
            if (buffer_len >= MAXLINE) {
                printf("Sorry, too long.\n");
                return 0;
            }
            buffer[buffer_len++] = c;
        }
    }
    return 0;
}

int getfloat(double *pn) {
    int i, sign = 1, div_by = 1, ws_skipped = 0, past_point = 0;
    *pn = 0;
    for (i = 0; i < buffer_len; i++) {
        if (ws_skipped) {
            if (past_point) {
                div_by *= 10;
            }
            if (isdigit(buffer[i])) {
                *pn *= 10;
                *pn += (buffer[i] - '0');
            } else if (buffer[i] == '.' && !past_point) {
                past_point = 1;
            } else {
                return 0;
            }
        } else {
            switch (buffer[i]) {
                case ' ':
                case '\t':
                    break;
                case '-':
                    sign = -1;
                default:
                    ws_skipped = 1;
                    if (isdigit(buffer[i])) {
                        i--;
                    } else if (buffer[i] != '+' && buffer[i] != '-') {
                        return 0;
                    }
                    break;
            }
        }
    }
    *pn *= sign;
    *pn /= div_by;
    return 1;
}
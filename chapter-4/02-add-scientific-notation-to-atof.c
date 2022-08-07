#include <stdio.h>

/* Extend the function atof (converts character string to double float) to handle scientific notation of the form '13.892e-7' with optional 'e' or 'E' and optional sign in exponent */

#define MAXLINE 100

double atof(char s[]);

int main() {
    char c, user_in[MAXLINE];
    int i = 0;
    for (i = 0; i < MAXLINE; i++) {
        user_in[i] = '\0';
    }
    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            printf("*********\n%f\n*********\n", atof(user_in));
            for (i = 0; i < MAXLINE; i++) {
                user_in[i] = '\0';
            }
            i = 0;
        } else if (i >= MAXLINE) {
            printf("String is too long. Goodbye.\n");
            break;
        } else {
            user_in[i++] = c;
        }
    }
    return 0;
}

double atof(char s[]) {
    int i = 0, past_decimal = 0, past_exp = 0, exp = 0;
    int sign = 1, power = 1, sign_exp = 1;
    double value = 0.0;
    while (s[i] != '\0') {
        switch (s[i])
        {
        case '-':
            if (past_exp && exp == 0) {
                sign_exp = -1;
            } else if (value == 0.0 && !past_decimal) {
                sign = -1;
            }
            break;
        case '.':
            if (!past_decimal) {
                past_decimal = 1;
            }
            break;
        case 'e':
        case 'E':
            if (!past_exp) {
                past_exp = 1;
            }
            break;
        default:
            if (s[i] >= '0' && s[i] <= '9') {
                if (past_exp) {
                    exp = (exp * 10) + (s[i] - '0');
                } else {
                    value = (value * 10) + (s[i] - '0');
                    if (past_decimal) {
                        power *= 10;
                    }
                }
            }
            break;
        }
        i++;
    }
    value = (sign * value) / power;
    if (sign_exp == -1) {
        for (i = 0; i < exp; i++) {
            value /= 10;
        }
    } else {
        for (i = 0; i < exp; i++) {
            value *= 10;
        }
    }
    return value;
}
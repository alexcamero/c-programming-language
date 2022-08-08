#include <stdio.h>

/* Reverse Polish Calculator */

#define MAXLINE 100

double stack[MAXLINE];
char incoming[MAXLINE];
int stack_length = 0;

double atof(char s[]);
void push(double x);
double pop(void);
double calculator(void);
double argument_error_handler(int index, int num_args);

int main() {
    char c;
    int i;
    for (i = 0; i < MAXLINE; i++) {
        incoming[i] = '\0';
        stack[i] = 0.0;
    }
    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            incoming[i] = ' ';
            printf("**********\n%f\n**********\n", calculator());
            for (i = 0; i < MAXLINE; i++) {
                incoming[i] = '\0';
            }
            i = 0;
        } else if (i >= MAXLINE) {
            printf("**********\nThis expression is too long. Goodbye.\n**********\n");
            return 0;
        } else {
            incoming[i++] = c;
        }
    }
    return 0;
}

double calculator(void) {
    int i = 0, j = 0;
    double x;
    char buffer[MAXLINE];
    for (j = 0; j < MAXLINE; j++) {
        buffer[j] = '\0';
    }
    j = 0;
    while (incoming[i] != '\0') {
        switch (incoming[i]) {
            case ' ':
            case '\t':
                if (j < 2) {
                    switch (buffer[0]) {
                        case '\0':
                            break;
                        case '+':
                            if (stack_length < 2) {
                                return argument_error_handler(i-1, 2);
                            }
                            push(pop() + pop());
                            break;
                        case '-':
                            if (stack_length < 2) {
                                return argument_error_handler(i-1, 2);
                            }
                            x = pop();
                            push(pop() - x);
                            break;
                        case '*':
                            if (stack_length < 2) {
                                return argument_error_handler(i-1, 2);
                            }
                            push(pop() * pop());
                            break;
                        case '/':
                            if (stack_length < 2) {
                                return argument_error_handler(i-1, 2);
                            }
                            x = pop();
                            if (x == 0.0) {
                                stack_length = 0;
                                printf("**********\nDivision by zero error!\n**********\n");
                                return 0.0;
                            }
                            push(pop() / x);
                            break;
                        default:
                            push(atof(buffer));
                            break;
                    }
                } else {
                    push(atof(buffer));
                }
                for (j = 0; j < MAXLINE; j++) {
                    buffer[j] = '\0';
                }
                j = 0;
                break;
            default:
                buffer[j++] = incoming[i];
                break;
        }
        i++;
    }
    if (stack_length != 1) {
        stack_length = 0;
        printf("**********\nIncorrect number of arguments.\n**********\n");
        return 0.0;
    }
    return pop();
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

double pop(void) {
    double x = stack[stack_length - 1];
    stack[stack_length - 1] = 0.0;
    stack_length -= 1;
    return x;
}

void push(double x) {
    stack[stack_length++] = x;
}

double argument_error_handler(int index, int num_args) {
    stack_length = 0;
    printf("**********\nOperation at position %d requires %d arguments.\n**********\n", index, num_args);
    return 0.0;
}
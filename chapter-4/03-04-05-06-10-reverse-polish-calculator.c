#include <stdio.h>
#include <math.h>

/* Reverse Polish Calculator

This covers problems 4-3 through 4-6 and also 4-10. The chapter contains code for their implementation of a basic Reverse Polish calculator. I wanted to design it from scratch before reading the book version so there were some differences that muddied the waters a bit when I got to some later exercises. The book implementation used a function to get a character and another function to unget the character to a buffer if it took too many. My implementation didn't need to unget characters since main handed entire lines to the calculator function which just used an internal buffer to store operators and operands as it looped through the line. 4-10 asks for this second implementation with a getline function so I threw that part in here. Problems 4-7 through 4-9 are specifically about the get and unget character functions so I will treat those separately and, for simplicity, remove them from the context of the calculator.

4-3 Add provisions for modulus operand and negative numbers to the calculator
4-4 Add commands to print top of the stack, duplicate it, swap top two elements of the stack, and clear the stack.
4-5 Add access to math.h library functions (note: tried to find a non-tedious way to do this that avoids evaluating a string as code or whatever. still ended up kinda tedious though.)
4-6 Add commands for handling variables and add a variable for the most recent result. My implementation uses the expressions '=a', '=b', ..., '=z' to store whatever is at the top of the stack to the variable after the equal sign.
4-10 Write a function getline to read an entire input line and revise the calculator to use this.

*/

#define MAXLINE 100

double stack[MAXLINE];
char incoming[MAXLINE];
int stack_length = 0;
double ans = 0;
double variables[26];
int var_states[26];
int reading = 1;

double atof(char s[]);
void push(double x);
double pop(void);
double calculator(void);
double number_arguments_error(int index, int num_args);
double unknown_operation_error(int index);
double improper_argument_error(int index, int arg_position, double arg);
void clear_stack(void);
void print_top_stack(void);
double duplicate_top_stack(void);
void swap_top_two_stack(void);
void get_line(void);

int main() {
    int i;
    for (i = 0; i < 26; i++) {
        var_states[i] = 0;
    }
    for (i = 0; i < MAXLINE; i++) {
        stack[i] = 0.0;
    }
    i = 0;
    while (reading) {
        get_line();
        if (!reading) {
            break;
        }
        ans = calculator();
        printf("**********\n%f\n**********\n", ans);
    }
    return 0;
}

void get_line(void) {
    char c;
    int i;
    for (i = 0; i < MAXLINE; i++) {
        incoming[i] = '\0';
    }
    i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (i >= MAXLINE) {
            printf("**********\nThis expression is too long. Goodbye.\n**********\n");
            reading = 0;
            return;
        } else {
            incoming[i++] = c;
        }
    }
    incoming[i] = ' ';
    if (c == EOF) {
        reading = 0;
    }
}

double calculator(void) {
    int i = 0, j = 0, k = 0, signature = 0;
    double x, y;
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
                                return number_arguments_error(i-1, 2);
                            }
                            push(pop() + pop());
                            break;
                        case '-':
                            if (stack_length < 2) {
                                return number_arguments_error(i-1, 2);
                            }
                            x = pop();
                            push(pop() - x);
                            break;
                        case '*':
                            if (stack_length < 2) {
                                return number_arguments_error(i-1, 2);
                            }
                            push(pop() * pop());
                            break;
                        case '/':
                            if (stack_length < 2) {
                                return number_arguments_error(i-1, 2);
                            }
                            x = pop();
                            if (x == 0.0) {
                                return improper_argument_error(i-1, 2, x);
                            }
                            push(pop() / x);
                            break;
                        case '%':
                            if (stack_length < 2) {
                                return number_arguments_error(i-1, 2);
                            }
                            x = pop();
                            push((int) pop() % (int) x);
                            break;
                        default:
                            if (buffer[0] <= 'z' && buffer[0] >= 'a') {
                                if (var_states[buffer[0] - 'a']) {
                                    push(variables[buffer[0] - 'a']);
                                } else {
                                    printf("**********\nVariable ");
                                    putchar(buffer[0]);
                                    printf(" at index %d has not been defined.\n**********\n", i-1);
                                    return 0.0;
                                }
                            } else {
                                push(atof(buffer));
                            }
                            break;
                    }
                } else if ((buffer[0] >= '0' && buffer[0] <= '9') || buffer[0] == '-' || buffer[0] == '+') {
                    push(atof(buffer));
                } else if (buffer[0] == '=' && j == 2 && buffer[1] <= 'z' && buffer[1] >= 'a') {
                    if (stack_length < 1) {
                        return number_arguments_error(i - j, 1);
                    }
                    variables[buffer[1] - 'a'] = duplicate_top_stack();
                    var_states[buffer[1] - 'a'] = 1;
                } else {
                    for (k = 0; k < j; k++) {
                        signature *= 37;
                        if (buffer[k] <= 'z' && buffer[k] >= 'a') {
                            signature += (buffer[k] - 'a' + 1);
                        } else if (buffer[k] <= '9' && buffer[k] >= '0') {
                            signature += (buffer[k] - '0' + 27);
                        }
                    }
                    switch (signature) {
                        case 37*37*('a'-'a'+1)+37*('n'-'a'+1)+('s'-'a'+1):
                            push(ans);
                            break;
                        case 37*37*('s'-'a'+1)+37*('i'-'a'+1)+('n'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            push(sin(pop()));
                            break;
                        case 37*37*('c'-'a'+1)+37*('o'-'a'+1)+('s'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            push(cos(pop()));
                            break;
                        case 37*37*('t'-'a'+1)+37*('a'-'a'+1)+('n'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            x = pop();
                            if (cos(x) == 0) {
                                return improper_argument_error(i-j, 1, x);
                            }
                            push(tan(x));
                            break;
                        case 37*37*37*('a'-'a'+1)+37*37*('s'-'a'+1)+37*('i'-'a'+1)+('n'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            x = pop();
                            if (x > 1 || x < -1) {
                                return improper_argument_error(i-j, 1, x);
                            }
                            push(asin(x));
                            break;
                        case 37*37*37*('a'-'a'+1)+37*37*('c'-'a'+1)+37*('o'-'a'+1)+('s'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            x = pop();
                            if (x > 1 || x < -1) {
                                return improper_argument_error(i-j, 1, x);
                            } 
                            push(acos(x));
                            break;
                        case 37*37*37*('a'-'a'+1)+37*37*('t'-'a'+1)+37*('a'-'a'+1)+('n'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            push(atan(pop()));
                            break;
                        case 37*37*37*37*('a'-'a'+1)+37*37*37*('t'-'a'+1)+37*37*('a'-'a'+1)+37*('n'-'a'+1)+29:
                            if (stack_length < 2) {
                                return number_arguments_error(i-j, 1);
                            }
                            x = pop();
                            if (x == 0) {
                                return improper_argument_error(i-j, 2, x);
                            }
                            push(atan2(pop(), x));
                            break;
                        case 37*37*37*('s'-'a'+1)+37*37*('i'-'a'+1)+37*('n'-'a'+1)+('h'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            push(sinh(pop()));
                            break;
                        case 37*37*37*('c'-'a'+1)+37*37*('o'-'a'+1)+37*('s'-'a'+1)+('h'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            push(cosh(pop()));
                            break;
                        case 37*37*37*('t'-'a'+1)+37*37*('a'-'a'+1)+37*('n'-'a'+1)+('h'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            push(tanh(pop()));
                            break;
                        case 37*37*('e'-'a'+1)+37*('x'-'a'+1)+('p'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            push(exp(pop()));
                            break;
                        case 37*37*('l'-'a'+1)+37*('o'-'a'+1)+('g'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            x = pop();
                            if (x <= 0) {
                                return improper_argument_error(i-j, 1, x);
                            }
                            push(log(x));
                            break;
                        case 37*37*37*37*('l'-'a'+1)+37*37*37*('o'-'a'+1)+37*37*('g'-'a'+1)+37*28+27:
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            x = pop();
                            if (x <= 0) {
                                return improper_argument_error(i-j, 1, x);
                            }
                            push(log10(x));
                            break;
                        case 37*37*('p'-'a'+1)+37*('o'-'a'+1)+37*37*('w'-'a'+1):
                            if (stack_length < 2) {
                                return number_arguments_error(i-j, 1);
                            }
                            x = pop();
                            y = pop();
                            if (y == 0 && x <= 0) {
                                return improper_argument_error(i-j, 2, x);
                            }
                            if (y < 0 && x != floor(x)) {
                                return improper_argument_error(i-j, 1, y);
                            }
                            push(pow(y, x));
                            break;
                        case 37*37*37*('s'-'a'+1)+37*37*('q'-'a'+1)+37*('r'-'a'+1)+('t'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            x = pop();
                            if (x < 0) {
                                return improper_argument_error(i-j, 1, x);
                            }
                            push(sqrt(x));
                            break;
                        case 37*37*37*('c'-'a'+1)+37*37*('e'-'a'+1)+37*('i'-'a'+1)+('l'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            push(ceil(pop()));
                            break;
                        case 37*37*37*37*('f'-'a'+1)+37*37*37*('l'-'a'+1)+37*37*('o'-'a'+1)+37*('o'-'a'+1)+('r'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            push(floor(pop()));
                            break;
                        case 37*37*37*('f'-'a'+1)+37*37*('a'-'a'+1)+37*('b'-'a'+1)+('s'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            push(fabs(pop()));
                            break;
                        case 37*37*37*37*('l'-'a'+1)+37*37*37*('d'-'a'+1)+37*37*('e'-'a'+1)+37*('x'-'a'+1)+('p'-'a'+1):
                            if (stack_length < 2) {
                                return number_arguments_error(i-j, 1);
                            }
                            x = pop();
                            push(ldexp(pop(), x));
                            break;
                        case 37*37*37*37*('f'-'a'+1)+37*37*37*('r'-'a'+1)+37*37*('e'-'a'+1)+37*('x'-'a'+1)+('p'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            push(frexp(pop(), &signature));
                            break;
                        case 37*37*37*('m'-'a'+1)+37*37*('o'-'a'+1)+37*('d'-'a'+1)+('f'-'a'+1):
                            if (stack_length < 1) {
                                return number_arguments_error(i-j, 1);
                            }
                            push(modf(pop(), &x));
                            break;
                        case 37*37*37*('f'-'a'+1)+37*37*('m'-'a'+1)+37*('o'-'a'+1)+('d'-'a'+1):
                            if (stack_length < 2) {
                                return number_arguments_error(i-j, 1);
                            }
                            x = pop();
                            if (x == 0) {
                                return improper_argument_error(i-j, 2, x);
                            }
                            push(fmod(pop(), x));
                            break;
                        default:
                            return unknown_operation_error(i-j);
                            break;
                    }
                    signature = 0;
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

double number_arguments_error(int index, int num_args) {
    stack_length = 0;
    printf("**********\nOperation at position %d requires %d arguments.\n**********\n", index, num_args);
    return 0.0;
}

double unknown_operation_error(int index) {
    stack_length = 0;
    printf("**********\nUnknown operation at position %d.\n**********\n", index);
    return 0.0;
}

double improper_argument_error(int index, int arg_position, double arg) {
    stack_length = 0;
    printf("**********\nImproper argument for operation at position %d. Cannot take %f for parameter %d.\n**********\n", index, arg, arg_position);
    return 0.0;
}

void clear_stack(void) {
    int i = 0;
    while (stack[i] != 0.0) {
        stack[i++] = 0.0;
    }
    stack_length = 0;
}

void print_top_stack(void) {
    printf("%f", stack[stack_length - 1]);
}

double duplicate_top_stack(void) {
    return stack[stack_length - 1];
}

void swap_top_two_stack(void) {
    double temp = stack[stack_length - 1];
    stack[stack_length - 1] = stack[stack_length - 2];
    stack[stack_length - 2] = temp;
}
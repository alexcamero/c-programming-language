#include <stdio.h>

/* Problem 1-15 Update the temp conversion to use a function. */

float celcius_to_fahrenheit(float celcius);

int main() {

    #define UPPER 150
    #define LOWER -20
    #define STEP 10

    float cel;

    printf("|----------------------|\n| Celcius | Fahrenheit |\n|---------|------------|\n");

    for (cel = LOWER; cel <= UPPER; cel = cel + STEP) {
        printf("| %7.0f | %10.0f |\n", cel, celcius_to_fahrenheit(cel));
    }

    printf("|----------------------|\n");

}

float celcius_to_fahrenheit(float celcius) {
    return (9.0/5.0) * celcius + 32.0;
}
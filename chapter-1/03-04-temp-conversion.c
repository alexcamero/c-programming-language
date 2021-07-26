#include <stdio.h>

/* Makes a table of temps converted from Celsius to Fahrenheit with a heading,
roughly taking out exercises 1-3 and 1-4 */

int main() {
    float fahr, cel;
    int lower, upper, step;
    lower = -20;
    upper = 150;
    step = 10;

    printf("%10s %12s\n", "Celcius", "Fahrenheit");

    cel = lower;

    while (cel <= upper) {
        fahr = (9.0/5.0) * cel + 32.0;
        printf("%10.0f %12.0f\n", cel, fahr);
        cel = cel + step;
    }

}
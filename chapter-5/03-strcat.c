#include <stdio.h>

/* 
5-3 Write pointer version of strcat(s, t) that copies string t to the end of string s
*/

#define MAXSTRING 1000

void my_strcat(char *s, char *t);

int main() {
    char s[MAXSTRING] = "this is s";
    my_strcat(s, " and this is t");
    printf("%s\n", s);
    return 0;
}

void my_strcat(char *s, char *t) {
    while(*s) {
        s++;
    }
    while((*s++ = *t++))
        ;
}
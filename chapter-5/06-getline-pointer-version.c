#include <stdio.h>

/* 
5-6 Rewrite appropriate programs from earlier chapters with pointers instead of array indexing. Good possibilities include (the ones I'll do) getline, atoi, itoa, reverse, strindex, and getop.

getline adds the input line into the character array and returns the length
*/

#define MAXLINE 1000

int my_getline(char *line);

int main() {
    char line[MAXLINE];
    int l = my_getline(line);
    printf("\n%s\n%d\n", line, l);
    return 0;
}

int my_getline(char *line) {
    char *start;
    start = line;
    while(line - start < MAXLINE && (*line = getchar()) != EOF && *line++ != '\n')
        ;
    *line = '\0';
    return line - start - 1;
}
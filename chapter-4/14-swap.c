#include <stdio.h>

/* 4-14 Define a macro swap(t,x,y) that interchanges two arguments x and y of type t */

#define swap(t,x,y) t temp = y;\
                    y = x;\
                    x = temp;

int main() {
    int i = 9, j = -8;
    printf("i = %d, j = %d\n", i, j);
    swap(int, i, j)
    printf("i = %d, j = %d\n", i, j);
    return 0;
}
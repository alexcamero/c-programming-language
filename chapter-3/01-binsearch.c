#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* Problem 3-1 rework bin search function given so that there is only one test inside the loop instead of two and then measure the difference in runtime */

/* This thing gives a runtime error if I make the search array too big and the clock times are too small to get much info from when the array is limited in size. So I guess I'll come back to this one after learning more about malloc or something? */

#define TRIALS 20000

int binsearch_og(int x, int v[], int n);
int binsearch_mine(int x, int v[], int n);

int main() {
    int big;
    big = RAND_MAX/10000;


    int v[big], i = 0, result;
    for (i=0; i<big; i++) {
        v[i] = i;
    }

    clock_t start[TRIALS], middle[TRIALS], end[TRIALS];
    int og_results[TRIALS], mine_results[TRIALS], random_nums[TRIALS];
    
    for (i=0; i<TRIALS; i++) {
        random_nums[i] = rand();
        
        if (random_nums[i] >= big) {
            random_nums[i] = -1;
        }

        start[i] = clock();
        og_results[i] = binsearch_og(random_nums[i], v, big);
        middle[i] = clock();
        mine_results[i] = binsearch_mine(random_nums[i], v, big);
        end[i] = clock();

    }

    clock_t worst[2], best[2], sum[2];

    worst[0] = 0;
    worst[1] = 0;
    best[0] = 1000;
    best[1] = 1000;
    sum[0] = 0;
    sum[1] = 0;

    for (i=0; i<TRIALS; i++) {
        if (og_results[i] != random_nums[i]) {
            printf("Error: original failed looking for %d and instead produced %d", random_nums[i], og_results[i]);
        }
        if (mine_results[i] != random_nums[i]) {
            printf("Error: mine failed looking for %d and instead produced %d", random_nums[i], mine_results[i]);
        }
        if (worst[0] < middle[i] - start[i]) {
            worst[0] = middle[i] - start[i];
        }
        if (worst[1] < end[i] - middle[i]) {
            worst[1] = end[i] - middle[i];
        }
        if (best[0] > middle[i] - start[i]) {
            best[0] = middle[i] - start[i];
        }
        if (best[1] > end[i] - middle[i]) {
            best[1] = end[i] - middle[i];
        }
        sum[0] += (middle[i] - start[i]);
        sum[1] += (end[i] - middle[i]);
    }

    double average[2];

    average[0] = sum[0] / TRIALS;
    average[1] = sum[1] / TRIALS;

    printf("           | The OG |   Mine\n");
    printf("Worst case | %6lu | %6lu\n", worst[0], worst[1]);
    printf(" Best case | %6lu | %6lu\n", best[0], best[1]);
    printf("   Average | %6.4f | %4.4f\n", average[0], average[1]);

    return 0;
}

int binsearch_og(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int binsearch_mine(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    if (x == low) {
        return low;
    }

    return -1;
}

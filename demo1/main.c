#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int range_f(const int start, const int end, const int step, int (*f)(int)) {
    int sum = 0;

    for (int i = start; i <= end; i += step) {
        sum += f(i);
    }

    return sum;
}

int f1(int x) {
    return x;
}

int f2(int x) {
    return x * x;
}

int f3(int x) {
    return (2 * x) + 10;
}

int main(int argc, char **argv) {
    int start, end, step;

    if (argc != 4) {
        printf("Usage: %s <start> <end> <step>\n", argv[0]);
        return EXIT_FAILURE;
    }

    start = atoi(argv[1]);
    end = atoi(argv[2]);
    step = atoi(argv[3]);

    printf("Sum of x for x = %d..%d..%d = %d\n", 
        start, start + step, end, range_f(start, end, step, f1));

    printf("Sum of x^2 for x = %d..%d..%d = %d\n", 
        start, start + step, end, range_f(start, end, step, f2));

    printf("Sum of 2x+10 for x = %d..%d..%d = %d\n", 
        start, start + step, end, range_f(start, end, step, f3));

    return EXIT_SUCCESS;
}
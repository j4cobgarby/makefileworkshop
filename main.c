#include "fizzbuzz.h"
#include "linked_list.h"
#include "fibonacci.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

int main(int argc, char **argv) {
    int fibcount, fizzcount;

    printf("How many fibonacci numbers and how many fizzbuzz numbers? '<fib>, <fizz>': ");
    if (scanf("%d, %d", &fibcount, &fizzcount) != 2) {
        return EXIT_FAILURE;
    }

    linked_list fib = generate_fibonacci(fibcount);
    linked_list fzbz = generate_fizzbuzz(fizzcount);

    printf("Max: %lu\n", MAX(fib.len, fzbz.len));

    printf("\tFibonacci\tFizzbuzz\n");

    for (size_t i = 0; i < MAX(fib.len, fzbz.len); i++) {
        printf("%3lu=\t", i+1);
        if (i < fib.len)
            printf("%10d\t", AT_T(int, &fib, i));
        else
            printf("          \t");

        if (i < fzbz.len)
            printf("%s\n", (char*)ll_at(&fzbz, i)->ptr);
        else
            printf("\n");
    }

    return EXIT_SUCCESS;
}
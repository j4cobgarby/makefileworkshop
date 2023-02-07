#include "range_f.h"

int range_f(const int start, const int end, const int step, int (*f)(int)) {
    int sum = 0;

    for (int i = start; i <= end; i += step) {
        sum += f(i);
    }

    return sum;
}
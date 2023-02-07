#include "fibonacci.h"
#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

linked_list generate_fibonacci(int count) {
    int a = 0, b = 1;
    int c;
    linked_list l = {.head = NULL, .tail = NULL, .len = 0};

    for (int i = 0; i < count; i++) {
        PUSH_TAIL_T(int, &l, b);
        
        c = func(a, b); // Defined in func.s
        a = b; b = c;
    }

    return l;
}
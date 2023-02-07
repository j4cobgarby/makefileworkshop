#include "fizzbuzz.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

#define ITEM_STRLEN 16

linked_list generate_fizzbuzz(int count) {
    linked_list l = {.head = NULL, .tail = NULL, .len = 0};

    for (int i = 1; i < count+1; i++) {
        char *s = ll_push_tail(&l, malloc(ITEM_STRLEN * sizeof(char)))->ptr;
        if (i % 3 == 0 && i % 5 == 0) {
            snprintf(s, ITEM_STRLEN, "FizzBuzz");
        } else if (i % 5 == 0) {
            snprintf(s, ITEM_STRLEN, "Buzz");
        } else if (i % 3 == 0) {
            snprintf(s, ITEM_STRLEN, "Fizz");
        } else {
            snprintf(s, ITEM_STRLEN, "%d", i);
        }
    }

    return l;
}
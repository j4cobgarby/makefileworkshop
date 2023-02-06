#include "linked_list.h"
#include <stdlib.h>

#include <stdio.h>

int main(int argc, char **argv) {
    linked_list ll = {.head = NULL, .tail = NULL};

    *(int*)ll_push_head(&ll, malloc(sizeof(int)))->ptr = 10;
    *(int*)ll_push_head(&ll, malloc(sizeof(int)))->ptr = 20;

    printf("(%p, %p)\n", ll.head, ll.tail);
}
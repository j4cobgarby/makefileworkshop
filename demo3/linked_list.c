#include "linked_list.h"
#include <stdlib.h>

struct ll_node *ll_push_head(linked_list *list, void *data) {
    struct ll_node *node = malloc(sizeof(struct ll_node));

    node->ptr = data;
    node->next = list->head;
    node->prev = NULL;

    if (list->head) list->head->prev = node;
    list->head = node;
    if (!node->next) list->tail = node;

    list->len++;
    return node;
}

struct ll_node *ll_push_tail(linked_list *list, void *data) {
    struct ll_node *node = malloc(sizeof(struct ll_node));

    node->ptr = data;
    node->next = NULL;
    node->prev = list->tail;

    if (list->tail) list->tail->next = node;
    list->tail = node;
    if (!node->prev) list->head = node;

    list->len++;
    return node;
}

void *ll_pop_head(linked_list *list) {
    struct ll_node *node = list->head;
    if (!node) return NULL;
    void *dat = node->ptr;

    list->head = node->next;
    if (list->head) list->head->prev = NULL;

    free(node);
    list->len--;
    return dat;
}

void *ll_pop_tail(linked_list *list) {
    struct ll_node *node = list->tail;
    if (!node) return NULL;
    void *dat = node->ptr;

    list->tail = node->prev;
    if (list->tail) list->tail->next = NULL;

    free(node);
    list->len--;
    return dat;
}

struct ll_node *ll_search(linked_list *list, void *to_search, int (*eq)(void *, void *)) {
    struct ll_node *n;
    for (n = list->head; n && !eq(n->ptr, to_search); n = n->next);
    return n;
}

struct ll_node *ll_at(linked_list *list, int index) {
    struct ll_node *n = list->head;
    for (int i = 0; i < index; i++) {
        n = n->next;
        if (!n) return NULL; // Index out of bounds
    }
    return n;
}

void ll_delete(linked_list *list, struct ll_node *to_delete) {
    if (!to_delete) return;
    if (to_delete->prev) to_delete->prev->next = to_delete->next;
    if (to_delete->next) to_delete->next->prev = to_delete->prev;
    free(to_delete);
    list->len--;
}
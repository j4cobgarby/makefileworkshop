/* A doubly linked list which can hold arbitrary data types. */

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

struct ll_node {
    struct ll_node *prev, *next;
    void *ptr;
};

typedef struct {struct ll_node *head; struct ll_node *tail;} linked_list;

struct ll_node *ll_push_head(linked_list *list, void *data);
struct ll_node *ll_push_tail(linked_list *list, void *data);

void *ll_pop_head(linked_list *list);
void *ll_pop_tail(linked_list *list);

struct ll_node *ll_search(linked_list *list, void *to_search, int (*eq)(void *, void *));
struct ll_node *ll_at(linked_list *list, int index);
void ll_delete(linked_list *list, struct ll_node *to_delete);

#endif /* __LINKED_LIST_H__ */
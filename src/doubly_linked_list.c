#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "doubly_linked_list.h"

List * list_new() {
    List *list = malloc(sizeof(List));
    list->next = NULL;
    list->size = 0;

    return list;
}

void list_add(List *list, int element) {
    Node *new = malloc(sizeof(Node));
    new->value = element;
    new->next = NULL;

    if (list->size == 0) {
        new->prev = NULL;
        list->next = new;
    } else {
        new->prev = list->tail;
        list->tail->next = new;
    }

    list->tail = new;
    list->size++;
}

int list_size(List *list) {
    return list->size;
}

bool list_is_empty(List *list) {
    return list_size(list) == 0;
}


void list_printf(List *list) {
    Node *n = list->next;
    int i = 0;

    while (n != NULL) {
        printf("%d: %d\n", i++, n->value);
        n = n->next;
    }
}

int main() {
    printf("Create new list list\n");
    List *list = list_new();
    printf("Add: list -> 2\n");
    list_add(list, 2);
    printf("Add: list -> 4\n");
    list_add(list, 4);
    printf("Add: list -> 6\n");
    list_add(list, 6);
    list_printf(list);
    return 0;
}

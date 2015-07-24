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

int main() {
    List *list = list_new();

    return 0;
}

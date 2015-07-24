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

void list_add_all(List *dest, List *adding) {
    if (list_is_empty(adding)) {
        return;
    }

    Node *next = adding->next;

    while (next != NULL) {
        list_add(dest, next->value);
        next = next->next;
    }
}

void list_printf(List *list) {
    Node *n = list->next;
    int i = 0;

    while (n != NULL) {
        printf("%d: %d\n", i++, n->value);
        n = n->next;
    }
}

int list_get(List *list, int index) {
    if (index >= list_size(list) || index < 0) {
        return -1;
    }

    if (index == 0) {
        return list->next->value;
    }

    if (index == (list_size(list) - 1)) {
        return list->tail->value;
    }

    int element = -1;
    int i = 0;
    Node *n = list->next;

    while (n != NULL) {
        if (i == index) {
            element = n->value;
            break;
        }

        i++;
        n = n->next;
    }

    return element;
}

bool list_equals(List *list1, List *list2) {
    if (list_size(list1) == list_size(list2)) {
        return false;
    }

    Node *l1next = list1->next;
    Node *l2next = list2->next;

    while (l1next != NULL || l2next != NULL) {
        if (l1next->value != l2next->value) {
            return false;
        }

        l1next = l1next->next;
        l2next = l2next->next;
    }

    return true;
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

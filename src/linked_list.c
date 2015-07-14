#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

List* list_new() {
    List *list = malloc(sizeof(List));
    list->next = NULL;
    list->size = 0;

    return list;
}

void list_add(List *list, int element) {
    Node *next = malloc(sizeof(Node));
    next->value = element;
    next->next = NULL;

    if (list->next != NULL) {
        list->tail->next = next;
    } else {
        list->next = next;
    }

    list->tail = next;
    list->size++;
}

void list_printf(List *list) {
    Node *n = list->next;
    int i = 0;

    while (n != NULL) {
        printf("%d: %d\n", i++, n->value);
        n = n->next;
    }
}

void list_remove_index(List *list, int index) {
    if (index >= list->size) {
        return;
    }

    if (index == 0 && list->size == 1) {
        list->next = NULL;
        list->next = NULL;
    } else if (index == 0 && list->size > 1) {
        list->next = list->next->next;
    } else if (index == (list->size - 1)) {
        
    } else {
        int i = 0;
        Node *n = list->next;
        Node *p = NULL;

        while (i <= index) {
            if (i == index) {
                p->next = n->next;
            }

            p = n;
            n = n->next;
            i++;
        }
    }

    list->size--;
}

int main() {
    List *list = list_new();
    list_add(list, 3);
    list_add(list, 5);
    list_add(list, 7);
    list_add(list, 9);
    list_add(list, 11);

    printf("Size: %d\n", list->size);
    list_printf(list);

    list_remove_index(list, 0);

    printf("Size: %d\n", list->size);
    list_printf(list);

    return 0;
}

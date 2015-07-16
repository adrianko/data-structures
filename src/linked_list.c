#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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

void list_set(List *list, int index, int element) {
    if (index >= list_size(list) || index < 0) {
        return;
    }

    Node *n = list->next;
    int i = 0;

    while (n != NULL) {
        if (i == index) {
            n->value = element;
            break;
        }

        i++;
        n = n->next;
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

void list_remove_index(List *list, int index) {
    if (index >= list_size(list) || index < 0) {
        return;
    }

    Node *rm = malloc(sizeof(*rm));

    if (index == 0 && list_size(list) == 1) {
        rm = list->next;
        list->next = NULL;
        list->tail = NULL;
    } else if (index == 0 && list_size(list) > 1) {
        rm = list->next;
        list->next = list->next->next;
    } else {
        int i = 0;
        Node *n = list->next;
        Node *p = NULL;

        while (i <= index) {
            if (i == index) {
                if (index == (list_size(list) - 1)) {
                    list->tail = p;
                    p->next = NULL;
                } else {
                    p->next = n->next;
                }

                rm = n;
                break;
            }

            p = n;
            n = n->next;
            i++;
        }
    }

    list->size--;
    free(rm);
    rm = NULL;
}

bool list_contains(List *list, int element) {
    if (list_size(list) == 0) {
        return false;
    }

    Node *n = list->next;

    while (n != NULL) {
        if (n->value == element) {
            return true;
        }

        n = n->next;
    }

    return false;
}

int list_get(List *list, int index) {
    if (index >= list_size(list) || index < 0) {
        return -1;
    }

    if (index == 0) {
        return list_get_first(list);
    }

    if (index == (list->size - 1)) {
        return list_get_last(list);
    }

    int element = 0;
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

int list_get_first(List *list) {
    if (list_size(list) == 0) {
        return -1;
    }

    return list->next->value;
}

int list_get_last(List *list) {
    if (list_size(list) == 0) {
        return -1;
    }

    return list->tail->value;
}

bool list_is_empty(List *list) {
    return list_size(list) == 0;
}

int list_index_of(List *list, int element) {
    Node *n = list->next;
    int i = 0;

    while (n != NULL) {
        if (n->value == element) {
            return i;
        }

        i++;
    }

    return -1;
}

int list_size(List *list) {
    return list->size;
}

void list_insert(List *list, int index, int element) {
    if (list_size(list) < index) {
        return;
    }

    if (list_size(list) == 0 && index == 0) {
        list_add(list, element);
        return;
    }

    Node *new = malloc(sizeof(Node));
    new->value = element;
    new->next = NULL;
    Node *next = list->next;
    Node *prev = NULL;
    int i = 0;

    while (next != NULL) {
        if (i == index) {
            if (i == 0) {
                new->next = list->next;
                list->next = new;
            } else {
                new->next = prev->next;
                prev->next = new;
            }
        }

        prev = next;
        next = next->next;
        i++;
    }

    list->size++;
}

void list_clear(List *list) {
    if (list_is_empty(list)) {
        return;
    }

    Node *n = list->next;
    Node *next = NULL;

    while (n != NULL) {
        if (n->next != NULL) {
            next = n->next;
        } else {
            next = NULL;
        }

        free(n);
        n = next;
    }
}

int main() {
    List *list = list_new();
    list_add(list, 3);
    list_add(list, 5);
    list_add(list, 7);
    list_add(list, 9);
    list_add(list, 11);

    printf("Size: %d\n", list_size(list));
    list_printf(list);

    list_remove_index(list, 2);
    list_remove_index(list, 3);
    list_set(list, 2, 5);
    list_insert(list, 1, 7);
    printf("Size: %d\n", list_size(list));
    list_printf(list);
    printf("Contains 9: %s\n", list_contains(list, 9) ? "true" : "false");
    printf("Contains 7: %s\n", list_contains(list, 7) ? "true" : "false");
    printf("List index 2: %d\n", list_get(list, 2));
    list_clear(list);
    printf("Size: %d\n", list_size(list));
    
    printf("------------------------------\n");
    List *list2 = list_new();
    list_add(list2, 1);
    printf("Size: %d\n", list_size(list2));
    list_printf(list2);
    list_remove_index(list2, 0);
    printf("Size: %d\n", list_size(list2));
    list_printf(list2);
    list_remove_index(list2, 0);
    printf("List2 is empty: %s\n", list_is_empty(list2) ? "true" : "false");

    return 0;
}

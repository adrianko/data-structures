#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "singly_linked_list.h"

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

    list->size = 0;
    list->next = NULL;
    list->tail = NULL;
}

void list_reverse(List *list){
    Node *current, *prev, *next;
    current = list->next;
    prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list->next = list->tail;
    list->tail = prev;
}

int list_last_index_of(List *list, int element) {
    if (list_is_empty(list)) {
        return -1;
    }

    Node *next = list->next;
    int index = 0;
    int i = 0;

    while (next != NULL) {
        if (next->value == element) {
            index = i;
        }

        i++;
        next = next->next;
    }

    return index;
}

bool list_equals(List *list1, List *list2) {
    if (list1->size != list2->size) {
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

void list_remove_element(List *list, int element) {
    if (list_is_empty(list)) {
        return;
    }

    int index = list_index_of(list, element);
    
    if (index != -1) {
        list_remove_index(list, index);
    }
}

int main() {
    // create new list and populate
    printf("Create new list: list\n");
    List *list = list_new();
    printf("Add: list -> 3\n");
    list_add(list, 3);
    printf("Add: list -> 5\n");
    list_add(list, 5);
    printf("Add: list -> 7\n");
    list_add(list, 7);
    printf("Add: list -> 9\n");
    list_add(list, 9);
    printf("Add: list -> 11\n");
    list_add(list, 11);

    // check size and print elements
    printf("Size: %d\n", list_size(list));
    list_printf(list);

    // remove by index 
    printf("Remove by index: list -> 2\n");
    list_remove_index(list, 2);
    printf("Remove by index: list -> 3\n");
    list_remove_index(list, 3);

    // set at index, same list size
    printf("Set list index 2: 5\n");
    list_set(list, 2, 5);

    // insert at index increasing list size
    printf("Insert to: list at index 1 -> 7\n");
    list_insert(list, 1, 7);
    printf("Size: %d\n", list_size(list));
    list_printf(list);

    printf("Reverse: list\n");
    list_reverse(list);
    printf("Size: %d\n", list_size(list));
    list_printf(list);

    // check whether contains element
    printf("Contains 9: %s\n", list_contains(list, 9) ? "true" : "false");
    printf("Contains 7: %s\n", list_contains(list, 7) ? "true" : "false");

    // get element at index
    printf("List index 2: %d\n", list_get(list, 2));

    // get last index of
    printf("Last index of 5: %d\n", list_last_index_of(list, 5));

    // empty list
    printf("Clear: list\n");
    list_clear(list);
    printf("Size: %d\n", list_size(list));

    printf("------------------------------\n");

    // create new list
    printf("Create new list: list2\n");
    List *list2 = list_new();
    printf("Add: list2 -> 1\n");
    list_add(list2, 1);
    printf("Size: %d\n", list_size(list2));
    list_printf(list2);

    // remove by index when list size is 1
    printf("Remove index: list2 -> 0\n");
    list_remove_index(list2, 0);
    printf("Size: %d\n", list_size(list2));
    list_printf(list2);
    printf("Remove index: list2 -> 0\n");
    list_remove_index(list2, 0);
    printf("List2 is empty: %s\n", list_is_empty(list2) ? "true" : "false");

    printf("------------------------------\n");
    printf("Create new list: l1\n");
    List *l1 = list_new();
    printf("Add: l1 -> 3\n");
    list_add(l1, 3);
    printf("Add: l1 -> 5\n");
    list_add(l1, 5);
    printf("Add: l1 -> 7\n");
    list_add(l1, 7);

    printf("Create new list: l2\n");
    List *l2 = list_new();
    printf("Add: l2 -> 3\n");
    list_add(l2, 3);
    printf("Add: l2 -> 5\n");
    list_add(l2, 5);
    printf("Add: l2 -> 7\n");
    list_add(l2, 7);

    printf("Create new list: l3\n");
    List *l3 = list_new();
    printf("Add: l3 -> 3\n");
    list_add(l3, 3);
    printf("Add: l3 -> 5\n");
    list_add(l3, 5);
    printf("Add: l3 -> 5\n");
    list_add(l3, 5);

    printf("L1, L2: %s\n", list_equals(l1, l2) ? "true" : "false");
    printf("L1, L3: %s\n", list_equals(l1, l3) ? "true" : "false");

    printf("Add all: l1 -> l2\n");
    list_add_all(l1, l2);
    list_printf(l1);

    return 0;
}

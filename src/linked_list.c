#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct list {
    struct node *next;
    struct node *tail;
    int size;
} List;

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

int main() {
    List *list = list_new();
    list_add(list, 3);
    list_add(list, 5);
    list_add(list, 7);
    list_add(list, 9);
    list_add(list, 11);

    printf("Size: %d\n", list->size);
    list_printf(list);

    return 0;
}

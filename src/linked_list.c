#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct list {
    struct node *next;
} List;

List* listNew() {
    List *list = malloc(sizeof(List));
    list->next = NULL;

    return list;
}

void listAdd(List *list, int element) {
    Node *next = malloc(sizeof(Node));
    next->value = element;
    next->next = NULL;
    
    if (list->next != NULL) {
        Node *last = list->next;

        while (last->next != NULL) {
            last = last->next;
        }

        last->next = next;
    } else {
        list->next = next;
    }
}

int main() {
    List *list = listNew();
    listAdd(list, 3);
    listAdd(list, 5);
    listAdd(list, 7);
    listAdd(list, 9);
    listAdd(list, 11);

    Node *n = list->next;
    int i = 0;

    while (n->next != NULL) {
        printf("%d: %d\n", i++, n->value);
        n = n->next;
    }

    printf("%d: %d\n", i, n->value);

    return 0;
}

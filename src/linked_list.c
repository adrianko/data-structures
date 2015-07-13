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
    printf("%d\n", list->next->value);
    listAdd(list, 5);
    printf("%d\n", list->next->next->value);
    
    
    return 0;
}

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
    if (list->next == NULL) {
        Node *next = malloc(sizeof(Node));
        next->value = element;
        next->next = NULL;
        list->next = next;
    }
}

int main() {
    List *list = listNew();
    listAdd(list, 3);
    printf("%d\n", list->next->value);
    
    
    return 0;
}

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct list {
    struct node *next;
} List;

int main() {
    Node *head = malloc(sizeof(Node));
    head->value = 5;
    printf("%d\n", head->value);

    Node *next = malloc(sizeof(Node));
    next->value = 7;
    
    head->next = next;

    printf("%d\n", head->next->value);
    return 0;
}

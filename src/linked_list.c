#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

int main() {
    Node *n = malloc(sizeof(Node));
    n->value = 5;
    printf("%d\n", n->value);
    return 0;
}

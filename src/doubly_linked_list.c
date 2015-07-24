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

int main() {

    return 0;
}

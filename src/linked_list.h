typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct list {
    struct node *next;
    struct node *tail;
    int size;
} List;

List* list_new();
void list_add(List *list, int element);
void list_insert(List *list, int index, int element);
void list_printf(List *list);
void list_remove_index(List *list, int index);

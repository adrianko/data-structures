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
void list_set(List *list, int index, int element);
void list_printf(List *list);
void list_remove_index(List *list, int index);
bool list_contains(List *list, int element);
int list_get(List *list, int index);
int list_get_first(List *list);
int list_get_last(List *list);
bool list_is_empty(List *list);
int list_index_of(List *list, int element);

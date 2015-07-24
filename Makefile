all: linked_list doubly_linked_list

linked_list:
	gcc -o bin/linked_list src/linked_list.c

doubly_linked_list:
	gcc -o bin/doubly_linked_list src/doubly_linked_list.c

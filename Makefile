all: singly_linked_list doubly_linked_list

singly_linked_list:
	gcc -o bin/singly_linked_list src/singly_linked_list.c

doubly_linked_list:
	gcc -o bin/doubly_linked_list src/doubly_linked_list.c

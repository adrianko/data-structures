CC=gcc
CFLAGS=-Wall -c
LFLAGS=-Wall

all: linked_list
	
linked_list: linked_list.o
	$(CC) $(LFLAGS) linked_list.o -o bin/linked_list
	
linked_list.o: src/linked_list.c
	$(CC) $(CFLAGS) src/linked_list.o
	
run:
	./bin/linked_list
	
clean:
	rm *.o bin/*
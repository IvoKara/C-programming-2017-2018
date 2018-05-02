
GCCL=gcc -Wall -pedantic -std=c11

a.out: linked_list.o main.o
	$(GCCL) linked_list.o main.o

linked_list.o: linked_list.c linked_list.h
	$(GCCL) -c linked_list.c

main.o: main.c
	$(GCCL) -c main.c

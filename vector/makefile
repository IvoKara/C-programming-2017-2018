
GCCL=gcc -Wall -pedantic -std=c11

a.out: my_vector.o main.o
	$(GCCL) my_vector.o main.o

my_vector.o: my_vector.c my_vector.h
	$(GCCL) -c my_vector.c

main.o: main.c
	$(GCCL) -c main.c

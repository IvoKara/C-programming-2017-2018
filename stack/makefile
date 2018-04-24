
GCCL=gcc -Wall -pedantic -std=c11

a.out: stack.o rpn.o
	$(GCCL) stack.o rpn.o

stack.o: stack.c stack.h
	$(GCCL) -c stack.c

rpn.o: rpn.c
	$(GCCL) -c rpn.c

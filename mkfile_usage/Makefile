GCCL=gcc -Wall -pedantic -std=c11
#if anything of these files is changed
a.out: main.o shellsort.o insertion_sort.o
	$(GCCL) shellsort.o insertion_sort.o main.o
	rm *.o
	./a.out

main.o: main.c 
	$(GCCL) -c main.c
	
shellsort.o: shellsort.c shellsort.h
	$(GCCL) -c shellsort.c
	
insertion_sort.o: insertion_sort.c insertion_sort.h
	$(GCCL) -c insertion_sort.c

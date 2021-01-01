#this is a comment
a.out: sllimp.o main.o
	gcc sllimp.c main.c
sllimp.o: sllimp.c
	gcc -c sllimp.c
main.o: main.c sll.h
	gcc -c main.c
run:
	./a.out
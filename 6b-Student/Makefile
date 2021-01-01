#this is a comment
a.out: 6bimp2.o 6bmain.o
	gcc 6bimp2.c 6bmain.c
6bimp2.o: 6bimp2.c
	gcc -c 6bimp2.c
6bmain.o: 6bmain.c 6b.h
	gcc -c 6bmain.c
run:
	./a.out
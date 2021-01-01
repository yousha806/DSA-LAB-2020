#this is a comment
a.out: etimp.o etmain.o
	gcc etimp.c etmain.c
etimp.o: etimp.c
	gcc -c etimp.c
etmain.o: etmain.c et.h
	gcc -c etmain.c
run:
	./a.out
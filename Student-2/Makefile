#this is a comment
a.out: bstimp.o bstmain.o
	gcc bstimp.c bstmain.c
bstimp.o: bstimp.c
	gcc -c bstimp.c
bstmain.o: bstmain.c bst.h
	gcc -c bstmain.c
run:
	./a.out
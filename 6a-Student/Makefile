#this is a comment
a.out: 6aimp.o 6amain.o
	gcc 6aimp.c 6amain.c
6aimp.o: 6aimp.c
	gcc -c 6aimp.c
6amain.o: 6amain.c 6a.h
	gcc -c 6amain.c
run:
	./a.out
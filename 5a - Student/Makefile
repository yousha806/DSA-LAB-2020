#this is a comment
a.out: 5aimp.o 5amain.o
	gcc 5aimp.c 5amain.c
5aimp.o: 5aimp.c
	gcc -c 5aimp.c
5amain.o: 5amain.c 5a.h
	gcc -c 5amain.c
run:
	./a.out
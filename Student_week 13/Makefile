#this is a comment
a.out: trieimp.o triemain.o
	gcc trieimp.c triemain.c
trieimp.o: trieimp.c
	gcc -c trieimp.c
triemain.o: triemain.c trie.h
	gcc -c triemain.c
run:
	./a.out
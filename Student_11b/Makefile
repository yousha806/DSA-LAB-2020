#this is a comment
a.out: bfsimp.o bfsmain.o
	gcc bfsimp.c bfsmain.c
bfsimp.o: bfsimp.c
	gcc -c bfsimp.c
bfsmain.o: bfsmain.c bfs.h
	gcc -c bfsmain.c
run:
	./a.out
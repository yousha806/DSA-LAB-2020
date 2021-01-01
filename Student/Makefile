#this is a comment
a.out: cllimp.o cllmain.o
	gcc cllimp.c cllmain.c
cllimp.o: cllimp.c
	gcc -c cllimp.c
cllmain.o: cllmain.c cll.h
	gcc -c cllmain.c
run:
	./a.out
#this is a comment
a.out: dllimp.o dllmain.o
	gcc dllimp.c dllmain.c
dllimp.o: dllimp.c
	gcc -c dllimp.c
dllmain.o: dllmain.c dll.h
	gcc -c dllmain.c
run:
	./a.out
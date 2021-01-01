#this is a comment
a.out: polyimp.o polymain.o
	gcc polyimp.c polymain.c
polyimp.o: polyimp.c
	gcc -c polyimp.c
polymain.o: polymain.c poly.h
	gcc -c polymain.c
run:
	./a.out
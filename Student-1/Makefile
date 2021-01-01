#this is a comment
a.out: queueimp_21.o queuemain.o
	gcc queueimp_21.c queuemain.c
queueimp_21.o: queueimp_21.c
	gcc -c queueimp_21.c
queuemain.o: queuemain.c queue.h
	gcc -c queuemain.c
run:
	./a.out
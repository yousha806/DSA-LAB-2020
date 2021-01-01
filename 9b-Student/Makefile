#this is a comment
a.out: H_PES2201900653_Week9b.o heapmain.o
	gcc H_PES2201900653_Week9b.c heapmain.c
H_PES2201900653_Week9b.o: H_PES2201900653_Week9b.c
	gcc -c H_PES2201900653_Week9b.c
heapmain.o: heapmain.c heap.h
	gcc -c heapmain.c
run:
	./a.out
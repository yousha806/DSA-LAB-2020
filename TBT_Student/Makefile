#this is a comment
a.out: test.o tbtmain.o
	gcc test.c tbtmain.c
test.o: test.c
	gcc -c test.c
tbtmain.o: tbtmain.c tbt.h
	gcc -c tbtmain.c
run:
	./a.out
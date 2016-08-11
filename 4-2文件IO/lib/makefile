libfun.a: fun.o
	gcc -c fun.c -I .
	ar cr libfun.a fun.o

ex:
	gcc libuse_example.c -L. -lfun